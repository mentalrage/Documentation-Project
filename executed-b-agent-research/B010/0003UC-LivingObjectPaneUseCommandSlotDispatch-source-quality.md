** TARGET-REPORT-UID:0003UC **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003UC LivingObjectPane UseCommandSlot Dispatch Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0003UC] `0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch` as a source-authored `LivingObjectPane` command/spell-slot method.
- Final disposition: already implemented in current by-* docs as first-draft C++ `void LivingObjectPane::UseCommandSlot(unsigned char slot)` emitted through [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) into [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) / `NexusTK/map/LivingObjectPane.cpp`.
- Required action for this repair: report-text repair only. Remove the active-copy top-level revalidation status headers, historicalize the old `target_uid_unknown: 0003UC` lifecycle state, record current MCP evidence, and preserve the validator-owned history footer unchanged.
- Confidence: high. Current IDA MCP session `supervisor_recovery_20260705` is healthy and confirms the exact function, xref, callee, decompile, byte, and switch-table facts; current by-* docs already contain the accepted B010 implementation at same-or-greater detail.

## Supporting Research

- Historical lifecycle context: this report was previously marked `needs-revalidation` for `target_uid_unknown: 0003UC` by validator history command `000000004167` and was de-executed back to active Agent-B010 research by validator lifecycle command `000000006865` at `2026-07-05T07:16:12-04:00`.
- Current active-copy repair context: the old top-level validation-status line carrying `needs-revalidation` and the old top-level revalidation-reason line carrying `target_uid_unknown: 0003UC` were removed under the supervisor narrow override for this de-executed active research copy only. The prior status/reason are historical lifecycle facts, not current report status.
- Validator-owned footer context: the `VALIDATOR-REPORT-HISTORY` footer at the end of this report is preserved unchanged.
- Historical stale evidence: the old 2026-06-19 report text said IDA MCP was unavailable and relied on exported/local PE evidence. That is now stale. Current MCP evidence was collected from active session `supervisor_recovery_20260705` on 2026-07-05 and is incorporated below.
- Current target/support state: the target by-memory page and support docs already reflect the accepted B010 implementation from 2026-06-21; this report repair does not edit target/support by-* docs.

## Target

- Target UID: `0003UC`.
- Target path: `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`.
- Source route: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) / `NexusTK/map/LivingObjectPane.cpp`.
- Direct owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Current supervisor classification: reconstructable exact method child, source-authored command/spell-slot dispatcher.
- Current scores and parent state: target is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`.

## Current Target State

- Existing metadata in the target page is current: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`.
- Existing C++/emitter state is current: the target formal `RECONSTRUCTION_CPP CODE` block is populated with `void LivingObjectPane::UseCommandSlot(unsigned char slot)`.
- Historical pre-implementation state: older report text that described the target as `85/87`, blank C++, and unresolved source naming is now pre-callback/historical only.
- Current IDA name: `sub_5A4530`.
- Current function extent: `0x005a4530-0x005a4908`, size `0x3d8` / 984 bytes.
- Current UID/mapping state: read-only `tools/validator.ini` checks show `0003UC = by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`, completion `88`, confidence `90`, owner/emitter `00007B`, reconstruction code mode `block`, and source route [UID:0000KU].
- Existing support docs checked: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), [UID:0001KM][LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md), [UID:0003UA][LivingObjectPaneRawConfigHotkeyHelper](by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md), [UID:0003UB][LivingObjectPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.LivingObjectPaneExecuteHotkeyAction.md), [UID:0003UJ][LivingObjectPaneRawFunctionKeyDebounceHelper](by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md), and [UID:0001MQ][SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md).

## Executive Recommendation

Keep the current target implementation and documentation disposition. No by-* edit is required in this report-only repair unless a later supervisor implementation callback finds drift. If a callback is issued, verify the already-present target/support facts claim by claim rather than rewriting same-detail prose.

## Supervisor Active Recheck

- Current instruction: repair the same active report for UID `0003UC`, remove only the top-level status/reason lines, preserve the validator history footer, incorporate validator commands `000000006865` and `000000006866`, obtain current MCP evidence, and normalize to the current exact-heading B-agent template.
- No target/support by-* edits are authorized during this pass.
- No `execute_report`, dry-run/probing execute variants, registry lifecycle commands, archive commands, generated edits, coverage edits, validator-state edits, supervisor-ledger edits, or manual report moves were run or performed by B010 in this repair.

## Inference Research Guidance Check

