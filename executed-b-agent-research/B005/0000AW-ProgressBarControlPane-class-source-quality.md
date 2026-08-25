** TARGET-REPORT-UID:0000AW **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B005 source-quality report: [UID:0000AW] ProgressBarControlPane

FINISHED research target: `source-3/project-documentation/by-class/ProgressBarControlPane.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000AW-ProgressBarControlPane-class-source-quality.md`  
Assignment: report-only Rule 26 source-quality pass. No by-* documentation and no coverage file were edited in this pass.

## Summary recommendation

`ProgressBarControlPane` should stay source-bearing and reconstructable under [UID:0000AW], emitted through [UID:0000MT] `ProgressBarControlPane.cpp`. The current `86/85` target score is stale because the unresolved helper-name and blank-C++ blockers can be closed with a defensible class declaration plus child method drafts.

Recommended metadata for the class page:

```yaml
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000MT
EMITTER_UIDS:
  - 0000MT
```

Recommended source-facing names:

- `ProgressBarControlPane::ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)` for [UID:000119].
- `ProgressBarControlPane::SetMinValue(short minValue)` for [UID:000115] at `0x00494a90`.
- `ProgressBarControlPane::SetMaxValue(short maxValue)` for [UID:000117] at `0x00494af0`.
- `ProgressBarControlPane::SetCurrentValue(short value)` for [UID:0003N1] at `0x00494b50`.
- `ProgressBarControlPane::AddCurrentValue(short delta)` for [UID:00011A] at `0x00494db0`.
- `ProgressBarControlPane::DrawProgressBar()` for [UID:00011C] at `0x00494de0`; `OnPaint`/`Paint` remains a possible alternate only if a later project-wide paint-virtual naming sweep chooses that convention.

Recommended field names:

- `+0xf8`: `m_minValue`.
- `+0xfa`: `m_currentValue`.
- `+0xfc`: `m_maxValue`.
- `+0x44`: inherited pane bounds, source-facing `m_bounds` / `RectBounds`.
- `+0x70`: inherited draw/fill mode byte; exact original field name is still not proven, but `m_drawMode` is a useful draft name.

The raw/no-direct-xref helper caveat should remain documented, but it is not a no-code proof. The raw helpers are class-specific source-authored progress-control mutators, not compiler thunks or library glue.

## Evidence checked

Project documentation reviewed:

