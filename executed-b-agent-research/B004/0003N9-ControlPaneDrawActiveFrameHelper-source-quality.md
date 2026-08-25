** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003N9 ControlPaneDrawActiveFrameHelper Source-Quality Report

Current artifact state: this is the same UID0003N9 B004 report after validator-owned active revalidation clearance and the 2026-07-05 Gate 2 verification callback, not a new target report. Historical report-only research, implementation callback, correction validators, and validator-owned lifecycle history are preserved below. During Gate 2 verification, B004 verified claims C-0003N9-01 through C-0003N9-12, repaired drifted support-doc generated-state wording in `by-file/ControlPane.md`, ran scoped validators for that file, released the leases, and updated this report. B004 did not edit target/class/parent docs, generated files by hand, coverage reports, validator state by hand, lifecycle/archive files, supervisor ledgers, or IDA DB, and did not run `execute_report`.

## Finalized Report / Current Recommendation

- Target: [UID:0003N9] `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`.
- Assignment ID: `B004-report-controlpane-draw-active-frame-helper-source-quality-0003N9-mcp-20260623`.
- Current metadata after the historical B004 implementation callback: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, blank formal C++.
- Current recommendation: preserve the applied `88/89` target disposition; keep `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, and blank formal C++.
- C++ recommendation: keep formal `RECONSTRUCTION_CPP` blank with the target-specific no-code proof below. The body is exact and source-shaped, but current MCP plus local PE route scans still prove no entry route, function object, vtable/table/pointer route, or source declaration for the retained raw helper. The score can improve because the range, fields, owner, callees, and negative route evidence are now current-session audited and source-quality names can be resolved to implementation-ready descriptive names.
- Historical implementation disposition: the target page plus `by-class/ControlPane.md`, `by-file/ControlPane.md`, and the mixed aggregate `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md` were the accepted support destinations. GrafPort callee pages and ControlPane vtable pages remain support evidence only and already contain same-or-greater detail for this consumer.

## Supporting Research

- Lifecycle/status notes: the validator-owned footer records that this report was marked `needs-revalidation` for `target_uid_unknown: 0003N9`, returned from `executed-b-agent-research/B004/` to `tools/leaser/Agents/Agent-B004/research/` by validator command `000000007184` at `2026-07-05T15:40:54-04:00`, and then cleared by supervisor-owned `active-clear-revalidation` command `000000007202` at `2026-07-05T16:00:53-04:00`. The prior `REPORT-VALIDATION-STATUS`/`REPORT-REVALIDATION-REASON` header is no longer present after that validator-owned clear; B004 did not manually edit validator-owned status headers or the `VALIDATOR-REPORT-HISTORY` footer.
- Prior active-clear cleanup objective: preserve the repaired Gate 1-ready report text while removing stale body wording that described the old status header as live. That cleanup was report-text-only; the supervisor already performed the validator-owned active-clear lifecycle command, and B004 did not archive/execute the report.
- Historical report-only evidence basis: B004 used project-level `ntk-b-agent-workflow`, current IDA MCP session `80de0a67`, current by-* docs, generated `ControlPane.cpp`, PE route scans, prior B001/B002/B003 reports as leads, and support docs for ControlPane/GrafPort/vtables.
- Historical callback/validator basis: accepted B004 implementation changed the target/support by-* docs and ran scoped validators. Later supervisor-return corrections removed prose-only C++ body material from the report/docs and kept the formal target C++ block blank.
- Current read-only revalidation/final-cleanup checks: B004 re-read the assigned `goal.md`, the B-agent workflow/template references, this report artifact, current target/support docs, current generated `auto-generated/NexusTK/ui/core/ControlPane.cpp`, and current generated research-tracker rows for `0003N9`. The current report has no `REPORT-VALIDATION-STATUS` header after command `000000007202`; the current by-* docs already show the post-callback `88/89` target state; the current generated C++ read-only search shows no UID0003N9 marker/body.
- Gate 2 verification callback: B004 rechecked ledger rows C-0003N9-01 through C-0003N9-12 against current target/support docs. Target, class, mixed parent, GrafPort support, and vtable support details were already present at same-or-greater detail. `by-file/ControlPane.md` had stale generated-marker wording for UID0003N9 in the raw-helper row and historical route prose, so B004 repaired only that support prose to match current generated omission/no-body state, validated `by-file/ControlPane.md`, and released the leases.

## Target

- Target UID: `0003N9`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`.
- Exact range: `0x00494c50-0x00494c80`, half-open; size `0x30` / decimal `48` bytes (Verified with `int_convert.py`).
- Current owner/emitter: [UID:000038] `ControlPane`, which routes through [UID:0000IG] `ControlPane` at `NexusTK/ui/core/ControlPane.cpp`.
- Physical container: [UID:0002PD] `0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers`, a non-reconstructable/non-emitting mixed helper-band index.
- Current generated output: read-only search of `auto-generated/NexusTK/ui/core/ControlPane.cpp` on 2026-07-05 after the final Gate 2 by-file validator shows header `validator-command-id: 000000007224`, `validator-refreshed-at: 2026-07-05T16:20:32-04:00`, `validator-refresh-source: deferred-generated-refresh`, and no UID0003N9 marker/body/reference. This is consistent with the blank formal C++ no-code proof. Earlier historical validator notes about an empty UID0003N9 marker are preserved as history, not current generated state.

## Current Target State

The target already records a strong source-shaped raw body:

```text
0x00494c50  push esi
0x00494c51  mov esi, ecx
0x00494c53  cmp byte ptr [esi+101h], 0
0x00494c5a  jz short 0x00494c7e
0x00494c5c  cmp byte ptr [esi+102h], 0
0x00494c63  jz short 0x00494c7e
0x00494c65  push 80h
0x00494c6a  call sub_4B9660
0x00494c6f  lea eax, [esi+44h]
0x00494c72  mov byte ptr [esi+70h], 0
0x00494c76  push eax
0x00494c77  mov ecx, esi
0x00494c79  call sub_4BA450
0x00494c7e  pop esi
0x00494c7f  retn
```

