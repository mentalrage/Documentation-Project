#!/usr/bin/env python3
"""Standalone clone of ida-pro-mcp's int_convert helper.

Reads one conversion request or a batch of requests and emits JSON.

Accepted input shapes:
  "0x414243"
  {"text": "0x414243", "size": 8}
  ["0x41", "65", {"text": "-1", "size": 1}]
  {"inputs": ["0x41", {"text": "1234"}]}

Usage examples:
  python int_convert.py 0x414243
  python int_convert.py --text -1 --size 1 --pretty
  python int_convert.py '{"text":"-1","size":1}'
  echo '["0x41","65"]' | python int_convert.py --pretty
"""

from __future__ import annotations

import argparse
import json
import sys
from typing import Any


def _split_csv(text: str) -> list[str]:
    return [part.strip() for part in text.split(",") if part.strip()]


def _normalize_inputs(value: Any) -> list[dict[str, Any]]:
    """Normalize agent/user input into ida-pro-mcp-style request dicts.

    This intentionally mirrors the important behavior from ida-pro-mcp:
    plain string inputs are converted to {"text": string, "size": 64}.
    Dict inputs are used as-is, so an omitted size triggers auto-sizing.
    """
    if isinstance(value, dict) and "inputs" in value:
        return _normalize_inputs(value["inputs"])

    if isinstance(value, dict):
        return [value]

    if isinstance(value, list):
        if not value:
            return []
        normalized: list[dict[str, Any]] = []
        for item in value:
            if isinstance(item, dict):
                normalized.append(item)
            elif isinstance(item, str):
                text = item.strip()
                if text:
                    normalized.append({"text": text, "size": 64})
            else:
                normalized.append({"text": str(item), "size": 64})
        return normalized

    if isinstance(value, str):
        try:
            parsed = json.loads(value)
        except json.JSONDecodeError:
            return [{"text": part, "size": 64} for part in _split_csv(value)]
        return _normalize_inputs(parsed)

    return [{"text": str(value), "size": 64}]


def _auto_size_bytes(value: int) -> int:
    size = 0
    n = abs(value)
    while n:
        size += 1
        n >>= 1
    size += 7
    size //= 8
    return size


def convert_one(item: dict[str, Any]) -> dict[str, Any]:
    text = str(item.get("text", ""))
    size = item.get("size")

    try:
        value = int(text, 0)
    except (TypeError, ValueError):
        return {"input": text, "result": None, "error": f"Invalid number: {text}"}

    if not size:
        size = _auto_size_bytes(value)

    try:
        size = int(size)
    except (TypeError, ValueError):
        return {"input": text, "result": None, "error": f"Invalid size: {size}"}

    try:
        bytes_data = value.to_bytes(size, "little", signed=True)
    except OverflowError:
        return {
            "input": text,
            "result": None,
            "error": f"Number {text} is too big for {size} bytes",
        }
    except ValueError as exc:
        return {"input": text, "result": None, "error": str(exc)}

    ascii_str: str | None = ""
    for byte in bytes_data.rstrip(b"\x00"):
        if 32 <= byte <= 126:
            ascii_str += chr(byte)
        else:
            ascii_str = None
            break

    return {
        "input": text,
        "result": {
            "decimal": str(value),
            "hexadecimal": hex(value),
            "bytes": bytes_data.hex(" "),
            "ascii": ascii_str,
            "binary": bin(value),
        },
        "error": None,
    }


def convert(inputs: Any) -> list[dict[str, Any]]:
    return [convert_one(item) for item in _normalize_inputs(inputs)]


def _read_request(args: argparse.Namespace) -> Any:
    if args.text is not None:
        request: dict[str, Any] = {"text": args.text}
        if args.size is not None:
            request["size"] = args.size
        return request

    if args.input:
        raw = " ".join(args.input).strip()
        try:
            return json.loads(raw)
        except json.JSONDecodeError:
            return raw

    raw = sys.stdin.read().strip()
    if not raw:
        return []
    try:
        return json.loads(raw)
    except json.JSONDecodeError:
        return raw


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="Convert numbers like ida-pro-mcp's int_convert tool."
    )
    parser.add_argument(
        "input",
        nargs="*",
        help="Number, JSON request, or JSON batch. If omitted, reads stdin.",
    )
    parser.add_argument(
        "--text",
        help="Number text to convert. Use with --size for shell-safe agent calls.",
    )
    parser.add_argument(
        "--size",
        type=int,
        help="Signed little-endian output width in bytes for --text.",
    )
    parser.add_argument(
        "--pretty",
        action="store_true",
        help="Pretty-print JSON output.",
    )
    parser.add_argument(
        "--single",
        action="store_true",
        help="Return a single object instead of a list when there is one result.",
    )
    args = parser.parse_args(argv)

    results = convert(_read_request(args))
    output: Any = results[0] if args.single and len(results) == 1 else results
    print(json.dumps(output, indent=2 if args.pretty else None))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
