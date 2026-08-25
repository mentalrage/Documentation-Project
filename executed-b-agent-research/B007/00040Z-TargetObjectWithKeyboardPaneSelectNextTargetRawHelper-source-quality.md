** TARGET-REPORT-UID:00040Z **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 00040Z TargetObjectWithKeyboardPane Select Next Target Raw Helper Source-Quality Research

Agent: B007  
Mode: post-implementation callback report repair; implementation complete and awaiting supervisor Gate 2 / execution  
Target: `[UID:00040Z] by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md`  
Report path: `tools/leaser/Agents/Agent-B007/research/00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md`

## Finalized Report / Current Recommendation

Current implemented recommendation: `[UID:00040Z]` is now documented as a reconstructable marker-only emitting child through `[UID:0000ED] TargetObjectWithKeyboardPane`, and the implementation callback is complete pending supervisor Gate 2 / execution.

The raw helper body is source-authored TargetObject selection code, but live MCP session `c9ac3d5b` still finds no function entry, xref, code-ref, data-ref, immediate, absolute-VA pointer, or imagebase-relative RVA pointer route to raw start `0x005b0640`. The active vtable-routed key handler `[UID:0001LK]` contains the same next/down target-selection behavior inline at `0x005b0180-0x005b01cc`; this is inline coverage, not caller proof.

Current target disposition after callback:

- `COMPLETION:88`, `CONFIDENCE:89`.
- `CANONICAL_OWNER:0000ED`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`.
- `EMITTER_UIDS:0000ED`.
- Inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank.
- Multiline reconstruction block contains only the formal covered-by marker to `[UID:0001LK]`.
- Generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` contains the UID00040Z marker and does not list UID00040Z as an Empty Emitter Marker.
- Report is not executed/archived yet; supervisor `execute_report` remains pending after Gate 2.
- Do not emit a callable `SelectNextTargetObject()` helper body unless a future pass recovers a real route or the supervisor explicitly accepts retained unreferenced helper-body emission.

## Supporting Research

The current target page already captures the high-level behavior from prior B014 split work: resolve `s_targetObjectTargetId`, call `MapPane::FindNextSelectableObject` when an old target exists, fall back to the local-player object when it does not, clear/set `LivingObjectPane` target highlights, store `[new + 0xfc]`, or clear the saved id. This report rechecks the route and coverage blocker with restored live MCP evidence and applies the current literal formal-block rule for nonblank emitters.

Relevant current docs reviewed:

- Target `[UID:00040Z]` raw helper page.
- Parent `[UID:00036T]` navigation raw helper container.
- Active key handler `[UID:0001LK]`.
- Marker-only sibling `[UID:000410]`.
- Class `[UID:0000ED] TargetObjectWithKeyboardPane`.
- Source file route `[UID:0000OH] TargetSelectionInputPanes`.
- Generated tracker/coverage rows and generated `TargetSelectionInputPanes.cpp`.
- Executed B014, B003, and B002 reports as leads/precedent, with current MCP used as the hard proof for this target.

## Target

- UID: `00040Z`.
- Path: `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md`.
- Historical queue source before implementation: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Historical pre-callback generated tracker row: `85/88`, combined `86.5`, reconstructable `true`, report count `0`, blank executed report path.
- Historical pre-callback generated memory coverage row: `non-emits`, owner `0000ED`, blank emitter.
- Current post-callback generated/source state: target metadata is `88/89` with `EMITTER_UIDS:0000ED`; generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` contains marker-only entries for UID00040Y, UID00040Z, and UID000410. UID00040Z appears as a covered-by marker at generated lines `1103-1104`, not as an Empty Emitter Marker.
- Current report lifecycle state: implementation callback complete, scoped validators passed, report not yet executed/archived by supervisor.

## Current Target State

Current implemented target metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000ED
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ED
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
multiline RECONSTRUCTION_CPP block: marker-only covered by UID0001LK
```

Historical pre-callback state: the target previously had `COMPLETION:85`, `CONFIDENCE:88`, blank `EMITTER_UIDS`, blank multiline reconstruction block, and prose saying formal C++ stayed blank until a real entry route was recovered or retained helper emission was accepted. That was correct before the UID000410 and UID00040Y marker-only precedents, but it has now been superseded for UID00040Z.

