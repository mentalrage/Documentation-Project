** TARGET-REPORT-UID:00048I **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00048I SimpleHelpPaneOnTimerEvent Source Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: retain the UID and stable historical path `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md` with the applied source-facing method `SimpleHelpPane::HandlePointerOrMouseEvent(Event *event)`.
- Final disposition: source-authored virtual override, not a timer callback, raw helper, compiler wrapper, or non-emitting aggregate. The exact child remains owned/emitted by [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md) through [UID:0000JU][HelpPanes](by-file/HelpPanes.md).
- Applied callback state: Destinations 1-11 and C01-C30 are implemented. The target is `92/94`, remains `CANONICAL_OWNER:0000D6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D6`, has position `50`, and keeps `Nested:0`.
- Behavior: event types `1` and `4` schedule timer id `0` at zero delay with zero payload and return `true`; event type `0` schedules the same timer and returns `false`; every other pointer-family value returns `false` without scheduling. No timer-removal wrapper is called.
- Confidence: very high for range, bytes, CFG, ABI, vtable slot, event-family identity, event type field, schedule operation, branch behavior, owner/emitter, and source placement; high for the accepted descriptive virtual names because no PDB/original source symbol survives.

## Supporting Research

- This is a new report-only pass for the first dedicated exact-target UID00048I report. The older executed aggregate and sibling reports are evidence, not substitutes for this report.
- The historical report [executed-b-agent-research/B007/00016S-SimpleHelpPanes-source-quality.md] classified `0x004c7450` as `OnTimerEvent` and interpreted `0x005975e0` as cancel/remove. Its split/range/owner evidence remains valid; its method, event, and timer-operation interpretation is superseded by the current vtable, dispatcher, RTTI, and TimerHandler evidence.
- The historical reports [executed-b-agent-research/B002/00048H-SimpleHelpPaneOnMouseDown-source-quality.md] and [executed-b-agent-research/B003/00048J-SimpleHelpPaneOnKeyPress-source-quality.md] preserve exact body/range/xref facts but assigned the wrong interface roles. Current evidence identifies UID00048H as the TimerHandler callback and UID00048J as the EventHandler key/text slot.
- [executed-b-agent-research/B004/00048M-SimpleHelpPane2OnAccept-source-quality.md] is an accepted corrective precedent: the tertiary `+0xa4` table is TimerHandler and its `retn 0Ch` handler is `OnTimer(int,int,int)`. The same layout proves UID00048H is the SimpleHelpPane counterpart.
- [executed-b-agent-research/B004/0001K8-TimerHandlerScheduleRemoveWrappers-source-quality.md] supplies the already accepted source-facing TimerHandler API and schedule/remove split. Current live MCP independently revalidated it.
- [executed-b-agent-research/B001/00014A-eventhandler-base-source-quality.md], [executed-b-agent-research/B002/00014B-EventBaseConstructorDestructor-empty-emitter-source-quality.md], and [executed-b-agent-research/B008/00014C-EventManAndEventFactoryHelpers-source-quality.md] supply interface, Event record, dispatcher, and event-family context. Current live dispatcher and producer checks independently revalidated the target-relevant claims.
- The report-only artifact is under B002's assigned research directory at authoring time. No validator, report execution, lifecycle, move, or archive state is asserted for current or future artifacts; those states are external and validator/supervisor-owned.

## Target

- Target UID: `00048I`.
- Target path: `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md`.
- Report path: `tools/leaser/Agents/Agent-B002/research/00048I-SimpleHelpPaneOnTimerEvent-source-quality.md`.
- Queue source: refreshed validator command `000000010518`, `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Queue state at assignment time: `86/90`, report count `0`, reconstructable.
- Exact binary range: half-open `0x004c7450-0x004c7491`, 65 bytes.

## Current Target State

- Evidence-time / pre-callback metadata was `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000D6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D6`, blank optional position, and `Nested:0`. The stale formal C++ used `SimpleHelpPane::OnTimerEvent(const PaneEvent &event)`, a local `0/1/4` enum, and `CancelTimer()`; prose described the operation as cancel/remove.
- Applied target state is `COMPLETION:92`, `CONFIDENCE:94`, retained owner/emitter/reconstructable/Nested metadata, position `50`, and the exact Destination 1 `SimpleHelpPane::HandlePointerOrMouseEvent(Event *event)` body. Validator command `000000010586` accepted the target edit, and B002's waited command `000000010632` completed generated output.
- The target page preserves the exact range, byte read at argument `+4`, branch constants `0/1/4`, both calls to `0x005975e0`, return values, owner/emitter, trailing padding, and historical aliases while explicitly rejecting the stale method/type/cancel interpretation.
- Evidence-time generated `HelpPanes.cpp` mirrored the stale block. B002's waited command `000000010632` produced the corrected output; a later read-only observation of validator-owned header `000000010669` found the same callback content: exactly one UID00048I marker and one accepted method definition, with no UID00048I Empty Emitter Marker, stale `SimpleHelpPane::OnTimerEvent`, or `CancelTimer` call.
- The pre-callback support contradictions are resolved: UID00048H is the TimerHandler callback at position `40`; UID00048J is the EventHandler key/text-family override at position `60`; UID00048N and UID00048O are the SimpleHelpPane2 pointer/mouse and key/text overrides at positions `40` and `50`; UID00004L emits y at `+0x08` then x at `+0x0c`; and prose-only UID0000J6 states the same order without reconstruction metadata.
- B002 edited only the eleven authorized ordinary destinations and this report. Coverage, generated, tracker, audit, supervisor, lifecycle, IDA, and validator-owned files were not edited manually; validator-owned side effects are recorded under Validator Results.

## Executive Recommendation

- Keep the existing exact child and stable path. Treat `SimpleHelpPaneOnTimerEvent` only as a historical slug/search alias.
- Rename the source-facing target method to the accepted EventHandler interface name `HandlePointerOrMouseEvent` and use `Event *` with `m_type` at `+0x04`.
- Emit the exact Destination 1 body. It calls the accepted TimerHandler service `ScheduleTimer(0, 0, 0, 0)`, never `CancelTimer`, `RemovePendingTimers`, or a cancel-by-id wrapper.
- Correct the directly affected same-class handler roles: UID00048H becomes `OnTimer(int,int,int)` and UID00048J becomes `HandleKeyOrTextEvent(Event *)`.
- Correct the homologous SimpleHelpPane2 EventHandler pair and the Event pointer-payload y/x field order because they are the direct vtable/layout proof and otherwise leave source-facing contradictions in the same generated HelpPanes/Event dependency chain. Synchronize both the UID00004L formal declaration and the UID0000J6 Event file-route prose; the latter remains prose-only and non-emitting.
- Preserve UID00016S as a non-emitting split index and preserve class/file pages as route/prose owners. Do not duplicate any child method body on aggregate, class, file, vtable, or compiler-wrapper pages.

## Supervisor Active Recheck

- Report-only trigger at assignment time: the supervisor assigned UID00048I as the next unique target and required live IDA MCP, blocker resolution, exact formal destinations, atomic ledger, manual coverage text, and an initially unchecked callback checklist.
- Split repair: no new split or UID is required. UID00048I already has exact half-open bounds and one source owner.
- Source-bearing scope: every source-bearing target/support body recommended here has a complete managed formal destination below. Verify-only dependencies have an exact no-edit disposition.
- Duplicate-report check: there is no dedicated exact UID00048I report in central executed, older legacy, archived, active B-agent research, or SpecialReports roots.

## Inference Research Guidance Check

- IDA facts are labeled as exact bytes, instructions, control flow, xrefs, table locations, RTTI names, wrapper calls, and producer/dispatcher behavior.
- Documentation evidence is used only after direct revalidation and is historicalized where current evidence disproves a prior source-facing name or operation.
- Inference is limited to human source spellings and declaration placement. `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `Event`, `m_type`, and `ScheduleTimer` are already accepted project vocabulary supported by the recovered interface and wrapper pages.
- The source body avoids decompiler types, local enums, raw addresses, explicit `this` adjustments, vtable syntax, and compiler ABI wrappers.
- Wave2/Wave3 artifacts and old generated source were treated as stale provenance/search material only. They did not override current by-* docs or live MCP evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Resolution | Classification |
| --- | --- | --- | --- |
| `OnTimerEvent` name | SimpleHelpPane secondary table `0x0061ac30`, target at slot `+4`, live EventDispatcher `+4` dispatch, EventHandler declaration | `HandlePointerOrMouseEvent` | High-probability source name; interface role direct |
| `PaneEvent` type | One pointer argument, `m_type` byte at `+4`, EventHandler virtual declaration, Event record layout | `Event *event` | Accepted project type |
| Local values `0/1/4` | Event enum, EventMan producers, pointer classifier `0..7` | `kEventCursorMove`, `kEventLeftButtonDown`, `kEventRightButtonDown` | Accepted descriptive enum |
| `CancelTimer` operation | Target calls only `0x005975e0`; live wrapper forwards to `0x00597910`; removal is separate `0x00597600` | `ScheduleTimer(0,0,0,0)` | Direct behavior and accepted API |
| Receiver adjustment | Target enters with EventHandler subobject at complete `+0xa0`; `add ecx,4` reaches TimerHandler `+0xa4` | Omit from source; inherited TimerHandler call | Compiler/base-layout lowering |
| Return meaning | Target returns one only on button-down values, zero on move and other pointer values; dispatcher returns virtual result | `true` consumes/handles button down; move schedules dismissal but remains unhandled | Direct behavior plus dispatcher contract |
| UID00048H role | `retn 0Ch`, `this-0xa4`, tertiary slot `0x0061ac64` | `OnTimer(int,int,int)` | Direct TimerHandler ABI |
| UID00048J role | `retn 4`, `this-0xa0`, secondary slot `0x0061ac38` | `HandleKeyOrTextEvent(Event *)` | Direct EventHandler slot |
| UID00048N/O homologs | SimpleHelpPane2 secondary slots `0x0061acbc/0x0061acc0`, tertiary OnTimer at `0x0061acec` | Pointer/mouse and key/text handlers; schedule, not cancel | Direct homologous table evidence |
| Event pointer field order | Pointer consumers, `PointInRect(y,x,bounds)`, EventMan state/producers, live UID00048N call order | `m_y` at `+0x08`, `m_x` at `+0x0c` | Direct offset/order evidence; pre-callback declaration was stale and is now corrected |
| Source path | Contiguous HelpPanes family, class owner, existing generator route | `NexusTK/ui/controls/HelpPanes.cpp` | Strong source-placement inference |
| Stable paths | Existing UIDs and generated routes, historical correction precedent UID00048M | Preserve file slugs, correct source-facing titles/prose/code | Collision-safe documentation choice |

