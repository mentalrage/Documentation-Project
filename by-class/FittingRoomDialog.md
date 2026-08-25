*** UID:000050 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/BlackHole.h"
#include "../map/ObjectStatusBlob.h"
#include "../ui/core/DialogPane.h"
#include "CashShopRequest.h"

class FittingRoomListPane;

enum FittingRoomDialogCommand
{
    kFittingRoomCommandClose = 0,
    kFittingRoomCommandRotateRight = 3,
    kFittingRoomCommandRotateLeft = 4,
    kFittingRoomCommandBasic = 5,
    kFittingRoomCommandCurrent = 6,
    kFittingRoomCommandUsableItems = 7,
    kFittingRoomCommandWeapons = 8,
    kFittingRoomCommandMounts = 9,
    kFittingRoomCommandFace = 10,
    kFittingRoomCommandHead = 11,
    kFittingRoomCommandMantle = 12,
    kFittingRoomCommandNecklaces = 13,
    kFittingRoomCommandCoats = 14,
    kFittingRoomCommandShoes = 15,
    kFittingRoomCommandSpecialtySets = 16
};

struct FittingRoomCategoryButtonDef
{
    int commandId;
    const wchar_t* label;
};

class FittingRoomDialog : public DialogPane
{
    friend class FittingRoomListPane;

public:
    FittingRoomDialog();
    virtual ~FittingRoomDialog();

protected:
    virtual void OnCommand(int commandId);
    virtual void DrawBackground();
    virtual bool HandleFittingAction(int action, int arg0, int arg1);

private:
    int ShowPreview();
    void RebuildCategoryButtons();
    void SelectButton(int commandId);

    ObjectStatusBlob m_baseAppearance;
    ObjectStatusBlob m_previewAppearance;
    FittingRoomDialogItemState m_itemState;
    int m_activeCategory;
    int m_selectedCategoryCommandId;
    int m_categoryListState;
    std::string m_itemShopVersion;
    CashShopRequest* m_activeCatalogRequest;
};

typedef char FittingRoomDialogSizeMustBe1964[
    sizeof(FittingRoomDialog) == 0x7ac ? 1 : -1];

extern FittingRoomDialog* g_pFittingRoomDialog;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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
| [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) | constructor | Builds the dialog, writes `g_pFittingRoomDialog`, constructs item state and initial controls, installs a temporary download/progress child id `7`, calls the FileDownloader/download-dispatcher version-submit helper that posts message `10002`, and schedules timer action `0` at `100` ms. |
| [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) | `OnCommand` | Handles close, preview direction, Basic/Current appearance resets, category command ids `7..16`, selected command id `+0x788`, active category `+0x784`, and list reset through child id `2`. |
| [UID:0002CS][0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground](by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md) | `DrawBackground` | Primary draw virtual using `WBOARDBK` center tiling and `WEBBOARD` frame pieces `1/6/3/4/0/2/5/7`. |
| [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md) | `HandleFittingAction` | Source-ready `88/91` method emitted through this class after B007 MCP session `c9b60f19`; action `1` polls `m_activeCatalogRequest`, calls [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md) at `0x0041cbbc` with request `+0x04`, updates child id `7` progress byte `+0x108`, loads/saves item state, and calls `ShowPreview`, while action `0` compares `m_itemShopVersion`, marks child id `7` waiting byte `+0x109`, submits the FileDownloader catalog request `10001`, and schedules the poll timer. |
| [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md) | `ShowPreview` | Called after item-state load/save; refreshes dialog state, rebuilds category buttons, calls list child `ControlPane::SetVisibleFlag` and `Pane::Show`, then shows the dialog at `(102,134,820,500)` on main layer/context `0x0069b36c`. |
| [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) | `RebuildCategoryButtons` | Removes old child id `7`, creates category text buttons `7..16` (`UsableItems`, `Weapons`, `Mounts`, `Face`, `Head`, `Mantle`, `Necklaces`, `Coats`, `Shoes`, `SpecialtySets`), default-selects id `7` when category `0` count is not positive, and invalidates dialog bounds. |
| [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) | `SelectButton` | Updates selected category command id `+0x788`, toggles old/new `FittingRoomTextButtonControlPane::SetSelected` state, and invalidates changed buttons. |
| [UID:0002D0][0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal](by-memory/0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal.md) | cleanup helper | Clears `g_pFittingRoomDialog`; likely cleanup/unwind support. |
| [UID:0002CR][0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor](by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md) | scalar deleting destructor wrapper / source destructor anchor | Source-ready `88/91` class-emitted destructor after B004 MCP session `dbe126a4`; formal source body releases a completed `m_activeCatalogRequest`, clears the request pointer, and clears `g_pFittingRoomDialog`, while vtable restores, member/base destruction, adjustor thunks, scalar-delete flags, and object-free mechanics remain compiler/lowering evidence. |