Current target prose now describes the marker-only policy: UID00040Z has the same class owner, same raw-helper no-route blocker, and active inline UID0001LK coverage. The callable helper body remains intentionally absent, but the formal multiline block contains the covered-by marker.

Post-B006 and post-B007 support-doc baseline: UID00040Y has been accepted and supervisor-executed as marker-only covered by UID0001LK, with score `88/90`, supervisor execute command `000000005362`, and generated output containing the UID00040Y covered-by marker. UID00040Z is now also implemented as marker-only covered by UID0001LK at `88/89`. Shared support docs describe UID00040Y, UID00040Z, and UID000410 as marker-only raw-helper children covered by UID0001LK, while parent UID00036T stays non-emitting.

The central unresolved issue is not behavior. Live MCP confirms the behavior and range. The issue is source-output policy: a callable helper body would overclaim a recovered call surface, while a formal covered-by marker safely connects this retained raw range to the active emitted key-handler source.

## Evidence Standards Used

- Current IDA MCP evidence is mandatory and primary for route/function/byte claims.
- Current by-* docs are authoritative for accepted UID names, owner/source route, and source-facing names unless contradicted by live MCP.
- Executed reports are leads and precedent only; this report does not rely on B014's older PE-only or B003's older session as hard current proof.
- Generated reports and generated C++ are read-only state observations, not manually edited sources.
- Facts, source-shape inference, and rejected alternatives are kept separate.

## Evidence Checked

