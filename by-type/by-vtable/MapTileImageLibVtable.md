*** UID:0001Y3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)

## Changes

- Completion/confidence metadata: existed before as `0/0`; changed to `84/90`. Summary: the three vtable slots, RTTI-adjacent bounds, owner xrefs, and constructor/destructor stores are IDA-verified. Evidence: `get_u32` values at `0x0061b664`, `0x0061b668`, and `0x0061b66c`; `xrefs_to 0x0061b664` at the constructor, ordinary destructor, and scalar deleting destructor.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: this is compiler-emitted but rebuild-relevant class metadata for `MapTileImageLib`; parent UID and C++ reconstruction remain blank because final source emission is not at the `95+` gate.
