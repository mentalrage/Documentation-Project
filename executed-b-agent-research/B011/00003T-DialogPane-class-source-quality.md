** TARGET-REPORT-UID:00003T **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00003T DialogPane Class Source-Quality Report

Status: FINISHED
Date: 2026-06-19
Agent: B011
Target UID: [UID:00003T]
Target path: `source-3/project-documentation/by-class/DialogPane.md`
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00003T-DialogPane-class-source-quality.md`

This is report-only. I did not edit `by-*` documentation, generated source, IDA state, or any coverage report. The recommendations below are intended for a later supervisor implementation callback.

## Executive Recommendation

Raise [UID:00003T] `DialogPane` from `85/86` to `COMPLETION:88`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000IT`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000IT`, and populate class-page declaration C++ only.

Do not put method bodies into the class page. The class page should emit a first-draft declaration, field layout, and virtual/member API shape with `[[CHILDREN]]`. Exact method bodies still belong on exact by-memory pages such as [UID:00012R], [UID:0003KD]-[UID:0003KP], [UID:00012T], and [UID:00012U]. Compiler ABI support such as scalar deleting destructors, adjustor thunks, and literal vtable data must remain non-handwritten.

The current no-code explanation is stale because it still refers to a near-final `95/95` style gate. Under the current B-agent rule, the class clears the active source gate and now has enough evidence for a declaration. Remaining uncertainty is not class ownership or source placement; it is final original spelling for helper methods, the internal control-manager type, visual-state enum names, and background resource payload names. Those cap final confidence but do not block a class declaration.

## Evidence Checked

Instruction and workflow files:

- `tools/leaser/Agents/Agent-B011/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`

Primary target and source root:

- `by-class/DialogPane.md`
- `by-file/DialogPane.md`
- `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
- `auto-generated/NexusTK/ui/core/DialogPane.cpp`
- `source-3/simroot_v2/class_DialogPane.cpp` as a generated-source lead only

Layout, vtable, and global support:

- `by-type/by-struct/DialogPaneLayout.md`
- `by-type/by-vtable/DialogPaneVtables.md`
- `by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md`
- `by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md`
- `by-global/g_activeDialogCount.md`
- `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md`

Control/helper split support:

- `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`
- Exact children [UID:0003KD] through [UID:0003KP]
- [UID:00012T] `DialogCategorySwitch`

Slide and derived override support:

- [UID:00012U] `0x0049eac0-0x0049f07e.DialogPaneSlideAnimation`
- [UID:00020X] `BrowserDialogPaneVirtuals`
- [UID:00020Y] `WebBoardDialogVirtualCompanions`
- [UID:00020Z] `WebBoardDialogInputAndRequestHelpers`
- [UID:000212] `WebBoardDialogOldDestructionAndMouseCallbacks`
- B002 executed report `00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality.md`
- B002 executed report `0002V7-pane-set-mode-source-quality.md`
- B008 `TextPad` report as a current example of inherited DialogPane control-manager offset usage
- B002 `AlertPane` report as a current example of class-page declaration-only C++ policy

Coverage rows checked:

- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `by-type/by-struct/-coverage-report.md`
- `by-type/by-vtable/-coverage-report.md`

Local availability checked:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` exists.
- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` exists.
- Current autogen `DialogPane.cpp` contains only empty emitter markers for [UID:00003T], [UID:00012R], the exact control-helper children, layout/vtable support, frame resources, and active-dialog globals.

## Current State

[UID:00003T] currently records:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000IT`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000IT`
- blank formal C++

This metadata is valid for routing but conservative for source quality. The class is the direct parent for the exact vtable and layout pages and the exact control-helper children. The by-file parent [UID:0000IT] is `87/86`; the main by-memory aggregate [UID:00012R] is `86/88`; the layout is `86/90`; the vtable page is `88/93`; the active-dialog byte storage is `88/91`; and the control-helper inventory is `90/91` as a non-emitting split/index.

The coverage row for [UID:00003T] is stale: it still says `82%`, while the class page itself is `85/86`.

## Source Placement And Ownership