Rejected alternatives:

- `OnTimerEvent` is rejected because the target is not in the TimerHandler table and has only one explicit argument.
- `OnMouseDown` is rejected for UID00048I because the slot covers the complete pointer/mouse event family and explicitly handles cursor movement.
- `CancelTimer`, `RemovePendingTimers`, and cancel-by-id spellings are rejected because none call the observed wrapper or manager operation.
- A raw helper/free function is rejected because the target is uniquely table-installed and lifecycle paths install the enclosing class table.
- A compiler-generated adjustor thunk is rejected because the target contains source branch logic, two wrapper calls, and six CFG blocks; only the receiver transition is compiler lowering.
- Aggregate emission from UID00016S is rejected because it would duplicate exact child bodies and include unrelated methods/padding.
- Renaming/moving the target file is rejected as unnecessary UID/path churn; the historical slug remains searchable.

## Evidence Standards Used

- Primary evidence: live IDA MCP health/session checks, function lookup, decompilation, disassembly, bytes, basic blocks, function profiles, xrefs, pointer-pattern search, names/RTTI, vtable bytes, dispatcher analysis, timer-wrapper/manager analysis, and event-producer analysis.
- Secondary evidence: evidence-time by-* target/support docs and generated HelpPanes output read-only, inspected tracker/manual coverage rows, source-tree guidance, and matching executed reports.
- Negative evidence: no direct code callers, no target string/constants beyond branch values, no RVA pointer hit, no removal-wrapper call, no null check, no event payload reads beyond `m_type`, no direct close call, no exception/EH body, and no PDB/source symbol.
- The evidence ladder is sufficient for a high-confidence first draft because range, ABI, interface slot, accepted dependency APIs, and exact behavior all converge. The confidence cap is original spelling/header provenance, not runtime semantics.

## Evidence Checked

IDA MCP/manual checks performed against evidence-time database `supervisor_nexustk_20260713`:

- Fresh `idb_list`: one active adopted NexusTK session, `is_analyzing:false`, worker PID `2236`.
- Evidence-time `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis, Hex-Rays, and strings cache ready. This is an evidence-collection-time observation only and does not assert future session availability.
- `lookup_funcs`: target/siblings, boundaries, schedule/remove/cancel wrappers, and manager schedule function.
- `analyze_function`, `disasm`, `basic_blocks`, `func_profile`, `get_bytes`, `xrefs_to`, `find_bytes`, and `entity_query` for the target, adjacent handlers, vtables, TimerHandler wrappers, manager schedule, EventDispatcher, EventMan pointer producers, and SimpleHelpPane2 homologs.

Documentation/support inputs checked:

- Target UID00048I; UID00048E-H/J/K-O; classes UID0000D6/UID0000D7; aggregate UID00016S; file UID0000JU; Event UID00004L and Event file UID0000J6; EventHandler UID00004N; TimerHandler UID0000F0; wrappers UID0001K8; RectBounds/PointInRect; read-only data UID00025G; generated `HelpPanes.cpp`; tracker row; manual by-class/by-file/by-memory coverage rows.

Exact report-root search terms:

- `UID:00048I`, `UID00048I`, `0x004c7450`, `0x004c7491`, `SimpleHelpPaneOnTimerEvent`, `SimpleHelpPane::OnTimerEvent`, `HandlePointerOrMouseEvent`, `PaneEvent`, `CancelTimer`, `0x005975e0`, `UID0001K8`, `SimpleHelpPane`, `HelpPanes`.

Exact roots searched and outcomes:

- The report-root results below are the evidence-time, pre-creation search snapshot. This assigned B002 report did not yet exist when those roots were searched.

- Central executed root `source-3/project-documentation/executed-b-agent-research`: no dedicated exact-target report; exact-target mentions opened in B007 `00016S`, B002 `00048H`, and B003 `00048J`. Relevant support reports opened: B011 `00048E`, B004 `00048M`, B004 `0001K8`, B001 `00014A`, B002 `00014B`, and B008 `00014C`.
- Legacy older root `source-3/project-documentation/tools/leaser/Agents/Older-Research`: no direct exact-target match.
- Archived root `source-3/project-documentation/archived`: no direct exact-target match.
- Active report roots `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`: no active exact-target report existed in the pre-creation snapshot. B002 `goal.md` and `SupervisorAssignments.md` matched assignment text only, not research artifacts.
- Special root `source-3/project-documentation/tools/leaser/Agents/SpecialReports`: no direct exact-target match.

Failed/unavailable/skipped checks:

- The first PowerShell `Invoke-WebRequest` omitted `-UseBasicParsing`; that local client parsing attempt failed before any MCP call. Retrying with `-UseBasicParsing` succeeded. No MCP `tools/call` failed or returned a missing/unreachable database.
- IDA writes, process management, validators, lifecycle probes, report execution, and generated/coverage writes were intentionally prohibited and not attempted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target is one modeled function at `0x004c7450-0x004c7491`, size `0x41`. | Very high | live lookup/profile | Destination 1 range/evidence; validator `000000010586` | incorporate | applied |
| C02 | Exact 65 bytes have SHA256 `0C38293E65BC20914975B70755A8AAE13A1A0192FA46AF17BD0B086AD97A87D8`. | Very high | live bytes plus local hash | Destination 1 bytes/hash; validator `000000010586` | incorporate | applied |
| C03 | Target has 28 instructions, six blocks, cyclomatic complexity 3, and exact branch graph recorded below. | Very high | profile/basic_blocks/disasm | Destination 1 CFG; validator `000000010586` | incorporate | applied |
| C04 | ABI is x86 `__thiscall`, one explicit pointer argument, bool in `AL`, and `retn 4`. | Very high | disasm/decompile | Destination 1 ABI; validator `000000010586` | incorporate | applied |
| C05 | `0x0061ac34 -> 0x004c7450` is the unique VA pointer and EventHandler secondary slot `+4`. | Very high | xrefs/find_bytes/vtable | Destinations 1, 7-10; validators `000000010586`, `000000010609`, `000000010615`, `000000010620`, `000000010627` | incorporate | applied |
| C06 | SimpleHelpPane uses EventHandler at complete `+0xa0` and TimerHandler at `+0xa4`. | Very high | RTTI/table installs/adjustments | Destinations 1-3, 7-10; validators `000000010586`, `000000010590`, `000000010595`, `000000010609`, `000000010615`, `000000010620`, `000000010627` | incorporate | applied |
| C07 | EventDispatcher routes pointer/mouse events through EventHandler slot `+4`. | Very high | live `0x004a77d0` | Destinations 1, 7-10; validators `000000010586`, `000000010609`, `000000010615`, `000000010620`, `000000010627` | incorporate | applied |
| C08 | Target source type is `Event *`; `m_type` is an unsigned byte at `+0x04`. | Very high | Event layout/read width/interface | Destinations 1, 6, and 11; validators `000000010586`, `000000010606`, `000000010629` | incorporate | applied |
| C09 | Values `0/1/4` are cursor move, left-button down, and right-button down. | High | Event enum/live producers/classifier | Destinations 1, 4, 6-10; validators `000000010586`, `000000010599`, `000000010606`, `000000010609`, `000000010615`, `000000010620`, `000000010627` | incorporate | applied |
| C10 | Type `1` schedules `(0,0,0,0)` and returns true. | Very high | exact branch/disasm | Destination 1 body/behavior; validator `000000010586` | incorporate | applied |
| C11 | Type `4` schedules `(0,0,0,0)` and returns true. | Very high | exact branch/disasm | Destination 1 body/behavior; validator `000000010586` | incorporate | applied |
| C12 | Type `0` schedules `(0,0,0,0)` and returns false. | Very high | exact branch/disasm | Destination 1 body/behavior; validator `000000010586` | incorporate | applied |
| C13 | Other pointer values `2,3,5,6,7` do not schedule and return false. | Very high | CFG plus classifier range | Destination 1 behavior; validator `000000010586` | incorporate | applied |
| C14 | Target performs no null check, payload-coordinate read, direct close, field write, or cleanup. | Very high | full body inventory | Destination 1 negative evidence; validator `000000010586` | incorporate | applied |
| C15 | Raw `add ecx,4` is EventHandler-to-TimerHandler base adjustment and must not appear in source. | Very high | RTTI/base offsets/tables | Destination 1 source notes; generated readback `000000010632` | historicalize | applied |
| C16 | `0x005975e0` is `TimerHandler::ScheduleTimer`, not cancel/remove. | Very high | wrapper and UID0001K8 | Destinations 1, 4, 9-10; validators `000000010586`, `000000010599`, `000000010620`, `000000010627` | reject-stale | applied |
| C17 | Manager schedule stores owner, id, due tick `current+delay`, and two payload dwords in an ordered five-dword record. | Very high | live `0x00597910` | Destinations 1, 4, 9-10; validators `000000010586`, `000000010599`, `000000010620`, `000000010627` | incorporate | applied |
| C18 | Removal is separate `0x00597600`; cancel-by-id wrappers are `0x00597610/30`; target calls none. | Very high | live wrapper inventory/xrefs | Destination 1 negative evidence; validator `000000010586`, generated readback `000000010632` | reject-invalid | applied |
| C19 | Destination 1 is compile-valid, behavior-identical, period-plausible first-draft source. | High | dependency and behavior audit | Destination 1 formal block; validators `000000010586`, `000000010632` | incorporate | applied |
| C20 | Target metadata is `92/94`, owner/emitter unchanged, position `50`, `Nested:0`. | High | blocker closure/source order | Destination 1 metadata; validator `000000010586` | incorporate | applied |
| C21 | UID00048H is TimerHandler `OnTimer(int,int,int)`, not mouse-down. | Very high | `retn 0Ch`, `this-0xa4`, slot `0x61ac64` | Destination 2; validator `000000010590` | reject-stale | applied |
| C22 | UID00048J is EventHandler `HandleKeyOrTextEvent(Event *)`, not generic key-press. | Very high | secondary slot `+8`, dispatcher | Destination 3; validator `000000010595` | reject-stale | applied |
| C23 | UID00048N is the SimpleHelpPane2 pointer/mouse homolog and schedules rather than cancels. | Very high | slot `0x61acbc`, live body | Destination 4; validator `000000010599` | reject-stale | applied |
| C24 | UID00048O is the SimpleHelpPane2 key/text homolog. | Very high | slot `0x61acc0`, ABI/body | Destination 5; validator `000000010603` | reject-stale | applied |
| C25 | Event pointer payload is y-first at `+0x08`, x-second at `+0x0c`; UID00004L carries the corrected formal declaration and prose-only UID0000J6 carries the same direct-evidence, confidence-ranked, historically reconciled order without by-file C++ metadata. | High | producers, point ABI, consumers, pre-callback class/file drift | Destinations 6 and 11; validators `000000010606`, `000000010629`; generated readback `000000010632` | reject-stale | applied |
| C26 | SimpleHelpPane and SimpleHelpPane2 class pages remain route owners with marker/children C++ unchanged. | High | ownership/generator route | Destinations 7-8; validators `000000010609`, `000000010615` | incorporate | applied |
| C27 | UID00016S remains `RECONSTRUCTABLE:FALSE`, blank emitter/formal body, non-emitting split index. | Very high | mixed classes/padding/exact children | Destination 9 current metadata/index; validator `000000010620` | already-present | applied |
| C28 | HelpPanes and Event remain their respective source-file routes; Destinations 10 and 11 are prose-only and receive no by-file reconstruction metadata/body. | Very high | by-file guidance/current routes | Destinations 10-11; validators `000000010627`, `000000010629`; header readback | incorporate | applied |
| C29 | EventHandler, TimerHandler/UID0001K8, constructors, RectBounds, and vtable data were verify-only; callback reread found no concrete drift beyond listed Destinations. | High | current docs/live checks | Read-only contracts re-read; no concrete accepted-scope drift, no edits | not-applicable | excluded-with-reason |
| C30 | Six exact supervisor-owned manual coverage replacements preserve current/recommended metadata: UID00016S is `not_reconstructable : 88%`; UID00004L, UID0000D6, UID0000D7, UID0000J6, and UID0000JU are `reconstructable` at `92%`, `86%`, `88%`, `91%`, and `90%` respectively. The UID0000J6 row's corrected y/x description is synchronized with prose-only Destination 11. Exact-count/order/no-duplicate checks completed through validator-owned output. | High | current page headers plus inspected manual rows/workflow | Manual rows excluded as supervisor-owned; generated exact-count/order proof completed by `000000010632` | incorporate | excluded-with-reason |

## Positive Evidence Summary

- The target address occurs exactly once as a VA pointer, at `0x0061ac34`, inside the named SimpleHelpPane secondary vtable.
- The EventDispatcher directly proves secondary slot `+4` is the pointer/mouse event-family virtual.
- The neighboring secondary slot `+8` is UID00048J, while the separate tertiary TimerHandler table points to UID00048H. This resolves all three SimpleHelpPane handlers without relying on filenames.
- The target reads only the accepted Event type byte and implements branch behavior for three accepted pointer-family values.
- Both target calls reach the accepted TimerHandler schedule wrapper; live manager code proves zero delay and queue insertion, not removal.
- Constructor/destructor/scalar paths repeatedly install the same secondary/tertiary table bases, proving class ownership and live virtual routing despite zero direct code callers.

## IDA MCP Facts

Function/range facts:

- `lookup_funcs(0x004c7450)` -> `sub_4C7450`, size `0x41`; `0x004c7491` is not a function.
- Exact instructions:
  - prologue; load explicit argument; load byte `[arg+4]`;
  - compare `1`, compare `4`, test zero;
  - zero path pushes four zeros, adds `4` to `ecx`, calls `0x005975e0`, returns `AL=0`;
  - one/four path pushes four zeros, adds `4` to `ecx`, calls `0x005975e0`, returns `AL=1`;
  - both returns use `retn 4`.
- Exact bytes: `55 8b ec 8b 45 08 8a 40 04 3c 01 74 1e 3c 04 74 1a 84 c0 75 10 6a 00 6a 00 6a 00 6a 00 83 c1 04 e8 6b 01 0d 00 32 c0 5d c2 04 00 6a 00 6a 00 6a 00 6a 00 83 c1 04 e8 55 01 0d 00 b0 01 5d c2 04 00`.
- CFG blocks: `7450-745d -> 745d/747b`; `745d-7461 -> 7461/747b`; `7461-7465 -> 7465/7475`; `7465-7475 -> 7475`; `7475-747b return`; `747b-7491 return`.

Boundary/padding facts:

- Predecessor UID00048H ends exactly at `0x004c7450` after two `0xcc` bytes at `0x004c743e-0x004c7440` before it.
- Target ends exactly at `0x004c7491`.
- `0x004c7491-0x004c74a0` is fifteen `0xcc` bytes; successor UID00048J starts at `0x004c74a0`.

Xref/table/type facts:

- Target xrefs: one data xref at `0x0061ac34`, zero code callers.
- VA pointer `50 74 4c 00`: one match at `0x0061ac34`; RVA `50 74 0c 00`: zero matches.
- Named vtables: primary `0x0061abe4`, secondary `0x0061ac30`, tertiary `0x0061ac60`.
- Secondary entries start scalar adjustor `0x004ce38d`, target `0x004c7450`, UID00048J `0x004c74a0`, then inherited EventHandler defaults.
- Tertiary entries start scalar adjustor `0x004ce398`, UID00048H `0x004c7440`.
- Table-base refs: secondary at constructor/destructor/scalar paths `0x004c700f/0x004c72c1/0x004ce598`; tertiary at `0x004c7019/0x004c72cb/0x004ce5a2`.
- RTTI identifies SimpleHelpPane with Pane/GrafPort/LObject, EventHandler at complete `+0xa0`, TimerHandler at complete `+0xa4`, and Singleton support.

Timer facts:

- `0x005975e0` size `0x1f`, `__thiscall` with four explicit dwords, forwards receiver plus arguments to `g_pTimerMgr->0x00597910`, returns with `retn 10h`.
- `0x00597910` builds a five-dword queue record: owner, timer id, due tick `delay + currentTick`, arg0, arg1; it inserts in due-time order.
- `0x00597600` is the distinct owner-wide pending-timer removal wrapper. `0x00597610` and `0x00597630` are distinct one-argument manager wrappers. Target references none.

Negative IDA facts:

- No strings, resource literals, globals, EH cleanup, allocation/free, direct object field writes, or direct Close call occur in the target.
- No PDB/original target symbol, alternate target pointer, direct code caller, or RVA pointer route was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c6f90-0x004c7287` | UID00048E | SimpleHelpPane constructor; schedules timer 0 with caller delay | true | UID0000D6 | preserve | verify-only |
| `0x004c7290-0x004c7307` | UID00048F | ordinary destructor | true | UID0000D6 | preserve | verify-only |
| `0x004c7310-0x004c743e` | UID00048G | paint | true | UID0000D6 | preserve | verify-only |
| `0x004c7440-0x004c7450` | UID00048H | TimerHandler `OnTimer(int,int,int)`, closes, returns false | true | UID0000D6 | `88/92 -> 91/94` | Destination 2 |
| `0x004c7450-0x004c7491` | UID00048I | EventHandler pointer/mouse override | true | UID0000D6 | `86/90 -> 92/94` | Destination 1 |
| `0x004c7491-0x004c74a0` | UID0000VN | fifteen-byte padding | false | none | `100/strong` | unchanged |
| `0x004c74a0-0x004c74b0` | UID00048J | EventHandler key/text override | true | UID0000D6 | `88/92 -> 91/94` | Destination 3 |
| `0x004c7610-0x004c7620` | UID00048M | SimpleHelpPane2 TimerHandler `OnTimer`, closes, returns true | true | UID0000D7 | preserve `88/91` | verify-only accepted precedent |
| `0x004c7620-0x004c7668` | UID00048N | SimpleHelpPane2 pointer/mouse override | true | UID0000D7 | `86/90 -> 91/94` | Destination 4 |
| `0x004c7670-0x004c7680` | UID00048O | SimpleHelpPane2 key/text override | true | UID0000D7 | `88/91 -> 91/94` | Destination 5 |
| `0x004c6f90-0x004c7680` | UID00016S | non-emitting mixed-class split index | false | UID0000JU semantic | preserve `88/90` | Destination 9 prose only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061ac34` | data -> target | unique EventHandler pointer/mouse slot |
| `0x0061ac38` | data -> UID00048J | next EventHandler key/text slot |
| `0x0061ac64` | data -> UID00048H | TimerHandler callback slot |
| `0x004c7470`, `0x004c7486` | target -> `0x005975e0` | two schedule paths |
| target direct callers | none | virtual dispatch is table-based |
| `0x004c700f/19` | constructor -> secondary/tertiary table bases | class layout/liveness |
| `0x004c72c1/cb` | destructor -> secondary/tertiary table bases | class layout/liveness |
| `0x004ce598/a2` | scalar path -> secondary/tertiary table bases | class layout/liveness |
| `0x004a77d0` | EventDispatcher indirect call at secondary `+4` | pointer/mouse family dispatch |
| `0x005975e0` | 163 xrefs / 122 profiled callers | shared schedule service, not target-local helper |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback target documentation preserved the exact range, type-byte read, constants, returns, owner/emitter, and padding but mislabeled the method, argument type, enum scope, and timer operation. Validator `000000010586` applied the corrected `92/94`, position `50`, full evidence, history, and Destination 1 formal body.
- UID00016S/B007 material established the split and padding; its timer-cancel/source-name interpretation remains labeled historical. Current UID00016S is still `88/90`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal body, `Nested:0`, with its exact corrected child index applied by validator `000000010620`.
- Evidence-time UID00048H and UID00048J pages contained valid exact bytes/xrefs but contradictory source-facing names. Validators `000000010590` and `000000010595` applied TimerHandler `OnTimer(int,int,int)` and EventHandler `HandleKeyOrTextEvent(Event *)`, scores `91/94`, and positions `40/60`.
- UID00048M remains the accepted, unchanged same-family TimerHandler precedent. UID0001K8 remains consistent with schedule/remove separation and was re-read as a verify-only dependency.
- EventHandler declaration and dispatcher slot order remain sufficient and unchanged. The concrete pointer-payload drift is now resolved: validator `000000010606` applied y-first/x-second to UID00004L's formal declaration, and validator `000000010629` applied the same direct-evidence order to prose-only UID0000J6 without by-file reconstruction metadata.
- Validators `000000010599` and `000000010603` applied the homologous UID00048N/UID00048O EventHandler roles. Validators `000000010609`, `000000010615`, and `000000010627` synchronized the SimpleHelpPane, SimpleHelpPane2, and HelpPanes route pages while preserving their marker/children or prose-only roles.
- B002's waited command `000000010632` completed callback generation. Read-only verification against validator-owned headers from command `000000010669` observed the same result: `HelpPanes.cpp` has the five exact accepted child definitions once each and in position order, and `Event.cpp` has one y-first/x-second Event declaration with compiler-only artifacts still excluded from handwritten source.

## Ranked Ownership Analysis

### 1. UID0000D6 SimpleHelpPane through UID0000JU HelpPanes

- Evidence for: named SimpleHelpPane tables, unique target slot, constructor/destructor/scalar table installs, exact contiguous class child cluster, accepted generated route, and inherited EventHandler/TimerHandler layout.
- Evidence against: no original function symbol and no direct code caller.
- Decision: accepted direct semantic owner and emitter. Virtual dispatch explains the absence of direct code callers.

### 2. UID0000F0 TimerHandler / TimerMgr

- Evidence for: target invokes the TimerHandler schedule wrapper after transitioning to the adjacent base subobject.
- Evidence against: TimerHandler owns the service and callback interface, not this derived EventHandler override; target is not in the TimerHandler table.
- Decision: dependency only.

### 3. EventHandler / EventDispatcher

- Evidence for: defines the virtual slot contract and dispatches the target.
- Evidence against: base interface/dispatcher does not own concrete SimpleHelpPane behavior.
- Decision: declaration/dispatch dependency only.

### 4. UID00016S aggregate or free/raw HelpPanes helper

- Evidence for: physical containment in the aggregate and HelpPanes source family.
- Evidence against: exact child already exists with one class owner; aggregate spans two classes and padding; unique vtable slot disproves free-helper status.
- Decision: reject aggregate/free-helper emission. Keep UID00016S non-emitting.

### Proposed new file/grouping, if applicable

- Not applicable. No new UID, child, source file, or grouping is needed.

## Source Placement

- Recommended placement: derived methods in `NexusTK/ui/controls/HelpPanes.cpp`, declarations on `SimpleHelpPane`/`SimpleHelpPane2` in the HelpPanes class header route, using shared EventHandler/Event and TimerHandler declarations.
- Target body emits only from UID00048I under class UID0000D6. Class UID0000D6 and file UID0000JU retain marker/route roles; UID00016S retains index-only status.
- The TimerHandler schedule implementation remains in the TimerMgr/TimerHandler route. Event/EventHandler declarations remain in UI event infrastructure. UID0000J6 remains the `Event.cpp` source-file route and receives only synchronized y/x layout prose; it does not emit the declaration or carry by-file reconstruction metadata.
- Rejected placements: Event.cpp owns records/infrastructure, TimerMgr.cpp owns service implementation, Pane.cpp owns the close helper/base layout, and read-only-data pages own generated vtable evidence. None owns this derived method body.
- Remaining uncertainty: exact disk header split and original virtual spelling are not symbol-proven. Existing accepted interface names make this a confidence cap, not a C++ blocker.

## Range / Split / Padding / Reclassification Analysis

- Keep range `0x004c7450-0x004c7491` unchanged.
- Keep target `Nested:0`; it is an exact child, not an inner subrange.
- Keep predecessor/successor children separate. Do not absorb `0x004c7491-0x004c74a0` padding.
- Reclassify source role only: stale timer-event name -> EventHandler pointer/mouse override.
- UID00016S remains `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal body, and documents children/padding without emission.
- No new child, merge, range rename, or ignored-padding registration is needed.