MCP session and availability:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC flow used: `initialize -> tools/list -> tools/call`.
- Server: `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- Active session: `c9ac3d5b`.
- `idb_list`: one active owned/adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing=false`, `pid=12376`, `worker_pid=12376`.
- `server_health`: `status=ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.

MCP tool calls used:

- `lookup_funcs` for `0x005b0010`, `0x005b05b0`, `0x005b05d0`, `0x005b0640`, `0x005b06a8`, `0x005b06b0`, and `0x005b06f0`.
- `xrefs_to` for `0x005b0640`, `0x005b05d0`, `0x005b06b0`, `0x005b05b0`, `0x005b06f0`, `0x005b0010`, and `0x0069bf2c`.
- `find type=code_ref`, `find type=data_ref`, and `find type=immediate` for raw starts `0x005b0640`, `0x005b05d0`, and `0x005b06b0`.
- `find_bytes` for UID00040Z absolute VA pointer bytes `40 06 5B 00` and imagebase-relative RVA pointer bytes `40 06 1B 00`.
- `get_bytes` for `0x005b0638-0x005b0640`, `0x005b0640-0x005b06a8`, and `0x005b06a8-0x005b06b0`.
- Bounded `disasm` for raw start `0x005b0640` with `max_instructions=80`.
- Paged bounded `disasm` for active key handler `0x005b0010`, including offset `80` for the self/previous/next branch cluster.
- `decompile 0x005b0010` with address markers disabled for key-handler sanity check.

Documentation/generated checks:

- `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md`.
- `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`.
- `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`.
- `by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`.
- `by-class/TargetObjectWithKeyboardPane.md`.
- `by-file/TargetSelectionInputPanes.md`.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Executed reports `B014/00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md`, `B003/000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md`, and `B002/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported conclusion | Rejected alternatives / uncertainty |
| --- | --- | --- | --- |
| Raw helper role | Current disassembly at `0x005b0640`, target page, parent page, active key-handler branch. | `SelectNextTargetObject()` / next-down target traversal for `TargetObjectWithKeyboardPane`. | Exact original helper spelling is inferred; do not claim symbol proof. |
| Range and bytes | `get_bytes` and bounded raw disassembly. | `0x005b0640-0x005b06a8` is executable helper code; `0x005b0638-0x005b0640` and `0x005b06a8-0x005b06b0` are eight `0xcc` bytes each. | Reject padding or compiler-only bytes for the body. |
| Liveness/reachability | `lookup_funcs`, `xrefs_to`, `find`, `find_bytes`, neighbor positive controls. | Retained/unreferenced raw helper body; no current route to start `0x005b0640`. | Reject active key-handler callee wording; reject vtable/callback/table route. |
| Owner/emitter | Class/file docs, saved-target refs, dependency direction, UID00040Y/UID000410 and UID0002S5 precedents. | Keep direct owner `[UID:0000ED]`; set direct emitter `[UID:0000ED]`; `[UID:0000OH]` remains source-file route. | Reject direct file UID emitter, dual emitter, MapPane/UserPane/LivingObjectPane ownership. |
| Formal source output | Current no-empty-emitter rule, active UID0001LK coverage, UID00040Y/UID000410 marker-only precedents. | Emit exact formal covered-by marker to UID0001LK; do not emit callable helper-body C++. | Confidence capped by no recovered source call surface and unknown original retention shape. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00040Z-01 | UID00040Z is reconstructable TargetObject source-authored raw helper code, not padding or compiler glue. | Strong | MCP `get_bytes` shows executable bytes from `0x005b0640-0x005b06a7` bounded by eight `0xcc` bytes before and after; bounded `disasm 0x005b0640` decodes MapPane lookup/traversal, LivingObjectPane highlight calls, `s_targetObjectTargetId` stores, and normal returns. | Target page `Status`, `Purpose`, `Behavior`, `No-Code Proof / Covered-By Marker`; parent UID00036T child row; class UID0000ED helper evidence. | incorporate | applied |
| C-00040Z-02 | UID00040Z metadata should become `COMPLETION:88`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000ED`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000ED`, and leave `EMITTER_POSITION_OPTIONAL` blank. | Strong | Historical pre-callback target header was `85/88`, owner `0000ED`, reconstructable true, blank emitter; live evidence resolved the empty-emitter/source-output blocker while preserving the no-route confidence cap. Callback implementation applied the current `88/89` and `EMITTER_UIDS:0000ED` state. | Target page header; target item summary; parent/class/file support rows that summarize child status. | incorporate | applied |
| C-00040Z-03 | UID00040Z formal multiline reconstruction block should contain only the covered-by marker to UID0001LK, with inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank. | Strong | `First-Draft C++ Recommendation` supplies exact formal block text; UID0001LK is vtable-routed at data ref `0x0062f40c` and contains the active next/down branch inline. | Target page `RECONSTRUCTION_CPP CODE` header/block; generated output expectation in `TargetSelectionInputPanes.cpp`. | incorporate | applied |
| C-00040Z-04 | No callable `SelectNextTargetObject()` helper body should be emitted for UID00040Z in this callback. | Strong | MCP `lookup_funcs 0x005b0640` returns `Not a function`; `xrefs_to`, `find code_ref`, `find data_ref`, `find immediate`, and `find_bytes` VA/RVA pointer checks all return zero for `0x005b0640`; active behavior already exists inline in UID0001LK. | Target `No-Code Proof / Covered-By Marker`; class/file support caveats; key-handler relationship note. | incorporate | applied |
| C-00040Z-05 | Live MCP session `c9ac3d5b` is the current hard evidence source for UID00040Z route/boundary claims. | Strong | `idb_list` reported active session `c9ac3d5b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status=ok`, imagebase `0x400000`, analysis ready, Hex-Rays ready, strings cache ready. | Target evidence section; parent/class/file support notes where current MCP proof is cited. | incorporate | applied |
| C-00040Z-06 | MCP confirms `0x005b0640` has no recovered direct route. | Strong | `xrefs_to 0x005b0640` returned zero; `find type=code_ref`, `find type=data_ref`, and `find type=immediate` returned zero; `find_bytes` returned zero matches for absolute VA bytes `40 06 5B 00` and RVA bytes `40 06 1B 00`. | Target `Reachability And Negative Route Evidence`; parent UID00036T route table; class/file support evidence. | incorporate | applied |
| C-00040Z-07 | Neighbor positive controls prove the negative route result is meaningful rather than a broken search. | Strong | MCP `xrefs_to 0x005b05b0` returned code refs from `0x005b0082`, `0x005b0422`, and `0x005b0495`; `xrefs_to 0x005b06f0` returned code refs from `0x005b00ce` and `0x005b00f4`; `xrefs_to 0x005b0010` returned data ref `0x0062f40c`. | Target route table; parent route evidence; class evidence notes. | incorporate | applied |
| C-00040Z-08 | UID0001LK contains active next/down inline coverage for UID00040Z behavior. | Strong | Bounded key-handler disassembly shows subtype/key branch at `0x005b0180`, saved-id push `0x005b0186`, active MapPane load `0x005b018c`, `FindObjectPaneById` call `0x005b0192`, `FindNextSelectableObject` call `0x005b01a4`, local-player fallback `0x005b01ad`, common highlight/update tail `0x005b01b3-0x005b01cc`, and saved-id clear/store behavior. | Target relationship section; key-handler UID0001LK relationship note; parent/class/file support docs. | incorporate | applied |
| C-00040Z-09 | Accepted source-facing names should remain `s_targetObjectTargetId`, `g_activeMapPane`, local-player/UserPane object view / `g_pUserPane->GetLocalPlayerObject()`, `MapPane::FindObjectPaneById`, `MapPane::FindNextSelectableObject`, `LivingObjectPane::SetTargetHighlight(bool)`, and object id `+0xfc` / `GetObjectId()`. | Strong | Current target/parent/class/file docs already use these names; MCP raw disassembly references `unk_69BF2C`, `dword_67A764`, `dword_67A748`, `sub_506970`, `sub_506B30`, `sub_53B1B0`, and `[esi+0FCh]` in matching roles. | Target behavior/source-facing-name table; support docs where TargetObject raw helper family is summarized. | incorporate | applied |
| C-00040Z-10 | Rejected alternatives must be preserved: no MapPane/UserPane/LivingObjectPane ownership, no direct file UID emitter, no dual emitter, no caller-proof wording, no IDA DB edits, and no reconstructable downgrade. | Strong | Dependency direction shows MapPane/UserPane/LivingObjectPane are callees/data sources only; direct owner UID0000ED is established; UID0001LK inline branch does not call `0x005b0640`; no MCP write/IDA DB action was performed. | Target `Rejected Alternatives`; class/file support notes; key-handler relationship caveat. | incorporate | applied |
| C-00040Z-11 | B006 executed UID00040Y as marker-only covered by UID0001LK with score `88/90`, supervisor execute command `000000005362`, and generated output now containing the UID00040Y marker. | Strong | Supervisor supplied this post-B006 baseline explicitly in the repair instruction; this report's current-state/support-plan text has been normalized to avoid stale UID00040Y blank wording. | `Current Target State`; `Final Recommendation`; parent/class/file support plan; implementation checklist. | incorporate | applied |
| C-00040Z-12 | After UID00040Z implementation, support docs should describe UID00040Y, UID00040Z, and UID000410 as marker-only children covered by UID0001LK while parent UID00036T remains non-emitting. | Strong | UID00040Y is now executed marker-only by B006; UID000410 is already accepted marker-only; UID00040Z has same owner/no-route/inline-coverage policy and formal marker recommendation in this report. | Parent UID00036T status/table/no-code proof; class UID0000ED raw-helper row; file UID0000OH source-output note; key-handler UID0001LK relationship note. | incorporate | applied |
| C-00040Z-13 | Generated `TargetSelectionInputPanes.cpp` should surface UID00040Z as marker-only, not as an Empty Emitter Marker. | Strong | Historical pre-callback generated output had UID00040Y and UID000410 markers but no UID00040Z output because UID00040Z had blank `EMITTER_UIDS`. After callback validation, generated `TargetSelectionInputPanes.cpp` contains UID00040Z marker-only output at lines `1103-1104` and no UID00040Z Empty Emitter Marker. | Report validator plan; target generated freshness expectation; file support generated-output note. | incorporate | applied |
| C-00040Z-14 | Callback implementation state, changed files, validators, generated freshness, leases, and lifecycle boundaries must be recorded accurately. | Strong | Callback edited the accepted by-* target/support docs, ran scoped validators only, did not run `execute_report` or lifecycle/archive commands, and updated this report after validation. | Report `Validator Results`, `Changed Files`, `Implementation Tracking Checklist`; final response. | incorporate | applied |

