** TARGET-REPORT-UID:00019V **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: [UID:00019V] SelectBoxControlPane

Assignment id: `B002-goal2-selectbox-control-pane-source-quality-00019V-20260618`

Primary target: [UID:00019V] `by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md`

Report author: Agent-B002

Report-only status: no by-* documentation, generated source, IDA database, generated reports, or `by-memory/-coverage-report.md` files were edited. This report is the only file created for supervisor review/application.

## Summary Recommendation

Raise [UID:00019V] from `82/90` to `88/91`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000CQ`, keep `EMITTER_UIDS:0000CQ`, keep source route through [UID:0000HY] `ButtonControlPane.cpp`, and populate first-draft formal C++ for the constructor, selected-state accessor, selected-state setter, adjusted EventHandler mouse-event virtual, and paint virtual.

The current blockers are materially resolved:

- The selected byte is the SelectBox-specific boolean selected flag at `this + 0x108` (`+264` decimal), not an unresolved anonymous byte.
- The mouse/event handler does not read a host/callback member. Dialog/group coordination lives in NewUserMisc caller code that invokes the setter; this target only owns local selected state, hit testing, invalidation, and drawing.
- The vtable writes resolve to a three-view ControlPane/Pane object layout: primary vtable at `+0x00` (`0x0061d4c0`), EventHandler secondary view at `+0xa0` (`0x0061d528`), and a tertiary inherited/default handler view at `+0xa4` (`0x0061d558`).
- The constructor parameter is best represented as `const RectBounds *bounds`: the ABI takes one pointer argument, forwards it to `ControlPane::ControlPane(8, bounds)`, writes SelectBox vtables, clears `m_selected`, and calls `Pane::SetMode(1)`.
- Source placement should remain in the generic button/choice control family under [UID:0000HY] `ButtonControlPane.cpp`; NewUserMisc/UserCreateAppearanceControls are consumers, not owners.
- No split is needed for this aggregate. Destructor/thunk glue is already represented by [UID:0002XV]/[UID:0002XW], and the five source-bearing methods in this range share the same class, emitter, state field, and vtable family.

## Evidence Checked

Documentation reviewed:

- [UID:00019V] `by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md`
- [UID:0000CQ] `by-class/SelectBoxControlPane.md`
- [UID:0000HY] `by-file/ButtonControlPane.md`
- [UID:00019U] `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`
- [UID:0002Q8] `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`
- [UID:0002XV] `by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md`
- [UID:0002XW] `by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md`
- [UID:00025Q] `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`
- [UID:0000FR] `by-file/UserCreateAppearanceControls.md`
- [UID:0000CP] `by-class/ButtonControlPane.md`
- [UID:000037] `by-class/ControlPane.md`
- [UID:0000IF] `by-file/ControlPane.md`
- [UID:000114] `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`
- [UID:00025R] `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md`
- [UID:00031T] `by-type/by-vtable/ControlPaneVtables.md`
- [UID:000116] `by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md`
- [UID:000117] `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
- [UID:00016K] `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- [UID:00016R] `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
- `by-project-structure/proposed-source-tree.md`
- Prior accepted report `tools/leaser/Agents/Agent-B001/research/executed/0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md`

Read-only binary checks:

- PE inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base `0x00400000`; relevant sections include `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, and `.data 0x0066d000-0x0069ce24`.
- Local Capstone disassembly was used for `0x004fccf0-0x004fce7e`, nearby constructor inlining in `0x004fb630-0x004fe782`, vtable data near `0x0061d4c0`, and cross-reference scans.
- IDA MCP/GhidraBridge live connection was not available during this pass; `127.0.0.1:13337` had no listener. This does not block the recommendation because the PE disassembly, existing docs, vtable data, and generated coverage are sufficient for this target.

Generated output checked:

- `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`
- `auto-generated/NexusTK/login/UserCreateAppearanceControls.cpp`
- `auto-generated/NexusTK/login/NewUserShapeSelectControlPane.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`

The generated source files above are currently empty, so they confirm that the emitter route exists but has not yet received formal C++ for this method cluster.

## Heuristic / Inference Reanalysis And Validation

### Method Inventory And Source-Facing Names

The range contains five source-bearing SelectBoxControlPane methods:

| Address range | Best source-facing name | Evidence and rationale |
| --- | --- | --- |
| `0x004fccf0-0x004fcd67` | `SelectBoxControlPane::SelectBoxControlPane(const RectBounds *bounds)` | Single-argument constructor; forwards `[ebp+8]` and control type `8` into `ControlPane::ControlPane`, writes all SelectBox vtable views, clears `+0x108`, calls `Pane::SetMode(1)`, and returns `ret 4`. |
| `0x004fcd70-0x004fcd77` | `bool SelectBoxControlPane::IsSelected() const` | Loads `al` directly from `[ecx+0x108]` and returns. No other fields or helper calls. |
| `0x004fcd80-0x004fcda4` | `void SelectBoxControlPane::SetSelected(bool selected)` | Compares the byte argument with `[ecx+0x108]`; if changed, writes the byte and invalidates the inherited bounds rect at `this+0x44` through primary vtable slot `+0x20`. |
| `0x004fcdb0-0x004fcdf7` | `bool SelectBoxControlPane::OnMouseEvent(const Event *event)` | Entry receiver is the EventHandler secondary view (`this+0xa0`), checks event type byte `event+4 == 3`, hit-tests event coordinates against inherited bounds `this+0x44`, converts back to primary receiver with `-0xa0`, sets `m_selected`, invalidates bounds, and returns true. |
| `0x004fce00-0x004fce7e` | `void SelectBoxControlPane::OnPaint()` | Primary virtual slot at `0x0061d504`; sets draw color `0`, calls shared surface/background callback at `dword_69B3FC`, then draws a double frame when selected or when inherited visual state `+0x103` is not `10`. |

`OnMouseEvent` is a stronger source-facing name than `OnMouseDown` because the vtable entry is an EventHandler virtual and the method itself filters event type `3`. A compact behavioral alias such as `HandleMouseDown` is acceptable in prose, but the formal C++ should use an event-handler signature rather than a direct `OnMouseDown(x, y)` signature.

### Selected Byte `+0x108` (`+264`)

The field currently documented as selected byte `+264` should be named `m_selected` or `m_isSelected`, with `m_selected` preferred for concise source fit. The offset should be written as `+0x108` with decimal `+264` only as a parenthetical compatibility note.

Evidence:

- Constructor at `0x004fcd4b` writes `0` to `[esi+0x108]`.
- Accessor at `0x004fcd70` returns only `[ecx+0x108]`.
- Setter at `0x004fcd80` compares/writes only `[ecx+0x108]` and invalidates on change.
- Mouse/event handler at `0x004fcdd8-0x004fcde3` checks the secondary-view-relative address `[esi+0x68]`, which is `(this+0xa0)+0x68 == this+0x108`, then writes `[ecx+0x108] = 1`.
- Paint at `0x004fce2a` gates the frame drawing on `[esi+0x108] != 0` before consulting inherited visual state.
- Object size is `0x10c` from the scalar deleting destructor/vector-delete guard path in [UID:0002XW], placing `+0x108` near the SelectBox-specific tail and leaving only trailing padding/ABI space.

Rejected alternatives:

- Generic `selectedByte` or `byte_108`: rejected because every use has a boolean selected-state role and there is a direct accessor/setter pair.
- `m_checked`: possible UI vocabulary, but no checkbox resource, check-mark draw, or toggle-off behavior is present. The control behaves as a selection/radio indicator in the NewUserMisc group.
- `m_pressed` or `m_hot`: rejected because hit/press visual state is inherited from ControlPane at `+0x103`, while this byte is persistent and only set by mouse hit/setter calls.
- Host index/current-choice byte: rejected because setter callers in NewUserMisc coordinate multiple child SelectBoxes externally; this byte never stores an index and never points back to a host.

### Host Selection Or Callback Members

No host/callback member is used by the mouse handler in [UID:00019V]. This should be recorded as a resolved negative finding, not left as an open field question.

Evidence:

- `0x004fcdb0-0x004fcdf7` reads only the EventHandler secondary receiver, the event record (`+4`, `+8`, `+0xc`), inherited bounds at primary `+0x44`, and selected state at primary `+0x108`.
- The only outbound call after a successful hit is the inherited invalidation virtual at primary vtable slot `+0x20`.
- There is no load from a host pointer, dialog pointer, callback table, action id, sibling list, or control id field in this method.
- The seven setter callers inside NewUserMisc code perform group reset/selection orchestration outside SelectBoxControlPane.

Rejected alternatives:

- `m_ownerDialog`, `m_selectionGroup`, or callback delegate inside SelectBoxControlPane: rejected due to absence of any field load beyond inherited bounds/state and `m_selected`.
- Direct notification from mouse handler to NewUserMiscDialogPane: rejected; the mouse handler selects itself and repaints only. Higher-level state changes are performed by caller/dialog code.
- A hidden table/pointer route through vtables: rejected for this range; virtual dispatch is only inherited invalidation, not a host callback.

### Vtables, Secondary Bases, And Receiver Adjustment

The SelectBoxControlPane object has three vtable views:

- Primary view at object offset `+0x00`, vtable `0x0061d4c0`.
- EventHandler secondary view at object offset `+0xa0`, vtable `0x0061d528`.
- Tertiary inherited/default handler view at object offset `+0xa4`, vtable `0x0061d558`.

Constructor evidence:

```asm
0x004fcd30  mov dword ptr [esi],     0x0061d4c0
0x004fcd3a  mov dword ptr [esi+0xa0], 0x0061d528
0x004fcd44  mov dword ptr [esi+0xa4], 0x0061d558
```

Vtable evidence from `.rdata`:

- `0x0061d4c0` starts with scalar deleting destructor `0x0049b0d0`.
- `0x0061d504` points to `0x004fce00`, the paint virtual in this target.
- `0x0061d528` points to adjustor thunk `0x0049af11`, and `0x0061d52c` points to `0x004fcdb0`, the EventHandler mouse/event virtual in this target.
- `0x0061d558` points to adjustor thunk `0x0049af1c`, followed by inherited/default handler `0x00544e90`.

The EventHandler method receives `ecx == this + 0xa0`. It forms the bounds pointer with `lea eax, [esi-0x5c]`, which resolves to `(this+0xa0)-0x5c == this+0x44`, and later forms the primary receiver with `lea ecx, [esi-0xa0]`. This validates the inherited receiver adjustment recorded in [UID:0002XV] and should be included in [UID:00019V] as a concrete receiver model.

Rejected alternatives:

- Separate embedded child object at `+0xa0`: rejected. The constructor writes a secondary vtable view into the same allocation and the handler adjusts back to the primary object.
- SelectBox-specific timer base at `+0xa4`: not supported by this target. The tertiary view is present for ControlPane/Pane layout compatibility, but no SelectBox method in this range uses it.
- WeatherLayer/Raining ownership of the shared thunks: rejected for this target. [UID:0002XV] correctly treats the thunks as shared ABI glue; SelectBox owns the vtable entries and methods in this range.

### Constructor Parameters And Embedded Layout

Best constructor signature:

```cpp
SelectBoxControlPane::SelectBoxControlPane(const RectBounds *bounds)
```

Rationale:

- The function receives exactly one stack argument and returns `ret 4`.
- It forwards that pointer unchanged to `ControlPane::ControlPane(8, bounds)`.
- [UID:000114] documents the ControlPane constructor as taking a control type and optional bounds pointer.
- Inline construction sites in NewUserMisc build stack RectBounds records and pass their addresses, which matches pointer ABI evidence.

The source author may have written a reference-like API if all real call sites pass non-null stack rects, but the binary and base constructor support a pointer. Formal C++ should use `const RectBounds *bounds` until a broader source API pass proves a reference style.

Object layout additions for [UID:0000CQ]:

```cpp
// inherited ControlPane/Pane state precedes this offset
bool m_selected; // +0x108
// object size observed by scalar deleting destructor path: 0x10c
```

Known inherited fields used by this target:

- `this + 0x44`: inherited bounds rectangle; passed to hit-testing, invalidation, background draw callback, and frame drawing.
- `this + 0x103`: inherited ControlPane visual-state byte; paint suppresses the frame only when `!m_selected && visualState == 10`.
- `this + 0xa0`: EventHandler secondary vtable view.
- `this + 0xa4`: tertiary inherited/default vtable view.

### Helper Calls And Descriptive Names

Best names/types for helper references in this target:

| Address/global | Recommended descriptive name | Evidence/status |
| --- | --- | --- |
| `0x004949e0` | `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)` | Called by constructor with control type `8` and incoming bounds pointer. |
| `0x005446b0` | `Pane::SetMode(unsigned char mode)` | Called with `1` after vtable setup; supported by Pane layout docs. |
| `0x004b7e80` | `PointInRect_4B7E80` / `PointInRect(y, x, rect)` | Mouse handler passes event coordinates and inherited bounds; existing RectGeometry docs support this role. |
| `0x004b9660` | `SetDrawColor` / GrafPort draw-state setter | Paint calls with `0`, then `4`; [UID:00016K] documents draw-state accessors. Exact original source spelling remains shared GrafPort work, not a target blocker. |
| `dword_69B3FC` | shared surface/background rectangle callback | Paint calls it after setting draw color `0` and before optional frame drawing. It should not be modeled as a SelectBox member. |
| `0x004ba450` | `DrawRectFrame` | Paint calls it twice around a rect adjust; [UID:00016R] documents the frame draw helper. |
| `0x004b7e30` | `InsetRect` / signed rect adjust by `(1, 1)` | Paint copies bounds to a local rect, draws the first frame, adjusts the local rect by `(1,1)`, and draws the second frame. Existing docs name the raw helper `InflateRect_4B7E30`; first-draft source should use a descriptive rect-adjust helper. |

The exact original source spelling for GrafPort/Rect helpers is still a shared support-doc question, but it does not block first-draft C++ because their behavior and signatures are sufficient and already documented elsewhere.

### Seven Setter Callers

The seven direct calls to `0x004fcd80` all occur inside the NewUserMisc dialog action/update code around `0x004fc010`:

- `0x004fc4f5`
- `0x004fc502`
- `0x004fc51f`
- `0x004fc52c`
- `0x004fc541`
- `0x004fc54e`
- `0x004fc55b`

The surrounding function obtains child controls by id from a child/control manager at `this+0x1fc`, including ids `9`, `10`, `3`, `4`, `5`, `6`, `7`, `8`, `11`, `12`, `13`, `14`, `15`, and `16`, then uses the SelectBox setter to clear competing selections in a dialog-side group. This validates that selection-group behavior belongs to NewUserMisc/UserCreateAppearanceControls, while the SelectBox class remains a generic reusable control.

Do not infer a hidden callback field in SelectBoxControlPane from these callers. The caller-side orchestration is the evidence against such a field.

### Source Placement And Ownership

Recommended placement:

- Keep [UID:00019V] owned by [UID:0000CQ] `SelectBoxControlPane`.
- Keep [UID:0000CQ] emitted through [UID:0000HY] `ButtonControlPane.cpp`.
- Describe the source family as generic button/choice controls. A future source tree may split this into `ChoiceControlPane.cpp` or `SelectBoxControlPane.cpp`, but current evidence does not justify moving this target away from [UID:0000HY].

Validation:

- The class has its own vtable family and source-bearing methods.
- It uses only generic ControlPane/Pane, GrafPort, geometry, and event helper behavior.
- NewUserMisc is a consumer and inlines construction of six SelectBox controls, but the target method bodies are generic and have no new-user resource or dialog-specific field dependency.
- [UID:0002Q8] begins at `0x004fce80`, immediately after this range, and owns UserShapeSelectControlPane-specific behavior. That boundary supports keeping SelectBox generic and UserShapeSelect specific.
- [UID:0002XV]/[UID:0002XW] are shared ABI glue and destructor wrappers, not evidence for shared source ownership of this method range.

Rejected alternatives:

- `UserCreateAppearanceControls.cpp` / NewUser-local source: rejected because locality and caller use are the only supporting facts. The class is generic, has standalone vtables, and has no login-specific resource dependency.
- New `ChoiceControlPane.cpp` now: plausible future source-tree cleanup, but there is no current file-support UID or independent source evidence requiring it. Prefer documenting the family direction under [UID:0000HY] and leaving a future split note.
- Direct `ControlPane.cpp` ownership: rejected because ControlPane is the base; SelectBox writes its own vtables and adds `m_selected`.
- WeatherLayer/Raining ownership: rejected because their only relation is shared adjustor/scalar-deleting glue already covered by [UID:0002XV]/[UID:0002XW].

### Split / No-Split Decision

Do not split [UID:00019V] into child method pages now.

Reasons:

- The five methods are short, source-bearing, and form one coherent class method island.
- All methods share the same field `m_selected`, inherited bounds/visual-state usage, vtable family, owner, and emitter.
- The target begins at the standalone SelectBox constructor and ends exactly before [UID:0002Q8] UserShapeSelectControlPane code at `0x004fce80`.
- Destructor/thunk-related compiler glue is already split into [UID:0002XV] and [UID:0002XW].
- Method-child splits would add administrative overhead without improving source placement or generated C++ quality.

Optional future support split:

- A vtable/data child for `0x0061d4bc-0x0061d560.SelectBoxControlPaneVtableData` would improve read-only-data precision, but it is not required to raise [UID:00019V] or populate C++.

### Generated Output And Stale Gate Text

The current “blank formal C++ due to below 95/95” style explanation is stale and should be removed. Under the active code-entry rule, [UID:00019V] is reconstructable, has a nonblank owner/emitter route, and exceeds the average score gate after this pass. First-draft C++ should be populated.

Generated output is currently empty for the relevant route:

- `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` is empty.
- The coverage generator already routes [UID:00019V] through [UID:0000CQ] into `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`.

This is generated-output absence, not source-placement contradiction.

## First-Draft C++ Recommendation

Populate formal C++ for [UID:00019V]. The code below is intentionally source-shaped and avoids raw decompiler temporaries. Helper names are descriptive where project-wide exact source names remain pending.

```cpp
enum
{
    kSelectBoxControlType = 8,
    kSelectBoxMouseDownEvent = 3,
    kControlPaneVisualStateNormal = 10
};

