*** UID:0000KE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemDialogs

## Status

- Confidence: strong for item selection, mixing, and menu-dialog ownership; medium for exact split between exchange, mix, context-menu, and item-action input files.
- Proposed module folder: `ui/dialogs/`
- Projected reconstruction path: `NexusTK/ui/dialogs/`
- Candidate files: `ui/dialogs/ItemDialogs.cpp`, [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), `ui/dialogs/MixItemDialog.cpp`, and `ui/dialogs/ItemActionInputPanes.cpp`
- Current generated sources: `class_AddItemDialog.cpp`, `class_AddItemWithCountDialog.cpp`, `class_MyItemListPane.cpp`, `class_AddEmployeeItemDialog.cpp`, `class_MixItemDialog.cpp`, `class_AddMixingItemDialog.cpp`, `class_ServerItemMenuDialog.cpp`, `class_ServerItemMenuItemList.cpp`, `class_ClientItemMenuDialog.cpp`, `class_ClientItemMenuItemList.cpp`, plus direct item-action input panes now covered by [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Placement update: `class_AddEmployeeItemDialog.cpp` is generated near item picker code, but 2026-05-24 IDA evidence ties final ownership to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Evidence basis: Wave3 metadata and targeted IDA MCP boundary/vtable checks on 2026-05-23, 2026-05-24, and 2026-05-26. Use [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) as the current IDA-backed layout anchor.

## Hypothesis

The item dialog code was likely grouped by gameplay UI feature rather than one class per file. The core file should own exchange/mix item-selection dialogs and item context menus; direct command input panes such as drop, give, use, wear, wield, and take-off likely live nearby in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).

Player-to-player exchange itself is now documented separately in [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). This file should keep the reusable item picker dialogs that exchange calls, but not absorb the live trade window, exchange packet dispatcher, money edit control, or exchange alerts.

Likely split:

```text
ui/dialogs/ItemDialogs.cpp
ui/dialogs/MyItemListPane.cpp
ui/dialogs/ItemMenuDialogs.cpp
ui/dialogs/MixItemDialog.cpp
ui/dialogs/ItemActionInputPanes.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/ItemDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `AddItemDialog` | `0x004ae4c0-0x004b096e` | `class_AddItemDialog.cpp` | Modal item selection dialog with list layout, OK/cancel handling, action state, and destructor thunks. |
| `AddItemWithCountDialog` | `0x004af040-0x004af4b6` | `class_AddItemWithCountDialog.cpp` | Quantity-aware item add dialog. |
| `MyItemListPane` | `0x004aeb30-0x004af031` | `class_MyItemListPane.cpp` | Player inventory item-picker list used by add-item, mix-item, and clan-deposit flows. |
| `AddEmployeeItemDialog` | `0x004a4ae0`, `0x004a4b20-0x004a4d3a` | `class_AddEmployeeItemDialog.cpp` | Employee-specific `AddItemDialog` variant; final owner is likely [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), while the base picker remains here. |
| `MixItemDialog` | `0x004af570-0x004b0b14` | `class_MixItemDialog.cpp` | Builds selected-item mix list, handles add/remove/submit actions, and sends mix packet. |
| `AddMixingItemDialog` | `0x004b0000-0x004b09cf` | `class_AddMixingItemDialog.cpp` | Item picker used by the mix dialog; filters already selected items and handles stack quantity flow. |
| [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) caller use | `0x00530640-0x00530cf7` | `class_NumberInputDialog.cpp` | Reusable numeric prompt invoked by item-mixing quantity paths; implementation should stay in `ui/dialogs/NumberInputDialog.cpp`, not this file. |
| `ServerItemMenuDialog` | `0x0051a520-0x0051ae8c` | `class_ServerItemMenuDialog.cpp` | Server-provided item action menu over the shared merchant-menu dialog base. |
| `ServerItemMenuItemList` | `0x0051ae90-0x0051b87a` | `class_ServerItemMenuItemList.cpp` | Private row-list widget for server-provided item menu entries. |
| `ClientItemMenuDialog` | `0x0051b880-0x0051c46c` | `class_ClientItemMenuDialog.cpp` | Client-side item action context menu over the shared merchant-menu dialog base. |
| `ClientItemMenuItemList` | `0x0051c470-0x0051ca3b` | `class_ClientItemMenuItemList.cpp` | Private row-list widget for client-side item action entries. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x004ae4c0`, `0x004ae900`, `0x004ae930`, `0x004aea40`, and `0x004b0910` for `AddItemDialog`.
- `0x004af040`, `0x004af380`, and `0x004af480` for `AddItemWithCountDialog`.
- `0x004aeb30` and `0x004aec90` for `MyItemListPane`; constructor callers are `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`.
- 2026-05-26 vtable follow-up confirms `MyItemListPane` table bases `0x00619f28`, `0x00619fb0`, and `0x00619fe0`, with `DrawListEntry` at primary slot `+0x80`; see [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md).
- `0x004af570`, `0x004af8b0`, and `0x004b0ad0` for `MixItemDialog`.
- `0x004b0000`, `0x004b0120`, and `0x004b0970` for `AddMixingItemDialog`.
- 2026-05-26 vtable pass confirms three-view dialog tables for `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, and `AddMixingItemDialog`, with object vfptr offsets `+0x00`, `+0xa0`, and `+0xa4`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- `0x0051a520`, `0x0051acb0`, and `0x0051ae50` for `ServerItemMenuDialog`.
- `0x0051ae90` is raw constructor-shaped code for `ServerItemMenuItemList`; IDA confirms the vtable virtuals at `0x0051b100`, `0x0051b2b0`, `0x0051b2c0`, and `0x0051b3e0`.
- `0x0051b880`, `0x0051c310`, and `0x0051c430` for `ClientItemMenuDialog`.
- `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0` for `ClientItemMenuItemList`, with raw helper-shaped code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`.

