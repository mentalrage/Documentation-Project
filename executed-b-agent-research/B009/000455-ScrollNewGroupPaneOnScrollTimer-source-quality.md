** TARGET-REPORT-UID:000455 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000455 ScrollNewGroupPaneOnScrollTimer Source-Quality Research

## Finalized Report / Current Recommendation

Keep [UID:000455] `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md` as an exact reconstructable `ScrollNewGroupPane` timer callback child emitted through [UID:0000CL] `ScrollNewGroupPane`, with source-file ancestry through [UID:0000JS] `Group`.

Supervisor Gate 1 accepted this report, and the implementation callback has been applied target-only. The target page now contains the live B009 MCP recheck, metadata is raised from `86/89` to `88/90`, and `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:48`, and the existing formal C++ block remain unchanged.

No support by-* doc edits were required. Current class, file, parent split, helper, and vtable-data docs already carry the needed owner/source-route and stale-name corrections.

## Supporting Research

Initial research was report-only. During the supervisor-accepted implementation callback, I edited only the target by-memory page and this report. I did not manually edit support by-* docs, generated files, coverage reports, validator state, supervisor ledgers, lifecycle headers/footers, archives, or executed reports. I did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, archive moves, or broad validators.

MCP was available for this resumed pass and for the implementation callback precheck. Direct live IDA evidence is current for session `b001-0001I5`; old reports and generated-output references are used only as lead material or consistency checks.

## Target

- Target UID: `000455`.
- Target path: `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md`.
- Assigned report path: `tools/leaser/Agents/Agent-B009/research/000455-ScrollNewGroupPaneOnScrollTimer-source-quality.md`.
- Current target state after callback: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter `0000CL`, reconstructable `TRUE`, emitter position `48`, formal first-draft C++ populated unchanged.
- Current target summary: `ScrollNewGroupPane` timer/repeat callback; checks timer id zero, updates active interaction, reschedules a 30 ms repeat while active, and returns true.

## Current Target State

The current page is now updated with the accepted B009 evidence:

- Direct owner and emitter are [UID:0000CL] `ScrollNewGroupPane`.
- Source route is [UID:0000CL] `ScrollNewGroupPane` through [UID:0000JS] `Group` / `NexusTK/social/Group.cpp`.
- Parent split index is [UID:0001GP] `0x00560900-0x0056141f.ScrollNewGroupPaneCore`.
- The existing source-facing name `OnScrollTimer` replaces stale `OnSelectionChanged` wording and is supported by timer-id, active-part, and scheduling evidence.
- The formal C++ body is behavior-correct and remains unchanged.

The former weakness was not behavior or ownership; the page cited accepted B005 evidence but lacked stronger live subobject ABI explanation, exact byte/signature proof, current boundary recheck, and schedule-wrapper/callee facts. The callback added those facts and justified the implemented `88/90` score.

## Heuristic / Inference Reanalysis And Validation

The strongest live inference nuance is the adjusted receiver:

- Hex-Rays models `sub_560D00` as `char __thiscall sub_560D00(_BYTE *this, int a2, int a3, int a4)`.
- In this callback, `this` is the TimerHandler/update-handler subobject at `ScrollNewGroupPane + 0xa4`, not the complete `ScrollNewGroupPane *`.
- The instruction `cmp byte ptr [esi+60h], 0FFh` therefore reads effective class offset `0xa4 + 0x60 = 0x104`, matching `m_activePart`.
- The instruction `lea ecx, [esi-0A4h]` recovers the complete owner before calling `sub_561B00`, matching `ScrollNewGroupPane::UpdateActiveInteraction()`.
- The later `mov ecx, esi; call sub_5975E0` schedules through the timer subobject, matching the accepted `ScheduleTimer(0, 30, 0, 0)` source-facing wrapper.

