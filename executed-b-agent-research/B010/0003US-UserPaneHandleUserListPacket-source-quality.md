** TARGET-REPORT-UID:0003US **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003US UserPane Handle User List Packet Source Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0003US] as the source-authored `bool UserPane::HandleUserListPacket(const ServerMessageEvent *event)` member at `[0x005abb20,0x005abc6f)`, keep canonical owner/emitter [UID:0000FQ], and retain the now-applied `94/95` metadata.
- Final disposition: reconstructable, nonblank formal CPP, blank target H because [UID:0000FQ] already declares the member, and source placement in [UID:0000P1] `NexusTK/ui/panels/UserPane.cpp`.
- Implemented ordinary action: target/support documentation now uses `m_userListPacketTick`, `m_userListDeferUntilTick`, `m_skipNextUserListPacket`, and the proven `g_pTimerMgr->m_currentTick`; the standalone body and opcode-`0x36` inline dispatcher copy remain distinct binary bodies.
- Ownership resolution: the receiver fields at `+0x13eb20..+0x13eb30` are outside the complete `0x20c` `LivingObjectPane` and inside the complete `0x13eb84` `UserPane`. LivingObjectPane ownership is rejected, not retained as an alternative.
- Liveness/source-shape resolution: the standalone body has zero xrefs, while the dispatcher contains an exact semantic inline clone at `[0x005a7bae,0x005a7cd7)`. The most plausible VC-era source had an ordinary out-of-line UserPane member whose body was also inlined into `UserPane::OnServerMessage`; reconstruction must retain both machine behaviors and must not rewrite the live dispatcher case as a call.
- Confidence: very strong. Exact original lexical spellings and the compiler's reason for retaining the unreferenced out-of-line body remain inferred, but behavior, object ownership, fields, ABI, body boundaries, duplicate relationship, and source route are independently corroborated.

## Supporting Research

