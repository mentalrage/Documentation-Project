** TARGET-REPORT-UID:0002CP **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 FittingRoomDialog Core Source-Quality Report

Assignment id: `B003-goal2-fittingroom-dialog-core-source-quality-0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-20260618`

Targets:

- [UID:0002CP] `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`
- [UID:0002CQ] `by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md`
- [UID:0002CS] `by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md`
- [UID:0002CU] `by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md`
- [UID:0002CV] `by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md`
- [UID:0002CX] `by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md`

## Evidence Checked

- Read the current B-agent workflow files: `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B003/goal.md`, and `tools/leaser/Agents/Agent-B003/notes.md`.
- Read current target pages for [UID:0002CP], [UID:0002CQ], [UID:0002CS], [UID:0002CU], [UID:0002CV], and [UID:0002CX]. All six are currently `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JE`, `EMITTER_UIDS:0000JE`, with blank formal C++.
- Read support pages [UID:000050] `by-class/FittingRoomDialog.md`, [UID:0000JE] `by-file/FittingRoom.md`, [UID:0000WR] `FittingRoomUiCore`, [UID:000051] `FittingRoomDialogItemState`, [UID:000053] `FittingRoomListPane`, [UID:000054] `FittingRoomScrollPane`, [UID:000055] `FittingRoomTextButtonControlPane`, [UID:000056] `FittingRoomUserImageControlPane`, [UID:00004Z] `FittingEquipmentState`, [UID:00006T] `ItemCatalog`, [UID:00028I] `g_pFittingRoomDialog`, [UID:0002CT] `FittingRoomDialogHandleFittingAction`, [UID:0002CW] `FittingRoomControlBounds`, [UID:0002CY] `CompareEquipmentNames`, [UID:0002D0] `ClearFittingRoomDialogGlobal`, [UID:0002CR] `FittingRoomDialogScalarDeletingDestructor`, [UID:00012S] `DialogControlPaneHelpers`, [UID:00012R] `DialogPane`, [UID:0000A2] `Pane`, [UID:000038] `ControlPane`, [UID:00029M] `MainUiLayerSlotsHead`, and fitting-room read-only/vtable pages.
- Checked executed B003 FittingRoomListPane reports. Those reports have already promoted `FittingRoomListPane` support details into active docs: scroll fields `+0x108/+0x10a/+0x10c/+0x11c`, `m_scrollPane` at list `+0x11c`, `ResetScrollPosition`, child `Pane::GetScreenBounds`/`SetBounds`/`AddToLayer`/`Invalidate`, EventMan types, selected-entry vector layout, and first-draft C++ readiness for the list pane children.
- Checked B001-incorporated `FittingRoomDialogItemState` support: `m_catalogVersion` at item-state `+0x000`, `m_cacheFilePath[MAX_PATH]` at `+0x018`, `m_categoryLookup` at `+0x220`, `m_equipmentEntries` vector at `+0x240/+0x244/+0x248`, `m_cacheLoaded` at `+0x24c`, `m_encodeKey` at `+0x250`, and `m_decodeKey` at `+0x268`. Category entries are `0xc0` bytes; part records are packed 6-byte records.
- Performed a read-only section-mapped PE byte/vtable check against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`. The fixed section map reports `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, and `.data 0x0066d000-0x0069ce24`.
- Vtable bytes from the PE confirm `FittingRoomDialog` primary table at `0x0060da68`: `+0x00 -> 0x0041d490` scalar deleting destructor, `+0x0c -> 0x004b8e20`, `+0x14 -> 0x00544730` (`Pane::Show`), `+0x20 -> 0x00544800` (`Pane::InvalidateRect`), `+0x2c -> 0x00544bd0`, `+0x30 -> 0x0049dfd0`, `+0x38 -> 0x0049e1c0`, `+0x3c -> 0x0049e190`, `+0x44 -> 0x0041c5e0` [UID:0002CS], `+0x48 -> 0x0041c310` [UID:0002CQ], and `+0x60 -> 0x0041d455` adjustor thunk.
- Vtable bytes confirm `FittingRoomListPane` primary table at `0x0060dd10`: `+0x14 -> 0x00544730` (`Pane::Show`), `+0x20 -> 0x00544800` (`Pane::InvalidateRect`), `+0x44 -> 0x0041f2b0` (`OnPaint`), `+0x48 -> 0x00494b80` (`ControlPane::SetVisualState`), `+0x4c -> 0x00494bb0` (`ControlPane::SetVisibleFlag`), `+0x50 -> 0x00494bd0` (`ControlPane::ClearVisibleFlag`), and EventHandler entry `+0x6c -> 0x0041fcd0`. This resolves [UID:0002CU]'s previous open list-child slot question: it calls `ControlPane::SetVisibleFlag` and then `Pane::Show`, not `ResetScrollPosition`.
- Vtable bytes confirm `FittingRoomTextButtonControlPane` primary table at `0x0060dfd4` includes the inherited state helpers `0x00494b80/0x00494bb0/0x00494bd0/0x00494c00/0x00494c10/0x00494c30`, draw virtual `0x00424080`, and fitting-room text-button selected-state helper `0x00424260` in nearby support docs.
- Checked active generated reports:
  - `project-level/-auto-completion-stats.md` rows 113-118 show all six target pages at `84/90`, average `87.0`.
  - `auto-generated/-ag-memory-coverage.md` rows 211-218 currently route all six directly through owner/emitter `0000JE` to `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.
  - `by-memory/-coverage-report.md` rows 144-151 list all six at `84% : strong`.

## Heuristic / Inference Reanalysis And Validation

### Source placement and owner/emitter route

Best current placement: all six targets are `FittingRoomDialog` class methods and should use [UID:000050] as `CANONICAL_OWNER` and `EMITTER_UIDS`. [UID:000050] itself routes to [UID:0000JE] `FittingRoom`, so generated source still lands in `NexusTK/cashshop/FittingRoom.cpp`. This is a semantic owner repair, not a source-file move.

Evidence:

- Each target page already describes the natural class owner as [UID:000050] and the source file as [UID:0000JE], but the metadata still points directly at the file.
- [UID:0002CQ] and [UID:0002CS] are primary `FittingRoomDialog` vtable slots at `0x0060dab0` and `0x0060daac`.
- [UID:0002CP] installs `FittingRoomDialog` primary/secondary/tertiary vtables and writes `g_pFittingRoomDialog`.
- [UID:0002CU], [UID:0002CV], and [UID:0002CX] are ordinary class helpers with direct callers inside the dialog class cluster.
- [UID:000050] is already above the owner gate at `85/88`, so no bypass to file-level owner is needed.

Rejected alternatives:

- Direct [UID:0000JE] ownership is now stale. `FittingRoom.cpp` remains the file emitter but is too broad as canonical owner for class methods with a stable direct class page.
- `DialogPane`, `Pane`, `ControlPane`, `TimerHandler`, `FittingRoomListPane`, and `FittingRoomTextButtonControlPane` ownership is rejected. They provide inherited helper functions and child controls, but the decision logic, offsets, child ids, command cases, and vtable slots are dialog-owned.
- [UID:0000WR] `FittingRoomUiCore` is a broad range/container, not the direct source owner for these exact methods.

Impact: set `CANONICAL_OWNER:000050` and `EMITTER_UIDS:000050` on all six targets. Generated reports should still show final path `auto-generated/NexusTK/cashshop/FittingRoom.cpp` through the class-to-file route.

### Dialog field/type reanalysis

Recommended field names and roles:

| Offset | Best source-facing role | Evidence and caveats |
| ---: | --- | --- |
| `+0x1fc` | `m_controlManager` / `m_controls` | Dialog control container used by constructor attach helper, `OnCommand`, `ShowPreview`, `RebuildCategoryButtons`, and `SelectButton`; virtual slot `+0x10` is a child lookup by command/control id. |
| `+0x47c` | `m_baseAppearance` / `m_currentAppearance` | Constructor and `OnCommand` copy a 68-byte appearance snapshot from `g_pCollectionData + 0x13eb40`; `OnCommand` Basic/Current paths normalize or clear fields here before mirroring. |
| `+0x4c0` | `m_previewAppearance` | Mirrored from `+0x47c`; preview/user-image/list paths consume this as the working appearance block. |
| `+0x49e` | `m_previewPartMode` / `m_specialPreviewMode` | Constructor clears it, Basic/Current reset paths clear or normalize it, `ResetScrollPosition` clears it for non-category-3 and sets it to `3` when a selected-entry first dword equals `3`; list input reports document preview side effects for special/set preview fields. Exact original enum name is not recoverable yet. |
| `+0x4a4`, `+0x4e8` | appearance byte initialized to `0x50` | Constructor writes `0x50` in both appearance blocks. Current evidence supports role but not original member spelling. |
| `+0x4e2` | mirrored appearance option byte | Constructor clears it in preview block. |
| `+0x504` | `m_itemState` | Embedded [UID:000051] `FittingRoomDialogItemState`; constructor/destructor and item-state pages confirm field layout and method use. |
| `+0x744/+0x748` | selected/cart item-entry vector begin/end | Executed list-pane reports identify the vector and `0xb4` entry layout; [UID:0002DI] loops it for category-3 side effects. |
| `+0x784` | `m_activeCategory` / `m_activeCategoryOrdinal` | `OnCommand` cases 7-16 store `1..10`; list pane paint/input/update paths read this active category. |
| `+0x788` | `m_selectedCategoryCommandId` | Constructor initializes `-1`; `SelectButton` treats it as signed command/control id, looks up old button if positive, stores incoming id unconditionally. It is not a pointer. The current constructor doc wording "active selection-button pointer" should be corrected. |
| `+0x78c` | cleared reserved/list-side field | Constructor clears it. No strong use in the six current targets; leave as reserved/unresolved and do not inflate score for it. |
| `+0x790` | cached/current equipment name string | `HandleFittingAction` compares it to the item-state current name; destructor releases it if heap-backed. |
| `+0x7a8` | pending catalog/version request pointer/status | Constructor clears it; `HandleFittingAction` polls it; destructor releases it. |
| `+0xa4` | embedded `TimerHandler`/action facet | Constructor installs tertiary vtable and schedules action `0` through `TimerHandler`; [UID:0002CT] is the timer/action callback. |

Rejected field alternatives:

- `+0x788` as a selected-button pointer is rejected because [UID:0002CX] compares the stored dword to zero as an id, passes it to child lookup slot `+0x10`, then overwrites it with the incoming command id. No pointer dereference of `+0x788` occurs in the target.
- Treating `+0x504` as standalone `ItemCatalog` ownership is rejected. The active support docs identify the item-state-owned category lookup and `ItemCatalog` facade; dialog code passes the embedded state object.
- Treating `+0x49e` as a simple boolean is rejected. It carries at least clear/zero and value `3` semantics tied to category/set preview behavior.

Impact: the unresolved appearance subfield spellings and `+0x78c` cap [UID:0002CP]/[UID:0002CQ] below the mid-90s, but do not block current-code-gate first-draft C++.

### Helper and virtual-slot names

Recommended names:

- `0x0041d150`: `GetFittingRoomControlBounds` or `LoadFittingRoomControlBounds`. Use `GetFittingRoomControlBounds` in first-draft code; existing support page title can remain `FittingRoomControlBounds`.
- `0x0049dc10`: `DialogPaneEnsureControlManagerAndAdd` / source-facing `AddControl`. It lazily creates/accesses the dialog control manager and attaches the child control.
- Dialog control-manager virtual slot `+0x10`: `FindControlById` / `GetControlById`.
- `0x0049dd00`: `DialogCategorySwitch`. In [UID:0002CV] it selects/removes/replaces the old entry for command id `7` before rebuilding category buttons.
- `0x00424550`: `FittingRoomUserImageControlPane::AdvanceFacingDirection`.
- `0x00424570`: `FittingRoomUserImageControlPane::RetreatFacingDirection`.
- `0x0041d5e0`: `FittingEquipmentStateResetEntries` / source-facing `m_itemState.ResetEquipmentEntries()`.
- `0x00424260`: `FittingRoomTextButtonControlPane::SetSelected` / `SetSelectedState`.
- `0x00494bb0`: `ControlPane::SetVisibleFlag`. [UID:0002CU] calls this on the list child through vtable slot `+0x4c`.
- `0x00544730`: `Pane::Show`. [UID:0002CU] calls this on the same list child through vtable slot `+0x14`.
- Dialog primary vtable slot `+0x20`: `Pane::InvalidateRect`.
- Dialog primary vtable slot `+0x30`: `DialogPane::Show` / `DialogPane::ShowInLayer`. Use descriptive `ShowInLayer` in first-draft C++ because [UID:0002CU] passes a rectangle, flags, and `0x0069b36c`.
- Dialog primary vtable slot `+0x38`: `DialogPane` refresh/update hook. Existing DialogPane docs do not give a final source name; use `RefreshDialogStateForDisplay()` as a descriptive placeholder in first-draft C++ and record the slot target `0x0049e1c0`.
- `0x005975e0`: `TimerHandler::ScheduleTimer` wrapper. Constructor schedules action `0`, interval/value `100`.

Rejected stale helper interpretations:

- [UID:0002CU]'s child slot `+0x4c` is not `FittingRoomListPane::ResetScrollPosition`; the PE vtable maps `+0x4c` to `0x00494bb0`, the base `ControlPaneSetVisibleFlag`. `ResetScrollPosition` at `0x0041f100` has no vtable pointer and is directly called by [UID:0002CQ].
- `MainUiLayerSlotsHead + 8` / `0x0069b36c` should not be named `g_pMainMenuPane`. Active docs identify it as a main UI layer/context slot.

### Target-specific validation and C++ readiness

[UID:0002CP] `FittingRoomDialogConstructor`

- Validated current behavior: base `DialogPane` construction with empty title, vtable triad stores, singleton write to `g_pFittingRoomDialog`, embedded item-state construction, two appearance-block copies from `g_pCollectionData`, child-control construction, dialog show/setup, cash-shop version request `10002`, and timer action `0` at `100`.
- Source-facing child-control roles:
  - command/control id `0`: close/control button bounds.
  - child id `1`: `FittingRoomUserImageControlPane`.
  - child id `2`: `FittingRoomListPane`.
  - child ids `3` and `4`: generic rotate/utility buttons with command ids `44` and `45`.
  - child ids `5` and `6`: text buttons `Basic` and `Current`.
  - temporary child/control id `7`: download/progress control using download-control vtables, later removed/replaced by [UID:0002CV] when catalog data is ready.
- Current doc table should clarify that duplicate "bounds id 2" is a bounds/content-area reuse, not a second list child. The progress control is addressable as child id `7` by [UID:0002CT].
- C++ readiness: yes. Missing exact generic button constructor names and EH cleanup funclets are confidence caps, not blockers.

[UID:0002CQ] `FittingRoomDialogOnCommand`

- Validated command map: `0` deferred close, `1`/`2` no-op, `3`/`4` preview facing direction, `5` Basic reset, `6` Current reset, `7..16` category selection ordinals `1..10`.
- The common refresh path retrieves child id `2` and calls `FittingRoomListPane::ResetScrollPosition` at `0x0041f100`.
- The Basic path normalizes several packed appearance/display fields; exact original field spellings are still unresolved. Descriptive helper names are acceptable in first-draft C++ because the source behavior and offsets are proven.
- C++ readiness: yes. The old blank-C++ reason used a stale `95/95` threshold; current average score already clears the active gate, and this report resolves the open source names enough for role-based C++.

[UID:0002CS] `FittingRoomDialogDrawBackground`

- Validated vtable-only dispatch from primary slot `+0x44`, no direct callers, resources `WBOARDBK.EPF`/`.PAL` and `WEBBOARD.EPF`/`.PAL`, center inset `(left+11, top+42, right-11, bottom-40)`, center tile frame `0`, and WEBBOARD frame pieces `1,6,3,4,0,2,5,7`.
- The draw helper stack is generic `EPFTileContext`, `ResourceLayoutTableLookupLayoutEntry`, `GrafPortDrawStateAccessors`, `SurfacePaintHelpers::RenderTileFrame`, and `RectGeometryHelpers`.
- C++ readiness: yes. Exact names for draw-state temporary helpers are generic support issues; the target's source shape is stable.

[UID:0002CU] `FittingRoomDialogShowPreview`

- Validated single direct caller from [UID:0002CT] after successful catalog load/save.
- Resolved previous virtual-slot blocker:
  - dialog slot `+0x38`: inherited `DialogPane` refresh/update hook at `0x0049e1c0`.
  - child id `2`: `FittingRoomListPane`.
  - child slot `+0x4c`: `ControlPane::SetVisibleFlag`.
  - child slot `+0x14`: `Pane::Show`.
  - dialog slot `+0x30`: `DialogPane::ShowInLayer`/show route at `0x0049dfd0`.
- Validated rectangle helper parameters are left/top/width/height `(102, 134, 820, 500)`, producing bounds `(102, 134, 922, 634)`.
- C++ readiness: yes. Use descriptive `RefreshDialogStateForDisplay` for unresolved dialog slot `+0x38`, with the exact slot target recorded.

[UID:0002CV] `FittingRoomDialogRebuildCategoryButtons`

- Validated single direct caller from [UID:0002CU], old child/control id `7` removal via `DialogCategorySwitch`, ten `FittingRoomTextButtonControlPane` allocations of `0x114` bytes, command ids `7..16`, and labels `UsableItems`, `Weapons`, `Mounts`, `Face`, `Head`, `Mantle`, `Necklaces`, `Coats`, `Shoes`, `SpecialtySets`.
- The default-selection test calls item-catalog lookup/count on the embedded item state with category `0`; if signed count is not positive, it selects command `7` and stores `+0x788 = 7`.
- A table-driven source expression is recommended even though the binary is unrolled. The table is source-equivalent and preserves all command ids/labels/bounds calls.
- C++ readiness: yes. Original table-vs-unrolled spelling remains a source-form caveat but not a blocker.

[UID:0002CX] `FittingRoomDialogSelectButton`

- Validated ten direct callers from [UID:0002CQ] cases `7..16`.
- Resolved field name: `+0x788` is selected category command id, not a pointer.
- Helper semantics: lookup old/new controls via `m_controlManager->FindControlById`, call `FittingRoomTextButtonControlPane::SetSelected(false/true)`, invalidate old/new via `Pane::InvalidateRect`.
- C++ readiness: yes. This is the cleanest target in the cluster; raise above the others.

## Recommended Metadata And Score Changes

| UID | Current | Recommended | Owner/emitter | Reason |
| --- | --- | --- | --- | --- |
| `0002CP` | `84/90`, owner/emitter `0000JE` | `86/91` | `000050` / `000050` | Class owner route resolved; constructor field/child/control setup is source-ready, with remaining caps from generic button constructor names and EH cleanup mapping. |
| `0002CQ` | `84/90`, owner/emitter `0000JE` | `87/91` | `000050` / `000050` | Command map, category ids, reset paths, child refresh, and helper names are source-quality; appearance subfield spellings remain a cap. |
| `0002CS` | `84/90`, owner/emitter `0000JE` | `87/91` | `000050` / `000050` | Resource/frame semantics and vtable placement are exact; generic draw-state helper spellings remain a cap. |
| `0002CU` | `84/90`, owner/emitter `0000JE` | `87/91` | `000050` / `000050` | List-child slot identities are resolved as `ControlPane::SetVisibleFlag` and `Pane::Show`; main-layer show route is stable. |
| `0002CV` | `84/90`, owner/emitter `0000JE` | `87/91` | `000050` / `000050` | Category labels, ids, default selection, old-control removal, and text-button helper names are source-ready. |
| `0002CX` | `84/90`, owner/emitter `0000JE` | `88/92` | `000050` / `000050` | Simple direct helper with exact callers, field role, lookup, selected-state setter, and invalidation behavior. |

Do not raise any of these to `95+`. Exact original names for some appearance subfields, generic constructor overloads, and dialog refresh slot spelling are not recoverable from the current binary evidence.

Support-doc score changes are optional. [UID:000050] already clears the direct-owner gate. If the supervisor wants a class-page score sync after incorporating these six children, `FittingRoomDialog` can reasonably move from `85/88` to `87/89`; however, this is not required for these target owner/emitter changes because the parent already clears the gate.

## First-Draft C++ Recommendation

Populate formal C++ for all six targets. All six are reconstructable, now have a nonblank class emitter route, and exceed the active `(COMPLETION + CONFIDENCE) / 2 > 85` gate after the recommended score/metadata changes. The following uses source-facing descriptive names where exact original spellings are not recoverable. Those names should be kept consistent with the support docs.

Shared declarations for context:

```cpp
enum FittingRoomDialogCommand {
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
    kFittingRoomCommandSpecialtySets = 16,
};

