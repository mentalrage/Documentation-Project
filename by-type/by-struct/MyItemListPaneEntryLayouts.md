*** UID:0001VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MyItemListEntry
{
    unsigned char slotIndex;
    unsigned short itemId;
    unsigned char iconStyle;
    wchar_t displayName[256];
    unsigned char reservedTail[6];
};

typedef char MyItemListEntrySizeMustBe524[
    sizeof(MyItemListEntry) == 0x20c ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MyItemListPane Entry Layouts

## UID0000LO Accepted Header Layout - 2026-08-14

`MyItemListEntry` is an H-only declaration emitted before the
`MyItemListPane` class through UID00008W. The used layout is slot byte `+0x00`,
natural padding `+0x01`, item id `+0x02`, icon style `+0x04`, natural padding
`+0x05`, exactly 256 wide characters at `+0x06`, and an opaque six-byte tail
at `+0x206`, for total size `0x20c`. The tail is required by constructor copy
size and ListPane entry stride but has no recovered semantic field; the size
guard is therefore authoritative while the tail remains deliberately opaque.

The prior CPP declaration and `wchar_t[259]` interpretation below are
historical. The accepted current formal channel is H, matching constructor,
accessor, and renderer use in ItemDialogs.

## Status

- Confidence: strong for observed inventory-slot and row-payload offsets; medium for final source-facing names of the active user/status inventory record and `ListPane` row API.
- Owner/emitter: attached to [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), which currently clears the strict parent gate at `85/86`.
- Evidence basis: live IDA decompilation of `0x004aeb30`, `0x004aec80`, and `0x004aec90`, exact xrefs, and current IDA DB names applied by C001 on 2026-06-16.
- B004 UID0002JQ callback source-facing name: use the existing emitted `MyItemListEntry` declaration for the constructor-built row payload consumed by `MyItemListPane::DrawListEntry`. The accepted report's `MyItemListPaneEntry` spelling is normalized to this support-doc name so the constructor and draw method share one row type.
- B004 UID0002JP callback source-facing use: `MyItemListPane::GetSelectedSlotIndex()` now emits formal C++ that obtains a `MyItemListEntry *` from the selected row and returns `entry->slotIndex`, confirming byte `+0x00` is the selected inventory-slot field in the shared row payload.
- C++ status: emits the `MyItemListEntry` row payload declaration needed by [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md). The broader `LocalInventorySlotRecord` remains owned by the inventory accessor/support path.

## Inventory Slot Record

The constructor reads local-player inventory slot records through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). B006 resolves that accessor as `this + 0x133f08 + slot * 0x1fc`, returning a `LocalInventorySlotRecord *`.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint8` | Active/non-empty flag. |
| `+0x02` | `uint16` | Item id used by row drawing. |
| `+0x04` | `uint8` | Category/style byte passed to the item icon draw path. |
| `+0x06` | `wchar_t[]` | Item display text copied into the list row payload; if a concrete partial slot-record declaration is needed, the maximum contiguous bound before the confirmed `+0x1e8` field is `wchar_t[241]`. |
| `+0x1e8` | `uint32` | Quantity/count payload used by employee and mix dialog paths. |
| `+0x1ec` | `uint8` | Quantity-prompt / stack-like flag used before opening quantity dialogs. |
| `+0x1f8` | `uint8` | Item-use target mode consumed by [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md). |

The older `wchar_t[259]` figure belongs to the stack/list-row payload used by this pane, not to the returned `LocalInventorySlotRecord`. It cannot be the slot-record field bound because the same `0x1fc` stride has confirmed later fields at `+0x1e8`, `+0x1ec`, and `+0x1f8`.

## List Row Payload

The constructor builds a packed stack payload before calling the list append helper.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint8` | Source inventory slot index. |
| `+0x02` | `uint16` | Item id. |
| `+0x04` | `uint8` | Category/style byte. |
| `+0x06` | `wchar_t[259]` | Inline item display text. |

The full row payload size is `0x20c` bytes, matching `sizeof(MyItemListEntry)` in the UID0002JO constructor's `ListPane` base call. The unused/padding bytes at `+0x01` and `+0x05` are not initialized in the active constructor, so they remain reserved padding and must not be assigned semantics yet.