- Current target artifact at report time: `by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md`, SHA256 `C5AB507DB756A76BF2F55D882B4B2460648BB95EA60E1E25BD1CEBAC6EFDBF29`, `15,952` bytes / `143` lines.
- Earlier report-time MCP session: `f608d7c2`. `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays and string cache ready. `auto_analysis_ready:false` was recorded as context; bounded IDB-backed calls remained successful.
- Resumption recheck at `2026-08-01T03:49:25-04:00`: that live read-only session reconfirmed target/helper/inline identities, exact ranges, literal function-comment prestates, stack frames, target zero-xref state, all three `0x005a5010` callers, UserPane/LivingObjectPane/TimerMgr exposed type layouts, and the three body hashes `07E608...9CE8`, `8E6DC1...3EA`, and `E56C59...7D4F`. The saved IDB remained SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`; no ordinary recommendation or implementation destination became stale.
- Gate 1 repair MCP session: `b3b2bf88`. At `2026-08-01T04:43:48-04:00`, bounded `server_health` returned `status:ok` and `auto_analysis_ready:true`. Current `type_inspect` and `type_query` each returned the same three UserPane member name/offset/size/type records, but their schemas expose no member-comment property; `search_structs` exposes only type summary metadata, `get_comments` is address/function based, and the live tool list contains no UDT-member-comment reader. Therefore the I02-I04 member-comment prestates are opaque, not absent.
- Gate 1 no-mutation repair recheck at `2026-08-01T05:20:55-04:00`: session `b3b2bf88` remained active and not analyzing; bounded `server_health` returned `status:ok`, `auto_analysis_ready:true`, and Hex-Rays/string-cache readiness. A fresh `tools/list` schema audit again proved that `type_inspect` and `type_query` expose only UDT-member `name,offset,size,type`, `search_structs` exposes only summary fields, `read_struct` exposes runtime member values rather than local-type comments, and `get_comments` accepts addresses only. Fresh `type_inspect(UserPane)` returned the exact unchanged records `int m_deferredUserListCount +0x13eb28 size 4`, `unsigned int m_deferredUserListDeadline +0x13eb2c size 4`, and `bool m_deferredUserListActive +0x13eb30 size 1`. Because no bounded tool can establish literal member-comment prestates, I02-I04 now authorize no IDA member mutation; their inferred replacements remain ordinary documentation/formal-source recommendations only.
- Dated saved-IDB checkpoint used for this report: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143,192,751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`. This is a report-time checkpoint, not a claim that the shared IDB can never advance.
- The MCP recovery pass was redone after the earlier timeout. This report relies only on successful post-recovery bounded calls for target, dispatcher, tables, helper, type, caller, comment, frame, byte, xref, and decompile evidence.
- Relevant historical reports were searched by UID, address, target name, `sub_5ABB20`, `HandleUserListPacket`, opcode `0x36`, UserPane/LivingObjectPane, and deferred-user-list field terms. `executed-b-agent-research/B001/0003US-LivingObjectPaneHandleUserListPacket-source-quality.md`, `B001/0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md`, and `B002/0003UK-LivingObjectPaneDeferredPacketBuffer-source-quality.md` are useful historical leads but retain superseded LivingObjectPane/no-code conclusions. Accepted B001 `0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md` supplies the later UserPane ownership correction and retained-source policy.
- Existing generated/tracker identities are dated bounded observations only. Validator command `000000020493`, refreshed `2026-07-31T10:40:09-04:00`, generated the current report-time UserPane CPP/H and tracker snapshot described below.

## Target

- Target UID: `0003US`.
- Additional target UIDs: none. The `0x005a5010` opener is fully characterized as support evidence but is not declared as additional direct report coverage.
- Declared-target inventory: one exact by-memory function page, `[0x005abb20,0x005abc6f)`, 335 bytes, role retained source-authored UserPane packet member.
- Target path: `by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md`.
- Pre-callback source queue row: dated command-20493 tracker line 1684 records `88/88`, average `88.0`, reconstructable true, `0/0/0` direct/additional/total B-report coverage. It is historical generated evidence, not the current target score.
- Durable callback provenance: the supervisor accepted exact pre-callback report SHA256 `2F478108A7A9B455FC84BA79DFB0888B05ABB129D2199DCD0F9EC68AA2CB34D7`, after which B010 applied and scoped-validated the accepted ordinary changes recorded in this artifact. Gate, execution, and archive state are external to ordinary report prose and authoritative only from the artifact's actual current path plus validator-owned status/history metadata.
- Current metadata: completion `94`, confidence `95`, owner/emitter `0000FQ`, reconstructable true, blank optional position, nonblank CPP, blank H, `Nested:8`.

## Current Target State

- UID0003US now has completion `94`, confidence `95`, owner/emitter `0000FQ`, reconstructable true, blank optional position, exact nonblank formal CPP, blank formal H, and `Nested:8`.
- The managed CPP uses `m_userListPacketTick`, `m_userListDeferUntilTick`, `m_skipNextUserListPacket`, and `g_pTimerMgr->m_currentTick`; UserPane class/file, dispatcher, key path, cleanup, copy-helper support, aggregate indexes, LivingObjectPane exclusions, and timer consumers are synchronized to the accepted ordinary claims.
- Current ordinary documentation treats the older LivingObjectPane qualification, raw `sub_5ABB20` identity, and blank/no-code conclusion only as explicitly rejected history. The standalone body and live inline opcode-`0x36` copy remain separate source/machine forms without an invented call.
- Current IDA target identity remains the already-correct `UserPane_HandleUserListPacket`, `bool __thiscall(UserPane *this, const ServerMessageEvent *event)`, exact range `[0x005abb20,0x005abc6f)`. B010 did not mutate or save IDA; I01/I05-I08 remain supervisor Gate 2B work and I02-I04 remain deterministic no-mutation rows.
- Current target body SHA256 from live bytes remains `07E608A9F5D9D8455BBB5786DC7B289C2B1A6D3FFBE7EBFB082B818878A79CE8` over 335 bytes. `LivingObjectPane` remains exactly `0x20c`; the complete `UserPane` remains `0x13eb84`.
- All 13 changed ordinary documents passed scoped serial validation with generated refresh disabled; the final ordinary claim audit passed C001-C051 (`51/51`). Manual coverage, generated topology, tracker refresh, IDA closure, execution, and archive movement remain supervisor-owned and are not claimed complete.
- Durable lifecycle statement: B010 completed and reconciled the ordinary callback documented here. Any execution or archive state is authoritative only from the artifact's actual current path plus validator-owned status/history metadata; this section does not assert a current directory or review stage.

## Executive Recommendation

- Direct owner: [UID:0000FQ] `UserPane`; source root [UID:0000P1] `NexusTK/ui/panels/UserPane.cpp`.
- Function name/signature: retain `bool UserPane::HandleUserListPacket(const ServerMessageEvent *event)`.
- Field names/types: retain `unsigned char *m_deferredUserListPacket` and `size_t m_deferredUserListPacketSize`; change `+0x13eb28` to `unsigned int m_userListPacketTick`, `+0x13eb2c` to `unsigned int m_userListDeferUntilTick`, and `+0x13eb30` to `bool m_skipNextUserListPacket`.
- Source representation: emit the complete standalone member and preserve the inline opcode-`0x36` copy in the broad dispatcher. A source-level call substitution would not reproduce the observed executable shape.
- Support synchronization: update UserPane class/file, dispatcher, key-event inline copy, cleanup member, broad local-player index, mixed SayMode index, and historical LivingObjectPane pages without pruning old assumptions.
- Associated helper `0x005a5010`: document as inferred `UserPane::OpenUserList`, not say-mode state. It requests nation data, replays a valid cached list with the skip-next guard, or sends opcode `0x18`. This exact conclusion removes its semantic use as a blocker; a separately registered exact child can later carry its own formal source without changing UID0003US ownership or score.

## Supervisor Active Recheck

- Trigger: supervisor assigned UID0003US specifically to resolve nonblank-CPP versus blank/no-code prose, UserPane versus LivingObjectPane ownership, and standalone zero-route versus inline opcode-`0x36` source shape.
- Split gate: the exact target is already correctly bounded; no target split is required. The dispatcher inline span remains part of UID0003VB and is not split into a second UID0003US emitter.
- Every source-bearing item needed to resolve the target was rechecked: target, inline duplicate, compact selector/jump tables, copy helper, cleanup helper, cache-open helper, class layouts, globals, dated report-time generated source and manual rows, historical reports, and direct callers/xrefs.
- The mixed UID0001KO support range remains correctly non-emitting. Its `0x005a5010` row needs semantic/source-family correction, but that support issue does not justify broad aggregate emission or a target no-code disposition.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and inference are kept separate throughout. Exact addresses, bytes, calls, fields, and types are IDA facts; current UIDs/routes/formals are documentation evidence; lexical names and retained-out-of-line source policy are inference.
- Existing documentation was treated as fallible. In particular, pre-2026-07-14 LivingObjectPane ownership, blank/no-code conclusions, `g_pCollectionData`, `ProcessDeferredSendState`, and stale field names were rechecked rather than copied.
- Source-quality inference follows the project's final goal: exact runtime behavior plus plausible human-written late-1999/mid-2000s C++, with no `sub_`, raw-offset, or decompiler-temporary names in formal source.
- Project naming consistency was preferred where evidence was comparable: historical reports already converge on `m_userListPacketTick`, `m_userListDeferUntilTick`, and `m_skipNextUserListPacket`; live `0x005a5010` behavior strengthens those names.
- Wave2/Wave3 references appeared in older prose/search results and were ignored as stale authority. None is used to prove this recommendation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution / classification |
| --- | --- | --- |
| `sub_5ABB20` / raw signature | Live lookup and item inspection now show `UserPane_HandleUserListPacket` with the exact typed member prototype. | Old raw identity is historical; current source name/type are already present IDA facts. |
| LivingObjectPane ownership | Live types give `sizeof(LivingObjectPane)==0x20c` and `sizeof(UserPane)==0x13eb84`; target touches `+0x13eb20..+0x13eb30`. | UserPane ownership is certain; LivingObjectPane current ownership is rejected-invalid. |
| Zero direct xrefs | Live `xrefs_to(0x005abb20)` is empty; current PE-era route searches in prior reports found no VA/RVA/rel32 route. | Liveness-negative evidence, not no-code proof. Retained outlined source is supported by the inline clone. |
| Inline duplicate | Opcode `0x36` maps through selector byte `0x0d` to jump-table entry `0x005a7bae`; exact inline end is `0x005a7cd7`. | Live dispatcher source keeps an inline copy; standalone retained source also emits. |
| Duplicate equivalence | Constants, fields, helper calls, direct-copy path, singleton allocation, and return behavior match. Receiver/prologue/register/call-displacement differences are compiler-context differences. | Exact semantic clone, not unrelated coincidental logic. |
| `m_deferredUserListCount` | Target stores current timer tick, cleanup zeros it, no count arithmetic exists. | Rename/type to `unsigned int m_userListPacketTick`; old count name reject-invalid. |
| `m_deferredUserListDeadline` | Target writes current tick plus tier delay; `0x005a5010` compares it unsigned against current tick to choose cached replay. | Rename to `m_userListDeferUntilTick`; old name is descriptive but less source-consistent. |
| `m_deferredUserListActive` | `0x005a5010` sets it immediately before dispatching the cached payload; handler clears it and skips cache restaging. | Rename to `m_skipNextUserListPacket`; generic active-state interpretation reject-invalid. |
| Timer member | Live TimerMgr UDT has `unsigned int m_currentTick` at `+0x18`. | Formal source must use `g_pTimerMgr->m_currentTick`; `currentTick` member spelling reject-stale. |
| Entry-count word | Both bodies call `PacketBufferReadUInt16BE(packet+3)` and compare 100/300/500/800. | `entryCount` is a safe descriptive local; exact original spelling remains inferred. |
| `0x005a5010` | Live body, three callers, and key-event inline copy tie it to opening/requesting user lists, not say-mode state. | Best name `UserPane::OpenUserList`; `ProcessDeferredSendState` and `SyncNationEntriesOrDeferredState` are rejected as overbroad/stale. |
| Header topology | UserPane class H already declares `HandleUserListPacket`. | Target H remains blank; duplicating the declaration in the child H would be invalid. |
| Score blocker | Prior score was capped by ownership/no-code/liveness uncertainty. | Exact type, typed target, complete clone, and source-route evidence remove those blockers; residual lexical/compiler-retention uncertainty caps below 100. |

## Evidence Standards Used

- Primary binary evidence: successful live MCP `server_health`, `lookup_funcs`, `inspect_items`, `get_comments`, `stack_frame`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `entity_query`, and `type_inspect` calls.
- Source-shape evidence: exact duplicate control/data semantics plus compiler-context differences; switch-table byte/pointer resolution; sole vtable data xref to dispatcher; current typed class/member layouts.
- Documentation evidence: target/support by-memory pages, UserPane/LivingObjectPane class/file roots, TimerMgr and singleton globals, accepted historical B reports, dated command-20493 generated CPP/H and tracker snapshots, and dated report-time manual coverage rows.
- Negative evidence: zero target start xrefs, zero `UserPane_OpenUserList` collision, no proposed field-name collision in current UserPane UDT, no target table/pointer route, no LivingObjectPane storage capacity for the fields, and no target need for a separate H declaration.
- Tool limitations: `ServerMessageEvent` exists as an incomplete named type in the live catalog. For UDT members, current `type_inspect` and `type_query` schemas expose only `name`, `offset`, `size`, and `type`; `search_structs` exposes only type summary metadata; `get_comments` accepts IDB addresses rather than local-type member identifiers; and no bounded UDT-member-comment reader exists in the live tool list. The member-comment state at UserPane `+0x13eb28`, `+0x13eb2c`, and `+0x13eb30` is therefore opaque and is not asserted empty or absent. That opacity blocks an implementation-ready IDA member mutation in this report, so I02-I04 protect the exact current IDA members unchanged while the independently supported source-facing names/types remain ordinary documentation/formal-source recommendations.

## Evidence Checked

- IDA MCP/manual checks: target and support function identities/ranges/types; exact first/last items; comments; frames; target/helper bytes; target/helper/dispatcher xrefs; target/inline callees; dispatcher beginning and opcode-`0x36` body; selector/jump-table values; UserPane/LivingObjectPane/TimerMgr/ServerMessageEvent types; globals; callers of `0x005a5010`; helper decompilation.
- Exact binary identities: target SHA256 `07E608A9F5D9D8455BBB5786DC7B289C2B1A6D3FFBE7EBFB082B818878A79CE8`; inline `[0x005a7bae,0x005a7cd7)` SHA256 `8E6DC1ADBFE3223DE5786EA92CE6CF0CEF39DCBA8F6BCE7997718E30DA8873EA`; `0x005a5010` SHA256 `E56C599799A7EE817A11599F167E5168E84FD7579843B5A857181BA80FCF7D4F` over 129 bytes.
- Current docs checked: UID0003US, UID0003VB, UID0003UK, UID0004TX, UID0001KM, UID0001KO, UID0003V9, UID0003UD, UID0003UI, UID0000FQ, UID00007B, UID0000P1, UID0000KU, UID0003EI, UID0000SI.
- Generated/report checks: dated command-20493 UserPane CPP/H, memory coverage, research tracker, and all report-relevant manual coverage rows.
- Old reports checked: exact UID/range/name matches only. Broad archived material unrelated to this family was intentionally not opened.
- No failed MCP evidence is used. The pre-recovery timeout was discarded; all listed conclusions were reconfirmed after the supervisor's health/get-bytes recovery signal.
- The `2026-08-01T03:49:25-04:00` resume pass repeated bounded `server_health`, `lookup_funcs`, `inspect_items`, `get_comments`, `stack_frame`, `xrefs_to`, `get_bytes`, `type_inspect`, `analyze_function`, `decompile`, `disasm`, and `callees` checks. Every exposed report-critical IDA prestate remained exact; that pass did not establish UDT-member comment absence.
- The `2026-08-01T04:43:48-04:00` and `2026-08-01T05:20:55-04:00` Gate 1 repair passes inspected the live `tools/list` schemas and repeated bounded `server_health`, `type_inspect`, `type_query`, and `search_structs` calls in session `b3b2bf88`. Both member-detail tools returned only `name,offset,size,type` for the three fields, and no available read-only tool exposes their comment channels. I02-I04 and C053-C055 therefore use deterministic no-mutation dispositions: the supervisor must leave those IDA members untouched, while the ordinary documentation/formal-source callback applies the inferred source-facing names/types.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0003US | Exact target range is `[0x005abb20,0x005abc6f)`, 335 bytes. | Certain | live lookup/items/bytes | UID0003US exact binary evidence | incorporate | applied |
| C002 | 0003US | Current IDA identity/type are `UserPane_HandleUserListPacket` and `bool __thiscall(UserPane *, const ServerMessageEvent *)`. | Certain | live lookup/items | UID0003US current state | already-present | already-present |
| C003 | 0003US | Target body SHA256 is `07E608...9CE8`. | Certain | live 335-byte read | UID0003US exact binary evidence | incorporate | applied |
| C004 | 0003US | Target start has zero current xrefs. | Certain | live xrefs | UID0003US liveness/negative evidence | incorporate | applied |
| C005 | 0003US | Opcode `0x36` resolves through selector index `0x0d` to inline case `0x005a7bae`. | Certain | table bytes/disasm | UID0003US duplicate analysis | incorporate | applied |
| C006 | 0003US | Inline clone range is `[0x005a7bae,0x005a7cd7)`, 297 bytes, SHA256 `8E6DC1...3EA`. | Certain | live items/bytes/disasm | UID0003US duplicate analysis | incorporate | applied |
| C007 | 0003US | Standalone and inline bodies have identical semantic thresholds, fields, helpers, direct-copy branch, singleton creation, and true return. | Very strong | side-by-side disassembly | UID0003US source-shape decision | incorporate | applied |
| C008 | 0003US | Prologue/register/receiver/call displacement differences are compiler context, not behavior differences. | Very strong | side-by-side disassembly | UID0003US source-shape decision | incorporate | applied |
| C009 | 0003US | UserPane is the direct class owner and UID0000FQ is the canonical emitter. | Certain | type sizes/offsets/current route | UID0003US ownership | incorporate | applied |
| C010 | 0003US | LivingObjectPane ownership is impossible because the base ends at `+0x20c`. | Certain | live type layout | UID0003US rejected/history section | reject-invalid | applied |
| C011 | 0003US | Event packet pointer/size are read from event `+0x0c/+0x10`. | Certain | target/dispatcher instructions | UID0003US behavior | incorporate | applied |
| C012 | 0003US | Entry count is UInt16BE at packet `+3`. | Certain | both bodies/callee | UID0003US behavior/formal CPP | incorporate | applied |
| C013 | 0003US | Timer source field is `g_pTimerMgr->m_currentTick` at `+0x18`. | Certain | TimerMgr UDT/target reads | UID0003US formal CPP | incorporate | applied |
| C014 | 0003US | `+0x13eb28` stores the packet receipt/current tick, not an entry count. | Certain | exact store/cleanup | UID0003US fields/prose | incorporate | applied |
| C015 | 0003US | Count `<100` sets defer-until tick to current tick and makes no cache copy. | Certain | exact branches | UID0003US behavior/formal CPP | incorporate | applied |
| C016 | 0003US | Count `100..299` uses `+30000` and copy helper. | Certain | exact branches | UID0003US behavior/formal CPP | incorporate | applied |
| C017 | 0003US | Count `300..499` uses `+60000` and copy helper. | Certain | exact branches | UID0003US behavior/formal CPP | incorporate | applied |
| C018 | 0003US | Count `500..799` uses `+90000` and copy helper. | Certain | exact branches | UID0003US behavior/formal CPP | incorporate | applied |
| C019 | 0003US | Count `>=800` uses `+150000` and direct free/malloc/size/memmove. | Certain | exact branches/callees | UID0003US behavior/formal CPP | incorporate | applied |
| C020 | 0003US | `+0x13eb30` is a one-shot skip-restaging flag set before cached dispatch and cleared by the handler. | Certain behavior, strong name | target plus 0x5a5010 | UID0003US fields/formal CPP | incorporate | applied |
| C021 | 0003US | UID0003UK has exactly six calls: three inline and three standalone. | Certain | live xrefs | UID0003US/helper links | incorporate | applied |
| C022 | 0003US | Null singleton path allocates `0x28c` and calls UserListDialogPane constructor with original packet pointer. | Certain | both bodies | UID0003US behavior/formal CPP | incorporate | applied |
| C023 | 0003US | Function returns true on all paths. | Certain | CFG/epilogue | UID0003US behavior/formal CPP | incorporate | applied |
| C024 | 0003US | Source must retain outlined member and inline dispatcher copy; no artificial direct call is introduced. | Very strong | binary duplication/zero route | UID0003US source placement | incorporate | applied |
| C025 | 0003US | Replace target formal CPP with exact source-quality block in this report. | Very strong | all target evidence | UID0003US RECONSTRUCTION_CPP | incorporate | applied |
| C026 | 0003US | Target formal H remains blank because UID0000FQ already declares the method. | Certain | class H topology | UID0003US RECONSTRUCTION_H | already-present | already-present |
| C027 | 0003US | Raise metadata to `94/95`; retain owner/emitter/reconstructable/position/Nested. | Strong | blocker closure/complete source | UID0003US metadata | incorporate | applied |
| C028 | 0003US | Preserve pre-2026-07-14 LivingObjectPane/no-code conclusions as explicitly rejected history. | Certain | current contradictory prose | UID0003US history | historicalize | applied |
| C029 | 0000FQ | Rename/type `+0x13eb28` to `unsigned int m_userListPacketTick`. | Very strong | exact use/current reports | by-class/UserPane H/prose | incorporate | applied |
| C030 | 0000FQ | Rename `+0x13eb2c` to `m_userListDeferUntilTick`, preserving unsigned type/offset. | Strong | write/compare semantics | by-class/UserPane H/prose | incorporate | applied |
| C031 | 0000FQ | Rename `+0x13eb30` to `m_skipNextUserListPacket`, preserving bool/offset. | Strong | replay set/handler clear | by-class/UserPane H/prose | incorporate | applied |
| C032 | 0000FQ | Preserve pointer/size members and total class size `0x13eb84`. | Certain | live type/current H | by-class/UserPane H/prose | already-present | already-present |
| C033 | 0000FQ | Historicalize line-610 LivingObjectPane duplicate ownership and cleanup stale field prose. | Certain | current class text/live types | by-class/UserPane history | historicalize | applied |
| C034 | 0000P1 | Synchronize source-root field names, target body, cleanup behavior, inline key path, and UserPane ownership. | Very strong | target/support evidence | by-file/UserPane current source family | incorporate | applied |
| C035 | 0003V9 | Replace key-event inline cache check/guard with `m_userListDeferUntilTick`/`m_skipNextUserListPacket`. | Certain behavior, strong names | formal block/live 0x5a5010 clone | UID0003V9 formal CPP/prose | incorporate | applied |
| C036 | 0004TX | Replace cleanup formal stores with `m_userListPacketTick` and `m_userListDeferUntilTick`. | Certain | exact stores/field semantics | UID0004TX formal CPP | incorporate | applied |
| C037 | 0004TX | Replace count/deadline/active prose while preserving observed no-store to size/skip flag. | Certain | live body/stores | UID0004TX prose/history | incorporate | applied |
| C038 | 0003UK | Keep pointer/size formal; synchronize caller-side field-name prose to final names. | Very strong | helper body and six callers | UID0003UK field/history prose | incorporate | applied |
| C039 | 0003VB | Replace LivingObjectPane offset/receiver wording for opcode `0x36` with UserPane complete-object semantics; retain inline body. | Certain | type sizes/dispatcher adjust | UID0003VB opcode-0x36 prose | incorporate | applied |
| C040 | 0001KM | Synchronize UID0003US/UID0003UK rows and trailing-state field names as UserPane-only. | Certain | accepted aggregate role/live types | UID0001KM inventory/history | incorporate | applied |
| C041 | 0001KO | Reclassify `0x005a5010` row from say/deferred-send ambiguity to UserPane user-list opener support. | Very strong | live body/callers/clone | UID0001KO inventory/evidence | incorporate | applied |
| C042 | 00007B | Keep old `+0x13ebxx` research only as rejected adjusted-local-player history; no current LivingObjectPane field ownership. | Certain | `0x20c` type | by-class/LivingObjectPane history | historicalize | applied |
| C043 | 0000KU | Preserve explicit exclusion of UserPane-only large-offset functions and historicalize stale user-list ownership references. | Certain | file boundary/current route | by-file/LivingObjectPane history | historicalize | applied |
| C044 | 0003UD | Replace `g_pTimerMgr->currentTick` with `g_pTimerMgr->m_currentTick` in formal/prose. | Certain | TimerMgr UDT | UID0003UD formal/prose | incorporate | applied |
| C045 | 0003UI | Replace `g_pTimerMgr->currentTick` with `g_pTimerMgr->m_currentTick` in formal/prose. | Certain | TimerMgr UDT | UID0003UI formal/prose | incorporate | applied |
| C046 | 0000SI | TimerMgr global name/type and `m_currentTick` dependency are already correct. | Certain | live global/type/current docs | by-global/g_pTimerMgr | already-present | already-present |
| C047 | 0003EI | User-list-dialog singleton name/type/definition are already correct. | Certain | live global/current docs | by-global/g_pUserListDialogPane | already-present | already-present |
| C048 | 0001KO | `0x005a5010` requests nation entries, checks cached validity, replays cached payload, or sends opcode `0x18`. | Certain | live decompile/disasm | UID0001KO function map/evidence | incorporate | applied |
| C049 | 0001KO | `0x005a5010` receives `g_pUserPane` at all three callers and touches UserPane-only fields. | Certain | live callers/offsets | UID0001KO ownership note | incorporate | applied |
| C050 | 0001KO | `0x005a5010` has exactly three direct callers at `0x4cf6f6`, `0x4cf925`, `0x5bd12d`. | Certain | live xrefs | UID0001KO xref inventory | incorporate | applied |
| C051 | 0001KO | Reject `SayToPlanMessageInputPane::ProcessDeferredSendState` and `g_pCollectionData` as current identities. | Certain | live UserPane callers/type | UID0001KO history | reject-invalid | applied |
| C052 | 0003US | Add exact target function comment without changing already-correct name/type/body/frame. | Very strong | I01 | IDA I01 | incorporate | proposed |
| C053 | 0000FQ | Leave IDA `int m_deferredUserListCount +0x13eb28` unchanged because no bounded tool exposes its literal member-comment prestate; apply inferred `unsigned int m_userListPacketTick` only in ordinary documentation/formal source. | Very strong | I02 plus two live schema/member audits | IDA I02 no-mutation disposition | not-applicable | proposed |
| C054 | 0000FQ | Leave IDA `unsigned int m_deferredUserListDeadline +0x13eb2c` unchanged because no bounded tool exposes its literal member-comment prestate; apply inferred `m_userListDeferUntilTick` only in ordinary documentation/formal source. | Strong | I03 plus two live schema/member audits | IDA I03 no-mutation disposition | not-applicable | proposed |
| C055 | 0000FQ | Leave IDA `bool m_deferredUserListActive +0x13eb30` unchanged because no bounded tool exposes its literal member-comment prestate; apply inferred `m_skipNextUserListPacket` only in ordinary documentation/formal source. | Strong | I04 plus two live schema/member audits | IDA I04 no-mutation disposition | not-applicable | proposed |
| C056 | 0001KO | Rename/type/comment `0x005a5010` as inferred `UserPane_OpenUserList`. | Strong | I05 | IDA I05 | incorporate | proposed |
| C057 | 0003UK | Add exact function comment to already-correct copy helper. | Very strong | I06 | IDA I06 | incorporate | proposed |
| C058 | 0004TX | Replace stale cleanup function comment with final field semantics. | Very strong | I07 | IDA I07 | incorporate | proposed |
| C059 | 0003VB | Add exact opcode-0x36 function comment; do not force unsafe broad prototype/frame mutation in this target transaction. | Very strong | I08 | IDA I08 | incorporate | proposed |
| C060 | 0003US | Replace manual by-memory target row with 94%/very-strong source-ready text. | Strong | M01 | by-memory/-coverage-report.md | incorporate | proposed |
| C061 | 0003VB | Existing dispatcher manual row remains semantically current. | Certain | M02 | by-memory/-coverage-report.md | already-present | already-present |
| C062 | 0003UK | Existing copy-helper manual row remains semantically current. | Certain | M03 | by-memory/-coverage-report.md | already-present | already-present |
| C063 | 0004TX | Replace cleanup manual-row count/deadline/active wording. | Certain | M04 | by-memory/-coverage-report.md | incorporate | proposed |
| C064 | 0001KM | Existing broad local-player index manual row needs no target-specific replacement. | Certain | M05 | by-memory/-coverage-report.md | already-present | already-present |
| C065 | 0001KO | Replace mixed-index row to identify the exact UserPane `0x005a5010` exclusion. | Strong | M06 | by-memory/-coverage-report.md | incorporate | proposed |
| C066 | 0000FQ | Apply exact token replacement in class row for final cleanup field names. | Strong | M07 | by-class/-coverage-report.md | incorporate | proposed |
| C067 | 00007B | Existing `0x20c` class manual row needs no target-specific change. | Certain | M08 | by-class/-coverage-report.md | already-present | already-present |
| C068 | 0000P1 | Apply exact token replacement in file row for final cleanup field names. | Strong | M09 | by-file/-coverage-report.md | incorporate | proposed |
| C069 | 0000KU | Existing file row already excludes UserPane-only large offsets. | Certain | M10 | by-file/-coverage-report.md | already-present | already-present |
| C070 | 0003V9 | Existing key-event manual row remains behaviorally current after lexical field sync. | Certain | M11 | by-memory/-coverage-report.md | already-present | already-present |
| C071 | 0003UD | Existing action-helper manual row needs no timer-member spelling change. | Certain | M12 | by-memory/-coverage-report.md | already-present | already-present |
| C072 | 0003UI | Existing movement-sender manual row needs no timer-member spelling change. | Certain | M13 | by-memory/-coverage-report.md | already-present | already-present |
| C073 | 0003US | At the dated command-20493 checkpoint, generated CPP has one target marker/definition and stale field names; H has one declaration and stale fields. | Certain | generated scan | report generated evidence | incorporate | already-present |
| C074 | 0003US | Expected refreshed generated topology is one target definition, one class declaration, final field names, and no target empty marker. | Strong | formal routing | report generated expectations | incorporate | proposed |
| C075 | 0003US | Command-20493 tracker row is a dated 88/88 pre-callback snapshot and must advance only through validator generation. | Certain | tracker line 1684 | report tracker evidence | incorporate | already-present |
| C076 | 0003US | Report execution/archive remains supervisor-owned and path/history authoritative. | Certain | workflow | report lifecycle wording | not-applicable | already-present |
| C077 | 0003US | No third-party import directive applies. | Certain | custom game code | target formal disposition | not-applicable | already-present |
| C078 | 0003US | Wave2/Wave3 material was ignored as stale authority. | Certain | workflow/search | inference/history | reject-stale | already-present |
| C079 | 0003US | No unresolved behavior, owner, placement, CPP, H, or score blocker remains for the target. | Strong | complete audit | final recommendation | incorporate | applied |

## Positive Evidence Summary

- The exact target is already modeled as a typed UserPane method, and every meaningful receiver field is inside the live UserPane UDT.
- The live dispatcher contains a byte-bounded opcode-`0x36` case whose dataflow and side effects match the standalone target exactly.
- The compact selector/jump tables independently prove opcode-to-inline-case routing without routing to the standalone start.
- Six exact copy-helper calls split three/three between the inline and standalone forms, an unusually strong duplicate-body fingerprint.
- Both forms use identical tier thresholds and millisecond constants, identical TimerMgr storage, identical large-buffer ownership, and identical dialog singleton creation.
- The cache-open helper independently proves the semantics of the defer-until tick and one-shot skip-next flag.
- Current UserPane class/file and accepted UID0002QY evidence already establish the source route and class declaration; this report closes stale field and no-code residue rather than inventing a new module.

## IDA MCP Facts

- Target function: `0x005abb20`, current `UserPane_HandleUserListPacket`, size `0x14f`, exclusive end `0x005abc6f`, prototype `bool __thiscall(UserPane *this, const ServerMessageEvent *event)`.
- Target frame: `Block +0x10 void *`, `var_C +0x14 _DWORD`, `var_4 +0x1c _DWORD`, saved registers `+0x20`, return address `+0x24`, `event +0x28 const ServerMessageEvent *`, residual `arg_4 +0x2c _DWORD`.
- Target comments: address regular `""`; address repeatable `""`; function regular `""`; function repeatable `""`.
- Target xrefs: zero. Copy helper xrefs: six exact calls. Dialog constructor calls include inline `0x005a7ccb` and standalone `0x005abc54`.
- Dispatcher: `sub_5A76C0`, size `0xbfd`, sole data xref from vtable cell `0x0062efa0`, which contains little-endian pointer `0x005a76c0`.
- Dispatcher entry saves ECX in EBX; `[ebx+0x3e1a]` is complete-object `+0x3eba`, proving the machine receiver is the inherited EventHandler facet at UserPane `+0xa0`. Inline case begins with `add ebx, -0xa0` to recover complete UserPane.
- Selector byte at normalized opcode index `0x32` is `0x0d`; jump-table entry 13 is `0x005a7bae`.
- `0x005a5010`: current `sub_5A5010`, `[0x005a5010,0x005a5091)`, type `void __thiscall(int this)`, 39 instructions, comments all empty, frame `Src +0x4 __int16[6]`, `var_4 +0x10`, saved registers `+0x14`, return address `+0x18`; three direct callers.
- `0x005a5010` calls nation-table request `0x00503c70`, packet sender `0x00574bb0`, and `DispatchCopiedEventPayload` `0x004aa050`. It compares `+0x13eb2c` unsigned against TimerMgr current tick, sets `+0x13eb30`, and dispatches pointer/size or sends one byte `0x18`.
- UserPane UDT size `1,305,476` / `0x13eb84`; LivingObjectPane size `524` / `0x20c`; TimerMgr `m_currentTick` is unsigned int at `+0x18`; `ServerMessageEvent` is named but incomplete in the current type catalog.
- UserPane member records at `+0x13eb28`, `+0x13eb2c`, and `+0x13eb30` expose exact name/type/offset/size through both `type_inspect` and `type_query`. Their comment channels are opaque to the current bounded read-only schemas; no empty/absent comment claim is made, and no IDA mutation of those three members is recommended by this report.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x005abb20,0x005abc6f)` | UID0003US | retained outlined UserPane member | true | UID0001KM | `88/88 -> 94/95` | target; source-ready after callback |
| `[0x005a7bae,0x005a7cd7)` | inside UID0003VB | live inline opcode-0x36 clone | true through dispatcher | UID0003VB | UID0003VB `87/89` | preserve inline; no split/call rewrite |
| `[0x005a9310,0x005a934a)` | UID0003UK | deferred packet copy helper | true | UID0001KM | `88/90` | source-ready; prose sync |
| `[0x005a89d0,0x005a8a01)` | UID0004TX | deferred packet cleanup | true | UID0001KM | `92/94` | source-ready; field sync |
| `[0x005a5010,0x005a5091)` | inside UID0001KO | UserPane user-list opener/request helper | custom code, exact child not registered | UID0001KO | aggregate `86/88` | fully characterized support; aggregate remains non-emitting |
| `0x005a8324` compact table | UID0003VC | opcode selector bytes | false source data/compiler table | UID0003VB | existing | opcode0x36 -> index13 |
| `0x005a82c0` jump table | UID0003VC | dispatcher jump targets | false source data/compiler table | UID0003VB | existing | index13 -> 0x5a7bae |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005abb20` | no xrefs | retained outlined body has no live start route |
| `0x0062efa0 -> 0x005a76c0` | sole dispatcher data xref | UserPane EventHandler vtable route |
| `0x005a7c44`, `0x005a7c64`, `0x005a7c84` | inline calls to UID0003UK | medium-tier cache copies |
| `0x005abbdb`, `0x005abbfb`, `0x005abc1b` | standalone calls to UID0003UK | same medium-tier cache copies |
| `0x005a7ccb`, `0x005abc54` | UserListDialogPane constructor calls | same singleton-open tail |
| `0x004cf6f6`, `0x004cf925`, `0x005bd12d` | callers of `0x005a5010` | three UI routes pass `g_pUserPane` |
| `0x00510200 -> 0x005a89d0` | sole cleanup call | MapPane transition clears cached packet state |
| `0x0069b4e0` | `g_pUserListDialogPane`, 12 refs | singleton dependency, not owner |
| `0x0067ab80` | `g_pTimerMgr`, 125 refs | current-tick dependency, not owner |

## Documentation Evidence And IDA Status

- UID0003US is now `94/95`, owner/emitter UID0000FQ, reconstructable, nonblank exact formal CPP, and blank formal H. Its current section preserves the exact target/clone evidence and labels the older LivingObjectPane, raw-name, and blank/no-code conclusions explicitly as rejected history.
- UID0000FQ `by-class/UserPane.md` and UID0000P1 `by-file/UserPane.md` now use `m_userListPacketTick`, `m_userListDeferUntilTick`, `m_skipNextUserListPacket`, and `g_pTimerMgr->m_currentTick`, retain pointer/size state and class size `0x13eb84`, and document the standalone-plus-inline UserPane source shape and narrow cleanup behavior.
- UID0003VB now records opcode `0x36` as the live inline UserPane case, including `-0xa0` complete-object recovery, exact selector/range, final field names, threshold/timing behavior, copy/direct-allocation branches, singleton creation, and the prohibition on inventing a call to UID0003US.
- UID0003UK retains its exact pointer/size formal source and now uses the final caller-side UserPane timing/guard names while preserving all six inline/standalone call sites and the separation from movement-history state.
- UID0004TX now clears `m_userListPacketTick` and `m_userListDeferUntilTick` in formal source and prose, while explicitly preserving `m_deferredUserListPacketSize` and `m_skipNextUserListPacket` because the exact body contains no stores to them.
- UID0003V9 now uses `m_userListDeferUntilTick` and `m_skipNextUserListPacket` in the source-level cached user-list path under key `'w'`; the dispatch behavior remains unchanged.
- UID0001KO now classifies `[0x005a5010,0x005a5091)` as inferred `UserPane::OpenUserList`, records all three `g_pUserPane` callers, nation request/cached replay/opcode-`0x18` behavior, and rejects the former say/deferred-send and `g_pCollectionData` identities.
- The dated command-20493 UserPane.cpp/H and tracker snapshots remain pre-callback generated evidence only. B010 did not refresh generated output; the ordinary post-callback state is authoritative from the validator-final by-* destinations and hashes recorded below. No current C001-C051 ordinary contradiction remains identified.

## Ranked Ownership Analysis

### 1. UserPane / UserPane.cpp

- Evidence for: exact current typed function, all touched offsets within complete UserPane, current owner/emitter, matching dispatcher source family, three helper callers passing `g_pUserPane`, and existing declaration/source root.
- Evidence against: no direct route to standalone start and original lexical spellings unavailable.
- Decision: certain structural owner and very-strong source placement. Route-negative evidence affects retained source-shape confidence, not ownership.

### 2. LivingObjectPane / LivingObjectPane.cpp

- Evidence for: historical docs interpreted dispatcher `this-0xa0` as a LivingObjectPane conversion and grouped local-player helpers near LivingObjectPane source.
- Evidence against: live LivingObjectPane ends at `+0x20c`; all user-list storage is at `+0x13eb20`; current typed target/helper receivers are UserPane; accepted class/file route excludes large offsets.
- Decision: rejected-invalid as current owner. Preserve only as dated historical assumption.

### 3. UserListDialogPane or social/say source

- Evidence for: target constructs UserListDialogPane; helper sits in a mixed range historically named SayModeHelpers.
- Evidence against: dialog is a consumer; target and helper mutate UserPane cache state; all helper callers pass `g_pUserPane`; physical adjacency does not prove source ownership.
- Decision: dependencies only, rejected as owners.

### Proposed new file/grouping, if applicable

- No new source file is proposed for UID0003US. The existing `NexusTK/ui/panels/UserPane.cpp` route is correct.
- `0x005a5010` is sufficiently researched for a future exact `UserPaneOpenUserList` child under the mixed UID0001KO range, but this report does not invent a UID or declare it as additional coverage. UID0001KO should receive the complete behavioral/source-family correction now.

## Source Placement

- Place the outlined target definition in `NexusTK/ui/panels/UserPane.cpp` through UID0000FQ/UID0000P1.
- Keep its declaration once in the complete UserPane H shell. The child target's own H block remains empty to avoid duplicate declaration output.
- Keep opcode `0x36` inline inside the broad `UserPane::OnServerMessage` body. Do not emit a source call to the outlined target at that location.
- Keep copy/cleanup helpers in UserPane.cpp and the trailing fields in UserPane.h.
- Reject `NexusTK/map/LivingObjectPane.cpp`, UserListDialogPane.cpp, SayInputPanes.cpp, and a new standalone target source file.

## Range / Split / Padding / Reclassification Analysis

- Target start/end are exact modeled function boundaries; first item is one-byte entry at `0x005abb20`; final item is `[0x005abc6c,0x005abc6f)`.
- The inline clone is not a separate function and remains inside UID0003VB. It begins at switch case `0x005a7bae` and the next case begins exactly at `0x005a7cd7`.
- UID0003VC retains both selector/jump-table data spans. No table byte is absorbed into UID0003US.
- No UID0003US split, merge, padding child, ignored range, or reclassification is needed.
- UID0001KO remains a mixed non-reconstructable aggregate. Correcting its `0x005a5010` row does not make the broad range a source emitter.

## Negative Evidence Summary

- No current xref, vtable entry, switch target, direct call, or pointer route reaches standalone `0x005abb20`.
- No evidence supports deleting or blanking a complete custom game-code body merely because the compiler also emitted an inline copy.
- No LivingObjectPane layout includes or reaches the `+0x13ebxx` fields.
- No behavior uses `+0x13eb28` as a count or `+0x13eb30` as a durable active state.
- No source body should use `g_pTimerMgr->currentTick`; live type and most current UserPane source use `m_currentTick`.
- No evidence supports UserListDialogPane ownership, SayInputPanes ownership, broad aggregate emission, or an artificial dispatcher call to UID0003US.
- No collision exists for `UserPane_OpenUserList` or the proposed UDT member names in the current IDB.

## IDA Rename / Type / Comment Recommendations

| ID | Entity | Literal current prestate | Proposed action | Safety / collision / protected constraints | Exact expected readback | Supervisor action classification |
| --- | --- | --- | --- | --- | --- | --- |
| I01 | function `0x005abb20` | name `UserPane_HandleUserListPacket`; range `[0x5abb20,0x5abc6f)`; type `bool __thiscall(UserPane *this, const ServerMessageEvent *event)`; address regular `""`, address repeatable `""`, function regular `""`, function repeatable `""`; frame `Block:void *:+0x10`, `var_C:_DWORD:+0x14`, `var_4:_DWORD:+0x1c`, saved `+0x20`, return `+0x24`, `event:const ServerMessageEvent *:+0x28`, residual `arg_4:_DWORD:+0x2c`; zero xrefs; body SHA `07E608...9CE8` | Set function regular comment exactly: `Parses a user-list packet, stages a size-tiered cached copy with a defer-until tick, suppresses restaging during cached replay, and opens UserListDialogPane.` Name/type/frame/body unchanged. | Already-correct name/type; no collision search needed; do not rename locals, remove residual arg slot, create xrefs, or change range/bytes. | Exact name/type/range/frame/xrefs/body preserved; three companion comment channels remain `""`; function regular equals proposed text. | apply |
| I02 | UserPane UDT member `+0x13eb28` | Exposed literal prestate: `int m_deferredUserListCount`, offset `0x13eb28`, size 4, total UserPane size `0x13eb84`. Current `type_inspect`/`type_query` member schemas return only `name,offset,size,type`; `search_structs` has summary metadata; `get_comments` is address/function based; no live bounded tool reads UDT-member comments. Member-comment state is opaque, not asserted empty/absent. | No IDA mutation. Retain `int m_deferredUserListCount` unchanged in IDA. Apply inferred `unsigned int m_userListPacketTick` only to ordinary documentation/formal source during the accepted callback. | No member rename, type change, comment write, UDT rebuild, or operation targeting this member is authorized. This deterministic no-action preserves offset/size, total UDT size, adjacent members, and the unobservable member-comment state without requiring an unsupported prestate assertion. | Supervisor queries `type_inspect(UserPane, include_members=true)` and confirms unchanged `int m_deferredUserListCount` at `+0x13eb28`, size 4, with total UDT size `0x13eb84`; record that no IDA operation targeted this member and do not assert a comment value. | no change recommended |
| I03 | UserPane UDT member `+0x13eb2c` | Exposed literal prestate: `unsigned int m_deferredUserListDeadline`, offset `0x13eb2c`, size 4, total UserPane size `0x13eb84`. Available member-detail schemas omit comments, so member-comment state is opaque and is not asserted empty/absent. | No IDA mutation. Retain `unsigned int m_deferredUserListDeadline` unchanged in IDA. Apply inferred `m_userListDeferUntilTick` only to ordinary documentation/formal source during the accepted callback. | No member rename, type/comment write, UDT rebuild, or operation targeting this member is authorized. The exact current layout and unobservable member-comment state remain untouched. | Supervisor queries `type_inspect(UserPane, include_members=true)` and confirms unchanged `unsigned int m_deferredUserListDeadline` at `+0x13eb2c`, size 4, with unchanged UDT/adjacent layout; record that no IDA operation targeted this member and do not assert a comment value. | no change recommended |
| I04 | UserPane UDT member `+0x13eb30` | Exposed literal prestate: `bool m_deferredUserListActive`, offset `0x13eb30`, size 1, followed by `m_preMovementTicks` at `+0x13eb31`, total UserPane size `0x13eb84`. Available member-detail schemas omit comments, so member-comment state is opaque and is not asserted empty/absent. | No IDA mutation. Retain `bool m_deferredUserListActive` unchanged in IDA. Apply inferred `m_skipNextUserListPacket` only to ordinary documentation/formal source during the accepted callback. | No member rename, type/comment write, UDT rebuild, or operation targeting this member is authorized. This preserves `m_preMovementTicks`, total UDT size, and the unobservable member-comment state. | Supervisor queries `type_inspect(UserPane, include_members=true)` and confirms unchanged `bool m_deferredUserListActive` at `+0x13eb30`, size 1, followed by `m_preMovementTicks +0x13eb31`; record that no IDA operation targeted this member and do not assert a comment value. | no change recommended |
| I05 | function `0x005a5010` | name `sub_5A5010`; range `[0x5a5010,0x5a5091)`; type `void __thiscall(int this)`; all four comment channels `""`; frame `Src:__int16[6]:+0x4`, `var_4:_DWORD:+0x10`, saved `+0x14`, return `+0x18`; three callers; body SHA `E56C59...7D4F`; `UserPane_OpenUserList` collision search empty | Rename `UserPane_OpenUserList`; set type `void __thiscall(UserPane *this)`; set function regular comment exactly: `Requests nation-table data, replays a still-valid cached user-list packet with the skip-next guard set, or sends opcode 0x18 to request a fresh user list.` Leave local/frame unchanged. | All callers pass `g_pUserPane`; no name collision; do not change body/range/frame/stack local because source local spelling/type is not required for safe function identity. | New name/type/comment exact; address regular/repeatable and function repeatable remain `""`; frame, three callers, and bytes unchanged. | apply |
| I06 | function `0x005a9310` | name `UserPane_CopyDeferredUserListPacket`; range `[0x5a9310,0x5a934a)`; type `void __thiscall(UserPane *this, const unsigned __int8 *packetData, unsigned int packetSize)`; address regular `""`, address repeatable `""`, function regular `""`, function repeatable `""`; frame saved `+0x8`, return `+0xc`, `Src:void *:+0x10`, `Size:size_t:+0x14`; six callers | Set function regular comment exactly: `Replaces the owned deferred user-list packet buffer, records its byte size, and copies the complete packet payload.` Name/type/frame unchanged. | Current name/type already correct; no body/range/caller/local mutation. | Proposed function regular exact; other channels blank; range, six callers, and frame unchanged. | apply |
| I07 | function `0x005a89d0` | name `UserPane__ClearDeferredUserListPacket`; range `[0x5a89d0,0x5a8a01)`; type `void __thiscall(UserPane *this)`; address regular `""`, address repeatable `""`, function regular `Frees the deferred user-list packet and clears only pointer, count, and deadline. Recorded size and active flag are intentionally preserved.`, function repeatable `""`; frame only return `+0x4`; one caller | Replace function regular with exactly: `Frees the deferred user-list packet and clears only the pointer, packet tick, and defer-until tick. Recorded size and skip-next flag are intentionally preserved.` | Name/type/body/range/caller already correct; do not clear size/flag or change frame. | New function regular exact; companion channels blank; range, one caller, frame, and body unchanged. | apply |
| I08 | function `0x005a76c0` | name `sub_5A76C0`; range `[0x5a76c0,0x5a82bd)`; current IDA declaration `char __fastcall(UserPane *, int, WCHAR *)`; address regular `""`, address repeatable `""`, function regular `""`, function repeatable `""`; literal frame prestate: `Block:void *:+0x10`, `var_6B4:UserPane *:+0x14`, `var_6AD:_BYTE:+0x1b`, `var_6AC:UserPane *:+0x1c`, `var_6A8:LPWSTR:+0x20`, `var_6A1:_BYTE:+0x27`, `outBounds:RectBounds:+0x28`, `Source:wchar_t[256]:+0x38`, `WideCharStr:wchar_t[256]:+0x238`, `var_290:WCHAR:+0x438`, `MultiByteStr:CHAR[256]:+0x538`, `destination:CHAR[128]:+0x638`, `var_10:_DWORD:+0x6b8`, `var_C:_DWORD:+0x6bc`, `var_4:_DWORD:+0x6c4`, saved `+0x6c8`, return `+0x6cc`, `arg_0:_DWORD:+0x6d0`, `arg_4:_DWORD:+0x6d4`; sole data xref `0x62efa0`; body uses adjusted EventHandler receiver | Set function regular comment exactly: `UserPane EventHandler dispatcher; opcode 0x36 contains the live inline user-list staging/dialog-open body equivalent to retained UserPane_HandleUserListPacket.` Do not rename/type/frame in this target transaction. | Broad dispatcher prototype is unsafe to rewrite from one case because adjusted receiver and residual ABI slot require whole-function analysis. Protect vtable cell, range, tables, every listed frame member, and body. | Current name/declaration/range/literal frame/xref remain; function regular equals exact text; other comment channels blank. | apply |

- Protected dependencies outside the action table: `g_pTimerMgr` at `0x0067ab80` remains `TimerMgr *`; `g_pUserListDialogPane` at `0x0069b4e0` remains `UserListDialogPane *`; TimerMgr `m_currentTick +0x18` remains unsigned; LivingObjectPane remains `0x20c`; UserPane remains `0x13eb84`; vtable cell `0x0062efa0` remains pointer `0x005a76c0`.
- Deterministic I02-I04 Gate 2B closure: before any unrelated accepted IDA action, call `type_inspect` with `database=<active session>` and `queries={name:"UserPane",include_members:true,max_members:2000}`; record the exact three exposed records above; issue no IDA call targeting those members or rebuilding UserPane; after the unrelated actions, repeat that same query and require the three records and total UDT size to remain unchanged. This is a no-mutation verification procedure, not permission to infer or overwrite the hidden comment channel.
- No IDA action may create a function at inline case `0x005a7bae`, split the dispatcher, change table items, create a call to the standalone target, or alter bytes.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; the target is complete custom game code with exact behavior and a valid owner/header route.
- CPP block disposition: replace the target's formal CPP body with exactly:

```cpp
bool UserPane::HandleUserListPacket(const ServerMessageEvent *event)
{
    if (m_skipNextUserListPacket)
    {
        m_skipNextUserListPacket = false;
    }
    else
    {
        const unsigned char *packet = event->packetData;
        const size_t packetSize = event->packetSize;
        const unsigned short entryCount =
            PacketBufferReadUInt16BE(packet + 3);
        const unsigned int currentTick = g_pTimerMgr->m_currentTick;

        m_userListPacketTick = currentTick;
        if (entryCount < 100)
        {
            m_userListDeferUntilTick = currentTick;
        }
        else if (entryCount < 300)
        {
            m_userListDeferUntilTick = currentTick + 30000;
            CopyDeferredUserListPacket(packet, packetSize);
        }
        else if (entryCount < 500)
        {
            m_userListDeferUntilTick = currentTick + 60000;
            CopyDeferredUserListPacket(packet, packetSize);
        }
        else if (entryCount < 800)
        {
            m_userListDeferUntilTick = currentTick + 90000;
            CopyDeferredUserListPacket(packet, packetSize);
        }
        else
        {
            m_userListDeferUntilTick = currentTick + 150000;
            free(m_deferredUserListPacket);
            m_deferredUserListPacket =
                static_cast<unsigned char *>(malloc(packetSize));
            m_deferredUserListPacketSize = packetSize;
            memmove(m_deferredUserListPacket, packet, packetSize);
        }
    }

    if (g_pUserListDialogPane == NULL)
        new UserListDialogPane(event->packetData);
    return true;
}
```

- H block disposition: leave the target `RECONSTRUCTION_H CODE` block empty. UID0000FQ already contains `bool HandleUserListPacket(const ServerMessageEvent *event);` in the complete UserPane class shell; a second child declaration would duplicate it.
- Exact behavior: all branches, thresholds, delays, cache ownership, skip behavior, singleton construction, and true return match the machine body.
- Human source shape: ordinary locals, member names, control flow, CRT calls, and `NULL` fit the project's established mid-2000s style and avoid raw offsets/decompiler labels.
- Third-party import directive: not applicable.

## Final Recommendation

- Accept all C001-C079 claims for ordinary callback/supervisor handoff.
- Raise UID0003US to `94/95` and retain owner/emitter UID0000FQ, reconstructable true, blank optional position, `Nested:8`.
- Apply exact target CPP and keep target H blank.
- Synchronize the three UserPane field identities across all named ordinary docs and current formal sources.
- Preserve both binary source forms: standalone UID0003US and inline UID0003VB opcode-`0x36` case.
- Apply I01 and I05-I08 only through supervisor Gate 2B. I02-I04 are deterministic no-change dispositions: leave the three IDA UDT members untouched and verify their exposed records remain unchanged, while applying the evidence-backed source-facing names/types only to ordinary documentation/formal source. B010 must not mutate IDA.
- Apply M01, M04, M06, M07, and M09 through the supervisor; M02/M03/M05/M08/M10-M13 are verified no-ops at this checkpoint.
- Fully document `0x005a5010` as UserPane user-list opener support. A separately assigned exact-child report may later register/employ its formal source, but no semantic investigation remains open and UID0003US does not depend on that registration.

## Recommended Target Doc Changes

- Target: `by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md`.
- Metadata: `COMPLETION:94`, `CONFIDENCE:95`; retain owner/emitter/reconstructable/position/Nested.
- Formal CPP: exact block above. Formal H: blank with explicit existing-class-declaration rationale.
- Current prose: add exact binary, inline-clone, field, helper, ownership, liveness, source-shape, score, and generated evidence from this report.
- History: retain but clearly label every LivingObjectPane, raw name/type, blank/no-code, and UserPane-dispatcher-only statement as superseded.
- Remove current contradictions that say the formal body remains blank or the best source name is LivingObjectPane-qualified.

## Recommended Support Doc Changes

| Path / UID | Exact callback scope |
| --- | --- |
| `by-class/UserPane.md` / 0000FQ | Replace three field declarations/names; preserve offsets/size; synchronize cleanup and opcode-0x36 history; keep method declaration once. |
| `by-file/UserPane.md` / 0000P1 | Add final target/source-shape and trailing-state semantics; synchronize cleanup/key-event/helper source. |
| `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` / 0003VB | Replace opcode-0x36 LivingObjectPane field/receiver wording with UserPane complete-object state; retain inline/no-direct-call decision. |
| `by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md` / 0003UK | Keep formal pointer/size code; synchronize caller-side tick/defer/skip names and historical ownership. |
| `by-memory/0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket.md` / 0004TX | Replace formal tick/defer names, field table, summary, preserved-field wording, and history. |
| `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md` / 0003V9 | Replace only user-list inline cache field names in formal/prose; preserve all unrelated key behavior. |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` / 0001KM | Synchronize UID0003US/UID0003UK rows, field names, and ownership history; keep aggregate non-emitting. |
| `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` / 0001KO | Replace `0x005a5010` row/evidence with complete UserPane user-list opener behavior, callers, name direction, and exclusion from SayInputPanes emission. |
| `by-class/LivingObjectPane.md` / 00007B | Move any current `+0x13ebxx` ownership claims into rejected adjusted-local-player history; preserve exact 0x20c class. |
| `by-file/LivingObjectPane.md` / 0000KU | Preserve explicit UserPane-large-offset exclusion and historicalize stale user-list source ownership. |
| `by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md` / 0003UD | Replace all source-facing `g_pTimerMgr->currentTick` spellings with `m_currentTick`; behavior/score unchanged. |
| `by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md` / 0003UI | Replace all source-facing `g_pTimerMgr->currentTick` spellings with `m_currentTick`; behavior/score unchanged. |
| `by-global/g_pTimerMgr.md` / 0000SI | Inspect/no change; dependency already source-facing. |
| `by-global/g_pUserListDialogPane.md` / 0003EI | Inspect/no change; singleton already source-facing. |

