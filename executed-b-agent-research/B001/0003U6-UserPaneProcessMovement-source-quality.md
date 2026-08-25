** TARGET-REPORT-UID:0003U6 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003U6 UserPaneProcessMovement Ownership / Split Research


## Finalized Report / Current Recommendation

- Current implemented recommendation: `UserPane::ProcessMovement(unsigned char)` is a source-authored `UserPane` member under class owner/emitter UID0000FQ and source root UID0000P1 at corrected physical range `0x005a2e00-0x005a36f0`; the complete formal body in this report is applied exactly.
- Final disposition: one source method, no source child split. The IDA-modeled code ends at `0x005a36de`; the referenced four-entry direction switch table and its alignment bytes occupy `0x005a36de-0x005a36f0` and must remain attached to this method. The successor `UserPane::InitializeWalkAnimation` starts at `0x005a36f0`.
- Applied callback state: UID-preserving validator-aware rename/range correction; target score `86/88 -> 92/94`; owner/emitter UID0000FQ, reconstructable true, and blank emitter position retained; `Nested:8 -> Nested:0`; nine complete destination-specific managed C++ blocks applied; bounded support pages synchronized. B001 did not edit manual coverage; the supervisor later applied and validated the no-loss coverage synchronization through commands `000000012665` through `000000012668`.
- Confidence: very strong for boundary, ABI, receiver class, callers, control flow, packet bytes, field offsets, helper identities, source route, and compiler/data split; strong for inferred private identifiers and exact historical helper spellings.

## Supporting Research

- Current active B001-B005 report roots were searched with `UID0003U6`, `0x005a2e00`, `sub_5A2E00`, `UserPaneProcessMovement`, `LivingObjectPaneProcessMovement`, `ProcessMovement`, retained packet-helper names, and UserPane/MapPane/Event source-family terms. No active report directly covers this target.
- Central executed report matches opened and classified:
  - `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md`: direct range/caller lead; its old LivingObjectPane ownership is superseded by the later complete UserPane declaration and the current large-offset receiver evidence.
  - `executed-b-agent-research/B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`: direct embedded Destination 29 support that moved the page to UserPane, but retained `86/88`, an incomplete body, stale helper names, and no standalone target reanalysis.
  - `executed-b-agent-research/B001/0003Z4-LivingObjectPaneLinkedObjectSetupHelpers-source-quality.md`: direct inherited-field/global synchronization support; it is not a target-complete movement audit.
  - `executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md` and `executed-b-agent-research/B003/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`: direct retained-helper leads; current raw-byte reanalysis corrects their status-gate, status-byte, argument-order, and opcode-`0x32` tail conclusions.
  - `executed-b-agent-research/B014/000428-MapPaneGetAdjacentVisibleTileBounds-source-quality.md`, `B005/000425-MapPaneCheckMovementCollision-source-quality.md`, `B007/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`, and `B008/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`: direct callee/support evidence independently revalidated here.
  - `executed-b-agent-research/B004/0001KL-UserPane-source-quality.md`, `B001/00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`, and `B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`: class/layout/source-family leads, not substitutes for this target.
- `tools/leaser/Agents/Older-Research/**` and `tools/leaser/Agents/SpecialReports/**` were explicitly searched with the same target/address/name/source-family terms and returned no matches. No legacy per-agent `research/executed` archive directory exists in the current tree. The central executed root is therefore the only matching archived/executed source.
- Explicit conclusion: no prior report has exact `TARGET-REPORT-UID:0003U6` or independently closes this exact page. Prior direct coverage is embedded support in broader reports; all other matches are caller, callee, adjacency, layout, or historical-ownership leads.

## Target

- Target UID: `0003U6`.
- Historical pre-callback target path: `by-memory/0x005a2e00-0x005a36de.UserPaneProcessMovement.md`.
- Current implemented path: `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md`; validator command `000000012541` preserved UID0003U6 and updated its mapping/reverse links.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; the queue row had zero registered exact reports when assigned.
- Current callback classification: accepted implementation is complete, and supervisor-owned post-callback commands `000000012669` through `000000012692` freshly passed all 24 ordinary destinations with final waited generated verification. The supervisor still owns report audit/lifecycle disposition; no B001 implementation item remains.
- Current scores and parent state: target `92/94`, owner/emitter UID0000FQ, reconstructable true, blank position, `Nested:0`; class UID0000FQ is `92/93`; source file UID0000P1 is `91/92`; non-emitting source-family index UID0001KM is `90/92`.

