** TARGET-REPORT-UID:0004C3 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0004C3] IMECompositionPaneOnMouseEvent Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0004C3] `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md` from a blank split child to an emitting `IMECompositionPane::OnMouseEvent` method body.
- Final disposition: keep direct owner [UID:00006G] `IMECompositionPane`, route output through [UID:00006G] into [UID:0000K5] `IMEPanes`, add the target formal C++ block, and add the missing drag-state fields to the `IMECompositionPane` class shell.
- Required action: implementation callback should update the target metadata to `88/91`, set `EMITTER_UIDS:00006G`, leave `EMITTER_POSITION_OPTIONAL` blank, insert the exact target formal C++ block below, update support docs at the listed destinations, and run scoped validators with generated freshness checks for `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Confidence: high for range, owner, event branch behavior, drag state, `g_pIMEPane` anchor writes, and C++ readiness; medium-high for final original enum/field spellings of the mouse event constants and inherited pane origin names.

## Target

- Target UID: `0004C3`
- Target path: `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md`
- Assignment: `B009-report-0004C3-IMECompositionPaneOnMouseEvent-20260630`
- Queue row: `auto-generated/-ag-research-tracker.md` lists [UID:0004C3] as `80/86`, combined `83.0`, reconstructable `true`, reports `0`.
- Current generated row: `auto-generated/-ag-coverage-report-by-memory.md` shows `emits_code:false` for this exact range.

## Current Target State

- Current metadata: `COMPLETION:80`, `CONFIDENCE:86`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current owner/source route: [UID:00006G] `IMECompositionPane` -> [UID:0000K5] `IMEPanes`, with aggregate [UID:000189] `IMEPaneFamily`.
- Current blocker text says drag-state/helper spellings remain a child-specific C++ task. Current MCP evidence resolves that blocker.
- Current support state: [UID:00006G] already emits a class shell with `compositionCursorX +0xf8` and `compositionText[256] +0xfc`, but it does not yet declare the drag fields used by this target at primary offsets `+0x2fc`, `+0x300`, `+0x304`, and `+0x308`.

## Evidence Checked

- Read assignment `Agent-B009/goal.md`, `ntk-b-agent-workflow/SKILL.md`, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, and relevant `by-structure.md` ownership/emitter/C++ rules.
- Read target and support docs: target [UID:0004C3], [UID:00006G] `IMECompositionPane`, [UID:0000K5] `IMEPanes`, [UID:000189] `IMEPaneFamily`, [UID:0000R7] `g_pIMEPane`, [UID:0001PS] `0x0069b458.g_pIMEPane`, [UID:00018A] `SetCompositionString`, sibling composition children [UID:0004C1] through [UID:0004C6], [UID:00006H] `IMEPane`, [UID:0002V7] `PaneSetMode`, [UID:0001VH] `PaneLayout`, and [UID:00014C]/[UID:0000J6] Event type-map support.
- Read generated lead `auto-generated/NexusTK/input/IMEPanes.cpp`; current generated header is command `000000003148`, refreshed `2026-06-30T15:45:03-04:00`, and does not yet include UID0004C3 output.
- Old report search terms: `0004C3`, `004e7640`, `IMECompositionPaneOnMouseEvent`, `OnMouseEvent`, `IMECompositionPane`, `IMEPanes`, `00018A`, and `EventManAndEventFactoryHelpers`.
- Relevant old reports used as leads: executed B008 `0000K5-IMEPanes-empty-emitter-family-source-quality.md`, executed B003 `00018A-ime-composition-set-composition-string-source-quality.md`, and executed B008 `00014C-EventManAndEventFactoryHelpers-source-quality.md`. No prior UID0004C3-specific report was found.

## Current MCP Evidence

MCP was available; no fallback-only evidence was used.

| Call | Result |
| --- | --- |
| `initialize` | MCP server `ida-pro-mcp`, protocol `2025-06-18`. |
| `tools/list` | Current schema checked; used `database` on every inspection call. A wrapper retry was needed after hitting the documented PowerShell `$args` trap; MCP itself remained responsive. |
| `idb_list` | One active worker session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, pid/worker_pid `24256`. |
| `server_health` | `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready. |
| `lookup_funcs` | Target `0x004e7640` is `sub_4E7640`, size `0x1c9`; `0x004e7809` is not a function; next sibling `0x004e7810` is size `0x28`. |
| `get_bytes` | `0x004e763c-0x004e7640` is `cc cc cc cc`; `0x004e7809-0x004e7810` is seven `cc` bytes. |
| `decompile/analyze_function 0x004e7640` | 15 basic blocks, complexity 6; branch on event type byte `event+4`; uses event `+8`/`+0x0c` coordinates, drag active byte, drag start coordinates, saved pane mode, `Pane::SetMode`, `PointInRect`, `GetBounds`, `TranslateRectBounds`, `SetBounds`, and `g_pIMEPane` focus anchor fields. |
| `disasm 0x004e7640` | 143 instructions. EventHandler secondary view is normalized with `this-0xa0` for base pane calls. |
| `callees 0x004e7640` | `sub_4B7E80` point-in-rect, `sub_4B7E10` rectangle translate, `sub_5446B0` `Pane::SetMode`, and `__security_check_cookie`. |
| `xref_query to 0x004e7640` | One data xref at `0x0061c43c`, the IMECompositionPane secondary vtable slot; no direct code callers. |
| `xrefs_to 0x0069b458` | 17 xrefs; target reads the singleton at `0x004e7689`, `0x004e77c2`, and `0x004e77d3`. |
| `decompile 0x004e7380` | Constructor sets `compositionCursorX +0xf8` to `0`, clears `compositionText[256] +0xfc`, and clears byte `+0x2fc` to `0`; drag coordinate/saved-mode fields are assigned on mouse-down before use. |
| `decompile 0x004e7810/0x004e7840/0x004e7920` | Confirms sibling key handler calls [UID:00018A], paint uses `compositionText +0xfc` and `compositionCursorX +0xf8`, and accessor returns `this[62]` / `+0xf8`. |
| `get_int/entity_query 0x0061c3ec-0x0061c480` | IMECompositionPane vtable names at `0x0061c3ec`, secondary vtable at `0x0061c438`, target slot at `0x0061c43c -> 0x004e7640`, key slot `0x0061c444 -> 0x004e7810`, paint slot `0x0061c430 -> 0x004e7840`. |