Current target/support docs preserve the important historical no-owner/no-route scans, later ControlPane assignment, and the applied B004 `88/89` state. The current target header is `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, and blank formal C++ block. The still-relevant confidence caps are no function object, no xrefs/routes, no vtable/table/pointer/direct-branch route, no recovered source declaration, and exact original spelling/color-constant uncertainty.

Related docs checked:

- [UID:000038] `by-class/ControlPane.md`.
- [UID:0000IG] `by-file/ControlPane.md`.
- [UID:0002PD] `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`.
- [UID:0003N3] / [UID:0003N4] visible-state helpers over `+0x101`.
- [UID:0003N6] / [UID:0003N7] active-state helpers over `+0x102`.
- [UID:0003N8] `ButtonControlPaneActiveRefreshHelper` as the closest accepted no-route raw frame-helper analogue.
- [UID:000162] `GrafPortDrawStateAccessors`.
- [UID:000168] `GrafPortDrawRectFrame`.
- [UID:0003J8] / [UID:0003J9] ControlPane vtable data/type docs.
- `by-project-structure/proposed-source-tree.md`, generated autogen coverage, generated `ControlPane.cpp`, active B001 executed redo report, and supervisor tracker notes.

Current artifact/lifecycle status: this active report file is under B004's own `research/` folder after validator-owned active revalidation clearance. The footer records historical lifecycle return from executed research and the supervisor-owned active-clear event. B004 has not run any lifecycle command; the only current scoped validator was the Gate 2 `by-file/ControlPane.md` validator after the narrow support-doc prose repair.

## Supervisor Active Recheck

The supervisor assigned B004 to redo [UID:0003N9] under stricter Rule 26 score-blocker handling. The named blockers were the raw no-function state, no xrefs/reachability, unresolved state-byte names, draw helper names, owner/emitter, split, score, and C++ readiness. The historical B004 research pass did not use Wave2/Wave3 as authority and did not defer those blockers: each was checked against MCP session `80de0a67`, support docs, generated output, and a local section-mapped PE route scan.

## Evidence Standards Used

- Direct IDA/MCP evidence is treated as ground truth for function boundaries, bytes, disassembly, xrefs, vtable/data-cell values, callee behavior, decompilation failure, and "not a function" state. The historical B004 MCP pass followed `by-structure.md` IDA MCP Output Discipline with narrow, exact-address calls rather than broad unbounded scans.
- Local PE evidence is used as corroborating negative route evidence: section-mapped scans checked VA/RVA/raw-offset dwords and direct transfer encodings, with positive controls for neighboring routed entries so a zero-hit result is meaningful.
- Current by-* docs are treated as implementation/current-state evidence, not as proof overriding IDA. During this 2026-07-05 repair, B004 inspected the current target/support docs read-only to distinguish applied current state from historical recommendations.
- Generated `auto-generated/NexusTK/ui/core/ControlPane.cpp` and `auto-generated/-ag-research-tracker.md` are read-only generated state. They are used for current generated freshness/omission/tracker observations only; B004 did not edit them.
- Historical B001/B002/B003 reports are leads and lifecycle context. Their no-owner/no-route scans remain useful negative evidence, but their no-owner metadata is historicalized because current docs have accepted ControlPane ownership.
- `by-structure.md` reconstruction rules are applied as a confidence cap: the target is mechanically C++-eligible by score/emitter route, but formal C++ remains blank because no route/declaration evidence proves a safe source representation. Prose behavior names are allowed; emitted code must stay out of the formal block until the no-code proof changes.
- Current Gate 2 limitation: no lifecycle commands, report moves, generated/manual coverage edits, IDA DB edits, or new MCP calls were run by B004. No new MCP calls were required because the existing report already contains the necessary narrow MCP evidence; Gate 2 verification used current docs/generated state and one scoped by-file validator after a support prose repair.

## Evidence Checked

- Historical MCP checks recorded in this report: `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `entity_query`, `get_bytes`, `make_signature_for_range`, `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, `find immediate`, `decompile`, `disasm`, `insn_query`, `callees`, `get_int`, `analyze_function`, and `analyze_component` against session `80de0a67`.
- Historical byte/range checks: exact `0x00494c50-0x00494c80` helper bytes, six-byte `0xcc` pre-padding at `0x00494c4a-0x00494c50`, clean successor function at `0x00494c80`, unique signature for the `0x30`-byte range, and no IDA function object at the helper start or likely interiors.
- Historical route-negative checks: zero MCP xrefs/code refs/data refs/immediates to `0x00494c50`, `0x00494c51`, and `0x00494c53`; no selected ControlPane/ProgressBarControlPane vtable cell to the helper; zero local PE VA/RVA/raw-offset pointer hits and zero local PE direct-transfer hits to the helper start/interiors, with positive controls for `0x00494b80`, `0x00494c30`, and successor `0x00494c80`.
- Historical behavior checks: disassembly confirms the two ControlPane state-byte gates, active-frame color `0x80`, inherited bounds access at `+0x44`, inherited draw-mode clear at `+0x70`, and outgoing calls to `0x004b9660` and `0x004ba450`.
- Historical support checks: sibling ControlPane visible/active helpers over `+0x101`/`+0x102`, GrafPort draw-state and rectangle-frame docs, ControlPane vtable data/type docs, closest raw-helper analogue [UID:0003N8], proposed source-tree placement, and prior B001/B002/B003 reports.
- Current 2026-07-05 Gate 2 checks: assigned `goal.md`, project B-agent workflow/template, `by-structure.md` MCP/reconstruction rules, target doc header and body, `by-class/ControlPane.md`, `by-file/ControlPane.md`, `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`, optional GrafPort/vtable support docs, generated `auto-generated/NexusTK/ui/core/ControlPane.cpp` header/content search, generated tracker rows for `0003N9`, this report's validator-owned lifecycle footer, and scoped validator output for `by-file/ControlPane.md`.
- Current generated/lifecycle observation: before the Gate 2 support repair, `ControlPane.cpp` had `validator-command-id: 000000007143`, `validator-refreshed-at: 2026-07-05T15:10:39-04:00`, and no UID0003N9 marker/body/reference. After the final same-file support repair and validator, validator-owned generated `ControlPane.cpp` refreshed to `validator-command-id: 000000007224`, `validator-refreshed-at: 2026-07-05T16:20:32-04:00`, and still has no UID0003N9 marker/body/reference. The active report no longer carries the `needs-revalidation` status header after command `000000007202`. The tracker still lists older executed UID0003N9 reports as `needs-revalidation: target_uid_unknown: 0003N9`; those rows are historical/generated lifecycle state and are not manually repaired here.
- Intentionally skipped in this callback: `execute_report`, lifecycle/archive commands, report moves, IDA DB edits, new MCP calls, target/class/parent by-* edits, generated manual edits, coverage edits, and validator-state manual edits.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0003N9-01 | Target metadata should be `COMPLETION:88`, `CONFIDENCE:89`, with `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, and blank formal C++ preserved. | Strong | Gate 2 verified current target header shows `88/89`, owner/emitter `000038`, reconstructable true, and blank formal block; historical MCP/PE evidence supports the score move but no C++ emission. | `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md` header metadata and C++ block | already-present | already-present |
| C-0003N9-02 | The target is one exact raw helper range `0x00494c50-0x00494c80`, not padding, successor-fragment, or split candidate. | Confirmed | Gate 2 verified target `Status`, MCP-backed recheck, and history preserve exact bytes/signature, `retn` at `0x00494c7f`, six-byte pre-padding, clean successor prologue at `0x00494c80`, and no interior entry evidence. | Target `Status`, MCP-backed recheck, and range/split discussion | already-present | already-present |
| C-0003N9-03 | No route/declaration evidence currently proves safe formal emission for UID0003N9. | Strong | Gate 2 verified target no-code proof preserves no function object, no xrefs/code/data/immediate refs, no selected vtable slot, no PE pointer/direct-transfer route, and decompile/callees fail as no function. | Target no-code proof, `First-Draft C++ Recommendation`, generated C++ disposition | already-present | already-present |
| C-0003N9-04 | The best semantic owner/emitter remains [UID:000038] `ControlPane`, routed through [UID:0000IG] `ControlPane.cpp`. | Strong | Gate 2 verified target/class/file docs preserve ControlPane local visible/active state, inherited bounds/draw-mode fields, and weaker ProgressBar/Button/GrafPort/no-owner alternatives. | Target owner prose, `by-class/ControlPane.md`, `by-file/ControlPane.md`, `Ranked Ownership Analysis`, `Source Placement` | already-present | already-present |
| C-0003N9-05 | Source-facing behavior names are resolved enough for documentation: `ControlPane::DrawActiveFrame`, `m_controlVisible`, `m_controlActive`, `m_bounds`, `m_drawMode`, `GrafPort::SetDrawColor`, and `GrafPort::DrawRectFrame`. | Strong for meanings; medium for exact original spellings | Gate 2 verified target/class/file/parent/support docs preserve these source-facing behavior names and exact spelling caveats. | Target behavior/source-quality section and support doc prose | already-present | already-present |
| C-0003N9-06 | The target docs must preserve negative evidence and rejected alternatives rather than presenting the helper as source-ready emitted C++. | Strong | Gate 2 verified target/support docs preserve route-negative checks, no declaration, historical no-owner policy, rejected ProgressBar/Button/GrafPort/standalone routes, and blank/no-code generated state. | Target history/rejected alternatives, `Negative Evidence Summary`, `Open Questions With Attempted Resolution` | already-present | already-present |
| C-0003N9-07 | `by-class/ControlPane.md` should synchronize UID0003N9 at `88/89` with ControlPane route, blank C++ proof, field/callee names, and route-negative evidence. | Strong | Gate 2 verified class row and history section contain the `88/89` state, no-code proof, route-negative evidence, source names, and rejected alternatives at report-level detail. | `by-class/ControlPane.md` active-frame helper row and implementation history | already-present | already-present |
| C-0003N9-08 | `by-file/ControlPane.md` should synchronize UID0003N9 at `88/89`, keep `NexusTK/ui/core/ControlPane.cpp` as route context, and preserve no-code generated disposition. | Strong | Gate 2 found stale generated-marker wording in the raw-helper row and historical route prose, repaired `by-file/ControlPane.md` to current no-marker/no-body generated state, and validated it with final command `000000007224`; generated `ControlPane.cpp` refreshed to the same command id and still has no UID0003N9 marker/body/reference. | `by-file/ControlPane.md` raw draw-state helper row and implementation history | incorporate | applied |
| C-0003N9-09 | The mixed parent `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md` should remain non-reconstructable/non-emitting while its UID0003N9 child row carries the `88/89` raw-helper status. | Strong | Gate 2 verified parent doc shows `RECONSTRUCTABLE:FALSE`, blank emitters/C++, child row at `88/89`, no-code proof, and 2026-07-05 B015 unrelated support update. | Mixed parent child inventory and status notes | already-present | already-present |
| C-0003N9-10 | Optional GrafPort callee and ControlPane vtable support pages do not require B004 edits for this report. | Strong | Current target/support docs and prior support pages already record the `0x004b9660` consumer, `0x00494c79` raw caller, `GrafPort::DrawRectFrame`, and sibling vtable/no-slot evidence. | `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`, `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md`, `by-type/by-vtable/ControlPaneVtables.md` | already-present | already-present |
| C-0003N9-11 | Manual `by-memory/-coverage-report.md` replacement text, if still desired, is supervisor-owned and must not be applied by B004. | Strong | B-agent workflow excludes manual coverage edits; current callback rules forbid coverage/generated manual edits; historical exact row text remains supplied for supervisor use only. | `Exact Manual Supervisor-Owned Coverage Or Tracker Text` | not-applicable | excluded-with-reason |
| C-0003N9-12 | Current report repair/final cleanup must preserve validator-owned lifecycle history while fixing stale report sections and checklist/ledger defects. | Strong | Goal names validator return command `000000007184`; supervisor reports and current footer record active-clear command `000000007202`; prior active-clear cleanup changed only report text, and current Gate 2 reporting now also records the scoped `by-file/ControlPane.md` repair plus final validator `000000007224` without manual lifecycle edits. | `Supporting Research`, `Validator Results`, `Changed Files`, `Implementation Tracking Checklist`, footer | historicalize | applied |

