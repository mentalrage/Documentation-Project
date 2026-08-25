** TARGET-REPORT-UID:0003U7 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003U7 UserPaneInitializeWalkAnimation Source-Quality Research

## Finalized Report / Current Recommendation

- Current result: UID0003U7 remains the exact source-authored `UserPane::InitializeWalkAnimation(unsigned char direction)` member at `[0x005a36f0,0x005a3766)`, with class owner/emitter UID0000FQ and the `UserPane.cpp` route; the stale field expression and stale MapPane semantic alias have been corrected in its managed definition.
- Final disposition: one reconstructable, emitting source method. No source split, wrapper, compiler-product, vtable entry, callback-table entry, or no-code disposition is justified.
- Completed target action: `86/88 -> 92/94`, with `RECONSTRUCTABLE:TRUE`, owner/emitter UID0000FQ, blank emitter position, and `Nested:0` retained; Destination 1 is exact and the lower stale `Open Questions` assertions are dated superseded history rather than deleted provenance.
- Completed bounded support action: Destinations 2-5 are exact, UID0003U8 and UID0003UQ remain `86/88`, UID0002CF/UID00027F now carry signed-byte evidence at `91/93` and `90/93`, and `[0x005a3766,0x005a3770)` is recorded as ten bytes of compiler/linker alignment in `by-memory/-ignored.md`.
- Confidence: very strong for function identity, range, ABI, execution order, receiver layout, calls, timer event, field offsets, scale signedness, liveness, and source route; strong for stripped private method/global spellings.

## Supporting Research

- Evidence-time MCP state: B004 initialized a fresh streamable MCP client at `2026-07-15T01:34:16-04:00`. `idb_list` returned the sole active/adopted NexusTK database `2198f811`, worker PID `19764`; `server_health(database=2198f811)` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready, and 2067 cached strings. A bounded target/successor lookup and bounded target/padding byte read succeeded. This records evidence-time health and does not assert indefinite worker availability.
- Final evidence-time closure at `2026-07-15T01:44:18.3262488-04:00` repeated `idb_list`, `server_health`, `lookup_funcs(0x005a36f0)`, and `get_bytes(0x005a3766,10)`: the same sole worker/session was healthy, the target remained `sub_5A36F0` size `0x76`, and the boundary remained ten `cc` bytes. This is a bounded verification-time observation, not a durable availability claim.
- Interruption handling: stale database `46dda60b` was not reused. Work stopped during the supervisor-declared outage and resumed only after the supervisor restored the worker. MCP-dependent facts gathered around the interruption were repeated against `2198f811`.
- One broad whole-code text search for `byte_66DA96` exceeded the MCP tool's 60-second internal timeout. Immediate `idb_list`, `server_health`, target lookup, and bounded reads proved the listener and worker remained healthy; B004 replaced the broad query with bounded disassembly of all 14 already enumerated reader functions. That bounded pass returned all 23 direct reads and their load forms.
- Active-report search terms: `UID0003U7`, `0003U7`, `0x005a36f0`, `0x005a3766`, `UserPaneInitializeWalkAnimation`, `InitializeWalkAnimation`, `UID0003U6`, `UID0003U8`, `UserPane`, `LivingObjectPane`, `TimerMgr`, `g_movementSubstepScale`, and `ObjectStatusBlob`.
- The matching B001 report that was active when searched was `tools/leaser/Agents/Agent-B001/research/0003U6-UserPaneProcessMovement-source-quality.md`, SHA256 `F8D1E6AA96A4CA09101A62BBB3DE476C81E88F3BB8A62C21D083556330DF50FE`. It independently fixes the predecessor endpoint, proves the attached switch material through `0x005a36f0`, and treats UID0003U7 only as a verify-only successor. It is a compatible boundary lead, not a competing UID0003U7 report.
- Exact target matches opened under `executed-b-agent-research`: B001 `00007B-LivingObjectPane-class-source-quality.md`, `0001KM-livingobject-localplayer-source-split-audit.md`, `0001KM-livingobject-localplayer-source-split-retry.md`, `00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`, `0002CF-g_movementSubstepScale.md`, `0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`, `0003Z4-LivingObjectPaneLinkedObjectSetupHelpers-source-quality.md`; B005 `00037X-MapPaneInteractionMapChangeCore-source-quality.md`; and B007 `0002R1-LivingObjectPaneAnimationTimer-source-quality.md`.
- Executed-report disposition: UID0002QY's UserPane owner/route and nonblank target integration remain current, but its inherited `m_movementSpeed` expression is superseded by current ObjectStatusBlob layout and live offset evidence. UID0002CF's 23-reader inventory and MapPane ownership remain current, but its unsigned declaration is superseded because every live reader sign-extends the byte. UID00024A's `m_mapPane` field, UID0002R1's timer/event model, UID0003Z4's LivingObjectPane timer constants, and B005's MapPane object-screen-bounds helper identity remain current corroboration.
- `tools/leaser/Agents/Older-Research` was searched explicitly. It contained three Markdown reports and no match for UID0003U7, its address/name, UserPane/LivingObjectPane family, or movement-scale terms; one `TimerMgr`-only match in an unrelated ScrollCollection report was opened/classified as irrelevant.
- `tools/leaser/Agents/SpecialReports` contained five Markdown reports and no match for the exact UID/range/name or relevant source-family terms.
- The actual archive root `source-3/project-documentation/archived` existed and contained zero Markdown reports when searched; all exact and family searches therefore returned no archive report.
- Evidence-time generated lead `auto-generated/NexusTK/ui/panels/UserPane.cpp` initially had SHA256 `4165B1D63EB9BE7C96327B0397C675AD69E2D00FF563EE839E88179389885402`. An external read-only refresh at `2026-07-15T01:42:04.7738884-04:00` produced SHA256 `4483C82041930CB3DD56FEAFF06BC19C54113ABA4170F9E0443ADC548CA3E30C` without changing the relevant 64,237-byte source state: one UID0003U7 definition, zero target Empty Emitter Markers, and four stale `m_objectStatus.m_movementSpeed` references at lines 512, 540, 1219, and 1246. Generated source was treated as a lead, not binary authority, and B004 did not edit it.
- Historical callback authorization: the supervisor accepted exact pre-callback report SHA256 `4A64459D38D69C1C4B71E63E52797EEE84A6EDFF1CCD90F0D0FA1A75CB066B49` at `2026-07-15T01:46:32-04:00`. That hash identifies the accepted historical revision, not this mutated callback artifact.
- Callback implementation used six short ordinary-file leases, scoped validator commands `000000012693` through `000000012698`, and waited refresh command `000000012699`; every lease was released immediately after its file's validation window.
- Post-callback generated readback at validator timestamp `2026-07-15T01:54:32-04:00`: `UserPane.cpp` SHA256 `DDE87CCDC7700348665C170FF768C18909CF4636125EF77B46E3152AA3856EEA`, 64,313 bytes, 1,739 lines; `MapPane.cpp` SHA256 `1DBEA0BAAEA313EE54737C5D9D75AAB18BFCE2680DB9CEE8D9F7D08D0C783B94`, 75,956 bytes, 2,173 lines. Both generated headers identify command `000000012699` and `foreground-generated-refresh`.
- Supervisor manual-coverage application is complete. Command `000000012707` at `2026-07-15T02:29:39-04:00` validated `by-memory/-coverage-report.md` with exit 0 / `ok:1`; current SHA256 `96546FE73C04070B835DA2C2656092D3E40E77B3CBAE29A7C803C23B0BEF8990`. Command `000000012708` at `2026-07-15T02:29:45-04:00` validated `by-global/-coverage-report.md` with exit 0 / `ok:1`; current SHA256 `7E02F744D4AFC5259002545D36C13B8FDBA0D3F93FD851F96DC830765E8296F1`.

## Target

- Target UID: `0003U7`.
- Target path: `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md`.
- Assigned report artifact: `tools/leaser/Agents/Agent-B004/research/0003U7-UserPaneInitializeWalkAnimation-source-quality.md`.
- Historical source queue/report snapshot: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; the evidence-time row reported `86/88`, reconstructable true, and direct report count zero. Tracker/count state is external validator/supervisor-owned and is not asserted as current here.
- Historical assignment classification: report-only target-specific source-quality research. The supervisor later accepted that exact artifact and authorized this bounded implementation callback.
- Current implemented target state: completion 92, confidence 94, canonical owner UID0000FQ, emitter UID0000FQ, reconstructable true, blank emitter position, `Nested:0`.

## Current Target State

- Existing valid metadata: UID, path, exact range, owner/emitter UID0000FQ, reconstructable state, blank position, and `Nested:0` are correct.
- Existing valid source route: class UID0000FQ `UserPane`, file UID0000P1 `UserPane`, generated route `NexusTK/ui/panels/UserPane.cpp`.
- Existing valid formal shape: the nonblank `void UserPane::InitializeWalkAnimation(unsigned char direction)` body, state-reset order, timer event, and final map refresh are substantially correct.
- Resolved target defect 1: `m_objectStatus.m_movementSpeed` was replaced by current authoritative `m_objectStatus.m_displayStatusByte` for machine offset `UserPane + 0x1a0` (`LivingObjectPane + 0x178 + 0x28`).
- Resolved target defect 2: the stale `m_mapPane->InvalidateObject(this)` alias was replaced by exact child UID0004DS identity `m_mapPane->UpdateObjectPaneScreenBounds(this)`.
- Resolved target defect 3: the lower pre-2026-07-14 blank-C++/open-name assertions are explicitly historicalized while their provenance remains intact.
- Resolved support defects: UID0003U8 contains the corrected field and exact MapPane callee; UID0003UQ contains both corrected field expressions and all three exact MapPane calls; UID0002CF now declares plain `char` and UID00027F records all signed-reader/storage evidence without duplicate emission.
- Resolved boundary defect: `[0x005a3766,0x005a3770)` is recorded once as ten all-`0xcc` compiler/linker alignment bytes in `by-memory/-ignored.md`.
- Current callback state: all accepted implementation, scoped validation, formal equality, generated readback, and checklist work is complete. B004 performed no report execution, lifecycle, count, move, or archive command. Report validation/execution/count/path/archive state is external supervisor/validator-owned and is not asserted here.
- Current manual-coverage state: the supervisor applied and validated the accepted UID0003U7 replacement, UID0000VN padding insertion, UID00027F replacement, and UID0002CF replacement through commands `000000012707` and `000000012708`; no manual coverage action remains.