This resolves the apparent offset mismatch between Hex-Rays `this[96]` and the class field table `m_activePart` at `+0x104`. It also confirms that the source-level formal C++ should stay class-oriented rather than copying the decompiler's `_BYTE *this` form.

## Evidence Standards Used

- Direct IDA MCP facts outrank current prose, generated output, and old reports.
- Current by-* docs outrank generated summaries when they disagree.
- Executed B-agent reports are lead material after search-gating; their facts were rechecked live where relevant.
- Inference is acceptable only when labeled, behavior-backed, and not used to claim recovered original source spellings.
- Formal C++ must be source-shaped and must not import decompiler temporaries or adjusted-subobject implementation details unless those are actual source concepts.

## Evidence Checked

Current docs checked:

- `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md`
- `by-class/ScrollNewGroupPane.md`
- `by-file/Group.md`
- `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
- `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`
- `by-memory/0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md`
- `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`

Old/executed report leads checked with terms including `TARGET-REPORT-UID:000455`, `UID:000455`, `000455`, `0x00560d00`, `0x00560d33`, `ScrollNewGroupPaneOnScrollTimer`, `OnScrollTimer`, `OnSelectionChanged`, `UpdateActiveInteraction`, and `ScheduleTimer`:

- No exact prior standalone `TARGET-REPORT-UID:000455` report was found.
- Relevant executed leads opened or searched: B005 `0001GP-ScrollNewGroupPaneCore-source-quality.md`, B002 `0000JS-Group-empty-emitter-family-source-quality.md`, B008 `0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md`, B005 `000454-ScrollNewGroupPaneCanScroll-source-quality.md`, and analogous B012 `000435-ScrollPaneOnScrollTimer-source-quality.md`.

Live MCP tools used read-only on session `b001-0001I5`: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `entity_query`, and `make_signature_for_range`.

## Claim And Incorporation Ledger

| Claim | Action / destination | Verification state | Implementation note |
| --- | --- | --- | --- |
| UID000455 is an exact modeled function at `0x00560d00-0x00560d33`. | incorporate in target MCP/evidence and score rationale | applied | Target now records B009 `lookup_funcs` neighborhood facts, size `0x33`, non-function end/padding, exact bytes, and unique signature. |
| The receiver is the TimerHandler/update-handler view at `ScrollNewGroupPane+0xa4`. | incorporate in target reconstruction notes | applied | Target now records `this[96]`, `lea ecx,[esi-0A4h]`, scheduling on `esi`, and effective class `m_activePart +0x104` mapping. |
| The function is vtable/data reached, not directly code-called. | incorporate in target xref evidence | applied | Target now records B009 `xrefs_to 0x00560d00` one data ref from `0x00623f9c` and no direct code caller; vtable support was already present. |
| Timer id zero and active part not `0xff` gate the repeat body. | incorporate in target behavior/evidence | applied | Target now records the disassembly/decompile facts for the timer-id check and active-part sentinel check. |
| The body calls `UpdateActiveInteraction()` and `ScheduleTimer(0,30,0,0)`. | incorporate in target evidence and preserve formal C++ | applied | Target now records callees `sub_561B00` and `sub_5975E0`, helper xref at `0x00560d18`, and schedule-wrapper forwarding evidence. |
| The target can rise above `86/89`. | incorporate metadata and score rationale | applied | Target header is now `COMPLETION:88` and `CONFIDENCE:90`; scoped validator `000000007629` accepted both updates. |
| It should not rise to final-audit scores. | incorporate target open-question/score-cap wording | applied | Target now records source-name/type uncertainty, exact TimerHandler declaration caveat, and class/header pass cap. |
| Support docs do not require edits for this target-only improvement. | already-present in support docs | already-present | Class, file, parent split, helper, and vtable pages already document `OnScrollTimer`, stale-name rejection, owner route, `+0x104`, `this+0xa4`, and helper linkage; no support docs were edited. |

## Positive Evidence Summary

- MCP `server_health` for `b001-0001I5` returned `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, imagebase `0x400000`.
- `lookup_funcs` reports `0x00560d00 -> sub_560D00`, size `0x33` / 51 bytes.
- `disasm` reports 20 instructions and exact handled-return shape: timer-id compare, active-part sentinel compare, owner recovery, update call, schedule call, `mov al,1`, `retn 0Ch`.
- `decompile` matches the existing formal C++ behavior: if timer id is zero and active part is not `0xff`, call `sub_561B00(this - 164)`, call `sub_5975E0(this, 0, 30, 0, 0)`, return `1`.
- `callees 0x00560d00` reports only `sub_561B00` and `sub_5975E0`, matching `UpdateActiveInteraction` and `ScheduleTimer`.
- `xrefs_to 0x00560d00` reports one data ref from `0x00623f9c`; `entity_query` also finds the `ScrollNewGroupPane` vtable names at `0x00623f1c`, `0x00623f68`, and `0x00623f98`.
- `xrefs_to 0x00561b00` reports calls from `0x00560c73`, `0x00560d18`, and raw `0x00561ad2`; the target's call is one of the documented active-interaction callsites.
- `get_bytes 0x00560cf5` shows `0xcc` padding before the target prologue; `get_bytes 0x00560d00` exactly matches the body; bytes after `0x00560d33` are `0xcc` padding before `0x00560d40`.
- `make_signature_for_range 0x00560d00-0x00560d33` returned a unique exact signature:
  `55 8B EC 83 7D 08 00 56 8B F1 75 20 80 7E 60 FF 74 1A 8D 8E 5C FF FF FF E8 E3 0D 00 00 6A 00 6A 00 6A 1E 6A 00 8B CE E8 B4 68 03 00 B0 01 5E 5D C2 0C 00`.

