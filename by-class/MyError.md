*** UID:00008V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:220 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MyError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_MyError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks through 2026-05-25.

## Responsibility

`MyError` is an application-specific error class that owns a dynamically copied wide error message. `PasswordError` derives from it.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a67a0` | `MyError` | Allocates and copies the supplied wide message. |
| `0x004a6860` | `~MyError` | Frees owned message and tears down base error state. |
| `0x004a6a10` | `ScalarDeletingDestructor` | Destructor plus optional `operator delete`. |

## Ownership Notes

This is shared application error infrastructure. Keep it with [UID:0000J5][Error](by-file/Error.md), even when callers originate from password validation, map/dialog code, or transport code.

The object layout is the heap-message storage family: vtable at `+0x00`, owned `wchar_t*` at `+0x04`. [UID:0000A8][PasswordError](by-class/PasswordError.md) reuses the same message-copy slot and installs a separate vtable.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata, with C++ blank until allocator naming and the `PasswordError` subclass split are final-source quality.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: the application error class has clear responsibility, module placement, constructor/destructor/deleting-destructor addresses, layout family, and `PasswordError` relationship documented, but the page is intentionally concise and does not expand every caller path. Evidence: linked `ErrorWrappers` memory range, error hierarchy vtable/layout docs, shared `Error` module, and owned wide-message slot.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: constructor/destructor/layout evidence supports shared `Error.cpp` ownership; password/fatal helpers remain separate ownership caveats.