## Executive Recommendation

- UID0003U7 remains one `UserPane` member under UID0000FQ/UID0000P1; it was not renamed, split, de-emitted, or moved to LivingObjectPane, MapPane, TimerMgr, or a packet module.
- The target now uses `m_objectStatus.m_displayStatusByte` and `m_mapPane->UpdateObjectPaneScreenBounds(this)` while retaining exact side-effect order and unguarded signed division.
- Retain `InitializeWalkAnimation` as the highest-probability descriptive private-member name. It distinguishes this initializer from sibling UID0003U8 `StartDirectionalAnimation`, which selects a human-image animation group and derives a frame delay when applicable.
- Retain parameter name/type `unsigned char direction`. Callers pass byte direction values `0..3`, packet callers use `4` as the no-direction sentinel before suppressing the call, and the target stores the byte into `m_facing`. IDA's stack `char` and `movsx` at one call argument do not establish a semantically signed direction.
- Target score is `92/94`; every named blocker has a current resolution, the complete body is emitted, and remaining uncertainty is stripped private spelling rather than behavior or source legality.
- UID0003U8 and UID0003UQ formal blocks are corrected without changing their scores or unrelated behavior; this bounded callback does not inflate them.
- UID0002CF is a MapPane-owned file-static plain `char` at `91/93`; exact storage UID00027F is signed-reader-aware `90/93` with covered-by emitter disposition and direct MapPane ownership preserved.
- UID0000VN contains the exact ten-byte alignment row. It remains compiler/linker padding between two independent source methods, not part of either source body.

## Supervisor Active Recheck

- Trigger: the supervisor assigned UID0003U7 because the tracker showed zero direct reports and the current page combined an `86/88` score with contradictory blank/nonblank source claims.
- Split-first result: no source split is required. The target is one IDA-modeled 118-byte function, one basic block, with no internal entry, jump table, data island, EH helper, or compiler wrapper.
- Source-bearing child result: not applicable; the target itself owns the complete body. The successor gap is padding, not a child.
- Every named blocker in the goal was investigated: range, boundary, ABI, calls, callers, fields, helpers, event, scale type, map call, liveness, class/file route, historical contradiction, score, formal C++, and manual coverage disposition all have implementation-ready outcomes.
- Collision recheck: the only active exact-family report when searched was B001's UID0003U6 predecessor report; it does not own or propose edits to UID0003U7. No B001-B005 current goal/report targeted this UID.
- Callback completion recheck: all six accepted ordinary destinations were reread under short B004 leases, validated individually, and released; all five destination managed blocks are exactly equal to the accepted report blocks after validation.

## Inference Research Guidance Check

- `by-structure.md` and the B-agent score standard were applied by preserving direct class/file ownership, avoiding ownership from mere consumers, keeping padding separate, and requiring a complete managed destination block for every C++ change.
- Assumptions treated as uncertain: current stripped method name, unsigned scale type, synthetic movement-speed field, generic map invalidation alias, LivingObjectPane ownership history, below-95 blank-C++ history, and the claim that no final names were available.
- Direct IDA fact: bytes, range, one-block CFG, instruction order, offsets, call targets, four callers, data/global reads, event literal, return cleanup, ten-byte padding, and all 23 signed scale loads.
- Documentation evidence: current class layouts, field names, timer enums, helper pages, source routes, support scores, old-report provenance, generated source, tracker row, and manual coverage rows.
- Inference: stripped source spelling `InitializeWalkAnimation`, parameter spelling `direction`, global spelling `g_movementSubstepScale`, and plain `char` rather than explicit `signed char` as the most likely historical declaration.
- No Wave2/Wave3 evidence was used. Search results and old docs were screened for stale workflow material; any such material is rejected by the current project skill.

## Heuristic / Inference Reanalysis And Validation

- Method identity: `InitializeWalkAnimation` remains stronger than `StartWalkAnimation`, `BeginWalkMovement`, or a packet-derived name. The body initializes common walking state and schedules the inherited forward-step event; packet reply handlers are only two of four callers. The sibling at `0x005a3770` already owns the more animation-group-specific `StartDirectionalAnimation` role.
- Parameter: `direction` is stronger than `facing` because the byte is both stored as facing and passed as the timer argument. `unsigned char` matches the project's direction APIs and packet values. Signed `char` is rejected as semantic source type even though IDA models the stack byte as `char`.
- Receiver: UserPane is proven by offsets `+0x1340f8` and `+0x13eaf2/+0x13eaf4`, which lie far beyond the standalone LivingObjectPane extent and are current UserPane fields. LivingObjectPane supplies inherited state and helper methods but does not own this method.
- `+0x1c5`: current `m_facing` is retained. It is a byte copied from the direction parameter and compared/passed as direction throughout movement replies and animation steps.
- `+0x13eaf2`: the exact word zero covers movement-state bytes 2 and 3. Current `ClearMovementHistoryToken()` is retained because callers and reply-state helpers treat these bytes as the compact movement-reply/history token state.
- `+0x13eaf4`: current `SetDirectionDelayActive(false)` is retained. The extended reply path tests this byte before scheduling another movement-step timer.
- `+0x1c4`: call UID0004QG `SetMovingState(true)` is retained. The helper writes `m_isMoving` and only clears `m_moveFrame` on false; the target separately clears the frame after setting true, preserving exact order.
- `+0x1c6`: current `m_moveFrame` is retained. It is reset before scheduling and consumed as a signed frame/substep counter by animation and position updates.
- `0x0053bf80`: `CancelBoxRotationStep()` is retained. The exact helper removes timer event `0x41534246` (`FBSA`) from the object's inherited TimerHandler facet; it has target and sibling UID0003U8 as callers.
- Timer callback: `this + 0xa4` is the inherited TimerHandler subobject. Event `0x41645746` is current `kLivingTimerForwardStep` (`FWdA`). UID0002R1 and LivingObjectPane timer docs corroborate event dispatch behavior.
- Timer API: `g_pTimerMgr->ScheduleTimer(handler,event,delay,direction,0)` matches the exact push order and current TimerMgr surface. No cancellation of `FWdA` occurs in this target; box-step cancellation is a separate preceding event removal.
- Status byte: `+0x1a0` is exactly ObjectStatusBlob `+0x28`, current `m_displayStatusByte`. The synthetic `m_movementSpeed` field is rejected because no current layout member occupies that offset under that name.
- Scale type: all 23 direct reads at 14 functions use `movsx`. An unsigned declaration would normally lower to zero-extension and is rejected. `static char ... = 1` is the strongest late-1999/mid-2000s MSVC source form because x86 MSVC plain `char` is signed by default in the observed build style. `static signed char ... = 1` is machine-equivalent but stylistically less probable. `std::uint8_t` and `unsigned char` are rejected because they imply unsigned promotion.
- Division: machine code performs `movzx` of the status byte, sign-extension of the scale byte, `cdq`, and `idiv`. The source must retain direct integer division with no zero check, clamp, absolute value, or fallback. Initial scale is 1 and no direct writer was found.
- Map call: target, UID0003U8, and the inspected UID0003UQ branches call exact child UID0004DS `0x00506980`. The direct source-facing callee is therefore `UpdateObjectPaneScreenBounds`, not a generic `InvalidateObject` alias.
- Return type: all four callers ignore EAX; no explicit return value is established. `void` is retained rather than decompiler `int`.
- Source placement: method mutates UserPane fields and is called by UserPane movement/packet paths; `NexusTK/ui/panels/UserPane.cpp` is the only coherent current route.
- Rejected alternatives: LivingObjectPane member, MapPane member, TimerMgr callback body, packet helper, standalone movement module, inline-only source, compiler wrapper, blank C++, source split, unsigned scale, movement-speed field, generic invalidation alias, zero-divisor guard, and direction normalization.
- Unresolved but nonblocking: exact original private method/global spellings and whether the developer wrote plain `char` or explicit `signed char`. Direct machine behavior and project-consistent source are complete; this lexical uncertainty caps scores below 95.

## Evidence Standards Used

- Primary evidence: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, bounded `get_bytes`, function analysis, decompile, disassembly, xrefs, call inventories, and bounded scale-reader audits.
- Binary identity: NexusTK.exe length 2,679,296; MD5 `4247E04E20B65D6414C7238AA8FF5515`; SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Secondary evidence: current target/support/class/file/global/storage pages, generated UserPane source, tracker row, manual coverage rows, and searched old reports.
- Negative evidence: no absolute VA/RVA pointer to target, no data/vtable/RTTI route, no internal split, no EH/security-cookie path, no target string, no scale writer, no unsigned scale load, and no archive report.
- Evidence ladder: exact bytes/control flow/calls and current layout outrank generated source and old reports. Existing semantic names are retained only where current direct behavior and family consistency support them.
- Tool limitation: one broad search timed out under load. It did not become evidence; bounded per-function disassembly replaced it and returned a complete 23-reference load-form inventory.

## Evidence Checked