## MCP / PE Provenance

IDA MCP:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- `idb_list`: active owned worker session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `21816`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `tools/list`: current schema requires explicit `database`; bounded read-only tools used included `lookup_funcs`, `entity_query`, `get_bytes`, `make_signature_for_range`, `xrefs_to`, `xref_query`, `find`, `decompile`, `disasm`, `insn_query`, `callees`, `get_int`, `analyze_function`, and `analyze_component`.

Local PE:

- Executable scanned: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- Image base: `0x00400000`.
- Sections from the scanned PE:
  - `.text` VA `0x00001000`, virtual `0x00401000-0x0060c600`, raw pointer `0x400`, raw size `0x20b600`, virtual size `0x20b4ac`.
  - `.rdata` VA `0x0020d000`, virtual `0x0060d000-0x0066c200`, raw pointer `0x20ba00`, raw size `0x5f200`, virtual size `0x5f0be`.
  - `.data` VA `0x0026d000`, virtual `0x0066d000-0x0069ce24`, raw pointer `0x26ac00`, raw size `0xd800`, virtual size `0x2fe24`.
  - `.rsrc` VA `0x0029d000`, virtual `0x0069d000-0x006b2e00`, raw pointer `0x278400`, raw size `0x15e00`, virtual size `0x15c38`.

## IDA MCP Facts

Function and boundary facts:

- `lookup_funcs` in current session:
  - `0x00494b50`: `sub_494B50`, size `0x27`.
  - `0x00494b80`: `sub_494B80`, size `0x2d` / decimal `45` (Verified with `int_convert.py`).
  - `0x00494bb0`: `sub_494BB0`, size `0x1a`.
  - `0x00494bd0`: `sub_494BD0`, size `0x1a`.
  - `0x00494bf0`: `sub_494BF0`, size `0x7`.
  - `0x00494c00`: `sub_494C00`, size `0x10`.
  - `0x00494c10`: `sub_494C10`, size `0x1a`.
  - `0x00494c30`: `sub_494C30`, size `0x1a`.
  - `0x00494c4a`, `0x00494c50`, `0x00494c51`, `0x00494c53`, and `0x00494c7e`: not functions.
  - `0x00494c80`: `sub_494C80`, size `0x12a`.
- `entity_query` over `0x00494b40-0x00494c90`: function starts are exactly `0x00494b50`, `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494bf0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, and `0x00494c80`; no function start exists at the raw helper.
- `get_bytes 0x00494c4a size 54`: six `0xcc` bytes followed by the complete helper bytes. `get_bytes 0x00494c80 size 16` starts with `55 8b ec 6a ff`, proving the clean successor prologue.
- `make_signature_for_range 0x00494c50-0x00494c80` with no operand wildcarding returns the full exact signature and `unique:true`:

```text
56 8B F1 80 BE 01 01 00 00 00 74 22 80 BE 02 01 00 00 00 74 19 68 80 00 00 00 E8 F1 49 02 00 8D 46 44 C6 46 70 00 50 8B CE E8 D2 57 02 00 5E C3
```

Disassembly/decompile facts:

- `insn_query 0x00494c4a-0x00494c80`: one alignment directive at `0x00494c4a`, then sixteen helper instructions, all with `fn:null`.
- `disasm 0x00494c50`: labels the range as `<no function>`, decodes the complete helper, then continues into successor `sub_494C80`.
- `decompile 0x00494c50`: `Decompilation failed at 0x494c50`.
- `callees 0x00494c50`: `No function found`. The outgoing calls to `0x004b9660` and `0x004ba450` are therefore direct disassembly/body facts rather than function-level callee facts.

Xref/route facts:

- `xref_query to 0x00494c50`: total `0`, message `No cross-references to this address`.
- `xref_query to 0x00494c51`: one local flow xref from `0x00494c50`.
- `xref_query to 0x00494c53`: one local flow xref from `0x00494c51`.
- `xref_query to 0x00494c7e`: three local xrefs from `0x00494c5a`, `0x00494c63`, and `0x00494c79`; the first two are the two early-exit branches and the last is local fall-through after the frame call.
- `xref_query to 0x00494c80`: one code xref from `0x005472d7` inside `sub_5470B0`, a positive control proving the successor constructor has a normal entry route.
- `find code_ref`: zero hits for `0x00494c50`, `0x00494c51`, and `0x00494c53`; two internal branch hits to `0x00494c7e`; one positive-control hit to successor `0x00494c80`; two positive-control hits to `0x00494c30`.
- `find data_ref`: zero hits for `0x00494c50`, `0x00494c51`, `0x00494c53`, `0x00494c7e`, and `0x00494c80`; positive-control `0x00494c30` returns vtable/table data refs including `0x00617aec`.
- `find immediate`: zero hits for the target start and plausible entries/exits `0x00494c50`, `0x00494c51`, `0x00494c53`, `0x00494c7e`, and `0x00494c80`.

Vtable/table facts:

- `get_int u32le` in current session:
  - `0x00617ad8 -> 0x00494b80` (decimal conversion verified with `int_convert.py`).
  - `0x00617adc -> 0x00494bb0`.
  - `0x00617ae0 -> 0x00494bd0`.
  - `0x00617ae4 -> 0x00494c00`.
  - `0x00617ae8 -> 0x00494c10`.
  - `0x00617aec -> 0x00494c30`.
  - `0x00617af0 -> 0x0041d690`.
  - `0x00617b30 -> 0x0064590c` marks the ProgressBarControlPane RTTI/locator boundary.
  - `0x00617b34 -> 0x0049b170`, `0x00617b9c -> 0x0049af3d`, and `0x00617bcc -> 0x0049af48` for successor ProgressBarControlPane entries.
- No selected ControlPane or ProgressBarControlPane vtable cell points to `0x00494c50`, `0x00494c51`, or `0x00494c53`.

Callee/helper facts:

- `analyze_function 0x004b9660`: one-block `int __thiscall(_DWORD *this, int)` leaf; disassembly stores `[ebp+arg_0]` into `[ecx+0x74]`, with no callees and broad draw caller fan-in. The source-facing name should be `GrafPort::SetDrawColor` / active draw-fill color setter in this context, not a text-color-only feature method. Offset `0x74` is decimal `116` (Verified with `int_convert.py`).
- `analyze_function 0x004ba450`: `sub_4BA450`, size `0xeb` / decimal `235` (Verified with `int_convert.py`), one explicit rectangle argument, draw-enabled gate at `this+0x71`, clip/intersection checks, four `unk_69B3E4` line-delta callbacks, and cursor restore. Existing [UID:000168] correctly reconstructs this as the `GrafPort::DrawRectFrame` rectangle-frame helper.
- `analyze_component` over the visible/active sibling helpers plus the two GrafPort callees shows `0x00494bb0`, `0x00494bd0`, `0x00494c10`, and `0x00494c30` as internal-only ControlPane state helpers, while `0x004b9660` and `0x004ba450` are broad interface functions.

## Local PE Route Scan

The local scan checked raw dword encodings for absolute VA, RVA, and raw file offsets plus direct `E8`/`E9`, near conditional `0F 80-8F`, short conditional `70-7F`, `EB`, `E0-E3` style transfers inside `.text`.

Pointer pattern results:

| Target | RVA | Raw offset | VA hits | RVA hits | Raw-offset hits |
| --- | --- | --- | ---: | ---: | ---: |
| `0x00494c50` | `0x00094c50` | `0x94050` | 0 | 0 | 0 |
| `0x00494c51` | `0x00094c51` | `0x94051` | 0 | 0 | 0 |
| `0x00494c53` | `0x00094c53` | `0x94053` | 0 | 0 | 0 |
| `0x00494c7e` | `0x00094c7e` | `0x9407e` | 0 | 0 | 0 |
| `0x00494c80` | `0x00094c80` | `0x94080` | 0 | 0 | 0 |
| positive `0x00494c30` | `0x00094c30` | `0x94030` | 46 | 0 | 0 |
| positive `0x00494b80` | `0x00094b80` | `0x93f80` | 43 | 0 | 0 |

Direct transfer results:

| Target | Direct hits | Meaning |
| --- | ---: | --- |
| `0x00494c50` | 0 | No direct call/jump/branch route to helper start. |
| `0x00494c51` | 0 | No direct route to plausible interior entry. |
| `0x00494c53` | 0 | No direct route to plausible first semantic instruction. |
| `0x00494c7e` | 2 | Internal early-exit branches at `0x00494c5a` and `0x00494c63`. |
| `0x00494c80` | 1 | Positive control: `0x005472d7: E8` to successor constructor. |
| `0x00494c30` | 2 | Positive control: `0x004b0b4f: E9` and `0x00580640: E9` to modeled sibling. |
| `0x00494b80` | 6 | Positive control: direct `E8` callers at `0x005006f5`, `0x00500814`, `0x0054b78d`, `0x0054b7a7`, `0x0054ba6d`, and `0x0054ba87`. |

These controls make the zero route result for `0x00494c50` meaningful rather than a broken scanner artifact.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00494c50` | MCP `xref_query` total `0`; local PE direct-transfer hits `0` | No proven external entry to the raw helper start. |
| `0x00494c51` | One local flow xref from `0x00494c50`; local PE direct-transfer hits `0` | Plausible interior entry rejected; only sequential flow from helper prologue. |
| `0x00494c53` | One local flow xref from `0x00494c51`; local PE direct-transfer hits `0` | Plausible first semantic instruction is not externally targeted. |
| `0x00494c7e` | Internal branch/fall-through refs from `0x00494c5a`, `0x00494c63`, and `0x00494c79` | Shared local epilogue only, not an external callable entry. |
| `0x00494c80` | Positive-control code xref from `0x005472d7` | Successor `ProgressBarControlPane` constructor has a normal route; the target boundary is clean. |
| `0x00494c30` | Positive-control direct routes at `0x004b0b4f` and `0x00580640`; vtable/table refs including `0x00617aec` | Neighboring ControlPane state helper has route evidence, proving the scanner/MCP checks can find routed siblings. |
| `0x00494b80` | Positive-control direct callers at `0x005006f5`, `0x00500814`, `0x0054b78d`, `0x0054b7a7`, `0x0054ba6d`, and `0x0054ba87` | Earlier ControlPane helper has normal direct-call evidence; zero routes for UID0003N9 are meaningful. |
| `0x004b9660` | Outgoing call observed in raw disassembly at `0x00494c6a` | Draw-color setter dependency; proves behavior, not owner. |
| `0x004ba450` | Outgoing call observed in raw disassembly at `0x00494c79` | Rectangle-frame draw dependency; proves behavior, not owner. |