Best owner/source root: [UID:0000IT] `DialogPane`, proposed module `NexusTK/ui/core/DialogPane.cpp`.

Evidence:

- The constructor at `0x0049d8a0` has 84 direct constructor call sites in the current docs.
- The contiguous base class island [UID:00012R] spans constructor, ordinary destructor cleanup, lifecycle handlers, input/control dispatch, control helpers, slide helpers, draw/config helpers, and selected-control repaint logic.
- Constructor/destructor store `DialogPane` primary/secondary/tertiary vtables at offsets `+0x00`, `+0xa0`, and `+0xa4`.
- `g_activeDialogCount` is incremented by the constructor at `0x0049d902` and decremented by the destructor cleanup at `0x0049da31`; other modules only consume the byte as an input/action gate.
- The helper fan-in is broad: create/layout, slide, control, and rect helpers have high caller counts across dialog families, so they are base-dialog infrastructure rather than feature-dialog code.

Rejected owner alternatives:

- `BrowserDialog`, `WebBoardDialog`, `WebBoardDialogOld`: rejected for base class ownership. These classes own derived input/browser-HWND reposition overrides; they only consume `DialogPane::OnInputEvent` and the inherited title-drag byte.
- `HeadSelectDialog`: rejected for [UID:00012T]. The category switch helper has FittingRoom and WebBoard callers plus HeadSelect; it is a shared `DialogPane` control-manager helper.
- `Clan`/`RankingDialog`: rejected for [UID:00012U]. Those names are generated-output pollution or caller provenance for shared slide helpers.
- `Pane`: accepted as base dependency only. `DialogPane` extends `Pane`, but its title/config/control-manager/modal/tile/background state is direct DialogPane state.

## Class Layout And Field Names

The current layout page is mostly correct but can now be more decisive on source-facing names. Recommended field directions:

| Offset | Recommended source-facing field | Evidence and uncertainty |
| --- | --- | --- |
| `+0x0f8` | `m_title[128]` | Constructor and `SetTitleText` use `_wcscpy_s(..., 0x80, ...)`. Strong. |
| `+0x1f8` | `m_dialogConfigId` | Constructor stores it; `OnCreate` checks against `0xffff` and does config-backed placement. Strong. |
| `+0x1fc` | `m_controlManager` | Used by add/find/select/category/focus helpers and by many derived dialog reports. Prefer `m_controlManager` over `m_controls` because the object has count, entry lookup, select/category virtual slots. Strong. |
| `+0x200` | `m_focusedControlId` | [UID:0003KL] and [UID:0003KO] use it for focus and activation. Strong. |
| `+0x204` | `m_pendingControlId` | [UID:0003KM] stores it and [UID:0003KP] activates it. Replace "previous/default/action" where possible. Strong. |
| `+0x208` | `m_isTitleDragActive` / `m_titleDragActive` | Browser/WebBoard input reports identify secondary-view `+0x168` as this primary byte during title-drag/move. Modeless mouse handling also maps to it. Strong enough for descriptive field. |
| `+0x209` | `m_savedPaneMode` | Constructor initializes it from the mode argument; modeless/dialog drag saves/restores pane mode through this byte. Exact original spelling could be `m_dialogMode` or `m_savedMode`; use `m_savedPaneMode` with the constructor-initialized caveat. |
| `+0x20c` | `m_dragOriginX` | Modeless drag math uses mouse X. Strong. |
| `+0x210` | `m_dragOriginY` | Modeless drag math uses mouse Y. Strong. |
| `+0x214` | `m_activeControlId` | Keyboard/input and TextPad report use it as active/current control id. Existing "hover control id" wording is partly true for mouse hover paths, but `m_activeControlId` fits broader behavior better. |
| `+0x218` | `m_pressedControlActive` | Mouse down/release state byte. Medium-high. |
| `+0x21c` | `m_pressedControlId` | Mouse and dispatch paths store the pressed candidate. Medium-high. |
| `+0x220` | `m_pressedHitType` | Modeless release checks hit type; hit type `10` is title/chrome behavior in support docs. Medium-high. |
| `+0x224` | `m_selectedControlId` | [UID:0003KN], [UID:0003KO], [UID:0003KP], and keyboard/control dispatch use it for selected/prior selected control. Strong. |
| `+0x228` | `m_selectionVisualState` | [UID:0003KN] stores visual-state byte and uses state `0x0a`/`0x0b` semantics. Strong enough as descriptive name; final enum names remain open. |
| `+0x229` | `m_clampDragToBounds` | [UID:0003KD] sets it; [UID:0003KE] clears it; modeless drag checks it before clamping. Strong. |
| `+0x22c/+0x230/+0x234/+0x238` | `m_dragClampMinY`, `m_dragClampMinX`, `m_dragClampMaxY`, `m_dragClampMaxX` | StoreClampRect writes this order; modeless drag compares top/left/bottom/right. Strong for role, exact member order should remain offset-documented. |
| `+0x23c` | `m_tileContext` | Constructor initializes and destructor tears down `EPFTileContext`. Strong. |
| `+0x240..+0x268` | `m_background...` fields | `SetBackgroundResource` and draw helpers use copied frame/tile payload fields. Keep as a grouped `DialogPaneBackground` or descriptive background-resource fields until helper signatures are final. |