## Negative Evidence Summary

- No target source symbol, PDB, source path string, RTTI method name, or direct caller exists.
- No call to owner-wide removal `0x00597600` or cancel wrappers `0x00597610/30` exists.
- No target branch calls `Close()` directly; dismissal is deferred through a scheduled zero-delay TimerHandler callback.
- No target branch reads coordinates or other payload fields; coordinate-layout correction is support synchronization for the homologous pointer handler, not invented target behavior.
- No target writes a local timer-active flag, clears a timer ID, or removes an existing queue record.
- No EH, allocation, free, null check, cleanup, vtable write, or compiler wrapper body is present.
- Nearby TimerHandler/EventHandler code proves interface relationships but does not move ownership away from SimpleHelpPane.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name: `SimpleHelpPane::HandlePointerOrMouseEvent`.
- Source-facing target type: `bool __thiscall SimpleHelpPane::HandlePointerOrMouseEvent(Event *event)`; source omits explicit calling convention.
- Source-facing target comment: pointer/mouse override that queues immediate timer id 0 on cursor move or either button-down, consumes button-down only, and does not remove pending timers.
- Historical aliases to retain in prose only: `SimpleHelpPaneOnTimerEvent`, `OnTimerEvent`, `PaneEvent`, local `kPaneEvent*`, and `CancelTimer`.
- Support source names: UID00048H `SimpleHelpPane::OnTimer`; UID00048J `SimpleHelpPane::HandleKeyOrTextEvent`; UID00048N `SimpleHelpPane2::HandlePointerOrMouseEvent`; UID00048O `SimpleHelpPane2::HandleKeyOrTextEvent`.
- Type correction: `EventPointerPayload::m_y` at `+0x08`, `m_x` at `+0x0c`; `m_type` remains unsigned byte at Event `+0x04`. Apply the formal field correction to UID00004L and synchronize the same offset order into prose-only UID0000J6.
- IDA database edits are not requested and were prohibited for this pass. Raw IDA names remain evidence labels.

