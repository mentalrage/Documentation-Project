** TARGET-REPORT-UID:0003ZT **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003ZT MapPane HandleSystemOrControlEvent Source Quality


## Finalized Report / Current Recommendation

- Current recommendation: rename and reconstruct [UID:0003ZT] as `bool MapPane::HandleSystemOrControlEvent(Event *event)`, the exact `EventHandler` system/control-family virtual reached from the `MapPane` secondary vtable slot at `0x0061e77c`.
- Final disposition: retain `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007Q`; raise the exact child from `87/89` to `92/94`; preserve the blank emitter-position field because existing address/source ordering already places the method correctly.
- Required action: replace the stale byte-message signature, raw message code, fake refresh helper, and nonexistent `m_timerHandler` member model; synchronize the class/file/layout/vtable/aggregate/timer-state family and every emitted MapPane child still using that nonexistent member; preserve raw queue children as non-emitting evidence; and apply the exact declaration-routing package documented below.
- Confidence: very strong for behavior, ABI, vtable family, event type, field state machine, helper role, owner/emitter route, source order, and the dependency-closed six-block source package. Contextual source-era inference selects `ui/core/Event.h` as the canonical complete UID00004L declaration header, `ui/core/EventHandler.h` as the pointer-interface header, and the existing same-basename project headers listed below for every complete object/member/API dependency; lack of PDB spelling proof caps confidence below 95 but does not defer those routes.
- Lifecycle: the supervisor passed the exact pre-callback report artifact SHA `4CBEA9E9DCA75ABC6907B9C3F7FF3DA491A50F84E506498C85E3C43DB00A64A5` for implementation. B001 completed the accepted ordinary-document callback, serial scoped validation, generated readback, and same-report reconciliation. B001 did not run or probe any report lifecycle command and did not mutate IDA or manual coverage. The timestamped command16920 checkpoint below records the pre-execution `0/0/0` state; any later validator-owned report footer/registry/archive path and regenerated research tracker supersede it.

## Supporting Research

- B001 report-research IDA MCP checkpoint: session `9b0396a3`, health request `9002`, status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. This was the healthy read-only session used to establish the B001 binary evidence; the later supervisor-owned Gate 2B readback is recorded separately under the exact IDA heading.
- Current executable baseline reported by MCP: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Exact target analysis requests: `9010` (`analyze_function 0x00508f60`), `9013` (`xrefs_to` target/helper/vtable slot), and `9014` (`get_bytes` target/boundary/helper).
- Helper-family requests: `9011` (`analyze_function 0x005449f0`), `9012` (`analyze_function 0x004a6f40`), `9015` (`analyze_function 0x005449d0`), and `9016` (`xrefs_to 0x005449d0`).
- Current target SHA-256 is `ACFE0DF9EE39DD2E68B2131E33F30AC7D8F086987D7A6FB4D089A740D8F4C80` over exactly 203 bytes at `[0x00508f60,0x0050902b)`.
- Exact internal alignment SHA-256 is `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329` over five `0xcc` bytes at `[0x0050902b,0x00509030)`.
- Exact `0x005449f0` helper SHA-256 is `02AA21C6F21555114B9E6F0DF9C85B14F3C5BDFFE4B2625BF759D4BC24351AE6` over 14 bytes.
- Historical pre-callback generated-source checkpoint: `auto-generated/NexusTK/map/MapPane.cpp`, command `000000016823`, refreshed `2026-07-23T05:25:07-04:00`, source `foreground-generated-refresh`, SHA-256 `252420F7337C0309ACD06CC2800BEB8D535746CFF17FADC0018EAD7E748F40CD`, 149,195 bytes, 4,477 physical lines. It preserves the exact stale-state baseline used by the report: `OnNotifyMessage`, `RefreshQueuedMapState`, and `m_timerHandler.` pollution before callback.
- Current post-callback generated-source checkpoint: `auto-generated/NexusTK/map/MapPane.cpp`, validator header command `000000016910`, refreshed `2026-07-23T22:20:59-04:00`, source `foreground-generated-refresh`, SHA-256 `765242135150DF94241861C1DE248D8E3C9299C081F584AA695561DC6FFF3E89`, 149,522 bytes / 4,495 physical lines at the final `2026-07-23T22:26:56-04:00` readback. It contains one class declaration and one definition of `HandleSystemOrControlEvent`, one UID0003ZT provenance marker, canonical body/field, inherited TimerHandler calls, `ReleaseMouseCapture`, all required include/extern routes, no target Empty Emitter Marker, zero `OnNotifyMessage`, zero `RefreshQueuedMapState`, zero `m_timerHandler.`, and zero `m_movementTimerQueued`; the only four Empty Emitter Markers remain unrelated UID0004DS/UID00037T/UID0003TN/UID0001SO.
- Current generated dependency checkpoints, all command `000000016910` at `2026-07-23T22:20:59-04:00`, are `Event.cpp` SHA-256 `ABC6BF86E5AFF4BB386AB55F93967F280590209134A76E61152A4344D36CAF3F`, 9,048 bytes / 242 lines; `EventDispatcher.cpp` SHA-256 `263AAFA10835115518592C1C4153B0B2890288EBF8372D8F4429413EBE8730A7`, 19,422 bytes / 601 lines; `Pane.cpp` SHA-256 `83299D7A5BD8465B07AC3BACCE8EF6D477A9C6E03C2239B6CFABADD2DDC4EE33`, 1,423 bytes / 39 lines; `ObjectStatusBlob.cpp` SHA-256 `7309F0CB77472801315819341D45185D40E2890A86C49FA1CA9AFD079DA6F3D5`, 9,097 bytes / 256 lines; and `UserPane.cpp` SHA-256 `151C8BAE885B5490507B3988A22AA5EA7F6F7DB4D0B9DCF4E30B5A6F26A34C8D`, 92,079 bytes / 2,786 lines. The report's explicit header/source graph remains the canonical declaration contract; validator combined `.cpp` artifacts do not replace those inferred header boundaries.
- Historical time-scoped research-tracker checkpoint: command `000000016789`, refreshed `2026-07-23T03:19:21-04:00`, SHA-256 `402719AD13CE298CC753D49546CF8F8187F41C0F30A70AF6178EF3AA71160E14`, 1,637,671 bytes, 6,514 physical lines.
- Current validator-owned tracker/report-count checkpoint: command `000000016920`, refreshed `2026-07-23T22:26:56-04:00` from `deferred-generated-refresh`, SHA-256 `5DE69C1F402CD8FAE6149FF5583027D3909247E19F54739455DDDEE8A885E753`, 1,639,514 bytes / 6,518 physical lines. UID0003ZT is current at physical row `3230`, `92/94`, reconstructable true, and direct/additional/total report coverage `0/0/0`. The zero count is expected before supervisor lifecycle execution; after execution, the validator-owned registry/footer and regenerated tracker supersede this timestamped checkpoint.
- Current validator-owned generated memory-coverage checkpoint: command `000000016920`, refreshed `2026-07-23T22:26:56-04:00`, source `deferred-generated-refresh`, SHA-256 `F7E9026FC2371522BABF835B0CC56F819C35F1F2B0FB2CE892B370FFE989E837`, 1,353,524 bytes / 4,838 physical lines. UID0003ZT is `coded` through owner/emitter UID00007Q and `auto-generated/NexusTK/map/MapPane.cpp`.

### Historical report revalidation

| Historical report | SHA-256 | Accepted after current recheck | Revised or rejected after current recheck |
| --- | --- | --- | --- |
| `executed-b-agent-research/B013/00037U-MapPaneNotifyTimerCore-source-quality.md` | `8DF3EDDB4B2E7506F9282BA3113FF503DA296E3B2F071ECD605A02A88856AE81` | Exact two-child split, target range, secondary-vtable liveness, adjusted receiver, message guard, dialog constructor, and five-byte alignment. | `OnNotifyMessage` / `HandleNotifyMessage`, unresolved `0x005449f0`, and the unresolved `+0x39d` naming pair are superseded by current EventHandler, helper-family, and state-family evidence. |
| `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md` | `1A3A8C37068677B2383B81AD5F8B1FCF0A0FB44973BF4E896647E8DDDC26D8DC` | Exact MapPane aggregate ownership, timer-state family, child boundaries, and modeled clearer route. | The prior generic "refresh" wording is revised to the proven capture/release state transition. |
| `executed-b-agent-research/B010/00042E-MapPaneQueueMovementRefreshTimer6-by-memory-source-quality.md` | `5B6455AFB40AA47DD4A99C61EBC424E42C22CA3CE5C2E9E8BC52F7127DD53610` | Raw no-function/no-route proof, timer-id-6 queue behavior, `+0x39d` state, and distinction between `0x005449d0` and `0x005449f0`. | "Map-refresh wrapper" wording is revised: the pair is `Pane::CaptureMouse` and `Pane::ReleaseMouseCapture`. |
| `executed-b-agent-research/B001/00042G-MapPaneQueueMovementRefreshTimer8-by-memory-source-quality.md` | `906B491DA5B39C40FF9540781A60E3B916AB365DB2CA947D76A0BEFC79283DFA` | Raw no-route proof, timer-id-8 queue behavior, coordinate conversion, `Sleep(100)`, input-blocker gate, and `0x005449d0` capture role. | Provisional `m_timerHandler` member wording is rejected; the timer facet is inherited through `Pane` and should be expressed through `TimerHandler::ScheduleTimer`. |
| `executed-b-agent-research/B002/0002D2-0002D7-0002D5-0002D9-0002DB-FittingRoomScrollPaneInteraction-source-quality.md` | `365C82A9C39BC9BBFAEA1D8EAAAA114847D3B60B14D17C9C16FCB87EA67254D5` | Independent current caller-family evidence naming `0x005449d0` `Pane::CaptureMouse` and `0x005449f0` `Pane::ReleaseMouseCapture`. | No target ownership inference is imported from FittingRoom. |
| `executed-b-agent-research/B002/00030E-TextEditPaneOnMouseEvent-source-quality.md` | `33D628CC2B8C29ACDA18D252F5185B86910E394465D9CB30C0C2B0FC47C2D0FD` | Independent current caller-family confirmation of Capture/Release/HasMouseCapture source vocabulary. | No TextEditPane-specific field or source placement is imported. |

Wave2/Wave3 labels and workflows encountered in old material were ignored. In particular, a stale `ClearActivePaneEntry_5449F0`-style label is not authority; the current helper body, paired helper, manager behavior, broad caller family, and accepted current pane documentation independently establish release semantics.

## Target

- Target UID: `0003ZT`.
- Additional target UIDs: none.
- Declared-target inventory: one primary target, `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md`, exact live secondary-facet `MapPane` system/control event handler.
- Target path: `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md`.
- Source queue/report row: validator-owned tracker command `000000016920`, refreshed `2026-07-23T22:26:56-04:00`, physical row `3230`, tuple `92/94`, reconstructable true, coded, and direct/additional/total report coverage `0/0/0` before supervisor execution.
- Current classification: implementation callback complete and handed to the supervisor as an execution-ready artifact; any later validator-owned footer/registry/archive path is authoritative.
- Current scores and parent state: target `92/94`; canonical owner/emitter [UID:00007Q] `MapPane` remains `93/94`; source root [UID:0000L3] `MapPane` remains `92/92`.

## Current Target State