static int FittingRoomCategoryFromCommand(int commandId)
{
    return commandId - kFittingRoomCommandBasic;
}

struct FittingRoomCategoryButtonDef {
    int commandId;
    const wchar_t* label;
};
```

[UID:0002CP] recommended first-draft C++:

```cpp
FittingRoomDialog::FittingRoomDialog()
    : DialogPane(L""),
      m_itemState(),
      m_activeCategory(0),
      m_selectedCategoryCommandId(-1),
      m_reservedCategoryState(0),
      m_cachedEquipmentName(),
      m_pendingCatalogRequest(NULL)
{
    g_pFittingRoomDialog = this;

    CopyCollectionAppearance(&m_baseAppearance, g_pCollectionData, 0x13eb40, 0x44);
    CopyCollectionAppearance(&m_previewAppearance, g_pCollectionData, 0x13eb40, 0x44);
    m_baseAppearance.byte28 = 0;
    m_baseAppearance.byte34 = 0x50;
    m_previewAppearance.byte28 = 0;
    m_previewAppearance.byte34 = 0x50;

    RectBounds bounds;
    GetFittingRoomControlBounds(0, &bounds);
    AddControl(new ButtonControlPane(14, &bounds));

    GetFittingRoomControlBounds(1, &bounds);
    AddControl(new FittingRoomUserImageControlPane(&bounds, &m_baseAppearance));

    GetFittingRoomControlBounds(2, &bounds);
    FittingRoomListPane* listPane = new FittingRoomListPane(&bounds);
    listPane->SetVisibleFlag();
    listPane->Show();
    AddControl(listPane);

    GetFittingRoomControlBounds(3, &bounds);
    AddControl(new ButtonControlPane(44, &bounds));

    GetFittingRoomControlBounds(4, &bounds);
    AddControl(new ButtonControlPane(45, &bounds));

    GetFittingRoomControlBounds(5, &bounds);
    AddControl(new FittingRoomTextButtonControlPane(kFittingRoomCommandBasic, L"Basic", &bounds));

    GetFittingRoomControlBounds(6, &bounds);
    AddControl(new FittingRoomTextButtonControlPane(kFittingRoomCommandCurrent, L"Current", &bounds));

    GetFittingRoomControlBounds(2, &bounds);
    FittingRoomDownloadControlPane* downloadPane = new FittingRoomDownloadControlPane(7, &bounds);
    downloadPane->SetProgressPercent(0);
    AddControl(downloadPane);

    RectBounds dialogRect;
    InitRectBounds(&dialogRect, 102, 134, 820, 500);
    SetDialogResourceName(L"USERLOOK.EPF");
    ShowInLayer(&dialogRect, 0, 0, g_mainUiLayerSlots[2]);
    InitializeDialogControls();
    EnableDialogInput();
    ActivateDialog();

    SubmitCashShopVersionRequest(g_pCashShopRequest, 10002);
    m_timerHandler.ScheduleTimer(0, 100, 0, 0);
}
```

[UID:0002CQ] recommended first-draft C++:

```cpp
void FittingRoomDialog::OnCommand(int commandId)
{
    switch (commandId) {
    case kFittingRoomCommandClose:
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return;

    case kFittingRoomCommandRotateRight: {
        FittingRoomUserImageControlPane* pane =
            static_cast<FittingRoomUserImageControlPane*>(m_controlManager->FindControlById(1));
        if (pane != NULL)
            pane->AdvanceFacingDirection();
        return;
    }

    case kFittingRoomCommandRotateLeft: {
        FittingRoomUserImageControlPane* pane =
            static_cast<FittingRoomUserImageControlPane*>(m_controlManager->FindControlById(1));
        if (pane != NULL)
            pane->RetreatFacingDirection();
        return;
    }

    case kFittingRoomCommandBasic:
        CopyCollectionAppearance(&m_baseAppearance, g_pCollectionData, 0x13eb40, 0x44);
        NormalizeBasicFittingAppearance(&m_baseAppearance);
        m_previewAppearance = m_baseAppearance;
        m_itemState.ResetEquipmentEntries();
        break;

    case kFittingRoomCommandCurrent:
        CopyCollectionAppearance(&m_baseAppearance, g_pCollectionData, 0x13eb40, 0x44);
        m_baseAppearance.previewPartMode = 0;
        m_previewAppearance = m_baseAppearance;
        m_itemState.ResetEquipmentEntries();
        break;

    case kFittingRoomCommandUsableItems:
    case kFittingRoomCommandWeapons:
    case kFittingRoomCommandMounts:
    case kFittingRoomCommandFace:
    case kFittingRoomCommandHead:
    case kFittingRoomCommandMantle:
    case kFittingRoomCommandNecklaces:
    case kFittingRoomCommandCoats:
    case kFittingRoomCommandShoes:
    case kFittingRoomCommandSpecialtySets:
        SelectButton(commandId);
        m_activeCategory = FittingRoomCategoryFromCommand(commandId);
        break;

    default:
        return;
    }

    FittingRoomListPane* listPane =
        static_cast<FittingRoomListPane*>(m_controlManager->FindControlById(2));
    if (listPane != NULL)
        listPane->ResetScrollPosition();
}
```

[UID:0002CS] recommended first-draft C++:

```cpp
void FittingRoomDialog::DrawBackground()
{
    RectBounds content;
    content.left = m_bounds.left + 11;
    content.top = m_bounds.top + 42;
    content.right = m_bounds.right - 11;
    content.bottom = m_bounds.bottom - 40;

    EPFTileContext tile;
    tile.Open(L"WBOARDBK.EPF");
    const ResourceFrame* centerFrame = LookupResourceFrame(&tile, 0);

    DrawState savedState;
    SaveGrafPortDrawState(&savedState);
    SetGrafPortClipRect(&content);

    if (centerFrame != NULL && centerFrame->width > 0 && centerFrame->height > 0) {
        for (int y = content.top; y < content.bottom; y += centerFrame->height) {
            for (int x = content.left; x < content.right; x += centerFrame->width) {
                RectBounds tileRect;
                InitRectLTRB(&tileRect, x, y, x + centerFrame->width, y + centerFrame->height);
                RenderTileFrame(&tile, 0, L"WBOARDBK.PAL", &tileRect);
            }
        }
    }

    RestoreGrafPortDrawState(&savedState);
    tile.Close();

    EPFTileContext frame;
    frame.Open(L"WEBBOARD.EPF");

    const int width = m_bounds.right - m_bounds.left;
    const int height = m_bounds.bottom - m_bounds.top;

    for (int x = 37; x < width - 37; x += 37) {
        DrawResourceFrame(&frame, 1, L"WEBBOARD.PAL", x, 0, 37, 42);
        DrawResourceFrame(&frame, 6, L"WEBBOARD.PAL", x, height - 40, 37, 40);
    }

    for (int y = 42; y < height - 40; y += 40) {
        DrawResourceFrame(&frame, 3, L"WEBBOARD.PAL", 0, y, 11, 40);
        DrawResourceFrame(&frame, 4, L"WEBBOARD.PAL", width - 11, y, 11, 40);
    }

    DrawResourceFrame(&frame, 0, L"WEBBOARD.PAL", 0, 0, 37, 42);
    DrawResourceFrame(&frame, 2, L"WEBBOARD.PAL", width - 37, 0, 37, 42);
    DrawResourceFrame(&frame, 5, L"WEBBOARD.PAL", 0, height - 40, 37, 40);
    DrawResourceFrame(&frame, 7, L"WEBBOARD.PAL", width - 37, height - 40, 37, 40);

    frame.Close();
}
```

[UID:0002CU] recommended first-draft C++:

```cpp
int FittingRoomDialog::ShowPreview()
{
    RefreshDialogStateForDisplay();
    RebuildCategoryButtons();

    FittingRoomListPane* listPane =
        static_cast<FittingRoomListPane*>(m_controlManager->FindControlById(2));
    if (listPane != NULL) {
        listPane->SetVisibleFlag();
        listPane->Show();
    }

    RectBounds dialogRect;
    InitRectBounds(&dialogRect, 102, 134, 820, 500);
    return ShowInLayer(&dialogRect, 0, 0, g_mainUiLayerSlots[2]);
}
```

[UID:0002CV] recommended first-draft C++:

```cpp
void FittingRoomDialog::RebuildCategoryButtons()
{
    static const FittingRoomCategoryButtonDef kButtons[] = {
        { kFittingRoomCommandUsableItems, L"UsableItems" },
        { kFittingRoomCommandWeapons, L"Weapons" },
        { kFittingRoomCommandMounts, L"Mounts" },
        { kFittingRoomCommandFace, L"Face" },
        { kFittingRoomCommandHead, L"Head" },
        { kFittingRoomCommandMantle, L"Mantle" },
        { kFittingRoomCommandNecklaces, L"Necklaces" },
        { kFittingRoomCommandCoats, L"Coats" },
        { kFittingRoomCommandShoes, L"Shoes" },
        { kFittingRoomCommandSpecialtySets, L"SpecialtySets" },
    };

    ControlPane* oldFirstButton = m_controlManager->FindControlById(kFittingRoomCommandUsableItems);
    if (oldFirstButton != NULL) {
        ControlPane* removed = DialogCategorySwitch(this, kFittingRoomCommandUsableItems);
        if (removed != NULL)
            removed->Release(true);
    }

    for (unsigned int i = 0; i < sizeof(kButtons) / sizeof(kButtons[0]); ++i) {
        RectBounds bounds;
        GetFittingRoomControlBounds(kButtons[i].commandId, &bounds);

        FittingRoomTextButtonControlPane* button =
            new FittingRoomTextButtonControlPane(kButtons[i].commandId, kButtons[i].label, &bounds);
        AddControl(button);

        if (i == 0 && m_itemState.GetItemCount(0) <= 0) {
            button->SetSelected(true);
            m_selectedCategoryCommandId = kFittingRoomCommandUsableItems;
        }
    }

    InvalidateRect(&m_bounds);
}
```

[UID:0002CX] recommended first-draft C++:

```cpp
void FittingRoomDialog::SelectButton(int commandId)
{
    FittingRoomTextButtonControlPane* oldButton = NULL;
    FittingRoomTextButtonControlPane* newButton = NULL;

    if (m_selectedCategoryCommandId > 0) {
        oldButton = static_cast<FittingRoomTextButtonControlPane*>(
            m_controlManager->FindControlById(m_selectedCategoryCommandId));
    }

    if (commandId > 0) {
        newButton = static_cast<FittingRoomTextButtonControlPane*>(
            m_controlManager->FindControlById(commandId));
    }

    m_selectedCategoryCommandId = commandId;

    if (oldButton != NULL) {
        oldButton->SetSelected(false);
        oldButton->InvalidateRect(NULL);
    }

    if (newButton != NULL) {
        newButton->SetSelected(true);
        newButton->InvalidateRect(NULL);
    }
}
```

## Exact Supervisor Changes Required

### Target metadata

Replace the metadata headers on each target as follows:

```text
[UID:0002CP]
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