## Positive Evidence Summary

- The range is exact: modeled start `0x004e7640`, function size `0x1c9`, half-open function end `0x004e7809`, last return instruction begins at `0x004e7806`, and `0x004e7809-0x004e7810` is padding before [UID:0004C4].
- The vtable-only xref at `0x0061c43c` places the body in `IMECompositionPane`'s secondary event-handler view. This matches sibling vtable entries for `OnKeyEvent` and `OnPaint`.
- The body has no dependency that suggests a different owner: it uses inherited Pane geometry/mode helpers, Event mouse fields, and root IME singleton anchor fields, all as dependencies of the composition pane.
- The body exposes the missing class state: `compositionDragActive +0x2fc`, `compositionDragStartY +0x300`, `compositionDragStartX +0x304`, and `compositionDragSavedMode +0x308`. The constructor clears the active byte; mouse-down initializes all fields before move/up reads them.
- Event type support is already documented: current Event docs map type `0` to cursor/mouse move, type `1` to left-button down, and type `3` to left-button up. Coordinate order follows the accepted pane helper convention `event->mouseY` at `+0x08`, `event->mouseX` at `+0x0c`.
- Pane support is already documented: [UID:0002V7] proves `sub_5446B0` is `Pane::SetMode(unsigned char)`, [UID:0001VH] proves `+0xb5` is `m_mode`, `+0x44` is bounds, and `+0xac/+0xb0` is the pane origin point.

## Negative Evidence Summary