## Positive Evidence Summary

- `get_bytes` confirms exact target bytes: executable helper body at `0x005b0640-0x005b06a7`, with eight `0xcc` bytes before and after.
- `disasm 0x005b0640` decodes normal code: load `dword_67A764`, push `unk_69BF2C`, call `sub_506970`, call `sub_506B30` for old-target traversal, use `dword_67A748` fallback, compare old/new pointers, call `sub_53B1B0` to clear/set highlight, store `[esi+0xfc]` to `unk_69BF2C`, or write zero.
- The body reads/writes `0x0069bf2c` at `0x005b0648`, `0x005b0694`, and `0x005b069b`; this is accepted TargetObject saved-target state.
- Active UID0001LK next/down branch performs equivalent behavior inline with vtable reachability at `0x0062f40c`.
- Neighbor helpers prove route tooling is working: clear helper `0x005b05b0` and dispatch-forward helper `0x005b06f0` both have positive code xrefs.
- UID00040Y and UID000410 siblings already use the same class owner and a formal covered-by marker to UID0001LK for retained raw helpers with no direct route; UID00040Y was executed by B006 at `88/90` under supervisor command `000000005362`.
- UID0002S5 ItemWho report is accepted broader precedent for marker-only emission of reconstructable raw target-navigation helper code when active key-handler behavior exists inline and raw starts have no route.

