*** UID:0001VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MyItemListPane Entry Layouts

## Status

- Confidence: medium.
- Evidence basis: active `class_MyItemListPane.cpp` constructor, IDA decompilation of `0x004aec90`, and local stack payload copies.

## Inventory Slot Record

The constructor reads player inventory slot records through `GetInventorySlotAddress(playerData, slotIndex)`.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint8` | Active/non-empty flag. |
| `+0x02` | `uint16` | Item id used by row drawing. |
| `+0x04` | `uint8` | Category/style byte passed to the item icon draw path. |
| `+0x06` | `wchar_t[259]` | Item display text copied into the list row payload. |

## List Row Payload

The constructor builds a packed stack payload before calling the list append helper.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint8` | Source inventory slot index. |
| `+0x02` | `uint16` | Item id. |
| `+0x04` | `uint8` | Category/style byte. |
| `+0x06` | `wchar_t[259]` | Inline item display text. |

The unused/padding bytes at `+0x01` and `+0x05` are not initialized in the active generated constructor, so they should not be assigned semantics yet.

## Draw Entry Payload

The virtual draw method consumes an entry pointer with this effective layout:

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint8[2]` | Prefix bytes; slot index and/or padding depending on construction path. |
| `+0x02` | `uint16` | Item icon id. |
| `+0x04` | `uint8` | Icon category/style state. |
| `+0x05` | `uint8` | Unknown/padding. |
| `+0x06` | `wchar_t[]` | Inline wide item text. |

IDA MCP confirms `DrawListEntry` sends `+0x02` and `+0x04` into the item-icon path through [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), then copies and truncates the `+0x06` wide text before drawing it.

## IDA Verification Notes

- 2026-05-31 IDA MCP `lookup_funcs` verifies exact relevant ranges: [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md), [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md), and [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md).
- Constructor decompilation reads one-based inventory slots through `0x005a3870`, tests slot `+0x00`, copies `slotIndex` to payload `+0x00`, item id from slot `+0x02` to payload `+0x02`, style/category byte from slot `+0x04` to payload `+0x04`, and wide text from slot `+0x06` to payload `+0x06`.
- The selected-slot helper at `0x004aec80` resolves the row payload through the selected index at `this +0x134` and returns payload byte `+0x00`, confirming the payload prefix is an inventory slot id.
- Draw method decompilation reads payload `+0x02` for item id, payload `+0x04` for icon category/style, and payload `+0x06` for wide text in both rendering-mode branches.
- Scores stay below `95` because final original names for the player inventory slot type, row payload type, and `ListPane` selected-row API remain inferred.

## Caveats

- The slot-count source in active output is named as an `EffectObjImageLib` field, but IDA decompilation reads [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) / `dword_69AE0C + 0x284`. This is generated global-owner pollution; the layout above only documents the row and slot data used by `MyItemListPane`.
- Recheck against reviewed player/inventory globals before converting this into a final C++ struct.

## Cross-References

- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md)
- [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md)
- [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `82`, confidence `88`.
- Summary/evidence: IDA MCP on 2026-05-31 verified constructor payload writes, selected-slot helper reads, draw-method payload reads, and exact child function boundaries. Scores remain below `95` because original type/API names and full player inventory structure ownership are not yet final.