[UID:0002CQ]
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

[UID:0002CS]
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

[UID:0002CU]
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

[UID:0002CV]
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

[UID:0002CX]
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000050 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target body updates

Apply these text changes to [UID:0002CP]:

- In the `Dialog State` table, replace the row for `+0x784`, `+0x788`, and `+0x78c` with:

```text
| dialog offsets `+0x784`, `+0x788`, `+0x78c` | Initializes active/list state to `0`, selected category command id to `-1`, and a reserved/list-side dword to `0`. Later paths use `+0x784` as the active fitting-room category ordinal and `+0x788` as the selected category command/control id; `+0x788` is not a button pointer. |
```

- In the child construction notes, clarify the download control row:

```text
| content/list bounds, child id `7` | [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md), `0x10c` bytes, with base control type `8`, three download-control vtables, and progress word at child offset `+0x108` cleared. It is the temporary child id `7` consumed by [UID:0002CT] before [UID:0002CV] replaces that id with the first category button. |
```

- Replace the blank-C++ reconstruction note with:

```text
Current source-quality reanalysis clears the active first-draft C++ gate. Formal C++ should be populated as a `FittingRoomDialog` constructor under [UID:000050], emitting through [UID:0000JE]. Remaining limitations are exact generic button constructor spelling, exact appearance subfield names, and compiler EH cleanup funclets; these cap the score but do not block first-draft C++.
```

