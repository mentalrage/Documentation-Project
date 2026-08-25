*** UID:0001Y3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No handwritten vtable or RTTI data should be emitted for [UID:0001Y3].
// The MapTileImageLib declaration, virtual destructor, and direct empty
// Singleton<MapTileImageLib> base regenerate the three-slot vtable and
// three-entry MapTileImageLib/LObject/Singleton class hierarchy.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib Vtable

## Status

- Confidence: very strong for slots, COL/CHD/base descriptors, exact three-entry hierarchy, direct Singleton PMD, owner association, and compiler-regenerated disposition.
- Evidence basis: IDA MCP `py_eval`, `xrefs_to`, and function lookup checks on 2026-05-26.
- Wave3 status: `class_MapTileImageLib.meta_wave3` now reports `vtable_count: 1` and `primary_vtable: 0x0061b664`.

## Primary Vtable

- RTTI pointer: `0x0061b660`
- Primary vtable: `0x0061b664`
- Owner class: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- Likely source file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Confirmed layout: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- Complete object locator: `0x00648774`; class hierarchy descriptor: `0x00648788`; base array: `0x00648798`.
- Type descriptors: `MapTileImageLib` at `0x00676738` and `Singleton<MapTileImageLib>` at `0x00676758`.
- Base descriptors: self BCD `0x006487a8`; direct Singleton BCD `0x006487c4`, PMD `+4/-1/0`. The exact hierarchy is `MapTileImageLib`, `LObject`, `Singleton<MapTileImageLib>`.

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | `0x004e66a0` | `MapTileImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited `LObject`/runtime virtual |
| `+0x08` | `0x0041b6c0` | inherited no-op virtual / `nullsub_18` |

IDA xrefs to `0x0061b664` land at:

- `0x004d18bb` in `MapTileImageLib::MapTileImageLib`
- `0x004d19ca` in [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- `0x004e66d1` in `MapTileImageLib::ScalarDeletingDestructor`

The table ends before the `ProtectedArray<HeadInfo>` RTTI pointer at `0x0061b670`.

2026-06-19 B015 local PE review reconfirms that slot `0x0061b664` points to [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md). This is separate tail support outside the [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) index span; coverage/source routing should keep [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) address-ordered at `0x004e66a0` and should not nest it under the local-method aggregate.

2026-07-14 B002 direct-base reanalysis ties the RTTI and executable lifetime together: constructor unwind state 1 adjusts the complete object by `+4` before tail-jumping to [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md), matching the direct Singleton BCD PMD exactly. The class declaration and virtual destructor regenerate the COL/CHD/base array, three vtable slots, UID0002J2 scalar wrapper, and UID000180 base-destructor instantiation; none should be hand-authored as raw ABI C++.

## 2026-06-08 Batch133 Live IDA Recheck

- IDA MCP `idb_meta` rechecked `NexusTK.exe` `sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `py_eval` reconfirmed the complete vtable sequence: `0x0061b660 -> ??_R4MapTileImageLib@@6B@`, `0x0061b664 -> 0x004e66a0`, `0x0061b668 -> 0x004f4b10`, `0x0061b66c -> 0x0041b6c0`, then `0x0061b670 -> ??_R4?$ProtectedArray@UHeadInfo@@@@6B@`.
- `xrefs_to 0x0061b664` still reports only the constructor, ordinary destructor, and scalar deleting destructor stores at `0x004d18bb`, `0x004d19ca`, and `0x004e66d1`. `xrefs_to 0x004e66a0` reports the vtable slot data reference at `0x0061b664`.
- Historical 2026-06-08 parent-side checks remained stable for constructor `0x004d1860-0x004d199e`, ordinary destructor `0x004d19a0-0x004d1a1c`, `DrawTile` `0x004d1a20-0x004d1b72`, `LoadTileEpfMetadata` `0x004d1b80-0x004d1f22`, then-termed singleton clear helper `0x004e5bc0-0x004e5bcb`, and scalar deleting destructor `0x004e66a0-0x004e6748`. The helper label is superseded by the current Singleton base-destructor identity.

## Assignment Gate

