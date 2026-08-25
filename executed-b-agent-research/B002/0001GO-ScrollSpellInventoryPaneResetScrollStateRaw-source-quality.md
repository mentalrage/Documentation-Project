** TARGET-REPORT-UID:0001GO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GO ScrollSpellInventoryPaneResetScrollStateRaw Source-Quality Research

Assignment id: `B002-goal2-scroll-spell-inventory-reset-source-quality-0001GO-20260618`  
Agent: `Agent-B002`  
Primary target: [UID:0001GO] `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md`  
Required mode: report-only; no by-* docs, generated reports/source, IDA DB, or coverage report edited directly.

## Executive Recommendation

[UID:0001GO] should remain an exact source-bearing child for the raw helper at `0x005608a0-0x005608fc`, but its direct owner/emitter should change from file [UID:0000NJ] to class [UID:0000CN]. The best source-facing declaration is:

```cpp
void ScrollSpellInventoryPane::ResetScrollState();
```

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000CN
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CN
EMITTER_POSITION_OPTIONAL:
```

The old "below 95/95" / "95/95-bar" wording is stale. Under the active code-entry gate observed in the project completion stats, a reconstructable target with emitter route and `(COMPLETION + CONFIDENCE) / 2 > 85` is eligible. With `87/89`, [UID:0001GO] should receive first-draft formal C++ despite the raw no-function/no-direct-caller caveat.

## Evidence Checked

- Active supervisor rules, Agent-B002 `goal.md`, Agent-B002 `notes.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Primary target [UID:0001GO].
- Owner/support docs: [UID:0000CN] `ScrollSpellInventoryPane` class, [UID:0000NJ] `ScrollSpellInventoryPane` file, [UID:0000LU] `NewSpellInventoryPane` file, [UID:00009A] `NewSpellInventoryPane` class.
- Neighbor/sibling docs: [UID:0001GM] `ScrollSpellInventoryPane` aggregate, [UID:0001GN] `ScrollSpellInventoryPaneUpdateFromDrag`, [UID:0001H1] `ScrollInventoryPaneResetScrollStateRaw`, [UID:0001H0] `ScrollInventoryPaneUpdateFromDrag`, [UID:0002LD] `ScrollVolumePaneResetInteractionStateRaw`.
- Layout/vtable/helper docs: [UID:0001W1] `ScrollSpellInventoryPaneLayout`, [UID:0001YS] `ScrollSpellInventoryPaneVtables`, [UID:0001K8] `TimerHandlerScheduleRemoveWrappers`.
- Generated-state reports: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `project-level/-auto-completion-stats.md`.
- Active generated source path: `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`.
- Lead source path: `simroot_v2/ui/inventory/class_ScrollSpellInventoryPane.cpp`.
- IDA text export: `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`.
- Local PE bytes: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Live IDA MCP was attempted at `http://127.0.0.1:13337/mcp`, but it was unreachable during this pass. Therefore the fresh recheck uses the existing IDA-backed project docs/export plus an independent local PE scan.

## Binary / Boundary Findings