- Fresh MCP checks: `idb_list`; `server_health(database=2198f811)`; bounded `lookup_funcs` for `0x005a36f0`, predecessor `0x005a2e00`, successor `0x005a3770`, helper `0x0053bf80`, and scheduler `0x00597910`; bounded target and adjacent bytes; target analysis/decompile/disassembly; all target callers/callees; data/pointer route checks; bounded disassembly for all 14 `0x0066da96` reader functions.
- Exact old-report search terms used: `UID0003U7`, `0003U7`, `0x005a36f0`, `0x005a3766`, `UserPaneInitializeWalkAnimation`, `InitializeWalkAnimation`, `UID0002QY`, `UID0001KM`, `UID0002R1`, `UID0002CF`, `UID00024A`, `UID0003U6`, `UID0003U8`, `movement timer`, `TimerMgr`, `UserPane`, `LivingObjectPane`, `MapPane`, `ObjectStatusBlob`, and `g_movementSubstepScale`.
- Matching active path opened: `tools/leaser/Agents/Agent-B001/research/0003U6-UserPaneProcessMovement-source-quality.md`; finding: exact predecessor/switch-table boundary, no target collision.
- Matching executed paths opened: the nine reports listed under Supporting Research; findings: owner/route, timer/event, `m_mapPane`, MapPane helper, and 23-reader facts remain useful; target field token and unsigned scale conclusion are incomplete/superseded.
- `Older-Research` result: no direct target/family match; one unrelated TimerMgr-only report classified irrelevant. `SpecialReports`: no match. Correct archive root `source-3/project-documentation/archived`: zero Markdown reports, therefore no direct report.
- Current docs read: UID0003U7, UID0003U8, UID0003UQ, UID0003U6, UID0001KM, UID0002R1, UID0002CF, UID00027F, UID00024A, UID0004QG, UID0004DS, UID0000FQ UserPane, UID00007B LivingObjectPane, UID00009S ObjectStatusBlob, UID0000P1 UserPane file, UID0000L3 MapPane file, TimerMgr/global pages, and `by-memory/-ignored.md`.
- Pre-callback artifact hashes recorded at research time: target `46FE8F8D302143FEE0A26C3DCE41C1AFD2DFA8426EB921151B9F2744C259092C`; UID0003U8 `15BA475368D4BAF5308F23F2E70F31F0F2B570BC1B938C6E8BC8A602E82D20C6`; UID0003UQ `0A2C95D7A8A9081C0FB7FEFF8E1B7E61241085ECAEEB38C98BE2651CBD0E7627`; UID0002CF `DF5982C8CC78B75A5D7302F38F0C591979B19E36735630BF00B053FD144B6E94`; UID00027F `AE4FFC306330ED459860649532AD8FC9F2A60E89E6F0E3D3CB907063C12B07B8`; UID0000FQ `4D456A312DF68B1C8E3F24EC7F8066EC20C937B5089E64463DC126AF2147DA0E`; UID00007B `7C0535061E05C9E530D81092DAA94EF3AD285B8778F734452A9FC5E10BA4CF33`; UID00009S `110F06C13CB4F5006910B5A553C3E9DCE5A4901E7A14CF0F9C096502DE51D39E`; UID0000P1 `2DD547743B396369F0B1A6ADB7176AEA9DC9C680CB06CE1F24287AF8CEDD480F`; UID0000VN `FE175D085D57DC695E22A8FF83394686CD9CE533268B795FD9C559BD427B8B85`. Post-callback hashes are recorded under Changed Files.
- Historical pre-application manual-coverage checks: UID0003U7, UID0003U8, UID0003UQ, UID0002CF, and UID00027F rows were opened, and UID0000VN placement around UID0003U7/UID0003U8 was inspected. The exact handoff text remains below. Current readback confirms the supervisor-applied UID0003U7/UID0000VN/UID00027F rows in `by-memory/-coverage-report.md` and UID0002CF row in `by-global/-coverage-report.md`, validated by commands `000000012707` and `000000012708`.
- Failed/unavailable checks: only the broad scale text search timed out; it was replaced by bounded complete reader disassembly. No MCP-backed conclusion relies on that failed call.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3U7-001 | Evidence-time MCP database was `2198f811`, worker PID 19764, health ok. | High | Fresh idb_list/health and bounded target calls. | Report evidence sections | incorporate | already-present |
| C3U7-002 | Target exact range is `[0x005a36f0,0x005a3766)`, 118 bytes. | High | lookup, bytes, function model. | UID0003U7 | incorporate | applied |
| C3U7-003 | Target bytes hash to `986286D5DC686EEAE3C1FB5457A811E54C091D0587EA0EC22CF54B13EF37C158`. | High | Exact 118-byte read/hash. | UID0003U7 evidence | incorporate | applied |
| C3U7-004 | Target is one source method with one block and no EH/compiler split. | High | Function analysis and disassembly. | UID0003U7 range/source sections | incorporate | applied |
| C3U7-005 | Predecessor UID0003U6 owns attached switch support through `0x005a36f0`; no overlap. | High | B001 current report plus live lookup. | UID0003U7 boundary history | already-present | already-present |
| C3U7-006 | `[0x005a3766,0x005a3770)` is ten `cc` alignment bytes. | High | Bounded bytes, successor lookup. | UID0000VN | incorporate | applied |
| C3U7-007 | Source signature is `void UserPane::InitializeWalkAnimation(unsigned char direction)`. | High | thiscall ABI, ignored return, caller semantics. | UID0003U7 formal/prose | incorporate | applied |
| C3U7-008 | Four direct callers make the method live. | High | Code xrefs and caller windows. | UID0003U7 callers | incorporate | applied |
| C3U7-009 | No data, pointer, vtable, RTTI, or callback-table route exists. | High | Pointer/data/xref negative scans. | UID0003U7 negative evidence | incorporate | applied |
| C3U7-010 | Canonical owner/emitter UID0000FQ and source route UID0000P1 remain correct. | High | UserPane-only offsets and current class/file route. | UID0003U7 metadata | already-present | already-present |
| C3U7-011 | `m_facing` at `+0x1c5` is the correct direction/facing byte. | High | Exact store and cross-family consumers. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-012 | `ClearMovementHistoryToken()` exactly represents the word zero at `+0x13eaf2`. | High | UserPane helper contract and reply-state use. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-013 | `SetDirectionDelayActive(false)` exactly represents byte zero at `+0x13eaf4`. | High | Extended-reply consumer and helper contract. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-014 | UID0004QG `SetMovingState(true)` is the exact `0x0053ab20` call. | High | Callee body and current registered page. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-015 | `m_moveFrame = 0` must remain after SetMovingState. | High | Exact instruction order/helper behavior. | UID0003U7 detail/formal | incorporate | applied |
| C3U7-016 | `CancelBoxRotationStep()` is exact helper `0x0053bf80` and removes `FBSA`. | High | Helper disassembly/callers. | UID0003U7 detail/formal | incorporate | applied |
| C3U7-017 | Timer handler is inherited subobject `this + 0xa4`. | High | Exact LEA and timer-family docs. | UID0003U7 ABI/timer detail | incorporate | applied |
| C3U7-018 | Event `0x41645746` is `kLivingTimerForwardStep` (`FWdA`). | High | Literal and current LivingObjectPane enum. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-019 | `g_pTimerMgr` at `0x0067ab80` and ScheduleTimer call shape remain correct. | High | Data read, scheduler disassembly, current docs. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-020 | `UserPane + 0x1a0` is ObjectStatusBlob `m_displayStatusByte`, not movement speed. | High | Layout arithmetic and current UID00009S. | UID0003U7, UID0003U8, UID0003UQ | reject-stale | applied |
| C3U7-021 | All 23 direct scale readers across 14 functions use signed loads. | High | Bounded complete reader disassembly. | UID0002CF, UID00027F | incorporate | applied |
| C3U7-022 | Highest-probability source declaration is file-static plain `char`, initialized to 1. | High | MOVSX-only readers, byte storage, era style. | UID0002CF formal/prose | reject-stale | applied |
| C3U7-023 | Direct unguarded signed division must remain. | High | MOVZX/MOVSX/CDQ/IDIV sequence. | Destinations 1-3 | incorporate | applied |
| C3U7-024 | `m_mapPane` is UserPane field at `+0x1340f8`. | High | Exact load and UID00024A/current class. | UID0003U7 detail/formal | already-present | already-present |
| C3U7-025 | Exact final callee is UID0004DS `UpdateObjectPaneScreenBounds`, not generic InvalidateObject. | High | Direct calls to `0x00506980` and current child identity. | UID0003U7, UID0003U8, UID0003UQ | reject-stale | applied |
| C3U7-026 | Exact execution order is state writes, moving-state set, frame clear, box timer cancel, forward timer schedule, screen-bounds refresh. | High | Linear one-block disassembly. | UID0003U7 behavior/formal | incorporate | applied |
| C3U7-027 | `InitializeWalkAnimation` is the strongest source-facing method name. | Medium-high | Role, caller set, sibling distinction, project style. | UID0003U7 title/formal | already-present | already-present |
| C3U7-028 | `direction`/`unsigned char` is strongest parameter contract. | High | Values, store, timer arg, sibling APIs. | UID0003U7 formal/ABI | already-present | already-present |
| C3U7-029 | Destination 1 is the exact corrected target managed block. | High | All preceding evidence. | UID0003U7 formal | incorporate | applied |
| C3U7-030 | Destination 2 corrects only evidenced stale field/callee tokens in UID0003U8. | High | Live UID0003U8 disassembly. | UID0003U8 formal/prose | incorporate | applied |
| C3U7-031 | Destination 3 corrects two field and three callee tokens in UID0003UQ. | High | Live UID0003UQ disassembly. | UID0003UQ formal/prose | incorporate | applied |
| C3U7-032 | Destination 4 is the exact corrected global declaration. | High | Complete 23-reader signedness proof. | UID0002CF formal/prose | incorporate | applied |
| C3U7-033 | UID00027F remains nonduplicating covered-by storage and gains signed-reader evidence. | High | Current owner/emitter model plus live readers. | UID00027F formal/prose | incorporate | applied |
| C3U7-034 | Target Item Summary must describe corrected display-status/timer/map behavior without header duplication. | High | Generated coverage rules. | UID0003U7 Item Summary | incorporate | applied |
| C3U7-035 | Target score becomes `92/94`; metadata otherwise unchanged. | High | Blocker closure and score standard. | UID0003U7 headers/coverage | incorporate | applied |
| C3U7-036 | UID0003U8 and UID0003UQ scores remain `86/88`. | High | Bounded correction only; no full sibling rescore audit. | Support headers/coverage | already-present | already-present |
| C3U7-037 | UID0002CF becomes `91/93`; UID00027F becomes `90/93`. | High | Original type blocker resolved; spelling/owner caps remain. | Support headers/coverage | incorporate | applied |
| C3U7-038 | Lower target blank-C++ questions are historical/superseded, not current. | High | Direct contradiction with authoritative header/current section. | UID0003U7 history/open questions | historicalize | applied |
| C3U7-039 | Target remains `Nested:0`; no child-count reinterpretation. | High | Address-order sibling level and current metadata. | UID0003U7 metadata | already-present | already-present |
| C3U7-040 | No target rename, split, owner change, emitter change, or position change is justified. | High | Exact source boundary and route. | UID0003U7 metadata | reject-invalid | excluded-with-reason |
| C3U7-041 | Evidence-time generated source contained four stale field tokens; callback output contains zero. | High | Read-only before/after generated scans and hashes. | Report/generated verification | incorporate | applied |
| C3U7-042 | B001 UID0003U6 report is compatible predecessor evidence, not a collision. | High | Current active-report read. | Report coordination | incorporate | already-present |
| C3U7-043 | Older-Research, SpecialReports, and actual archive root contain no direct target report. | High | Explicit per-root searches. | Report provenance | incorporate | already-present |
| C3U7-044 | Historical read-only comparison required target/global/storage replacement plus one padding addition; U8/UQ rows remained textually adequate. | High | Exact historical handoff plus current row readback and supervisor commands 12707/12708. | Supervisor-owned manual coverage | incorporate | applied |
| C3U7-045 | Rejected alternatives and negative evidence must be retained with reasons. | High | Full fact/inference matrix. | All changed prose destinations | incorporate | applied |
| C3U7-046 | B004 may implement ordinary accepted destinations but performs no manual restricted-file edit or lifecycle command. | High | Callback boundary and command inventory. | Report/checklist | incorporate | applied |