## Associated Helpers

- [UID:0002CW][0x0041d150-0x0041d284.FittingRoomControlBounds](by-memory/0x0041d150-0x0041d284.FittingRoomControlBounds.md) is a file-local style control rectangle lookup used by the constructor and category-button rebuild path.
- [UID:0002CY][0x0041d340-0x0041d3b0.CompareEquipmentNames](by-memory/0x0041d340-0x0041d3b0.CompareEquipmentNames.md) is a file-local raw pointer/length byte-string equality helper used by [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md). B005 MCP session `a16fd2b6-0d5f-4973-9eae-b580b2599295` confirms two direct calls at `0x0041cc8a` and `0x0041cccc`, no callees, and raw `__cdecl` pointer/length comparison semantics. The compared dialog field is `m_itemShopVersion` at `+0x790`; the item-state side is catalog/version text from [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) `m_catalogVersion`, loaded from JSON `"version"`. The `CompareEquipmentNames` name is project-facing/descriptive, not original-symbol proof and not equipment-entry traversal.
- [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) is address-adjacent and used by fitting-room code, but IDA callers show it is shared string-storage support rather than a `FittingRoomDialog` method.
- [UID:0002D1][0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks](by-memory/0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks.md) documents compiler-generated destructor adjustor thunks; do not port them as handwritten methods.

## B003 Core Source-Quality Reanalysis

