*** UID:00004X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks through 2026-05-25.

## Responsibility

`FileError` is a concrete error class for file-not-found or file-open failures with a default formatted message template.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6430` | `FileError` | Initializes vtable and default file-not-found message. |
| [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) | copy helper | IDA-confirmed vtable slot helper that copies the inline wide message buffer. Current active generated output omits it. |
| `0x004a6970` | `ScalarDeletingDestructor` | Base teardown and optional deletion. |

## Ownership Notes

Keep the class in `util/Error.cpp`; file/archive loaders should construct it but should not own the wrapper implementation. IDA xrefs place [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) in the `FileError` vtable message slot at `0x006193e0`, and the constructor writes the `FileError` vtable at `0x004a6445`.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. C++ stays blank until the inline buffer declaration and constructor signature are final-source quality.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: class responsibility, constructor/copy/destructor evidence, vtable slot placement, and file-module ownership are documented; remaining gaps are mostly final source reconstruction and broader error-hierarchy details. Evidence: IDA-confirmed constructor at `0x004a6430`, copy helper `0x004a6480-0x004a6499`, vtable slot note at `0x006193e0`, and `ErrorWrappers` memory page.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: constructor/copy-helper/vtable evidence supports shared `Error.cpp` ownership; archive/file docs remain caller-side evidence only.