Derived tails:

- Do not treat `+0x26c` as base `DialogPane` state. It is `AlertPane::m_layoutReference`, Browser/WebBoard `m_browserControlPane`, DialogInSession tail state, or other derived-class storage depending on the class.
- Browser/embedded-window offsets `+0x11c`, `+0x120`, `+0x26c`, `+0x278`, and `+0x27c` belong to derived/browser classes or their subobjects, not to DialogPane.

## Control Helper Split Ownership

[UID:00012S] should remain a non-emitting split inventory. It should not be reconstructed as one helper-cluster body. Exact child bodies carry direct [UID:00003T] ownership:

- [UID:0003KD] `StoreClampRect`: stores four clamp dwords and sets `m_clampDragToBounds`.
- [UID:0003KE] `ClearClampRectDirtyFlag`: clears `m_clampDragToBounds`.
- [UID:0003KF] `SetTitleText`: copies to `m_title[128]` and invalidates/refreshes via virtual slot.
- [UID:0003KG] `SetBackgroundResource`: updates tile/background state through `+0x260`; helper callees still need final names.
- [UID:0003KH] `EnsureControlManagerAndAdd`: lazily creates `m_controlManager` and adds the supplied control.
- [UID:0003KI] `SelectControlById`: finds a control by id and selects it through manager slot `+0x1c`.
- [UID:00012T] `SwitchControlCategory`: shared category switch helper; not HeadSelect-private.
- [UID:0003KJ] `FindControlIndexById`: returns the matching manager entry index or `-1`.
- [UID:0003KK] `GetControlCountRaw`: raw 15-byte helper; no direct xrefs, but byte placement and state use prove it is source-shaped DialogPane helper code, not dead/no-owner padding.
- [UID:0003KL] `SetFocusedControl`: updates `m_focusedControlId` and toggles control visual state.
- [UID:0003KM] `SetPendingControl`: stores `m_pendingControlId`.
- [UID:0003KN] `SetSelectionVisualState`: updates `m_selectedControlId` and `m_selectionVisualState`.
- [UID:0003KO] `ActivateFocusedControlRaw`: raw/polluted body; use `ActivateFocusedControl`. It has raw-byte behavior, calls `SetSelectionVisualState`, redraws through screen-pane refresh, sleeps `0x85`, and dispatches selected state.
- [UID:0003KP] `ActivatePendingControl`: modeled partner for `m_pendingControlId`.

Recommended support-doc wording: exact children are source-authored `DialogPane` member helpers, but formal child C++ may stay blank until `DialogControlManager`, visual-state enum names, and helper signatures are normalized. The class declaration can safely declare their source-facing names.

Rejected alternatives:

- Emitting [UID:00012S] as a source body: rejected because it duplicates exact children and includes padding.
- Treating raw [UID:0003KK] as dead/no-code: rejected because it is a coherent helper between two modeled children and uses the same `m_controlManager` contract.
- Treating [UID:0003KO] as feature-owned because of thunk callers: rejected because its state fields and sibling helper calls are DialogPane class state.

