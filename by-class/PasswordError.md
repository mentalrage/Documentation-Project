*** UID:0000A8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:240 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PasswordError

## Status

- Confidence: strong for class responsibility, vtable slots, descriptor helper, and construction path; medium-high for final source split with password guard helpers.
- Likely source module: [UID:0000J5][Error](by-file/Error.md), with caller helpers in [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- Current ranges: [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md), [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md), [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md), [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md), and [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact vtable data: [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md)
- Evidence basis: live IDA MCP lookup, xref, decompile, and data reads on 2026-06-04, plus the exact vtable-data child.

## Responsibility

`PasswordError` is a concrete `MyError` subclass thrown when protected password text appears in outbound input. It wraps the localized message loaded by the password guard.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md) | `PasswordError` | Calls `MyError` constructor and installs `PasswordError` vtable. |
| [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | Destroys `MyError` and optionally deletes `this`. |
| [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md) | `GetErrorDescriptor` | Returns descriptor data at `0x006125bc`, the adjacent `Password Warning` string/data after the vtable. |
| `0x004a6840` | `CopyErrorMessage` | Copies the stored wide message. |

## Ownership Notes

The class belongs to the error hierarchy, but `SetProtectedPasswordToken` and `ValidateChatInputOrThrowPasswordError` should remain in [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) until final source-layout review.

IDA resolves `PasswordError::vftable` to `0x006125a8`; the constructor writes that table at `0x00467172`. The fifth virtual slot points to `0x00467400`, whose body returns `0x006125bc` descriptor/string data. The scalar deleting destructor and descriptor helper have no direct code callers because they are reached through the vtable.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- [UID:00008V][MyError](by-class/MyError.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md)
- [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md)
- [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md)
- [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md)
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

- 2026-06-04 live IDA refresh:
  - Before: the page still referenced older non-IDA evidence and had not recorded the exact live construction/destructor/descriptor call shape.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP confirmed constructor `0x00467160-0x00467181`, scalar deleting destructor `0x00467300-0x00467338`, descriptor helper `0x00467400-0x00467406`, constructor caller `0x00465abe` from the password guard throw path, vtable store `0x00467172 -> 0x006125a8`, descriptor return `0x00467400 -> 0x006125bc`, and the `Password Warning` descriptor data. The class remains below 95/95 because the final original source boundary between `Error.cpp` declarations and `PasswordGuard.cpp` throw-site helpers is still not proven.

- 2026-06-05 exact method split:
  - Before: the class page listed the constructor/destructor/descriptor ranges but linked only the mixed aggregate and vtable-data page.
  - Changed to: exact method pages [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md), [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md), and [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md) now hold the function-level evidence; score raised to `86/90`.
  - Summary/evidence: IDA MCP reverified the constructor caller from the password guard throw path, the vtable-only destructor and descriptor xrefs, the vtable store, and the `Password Warning` descriptor return.

- 2026-06-06 autogen parent attachment:
  - Before: the class was reconstructable but remained unassigned in generated class coverage.
  - Changed to: attached to [UID:0000J5][Error](by-file/Error.md) at position `240`, after the shared `MyError` hierarchy entry.
  - Summary/evidence: live IDA MCP rechecked `0x00467160`, `0x00467300`, and `0x00467400` as exact `PasswordError` methods; `xrefs_to` confirms the constructor writes `PasswordError::vftable` at `0x006125a8`, the destructor and descriptor helper are vtable-reached, and the constructor is called from the password guard throw path. Existing file/class docs already separate the `PasswordGuard` throw helpers from the `PasswordError` class implementation in [UID:0000J5][Error](by-file/Error.md).
