*** UID:0000LO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MyItemListPane

## UID0000LO Accepted Fold Integration - 2026-08-14

UID0000LO is a retired standalone source-root and historical split alias. The
source-authored class and its three methods are now placed in
[UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), in binary/source order
between AddItemDialog and AddItemWithCountDialog. There is no separate
`NexusTK/ui/dialogs/MyItemListPane.cpp` reconstruction route; any prior
standalone generated file is stale and must disappear after validator refresh.

The complete source-bearing inventory is the H-only
[UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md),
the H/CPP class route [UID:00008W][MyItemListPane](by-class/MyItemListPane.md),
and the ordered CPP children [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md),
[UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md),
and [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md).
[UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
and [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md)
remain non-emitting indexes.

Compiler-only material remains outside handwritten source: constructor EH
unwind chunks/objects, three vptr stores, primary/secondary/tertiary vtables
and RTTI locators, shared scalar deleting destructor `0x0047ea50`, adjustor
thunks `0x0047e8ad` and `0x0047e8b8`, inter-function padding, and literal/global
storage. Runtime dependencies remain references only: `g_useEpfAssets`,
`g_activeUserStatusPane`, `g_pUserPane`, `g_pItemObjImageLib`,
`g_pfnFillRect`, the EPF tile context, text helpers, and ListPane methods.

This accepted fold supersedes the historical standalone/fold ambiguity below.
No source/PDB filename, local static anchor, class-specific destructor, extra
derived field, or additional source-authored method was found; those negatives
remain confidence limits rather than deferred work.

### Accepted Complete Address And Artifact Inventory

| Kind | Exact item/range | Disposition |
| --- | --- | --- |
| source function | `0x004aeb30-0x004aec77`, `0x147`, 100 instructions, 10 blocks | constructor child UID0002JO |
| padding | `0x004aec77-0x004aec80`, nine `0xcc` bytes | alignment; preserve, no source |
| source function | `0x004aec80-0x004aec8e`, `0x0e`, four instructions | selected-slot child UID0002JP |
| padding | `0x004aec8e-0x004aec90`, two `0xcc` bytes | alignment; preserve, no source |
| source function | `0x004aec90-0x004af031`, `0x3a1`, 270 instructions, 14 blocks | draw child UID0002JQ |
| padding | `0x004af031-0x004af040`, fifteen `0xcc` bytes | alignment before AddItemWithCountDialog |
| successor | `0x004af040-0x004af371`, `0x331` | existing AddItemWithCountDialog constructor, not MyItem-owned |
| EH cleanup | `0x005fe4d6-0x005fe4e1` | compiler ListPane cleanup chunk |
| EH handler | `0x005fe4e1-0x005fe509` | compiler `SEH_4AEB30` frame handler |
| unwind map | `0x0065c658-0x0065c660` | compiler object `stru_65C658` |
| FuncInfo | `0x0065c800-0x0065c824` | compiler object `stru_65C800` |
| primary vtable | `0x00619f28-0x00619fac`, `0x84` bytes/33 slots | compiler-only |
| secondary vtable | `0x00619fb0-0x00619fdc`, `0x2c` bytes/11 slots | compiler-only |
| tertiary vtable | `0x00619fe0-0x00619fe8`, eight bytes/two slots | compiler-only |
| RTTI primary COL | `0x00647354-0x00647368` | `??_R4MyItemListPane@@6B@` |
| RTTI CHD | `0x00647368-0x00647378` | `??_R3MyItemListPane@@8` |
| RTTI base array | `0x00647378-0x0064739c` | `??_R2MyItemListPane@@8` |
| RTTI self BCD | `0x0064739c-0x006473b8` | `??_R1A@?0A@EA@MyItemListPane@@8` |
| RTTI secondary COL | `0x006473b8-0x006473cc` | `??_R4MyItemListPane@@6B@_0` |
| RTTI tertiary COL | `0x006473cc-0x006473e0` | `??_R4MyItemListPane@@6B@_1` |
| type descriptor | `0x00675ff0-0x00676010` | `??_R0?AVMyItemListPane@@@8` |
| deleting destructor | `0x0047ea50-0x0047ea8b` | shared ListPane scalar deleting destructor |
| adjustor thunk | `0x0047e8ad-0x0047e8b8` | subtract `0xa0`, jump to shared destructor |
| adjustor thunk | `0x0047e8b8-0x0047e8c3` | subtract `0xa4`, jump to shared destructor |
| pooled literal | `0x0061066c-0x00610674` | UTF-16 ellipsis, 23 xrefs; no target ownership |

### Accepted Direct Xref Inventory

| Source/reference | Destination/action |
| --- | --- |
| `0x0048a50d` in `sub_48A1C0` | constructs MyItemListPane |
| `0x004ae63e` | AddItemDialog branch-one constructor call |
| `0x004ae7f0` | AddItemDialog branch-two constructor call |
| `0x004af7a7` in `MixItemDialog_MixItemDialog` | constructor call |
| `0x0048a733` in `sub_48A6B0` | calls selected-slot accessor |
| `0x0048b6ae` in `sub_48B630` | calls selected-slot accessor |
| `0x00619fa8` | sole draw-method data xref; no direct code caller |
| `0x004aeb9a` | stores primary vtable `0x00619f28` |
| `0x004aeba5` | stores secondary vtable `0x00619fb0` at `this+0xa0` |
| `0x004aebb1` | stores tertiary vtable `0x00619fe0` at `this+0xa4` |
| `0x00619f24` | binds primary table to COL `0x00647354` |
| `0x00619fac` | binds secondary table to COL `0x006473b8` |
| `0x00619fdc` | binds tertiary table to COL `0x006473cc` |
| `0x00647360` | primary COL reference to type descriptor |
| `0x0064739c` | self BCD reference to type descriptor |
| `0x006473c4` | secondary COL reference to type descriptor |
| `0x006473d8` | tertiary COL reference to type descriptor |
| `0x004aee2f` | EPF branch ellipsis reference |
| `0x004aefc6` | legacy branch ellipsis reference |

### Accepted Callee And External Dependency Inventory

| Child | Exact callee/dependency | Source disposition |
| --- | --- | --- |
| constructor | `0x004f3a50` ListPane constructor | resolved base constructor route |
| constructor | `0x005a3870` UserPane inventory-slot accessor | external member call |
| constructor | `0x005cd657` `_wcscpy_s` | bounded copy retained |
| constructor | `0x004f3c50` ListPane AddEntry | member call retained |
| constructor cleanup | `0x004f3b60` ListPane destructor | compiler EH cleanup only |
| constructor | `0x005c772f` security-cookie helper | compiler-only |
| constructor handler | `0x005c956c` `___CxxFrameHandler3` | compiler-only |
| accessor | `0x004f3dc0` ListPane GetItem | call with `m_selectedIndex` |
| draw | `0x00457a60` EPFTileContext Initialize | retained in both branches |
| draw | `0x004f3f00` ListPane IsItemSelected | retained selection query |
| draw | `0x004b9660` SetDrawColor | retained |
| draw | `0x004b9680` SetTextColor | retained |
| draw | `0x004df460` ItemObjImageLib GetItemGlyphBounds | member call/declaration |
| draw | `0x004b7cc0` IntersectRects | EPF clipping retained |
| draw | `0x004df2c0` DrawItemImageScaled | EPF image path |
| draw | `0x004b9690` SetTextBackColor | retained |
| draw | `0x005cd657` `_wcscpy_s` | retained in both branches |
| draw | `0x004ba820` FitTextAndAppendSuffix | 256-character fit and ellipsis |
| draw | `0x004b9600` MoveTo | x=50/text baseline retained |
| draw | `0x004dee50` DrawItemImage | legacy image path |
| draw | `0x004bab70` DrawWideText | final text draw |
| draw | `0x005c772f` security-cookie helper | compiler-only |

The external globals remain owned by their existing pages:
`g_activeUserStatusPane` supplies the slot count, `g_useEpfAssets` is compared
with literal one, `g_pUserPane` supplies slot records,
`g_pItemObjImageLib` supplies glyph/image members, and callback
`g_pfnFillRect` at `0x0069b3fc` fills selected rows. Their dedicated pages now
carry target consumer links without owner/emitter/score changes.

## Status

- Confidence: strong for behavior, direct file placement, vtable routing, and current generated-body coverage; medium-high for the final standalone-versus-folded source split.
- Proposed module: `ui/dialogs/MyItemListPane.cpp`
- Alternative compact placement: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_MyItemListPane.cpp`
- Main inventory range: [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- Vtables: [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md) at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`
- 2026-07-02 B003 note: UID0002JO is first-draft C++ ready and now routes through class [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), while the source file placement remains `NexusTK/ui/dialogs/MyItemListPane.cpp`.
- 2026-07-02 B004 note: UID0002JQ is now `88/90`, class-owned/class-emitted through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), and carries first-draft `DrawListEntry` C++. This file remains the source root for the generated `NexusTK/ui/dialogs/MyItemListPane.cpp` route.
- 2026-07-05 B004 note: UID0002JP is now `88/92`, class-owned/class-emitted through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), and carries first-draft `GetSelectedSlotIndex` C++. This file remains the source root for generated `NexusTK/ui/dialogs/MyItemListPane.cpp`; exact original source split versus compact `ItemDialogs.cpp` remains a confidence cap, not a code blocker.