## Slide Animation Ownership

[UID:00012U] remains direct `DialogPane` infrastructure. It should not be moved to Ranking, Clan, or any feature dialog.

Best source-facing names:

- `SlideOpenVertical` for `0x0049eac0-0x0049eb8d`
- `SlideCloseVertical` for `0x0049eb90-0x0049ec72`
- `SlideOpenHorizontal` or `SlideHorizontal` for `0x0049ec80-0x0049ed58`
- `SlideCloseHorizontal` for `0x0049ed60-0x0049ee42`
- `SlideShrink` for raw `0x0049ee50-0x0049ef59`
- `SlideExpand` for raw `0x0049ef60-0x0049f07e`

The raw shrink/expand helpers currently have no direct caller/xref evidence, so do not force method bodies into formal C++ yet. Preserve them as source-shaped retained base-dialog animation helpers inside the support doc.

Rejected alternatives:

- `ClanDialogSlideAnimation` as owner: rejected. [UID:00012V] is a historical/caller-provenance alias for two horizontal helpers, not a new owner.
- Ranking ownership: rejected as generated-owner pollution.
- Compiler-only/no-code for the whole slide cluster: rejected because four helpers have broad direct caller fan-in and source-level animation behavior; only padding and retained raw starts need caveats.

## Derived Input Override Split

Correct split:

- `DialogPane` owns inherited secondary-view virtuals at `0x0049e240` and `0x0049e6e0`: shared input/control dispatch and keyboard/focus/selection handling.
- `BrowserDialog` owns `0x0046ad80` and the surrounding BrowserDialog virtual cluster [UID:00020X].
- Active `WebBoardDialog` owns `0x0046d3b0` in [UID:00020Y] and `0x0046d4b0` in [UID:00020Z].
- Old `WebBoardDialogOld` owns `0x0046e930` in [UID:000212].

Recommended `DialogPane` class/file doc change: stop listing `0x0046ad80` and `0x0046e930` as "input/window reposition overrides" under DialogPane proposed contents. They should be listed only as derived override examples/consumers of the inherited DialogPane input surface.

Evidence:

- B002 reanalysis places `0x0046ad80` in BrowserDialog vtable slot `0x00613414`, with browser-control HWND reposition behavior.
- B002 reanalysis places `0x0046d3b0` in WebBoardDialog vtable slot `0x00613654`, using WebBoard-specific `+11,+42` inset.
- B002 reanalysis places `0x0046e930` in WebBoardDialogOld vtable slot `0x00613704`, using fixed old-dialog `+30,+30` inset.
- These derived bodies use `m_browserControlPane`/BrowserControlPane `+0x11c` hosted HWND and class-specific singleton/vtable context.

Rejected alternatives:

- Absorbing browser reposition overrides into DialogPane because they call `0x0049e240`: rejected. A base call does not make the derived override a base method.
- Keeping the current class-page row as unresolved for `0x0046ad80`/`0x0046e930`: rejected. Current B002 reports resolve both.

## Destructor, Vtable, And Compiler-Generated Policy

Source shape:

- The source class should declare `virtual ~DialogPane()`.
- The ordinary cleanup body is inside [UID:00012R] at `0x0049d9f0-0x0049dacb`. It decrements `g_activeDialogCount`, releases `m_controlManager`, tears down `m_tileContext`, reinstalls vtables as compiler lowering, and chains to `Pane` teardown.
- The primary scalar deleting destructor slot is `0x0048c350`; secondary/tertiary adjustor thunks are [UID:00010U] at `0x0048c27b` and `0x0048c286`.

Policy:

- Do not write scalar-deleting destructor C++ with flags.
- Do not write adjustor thunk C++.
- Do not write literal vtable dwords.
- Do not hand-author vtable restores in the ordinary destructor source. They are compiler lowering from the class declaration and base/member destructor layout.

Recommended support-doc correction: [UID:00010U] filename still ends `0x0048c290`, while its text says the true half-open thunk range is `0x0048c27b-0x0048c291`. If a later support cleanup is in scope, repair the filename/header mismatch.

