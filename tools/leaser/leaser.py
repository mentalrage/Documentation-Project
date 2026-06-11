#!/usr/bin/env python3
"""Small file lease tracker for coordinating documentation agents.

Usage:
  python leaser.py AgentID lease <filepath> [filepath ...]
  python leaser.py AgentID unlease [filepath ...]
  python leaser.py AgentID leases
  python leaser.py AgentID leases all
  python leaser.py leases

Leases are stored in lease.json beside this script. All reads and writes are
serialized with lease.lock so concurrent agents cannot claim the same file.
When report-file mode is enabled, read current_leases.md instead of running
lease info commands.
"""

from __future__ import annotations

import json
import os
import sys
import tempfile
import time
from datetime import datetime, timedelta, timezone
from pathlib import Path
from typing import Any


TOOL_DIR = Path(__file__).resolve().parent
STORE_PATH = TOOL_DIR / "lease.json"
LOCK_PATH = TOOL_DIR / "lease.lock"
DEFAULT_LEASE_SECONDS = 15 * 60
LOCK_TIMEOUT_SECONDS = 30.0
LOCK_POLL_SECONDS = 0.1
ENABLE_REPORT_KEY = "enable_current_lease_reporting_file_generation"
REPORT_PATHS_KEY = "paths"
REPORT_FILENAME_KEY = "lease_reporting_filename"
DISABLE_INFO_KEY = "disable_info_commands_when_report_file_enabled"
DEFAULT_REPORT_FILENAME = "current_leases.md"
LEGACY_ENABLE_REPORT_KEY = "enable_current_lease_report_file_generation"
LEGACY_REPORT_PATHS_KEY = "current_lease_report_paths"
LEGACY_REPORT_FILENAME_KEY = "current_lease_report_filename"


class UsageError(Exception):
    pass


class StoreError(Exception):
    pass


class FileLock:
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
        self.path.parent.mkdir(parents=True, exist_ok=True)
        self.handle = self.path.open("a+", encoding="utf-8")
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
    if not isinstance(value, str) or not value.strip():
        return None

    text = value.strip()
    if text.endswith("Z"):
        text = text[:-1] + "+00:00"

    try:
        parsed = datetime.fromisoformat(text)
    except ValueError:
        return None

    if parsed.tzinfo is None:
        parsed = parsed.replace(tzinfo=timezone.utc)
    return parsed.astimezone(timezone.utc)


def normalize_lease_seconds(value: Any) -> int | None:
    if isinstance(value, bool):
        return None
    if isinstance(value, int):
        seconds = value
    elif isinstance(value, str) and value.strip().isdigit():
        seconds = int(value.strip())
    else:
        return None

    return seconds if seconds > 0 else None


def lease_seconds(store: dict[str, Any]) -> int:
    return normalize_lease_seconds(store.get("lease_seconds")) or DEFAULT_LEASE_SECONDS


def effective_expires_at(entry: dict[str, Any], duration_seconds: int) -> datetime | None:
    stored_expires_at = parse_timestamp(entry.get("expires_at"))
    leased_at = parse_timestamp(entry.get("leased_at"))
    if leased_at is None:
        return stored_expires_at

    configured_expires_at = leased_at + timedelta(seconds=duration_seconds)
    if stored_expires_at is None:
        return configured_expires_at

    return min(stored_expires_at, configured_expires_at)


def empty_store() -> dict[str, Any]:
    return {
        "version": 1,
        "lease_seconds": DEFAULT_LEASE_SECONDS,
        ENABLE_REPORT_KEY: False,
        REPORT_PATHS_KEY: [],
        REPORT_FILENAME_KEY: DEFAULT_REPORT_FILENAME,
        DISABLE_INFO_KEY: False,
        "leases": {},
    }