SelectBoxControlPane::SelectBoxControlPane(const RectBounds *bounds)
    : ControlPane(kSelectBoxControlType, bounds),
      m_selected(false)
{
    SetMode(1);
}

bool SelectBoxControlPane::IsSelected() const
{
    return m_selected;
}

void SelectBoxControlPane::SetSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    InvalidateRect(&m_bounds);
}

bool SelectBoxControlPane::OnMouseEvent(const EventRecord *event)
{
    if (event != NULL &&
        event->type == kSelectBoxMouseDownEvent &&
        PointInRect(event->y, event->x, &m_bounds) &&
        !m_selected)
    {
        m_selected = true;
        InvalidateRect(&m_bounds);
    }

    return true;
}

void SelectBoxControlPane::OnPaint()
{
    RectBounds frame = m_bounds;

    SetDrawColor(0);
    DrawBackgroundRect(&m_bounds);

    if (!m_selected && m_visualState == kControlPaneVisualStateNormal)
        return;

    SetDrawColor(4);
    DrawRectFrame(&frame);
    InsetRect(&frame, 1, 1);
    DrawRectFrame(&frame);
}
```

Required C++ notes for supervisor/editor:

- `EventRecord` field names should map `type` to offset `+4` and the coordinate fields to offsets `+8/+0xc` in the order expected by `PointInRect_4B7E80`. If the shared event struct uses different names, preserve the offsets and adapt names.
- `m_bounds` is inherited at `+0x44`; do not add a new SelectBox field for it.
- `m_visualState` is inherited ControlPane state at `+0x103`; do not model it as a SelectBox-specific byte.
- `DrawBackgroundRect` is the source-shaped placeholder for the `dword_69B3FC` callback invoked after `SetDrawColor(0)`. If the support docs have a canonical name for this surface callback at application time, use that canonical name.
- `InsetRect` is the source-shaped placeholder for the signed rect-adjust helper at `0x004b7e30` called with `(1, 1)` between the two frame draws.
- If the project standard prefers no local enum constants in method blocks, move the three constants into the class/file support doc or use existing shared enum names.

Optional class-level declaration material for [UID:0000CQ] if the supervisor updates that class page during the same application:

```cpp
class SelectBoxControlPane : public ControlPane
{
public:
    explicit SelectBoxControlPane(const RectBounds *bounds);