## Negative Evidence Summary

- `lookup_funcs 0x005b0640` returns `Not a function`.
- `xrefs_to 0x005b0640` returns zero xrefs.
- `find type=code_ref`, `find type=data_ref`, and `find type=immediate` return zero matches for `0x005b0640`.
- `find_bytes` returns zero absolute VA pointer byte matches for `40 06 5B 00` and zero RVA pointer byte matches for `40 06 1B 00`.
- No vtable, callback, function-pointer table, switch-table, registration, or direct call route to `0x005b0640` was recovered.
- The active key handler duplicates the next/down behavior inline; it does not call `0x005b0640`.
- Exact original helper spelling and original source retention shape are unresolved; the body may have been private static, file-static, or retained dead helper code.
- A callable helper-body C++ block would invent an unrecovered call surface and duplicate active emitted behavior.

## Ranked Ownership Analysis

| Rank | Candidate | Recommendation | Reason |
| --- | --- | --- | --- |
| 1 | `[UID:0000ED] TargetObjectWithKeyboardPane` | Keep as canonical owner and direct marker emitter. | The helper mutates TargetObject saved target state, sits in the TargetObject helper suffix, and duplicates TargetObject keyboard navigation semantics. |
| 2 | `[UID:0000OH] TargetSelectionInputPanes` | Keep as indirect source-file route only. | This file owns the target-selection source family, but direct child emission should route through the class owner, matching UID00040Y, UID000410, and UID0002S5 precedent. |
| 3 | `[UID:0001LK] TargetObjectWithKeyboardPaneKeyboardEvent` | Use as formal covered-by target, not owner. | It has vtable reachability and inline next/down behavior, but it does not own the raw start or call it. |
| 4 | `MapPane` | Reject. | MapPane supplies lookup/traversal callees; UID00040Z mutates TargetObject saved-target state. |
| 5 | `UserPane` / local-player global owner | Reject. | `dword_67A748` is only the fallback selected object path. |
| 6 | `LivingObjectPane` | Reject. | It supplies highlight side-effect calls only. |
| 7 | No-owner/non-emitting | Reject for final disposition. | The raw helper is source-authored and directly class-owned; marker-only emission resolves the blank-emitter policy without overclaiming helper-body source. |

## Source Placement

The best source placement remains the TargetObject portion of `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`. At the by-* ownership layer, the direct emitter should be `[UID:0000ED] TargetObjectWithKeyboardPane`; `[UID:0000OH] TargetSelectionInputPanes` remains the file route through that class.

The generated output should not gain a standalone `static void SelectNextTargetObject()` body. The source-facing active implementation is already in `TargetObjectWithKeyboardPane::OnKeyEvent`, and the marker preserves traceability for this retained raw range.

## First-Draft C++ Recommendation

Eligible for formal C++ content after this report: yes, but marker-only. The target is reconstructable, should gain `EMITTER_UIDS:0000ED`, and can be safely represented in generated output through the active key-handler page without inventing a callable helper body.

Exact formal block insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Target-specific no-standalone-helper-body proof:

- Current MCP session `c9ac3d5b` reports no function at `0x005b0640`.
- Current MCP route checks found no xrefs, code refs, data refs, immediates, VA pointer bytes, or RVA pointer bytes for `0x005b0640`.
- The active vtable key handler UID0001LK already emits the equivalent next/down behavior inline.
- The exact original helper declaration, helper spelling, and source retention shape are not recoverable from the checked binary.
- A callable `SelectNextTargetObject()` body would imply a call surface the binary does not prove.

The marker is safe because it adds no behavior and points generated-source traceability to the exact active page covering the behavior. It is not caller proof.

## Final Recommendation

Final disposition: UID00040Z has been implemented as source-ready marker-only coverage through `[UID:0000ED] TargetObjectWithKeyboardPane`; the report is implementation-complete and awaiting supervisor Gate 2 / execution.

