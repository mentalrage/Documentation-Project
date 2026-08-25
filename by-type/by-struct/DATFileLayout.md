*** UID:0003H3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATFile Layout

## Status

- Entity kind: non-emitting semantic class-layout overlay.
- Disposition: preserve exact 0x14 layout evidence here; [UID:00003G][DATFile](by-class/DATFile.md) H is the sole human source declaration.
- Owner/emitter: none; the former direct-owner route is superseded to prevent duplicate declarations.
- Source context: [UID:0000IN][DATFile](by-file/DATFile.md).
- Evidence basis: live IDA MCP checks on 2026-06-12 plus [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md), [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md), and [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md).

This page splits the concrete `DATFile` layout out of the mixed [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) family for evidence and review only. It emits no source.

## Layout

`DATFile` is a 20-byte (`0x14`; decimal 20, Verified with int_convert.py) concrete subclass of the 4-byte (`0x04`; decimal 4, Verified with int_convert.py) data-member-free [UID:00004V][File](by-class/File.md) base.

| Offset | Size | Field hypothesis | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | `0x04` | `File`/`LObject` vtable head | Constructor `0x0049c130` installs vtable `0x00618924`; destructor paths restore the abstract `File` vtable. |
| `+0x04` | `0x04` | DATFile-owned archive/container field | `Open`, `Close`, `GetPosition`, `GetSize`, and `Read` test this slot before using entry data. |
| `+0x08` | `0x04` | entry-record pointer/handle | `Open` / `OpenByIndex` set this to the resolved 17-byte entry record; `Close` clears it. |
| `+0x0c` | `0x04` | current absolute payload offset | `GetPosition` subtracts the entry start offset from this value; `Read` advances it after copying bytes. |
| `+0x10` | `0x04` | payload size | `Open` computes it from adjacent DAT entry start offsets; `GetSize` returns it. |

## IDA Evidence

2026-06-12 A004 live IDA MCP `lookup_funcs` confirms the concrete slot targets and sizes: constructor `0x0049c130` size `0x2a`, `Open` `0x0049c180` size `0xbb`, `Close` `0x0049c240` size `0x20`, `Seek` `0x0049c260` size `0x6c`, `GetPosition` (historically `Tell`) `0x0049c2d0` size `0x17`, `GetSize` `0x0049c2f0` size `0x14`, `Read` `0x0049c310` size `0x52`, raw-line read `0x0049c370` size `0x6f`, and string line read `0x0049c3e0` size `0xb9`.

`xrefs_to 0x00618924` reports the constructor vtable-install ref at `0x0049c13f`.

`analyze_function 0x0049c180` confirms `Open` calls the DAT entry lookup helper, throws `FileError` when lookup fails, stores the archive/container at `this[1]`, stores the entry record at `this[2]`, initializes `this[3]` from the entry start offset, and computes/stores payload size in `this[4]`. Current IDA reports broad `Open` fan-in from resource, render, map, and audio loaders plus the [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) lifecycle helper.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:00003G][DATFile](by-class/DATFile.md). The child layout is `90/93`, and the direct class parent is `89/92`. This page attaches to the class rather than the archive file root because it is class storage.

## Score Rationale

Completion is `90` because the exact 20-byte size, four-byte base, all derived fields, scalar-wrapper size proof, concrete virtual evidence, signed Read behavior, vtable ref, source owner, and split rationale are documented. Confidence is `93` because wrapper, constructor, Open, position, size, and Read evidence agree; field spellings remain provisional.

## UID0002UV Source-Quality Callback

- Preserved the blank formal, direct DATFile class route, source owner, and all method/caller evidence.
- Corrected the base from eight bytes to four bytes and identified `+0x04/+0x08/+0x0c/+0x10` as DATFile-owned fields.
- DATFile scalar wrapper pushes `0x14`, exactly matching the complete layout.
- Current source-facing position name is `GetPosition`; `Tell` remains historical.
- `Read` returns `size_t` and takes signed `int count`; its negative-count full-payload branch is direct type evidence.
- The old shared File handle is rejected because it would misplace all derived fields.
- Raised only this page from `86/89` to `90/93`; no class formal was added.

## Cross-References

- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:00004V][File](by-class/File.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)

## Changes

- 2026-06-12 A004 Batch 297 split: created this exact source-owned child from the former mixed `FileStreamLayouts` page. Live IDA MCP reconfirmed the method sizes, vtable ref, DAT-entry field stores, broad caller set, and 20-byte layout; final C++ remains blank below the 95/95 source-emission gate.
