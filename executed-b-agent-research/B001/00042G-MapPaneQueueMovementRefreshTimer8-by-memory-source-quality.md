** TARGET-REPORT-UID:00042G **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00042G MapPaneQueueMovementRefreshTimer8 Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00042G] `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md` as reconstructable `MapPane` source-shaped code owned by [UID:00007Q], with blank `EMITTER_UIDS` and blank formal C++ because current IDA MCP still proves no entry route.
- Final disposition: improve the target page, not the ownership route. The page should record the current instruction-level behavior, the target-coordinate conversion, the modal-input-blocker gate, `TimerHandler::ScheduleTimer(8, 44, 0, 0)`, and the `0x005449d0` Pane capture helper call. The current "refreshes" wording is too imprecise for this target; `0x005449d0` is capture-style, while the release/refresh-side helper in the clearer path is `0x005449f0`.
- Required action: implementation callback completed on 2026-07-01 after supervisor acceptance. Supervisor verification is required before report execution.
- Confidence: strong for range, body behavior, MapPane ownership, and no-route evidence; medium-high for final original helper and field spellings.

## Target

- Target UID: `00042G`
- Target path: `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `85/85`, combined `85.0`, reconstructable `true`, reports `0`.
- Current supervisor assignment: `B001-implement-00042G-MapPaneQueueMovementRefreshTimer8-by-memory-20260701`, accepted implementation callback.
- Current scores and parent state: target `85/85`; `CANONICAL_OWNER:00007Q`; `RECONSTRUCTABLE:TRUE`; blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, no emitter route.
- Existing owner/emitter state: owner is [UID:00007Q][MapPane]; MapPane class emits through [UID:0000L3][MapPane] but this raw child has no proven entry route, so it does not emit.
- Existing C++/emitter state: formal C++ block is blank.
- Existing blockers: target body is documented only at summary level; it lacks current instruction-level evidence, callee role detail, field/global roles, boundary proof from current bytes, and an explicit no-code proof under the current code-entry gate.
- Related docs checked: target page, `by-memory/-guidance.md`, `by-structure.md`, [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane`, [UID:0001AP] `MapPaneWeatherCoordinateObjectCore`, [UID:00042E], [UID:00042F], [UID:00042H], [UID:0003ZS], [UID:0001K8] `TimerHandlerScheduleRemoveWrappers`, [UID:0000T7] `MapTilePixelDimensions`, and [UID:0002W8] `InputBlockerPaneSingleton`.

## Evidence Checked

- IDA MCP session: `supervisor_resume_20260629`; `server_health` call `10` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- Tool schema/current session: `initialize` calls `1`, `tools/list` calls `2/3`, `idb_list` call `4`.
- MCP target checks:
  - `lookup_funcs` call `11`: `0x00505d00`, `0x00505d01`, and `0x00505d97` are `Not a function`; sibling `0x00505cc0` is modeled as `sub_505CC0`; `0x00505da0` is also `Not a function`.
  - `insn_query` call `12`: exact range `0x00505d00-0x00505d9a` contains 45 decoded instructions, no owning IDA function, prologue at `0x00505d00`, and `retn 8` at `0x00505d97`.
  - `xrefs_to` call `13` and `xref_query` call `23`: zero incoming code refs and zero incoming data refs to `0x00505d00`; only fallthrough-style internal xrefs from the first instruction to following instructions.
  - `find_bytes` calls `14` and `30`: no hits for little-endian VA `00 5D 50 00`; no hits for RVA-style `00 5D 10 00`; no hits for raw-offset-style `00 51 10 00`.
  - `get_bytes` call `15`: `0x00505cf9-0x00505d00` and `0x00505d9a-0x00505da0` are `0xcc` alignment around the target; target bytes end with `5f 5e 5d c2 08 00`.
  - `lookup_funcs`/`analyze_function`/`decompile` calls `20-22`: `0x005449d0` is a modeled `sub_5449D0` helper, size `0x19`, decompiling to a call through `unk_67AB30` with `this + 0xa0`; support docs identify it as `Pane::CaptureMouse` / capture-style input state.
  - `disasm`/`insn_query` calls `24-26`: sibling `00042F`, `00042E`, and `00042H` were checked for timer-state relationships and the `0x005449d0` versus `0x005449f0` distinction.
