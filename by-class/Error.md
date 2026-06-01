*** UID:00004J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Error

## Status

- Confidence: strong for base error role, medium for exact destructor variant ownership.
- Current Wave3 file: `class_Error.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact vtable data: [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks through 2026-05-25.

## Responsibility

`Error` is the base class for exception-like client error objects. It inherits from `LObject` and supplies common destructor/vtable behavior for concrete wrappers.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup helper | Resets to the base `Error` vtable and calls the inherited `LObject` cleanup path; current generated output omits it. |
| `0x004a68a0` | `ScalarDeletingDestructor` | Resets vtable, destroys `LObject`, optionally deletes. |
| `0x004a68e0` | `ScalarDeletingDestructor` | Similar destructor variant. |
| `0x004a69c0` | `ScalarDeletingDestructor` | Destroys an embedded message string before base teardown. |

## Ownership Notes

The duplicated destructor names likely represent different vtable slots or recovered subtype/base variants. Keep them with the shared error hierarchy until vtable layout is fully named.

See [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) for the shared five-slot interface and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) for storage-family notes.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/78`.
  - Summary/evidence: base error role, cleanup helper, destructor variants, module ownership, vtable/layout cross-references, and duplicate destructor caveat are documented; confidence remains limited until the destructor variants are fully assigned to exact vtable/subtype owners.
