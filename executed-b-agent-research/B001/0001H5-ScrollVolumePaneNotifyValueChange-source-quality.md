** TARGET-REPORT-UID:0001H5 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001H5 ScrollVolumePaneNotifyValueChange Source-Quality Report

## Scope And Paths

- Agent: B001.
- Assignment: report-only source-quality / heuristic pass for [UID:0001H5] `ScrollVolumePaneNotifyValueChange`.
- Target path: `source-3/project-documentation/by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001H5-ScrollVolumePaneNotifyValueChange-source-quality.md`.
- Support paths checked or used:
  - `source-3/project-documentation/by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`
  - `source-3/project-documentation/by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`
  - `source-3/project-documentation/by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md`
  - `source-3/project-documentation/by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md`
  - `source-3/project-documentation/by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`
  - `source-3/project-documentation/by-class/ScrollVolumePane.md`
  - `source-3/project-documentation/by-file/ScrollVolumePane.md`
  - `source-3/project-documentation/by-type/by-struct/ScrollVolumePaneLayout.md`
  - `source-3/project-documentation/by-type/by-struct/RectBoundsLayout.md`
  - `source-3/project-documentation/by-type/by-struct/PaneLayout.md`
  - `source-3/project-documentation/by-type/by-vtable/ScrollVolumePaneVtables.md`
  - `source-3/project-documentation/by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`
  - `source-3/project-documentation/by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`
  - `source-3/project-documentation/by-class/NewOptionPane.md`
  - `source-3/project-documentation/by-file/OptionPane.md`
  - `source-3/project-documentation/by-memory/-coverage-report.md`
  - `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
  - `source-3/project-documentation/auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/executed/older/B001-MEMTOOL-00565360-ScrollVolumePaneNotifyValueChange.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/executed/0002LB-0002LC-0002LD-ScrollVolumePaneRawInteraction-source-quality.md`

No target/support by-* docs were edited. No generated coverage report was edited. The only file changed by this pass is this report.

## Executive Recommendation

Populate first-draft C++ for [UID:0001H5] and refresh its source-quality text. The stale no-code reason in the target is now invalid because the active code-entry gate is the combined `85/85` emitter gate, not the old `90/90+` threshold. The target is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0001H2`, routes through the valid `ScrollVolumePane` class/file chain to `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`, and its current `(85 + 86) / 2 = 85.5` already clears the minimum gate.

Recommended source-facing method and signature:

```cpp
void ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX);
```

This signature keeps the local-coordinate order used by the related raw `BeginInteraction(char part, int mouseY, int mouseX)` draft. The notify helper only uses the second coordinate (`mouseX`) because `ScrollVolumePane` is a horizontal volume slider. That resolves the old `TextEditPane::TrackScrollThumbF(int coord0, int coord1)` pollution without throwing away the two-argument ABI.

Recommended metadata after implementation:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0001H2
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0001H2
EMITTER_POSITION_OPTIONAL:140
```

Owner/emitter should remain [UID:0001H2] `ScrollVolumePane`. [UID:0000M7]/[UID:000097] `OptionPane`/`NewOptionPane` owns the policy callback, not the slider math. No split or range change is recommended.

## Evidence Checked

Instruction sources read:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/inference_research.md`

IDA MCP availability was attempted first. Local endpoints `http://127.0.0.1:13337/mcp`, `http://localhost:13337/mcp`, `http://127.0.0.1:1337/mcp`, and `http://localhost:1337/mcp` all failed during this pass, so no new IDA database edits or comments were made. The report uses existing IDA-backed docs plus fresh local PE/Capstone evidence from `E:\NTK\Resources\NexusTK\NexusTK.exe`.

Fresh PE route scan results:

```text
image_base 0x400000
0x00565360 rel32 callers: 0x005652fb, 0x00565324
0x00565010 rel32 callers include: 0x00565385
0x00540490 rel32 caller: 0x00565470
0x005652a0 rel32 callers include: 0x00565272
0x00565490 rel32 callers: none
0x00565488 rel32 callers: none
0x00564e30 rel32 callers include: 0x0056530f
0x004a9090 rel32 callers include: 0x00565394 and 0x005653cc
0x005447c0 rel32 callers include: 0x0056539f and 0x005653d7
```

