** TARGET-REPORT-UID:0004CL **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0004CL ThreadProc Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0004CL] as the exact reconstructable `Thread::ThreadProc()` child at `0x00596810-0x00596915`, owned and emitted by [UID:0000OR] `by-file/Thread.md` through `NexusTK/util/Thread.cpp`.
- Current post-callback disposition: the ordinary documentation now contains the exact one-record-per-primary-wake worker loop and the applied `92/94` target score. The accepted `Thread` virtual declarations, Monitor/List field and API contracts, inherited Socket override names, padding/vtable evidence, support scores, and historical/generated-state corrections are also present in their current destinations.
- Completed ownership-separated closure: the primary supervisor record verifies Gate 2A C001-C057 `57/57`, manual C058-C067/M01-M10 `10/10`, IDA/protection C068-C078/A00-A17/P00-P12 `11/11`, and the combined ledger `78/78`. Generated command `000000020608` also completed the expected CPP/H/tracker refresh. B008 did not perform the supervisor-owned manual, IDA, generated, audit, catalog, or lifecycle work.
- Confidence: very strong for behavior, range, ABI, records, field offsets, queue selection, sync result protocol, stop timing, vtable order, owner, and emitter. Source-facing private names and `OnDispatchBegin`/`OnIdle` spellings are high-probability inferences because original symbols are absent.

## Supporting Research