- Current metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`.
- Current formal C++ is the accepted `MapPane::HandleSystemOrControlEvent(Event *event)` body with `event->m_type`, `kEventWorkNotification`, canonical `m_queuedMapStateRefresh`, inherited TimerHandler cancellation, `ReleaseMouseCapture`, the UrlAlert guard, ordinary ConnectionClosedDialog construction, and exact return behavior.
- Current target/class/file/layout/vtable/aggregate/timer-family prose closes `0x005449f0` as `Pane::ReleaseMouseCapture`, the EventHandler method family, and `+0x39d` as the sole current `bool m_queuedMapStateRefresh`; stale aliases are historicalized.
- Current UID00007Q formal contains the accepted complete/API include package, complete MapPoint before MapPane, exact extern routes, `UserPane *m_localPlayerObjectPane`, the corrected virtual, no fake `RefreshQueuedMapState`, and no `m_timerHandler` member.
- Current sibling formals UID00042F, UID00042I, UID0003ZS, and UID0004QB use explicit inherited TimerHandler qualification. Raw UID00042E/G remain non-emitting with blank formal C++ and exhaustive no-route proof.
- Current generated MapPane.cpp has one declaration and one definition of `HandleSystemOrControlEvent`, canonical source vocabulary, no target Empty Emitter Marker, and zero stale `OnNotifyMessage`, `RefreshQueuedMapState`, `m_timerHandler.`, or `m_movementTimerQueued` occurrences. The four unrelated empty markers remain outside this report.
- [UID00004L] owns the complete `EventType`, `kEventWorkNotification`, payload, and `Event` declaration through [UID0000J6] `Event.cpp`. Ranked project/period inference commits its declaration header to `ui/core/Event.h`: same-basename `.h`/`.cpp` ownership, broad non-dispatcher consumers, and separation from EventHandler traversal internals outweigh the combined-header alternatives. `Event.h` includes exact existing `NexusTK/util/LObject.h` before `class Event : public LObject`, so the proposed canonical header is self-contained.
- [UID0004R0] supplies the exact complete `MapPoint { int row; int column; }` declaration. Highest-probability source shape places that small shared value declaration in `map/MapPane.h` before `MapPane`; its current position-5 ownership remains UID0000L3.
- UID00009S/0000M6, UID0000FQ/0000P1, UID00007B/0000KU, UID00009Q/0000M4, UID0000M8, UID0000DD/0000NS/0000Q5, and UID0003EE establish the complete/status/local-player/living-object/list/packet/socket/global routes. The callback uses `ObjectStatusBlob.h`, `UserPane.h`, `LivingObjectPane.h`, `ObjectList.h`, `PacketBuffer.h`, and `Socket.h`, plus an exact `InputBlockerPane` forward declaration/extern. The field at MapPane `+0x418` is source-typed `UserPane *m_localPlayerObjectPane`: it stores the local UserPane and calls UserPane-only `ProcessMovement`; `UserPane` remains substitutable where inherited LivingObjectPane methods are needed.
- [UID000036]/[UID0000N0] prove the complete `ConnectionClosedDialog` declaration and documented `network/ReconnectDialog.h` route. [UID0000SM]/[UID0000HE] prove `g_pUrlAlertPane` and documented `ui/dialogs/AlertPanes.h`. [UID0000SW]/[UID0000O5] prove the `bool g_useEpfAssets` definition but no shared header basename; the exact current MapPane source-root route is an explicit `extern bool g_useEpfAssets;`.
- Timestamped pre-execution artifact/lifecycle checkpoint: at tracker command16920 (`2026-07-23T22:26:56-04:00`), this same post-callback report was in `tools/leaser/Agents/Agent-B001/research/`, had no validator-owned execution footer/registry entry, and had tracker coverage `0/0/0`. B001's ordinary implementation and scoped validation were complete, and supervisor-owned IDA Gate 2B was applied/read back exactly as recorded. B001 did not run, probe, or dry-run a report lifecycle command. Any later validator-owned footer/registry/archive path and regenerated tracker supersede this timestamped location and count.

## Executive Recommendation

- Direct owner and emitter remain [UID:00007Q][MapPane](by-class/MapPane.md), routed through [UID:0000L3][MapPane](by-file/MapPane.md) to `NexusTK/map/MapPane.cpp`.
- Source method is `bool MapPane::HandleSystemOrControlEvent(Event *event)`. It overrides the inherited EventHandler `+0x14` family slot for event types `20..22`; this concrete body handles `kEventWorkNotification` (`22`).
- Use `event->m_type`, `kEventWorkNotification`, `m_queuedMapStateRefresh`, inherited `TimerHandler::CancelTimer`, and inherited `ReleaseMouseCapture`. Reject raw pointer/offset/number/helper/member forms from decompilation.
- Raise UID0003ZT to `92/94`. Raise the directly corrected UID00042F clearer to `90/92`. Keep the remaining support scores unchanged unless their current metadata is already stale in manual coverage.
- Normalize all current MapPane emitted child calls from nonexistent `m_timerHandler` to explicit inherited `TimerHandler::CancelTimer` / `TimerHandler::ScheduleTimer` so the MapPane class/body vocabulary is internally coherent.
- Extend the UID00007Q source package with `<windows.h>`, inferred canonical `Event.h`, documented `AlertPanes.h` and `ReconnectDialog.h`, complete `ObjectStatusBlob.h`, `UserPane.h`, `LivingObjectPane.h`, `ObjectList.h`, `PacketBuffer.h`, and `Socket.h`, plus exact extern routes for `g_useEpfAssets` and `g_pInputBlockerPane`. Emit complete `MapPoint` before `MapPane`, remove insufficient duplicate forward declarations, and source-type the local-player field as `UserPane *`. Under this committed package, all six displayed blocks are declaration/include dependency-closed.
- Keep raw queue children UID00042E and UID00042G non-emitting with blank C++; update only their canonical field/helper/timer-facet prose.

## Supervisor Active Recheck

- The assignment explicitly requires fresh UID0003ZT report-only research and forbids forwarding the helper/field/name/score blockers.
- No new split is required. The existing UID00037U split is correct: exact target, five-byte internal alignment, exact UID0003ZS timer child, and tail/alignment remain separate.
- Every source-bearing dependency required by the target and its five coordinated sibling formals is included in the proposed callback or bounded as an already-correct read-only header provider: target, class, source root, layout, split parent, timer sibling, vtable, clearer, raw queue siblings, aggregate, pending-action clearer, object-interaction sender, complete Event/LObject declaration owners, EventHandler/EventDispatcher/Pane interface owners, MapPoint, UserPane/InputBlocker, ObjectStatusBlob, LivingObjectPane, ObjectList, PacketBuffer, Socket/g_packetSender, ConnectionClosedDialog, Win32 input declarations, and both other global declaration owners.
- Event/EventType complete-declaration ownership and source factoring are explicit: UID00004L/UID0000J6 own self-contained `Event.h`/`Event.cpp` with exact `LObject.h` base visibility; UID00004N uses separate `EventHandler.h` with only `class Event;` and `class EventDispatcher;`; UID00004M/UID0000J7 use `EventDispatcher.h`, which includes `TimerHandler.h` for its complete base and `EventHandler.h` for handler/record declarations; and `Pane.h` includes `GrafPort.h`, `EventHandler.h`, and `TimerHandler.h` so its complete declaration and both inherited facets are visible. `MapPane.h` includes Pane.h, GrafPort.h, Motion.h, and `<vector>`, and owns MapPoint before MapPane; MapPane.cpp includes the remaining complete-type/API headers before the six definitions.

## Inference Research Guidance Check

- Binary facts establish bytes, exact half-open range, thiscall lowering, secondary receiver, control flow, field offsets, timer arguments, vtable slot, xrefs, callees, guard, allocation size, constructor call, and return values.
- Current documentation establishes the accepted Event/EventHandler type system, type-22 enum, Pane capture/release vocabulary, MapPane class/source route, TimerHandler inheritance policy, and dialog/global types.
- Inference selects plausible human source spelling where original symbols are stripped: `HandleSystemOrControlEvent`, `m_queuedMapStateRefresh`, and explicit inherited TimerHandler qualification. These names are project-consistent and avoid IDA-shaped output.
- Existing documentation was treated as uncertain where it offered unresolved pairs or placeholders. The stale `OnNotifyMessage`, `HandleNotifyMessage`, `RefreshQueuedMapState`, `m_movementTimerQueued`, and `m_timerHandler` forms were rechecked rather than copied.
- Wave2/Wave3 references were ignored as stale.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible result | Evidence and classification | Rejected alternatives |
| --- | --- | --- | --- |
| Method family/name | `MapPane::HandleSystemOrControlEvent(Event *event)` | Direct vtable slot order plus current EventHandler interface; source-facing inferred spelling with binary-proven family/signature. | `OnNotifyMessage`, `HandleNotifyMessage`, raw `sub_508F60`, and `const unsigned char *message`. |
| Parameter/type byte | trusted non-null `Event *event`; discriminator `event->m_type` at `+0x04` | Target raw `Block[4]`; Event exact layout; EventDispatcher family routing. | Raw byte block, extra null guard, or payload subtype at another offset. |
| Message code 22 | `kEventWorkNotification` | Current Event enum and producer/dispatcher evidence; binary immediate `22`. | Magic `22`, packet opcode, chat message, or type-19 application notification. |
| Secondary `this` | EventHandler facet at complete `MapPane+0xa0`; normalize to complete MapPane | Vtable slice and raw `this-0xa0`; state access `this[0x2fd]` becomes complete `+0x39d`; `this+4` becomes complete `+0xa4`. | Embedded independent handler object or standalone callback class. |
| `+0x39d` | `bool m_queuedMapStateRefresh` | Byte test/set/clear across target, UID00042E/F/G, and UID0003ZS; current class already uses this name. | Simultaneous `m_movementTimerQueued`, integer type, or target-only field. |
| Timer facet | inherited `TimerHandler` through Pane; explicit base qualification in source | Complete `MapPane+0xa4` adjusted calls; Pane docs explicitly reject extra direct source base/member; class has no `m_timerHandler`. | Embedded `m_timerHandler` field or handwritten subobject pointer arithmetic. |
| Timer IDs | literal IDs `6` and `8` for this drain | Exact pushes/cancel calls and sibling timer switch. No accepted project enum exists. | Invented enum names or merging both into one timer. |
| `0x005449f0` | `Pane::ReleaseMouseCapture()` / inherited `ReleaseMouseCapture()` | Zero-context manager call, paired nonzero-context `0x005449d0`, 20 call sites across pane interaction handlers, and current accepted pane docs. | Refresh, redraw, active-pane deletion, destructor/reset, or MapPane-owned helper. |
| `0x005449d0` | `Pane::CaptureMouse()` | Passes `this+0xa0` into same manager; paired caller family and accepted docs. | Generic map refresh wrapper. |
| Global mode gate | `bool g_useEpfAssets` | Current typed global UID0000SW; exact byte compare to 1; broad asset-mode consumer set. | MapPane member or narrow attachment/layout-only flag. |
| Dialog guard | `ConnectionClosedDialog` creation is gated by `g_pUrlAlertPane == NULL` | Current typed global and direct branch. | Treating the constructed object as UrlAlertPane. |
| Allocation/construction | ordinary `new ConnectionClosedDialog;` | Exact allocation size 624/`0x270`, unique direct call to exact no-argument constructor UID00023O, current class size/source route. | Manual allocator call, explicit null branch in human source, or UrlAlertPane construction. |
| Allocation-null behavior | return `true` after the attempted `new` path even when machine allocator returned null | Target CFG returns true outside the compiler-lowered constructor null check. | Returning false when allocation returns null. |
| Source placement | `NexusTK/map/MapPane.cpp` in exact address/source order after UID00037T and before UID0003ZS | Existing owner/file route and generated child ordering. | EventDispatcher.cpp, Pane.cpp, ReconnectDialog.cpp, standalone helper file, or split aggregate body. |
| Complete Event visibility | canonical complete contract is UID00004L through UID0000J6 in inferred `ui/core/Event.h` / `Event.cpp` | Complete enum/class formal, same-basename file ownership, broad non-dispatcher consumers, Event.cpp generated root, EventHandler forward-only interface, and period/project module style. | Combining the large record into `EventHandler.h`/`EventDispatcher.h`, relying on unnamed PCH/transitive inclusion, or duplicating Event in MapPane.cpp. |
| Complete dialog visibility | include documented `ReconnectDialog.h` | UID000036 complete declaration and UID0000N0 documented header/source route. | Forward declaration at `new`, transitive include guess, or moving constructor ownership. |
| Alert global visibility | include documented `AlertPanes.h`, whose header contract exports `g_pUrlAlertPane` | UID0000HE documented header and UID0000SM definition/owner route. | Depending silently on ReconnectDialog.h transitively or defining the pointer in MapPane.cpp. |
| Asset-mode global visibility | direct source-root `extern bool g_useEpfAssets;`; definition remains UID0000SW/UID0000O5 | Exact global formal, process-wide reads, unique StartupWindow writer, and absence of a proven shared header basename. | Inventing a global header or duplicating the definition. |
| Event header factoring | rank 1 `Event.h`; rank 2 `EventHandler.h`; rank 3 combined `EventDispatcher.h`; rank 4 `Pane.h` | Dedicated Event.cpp ownership and broad factories/consumers favor same-basename Event.h; EventHandler docs favor its own small interface header; EventDispatcher.h is already dispatcher-specific; Pane.h is only a consumer/base route. | Leaving the basename open because no PDB survives. |
| Score blocker | target can reach `92/94` under committed Event.h source factoring | All behavior, helper, field, signature, C++, declaration, and source-placement blockers are closed; remaining uncertainty is inferred original spelling/factoring. | Deferring the route or leaving decompiler labels. |

The remaining uncertainty is lexical and historical, not implementation-blocking: no source symbol proves the developers' exact spelling of the event-family virtual, `+0x39d` field, or Event header basename. Project structure and period style make `Event.h` the highest-probability human answer, so it is committed rather than deferred. That inferred factoring and stripped names cap confidence below 95 but permit `92/94` compile-visible source.

## Evidence Standards Used

- Direct evidence: MCP function model/decompile, exact bytes and hashes, vtable/data xrefs, caller/callee sets, paired helper bodies, field offsets, constants, branches, allocation size, constructor call, and boundary padding.
- Current documentation evidence: Event/EventHandler formals, MapPane class/file/layout/vtable/aggregate/timer pages, TimerHandler wrappers, Pane capture/release consumer pages, globals, dialog constructor, generated output, and manual coverage.
- Negative evidence: zero ordinary target code callers, sole vtable data xref, no need for a new source owner, no independent helper role for `0x005449f0`, no `m_timerHandler` declaration, no source enum for timer IDs 6/8, no reason to merge the sibling timer function, and no target-specific generated empty marker.
- Evidence ladder: direct binary facts control behavior; current typed docs control shared source vocabulary; inference supplies human lexical/source shape only after alternatives are tested.
- Tool limitations: stripped symbols prevent original lexical/header proof, but the workflow requires a ranked human answer. Dedicated `Event.h` is the committed highest-probability route; validator source-only output limitations do not make the reconstructed source contract incomplete.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: server health; `analyze_function` target, helper pair, and manager; xrefs to target, release helper, and capture helper; exact target/helper/boundary bytes; vtable slot values and adjusted receiver arithmetic.
- Current by-* docs: target, MapPane class/file/layout/vtable/aggregate/split parent/timer state family, Event/EventHandler, TimerHandler wrappers, `g_useEpfAssets`, `g_pUrlAlertPane`, ConnectionClosedDialog constructor, FittingRoom/Icons/Scroll/TextEdit capture-release consumers.
- Historical reports searched with `0003ZT`, `0x00508f60`, `00037U`, `0x005449f0`, `00042E`, and `00042G`; only matching reports were opened as leads and revalidated.
- Generated/tracker checks: historical pre-callback command16823 plus current post-callback MapPane/Event/EventDispatcher/Pane/ObjectStatusBlob/UserPane command16910 generated artifacts and command16920 generated-memory/research-tracker checkpoints; older command16816/16814/16811/16808/16807/16806/16805/16803/16802 and command16789/16797 roots remain historical; all relevant manual coverage rows were reread without editing.
- Declaration-route checks: complete UID00004L Event formal and UID0000J6 ownership; UID00004N/UID0000J7 forward-only EventHandler interface; UID000036/UID0000N0 complete dialog and documented `ReconnectDialog.h`; UID0000SM/UID0000HE alert global and documented `AlertPanes.h`; UID0000SW/UID0000O5 asset-mode definition ownership; current generated source roots and absence of a projected Event header.
- Negative checks: target direct-call absence, target single vtable route, unrelated generated empty markers, nonexistent `m_timerHandler` class member, stale helper/name alternatives, source-owner alternatives, merge alternatives, unnamed-PCH reliance, duplicate Event declarations, combined dispatcher/record headers, Pane.h ownership, and duplicate global definitions.
- Failed/unavailable checks during B001 research: none. MCP remained healthy and B001 made no IDA mutation. The supervisor later applied and read back the accepted IDA changes under the current Gate 2B role boundary.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3ZT-01 | 0003ZT | Exact source body is `[0x00508f60,0x0050902b)`, 203 bytes, SHA-256 `ACFE...4C80`. | direct/very strong | MCP 9010/9014 | target Range/IDA evidence | incorporate | incorporated-verified |
| C3ZT-02 | 0003ZT | `[0x0050902b,0x00509030)` is five `0xcc` alignment bytes with SHA-256 `992C...7329`. | direct/very strong | MCP 9014 | target and UID00037U range ledger | incorporate | incorporated-verified |
| C3ZT-03 | 0003ZT | IDA models one 203-byte thiscall function with 13 blocks and complexity 4. | direct/very strong | MCP 9010 | target IDA facts | incorporate | incorporated-verified |
| C3ZT-04 | 0003ZT | Sole inbound route is data xref `0x0061e77c -> 0x00508f60`; absence of direct callers is expected virtual dispatch. | direct/very strong | MCP 9010/9013 | target/vtable/parent | incorporate | incorporated-verified |
| C3ZT-05 | 0003ZT | Slot `0x0061e77c` is EventHandler system/control `+0x14`, not a generic notify block. | very strong | vtable order + EventHandler docs | target/class/vtable/file | incorporate | incorporated-verified |
| C3ZT-06 | 0003ZT | Source signature is `bool MapPane::HandleSystemOrControlEvent(Event *event)`. | very strong inferred source | C3ZT-05 + ABI | target/class | incorporate | incorporated-verified |
| C3ZT-07 | 0003ZT | Secondary receiver is complete `MapPane+0xa0`; raw accesses normalize through `this-0xa0`. | direct/very strong | target decompile/vtable | target/vtable/class | incorporate | incorporated-verified |
| C3ZT-08 | 0003ZT | Parameter discriminator is `event->m_type` at Event `+0x04`. | very strong | raw `Block[4]` + Event layout | target/class/file | incorporate | incorporated-verified |
| C3ZT-09 | 0003ZT | Immediate 22 is `kEventWorkNotification`. | very strong | Event enum/producer + binary | target/class/file/vtable | incorporate | incorporated-verified |
| C3ZT-10 | 0003ZT | The pending-state drain executes before the type-22 test and therefore occurs for every incoming system/control event. | direct/very strong | target CFG | target behavior/C++ | incorporate | incorporated-verified |
| C3ZT-11 | 0003ZT | Global gate is typed `bool g_useEpfAssets`, true only in the observed branch. | very strong | target bytes + UID0000SW | target behavior | incorporate | incorporated-verified |
| C3ZT-12 | 0003ZT | Complete-object `+0x39d` is `bool m_queuedMapStateRefresh`. | very strong | state-family reads/writes + current class | target/class/layout/timer family | incorporate | incorporated-verified |
| C3ZT-13 | 0003ZT | `m_movementTimerQueued` is a superseded descriptive alias, not a simultaneous current name. | strong | family reanalysis | class/layout/target/history | historicalize | incorporated-verified |
| C3ZT-14 | 0003ZT | Complete-object `+0xa4` is the inherited TimerHandler facet, not `m_timerHandler`. | very strong | adjusted calls + Pane policy + class absence | target/class/emitted siblings | incorporate | incorporated-verified |
| C3ZT-15 | 0003ZT | Pending drain clears the flag then cancels IDs 6 and 8 in that exact order. | direct/very strong | target bytes/decompile | target/UID00042F | incorporate | incorporated-verified |
| C3ZT-16 | 0003ZT | `0x005449f0` is `Pane::ReleaseMouseCapture`; helper is 14 bytes with SHA-256 `02AA...1AE6`. | very strong | MCP 9011-9013 + consumer docs | target/42E/42F/42G/parent/file/class | incorporate | incorporated-verified |
| C3ZT-17 | 0003ZT | `0x005449d0` is paired `Pane::CaptureMouse`, passing receiver `this+0xa0`. | very strong | MCP 9015/9016 | raw queue supports/aggregate | incorporate | incorporated-verified |
| C3ZT-18 | 0003ZT | Shared manager `0x004a6f40` stores capture handler/state on nonzero input and clears both on zero input. | direct/very strong | MCP 9012 | target/helper rationale | incorporate | incorporated-verified |
| C3ZT-19 | 0003ZT | `RefreshQueuedMapState` is an invalid invented helper and must be removed from class and bodies. | very strong | C3ZT-16/18 | target/class/UID00042F/generated checks | reject-invalid | incorporated-verified |
| C3ZT-20 | 0003ZT | Type mismatch returns false after any applicable pending-state drain. | direct/very strong | target CFG | target behavior/C++ | incorporate | incorporated-verified |
| C3ZT-21 | 0003ZT | Type 22 with non-null `g_pUrlAlertPane` returns false. | direct/very strong | target CFG/global | target behavior/C++ | incorporate | incorporated-verified |
| C3ZT-22 | 0003ZT | Type 22 with null guard allocates exactly 624/`0x270` bytes. | direct/very strong | target bytes/decompile | target behavior | incorporate | incorporated-verified |
| C3ZT-23 | 0003ZT | Direct constructor is UID00023O `ConnectionClosedDialog::ConnectionClosedDialog()`. | very strong | unique call `0x508ffc -> 0x553c10` | target behavior/C++ | incorporate | incorporated-verified |
| C3ZT-24 | 0003ZT | Human source is ordinary `new ConnectionClosedDialog;`; allocator/null test is compiler/custom-new lowering. | strong source inference | allocation/constructor pattern | target C++/history | incorporate | incorporated-verified |
| C3ZT-25 | 0003ZT | Function returns true after the attempted allocation path even if the machine allocator returned null. | direct/very strong | target CFG | target behavior/C++ | incorporate | incorporated-verified |
| C3ZT-26 | 0003ZT | No event null check exists; source trusts dispatcher contract. | direct/very strong | target CFG | target behavior/negative evidence | incorporate | incorporated-verified |
| C3ZT-27 | 0003ZT | Owner/emitter remain UID00007Q MapPane; source root remains UID0000L3. | very strong | receiver/state/vtable/source tree | target metadata/class/file | already-present | incorporated-verified |
| C3ZT-28 | 0003ZT | Target remains after UID00037T and before UID0003ZS in MapPane.cpp. | very strong | address/generated order | target/file/parent | already-present | incorporated-verified |
| C3ZT-29 | 00037U | Split parent remains non-emitting because it spans two source methods plus alignment/tail bytes. | very strong | exact split inventory | parent | already-present | incorporated-verified |
| C3ZT-30 | 0003ZS | Sibling begins at `0x00509030`; target must not absorb it. | direct/very strong | bytes/functions/vtable | target/parent/timer sibling | already-present | incorporated-verified |
| C3ZT-31 | 00007Q | Class virtual changes to `HandleSystemOrControlEvent(Event *event)`. | very strong | C3ZT-05/06 | by-class/MapPane formal/prose | incorporate | incorporated-verified |
| C3ZT-32 | 00007Q | Remove fake private `RefreshQueuedMapState`; retain canonical bool field. | very strong | helper/field closure | by-class/MapPane formal/prose | incorporate | incorporated-verified |
| C3ZT-33 | 00042F | Clearer formal uses inherited `TimerHandler::CancelTimer(6/8)` and `ReleaseMouseCapture()`. | very strong | exact sibling body + helper closure | UID00042F formal/prose | incorporate | incorporated-verified |
| C3ZT-34 | 00042I | Pending-action clearer uses inherited `TimerHandler::CancelTimer(7)`. | very strong | exact adjusted facet | UID00042I formal/prose | incorporate | incorporated-verified |
| C3ZT-35 | 0003ZS | Timer callback uses inherited `TimerHandler::ScheduleTimer` for IDs 7/6/8. | very strong | exact adjusted facet | UID0003ZS formal/prose | incorporate | incorporated-verified |
| C3ZT-36 | 0004QB | Interaction sender uses inherited `TimerHandler::ScheduleTimer(5,4000,0,0)`. | very strong | exact adjusted facet | UID0004QB formal/prose | incorporate | incorporated-verified |
| C3ZT-37 | 00042E | Raw timer-6 page retains no-route/no-code status but names `CaptureMouse`, `ReleaseMouseCapture`, canonical field, and inherited TimerHandler facet. | strong | current raw proof + helper closure | UID00042E prose/item summary | incorporate | incorporated-verified |
| C3ZT-38 | 00042G | Raw timer-8 page retains no-route/no-code status but removes provisional member/helper ambiguity. | strong | current raw proof + helper closure | UID00042G prose/item summary | incorporate | incorporated-verified |
| C3ZT-39 | 0001AP | Aggregate keeps source-range-index role and incorporates canonical capture/release/timer-state family. | strong | child family | UID0001AP prose/item summary | incorporate | incorporated-verified |
| C3ZT-40 | 0002SQ | Vtable page names the exact EventHandler slot/signature/type-22 role and keeps compiler-regenerated disposition. | very strong | vtable/Event evidence | UID0002SQ | incorporate | incorporated-verified |
| C3ZT-41 | 00042K | Layout uses one current `m_queuedMapStateRefresh` name and historicalizes the alternate. | very strong | state-family evidence | UID00042K | incorporate | incorporated-verified |
| C3ZT-42 | 0003ZT | Target score becomes `92/94`, owner/emitter/reconstructable unchanged; inferred `Event.h` closes the complete-type route while stripped spelling/factoring caps confidence below 95. | strong | blocker closure + ranked source-route audit | target metadata/manual | incorporate | incorporated-verified |
| C3ZT-43 | 00042F | Clearer score becomes `90/92` after exact helper/facet/source closure. | strong | blocker closure | UID00042F metadata/manual | incorporate | incorporated-verified |
| C3ZT-44 | support | UID00007Q, 0000L3, 00042K, 00037U, 0003ZS, 0002SQ, 00042E, 00042G, 0001AP, 00042I, and 0004QB retain current ordinary scores unless explicitly changed above. | strong | current metadata | support docs/manual | already-present | incorporated-verified |
| C3ZT-45 | 0003ZT | Item Summary must use exact system/control event, release-capture, Event enum, guard, constructor, and return semantics. | strong | complete report | target metadata prose | incorporate | incorporated-verified |
| C3ZT-46 | 0003ZT | Historical unresolved names remain only in labeled rejected/superseded history. | strong | old/current comparison | all changed docs | historicalize | incorporated-verified |
| C3ZT-47 | 0003ZT | Generated acceptance requires no target empty marker and zero current `OnNotifyMessage`, `RefreshQueuedMapState`, `m_timerHandler.`, or `m_movementTimerQueued` source vocabulary. | strong | current generated audit | generated readback after callback | incorporate | incorporated-verified |
| C3ZT-48 | 0003ZT | Generated source must contain one class declaration and one definition for `HandleSystemOrControlEvent`, canonical field use, inherited TimerHandler calls, ReleaseMouseCapture, complete MapPoint before use, `<windows.h>`, Event/ObjectStatusBlob/UserPane/LivingObjectPane/ObjectList/PacketBuffer/Socket/AlertPanes/ReconnectDialog declarations, exact externs, and unchanged unrelated marker inventory. | strong | full six-block source-closure audit | generated readback after callback | incorporate | incorporated-verified |
| C3ZT-49 | support | Manual coverage needs exact no-loss rows for every changed page; B001 must not edit coverage. | strong | current manual-row audit | five manual coverage files | incorporate | pending-supervisor-manual |
| C3ZT-50 | 0003ZT | Current tracker/generated identities are bounded checkpoints and must be reread after callback validators. | strong | validator-owned headers | report Validator Results/Changed Files | incorporate | incorporated-verified |
| C3ZT-51 | 00004L | UID00004L through UID0000J6 is the canonical complete owner for `EventType`, `kEventWorkNotification`, Event payload, and Event; `ui/core/Event.h` must include existing `NexusTK/util/LObject.h` before the complete declaration, while Event.cpp owns definitions/factories. | very strong | complete Event/LObject formals, same-basename ownership, broad consumers, period module style | Event class/file and MapPane source contract | incorporate | incorporated-verified |
| C3ZT-52 | 00004N | `ui/core/EventHandler.h` forward-declares Event and EventDispatcher, defines EventPointPair/EventHandler, and declares `extern EventDispatcher *g_pEventDispatcher`; EventHandler.cpp includes EventDispatcher.h for the forwarding-body member call. It must not redeclare a partial EventDispatcher class. | strong | current handler formal, dispatcher ownership, pointer-only Event signatures | EventHandler class + EventDispatcher class/file + Pane class/file | incorporate | incorporated-verified |
| C3ZT-53 | support | Exact include graph is: Event.h -> LObject.h; EventHandler.h -> forward Event/EventDispatcher only; EventDispatcher.h -> TimerHandler.h + EventHandler.h, with dispatcher-local record/storage declarations before the full dispatcher shell; Pane.h -> GrafPort.h + EventHandler.h + TimerHandler.h; MapPane.h -> Pane.h + GrafPort.h + Motion.h + `<vector>`, with complete MapPoint before MapPane; MapPane.cpp -> MapPane.h plus all source-only complete/API dependencies. | strong | docs/generated/source-tree/project-style reanalysis | Event/EventHandler/EventDispatcher/Pane/MapPane support docs | incorporate | incorporated-verified |
| C3ZT-54 | 000036 | UID000036 is the complete `ConnectionClosedDialog` declaration and UID0000N0 documents `network/ReconnectDialog.h`; UID00007Q must include `ReconnectDialog.h` before using `new ConnectionClosedDialog`. | very strong | complete class formal + documented header route | ConnectionClosedDialog/ReconnectDialog/MapPane class/file | incorporate | incorporated-verified |
| C3ZT-55 | 0000SM | UID0000SM is the `g_pUrlAlertPane` definition under UID0000HE, whose documented `ui/dialogs/AlertPanes.h` is the evidence-backed declaration route; UID00007Q must include `AlertPanes.h`. | very strong | global/file ownership + documented header | g_pUrlAlertPane/AlertPanes/MapPane class/file | incorporate | incorporated-verified |
| C3ZT-56 | 0000SW | UID0000SW defines `bool g_useEpfAssets` through UID0000O5, but no shared header basename is proven; MapPane must use `extern bool g_useEpfAssets;` without duplicating the definition. | very strong | global formal, owner route, broad xrefs | g_useEpfAssets/MapPane class/file | incorporate | incorporated-verified |
| C3ZT-57 | 00007Q | UID00007Q must remove incomplete Event/MapPoint/ObjectStatusBlob/LivingObjectPane/ObjectList-only reliance; add the exact include/extern package, define complete MapPoint before MapPane, forward InputBlockerPane, source-type `+0x418` as `UserPane *`, and preserve all unrelated declaration/layout content. | strong | C3ZT-51..56 plus complete six-block dependency audit | UID00007Q exact formal + MapPoint/UserPane supports | incorporate | incorporated-verified |
| C3ZT-58 | 0000L3 | Canonical MapPane.h/MapPane.cpp factoring is dependency-closed: MapPane.h includes Pane.h, GrafPort.h, Motion.h, and `<vector>`, then carries complete MapPoint and the MapPane class; MapPane.cpp includes `<windows.h>`, Event.h, ObjectStatusBlob.h, UserPane.h, LivingObjectPane.h, ObjectList.h, PacketBuffer.h, Socket.h, AlertPanes.h, and ReconnectDialog.h before affected definitions. | strong | generated-root separation + documented same-basename headers + ranked source-era factoring | MapPane and dependency-owner docs/generated acceptance | incorporate | incorporated-verified |
| C3ZT-59 | 0003ZT | The target and all five coordinated formal siblings are compile-visible and behavior/source-shape ready only under the complete C3ZT-51..58 graph; that closed graph justifies `92/94`, while missing PDB spelling remains a confidence cap. | strong | complete blocker audit including UID0003ZS/UID0004QB | target score/readiness/open questions | incorporate | incorporated-verified |
| C3ZT-60 | support | Callback acceptance must verify the complete include graph, exact complete/forward declaration order, `UserPane *` local-player field, Win32 API visibility, PacketBuffer prototypes, Socket/g_packetSender visibility, no duplicate Event/global definition, and no undeclared incomplete-object/member use across all six emitted blocks. | strong | dependency closure matrix | validators/generated readback/checklist | incorporate | incorporated-verified |
| C3ZT-61 | support | Exact no-loss manual rows and ordinary support documentation must cover every proposed editable dependency page while ObjectList, LivingObjectPane, PacketBuffer, Socket/g_packetSender, LObject, TimerHandler, and StartupWindow remain explicit read-only providers unless callback evidence contradicts their already-correct declarations. None is an additional report target. | strong | support/manual audit | support docs and supervisor-owned manual files | incorporate | incorporated-verified |

## Positive Evidence Summary

- The target is a modeled function with exact bytes, normal prologue/epilogue, one live data route, and a complete decompile whose branches match the proposed source.
- Vtable slot `0x0061e77c` aligns exactly with EventHandler system/control slot `+0x14`, while the target reads the Event type byte at `+0x04` and compares it to the accepted enum value 22.
- Secondary-receiver arithmetic independently normalizes MapPane state `+0x39d` and TimerHandler facet `+0xa4`.
- The capture/release helper pair is behaviorally symmetric: `0x005449d0` supplies a handler pointer and `0x005449f0` supplies null to the same manager. Twenty release call sites and sixteen capture call sites span canonical pane interaction code.
- UID00023O independently proves the exact no-argument ConnectionClosedDialog constructor and identifies this target as its sole caller.
- Current class/file/generated ordering already supplies a valid owner/emitter/source position. The remaining work is vocabulary and source closure, not ownership invention.
- UID00004L's large value record and enums have independent UID0000J6 Event.cpp ownership and broad producer/consumer use, while UID00004N uses only Event pointers and UID0000J7 has a separately documented dispatcher header. Combined with the project's repeated same-basename `.h`/`.cpp` modules, this positively favors dedicated `ui/core/Event.h` over EventHandler.h, EventDispatcher.h, or Pane.h ownership.

## IDA MCP Facts

- Function: `sub_508F60`, address `0x00508f60`, size `0xcb` / 203, raw prototype `char __thiscall(_BYTE *this, _BYTE *Block)`, 13 basic blocks, cyclomatic complexity 4.
- Callees: `sub_597610`, `sub_5449F0`, `sub_4F4AA0`, and `sub_553C10`.
- Callers: no ordinary modeled code callers.
- Xrefs: sole inbound data xref `0x0061e77c`; this is the live secondary-vtable route.
- Target bytes begin `55 8b ec 6a ff 68 73 25 60 00 ...` and end in the distinct false/true return epilogues; exact hash is recorded above.
- Boundary bytes at `0x0050902b` are `cc cc cc cc cc`; successor `0x00509030` starts a separate modeled function.
- Raw target semantics: compare `byte_66DA97` to one; test and clear adjusted field; cancel timer 6 then 8; call `0x005449f0`; compare Event byte `+4` with `0x16`; reject non-null global `0x0069b4dc`; allocate `0x270`; call `0x00553c10`; return one.
- `0x005449f0`: 14-byte, one-block function, `return sub_4A6F40(unk_67AB30, 0)`, 20 call sites in 14 caller functions.
- `0x005449d0`: 25-byte, one-block thiscall, passes `this ? this+0xa0 : 0`, 16 call sites in 12 caller functions.
- `0x004a6f40`: 53-byte manager operation; nonzero argument populates handler/state fields and zero clears both.
- Negative IDA facts: no direct target callers, no second target entry, no evidence that `0x005449f0` refreshes map state, and no evidence that the constructed object is UrlAlertPane.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00508f60-0x0050902b` | UID0003ZT target | `MapPane::HandleSystemOrControlEvent` | true | UID00007Q | `87/89 -> 92/94` | compile-visible through committed Event.h route |
| `0x0050902b-0x00509030` | UID0000VN ignored coverage | five-byte alignment | ignored | UID00037U range | 100 | unchanged |
| `0x00509030-0x00509439` | UID0003ZS | `MapPane::OnTimerEvent` | true | UID00007Q | `88/89` | body retained; TimerHandler source shape normalized |
| `0x00508f60-0x00509470` | UID00037U | split index over target/timer/alignment/tail | false | UID00007Q | `88/90` | non-emitting unchanged |
| `0x0061e71c-0x0061e7a0` | UID0002SQ | MapPane compiler-generated vtable data | true | UID00007Q | `88/92` | covered-by/class-regenerated |
| `0x00505c00-0x00505cb1` | UID00042E | raw timer-6 queue helper | true | UID00007Q | `87/90` | non-emitting/no-route; prose sync |
| `0x00505cc0-0x00505cf9` | UID00042F | clear queued map state | true | UID00007Q | `87/89 -> 90/92` | source-ready after helper closure |
| `0x00505d00-0x00505d9a` | UID00042G | raw timer-8 queue helper | true | UID00007Q | `87/89` | non-emitting/no-route; prose sync |
| `0x00505de0-0x00505dfe` | UID00042I | clear action poll | true | UID00007Q | `87/89` | body retained; TimerHandler source shape normalized |
| `0x0050b1b0-0x0050b2af` | UID0004QB | object interaction sender | true | UID00007Q | `92/94` | body retained; TimerHandler source shape normalized |
| `0x005449d0-0x005449e9` | shared Pane helper | `Pane::CaptureMouse` | true/shared | Pane/EventMan family | documented | read-only evidence |
| `0x005449f0-0x005449fe` | shared Pane helper | `Pane::ReleaseMouseCapture` | true/shared | Pane/EventMan family | documented | read-only evidence |
| `0x00553c10-0x00553cbf` | UID00023O | `ConnectionClosedDialog()` | true | UID000036 | `92/94` | read-only constructor evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061e77c` | data xref to `0x00508f60` | sole target route; MapPane EventHandler system/control slot |
| `0x00508fb4`, `0x00508fc1` | calls `0x00597610` | cancel timer IDs 6 and 8 through adjusted TimerHandler facet |
| `0x00508fc8` | calls `0x005449f0` | release mouse capture after draining queued state |
| `0x00508fe4` | calls `0x004f4aa0(624)` | allocation lowering |
| `0x00508ffc` | calls UID00023O `0x00553c10` | unique ConnectionClosedDialog default-constructor route |
| `0x0041d8bf` | UID0002D2/FittingRoom scroll caller -> release | pane mouse-release family |
| `0x00459aaf` | RankingEventScrollPane caller -> release | pane mouse-release family |
| `0x00497508` | SliderControlPane caller -> release | pane mouse-release family |
| `0x004cf729` | IconsPane caller -> release | pane mouse-release family |
| `0x00505cf2` | UID00042F clearer -> release | same MapPane state drain as target |
| `0x0050c8db`, `0x0050cf8a`, `0x0050cfca` | MapPane path helpers -> release | additional MapPane release contexts |
| `0x0050d1b6`, `0x0050d7b8`, `0x0050d7f8` | MapPane path helpers -> release | additional MapPane release contexts |
| `0x0055c44e`, `0x0055c562` | ScrollPane caller -> release | generic scroll interaction |
| `0x0055f69f` | ScrollSpellInventoryPane caller -> release | pane interaction |
| `0x00560b4f` | ScrollNewGroupPane caller -> release | pane interaction |
| `0x00561fff` | ScrollCollectionPane caller -> release | pane interaction |
| `0x005634af` | ScrollInventoryPane caller -> release | pane interaction |
| `0x0056495f` | ScrollVolumePane caller -> release | pane interaction |
| `0x0059113b` | TextEditPane caller -> release | text-edit mouse interaction |
| `0x00505ca7`, `0x00505d8f` | raw UID00042E/G -> capture | queue paths acquire capture before timer work |

## Documentation Evidence And IDA Status

- [UID00004N] EventHandler fixes the slot order as packet `+0x10`, system/control `+0x14`, and type-19 `+0x18`; types 20 through 22 route to system/control.
- [UID00004L] Event fixes `m_type` at `+0x04` and names 22 `kEventWorkNotification`.
- [UID00004L]/[UID0000J6] own the only complete current Event/EventType declaration. Ranked contextual inference places it in self-contained `ui/core/Event.h` including exact existing `util/LObject.h`; [UID00004N] belongs in separate `EventHandler.h`; [UID00004M]/[UID0000J7] retain `EventDispatcher.h` with exact TimerHandler.h/EventHandler.h prerequisites; and UID0000A2/UID0000MC consume complete GrafPort plus EventHandler/TimerHandler facets through Pane.h.
- UID0002SQ fixes the MapPane secondary table and target slot, while UID00037U fixes the source-range split.
- UID00042E/F/G and UID0003ZS establish the complete `+0x39d` set/test/clear/timer state machine.
- Current FittingRoom, Ranking, Icons, ScrollPane, and TextEditPane pages independently use `CaptureMouse` / `ReleaseMouseCapture` for the same helper pair.
- UID0000SW types `g_useEpfAssets` as `bool` and routes its definition to UID0000O5 StartupWindow; no shared header name is proven, so an explicit MapPane source-root `extern` is required.
- UID0000SM types `g_pUrlAlertPane` and routes through UID0000HE, whose current file page explicitly documents `ui/dialogs/AlertPanes.h`.
- UID00023O provides exact ConnectionClosedDialog constructor source, while UID000036/UID0000N0 provide the complete class and explicitly documented `network/ReconnectDialog.h` route.
- UID0004R0 supplies the exact complete two-int MapPoint declaration; UID0000L3's documented MapPane.h/MapPane.cpp pair is its strongest header route. UID0000FQ proves the local-player object is a UserPane and supplies `ProcessMovement`, UID0003EE supplies the InputBlocker singleton declaration, UID00009S supplies ObjectStatusBlob, UID00009Q supplies ObjectList, UID00007B supplies LivingObjectPane, UID0000M8 supplies PacketBuffer.h prototypes, and UID0000DD/UID0000NS/UID0000Q5 supply Socket.h plus `extern Socket *g_packetSender`.
- `<windows.h>` is the exact platform declaration route for `GetAsyncKeyState` and `VK_LBUTTON`; no project wrapper or PCH-only assumption is accepted.
- B001 did not mutate IDA. The supervisor-owned accepted Gate 2B changes were independently saved/read back and remain recorded verbatim under the exact IDA heading.
- Generated MapPane.cpp command16823 is retained only as the exact pre-callback pollution baseline. Current command16910 generated output and command16920 tracker/memory output confirm the callback result; their timestamped identities and semantic counts are recorded under Supporting Research and Validator Results.

## Ranked Ownership Analysis

### 1. UID00007Q MapPane through UID0000L3 MapPane.cpp

- Evidence for: complete-object state, three MapPane vtable views, class virtual override, TimerHandler/EventHandler inherited facets, adjacent MapPane methods, existing owner/emitter route, generated source order, and MapPane-only timer state.
- Evidence against: none material. The dialog constructor and shared helpers are dependencies, not owners.
- Decision: retain canonical owner/emitter UID00007Q and file route UID0000L3.

### 2. Event / EventHandler / EventDispatcher infrastructure

- Evidence for: UID00004L defines the complete Event/EventType contract; UID00004N defines the virtual family and currently uses only an Event forward declaration.
- Evidence against: target mutates MapPane fields, uses MapPane timer state, and occupies a concrete MapPane vtable slot.
- Decision: type/interface dependency, not source owner. Commit the complete record/enums to self-contained `Event.h` including LObject.h; commit pointer interfaces to EventHandler.h without a partial dispatcher redeclaration; commit the complete dispatcher shell to EventDispatcher.h after TimerHandler.h and EventHandler.h; make Pane.h include GrafPort.h, EventHandler.h, and TimerHandler.h; and make MapPane.cpp include Event.h rather than duplicating Event.

### 3. ReconnectDialog / ConnectionClosedDialog

- Evidence for: target constructs a ConnectionClosedDialog.
- Evidence against: constructor is only a callee after MapPane event and state handling; it has its own owner/file route.
- Decision: callee dependency, not target owner. The complete type is consumed through the documented `ReconnectDialog.h` route.

### 4. Pane / TimerMgr shared helpers

- Evidence for: capture/release and timer operations are shared.
- Evidence against: helpers operate on inherited facets supplied by the MapPane object and do not own the event method.
- Decision: dependency ownership only.

### 5. AlertPanes and StartupWindow globals

- Evidence for: UID0000SM/UID0000HE own `g_pUrlAlertPane` and document `AlertPanes.h`; UID0000SW/UID0000O5 own the definition of `g_useEpfAssets`.
- Evidence against: neither global owns the MapPane method. No current evidence proves a shared header basename for `g_useEpfAssets`.
- Decision: consume `g_pUrlAlertPane` through documented `AlertPanes.h`; declare `extern bool g_useEpfAssets;` at the MapPane source root; never duplicate either definition.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/map/MapPane.cpp` is the exact method source root.
- No standalone notify helper, event file, dialog file move, or aggregate-emitted wrapper is justified.

