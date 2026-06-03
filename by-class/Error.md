*** UID:00004J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Error

## Status

- Confidence: strong for base error role, vtable membership, and destructor-family ownership; medium for final virtual method names.
- Current Wave3 file: `class_Error.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Destructor/name helper range: [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- Exact vtable data: [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks through 2026-06-03.

## Responsibility

`Error` is the base class for exception-like client error objects. It inherits from `LObject` and supplies common destructor/vtable behavior for concrete wrappers.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup helper | Resets to the base `Error` vtable and calls the inherited `LObject` cleanup path; current generated output omits it. |
| [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md) | destructor/name helper cluster | Exact destructor-family map and common name virtual. |
| `0x004a68a0-0x004a68de` | status-code wrapper scalar deleting destructor | Used by `Win32Error`, `DIError`, `DDError`, `DSError`, and `WSAError`; not the base `Error` vtable slot. |
| `0x004a68e0-0x004a691e` | `Error` scalar deleting destructor | The base `Error` destructor slot. Resets the base vtable, calls `LObject` cleanup, and conditionally deletes storage. |
| `0x004a69c0-0x004a6a08` | `InternetError`/`InternetConnectionError` scalar deleting destructor | Destroys the `SimpleUString` member at `+0x04` before base teardown. |
| `0x004a6a70-0x004a6a76` | common error name helper | Returns the shared `Error` literal used by the main hierarchy's descriptor/name slot. |

## Ownership Notes

The apparent duplicate destructor names are now separated by vtable ownership. The base [UID:00004J][Error](by-class/Error.md) table uses `0x004a68e0`; `0x004a68a0` is a shared status-code wrapper destructor; `0x004a6920` and `0x004a6970` are inline-message wrapper destructors; `0x004a69c0` is the `SimpleUString` storage-family destructor; and `0x004a6a10` is the owned heap-message destructor used by `MyError`.

See [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) for the shared five-slot interface and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) for storage-family notes.

## 2026-06-03 IDA MCP Recheck

- IDA reports `sub_4A68E0` as `0x004a68e0-0x004a691e`, and the only data xref to that function is the base `Error` vtable at `0x00619344`.
- IDA reports `sub_4A68A0` as `0x004a68a0-0x004a68de`, with data xrefs from the `Win32Error`, `DIError`, `DDError`, `DSError`, and `WSAError` destructor slots.
- The base vtable at `0x00619344` has slot order: `0x004a68e0`, `0x004f4b10`, `nullsub_18`, `__purecall`, and `0x004a6a70`.
- All destructor variants restore or retain the base `Error` vtable before inherited `LObject` cleanup; storage-family destructors add only the member cleanup required by their layout family.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/78`.
  - Summary/evidence: base error role, cleanup helper, destructor variants, module ownership, vtable/layout cross-references, and duplicate destructor caveat are documented; confidence remains limited until the destructor variants are fully assigned to exact vtable/subtype owners.
- 2026-06-03 destructor-family ownership recheck:
  - Before: destructor variants were documented as duplicate scalar deleting destructors with ownership still caveated, and the class was reconstructable but unparented.
  - Changed to: score is `76/82`, attached to [UID:0000J5][Error](by-file/Error.md), and the destructor/name-helper tail is split to [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md).
  - Summary/evidence: live IDA MCP confirmed the exact function bounds, vtable slot map, and destructor xrefs that prove `0x004a68e0` is the base `Error` destructor while sibling destructor helpers belong to storage-family subclasses.
  - C++ remains blank because final source-level virtual names and surrounding constructor-shaped raw records are not at the 95% reconstruction threshold.
