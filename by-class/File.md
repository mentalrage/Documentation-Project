*** UID:00004V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# File

## Status

- Confidence: strong for abstract base role, vtable contract, and direct source-root attachment.
- Assigned source root: [UID:0000JB][File](by-file/File.md), under the [UID:0000JD][FileIO](by-file/FileIO.md) utility layer
- Current recovered source lead: `class_File.cpp` only; class ownership here is based on existing docs plus IDA/MCP evidence.
- Address evidence: [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- Size/layout: 8 bytes; see [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md).
- Vtable/type evidence: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)

## Role

`File` is the abstract file-stream base class used by archive-backed and loose-file readers. It contributes the vtable contract and small source-authored convenience helpers over that contract, while concrete subclasses such as [UID:00003G][DATFile](by-class/DATFile.md) and [UID:0000E6][StdioFile](by-class/StdioFile.md) implement open, close, positioning, size, read, and line-read behavior.

## Confirmed Behavior

| Address | Method | Notes |
| --- | --- | --- |
| `0x0049d390` | `ScalarDeletingDestructor` | Restores the `File` vtable, destroys the `LObject` base, and conditionally frees the object. |
| [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) | file-stream string helper pair | B001-021 assigns this pair here: `0x004b12a0` uses slots `+0x14/+0x1c/+0x20` to read a bounded byte span into a string, and `0x004b1340` uses slot `+0x24` to read a line then converts it to the wide/shared string destination. |

IDA vtable inspection shows `File` has pure virtual entries after the inherited/base runtime slots. `StdioFile` fills the same slots with local `FILE*` operations; `DATFile` fills them with mapped-DAT entry operations.

2026-06-07 IDA MCP recheck confirms the destructor body remains `0x0049d390-0x0049d3ce`, with five bytes of preceding `cc` padding and two bytes of following `cc` padding. The only direct xref to the function start is the File vtable data entry at `0x006188e4`.

## Interface Slots

The primary vtable at `0x006188e4` has destructor/base slots at `+0x00` through `+0x08`; slots `+0x0c` through `+0x28` are pure virtual in `File` and concrete in `DATFile`/`StdioFile`. The current names are `Open`, `Close`, `Tell`/`GetPosition`, `Seek`, `GetSize`, `Read`, `ReadLine`, and raw line read. See [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) for the exact slot map.

The adjacent read-only data page records the exact vtable dwords: RTTI at `0x006188e0`, destructor `0x0049d390` at `0x006188e4`, base/runtime slot `0x004f4b10`, no-op slot `0x0041b6c0`, and `__purecall` entries through `0x0061890c`. Vptr-store xrefs at `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be` tie the abstract base to constructor/destructor paths for the concrete stream family.

Layout note: the 8-byte base footprint includes the vtable pointer at `+0x00` and an implementation-handle word at `+0x04`. `StdioFile` uses that word as `FILE*`; `DATFile` uses it as an archive/container handle.

## 2026-06-10 B001-021 File-Stream Helper Assignment

B001-021 rechecked [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) after prior docs left it unassigned as a possible string utility helper. Live IDA MCP confirms it is a `File` convenience helper pair:

- `0x004b12a0` dispatches through `this->vtable` slots `+0x14`, `+0x1c`, and `+0x20`.
- `0x004b1340` dispatches through `this->vtable` slot `+0x24`.
- Direct IDA vtable reads show the abstract File vtable keeps those slots as `__purecall`, DATFile implements them at `0x0049c2d0`, `0x0049c2f0`, `0x0049c310`, and `0x0049c3e0`, and StdioFile implements them at `0x00582200`, `0x004f5ad0`, `0x00582230`, and `0x005822d0`.
- The string helper callees allocate/assign the output buffers; they do not make `StringUtil` or `StringBase` the direct owner.

The helper pair has no direct callers or address-taken refs in current IDA, so final method names remain open. The direct class parent still clears the strict gate: this class is now `86/89`, and [UID:0000JB][File](by-file/File.md) is now `86/88`.

## Ownership Notes

Keep this with the generic file I/O layer, not with DAT parsing. The base class does not know about archive entry tables, stat buffers, or Miles callbacks; those belong to `DATFile`, `StdioFile`, and `SoundManager` consumers respectively.

## Assignment Decision

Assigned to [UID:0000JB][File](by-file/File.md) under the corrected Batch088 gate. This class now has `86/89` documentation, and the direct parent is now `86/88` after the B001-021 helper sync. The broader [UID:0000JD][FileIO](by-file/FileIO.md) umbrella is not the direct parent for this class.

Final C++ remains blank because the declaration is useful but not yet at the `95/95` source-emission gate; exact original method names, header split, and integration with `StdioFile` still need final reconstruction review.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The class page now records the abstract stream role, destructor range, vtable dwords/xrefs, 8-byte layout, concrete subclass relationship, direct file parent, B001-021 file-stream string helper pair, and assignment rationale. It remains below final because the final C++ declaration, exact field names, method names, and source/header split are not yet fully reconstructed. |
| Confidence `89` | Confidence is strong because the class identity and parent relationship are backed by IDA-verified destructor/vtable evidence, concrete DAT/Stdio slot matching, and the B001-021 helper's direct use of File stream slots. Confidence remains below final audit because some source-level names and the original file split remain inferred. |

## Cross-References

- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)
- [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md)

## Changes

- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the abstract `File` vtable at `0x006188e4`, base destructor at `0x0049d390`, and shared virtual stream contract implemented by `DATFile` and `StdioFile`; no parent/code was attached because final declaration shape remains below the 95+ gate.

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: abstract base role, known destructor behavior, vtable slot responsibilities, and subclass relationships are documented with strong confidence, while exact recovered source and all consumer paths remain incomplete. Evidence: `0x0049d390` destructor page, `FileStreamVtables`, `FileStreamLayouts`, and cross-references to `DATFile` and `StdioFile`.
- 2026-06-07 Batch088 class coverage audit:
  - Before: scores were `76/86`, `AUTOGEN_PARENT_UID` was blank, and the direct by-file parent was below the corrected parent gate.
  - After: raised to `85/88` and assigned to [UID:0000JB][File](by-file/File.md) after that parent was raised to `85/87`.
  - Summary/evidence: live IDA/MCP recheck and existing by-memory/type docs confirm destructor bounds, vtable dwords, vptr-store xrefs, pure virtual operation slots, and the concrete DAT/Stdio implementations. C++ remains blank under the 95/95 source-emission gate.
- 2026-06-10 B001-021 helper ownership repair:
  - Before: `00022C` remained unassigned as a possible string utility helper even though it dispatched through virtual slots.
  - After: raised this class to `86/89` and accepted [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) as a File-class helper pair.
  - Summary/evidence: live IDA MCP maps the helper virtual slots to the File stream contract and confirms StringUtil/StringBase are output-buffer dependencies rather than direct owners.