Exact target changes applied:

- `COMPLETION:85 -> 88`.
- `CONFIDENCE:88 -> 89`.
- Kept `CANONICAL_OWNER:0000ED`.
- Kept `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS: -> 0000ED`.
- Kept `EMITTER_POSITION_OPTIONAL:` blank.
- Replaced the blank formal multiline reconstruction block with the exact marker block under `First-Draft C++ Recommendation`.
- Replaced stale "blank until route/policy" wording with a current covered-by-marker policy: no callable helper body, marker covered by UID0001LK, inline coverage only, no caller proof.

Parent assignment disposition: `[UID:00036T]` remains a non-reconstructable/non-emitting split container. Its UID00040Y child is no longer blank: B006 already accepted and supervisor-executed UID00040Y as marker-only covered by UID0001LK at `88/90` with execute command `000000005362`. After this UID00040Z callback, support docs now describe all three raw-helper children as marker-only covered by UID0001LK: UID00040Y previous/up, UID00040Z next/down, and UID000410 local-player/self.

No-owner/non-emitting disposition: not recommended. If forced to leave UID00040Z non-emitting, the best fallback would be the current state, but that is weaker than the marker-only policy now accepted for UID000410 and UID0002S5.

Future work outside this report scope: recover original helper symbol/retention shape only if new symbols, route evidence, or source material appears. UID00040Y no longer needs separate consideration under this report because B006 has already executed its marker-only disposition.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md`.

Callback application state:

- Applied: metadata is `88/89`, owner `0000ED`, reconstructable true, emitter `0000ED`, blank emitter position.
- Applied: exact formal marker block from `First-Draft C++ Recommendation` inserted, with inline `RECONSTRUCTION_CPP CODE:[[[]]]` still blank.
- Applied: item summary says `SelectNextTargetObject : reconstructable/marker-only covered by UID0001LK : 88% : strong`.
- Applied: live MCP session `c9ac3d5b` evidence added, including IDB path, health state, raw-start no-function result, route-negative table, bytes/padding, and active UID0001LK next/down inline coverage.
- Applied: old no-code proof replaced with `No-Code Proof / Covered-By Marker`.
- Applied: accepted source-facing names and rejected alternatives preserved.
- Applied: change entry describes the B007 callback implementation before/after state.

Suggested summary text:

```text
0x005b0640-0x005b06a8 | retained raw helper | SelectNextTargetObject : reconstructable/marker-only covered by UID0001LK : 88% : strong : B007 MCP session `c9ac3d5b` reconfirmed the unmodeled raw start, exact next/down target traversal through `MapPane::FindNextSelectableObject`, `s_targetObjectTargetId` reads/writes, zero xref/code/data/immediate/VA/RVA route to `0x005b0640`, and active inline coverage by UID0001LK; emits only the formal covered-by marker to the key handler.
```

## Recommended Support Doc Changes

Callback application state:

- `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`
  - Applied: UID00040Z row changed from blank-emitter/no-code to marker-only covered by UID0001LK.
  - Applied: parent remains non-emitting.
  - Applied: UID00040Y preserved as already marker-only covered by UID0001LK after B006 execution (`88/90`, supervisor command `000000005362`) and UID000410 preserved as already marker-only. The parent now ends with UID00040Y, UID00040Z, and UID000410 all described as marker-only covered by UID0001LK.

- `by-class/TargetObjectWithKeyboardPane.md`
  - Applied: raw navigation helper row/evidence notes no longer read UID00040Z as a blank child.
  - Applied: UID00040Z is marker-only through UID0000ED and covered by UID0001LK next/down inline behavior.
  - Applied: post-B006 baseline that UID00040Y is already marker-only covered by UID0001LK at `88/90` is preserved.
  - Applied: class score unchanged.

- `by-file/TargetSelectionInputPanes.md`
  - Applied: TargetObject raw-helper disposition no longer describes UID00040Z as blank.
  - Applied: direct emitter UID0000ED, indirect source route UID0000OH, and generated marker output for UID00040Z are recorded.
  - Applied: post-B006 source-output baseline is preserved, and the TargetObject raw-helper family now has UID00040Y, UID00040Z, and UID000410 all marker-only in generated output.

- `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`
  - Applied: relationship note added that UID0001LK is the formal covered-by target for UID00040Z's next/down raw helper behavior.
  - Applied: caveat preserved that UID0001LK does not call the raw start; the relationship is inline coverage only.

Optional/no edit unless stale:

- `by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`: no change required; it is already the accepted marker-only sibling.
- `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`, `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`, and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: current dependency/name coverage appears sufficient.
- Generated reports, generated C++, project-level generated files, manual `-coverage-report.md` files, validator state, lifecycle/archive files, and supervisor ledgers: do not edit manually.

## Score And Metadata Recommendation

Recommended target header:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000ED
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ED
EMITTER_POSITION_OPTIONAL:
```

