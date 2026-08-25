** TARGET-REPORT-UID:00008K **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B015 Source-Quality Report: [UID:00008K] ModelessDialogPane

Status: FINISHED - research/report-only  
Target: `source-3/project-documentation/by-class/ModelessDialogPane.md`  
Report: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00008K-ModelessDialogPane-class-source-quality.md`  
Rules observed: no `by-*` documentation edited; `by-memory/-coverage-report.md` not edited.

## Executive Recommendation

- Keep canonical owner/emitter as [UID:0000LH] `ModelessDialogPane`.
- Raise target metadata from `COMPLETION:87`, `CONFIDENCE:85` to `COMPLETION:89`, `CONFIDENCE:88`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Source placement remains shared dialog infrastructure, routed through `by-file/ModelessDialogPane.md`; do not move this class to feature dialogs, alert-pane code, or `EventDispatcher`.
- Class-level C++ is ready as a declaration/source-shape block. Do not emit full method bodies in the class page; the bodies belong to child by-memory pages [UID:000310], [UID:000311], and [UID:000312].
- Constructor and `IsModal` child pages are first-draft C++ ready. The mouse handler is source-shaped and materially understood, but final full-body emission should stay capped until the implementation callback accepts the resolved helper/field spelling below.
- The current stale blocker text should be replaced: constructor allocation sites are not an unresolved blocker after the raw PE scan; inherited field roles and mouse event type names now have high-probability names; the Wave3 `vtable_count:0` value is stale against the .rdata/constructor evidence.

## Evidence Checked

- Target and support docs:
  - `by-class/ModelessDialogPane.md`
  - `by-file/ModelessDialogPane.md`
  - `by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md`
  - `by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md`
  - `by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md`
  - `by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md`
  - `by-type/by-struct/ModelessDialogPaneLayout.md`
  - `by-type/by-vtable/ModelessDialogPaneVtables.md`
  - `by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md`
  - `by-class/DialogPane.md`
  - `by-type/by-struct/DialogPaneLayout.md`
  - `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
  - `by-file/Event.md`
  - `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
  - `by-class/EventDispatcher.md`
  - `by-file/EventDispatcher.md`
  - `by-memory/0x005446b0-0x005446c1.PaneSetMode.md`
  - `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md`
- Generated/decompiler evidence:
  - `source-3/simroot_v2/class_ModelessDialogPane.cpp`
  - `source-3/simroot_v2/class_DialogPane.cpp`
  - combined function JSON for `0x004a0760`, `0x004a0830`, `0x004a0840`
- Raw PE scan:
  - Image: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5: `4247E04E20B65D6414C7238AA8FF5515`
  - SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
  - Image base: `0x00400000`
  - `.text`: VA `0x00401000`, raw `0x00000400`, raw size `0x0020b600`
  - `.rdata`: VA `0x0060d000`, raw `0x0020ba00`
  - Constructor `0x004a0760`: zero VA/RVA/raw-offset pointer hits and zero `.text` rel32 call/jump hits.
  - `IsModal` `0x004a0830`: one VA hit at `.rdata` VA `0x00618cb0`; zero direct branch hits.
  - `HandleMouseEvent` `0x004a0840`: one VA hit at `.rdata` VA `0x00618cac`; zero direct branch hits.
  - Aggregate end `0x004a0c8e`: zero pointer hits and zero direct branch hits.
  - Primary vtable `0x00618c48`: constructor immediate only at instruction `0x004a07bd`.
  - Secondary vtable `0x00618ca8`: constructor immediate only at instruction `0x004a07c4`.
  - Tertiary vtable `0x00618cd8`: constructor immediate only at instruction `0x004a07ca`.

## Findings

### Source Placement And Ownership

`ModelessDialogPane` remains a shared dialog infrastructure class under [UID:0000LH] `ModelessDialogPane`. The constructor registers an event-handler/list view with the global event dispatcher, but that is runtime registration, not source ownership by `EventDispatcher`. The mouse handler relies heavily on inherited `DialogPane` helpers and fields, but the overrides and vtables are specific to `ModelessDialogPane`.

Rejected alternatives:

- Do not route to feature-specific dialog files or `AlertPanes`; no checked evidence ties the class to a feature dialog.
- Do not route method bodies to `EventDispatcher`; the dispatcher owns list traversal/routing, not this pane's input policy.
- Do not introduce a separate derived tail layout for the `+0x208..+0x238` state. These fields are inherited `DialogPane` interaction fields used by `ModelessDialogPane`.

### Range, Split, And Vtable Policy

The aggregate [UID:00012Z] `0x004a0760-0x004a0c8e` is an index-only wrapper over exact child functions:

- [UID:000310] `0x004a0760-0x004a0827` constructor
- padding `0x004a0827-0x004a0830`
- [UID:000311] `0x004a0830-0x004a0835` `IsModal`
- padding `0x004a0835-0x004a0840`
- [UID:000312] `0x004a0840-0x004a0c8e` mouse handler
- following `66 90` padding and jump-table data begin after the handler; do not merge the switch table into the function.

The Wave3/generated class metadata that says `vtable_count:0` is stale. Constructor stores and .rdata prove three vtable views:

- primary complete-object vtable at `0x00618c48`
- secondary/event-handler view at `0x00618ca8`
- tertiary view at `0x00618cd8`

The tertiary view has two function slots; the next dword at `0x00618ce0` is not another slot and begins adjacent data/string material.

### Constructor And Allocation Sites

[UID:000310] is source-ready as a normal constructor:

```cpp
ModelessDialogPane::ModelessDialogPane(const wchar_t *titleText)
    : DialogPane(titleText, -1, 1)
{
    RECT bounds;
    SetRectLTRB(&bounds, 100, 100, 200, 200);
    OnCreate(&bounds, 0, 0, g_dialogRenderContext);
    InitializePaneInteraction(0, 0);
    g_pEventDispatcher->AddToModalList(GetEventHandlerView());
}
```

Implementation notes:

- The `-1` base argument is the same sentinel as the raw `0xffff` config id; use `0xffff` instead if the accepted `DialogPane` signature makes that parameter unsigned.
- `GetEventHandlerView()` is the secondary view at `this+0xa0`.
- `InitializePaneInteraction(0, 0)` is the current best source role for `0x00544d30`; exact Pane helper spelling remains the only meaningful constructor-name caveat.
- The binary emits SEH/security-cookie and vtable-store codegen; those are not handwritten source.
- The absence of direct constructor callers/pointers is now negative evidence, not a blocker. This constructor may be reached through factory/allocation paths not statically represented as direct calls in the PE, or through paths outside the currently indexed references.

### Event Dispatcher/List Registration

Constructor tail call `EventDispatcher::AddToModalList(g_pEventDispatcher, this+0xa0)` should be described as registration of the secondary event/list view with the dialog/event dispatch list. Because `ModelessDialogPane::IsModal()` returns false, this is not proof that the pane behaves modally. Recommended wording: "registers the modeless event-handler view in the dispatcher dialog list; the virtual `IsModal` result distinguishes modeless behavior during traversal."

### Mouse Event Type Names

Use the `EventMan` support mapping:

- `0`: cursor move/state dispatch
- `1`: left-button down
- `2`: left double-click
- `3`: left-button release/up
- `7`: mouse wheel

Current Modeless docs that omit type `2` or call type `7` passive/hover should be corrected. Right-button event types `4`, `5`, `6` exist in the wider event system but are not handled by this switch.

### Handler Flow

[UID:000312] receives the secondary-view `this` pointer and recovers the complete object as `this-0xa0`. The source-facing signature should be on the complete object:

```cpp
bool ModelessDialogPane::HandleMouseEvent(InputEvent *event);
```

Branch summary to preserve in docs:

- Type `0` cursor move:
  - If title dragging is active, compute the new pane location from current mouse position minus saved drag origin, clamp if enabled, then update pane bounds.
  - If not dragging, hit-test controls. If a press is active, keep or clear the selected visual state depending on whether the cursor is still over the pressed control and hit type; dispatch the event to the pressed control; otherwise return false.
- Type `1` left down:
  - Hit-test. Hit type `10` within the dialog rect starts title drag: set drag active, save mouse origin, save current pane mode, and normalize mode through `Pane::SetMode(0)` or `Pane::SetMode(1)` when the saved mode is `2` or `3`.
  - Non-title control hits set the pressed-control fields, set the selected visual state, and dispatch the input to the selected control. The code may call the primary virtual at slot `+0x58` before setting press state when the hover/control id changes and the control entry is interactive.
- Type `2` left double-click:
  - Hit-test; if a control id is found and the point is inside the dialog rect, dispatch the event to that control.
- Type `3` left release/up:
  - If title dragging is active, restore the saved pane mode, persist position through `DialogPane::SavePosition()` when the config id is not `0xffff`, clear drag active, and return handled.
  - If a control press is active, clear press state, reset selected visual state to id `-1` and hit type `10`, dispatch release to the pressed control, call the frame/surface presentation helper at `0x00557140` with `dword_67A7CC`, and if the release hit matches the original pressed control/hit type, invoke the control-activation virtual and `DialogPane::UpdateFocusedControl()`.
- Type `7` mouse wheel:
  - If the point is inside the dialog rect, hit-test and dispatch the wheel event to the resolved control. Do not describe this as passive hover routing.
- Default:
  - Return false.

`0x00557140` should not be described as an input-manager notification. Current support identifies it as `SurfaceRenderPresentation`/frame presentation; the modeless release path uses it as a post-release presentation refresh with `dword_67A7CC`.

### Field And Helper Names

Recommended field names for inherited `DialogPane` state used by `ModelessDialogPane`:

| Offset | Recommended name | Evidence |
| --- | --- | --- |
| `+0x1f8` | `m_dialogConfigId` | Constructor/base passes `0xffff`; release path checks not `0xffff` before saving position. |
| `+0x1fc` | `m_controlManager` | Passed to hit-test/control dispatch helpers. |
| `+0x208` | `m_titleDragActive` | Set only on title/chrome drag start and cleared on release. |
| `+0x209` | `m_savedPaneMode` | Saves `Pane +0xb5` mode and is restored through `Pane::SetMode`. |
| `+0x20c` | `m_dragStartX` | Mouse X saved at drag start. |
| `+0x210` | `m_dragStartY` | Mouse Y saved at drag start. |
| `+0x214` | `m_hoverControlId` | Compared to hit control id before hover/interactive callback path. |
| `+0x218` | `m_pressedControlActive` | Gates pressed-control move/release paths. |
| `+0x21c` | `m_pressedControlId` | Stores the control id pressed on left down. |
| `+0x220` | `m_pressedHitType` | Stores the hit type pressed on left down. |
| `+0x224` | `m_selectedControlId` | Selection helper and release reset use id `-1`. |
| `+0x228` | `m_selectedHitType` | Selection helper and release reset use neutral hit type `10`. |
| `+0x229` | `m_dragClampEnabled` | Enables clamp of dragged bounds. |
| `+0x22c` | `m_dragBoundsTop` | Clamp top/min-Y, stored by `DialogPaneStoreClampRect`. |
| `+0x230` | `m_dragBoundsLeft` | Clamp left/min-X. |
| `+0x234` | `m_dragBoundsBottom` | Clamp bottom/max-Y. |
| `+0x238` | `m_dragBoundsRight` | Clamp right/max-X. |

Recommended helper names:

- `0x0049fb10`: `DialogPane::HitTestControls(int x, int y, int *outControlId)` - high confidence.
- `0x0049fda0`: `DialogPane::DispatchInputToControl(InputEvent *event, int controlId)` - high confidence.
- `0x0049fa60`: `DialogPane::SavePosition()` or `DialogPane::SavePositionFromCurrentRect()` - medium/high confidence.
- `0x0049fe20`: `DialogPane::UpdateFocusedControl()` - medium/high confidence.
- `0x0049de00`: `DialogPane::SetSelectionVisualState(int controlId, unsigned char hitType)` - high confidence from support.
- `0x005446b0`: `Pane::SetMode(unsigned char mode)` - exact support page exists.
- `0x004a6fc0`: `EventDispatcher::AddToModalList(...)` - current best name, medium/high confidence.
- `0x00557140`: `SurfaceRenderPresentation(...)` / `PresentFrame(...)` - medium confidence; do not use `g_globalInputManager` wording.

## First-Draft C++ / No-Code Policy

The class target should carry a declaration/source-shape block rather than full method bodies:

```cpp
class ModelessDialogPane : public DialogPane
{
public:
    ModelessDialogPane(const wchar_t *titleText);
    virtual bool IsModal();
    virtual bool HandleMouseEvent(InputEvent *event);
};
```

Use `wchar_t *` instead of `const wchar_t *` only if the surrounding reconstructed headers consistently avoid const for dialog titles. Do not add C++ for vtable data or the aggregate/index range.

Child-body readiness:

- [UID:000310] constructor: first-draft C++ ready with the caveat that `0x00544d30` source spelling should be finalized as the accepted Pane interaction/init helper name.
- [UID:000311] `IsModal`: exact first-draft C++ ready:

```cpp
bool ModelessDialogPane::IsModal()
{
    return false;
}
```

- [UID:000312] mouse handler: behavior is source-shaped enough to improve documentation and possibly draft C++, but I recommend not emitting a full formal body in the class-level callback. Put it on the child method page if the supervisor explicitly wants handler C++ after accepting the helper/field names above.
- [UID:00012Z] aggregate: exact no-code proof. It is an index over children plus padding/jump-table adjacency; source belongs to child methods and class declarations, not an aggregate function.
- [UID:00036P] vtable data: exact no-code proof. Vtable bytes are compiler-emitted RTTI/vtable data from the class declaration and should not be hand-authored.

## Recommended Target Edits

For `by-class/ModelessDialogPane.md`:

1. Update metadata:

```yaml
COMPLETION: 89
CONFIDENCE: 88
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000LH
EMITTER_UIDS: 0000LH
```

2. Replace stale "C++ remains blank until allocation sites/fields/event-dispatcher interaction are resolved" wording with:

> B015 source-quality recheck resolves the major blockers. The class page should carry the source-facing declaration for `ModelessDialogPane`; exact method bodies are owned by [UID:000310], [UID:000311], and [UID:000312]. Constructor allocation has no static direct caller or pointer evidence in the raw PE scan, which caps final reachability confidence but does not block first-draft constructor C++. Inherited `DialogPane` state names and mouse event types are now high-probability and should be propagated to support docs.

3. Add the declaration block shown above as the formal/source-shape C++ for the class page.

4. Add a "Static reachability" note:

> Raw PE scan of `NexusTK.exe` found no VA/RVA/raw-offset pointer hits and no `.text` rel32 calls/jumps to constructor `0x004a0760`. `IsModal` and `HandleMouseEvent` have only vtable data VA refs at `0x00618cb0` and `0x00618cac`. The constructor's three vtable immediates are only the stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`.