## File Role

`MyItemListPane` is the reusable player-inventory item picker list used by item-add, mix, and clan-deposit flows. It derives from [UID:0000KT][ListPane](by-file/ListPane.md), populates rows from the local player's item slots, and draws each row with an item icon, selected-row background, and truncated item name.

This is item-picker UI, not the generic list control itself. Keep it adjacent to `ItemDialogs.cpp`/`MixItemDialog.cpp`, and cross-reference clan-bank deposit usage rather than moving the class into clan ownership.

[UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) reaches the dynamic MyItemListPane through selector `3`'s separately allocated ScrollableControlPane and its `GetScrollablePane()` accessor, then invokes inherited [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md). Exact constructor/layout evidence still proves there is no AddItemDialog member pointer for this list.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `MyItemListPane::MyItemListPane` | `0x004aeb30-0x004aec77` | [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md) constructs the list pane, passes `0x20c` row payload size plus mode-dependent `205/170` extent to `ListPane`, enumerates player item slots, and appends active slots as row payloads. |
| `MyItemListPane::GetSelectedSlotIndex` | `0x004aec80-0x004aec8e` | [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md) `88/92` class-owned selected-row helper; resolves the inherited selected row through ListPane `0x004f3dc0`, returns `MyItemListEntry::slotIndex`, and emits first-draft C++ through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md). |
| `MyItemListPane::DrawListEntry` | `0x004aec90-0x004af031` | [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md) `88/90` class-owned virtual row renderer; draws selected background, item icon, and truncated item text with first-draft C++ emitted through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md). |
| inherited `ListPane::GetSelectionCount` | [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md) | Generic ListPane dependency used by UID0004BP through the wrapper; no MyItemListPane override, source ownership, or new field. |
| shared list-pane scalar deleting destructor | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Vtable slot target shared with exchange/list-pane relatives; not exclusive to this file. |
| row payload layouts | local stack and draw payload structures | See [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md). |

