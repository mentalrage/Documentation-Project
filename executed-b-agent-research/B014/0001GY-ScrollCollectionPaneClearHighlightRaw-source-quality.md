** TARGET-REPORT-UID:0001GY **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GY ScrollCollectionPaneResetScrollStateRaw Source-Quality Research

Assignment: `B014-report-0001GY-scroll-collection-pane-clear-highlight-raw-20260625`

Primary target: [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw.md`

Report timestamp: `2026-06-25T04:13:25-04:00`

## Executive Recommendation

Rename and retitle [UID:0001GY] to the source-facing reset helper name:

```text
by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md
# 0x00563200-0x0056325c ScrollCollectionPane ResetScrollState Raw
```

The current `ClearHighlight` name is a useful historical alias, but it is too narrow for final source-facing use. The body cancels pending timer/update work through the `+0xa4` `TimerHandler` view, clears `m_activePart`, invalidates any stale highlighted part rectangle, and clears `m_highlightPart`. This matches the accepted sibling reset-state helpers for `ScrollSpellInventoryPane`, `ScrollInventoryPane`, `FittingRoomScrollPane`, and `ScrollVolumePane`.

Recommended metadata after implementation:

```text
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:0000CG
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CG
```

Recommended formal C++ block:

```cpp
void ScrollCollectionPane::ResetScrollState()
{
    RectBounds rect;
    char oldPart;

    RemovePendingTimers();

    oldPart = m_highlightPart;
    m_activePart = -1;

    if (oldPart != -1) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = -1;
    }
}
```

The raw no-function/no-direct-route caveat remains and should continue to block IDA function creation and live-caller claims. It does not block bounded first-draft C++ under the current by-structure gate because the target is reconstructable, already routes through [UID:0000CG], has a combined score above 85 after this correction, and now has source-quality names and sibling precedent.

## Current Target State

The source page currently has:

- `COMPLETION:85`, `CONFIDENCE:88`
- `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`
- blank formal C++ despite being routed and eligible under the active combined-score gate
- title and filename `ScrollCollectionPaneClearHighlightRaw`
- current item summary describing scheduler cleanup, `+0x103/+0x104` sentinel clears, rectangle invalidation, no direct modeled callers, and padding before `ScrollInventoryPane`
- stale final-C++ rationale: the page still says C++ stays blank because raw-boundary/source names are below a `95/95` final-source gate

The generated reports are stale relative to the source page. `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show [UID:0001GY] at old `74/86` values, and `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` still contains only an old empty marker for this UID. Those are validator-owned generated artifacts; do not edit them by hand.

No leases were taken and no by-* files were edited for this report-only pass.

## Evidence Checked

Workflow and local guidance:

- `tools/leaser/Agents/Agent-B014/goal.md`
- `tools/leaser/Agents/Agent-B014/notes.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `by-structure.md`
- `tools/validator_README.txt`
- `by-memory/-guidance.md`

Primary and support docs:

- [UID:0001GY] target page
- [UID:0000CG] `by-class/ScrollCollectionPane.md`
- [UID:0000NG] `by-file/ScrollCollectionPane.md`
- [UID:0001GT] `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`
- [UID:0001VZ] `by-type/by-struct/ScrollCollectionPaneLayout.md`
- [UID:0001YP] `by-type/by-vtable/ScrollCollectionPaneVtables.md`
- [UID:0001GV], [UID:0003MX], [UID:0003MY], [UID:0001GW], and [UID:0001GX] adjacent ScrollCollectionPane helper docs
- [UID:0001K8] `TimerHandlerScheduleRemoveWrappers`
- [UID:0001GO], [UID:0001H1], [UID:0002DB], and [UID:0002LD] sibling raw reset helpers
- `by-file/ScrollBar.md` and `by-project-structure/proposed-source-tree.md` as read-only source-placement context
- generated tracker/coverage/C++ artifacts as read-only stale-state context

IDA MCP status and provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `server_health`: `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready

Current MCP checks:

- `lookup_funcs` over `0x005631fd`, `0x00563200`, `0x0056325b`, and `0x0056325c` reports `Not a function`; `0x00563260` is `sub_563260`, size `0xa1`.
- `entity_query` over `0x00561d00-0x00563320` lists the ScrollCollectionPane modeled functions and shows no function between `sub_563070` at `0x00563070`, size `0x18d`, and successor `sub_563260` at `0x00563260`.
- `get_bytes` confirms `0x005631fd-0x00563200` is `cc cc cc`, `0x00563200-0x0056325c` is the 92-byte helper body, `0x0056325b` is `c3`, and `0x0056325c-0x00563260` is four `cc` bytes.
- `insn_query 0x00563200-0x0056325c` returns 32 ownerless instructions: stack-cookie prologue, `lea ecx,[esi+0xa4]`, call `sub_597600`, `+0x103/+0x104` state handling, call `sub_562BF0`, virtual invalidation through slot `+0x20`, stack-cookie check, and `retn`.
- `xrefs_to` / `xref_query` find no direct external xref to raw start `0x00563200`; only local instruction/fallthrough edges appear inside the raw span.
- `decompile 0x00563200` fails because there is no modeled function at that address.
- `disasm 0x00563200` renders `<no function>` and shows the raw helper followed by `align 10h` and `sub_563260`.
- `callees 0x00563200` returns `No function found`; outgoing calls are therefore documented from raw disassembly rather than modeled call-graph metadata.
- `analyze_function 0x00562bf0` confirms the rectangle helper has prototype-shaped `int __thiscall(int this, char, int *)`, is called from this target at `0x00563236`, and has thirteen code xrefs in the ScrollCollectionPane cluster.
- `analyze_function 0x00562fb0` confirms the active/drag helper uses `+0x104`, `+0x103`, `sub_5628D0`, `sub_562BF0`, and `sub_563070`.
- `analyze_function 0x00563070` confirms the cursor-to-position helper uses `+0xfc`, `+0xfe`, `+0x100`, `+0x108/+0x10c`, and owner callback `0x0056fa90`.

Fresh local PE scan:

- File: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- Imagebase: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- No absolute-VA dword hit for `0x00563200` or `0x0056325c`.
- No image-RVA dword hit for `0x00163200` or `0x0016325c`.
- No dword hit into the target VA range `0x00563200-0x0056325c`.
- No dword hit into the target RVA range `0x00163200-0x0016325c`.
- No direct call/jump/conditional branch targets raw start `0x00563200`.
- The only direct branch target inside the target range is the helper's own conditional skip `0x0056322d -> 0x0056324d`.
- Positive controls worked: direct calls to `0x00562bf0` include the target callsite `0x00563236`, and direct calls to `0x00597600` include the target callsite `0x00563219`.

## Raw Behavior

The raw body is:

```asm
00563200  push    ebp
00563201  mov     ebp, esp
00563203  sub     esp, 14h
00563213  lea     ecx, [esi+0A4h]
00563219  call    sub_597600
0056321e  mov     al, [esi+103h]
00563224  mov     byte ptr [esi+104h], 0FFh
0056322b  cmp     al, 0FFh
0056322d  jz      short loc_56324D
00563232  push    rect
00563233  push    eax
00563236  call    sub_562BF0
00563243  call    dword ptr [eax+20h]
00563246  mov     byte ptr [esi+103h], 0FFh
00563253  call    @__security_check_cookie@4
0056325b  retn
```

Source-equivalent behavior:

1. Cancels pending timer/update work through the `TimerHandler` view at `this+0xa4`.
2. Copies old highlighted part from `this+0x103`.
3. Clears active/interacting part `this+0x104` to the no-part sentinel `0xff`.
4. If the old highlighted part was not `0xff`, computes its part rectangle through `ScrollCollectionPane::GetPartRect`, invalidates the rectangle through the inherited pane virtual at slot `+0x20`, then clears `this+0x103` to `0xff`.
5. Returns normally after the stack-cookie epilogue.

## Heuristic / Inference Reanalysis And Validation

### Raw No-Function And Liveness

Current IDA still does not model `0x00563200` as a function, and both IDA xref queries and the fresh local PE route scan found no static route to the raw start. That means no live caller should be claimed, and no IDA function should be created from this report.

This is still source-authored code, not padding or compiler glue. The body has a normal prologue, stack-cookie instrumentation, instance-field operations, calls into class-local `GetPartRect`, inherited pane invalidation, and a normal return. It sits between explicit `0xcc` alignment and the next sibling constructor. The same no-route pattern has already been accepted for sibling reset helpers, including [UID:0001GO], [UID:0001H1], [UID:0002DB], and [UID:0002LD].

### Source-Facing Method Name

Best name: `ScrollCollectionPane::ResetScrollState()`.

Evidence:

- The body resets interaction state, not only highlight state.
- It removes pending timer/update events, clears active part `+0x104`, conditionally invalidates old highlight part `+0x103`, and clears highlight state.
- The accepted sibling helpers use `ResetScrollState()` for spell/inventory/fitting scroll panes and `ResetInteractionState()` for volume, where the volume source family uses different naming.
- The current class page already calls the surrounding helpers `SetHighlightedRegion`, `SetActiveRegionAndStartDrag`, `UpdateDragScroll`, and `UpdatePositionFromCursor`; `ResetScrollState` is the cleanup counterpart to those interaction helpers.

Rejected names:

- `ClearHighlight`: historical alias retained for searchability, but too narrow for final source because it omits timer cancellation and active-part reset.
- `StopTimer` / `RemovePendingTimers`: too narrow and collides with the generic [UID:0001K8] `TimerHandler::RemovePendingTimers()` dependency.
- `CollectionPane::ResetScrollState`: rejected because the `this` object is `ScrollCollectionPane`; `CollectionPane` only constructs and consumes the child scrollbar.
- `ScrollBar::ResetScrollState`: rejected for this exact body. The broader source file may later fold into `ScrollBar.cpp`, but the direct semantic method owner is the class [UID:0000CG].
- `TimerHandler` / `TimerMgr` ownership: rejected because `0x00597600` is an outgoing dependency reached through `this+0xa4`, not the owner of the reset helper.

### Field And Helper Names

Recommended source-facing fields and helpers:

| Binary evidence | Recommended source model | Rationale |
| --- | --- | --- |
| `this+0xa4` | `TimerHandler` / update-handler base view | Constructor installs the tertiary vtable at `+0xa4`; reset calls `TimerHandler::RemovePendingTimers()` through this adjusted view. |
| `this+0x103` | `char m_highlightPart` | Old highlighted/hovered scrollbar part; reset reads it, invalidates its rectangle if valid, then clears it. |
| `this+0x104` | `char m_activePart` | Active/pressed/tracking scrollbar part; reset clears it unconditionally. |
| `0xff` byte | no-part sentinel, represented as `-1` in source C++ | Accepted sibling reset helpers use `-1`; byte-level docs should still record `0xff`. |
| `0x00562bf0` | `ScrollCollectionPane::GetPartRect(char part, RectBounds *outRect)` | The target pushes old part and stack rect, then calls the class-local geometry helper with `ecx=this`. |
| vtable slot `+0x20` | `InvalidateRect(&rect)` | Same pane invalidation virtual used by sibling scroll helpers. |
| `0x00597600` | `TimerHandler::RemovePendingTimers()` | [UID:0001K8] already documents the generic timer-handler remove wrapper. |

### Ownership And Source Placement

Direct owner/emitter should remain [UID:0000CG] `ScrollCollectionPane`. The helper touches only class-local fields, calls the class-local part-rectangle helper, invalidates through the pane vtable on the same object, and uses the class's `+0xa4` timer view. [UID:0000NG] remains the current source-file route, with the documented broader caveat that a later scrollbar-family pass could fold the file into [UID:0000NF] `ScrollBar.cpp`.

Do not reroute this helper directly to [UID:0000NG] or [UID:0000NF]. `EMITTER_UIDS:0000CG` is the narrower correct route; the class already emits through the file page.

### Split And Range

No split is needed.

- `0x005631fd-0x00563200`: three `0xcc` bytes after [UID:0001GX].
- `0x00563200-0x0056325c`: one complete raw helper body.
- `0x0056325b`: final `retn`.
- `0x0056325c-0x00563260`: four `0xcc` bytes.
- `0x00563260`: next modeled function `sub_563260`, the `ScrollInventoryPane` constructor.

The old aggregate endpoint issue is already repaired in [UID:0001GT]. The remaining target issue is source-quality naming and final-C++ readiness, not range repair.

### C++ Readiness

The old `95/95` blocker is obsolete. Active `by-structure.md` allows reconstruction C++ when the item is `RECONSTRUCTABLE:TRUE`, has a nonblank emitter route that surfaces to a generated source file, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided the names, boundaries, dependencies, source placement, and helper roles are sufficiently documented.

[UID:0001GY] meets that gate after this report's recommended `87/90` source-quality update. The raw no-route caveat remains a score cap and IDA-maintenance blocker, but the body is bounded and short enough for formal first-draft C++.

## Recommended Target Changes

1. Rename the target file to `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`.
2. Retitle the page to `# 0x00563200-0x0056325c ScrollCollectionPane ResetScrollState Raw`.
3. Update metadata to `87/90`, keeping owner/emitter/reconstructable as `0000CG`, `TRUE`, `0000CG`.
4. Replace the item summary with a concise source-facing summary, for example:

```text
ScrollCollectionPane reset-state raw helper cancels pending timers, clears active/highlight parts, invalidates stale highlight rectangle, and has no direct static route.
```

5. Add a source-quality section preserving current MCP evidence, PE no-route scan results, sibling reset-helper precedent, rejected names/owners, and the active code-entry gate rationale.
6. Insert the formal C++ block from the executive recommendation.
7. Preserve historical alias text: `ClearHighlightRaw` is the previous filename/descriptive alias; rejected as too narrow, not deleted from evidence.
8. Preserve the raw no-function/no-direct-route warning and the instruction not to create an IDA function from this report.

## Recommended Support-Doc Changes

Update these direct support docs if the supervisor accepts implementation:

- [UID:0000CG] `by-class/ScrollCollectionPane.md`
  - Change the method row from `ClearHighlight` to `ResetScrollState`.
  - Record that [UID:0001GY] now emits first-draft `ScrollCollectionPane::ResetScrollState()` C++ while preserving the raw no-route caveat.
  - Keep class score `86/88` unless the supervisor wants a broader class pass; this target alone does not close the file-placement/raw-helper set enough for `90+`.

- [UID:0000NG] `by-file/ScrollCollectionPane.md`
  - Update proposed contents/source notes from `clear helpers` / clear-highlight wording to reset-state wording.
  - Keep the `ScrollBar.cpp` caveat; direct class ownership and this child C++ do not settle the final standalone-vs-merge source-file question.
  - Keep score `86/85` unless the supervisor broadens the file-level source-placement audit.

- [UID:0001GT] `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`
  - Update the covered-functions row for the terminal raw helper to `ResetScrollState`.
  - Replace text saying this child remains blank because of the old raw-helper/source-name gate with the current disposition: this exact child can emit C++, while the aggregate remains blank because exact children own method bodies and other raw children still need source-quality work.
  - Keep aggregate score `85/88` unless the supervisor wants a separate aggregate refresh.

- [UID:0001VZ] `by-type/by-struct/ScrollCollectionPaneLayout.md`
  - Promote field wording for `+0x103` to `char m_highlightPart`.
  - Promote field wording for `+0x104` to `char m_activePart`.
  - Clarify `+0xa4` as a tertiary `TimerHandler` / update-handler view used by `RemovePendingTimers()`.
  - Keep layout score `85/88`; field-name parity alone does not require a score raise.

- [UID:0001YP] `by-type/by-vtable/ScrollCollectionPaneVtables.md`
  - Add a short no-vtable-route note for [UID:0001GY]: no pointer/vtable/data route to raw reset start was found; the virtual call inside the helper is the inherited Pane invalidation slot, not a route to this helper.
  - Keep score `86/90`.

Do not edit generated files, `by-memory/-coverage-report.md`, any other `-coverage-report.md`, validator state/cache, the IDA DB, or by-project-structure files during the normal B014 implementation callback unless the supervisor explicitly broadens scope.

Out-of-scope note for supervisor: `by-project-structure/proposed-source-tree.md` still has a stale `ScrollCollectionPane` range ending at `0x0056325b`. That is outside normal B-agent implementation write scope. If the supervisor later authorizes a project-structure sync, update that line to `0x00561db0-0x0056325c` and keep the existing generic-scrollbar placement caveat.

## Score Rationale

| Field | Before | After | Rationale |
| --- | ---: | ---: | --- |
| Completion | 85 | 87 | Adds current MCP provenance, source-facing method name/signature, field/helper names, PE route scan, sibling precedent, rejected alternatives, active gate correction, and formal C++ for the exact raw body. Completion remains below `90` because no static caller route is proven and adjacent raw helpers still need source-quality C++ passes. |
| Confidence | 88 | 90 | Current IDA MCP, raw disassembly, byte boundaries, no-route scan, positive controls, TimerHandler wrapper docs, and accepted sibling reset helpers all agree. Confidence stays well below final-audit range because IDA still has no function object, no caller/table/vtable route, and the final source-file merge question remains open. |

## Remaining Blockers