## Documentation Evidence And IDA Status

- Current target doc status: `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md` currently has `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, and blank formal C++.
- Current support doc status: `by-class/ControlPane.md`, `by-file/ControlPane.md`, and `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md` already carry B004 evidence for the raw helper, its ControlPane route, the blank-C++ proof, and the `88/89` child state.
- Current generated C++ status: `auto-generated/NexusTK/ui/core/ControlPane.cpp` is generated from by-file UID `0000IG` with command id `000000007224` at `2026-07-05T16:20:32-04:00`; read-only search found no UID0003N9 marker/body/reference. The file itself refreshed during the final Gate 2 by-file validator, and the UID0003N9 omission is a target-specific generated state, not an unreadable file.
- Current generated tracker status: `auto-generated/-ag-research-tracker.md` still lists older executed UID0003N9 reports under `needs-revalidation: target_uid_unknown: 0003N9`. Those rows are validator-owned lifecycle state and are not repaired manually in this report-only pass.
- IDA status from historical B004 evidence: no IDA function object at the target start or plausible interiors, no decompilation/callee listing because no function object exists, exact raw bytes decode correctly as code, and all route checks remain negative except internal helper flow.
- Stale documentation assumptions now historicalized: older no-owner/no-emitter recommendations remain useful route-negative history, but they no longer override the current accepted ControlPane owner/emitter metadata. Older report text that treated blank C++ as unresolved source placement is historical; the current disposition is an explicit no-code proof.

## Behavior And Source-Quality Names

Confirmed behavior:

- Receiver is in `ECX` and copied to `ESI`.
- If byte `this+0x101` is zero, the helper returns.
- If byte `this+0x102` is zero, the helper returns.
- If both are nonzero, it uses `GrafPort::SetDrawColor` with color index `0x80`, decimal `128` (Verified with `int_convert.py`).
- It takes the inherited rectangle at `this+0x44` (`0x44` / decimal `68`, Verified with `int_convert.py`).
- It clears inherited draw/blit mode byte `this+0x70` (`0x70` / decimal `112`, Verified with `int_convert.py`) to mode zero.
- It draws inherited `m_bounds` through `GrafPort::DrawRectFrame` and returns.

Resolved source-facing meanings:

| Binary item | Best source-facing meaning | Evidence and rejected alternatives |
| --- | --- | --- |
| `this+0x101` | `ControlPane` local visible/shown state; best field name direction `m_controlVisible` | Paired set/clear pages [UID:0003N3]/[UID:0003N4], constructor state initialization, and this frame gate. Do not conflate with inherited `Pane` visibility byte `+0xb4`; do not call it the active byte. |
| `this+0x102` | `ControlPane` local active/focus state; best field name direction `m_controlActive` | Paired deactivate/activate pages [UID:0003N6]/[UID:0003N7], direct activation wrappers, and this frame gate. |
| `this+0x44` | inherited bounds rectangle; best field name direction `m_bounds` / `RectBounds` | Sibling state helpers invalidate the same rectangle and this helper passes it to `DrawRectFrame`. |
| `this+0x70` | inherited GrafPort draw/blit mode byte; best field name direction `m_drawMode` | Water/caustic and progress/button frame consumers also treat this as draw/blit mode. It is not a ControlPane-local boolean or text background mode. |
| `0x004b9660` | `GrafPort::SetDrawColor` / active draw-fill color setter | Current MCP decompile writes argument to `this+0x74`; broad callers and sibling frame helpers reject feature-owner/text-only names. |
| `0x004ba450` | `GrafPort::DrawRectFrame` rectangle-frame helper | Existing first-draft C++ and current MCP analysis confirm frame drawing over a rectangle. |
| helper name | best future source-facing method `ControlPane::DrawActiveFrame` | It draws the active/focus frame for a visible/active base control. `ControlPaneDrawActiveFrameHelper` is a documentation label, not likely original source spelling. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494c4a-0x00494c50` | [UID:0000VN] `by-memory/-ignored.md` | Six-byte `0xcc` alignment before raw helper | ignored | n/a | unchanged | Already correct. |
| `0x00494c50-0x00494c80` | [UID:0003N9] target | Raw active-frame drawing helper | TRUE | [UID:000038] `ControlPane` | `88/89` | Keep routed, blank C++. |
| `0x00494c80-0x00494daa` | [UID:000119] `ProgressBarControlPaneConstructor` | Successor constructor | TRUE | ProgressBarControlPane | unchanged | Separate normal function with positive code xref. |

No split or merge is recommended. The raw helper is one coherent `0x30`-byte body with only one internal epilogue target at `0x00494c7e`; no independent interior entry was found.

## Positive Evidence Summary

- MCP health/session was live and IDB-backed during the B004 evidence pass.
- Function inventory proves `0x00494c50` is a raw non-function gap between modeled `ControlPane` active-state helper `0x00494c30` and successor `ProgressBarControlPane` constructor `0x00494c80`.
- Current bytes/signature prove a unique, exact, source-shaped helper body.
- Sibling state helper pages and vtable cells prove `+0x101` and `+0x102` are base `ControlPane` local visible/active state bytes, not ProgressBar/Button state.
- Current callee analysis and support docs prove `0x004b9660` is the active draw-color setter and `0x004ba450` is `GrafPort::DrawRectFrame`.
- Existing generated output already routes [UID:0003N9] through [UID:000038] to `auto-generated/NexusTK/ui/core/ControlPane.cpp`, so owner/emitter metadata is internally consistent.
- The closest accepted analogue [UID:0003N8] is also a no-function/no-route raw frame helper with blank formal C++, yet it scores `87/88` after source-quality field/callee/route work. [UID:0003N9] is at least as well understood after this pass.

## Negative Evidence Summary

- No IDA function object at `0x00494c50` or plausible interior starts.
- No MCP xrefs to the helper start.
- No MCP code refs, data refs, or immediates to the helper start or plausible interior entries.
- No local PE absolute-VA, RVA, or raw-offset dword encodings for the helper start/interiors/exit label.
- No local PE direct `call`, `jmp`, near conditional, short conditional, `EB`, or loop/jecxz branch route to the helper start or plausible interiors.
- No selected ControlPane or ProgressBarControlPane vtable cell points to this raw helper.
- No decompilable function object, function-level callees, source/debug declaration, or original helper/field/color constant spelling was recovered.
- The two outgoing callee refs do not prove ownership; they are reusable GrafPort primitive dependencies.

## Heuristic / Inference Reanalysis And Validation

Claim: [UID:0003N9] is a full exact raw helper and not padding or a successor-fragment.

- Confidence: confirmed.
- Evidence: current MCP bytes/disassembly/signature; `retn` at `0x00494c7f`; successor prologue at `0x00494c80`; six-byte `0xcc` pre-padding.
- Counter-evidence checked: function inventory, xrefs, code/data/immediate refs, direct PE transfer scan, pointer scan, successor positive control.
- Result: keep exact range unchanged.

Claim: direct semantic owner remains `ControlPane`.

- Confidence: strong.
- Evidence: the helper consumes `ControlPane` local visible/active fields, inherited bounds, and inherited draw mode; sibling setters/clearers and vtable cells around `0x00617ad8-0x00617aec` anchor those fields to `ControlPane`; proposed source tree places `ControlPane.cpp` under `ui/core`.
- Counter-evidence checked: ProgressBar successor adjacency, Button/concrete-control analogues, GrafPort primitive dependency, no-owner historical route, vtable/table route absence.
- Result: keep [UID:000038] owner/emitter; route absence limits C++ and confidence, not ownership.