- 2026-06-18 B003 FittingRoomDialog core source-quality reanalysis routes [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md)/[UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md)/[UID:0002CS][0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground](by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md)/[UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md)/[UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md)/[UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) directly through this class as owner/emitter, with generated output still routed through [UID:0000JE][FittingRoom](by-file/FittingRoom.md).
- 2026-07-03 B007 UID0002CT source-quality implementation extends that class-emitter route to [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md). MCP session `c9b60f19` confirms exact range `0x0041cb70-0x0041cd38`, size `0x1c8`, vtable data xref `0x0060dafc`, no direct code callers, `0xcc` padding on both sides, constructor scheduling of action `0` through the `+0xa4` timer/action facet, and the action `0`/`1` request-progress behavior. The method now emits first-draft C++ through this class; exact names for the timer facet, request progress wrapper, item-state cached-version accessor, and child id `7` waiting byte remain documented confidence caps.
- 2026-07-09 B004 UID0002CR implementation extends the class-emitter route to [UID:0002CR][0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor](by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md). MCP session `dbe126a4` confirms exact range `0x0041d490-0x0041d572`, size `0xe2`, successor `0x0041d580`, primary vtable slot `0x0060da68`, secondary/tertiary adjustor thunks `0x0041d455`/`0x0041d460` through vtable cells `0x0060dac8`/`0x0060daf8`, no ordinary direct callers, raw `0x0041c250` no-function/no-xref status, and generated empty-marker resolution. The target now emits first-draft `FittingRoomDialog::~FittingRoomDialog()` C++; exact field spellings and final class layout remain confidence caps.
- 2026-07-09 B005 UID0002CY implementation keeps [UID:0002CY][0x0041d340-0x0041d3b0.CompareEquipmentNames](by-memory/0x0041d340-0x0041d3b0.CompareEquipmentNames.md) as a file-local [UID:0000JE][FittingRoom](by-file/FittingRoom.md) helper, not a dialog instance method. MCP session `a16fd2b6-0d5f-4973-9eae-b580b2599295` confirms exact `0x0041d340-0x0041d3b0` range, two `HandleFittingAction` callers, no callees, and raw pointer/length byte-string equality. In dialog terms, the helper compares `m_itemShopVersion` against item-state `m_catalogVersion` / cached version text; UID0002CZ remains adjacent shared SSO support, not dialog-owned source.
- Field roles from the six-target pass plus B007 FileDownloader support sync: `+0x1fc` is `m_controlManager`/child container with lookup slot `+0x10`; `+0x47c` is the base/current appearance block; `+0x4c0` is the preview appearance block; `+0x49e` is preview/special-part mode; `+0x4a4/+0x4e8` are appearance bytes initialized to `0x50`; `+0x4e2` is a mirrored appearance option byte; `+0x504` is embedded `FittingRoomDialogItemState`; `+0x744/+0x748` is the selected/cart item-entry vector span; `+0x784` is active category ordinal; `+0x788` is selected category command/control id, not a pointer; `+0x78c` is a reserved/list-side dword; `+0x790` is `m_itemShopVersion`, the version string written by [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md); `+0x7a8` is `m_activeCatalogRequest`, the active catalog request pointer/status used by catalog submission/cleanup, not version string storage; `+0xa4` is the embedded `TimerHandler`/action facet.
- Helper/source-name directions: `0x0041d150` is `GetFittingRoomControlBounds`; `0x0049dc10` is the dialog add-control helper; control-manager slot `+0x10` is `FindControlById`; `0x0049dd00` is `DialogCategorySwitch`; `0x00424550` and `0x00424570` advance/retreat preview facing direction; `0x0041d5e0` resets embedded fitting-equipment entries; `0x00424260` is `FittingRoomTextButtonControlPane::SetSelected`; `0x00494bb0` is `ControlPane::SetVisibleFlag`; `0x00544730` is `Pane::Show`; dialog slot `+0x30` is the inherited show-in-layer route; dialog slot `+0x38` remains a refresh/update hook at `0x0049e1c0`; `0x005975e0` schedules timer action `0` at `100` ms.
- Child id/source behavior corrections: child id `2` is the list pane; temporary child id `7` is the pre-preview download/progress control and is later replaced by category button id `7`; category buttons `7..16` are `UsableItems`, `Weapons`, `Mounts`, `Face`, `Head`, `Mantle`, `Necklaces`, `Coats`, `Shoes`, and `SpecialtySets`; `ShowPreview` calls list-child `ControlPane::SetVisibleFlag` and `Pane::Show`, not `FittingRoomListPane::ResetScrollPosition`.
- Rejected alternatives preserved from the B003 report: direct [UID:0000JE][FittingRoom](by-file/FittingRoom.md) ownership is stale for these six class methods; [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md) is only a broad container; DialogPane, Pane, ControlPane, TimerHandler, FittingRoomListPane, FittingRoomTextButtonControlPane, and ItemCatalog provide helpers or child objects but do not own these dialog methods; `+0x788` is not a selected-button pointer; `0x0069b36c` is a main UI layer/context slot, not `g_pMainMenuPane`; table-driven category-button C++ is source-equivalent but not proven as the exact original source form.

## Boundary Cautions

