*** UID:0000E7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StringIter

## Summary

`StringIter` is an `LObject`-derived iterator over wide-character string data. It stores a source data pointer, length, and current position, and returns the next character or `0` when exhausted.

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp` or `util/StringIter.cpp`
- Confidence: medium

## Methods

| Range | Role |
| --- | --- |
| `0x00584d80-0x00584db1` | constructor from data pointer and length, starts at position 0. |
| `0x00584dc0` | projected constructor with explicit start position; IDA currently reports this is not a function. |
| `0x00584df0-0x00584dfb` | destructor body. |
| `0x00584e40-0x00584e59` | `GetNextChar`. |
| `0x00584e60-0x00584e9e` | scalar deleting destructor. |

## Evidence

- Generated source and metadata agree on fields: `m_data`, `m_length`, and `m_position`.
- `GetNextChar` has caller fan-in from text parsing/render helper functions around `0x004ba8b0`, `0x004ba9a0`, `0x004bab70`, and `0x005948a0`.
- The class installs its own vtable and uses `LObject` base construction/destruction.

## Generated Data Caveats

`0x00584dc0` is emitted as an active constructor by `class_StringIter.cpp`, but IDA MCP reports it is not a function. Treat it as a projected/raw constructor slice until a boundary pass confirms the start.

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Memory: [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- Related: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `70`.
- Evidence: the page documents iterator role, likely utility placement, fields, method ranges, caller fan-in, and the generated-data caveat for the projected constructor; completion/confidence stay limited because `0x00584dc0` is not an IDA function and final file split remains only medium confidence.
