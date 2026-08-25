#!/usr/bin/env python3
"""Concurrent-safe status reporting for the documentation agent pool.

Usage:
  python status.py -status
  python status.py -list-agents
  python status.py -history AGENTID [COUNT]
  python status.py -report STATUS AGENTID [message ...]
  python status.py -online AGENTID
  python status.py -offline AGENTID
  python status.py -clear-agent AGENTID
  python status.py -add-agent AGENTID

Agent IDs are one uppercase letter followed by exactly three digits (for
example, A001 or B002). Agents must be added and online before they can report.
Use ``-online`` and ``-offline`` to change whether a registered agent appears
in the supervisor's prioritized status view.
"""

from __future__ import annotations

import json
import os
import re
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


TOOL_DIR = Path(__file__).resolve().parent
STORE_PATH = TOOL_DIR / "status.json"
LOCK_PATH = TOOL_DIR / "status.lock"
LOCK_TIMEOUT_SECONDS = 30.0
LOCK_POLL_SECONDS = 0.1
HISTORY_LIMIT = 100
STATUS_INFO = {
    "needs-supervisor": (
        "URGENT",
        0,
        "Supervisor intervention or a supervisor-owned action is required.",
    ),
    "error": ("URGENT", 1, "An error stopped or materially disrupted the work."),
    "complete": (
        "ACTION",
        2,
        "The assigned checkpoint is complete and ready for supervisor follow-up.",
    ),
    "blocked": ("ACTION", 3, "Work cannot continue until a blocker is resolved."),
    "idle": ("ACTION", 4, "The online agent has no active work and needs assignment."),
    "issue": (
        "ATTENTION",
        5,
        "An issue needs attention, but non-conflicting work may still continue.",
    ),
    "waiting": (
        "ATTENTION",
        6,
        "The agent is waiting on a transient dependency or external event.",
    ),
    "starting": ("ACTIVE", 7, "The agent is beginning its assigned work."),
    "working": ("ACTIVE", 8, "The agent is actively progressing its assignment."),
}
STATUS_CHOICES = tuple(STATUS_INFO)
ALLOWED_STATUSES = frozenset(STATUS_CHOICES)
UNREPORTED_PRIORITY = ("ACTION", 4)
AGENT_ID_PATTERN = re.compile(r"[A-Z][0-9]{3}\Z")


class UsageError(Exception):
    """Raised when the command line is malformed."""


class CommandError(Exception):
    """Raised when a valid command cannot be applied to the current state."""


class StoreError(Exception):
    """Raised when the JSON status store cannot be safely read or written."""