5. Correct event-type text to include type `2` as left double-click and type `7` as mouse wheel.

6. Add the field-name table from this report, or a condensed version, and state these are inherited `DialogPane` fields, not a derived tail.

7. Add rejected alternatives:

> No feature-dialog or alert-pane source route is supported; no EventDispatcher ownership is supported; no direct constructor callers should be invented; no `ModelessDialogPane`-specific data tail is introduced for `+0x208..+0x238`; vtable stores, RTTI, SEH, and security-cookie operations are compiler output.

## Recommended Support Edits

### `by-file/ModelessDialogPane.md`

- Keep source route under shared `ModelessDialogPane` infrastructure.
- Replace `g_globalInputManager`/input-manager wording for the release refresh with `SurfaceRenderPresentation`/frame presentation via `0x00557140(dword_67A7CC)`.
- Add the raw PE no-direct-caller/no-pointer caveat for the constructor.
- Add that the constructor registers `this+0xa0` in the dispatcher dialog list through `EventDispatcher::AddToModalList`; `IsModal() == false` is the modeless behavior discriminator.
- Add that child methods, not the aggregate, own source bodies.

### `by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md`

- Keep `RECONSTRUCTABLE:FALSE` and no formal C++.
- Add an exact no-code proof: aggregate/index only, exact children listed above, padding at both internal gaps, jump table starts after `0x004a0c8e`.
- Mention B015 revalidated child split and vtable-only reachability.