- IDA MCP facts are treated as the current binary authority for start, size, xrefs, callees, bytes, decompile shape, and switch-table status.
- Existing by-* docs are treated as current documentation authority for owner/emitter/source route and implemented prose when they match MCP and target metadata.
- Historical generated names and old exported/local PE checks remain useful leads only. They are superseded where current MCP or current by-* docs are more specific.
- No Wave2/Wave3 material was used as proof for this repair.

## Heuristic / Inference Reanalysis And Validation

Best source-facing method name remains `LivingObjectPane::UseCommandSlot(unsigned char slot)`.

Validation:

- [UID:0001KM][LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md) names `0x005a4530-0x005a4908` as `UseCommandSlot` and distinguishes command/spell-slot dispatch from inventory-slot dispatch.
- [UID:0001MQ][SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) dispatches a letter-derived `1..52` slot through `g_pUserPane->UseCommandSlot(slot)`, rejecting direct packet send and generated spell-manager ownership for that accept handler.
- Current MCP confirms `sub_5A4530` validates a guard byte at `this+0x13ead4`, checks one-based slots via `(slot - 1) <= 0x33`, indexes a stride `0x148` command-slot record at `this+0x13a6ec + 0x148 * slot`, tests record byte `+0`, switches on record dword `+4`, opens prompt panes or sends opcode `0x0f` packets, and uses compiler vtable-store/EH/cookie scaffolding that must not be represented as handwritten source.
- Current MCP xrefs confirm eight direct code xrefs and no extra table route through the function start. The route pattern supports an ordinary source-authored method reached by hotkey/shortcut/input-pane consumers, with raw helper callers preserved as support rather than hidden ownership moves.

Rejected alternatives:

- `SpellManager::SelectSpell` and generated `g_pSpellMan`: rejected because the receiver/state is local-player/UserPane/LivingObjectPane command state, and the body opens panes or sends packets instead of merely selecting a spell.
- `LivingObjectPane::UseSpellSlot`: rejected as final source-facing name because it collides with older generated ambiguity around the paired inventory helper [UID:0001KN][UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md).
- `SpellInputPanes`, `SpellInventoryPane`, `TargetSelectionInputPanes`, `Socket`, and `PacketBuffer` ownership: rejected as direct ownership. They provide constructed panes, caller context, target helpers, or packet dependencies; the method body belongs to the local-player `LivingObjectPane` command family.
- Splitting per switch case: rejected. Current MCP and docs show one source switch with shared slot validation, EH cleanup, common prompt setup, and a single compiler jump table.

## Evidence Standards Used