class FileLock:
    """Small cross-platform advisory file lock shared by all status commands."""

    def __init__(self, path: Path, timeout_seconds: float) -> None:
        self.path = path
        self.timeout_seconds = timeout_seconds
        self.handle = None

    def __enter__(self) -> "FileLock":
        self.acquire()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.release()

    def acquire(self) -> None:
        try:
            self.path.parent.mkdir(parents=True, exist_ok=True)
            self.handle = self.path.open("a+", encoding="utf-8")
        except OSError as exc:
            raise StoreError(f"could not open status lock {self.path}: {exc}") from exc

        deadline = time.monotonic() + self.timeout_seconds
        while True:
            try:
                self._lock_nonblocking()
                return
            except OSError:
                if time.monotonic() >= deadline:
                    self.handle.close()
                    self.handle = None
                    raise TimeoutError(str(self.path))
                time.sleep(LOCK_POLL_SECONDS)

    def release(self) -> None:
        if self.handle is None:
            return
        try:
            self._unlock()
        finally:
            self.handle.close()
            self.handle = None

    def _lock_nonblocking(self) -> None:
        assert self.handle is not None
        self.handle.seek(0)
        if os.name == "nt":
            import msvcrt

            msvcrt.locking(self.handle.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl

            fcntl.flock(self.handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)

    def _unlock(self) -> None:
        assert self.handle is not None
        self.handle.seek(0)
        if os.name == "nt":
            import msvcrt

            msvcrt.locking(self.handle.fileno(), msvcrt.LK_UNLCK, 1)
        else:
            import fcntl

            fcntl.flock(self.handle.fileno(), fcntl.LOCK_UN)


def utc_now() -> datetime:
    return datetime.now(timezone.utc)


def format_timestamp(value: datetime) -> str:
    return value.astimezone(timezone.utc).isoformat(timespec="seconds").replace("+00:00", "Z")


def parse_timestamp(value: Any) -> datetime | None:
    if not isinstance(value, str) or not value:
        return None
    text = value[:-1] + "+00:00" if value.endswith("Z") else value
    try:
        parsed = datetime.fromisoformat(text)
    except ValueError:
        return None
    if parsed.tzinfo is None:
        parsed = parsed.replace(tzinfo=timezone.utc)
    return parsed.astimezone(timezone.utc)


def empty_store() -> dict[str, Any]:
    return {"version": 1, "agents": {}}


def validate_agent_id(agent_id: str) -> str:
    if AGENT_ID_PATTERN.fullmatch(agent_id) is None:
        raise UsageError(
            f"invalid agent ID '{agent_id}'; expected one uppercase letter followed by "
            "exactly three digits (for example A001 or B002)"
        )
    return agent_id


def load_store(path: Path = STORE_PATH) -> dict[str, Any]:
    if not path.exists():
        return empty_store()

    try:
        with path.open("r", encoding="utf-8-sig") as handle:
            data = json.load(handle)
    except (json.JSONDecodeError, UnicodeError) as exc:
        raise StoreError(f"invalid JSON in {path}: {exc}") from exc
    except OSError as exc:
        raise StoreError(f"could not read {path}: {exc}") from exc

    if not isinstance(data, dict):
        raise StoreError(f"{path} must contain a JSON object")
    if data.get("version") != 1:
        raise StoreError(f"{path} field 'version' must be 1")

    agents = data.get("agents")
    if not isinstance(agents, dict):
        raise StoreError(f"{path} field 'agents' must be a JSON object")

    for agent_id, agent in agents.items():
        if not isinstance(agent_id, str) or AGENT_ID_PATTERN.fullmatch(agent_id) is None:
            raise StoreError(f"{path} contains invalid agent ID {agent_id!r}")
        if not isinstance(agent, dict):
            raise StoreError(f"{path} agent {agent_id} must be a JSON object")
        if not isinstance(agent.get("online"), bool):
            raise StoreError(f"{path} agent {agent_id} field 'online' must be true or false")
        if parse_timestamp(agent.get("added_at")) is None:
            raise StoreError(f"{path} agent {agent_id} has an invalid 'added_at' timestamp")
        if parse_timestamp(agent.get("state_changed_at")) is None:
            raise StoreError(f"{path} agent {agent_id} has an invalid 'state_changed_at' timestamp")

        history = agent.get("history")
        if not isinstance(history, list):
            raise StoreError(f"{path} agent {agent_id} field 'history' must be a JSON array")
        if len(history) > HISTORY_LIMIT:
            raise StoreError(
                f"{path} agent {agent_id} has more than {HISTORY_LIMIT} status updates"
            )
        for index, update in enumerate(history):
            if not isinstance(update, dict):
                raise StoreError(f"{path} agent {agent_id} history item {index} must be an object")
            if update.get("status") not in ALLOWED_STATUSES:
                raise StoreError(f"{path} agent {agent_id} history item {index} has invalid status")
            if not isinstance(update.get("message"), str):
                raise StoreError(f"{path} agent {agent_id} history item {index} has invalid message")
            if parse_timestamp(update.get("timestamp")) is None:
                raise StoreError(f"{path} agent {agent_id} history item {index} has invalid timestamp")

    return data


def write_store(data: dict[str, Any], path: Path = STORE_PATH) -> None:
    try:
        path.parent.mkdir(parents=True, exist_ok=True)
        handle = tempfile.NamedTemporaryFile(
            "w",
            encoding="utf-8",
            newline="\n",
            dir=path.parent,
            delete=False,
        )
    except OSError as exc:
        raise StoreError(f"could not create a temporary status file beside {path}: {exc}") from exc

    temp_path = Path(handle.name)
    try:
        with handle:
            json.dump(data, handle, indent=2, sort_keys=True, ensure_ascii=False)
            handle.write("\n")
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temp_path, path)
    except OSError as exc:
        temp_path.unlink(missing_ok=True)
        raise StoreError(f"could not write {path}: {exc}") from exc
    except Exception:
        temp_path.unlink(missing_ok=True)
        raise