- Fresh post-callback reread target artifact: `by-memory/0x00596810-0x00596915.ThreadProc.md`, SHA256 `ACDFB87FA487778F4F238541878E20C609CA687C69ABBC938FC9DDB3ED0D62E9`, 13,202 bytes, 224 lines; it contains the accepted `92/94` metadata and corrected formal CPP.
- Fresh post-callback reread direct support artifacts:
  - [UID:0000EV] `by-class/Thread.md`, SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`, 31,749 bytes, 337 lines; accepted Thread declaration/type/evidence changes are present.
  - [UID:0000OR] `by-file/Thread.md`, SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`, 46,114 bytes, 264 lines; accepted source route and worker correction are present.
  - [UID:0001JY] `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`, SHA256 `3E81DF27C842C74CE6B3D125C98E9F2008513CB78D8C8C5257125B1383F29719`, 31,176 bytes, 209 lines; accepted split-index behavior/API changes are present.
  - [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`, SHA256 `238BF52BEB6007A168B8B070584098699D0B790E9FE5B90B3C83015777A9D384`, 40,001 bytes, 203 lines; accepted exact-child correction is present while broad aggregate scope remains.
  - [UID:00026P] `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`, SHA256 `F152CD0A724908BB54C4E5E8D7A434B45CF90C9BD54EE13EBA522B7030D4A705`, 26,942 bytes, 177 lines; accepted complete vtable and score changes are present.
- Fresh post-callback reread derived-vtable and synchronization support artifacts:
  - [UID:0000DD] `by-class/Socket.md`, SHA256 `4ED2AEF3686E2A97863592637CF7ED8A58B62E73AB892E3AEF4FAE7B36200261`, 36,819 bytes, 308 lines; accepted `OnStart`/`OnIdle` override names are present.
  - [UID:0000NS] `by-file/Socket.md`, SHA256 `B01FD40C354C6AFD6BB2A96149DABD95B4B4CF9692603B5E55F71A079A4A4BED`, 26,544 bytes, 173 lines; accepted inherited virtual correction is present.
  - [UID:0001I1] `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`, SHA256 `32AD32505CA0093CE07D09A8DDCA4BBF6E206044AC135EB04B41C7DF77E88299`, 34,223 bytes, 206 lines; accepted method-table source spelling correction is present.
  - [UID:00026G] `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md`, SHA256 `EA433E1EF123FE45C4A603967AAC49F58671569FEDA1DC23640630B146B03371`, 18,343 bytes, 148 lines; accepted Socket vtable and score changes are present.
  - [UID:0000BX] `by-class/RequestSyncGate.md`, SHA256 `1DF95ABCC7D0342A46E7E81149561FADA15382641F1EDF314CBE4F9EC9D27392`, 11,240 bytes, 98 lines; accepted historical alias correction is present.
- API evidence artifacts:
  - [UID:000079] `by-class/List.md`, SHA256 `9C69E4F370A64A0F15217DB58D2A8BC74D62691DC088E6811EB6888421FD2011`.
  - [UID:0000KS] `by-file/List.md`, SHA256 `61A1347B4FB168105E191239D6EDAD585752FFE8530FCC24FDB087DF5E98E68E`.
  - `by-class/Monitor.md`, SHA256 `1226640750ED4FAF17B6BF51E0C70E937F3C60B4AB674D05072F648B502D5190`.
  - `by-file/Monitor.md`, SHA256 `900E2C1947C79B0E2E7EE406763D30BF71E7C1F6D9B0658DDEE43FCC1FC89B19`.
  - `by-class/RingBuffer.md`, SHA256 `73E86CA7675FDDDC061352D5C5A7684772DA93AE61FFDAC6E74F8839D602EA68`.
  - `by-file/RingBuffer.md`, SHA256 `22FE0FDA0BC4AD58DA5C213BDC8733AFD7B0599831395646D49FC383E96E3277`.
- Completed supervisor evidence: `b-report-validation-audit.md` primary Gate 2 record dated `2026-08-01T07:54:00-04:00` verifies `57/57 + 10/10 + 11/11 = 78/78`; IDA catalog entry `0394` records the complete transaction and post-save readback; authoritative saved IDB SHA256 is `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A`.
- Matching executed reports were used as historical leads, not accepted uncritically: B003 `0001JY-ThreadMessageDispatchHelpers-source-quality.md`, B013 `0000EV-Thread-class-source-quality.md`, B007 `0000OR-Thread-empty-emitter-family-source-quality.md`, and B006 `0000DD-Socket-class-source-quality.md`.
- Historical corrections from this pass: B003's and the current target's word `drains` is too broad; B013's `OnDispatchEnd` is too narrow; B006's `Socket::NoOpVirtualHook` and `Socket::PollAndReceive` cannot be the original override spellings because they occupy inherited `Thread` virtual slots.
- Lifecycle-neutral status: this report's execution/archive truth is authoritative only from its physical path plus validator-owned status/history metadata. The report body does not assert a lifecycle command state.

## Target

- Target UID: `0004CL`.
- Additional target UIDs: none. Support pages below are not declared as independently covered targets.
- Declared-target inventory: [UID:0004CL] `by-memory/0x00596810-0x00596915.ThreadProc.md`, exact source-bearing method child.
- Target path: `by-memory/0x00596810-0x00596915.ThreadProc.md`.
- Source queue/report provenance: command `000000020493` research tracker line 1683 reported pre-callback `88/88`, reconstructable true, and direct/additional/total B-report counts `0/0/0`.
- Current supervisor classification: ordinary implementation and the recorded supervisor Gate 2A/manual/IDA/protection/generated closure are complete at `78/78`. Report execution/archive/revalidation state remains external and authoritative only from the artifact's physical path and validator-owned history metadata.
- Current scores and parent state: target `92/94`; canonical owner/emitter [UID:0000OR]; reconstructable true; corrected formal CPP present; H blank by correct class-owner routing.

## Current Target State

- Accepted ordinary implementation is complete. [UID:0004CL] now has `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, blank optional position, and blank formal H.
- The target formal CPP now matches the accepted one-record worker loop: per-iteration `Sleep(1)`, exact wait routing, `OnDispatchBegin`, priority/default `IsEmpty` selection, one `Dequeue`, async/sync dispatch, caller-created result publication under `Monitor`, unlock-before-`SetEvent`, secondary `OnWaitObject`, and stop-before-`OnIdle`.
- [UID:0000EV] now emits the complete Thread declaration with `Monitor *m_resultMonitor`, exact records/fields, and all virtual slots from `OnStart` through `OnWaitObject`; [UID:0000OR] records the same source route and worker correction.
- [UID:0001JY], [UID:0001JX], [UID:00026P], [UID:0000DD], [UID:0000NS], [UID:0001I1], [UID:00026G], and [UID:0000BX] contain the accepted support corrections without duplicate aggregate/vtable/alias emission.
- Accepted existing APIs were physically rechecked without edits: `RingBuffer::IsEmpty`/`Dequeue`, inline `List::GetCount`, virtual `List::GetElementAt`, and `Monitor::Lock`/`Unlock`.
- Generated command `000000020493` is retained only as dated pre-repair documentation-state evidence. Later supervisor command `000000020608` completed generated refresh: one UID0004CL definition at `92/94` is present in generated `Thread.cpp`, generated `Thread.h` has the single `virtual int ThreadProc();` declaration, UID0004CL has no empty-emitter marker, generated memory coverage marks it coded to UID0000OR, and the tracker row is `92/94`.
- Historical callback authorization: Gate 1 accepted exact pre-callback report SHA256 `050FB3F9FAA9F3BE6806C167C1C5FEF803F2E58A067B4F8663695EF7E9D68148` at `33/33`; the later primary supervisor record closed all 78 claims. Current report execution/archive/revalidation truth is authoritative only from this artifact's physical state and validator-owned history.

## Executive Recommendation

- Keep direct owner [UID:0000OR] `Thread.cpp`; no new source file, split, merge, or no-owner route is justified.
- Keep [UID:0004CL] as the exact method child; its CPP now contains the implementation in this report.
- Applied scores are [UID:0004CL] `92/94`, [UID:0000EV] `93/94`, [UID:0000OR] `92/93`, [UID:0001JY] `90/92`, and [UID:00026P] `90/93`.
- Preserve [UID:0001JX] as the broad reconstructable aggregate at `88/89`; this pass does not make the entire Thread/ThreadMan island exact.
- Socket's inherited slot declarations are corrected to `Socket::OnStart()` and `Socket::OnIdle()`, with `PollAndReceive` preserved as a descriptive behavior/search alias rather than source spelling.
- The primary supervisor completed the bounded IDA handoff and saved/read back the result: three UDTs, target/support identities, frame aggregation, durable locals, and comments are applied; A08 is safely `ATTEMPTED_NOT_DURABLE` presentation-only; folded base no-ops, vtables, padding, RingBuffer functions, and every P00-P12 dependency remain protected.

## Supervisor Active Recheck

- The triggering instruction required a fresh report-only pass for UID0004CL with mandatory live IDA MCP and explicit resolution of queue/vtable/type/source-shape blockers.
- Resume recheck on 2026-08-01 used a new read-only MCP transport session `c87126a2-da3c-47f6-b70f-7cb99198cd06` against the same live database session `f608d7c2`. `initialize`, `tools/list` (70 current tools), `idb_list`, `server_health`, bounded `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `xrefs_to`, `callees`, `get_bytes`, `get_comments`, `stack_frame`, and `type_query` all returned successfully; no fallback evidence was used.
- The resumed live pass reconfirmed `sub_596810` at `[0x00596810,0x00596915)` as 261 bytes, 99 instructions, 20 basic blocks, cyclomatic complexity 11, with no direct caller and the same five data/vtable xrefs. It also reconfirmed the single `RingBuffer_Dequeue`, caller-created result-entry scan/write, unsigned secondary-index bound, stop-before-slot-`+0x28` order, eleven-byte `0xCC` boundary runs, unchanged entry comment channels, and unchanged raw Thread/Socket vtable cells.
- Gate 1 repair recheck used read-only MCP transport `939408a9-e062-479a-9811-e25765433243`. Database session `f608d7c2` rolled over while schemas were being inspected; `idb_list` immediately exposed replacement active session `b3b2bf88`, whose health was `status:ok` with auto-analysis, Hex-Rays, and strings ready. Fresh `stack_frame`, `decompile`, `get_comments`, `search_structs`, and `type_inspect` on `b3b2bf88` reconfirmed the exact A04 prestate and absence of `Thread`, `ThreadMessage`, and `ThreadResultEntry` UDTs. No mutation or save was attempted.
- The target did not require another split: the exact child range already matches the modeled function and eleven-byte padding on each side.
- Every source-bearing item needed for this method is either present as an existing exact child/API or has a concrete target/support recommendation. No required helper is deferred with only `needs investigation` wording.
- The wider [UID:0001JX] aggregate remains broader than this target; its unrelated ThreadMan/raw-wrapper debt is outside this report and does not block exact UID0004CL source.
- Supervisor authorized the ordinary implementation callback for exact accepted SHA256 `050FB3F9FAA9F3BE6806C167C1C5FEF803F2E58A067B4F8663695EF7E9D68148` after Gate 1 passed `33/33`. B008 applied only C001-C056 ordinary-document work, used no IDA mutation/save/control, manual coverage, generated refresh, audit/catalog/lifecycle action, subagent, or `execute_report` path, and left C058-C078 in their supervisor-owned lanes.
- Later primary supervisor closure, not B008 action, completed those lanes: C058-C067 manual `10/10`, C068-C078 IDA/protection `11/11`, generated command `000000020608`, and combined C001-C078 `78/78`.

## Inference Research Guidance Check

- Binary behavior was treated as authoritative over current generated C++ and older prose.
- Existing terms `drains`, `RequestSyncGate`, `OnDispatchEnd`, `NoOpVirtualHook`, and `PollAndReceive` were treated as uncertain source-shape inferences and retested.
- Direct IDA facts: instruction order, fields, record layout, call signatures, xrefs, vtable cell values, padding bytes, type catalog, comments, and frames.
- Documentation evidence: class/file ownership, accepted List/RingBuffer/Monitor APIs, source route, and prior report hypotheses.
- Inference: human source names for private members and the five missing virtual hooks. These are chosen from call timing, derived overrides, project naming style, and late-1990s/mid-2000s C++ conventions.
- Wave2/Wave3 labels found in old Socket documentation were ignored as stale ownership/source authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| Queue drain order | Decompiler and semaphore producer were checked together. A producer enqueues once and releases once; `ThreadProc` performs one `Dequeue` after choosing one queue. | One record per primary wake. Priority queue is selected first; default queue is fallback. Reject a drain loop. |
| Queue API spelling | IDA already names `RingBuffer_IsEmpty` and `RingBuffer_Dequeue`; current RingBuffer formal H declares `bool IsEmpty() const` and `void Dequeue(void *)`. | Use `IsEmpty`/`Dequeue`; reject `Pop`. |
| Result entry ownership | `DispatchRequestAndReturnEvent` creates/registers the list entry before queueing. `ThreadProc` only searches for a matching event and writes `entry->result`. | Reject constructing or appending a new entry in `ThreadProc`. |
| Synchronization type | IDA ordinal 557 is exact 16-byte `Monitor`; `0x528710/0x528720` are accepted `Monitor::Lock`/`Unlock`; no separate RequestSyncGate vtable/constructor exists. | Use `Monitor *m_resultMonitor`; retain RequestSyncGate only as historical alias. |
| List API | `List` formal H has inline `GetCount()` and virtual `GetElementAt(int)`; direct `+0x0c` count read is expected inlining; target calls vtable `+0x10`. | Use `GetCount` and `GetElementAt`; reject `GetAt`. |
| Hook `+0x14` | `StartThread` calls it before `ResumeThread`; Socket uniquely overrides with an empty one-byte function. | `OnStart` is the strongest human source name; `Socket::OnStart()` is an empty override. |
| Hooks `+0x18/+0x20` | `ThreadEntry` calls them immediately before and after `ThreadProc`. | `OnThreadBegin` and `OnThreadEnd` remain strongest names. |
| Hook `+0x24` | Called only on primary semaphore wake, before queue selection; base and observed derived entries are folded no-op. | Retain prior high-probability `OnDispatchBegin`. |
| Hook `+0x28` | Called after every completed wait iteration unless stop is set, including timeout/failure and secondary-handle paths. Socket override performs nonblocking receive polling. | Use `OnIdle`; reject `OnDispatchEnd` as semantically too narrow and `PollAndReceive` as derived behavior rather than shared virtual spelling. |
| Secondary callback | Nonzero wait result below signed handle count is passed directly to slot `+0x34`; Socket override uses index 1. | `OnWaitObject(int waitIndex)` remains correct. |
| Stop timing | Stop byte is tested after every wait/dispatch path and before slot `+0x28`. | Return `0` immediately when set; do not call `OnIdle` on the stopping iteration. |
| Source placement | All base Thread construction, queue APIs, handlers, target vtable, and ThreadMan companion code route through UID0000OR. | `NexusTK/util/Thread.cpp` and `Thread.h`; reject Socket/CashShop ownership. |
| Original symbols | No original target/type symbols survive. | Use consistent project source names; do not retain `sub_596810`, `v2`, `v3`, or raw offset expressions in final source. |

Rejected alternatives:

- `while (queue->Pop(...))`: contradicts one dequeue and one semaphore release per message.
- `ThreadResultEntry entry; m_resultList->Add(&entry)`: contradicts the scan/write protocol and caller-created result record.
- `OnDispatchEnd`: contradicted by timeout/secondary-handle call paths.
- `Socket::PollAndReceive` as a virtual declaration: cannot override a base method under a different name in C++ source.
- `RequestSyncGate`: contradicted as a distinct class by current Monitor ownership and absent independent construction/vtable evidence.
- CashShopRequest/Socket ownership: target is shared by five Thread-family vtables and has no direct callers.

No implementation blocker remains. Exact original private/member spellings cannot be proven, but the selected names are high-probability, human, consistent, and do not justify leaving decompiler labels.

## Evidence Standards Used

- Historical B008 read-only MCP sessions `f608d7c2` and replacement `b3b2bf88`: health, `lookup_funcs`, `get_comments`, `stack_frame`, `inspect_items`, `get_bytes`, `decompile`, `analyze_function`, `search_structs`, `type_inspect`, and `type_query`; mutation schemas were read but never called by B008.
- Binary evidence ladder: exact bytes/range, modeled function and frame, direct callees, virtual calls, data xrefs, vtable cell bytes, derived override behavior, caller-side record lifecycle, and negative collision/type checks.
- Documentation evidence: exact by-memory child, class/file formal blocks, accepted container/synchronization source APIs, generated CPP/H, manual coverage, tracker, and matching executed reports.
- Historical pre-Gate2 negative evidence: no target direct code callers; no pre-existing Thread/ThreadMessage/ThreadResultEntry IDA types; no proposed function-name collisions; no second dequeue/add-entry call; no separate RequestSyncGate construction/vtable. The three missing types were subsequently created and verified by the primary supervisor; the other negative facts remain unchanged.
- Final supervisor evidence: catalog entry `0394`, saved IDB SHA256 `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A`, post-save type/function/frame/local/comment readback, P00-P12 preservation, manual commands `000000020605`-`000000020607`, and generated command `000000020608`.
- Evidence is strong enough for exact behavior and ABI. Confidence remains below 95 only because original private/hook spellings are inferred.

## Evidence Checked

- Historical pre-Gate2 IDA MCP/manual-disassembly/raw-byte checks:
  - `sub_596810`, exact `[0x596810,0x596915)`, 261 bytes, prototype `int __thiscall(char *this)`, full decompile, stack frame, all four function/address comment channels, five vtable refs, and target padding.
  - Base Thread vtable and FileDownloader, MiniMapDownloader, MiscWorkThread, and Socket vtables, all 14 slots.
  - `RingBuffer_Dequeue`, `RingBuffer_IsEmpty`, `sub_4F32B0`, `sub_528710`, `sub_528720`, `nullsub_53`, `sub_575DA0`, folded `@_guard_check_icall_nop@4`, and `nullsub_17`.
  - Prestate IDA types: RingBuffer ordinal 559 size 40, Monitor ordinal 557 size 16, List ordinal 485 incomplete, Socket ordinal 688 incomplete, and no Thread/ThreadMessage/ThreadResultEntry types.
- Historical A04 frame-repair evidence: pre-Gate2 `stack_frame` returned `record +0x0c`, `var_18 +0x10`, `var_14 +0x14`, `hEvent +0x18`, `var_C +0x1c`, `var_8 +0x20`, and separate `var_4 +0x24`, each size four; decompilation mapped those to `[ebp-0x1c]` through `[ebp-0x04]`. The schemas exposed `delete_stack`, `declare_stack`, `force_recompile`, `stack_frame`, and `decompile`, but no transaction/dry-run or guaranteed Hex-Rays aggregate-lvar presentation.
- Historical supervisor catalog evidence was checked only for MCP stack-tool semantics: prior unsaved attempts prove `declare_stack.offset` is a frame-pointer displacement, not the positive frame offset reported by `stack_frame`; using `+0x0c` can create duplicate out-of-frame members. Therefore A04 uses `-0x1c`, requires a no-save rollback guard, and forbids exploratory alternate offsets.
- Docs/reports checked: target, Thread class/file/aggregate/rdata, Socket class/file/core/rdata, List/Monitor/RingBuffer class/file pages, B003/B006/B007/B013 reports, generated Thread.cpp/Thread.h, manual coverage, research tracker, and generated memory coverage.
- Negative checks: target name collisions, proposed support-name collisions, direct caller absence, raw start/end boundary items, and invalid alternative source ownership.
- Failed/unavailable checks: none after MCP recovery. `auto_analysis_ready:false` remained informational because bounded valid IDB-backed calls returned successfully.
- Final primary-supervisor readback: exact UDTs, functions, comments, frame aggregation, durable locals, protected dependencies, and saved authority are recorded in catalog entry `0394`; A08 alone is presentation-only `ATTEMPTED_NOT_DURABLE`, without semantic/type/body impact.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0004CL | Set completion to 92. | very-strong | Exact body and blockers resolved. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / metadata | incorporate | applied |
| C002 | 0004CL | Set confidence to 94. | very-strong | Exact control flow, ABI, vtables, APIs, and boundaries. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / metadata | incorporate | applied |
| C003 | 0004CL | Preserve canonical owner 0000OR. | very-strong | Shared Thread vtables and file route. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / metadata | already-present | verified |
| C004 | 0004CL | Preserve emitter 0000OR and reconstructable true. | very-strong | Exact source method, not generated-only data. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / metadata | already-present | verified |
| C005 | 0004CL | Replace formal CPP with the exact one-record worker loop in this report. | very-strong | Decompiled and byte/vtable corroborated. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / `RECONSTRUCTION_CPP` | incorporate | applied |
| C006 | 0004CL | Keep formal H blank because UID0000EV owns the declaration. | very-strong | Existing owner/emitter route. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / `RECONSTRUCTION_H` | already-present | verified |
| C007 | 0004CL | Sleep(1) occurs at the start of every loop iteration. | very-strong | Call at 0x596822 on loop backedge. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C008 | 0004CL | Wait uses signed-byte count +0x08, handle array +0x0c, waitAll false, timeout +0x04. | very-strong | Exact call setup/decompile. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C009 | 0004CL | Primary wake calls virtual +0x24 before queue selection. | very-strong | Indirect call at 0x596847. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C010 | 0004CL | Priority queue +0x50 is selected first when nonempty. | very-strong | IsEmpty/cmov branch at 0x59684d-0x596856. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C011 | 0004CL | Default queue +0x4c is selected only when priority is empty. | very-strong | Second IsEmpty branch at 0x59685e-0x59686b. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C012 | 0004CL | Exactly one 24-byte ThreadMessage is dequeued per primary wake. | very-strong | Single Dequeue call and producer semaphore count. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C013 | 0004CL | Null resultEvent dispatches OnMessage(messageId,arg1,arg2). | very-strong | Vslot +0x2c call. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C014 | 0004CL | Non-null resultEvent dispatches OnMessageEx(messageId,syncArg1,syncArg2,arg1,arg2). | very-strong | Vslot +0x30 call and record offsets. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Behavior | incorporate | applied |
| C015 | 0004CL | ThreadProc searches an already-created result entry and writes only its result field. | very-strong | List scan and caller-side creation. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Sync result protocol | incorporate | applied |
| C016 | 0004CL | Monitor +0x54 guards the result-list scan/write. | very-strong | Lock/unlock calls and Monitor layout. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Sync result protocol | incorporate | applied |
| C017 | 0004CL | SetEvent runs after unlock even if no matching entry was found. | very-strong | Shared post-loop SetEvent path. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Sync result protocol | incorporate | applied |
| C018 | 0004CL | Nonzero wait result below handle count calls OnWaitObject(waitIndex). | very-strong | Unsigned branch and vslot +0x34. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Wait routing | incorporate | applied |
| C019 | 0004CL | Stop byte +0x64 returns 0 before the final loop hook. | very-strong | Test at 0x5968fa and return at 0x59690c. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Stop behavior | incorporate | applied |
| C020 | 0004CL | Vslot +0x28 runs after every non-stopping wait iteration and is best named OnIdle. | strong | Call at 0x596904 and Socket polling override. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Virtual hooks | incorporate | applied |
| C021 | 0004CL | Target has no direct code caller and is reached through five vtable cells. | very-strong | xrefs at 0x60d7c4, 0x6106ec, 0x61fb90, 0x624f3c, 0x62e288. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Evidence | incorporate | applied |
| C022 | 0004CL | Preserve exact 0x105 function range. | very-strong | Modeled function and bytes. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Address Range | already-present | verified |
| C023 | 0004CL | Preserve eleven 0xCC bytes before and after the function as padding. | very-strong | get_bytes/inspect_items. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Boundaries | incorporate | applied |
| C024 | 0004CL | Historicalize the claim that ThreadProc drains both queues. | very-strong | Single Dequeue and one-release producer. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Historical assumptions | historicalize | applied |
| C025 | 0004CL | Reject the stale new-result-entry append in current CPP. | very-strong | Existing entry scan/write behavior. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Historical assumptions | reject-stale | applied |
| C026 | 0000EV | Add OnStart, OnThreadBegin, OnThreadEnd, OnDispatchBegin, and OnIdle in exact vtable order. | strong | StartThread, ThreadEntry, ThreadProc, and derived vtables. | `by-class/Thread.md` / formal H | incorporate | applied |
| C027 | 0000EV | Preserve exact 24-byte ThreadMessage declaration. | very-strong | Stack record and producer/consumer field order. | `by-class/Thread.md` / formal H | already-present | verified |
| C028 | 0000EV | Preserve exact 8-byte ThreadResultEntry declaration. | very-strong | List element size and event/result accesses. | `by-class/Thread.md` / formal H | already-present | verified |
| C029 | 0000EV | Preserve fields and offsets +0x04 through +0x64. | very-strong | Constructor, worker, handlers, and UDT proposal. | `by-class/Thread.md` / Field And Record Layout | incorporate | applied |
| C030 | 0000EV | Replace RequestSyncGate pointer with Monitor *m_resultMonitor. | very-strong | Monitor ordinal 557 and accepted Lock/Unlock ownership. | `by-class/Thread.md` / formal H | incorporate | applied |
| C031 | 0000EV | Record inline GetCount and virtual GetElementAt use. | very-strong | Direct +0x0c count and vslot +0x10. | `by-class/Thread.md` / Evidence | incorporate | applied |
| C032 | 0000EV | Raise class score to 93/94. | strong | Complete virtual order and exact target body. | `by-class/Thread.md` / metadata | incorporate | applied |
| C033 | 0000EV | Historicalize unresolved final virtual-slot spelling caveat as resolved high-probability source names. | strong | Derived override/timing reanalysis. | `by-class/Thread.md` / Historical assumptions | historicalize | applied |
| C034 | 0000OR | Preserve util/Thread.cpp and Thread.h placement. | very-strong | Complete family and generated route. | `by-file/Thread.md` / source placement | already-present | verified |
| C035 | 0000OR | Raise file score to 92/93 and record exact target correction. | strong | Source-ready Thread body/header. | `by-file/Thread.md` / score and changes | incorporate | applied |
| C036 | 0001JY | Replace drain/new-entry/API caveats with one-record, Monitor, GetElementAt facts. | very-strong | Live target and support APIs. | `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` / child index | incorporate | applied |
| C037 | 0001JY | Raise split-index score to 90/92 while preserving non-emitting status. | strong | Exact children and resolved target caveats. | `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` / metadata | incorporate | applied |
| C038 | 0001JX | Record UID0004CL exact-child correction without emitting aggregate code. | strong | Existing child split and broad aggregate role. | `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` / inventory | incorporate | applied |
| C039 | 0001JX | Preserve aggregate score 88/89. | strong | Unrelated wider ThreadMan/raw debt remains. | `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` / metadata | already-present | verified |
| C040 | 00026P | Expand Thread vtable table to all slots 0-13 and exact cell values. | very-strong | 56-byte vtable readback. | `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` / Thread Vtable Slot Names | incorporate | applied |
| C041 | 00026P | Replace OnDispatchEnd caveat with OnIdle and explain derived Socket evidence. | strong | Worker call timing and 0x575da0. | `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` / Thread Vtable Slot Names | incorporate | applied |
| C042 | 00026P | Raise rdata page to 90/93. | strong | Fresh live full vtable and boundary readback. | `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` / metadata | incorporate | applied |
| C043 | 0000DD | Rename formal Socket override NoOpVirtualHook to OnStart. | strong | Slot +0x14 inherited position and StartThread call. | `by-class/Socket.md` / formal CPP declaration | incorporate | applied |
| C044 | 0000DD | Rename formal Socket override PollAndReceive to OnIdle. | strong | Slot +0x28 inherited position and per-loop poll behavior. | `by-class/Socket.md` / formal CPP declaration | incorporate | applied |
| C045 | 0000DD | Record inherited Thread virtual contract and preserve PollAndReceive as behavior alias only. | strong | Base/Socket vtable comparison. | `by-class/Socket.md` / Vtable Findings | incorporate | applied |
| C046 | 0000DD | Raise Socket class score to 91/92. | strong | Fresh exact inherited-slot correction. | `by-class/Socket.md` / metadata | incorporate | applied |
| C047 | 0000NS | Record override-name correction and set file score 90/91. | strong | Existing source route plus vtable correction. | `by-file/Socket.md` / source inventory | incorporate | applied |
| C048 | 0001I1 | Replace NoOpVirtualHook/PollAndReceive source spellings with OnStart/OnIdle and aliases. | strong | Slot inheritance proof. | `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md` / method table | incorporate | applied |
| C049 | 00026G | Correct Socket vtable slot names and raise score to 89/93. | strong | Fresh exact vtable bytes. | `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md` / vtable table and metadata | incorporate | applied |
| C050 | 000079 | Use existing List::GetElementAt and inline GetCount source APIs. | very-strong | Formal H and exact child UID0003JW. | `by-class/List.md` / method inventory | already-present | verified |
| C051 | 0000KS | Preserve List.cpp ownership of GetElementAt. | very-strong | Existing exact source route. | `by-file/List.md` / child inventory | already-present | verified |
| C052 | 0000BX | Reject RequestSyncGate as a separate Thread field type. | very-strong | No independent vtable/constructor; Monitor owns functions. | `by-class/RequestSyncGate.md` / historical alias | historicalize | applied |
| C053 | 0000EV | Use accepted Monitor::Lock/Unlock ownership for the field contract. | very-strong | Monitor docs and live functions. | `by-class/Thread.md` / synchronization evidence | incorporate | applied |
| C054 | 0000EV | Use existing RingBuffer::IsEmpty/Dequeue API names. | very-strong | IDA and formal RingBuffer H. | `by-class/Thread.md` / queue evidence | incorporate | applied |
| C055 | 0004CL | Record command20493 generated Thread.cpp as stale behavior evidence. | very-strong | Current generated body differs from binary. | `by-memory/0x00596810-0x00596915.ThreadProc.md` / Generated state | historicalize | applied |
| C056 | 0000EV | Expect regenerated Thread.h to include hooks and Monitor, with no RequestSyncGate. | strong | Exact formal H recommendation. | `by-class/Thread.md` / generated expectations | incorporate | applied |
| C057 | 0004CL | Preserve tracker fact 0/0/0 solely as dated assignment provenance, never as current coverage authority. | very-strong | Command20493 line1683 and current lifecycle-neutral Target wording. | `tools/leaser/Agents/Agent-B008/research/0004CL-ThreadProc-source-quality.md` / Target | already-present | verified |
| C058 | 0004CL | Supervisor inserted the exact by-memory manual coverage row at 92%. | very-strong | Primary Gate 2 manual closure and validator `000000020605`. | `by-memory/-coverage-report.md` / UID0004CL row | incorporate | applied |
| C059 | 0001JX | Supervisor replaced the by-memory manual row at 88%. | very-strong | Primary Gate 2 manual closure and validator `000000020605`. | `by-memory/-coverage-report.md` / UID0001JX row | incorporate | applied |
| C060 | 0001JY | Supervisor replaced the by-memory manual row at 90%. | very-strong | Primary Gate 2 manual closure and validator `000000020605`. | `by-memory/-coverage-report.md` / UID0001JY row | incorporate | applied |
| C061 | 00026P | Supervisor replaced the by-memory manual row with corrected bounds and 90%. | very-strong | Primary Gate 2 manual closure and validator `000000020605`. | `by-memory/-coverage-report.md` / UID00026P row | incorporate | applied |
| C062 | 0001I1 | Supervisor replaced the by-memory manual row at current bounds/88%. | very-strong | Primary Gate 2 manual closure and validator `000000020605`. | `by-memory/-coverage-report.md` / UID0001I1 row | incorporate | applied |
| C063 | 00026G | Supervisor replaced the by-memory manual row at 89%. | very-strong | Primary Gate 2 manual closure and validator `000000020605`. | `by-memory/-coverage-report.md` / UID00026G row | incorporate | applied |
| C064 | 0000EV | Supervisor replaced the by-class manual row at 93%. | very-strong | Primary Gate 2 manual closure and validator `000000020606`. | `by-class/-coverage-report.md` / UID0000EV row | incorporate | applied |
| C065 | 0000DD | Supervisor replaced the by-class manual row at 91%. | strong | Primary Gate 2 manual closure and validator `000000020606`. | `by-class/-coverage-report.md` / UID0000DD row | incorporate | applied |
| C066 | 0000OR | Supervisor replaced the by-file manual row at 92%. | very-strong | Primary Gate 2 manual closure and validator `000000020607`. | `by-file/-coverage-report.md` / UID0000OR row | incorporate | applied |
| C067 | 0000NS | Supervisor replaced the by-file manual row at 90%. | strong | Primary Gate 2 manual closure and validator `000000020607`. | `by-file/-coverage-report.md` / UID0000NS row | incorporate | applied |
| C068 | 0004CL | Supervisor created and post-save verified exact 0x68/13-member Thread UDT. | very-strong | Primary Gate 2B and catalog entry 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C069 | 0004CL | Supervisor created and post-save verified exact 0x18/6-member ThreadMessage UDT. | very-strong | Primary Gate 2B and catalog entry 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C070 | 0004CL | Supervisor created and post-save verified exact 0x08/2-member ThreadResultEntry UDT. | very-strong | Primary Gate 2B and catalog entry 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C071 | 0004CL | Supervisor renamed/typed/commented target as Thread_ThreadProc and applied every durable A05-A12 local result; A08 `v6 -> result` is safely attempted-not-durable presentation-only. | very-strong | Primary Gate 2B post-save function/local/comment readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C072 | 0004CL | Supervisor consolidated the six scalar frame members into one durable `message +0x0c/0x18/struct ThreadMessage`, preserving `var_4` and compiler rows. | very-strong | Primary Gate 2B post-save frame/decompiler readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C073 | 0003JW | Supervisor renamed/typed/commented `0x4f32b0` as List_GetElementAt and verified argument `index`. | very-strong | Primary Gate 2B post-save readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C074 | 0001CL | Supervisor renamed/typed/commented `0x528710` as Monitor_Lock with protected internal comments intact. | very-strong | Primary Gate 2B post-save readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C075 | 0001CL | Supervisor renamed/typed/commented `0x528720` as Monitor_Unlock with protected internal comments intact. | very-strong | Primary Gate 2B post-save readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C076 | 0000DD | Supervisor renamed/typed/commented `0x575d90` as Socket_OnStart. | strong | Primary Gate 2B post-save readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C077 | 0000DD | Supervisor renamed/typed/commented `0x575da0` as Socket_OnIdle and verified durable local `transportMode`. | strong | Primary Gate 2B post-save readback and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | incorporate | applied |
| C078 | 0004CL | Supervisor verified folded no-op bodies, exact vtable cells, RingBuffer functions, List cell, Monitor UDT, comments, bounds, xrefs, bytes, and padding unchanged. | very-strong | Primary Gate 2B P00-P12 `PASS` and catalog 0394. | `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` / 0394 | already-present | verified |

## Positive Evidence Summary

- The exact target is a modeled 0x105-byte function bounded by 11-byte `0xCC` runs.
- Five vtables point to the exact start at the same inherited slot `+0x1c`.
- The decompile, raw bytes, producer behavior, and RingBuffer API prove one dequeue per semaphore wake.
- The 24-byte stack record exactly matches both producer packing and current ThreadMessage formal layout.
- The result-event path exactly matches the caller-created 8-byte result-list record protocol.
- Current List, RingBuffer, and Monitor docs independently establish every API needed by human source.
- Socket's unique `+0x28` override proves the base hook is a per-loop idle hook and rejects `OnDispatchEnd`.
- Thread's source owner and generated route are already stable; this is a source-quality correction, not an ownership guess.

## IDA MCP Facts

- Historical B008 read-only prestate sessions: initial transport `b628ef3f-1184-4e54-9b09-f69ea514830c`, first resume `c87126a2-da3c-47f6-b70f-7cb99198cd06`, and Gate 1 repair `939408a9-e062-479a-9811-e25765433243`. Database `f608d7c2` rolled over during schema inspection; replacement `b3b2bf88` reconfirmed the literal prestates below. Health was `status:ok`; `auto_analysis_ready:false` did not block bounded reads.
- Historical disk/prestate identities: the initial report recorded saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`; the immediate supervisor transaction prestate was later SHA256 `E32FB8316846E8BA7B8D83CF40609323E24F79698A8710A38CDFE4CE6B625BC4`, 143,192,987 bytes. Neither hash is the final saved authority.
- Historical function/type/comment prestate: `0x596810` was `sub_596810`, size `0x105`, declaration `int __thiscall(char *this)`, with 99 instructions, 20 basic blocks, complexity 11, absent entry address/function comments, generic target/support names, and absent `Thread`, `ThreadMessage`, and `ThreadResultEntry` UDTs.
- Historical frame/local prestate: six scalar message rows `record`, `var_18`, `var_14`, `hEvent`, `var_C`, and `var_8` occupied physical `[ebp-0x1c]` through `[ebp-0x08]`; independent `var_4 [ebp-0x04]` and compiler rows followed. Decompiler locals were generic `v2`-`v10` forms itemized in A05-A12.
- Final saved authority from primary supervisor catalog entry `0394`: `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`, SHA256 `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A`, 143,193,372 bytes, last write `2026-08-01T07:52:08-04:00`; one `idb_save` returned `ok:true`, followed by successful post-save health/type/frame/function/comment/decompile readback.
- Final types: `Thread` is exactly `0x68`/104 bytes with 13 members; `ThreadMessage` is exactly `0x18`/24 bytes with six members; `ThreadResultEntry` is exactly `0x08`/8 bytes with two members. Offsets are exact; IDA normalized byte spellings to `signed/unsigned __int8` and frame display to `struct ThreadMessage`.
- Final target/support functions: `0x00596810` is `Thread_ThreadProc`, `int __thiscall(Thread *this)`; `0x004f32b0` is `List_GetElementAt`, `void *__thiscall(List *this, int index)`; `0x00528710/0x00528720` are typed `Monitor_Lock/Monitor_Unlock`; `0x00575d90/0x00575da0` are typed `Socket_OnStart/Socket_OnIdle`. All six regular/repeatable function comments read back exactly and pre-existing address/internal comments remain unchanged.
- Final frame: the six old scalar rows are absent; one `message +0x0c/0x18/struct ThreadMessage` row remains and exposes all six aggregate fields. `var_4 +0x24`, `__saved_registers +0x28`, and `__return_address +0x2c` remain exact; instruction comments `record` and `hEvent` remain unchanged.
- Final durable locals: `const HANDLE *waitHandles`, `DWORD waitIndex`, `RingBuffer *queue`, `Monitor *resultMonitor`, `int resultIndex`, `int resultCount`, `ThreadResultEntry *resultEntry`, List argument `index`, and Socket local `transportMode`. A08's register-only `v6 -> result` rename was attempted twice, but fresh Hex-Rays recompilation regenerated `v6` and supported local typing rejected it; final disposition is safe `ATTEMPTED_NOT_DURABLE`, presentation-only, with no unstable workaround.
- Final protected readback: target remains `[0x00596810,0x00596915)` with the same 261 bytes and five data/vtable xrefs; both eleven-byte `CC` fences, all five vtable pointers, shared `0x0041b6a0/0x0041b6b0`, accepted RingBuffer functions, List vtable cell, Monitor UDT, internal comments, bounds, and xrefs remain unchanged.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x596805-0x596810` | parent padding | predecessor alignment | no source body | UID0001JY | n/a | preserve 11 CC bytes |
| `0x596810-0x596915` | UID0004CL target | `Thread::ThreadProc()` | true | UID0000OR | 88/88 -> 92/94 | exact source body |
| `0x596915-0x596920` | parent padding | successor alignment | no source body | UID0001JY | n/a | preserve 11 CC bytes |
| `0x596920-0x596931` | neighboring UID0004CM | `Thread::OnMessage` | true | UID0000OR | existing | excluded from body edits |
| `0x596940-0x59695e` | neighboring UID0004CN | `Thread::OnMessageEx` | true | UID0000OR | existing | excluded from body edits |
| `0x62e26c-0x62e2a4` | UID00026P | compiler-generated Thread vtable | through declarations | UID0000OR | 87/91 -> 90/93 | support update |
| `0x575d90-0x575d91` | UID0001I1 support | `Socket::OnStart` empty override | source method | UID0000NS | aggregate 88/92 | rename support |
| `0x575da0-0x575e5b` | UID0001I1 support | `Socket::OnIdle` polling override | source method | UID0000NS | aggregate 88/92 | rename support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x62e288` | Thread vtable slot `+0x1c` -> `0x596810` | Base virtual owner. |
| `0x60d7c4` | FileDownloader vtable slot `+0x1c` -> `0x596810` | Inherited target. |
| `0x6106ec` | MiniMapDownloader vtable slot `+0x1c` -> `0x596810` | Inherited target. |
| `0x61fb90` | MiscWorkThread vtable slot `+0x1c` -> `0x596810` | Inherited target. |
| `0x624f3c` | Socket vtable slot `+0x1c` -> `0x596810` | Inherited target. |
| `0x596822` | `Sleep(1)` | Per-iteration throttle. |
| `0x596839` | `WaitForMultipleObjects` | Primary/secondary wait dispatch. |
| `0x59684d`, `0x59685e` | `RingBuffer_IsEmpty` | Priority then default queue selection. |
| `0x596872` | `RingBuffer_Dequeue` | Exactly one record. |
| `0x5968a1`, `0x5968d2` | Monitor lock/unlock helpers | Result-list critical section. |
| `0x61ce3c` | List vtable slot `+0x10` -> `0x4f32b0` | `GetElementAt`. |
| `0x5968da` | `SetEvent` | Wake synchronous caller after result publication attempt. |
| `0x624f34` | Socket vtable slot `+0x14` -> `0x575d90` | Empty `OnStart` override. |
| `0x624f48` | Socket vtable slot `+0x28` -> `0x575da0` | Nonblocking `OnIdle` override. |

## Documentation Evidence And IDA Status

- Historical pre-repair documentation state: before the ordinary callback, the target/generated source was materially wrong in loop timing, dequeue count, result handling, and hook calls; Thread docs retained the RequestSyncGate alias and omitted five virtual declarations; Thread rdata had partial slot names; Socket docs exposed behavior aliases as override names. These defects are dated evidence, not current conditions.
- Historical generated command `000000020493`, refreshed `2026-07-31T10:40:09-04:00`:
  - `auto-generated/NexusTK/util/Thread.cpp` SHA256 `1C0179E5099E00BFDBB5B7D1776878DD9EADE0D6DEF23AA62E9DBF25B53EFE93`, 13,096 bytes, 410 lines.
  - `auto-generated/NexusTK/util/Thread.h` SHA256 `0F632951B2547EF183578B48310B5EC15C71731EEE909876A2DBC9D100C5C287`, 1,972 bytes, 76 lines.
  - Tracker SHA256 `13F74CBAA11133CF1CE2F061C0A9E27A70E6D18A57C7770A4F800F777AB7EDBE`, 1,690,672 bytes, 6,676 lines; target line 1683.
  - Generated memory coverage SHA256 `AA9079AB934EE980C004BB3A767E2E453F290345BE957FD0EE973C157FDA8C36`, 1,430,860 bytes, 4,985 lines; target line 2392 is coded to UID0000OR.
- Current corrected ordinary state: target, Thread, Thread rdata, Socket, aggregate, and RequestSyncGate-alias pages contain the accepted report-level changes recorded in `Changed Files`; List/RingBuffer/Monitor APIs remain accepted no-edit dependencies.
- Completed generated closure: primary supervisor command `000000020608` exited `0`, refreshed generated output and registry/current metadata, emitted exactly one UID0004CL definition at `92/94` in `Thread.cpp`, retained the single `virtual int ThreadProc();` declaration in `Thread.h`, removed any UID0004CL empty-emitter condition, marked generated memory coverage coded to UID0000OR, and refreshed the tracker row to `92/94`.
- Completed IDA closure: catalog entry `0394` and saved IDB SHA256 `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A` record the final UDT/function/comment/frame/local results and unchanged protected state. B008 did not perform those supervisor-owned mutations.

## Ranked Ownership Analysis

### 1. UID0000OR Thread.cpp

- Evidence for: five Thread-family vtables share the target; Thread constructor/entry/handlers/post helpers surround it; class/file docs and generated route agree; source type is generic.
- Evidence against: none material.
- Decision: canonical owner and emitter remain UID0000OR.

### 2. UID0000EV Thread class

- Evidence for: declares the method, fields, records, and virtual contract.
- Evidence against: class page is a declaration/support parent rather than source-file emitter root.
- Decision: class declaration owner and support destination, not canonical file owner.

### 3. Socket or CashShopRequest

- Evidence for: Socket inherits the body; older aggregate title used CashShopRequest.
- Evidence against: four other vtables inherit the same body; no target direct callers; queue/result infrastructure is generic; current ownership history already rejects those labels.
- Decision: reject as owner. Socket is derived override evidence only; CashShopRequest is historical alias pollution.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; retain `NexusTK/util/Thread.cpp` and `Thread.h`.
- Likely full contents: existing Thread/ThreadMan source family.
- Candidate related items that belong: exact target and existing Thread children already routed to UID0000OR.
- Candidate related items rejected: Socket polling implementation remains Socket.cpp; List/Monitor/RingBuffer implementations remain their own utility files.
- Standalone, narrow, or broad source-file inference: exact narrow child within established broad Thread.cpp.

## Source Placement

- Recommended placement: `NexusTK/util/Thread.cpp`, member of `Thread`, declaration in `NexusTK/util/Thread.h` through UID0000EV.
- This fits the surrounding executable island, base vtable, five derived vtables, generic container/synchronization dependencies, existing parent links, and generated source root.
- Rejected placements: `network/Socket.cpp` owns only overrides; CashShopRequest owns no generic worker infrastructure; RingBuffer/List/Monitor files own dependencies, not the loop.
- Remaining placement uncertainty: none material. Exact historical folder casing is less certain than the established project path but does not affect owner/emitter.

## Range / Split / Padding / Reclassification Analysis

- Exact function range: `[0x00596810,0x00596915)`, modeled size `0x105`.
- Predecessor: `[0x00596805,0x00596810)` is one 11-byte data item of `0xCC` padding.
- Successor: `[0x00596915,0x00596920)` is one 11-byte data item of `0xCC` padding before `Thread::OnMessage`.
- No split, merge, extension, or child creation is required.
- Keep UID0001JY as non-emitting split/index coverage and UID0001JX as its broader aggregate.
- Vtable/rdata pages remain generated-binary evidence; they should rebuild from class declarations, not handwritten table arrays.

## Negative Evidence Summary

- No direct code xref calls target; data-only vtable reachability rejects free/static helper ownership.
- No loop backedge encloses the dequeue call; queue draining is rejected.
- No `List::Add` call exists in target; new result-entry creation is rejected.
- No separate RequestSyncGate UDT/vtable/constructor exists; distinct class typing is rejected.
- `OnDispatchEnd` is rejected because hook `+0x28` executes after timeout/failure and secondary waits.
- `Socket::PollAndReceive` and `Socket::NoOpVirtualHook` are rejected as final override spellings because C++ overrides retain the base method name.
- Folded `0x41b6a0` is shared with compiler/runtime and unrelated no-op paths; renaming it to any Thread hook is unsafe.
- `nullsub_17` at `0x41b6b0` is shared by multiple vtables; a global rename to Thread_OnWaitObject would be misleading even though Thread uses it for that slot.
- No new source file, raw vtable object, or standalone padding source is warranted.

## IDA Rename / Type / Comment Recommendations

### Historical atomic supervisor action table and literal transaction prestate

The A00-A17 table preserves the exact pre-Gate2 transaction evidence and accepted action plan. Its `apply`/`apply-with-guarded-rollback` labels are historical pre-action classifications, not current work states; final per-row dispositions follow the guarded protocol.

| ID | Entity | Historical literal prestate | Historical accepted action | Historical expected readback | Historical pre-action classification |
| --- | --- | --- | --- | --- | --- |
| A00 | Type `Thread` | Type absent; no name collision. | Create 0x68 UDT: `void **vftable` +0x00; `DWORD m_waitTimeout` +0x04; `signed char m_waitHandleCount` +0x08; `unsigned char _pad09[3]` +0x09; `HANDLE m_waitHandles[16]` +0x0c; `RingBuffer *m_messageQueue` +0x4c; `RingBuffer *m_priorityQueue` +0x50; `Monitor *m_resultMonitor` +0x54; `List *m_resultList` +0x58; `HANDLE m_threadHandle` +0x5c; `unsigned int m_threadId` +0x60; `unsigned char m_stopRequested` +0x64; `unsigned char _pad65[3]` +0x65. | One exact size-0x68 Thread UDT; offsets/widths unchanged. | apply |
| A01 | Type `ThreadMessage` | Type absent; no name collision. | Create size-0x18 UDT: `int messageId` +0x00, `int arg1` +0x04, `int arg2` +0x08, `HANDLE resultEvent` +0x0c, `int syncArg1` +0x10, `int syncArg2` +0x14. | One six-member 24-byte UDT. | apply |
| A02 | Type `ThreadResultEntry` | Type absent; no name collision. | Create size-0x08 UDT: `HANDLE event` +0x00, `int result` +0x04. | One two-member 8-byte UDT. | apply |
| A03 | Function `0x596810` | Name `sub_596810`; declaration `int __thiscall(char *this)`; frame has the six A04 message members plus independent `var_4` and compiler rows exactly itemized below; address regular absent; address repeatable absent; function regular absent; function repeatable absent; proposed name collision absent. | Rename `Thread_ThreadProc`; type `int __thiscall Thread_ThreadProc(Thread *this)`; preserve address comments absent; set function regular `Worker loop: waits on the primary queue semaphore and secondary handles, dispatches one priority/default ThreadMessage per wake, publishes synchronous results, and calls OnIdle between non-stopping waits.`; set function repeatable `virtual int Thread::ThreadProc(); priority queue precedes default queue; synchronous result entries are created by callers.` A03 does not itself alter frame members; A04 owns that bounded transaction. | Exact name/type/comments; bytes, range, xrefs, and all existing internal comments unchanged. Frame readback is governed separately by A04. | apply |
| A04 | Target frame message storage | Exact current member-by-member prestate, mapping, protected rows, and comments are in the A04 tables below; no aggregate UDT/member currently exists. | After A01 creates and verifies the exact `ThreadMessage` UDT, run only the guarded A04 transaction below: remove the six individually named message members, declare one `ThreadMessage message` at EBP displacement `-0x1c`, recompile, and read back. Preserve `var_4`, compiler rows, bytes, xrefs, and comments. | Required durable readback is one `message` frame member at reported frame offset `+0x0c`, size `0x18`, type `ThreadMessage`; no six old members; `var_4` and compiler rows unchanged. Hex-Rays must still decompile correctly and preserve accesses, but exact aggregate-lvar spelling/presentation is not promised unless actually exposed by readback. | apply-with-guarded-rollback |
| A05 | Target local `v2` | `const HANDLE *v2`, EBX; local comments not applicable. | Rename `waitHandles`; keep `const HANDLE *`. | Source-facing local with identical register/use. | apply |
| A06 | Target local `v3` | `DWORD v3`, ECX; local comments not applicable. | Rename `waitIndex`; keep `DWORD`. | Wait result comparisons retain unsigned semantics. | apply |
| A07 | Target local `v4` | `RingBuffer *v4`, ECX; local comments not applicable. | Rename `queue`; keep `RingBuffer *`. | Selected priority/default queue is explicit. | apply |
| A08 | Target local `v6` | `int v6`, EAX; local comments not applicable. | Rename `result`; keep `int`. | Sync-handler return is explicit. | apply |
| A09 | Target local `v7` | `HANDLE *v7`, ECX; local comments not applicable. | Rename `resultMonitor`; type `Monitor *`. | Lock target decompiles as Monitor pointer. | apply |
| A10 | Target local `v8` | `int v8`, EDI; local comments not applicable. | Rename `resultIndex`; keep `int`. | Result-list loop index is explicit. | apply |
| A11 | Target local `v9` | `int v9`, EBX; local comments not applicable. | Rename `resultCount`; keep `int`. | Inlined List count read is explicit. | apply |
| A12 | Target local `v10` | `int v10`, EAX; local comments not applicable. | Rename `resultEntry`; type `ThreadResultEntry *`. | Event/result member accesses become typed. | apply |
| A13 | Function `0x4f32b0` | Name `sub_4F32B0`; declaration `int __thiscall(_DWORD *this, int)`; frame saved +0x0, return +0x4, `arg_0/_DWORD` +0x8; decompiler argument `a2 int`; all four address/function comment channels absent; proposed collision absent. | Rename `List_GetElementAt`; type `void *__thiscall List_GetElementAt(List *this, int index)`; preserve address comments absent; function regular `Return the element at index from List backing storage; index zero is valid whenever storage exists.`; function repeatable `virtual void *List::GetElementAt(int index);`; rename argument `index`. | Typed List accessor; 42-byte body, xrefs, vtable cells unchanged. | apply |
| A14 | Function `0x528710` | Name `sub_528710`; declaration `DWORD __thiscall(HANDLE *this)`; frame only return address; no locals; address regular `dwMilliseconds`; address repeatable absent; function regular absent; function repeatable absent; proposed collision absent; internal `0x528712` regular `hHandle`. | Rename `Monitor_Lock`; type `void __thiscall Monitor_Lock(Monitor *this)`; preserve address/internal comments; function regular `Acquire the Monitor mutex with an infinite wait.`; function repeatable `void Monitor::Lock();`. | Source-facing Monitor method; bytes/callers unchanged. | apply |
| A15 | Function `0x528720` | Name `sub_528720`; declaration `BOOL __thiscall(int this)`; frame only return; no locals; all four entry comment channels absent; proposed collision absent; internal regular comments at 0x528726 `lpPreviousCount`, 0x528728 `lReleaseCount`, 0x52872a `hSemaphore`, 0x528734 `hMutex`. | Rename `Monitor_Unlock`; type `void __thiscall Monitor_Unlock(Monitor *this)`; preserve internal comments; function regular `Release the Monitor mutex, or hand off through its waiter semaphore when waiters are present.`; function repeatable `void Monitor::Unlock();`. | Typed Monitor method; 30-byte body/callers unchanged. | apply |
| A16 | Function `0x575d90` | Name `nullsub_53`; declaration `void()`; size 1 `retn`; frame only return; no locals; all four comments absent; only xref Socket vtable 0x624f34; proposed collision absent. | Rename `Socket_OnStart`; type `void __thiscall Socket_OnStart(Socket *this)`; address comments remain absent; function regular `Empty Socket override of Thread::OnStart, invoked before the worker thread is resumed.`; function repeatable `virtual void Socket::OnStart();`. | Unique derived empty override; vtable value/byte unchanged. | apply |
| A17 | Function `0x575da0` | Name `sub_575DA0`; declaration `void __thiscall(int this)`; frame `timeout/timeval` +0x4 size8, `readfds/fd_set` +0xc size0x104, `var_4/_DWORD` +0x110, saved +0x114, return +0x118; decompiler local `char v2`; all four entry comments absent; internal comments `timeout`, `exceptfds`, `writefds`, `readfds`, `nfds`, `StackCookie`, `Block`; only xref Socket vtable 0x624f48; proposed collision absent. | Rename `Socket_OnIdle`; type `void __thiscall Socket_OnIdle(Socket *this)`; rename `v2` to `transportMode`; preserve frame/internal comments; function regular `Thread idle hook: poll the active Socket transport with zero-timeout select and dispatch available receive work.`; function repeatable `virtual void Socket::OnIdle();`. | Derived override name matches base slot; 0xbb body/xref unchanged. | apply |

### A04 literal frame-member map

`stack_frame.offset` below is IDA's reported positive frame-structure offset. `declare_stack.offset` must instead use the physical EBP displacement shown in the next column.

| Current member | `stack_frame` offset | Physical EBP relation | Size / current type | Exposed local/comment state | Exact `ThreadMessage` mapping and disposition |
| --- | --- | --- | --- | --- | --- |
| `record` | `+0x0c` | `[ebp-0x1c]` | `0x4 / _DWORD` | Hex-Rays `int record` with `BYREF`; address `0x596871` regular comment `record`, repeatable absent; no per-member comment field is exposed by `stack_frame`. | Delete only this individual frame member after exact precheck; aggregate field `message.messageId` at `+0x00` replaces its storage. Preserve the existing `0x596871` instruction comment as a generic record annotation. |
| `var_18` | `+0x10` | `[ebp-0x18]` | `0x4 / _DWORD` | Hex-Rays `int v13`; no address comment on its use at `0x596882`; no exposed per-member comment. | Delete only this individual frame member; aggregate field `message.arg1` at `+0x04` replaces its storage. |
| `var_14` | `+0x14` | `[ebp-0x14]` | `0x4 / _DWORD` | Hex-Rays `int v14`; no address comment on its use at `0x59687d`; no exposed per-member comment. | Delete only this individual frame member; aggregate field `message.arg2` at `+0x08` replaces its storage. |
| `hEvent` | `+0x18` | `[ebp-0x10]` | `0x4 / HANDLE` | Hex-Rays `HANDLE hEvent`; address `0x5968d7` regular comment `hEvent`, repeatable absent; no exposed per-member comment. | Delete only this individual frame member; aggregate field `message.resultEvent` at `+0x0c` replaces its storage. Preserve the existing instruction comment. |
| `var_C` | `+0x1c` | `[ebp-0x0c]` | `0x4 / _DWORD` | Hex-Rays `int v16`; no address comment on its use at `0x596892`; no exposed per-member comment. | Delete only this individual frame member; aggregate field `message.syncArg1` at `+0x10` replaces its storage. |
| `var_8` | `+0x20` | `[ebp-0x08]` | `0x4 / _DWORD` | Hex-Rays `int v17`; no address comment on its use at `0x59688f`; no exposed per-member comment. | Delete only this individual frame member; aggregate field `message.syncArg2` at `+0x14` replaces its storage. |

Protected adjacent members:

| Member | Exact current state | A04 disposition |
| --- | --- | --- |
| `var_4` | `stack_frame +0x24`, `[ebp-0x04]`, size `0x4`, `_DWORD`; Hex-Rays `int v18`, assigned the `OnMessageEx` result at `0x59689e`; no exposed per-member comment. | Preserve as a separate result local. Do not delete, absorb, rename, or retype under A04. A08 may separately rename the decompiler local only if its prestate still matches. |
| `__saved_registers` | `stack_frame +0x28`, size `0x4`, `_DWORD`. | Preserve exactly; never delete or redeclare. |
| `__return_address` | `stack_frame +0x2c`, size `0x4`, `_UNKNOWN *`. | Preserve exactly; never delete or redeclare. |

### A04 supervisor-supported mutation protocol

1. Preflight under one healthy database session: record the authoritative IDB disk hash/size/time and a same-hash backup; run `type_inspect(ThreadMessage)`, `stack_frame(0x596810)`, `decompile(0x596810)`, `get_comments` for the listed use sites, target `get_bytes`, and target/vtable `xrefs_to`. Stop before mutation if any row differs from the literal tables above, if `ThreadMessage` already exists with a conflicting layout, or if the session changes/disappears.
2. Complete A01 first with `declare_type`, then require `type_inspect` to show exactly size `0x18` and the six fields/offsets/types in A01. Do not begin frame edits if the UDT readback differs.
3. Do not save the IDB during the frame transaction. Call `delete_stack` separately and in this order for `record`, `var_18`, `var_14`, `hEvent`, `var_C`, and `var_8`, always with `addr=0x00596810`; after each call, use `stack_frame` to prove only the named row disappeared and every not-yet-removed/protected row is unchanged. The schema has no dry-run or transaction flag, so any error, partial result, automatic rename, offset shift, or protected-row change is an immediate rollback condition.
4. Only after all six removals read back exactly, call `declare_stack` once with `addr=0x00596810`, `offset=-0x1c`, `name=message`, and `ty=ThreadMessage`. The negative EBP displacement is intentional; never substitute the reported positive frame offset `+0x0c` or try alternate offsets.
5. Call `force_recompile` only for `0x00596810`, then read back `stack_frame`, `decompile`, comments, bytes, function bounds, and xrefs. Durable success requires exactly `message +0x0c / 0x18 / ThreadMessage`, absence of all six replaced names, unchanged `var_4`/compiler rows, valid equivalent decompilation, unchanged comments, bytes, bounds, and xrefs. Exact Hex-Rays text `ThreadMessage message` is desirable but not a promised success condition because current tools expose no safe lvar-map operation that guarantees that presentation. Do not issue blind `rename.local` or `set_type(variable=...)` if no stable aggregate lvar is exposed.
6. If all durable checks pass, the supervisor may save once and then repeat `server_health`, `stack_frame`, `decompile`, `get_comments`, `get_bytes`, and xref readback from the saved/reopened authority. If any check fails before save, do not attempt inverse frame edits in the uncertain live session: discard that unsaved worker state under supervisor process control, reopen the unchanged authoritative IDB/backup, verify its hash and every literal prestate row, and record A04 as rolled back. If failure occurs after a save attempt, restore the verified pre-transaction backup, reopen, and prove full prestate restoration before further work.

Historical A04 stop conditions were explicit: prestate drift, type collision/layout mismatch, session rollover during mutation, any delete failure or collateral row change, wrong aggregate offset/size/type, decompile failure, bytes/bounds/xref/comment drift, or inability to prove saved readback would have required leaving A04 unapplied rather than retaining partial state. None fired during the completed supervisor transaction.

### Final supervisor disposition and post-save readback

- Authority: primary supervisor Gate 2B, catalog entry `0394`; B008 did not perform these actions.
- Saved IDB: `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`, SHA256 `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A`, 143,193,372 bytes, last write `2026-08-01T07:52:08-04:00`.

| ID | Final disposition | Exact durable readback |
| --- | --- | --- |
| A00 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `Thread` is exactly `0x68`/104 bytes with 13 members at the accepted offsets; IDA-normalized byte spellings preserve widths and signedness. |
| A01 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `ThreadMessage` is exactly `0x18`/24 bytes with six fields at `+0x00..+0x14`. |
| A02 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `ThreadResultEntry` is exactly `0x08`/8 bytes with `event +0x00` and `result +0x04`. |
| A03 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `0x00596810` is `Thread_ThreadProc`, `int __thiscall(Thread *this)`; regular/repeatable comments read back exactly; address/internal comments, 261 bytes, bounds, and five xrefs remain unchanged. |
| A04 | `APPLIED_VERIFIED_BY_SUPERVISOR` | The six scalar rows were removed individually with after-each checks; one `message +0x0c/0x18/struct ThreadMessage` remains; `var_4` and compiler rows are exact; decompile exposes all six aggregate fields. |
| A05 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `const HANDLE *waitHandles`. |
| A06 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `DWORD waitIndex`. |
| A07 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `RingBuffer *queue`. |
| A08 | `ATTEMPTED_NOT_DURABLE_SAFE_PRESENTATION_ONLY` | Supported rename was attempted twice, but fresh Hex-Rays recompilation regenerated register-only `v6`; supported local typing also rejected it. No force/unsupported workaround was used; semantics, type, body, formal C++, and confidence are unaffected. |
| A09 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `Monitor *resultMonitor`. |
| A10 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `int resultIndex`. |
| A11 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `int resultCount`. |
| A12 | `APPLIED_VERIFIED_BY_SUPERVISOR` | Durable local is `ThreadResultEntry *resultEntry`. |
| A13 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `0x004f32b0` is `List_GetElementAt`, `void *__thiscall(List *this, int index)`; comments and argument `index` read back exactly; body/xrefs/vtable cells are unchanged. |
| A14 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `0x00528710` is typed/commented `Monitor_Lock`; protected address/internal comments read back unchanged. |
| A15 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `0x00528720` is typed/commented `Monitor_Unlock`; protected internal comments read back unchanged. |
| A16 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `0x00575d90` is typed/commented `Socket_OnStart`; the one-byte body and sole vtable xref are unchanged. |
| A17 | `APPLIED_VERIFIED_BY_SUPERVISOR` | `0x00575da0` is typed/commented `Socket_OnIdle`; durable local `transportMode`, comments, body, and sole vtable xref read back correctly. |

### Individually protected dependencies

The following table preserves the historical literal prestate and required protection rule used by the supervisor transaction.

| ID | Entity and historical literal prestate | Protected disposition |
| --- | --- | --- |
| P00 | `0x596805-0x596810`: one unnamed size-11 data item, bytes `CC` x11, regular absent, repeatable absent. | Preserve as predecessor padding; no name/type/comment. |
| P01 | `0x596915-0x596920`: one unnamed size-11 data item, bytes `CC` x11, regular absent, repeatable absent. | Preserve as successor padding; no function creation. |
| P02 | Thread vtable cell `0x62e288`: unnamed data dword `0x00596810`, regular absent, repeatable absent. | Preserve exact target pointer; no handwritten vtable. |
| P03 | FileDownloader vtable cell `0x60d7c4`: unnamed data dword `0x00596810`, regular absent, repeatable absent. | Preserve inherited pointer. |
| P04 | MiniMapDownloader vtable cell `0x6106ec`: unnamed data dword `0x00596810`, regular absent, repeatable absent. | Preserve inherited pointer. |
| P05 | MiscWorkThread vtable cell `0x61fb90`: unnamed data dword `0x00596810`, regular absent, repeatable absent. | Preserve inherited pointer. |
| P06 | Socket vtable cell `0x624f3c`: unnamed data dword `0x00596810`, regular absent, repeatable absent. | Preserve inherited pointer. |
| P07 | `0x41b6a0` `@_guard_check_icall_nop@4`, one-byte `retn`, shared by many unrelated vtables/runtime paths; address regular/repeatable absent; function regular contains existing two-line compiler/runtime no-op warning; function repeatable absent. | No rename/retype/comment overwrite. It implements several folded empty source methods but is not one globally nameable Thread method. |
| P08 | `0x41b6b0` `nullsub_17`, size 3 `retn 4`, no IDA prototype, all four comments absent, seven vtable refs including Thread `0x62e2a0`. | Preserve current shared identity; source declarations provide `OnWaitObject(int)`. A global Thread rename would mislabel other uses. |
| P09 | `0x5565f0` `RingBuffer_Dequeue`, size 0x6a, accepted `void __thiscall(RingBuffer *, void *)`; address regular/repeatable absent; function regular exact blocking-dequeue description; function repeatable absent. | Already present; no change. |
| P10 | `0x556660` `RingBuffer_IsEmpty`, size 8, accepted `bool __thiscall(const RingBuffer *)`; address regular/repeatable absent; function regular `RingBuffer empty predicate (count == 0).`; function repeatable absent. | Already present; no change. |
| P11 | List vtable cell `0x61ce3c`: unnamed data dword `0x004f32b0`, regular absent, repeatable absent. | Preserve exact virtual slot +0x10 pointer. |
| P12 | Monitor UDT ordinal 557: size 16; `vftable` +0, `m_mutex` +4, `m_waiterCount` +8, `m_semaphore` +0xc. | Already present; do not redeclare/retype. |

Final primary-supervisor P00-P12 readback, catalog `0394`:

| ID | Final disposition/readback |
| --- | --- |
| P00 | `VERIFIED_UNCHANGED`: predecessor `[0x596805,0x596810)` remains eleven `CC` bytes with no source-bearing item. |
| P01 | `VERIFIED_UNCHANGED`: successor `[0x596915,0x596920)` remains eleven `CC` bytes with no function creation. |
| P02 | `VERIFIED_UNCHANGED`: Thread vtable cell `0x62e288` still points to `0x00596810`. |
| P03 | `VERIFIED_UNCHANGED`: FileDownloader vtable cell `0x60d7c4` still points to `0x00596810`. |
| P04 | `VERIFIED_UNCHANGED`: MiniMapDownloader vtable cell `0x6106ec` still points to `0x00596810`. |
| P05 | `VERIFIED_UNCHANGED`: MiscWorkThread vtable cell `0x61fb90` still points to `0x00596810`. |
| P06 | `VERIFIED_UNCHANGED`: Socket vtable cell `0x624f3c` still points to `0x00596810`. |
| P07 | `VERIFIED_UNCHANGED`: shared `0x0041b6a0` compiler/runtime no-op identity, bytes, refs, and warning comment remain protected. |
| P08 | `VERIFIED_UNCHANGED`: shared `0x0041b6b0` `nullsub_17`, bytes, and multi-vtable identity remain protected. |
| P09 | `VERIFIED_UNCHANGED`: `RingBuffer_Dequeue` name/type/comment/body remain accepted. |
| P10 | `VERIFIED_UNCHANGED`: `RingBuffer_IsEmpty` name/type/comment/body remain accepted. |
| P11 | `VERIFIED_UNCHANGED`: List vtable cell `0x61ce3c` still points to `0x004f32b0`. |
| P12 | `VERIFIED_UNCHANGED`: Monitor UDT remains exact size 16 with the accepted four fields. |

Negative constraints:

- Do not rename or retype folded `0x41b6a0`/`0x41b6b0` as unique Thread methods.
- Do not create code at either padding run.
- Do not alter target bytes, function bounds, vtable bytes, xrefs, existing internal instruction comments, or RingBuffer/Monitor UDT layouts.
- Do not use positive `stack_frame` offset `+0x0c` as the `declare_stack` offset, delete `var_4` or compiler rows, batch unverified frame removals, save partial A04 state, or promise exact Hex-Rays aggregate text that readback does not expose.
- Do not create a RequestSyncGate UDT or duplicate Monitor methods.
- Do not name the base hook `PollAndReceive` or `OnDispatchEnd`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; exact target behavior and all source dependencies are resolved.
- Target CPP block disposition: replace the entire UID0004CL formal block with the following exact text.

```cpp
int Thread::ThreadProc()
{
    for (;;)
    {
        Sleep(1);

        DWORD waitIndex = WaitForMultipleObjects(
            m_waitHandleCount,
            m_waitHandles,
            FALSE,
            m_waitTimeout);

        if (waitIndex == WAIT_OBJECT_0)
        {
            OnDispatchBegin();

            RingBuffer *queue = NULL;
            if (!m_priorityQueue->IsEmpty())
                queue = m_priorityQueue;
            else if (!m_messageQueue->IsEmpty())
                queue = m_messageQueue;

            if (queue != NULL)
            {
                ThreadMessage message;
                queue->Dequeue(&message);

                if (message.resultEvent == NULL)
                {
                    OnMessage(message.messageId, message.arg1, message.arg2);
                }
                else
                {
                    int result = OnMessageEx(message.messageId,
                                             message.syncArg1,
                                             message.syncArg2,
                                             message.arg1,
                                             message.arg2);

                    m_resultMonitor->Lock();
                    int resultCount = m_resultList->GetCount();
                    for (int resultIndex = 0;
                         resultIndex < resultCount;
                         ++resultIndex)
                    {
                        ThreadResultEntry *entry =
                            static_cast<ThreadResultEntry *>(
                                m_resultList->GetElementAt(resultIndex));
                        if (entry->event == message.resultEvent)
                        {
                            entry->result = result;
                            break;
                        }
                    }
                    m_resultMonitor->Unlock();

                    SetEvent(message.resultEvent);
                }
            }
        }
        else if (waitIndex < m_waitHandleCount)
        {
            OnWaitObject(static_cast<int>(waitIndex));
        }

        if (m_stopRequested)
            return 0;

        OnIdle();
    }
}
```

- Target H block disposition: remain blank. The exact declaration belongs in [UID:0000EV]'s formal H block.
- UID0000EV formal H changes: replace `class RequestSyncGate;` with `class Monitor;`, replace `RequestSyncGate *m_resultGate;` with `Monitor *m_resultMonitor;`, and use this exact virtual sequence after `ForceTerminate()`:

```cpp
    virtual void OnStart();
    virtual void OnThreadBegin();
    virtual int ThreadProc();
    virtual void OnThreadEnd();
    virtual void OnDispatchBegin();
    virtual void OnIdle();
    virtual void OnMessage(int messageId, int arg1, int arg2);
    virtual int OnMessageEx(int messageId, int syncArg1, int syncArg2,
                            int arg1, int arg2);
    virtual void OnWaitObject(int waitIndex);
```

- UID0000DD formal declaration changes: replace only the two inherited override lines with:

```cpp
    virtual void OnStart();
    virtual void OnIdle();
```

- Reason behavior is exact: loop timing, wait comparisons, hook order, one dequeue, record order, virtual arguments, result scan/write, lock boundaries, event signaling, stop test, and return value mirror the target.
- Reason source shape is plausible: ordinary member names, structured control flow, container methods, virtual dispatch, and Win32 calls match project style and avoid decompiler temporaries/offset expressions.
- Naming style: existing project `m_` fields and PascalCase methods; inferred names are applied consistently. Execution fidelity and human source shape take priority over cosmetic consistency.
- Third-party import directive: not applicable.

## Final Recommendation

- The primary supervisor record closes Gate 2A C001-C057 `57/57`, manual C058-C067 `10/10`, IDA/protection C068-C078 `11/11`, and the combined claim ledger `78/78`. B008 performed only the accepted ordinary-document callback; the supervisor performed and verified the manual, IDA, protection, generated, audit, and catalog work.
- Catalog entry `0394` and saved IDB SHA256 `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A` record A00-A17/P00-P12 closure. A08 alone is safely `ATTEMPTED_NOT_DURABLE` presentation-only; no force or unstable workaround is appropriate or required.
- Manual commands `000000020605`-`000000020607` closed M01-M10, and generated command `000000020608` closed the expected Thread.cpp/Thread.h/memory-coverage/tracker state.
- The applied UID0004CL owner/emitter/reconstructable metadata and corrected score/body/detail fields remain the report's final recommendation.
- Keep UID0001JX broad aggregate emitting behavior and `88/89` unchanged; its exact-child history is updated.
- Keep compiler-generated vtables and padding non-handwritten.
- Future work outside scope: unrelated raw Thread/ThreadMan helpers and broad Socket transport source-quality debt remain separate targets; they do not block this target.

## Recommended Target Doc Changes

- Implementation state: applied and validated as command `000000020530`; the bullets below preserve the accepted pre-callback plan.
- Target path: `by-memory/0x00596810-0x00596915.ThreadProc.md`.
- Replace formal CPP exactly; keep H blank.
- Rewrite Behavior to state one record per primary wake, exact hook order, result-list search/write, SetEvent behavior, secondary wait route, stop-before-idle timing, and APIs.
- Add exact vtable/xref and boundary evidence.
- Historicalize the drain-loop and new-entry assumptions with reasons; do not silently delete them.
- Metadata: `92/94`, owner 0000OR, reconstructable true, emitter 0000OR, blank optional position.

## Recommended Support Doc Changes

- Implementation state: all listed ordinary changes are applied and validated; List/RingBuffer/Monitor dependencies were read back and required no edits.
- `by-class/Thread.md`: exact H changes, complete vtable order, Monitor field, GetCount/GetElementAt/IsEmpty/Dequeue evidence, source-name inference, score `93/94`.
- `by-file/Thread.md`: exact target correction, generated expectation, score `92/93`.
- `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`: correct one-record behavior and APIs; preserve non-emitting split-index status; score `90/92`.
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`: add exact child correction; retain `88/89`.
- `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`: complete all Thread slots, OnIdle correction, current live bytes, score `90/93`.
- `by-class/Socket.md`: OnStart/OnIdle overrides and source-alias explanation; score `91/92`.
- `by-file/Socket.md`: inherited virtual correction and score `90/91`.
- `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`: method-table source spelling correction; keep aggregate `88/92`.
- `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md`: vtable spelling correction and score `89/93`.
- List/RingBuffer/Monitor pages: no ordinary edit required; their accepted current source APIs are evidence and must not be duplicated.

## Score And Metadata Recommendation

| UID | Pre-callback | Applied | Rationale |
| --- | --- | --- | --- |
| 0004CL | 88/88 | 92/94 | Exact behavior, APIs, vtable, bounds, formal CPP, and IDA handoff resolved. |
| 0000EV | 91/92 | 93/94 | Complete header/vtable contract and exact Monitor/List typing. |
| 0000OR | 91/91 | 92/93 | Source root gains exact central worker implementation/header. |
| 0001JY | 88/89 | 90/92 | Split index no longer carries target queue/vtable caveats. |
| 0001JX | 88/89 | 88/89 | Wider unrelated debt remains. |
| 00026P | 87/91 | 90/93 | Fresh full live vtable and exact source slot names. |
| 0000DD | 90/89 | 91/92 | Derived override names/order corrected. |
| 0000NS | 90/89 | 90/91 | File placement already strong; confidence improves. |
| 0001I1 | 88/92 | 88/92 | Method aliases corrected but wider aggregate debt remains. |
| 00026G | 88/91 | 89/93 | Fresh Socket vtable interpretation closes inherited-name caveat. |

Reason target is not higher than 92/94:

- Original private field spellings and five hook spellings are not symbol-proven.
- `OnDispatchBegin` and `OnIdle` are high-probability source names, not recovered PDB names.
- This pass does not compile/link the entire source tree.

Reason target is not lower:

- Every instruction path and source dependency is resolved; no raw helper, ownership, split, API, or type blocker remains.
- Vtable/caller/callee/type/byte evidence independently corroborates the decompile.

Metadata fields to retain: owner/emitter/reconstructable and blank optional position.

## Open Questions With Attempted Resolution

1. Does ThreadProc drain queues?
   - Checked decompile, disassembly, RingBuffer calls, and producer semaphore behavior.
   - Resolved: no; exactly one record per primary wake.
2. Which queue API names are source-ready?
   - Checked IDA names and formal RingBuffer H.
   - Resolved: `IsEmpty` and `Dequeue`.
3. Who creates synchronous result entries?
   - Checked caller-side post helper and target list operations.
   - Resolved: caller pre-creates; target only finds/writes.
4. Is RequestSyncGate a source class?
   - Checked type catalog, Monitor docs, construction/vtable evidence, and functions.
   - Resolved: no separate class; use Monitor.
5. Which List APIs are correct?
   - Checked List H, exact GetElementAt child, vtable, and direct count read.
   - Resolved: inline `GetCount`, virtual `GetElementAt`.
6. What are slots +0x14/+0x18/+0x20?
   - Checked StartThread and ThreadEntry call timing.
   - Resolved: OnStart, OnThreadBegin, OnThreadEnd.
7. What is slot +0x24?
   - Checked target call placement and all derived vtables.
   - Resolved high-probability name: OnDispatchBegin.
8. What is slot +0x28?
   - Checked every target path and Socket override body.
   - Resolved high-probability name: OnIdle; reject OnDispatchEnd.
9. Should Socket use NoOpVirtualHook/PollAndReceive?
   - Checked inherited slot positions and C++ override rules.
   - Resolved: source declarations use OnStart/OnIdle; old names remain behavior aliases.
10. Does secondary index need subtraction?
    - WAIT_OBJECT_0 is zero; target passes nonzero result directly.
    - Resolved: pass `waitIndex` directly.
11. Is a new split/source file needed?
    - Checked exact bounds, owner, siblings, and generated route.
    - Resolved: no.
12. Can the score improve?
    - All former queue/list/vtable/type/formal blockers were researched and resolved.
    - Resolved: raise to 92/94.
13. Can A04 safely promise a `ThreadMessage message` frame/decompiler result?
    - Checked fresh `stack_frame`/`decompile`/comments, current `declare_stack`/`delete_stack`/`force_recompile` schemas, and prior supervisor stack-tool failure evidence.
    - Resolved and completed by the primary supervisor: the guarded six-member replacement at EBP displacement `-0x1c` produced one durable `message +0x0c/0x18/struct ThreadMessage` row, preserved `var_4` and compiler rows, and exposed all six aggregate fields after save/recompile. A08's independent register-only rename remained safely presentation-only and not durable.

Remaining uncertainty is limited to original spelling. It does not block source emission and must not be represented by IDA-style names.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Historical pre-application containers inspected by B008; these hashes are dated prestates, not current identities:

- `by-memory/-coverage-report.md` SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, 2,134,111 bytes, 4,803 lines.
- `by-class/-coverage-report.md` SHA256 `0A2F8F0BF6EF28ECB9633E504A0C2B59BCBF022B31201B33A1AAAB319B15D272`, 275,060 bytes, 625 lines.
- `by-file/-coverage-report.md` SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`, 166,582 bytes, 319 lines.

Historical accepted payload M01, subsequently inserted and read back by the primary supervisor after UID0001JZ and before UID0001K0:

```markdown
    - [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md) 0x00596810-0x00596915 | method | ThreadProc : reconstructable : 92% : very-strong : Exact Thread::ThreadProc worker loop with per-iteration Sleep(1), WaitForMultipleObjects routing, one priority/default ThreadMessage dequeue per primary wake, async/sync virtual dispatch, Monitor-guarded result publication, event signaling, secondary-handle callback, stop-before-OnIdle behavior, complete vtable evidence, and human source-ready C++.
```

Historical accepted payload M02, subsequently applied/read back for UID0001JX:

```markdown
    - [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) 0x00596250-0x0059756e | aggregate | ThreadAndThreadMan : reconstructable : 88% : strong : Thread/ThreadMan utility-threading island attached to Thread.cpp with exact child coverage for ThreadProc and adjacent worker methods, modeled/raw wrapper inventory, singleton/watchdog evidence, vtable/read-only-data routes, and preserved wider aggregate debt outside the exact source-bearing children.
```

Historical accepted payload M03, subsequently applied/read back for UID0001JY:

```markdown
    - [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) 0x00596620-0x005969b0 | aggregate | ThreadMessageDispatchHelpers : non-reconstructable split/index : 90% : very-strong : Generic base Thread queue/result/wait/worker helper index with exact children, one-message-per-wake ThreadProc behavior, RingBuffer IsEmpty/Dequeue APIs, Monitor-guarded caller-created result entries, List GetCount/GetElementAt access, complete virtual-slot routing, and no duplicate aggregate emitter.
```

Historical accepted payload M04, subsequently applied/read back for UID00026P:

```markdown
    - [UID:00026P][0x0062e268-0x0062e334.ThreadReadOnlyData](by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) 0x0062e268-0x0062e334 | vtable/string-data | ThreadReadOnlyData : reconstructable : 90% : very-strong : Thread/ThreadMan RTTI, complete Thread vtable slot map, generated scalar run, ThreadMan vtable, debugger-probe literals, watchdog diagnostic text, exact predecessor/successor boundaries, and compiler-generated/no-handwritten-vtable rebuild policy through Thread.cpp declarations.
```

Historical accepted payload M05, subsequently applied/read back for UID0001I1:

```markdown
    - [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md) 0x00575d90-0x005797ae | Socket transport aggregate | SocketTransportCore : non-reconstructable split/index : 88% : very-strong : Socket transport method inventory with inherited Thread OnStart/OnIdle override contracts, nonblocking idle polling, command/send/receive/parser/destructor flows, raw reconnect/serial helpers, g_packetSender lifetime evidence, packet-transform splits, and no duplicate aggregate emitter.
```

Historical accepted payload M06, subsequently applied/read back for UID00026G:

```markdown
    - [UID:00026G][0x00624f20-0x00625008.SocketReadOnlyData](by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md) 0x00624f20-0x00625008 | vtable/string-data | SocketReadOnlyData : reconstructable : 89% : very-strong : Socket.cpp read-only data with exact full Socket vtable, inherited ThreadProc/OnStart/OnIdle contracts, transport-specific virtuals, parser/error literals, clean neighbor bounds, and source-declared/compiler-generated vtable handling.
```

Historical accepted payload M07, subsequently applied/read back for UID0000EV:

```markdown
- [UID:0000EV][Thread](by-class/Thread.md) : reconstructable : 93% : very-strong : Complete shared Thread base declaration and 0x68 layout with exact ThreadMessage/ThreadResultEntry records, Monitor result synchronization, RingBuffer and List APIs, full virtual order from OnStart through OnWaitObject, exact one-message-per-wake ThreadProc source, and util/Thread.cpp plus Thread.h ownership through UID0000OR.
```

Historical accepted payload M08, subsequently applied/read back for UID0000DD:

```markdown
- [UID:0000DD][Socket](by-class/Socket.md) : reconstructable : 91% : very-strong : Stateful Thread-derived transport class owning command-post, TCP/serial, packet send/receive/transform, and g_packetSender flows, with exact inherited ThreadProc plus OnStart/OnIdle override contracts, nonblocking idle-poll behavior, source-facing transport virtuals, and NexusTK/network/Socket ownership.
```

Historical accepted payload M09, subsequently applied/read back for UID0000OR:

```markdown
- [UID:0000OR][Thread](by-file/Thread.md) : reconstructable : 92% : very-strong : NexusTK/util/Thread.cpp and Thread.h source root for Thread/ThreadMan with complete base declaration, exact 0x68 layout and records, Monitor/RingBuffer/List contracts, full virtual order, exact ThreadProc worker loop, queue/result/wait/post helpers, ThreadMan singleton/watchdog code, and compiler-generated vtable/read-only-data routing.
```

Historical accepted payload M10, subsequently applied/read back for UID0000NS:

```markdown
- [UID:0000NS][Socket](by-file/Socket.md) : reconstructable : 90% : very-strong : NexusTK/network/Socket.cpp transport source with lifecycle, command, send, receive, transform, parser, and packet-sender contents plus exact Thread-derived OnStart/OnIdle override contracts and nonblocking idle receive polling.
```

The payload/prestate remains here as historical transaction evidence. B008 did not apply it because manual coverage containers are supervisor-owned collision surfaces.

Exact primary-supervisor closure/readback:

- C058-C063/M01-M06: UID0004CL was inserted and UID0001JX, UID0001JY, UID00026P, UID0001I1, and UID00026G were replaced exactly in `by-memory/-coverage-report.md`; validator `000000020605` exited `0`, `ok:1`. Its two missing-UID diagnostics were pre-existing and unrelated.
- C064-C065/M07-M08: UID0000EV and UID0000DD were replaced exactly in `by-class/-coverage-report.md`; validator `000000020606` exited `0`, `ok:1`.
- C066-C067/M09-M10: UID0000OR and UID0000NS were replaced exactly in `by-file/-coverage-report.md`; validator `000000020607` exited `0`, `ok:1`.
- Generated command `000000020608` exited `0`, completed generated refresh, and rebuilt registry/current metadata. Generated `Thread.cpp` has exactly one UID0004CL definition at `92/94`; `Thread.h` has the single `virtual int ThreadProc();` declaration; UID0004CL has no empty-emitter marker; generated memory coverage marks it coded to UID0000OR; tracker score is `92/94`.
- Live/current manual and generated identities remain authoritative only from physical files and validator-owned command metadata; the historical prestates and applied payloads above must not be mistaken for a lifecycle claim.

## Follow-Up Actions

- Completed historical closure: Gate 2A `57/57`, manual M01-M10 `10/10`, IDA/protection `11/11`, combined ledger `78/78`, saved IDB/catalog `0394`, and generated command `000000020608` are recorded above; none should be repeated merely because the report artifact moved or was returned for text repair.
- No ordinary-document, manual-coverage, IDA, protection, or generated-output implementation remains in this report.
- Report execution/archive/revalidation truth is lifecycle-neutral here and authoritative only from the current physical path plus validator-owned status/history metadata; this section does not prescribe a lifecycle command.
- A-agent actions: none.
- B008 future research: none for UID0004CL; any later exact defect would require a separately scoped same-report correction.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: 93/100.
- Remaining uncertainty: exact original private/hook spellings only. Selected names are evidence-backed and preferable to raw labels; behavior/ABI/ownership are not uncertain.

## Validator Results

All ordinary validators ran serially from `source-3/project-documentation` with `--apply --queue-timeout 240 --no-generated-refresh`. Every command exited `0` with `ok:1`; no generated refresh ran.

| Command | Timestamp | File | Result |
| --- | --- | --- | --- |
| `000000020530` | `2026-08-01T05:15:10-04:00` | `by-memory/0x00596810-0x00596915.ThreadProc.md` | exit `0`, `ok:1`; completion/confidence and UID link updated. |
| `000000020532` | `2026-08-01T05:16:51-04:00` | `by-class/Thread.md` | exit `0`, `ok:1`; known pre-existing missing UID0003GY diagnostics only. |
| `000000020533` | `2026-08-01T05:18:26-04:00` | `by-file/Thread.md` | exit `0`, `ok:1`; known pre-existing missing UID0003V7/UID0003GY diagnostics only. |
| `000000020534` | `2026-08-01T05:23:28-04:00` | `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` | exit `0`, `ok:1`; accepted `90/92` metadata applied. |
| `000000020535` | `2026-08-01T05:24:41-04:00` | `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` | exit `0`, `ok:1`; known pre-existing missing UID0003V7 diagnostics only. |
| `000000020536` | `2026-08-01T05:27:31-04:00` | `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` | exit `0`, `ok:1`; accepted `90/93` metadata and UID0004CL reference applied. |
| `000000020537` | `2026-08-01T05:28:43-04:00` | `by-class/Socket.md` | exit `0`, `ok:1`; known pre-existing missing UID0003A6/UID0003A7 diagnostics only. |
| `000000020538` | `2026-08-01T05:30:02-04:00` | `by-file/Socket.md` | exit `0`, `ok:1`; known pre-existing missing UID0003A6/UID0003A7 diagnostics only. |
| `000000020539` | `2026-08-01T05:30:56-04:00` | `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md` | exit `0`, `ok:1`; known pre-existing missing UID0003A6/UID0003A7 diagnostics only. |
| `000000020541` | `2026-08-01T05:32:19-04:00` | `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md` | exit `0`, `ok:1`; accepted `89/93` metadata applied. |
| `000000020542` | `2026-08-01T05:33:40-04:00` | `by-class/RequestSyncGate.md` | exit `0`, `ok:1`; no unresolved target-specific diagnostic. |

Validator-owned projected-stat/registry updates were automatic side effects of scoped validation. B008 did not manually edit stats, validator state, generated output, tracker, coverage, audit, catalog, or lifecycle files.

Later primary-supervisor closure commands, recorded here as supervisor evidence rather than B008 actions:

- `000000020605`: scoped `by-memory/-coverage-report.md`, exit `0`, `ok:1`; C058-C063/M01-M06 applied/read back, with two unrelated pre-existing missing-UID diagnostics.
- `000000020606`: scoped `by-class/-coverage-report.md`, exit `0`, `ok:1`; C064-C065/M07-M08 applied/read back.
- `000000020607`: scoped `by-file/-coverage-report.md`, exit `0`, `ok:1`; C066-C067/M09-M10 applied/read back.
- `000000020608`: autogen exit `0`; generated refresh and registry/current-metadata rebuild completed with the UID0004CL CPP/H/memory-coverage/tracker results documented above.
- This post-invalidation report-text reconciliation ran no validator, generated refresh, lifecycle command, or report execution probe, as explicitly required.

## Changed Files

Validated post-callback ordinary destinations:

| File | SHA256 | Bytes | Lines | Claims |
| --- | --- | ---: | ---: | --- |
| `by-memory/0x00596810-0x00596915.ThreadProc.md` | `ACDFB87FA487778F4F238541878E20C609CA687C69ABBC938FC9DDB3ED0D62E9` | 13,202 | 224 | C001-C025, C055 |
| `by-class/Thread.md` | `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360` | 31,749 | 337 | C026-C033, C053-C054, C056 |
| `by-file/Thread.md` | `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30` | 46,114 | 264 | C034-C035 |
| `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` | `3E81DF27C842C74CE6B3D125C98E9F2008513CB78D8C8C5257125B1383F29719` | 31,176 | 209 | C036-C037 |
| `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` | `238BF52BEB6007A168B8B070584098699D0B790E9FE5B90B3C83015777A9D384` | 40,001 | 203 | C038-C039 |
| `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` | `F152CD0A724908BB54C4E5E8D7A434B45CF90C9BD54EE13EBA522B7030D4A705` | 26,942 | 177 | C040-C042 |
| `by-class/Socket.md` | `4ED2AEF3686E2A97863592637CF7ED8A58B62E73AB892E3AEF4FAE7B36200261` | 36,819 | 308 | C043-C046 |
| `by-file/Socket.md` | `B01FD40C354C6AFD6BB2A96149DABD95B4B4CF9692603B5E55F71A079A4A4BED` | 26,544 | 173 | C047 |
| `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md` | `32AD32505CA0093CE07D09A8DDCA4BBF6E206044AC135EB04B41C7DF77E88299` | 34,223 | 206 | C048 |
| `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md` | `EA433E1EF123FE45C4A603967AAC49F58671569FEDA1DC23640630B146B03371` | 18,343 | 148 | C049 |
| `by-class/RequestSyncGate.md` | `1DF95ABCC7D0342A46E7E81149561FADA15382641F1EDF314CBE4F9EC9D27392` | 11,240 | 98 | C052 |

Verified no-edit dependencies: `by-class/List.md` `9C69E4F370A64A0F15217DB58D2A8BC74D62691DC088E6811EB6888421FD2011`; `by-file/List.md` `61A1347B4FB168105E191239D6EDAD585752FFE8530FCC24FDB087DF5E98E68E`; `by-class/Monitor.md` `1226640750ED4FAF17B6BF51E0C70E937F3C60B4AB674D05072F648B502D5190`; `by-file/Monitor.md` `900E2C1947C79B0E2E7EE406763D30BF71E7C1F6D9B0658DDEE43FCC1FC89B19`; `by-class/RingBuffer.md` `73E86CA7675FDDDC061352D5C5A7684772DA93AE61FFDAC6E74F8839D602EA68`; `by-file/RingBuffer.md` `22FE0FDA0BC4AD58DA5C213BDC8733AFD7B0599831395646D49FC383E96E3277`.

Each ordinary destination was leased immediately before editing, validated while leased, and released immediately afterward. No file was created, renamed, moved, or deleted. B008 did not edit manual coverage, generated/tracker, audit/catalog, goal/notes, IDA, or lifecycle artifacts and did not run/probe `execute_report`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update are enumerated with literal paths.
- [x] Additional target UID requirement checked; none declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim ledger contains C001-C078 with one destination, canonical action, and current verification state per row.
- [x] A04 now enumerates every affected frame member and maps exact removal/replacement, protected rows, tool sequence, deterministic readback, stop conditions, and rollback behavior without promising unsupported Hex-Rays presentation.
- [x] Metadata/score changes to apply are explicit.
- [x] Score-limiting blockers were researched to resolution; no `needs investigation` deferral remains.
- [x] Owner/emitter/reconstructable dispositions are explicit.
- [x] Split/range/padding decisions are explicit; no new child is needed.
- [x] Source placement and historical reclassification are explicit.
- [x] Primary supervisor Gate 2B applied/finally disposed A00-A17 and verified P00-P12 under catalog entry `0394`; B008 did not perform the supervisor work.
- [x] Exact target CPP, blank target H reason, Thread H changes, and Socket declaration changes are supplied.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support facts are assigned at report-level detail.
- [x] Historical assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Wave2/Wave3 references encountered in old Socket docs were rejected as stale.
- [x] Thirteen open questions are resolved with evidence.
- [x] Scoped validators run after an authorized implementation callback.
- [x] Generated refresh expectations and exact supervisor-owned manual coverage text are supplied.

Implementation callback pass:

- [x] Supervisor-owned IDA changes remain supervisor actions and were not applied by B008.
- [x] Report accepted by supervisor for ordinary implementation at SHA256 `050FB3F9FAA9F3BE6806C167C1C5FEF803F2E58A067B4F8663695EF7E9D68148`, Gate 1 `33/33`.
- [x] All accepted ordinary target/support detail C001-C056 incorporated or physically verified already present.
- [x] Every affected support UID verified against its ledger and destination.
- [x] Claim verification states changed from proposed only after physical readback.
- [x] Metadata/score/CPP/H changes applied or excluded with reason.
- [x] Historical assumptions and negative evidence preserved in ordinary docs.
- [x] Open-question resolutions incorporated without summary loss.
- [x] Serial scoped validators run and exact command IDs/results recorded.
- [x] Generated CPP/H, memory coverage, tracker, and registry/current metadata refreshed and verified by primary supervisor command `000000020608`.
- [x] C057 is reconciled as verified dated assignment provenance; no accepted C058-C078 item remains unapplied in the primary supervisor record.
- [x] Report body is lifecycle-neutral and contains no self-execution claim.

Primary-supervisor closure pass recorded from external Gate 2 evidence, not B008 action:

- [x] C058/M01 exact UID0004CL by-memory manual row inserted and verified by command `000000020605`.
- [x] C059/M02 exact UID0001JX by-memory manual row replaced and verified by command `000000020605`.
- [x] C060/M03 exact UID0001JY by-memory manual row replaced and verified by command `000000020605`.
- [x] C061/M04 exact UID00026P by-memory manual row replaced and verified by command `000000020605`.
- [x] C062/M05 exact UID0001I1 by-memory manual row replaced and verified by command `000000020605`.
- [x] C063/M06 exact UID00026G by-memory manual row replaced and verified by command `000000020605`.
- [x] C064/M07 exact UID0000EV by-class manual row replaced and verified by command `000000020606`.
- [x] C065/M08 exact UID0000DD by-class manual row replaced and verified by command `000000020606`.
- [x] C066/M09 exact UID0000OR by-file manual row replaced and verified by command `000000020607`.
- [x] C067/M10 exact UID0000NS by-file manual row replaced and verified by command `000000020607`.
- [x] C068/A00 exact Thread UDT applied and post-save verified under catalog `0394`.
- [x] C069/A01 exact ThreadMessage UDT applied and post-save verified under catalog `0394`.
- [x] C070/A02 exact ThreadResultEntry UDT applied and post-save verified under catalog `0394`.
- [x] C071/A03,A05-A12 target identity/comments and durable locals applied/read back; A08 is explicitly safe `ATTEMPTED_NOT_DURABLE` presentation-only.
- [x] C072/A04 six scalar frame rows consolidated into one durable typed message aggregate with protected rows unchanged.
- [x] C073/A13 List_GetElementAt identity/type/comments/argument applied and post-save verified.
- [x] C074/A14 Monitor_Lock identity/type/comments applied and post-save verified.
- [x] C075/A15 Monitor_Unlock identity/type/comments applied and post-save verified.
- [x] C076/A16 Socket_OnStart identity/type/comments applied and post-save verified.
- [x] C077/A17 Socket_OnIdle identity/type/comments/transportMode applied and post-save verified.
- [x] C078/P00-P12 exact protected bytes, bounds, xrefs, cells, no-ops, APIs, comments, and UDT state verified unchanged.
- [x] Combined C001-C078 primary-supervisor verification is `78/78 PASS` with saved IDB SHA256 `3A1DEC510FF692C7B0655764E9CC37036633B876CFDB1146046A1DB8260FE98A`.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000020609","destination_path":"executed-b-agent-research/B008/0004CL-ThreadProc-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004CL-ThreadProc-source-quality.md","timestamp":"2026-08-01T07:57:35-04:00","uid":"0004CL"} -->
<!-- {"agent":"B008","command_id":"000000020617","destination_path":"tools/leaser/Agents/Agent-B008/research/0004CL-ThreadProc-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B008/0004CL-ThreadProc-source-quality.md","timestamp":"2026-08-01T08:09:07-04:00","uid":"0004CL"} -->
<!-- {"agent":"B008","command_id":"000000020628","destination_path":"executed-b-agent-research/B008/0004CL-ThreadProc-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004CL-ThreadProc-source-quality.md","timestamp":"2026-08-01T08:40:15-04:00","uid":"0004CL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