    bool IsSelected() const;
    void SetSelected(bool selected);

protected:
    virtual bool OnMouseEvent(const EventRecord *event);
    virtual void OnPaint();

private:
    bool m_selected; // +0x108, object size 0x10c
};
```

## Exact Supervisor Edits

### [UID:00019V] Metadata

Recommended replacement metadata:

```text
COMPLETION: 88
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000CQ
EMITTER_UIDS: 0000CQ
```

Do not change owner/emitter. Replace stale “95/95” or “below final-code gate” explanations with active-gate wording:

```text
Formal C++ is now eligible: this target is reconstructable, has a valid owner/emitter route through [UID:0000CQ], and the source-quality pass resolves the selected-state field, receiver adjustment, helper roles, and source placement enough to exceed the active code-entry gate.
```

### [UID:00019V] Method/Field Note Replacement

Replace any unresolved selected-byte / host-callback blocker text with:

```text
The SelectBox-specific field at `this+0x108` (`+264` decimal) is the boolean selected flag, best named `m_selected`. The constructor clears it, the accessor returns it, the setter updates it and invalidates inherited bounds `this+0x44`, the EventHandler mouse-event virtual sets it after a type-3 event hit-test, and `OnPaint` uses it to decide whether to draw the double selection frame. No host-selection pointer, callback member, or selection-group field is read in this target; NewUserMisc dialog code performs group reset externally through seven direct `SetSelected(false)` calls.
```

Add or replace vtable/receiver note:

```text
SelectBoxControlPane uses the inherited ControlPane/Pane multi-view layout: primary vtable `0x0061d4c0` at object offset `+0x00`, EventHandler secondary vtable `0x0061d528` at `+0xa0`, and tertiary inherited/default handler vtable `0x0061d558` at `+0xa4`. The mouse-event method receives `ecx == this+0xa0`, reaches inherited bounds with `(this+0xa0)-0x5c == this+0x44`, and converts back to the primary receiver with `-0xa0` before writing `m_selected` and invalidating.
```

Add or replace source-placement note:

```text
Source placement should remain with [UID:0000CQ] `SelectBoxControlPane`, emitted through [UID:0000HY] `ButtonControlPane.cpp` as part of the generic button/choice control family. NewUserMisc/UserCreateAppearanceControls are consumers that inline six SelectBox constructions and call the setter for group reset; they do not own this generic control. [UID:0002Q8] begins the UserShapeSelectControlPane-specific code immediately after this range at `0x004fce80`, confirming the boundary.
```

Add split decision:

```text
Do not split this target into per-method children at this time. The constructor, accessor, setter, EventHandler mouse-event virtual, and paint virtual are short, coherent SelectBoxControlPane methods with one owner/emitter and one state field. Destructor/thunk ABI glue is already represented separately by [UID:0002XV] and [UID:0002XW].
```

### [UID:0000CQ] `by-class/SelectBoxControlPane.md`

Recommended support insert under the class layout/source placement notes:

```text
`SelectBoxControlPane` adds one confirmed class-specific field: `bool m_selected` at `+0x108` (`+264` decimal), within an object size of `0x10c` observed from the scalar deleting destructor/vector-delete path. Inherited fields used by the methods are `m_bounds` at `+0x44`, ControlPane visual state at `+0x103`, EventHandler secondary vtable view at `+0xa0`, and tertiary inherited/default handler view at `+0xa4`.