Deterministic formal-source callback payloads:

- UID0000FQ `RECONSTRUCTION_H`: replace exact declaration `int m_deferredUserListCount;` with `unsigned int m_userListPacketTick;`; replace `unsigned int m_deferredUserListDeadline;` with `unsigned int m_userListDeferUntilTick;`; replace `bool m_deferredUserListActive;` with `bool m_skipNextUserListPacket;`. Preserve the exact offsets, neighboring declarations, `sizeof(UserPane)==0x13eb84` guard, existing `HandleUserListPacket` declaration, and `[[CHILDREN]]` placement.
- UID0003V9 `RECONSTRUCTION_CPP`: replace every user-list-cache occurrence of `m_deferredUserListDeadline` with `m_userListDeferUntilTick` and `m_deferredUserListActive` with `m_skipNextUserListPacket`; no other key/text-event source token changes.
- UID0004TX `RECONSTRUCTION_CPP`: replace `m_deferredUserListCount = 0;` with `m_userListPacketTick = 0;` and `m_deferredUserListDeadline = 0;` with `m_userListDeferUntilTick = 0;`; preserve the free/null sequence and the absence of stores to packet size and skip-next flag.
- UID0003UD and UID0003UI `RECONSTRUCTION_CPP`: replace only exact source token `g_pTimerMgr->currentTick` with `g_pTimerMgr->m_currentTick`; preserve all other source.
- UID0003UK formal CPP and H remain byte-for-byte unchanged; only caller/field prose and history are synchronized.
- UID0003VB, UID0001KM, UID0001KO, UID00007B, UID0000P1, and UID0000KU receive prose/history/source-family synchronization only; no formal CPP/H payload is accepted for those destinations in this callback.