## IDA MCP Facts

Live function and boundary facts:

- `0x00560cf0`: `sub_560CF0`, size `0x5`, preceding `CanScroll` false/default virtual.
- `0x00560cf5`: not a function; padding before the timer callback.
- `0x00560d00`: `sub_560D00`, size `0x33`, target.
- `0x00560d31` and `0x00560d32`: inside `sub_560D00`.
- `0x00560d33` and `0x00560d3f`: not functions; padding before paint.
- `0x00560d40`: `sub_560D40`, size `0x6e0`, `OnPaint` successor.
- `0x00561b00`: `sub_561B00`, size `0xc0`, `UpdateActiveInteraction` callee.
- `0x005975e0`: `sub_5975E0`, size `0x1f`, accepted TimerHandler schedule wrapper.

Live target disassembly facts:

```asm
00560d03  cmp [ebp+arg_0], 0
00560d08  mov esi, ecx
00560d0a  jnz loc_560D2C
00560d0c  cmp byte ptr [esi+60h], 0FFh
00560d10  jz loc_560D2C
00560d12  lea ecx, [esi-0A4h]
00560d18  call sub_561B00
00560d1d  push 0
00560d1f  push 0
00560d21  push 1Eh
00560d23  push 0
00560d25  mov ecx, esi
00560d27  call sub_5975E0
00560d2c  mov al, 1
00560d30  retn 0Ch
```

Live Hex-Rays output:

```cpp
char __thiscall sub_560D00(_BYTE *this, int a2, int a3, int a4)
{
  if ( !a2 && this[96] != 0xFF )
  {
    sub_561B00((int)(this - 164));
    sub_5975E0(this, 0, 30, 0, 0);
  }
  return 1;
}
```

The decompiler output should be documented as ABI evidence, not copied into formal source C++.

## Function / Child Inventory