- `by-class/ProgressBarControlPane.md`
- `by-file/ProgressBarControlPane.md`
- `by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md`
- `by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md`
- `by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md`
- `by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md`
- `by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md`
- `by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md`
- `by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md`
- `by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md`
- `by-type/by-vtable/ProgressBarControlPaneVtables.md`
- `by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md`
- `by-class/ControlPane.md`
- `by-file/ControlPane.md`
- `by-file/PatchPane.md`
- `by-class/PatchPane.md`
- `by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
- `project-documentation/wave3_data_issues.md`
- generated coverage and generated output attachments for `ProgressBarControlPane`.

Current-session direct binary check:

- Local PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP was attempted at `127.0.0.1:13337/mcp`; it was unavailable, so this pass distinguishes the existing docs' live-IDA evidence from current-session PE/Capstone confirmation.
- `.text` contains the exact target bodies and padding; `.rdata` contains the vtable dwords listed below.

## Current-session binary findings

Function/island boundaries:

- `0x00494a81-0x00494a90`: fifteen `0xcc` bytes before the range-start helper.
- `0x00494a90-0x00494ae7`: raw range-start/min setter body, ending with `ret 4` at `0x00494ae4`.
- `0x00494ae7-0x00494af0`: nine `0xcc` bytes between range setters.
- `0x00494af0-0x00494b4b`: raw range-end/max setter body, ending with `ret 4` at `0x00494b48`.
- `0x00494b4b-0x00494b50`: five `0xcc` bytes before modeled current setter.
- `0x00494b50-0x00494b77`: modeled current setter body, ending with an unchanged-value `ret 4` path and a changed-value tail jump through inherited invalidation.
- `0x00494b77-0x00494b80`: nine `0xcc` bytes before neighboring ControlPane state virtuals.
- `0x00494c80-0x00494daa`: constructor body.
- `0x00494daa-0x00494db0`: six `0xcc` bytes before current-value adder.
- `0x00494db0-0x00494dde`: raw current-value adder body.
- `0x00494dde-0x00494de0`: two `0xcc` bytes before draw body.
- `0x00494de0-0x00494eb0`: modeled draw body.

Direct route/search findings:

- Direct call/jump scan found no `E8`/`E9` refs to `0x00494a90`, `0x00494af0`, or `0x00494db0`.
- Direct long conditional branch scan found no refs to `0x00494a90`, `0x00494af0`, `0x00494b50`, `0x00494db0`, or `0x00494de0`.
- VA/RVA pointer scan found no pointer/table refs to `0x00494a90`, `0x00494af0`, `0x00494b50`, or `0x00494db0`.
- `0x00494de0` appears as a VA only in the primary vtable slot at `0x00617b78`.
- Constructor caller is `0x005472d7` in `PatchPane::PatchPane`, after allocation size `0x108` and pushes for `bounds`, `0`, and `100`.
- Modeled current setter callers are `0x005476ed` and `0x0054783f` in [UID:0001ER] `PatchPanePacketResponseHandler`: the first sends computed patch percent progress, the second resets the progress value to zero.

Vtable facts:

- Primary RTTI/vtable pair: RTTI at `0x00617b30`, vtable at `0x00617b34`.
- Primary destructor slot `+0x00`: `0x0049b170`, inherited `ControlPane` scalar deleting destructor.
- Primary inherited invalidation/refresh slot `+0x20`: `0x00544800`; all state-change mutators call this through the vtable with `this+0x44`.
- Primary draw slot `+0x44`: `0x00494de0`, `ProgressBarControlPane::DrawProgressBar`.
- Primary following state virtuals `+0x48..+0x5c`: `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, `0x00494c30`; these remain `ControlPane`-owned state helpers, not progress-bar methods.
- Secondary RTTI/vtable pair: RTTI at `0x00617b98`, vtable at `0x00617b9c`, constructor store at `0x00494ccb`, offset `+0xa0`.
- Tertiary RTTI/vtable pair: RTTI at `0x00617bc8`, vtable at `0x00617bcc`, constructor store at `0x00494cd5`, offset `+0xa4`.
- Secondary and tertiary destructor entries are compiler-generated adjustor thunks (`0x0049af3d`, `0x0049af48`) and should not produce handwritten C++ on the class child method pages.

Body semantics:

- `SetMinValue` clamps the input to `[0, 30000]`, compares it against `+0xf8`, raises `+0xfa` if current is below the new minimum, invalidates after the current raise, writes `+0xf8`, and invalidates again.
- `SetMaxValue` clamps the input to `[0, 30000]`, compares it against `+0xfc`, lowers `+0xfa` if current is above the new maximum, invalidates after the current lower, writes `+0xfc`, and invalidates again.
- `SetCurrentValue` does not clamp. It compares the stack argument with `+0xfa`, writes `+0xfa` only on change, and tail-calls the inherited invalidation slot with the bounds at `+0x44`.
- The constructor calls the base `ControlPane` constructor at `0x004949e0` with control type `0x16` (22), installs the three ProgressBarControlPane vtable views, applies the same clamp/sync behavior for min and max constructor arguments, and resets current to zero if needed.
- `AddCurrentValue` reads the old 16-bit current value, adds the stack argument, truncates the result to 16 bits, writes `+0xfa` only if the low 16-bit value changed, and invalidates through the inherited slot.
- `DrawProgressBar` reads `+0xf8/+0xfa/+0xfc`, computes `splitX = bounds.left + ((current - min) * (bounds.right - bounds.left)) / (max - min)` when min and max differ, falls back to `bounds.left` when they match, builds filled and empty `RectBounds`, clears the inherited draw/fill mode byte at `+0x70`, sets draw colors `1`, `143`, and `128`, fills the two rectangles through `SurfaceRenderCallbackTable` slot `0x0069b3fc`, and frames the full bounds through `GrafPort::DrawRectFrame` at `0x004ba450`.