Apply these text changes to [UID:0002CQ]:

- Add to `State Notes`:

```text
- Dialog offset `+0x788` is a selected category command/control id, not a pointer. [UID:0002CX] uses it only as an id for child lookup and overwrites it with the incoming command id.
- The common category/appearance refresh path retrieves child id `2`, the [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), and calls [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md).
```

- Replace stale blank-C++ language with:

```text
Current source-quality reanalysis clears the active first-draft C++ gate. Formal C++ should express this as a normal `switch` over command ids `0..16`. Exact original spellings for packed appearance subfields remain unresolved but are acceptable as descriptive helper/member names in first-draft C++.
```

Apply these text changes to [UID:0002CS]:

- Replace stale `95/95` wording in `Reconstruction Notes` with:

```text
Current source-quality reanalysis clears the active first-draft C++ gate. Formal C++ should be populated as a `FittingRoomDialog` primary virtual draw method using resource constants for `WBOARDBK` and `WEBBOARD`, with two phases: center tiling, then frame strips/corners. Generic draw-state helper names remain support-level confidence caps only.
```

Apply these text changes to [UID:0002CU]:

- Replace the list-child slot entries in `Call Sequence`:

```text
| 4 | Show list child | Virtual slot `+0x4c` on the returned [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), resolved by PE vtable bytes as inherited [UID:000038][ControlPane](by-class/ControlPane.md) `ControlPane::SetVisibleFlag` at `0x00494bb0`. |
| 5 | Apply pane show/update | Virtual slot `+0x14` on the same child, resolved by [UID:0000A2][Pane](by-class/Pane.md) / [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) as `Pane::Show` at `0x00544730`. |
```