## Score And Metadata Recommendation

- Pre-callback UID0003US state: `88/88`, owner/emitter UID0000FQ, reconstructable true, blank position, `Nested:8`, nonblank CPP, blank H.
- Current/applied UID0003US state: `94/95`; owner/emitter UID0000FQ, reconstructable true, blank position, `Nested:8`, nonblank exact CPP, and blank H remain unchanged.
- Reason not lower: complete exact body; typed current IDA; exact range/hash/frame; complete control flow and dependencies; exact semantic inline clone and switch route; proven UserPane layout; source-legal class/file route; exact formal CPP/H; all contradictory ownership/no-code residue identified for callback.
- Reason not higher: no original symbols/PDB; the lexical field/local names and retained outlined-versus-inline compiler policy are high-probability inference; standalone entry has zero direct route; ServerMessageEvent remains incomplete in the live type catalog. These do not block source, behavior, owner, or emission.
- Score-improvement audit: ownership blocker closed by `0x20c`/`0x13eb84`; no-code blocker closed by retained-source policy plus exact clone; field blocker closed by 0x5a5010 replay semantics; TimerMgr spelling closed by live UDT; header blocker closed by existing class declaration; accepted ordinary support contradictions were corrected and passed the recorded C001-C051 audit.

## Open Questions With Attempted Resolution