def format_elapsed(then: datetime, now: datetime) -> str:
    total_seconds = max(0, int((now - then).total_seconds()))
    days, remainder = divmod(total_seconds, 24 * 60 * 60)
    hours, remainder = divmod(remainder, 60 * 60)
    minutes, seconds = divmod(remainder, 60)

    parts: list[str] = []
    if days:
        parts.append(f"{days}d")
    if hours or days:
        parts.append(f"{hours}h")
    if minutes or hours or days:
        parts.append(f"{minutes}m")
    parts.append(f"{seconds}s")
    return " ".join(parts)


def display_message(message: str, fallback: str = "(no details reported)") -> str:
    flattened = " ".join(message.splitlines()).strip()
    return flattened if flattened else fallback


def online_status_sort_key(item: tuple[str, dict[str, Any]]) -> tuple[int, datetime, str]:
    agent_id, agent = item
    history = agent["history"]
    if not history:
        return (UNREPORTED_PRIORITY[1], datetime.min.replace(tzinfo=timezone.utc), agent_id)

    update = history[-1]
    action_at = parse_timestamp(update["timestamp"])
    assert action_at is not None
    return (STATUS_INFO[update["status"]][1], action_at, agent_id)


def command_status(store_path: Path, lock_path: Path) -> int:
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)

    now = utc_now()
    total_agents = len(store["agents"])
    online_agents = [
        (agent_id, agent)
        for agent_id, agent in store["agents"].items()
        if agent["online"]
    ]
    offline_count = total_agents - len(online_agents)
    print(
        f"Supervisor agent status at {format_timestamp(now)} | "
        f"online: {len(online_agents)} | offline: {offline_count}"
    )
    if not online_agents:
        print("No online agents.")
        return 0

    print("PRIORITY | AGENT | STATUS | LAST ACTION (UTC) | ELAPSED | DETAILS")
    online_agents.sort(key=online_status_sort_key)
    for agent_id, agent in online_agents:
        history = agent["history"]
        if not history:
            print(
                f"{UNREPORTED_PRIORITY[0]} | {agent_id} | unreported | never | n/a | "
                "No status has been reported."
            )
            continue

        update = history[-1]
        action_at = parse_timestamp(update["timestamp"])
        assert action_at is not None
        priority = STATUS_INFO[update["status"]][0]
        print(
            f"{priority} | {agent_id} | {update['status']} | {update['timestamp']} | "
            f"{format_elapsed(action_at, now)} | "
            f"{display_message(update['message'], STATUS_INFO[update['status']][2])}"
        )
    return 0


def command_list_agents(store_path: Path, lock_path: Path) -> int:
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)

    now_text = format_timestamp(utc_now())
    agents = sorted(store["agents"].items())
    print(f"Registered agents at {now_text} | total: {len(agents)}")
    if not agents:
        print("No registered agents.")
        return 0

    print("AGENT | STATE | LAST STATUS | LAST ACTION (UTC) | REPORTS")
    for agent_id, agent in agents:
        history = agent["history"]
        state = "online" if agent["online"] else "offline"
        if history:
            update = history[-1]
            print(
                f"{agent_id} | {state} | {update['status']} | "
                f"{update['timestamp']} | {len(history)}"
            )
        else:
            print(f"{agent_id} | {state} | unreported | never | 0")
    return 0