### `by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md`

- Raise to about `COMPLETION:88`, `CONFIDENCE:90`.
- Add first-draft constructor C++ from this report.
- Describe `DialogPane(title, -1/0xffff, 1)` base construction, final vtable stores, default `(100,100)-(200,200)` rect, `OnCreate`, Pane interaction init, and `this+0xa0` dispatcher registration.
- Add raw PE no-direct-caller/no-pointer evidence.
- State vtable stores, EH/security-cookie, and ctor unwind machinery are compiler-generated.
- Preserve caveat that the exact source spelling for `0x00544d30` remains provisional.

### `by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md`

- Raise to about `COMPLETION:90`, `CONFIDENCE:94`.
- Add exact C++:

```cpp
bool ModelessDialogPane::IsModal()
{
    return false;
}
```

- Add static reachability: sole static VA ref is the secondary vtable slot at `0x00618cb0`; no direct branch hits; no callees.

### `by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md`

- Raise to about `COMPLETION:88`, `CONFIDENCE:90` after field/helper/event-map edits.
- Correct event types: `0` move, `1` left down, `2` left double-click, `3` left up, `7` wheel.
- Add the handler branch summary and field names from this report.
- Replace raw helper names with source-facing helper names listed above.
- Correct `0x00557140` to frame/surface presentation, not input-manager notification.
- Keep full formal C++ optional/deferred unless the supervisor requests method-body implementation.