## First-Draft C++ Recommendation

- Applied draft C++ status: all six source-emitting managed blocks below were installed exactly and clear owner/emitter/range/dependency/behavior blockers. Destinations 7-11 retain their accepted non-duplicating marker/index/prose roles.
- Third-party import directive: not applicable.

### Destination 1 - UID00048I target

Target: `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SimpleHelpPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonDown ||
        event->m_type == kEventRightButtonDown)
    {
        ScheduleTimer(0, 0, 0, 0);
        return true;
    }

    if (event->m_type == kEventCursorMove)
        ScheduleTimer(0, 0, 0, 0);

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID00048H SimpleHelpPane timer callback

Target: `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md`; stable slug is historical.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SimpleHelpPane::OnTimer(int, int, int)
{
    Close();
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID00048J SimpleHelpPane key/text handler

Target: `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md`; stable slug is historical.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SimpleHelpPane::HandleKeyOrTextEvent(Event *)
{
    Close();
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID00048N SimpleHelpPane2 pointer/mouse handler

Target: `by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md`; stable slug is historical.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SimpleHelpPane2::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonDown ||
        event->m_type == kEventRightButtonDown ||
        (event->m_type == kEventCursorMove &&
         !PointInRect(event->m_payload.m_pointer.m_y,
                      event->m_payload.m_pointer.m_x,
                      &m_anchorRect)))
    {
        ScheduleTimer(0, 0, 0, 0);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID00048O SimpleHelpPane2 key/text handler

Target: `by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md`; stable slug is historical.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SimpleHelpPane2::HandleKeyOrTextEvent(Event *)
{
    Close();
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID00004L Event declaration dependency

Target: `by-class/Event.md`; complete current block retained with the pointer payload field order corrected to y then x.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum EventType
{
    kEventCursorMove = 0,
    kEventLeftButtonDown = 1,
    kEventLeftButtonDoubleClick = 2,
    kEventLeftButtonUp = 3,
    kEventRightButtonDown = 4,
    kEventRightButtonDoubleClick = 5,
    kEventRightButtonUp = 6,
    kEventMouseWheel = 7,
    kEventKeyDown = 8,
    kEventKeyUp = 9,
    kEventTextInput = 10,
    kEventImeOpenStatus = 11,
    kEventImeCompositionStart = 12,
    kEventImeCompositionResult = 13,
    kEventImeCompositionEnd = 14,
    kEventImeCandidateList = 15,
    kEventImeCandidateClose = 16,
    kEventImeReserved = 17,
    kEventPacket = 18,
    kEventApplicationNotification = 19,
    kEventDispatchSuppressed = 20,
    kEventSystemControl = 21,
    kEventWorkNotification = 22,
    kEventNone = 0xff
};

struct EventPointerPayload
{
    int m_y;
    int m_x;
    unsigned char m_modifiers;
    unsigned char m_padding[3];
    int m_detail;
    unsigned int m_messageTime;
};

struct EventKeyPayload
{
    unsigned char m_key;
    unsigned char m_reserved;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned char m_padding;
    unsigned int m_messageTime;
};

struct EventTextPayload
{
    unsigned short m_inputCode;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned char m_padding;
    unsigned int m_messageTime;
};

struct EventCompositionPayload
{
    unsigned char m_subtype;
    unsigned char m_length;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned char m_padding;
    unsigned int m_messageTime;
};

struct EventImeResultPayload
{
    unsigned char m_reserved;
    unsigned char m_length;
    wchar_t m_text[129];
    unsigned int m_messageTime;
};

struct EventImeOpenPayload
{
    int m_isOpen;
    unsigned char m_reserved[0x100];
    unsigned int m_messageTime;
};

struct EventCandidatePayload
{
    void *m_candidateList;
    int m_selectedRow;
    unsigned char m_reserved[0xfc];
    unsigned int m_messageTime;
};

struct EventPacketPayload
{
    unsigned char m_packetKind;
    unsigned char m_padding[3];
    void *m_data;
    unsigned int m_size;
};

struct EventNotificationPayload
{
    unsigned int m_channel;
    LObject *m_payload;
};

union EventPayload
{
    EventPointerPayload m_pointer;
    EventKeyPayload m_key;
    EventTextPayload m_text;
    EventCompositionPayload m_composition;
    EventImeResultPayload m_imeResult;
    EventImeOpenPayload m_imeOpen;
    EventCandidatePayload m_candidate;
    EventPacketPayload m_packet;
    EventNotificationPayload m_notification;
    unsigned char m_raw[0x108];
};

class Event : public LObject
{
public:
    Event();
    virtual ~Event();

    bool IsPointerEvent() const;
    bool IsKeyOrTextEvent() const;
    bool IsImeEvent() const;
    bool IsPacketEvent() const;
    bool IsSystemOrControlEvent() const;

    unsigned char m_type;
    EventPayload m_payload;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior/source-shape audit:

- Destination 1 preserves branch ordering and return behavior exactly. Short-circuiting combines the two button-down cases but does not change calls or returns.
- Destination 4 preserves the binary's `1`, `4`, and `0 outside bounds` schedule cases, always-false return, y/x helper convention, and no removal.
- `ScheduleTimer` is declared by the accepted TimerHandler support. Event enum/type/member names are declared by Destination 6. `PointInRect(int y,int x,const RectBounds *)` and `m_anchorRect` are accepted support declarations.
- Destination 11 has no managed C++ block. `by-file/Event.md` is a prose/source-route index under the current by-file policy; UID00004L Destination 6 alone emits the corrected Event declaration.
- No source block emits explicit base-pointer adjustment, vtable slots, scalar wrappers, raw addresses, or timer-manager internals.

## Final Recommendation

- Destination 1 and target metadata `92/94`, retained owner/emitter/Nested, and position `50` are applied and validated.
- Destinations 2-5 are applied and validated; their stable filenames remain historical slugs while source-facing handler names and timer-operation prose are corrected.
- Destination 6's y/x payload correction is applied without changing Event ownership, emitter, reconstructable state, score, or unrelated declaration detail.
- Destinations 7-10 are synchronized and validated without duplicate source: SimpleHelpPane and SimpleHelpPane2 retain marker/children route blocks, UID00016S remains non-emitting, and HelpPanes remains prose-only.
- Prose-only Destination 11 is applied and validated at preserved `91/92`; it carries the corrected payload order and superseded history, with no by-file reconstruction metadata or body.
- EventHandler, TimerHandler/UID0001K8, constructor/destructor/paint pages, RectBounds, and vtable/read-only-data pages were re-read and remained verify-only because no concrete drift appeared outside the accepted destinations.
- No source was added to UID00016S, class route pages, by-file pages, ABI wrappers, or vtable data. No accepted item remains unapplied or blocked.

## Recommended Target Doc Changes

Target: `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md`.

- Applied by validator `000000010586`: score `92/94`; preserved `CANONICAL_OWNER:0000D6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D6`, and `Nested:0`; position `50`.
- Destination 1 is installed byte-for-byte.
- Source-facing title/summary/scope now use `SimpleHelpPane::HandlePointerOrMouseEvent`; the stable path and old name remain explicitly historical/superseded.
- Exact range, size, bytes/hash, instructions, CFG, ABI, xrefs, unique VA pointer/no RVA pointer, vtable/RTTI/base offsets, table installation, dispatcher slot, event field/type, branch matrix, wrapper/manager arguments, no-removal proof, negative evidence, ownership/source placement, rejected alternatives, and score rationale are present at report-level detail.
- Every valid historical fact is preserved; `PaneEvent`, local `kPaneEvent*`, `OnTimerEvent`, and `CancelTimer` are labeled rejected/superseded.

## Recommended Support Doc Changes

### Destination 2 - UID00048H

- Applied by validator `000000010590`: Destination 2, score `91/94`, retained owner/emitter/reconstructable/Nested, and position `40`.
- Exact bytes/xrefs now support TimerHandler `OnTimer(int,int,int)`; the historical `OnMouseDown` slug/signature is superseded.

### Destination 3 - UID00048J

- Applied by validator `000000010595`: Destination 3, score `91/94`, retained owner/emitter/reconstructable/Nested, and position `60`.
- Exact bytes/xrefs now support the EventHandler key/text family; the historical `OnKeyPress` slug/signature is superseded.

### Destination 4 - UID00048N

- Applied by validator `000000010599`: Destination 4, score `91/94`, retained owner/emitter/reconstructable/Nested, and position `40`.
- Exact EventHandler pointer/mouse naming, y/x payload, and schedule behavior replace the historical generic `HandleEvent`, local enum, x/y inversion, and `CancelTimer`; exact range/CFG/anchor logic is preserved.

### Destination 5 - UID00048O

- Applied by validator `000000010603`: Destination 5, score `91/94`, retained owner/emitter/reconstructable/Nested, and position `50`.
- EventHandler key/text-family role replaces historical `OnCancel(PaneEvent)`; the exact close/false body and historical slug are preserved.

### Destination 6 - UID00004L Event

- Applied exactly by validator `000000010606`. `92/93`, owner/emitter/position, lifecycle, enum, union size, all other field declarations, child route, and history are preserved.
- Pointer payload declaration/prose now place y at `+0x08` and x at `+0x0c`; the historical x-first declaration is superseded.

### Destination 7 - UID0000D6 SimpleHelpPane

- Validator `000000010609` preserved metadata and the existing marker/`[[CHILDREN]]` formal block.
- Method inventory/prose now records UID00048H/I/J as TimerHandler OnTimer, EventHandler pointer/mouse, and EventHandler key/text; base offsets, schedule/no-remove distinction, event constants, stable-slug history, and direct source placement are synchronized.

### Destination 8 - UID0000D7 SimpleHelpPane2

- Validator `000000010615` preserved metadata and the existing marker/`[[CHILDREN]]` formal block.
- UID00048N/O inventory/prose now carries the corrected EventHandler roles and schedule operation; UID00048M's accepted OnTimer correction and all factory/layout evidence are preserved.

### Destination 9 - UID00016S aggregate

- Validator `000000010620` preserved `88/90`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal body, and `Nested:0`.
- Exact child inventory, vtable roles, timer schedule/remove distinction, Event type names, y/x payload, historical aliases, and parent no-code proof are synchronized without duplicate child source.

### Destination 10 - UID0000JU HelpPanes file

- Validator `000000010627` preserved metadata and the by-file no-reconstruction-metadata rule.
- Method family/source placement, event/timer dependencies, stable-slug history, and child emission route are synchronized; no by-file formal child body was added.

### Destination 11 - UID0000J6 Event file

- Applied by validator `000000010629` as bounded prose-only support synchronization. `COMPLETION:91`, `CONFIDENCE:92`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"`, `CANONICAL_OWNER:FILE`, all unrelated Event/EventMan source-family detail, and the by-file prohibition on `RECONSTRUCTION_CPP` metadata or formal bodies are preserved.
- The exact source-facing text is now present: `Pointer/mouse records use y at +0x08, x at +0x0c, modifiers at +0x10, detail at +0x14, and message time at +0x18.`
- Direct support is recorded at report-level detail: EventMan pointer producers place y at `+0x08` and x at `+0x0c`; UID00048N passes the `+0x08` value before the `+0x0c` value to accepted `PointInRect(int y, int x, const RectBounds *)`; and Destination 6 uses the same order in the source-emitting Event declaration.
- Confidence is high because producer writes, consumer argument order, and the accepted project point ABI converge. Exact original field spellings remain a lexical confidence cap only.
- Preserve the former `x at +0x08` / `y at +0x0c` statement as an explicitly historical, superseded assumption rather than silently deleting its provenance. Do not add a formal block, duplicate Event declaration, or by-file reconstruction metadata.