## Class Declaration C++ Readiness

First-draft class declaration is ready. This class page should emit declaration-level source, not method bodies.

Recommended formal C++ for [UID:00003T]:

```cpp
class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual bool OnInputEvent(InputEvent *event);
    virtual bool OnKeyInput(InputEvent *event);

protected:
    void CloseDialog();
    void StoreClampRect(int minY, int minX, int maxY, int maxX);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, const wchar_t *paletteName);
    void AddControl(unsigned char category, ControlPane *control);
    void SelectControlById(int controlId);
    void SwitchControlCategory(int categoryId);
    int FindControlIndexById(int controlId) const;
    int GetControlCount() const;
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    void SetSelectionVisualState(int controlId, unsigned char state);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RedrawSelectedControl();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    DialogControlManager *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginX;
    int m_dragOriginY;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinY;
    int m_dragClampMinX;
    int m_dragClampMaxY;
    int m_dragClampMaxX;
    EPFTileContext m_tileContext;
    DialogBackgroundState m_backgroundState;

    [[CHILDREN]]
};
```

Notes for implementation:

- `DialogControlManager` and `DialogBackgroundState` are source-facing placeholder type names. If an accepted support type already exists by implementation time, use the accepted project type instead.
- `OnKeyInput` is the best descriptive name for `0x0049e6e0` based on current inherited secondary-view slot usage. `OnKeyboardControl` or `OnControlKeyInput` would also be defensible; record the exact chosen name in vtable/layout docs.
- `SetBackgroundResource` argument shape is not final. The class declaration can include the source-facing helper name while exact child C++ remains blank.
- Do not include browser HWND reposition overrides in this class declaration.

## Exact Recommended Doc Changes

### `by-class/DialogPane.md`

1. Change metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:89`
   - keep owner/emitter/reconstructable unchanged.
2. Replace stale final-source/no-code wording with current active gate language:
   - class declaration is source-ready;
   - method bodies remain on exact by-memory pages;
   - helper/type names cap final confidence but no longer block class declaration output.
3. Update "Observed State" field names using the table in this report:
   - `m_controlManager`, `m_focusedControlId`, `m_pendingControlId`, `m_isTitleDragActive`, `m_savedPaneMode`, `m_dragOriginX/Y`, `m_activeControlId`, `m_pressedControlActive`, `m_pressedControlId`, `m_pressedHitType`, `m_selectedControlId`, `m_selectionVisualState`, `m_clampDragToBounds`, clamp bounds, `m_tileContext`, and grouped background state.
4. Update the input override row:
   - base owns `0x0049e240`/`0x0049e6e0`;
   - `0x0046ad80`, `0x0046d3b0`, `0x0046d4b0`, and `0x0046e930` are derived Browser/WebBoard overrides.
5. Add first-draft class declaration C++ above.
6. Add a 2026-06-19 B011 changelog entry:
   - "B011 source-quality pass resolved class declaration readiness, control-helper split ownership, field-name directions, derived input override exclusions, slide helper ownership, and compiler-destructor/vtable policy."

### `by-file/DialogPane.md`

1. Recommended score `88/88`.
2. Update proposed contents to remove `0x0046ad80` and `0x0046e930` from DialogPane-owned input/window overrides; list them as derived override consumers instead.
3. Add that class [UID:00003T] should now emit declaration C++ while exact by-memory pages continue to carry method-body evidence.
4. Add control helper split summary: [UID:00012S] is a non-emitting inventory; exact children are DialogPane class methods.
5. Add slide helper summary: [UID:00012U] is DialogPane-owned; [UID:00012V] is a historical caller alias only.
6. Preserve caveats for exact helper/type names, background state type, visual-state enum names, and `g_activeDialogCount` signed/bias declaration.

### `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` [UID:00012R]

1. Keep `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00003T].
2. Optional score change to `87/89`; acceptable to keep `86/88` if implementation scope is class-only.
3. Replace stale `95/95` wording:
   - active source gate is satisfied;
   - aggregate method-body C++ remains blank because class declaration belongs on [UID:00003T] and exact method bodies should be emitted by child pages to avoid duplicate aggregate output.