- Add to `Reconstruction Notes`:

```text
The former unresolved list-child slot blocker is resolved: this method does not call `FittingRoomListPane::ResetScrollPosition`. It calls inherited `ControlPane::SetVisibleFlag` and `Pane::Show` on child id `2`, then shows the dialog through the main layer/context at `0x0069b36c`.
```

Apply these text changes to [UID:0002CV]:

- Add after `Category Buttons`:

```text
Source reconstruction may use a static table of `{ commandId, label }` entries even though the binary body is unrolled. The table form preserves all proven source facts and leaves the compiler free to regenerate an equivalent unrolled or EH-cleanup-heavy body. The first child id `7` replaces the temporary download/progress control installed by the constructor.
```

- Replace stale blank-C++ language with:

```text
Current source-quality reanalysis clears the active first-draft C++ gate. Formal C++ should be populated using the exact command ids, labels, default-selection test on embedded item-state category `0`, selected-command write at `+0x788`, and final invalidation of dialog bounds `+0x44`.
```

Apply these text changes to [UID:0002CX]:

- Add to `Behavior` or `Reconstruction Notes`:

```text
Dialog offset `+0x788` is confirmed as a selected category command/control id. It is intentionally tolerant of nonpositive incoming ids: old positive selection is cleared, no new lookup is attempted, and the nonpositive value is still stored.
```