## Source-quality decisions

Owner/emitter:

- Keep class owner [UID:0000AW] and file emitter [UID:0000MT].
- Keep method children under [UID:0000AW].
- Keep [UID:000116] `ProgressBarRangeSetters` and [UID:00011B] `ProgressBarControlPaneUpdateAndDraw` as non-emitting duplicate aggregates. They are useful inventories but should not own formal source.

Rejected ownership/source-placement alternatives:

- `PatchPane` is only a consumer. It constructs the progress bar for Auto Patch and calls `SetCurrentValue`; it does not own progress control implementation.
- `ControlPane` owns the base constructor, inherited invalidation slot, and neighboring state virtuals, but not the `+0xf8/+0xfa/+0xfc` progress fields or the progress mutators.
- `ButtonControlPane`, other nearby controls, and the vtable-data page are rejected as owners because the constructor installs `ProgressBarControlPane` vtables and the bodies operate on ProgressBar-specific fields.
- `SurfaceRenderCallbackTable` and `GrafPort` are draw dependencies only. Do not move `DrawProgressBar` into them.

Raw/no-xref helper policy:

- The no-direct-xref status for `SetMinValue`, `SetMaxValue`, and `AddCurrentValue` should stay visible because it caps certainty and explains why the old generated output omitted them.
- It is not a no-code proof. These bodies are not compiler thunks, destructors, RTTI, or STL/runtime glue. They are hand-authored, thiscall-shaped mutators over class fields with normal range/current/invalidation behavior.
- The safest implementation is to emit first-draft C++ on the exact child pages and record their raw/no-caller caveat, not to blank them or merge them into aggregates.

Generated-name/control-character caveat:

- Existing project docs mention stale generated metadata and a constructor-name/control-character caveat. This pass found the active ProgressBar-specific `wave3_data_issues.md` evidence for omitted projected helpers and `class_ProgressBarControlPane.meta_wave3` `vtable_count:0`.
- Treat generated labels such as `sub_494B50` and any `class_ProgressBarControlPane` metadata artifact as historical generated-output issues, not source-facing names.
- Do not use raw names in formal C++ except as evidence comments in prose.

## First-draft class C++

Class page [UID:0000AW] should receive declaration-level C++ with a child insertion point. Method bodies belong on the exact by-memory child pages.

```cpp
class ProgressBarControlPane : public ControlPane
{
public:
    ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue);

    void SetMinValue(short minValue);
    void SetMaxValue(short maxValue);
    void SetCurrentValue(short value);
    void AddCurrentValue(short delta);

protected:
    virtual void DrawProgressBar();

private:
    enum
    {
        kMaxProgressValue = 30000
    };

    // ProgressBarControlPane fields begin at +0xf8 after the inherited ControlPane state.
    short m_minValue;      // +0xf8
    short m_currentValue;  // +0xfa
    short m_maxValue;      // +0xfc

    [[CHILDREN]]
};
```

## First-draft child method C++

[UID:000115] `0x00494a90-0x00494ae7`:

```cpp
void ProgressBarControlPane::SetMinValue(short minValue)
{
    if (minValue < 0)
        minValue = 0;
    else if (minValue > kMaxProgressValue)
        minValue = kMaxProgressValue;

    if (m_minValue == minValue)
        return;

    if (m_currentValue < minValue) {
        m_currentValue = minValue;
        Invalidate(&m_bounds);
    }

    m_minValue = minValue;
    Invalidate(&m_bounds);
}
```

[UID:000117] `0x00494af0-0x00494b4b`:

```cpp
void ProgressBarControlPane::SetMaxValue(short maxValue)
{
    if (maxValue < 0)
        maxValue = 0;
    else if (maxValue > kMaxProgressValue)
        maxValue = kMaxProgressValue;

    if (m_maxValue == maxValue)
        return;

    if (m_currentValue > maxValue) {
        m_currentValue = maxValue;
        Invalidate(&m_bounds);
    }

    m_maxValue = maxValue;
    Invalidate(&m_bounds);
}
```