## Source Placement

- Recommended placement: one `MapPane::HandleSystemOrControlEvent(Event *event)` definition in `NexusTK/map/MapPane.cpp`.
- Declaration placement: UID00007Q MapPane class, in existing EventHandler override order after `HandlePacketEvent` and before `OnTimerEvent`.
- Definition order: after UID00037T packet dispatcher and before UID0003ZS timer handler, matching exact addresses and current generator order.
- Shared helpers remain declared through Pane/EventHandler/TimerHandler infrastructure; no local fake helper or member is introduced.
- Header graph: `Event.h` includes `LObject.h`; `EventHandler.h` forward-declares Event/EventDispatcher and owns EventHandler/EventPointPair/dispatcher extern declarations; `EventDispatcher.h` includes TimerHandler.h and EventHandler.h before its dispatcher-local record/storage and complete dispatcher declarations; `Pane.h` includes GrafPort.h, EventHandler.h, and TimerHandler.h; `MapPane.h` includes Pane.h, GrafPort.h, Motion.h, and `<vector>`, then places the exact UID0004R0 MapPoint declaration before MapPane.
- MapPane.cpp source-only dependencies: `<windows.h>`, Event.h, ObjectStatusBlob.h, UserPane.h, LivingObjectPane.h, ObjectList.h, PacketBuffer.h, Socket.h, ReconnectDialog.h, and AlertPanes.h. It also carries exact extern declarations for StartupWindow-owned `g_useEpfAssets` and UserPane-owned `g_pInputBlockerPane` if those declarations are not transitively exported.
- The +0x418 field is `UserPane *m_localPlayerObjectPane`, not a LivingObjectPane pointer: timer cases call UserPane-only `ProcessMovement`, while inheritance preserves all LivingObjectPane/ObjectPane operations used elsewhere.
- Rejected placements: EventDispatcher.cpp, Event.cpp, Pane.cpp, TimerMgr.cpp, ReconnectDialog.cpp, a new `MapPaneNotify.cpp`, or the non-emitting UID00037U aggregate.
- Remaining placement uncertainty: original PDB/header spelling is unavailable, but each selected basename follows either an existing documented route or same-basename class/source convention. The ranked package is committed; uncertainty affects confidence, not implementation readiness.