- Replace stale blank-C++ language with:

```text
Current source-quality reanalysis clears the active first-draft C++ gate. Formal C++ should be populated as a small `FittingRoomDialog::SelectButton(int commandId)` helper using child lookup, `FittingRoomTextButtonControlPane::SetSelected`, and `Pane::InvalidateRect`.
```

### Support-doc updates

In [UID:000050] `by-class/FittingRoomDialog.md`, update the method table rows for the six target methods to include:

```text
| [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) | constructor | Builds the dialog, writes `g_pFittingRoomDialog`, constructs item state and initial controls, installs a temporary download/progress child id `7`, submits cash-shop version request `10002`, and schedules timer action `0` at `100` ms. |
| [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) | `OnCommand` | Handles close, preview direction, Basic/Current appearance resets, category command ids `7..16`, selected command id `+0x788`, active category `+0x784`, and list reset through child id `2`. |
| [UID:0002CS][0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground](by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md) | `DrawBackground` | Primary draw virtual using `WBOARDBK` center tiling and `WEBBOARD` frame pieces `1/6/3/4/0/2/5/7`. |
| [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md) | `ShowPreview` | Called after item-state load/save; refreshes dialog state, rebuilds category buttons, calls list child `ControlPane::SetVisibleFlag` and `Pane::Show`, then shows the dialog at `(102,134,820,500)` on main layer/context `0x0069b36c`. |
| [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) | `RebuildCategoryButtons` | Removes old child id `7`, creates category text buttons `7..16` (`UsableItems`, `Weapons`, `Mounts`, `Face`, `Head`, `Mantle`, `Necklaces`, `Coats`, `Shoes`, `SpecialtySets`), default-selects id `7` when category `0` count is not positive, and invalidates dialog bounds. |
| [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) | `SelectButton` | Updates selected category command id `+0x788`, toggles old/new `FittingRoomTextButtonControlPane::SetSelected` state, and invalidates changed buttons. |
```

