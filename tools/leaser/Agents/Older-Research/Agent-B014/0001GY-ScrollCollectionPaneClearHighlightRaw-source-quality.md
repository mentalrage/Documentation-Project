** TARGET-REPORT-UID:0001GY **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0001GY ScrollCollectionPane ResetScrollState Raw Backlog Clearance

Agent: Agent-B014
Original assignment: B014-report-0001GY-scroll-collection-pane-clear-highlight-raw-20260625
Original assignment target: [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw.md`
Current target path: [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`
Backlog clearance recheck: 2026-07-02

## Supervisor Disposition / Current Status

This loose report is a duplicate historical lead, not an active unexecuted report.

Current status classification: already implemented and centrally executed. It is not report-only pending supervisor validation, not implementation-callback-ready, not already-implemented-but-unexecuted, and not incomplete for target/support incorporation.

The accepted implementation lives at:

`executed-b-agent-research/B014/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md`

The validator-owned executed-report history in that central report records command `000000004165`, timestamp `2026-06-25T04:37:38`, source path `tools/leaser/Agents/Agent-B014/research/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md`, destination path `executed-b-agent-research/B014/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md`, and UID `0001GY`.

Do not execute this loose report a second time unless the supervisor gives a validator lifecycle repair instruction for this exact duplicate/orphan state. The current task reopens the file only to make the loose report self-auditing and clear for backlog clearance.

## Current Target State

| Field | Current value |
| --- | --- |
| UID | `0001GY` |
| Current by-memory path | `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md` |
| Title | `0x00563200-0x0056325c ScrollCollectionPane ResetScrollState Raw` |
| `COMPLETION` / `CONFIDENCE` | `87` / `90` |
| `CANONICAL_OWNER` | `0000CG` / `ScrollCollectionPane` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000CG` |
| Formal C++ | populated with `void ScrollCollectionPane::ResetScrollState()` |
| Generated C++ route | `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` |
| Liveness caveat | no IDA function object and no static route/xref found for raw start `0x00563200` |
| Historical alias | `ScrollCollectionPaneClearHighlightRaw` / `ClearHighlightRaw`, rejected as too narrow |

## Evidence Checked

Assignment and workflow inputs:

- `tools/leaser/Agents/Agent-B014/goal.md`: Agent-B014 is idle; no current target assignment is active. The prior [UID:0001OF] work is separately executed.
- `tools/leaser/Agents/Agent-B014/notes.md`: no active notes.
- Project-level `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `supervisor-rule26-review-and-incorporation-standard.md`, `score-blocker-audit-standard.md`, and `b-agent-report-template.md`.
- `by-structure.md` current ownership/emitter/C++ gate, by-memory role, generated-file, and MCP discipline sections.

Current target/support docs:

- [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`
- [UID:0000CG] `by-class/ScrollCollectionPane.md`
- [UID:0000NG] `by-file/ScrollCollectionPane.md`
- [UID:0001GT] `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`
- [UID:0001VZ] `by-type/by-struct/ScrollCollectionPaneLayout.md`
- [UID:0001YP] `by-type/by-vtable/ScrollCollectionPaneVtables.md`
- Read-only support context: `by-project-structure/proposed-source-tree.md`

Generated artifacts read as evidence only:

- `auto-generated/-ag-research-tracker.md`: row 4193 lists UID `0001GY` at `87/90`, report count `1`, author `B014`, target path `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`, and central executed report path.
- `auto-generated/-ag-memory-coverage.md`: row 1348 lists UID `0001GY` as `coded`, owner/emitter `0000CG`, and generated source `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp`.
- `auto-generated/-ag-coverage-report-by-memory.md`: row 2088 lists UID `0001GY` as `emits_code:true`, reconstructable, `87%`, very-strong, updated `2026-06-25 04:33:14`.
- `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp`: header `validator-command-id: 000000004212`, `validator-refreshed-at: 2026-07-02T04:46:07-04:00`, and UID `0001GY` body for `ScrollCollectionPane::ResetScrollState()`.

Old report search terms used before finalizing this backlog recheck:

- `0001GY`
- `0x00563200`
- `0x0056325c`
- `ScrollCollectionPaneResetScrollStateRaw`
- `ScrollCollectionPaneClearHighlightRaw`
- `ResetScrollState`

Relevant matches were the central executed B014 report, executed reports that reference this accepted C++/field precedent, and supervisor triage rows stating that B014 `0001GY` is duplicate/orphan historical lead material because central executed coverage already exists.

## Current IDA MCP Recheck

IDA MCP was available and used read-only on 2026-07-02.

| Field | Value |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Active session | `supervisor_resume_20260629` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Input path | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Imagebase | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready, size `2067` |

Read-only calls and results:

| Check | Result |
| --- | --- |
| `idb_list` | one active worker session, `supervisor_resume_20260629`, not analyzing |
| `tools/list` | schema includes `server_health`, `lookup_funcs`, `get_bytes`, `disasm`, `xrefs_to`, `xref_query`, `decompile`, and other inspection tools |
| `server_health` | `status:"ok"` |
| `lookup_funcs` for `0x005631fd`, `0x00563200`, `0x0056325b`, `0x0056325c` | all `Not a function` |
| `lookup_funcs 0x00563260` | `sub_563260`, size `0xa1` |
| `lookup_funcs 0x00562bf0` | `sub_562BF0`, size `0x287` |
| `lookup_funcs 0x00597600` | `sub_597600`, size `0xd` |
| `get_bytes 0x005631fd size 3` | `cc cc cc` pre-body padding |
| `get_bytes 0x00563200 size 16` | `55 8b ec 83 ec 14 ...` normal prologue/cookie setup |
| `get_bytes 0x0056325b size 5` | `c3 cc cc cc cc`, proving `0x0056325b` is `retn` and `0x0056325c` starts padding |
| `xrefs_to 0x00563200` / `xrefs_to 0x0056325c` | zero xrefs |
| `xref_query` to `0x00563200` | total `0`, no cross-references |
| `decompile 0x00563200` | failed because there is no modeled function at `0x563200` |
| `disasm 0x00563200`, max 50 instructions | renders `<no function>`, the 32-instruction raw helper body, `align 10h`, and successor `sub_563260` |

Current disassembly still matches the accepted report:

- `0x00563213`: `lea ecx, [esi+0A4h]`
- `0x00563219`: `call sub_597600`
- `0x0056321e`: `mov al, [esi+103h]`
- `0x00563224`: `mov byte ptr [esi+104h], 0FFh`
- `0x0056322d`: conditional skip to `0x0056324d`
- `0x00563236`: `call sub_562BF0`
- `0x00563243`: `call dword ptr [eax+20h]`
- `0x00563246`: `mov byte ptr [esi+103h], 0FFh`
- `0x00563253`: `call @__security_check_cookie@4`
- `0x0056325b`: `retn`

## Heuristic / Inference Reanalysis And Validation

### Function Shape, Range, And Split

The range remains one complete source-authored raw helper:

- `0x005631fd-0x00563200`: three bytes of `0xcc` alignment padding.
- `0x00563200-0x0056325c`: one stack-cookie protected helper body.
- `0x0056325b`: final `retn`.
- `0x0056325c-0x00563260`: four bytes of `0xcc` padding.
- `0x00563260`: successor modeled function `sub_563260`.

No split, merge, child creation, range rename, or padding repair is currently needed for UID `0001GY`. The parent aggregate is already at the correct exclusive end `0x0056325c`.

### Behavior And Source Name

The accepted source-facing method name remains `ScrollCollectionPane::ResetScrollState()`.

Positive behavior evidence:

- the helper cancels pending timer/update work through the `this+0xa4` timer/update handler view;
- reads old highlighted part byte `this+0x103`;
- clears active part byte `this+0x104` to byte sentinel `0xff`, represented as `-1` in source;
- if an old highlight was present, calls `ScrollCollectionPane::GetPartRect(char, RectBounds*)`, invalidates the old rectangle through inherited pane virtual slot `+0x20`, then clears `m_highlightPart`;
- sibling reset-state helpers already support `ResetScrollState` naming for this cleanup pattern.

Rejected alternatives remain closed:

| Candidate | Current disposition |
| --- | --- |
| `ClearHighlightRaw` / `ClearHighlight` | Historical alias only. It is too narrow because the helper also removes timers and clears active part state. |
| `StopTimer` / `RemovePendingTimers` | Too narrow and collides with the generic timer-handler dependency at `0x00597600`. |
| `TimerHandler` / `TimerMgr` ownership | Rejected because timer removal is an outgoing call through `this+0xa4`, not the target's owner. |
| `CollectionPane::ResetScrollState` | Rejected because the touched layout and helper calls are `ScrollCollectionPane`-specific. |
| `ScrollBar::ResetScrollState` | Physical family context only; direct semantic owner remains `ScrollCollectionPane`. |
| no-owner/non-emitting raw helper | Rejected because class ownership, range, behavior, and emitter route are strong despite the no-static-route caveat. |

### Ownership, Emitter, And Source Placement

Accepted direct owner/emitter remains [UID:0000CG] `ScrollCollectionPane`.

Rationale:

- the helper reads/writes `ScrollCollectionPane` part-state fields at `+0x103/+0x104`;
- it calls the class-local geometry helper `0x00562bf0`;
- it invalidates through the inherited pane virtual on the same object;
- it uses the class's timer/update subobject view at `+0xa4`;
- the class page, file page, aggregate page, layout page, and vtable page now preserve the same evidence.

[UID:0000NG] `ScrollCollectionPane` remains the source-file route. The broader `ScrollCollectionPane.cpp` versus possible `ScrollBar.cpp` consolidation caveat remains a file-family placement issue, not a blocker to this exact child owner/emitter route.

### Field, Type, And Helper Vocabulary

The current target/support docs already preserve the accepted vocabulary:

| Binary evidence | Accepted source-facing interpretation |
| --- | --- |
| `this+0xa4` | tertiary `TimerHandler` / update-handler view used for `RemovePendingTimers()` |
| `this+0x103` | `char m_highlightPart` |
| `this+0x104` | `char m_activePart` |
| byte `0xff` | no-part sentinel, source `-1` |
| `0x00562bf0` | `ScrollCollectionPane::GetPartRect(char part, RectBounds *outRect)` |
| vtable slot `+0x20` | inherited pane `InvalidateRect(&rect)` |
| stack local at `ebp-0x14` | `RectBounds rect` |

No placeholder/generator name blocker remains for this target. Exact original spelling is still not symbol-proven, but the source-facing names are the best supported reconstruction and are implemented consistently in the target/support docs and generated C++.

### Liveness / Static Route

The no-static-route question is closed as an evidence-backed residual caveat, not an open blocker:

- current MCP xrefs to `0x00563200` and `0x0056325c` remain empty;
- current `xref_query` to `0x00563200` returns total `0`;
- current `decompile` fails because no function is modeled;
- the central accepted report's local PE scan found no VA/RVA/start/end/interior pointer hit and no direct call/jump/branch to the raw start, with positive controls for the outgoing callsites;
- the target, class, aggregate, and vtable docs preserve this no-function/no-route caveat.

This means no live caller, IDA function creation, IDA rename/type application, or recovered original symbol claim should be made from this report. It does not block current reconstruction C++ because the method body is exact, bounded, source-authored, owned, emitted, and above the current combined-score gate.

## First-Draft C++ / Applied Proof

UID `0001GY` is eligible for formal C++ under current `by-structure.md` rules because it is reconstructable, has a nonblank emitter route through [UID:0000CG], surfaces to a by-file source root, and has `(87 + 90) / 2 = 88.5`.

The formal target block is already populated:

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

Generated-output proof: `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` currently contains the UID `0001GY` marker for `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`, `Completion:87`, `Confidence:90`, and the same method body. The generated file header is validator-owned and current at command `000000004212`, refreshed `2026-07-02T04:46:07-04:00`.

## Score And Metadata Disposition

| Field | Historical pre-implementation state | Current accepted state |
| --- | --- | --- |
| Filename/title | `ScrollCollectionPaneClearHighlightRaw` | `ScrollCollectionPaneResetScrollStateRaw` |
| Completion | `85` | `87` |
| Confidence | `88` | `90` |
| Owner | `0000CG` | `0000CG` |
| Reconstructable | `TRUE` | `TRUE` |
| Emitters | `0000CG` | `0000CG` |
| C++ | blank under stale raw-helper/source-name gate | formal `ResetScrollState()` block populated |

Score rationale remains valid:

- Completion improved because source name, behavior, exact boundary, field/helper names, rejected alternatives, liveness caveat, active C++ gate, and formal C++ are documented.
- Confidence improved because current and accepted MCP evidence, exact bytes, raw disassembly, no-route checks, helper roles, support docs, and sibling precedent agree.
- Score stays below final-audit range because no static caller route or IDA function object is known, exact original spelling is inferred, and final file-family placement is still not symbol-proven.

No skipped score/source-quality blocker remains for this target. Each named blocker is either resolved, implemented, or preserved as an evidence-backed caveat with score/C++ impact.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | This loose report is duplicate/orphan historical lead material and should not be executed again absent validator lifecycle repair direction. | High | Central executed report exists; tracker row 4193 records report count `1`, author `B014`, central path; supervisor triage rows say B014 `0001GY` is duplicate/orphan. | This loose report, `Supervisor Disposition / Current Status` | already-present | already-present |
| C02 | UID `0001GY` current path/name is `ScrollCollectionPaneResetScrollStateRaw`, not the original `ClearHighlightRaw` assignment path. | High | Current target file exists; old path absent from active target docs; tracker and generated coverage use reset-state path. | Target by-memory title/path; generated tracker path | already-present | already-present |
| C03 | Metadata is `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`. | High | Target header and generated tracker/coverage rows. | Target metadata header | already-present | already-present |
| C04 | The formal target C++ block emits `void ScrollCollectionPane::ResetScrollState()` with `RectBounds rect`, `char oldPart`, timer removal, active/highlight clearing, old-highlight invalidation, and no extra behavior. | High | Target C++ block and generated `ScrollCollectionPane.cpp` UID marker/body. | Target `RECONSTRUCTION_CPP CODE`; generated C++ via validator | already-present | already-present |
| C05 | IDA still has no function object at `0x00563200`; `0x0056325b` is `retn`; `0x0056325c` starts padding; successor `sub_563260` starts at `0x00563260`. | High | 2026-07-02 live MCP `lookup_funcs`, `get_bytes`, `disasm`; accepted report evidence. | Target `IDA MCP Evidence`; aggregate boundary notes | already-present | already-present |
| C06 | No direct static route to raw start `0x00563200` is known, so no live caller, IDA function creation, or IDA rename/type claim should be made. | High | 2026-07-02 MCP `xrefs_to`/`xref_query` total `0`; accepted report PE route scan; current support docs. | Target/source-quality notes; class/vtable caveats | already-present | already-present |
| C07 | `ClearHighlightRaw` is historical search alias only and is rejected as final source name because the helper also cancels timers and clears active part. | High | Raw instructions and target/class notes. | Target source-quality notes; class notes | already-present | already-present |
| C08 | Direct owner/emitter is [UID:0000CG] `ScrollCollectionPane`; `TimerHandler`, `CollectionPane`, `ScrollBar`, and no-owner/non-emitting alternatives are rejected for direct ownership. | High | Field offsets, helper calls, class/file/layout/vtable docs, accepted report. | Target owner metadata and source-quality notes; class/file support docs | already-present | already-present |
| C09 | Support docs preserve report-level details: class method row, file proposed contents, aggregate child row/C++ policy, layout field names, and vtable no-route note. | High | Current `rg` checks across five support docs. | `by-class`, `by-file`, aggregate `by-memory`, layout, and vtable docs | already-present | already-present |
| C10 | Generated artifacts are read-only proof and must not be manually edited by B014. | High | Workflow rules; generated file headers; current user instruction. | This report and final checkpoint | not-applicable | excluded-with-reason |
| C11 | `by-project-structure/proposed-source-tree.md` still has a stale `ScrollCollectionPane` range ending at `0x0056325b`; B014 did not edit it because normal B-agent callback scope excludes by-project-structure without explicit authorization. | Medium-high | `rg` shows line 1902 with `0x00561db0-0x0056325b`; current aggregate/target prove exclusive end should be `0x0056325c`. | This report `Supervisor Follow-Up` | incorporate | excluded-with-reason |

## Recommended Target / Support Doc State

No by-* implementation callback is pending for UID `0001GY`; accepted details are already present at same-or-greater detail.

Already-present target/support state:

- Target `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`: current path/title, `87/90`, owner/emitter `0000CG`, formal C++ body, exact boundary, IDA no-function evidence, no-static-route caveat, PE route-scan evidence, rejected alias/name/owner alternatives.
- `by-class/ScrollCollectionPane.md`: method row uses `ResetScrollState`, links UID `0001GY`, records raw no-function/no-route caveat, C++ emission, field names, and rejected `ClearHighlightRaw` alias.
- `by-file/ScrollCollectionPane.md`: proposed contents include `ScrollCollectionPane::ResetScrollState()` and preserve the unresolved `ScrollCollectionPane.cpp` versus possible `ScrollBar.cpp` placement caveat.
- `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`: aggregate row links the reset-state child and leaves aggregate C++ blank only to avoid duplicating exact child method bodies.
- `by-type/by-struct/ScrollCollectionPaneLayout.md`: `+0xa4`, `+0x103`, and `+0x104` preserve the accepted timer-handler, `m_highlightPart`, and `m_activePart` interpretations.
- `by-type/by-vtable/ScrollCollectionPaneVtables.md`: records that no pointer/vtable/data/direct-branch route to `0x00563200` was found and that the helper's internal `+0x20` call is inherited invalidation, not a route to the helper.

Supervisor-owned optional support sync:

- `by-project-structure/proposed-source-tree.md` line 1902 still says `ScrollCollectionPane` owns a scrollbar family at `0x00561db0-0x0056325b`. If a supervisor authorizes a project-structure sync, change that range to `0x00561db0-0x0056325c` and keep the existing generic-scrollbar placement caveat. B014 did not edit by-project-structure in this backlog pass.

## Open Questions With Attempted Resolution

1. Static route / runtime liveness:
   - Resolution: evidence-backed caveat remains. Current MCP xrefs and accepted PE route scan find no route to `0x00563200`.
   - Impact: caps confidence and forbids live-caller/IDA-function claims; does not block formal C++ because the body is exact and emitted through a supported class route.

2. Exact original method spelling:
   - Resolution: no symbol/source proof found; `ResetScrollState` remains inferred but accepted.
   - Impact: confidence remains below final-audit range, but the source-facing name is better supported than any rejected alternative.

3. Physical source file family:
   - Resolution: current route remains through [UID:0000CG] to [UID:0000NG] `ScrollCollectionPane`. Broader `ScrollBar.cpp` consolidation remains a family-level question.
   - Impact: no target owner/emitter change; no C++ blocker for this exact child.

4. Stale by-project-structure range:
   - Resolution: exact correction is known (`0x00561db0-0x0056325c`), but not applied in this B-agent backlog report because by-project-structure is outside normal callback scope without explicit authorization.
   - Impact: supervisor may optionally authorize that sync; it is not a blocker to target/support by-* incorporation.

## Validator Results

No validators were run in the 2026-07-02 backlog-clearance pass because no by-* documentation, generated file, coverage report, tool state, or IDA state was edited.

Historical accepted implementation validators from the central executed report:

| Command | Command ID | Timestamp | Exit | `ok` | Generated state |
| --- | --- | --- | --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md --apply --queue-timeout 240` | `000000001211` | `2026-06-25T04:33:13-04:00` | `0` | `1` | deferred |
| `python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --queue-timeout 240` | `000000001214` | `2026-06-25T04:33:34-04:00` | `0` | `1` | deferred |
| `python .\tools\validator.py --mode file --file by-file\ScrollCollectionPane.md --apply --queue-timeout 240` | `000000001215` | `2026-06-25T04:33:41-04:00` | `0` | `1` | deferred |
| `python .\tools\validator.py --mode file --file by-memory\0x00561db0-0x0056325c.ScrollCollectionPane.md --apply --queue-timeout 240` | `000000001217` | `2026-06-25T04:33:48-04:00` | `0` | `1` | deferred |
| `python .\tools\validator.py --mode file --file by-type\by-struct\ScrollCollectionPaneLayout.md --apply --queue-timeout 240` | `000000001219` | `2026-06-25T04:33:58-04:00` | `0` | `1` | deferred |
| `python .\tools\validator.py --mode file --file by-type\by-vtable\ScrollCollectionPaneVtables.md --apply --queue-timeout 240 --wait-generated` | `000000001220` | `2026-06-25T04:34:04-04:00` | `0` | `1` | completed |

Current generated-readback proof:

- `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` is validator-owned at command `000000004212`, refreshed `2026-07-02T04:46:07-04:00`, and contains UID `0001GY` C++.
- `auto-generated/-ag-research-tracker.md` is validator-owned at command `000000004216`, refreshed `2026-07-02T04:59:58-04:00`, and points UID `0001GY` to the central executed B014 report.

## Changed Files

2026-07-02 backlog-clearance pass:

- Modified only this loose report: `tools/leaser/Agents/Agent-B014/research/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md`

No by-* docs were edited. No generated files, coverage reports, project-level generated reports, validator/tool state, queues, archives, locks, IDA DB, or by-project-structure files were edited. No leases were acquired because the only edit was in Agent-B014's own research folder.

## Implementation Tracking Checklist

Backlog clearance pass:

- [x] Preserve original target UID, `AUTHOR-AGENT-ID`, and `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`.
- [x] Preserve original assignment identity and original `ClearHighlightRaw` target path as historical assignment context.
- [x] Classify current lifecycle status: loose duplicate/orphan historical lead; already implemented and centrally executed; do not execute this loose report again without explicit validator lifecycle repair direction.
- [x] Verify the central executed report exists and records validator execution for UID `0001GY`.
- [x] Verify current target by-memory doc has `87/90`, owner/emitter `0000CG`, reconstructable `TRUE`, reset-state title/path, summary, and formal C++ body.
- [x] Verify current support docs already preserve the accepted class/file/aggregate/layout/vtable details at report-level or greater detail.
- [x] Run a current read-only IDA MCP recheck for endpoint/session/health, function lookup, bytes, xrefs, decompile failure, and disassembly around `0x00563200`.
- [x] Recheck generated tracker/coverage/C++ artifacts as read-only proof and confirm they point to the central executed report and generated body.
- [x] Add a Claim And Incorporation Ledger with every accepted/duplicate-status claim marked already-present, not-applicable, or excluded-with-reason.
- [x] Close named source-quality blockers: name, range/split, owner/emitter, field/helper vocabulary, C++ readiness, raw no-route caveat, and physical file caveat.
- [x] Record the stale `by-project-structure/proposed-source-tree.md` range as supervisor-owned optional sync, not a B014 edit in this pass.
- [x] Do not edit generated files, coverage reports, project-level generated reports, validator/tool state, queues, archives, locks, IDA DB, by-project-structure, or any by-* docs.
- [x] Do not acquire leases because no leased-scope files were edited.
- [x] Do not run validators because no by-* docs were edited during this backlog-clearance pass; preserve historical validator command IDs from the central executed report.

Remaining supervisor verification:

- [ ] Supervisor should verify that the loose report should remain preserved as duplicate historical lead material and should not be executed a second time.
- [ ] Supervisor should decide whether to authorize a separate by-project-structure sync for the stale `0x00561db0-0x0056325b` text in `by-project-structure/proposed-source-tree.md`; this is outside this B014 backlog clearance edit.
