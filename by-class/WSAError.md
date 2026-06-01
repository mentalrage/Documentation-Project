*** UID:0000GB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WSAError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_WSAError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x006193e8`, vtable `0x006193ec`
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`WSAError` captures `WSAGetLastError` and formats Winsock failures for display or exception reporting.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a64a0` | `WSAError` | Initializes base object and stores the Winsock error code. |
| `0x004a64d0` | `FormatErrorMessage` | Formats `WSAError` using `FormatMessageW` or raw code fallback. |

## Ownership Notes

The constructor is called from socket/transport code, but implementation belongs with [UID:0000J5][Error](by-file/Error.md). Transport ownership remains with [UID:0000DD][Socket](by-class/Socket.md).

2026-05-26 IDA MCP recheck reports `WSAError::WSAError` at `0x004a64a0` as a real `0x25`-byte function, `FormatErrorMessage` at `0x004a64d0` as a real `0x79`-byte function, and the vtable write/xref to `0x006193ec` at `0x004a64af`.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the focused constructor/format-method documentation, shared `Error` module placement, socket caller ownership note, and IDA-confirmed method/vtable evidence; completion is moderate because the page is intentionally small and does not yet spell out the full formatting internals.