### `by-type/by-struct/ModelessDialogPaneLayout.md`

- State no derived tail beyond inherited `DialogPane`.
- Propagate the inherited field names from this report for the secondary-view offsets.
- Add that `this` in the secondary handler is `object+0xa0`; complete-object recovery is `this-0xa0`.

### `by-type/by-struct/DialogPaneLayout.md` and `by-class/DialogPane.md`

- Replace provisional field names after `+0x208` with the recommended names where accepted.
- Add evidence that `+0x209` is saved `Pane::m_mode`, not a constructor-only flag.
- Add `+0x224/+0x228` as selected/highlight visual state, with neutral reset `-1/10`.

### `by-type/by-vtable/ModelessDialogPaneVtables.md`

- Add that B015 found Wave3 `vtable_count:0` stale; constructor and .rdata prove three vtable views.
- Add raw PE vtable immediate evidence at constructor stores `0x004a07bd`, `0x004a07c4`, `0x004a07ca`.
- Keep tertiary slot count at two; next dword `0x00618ce0` is not a slot.

### `by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md`

- Add the same vtable-count mismatch note if useful.
- Keep no formal C++; vtable/RTTI data is compiler-generated from the class declaration.

### `by-class/EventDispatcher.md` / `by-file/EventDispatcher.md`