## Range / Split / Padding / Reclassification Analysis

- Exact target: `[0x00508f60,0x0050902b)`, one modeled source method.
- Exact following alignment: `[0x0050902b,0x00509030)`, five `0xcc` bytes, not source C++.
- Exact sibling: UID0003ZS begins at `0x00509030`; it is a different tertiary TimerHandler-facet vtable method.
- UID00037U remains a non-emitting split index because it spans both methods, alignment, and pre-getter tail bytes.
- No new child, merge, filename change, reclassification, or UID allocation is required.
- Raw UID00042E/G remain executable source-shaped evidence with no proven entry/emission route; this report does not manufacture one.

## Negative Evidence Summary

- No direct target caller exists, but the sole vtable data xref proves liveness; this is not dead code.
- The global `g_pUrlAlertPane` is only a guard; it does not identify the allocated class.
- `0x005449f0` does not read MapPane state, perform rendering, or call a refresh routine. It passes zero to the shared capture manager.
- `m_timerHandler` is absent from the exact MapPane declaration and conflicts with documented inherited-facet source shape.
- No accepted timer-ID enum supports inventing symbolic names for 6 and 8.
- No evidence supports an Event null check, allocation-failure false return, packet-event signature, or raw message pointer in source.
- No evidence supports merging target with UID0003ZS or emitting UID00037U as one function.
- Consumer dependencies do not alter target ownership.
- `EventHandler.h` as the complete Event owner is weaker because its own interface needs only pointers and its docs favor a small shared handler declaration; combined `EventDispatcher.h` is weaker because Event/EventMan have independent Event.cpp ownership and non-dispatcher producers; Pane.h is a consumer/base header, not the canonical value-type owner.
- The pre-repair package was not compile-visible: MapPoint/ObjectStatusBlob were instantiated while incomplete; UserPane/LivingObjectPane/ObjectList methods were called through incomplete or overly broad pointer declarations; Win32 input, PacketBuffer, Socket, and both packet/global declarations lacked exact routes; Event.h lacked complete LObject visibility; and EventHandler.h modeled a partial EventDispatcher class. These are now explicit rejected states, not presumed-PCH exceptions.

## IDA Rename / Type / Comment Recommendations

- Supervisor action classification: `APPLIED_VERIFIED`; detailed catalog record `0304` and the post-standard pointer-boundary reconciliation are in `tools/leaser/Agents/ida-recommendation-implementation-catalog.md`.
- Pre-state: `0x00508f60` was `sub_508F60`, typed as a generic byte-returning thiscall with a raw secondary receiver and event block. `0x00597610` remained raw, `0x005975e0` had an incomplete TimerHandler identity, `MapPane::m_queuedMapStateRefresh` and `Event::m_type` were byte-shaped rather than semantic types, and `0x0069b4dc` was rendered as a raw alert guard.
- Applied function identities/types:
  - `0x00508f60`: `bool __thiscall MapPane__HandleSystemOrControlEvent(MapPane *__shifted(MapPane, 0xA0) this, Event *event)`;
  - `0x005975e0`: `void __thiscall TimerHandler__ScheduleTimer(TimerHandler *this, int timerId, unsigned int delayMs, int arg0, int arg1)`;
  - `0x00597610`: `void __thiscall TimerHandler__CancelTimer(TimerHandler *this, int timerId)`.
- Applied semantic types/data:
  - `Event::m_type` is `EventType`, with `kEventWorkNotification = 22`;
  - `MapPane::m_queuedMapStateRefresh` is `bool` at complete-object offset `+0x39d`;
  - `0x0066da97` is `bool g_useEpfAssets`;
  - `0x0069b4dc` is the exact four-byte `UrlAlertPane *g_pUrlAlertPane` data item.
- Applied comments: target receiver adjustment, queued-state drain, event comparison, alert guard, ordinary `new ConnectionClosedDialog` lowering, vtable route, and the generic inherited TimerHandler wrapper roles. Existing `Pane::CaptureMouse`, `Pane::ReleaseMouseCapture`, and `ConnectionClosedDialog::ConnectionClosedDialog` identities were preserved.
- Safety constraints: preserve the real secondary-facet `+0xa0` ABI, literal timer IDs 6/8 unless later source evidence proves enum spellings, raw allocation lowering, exact function bounds, and compiler-generated entities. Do not add a null guard, invent a source-visible TimerHandler member, or rename unrelated callers/owners.
- Post-state/readback: clean-restart session `ced65025` reports `MapPane__HandleSystemOrControlEvent` at `[0x00508f60,0x0050902b)`, `TimerHandler__ScheduleTimer` at `0x005975e0`, `TimerHandler__CancelTimer` at `0x00597610`, and `g_pUrlAlertPane` at `0x0069b4dc`, size four, with six data xrefs. `Event` remains size `0x110`; `MapPane` remains size `0x910`; the IDB was saved with SHA-256 `0C2F8BDA0866B42EA14EB3E89088013FA6E73BAE7D470D8691E3795F7C0EC53A`.
- Readback limitation: Hex-Rays still prints the direct alert operand as `MEMORY[0x69B4DC]`; disassembly shows `cmp dword ptr ds:69B4DCh, 0`, the source comment is present, and global/xref queries resolve the correctly named four-byte item. Do not treat that rendering limitation as a missing definition.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The exact target and five coordinated sibling blocks are live emitted methods and are compile-visible under the complete committed header/declaration package below; Event.h alone would not be sufficient.
- Behavior preservation: the proposed method preserves the unconditional pre-discriminator drain, exact gate order, timer order, release side effect, event type, alert guard, construction attempt, and handled/unhandled returns.
- Human-source shape: the proposed code uses the accepted Event/EventHandler contract, inherited Pane/TimerHandler methods, a canonical MapPane field, ordinary C++03 `new`, and no IDA labels, raw offsets, compiler EH state, vptr writes, or allocator plumbing.
- Naming convention: existing project `Handle...Event`, `m_...`, `g_p...`, and `kEvent...` conventions.
- Third-party import directive: not applicable.

### Compile-visible dependency closure matrix

| Symbol/use in UID0003ZT | Canonical declaration/definition owner | Evidence-backed route | Exact callback change | Current standalone status |
| --- | --- | --- | --- | --- |
| `Event`, `EventType`, `kEventWorkNotification` | UID00004L through UID0000J6, base UID0000L4 | Inferred canonical `ui/core/Event.h`, exact `util/LObject.h`, and documented/generated Event.cpp ownership | Event.h includes LObject.h before emitting the complete UID00004L enum/record formal; MapPane.cpp includes Event.h | Compile-visible and self-contained |
| EventHandler/dispatcher/Pane facets | UID00004N/00004M/0000J7 and UID0000A2/0000MC | `ui/core/EventHandler.h`, documented `EventDispatcher.h`, and inferred same-basename `Pane.h` | EventHandler.h forward-declares Event/EventDispatcher without a partial dispatcher class; EventDispatcher.h includes TimerHandler.h/EventHandler.h before its complete shell; EventHandler.cpp includes EventDispatcher.h; Pane.h includes GrafPort.h/EventHandler.h/TimerHandler.h | Compile-visible |
| `MapPoint` local object and references | UID0004R0 through UID0000L3 | Exact eight-byte declaration plus documented `map/MapPane.h`/MapPane.cpp pair | Move/place UID0004R0 complete declaration before MapPane in MapPane.h; remove `struct MapPoint;` from the combined formal | Compile-visible |
| `ObjectStatusBlob` local object/by-value API | UID00009S through UID0000M6 | Inferred same-basename `map/ObjectStatusBlob.h`; exact complete class formal | Include ObjectStatusBlob.h before MapPane declarations/definitions; remove incomplete forward-only reliance | Compile-visible |
| `m_localPlayerObjectPane`, `g_pUserPane`, `g_pInputBlockerPane` | UID0000FQ/0000P1 and UID0003EE | Inferred same-basename `ui/panels/UserPane.h`; exact global formal | Include UserPane.h, source-type +0x418 as `UserPane *`, and declare/export InputBlockerPane pointer exactly | Compile-visible |
| `LivingObjectPane` calls/field access | UID00007B through UID0000KU | Inferred same-basename `map/LivingObjectPane.h`; complete class formal/friendship | Include LivingObjectPane.h before UID0004QB definition | Compile-visible |
| `ObjectList::FindByObjectId` | UID00009Q through UID0000M4 | Documented `map/ObjectList.h` | Include ObjectList.h before UID0003ZS definition | Compile-visible |
| `GetAsyncKeyState`, `VK_LBUTTON` | Win32 SDK | `<windows.h>` | Include `<windows.h>` in MapPane.cpp source prelude; do not assume an unnamed PCH | Compile-visible |
| Packet scalar writers | UID0000M8 PacketBuffer | Documented `network/PacketBuffer.h` | Include PacketBuffer.h before UID0004QB definition | Compile-visible |
| `g_packetSender->QueueAndSendPacket` | UID0000DD/0000NS/0000Q5 | Documented `network/Socket.h`, complete Socket formal with extern | Include Socket.h before UID0004QB definition; keep sole definition in Socket.cpp | Compile-visible |
| `ConnectionClosedDialog` complete type | UID000036 through UID0000N0 | Documented `network/ReconnectDialog.h` | Add `#include "ReconnectDialog.h"` to UID00007Q formal | Exact final source route established |
| `g_pUrlAlertPane` | UID0000SM through UID0000HE | Documented `ui/dialogs/AlertPanes.h` | Add `#include "AlertPanes.h"` and document its extern-global contract | Exact final source route established |
| `g_useEpfAssets` | definition UID0000SW through UID0000O5 StartupWindow | No shared header basename proven | Add `extern bool g_useEpfAssets;` to the MapPane source-root prelude; keep sole definition in StartupWindow.cpp | Exact current source-root declaration route established |
| `TimerHandler::CancelTimer`, `ReleaseMouseCapture` | inherited Pane/TimerHandler contract | Existing `Pane.h` route in UID00007Q | Preserve `Pane.h`; use inherited/base-qualified calls; add no member/helper | Resolved |
| `NULL` and ordinary `new` | C++03/platform headers already included by the committed source package | Windows/project compilation environment and observed lowering | No custom allocator declaration or fabricated wrapper is introduced | Compile-visible |

