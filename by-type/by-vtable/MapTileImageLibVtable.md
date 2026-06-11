*** UID:0001Y3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib Vtable

## Status

- Confidence: strong for slot values and owner association.
- Evidence basis: IDA MCP `py_eval`, `xrefs_to`, and function lookup checks on 2026-05-26.
- Wave3 status: `class_MapTileImageLib.meta_wave3` now reports `vtable_count: 1` and `primary_vtable: 0x0061b664`.

## Primary Vtable

- RTTI pointer: `0x0061b660`
- Primary vtable: `0x0061b664`
- Owner class: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- Likely source file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Confirmed layout: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)

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

## 2026-06-08 Batch133 Live IDA Recheck

- IDA MCP `idb_meta` rechecked `NexusTK.exe` `sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `py_eval` reconfirmed the complete vtable sequence: `0x0061b660 -> ??_R4MapTileImageLib@@6B@`, `0x0061b664 -> 0x004e66a0`, `0x0061b668 -> 0x004f4b10`, `0x0061b66c -> 0x0041b6c0`, then `0x0061b670 -> ??_R4?$ProtectedArray@UHeadInfo@@@@6B@`.
- `xrefs_to 0x0061b664` still reports only the constructor, ordinary destructor, and scalar deleting destructor stores at `0x004d18bb`, `0x004d19ca`, and `0x004e66d1`. `xrefs_to 0x004e66a0` reports the vtable slot data reference at `0x0061b664`.
- Parent-side live checks remained stable: constructor `0x004d1860-0x004d199e`, ordinary destructor `0x004d19a0-0x004d1a1c`, `DrawTile` `0x004d1a20-0x004d1b72`, `LoadTileEpfMetadata` `0x004d1b80-0x004d1f22`, singleton clear helper `0x004e5bc0-0x004e5bcb`, and scalar deleting destructor `0x004e66a0-0x004e6748`.

## Assignment Gate

- `AUTOGEN_PARENT_UID` points to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md). This page is now `85/90`, the direct class parent is now `85/85`, and the class page remains attached to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), now `86/85`.
- This is a single-class vtable layout. The direct owner is the `MapTileImageLib` class declaration; inherited `LObject` slots stay documented here as ABI evidence rather than source-authored overrides.

## Memory Coverage Caveat

The exact physical data span is `0x0061b660-0x0061b670`, including the RTTI locator at `0x0061b660`. Current broad memory docs split that exact span across [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) and [UID:00025I][0x0061b664-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md), so an exact `MapTileImageLib` vtable-data child requires a coordinated re-range of those broad read-only pages rather than an overlapping child in this pass.

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)

## Changes

- 2026-06-08 A005 Batch133:
  - What existed before: the page was `84/90` with a blank parent; the direct class parent and file parent were below the strict `85/85` gate.
  - Changed to: `85/90`, `AUTOGEN_PARENT_UID:00007T`, a live IDA recheck, assignment-gate rationale, and a memory coverage caveat for the existing broad read-only split around `0x0061b660`.
  - Summary/evidence: live IDA MCP reconfirmed the RTTI/vtable dwords, the constructor/destructor/deleting-destructor vtable-store xrefs, the vtable-slot reference to `0x004e66a0`, and the stable method/helper boundaries used to refresh the class/file parents.
- Completion/confidence metadata: existed before as `0/0`; changed to `84/90`. Summary: the three vtable slots, RTTI-adjacent bounds, owner xrefs, and constructor/destructor stores are IDA-verified. Evidence: `get_u32` values at `0x0061b664`, `0x0061b668`, and `0x0061b66c`; `xrefs_to 0x0061b664` at the constructor, ordinary destructor, and scalar deleting destructor.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: this is compiler-emitted but rebuild-relevant class metadata for `MapTileImageLib`; parent UID and C++ reconstruction remain blank because final source emission is not at the `95+` gate.