Live IDA decompilation on 2026-06-16 still shows the constructor stack layout as `slotIndex` byte, one padding byte, `uint16_t itemId`, `uint8_t category/style`, one padding byte, then `wchar_t Destination[259]`. The append call passes the stack payload start, so the source-facing row payload should preserve those padding bytes unless a later `ListPane` ABI pass proves a packed declaration.

B003's 2026-07-02 callback preserves the constructor's explicit `_wcscpy_s(entry.displayName, 0x100, slot->displayName)` count. The row field is modeled as `wchar_t[259]`, but the constructor uses `0x100` as the checked-copy count and that smaller literal is behaviorally significant.

## Draw Entry Payload

The virtual draw method consumes an entry pointer with this effective layout. B004 UID0002JQ incorporation uses the existing source-facing type name `MyItemListEntry` for this same constructor-built row payload:

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint8[2]` | Prefix bytes; slot index and/or padding depending on construction path. |
| `+0x02` | `uint16` | Item icon id. |
| `+0x04` | `uint8` | Icon category/style state. |
| `+0x05` | `uint8` | Unknown/padding. |
| `+0x06` | `wchar_t[]` | Inline wide item text. |

IDA MCP confirms `DrawListEntry` sends `+0x02` and `+0x04` into the item-icon path through [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), then copies and truncates the `+0x06` wide text before drawing it.

Current emitted first-draft declaration for the row payload:

```cpp
struct MyItemListEntry
{
    unsigned char slotIndex;
    unsigned char reserved1;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved5;
    wchar_t displayName[259];
};
```

UID0002JQ now consumes this declaration shape in formal first-draft C++ as `DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)`. The renderer reads `entry->itemId`, `entry->iconStyle`, and `entry->displayName`; the `slotIndex` byte remains part of the shared row payload because the constructor writes it and UID0002JP now emits formal first-draft C++ returning `entry->slotIndex`.

## IDA Verification Notes

- 2026-05-31 IDA MCP `lookup_funcs` verifies exact relevant ranges: [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md), [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md), and [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md).
- 2026-06-16 C001 live IDA refresh reconfirmed the same method sizes and xrefs after the parent pages had cleared the strict gate: constructor callers at `0x0048a50d`, `0x004ae63e`, `0x004ae7f0`, and `0x004af7a7`; selected-slot helper callers at `0x0048a733` and `0x0048b6ae`; and the draw method's vtable-only data xref at `0x00619fa8`.
- C001 applied and saved current IDA names `MyItemListPane_Constructor`, `MyItemListPane_GetSelectedSlotIndex`, and `MyItemListPane_DrawListEntry`.
- Constructor decompilation reads one-based inventory slots through `0x005a3870`, tests slot `+0x00`, copies `slotIndex` to payload `+0x00`, item id from slot `+0x02` to payload `+0x02`, style/category byte from slot `+0x04` to payload `+0x04`, and wide text from slot `+0x06` to payload `+0x06`.
- The selected-slot helper at `0x004aec80` resolves the row payload through the selected index at `this +0x134` and returns payload byte `+0x00`, confirming the payload prefix is an inventory slot id.
- Draw method decompilation reads payload `+0x02` for item id, payload `+0x04` for icon category/style, and payload `+0x06` for wide text in both rendering-mode branches.
- Scores stay below `95` because final original names for the player inventory slot type, row payload type, and `ListPane` selected-row API remain inferred.
- 2026-07-02 B004 UID0002JQ live MCP reconfirmed the draw consumer: `sub_4AEC90` reads payload `+0x02`, `+0x04`, and `+0x06` in both EPF and legacy branches, and the inherited ListPane row-draw callback passes `(rowIndex, itemPayload, rowBounds)`.
- 2026-07-02 B003 rechecked UID0002JO against active IDA MCP and incorporated the accepted report detail that `0x20c` is the row payload size, not a geometry value; `205/170` is a ListPane mode-dependent extent; and row padding bytes are left uninitialized by the constructor.
- 2026-07-05 B004 UID0002JP current MCP reconfirmed `sub_4AEC80` as a 14-byte selected-slot accessor: it supplies inherited selected index `this+0x134` to ListPane helper `0x004f3dc0`, reads row payload byte `+0x00`, returns it without local null/range guards, and has direct ClanDep/ClanBank callers plus AddItem inline-equivalent support. This is the formal source-facing consumer for `MyItemListEntry::slotIndex`.

## Caveats

- The slot-count source in active output is named as an `EffectObjImageLib` field, but IDA decompilation reads [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) / `dword_69AE0C + 0x284`. This is generated global-owner pollution; the layout above only documents the row and slot data used by `MyItemListPane`.
- The emitted `MyItemListEntry` declaration is a first-draft source support type for the MyItemListPane row payload. Exact original type spelling remains inferred.
- Do not confuse `MyItemListEntry` with `LocalInventorySlotRecord`. The constructor copies from the inventory slot record returned by UID0003U9 into the row payload appended to ListPane.
- IDA DB type/member edits were skipped. The byte offsets are strong, but broader active user/status object field ownership and exact original `ListPane` row API names remain below final-source proof.

## Cross-References

- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md)
- [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md)
- [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Split the returned `LocalInventorySlotRecord` model from the MyItemListPane stack/list-row payload.
  - Kept row payload `wchar_t[259]` as the constructor-local payload copy, but removed it as slot-record truth and added confirmed slot-record fields `quantityOrCount`, `quantityPromptFlag`, and `targetMode`.
- 2026-06-06: Attached the entry layouts to [UID:00008W][MyItemListPane](by-class/MyItemListPane.md). Scores remain `82/88`; the layouts document class-local inventory slot and list-row payloads used by this pane.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `82`, confidence `88`.
- Summary/evidence: IDA MCP on 2026-05-31 verified constructor payload writes, selected-slot helper reads, draw-method payload reads, and exact child function boundaries. Scores remain below `95` because original type/API names and full player inventory structure ownership are not yet final.
- 2026-06-16 C001 type-layout refresh:
  - Before: `82/88`, with the row offsets documented but stale parent-gate wording and no current IDA DB name evidence.
  - After: `85/90`, preserving owner/emitter route through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) and final C++ blank.
  - Evidence: live IDA reconfirmed constructor, selected-slot, and draw method sizes/xrefs; constructor stack writes to payload `+0x00/+0x02/+0x04/+0x06`; selected helper returning payload `+0x00`; draw reads at `+0x02/+0x04/+0x06`; and C001 saved the three method names in IDA. Remaining blockers are source-facing inventory/status object names and the `ListPane` row payload declaration, not offset confidence.
- 2026-07-02 B004 UID0002JQ implementation callback:
  - Score unchanged at `85/90`; the accepted callback records the existing `MyItemListEntry` declaration as the preferred source-facing row payload name for UID0002JQ without claiming final player inventory/status object names.
  - Evidence: UID0002JQ now emits `DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)` and consumes `itemId`, `iconStyle`, and `displayName`; the slot byte remains in the declaration because UID0002JO writes it and UID0002JP reads it.
- 2026-07-02 B003 UID0002JO implementation callback:
  - Added first-draft `MyItemListEntry` formal C++ declaration for the row payload consumed by UID0002JO and set `EMITTER_POSITION_OPTIONAL:0` so the declaration emits before the constructor body.
  - Confirmed row payload size `0x20c`, explicit constructor copy count `0x100`, and uninitialized padding bytes at `+0x01` and `+0x05`.
  - Preserved the LocalInventorySlotRecord versus MyItemListEntry distinction: UID0003U9 returns the slot record; UID0002JO copies selected fields into this ListPane row payload.
- 2026-07-05 B004 UID0002JP implementation callback:
  - Score unchanged at `85/90`; no layout metadata or emitted declaration change was needed.
  - Added source-facing support that UID0002JP now emits `MyItemListPane::GetSelectedSlotIndex()` using `MyItemListEntry *entry = static_cast<MyItemListEntry *>(GetSelectedItem()); return entry->slotIndex;`.
  - Evidence: current MCP exact bytes, `0x004f3dc0` selected-row lowering, no local guards, direct ClanDep/ClanBank callers, and AddItem inline-equivalent context confirm `+0x00` as the selected inventory-slot field.