- Current IDA MCP evidence: `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, `disasm`, and `analyze_function`, all scoped to `supervisor_recovery_20260705` and exact target addresses.
- Documentation evidence: current target and support by-* docs listed in `Current Target State`.
- Validator evidence: lifecycle command `000000006865` from footer and scoped target validator command `000000006866` from current `goal.md`.
- Negative evidence: `0x005a4908` is not a function; the adjacent table/padding is compiler output; no support page requires a new owner route; old MCP-unavailable wording is stale.
- Confidence limit: exact original source spellings for `SpellCommandSlotRecord`, `m_spellCommandSlotsReady`, target-position words, and a possible named immediate-packet helper remain inferred/descriptive, so `90` confidence is appropriate rather than final-source certainty.

## Evidence Checked

- MCP health: `server_health` on `supervisor_recovery_20260705` returned `status:"ok"`, `idb_path:"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"`, module `NexusTK.exe`, input path `C:\\Users\\admin\\Desktop\\Clone\\NexusTK\\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_size:2067`.
- MCP session state: `idb_list` returned count `1`, active worker session `supervisor_recovery_20260705`, `is_analyzing:false`, owned/adopted worker PID `19604`.
- Continuation MCP recheck for this repair resume: `server_health` again returned `status:"ok"` with `auto_analysis_ready:true` and `hexrays_ready:true`; `idb_list` again returned count `1`, active worker session `supervisor_recovery_20260705`, `is_analyzing:false`, PID/worker PID `19604`, and `last_accessed:"2026-07-05T07:33:01.723459"`.
- MCP function lookup: `lookup_funcs` returned `0x005a4530 -> sub_5A4530 size 0x3d8`; `0x005a4908` returned `Not a function`; `0x005a4930 -> sub_5A4930 size 0x5b`.
- MCP xrefs: `xrefs_to 0x005a4530 limit 20` returned eight code xrefs with `more:false`: `0x005a3ab8`, `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, `0x005a92c6`, `0x005a92eb`, `0x005a92ff`, and `0x005b62bd`.
- MCP callees: `callees 0x005a4530 limit 30` returned twelve callees: `0x004f4aa0`, `0x004f1c00`, `0x005374d0`, `0x005af4f0`, `0x004f20a0`, `0x00506970`, `0x0053b1b0`, `0x004f2b80`, `0x00575380`, `0x00574bb0`, `0x004f28a0`, and `0x005c772f`.
- MCP bytes: first 32 function bytes are `55 8b ec 6a ff 68 fc a4 60 00 64 a1 00 00 00 00 50 81 ec 9c 00 00 00 a1 24 2f 67 00 33 c5 89 45`. Switch-table/padding bytes at `0x005a4908` are `b3 45 5a 00 03 46 5a 00 0e 47 5a 00 5e 47 5a 00 ae 47 5a 00 ec 47 5a 00 3c 48 5a 00 89 48 5a 00 cc cc cc cc cc cc cc cc`.
- MCP decompile/analyze: confirms `void __thiscall sub_5A4530(_BYTE *this, char a2)`, guard `this[1305300]`, slot check `(unsigned __int8)(a2 - 1) <= 0x33`, stride `328 * a2`, record base `this + 1287916 + stride`, switch on `*((DWORD*)record + 1)`, prompt-pane construction cases, opcode `0x0f` no-argument packet case, targeted-action send, and compiler scaffolding.
- by-* docs checked: target, by-class `LivingObjectPane`, by-file `LivingObjectPane`, local-player split index, raw config hotkey helper, hotkey action helper, raw function-key debounce helper, SpellSpellInputPane accept handler, g_pCollectionData, g_activeMapPane, target-selection saved globals, and g_packetSender support.
- Validator state checked read-only: `tools/validator.ini` has current UID/path/score/owner/emitter/reconstruction-mode entries for `0003UC`.
- Failed/unavailable checks: none in current repair. The old MCP-unavailable note is historical and superseded.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| UC-001 | The old top-level `needs-revalidation` / `target_uid_unknown: 0003UC` headers are historical only and must not remain as current active-report status. | High | Supervisor override, footer command `000000004167`, de-execute command `000000006865`. | This report: `Supporting Research`, top-level headers. | Callback verified: active report top-level status/reason lines remain absent; historical lifecycle context remains in `Supporting Research` and the validator-owned footer. | applied |
| UC-002 | Current target metadata is `88/90`, owner/emitter `00007B`, reconstructable true, blank emitter position, formal C++ populated. | High | Current target header and read-only validator.ini mapping. | Target header and this report `Current Target State` / `Score And Metadata Recommendation`. | Callback verified already present in target header/formal block at same-or-greater detail. | already-present |
| UC-003 | Current MCP is available; old MCP-unavailable statement is stale. | High | `server_health` status ok, `idb_list` count 1 active worker session. | This report `Supporting Research`, `Evidence Checked`, `IDA MCP Facts`. | Callback verified report retains current MCP evidence and historicalizes the old unavailable statement. | applied |
| UC-004 | `0x005a4530` is `sub_5A4530`, size `0x3d8`, end `0x005a4908`; `0x005a4908` is not a function and `0x005a4930` starts the next function. | High | MCP `lookup_funcs`. | Target `Status`/`Evidence`/`Split And Range Decisions`; this report `Target`, `IDA MCP Facts`, `Range / Split / Padding / Reclassification Analysis`. | Callback verified already present in target range/status/evidence sections. | already-present |
| UC-005 | There are exactly eight direct code xrefs to the target start: `0x005a3ab8`, `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, `0x005a92c6`, `0x005a92eb`, `0x005a92ff`, `0x005b62bd`. | High | MCP `xrefs_to`, current target `Direct Callers`, split-index positive controls. | Target `Direct Callers`; support docs [UID:0001KM], [UID:0003UA], [UID:0003UB], [UID:0003UJ], [UID:0001MQ]. | Callback verified already present in target caller table and all listed support docs. | already-present |
| UC-006 | The function validates one-based command slots `1..52`, guard byte `+0x13ead4`, record base `+0x13a6ec + 0x148 * slot`, record active byte `+0`, input kind dword `+4`. | High | MCP decompile/analyze, target field table, class/file command-slot sections. | Target `Behavior And Case Map` and `Slot Table And Field Direction`; [UID:00007B] `Local-Player Command Slots`; [UID:0001KM] accepted case map. | Callback verified already present in target slot-field proof and support command-slot sections. | already-present |
| UC-007 | Case map is `1` string prompt, `2` target/who or immediate targeted send, `3` four-number prompt, `4` three-number prompt, `5` no-argument opcode `0x0f`, `6` two-number prompt, `7` one-number prompt, `8` spell-slot prompt. | High | MCP decompile/analyze, target behavior table, support docs. | Target `Behavior And Case Map`; [UID:0001KM]; [UID:00007B]; [UID:0000KU]. | Callback verified already present in target case map and listed support docs. | already-present |
| UC-008 | Adjacent `0x005a4908-0x005a4928` is the eight-entry compiler jump table and `0x005a4928-0x005a4930` is `0xcc` padding, not source body or separate method. | High | MCP `lookup_funcs` and `get_bytes`; target range section. | Target `Split And Range Decisions`; this report `Range / Split / Padding / Reclassification Analysis`. | Callback verified already present in target split/range section; no split edit required. | already-present |
| UC-009 | Direct vtable stores, EH state, SEH setup, security-cookie checks, and jump-table bytes must not be modeled as handwritten source. | High | MCP decompile/disasm/analyze, target compiler-artifact section. | Target `Heuristic / Inference Reanalysis And Validation`; this report `First-Draft C++ Recommendation`. | Callback verified already present in target compiler-artifact/no-source-body discussion and report recommendation. | already-present |
| UC-010 | Formal first-draft C++ should remain exact target insertion text for `LivingObjectPane::UseCommandSlot(unsigned char slot)`, not a body-only report sample. | High | Current target formal C++ block, B-agent template rule. | Target formal `RECONSTRUCTION_CPP CODE` block; this report `First-Draft C++ Recommendation`. | Callback verified already present as exact formal insertion text; no body-only/sample snippet found in target. | already-present |
| UC-011 | Source placement remains [UID:00007B] class owner, [UID:0000KU] file route; direct UserPane, SpellInputPanes, SpellInventoryPane, TargetSelectionInputPanes, Socket, and PacketBuffer ownership are rejected. | High | Current class/file docs and target heuristic section. | Target `Status`/`Heuristic`; [UID:00007B] `Local-Player Command Slots`; [UID:0000KU] B010 support sync. | Callback verified already present in target ownership section and class/file support docs. | already-present |
| UC-012 | Historical pre-implementation score `85/87` and blank-C++ wording are stale and must be labeled historical if mentioned. | High | Current target header and formal C++; old report text. | This report `Current Target State`, `Score And Metadata Recommendation`. | Historicalize stale wording. | applied |
| UC-013 | Supervisor scoped target validator command `000000006866` repaired/confirmed UID/path mapping, metadata, registry/reference indexes, projected stats, and deferred generated refresh; warnings for `0003UA`, `0003UB`, `0003UJ` are validator/index follow-up, not target-doc blockers. | High | Current `goal.md` command metadata. | This report `Validator Results`, `Changed Files`, `Implementation Tracking Checklist`. | Incorporate command metadata; exclude sibling warnings from target changes. | applied |
| UC-014 | Old manual coverage row recommendation is historical/superseded by validator-owned UID/path and generated refresh handling. | Medium-high | Current goal.md says command `000000006866` repaired mapping and generated refresh deferred; manual coverage edits forbidden. | This report `Exact Manual Supervisor-Owned Coverage Or Tracker Text`. | Exclude manual coverage edit with reason. | excluded-with-reason |

## Positive Evidence Summary

- Current MCP confirms a real function at `0x005a4530` with size `0x3d8`, a decompiled thiscall command-slot dispatcher shape, twelve known callees, and eight direct code xrefs.
- Current target/support docs already incorporate B010's source-facing method name, owner/emitter route, case map, slot-record offsets, switch-table boundary, compiler-artifact exclusions, and rejected generated names.
- The strongest inference chain is: IDA function and caller facts prove a live exact method; by-* class/file/split-index docs place local-player command-slot behavior under `LivingObjectPane.cpp`; the body semantics match command/spell-slot dispatch rather than SpellManager, UserPane, or packet-helper ownership.

## IDA MCP Facts

- Function/range facts: `0x005a4530 -> sub_5A4530`, size `0x3d8`; `0x005a4908` not a function; `0x005a4930 -> sub_5A4930`, size `0x5b`.
- Data/table/padding facts: bytes at `0x005a4908` decode eight dword case targets (`0x005a45b3`, `0x005a4603`, `0x005a470e`, `0x005a475e`, `0x005a47ae`, `0x005a47ec`, `0x005a483c`, `0x005a4889`) followed by eight `0xcc` bytes.
- Xref facts: eight code xrefs to the function start, with raw/no-function callers at `0x005a3ab8`, `0x005a92c6`, `0x005a92eb`, and `0x005a92ff`, modeled `sub_5A3AE0` callers at `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, and modeled `sub_5B6260` caller at `0x005b62bd`.
- Callee facts: allocation/base constructors/prompt setter/target helpers/packet writers/security cookie as listed in `Evidence Checked`.
- Negative IDA facts: no function object at the jump-table address; compiler vtable stores and security-cookie scaffolding are binary artifacts; current MCP did not support the old MCP-unavailable statement.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a4530-0x005a4908` | [UID:0003UC](by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md) | Source-authored `LivingObjectPane::UseCommandSlot(unsigned char slot)` command/spell-slot dispatcher. | TRUE | [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) | `88/90` | Current target; first-draft C++ already present. |
| `0x005a4908-0x005a4928` | compiler table, no UID in target | Eight-entry switch table for the source switch. | FALSE | ignored/compiler data | n/a | Do not emit or split as method body. |
| `0x005a4928-0x005a4930` | padding, no UID in target | Alignment bytes before next function. | FALSE | ignored/compiler padding | n/a | Do not emit. |
| `0x005a4930` | next IDA function `sub_5A4930` | Successor function start. | out of scope | out of scope | n/a | Boundary proof only. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a3ab8` | Raw compact shortcut helper [UID:0003UA] | Source-shaped retained shortcut support call; no ordinary live entry asserted for the raw helper. |
| `0x005a3bf2` | [UID:0003UB] `ExecuteHotkeyAction` | Live modeled hotkey call. |
| `0x005a3c28` | [UID:0003UB] `ExecuteHotkeyAction` | Live modeled hotkey call. |
| `0x005a3c4e` | [UID:0003UB] `ExecuteHotkeyAction` | Live modeled hotkey call. |
| `0x005a92c6` | Raw function-key debounce helper [UID:0003UJ] | Retained raw no-live-route support call. |
| `0x005a92eb` | Raw function-key debounce helper [UID:0003UJ] | Retained raw no-live-route support call. |
| `0x005a92ff` | Raw function-key debounce helper [UID:0003UJ] | Sentinel/invalid-key dispatch support call. |
| `0x005b62bd` | [UID:0001MQ] `SpellSpellInputPaneAccept` | Live vtable-reached accept-handler call after letter-to-slot mapping. |