| Range | Current item | Disposition for this report |
| --- | --- | --- |
| `0x00560cf0-0x00560cf5` | [UID:000454] `ScrollNewGroupPaneCanScroll` | Predecessor exact child; confirms previous modeled body ends before padding. |
| `0x00560cf5-0x00560d00` | padding | No child; live bytes are `0xcc`. |
| `0x00560d00-0x00560d33` | [UID:000455] `ScrollNewGroupPaneOnScrollTimer` | Target exact child; keep reconstructable and formal C++. |
| `0x00560d33-0x00560d40` | padding | No child; live bytes are `0xcc`. |
| `0x00560d40-0x00561420` | [UID:000456] `ScrollNewGroupPaneOnPaint` | Successor exact child. |

No split, merge, rename, or range change is recommended for UID000455.

## Direct Xref / Caller Inventory

- Direct xref to target: one data xref from `0x00623f9c`.
- No direct code caller was reported by `analyze_function`; this is expected for a virtual/timer callback slot.
- Current vtable docs already explain `0x00623f9c` as the secondary `+0x34`/tertiary callback exposure for `OnScrollTimer`.
- Direct call from target to helper: `0x00560d18 -> 0x00561b00`, confirmed by `xrefs_to 0x00561b00`.
- Direct call from target to timer wrapper: `0x00560d27 -> 0x005975e0`.

## Documentation Evidence And IDA Status

- The target page already records owner/emitter `0000CL`, source route through `Group`, accepted B005 evidence, vtable data ref `0x00623f9c`, and first-draft C++.
- `ScrollNewGroupPane.md` already records `OnScrollTimer` at `0x00560d00-0x00560d33`, `m_activePart` at `+0x104`, and the `this+0xa4` timer/update-handler view.
- `ScrollNewGroupPaneCore.md` already records the target row as an exact child and preserves padding rows before/after it.
- `ScrollNewGroupPaneUpdateActiveInteraction.md` already records the target callsite `0x00560d18`, helper behavior, and fields consumed by the callback.
- `ScrollNewGroupPaneVtableData.md` already records `0x00560d00` as `OnScrollTimer` and rejects stale `OnSelectionChanged` prose.
- `Group.md` already lists UID000455 in the `ScrollNewGroupPane` child set and preserves the source route.

Support docs are consistent enough that the implementation callback should not edit them merely to repeat this target's live evidence.

## Ranked Ownership Analysis

1. [UID:0000CL] `ScrollNewGroupPane` is the direct owner and emitter. This is strongly supported by vtable names, constructor-installed vtable views, class field offsets, the complete-object recovery `this-0xa4`, helper ownership, and current class/file docs.
2. [UID:0000JS] `Group` is the source-file ancestor, not the direct method owner. It should remain the file route through `NexusTK/social/Group.cpp`.
3. Generic ScrollPane/ScrollBar ownership is rejected. It is useful pattern evidence because generic `ScrollPaneOnScrollTimer` has an analogous TimerHandler-adjusted body, but the live target's vtables, fields, helper calls, and source route are `ScrollNewGroupPane`.
4. Stale `OnSelectionChanged` ownership/name evidence is rejected. The body does not handle selection state; it checks a timer id, consumes active scroll state, and schedules repeat work.

## Source Placement

Source placement remains [UID:0000CL] `ScrollNewGroupPane` emitted through [UID:0000JS] `Group` / `NexusTK/social/Group.cpp`. The target is a class method exposed through an adjusted timer/callback vtable view; that ABI detail should be recorded in prose but should not move the source body to a standalone TimerHandler owner.

## Range / Split / Padding / Reclassification Analysis

The current target range is exact and should not be reclassified:

- The target starts at the IDA-modeled function prologue `0x00560d00`.
- The modeled size is `0x33`, matching the half-open end `0x00560d33`.
- `0x00560cf5-0x00560d00` and `0x00560d33-0x00560d40` are alignment padding.
- The predecessor and successor are separate accepted children.
- The target body is not compiler padding, a thunk-only helper, or a broad aggregate.

## Negative Evidence Summary

