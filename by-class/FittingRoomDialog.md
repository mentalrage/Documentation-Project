*** UID:000050 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDialog

## Status

- Confidence: strong for the main dialog constructor, command, draw, action, show-preview, category-button rebuild, selection, singleton cleanup, and destructor-wrapper methods.
- Current recovered source lead: `class_FittingRoomDialog.cpp` only; ownership and scoring here are based on existing docs plus IDA/MCP evidence.
- Assigned source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: exact by-memory method pages and IDA MCP checks through the 2026-06-07 Batch088 recheck.

## Role

Feature dialog for fitting-room equipment preview and cash-shop item browsing. It owns preview state, child controls, slot/category buttons, fitting-room request submission, reset/show-preview behavior, and the global `g_pFittingRoomDialog` lifetime.

## Batch088 IDA Evidence Refresh

IDA MCP recheck on 2026-06-07 confirmed the documented method island still has the expected exact starts and sizes: constructor `0x0041bdd0-0x0041c250`, `OnCommand` `0x0041c310-0x0041c596`, draw background `0x0041c5e0-0x0041cb63`, fitting action `0x0041cb70-0x0041cd38`, show preview `0x0041cd40-0x0041cdbf`, category-button rebuild `0x0041cdc0-0x0041d14b`, control bounds `0x0041d150-0x0041d284`, selection toggle `0x0041d2c0-0x0041d335`, compare helper `0x0041d340-0x0041d3b0`, shared string-storage assign `0x0041d3b0-0x0041d431`, singleton clear `0x0041d440-0x0041d44b`, and scalar deleting destructor `0x0041d490-0x0041d572`.

The same recheck confirmed three FittingRoomDialog vtable anchors: primary table `0x0060da68`, secondary table `0x0060dac8`, and tertiary table `0x0060daf8`, with constructor stores at `0x0041be37`, `0x0041be43`, and `0x0041be53`, raw destructor-shaped stores at `0x0041c259`, `0x0041c25f`, and `0x0041c269`, and scalar-destructor stores at `0x0041d49c`, `0x0041d4a2`, and `0x0041d4ac`. `g_pFittingRoomDialog` at `0x0067a73c` is written by the constructor, cleared by destructor/cleanup paths, and read by fitting-room request/list flows.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) | constructor | Constructs the dialog, item state, catalog/list children, preview controls, and sends the version request. Called by `0x005a5bd0`. |
| [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) | `OnCommand` | Handles close, rotate preview, reset/current appearance, and slot/category selection. Reset/show paths call [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) at `0x0041c404` with `this + 0x504`. |
| [UID:0002CS][0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground](by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md) | `DrawBackground` | Tiles the center background and draws fitting-room/dialog frame resources. |
| [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md) | `HandleFittingAction` | Submits/catalog request flow through [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), polls [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md), and calls `ShowPreview` when fitting state is ready. |
| [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md) | `ShowPreview` | Refreshes preview/list state and shows the fitting-room preview through the main UI layer. |
| [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) | `RebuildCategoryButtons` | Recreates category command buttons `7` through `16`, selects the first category when usable entries are missing, and invalidates dialog bounds. |
| [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) | `SelectButton` | Updates active selection button state at `this + 0x788` and toggles the old/new button selected flags. |
| [UID:0002D0][0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal](by-memory/0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal.md) | cleanup helper | Clears `g_pFittingRoomDialog`; likely cleanup/unwind support. |
| [UID:0002CR][0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor](by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md) | scalar deleting destructor wrapper | Tears down pending request/status string/item state, clears `g_pFittingRoomDialog`, and conditionally deletes `this`. |

## Associated Helpers

- [UID:0002CW][0x0041d150-0x0041d284.FittingRoomControlBounds](by-memory/0x0041d150-0x0041d284.FittingRoomControlBounds.md) is a file-local style control rectangle lookup used by the constructor and category-button rebuild path.
- [UID:0002CY][0x0041d340-0x0041d3b0.CompareEquipmentNames](by-memory/0x0041d340-0x0041d3b0.CompareEquipmentNames.md) is a fitting-room state-name comparison helper called by `HandleFittingAction`.
- [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) is address-adjacent and used by fitting-room code, but IDA callers show it is shared string-storage support rather than a `FittingRoomDialog` method.
- [UID:0002D1][0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks](by-memory/0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks.md) documents compiler-generated destructor adjustor thunks; do not port them as handwritten methods.

## Boundary Cautions