[UID:0003N1] `0x00494b50-0x00494b77`:

```cpp
void ProgressBarControlPane::SetCurrentValue(short value)
{
    if (m_currentValue == value)
        return;

    m_currentValue = value;
    Invalidate(&m_bounds);
}
```

[UID:000119] `0x00494c80-0x00494daa`:

```cpp
ProgressBarControlPane::ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)
    : ControlPane(22, bounds)
{
    if (minValue < 0)
        minValue = 0;
    else if (minValue > kMaxProgressValue)
        minValue = kMaxProgressValue;

    if (m_minValue != minValue) {
        if (m_currentValue < minValue) {
            m_currentValue = minValue;
            Invalidate(&m_bounds);
        }

        m_minValue = minValue;
        Invalidate(&m_bounds);
    }

    if (maxValue < 0)
        maxValue = 0;
    else if (maxValue > kMaxProgressValue)
        maxValue = kMaxProgressValue;

    if (m_maxValue != maxValue) {
        if (m_currentValue > maxValue) {
            m_currentValue = maxValue;
            Invalidate(&m_bounds);
        }

        m_maxValue = maxValue;
        Invalidate(&m_bounds);
    }

    if (m_currentValue != 0) {
        m_currentValue = 0;
        Invalidate(&m_bounds);
    }
}
```

Constructor caveat: the binary installs vtables explicitly between the base constructor and the field logic. Formal C++ should not spell those vptr stores.

[UID:00011A] `0x00494db0-0x00494dde`:

```cpp
void ProgressBarControlPane::AddCurrentValue(short delta)
{
    short value = static_cast<short>(m_currentValue + delta);
    if (m_currentValue == value)
        return;

    m_currentValue = value;
    Invalidate(&m_bounds);
}
```

[UID:00011C] `0x00494de0-0x00494eb0`:

```cpp
void ProgressBarControlPane::DrawProgressBar()
{
    int splitX = m_bounds.left;
    if (m_minValue != m_maxValue) {
        splitX += ((m_currentValue - m_minValue) * (m_bounds.right - m_bounds.left)) /
            (m_maxValue - m_minValue);
    }

    RectBounds filledBounds = m_bounds;
    filledBounds.right = splitX;

    RectBounds emptyBounds = m_bounds;
    emptyBounds.left = splitX;

    m_drawMode = 0;

    SetDrawColor(1);
    FillRect(&filledBounds);

    SetDrawColor(143);
    FillRect(&emptyBounds);

    SetDrawColor(128);
    DrawRectFrame(&m_bounds);
}
```

Draw helper naming caveat: `FillRect` is the source-facing wrapper for [UID:SurfaceRenderCallbackTable] slot `0x0069b3fc`; do not emit raw `dword_69B3FC` or generated `g_pfnLockSurface`. `SetDrawColor` corresponds to `0x004b9660`; `DrawRectFrame` corresponds to `0x004ba450`.

## Recommended target/support changes for implementation callback

Target `by-class/ProgressBarControlPane.md`:

- Change score to `COMPLETION:88`, `CONFIDENCE:90`.
- Keep reconstructable true, owner/emitter [UID:0000MT].
- Replace the stale blank-C++/private-helper blocker with the class declaration above.
- Record the exact field map `m_minValue +0xf8`, `m_currentValue +0xfa`, `m_maxValue +0xfc`.
- Record `sizeof(ProgressBarControlPane) == 0x108` as a high-confidence allocation-size inference from `PatchPane::PatchPane` at `0x005472d7`.
- Add explicit source-name recommendations for the five child methods and draw virtual.
- Preserve the caveat that raw helper liveness is no-direct-xref/no-pointer in the current executable.
- Preserve the vtable-only draw reachability at `0x00617b78`.
- Record that the inherited invalidation/refresh slot is primary vtable `+0x20`, `0x00617b54 -> 0x00544800`.
- Record that `SetCurrentValue` has live PatchPane callers at `0x005476ed` and `0x0054783f`.
- Reject PatchPane ownership, ControlPane ownership for progress fields, ButtonControlPane ownership, aggregate ownership, and vtable-data ownership.