## Documentation Evidence And IDA Status

- Target page already has the current formal C++ block, score/metadata, item summary, direct callers, callees, behavior/case map, slot table, split/range decision, heuristic reanalysis, C++ notes, score rationale, open questions, and cross-references.
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) already has a `Local-Player Command Slots` section with this target's source-quality method model, slot-record offsets, case map, direct callers, and ownership rejection notes.
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) already records `LivingObjectPane::UseCommandSlot(unsigned char slot)` as an exact first-draft child under `map/LivingObjectPane.cpp`.
- [UID:0001KM][LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md) already records this range as `UseCommandSlot`, the exact range, switch-table boundary, caller set, no pointer route, case map, and generated-name rejections.
- Existing docs that were stale: this report's old top-level status headers, old MCP-unavailable statement, old `85/87`/blank-C++ current-state wording, and old manual coverage-row recommendation.

## Ranked Ownership Analysis

### 1. LivingObjectPane / LivingObjectPane.cpp

- Evidence for: current target metadata owner/emitter [UID:00007B]; class/file docs place command-slot methods in `LivingObjectPane.cpp`; current MCP shows thiscall receiver and local-player command-slot fields; caller docs route hotkeys and spell-input accept handling through `UseCommandSlot`.
- Evidence against: the receiver is an adjusted local-player/UserPane aggregate in some paths, and the method creates SpellInputPane objects and sends packets.
- Decision: accepted direct owner/emitter. The dependencies are not owner moves.