- Not `InputMan`: InputMan produces IME/Event records; the target consumes mouse events on the pane-side UI object and does not own Win32/IMM message handling.
- Not `TextEditPane` or `TextBoxPane`: text controls only populate focus/caret state used by composition positioning; this target moves the composition popup itself.
- Not `Pane`/`GrafPort`: inherited geometry, hit-test, translate, set-bounds, and mode helpers are dependencies; the target state begins after the `IMECompositionPane` composition text buffer.
- Not `g_pIMEPane` global ownership: the target reads the singleton and writes root anchor fields, but its direct state and vtable slot are in `IMECompositionPane`.
- Not a raw helper/no-code case: IDA models a normal function, the vtable has one data xref to the entry, and the method has source-visible event behavior. Blank C++ is no longer justified.
- Not a merge with siblings: preceding and following padding plus separate function starts at `0x004e7470`, `0x004e7810`, `0x004e7840`, and `0x004e7920` keep this exact child boundary stable.

## Heuristic / Inference Reanalysis And Validation

The old blocker "drag-state and helper spellings remain open" is resolved enough for first-draft C++:

- `sub_5446B0` is not a visibility helper. Current Pane docs resolve it as `Pane::SetMode(unsigned char)`, and this target saves/restores the inherited mode byte `m_mode +0xb5`.
- Mouse event kind names are inferred from current EventMan support. Use `kEventCursorMove`, `kEventLeftButtonDown`, and `kEventLeftButtonUp` or equivalent project constants; keep exact original enum spelling below final-audit confidence.
- `event+0x08` and `event+0x0c` are best source-facing `mouseY` and `mouseX` in the pane helper convention. The binary calls the point-in-rect helper in the accepted `y, x` argument order and stores those same fields as drag Y/X anchors.
- `IMECompositionPane` uses a secondary EventHandler view at `this+0xa0`; source C++ should normalize this to ordinary `IMECompositionPane::OnMouseEvent(const Event *event)` rather than expose `this-0xa0` in source.
- The target updates `IMEPane::focusCaretAnchorX/Y` while dragging and after release. That keeps candidate/composition popup anchoring synchronized with the manually moved composition pane.
- Exact original names for the new fields are inferred. The proposed names are source-quality and behavior-driven: `compositionDragActive`, `compositionDragStartY`, `compositionDragStartX`, and `compositionDragSavedMode`.

## Ranked Ownership Analysis

### 1. [UID:00006G] `IMECompositionPane`

- Evidence for: target vtable slot is in the `IMECompositionPane` secondary vtable, constructor initializes target-local drag-active byte, sibling composition methods use the same class route, and the body manipulates composition-pane bounds/mode while updating root IME anchors.
- Evidence against: it reads [UID:0000R7] `g_pIMEPane` and calls base Pane helpers, but those are dependencies rather than owner signals.
- Decision: keep as direct canonical owner and emitter.

### 2. [UID:0000K5] `IMEPanes`

- Evidence for: it is the correct source file root and generated route for this class.
- Evidence against: too broad for direct semantic ownership; by-structure says class methods should attach to the class when the class page clears the gate.
- Decision: keep as source-file route through [UID:00006G], not direct target owner.

### 3. [UID:0000K6] `InputMan`

- Evidence for: InputMan produces many IME events in this subsystem.
- Evidence against: target has no Win32/IMM calls and is reached from an IMECompositionPane vtable slot; it consumes an already built Event.
- Decision: reject.

### 4. [UID:0000A2] `Pane` / [UID:0001VH] `PaneLayout`

- Evidence for: target uses inherited bounds, origin, mode, `SetMode`, `GetBounds`, and `SetBounds`.
- Evidence against: target-local fields are after the IME composition text buffer, and vtable slot is in `IMECompositionPane`.
- Decision: reject as direct owner; cite as support.

## Range / Split / Padding / Reclassification Analysis

- Keep target range as `0x004e7640-0x004e7809` documented child. MCP `lookup_funcs` size `0x1c9` means the modeled function is half-open `0x004e7640-0x004e7809`; `0x004e7809` is not itself a function start and begins the padding before [UID:0004C4].
- Predecessor padding: `0x004e763c-0x004e7640` is four `0xcc` bytes after [UID:00018A].
- Successor padding: `0x004e7809-0x004e7810` is seven `0xcc` bytes before [UID:0004C4].
- No split is required inside this target. The method has one coherent event-handler body with branch cases for move/down/up.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a valid owner/emitter route through [UID:00006G], and the recommended score average is greater than `85`.