The local PE scan used `NexusTK.exe` with MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`, image base `0x00400000`, `.text` range `0x00401000-0x0060c4ac`, `.rdata` range `0x0060d000-0x0066c0be`, and `.data` range `0x0066d000-0x0069ce24`.

The target boundary is exact:

- `0x0056089d-0x0056089f` is `cc cc cc`.
- `0x005608a0` begins a normal `push ebp; mov ebp, esp` method-shaped prologue.
- `0x005608fb` returns.
- `0x005608fc-0x005608ff` is `cc cc cc cc`.
- `0x00560900` begins the next modeled function and has a separate direct caller at `0x0056caae`.

The IDA listing confirms that IDA does not currently define a procedure object at `0x005608a0`: it appears as raw aligned code after `sub_560710 endp` and before `sub_560900 proc near`.

## Raw Body Semantics

The raw body at `0x005608a0-0x005608fb`:

1. Saves `esi = this`.
2. Calls `sub_597600` with `ecx = this + 0xa4`.
3. Reads old `this + 0x103`.
4. Writes `this + 0x104 = 0xff`.
5. If old `this + 0x103` was not `0xff`, builds a stack rectangle through `sub_560290(this, oldPart, &rect)`.
6. Calls the primary Pane virtual at vtable slot `+0x20` with the rectangle pointer.
7. Writes `this + 0x103 = 0xff`.
8. Returns.

The best source interpretation is "stop/cancel scroll-part interaction state, clear the active part, invalidate the old hover/highlight part if one existed, then clear hover part."

## Direct Xref / Reachability Recheck

Fresh PE scanning found:

- VA literal references to `0x005608a0`: zero.
- RVA literal references to `0x001608a0`: zero.
- Direct branch/call edges to `0x005608a0`: zero.
- External direct branches/calls into the target span `0x005608a0-0x005608fc`: zero.
- Equivalent raw neighbor controls `0x00560520` and `0x00560590`: also zero VA/RVA/direct references.
- Positive controls worked: `0x00560710` has direct edges from `0x005606ab` and `0x005606d4`; `0x00560290` has 13 direct edges; `0x00597600` has 45 direct edges; `0x005975e0` has 163 direct edges.
- Vtable positive controls worked: `0x0055f650`, `0x0055f850`, and `0x0055f890` each appear as expected in `.rdata` vtable slots.

This validates the current "no direct xref / no direct caller / no pointer-table route" finding for [UID:0001GO]. It does not prove impossible runtime reachability by computed control flow, but there is no defensible static direct route to record.

The modeled mouse handler at `0x0055f650` contains an inline release/cleanup branch with the same core operations: end capture, remove pending timers through the `+0xa4` timer view, clear `+0x104`, invalidate the old `+0x103` part through `sub_560290` and Pane virtual `+0x20`, then clear `+0x103`. That supports the semantic name and field roles, but it is not a call to this raw helper.

## Heuristic / Inference Reanalysis And Validation

Best source-facing method name:

- Use `ScrollSpellInventoryPane::ResetScrollState`.
- Evidence: target title, active simroot lead code, behavior, and sibling naming all converge on reset of scroll/part interaction state.
- Rejected alternative: `ResetInteractionState`. That name is appropriate for the accepted [UID:0002LD] ScrollVolumePane precedent, but this target's existing source lead and target name consistently use `ResetScrollState`.
- Rejected alternative: `ClearHoverPart` / `ClearActivePart`. These names are too narrow because the helper removes timers, clears active/tracking state, invalidates old hover rectangle, and clears hover state.

Best signature:

- `void ScrollSpellInventoryPane::ResetScrollState()`.
- No arguments are consumed and no return value is produced by the machine code.
- This is an ordinary instance method, not a virtual entry: no vtable slot points at `0x005608a0`.

Field and helper conclusions:

- `this + 0xa4`: tertiary `TimerHandler` / timer-update handler view or subobject. The constructor/vtable docs show tertiary vtable `0x00623f10`, repeat paths schedule timers through this view, and this target removes pending timers through it. It should not be modeled as a plain integer/member byte array in source.
- `this + 0x103`: `char m_hoverPart`. `0xff` / `-1` is the no-part sentinel. `SetHoverPart` at `0x00560520`, the raw reset helper, and the inline mouse-release cleanup all invalidate the old hover part rectangle before replacing/clearing it.
- `this + 0x104`: `char m_activePart` or, slightly less cleanly, `m_trackingPart`. It is not "previous active part." Begin-interaction code writes the clicked/tracked part, drag/update paths read it as the current part being manipulated, and reset clears it. The current simroot name `m_prevActivePart` should be treated as generated-source pollution.
- `sub_597600`: `TimerHandler::RemovePendingTimers()` / `RemovePendingTimers()` on the `+0xa4` timer view. [UID:0001K8] proves broad fan-in and TimerHandler ownership, not ScrollSpell-specific ownership.
- `sub_560290`: `ScrollSpellInventoryPane::GetPartRect(char part, RectBounds *outRect)`. Callers use it to materialize a rectangle for a scroll-control part; any decompiler return artifact should be ignored for source-quality C++.
- Pane vtable slot `+0x20`: `Pane::InvalidateRect` or equivalent invalidation virtual.

Ownership/source placement:

- Direct class owner [UID:0000CN] is the defensible owner because the body is an instance method over ScrollSpellInventoryPane fields, helpers, and vtables.
- File [UID:0000NJ] is the source-file ancestor and generated file route, not the direct semantic owner.
- [UID:0000LU] / [UID:00009A] `NewSpellInventoryPane` is a consumer/fold candidate because its constructor is the only currently documented allocator/caller route for the class, but the reset helper is not a NewSpellInventoryPane method and should not be directly owned there.
- Shared scrollbar/helper ownership is rejected. The code uses ScrollSpellInventoryPane layout offsets and the class-local `GetPartRect`; generic scrollbar code is only a conceptual dependency.
- TimerHandler ownership is rejected. `sub_597600` is a helper dependency, not the source owner of the reset method.

Relationship to [UID:0001GM] and [UID:0001GN]:

- [UID:0001GM] should remain the class aggregate and direct class-level source context. Its docs already route through [UID:0000CN]; its coverage row is stale if it still says `84%`/unassigned.
- [UID:0001GN] already has the right owner/emitter pattern and should remain the nearby modeled update helper. Its coverage row is stale if it still says `86%`/unassigned while the doc metadata is `87/89`.
- [UID:0001GO] should be aligned with those pages by moving owner/emitter to [UID:0000CN].

Sibling [UID:0001H1]:

- [UID:0001H1] is a strong item-inventory sibling with nearly identical raw reset structure and the same old blocker language.
- This report should not directly raise or populate [UID:0001H1] because the assignment is target-specific and this pass did not repeat a full binary route scan for the item-inventory address range.
- [UID:0001H1] should not block [UID:0001GO]. The current stronger policy precedent is [UID:0002LD], where a raw no-direct-route helper was raised and given first-draft C++ after sufficient source/body evidence.

Open blockers after this pass:

- No live IDA MCP session was available.
- No direct static caller, pointer table, vtable slot, RVA literal, or external direct branch into the target span was found.
- Therefore final docs should not claim live reachability or create a function object solely from this research.
- These blockers affect final confidence and prevent a 95+ audit posture, but they do not block first-draft target C++ at the recommended `87/89` score.

## First-Draft C++ Recommendation

Populate [UID:0001GO]'s formal C++ block after applying the score and owner/emitter update. This is eligible source C++ because the target is reconstructable, exact-bodied, class-owned, and above the active code-entry threshold. The code should be source-facing, not a copied decompiler artifact and not a raw-layout cast dump.

Recommended draft:

```cpp
void ScrollSpellInventoryPane::ResetScrollState()
{
    RectBounds rect;
    char oldPart;

    RemovePendingTimers();

    oldPart = m_hoverPart;
    m_activePart = -1;

    if (oldPart != -1) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_hoverPart = -1;
    }
}
```

Notes for incorporation:

- If local style requires explicit base/helper qualification, use `m_timerHandler.RemovePendingTimers()` or `TimerHandler::RemovePendingTimers()` for the `this + 0xa4` call. Do not emit `reinterpret_cast<TimerHandler*>(this + 0xa4)` in final source-quality C++ unless the class layout support doc has not yet named the timer view.
- `RectBounds` may be replaced with the project's established rectangle type if [UID:0000CN]/[UID:0001W1] standardizes a different name.
- Use `m_activePart`, not `m_prevActivePart`, unless the supervisor deliberately preserves the current simroot name as a temporary generated alias.

## Exact Supervisor Edits

### [UID:0001GO] Metadata

In `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md`, replace the current score/owner/emitter metadata with:

```text
*** COMPLETION:87
*** CONFIDENCE:89
*** CANONICAL_OWNER:0000CN
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:0000CN
*** EMITTER_POSITION_OPTIONAL:
```

### [UID:0001GO] Status Replacement

Replace the current status/open-question block that says the target is below the old first-draft bar with:

```text
## Status