- Optional support note: `ModelessDialogPane` constructor calls `AddToModalList` with the secondary event/list view, but modeless behavior is governed by `IsModal() == false`.

### `by-file/Event.md` / EventMan support

- No required score change. If touched, cross-reference that `ModelessDialogPane` uses mouse event types `0`, `1`, `2`, `3`, and `7`.

## Score And Metadata Recommendation

Target [UID:00008K]:

```yaml
COMPLETION: 89
CONFIDENCE: 88
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000LH
EMITTER_UIDS: 0000LH
```

Rationale: source route is stable, vtable count mismatch is resolved, event type semantics are resolved from EventMan support, inherited field roles are high-probability from branch use and `DialogPane` helper pages, and raw PE reachability was checked. Confidence should remain below the 90s because original allocation/factory source remains unproven and `0x00544d30` has only a role-level name.

Suggested support score changes if the supervisor applies the implementation:

- [UID:000310] constructor: `86/89 -> 88/90`
- [UID:000311] `IsModal`: `86/91 -> 90/94`
- [UID:000312] handler: `86/88 -> 88/90`
- [UID:0001V9] layout: `85/90 -> 88/91`
- [UID:0001Y6] vtable support: keep or raise to `87/92` after stale `vtable_count:0` note.

## Supervisor-Owned Coverage Text

No `by-memory/-coverage-report.md` change is required if the implementation only updates the class page and support pages without changing by-memory scores. If the supervisor applies the recommended child score changes, replace the `ModelessDialogPane` aggregate block with:

```text
    - [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md) 0x004a0760-0x004a0c8e | class aggregate index | ModelessDialogPane : ignored : 86% : strong : Reviewed non-reconstructable aggregate/index after exact method split; child pages carry class assignment while B015 source-quality recheck keeps aggregate non-emitting, confirms constructor/virtual boundaries, vtable-only reachability, secondary-view state mapping, event-type map, and jump-table exclusion.
        - [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md) 0x004a0760-0x004a0827 | constructor | ModelessDialogPaneConstructor : reconstructable : 88% : strong : B015 source-quality recheck confirms the exact `0xc7` constructor, `DialogPane(title, 0xffff, 1)` base call, three final vtable stores, default `(100,100)-(200,200)` bounds, `DialogPane::OnCreate`, Pane interaction setup, `this+0xa0` EventDispatcher `AddToModalList` registration, raw PE no-direct-caller/no-pointer evidence, and first-draft constructor C++ with `0x00544d30` source spelling still provisional.
        - [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md) 0x004a0830-0x004a0835 | virtual method | ModelessDialogPaneIsModal : reconstructable : 90% : very-strong : Exact five-byte secondary-vtable method assigned to [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md); B015 confirms sole static VA ref from `0x00618cb0`, no direct branches, no callees, and source-ready `bool ModelessDialogPane::IsModal() { return false; }`.
        - [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) 0x004a0840-0x004a0c8e | virtual method | ModelessDialogPaneHandleMouseEvent : reconstructable : 88% : strong : B015 source-quality recheck confirms secondary-view `this` recovery, sole static VA ref from `0x00618cac`, no direct branches, EventMan type map (`0` cursor, `1` left down, `2` left double-click, `3` left up, `7` wheel), DialogPane helper names, inherited drag/pressed/selection/clamp field roles, post-release Surface presentation call, and following switch-table exclusion; final full handler C++ remains capped by helper/field spelling.
```