Claim: source-facing names can improve beyond raw offsets.

- Confidence: strong for meanings, medium for exact original spellings.
- Evidence: sibling helper behavior and accepted GrafPort pages support `m_controlVisible`, `m_controlActive`, `m_bounds`, `m_drawMode`, `SetDrawColor`, and `DrawRectFrame`.
- Counter-evidence checked: inherited Pane visibility byte, Button selected-state fields, `GrafPort::SetTextColor` generated pollution, ProgressBar fields, text background mode fields.
- Result: update docs to use these source-facing names as inferred/descriptive names rather than leaving blocker wording around field names.

Claim: formal C++ should still stay blank.

- Confidence: strong.
- Evidence: current same-pass route audit found no function object, no xrefs, no code/data/immediate refs, no pointer encodings, no direct control-transfer route, no vtable slot, and no source declaration. The body can be described exactly, but an emitted method would assert a callable source declaration that the binary does not currently prove.
- Counter-evidence checked: mechanical body simplicity, valid emitter route, accepted `ControlPane` owner, accepted `GrafPort::DrawRectFrame` C++ dependency, analogous raw helper [UID:0003N8].
- Result: use a target-specific blank-C++ proof. This is not deferral; it is the current source-quality disposition after all reasonable current route/name checks were exhausted.

## Ranked Ownership Analysis

### 1. [UID:000038] ControlPane

- Evidence for: `+0x101/+0x102` are ControlPane-local visible/active state bytes; siblings set/clear them; helper draws inherited bounds after setting inherited GrafPort state; current class/file/generated output route already uses `ControlPane`.
- Evidence against: no route/declaration/vtable slot to this helper.
- Decision: keep. The route gap caps confidence/C++ but does not beat the field/source-family evidence.

### 2. [UID:0000JR] / [UID:00005V] GrafPort

- Evidence for: helper calls GrafPort draw-state and frame methods and writes inherited GrafPort draw mode.
- Evidence against: the policy decision is gated by ControlPane state bytes; GrafPort owns primitives, not this control-state frame policy.
- Decision: reject as direct owner; preserve as dependency owner.

### 3. ProgressBarControlPane

- Evidence for: successor starts immediately at `0x00494c80`.
- Evidence against: clean half-open boundary, pre-padding, no progress fields, no ProgressBar vtable/pointer route to the raw helper.
- Decision: reject.

### 4. ButtonControlPane / concrete control family

- Evidence for: neighboring no-route raw frame helper [UID:0003N8] uses a similar draw-color/draw-frame idiom.
- Evidence against: [UID:0003N9] uses only base ControlPane state and no button selected/text/radio fields; exact concrete control ranges start elsewhere.
- Decision: reject.

### 5. `CANONICAL_OWNER:NONE` / non-emitting

- Evidence for: historical no-owner reports were correct under older caller-required policy.
- Evidence against: current owner/emitter model accepts strong raw-helper class ownership when source-family fields and context are this direct. Reverting to no-owner would lose known ControlPane semantics.
- Decision: reject as current metadata; preserve as historical context.

## Source Placement

Recommended source placement remains [UID:0000IG] `NexusTK/ui/core/ControlPane.cpp`.

Why:

- `by-file/ControlPane.md` already has projected path `NexusTK/ui/core/`.
- `by-project-structure/proposed-source-tree.md` lists `ControlPane.cpp` under `ui/core` and distinguishes it from reusable `ui/controls` concrete controls.
- The helper is base-control active-frame policy, not progress, button, feature-dialog, or primitive GrafPort source.

Rejected placements:

- `ProgressBarControlPane.cpp`: successor adjacency only.
- `ButtonControlPane.cpp`: analogous frame helper exists but fields differ.
- `GrafPort.cpp`: dependency primitives only.
- New standalone helper file: no source/debug/source-tree evidence and the helper is too small/local to justify a source root.

## Range / Split / Padding / Reclassification Analysis

- Keep exact target range `0x00494c50-0x00494c80`.
- Keep `0x00494c4a-0x00494c50` as ignored `0xcc` alignment.
- Keep [UID:0002PD] as a non-reconstructable mixed physical helper-band container. It spans ProgressBar and ControlPane children and must not emit aggregate C++.
- Do not merge [UID:0003N9] into [UID:0003N7]; six `0xcc` bytes separate the active-state setter from the raw draw helper.
- Do not split [UID:0003N9]; no independent interior entry exists and the two conditional branches both target the shared local epilogue.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested in this report-only assignment.

Documentation/source-facing recommendations:

- Keep document/file subject `ControlPaneDrawActiveFrameHelper`.
- Use `ControlPane::DrawActiveFrame` as the best inferred future source method name in behavior prose only. Do not include a C++ body unless it is placed in the target's formal `RECONSTRUCTION_CPP` block.
- Use `m_controlVisible` for `+0x101` and `m_controlActive` for `+0x102` in behavior prose.
- Use `m_bounds` / `RectBounds` for `+0x44`.
- Use `m_drawMode` for `+0x70`.
- Use `GrafPort::SetDrawColor` for `0x004b9660` in this context.
- Use `GrafPort::DrawRectFrame` for `0x004ba450`.
- Keep `0x80` as active/focus/frame color index; do not invent a named palette constant yet.

## First-Draft C++ Recommendation

Eligible mechanically: yes. [UID:0003N9] is reconstructable, has nonblank emitter [UID:000038], and recommended `(88 + 89) / 2 = 88.5` exceeds the current code-entry gate.

Formal insertion recommendation: do not insert formal C++ yet. Keep the managed C++ block blank.

Behavior prose for documentation, not C++ for insertion: `ControlPane::DrawActiveFrame` is the best source-facing behavior name. When `m_controlVisible` and `m_controlActive` are both nonzero, the helper selects active-frame color `0x80` through `GrafPort::SetDrawColor`, clears inherited `m_drawMode` to `0`, and frames inherited `m_bounds` through `GrafPort::DrawRectFrame`; otherwise it performs no drawing. Under the supervisor correction, this report intentionally carries no C++ body outside the formal `RECONSTRUCTION_CPP` block, and that block remains blank under the proof below.

Reason the behavior prose preserves the recovered body: it matches the two state-byte gates, color `0x80`, draw-mode clear, inherited bounds pointer, and `DrawRectFrame` dependency without presenting C++ outside the formal block.

Reason formal C++ should remain blank: no current evidence proves how this out-of-line body is declared or reached. It may be a retained private member, a protected member, source-unused retained body, or another compiler/linker-retained source artifact. The body is known; source liveness/declaration is not. Emitting a formal method now would make the generated source look more final than the binary evidence supports. The correct current generated disposition is no emitted UID0003N9 body; the current generated `ControlPane.cpp` search shows no UID0003N9 marker/body/reference while the by-* docs retain the route context and detailed no-code proof.

## Score And Metadata Recommendation

Historical pre-callback state:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:000038`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000038`
- blank emitter position
- blank formal C++

Current/applied state and retained recommendation:

- `COMPLETION:88`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:000038`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:000038`
- Keep blank emitter position
- Keep formal C++ blank

Score-improvement attempt and result:

