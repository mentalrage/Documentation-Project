#!/usr/bin/env python3
"""Queueing frontend for validator_background.py.

Every invocation writes one queue job, starts the background worker if needed,
waits for that job result, then relays the worker's stdout/stderr and exit code.
This keeps concurrent validator.py calls ordered without racing validator.ini.
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import tempfile
import time
import uuid
from datetime import datetime
from pathlib import Path


TOOL_DIR = Path(__file__).resolve().parent
BACKGROUND = TOOL_DIR / "validator_background.py"
DEFAULT_DOC_ROOT = TOOL_DIR.parent
QUEUE_DIR = TOOL_DIR / "validator_queue"
QUEUE_LOCK = TOOL_DIR / "validator_queue.lock"
WORKER_LOCK = TOOL_DIR / "validator_worker.lock"
QUEUE_COUNTER = QUEUE_DIR / "next_job_id.txt"
COMMAND_STATE = TOOL_DIR / "validator_command_state.json"
QUEUE_POLL_SECONDS = 0.25
COMMAND_ALIASES = {
    "execute_report": "execute-report",
    "execute-report": "execute-report",
    "invalidate_execute": "invalidate-execute",
    "invalidate-execute": "invalidate-execute",
    "execute_rescan_reports": "execute-rescan-reports",
    "execute-rescan-reports": "execute-rescan-reports",
    "execute_confirm_change": "execute-confirm-change",
    "execute-confirm-change": "execute-confirm-change",
    "execute_confirm_removed_archives": "execute-confirm-removed-archives",
    "execute-confirm-removed-archives": "execute-confirm-removed-archives",
    "executed_reassign": "executed-reassign",
    "executed-reassign": "executed-reassign",
    "executed_mark_invalid": "executed-mark-invalid",
    "executed-mark-invalid": "executed-mark-invalid",
    "executed_mark_needs_revalidation": "executed-mark-needs-revalidation",
    "executed-mark-needs-revalidation": "executed-mark-needs-revalidation",
    "executed_clear_revalidation": "executed-clear-revalidation",
    "executed-clear-revalidation": "executed-clear-revalidation",
    "active_clear_revalidation": "active-clear-revalidation",
    "active-clear-revalidation": "active-clear-revalidation",
    "migrate_executed_reports": "migrate-executed-reports",
    "migrate-executed-reports": "migrate-executed-reports",
    "migrate_report_agent_specs": "migrate-report-agent-specs",
    "migrate-report-agent-specs": "migrate-report-agent-specs",
    "migrate_report_history": "migrate-report-history",
    "migrate-report-history": "migrate-report-history",
    "migrate_reconstruction_h": "migrate-reconstruction-h",
    "migrate-reconstruction-h": "migrate-reconstruction-h",
}


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
        deadline = None if self.timeout_seconds < 0 else time.monotonic() + self.timeout_seconds
        while True:
            try:
                self._lock_nonblocking()
                return
            except OSError:
                if self.timeout_seconds == 0:
                    self.handle.close()
                    self.handle = None
                    raise TimeoutError(str(self.path))
                if deadline is not None and time.monotonic() >= deadline:
                    self.handle.close()
                    self.handle = None
                    raise TimeoutError(str(self.path))
                time.sleep(QUEUE_POLL_SECONDS)

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


def write_json_atomic(data: dict, path: Path) -> None:
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
        temp_path.replace(path)
    except Exception:
        temp_path.unlink(missing_ok=True)
        raise


def command_id_display(value: int) -> str:
    return f"{value:012d}"


def read_command_state() -> dict:
    try:
        data = json.loads(COMMAND_STATE.read_text(encoding="utf-8"))
    except (FileNotFoundError, json.JSONDecodeError, OSError):
        data = {}
    if not isinstance(data, dict):
        data = {}
    raw_last = data.get("last_command_id", 0)
    try:
        last_id = int(raw_last)
    except (TypeError, ValueError):
        last_id = 0
    timestamp = data.get("last_command_timestamp", "")
    if not isinstance(timestamp, str):
        timestamp = ""
    return {
        "schema": 1,
        "last_command_id": max(0, last_id),
        "last_command_timestamp": timestamp,
    }


def allocate_command_context_locked() -> dict:
    state = read_command_state()
    command_id = int(state.get("last_command_id", 0)) + 1
    timestamp = datetime.now().astimezone().isoformat(timespec="seconds")
    new_state = {
        "schema": 1,
        "last_command_id": command_id,
        "last_command_timestamp": timestamp,
    }
    write_json_atomic(new_state, COMMAND_STATE)
    return {
        "command_id": command_id,
        "command_id_display": command_id_display(command_id),
        "command_timestamp": timestamp,
    }


def allocate_command_context() -> dict:
    with FileLock(QUEUE_LOCK, -1):
        return allocate_command_context_locked()


def print_command_preamble(context: dict) -> None:
    print(f"command_id: {context['command_id_display']}", flush=True)
    print(f"command_timestamp: {context['command_timestamp']}", flush=True)


def command_context_args(context: dict) -> list[str]:
    return [
        "--command-id",
        str(context["command_id"]),
        "--command-id-display",
        str(context["command_id_display"]),
        "--command-timestamp",
        str(context["command_timestamp"]),
    ]


def safe_resolve(path: Path) -> Path:
    try:
        return path.resolve(strict=False)
    except RuntimeError:
        return path.absolute()


def docs_relative_candidate(root: Path, candidate: Path) -> str | None:
    root_resolved = safe_resolve(root)
    candidate_resolved = safe_resolve(candidate)
    try:
        relative = candidate_resolved.relative_to(root_resolved)
    except ValueError:
        return None
    if len(relative.parts) < 2 or not relative.parts[0].startswith("by-"):
        return None
    return relative.as_posix()


def project_documentation_suffix(path: Path) -> Path | None:
    parts = path.parts
    lower_parts = [part.lower() for part in parts]
    if "project-documentation" not in lower_parts:
        return None
    index = len(lower_parts) - 1 - lower_parts[::-1].index("project-documentation")
    suffix_parts = parts[index + 1 :]
    if not suffix_parts:
        return None
    return Path(*suffix_parts)


def normalize_file_argument(root: Path, value: str, cwd: Path) -> str:
    """Return a docs-root-relative by-* path when the file argument is recognizable.

    The background worker also normalizes paths. Doing this before queueing keeps
    jobs independent from the caller's current directory and from junction path
    spelling versus resolved path spelling.
    """

    raw_path = Path(value).expanduser()
    candidates: list[Path] = []

    def add_candidate(path: Path) -> None:
        if path not in candidates:
            candidates.append(path)

    if raw_path.is_absolute():
        add_candidate(raw_path)
    else:
        add_candidate(cwd / raw_path)
        add_candidate(root / raw_path)

    suffix = project_documentation_suffix(raw_path)
    if suffix is not None:
        add_candidate(root / suffix)

    cwd_suffix = project_documentation_suffix(cwd / raw_path)
    if cwd_suffix is not None:
        add_candidate(root / cwd_suffix)

    for candidate in candidates:
        relative = docs_relative_candidate(root, candidate)
        if relative is not None:
            return relative

    if suffix is not None and len(suffix.parts) >= 2 and suffix.parts[0].startswith("by-"):
        return suffix.as_posix()

    return value


def root_from_validator_args(argv: list[str], cwd: Path) -> Path:
    root = DEFAULT_DOC_ROOT
    for index, item in enumerate(argv):
        value: str | None = None
        if item == "--root" and index + 1 < len(argv):
            value = argv[index + 1]
        elif item.startswith("--root="):
            value = item.split("=", 1)[1]
        if value:
            raw_root = Path(value).expanduser()
            root = raw_root if raw_root.is_absolute() else cwd / raw_root
    return safe_resolve(root)


def normalize_validator_args(argv: list[str]) -> list[str]:
    argv = normalize_command_aliases(argv)
    root = root_from_validator_args(argv, Path.cwd())
    normalized = list(argv)
    index = 0
    while index < len(normalized):
        item = normalized[index]
        if item == "--file" and index + 1 < len(normalized):
            normalized[index + 1] = normalize_file_argument(root, normalized[index + 1], Path.cwd())
            index += 2
            continue
        if item.startswith("--file="):
            value = item.split("=", 1)[1]
            normalized[index] = f"--file={normalize_file_argument(root, value, Path.cwd())}"
        index += 1
    return normalized


def command_positionals(items: list[str], maximum: int) -> tuple[list[str], list[str]]:
    positionals: list[str] = []
    rest: list[str] = []
    options_started = False
    for item in items:
        if not options_started and len(positionals) < maximum and not item.startswith("-"):
            positionals.append(item)
        else:
            options_started = True
            rest.append(item)
    return positionals, rest


def normalize_command_aliases(argv: list[str]) -> list[str]:
    if not argv:
        return argv
    command = COMMAND_ALIASES.get(argv[0])
    if command is None:
        return argv

    if command == "execute-report":
        positionals, rest = command_positionals(argv[1:], 3)
        if len(positionals) < 2:
            return argv
        normalized = [
            "--mode",
            command,
            "--agent-id",
            positionals[0],
            "--report-file",
            positionals[1],
        ]
        if len(positionals) >= 3:
            normalized.extend(["--target-uid", positionals[2]])
        return normalized + rest

    if command in {
        "invalidate-execute",
        "execute-confirm-change",
        "executed-mark-invalid",
        "executed-mark-needs-revalidation",
        "executed-clear-revalidation",
        "active-clear-revalidation",
    }:
        positionals, rest = command_positionals(argv[1:], 2)
        if len(positionals) < 2 and "--report-path" not in rest and not any(item.startswith("--report-path=") for item in rest):
            return argv
        normalized = ["--mode", command]
        if len(positionals) >= 2:
            normalized.extend(["--agent-id", positionals[0], "--report-file", positionals[1]])
        return [*normalized, *rest]

    if command == "executed-reassign":
        positionals, rest = command_positionals(argv[1:], 3)
        if len(positionals) < 3:
            return argv
        return [
            "--mode",
            command,
            "--agent-id",
            positionals[0],
            "--report-file",
            positionals[1],
            "--new-agent-id",
            positionals[2],
            *rest,
        ]

    return ["--mode", command, *argv[1:]]


def read_counter() -> int:
    try:
        return int(QUEUE_COUNTER.read_text(encoding="utf-8").strip() or "0")
    except FileNotFoundError:
        return 0
    except ValueError:
        return 0


def write_counter(value: int) -> None:
    QUEUE_COUNTER.parent.mkdir(parents=True, exist_ok=True)
    QUEUE_COUNTER.write_text(f"{value}\n", encoding="utf-8")


def enqueue_job(argv: list[str]) -> tuple[str, Path, dict]:
    jobs_dir = QUEUE_DIR / "jobs"
    results_dir = QUEUE_DIR / "results"
    jobs_dir.mkdir(parents=True, exist_ok=True)
    results_dir.mkdir(parents=True, exist_ok=True)

    with FileLock(QUEUE_LOCK, -1):
        command_context = allocate_command_context_locked()
        job_id = read_counter() + 1
        write_counter(job_id)
        token = uuid.uuid4().hex[:12]
        job_name = f"{job_id:012d}-{os.getpid()}-{token}.json"
        job_path = jobs_dir / job_name
        result_path = results_dir / f"{Path(job_name).stem}.result.json"
        job = {
            "id": job_id,
            "argv": argv,
            "command_id": command_context["command_id"],
            "command_id_display": command_context["command_id_display"],
            "command_timestamp": command_context["command_timestamp"],
            "cwd": str(Path.cwd()),
            "enqueued_at": datetime.now().isoformat(timespec="seconds"),
            "pid": os.getpid(),
            "result_path": str(result_path),
        }
        write_json_atomic(job, job_path)
    return job_name, result_path, command_context


def lock_is_held(path: Path) -> bool:
    try:
        with FileLock(path, 0):
            return False
    except TimeoutError:
        return True


def start_worker_if_needed() -> None:
    if lock_is_held(WORKER_LOCK):
        return

    QUEUE_DIR.mkdir(parents=True, exist_ok=True)
    log_path = QUEUE_DIR / "validator_worker.log"
    command = [sys.executable, str(BACKGROUND), "--worker"]
    creationflags = 0
    if os.name == "nt":
        creationflags = getattr(subprocess, "CREATE_NO_WINDOW", 0)
    with log_path.open("ab") as log:
        subprocess.Popen(
            command,
            cwd=str(TOOL_DIR),
            stdin=subprocess.DEVNULL,
            stdout=log,
            stderr=log,
            creationflags=creationflags,
            close_fds=False,
        )


def queue_status() -> int:
    jobs = sorted((QUEUE_DIR / "jobs").glob("*.json")) if (QUEUE_DIR / "jobs").exists() else []
    processing = (
        sorted((QUEUE_DIR / "processing").glob("*.json"))
        if (QUEUE_DIR / "processing").exists()
        else []
    )
    results = (
        sorted((QUEUE_DIR / "results").glob("*.result.json"))
        if (QUEUE_DIR / "results").exists()
        else []
    )
    generated_results = (
        sorted((QUEUE_DIR / "generated_refresh_results").glob("*.result.json"))
        if (QUEUE_DIR / "generated_refresh_results").exists()
        else []
    )
    generated_jobs: list[Path] = []
    user_jobs: list[Path] = []
    for path in jobs:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            data = {}
        if isinstance(data, dict) and data.get("kind") == "generated-refresh":
            generated_jobs.append(path)
        else:
            user_jobs.append(path)
    generated_processing: list[Path] = []
    user_processing: list[Path] = []
    for path in processing:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            data = {}
        if isinstance(data, dict) and data.get("kind") == "generated-refresh":
            generated_processing.append(path)
        else:
            user_processing.append(path)
    print(f"worker running: {lock_is_held(WORKER_LOCK)}")
    print(f"queued jobs: {len(user_jobs)}")
    print(f"processing jobs: {len(user_processing)}")
    print(f"queued generated refresh jobs: {len(generated_jobs)}")
    print(f"processing generated refresh jobs: {len(generated_processing)}")
    print(f"unclaimed results: {len(results)}")
    print(f"generated refresh results: {len(generated_results)}")
    for path in user_jobs[:25]:
        print(f"queued {path.name}")
    for path in user_processing[:25]:
        print(f"processing {path.name}")
    for path in generated_jobs[:25]:
        print(f"queued generated-refresh {path.name}")
    for path in generated_processing[:25]:
        print(f"processing generated-refresh {path.name}")
    return 0


def wait_for_result(result_path: Path, queue_timeout: float) -> dict:
    deadline = None if queue_timeout < 0 else time.monotonic() + queue_timeout
    while True:
        if result_path.exists():
            result = json.loads(result_path.read_text(encoding="utf-8"))
            result_path.unlink(missing_ok=True)
            return result
        if not lock_is_held(WORKER_LOCK):
            start_worker_if_needed()
        if deadline is not None and time.monotonic() >= deadline:
            raise TimeoutError(f"timed out waiting for queued validator result: {result_path}")
        time.sleep(QUEUE_POLL_SECONDS)


def split_frontend_args(argv: list[str]) -> tuple[argparse.Namespace, list[str]]:
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("--queue-timeout", type=float, default=-1.0)
    parser.add_argument("--queue-status", action="store_true")
    parser.add_argument("--start-worker", action="store_true")
    parser.add_argument("--background-direct", action="store_true")
    return parser.parse_known_args(argv)


def main(argv: list[str] | None = None) -> int:
    if argv is None:
        argv = sys.argv[1:]

    frontend_args, validator_args = split_frontend_args(argv)
    if frontend_args.queue_status:
        command_context = allocate_command_context()
        print_command_preamble(command_context)
        return queue_status()
    if frontend_args.start_worker:
        command_context = allocate_command_context()
        print_command_preamble(command_context)
        start_worker_if_needed()
        return queue_status()
    if frontend_args.background_direct:
        command_context = allocate_command_context()
        print_command_preamble(command_context)
        validator_args = normalize_validator_args(validator_args)
        return subprocess.call(
            [sys.executable, str(BACKGROUND), *command_context_args(command_context), *validator_args]
        )

    validator_args = normalize_validator_args(validator_args)
    job_name, result_path, command_context = enqueue_job(validator_args)
    print_command_preamble(command_context)
    start_worker_if_needed()
    try:
        result = wait_for_result(result_path, frontend_args.queue_timeout)
    except TimeoutError as exc:
        print(
            f"validator job remains queued or running: {job_name} "
            f"(command_id: {command_context['command_id_display']}, "
            f"command_timestamp: {command_context['command_timestamp']})",
            file=sys.stderr,
        )
        print(exc, file=sys.stderr)
        return 1

    stdout = result.get("stdout", "")
    stderr = result.get("stderr", "")
    if stdout:
        print(stdout, end="")
    if stderr:
        print(stderr, end="", file=sys.stderr)
    return int(result.get("exit_code", 1))


if __name__ == "__main__":
    raise SystemExit(main())