### Proposed UID0003ZT formal block

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MapPane::HandleSystemOrControlEvent(Event *event)
{
    if (g_useEpfAssets && m_queuedMapStateRefresh)
    {
        m_queuedMapStateRefresh = false;
        TimerHandler::CancelTimer(6);
        TimerHandler::CancelTimer(8);
        ReleaseMouseCapture();
    }

    if (event->m_type != kEventWorkNotification)
        return false;

    if (g_pUrlAlertPane != NULL)
        return false;

    new ConnectionClosedDialog;
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Proposed UID00007Q formal block

The following is the complete current class/source-root block with the accepted source-closure changes: replace the stale virtual, remove the fake private helper, preserve every other declaration, field, size guard, and `[[CHILDREN]]` position, add all exact complete/API headers, emit the exact UID0004R0 MapPoint declaration before MapPane, source-type the local-player field as UserPane, and add both exact global extern routes. Conceptually, MapPane.h includes Pane.h/GrafPort.h/Motion.h/`<vector>` and owns MapPoint plus the class declaration, while source-only headers belong in MapPane.cpp; the validator's combined output receives the same declarations in legal order.

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <windows.h>

#include "Pane.h"
#include "GrafPort.h"
#include "Motion.h"
#include "Event.h"
#include "ObjectStatusBlob.h"
#include "UserPane.h"
#include "LivingObjectPane.h"
#include "ObjectList.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "AlertPanes.h"
#include "ReconnectDialog.h"

#include <vector>

class AlphaMaskSurface;
class EffectObjectPane;
class Layer;
class LightingObjectPane;
class LObject;
class Message;
class ObjectPane;
class ScreenEffecter;
class StaticObjectPane;
class InputBlockerPane;
struct EffectInfo;
struct StaticObjEntry;
struct MapTileLayerIds
{
    unsigned short groundTileId;
    unsigned short flags;
    unsigned short staticObjectId;
};
struct MapPaneTileRecord;
struct MapPoint
{
    int row;
    int column;
};

typedef char MapPointSizeMustBe8[
    sizeof(MapPoint) == 8 ? 1 : -1];

struct RectBounds;
typedef RectBounds MapRect;

extern bool g_useEpfAssets;
extern InputBlockerPane *g_pInputBlockerPane;
struct Rect;

class MapPane : public Pane
{
public:
    MapPane(int visibleTileColumns, int visibleTileRows);
    virtual ~MapPane();

    virtual void AddToLayer(
        const RectBounds *bounds,
        int order,
        Pane *parentPane,
        Layer *layer);
    virtual void QueueMotionMessage(const Rect *rect);
    virtual void OnChangeMessage(LObject *sender, Message *message);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool OnTimerEvent(int timerId, int param1, int param2);
    virtual void OnPaint();

    bool HasScreenEffecters() const;
    ScreenEffecter *FindActivePixelEffecter();
    void ResetScreenEffecterListFields();
    void ConfigureScreenEffecterList(signed char effectMode);
    void ClearScreenEffecterList();
    void ExitToMenu(bool notifyServer);
    void LoadCompressedMapFile(unsigned short mapId, int unusedLoadOption);
    void SaveCompressedMapFile();
    void MapToScreenCoords(MapPoint *point) const;
    void ScreenToMapCoords(MapPoint *point) const;
    void RedrawVisibleTiles();
    bool ValidateMapAndViewportCoords(
        int mapColumn,
        int mapRow,
        int viewportColumn,
        int viewportRow) const;
    void GetClampedVisibleTileBounds(MapRect *outBounds) const;
    void GetVisibleTileBounds(MapRect *outBounds) const;
    MapPoint *GetVisibleTileSpan(MapPoint *outSpan) const;
    void GetExtendedVisibleTileBounds(MapRect *outBounds) const;
    int CheckMovementCollision(
        int mapColumn,
        int mapRow,
        unsigned char direction);
    bool AllowsMovementStatusTag() const;
    bool ApplyMovementSubstepScroll(unsigned char direction);
    unsigned short GetAdjacentVisibleTileBounds(
        unsigned char direction,
        MapRect *outBounds) const;
    void AfterLocalPlayerWarp();
    void ObjectCallbackNoOp(ObjectPane *objectPane);
    void ScrollViewportByDirection(unsigned char direction);
    void ReindexObjectPanePosition(
        ObjectPane *objectPane,
        int removeRow,
        int removeColumn,
        int addRow,
        int addColumn);
    void RecenterAndSendPosition(
        int targetX,
        int targetY,
        int viewportX,
        int viewportY,
        bool useActiveObjectViewport);
    void ClearQueuedMapStateRefresh();
    void ClearPendingActionPoll();
    ObjectPane *CreateOrUpdateObjectPane(
        int objectId,
        int mapX,
        int mapY,
        unsigned char action,
        ObjectStatusBlob status);
    void RemoveObjectPaneById(int objectId);
    void DetachObjectPane(ObjectPane *objectPane);
    bool HasObjectIntersectingRect(const Rect *rect) const;
    ObjectPane *FindObjectPaneById(int objectId);
    ObjectPane *FindPreviousSelectableObject(ObjectPane *current);
    ObjectPane *FindNextSelectableObject(ObjectPane *current);
    ObjectPane *FindPreviousItemTargetObject(ObjectPane *current);
    ObjectPane *FindNextItemTargetObject(ObjectPane *current);
    ObjectPane *FindPreviousLivingTarget(ObjectPane *current, int targetFilter);
    ObjectPane *FindNextLivingTarget(ObjectPane *current, int targetFilter);
    void RemoveObjectPaneIfPresent(ObjectPane *objectPane);
    void UpdateObjectPaneScreenBounds(ObjectPane *objectPane);
    void UpdateObjectPosition(ObjectPane *objectPane);
    LivingObjectPane *HitTestObjectAtPoint(int y, int x);
    unsigned short GetCurrentMapId() const;
    void RenderMapView();
    void ComputeDayNightBrightnessAndTint(
        unsigned char hour,
        float brightnessScale,
        float brightnessBias,
        float *outBrightness,
        float *outTintAmount) const;
    void SetDayNightFadeTarget(float targetBrightness, float tintAmount);
    void AttachObjectLighting(
        ObjectPane *anchorSource,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    void RenderDayNightOverlay(const RectBounds *dirtyBounds);
    bool ShouldUseLivingObjectLightOverlay() const;
    bool ShouldOffsetElevatedLivingObjects() const;
    MapPoint *GetObjectScreenPoint(
        ObjectPane *objectPane,
        MapPoint *outPoint) const;
    void FlashMapColor(int drawColor);
    void FinishVisibleObjectRefresh();
    void InteractWithObject(LivingObjectPane *target);
    void CollectMovementTargetObjectIds(
        std::vector<unsigned int> &objectIds) const;
    void SortMovementTargetObjectIdsByDistance(
        std::vector<unsigned int> &objectIds) const;
    void ChangeMap(
        unsigned short mapId,
        short mapWidth,
        short mapHeight,
        unsigned char weatherMode,
        unsigned char transitionState,
        int loadOption);
    void AllocateTileBuffer();
    void RequestObjectEffect(
        unsigned int objectId,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void RefreshGroupMemberHitBar(unsigned int memberId);
    void ApplyHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned int primaryValue,
        unsigned int primaryMaximum,
        unsigned int secondaryValue,
        unsigned int secondaryMaximum);
    void RemoveGroupMemberHitBar(unsigned int memberId);
    bool HandleMapInfoTileRegionPacket(const unsigned char *packet);

private:
    void NotifyDeferredMotionChanged();
    LivingObjectPane *FindObjectAtMapPoint(int y, int x);
    void DrawVisibleTiles();
    void DrawTileAt(int tileX, int tileY, bool refreshStaticObjects);
    unsigned short ComputeTileRectChecksum(const MapRect *bounds) const;
    unsigned int ComputeVisibleTileChecksum(const MapRect &bounds) const;
    MapTileLayerIds *GetLegacyAwareMapTileLayerIds(
        MapTileLayerIds *outTile,
        int mapColumn,
        int mapRow) const;
    unsigned char RemapMovementDirectionForMapScroll(
        unsigned char direction) const;
    void RefreshScrolledTileData(
        int objectColumn,
        int objectRow,
        int viewportColumn,
        int viewportRow,
        unsigned char direction);
    int SelectMovementPathStep();
    bool ShouldClearMovementTimerState() const;
    int BuildPathToPendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void ResolvePendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void SetMapState(int weatherType, unsigned char weatherMode);
    void RequestCoordinateEffect(
        int mapColumn,
        int mapRow,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void ApplyEffectObjectPaneTimerAction(
        EffectObjectPane *effectObjectPane,
        int timerAction);
    void CreateEffectObjectPane(
        LivingObjectPane *target,
        int mapRow,
        int mapColumn,
        EffectInfo effectInfo,
        int timerAction,
        int sequenceIndex,
        bool renderAfterLivingObjects);
    void CreateHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned short currentValue,
        unsigned short maximumValue);
    StaticObjectPane *CreateStaticObjectPaneForTile(
        int tileX,
        int tileY,
        unsigned short staticObjectId,
        bool skipListInsertion);
    void RefreshStaticObjectTileRegion(const MapRect &tileBounds);
    void ResetMapResourceStateForModeChange();
    void RefreshDeferredMapSurfacesForTileRegion();
    bool InvalidateShiftedMapArea(int deltaX, int deltaY);
    bool HandleObjectInfoPacket(const unsigned char *packet);
    bool HandleEffectMapStatePacket(const unsigned char *packet);
    bool HandleDrawObjectsPacket(const unsigned char *packet);
    bool HandleMovementSpeechBalloonPacket(const unsigned char *packet);
    bool HandleObjectMoveEffectPacket(const unsigned char *packet);
    bool HandleObjectWorldMapCreationPacket(const unsigned char *packet);
    bool HandleActionPacket(const unsigned char *packet);
    bool HandleFlyingObjectUpdatePacket(const unsigned char *packet);
    bool HandleAnimationSoundPacket(const unsigned char *packet);
    bool HandleObjectStatusPacket(const unsigned char *packet);
    bool HandleMapTransitionPacket(const unsigned char *packet);

public:
    int m_screenEffecterCount;
    int m_screenEffecterCapacity;
    ScreenEffecter **m_screenEffecters;
    LivingObjectPane *m_highlightedObjectPane;
    bool m_selectedObjectActive;
    unsigned char m_selectedObjectPadding[3];
    LivingObjectPane *m_selectedObjectPane;
    int m_mapResourceMode;
    bool m_mapEffectEnabled;
    unsigned char m_mapEffectPadding[3];
    Motion m_deferredMotionRecords[32];
    int m_deferredMotionRecordCount;
    bool m_deferMotionMessages;
    bool m_queuedMapStateRefresh;
    bool m_pendingActionPoll;
    unsigned char m_deferredStatePadding;
    int m_pendingMovementState[6];
    float m_currentDayNightBrightness;
    float m_dayNightCurrentScale;
    float m_dayNightCurrentBias;
    float m_dayNightCurrentTint;
    float m_dayNightTintCurveScale;
    float m_dayNightTintCurveBase;
    float m_dayNightTintAmount;
    float m_newHumanProjectionDivisor;
    float m_newHumanProjectionShear;
    float m_dayNightTargetBrightness;
    AlphaMaskSurface *m_selectionOverlay;
    float m_dayNightBrightnessScale;
    float m_dayNightBrightnessBias;
    unsigned int m_pendingMapStateToken;
    bool m_waitingForLocalPlayerStatus;
    bool m_objectInteractionTimerActive;
    unsigned short m_mapId;
    short m_mapWidth;
    short m_mapHeight;
    MapPaneTileRecord *m_tileBuffer;
    int m_tileOriginX;
    int m_tileOriginY;
    int m_visibleTileColumns;
    int m_visibleTileRows;
    unsigned char m_mapTransitionState;
    unsigned char m_weatherMode;
    unsigned char m_movementGate;
    unsigned char m_dayNightHour;
    int m_weatherType;
    Pane *m_weatherLayerPane;
    UserPane *m_localPlayerObjectPane;
    Pane *m_auxiliaryPane;
    Layer *m_activeScreenLayer;
    ObjectList *m_objectList;
    GrafPort m_viewportGrafPort;
    int m_mapFlashColor;
    unsigned char m_mapRuntimeMode;
    bool m_visibleObjectRefreshPending;
    bool m_refreshWholeVisibleMap;
    unsigned char m_mapRefreshPadding;
    int m_zoneMusicId;
    int m_zoneMusicFallbackTrackIndex;
    int m_zoneMusicVolumeScale;
    wchar_t m_mapName[256];
    unsigned short m_mapNameLength;
    wchar_t m_mapResourceName[256];
    unsigned short m_mapResourceNameLength;
    unsigned char m_actionStatePrefix[8];
    bool m_pendingActionModeActive;
    unsigned char m_pendingActionModePadding[3];
    int m_pendingActionTileX;
    int m_pendingActionTileY;
    unsigned char m_pendingActionState[20];
    unsigned int m_pendingActionTargetObjectId;
    bool m_deferredPrimarySurfaceDirty;
    unsigned char m_deferredSurfacePadding;
    bool m_deferredSecondarySurfaceDirty;
    unsigned char m_finalPadding;
};

typedef char MapPaneSizeMustBe0x910[
    sizeof(MapPane) == 0x910 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Proposed UID00042F formal block

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::ClearQueuedMapStateRefresh()
{
    if (m_queuedMapStateRefresh)
    {
        m_queuedMapStateRefresh = false;
        TimerHandler::CancelTimer(6);
        TimerHandler::CancelTimer(8);
        ReleaseMouseCapture();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Proposed UID00042I formal block

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::ClearPendingActionPoll()
{
    if (m_pendingActionPoll)
    {
        m_pendingActionPoll = false;
        TimerHandler::CancelTimer(7);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Proposed UID0003ZS formal block

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MapPane::OnTimerEvent(int timerId, int, int)
{
    switch (timerId)
    {
    case 5:
        m_objectInteractionTimerActive = false;
        return true;

    case 7:
        if (m_pendingActionPoll)
        {
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
            {
                if (g_pUserPane != NULL)
                    g_pUserPane->TryPerformAction();
                TimerHandler::ScheduleTimer(7, 500, 0, 0);
            }
            else
            {
                ClearPendingActionPoll();
            }
            return true;
        }

        /* fall through to the movement/path timer */
    case 6:
        if (!m_queuedMapStateRefresh)
            return true;

        if (g_pInputBlockerPane != NULL)
        {
            ClearQueuedMapStateRefresh();
            return true;
        }

        if (m_localPlayerObjectPane != NULL)
        {
            int direction = SelectMovementPathStep();
            if (direction >= 0 && direction < 4)
                m_localPlayerObjectPane->ProcessMovement(direction);
        }

        if (ShouldClearMovementTimerState())
            ClearQueuedMapStateRefresh();
        else
            TimerHandler::ScheduleTimer(6, 44, 0, 0);
        return true;

    case 8:
        if (!m_queuedMapStateRefresh)
            return true;

        if (g_pInputBlockerPane != NULL)
        {
            ClearQueuedMapStateRefresh();
            return true;
        }

        if (m_localPlayerObjectPane != NULL)
        {
            MapPoint currentPosition;
            m_localPlayerObjectPane->GetMapPosition(&currentPosition);

            ObjectPane *target = m_objectList != NULL
                ? m_objectList->FindByObjectId(m_pendingActionTargetObjectId)
                : NULL;

            int direction = BuildPathToPendingActionTarget(target, currentPosition);
            if (direction >= 0 && direction < 4)
                m_localPlayerObjectPane->ProcessMovement(direction);
            else
                ResolvePendingActionTarget(target, currentPosition);
        }

        if (ShouldClearMovementTimerState())
            ClearQueuedMapStateRefresh();
        else
            TimerHandler::ScheduleTimer(8, 44, 0, 0);
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Proposed UID0004QB formal block

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::InteractWithObject(LivingObjectPane *target)
{
    ObjectStatusBlob status;
    target->GetSpriteConfig(&status);

    unsigned char packet[80];
    PacketBufferWriteUInt8(0x43, packet);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt32BE(target->m_objectId, packet + 2);

    if (status.m_statusKind == ObjectStatusBlob::HumanObject)
    {
        if (m_objectInteractionTimerActive)
            return;

        m_objectInteractionTimerActive = true;
        g_packetSender->QueueAndSendPacket(packet, 6);
        TimerHandler::ScheduleTimer(5, 4000, 0, 0);
        return;
    }

    g_packetSender->QueueAndSendPacket(packet, 6);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- Replace UID0003ZT's stale method/signature/body with the exact proposed `HandleSystemOrControlEvent(Event *event)` formal and raise it to `92/94`.
- Retain UID0003ZT owner/emitter/reconstructable fields and blank emitter position.
- Synchronize UID00007Q MapPane's complete declaration/source package: exact virtual override, no fake `RefreshQueuedMapState`, canonical bool field retained, no added `m_timerHandler`, `UserPane *` at +0x418, complete MapPoint before MapPane, `<windows.h>`, Event/ObjectStatusBlob/UserPane/LivingObjectPane/ObjectList/PacketBuffer/Socket/AlertPanes/ReconnectDialog headers, and exact externs.
- Normalize inherited TimerHandler calls in UID00042F, UID00042I, UID0003ZS, and UID0004QB with the complete proposed formals.
- Update UID00042E/G raw no-route evidence to the accepted CaptureMouse/ReleaseMouseCapture and inherited TimerHandler vocabulary without adding emitters or C++.
- Synchronize UID0000L3, UID00042K, UID00037U, UID0002SQ, and UID0001AP at report-level detail.
- Synchronize UID00004L/UID0000J6 to self-contained `Event.h`/Event.cpp through exact `LObject.h`; UID00004N/UID00004M/UID0000J7 and UID0000A2/UID0000MC to the EventHandler/EventDispatcher/Pane include graph; UID0004R0, UID0000FQ/UID0000P1/UID0003EE, UID0000M6, UID000036/UID0000N0, UID0000HE/UID0000SM, and UID0000SW to the exact declaration-owner/header/extern contract. Preserve already-correct LivingObjectPane/ObjectList/PacketBuffer/Socket/g_packetSender/LObject/TimerHandler/StartupWindow providers unless callback evidence contradicts them.
- Treat all six draft formal blocks as compile-visible reconstructed source only under the full matrix and exact order above. Event.h alone or unnamed-PCH/transitive visibility is explicitly insufficient; the validator's current `.cpp`-only artifact set does not reopen the committed source-factoring decision.
- No target remains no-owner or non-emitting. UID00037U stays non-emitting because it is a split index; UID00042E/G stay non-emitting because current route-negative proof remains valid.
- No further target-specific research or ordinary-document implementation is needed. The accepted callback, 30 serial scoped validators, six-block comparison, provider reread, and generated/tracker readback are complete. At this B001 handoff the exact artifact is execution-ready for the supervisor; manual coverage application and lifecycle execution remain supervisor-owned, and any later validator-owned footer/registry/archive path is authoritative.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md`.
- Metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`.
- Formal: exact proposed UID0003ZT block in this report.
- Item Summary: exact EventHandler system/control callback, type-22 enum, unconditional pre-discriminator drain, canonical bool field, inherited timer cancels, ReleaseMouseCapture, UrlAlert guard, ConnectionClosedDialog construction, true/false behavior, owner/emitter/source route.
- Required detail: exact range/hash, alignment hash, function model/CFG, sole vtable xref, adjusted receiver, complete field/facet normalization, callee inventory, helper-family evidence, constructor allocation/call, negative evidence, source placement, rejected alternatives, and historical stale assumptions.
- Preserve historical statements only in a labeled section explaining why `OnNotifyMessage`, raw message pointer, numeric 22, `m_movementTimerQueued`, `m_timerHandler`, `RefreshQueuedMapState`, and UrlAlertPane construction were superseded.

## Recommended Support Doc Changes

| Support path | Exact proposed work |
| --- | --- |
| `by-class/MapPane.md` | Retain `93/94`, owner/emitter/file route, full prior evidence, 0x910 size, and every unrelated declaration. Apply the complete proposed formal and dependency order; replace target method prose; use only `m_queuedMapStateRefresh` as current; label `m_movementTimerQueued` historical; remove the fake helper; source-type +0x418 as `UserPane *`; explain inherited EventHandler/TimerHandler facets and every complete/API dependency. |
| `by-file/MapPane.md` | Retain `92/92` and `NexusTK/map/`. Replace notify vocabulary with the exact system/control event method/type; commit MapPane.h/MapPane.cpp split, complete MapPoint placement, full source-only include/extern package, local-player UserPane type, helper/field/timer source shape, exact source order, and preserve the complete prior source-family union. |
| `by-type/by-struct/MapPaneLayout.md` | Retain `93/94`, owner/emitter, and layout-only formal. Make `bool m_queuedMapStateRefresh` the sole current `+0x39d` name; retain the alternate only as historical; add target/queue/clear/timer lifecycle. |
| `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md` | Retain `88/90`, false reconstructable, blank emitter/formal, split-index role, exact children and padding. Rename target role and helper/field/event semantics without emitting aggregate code. |
| `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | Retain `88/89`, owner/emitter. Apply exact proposed formal with inherited TimerHandler qualification; use one current field name; preserve all branch behavior and evidence. |
| `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md` | Retain `88/92`, owner/emitter, and covered-by formal. Replace stale slot role with exact EventHandler family/signature/type and preserve all vtable bytes, ranges, slots, boundaries, stores, and compiler-regenerated handling. |
| `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` | Raise `87/89 -> 90/92`; retain owner/emitter. Apply exact proposed formal and incorporate helper body/caller-family proof, canonical field, inherited TimerHandler, paired queue paths, and rejected refresh-helper history. |
| `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` | Retain `87/90`, MapPane owner, reconstructable true, blank emitter/formal. Preserve all raw no-route evidence; replace map-refresh wrapper wording with CaptureMouse/ReleaseMouseCapture pair and canonical field/inherited-facet source shape. |
| `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md` | Retain `87/89`, MapPane owner, reconstructable true, blank emitter/formal. Preserve all raw no-route evidence and behavior; remove provisional `m_timerHandler`/helper ambiguity. |
| `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | Retain `90/91`, owner/emitter, aggregate covered-by formal, all child inventory. Add canonical timer-state/capture-release closure without pruning prior detail. |
| `by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md` | Retain `87/89`, owner/emitter. Apply exact proposed formal with inherited `TimerHandler::CancelTimer(7)` and explain the facet source shape. |
| `by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md` | Retain `92/94`, owner/emitter, all packet/caller/body evidence. Apply exact proposed formal with inherited `TimerHandler::ScheduleTimer(5,4000,0,0)` only. |
| `by-class/Event.md` | Retain `94/95`, owner/emitter, complete current formal, and all payload/producer/consumer evidence. Commit UID00004L's complete `EventType`/Event declaration to self-contained `ui/core/Event.h` with exact `util/LObject.h` inclusion before the base-derived class; do not duplicate or reduce the formal. |
| `by-file/Event.md` | Retain `91/92`, `NexusTK/ui/core/`, complete Event module evidence, and blank by-file formal. Commit `ui/core/Event.h` / Event.cpp: header includes LObject.h and owns enums/record/declarations; cpp owns implementation/factories. |
| `by-class/EventHandler.md` | Retain `89/92`, owner/emitter, complete handler/dispatcher evidence, and all virtual declarations. Commit EventHandler/EventPointPair to `ui/core/EventHandler.h`; forward-declare Event/EventDispatcher and extern the dispatcher pointer, remove the partial EventDispatcher class declaration, and include EventDispatcher.h only in the implementation that calls `SetPaneOrder`. |
| `by-class/EventDispatcher.md` | Retain `89/91`, owner/emitter and route-marker policy. Commit the complete public router declaration to EventDispatcher.h after TimerHandler.h/EventHandler.h and dispatcher-local record/storage declarations; preserve all constructor/route/helper evidence and avoid absorbing Event's complete record. |
| `by-file/EventDispatcher.md` | Retain `92/89`, documented `ui/core/EventDispatcher.h`, ownership, and all routing evidence. Commit EventDispatcher.h -> TimerHandler.h + EventHandler.h, EventHandler.cpp -> EventDispatcher.h, and separate Event.h ownership; neither dispatcher header nor handler header absorbs the complete Event record. |
| `by-class/Pane.md` | Retain `90/91`, owner/emitter and blank broad formal. Document that Pane.h includes GrafPort.h, EventHandler.h, and TimerHandler.h to expose its complete base and inherited facets; preserve every Layer/GrafPort/layout/method/default/compiler fact. |
| `by-file/Pane.md` | Retain `90/91` and `NexusTK/ui/core/`. Commit the same-basename Pane.h/Pane.cpp pair and Pane.h's GrafPort.h/EventHandler.h/TimerHandler.h visibility without moving GrafPort, EventHandler, or TimerHandler ownership. |
| `by-type/by-struct/MapPoint.md` | Retain `92/93`, UID0000L3 owner/emitter, position 5, exact two-int formal and all consumers. Commit declaration placement in `map/MapPane.h` before MapPane while definitions/consumers remain in MapPane.cpp and other modules include MapPane.h. |
| `by-class/UserPane.md` | Retain `94/95`, owner/emitter and complete class formal. Add MapPane +0x418 as a `UserPane *` consumer, preserve UserPane inheritance, and export the exact g_pUserPane/InputBlocker pointer declarations through the inferred same-basename UserPane.h contract without duplicating definitions. |
| `by-file/UserPane.md` | Retain `93/94` and `NexusTK/ui/panels/`. Commit UserPane.h/UserPane.cpp factoring for the complete UserPane declaration and extern singleton declarations consumed by MapPane; definitions remain in their current emitters. |
| `by-global/g_pInputBlockerPane.md` | Retain `87/90`, owner/emitter UID0000P1, exact definition and all lifecycle/xref evidence. Add the UserPane.h extern declaration route and UID0003ZS MapPane consumer; never duplicate the definition. |
| `by-file/ObjectStatusBlob.md` | Retain `90/93`, `NexusTK/map/`, complete class/parser/source evidence, and blank file formal. Commit same-basename ObjectStatusBlob.h as the complete 68-byte declaration route consumed by MapPane.h/MapPane.cpp; definitions remain ObjectStatusBlob.cpp. |
| `by-class/ConnectionClosedDialog.md` | Retain `92/94`, owner/emitter, complete class formal, and all constructor/callback/vtable evidence. Document that the complete type is exported by the UID0000N0 `ReconnectDialog.h` contract and is consumed by MapPane's ordinary `new ConnectionClosedDialog`. |
| `by-file/ReconnectDialog.md` | Retain `90/93`, `NexusTK/network/`, complete source union, and blank by-file formal. Preserve the explicitly documented `network/ReconnectDialog.h` route and add MapPane as a complete-type consumer; do not move construction ownership. |
| `by-file/AlertPanes.md` | Retain `85/88`, `NexusTK/ui/dialogs/`, complete alert-family evidence, and blank by-file formal. Preserve the explicitly documented `ui/dialogs/AlertPanes.h` route and state that its declaration contract exports `g_pUrlAlertPane` for MapPane while the definition remains UID0000SM in AlertPanes.cpp. |
| `by-global/g_pUrlAlertPane.md` | Retain `87/92`, owner/emitter UID0000HE, exact pointer definition formal, storage/xref/lifecycle evidence, and source ownership. Add the documented AlertPanes.h extern-declaration route and MapPane guard consumer; do not duplicate the definition in MapPane.cpp. |
| `by-global/g_useEpfAssets.md` | Retain `88/90`, owner/emitter UID0000O5, exact bool definition formal, storage/xref/writer evidence, and source ownership. Add MapPane as a direct read consumer and document the exact source-root `extern bool g_useEpfAssets;` route because no shared header basename is proven; do not create a guessed header or second definition. |

### Current ordinary-document identity manifest

| ID | Path | SHA-256 | Bytes / physical lines |
| --- | --- | --- | --- |
| D1 | `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md` | `13ED7A3F3A26431F7D7F882CEB9A72EC48C9920456C270A2DC45E3243EE1020B` | 15,045 / 139 |
| D2 | `by-class/MapPane.md` | `4B553E854703A2E5ACC039AAA6D1290E163087EFBF7AD9E64607B10135F4119D` | 189,115 / 1,042 |
| D3 | `by-file/MapPane.md` | `720F0AE24A97A730AE9B6051B817192E8103D1A1C0D2AFAB07510B4025C1DEDA` | 195,698 / 805 |
| D4 | `by-type/by-struct/MapPaneLayout.md` | `8D8B8D5CD54C3B36896338C7D22ACF22E6146872157AA2C6870332738D608265` | 27,940 / 163 |
| D5 | `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md` | `3EA3FD05217F863DDABC4A3BB8F5B78CE9E3D87BA363DAC58D3F2A16BAF0C2AA` | 17,548 / 167 |
| D6 | `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | `3CEE8D7BD6BC122B25CB3327E47F3AFEC6535D31E05BDB891144A12F74EE64DF` | 27,858 / 272 |
| D7 | `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md` | `B1CA153F79DC93A3C89C0498BCD2CA74510C6ED23E5EEBE4F9AA424F6A584EA3` | 12,587 / 104 |
| D8 | `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` | `6E87C2EEDB1F760313DE9F0A3DDCEFC06463157D80973D24988FCAC5CF93AA3E` | 3,772 / 51 |
| D9 | `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` | `371192D10858A023C89DDA884AA71BF2244C07EA848EECAB5EC78029D02381E4` | 14,433 / 114 |
| D10 | `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md` | `F1BEA8785E2D3AACACCA9270B1457F7117C18610E80F0D5E424727CFA87B94BE` | 11,132 / 91 |
| D11 | `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | `06C59CCE3E4228949F978AE609228E81E18D10B2F9FCE45902FE4884671109A2` | 70,306 / 347 |
| D12 | `by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md` | `AD7339877E0D690B779ED7754DEF4D4E4FA7EAD729CA3765748EA810D5764891` | 3,044 / 46 |
| D13 | `by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md` | `659DF3A9A6B0FF81E12CA38E0AC4B8CB97BE2A7209D413F4239A5A528C630507` | 6,352 / 84 |
| D14 | `by-class/Event.md` | `5F7D81ECBC5D8E5AC9751DE0E8C8C2D2D8644538B3E54E17FFF741EB911E1B3F` | 24,875 / 326 |
| D15 | `by-file/Event.md` | `7F1D92CA5722925F8A575DEE15262822F6C937B3AE91B8D5A473D3E138BE6E91` | 24,662 / 159 |
| D16 | `by-class/EventHandler.md` | `BE2C59247675ADE6D81B8B9F705304FD70D475CF070329335141D8FA473B7875` | 20,982 / 175 |
| D17 | `by-file/EventDispatcher.md` | `8E3A88B9AB1B77454AAEDBF157C1E4D6FC8F18733F61072BAD4AD3ECA41A1DA4` | 36,848 / 190 |
| D18 | `by-class/ConnectionClosedDialog.md` | `6ADC4C8FECC3EA38929C64680E5B89D625010DD9C7118A833ECA3D59AC60BA67` | 22,966 / 174 |
| D19 | `by-file/ReconnectDialog.md` | `9E1F51DE0F3E2946E75D54AF49664E21AF767AB289F7D69ECBF590974B573543` | 28,363 / 191 |
| D20 | `by-file/AlertPanes.md` | `B579F4F50DACB99221009699BB971A3B5DF2A4EF2A430082E216EC1CC7D73796` | 31,562 / 182 |
| D21 | `by-global/g_pUrlAlertPane.md` | `28A200A2711E2288AE4CB2EEE2AF3E4B0049204853396315B8C066B1C1699FA3` | 12,817 / 93 |
| D22 | `by-global/g_useEpfAssets.md` | `DFF2CBD42DC37584DA304AB5E3B2DFD9C691D17345E45C89D067AF3024624B98` | 21,583 / 157 |
| D23 | `by-class/EventDispatcher.md` | `907C2E5F26546352FC55548D99E666D94E11FFA81A82287E99C9E20F64C9E0FD` | 29,684 / 232 |
| D24 | `by-class/Pane.md` | `3DBEF7559E1BEE8A845903AFB2BBE13D2EC128E045C3618405F575CB95EEC1C7` | 21,819 / 183 |
| D25 | `by-file/Pane.md` | `636ADCF73166A59C7E8111BB783F1454D722AE886A3B3073BD2FF9675EAC231C` | 24,360 / 190 |
| D26 | `by-type/by-struct/MapPoint.md` | `E942A86010B8BFEF42E171B87EFA7EC393086CEEE102D48B48A2794DBC9F15C3` | 6,420 / 71 |
| D27 | `by-class/UserPane.md` | `3E8202BAA1CE19A9539E15ED05465DAA5D280923F6B6A609269F255613D666B8` | 98,814 / 727 |
| D28 | `by-file/UserPane.md` | `22E3B97D97560B1E016007712668936C7BD093EFC8DF0E61B0FE57C2A2EEF3B5` | 112,944 / 465 |
| D29 | `by-global/g_pInputBlockerPane.md` | `D41205177D1DD69BC77EB7595878CD2BB13D56319625F8540805BC6DC8466554` | 6,692 / 66 |
| D30 | `by-file/ObjectStatusBlob.md` | `03B0B3B364B1549D985928C5A988D93C4199C6A1E5EC247AC630A481539F121B` | 10,947 / 89 |

Read-only support providers were reread after callback and remained consistent: UID0000O5 StartupWindow SHA `13DCCA5CF9CBA280CC4A540F0197EADC1F6476FB26DF8747EF3D7662CBEE34B1` (49,765 / 233); TimerHandler schedule/remove wrappers SHA `FC828CD63FDC922B25DD97445E8A32B9A35FFA9278ADFAA0A3B7F48785C383AA` (21,843 / 169) and adjacent wrappers SHA `13EA5953DB3086FE9C8C439AED43DF954C660D660AB3BBF7B87C3544BDCBCBB9` (15,039 / 139); UID00023O SHA `A0D10B643F25819332512F98DB17C54BDEDF9EB0328D3A7098EC8A94FE5CAC19` (20,637 / 139); LivingObjectPane class/file `D5BD4C2F6BC154BD08781199323E93C7358FFB131EA70C225E7B8AF96C2AD94A` / `6CA2609588B61D36CC8847C3E828F286ED532C700EB441F54F545D19B2518135`; ObjectList class/file `812673D1AF24712C765A68E8D8E7A21D0ACA7588CC2B1B431B318FCC88DBD2C2` / `901DE1AA6201D8EC1842BC1213C7D5646ACCD5A46AE9F6F2FF05DBF7771B00E1`; PacketBuffer file `901FF7260402234BF5423882EB6739827808150E1DD84779DB989C2FCC41FF9F`; Socket class/file `EC72EDC2D2D342F78B6873D7C74CF53D920F21767D53F13E65F46DE97281FE6B` / `D5AE31309F66FDA5177870839EBB7F64F8680369642ABB25544287DB109E8BFE`; g_packetSender `B79FB4848A0D59B7A1F45A01032BDA67CFD1D1EC2274C732D294188C898FCE1F`; and LObject file `15E3344ABD8E7B1B8DF3B741BE82C00C8BCF551FA36ABE70C584F6F93DC9D616`. They were not edited, none contradicted the accepted matrix, and none is an additional report target.

## Score And Metadata Recommendation

### UID0003ZT

- Pre-callback baseline: `87/89`, owner/emitter UID00007Q, reconstructable true, blank position.
- Current implemented state: `92/94`, same owner/emitter/reconstructable/position.
- Reason higher: exact function/bounds/hash/CFG, vtable family, ABI, Event type/enum, adjusted receiver, complete field/timer/helper/global/dialog/return behavior, source placement, declaration ownership, full Event/EventHandler/EventDispatcher/Pane graph, and complete MapPane six-block include/declaration package are resolved.
- Reason not higher than `92/94`: original symbol/header spelling is stripped. `HandleSystemOrControlEvent`, `m_queuedMapStateRefresh`, Event.h/EventHandler.h, MapPoint-in-MapPane.h, UserPane.h, LivingObjectPane.h, and ObjectStatusBlob.h are highest-probability project-consistent source answers rather than recovered PDB names; exact custom allocator/new source syntax is inferred from compiler lowering.
- Reason not lower: no behavioral, ownership, method-signature, helper, type, field, callback, range, body, source-placement, or declaration-visibility blocker remains under the complete committed matrix. Event.h alone is not claimed sufficient; LObject, Pane/EventHandler/TimerHandler, MapPoint, UserPane/InputBlocker, ObjectStatusBlob, LivingObjectPane, ObjectList, Win32, PacketBuffer, Socket/g_packetSender, AlertPanes, ReconnectDialog, and asset-global routes are all explicit.

### UID00042F

- Pre-callback baseline: `87/89`.
- Current implemented state: `90/92`, owner/emitter/reconstructable unchanged.
- Improvement: the exact release helper, inherited TimerHandler source shape, canonical bool field, caller-family evidence, and full source body are now closed.
- Cap: exact original private method spelling remains inferred.

### Other supports

- Retain current ordinary scores: UID00007Q `93/94`, UID0000L3 `92/92`, UID00042K `93/94`, UID00037U `88/90`, UID0003ZS `88/89`, UID0002SQ `88/92`, UID00042E `87/90`, UID00042G `87/89`, UID0001AP `90/91`, UID00042I `87/89`, UID0004QB `92/94`.
- Retain current support scores for dependency-closure destinations: UID00004L `94/95`, UID0000J6 `91/92`, UID00004N `89/92`, UID00004M `89/91`, UID0000J7 `92/89`, UID0000A2 `90/91`, UID0000MC `90/91`, UID0004R0 `92/93`, UID0000FQ `94/95`, UID0000P1 `93/94`, UID0003EE `87/90`, and UID0000M6 `90/93`. These edits close declaration placement, not missing behavior.
- Score-improvement attempt was not limited to the target: all compile/source blockers in associated emitted children were traced. No support score is lowered because their existing behavior/evidence remains valid and no contradictory runtime fact was found.

## Open Questions With Attempted Resolution

| Open question found | Evidence checked | Best supported resolution | Remaining impact |
| --- | --- | --- | --- |
| Is this a notify-message byte block or Event virtual? | EventHandler slot order, vtable values, target `+4` read, Event layout/type routing | Event system/control-family virtual with `Event *` | none |
| What does code 22 mean? | Event enum, producer/dispatcher docs, binary immediate | `kEventWorkNotification` | none |
| What is `0x005449f0`? | Exact body/hash, paired `0x005449d0`, manager body, 20/16 caller inventories, current pane docs | `Pane::ReleaseMouseCapture`; pair is CaptureMouse/ReleaseMouseCapture | none |
| What is MapPane `+0x39d`? | target, raw timer-6/8 setters, modeled clearer, timer callback, class/layout | `bool m_queuedMapStateRefresh` | original lexical spelling only |
| Is `m_timerHandler` a member? | adjusted receiver math, Pane inherited-facet docs, complete MapPane declaration, all affected children | no; use inherited TimerHandler methods | none |
| Does the guard imply UrlAlertPane construction? | direct constructor call, allocation size, UID00023O, global type | no; guard is `g_pUrlAlertPane`, object is ConnectionClosedDialog | none |
| What happens on allocator null? | exact CFG | machine path still returns true; ordinary source remains `new ConnectionClosedDialog` | allocator implementation detail only |
| Should target merge with timer sibling or parent? | exact function starts/ends, alignment, vtable slots | no; preserve exact child split | none |
| Does raw UID00042E/G get C++ now? | modeled-function, xref, pointer, table, generated-route negative proof | no; preserve non-emitting pages while syncing semantics | none |
| Where does the complete Event declaration come from? | UID00004L formal, UID0000J6/Event.cpp ownership, broad Event factories/consumers, UID00004N forward-only formal, generated Event.cpp/MapPane.cpp, and project same-basename header style | `ui/core/Event.h` is the committed complete declaration owner | inferred basename only; no implementation blocker |
| Why not put complete Event in `EventHandler.h`? | handler interface uses only Event pointers; docs favor a small shared EventHandler header; Event/EventMan have independent Event.cpp ownership | keep EventHandler.h separate and forward-declare Event; dereferencing consumers include Event.h | lower-ranked alternative rejected |
| Why not put complete Event in `EventDispatcher.h` or `Pane.h`? | EventDispatcher has its own documented router header; Event has non-dispatcher producers; Pane is a consumer/base route | retain EventDispatcher.h for router APIs and Pane.h for Pane; neither owns the value record | lower-ranked alternatives rejected |
| How is canonical Event.h self-contained? | UID00004L derives from/uses LObject and UID0000L4 documents exact `util/LObject.h` | Event.h includes LObject.h before all Event payload/class declarations | none after callback |
| How are EventHandler, EventDispatcher, and Pane mutually visible without partial-class duplication? | UID00004N pointer-only Event signatures, UID00004M/0000J7 TimerHandler-derived dispatcher ownership, Pane complete GrafPort/EventHandler/TimerHandler facets | EventHandler.h forward-declares Event/EventDispatcher; EventDispatcher.h includes TimerHandler.h/EventHandler.h before its complete shell; EventHandler.cpp includes EventDispatcher.h for SetPaneOrder; Pane.h includes GrafPort.h/EventHandler.h/TimerHandler.h | none after callback |
| Where is complete MapPoint visible? | UID0004R0 exact declaration/position and UID0000L3 documented MapPane.h/MapPane.cpp pair | place UID0004R0 before MapPane in MapPane.h and remove forward-only reliance | inferred factoring only |
| Why is +0x418 `UserPane *` rather than `LivingObjectPane *`? | UID0003ZS calls UserPane-only ProcessMovement twice; UID0000FQ derives from LivingObjectPane and the field stores the local player | source-type field as UserPane*, preserving inherited LivingObjectPane operations | original field spelling only |
| How are ObjectStatusBlob/LivingObjectPane/ObjectList calls complete? | complete UID00009S/00007B/00009Q class formals and documented same-basename/source routes | include ObjectStatusBlob.h, LivingObjectPane.h, and ObjectList.h before affected definitions | none after callback |
| How are Win32, PacketBuffer, and sender APIs declared? | standard Win32 API, UID0000M8 documented PacketBuffer.h, UID0000DD/0000NS documented Socket.h and extern sender | include `<windows.h>`, PacketBuffer.h, and Socket.h; sole g_packetSender definition stays Socket.cpp | none after callback |
| How is `g_pInputBlockerPane` declared? | UID0003EE exact pointer formal and UID0000P1 ownership | UserPane.h exports the extern, with exact forward declaration; combined formal repeats no definition | none after callback |
| How is `ConnectionClosedDialog` made complete? | UID000036 formal and UID0000N0 documented source/header route | include documented `ReconnectDialog.h`; ownership remains ReconnectDialog | none after callback |
| How is `g_pUrlAlertPane` declared? | UID0000SM definition/owner and UID0000HE documented header route | include documented `AlertPanes.h`; definition stays AlertPanes.cpp | none after callback |
| How is `g_useEpfAssets` declared? | UID0000SW formal/xrefs/owner and UID0000O5 writer; no proven shared header | explicit `extern bool g_useEpfAssets;` in MapPane source prelude; definition stays StartupWindow.cpp | none after callback |
| Is reconstructed MapPane.cpp compile-visible after the callback? | full closure matrix for six formals, including complete local/value types, member-call owners, Win32, packet/socket APIs, globals, Event/LObject and Pane facets | yes under the canonical source-tree contract; validator `.cpp`-only artifacts do not negate the header decision | none |
| What score blocker remains? | all assignment-listed blockers plus full dependency-closure audit | only stripped lexical/header proof; target is `92/94` | confidence cap below 95 |

No final answer is "needs investigation." Every assignment-listed issue has a current conclusion. Future symbol recovery could refine lexical/header spelling, but the current implementation answer is the complete dependency graph and MapPane package above, not Event.h alone or PCH assumptions. Callback implementation may proceed at `92/94` only by implementing and verifying that whole package.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current inspected manual roots:

| Manual file | Current SHA-256 | Bytes / physical lines |
| --- | --- | --- |
| `by-memory/-coverage-report.md` | `0B7613ED5A8026F44AA12E55FCC1D0FD1E1C7E5938AA58687394FCAB2A1FEA68` | 1,998,874 / 4,582 |
| `by-class/-coverage-report.md` | `45A6008695F99C043D81466D8CE0767C7766CAF47BFDC5CC1EE1052E10878246` | 258,570 / 624 |
| `by-file/-coverage-report.md` | `FA46E74105C0E81FD14E3B3FD56745E2C05F654F78B48F906E2107C65020D612` | 155,316 / 317 |
| `by-global/-coverage-report.md` | `A8089C99BEAC6A154F3FDA437E0AAA70A6188EDD6AC5BC4CC98E953ADBF5FA9A` | 99,613 / 217 |
| `by-type/by-struct/-coverage-report.md` | `EBA8BEFBA2A51A97B2091D16B4043C43A08B1446B5684D22B25AA080EFCC7B07` | 58,525 / 137 |

The supervisor must reread these rows immediately before applying them and preserve any concurrent same-or-greater detail. B001 must not edit manual coverage.

### `by-memory/-coverage-report.md`

1. Replace the current UID0001AP row at its existing anchor with:

```text
    - [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) 0x00503ef0-0x0050637a | class aggregate/source-range index | MapPaneWeatherCoordinateObjectCore : reconstructable : 90% : very-strong : MapPane weather/effect, lifecycle, map-cache, coordinate, scroll, movement, timer, and object source-range aggregate; the 2026-06-01 inventory identified 35 modeled functions and twelve major initial splits, while current exact child pages own source bodies, raw no-route evidence, tables, and alignment. UID000421 is the exact source-ready unclamped visible-tile bounds child with one UserPaneProcessMovement caller, canonical MapRect/MapPane field contract, one-tile half-open margin, void const C++, and separate UID000420/000422/000423/000424 siblings. UID0003ZT closure resolves the timer-6/timer-8 queued-state family to canonical bool m_queuedMapStateRefresh, inherited TimerHandler calls, and the Pane CaptureMouse/ReleaseMouseCapture pair while preserving raw UID00042E/UID00042G as non-emitting no-route children.
```

2. Under UID0001AP, after the existing UID0002QM row and before UID0002QN, insert these four exact rows in address order:

```text
        - [UID:00042E][0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6](by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md) 0x00505c00-0x00505cb1 | raw no-route MapPane helper | MapPaneQueueMovementRefreshTimer6 : reconstructable : 87% : strong : Exact raw timer-6 queue body with coordinate conversion, Sleep(100), canonical bool m_queuedMapStateRefresh, inherited TimerHandler schedule at MapPane+0xa4, Pane::CaptureMouse, paired ReleaseMouseCapture drain evidence, exact padding, and exhaustive no-function/no-xref/no-pointer/no-vtable/no-generated-route proof; remains non-emitting with blank formal C++.
        - [UID:00042F][0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh](by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md) 0x00505cc0-0x00505cf9 | MapPane method | MapPaneClearQueuedMovementRefresh : reconstructable : 90% : very-strong : Source-ready MapPane queued-state clearer with canonical bool m_queuedMapStateRefresh, exact timer-id-6/8 cancellation through the inherited TimerHandler facet, proven Pane::ReleaseMouseCapture helper, paired queue paths, target-callback equivalence, rejected refresh-helper history, and complete formal C++.
        - [UID:00042G][0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8](by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md) 0x00505d00-0x00505d9a | raw no-route MapPane helper | MapPaneQueueMovementRefreshTimer8 : reconstructable : 87% : strong : Exact raw timer-8 queue body with pending coordinate conversion, Sleep(100), input-blocker gate, canonical bool m_queuedMapStateRefresh, inherited TimerHandler schedule at MapPane+0xa4, Pane::CaptureMouse, exact padding, and exhaustive no-function/no-xref/no-pointer/no-vtable/no-generated-route proof; remains non-emitting with blank formal C++.
        - [UID:00042I][0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll](by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md) 0x00505de0-0x00505dfe | MapPane method | MapPaneClearPendingActionPoll : reconstructable : 87% : strong : Exact MapPane pending-action-poll clearer with bool m_pendingActionPoll, timer-id-7 cancellation through inherited TimerHandler source shape, UID0003ZS event-7 lifecycle, and complete formal C++.
```

3. Under UID0001AT, immediately after the existing UID00037T row, insert UID00037U and UID0003ZT below. Delete the old standalone UID0003ZS row at its current anchor and reinsert the exact replacement as the second child under UID00037U:

```text
        - [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md) 0x00508f60-0x00509470 | non-emitting split index | MapPaneNotifyTimerCore : not reconstructable : 88% : very-strong : Exact split index over UID0003ZT EventHandler system/control callback, five bytes of internal 0xcc alignment, UID0003ZS TimerHandler callback, and pre-getter tail/alignment; exact children own source C++ and MapPane routing while this mixed range remains blank-C++ and non-emitting.
            - [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) 0x00508f60-0x0050902b | virtual system/control event method | MapPaneHandleSystemOrControlEvent : reconstructable : 92% : very-strong : Exact live MapPane EventHandler-slot callback with secondary-this normalization, Event::m_type and kEventWorkNotification, unconditional pre-discriminator queued-state drain under g_useEpfAssets, canonical bool m_queuedMapStateRefresh, inherited timer-id-6/8 cancellation, proven Pane::ReleaseMouseCapture, g_pUrlAlertPane guard, exact 624-byte ConnectionClosedDialog construction path, handled/unhandled returns, exact bytes/hash/padding, compile-visible human C++, and a dependency-closed MapPane package using self-contained Event.h/LObject.h, Pane/EventHandler/TimerHandler, complete MapPoint/ObjectStatusBlob/UserPane/LivingObjectPane/ObjectList declarations, Win32 input declarations, PacketBuffer/Socket APIs, documented alert/dialog headers, and exact global externs.
            - [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) 0x00509030-0x00509439 | virtual timer method | MapPaneMovementTimerHandler : reconstructable : 88% : strong : Source-ready MapPane timer callback with singular UserPane-typed local-player and queued-state fields, exact movement/path/action timer branches and helper signatures, intentional global g_pUserPane event-7 route, explicit inherited TimerHandler::ScheduleTimer source shape, complete MapPoint/ObjectList/UserPane/Win32/InputBlocker declaration routes, compiler exclusions, and complete body.
```

4. Replace the existing UID0004QB row at its current anchor with:

```text
            - [UID:0004QB][0x0050b1b0-0x0050b2af.MapPaneInteractWithObject](by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md) 0x0050b1b0-0x0050b2af | method | MapPaneInteractWithObject : reconstructable : 92% : very strong : Source-ready MapPane interaction sender with exact six-byte 0x43/0x01/object-id packet, ObjectStatusBlob human gate, timer-id-5 cooldown, nonhuman immediate send, five call sites, value-first packet ABI, explicit inherited TimerHandler::ScheduleTimer source shape, and complete LivingObjectPane/ObjectStatusBlob/PacketBuffer.h/Socket.h/g_packetSender declaration visibility.
```

5. Replace the existing stale UID0002SQ row at its current anchor with:

```text
        - [UID:0002SQ][0x0061e71c-0x0061e7a0.MapPaneVtableData](by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md) 0x0061e71c-0x0061e7a0 | compiler-generated vtable data | MapPaneVtableData : reconstructable : 88% : very-strong : Exact three-view MapPane vtable/COL range with complete slot inventory, constructor/cleanup stores, GameServerConfig/SelfSaveOKPane boundaries, compiler-regenerated covered-by disposition, UID0003ZT at secondary EventHandler system/control slot 0x0061e77c with Event * and kEventWorkNotification semantics, and UID0003ZS at tertiary TimerHandler slot 0x0061e79c; owner/emitter is UID00007Q MapPane.
```

### `by-class/-coverage-report.md`

Replace the existing UID00007Q row at its current anchor with the following no-loss row, preserving all prior packet/source-family facts and appending this callback:

```text
- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era MapPane declaration emitter at position 0 with exact 0x910 layout and current method union, preserving source-ready effect/HitBar/static-object UID0003TI/UID0003TJ work, opcode-0x15 UID0003TK map/effect-state parsing, opcode-0x06 UID0003TL map-info/tile-region parsing, opcode-0x29 UID0003TO object/effect routing, opcode-0x33 UID0003TX object-info handling with UID0003TW status-overlay helper and corrected by-value UID0002QN factory, source-ready opcode-0x13 UID0003TQ action-combat processing with exact UID0004SJ/UID0004SK/UID0004SL/UID0004SM owner-file dependencies, source-ready opcode-0x2e UID0003TP HandleObjectWorldMapCreationPacket trusted parsing with a local std::vector<bool> directed graph, exact whole-name legacy world-map coordinate overrides, WorldMapPane/Layer installation, cleanup and true return, source-ready opcode-0x19 UID0003TS HandleAnimationSoundPacket with SoundObject/zone-music/MIDI subtypes, exact framed records, corrected m_zoneMusicId/m_zoneMusicFallbackTrackIndex/m_zoneMusicVolumeScale fields, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion, and source-ready opcode-0x1d UID0003TT HandleObjectStatusPacket with exact full/partial ObjectStatusBlob, object-info/counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle and UID0003HS item update route; exact file-local UID0004SN Pursuit adapter remains MapPane.cpp-owned while creator/member implementation stays MessageDialogs-owned, and all unrelated methods/fields, class closure, size guard, children, unsafe trusted-buffer behavior, and compiler ABI exclusions remain preserved. The callback adds the private UID0003TY HandleMapTransitionPacket declaration with exact transition-token/socket/registry/dialog/timer behavior and six independently owned helper dependencies while preserving the complete class union. UID0003ZT closure replaces the stale raw notify signature with HandleSystemOrControlEvent(Event *), removes the invented RefreshQueuedMapState helper, retains canonical bool m_queuedMapStateRefresh, uses inherited TimerHandler and Pane::ReleaseMouseCapture source shape, source-types +0x418 as UserPane *, emits complete MapPoint before MapPane, and adds a dependency-closed package for Event/LObject, Pane/EventHandler/TimerHandler, ObjectStatusBlob, UserPane/InputBlocker, LivingObjectPane, ObjectList, Win32 input, PacketBuffer, Socket/g_packetSender, AlertPanes, ReconnectDialog, and g_useEpfAssets while preserving exact 0x910 layout, unrelated declarations, class closure, size guard, and children.
```

Replace the existing UID00004L, UID00004N, and UID000036 rows at their current anchors with these exact no-loss rows:

```text
- [UID:00004L][Event](by-class/Event.md) : reconstructable : 94% : very-strong : Event.cpp-owned exact 0x110 event record with complete 0x108 EventType payload union, pointer-local message time at object +0x18, key/text/composition/IME-local message time at +0x10c, retained real variant storage extents, no explicit compiler-alignment m_padding members, y/x pointer order, key/text/modifier overlays, shared PaneKeyCode including Delete 0x84 and PageUp/PageDown, Alt/Control/Shift flags, producer/dispatcher/UID00030F consumers, source declaration, and scalar/vtable compiler separation. UID0003ZT confirms this is the canonical complete EventType/kEventWorkNotification/Event declaration contract in self-contained ui/core/Event.h, which includes exact util/LObject.h before Event's base-derived declaration and is consumed directly by MapPane.cpp without duplication.
- [UID:00004N][EventHandler](by-class/EventHandler.md) : reconstructable : 89% : strong : Base event-handler interface with exact constructor/destructor/default-slot bodies, vtable/RTTI layout, narrow Pane-side caller evidence, EventDispatcher parent attachment, and exact packet/system-control/type-19 slot family documented. Highest-probability ui/core/EventHandler.h owns EventPointPair and EventHandler, forward-declares Event and EventDispatcher, and declares extern EventDispatcher *g_pEventDispatcher without a partial dispatcher class; EventHandler.cpp includes EventDispatcher.h for SetPaneOrder, EventDispatcher.h includes TimerHandler.h and EventHandler.h before its complete shell, Pane.h includes GrafPort.h/EventHandler.h/TimerHandler.h, and member-access consumers include separate Event.h.
- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) : reconstructable : 92% : very-strong : Source-ready connection-loss alert class in ReconnectDialog.cpp with default and explicit Pane-pointer constructors, exact AlertPane plus Singleton<ConnectionClosedDialog> inheritance, implicit virtual destructor, HandlePacketEvent and primary/secondary callback declarations, private InitializeConnectionState helper, three inherited facets, nine-entry RTTI, PMD +0x270 EBO at the 0x270 endpoint, typed singleton route, compiler-only publication/cleanup, CopyWindow side-path exclusion, complete formal declaration, and ordered method children. The complete class is exported through the documented UID0000N0 ReconnectDialog.h contract and consumed by UID0003ZT MapPane's ordinary new ConnectionClosedDialog without moving constructor ownership.
```

For the following current rows, preserve every existing byte of row text and append the quoted suffix immediately before the line ending. This is an exact no-loss append operation, not permission to summarize or replace the existing row:

- UID00004M `EventDispatcher`: append exactly ` UID0003ZT commits EventDispatcher.h to include TimerHandler.h and EventHandler.h before its dispatcher-local records/storage and complete router shell; EventHandler.h forward-declares Event/EventDispatcher without a partial dispatcher class, EventHandler.cpp includes EventDispatcher.h for SetPaneOrder, and complete Event remains owned by self-contained Event.h.`
- UID0000A2 `Pane`: append exactly ` UID0003ZT commits Pane.h to include GrafPort.h, EventHandler.h, and TimerHandler.h so the complete base plus inherited facets are visible without re-owning those interfaces or relying on an unnamed precompiled header.`
- UID0000FQ `UserPane`: append exactly ` UID0003ZT confirms MapPane +0x418 is source-typed UserPane * because UID0003ZS calls UserPane-only ProcessMovement twice; UserPane.h exports the complete UserPane declaration plus g_pUserPane and g_pInputBlockerPane extern contracts while their definitions remain singular.`

### `by-file/-coverage-report.md`

Replace the existing UID0000L3 row at its current anchor with the following no-loss row:

```text
- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children route and the full current cross-agent effect/HitBar/static-object/map-state/map-info/object-move/object-info/action-combat union, including UID0003TI/UID0003TJ, UID0003TK, UID0003TL, UID0003TO, UID0003TQ with exact UID0004SJ-UID0004SM owner-file calls, UID0003TW/UID0003TX and corrected UID0002QN behavior; preserves source-ready UID0003TP opcode-0x2e trusted world-map parsing, exact whole-name legacy coordinate overrides, WorldMapPane/Layer installation, cleanup and true return, plus retained file-local UID0004SN Pursuit packet adapter with zero-route history and MessageDialogs creator/member boundary; preserves source-ready UID0003TS opcode-0x19 SoundObject/zone-music/MIDI routing with exact framed records, corrected zone/fallback/volume fields and replay contract, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion; and adds source-ready UID0003TT opcode-0x1d object-status handling in exact source order after UID0003TS with full/partial ObjectStatusBlob, object-info byte, counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle and ItemObjectPane UID0003HS dependency. All unrelated source families remain present; WorldMapPane, MessageDialogs, Layer, ScreenPane, PacketBuffer, MemoryMan, TimerMgr, SoundObjectPane, ObjectList, MidiPlayer, and SoundManager remain dependency/source owners; unsafe trusted-buffer behavior is retained; and compiler/runtime lowering plus by-file formal metadata remain excluded. UID0003TY directly consumes the exact SOFTWARE\\Nexon\\Kingdom of the Winds registry-root literal, so MapPane.cpp is the second source emitter for ownerless UID0003FV pooled data without a RegistryConfig-static dependency, target-owned array, duplicate root declaration, class-ownership change, or by-file formal change. The callback adds source-ready UID0003TY opcode-0x03 map-transition handling with exact trusted packet layout, zero-endpoint dialog branch, distinct socket/registry paths, preserved uninitialized install-key fallback, opcode-0x10 framing, timer cancellation, and six cross-file helper calls without changing unrelated source families or file-root metadata. UID0002SR source closure additionally places private MapRefreshDimmer class position 1 and exact constructor/HandlePacketEvent/OnTimer positions 2-4 in MapPane.cpp, preserving ScreenDimmer(3,g_pScreenPane), timer 0/2000, opcode 0x22 delete-before-FinishVisibleObjectRefresh behavior, implicit destructor/compiler-only ABI boundaries, and the complete pre-existing MapPane union without pruning. UID0003ZT source closure adds exact HandleSystemOrControlEvent(Event *) after the packet dispatcher and before OnTimerEvent, canonical Event::m_type/kEventWorkNotification handling, queued-state drain through inherited TimerHandler and Pane::ReleaseMouseCapture, ConnectionClosedDialog construction, consistent inherited TimerHandler source shape across all affected emitted MapPane children, complete MapPoint placement in MapPane.h, UserPane-typed +0x418 state, self-contained Event.h/LObject.h, Pane/EventHandler/TimerHandler, ObjectStatusBlob/UserPane/InputBlocker/LivingObjectPane/ObjectList, Win32, PacketBuffer/Socket, AlertPanes/ReconnectDialog, and exact global extern routes without changing unrelated source order or ownership.
```

Replace the existing UID0000J6, UID0000J7, UID0000N0, and UID0000HE rows at their current anchors with these exact no-loss rows:

```text
- [UID:0000J6][Event](by-file/Event.md) : reconstructable : 91% : very-strong : NexusTK/ui/core/Event.cpp event object/factory module with exact Event lifecycle, 0x108 payload union, pointer-local message time at object +0x18, key/text/composition/IME-local message time at +0x10c, and total 0x110 size without explicit compiler-alignment m_padding members; complete EventType/PaneKeyCode includes target-proven Delete 0x84, Alt/Control/Shift flags, EventMan translation, active producers/dispatchers, compiler separation, retained real variant storage extents, and retained helper islands. UID0003ZT confirms the highest-probability human source pair is ui/core/Event.h/Event.cpp: Event.h includes exact util/LObject.h and owns the complete UID00004L enums/record declaration, while Event.cpp owns implementation/factories.
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) : reconstructable : 92% : strong : Direct source route for [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) and [UID:00004N][EventHandler](by-class/EventHandler.md), with UI event-routing module ownership, helper ownership, IDA call/xref evidence, migration notes, stale timer-handler ownership exclusion, extensive class/file/memory cross-references, and documented ui/core/EventDispatcher.h route. UID0003ZT commits EventHandler.h to forward-declare Event/EventDispatcher and own EventPointPair/EventHandler plus the dispatcher extern without a partial dispatcher class; EventDispatcher.h includes TimerHandler.h and EventHandler.h before its dispatcher-local records/storage and complete router shell, EventHandler.cpp includes EventDispatcher.h for SetPaneOrder, and complete Event remains in self-contained Event.h for member-access consumers.
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) : reconstructable : 90% : very-strong : NexusTK/network/ReconnectDialog.cpp source root for ConnectionClosedDialog and ReconnectDialog, with a source-ready complete ConnectionClosedDialog declaration and ordered constructor/callback/init-helper/vtable children, separate external g_pConnectionClosedDialog and g_pReconnectDialog definitions plus exact storage routes, direct Singleton source/compiler lifecycle, mixed aggregate and CopyWindow exclusions, packet/reconnect behavior, pooled resource use, and preserved independent ReconnectDialog class/parser declaration debt. Its documented network/ReconnectDialog.h contract exports the complete ConnectionClosedDialog type consumed by UID0003ZT MapPane's ordinary new expression without moving class or constructor ownership.
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md) : reconstructable : 85% : strong : NexusTK/ui/dialogs/AlertPanes.cpp shared modal-alert source root; VersatileAlertPane has exact typed constructor/destructor/callback source children and non-emitting ABI/vtable support, while all unrelated AlertPane/Blue/Url family evidence and the conservative whole-file score remain preserved. The documented ui/dialogs/AlertPanes.h contract exports the g_pUrlAlertPane declaration consumed by UID0003ZT MapPane, while the sole UID0000SM definition remains in AlertPanes.cpp.
```

For the following current rows, preserve every existing byte of row text and append the quoted suffix immediately before the line ending:

- UID0000M6 `ObjectStatusBlob`: append exactly ` UID0003ZT commits the highest-probability same-basename map/ObjectStatusBlob.h as the complete 68-byte declaration route consumed by MapPane; parser definitions remain in ObjectStatusBlob.cpp.`
- UID0000MC `Pane`: append exactly ` UID0003ZT commits ui/core/Pane.h as the complete Pane declaration route including GrafPort.h, EventHandler.h, and TimerHandler.h, while Pane.cpp retains implementation and none of those dependencies changes owner.`
- UID0000P1 `UserPane`: append exactly ` UID0003ZT commits ui/panels/UserPane.h/UserPane.cpp factoring for the complete UserPane declaration and g_pUserPane/g_pInputBlockerPane extern declarations consumed by MapPane; existing emitter pages retain the sole definitions.`

### `by-global/-coverage-report.md`

Replace the existing UID0000SM and UID0000SW rows at their current anchors with these exact no-loss rows:

```text
- [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) : reconstructable : 87% : very strong : UrlAlertPane singleton pointer at `0x0069b4dc`, with exact memory child [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md), `0x4` / 4-byte storage verified with int_convert.py, six-xref lifecycle table, duplicate-open guard, constructor caller set, main-menu opcode `0x66` URL packet helper, URL buffer/exit flag offsets, vtable-backed class identity, and AlertPanes parent [UID:0000HE][AlertPanes](by-file/AlertPanes.md). UID0003ZT adds a direct MapPane guard consumer through the documented AlertPanes.h extern-declaration contract; the sole definition remains AlertPanes.cpp and must not be duplicated in MapPane.cpp.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) : reconstructable : 88% : strong : Broad EPF/current-layout selector global with exact one-byte storage at `0x0066da97`, initial 1, 366 xrefs across broad startup/UI/resource/input/weather users, strict neighboring-global boundaries, alias normalization, and exact memory child [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md) documented as a direct evidence anchor; B001-043 live IDA reconfirmed one write at `0x005807f3` in `StartupWindow__Constructor`, 365 reads, zero unknown operand refs, and zero direct refs in documented Application/Config/WinMain ranges, so the by-global page routes upward to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) as the best existing source-owner inference while original source spelling remains unresolved. UID0003ZT adds an exact MapPane read consumer and direct source-root `extern bool g_useEpfAssets;` declaration because no shared header basename is proven; the StartupWindow.cpp-owned definition remains singular.
```

For current UID0003EE `g_pInputBlockerPane`, preserve every existing byte of row text and append exactly ` UID0003ZT adds the exact MapPane timer consumer and UserPane.h extern-declaration contract; the sole definition remains UID0003EE/UserPane.cpp and MapPane must not duplicate it.`

### `by-type/by-struct/-coverage-report.md`

Replace the existing UID00042K row at its current anchor with:

```text
- [UID:00042K][MapPaneLayout](by-type/by-struct/MapPaneLayout.md) | exact 0x910 layout support | MapPaneLayout : reconstructable : 93% : very strong : Complete exact 0x910 MapPane layout support from inherited Pane through final padding, including screen effecters, highlighted/selected state, 32 Motion records, day/night and AlphaMaskSurface-pointer overlay state, map/tile/resource/action fields, weather/local-player/ObjectList/embedded-GrafPort state, singular canonical aliases, constructor/destructor size proof, and exact opcode-0x15 lifecycle for runtime/refresh/map/dimension/transition/weather/movement/day-night/auxiliary/layer/waiting/EPF fields, with layout-only covered-by formal disposition. Offset +0x39d is the canonical bool m_queuedMapStateRefresh across timer-6/timer-8 queue, clear, EventHandler system/control, and TimerHandler paths; m_movementTimerQueued is retained only as a superseded descriptive alias.
```

For current UID0004R0 `MapPoint`, preserve every existing byte of row text and append exactly ` UID0003ZT commits the exact two-int declaration to map/MapPane.h before MapPane so UID0003ZS local MapPoint objects are complete; MapPane.cpp remains the source owner and all row/column semantics stay unchanged.`

## Follow-Up Actions

- B001 callback is complete: C3ZT-01..C3ZT-48 and C3ZT-50..C3ZT-61 are incorporated and verified across D1-D30; all six managed formal blocks match; all explicit read-only providers were reread; 30 serial scoped validators passed; generated and tracker checkpoints were reread; and all B001 leases were released.
- Supervisor handoff at command16920: this exact post-callback artifact carries complete ordinary-document/generated verification and the preserved supervisor-owned IDA Gate 2B readback. Supervisor review, manual C3ZT-49 application, and lifecycle handling remain role-separated supervisor actions rather than B001 completion claims.
- Durable lifecycle authority: use any later validator-owned report footer/registry/archive path and regenerated research tracker as current truth. The timestamped command16920 `0/0/0` checkpoint records only the pre-execution state and is historical after lifecycle execution.
- A-agent actions: none.
- Future B001 research: none for this target unless the supervisor identifies a concrete post-callback artifact defect or contradictory evidence.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; current implemented `92/94` reflects complete behavior/body/source-placement/declaration closure under ranked `Event.h` factoring, successful scoped validation, exact six-block comparison, and generated semantic readback, with uncertainty limited to stripped original spelling.
- Remaining uncertainty: exact historical developer spelling of the virtual, field, and header basename cannot be recovered from current symbols/docs. The committed `Event.h`/`EventHandler.h`/`EventDispatcher.h` split is the most defensible period/project answer and replaces deferral.

## Validator Results

- Command form for every ordinary destination: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`, run serially from `source-3/project-documentation` while the corresponding short B001 lease was held. Every command exited `0` with `ok: 1`; generated refresh was deferred during the serial file passes.

| D IDs | Command IDs | Timestamps on 2026-07-23 (America/New_York) | Result / warnings |
| --- | --- | --- | --- |
| D1-D2 | `16824`, `16825` | `21:59:39`, `22:00:58` | both pass; D2 reported 42 pre-existing `missing_ref` warnings |
| D8, D12, D6, D13 | `16829`, `16830`, `16832`, `16833` | `22:01:35`, `22:02:04`, `22:02:44`, `22:03:06` | all pass; no new blocker |
| D3-D5 | `16835`, `16837`, `16839` | `22:04:09`, `22:04:40`, `22:05:17` | all pass; D3 reported 49 pre-existing `missing_ref` warnings |
| D7, D9-D11 | `16842`, `16845`, `16851`, `16858` | `22:07:20`, `22:08:12`, `22:09:05`, `22:10:01` | all pass; no new blocker |
| D14-D17 | `16865`, `16870`, `16878`, `16881` | `22:10:57`, `22:11:28`, `22:12:23`, `22:12:48` | all pass; D15 had 2 and D16 had 4 pre-existing `missing_ref` warnings |
| D18-D22 | `16882`, `16884`, `16885`, `16892`, `16895` | `22:13:15`, `22:13:45`, `22:14:04`, `22:14:25`, `22:15:06` | all pass; D19 and D22 each had 3 pre-existing `missing_ref` warnings |
| D23-D26 | `16896`, `16897`, `16898`, `16899` | `22:15:34`, `22:15:58`, `22:16:33`, `22:16:57` | all pass; no new blocker |
| D27-D30 | `16900`, `16901`, `16903`, `16904` | `22:17:26`, `22:17:53`, `22:18:15`, `22:18:33` | all pass; D27 had 5 and D28 had 18 pre-existing `missing_ref` warnings |

- Generated readback: MapPane.cpp header command16910 at `2026-07-23T22:20:59-04:00`; current readback SHA/size is recorded under Supporting Research. Counts are two total `HandleSystemOrControlEvent` occurrences (one declaration, one definition), nine canonical field uses, five inherited cancel calls, four inherited schedule calls, two release-capture uses, one UID0003ZT marker, zero target empty markers, and zero stale source-vocabulary occurrences. Required include and extern routes are present; four unrelated empty markers remain UID0004DS/00037T/0003TN/0001SO.
- Validator-owned queue/report checkpoint: tracker and generated-memory command16920, refreshed `2026-07-23T22:26:56-04:00`; exact hashes/sizes and UID0003ZT `92/94`, coded, `0/0/0` state are recorded under Supporting Research. This is the authoritative timestamped pre-execution count.
- Six managed formal blocks: exact byte-for-byte comparison passed for UID0003ZT, UID00007Q, UID00042F, UID00042I, UID0003ZS, and UID0004QB.
- Unresolved validator defects: none. Reported `missing_ref` warnings pre-existed and do not contradict the accepted package.
- Report lifecycle command by B001: not run, probed, or dry-run. B001 did not edit validator state, generated/tracker files directly, or a validator-owned report footer.

## Changed Files

- Modified ordinary documentation: all D1-D30 paths and exact current SHA-256/bytes/lines listed under `### Current ordinary-document identity manifest`.
- Modified report in place: `tools/leaser/Agents/Agent-B001/research/0003ZT-MapPaneNotifyMessageCore-source-quality.md`; valid prior research, negative evidence, historical assumptions, claim ledger, managed C++, and the supervisor-owned IDA section were preserved and reconciled to post-callback truth.
- Renamed/moved: none.
- Validator side effects: generated artifacts and validator-owned trackers refreshed through ordinary scoped validation; B001 did not edit them directly. Final current identities and semantic checks are recorded above.
- Manual coverage/generated/tracker/audit/supervisor/goal/validator-state/lifecycle/archive files edited directly by B001: none. B001 made no IDA mutation; the supervisor separately applied, saved, and read back the Gate 2B changes under the exact IDA heading.
- Leases: 30 short ordinary-file leases acquired serially immediately before edits, each released after scoped validation; zero B001 leases remain at final readback.
- Report execution by B001: not run, probed, or dry-run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor accepted pre-callback SHA `4CBEA9E9DCA75ABC6907B9C3F7FF3DA491A50F84E506498C85E3C43DB00A64A5` for implementation before B001 began the callback.
- [x] Update `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md` with C3ZT-01..28, C3ZT-42, C3ZT-45..48, C3ZT-51..61, the exact proposed target formal, `92/94`, and the complete declaration/include closure matrix rather than Event.h-only or PCH assumptions.
- [x] Update `by-class/MapPane.md` with C3ZT-05..14, C3ZT-27, C3ZT-31/32, C3ZT-51..61, complete proposed class formal, exact Event/LObject/Pane/EventHandler/TimerHandler/MapPoint/ObjectStatusBlob/UserPane/LivingObjectPane/ObjectList/Win32/packet/socket/dialog/global dependency routes, canonical field, helper history, and no-loss prior evidence.
- [x] Update `by-file/MapPane.md` with C3ZT-05..18, C3ZT-27/28, C3ZT-51..61, exact header/source order, complete dependency/header/extern routing, and no-loss prior source-family detail.
- [x] Update `by-type/by-struct/MapPaneLayout.md` with C3ZT-12/13/41 and preserve full 0x910 layout evidence/formal disposition.
- [x] Update `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md` with C3ZT-01/02/05/16/28..30/39 and preserve non-emitting split-index state.
- [x] Update `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` with C3ZT-12/14/30/35, exact proposed formal, and all prior branch evidence.
- [x] Update `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md` with C3ZT-04..09/29/30/40 and preserve compiler-generated covered-by handling.
- [x] Update `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` with C3ZT-12..19/33/43 and the exact proposed formal.
- [x] Update `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` with C3ZT-12..18/37 while preserving blank emitter/formal and all route-negative proof.
- [x] Update `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md` with C3ZT-12..18/38 while preserving blank emitter/formal and all route-negative proof.
- [x] Update `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` with C3ZT-12..18/39 while preserving full aggregate inventory/evidence.
- [x] Update `by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md` with C3ZT-14/34 and the exact proposed formal.
- [x] Update `by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md` with C3ZT-14/36 and the exact proposed formal while preserving all packet/body evidence.
- [x] Update `by-class/Event.md` with C3ZT-51/53/61 while preserving the complete UID00004L formal and every prior Event fact; make canonical Event.h self-contained by including exact `util/LObject.h` before the base-derived declaration.
- [x] Update `by-file/Event.md` with C3ZT-51/53/58/61 and commit `ui/core/Event.h`/Event.cpp source factoring without adding a by-file formal.
- [x] Update `by-class/EventHandler.md` with C3ZT-52/53/61, preserving the current formal while committing EventHandler.h to forward declarations only, removing the partial EventDispatcher class declaration, and routing the SetPaneOrder member call through EventHandler.cpp -> EventDispatcher.h.
- [x] Update `by-class/EventDispatcher.md` with C3ZT-52/53/61, preserving its class evidence and committing EventDispatcher.h -> TimerHandler.h + EventHandler.h before dispatcher-local record/storage and complete-router declarations, without absorbing complete Event.
- [x] Update `by-file/EventDispatcher.md` with C3ZT-52/53/61, preserving EventDispatcher.h and distinguishing it from Event.h complete-record ownership.
- [x] Update `by-class/Pane.md` with C3ZT-52/53/61, preserving all prior class evidence and documenting Pane.h -> GrafPort.h + EventHandler.h + TimerHandler.h complete-base/inherited-facet visibility.
- [x] Update `by-file/Pane.md` with C3ZT-52/53/61, preserving the same-basename source pair and documenting the exact Pane.h include graph without changing GrafPort/EventHandler/TimerHandler ownership.
- [x] Update `by-type/by-struct/MapPoint.md` with C3ZT-53/57/58/61, preserving its exact two-int formal/position/consumers and placing the complete declaration in MapPane.h before MapPane.
- [x] Update `by-class/UserPane.md` with C3ZT-57/58/61, preserving its complete class/inheritance evidence, documenting MapPane +0x418 as `UserPane *`, and committing the UserPane.h declaration/extern contract.
- [x] Update `by-file/UserPane.md` with C3ZT-57/58/61, preserving all prior source-family evidence and committing the inferred same-basename header/source split for complete UserPane and singleton extern visibility.
- [x] Update `by-global/g_pInputBlockerPane.md` with C3ZT-57/58/61, preserving its sole definition/lifecycle evidence and adding the UserPane.h extern plus MapPane consumer route.
- [x] Update `by-file/ObjectStatusBlob.md` with C3ZT-57/58/61, preserving all prior object/parser evidence and committing the highest-probability same-basename complete declaration header consumed by MapPane.
- [x] Update `by-class/ConnectionClosedDialog.md` with C3ZT-54/61, preserving its complete formal and documenting MapPane consumption through ReconnectDialog.h.
- [x] Update `by-file/ReconnectDialog.md` with C3ZT-54/61, preserving the documented header/source route and all prior source-family detail.
- [x] Update `by-file/AlertPanes.md` with C3ZT-55/61, preserving the documented header/source route and adding the exact alert-global extern contract.
- [x] Update `by-global/g_pUrlAlertPane.md` with C3ZT-55/61, preserving the singular definition and adding the AlertPanes.h/MapPane consumer route.
- [x] Update `by-global/g_useEpfAssets.md` with C3ZT-56/61, preserving the singular UID0000O5 definition and adding the exact MapPane source-root extern route.
- [x] Reread unchanged `by-file/StartupWindow.md` to confirm UID0000O5 remains the sole `g_useEpfAssets` definition owner; do not edit it unless callback evidence directly contradicts the accepted route.
- [x] Reread and preserve the already-correct read-only declaration providers: `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`, `by-class/ObjectList.md`, `by-file/ObjectList.md`, `by-file/PacketBuffer.md`, `by-class/Socket.md`, `by-file/Socket.md`, `by-global/g_packetSender.md`, `by-file/LObject.md`, TimerHandler wrappers, UID00023O, and `by-file/StartupWindow.md`; edit none unless callback evidence directly contradicts an accepted declaration contract.
- [x] Confirm no edit is needed to other Pane helper consumers; their current behavior evidence is sufficient and they are not deficient declaration owners.
- [x] Confirm no additional declared target UID exists; support UIDs are not claimed as additional report coverage.
- [x] Apply metadata changes only to UID0003ZT (`92/94`) and UID00042F (`90/92`); preserve every other ordinary metadata tuple listed in this report.
- [x] Preserve owner/emitter/reconstructable fields and blank target position exactly.
- [x] Preserve raw UID00042E/G no-route/no-code disposition; do not manufacture functions, emitters, or C++.
- [x] Preserve historical stale assumptions under labeled history rather than deleting evidence.
- [x] Ignore/reject all Wave2/Wave3 material encountered.
- [x] Run scoped validators serially from `source-3/project-documentation` for every changed ordinary file using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`.
- [x] Record exact validator command, command_id, command_timestamp, exit code, ok count, generated-refresh state, warnings, and side effects for each changed ordinary path.
- [x] Reread all editable D1-D30 destinations after validation and record post-callback SHA-256/bytes/lines; reread every explicit read-only provider at line 1016 as an unchanged declaration/definition-owner checkpoint.
- [x] Reread `auto-generated/NexusTK/map/MapPane.cpp` after the final serial validator; record header command/timestamp/source, SHA-256/bytes/lines, and semantic counts.
- [x] Generated acceptance: one `HandleSystemOrControlEvent` declaration, one definition, canonical target body, canonical field, inherited TimerHandler calls, ReleaseMouseCapture, complete MapPoint before all local use, complete ObjectStatusBlob/UserPane/LivingObjectPane/ObjectList member-call visibility, `<windows.h>` for `GetAsyncKeyState`/`VK_LBUTTON`, PacketBuffer and Socket/g_packetSender declarations, documented AlertPanes/ReconnectDialog routes, explicit `extern bool g_useEpfAssets;`, no duplicate Event/global definitions, no incomplete-object/member access, no target Empty Emitter Marker, and zero current `OnNotifyMessage`, `RefreshQueuedMapState`, `m_timerHandler.`, or `m_movementTimerQueued` source vocabulary outside explicit history/comments.
- [x] Verify the canonical final source contract places complete UID00004L EventType/Event declarations in self-contained Event.h -> LObject.h, EventHandler pointer interfaces in EventHandler.h, the complete TimerHandler-derived dispatcher shell in EventDispatcher.h -> TimerHandler.h + EventHandler.h, EventHandler.cpp -> EventDispatcher.h for the member call, complete Pane in Pane.h -> GrafPort.h + EventHandler.h + TimerHandler.h, MapPane.h -> Pane.h + GrafPort.h + Motion.h + `<vector>` with complete MapPoint before MapPane, and every source-only dependency before the six MapPane definitions; validator `.cpp`-only output must not be misreported as overturning this inference.
- [x] Confirm unrelated generated empty markers UID0004DS/00037T/0003TN/0001SO are unchanged/out of scope rather than misreported as target failures.
- [x] Keep all manual `-coverage-report.md` files supervisor-owned; do not edit them.
- [ ] Supervisor to apply the exact manual replacements/inserts/appends for UID0001AP, UID00042E, UID00042F, UID00042G, UID00042I, UID00037U, UID0003ZT, UID0003ZS, UID0004QB, UID0002SQ, UID00007Q, UID00004L, UID00004N, UID00004M, UID0000A2, UID0000FQ, UID000036, UID0000L3, UID0000J6, UID0000J7, UID0000M6, UID0000MC, UID0000P1, UID0000N0, UID0000HE, UID0000SM, UID0000SW, UID0003EE, UID00042K, and UID0004R0 after current-root reread.
- [x] Update Claim And Incorporation Ledger states from `proposed` only after claim-by-claim implementation/readback.
- [x] Updated this same report after callback with current target/support/manual/generated/tracker truth; command16823 is retained as a historical pre-callback baseline, command16910 records current generated artifacts, command16920 records the timestamped pre-execution tracker/memory epoch, and exactly one execution handoff marker is present.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All B001-owned accepted claims C3ZT-01..C3ZT-48 and C3ZT-50..C3ZT-61 are incorporated-verified; C3ZT-49 remains the exact supervisor-owned manual coverage handoff.
- [x] All editable D1-D30 ordinary destinations independently verified, plus every explicit read-only provider at line 1016 reread and confirmed unchanged or reconciled with exact evidence.
- [x] All six proposed managed formal blocks compared byte-for-byte against destination blocks.
- [x] All accepted target/support details incorporated at report-level detail without summarizing away prior valid evidence.
- [x] Metadata/score/source placement/owner/emitter/split decisions verified.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] All open questions remain closed under post-callback evidence.
- [x] Scoped validators complete and serial; zero leases remain.
- [x] Final callback-time generated MapPane.cpp checkpoint and semantic acceptance recorded.
- [x] Exact manual supervisor-owned handoff text is preserved without B001 editing any coverage report; the supervisor application action remains separately unchecked.
- [x] No report lifecycle command invoked by B001.
- [x] Supervisor IDA reconciliation remains preserved as the exact `APPLIED_VERIFIED` Gate 2B evidence record under `## IDA Rename / Type / Comment Recommendations`; B001 did not perform or alter those IDA changes.
- [ ] Supervisor alone may invoke the report lifecycle command and establish the validator-owned footer/registry/archive state; B001 did not run, probe, or dry-run it.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000016933","destination_path":"executed-b-agent-research/B001/0003ZT-MapPaneNotifyMessageCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0003ZT-MapPaneNotifyMessageCore-source-quality.md","timestamp":"2026-07-23T22:45:55-04:00","uid":"0003ZT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
