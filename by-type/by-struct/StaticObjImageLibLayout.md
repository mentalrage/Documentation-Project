*** UID:0001W9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib Layout

## Status

- Confidence: strong for field offsets and owner class, medium for final field names.
- Owner class: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md).
- Evidence: IDA constructor/destructor/render/bounds decompilation rechecked through Batch 132.
- Assignment: attached to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) after this layout reached `85/88` and the direct class parent is `86/85`.

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
- 2026-06-08 Batch 132 IDA MCP recheck confirms the constructor at `0x004dcf60` publishes [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md), writes the `StaticObjImageLib` vtable at `+0x00`, opens `SOBJ.TBL`, stores the entry count at `+0x10`, allocates the entry pointer array at `+0x0c`, builds per-entry records with layer count at entry `+0x05`, and initializes `+0x04`/`+0x08` from the `TILEC` resource path.
- The same recheck confirms `RenderStaticObject` at `0x004dd2c0` uses `this+0x0c` for entry pointers, `this+0x10` for the object-id bound, `this+0x04` for frame metadata, and `this+0x08` for tile-class flags; `GetStaticObjectBounds` at `0x004dd850` uses the same entry/count pair to compute local bounds.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). This layout page is `85/88`, the direct class parent is `86/85`, and the file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) is `86/85`. The by-structure relationship is direct: the by-struct layout describes the in-memory object layout of the owning class.

## Score Rationale

- `COMPLETION:85`: the page records the complete observed object field map, constructor stores, renderer/bounds usage, destructor ownership, singleton/vtable context, dependent entry/tile-class structs, and direct parent chain.
- `CONFIDENCE:88`: constructor, renderer, bounds helper, and destructor decompilation agree on offsets and ownership. Confidence remains below final-source levels because the original member names and helper naming are still inferred.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)

## Changes

- 2026-06-08 A003 Batch132:
  - Before: `78/86`, parent blank, with good field-offset notes but no strict-gate assignment section.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000E2`.
  - Evidence: live IDA MCP rechecked constructor, destructor, render, bounds, vtable, and singleton usage. The direct class parent [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) is `86/85` and the file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) is `86/85`, so the corrected child-and-parent gate is met.

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing field-offset notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, renderer, bounds helper, and destructor field use. The score remains below the final-source threshold because final source field names and all dependent helper/data-table pages are not yet audited to near-final quality.