### 2. UserPane

- Evidence for: `g_pUserPane` / `dword_67A748` local-player state and adjusted offsets are involved; [UID:0001MQ] calls through `g_pUserPane`.
- Evidence against: class/file docs consistently route movement/object/command behavior to `LivingObjectPane`; exact target metadata owns/emits through [UID:00007B]; UserPane owns local UI/event surface, not this method's command-slot implementation.
- Decision: rejected as direct owner, retained as state/caller context.

### 3. SpellInputPanes / SpellInventoryPane / TargetSelectionInputPanes / Socket

- Evidence for: the method constructs spell input panes, uses target selection, and writes opcode `0x0f` packets.
- Evidence against: these are dependencies or consumers. They do not own the dispatcher receiver, slot table, hotkey route, or command-slot source family.
- Decision: rejected as direct owners.

## Source Placement

- Recommended source file/class placement: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) exact child emitted through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) / `NexusTK/map/LivingObjectPane.cpp`.
- Why this fits: command/spell-slot behavior is in the local-player `LivingObjectPane` extension family, paired with inventory/action/movement methods under the same class/file route.
- Rejected placements: `UserPane.cpp`, `SpellInputPanes.cpp`, `SpellInventoryPane.cpp`, `TargetSelectionInputPanes.cpp`, Socket/PacketBuffer helpers.
- Remaining uncertainty: exact original field/type spellings and helper declarations remain inferred, but they do not change source placement.