def load_store(path: Path = STORE_PATH) -> dict[str, Any]:
    if not path.exists():
        return empty_store()

    try:
        with path.open("r", encoding="utf-8-sig") as handle:
            data = json.load(handle)
    except json.JSONDecodeError as exc:
        raise StoreError(f"invalid JSON in {path}: {exc}") from exc
    except OSError as exc:
        raise StoreError(f"could not read {path}: {exc}") from exc

    if not isinstance(data, dict):
        raise StoreError(f"{path} must contain a JSON object")

    leases = data.get("leases")
    if leases is None:
        data["leases"] = {}
    elif not isinstance(leases, dict):
        raise StoreError(f"{path} field 'leases' must be a JSON object")

    legacy_keys = [
        (LEGACY_ENABLE_REPORT_KEY, ENABLE_REPORT_KEY),
        (LEGACY_REPORT_PATHS_KEY, REPORT_PATHS_KEY),
        (LEGACY_REPORT_FILENAME_KEY, REPORT_FILENAME_KEY),
    ]
    for legacy_key, current_key in legacy_keys:
        if legacy_key in data:
            data.setdefault(current_key, data[legacy_key])
            del data[legacy_key]

    data.setdefault("version", 1)
    data.setdefault("lease_seconds", DEFAULT_LEASE_SECONDS)
    normalized_lease_seconds = normalize_lease_seconds(data.get("lease_seconds"))
    if normalized_lease_seconds is None:
        raise StoreError(f"{path} field 'lease_seconds' must be a positive integer")
    data["lease_seconds"] = normalized_lease_seconds
    data.setdefault(ENABLE_REPORT_KEY, False)
    data.setdefault(REPORT_PATHS_KEY, [])
    data.setdefault(REPORT_FILENAME_KEY, DEFAULT_REPORT_FILENAME)
    data.setdefault(DISABLE_INFO_KEY, False)

    report_paths = data.get(REPORT_PATHS_KEY)
    if isinstance(report_paths, str):
        data[REPORT_PATHS_KEY] = [report_paths]
    elif not isinstance(report_paths, list) or not all(isinstance(item, str) for item in report_paths):
        raise StoreError(f"{path} field '{REPORT_PATHS_KEY}' must be a string or list of strings")

    report_filename = data.get(REPORT_FILENAME_KEY)
    if not isinstance(report_filename, str) or not report_filename.strip():
        raise StoreError(f"{path} field '{REPORT_FILENAME_KEY}' must be a non-empty string")
    report_name = Path(report_filename)
    if report_name.is_absolute() or report_name.name != report_filename:
        raise StoreError(f"{path} field '{REPORT_FILENAME_KEY}' must be a filename, not a path")

    return data


def write_store(data: dict[str, Any], path: Path = STORE_PATH) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    handle = tempfile.NamedTemporaryFile(
        "w",
        encoding="utf-8",
        newline="\n",
        dir=path.parent,
        delete=False,
    )
    temp_path = Path(handle.name)

    try:
        with handle:
            json.dump(data, handle, indent=2, sort_keys=True)
            handle.write("\n")
        os.replace(temp_path, path)
    except Exception:
        temp_path.unlink(missing_ok=True)
        raise


def markdown_cell(value: Any) -> str:
    return str(value).replace("\r", " ").replace("\n", " ").replace("|", "\\|")


def report_paths(store: dict[str, Any]) -> list[Path]:
    raw_paths = store.get(REPORT_PATHS_KEY, [])
    if isinstance(raw_paths, str):
        raw_paths = [raw_paths]

    paths: list[Path] = []
    for value in raw_paths:
        if not isinstance(value, str) or not value.strip():
            continue
        path = Path(value).expanduser()
        if not path.is_absolute():
            path = TOOL_DIR / path
        paths.append(path)
    return paths


def report_targets(store: dict[str, Any]) -> list[Path]:
    filename = str(store.get(REPORT_FILENAME_KEY, DEFAULT_REPORT_FILENAME)).strip()
    return [path / filename for path in report_paths(store)]