Boundary bytes:

- `0x00565360` starts `55 8b ec 83 ec 48 ...`, a normal modeled function prologue.
- The body ends with `ret 8` at `0x00565485`.
- `0x00565488-0x00565490` is eight `0xcc` bytes.
- `0x00565490` starts the next raw reset helper prologue.

Capstone was available locally (`capstone 5.0.7`) and was used to decode:

- `0x00565360-0x00565488`
- `0x005652a0-0x00565360`
- `0x005651e0-0x005652a0`
- `0x00565010-0x0056516b`
- `0x00540490-0x005404c7`
- `0x004b7c30-0x004b7c50`
- `0x00544730-0x005447c0`
- `0x004f1420-0x004f14a0`
- selected Pane and ScrollVolumePane vtable dwords

## Boundary And Reachability

The target range should remain exactly `0x00565360-0x00565488`.

- Start: IDA-modeled `sub_565360`; local PE bytes show the function prologue at `0x00565360`.
- End: the epilogue is `ret 8` at `0x00565485`; the half-open function end is `0x00565488`.
- Padding: `0x00565488-0x00565490` is eight `int3` bytes and should remain outside both this target and [UID:0002LD].
- Successor: [UID:0002LD] `ScrollVolumePaneResetInteractionStateRaw` starts at `0x00565490`; direct route scans found no rel32 branch or VA/RVA pointer route to that raw start.

Direct callers are exactly the two existing commit-helper calls:

```text
0x005652fb -> 0x00565360
0x00565324 -> 0x00565360
```

Both sit inside [UID:0001H4] `ScrollVolumePaneCommitInteraction`. The first is the active-thumb path when `m_activePart == 2`; the second follows hit-test confirmation when the clicked part still matches `m_activePart`.

This target has no vtable slot reference and no direct external caller outside the ScrollVolumePane interaction helper chain. That does not make it dead code: [UID:0001H4] is reached by modeled mouse/focus paths and raw begin-interaction code, and [UID:0001H4] calls this target directly.

## Instruction-Level Behavior

The target body is a horizontal value-from-thumb helper. The old support wording that described the `+0x10c` component as vertical and part codes `0/1/3/4` as top/above/below/bottom is not supported by the current RectBounds layout or by this disassembly.

Key decoded sequence:

1. Reads the old slider value from `word ptr [this + 0xfe]`.
2. Calls `0x00565010` once with part `2` to obtain the thumb rectangle.
3. Runs two cursor/origin/bounds-copy blocks that match constant `GetPartRect(0)` and `GetPartRect(4)` logic inlined by the compiler:
   - The first block collapses the local bounds rectangle so `leftRect.right == leftRect.left`; the code later uses `leftRect.right` as the left travel limit.
   - The second block collapses the local bounds rectangle so `rightRect.left == rightRect.right`; the code later uses `rightRect.left` as the right travel limit.
   - These blocks explain why the target has direct calls to `EventMan::GetCursorPosition` (`0x004a9090`) and the pane origin helper (`0x005447c0`) even though the final arithmetic uses the passed `mouseX`.
4. Computes `thumbLeft = mouseX - m_thumbDragOffset.x + 1`.
5. Clamps `thumbLeft` to `[leftLimit, rightLimit - thumbWidth]`.
6. Computes an inclusive range value:

```text
value = ((thumbLeft - leftLimit) * (m_range + 1)) / (rightLimit - leftLimit - thumbWidth)
if value > m_range:
    value = m_range
```

7. Compares the computed value against the old `m_value`.
8. If unchanged, returns without callback.
9. If changed:
   - dispatches through primary vtable slot `+0x1c`, inherited from `Pane`, target `0x005447a0`;
   - that slot walks the cached `Layer*` at `Pane +0xa8` through `0x004f1420` and returns the parent/owner pane;
   - calls `NewOptionPane::OnVolumeChanged` at `0x00540490` with `volumeType`, old value, and new value.

The target does not write `this + 0xfe` itself. `NewOptionPane::OnVolumeChanged` updates NewOptionPane local volume display fields (`+0x12bc` for nonzero type, `+0x12c0` for zero type), calls `ApplyVolumeSettings` at `0x005403b0`, then invalidates its bounds through `Pane::InvalidateRect`. That callback may reapply the slider values through the documented NewOptionPane volume path.