## Range / Split / Padding / Reclassification Analysis

- Keep target range `0x005a4530-0x005a4908`.
- Do not split the eight switch cases into child pages; they are one source switch in one method.
- Treat `0x005a4908-0x005a4928` as compiler switch data and `0x005a4928-0x005a4930` as alignment padding.
- Do not merge the switch table into the source C++ body and do not create standalone C++ for it.
- Current target is not a no-code/non-emitting target. It is reconstructable and has first-draft formal C++.

## Negative Evidence Summary

- `0x005a4908` is not a function, so the adjacent table is not a child method.
- Compiler vtable stores, SEH state, and security cookie should not be treated as source-authored statements.
- Generated names `sub_5A4530`, `meth_0x5a4530`, `SpellManager::SelectSpell`, `g_pSpellMan`, and ambiguous `UseSpellSlot` are rejected.
- Read/state dependencies on UserPane, SpellInputPanes, TargetSelectionInputPanes, Socket, PacketBuffer, and MapPane do not prove ownership.
- Manual coverage editing is rejected for this repair because validator-owned UID/path state has been repaired and generated refresh is validator-owned/deferred.

## IDA Rename / Type / Comment Recommendations

- Source-facing method name: `LivingObjectPane::UseCommandSlot(unsigned char slot)`.
- Source-facing type/name directions already used in target C++: `SpellCommandSlotRecord`, `m_spellCommandSlotsReady`, `GetSpellCommandSlotRecord`, `inputKind`, `active`, `MapPosition`, `SendImmediateSpellCommand`, `g_activeMapPane`, `g_pUserPane`, and `s_spellWhoTargetId`.
- IDA database edits are not requested in this report-only repair.
- Keep raw IDA names as evidence only where current IDB still displays them.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, already populated in the target.
- Recommended code: keep the current target formal `RECONSTRUCTION_CPP CODE` block. This is exact formal insertion text, not a body-only/sample side snippet.
- Reason it preserves behavior: it preserves the guard, slot range, active-record test, input-kind switch, target fast path, prompt-pane construction choices, no-argument opcode `0x0f` send, and no default side effects.
- Reason it matches plausible original source shape: it uses source-level constructors/helpers and descriptive field names instead of compiler vtable stores, EH state, raw stack temporaries, or decompiler labels.
- Reason not higher/final: field/type/helper spellings remain descriptive reconstruction names, not recovered original symbols.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::UseCommandSlot(unsigned char slot)
{
    if (!m_spellCommandSlotsReady) {
        return;
    }

    if (slot == 0 || slot > 52) {
        return;
    }

    SpellCommandSlotRecord *record = GetSpellCommandSlotRecord(slot);
    if (record == NULL || !record->active) {
        return;
    }

    switch (record->inputKind) {
    case kSpellInputString:
        new SpellStringInputPane(slot);
        return;

    case kSpellInputTarget:
        if (g_activeMapPane != NULL && g_activeMapPane->HasPendingSpellTarget()) {
            LivingObjectPane *target = g_activeMapPane->GetPendingSpellTarget();
            if (target != NULL) {
                MapPosition firstPosition;
                MapPosition secondPosition;
                target->GetMapPosition(&firstPosition);
                target->GetMapPosition(&secondPosition);
                SendTargetedActionPacket(slot, target->GetObjectId(),
                                         secondPosition.word1, firstPosition.word0);
                return;
            }
        }

        new SpellWhoInputPane(slot);
        {
            LivingObjectPane *target = NULL;
            if (g_activeMapPane != NULL) {
                target = g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
            }

            if (target == NULL || target->GetObjectType() != kObjectTypeLiving ||
                target->IsTargetSuppressed()) {
                target = g_pUserPane;
            }

            if (target != NULL) {
                target->SetTargetHighlight(true);
                s_spellWhoTargetId = target->GetObjectId();
            }
        }
        return;

    case kSpellInputFourNumbers:
        new SpellFourArgsInputPane(slot);
        return;

    case kSpellInputThreeNumbers:
        new SpellThreeArgsInputPane(slot);
        return;

    case kSpellInputNone:
        SendImmediateSpellCommand(slot);
        return;

    case kSpellInputTwoNumbers:
        new SpellTwoArgsInputPane(slot);
        return;

    case kSpellInputOneNumber:
        new SpellOneArgInputPane(slot);
        return;

    case kSpellInputSlot:
        new SpellSlotInputPane(slot);
        return;

    default:
        return;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- Accept the current target/support by-* state as already incorporating the valid B010 research at report-level detail.
- Keep target score/metadata at `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`.
- Keep the formal first-draft C++ block populated as above.
- Keep source placement under [UID:00007B] / [UID:0000KU].
- Do not edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers from this B010 repair.
- Future work outside this repair: final-source audit of exact record type declarations, guard byte spelling, target-position word names, and whether `SendImmediateSpellCommand` was a named helper or inline packet-buffer sequence.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`.
- Current disposition: no immediate target edit recommended during this report-only repair. The target already contains the accepted metadata, formal C++ block, item summary, current source-facing name, evidence, direct caller table, callee table, case map, slot-field table, split/range decision, rejected names/owners, score rationale, and open-question closure.
- If supervisor sends an implementation callback despite the already-present state, validate claim IDs UC-002 through UC-011 against the target and edit only if a drift is found.

## Recommended Support Doc Changes

- Support docs currently checked at same-or-greater detail: `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`, `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`, `by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md`, `by-memory/0x005a3ae0-0x005a3d39.LivingObjectPaneExecuteHotkeyAction.md`, `by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md`, and `by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md`.
- Current disposition: no support by-* edits recommended during this report-only repair. These docs already preserve source placement, caller/callee routes, raw-helper caveats, rejected naming, and command-slot semantics.
- Manual support coverage text from the old report is superseded. Generated/tracker refresh belongs to validator/supervisor lifecycle after Gate 1/Gate 2, not B010 manual edits.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`, formal C++ block populated.
- Recommended score/metadata: unchanged.
- Historical score/metadata: pre-callback report text said `85/87` and blank C++; that is historical and no longer current.
- Score rationale: `88` completion is justified by resolved owner/source route, exact range, caller/callee facts, case map, slot-field roles, compiler-artifact exclusions, switch-table boundary, and first-draft C++ readiness. `90` confidence is justified by current MCP agreement with current by-* docs and prior PE/exported evidence, but not higher because exact original field/type/helper spellings are still inferred.
- Metadata fields to leave unchanged: owner/emitter/reconstructable/emitter-position.

## Open Questions With Attempted Resolution

- Exact original spelling for `SpellCommandSlotRecord`, `m_spellCommandSlotsReady`, `GetSpellCommandSlotRecord`, and target-position word fields remains unrecovered. Current descriptive names are sufficient for first-draft C++ and are clearly inferential.
- Case `5` may have been a named `SendImmediateSpellCommand` helper or an inline packet-buffer sequence. Current C++ uses a helper-shaped source abstraction; future source-family declaration work can inline it if broader style evidence demands that.
- The broader local-player/UserPane aggregate type remains outside this target's exact method page. The current target records only field roles needed by `UseCommandSlot`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable for B010 to apply in this repair.
- Historical old-report coverage row text for UID `0003UC` is superseded by current validator-owned UID/path repair. Command `000000006866` repaired/confirmed target path/UID mapping and deferred generated refresh.
- Do not manually edit `by-memory/-coverage-report.md`, generated tracker files, or validator state from this report.

## Follow-Up Actions

- Supervisor Gate 1: audit this repaired active report artifact by current hash and headings.
- Supervisor Gate 2/execute path, if Gate 1 passes: verify claim ledger states against current target/support docs; most accepted claims should be `already-present`.
- B010: no by-* implementation work is pending unless supervisor sends a specific implementation callback after Gate 1.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for retaining `88/90`; current MCP and current by-* docs agree.
- Remaining uncertainty: exact original source spellings for several reconstructed names and full local-player aggregate declarations.

## Validator Results

- B010 did not run validators, `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, generated edits, coverage edits, validator-state edits, supervisor-ledger edits, or manual report moves during this repair.
- Historical validator history command `000000004167`: marked the executed report `needs-revalidation` for `target_uid_unknown: 0003UC` at `2026-07-01T19:52:03-04:00`; preserved in footer as validator-owned history.
- Lifecycle command `000000006865`: de-executed the report from `executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md` to `tools/leaser/Agents/Agent-B010/research/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md` at `2026-07-05T07:16:12-04:00`; preserved in footer as validator-owned history.
- Supervisor scoped target validator command `000000006866`: timestamp `2026-07-05T07:16:33-04:00`, exit `0`, `ok: 1`. Reported effects per current `goal.md`: repaired/confirmed target path/UID mapping, inserted a blank header field, updated completion `88`, confidence `90`, canonical owner `00007B`, autogen registry/reference indexes, projected stats, and deferred generated refresh.
- Current warning disposition from command `000000006866`: missing-ref UID warnings for `0003UA`, `0003UB`, and `0003UJ` are validator/index follow-up unless directly in scope; this report does not edit those docs or validator state.
- Current MCP recheck for this continuation was not a validator command and has no command ID. It confirmed the listener/session/process state and target facts without running lifecycle, registry, generated, coverage, or by-* validators.
- Implementation callback / already-present verification pass after Gate 1 did not run scoped file validators because no by-* drift was found and no by-* docs were edited.

## Changed Files

- Modified: `tools/leaser/Agents/Agent-B010/research/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md`.
- Callback update: report ledger/checklist/validator notes only, recording already-present verification for accepted claims UC-001 through UC-011.
- Removed from active report top level: the validator status line carrying `needs-revalidation` and the validator reason line carrying `target_uid_unknown: 0003UC`.
- Preserved unchanged: validator-owned `VALIDATOR-REPORT-HISTORY` footer.
- Not modified: target/support by-* docs, generated files, project-level generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files.
- Report execution: not run.

## Implementation Tracking Checklist

Current report repair pass:

- [x] Read current Agent-B010 `goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` and current B-agent report template.
- [x] Removed only the two top-level active-copy status/reason lines under the supervisor narrow override.
- [x] Preserved the validator-owned `VALIDATOR-REPORT-HISTORY` footer unchanged.
- [x] Historicalized `needs-revalidation` / `target_uid_unknown: 0003UC` under `Supporting Research`.
- [x] Replaced stale MCP-unavailable current-state language with current MCP evidence from `supervisor_recovery_20260705`.
- [x] Incorporated validator lifecycle command `000000006865`.
- [x] Incorporated scoped target validator command `000000006866`, timestamp `2026-07-05T07:16:33-04:00`, exit `0`, `ok: 1`, effects, deferred generated refresh, and sibling missing-ref warning disposition.
- [x] Current target state recorded as `88/90`, owner/emitter [UID:00007B], reconstructable true, formal C++ populated.
- [x] Historical pre-callback `85/87` and blank-C++ wording labeled stale/pre-callback where mentioned.
- [x] Claim And Incorporation Ledger maps accepted facts to target/support/report destinations with `applied`, `already-present`, or `excluded-with-reason` states.
- [x] First-draft C++ appears only as exact formal `RECONSTRUCTION_CPP CODE` insertion text.
- [x] Target/support docs verified read-only for same-or-greater detail where needed; no by-* edits made.
- [x] Manual coverage/tracker row recommendation excluded as validator-owned/generated-refresh work.
- [x] No generated, project-level, coverage, validator-state, lifecycle/archive, or supervisor-ledger files edited.
- [x] No `execute_report`, dry-run/probing variant, registry lifecycle command, archive command, or manual report move run.
- [x] Supervisor Gate 1 passed at SHA256 `B3F6E7D506A39465717481D9144F21609932999ECB68F71106C69C271732B221`.

Implementation callback / already-present verification pass:

- [x] Re-read the report `Claim And Incorporation Ledger` and `Implementation Tracking Checklist`.
- [x] UC-001 verified applied: active report top-level status/reason lines remain absent; historical lifecycle context is preserved in the body/footer.
- [x] UC-002 verified already-present: target metadata/formal C++ block already match the accepted state.
- [x] UC-003 verified applied: report body retains current MCP evidence and treats the old unavailable state as historical.
- [x] UC-004 verified already-present: target records `sub_5A4530`, size `0x3d8`, end `0x005a4908`, switch-table boundary, padding, and next function.
- [x] UC-005 verified already-present: target/support docs record the exact eight direct caller sites.
- [x] UC-006 verified already-present: target/support docs record slot validation, guard byte, record base, active byte, and input-kind dword.
- [x] UC-007 verified already-present: target/support docs record the accepted case map for kinds `1` through `8`.
- [x] UC-008 verified already-present: target records the jump table and padding as compiler data, not a separate source body.
- [x] UC-009 verified already-present: target/report exclude vtable stores, EH/SEH, cookie checks, and jump-table bytes from handwritten source.
- [x] UC-010 verified already-present: target formal C++ is exact insertion text and no body-only/sample snippet required removal.
- [x] UC-011 verified already-present: class/file route and rejected ownership alternatives are already documented.
- [x] No drift found in accepted target/support destinations; no by-* files edited.
- [x] No leases used because no by-* edits were required.
- [x] No scoped validators run because no by-* files were edited.
- [x] Generated files, coverage files, validator state, lifecycle/archive files, and supervisor ledgers left untouched.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UC","source_path":"executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006865","destination_path":"tools/leaser/Agents/Agent-B010/research/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md","timestamp":"2026-07-05T07:16:12-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006877","destination_path":"executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md","timestamp":"2026-07-05T07:41:27-04:00","uid":"0003UC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