- Wave3 lists `~FittingRoomDialog` at `0x0041c250`, but IDA MCP reports `0x0041c250` is not a function start. Use exact constructor range [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) and `0x0041c310+` confirmed starts for source migration.
- 2026-05-25 IDA MCP recheck, reconfirmed by B004 session `dbe126a4`: `xrefs_to 0x0041c250` reports no references and no function object exists there. Disassembly at `0x0041c250` is destructor-shaped raw code, but the migration anchor remains the confirmed scalar deleting destructor at `0x0041d490`, which now emits the source destructor body while retaining child/state cleanup, embedded item-state teardown via `0x00422330`, `g_pFittingRoomDialog` clear, and conditional delete through `0x004f4ac0` as compiler/lowering evidence.
- 2026-05-27 IDA recheck plus B006 2026-07-03 split: `HandleFittingAction` calls `0x0041a580` at `0x0041cbbc` with the selected/request pointer plus `4` as receiver. That helper computes a progress percentage and is now exact child [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md) under split/index parent [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), not the UI dirty-region [UID:0000BV][Region](by-class/Region.md) class. Reset/no-op siblings [UID:0004G9][0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary](by-memory/0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md), [UID:0004GA][0x0041a570-0x0041a571.FittingRoomDownloadProgressStateNullPrimary](by-memory/0x0041a570-0x0041a571.FittingRoomDownloadProgressStateNullPrimary.md), [UID:0004GC][0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary](by-memory/0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary.md), and [UID:0004GD][0x0041a5c0-0x0041a5c1.FittingRoomDownloadProgressStateNullSecondary](by-memory/0x0041a5c0-0x0041a5c1.FittingRoomDownloadProgressStateNullSecondary.md) remain non-emitting/no-route children.
- Wave3 also attaches generic clip/timer helpers at `0x004a6fa0`, `0x004b9580`, `0x004b9590`, `0x004b95b0`, and `0x005975e0`. Keep those as medium-confidence until generic UI/timer ownership is reviewed.

## Assignment Decision

Assigned to [UID:0000JE][FittingRoom](by-file/FittingRoom.md) under the corrected Batch088 gate. This class remains `87/89`, and the file route is documented at `88/90`. The class belongs to the fitting-room source module because its exact method pages, vtables, singleton lifetime, child controls, catalog/list interactions, and reset/preview flows are all local to the cash-shop fitting-room feature.

Class-level C++ is limited to shared draft command constants, the category-button definition, and a `[[CHILDREN]]` insertion point used by the method children. The full class declaration remains withheld because inherited base list, final field names, and complete layout are not final. The B003 six source-bearing method children plus B007's UID0002CT `HandleFittingAction` and B004's UID0002CR destructor now carry first-draft C++ individually.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now has a full exact-method inventory, associated helper list, vtable/singleton refresh evidence, boundary cautions, cross-references, direct source-parent assignment, B003 field/helper/source-placement reanalysis, shared draft command/category declarations, and first-draft C++ readiness for the six core method children. It remains below final because full class layout declaration and exact appearance subfield names are not complete. |
| Confidence `89` | Confidence is strong because constructor/destructor/vtable/singleton evidence, exact method pages, executed fitting-room list/item-state reports, and B003 section-mapped PE/vtable checks align on FittingRoomDialog ownership. It remains below final because some generic helper ownership and source-level layout details are still provisional. |

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
- [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md)
- [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)

## Changes

- 2026-07-09 B005 UID0002CY implementation callback: Metadata unchanged. Updated associated-helper wording for [UID:0002CY][0x0041d340-0x0041d3b0.CompareEquipmentNames](by-memory/0x0041d340-0x0041d3b0.CompareEquipmentNames.md): it is now first-draft source-ready through [UID:0000JE][FittingRoom](by-file/FittingRoom.md) as a file-local static raw pointer/length helper, not a `FittingRoomDialog` instance method. Preserved [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md) as the only consumer, recorded B005 MCP session `a16fd2b6-0d5f-4973-9eae-b580b2599295` two-call/no-callee evidence, clarified `m_itemShopVersion` versus item-state `m_catalogVersion` semantics, and kept [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) as adjacent shared string support rather than dialog-owned source.
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
  - Summary/evidence: IDA/MCP recheck confirmed exact method ranges, three vtable-anchor store groups, and `g_pFittingRoomDialog` lifetime refs. The child-method blank-C++ state from this audit is superseded by the 2026-06-18 B003 first-draft C++ incorporation; class-level declaration C++ remains blank pending final layout/inheritance names.