## Caller Evidence

IDA MCP reports constructor callers at:

- `0x0048a50d` inside `ClanDepItemDialog`
- `0x004ae63e` and `0x004ae7f0` inside `AddItemDialog`
- `0x004af7a7` inside `MixItemDialog`

The two AddItemDialog construction paths are exact ownership-transfer callers, not evidence for an AddItemDialog member. [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md) allocates a local MyItemListPane in each branch, calls inherited [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md), then transfers the pointer to ScrollableControlPane. EPF passes the constructor byte `allowMultipleSelection`; EPD forces one. No list pointer or byte-mode value is stored in AddItemDialog.

This relationship does not move UID0004LX into this file: the setter has three additional cross-feature callers, operates only on generic ListPane selection storage/bounds, and emits from `NexusTK/ui/controls/ListPane.cpp`. MyItemListPane remains a consumer of inherited behavior.

The same rule applies to UID0004M9. Its 14 cross-feature callers and generic selection fields keep it in `NexusTK/ui/controls/ListPane.cpp`; this file documents only the dynamic receiver reached through ScrollableControlPane.

The selected-slot helper has two direct callers, `0x0048a733` in `ClanDepItemDialog` and `0x0048b6ae` in `ClanBankPane`, both of which validate the selected row index before calling it. The AddItem action path at `0x004ae930` is inline-equivalent rather than a direct caller: it obtains selected rows, resolves each row payload through ListPane `0x004f3dc0`, reads byte `+0x00`, and serializes the same selected-inventory-slot value into packet `0x4A/1`.