Support `by-file/ProgressBarControlPane.md`:

- Mirror the class-level source-shape recommendation, score recommendation, field map, child method names, and raw/no-xref caveat.
- State that `NexusTK/ui/controls/ProgressBarControlPane.cpp` should emit the class declaration plus child methods once children are updated.
- Keep PatchPane as a consumer relationship only.

Child by-memory method docs:

- [UID:000115]: rename/source-shape to `SetMinValue(short minValue)`, add first-draft C++, and recommend `87/89`.
- [UID:000117]: rename/source-shape to `SetMaxValue(short maxValue)`, add first-draft C++, and recommend `87/89`.
- [UID:0003N1]: keep/upgrade source-shape to `SetCurrentValue(short value)`, add first-draft C++, and recommend `88/91`.
- [UID:000119]: add constructor C++, keep vptr-store caveat, and recommend `88/91`.
- [UID:00011A]: source-shape to `AddCurrentValue(short delta)`, add first-draft C++, and recommend `87/89`.
- [UID:00011C]: keep source-shape `DrawProgressBar()`, add first-draft C++, and recommend `88/91`.

Aggregate docs:

- [UID:000116] and [UID:00011B] should stay non-emitting duplicate inventories. Add a short note that exact child pages now carry the source-facing names and C++.

Vtable docs:

- `by-type/by-vtable/ProgressBarControlPaneVtables.md` and `by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md` should record that vtable/adjustor artifacts are generated by the class declaration. No handwritten vtable C++ is needed.
- Keep the secondary/tertiary destructor thunks as compiler-generated no-code artifacts.

Dependency support docs:

- `ControlPane` docs should continue to own the base constructor, inherited invalidation slot, and state virtual helpers. Add a cross-reference that ProgressBar mutators call the inherited invalidation slot but do not belong to `ControlPane`.
- `PatchPane` docs should keep the constructor/current setter consumer route and avoid implying ownership of progress control implementation.
- `SurfaceRenderCallbackTable` docs should keep slot `0x0069b3fc` described as the active rectangle fill wrapper used by controls such as `ProgressBarControlPane::DrawProgressBar`.
- `GrafPortDrawStateAccessors` and `GrafPortDrawRectFrame` docs can add ProgressBar draw as a consumer if that detail is missing.

Generated output expectation after implementation:

- `auto-generated/NexusTK/ui/controls/ProgressBarControlPane.cpp` should change from emitter markers only to a nonblank class declaration and child method bodies.
- Generated coverage/stat files may change after validator/application; report them in the implementation callback result if they do.

## Exact coverage text

Do not edit coverage files during report-only work. If implementation accepts this report, use these replacement rows or adapt only for wording changes made during implementation.

`by-class/-coverage-report.md` replacement row:

```markdown
- [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) : reconstructable : 88% : very-strong : B005 source-quality pass resolves the stale helper-name/blank-C++ blocker: emit declaration-level `class ProgressBarControlPane : public ControlPane` with `m_minValue +0xf8`, `m_currentValue +0xfa`, `m_maxValue +0xfc`, public mutators `SetMinValue`, `SetMaxValue`, `SetCurrentValue`, `AddCurrentValue`, protected virtual `DrawProgressBar`, and `[[CHILDREN]]`. Local PE/Capstone recheck reconfirms exact helper boundaries/padding, no direct branch/call or VA/RVA pointer refs to raw helper starts, modeled `SetCurrentValue` PatchPane callers at `0x005476ed`/`0x0054783f`, constructor caller `0x005472d7` with allocation `0x108` and args `bounds,0,100`, draw vtable slot `0x00617b78`, inherited invalidation slot `0x00617b54 -> 0x00544800`, and SurfaceRenderCallbackTable fill slot `0x0069b3fc` plus `GrafPort::DrawRectFrame` dependency. Preserve raw no-xref caveat, reject PatchPane/ControlPane/ButtonControlPane ownership, and treat Wave3 omitted-helper/vtable-count/control-character issues as generated metadata caveats.
```