- No-function blocker: attacked with `lookup_funcs`, `entity_query`, `disasm`, `decompile`, `insn_query`, `callees`; result remains raw/non-function, but exact decode/range is current-session proven.
- No-xref/reachability blocker: attacked with `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, `find immediate`, local VA/RVA/raw pointer scan, and local direct-transfer scan with positive controls; result remains no route, now strong enough for a formal no-code proof.
- Field-name blocker: attacked through sibling ControlPane state helper docs/MCP vtable cells and GrafPort docs; result resolved to source-facing meanings and best inferred names.
- Helper-name blocker: attacked through body behavior and sibling analogues; result `ControlPane::DrawActiveFrame` as best future source-facing method name, while doc label remains descriptive.
- Owner/emitter blocker: attacked through ControlPane, ProgressBar, Button, GrafPort, no-owner, generated output, proposed source tree, and vtable evidence; result keep ControlPane owner/emitter.
- C++ blocker: attacked by recovering the source-shaped behavior and testing route/declaration evidence; result blank formal C++ remains correct, with behavior described only in prose outside the formal block.

Reason not higher:

- No source-grade entry route, vtable/table/pointer route, or source declaration exists after current checks.
- Exact original helper/member/color constant spellings remain unrecovered.
- Formal C++ remains blank, so completion should stay below `90`.
- Confidence should remain below `90` because the no-route retained-helper disposition is correct but not final-source certainty.

Reason not lower:

- Exact range, bytes, behavior, sibling field meanings, callee meanings, owner/source placement, route-negative evidence, and rejected alternatives are now current-session audited and implementation-ready.
- An analogous accepted raw helper [UID:0003N8] sits at `87/88` with no route and blank C++; [UID:0003N9] has equally strong or stronger base-class field evidence after this pass.

## Final Recommendation

- Keep UID0003N9 as the exact half-open raw helper `0x00494c50-0x00494c80`.
- Preserve current target metadata: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, `Nested:0`, and blank formal `RECONSTRUCTION_CPP`.
- Preserve [UID:000038] `ControlPane` as the semantic owner and emitted route context through [UID:0000IG] `NexusTK/ui/core/ControlPane.cpp`, while documenting that current generated C++ omits UID0003N9 because the formal block is blank under no-route/no-declaration proof.
- Preserve the source-facing behavior names in prose only: `ControlPane::DrawActiveFrame`, `m_controlVisible`, `m_controlActive`, `m_bounds`, `m_drawMode`, `GrafPort::SetDrawColor`, and `GrafPort::DrawRectFrame`. Exact original spellings and any named color constant remain confidence caps.
- Preserve rejected alternatives: ProgressBar successor fragment, Button/concrete control owner, GrafPort primitive owner, standalone helper file, and current no-owner/non-emitting metadata.
- Preserve support sync in `by-class/ControlPane.md`, `by-file/ControlPane.md`, and `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`; optional GrafPort/vtable support pages are already sufficient.
- Gate 2 callback result: only `by-file/ControlPane.md` needed narrow support prose repair, changing stale generated-marker wording in the raw-helper row and historical route prose to the current no-marker/no-body generated disposition. No target, class, mixed-parent, optional support, generated manual, coverage, validator-state manual, lifecycle, or archive edits are recommended or remaining. Supervisor-owned active revalidation clearance already occurred through command `000000007202`; any later supervisor-owned execution remains outside B004 scope.

## Recommended Target Doc Changes

Target path: `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`.

Historical accepted changes, now applied and recommended to retain:

- Metadata changed to `COMPLETION:88`, `CONFIDENCE:89`.
- Keep owner/emitter/reconstructable fields unchanged.
- Keep formal C++ blank.
- Retain the dated `2026-06-23 B004 MCP-backed source-quality recheck` section with session `80de0a67`, IDB/input provenance, PE hash/section facts, current function/no-function evidence, exact bytes/signature, decompile failure, raw disassembly, xref/code/data/immediate route results, PE pointer/direct-transfer scan with positive controls, vtable dwords, and callee analyses.
- Retain the status/score rationale change from "field/helper names unresolved" to "source-facing meanings resolved; exact original spelling and route/declaration still cap confidence/C++."
- Preserve historical no-owner/no-emitter and prior B001/B002 no-change decisions as superseded policy/history, not current metadata.
- Preserve rejected ProgressBar/Button/GrafPort/no-owner/standalone routes and negative route evidence.
- Retain the no-code proof above and behavior prose for `ControlPane::DrawActiveFrame`, explicitly without a C++ body outside the formal block.

## Recommended Support Doc Changes

Historical accepted support changes, now applied or already-present and recommended to retain:

- `by-class/ControlPane.md`: records [UID:0003N9] as raised to `88/89`, keeps it class-routed, includes B004 evidence summary, uses `m_controlVisible`/`m_controlActive`/`m_bounds`/`m_drawMode` source-facing meanings, and keeps formal class C++ blank.
- `by-file/ControlPane.md`: records the `80de0a67` no-route/source-quality recheck and keeps `NexusTK/ui/core/ControlPane.cpp` as the source route context with blank/no-code proof.
- `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`: carries the child inventory row for [UID:0003N9] at `88/89`, keeps the parent non-reconstructable/non-emitting, and summarizes the current field/callee names plus no-route proof.

Already sufficient; no B004 edit required:

- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`: already records [UID:0003N9] as a `0x004b9660` consumer and supports `SetDrawColor`.
- `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`: already records the `0x00494c79` raw ControlPane caller and has first-draft `GrafPort::DrawRectFrame` C++.
- `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md` and `by-type/by-vtable/ControlPaneVtables.md`: already prove the vtable route for modeled siblings and no slot for the raw helper; no edit is needed unless adding the B004 no-slot note is desired.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

File/placement: `by-memory/-coverage-report.md`, replace the current nested [UID:0003N9] row under [UID:0002PD] `ControlFamilyStateVirtualHelpers`.

Exact replacement row:

```text
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable : 88% : strong : B004 2026-06-23 MCP session 80de0a67 and PE scan raise this ControlPane class-routed raw active-frame helper: exact 0x30-byte source-shaped body after six 0xcc bytes, zero function/xref/code-ref/data-ref/immediate/VA/RVA/raw-offset/direct-branch route to 0x00494c50 or plausible interiors, positive controls for sibling ControlPane vtable/direct routes and ProgressBar successor, resolved field/callee meanings for ControlPane visible/active bytes +0x101/+0x102, inherited bounds +0x44, GrafPort draw mode +0x70, SetDrawColor color 0x80, and DrawRectFrame rectangle framing; keep owner/emitter 000038 and blank formal C++ under explicit no-route/no-declaration retained-helper proof.
```

Reason B004 must not apply it directly: B-agent reports do not edit any `-coverage-report.md` file during report-only work, and supervisor owns coverage application after verification.

## Open Questions With Attempted Resolution

- Raw helper reachability: resolved to "no proven static route in current evidence." Same-pass checks covered MCP xrefs/code/data/immediates, function inventory, vtable cells, and local PE pointer/direct-transfer scans with positive controls. Score/C++ impact: confidence capped below `90`; formal C++ blank.
- Helper declaration shape: best inferred behavior name is `ControlPane::DrawActiveFrame`, but no caller/vtable/source declaration proves public/protected/private status, return spelling, or retained/dead source liveness. Score/C++ impact: blank formal C++; no C++ body is allowed outside the formal block.
- Field names: source-facing meanings are resolved enough for documentation and reference code as `m_controlVisible`, `m_controlActive`, `m_bounds`, and `m_drawMode`. Exact original spellings are not proven. Score impact: no longer blocks a score raise, but caps final-source confidence.
- Color constant: `0x80` is active/focus/frame color index 128 (Verified with `int_convert.py`). No named palette constant is proven. Score impact: minor confidence cap only.
- Split/source placement: resolved. Keep exact range and ControlPane source route; no split/merge/new file.

## Validator Results

Prior 2026-07-05 final cleanup after active revalidation clear:

- Validators run during that cleanup: none. The supervisor instruction forbade validators during that report-text cleanup.
- `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, and manual archive moves: not run.
- Generated output read-only observation at that prior cleanup point: `auto-generated/NexusTK/ui/core/ControlPane.cpp` showed `validator-command-id: 000000007143`, `validator-refreshed-at: 2026-07-05T15:10:39-04:00`, and no UID0003N9 marker/body/reference in that search.
- Validator lifecycle state preserved: footer records `needs-revalidation` event command `000000004167` at `2026-07-01T19:52:03-04:00`, de-execution/return command `000000007184` at `2026-07-05T15:40:54-04:00`, and active revalidation clear command `000000007202` at `2026-07-05T16:00:53-04:00`.
- Historical scoped validator command IDs/timestamps for the original implementation/correction batches were not present in the returned report artifact; their command text, exit code, `ok` count, warnings, and generated side effects are preserved below exactly as recorded. This repair does not invent missing historical command metadata.

Gate 2 verification callback on 2026-07-05:

> Executable block R001 was removed from this report and preserved verbatim in [0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md](0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- First same-file validator after the raw-helper-row wording repair: command id `000000007220`, timestamp `2026-07-05T16:12:56-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred`.
- Final same-file validator after the historical-route wording repair: command id `000000007224`, timestamp `2026-07-05T16:20:32-04:00`, exit code `0`, `ok: 1`; `scanned markdown files: 1`; `stats_incremental_noop: 1`; `projected_stats_update: 1`; generated refresh reported `deferred` with generated refresh command id/timestamp matching `000000007224` / `2026-07-05T16:20:32-04:00`.
- Warnings: existing `missing_ref_uid` diagnostics for ControlPane support links, including `0003J9`, `0003N3`, `0003N4`, `0003N6`, `0003N7`, `0003N9`, and `0003J8`, with 19 more suppressed rows. These are validator-owned registry/reference diagnostics; B004 did not hand-edit validator state.

Queue/generated status after the validator:

> Executable block R002 was removed from this report and preserved verbatim in [0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md](0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Intermediate queue-status command id `000000007225` at `2026-07-05T16:20:40-04:00` showed the deferred generated refresh for command `000000007224` still processing: worker running `True`, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `1`.
- Final queue-status command id: `000000007226`.
- Final queue-status timestamp: `2026-07-05T16:20:47-04:00`.
- Final queue state: worker running `True`; queued jobs `0`; processing jobs `0`; queued generated refresh jobs `0`; processing generated refresh jobs `0`; unclaimed results `37`; generated refresh results `6301`.
- Generated freshness observation, read-only: `auto-generated/NexusTK/ui/core/ControlPane.cpp` now shows `validator-command-id: 000000007224`, `validator-refreshed-at: 2026-07-05T16:20:32-04:00`, `validator-refresh-source: deferred-generated-refresh`, and no UID0003N9 / `0x00494c50` / `DrawActiveFrame` marker/body/reference in the search.

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R003 was removed from this report and preserved verbatim in [0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md](0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Target validator result: exit code `0`, `ok: 1`. Validator applied `completion_update 0003N9 ... 88`, `confidence_update 0003N9 ... 89`, removed [UID:0003N9] from generated low-score lists in `project-level/-auto-completion-stats.md`, rebuilt `validator.ini`, updated projected stats, reported stale registry rows `0003E6`/`00026U`, and produced validator-owned autogen side effects including `autogen_cpp_update 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp` plus `tools/validator_autogen_backup/20260623-170851`.
- Class validator result: exit code `0`, `ok: 1`. Validator inserted the normalized [UID:0003N9] link in `by-class/ControlPane.md`, rebuilt `validator.ini`, updated projected stats, and reported the same stale registry rows; generated C++ and autogen reports were no-op.
- File validator result: exit code `0`, `ok: 1`. Validator inserted the normalized [UID:0003N9] link in `by-file/ControlPane.md`, rebuilt `validator.ini`, updated projected stats, and reported the same stale registry rows; generated C++ and autogen reports were no-op.
- Aggregate validator result: exit code `0`, `ok: 1`. Validator inserted the normalized [UID:0003N9] link in `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`, rebuilt `validator.ini`, updated projected stats, and reported the same stale registry rows; generated C++ and autogen reports were no-op.

Supervisor-return correction validators were rerun from `E:\NTK\GhidraBridge\source-3\project-documentation` after removing the prose-only C++ body:

> Executable block R004 was removed from this report and preserved verbatim in [0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md](0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Correction target validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 0003N9`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows `0003E6`/`00026U`, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.
- Correction class validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 000038`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.
- Correction file validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 0000IG`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.
- Correction aggregate validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 0002PD`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.

Second supervisor-return correction validators were rerun after removing inline call/prototype-style C++ fragments such as call parentheses, typed helper prototype text, reference-shape wording, and address-of bounds expressions from the target/support docs and report:

> Executable block R005 was removed from this report and preserved verbatim in [0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md](0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Second correction target validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 0003N9`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows `0003E6`/`00026U`, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.
- Second correction class validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 000038`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.
- Second correction file validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 0000IG`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.
- Second correction aggregate validator result: exit code `0`, `ok: 1`; `stats_incremental_noop 0002PD`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, same stale registry rows, and `autogen_cpp_noop 0000IG auto-generated/NexusTK/ui/core/ControlPane.cpp unchanged`.