- No original source symbol, UDT, or exact source header signature was recovered by MCP.
- The live function has no direct code caller; reachability is through vtable/data, which is expected but caps final-audit confidence.
- Hex-Rays reports a `char` return and adjusted `_BYTE *this` receiver. These are ABI/decompiler artifacts; they should not replace the current source-shaped `bool ScrollNewGroupPane::OnScrollTimer(int timerId, int, int)` formal block.
- `UpdateActiveInteraction`, `ScheduleTimer`, `m_activePart`, and `kScrollNewGroupPartNone` remain source-facing project names inferred from behavior and support docs, not recovered original symbols.
- The class-level declaration/header for `ScrollNewGroupPane` remains below final audit, so this exact child should not be raised to a near-final score.
- No support-doc contradiction was found that requires an implementation callback beyond the target page.

## IDA Rename / Type / Comment Recommendations

No IDA database edits are authorized or needed for this report.

Optional future IDA curation, if a supervisor-owned IDA annotation pass exists:

- Name `sub_560D00` as `ScrollNewGroupPane::OnScrollTimer` or an equivalent project-safe callback name.
- Preserve a comment/type note that the machine-code receiver is the TimerHandler/update-handler view at complete object `+0xa4`, while source reconstruction is owned by `ScrollNewGroupPane`.

## First-Draft C++ Recommendation

Keep the existing formal C++ unchanged:

```cpp
bool ScrollNewGroupPane::OnScrollTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollNewGroupPartNone) {
        UpdateActiveInteraction();
        ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}
```

The two unnamed trailing parameters are correct because the body ignores them. The boolean return is source-shaped and matches the `mov al,1` handled-return behavior. The adjusted receiver should be documented in prose, not exposed in final C++.

## Final Recommendation

UID000455 is ready for supervisor Gate 2 verification and report execution:

- The target page contains the accepted `2026-07-06 B009 live MCP recheck` evidence.
- Score metadata is `COMPLETION:88` and `CONFIDENCE:90`.
- Owner/emitter/reconstructable/position/formal C++ are unchanged.
- The scoped target-file validator passed as command `000000007629`.

No support by-* docs were edited because accepted support facts were already present. No generated, coverage, lifecycle, archive, supervisor-ledger, or validator-state files were manually edited.

## Recommended Target Doc Changes

Target path: `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md`.

Implemented in the target:

- Header metadata changed from `COMPLETION:86` / `CONFIDENCE:89` to `COMPLETION:88` / `CONFIDENCE:90`.
- `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, and `EMITTER_POSITION_OPTIONAL:48` are unchanged.
- The formal C++ block is unchanged.
- Current B009 MCP facts were added: session `b001-0001I5`, healthy Hex-Rays, `lookup_funcs` size `0x33`, exact disassembly/decompile facts, unique exact signature, vtable/data xref `0x00623f9c`, active-part mapping from `this[96]` to class `+0x104`, owner recovery through `this-0xa4`, `sub_561B00` and `sub_5975E0` callees, and padding boundaries.
- Score rationale now explains why the target rises to `88/90` but remains capped by unrecovered original source names/types.
- Open-question/cap wording now states that `OnScrollTimer`, `ScheduleTimer`, `UpdateActiveInteraction`, and enum/field names are accepted source-facing names, not recovered symbols.

Implemented item summary:

`TimerHandler-adjusted ScrollNewGroupPane repeat callback; for timer id 0 and active part present, updates active interaction through the owner object, reschedules a 30 ms timer, returns true, and carries first-draft C++.`

## Recommended Support Doc Changes

No mandatory support edits.

Already-present support:

- `by-class/ScrollNewGroupPane.md` already documents `OnScrollTimer`, `m_activePart +0x104`, and `this+0xa4`.
- `by-file/Group.md` already routes UID000455 through the Group source family.
- `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md` already records the exact child and padding rows.
- `by-memory/0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md` already documents `0x00560d18` as a caller and describes the callee behavior.
- `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md` already records the secondary/tertiary `OnScrollTimer` slot and stale-name rejection.

## Score And Metadata Recommendation

- Before callback: `86/89`, owner/emitter `0000CL`, reconstructable `TRUE`, position `48`, formal C++ present.
- After callback: `88/90`, owner/emitter `0000CL`, reconstructable `TRUE`, position `48`, formal C++ unchanged.

Reason for increase:

- Live MCP confirms exact boundaries, unique bytes, full branch/callee behavior, vtable reachability, adjusted receiver mapping, helper linkage, and scheduler wrapper role.
- The current formal C++ is verified against the binary rather than treated as proof.
- Support docs are consistent and source placement is settled.

Reason not higher:

- Original source symbols and exact UDT/callback declaration are not recovered.
- Source-facing helper, field, enum, and wrapper names remain behavior-backed inferences.
- Whole-class `ScrollNewGroupPane` declaration/header audit is not complete.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Result |
| --- | --- | --- |
| Is UID000455 an exact function or a split/padding artifact? | Checked `lookup_funcs`, surrounding functions, bytes, and signature. | Resolved: exact modeled function `0x00560d00-0x00560d33`; padding before and after. |
| Does the body really use `m_activePart +0x104`? | Checked Hex-Rays, disassembly, class field docs, and timer subobject offset. | Resolved: decompiler `this[96]` maps to complete-object `+0x104` because receiver is `this+0xa4`. |
| Is `OnSelectionChanged` still plausible? | Checked body gates, scheduling call, vtable/support docs, and B005 stale-name correction. | Resolved: no; `OnScrollTimer`/timer callback is the correct source-facing role. |
| Should formal C++ change to expose the adjusted receiver? | Compared source-shape rules, current C++ block, decompiler output, and support docs. | Resolved: no; keep class method formal C++ and document ABI detail in prose. |
| Are support docs stale or contradictory? | Checked class, file, parent split, helper, and vtable docs. | Resolved: no mandatory support edits. |
| Can score rise above `88/90`? | Checked for recovered symbols/types and final declaration evidence. | Not resolved; no original names/UDT recovered, so `88/90` is the justified cap. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not edit manual `-coverage-report.md` files or generated tracker/coverage files during this B-agent report-only phase.

The scoped target validator refreshed validator-owned generated/tracker outputs under command `000000007629`. No manual coverage/tracker text is required.

## Follow-Up Actions

- Supervisor Gate 2: verify the target page, this updated ledger/checklist, validator command `000000007629`, and generated freshness notes.
- If Gate 2 passes, supervisor may run the supervisor-owned `execute_report` lifecycle command.
- No B009 follow-up is blocked or pending for the accepted scope.

## Confidence

High for range, reachability, owner, source route, callback semantics, and formal C++ body. Medium-high for exact score because source-facing names and type declarations remain inferred rather than recovered.

Overall report confidence: `90`.

## Validator Results

Scoped validator run during the implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [000455-ScrollNewGroupPaneOnScrollTimer-source-quality-removed.md](000455-ScrollNewGroupPaneOnScrollTimer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Working directory: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Exit code: `0`.
- `command_id`: `000000007629`.
- `command_timestamp`: `2026-07-06T18:47:10-04:00`.
- `ok`: `1`.
- Target updates reported: `completion_update 000455 ... 88`; `confidence_update 000455 ... 90`.
- Other validator output: `projected_stats_update: 1`, `stats_incremental_noop: 1`.
- Generated refresh result: validator initially reported `generated_refresh: deferred`; read-only freshness checks then showed `auto-generated/NexusTK/social/Group.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md` at `validator-command-id: 000000007629` / `validator-refreshed-at: 2026-07-06T18:47:10-04:00`.
- Generated current-state checks: `Group.cpp` shows UID000455 `Completion:88 | Confidence:90`; `-ag-research-tracker.md` shows UID000455 `88/90`, combined `89.0`; `-ag-coverage-report-by-memory.md` shows UID000455 reconstructable `88% : very-strong`.
- Queue-status check after generated refresh: command `000000007630`, timestamp `2026-07-06T18:47:36-04:00`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.

No broad validators, `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, archive moves, or manual generated/coverage edits were run.