Why completion should rise from `85` to `88`:

- The current report resolves the blank-emitter/source-output blocker with exact formal marker text.
- It refreshes old PE/Capstone route claims with live MCP evidence from session `c9ac3d5b`.
- It confirms target bytes, boundary alignment, accepted source-facing names, dependency direction, active inline coverage, and rejected owner/source alternatives.

Why confidence should rise from `88` to `89`, but not higher:

- Strong current evidence supports behavior, owner, range, and no-route state.
- Confidence remains below `90` because no original symbol/call surface exists, IDA still does not model `0x005b0640` as a function, and the exact original source retention shape cannot be proven.

## Open Questions With Attempted Resolution

- Should UID00040Z remain blank-emitter/no-code?
  - Resolution: no. Marker-only emission through UID0000ED is safer and now matches accepted project policy for UID00040Y, UID000410, and UID0002S5.
- Should UID00040Z emit a callable `SelectNextTargetObject()` body?
  - Resolution: no. The behavior is known, but all route forms are negative and active behavior is already inline in UID0001LK.
- Should the marker target UID0001LK?
  - Resolution: yes. UID0001LK is vtable-routed and contains exact next/down behavior: event subtype check at `0x005b0180`, saved id push at `0x005b0186`, active MapPane load at `0x005b018c`, `FindObjectPaneById` at `0x005b0192`, `FindNextSelectableObject` at `0x005b01a4`, fallback at `0x005b01ad`, highlight tail at `0x005b01b7-0x005b01c6`, and saved-id clear at `0x005b01cc`.
- Should UID0000OH be a direct emitter?
  - Resolution: no. It is the source-file route; direct emission should stay with the class UID0000ED.
- Is the active key handler a caller?
  - Resolution: no. Treat as inline coverage only.
- What would change the recommendation?
  - A future direct call/jump/data/pointer/vtable route to `0x005b0640`, recovered source symbols, or an explicit retained-helper-body policy could justify a callable helper body.

## Validator Results