- `CANONICAL_OWNER`/emitter UID00007T routes this support through the complete class declaration, now `92/94`, and [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md). This page is `92/96` and emits only the accepted compiler-regenerated support comment.
- This is a single-class vtable layout. The direct owner is the `MapTileImageLib` class declaration; inherited `LObject` slots stay documented here as ABI evidence rather than source-authored overrides.

## Memory Coverage

The exact physical data span is now covered by [UID:0003BQ][0x0061b660-0x0061b670.MapTileImageLibVtableData](by-memory/0x0061b660-0x0061b670.MapTileImageLibVtableData.md), including the RTTI locator at `0x0061b660` and the primary vtable at `0x0061b664`. Batch 215 corrected the surrounding broad memory docs so [UID:00025H][0x0061b340-0x0061b660.HourIconsIdleReadOnlyData](by-memory/0x0061b340-0x0061b660.HourIconsIdleReadOnlyData.md) ends before this locator and [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md) starts with it.

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0003BQ][0x0061b660-0x0061b670.MapTileImageLibVtableData](by-memory/0x0061b660-0x0061b670.MapTileImageLibVtableData.md)
- [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)

## Changes

- 2026-07-14 B002 UID000180 implementation callback:
  - Raised `86/91` to `92/96`; installed the complete no-handwritten-vtable/RTTI formal block.
  - Added COL `0x00648774`, CHD `0x00648788`, base array `0x00648798`, self/Singleton descriptors, exact three-entry hierarchy, Singleton PMD `+4/-1/0`, EBO/lifetime linkage, and compiler-only UID000180/UID0002J2/vtable distinctions.
- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `85/90` to `86/91` and inserted the accepted generated-vtable no-code formal comment.
  - Preserved the `0x0061b660-0x0061b670` vtable-data facts, `0x0061b664 -> 0x004e66a0` scalar deleting destructor slot, and policy that the class declaration plus virtual destructor regenerate this compiler data.
- 2026-06-11 A001 Batch 215 memory child repair:
  - What existed before: the page recorded a memory coverage caveat because the exact `0x0061b660-0x0061b670` vtable-data span was split across two broad by-memory aggregates.
  - Changed to: replaced the caveat with a link to exact child [UID:0003BQ][0x0061b660-0x0061b670.MapTileImageLibVtableData](by-memory/0x0061b660-0x0061b670.MapTileImageLibVtableData.md) and updated the surrounding aggregate links to the corrected `0x0061b340-0x0061b660` / `0x0061b660-0x0061c360` split.
  - Summary/evidence: live IDA MCP on 2026-06-11 confirmed the `MapTileImageLib` locator/vtable dwords, vtable xrefs, deleting-destructor target, and following `ProtectedArray<HeadInfo>` locator.
- 2026-06-08 A005 Batch133:
  - What existed before: the page was `84/90` with a blank parent; the direct class parent and file parent were below the strict `85/85` gate.
  - Changed to: `85/90`, `AUTOGEN_PARENT_UID:00007T`, a live IDA recheck, assignment-gate rationale, and a memory coverage caveat for the existing broad read-only split around `0x0061b660`.
  - Summary/evidence: live IDA MCP reconfirmed the RTTI/vtable dwords, the constructor/destructor/deleting-destructor vtable-store xrefs, the vtable-slot reference to `0x004e66a0`, and the stable method/helper boundaries used to refresh the class/file parents.
- 2026-06-19 B015 tail-page placement sync:
  - Score unchanged. Added explicit support that the `0x0061b664 -> 0x004e66a0` scalar deleting destructor slot belongs to a standalone tail page, not the [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) local-method aggregate.
  - Evidence: B015 local PE pointer/vtable-slot scan and existing IDA xrefs agree on the scalar deleting destructor target.
- Completion/confidence metadata: existed before as `0/0`; changed to `84/90`. Summary: the three vtable slots, RTTI-adjacent bounds, owner xrefs, and constructor/destructor stores are IDA-verified. Evidence: `get_u32` values at `0x0061b664`, `0x0061b668`, and `0x0061b66c`; `xrefs_to 0x0061b664` at the constructor, ordinary destructor, and scalar deleting destructor.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Historical note: older wording left C++ blank because final source emission was not at the `95+` gate; B011's 2026-07-01 callback supersedes that with an accepted generated-vtable no-code formal comment.
