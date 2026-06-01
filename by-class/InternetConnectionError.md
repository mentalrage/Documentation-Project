*** UID:00006P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InternetConnectionError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_InternetConnectionError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x00619418`, vtable `0x0061941c`
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`InternetConnectionError` captures extended WinINet response information and stores the text for display/copy-out.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6690` | `InternetConnectionError` | Calls `InternetGetLastResponseInfoA`, converts text to wide, and stores it. |
| `0x004a6780` | `CopyErrorMessage` | Copies the stored wide message. |

## Ownership Notes

This is a specialization of the internet error family. Keep it in the shared error module and let HTTP/download code reference it.

2026-05-26 IDA MCP recheck reports `InternetConnectionError::InternetConnectionError` at `0x004a6690` as a real `0xe2`-byte function, `CopyErrorMessage` at `0x004a6780` as a real `0x1e`-byte function, and the vtable write/xref to `0x0061941c` at `0x004a66da`.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00006Q][InternetError](by-class/InternetError.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: WinINet response-error responsibility, constructor/copy method behavior, vtable anchor, shared error-module placement, and IDA recheck evidence are documented with strong confidence; remaining work is final C++ body reconstruction and broader hierarchy integration. Evidence: `ErrorWrappers`, `ErrorHierarchyVtables`, `InternetError`, function starts `0x004a6690`/`0x004a6780`, and vtable `0x0061941c`.
