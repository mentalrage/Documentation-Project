*** UID:00004X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:140 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FileError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_FileError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact method pages: [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks through 2026-05-25.
- Final C++ gate: keep blank until the base error declaration, inline message buffer type/name, and original constructor signature are settled.

## Responsibility

`FileError` is a concrete error class for file-not-found or file-open failures with a default formatted message template. File/archive code constructs it on stat/open failures, but the implementation belongs to the shared error hierarchy in [UID:0000J5][Error](by-file/Error.md).

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) | `FileError` | Calls shared base setup, installs the `FileError` vtable, formats the default message into the inline wide buffer at byte offset `+0x04`, and clears the trailing flag/status word. |
| [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) | copy helper | IDA-confirmed vtable slot helper that copies the inline wide message buffer. Current active generated output omits it. |
| `0x004a6970` | `ScalarDeletingDestructor` | Base teardown and optional deletion. |

## Ownership Notes

Keep the class in `util/Error.cpp`; file/archive loaders should construct it but should not own the wrapper implementation. IDA xrefs place [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) in the `FileError` vtable message slot at `0x006193e0`, and the constructor writes the `FileError` vtable at `0x004a6445`.

The constructor callers recorded in the exact method page include archive/file paths such as `0x0049c180`, `0x004f53b0`, and `0x005820d0`; these are use-sites, not source ownership evidence. [UID:0000J5][Error](by-file/Error.md) groups the compact `0x004a60d0-0x004a6a76` Win32/DirectX/file/Winsock/WinINet wrapper run as the shared error module.

## Layout And Vtable Notes

| Item | Evidence | Reconstruction Note |
| --- | --- | --- |
| vtable pointer | Constructor writes the `FileError` vtable, with table data documented through [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md). | Keep as a concrete derived error class under `Error.h`/`Error.cpp`. |
| inline message buffer | Constructor formats into `this + 2` in `wchar_t*` terms, i.e. byte offset `+0x04`; copy helper reads the same offset. | Name/type should follow [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) after the hierarchy declaration is audited. |
| message-copy virtual | Vtable data xref at `0x006193e0` targets [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md). | Preserve this method even though the active generated class source omits it. |
| scalar deleting destructor | Listed inside the shared error wrapper cluster at `0x004a6970`. | Treat as compiler/vtable support until the hierarchy-level destructor strategy is reconstructed. |

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. C++ stays blank until the inline buffer declaration and constructor signature are final-source quality.

Child memory pages are already attached under this class: [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md). Do not add source C++ here until the class can include those children through a stable hierarchy declaration.

## Score Rationale

The page is scored `82/88` because exact constructor and copy-message child pages now anchor the class behavior, parent ownership is already established, caller versus owner boundaries are documented, and the inline-message/vtable layout is tied back to type docs. Completion remains below `95` because the final class declaration, original constructor signature, base-error field names, and destructor treatment still need a hierarchy-wide reconstruction pass.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md)
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000JB][File](by-file/File.md)

## Changes

- 2026-06-07: Raised `COMPLETION` from `74` to `82` and `CONFIDENCE` from `86` to `88`.
  - Before: the class identified the shared error-module owner and the copy helper but did not consolidate the exact constructor page, inline-message layout evidence, child-page attachment state, caller/owner boundary, or score rationale.
  - After: the page links the exact constructor and copy-message method pages, documents the `+0x04` inline wide-message storage, vtable slot `0x006193e0`, constructor caller examples, generated-output omission caveat, autogen child state, and final-C++ blockers.
  - Evidence: [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) records base setup, vtable write, message formatting, and file/archive caller xrefs; [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) records the omitted real vtable-slot helper.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: class responsibility, constructor/copy/destructor evidence, vtable slot placement, and file-module ownership are documented; remaining gaps are mostly final source reconstruction and broader error-hierarchy details. Evidence: IDA-confirmed constructor at `0x004a6430`, copy helper `0x004a6480-0x004a6499`, vtable slot note at `0x006193e0`, and `ErrorWrappers` memory page.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: constructor/copy-helper/vtable evidence supports shared `Error.cpp` ownership; archive/file docs remain caller-side evidence only.