def command_history(
    agent_id: str,
    count: int,
    store_path: Path,
    lock_path: Path,
) -> int:
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)

    agent = store["agents"].get(agent_id)
    if agent is None:
        raise CommandError(f"agent {agent_id} does not exist")

    history = agent["history"]
    shown = min(count, len(history))
    state = "online" if agent["online"] else "offline"
    print(
        f"Status history for {agent_id} at {format_timestamp(utc_now())} | "
        f"state: {state} | showing: {shown} of {len(history)}"
    )
    if not history:
        print("No status updates recorded.")
        return 0

    print("TIMESTAMP (UTC) | PRIORITY | STATUS | DETAILS")
    for update in reversed(history[-count:]):
        priority = STATUS_INFO[update["status"]][0]
        print(
            f"{update['timestamp']} | {priority} | {update['status']} | "
            f"{display_message(update['message'], STATUS_INFO[update['status']][2])}"
        )
    return 0


def command_add_agent(agent_id: str, store_path: Path, lock_path: Path) -> int:
    now_text = format_timestamp(utc_now())
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)
        agents = store["agents"]
        existing = agents.get(agent_id)
        if existing is not None:
            state = "online" if existing["online"] else "offline"
            hint = "" if existing["online"] else f"; run -online {agent_id} to reactivate it"
            raise CommandError(f"agent {agent_id} already exists and is {state}{hint}")

        agents[agent_id] = {
            "online": True,
            "added_at": now_text,
            "state_changed_at": now_text,
            "history": [],
        }
        write_store(store, store_path)

    print(f"[{now_text}] Agent {agent_id} added and online.")
    return 0


def command_online(agent_id: str, store_path: Path, lock_path: Path) -> int:
    now_text = format_timestamp(utc_now())
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)
        agent = store["agents"].get(agent_id)
        if agent is None:
            raise CommandError(f"agent {agent_id} does not exist; run -add-agent {agent_id} first")
        if agent["online"]:
            raise CommandError(f"agent {agent_id} is already online")

        agent["online"] = True
        agent["state_changed_at"] = now_text
        write_store(store, store_path)

    print(f"[{now_text}] Agent {agent_id} is online; history preserved.")
    return 0


def command_report(
    status: str,
    agent_id: str,
    message: str,
    store_path: Path,
    lock_path: Path,
) -> int:
    now_text = format_timestamp(utc_now())
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)
        agent = store["agents"].get(agent_id)
        if agent is None:
            raise CommandError(f"agent {agent_id} does not exist; run -add-agent {agent_id} first")
        if not agent["online"]:
            raise CommandError(f"agent {agent_id} is offline; run -online {agent_id} first")

        agent["history"].append(
            {"timestamp": now_text, "status": status, "message": message}
        )
        agent["history"] = agent["history"][-HISTORY_LIMIT:]
        write_store(store, store_path)

    print(
        f"[{now_text}] {agent_id} reported {status}: "
        f"{display_message(message, STATUS_INFO[status][2])}"
    )
    return 0


def command_offline(agent_id: str, store_path: Path, lock_path: Path) -> int:
    now_text = format_timestamp(utc_now())
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)
        agent = store["agents"].get(agent_id)
        if agent is None:
            raise CommandError(f"agent {agent_id} does not exist")
        if not agent["online"]:
            raise CommandError(f"agent {agent_id} is already offline")

        agent["online"] = False
        agent["state_changed_at"] = now_text
        write_store(store, store_path)

    print(f"[{now_text}] Agent {agent_id} is offline; history preserved.")
    return 0


def command_clear_agent(agent_id: str, store_path: Path, lock_path: Path) -> int:
    now_text = format_timestamp(utc_now())
    with FileLock(lock_path, LOCK_TIMEOUT_SECONDS):
        store = load_store(store_path)
        if agent_id not in store["agents"]:
            raise CommandError(f"agent {agent_id} does not exist")
        del store["agents"][agent_id]
        write_store(store, store_path)

    print(f"[{now_text}] Agent {agent_id} and all of its history were deleted.")
    return 0