- No direct caller, pointer table, vtable slot, RVA literal, VA literal, or external direct branch route to `0x00563200` was found.
- IDA function creation, IDA rename/type application, and live-caller claims remain unsafe from this report alone.
- Exact original method spelling is not symbol-proven. `ResetScrollState` is a high-confidence source-facing reconstruction based on body semantics and accepted sibling naming.
- Final physical source-file placement remains `ScrollCollectionPane.cpp` versus possible `ScrollBar.cpp` fold. This does not block direct class ownership or target C++ emission.
- Other ScrollCollectionPane raw helpers, especially [UID:0003MX] and [UID:0003MY], still have blank C++ and source-name caveats. This report does not attempt to solve those separate helper bodies.

## Validation Commands Expected After Implementation

Run validators only after accepted by-* edits under a supervisor implementation callback. Suggested working directory:

> Executable block R001 was removed from this report and preserved verbatim in [0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality-removed.md](0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Suggested scoped commands:

> Executable block R002 was removed from this report and preserved verbatim in [0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality-removed.md](0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the final validator command, verify generated freshness only by reading validator-owned headers, not by hand-editing generated files:

- `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`

## Implementation Tracking Checklist

- [x] Lease only the target/support by-* files immediately before editing; release leases immediately after the edit/validator batch.
  - Proof: `python leaser.py B014 lease ...` from `tools/leaser` returned `Success` for the six edited by-* files: the original target path, `by-class/ScrollCollectionPane.md`, `by-file/ScrollCollectionPane.md`, `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`, `by-type/by-struct/ScrollCollectionPaneLayout.md`, and `by-type/by-vtable/ScrollCollectionPaneVtables.md`.
  - Release proof: `python leaser.py B014 unlease` exited `0` and reported `B014: No active leases`; `tools/leaser/Agents/current_leases.md` readback after release shows `No active leases`.
- [x] Rename [UID:0001GY] to `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`.
  - Proof: target validator command `000000001211` recorded `path_update 0001GY ... was by-memory/0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw.md`; post-validation readback confirms the new file exists and the old file is absent.
- [x] Update target title, summary, score, and source-quality text as recommended.
  - Proof: post-validation target readback shows `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CG`, `EMITTER_UIDS:0000CG`, title `0x00563200-0x0056325c ScrollCollectionPane ResetScrollState Raw`, and item summary `ScrollCollectionPane reset-state raw helper cancels pending timers, clears active/highlight parts, invalidates stale highlight rectangle, and has no direct static route.`
- [x] Insert the formal `ScrollCollectionPane::ResetScrollState()` C++ block exactly in the target `RECONSTRUCTION_CPP CODE` block.
  - Proof: post-validation target readback shows the accepted block between `RECONSTRUCTION_CPP CODE:BEGIN` and `END`; generated `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` also contains the same UID/path and method body.
- [x] Preserve historical `ClearHighlightRaw` alias/rejected-name evidence and no-function/no-static-route caveat.
  - Proof: target `Source-Quality And Reconstruction Notes` retains `ClearHighlightRaw` as historical alias and rejects it as too narrow; class notes preserve the same alias/rejection and no IDA function/live-caller caveat.
- [x] Preserve current MCP evidence: session `80de0a67`, no modeled function at `0x00563200`, exact bytes/padding, 32 ownerless instructions, decompile/callees no-function failures, and outgoing raw callsites.
  - Proof: target `IDA MCP Evidence` records endpoint/session/IDB/input, no modeled function, exact bytes/padding, 32 ownerless instructions, `decompile`/`callees` no-function failures, and outgoing raw callsites to `0x00597600`, `0x00562bf0`, inherited invalidation slot `+0x20`, and stack-cookie check.
- [x] Preserve PE route-scan evidence: no VA/RVA/start/end/interior pointer hits, no direct branch/call to raw start, only internal branch `0x0056322d -> 0x0056324d`, positive controls at `0x00563236 -> 0x00562bf0` and `0x00563219 -> 0x00597600`.
  - Proof: target `PE Route-Scan Evidence` records the executable SHA-256, imagebase, `.text` span, all no-route findings, internal branch, and positive controls; class and aggregate support docs preserve the same no-route result in shorter form.
- [x] Update [UID:0000CG] `ScrollCollectionPane` class method table and source-quality notes for `ResetScrollState`.
  - Proof: `by-class/ScrollCollectionPane.md` method table now lists `ResetScrollState`, links [UID:0001GY] at the new path, records `87/90`, formal child C++ emission, historical alias rejection, MCP evidence, PE route-scan evidence, and unchanged file-placement caveat.
- [x] Update [UID:0000NG] `ScrollCollectionPane` file page source notes without resolving the broader `ScrollBar.cpp` caveat.
  - Proof: `by-file/ScrollCollectionPane.md` now names `ScrollCollectionPane::ResetScrollState()`, adds [UID:0001GY] to proposed contents, and explicitly preserves the unresolved standalone `ScrollCollectionPane.cpp` versus possible `ScrollBar.cpp` migration caveat.
- [x] Update [UID:0001GT] aggregate covered-functions row and C++ policy text so it no longer contradicts the target child emission.
  - Proof: `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md` now links [UID:0001GY] at the reset-state path, says the exact child owns the formal `ScrollCollectionPane::ResetScrollState()` body, and leaves aggregate C++ blank only to avoid duplicating child method bodies.
- [x] Update [UID:0001VZ] layout page field names for `+0xa4`, `+0x103`, and `+0x104`.
  - Proof: `by-type/by-struct/ScrollCollectionPaneLayout.md` now documents `+0xa4` as tertiary `TimerHandler` / update-handler view, `+0x103` as `char m_highlightPart`, and `+0x104` as `char m_activePart`, with ResetScrollState evidence.
- [x] Update [UID:0001YP] vtable page with the no-vtable-route note for this raw reset helper.
  - Proof: `by-type/by-vtable/ScrollCollectionPaneVtables.md` now states that no pointer/vtable/data/direct-branch route to `0x00563200` was found, and that the helper's internal slot `+0x20` call is inherited pane invalidation, not a route to the helper.
- [x] Do not edit generated files, project-level generated reports, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, any other `-coverage-report.md`, or by-project-structure files unless explicitly reauthorized by the supervisor.
  - Proof: no manual edits were made to generated files, project-level files, validator state/cache, IDA DB, by-project-structure files, or coverage-report files. Validator commands with `--apply` produced expected tool-owned side effects in generated/project-level outputs and validator registry state. The scoped validator also auto-normalized stale UID links in `by-memory/-coverage-report.md` for [UID:0001GY]/[UID:0001GT]; I did not manually edit that supervisor-owned legacy row or repair its stale score/summary.
- [x] Run the scoped validators listed above and record command id, timestamp, exit code, ok count, generated-refresh state, and generated-header freshness.
  - `python .\tools\validator.py --mode file --file by-memory\0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md --apply --queue-timeout 240`: command `000000001211`, timestamp `2026-06-25T04:33:13-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`, refresh command `000000001211`.
  - `python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --queue-timeout 240`: command `000000001214`, timestamp `2026-06-25T04:33:34-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`, refresh command `000000001214`.
  - `python .\tools\validator.py --mode file --file by-file\ScrollCollectionPane.md --apply --queue-timeout 240`: command `000000001215`, timestamp `2026-06-25T04:33:41-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`, refresh command `000000001215`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00561db0-0x0056325c.ScrollCollectionPane.md --apply --queue-timeout 240`: command `000000001217`, timestamp `2026-06-25T04:33:48-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`, refresh command `000000001217`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\ScrollCollectionPaneLayout.md --apply --queue-timeout 240`: command `000000001219`, timestamp `2026-06-25T04:33:58-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`, refresh command `000000001219`.
  - `python .\tools\validator.py --mode file --file by-type\by-vtable\ScrollCollectionPaneVtables.md --apply --queue-timeout 240 --wait-generated`: command `000000001220`, timestamp `2026-06-25T04:34:04-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, refresh command `000000001220`.
  - Known warnings/side effects: stale missing registry/coverage rows and missing raw-child UIDs remain unrelated; validators updated projected stats, generated metadata, and UID reference indexes as tool-owned side effects.
- [x] Re-read the target header, C++ block, and generated `ScrollCollectionPane.cpp` marker/body after validation to confirm the rename, score, summary, route, and C++ block persisted.
  - Target proof: post-validation readback shows UID `0001GY`, `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`, nonblank summary, reset-state title, and exact accepted C++ block.
  - Generated C++ proof: `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` header is `validator-command-id: 000000001219`, `validator-refreshed-at: 2026-06-25T04:33:58-04:00`, which is newer than the target source validator command `000000001211`; it contains `// UID:0001GY | by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md | Completion:87 | Confidence:90` and the accepted `ScrollCollectionPane::ResetScrollState()` body.
  - Generated coverage/tracker proof: `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-coverage-report-by-memory.md` headers are at command `000000001217` and list [UID:0001GY] as coded/emits_code true at the reset-state path; `auto-generated/-ag-research-tracker.md` header is command `000000001219` and lists [UID:0001GY] as `87/90`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md","timestamp":"2026-06-25T04:37:38","uid":"0001GY"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