## Source-Facing Names And Field Directions

### Method Name

Best source-facing name: `ScrollVolumePane::NotifyValueChange`.

Evidence:

- The existing page filename/search label already uses `ScrollVolumePaneNotifyValueChange`.
- The body does not simply set a field; it computes a candidate value and conditionally dispatches a callback.
- `NewOptionPane::OnVolumeChanged` duplicates the old/new comparison and owns the policy update, but the slider helper is still the notification trigger.
- `UpdateValueFromDrag` is a valid behavior alias, but it underplays the owner callback and conflicts with the existing `OnVolumeChanged` naming on the receiving side.
- `TrackScrollThumbF` is rejected as stale generated TextEditPane pollution because the body uses ScrollVolumePane tail fields, the ScrollVolumePane part helper, and the NewOptionPane volume callback.

Confidence: high for `NotifyValueChange` as a descriptive source-facing name; medium for original spelling because no live symbol proves it.

### Signature

Recommended source signature:

```cpp
void ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)
```

Evidence:

- Binary ABI is `__thiscall` with `ret 8`.
- [UID:0001H4] pushes two local coordinates before calling this target.
- The target only reads `[ebp+0xc]`, the second argument. With the companion [UID:0002LC] source shape and `RectBoundsLayout` field order, this is the horizontal coordinate (`mouseX`).
- Keeping the first coordinate preserves call-site symmetry with `HitTestPart` and `BeginInteraction` even though this horizontal-only slider ignores it.
- Return value is not consumed by the two callers. The source-facing method should be `void`. Any apparent EAX value at return is compiler residue from the last arithmetic/call path.

Rejected alternatives:

- `int NotifyValueChange(...)`: not supported by callers; both callers are statement calls.
- `NotifyValueChange(int mouseX, int mouseY)`: conflicts with the accepted sibling `BeginInteraction(char part, int mouseY, int mouseX)` and with the target's use of the second coordinate as horizontal.
- `TextEditPane::TrackScrollThumbF(int coord0, int coord1)`: rejected as generated owner/signature pollution.

### Fields

| Offset | Recommended source-facing name | Confidence | Evidence |
| --- | --- | --- | --- |
| `+0xfb` | `m_useDragPosition` / `m_dragPositionOverride` | medium | `GetPartRect` checks this byte before using cursor position and stored drag offsets. Final original spelling not proven. |
| `+0xfc` | `m_volumeType` | high | Constructor stores the constructor argument; target pushes it to `NewOptionPane::OnVolumeChanged`. |
| `+0xfe` | `m_value` / `m_currentValue` | high | `SetValue` writes it, `SetRange` clamps it, target compares it against computed new value. |
| `+0x100` | `m_range` / `m_maxValue` | high | `SetRange` writes it, `CanAdjust` checks it, value math scales and clamps against it. |
| `+0x102` | `m_enabled` | high | Enable/Disable and CanAdjust behavior. |
| `+0x103` | `m_highlightPart` | high | B003-accepted sibling docs and C++ use this name. |
| `+0x104` | `m_activePart` | high | B003-accepted sibling docs and C++ use this name. |
| `+0x108` | `m_thumbDragOffset` first component, vertical/top offset | medium-high | BeginInteraction writes `mouseY - thumbRect.top` into the first component. |
| `+0x10c` | `m_thumbDragOffset` second component, horizontal/left offset | high for role, medium for exact member spelling | BeginInteraction writes `mouseX - thumbRect.left` into the second component; target subtracts this component from `mouseX`. Current support text saying "vertical drag offset" should be corrected. |

### Helper Names