The draw method has no direct callers because it is reached through the list-pane vtable.

## Draw Path Details

IDA MCP on 2026-05-25 and the 2026-07-02 B004 callback confirm `DrawListEntry` calls the list selection helper, GrafPort/text state helpers, `GetItemGlyphBounds`, and the shared item image library through [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md). B004 live MCP in `supervisor_resume_20260629` reconfirmed `sub_4AEC90` size `0x3a1`, end boundary `0x004af031` as non-function, the vtable-only data xref at `0x00619fa8`, no direct callers, and the inherited ListPane callback shape `(rowIndex, itemPayload, rowBounds)`.

The draw path consumes `MyItemListEntry`: source slot byte at `+0x00`, item id at `+0x02`, icon style/category at `+0x04`, and inline wide display text at `+0x06`. It branches on `g_useEpfAssets`:

- extended/EPF mode computes a clipped half-size destination and calls `ItemObjImageLib::DrawItemImageScaled` at `0x004df2c0`;
- legacy mode computes the normal icon destination and calls `ItemObjImageLib::DrawItemImage` at `0x004dee50`.

After icon drawing, it sets text mode at `this+0x88`, clears secondary/background text color through `0x004b9690`, copies the row text from payload offset `+0x06` into a 256-wide-char buffer, truncates it with the shared text fitting helper at `0x004ba820` and suffix `L"..."`, moves the draw cursor through `0x004b9600` to `(50, rowCenterY + 6)`, and emits the final wide text through `0x004bab70`.

## Selected-Slot Helper Details

IDA MCP on 2026-07-05 reconfirms [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md) as exact function `sub_4AEC80`, size `0x0e`, with bytes `ff b1 34 01 00 00 e8 35 51 04 00 8a 00 c3`. The body pushes the inherited selected-index field at `this+0x134`, calls ListPane helper `0x004f3dc0`, reads the first payload byte, and returns it. Current ListPane docs already record `0x004f3dc0` as indexed `GetItem` / `GetEntryAt`; UID0002JP is the selected-entry call-site shape because it supplies the selected index.

The source-facing row payload is the emitted [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md) `MyItemListEntry` declaration. UID0002JO writes `entry.slotIndex`, UID0002JP returns `entry->slotIndex`, and UID0002JQ consumes `itemId`, `iconStyle`, and `displayName`. There is no null guard or range guard inside UID0002JP; caller-side selected-index checks are the relevant safety boundary.

## Ownership Decision

Keep this as item-picker dialog support:

- `AddItemDialog` and `MixItemDialog` are the strongest current consumers.
- AddItemDialog's use is borrowed-local construction followed by ownership transfer to ScrollableControlPane. Historical generated `m_itemList = new MyItemListPane(this)` is rejected; exact constructor evidence shows neither a stored list member nor that constructor argument shape.
- `ClanDepItemDialog` reuses the same picker to choose a player-owned item for clan-bank deposit, but the class itself remains generic player item selection.
- The class should not be migrated into `ListPane.cpp`; it depends on inventory/player item records, item image rendering, and dialog-specific row sizing.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed the route:

- `lookup_funcs` reports constructor `0x004aeb30` size `0x147`, selected-slot helper `0x004aec80` size `0x0e`, and `DrawListEntry` `0x004aec90` size `0x3a1`.
- `xrefs_to 0x004aeb30` reports the existing four constructor call sites from `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`; `xrefs_to 0x004aec80` reports direct selected-slot callers at `0x0048a733` and `0x0048b6ae`; `xrefs_to 0x004aec90` remains the primary-vtable data ref at `0x00619fa8`.
- Vtable refs to `0x00619f28`, `0x00619fb0`, and `0x00619fe0` are still constructor stores only, so the class remains a specific list-pane subclass rather than generic `ListPane` code.
- `analyze_function 0x004aec90` reconfirmed the EPF/legacy split through `ItemObjImageLib::DrawItemImageScaled` / `DrawItemImage`, item bounds helper `0x004df460`, shared text fit/draw helpers, and row payload offsets `+0x02`, `+0x04`, and `+0x06`.
- Targeted historical generated-output review found `simroot_v2/ui/dialogs/class_MyItemListPane.cpp` included a scoped `DrawListEntry` body for `0x004aec90`, but the current validator-generated `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` checked by B004 before incorporation still showed UID0002JQ as an empty marker at command `000000004547`. The authoritative source body is now the formal C++ on UID0002JQ; generated output should be refreshed through scoped validators.
- IDA string search finds the RTTI class name but no embedded `MyItemListPane.cpp` source filename, and `search_structs MyItemListPane` returns no local IDA struct/type record.

This raises the file root to `87/86`. The remaining blocker is not behavior or ownership; it is final source placement between standalone `MyItemListPane.cpp` and a compact `ItemDialogs.cpp` fold, plus source-quality row/API and player-inventory field names.

## Data Caveats

- Older simroot output had a provisional scoped `DrawListEntry` body for `0x004aec90`, but validator-generated output is a refresh product only; IDA and the exact by-memory/type pages remain authoritative.
- 2026-07-05 pre-callback generated-output check found `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` at validator command `000000006959`, refreshed `2026-07-05T10:43:05-04:00`. It already emitted UID0001VE, UID0002JO, and UID0002JQ, while UID00008W and UID0001Y8 remained marker-only by design and UID0002JP still showed an empty marker. After this callback, scoped validators should refresh UID0002JP/UID00008W so the generated file no longer has a UID0002JP empty marker. No generated file should be edited manually.
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
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md)
- [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md)
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Score Rationale

The file remains `87/86`. The direct file placement is defensible because IDA confirms this is reusable player-inventory picker UI with constructor callers from `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`, not a clan-only or exchange-only implementation. The exact child pages document constructor, selected-slot helper, and draw method boundaries at or above the strict `85/85` child gate; UID0002JO emits constructor C++, UID0002JP now emits `GetSelectedSlotIndex` C++ at `88/92`, UID0002JQ emits `DrawListEntry` C++ at `88/90`, and class-owned child emission routes through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md). The file remains below final-source quality because the final source split between standalone `MyItemListPane.cpp` and compact `ItemDialogs.cpp` is inferred from proposed project structure and consumer clustering rather than original source files, and some row/API names remain provisional.

## Changes

- 2026-07-13 B005 UID0004BP support synchronization: score/path/FILE ownership unchanged at `87/86`; added the selector-3 wrapper path, dynamic MyItemListPane receiver, inherited UID0004M9 dependency, generic ListPane ownership, and negative AddItemDialog member evidence while preserving all existing file-placement and row/API caveats.