IDA reports no function at Wave3's `AddEmployeeItemDialog` constructor start `0x004a4ae0`; this is tracked in [wave3_data_issues](../wave3_data_issues.md). A 2026-05-24 recheck shows `EmployeeDialogPane::OnButtonAction` constructs an `AddItemDialog`, then patches its vtables to `AddEmployeeItemDialog`; a 2026-05-27 recheck still finds no function/xrefs or raw pointer-table references to `0x004a4ae0`. Source migration should attach the employee-specific subclass to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) unless stronger original-file evidence appears.

## Ownership Notes

- Exchange/mix item selection is dialog/session UI, not inventory pane rendering. Keep it separate from [UID:0000KA][InventoryPane](by-file/InventoryPane.md) and item image code.
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) is reusable player-inventory picker UI. Keep it adjacent to item dialogs or as its own `ui/dialogs/MyItemListPane.cpp`; do not migrate it into generic [UID:0000KT][ListPane](by-file/ListPane.md) or social/clan ownership just because clan deposit uses it.
- `MyItemListPane` consumes [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) for icon drawing, but the singleton and draw routines remain owned by [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Player-to-player exchange session UI belongs to [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). `AddItemDialog` is invoked by exchange as a picker, but `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, and `ExchangeAlertPane` should migrate as a separate source module.
- `AddMixingItemDialog` derives from `AddItemDialog` and stores a pointer back to `MixItemDialog`, so those files should stay adjacent even if split.
- The item dialog vtables sit immediately before/among adjacent `MyItemListPane`, `ExchangeAlertPane`, and `FieldMapPane` RTTI/table data. Use the confirmed table bases rather than a broad `.rdata` neighborhood when assigning class layout.
- Stackable item quantity prompts call [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md). Treat this as a reusable dialog dependency, not as proof that `NumberInputDialog` belongs in item-dialog source.
- `AddEmployeeItemDialog` also derives from/reuses `AddItemDialog`, but its owner pointer and command path are employee-specific. Keep it cross-referenced here but do not use it as generic `ItemDialogs.cpp` ownership proof.
- Item context menus around `0x0051a520+` are later in memory than the exchange/mix constructors but are still item-action UI and should cross-reference this module. The stronger file-level split is now documented in [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
- Item context menu vtables share [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)'s [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md); keep that shared base adjacent but do not migrate it as item-only source.
- The item menu dialog/list vtables are covered by [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- Generated `ServerItemMenuItemList` currently includes article/mail pagination and shared `ListPane` helpers. Do not use those scattered generated methods as proof that bulletin/mail paging belongs in `ItemMenuDialogs.cpp`.
- Spell action context menus are a sibling family now covered by [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), not part of the item-dialog source itself.
- Clan item deposit/withdraw dialogs are intentionally deferred to a future clan-dialog module because their ownership is social/clan banking rather than generic item actions.

## Cross-References

- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: item picker, mix, menu-dialog, list-pane, employee-dialog boundary, vtable family, ownership notes, exchange/menu/action split, and cross-references are well documented; confidence is capped by exact original split among item dialogs, exchange, mix, context menus, and item-action input files.
- 2026-06-03 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though this page and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already placed `ItemDialogs.cpp` under `ui/dialogs/`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: the page's status, proposed contents, and project-structure entry consistently place the item picker/mix/menu dialog family under `ui/dialogs/`; this assignment allows attached child documentation such as [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md) to resolve to a concrete generated source root while preserving the documented caveat that some adjacent classes may later split into `MyItemListPane.cpp`, `ItemMenuDialogs.cpp`, or `MixItemDialog.cpp`.