| Address | Recommended name | Confidence | Evidence |
| --- | --- | --- | --- |
| `0x00565010` | `ScrollVolumePane::GetPartRect(char part, RectBounds *outRect)` | high | Existing aggregate name, direct use by hit-test/paint/raw helpers, and decoded RectBounds behavior. |
| `0x004a9090` | `EventMan::GetCursorPosition(PointPair *outPoint)` | high as dependency name | Existing EventMan docs and disassembly copying two stored coordinates. |
| `0x005447c0` | `Pane::GetScreenOrigin(PointPair *outPoint)` / pane origin helper | medium | Existing commit docs and disassembly. Broader Pane API pass has not finalized original spelling. |
| `0x005447a0` | `Pane::GetParentPane()` or `Pane::GetOwnerPane()` | medium | Vtable slot `+0x1c`, walks `Pane +0xa8` attached Layer through `0x004f1420`, returns a pane pointer used as `NewOptionPane *`. Original API name not proven; `GetParentPane` is the best source-facing expression for this call. |
| `0x00540490` | `NewOptionPane::OnVolumeChanged(unsigned char volumeType, int oldValue, int newValue)` | high | Existing NewOptionPane docs plus fresh disassembly show exact three-argument ret `0xc`, old/new check, field updates, apply, and invalidation. |

## Corrected Slider Axis And Part Codes

`ScrollVolumePane` should be described as horizontal for this helper and layout context.

Direct proof:

- `RectBoundsLayout.md` confirms `RectBounds` order is `left, top, right, bottom`.
- `GetPartRect(0)` copies the local bounds and sets `right = left`, producing a collapsed left edge.
- `GetPartRect(4)` copies the local bounds and sets `left = right`, producing a collapsed right edge.
- `GetPartRect(2)` computes thumb `left/right` using the current value, range, and a fixed `0x26` / 38-pixel thumb width.
- Target [UID:0001H5] uses `thumbRect.left`, `thumbRect.right`, the collapsed left/right edge rectangles, and `m_thumbDragOffset` second/+4 component to compute the new value.

Recommended part-code wording for `ScrollVolumePaneLayout.md`:

```text
| `0` | collapsed left edge / left cap region |
| `1` | track left of thumb |
| `2` | thumb |
| `3` | track right of thumb |
| `4` | collapsed right edge / right cap region |
| `0xff` | no highlighted or active part |
```

This should replace the current top/above/below/bottom wording for ScrollVolumePane. It does not necessarily apply to every sibling scroll control with an orientation byte.

## Relationship To Required Support Targets

### [UID:0001H3] ScrollVolumePaneHitTestPart

The hit-test page stays a dependency and should still be blank until its own final C++ is audited. This target confirms that its part ids should be interpreted horizontally for ScrollVolumePane. `HitTestPart` callers pass local coordinates; its return is compared to `m_activePart` before [UID:0001H5] is called.

### [UID:0001H4] ScrollVolumePaneCommitInteraction

[UID:0001H4] is the only direct caller. Its two calls to this target are statement calls, supporting the `void` source signature. The commit helper computes local cursor coordinates and either:

- calls [UID:0001H5] immediately if `m_activePart == 2`, or
- hit-tests the current local point and calls [UID:0001H5] only when the hit part still matches the active part.

Recommended support note: the target signature is `NotifyValueChange(int mouseY, int mouseX)`; the second coordinate is the horizontal value coordinate.

### [UID:0002LC] ScrollVolumePaneBeginInteractionRaw

Current first-draft C++ on [UID:0002LC] is compatible with this report:

```cpp
InitPointPair(&m_thumbDragOffset, mouseY - rect.top, mouseX - rect.left);
```

The important support correction is interpretation, not necessarily the C++ line: the first component at `+0x108` is the vertical/top offset; the second component at `+0x10c` is the horizontal/left offset consumed by [UID:0001H5].

### [UID:0002LD] ScrollVolumePaneResetInteractionStateRaw

No range or C++ change is needed. This target reconfirms the padding between [UID:0001H5] and [UID:0002LD] and keeps [UID:0002LD] at `0x00565490-0x005654ec`.

### [UID:0001W2] ScrollVolumePaneLayout

Support text should be updated to:

- Replace the current `+0x10c` "vertical drag offset" wording with "second/horizontal component of `m_thumbDragOffset`; current value math uses it as the horizontal left/drag offset."
- Replace top/above/below/bottom part-code names with left/right names for this class.
- Replace "fixed 38-pixel thumb height" wording with "fixed 38-pixel thumb width" where it is describing ScrollVolumePane's `GetPartRect`/value math.

### NewOptionPane / OptionPane

`NewOptionPane::OnVolumeChanged` remains the callback owner. The slider should not be rerouted under OptionPane because the receiver state and interaction geometry are ScrollVolumePane-owned, and OptionPane only consumes notifications. If support docs are edited, add that disassembly shows:

- argument 1: `volumeType`;
- argument 2: old value;
- argument 3: new value;
- nonzero type writes `this+0x12bc`;
- zero type writes `this+0x12c0`;
- callback calls `ApplyVolumeSettings` and invalidates NewOptionPane bounds.

## First-Draft C++ Recommendation

Enter this in the target's `RECONSTRUCTION_CPP CODE:BEGIN/END` block after supervisor acceptance:

```cpp
void ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)
{
    RectBounds leftRect;
    RectBounds thumbRect;
    RectBounds rightRect;
    int oldValue;
    int leftLimit;
    int rightLimit;
    int thumbWidth;
    int thumbLeft;
    int travel;
    int value;
    NewOptionPane *owner;

    oldValue = m_value;

    GetPartRect(2, &thumbRect);
    GetPartRect(0, &leftRect);
    GetPartRect(4, &rightRect);

    leftLimit = leftRect.right;
    rightLimit = rightRect.left;
    thumbWidth = thumbRect.right - thumbRect.left;

    thumbLeft = mouseX - m_thumbDragOffset.x + 1;
    if (thumbLeft < leftLimit) {
        thumbLeft = leftLimit;
    }
    if (thumbLeft > rightLimit - thumbWidth) {
        thumbLeft = rightLimit - thumbWidth;
    }

    travel = rightLimit - leftLimit - thumbWidth;
    value = ((thumbLeft - leftLimit) * (m_range + 1)) / travel;
    if (value > m_range) {
        value = m_range;
    }

    if (oldValue != value) {
        owner = static_cast<NewOptionPane *>(GetParentPane());
        owner->OnVolumeChanged(m_volumeType, oldValue, value);
    }
}
```

Notes for implementation:

- If the shared point/offset declaration does not expose `.x`, use the local project's accepted accessor/name for the second `m_thumbDragOffset` component. The binary uses `this + 0x10c`.
- Do not add a `travel <= 0` guard in this first draft. The binary divides unconditionally, and callers reach this after range/enabled state has already made the interaction meaningful.
- Do not assign `m_value = value` in this helper. The binary does not write `this + 0xfe`; the owner callback handles policy/application.
- `mouseY` is intentionally unused by this horizontal-only source draft, but it remains in the signature to match the two-coordinate interaction helper family.
- The three `GetPartRect` calls are the best source-facing expression. The binary directly calls `GetPartRect(2)` and contains inlined constant-part copies for `GetPartRect(0)` and `GetPartRect(4)`.

## Generated-Output Caveat

The target page currently says the "current generated source still emits this body with stale `TextEditPane::TrackScrollThumbF(int coord0, int coord1)` naming/signature." The current `project-documentation/auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` does not contain that stale body because the target's formal C++ block is blank; it emits an empty marker for [UID:0001H5]. The stale label remains a recovered/source-map lead from older generated material and target prose, not authoritative ownership. The implementation should word this as:

```text
Older recovered/source-map material labels the body as `TextEditPane::TrackScrollThumbF(int coord0, int coord1)`. Current by-* ownership and generated final output route the target through `ScrollVolumePane.cpp`; the formal C++ block was empty until this source-quality pass.
```

## Score And Metadata Rationale

Recommended target score after implementation: `87/89`.

Completion should rise from `85` to `87` because this pass resolves the stale no-code gate, the method/source signature, horizontal-axis formula, callback owner expression, part-helper shape, field directions for the value math, generated TextEditPane rejection, and first-draft C++ readiness. It should not jump higher because the exact original method name and exact inherited Pane accessor spelling are still inferred.

Confidence should rise from `86` to `89` because fresh PE/Capstone evidence directly confirms the body, callers, boundary, callees, padding, vtable owner lookup, and callback target. It should remain below final-audit confidence because IDA MCP was unavailable during this pass and because the broad Pane owner accessor API name still needs a Pane-core naming pass.

Metadata recommendations:

- Keep `CANONICAL_OWNER:0001H2`.
- Keep `EMITTER_UIDS:0001H2`.
- Set `EMITTER_POSITION_OPTIONAL:140` to match the page's parent-handling prose and the address-order slot between [UID:0001H4] position `130` and [UID:0002LD].
- Keep `RECONSTRUCTABLE:TRUE`.
- Populate first-draft C++ as above.