## Current Target State

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000FQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FQ`, blank position, and `Nested:0`.
- Applied owner/emitter/reconstructable state: UserPane is current throughout target/support current sections. Direct offsets above the `0x20c` LivingObjectPane boundary, exact class declaration, and caller set establish the route; former LivingObjectPane statements remain only under explicit historical headings.
- Applied C++/emitter state: exact Destination 1 replaces the inaccurate body. It uses `sendWaypointPacket`, both success routes, `AllowsMovementStatusTag`, display-status byte, external free `DirectionToTileOffset`, free UID0004QZ copied-event helper, exact opcode `0x32` zero tail, and value-first PacketBuffer ABI.
- Closed blockers: exact range/table ownership, direction modes, viewport fields, status byte/tag, writer ABI, Event child route, retained helper liveness, packet/event layouts, effect-list pointer slots, MapPoint declaration, source owners, and generated integration are all implemented and validated below.
- Related docs checked: UID0001KM, UID0000FQ, UID0000P1, UID00007B, UID00007Q, UID0000L3, UID00009R, UID0003UX, UID0003UY, UID0003XP, UID00041W, UID000425, UID000426, UID000428, UID000232, UID00023H, UID0001U8, List, ObjectStatusBlob, TimerMgr, Config, PacketBuffer, Event, EventDispatcher, and relevant globals.
- Current artifact/lifecycle status: the accepted callback implementation is complete; all leases are released and no B001 work remains. B001 ran only the scoped validators and waited refresh recorded below. B001 performed no execute, report lifecycle, probe/count, move, archive, IDA mutation, manual coverage edit, or generated-file edit. Report path/count/execution/archive state is external supervisor/validator-owned.

## Executive Recommendation

- Direct owner: class UID0000FQ `UserPane`; emitter route UID0000FQ -> UID0000P1 `NexusTK/ui/panels/UserPane.cpp`.
- Target state applied: `92/94`, reconstructable true, owner/emitter unchanged, blank position, `Nested:0`, corrected path ending `0x005a36f0`, complete formal method body.
- Split disposition: no source child. Attach `0x005a36de-0x005a36f0` as compiler switch support to the target; do not add it to ignored padding and do not merge successor UID0003U7.
- Retained helpers applied: UID0003UX and UID0003UY remain source-bearing retained UserPane members despite no inbound route to their raw starts. Their exact bodies are corrected, emitted once, and preserved as live inline-equivalent source without target-page duplication.
- Registered exact child: UID0004QZ `by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md`, issued by command `000000012543`, is `92/94` under Event.cpp and linked only after registration.
- Registered shared type: UID0004R0 `by-type/by-struct/MapPoint.md`, issued by command `000000012547`, is `92/93`, owner/emitter UID0000L3, position 5, exact `{ row, column }`; UID0002RW is synchronized to `90/92` without an alias union.

## Supervisor Active Recheck

- Historical phase: the goal first assigned UID0003U6 as standalone report-only research and forbade ordinary edits before exact-artifact Gate 1.
- Gate 1 passed exact report SHA `2157FABB3C75F1CD2F17B864AE0BA9AE0CEE632AFC103CBDF5933FC6F3586BBC`; the supervisor then authorized C3U6-001 through C3U6-064 and Destinations 1-9.
- Current recheck: every accepted claim is terminally mapped, every source-bearing destination has its exact block, and supervisor-owned commands `000000012669` through `000000012692` freshly passed all 24 ordinary pages. At the final waited target checkpoint, command `000000012692` at `2026-07-15T01:41:46-04:00` was present in all four relevant generated headers and all accepted assertions passed. Later external refreshes culminated in command `000000012699` on all four generated files; the exact checkpoint/current distinction and repeated accepted assertions are recorded below, and no UID0003U6 callback blocker remains.

## Inference Research Guidance Check

- `by-structure.md` requires exact by-memory boundaries, direct semantic ownership, source versus compiler/data classification, and complete formal C++ only after the owner/emitter/score gate clears. The recommendation follows those rules.
- Existing generated source, old LivingObjectPane labels, old Wave2/Wave3 aliases, broad aggregate reports, and decompiler names were treated as leads, not authority.
- Direct IDA facts are separated below from documentation evidence and inferred source-facing names. Original private spellings remain lexical confidence caps rather than behavior blockers.
- Wave2/Wave3 mentions were encountered in older docs. They were ignored as stale provenance under the current workflow and were not used to prove any recommendation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and decision | Evidence class |
| --- | --- | --- |
| UserPane versus LivingObjectPane | UserPane is authoritative. The receiver uses fields at `+0x1340f8`, `+0x1340fe/+0x1340ff`, `+0x13ead8..+0x13eaec`, and `+0x13eb14..+0x13eb1c`, far beyond the exact LivingObjectPane size `0x20c`. | Direct binary plus current class layout. |
| Method name | Retain `ProcessMovement`; all ten callers supply direction values `0..3`, and the body performs the complete local movement/prediction/send path. | Descriptive inference supported by callers and behavior. |
| Direction mode | `m_playerSettingsState[3] == 1` performs signed `(direction + 2) % 4`; other nonzero values use `g_pTimerMgr->m_currentTick & 3`; zero preserves input. Do not normalize the first expression to `& 3` in source. | Direct instruction/decompile behavior. |
| Facing-only branch | A changed direction sends `{0x11,direction}`, calls `SetFacing`, and returns. Existing file-local `SendDirectionPacket` is the plausible source helper whose body is inlined here. | Direct packet writes/callee plus retained helper. |
| Asset effect cleanup | Only `g_useEpfAssets == 1` requests effect 201, copies its descriptor, and scans the global `g_pUserPane` secondary list before primary. Each reverse scan dereferences a `List` pointer slot, matches `m_effectId`, tests `IsLooping`, and source-deletes the first match. | Direct globals, List ABI, descriptor offsets, scalar-delete call. |
| Viewport predicate | Rename the current misleading `movementBlocked` concept to `sendWaypointPacket`. True selects opcode `0x06` after positive collision; false selects opcode `0x32`. Collision result zero, not this flag, selects blocked opcode `0x69`. | Direct CFG and branch destinations. |
| Threshold fields | Rename `+0x13eae0/+e4/+e8/+ec` to `m_viewportHalfColumns`, `m_viewportHalfRows`, `m_viewportRemainingColumns`, `m_viewportRemainingRows`. Constructor math uses visible columns/rows and the switch uses each matching axis. | Constructor disassembly plus target switch. |
| Direction helper linkage | `DirectionToTileOffset` is a free external MapPane.cpp helper, not a MapPane member and not file-static: 32 direct callers span source families including UserPane. | Direct xrefs and no receiver. |
| Object position accessor | `ObjectPane::GetMapPosition` writes row/mapY at output `+0`, column/mapX at `+4`, returns the output pointer, and is source-ready. | Exact `0x1b` leaf body and class layout. |
| MapPoint declaration | Use one exact eight-byte `MapPoint { int row; int column; }` support type through MapPane.cpp. Offset 0 is consistently row/Y and offset 4 is column/X. Historical `x/y` field spellings on UID0002RW are synchronized rather than preserved as a second layout. | Direct output stores and converging MapPane/ObjectPane consumers. |
| Movement collision | Preserve tri-state: negative silently returns, zero sends blocked `0x69`, positive sends the selected success packet. | Direct return comparisons. |
| Status tag | Use `MapPane::AllowsMovementStatusTag()` plus `g_pConfig->m_sendMovementStatusBit`. The high bit applies to movement-history tag and status-event direction, not collision. | UID000426 body and target/raw helpers. |
| Packet byte 3 | Use inherited `m_objectStatus.m_displayStatusByte` at ObjectStatusBlob `+0x28`; `m_movementSpeed` is not a declared or observed field. | Direct offset plus ObjectStatusBlob declaration. |
| Opcode `0x06` helper | Retained UID0003UX is source-authored no-route code and exact inline equivalent. Correct status-gate/status-byte/MapPoint fields and value-first append ABI; keep no-route history. | Raw body plus live target. |
| Opcode `0x32` helper | Retained UID0003UY is source-authored no-route code and exact inline equivalent. `WriteUInt16BE(0x32, packet+8)` followed by `packet[9]=0` makes sent byte 8 zero; the historical "trailing sent 0x32" claim is false. | Raw disassembly and send length 9. |
| Movement history | The 16-byte ring record is `{active,pad,tileY,tileX,direction,pad}`; index increments with signed modulo capacity. Constructor evidence keeps capacity positive; do not modernize behavior with an extra zero-capacity guard. | Direct stride/stores/idiv plus class declaration. |
| Copied status event | `0x004aa050` is a free `__stdcall` Event.cpp helper, allocates/copies the 11-byte payload, builds Event type 18/kind 0, dispatches through `g_pEventDispatcher`, and relies on EventDispatcher ownership cleanup. | Fresh decompile/disassembly/xrefs and Event layout. |
| EH/compiler glue | Target has stack cookie and range-check support only; copied-event helper has normal stack-Event unwind cleanup. Neither warrants handwritten EH, cookie, rangecheck, vptr, or destructor code. | Analyze/disassembly/SEH metadata. |
| Source placement | Target and retained packet helpers belong to UserPane.cpp; the shared MapPoint declaration and direction helper belong to MapPane.cpp; copied-event helper belongs to Event.cpp; ObjectPane accessor belongs to ObjectPane.cpp. | Receiver/source-family and file-level dependencies. |

Rejected alternatives:

- LivingObjectPane method: rejected by exact base size and UserPane-only offsets.
- MapPane method or protocol utility: rejected because MapPane is a consumed receiver and the method mutates UserPane history/animation state.
- Split the target into packet/effect/view helpers: rejected because there is one modeled source method and no internal callable boundaries; only compiler table bytes follow the return.
- Treat `0x005a36de-0x005a36f0` as padding: rejected because four dwords are referenced by the direction switch.
- Canonical 0x32 tail byte: rejected by direct value-first writer behavior and explicit overwrite.
- `movementBlocked`, `AllowsMovementStatusFlag`, `m_movementSpeed`, and `SendMovementViewportState`: rejected as stale or invented labels.
- Keep `DirectionToTileOffset` static: rejected by cross-file caller spread.
- Emit a standalone effect-list stop helper: rejected because no such callable body exists; the two scans are source-level inline loops in this method.

## Evidence Standards Used

- Direct evidence: fresh streamable IDA MCP `idb_list`, `server_health`, bounded `get_bytes`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, and `xrefs_to`; exact raw helper disassembly; adjacent functions and table bytes.
- Documentation evidence: current by-memory/class/file/type/global pages, read-only manual coverage, the historical pre-callback generated UserPane.cpp as a non-authoritative integration lead, and matching executed reports opened after search gating.
- Inference: source-facing private names, retained-inline source shape, and original `.cpp` organization. Each is constrained by binary behavior and existing project conventions.
- Tool limitation: two initial direct-client requests used obsolete response/schema assumptions (`databases` instead of `sessions`, and an omitted `UseBasicParsing`) and failed client-side before a valid IDB call. Corrected calls against the live session succeeded; these were request-shape limitations, not MCP unavailability. No evidence depends on a failed call.

## Evidence Checked

- Fresh MCP transport initialized at `2026-07-14T23:17:03.7832199-04:00`; `idb_list` returned one active/adopted session `0cf42e97`, worker PID 8808, `is_analyzing:false`.
- `server_health(database=0cf42e97)` returned `status:ok`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, cache size 2067.
- Bounded `get_bytes(0x005a2e00,32)` returned `55 8b ec 81 ec f4 00 00 00 a1 24 2f 67 00 33 c5 89 45 fc 53 8a 5d 08 56 8b f1 89 9d 10 ff ff ff`.
- `lookup_funcs(0x005a2e00)` returned `sub_5A2E00`, size `0x8de`, modeled end `0x005a36de`; predecessor `0x005a2de0-0x005a2dfb`, five `cc` alignment bytes, and successor `0x005a36f0-0x005a3766` were checked.
- Target `analyze_function` returned 81 basic blocks, cyclomatic complexity 48, 585 instructions, no user EH, and 24 callees. Full target decompile plus bounded disassembly were reviewed.
- Target tail bytes show return at `0x005a36d6`, compiler range-check call at `0x005a36d9`, alignment `66 90`, four jump-table dwords `0x005a30ef`, `0x005a30a3`, `0x005a3139`, `0x005a3059`, and successor `0x005a36f0`.
- `xrefs_to(0x005a2e00)` returned ten calls: two from MapPane timer `0x00509030`, four from UserPane key handler `0x005a5bd0`, and four from raw key-direction helper `0x005a9190`.
- Raw helper `0x005a9190` maps key words `0x80..0x83` to direction `3,0,1,2`; it is source-shaped but not an IDA function and has an attached jump table. It is caller support, not a target split.
- `lookup/decompile/disasm/xrefs` for `0x004aa050` returned exact range `0x004aa050-0x004aa109`, `__stdcall(void*,size_t)`, three callers (`0x005a36c1`, `0x005a507d`, `0x005a5e18`), Event construction/type 18/kind 0/data/size writes, dispatcher call `0x004a6ef0`, and compiler Event cleanup.
- Current docs and exact formal blocks were read for UserPane, MapPane, ObjectPane, LivingObjectPane, Event, EventDispatcher, List, EffectInfo, EffectObjectPane, ObjectStatusBlob, PacketBuffer scalar/cursor helpers, UID0003UX, UID0003UY, UID00041W, UID0003XP, UID000425, UID000426, UID000428, and UID000232.
- Historical pre-callback generated lead: UserPane.cpp SHA256 `54B37C0A2B6AB27C31F67AA1090B44EFE8E246F6FFAEBACAA478368A19309ECF`, 60,034 bytes, last write `2026-07-14T23:31:51.8033444-04:00`, exposed stale target tokens and established the callback verification baseline; it is not current output.
- Historical B001 waited generated evidence: command `000000012593` produced the immediate UserPane.cpp SHA256 `6B4B0FC7E10109C3F6FF9F036110621B59132FD3AB17EDD7207723FD89135000`, MapPane.cpp `E0DC36F8A258B245E0EE62A646FF97E4BA28CF0F1CC1DCA7F1B9629985B04C7A`, ObjectPane.cpp `5F4F5E2CD6C8EFF36C5ECA5626C864D884401E40BA4C72D0835122EC4B1D70B2`, and Event.cpp `F469652986FF9ED476D3E4A35673E477BED2DE9D9296F77F1F1E8040989F3CF2`; Validator Results separately records the current supervisor-owned command-`000000012692` snapshot and assertions.
- Manual coverage rows were read for all applied path/score/description changes. B001 did not edit them; the exact text below is preserved as the historical pre-application supervisor handoff. Supervisor commands `000000012665` through `000000012668` later applied and validated the current manual rows without loss.
- Negative checks: no second target body, no vtable/data callback to target, no user exception handler, no additional source-bearing tail after the return, no effect-pane null guard, no `std::vector` semantics, no direct route to raw UID0003UX/UID0003UY starts, no exact prior standalone target report, and no Older-Research/SpecialReports match.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3U6-001 | Target is `UserPane::ProcessMovement(unsigned char)`, not LivingObjectPane. | High | UserPane-only offsets; exact base size; callers. | Target, UID0000FQ, UID0000P1, UID0001KM | incorporate | applied |
| C3U6-002 | Correct target physical range/path is `0x005a2e00-0x005a36f0`. | High | Code endpoint plus referenced jump table and successor. | Target path, parent links, coverage | incorporate | applied |
| C3U6-003 | Target is one source method with attached compiler switch data, no source child split. | High | One function/CFG; table references; no internal starts. | Target range/split sections | incorporate | applied |
| C3U6-004 | Target score becomes `92/94`. | High | Exhaustive behavior, boundary, route, names, and C++ resolution. | Target metadata/coverage | incorporate | applied |
| C3U6-005 | Owner/emitter UID0000FQ, reconstructable true, blank position remain. | High | Member receiver and current valid route. | Target metadata | already-present | already-present |
| C3U6-006 | Target `Nested` becomes `0`, not count-style `8`. | High | Parent-first relative indentation; first sibling already opens level. | Target metadata/manual hierarchy | reject-stale | applied |
| C3U6-007 | Preserve exact moving and name-visible early returns. | High | Direct byte tests `+0x1c4/+0x1d1`. | Target behavior/C++ | incorporate | applied |
| C3U6-008 | Direction mode 1 uses signed modulo; other nonzero uses current tick low bits. | High | Direct lowering and TimerMgr `+0x18`. | Target behavior/C++ | incorporate | applied |
| C3U6-009 | Changed facing sends opcode `0x11`, sets facing, returns. | High | Direct writes/callee. | Target and UID0003H4 relation | incorporate | applied |
| C3U6-010 | EPF effect path is gated by exact equality `g_useEpfAssets == 1`. | High | Direct compare. | Target behavior | incorporate | applied |
| C3U6-011 | Effect 201 is requested through global active MapPane and copied through EffectObjImageLib. | High | Direct globals/calls. | Target, UID000232, EffectInfo | incorporate | applied |
| C3U6-012 | Effect cleanup scans global `g_pUserPane`, secondary before primary, in reverse. | High | Direct loads/list loops. | Target, UID00023H, UID0001U8 | incorporate | applied |
| C3U6-013 | List elements are pointer slots; source dereferences `EffectObjectPane **`. | High | List element size/accessor and target load. | Target behavior | incorporate | applied |
| C3U6-014 | Cleanup matches `m_effectId`, requires `IsLooping`, deletes first match, and has no pane-null guard. | High | Direct compare/call/scalar delete. | Target/support prose | incorporate | applied |
| C3U6-015 | `m_playerSettingsState[2]` and MapPane `+0x40c` select viewport-threshold mode. | High | Direct byte gates. | Target/MapPane support | incorporate | applied |
| C3U6-016 | Four threshold fields are half/remaining column/row values from constructor math. | High | Constructor and switch use. | UID0000FQ class block/prose | reject-stale | applied |
| C3U6-017 | True predicate means `sendWaypointPacket`, not blocked movement. | High | CFG to opcode `0x06`. | Target/C++/history | reject-invalid | applied |
| C3U6-018 | Fallback computes next tile with external free `DirectionToTileOffset`. | High | No receiver; 32 caller xrefs. | Target, UID00041W, UID0000L3 | incorporate | applied |
| C3U6-019 | UID00041W becomes `92/93` and drops `static`. | High | Cross-source callers and exact body. | UID00041W metadata/formal | incorporate | applied |
| C3U6-020 | ObjectPane GetMapPosition is row/mapY then column/mapX and returns output. | High | Exact leaf stores. | UID0003XP | incorporate | applied |
| C3U6-021 | UID0003XP becomes `92/94` with complete formal body. | High | Exact leaf, owner/declaration, broad callers. | UID0003XP metadata/formal | incorporate | applied |
| C3U6-022 | Expanded visible bounds use `InsetRect(bounds,-1,-1)` and `PointInRect(row,column)`. | High | Direct callees and geometry contract. | Target behavior/C++ | incorporate | applied |
| C3U6-023 | Collision result `<0` returns, `0` sends blocked, `>0` succeeds. | High | Direct comparisons/branches. | Target/UID000425 support | incorporate | applied |
| C3U6-024 | Blocked packet is opcode `0x69`, BE X/Y, direction, six sent bytes, unsent NUL. | High | Direct writer calls/send length. | Target behavior/C++ | incorporate | applied |
| C3U6-025 | Waypoint packet selected only when predicate true and collision positive. | High | CFG. | Target behavior | incorporate | applied |
| C3U6-026 | Waypoint packet is 16 sent bytes with opcode `0x06`, direction, tag, display status, X/Y, bounds, deltas, token. | High | Live target/raw helper. | Target/UID0003UX | incorporate | applied |
| C3U6-027 | Normal packet is nine sent bytes with opcode `0x32`, direction, tag, display status, X/Y, and sent byte 8 zero. | High | Live target/raw helper. | Target/UID0003UY | reject-stale | applied |
| C3U6-028 | Status tag/event gate is `AllowsMovementStatusTag` plus config bit. | High | UID000426 and direct calls. | Target/UID0003UX/UID0003UY | reject-stale | applied |
| C3U6-029 | Packet byte 3 is `m_objectStatus.m_displayStatusByte`. | High | Exact `this+0x1a0` and type layout. | Target/UID0003UX/UID0003UY | reject-invalid | applied |
| C3U6-030 | History record exact stride/order and modulo update are preserved. | High | Direct stores/stride/idiv. | Target/raw helpers/class/file | incorporate | applied |
| C3U6-031 | UID0003UX remains retained source member with no inbound start route. | Medium-high | Raw source shape and inline-equivalent live route. | UID0003UX history/formal | already-present | already-present |
| C3U6-032 | UID0003UX formal block receives exact ABI/status/MapPoint corrections; score remains `88/89`. | High | Raw body and current score cap. | UID0003UX formal/prose | incorporate | applied |
| C3U6-033 | UID0003UY remains retained source member with no inbound start route. | Medium-high | Raw source shape and inline-equivalent live route. | UID0003UY history/formal | already-present | already-present |
| C3U6-034 | UID0003UY formal block receives exact ABI/status/zero-tail corrections; score remains `87/89`. | High | Raw disassembly and route cap. | UID0003UY formal/prose | incorporate | applied |
| C3U6-035 | Value-first PacketBuffer scalar and append ABI applies to all three movement bodies. | High | Raw callees and call pushes. | Target, UID3UX, UID3UY, UID3YJ, UID3YM | reject-stale | applied |
| C3U6-036 | Waypoint success calls `InitializeWalkAnimation`; normal success calls `StartDirectionalAnimation`. | High | Direct callees. | Target behavior/C++ | incorporate | applied |
| C3U6-037 | Status event payloads are 11 bytes with opcodes `0x0b`/`0x26`, direction high bit, X/Y, viewport column/row, terminal one. | High | Direct writes/call size. | Target and Event helper | incorporate | applied |
| C3U6-038 | `0x004aa050` is free Event.cpp `DispatchCopiedEventPayload`, not MapPane method. | High | `__stdcall`, no receiver use, Event construction. | New exact child, Event aggregate/file | incorporate | applied |
| C3U6-039 | Create/register exact `0x004aa050-0x004aa109` child before links; never fabricate UID. | High | Existing mixed aggregate and exact function. | New child/callback ordering | incorporate | applied |
| C3U6-040 | New copied-event child is `92/94`, owner/emitter UID0000J6, true, blank position, Nested 0. | High | Exact body and Event.cpp route. | UID0004QZ metadata | incorporate | applied |
| C3U6-041 | EventDispatcher owns/frees copied packet payload after synchronous dispatch. | High | Event payload docs and dispatcher type-18 route. | New child/Event support | incorporate | applied |
| C3U6-042 | The historical pre-callback incomplete target formal body required exact replacement. | High | Full source-quality resolution. | Target formal | incorporate | applied |
| C3U6-043 | UserPane class block adds external helper declarations and renames four threshold fields without size change. | High | Cross-TU linkage and constructor offsets. | UID0000FQ formal | incorporate | applied |
| C3U6-044 | UserPane class/file scores remain `92/93` and `91/92`. | High | Bounded synchronization only. | UID0000FQ/UID0000P1 | already-present | already-present |
| C3U6-045 | Parent UID0001KM remains `90/92`, non-emitting index, with corrected target path/range/history. | High | Parent role unchanged. | UID0001KM | incorporate | applied |
| C3U6-046 | MapPane timer caller invokes target twice from active UserPane and ignores return. | High | Xrefs/caller disassembly. | UID0003ZS support | incorporate | applied |
| C3U6-047 | UserPane key handler invokes target for directions `1,2,3,0`. | High | Four direct call sites. | UID0003V9 support | incorporate | applied |
| C3U6-048 | Raw key helper invokes directions `3,0,1,2`; retained caller support only. | High | Raw switch/calls. | Target/parent evidence | incorporate | applied |
| C3U6-049 | UID000428 caller link must use corrected UserPane target path and inline-helper relationship. | High | Direct call `0x005a3235`. | UID000428 | incorporate | applied |
| C3U6-050 | UID00023H support must record global UserPane reverse scans and exact delete condition. | High | Direct target flow. | UID00023H | incorporate | applied |
| C3U6-051 | UID000232 support must record request consumer and separate post-request cleanup. | High | Direct request followed by descriptor scan. | UID000232 | incorporate | applied |
| C3U6-052 | PacketBuffer scalar docs must correct opcode-`0x32` sent-byte claim; cursor docs must correct path/link/ABI wording. | High | Raw helper evidence. | UID0003YJ/UID0003YM/PacketBuffer file | incorporate | applied |
| C3U6-053 | Target has no user-authored EH, cookie, rangecheck, vptr, or destructor source. | High | Analyze/disassembly. | Target compiler-negative evidence | incorporate | applied |
| C3U6-054 | No padding row is added for target tail; table bytes remain target-owned compiler support. | High | Referenced dwords. | Range/padding section | reject-invalid | excluded-with-reason |
| C3U6-055 | Preserve all valid UID0002QY/UID0003Z4 ownership/layout history while explicitly rejecting stale lower conclusions. | High | Current docs and binary. | Target/support history | historicalize | applied |
| C3U6-056 | The pre-application manual-coverage handoff is historical; supervisor commands `000000012665` through `000000012668` applied and validated the current target, helper, parent, and new-child rows with same-or-greater details preserved. | High | Read-only B001 row comparison plus supervisor-owned coverage commands. | Exact coverage section | historicalize | already-present |
| C3U6-057 | Historical pre-callback UserPane.cpp was lead-only; callback verification required each accepted body once in physical order. | High | Pre-callback generated read-only inspection and route. | Callback verification plan | incorporate | applied |
| C3U6-058 | No IDA rename/type/comment mutation is requested. | High | Report-only restriction. | IDA recommendation | not-applicable | excluded-with-reason |
| C3U6-059 | No third-party import applies. | High | NexusTK-owned UI/map/event code. | Checklist | not-applicable | excluded-with-reason |
| C3U6-060 | The historical B001 report-only phase changed only this report and ran no validator/lifecycle operation. | High | Actual operation log. | Validator/Changed Files | already-present | already-present |
| C3U6-061 | Create/register shared `by-type/by-struct/MapPoint.md` before links; never fabricate its UID. | High | Repeated exact 8-byte row/column ABI and no current type page. | New MapPoint type page | incorporate | applied |
| C3U6-062 | MapPoint is `92/93`, owner/emitter UID0000L3, position 5, with row at `+0` and column at `+4`. | High | MapPane/ObjectPane/UserPane stores and source placement. | New MapPoint metadata/formal block | incorporate | applied |
| C3U6-063 | UID0002RW formal body must use `row/column`, preserving `90/92`, UID0000FQ route, and exact viewport values. | High | Exact stores and shared type resolution. | UID0002RW formal/prose | reject-stale | applied |
| C3U6-064 | Historical `MapPoint::x/y` aliases remain search history only; do not emit an anonymous-union compatibility shim. | Medium-high | Project row/column movement semantics and source-quality mandate. | MapPoint/UserPane support history | historicalize | applied |

Callback verification notes for every ledger claim:

| Claim ID | Terminal callback proof |
| --- | --- |
| C3U6-001 | Renamed target, UID0000FQ class, UID0000P1 file, and UID0001KM index now identify `UserPane::ProcessMovement`; scoped commands `000000012541`, `000000012550`, `000000012557`, and `000000012563` each returned exit 0 / `ok:1`. |
| C3U6-002 | Command `000000012541` preserved UID0003U6 while changing the mapped path to `0x005a2e00-0x005a36f0`; it recorded `path_update:1`, 11 reverse source-path updates, and three UID link updates. The old ordinary path is absent. |
| C3U6-003 | The renamed target documents one modeled source method ending `0x005a36de` plus the referenced four-entry switch material through `0x005a36f0`; no source child or ignored-padding row was created. |
| C3U6-004 | UID0003U6 headers are `92/94`; commands `000000012541` and final waited `000000012593` returned exit 0 / `ok:1`, and generated UserPane.cpp records the same scores. |
| C3U6-005 | Target owner/emitter UID0000FQ, reconstructable true, and blank position were retained and validated; no route mutation was reported. |
| C3U6-006 | Target `Nested` is now `0`; final generated order returns from UID0002RW to UID0003U6 and then UID0003U7 without count-style indentation. |
| C3U6-007 | Destination 1 exactly preserves the `m_isMoving` and `m_nameVisible` early returns; accepted-block comparison reports Destination 1 exact match. |
| C3U6-008 | Destination 1 uses signed `(static_cast<signed char>(direction) + 2) % 4` for mode one and timer tick low bits for other nonzero modes; generated target lines 288-298 preserve it. |
| C3U6-009 | Target sends direction through `SendDirectionPacket`, calls `SetFacing`, and returns before movement work; complete UserPane declaration/file evidence was retained. |
| C3U6-010 | Target uses exact `g_useEpfAssets == 1`; generated target contains that equality once and no generalized truthy gate. |
| C3U6-011 | Target requests effect 201 and copies EffectInfo; UID000232 records it as a direct consumer while preserving separate MapPane ownership under command `000000012589`. |
| C3U6-012 | Target and UID00023H now record global `g_pUserPane`, secondary-before-primary reverse scans; UID00023H command `000000012588` returned exit 0 / `ok:1`. |
| C3U6-013 | Destination 1 contains two explicit `EffectObjectPane **` pointer-slot dereferences; generated target contains both and no flattened List model. |
| C3U6-014 | Target/UID00023H preserve `m_effectId`, `IsLooping`, first-match source delete, and absence of a candidate-pane null guard. |
| C3U6-015 | Target and MapPane file document the settings byte plus MapPane transition byte gate without moving ownership; MapPane command `000000012577` returned exit 0 / `ok:1`. |
| C3U6-016 | Exact half/remaining columns/rows fields are in Destination 2 with unchanged layout and size guard; UID0000FQ validation `000000012550` passed. |
| C3U6-017 | Destination 1 and target history use `sendWaypointPacket`; the generated target segment has eight such tokens and zero `movementBlocked`. |
| C3U6-018 | Target calls free `DirectionToTileOffset`; UID00041W and MapPane file record external cross-source linkage under commands `000000012572` and `000000012577`. |
| C3U6-019 | UID00041W is `92/93`; Destination 5 has no `static`, and generated MapPane.cpp contains one non-static definition. |
| C3U6-020 | UID0003XP writes `m_mapY` to `row`, `m_mapX` to `column`, and returns the caller pointer; ObjectPane support links were bounded and validated. |
| C3U6-021 | UID0003XP is `92/94` with exact Destination 6; command `000000012579` registered its previously missing mapping and returned exit 0 / `ok:1`. |
| C3U6-022 | Destination 1 preserves clamped visible bounds, `InsetRect(-1,-1)`, and row/column `PointInRect`; no geometry wrapper was introduced. |
| C3U6-023 | Destination 1 preserves negative return, zero blocked send, and positive success. UID000425 remained verify-only because no current contradiction was found. |
| C3U6-024 | Target formal C++ retains seven local bytes, opcode `0x69`, value-first BE X/Y writes, direction, unsent NUL, and six-byte send. |
| C3U6-025 | Target reaches waypoint selection only after positive collision and true `sendWaypointPacket`; generated order confirms the branch. |
| C3U6-026 | Destination 3 and the live target branch preserve the exact 16-byte opcode-`0x06` layout, bounds/deltas/token, history tag, and display-status byte; UID0003UX validation `000000012568` passed. |
| C3U6-027 | Destination 4 and UID0003YJ now prove the nine-byte opcode-`0x32` packet sends byte eight zero; commands `000000012570` and `000000012590` passed. |
| C3U6-028 | Target, UID0003UX, and UID0003UY use `AllowsMovementStatusTag` plus the Config bit; their generated segments contain the new token and no old status helper. |
| C3U6-029 | Both retained helper blocks use inherited `m_objectStatus.m_displayStatusByte`; no target/helper block uses `m_movementSpeed` as packet byte three. |
| C3U6-030 | Target, both retained helpers, UID0000FQ, and UID0000P1 preserve the exact 16-byte record order and signed modulo index update. |
| C3U6-031 | UID0003UX retains its no-inbound-start route and `88/89` score as already-present negative/liveness evidence; only its inaccurate formal/prose details changed. |
| C3U6-032 | UID0003UX managed block is an exact Destination 3 match; command `000000012568` updated its registry hash and passed. |
| C3U6-033 | UID0003UY retains its no-inbound-start route and `87/89` score as already-present negative/liveness evidence. |
| C3U6-034 | UID0003UY managed block is an exact Destination 4 match, including value-first ABI and zero tail; command `000000012570` passed. |
| C3U6-035 | Target/helpers plus UID0003YJ, UID0003YM, and PacketBuffer file now consistently document value-first scalar/cursor ABI; commands `000000012590`-`000000012592` passed. |
| C3U6-036 | Target calls `InitializeWalkAnimation` on waypoint success and `StartDirectionalAnimation` on normal success; generated target preserves both in branch order. |
| C3U6-037 | Target preserves both exact 11-byte status payloads and calls UID0004QZ twice; payload opcodes, high-bit direction, X/Y, viewport column/row, and terminal one remain explicit. |
| C3U6-038 | Registered UID0004QZ is the free Event.cpp `__stdcall` helper with no receiver; Event parent/file and target links were validated by `000000012583`, `000000012584`, and `000000012593`. |
| C3U6-039 | The child was created first without a UID, then command `000000012543` issued real UID0004QZ before dependent links were added. |
| C3U6-040 | UID0004QZ is `92/94`, owner/emitter UID0000J6, reconstructable true, blank position, `Nested:0`; registration command returned exit 0 / `ok:1`. |
| C3U6-041 | UID0004QZ, UID00014C, and Event file record EventDispatcher's type-18 copied-payload ownership/free route and compiler-only local Event unwind. |
| C3U6-042 | Renamed target's managed block exactly matches Destination 1; generated UserPane.cpp contains one UID0003U6 marker and one definition, with no empty marker. |
| C3U6-043 | UID0000FQ managed block exactly matches Destination 2, including external helper declarations, exact four threshold names, all prior members, `[[CHILDREN]]`, and size guard. |
| C3U6-044 | UID0000FQ remains `92/93` and UID0000P1 remains `91/92`; commands `000000012550` and `000000012557` reported no score change. |
| C3U6-045 | UID0001KM remains `90/92`, ownerless, non-reconstructable, non-emitting, and blank; command `000000012563` synchronized current path/inventory/history. |
| C3U6-046 | UID0003ZS records exact calls `0x0050913c/0x0050933c` through active UserPane with ignored void result; command `000000012585` passed. |
| C3U6-047 | UID0003V9 records call sites `0x005a6e95/eb1/ecd/ee9` with directions `1/2/3/0`; command `000000012586` restored its missing registry mapping and passed. |
| C3U6-048 | Target/index retain raw key-helper sites and direction order `3/0/1/2` as caller support only; no new child/body was fabricated. |
| C3U6-049 | UID000428 links corrected target path and live-inline relation to UID0003UX while retaining `90/92` and its formal body; command `000000012587` passed. |
| C3U6-050 | UID00023H contains exact global UserPane list order, pointer-slot dereference, match/loop/delete/break behavior, and no-null negative; command `000000012588` passed. |
| C3U6-051 | UID000232 records the exact gated request arguments and explicitly separates later UserPane descriptor-copy/list cleanup; command `000000012589` passed. |
| C3U6-052 | UID0003YJ corrects sent-byte history; UID0003YM corrects path/type/value-first append use; PacketBuffer file synchronizes all movement consumers. Commands `000000012590`-`000000012592` passed. |
| C3U6-053 | Target current evidence excludes user EH, cookie, rangecheck, vptr, destructor, and table source; generated target segment contains no `sub_`, cookie, `_RTC_`, or handwritten table body. |
| C3U6-054 | No `by-memory/-ignored.md` edit was made because the referenced switch material is target-owned compiler support, not valid padding; exclusion reason remains exact and applied. |
| C3U6-055 | UID0002QY/UID0003Z4 facts remain in explicit historical sections with rejection reasons; current sections consistently use UserPane, corrected range, helpers, and source route. |
| C3U6-056 | B001 did not edit manual coverage. The exact replacement/insertion handoff remains below as historical pre-application evidence; supervisor commands `000000012665` through `000000012668` applied and validated the current rows. The supervisor preserved or merged same-or-greater existing detail for UID00014C, UID0000FQ, UID0000J6, UID0000L3, UID0000M8, UID0000P1, and UID0002RW instead of replacing those rows with shorter text. |
| C3U6-057 | B001 waited command `000000012593` completed the callback refresh; current supervisor waited command `000000012692` independently reverified each target/helper/accessor marker and definition once in order. Both generated snapshots are recorded below. |
| C3U6-058 | No IDA mutation was requested or performed; documentation-only source names remain the accepted disposition. |
| C3U6-059 | No third-party import applies; every emitted destination is NexusTK-owned source. |
| C3U6-060 | The initial report-only phase changed only this report and ran no validator/lifecycle operation; that historical operation record remains true and is distinct from this authorized callback. |
| C3U6-061 | MapPoint was created without a UID and command `000000012547` issued real UID0004R0 before dependent links were added. |
| C3U6-062 | UID0004R0 is `92/93`, owner/emitter UID0000L3, reconstructable true, position 5, with exact Destination 8 and size guard; registration passed. |
| C3U6-063 | UID0002RW is now `90/92` with exact Destination 9, UID0000FQ route, row/column fields, and exact viewport values; command `000000012575` passed. |
| C3U6-064 | MapPoint, UID0002RW, UserPane, MapPane, and ObjectPane current sections use row/column only; x/y aliases are historical, and generated roots contain no full duplicate/anonymous-union declaration. |

## Positive Evidence Summary

- Direct facts supporting the recommendation: exact function size/CFG; ten calls from three caller families; all UserPane-only offsets; exact packet writes and send lengths; exact tri-state collision flow; exact movement ring stores; exact effect descriptor/list cleanup; exact animation and Event.cpp calls; exact switch table and successor boundary.
- Corroborating docs: complete UserPane and LivingObjectPane declarations establish the derived boundary; MapPane and ObjectPane children establish helper behavior; Event/List/ObjectStatusBlob/EffectInfo pages establish exact source-legal types.
- Strongest inference chain: direct derived-only field use proves UserPane; neighboring UserPane family plus class/file route proves source placement; retained packet bodies and the live inlined copies prove human helper source shape; exact Event factory behavior closes the last cross-module source dependency.

## IDA MCP Facts

- Function/range: `sub_5A2E00`, `0x8de` modeled bytes, 81 basic blocks, 585 instructions, code endpoint `0x005a36de`; attached table extends documentation range to `0x005a36f0`.
- Data/table/padding: predecessor has five `cc`; target tail has referenced NOP/table bytes, not padding; successor starts exactly `0x005a36f0`; no internal target padding split is justified.
- Xrefs: ten calls to target; three calls to `0x004aa050`; retained helpers UID0003UX/UID0003UY have no inbound route to their raw starts.
- Vtable/global/type: target is nonvirtual direct member; consumes `g_pTimerMgr`, `g_activeMapPane`, `g_pEffectObjImageLib`, `g_pUserPane`, `g_packetSender`, `g_pConfig`, and `g_pEventDispatcher`; none of those globals owns the target.
- Negative facts: no target data/pointer callback route, no target user EH, no source function after return before successor, no effect pointer null check, no collision hardening, no history-capacity guard, and no canonicalization of the packet tail.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a2e00-0x005a36f0` | UID0003U6 corrected target path | UserPane source member plus attached switch table | true | UID0000FQ | current `92/94` | implemented and validated |
| `0x005a36de-0x005a36f0` | within UID0003U6 | compiler NOP/four-entry switch material | covered by target | UID0003U6 | not separately scored | attached, no child/no ignored row |
| `0x005a36f0-0x005a3766` | UID0003U7 | successor `InitializeWalkAnimation` | true | UID0000FQ | unchanged `86/88` | verify-only boundary |
| `0x005ac7e0-0x005ac99b` | UID0003UX | retained opcode-`0x06` UserPane member | true | UID0000FQ | current `88/89` | exact formal synchronization applied |
| `0x005ac9a0-0x005acad5` | UID0003UY | retained opcode-`0x32` UserPane member | true | UID0000FQ | current `87/89` | exact formal synchronization applied |
| `0x00505080-0x00505100` | UID00041W | external free MapPane.cpp direction helper | true | UID0000L3 | current `92/93` | linkage/formal repair applied |
| `0x005374d0-0x005374eb` | UID0003XP | ObjectPane position accessor | true | UID00009R | current `92/94` | formal body repair applied |
| `0x004aa050-0x004aa109` | UID0004QZ | free Event.cpp copied-payload factory | true | UID0000J6 | current `92/94` | registered and linked exact child |
| shared eight-byte type | UID0004R0 / `by-type/by-struct/MapPoint.md` | map row/column value type | true | UID0000L3 | current `92/93` | registered shared declaration |
| `0x005a2de0-0x005a2dfb` | UID0002RW | UserPane viewport-position accessor | true | UID0000FQ | current `90/92` | formal field synchronization applied |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050913c`, `0x0050933c` | MapPane timer `0x00509030` -> target | map-side automatic/path movement using active UserPane; return ignored |
| `0x005a6e95`, `0x005a6eb1`, `0x005a6ecd`, `0x005a6ee9` | UserPane OnKeyEvent -> target | direction values `1,2,3,0` |
| `0x005a91ad`, `0x005a91bd`, `0x005a91cd`, `0x005a91dd` | raw key helper -> target | key words map to directions `3,0,1,2` |
| `0x005a2e8c` | QueueAndSendPacket | two-byte facing packet |
| `0x005a2e99` | LivingObjectPane::SetFacing | applies changed facing before return |
| `0x005a2ee0` | MapPane::RequestObjectEffect | requests effect descriptor 201 |
| `0x005a2ef4` | EffectObjImageLib::GetEffectInfo | copies exact descriptor |
| `0x005a3207` | MapPane::CheckMovementCollision | tri-state local movement result |
| `0x005a3235` | MapPane::GetAdjacentVisibleTileBounds | waypoint bounds and token |
| `0x005a3424` | UserPane::InitializeWalkAnimation | waypoint-success animation |
| `0x005a3607` | UserPane::StartDirectionalAnimation | normal-success animation |
| `0x005a36c1` | DispatchCopiedEventPayload | copied 11-byte status event |
| `0x005a507d`, `0x005a5e18` | other callers of copied-event helper | supports shared Event.cpp free-helper ownership |

## Documentation Evidence And IDA Status

- Historical pre-callback defects, now superseded: target lower sections claimed LivingObjectPane ownership and blank C++; the target and retained helper bodies used wrong status/linkage/packet names; UID0003YJ described opcode `0x32` as the sent byte at offset 8; UID00041W used internal `static` linkage; UID0003XP was blank; UID00014C inventoried `0x004aa050` without an exact child; and the pre-callback generated UserPane.cpp emitted one flawed target body. Exact receiver bounds, raw helper/caller evidence, accepted source modeling, and the completed callback rejected each of those states.
- Current implemented ordinary/formal state: UID0003U6 is a `92/94` UserPane member at corrected path/range `0x005a2e00-0x005a36f0`, with owner/emitter UID0000FQ, `Nested:0`, and the complete accepted body. UID0003UX/UID0003UY use the corrected status tag, display-status byte, value-first PacketBuffer ABI, MapPoint contract, and packet tails; UID0003YJ records sent byte 8 as zero; UID00041W has external MapPane.cpp linkage; UID0003XP has its complete accessor body; and registered UID0004QZ is the exact copied-event child linked from UID00014C/Event.cpp. UID0000FQ supplies the complete 0x13eb84 UserPane declaration, UID0000P1 supplies the valid source route, UID00007B establishes the 0x20c LivingObjectPane base boundary, and the synchronized MapPane/ObjectPane/Event/List/Effect/ObjectStatus pages supply the required declarations and contracts. The 24 ordinary destination hashes and successful scoped validator records below verify this applied state.
- Generated and externally owned state: historical B001 waited command `000000012593` generated each accepted target/helper/type body once in physical order. Supervisor-owned command `000000012692` at `2026-07-15T01:41:46-04:00` freshly revalidated the target with `--wait-generated`; at that checkpoint UserPane.cpp, MapPane.cpp, ObjectPane.cpp, and Event.cpp all carried that exact command header and passed the same uniqueness/order/body/negative assertions. Later external refreshes for concurrent work culminated in foreground command `000000012699` on all four files at final rebase readback. The accepted target/helper/type/accessor assertions still pass under that newer generation epoch. B001 did not run any supervisor/external command or edit generated output. Manual coverage synchronization is complete under supervisor commands `000000012665` through `000000012668`, with same-or-greater existing row detail preserved where applicable. Report validation, Gate 2 disposition, execution, count, path movement, and archive state remain external supervisor/validator-owned; none changes the completed ordinary/formal implementation.

## Ranked Ownership Analysis

### 1. UserPane class / UserPane.cpp

- Evidence for: direct receiver; derived-only offsets; UserPane keyboard calls; MapPane active-user pointer; UserPane movement history and animation siblings; complete class declaration and source route.
- Evidence against: inherited LivingObjectPane fields and methods are heavily consumed, but inheritance is dependency evidence, not owner evidence.
- Decision: canonical owner/emitter UID0000FQ; source root UID0000P1.

### 2. LivingObjectPane class / LivingObjectPane.cpp

- Evidence for: `m_isMoving`, `m_facing`, `m_nameVisible`, effect lists, map coordinates, ObjectStatusBlob, and animation helpers originate in the base class.
- Evidence against: method requires many offsets beyond exact base size and all direct interactive callers use UserPane.
- Decision: rejected as target owner; retained as inherited support only.

### 3. MapPane or shared protocol module

- Evidence for: MapPane supplies bounds, collision, transition state, dimensions, and effect request; packet protocol dominates the body.
- Evidence against: MapPane is loaded from a UserPane field, and the body mutates UserPane history/animation/viewport state. PacketBuffer/Socket are generic callees.
- Decision: rejected as target owner. Only UID00041W remains a MapPane.cpp free helper.

### Proposed new file/grouping, if applicable

- No new UserPane source file. Reuse `NexusTK/ui/panels/UserPane.cpp`.
- Exact by-memory child UID0004QZ is registered inside existing `NexusTK/ui/core/Event.cpp`: `0x004aa050-0x004aa109.DispatchCopiedEventPayload.md`. It is narrow, contains one free source helper, and remains owned/emitted by UID0000J6.
- Exact shared type UID0004R0 is registered through existing `NexusTK/map/MapPane.cpp`: `by-type/by-struct/MapPoint.md`. It supplies the common eight-byte row/column declaration required by the target, UID0002RW, UID00041W, and UID0003XP without creating a new source file.
- Candidate related items that belong in Event.cpp but are outside this exact child remain indexed by UID00014C. No broad Event aggregate rewrite is proposed.

## Source Placement

- Target and UID0003UX/UID0003UY: UserPane.cpp through UID0000FQ/UID0000P1.
- MapPoint and UID00041W: shared declaration plus free external helper in MapPane.cpp through UID0000L3.
- UID0003XP: ObjectPane.cpp member through UID00009R/UID0000M5.
- Copied-event child: Event.cpp free helper through UID0000J6.
- Rejected placements: LivingObjectPane.cpp, Socket.cpp, PacketBuffer.cpp, MapPane member qualification for UID00041W, EventDispatcher.cpp for copied-event construction, or a new protocol/movement utility file.
- Remaining uncertainty: exact historical private spellings/header factoring only; no route, access, or compilation blocker remains.

## Range / Split / Padding / Reclassification Analysis

- Exact target code range is `0x005a2e00-0x005a36de`; exact source-document range is `0x005a2e00-0x005a36f0` because the target switch at `0x005a3052` references four dwords in the tail.
- `0x005a36dc-0x005a36de` is `66 90` alignment within the modeled function; `0x005a36de-0x005a36ee` is the four-entry table; final bytes to `0x005a36f0` align the successor. None is a source child or ignored padding.
- Predecessor UID0002RW ends at `0x005a2dfb`; five `cc` bytes remain existing ignored alignment through `0x005a2e00`.
- Successor UID0003U7 starts exactly at `0x005a36f0`; no overlap or merger.
- `Nested:8` is a historical count-style misuse. Parent UID0001KM is already opened by first child UID0002RW; target and subsequent siblings require delta `0`.
- The copied-event helper is one exact source child split from mixed aggregate UID00014C. Its range is `0x004aa050-0x004aa109`; it does not convert the aggregate into one body or change the aggregate formal block.

## Negative Evidence Summary

- No second target function, vtable slot, callback pointer, or source-bearing internal child exists.
- No evidence supports LivingObjectPane ownership after applying the exact object boundary.
- No evidence supports a null guard in either effect-list loop, a history-capacity guard, collision-result hardening, or modulo normalization.
- No direct inbound call/pointer route reaches raw UID0003UX or UID0003UY; retain that negative fact while preserving their source-shaped bodies.
- No source evidence supports `m_movementSpeed`, `AllowsMovementStatusFlag`, `SendMovementViewportState`, `movementBlocked`, or the four current movement-limit field names.
- No binary evidence supports a sent trailing `0x32` byte in the nine-byte normal packet.
- No Wave2/Wave3/generated claim was accepted without current IDA/document confirmation.

## IDA Rename / Type / Comment Recommendations

- Source-facing names: `sendWaypointPacket`; `m_viewportHalfColumns`; `m_viewportHalfRows`; `m_viewportRemainingColumns`; `m_viewportRemainingRows`; `DispatchCopiedEventPayload`; `m_displayStatusByte`; `AllowsMovementStatusTag`.
- Type directions: `unsigned char direction`, `MapPoint { row, column }`, `MapRect { left, top, right, bottom }`, `MovementWaypointSegment`, `LocalMovementHistoryRecord`, `EffectInfo`, `EffectObjectPane *` pointer slots, and `size_t` for copied payload size.
- Keep current IDA symbol names unchanged in this assignment. The report recommends documentation/source names only; IDA mutation is forbidden and unnecessary.

## First-Draft C++ Recommendation

- Applied destinations: target UID0003U6, UserPane declaration UID0000FQ, retained UID0003UX, retained UID0003UY, UID00041W, UID0003XP, registered copied-event child UID0004QZ, registered MapPoint type UID0004R0, and UID0002RW. Exactly nine complete managed blocks follow and each matches its destination exactly.

Destination 1: UID0003U6 corrected target path.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::ProcessMovement(unsigned char direction)
{
    if (m_isMoving)
        return;

    const unsigned char directionMode = m_playerSettingsState[3];
    if (directionMode == 1)
    {
        direction = static_cast<unsigned char>(
            (static_cast<signed char>(direction) + 2) % 4);
    }
    else if (directionMode != 0)
    {
        direction = static_cast<unsigned char>(
            g_pTimerMgr->m_currentTick & 3);
    }

    if (direction != m_facing)
    {
        SendDirectionPacket(direction);
        SetFacing(direction);
        return;
    }

    if (m_nameVisible)
        return;

    if (g_useEpfAssets == 1)
    {
        g_activeMapPane->RequestObjectEffect(m_objectId, 201, 0, false);

        EffectInfo effectInfo;
        g_pEffectObjImageLib->GetEffectInfo(&effectInfo, 201);
        UserPane *activeUserPane = g_pUserPane;
        if (activeUserPane != NULL)
        {
            if (effectInfo.secondaryFrameCount > 0 &&
                effectInfo.secondaryRangeStart >= 0 &&
                effectInfo.secondaryRangeEnd >= 0)
            {
                List *effects = activeUserPane->m_secondaryEffectObjectPanes;
                for (int index = effects->GetCount() - 1; index >= 0; --index)
                {
                    EffectObjectPane *effectPane =
                        *static_cast<EffectObjectPane **>(effects->GetElementAt(index));
                    if (effectPane->m_effectId == effectInfo.effectKeyOrId &&
                        effectPane->IsLooping())
                    {
                        delete effectPane;
                        break;
                    }
                }
            }

            if (effectInfo.primaryFrameCount > 0 &&
                effectInfo.primaryRangeStart >= 0 &&
                effectInfo.primaryRangeEnd >= 0)
            {
                List *effects = activeUserPane->m_primaryEffectObjectPanes;
                for (int index = effects->GetCount() - 1; index >= 0; --index)
                {
                    EffectObjectPane *effectPane =
                        *static_cast<EffectObjectPane **>(effects->GetElementAt(index));
                    if (effectPane->m_effectId == effectInfo.effectKeyOrId &&
                        effectPane->IsLooping())
                    {
                        delete effectPane;
                        break;
                    }
                }
            }
        }
    }

    bool sendWaypointPacket = false;
    if (m_playerSettingsState[2] != 0 &&
        m_mapPane->m_mapTransitionState != 0)
    {
        MapRect mapBounds;
        SetRect(&mapBounds, 0, 0,
                m_mapPane->m_mapWidth, m_mapPane->m_mapHeight);

        MapRect visibleBounds;
        m_mapPane->GetVisibleTileBounds(&visibleBounds);
        ++visibleBounds.left;
        ++visibleBounds.top;
        --visibleBounds.right;
        --visibleBounds.bottom;

        MapPoint position;
        GetMapPosition(&position);
        switch (direction)
        {
        case 0:
            sendWaypointPacket =
                visibleBounds.top - 1 >= mapBounds.top &&
                (visibleBounds.bottom > mapBounds.bottom ||
                 mapBounds.bottom - position.row >= m_viewportRemainingRows);
            break;
        case 1:
            sendWaypointPacket =
                visibleBounds.right + 1 <= mapBounds.right &&
                (visibleBounds.left < mapBounds.left ||
                 position.column - mapBounds.left >= m_viewportHalfColumns);
            break;
        case 2:
            sendWaypointPacket =
                visibleBounds.bottom + 1 <= mapBounds.bottom &&
                (visibleBounds.top < mapBounds.top ||
                 position.row - mapBounds.top >= m_viewportHalfRows);
            break;
        case 3:
            sendWaypointPacket =
                visibleBounds.left - 1 >= mapBounds.left &&
                (visibleBounds.right > mapBounds.right ||
                 mapBounds.right - position.column >= m_viewportRemainingColumns);
            break;
        default:
            sendWaypointPacket = false;
            break;
        }
    }
    else
    {
        MapPoint offset;
        DirectionToTileOffset(&offset, direction);

        MapPoint position;
        GetMapPosition(&position);

        MapRect visibleBounds;
        m_mapPane->GetClampedVisibleTileBounds(&visibleBounds);
        InsetRect(&visibleBounds, -1, -1);
        sendWaypointPacket = !PointInRect(
            position.row + offset.row,
            position.column + offset.column,
            &visibleBounds);
    }

    const int movementResult =
        m_mapPane->CheckMovementCollision(m_mapX, m_mapY, direction);
    if (movementResult < 0)
        return;

    if (movementResult == 0)
    {
        unsigned char packet[7];
        packet[0] = 0x69;
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapX), packet + 1);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapY), packet + 3);
        packet[5] = direction;
        packet[6] = 0;
        g_packetSender->QueueAndSendPacket(packet, 6);
        return;
    }

    const bool sendMovementStatus =
        m_mapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_sendMovementStatusBit;

    if (sendWaypointPacket)
    {
        MapRect movementBounds;
        const unsigned short movementToken =
            m_mapPane->GetAdjacentVisibleTileBounds(
                direction, &movementBounds);
        MovementWaypointSegment segment;
        segment.startX = movementBounds.left;
        segment.startY = movementBounds.top;
        segment.endX = movementBounds.right;
        segment.endY = movementBounds.bottom;
        SendMovementWaypointPacket(direction, movementToken, &segment);
        InitializeWalkAnimation(direction);

        if (sendMovementStatus)
        {
            unsigned char payload[12];
            payload[0] = 0x0b;
            payload[1] = static_cast<unsigned char>(direction | 0x80);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_mapX), payload + 2);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_mapY), payload + 4);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_viewportColumn), payload + 6);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_viewportRow), payload + 8);
            payload[10] = 1;
            payload[11] = 0;
            DispatchCopiedEventPayload(payload, 11);
        }
        return;
    }

    SendFaceDirectionPacket(direction);
    StartDirectionalAnimation(direction);
    if (sendMovementStatus)
    {
        unsigned char payload[12];
        payload[0] = 0x26;
        payload[1] = static_cast<unsigned char>(direction | 0x80);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapX), payload + 2);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapY), payload + 4);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_viewportColumn), payload + 6);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_viewportRow), payload + 8);
        payload[10] = 1;
        payload[11] = 0;
        DispatchCopiedEventPayload(payload, 11);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2: UID0000FQ `by-class/UserPane.md`, complete declaration replacement preserving all current members and `[[CHILDREN]]`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapPane;
struct MapPoint;
struct PaneKeyEvent;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void SendDirectionPacket(unsigned char direction);

struct LinkedPlayerRecord
{
    unsigned int objectId;                // +0x000
    wchar_t name[128];                    // +0x004
    bool active;                          // +0x104
    unsigned char reserved105;
    unsigned short field106;
    unsigned char state108[7];
    unsigned char reserved10f;
    unsigned short field110;
    unsigned char field112;
    unsigned char reserved113;
    unsigned short field114;
    unsigned char field116;
    unsigned char reserved117;
    unsigned short field118;
    unsigned char field11a;
    unsigned char reserved11b;
    unsigned int value11c;
    unsigned int value120;
    unsigned int value124;
    unsigned int value128;
};

struct LocalInventorySlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001;
    unsigned short itemId;                // +0x002
    unsigned char iconStyle;              // +0x004
    unsigned char reserved005;
    wchar_t displayName[80];              // +0x006
    wchar_t secondaryText[80];            // +0x0a6
    wchar_t tertiaryText[80];             // +0x146
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;         // +0x1e8
    unsigned char quantityPromptFlag;     // +0x1ec
    unsigned char reserved1ed[3];
    unsigned int value1f0;                // +0x1f0
    unsigned int value1f4;                // +0x1f4
    unsigned char targetMode;             // +0x1f8
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001[3];
    int inputKind;                        // +0x004
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];                   // +0x0a8
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(unsigned char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseLinkedObjectsPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(unsigned char action);

private:
    friend class MapPane;

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];       // 0x20c
    LinkedPlayerRecord m_linkedPlayers[50];       // 0x218
    signed char m_linkedPlayerCount;              // 0x3cb0
    unsigned char m_preCollectionState[0x213];    // 0x3cb1
    int m_localPlayerHitRadius;                   // 0x3ec4
    CollectionPlayerDataView m_collectionData;   // 0x3ec8
    int m_screenX;                                // 0x1340cc
    int m_screenY;                                // 0x1340d0
    unsigned int m_screenState;                   // 0x1340d4
    RectBounds m_screenHitBounds;                 // 0x1340d8
    RectBounds m_screenLowerHitBounds;            // 0x1340e8
    MapPane *m_mapPane;                           // 0x1340f8
    unsigned char m_playerSettingsState[8];       // 0x1340fc
    LocalInventorySlotRecord m_inventorySlots[52];// 0x134104
    SpellCommandSlotRecord m_spellCommandSlots[52];// 0x13a834
    bool m_spellCommandSlotsReady;                // 0x13ead4
    unsigned char m_preViewportState[3];          // 0x13ead5
    int m_viewportColumn;                         // 0x13ead8
    int m_viewportRow;                            // 0x13eadc
    int m_viewportHalfColumns;                    // 0x13eae0
    int m_viewportHalfRows;                       // 0x13eae4
    int m_viewportRemainingColumns;               // 0x13eae8
    int m_viewportRemainingRows;                  // 0x13eaec
    unsigned char m_movementState[5];             // 0x13eaf0
    unsigned char m_preActionTickState[3];        // 0x13eaf5
    unsigned int m_lastActionTick;                // 0x13eaf8
    unsigned char m_preWhisperHistory[8];         // 0x13eafc
    List *m_whisperHistoryOther;                  // 0x13eb04
    List *m_outgoingWhisperRecipientHistory;      // 0x13eb08
    List *m_incomingWhisperSenderHistory;         // 0x13eb0c
    unsigned char m_whisperHistorySource;         // 0x13eb10
    unsigned char m_preMovementHistory[3];        // 0x13eb11
    LocalMovementHistoryRecord *m_movementHistoryRecords; // 0x13eb14
    int m_movementHistoryCapacity;                // 0x13eb18
    unsigned char m_movementHistoryWriteIndex;    // 0x13eb1c
    unsigned char m_movementHistoryState[3];      // 0x13eb1d
    unsigned char *m_deferredUserListPacket;      // 0x13eb20
    size_t m_deferredUserListPacketSize;          // 0x13eb24
    int m_deferredUserListCount;                  // 0x13eb28
    unsigned int m_deferredUserListDeadline;      // 0x13eb2c
    bool m_deferredUserListActive;                // 0x13eb30
    unsigned char m_preMovementTicks[3];          // 0x13eb31
    unsigned int m_lastMovementSendTick;          // 0x13eb34
    unsigned int m_lastMovementInputTick;         // 0x13eb38
    unsigned char m_actionMode;                   // 0x13eb3c
    unsigned char m_userPaneTrailingState0;       // 0x13eb3d
    bool m_includeAdjacentMovementTargets;        // 0x13eb3e
    unsigned char m_userPaneTrailingState2[0x45]; // 0x13eb3f
};

typedef char LinkedPlayerRecordSizeMustBe300[
    sizeof(LinkedPlayerRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3: UID0003UX retained waypoint helper.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::SendMovementWaypointPacket(
    unsigned char direction, unsigned short token,
    const MovementWaypointSegment *segment)
{
    unsigned char packet[0x12];
    int packetSize = 0;
    packet[packetSize++] = 0x06;
    packet[packetSize++] = direction;
    packet[packetSize++] =
        m_mapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_sendMovementStatusBit
            ? static_cast<unsigned char>(m_movementHistoryWriteIndex | 0x80)
            : static_cast<unsigned char>(m_movementHistoryWriteIndex & 0x7f);
    packet[packetSize++] = m_objectStatus.m_displayStatusByte;

    MapPoint position;
    GetMapPosition(&position);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(position.column), packet, &packetSize);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(position.row), packet, &packetSize);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(segment->startX), packet, &packetSize);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(segment->startY), packet, &packetSize);
    PacketBufferAppendUInt8(
        static_cast<unsigned char>(segment->endX - segment->startX),
        packet, &packetSize);
    PacketBufferAppendUInt8(
        static_cast<unsigned char>(segment->endY - segment->startY),
        packet, &packetSize);
    PacketBufferAppendUInt16BE(token, packet, &packetSize);

    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[m_movementHistoryWriteIndex];
    record.active = 1;
    record.tileY = position.row;
    record.tileX = position.column;
    record.direction = direction;
    m_movementHistoryWriteIndex = static_cast<unsigned char>(
        (m_movementHistoryWriteIndex + 1) % m_movementHistoryCapacity);
    packet[packetSize] = 0;
    g_packetSender->QueueAndSendPacket(packet, packetSize);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4: UID0003UY retained face-direction helper.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::SendFaceDirectionPacket(unsigned char direction)
{
    unsigned char packet[11];
    packet[0] = 0x32;
    packet[1] = direction;
    packet[2] =
        m_mapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_sendMovementStatusBit
            ? static_cast<unsigned char>(m_movementHistoryWriteIndex | 0x80)
            : static_cast<unsigned char>(m_movementHistoryWriteIndex & 0x7f);
    packet[3] = m_objectStatus.m_displayStatusByte;

    MapPoint position;
    GetMapPosition(&position);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(position.column), packet + 4);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(position.row), packet + 6);

    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[m_movementHistoryWriteIndex];
    record.active = 1;
    record.tileY = position.row;
    record.tileX = position.column;
    record.direction = direction;
    m_movementHistoryWriteIndex = static_cast<unsigned char>(
        (m_movementHistoryWriteIndex + 1) % m_movementHistoryCapacity);

    PacketBufferWriteUInt16BE(0x32, packet + 8);
    packet[9] = 0;
    g_packetSender->QueueAndSendPacket(packet, 9);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5: UID00041W MapPane direction helper.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction)
{
    switch (direction)
    {
    case 0:
        SetPoint(outOffset, -1, 0);
        break;
    case 1:
        SetPoint(outOffset, 0, 1);
        break;
    case 2:
        SetPoint(outOffset, 1, 0);
        break;
    case 3:
        SetPoint(outOffset, 0, -1);
        break;
    default:
        SetPoint(outOffset, 0, 0);
        break;
    }

    return outOffset;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6: UID0003XP ObjectPane position accessor.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPoint *ObjectPane::GetMapPosition(MapPoint *outPosition) const
{
    outPosition->row = m_mapY;
    outPosition->column = m_mapX;
    return outPosition;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7: registered UID0004QZ `by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size)
{
    void *copy = operator new(size);
    memmove(copy, data, size);

    Event event;
    event.m_type = kEventPacket;
    event.m_payload.m_packet.m_packetKind = 0;
    event.m_payload.m_packet.m_data = copy;
    event.m_payload.m_packet.m_size = size;
    g_pEventDispatcher->DispatchEvent(&event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 8: registered UID0004R0 `by-type/by-struct/MapPoint.md`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MapPoint
{
    int row;
    int column;
};

typedef char MapPointSizeMustBe8[
    sizeof(MapPoint) == 8 ? 1 : -1];
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 9: UID0002RW `by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPoint *UserPane::GetViewportPosition(MapPoint *outPosition) const
{
    outPosition->row = m_viewportRow;
    outPosition->column = m_viewportColumn;
    return outPosition;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: the blocks keep exact branch polarity, signed modulo, raw writer ABI, packet lengths, local NUL writes, effect scan order, no-null/no-capacity-guard behavior, history update, animation ordering, and Event copy/dispatch ownership.
- Source shape: ordinary late-1999/mid-2000s class members plus narrow file-level helpers; no decompiler variables, raw addresses, synthetic wrappers, lambdas, STL substitutions, cookie/rangecheck source, or ABI destructor source.
- Third-party import: not applicable; all destinations are NexusTK-owned source.

## Final Recommendation

- C3U6-001 through C3U6-064 are implemented at report-level detail with terminal states and per-claim proof above.
- UID0003U6 was UID-preserving range-renamed, set to `92/94` and Nested 0, retained owner/emitter/reconstructable/blank position, and received exact Destination 1.
- Copied-event UID0004QZ and MapPoint UID0004R0 were created/registered serially before dependent links; both real validator UIDs and registration commands are recorded.
- Destinations 2 through 9 are exact managed-block matches and every bounded support page was synchronized under scoped validation.
- UID0001KM remains non-emitting; UID0003UX/UID0003UY remain retained and score-capped; compiler switch bytes remain attached to the target and absent from ignored padding.
- Implementation is complete and no B001 work remains. Exact original private spellings remain confidence caps only.

## Recommended Target Doc Changes

- Applied path: UID-preserving rename from historical `by-memory/0x005a2e00-0x005a36de.UserPaneProcessMovement.md` to current `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md`.
- Applied metadata: `92/94`, owner/emitter UID0000FQ unchanged, reconstructable true, blank position, `Nested:0`.
- Applied formal C++: exact Destination 1.
- Applied detail: complete IDA session proof, callers/callees, packet/state/effect/map/history/event behavior, range/table disposition, ownership/source placement, source names, rejected alternatives, and negative evidence.
- Preserved history: old LivingObjectPane route, blank-C++ decision, unresolved-name statements, flawed `movementBlocked` interpretation, and prior report provenance remain explicitly labeled with rejection reasons.

## Recommended Support Doc Changes

| Support path | Exact applied synchronization |
| --- | --- |
| `by-class/UserPane.md` UID0000FQ | Destination 2 applied; `92/93`, route, size, unrelated fields/methods/history preserved; complete movement semantics and threshold-constructor proof added. |
| `by-file/UserPane.md` UID0000P1 | Preserve `91/92`; add target range/source order, retained-inline helper relation, copied-event declaration dependency, packet/history behavior, and historical corrections. |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` UID0001KM | Preserve `90/92` non-emitting state; correct child path/range, target inventory, behavior, table attachment, retained-helper facts, and stale LivingObjectPane/blank-body text. |
| UID0003UX waypoint helper | Destination 3 applied; `88/89`, owner/emitter, no-route history preserved; gate, byte 3, MapPoint fields, value-first append ABI, and live inline-equivalent relationship corrected. |
| UID0003UY face helper | Destination 4 applied; `87/89`, owner/emitter, no-route history preserved; gate, byte 3, value-first scalar ABI, backing size, sent byte 8 zero, and live inline-equivalent relationship corrected. |
| UID00041W direction helper | `92/93` and Destination 5 applied; MapPane.cpp owner/emitter/body behavior preserved; file-static claim replaced by external/free cross-source linkage. |
| UID0004R0 `by-type/by-struct/MapPoint.md` | Registered before links at `92/93`, owner/emitter UID0000L3, true, position 5; exact Destination 8, row/Y at `+0`, column/X at `+4`, and size guard applied. |
| UID0002RW UserPane viewport accessor | `90/92`, owner/emitter UID0000FQ and route retained; Destination 9 and exact row/column fields applied; superseded x/y spelling historicalized without alias union. |
| `by-file/MapPane.md` UID0000L3 | Preserve `89/85`; document shared MapPoint declaration ownership, UID00041W external linkage, target consumer, exact direction mapping, and rejected MapPane-member/static alternatives. |
| UID0003XP ObjectPane accessor | `92/94` and Destination 6 applied with owner/emitter preserved; exact leaf bytes/callers, row/column contract, and rejected blank blocker added. |
| `by-class/ObjectPane.md` UID00009R and `by-file/ObjectPane.md` | Preserve scores/formal content; add bounded link proving the existing declaration now has an exact emitting child. |
| UID0004QZ copied-event child | Registered serially at `92/94`, owner/emitter UID0000J6, true, blank position, Nested 0; exact Destination 7 and full caller/ownership/EH evidence applied. |
| UID00014C Event aggregate | Preserve `91/92`, blank aggregate formal C++; add exact child link/inventory and distinguish source child from aggregate/retained/EH contents. |
| `by-file/Event.md` UID0000J6 | Preserve `91/92`; add copied-event child, three callers, ownership transfer, and EventDispatcher dependency. |
| `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` UID0003ZS | Preserve score/formal; correct target path/owner and two caller sites. |
| `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md` UID0003V9 | Preserve score/formal state; add four directions and corrected target link. |
| UID000428 adjacent bounds | Preserve `90/92` and formal; correct target path/owner and inline waypoint-helper relation. |
| UID00023H IsLooping | Preserve `88/92` and formal; add exact global UserPane secondary/primary reverse scan consumer and delete condition. |
| UID000232 effect dispatch | Preserve `89/91` and formal; add effect-201 request consumer followed by separate descriptor/list cleanup. |
| UID0003YJ scalar writers | Preserve metadata/blank formal; correct value-first ABI application and replace false "sent trailing 0x32" claim with sent byte 8 zero. |
| UID0003YM cursor append writers | Preserve metadata/blank formal; correct value-first ABI and current UserPane helper paths/names. |
| `by-file/PacketBuffer.md` UID0000M8 | Preserve score; add movement consumers as exact value-first ABI evidence and historicalize destination-first examples. |
| ObjectStatusBlob, EffectInfo, List, TimerMgr, Config, globals, UID000425/426 | Verify-only unless drift appears; their current same-or-greater contracts are authoritative dependencies. |

## Score And Metadata Recommendation

- Target historical pre-callback state: `86/88`, UID0000FQ owner/emitter, true, blank position, Nested 8, old range.
- Target current applied state: `92/94`, owner/emitter/reconstructable/blank position unchanged, Nested 0, corrected range/path and complete body.
- Completion rises because every branch, packet, field, helper, caller, table, compiler exclusion, source route, and formal body is now documented.
- Confidence rises because current live IDA, raw retained helpers, exact class layouts, and caller/callee support converge. It remains below 95 because stripped symbols cannot prove every private identifier or historical header split.
- Applied scores: UID00041W `88/91 -> 92/93`; UID0003XP `87/91 -> 92/94`; UID0004QZ `92/94`; UID0004R0 `92/93`; UID0002RW `90/91 -> 90/92`. UID0003UX/UID0003UY remain `88/89` and `87/89` because no inbound start route is recovered.
- Score blocker audit: owner, range, table/padding, callers/callees, field/type/global names, packet ABI/layout, source placement, declaration/access, copied-event source, retained-helper liveness, and generated integration are resolved and validated.

## Open Questions With Attempted Resolution

- Exact original method/helper/private-field spellings: stripped binary and no PDB were checked. Current names are the strongest project-consistent semantic spellings; this is a confidence cap, not a code blocker.
- Whether retained UID0003UX/UID0003UY had a hidden source route: direct xrefs, pointer routes, modeled starts, raw bytes, and live inline copies were checked. No route was found; source-shaped retained members remain the safest disposition.
- Whether `0x004aa050` is an EventMan member: no receiver is consumed, it returns with `retn 8`, and callers span UserPane helpers. Free Event.cpp helper is stronger and fully source-legal.
- Whether target should end at `0x005a36de`: no, because its switch references the following table. The precise source-document endpoint is `0x005a36f0`.
- Whether MapPane direct field access is legal: current project MapPane source surface already exposes the exact documented map/transition fields to UserPane/MapPane collaborators; the target uses no unmodeled private accessor. No future friend/accessor placeholder is required.
- Whether MapPoint should expose `x/y`, `row/column`, or both: direct stores and MapPane/ObjectPane/UserPane semantics converge on row at `+0` and column at `+4`. Destination 8 provides that one exact declaration, Destination 9 consumes it, and the older x/y spelling is historicalized rather than retained through a source-invented union.
- Remaining unresolved questions with source/score impact: none. Lexical uncertainty alone caps scores below 95.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- B001 read `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md` read-only for every applied path, score, child, source-route, or description change. B001 did not edit these supervisor-owned manual files.
- Current state: the supervisor applied and validated the no-loss manual-coverage synchronization through the following commands. These operations were not run by B001.

| Supervisor command ID | Timestamp (EDT) | Manual coverage path | Current result |
|---|---|---|---|
| `000000012665` | `2026-07-15T01:34:39-04:00` | `by-memory/-coverage-report.md` | supervisor-applied and validated |
| `000000012666` | `2026-07-15T01:35:03-04:00` | `by-class/-coverage-report.md` | supervisor-applied and validated |
| `000000012667` | `2026-07-15T01:35:50-04:00` | `by-file/-coverage-report.md` | supervisor-applied and validated |
| `000000012668` | `2026-07-15T01:36:15-04:00` | `by-type/by-struct/-coverage-report.md` | supervisor-applied and validated |

- No-loss disposition: the supervisor deliberately preserved or merged same-or-greater existing details for UID00014C, UID0000FQ, UID0000J6, UID0000L3, UID0000M8, UID0000P1, and UID0002RW rather than replacing those current rows with shorter text.
- Historical handoff boundary: every imperative replacement/insertion label and exact row payload below records B001's pre-application supervisor handoff. It is retained as historical evidence and is not a current instruction or pending action.
- Historical handoff proposed replacing the UID0003U6 row in `by-memory/-coverage-report.md` with:

`        - [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md) 0x005a2e00-0x005a36f0 | UserPane member plus attached switch table | UserPaneProcessMovement : reconstructable : 92% : very-strong : Exact ten-call local movement method with direction modes, facing-only send, effect-201 cleanup, viewport packet selection, tri-state collision, opcode 0x69/0x06/0x32 packets, history ring, animation/status events, and complete source-ready C++.`

- Historical handoff proposed replacing UID0003UX and UID0003UY rows with:

`        - [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md) 0x005ac7e0-0x005ac99b | retained UserPane member | UserPaneSendMovementWaypointPacket : reconstructable : 88% : strong : Complete retained no-start-xref opcode-0x06 sender with value-first PacketBuffer ABI, status tag/display byte, exact 16-byte payload, history ring update, and live ProcessMovement inline-equivalent route.`

`        - [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md) 0x005ac9a0-0x005acad5 | retained UserPane member | UserPaneSendFaceDirectionPacket : reconstructable : 87% : strong : Complete retained no-start-xref opcode-0x32 sender with value-first PacketBuffer ABI, status tag/display byte, exact nine-byte payload whose sent byte 8 is zero, history ring update, and live ProcessMovement inline-equivalent route.`

- Historical handoff proposed inserting under the MapPane coordinate aggregate immediately before UID0001AQ:

`        - [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md) 0x00505080-0x00505100 | external free MapPane.cpp helper | MapPaneDirectionToTileOffset : reconstructable : 92% : very-strong : Exact direction 0/1/2/3 to row/column offset conversion, 32 cross-source callers, external linkage, complete formal body, and rejected static/member alternatives.`

- Historical handoff proposed inserting under UID0001D5 ObjectPane aggregate before UID0003XT:

`        - [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md) 0x005374d0-0x005374eb | ObjectPane member accessor | ObjectPaneGetMapPosition : reconstructable : 92% : very-strong : Exact leaf accessor writes map row/Y then column/X to caller output, returns the output pointer, preserves ObjectPane ownership, and emits complete source C++.`

- Historical handoff proposed replacing the UID0002RW row with:

`        - [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) 0x005a2de0-0x005a2dfb | UserPane member | UserPaneGetViewportPosition : reconstructable : 90% : very-strong : Exact four-caller UserPane viewport accessor writing row then column through the shared MapPoint declaration, with complete source body and corrected historical x/y and LivingObjectPane aliases.`

- Historical handoff proposed replacing the UID00014C row and inserting the new child immediately after it, substituting the real validator-issued UID:

`    - [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) 0x004a8ac0-0x004ab3eb | mixed Event.cpp helper island | EventManAndEventFactoryHelpers : reconstructable : 91% : very-strong : Exact Event classifiers, EventMan methods, active/free factories, retained duplicate helpers, compiler/EH exclusions, child-only source emission, and complete payload/type/source-family inventory.`

`    - [UID:0004QZ][0x004aa050-0x004aa109.DispatchCopiedEventPayload](by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md) 0x004aa050-0x004aa109 | Event.cpp free helper | DispatchCopiedEventPayload : reconstructable : 92% : very-strong : Exact three-caller copied packet-event factory allocating and copying payload bytes, constructing type-18 kind-0 Event state, dispatching through g_pEventDispatcher, and preserving compiler-only Event unwind cleanup.`

- Historical handoff proposed inserting alphabetically after MapPaneTileRecord in `by-type/by-struct/-coverage-report.md`, substituting the real validator-issued UID:

`- [UID:0004R0][MapPoint](by-type/by-struct/MapPoint.md) : reconstructable : 92% : very-strong : Exact eight-byte shared map coordinate value type with row/Y at +0, column/X at +4, a size guard, MapPane source ownership, and synchronized UserPane/ObjectPane/MapPane consumers.`

- Historical handoff proposed inserting UID0003YM immediately after existing UID0003YJ:

`        - [UID:0003YM][0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers](by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md) 0x00575650-0x00575703 | cursor append writer family | PacketBufferCursorAppendBigEndianHelpers : reconstructable : 86% : strong : Four value-first cursor append helpers with exact widths, spare-zero/cursor semantics, retained raw UInt24 overload, and corrected UserPane movement-packet consumers.`

- Historical handoff proposed replacing the by-class UID0000FQ row with:

`- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 92% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external movement/event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, action/adjacent-target state, and preserved full layout/size guard.`

- Historical handoff proposed replacing the by-file UID0000P1, UID0000L3, UID0000J6, and UID0000M8 rows with:

`- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, and preserved server/action/target evidence.`

`- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : very-strong : Major NexusTK/map/MapPane.cpp source root with source-ready map lifecycle/interaction/coordinate/movement families, shared MapPoint declaration ownership, external DirectionToTileOffset linkage and cross-source consumers, exact switch-table handling, dependencies, and compiler-artifact exclusions.`

`- [UID:0000J6][Event](by-file/Event.md) : reconstructable : 91% : very-strong : NexusTK/ui/core/Event.cpp event object/factory module with exact Event lifecycle/payload layout, active EventMan/IME/packet/notification producers, exact copied-payload child, EventDispatcher ownership transfer, and compiler/retained-helper separation.`

`- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) : reconstructable : 84% : medium-high : Packet-buffer utility with scalar/cursor/string helper families, proven value-first ABI and spare-zero semantics, corrected UserPane movement consumers, Socket/PacketTransform boundaries, placement, and remaining shared-header naming questions.`

- Auto-generated tracker text remains validator-owned and was not hand-written by B001. The target `Item Summary` and `Nested` metadata drive generated by-memory coverage after authorized validation.

## Follow-Up Actions

- Manual coverage application and validation are complete under supervisor commands `000000012665` through `000000012668`. Report validation, independent Gate 2 disposition, execution, report count/path, movement, and archival remain external supervisor/validator-owned state; this artifact neither asserts nor directs those lifecycle operations.
- A-agent actions: none.
- B001 actions remaining for UID0003U6: none. The accepted callback is implemented and verified, B001 performed no report lifecycle operation, and no second target was started.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: target `92/94` is justified and remains below rare 95+ final-audit territory because original private spellings/header factoring are inferred.
- Remaining uncertainty: lexical source names and whether retained raw helpers were emitted by an unobserved build route; neither affects exact behavior, owner, split, or C++ readiness.

## Validator Results

- Historical B001 callback invocation used for each ordinary page: `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; command `000000012593` additionally used `--wait-generated`. Every B001 command below ran from `source-3/project-documentation` and returned process exit `0`, validator `ok:1`.

| Command ID | Timestamp (EDT) | Scoped ordinary path | Result / material side effect |
|---|---|---|---|
| `000000012541` | `2026-07-14T23:55:28-04:00` | `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` | exit 0 / ok 1; UID0003U6 preserved; one path update, 11 reverse source-path updates, and three UID-link updates; generated refresh deferred. |
| `000000012543` | `2026-07-14T23:56:17-04:00` | `by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md` | exit 0 / ok 1; issued UID0004QZ; generated refresh deferred. |
| `000000012547` | `2026-07-14T23:57:03-04:00` | `by-type/by-struct/MapPoint.md` | exit 0 / ok 1; issued UID0004R0; generated refresh deferred. |
| `000000012550` | `2026-07-14T23:58:21-04:00` | `by-class/UserPane.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012557` | `2026-07-14T23:58:50-04:00` | `by-file/UserPane.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012563` | `2026-07-14T23:59:32-04:00` | `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012568` | `2026-07-15T00:00:19-04:00` | `by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012570` | `2026-07-15T00:00:58-04:00` | `by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012572` | `2026-07-15T00:01:41-04:00` | `by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md` | exit 0 / ok 1; score synchronized to 92/93; generated refresh deferred. |
| `000000012575` | `2026-07-15T00:02:37-04:00` | `by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md` | exit 0 / ok 1; confidence synchronized to 92; generated refresh deferred. |
| `000000012577` | `2026-07-15T00:03:11-04:00` | `by-file/MapPane.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012579` | `2026-07-15T00:04:08-04:00` | `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md` | exit 0 / ok 1; score synchronized to 92/94 and missing registry mapping restored; generated refresh deferred. |
| `000000012580` | `2026-07-15T00:04:33-04:00` | `by-class/ObjectPane.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012581` | `2026-07-15T00:04:56-04:00` | `by-file/ObjectPane.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012583` | `2026-07-15T00:05:29-04:00` | `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012584` | `2026-07-15T00:06:09-04:00` | `by-file/Event.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012585` | `2026-07-15T00:06:53-04:00` | `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012586` | `2026-07-15T00:07:16-04:00` | `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md` | exit 0 / ok 1; missing registry mapping restored; generated refresh deferred. |
| `000000012587` | `2026-07-15T00:07:41-04:00` | `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012588` | `2026-07-15T00:08:11-04:00` | `by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012589` | `2026-07-15T00:08:40-04:00` | `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012590` | `2026-07-15T00:09:18-04:00` | `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012591` | `2026-07-15T00:09:50-04:00` | `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md` | exit 0 / ok 1; missing registry mapping restored; generated refresh deferred. |
| `000000012592` | `2026-07-15T00:10:17-04:00` | `by-file/PacketBuffer.md` | exit 0 / ok 1; generated refresh deferred. |
| `000000012593` | `2026-07-15T00:11:57-04:00` | `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` | exit 0 / ok 1; `--wait-generated` completed; regenerated 4,955 nodes and 3,996 edges. |

- Fresh supervisor-owned post-callback verification, not run by B001: the supervisor reported all 24 scoped ordinary validations passed. Queue-result metadata for commands `000000012669` through `000000012691` confirms each listed path/timestamp and generated-refresh exit `0`; the supervisor identified command `000000012692` as the final passed target validation with `--wait-generated`.

| Supervisor command ID | Timestamp (EDT) | Scoped ordinary path | Supervisor-owned result |
|---|---|---|---|
| `000000012669` | `2026-07-15T01:37:41-04:00` | `by-class/ObjectPane.md` | scoped pass; queued generated refresh exit 0. |
| `000000012670` | `2026-07-15T01:38:07-04:00` | `by-class/UserPane.md` | scoped pass; queued generated refresh exit 0. |
| `000000012671` | `2026-07-15T01:38:10-04:00` | `by-file/Event.md` | scoped pass; queued generated refresh exit 0. |
| `000000012672` | `2026-07-15T01:38:19-04:00` | `by-file/MapPane.md` | scoped pass; queued generated refresh exit 0. |
| `000000012673` | `2026-07-15T01:38:27-04:00` | `by-file/ObjectPane.md` | scoped pass; queued generated refresh exit 0. |
| `000000012674` | `2026-07-15T01:38:36-04:00` | `by-file/PacketBuffer.md` | scoped pass; queued generated refresh exit 0. |
| `000000012675` | `2026-07-15T01:38:44-04:00` | `by-file/UserPane.md` | scoped pass; queued generated refresh exit 0. |
| `000000012676` | `2026-07-15T01:38:53-04:00` | `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` | scoped pass; queued generated refresh exit 0. |
| `000000012677` | `2026-07-15T01:39:01-04:00` | `by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md` | scoped pass; queued generated refresh exit 0. |
| `000000012678` | `2026-07-15T01:39:12-04:00` | `by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md` | scoped pass; queued generated refresh exit 0. |
| `000000012679` | `2026-07-15T01:39:23-04:00` | `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` | scoped pass; queued generated refresh exit 0. |
| `000000012680` | `2026-07-15T01:39:34-04:00` | `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | scoped pass; queued generated refresh exit 0. |
| `000000012681` | `2026-07-15T01:39:45-04:00` | `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md` | scoped pass; queued generated refresh exit 0. |
| `000000012682` | `2026-07-15T01:39:56-04:00` | `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md` | scoped pass; queued generated refresh exit 0. |
| `000000012683` | `2026-07-15T01:40:07-04:00` | `by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md` | scoped pass; queued generated refresh exit 0. |
| `000000012684` | `2026-07-15T01:40:17-04:00` | `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` | scoped pass; queued generated refresh exit 0. |
| `000000012685` | `2026-07-15T01:40:28-04:00` | `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md` | scoped pass; queued generated refresh exit 0. |
| `000000012686` | `2026-07-15T01:40:39-04:00` | `by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md` | scoped pass; queued generated refresh exit 0. |
| `000000012687` | `2026-07-15T01:40:50-04:00` | `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | scoped pass; queued generated refresh exit 0. |
| `000000012688` | `2026-07-15T01:41:01-04:00` | `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md` | scoped pass; queued generated refresh exit 0. |
| `000000012689` | `2026-07-15T01:41:12-04:00` | `by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md` | scoped pass; queued generated refresh exit 0. |
| `000000012690` | `2026-07-15T01:41:23-04:00` | `by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md` | scoped pass; queued generated refresh exit 0. |
| `000000012691` | `2026-07-15T01:41:34-04:00` | `by-type/by-struct/MapPoint.md` | scoped pass; validator-owned reference/index refresh; queued generated refresh exit 0. |
| `000000012692` | `2026-07-15T01:41:46-04:00` | `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` | scoped pass; final `--wait-generated`; all four relevant generated headers match. |

- The ordinary-file validators reported only broad pre-existing repository warnings during the final generated pass (fallback insert 14, marker missing 86, emitter-with-no-code 171) and bounded pre-existing missing-reference warnings in current support pages. No scoped error blocked any accepted C3U6 claim. Validator-owned mapping and generated/coverage projection side effects were accepted; B001 did not manually edit those files.
- B001 command `000000012593` completed the authorized waited refresh at `2026-07-15T00:11:57-04:00`. Its immediate generated snapshot hashes were UserPane.cpp `6B4B0FC7E10109C3F6FF9F036110621B59132FD3AB17EDD7207723FD89135000`, MapPane.cpp `E0DC36F8A258B245E0EE62A646FF97E4BA28CF0F1CC1DCA7F1B9629985B04C7A`, ObjectPane.cpp `5F4F5E2CD6C8EFF36C5ECA5626C864D884401E40BA4C72D0835122EC4B1D70B2`, and Event.cpp `F469652986FF9ED476D3E4A35673E477BED2DE9D9296F77F1F1E8040989F3CF2`.
- Later external validator-owned foreground refreshes superseded only generated headers/freshness after B001 released all leases. The table records B001's exact command-`000000012593` waited snapshot and assertions rather than asserting an indefinitely current external header state:

| Generated file | SHA256 | Bytes | Last write (EDT) | Required assertions |
|---|---|---:|---|---|
| `auto-generated/NexusTK/ui/panels/UserPane.cpp` | `6B4B0FC7E10109C3F6FF9F036110621B59132FD3AB17EDD7207723FD89135000` | 64,237 | `2026-07-15T00:12:10.2352337-04:00` | UID0003U6, UID0003UX, UID0003UY, and UID0002RW each have one marker and one definition/body; physical source order is UID0002RW (offset 10,425), UID0003U6 (10,716), UID0003U7 (18,220), UID0003UX (53,599), UID0003UY (55,576); no UID0003U6 empty marker, old path, duplicate, `sub_` placeholder, compiler cookie, or RTC artifact. Target body retains exact signed modulo, asset equality, two pointer slots, waypoint send, collision branches, status tag, and two copied-event dispatches. Accepted target/helper segments contain no stale movement-blocked, speed, status, or sender spelling. |
| `auto-generated/NexusTK/map/MapPane.cpp` | `E0DC36F8A258B245E0EE62A646FF97E4BA28CF0F1CC1DCA7F1B9629985B04C7A` | 75,965 | `2026-07-15T00:12:06.1827222-04:00` | UID0004R0 marker, one complete `MapPoint` definition, one DirectionToTileOffset helper, and no competing static MapPoint definition. |
| `auto-generated/NexusTK/map/ObjectPane.cpp` | `5F4F5E2CD6C8EFF36C5ECA5626C864D884401E40BA4C72D0835122EC4B1D70B2` | 3,989 | `2026-07-15T00:12:07.2865755-04:00` | UID0003XP appears once with one accepted ObjectPane map-point accessor body. |
| `auto-generated/NexusTK/ui/core/Event.cpp` | `F469652986FF9ED476D3E4A35673E477BED2DE9D9296F77F1F1E8040989F3CF2` | 8,816 | `2026-07-15T00:12:03.9302774-04:00` | UID0004QZ appears once with one accepted copied-payload dispatch body and no duplicate. |

- A bounded read-only recheck after external command `000000012618` (`validator-refreshed-at: 2026-07-15T00:29:18-04:00`) again passed the same assertions. Its evidence-time hashes were UserPane.cpp `88ACEF77508276E9AB73E5BDFD297F4F5DDFB953CDCE7DC40F24D83B5CC231C2`, MapPane.cpp `02ECE1E069A4605F3F388E5475787150DF12DD30807456F5244CDE85979F046D`, ObjectPane.cpp `4A429EEE4DB72EFA22C51C7EB9B642FD4F247D817EEF753E52A3E2E10C435EE0`, and Event.cpp `8A82EE187B224EFB82826BA56B58DECE44C8DE12EBFC21BC17DBA004CA96C1D8`. These are timestamped verification facts, not an assertion of indefinite external freshness. UserPane.cpp contained only a forward declaration of MapPoint while MapPane.cpp owned the sole full definition. Unrelated existing UserPane methods retained their own pre-existing movement-status/speed spellings; the verified target and accepted helper segments did not.
- Supervisor Gate 2 generated checkpoint: all four files carried `validator-command-id: 000000012692` and `validator-refreshed-at: 2026-07-15T01:41:46-04:00` when the final waited command completed.

| Supervisor command-12692 generated file | SHA256 | Bytes | Last write (EDT) | Checkpoint assertions |
|---|---|---:|---|---|
| `auto-generated/NexusTK/ui/panels/UserPane.cpp` | `4483C82041930CB3DD56FEAFF06BC19C54113ABA4170F9E0443ADC548CA3E30C` | 64,237 | `2026-07-15T01:42:04.7738884-04:00` | UID0002RW, UID0003U6, UID0003U7, UID0003UX, and UID0003UY remain in physical order at offsets 10,422 / 10,713 / 18,217 / 53,596 / 55,573. UID0003U6, UID0003UX, UID0003UY, and UID0002RW each have one marker and one accepted definition; the target/helper family retains signed history modulo, asset equality, two pointer-slot dereferences, waypoint and collision branches, status tag, and two copied-event dispatches. No target empty marker, old path, duplicate, stale movement-blocked/status/speed spelling in the accepted segments, raw `sub_` name, cookie, or RTC artifact appears. |
| `auto-generated/NexusTK/map/MapPane.cpp` | `9A7F2FFE961E315FB4BB6719F55C7180769CD4222245F78253BB9AE36107497A` | 75,965 | `2026-07-15T01:42:00.8497686-04:00` | UID0004R0 and UID00041W each have one marker and one accepted definition; MapPoint has one full struct definition, DirectionToTileOffset has external linkage, and no competing static definition appears. |
| `auto-generated/NexusTK/map/ObjectPane.cpp` | `EE8F8159EE942F234004B90F527A9949653AD1D72FFEEC93BD1E92E396484BB6` | 3,989 | `2026-07-15T01:42:01.8976573-04:00` | UID0003XP has one marker and one accepted ObjectPane map-position accessor definition. |
| `auto-generated/NexusTK/ui/core/Event.cpp` | `7A7DC1D9C9B102E7A629988834D98A59B960AE487E5F437A60A37036643571DF` | 8,816 | `2026-07-15T01:41:58.6218688-04:00` | UID0004QZ has one marker and one accepted copied-payload dispatch definition with no duplicate. |

- The command-`000000012692` generated readback is supervisor-owned. B001 performed only read-only header/hash/body assertions during this rebase and did not run any command in `000000012669` through `000000012692`.
- Post-checkpoint external drift, final evidence-time rebase readback: intermediate commands `000000012694`/`000000012695` refreshed UserPane.cpp for unrelated UID0003U8/UID0003UQ work, and `000000012697` refreshed MapPane.cpp for unrelated UID00027F work. A later external foreground refresh placed all four relevant files on `validator-command-id: 000000012699` and `validator-refreshed-at: 2026-07-15T01:54:32-04:00`. Current evidence-time hashes/size/last-write are UserPane.cpp `DDE87CCDC7700348665C170FF768C18909CF4636125EF77B46E3152AA3856EEA` / 64,313 / `2026-07-15T01:54:44.9819607-04:00`; MapPane.cpp `1DBEA0BAAEA313EE54737C5D9D75AAB18BFCE2680DB9CEE8D9F7D08D0C783B94` / 75,956 / `2026-07-15T01:54:41.0713209-04:00`; ObjectPane.cpp `B1CB70C5830B88150C5FE28EF3F74476CD8A39C17625F8436E532366600D353A` / 3,989 / `2026-07-15T01:54:42.1231985-04:00`; Event.cpp `6E3D884CCC055CC8D0293B62F964253BF1FB25515EE0E66B47EA95B407D662B9` / 8,816 / `2026-07-15T01:54:38.9044824-04:00`. Read-only recheck found one UID0003U6/UID0003UX/UID0003UY/UID0002RW marker and accepted definition each in order at offsets 10,422 / 10,713 / 18,217 / 53,672 / 55,649; one UID0004R0/UID00041W/UID0003XP/UID0004QZ marker and accepted definition each; and zero target empty marker, old path, duplicate, static DirectionToTileOffset, or stale target token. These later validator-owned generated changes are not B001 implementation drift, do not alter the supervisor command-`000000012692` Gate 2 checkpoint, and are recorded as a timestamped readback rather than an indefinite freshness claim.
- Lease closure: every ordinary lease was acquired only immediately before its edit and released immediately after the scoped validator. Final lease inspection found zero active B001 leases.

## Changed Files

- Renamed with UID preservation: `by-memory/0x005a2e00-0x005a36de.UserPaneProcessMovement.md` -> `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` (UID0003U6). The old path is absent.
- Created and registered serially before dependent links: `by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md` (UID0004QZ), then `by-type/by-struct/MapPoint.md` (UID0004R0).
- Modified the 21 bounded existing support pages listed below and this same report. No ordinary destination outside the accepted scope was edited manually.

| Current ordinary destination | SHA256 after scoped validation |
|---|---|
| `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` | `3AB216A8190A2A20D186E8D9CEFD58D6B8E22A872D4E16652F7B1E71B9AEB56D` |
| `by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md` | `C95C42E4128DA36BBBC28FBFE68B27A85E0ADA596EE7FC89BA1D74D4E8EAF06C` |
| `by-type/by-struct/MapPoint.md` | `B9E2E954A931B06035FA0B6AF88F344DAF8DACB9EB9666369E5DF74F6610CFBD` |
| `by-class/UserPane.md` | `4D456A312DF68B1C8E3F24EC7F8066EC20C937B5089E64463DC126AF2147DA0E` |
| `by-file/UserPane.md` | `2DD547743B396369F0B1A6ADB7176AEA9DC9C680CB06CE1F24287AF8CEDD480F` |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `0EF217E43CDC49C4B26116295D2D4757122AE59D3CC809F696AFCC1CF2E548A3` |
| `by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md` | `47B41CD437A3F74DBD6651416993C1F757E6B1709DEBF638103DA8F4DE51FD91` |
| `by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md` | `0F9B71BCF7106C99437707B3C0FD47D19B6DA364633572D4D498A79287FB0D4F` |
| `by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md` | `999C20C4CC3CEE8002F020839675C68A7E45650F1CD7EF7742D86D8B2A063A10` |
| `by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md` | `8CE41EEB93BA534640AD45D807F3A9D599E337A375C4FC297CCDF42C4221069A` |
| `by-file/MapPane.md` | `2E7908E81F5B4B411C55EE17403EE434AA964DE503C3A1180F21722B70C0C1B8` |
| `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md` | `D1E711D5BAED2E669F1208094F4DD75E6168F211F8FBB8ACEF5ECC0A7C23F501` |
| `by-class/ObjectPane.md` | `652BC11566A535528D3C6D20ABEBDA37C0ED40408F3863E9891E7E0D32BC4531` |
| `by-file/ObjectPane.md` | `3D9FEAF9464C1B079E75D31989EA6A43C70B250DFABEFC978AF779FC01D1A6B3` |
| `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` | `F28713EA42334F076EA792D9244FC865E9940E4E137C0BF0A9085E7B7E319949` |
| `by-file/Event.md` | `1A3EA68C36E3F21F12A301DB5A30748AC0C0C1BF192FD5C634411D2F3C2E8A9C` |
| `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | `5A1A9F4279DB92D813DE04B3285C492F7CFBE573D51128FDAD5ECCFE5A50DF59` |
| `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md` | `C83CD3F7689EC815ECAD3FD83E97CF82C8B7B967149D598A489154A415898A07` |
| `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` | `1589E4F1E3A221A9059A8FA4B882F16C317F40E5A0930406F97BD5F6EBB0B232` |
| `by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md` | `26BF81E0C4154FDD976DB2D63F63957E25AC0E51C3E824B1870674DF8201DC5F` |
| `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md` | `625090B8446EB32428EBA4B0EA5916263006BA3536F52FD4E71D2AB4BFB5509F` |
| `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` | `BE302FAEFD8D6CE779FA3ED30F2B28DA3AB28678603BE3520DB40B86274777D0` |
| `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md` | `D21709682536D1E61F968A355343B9BD228BB5CD4267CF215F2D3C157DC7CD95` |
| `by-file/PacketBuffer.md` | `E36A7117AA6E0E205A5B45694F371D527D5D798629860631C2EA78E9A14933CA` |

- Restricted files: no manual edit to generated output, any `-coverage-report.md`, tracker, supervisor/audit, validator-state, lifecycle, queue, lock, archive, or IDA state. Generated and projection changes above are validator-owned side effects.
- Report-repair readback at `2026-07-15T00:49-04:00` found that another callback had externally updated `by-file/MapPane.md` at `2026-07-15T00:44:17.1680562-04:00` after B001's scoped-validation snapshot. The current page retains UID0004R0 MapPoint ownership/layout, UID00041W external free-helper linkage/mapping, UID0003U6 consumer linkage, status-tag semantics, rejected stale alternatives, and unchanged `89/85` file metadata. The inventory hash above is synchronized to that read-only current state; B001 did not edit, lease, or validate the page during this report-text repair.
- Supervisor-owned command `000000012691` refreshed MapPoint reference/index metadata at `2026-07-15T01:41:34-04:00`, changing only its current ordinary-file hash from the historical B001 snapshot `2DB9A8DEE0FCEE86864426B358AE8E0898CFA6B4D954FA523E8F15FFDB95FCB6` to `B9E2E954A931B06035FA0B6AF88F344DAF8DACB9EB9666369E5DF74F6610CFBD`. Its accepted UID0004R0 metadata, formal block, MapPoint layout/size guard, source owner, and consumer evidence remain unchanged. This is supervisor validator-owned reference/index synchronization, not B001 implementation drift; B001 did not edit, lease, or validate the page during this rebase.
- Report execution: not run or probed. B001 performed no execute, report-lifecycle, count, move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor accepted the exact report SHA `2157FABB3C75F1CD2F17B864AE0BA9AE0CEE632AFC103CBDF5933FC6F3586BBC` before implementation.
- [x] Updated the complete accepted target/support set: corrected UID0003U6 path; UID0000FQ; UID0000P1; UID0001KM; UID0003UX; UID0003UY; UID00041W; UID0004R0; UID0002RW; UID0000L3; UID0003XP; ObjectPane class/file; UID0004QZ; UID00014C; UID0000J6; UID0003ZS; UID0003V9; UID000428; UID00023H; UID000232; UID0003YJ; UID0003YM; UID0000M8.
- [x] Preserved the live IDB `0cf42e97` evidence pass, exact range/bytes/CFG/xrefs/callees, raw helper bodies, support docs, historical roots, generated lead, and manual coverage findings.
- [x] Updated C3U6-001 through C3U6-064 to allowed terminal callback states and added claim-specific destination/command proof.
- [x] Applied target `92/94`, UID00041W `92/93`, UID0003XP `92/94`, UID0004QZ `92/94`, UID0004R0 `92/93`, and UID0002RW `90/92`; retained all other accepted scores.
- [x] Preserved evidence-backed confidence caps for lexical spelling and raw-helper liveness while resolving every implementation blocker.
- [x] Retained target owner/emitter UID0000FQ and source root UID0000P1; registered UID0004QZ under Event.cpp UID0000J6 and UID0004R0 under MapPane.cpp UID0000L3.
- [x] Performed the UID-preserving target range rename, created/registered UID0004QZ and UID0004R0 serially before links, and retained the accepted no-target-split disposition.
- [x] Applied exact table attachment and source-route facts with no IDA mutation, padding change, or unsupported reclassification.
- [x] Applied exactly nine complete destination-specific managed blocks and verified each against the accepted report payload.
- [x] Confirmed third-party import is not applicable because every destination is NexusTK-owned source.
- [x] Incorporated target behavior, packets, fields, globals, lists, history, events, callers, boundaries, ownership, and source-shape facts at report-level detail.
- [x] Preserved historical/stale assumptions, rejected alternatives, and negative evidence in explicit sections and destination pages.
- [x] Preserved and classified Wave2/Wave3 material only as historical research guidance where encountered.
- [x] Closed all behavior/integration questions; retained only evidence-capped lexical uncertainty that does not block source reconstruction.
- [x] B001 ran one successful scoped validator for every changed ordinary page and final waited command `000000012593`; the supervisor later independently passed all 24 pages with commands `000000012669` through `000000012692`.
- [x] Verified the four-file supervisor command-`000000012692` checkpoint headers/hashes/assertions; separately recorded the later all-file command-`000000012699` evidence-time epoch and reconfirmed unchanged accepted assertions. Preserved the exact manual-coverage handoff as historical text; supervisor commands `000000012665` through `000000012668` applied and validated current coverage without B001 editing coverage files.

Implementation callback pass:
- [x] Exact accepted artifact and bounded same-report callback authority recorded.
- [x] All accepted target/support details incorporated without compressing the research record.
- [x] Every ledger row has a legal terminal state and separate claim-specific proof.
- [x] Metadata, score, owner/emitter, rename, registration, link, and nine formal-block changes applied or explicitly excluded with evidence.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved in current destinations and this report.
- [x] Open questions resolved or retained only as evidence-backed nonblocking lexical uncertainty.
- [x] All 25 historical B001 callback validator commands completed exit 0 / ok 1; all 24 fresh supervisor-owned post-callback commands passed and are separately recorded without attribution to B001.
- [x] Historical B001 waited refresh `000000012593` and supervisor waited checkpoint `000000012692` both have exact hashes, freshness, ordering, uniqueness, body, and stale-token assertions recorded above; later external command `000000012699` is separately timestamped without replacing the accepted checkpoint. Manual coverage remains supervisor-owned and its application/validation is complete under commands `000000012665` through `000000012668`.
- [x] No accepted callback item remains unapplied or blocked; zero B001 lease remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000012709","destination_path":"executed-b-agent-research/B001/0003U6-UserPaneProcessMovement-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0003U6-UserPaneProcessMovement-source-quality.md","timestamp":"2026-07-15T02:34:21-04:00","uid":"0003U6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
