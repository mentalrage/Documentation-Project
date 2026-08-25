*** UID:0001V2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No separate layout C++ should be emitted for [UID:0001V2].
// The MapTileImageLib declaration emitted by [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) owns the
// LObject base at +0x00, empty Singleton<MapTileImageLib> base at +0x04,
// ArchiveMetadataTable pointer at +0x04, and MapTileRecord pointer at +0x08.
// Direct RTTI PMD +0x04 and the 0x0c complete size prove EBO overlap.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib Layout

## Status

- Entity kind: class layout support struct.
- Confidence: very strong for direct bases, PMD/EBO, observed offsets, `0x0c` size, ownership, and reachability; final source member names use accepted bounded aliases.
- Proposed owner: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md), emitted through [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- Autogen parent: attached to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md), emitted through [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md); this support page contributes no duplicate class declaration.
- Evidence basis: IDA MCP constructor/destructor/draw decompile checks, vtable xrefs, singleton xrefs, read-only PE section scan, current exact by-memory child pages, and current support docs. Generated `simroot_v2` data is only a lead source.

## Layout

```text
MapTileImageLib
  +0x00  LObject base / MapTileImageLib vptr
  +0x04  empty Singleton<MapTileImageLib> direct base (PMD +4/-1/0)
  +0x04  ArchiveMetadataTable* tileFrameTable (EBO overlap)
  +0x08  MapTileRecord* tileRecords
```

Observed object size is `0x0c` bytes.

## Field Evidence

- The constructor stores [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)'s return value at `+0x04`, best documented as `ArchiveMetadataTable *tileFrameTable`.
- `DrawTile` reads `+0x04` before calling `LoadFrameDrawRecord_4D1600` / `0x004d1600`, using the field as the tile frame metadata table.
- The constructor allocates `4 * tileCount` bytes and stores the result at `+0x08`.
- The constructor decodes each `TILE.TBL` packed word into one [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md) at `+0x08 + 4 * index`.
- The ordinary and scalar deleting destructors free both `+0x04` metadata storage and the `+0x08` tile-record array, then clear [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md).
- Original RTTI records exactly three hierarchy entries: `MapTileImageLib`, `LObject`, and direct `Singleton<MapTileImageLib>`. The Singleton BCD at `0x006487c4` has PMD `+4/-1/0`; because the base is empty, it overlaps the `tileFrameTable` storage without increasing the `0x0c` complete size.
- Constructor publication at `0x004d18a3`, constructor-EH clear through UID000180, ordinary clear at `0x004d19f9`, and scalar clear at `0x004e6700` are direct Singleton base lifetime lowering, not additional data members or handwritten field operations.

## 2026-05-31 IDA Recheck

- `sub_4D1860` stores [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md), writes [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md), stores the [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md) result at object `+0x04`, and stores the allocated [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md) array at object `+0x08`.
- `sub_4D1A20` reads `this[1]` / object `+0x04` as the frame metadata table and `this[2]` / object `+0x08` as the 4-byte tile-record array.
- `sub_4D19A0` and `sub_4E66A0` release the metadata payload/table and the tile-record array, confirming both non-base fields are owned by this object.
- `xrefs_to 0x0061b664` lands only in the constructor, ordinary destructor, and scalar deleting destructor. The vtable ends before the next RTTI pointer at `0x0061b670`.

## 2026-06-16 A001 Evidence Refresh