## Open Questions And Attempted Resolution

| Issue | Resolution / best inference | Evidence checked |
| --- | --- | --- |
| Original method spelling | Use `NotifyValueChange` as best descriptive source-facing name; original spelling not proven. | Existing filename/search label, callback behavior, sibling docs, stale TextEditPane rejection. |
| Source signature coordinate order | Use `NotifyValueChange(int mouseY, int mouseX)`. | `ret 8`, [UID:0001H4] two-coordinate call shape, [UID:0002LC] accepted coordinate order, target reads second arg as horizontal value coordinate. |
| Is the slider horizontal or vertical? | Horizontal for ScrollVolumePane. | `RectBoundsLayout` order, `GetPartRect(0/4)` collapsed left/right edges, `GetPartRect(2)` 38-pixel width math, target uses `thumbRect.left/right` and `m_thumbDragOffset` second/+4 component. |
| Exact name of vtable `+0x1c` callback owner lookup | Best source-facing expression is `GetParentPane()`; `GetOwnerPane()` remains an acceptable alias if Pane API audit standardizes that name. | ScrollVolume primary vtable `+0x1c -> 0x005447a0`; disassembly reads `Pane +0xa8` attached `Layer*` and calls `0x004f1420`, which returns a pane pointer used as `NewOptionPane *`. |
| Does target update `m_value`? | No local store should be added. | Target disassembly reads `+0xfe`, computes value, compares, and calls owner callback; no write to `+0xfe`. |
| `volumeType` channel constants | Keep generic `m_volumeType`; do not label 0/1 as sound/music without a NewOptionPane config pass. | `NewOptionPane` docs show two local volume fields and config offsets but do not conclusively map constructor arg `1`/`0` to final source enum names. |
| Need split/range repair? | No. | Direct modeled body, exact `ret 8`, padding, successor raw helper boundary, no branches/pointers into padding. |
| Need target C++ or no-code proof? | C++ is appropriate. | Current gate clears; owner/emitter route valid; behavior/source shape now specific enough. |

## Implementation Instructions For Supervisor Callback

When accepted, implement these exact edits. Do not apply them before supervisor callback.

### Target Doc

Path: `source-3/project-documentation/by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md`

1. Header:
   - Change `COMPLETION:85` to `COMPLETION:87`.
   - Change `CONFIDENCE:86` to `CONFIDENCE:89`.
   - Keep `CANONICAL_OWNER:0001H2`.
   - Keep `RECONSTRUCTABLE:TRUE`.
   - Keep `EMITTER_UIDS:0001H2`.
   - Set `EMITTER_POSITION_OPTIONAL:140`.
2. Populate `RECONSTRUCTION_CPP CODE:BEGIN/END` with the first-draft C++ block in this report.
3. Status section:
   - Replace "medium for final public name" with "medium-high for exact original method spelling; strong for source-facing `NotifyValueChange` role/signature."
   - Replace the generated-output caveat with the wording from `Generated-Output Caveat`.
   - Replace "Final C++ remains withheld..." with "First-draft C++ is now appropriate under the active combined-score/emitter gate; remaining name caveats are documented."
4. Behavior section:
   - State that the helper computes horizontal thumb/value math.
   - State that the direct `GetPartRect(2)` call obtains the thumb rectangle and the two cursor/origin blocks match inlined constant `GetPartRect(0)`/`GetPartRect(4)` left/right edge rectangles.
   - State the exact formula and that no `m_value` write occurs in this helper.
   - State the callback owner is obtained through inherited vtable slot `+0x1c` / `0x005447a0` before calling `NewOptionPane::OnVolumeChanged`.
5. Touched State And Calls:
   - Update `+0x10c` to "second/horizontal component of `m_thumbDragOffset`; subtract from `mouseX` while converting thumb position to value."
   - Add `0x005447a0` as inherited parent/owner pane lookup via Pane slot `+0x1c`.
   - Clarify `0x004a9090`/`0x005447c0` calls are from the inlined constant edge-rect computations.
6. Evidence Notes:
   - Add the 2026-06-19 local PE/Capstone evidence, including direct callers, padding, direct callback call, and unavailable IDA MCP note.