Add this boundary/source-quality note to [UID:000050]:

```text
- 2026-06-18 B003 FittingRoomDialog core source-quality reanalysis: [UID:0002CP]/[UID:0002CQ]/[UID:0002CS]/[UID:0002CU]/[UID:0002CV]/[UID:0002CX] should now attach directly to this class as owner/emitter, with generated output still routed through [UID:0000JE][FittingRoom](by-file/FittingRoom.md). The pass resolves `+0x788` as selected category command id, `+0x784` as active category ordinal, child id `2` as the list pane, temporary child id `7` as the pre-preview download/progress control later replaced by category button id `7`, `ShowPreview` child slot `+0x4c` as `ControlPane::SetVisibleFlag`, and child slot `+0x14` as `Pane::Show`. First-draft C++ is ready for the six target children; remaining class-level caps are exact appearance subfield names, generic button constructor spelling, and final DialogPane refresh-slot naming.
```

In [UID:0000JE] `by-file/FittingRoom.md`, add:

```text
- 2026-06-18 B003 FittingRoomDialog core source-quality reanalysis keeps final source placement in `NexusTK/cashshop/FittingRoom.cpp` but routes the six dialog core method children through [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md) rather than direct file ownership. The report resolves dialog category fields, child ids, list-child show slots, category labels, background resource frame roles, version/request/timer paths, and first-draft C++ readiness for [UID:0002CP]/[UID:0002CQ]/[UID:0002CS]/[UID:0002CU]/[UID:0002CV]/[UID:0002CX].
```

No support-doc update is required for [UID:000038] `ControlPane` or [UID:0000A2] `Pane`; they already document `0x00494bb0` as `ControlPaneSetVisibleFlag` and `0x00544730` as `Pane::Show`.