### Callback Claim-By-Claim Destination Proof

- `C3U7-001`: evidence-time MCP session/health remains preserved in Supporting Research, Evidence Checked, and IDA MCP Facts; the callback makes no indefinite availability assertion.
- `C3U7-002`: UID0003U7 records exact `[0x005a36f0,0x005a3766)` and 118-byte size; validator `000000012693` passed.
- `C3U7-003`: UID0003U7 records exact target SHA256 `986286D5DC686EEAE3C1FB5457A811E54C091D0587EA0EC22CF54B13EF37C158` separately from documentation hashes.
- `C3U7-004`: UID0003U7 records one block, no internal entry, and no EH/compiler split; no child/source split was created.
- `C3U7-005`: predecessor UID0003U6 remained verify-only and unedited; target starts exactly at the accepted boundary.
- `C3U7-006`: UID0000VN now contains the single `[0x005a3766,0x005a3770)` ten-`cc` row with accepted hash and adjacency; validator `000000012698` passed.
- `C3U7-007`: Destination 1 and generated output contain exactly `void UserPane::InitializeWalkAnimation(unsigned char direction)`.
- `C3U7-008`: UID0003U7 preserves all four direct callers and liveness conclusions in its callback evidence.
- `C3U7-009`: UID0003U7 preserves the no data/pointer/vtable/RTTI/callback-table-route negative inventory.
- `C3U7-010`: UID0003U7 retains owner/emitter UID0000FQ and UserPane file route UID0000P1; no ownership metadata changed.
- `C3U7-011`: Destination 1 retains `m_facing = direction` at the documented `+0x1c5` field.
- `C3U7-012`: Destination 1 retains `ClearMovementHistoryToken()` and the exact `+0x13eaf2` word-zero evidence.
- `C3U7-013`: Destination 1 retains `SetDirectionDelayActive(false)` and the exact `+0x13eaf4` byte-zero evidence.
- `C3U7-014`: Destination 1 retains UID0004QG `SetMovingState(true)` for call `0x0053ab20`.
- `C3U7-015`: Destination 1 preserves `m_moveFrame = 0` immediately after `SetMovingState(true)`.
- `C3U7-016`: Destination 1 and target evidence preserve `CancelBoxRotationStep()`/`FBSA` cancellation at `0x0053bf80`.
- `C3U7-017`: UID0003U7 records the inherited `TimerHandler` facet at `this + 0xa4`; the formal cast remains exact.
- `C3U7-018`: Destination 1 retains `kLivingTimerForwardStep` and the `0x41645746`/`FWdA` evidence.
- `C3U7-019`: UID0003U7 retains `g_pTimerMgr` `0x0067ab80` and exact five-argument `ScheduleTimer` shape.
- `C3U7-020`: UID0003U7, UID0003U8, and UID0003UQ contain zero current `m_objectStatus.m_movementSpeed` tokens and use `m_displayStatusByte` at every accepted site.
- `C3U7-021`: UID0002CF and UID00027F each record all 23 exact `movsx` reader addresses across 14 functions.
- `C3U7-022`: UID0002CF Destination 4 is exactly `static char g_movementSubstepScale = 1;`; unsigned declarations are explicitly rejected.
- `C3U7-023`: Destinations 1-3 retain direct division by `g_movementSubstepScale` with no guard, clamp, or fallback.
- `C3U7-024`: UID0003U7 retains `m_mapPane` at UserPane `+0x1340f8` and its UID00024A provenance.
- `C3U7-025`: Destinations 1-3 use exact UID0004DS `UpdateObjectPaneScreenBounds` at all accepted sites; no stale alias remains in those managed blocks.
- `C3U7-026`: Destination 1 preserves the accepted linear state-write, moving-state, frame-clear, box-cancel, timer-schedule, and screen-bounds-refresh order.
- `C3U7-027`: UID0003U7 path/title/signature retain `InitializeWalkAnimation`; no rename occurred.
- `C3U7-028`: Destination 1 retains `unsigned char direction`; no enum or signed parameter was invented.
- `C3U7-029`: UID0003U7 managed block is byte-for-byte equal after newline normalization to accepted Destination 1; validator `000000012693` and generated exact-body comparison passed.
- `C3U7-030`: UID0003U8 managed block is byte-for-byte equal to Destination 2; validator `000000012694` and generated exact-body comparison passed.
- `C3U7-031`: UID0003UQ managed block is byte-for-byte equal to Destination 3; validator `000000012695` and generated exact-body comparison passed.
- `C3U7-032`: UID0002CF managed block is byte-for-byte equal to Destination 4; validator `000000012696` passed.
- `C3U7-033`: UID00027F managed block is byte-for-byte equal to Destination 5 and emits only its covered-by marker; validator `000000012697` passed.
- `C3U7-034`: UID0003U7 Item Summary now names the exact display-status delay scaling, inherited timer, box cancellation, and MapPane screen-bounds behavior.
- `C3U7-035`: UID0003U7 headers are `92/94`; UID/owner/emitter/reconstructable/blank-position/`Nested:0` remain exact.
- `C3U7-036`: UID0003U8 and UID0003UQ headers remain `86/88`; no unrelated score or metadata changed.
- `C3U7-037`: UID0002CF headers are `91/93`; UID00027F headers are `90/93`; their owner/emitter/formal disposition remains bounded as accepted.
- `C3U7-038`: UID0003U7 labels the former blank-C++/name questions as pre-2026-07-14 superseded history and states the current resolution.
- `C3U7-039`: UID0003U7 remains `Nested:0`; no child-count reinterpretation was applied.
- `C3U7-040`: no target rename, split, owner/emitter change, or position change occurred; these rejected actions are excluded by exact boundary/route evidence.
- `C3U7-041`: waited command `000000012699` generated one exact UID0003U7 body, zero target Empty Emitter Markers, and zero stale movement-speed tokens in `UserPane.cpp`.
- `C3U7-042`: B001 UID0003U6 report/path evidence remains report provenance; no B001-owned destination was edited.
- `C3U7-043`: Older-Research, SpecialReports, and the actual archive-root no-match results remain preserved unchanged.
- `C3U7-044`: exact pre-application replacement/addition text remains preserved as historical handoff evidence; the supervisor applied the UID0003U7/UID0000VN/UID00027F rows under command `000000012707` and UID0002CF under command `000000012708`, both exit 0 / `ok:1`. B004 made no manual coverage edit.
- `C3U7-045`: each changed destination retains explicit historical, negative, source-route, and rejected-alternative evidence instead of compressing it into the formal block.
- `C3U7-046`: only six accepted ordinary pages plus this report were manually edited; validators alone refreshed generated/registry/projected-stat side effects, and B004 ran no report lifecycle command.

## Positive Evidence Summary

