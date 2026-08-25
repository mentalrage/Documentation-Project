*** UID:0000AW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProgressBarControlPane

## Status

- Confidence: very strong for constructor/draw/vtable ownership, exact helper boundaries and hashes, signed field roles and clamp flow, inherited range storage/invalidation/member route, source placement, legal generated child placement, and exhaustive raw-helper no-route evidence; strong for inferred original lexical spellings.
- Likely source file: [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- Final C++ status: declaration-level first draft populated. The class closes before `[[CHILDREN]]`, so exact by-memory child definitions assemble at file scope without illegal qualified definitions inside the class or duplicate aggregate bodies.
- Vtables: [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`

## Class Purpose

`ProgressBarControlPane` is a `ControlPane`-derived progress indicator. It interprets the protected `ControlPane` range triplet as its lower bound, current value, and upper bound, clamps public range input to `0..30000`, invalidates the pane when state changes, and paints a horizontal filled/empty bar with a frame. It introduces no derived range storage: the accepted complete `ControlPane` layout is already `0x108` bytes and owns `m_rangeStart +0xf8`, `m_rangeCurrent +0xfa`, and `m_rangeEnd +0xfc`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetMinValue(short minValue)` | [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) | Exact 87-byte raw source method. Signed-clamps to `0..30000`, returns unchanged with no side effects, optionally raises inherited `m_rangeCurrent`, writes inherited `m_rangeStart`, and calls `InvalidateRect(&m_visibleBounds)` zero, one, or two times. |
| `SetMaxValue(short maxValue)` | [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md) | Exact 91-byte raw source method. Signed-clamps to `0..30000`, returns unchanged with no side effects, optionally lowers inherited `m_rangeCurrent`, writes inherited `m_rangeEnd`, and calls `InvalidateRect(&m_visibleBounds)` zero, one, or two times. |
| `SetCurrentValue(short value)` | [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) | Modeled setter for inherited `m_rangeCurrent` at `+0xfa`; PatchPane packet responses call it for computed percent progress and reset-to-zero, and changed state tail-dispatches `InvalidateRect(&m_visibleBounds)`. |
| `ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)` | [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | Constructs the control with `ControlPane` type `22`, installs generated vtable views, clamps initial range fields, synchronizes current, and resets current value to `0`. |
| `AddCurrentValue(short delta)` | [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) | Exact unique 46-byte retained source method, SHA-256 `D13A5B1018EA66A5752E53501A6F8E1EDFE0A50C53BA804A54BFA89AF328AA7C`, adds the signed delta to inherited `m_rangeCurrent +0xfa`, truncates modulo 16 bits, returns with no side effects when the stored word is unchanged, and otherwise writes current before one `InvalidateRect(&m_visibleBounds)`. IDA does not model the start and no external entry/pointer route survives; complete ABI/class evidence rejects no-code/compiler residue. Target score is `93/94`. |
| `DrawProgressBar()` | [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) | Computes the filled width from inherited `m_rangeStart/m_rangeCurrent/m_rangeEnd`, draws filled and empty rectangles through the active fill callback, and frames `m_visibleBounds`. |

## Field Map And Source Shape

| Offset | Source-facing name | Evidence-backed role |
| --- | --- | --- |
| inherited `+0x44` | `GrafPort::m_visibleBounds` / `RectBounds` | Current PaneLayout/GrafPort authority: rectangle passed to `Pane::InvalidateRect` and copied by draw. Historical `m_bounds`/`m_localBounds` aliases are superseded. |
| inherited `+0x70` | `m_drawMode` | Draw/fill mode byte cleared before the fill calls in `DrawProgressBar`; exact original inherited field name is not proven. |
| inherited `+0xf8` | `ControlPane::m_rangeStart` | Lower progress-range value written by `SetMinValue` and constructor and consumed by `DrawProgressBar`. Earlier `m_minValue` wording was a semantic alias, not a physically separate derived member. |
| inherited `+0xfa` | `ControlPane::m_rangeCurrent` | Current progress value written by constructor, `SetCurrentValue`, `AddCurrentValue`, and range synchronization; consumed by `DrawProgressBar`. Earlier `m_currentValue` wording was a semantic alias, not a physically separate derived member. |
| inherited `+0xfc` | `ControlPane::m_rangeEnd` | Upper progress-range value written by `SetMaxValue` and constructor and consumed by `DrawProgressBar`. Earlier `m_maxValue` wording was a semantic alias, not a physically separate derived member. |

`sizeof(ProgressBarControlPane)` is high-confidence `0x108` from the `PatchPane::PatchPane` allocation at `0x005472d7`. The accepted complete `ControlPane` declaration is itself `0x108`, including the range triplet and tail state through `+0x107`; therefore `ProgressBarControlPane` cannot redeclare fields at `+0xf8/+0xfa/+0xfc` without moving them to `+0x108` or later and breaking the executable layout. That caller pushes the constructor arguments `bounds`, `0`, and `100`, so the source-facing constructor is `ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)`. The class declaration closes first; `[[CHILDREN]]` then emits exact qualified method definitions at file scope.

## Historical B005 Source-Quality Closure

The stale blank-C++ blocker is superseded. The active code-entry policy allows first-draft C++ because the class and file emitter are reconstructable, have a valid emitter chain through [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md), and now clear the combined evidence gate. The remaining uncertainty is naming provenance rather than source-shape safety: exact original names for `SetMinValue`, `SetMaxValue`, `AddCurrentValue`, `DrawProgressBar`, and `m_drawMode` are not proven by PDB/source strings, but the accepted descriptive names match the body semantics and project naming style.

Current-session PE/Capstone recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms the helper boundaries and padding:

- `0x00494a81-0x00494a90`: fifteen `0xcc` bytes before `SetMinValue`.
- `0x00494a90-0x00494ae7`: raw `SetMinValue` body, ending with `ret 4` at `0x00494ae4`.
- `0x00494ae7-0x00494af0`: nine `0xcc` bytes between range setters.
- `0x00494af0-0x00494b4b`: raw `SetMaxValue` body, ending with `ret 4` at `0x00494b48`.
- `0x00494b4b-0x00494b50`: five `0xcc` bytes before the modeled current setter.
- `0x00494b50-0x00494b77`: modeled `SetCurrentValue` body, ending with an unchanged-value `ret 4` path and a changed-value tail jump through inherited invalidation.
- `0x00494b77-0x00494b80`: nine `0xcc` bytes before neighboring base `ControlPane` state virtuals.
- `0x00494c80-0x00494daa`: constructor body.
- `0x00494daa-0x00494db0`: six `0xcc` bytes before `AddCurrentValue`.
- `0x00494db0-0x00494dde`: raw `AddCurrentValue` body.
- `0x00494dde-0x00494de0`: two `0xcc` bytes before the draw body.
- `0x00494de0-0x00494eb0`: modeled `DrawProgressBar` body.

Direct route/search findings should remain visible as a confidence cap rather than a no-code proof. The current scan found no direct `E8`/`E9` branch/call refs, no long conditional branch refs, and no VA/RVA pointer/table refs to raw helper starts `0x00494a90`, `0x00494af0`, or `0x00494db0`. `0x00494de0` appears as a VA only in the primary vtable slot at `0x00617b78`. `SetCurrentValue` is the live modeled setter with PatchPane callers at `0x005476ed` for computed patch percent progress and `0x0054783f` for reset to zero.

Vtable evidence stays class-owned and generated-binary aware. The primary RTTI/vtable pair is `0x00617b30/0x00617b34`; primary destructor slot `+0x00` is inherited `ControlPane` scalar deleting destructor `0x0049b170`; inherited invalidation/refresh slot `+0x20` is `0x00617b54 -> 0x00544800` and all state-change mutators call it with `this+0x44`; the primary draw slot `+0x44` is `0x00617b78 -> 0x00494de0`; the following `+0x48..+0x5c` state virtuals remain `ControlPane`-owned helpers, not progress-bar methods. Secondary and tertiary RTTI/vtable pairs at `0x00617b98/0x00617b9c` and `0x00617bc8/0x00617bcc` are installed at object offsets `+0xa0` and `+0xa4`; destructor entries `0x0049af3d` and `0x0049af48` are compiler-generated adjustor thunks and should not produce handwritten C++.

Body semantics are now source-quality enough for child C++: `SetMinValue` and `SetMaxValue` clamp public range input to `[0, 30000]`, synchronize current only when the new bound would exclude it, and invalidate after each observed state mutation; `SetCurrentValue` performs no clamp and writes `+0xfa` only on change; `AddCurrentValue` performs a 16-bit add/truncate and invalidates only when the low word changes; `DrawProgressBar` computes `splitX = bounds.left + ((current - min) * (bounds.right - bounds.left)) / (max - min)` when min and max differ, falls back to the left edge on a degenerate range, builds two local `RectBounds`, clears `m_drawMode`, fills with colors `1` and `143` through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc`, then sets color `128` and frames through [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md).

Generated metadata caveats are historical artifacts only. `class_ProgressBarControlPane.meta_wave3` reported `vtable_count:0`, projected helpers were omitted from generated output, and older notes mention a constructor-name/control-character artifact. Those explain previous output gaps but should not be used as source-facing names or reasons to blank current formal C++.

## B003 UID00011A Exact AddCurrentValue Closure

[UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) now has complete target-specific source-quality closure at `93/94`.

### Binary Identity, Boundaries, And Liveness

- Exact body: `[0x00494db0,0x00494dde)`, 46 bytes (`0x2e`), RVA `0x00094db0`, raw offset `0x000941b0`.
- SHA-256: `D13A5B1018EA66A5752E53501A6F8E1EDFE0A50C53BA804A54BFA89AF328AA7C`.
- Six `0xcc` bytes precede the body at `0x00494daa-0x00494db0`; two `0xcc` bytes follow at `0x00494dde-0x00494de0`; modeled `DrawProgressBar` starts at `0x00494de0`.
- Live MCP and independent whole-file scans each find the full body exactly once.
- No IDA function object, start xref, ordinary caller, external alternate instruction-head entry, decoded external branch/call target, or VA/RVA/raw-offset pointer route survives.
- An apparent raw short branch into `0x00494dd3` is rejected because the apparent opcode byte at `0x00494e11` is an operand inside draw's real `movd eax,xmm0` instruction at `0x00494e0f`.

The complete thiscall frame, state read, add, post-add low-word normalization, conditional branch, state write, bounds address, and inherited virtual tail dispatch classify the body as retained source-authored class logic. It is not padding, table data, runtime glue, a compiler thunk, or an inline duplicate. No surviving route is a historical liveness/confidence cap rather than a no-code condition.

### Exact Source Behavior

`m_rangeCurrent` and signed `short delta` promote to `int`; their mathematical sum cannot overflow 32-bit `int`. Target MSVC then converts the local `short value` to the same low 16 bits produced by `movzx eax,ax`. The method therefore performs modulo-`2^16` addition and allows negative deltas/wraparound. It does not read `m_rangeStart`/`m_rangeEnd`, clamp, or saturate.

The old and new stored words are compared after truncation. Equality returns with no write and no invalidation. A changed word is written to inherited `m_rangeCurrent +0xfa` before exactly one virtual `Pane::InvalidateRect(&m_visibleBounds)` call through primary slot `+0x20`, `0x00617b54 -> 0x00544800`. The tail jump is compiler lowering; normal source remains the ordinary virtual call.

### Human Source Vocabulary And Source Placement

- Keep public `void AddCurrentValue(short delta)` beside the public Set*Value methods.
- Keep inherited `ControlPane::m_rangeCurrent`, inherited `GrafPort::m_visibleBounds`, and inherited `Pane::InvalidateRect`.
- Reject `IncrementCurrentValue` because delta may be negative; reject `AddValue` as too generic; reject `SetCurrentValue` because the body adds; reject `Step`/`AdvanceProgress`/`AddProgress` because they imply positive-only or higher-level behavior.
- Keep class owner [UID:0000AW] and file emitter [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md).
- Keep duplicate aggregate [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md) ownerless, non-reconstructable, non-emitting, and blank-formal.
- No class-layout, declaration-order, split, source-file, vtable, IDA, or generated-code change is required beyond the exact child documentation/score synchronization.

Raw `sub_494DB0`, `_WORD`, offset-only fields, direct vtable syntax, derived `m_currentValue`, `m_bounds`, and generic `Invalidate` survive only as explicitly superseded history. The existing formal is behavior-exact, human-looking C++03 source and remains unchanged.

## B002 Exact Family And Generated-Route Reanalysis

- Healthy IDA MCP session `9b0396a3` independently rederived both raw range children and their modeled supports.
- UID000115 is `[0x00494a90,0x00494ae7)`, 87 bytes, SHA256 `492B0F418A63322765FED4BC638EC5F0C508C298A006820C1A41D40DB7358FFA`; UID000117 is `[0x00494af0,0x00494b4b)`, 91 bytes, SHA256 `97E860E2BD72C33445F80E40C704E7DB7B8F1B8583D9AB2547639294CAFC882C`.
- Both use signed-short arguments and fields, clamp to `0..30000`, preserve an unchanged zero-side-effect path, synchronize current before writing the changed bound, and perform exact zero/one/two invalidation counts. Neither enforces `min <= max`.
- All decoded instruction/padding-start addresses have zero external xrefs; all target/sibling VA, RVA, and raw-offset pointer searches are empty. These are retained source-authored but unreferenced methods, not compiler artifacts or no-code ranges.
- `SetMinValue`, `SetMaxValue`, `SetCurrentValue`, `AddCurrentValue`, and `kMaxProgressValue` form the strongest coherent human progress API. Physical storage uses the already accepted protected `ControlPane::m_rangeStart/m_rangeCurrent/m_rangeEnd` names; `m_minValue/m_currentValue/m_maxValue` survive only as superseded semantic aliases. Raw/decompiler names and `SetRangeStart`/`SetRangeEnd` aliases remain evidence/history only.
- Primary vtable cell `0x00617b54 -> 0x00544800` resolves the inherited call as `Pane::InvalidateRect`; [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) resolves complete-object `+0x44` as inherited `GrafPort::m_visibleBounds`.
- Pre-callback generated checkpoint command `000000016699`, SHA256 `E500FF208C07D49387CBF73A7B412235CE19E03957F7DB9F933A029108BE3081`, placed qualified child definitions before the class closing brace and omitted UID0003N1. That is a source-assembly defect, not evidence against the method bodies.
- The accepted repair closes `ProgressBarControlPane` before `[[CHILDREN]]` and separately validates UID0003N1. UID000116 and compiler/vtable pages remain non-emitting.

## Score Rationale

- Completion is `92`: the declaration, exact child inventory, inherited range-storage/constant/type family, constructor/draw/current consumers, hashes/boundaries, raw-helper liveness, inherited API/member names, owner/file route, non-emitting aggregate boundaries, legal child insertion, and exact no-shadow-storage layout are implementation-ready.
- Confidence is `93`: live MCP bytes/flow/xrefs, PE hashes, RTTI/vtables, constructor stores, PatchPane callers, PaneLayout, and exact child pages agree.
- The class remains below `95` because exact original lexical spellings and the historical header/source split are not symbol-proven, and the raw min/max/add helpers have no surviving static entry routes. Human inferred names are still required in emitted C++.

## Owner And Dependency Decisions

Keep class owner [UID:0000AW] and file emitter [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md). `PatchPane` is a consumer only: it constructs the control at `0x005472d7` and drives `SetCurrentValue` through packet-response call sites, but it does not own reusable progress-control implementation. `ControlPane`/`Pane`/`GrafPort` own base construction, protected `m_rangeStart/m_rangeCurrent/m_rangeEnd`, inherited `InvalidateRect`, and inherited `m_visibleBounds`; `ProgressBarControlPane` owns the progress-specific API and interpretation of that base storage. `ButtonControlPane`, duplicate aggregate pages, the vtable-data page, [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), and `GrafPort` are rejected as target owners because the constructor installs `ProgressBarControlPane` vtables and the bodies implement a coherent progress-control method family. The raw/no-xref helpers are class-specific source-authored mutators, not compiler thunks, destructors, RTTI, STL/runtime glue, or dependency code.

## Evidence Notes

- Live IDA currently models the constructor, current setter, and draw virtual as functions while leaving the two range setters and `AddCurrentValue` as exact retained unmodeled source bodies.
- IDA confirms `0x00494c80` has one direct caller, `PatchPane::PatchPane` at `0x005472d7`.
- IDA confirms the draw routine is a vtable target at `0x00617b78`.
- 2026-05-26 IDA MCP vtable pass confirms primary/secondary/tertiary vtables at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`, installed by constructor stores at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5`.
- The three projected helpers touch the same field triplet (`0xf8`, `0xfa`, `0xfc`) and use the same vtable `+0x20` invalidation pattern as the constructor.
- Current generated metadata records a stored constructor-name control-character issue; treat the active emitted source name as cleaned, but keep the data issue tracked.
- 2026-05-26 recheck: IDA MCP still reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, with no direct xrefs. Keep them as projected private helper bytes under this class, not ignored/runtime code.
- 2026-06-01 byte recheck confirms the two range-setter helper bodies end at `0x00494ae7` and `0x00494b4b`, with only `0xcc` alignment between/after them.
- 2026-06-03 cross-documentation review ties the class attachment tree together: [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) is at the parent-confidence threshold, the exact helper children are assigned here with blank C++ bodies, [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md) proves the vtable data range, and the constructor/draw pages prove the modeled class core.
- 2026-06-05 live IDA refresh confirms the constructor is modeled at `0x00494c80` with size `0x12a`, the draw virtual is modeled at `0x00494de0` with size `0xd0`, and helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` remain unmodeled function-shaped code.
- 2026-06-05 `callers` reports the constructor call at `0x005472d7` in the PatchPane constructor and no ordinary direct callers for the draw virtual; `xrefs_to` reports no references to the three helper starts and the expected draw vtable data reference at `0x00617b78`.
- 2026-06-05 byte reads reconfirm `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, and `0x00494dde-0x00494de0` are alignment gaps, and `0x00617b78` stores the draw virtual pointer `0x00494de0`.
- 2026-06-08 Batch 113 IDA MCP recheck reconfirms the parent-gate evidence: `lookup_funcs` reports raw helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` are still not IDA functions; `0x00494c80-0x00494daa` remains the constructor with the `PatchPane` constructor caller at `0x005472d7`; `0x00494de0-0x00494eb0` remains the draw virtual with vtable data xref `0x00617b78`; and the helper/draw byte windows still show only `0xcc` alignment at `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, and `0x00494dde-0x00494de0`.
- 2026-06-10 B001-018 IDA MCP audit reconfirms the update/draw grouping: [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) is an unmodeled/no-xref 46-byte current-value helper, [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) is the modeled draw virtual with vtable data xref `0x00617b78`, and aggregate [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md) is a non-emitting duplicate inventory, not a separate source owner.
- 2026-06-13 B002 split repair confirms [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) is a modeled progress current-value setter, not part of the inherited `ControlPane` state virtuals. IDA reports only PatchPane progress-update callers and no vtable/data refs.
- 2026-07-23 B003 UID00011A live MCP/PE pass confirms the exact adder SHA-256, unique body, complete instruction/ABI behavior, exhaustive no-entry/no-pointer route, inherited source names, retained-source classification, and `93/94` child score. The class declaration, storage layout, score, owner, and emitter remain unchanged.

## Cross-References

- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md)
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md)
- [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md)
- [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md)
- [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md)
- [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated despite documenting constructor, draw behavior, range fields, vtables, and helper caveats.
  - After: Scored as high completion with medium-high confidence because several helper byte ranges remain projected private helpers rather than IDA-modeled functions.
  - Evidence: Existing method notes, field descriptions, IDA MCP vtable pass, and function-boundary caveats document the class behavior and remaining uncertainty.
- 2026-06-01: Marked the class reconstructable and attached it to the `ProgressBarControlPane` source-file page.
  - Before: validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE`, parent UID `0000MT`, and position `10`; no C++ code is emitted.
  - Evidence: constructor, draw virtual, vtables, and projected helper bytes are all documented as NexusTK-owned progress-bar control code, but final-source code still requires higher confidence and completion.
- 2026-06-03 parent-threshold consistency pass:
  - Before: confidence remained `78` while exact helper children were already attached under this class.
  - After: completion/confidence are `84/80`, with confidence raised only to the attachment threshold and final C++ still withheld at that time; this historical no-code state is superseded by the 2026-06-19 B005 implementation below.
  - Evidence: the file page, constructor, draw virtual, vtable data, range-setter aggregate, update/draw aggregate, exact helper pages, and autogen reports agree on this class as the progress-bar control owner.
- 2026-06-05 live IDA refresh:
  - Changed from `84/80` to `86/84`.
  - Removed stale recovered-file wording and the old unavailable-IDA caveat.
  - Evidence: live `lookup_funcs`, `callers`, `xrefs_to`, and byte reads confirm the modeled constructor/draw functions, PatchPane constructor caller, vtable-only draw reachability, unmodeled/no-xref private helpers, alignment gaps, and draw vtable pointer.
- 2026-06-08 Batch 113 parent-gate refresh:
  - Changed from `86/84` to `86/85`.
  - Evidence: fresh IDA MCP read-only checks reconfirm the constructor/draw modeled boundaries, PatchPane constructor caller, draw vtable reference, no-xref raw helper starts, helper byte bodies, and alignment gaps. The confidence increase was limited to the corrected `85/85` parent gate at that time; the blank-C++/private-helper-name blocker is superseded by the 2026-06-19 B005 implementation below.
- 2026-06-13 B002 current-setter split repair:
  - Scores unchanged.
  - Added [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) to the class method inventory after live IDA confirmed it writes the `+0xfa` current value used by this class and is called only by PatchPane progress updates.
- 2026-06-19 B005 accepted source-quality implementation:
  - Changed from `86/85` to `88/90`.
  - Added declaration-level first-draft C++ with `ProgressBarControlPane : public ControlPane`, constructor, public range/current mutators, protected `DrawProgressBar`, `kMaxProgressValue = 30000`, field comments for `m_minValue +0xf8`, `m_currentValue +0xfa`, `m_maxValue +0xfc`, and `[[CHILDREN]]`.
  - Replaced the stale blank-C++/private-helper blocker with the current 85/85+ emitter-gate analysis, exact current-session helper boundary/padding evidence, raw no-direct-xref and pointer-search caveat, PatchPane constructor/current-setter route, vtable/invalidation slot facts, generated metadata caveats, owner rejection analysis, and child source-shape names.
- 2026-07-23 B002 UID000115 class callback:
  - Raised `88/90 -> 90/93` while preserving owner/emitter UID0000MT and reconstructable true.
  - Moved `[[CHILDREN]]` after the class closing `};` so qualified child definitions emit at file scope rather than illegally inside the class.
  - Replaced stale inherited `m_bounds`/`Invalidate` wording with current `GrafPort::m_visibleBounds`/`Pane::InvalidateRect`, preserved the former as superseded history, and incorporated exact child hashes, signed flow, invalidation counts, route negatives, family naming, generated defects, non-emitting aggregate policy, and score rationale.
- 2026-07-23 B003 UID000117 inherited-storage correction:
  - Raised `90/93 -> 92/93` while preserving owner/emitter UID0000MT and reconstructable true.
  - Removed impossible derived `m_minValue/m_currentValue/m_maxValue` declarations. The accepted complete `ControlPane` layout already owns protected `m_rangeStart/m_rangeCurrent/m_rangeEnd +0xf8/+0xfa/+0xfc` and has exact size `0x108`, matching the sole PatchPane allocation.
  - Preserved the legal class-before-children placement, six declarations, private C++03 `kMaxProgressValue`, all binary/liveness/vtable evidence, and the earlier derived names as explicitly superseded semantic aliases rather than deleting history.
- 2026-07-23 B003 UID00011A support synchronization:
  - Score and metadata remain `92/93`, owner/emitter UID0000MT, reconstructable true, and the exact storage-free declaration unchanged.
  - Expanded `AddCurrentValue` with exact hash/range/padding/unique-body/no-route evidence, modulo-16 signed behavior, write/invalidation ordering, realistic source naming, rejected alternatives, retained-source classification, current `93/94` child score, and unchanged class/file placement.
  - Preserved all unrelated method, layout, vtable, generated-history, owner, and dependency evidence.
