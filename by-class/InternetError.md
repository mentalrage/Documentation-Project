*** UID:00006Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InternetError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_InternetError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x00619400`, vtable `0x00619404`
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`InternetError` is a base WinINet-related error object. It loads WinINet/system error text and stores it in an internal string for later copy-out.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6550` | `InternetError` | Initializes base object, loads `WININET.DLL`, formats last error, and stores text. |
| `0x004a6670` | `GetErrorText` | Copies stored error text to a caller buffer. |

## Ownership Notes

Keep this wrapper in `util/Error.cpp`. HTTP/download modules should construct it but not absorb the generic WinINet error class.

2026-05-26 IDA MCP recheck reports `InternetError::InternetError` at `0x004a6550` as a real `0x11a`-byte function, `GetErrorText` at `0x004a6670` as a real `0x1e`-byte function, and the vtable write/xref to `0x00619404` at `0x004a65a2`.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00006P][InternetConnectionError](by-class/InternetConnectionError.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: WinINet/system-error wrapper responsibility, constructor/text-copy methods, vtable anchor, module placement, and IDA recheck evidence are documented with strong confidence; remaining work is final C++ body reconstruction and full error-hierarchy integration. Evidence: `ErrorWrappers`, `ErrorHierarchyVtables`, `InternetConnectionError`, function starts `0x004a6550`/`0x004a6670`, and vtable `0x00619404`.