def current_lease_report_text(store: dict[str, Any]) -> str:
    rows: list[tuple[str, str, str, str]] = []
    duration_seconds = lease_seconds(store)

    for key, entry in store.get("leases", {}).items():
        if not isinstance(entry, dict):
            continue
        agent_id = str(entry.get("agent_id", ""))
        lease_path = str(entry.get("path", key))
        leased_at = str(entry.get("leased_at", ""))
        effective_expiration = effective_expires_at(entry, duration_seconds)
        expires_at = format_timestamp(effective_expiration) if effective_expiration is not None else ""
        rows.append((agent_id, lease_path, leased_at, expires_at))

    lines = [
        "# Current Leases",
        "",
        "Generated by `leaser.py`. Do not edit this file.",
        "",
        "| AgentID | lease path | time created | expiration |",
        "| --- | --- | --- | --- |",
    ]

    for agent_id, lease_path, leased_at, expires_at in sorted(
        rows, key=lambda row: (row[0].lower(), row[1].lower())
    ):
        lines.append(
            f"| {markdown_cell(agent_id)} | {markdown_cell(lease_path)} | "
            f"{markdown_cell(leased_at)} | {markdown_cell(expires_at)} |"
        )

    if not rows:
        lines.extend(["", "No active leases."])

    lines.append("")
    return "\n".join(lines)


