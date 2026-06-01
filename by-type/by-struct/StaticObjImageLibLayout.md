*** UID:0001W9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib Layout

## Status

- Confidence: strong for field offsets, medium for final field names.
- Owner class: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md).
- Evidence: IDA constructor/destructor/render decompilation on 2026-05-26.

## Layout

```text
StaticObjImageLib
  +0x00  LObject/vtable
  +0x04  ArchiveMetadataTable* tileCatalog
  +0x08  TileClassEntry* tileClasses
  +0x0c  StaticObjEntry** staticObjEntries
  +0x10  int staticObjCount
```

## Notes

- The constructor fills `+0x0c` with `staticObjCount` heap pointers to variable-size [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) records loaded from `SOBJ.TBL`.
- The constructor fills `+0x08` with four-byte [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md) records loaded from `TILEC.TBL` or `TILEC.TBD`.
- `RenderStaticObject` resolves `staticObjEntries[staticObjectId - 1]`, reads its layer count from entry offset `+0x05`, and walks tile ids from entry offset `+0x0c`.
- The ordinary and scalar deleting destructors release the static-object records, tile catalog/cache chain, tile-class table, and [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md).

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x004dcf60` confirms the constructor stores the singleton at `0x0069b448`, installs `StaticObjImageLib` vtable at `+0x00`, writes the TILEC archive metadata pointer to `+0x04`, writes the tile-class table pointer to `+0x08`, writes the static-object entry pointer array to `+0x0c`, and keeps the static-object count at `+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x004dd2c0` confirms `RenderStaticObject` resolves entries through `this+0x0c`, checks the object id against `this+0x10`, and uses `this+0x04`/`this+0x08` to resolve frame metadata and tile-class flags.
- 2026-05-31 IDA MCP decompilation of `0x004dd850` confirms bounds lookup uses `this+0x0c` and `this+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x004dd1e0` confirms destructor ownership of the entry array at `+0x0c`, tile catalog/cache at `+0x04`, tile-class table at `+0x08`, and singleton clear at `0x0069b448`.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing field-offset notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, renderer, bounds helper, and destructor field use. The score remains below the final-source threshold because final source field names and all dependent helper/data-table pages are not yet audited to near-final quality.