- 2026-07-13 B001 UID0004BM callback: score/path unchanged at `87/86`; added exact AddItemDialog caller sites, EPF dynamic versus EPD forced multiple-selection configuration, local ownership transfer to ScrollableControlPane, negative AddItemDialog member-store evidence, and UID0004LX's retained generic ListPane source route.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents role, constructor/draw behavior, caller evidence, EPF/legacy draw paths, ownership decision, generated-data defects, vtable caveats, and cross-references; confidence remains capped by the original source split and active generated output omissions.
- Reconstruction path update: existed before as blank `PROPOSED_RECONSTRUCTION_PATH`; changed to `NexusTK/ui/dialogs/`. Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `ui/dialogs/MyItemListPane.cpp`, and the file is documented as reusable item-picker dialog support adjacent to `ItemDialogs.cpp`.
- Exact child split update: added child links for constructor, selected-slot helper, and draw method after 2026-05-31 IDA MCP found the real helper at `0x004aec80` inside the previous constructor-to-draw gap.
- 2026-06-10 B001-026 parent-gate repair:
  - Before: file confidence was `80`, so assigned reconstructable children inside [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md) were below the strict direct-parent `85/85` gate.
  - After: confidence is `85`; the direct parent now clears the gate for the exact constructor, selected-slot, and draw child pages.
  - Evidence: IDA confirms the child boundaries, vtables, draw-slot dispatch, row payload layout, caller fanout from AddItem/Mix/Clan deposit dialogs, and item-image draw dependencies. The remaining uncertainty affects final C++ naming, not ownership.
- 2026-06-16 A001 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Evidence: live IDA MCP reconfirmed method sizes, constructor/helper/draw xrefs, vtable stores, item-image/text draw dependencies, and row payload offsets. Targeted generated-output review shows `DrawListEntry` is now emitted in active `simroot_v2`, resolving the old missing-body caveat; IDA still has no source filename string or local struct, so final source split and row/API names remain blockers.
- 2026-07-02 B003 UID0002JO implementation callback:
  - Confirmed file placement remains `NexusTK/ui/dialogs/MyItemListPane.cpp` while UID0002JO now emits through class [UID:00008W][MyItemListPane](by-class/MyItemListPane.md).
  - Added source-placement note that UID0002JO is first-draft C++ ready through the class route.
  - Preserved rejected alternatives: this is not `ListPane.cpp`, not AddItem-only, not Mix-only, and not clan-only ownership.
- 2026-07-02 B004 UID0002JQ implementation callback:
  - Score unchanged at `87/86`; file placement remains `NexusTK/ui/dialogs/MyItemListPane.cpp` while UID0002JQ now emits through class [UID:00008W][MyItemListPane](by-class/MyItemListPane.md).
  - Updated Draw Path Details, Data Caveats, and Score Rationale with UID0002JQ `88/90`, first-draft `DrawListEntry` C++, vtable-only dispatch through `0x00619fa8`, inherited ListPane callback shape, row payload fields, selected-row callback, EPF/legacy draw branches, and text-tail helpers.
  - Replaced the stale current-generated-body claim with the current marker-only validator-generated state and the expectation that scoped validators refresh generated output; no generated file was edited manually.
- 2026-07-05 B004 UID0002JP implementation callback:
  - Score unchanged at `87/86`; file placement remains `NexusTK/ui/dialogs/MyItemListPane.cpp` while UID0002JP now emits through class [UID:00008W][MyItemListPane](by-class/MyItemListPane.md).
  - Updated status, proposed contents, caller evidence, selected-slot helper details, data caveats, and score rationale with UID0002JP `88/92`, first-draft `GetSelectedSlotIndex` C++, current MCP exact bytes/callee/callers, `ListPane` `0x004f3dc0` selected-index lowering, ClanDep/ClanBank direct callers, AddItem inline-equivalent negative evidence, and generated empty-marker state before validation.
  - Preserved rejected alternatives: this remains reusable item-picker UI routed through MyItemListPane, not `ListPane.cpp`, not AddItem-only, not Mix-only, not ClanBank-only, and not a raw no-owner helper.