def usage() -> str:
    statuses = "|".join(STATUS_CHOICES)
    lines = [
        "Usage:\n",
        "  python status.py -status\n",
        "  python status.py -list-agents\n",
        "  python status.py -history AGENTID [COUNT]\n",
        f"  python status.py -report {{{statuses}}} AGENTID [message ...]\n",
        "  python status.py -online AGENTID\n",
        "  python status.py -offline AGENTID\n",
        "  python status.py -clear-agent AGENTID\n",
        "  python status.py -add-agent AGENTID\n",
        "\n",
        "Commands:\n",
        "  -status       Show online agents, ordered by supervisor priority.\n",
        "  -list-agents  Show every registered agent, including offline agents.\n",
        "  -history      Show the newest COUNT reports (default 10, maximum 100).\n",
        "  -report       Record an agent's current workflow state and optional details.\n",
        "  -online       Bring a registered offline agent online; preserve history.\n",
        "  -offline      Hide a registered agent from -status; preserve history.\n",
        "  -clear-agent  Delete a registered agent and all of its history.\n",
        "  -add-agent    Register a new online agent.\n",
        "\n",
        "Workflow statuses (shown in supervisor priority order):\n",
    ]
    for status, (priority, _rank, description) in STATUS_INFO.items():
        lines.append(f"  {status:<17} [{priority}] {description}\n")
    lines.extend(
        [
            "\n",
            "AGENTID must be one uppercase letter followed by exactly three digits,\n",
            "for example A001 or B002. A quoted detail message is optional. Agents\n",
            "must be registered and online before reporting. When details are omitted,\n",
            "the workflow description above is displayed as the default message.\n",
        ]
    )
    return "".join(lines)


def run(
    argv: list[str],
    store_path: Path = STORE_PATH,
    lock_path: Path = LOCK_PATH,
) -> int:
    if not argv:
        raise UsageError("missing command")
    if argv[0] in {"-h", "--help"}:
        if len(argv) != 1:
            raise UsageError(f"{argv[0]} does not accept arguments")
        print(usage(), end="")
        return 0

    command = argv[0]
    if command == "-status":
        if len(argv) != 1:
            raise UsageError("-status does not accept arguments")
        return command_status(store_path, lock_path)

    if command == "-list-agents":
        if len(argv) != 1:
            raise UsageError("-list-agents does not accept arguments")
        return command_list_agents(store_path, lock_path)

    if command == "-history":
        if len(argv) not in {2, 3}:
            raise UsageError("-history requires an agent ID and optional count")
        agent_id = validate_agent_id(argv[1])
        count = 10
        if len(argv) == 3:
            if not argv[2].isdigit():
                raise UsageError("history count must be an integer from 1 through 100")
            count = int(argv[2])
            if not 1 <= count <= HISTORY_LIMIT:
                raise UsageError("history count must be an integer from 1 through 100")
        return command_history(agent_id, count, store_path, lock_path)

    if command == "-report":
        if len(argv) < 3:
            raise UsageError("-report requires a status and an agent ID")
        status = argv[1]
        if status not in ALLOWED_STATUSES:
            allowed = ", ".join(STATUS_CHOICES)
            raise UsageError(f"invalid report status '{status}'; expected one of: {allowed}")
        agent_id = validate_agent_id(argv[2])
        message = " ".join(argv[3:]).strip()
        return command_report(status, agent_id, message, store_path, lock_path)

    if command in {"-online", "-offline", "-clear-agent", "-add-agent"}:
        if len(argv) != 2:
            raise UsageError(f"{command} requires exactly one agent ID")
        agent_id = validate_agent_id(argv[1])
        if command == "-online":
            return command_online(agent_id, store_path, lock_path)
        if command == "-offline":
            return command_offline(agent_id, store_path, lock_path)
        if command == "-clear-agent":
            return command_clear_agent(agent_id, store_path, lock_path)
        return command_add_agent(agent_id, store_path, lock_path)

    raise UsageError(f"unknown command '{command}'")


def main() -> int:
    try:
        return run(sys.argv[1:])
    except UsageError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        print(usage(), end="", file=sys.stderr)
        return 2
    except CommandError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1
    except TimeoutError as exc:
        print(f"Error: timed out waiting for status lock: {exc}", file=sys.stderr)
        return 3
    except StoreError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 4


if __name__ == "__main__":
    raise SystemExit(main())