Recommended exact formal target insertion:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IMECompositionPane::OnMouseEvent(const Event *event)
{
    switch (event->type) {
    case kEventCursorMove:
        if (!compositionDragActive) {
            return false;
        }

        {
            RectBounds dragBounds;
            GetBounds(&dragBounds);
            TranslateRectBounds(&dragBounds, event->mouseX - compositionDragStartX, 0);
            TranslateRectBounds(&dragBounds, 0, event->mouseY - compositionDragStartY);
            SetBounds(&dragBounds, 0);

            g_pIMEPane->focusCaretAnchorX = dragBounds.left;
            g_pIMEPane->focusCaretAnchorY = dragBounds.top;
        }
        return true;

    case kEventLeftButtonDown:
        if (compositionDragActive) {
            return false;
        }

        if (!PointInRect(event->mouseY, event->mouseX, &m_bounds)) {
            return false;
        }

        compositionDragActive = true;
        compositionDragStartY = event->mouseY;
        compositionDragStartX = event->mouseX;
        compositionDragSavedMode = m_mode;

        if (compositionDragSavedMode == 2) {
            SetMode(0);
        } else if (compositionDragSavedMode == 3) {
            SetMode(1);
        }
        return true;

    case kEventLeftButtonUp:
        if (!compositionDragActive) {
            return false;
        }

        g_pIMEPane->focusCaretAnchorY = m_origin.y;
        g_pIMEPane->focusCaretAnchorX = m_origin.x;
        SetMode(compositionDragSavedMode);
        compositionDragActive = false;
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended exact support class-shell replacement for [UID:00006G] `by-class/IMECompositionPane.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class IMEPane;
class Pane;

class IMECompositionPane : public Pane
{
public:
    IMECompositionPane();
    virtual ~IMECompositionPane();

    void SetCompositionString(const wchar_t *text, int length);
    int GetCompositionWidth() const;

protected:
    virtual bool OnMouseEvent(const Event *event);
    virtual bool OnKeyEvent(const Event *event);
    virtual void OnPaint();

private:
    int compositionCursorX;              // +0xf8, cached cursor pixel offset.
    wchar_t compositionText[256];        // +0xfc, bounded UTF-16 composition text.
    bool compositionDragActive;          // +0x2fc, true while the popup is being dragged.
    int compositionDragStartY;           // +0x300, mouse event +0x08 at drag start.
    int compositionDragStartX;           // +0x304, mouse event +0x0c at drag start.
    unsigned char compositionDragSavedMode;  // +0x308, saved Pane mode byte.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason this preserves behavior: it matches the decompiled branches, return values, drag state writes, `PointInRect` gate, mode transitions through `Pane::SetMode`, geometry update through inherited bounds helpers, and `g_pIMEPane` focus-anchor writes.

Reason it is source-shaped: it uses the existing class/file route and accepted helper names instead of raw `this-0xa0`, `unk_69B458`, `sub_5446B0`, `sub_4B7E80`, or raw offsets.

## Score And Metadata Recommendation

Target before: `80/86`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.

Target after supervisor callback should be:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00006G
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006G
EMITTER_POSITION_OPTIONAL:
```

Score rationale:

- Completion `88`: exact range/padding, vtable reachability, event branch behavior, drag fields, constructor initialization, inherited helper names, `g_pIMEPane` anchor effects, and formal C++ are documented.
- Confidence `91`: current MCP directly confirms control flow, offsets, callees, vtable xref, and singleton reads. It stays below final-audit range because enum constant spellings, inherited `m_origin` naming, and exact original private field names are inferred rather than symbol-proven.

Support score recommendation:

- [UID:00006G] `IMECompositionPane`: raise from `87/90` to `88/91` if implementation updates the class shell with drag fields and the method row with UID0004C3 formal C++ status.
- [UID:0000K5] `IMEPanes`: no required score change; add a support note only. One child body improving does not close the remaining blank sibling methods.
- [UID:000189] `IMEPaneFamily`: no required score change; update the UID0004C3 row to say formal C++ is populated if the implementation callback lands.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md`

Incorporate:

- Current MCP session and function facts: active `supervisor_resume_20260629`, `lookup_funcs 0x004e7640` size `0x1c9`, vtable xref `0x0061c43c`, no direct callers, padding before/after, and singleton reads at `0x004e7689`, `0x004e77c2`, `0x004e77d3`.
- Behavior: event type `0` moves while dragging, event type `1` starts drag after hit-test, event type `3` ends drag/restores saved mode, all other cases return false.
- Field interpretations: `compositionDragActive +0x2fc`, `compositionDragStartY +0x300`, `compositionDragStartX +0x304`, `compositionDragSavedMode +0x308`.
- Inherited/support interpretation: secondary EventHandler view normalizes to `this-0xa0`; `m_bounds +0x44`, `m_origin +0xac/+0xb0`, `m_mode +0xb5`, `Pane::SetMode`, `PointInRect`, `TranslateRectBounds`, `GetBounds`, `SetBounds`.
- Metadata and exact formal C++ block above.
- Rejected alternatives: InputMan/TextEdit/Pane/global ownership, sibling merge, raw no-code disposition.

## Recommended Support Doc Changes

`by-class/IMECompositionPane.md`

- Replace the class formal block with the support class-shell block above.
- Update Method Notes row for `OnMouseEvent` to reference [UID:0004C3], score `88/91`, formal C++ populated, and drag/mode/anchor behavior.
- Add observed-state bullets for the four drag fields.
- Add evidence note: current MCP decompile of constructor clears `+0x2fc`, target writes/reads `+0x2fc/+0x300/+0x304/+0x308`, and target uses inherited `Pane::SetMode`.
- Recommended score: `88/91`.

`by-file/IMEPanes.md`

- Add a short evidence note that [UID:0004C3] has been child-reviewed and should emit through [UID:00006G], resolving the composition-pane mouse drag field/mode blocker.
- No score change required; remaining IME split children still lack method-body reviews.

`by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

- Update the UID0004C3 row in the split/source-placement table from generic drag/visibility wording to "formal C++ populated; type 0 drag-move, type 1 drag-start, type 3 drag-end/restore; updates root focus anchors and uses Pane::SetMode."
- No score change required unless the supervisor wants a one-point completion bump after generated output refresh.

`by-class/IMEPane.md`, `by-global/g_pIMEPane.md`, and `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`

- Conditional/optional only. These pages already document `focusCaretAnchorY +0x118`, `focusCaretAnchorX +0x11c`, the singleton xrefs including UID0004C3, and the pane-side owner route. A small support note may be added if the supervisor wants all UID0004C3 writes listed explicitly; otherwise mark already-present.

`by-memory/0x005446b0-0x005446d4.PaneSetMode.md`, `by-type/by-struct/PaneLayout.md`, `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`, and `by-file/Event.md`

- Already-present support. Do not edit unless implementation finds the exact field/constant names absent in current content. Current docs already support `Pane::SetMode`, `m_mode +0xb5`, `m_bounds +0x44`, `m_origin +0xac/+0xb0`, Event type `0/1/3`, and union-style event payload fields.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Callback proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | Target current state was `80/86`, owner `00006G`, reconstructable true, blank emitter/C++. | High | Current target metadata read during report pass. | Target Changes / Score Rationale | incorporate | applied | Target now records before/after B009 callback state in `## Changes`; validator `000000003167` applied `88/91`. |
| C002 | MCP was available through session `supervisor_resume_20260629`; no fallback-only evidence used. | High | `initialize`, `idb_list`, `server_health`. | Target Evidence / report evidence note | incorporate | applied | Target Evidence records active session, `server_health` OK, and MCP-backed calls. |
| C003 | Target function is exact `sub_4E7640`, size `0x1c9`, with `0x004e763c-0x004e7640` predecessor padding and `0x004e7809-0x004e7810` successor padding. | High | MCP `lookup_funcs`, `get_bytes`. | Target Evidence / Range notes; aggregate row | incorporate | applied | Target Evidence/Reconstruction Notes and aggregate Covered Ranges/Split table include size, half-open end, and padding. |
| C004 | Target has one vtable data xref at `0x0061c43c` and no direct code callers. | High | MCP `xref_query`, vtable int/name checks. | Target Evidence / Xrefs | incorporate | applied | Target Evidence records vtable slot `0x0061c43c` and no direct code callers. |
| C005 | Event fields used by the body are `type +0x04`, mouseY `+0x08`, mouseX `+0x0c`; event types `0/1/3` are cursor move, left down, left up. | Medium-high | Target disasm/decompile plus Event docs [UID:00014C]/[UID:0000J6]. | Target Behavior; support note if needed | incorporate | applied | Target Behavior and formal C++ use `event->type`, `mouseY`, `mouseX`, and `kEventCursorMove`/left down/up cases. |
| C006 | Type `1` starts drag only when not already active and the cursor point is inside inherited bounds. | High | MCP decompile/disasm: `PointInRect` call, active-byte check. | Target Behavior and C++ | incorporate | applied | Target Behavior and formal C++ include `compositionDragActive` guard and `PointInRect(event->mouseY, event->mouseX, &m_bounds)`. |
| C007 | Drag state fields are `compositionDragActive +0x2fc`, `compositionDragStartY +0x300`, `compositionDragStartX +0x304`, `compositionDragSavedMode +0x308`. | High | Target disasm/decompile; constructor clears `+0x2fc`. | Target Behavior; `by-class/IMECompositionPane.md` class shell/state | incorporate | applied | Target Reconstruction Notes and `by-class/IMECompositionPane.md` formal shell/Observed State include all four fields and offsets. |
| C008 | During move, the method gets current bounds, translates by mouse deltas, sets bounds, and writes `g_pIMEPane->focusCaretAnchorX/Y` from the moved rectangle left/top. | High | Target decompile lines around `0x004e7770-0x004e77dc`; `xrefs_to 0x0069b458`. | Target Behavior/C++; IMEPaneFamily row | incorporate | applied | Target formal C++ and aggregate UID0004C3 rows include drag-move bounds translation and root focus-anchor writes. |
| C009 | During left-button up, the method writes root focus anchors from Pane origin, restores the saved pane mode, clears drag active, and returns true. | High | Target decompile/disasm around `0x004e7689-0x004e76b4`; PaneLayout `+0xac/+0xb0` origin. | Target Behavior/C++; class support note | incorporate | applied | Target formal C++ and class Method Notes include release behavior, `m_origin`, `SetMode`, and active-state clear. |
| C010 | `sub_5446B0` is `Pane::SetMode(unsigned char)`, not visibility or IME-specific code. | High | [UID:0002V7] formal C++ and PaneLayout support. | Target Reconstruction Notes; support already-present | already-present | already-present | Pane support docs were read-only; target Reconstruction Notes cite existing [UID:0002V7] support and no contradiction was found. |
| C011 | Correct owner/emitter is [UID:00006G] `IMECompositionPane`; [UID:0000K5] remains source file route. | High | Vtable slot, class/aggregate/file docs, target state. | Target metadata/status; file/class support | incorporate | applied | Target metadata now has `EMITTER_UIDS:00006G`; class/by-file/aggregate support notes route through [UID:00006G] into [UID:0000K5]. |
| C012 | InputMan, TextEditPane, Pane, and g_pIMEPane/global ownership alternatives are rejected. | High | Negative evidence from target callees/xrefs and current support docs. | Target Reconstruction Notes; report rejected alternatives | incorporate | applied | Target Reconstruction Notes preserve all rejected ownership/no-code/sibling-merge alternatives at report-level detail. |
| C013 | Target clears code-entry gate and should emit the exact formal `OnMouseEvent` C++ block. | High | Recommended `88/91`, valid emitter route, body resolved by MCP. | Target formal C++ | incorporate | applied | Target formal C++ block is populated; validator `000000003167` and generated `IMEPanes.cpp` command `000000003173` include `IMECompositionPane::OnMouseEvent`. |
| C014 | `IMECompositionPane` class shell must add four drag fields after `compositionText[256]`. | High | Constructor/target decompilation and primary offset math. | `by-class/IMECompositionPane.md` formal class shell and Observed State | incorporate | applied | `by-class/IMECompositionPane.md` formal shell and Observed State include four fields; validator `000000003169` passed. |
| C015 | Generated `IMEPanes.cpp` should refresh after validators and include `IMECompositionPane::OnMouseEvent`; no generated/manual coverage files should be edited by hand. | High | by-structure generated-output rules and current generated lead. | Report checklist; implementation callback proof | incorporate | applied | B009 final root validator `000000003173` completed generated refresh and emitted UID0004C3. Later read-only check found current generated header `000000003177`, newer than B009, still containing UID0004C3 body and no `Empty Emitter Marker`. |

## Open Questions With Attempted Resolution

- Exact original enum names for mouse event types are not symbol-proven. Current Event docs provide accepted source-facing names, so this is a final-audit naming cap, not a C++ blocker.
- Exact original names for `m_origin`, `m_bounds`, and `m_mode` are inherited Pane names. Current Pane docs support those names or close variants strongly enough for first-draft C++.
- Exact original names for the new composition drag fields are inferred from behavior. The offsets and dataflow are direct MCP facts; the chosen names are source-facing and coherent with existing `compositionCursorX` / `compositionText` style.

## Validator Results

Report-only pass:

- No validators were run and no by-* docs were edited.

Implementation callback pass:

| Command | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md --apply --wait-generated --queue-timeout 240` | `000000003167` | `2026-06-30T16:02:24-04:00` | `0` | `1` | `completed`; generated refresh command `000000003167` at `2026-06-30T16:02:24-04:00`. |
| `python .\tools\validator.py --mode file --file by-class/IMECompositionPane.md --apply --wait-generated --queue-timeout 240` | `000000003169` | `2026-06-30T16:02:42-04:00` | `0` | `1` | `completed`; generated refresh command `000000003169` at `2026-06-30T16:02:42-04:00`. |
| `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240` | `000000003171` | `2026-06-30T16:04:25-04:00` | `0` | `1` | `completed`; generated refresh command `000000003171` at `2026-06-30T16:04:25-04:00`. |
| `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240` | `000000003173` | `2026-06-30T16:04:42-04:00` | `0` | `1` | `completed`; generated refresh command `000000003173` at `2026-06-30T16:04:42-04:00`. |

Validator-owned side effects observed: generated metadata/report refreshes, `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` refresh/update messages, project-level projected stats update messages, and validator autogen backups under `tools/validator_autogen_backup/`. These were tool outputs only; no generated C++, generated report, manual coverage report, validator state, queue file, lock file, IDA DB, supervisor ledger, or archive was manually edited.

Generated freshness check:

- `auto-generated/NexusTK/input/IMEPanes.cpp` header after B009 final validator matched `validator-command-id: 000000003173`, `validator-refreshed-at: 2026-06-30T16:04:42-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- A later read-only check after another agent's refresh found the current generated header at `validator-command-id: 000000003177`, `validator-refreshed-at: 2026-06-30T16:08:17-04:00`, which is newer than B009's final relevant command and still current for UID0004C3.
- `Select-String` found [UID:0004C3] at the generated `IMECompositionPane::OnMouseEvent` body and found no `Empty Emitter Marker` match in `IMEPanes.cpp`.

Lease proof:

- Batch 1: leased target `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md` and `by-class/IMECompositionPane.md` as `B009`; lease report showed creation `2026-06-30T20:00:38Z`, expiration `2026-06-30T20:05:38Z`. Both were released with `Success` after validators `000000003167` and `000000003169`.
- Batch 2: after re-reading current lease report and seeing no active leases, leased `by-file/IMEPanes.md` and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` as `B009`. Both were released with `Success` after validators `000000003171` and `000000003173`.
- Post-release lease report contained no `B009` rows; it showed later `B008` leases on shared IME support docs after B009 had released them.

## Changed Files

- Updated target: `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md`.
- Updated support: `by-class/IMECompositionPane.md`.
- Updated support: `by-file/IMEPanes.md`.
- Updated support: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
- Updated report bookkeeping: `tools/leaser/Agents/Agent-B009/research/0004C3-IMECompositionPaneOnMouseEvent-source-quality.md`.
- Not manually edited: generated C++, generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, lock files, and unrelated docs.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted report and issued implementation callback.
- [x] Update target `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md` metadata to `88/91`, keep owner/reconstructable, set `EMITTER_UIDS:00006G`, leave optional position blank, and insert the exact target formal C++ block. Proof: target edited and validator `000000003167` passed.
- [x] Target body notes must preserve MCP session `supervisor_resume_20260629`, range size `0x1c9`, padding bytes, vtable xref `0x0061c43c`, no direct callers, g_pIMEPane read sites, constructor initialization of `+0x2fc`, branch behavior, drag field offsets, and rejected alternatives. Proof: target Evidence/Reconstruction Notes/Changes contain these facts.
- [x] Update `by-class/IMECompositionPane.md` formal shell with the exact support class block, add drag-state observed fields, update `OnMouseEvent` method row to UID0004C3 `88/91` formal C++ populated, and raise class score to `88/91` if the supervisor accepts that score move. Proof: class edited and validator `000000003169` passed.
- [x] Update `by-file/IMEPanes.md` with a concise UID0004C3 source-emission/support note; no required score change. Proof: by-file Proposed Contents/Evidence Notes/Changes updated and validator `000000003173` passed.
- [x] Update `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` UID0004C3 row to reflect formal C++ populated and exact drag/mode/root-anchor behavior; no required score change. Proof: aggregate Covered Ranges, Evidence Notes, split table, and Changes updated; validator `000000003171` passed.
- [x] Treat `by-class/IMEPane.md`, `by-global/g_pIMEPane.md`, and `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` as already-present unless implementation finds missing anchor/write wording; if edited, preserve current B008 zero/null singleton evidence. Proof: re-read support during report pass; no conflict found during callback; not edited.
- [x] Treat Pane/Event support docs as already-present support for `Pane::SetMode`, `m_mode`, `m_bounds`, `m_origin`, event type `0/1/3`, and mouse coordinate fields; do not edit unless current content contradicts implementation. Proof: target cites existing [UID:0002V7], [UID:0001VH], [UID:00014C], and [UID:0000J6]; no support edits needed.
- [x] Preserve rejected alternatives: InputMan ownership, TextEdit/TextBox ownership, Pane/helper ownership, global-owned body, no-code marker, sibling merge, and aggregate-body rewrite. Proof: target Reconstruction Notes preserve all rejected alternatives.
- [x] Run scoped validators for every changed by-* file with `--apply --queue-timeout 240`; use `--wait-generated` where generated `IMEPanes.cpp` freshness matters. Proof: validators `000000003167`, `000000003169`, `000000003171`, and `000000003173` all exited `0`, `ok:1`, generated refresh `completed`.
- [x] Inspect generated `auto-generated/NexusTK/input/IMEPanes.cpp` header after final validator and confirm it is equal/newer than the final relevant command metadata and contains UID0004C3 `IMECompositionPane::OnMouseEvent`. Proof: B009 header initially matched `validator-command-id: 000000003173`; later current header is newer at `000000003177`; UID0004C3 body remains present; no empty-emitter marker found.
- [x] Update this report's Claim And Incorporation Ledger and checklist to callback `applied`, `already-present`, `excluded-with-reason`, or `blocked` states with proof during implementation callback. Proof: ledger has callback proof column and verification states updated.
- [x] Do not manually edit generated files, generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, lock files, or unrelated docs. Proof: only allowed by-* docs and this report were manually edited; generated updates were validator-owned.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback assignment received for [UID:0004C3].
- [x] All accepted target/support doc details incorporated at report-level detail or explicitly excluded with reason. Proof: target, class, by-file, and aggregate support updated; optional IMEPane/g_pIMEPane/Pane/Event docs marked already-present/read-only.
- [x] Claim And Incorporation Ledger updated with callback verification states and proof. Proof: ledger rows C001-C015 updated.
- [x] Validators run and recorded with command ids, timestamps, exit codes, ok counts, warnings, and generated-refresh state. Proof: Validator Results table above.
- [x] Leases, if any, used only for immediate edit/validator batches and released immediately. Proof: two B009 lease batches released with `Success`; post-release lease report had no B009 rows.

Unchecked blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0004C3-IMECompositionPaneOnMouseEvent-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0004C3-IMECompositionPaneOnMouseEvent-source-quality.md","timestamp":"2026-06-30T16:14:26","uid":"0004C3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