## Implementation Callback Checklist

If accepted, implement only these documentation edits:

1. Update `by-class/ModelessDialogPane.md` metadata to `89/88`, add the class declaration C++ block, replace stale blocker text, add raw PE reachability evidence, correct event types, add field names, and add rejected alternatives.
2. Update `by-file/ModelessDialogPane.md` source route notes, dispatcher registration wording, frame presentation wording, and constructor no-direct-reference evidence.
3. Update [UID:00012Z] aggregate page with no-code proof and exact split/jump-table boundary.
4. Update [UID:000310] constructor page with first-draft C++, source-shape notes, score `88/90`, raw PE caveat, and compiler-codegen caveat.
5. Update [UID:000311] `IsModal` page with exact C++, score `90/94`, and vtable-only reachability.
6. Update [UID:000312] handler page with event map, field/helper names, branch summary, score `88/90`, and frame-presentation correction.
7. Update `ModelessDialogPaneLayout.md`, `DialogPaneLayout.md`, and `DialogPane.md` with inherited field names.
8. Update `ModelessDialogPaneVtables.md` and optionally `0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md` with the Wave3 `vtable_count:0` mismatch and constructor immediate evidence.
9. Optionally add EventDispatcher support wording that `AddToModalList` receives the modeless secondary view but does not imply modal behavior.
10. Do not edit `by-memory/-coverage-report.md`; supervisor applies the replacement block above if child score changes are accepted.

## Validation Commands For Callback

From `source-3/project-documentation` run file validators for each edited file, for example:

> Executable block R001 was removed from this report and preserved verbatim in [00008K-ModelessDialogPane-class-source-quality-removed.md](00008K-ModelessDialogPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually edited during callback. Run autogen if any metadata, C++ block, or generated index input changes.

## IDA Rename, Type, And Comment Recommendations

- `0x004a0760`: rename to `ModelessDialogPane::ModelessDialogPane`; type as constructor taking `const wchar_t *titleText`; confidence high.
- `0x004a0830`: rename to `ModelessDialogPane::IsModal`; type `bool __thiscall ModelessDialogPane::IsModal()`; confidence high.
- `0x004a0840`: rename to `ModelessDialogPane::HandleMouseEvent`; source signature `bool ModelessDialogPane::HandleMouseEvent(InputEvent *event)`; add comment that the binary entry receives the secondary/event view pointer (`complete object +0xa0`); confidence high.
- `0x0049fb10`: `DialogPane::HitTestControls`; confidence high.
- `0x0049fda0`: `DialogPane::DispatchInputToControl`; confidence high.
- `0x0049fa60`: `DialogPane::SavePosition` or `SavePositionFromCurrentRect`; confidence medium/high.
- `0x0049fe20`: `DialogPane::UpdateFocusedControl`; confidence medium/high.
- `0x0049de00`: `DialogPane::SetSelectionVisualState`; confidence high.
- `0x005446b0`: `Pane::SetMode`; confidence high, already supported.
- `0x004a6fc0`: `EventDispatcher::AddToModalList`; confidence medium/high.
- `0x00557140`: `SurfaceRenderPresentation` or `PresentFrame`; confidence medium. Add a comment that Modeless release uses it as post-release presentation refresh, not input-manager notification.
- Add a class/vtable comment: generated `vtable_count:0` is stale; constructor and .rdata prove primary, secondary, and tertiary vtable views.

## Remaining Open Questions

- Exact source name for `0x00544d30` is still role-level only (`Pane` interaction/init helper). Evidence checked: constructor JSON, generated class output, and support docs. This should not block constructor source C++ because the call shape and role are clear.
- Original allocation/factory source remains unproven. Evidence checked: raw VA/RVA/raw-offset pointers and `.text` rel32 call/jump scan. This caps confidence but does not block class ownership or constructor source shape.
- Exact original header style (`wchar_t *` vs `const wchar_t *`, `override` use) is not proven. Recommendation is to use conservative C++ declaration style consistent with nearby reconstructed source.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00008K-ModelessDialogPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00008K"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00008K-ModelessDialogPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00008K-ModelessDialogPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00008K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
