*** UID:0000G7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Win32Error

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_Win32Error.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x00619358`, vtable `0x0061935c`
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`Win32Error` captures a Win32 last-error code and formats it into a readable message for display or exception reporting.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a60d0` | `Win32Error` | Calls `GetLastError` and stores the code after `LObject` initialization. |
| `0x004a6100` | `FormatErrorMessage` | Uses `FormatMessageW`; falls back to raw code formatting. |

## Ownership Notes

This is a generic platform error wrapper. Keep implementation in `util/Error.cpp`; callers from startup, file, network, or rendering code should only construct it.

2026-05-26 IDA MCP recheck reports `Win32Error::Win32Error` at `0x004a60d0` as a real `0x25`-byte function, `FormatErrorMessage` at `0x004a6100` as a real `0xa3`-byte function, and the vtable write/xref to `0x0061935c` at `0x004a60df`.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the constructor/format method documentation, shared `Error` module placement, generic ownership note, and IDA-confirmed function/vtable evidence; completion is moderate because the page is focused and does not yet fully document formatting internals.