4. Add ordinary-destructor/source-shape note: source declares `DialogPane::~DialogPane`; vtable restores/base teardown are compiler lowering.
5. Correct helper names in inventory text to use `m_pendingControlId`, `m_activeControlId`, `m_selectionVisualState`, and `m_clampDragToBounds`.

### `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md` [UID:00012S]

1. Keep metadata `90/91`, `RECONSTRUCTABLE:FALSE`, owner/emitter blank.
2. Add B011 source-name direction from this report.
3. Keep it non-emitting. Exact children carry source ownership.
4. State that raw [UID:0003KK] is retained source-shaped helper code and raw [UID:0003KO] is source-authored despite IDA metadata pollution.

### Exact control-helper children [UID:0003KD]-[UID:0003KP] and [UID:00012T]

No broad metadata change required. If touched, add source-facing name directions:

- `SetFocusedControl`, `SetPendingControl`, `SetSelectionVisualState`, `ActivateFocusedControl`, `ActivatePendingControl`, `SwitchControlCategory`, `GetControlCount`.
- Keep C++ blank unless the implementation callback explicitly accepts exact helper-body C++ for those children.

### `by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md` [UID:00012U]

1. Keep owner/emitter [UID:00003T].
2. Keep method-body C++ blank for now.
3. Add the final source-facing name directions: vertical/horizontal slide open/close plus retained `SlideShrink`/`SlideExpand`.
4. Re-emphasize that Ranking/Clan labels are generated/caller pollution.

### `by-type/by-struct/DialogPaneLayout.md`

1. Update post-`+0x208` field names using the recommended table.
2. Add explicit statement that [UID:00003T] class declaration is now first-draft ready, while helper body C++ is still delegated to exact by-memory pages.
3. Keep derived tail boundary at `+0x26c`.

### `by-type/by-vtable/DialogPaneVtables.md` and `0x00618a60-0x00618afc.DialogPaneVtableData.md`

1. Keep vtable pages non-body/non-dword output.
2. Add that the class declaration on [UID:00003T] is the source mechanism that regenerates the vtables.
3. Preserve scalar deleting destructor and adjustor thunk compiler policy.

### `by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md`

If support cleanup scope allows it, fix the filename/header mismatch noted above. Otherwise add a note only. No C++.

## Exact Coverage Text

Do not edit coverage directly as B011. Recommended supervisor-owned replacement rows are below.

### `by-class/-coverage-report.md`

Replace the [UID:00003T] row with:

```markdown
- [UID:00003T][DialogPane](by-class/DialogPane.md) : reconstructable : 88% : strong : B011 2026-06-19 source-quality pass resolves DialogPane class declaration/source shape under [UID:0000IT][DialogPane](by-file/DialogPane.md), direct class ownership for exact control-helper children, recommended field names for control-manager/focus/pending/active/drag/selection/clamp/tile/background state, ordinary destructor versus compiler scalar-deleting/adjustor glue policy, three-view vtable declaration handling, active-dialog counter dependency, Browser/WebBoard derived input override exclusion, DialogPane-owned slide helper direction, and first-draft class declaration C++ readiness with method bodies still carried by exact by-memory pages.
```

### `by-file/-coverage-report.md`

Replace the [UID:0000IT] row with:

```markdown
- [UID:0000IT][DialogPane](by-file/DialogPane.md) : reconstructable : 88% : very strong : Base dialog module with common lifetime/control behavior, B011 2026-06-19 class source-quality closure, first-draft [UID:00003T][DialogPane](by-class/DialogPane.md) declaration route, exact base-dialog aggregate support, non-emitting [UID:00012S][DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) split over class-owned exact helper children, DialogPane-owned slide helper family, vtable/layout anchors, 84 constructor refs, active-dialog counter ownership, corrected Browser/WebBoard derived override split, compiler thunk/vtable-data exclusion, and remaining final-name caveats for control-manager/background/visual-state helper types.
```