- Exact function: `sub_5A36F0`, size `0x76`, end `0x005a3766`; one block, 34 instructions, direct `retn 4`.
- Exact body dataflow: direction byte to `m_facing`; movement token/delay bytes cleared; moving state set; frame reset; box-step timer canceled; forward-step timer scheduled from display-status byte divided by signed scale; map object bounds refreshed.
- Four live direct calls span local movement, animation-step handling, and both movement-reply packet forms.
- Current UserPane and LivingObjectPane layouts account for every receiver offset and inherited helper. No raw-offset field invention is required.
- Current TimerMgr/LivingObjectPane docs account for handler adjustment, event IDs, schedule/remove semantics, and callback liveness.
- UID00009S accounts for exact `+0x1a0` byte as `m_displayStatusByte`. The historical pre-callback target/support bodies carried mechanically identifiable stale `m_movementSpeed` tokens; the current ordinary and command-12699 generated bodies contain zero target-family occurrences.
- Complete 23-reader audit proves the scale byte is consumed as signed in every function; no unsigned reader or writer contradicts plain `char`.
- Strongest inference chain: exact receiver-only fields prove UserPane; exact calls and helper pages close behavior; current class/file route closes emission; sibling and caller semantics support method/parameter names; all residual uncertainty is lexical.

## IDA MCP Facts

- Database evidence-time identity: `2198f811`, worker PID 19764, NexusTK.exe imagebase `0x400000`, analysis/Hex-Rays/strings ready.
- Target: `sub_5A36F0`, start `0x005a36f0`, size `0x76`, end `0x005a3766`; prototype modeled as thiscall receiver plus one stack byte; one basic block, cyclomatic complexity 1, 34 instructions, no EH/security cookie/string reference.
- Exact target bytes: `55 8b ec 53 8a 5d 08 56 8b f1 6a 01 88 9e c5 01 00 00 66 c7 86 f2 ea 13 00 00 00 c6 86 f4 ea 13 00 00 e8 09 74 f9 ff 8b ce c6 86 c6 01 00 00 00 e8 5b 88 f9 ff 0f be 0d 96 da 66 00 6a 00 0f be c3 50 0f b6 86 a0 01 00 00 99 f7 f9 8b 0d 80 ab 67 00 50 68 46 57 64 41 8d 86 a4 00 00 00 50 e8 bc 41 ff ff 8b 8e f8 40 13 00 56 e8 20 32 f6 ff 5e 5b 5d c2 04 00`.
- Target byte SHA256: `986286D5DC686EEAE3C1FB5457A811E54C091D0587EA0EC22CF54B13EF37C158`.
- Predecessor: modeled `sub_5A2E00`, size `0x8de`, code end `0x005a36de`; UID0003U6's referenced NOP/four-entry switch material continues through documentation end `0x005a36f0`.
- Successor: `sub_5A3770`, size `0xfa`; ten bytes between target and successor are all `cc`, SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`.
- Callees: `0x0053ab20`, `0x0053bf80`, `0x00597910`, and `0x00506980`, in that source-relevant order.
- Data reads: `byte_66DA96` and `dword 0x0067ab80`; receiver reads/writes at `+0x1a0`, `+0x1c4/+0x1c5/+0x1c6`, `+0xa4`, `+0x1340f8`, and `+0x13eaf2/+0x13eaf4`.
- Scale reader set: 23 references in 14 functions at `0x00468577/0x00468644`, `0x005055f7`, `0x00506a1e`, `0x0050b0f5/0x0050b11c`, `0x0053864f`, `0x00538744/0x0053875d`, `0x00539b6f`, `0x0053c773/0x0053c78f`, `0x0053c895`, `0x005a3725`, `0x005a3836`, `0x005a840e/0x005a846b/0x005a84cc/0x005a85fe/0x005a865b/0x005a86bc`, `0x005a8923`, and `0x005ab554`; every instruction uses `movsx`.
- Negative IDA facts: no target absolute VA pointer, no target RVA pointer, no target data/vtable/RTTI reference, no internal source boundary, no source EH, no scale writer, no zero-divisor guard, no status-byte clamp, and no generated return-value use.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a2e00-0x005a36f0` | UID0003U6 UserPaneProcessMovement | predecessor source member plus attached switch support | true | UID0000FQ | current `92/94` | verify-only; B001-owned |
| `0x005a36f0-0x005a3766` | UID0003U7 assigned target | exact UserPane walk-animation initializer | true | UID0000FQ | `86/88 -> 92/94` | target correction applied |
| `0x005a3766-0x005a3770` | UID0000VN `by-memory/-ignored.md` | ten-byte `cc` alignment | false/source-no-code | none | ignored | exact row applied |
| `0x005a3770-0x005a386a` | UID0003U8 StartDirectionalAnimation | source sibling | true | UID0000FQ | retain `86/88` | bounded formal token correction applied |
| `0x005ab410-0x005ab75d` | UID0003UQ HandleExtendedMovementReplyPacket | source packet sibling | true | UID0000FQ | retain `86/88` | bounded formal token correction applied |
| `0x0066da96-0x0066da97` | UID00027F exact scale storage | initialized signed-byte-consumed data | true | UID0000L3 | `88/91 -> 90/93` | prose/score sync applied |
| semantic global | UID0002CF g_movementSubstepScale | file-static MapPane-owned declaration | true | UID0000L3 | `89/90 -> 91/93` | signed type/formal correction applied |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a3424` | UID0003U6 `UserPane::ProcessMovement` -> target | Normal local movement path initializes walking after movement/status processing. |
| `0x005a85d6` | `UserPane::OnAnimationStep` adjusted TimerHandler facet -> target | Timer callback route recovers UserPane from `this + 0xa4`, reinitializes by direction, then advances state. |
| `0x005ab143` | baseline movement reply handler -> target | Server correction/warp path calls when direction is not sentinel 4. |
| `0x005ab4c1` | UID0003UQ extended movement reply -> target | Extended correction path calls when direction is not sentinel 4. |
| `0x0053ab20` | target -> UID0004QG `SetMovingState(true)` | Writes inherited moving state. |
| `0x0053bf80` | target -> `CancelBoxRotationStep()` | Removes inherited box-step timer event `FBSA`. |
| `0x00597910` | target -> TimerMgr schedule helper | Schedules `FWdA` on TimerHandler facet with computed delay/direction/zero. |
| `0x00506980` | target -> UID0004DS `UpdateObjectPaneScreenBounds` | Refreshes object screen position/bounds after state initialization. |
| `0x0066da96` | target and 22 other reads | Signed one-byte movement substep/timer divisor. |
| `0x0067ab80` | target and timer consumers | TimerMgr singleton pointer. |

## Documentation Evidence And IDA Status

- UID0000FQ already declares `InitializeWalkAnimation(unsigned char)`, `StartDirectionalAnimation(unsigned char)`, movement-state helpers, `m_movementState[5]`, `m_mapPane`, and inherited movement fields without synthetic `m_movementSpeed`.
- UID00007B already declares `m_objectStatus` at `+0x178`, `m_isMoving`, `m_facing`, `m_moveFrame`, TimerHandler inheritance, and `kLivingTimerForwardStep`/box-step constants.
- UID00009S defines ObjectStatusBlob `+0x28` as `m_displayStatusByte`; that is the decisive current layout evidence for target `+0x1a0`.
- UID0004QG supplies exact SetMovingState behavior; UID0002R1 supplies timer message behavior; UID0004DS supplies the exact final MapPane callee identity; UID00024A supplies the UserPane `m_mapPane` field route.
- UID0003U7's top current-disposition section and nonblank header are current. Its lower blank-C++ questions are stale embedded history.
- UID0002CF's ownership, xref count, value, and storage route are current. Its unsigned type rationale is contradicted by complete live load-form evidence.
- Historical pre-callback generated baseline: `UserPane.cpp` emitted one target body while repeating four stale target-family `m_objectStatus.m_movementSpeed` tokens and stale MapPane callee aliases inherited from the then-current ordinary pages. This baseline is evidence history only and is not the current generated state.
- Current command-12699 generated state: waited validator `000000012699` emits the exact accepted UID0003U7, UID0003U8, and UID0003UQ bodies once each; those bodies contain zero target-family `m_objectStatus.m_movementSpeed` tokens, use `UpdateObjectPaneScreenBounds` at the accepted target/U8/UQ call counts `1/1/3`, and emit no UID0003U7 Empty Emitter Marker. `MapPane.cpp` emits exactly one signed `static char g_movementSubstepScale = 1;` UID0002CF declaration, zero unsigned declarations, and exactly one UID00027F covered-by marker.
- Current manual coverage is synchronized: command `000000012707` applied/validated UID0003U7 at 92, the exact ignored padding row, and UID00027F at 90; command `000000012708` applied/validated UID0002CF at 91. The exact earlier supervisor handoff remains below as historical evidence; B004 did not edit manual coverage.

## Ranked Ownership Analysis

### 1. UID0000FQ UserPane / UID0000P1 UserPane.cpp

- Evidence for: receiver uses UserPane-only fields beyond the LivingObjectPane extent; all callers are UserPane movement/packet methods or an inherited timer facet adjusted back to UserPane; the class and file route already declare/emit the member.
- Evidence against: exact original private method spelling is stripped.
- Decision: accepted canonical owner/emitter and source route. Retain unchanged.

### 2. UID00007B LivingObjectPane / LivingObjectPane.cpp

- Evidence for: target uses inherited movement fields, TimerHandler facet, SetMovingState, and box-step cancellation.
- Evidence against: receiver also uses `+0x1340f8` and `+0x13eaf2/+0x13eaf4`, which are UserPane extension fields; direct callers are UserPane-specific.
- Decision: dependency/base-class support only; reject ownership.

### 3. UID0000L3 MapPane / TimerMgr / movement utility module

- Evidence for: target calls MapPane screen-bounds refresh and consumes a MapPane-owned scale; it schedules through TimerMgr.
- Evidence against: neither callee owns the receiver state or caller surface. No standalone movement source file, symbol, writer, or route exists.
- Decision: dependencies only; reject target ownership. Keep scale declaration MapPane-owned separately.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/ui/panels/UserPane.cpp` fully covers the source method, and existing `NexusTK/map/MapPane.cpp` covers the shared scale declaration.
- Rejected new groupings: `MovementAnimation.cpp`, `UserMovementTimers.cpp`, `MapMovementGlobals.cpp`, and packet-handler ownership. Each lacks source/debug/caller evidence and would fragment coherent existing routes.

