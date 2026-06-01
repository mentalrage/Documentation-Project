*** UID:0000UQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GetItemGlyphBounds 0x004DF460

## Status

- Confidence: strong for behavior and current canonical name, medium for final source-file placement.
- Entity kind: shared global helper.
- Likely source module: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) or a small item-image helper module.
- Exact range: `0x004df460-0x004df4f9`

## Behavior

`GetItemGlyphBounds` resolves an item sprite rectangle for icon/list rendering. It starts from `itemId + 0x4000`, applies the legacy non-EPF remap policy when extended item archives are disabled, asks [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) for the frame rectangle from `ITEM.EPF` or `ITEM.EPD`, then offsets the rectangle by half of the configured [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md).

Callers usually pair this helper with the item-image singleton [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) before invoking `ItemObjImageLib::DrawItemImage` or `DrawItemImageScaled`.

The non-EPF remap policy is:

- if the computed entry is inside the translated band, use `itemId + 16211`;
- if it is above the configured archive floor, clamp to entry `2418`;
- otherwise use the original `itemId + 0x4000` entry.

## Evidence

- IDA MCP on 2026-05-30 reports `sub_4DF460` as `0x004df460-0x004df4f9`, size `153`.
- IDA xrefs show 48 code refs across item-list, look-pane, menu, inventory, and item-preview paths, supporting free-helper ownership rather than a pane-specific method.
- Hex-Rays shows signature shape `int __stdcall sub_4DF460(__int16 itemId, RectBounds *outRect)`, base entry `itemId + 0x4000`, `byte_66DA97` mode selection, translated-band remap to `itemId + 16211`, fallback clamp to entry `2418`, `ITEM.EPF` vs `ITEM.EPD` layout lookup, and final center offset.
- The helper calls [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) entry lookup at `0x004df4cb -> 0x004d0530` and rectangle offset at `0x004df4eb -> 0x004b7e10`.
- The final centering reads [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) as `word_66DA9C / 2` and `word_66DAA0 / 2`.

## Ownership Decision

Keep this as a free helper, not a UI-pane method. Its caller spread is broad and item-render focused. The most likely original placement is near `ItemObjImageLib` or a local item-image helper source file that also had access to the item archive selection globals.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, cited generated metadata, and used an older exact range spelling.
- Changed to: `COMPLETION:82` and `CONFIDENCE:88`, IDA-backed function bounds and caller count, and current Hex-Rays behavior for remapping, lookup, and centering.
- Summary/evidence: IDA MCP on 2026-05-30 confirms `0x004df460-0x004df4f9`, 48 code xrefs, calls to `0x004d0530` and `0x004b7e10`, and the `ITEM.EPF`/`ITEM.EPD` mode branch.