### Read-only comparison contracts

- UID00048E/K constructors: preserve bodies/scores; record only that their direct `0x005975e0` calls schedule timer id `0` with caller delay and zero payload if existing prose needs exact wording during reread.
- UID00048M: already accepted OnTimer; no edit unless concrete drift.
- UID00004N EventHandler: accepted interface names/order already match; verify-only.
- UID0000F0 TimerHandler and UID0001K8: accepted schedule/remove declarations already match; verify-only.
- RectBounds/UID00015S: accepted `PointInRect(y,x,bounds)` already matches; verify-only.
- UID00025G vtable data and compiler wrappers: evidence only; no handwritten table/wrapper source.

## Score And Metadata Recommendation

| Page | Pre-callback | Applied | Metadata disposition |
| --- | ---: | ---: | --- |
| UID00048I | `86/90` | `92/94` | owner/emitter/true/Nested retained; position `50`; validator `000000010586` |
| UID00048H | `88/92` | `91/94` | owner/emitter/true/Nested retained; position `40`; validator `000000010590` |
| UID00048J | `88/92` | `91/94` | owner/emitter/true/Nested retained; position `60`; validator `000000010595` |
| UID00048N | `86/90` | `91/94` | owner/emitter/true/Nested retained; position `40`; validator `000000010599` |
| UID00048O | `88/91` | `91/94` | owner/emitter/true/Nested retained; position `50`; validator `000000010603` |
| UID00004L | `92/93` | preserve | formal field order/prose only |
| UID0000J6 | `91/92` | preserve | prose-only pointer payload order; no by-file formal metadata/body |
| UID0000D6/0000D7/00016S/0000JU | preserve | preserve | prose/inventory only |

