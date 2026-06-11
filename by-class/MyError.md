*** UID:00008V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Source module: [UID:0000J5][Error](by-file/Error.md)
- Exact constructor: [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md)
- Destructor/name helper tail: [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- Aggregate range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Parent attachment: attached to [UID:0000J5][Error](by-file/Error.md) because the file page is `87/84` and this class page is now `82/86`.
- Evidence basis: existing IDA-backed by-memory constructor/destructor pages, error vtable/layout docs, and the shared `Error.cpp` file page.

## Responsibility

`MyError` is an application-specific error class that owns a dynamically copied wide error message. `PasswordError` derives from it.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) | `MyError` | Allocates and copies the supplied wide message into the owned pointer field at `+0x04`. |
| `0x004a6860` | `~MyError` | Frees owned message and tears down base error state; still aggregate-only inside [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md). |
| [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md) | scalar deleting destructor family | The `0x004a6a10` storage-family destructor frees the `+0x04` wide-string pointer and optionally deletes `this`. |

## Ownership Notes

This is shared application error infrastructure. Keep it with [UID:0000J5][Error](by-file/Error.md), even when callers originate from password validation, map/dialog code, or transport code.

The object layout is the heap-message storage family: vtable at `+0x00`, owned `wchar_t*` at `+0x04`. [UID:0000A8][PasswordError](by-class/PasswordError.md) reuses the same message-copy slot and installs a separate vtable.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata, with C++ blank until allocator naming and the `PasswordError` subclass split are final-source quality.

## Score Rationale

- Completion raised from `74` to `82` because the page now links the exact constructor and destructor-family pages, records the parent gate, names the heap-message layout family, and separates the `Error.cpp` class implementation from password-guard throw-site ownership.
- Confidence remains `86` because the constructor/destructor/layout evidence is strong, but final allocator naming, the aggregate-only `0x004a6860` destructor body, and the exact original header split with `PasswordError` remain open.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md)
- [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: the application error class has clear responsibility, module placement, constructor/destructor/deleting-destructor addresses, layout family, and `PasswordError` relationship documented, but the page is intentionally concise and does not expand every caller path. Evidence: linked `ErrorWrappers` memory range, error hierarchy vtable/layout docs, shared `Error` module, and owned wide-message slot.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: constructor/destructor/layout evidence supports shared `Error.cpp` ownership; password/fatal helpers remain separate ownership caveats.
- 2026-06-06 A004 parent-gate cleanup:
  - Before: the class page was `74/86` while child constructor pages were already attached to it.
  - After: `COMPLETION:82`, exact constructor/destructor-family links, parent-gate wording, by-* evidence basis, and score rationale.
  - Summary/evidence: [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md), [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md), [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md), and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) support the higher completion score. Final C++ remains blank below the 95/95 gate.