### Validation commands for supervisor

After applying changes, run:

> Executable block R001 was removed from this report and preserved verbatim in [0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-FittingRoomDialogCore-source-quality-removed.md](0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-FittingRoomDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Coverage Report Replacement Text

Replace the six target rows in `by-memory/-coverage-report.md` with:

```text
        - [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) 0x0041bdd0-0x0041c250 | constructor | FittingRoomDialogConstructor : reconstructable : 86% : very strong : B003 2026-06-18 source-quality reanalysis confirms direct class owner [UID:000050], constructor range/caller/vtable/singleton evidence, item-state construction, appearance-block copies, child-control construction including temporary download/progress child id 7, version request 10002, timer action 0 at 100 ms, corrected selected-command field +0x788, and first-draft C++ readiness with only generic button/EH cleanup/appearance-subfield name caps.
        - [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) 0x0041c310-0x0041c596 | method | FittingRoomDialogOnCommand : reconstructable : 87% : very strong : B003 2026-06-18 source-quality reanalysis confirms direct class owner [UID:000050], primary vtable-only command handler, cases 0..16, deferred close, preview direction helpers, Basic/Current appearance reset paths, category commands 7..16, active category +0x784, selected command id +0x788, list child id 2 ResetScrollPosition call, switch-table boundary, and first-draft C++ readiness with only packed appearance subfield spelling caps.
        - [UID:0002CS][0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground](by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md) 0x0041c5e0-0x0041cb63 | method | FittingRoomDialogDrawBackground : reconstructable : 87% : very strong : B003 2026-06-18 source-quality reanalysis confirms direct class owner [UID:000050], primary draw vtable slot, exact 0x583 boundary, WBOARDBK center tiling, WEBBOARD frame resources, frame-piece indices 1/6/3/4/0/2/5/7, inset rectangle math, generic draw/resource helper ownership, and first-draft C++ readiness.
        - [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md) 0x0041cd40-0x0041cdbf | method | FittingRoomDialogShowPreview : reconstructable : 87% : very strong : B003 2026-06-18 source-quality reanalysis confirms direct class owner [UID:000050], single HandleFittingAction caller, category-button rebuild, child id 2 list-pane lookup, resolved child slot +0x4c as ControlPane::SetVisibleFlag, resolved child slot +0x14 as Pane::Show, fixed left/top/width/height rectangle 102/134/820/500, main layer/context 0x0069b36c show route, and first-draft C++ readiness.
        - [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) 0x0041cdc0-0x0041d14b | method | FittingRoomDialogRebuildCategoryButtons : reconstructable : 87% : very strong : B003 2026-06-18 source-quality reanalysis confirms direct class owner [UID:000050], single ShowPreview caller, old child id 7 replacement, category command ids 7..16, labels UsableItems/Weapons/Mounts/Face/Head/Mantle/Necklaces/Coats/Shoes/SpecialtySets, text-button construction and SetSelected helper, default-selection item-state count test, selected-command +0x788 write, dialog invalidation, and first-draft C++ readiness.
        - [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) 0x0041d2c0-0x0041d335 | method | FittingRoomDialogSelectButton : reconstructable : 88% : very strong : B003 2026-06-18 source-quality reanalysis confirms direct class owner [UID:000050], exact helper bounds, ten OnCommand category callers, selected command/control id +0x788, child-container lookup slot +0x10, FittingRoomTextButtonControlPane::SetSelected calls, old/new Pane::InvalidateRect calls, nonpositive-id tolerance, and first-draft C++ readiness.
```

If the supervisor updates `project-level/-auto-completion-stats.md` manually instead of regenerating it, replace rows 113-118 with:

```text
| `0002CP` | 86 | 91 | 88.5 | `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md` |
| `0002CQ` | 87 | 91 | 89.0 | `by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md` |
| `0002CS` | 87 | 91 | 89.0 | `by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md` |
| `0002CU` | 87 | 91 | 89.0 | `by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md` |
| `0002CV` | 87 | 91 | 89.0 | `by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md` |
| `0002CX` | 88 | 92 | 90.0 | `by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md` |
```

Generated `auto-generated/-ag-memory-coverage.md` should be regenerated rather than hand-edited. Expected route after regeneration: all six rows should show class owner/emitter `000050` while final path remains `auto-generated/NexusTK/cashshop/FittingRoom.cpp` through [UID:000050] -> [UID:0000JE].

## Remaining Blockers

- Exact original member names inside the two 68-byte appearance blocks are not recoverable from current evidence. The report recommends descriptive names (`m_baseAppearance`, `m_previewAppearance`, `m_previewPartMode`, `NormalizeBasicFittingAppearance`) and records exact offsets. This caps [UID:0002CP]/[UID:0002CQ] but does not block first-draft C++.
- Dialog primary vtable slot `+0x38` target `0x0049e1c0` is a `DialogPane` refresh/update hook, but final original source spelling is not proven. Use a descriptive placeholder in [UID:0002CU] formal C++ and keep the exact slot target in docs.
- Generic button/control constructor names for constructor child ids `0`, `3`, and `4` remain support-level names rather than final original names. The constructor source can still emit with descriptive `ButtonControlPane` or existing support names.
- [UID:0002CV] binary shape is unrolled and EH-cleanup-heavy; original source may have used repeated statements or a local table. A table-driven first draft is source-equivalent and preserves all proven facts, but do not claim table form as original.
- `+0x78c` is cleared by the constructor but has no decisive role in the six current targets. Leave it as reserved/unresolved; no score should be inflated for it.
- Exact draw-state temporary helper names in [UID:0002CS] remain generic support questions. Resource names, frame indices, and rectangle math are fully recoverable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-FittingRoomDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002CP"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-FittingRoomDialogCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-FittingRoomDialogCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002CP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