def write_text_atomic(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    handle = tempfile.NamedTemporaryFile(
        "w",
        encoding="utf-8",
        newline="\n",
        dir=path.parent,
        delete=False,
    )
    temp_path = Path(handle.name)

    try:
        with handle:
            handle.write(text)
        os.replace(temp_path, path)
    except Exception:
        temp_path.unlink(missing_ok=True)
        raise


def write_current_lease_reports(store: dict[str, Any]) -> None:
    if not store.get(ENABLE_REPORT_KEY):
        return

    text = current_lease_report_text(store)
    for target in report_targets(store):
        try:
            write_text_atomic(target, text)
        except OSError as exc:
            raise StoreError(f"could not write current lease report {target}: {exc}") from exc


def report_location_text(store: dict[str, Any]) -> str:
    targets = report_targets(store)
    if not targets:
        return "the configured current lease report file"
    return ", ".join(str(target) for target in targets)


def info_commands_disabled(store: dict[str, Any]) -> bool:
    return bool(store.get(ENABLE_REPORT_KEY)) and bool(store.get(DISABLE_INFO_KEY))


def path_key(path: Path) -> str:
    text = str(path)
    if os.name == "nt":
        text = os.path.normcase(text)
    return text


def resolve_input_path(value: str, *, must_be_file: bool) -> tuple[Path | None, str | None]:
    raw = Path(value).expanduser()
    candidate = raw if raw.is_absolute() else Path.cwd() / raw

    try:
        exists = candidate.exists()
    except OSError:
        exists = False

    if must_be_file:
        if not exists:
            return None, "File not found"
        if not candidate.is_file():
            return None, "Not a file"

    try:
        strict = must_be_file or exists
        return candidate.resolve(strict=strict), None
    except OSError as exc:
        if must_be_file:
            return None, str(exc)
        return candidate.absolute(), None


def purge_expired_leases(store: dict[str, Any], now: datetime) -> bool:
    leases = store["leases"]
    expired_keys: list[str] = []
    duration_seconds = lease_seconds(store)

    for key, entry in leases.items():
        if not isinstance(entry, dict):
            expired_keys.append(key)
            continue

        expires_at = effective_expires_at(entry, duration_seconds)
        if expires_at is None or expires_at <= now:
            expired_keys.append(key)

    for key in expired_keys:
        del leases[key]

    return bool(expired_keys)


def store_entry(
    agent_id: str,
    resolved_path: Path,
    requested_path: str,
    now: datetime,
    duration_seconds: int,
) -> dict[str, str]:
    expires_at = now + timedelta(seconds=duration_seconds)
    return {
        "agent_id": agent_id,
        "path": str(resolved_path),
        "requested_path": requested_path,
        "leased_at": format_timestamp(now),
        "expires_at": format_timestamp(expires_at),
    }


def print_statuses(statuses: list[tuple[str, str]]) -> None:
    for path, status in statuses:
        print(f"{path}: {status}")


def command_lease(agent_id: str, path_args: list[str]) -> int:
    if not path_args:
        raise UsageError("lease requires at least one filepath")

    now = utc_now()
    statuses: list[tuple[str, str]] = []
    changed = False

    with FileLock(LOCK_PATH, LOCK_TIMEOUT_SECONDS):
        store = load_store()
        changed = purge_expired_leases(store, now)
        leases = store["leases"]
        duration_seconds = lease_seconds(store)

        for path_arg in path_args:
            resolved_path, error = resolve_input_path(path_arg, must_be_file=True)
            if error is not None or resolved_path is None:
                statuses.append((path_arg, f"Rejected[{error}]"))
                continue

            key = path_key(resolved_path)
            if key in leases:
                statuses.append((path_arg, "Rejected[Already has lease]"))
                continue

            leases[key] = store_entry(agent_id, resolved_path, path_arg, now, duration_seconds)
            statuses.append((path_arg, "Success"))
            changed = True

        if changed:
            write_store(store)
        write_current_lease_reports(store)

    print_statuses(statuses)
    return 1 if any(status != "Success" for _, status in statuses) else 0


def command_unlease(agent_id: str, path_args: list[str]) -> int:
    now = utc_now()
    statuses: list[tuple[str, str]] = []
    changed = False

    with FileLock(LOCK_PATH, LOCK_TIMEOUT_SECONDS):
        store = load_store()
        changed = purge_expired_leases(store, now)
        leases = store["leases"]

        if not path_args:
            owned_keys = [
                key
                for key, entry in leases.items()
                if isinstance(entry, dict) and entry.get("agent_id") == agent_id
            ]
            if not owned_keys:
                if changed:
                    write_store(store)
                write_current_lease_reports(store)
                print(f"{agent_id}: No active leases")
                return 0

            for key in owned_keys:
                entry = leases[key]
                statuses.append((str(entry.get("path", key)), "Success"))
                del leases[key]
            changed = True
        else:
            for path_arg in path_args:
                resolved_path, error = resolve_input_path(path_arg, must_be_file=False)
                if error is not None or resolved_path is None:
                    statuses.append((path_arg, f"Rejected[{error}]"))
                    continue

                key = path_key(resolved_path)
                entry = leases.get(key)
                if not isinstance(entry, dict):
                    statuses.append((path_arg, "Rejected[No active lease]"))
                    continue

                owner = entry.get("agent_id")
                if owner != agent_id:
                    statuses.append((path_arg, f"Rejected[Lease owned by {owner}]"))
                    continue

                del leases[key]
                statuses.append((path_arg, "Success"))
                changed = True

        if changed:
            write_store(store)
        write_current_lease_reports(store)

    print_statuses(statuses)
    return 1 if any(status != "Success" for _, status in statuses) else 0


def remaining_text(now: datetime, expires_at: datetime) -> str:
    total_seconds = max(0, int((expires_at - now).total_seconds() + 0.999))
    minutes, seconds = divmod(total_seconds, 60)
    return f"{minutes}m {seconds}s"


def command_leases(agent_id: str) -> int:
    now = utc_now()
    changed = False
    rows: list[tuple[str, datetime, datetime]] = []

    with FileLock(LOCK_PATH, LOCK_TIMEOUT_SECONDS):
        store = load_store()
        changed = purge_expired_leases(store, now)
        leases = store["leases"]
        duration_seconds = lease_seconds(store)

        if info_commands_disabled(store):
            if changed:
                write_store(store)
            write_current_lease_reports(store)
            print(
                "Error: lease info commands are disabled because current lease "
                f"reporting is enabled. Read {report_location_text(store)} instead.",
                file=sys.stderr,
            )
            return 2

        for key, entry in leases.items():
            if not isinstance(entry, dict) or entry.get("agent_id") != agent_id:
                continue

            leased_at = parse_timestamp(entry.get("leased_at"))
            expires_at = effective_expires_at(entry, duration_seconds)
            if leased_at is None or expires_at is None:
                continue

            rows.append((str(entry.get("path", key)), leased_at, expires_at))

        if changed:
            write_store(store)
        write_current_lease_reports(store)

    if not rows:
        print(f"{agent_id}: No active leases")
        return 0

    for path, leased_at, expires_at in sorted(rows, key=lambda row: row[0].lower()):
        print(
            f"{path}: leased_at={format_timestamp(leased_at)} "
            f"expires_at={format_timestamp(expires_at)} "
            f"remaining={remaining_text(now, expires_at)}"
        )

    return 0


def command_all_leases() -> int:
    now = utc_now()
    changed = False
    rows: list[tuple[str, datetime, datetime]] = []

    with FileLock(LOCK_PATH, LOCK_TIMEOUT_SECONDS):
        store = load_store()
        changed = purge_expired_leases(store, now)
        leases = store["leases"]
        duration_seconds = lease_seconds(store)

        if info_commands_disabled(store):
            if changed:
                write_store(store)
            write_current_lease_reports(store)
            print(
                "Error: lease info commands are disabled because current lease "
                f"reporting is enabled. Read {report_location_text(store)} instead.",
                file=sys.stderr,
            )
            return 2

        for key, entry in leases.items():
            if not isinstance(entry, dict):
                continue

            leased_at = parse_timestamp(entry.get("leased_at"))
            expires_at = effective_expires_at(entry, duration_seconds)
            if leased_at is None or expires_at is None:
                continue

            rows.append((str(entry.get("path", key)), leased_at, expires_at))

        if changed:
            write_store(store)
        write_current_lease_reports(store)

    if not rows:
        print("No active leases")
        return 0

    for path, leased_at, expires_at in sorted(rows, key=lambda row: row[0].lower()):
        print(
            f"{path}: leased_at={format_timestamp(leased_at)} "
            f"expires_at={format_timestamp(expires_at)} "
            f"remaining={remaining_text(now, expires_at)}"
        )

    return 0


def usage() -> str:
    return (
        "Usage:\n"
        "  python leaser.py AgentID lease <filepath> [filepath ...]\n"
        "  python leaser.py AgentID unlease [filepath ...]\n"
        "  python leaser.py AgentID leases\n"
        "  python leaser.py AgentID leases all\n"
        "  python leaser.py leases\n"
        "\n"
        "Note: when current lease report-file mode is enabled, leases info commands\n"
        "are rejected. Read the configured current_leases.md report instead.\n"
    )


def run(argv: list[str]) -> int:
    if not argv or argv[0] in {"-h", "--help"}:
        print(usage(), end="")
        return 0 if argv else 2

    if len(argv) == 1 and argv[0].strip().lower() == "leases":
        return command_all_leases()

    if len(argv) < 2:
        raise UsageError("missing command")

    agent_id = argv[0].strip()
    if not agent_id:
        raise UsageError("AgentID cannot be blank")

    command = argv[1].strip().lower()
    path_args = argv[2:]

    if command == "lease":
        return command_lease(agent_id, path_args)
    if command == "unlease":
        return command_unlease(agent_id, path_args)
    if command == "leases":
        if not path_args:
            return command_leases(agent_id)
        if len(path_args) == 1 and path_args[0].strip().lower() == "all":
            return command_all_leases()
        else:
            raise UsageError("leases does not accept filepath arguments")

    raise UsageError(f"unknown command: {argv[1]}")


def main() -> int:
    try:
        return run(sys.argv[1:])
    except UsageError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        print(usage(), end="", file=sys.stderr)
        return 2
    except TimeoutError as exc:
        print(f"Error: timed out waiting for lease lock: {exc}", file=sys.stderr)
        return 3
    except StoreError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 4


if __name__ == "__main__":
    raise SystemExit(main())