- Why does a zero-route outlined body exist? Checked current xrefs, tables, bytes, inline clone, old PE scans, compiler-context differences, and current source family. Best resolution: a normal member was emitted out of line while the live dispatcher call was inlined; the linker retained the body. This is sufficient for source reconstruction and does not require inventing a route.
- Are the exact original field spellings proven? No symbol proves spelling. Usage and project history make `m_userListPacketTick`, `m_userListDeferUntilTick`, and `m_skipNextUserListPacket` the most realistic consistent names. Raw/stale names are less accurate and must not remain merely because symbol proof is unavailable.
- Is `0x005a5010` say-mode code? No. Exact body, callers, receiver, opcode, and cache fields resolve it as a UserPane user-list opener/request helper. Its exact future child UID is an allocation/lifecycle matter, not unresolved research.
- Should the dispatcher call UID0003US in reconstructed source? No. Exact live machine code contains the inline body, so forcing a call changes the source/compiler shape and likely binary layout.
- Should target H contain a declaration? No. The declaration already exists in the complete class H and child duplication is invalid.
- Remaining unresolved target blockers: none. Residual lexical/compiler-retention uncertainty is explicitly reflected in the 94/95 cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current manual identities at `2026-07-31T10:54:40-04:00`: by-memory SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, `2,134,111` bytes / `4,803` lines; by-class SHA256 `0A2F8F0BF6EF28ECB9633E504A0C2B59BCBF022B31201B33A1AAAB319B15D272`, `275,060` bytes / `625` lines; by-file SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`, `166,582` bytes / `319` lines. These are dated anchors and must be reread before supervisor application.
- M01 replace current by-memory row 3854 exactly with:

```text
        - [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) 0x005abb20-0x005abc6f | retained UserPane member | UserPaneHandleUserListPacket : reconstructable : 94% : very-strong : Source-ready retained UserPane user-list packet member with exact typed body, tiered cache/defer behavior, skip-next replay guard, lazy dialog creation, zero standalone xrefs, and an exact live opcode-0x36 inline clone preserved as a separate dispatcher source form.