- Report/documentation searches:
  - Exact terms searched: `00042G`, `0x00505d00`, `0x00505d9a`, `MapPaneQueueMovementRefreshTimer8`, `Timer8`, `0x00505d97`, and later exact `[UID:00042G]`.
  - Relevant executed report opened/used: `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`.
  - Stale UID-collision leads found and rejected: `executed-b-agent-research/B001/0001BR-SpellMenuDialogs-source-quality.md` and current SpellMenu docs still contain stale `[UID:00042G]` references whose prose describes the older `0x0051d700-0x0051db38.ServerSpellMenuItemList` target. These are not evidence for this MapPane target.
- Failed/skipped checks: one MCP `search_text` attempt used the wrong current schema and was not used as evidence. Local `rg` and exact MCP xref/byte searches were sufficient for the route and stale-doc checks.

## Positive Evidence Summary

- The body is real source-shaped code: prologue, `this` in `ecx` moved to `edi`, two stack arguments loaded from `[ebp+8]` and `[ebp+0xc]`, MapPane field writes, global word reads, division by tile dimensions, timer scheduling, and `retn 8`.
- The body writes `[MapPane+0x8ec]` and `[MapPane+0x8f0]`, converts those pixel arguments to tile-space pending target coordinates using `word_66DAA0` and `word_66DA9C`, adds `m_tileOriginY - 1` and `m_tileOriginX - 1` through fields `+0x400` and `+0x3fc`, sleeps 100 ms, then queues timer event `8` with delay `0x2c` / 44 ms.
- It sets `MapPane+0x39d` only when the queued flag is clear and `g_pInputBlockerPane` / `0x0069b4cc` is null. That matches [UID:0003ZS] timer event `8`, [UID:00042F] cancellation of event ids `6` and `8`, and the MapPane class field glossary.
- It calls `TimerHandler::ScheduleTimer` through `lea ecx, [edi+0xa4]`, proving the same embedded timer-handler facet used by the modeled timer handler.
- It calls `0x005449d0` after scheduling. Current MCP and support docs support a Pane capture-style role (`Pane::CaptureMouse`), not the `0x005449f0` release/refresh helper used by the clearer path.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` reports target start and target tail as not modeled functions; `insn_query` decodes the full raw body from `0x00505d00` through `0x00505d97`.
- Boundary facts: `0x00505cf9-0x00505d00` and `0x00505d9a-0x00505da0` are `0xcc` alignment; the target includes the `retn 8` immediate bytes and has half-open end `0x00505d9a`.
- Key instruction facts:
  - `0x00505d0c` writes first argument to `[edi+0x8ec]`.
  - `0x00505d15` writes second argument to `[edi+0x8f0]`.
  - `0x00505d1b` and `0x00505d2b` read `word_66DAA0` / `word_66DA9C`.
  - `0x00505d3d-0x00505d55` adjusts by MapPane origin fields `+0x3fc/+0x400`.
  - `0x00505d5b` calls `Sleep` after pushing `0x64`.
  - `0x00505d61` checks `+0x39d`; `0x00505d6a` checks `0x0069b4cc`.
  - `0x00505d79` pushes timer id `8`; `0x00505d77` pushes delay `0x2c`; `0x00505d88` calls `0x005975e0`.
  - `0x00505d81` sets `+0x39d` to `1`; `0x00505d8f` calls `0x005449d0`.
- Negative IDA facts: no incoming code/data xrefs to `0x00505d00`; no VA/RVA/raw pointer-byte hits for the target start; no vtable/table/name route found in current docs or MCP facts.

## Heuristic / Inference Reanalysis And Validation

- Best source-facing role: raw no-route `MapPane` helper that queues the timer-8 path-follow / auto-action movement state from a pixel coordinate pair, captures Pane input state, and starts event `8`.
- Owner validation: the body reads and writes MapPane instance fields (`+0x39d`, `+0x3fc`, `+0x400`, `+0x8ec`, `+0x8f0`), uses the MapPane embedded `TimerHandler` at `+0xa4`, and uses MapPane tile-dimension globals and timer-handler documentation. [UID:00007Q] remains the best direct owner.
- Route validation: no modeled function, no start xrefs, and no pointer patterns were found. Sibling raw helpers [UID:00042E] and [UID:00042H] share the same no-route condition; modeled sibling [UID:00042F] proves the same timer flag is live but does not create an entry route for this raw target.
- Source-placement inference: the source family remains `NexusTK/map/MapPane.cpp` via [UID:00007Q] -> [UID:0000L3], but this exact raw helper should not emit until the project adopts a retained raw-helper emission policy or a real caller/registration route is found.
- Corrected assumption: target prose should not say the final call "refreshes" unless it is specifically distinguishing `0x005449f0`. For this target, the observed callee is `0x005449d0`, which current evidence supports as capture-style pane input state.
- Rejected alternatives:
  - TimerHandler/TimerMgr ownership: rejected because `TimerHandler` is only a scheduler dependency and receiver facet; MapPane fields drive the behavior.
  - Pane/generic input ownership: rejected because `0x005449d0` is only a callee after MapPane timer-state setup.
  - `MapTilePixelDimensions` ownership: rejected because the globals are coordinate constants consumed by the helper, not the source owner.
  - InputBlocker ownership: rejected because `g_pInputBlockerPane` is a guard that prevents scheduling, not the owner.
  - SpellMenu ownership: rejected as stale UID-collision contamination.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane

- Evidence for: direct MapPane field writes/reads, embedded timer-handler facet at `+0xa4`, sibling MapPane timer pages, [UID:0003ZS] event-8 consumer semantics, and existing [UID:0001AP] aggregate membership.
- Evidence against: no callable entry route to this raw body.
- Decision: keep as direct owner. Lack of route affects `EMITTER_UIDS` and formal C++, not semantic ownership.

### 2. [UID:0000L3] MapPane file root

- Evidence for: the class routes to `NexusTK/map/MapPane.cpp`; file root documents the raw no-route children as MapPane source-shaped evidence.
- Evidence against: the body uses `this` and MapPane instance fields, so the direct semantic owner is the class, not the file root.
- Decision: source placement through file root only; do not replace `CANONICAL_OWNER:00007Q`.

### 3. TimerHandler / TimerMgr

- Evidence for: the body schedules event `8` through `0x005975e0`.
- Evidence against: the scheduled owner is `MapPane+0xa4`; generic wrapper docs place only the wrapper under TimerHandler/TimerMgr; target behavior is MapPane state setup.
- Decision: dependency only.

### 4. No-owner / non-reconstructable / padding

- Evidence for: no IDA function and no entry route.
- Evidence against: source-shaped body, MapPane fields, calls, imports, and real return; adjacent bytes are padding but the target body is not.
- Decision: reject. Keep reconstructable true, owner MapPane, non-emitting.

## Source Placement

- Recommended source file/class placement: `MapPane` class helper in `NexusTK/map/MapPane.cpp`, direct owner [UID:00007Q], source route through [UID:0000L3] only when a future emitter route exists.
- Why this fits: the helper prepares the same pending target/action coordinate block consumed by `MapPane::OnTimerEvent` event id `8`.
- Rejected placements: TimerMgr/TimerHandler, generic Pane, InputBlocker, tile-dimension globals, SpellMenu, and no-owner.
- Remaining placement uncertainty: exact original helper name and whether the original source intentionally retained this raw helper without an externally discoverable route are not recoverable from current evidence.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `0x00505d00-0x00505d9a`, half-open. No split is recommended.
- Preceding alignment: `0x00505cf9-0x00505d00` is pure `0xcc`.
- Following alignment: `0x00505d9a-0x00505da0` is pure `0xcc`.
- The target is not padding and should not be moved to `-ignored.md`.
- No child creation, merge, or rename is recommended.

## Negative Evidence Summary

- No current IDA function start at `0x00505d00`.
- No incoming code or data xrefs to `0x00505d00`.
- No absolute VA, RVA-style, or raw-offset-style pointer-byte hits for the start address in current MCP `find_bytes`.
- No current vtable, callback-table, jump-table, or source-name route was found.
- Stale SpellMenu docs with `[UID:00042G]` are current documentation contamination from an older UID assignment, not evidence that this MapPane body belongs to SpellMenu.

## First-Draft C++ Recommendation

- Eligible for draft C++: no.
- Reason code should remain blank: the current code-entry gate requires `RECONSTRUCTABLE:TRUE`, a confirmed nonblank `EMITTER_UIDS` route that surfaces to a valid source output, and combined score above 85. This target is reconstructable and should score above the combined-score threshold after incorporation, but it still has no emitter route.
- Exact no-code proof: current MCP proves no modeled function entry, no incoming code/data xrefs, no pointer-byte route for the raw start, no vtable/table/name route, and no generated-output route. Writing formal C++ now would create an uncalled emitted helper and risk introducing source that the original binary does not route.
- If a future route is found, the body is behaviorally ready enough for a first-draft helper using descriptive names for `m_pendingActionTargetY/X`, `m_queuedMapStateRefresh`, `m_timerHandler`, and `CaptureMouse`, but this report intentionally supplies no C++ block because the route gate is not met.

## Score And Metadata Recommendation

- Current score/metadata: `85/85`, owner `00007Q`, reconstructable true, blank emitter/code.
- Recommended score/metadata: raise to `COMPLETION:87`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:00007Q`; keep `RECONSTRUCTABLE:TRUE`; keep `EMITTER_UIDS` blank; keep `EMITTER_POSITION_OPTIONAL` blank; keep formal C++ blank.
- Score rationale: the target can improve because this pass resolves instruction-level behavior, route checks, boundary/padding, callee roles, and the incorrect refresh/capture ambiguity. It should not rise to final-audit scores because original helper spelling, final field names for `+0x8ec/+0x8f0`, and an entry/emitter route remain unresolved.
- Score-improvement attempt:
  - Raw helper liveness: resolved as live source-shaped code, not padding.
  - Route/xref/pointer evidence: no route found after current MCP `lookup_funcs`, `xrefs_to`, `xref_query`, and VA/RVA/raw pointer-pattern searches.
  - Timer-id `8` semantics: resolved as event-8 queue setup for pending action/path-follow target coordinates.
  - Field writes: resolved to `+0x8ec/+0x8f0` pending target coordinates and `+0x39d` queued movement/map-state flag; final original names remain inferred.
  - Source placement: resolved to MapPane source family, class direct owner, blank emitter.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md`
- Metadata/summary:
  - Change scores to `87/89`.
  - Keep owner/reconstructable/emitter/code metadata unchanged.
  - Update `Item Summary` to mention stored pending target coordinates, timer id `8`, `g_pInputBlockerPane` guard, `Pane::CaptureMouse` / `0x005449d0`, `retn 8`, and no-route/non-emitting status.
- Body facts to incorporate:
  - Current MCP session and exact no-route proof, including no code/data xrefs and no VA/RVA/raw pointer-pattern hits.
  - Instruction-level behavior from `0x00505d00-0x00505d97`.
  - Boundary/padding facts for `0x00505cf9-0x00505d00` and `0x00505d9a-0x00505da0`.
  - Distinguish `0x005449d0` capture-style helper from `0x005449f0` release/refresh-style helper.
  - Add first-draft no-code proof explaining why blank formal C++ remains required.

## Recommended Support Doc Changes

- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: expand the [UID:00042G] row from a short "similar raw timer queue body" summary to include the exact target-coordinate writes, tile-dimension conversion, `+0x39d` and input-blocker gates, `TimerHandler::ScheduleTimer(8, 44, 0, 0)`, and `0x005449d0` capture helper call.
- `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`: expand the [UID:00042G] helper table row to say the raw helper prepares the event-8 pending coordinate/action state consumed by `OnTimerEvent`, not merely that it schedules event `8`.
- No change recommended for `by-class/MapPane.md` or `by-file/MapPane.md` unless the supervisor wants a short change-log note; their existing class/file raw-child no-route statements remain correct.
- Separate stale UID-collision cleanup, outside this target's implementation callback unless the supervisor explicitly includes it: current SpellMenu docs still contain `[UID:00042G]` links whose text describes old spell-menu ranges (`0x0051d700-0x0051db38`) but now resolve to this MapPane target. Affected examples include `by-file/SpellMenuDialogs.md`, `by-class/ServerSpellMenuDialog.md`, `by-class/ServerSpellMenuItemList.md`, `by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md`, `by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md`, `by-type/by-vtable/SpellMenuDialogVtables.md`, and `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`. Treat these as stale collision contamination and do not use them as MapPane evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | `0x00505d00-0x00505d9a` is a raw no-function body, not an IDA-modeled function. | strong | MCP `lookup_funcs` call `11`; `insn_query` call `12` | target Status / No-Route Proof | incorporate | applied |
| C2 | No entry route is currently proven: zero code/data xrefs to `0x00505d00` and no VA/RVA/raw pointer-pattern hits. | strong | MCP calls `13`, `23`, `14`, `30` | target No-Route Proof / First-Draft C++ | incorporate | applied |
| C3 | Body stores two arguments into `MapPane+0x8ec/+0x8f0`, converts through tile dimensions and origin fields, sleeps 100 ms, queues timer `8` at 44 ms, sets `+0x39d`, and returns with `retn 8`. | strong | MCP `insn_query` call `12` | target Behavior / Raw Code Evidence | incorporate | applied |
| C4 | `0x005449d0` in this target is capture-style Pane input state, not the `0x005449f0` release/refresh helper. | strong | MCP calls `20-22`; support docs for scroll/fitting room helpers; [UID:00042F] disasm call `24` | target Behavior / Callees; support rows | incorporate | applied |
| C5 | Direct owner remains [UID:00007Q] MapPane; TimerHandler, Pane, InputBlocker, tile dimensions, and SpellMenu are dependencies or stale evidence. | strong | target body fields, MapPane docs, TimerHandler docs, stale UID search | target Status / Ownership; support docs | incorporate | applied |
| C6 | Keep `EMITTER_UIDS` and formal C++ blank; target is not code-entry eligible without an emitter route. | strong | by-structure code-entry gate; MCP no-route facts | target First-Draft C++ / metadata | incorporate | applied |
| C7 | Recommend score `87/89` after incorporation. | medium-high | improved target-specific evidence but remaining route/name blockers | target metadata / score rationale | incorporate | applied |
| C8 | Stale SpellMenu `[UID:00042G]` references are UID-collision contamination unrelated to this MapPane target. | strong | exact `rg` search of current by-* docs and old executed reports | target Ownership And Rejected Alternatives; separate supervisor cleanup if desired | not-applicable | excluded-with-reason |

## Open Questions With Attempted Resolution

- Original helper name: unresolved. Evidence checked includes current body, siblings, MapPane class/file docs, timer handler docs, and executed B009 report. No current source string, symbol, route, or caller name proves original spelling. Use descriptive wording only.
- Entry route/emitter: unresolved with evidence-backed no-improvement proof. Current MCP found no function, no code/data xrefs, no VA/RVA/raw pointer hits, and no table/vtable/name route. Further current-pass work would be unsupported without new binary/source evidence or a supervisor-approved retained-raw-helper emission policy.
- Final field names for `+0x8ec/+0x8f0`: behavior is clear enough as pending target/action tile coordinates, but exact original names remain broader MapPane action-state layout work. This limits final C++ confidence but not ownership or behavior documentation.
- Stale SpellMenu UID collision: resolved for this report as rejected evidence. Actual cleanup is outside this target unless assigned.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md --apply --queue-timeout 240`
  - `command_id: 000000004090`
  - `command_timestamp: 2026-07-01T17:41:28-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Validator-applied side effects: `completion_update 00042G ... 87`, `confidence_update 00042G ... 89`, three UID link updates in the target, five reference-index additions, four stats-row removals, projected stats update, `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240`
  - `command_id: 000000004091`
  - `command_timestamp: 2026-07-01T17:41:35-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Validator-applied side effects: projected stats update, `stats_incremental_noop` for `0001AP`, `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md --apply --queue-timeout 240`
  - `command_id: 000000004093`
  - `command_timestamp: 2026-07-01T17:41:46-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/diagnostics: four pre-existing `missing_ref_uid` diagnostics for UID references `0003UD` and `0003XP` in the timer-handler page. The command still validated the edited file with `ok: 1`; no validator lifecycle repair was performed because cleanup is outside this callback.
  - Validator-applied side effects: projected stats update, `stats_incremental_noop` for `0003ZS`, `generated_refresh: deferred`.
- Generated refresh observations: all three file validators returned deferred generated refresh using command IDs `000000004090`, `000000004091`, and `000000004093`. Generated reports/files are validator-owned and were not manually edited.
- Leases: B001 leased the three accepted by-memory docs immediately before editing and released them immediately after the edit/validator batch. Lease and unlease commands both returned `Success` for each by-* path.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00042G-MapPaneQueueMovementRefreshTimer8-by-memory-source-quality.md`
- Modified during implementation:
  - `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md`
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`
  - `tools/leaser/Agents/Agent-B001/research/00042G-MapPaneQueueMovementRefreshTimer8-by-memory-source-quality.md`
- Renamed: none.
- Report execution: pending supervisor verification; supervisor runs `tools/validator.py execute_report ... --apply` only after verifying this implementation.

## Implementation Tracking Checklist

Implementation callback pass:
- [x] Supervisor validation required before implementation. Proof: callback assignment `B001-implement-00042G-MapPaneQueueMovementRefreshTimer8-by-memory-20260701` accepted this report for implementation.
- [x] Target/support docs to update. Proof: edited target `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md` plus support rows in `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` and `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`.
- [x] Current target state and actual evidence checked recorded. Proof: target now records current MCP session, no-route proof, raw instruction behavior, boundary bytes, and stale UID-collision rejection.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C1-C7 are `applied`; C8 is `excluded-with-reason` for stale SpellMenu cleanup outside callback scope while preserving rejection in target/report.
- [x] Metadata/score changes applied. Proof: target metadata changed `85/85 -> 87/89`; validator command `000000004090` applied `completion_update` and `confidence_update`.
- [x] Score-limiting blockers researched and incorporated. Proof: target no-route/no-code proof records modeled-function, xref, pointer-pattern, table/vtable, and generated-route failures.
- [x] Owner/emitter/reconstructable changes applied or confirmed unchanged. Proof: target keeps `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- [x] Split/rename/new-child changes applied or confirmed not applicable. Proof: no split, rename, or child creation was recommended or performed.
- [x] Source-placement/range/padding changes applied. Proof: target records `0x00505cf9-0x00505d00` and `0x00505d9a-0x00505da0` as adjacent `0xcc` alignment and keeps the body as source-shaped MapPane code.
- [x] First-draft C++ or no-code proof applied. Proof: target has a `First-Draft C++ / No-Code Proof` section and formal C++ remains blank.
- [x] Third-party import directive confirmed not applicable. Proof: target is NexusTK MapPane code, not a third-party import.
- [x] Exact target/support doc facts incorporated at report-level detail. Proof: target and support rows include coordinate writes, tile-dimension conversion, `Sleep(100)`, `+0x39d` and `g_pInputBlockerPane` gates, `ScheduleTimer(8, 44, 0, 0)`, `0x005449d0` capture-style helper, and no-route proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target rejects SpellMenu UID collision, TimerHandler/Pane/InputBlocker/tile-dimension ownership, and imprecise "refreshes through `0x005449d0`" wording.
- [x] Wave2/Wave3 or stale artifacts encountered and rejected. Proof: stale SpellMenu `[UID:00042G]` collision references are documented as contamination and no SpellMenu docs were edited.
- [x] Open questions closed or documented with evidence-backed unresolved rationale. Proof: target/report retain unresolved original helper name, final `+0x8ec/+0x8f0` field names, and missing entry route with evidence.
- [x] Validators run. Proof: validator commands `000000004090`, `000000004091`, and `000000004093` all exited `0` with `ok: 1`.
- [x] Generated report refresh expected or manual supervisor-owned coverage/tracker text applied. Proof: generated refresh was deferred by validators; no manual coverage/tracker edit was recommended or performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00042G-MapPaneQueueMovementRefreshTimer8-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00042G-MapPaneQueueMovementRefreshTimer8-by-memory-source-quality.md","timestamp":"2026-07-01T17:49:12","uid":"00042G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