Source-facing methods resolved by [UID:00019V] are `SelectBoxControlPane(const RectBounds *bounds)`, `IsSelected() const`, `SetSelected(bool)`, `OnMouseEvent(const EventRecord *)`, and `OnPaint()`. The mouse-event method only selects and invalidates the control after a type-3 event hit-test; dialog-level group clearing is external caller behavior, not a SelectBox callback/member.
```

Recommended class score if supervisor applies the class-layout material:

```text
COMPLETION: 88
CONFIDENCE: 89
```

If the supervisor chooses to populate class-level formal C++ for [UID:0000CQ], use the declaration block from the First-Draft C++ section rather than method bodies.

### [UID:0000HY] `by-file/ButtonControlPane.md`

Recommended support insert under SelectBox/ButtonControl family notes:

```text
`SelectBoxControlPane` remains a generic button/choice-control family member in this file route. [UID:00019V] has no NewUser-specific resource dependency and no host callback field; NewUserMisc is only a consumer that constructs six select boxes and invokes `SetSelected` for group coordination. A future narrower `ChoiceControlPane.cpp` or `SelectBoxControlPane.cpp` split is plausible if the source tree is reorganized, but current evidence supports retaining the [UID:0000HY] emitter route.
```

No file-level score change is required solely for this target. If the supervisor wants to reflect resolved SelectBox source placement, `86/88` can remain valid; `87/89` is also defensible after adding this note.

### [UID:00019U] `NewUserMiscShapeAndPasswordDialogs`

Recommended support insert near the NewUserMisc child-control/caller notes:

```text
The seven direct calls to [UID:00019V] `SelectBoxControlPane::SetSelected(bool)` at `0x004fc4f5`, `0x004fc502`, `0x004fc51f`, `0x004fc52c`, `0x004fc541`, `0x004fc54e`, and `0x004fc55b` are dialog-side selection-group resets. They do not imply a host/callback field inside SelectBoxControlPane. The generic control owns only its local selected flag and repaint behavior.
```

No ownership change for [UID:00019U].

### [UID:00025Q] `MainMenuNewUserReadOnlyData`

Optional support insert if supervisor wants exact vtable precision before creating a dedicated data child:

```text
SelectBoxControlPane vtable family within the mixed read-only-data range: primary vtable at `0x0061d4c0`, EventHandler secondary vtable at `0x0061d528`, and tertiary inherited/default handler vtable at `0x0061d558`. The primary paint slot points to [UID:00019V] `0x004fce00`; the EventHandler mouse/event slot points to [UID:00019V] `0x004fcdb0`; scalar deleting destructor and adjustor thunk entries route through [UID:0002XW] and [UID:0002XV].
```

This is optional support text; no new data split is required for the current target.

### [UID:0002XV] / [UID:0002XW]

No metadata change required. If updating cross-links, add:

```text
[UID:00019V] validates the SelectBox receiver adjustments: the EventHandler vtable at `0x0061d528` is stored at object offset `+0xa0`, and the mouse-event body adjusts `this+0xa0` back to the primary object with `-0xa0`. The scalar deleting destructor remains compiler ABI glue and should not be folded into [UID:00019V] formal source.
```

## Coverage Row Recommendation

Replace the existing [UID:00019V] row in `by-memory/-coverage-report.md` with:

```text
        - [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md) : reconstructable : 88% : very-strong : B002 2026-06-18 source-quality pass resolves this as a coherent SelectBoxControlPane method island: constructor/accessor/SetSelected/adjusted EventHandler mouse-event/OnPaint, selected flag `+0x108` (decimal 264), object size `0x10c`, primary/secondary/tertiary vtables `0x0061d4c0`/`0x0061d528`/`0x0061d558`, `+0xa0` receiver adjustment, no host callback/member use in the mouse handler, seven NewUserMisc setter callers as dialog-side group reset, ButtonControlPane.cpp source placement over login/new-user alternatives, no split needed, stale 95/95 wording rejected, and first-draft C++ ready.
