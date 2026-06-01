*** UID:00004V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# File

## Status

- Confidence: strong for abstract base role.
- Proposed path: [UID:0000JB][File](by-file/File.md), under the [UID:0000JD][FileIO](by-file/FileIO.md) utility layer
- Current Wave3 file: `class_File.cpp`
- Address evidence: [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- Size/layout: 8 bytes; see [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md).
- Vtable/type evidence: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)

## Role

`File` is the abstract file-stream base class used by archive-backed and loose-file readers. It contributes the vtable contract, while concrete subclasses such as [UID:00003G][DATFile](by-class/DATFile.md) and [UID:0000E6][StdioFile](by-class/StdioFile.md) implement open, close, positioning, size, read, and line-read behavior.

## Confirmed Behavior

| Address | Method | Notes |
| --- | --- | --- |
| `0x0049d390` | `ScalarDeletingDestructor` | Restores the `File` vtable, destroys the `LObject` base, and conditionally frees the object. |

IDA vtable inspection shows `File` has pure virtual entries after the inherited/base runtime slots. `StdioFile` fills the same slots with local `FILE*` operations; `DATFile` fills them with mapped-DAT entry operations.

## Interface Slots

The primary vtable at `0x006188e4` has destructor/base slots at `+0x00` through `+0x08`; slots `+0x0c` through `+0x28` are pure virtual in `File` and concrete in `DATFile`/`StdioFile`. The current names are `Open`, `Close`, `Tell`/`GetPosition`, `Seek`, `GetSize`, `Read`, `ReadLine`, and raw line read. See [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) for the exact slot map.

Layout note: the 8-byte base footprint includes the vtable pointer at `+0x00` and an implementation-handle word at `+0x04`. `StdioFile` uses that word as `FILE*`; `DATFile` uses it as an archive/container handle.

## Ownership Notes

Keep this with the generic file I/O layer, not with DAT parsing. The base class does not know about archive entry tables, stat buffers, or Miles callbacks; those belong to `DATFile`, `StdioFile`, and `SoundManager` consumers respectively.

## Cross-References

- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)

## Changes

- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the abstract `File` vtable at `0x006188e4`, base destructor at `0x0049d390`, and shared virtual stream contract implemented by `DATFile` and `StdioFile`; no parent/code was attached because final declaration shape remains below the 95+ gate.

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: abstract base role, known destructor behavior, vtable slot responsibilities, and subclass relationships are documented with strong confidence, while exact recovered source and all consumer paths remain incomplete. Evidence: `0x0049d390` destructor page, `FileStreamVtables`, `FileStreamLayouts`, and cross-references to `DATFile` and `StdioFile`.
