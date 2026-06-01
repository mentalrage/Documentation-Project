*** UID:0000A8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PasswordError

## Status

- Confidence: strong for class responsibility, medium for source split with password guard helpers.
- Current Wave3 file: `class_PasswordError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md), with caller helpers in [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- Current ranges: [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md) and [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact vtable data: [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md)
- Evidence basis: `simroot_v2`, recovered global helpers, Wave3 summary, and IDA MCP checks through 2026-05-25.

## Responsibility

`PasswordError` is a concrete `MyError` subclass thrown when protected password text appears in outbound input. It wraps the localized message loaded by the password guard.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x00467160` | `PasswordError` | Calls `MyError` constructor and installs `PasswordError` vtable. |
| `0x00467300` | `ScalarDeletingDestructor` | Destroys `MyError` and optionally deletes `this`. |
| `0x00467400` | `GetErrorDescriptor` | Returns descriptor data at `0x006125bc`; generated output currently mislabels this as returning the `PasswordError` vtable. |
| `0x004a6840` | `CopyErrorMessage` | Copies the stored wide message. |

## Ownership Notes

The class belongs to the error hierarchy, but `SetProtectedPasswordToken` and `ValidateChatInputOrThrowPasswordError` should remain in [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) until final source-layout review.

IDA resolves `PasswordError::vftable` to `0x006125a8`; the constructor writes that table at `0x00467172`. The fifth virtual slot points to `0x00467400`, whose body returns `0x006125bc` descriptor/string data. Do not use the generated `reinterpret_cast<wchar_t*>(&PasswordError_vtable)` body as source-layout or type evidence.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- [UID:00008V][MyError](by-class/MyError.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite clear class responsibility, method list, vtable/descriptor caveat, ownership notes, and cross-references.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: constructor, scalar deleting destructor, descriptor virtual, message-copy wrapper, vtable address, descriptor-data caveat, and split between error hierarchy and password guard helpers are documented; confidence stays medium-high because final source split with guard helpers remains unresolved.

- 2026-05-31:
  - Before: the page referenced the vtable address but did not link an exact by-memory vtable-data child.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and exact vtable child [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md).
  - Summary/evidence: IDA MCP verified the `PasswordError` vtable dwords, constructor store at `0x00467172`, descriptor helper `0x00467400`, and descriptor string boundary at `0x006125bc`; final `PasswordGuard` source split still limits confidence.