```

- M02 no change: UID0003VB current row 3830 already accurately describes the exact dispatcher, inline/retained distinctions, and bounded dependency ownership.
- M03 no change: UID0003UK current row 3842 already accurately describes pointer/size copy behavior and six callers.
- M04 replace current UID0004TX row 3841 exactly with:

```text
        - [UID:0004TX][0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket](by-memory/0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket.md) 0x005a89d0-0x005a8a01 | class method | UserPaneClearDeferredUserListPacket : reconstructable : 92% : very-strong : Source-ready UserPane deferred-list cleanup that frees and clears pointer, packet tick, and defer-until tick while deliberately preserving size and skip-next flag; sole UID0003TY caller and exact field-store negatives.
```

- M05 no change: UID0001KM row 3812 is already a non-emitting UserPane source-family index and need not enumerate every field rename.
- M06 replace current UID0001KO row 3869 exactly with:

```text
    - [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md) 0x005a4b60-0x005a5791 | non-emitting mixed helper index | SayModeHelpers : not_reconstructable : 86% : strong : Mixed say-mode and adjacent UI action helper neighborhood with nineteen modeled functions, exact source-ready UID0002RX say-mode child, exact UserPane-owned UID0004US EnsureNormalBulletinSession child, fully characterized UserPane user-list opener at 0x005a5010 excluded from say ownership, boundary padding, caller/source-family distinctions, and no synthetic aggregate source body.