### `by-memory/-coverage-report.md`

Replace the [UID:00012R] row with:

```markdown
    - [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) 0x0049d8a0-0x0049feae | class-method aggregate | DialogPane : reconstructable : 86% : strong : B011 2026-06-19 source-quality pass keeps the exact base-dialog method island source-bearing under [UID:00003T][DialogPane](by-class/DialogPane.md), with constructor, ordinary destructor cleanup, lifecycle handlers, input/control dispatch, control-helper split children, DialogPane-owned slide helpers, draw/config helpers, layout offsets through +0x268, vtables 0x00618a64/0x00618ac4/0x00618af4, active-dialog counter mutators, corrected derived Browser/WebBoard override boundary, and blank aggregate C++ because class declaration belongs on [UID:00003T] and exact child pages should carry method bodies.
```

Replace the [UID:00012S] row with:

```markdown
    - [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) 0x0049dae0-0x0049dfc4 | split inventory | DialogControlPaneHelpers : not_reconstructable : 90% : very strong : Non-emitting DialogPane control-helper inventory over exact class-owned children [UID:0003KD] through [UID:0003KP] plus [UID:00012T]; B011 2026-06-19 source-quality pass preserves blank aggregate C++, resolves source-facing helper/field directions for clamp, title, background, control-manager add/find/select/category, focus, pending activation, selected visual state, raw GetControlCount, and raw ActivateFocusedControl, and rejects Browser/HeadSelect/feature-private ownership while exact child pages carry source-authored method evidence.
```

Replace the [UID:00012U] row with:

```markdown
    - [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md) 0x0049eac0-0x0049f07e | helper cluster | DialogPaneSlideAnimation : reconstructable : 86% : strong : Shared DialogPane slide animation helper cluster owned by [UID:00003T][DialogPane](by-class/DialogPane.md); B011 2026-06-19 source-quality pass confirms vertical slide-open/close, horizontal slide-open/close, retained raw SlideShrink/SlideExpand bodies, broad direct caller fan-in for live helpers, raw no-xref caveats for shrink/expand, exact padding/boundary handling, rejected Ranking/Clan generated-owner pollution, and blank formal C++ pending final helper signatures.
```

No exact child-row insertions are required for this class report unless the supervisor separately wants `by-memory/-coverage-report.md` to enumerate [UID:0003KD]-[UID:0003KP]. If that happens, use the exact child inventory in [UID:00012S] as the source for per-child rows.

### `by-type/by-struct/-coverage-report.md`

Optional replacement for [UID:0001U4] if the layout page is edited:

```markdown
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) : reconstructable : 87% : strong : DialogPane inherited layout attached to [UID:00003T][DialogPane](by-class/DialogPane.md); B011 2026-06-19 source-quality pass resolves recommended field names for title/config/control-manager/focused/pending/active/drag/pressed/selected/clamp/tile/background state, preserves derived-tail boundary at +0x26c, confirms constructor/destructor/control/repaint/vtable evidence and raw helper caveats, and supports first-draft class declaration output while final helper/type names still cap confidence.
```

## IDA Rename / Type / Comment Recommendations

These are recommendations only; I did not edit IDA.

High-confidence renames:

- `0x0049d8a0`: `DialogPane::DialogPane`
- `0x0049d9f0`: `DialogPane::~DialogPane` ordinary cleanup body, not scalar deleting destructor
- `0x0049dad0`: `DialogPane::CloseDialog` or `DialogPane::DismissDialogPane` (choose one project-wide)
- `0x0049dae0`: `DialogPane::StoreClampRect`
- `0x0049db20`: `DialogPane::ClearClampRect`
- `0x0049db30`: `DialogPane::SetTitleText`
- `0x0049dc10`: `DialogPane::AddControl` or `DialogPane::EnsureControlManagerAndAdd`
- `0x0049dd00`: `DialogPane::SwitchControlCategory`
- `0x0049dd20`: `DialogPane::FindControlIndexById`
- `0x0049dd70`: `DialogPane::GetControlCount`
- `0x0049dd80`: `DialogPane::SetFocusedControl`
- `0x0049ddd0`: `DialogPane::SetPendingControl`
- `0x0049de00`: `DialogPane::SetSelectionVisualState`
- `0x0049de70`: `DialogPane::ActivateFocusedControl`
- `0x0049df20`: `DialogPane::ActivatePendingControl`
- `0x0049e240`: `DialogPane::OnInputEvent`
- `0x0049e6e0`: `DialogPane::OnKeyInput` or `DialogPane::OnControlKeyInput`
- `0x0049fe20`: `DialogPane::RedrawSelectedControl`