## Changed Files

- Modified: `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md`
- Modified: `tools/leaser/Agents/Agent-B009/research/000455-ScrollNewGroupPaneOnScrollTimer-source-quality.md`

Validator-owned/generated side effects observed from scoped validation, not manually edited: `project-level/-auto-completion-stats.md`, `auto-generated/NexusTK/social/Group.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.

No support by-* docs, manual coverage reports, validator state files, supervisor ledgers, lifecycle headers/footers, archives, or executed reports were manually edited.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read current B009 `goal.md` and applied the project-level `ntk-b-agent-workflow` instructions.
- [x] Used live IDA MCP evidence from session `b001-0001I5`; stopped fallback-only behavior was not needed because MCP stayed available.
- [x] Checked target, class, file, parent split, helper, vtable, and relevant executed-report leads.
- [x] Treated current formal C++ as a lead and verified it against decompile, disassembly, xrefs, callees, bytes, and support docs.
- [x] Resolved the adjusted-receiver/field-offset nuance and recorded the target-only score recommendation.
- [x] Confirmed no mandatory support by-* edits are required if accepted.
- [x] Supervisor Gate 1 validation required before any by-* implementation edit. Proof: updated `goal.md` records Gate 1 accepted in `tools/leaser/Agents/b-report-validation-audit.md`, entry `2026-07-06T18:43:34-04:00 - B009 UID000455 Gate 1 Audit`, accepted SHA256 `2C07B43CAE0F3F167361CD3368CF0EB1DFF682647DCD1CE2F0BA2C1DE02E0E89`.

Implementation callback pass:

- [x] Edit only `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md` among by-* docs. Proof: support docs were checked for contradiction and left unchanged because accepted facts were already present.
- [x] Update target metadata to `COMPLETION:88` and `CONFIDENCE:90`; keep owner/emitter/reconstructable/position/formal C++ unchanged. Proof: target header and validator command `000000007629` report `completion_update 000455 ... 88` and `confidence_update 000455 ... 90`.
- [x] Add live B009 MCP evidence for function range, bytes/signature, xrefs, subobject receiver, callees, schedule wrapper, and boundary padding. Proof: target `Address Range And Boundary`, `Behavior`, `Evidence`, and `Reconstruction Notes` now include these details from session `b001-0001I5`.
- [x] Add score rationale and open-question/cap wording for unrecovered source names/types. Proof: target now has `Score Rationale` and `Open Questions And Score Caps` sections.
- [x] Preserve stale-name rejection for `OnSelectionChanged`. Proof: target `Behavior` retains the stale-name rejection, and support docs already had same-or-greater detail.
- [x] Run only the scoped target-file validator and record command id/timestamp/exit/ok. Proof: `Validator Results` records command `000000007629`, timestamp `2026-07-06T18:47:10-04:00`, exit `0`, `ok:1`.
- [x] Do not edit support docs unless the supervisor explicitly expands scope. Proof: no support by-* docs were changed in this callback.
- [x] Do not run `execute_report`, lifecycle/archive commands, broad validators, manual report moves, generated/coverage edits, validator-state edits, or supervisor-ledger edits. Proof: only the scoped target validator and read-only queue/freshness checks were run; generated/project-level outputs refreshed through validator-owned mechanisms only.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000007643","destination_path":"executed-b-agent-research/B009/000455-ScrollNewGroupPaneOnScrollTimer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/000455-ScrollNewGroupPaneOnScrollTimer-source-quality.md","timestamp":"2026-07-06T18:57:13-04:00","uid":"000455"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000455-ScrollNewGroupPaneOnScrollTimer-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/000455-ScrollNewGroupPaneOnScrollTimer-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000455"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
