# int_convert.py README

`int_convert.py` is a standalone clone of the `ida-pro-mcp` `int_convert` helper.
Use it when an agent must convert number bases or inspect the byte/ASCII form of an
integer. Do not manually convert bases in prompts; send the number text to this
script and parse the JSON response.

Source behavior mirrored from:
https://github.com/mrexodia/ida-pro-mcp/blob/main/src/ida_pro_mcp/ida_mcp/api_core.py

## Command Reference

```powershell
python Z:\int_convert.py [input...] [--text TEXT] [--size BYTES] [--pretty] [--single]
```

Options:

- `input`: Optional positional number, JSON object, JSON array, or comma-separated numbers. If omitted, the script reads stdin.
- `--text TEXT`: Shell-safe way to send one number. Recommended for Windows and agents.
- `--size BYTES`: Output byte width for `--text`, using signed little-endian bytes.
- `--pretty`: Pretty-print JSON for humans.
- `--single`: If there is exactly one result, return one JSON object instead of a one-item JSON list.

Important behavior:

- Number text is parsed with Python `int(text, 0)`.
- Accepted number text includes decimal (`65`), hex (`0x41`), binary (`0b1000001`), octal (`0o101`), and signed values (`-1`).
- Plain string inputs use the MCP default size of `64` bytes.
- Dict/object inputs without `size`, and `--text` without `--size`, auto-size to the smallest whole-byte width.
- Bytes are returned as signed little-endian bytes.
- `ascii` is a printable ASCII string after stripping trailing `00` bytes, or `null` if any remaining byte is non-printable.
- Conversion failures are returned in JSON with `result: null` and an `error` string. Agents should check the `error` field.
- The process exits successfully even when an individual conversion fails, because conversion errors are data in the JSON response.

## JSON Output Shape

Successful conversion:

```json
{
  "input": "0x4142",
  "result": {
    "decimal": "16706",
    "hexadecimal": "0x4142",
    "bytes": "42 41",
    "ascii": "BA",
    "binary": "0b100000101000010"
  },
  "error": null
}
```

Failed conversion:

```json
{
  "input": "256",
  "result": null,
  "error": "Number 256 is too big for 1 bytes"
}
```

## Recommended Agent Calls

Use `--text` for one value. Include `--size` when the byte width matters:

```powershell
python Z:\int_convert.py --text 0x4142 --size 2 --single
```

Use stdin JSON for batches:

```powershell
'["65", {"text":"0x4142", "size":2}, {"text":"256", "size":1}]' | python Z:\int_convert.py
```

Use `--pretty` only when a person will read the output. Agents can omit it and parse the same JSON shape in compact form.

## Examples With Output

### 1. Hex To 2 Bytes

Command:

```powershell
python Z:\int_convert.py --text 0x4142 --size 2 --single --pretty
```

Output:

```json
{
  "input": "0x4142",
  "result": {
    "decimal": "16706",
    "hexadecimal": "0x4142",
    "bytes": "42 41",
    "ascii": "BA",
    "binary": "0b100000101000010"
  },
  "error": null
}
```

### 2. Signed Negative Byte

Command:

```powershell
python Z:\int_convert.py --text -1 --size 1 --single --pretty
```

Output:

```json
{
  "input": "-1",
  "result": {
    "decimal": "-1",
    "hexadecimal": "-0x1",
    "bytes": "ff",
    "ascii": null,
    "binary": "-0b1"
  },
  "error": null
}
```

### 3. Auto-Sized Decimal

Command:

```powershell
python Z:\int_convert.py --text 65 --single --pretty
```

Output:

```json
{
  "input": "65",
  "result": {
    "decimal": "65",
    "hexadecimal": "0x41",
    "bytes": "41",
    "ascii": "A",
    "binary": "0b1000001"
  },
  "error": null
}
```

### 4. Auto-Sized Hex

Command:

```powershell
python Z:\int_convert.py --text 0x414243 --single --pretty
```

Output:

```json
{
  "input": "0x414243",
  "result": {
    "decimal": "4276803",
    "hexadecimal": "0x414243",
    "bytes": "43 42 41",
    "ascii": "CBA",
    "binary": "0b10000010100001001000011"
  },
  "error": null
}
```

### 5. Positional Number Input

Plain positional strings mirror the MCP string-parser behavior and default to `64` bytes.

Command:

```powershell
python Z:\int_convert.py 0x414243 --single --pretty
```

Output:

```json
{
  "input": "0x414243",
  "result": {
    "decimal": "4276803",
    "hexadecimal": "0x414243",
    "bytes": "43 42 41 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00",
    "ascii": "CBA",
    "binary": "0b10000010100001001000011"
  },
  "error": null
}
```

### 6. Overflow Error

Command:

```powershell
python Z:\int_convert.py --text 256 --size 1 --single --pretty
```

Output:

```json
{
  "input": "256",
  "result": null,
  "error": "Number 256 is too big for 1 bytes"
}
```

### 7. Invalid Number Error

Command:

```powershell
python Z:\int_convert.py --text nope --single --pretty
```

Output:

```json
{
  "input": "nope",
  "result": null,
  "error": "Invalid number: nope"
}
```

### 8. Batch JSON Through stdin

String entries in a batch default to `64` bytes. Object entries can specify `size`.

Command:

```powershell
'["65", {"text":"0x4142", "size":2}, {"text":"256", "size":1}]' | python Z:\int_convert.py --pretty
```

Output:

```json
[
  {
    "input": "65",
    "result": {
      "decimal": "65",
      "hexadecimal": "0x41",
      "bytes": "41 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00",
      "ascii": "A",
      "binary": "0b1000001"
    },
    "error": null
  },
  {
    "input": "0x4142",
    "result": {
      "decimal": "16706",
      "hexadecimal": "0x4142",
      "bytes": "42 41",
      "ascii": "BA",
      "binary": "0b100000101000010"
    },
    "error": null
  },
  {
    "input": "256",
    "result": null,
    "error": "Number 256 is too big for 1 bytes"
  }
]
```

### 9. Batch Wrapper Object Through stdin

Command:

```powershell
'{"inputs":["0x41", {"text":"0x4142", "size":2}]}' | python Z:\int_convert.py --pretty
```

Output:

```json
[
  {
    "input": "0x41",
    "result": {
      "decimal": "65",
      "hexadecimal": "0x41",
      "bytes": "41 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00",
      "ascii": "A",
      "binary": "0b1000001"
    },
    "error": null
  },
  {
    "input": "0x4142",
    "result": {
      "decimal": "16706",
      "hexadecimal": "0x4142",
      "bytes": "42 41",
      "ascii": "BA",
      "binary": "0b100000101000010"
    },
    "error": null
  }
]
```

## Agent Parsing Checklist

1. Send number text exactly as observed, including prefixes like `0x` or `0b`.
2. Provide `size` when byte width matters for signed interpretation or overflow checks.
3. Parse stdout as JSON.
4. Treat a non-null `error` as a failed conversion for that item.
5. Read converted values from `result.decimal`, `result.hexadecimal`, `result.bytes`, `result.ascii`, and `result.binary`.
6. Remember `bytes` are little-endian; `0x4142` with `size: 2` returns `42 41`.