## Changed Files

- Current Gate 2 callback manually modified `by-file/ControlPane.md` only, replacing stale UID0003N9 generated-marker wording in the raw-helper row and historical route prose with current no-marker/no-body generated disposition while preserving the `ControlPane.cpp` route context and no-code proof.
- Current Gate 2 callback modified this report artifact: `tools/leaser/Agents/Agent-B004/research/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md`, updating the ledger/checklist/validator/changed-file state.
- Leases: B004 read `tools/leaser/Agents/current_leases.md` and found no active leases, acquired `by-file\ControlPane.md` only immediately before each same-file support repair, validated the file after each repair, released the lease successfully after each validator batch, and re-read `current_leases.md` showing no active leases.
- Validator-owned side effects from current Gate 2 callback: `auto-generated/NexusTK/ui/core/ControlPane.cpp` refreshed to final command id `000000007224`; `project-level/-auto-completion-stats.md` projected path completion section was updated by the validator. B004 did not edit generated/project-level files by hand.
- Current Gate 2 callback did not edit target `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`, `by-class/ControlPane.md`, mixed parent `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`, optional GrafPort/vtable support pages, coverage reports, generated files by hand, validator state by hand, lifecycle/archive files, supervisor ledgers, IDA DB, or MCP/tool state.
- Prior 2026-07-05 final cleanup modified only this report artifact: `tools/leaser/Agents/Agent-B004/research/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md`.
- Prior final cleanup did not modify target/support by-* docs, generated files, project-level generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, IDA DB, MCP/tool state, or lease files.
- Historical implementation callback modified target/support docs: `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`, `by-class/ControlPane.md`, `by-file/ControlPane.md`, and `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`.
- Historical supervisor-return correction modified the target/support docs and this report to remove prose-only C++ body material and keep formal [UID:0003N9] `RECONSTRUCTION_CPP` blank under the no-code proof.
- Historical second supervisor-return correction modified target/support docs and this report to replace remaining reference-shape wording with behavior prose. Current read-only target/support inspection confirms the formal UID0003N9 C++ block is blank; any compact behavior shorthand in summaries remains outside the formal block and was not edited during this final cleanup.
- Optional support docs checked and not edited historically or during this cleanup: `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` already records [UID:0003N9] as a `0x004b9660` consumer and supports `SetDrawColor`; `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md` already records the `0x00494c79` raw ControlPane caller and has `GrafPort::DrawRectFrame`; `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md` and `by-type/by-vtable/ControlPaneVtables.md` already document sibling vtable routing/no helper slot at same-or-greater detail.
- No `-coverage-report.md` file was edited by B004; the exact replacement row remains supervisor-owned.
- Validator-owned/generated/project-level side effects from historical validators are recorded in `Validator Results`; the prior active-clear cleanup performed no validator-owned refresh, and the current Gate 2 validator-owned refresh is recorded above.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `88/89`; do not go to `90+` until a route/declaration or an accepted retained-helper emission policy exists.
- Remaining uncertainty: exact original source spelling and liveness/declaration route only. Current evidence is sufficient to raise documentation score and keep C++ blank; it is not sufficient for formal source emission.

## Implementation Tracking Checklist

Current Gate 2 verification callback:

- [x] Gate 1 callback authorization used exact artifact SHA256 `236C119337495FE5BF7278B1A8DAFF18B8F4104AC191F1D3E51B3347AAC1AD1B`.
- [x] Verified Claim And Incorporation Ledger rows C-0003N9-01 through C-0003N9-12 against current target/support docs and generated state.
- [x] Verified already-present target/support claims: C-0003N9-01 through C-0003N9-07, C-0003N9-09, and C-0003N9-10 are present at same-or-greater detail in the current target/class/mixed-parent/optional support docs.
- [x] Repaired the only drift category found: C-0003N9-08 in `by-file/ControlPane.md` still used stale generated-marker wording in the raw-helper row and historical route prose, so B004 changed both to the current no-marker/no-body generated disposition while preserving the `ControlPane.cpp` route context and no-code proof.
- [x] Preserved excluded/historical states: C-0003N9-11 remains supervisor-owned/coverage-tracker excluded, and C-0003N9-12 remains applied as lifecycle-history preservation after validator-owned active revalidation clear.
- [x] Lease discipline followed: current leases were read as empty before the edits, `by-file\ControlPane.md` was leased immediately before each same-file support repair, and it was released after each scoped validator; the final lease check showed no active leases.
- [x] Scoped validators run for the only edited by-* file: `python .\tools\validator.py --mode file --file by-file/ControlPane.md --apply --queue-timeout 240`, first command id `000000007220` at `2026-07-05T16:12:56-04:00`, final command id `000000007224` at `2026-07-05T16:20:32-04:00`, both exit code `0`, `ok: 1`.
- [x] Validator warnings recorded: `missing_ref_uid` warnings for `0003J9`, `0003N3`, `0003N4`, `0003N6`, `0003N7`, `0003N9`, and `0003J8`, plus 19 suppressed rows; these are validator-owned reference diagnostics and were not manually edited.
- [x] Queue/generated checks recorded: `python .\tools\validator.py --queue-status`, intermediate command id `000000007225` at `2026-07-05T16:20:40-04:00` showed one generated-refresh job processing; final command id `000000007226` at `2026-07-05T16:20:47-04:00` showed zero queued/processing jobs and zero queued/processing generated-refresh jobs.
- [x] Generated freshness verified read-only: `auto-generated/NexusTK/ui/core/ControlPane.cpp` refreshed to validator command id `000000007224`, `validator-refreshed-at: 2026-07-05T16:20:32-04:00`, `validator-refresh-source: deferred-generated-refresh`, and still has no UID0003N9 / `0x00494c50` / `DrawActiveFrame` marker, body, or reference.
- [x] No target, class, mixed-parent, optional support, generated manual, coverage, validator-state manual, lifecycle/archive, supervisor-ledger, IDA DB, or MCP/tool-state edits were made during this Gate 2 callback.
- [x] Remaining unapplied accepted items: none.

Prior 2026-07-05 final report-text cleanup after active revalidation clear:

