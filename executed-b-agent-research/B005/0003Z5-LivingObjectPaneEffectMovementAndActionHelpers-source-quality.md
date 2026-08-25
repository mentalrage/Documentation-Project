** TARGET-REPORT-UID:0003Z5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0003Z5 LivingObjectPane Effect Movement And Action Helpers Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep UID0003Z5 as a reconstructable `LivingObjectPane` exact child emitted through [UID:00007B] `LivingObjectPane` / [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Final disposition after implementation callback: same target range, no split, no owner move, no no-code downgrade, target metadata raised to `88/90`, and accepted first-draft C++ applied to the exact by-memory child.
- Required action now: supervisor execute/review only. B005 applied the accepted target/support doc changes, ran scoped validators for the three changed by-* docs, updated this report ledger/checklist, and did not run `execute_report`.
- Confidence: applied `88/90`. The live MCP evidence is strong for ownership/range/source placement, but exact raw helper names, three raw no-xref starts, and first-draft C++ source-shape caveats cap the score below final-source confidence.

## Supporting Research

- Assignment: Agent-B005 implementation callback for [UID:0003Z5] `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`, following the accepted Gate 1 report SHA `F21D7BE545D8BB1DAAC86828CDB2B05C6DB5AF4E010BF58DCF93C2B9965CFA49`.
- Repair trigger: supervisor Gate 1 audit entry `2026-07-06T17:51:00-04:00 - B005 UID0003Z5 Gate 1 Audit` found the earlier report artifact missing literal required B-agent headings.
- Current artifact status: implementation-callback ledger/checklist updated in `tools/leaser/Agents/Agent-B005/research/`; not executed and not archived.
- Work mode: implementation callback. B005 edited only the target/support by-* docs listed in `Changed Files` plus this report, then ran scoped file validators. B005 did not manually edit generated files, coverage reports, validator state, supervisor ledgers, lifecycle files, or archive files.
- Required report path: `tools/leaser/Agents/Agent-B005/research/0003Z5-LivingObjectPaneEffectMovementAndActionHelpers-source-quality.md`.
- MCP state during the completed research: available. Direct JSON-RPC MCP session headers were reinitialized against `http://127.0.0.1:13337/mcp`; active IDB session `18aed30a` remained live for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- This implementation callback did not rerun binary research because the accepted report already contained the target-specific evidence under healthy MCP; it applied those accepted facts at report-level detail and performed validator-only verification.

## Target

- Target UID: `0003Z5`.
- Target path: `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`.
- Target title: `LivingObjectPaneEffectMovementAndActionHelpers`.
- Current queue state at original assignment: `86/88`, combined `87.0`, reconstructable `true`, direct reports `0`.
- Current owner/emitter before callback: [UID:00007B] `LivingObjectPane`, emitted through [UID:0000KU] `LivingObjectPane.cpp`.
- Current report artifact: `tools/leaser/Agents/Agent-B005/research/0003Z5-LivingObjectPaneEffectMovementAndActionHelpers-source-quality.md`.

## Executive Recommendation

Keep UID0003Z5 as a reconstructable `LivingObjectPane` child emitted through [UID:00007B] `LivingObjectPane` / [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`. Do not move the owner to `Motion`, `ObjectPane`, `TimerHandler`, `TimerMgr`, `MapPane`, `SoundManager`, or any raw packet helper.

Recommended metadata after implementation callback:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
```

Reason for the modest increase: the live target-specific MCP pass now proves the exact function and raw-helper inventory, range boundaries, vtable slot route, raw no-xref status, Motion-constructor caller relationship, timer IDs, and emitted C++ repair needs. Do not raise higher yet. The raw helper original names remain descriptive, three raw starts have no inbound route, `PlayActionAnimationOrEffect` contains inlined active-effect insertion rather than a direct call to `RawAddActiveEffect`, and the current formal C++ has source-shape errors that should be repaired before any higher confidence claim.

Do not split this target in the implementation callback. It is a coherent LivingObjectPane effect/movement/action cluster:

- `0x0053b060`, `0x0053b0e0`, and `0x0053b190` are code-shaped raw/private helper bodies with no inbound xrefs. Splitting them into standalone pages would create no-route exact children without improving source placement.
- `0x0053b130`, `0x0053b1b0`, `0x0053b200`, `0x0053b280`, `0x0053b360`, and `0x0053b3d0` are modeled LivingObjectPane methods in the same state family.
- `0x0053b6b3-0x0053b700` is not successor source code. It is the lowered switch/table tail and padding from `0x0053b3d0`, and must remain excluded from [UID:0002R1] `LivingObjectPaneAnimationTimer`.

## Evidence Standards Used

I used current target/support docs, generated output, current tracker/coverage rows, executed B-agent reports as leads, and live read-only IDA MCP evidence. No IDA write, rename, type edit, broad unbounded callgraph, process-control action, `execute_report`, dry-run execute, manual report move, or lifecycle/archive command was run. During implementation callback, only scoped file validators were run for the changed by-* docs: command IDs `000000007624`, `000000007625`, and `000000007626`.

## Evidence Checked

Current docs and generated output:

- Target [UID:0003Z5] `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`.
- [UID:00007B] `by-class/LivingObjectPane.md`.
- [UID:0000KU] `by-file/LivingObjectPane.md`.
- [UID:0001DE] `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`.
- [UID:0002QW] `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`.
- [UID:000358] `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`.
- [UID:0002R1] `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`.
- [UID:0003Z8] `by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md`.
- Generated `auto-generated/NexusTK/map/LivingObjectPane.cpp`.
- Generated tracker rows in `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.

Relevant executed reports opened as leads:

- `executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md`.
- `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`.
- `executed-b-agent-research/B003/0002QW-MotionAnimationConstructor-source-quality.md`.
- `executed-b-agent-research/B007/0002R1-LivingObjectPaneAnimationTimer-source-quality.md`.
- `executed-b-agent-research/B007/0000KU-LivingObjectPane-empty-emitter-family-source-quality.md`.
- `executed-b-agent-research/B014/0003UD-LivingObjectPaneTryPerformAction-source-quality.md`.
- Relevant search hits from `executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`, `executed-b-agent-research/B008/0003Z3-LivingObjectPaneSpriteConfigHelpers-source-quality.md`, and `executed-b-agent-research/B004/00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md`.

Old-report search terms required by `goal.md` and results:

| Term | Search result |
| --- | --- |
| `TARGET-REPORT-UID:0003Z5` | No prior executed direct target report. Only current `tools/leaser/Agents/Agent-B005/goal.md` matched. |
| `0003Z5` | 17 matching files. Relevant executed leads: B001 `00007B`, B003 `0002QW`, B007 `0000KU`, B007 `0002R1`, B008 `0003UY`, B008 `0003Z3`, B014 `0003UD`; the rest were current goals/agent ledgers or broad assignment files. |
| `0x0053b060` | 10 matching files. Relevant executed leads: B001 `00007B`, B001 `0001DE`, B001 `0001DF`, B003 `0002QW`, B008 `0003UY`, B014 `0003UD`. |
| `0x0053b6b3` | 9 matching files. Relevant executed leads: B001 `00007B`, B001 `0001DE`, B003 `0002QW`, B007 `0002R1`, B008 `0003UY`, B014 `0003UD`. |
| `LivingObjectPaneEffectMovementAndActionHelpers` | 10 matching files. Relevant executed leads: B001 `00007B`, B001 `0001DE`, B003 `0002QW`, B008 `0003UY`, B014 `0003UD`. |
| `RawAddActiveEffect` | B001 `0001DE` plus current B005 goal. |
| `RawRemoveActiveEffect` | B001 `0001DE` plus current B005 goal. |
| `ClearAllEffects` | B001 `0001DE`, B007 `0000KU`, plus current B005 goal. |
| `RawSetCurrentEffect` | B001 `0001DE` plus current B005 goal. |
| `SetHighlightState` | B001 `0001DE`, B004 `00036R`, plus current B005 goal. |
| `ShowDamageEffect` | B001 `0001DE` plus current B005 goal. |
| `BeginMoveTo` | B001 `0001DE` plus current B005 goal. |
| `SetFacing` | B001 `0001DE`, B007 `0002R1`, plus current B005 goal. |
| `PlayActionAnimationOrEffect` | B001 `0001DE`, B003 `0002QW`, B014 `0003UD`, plus current B005 goal. |
| `LivingObjectPane` | 148 broad matches. Narrowed to target/source-family reports listed above. |
| `00007B` | 55 broad owner matches. Narrowed to LivingObjectPane class/file/core/timer/action reports listed above. |
| `0000KU` | 57 broad file-root matches. Narrowed to LivingObjectPane file/core/generated-output reports listed above. |

## MCP Session Summary

Read-only MCP availability and evidence:

- Listener/process check: TCP listener on `127.0.0.1:13337`; listener PID `10720`; `idalib-mcp.exe` PID `8796`; active Python worker PID `7064`.
- Fresh JSON-RPC MCP HTTP sessions included `9c82f062-77e6-4c94-b3e0-e4bcd1ab8e2d` and `31f991f7-3eff-41e7-9426-289d3d58accd`.
- `tools/list` succeeded and exposed `server_health`, `lookup_funcs`, `get_bytes`, `get_int`, `xrefs_to`, `xref_query`, `decompile`, `disasm`, `analyze_function`, and related read-only tools.
- `idb_list` returned active database session `18aed30a`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `7064`, `is_analyzing:false`, `is_active:true`, backend `worker`, owned/adopted.
- `server_health(database=18aed30a)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

One MCP HTTP parameter attempt used `address` instead of the schema-required `addr`, and one `insn_query` attempt omitted the schema-required `queries` array. Those are not evidence and were corrected by rechecking `tools/list`; MCP remained healthy.

## Current Target State

Current target metadata before callback:

```text
UID:0003Z5
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
```

Current generated output already contains non-empty UID0003Z5 C++ in `auto-generated/NexusTK/map/LivingObjectPane.cpp`, refreshed at `2026-07-06T13:34:19-04:00`, with generated header `validator-command-id:000000007590`.

The generated block is useful as a first draft but should not be treated as final source-quality code. Live MCP identified these callback repairs:

- `ClearAllEffects` must clear `m_pendingDamageEffect` / `+0x1f8` as well as `m_currentEffect`.
- `BeginMoveTo` only cancels `kLivingTimerForwardStep` and calls `TryStepForward` when `m_isMoving` is already set. It restarts highlighting inline, clears pending damage only in the moving branch, calls the base/ObjectPane position setter when coordinates differ, schedules `FWdA` with `(stepDelay, facing, stepDelay)`, and returns the MapPane invalidation result.
- `PlayActionAnimationOrEffect` uses the word at `+0x12a` as its animation guard, not the current generated `m_stepCode` field. `BeginMoveTo` does not store the step delay into that word.
- `PlayActionAnimationOrEffect` inlines the active-effect trim/insert logic after constructing Motion, rather than making a binary call to `RawAddActiveEffect`. A source helper call may still be acceptable only if the final emitted source treats it as inline-equivalent.
- The final timer schedule in `PlayActionAnimationOrEffect` is unconditional and passes `effect ? effect + 4 : 0`; the current generated C++ schedules only when `effect != 0`.

## Heuristic / Inference Reanalysis And Validation

The score/source-quality blockers in scope were range/split, raw-helper liveness, source owner, effect-list role, movement/timer semantics, Motion/Sound/MapPane dependency direction, generated field names, and current formal C++ correctness. The research separates direct IDA facts from documentation evidence and inference:

- Direct IDA fact: `0x0053b060`, `0x0053b0e0`, and `0x0053b190` are code-shaped raw starts but not IDA functions and have no inbound xrefs. Best inference: retained/private helper bodies in the LivingObjectPane source family. Decision: keep in UID0003Z5, document no-route caveat, do not split.
- Direct IDA fact: `0x0053b6b3-0x0053b700` is switch/table/padding tail after `sub_53B3D0`, not a function. Best inference: compiler output attached to `PlayActionAnimationOrEffect`. Decision: preserve as target boundary evidence and exclude from UID0002R1.
- Direct IDA fact: vtable word `0x006209ec` points to `0x0053b3d0`. Documentation evidence from B014 proves the live vtable dispatch from `TryPerformAction(27, 200, 0)`. Decision: `PlayActionAnimationOrEffect` is a LivingObjectPane virtual method, not a loose helper.
- Direct IDA fact: `sub_53B3D0` calls `Motion::Motion` at `0x00539bc0`. Documentation evidence from B003 proves Motion owns that constructor and its pool/vtable route. Decision: Motion is a callee/object type, not the owner of UID0003Z5.
- Direct IDA fact: `sub_53B130` clears both `this[126]` and `this[112]`. Best source-facing names from existing docs are `m_pendingDamageEffect` / `+0x1f8` and `m_currentEffect` / `+0x1c0`. Decision: generated C++ omitting `m_pendingDamageEffect = 0` must be repaired.
- Direct IDA fact: `sub_53B280` schedules `FWdA` with `(stepDelay, facing, stepDelay)`, restarts highlight inline only when already moving, and calls ObjectPane position setter when coordinates differ. Decision: generated `m_targetX/m_targetY/m_stepCode` body is stale source-shape and must be replaced.
- Direct IDA fact: animated action cases in `sub_53B3D0` gate on word `+0x12a`. Documentation evidence shows `+0x12a` has other LivingObjectPane/ObjectPane-family meanings and is not proven as movement step delay. Decision: use a provisional descriptive name such as `m_actionAnimationGuardWord`; reject current `m_stepCode` unless a later layout pass proves it.
- Direct IDA fact: non-animated action effect insertion is inlined in `sub_53B3D0`, including trimming old effects and scheduling the Motion timer view. Decision: source may keep a private helper only as inline-equivalent, but the safer formal C++ recommendation expands the trim/insert body.
- Documentation evidence: generated output already emits UID0003Z5 through `auto-generated/NexusTK/map/LivingObjectPane.cpp`. Decision: the target is eligible for first-draft C++; no no-code proof applies.
- Rejected stale/generated names: `sub_53B*` labels, `m_stepCode` as the action guard, and direct-call `RawAddActiveEffect(effect)` in `PlayActionAnimationOrEffect` as a binary call edge.

Unresolved issues are bounded and do not block first-draft C++: exact original raw helper spellings, exact original `+0x12a` member name, and whether the original source expressed active-effect insertion through an inline private helper. These issues cap confidence and are recorded in target/support caveats rather than left as "needs investigation."

## Positive Evidence Summary

- Direct IDA evidence supports the chosen target range: modeled function starts/sizes exist for `0x0053b130`, `0x0053b1b0`, `0x0053b200`, `0x0053b280`, `0x0053b360`, and `0x0053b3d0`; raw helper starts are code-shaped; and `0x0053b6b3-0x0053b700` is switch/table/padding output.
- Direct vtable evidence supports LivingObjectPane ownership: `0x006209ec -> 0x0053b3d0`, and B014 confirms a live `TryPerformAction` vtable dispatch through that slot.
- Receiver field evidence supports LivingObjectPane ownership: active-effect list `+0x1bc`, current effect `+0x1c0`, movement/facing bytes `+0x1c4/+0x1c5/+0x1c6`, highlight `+0x1e8`, BoxRotator `+0x1f0`, and pending damage/effect `+0x1f8`.
- Documentation and generated-output evidence support source placement: current target, class, file, core, vtable, timer, and generated C++ pages all route this family through LivingObjectPane.
- Prior executed reports corroborate dependencies without taking ownership: B003 for Motion constructor, B007 for timer constants and boundary exclusion, and B014 for action vtable dispatch.

## Negative Evidence Summary

- No inbound xrefs were found to raw starts `0x0053b060`, `0x0053b0e0`, or `0x0053b190`; this rejects standalone child promotion and caps raw-helper confidence.
- No ordinary direct code xref was found to `0x0053b3d0`; liveness comes through vtable/data refs, so the report must preserve the virtual-slot route rather than inventing ordinary callers.
- `0x0053b6b3` is not a function and the bytes before `0x0053b700` are not a successor source routine; this rejects absorption into UID0002R1 or creation of a new child there.
- Motion ownership is rejected because the constructed object at `0x00539bc0` writes Motion vtables and is owned by [UID:0002QW]; UID0003Z5 only allocates/constructs it.
- TimerHandler/TimerMgr ownership is rejected because timers are scheduled services and the receiver state remains LivingObjectPane.
- MapPane, SoundManager, ObjectPane, UserPane, and raw packet helpers are rejected as direct owners because they are callees, callers, inherited/base providers, or surrounding context rather than owners of this method cluster.

## Function / Child Inventory

| Range | IDA state | Accepted source role | Current decision |
| --- | --- | --- | --- |
| `0x0053b060-0x0053b0df` | raw code, not an IDA function | retained/private active-effect add/trim helper | Keep in UID0003Z5; no split; no standalone owner. |
| `0x0053b0e0-0x0053b12b` | raw code, not an IDA function | retained/private active-effect remove helper | Keep in UID0003Z5; no split; no standalone owner. |
| `0x0053b130-0x0053b184` | `sub_53B130`, size `0x54` | `LivingObjectPane::ClearAllEffects()` | Keep source method in UID0003Z5; repair C++ to clear `+0x1f8`. |
| `0x0053b190-0x0053b1a8` | raw code, not an IDA function | retained/private current-effect setter | Keep in UID0003Z5; no split; no standalone owner. |
| `0x0053b1b0-0x0053b1f7` | `sub_53B1B0`, size `0x47` | `LivingObjectPane::SetHighlightState(bool)` | Keep. B004 support may use target-highlight naming, but behavior is highlight/BoxRotator state. |
| `0x0053b200-0x0053b272` | `sub_53B200`, size `0x72` | `LivingObjectPane::ShowDamageEffect(int, short)` | Keep. SoundManager and delayed refresh are callees/dependencies. |
| `0x0053b280-0x0053b35a` | `sub_53B280`, size `0xda` | `LivingObjectPane::BeginMoveTo(int, int, unsigned char, short)` | Keep; repair C++ source shape. |
| `0x0053b360-0x0053b3c7` | `sub_53B360`, size `0x67` | `LivingObjectPane::SetFacing(unsigned char)` | Keep. Uses direction-delay timer when moving. |
| `0x0053b3d0-0x0053b6b3` | `sub_53B3D0`, size `0x2e3` | `LivingObjectPane::PlayActionAnimationOrEffect(unsigned, int, unsigned char)` | Keep. Vtable slot `+0x70` target and Motion caller. |
| `0x0053b6b3-0x0053b700` | not a function | action-helper switch/data tail plus padding | Exclude from UID0002R1 and do not create a source child. |

## IDA MCP Facts

Function boundaries and starts:

- `lookup_funcs` returned no IDA function for raw starts `0x0053b060`, `0x0053b0e0`, and `0x0053b190`.
- `lookup_funcs` returned `sub_53B130`, `sub_53B1B0`, `sub_53B200`, `sub_53B280`, `sub_53B360`, and `sub_53B3D0` with the exact sizes listed above.
- `lookup_funcs` returned no function at `0x0053b6b3`; successor `sub_53B700` starts at `0x0053b700`.

Boundary bytes:

- `get_bytes 0x0053b040 size 64` showed predecessor table data and twelve `0xcc` bytes before raw code at `0x0053b060`, whose bytes start `55 8b ec 56 57...`.
- `get_bytes 0x0053b6a0 size 112` showed the `sub_53B3D0` tail returning with `c2 0c 00 90`, then table bytes and selector bytes before `0xcc` padding and the `0x0053b700` prologue. This confirms `0x0053b6b3-0x0053b700` belongs to the action helper's lowered switch/data tail plus alignment.

Vtable and data route:

- `get_int 0x006209ec` returned `0x0053b3d0`, proving LivingObjectPane primary vtable slot `+0x70` targets `PlayActionAnimationOrEffect`.
- Neighbor slot reads returned `0x006209f0 -> 0x0053d800` and `0x006209f4 -> 0x0053d810`, matching the LivingObjectPane vtable support page's ShowName/HideName context used by the Motion constructor report.
- `xrefs_to 0x0053b3d0` returned data refs from `0x006209ec` and `0x0062ef7c`, with no ordinary direct code caller. B014 confirms the live vtable dispatch from `TryPerformAction` with `(27, 200, 0)`.

Xref/liveness summary:

- `xrefs_to` found no inbound xrefs to raw starts `0x0053b060`, `0x0053b0e0`, or `0x0053b190`.
- `xrefs_to 0x0053b130` returned eight xrefs, including destructor/cleanup, action helper, warp/local-player/server handling, and scalar-deleting-destructor cleanup contexts.
- `xrefs_to 0x0053b1b0` returned 89 xrefs across target-selection/UI/local-player action contexts.
- `xrefs_to 0x0053b200` returned callers from `sub_512960`.
- `xrefs_to 0x0053b280` returned movement callers including `sub_507C90` and the local-player movement path.
- `xrefs_to 0x0053b360` returned callers from `sub_507C90`, `sub_5A2E00`, and the local-player path.
- `xrefs_to 0x0053b700` included calls from this target's `SetFacing` and `PlayActionAnimationOrEffect`, plus animation/timer support routes.

Decompile facts:

- `sub_53B130` loops through the active-effect list at `this[111]` / `+0x1bc`, deletes each entry, clears the list, then writes `this[126] = 0` and `this[112] = 0`. These are `m_pendingDamageEffect` / `+0x1f8` and `m_currentEffect` / `+0x1c0`.
- `sub_53B1B0` toggles byte `+0x1e8`, starts or stops the embedded BoxRotator at `+0x1f0`, and invalidates through vtable slot `+0x20`.
- `sub_53B200` plays a SoundManager sample with volume `100`, skips damage overlay for sprite kind `1` image IDs in `(0x8173, 0x8187)`, stores the damage payload at `+0x1f8`, invalidates bounds, and schedules timer `1382368353` / `aDeR` for `120`.
- `sub_53B280` stores facing at `+0x1c5`; only if already moving does it cancel `FWdA`, call `TryStepForward`, restart highlight/BoxRotator inline, and clear `+0x1f8`; then it conditionally calls virtual slot `+0x68` / `ObjectPane::SetPosition`, sets `+0x1c4 = 1` and `+0x1c6 = 0`, schedules `FWdA` with `(a5, a4, a5)`, and invalidates through active MapPane.
- `sub_53B360` schedules timer `1130906729` / `iDhC` with `m_spriteConfig.directionDelay` when moving; otherwise it writes facing, calls `PlayAnimation(facing + 1)` for sprite kind `1`, and invalidates MapPane.
- `sub_53B3D0` handles animated sprite actions by mapping actions to animation groups. It gates actions 2, 3, 4, 5, and default group 4 on the word at `+0x12a`, not on the movement step delay. For non-animated objects, it skips action `25`, honors the name-visible gate, clears effects for action `27`, allocates from Motion pool `0x0069b984`, calls `Motion::Motion` at `0x00539bc0`, inlines active-effect trimming and insertion at list `+0x1bc`, and schedules the constructed Motion timer view with `effect ? effect + 4 : 0`.

## Ranked Ownership Analysis

### 1. LivingObjectPane / UID00007B

- Evidence for: receiver state is LivingObjectPane state: active-effect list `+0x1bc`, current effect `+0x1c0`, movement/facing/frame state `+0x1c4/+0x1c5/+0x1c6`, animation group `+0x1cc`, highlight byte `+0x1e8`, BoxRotator `+0x1f0`, and pending damage/effect payload `+0x1f8`.
- Evidence for: `PlayActionAnimationOrEffect` is a LivingObjectPane primary vtable slot at `+0x70`, with `0x006209ec -> 0x0053b3d0`.
- Evidence for: target, class, file, vtable, core, and generated-output docs all route UID0003Z5 through LivingObjectPane.
- Evidence against: three raw helper starts have no inbound route and exact original helper names are not recovered.
- Decision: accepted canonical owner and emitter. Raw no-route caveats cap confidence but do not move the owner.

### 2. Motion / UID00008R

- Evidence for: the non-animated action path allocates from the Motion pool and calls `Motion::Motion` at `0x00539bc0`.
- Evidence against: B003 proves `0x00539bc0` writes Motion vtables and belongs to Motion, while UID0003Z5 is the LivingObjectPane caller that owns active-effect list insertion and action semantics.
- Decision: rejected as direct owner; Motion is a constructed callee/object type.

### 3. TimerHandler / TimerMgr

- Evidence for: UID0003Z5 schedules/cancels `FWdA`, `iDhC`, `aDeR`, and Motion timer views through TimerMgr and the embedded timer handler.
- Evidence against: TimerMgr and TimerHandler do not own the receiver fields, vtable slot, movement/facing state, effect list, or damage/highlight state. Timer support pages document these constants as LivingObjectPane timer semantics.
- Decision: rejected as owner; keep as support/dependency evidence.

### 4. MapPane, SoundManager, ObjectPane, UserPane, and raw packet helpers

- Evidence for: MapPane invalidates/reindexes, SoundManager plays samples, ObjectPane supplies base position/bounds behavior, and UserPane/local-player packet paths call into this family.
- Evidence against: none of these candidates receives ownership of the full state cluster. They are callees, callers, inherited/base providers, or surrounding local-player context.
- Decision: rejected as direct owners. Preserve dependency/caller notes only.

## Source Placement

- Recommended source file/class placement: [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`, class [UID:00007B] `LivingObjectPane`.
- Why this placement fits: the target is a LivingObjectPane method/helper cluster that mutates actor visual/effect/movement state, uses the LivingObjectPane vtable, and is already emitted by generated output under the LivingObjectPane source file.
- Rejected placements: `NexusTK/render/Motion.cpp` because Motion is a constructed effect object only; TimerMgr/TimerHandler because they are scheduler services only; MapPane/SoundManager/ObjectPane/UserPane because they are dependency or caller contexts.
- Remaining placement uncertainty: exact private helper declarations and the `+0x12a` member name are provisional. This affects target prose and C++ caveats, not owner/emitter metadata.

## Range / Split / Padding / Reclassification Analysis

Do not split the target now.

The three raw starts are source-shaped but no-route:

- `0x0053b060`: raw add/trim active-effect helper. No direct xref. Body shape matches the trim/insert logic in `PlayActionAnimationOrEffect`.
- `0x0053b0e0`: raw remove active-effect helper. No direct xref.
- `0x0053b190`: raw current-effect setter. No direct xref.

They are not padding, but their no-route status means they should not be promoted into separate exact pages or used to raise confidence above `90` without a stronger route such as a rel32 call, vtable slot, pointer table, or compiler/lifecycle proof. Keeping them in the aggregate preserves source detail while avoiding standalone dead-helper overclaim.

The modeled functions are tightly connected by the same LivingObjectPane state and support services. A nine-way split would make the documentation noisier and would not improve owner or emitted-source placement.

## First-Draft C++ Recommendation

Keep formal C++ nonblank after callback, but replace the current UID0003Z5 block. The current generated block is a useful draft, not source-quality final. It overreaches or misstates these points:

- It omits the `m_pendingDamageEffect = 0` write in `ClearAllEffects`.
- It treats `BeginMoveTo` as always cancelling/calling `TryStepForward`, stores `m_targetX/m_targetY/m_stepCode`, and schedules with `(1, 0, 0)`. Live MCP shows conditional moving-branch behavior, ObjectPane position-setter use, and schedule payload `(stepDelay, facing, stepDelay)`.
- It calls guarded `SetHighlightState(true)` from the moving branch. Live MCP restarts the highlight BoxRotator inline even when `m_highlighted` is already true; the existing guarded setter would early-return.
- It uses `m_stepCode` as the action-animation guard. Live MCP reads the word at `+0x12a`, while `BeginMoveTo` does not store that value.
- It models the action helper as calling `RawAddActiveEffect(effect)`. Live MCP shows the active-effect trim/insert logic inlined in `sub_53B3D0`. If a source helper is used in the final source, it must be documented as inline-equivalent; otherwise expand the trim/insert body.
- It skips the final timer schedule when Motion allocation fails. Live MCP still calls TimerMgr with a zero timer-handler pointer in that case.

Implementation callback can use this as the exact replacement direction for the formal C++ block. The names `m_actionAnimationGuardWord`, `SetPosition`, and list/timer helper spellings remain first-draft source-facing names, not recovered decorated names:

```cpp
void LivingObjectPane::RawAddActiveEffect(ObjectPane *effect)
{
    while (m_activeEffects->Count() > 2)
    {
        ObjectPane *oldEffect = m_activeEffects->At(m_activeEffects->Count() - 3);
        if (oldEffect != 0)
            oldEffect->CancelTimersAndDelete();
        m_activeEffects->RemoveAt(m_activeEffects->Count() - 3, true);
        if (m_currentEffect == oldEffect)
            m_currentEffect = 0;
    }

    m_activeEffects->Insert(1, effect);
}

void LivingObjectPane::RawRemoveActiveEffect(ObjectPane *effect)
{
    for (int i = 0; i < m_activeEffects->Count(); ++i)
    {
        if (m_activeEffects->At(i) == effect)
        {
            m_activeEffects->RemoveAt(i, true);
            break;
        }
    }
}

void LivingObjectPane::ClearAllEffects()
{
    for (int i = 0; i < m_activeEffects->Count(); ++i)
        DeleteObjectPane(m_activeEffects->At(i));
    m_activeEffects->Clear();
    m_pendingDamageEffect = 0;
    m_currentEffect = 0;
}

void LivingObjectPane::RawSetCurrentEffect(ObjectPane *effect)
{
    if (m_currentEffect != effect)
        m_currentEffect = effect;
}

void LivingObjectPane::SetHighlightState(bool highlighted)
{
    if (m_highlighted == highlighted)
        return;

    m_highlighted = highlighted;
    if (highlighted)
        m_boxRotator.Start();
    else
        m_boxRotator.Stop();
    Invalidate(false);
}

void LivingObjectPane::ShowDamageEffect(int value, short soundId)
{
    g_pSoundManager->PlaySample(soundId, 100);
    if (m_spriteConfig.kind == 1 && m_spriteConfig.imageId > 0x8173 && m_spriteConfig.imageId < 0x8187)
        return;

    m_pendingDamageEffect = value;
    Invalidate(&m_bounds);
    g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerRefresh, 120, 0, 0);
}

bool LivingObjectPane::BeginMoveTo(int x, int y, unsigned char facing, short stepDelay)
{
    m_facing = facing;

    if (m_isMoving)
    {
        m_timerHandler.CancelTimer(kLivingTimerForwardStep);
        if (TryStepForward())
            return true;

        if (m_highlighted)
        {
            m_highlighted = true;
            m_boxRotator.Start();
            Invalidate(false);
        }

        m_pendingDamageEffect = 0;
    }

    m_facing = facing;
    if (m_tileX != x || m_tileY != y)
        SetPosition(x, y);

    m_isMoving = true;
    m_moveFrame = 0;
    g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerForwardStep, stepDelay, facing, stepDelay);
    return g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::SetFacing(unsigned char facing)
{
    if (m_isMoving)
    {
        g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerDirectionDelay, m_spriteConfig.directionDelay, facing, 0);
        return;
    }

    m_facing = facing;
    if (m_spriteConfig.kind == 1)
        PlayAnimation(facing + 1);
    g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing)
{
    if (m_spriteConfig.kind == 1)
    {
        if (m_animationGroup != 0 && m_animationGroup <= 8)
        {
            const bool canPlayActionGroup = (m_actionAnimationGuardWord == 0);
            switch (action)
            {
            case 0:  PlayAnimation(m_facing + 5); break;
            case 1:  PlayAnimation(m_facing + 13); break;
            case 2:  if (canPlayActionGroup) PlayAnimation(m_facing + 17); break;
            case 3:  if (canPlayActionGroup) PlayAnimation(m_facing + 21); break;
            case 4:  if (canPlayActionGroup) PlayAnimation(m_facing + 25); break;
            case 5:  if (canPlayActionGroup) PlayAnimation(m_facing + 29); break;
            case 6:  return;
            case 25: PlayAnimation(m_facing + 9); break;
            default: if (canPlayActionGroup) PlayAnimation(4); break;
            }
        }
        return;
    }

    if (action == 25)
        return;
    if (m_nameVisible && action != 27 && action != 4 && action != 6)
        return;
    if (action == 27)
        ClearAllEffects();

    Motion *effect = g_motionPool.Alloc();
    if (effect != 0)
        effect->Construct(this, action, static_cast<short>(value), facing);

    while (m_activeEffects->Count() > 2)
    {
        ObjectPane *oldEffect = m_activeEffects->At(m_activeEffects->Count() - 3);
        if (oldEffect != 0)
            oldEffect->CancelTimersAndDelete();
        m_activeEffects->RemoveAt(m_activeEffects->Count() - 3, true);
        if (m_currentEffect == oldEffect)
            m_currentEffect = 0;
    }

    m_activeEffects->Insert(1, effect);
    g_pTimerMgr->ScheduleTimer(effect != 0 ? effect->GetTimerHandler() : 0, 0, 0, 0, 0);
}
```

Score cap note: the replacement block is first-draft source-quality, not final header-quality. The exact original spelling of `m_actionAnimationGuardWord`, whether the active-effect insert was authored as an inline helper, and low-level null timer-handler behavior should remain caveats in target prose.

## Final Recommendation

- Exact changes recommended: update UID0003Z5 metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:00007B`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007B`, and keep blank `EMITTER_POSITION_OPTIONAL`.
- Exact parent/source placement recommended: keep under [UID:00007B] `LivingObjectPane` and [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Exact split decision: do not split UID0003Z5; keep raw no-xref helpers and modeled methods in the same target, and preserve the `0x0053b6b3-0x0053b700` switch/table/padding boundary note.
- Exact C++ decision: replace the current formal C++ block with the first-draft code in `First-Draft C++ Recommendation`, including `m_pendingDamageEffect = 0`, provisional `m_actionAnimationGuardWord`, inline active-effect insertion, and unconditional final timer scheduling with `effect != 0 ? effect->GetTimerHandler() : 0`.
- Exact items left non-emitting/no-owner: none inside UID0003Z5. Raw helper starts remain documented as no-route private/retained helpers, not standalone no-owner pages.
- Future work outside this assignment: a broader LivingObjectPane class-layout pass may later recover exact private helper names and the final `+0x12a` member name, but those are not blockers for this target's first-draft source output.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`.
- Metadata changes: raise `COMPLETION` from `86` to `88`; raise `CONFIDENCE` from `88` to `90`; keep owner/emitter/reconstructable fields unchanged.
- Formal C++ change: replace the current `RECONSTRUCTION_CPP CODE` content with the exact first-draft block above.
- Prose facts to incorporate: live MCP session `18aed30a` health ok; raw helper no-xref status; function inventory and exact boundaries; vtable slot `0x006209ec -> 0x0053b3d0`; `0x0053b6b3-0x0053b700` switch/table/padding tail; Motion constructor as callee only; and generated C++ repair points.
- Historical/stale assumptions to preserve as rejected: current generated `m_stepCode` action guard, direct binary call to `RawAddActiveEffect` from `PlayActionAnimationOrEffect`, omission of `m_pendingDamageEffect = 0`, and always-cancel/always-schedule-shape in `BeginMoveTo`.
- Split/range note: keep the target as a single aggregate child and explicitly reject splitting raw no-route helpers into standalone source pages.

## Recommended Support Doc Changes

- [UID:00007B] `by-class/LivingObjectPane.md`: add or update a concise child-row/source-quality note that UID0003Z5 is recommended `88/90`, still emits through LivingObjectPane, and has first-draft C++ repair for active effects, movement, facing, damage refresh, and action effects. No broad class C++ should be populated.
- [UID:0000KU] `by-file/LivingObjectPane.md`: add or update a generated-output/source-child note that UID0003Z5 should remain an exact child output in `NexusTK/map/LivingObjectPane.cpp` after callback, with no by-file metadata or broad file C++ change.
- [UID:000358] `LivingObjectPaneVtableData`: no metadata or score change recommended. If touched during callback, preserve or add the existing support fact that primary slot `+0x70` / `0x006209ec` targets `0x0053b3d0`.
- [UID:0002R1] `LivingObjectPaneAnimationTimer`: no metadata or score change recommended. If touched during callback, preserve the boundary fact that `0x0053b6b3-0x0053b700` is UID0003Z5 action-helper switch/table/padding, not timer target code.
- [UID:0002QW] `MotionAnimationConstructor`: no metadata or score change recommended. If touched during callback, preserve the caller relationship from `0x0053b5f9` while keeping Motion constructor ownership with Motion.
- No generated files, coverage reports, tracker files, supervisor ledgers, validator state, or manual `-coverage-report.md` files should be edited by B005.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
- Reason to raise: current target-specific MCP evidence closes the direct-report gap and validates function boundaries, raw-helper status, ownership, vtable route, Motion dependency direction, timer semantics, and formal C++ repair requirements.
- Reason not higher: exact raw helper names are inferred; three raw starts still have no inbound route; the `+0x12a` action guard name is descriptive; active-effect insertion may have been source-authored as an inline helper but the binary shows no call edge; and the broad LivingObjectPane class declaration remains below final-source confidence.
- Reason not lower: the target already emits first-draft C++, the direct owner/emitter route is stable, vtable/data evidence proves the virtual action route, and the remaining issues are bounded source-name/source-shape caveats rather than ownership or reconstructability blockers.
- Metadata fields to leave unchanged: owner, reconstructable, emitter UID, optional emitter position, target path, and UID.

## Open Questions With Attempted Resolution

- Raw helper original names: checked xrefs, raw code shape, old reports, target generated output, and active-effect list behavior. Best resolution: retain descriptive names `RawAddActiveEffect`, `RawRemoveActiveEffect`, and `RawSetCurrentEffect` as private/retained helpers with no-route caveats. Impact: caps confidence; does not block C++.
- Raw helper liveness: checked `xrefs_to` and direct route evidence. Best resolution: no inbound route is proven; keep them in the aggregate and do not create standalone child pages. Impact: no split; confidence cap.
- `+0x12a` field name: checked `PlayActionAnimationOrEffect`, `BeginMoveTo`, support docs, and generated output. Best resolution: reject `m_stepCode`; use provisional `m_actionAnimationGuardWord` or equivalent descriptive field until a class-layout pass proves a better name. Impact: formal C++ caveat and score cap.
- Active-effect insertion source shape: checked `sub_53B3D0` decompile and raw helper no-xref status. Best resolution: the binary inlines the trim/insert logic; formal C++ should expand it or document an inline-equivalent helper. Impact: repair C++.
- Final schedule with null Motion allocation: checked `sub_53B3D0` decompile. Best resolution: preserve unconditional schedule using `effect != 0 ? effect->GetTimerHandler() : 0`; do not guard the schedule solely on `effect != 0`. Impact: repair C++.
- Broad class/file C++ readiness: checked `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`, and generated output. Best resolution: exact child emits C++; broad class/file declarations remain blank. Impact: no support metadata score changes beyond child/source-quality notes.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | ---: | --- | --- | --- | --- |
| C-0003Z5-01 | UID0003Z5 should remain owner/emitter [UID:00007B] LivingObjectPane through [UID:0000KU] LivingObjectPane.cpp. | High | Target/support docs, generated route, receiver fields, vtable slot `0x006209ec -> 0x0053b3d0`. | Target metadata/status; `by-class/LivingObjectPane.md`; `by-file/LivingObjectPane.md`; generated `auto-generated/NexusTK/map/LivingObjectPane.cpp` after scoped validator refresh | applied | Target owner/emitter unchanged; class/file support notes applied; generated header now lists UID0003Z5 under UID0000KU with command `000000007626`. |
| C-0003Z5-02 | Raise target score from `86/88` to `88/90`, not higher. | Medium-high | Current MCP resolves direct target evidence but C++ and raw-helper caveats remain. | Target metadata and Score Rationale | applied | Target metadata now `COMPLETION:88` / `CONFIDENCE:90`; validator `000000007624` recorded `completion_update 88` and `confidence_update 90`. |
| C-0003Z5-03 | Do not split raw no-xref helpers into standalone pages. | High | No inbound xrefs to `0x0053b060`, `0x0053b0e0`, `0x0053b190`; source-shaped but no route. | Target B005 evidence/status/rejected alternatives; class/file support notes | applied | No new child pages or split docs were created; target records raw starts as retained private helpers inside UID0003Z5. |
| C-0003Z5-04 | `0x0053b6b3-0x0053b700` is action-helper table/padding, not UID0002R1 code. | High | `get_bytes` tail/table/padding evidence; B007 UID0002R1 report. | Target B005 evidence/rejected alternatives; `by-class/LivingObjectPane.md`; `by-file/LivingObjectPane.md` | applied | Target/support notes record the boundary. UID0002R1 was not edited because current scope did not require a contradiction fix. |
| C-0003Z5-05 | `ClearAllEffects` clears both pending damage/effect and current effect. | High | `decompile 0x0053b130`: `this[126] = 0`, `this[112] = 0`. | Target formal C++; target touched-fields/status; class/file support notes | applied | Target and generated output now include `m_pendingDamageEffect = 0;` followed by `m_currentEffect = 0;`. |
| C-0003Z5-06 | `BeginMoveTo` current generated C++ is source-shape incorrect. | High | `decompile 0x0053b280` shows conditional cancel/TryStepForward, inline highlight restart, ObjectPane position setter, schedule args `(a5, a4, a5)`. | Target formal C++; target B005 evidence/status; class/file support notes | applied | Target and generated output now preserve the conditional moving branch, inline highlight restart, `SetPosition(x, y)`, and timer args `(stepDelay, facing, stepDelay)`. |
| C-0003Z5-07 | `SetFacing` name/behavior is stable enough for first draft. | High | `decompile 0x0053b360`; timer `iDhC`; `PlayAnimation(facing + 1)` route. | Target formal C++ and behavior notes | applied | Target first-draft C++ keeps `SetFacing(unsigned char facing)` with moving timer delay and non-moving `PlayAnimation(facing + 1)` path. |
| C-0003Z5-08 | `PlayActionAnimationOrEffect` is a LivingObjectPane virtual at slot `+0x70` and is reached through vtable dispatch from `TryPerformAction`. | High | `get_int 0x006209ec`; B014 TryPerformAction report. | Target B005 evidence/status; class/file support notes | applied | Target and support docs record `0x006209ec -> 0x0053b3d0`. Vtable support page was not edited because current docs did not require a contradiction fix. |
| C-0003Z5-09 | `PlayActionAnimationOrEffect` constructs Motion but remains LivingObjectPane-owned. | High | `decompile 0x0053b3d0`; B003 Motion constructor report proves sole Motion constructor caller and Motion owner route. | Target ownership/rejected alternatives; class/file support notes | applied | Target/support docs record `Motion::Motion` as callee-only through `0x0053b5f9`; Motion constructor support page was not edited because no contradiction fix was required. |
| C-0003Z5-10 | The generated `m_stepCode` action guard should be replaced with a provisional word at `+0x12a` caveat. | Medium-high | `decompile 0x0053b3d0`; `BeginMoveTo` decompile has no store to `+0x12a`; support docs mention `+0x12a` in other ObjectPane/LivingObjectPane contexts. | Target formal C++, touched fields, score cap, and open-question caveat | applied | Target/generated C++ now uses provisional `m_actionAnimationGuardWord`; target rejected alternatives explicitly reject stale `m_stepCode`. |
| C-0003Z5-11 | The non-animated action path inlines active-effect insertion and schedules even when Motion allocation fails. | High | `decompile 0x0053b3d0` list loop and unconditional `sub_597910(effect ? effect + 4 : 0, 0, 0, 0, 0)`. | Target formal C++ and source-shape notes; class/file support notes | applied | Target/generated C++ expands the active-effect trim/insert loop and schedules unconditionally with `effect != 0 ? effect->GetTimerHandler() : 0`. |
| C-0003Z5-12 | No lifecycle commands, generated-file manual edits, coverage edits, validator-state edits, archive moves, or supervisor-ledger edits should be run/made during callback; scoped validators are required after by-* edits. | High | Work log, scoped validator outputs, generated header, and changed-file scope. | Report `Validator Results`, `Changed Files`, and final response | applied | Scoped validators `000000007624`, `000000007625`, and `000000007626` were run. No `execute_report`, lifecycle/archive command, generated manual edit, coverage edit, validator-state edit, or supervisor-ledger edit was run/made by B005. |

## Validator Results

All validators were run from working directory `E:\NTK\GhidraBridge\source-3\project-documentation` with scoped file mode and `--apply --queue-timeout 240`.

| Command | File | command_id | command_timestamp | Exit | ok | Target-specific output |
| --- | --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md --apply --queue-timeout 240` | `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md` | `000000007624` | `2026-07-06T18:30:58-04:00` | 0 | 1 | `completion_update 88`; `confidence_update 90`; `autogen_registry_update` from `46bd1bf5e8630e7575d0b08116b8881d14d9997334db55a57011e7497d38469e` to `986a00f15f1c509bcfd342a9a9bc375d839dffbb6efa08cc51b0ce6d3fb7decd`; `reference_index_add 0002R1`; existing `missing_ref_uid 0003UD` warnings reported three times. |
| `python .\tools\validator.py --mode file --file by-class/LivingObjectPane.md --apply --queue-timeout 240` | `by-class/LivingObjectPane.md` | `000000007625` | `2026-07-06T18:31:04-04:00` | 0 | 1 | `reference_index_add 0003Z5`; existing support-page `missing_ref_uid` warnings reported, with 66 rows suppressed. |
| `python .\tools\validator.py --mode file --file by-file/LivingObjectPane.md --apply --queue-timeout 240` | `by-file/LivingObjectPane.md` | `000000007626` | `2026-07-06T18:31:17-04:00` | 0 | 1 | `reference_index_add 0003Z5`; existing support-page `missing_ref_uid` warnings reported, with 61 rows suppressed. |

Generated-output freshness was inspected read-only after validation. `auto-generated/NexusTK/map/LivingObjectPane.cpp` now has `validator-command-id: 000000007626`, `validator-refreshed-at: 2026-07-06T18:31:17-04:00`, and a UID0003Z5 emitted block at `Completion:88 | Confidence:90` containing the repaired first-draft C++.

No lifecycle/archive/report-execution command was run. No manual generated-file edit, coverage edit, `-coverage-report.md` edit, supervisor-ledger edit, or validator-state edit was made by B005.

## Changed Files

- Modified by B005: `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`.
- Modified by B005: `by-class/LivingObjectPane.md`.
- Modified by B005: `by-file/LivingObjectPane.md`.
- Modified by B005: `tools/leaser/Agents/Agent-B005/research/0003Z5-LivingObjectPaneEffectMovementAndActionHelpers-source-quality.md`.
- Refreshed by validator/autogen, not manually edited by B005: `auto-generated/NexusTK/map/LivingObjectPane.cpp`, with header `validator-command-id: 000000007626`.
- Created: none.
- Renamed: none.
- Support docs intentionally not edited: UID000358 vtable data, UID0002R1 animation timer, and UID0002QW Motion constructor pages, because no current contradiction requiring a narrow fix was found in the callback scope.
- Coverage reports, manual `-coverage-report.md` files, supervisor ledgers, validator state files, executed archives, lifecycle files, queue files, and generated files were not manually edited by B005.
- Lease release: B005 attempted to unlease the three edited by-* paths after validation; `leaser.py` returned `Rejected[No active lease]` for each, and both visible lease ledgers contained no B005 entries for these paths.
- Report execution: not run. B005 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, archive moves, or equivalent lifecycle/archive commands.

## Blockers And Residual Caveats

No operational blocker remains for supervisor execute review. MCP was available for the accepted research phase and no new MCP verification fact was required during callback implementation.

Source-quality caveats that should stay in the target after callback:

- Exact original names for raw helper methods are not recovered.
- Raw helpers `0x0053b060`, `0x0053b0e0`, and `0x0053b190` have no inbound route.
- `m_actionAnimationGuardWord` at `+0x12a` is descriptive/provisional. Do not keep the current `m_stepCode` name unless a later class-layout pass proves it.
- The active-effect add helper may be an inline-equivalent source helper, but the binary body at `0x0053b3d0` does not call raw start `0x0053b060`.
- Broad `LivingObjectPane` class declaration remains below final-source confidence, so this child should not drive broad class C++ emission.

## Implementation Tracking Checklist

Repair pass status:

- [x] Same report artifact repaired with exact required headings from current `goal.md`.
- [x] Useful prior research and first-draft C++ recommendation preserved.
- [x] Repair scope stayed inside `tools/leaser/Agents/Agent-B005/research/`.
- [x] During the earlier Gate 1 repair pass, no validators, lifecycle commands, by-* edits, generated edits, coverage edits, supervisor-ledger edits, or archive moves were run/made.

Initial report-only pass:

- [x] Supervisor validation completed; Gate 1 passed for accepted report SHA `F21D7BE545D8BB1DAAC86828CDB2B05C6DB5AF4E010BF58DCF93C2B9965CFA49`.
- [x] Target/support docs to update were identified: target `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`, support `by-class/LivingObjectPane.md`, and support `by-file/LivingObjectPane.md`; vtable, UID0002R1, and UID0002QW support pages were explicitly excluded because no contradiction fix was required.
- [x] Current target state and actual evidence checked recorded: original `86/88`, owner/emitter `00007B`, generated C++ output, MCP session `18aed30a`, function/raw-helper inventory, vtable slot, xrefs, boundary bytes, and old-report lead checks.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-0003Z5-01 through C-0003Z5-12 are now `applied`.
- [x] Metadata/score changes applied: target `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged.
- [x] Score-limiting caveats preserved: raw no-xref helpers remain no-split caveats; `+0x12a` remains provisional; active-effect insertion source shape is repaired in C++; broad class C++ remains out of scope.
- [x] Owner/emitter/reconstructable changes confirmed: none; preserved `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
- [x] Split/rename/new-child changes confirmed: none; UID0003Z5 was not split.
- [x] Source-placement, range/split/padding, and reclassification facts incorporated: LivingObjectPane source placement recorded; `0x0053b6b3-0x0053b700` switch/table/padding recorded; no IDA DB edits requested or made.
- [x] First-draft C++ applied: target formal C++ replaced with the accepted block from `First-Draft C++ Recommendation`.
- [x] Third-party import directive confirmed not applicable: this target is project-authored LivingObjectPane code, not a third-party static embed.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP session/health, range inventory, raw no-route status, vtable slot, Motion callee relationship, timer IDs, generated C++ repair points, score rationale, and rejected owners.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: rejected Motion/Timer/Map/Sound/Object/UserPane ownership, raw helper standalone split, generated `m_stepCode`, binary call to `RawAddActiveEffect`, and UID0002R1 absorption of `0x0053b6b3-0x0053b700`.
- [x] Wave2/Wave3 handling recorded: none used as evidence in this repair; old executed B reports were treated as leads and checked against current evidence.
- [x] Open questions documented with evidence-backed unresolved rationale: raw helper exact names, `+0x12a` final member name, inline-helper source shape, null timer-handler schedule semantics, and broad class declaration readiness.
- [x] Validators run after implementation callback for the target by-memory page and both changed support by-* pages.
- [x] Generated output refresh completed through validator/autogen only; no manual generated/coverage/tracker text was edited by B005.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated output refresh completed by validator/autogen; generated source inspected read-only.
- [x] Remaining unapplied accepted items: none.
- [x] Lease cleanup checked: release command returned `Rejected[No active lease]` for all three edited by-* paths, with no visible B005 lease entries remaining.
- [x] Lifecycle/archive/report-execution commands not run: no `execute_report`, dry-run/probing execute variant, validator registry lifecycle command, manual report move, archive move, or equivalent lifecycle/archive command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000007644","destination_path":"executed-b-agent-research/B005/0003Z5-LivingObjectPaneEffectMovementAndActionHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003Z5-LivingObjectPaneEffectMovementAndActionHelpers-source-quality.md","timestamp":"2026-07-06T18:59:01-04:00","uid":"0003Z5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