- Disposition: reconstructable NexusTK project code with raw-function/no-direct-route caveat.
- Entity kind: raw method-shaped helper and exact source-bearing child.
- Source-facing method: `void ScrollSpellInventoryPane::ResetScrollState()`.
- Direct owner/emitter: [UID:0000CN] `ScrollSpellInventoryPane`; source-file ancestor [UID:0000NJ] `ScrollSpellInventoryPane`.
- Rebuild handling: source-authored helper. The raw start has no current IDA function object, direct caller, VA/RVA literal, pointer-table route, or vtable slot, so do not claim a live static caller from this page. The no-route caveat is score-limiting, not C++-blocking after the 2026-06-18 B002 score/source update.
- Confidence: strong for exact boundary, helper/body semantics, class ownership, and rejected hidden direct/table/vtable routes; medium for runtime reachability because no static route was proven.
```

### [UID:0001GO] Autogen / C++ Gate Replacement

Replace stale `95/95` wording with:

```text
## Autogen Status

- Reconstructable: true, exact raw source-bearing method-shaped project code.
- Direct owner/emitter: [UID:0000CN] `ScrollSpellInventoryPane`, which routes to [UID:0000NJ] `ScrollSpellInventoryPane` and generated path `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`.
- Generated-output caveat: the active generated `ScrollSpellInventoryPane.cpp` is currently zero bytes. `simroot_v2/ui/inventory/class_ScrollSpellInventoryPane.cpp` supplies useful lead names (`ResetScrollState`, `SetHoverPart`, `GetPartRect`) but also contains synthetic layout/pad/non-source-quality pollution and should not be copied directly.
- C++: populate the formal block after applying the score and owner/emitter update. The active gate is not the old `95/95` bar; with `87/89`, `RECONSTRUCTABLE:TRUE`, and emitter [UID:0000CN], this target clears `(COMPLETION + CONFIDENCE) / 2 > 85`.
```

### [UID:0001GO] Formal C++ Insert

Place this in the formal C++ section:

```cpp
void ScrollSpellInventoryPane::ResetScrollState()
{
    RectBounds rect;
    char oldPart;

    RemovePendingTimers();

    oldPart = m_hoverPart;
    m_activePart = -1;

    if (oldPart != -1) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_hoverPart = -1;
    }
}
```

### [UID:0001W1] Layout Support Update

In `by-memory/0x0055f450-0x00560900.ScrollSpellInventoryPaneLayout.md`, replace or add the field rows for `+0xa4`, `+0x103`, and `+0x104` with:

```text
| `+0xa4` | timer/update handler view | Tertiary `TimerHandler`-style subobject/view. Constructor installs tertiary vtable `0x00623f10`; repeat/reset paths call timer schedule/remove helpers with `ecx = this + 0xa4`. Treat as a TimerHandler view in source, not as an ordinary scalar data field. |
| `+0x103` | `char m_hoverPart` | Hover/highlight scroll-control part. `0xff` / `-1` is the no-part sentinel. `SetHoverPart`, inline mouse-release cleanup, and raw reset invalidate the old part rectangle through `GetPartRect` and Pane invalidation before replacing or clearing it. |
| `+0x104` | `char m_activePart` | Active/tracked scroll-control part. Begin-interaction writes the clicked/tracked part, update/commit paths read it, and reset clears it to `0xff`; this replaces misleading `m_prevActivePart` / previous-active wording. |
```

### [UID:0000CN] Class Support Update

In `by-class/ScrollSpellInventoryPane.md`, replace the `ResetScrollState` method row or add it near `SetHoverPart` / `UpdateFromDrag`:

```text
| `ResetScrollState` | [UID:0001GO] `0x005608a0-0x005608fc` | Exact raw source-bearing helper. Removes pending timers through the `+0xa4` TimerHandler view, clears `m_activePart` at `+0x104`, conditionally invalidates the old `m_hoverPart` at `+0x103` through `GetPartRect` and Pane invalidation, then clears `m_hoverPart`. B002 PE scan found no direct caller, VA/RVA literal, pointer-table route, vtable route, or external direct branch into the span; no-route status limits score but no longer blocks first-draft C++ after the `87/89` update. |
```

Add this evidence note if the class page has a research/evidence section:

```text
- 2026-06-18 B002 recheck for [UID:0001GO]: local PE scan of `NexusTK.exe` confirmed exact raw boundary `0x005608a0-0x005608fb`, padding before `0x00560900`, zero VA/RVA literal references to `0x005608a0`, zero direct branch/call edges to the start, and zero external direct branches into the span. Positive controls for nearby modeled helpers and vtable entries resolved, so the no-route finding is meaningful. The helper remains a class method by field/helper/vtable semantics.
```

### [UID:0000NJ] File Support Update

In `by-file/ScrollSpellInventoryPane.md`, update the proposed contents row for `0x005608a0-0x005608fc` to:

```text
| `0x005608a0-0x005608fc` | [UID:0001GO] `ScrollSpellInventoryPaneResetScrollStateRaw` | Source-facing `ScrollSpellInventoryPane::ResetScrollState()`: source-shaped raw helper with no direct static route, no VA/RVA literal, no external branch into span, and no vtable slot; removes pending timers through the class `+0xa4` TimerHandler view, clears `m_activePart`, invalidates/clears old `m_hoverPart`, and should be directly owned/emitted by class [UID:0000CN] with this file as source-file ancestor. Remove old `95/95` no-code wording after score update. |
```

If the file page still points to only `source-3/simroot_v2/class_ScrollSpellInventoryPane.cpp`, add the active path clarification:

```text
- Current generated lead source observed by B002 is `source-3/simroot_v2/ui/inventory/class_ScrollSpellInventoryPane.cpp`; active autogen destination `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` is currently zero bytes.
```

### [UID:0001GM] Aggregate Support Update

If [UID:0001GM] still describes [UID:0001GO] as below gate or excluded from C++, replace that note with:

```text
- [UID:0001GO] `ResetScrollState` is now recommended as an exact source-bearing class child at `87/89`, owner/emitter [UID:0000CN], with first-draft C++ populated. The raw no-direct-route finding remains true and score-limiting, but it is not a code-entry blocker under the active gate.
```

### [UID:0001YS] Vtable Support Update

If [UID:0001YS] has an open question about a vtable route to `0x005608a0`, close it with:

```text
- B002 PE scan found no vtable or pointer-table entry for `0x005608a0`. `ResetScrollState` should be modeled as a non-virtual ordinary instance helper; the relevant vtable use inside the body is the inherited Pane invalidation virtual at primary slot `+0x20`.
```

## Coverage Row Recommendation

Placement context: in `by-memory/-coverage-report.md`, inside `MasterCodeTextSection`, replace the ScrollSpellInventoryPane block for [UID:0001GM], [UID:0001GN], and [UID:0001GO] immediately after the ignored alignment row ending at `0x0055f450` and before [UID:0001GP].

Recommended replacement rows:

```text
    - [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) 0x0055f450-0x005608fc | class aggregate | ScrollSpellInventoryPane : reconstructable : 85% : strong : Attached to [UID:0000CN] `ScrollSpellInventoryPane`; broad aggregate over constructor/mouse/repeat/paint/update/reset helpers, with source-file route through [UID:0000NJ]. B002 confirms [UID:0001GO] raw reset should remain a child rather than an aggregate split blocker.
    - [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) 0x00560710-0x0056089d | method | ScrollSpellInventoryPaneUpdateFromDrag : reconstructable : 87% : strong : Attached to [UID:0000CN] `ScrollSpellInventoryPane`; modeled update-from-drag helper with direct call edges, class-local part/position math, `GetPartRect` invalidation, and emitter route through the class/file.
    - [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) 0x005608a0-0x005608fc | raw method-shaped helper | ScrollSpellInventoryPaneResetScrollStateRaw : reconstructable : 87% : strong : B002 source-quality pass confirms source-facing `ScrollSpellInventoryPane::ResetScrollState()`, exact raw `0x005608a0-0x005608fb` body, `this+0xa4` TimerHandler pending-timer removal through `sub_597600`, `+0x104 = m_activePart` clear, conditional old `+0x103 = m_hoverPart` invalidation through `GetPartRect`/Pane vtable `+0x20`, final `+0x103` clear, exact padding before `0x00560900`, zero VA/RVA literals, zero direct branch/call targets to the raw start, zero external direct branches into the span, rejected `NewSpellInventoryPane`/shared ScrollBar/TimerHandler direct ownership, class owner/emitter [UID:0000CN], and first-draft C++ readiness after score update.
