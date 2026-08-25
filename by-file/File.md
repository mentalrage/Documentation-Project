*** UID:0000JB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# File

## Status

- Confidence: very strong for the abstract file interface and direct source-root role; exact historical header spelling remains an inference cap.
- Proposed module: declaration in `NexusTK/util/File.h` and source-authored helper definitions in `NexusTK/util/File.cpp`.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Current recovered source lead: `class_File.cpp` only; ownership and scoring here are based on existing documentation plus IDA/MCP evidence, not generated source authority.
- Type docs: [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md), shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), and [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## File Role

`File.h` declares the abstract `LObject`-derived stream interface used by concrete file readers. `File.cpp` owns the two source-authored File convenience helpers. The vtable/RTTI record and scalar deleting destructor are compiler-generated from that declaration and are represented by covered-by markers rather than handwritten ABI source.

Do not place DAT archive parsing here. [UID:0000IN][DATFile](by-file/DATFile.md) implements the same file-like surface over packed archive entries and belongs under `archive/`.

The interface contract is explicit: IDA shows `File` slots `+0x0c` through `+0x28` are pure virtual and are filled by both [UID:0000IN][DATFile](by-file/DATFile.md) and [UID:0000O9][StdioFile](by-file/StdioFile.md). `File.h` is the common declaration point for `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, signed-count `Read`, ANSI `ReadLine`, and `ReadLineChars`; concrete implementation files remain split by backing store.

2026-06-07 IDA MCP recheck confirms `0x0049d390-0x0049d3ce` as the base destructor body referenced by the `File` vtable at `0x006188e4`. That vtable has the base destructor/runtime slots followed by pure virtual operation slots from `+0x0c` through `+0x28`, which supports keeping the abstract interface in a utility-layer source file rather than under archive, audio, map, or any concrete caller module.

## Batch088 Parent-Gate Audit

The direct parent for [UID:00004V][File](by-class/File.md) is this `File` source-root page, not the broader [UID:0000JD][FileIO](by-file/FileIO.md) umbrella. The parent now clears the corrected `85/85` gate because its abstract-source role is backed by exact destructor, vtable, layout, and concrete-subclass evidence:

- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md) documents the `0x0049d390-0x0049d3ce` destructor body, five bytes of preceding `cc` padding, two bytes of following `cc` padding, and the data xref from `0x006188e4`.
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md) records the RTTI pointer, destructor slot, base/no-op slot, `__purecall` operation slots, and five destructor/restoration vptr refs at `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be`; no constructor writes the abstract File vptr.
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) and [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) connect the four-byte data-member-free base layout and signed-count slot contract to the concrete DAT/Stdio implementations.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00004V][File](by-class/File.md) | `0x0049d390-0x0049d3cd` | Abstract file/stream base destructor and vtable contract. |
| [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) / shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) | `0x006188e4-0x00618910` | Base destructor plus pure virtual file operation slots. |
| [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) | size `0x08` | Vtable at `+0x00` and a concrete-implementation handle word at `+0x04`; final base-field name remains open. |
| [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) | `0x004b12a0-0x004b13ce` | File-class helper pair that reads a bounded byte span or a line through File stream virtual slots and writes string destinations. |

## 2026-06-10 B001-021 File-Stream Helper Sync

[UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) is now assigned through [UID:00004V][File](by-class/File.md). B001-021 resolved the previous `StringUtil`/`StringBase` ambiguity by comparing the helper virtual slots with live File-family vtable data:

- `0x004b12a0` calls virtual slots `+0x14`, `+0x1c`, and `+0x20`, matching File `Tell/GetPosition`, `GetSize`, and `Read`.
- `0x004b1340` calls virtual slot `+0x24`, matching File `ReadLine`.
- DATFile and StdioFile implement those same slots, while abstract File keeps them as pure virtual slots, so the helper pair belongs to the abstract File class/source root rather than either concrete reader.
- The string callees allocate and convert destination buffers; they are dependencies, not source ownership anchors.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `91` | The page documents the direct File.h/File.cpp route, complete class/helper inventory, exact compiler-generated vtable/destructor coverage, four-byte no-field layout, signed-count stream contract, DAT/Stdio boundaries, and generated-marker expectations. |
| Confidence `92` | IDA-backed memory/type docs, concrete subclass relationships, object-size immediates, and helper ABI prove the route. Confidence remains below final because the exact historical header filename and helper spelling/access are inferred. |

## UID0002UV Source-Quality Callback

- [UID:00004V][File](by-class/File.md) now emits the complete class shell at position `0` with an inline empty virtual destructor, all eight pure virtual operations, two helper declarations, and `[[CHILDREN]]`.
- [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) supplies the source-authored `ReadString(int)` and wide `ReadLine` definitions in File.cpp.
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md), [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md), [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md), and [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md) emit covered-by/no-standalone-code markers because the compiler regenerates those artifacts from File.h.
- Current pre-callback generated File.cpp contained four empty markers, one each for the class, helper pair, target vtable data, and scalar wrapper. The accepted callback replaces all four with the class/helper source or explicit compiler-data markers.
- File has no source data member. The wrapper size triad proves File `4`, DATFile `0x14`, and StdioFile `0x0c`; the historical eight-byte shared-handle model is superseded.
- `Read` returns `size_t` and takes `int count`. DATFile's negative-count full-payload behavior is part of the common virtual contract and requires the Stdio declaration/body to use the same signed parameter.
- [UID:0000JD][FileIO](by-file/FileIO.md) remains useful only as a non-emitting coordination page. The earlier possible compact `FileIO.cpp` folding is retained as rejected source-layout history, not a current alternative.

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)
- [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:80`.
  - Summary/evidence: abstract stream interface role, vtable/layout contract, DAT/StdioFile boundary, proposed placement, and core cross-references are documented; completion is moderate because this is a small base-interface page and detailed implementation behavior lives in concrete file pages.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `80/80`, and the module path used `util/File.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `82/84`, and proposed module `NexusTK/util/File.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the `0x0049d390-0x0049d3ce` destructor body, `File` vtable xref, and pure virtual operation slots, matching the existing `proposed-source-tree.md` utility placement. C++ reconstruction remains blank because the original one-file versus split-file boundary with `StdioFile` is still not fully proven.
- 2026-06-07 Batch088 parent-gate audit:
  - Before: scores were `82/84`, leaving this direct parent below the corrected child-and-parent `85/85` assignment gate for [UID:00004V][File](by-class/File.md).
  - After: raised to `85/87`.
  - Summary/evidence: exact destructor, vtable-data, file-stream layout, and subclass-slot docs plus live IDA/MCP recheck prove this page is the direct utility-layer source root for the abstract `File` class. The page still stays below final-source quality because the original split between `File.cpp`, `StdioFile.cpp`, and a possible compact FileIO unit is not fully proven.
- 2026-06-10 B001-021 helper ownership sync:
  - Before: scores were `85/87`, and [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) was documented elsewhere as unresolved between string utility candidates.
  - After: raised to `86/88` and added `00022C` as a File-class/source-root helper pair.
  - Summary/evidence: live IDA MCP compares the helper's `+0x14/+0x1c/+0x20/+0x24` virtual calls against the File/DATFile/StdioFile slot map; the receiver is the File stream interface, while StringUtil/StringBase are only output-buffer dependencies.
- 2026-06-12 A004 Batch 319 vtable split sync:
  - Scores remain `86/88`.
  - Added [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) as the exact source-local vtable child for the abstract `File` declaration; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) is now a non-emitting shared slot-layout index.