- Live IDA MCP database `b001_mappane_0001AW_20260616` reconfirmed the exact function starts and boundaries: constructor `0x004d1860` size `0x13e` / 318 bytes, ordinary destructor `0x004d19a0` size `0x7c`, `DrawTile` `0x004d1a20` size `0x152` / 338 bytes, metadata helper `0x004d1b80` size `0x3a2`, singleton-clear helper `0x004e5bc0` size `0x0b`, and scalar deleting destructor `0x004e66a0` size `0xa8` / 168 bytes. `int_convert.py` verified the documented decimal conversions.
- Constructor decompilation still stores the metadata helper return at `this + 0x04` and allocates `4 * tileCount` bytes at `this + 0x08`; the record decode writes the low 15-bit value at record `+0x00` and the high-bit palette-filter flag at record `+0x02`.
- `DrawTile` decompilation still reads `v10[1]` / object `+0x04` as the metadata table for `LoadFrameDrawRecord_4D1600`, and reads `v6[2]` / object `+0x08` as the tile-record array before the palette-filter gate.
- Ordinary destructor decompilation restores the MapTileImageLib vtable, frees the metadata payload/table through MemoryMan helpers, frees `*(this + 8)`, clears [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md), and then runs base `LObject` cleanup.
- `xrefs_to` and the section-mapped PE scan agree on reachability: one constructor call at `0x004f6055`, four `DrawTile` calls at `0x00424441`, `0x0050c3d7`, `0x0050d984`, and `0x005497d0`, one metadata-helper call at `0x004d18d1`, one singleton-clear call at `0x005ff9bb`, and one scalar deleting destructor data ref from vtable slot `0x0061b664`.
- Vtable/global checks remain clean: `0x0061b664` has exactly the three install/restore refs from constructor, ordinary destructor, and scalar deleting destructor; `0x0067a75c` has ten singleton refs across construction, cleanup, shutdown, and consumers. The PE scan found no additional RVA-only hits.
- `search_structs` for `MapTileImageLib` returned no local IDA struct/type record. Current source-facing documentation uses `tileFrameTable` and `tileRecords`; B011's 2026-07-01 accepted callback supersedes the stale `95+`/blank-gate wording with a formal no-duplicate layout comment because the class declaration [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) owns the source fields and this support page preserves offset evidence only.
- 2026-06-19 B015 raw PE recheck adds no layout offset changes, but it confirms the active layout validators are the exact child pages: constructor [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) initializes `tileFrameTable`/`tileRecords`, destructor [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) frees both, draw method [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) consumes both, and scalar deleting destructor [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) mirrors cleanup from a separate vtable-tail page outside the [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) aggregate span.
- 2026-07-14 B002 direct-base evidence: COL `0x00648774`, CHD `0x00648788`, base array `0x00648798`, and Singleton BCD `0x006487c4` establish the complete hierarchy and PMD. Constructor unwind action `0x005ff9b5` forms `this+4` before tail-jumping to UID000180, independently confirming that the empty direct base occupies the EBO address shared with `tileFrameTable`.

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md)

## Changes

- 2026-07-14 B002 UID000180 implementation callback:
  - Raised `87/90` to `92/96` and installed the accepted covered layout block with `LObject` at `+0x00`, empty direct Singleton base and `tileFrameTable` at `+0x04`, `tileRecords` at `+0x08`, and complete size `0x0c`.
  - Added exact COL/CHD/BCD PMD, constructor-EH adjusted receiver, EBO overlap, and implicit lifetime evidence without duplicating class C++.
- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `86/90` to `87/90` and inserted the accepted no-duplicate layout formal comment.
  - Historicalized stale `95+`/blank-gate language: layout C++ is intentionally covered by the [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) class declaration, not blocked for lack of source-quality evidence.
- 2026-06-17 B003 source-quality support update:
  - Standardized object field names to `tileFrameTable` at `+0x04` and `tileRecords` at `+0x08`.
  - Kept the score unchanged at `86/90`; this support page already cleared the gate, and B003's primary score increases belong to the constructor/helper pages.
  - Evidence: constructor/draw/destructor usage proves the field roles, while exact original wrapper spelling remains a formal-C++ caveat.
- 2026-06-19 B015 layout support sync:
  - Score unchanged. Added that the B015 aggregate pass confirms the same exact children as layout validators and does not introduce new field offsets or source declarations.
  - Evidence: local PE boundary checks and child-page ownership show [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) is an index while the constructor/destructor/draw/scalar-wrapper pages carry layout validation.
- 2026-06-16 A001 layout evidence refresh: Raised completion/confidence from `84/88` to `86/90`.
  - Before: the page had stale direct-parent score text and only older MapTileImageLib IDA evidence.
  - After: synced the current class/file parent gate, added live IDA MCP boundary/decompile/xref evidence, added a read-only PE reachability scan, recorded the negative local-type search, and kept final C++ blank because source member names and helper signatures remain below the final-source gate.
  - Evidence: live IDA `lookup_funcs`, `decompile`, `xrefs_to`, `get_bytes`, `search_structs`, local `int_convert.py`, current support docs, and the section-mapped PE scan.
- 2026-06-06 A004 parent-gate sync: moved `AUTOGEN_PARENT_UID` from [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) after the class page was refreshed to `84/84` and attached to the file root. Scores remain `84/88`; this is a parent metadata cleanup.
- 2026-06-06: Attached the layout to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) as a file-level parent. Scores remain `84/88`; this was a parent metadata cleanup while the direct class page remained below the confidence gate.
- Completion/confidence metadata: existed before as `0/0`; changed to `84/88`. Summary: object size, vtable install, singleton, owned metadata pointer, owned tile-record array, draw-path reads, and cleanup sites are now directly documented from IDA. Evidence: [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md), [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md), [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md), and [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md).
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Historical note: older wording said parent UID and C++ reconstruction remained blank because final source names and source-shape were below the `95+` final-source gate; B011's 2026-07-01 callback supersedes that gate with a covered-by-class no-duplicate formal comment.