## Source Placement

- Recommended target placement: class `UserPane`, source route UID0000P1, generated path `NexusTK/ui/panels/UserPane.cpp`.
- Recommended scale placement: file-static declaration under UID0000L3 `MapPane`, generated path `NexusTK/map/MapPane.cpp`; exact storage remains directly MapPane-owned and covered by UID0002CF.
- Placement fit: target mutates local-player UserPane extension state; scale's coherent reader/coordinate surface remains MapPane-owned; support siblings already emit in UserPane.cpp.
- Rejected target placements: LivingObjectPane.cpp, MapPane.cpp, TimerMgr.cpp, packet utilities, generated raw-helper file, or a new movement module.
- Remaining uncertainty: original header/private declaration ordering is stripped, but current class/file routes are source-legal and nonblocking.

## Range / Split / Padding / Reclassification Analysis

- Target exact source/binary range is `[0x005a36f0,0x005a3766)`. The first byte is a normal prologue and the last instruction is `retn 4` ending exactly at `0x005a3766`.
- Predecessor UID0003U6 has modeled code through `0x005a36de` and referenced switch support through `0x005a36f0`; it does not overlap the target.
- Successor UID0003U8 begins at `0x005a3770`. The intervening ten bytes are all `cc`, have no function/data/xref route, and hash to `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`.
- Applied range action: target and successor paths remain unchanged; one UID0000VN ignored-alignment row records `[0x005a3766,0x005a3770)`.
- No child is created. No internal table, padding, tail merge, duplicate body, compiler thunk, EH helper, or callback wrapper exists inside the target.
- Parent/container impact: UID0001KM remains the broader non-emitting UserPane local-player extension index. Target `Nested:0` remains the correct address-order relative delta, not a child count.

## Negative Evidence Summary

- No absolute target VA bytes and no target RVA pointer bytes were found; liveness is exclusively through four direct calls.
- No vtable, RTTI, callback table, import, data object, or function-pointer registration points at target.
- No internal branch or entry supports a split; all 34 instructions are one basic block.
- No EH, security-cookie, scalar-deleting, adjustor, wrapper, or compiler-only body is present.
- No caller consumes a return value; decompiler `int` is not source proof.
- No evidence supports LivingObjectPane ownership despite inherited helper use.
- No current layout supports `m_movementSpeed`; the exact byte belongs to ObjectStatusBlob `m_displayStatusByte`.
- No one of 23 scale readers zero-extends the byte; unsigned declaration is contradicted.
- No direct scale writer/config route was found. This preserves the existing owner/spelling confidence cap but does not block signed type recovery.
- No zero-scale protection, null TimerMgr check, null MapPane check, direction clamp, sentinel handling inside target, or post-schedule error handling occurs. Source must not invent them.
- No old report in Older-Research, SpecialReports, or the actual empty archive root substitutes for this target-specific pass.

## IDA Rename / Type / Comment Recommendations

- IDA DB mutation is not requested and is forbidden in this report-only assignment.
- Source-facing function name: retain `UserPane::InitializeWalkAnimation` for `sub_5A36F0`; confidence medium-high as descriptive stripped-name reconstruction.
- Source-facing parameter: retain `unsigned char direction`; confidence high for semantic type, medium-high for exact lexical spelling.
- Source-facing target fields/helpers: retain `m_facing`, `ClearMovementHistoryToken`, `SetDirectionDelayActive`, `SetMovingState`, `m_moveFrame`, `CancelBoxRotationStep`, `kLivingTimerForwardStep`, `g_pTimerMgr`, and `m_mapPane`.
- Correct source-facing ObjectStatusBlob member: `m_displayStatusByte`, directly mapped from `+0x1a0`.
- Correct source-facing MapPane callee: `UpdateObjectPaneScreenBounds`, directly mapped to UID0004DS/`0x00506980`.
- Correct global type: plain signed-by-default `char`; retain descriptive symbol `g_movementSubstepScale` and initial value 1.
- Intentionally unchanged: target UID/path/range/owner/emitter/position/Nested, support UID paths, and all IDA names/comments.

## First-Draft C++ Recommendation