```

Placement context: replace the current row for `[UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane]` under the `0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs` child/nearby coverage block.

No direct edit was made to the coverage report.

## Rejected Or Superseded Existing Text

Mark these current target/support statements stale or superseded during supervisor application:

- “Selected byte `+264` unresolved”: superseded by `bool m_selected` at `+0x108`.
- “Host selection/callback members used by mouse handler unresolved”: superseded by negative evidence that the mouse handler reads no host/callback fields.
- “Blank formal C++ because below 95/95” or equivalent: stale under the active code-entry gate.
- “Source grouping provisional between ButtonControlPane and NewUser-local source” without a recommendation: superseded by generic ButtonControlPane/choice-control ownership with NewUser as consumer.
- “Split needed for constructor/accessor/setter/mouse/paint” if present: rejected; no split is recommended for this method island.

## Remaining Uncertainties And Impact

The following uncertainties remain but do not block score increase or first-draft C++:

- Exact original source spelling for `EventRecord`, coordinate field names, and the event type enum is shared Event/ControlPane support work. Impact: use descriptive `EventRecord`, `type`, `x`, and `y` in first-draft C++; preserve offsets during formal application.
- Exact original source spelling for the `dword_69B3FC` background/surface callback is shared rendering support work. Impact: use descriptive `DrawBackgroundRect` or the canonical support-doc name if one exists at application time.
- Exact original source spelling for `0x004b7e30` is shared RectGeometry support work. Impact: use descriptive `InsetRect`/rect-adjust name in source-shaped C++ and retain raw helper evidence in notes.
- A future `ChoiceControlPane.cpp` split remains plausible as source-tree organization, but current evidence supports [UID:0000HY] `ButtonControlPane.cpp`. Impact: no owner/emitter change now.

These uncertainties cap the confidence below the mid-90s, but they do not justify leaving formal C++ blank.

## Validator Commands After Supervisor Application

Suggested commands after applying edits:

> Executable block R001 was removed from this report and preserved verbatim in [00019V-SelectBoxControlPane-source-quality-removed.md](00019V-SelectBoxControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support edits are also applied to [UID:00019U], [UID:00025Q], [UID:0002XV], or [UID:0002XW], include their files in targeted `--mode file` validation before global rescore/autogen.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00019V-SelectBoxControlPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00019V"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019V-SelectBoxControlPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00019V-SelectBoxControlPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