`by-file/-coverage-report.md` replacement row:

```markdown
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) : reconstructable : 88% : very-strong : B005 source-quality pass resolves `NexusTK/ui/controls/ProgressBarControlPane.cpp` as the source file for [UID:0000AW] and its exact method children: constructor `ProgressBarControlPane(const RectBounds*, short, short)`, `SetMinValue`, `SetMaxValue`, `SetCurrentValue`, `AddCurrentValue`, and `DrawProgressBar`. Evidence includes PatchPane construction at `0x005472d7`, PatchPane current-value callers at `0x005476ed`/`0x0054783f`, primary draw vtable slot `0x00617b78`, inherited invalidation slot `0x00617b54`, field map `+0xf8/+0xfa/+0xfc`, raw helper no-xref/padding checks, and draw dependencies on `0x0069b3fc`, `0x004b9660`, and `0x004ba450`; PatchPane is a consumer, not owner.
```

`by-memory/-coverage-report.md` replacement rows:

```markdown
    - [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) 0x00494a90-0x00494ae7 | method | ProgressBarControlPaneRangeStartSetter : reconstructable : 87% : strong : B005 source-quality pass recommends source-facing `ProgressBarControlPane::SetMinValue(short minValue)` with first-draft C++; current PE recheck reconfirms the raw body, fifteen-byte prepad, nine-byte postpad, clamp to `0..30000`, `+0xf8` min write, optional `+0xfa` current raise, invalidation through inherited vtable slot `+0x20`, and no direct branch/call or VA/RVA pointer refs to `0x00494a90`. Keep raw/no-caller caveat but reject no-code because the body is source-authored progress-control logic.
    - [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md) 0x00494af0-0x00494b4b | method | ProgressBarControlPaneRangeEndSetter : reconstructable : 87% : strong : B005 source-quality pass recommends source-facing `ProgressBarControlPane::SetMaxValue(short maxValue)` with first-draft C++; current PE recheck reconfirms the raw body, nine-byte prepad, five-byte postpad, clamp to `0..30000`, `+0xfc` max write, optional `+0xfa` current lower, invalidation through inherited vtable slot `+0x20`, and no direct branch/call or VA/RVA pointer refs to `0x00494af0`. Keep raw/no-caller caveat but reject no-code because the body is source-authored progress-control logic.
        - [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) 0x00494b50-0x00494b77 | method | ProgressBarControlPaneSetCurrentValue : reconstructable : 88% : very-strong : B005 source-quality pass keeps source-facing `ProgressBarControlPane::SetCurrentValue(short value)` and adds first-draft C++; current PE recheck reconfirms modeled function boundaries, nine-byte postpad, no clamp, `+0xfa` current write on change only, inherited invalidation through vtable slot `+0x20`, and PatchPane callers at `0x005476ed` for computed percent progress and `0x0054783f` for reset to zero.
    - [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) 0x00494c80-0x00494daa | method | ProgressBarControlPaneConstructor : reconstructable : 88% : very-strong : B005 source-quality pass recommends `ProgressBarControlPane::ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)` with first-draft C++; evidence reconfirms base `ControlPane` constructor call with control type `22`, vtable stores at `+0/+0xa0/+0xa4`, field clamp/sync behavior for `+0xf8/+0xfa/+0xfc`, current reset to zero, PatchPane constructor caller at `0x005472d7`, allocation size `0x108`, and non-source vptr-store caveat.
    - [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) 0x00494db0-0x00494dde | method | ProgressBarControlPaneCurrentValueAdder : reconstructable : 87% : strong : B005 source-quality pass recommends source-facing `ProgressBarControlPane::AddCurrentValue(short delta)` with first-draft C++; current PE recheck reconfirms the raw body, six-byte prepad, two-byte postpad, 16-bit current read/add/truncate behavior, `+0xfa` write on changed low 16-bit value, inherited invalidation through vtable slot `+0x20`, and no direct branch/call or VA/RVA pointer refs to `0x00494db0`. Keep raw/no-caller caveat but reject no-code because the body is source-authored progress-control logic.
    - [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) 0x00494de0-0x00494eb0 | method | ProgressBarControlPaneDrawProgressBar : reconstructable : 88% : very-strong : B005 source-quality pass keeps source-facing `ProgressBarControlPane::DrawProgressBar()` and adds first-draft C++; current PE recheck reconfirms vtable-only reachability at `0x00617b78`, split formula over `+0xf8/+0xfa/+0xfc`, degenerate min==max handling, two local `RectBounds`, inherited draw-mode byte clear at `+0x70`, colors `1/143/128`, fill calls through SurfaceRenderCallbackTable slot `0x0069b3fc`, and frame call to `GrafPort::DrawRectFrame` at `0x004ba450`.
```