- Wave3 lists `~FittingRoomDialog` at `0x0041c250`, but IDA MCP reports `0x0041c250` is not a function start. Use exact constructor range [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) and `0x0041c310+` confirmed starts for source migration.
- 2026-05-25 IDA MCP recheck: `xrefs_to 0x0041c250` reports no references. Disassembly at `0x0041c250` is destructor-shaped raw code, but the migration anchor remains the confirmed scalar deleting destructor at `0x0041d490`, which clears child/state fields, tears down the embedded item state via `0x00422330`, clears `g_pFittingRoomDialog`, and conditionally deletes through `0x004f4ac0`.
- 2026-05-27 IDA recheck: `HandleFittingAction` calls `0x0041a580` at `0x0041cbbc` with the selected/request pointer plus `4` as receiver. That helper computes a progress percentage and belongs to [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), not the UI dirty-region [UID:0000BV][Region](by-class/Region.md) class.
- Wave3 also attaches generic clip/timer helpers at `0x004a6fa0`, `0x004b9580`, `0x004b9590`, `0x004b95b0`, and `0x005975e0`. Keep those as medium-confidence until generic UI/timer ownership is reviewed.

## Assignment Decision

Assigned to [UID:0000JE][FittingRoom](by-file/FittingRoom.md) under the corrected Batch088 gate. This child now reaches `85/88`, and the direct parent is already documented at `85/87`. The class belongs to the fitting-room source module because its exact method pages, vtables, singleton lifetime, child controls, catalog/list interactions, and reset/preview flows are all local to the cash-shop fitting-room feature.

Final C++ remains blank because the class declaration, inherited base list, field names, and child-control layout are not yet at the `95/95` source-emission gate.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page now has a full exact-method inventory, associated helper list, vtable/singleton refresh evidence, boundary cautions, cross-references, and direct source-parent assignment. It remains below final because field names, full layout declaration, and final C++ are not complete. |
| Confidence `88` | Confidence is strong because constructor/destructor/vtable/singleton evidence and exact method pages align on the FittingRoom owner. It remains below final because some generic helper ownership and source-level layout details are still provisional. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md)
- [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md)
- [UID:0002CS][0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground](by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md)
- [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md)
- [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md)
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md)
- [UID:0002CW][0x0041d150-0x0041d284.FittingRoomControlBounds](by-memory/0x0041d150-0x0041d284.FittingRoomControlBounds.md)
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md)
- [UID:0002CY][0x0041d340-0x0041d3b0.CompareEquipmentNames](by-memory/0x0041d340-0x0041d3b0.CompareEquipmentNames.md)
- [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md)
- [UID:0002D0][0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal](by-memory/0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal.md)
- [UID:0002D1][0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks](by-memory/0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks.md)
- [UID:0002CR][0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor](by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)

## Changes

- Before: the main constructor, command handler, and scalar deleting destructor were listed by address only inside the class method table.
- After: those methods link to exact `by-memory` pages with IDA-backed ranges and behavior notes.
- Summary/evidence: IDA MCP on 2026-05-30 confirmed the exact function boundaries and decompiled the constructor, command switch, and destructor wrapper.
- 2026-05-30: Existing draw/action/show-preview method rows were address-only summaries. Changed them to exact `by-memory` UID links for `DrawBackground`, `HandleFittingAction`, and `ShowPreview`. Evidence: IDA MCP confirmed boundaries, callees/callers, and decompiled behavior for `0x0041c5e0`, `0x0041cb70`, and `0x0041cd40`.
- 2026-05-30: Existing `SelectButton` row was address-only and the adjacent category/control helper span was not split in this class page. Changed it to exact method/helper links for category-button rebuild, control bounds, selection toggle, equipment-name compare, shared string assignment, singleton cleanup, and destructor adjustor thunks. Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, and `decompile` for `0x0041cdc0-0x0041d481`.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the fitting-room dialog shell unclassified despite its detailed IDA-backed method inventory.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `79/86`, just below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms the main dialog starts at `0x0041bdd0`, `0x0041c310`, `0x0041c5e0`, `0x0041cb70`, `0x0041cd40`, `0x0041cdc0`, `0x0041d2c0`, and `0x0041d490`, with the constructor called from `0x005a726a`.
- 2026-06-07 Batch088 class coverage audit:
  - Before: scores were `79/86`, and `AUTOGEN_PARENT_UID` was blank.
  - After: raised to `85/88` and assigned to [UID:0000JE][FittingRoom](by-file/FittingRoom.md), which already satisfies the corrected direct-parent gate at `85/87`.
  - Summary/evidence: IDA/MCP recheck confirmed exact method ranges, three vtable-anchor store groups, and `g_pFittingRoomDialog` lifetime refs. Final C++ remains blank under the 95/95 source-emission gate.