Scoped validators run after accepted implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality-removed.md](00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results:

| File | command_id | command_timestamp | Exit | ok | Warnings/errors | Generated refresh |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md` | `000000005388` | `2026-07-03T12:17:49-04:00` | 0 | 1 | Existing unrelated `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` warnings; no target errors. | `completed`; updated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, memory coverage, research tracker, projected stats, and validator-owned metadata. |
| `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md` | `000000005389` | `2026-07-03T12:18:04-04:00` | 0 | 1 | None for target; stats incremental noop because UID00036T is not present in generated stats lists. | `deferred`. |
| `by-class/TargetObjectWithKeyboardPane.md` | `000000005390` | `2026-07-03T12:18:10-04:00` | 0 | 1 | None for target; stats incremental noop because UID0000ED is not present in generated stats lists. | `deferred`. |
| `by-file/TargetSelectionInputPanes.md` | `000000005391` | `2026-07-03T12:18:19-04:00` | 0 | 1 | None for target; stats incremental noop because UID0000OH is not present in generated stats lists. | `deferred`. |
| `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md` | `000000005392` | `2026-07-03T12:18:28-04:00` | 0 | 1 | None for target; stats incremental noop because UID0001LK is not present in generated stats lists. | `deferred`. |

Generated freshness: B007's last scoped implementation validator was command `000000005392` at `2026-07-03T12:18:28-04:00`. A later validator-owned refresh has since advanced the current generated header for `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` to `validator-command-id: 000000005393` and `validator-refreshed-at: 2026-07-03T12:21:25-04:00`; this is newer than B007's scoped validator batch and does not change the UID00040Z result. The current generated file still contains marker-only output for UID00040Y, UID00040Z, and UID000410; UID00040Z remains present at its marker lines and is not present as an Empty Emitter Marker.

## Changed Files

Edited during accepted implementation callback:

- `tools/leaser/Agents/Agent-B007/research/00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md`
- `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md`
- `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`
- `by-class/TargetObjectWithKeyboardPane.md`
- `by-file/TargetSelectionInputPanes.md`
- `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`

Edited during this Gate 1 report-text repair only:

- `tools/leaser/Agents/Agent-B007/research/00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md`
- Normalized lifecycle/current-state wording in the header, recommendation, target/current-state, recommended changes, validator, changed-files, and checklist areas so the report stands as implementation-complete awaiting supervisor Gate 2 / execution.
- No by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited during this repair.
- No validators, `execute_report`, dry-run/probing lifecycle commands, archive moves, registry commands, manual report moves, or generated/manual coverage edits were run during this repair.

Validator-owned side effects observed, not manually edited:

- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`
- `tools/validator_autogen_backup/...`

No manual edits were made to generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers. No `execute_report`, dry-run/probing execute variant, registry/lifecycle/archive command, or manual report move was run. Leases were taken for the five edited by-* docs before the edit/validator batch; release attempted after validation returned `Rejected[No active lease]` for each because the leases had already expired, and `tools/leaser/Agents/current_leases.md` then showed no active leases.

## Implementation Tracking Checklist

Callback implementation state:

- [x] Supervisor Gate 1 validation accepted exact report SHA256 `78D5F3F0C9B7318CFFCA8A3222DAD6C1F80CDC80FEB979F275AD0D8B73FC27E3`.
- [x] Target metadata updated in `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md` to `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000ED`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ED`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Target formal block inserted exactly as marker-only covered by UID0001LK, with inline `RECONSTRUCTION_CPP CODE:[[[]]]` left blank.
- [x] Target evidence incorporated: MCP session `c9ac3d5b`, health/session facts, function lookup, no-route proof, byte/padding facts, raw disassembly behavior, UID0001LK next/down inline coverage, generated output observation, source-facing names, and rejected alternatives.
- [x] Target policy wording replaced stale blank-until-route text with source-ready marker-only policy and remaining confidence caps; no callable helper-body proof preserved.
- [x] Parent support updated in `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`: UID00040Z is marker-only covered by UID0001LK, UID00040Y remains B006 marker-only executed (`88/90`, supervisor command `000000005362`), UID000410 remains marker-only, and parent UID00036T remains non-emitting.
- [x] Class support updated in `by-class/TargetObjectWithKeyboardPane.md` with UID00040Z marker-only disposition and no-route/inline-coverage caveat, preserving B006's executed UID00040Y marker-only state.
- [x] File support updated in `by-file/TargetSelectionInputPanes.md`: UID00040Z emits through UID0000ED as marker-only under the UID0000OH file route, and generated/source-output wording ends with UID00040Y, UID00040Z, and UID000410 all marker-only covered by UID0001LK.
- [x] Key-handler support updated in `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md` with UID00040Z covered-by relationship and "inline coverage, not caller proof" caveat.
- [x] Already-present check completed: saved-target globals, active MapPane singleton, UserPane/local-player global, UID00040Y executed sibling docs, and UID000410 sibling docs were sufficient; no edits needed outside the five listed support docs.
- [x] Rejected alternatives preserved: no MapPane/UserPane/LivingObjectPane ownership, no direct UID0000OH emitter, no dual emitter, no helper-body C++, no caller-proof wording, no reconstructable downgrade, and no IDA DB edits.
- [x] Scoped validators run and recorded in `Validator Results`: commands `000000005388` through `000000005392`, all exit `0`, all `ok: 1`.
- [x] Generated `TargetSelectionInputPanes.cpp` inspected after generated refresh only as output; B007's last scoped validator was `000000005392`, the current generated header has since advanced to validator command `000000005393` at `2026-07-03T12:21:25-04:00`, and UID00040Z marker output remains present without an Empty Emitter Marker.
- [x] Claim And Incorporation Ledger updated so every accepted claim is `applied`.
- [x] Gate 1 repair after callback normalized stale report-only/pre-callback wording: current state is implementation-complete, target is `88/89` with `EMITTER_UIDS:0000ED`, generated UID00040Z marker is present, report is not executed yet, and no lifecycle/archive/execute command was run during the repair.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000005395","destination_path":"executed-b-agent-research/B007/00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md","timestamp":"2026-07-03T12:30:12-04:00","uid":"00040Z"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00040Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