7. Ownership Decision:
   - Keep owner/emitter [UID:0001H2].
   - Reject `TextEditPane::TrackScrollThumbF`.
   - Reject OptionPane ownership for the slider math while keeping `NewOptionPane::OnVolumeChanged` as callback dependency.
8. Cross References:
   - Add `RectBoundsLayout`, `PaneLayout`, `PaneVtableData`, and `NewOptionPane` if not already present.
9. Changes:
   - Add a 2026-06-19 B001 source-quality entry with score/metadata/C++ update summary.

### Support Docs

Path: `source-3/project-documentation/by-type/by-struct/ScrollVolumePaneLayout.md`

Replace these rows:

```text
| `+0x108` | 8 | `PointPair m_thumbDragOffset` | Eight-byte point/offset written by `InitPointPair` during thumb begin-interaction and consumed by `NotifyValueChange` while converting mouse position to volume value. |
| `+0x10c` | 4 | second component of `m_thumbDragOffset` | The `+4` component of the `+0x108` point, not an unrelated independent field; current value math uses this component as the vertical drag offset. |
```

with:

```text
| `+0x108` | 8 | `PointPair m_thumbDragOffset` | Eight-byte drag offset written by `InitPointPair` during thumb begin-interaction as `(mouseY - thumbRect.top, mouseX - thumbRect.left)`; `NotifyValueChange` consumes the second/+4 component while converting horizontal mouse position to volume value. |
| `+0x10c` | 4 | second/horizontal component of `m_thumbDragOffset` | The `+4` component of the `+0x108` point, not an unrelated independent field; current value math uses this component as the horizontal left/drag offset subtracted from `mouseX`. |
```

Replace the part-code table with:

```text
| Code | Meaning |
| --- | --- |
| `0` | collapsed left edge / left cap region |
| `1` | track left of thumb |
| `2` | thumb |
| `3` | track right of thumb |
| `4` | collapsed right edge / right cap region |
| `0xff` | no highlighted or active part |
```

Replace "fixed 38-pixel thumb height" with "fixed 38-pixel thumb width" where the page discusses ScrollVolumePane paint/GetPartRect/value math.

Path: `source-3/project-documentation/by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`

Update the [UID:0001H5] row in the child table from "Computes value from drag position" to:

```text
Computes horizontal value from thumb/drag position and calls the owning option-pane callback when changed.
```

Add an evidence note:

```text
2026-06-19 B001 source-quality pass on [UID:0001H5] resolves the value-change helper as horizontal `ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)`: out-of-line `GetPartRect(2)` plus inlined constant left/right edge rectangles from `GetPartRect(0/4)`, value scaling through `+0x100`, old value at `+0xfe`, horizontal drag offset at `+0x10c`, and callback through inherited Pane owner lookup to `NewOptionPane::OnVolumeChanged`.
```

Path: `source-3/project-documentation/by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`

Add or update a note:

```text
B001's 2026-06-19 [UID:0001H5] pass resolves the notify call as source-facing `NotifyValueChange(int mouseY, int mouseX)`. The helper preserves two-coordinate call symmetry, but the horizontal ScrollVolumePane value math uses the second coordinate (`mouseX`) and the second/+4 drag-offset component.
```

Path: `source-3/project-documentation/by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md`

Add or update a support note:

```text
The `InitPointPair(&m_thumbDragOffset, mouseY - rect.top, mouseX - rect.left)` draft stores the vertical/top drag offset in the first component and the horizontal/left drag offset in the second/+4 component. [UID:0001H5] consumes the second/+4 component while computing the horizontal volume value.
```

Path: `source-3/project-documentation/by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`

If support owner-slot documentation is accepted, add a slot evidence row or note:

```text
Primary vtable slot `+0x1c` points to `0x005447a0`, an inherited pane owner/parent lookup that reads cached `Pane +0xa8` `Layer*`, walks that layer through `0x004f1420`, and returns the containing/owner pane. [UID:0001H5] uses this slot result as the `NewOptionPane *` receiver before calling `NewOptionPane::OnVolumeChanged`.
```

Path: `source-3/project-documentation/by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`

Optional support enrichment for the existing OnVolumeChanged row:

```text
Disassembly of `0x00540490-0x005404c7` shows `NewOptionPane::OnVolumeChanged(unsigned char volumeType, int oldValue, int newValue)`: it returns immediately if old and new match, writes nonzero `volumeType` changes to `this+0x12bc` and zero `volumeType` changes to `this+0x12c0`, calls `ApplyVolumeSettings`, and invalidates NewOptionPane bounds.
```

### Exact Pending Coverage Row

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly. Supervisor-owned replacement for the current [UID:0001H5] row:

```text
        - [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) 0x00565360-0x00565488 | method | ScrollVolumePaneNotifyValueChange : reconstructable : 87% : strong : B001 2026-06-19 source-quality pass resolves this as source-facing `ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)` with horizontal thumb/value math, rejects stale `TextEditPane::TrackScrollThumbF`, confirms exact modeled `0x128` body, two direct callers at `0x005652fb`/`0x00565324`, `0x00565488-0x00565490` `int3` padding before the reset raw helper, out-of-line `GetPartRect(2)` plus inlined constant `GetPartRect(0/4)` left/right edge rectangles, `m_thumbDragOffset` `+0x108/+0x10c` with second/+4 component as horizontal offset, range clamp `+0x100`, old/current value `+0xfe`, volume type `+0xfc`, inherited pane owner lookup through vtable `+0x1c`/`0x005447a0`, callback to `NewOptionPane::OnVolumeChanged` at `0x00540490` only on value change, no local `m_value` store, and first-draft C++ readiness.
```

### Validator Commands After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation\tools` after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001H5-ScrollVolumePaneNotifyValueChange-source-quality-removed.md](0001H5-ScrollVolumePaneNotifyValueChange-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validator/autogen effects:

- Target header remains valid with `COMPLETION:87`, `CONFIDENCE:89`, `EMITTER_POSITION_OPTIONAL:140`.
- `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` includes the new `ScrollVolumePane::NotifyValueChange` first-draft block rather than an empty target marker.
- `auto-generated/-ag-memory-coverage.md` should switch [UID:0001H5] from no-code/empty marker to coded/yes, with output file `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`.
- No range-barrier should appear between [UID:0001H5], [UID:0002LD], and [UID:0001H6].

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made in this report-only pass.

Recommended if an IDA callback is allowed later:

- Rename `sub_565360` to `ScrollVolumePane_NotifyValueChange` or method-style `ScrollVolumePane::NotifyValueChange`.
- Apply prototype: `void __thiscall ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)`.
- Comment `0x00565360`: "Horizontal ScrollVolumePane value helper; computes value from thumb drag x-position and notifies NewOptionPane only on change. Not TextEditPane."
- Rename/comment `sub_565010` as `ScrollVolumePane::GetPartRect(char part, RectBounds *outRect)`.
- Rename/comment `sub_540490` as `NewOptionPane::OnVolumeChanged(unsigned char volumeType, int oldValue, int newValue)`.
- Comment Pane slot `0x005447a0`: "Inherited parent/owner pane lookup via cached Layer*; used by ScrollVolumePane notify helper to get NewOptionPane receiver."
- Comment field offsets in ScrollVolumePane layout:
  - `+0xfc`: `m_volumeType`.
  - `+0xfe`: `m_value`.
  - `+0x100`: `m_range`.
  - `+0x103`: `m_highlightPart`.
  - `+0x104`: `m_activePart`.
  - `+0x108`: `m_thumbDragOffset` first component, vertical/top drag offset.
  - `+0x10c`: `m_thumbDragOffset` second component, horizontal/left drag offset used by NotifyValueChange.

## Report-Only Result

Changed files:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001H5-ScrollVolumePaneNotifyValueChange-source-quality.md`

Files intentionally not edited:

- `source-3/project-documentation/by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md`
- all support by-* docs
- `source-3/project-documentation/by-memory/-coverage-report.md`
- generated source and generated coverage reports

Validation commands run after this report: none. This is a report-only pass under supervisor instructions, and the changed file is an Agent-B001 research report outside validator-managed by-* scope.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001H5-ScrollVolumePaneNotifyValueChange-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001H5"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001H5-ScrollVolumePaneNotifyValueChange-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001H5-ScrollVolumePaneNotifyValueChange-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001H5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
