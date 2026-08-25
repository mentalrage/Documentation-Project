*** UID:0001W8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticObjEntry

## Status

- Confidence: very strong for packed offsets, minimum/allocation size, constructor population, renderer/bounds/destructor/lighting consumers, direct owner, class-H declaration route, and source-facing names; original spellings remain inferred.
- Owner class: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md).
- Owner file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- Source resource: [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md).
- Assignment: attached to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) after this struct reached `85/88` and the direct class parent is `86/85`.

## Layout

```text
StaticObjEntry
  +0x00  int32  lightImageIndex
  +0x04  uint8  lightHeightClass
  +0x05  uint8  layerCount
  +0x06  uint16 reserved
  +0x08  StaticObjEntry* cacheChain
  +0x0c  uint16 tileIds[layerCount]
  minimum sizeof 0x0e under 2-byte packing
```

## Notes

- The constructor allocates each record as `0x0c + 2 * layerCount` bytes and copies the trailing `uint16` list from `SOBJ.TBL`.
- The complete declaration appears exactly once in [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) H inside `#pragma pack(push, 2)` / `#pragma pack(pop)`. This child keeps blank CPP/H to avoid duplicate type emission.
- The formal one-element tail makes `sizeof(StaticObjEntry) == 0x0e`; runtime allocation uses `offsetof(StaticObjEntry, tileIds) + sizeof(unsigned short) * layerCount`, so records with more than one layer extend beyond the formal minimum.
- The constructor reads a secondary one-byte field between `lightHeightClass` and `layerCount`, but current IDA output shows the in-memory `+0x06` word is zeroed rather than preserving that byte.
- `RenderStaticObject` reads `layerCount` from offset `+0x05`, then draws tile ids from the inline list in reverse order.
- `GetStaticObjectBounds` uses `layerCount` from `+0x05` to derive the negative vertical extent from map-tile height.
- `ObjectList::RefreshStaticObjectLighting` and `MapPane::CreateStaticObjectPaneForTile` both call the StaticObjImageLib lookup helper, test `lightImageIndex` / `+0x00` as signed metadata, and pass nonnegative values to `LightingObjectPane` creation/update. Negative values suppress or remove the companion. `lightHeightClass` / `+0x04` feeds exact `tileHeight / 2 - tileHeight * lightHeightClass` placement arithmetic in both consumers. This proves an image-table index and height class rather than dead loader padding or photometric intensity.
- Earlier docs and generated variable names called the byte at record file offset `+0x06` a name length. IDA render evidence shows that file byte is copied into in-memory `+0x05` and used as the layer/tile-id count, not as a wide-name character count.
- The `cacheChain` field is cleared and released by the destructor before the main entry is freed.
- Rejected historical/generated labels: `lightIntensity` is superseded for `+0x00` because independent create/update callers pass the value as a signed LightObjImageLib/table row and `-1` means absence, not luminous strength; `objectId` is also rejected because the table index/caller-supplied `staticObjectId` is the object id. `paletteGroup` is not the best current name for `+0x04` because exact consumers use it as a tile-height multiplier, and `nameLength` is rejected for the layer-count byte.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x004dcf60` confirms the constructor reads four signed light/id-like bytes, one light-height/class byte, one unused/class byte, and one layer-count byte from `SOBJ.TBL`; allocates each record as `2 * layerCount + 0x0c`; copies the inline `uint16` tile-id list at `+0x0c`; stores the field now resolved as `lightImageIndex` at `+0x00`, `lightHeightClass` at `+0x04`, `layerCount` at `+0x05`, clears `+0x06`, and clears `cacheChain` at `+0x08`.
- 2026-05-31 IDA MCP decompilation of `0x004dd2c0` confirms the renderer loads the record pointer from `this+0x0c`, reads byte `+0x05` as the layer count, starts at `entry + 0x0c + 2 * (layerCount - 1)`, and walks the tile ids backward while drawing stacked layers.
- 2026-05-31 IDA MCP decompilation of `0x004dd850` confirms bounds calculation uses byte `+0x05` as the layer count to derive vertical extent.
- 2026-05-31 IDA MCP decompilation of `0x004dd1e0` confirms destructor cleanup uses `+0x08` as a linked cache-chain pointer before freeing the main entry table.
- 2026-06-11 A006 IDA MCP recheck reconfirmed `0x004dcf60` as a `0x278`-byte constructor, `0x004dd1e0` as a `0xde`-byte ordinary destructor, `0x004dd2c0` as a `0x58a`-byte renderer, and `0x004dd850` as a `0x51`-byte bounds helper. The constructor reads four bytes, one byte, one discarded byte, and one layer-count byte from `SOBJ.TBL`, allocates `0x0c + 2 * layerCount`, copies tile ids to `+0x0c`, stores fields at `+0x00/+0x04/+0x05`, zeroes `+0x06`, and zeroes `+0x08`.
- 2026-06-11 A006 IDA MCP decompilation of `0x00530d00` confirms an ObjectList removal/relight path calls the StaticObjImageLib lookup helper, tests entry `+0x00` as signed metadata, and reads byte `+0x04` when computing the replacement object's vertical tile-height offset. Later UID00023D and UID0003TI reanalysis proves the signed value is an image-table index, not intensity.
- 2026-08-11 UID00023D cross-consumer closure accepts `lightImageIndex`, `lightHeightClass`, `layerCount`, `reserved`, `cacheChain`, and `tileIds` as the best current source-facing names. `ObjectList::RefreshStaticObjectLighting`, `MapPane::CreateStaticObjectPaneForTile`, the `LightingObjectPane` constructor, and `SetLightImageIndex` all use `+0x00` as the same signed image-row selector. The names remain descriptive inferences rather than proven original spellings, but they are stronger than `lightIntensity`, `auxiliaryObjectOrLightId`, and `paletteGroupOrHeightClass` and support exact first-draft C++.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). This struct is `90/94`, the direct class parent is `92/96`, and file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) is `90/94`. The relationship is direct: `StaticObjEntry` is allocated, populated, owned, rendered, bounded, consumed by ObjectList/MapPane lighting, and destroyed by StaticObjImageLib. Its declaration remains blank here because the complete packed definition belongs once in the class H.

## Score Rationale

- `COMPLETION:90`: the page records fixed and variable fields, allocation formula, `SOBJ.TBL` read order, constructor stores, renderer reverse tile walk, bounds use, destructor chain cleanup, both independent lighting consumers, exact signed index/height arithmetic, owner/declaration route, and historical corrections.
- `CONFIDENCE:94`: constructor, renderer, bounds helper, destructor, ObjectList refresh, MapPane creation, LightingObjectPane constructor/setter, packed minimum size, and class-H ownership agree on offsets, signedness, semantics, and source placement. Confidence stays below final-audit levels because original spellings and the discarded file byte's resource-level meaning remain provisional.

## Historical Superseded Terminology

- `lightIntensity` is retained only as the rejected earlier name for `+0x00`. Independent create/update paths pass the signed value unchanged to `LightingObjectPane` construction and `SetLightImageIndex`; negative means no light image. Active source/type documentation therefore uses `lightImageIndex` consistently.
- `objectId`, `paletteGroup`, and `nameLength` remain rejected historical/generated labels for the reasons recorded in Notes; none belongs in the active class H declaration.

## Cross-References

- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)

## Changes

- 2026-08-11 B005 UID000184 lifecycle/type synchronization: preserved B003's `90` completion and `lightImageIndex` correction, raised confidence `92` to `94`, preserved owner/emitter UID0000E2 and blank child formal channels, and added exact 2-byte packing, `0x0e` minimum size, variable-tail allocation, one-declaration class-H ownership, and explicit historical terminology separation.

- 2026-08-11 B003 UID00023D cross-consumer implementation: raised `85/88` to `90/92`, preserved owner/emitter UID0000E2, reconstructable true, blank position, and blank CPP/H on this child. Renamed current field semantics from `lightIntensity` to `lightImageIndex`, strengthened exact `lightHeightClass` arithmetic, and retained intensity as rejected historical terminology. The complete declaration is emitted only by the parent StaticObjImageLib H channel.

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:76`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, renderer, bounds, and destructor use of the fields. The score stayed below final-source level because final original field names and the exact meaning of the secondary source-table byte remained partly open.
- 2026-06-11 A006 Batch153: Raised `76/86` to `85/88` and set `AUTOGEN_PARENT_UID:0000E2`.
  - Evidence: live IDA MCP rechecked constructor, destructor, renderer, bounds, and ObjectList relight consumer evidence. The pass corrected the `+0x06` description to an in-memory zeroed reserved word rather than a preserved source byte, added the `+0x00/+0x04` consumer evidence, and confirmed the strict child/direct-parent gate through [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) at `86/85` and [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) at `86/85`.
- 2026-06-21 B007 Rule 26 incorporation:
  - Scores unchanged at `85/88`.
  - Historical evidence: that pass accepted `lightIntensity`, `lightHeightClass`, `layerCount`, `reserved`, `cacheChain`, and `tileIds` over earlier fallback labels. UID00023D later supersedes only `lightIntensity` with the cross-consumer `lightImageIndex` proof while preserving this evidence trail.