Type/comment recommendations:

- Define or document `DialogControlManager` as the control list/manager at `DialogPane +0x1fc`.
- Define or document visual-state byte values used by `SetSelectionVisualState`: current evidence includes `0x0a` and `0x0b`.
- Comment `+0x204` as pending activation control id, not previous focus.
- Comment `+0x214` as active/current control id with hover-use caveat.
- Comment `+0x229` and `+0x22c..+0x238` as drag clamp state.
- Comment `0x0048c350`, `0x0048c27b`, and `0x0048c286` as compiler ABI support regenerated from `virtual ~DialogPane()`.
- Comment `0x0046ad80`, `0x0046d3b0`, `0x0046d4b0`, and `0x0046e930` as derived Browser/WebBoard overrides, not DialogPane methods.

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after a later implementation callback edits docs. Expected result: each file validator exits successfully and autogen refresh shows `auto-generated/NexusTK/ui/core/DialogPane.cpp` now contains the class declaration if [UID:00003T] C++ is applied.

> Executable block R001 was removed from this report and preserved verbatim in [00003T-DialogPane-class-source-quality-removed.md](00003T-DialogPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact helper child pages are edited, also validate each edited child:

> Executable block R002 was removed from this report and preserved verbatim in [00003T-DialogPane-class-source-quality-removed.md](00003T-DialogPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies coverage rows, validate the corresponding coverage files:

> Executable block R003 was removed from this report and preserved verbatim in [00003T-DialogPane-class-source-quality-removed.md](00003T-DialogPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Autogen refresh is needed if the class declaration C++ is populated:

> Executable block R004 was removed from this report and preserved verbatim in [00003T-DialogPane-class-source-quality-removed.md](00003T-DialogPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Callback Checklist

1. Lease all target/support docs before editing.
2. Update [UID:00003T] metadata to `88/89`, refresh field/source-shape text, and insert declaration-only C++ with `[[CHILDREN]]`.
3. Update [UID:0000IT] to remove Browser/WebBoard derived overrides from DialogPane-owned proposed contents and add class declaration readiness.
4. Update [UID:00012R] stale `95/95` wording and destructor/compiler-policy text.
5. Update [UID:00012S] and [UID:00012U] support wording; do not emit aggregate C++.
6. Update layout/vtable support with the class declaration/vtable regeneration policy and final field-name directions.
7. If scope allows, repair or note the [UID:00010U] endpoint filename/header mismatch.
8. Do not edit `by-memory/-coverage-report.md` directly as B-agent; carry the exact rows above for supervisor-owned application.
9. Run the scoped validators listed above with `--apply --queue-timeout 240`.
10. Run autogen validation/refresh after C++ declaration insertion.

## Remaining Issues

- Exact original names for `DialogControlManager`, background-state payload fields, and visual-state enum values are not symbol-proven. This caps the class below final-audit confidence but does not block declaration C++.
- `g_activeDialogCount` has an initial byte value `0xff`; its signed/bias declaration remains a global-support caveat, not a DialogPane class blocker.
- `0x0049ee50` and `0x0049ef60` raw slide helpers remain retained/no-direct-xref source-shaped helper bodies. Keep them in the slide support page until a route or original source factoring is found.
- [UID:0003KK] has no direct xrefs. Keep it as a source-shaped raw helper by placement and state contract, not as a dead/no-owner item.
- [UID:00010U] endpoint mismatch should be fixed in a support cleanup, but it does not affect the DialogPane class source decision.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00003T-DialogPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00003T"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00003T-DialogPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00003T-DialogPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00003T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
