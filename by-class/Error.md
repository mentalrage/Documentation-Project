*** UID:00004J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Error

## Status

- Confidence: strong for base error role, vtable membership, and destructor-family ownership; medium for final virtual method names.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Destructor/name helper range: [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- Exact vtable data: [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- Source-facing placement: base class declaration and destructor/name support in `NexusTK/util/Error.cpp` / `Error.h`; concrete storage-wrapper construction remains in the same shared hierarchy.
- Reconstructable: true; C++ remains blank until final virtual names, declaration shape, and raw constructor records reach the final-source gate.

## Responsibility

`Error` is the base class for exception-like client error objects. It inherits from `LObject` and supplies common destructor/vtable behavior for concrete wrappers.

The source-level hierarchy is compact. [UID:0000J5][Error](by-file/Error.md) groups `Error`, status-code wrappers (`Win32Error`, `DDError`, `DIError`, `DSError`, `WSAError`), inline-message wrappers (`ErrorMessage`, `FileError`), WinINet wrappers (`InternetError`, `InternetConnectionError`), and owned-message `MyError` into one utility module rather than one source file per generated class.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup helper | Resets to the base `Error` vtable and calls the inherited `LObject` cleanup path; current generated output omits it. |
| [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md) | destructor/name helper cluster | Exact destructor-family map and common name virtual. |
| `0x004a68a0-0x004a68de` | status-code wrapper scalar deleting destructor | Used by `Win32Error`, `DIError`, `DDError`, `DSError`, and `WSAError`; not the base `Error` vtable slot. |
| `0x004a68e0-0x004a691e` | `Error` scalar deleting destructor | The base `Error` destructor slot. Resets the base vtable, calls `LObject` cleanup, and conditionally deletes storage. |
| `0x004a69c0-0x004a6a08` | `InternetError`/`InternetConnectionError` scalar deleting destructor | Destroys the `SimpleUString` member at `+0x04` before base teardown. |
| `0x004a6a70-0x004a6a76` | common error name helper | Returns the shared `Error` literal used by the main hierarchy's descriptor/name slot. |

## Vtable And Storage Families

The exact vtable-data page records the shared five-slot interface and the class-specific destructor/descriptor slots:

| Class family | Vtable base | Destructor slot | Descriptor/name slot | Storage model |
| --- | --- | --- | --- | --- |
| `Error` | `0x00619344` | `0x004a68e0` | `0x004a6a70` | Base object with no extra stored message/status field. |
| Status-code wrappers | `0x0061935c`, `0x00619374`, `0x0061938c`, `0x006193a4`, `0x006193ec` | `0x004a68a0` | class-specific formatter or `0x004a6a70` | Stores last-error/HRESULT/WSA status at `+0x04`. |
| Inline-message wrappers | `0x006193bc`, `0x006193d4` | `0x004a6920` or `0x004a6970` | [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) / [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) | Inline or copied message buffer. |
| WinINet wrappers | `0x00619404`, `0x0061941c` | `0x004a69c0` | `0x004a6670` or `0x004a6780` | Owns a `SimpleUString` member at `+0x04`. |
| `MyError` | `0x00619434` | `0x004a6a10` | `0x004a6840` | Owns heap-backed message text. |

The base `Error` vtable at `0x00619344` is the only direct data xref to `0x004a68e0`, which is why the base destructor is now separated from the status-code wrapper destructor at `0x004a68a0`.

## Ownership Notes

The apparent duplicate destructor names are now separated by vtable ownership. The base [UID:00004J][Error](by-class/Error.md) table uses `0x004a68e0`; `0x004a68a0` is a shared status-code wrapper destructor; `0x004a6920` and `0x004a6970` are inline-message wrapper destructors; `0x004a69c0` is the `SimpleUString` storage-family destructor; and `0x004a6a10` is the owned heap-message destructor used by `MyError`.

See [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) for the shared five-slot interface and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) for storage-family notes.

## Source Boundary Notes

- `PasswordError` declaration and virtuals are part of the error hierarchy, but password-token filtering remains with [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) until stronger source-layout evidence moves it.
- `FatalError` remains a split candidate between application startup/error handling and `util/Error.cpp`; do not use it as proof that all password/fatal helpers belong on the base `Error` page.
- DirectDraw, DirectInput, DirectSound, Winsock, and WinINet callers reference this hierarchy through feature-specific failure paths, but the wrapper implementation still belongs in the shared `Error` utility module.

## 2026-06-03 IDA MCP Recheck

- IDA reports `sub_4A68E0` as `0x004a68e0-0x004a691e`, and the only data xref to that function is the base `Error` vtable at `0x00619344`.
- IDA reports `sub_4A68A0` as `0x004a68a0-0x004a68de`, with data xrefs from the `Win32Error`, `DIError`, `DDError`, `DSError`, and `WSAError` destructor slots.
- The base vtable at `0x00619344` has slot order: `0x004a68e0`, `0x004f4b10`, `nullsub_18`, `__purecall`, and `0x004a6a70`.
- All destructor variants restore or retain the base `Error` vtable before inherited `LObject` cleanup; storage-family destructors add only the member cleanup required by their layout family.

## Score Rationale

- Completion is `82` because the class now links the source parent, aggregate executable range, exact destructor/name-helper child, exact vtable data, storage-family slot map, module boundary notes, and final-C++ gate.
- Confidence is `86` because IDA-backed docs agree on the base destructor slot, hierarchy vtable layout, source owner, and subclass storage families; it remains below final-source quality because exact virtual names, declaration spelling, and several constructor-shaped raw records are still unresolved.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00004K][ErrorMessage](by-class/ErrorMessage.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)
- [UID:00004X][FileError](by-class/FileError.md)
- [UID:0000GB][WSAError](by-class/WSAError.md)
- [UID:00006Q][InternetError](by-class/InternetError.md)
- [UID:00008V][MyError](by-class/MyError.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)

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
- 2026-06-07 A001 hierarchy refresh:
  - Before: the page still carried stale generated-file wording and did not summarize the exact vtable/storage-family split now present in child docs.
  - After: raised to `82/86`, added source-facing `Error.cpp`/`Error.h` placement, vtable/storage-family table, source-boundary notes, score rationale, and sibling class cross-references.
  - Summary/evidence: [UID:0000J5][Error](by-file/Error.md), [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md), [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md), [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md), and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) now agree on shared utility ownership, the base `Error` destructor slot, and subclass storage-family destructor assignments.