## Validation commands for implementation callback

Run scoped validators only for docs touched during implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0000AW-ProgressBarControlPane-class-source-quality-removed.md](0000AW-ProgressBarControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation touches `ControlPane`, `PatchPane`, `SurfaceRenderCallbackTable`, `GrafPortDrawStateAccessors`, or `GrafPortDrawRectFrame`, run the same scoped validator for each touched support doc.

## IDA rename/type/comment recommendations

High confidence:

- Rename/type `0x00494b50` as `void __thiscall ProgressBarControlPane::SetCurrentValue(short value)`.
- Rename/type `0x00494c80` as `ProgressBarControlPane *__thiscall ProgressBarControlPane::ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)`.
- Rename/type `0x00494de0` as `void __thiscall ProgressBarControlPane::DrawProgressBar()`.
- In the class layout, name `+0xf8` `m_minValue`, `+0xfa` `m_currentValue`, and `+0xfc` `m_maxValue`.
- Comment primary vtable slot `0x00617b78` as `ProgressBarControlPane::DrawProgressBar`.
- Comment primary vtable slot `0x00617b54` as inherited invalidation/refresh over a `RectBounds`.

Medium confidence, because IDA currently does not model these as functions:

- If the analysis owner elects to create functions for raw helper bodies, name/type `0x00494a90` as `void __thiscall ProgressBarControlPane::SetMinValue(short minValue)`.
- If the analysis owner elects to create functions for raw helper bodies, name/type `0x00494af0` as `void __thiscall ProgressBarControlPane::SetMaxValue(short maxValue)`.
- If the analysis owner elects to create functions for raw helper bodies, name/type `0x00494db0` as `void __thiscall ProgressBarControlPane::AddCurrentValue(short delta)`.

Low/avoid:

- Do not rename the raw helpers to generated labels such as `sub_494A90`, `sub_494AF0`, or `sub_494DB0` in source docs.
- Do not type the secondary/tertiary destructor adjustor thunks as handwritten class methods.
- Do not force `OnPaint` over `DrawProgressBar` unless a project-wide virtual paint naming rule is applied consistently.

## Remaining issues and impact

- Exact original names for `SetMinValue`, `SetMaxValue`, `AddCurrentValue`, `DrawProgressBar`, and `m_drawMode` are not proven by strings/PDB/source. The recommended names are high-probability source-facing names derived from body semantics and existing project docs.
- The three raw helpers still have no direct call, branch, or pointer route in the current executable. This should remain a documented liveness caveat and confidence cap, not a no-code blocker.
- The constructor body relies on field values after the base constructor/custom allocation path; the first-draft C++ intentionally expresses the observed conditional writes without spelling vptr stores.
- A later generated-output refresh should verify that class-level `[[CHILDREN]]` plus child method C++ produces a nonblank `auto-generated/NexusTK/ui/controls/ProgressBarControlPane.cpp` and does not duplicate aggregate content.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000AW-ProgressBarControlPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000AW"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000AW-ProgressBarControlPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0000AW-ProgressBarControlPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