- [x] Read the refreshed B004 `goal.md`, project-level `ntk-b-agent-workflow` skill, B-agent workflow/template references, and relevant `by-structure.md` MCP/reconstruction rules.
- [x] Confirmed the validator-owned active-clear state: the report no longer has a `REPORT-VALIDATION-STATUS` header, and the footer contains `active-revalidation-cleared` command `000000007202` at `2026-07-05T16:00:53-04:00`.
- [x] Previously normalized required headings remain present: `Supporting Research`, `Evidence Standards Used`, `Evidence Checked`, `Claim And Incorporation Ledger`, `Direct Xref / Caller Inventory`, `Documentation Evidence And IDA Status`, `Final Recommendation`, exact coverage/tracker heading, exact `Validator Results`, current `Changed Files`, and repaired checklist state.
- [x] Repaired then-stale current-state language: at that cleanup point, target/support docs were post-callback `88/89`, generated `ControlPane.cpp` had command id `000000007143` and no UID0003N9 marker/body/reference, historical empty-marker and validator notes were labeled historical, and active revalidation clear was recorded as current lifecycle fact.
- [x] Repaired ledger schema and lifecycle states: required columns are present; actions use only allowed values; verification states use callback/current repair states (`applied`, `already-present`, `excluded-with-reason`) rather than report-only prose states.
- [x] Preserved useful research: exact MCP/PE evidence, raw bytes/signature, xref/route negatives, source-facing field/callee names, owner/source-placement reasoning, no-code proof, rejected alternatives, score rationale, and open-question closure remain in the report.
- [x] Preserved validator-owned lifecycle history footer and did not manually edit validator-owned status headers; the prior status header was removed by supervisor-owned validator command `000000007202`.
- [x] Did not edit target/support by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, IDA DB, tool state, or lease files during that cleanup.
- [x] Did not run validators, `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, manual archive moves, or equivalent lifecycle/archive commands during that cleanup.
- [x] Did not acquire leases; no lease is needed for report-text repair in B004's own research folder.

Historical initial report-only pass:

- [x] Supervisor validation was required before implementation; this report was later accepted for implementation historically.
- [x] Target/support docs to update were identified: target `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`; support `by-class/ControlPane.md`, `by-file/ControlPane.md`, and `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`.
- [x] Current target state and actual evidence checked were recorded: current docs, generated output, B001 executed report, MCP session `80de0a67` health/schema, function inventory, bytes/signature, disassembly/decompile failure, xrefs/routes, PE route scan, vtable cells, sibling state helpers, GrafPort callees, proposed source tree, and coverage row.
- [x] Metadata/score changes were specified: raise [UID:0003N9] from historical `85/86` to `88/89`; keep owner/emitter/reconstructable fields unchanged.
- [x] Score-limiting blockers were researched to resolution/no-code proof: no-function/no-xref/reachability tested by MCP plus PE scan; field/helper names resolved to best source-facing meanings; C++ blocker resolved to blank formal C++ with no-route/no-declaration proof.
- [x] Owner/emitter/reconstructable disposition was specified: no owner/emitter/reconstructable changes; preserve [UID:000038] `ControlPane` route and reject ProgressBar/Button/GrafPort/no-owner alternatives.
- [x] Split/rename/new-child changes were resolved as not applicable: keep `0x00494c50-0x00494c80`, keep pre-padding ignored, keep [UID:0002PD] non-emitting mixed container.
- [x] Source-placement, range/split/padding/reclassification, and source-facing name recommendations were recorded: use `ControlPane::DrawActiveFrame`, `m_controlVisible`, `m_controlActive`, `m_bounds`, `m_drawMode`, `GrafPort::SetDrawColor`, and `GrafPort::DrawRectFrame` in documentation; no IDA DB edits requested.
- [x] First-draft C++/no-code disposition was recorded: keep formal target C++ blank; add behavior prose and explicit no-route/no-declaration retained-helper proof without any C++ body outside the formal block.
- [x] Exact target/support doc facts to incorporate were listed at report-level detail: MCP/PE provenance, exact range/bytes, no-function/no-route evidence, positive controls, vtable cells, field/callee map, ranked owner analysis, score rationale, rejected alternatives, historical no-owner supersession, and no-code proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence were listed for preservation: old no-owner reports superseded as metadata/history; no-vtable/no-pointer/no-branch/no-xref negative evidence preserved; ProgressBar, Button, GrafPort, standalone-file, and no-owner current metadata rejected.
- [x] Wave2/Wave3 material was not used as authority; generated/autogen output was used only for route/status, and stale `sub_` labels remain raw evidence aliases only.
- [x] Open questions were closed or documented as evidence-backed unresolved: reachability/declaration remains no-code proof; exact original spellings and color constant name remain confidence caps, not blockers to score raise.
- [x] Validators to run after accepted implementation were specified: target, `by-class/ControlPane.md`, `by-file/ControlPane.md`, and [UID:0002PD] aggregate scoped validators.
- [x] Supervisor-owned coverage/tracker text was supplied; B004 must not edit coverage directly.
- [x] Third-party import directive was not applicable.

Historical implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted callback `B004-implement-controlpane-draw-active-frame-helper-source-quality-0003N9-mcp-20260623` received; implementation applied from this report.
- [x] Leases checked, acquired, and released/expired: initial `python .\tools\leaser\leaser.py B004 lease by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md by-class\ControlPane.md by-file\ControlPane.md by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md` returned `Success` for all four. After interruption, two stale B004 leases were explicitly released with `python .\tools\leaser\leaser.py B004 unlease by-file\ControlPane.md by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md` (`Success`/`Success`) and reacquired for the remaining validator batch (`Success`/`Success`). Final `python .\tools\leaser\leaser.py B004 unlease ...` returned `Rejected[No active lease]` for the already-expired target/class leases and `Success` for `by-file\ControlPane.md` plus `by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`; the final lease report showed no B004 rows.
- [x] Supervisor-return correction leases acquired and released: fresh lease command for the four correction docs returned `Success` for `by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`, `by-class\ControlPane.md`, `by-file\ControlPane.md`, and `by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`. Fresh release command after edits/validators returned `Success` for all four, and the final current lease report had no B004 rows.
- [x] Supervisor-return C++ correction applied historically: inspected target/support docs for `ControlPane::DrawActiveFrame` prose-only C++; kept formal [UID:0003N9] `RECONSTRUCTION_CPP` blank under the accepted no-code proof, removed the prose-only C++ body from the target/report, and replaced reference-shape wording with behavior prose.
- [x] Second supervisor-return C++ correction applied historically: remaining reference-shape fragments were replaced with behavior prose. Current repair did not re-edit by-* docs; current read-only target check confirms the formal UID0003N9 C++ block is blank.
- [x] All accepted target/support doc details incorporated at report-level detail: target has the `2026-06-23 B004 MCP-Backed Source-Quality Recheck` section with session `80de0a67`, IDB/PE provenance, exact bytes/signature, no-function/decompile failure, xref/code/data/immediate negatives, PE pointer/direct-transfer negatives with positive controls, vtable checks, callee analyses, source-facing names, rejected alternatives, score rationale, historical no-owner supersession, no-code proof, and behavior prose.
- [x] Support docs incorporated at report-level detail: `by-class/ControlPane.md`, `by-file/ControlPane.md`, and `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md` synchronize [UID:0003N9] to `88/89`, preserve ControlPane route/no-code proof, and carry current MCP/PE route-negative evidence plus source-facing names.
- [x] Optional support docs checked and not edited: `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`, `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md`, and `by-type/by-vtable/ControlPaneVtables.md` already contain same-or-greater supporting facts and no stale contradiction requiring an edit.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target changed to `COMPLETION:88`, `CONFIDENCE:89`; kept `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank emitter position, exact range `0x00494c50-0x00494c80`, and blank formal `RECONSTRUCTION_CPP`. No split/rename/new child was applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target and support docs preserve superseded historical no-owner/no-emitter decisions, no-function/no-xref/no-vtable/no-pointer/no-direct-branch evidence, and ProgressBar/Button/concrete-control/GrafPort/standalone-file/no-owner rejection.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: field/callee/source-facing names resolved for docs; reachability/declaration remains a no-code proof and confidence cap; exact original spelling and color-constant name remain documented confidence caps, not deferred score blockers.
- [x] Validators run historically and results recorded: all four required scoped validators ran from `source-3/project-documentation` during the accepted implementation, reran after the first supervisor-return C++ correction, and reran after the second strict cleanup; each recorded run exited `0` with `ok: 1`, with details in `Validator Results`.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact replacement row remains in `Exact Manual Supervisor-Owned Coverage Or Tracker Text`; B004 did not edit any `-coverage-report.md` file.
- [x] Remaining unapplied accepted items listed with exact blocker: none from the historical accepted callback; after the current Gate 2 C-0003N9-08 support repair, no accepted callback item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B004/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B004","command_id":"000000007184","destination_path":"tools/leaser/Agents/Agent-B004/research/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B004/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","timestamp":"2026-07-05T15:40:54-04:00"} -->
<!-- {"agent":"B004","command_id":"000000007202","details":"active returned report revalidation marker cleared after de-execution repair","event":"active-revalidation-cleared","source_path":"tools/leaser/Agents/Agent-B004/research/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","timestamp":"2026-07-05T16:00:53-04:00","uid":"0003N9"} -->
<!-- {"agent":"B004","command_id":"000000007233","destination_path":"executed-b-agent-research/B004/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","timestamp":"2026-07-05T16:28:48-04:00","uid":"0003N9"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003N9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