Manual coverage completion/status consistency is exact: UID00016S uses `not_reconstructable : 88%`; UID00004L uses `reconstructable : 92%`; UID0000D6 uses `reconstructable : 86%`; UID0000D7 uses `reconstructable : 88%`; UID0000J6 uses `reconstructable : 91%`; and UID0000JU retains `reconstructable : 90%`.

Score-improvement attempt for target:

- Range/boundaries: resolved exactly through lookup/bytes/CFG.
- Liveness: resolved as unique vtable-installed virtual, not direct-call dependent.
- Signature/interface: resolved through EventDispatcher and secondary table.
- Event names/type/member: resolved through accepted Event/EventHandler declarations and producers.
- Timer operation/arguments: resolved through wrapper and manager schedule body; cancellation rejected.
- Owner/emitter/source placement: resolved through class tables/lifecycle and current generator route.
- Formal C++ dependencies: resolved; complete exact block supplied.
- Remaining cap: no original source symbol/PDB and exact historical header split. These do not affect behavior or compilation and justify `92/94`, not `95+`.

## Open Questions With Attempted Resolution

- Is the target a timer callback? Resolved no: wrong table and wrong ABI; UID00048H is the timer callback.
- Is the event type `PaneEvent`? Resolved to accepted shared `Event *`; dispatcher and EventHandler use that record.
- Are values `0/1/4` local target enums? Resolved to global pointer-event constants.
- Does zero delay mean cancel? Resolved no: manager inserts a due-now record; removal has a separate wrapper.
- Is existing pending timer state removed first? Resolved no: no removal/cancel call exists in any branch.
- Why does target add four to `this`? Resolved as transition from EventHandler subobject `+0xa0` to TimerHandler `+0xa4`; source uses inherited method syntax.
- What are handled semantics? Resolved: dispatcher propagates the virtual's bool; button down returns handled, cursor move schedules close but returns not handled.
- What happens on double-click/up/wheel? Resolved: no schedule and false.
- Is pointer payload x-first? Resolved no for the current project source model: accepted point ABI and current producers/consumers establish y at `+8`, x at `+c`. UID00004L formal declaration and UID0000J6 prose-only file route now carry the same order; the former reversed order remains labeled historical.
- Exact original virtual spelling/header file remains unprovable after RTTI/name/string/source-tree/report searches. It is a confidence cap only; accepted interface names provide a defensible source draft.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Inspected manual rows:

- `by-memory/-coverage-report.md`: UID00016S row present; no separate UID00048H/I/J/N/O child rows.
- `by-class/-coverage-report.md`: UID00004L, UID00004N, UID0000D6, UID0000D7 rows present.
- `by-file/-coverage-report.md`: UID0000J6 and UID0000JU rows present.
- `by-memory/-coverage-report.md`: UID0001K8 row present and current; no replacement needed.

No child-row additions are proposed because the current manual by-memory report represents this region through its enclosing UID00016S aggregate row; generated by-memory coverage represents exact children and is validator-owned. Exact supervisor-owned replacements for stale affected rows follow. The UID0000J6 replacement already carries the corrected pointer y/x order and is the manual-coverage counterpart to prose-only Destination 11; its `91%` completion remains unchanged.

File/placement: replace the existing UID00016S line in `by-memory/-coverage-report.md`:

```markdown
    - [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) 0x004c6f90-0x004c7680 | class-method-cluster | SimpleHelpPanes : not_reconstructable : 88% : strong : Non-emitting HelpPanes split index over exact SimpleHelpPane and SimpleHelpPane2 constructors, teardown, paint, TimerHandler callbacks, EventHandler pointer/mouse and key/text overrides, singleton/vtable routes, y-first/x-second event payload semantics, schedule-versus-remove behavior, anchor logic, and internal padding; exact child pages alone emit source.
```

File/placement: replace UID0000D6 in `by-class/-coverage-report.md`:

```markdown
- [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md) : reconstructable : 86% : strong : HelpPanes-owned timed text tooltip with exact constructor/destructor/paint children, TimerHandler OnTimer callback, EventHandler pointer/mouse and key/text overrides, singleton/vtable/base-offset evidence, zero-delay schedule behavior, copied-text ownership, compiler-wrapper separation, and child-only source emission documented.
```

File/placement: replace UID0000D7 in `by-class/-coverage-report.md`:

```markdown
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md) : reconstructable : 88% : strong : HelpPanes-owned anchored tooltip with exact constructor/teardown, accepted TimerHandler OnTimer callback, corrected EventHandler pointer/mouse and key/text overrides, y/x anchor hit testing, schedule behavior, scalar-wrapper/vtable triplet, singleton, and factory/helper relationships documented; direct constructor xrefs and final private names remain confidence caps.
```

File/placement: replace UID00004L in `by-class/-coverage-report.md`:

```markdown
- [UID:00004L][Event](by-class/Event.md) : reconstructable : 92% : strong : Event.cpp-owned event record with exact lifecycle/vtable boundaries, accepted type enum and 0x110 union layout, unsigned type byte at +0x04, corrected pointer payload y at +0x08 and x at +0x0c, producer/dispatcher evidence, scalar-wrapper separation, and source-emitting declaration documented.
```

File/placement: replace UID0000J6 in `by-file/-coverage-report.md`:

```markdown
- [UID:0000J6][Event](by-file/Event.md) : reconstructable : 91% : strong : `NexusTK/ui/core/Event.cpp` event object/factory module with exact Event lifecycle, Event/EventMan vtable boundaries, accepted event families and payload union, corrected pointer y/x field order, EventMan/IME/packet/notification producers, and InputMan/EventDispatcher separation documented.
```

File/placement: replace UID0000JU in `by-file/-coverage-report.md`:

```markdown
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md) : reconstructable : 90% : strong : `NexusTK/ui/controls/HelpPanes.cpp` tooltip/help-pane family with exact child-only SimpleHelpPane/SimpleHelpPane2 source emission, TimerHandler callbacks, EventHandler pointer/mouse and key/text overrides, schedule/remove distinction, y/x anchor behavior, text parts, item/change previews, singleton helpers, factories, compiler-support separation, and broad cross-references documented.
```

Reason B002 must not apply coverage text: manual coverage is supervisor-owned; generated coverage/tracker files are validator-owned. This report supplies exact replacement text only.

## Follow-Up Actions

- B002's accepted implementation work, eleven scoped destination validations, waited generated verification, readback audit, report update, and lease releases are complete.
- Generated/readback proof confirms exactly one UID00048H/I/J and UID00048N/O definition in `HelpPanes.cpp`, target order consistent with positions, no UID00048I Empty Emitter Marker, no stale `OnTimerEvent`/`CancelTimer` target body, one corrected y-first/x-second Event declaration in `Event.cpp`, no handwritten scalar-thunk/vtable ABI, and corrected y-first/x-second prose with no managed reconstruction metadata on `by-file/Event.md`.
- No accepted callback item remains unapplied. Current or future report count, validation-gate result, execution, move, archive, and lifecycle state are external validator/supervisor-owned and are not asserted here.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: high for `92/94`; lower than final/PDB certainty only for original spelling and header split.
- Runtime behavior confidence: very high; every instruction and branch is represented.
- Ownership/source placement confidence: very high; table/lifecycle/generator evidence converges.

## Validator Results

- Scoped command form for Destinations 1-11: `python .\tools\validator.py --mode file --file '<project-relative-page>' --apply`. Each command exited `0` with `ok: 1`; generated refresh was deferred until the final waited command.

