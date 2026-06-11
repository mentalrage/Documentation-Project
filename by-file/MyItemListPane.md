*** UID:0000LO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MyItemListPane

## Status

- Confidence: strong for behavior and direct file placement.
- Proposed module: `ui/dialogs/MyItemListPane.cpp`
- Alternative compact placement: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_MyItemListPane.cpp`
- Main inventory range: [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- Vtables: [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md) at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`

## File Role

`MyItemListPane` is the reusable player-inventory item picker list used by item-add, mix, and clan-deposit flows. It derives from [UID:0000KT][ListPane](by-file/ListPane.md), populates rows from the local player's item slots, and draws each row with an item icon, selected-row background, and truncated item name.

This is item-picker UI, not the generic list control itself. Keep it adjacent to `ItemDialogs.cpp`/`MixItemDialog.cpp`, and cross-reference clan-bank deposit usage rather than moving the class into clan ownership.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `MyItemListPane::MyItemListPane` | `0x004aeb30-0x004aec77` | [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md) constructs the list pane, chooses layout width from high-res mode, enumerates player item slots, and appends active slots as row payloads. |
| `MyItemListPane::GetSelectedSlotIndex` | `0x004aec80-0x004aec8e` | [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md) selected-row helper used by item dialog action paths. |
| `MyItemListPane::DrawListEntry` | `0x004aec90-0x004af031` | [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md) virtual row renderer; draws selected background, item icon, and truncated item text. |
| shared list-pane scalar deleting destructor | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Vtable slot target shared with exchange/list-pane relatives; not exclusive to this file. |
| row payload layouts | local stack and draw payload structures | See [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md). |

## Caller Evidence

IDA MCP reports constructor callers at:

- `0x0048a50d` inside `ClanDepItemDialog`
- `0x004ae63e` and `0x004ae7f0` inside `AddItemDialog`
- `0x004af7a7` inside `MixItemDialog`

The draw method has no direct callers because it is reached through the list-pane vtable.

## Draw Path Details

IDA MCP on 2026-05-25 confirms `DrawListEntry` calls the list selection helper, GrafPort/text state helpers, `GetItemGlyphBounds`, and the shared item image library through [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md).

The draw path branches on `g_useEpfAssets`:

- extended/EPF mode computes a clipped half-size destination and calls `ItemObjImageLib::DrawItemImageScaled` at `0x004df2c0`;
- legacy mode computes the normal icon destination and calls `ItemObjImageLib::DrawItemImage` at `0x004dee50`.

After icon drawing, it copies the row text from payload offset `+0x06`, truncates it with the shared text fitting helper at `0x004ba820`, moves the draw cursor through `0x004b9600`, and emits the final wide text through `0x004bab70`.

## Ownership Decision

Keep this as item-picker dialog support:

- `AddItemDialog` and `MixItemDialog` are the strongest current consumers.
- `ClanDepItemDialog` reuses the same picker to choose a player-owned item for clan-bank deposit, but the class itself remains generic player item selection.
- The class should not be migrated into `ListPane.cpp`; it depends on inventory/player item records, item image rendering, and dialog-specific row sizing.

## Data Caveats

- Active generated output does not emit the body of `DrawListEntry`; it only emits the local struct/global declarations for that method. IDA decompilation confirms a real 0x3a1-byte function. This is part of the shared [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) defect class.
- Current `class_MyItemListPane.meta_wave3` reports `vtable_count: 0`, but IDA confirms three table bases and the `DrawListEntry` slot at primary `+0x80`. Use [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md) until generated metadata is corrected.
- Active generated output names the total slot count as `g_pEffectObjImageLib + 644`, but IDA decompilation reads `dword_69AE0C + 0x284`. Current docs track that storage as [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) / [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md). Treat the field as the local inventory slot count on the active user/status pane object until final naming review.

## Cross-References

- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md)
- [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md)
- [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md)
- [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Score Rationale

The file is now `86/85`. The direct file placement is defensible because IDA confirms this is reusable player-inventory picker UI with constructor callers from `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`, not a clan-only or exchange-only implementation. The exact child pages now document constructor, selected-slot helper, and draw method boundaries at or above the strict `85/85` child gate, while the file remains below final-source quality because the final source split between standalone `MyItemListPane.cpp` and compact `ItemDialogs.cpp` is inferred from proposed project structure and consumer clustering rather than original source files.

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents role, constructor/draw behavior, caller evidence, EPF/legacy draw paths, ownership decision, generated-data defects, vtable caveats, and cross-references; confidence remains capped by the original source split and active generated output omissions.
- Reconstruction path update: existed before as blank `PROPOSED_RECONSTRUCTION_PATH`; changed to `NexusTK/ui/dialogs/`. Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `ui/dialogs/MyItemListPane.cpp`, and the file is documented as reusable item-picker dialog support adjacent to `ItemDialogs.cpp`.
- Exact child split update: added child links for constructor, selected-slot helper, and draw method after 2026-05-31 IDA MCP found the real helper at `0x004aec80` inside the previous constructor-to-draw gap.
- 2026-06-10 B001-026 parent-gate repair:
  - Before: file confidence was `80`, so assigned reconstructable children inside [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md) were below the strict direct-parent `85/85` gate.
  - After: confidence is `85`; the direct parent now clears the gate for the exact constructor, selected-slot, and draw child pages.
  - Evidence: IDA confirms the child boundaries, vtables, draw-slot dispatch, row payload layout, caller fanout from AddItem/Mix/Clan deposit dialogs, and item-image draw dependencies. The remaining uncertainty affects final C++ naming, not ownership.