```

- M07 in current by-class row 589, replace exact token text `pointer, count, and deadline while preserving size, active state` with `pointer, packet tick, and defer-until tick while preserving size and skip-next state`. Keep the rest of the long row byte-for-byte.
- M08 no change: UID00007B by-class row 287 already describes an exact `0x20c` LivingObjectPane and contains no active `+0x13ebxx` ownership claim.
- M09 in current by-file row 300, replace exact token text `pointer/count/deadline only, preserves size and active state` with `pointer/packet tick/defer-until tick only, preserves size and skip-next state`. Keep the rest of the row byte-for-byte.
- M10 no change: UID0000KU by-file row 147 already explicitly excludes UserPane-only large-offset functions.
- M11 no change: UID0003V9 row 3828 remains behaviorally complete after lexical field synchronization.
- M12 no change: UID0003UD row 3826 does not encode the stale TimerMgr member spelling.
- M13 no change: UID0003UI row 3836 does not encode the stale TimerMgr member spelling.
- B010 must not apply these manual operations. The supervisor must reread the moving files, apply only still-applicable operations, preserve additive changes from other reports, and validate coverage serially.
- No manual edit is proposed for validator-owned `auto-generated/-ag-research-tracker.md`; its score row advances through normal validator generation.

## Follow-Up Actions

- Supervisor Gate 1: audit this exact report artifact against all literal sections, C001-C079, I01-I08, M01-M13, formal CPP/H, current identities, and the sole terminal marker.
- Completed same-agent callback after Gate 1: every accepted ordinary target/support change was applied at report-level detail with short edit leases and serial scoped validators using `--no-generated-refresh`; manual coverage/generated files and IDA were not edited by B010.
- Supervisor Gate 2B: apply/read back/save I01 and I05-I08 with backup/catalog evidence and protected layout/body constraints; close I02-I04 as no-change rows by running the exact `type_inspect(UserPane)` procedure, issuing no member/UDT mutation, and confirming the exposed member records remain unchanged without asserting hidden comment values.
- Same-agent post-IDA callback: reconcile exact saved/readback state into report and affected ordinary docs.
- Supervisor closure: apply applicable M01/M04/M06/M07/M09, verify no-op rows, refresh generated output, confirm target CPP/H topology and tracker score, then run final gates/lifecycle.
- Future separately assigned target: register an exact `0x005a5010-0x005a5091.UserPaneOpenUserList` child only under a dedicated assignment/accepted expansion; behavior and name direction are already resolved here, so no repeat broad investigation is required.

## Confidence

- Recommendation confidence: very strong (`95`) for owner/source/body/field roles/duplicate relation; strong for inferred exact lexical spellings.
- Score confidence: strong. `94/95` reflects complete reconstructability while preserving honest lexical/compiler-retention uncertainty.
- Remaining uncertainty: original symbol spellings and why the linker retained the unreferenced outline. Neither affects exact behavior or source legality.

## Validator Results

- Scoped command form: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh`, run serially from `source-3/project-documentation`.
- Final successful command inventory (`exit 0`, `ok: 1`, generated refresh skipped for every command):
  - `000000020548` UID0003US target.
  - `000000020549` by-class/UserPane.
  - `000000020550` by-file/UserPane initial callback validation; `000000020561` is the final validation after the claim-audit timer-token repair.
  - `000000020551` UID0003VB; `000000020552` UID0003UK; `000000020553` UID0004TX; `000000020554` UID0003V9.
  - `000000020555` UID0001KM; `000000020556` UID0001KO.
  - `000000020557` by-class/LivingObjectPane; `000000020558` by-file/LivingObjectPane.
  - `000000020559` UID0003UD; `000000020560` UID0003UI.