- Eligible: yes. Target and two source-bearing siblings already emit code; the global emits a declaration; exact storage remains a nonduplicating covered-by marker.
- Destination 1: `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::InitializeWalkAnimation(unsigned char direction)
{
    m_facing = direction;
    ClearMovementHistoryToken();
    SetDirectionDelayActive(false);
    SetMovingState(true);
    m_moveFrame = 0;
    CancelBoxRotationStep();
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        kLivingTimerForwardStep,
        m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
        direction, 0);
    m_mapPane->UpdateObjectPaneScreenBounds(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 2: `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::StartDirectionalAnimation(unsigned char direction)
{
    m_isMoving = true;
    ClearMovementHistoryToken();
    SetDirectionDelayActive(false);
    m_moveFrame = 0;

    int frameDelay;
    if (m_objectStatus.m_statusKind == ObjectStatusBlob::HumanObject)
    {
        m_animationGroup = direction + 5;
        const ImageFrameGroup *group =
            g_pObjectImageLib->GetFrameGroup(
                m_objectStatus.m_appearanceId - 0x8000,
                m_animationGroup);
        frameDelay = group->GetFrame(m_moveFrame)->delay;
        PlayFacingAnimation();
        CancelBoxRotationStep();
    }
    else
    {
        frameDelay =
            m_objectStatus.m_displayStatusByte / g_movementSubstepScale;
    }

    SetMovingState(true);
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this), kUserPaneMovementStep,
        frameDelay, direction, 0);
    m_mapPane->UpdateObjectPaneScreenBounds(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 3: `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::HandleExtendedMovementReplyPacket(const unsigned char *packet)
{
    const unsigned char direction = packet[1];
    const int serverX = PacketBufferReadUInt16BE(packet + 2);
    const int serverY = PacketBufferReadUInt16BE(packet + 4);
    const int viewportColumn = PacketBufferReadUInt16BE(packet + 6);
    const int viewportRow = PacketBufferReadUInt16BE(packet + 8);
    const unsigned char historyIndex = packet[10] & 0x7f;

    if (!m_isMoving &&
        (!m_mapPane->AllowsMovementStatusFlag() ||
         !g_pConfig->m_sendMovementStatusBit))
    {
        WarpToPosition(serverX, serverY, viewportColumn, viewportRow);
        if (direction != 4)
            InitializeWalkAnimation(direction);
        SetMovementReplyState();
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        return true;
    }

    if (!m_mapPane->AllowsMovementStatusFlag() ||
        g_pConfig->m_sendMovementStatusBit != 1)
    {
        if (serverX == m_tileX && serverY == m_tileY && direction == m_facing)
        {
            SetMovementReplyState();
            if (IsDirectionDelayActive())
            {
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kUserPaneMovementStep,
                    m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
                    m_facing, 0);
            }
            return false;
        }

        MapPoint step;
        m_mapPane->DirectionToTileOffset(&step, direction);
        WarpToPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        return false;
    }

    if (direction & 0x80)
    {
        SetMovementReplyState();
        if (IsDirectionDelayActive())
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kUserPaneMovementStep,
                m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
                m_facing, 0);
        return false;
    }
    if (historyIndex >= m_movementHistoryCapacity)
        return false;
    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[historyIndex];
    if (!record.active)
        return false;
    if (record.tileX != serverX || record.tileY != serverY ||
        record.direction != direction)
    {
        MapPoint step;
        m_mapPane->DirectionToTileOffset(&step, direction);
        WarpToPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        ClearAllMovementHistoryRecords();
    }
    ClearMovementHistoryRecordByIndex(historyIndex);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 4: `by-global/g_movementSubstepScale.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static char g_movementSubstepScale = 1;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 5: `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` retains its nonduplicating marker exactly.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted declaration for this storage byte is covered by [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: Destinations 1-3 preserve direct integer promotion/division, exact branch and side-effect order, no added guards, exact timer arguments, and exact MapPane call identity. Destination 4 reproduces one-byte initialized storage and the observed signed extension in every reader. Destination 5 prevents duplicate emission.
- Original-source shape: ordinary private members, semantic fields/helpers, a file-static scalar, and existing class/file routes fit the late-1999 through mid-2000s MSVC project style. No raw addresses, decompiler labels, ABI scaffolding, or invented wrapper file appears.
- Third-party import directive: not applicable; all destinations are first-party NexusTK source/docs.

## Final Recommendation

- Applied target score `92/94`, corrected Destination 1, corrected Item Summary, and complete evidence/history while retaining UID/path/range/owner/emitter/reconstructable/position/Nested.
- Applied bounded complete Destinations 2 and 3, removing every directly audited stale field and MapPane-callee token while retaining their scores and unrelated content.
- Applied Destination 4 and score `91/93` to UID0002CF, including all 23 signed loads, plain-char choice, runner-up/rejections, no-writer cap, and existing MapPane ownership.
- Retained Destination 5's marker while raising UID00027F to `90/93` and synchronizing exact signed-reader evidence.
- Added exact `[0x005a3766,0x005a3770)` ignored padding evidence to UID0000VN.
- Leave UID0003U6, UID0001KM, UID0002R1, UID00024A, UID0004QG, UID0004DS, UID0000FQ, UID00007B, UID00009S, UID0000P1, UID0000L3, TimerMgr/global pages, and all unrelated UserPane siblings verify-only.
- No investigable blocker remains. Original private spelling uncertainty is a confidence cap, not future target work.

## Recommended Target Doc Changes

- Path: `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md`.
- Implemented metadata: completion 92, confidence 94; UID0003U7, owner/emitter UID0000FQ, reconstructable true, blank position, and `Nested:0` retained.
- Implemented formal C++: complete block equals Destination 1 exactly.
- Item Summary: `Source-ready UserPane walk-animation initializer with exact one-block behavior, four live callers, byte-accurate movement-state writes, inherited TimerHandler scheduling, display-status delay scaling, box-step cancellation, and MapPane screen-bounds refresh; corrected current field/type/helper names and superseded blank-C++ questions are documented below.`
- Implemented detail: exact bytes/hash/range/padding, one-block/ABI/return evidence, four callers, four callees, offsets/field mappings, `FBSA` cancellation, `FWdA` scheduling, signed scale division, map call identity, source route, generated stale-token baseline, negative evidence, old-report classification, rejected alternatives, and score rationale.
- Implemented historical repair: lower `Open Questions` are labeled pre-2026-07-14 superseded assumptions and current field/helper names plus nonblank C++ are resolved; old claims remain as dated provenance.

## Recommended Support Doc Changes

- `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`: Destination 2 installed; the stale field token and both machine-branch UID0004DS call sites are corrected, signed-scale/current-layout evidence is present, and score/metadata/unrelated body detail is preserved.
- `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md`: Destination 3 installed; two stale field tokens and all three directly observed UID0004DS calls are corrected while packet branches, return behavior, score, owner/emitter, and unrelated evidence remain.
- `by-global/g_movementSubstepScale.md`: `91/93`, Destination 4 installed, all 23 direct `movsx` reads recorded, plain `char` primary, explicit `signed char` bounded runner-up, and unsigned forms rejected; MapPane ownership and all accepted caps remain.
- `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`: `90/93`, Destination 5 exact, complete signed-reader evidence present, semantic declaration/type remains on UID0002CF, and storage remains directly MapPane-owned.
- `by-memory/-ignored.md`: one exact row exists for `0x005a3766-0x005a3770`, ten `cc` bytes, SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`, between UID0003U7 and UID0003U8; no C++.
- Verify-only current pages: UID0003U6 predecessor, UID0001KM family index, UID0002R1 timer, UID00024A accessor/layout, UID0004QG moving-state helper, UID0004DS MapPane helper, UserPane/LivingObjectPane/ObjectStatusBlob class pages, UserPane/MapPane file pages, TimerMgr/global pages. No score/formal change is recommended there.

## Score And Metadata Recommendation

- Target historical pre-callback state: `86/88`, owner/emitter UID0000FQ, reconstructable true, blank position, `Nested:0`.
- Target current implemented state: `92/94`, all other metadata unchanged.
- Completion gain: resolves the invalid field token, direct MapPane callee identity, stale blank-C++ contradiction, exact bytes/hash, complete caller/callee inventory, boundary/padding, scale type, generated contamination, old-report classification, and exact formal destination.
- Confidence gain: direct MCP proves all behavior and types needed for the method. Confidence remains below 95 because exact stripped private spellings and plain-char versus explicit-signed-char lexical style are not recoverable.
- UID0002CF historical/current: `89/90 -> 91/93`; owner/emitter UID0000L3 and formal position unchanged. The original type blocker is closed by all 23 readers.
- UID00027F historical/current: `88/91 -> 90/93`; owner/emitter UID0000L3 and covered-by formal disposition unchanged.
- UID0003U8/UID0003UQ: retain `86/88`; this pass corrects direct shared tokens but does not claim a full independent rescore of their larger bodies.
- Score blocker attempt, original name: callers, sibling names, source route, and semantics were compared. Best name retained; lexical uncertainty caps only.
- Score blocker attempt, ABI: stack byte, return usage, caller values, and sibling APIs were checked. `void` plus unsigned-byte direction resolved.
- Score blocker attempt, fields: current class layouts and exact offsets were reconciled. Every field now has a valid current source name.
- Score blocker attempt, timer/helper/global: helper bodies, event literals, handler adjustment, all global readers, and storage were checked. Contracts resolved.
- Score blocker attempt, range/liveness: predecessor/successor, exact bytes, padding, xrefs, pointer/data routes, and callers were checked. Range and liveness resolved.
- Score blocker attempt, C++: target and triggered support bodies were compared to live machine behavior. Five exact managed blocks are supplied.

## Open Questions With Attempted Resolution

- Was the original method literally named `InitializeWalkAnimation`? The stripped IDB, caller roles, sibling identity, class declaration, old reports, generated source, and source-family style were checked. This is the strongest coherent name; `StartWalkAnimation` is a lower-probability lexical alternative and does not block implementation.
- Was the parameter originally `direction`, `facing`, or an enum? Call values, storage, timer argument, packet sentinels, and project APIs were checked. `unsigned char direction` is strongest. Introducing an enum would invent an unproven type.
- Is `+0x1a0` movement speed? No. Exact offset arithmetic into UID00009S proves `m_displayStatusByte`; the old name is rejected.
- Is scale unsigned? No. All 23 direct loads are signed. Plain `char` is highest-probability source spelling; explicit `signed char` is the only viable runner-up.
- Can scale be zero or negative? No writer was found, and initialized value is 1. Machine code has no guard, so source must preserve unguarded division regardless of theoretical invalid states.
- Is the final MapPane call generic invalidation? The exact call target is UID0004DS `UpdateObjectPaneScreenBounds`; use that source identity. Broader invalidation wording remains descriptive behavior only.
- Does the target return an integer? No caller consumes EAX and no source return is established; use `void`.
- Does target require a child split or no-code treatment? No. One function/block/body and four live callers prove one emitting source method.
- Remaining unresolved questions with code/score impact: none. Only exact private lexical spelling is unrecoverable and already reflected in the sub-95 scores.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-application handoff: the exact text below is preserved verbatim as the supervisor-owned replacement/addition package prepared before commands `000000012707` and `000000012708`; it is no longer pending work.
- Read-only files historically inspected: `by-memory/-coverage-report.md` rows for UID0003U7, UID0003U8, UID0003UQ, and UID00027F; `by-global/-coverage-report.md` row for UID0002CF; surrounding UID0003U7/UID0003U8 hierarchy for padding placement.
- UID0003U8 and UID0003UQ manual rows retained correct paths/scores/high-level descriptions and required no text change from this bounded token repair.
- Historical handoff instruction: replace the UID0003U7 row in `by-memory/-coverage-report.md` with:

`        - [UID:0003U7][0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation](by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md) 0x005a36f0-0x005a3766 | UserPane member | UserPaneInitializeWalkAnimation : reconstructable : 92% : very-strong : Exact 118-byte one-block, four-call UserPane walk-animation initializer; clears movement token/delay state, sets moving/facing/frame state, cancels FBSA, schedules FWdA through the inherited TimerHandler using display-status byte divided by signed movement scale, and refreshes MapPane object screen bounds.`

- Historical handoff instruction: insert immediately after that UID0003U7 row and before UID0003U8:

`        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a3766-0x005a3770 | compiler/linker alignment | UserPane InitializeWalkAnimation to StartDirectionalAnimation alignment : ignored : 100% : strong : Ten all-0xcc bytes, SHA256 22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045; no function, xref, data, or source-body role.`

- Historical handoff instruction: replace the UID0002CF row in `by-global/-coverage-report.md` with:

`- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) : reconstructable : 91% : very-strong : MapPane-owned file-static plain-char movement substep scale initialized to 1; exact storage UID00027F at 0x0066da96, 23 direct reads across 14 movement/timer functions, every reader using signed extension, no direct writer, strict neighboring-global boundaries, coherent MapPane coordinate ownership, and explicit rejection of unsigned declarations, standalone movement-global files, and consumer ownership.`

- Historical handoff instruction: replace the UID00027F row in `by-memory/-coverage-report.md` with:

`    - [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md) 0x0066da96-0x0066da97 | signed movement scale byte | g_movementSubstepScale : reconstructable : 90% : very-strong : Exact initialized byte value 1 directly owned by MapPane and declared through semantic global UID0002CF; 23 direct reads across 14 functions all sign-extend the byte, no direct writer exists, neighboring width/EPF/height boundaries remain strict, and the storage page stays nonduplicating through its covered-by formal marker.`

- No tracker row text is proposed. The tracker is validator-owned and current direct report/lifecycle state is external.
- Current applied state: the supervisor applied the by-memory handoff under command `000000012707` and the by-global handoff under command `000000012708`, both exit 0 / `ok:1`. Current rows preserve the accepted facts and add no-loss link/detail enrichment where appropriate. B004 did not apply or validate these manual files.

## Follow-Up Actions

- Supervisor boundary: exact-artifact report validation, callback authorization, report execution/counting/path/move/archive state remain external supervisor/validator-owned facts. Manual coverage application is separately recorded as completed historical supervisor action under commands `000000012707` and `000000012708`; this artifact does not direct lifecycle outcomes.
- A-agent actions: none required by the source decision.
- Completed B004 callback scope: C3U7-001 through C3U7-046 were applied only to the six named ordinary destinations; each short lease was released after its scoped validator, and one waited generated refresh reconciled this same report.
- Verified generated assertions: one UID0003U7 definition; no target Empty Emitter Marker; no `m_objectStatus.m_movementSpeed` in emitted UserPane source; exact `UpdateObjectPaneScreenBounds` calls in all three audited managed bodies; one signed UID0002CF declaration and one UID00027F covered-by marker in MapPane output; no duplicate storage declaration.
- No additional target research action remains. New evidence that recovers literal private spelling could refine confidence later but is not an implementation blocker.

## Confidence

- Recommendation confidence: very strong. The method is live, exact, source-authored, fully routed, and behavior-complete.
- Score confidence: high for `92/94`; the residual sub-95 cap accurately reflects stripped lexical provenance rather than unresolved code.
- Scale type confidence: very strong for signed one-byte behavior; strong for plain `char` as the most probable original spelling.
- Ownership confidence: very strong for UserPane target ownership and strong for retained MapPane scale ownership.
- Remaining uncertainty: exact original private method/global spellings and plain versus explicitly signed `char`; neither changes machine behavior or destination readiness.

## Validator Results

- `000000012693`, timestamp `2026-07-15T01:49:17-04:00`, wall interval `2026-07-15T01:49:17.4472355-04:00` to `01:49:19.6385344-04:00`: scoped target file apply, exit 0, `ok:1`; completion/confidence became `92/94`; validator normalized two UID link labels, updated reference index/registry/projected stats, and deferred generation.
- `000000012694`, timestamp `2026-07-15T01:49:57-04:00`, wall interval `2026-07-15T01:49:57.4179928-04:00` to `01:49:59.3587213-04:00`: scoped UID0003U8 file apply, exit 0, `ok:1`; UID link/reference index/registry/projected-stat side effects only, generation deferred.
- `000000012695`, timestamp `2026-07-15T01:50:48-04:00`, wall interval `2026-07-15T01:50:48.3327917-04:00` to `01:50:50.2832156-04:00`: scoped UID0003UQ file apply, exit 0, `ok:1`; reference index/registry/projected-stat side effects only, generation deferred.
- `000000012696`, timestamp `2026-07-15T01:51:51-04:00`, wall interval `2026-07-15T01:51:50.8490602-04:00` to `01:51:52.7971906-04:00`: scoped UID0002CF file apply, exit 0, `ok:1`; completion/confidence became `91/93`; registry/projected-stat side effects only, generation deferred.
- `000000012697`, timestamp `2026-07-15T01:52:36-04:00`, wall interval `2026-07-15T01:52:36.2654357-04:00` to `01:52:38.2195236-04:00`: scoped UID00027F file apply, exit 0, `ok:1`; completion/confidence became `90/93`; projected-stat side effect only, generation deferred.
- `000000012698`, timestamp `2026-07-15T01:54:07-04:00`, wall interval `2026-07-15T01:54:06.9044345-04:00` to `01:54:09.3688155-04:00`: scoped UID0000VN file apply, exit 0, `ok:1`; two reference-index additions and projected-stat update. It emitted 279 pre-existing/inherited `missing_ref_uid` diagnostics (first listed UID0003E6/E7/E8/E9/J2/J3/3BR/3BS/3BT/3BU), none caused by the new valid UID0003U7/UID0003U8 row; generation deferred.
- `000000012699`, timestamp `2026-07-15T01:54:32-04:00`, wall interval `2026-07-15T01:54:32.1449391-04:00` to `01:54:50.9186443-04:00`: exact authorized target `--wait-generated` command, exit 0, `ok:1`, `generated_refresh:completed`. Project-wide non-fatal diagnostics were `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:86`, `autogen_emitter_has_no_code:171`, and `generated_metadata_refresh:281`; none is a scoped UID0003U7 failure.
- Supervisor command `000000012707`, timestamp `2026-07-15T02:29:39-04:00`: `by-memory/-coverage-report.md` validation, exit 0, `ok:1`; synchronized UID0003U7, the `[0x005a3766,0x005a3770)` padding row, and UID00027F. This was not a B004 command.
- Supervisor command `000000012708`, timestamp `2026-07-15T02:29:45-04:00`: `by-global/-coverage-report.md` validation, exit 0, `ok:1`; synchronized UID0002CF. This was not a B004 command.
- Generated headers: both `auto-generated/NexusTK/ui/panels/UserPane.cpp` and `auto-generated/NexusTK/map/MapPane.cpp` identify validator command `000000012699`, refresh time `2026-07-15T01:54:32-04:00`, and `foreground-generated-refresh`.
- Generated semantic proof: UID0003U7/UID0003U8/UID0003UQ each have one definition and each emitted body exactly equals its managed destination body; target Empty Emitter Marker count 0; old `m_objectStatus.m_movementSpeed` token count 0; direct `UpdateObjectPaneScreenBounds` call counts are target 1, UID0003U8 1, UID0003UQ 3. MapPane has exactly one `static char g_movementSubstepScale = 1;`, zero unsigned declarations, exactly one storage declaration, and one UID00027F covered-by marker.
- Formal equality proof: accepted Destinations 1-5 each compare exactly, after newline normalization, to the complete managed block in their final ordinary page.
- Lease closure proof: final `tools/leaser/Agents/current_leases.md` SHA256 `EA2FA43FFE5ADAEE941CD801C5EA2E206A3D9B9D7FFC692F685134199392AAC4` contains zero `B004` lease rows.
- No scoped validator failed. B004 ran no validator report-lifecycle command.

## Changed Files

- Modified ordinary `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md`: SHA256 `37D1744E755C3404DA734068F9F29A9B992041FD328AACD6ED343FBB92A94347`; validator `000000012693`; lease released.
- Modified ordinary `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`: SHA256 `2D32082CD06C6EB86349ABC11FF6704BE90C2272DC111CCEE88B6AF31107C237`; validator `000000012694`; lease released.
- Modified ordinary `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md`: SHA256 `EF1AA9A3C398472A66A41D7BE6FD16A2CE9B886BAB6465AD23C9ED71F46F3B11`; validator `000000012695`; lease released.
- Modified ordinary `by-global/g_movementSubstepScale.md`: SHA256 `DBF3253E5D0C80F4A18BDBECADA282736FB6F21559C9FD72F1C7746DF77AF31B`; validator `000000012696`; lease released.
- Modified ordinary `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`: SHA256 `850C4A8DE9E2420EF00459EACD2B9867924256B5DA85180A9D752E563DC21EB6`; validator `000000012697`; lease released.
- Modified ordinary `by-memory/-ignored.md`: SHA256 `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232`; validator `000000012698`; lease released.
- Modified this same report in place; its final hash/metrics are computed after the terminal consistency scan.
- Generated files were refreshed only by authorized validator `000000012699`, not manually: `UserPane.cpp` SHA256 `DDE87CCDC7700348665C170FF768C18909CF4636125EF77B46E3152AA3856EEA`; `MapPane.cpp` SHA256 `1DBEA0BAAEA313EE54737C5D9D75AAB18BFCE2680DB9CEE8D9F7D08D0C783B94`.
- Supervisor-modified manual coverage: `by-memory/-coverage-report.md` SHA256 `96546FE73C04070B835DA2C2656092D3E40E77B3CBAE29A7C803C23B0BEF8990` under command `000000012707`; `by-global/-coverage-report.md` SHA256 `7E02F744D4AFC5259002545D36C13B8FDBA0D3F93FD851F96DC830765E8296F1` under command `000000012708`.
- B004-modified manual coverage/tracker/audit/supervisor/validator-state/lifecycle/archive/report-registry files: none.
- Renamed files: none.
- IDA mutations: none.
- Leases acquired: six, one ordinary destination at a time; every lease was released immediately after scoped validation. Final lease report is recorded in the terminal verification.
- Report execution: not run. B004 ran no execute, probe, count, revalidation, move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor accepted exact pre-callback SHA256 `4A64459D38D69C1C4B71E63E52797EEE84A6EDFF1CCD90F0D0FA1A75CB066B49` before implementation.
- [x] Target/support docs bounded to UID0003U7, UID0003U8, UID0003UQ, UID0002CF, UID00027F, and UID0000VN `by-memory/-ignored.md`.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and terminal verification state for every accepted claim.
- [x] Metadata/score results applied: UID0003U7 `92/94`, UID0002CF `91/93`, UID00027F `90/93`; support siblings unchanged.
- [x] Score-limiting blockers researched to resolution, including range, liveness, ABI, fields, helpers, timer event, scale type, map callee, source placement, historical contradiction, and final C++.
- [x] Owner/emitter/reconstructable changes confirmed unnecessary; target UID0000FQ/UID0000FQ/true and support routes retained.
- [x] No source split/rename/child applied; only the exact ignored alignment row was added.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment dispositions recorded.
- [x] Five exact managed formal blocks applied, including the unchanged storage covered-by marker.
- [x] Third-party import directive confirmed not applicable; no third-party path or import body exists.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 artifacts confirmed unused/rejected as stale.
- [x] Open questions closed or retained only as nonblocking lexical confidence caps.
- [x] One scoped validator run per changed ordinary destination after accepted callback.
- [x] Waited generated UserPane/MapPane refresh and exact readback assertions completed; exact manual-coverage handoff preserved historically and supervisor application commands `000000012707`/`000000012708` recorded.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at the recorded historical SHA/time.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with legal callback action and terminal verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed nonblocking rationale.
- [x] Scoped validators run and exact command IDs/timestamps/exits/ok/warnings recorded.
- [x] Waited generated refresh completed; historical manual supervisor-owned handoff retained exactly and current applied rows/commands recorded.
- [x] Remaining unapplied accepted implementation items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012711","destination_path":"executed-b-agent-research/B004/0003U7-UserPaneInitializeWalkAnimation-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003U7-UserPaneInitializeWalkAnimation-source-quality.md","timestamp":"2026-07-15T02:49:19-04:00","uid":"0003U7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