```

Do not update [UID:0001H1] in this coverage pass unless a separate sibling assignment repeats the same evidence standard for that address range.

## Generated Output Recommendation

The active generated destination `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` is zero bytes, while the active reports say [UID:0000NJ]/[UID:0000CN]/[UID:0001GO] emit to it. That is a generation failure or upstream blank-C++ consequence, not evidence that the source file should be empty.

After supervisor applies the target C++ block and owner/emitter change, rerun the generator and verify:

- [UID:0001GO] appears in `auto-generated/-ag-memory-coverage.md` as C++ emitted.
- `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` is no longer zero bytes.
- The emitted code does not use `m_prevActivePart` for `+0x104` unless support docs deliberately retain that alias.

## Validation Commands / Results

Representative local checks performed:

_Executable command block removed from the research report; preserved in [0001GO-ScrollSpellInventoryPaneResetScrollStateRaw-source-quality-removed.md](0001GO-ScrollSpellInventoryPaneResetScrollStateRaw-source-quality-removed.md)._

An independent Python PE scan checked image sections, boundary bytes, direct branch/call targets, VA/RVA literal references, and positive-control references. Live IDA MCP was not available, so no new IDA database edits or live IDA queries were made.

## Files Changed By Agent-B002

Only this report was created:

```text
project-documentation/tools/leaser/Agents/Agent-B002/research/0001GO-ScrollSpellInventoryPaneResetScrollStateRaw-source-quality.md
```

No by-* docs, generated docs/source, IDA DB files, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001GO-ScrollSpellInventoryPaneResetScrollStateRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001GO"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GO-ScrollSpellInventoryPaneResetScrollStateRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001GO-ScrollSpellInventoryPaneResetScrollStateRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