- The validators reported existing missing-reference warnings on several broad support pages, but every scoped result remained `ok: 1`; no new target-local validation failure was reported.
- `--no-generated-refresh` suppressed generated report/CPP/H refresh. The scoped validator still reported its normal validator-owned `projected_stats_update` bookkeeping on each call; B010 made no manual generated, tracker, stats, coverage, audit, catalog, or lifecycle edit.
- Post-validator ordinary destination audit: C001-C051 passed `51/51`. MCP remained read-only only; no IDA mutation/save or process-control action occurred.

## Changed Files

- Modified and validator-final ordinary docs:
  - `by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md`: SHA256 `4DAE719E3134A723559CC93AEE87DD2F8A2E4D39BB85920AB71402B41AD19E0F`, `20,776` bytes / `177` lines.
  - `by-class/UserPane.md`: `9C325FBF0910ACD3A757EEA560CC9DC7CE6AE732951983A956837EBD4D14A33D`, `114,100` / `823`.
  - `by-file/UserPane.md`: `E3DE1368E0465F4C50192EED3DBF73BA3112832AA304BEE6BF61059C6CE83839`, `124,171` / `519`.
  - `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`: `C224A9CFE0856E7560634EF5E7D06070026A4152E0E5AC641B2D9F01F053B821`, `38,067` / `197`.
  - `by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md`: `4AACD2FDE779D5E12EE3AACFD3BB67DC915F79A662533774AB1CFC41A44FAB57`, `14,486` / `127`.
  - `by-memory/0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket.md`: `13CB510890B503EF110E598FACF7B56E87A1DF8EA2F16DB0518610CDB7F5F0C6`, `5,661` / `80`.
  - `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md`: `09FE0D23A6E754349C919DED585A00C94ECAE8693A590C294F70326C6F929073`, `37,597` / `799`.
  - `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md`: `E96F955DA7D0CF02569ACF4BE9A6BBD2A1B0E5F42896C630393F83B98130C06C`, `145,277` / `623`.
  - `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`: `05AAE1C8100A6EFCF2FBFE566AB425E11CAEDC6B6680ABB0349B6F404038B120`, `20,515` / `149`.
  - `by-class/LivingObjectPane.md`: `E9C447CF0ED7B2A65AF79EE7DE47C88CED70AA1C2079CCFFDD6AB027050A2C5E`, `132,339` / `686`.
  - `by-file/LivingObjectPane.md`: `FF1A1EC131287FDCF250FE0F65C6741A53F59032F5F3B5138D332C0F0C7CA120`, `122,844` / `450`.
  - `by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md`: `9160B0F4147049BE80976C2E63737680C31F2FBE5281E30CE3ED371F77A6C806`, `21,035` / `204`.
  - `by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md`: `FA853201479175DFA073E7405622634228E3FDB44E74B635305F5175248952B4`, `12,468` / `132`.
- Read-only already-present support verified without edits: `by-global/g_pTimerMgr.md` and `by-global/g_pUserListDialogPane.md`.
- This report was reconciled in place after implementation. All target/support/report leases used by B010 were released; the shared current lease report had no remaining B010 lease for these files at callback close.
- No manual coverage, generated, tracker, audit, catalog, lifecycle, goal, or IDA file was edited by B010. Report execution/archive status remains supervisor-owned; B010 did not run, probe, or simulate `execute_report`.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact report SHA256 `2F478108A7A9B455FC84BA79DFB0888B05ABB129D2199DCD0F9EC68AA2CB34D7` before implementation.
- [x] Target/support docs to update are enumerated path-by-path in Recommended Target/Support Doc Changes.
- [x] No additional UID is declared; `0x005a5010` is support evidence only and is explicitly not counted as direct additional report coverage.
- [x] Current target state and actual successful post-recovery evidence are recorded.
- [x] C001-C079 are contiguous, atomic by destination/action, and use only allowed action vocabulary.
- [x] Metadata/score change to `94/95` is justified with reasons not higher/lower.
- [x] Every prior owner/liveness/no-code/field/header score blocker was researched to a concrete resolution.
- [x] Owner/emitter/reconstructable state is explicitly retained and LivingObjectPane ownership rejected.
- [x] Range/inline-duplicate/table boundaries and no-split disposition are exact.
- [x] I01/I05-I08 contain literal complete prestates; I02-I04 contain literal exposed name/type/offset/size prestates, explicit proof that the member-comment channel is unavailable, deterministic no-mutation dispositions, and exact unchanged-state supervisor query/readback procedures.
- [ ] Supervisor Gate 2B must apply/read back/save I01 and I05-I08; it must close I02-I04 by issuing no member/UDT mutation and verifying the exact exposed records remain unchanged. B010 has not mutated IDA.
- [x] Exact target formal CPP and blank-H proof are supplied.
- [x] Third-party import is explicitly not applicable.
- [x] Exact target/support facts are preserved at report-level detail rather than summarized away.
- [x] Historical/stale assumptions and negative evidence are retained and classified.
- [x] Wave2/Wave3 references were rejected as stale authority.
- [x] Open questions were attempted to resolution; none remains a target blocker.
- [x] Callback validator scope is identified; no validator was run during report-only work.
- [x] M01-M13 give exact supervisor manual dispositions; generated/tracker changes remain validator-owned.

Implementation callback pass:
- [x] Supervisor Gate 1 accepted the exact pre-callback report artifact identified above.
- [x] All accepted target/support ordinary changes were incorporated without detail loss; the 35 absent ordinary claims were applied and the 18 already-present ordinary claims were preserved.
- [x] C001-C079 were reconciled claim-by-claim: C001-C051 ordinary destinations passed `51/51`; IDA, manual-coverage, and generated-closure rows retain accurate `proposed`, `already-present`, or no-mutation states.
- [x] Metadata/score/formal CPP/H changes were applied exactly.
- [x] Historical assumptions were preserved and current contradictions removed.
- [x] Scoped ordinary validators ran serially with generated refresh disabled and exact IDs/results recorded.
- [ ] Supervisor-owned IDA state reconciled after Gate 2B.
- [ ] Applicable manual coverage operations applied/verified by supervisor.
- [ ] Supervisor-generated CPP/H/tracker closure verified against expected topology.
- [ ] Supervisor report execution/archive lifecycle is complete and recorded by validator-owned status/history metadata.
- [x] Current-state, documentation-status, score, and checklist wording is post-callback and lifecycle-neutral; it does not assert a current review stage or directory, and execution/archive truth remains external.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000020598","destination_path":"executed-b-agent-research/B010/0003US-UserPaneHandleUserListPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0003US-UserPaneHandleUserListPacket-source-quality.md","timestamp":"2026-08-01T07:36:13-04:00","uid":"0003US"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