- 2026-06-18 supervisor/B003: Accepted B003 FittingRoomDialog core source-quality report under Rule 26 with no arbitrary detail cap. Raised to `87/89`; rerouted the six core method children through this class; updated method rows with child ids, command ids, resource frame roles, selected-command semantics, and show/list slots; recorded field/helper/rejected-alternative details; added shared draft command/category declarations; and noted that the six method children now carry first-draft C++ while the full class declaration remains withheld.
- 2026-07-03 B007 UID0002CT implementation callback: Metadata unchanged. Rerouted [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md) from direct file owner/emitter to this class at `88/91` with formal `FittingRoomDialog::HandleFittingAction` C++. Preserved B007 MCP session `c9b60f19` facts for range/size, vtable data xref `0x0060dafc`, no direct code callers, action `0`/`1` behavior, helper callees, `+0xa4` timer-facet receiver, and rejected FileDownloader/TimerHandler/ProgressState/DownloadControlPane/Region/raw-helper/no-code ownership alternatives.
- 2026-07-09 B004 UID0002CR implementation callback: Metadata unchanged. Rerouted [UID:0002CR][0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor](by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md) from direct file owner/emitter to this class at `88/91` with formal `FittingRoomDialog::~FittingRoomDialog()` C++. Preserved B004 MCP session `dbe126a4` facts for range/size, successor `0x0041d580`, vtable labels `0x0060da68`/`0x0060dac8`/`0x0060daf8`, adjustor thunks `0x0041d455`/`0x0041d460`, no ordinary direct callers, raw `0x0041c250` no-function/no-xref evidence, generated empty-marker resolution, and compiler/member/base lowering exclusions.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (000050)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The complete position-5 dialog declaration is installed with direct project headers, exact 0x7ac field order, singleton declaration, and narrow FittingRoomListPane friendship. Former incomplete-layout conclusions are superseded.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-063 | 000051 | The implemented callback maps every standard/platform/JsonCpp identifier in UID000051 and every direct project identifier used by UID000050/UID000053 to an evidence-backed declaration owner plus an explicit companion-header or verified destination, including Event, Region, EPFTileContext, ImageLib/resource lookup, ItemObjImageLib, Surface, UserPane, and geometry/GrafPort APIs; executable import-dispatch slots remain linker lowering. All destinations are scoped-validated and command16927 textually generated the declaration closure; no full product compile is claimed. | Strong | Full identifier inventory, exact dependency formals, scoped validator results, API-child/source-root evidence, and command16927 readback. | UID000051/UID000050/UID000053 formals plus all dependency owner/source-placement destinations. | incorporate | implemented-verified |
| C2E6-071 | 000050 | UID000050 now carries the exact position-5 `0x7ac` declaration from this report: direct project headers, complete method inventory, two 68-byte appearance blocks, embedded 0x280 item state, category/list fields, version string, request pointer, size guard, singleton declaration, and narrow `FittingRoomListPane` friendship before UID000053 position 10. | Strong | Exact base boundary and field offsets/sizes, constructor/sibling consumers, UID0002DI/UID0002DL/UID0002DN direct access, scoped validation, and command16927 class/source ordering. | UID000050 formal/prose/metadata, UID000053/UID0000JE source-order notes. | incorporate | implemented-verified |
| C2E6-075 | 00009S | Dialog `+0x49e` is base appearance `+0x22`, the already-declared ObjectStatusBlob union member `m_compositionMode`/`m_posture`; fitting-room preview semantics use `m_compositionMode`, not invented `previewPartMode`. | Certain | UID000050 layout, UID00009S exact 68-byte formal, UID0002DI/UID0002DN offsets, NewHuman composition consumers. | UID0002DI/UID0002DN formals and FittingRoom/ObjectStatusBlob cross-reference prose; no UID00009S formal change. | reject-invalid | implemented |
| C2E6-079 | 000050 | The complete dialog formal uses `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, and same-directory `CashShopRequest.h`; UID0000IT/UID0000M6 are explicit callback destinations for the first two companion-header paths, while UID0000I0 already documents the third. Current autogen is not misrepresented as having materialized them. | Strong | Current by-file/class source roots, exact complete class declaration owners, and UID0000I0 Proposed Placement. | UID000050 formal/dependency prose; UID0000IT/UID0000M6/UID0000I0 source-package support. | incorporate | implemented |
| C2E6-085 | 0000I0 | `NexusTK/cashshop/CashShopRequest.h` is already explicitly documented by UID0000I0 and backed by complete UID00001H; FittingRoom's same-directory include consumes that route without another declaration. | Strong | UID0000I0 Proposed Placement and UID00001H complete formal. | UID000050 dependency evidence; no ordinary UID0000I0 change. | already-present | implemented |