| Destination | Page | Command ID | Command timestamp | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- | --- |
| 1 | `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md` | `000000010586` | `2026-07-14T03:17:24-04:00` | `0 / 1` | Completion/confidence/position/formal hash and references updated; projected stats refreshed; generated refresh deferred. |
| 2 | `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md` | `000000010590` | `2026-07-14T03:18:23-04:00` | `0 / 1` | Accepted metadata/formal/prose update; generated refresh deferred; no target-specific warning. |
| 3 | `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md` | `000000010595` | `2026-07-14T03:19:34-04:00` | `0 / 1` | Accepted metadata/formal/prose update; generated refresh deferred; no target-specific warning. |
| 4 | `by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md` | `000000010599` | `2026-07-14T03:20:50-04:00` | `0 / 1` | Accepted metadata/formal/prose update and UID00004L/UID00004N references; generated refresh deferred. |
| 5 | `by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md` | `000000010603` | `2026-07-14T03:21:51-04:00` | `0 / 1` | Accepted metadata/formal/prose update; generated refresh deferred; no target-specific warning. |
| 6 | `by-class/Event.md` | `000000010606` | `2026-07-14T03:22:29-04:00` | `0 / 1` | Accepted formal/prose y/x synchronization; generated refresh deferred; no target-specific warning. |
| 7 | `by-class/SimpleHelpPane.md` | `000000010609` | `2026-07-14T03:23:30-04:00` | `0 / 1` | Route/prose update; four pre-existing `missing_ref_uid 0003YZ` warnings; generated refresh deferred. |
| 8 | `by-class/SimpleHelpPane2.md` | `000000010615` | `2026-07-14T03:24:34-04:00` | `0 / 1` | Route/prose update; five pre-existing `missing_ref_uid 0003YY` warnings; generated refresh deferred. |
| 9 | `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md` | `000000010620` | `2026-07-14T03:25:48-04:00` | `0 / 1` | Non-emitting index/prose update; generated refresh deferred; no target-specific warning. |
| 10 | `by-file/HelpPanes.md` | `000000010627` | `2026-07-14T03:28:10-04:00` | `0 / 1` | Prose-only route update; 80 pre-existing `missing_ref_uid` warnings (10 listed, 70 suppressed); generated refresh deferred. |
| 11 | `by-file/Event.md` | `000000010629` | `2026-07-14T03:28:58-04:00` | `0 / 1` | Prose-only y/x update and UID00048N reference; two pre-existing `missing_ref_uid 0003LV` warnings; generated refresh deferred. |

- Final authorized command: `python .\tools\validator.py --mode file --file 'by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md' --apply --wait-generated --queue-timeout 240`; command ID `000000010632`, timestamp `2026-07-14T03:29:22-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Final command side effects were validator-owned: `autogen_children_fallback_insert:15`, `autogen_children_marker_missing:83`, `autogen_cpp_update:1` (unrelated `SelfLookPane`), `autogen_emitter_has_no_code:198`, `autogen_registry_rebuild:1` (`tools/validator.ini`, 4742 nodes/3841 edges), `autogen_report_update:2`, `generated_metadata_refresh:277`, `projected_stats:1`, and `research_tracker:1`. B002 did not edit those outputs manually.
- B002 waited-result readback: `HelpPanes.cpp` had one marker and one definition for each UID00048H/I/J/N/O in position order `40/50/60` and `40/50`; UID00048I Empty Emitter Marker count `0`; stale `SimpleHelpPane::OnTimerEvent` count `0`; `CancelTimer(` count `0`. `Event.cpp` had one `EventPointerPayload`, one `Event` class, one `m_y` before one `m_x`, no raw vtable array, and compiler scalar/vtable comments only.
- A later validator-owned refresh set both generated headers to command `000000010669` at `2026-07-14T03:45:18-04:00`. Read-only recheck at that observation found all preceding counts unchanged. `by-file/HelpPanes.md` and `by-file/Event.md` each have zero managed `RECONSTRUCTION_CPP` header lines.
- All warnings are pre-existing support-reference warnings and no target-specific validator error remains.
- Final read-only report/artifact audit: all 21 mandatory `##` headings present; 30 ledger rows; zero invalid Action values; zero invalid final Verification states; zero unchecked boxes; six report managed blocks, each byte-for-byte synchronized with Destinations 1-6; all eleven destination score and applicable position/reconstructable checks matched; exact Destination 11 sentence present; no B002 lease present.

## Changed Files

- Report artifact updated in place: `tools/leaser/Agents/Agent-B002/research/00048I-SimpleHelpPaneOnTimerEvent-source-quality.md`.
- Destination 1: `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md`.
- Destination 2: `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md`.
- Destination 3: `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md`.
- Destination 4: `by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md`.
- Destination 5: `by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md`.
- Destination 6: `by-class/Event.md`.
- Destination 7: `by-class/SimpleHelpPane.md`.
- Destination 8: `by-class/SimpleHelpPane2.md`.
- Destination 9: `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`.
- Destination 10: `by-file/HelpPanes.md`.
- Destination 11: `by-file/Event.md`, prose-only, preserved `91/92`, no managed reconstruction metadata/body.
- Renamed/created ordinary pages: none. Read-only comparison contracts: unchanged. Manual coverage and validator/generated/tracker/audit/supervisor/lifecycle/IDA files: not manually edited.
- Lease proof: each destination above was leased only immediately before its edit, re-read, validated, and released before the next lease. Current lease report contains no B002 entry; all eleven B002 leases are released.
- Report execution: not run. No execute-report, probe, lifecycle, move, or archive command was run.

## Implementation Tracking Checklist

Initial report-only and Gate 1 foundation:

- [x] Exact artifact passed supervisor Gate 1 before implementation.
- [x] Initial ledger audit confirmed every C01-C30 Action used only `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, or `not-applicable`, with report-only states `proposed`; callback states are now updated legally.
- [x] Authorized destination scope was Destinations 1-11 only; Destination 11 remained prose-only `by-file/Event.md` at `91/92` without a formal reconstruction block; read-only contracts had no concrete drift.
- [x] Evidence-time and applied current target state plus actual evidence checked are recorded distinctly.
- [x] Claim And Incorporation Ledger retains one atomic row for each C01-C30 with destination and final proof.
- [x] Applied scores are UID00048I `92/94` and UID00048H/J/N/O `91/94` with listed positions; all other scores are preserved.
- [x] Score-limiting blockers were resolved through live MCP or explicitly capped only by absent original symbols.
- [x] Owner/emitter/reconstructable state is retained exactly; UID00016S remains non-emitting.
- [x] Stable paths are retained; no split/new child/UID/rename operation was required.
- [x] Source placement, range, padding, reclassification, and IDA-name directions are recorded.
- [x] Six complete destination-specific managed formal C++ blocks are supplied and installed.
- [x] Third-party import directive is not applicable.
- [x] Target/support facts are preserved at report-level detail, including Destination 11's corrected y/x offsets, producer/consumer/point-ABI support, confidence ranking, reversed-order history, and prose-only source-route policy.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Wave2/Wave3 material was encountered only as stale history and rejected as authority.
- [x] Open questions are closed or reduced to explicit no-symbol confidence caps.
- [x] Exact six-row supervisor-owned manual coverage replacement text matches metadata: UID00016S `not_reconstructable/88%`; UID00004L `reconstructable/92%`; UID0000D6 `reconstructable/86%`; UID0000D7 `reconstructable/88%`; UID0000J6 `reconstructable/91%`; UID0000JU `reconstructable/90%`.

Implementation callback pass:

- [x] Report was accepted by supervisor for implementation at SHA256 `FD8D35D69F5D47827C8EDF54E7EE870CDC873724AE1BB623CE68837DD0CF7C93`.
- [x] Every destination was re-read and same-or-greater unrelated detail preserved before editing.
- [x] Only one ordinary page was leased at a time and each lease was released after its scoped validator.
- [x] Destination 1 target metadata/body/prose was applied exactly.
- [x] Destinations 2-5 support handler corrections were applied exactly.
- [x] Destination 6 Event y/x declaration/prose correction was applied exactly.
- [x] Destinations 7-10 route/index/file prose was synchronized without duplicate formal bodies or by-file reconstruction metadata.
- [x] Destination 11 `by-file/Event.md` now states y at `+0x08` and x at `+0x0c`, records direct evidence/confidence/history, preserves `91/92`, and has no managed `RECONSTRUCTION_CPP` metadata/body.
- [x] Read-only contracts were verified and left unchanged because no concrete drift was found.
- [x] C01-C30 ledger uses allowed Actions and final states `applied`, `already-present`, or `excluded-with-reason`, with separate destination proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] One scoped validator per changed ordinary page, including Destination 11, passed and is recorded.
- [x] Final authorized waited command `000000010632` completed; exact counts/order/absence and newer-header readback are recorded.
- [x] Manual coverage remained unedited by B002; generated/tracker/validator state changed only through authorized validator side effects.
- [x] Every B002 lease is released; the current lease report has no B002 entry.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000010704","destination_path":"executed-b-agent-research/B002/00048I-SimpleHelpPaneOnTimerEvent-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00048I-SimpleHelpPaneOnTimerEvent-source-quality.md","timestamp":"2026-07-14T04:09:45-04:00","uid":"00048I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
