** TARGET-REPORT-UID:0002Q3 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0002Q3 NewUserDialogPane Core And Packet Helpers Source-Quality Research

## Finalized Report / Current Recommendation

- Applied split and bounded-repair state: [UID:0002Q3] `by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md` is a `92/94` reviewed non-emitting split index. It retains canonical semantic owner [UID:0000LV] `NewUserDialogPane`, has `RECONSTRUCTABLE:FALSE`, blank emitter/position and managed C++ body, and retains `Nested:4` as the address-order relative delta. Supervisor Gate 2 rejected the first callback's UID0004PD source contract and UID0004PI conversion shape; the authorized bounded callback has now applied both corrections, synchronized the listed reverse-link/detail destinations, passed scoped validators `000000011674` through `000000011690`, and passed waited generated refresh `000000011691` without changing any accepted score, owner, emitter, range, position, nesting, source route, or compiler/data disposition.
- Final disposition: thirteen exact children were serially registered before cross-references: source children UID0004PB/PD/PE/PF/PG/PH/PI/PO and compiler/data children UID0004PC/PK/PL/PM/PP. Eight target-range and two lifecycle-range padding spans are recorded in `by-memory/-ignored.md`, not in aggregate C++.
- Source route: class members emit through [UID:00009D] `NewUserDialogPane`; file-local `SendCreateAccountRequest` emits directly through [UID:0000LV]. The class and file are `92/94` and `91/92`. Generated placement is standalone `NexusTK/login/NewUserDialogPane.cpp`, not `LoginDialogPane.cpp` and not a synthetic aggregate source file.
- Source/no-code distinction: constructor, EventHandler packet virtual, command handler, button-state updater, submit method, request helper, reply method, and ordinary destructor semantics receive complete managed C++. The raw cleanup island, constructor-unwind singleton clear helper, adjustor thunks, reply switch table, vtable data, and split parent remain blank compiler/data artifacts. UID0004PD now overrides `HandlePacketEvent(Event *)` and reads `Event::m_payload.m_packet.m_data`; UID0004PI now preserves the directly evidenced `char[256]`/`wchar_t[256]` conversion instead of the rejected `SimpleUString` abstraction.
- Confidence: very strong for boundaries, bytes, control flow, packet format, vtable routes, singleton lifecycle, source/class ownership, and compiler-support disposition; strong but capped below final-audit certainty for original symbol spellings and the absent direct constructor route.

## Supporting Research

- Mandatory MCP evidence was collected against NexusTK IDB database `3fc1dcef`. Before the interruption, evidence-time health at `2026-07-14T12:46:56-04:00` was `ok`; after the supervisor-restored listener, a fresh transport session called `idb_list` first at `2026-07-14T13:01:02-04:00`, returned only active worker/database `3fc1dcef` (worker PID `16564` at that evidence time), and `server_health` at `2026-07-14T13:01:15-04:00` again reported `ok`, imagebase `0x400000`, and analysis, Hex-Rays, and string cache ready.
- The post-resume evidence pass repeated target lookup, aggregate bytes/hash, raw-cleanup non-function status, lifecycle helper/thunk/destructor lookup, exact vtable bytes/hash, and xref sets. It reproduced aggregate SHA256 `4ada69a186599faa63c50a34ca27318830f19baf0ecb466a4bf6557bd0967d31`, support hashes, zero constructor/raw-island xrefs, the three vtable routes, and the five singleton references. No inference below depends only on evidence gathered while the listener was absent.
- During the callback, the earlier worker became unavailable and the supervisor supplied replacement database `9df6e9a0`. A fresh transport/session schema check and bounded read at evidence time `2026-07-14T13:34:24-04:00` returned target bytes `55 8b ec 6a ff 68 1b 17 60 00 64 a1 00 00 00 00` at `0x004f9d30`, after `idb_list` and `server_health` identified the replacement NexusTK worker as healthy with analysis, Hex-Rays, and strings ready at that verification time. The first bounded call used the stale prior `get_bytes` schema and returned an invalid-parameters `regions` requirement; refreshing the schema and repeating the call succeeded, so this was a client-schema mismatch rather than an MCP outage. No new binary uncertainty was introduced by callback edits.
- Fresh Gate 2 repair evidence used a new streamable transport session and `idb_list` at `2026-07-14T14:07:36-04:00`, which returned the sole active NexusTK worker/database `9df6e9a0`. `server_health` reported `ok`, imagebase `0x400000`, and analysis, Hex-Rays, and strings ready. Bounded `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, and `xrefs_to` calls for `0x004fa0f0`, `0x004fa5b0`, and sibling `0x004fab10` all succeeded. No result from a missing worker or interrupted session was used.
- Historical callback interruption and recovery: after UID0004PD had been moved, corrected, scoped-validated, and its lease released, the supervisor reported database `9df6e9a0` unreachable and paused B004. B004 made no further file or validator change during that pause. On resume, a fresh streamable transport session called `idb_list` at evidence time `2026-07-14T14:33:39-04:00` and discovered sole active NexusTK database `6b2e78f3`; `server_health` at `2026-07-14T14:34:16-04:00` reported `ok`, imagebase `0x400000`, and analysis, Hex-Rays, and strings ready. Fresh bounded `lookup_funcs` and `get_bytes` for `0x004fa0f0`, `0x004fa5b0`, and sibling `0x004fab10`, plus decompilation of both affected target functions, succeeded and reproduced the accepted Event `+0x0c`, receiver-adjustment, fixed-buffer, direct-conversion, and low-byte-terminator facts. No fallback-only evidence was used.
- Documentation read directly during research and reread/rebased during callback where edited: UID0002Q3 target; [UID:00009D] `by-class/NewUserDialogPane.md`; [UID:0000LV] `by-file/NewUserDialogPane.md`; [UID:0000KX] `by-file/LoginDialogPane.md`; [UID:00019I] `MainMenuLoginAndAccountDialogs`; [UID:00025Q] `MainMenuNewUserReadOnlyData`; [UID:00029H] `MainMenuAccountDialogSingletons`; [UID:0002X9] `g_pNewUserDialogPane`; [UID:00028Q] `g_pConfig`; DialogPane, Pane, TextEditControlPane, EPFImageControlPane, ImageButtonControlPane, AlertPane, ScreenDimmer, PacketBuffer, QueueAndSendPacket, MainUiLayerSlots, and global support pages. The Gate 2 repair additionally reread current `by-class/Event.md`, `by-class/EventHandler.md`, `by-file/Event.md`, `by-class/DialogPane.md`, `by-class/LoginDialogPane.md`, [UID:0004PQ] `LoginDialogPaneHandlePacketEvent`, UID0004PD, UID0004PI, and all current NewUser reverse-link destinations.
- Historical pre-callback generated evidence: at validator command `000000011542`, refreshed `2026-07-14T12:40:05-04:00`, read-only SHA256 `7D5170E2CBEB2E5999C97CCB4C1E6E9D4CC3E5C348727C233338C90CD32DFA2A`, `NewUserDialogPane.cpp` contained one UID0002X9 singleton declaration plus UID00009D and UID0002Q3 Empty Emitter Markers. B004 waited command `000000011608` refreshed the same path to SHA256 `C89E20028DE414DF1962CAF2869A3F58F8547B742A9FFEE2045B04B0F1517661`, with one class, one each of eight source definitions, and zero parent/class/false-child Empty Emitter Markers. A later concurrent external refresh changed only generated metadata: read-only header command `000000011617`, refresh `2026-07-14T13:42:34-04:00`, file read time `2026-07-14T13:42:47-04:00`, size `9145`, SHA256 `15984E68A6460E531846C22722824C9B3BFE1F7CCD57B527AF8B5C79FA9FF42C`; all structural source counts remained identical. Those snapshots are historical structural proof only: they still contain rejected `OnCreateUserReplyEvent(const PacketEvent *)` and `SimpleUString::FromMbcString` source and therefore do not prove the corrected semantics.
- Prior-report search terms were: `UID0002Q3`, `0x004f9d30`, `0x004fa7a0`, `NewUserDialogPaneCoreAndPacketHelpers`, `SendCreateAccountRequest`, `HandleCreateUserReply`, `OnCreateUserReplyEvent`, `UID0000LV`, `UID00009D`, `g_pNewUserDialogPane`, `0x0069b480`, `NewUserDialogPane`, `LoginDialogPane`, `account`, and `login` source-family terms.
- Search roots and evidence-time outcomes: active `tools/leaser/Agents/**` had 115 Markdown files and no direct-target report; central `executed-b-agent-research/**` had 2182 Markdown files and 19 exact/strong-family matches; project `archived/**` existed with zero Markdown files; `tools/leaser/Agents/Older-Research/**` had three Markdown files and no match; `tools/leaser/Agents/SpecialReports/**` had five Markdown files and no match.
- Relevant executed reports opened and classified:
  - `executed-b-agent-research/B004/0002X9-g_pNewUserDialogPane-source-quality.md`: direct support for the singleton declaration, five lifecycle refs, [UID:0000LV] route, zero-fill/source declaration, and stale manual-coverage correction. Its byte-tool disagreement remains a bounded singleton-storage caveat, not target-function proof.
  - `executed-b-agent-research/B003/0004GN-NewUserMiscDialogPaneRawCleanupIsland-source-quality.md`: accepted adjacent-family precedent that a no-function/no-xref duplicate teardown island is compiler non-deleting cleanup support, while the scalar-deleting entry anchors ordinary source destructor semantics. Adopted only after direct UID0002Q3 evidence reproduced the same route shape.
  - `executed-b-agent-research/B013/0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md`: adjacent aggregate/split precedent; useful for split structure and raw-island caution, not direct NewUserDialogPane proof.
  - `executed-b-agent-research/B008/0002QT-CreateUserDialogPaneCore-source-quality.md` and `B004/00003B-CreateUserDialogPane-class-source-quality.md`: sibling create-character class/packet/source-shape precedent; they do not own this older account-registration class.
  - `executed-b-agent-research/B015/00046S-CreateUserDialogPaneOnCreateUserReplyEvent-source-quality.md`: historical sibling lead for an opcode-2 event bridge, but its `PacketEvent::payload` naming is superseded for this target by the current Event/EventHandler contract and direct `[event+0x0c]` evidence. It is not source-contract authority for UID0004PD.
  - `executed-b-agent-research/B001/00011J-EPFImageControlPaneCore-empty-emitter-source-quality.md`: confirms the source-facing EPF control constructor and compiler-destructor exclusions used by the constructor draft.
  - `executed-b-agent-research/B001/00019L-EnsureLoginDialogPane-source-quality.md`: supports the standalone login/account file split and successor boundary, not UID0002Q3 ownership.
  - `executed-b-agent-research/B002/0002AF-g_pMainUiGraph-source-quality.md`: historical alias correction; `g_pMainUiGraph` is rejected and the relevant pane receiver is `g_pMainMenuPane`, while `0x0069b36c` remains the accepted overlay layer slot.
  - `executed-b-agent-research/B010/00019J-CloseMainMenuDialogSingletons-source-quality.md`: supports source-form `delete g_pScreenDimmer` and main-menu close behavior; it does not own this class.
  - `executed-b-agent-research/B010/0001CR-CreateUserDialogVariants-source-quality.md`: confirms that create-character variants are a different source family and must not absorb this account-registration target.
- At the report-search evidence time, the B005 goal assigned adjacent UID0002Q4 `LoginDialogPaneCore`, not UID0002Q3, and no B005 UID0002Q4 report artifact yet existed. B004's callback excluded UID0002Q4 and `by-class/LoginDialogPane.md`; on shared UID00019I/UID00025Q/UID00029H and `by-file/LoginDialogPane.md`, B004 reread/rebased current bytes and changed only the NewUser-specific rows/links. B005/concurrent content was preserved. This is a completed collision-free ownership decision, not a claim about B005's external lifecycle state.
- Current sibling recheck: finalized [UID:0004PQ] `by-memory/0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent.md` uses `bool LoginDialogPane::HandlePacketEvent(Event *event)`, reads `event->m_payload.m_packet.m_data`, and performs the same direct 256-narrow/256-wide conversion sequence. It is read-only corroboration; UID0002Q4 and all Login source methods remain outside B004 ownership.
- Current hierarchy recheck: `DialogPane : public Pane`; Pane documents the EventHandler secondary view at object `+0xa0`; EventHandler fixes packet dispatch at virtual slot `+0x10`; and both NewUser and Login lifecycle code install their corresponding secondary vtable at that same adjusted view. Thus the target's `ecx -= 0xa0` is compiler receiver recovery for the inherited EventHandler override, not evidence for a target-specific event class or differently named callback.

## Target

- Target UID: `0002Q3`.
- Target path: `by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md`.
- B004 research/implementation artifact path before any supervisor-owned lifecycle operation: `tools/leaser/Agents/Agent-B004/research/0002Q3-NewUserDialogPaneCoreAndPacketHelpers-empty-emitter-source-quality.md`.
- Queue state at assignment: intersection of Files With Empty Emitters and by-memory Not-Covered Files - Reconstructable; owner file UID0000LV had zero countable direct reports and only the singleton declaration emitted.
- Evidence-time target metadata: `86/90`, `CANONICAL_OWNER:0000LV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LV`, blank position, blank formal C++, `Nested:4`.
- Evidence-time manual row inspected: `by-memory/-coverage-report.md:1994` was `86% : strong` and described one reconstructable class-method cluster. B004 left manual coverage read-only and supplies exact external replacement/addition text below.

## Current Target State

- The page now records the broad behavior as a non-emitting split index rather than combining source methods, compiler cleanup, a switch table, and padding in one reconstructable emitter. Child-range source appears only on exact children.
- Semantic file family [UID:0000LV] is retained; class-method children narrow to [UID:00009D], and file-local sender UID0004PH remains on [UID:0000LV].
- The parent C++ remains deliberately blank because exact children carry human-source bodies. The bounded callback applied corrected formal Destinations 2, 5, and 10 to UID00009D, UID0004PD, and UID0004PI; synchronized UID0002Q3, UID0000LV, UID00019I, UID0004PP, and `by-memory/-ignored.md`; and preserved every unaffected source/compiler child.
- The hidden `0x004fa0b0` copy is documented as compiler non-deleting cleanup support; ordinary destructor semantics emit once from routed scalar-deleting entry UID0004PO at `0x00502970`.
- `Nested:4` is not four children. The validator README defines it as the relative nesting delta from the previous address-sorted row. The target retains `4`; exact children use `Nested:0` as address-sorted peers under the established split-index convention.
- Historical generated state after commands `000000011608/000000011617` remains structural baseline evidence and contained the rejected old-name packet virtual and `SimpleUString` conversion. Current waited command `000000011691` supersedes those semantics: generated `NewUserDialogPane.cpp` has one corrected definition/payload access, one direct fixed-buffer conversion, zero old name, zero standalone `PacketEvent`, zero `SimpleUString::FromMbcString`, and all historical structural positive/negative counts intact.
- The bounded ordinary implementation, scoped validation, UID/path uniqueness checks, and generated semantic readback are complete. B004 performed no report execution, lifecycle, count, move, archive, manual-coverage edit, or generated-file edit; external validation/execution/count/path/archive state remains supervisor/validator-owned and no implementation item remains in this artifact.

## Executive Recommendation

- Reclassify UID0002Q3 as a non-emitting split index and create thirteen exact pages serially. The nine target-range children cover every executable or table subrange; padding is represented exactly in `by-memory/-ignored.md`. Four separate pages cover constructor-unwind singleton clear, two adjustor thunks, the routed destructor anchor, and exact vtable data.
- Route constructor, `HandlePacketEvent(Event *)`, command, updater, submit, reply, and destructor through class UID00009D. Route `SendCreateAccountRequest` directly through file UID0000LV. Do not route compiler/raw/table/vtable pages.
- Make UID00009D a complete zero-new-field class declaration: the binary object size remains inherited `DialogPane` size `0x26c`; the three vptr writes are inherited/multiple-interface compiler layout, not source fields.
- Source placement is resolved as `NexusTK/login/NewUserDialogPane.cpp`. UID0000KX remains a family/index page; its stale `class_NewUserDialogPane.cpp` wording was replaced with the standalone source route without taking ownership.
- Preserve retained/no-route constructor and cleanup evidence. No direct constructor route caps confidence but does not justify blanking byte-real, internally coherent source that is fully tied through vtables, singleton lifecycle, resources, and sibling source conventions.
- UID0004PD is UID-preservingly registered at `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md`, with `Event *` and `event->m_payload.m_packet.m_data`. UID0004PI now uses direct `char narrowText[256]`, `wchar_t wideText[256]`, exact-length `memmove`, explicit narrow terminator, `MultiByteToWideChar(CP_ACP, 0, ..., textLength, ..., 256)`, the evidenced low-byte returned-length wide terminator, and AlertPane construction from `wideText`. No inline human helper is evidenced.

## Supervisor Active Recheck

- Historical Gate 1 state: the supervisor accepted exact pre-callback SHA256 `5DFAED97BCEECB401EC00A3B1812363B2F44409EC022A31B6C29DDF78A7A6DA4`, authorizing this implementation callback after the report-only evidence pass.
- A split is mandatory because the parent spans class methods, a file-local helper, compiler cleanup, a compiler table, and padding. Emitting one aggregate body would violate range ownership and duplicate compiler output.
- Every source-bearing child has a complete formal block below, and every compiler/data child has a specific no-code proof and blank formal block. Corrected Destinations 2, 5, and 10 now match their ordinary destinations exactly; all unaffected prior callback work remains applied proof.
- Adjacent B005 UID0002Q4 ownership remained collision-free: B004 excluded B005 source-method pages and limited shared-page edits to NewUser-specific rows after serialized reread/rebase.

## Inference Research Guidance Check

- IDA fact: exact bytes, modeled starts/sizes, control flow, xrefs, vtable cells, singleton refs, constants, packet offsets, control IDs, callees, and negative routes.
- Documentation evidence: current source-facing APIs and accepted sibling conventions for Event/EventHandler packet dispatch, DialogPane controls, packet buffers, AlertPane, ScreenDimmer, direct ANSI-to-wide conversion, layer slots, and scalar-destructor source anchoring.
- Inference: original method/helper spellings, standalone file manifest, and local variable names. Each chosen spelling is the highest-probability human form and remains confidence-capped where no symbol survives.
- Existing documentation assumptions treated as hypotheses: one reconstructable aggregate, cleanup-as-source-body blocker, folded LoginDialogPane placement, final-name deferral, child-count interpretation of `Nested`, historical `g_pMainUiGraph`, and broad read-only/vtable ownership.
- Stale Wave2/Wave3 wording appears in support docs but was not used as authority. Evidence-time IDA, destination docs, generated output, and non-Wave historical reports were independently checked.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Validation |
| --- | --- | --- |
| Aggregate source shape | Non-emitting split index; no aggregate C++. | Nine exact target children have distinct ownership/disposition; by-structure forbids child source in parent range. |
| Constructor name/type | `NewUserDialogPane::NewUserDialogPane()`; no new fields. | Exact resource/control setup, vptr triplet, singleton publish, inherited size `0x26c`, and DialogPane API. |
| Constructor liveness | Retained legacy source despite zero direct xrefs. | Full coherent body, class vtable/lifecycle symmetry, successor family, and active newer create-user routes establish a retained old variant rather than padding. |
| Raw cleanup `0x004fa0b0` | Compiler non-deleting cleanup island; no source body. | No IDA function, no xrefs, no pointer route, same vptr/dimmer/singleton/base teardown as routed scalar destructor. |
| Packet event virtual | `bool HandlePacketEvent(Event *event)`. | Current EventHandler declares this packet-family slot; current Login sibling uses the same override; secondary vtable slot `+0x10` routes `0x0061d35c -> 0x004fa0f0`; binary reads payload pointer at `Event +0x0c`, adjusts only `this-0xa0`, tests opcode `2`, and tail-calls the reply handler. |
| Command handler | `void OnControlCommand(int controlIndex, int notifyCode)`. | Primary vtable slot and exact base virtual API; cases 1/2, unused notify, no base call. |
| Button updater | `UpdateCreateUserButtonEnabledState`. | Same virtual slot role as documented `UpdateLoginButtonEnabledState`; control 1 toggles Enable/Disable after short-circuit IsEmpty checks on 3/4/5. |
| Submit method | `SubmitCreateUser`. | Sole command caller, three 16-wide buffers/capacity 15, exact digit/match branches, alerts, dimmer, helper call. |
| Request helper | file-local `static void __stdcall SendCreateAccountRequest`. | ABI has no receiver, sole call from submit, adjacency and packet role match sibling `SendLoginRequest`/`SendPasswordChangeRequest` style. |
| Request layout | opcode 2; three one-byte-length MBC fields; final zero included in send length. | Exact decompilation and bytes; each conversion cap is 256, final aggregate range check is `>=256`, no clamp/normalization. |
| Reply method | `bool HandleCreateUserReply(const unsigned char *packet)`. | Sole packet-virtual call, packet offsets 1/2/3, exact result groups, success handoff, always-true return. Direct stack/call evidence requires 256-byte narrow and 256-wide local buffers, exact-length copy, explicit terminators, and direct `MultiByteToWideChar(CP_ACP,...)`. |
| Error dimmer nuance | Entire nonzero focus/message branch is gated by nonnull `g_pScreenDimmer`. | CFG places switch, conversion, and alert inside the dimmer predicate; null dimmer returns true silently. |
| Reply table | compiler switch table, not source data declaration. | One NOP, three branch target dwords, compact byte map, no independent data owner, followed by exact padding. |
| Destructor source | ordinary source destructor anchored at scalar-deleting entry `0x00502970`. | Primary vtable + two adjustors route there; body duplicates teardown and adds compiler delete flags/free. |
| Unwind helper/thunks | compiler/EH/adjustor support, blank C++. | `0x005023f0` is ctor EH-only singleton clear; `0x0050250e/19` subtract `0xa0/0xa4` and jump to deleting entry. |
| Vtable data | exact source-declared/generated-binary child owned by class, false/non-emitting. | `0x0061d2ec-0x0061d384` contains primary/secondary/tertiary views and ends before Login RTTI/vtable data. |
| Source file | standalone `NewUserDialogPane.cpp`. | Dedicated class, singleton, file-local sender, contiguous method island, sibling files, and UID0000LV existing route; Login file is broader index only. |
| `Nested:4` | retain as relative delta, not count. | Validator README definition plus established exact-child `Nested:0` split convention. |
| Empty emitters | eliminated structurally by parent false/no emitter and populated class/child blocks. | Historical command `11542` proved the two-marker problem; command `11608` proved zero Empty Emitter Markers and valid routing but retained the two rejected source forms; B004 waited command `11691` proved the corrected virtual/conversion and preserved zero markers. |

Rejected alternatives:

- Keep one aggregate emitter: rejected because it would mix source bodies with compiler cleanup/table/padding and violate exact-range C++ ownership.
- Emit the raw cleanup as a second destructor: rejected because it has no route and duplicates the routed scalar destructor's source semantics.
- Handwrite scalar deleting flags, vptr stores, base destructor call, operator delete, adjustors, EH clear, or jump table: rejected as MSVC lowering.
- Fold all NewUser source into `LoginDialogPane.cpp`: weaker than the existing dedicated UID0000LV route and standalone class/helper cluster.
- Route the request helper through the class: rejected because ABI/callsite show no receiver; it is a file-local free helper.
- Keep source names blank until original symbols exist: rejected because behavior, interfaces, sibling naming, and source placement resolve plausible final source; uncertainty is bounded in scores.
- Treat no constructor xref as proof of dead bytes/no-code: rejected because the island is structured class source with vtable/lifecycle/resource evidence and belongs to a retained legacy variant.
- Use `g_pMainUiGraph`, raw `sub_`, `unk_`, byte offsets, or decompiler temporaries in destination C++: rejected by corrected support evidence and human-source requirement.
- Keep `OnCreateUserReplyEvent(const PacketEvent *)`: rejected because it does not override the current `EventHandler::HandlePacketEvent(Event *)` slot and invents a parallel event type/member contract contradicted by Event layout and Login sibling evidence.
- Use `SimpleUString::FromMbcString`: rejected because `0x004fa5b0` directly allocates two fixed stack buffers and calls `memmove` plus `MultiByteToWideChar`; no call, inlined helper signature, or equivalence proof supports replacing its edge behavior with that abstraction.

## Evidence Standards Used

- Highest weight: live IDA MCP bytes, modeled function boundaries, decompilation/disassembly, CFG block counts, xrefs, vtable pointers, global writes, and direct UTF-16LE decoding.
- Strong corroboration: constructor/destructor symmetry, single-caller chains, exact successor boundaries, current by-* API contracts, and accepted adjacent-family compiler/source conventions.
- Lead-only evidence: generated C++, old reports, historical aliases, and source-family groupings. Every adopted lead was checked against evidence-time binary/docs.
- Negative evidence was affirmative: zero xrefs/function objects/pointer routes for raw islands, no constructor callers, no independent table route, no extra class storage, and no direct helper receiver.
- Confidence is below 95 because no original symbols/source manifest survive and the constructor is retained/no-direct-route. Those limits do not block exact split, ownership, or first-draft source.

## Evidence Checked

- MCP availability: fresh `initialize`, `idb_list`, `server_health`, and bounded target calls against historical research database `3fc1dcef`; callback and Gate 2 repair checks used replacement database `9df6e9a0` while it was verified healthy. After that worker disappeared, supervisor-recovered database `6b2e78f3` was discovered by fresh `idb_list` and verified healthy at `2026-07-14T14:34:16-04:00`; repeated bounded lookup/bytes/decompile calls for both rejected methods and the Login sibling succeeded before implementation resumed.
- `lookup_funcs`: `0x004f9d30` size `0x379`; `0x004fa0b0` not a function; `0x004fa0f0` `0x26`; `0x004fa120` `0x2e`; `0x004fa150` `0x79`; `0x004fa1d0` `0x1cc`; `0x004fa3a0` `0x205`; `0x004fa5b0` `0x1c3`; lifecycle entries `0x005023f0`, `0x0050250e`, `0x00502519`, and `0x00502970` sizes `0xb`, `0xb`, `0xb`, and `0x71`.
- `analyze_function`/decompile: all seven modeled target functions and four lifecycle functions. Constructor reported 34 blocks; adapter 4; command 5; updater 7; submit 29; request 12; reply 19. Compiler EH blocks explain constructor/submit counts.
- Fresh repair decompile/disassembly: `0x004fa0f0` has 14 instructions and exact bytes/hash already recorded; `mov edx,[event+0x0c]`, opcode test, `ecx -= 0xa0`, and tail jump `0x004fa111 -> 0x004fa5b0` prove the EventHandler override shape. `0x004fa5b0` has a `WCHAR[256]` stack local at frame offset `0x18` and `CHAR[256]` at `0x218`; instructions `0x004fa669-0x004fa682` copy exactly `packet[2]` bytes and terminate narrow text, while `0x004fa677-0x004fa6a2` pass destination capacity `256`, code page/flags `0/0`, the same exact byte count, and terminate wide text at the returned length.
- Bounded `insn_query`: all 15 instructions in `0x004fa0b0-0x004fa0ef`, each with `fn:null`, including three vptr stores, guarded virtual delete flag `1`, singleton clear, and base-destructor tail jump.
- Bounded `get_bytes`: complete aggregate, all child/padding ranges, lifecycle helpers, destructor, and exact vtable child. SHA256 values are recorded below.
- `xrefs_to`: all modeled starts, raw start, vtable bases/slots, singleton, helper, thunks, and destructor. Exact route inventory is recorded below.
- Fresh repair xrefs: `0x004fa0f0` still has only data xref `0x0061d35c`; `0x004fa5b0` still has only code xref `0x004fa111`; sibling `0x004fab10` still has only EventHandler-vtable data xref `0x0061d3f8`. This ties both dialog functions to the same packet-family virtual contract without introducing a `PacketEvent` type.
- String evidence: `get_string` mis-typed UTF-16 as narrow `p`/`O`; direct bounded bytes were decoded as empty wide string, `password must containt at least 1 number`, and `OK`. The typo is preserved exactly.
- Evidence-time docs and generated source: all target/support pages listed in Supporting Research, manual by-memory/by-class/by-file coverage rows, generated `NewUserDialogPane.cpp`, research tracker, and by-structure/validator `Nested` rules.
- Old-report roots and exact terms: all roots, counts, relevant opened paths, and no-direct-report results are recorded in Supporting Research.
- Negative checks: no direct ctor/raw-cleanup xrefs; no function at raw start; no separate raw table function; no request-helper receiver; no extra derived data fields; no reason to move PacketBuffer/Socket/Config/AlertPane/ScreenDimmer ownership; no direct target report in the active/archive/SpecialReports roots when searched; no `PacketEvent` contract in current Event/EventHandler docs; and no helper call or inlined-helper proof at `0x004fa5b0` that could justify `SimpleUString` while preserving exact fixed-buffer edge behavior.
- Non-evidence transport corrections: an initial local PowerShell `Invoke-WebRequest` needed `-UseBasicParsing`, and one local JSON composition used PowerShell's reserved `$args` name and omitted arguments. Both were corrected before evidentiary calls; valid calls included explicit `database:'3fc1dcef'` and later `database:'6b2e78f3'` and succeeded. These were client-composition errors, distinct from the supervisor-confirmed historical worker outage.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | ---: | --- | --- | --- | --- |
| C01 | Historical databases `3fc1dcef` and `9df6e9a0` were healthy at their recorded evidence times; after the callback pause, fresh `idb_list` discovered replacement database `6b2e78f3`, whose health and bounded reads at `2026-07-14T14:34:16-04:00` reproduced both affected functions and the Login sibling. | 99 | Fresh `idb_list`, health, bounded lookup/decompile/disasm/bytes/xrefs; no fallback evidence. | Supporting Research / IDA MCP Facts | incorporate | applied |
| C02 | Aggregate `[0x004f9d30,0x004fa7a0)` is 2672 bytes with SHA256 `4ada69a186599faa63c50a34ca27318830f19baf0ecb466a4bf6557bd0967d31`. | 99 | Complete `get_bytes`. | UID0002Q3 and child evidence; target validator `000000011587` | incorporate | applied |
| C03 | Seven modeled target functions have exact starts/sizes and CFG listed in this report. | 98 | `lookup_funcs`, analyze/decompile. | UID0004PB/PD/PE/PF/PG/PH/PI; validators `11562/11565/11566/11568/11570/11571/11573` | incorporate | applied |
| C04 | Eight exact target padding spans and two lifecycle padding spans are compiler alignment. | 99 | Bytes all `cc`; boundaries/successors. | `by-memory/-ignored.md`; validator `000000011605` | incorporate | applied |
| C05 | UID0002Q3 is a non-emitting split index, `92/94`, owner 0000LV, false, blank emitter/position/C++, `Nested:4`. | 96 | Mixed dispositions; by-structure. | UID0002Q3; validator `000000011587` | incorporate | applied |
| C06 | `Nested:4` is a relative address-order delta, not four children; new peers use `0`. | 99 | Validator README and current split precedents. | UID0002Q3 plus UID0004PB-PC-PD-PE-PF-PG-PH-PI-PK-PL-PM-PO-PP; validators `11562-11587` | incorporate | applied |
| C07 | Constructor is source-authored `NewUserDialogPane::NewUserDialogPane()` with exact controls/resources/order. | 94 | Exact decompile, APIs, vtables. | UID0004PB; validator `000000011562` | incorporate | applied |
| C08 | Constructor has zero direct xrefs but remains retained legacy source; no-route is a confidence cap. | 93 | Xrefs; coherent class lifecycle and family. | UID0004PB, UID00009D, UID0000LV; validators `11562/11591/11594` | incorporate | applied |
| C09 | `0x004fa0b0-0x004fa0ef` is compiler non-deleting cleanup, not a source method. | 97 | No function/xrefs; instruction parity with destructor. | UID0004PC blank formal block; validator `000000011563` | incorporate | applied |
| C10 | `0x005023f0-0x005023fb` is ctor-EH singleton clear compiler support. | 98 | One EH xref at `0x6016d4`; 11-byte body. | UID0004PL blank formal block; validator `000000011577` | incorporate | applied |
| C11 | `0x004fa0f0` is the source override `bool NewUserDialogPane::HandlePacketEvent(Event *event)`, not `OnCreateUserReplyEvent(const PacketEvent *)`. | 98 | Current EventHandler declaration, Login sibling, secondary slot `+0x10`, opcode 2, receiver adjust, direct `[event+0x0c]` payload read; recovery database `6b2e78f3` reconfirmation. | UID0004PD UID-preserving rename/formal correction validator `000000011674`; UID00009D validator `000000011677`; generated command `000000011691` | reject-stale | applied |
| C12 | `0x004fa120` is `OnControlCommand`; case 1 submits and case 2 closes. | 96 | Primary vtable slot, base API, exact CFG. | UID0004PE and UID00009D; validators `11566/11591` | incorporate | applied |
| C13 | `0x004fa150` is `UpdateCreateUserButtonEnabledState`; empty 3/4/5 disables control 1. | 93 | Vtable role, sibling Login naming, virtual slots. | UID0004PF and UID00009D; validators `11568/11591` | incorporate | applied |
| C14 | `0x004fa1d0` is `SubmitCreateUser` with exact three buffers, digit/match branches, alerts, dimmer, and helper call. | 96 | Decompile, literals, sole caller/callee. | UID0004PG and UID00009D; validators `11570/11591` | incorporate | applied |
| C15 | `0x004fa3a0` is file-local `static void __stdcall SendCreateAccountRequest`, not a member. | 94 | ABI, sole caller, source adjacency. | UID0004PH and UID0000LV; validators `11571/11594` | incorporate | applied |
| C16 | Request format is opcode 2 plus three MBC length-prefixed fields and sent trailing zero, with exact cap/failure semantics. | 98 | Decompile/bytes/callees. | UID0004PH complete managed block; validator `000000011571` | incorporate | applied |
| C17 | `0x004fa5b0` is `HandleCreateUserReply` using packet `[1]/[2]/[3]`, two fixed 256-element stack buffers, direct conversion, and always returns true. | 99 | Fresh decompile/disassembly, sole packet-virtual route, exact frame and calls; recovery database `6b2e78f3` reconfirmation. | UID0004PI corrected formal block validator `000000011679`; class/file/target detail validators `11677/11684/11682`; generated command `000000011691` | reject-stale | applied |
| C18 | Nonzero reply focus, fixed-buffer conversion, and alert work occur only when `g_pScreenDimmer` is nonnull; null dimmer returns true silently. | 99 | Fresh reply CFG/decompile/disassembly. | UID0004PI managed block validator `000000011679`; generated exact branch/body readback `000000011691` | incorporate | applied |
| C19 | Success behavior remains unchanged by this repair: delete dimmer if present, close dialog, save control 3 through `g_pConfig->SetLogData`, and create `NewUserMiscDialogPane`. | 99 | Fresh exact callees/control read plus historical docs. | UID0004PI, UID00028Q, UID0000LV; historical validators `11573/11603/11594`; no support rewrite beyond corrected conversion description | already-present | already-present |
| C20 | `[0x004fa773,0x004fa793)` is compiler switch data; `[0x004fa793,0x004fa7a0)` is padding. | 99 | Exact bytes and successor. | UID0004PK, `by-memory/-ignored.md`, UID0002Q3; validators `11576/11605/11587` | incorporate | applied |
| C21 | Vtable slots bind destructor, command, updater, EventHandler packet virtual, and two adjustor thunks exactly; `0x0061d35c` is the packet-family `+0x10` slot. | 99 | Vtable bytes/xrefs plus EventHandler/Login contract. | UID00009D/UID0004PP/UID0002Q3 corrections; validators `000000011677/11688/11682`; generated command `000000011691` | reject-stale | applied |
| C22 | `[0x0061d2ec,0x0061d384)` is exact NewUserDialogPane vtable data ending before Login data. | 98 | 152 bytes/hash, RTTI/vtable boundary. | UID0004PP and UID00025Q; validators `11584/11598` | incorporate | applied |
| C23 | `0x00502970` anchors ordinary source destructor body once; deleting flags/free/base/vptr operations stay compiler-generated. | 97 | Primary vtable + thunks; scalar body. | UID0004PO and UID00009D; validators `11582/11591` | incorporate | applied |
| C24 | `0x0050250e/19` are compiler adjustor thunks subtracting `0xa0/0xa4`. | 99 | Bytes/decompile/xrefs. | UID0004PM blank formal block; validator `000000011579` | incorporate | applied |
| C25 | NewUserDialogPane adds no fields beyond `DialogPane`; object size is `0x26c`. | 95 | Allocation/constructor size and no derived accesses. | UID0004PB/UID00009D/UID0000LV; validators `11562/11591/11594` | incorporate | applied |
| C26 | UID00009D remains `92/94`, closes before `[[CHILDREN]]`, forward-declares `Event`, and overrides `HandlePacketEvent(Event *)`. | 98 | Current EventHandler/Login declarations and live target body. | `by-class/NewUserDialogPane.md` corrected Destination 2; validator `000000011677`; generated class/definition readback `000000011691` | reject-stale | applied |
| C27 | UID0000LV is `91/92`, resolved as standalone `NexusTK/login/NewUserDialogPane.cpp`. | 92 | Dedicated class/helper/singleton cluster. | `by-file/NewUserDialogPane.md`; validator `000000011594` | incorporate | applied |
| C28 | Parent score is `92/94`; confidence remains below 95 for symbols/ctor route. | 96 | Complete blocker audit. | UID0002Q3; validator `000000011587` | incorporate | applied |
| C29 | Source children retain class/file owners and positions exactly as listed; false children retain no emitter/position/C++; UID0004PD received a UID-preserving source-name/path correction without UID, score, owner, emitter, position, range, or nesting change. | 99 | Ownership/source order plus corrected interface contract. | All thirteen pages; UID0004PD path update and seven propagated links under validator `000000011674`; old path absent and UID unique | incorporate | applied |
| C30 | Thirteen temporary UID tokens were registration-only identifiers and have been replaced by the exact UID map `0004PB` through `0004PP` with validator-allocation gaps preserved. | 99 | Serial validator registration and final token scan. | Report, inventory, coverage text, checklist, and ordinary destinations; no temporary-token pattern match | incorporate | applied |
| C31 | All thirteen pages were registered serially before support cross-linking and every temporary token was replaced. | 99 | UID workflow and command chronology. | Validators `11562-11584`, then target/support validators `11587-11605` | incorporate | applied |
| C32 | Exact padding and compiler-support exclusions belong in `by-memory/-ignored.md`. | 98 | Disposition and current conventions. | `by-memory/-ignored.md`; validator `000000011605` | incorporate | applied |
| C33 | UID00019I remains false/mixed, score unchanged `85/88`, with its NewUser row pointing to exact children. | 95 | Current parent and split. | UID00019I; validator `000000011596` | incorporate | applied |
| C34 | UID00025Q remains `86/92` false/mixed and has the exact NewUser vtable child link only. | 98 | Exact vtable boundary. | UID00025Q; validator `000000011598` | incorporate | applied |
| C35 | UID00029H remains `91/93` false/mixed and distinguishes raw cleanup from routed destructor. | 96 | Current page and lifecycle refs. | UID00029H; validator `000000011600` | incorporate | applied |
| C36 | UID0002X9 remains `88/90` with its declaration unchanged and exact ctor/raw/EH/destructor child links added. | 97 | Five singleton refs. | UID0002X9; validator `000000011602` | already-present | applied |
| C37 | UID00028Q remains `86/90` with exact `SetLogData(accountName)` consumer detail. | 96 | Reply success call `0x48eb50`. | UID00028Q; validator `000000011603` | incorporate | applied |
| C38 | UID0000KX score/owner stayed unchanged and stale `class_NewUserDialogPane.cpp` wording was replaced with the standalone route. | 93 | Current file docs and dedicated UID0000LV. | `by-file/LoginDialogPane.md`; validator `000000011595` | reject-stale | applied |
| C39 | UID0002Q4/Login source methods remain B005-owned and verify-only for B004. | 99 | Collision-free scope and reread/rebase. | No B005 source-method page edited; only NewUser rows in shared docs changed | not-applicable | excluded-with-reason |
| C40 | Event/EventHandler/DialogPane/Login plus control/Alert/ScreenDimmer/PacketBuffer/global dependencies remain owner/score/formal verify-only; their current contract is direct evidence for this correction. | 99 | Current Event layout, EventHandler pure virtual, Login sibling and direct dependency roles. | Named support pages were read and left unchanged in this report-only repair | already-present | already-present |
| C41 | Zero routes, retained status, historical aliases, and superseded `PacketEvent`/`OnCreateUserReplyEvent`/`SimpleUString` assumptions remain explicit history rather than current source authority. | 99 | Negative checks, current docs, fresh MCP, old docs. | UID0002Q3, UID00009D, UID0000LV, UID0004PD, UID0004PI and reverse-link docs; validators `11674-11690` | historicalize | applied |
| C42 | Aggregate body, duplicate cleanup destructor, handwritten ABI/table/vtable code, folded Login ownership, raw labels, parallel `PacketEvent`, and helper-level `SimpleUString` conversion remain rejected. | 99 | By-structure, current interface, direct stack/call evidence. | Corrected blank/source blocks plus generated negatives under `000000011691`; historical commands `11608/11617` retained as structural baselines | reject-invalid | applied |
| C43 | Corrected generated source retains one class and one each of eight source bodies, no parent/false-child body or UID0002Q3 marker, exactly one `HandlePacketEvent(Event *)`, zero old `OnCreateUserReplyEvent`/standalone `PacketEvent`, direct fixed-buffer conversion, and zero `SimpleUString::FromMbcString`. | 99 | Historical readback, B004 waited semantic readback, and later concurrent-refresh readback with identical counts. | Waited refresh `000000011691`, header/SHA `11691`/`D904F8D4A9948019B6ED8B4D34D6A27EB420673521B8E7FCD324720D078954AA`; evidence-time later header/SHA `11692`/`AC07C072C036B9CCADACF705017A2FB7A88F9D25B3C9C390878DDD238108E149` | incorporate | applied |
| C44 | Exact supervisor-owned coverage replacement/addition text uses the corrected EventHandler/fixed-buffer wording and all thirteen real UIDs; manual files remain external, supervisor-owned, and read-only. | 99 | Read-only manual row comparison, UID map, corrected report text. | Exact Manual Supervisor-Owned Coverage Or Tracker Text; no manual coverage edit by B004 | incorporate | applied |
| C45 | Fresh scoped validators completed for UID0004PD, UID00009D, UID0004PI, target/file/aggregate/vtable/ignored destinations, followed by one waited generated semantic refresh. | 99 | Current validator commands and generated readback. | Validators `000000011674/11677/11679/11682/11684/11687/11688/11690`; waited `000000011691` | incorporate | applied |
| C46 | B004's historical callback stayed within accepted scope; this Gate 2 repair edited only this report, acquired no lease, ran no validator/lifecycle command, and touched no ordinary/generated/manual-coverage/tracker/audit/supervisor/validator-state/archive/IDA file. | 99 | Write-scope and lease audit. | Changed Files / repair checklist | already-present | applied |
| C47 | `Event::m_payload.m_packet.m_data` is the source-facing packet pointer at exact `Event +0x0c`; the byte at `Event +0x08` is packet kind and is not the packet pointer. | 99 | Current Event layout, dispatcher contract, `mov edx,[event+0x0c]`, Login sibling, recovery MCP read. | UID0004PD block, UID00009D declaration/prose, target/file/aggregate/vtable links; validators `11674/11677/11682/11684/11687/11688` | incorporate | applied |
| C48 | UID0004PI directly uses `char narrowText[256]`, `wchar_t wideText[256]`, exact packet length, explicit narrow/wide terminators, and `MultiByteToWideChar(CP_ACP,0,...,textLength,...,256)` with the returned length narrowed to unsigned byte before indexing; no equivalent inline helper is evidenced. | 99 | Fresh frame/disassembly/decompile, target `movzx eax,al`, matching Login sibling, recovery MCP read. | UID0004PI corrected Destination 10 and class/file/target/aggregate/ignored detail; validators `11679/11677/11684/11682/11687/11690`; generated `11691` | incorporate | applied |

## Positive Evidence Summary

- The aggregate's seven modeled functions are contiguous and internally linked: command calls submit, submit calls request, and the EventHandler packet virtual tail-calls reply. Three virtual entries route through exact NewUserDialogPane vtable cells.
- Constructor, raw cleanup, and routed destructor write the same three vtable views; all three views have exactly those three store xrefs. This is strong class/lifecycle identity evidence.
- The singleton has exactly five refs: constructor publish/fallback, raw cleanup clear, constructor-EH clear helper, and routed destructor clear.
- Constructor resource, control IDs, rectangles, field capacities, focus/default state, layer/main-menu attachment, and open animation all map to current source-facing APIs.
- Request and reply packet layouts are exact and symmetric with the account/login family; the request helper has no receiver and the reply handler has one packet-virtual route. Current Event/EventHandler/Login documents and fresh MCP converge on `HandlePacketEvent(Event *)` with payload at `+0x0c`. NewUser and Login reply bodies also share directly evidenced fixed narrow/wide stack buffers and direct `MultiByteToWideChar` conversion.
- The scalar deleting entry is the sole vtable-routed teardown and the only safe anchor for one ordinary destructor body. Compiler-only duplicates are separable without losing behavior.
- UID0000LV already owned the singleton declaration and dedicated generated file before callback. The registered exact class/file children eliminate both historical empty markers without inventing a new source root.

## IDA MCP Facts

- Research evidence database: `3fc1dcef`; post-resume `idb_list` count one and health `ok` at evidence time. Callback and Gate 2 repair verification used replacement database `9df6e9a0` while it was healthy. After its historical outage, fresh `idb_list` discovered database `6b2e78f3`; health and bounded target/sibling reads succeeded at `2026-07-14T14:34:16-04:00`. All availability statements are evidence-time scoped rather than indefinite claims.
- Aggregate bytes: `[0x004f9d30,0x004fa7a0)`, 2672 bytes, SHA256 `4ada69a186599faa63c50a34ca27318830f19baf0ecb466a4bf6557bd0967d31`.
- Exact source-body hashes: constructor `3a110b170517fa4a78338509feb4dc1e72aecf24d798f3f84b49abcb9889b171`; packet virtual `c3d67e221eee27a9e26679e41bb0db3d93c282b7d972004604dbed6eca1fd300`; command `385a29ef6011ffcda45bc154bbd5692e700e23464b28910e33a6d0915d6f0439`; updater `c902fba6017db9f990e1058e45bed6406398e1000b06d9b2390b60f8c5c41ad6`; submit `162f169a122292843b85db9564fc9c7a1670bfc3fc252ae4012255907f827087`; request `15ce581553ecc9a719e539a067b57cdcf26754ed6e9fa605efaf5b11ecdc5fdb`; reply `35a523243563535218f4aa1fedc5eeb3293bbd4e6ce759cc46174e415dde624d`.
- Compiler/data hashes: raw cleanup `3cc08bce1a118a9aed284f78d50ce70f3691f2a34cd72f7dc6d7d682c572e854`; switch/table `340a5216f250221ce1ee42758b7f77b70b0291c2ae8b3d8fa42cb6662f6d32bb`; singleton EH clear `ce16ca95b1c4401d6e858453625aa9bbe985ca1d10c078f851d4e41ad2dc3094`; adjustor pair `40cfdfa18029b769e73f61894cc49c4b701a541c2f49e070b1359f494174bbd9`; scalar destructor anchor `12f69b3b75a45766d368f0bcfa1a64af8d146bd2920e47374b98b3c1bf18389f`; vtable child `de5bd958657594827e29b018f1c2d016dc6c25cfe7cbaa9779b3425f71f23740`.
- Vtable cells: primary `0x0061d2ec -> 0x00502970`; command `0x0061d334 -> 0x004fa120`; updater `0x0061d338 -> 0x004fa150`; secondary base `0x0061d34c -> 0x0050250e`; secondary event slot `0x0061d35c -> 0x004fa0f0`; tertiary base `0x0061d37c -> 0x00502519`.
- Fresh packet-virtual proof: `0x004fa0f0` decompiles as a boolean/byte-returning secondary member that dereferences `*(_DWORD *)(event + 12)`, tests packet byte zero against `2`, subtracts `0xa0` only from `this`, and tail-jumps to `0x004fa5b0`; exact disassembly is `mov edx,[eax+0Ch]` at `0x004fa0f6`, opcode test at `0x004fa0f9-0x004fa0ff`, and tail jump at `0x004fa111`.
- Fresh conversion proof: `0x004fa5b0` reserves `CHAR MultiByteStr[256]` and `WCHAR WideCharStr[256]`; obtains unsigned packet length from byte `+2`; calls copy helper `0x00516220` with destination, `packet+3`, and that exact length; writes `MultiByteStr[textLength]=0`; calls imported `MultiByteToWideChar` with `CodePage=0` (`CP_ACP`), flags `0`, `cbMultiByte=textLength`, and `cchWideChar=256`; executes `movzx eax,al` at `0x004fa69d`; writes `WideCharStr[static_cast<unsigned char>(wideLength)]=0`; and passes `WideCharStr` directly to AlertPane construction. Sibling `0x004fab10` has the same fixed-buffer/direct-call shape; the target instruction controls the exact narrowed terminator index.
- Raw cleanup instruction sequence has 15 decoded instructions and no function owner; it restores the three vptrs, guarded-deletes the dimmer with flag 1, clears singleton, and tail-jumps base teardown.
- Direct UTF-16LE decode preserves `password must containt at least 1 number` exactly, including `containt`; shared OK text is `OK`.
- Success callee `0x0048eb50` is current `Config::SetLogData`; it receives the account text copied from control 3.
- Negative IDA facts: no xrefs to constructor or raw cleanup starts; no independent raw table function; no direct request helper receiver; no extra NewUserDialogPane data access beyond inherited DialogPane storage.

## Function / Child Inventory

The thirteen children were registered serially in ascending address order before cross-references were added. The exact validator-assigned UID map is `0004PB` constructor, `0004PC` raw cleanup, `0004PD` packet virtual, `0004PE` command, `0004PF` button state, `0004PG` submit, `0004PH` request helper, `0004PI` reply, `0004PK` reply table, `0004PL` unwind clear, `0004PM` adjustor thunks, `0004PO` destructor, and `0004PP` vtable data; no temporary UID remains. UID0004PD was moved once without copying and is uniquely registered at the corrected `NewUserDialogPaneHandlePacketEvent` path; the old path is absent.

| Range / Item | UID / registered path | Role | Reconstructable | Direct owner/emitter | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f9d30-0x004fa0a9` | `0004PB` / `by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md` | constructor | true | `00009D` / `00009D`, position 1 | `91/93` | registered source child |
| `0x004fa0a9-0x004fa0b0` | `by-memory/-ignored.md` | 7-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa0b0-0x004fa0ef` | `0004PC` / `by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md` | compiler non-deleting cleanup | false | none / blank | `90/94` | registered no-code child |
| `0x004fa0ef-0x004fa0f0` | `by-memory/-ignored.md` | 1-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa0f0-0x004fa116` | `0004PD` / `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md` | EventHandler packet virtual | true | `00009D` / `00009D`, position 3 | `90/93` retained | UID-preserving rename/formal correction applied; validator `000000011674`; old path absent and UID unique |
| `0x004fa116-0x004fa120` | `by-memory/-ignored.md` | 10-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa120-0x004fa14e` | `0004PE` / `by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md` | virtual control command | true | `00009D` / `00009D`, position 4 | `91/93` | registered source child |
| `0x004fa14e-0x004fa150` | `by-memory/-ignored.md` | 2-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa150-0x004fa1c9` | `0004PF` / `by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md` | virtual button-state updater | true | `00009D` / `00009D`, position 5 | `91/93` | registered source child |
| `0x004fa1c9-0x004fa1d0` | `by-memory/-ignored.md` | 7-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa1d0-0x004fa39c` | `0004PG` / `by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md` | validation/submit method | true | `00009D` / `00009D`, position 6 | `92/94` | registered source child |
| `0x004fa39c-0x004fa3a0` | `by-memory/-ignored.md` | 4-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa3a0-0x004fa5a5` | `0004PH` / `by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md` | file-local request helper | true | `0000LV` / `0000LV`, position 1 | `92/94` | registered source child |
| `0x004fa5a5-0x004fa5b0` | `by-memory/-ignored.md` | 11-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x004fa5b0-0x004fa773` | `0004PI` / `by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md` | reply method with direct fixed-buffer conversion | true | `00009D` / `00009D`, position 7 | `92/94` retained | direct conversion formal correction applied; validator `000000011679` |
| `0x004fa773-0x004fa793` | `0004PK` / `by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md` | compiler switch data | false | `00009D` / blank | `92/94` | registered no-code child |
| `0x004fa793-0x004fa7a0` | `by-memory/-ignored.md` | 13-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x005023f0-0x005023fb` | `0004PL` / `by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md` | constructor EH clear helper | false | none / blank | `90/94` | registered no-code child |
| `0x005023fb-0x00502400` | `by-memory/-ignored.md` | 5-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x0050250e-0x00502524` | `0004PM` / `by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md` | two compiler adjustor thunks | false | none / blank | `91/94` | registered no-code child |
| `0x00502970-0x005029e1` | `0004PO` / `by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md` | scalar wrapper / source destructor anchor | true | `00009D` / `00009D`, position 2 | `92/94` | registered source child |
| `0x005029e1-0x005029f0` | `by-memory/-ignored.md` | 15-byte `cc` alignment | false | none | n/a | exact ignored span |
| `0x0061d2ec-0x0061d384` | `0004PP` / `by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md` | source-declared/compiler-generated vtables | false | `00009D` / blank | `91/94` | registered no-code child |
| `0x004fa7a0-0x004fb2d0` | existing UID0002Q4 | LoginDialogPane successor | unchanged | B005 scope | unchanged | verify-only boundary |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x004f9d30` | zero inbound xrefs | retained constructor; confidence cap, not no-code proof |
| `0x004fa0b0` | zero xrefs; no function | compiler cleanup island |
| `0x004fa0f0` | sole data xref `0x0061d35c` | secondary EventHandler packet-family slot `+0x10`; source override is `HandlePacketEvent(Event *)` |
| `0x004fa120` | data xref `0x0061d334` | primary virtual command handler |
| `0x004fa150` | data xref `0x0061d338` | primary virtual button-state updater |
| `0x004fa1d0` | code call `0x004fa144` from command | private submit method |
| `0x004fa3a0` | code call `0x004fa392` from submit | file-local request helper |
| `0x004fa5b0` | sole code tail call `0x004fa111` from packet virtual | private reply method; no conversion-helper route |
| `0x0061d2ec` | stores at ctor `0x4f9db8`, raw `0x4fa0b3`, dtor `0x502976` | primary vtable lifecycle symmetry |
| `0x0061d34c` | stores at `0x4f9dbe`, `0x4fa0b9`, `0x50297c` | secondary vtable lifecycle symmetry |
| `0x0061d37c` | stores at `0x4f9dc8`, `0x4fa0c3`, `0x502986` | tertiary vtable lifecycle symmetry |
| `0x0069b480` | refs `0x4f9d91`, `0x4f9d98`, `0x4fa0df`, `0x5023f0`, `0x5029a2` | exact singleton publish/fallback/three clears |
| `0x005023f0` | sole code xref `0x006016d4` from constructor EH | compiler unwind clear helper |
| `0x0050250e/19` | vtable refs `0x61d34c/7c`, jumps to `0x502970` | receiver-adjusting destructor thunks |
| `0x00502970` | thunks `0x502514/1f`, primary vtable `0x61d2ec` | routed destructor anchor |

## Documentation Evidence And IDA Status

- Historical pre-repair state: UID0002Q3 and UID00009D already contained accurate split, broad behavior, and vtable/singleton facts, but their UID0004PD links/declaration still used the rejected source identity. Current UID0002Q3 and UID00009D now use the validated `HandlePacketEvent(Event *)` contract after validators `000000011682` and `000000011677`.
- UID0000LV already supplies the correct generated file root and singleton declaration, but its standalone-vs-folded ambiguity is resolved to standalone.
- Historical pre-callback state: UID0000KX used stale `class_NewUserDialogPane.cpp` wording. Validator `000000011595` replaced only that NewUser route with `login/NewUserDialogPane.cpp`; UID0000KX remains a family index and does not become the direct owner.
- UID00019I and UID00025Q are legitimate non-emitting broad indexes; they need exact child links without score/owner/formal changes.
- UID00029H and UID0002X9 preserve important session-qualified storage history. Only lifecycle route wording/link detail changes; the singleton declaration stays exactly as present.
- UID00028Q preserves its broad consumers and now includes the concrete success-path `SetLogData(accountName)` call with no metadata change.
- Historical pre-callback generated command `000000011542` proved UID0002X9 routing worked while class and aggregate were empty. Implemented split routing at B004 command `000000011608`, reconfirmed after external command `000000011617`, fixed the structural cause without an aggregate pseudo-body but retained the two semantic defects. Current waited command `000000011691` supplies the fresh corrected semantic proof.

## Ranked Ownership Analysis

### 1. NewUserDialogPane class plus dedicated NewUserDialogPane file

- Evidence for: exact NewUser vtables; constructor/destructor/singleton symmetry; class-sized allocation; virtual slots; dedicated controls/resources; existing UID00009D/UID0000LV route; one file-local packet sender adjacent to member methods.
- Evidence against: constructor has no current direct caller and original file manifest/symbols are absent.
- Decision: accepted. No-route makes this a retained legacy class, not ownerless data.

### 2. LoginDialogPane family/file as umbrella

- Evidence for: physical adjacency, common account packet APIs, main-menu lifecycle, and existing UID0000KX family page.
- Evidence against: separate class/vtables/singleton/resource/helper and existing dedicated file root; B005 owns successor class.
- Decision: retain as family/index context only. Correct the stale NewUser route row but do not move ownership.

### 3. PacketBuffer/Socket/Config/AlertPane/ScreenDimmer dependencies

- Evidence for: request serialization, sender call, config success write, alert creation, and dimmer lifecycle are material dependencies.
- Evidence against: none receives `this`, owns the vtables, builds the dialog, or owns the complete feature flow.
- Decision: reject as direct owners; verify support only.

### 4. No-owner/non-emitting or one decompiler aggregate

- Evidence for: constructor no-route and current aggregate blank body.
- Evidence against: seven exact source functions, strong class/file route, and complete source forms.
- Decision: reject for source children. Only compiler/data children and parent index are non-emitting.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: existing [UID:0000LV] `NewUserDialogPane`, `NexusTK/login/NewUserDialogPane.cpp`.
- Likely full contents: existing singleton declaration, file-local request helper, class declaration, constructor/destructor, `HandlePacketEvent(Event *)`, control command, button updater, submit, and reply method.
- Related items that belong: thirteen exact children listed above; only eight source bodies emit.
- Rejected: LoginDialogPane methods, NewUserMiscDialogPane methods, create-character variants, PacketBuffer internals, compiler cleanup/thunks/table/vtable bytes.
- Source-file inference: narrow standalone feature file, not a broad account umbrella.

## Source Placement

- Recommended placement: class/header identity `NewUserDialogPane`; implementation `NexusTK/login/NewUserDialogPane.cpp` through existing UID0000LV.
- Direct file ordering: file-local `SendCreateAccountRequest` at file emitter position 1; class declaration follows existing scan/order; class `[[CHILDREN]]` receives constructor position 1, destructor 2, EventHandler packet virtual 3, command 4, updater 5, submit 6, and reply 7.
- The class managed block closes `};` before `[[CHILDREN]]`; this prevents malformed generated source.
- Rejected placement: folded `LoginDialogPane.cpp`, `CreateUserDialogs.cpp`, PacketBuffer.cpp, Socket.cpp, Config.cpp, or a one-function protocol file.
- Remaining bounded uncertainty: exact original filename capitalization and helper spelling are inferred, but the existing project route and source cluster make the selected placement implementation-ready.

## Range / Split / Padding / Reclassification Analysis

| Exact range | Size | SHA256 / bytes | Classification |
| --- | ---: | --- | --- |
| `4f9d30-a0a9` | `0x379` | `3a110b170517fa4a78338509feb4dc1e72aecf24d798f3f84b49abcb9889b171` | source constructor |
| `a0a9-a0b0` | 7 | seven `cc` | padding |
| `a0b0-a0ef` | `0x3f` | `3cc08bce1a118a9aed284f78d50ce70f3691f2a34cd72f7dc6d7d682c572e854` | compiler cleanup |
| `a0ef-a0f0` | 1 | `cc` | padding |
| `a0f0-a116` | `0x26` | `c3d67e221eee27a9e26679e41bb0db3d93c282b7d972004604dbed6eca1fd300` | source event bridge |
| `a116-a120` | 10 | ten `cc` | padding |
| `a120-a14e` | `0x2e` | `385a29ef6011ffcda45bc154bbd5692e700e23464b28910e33a6d0915d6f0439` | source command |
| `a14e-a150` | 2 | two `cc` | padding |
| `a150-a1c9` | `0x79` | `c902fba6017db9f990e1058e45bed6406398e1000b06d9b2390b60f8c5c41ad6` | source updater |
| `a1c9-a1d0` | 7 | seven `cc` | padding |
| `a1d0-a39c` | `0x1cc` | `162f169a122292843b85db9564fc9c7a1670bfc3fc252ae4012255907f827087` | source submit |
| `a39c-a3a0` | 4 | four `cc` | padding |
| `a3a0-a5a5` | `0x205` | `15ce581553ecc9a719e539a067b57cdcf26754ed6e9fa605efaf5b11ecdc5fdb` | source file helper |
| `a5a5-a5b0` | 11 | eleven `cc` | padding |
| `a5b0-a773` | `0x1c3` | `35a523243563535218f4aa1fedc5eeb3293bbd4e6ce759cc46174e415dde624d` | source reply |
| `a773-a793` | `0x20` | `340a5216f250221ce1ee42758b7f77b70b0291c2ae8b3d8fa42cb6662f6d32bb` | compiler switch table |
| `a793-a7a0` | 13 | thirteen `cc` | padding before Login |

- Parent impact: UID0002Q3 becomes a false/non-emitting documentation index. It keeps every exact boundary, hash, behavior, history, and child link but cannot own child C++.
- Child impact: thirteen new pages are necessary because target-range methods, file helper, compiler artifacts, destructor support, and vtable data have distinct owner/emitter/reconstruction rules.
- Padding impact: ten exact spans go to `by-memory/-ignored.md`; no padding emitter or C++ comment is generated.
- Successor: `0x004fa7a0` remains exact UID0002Q4 start and outside B004 implementation ownership.

## Negative Evidence Summary

- No direct call/data xref reaches the constructor; no direct xref, function object, or vtable slot reaches raw cleanup.
- No direct evidence makes raw cleanup a second human destructor. Routed scalar entry and two adjustors account for runtime destruction.
- No receiver or vtable route makes `SendCreateAccountRequest` a class member.
- No evidence makes the reply table source-authored static data; it is local compiler lowering for one switch.
- No derived storage access supports invented child fields. Child controls remain retrieved through inherited control IDs.
- Proximity to LoginDialogPane does not override dedicated class/file/singleton/vtable ownership.
- PacketBuffer, Socket, Config, AlertPane, ScreenDimmer, LanguageMan, MainUiLayerSlots, and MainMenuPane are dependencies/consumers, not direct owners.
- Historical `g_pMainUiGraph`, raw IDA names, decompiler integer/pointer prototypes, and `class_NewUserDialogPane.cpp` are not current source-facing authority.
- The superseded historical UID0004PD `PacketEvent` type/name has no current Event/EventHandler declaration and does not override the established slot; it is rejected, not retained as an alias.
- The superseded historical UID0004PI `SimpleUString` conversion has no call or inlined-helper proof. It is rejected because it can alter direct fixed-buffer conversion and failure/termination behavior.
- At the report-search evidence time, no active-root, archived, Older-Research, or SpecialReports artifact independently covered UID0002Q3; prior reports were support leads only.

## IDA Rename / Type / Comment Recommendations

- Source-facing names: `NewUserDialogPane`, `HandlePacketEvent`, `OnControlCommand`, `UpdateCreateUserButtonEnabledState`, `SubmitCreateUser`, `SendCreateAccountRequest`, and `HandleCreateUserReply`.
- Source-facing types: `Event *event`, `event->m_payload.m_packet.m_data`, `const unsigned char *packet`, `char[256]` reply text, `wchar_t[256]` converted reply text, `wchar_t[16]` form fields, `ImageButtonControlPane *`, `TextEditControlPane *`, `NewUserDialogPane *g_pNewUserDialogPane`, and inherited `DialogPane` storage.
- Source-facing globals/helpers: `g_pLanguageMan`, `g_mainUiLayerSlots.overlayPaneLayerContext`, `g_pMainMenuPane`, `g_pScreenPane`, `g_pScreenDimmer`, `g_pConfig`, `g_packetSender`, `kDialogOkButtonText`, `PacketBufferWriteUInt8`, and `QueueAndSendPacket`.
- Preserve exact numeric packet/status/control values. Original enum constant names are not proven, so the destination code uses numeric cases rather than inventing false symbols.
- Do not retain IDA labels `sub_4F9D30`, `sub_4FA*`, `unk_69B480`, `unk_69AE08`, `dword_67A7C8`, `dword_67A7EC`, `off_613A18`, decompiler temporaries, or raw object offsets in emitted source.
- No IDA database rename/type/comment mutation was performed or required. The accepted names/types/comments were applied only to documentation/formal reconstruction destinations.

## First-Draft C++ Recommendation

- Eligible source destinations: constructor, event bridge, command handler, button-state updater, submit method, request helper, reply method, and ordinary destructor anchor.
- No-code destinations: split parent, raw cleanup, reply table, singleton unwind clear, adjustor thunks, and vtable data. Their blank blocks are deliberate and paired with exact compiler/data proof.
- Formal destination count: fifteen complete managed blocks: parent, class, nine target-range children, and four lifecycle/vtable children. All thirteen child destinations are registered under the real UID map in the Function / Child Inventory.
- Behavior: the blocks omit compiler vptr writes, EH state, stack cookies, deleting flags/free, adjustor arithmetic, table bytes, and `return this`, while preserving every source-visible branch, packet byte, control ID, order, capacity, and side effect.
- Bounded callback status: Destinations 2, 5, and 10 below are the corrected report-managed blocks and now match their named ordinary destinations. Destination 5 was applied through the one-time UID-preserving old-path-to-new-path rename and normal file validation; validators and generated proof are recorded below.

### Destination 1 - UID0002Q3 split parent (blank)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - `by-class/NewUserDialogPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class NewUserDialogPane : public DialogPane
{
public:
    NewUserDialogPane();
    virtual ~NewUserDialogPane();

protected:
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateCreateUserButtonEnabledState();

private:
    void SubmitCreateUser();
    bool HandleCreateUserReply(const unsigned char *packet);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - `by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewUserDialogPane::NewUserDialogPane()
    : DialogPane(g_pLanguageMan->GetString(89), static_cast<unsigned short>(-1), true)
{
    RectBounds bounds;

    g_pNewUserDialogPane = this;

    InitRectBounds(&bounds, 0, 0, 316, 202);
    AddControl(new EPFImageControlPane(L"DLGNEW01.EPF", 0, 1, &bounds, NULL));

    InitRectBounds(&bounds, 82, 138, 154, 154);
    AddControl(new ImageButtonControlPane(14, &bounds));

    InitRectBounds(&bounds, 159, 138, 231, 154);
    AddControl(new ImageButtonControlPane(22, &bounds));

    InitRectBounds(&bounds, 134, 48, 253, 60);
    AddControl(new TextEditControlPane(L"", true, 128, 143, &bounds,
                                       false, false, false, false, 1.0f, 0));

    InitRectBounds(&bounds, 134, 65, 253, 77);
    TextEditControlPane *passwordControl =
        new TextEditControlPane(L"", true, 128, 143, &bounds,
                                false, false, false, false, 1.0f, 0);
    AddControl(passwordControl);
    passwordControl->EnableMaskedText();

    InitRectBounds(&bounds, 134, 82, 253, 94);
    TextEditControlPane *confirmationControl =
        new TextEditControlPane(L"", true, 128, 143, &bounds,
                                false, false, false, false, 1.0f, 0);
    AddControl(confirmationControl);
    confirmationControl->EnableMaskedText();

    SetHoverControl(3);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGNEW01.EPF", NULL);
    SetMode(1);

    InitRectBounds(&bounds, 324, 191, 640, 393);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pMainMenuPane);
    SlideOpenVertical();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - `by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md` (blank)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID-preserving rename from `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneOnCreateUserReplyEvent.md` to `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet[0] != 2) {
        return false;
    }

    return HandleCreateUserReply(packet);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - `by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 1) {
        SubmitCreateUser();
    } else if (controlIndex == 2) {
        SlideCloseVertical();
        CloseDialog();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - `by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane::UpdateCreateUserButtonEnabledState()
{
    ImageButtonControlPane *createButton = GetChild<ImageButtonControlPane>(1);

    if (GetChild<TextEditControlPane>(3)->IsEmpty() ||
        GetChild<TextEditControlPane>(4)->IsEmpty() ||
        GetChild<TextEditControlPane>(5)->IsEmpty()) {
        createButton->Disable();
    } else {
        createButton->Enable();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - `by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t passwordConfirmation[16];

    GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
    GetChild<TextEditControlPane>(4)->ReadText(password, 15);
    GetChild<TextEditControlPane>(5)->ReadText(passwordConfirmation, 15);

    bool containsDigit = false;
    for (const wchar_t *cursor = password; *cursor != L'\0'; ++cursor) {
        if (*cursor >= L'0' && *cursor <= L'9') {
            containsDigit = true;
            break;
        }
    }

    if (!containsDigit) {
        SetHoverControl(4);
        new AlertPane(L"password must containt at least 1 number",
                      this,
                      kDialogOkButtonText,
                      NULL);
        return;
    }

    if (wcscmp(password, passwordConfirmation) != 0) {
        SetHoverControl(4);
        new AlertPane(g_pLanguageMan->GetString(90),
                      this,
                      kDialogOkButtonText,
                      NULL);
        return;
    }

    new ScreenDimmer(5, g_pScreenPane);
    SendCreateAccountRequest(accountName, password, L"");
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - `by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendCreateAccountRequest(
    const wchar_t *accountName,
    const wchar_t *password,
    const wchar_t *profileText)
{
    char packet[0x100];
    char converted[0x100];

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short passwordLength = static_cast<short>(wcslen(password));
    short profileTextLength = static_cast<short>(wcslen(profileText));

    PacketBufferWriteUInt8(2, packet);

    int accountNameByteLength = WideCharToMultiByte(
        0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100) {
        __report_rangecheckfailure();
    }
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    unsigned int packetLength =
        static_cast<unsigned int>(accountNameByteLength + 2);

    int passwordByteLength = WideCharToMultiByte(
        0, 0, password, passwordLength, converted, 0x100, NULL, NULL);
    if (passwordByteLength >= 0x100) {
        __report_rangecheckfailure();
    }
    converted[passwordByteLength] = 0;
    PacketBufferWriteUInt8(passwordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, passwordByteLength);
    packetLength += static_cast<unsigned int>(passwordByteLength + 1);

    int profileTextByteLength = WideCharToMultiByte(
        0, 0, profileText, profileTextLength, converted, 0x100, NULL, NULL);
    if (profileTextByteLength >= 0x100) {
        __report_rangecheckfailure();
    }
    converted[profileTextByteLength] = 0;
    PacketBufferWriteUInt8(profileTextByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, profileTextByteLength);
    packetLength += static_cast<unsigned int>(profileTextByteLength + 1);

    if (packetLength >= 0x100) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength + 1));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10 - `by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserDialogPane::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];

    if (result != 0) {
        if (g_pScreenDimmer != NULL) {
            delete g_pScreenDimmer;

            switch (result) {
            case 3:
            case 4:
            case 14:
            case 16:
            case 17:
            case 18:
            case 20:
            case 21:
                SetHoverControl(3);
                break;

            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 15:
                SetHoverControl(4);
                break;

            default:
                break;
            }

            char narrowText[256];
            wchar_t wideText[256];
            const unsigned int textLength = packet[2];

            memmove(narrowText, packet + 3, textLength);
            narrowText[textLength] = '\0';

            const unsigned char wideLength = static_cast<unsigned char>(
                MultiByteToWideChar(
                    CP_ACP, 0, narrowText, textLength, wideText, 256));
            wideText[wideLength] = L'\0';
            if (wideText[0] != L'\0') {
                new AlertPane(wideText, this, kDialogOkButtonText, NULL);
            }
        }

        return true;
    }

    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    SlideCloseVertical();
    CloseDialog();

    wchar_t accountName[16];
    GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
    g_pConfig->SetLogData(accountName);

    new NewUserMiscDialogPane;
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11 - `by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md` (blank)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12 - `by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md` (blank)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 13 - `by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md` (blank)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 14 - `by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewUserDialogPane::~NewUserDialogPane()
{
    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    g_pNewUserDialogPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 15 - `by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md` (blank)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- UID0002Q3 has the accepted false/non-emitting split-index metadata with all exact range/hash/behavior/history evidence preserved; the split itself is unchanged by this report-only repair.
- The thirteen exact child pages were registered in ascending address order as UID0004PB/PC/PD/PE/PF/PG/PH/PI/PK/PL/PM/PO/PP before cross-linking; every temporary token was replaced.
- All fifteen managed blocks remain complete in this report, and no draft/example source exists outside formal blocks. The prior callback applied the structural set, and the completed bounded callback subsequently applied corrected Destinations 2, 5, and 10, superseding the rejected source forms; their scoped-validator and generated proofs are recorded below.
- UID00009D/UID0000LV retain the prior callback's class/file source and exact child inventory with the bounded UID0004PD declaration/link and UID0004PI source-shape corrections applied. UID00019I, `by-memory/-ignored.md`, and UID0004PP carry only the accepted bounded synchronization. UID00025Q, UID00029H, UID0002X9, UID00028Q, and UID0000KX retain their accepted detail unchanged.
- UID0002Q4/Login source methods and Event/EventHandler/DialogPane/control/packet/global dependencies remained read-only. Generated output and manual coverage were read-only; no validator or generated refresh ran during this report-only repair.
- No research question or implementation item remains unresolved. Ordinary UID0004PD/UID0004PI/class/reverse-link corrections and fresh validation are complete. Original symbol/file-manifest absence remains a documented confidence cap, not a blocker.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md`.
- Metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000LV`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, exact blank Destination 1 block, `Nested:4`.
- Item Summary: reviewed non-emitting split index for seven source-authored target functions, one compiler cleanup island, one compiler switch table, eight local padding spans, and linked lifecycle/vtable children; exact children own source/no-code disposition.
- The broad reconstructable/entity wording was replaced with the exact inventory, hashes, CFG, callers/callees, vtable/singleton lifecycle, packet formats, controls/resources, retained constructor route, source placement, rejected alternatives, and compiler exclusions from this report.
- Preserve historical evidence: old page scores, previously corrected padding boundary, prior hidden-cleanup discovery, earlier no-final-name reasoning as historical, and the `g_pMainUiGraph` alias correction.
- Registered target-range child metadata follows the Function / Child Inventory exactly. All use `Nested:0`; false children have blank emitter/position/formal C++.
- Applied bounded repair: preserved UID0004PD while moving its old path once to `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md`; applied corrected Destinations 2/5/10; updated only target, file, current UID00019I aggregate, vtable, ignored, and validator-managed reverse links that named the stale path; retained all scores, owners, emitters, positions, ranges, nesting, and unrelated source.

## Recommended Support Doc Changes

| Support path | Exact change | Score/formal impact |
| --- | --- | --- |
| `by-class/NewUserDialogPane.md` | Preserved the prior complete class/inventory and replaced only the stale `PacketEvent` declaration/virtual with corrected Destination 2: forward-declare `Event` and override `HandlePacketEvent(Event *)`. | retained `92/94`; owner/emitter 0000LV unchanged; validator `000000011677`. |
| UID0004PD old path -> `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md` | Applied UID-preserving validator-managed rename, corrected Destination 5, and full EventHandler `+0x10`, Event payload `+0x0c`, opcode, receiver-adjustment, tail-call, sibling, negative, and historical evidence. | retained `90/93`, owner/emitter 00009D, true, position 3, `Nested:0`; validator `000000011674`. |
| UID0004PI `NewUserDialogPaneHandleCreateUserReply` | Preserved all status/dimmer/success behavior and replaced only `SimpleUString` with corrected Destination 10's exact 256-narrow/256-wide direct conversion and termination. | retained `92/94`, owner/emitter 00009D, true, position 7, `Nested:0`; validator `000000011679`. |
| `by-file/NewUserDialogPane.md` | Preserved standalone route and all content; renamed the UID0004PD row/link to `HandlePacketEvent`, and recorded UID0004PI direct fixed-buffer conversion. | retained `91/92`; path/FILE unchanged; validator `000000011684`. |
| `by-file/LoginDialogPane.md` | Replaced only stale NewUser `class_NewUserDialogPane.cpp` row with standalone `login/NewUserDialogPane.cpp`; retained family/index and all B005 content. | score/formal unchanged `88/86`. |
| UID00019I `MainMenuLoginAndAccountDialogs` | Replaced NewUser aggregate row with non-emitting index plus real child links; preserved all other children. | unchanged `85/88`, false. |
| UID00025Q `MainMenuNewUserReadOnlyData` | Added exact NewUser vtable child `[61d2ec,61d384)` and successor Login boundary. | unchanged `86/92`, false. |
| UID00029H `MainMenuAccountDialogSingletons` | Added exact constructor/raw/EH/destructor routes and distinguished compiler raw cleanup from source destructor anchor. | unchanged `91/93`, false. |
| UID0002X9 `g_pNewUserDialogPane` | Preserved declaration/storage discrepancy and score; added real child links. | unchanged `88/90`, existing C++ unchanged. |
| UID00028Q `g_pConfig` | Added reply-success consumer `g_pConfig->SetLogData(accountName)` from UID0004PI. | unchanged `86/90`, formal unchanged. |
| UID0002Q3 / UID00019I / UID0004PP | Preserved split/aggregate/vtable evidence and replaced stale UID0004PD link/name with the corrected HandlePacketEvent path/slot contract; added only bounded fixed-buffer detail where required. | scores/metadata/formals otherwise unchanged; validators `11682/11687/11688`. |
| `by-memory/-ignored.md` | Preserved ten exact padding spans and compiler/data rows; updated the UID0004PD neighboring-path link and bounded UID0004PI conversion detail after validator-managed rename. | meta/list only; validator `000000011690`. |
- Verify-only and unchanged: UID0002Q4/Login class, DialogPane, Pane, TextEditControlPane, EPFImageControlPane, ImageButtonControlPane, AlertPane, ScreenDimmer, PacketBuffer, QueueAndSendPacket, g_packetSender, g_pLanguageMan, g_pScreenPane, g_pScreenDimmer, g_pMainMenuPane, MainUiLayerSlots, and NewUserMiscDialogPane. No validator-managed reverse-reference propagation changed those source-method pages.
- Current Event/EventHandler/DialogPane/Login documents remain verify-only direct evidence and required no change. Shared-page work was limited to stale NewUser-specific links after reread/rebase; B005-owned Login source pages remained untouched.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Current metadata / corrected recommendation | Owner / emitter / reconstructable / position / nesting |
| --- | --- | --- | --- |
| UID0002Q3 parent | `86/90` | `92/94` | `0000LV` / blank / false / blank / `Nested:4` |
| UID00009D class | `86/90` | `92/94` | `0000LV` / `0000LV` / true / blank |
| UID0000LV file | `86/88` | `91/92` | FILE; `NexusTK/login/` unchanged |
| Seven target source children | absent | UID0004PB/PD/PE/PF/PG/PH/PI are applied; UID0004PD retains `90/93` at the corrected path/formal contract and UID0004PI retains `92/94` with direct conversion | class/file routes and positions in inventory; `Nested:0` |
| Raw/table target children | absent | UID0004PC `90/94`, UID0004PK `92/94` | false; raw owner none, table owner 00009D; no emitters |
| EH/thunk/vtable children | absent | UID0004PL `90/94`, UID0004PM `91/94`, UID0004PP `91/94` | false; no emitters; vtable owner 00009D |
| Destructor anchor | absent | UID0004PO `92/94` | owner/emitter 00009D, true, position 2, `Nested:0` |

- Completion rationale: all exact subranges, source/compiler dispositions, ABI, CFG, xrefs, callers/callees, packet bytes, controls, resources, globals, source placement, names/types, corrected formal C++, padding, coverage text, and bounded support changes are resolved and applied. Parent completion 92 reflects a complete split index, not source-body ownership. The two ordinary semantic corrections required no score changes and are now validated.
- Confidence rationale: exact binary facts and ownership are very strong. Scores remain below 95 because original symbols/source manifest are unavailable, constructor has no direct live route, and some source-facing spellings are inferred from sibling contracts.
- Score-blocker audit:
  - Broad mixed island: resolved by exact split and hashes.
  - Hidden cleanup form: resolved compiler-no-code with routed destructor anchor.
  - Constructor route: exhaustive zero-xref check retained as confidence cap, not unresolved work.
  - Method/helper names: resolved by base virtual slots, sibling Login/CreateUser naming, ABI, and role.
  - Packet virtual contract: resolved to `HandlePacketEvent(Event *)` by current EventHandler/Login declarations, vtable slot, and exact Event `+0x0c` payload read; `PacketEvent` is rejected.
  - Packet shape: resolved byte for byte including final sent zero and dimmer-gated reply branch.
  - Reply text source shape: resolved to direct fixed `char[256]`/`wchar_t[256]`, exact-length copy, explicit terminators, and `MultiByteToWideChar(CP_ACP,...)` with the result narrowed to one byte before the wide terminator store; `SimpleUString` is rejected.
  - Class layout: resolved no-new-field inherited size.
  - Source placement: resolved standalone existing file route; original manifest absence caps confidence only.
  - Empty marker: resolved structurally by parent false and exact emitting children.
- No unchanged-score exception is used for the target/class/file. Support scores remain unchanged only where this target adds a bounded link/consumer fact and does not improve the support page's broader unresolved scope.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution | Remaining impact |
| --- | --- | --- | --- |
| Is constructor dead/padding? | function body, resources, vtables, singleton, successor family, xrefs | retained old source constructor with zero current route | confidence cap only |
| Is raw cleanup handwritten? | no function/xrefs/pointers, exact instructions, scalar destructor parity, sibling precedent | compiler non-deleting cleanup; blank | none |
| What are method names? | current EventHandler virtual family, vtable slots, base APIs, Login sibling names, call roles | packet virtual is exact `HandlePacketEvent(Event *)`; remaining recommended names stay as documented | only non-interface private spellings retain confidence cap |
| Where is the event packet pointer? | current Event layout, dispatcher contract, Login sibling, target disassembly | `event->m_payload.m_packet.m_data` at exact `Event +0x0c`; byte `+0x08` is packet kind | none |
| Is request helper a member? | ABI, no receiver, sole caller, adjacency | file-local `static __stdcall` helper | none |
| What is request format? | full decompile/bytes and PacketBuffer APIs | opcode 2, three MBC length fields, final zero sent | none |
| Does error handling run without dimmer? | reply CFG | no; nonzero focus/message branch is dimmer-gated | exact formal branch preserved |
| Is a `SimpleUString` helper source-equivalent? | fresh stack frame, decompile/disassembly including `movzx eax,al`, callees, Login sibling | no evidence; direct fixed buffers/copy/conversion/low-byte returned-length terminator are the highest-probability and edge-faithful human source | none; corrected formal body required |
| Does class add fields? | allocation size and all accesses | no; inherited DialogPane size `0x26c` | none |
| Which destructor representation emits? | primary/secondary/tertiary routes and raw copy | one ordinary body on scalar anchor | none |
| Is source folded into Login? | existing file roots, dedicated cluster, sibling split, evidence-time B005 scope | standalone NewUserDialogPane.cpp | filename confidence cap |
| Does `Nested:4` count children? | validator README and split examples | no; relative delta retained | none |
| Can original enum names be recovered? | strings, symbols, docs, sibling code | no safe exact enums; numeric cases are behavior-identical and non-decompiler-shaped | confidence cap, no C++ blocker |

No investigable in-scope question or implementation item remains deferred. Further original-name certainty would require unavailable original source/PDB/project files; current evidence supports the corrected implementation, which is now applied and validated in ordinary docs.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only rows inspected:

- `by-memory/-coverage-report.md`: UID00019I line 1973, UID0002Q3 line 1994, UID00025Q line 3419, UID00028Q line 3645, UID00029H line 3760, UID0002X9 line 3761 at evidence time.
- `by-class/-coverage-report.md`: UID00009D line 360.
- `by-file/-coverage-report.md`: UID0000KX line 150 and UID0000LV line 184.
- Existing manual rows remain stale relative to implemented scores, split inventory, false/reconstructable disposition, standalone source route, exact vtable child, singleton lifecycle wording, and config consumer detail. Manual coverage therefore is not `not applicable`.
- B004 did not edit these files. The exact rows below now contain real UIDs for external supervisor-owned application; validator-generated coverage does not satisfy this manual row work.

Exact existing-row replacements:

```text
by-file/-coverage-report.md - replace UID0000LV row:
- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) : reconstructable : 91% : very-strong : Standalone NexusTK/login/NewUserDialogPane.cpp account-registration source root with exact class, singleton, constructor/destructor, EventHandler HandlePacketEvent, command/button-state/submit/reply methods, file-local SendCreateAccountRequest, direct fixed-buffer reply conversion, compiler-support exclusions, retained constructor route, and complete packet/control/source-placement evidence.

by-file/-coverage-report.md - replace UID0000KX row without changing score:
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) : reconstructable : 88% : strong : Login/account family index with LoginDialogPane.cpp ownership and source-ready SendLoginRequest; the older account-registration class is a separate NexusTK/login/NewUserDialogPane.cpp source root rather than stale class_NewUserDialogPane.cpp output, while adjacent UID0002Q4 remains independently owned.

by-class/-coverage-report.md - replace UID00009D row:
- [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md) : reconstructable : 92% : very-strong : Source-ready inherited-size account-registration class with complete declaration, exact constructor/destructor/HandlePacketEvent/command/button-state/submit/reply children, Event payload pointer at +0x0c, direct fixed-buffer reply conversion, file-local request-helper relationship, vtable/singleton lifecycle, packet/control/resource behavior, retained-route caveat, and compiler cleanup/table/thunk/vtable exclusions.

by-memory/-coverage-report.md - replace UID00019I row:
    - [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md) 0x004f6700-0x004fb62a | mixed login/account split index | MainMenuLoginAndAccountDialogs : ignored : 85% : strong : Reviewed mixed-owner MainMenu/NewUser/Login account range; exact children carry source ownership, including UID0002Q3 as a non-emitting NewUser split index and independently owned UID0002Q4 Login successor, while parent-only tables/padding remain documented.

by-memory/-coverage-report.md - replace UID0002Q3 row:
        - [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md) 0x004f9d30-0x004fa7a0 | non-emitting split index | NewUserDialogPaneCoreAndPacketHelpers : ignored : 92% : very-strong : Exact reviewed index for seven source-authored target functions, including EventHandler HandlePacketEvent and direct fixed-buffer reply conversion, compiler cleanup and switch-table children, eight local padding spans, and linked unwind/thunk/destructor/vtable support; exact children own all source emission and compiler exclusions.

by-memory/-coverage-report.md - replace UID00025Q row:
    - [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) 0x0061d264-0x0061e5b4 | mixed read-only data index | MainMenuNewUserReadOnlyData : ignored : 86% : very-strong : Exact mixed-owner non-emitting index with current boundaries/resources and exact nested vtable children, including NewUserDialogPane vtable data 0x0061d2ec-0x0061d384 before the LoginDialogPane successor; each exact child carries its own owner and rebuild disposition.

by-memory/-coverage-report.md - replace UID00028Q row:
    - [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) 0x0067a7c8-0x0067a7cc | global pointer | g_pConfig : reconstructable : 86% : strong : Config/RegistryConfig singleton pointer with zero storage, 433 xrefs, lifecycle writes, broad consumers, and exact NewUserDialogPane success consumer g_pConfig->SetLogData(accountName) before NewUserMiscDialogPane creation.

by-memory/-coverage-report.md - replace UID00029H row:
    - [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) 0x0069b480-0x0069b490 | mixed global pointer cluster | MainMenuAccountDialogSingletons : ignored : 91% : very-strong : Non-emitting four-slot account-dialog singleton index with exact children; NewUserDialogPane lifecycle distinguishes constructor publish/fallback, compiler raw-cleanup and EH clears, and one routed source-destructor anchor while retaining session-qualified storage-byte history.

by-memory/-coverage-report.md - replace UID0002X9 row:
        - [UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) 0x0069b480-0x0069b484 | global pointer | g_pNewUserDialogPane : reconstructable : 88% : strong : Source-declared older account-registration singleton pointer emitted through UID0000LV; exact refs are constructor publish/fallback 0x004f9d91/98, compiler raw clear 0x004fa0df, constructor-EH clear 0x005023f0, and routed destructor clear 0x005029a2, with zero-fill recommendation and signature-layer FF conflict preserved.
```

The following rows now contain the exact validator-assigned UIDs. They remain supervisor-owned manual coverage text and were not applied by B004.

```text
Insert in by-memory/-coverage-report.md in address order under/after UID0002Q3:
        - [UID:0004PB][0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor](by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md) 0x004f9d30-0x004fa0a9 | constructor | NewUserDialogPaneConstructor : reconstructable : 91% : very-strong : Source-ready legacy NewUserDialogPane constructor with exact resource, controls, bounds, singleton, layer/main-menu attachment, inherited-size layout, and retained zero-direct-route evidence.
        - [UID:0004PC][0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland](by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md) 0x004fa0b0-0x004fa0ef | compiler cleanup | NewUserDialogPaneRawCleanupIsland : ignored : 90% : very-strong : No-function/no-xref compiler non-deleting cleanup copy with vptr restores, guarded dimmer delete, singleton clear, and base-teardown tail jump; ordinary source destructor emits once from the routed scalar anchor.
        - [UID:0004PD][0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent](by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md) 0x004fa0f0-0x004fa116 | class method | NewUserDialogPaneHandlePacketEvent : reconstructable : 90% : very-strong : Exact EventHandler packet-family override at secondary slot +0x10; reads Event::m_payload.m_packet.m_data at Event +0x0c, accepts opcode 2, adjusts only the secondary receiver through compiler ABI, and tail-forwards to HandleCreateUserReply.
        - [UID:0004PE][0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand](by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md) 0x004fa120-0x004fa14e | class method | NewUserDialogPaneOnControlCommand : reconstructable : 91% : very-strong : Source-ready virtual command handler; control 1 submits and control 2 slides closed then closes the dialog, with unused notify code and no base call.
        - [UID:0004PF][0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState](by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md) 0x004fa150-0x004fa1c9 | class method | NewUserDialogPaneUpdateCreateUserButtonEnabledState : reconstructable : 91% : very-strong : Source-ready virtual updater that disables create button 1 when any text control 3/4/5 is empty and enables it only when all are nonempty.
        - [UID:0004PG][0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser](by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md) 0x004fa1d0-0x004fa39c | class method | NewUserDialogPaneSubmitCreateUser : reconstructable : 92% : very-strong : Exact account/password/confirmation read, digit validation, exact typo alert, localized mismatch alert, screen dimmer creation, and file-local request-helper call.
        - [UID:0004PH][0x004fa3a0-0x004fa5a5.SendCreateAccountRequest](by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md) 0x004fa3a0-0x004fa5a5 | file-local helper | SendCreateAccountRequest : reconstructable : 92% : very-strong : Source-ready __stdcall account request encoder with opcode 2, three one-byte-length MBC fields, exact 256-byte conversion/range behavior, sent trailing zero, and g_packetSender queue route.
        - [UID:0004PI][0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply](by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md) 0x004fa5b0-0x004fa773 | class method | NewUserDialogPaneHandleCreateUserReply : reconstructable : 92% : very-strong : Source-ready reply handler with exact status/message layout, dimmer-gated nonzero focus/alert branch, direct char[256] copy/terminator plus wchar_t[256] MultiByteToWideChar(CP_ACP) conversion and unsigned-byte-narrowed returned-length terminator, success close/config SetLogData/NewUserMiscDialogPane handoff, and always-true return.
        - [UID:0004PK][0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable](by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md) 0x004fa773-0x004fa793 | compiler switch table | NewUserDialogPaneReplySwitchTable : ignored : 92% : very-strong : Exact NOP, three branch-target dwords, and compact status map generated for HandleCreateUserReply; no independent source body or emitter.

Insert in by-memory/-coverage-report.md at the exact address-sorted support positions:
    - [UID:0004PL][0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper](by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md) 0x005023f0-0x005023fb | compiler unwind helper | NewUserDialogPaneSingletonClearUnwindHelper : ignored : 90% : very-strong : Constructor-EH-only 11-byte helper that clears g_pNewUserDialogPane; no standalone source function.
    - [UID:0004PM][0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks](by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md) 0x0050250e-0x00502524 | adjustor thunks | NewUserDialogPaneDestructorAdjustorThunks : ignored : 91% : very-strong : Two exact compiler thunks subtracting 0xa0/0xa4 from secondary receivers before tail-jumping the routed destructor anchor.
    - [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md) 0x00502970-0x005029e1 | destructor anchor | NewUserDialogPaneDestructor : reconstructable : 92% : very-strong : Source-ready ordinary destructor semantics anchored at the scalar-deleting entry; deletes active dimmer and clears singleton while vptrs, base teardown, deleting flags, free, and adjustors remain compiler-generated.
    - [UID:0004PP][0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData](by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md) 0x0061d2ec-0x0061d384 | vtable data | NewUserDialogPaneVtableData : ignored : 91% : very-strong : Exact source-declared/compiler-generated primary, secondary, and tertiary NewUserDialogPane vtable views with destructor, command, updater, EventHandler HandlePacketEvent at secondary slot +0x10, and adjustor slots; ends before LoginDialogPane data.
```

## Follow-Up Actions

- Supervisor/validator-owned report validation, execution, count, move, archive, and manual-coverage state are external to this artifact and are neither asserted nor directed here.
- Historical callback fact: thirteen children were registered, every temporary UID was replaced, bounded target/support/ignored changes were made, ordinary validators passed, and structural generated readback passed. Gate 2 then rejected UID0004PD's source contract and UID0004PI's conversion source shape; the current bounded callback superseded those two historical semantics with validated corrected source.
- Shared-page coordination with the B005-owned adjacent assignment completed through serialized reread/rebase; neither agent owns the other's source-method pages, regardless of external lifecycle timing.
- A-agent action: none. No IDA mutation is required.
- Further research or implementation: none. UID0004PD UID-preserving rename/formal correction, UID0004PI formal correction, bounded class/target/file/aggregate/vtable/ignored synchronization, scoped validators, and waited generated semantic readback are complete. External supervisor/validator-owned report lifecycle and manual-coverage state are not tracked as pending work by this artifact.

## Confidence

- Recommendation confidence: `98/100` for the corrected EventHandler contract and fixed-buffer conversion; `94/100` remains appropriate for the broader split, source/compiler disposition, owners/routes, and source placement.
- Score confidence: `96/100`; implemented scores deliberately remain below final-audit 95 where original symbols/live constructor route are absent.
- Remaining uncertainty: exact original spellings/file manifest and whether the constructor had an indirect historical route removed from the current binary. Neither changes the strongest present source reconstruction.

## Validator Results

- Historical commands through `000000011608` remain exact proof of the original split callback; snapshots `11608/11617` are structural baselines only for the semantics later rejected by Gate 2. Current bounded-repair commands `000000011674` through `000000011691` provide the fresh ordinary and generated semantic proof.
- All commands were run from `source-3/project-documentation`. Current scoped ordinary validations used `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`, returned exit `0`, `ok:1`, and deferred generation except final target command `000000011691`, which added `--wait-generated` and completed the refresh. Every edited ordinary path held one short B004 lease for reread/edit/validation and was released immediately; the final no-edit waited target refresh required no edit lease. Command IDs are validator-owned; concurrent commands explain allocation/ID gaps.

| Command ID | Timestamp EDT | Scoped path / operation | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- |
| `000000011562` | `2026-07-14T13:20:36-04:00` | `by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md` | `0 / 1` | Allocated UID0004PB; deferred generated refresh; lease released. |
| `000000011563` | `2026-07-14T13:21:10-04:00` | `by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md` | `0 / 1` | Allocated UID0004PC; blank compiler-support block retained; lease released. |
| `000000011565` | `2026-07-14T13:21:39-04:00` | `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneOnCreateUserReplyEvent.md` | `0 / 1` | Allocated UID0004PD; lease released. |
| `000000011566` | `2026-07-14T13:22:05-04:00` | `by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md` | `0 / 1` | Allocated UID0004PE; lease released. |
| `000000011568` | `2026-07-14T13:22:34-04:00` | `by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md` | `0 / 1` | Allocated UID0004PF; lease released. |
| `000000011570` | `2026-07-14T13:23:17-04:00` | `by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md` | `0 / 1` | Allocated UID0004PG; lease released. |
| `000000011571` | `2026-07-14T13:23:56-04:00` | `by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md` | `0 / 1` | Allocated UID0004PH; lease released. |
| `000000011573` | `2026-07-14T13:24:32-04:00` | `by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md` | `0 / 1` | Allocated UID0004PI; lease released. |
| `000000011576` | `2026-07-14T13:25:04-04:00` | `by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md` | `0 / 1` | Allocated UID0004PK; blank compiler-data block retained; lease released. |
| `000000011577` | `2026-07-14T13:25:35-04:00` | `by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md` | `0 / 1` | Allocated UID0004PL; blank compiler-support block retained; lease released. |
| `000000011579` | `2026-07-14T13:26:04-04:00` | `by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md` | `0 / 1` | Allocated UID0004PM; blank compiler-support block retained; lease released. |
| `000000011582` | `2026-07-14T13:26:37-04:00` | `by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md` | `0 / 1` | Allocated UID0004PO; lease released. |
| `000000011584` | `2026-07-14T13:27:19-04:00` | `by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md` | `0 / 1` | Allocated UID0004PP; blank compiler-data block retained; lease released. |
| `000000011587` | `2026-07-14T13:28:45-04:00` | UID0002Q3 target split index | `0 / 1` | Applied `92/94`, false/non-emitting, real child map; lease released. |
| `000000011591` | `2026-07-14T13:29:50-04:00` | `by-class/NewUserDialogPane.md` | `0 / 1` | Applied `92/94` complete class block closed before `[[CHILDREN]]`; lease released. |
| `000000011594` | `2026-07-14T13:30:47-04:00` | `by-file/NewUserDialogPane.md` | `0 / 1` | Applied `91/92` standalone route and exact children; lease released. |
| `000000011595` | `2026-07-14T13:31:25-04:00` | `by-file/LoginDialogPane.md` | `0 / 1` | Rebased current B005 content; changed only stale NewUser route; lease released. |
| `000000011596` | `2026-07-14T13:35:08-04:00` | UID00019I `MainMenuLoginAndAccountDialogs` | `0 / 1` | Rebased shared page; added only NewUser exact-child section; lease released. |
| `000000011598` | `2026-07-14T13:36:02-04:00` | UID00025Q `MainMenuNewUserReadOnlyData` | `0 / 1` | Added UID0004PP range/boundary. Pre-existing unrelated `missing_ref_uid 00036V` warning; lease released. |
| `000000011600` | `2026-07-14T13:37:41-04:00` | UID00029H `MainMenuAccountDialogSingletons` | `0 / 1` | Added four lifecycle routes; validator canonicalized UID link labels and reverse references; lease released. |
| `000000011602` | `2026-07-14T13:38:45-04:00` | UID0002X9 `g_pNewUserDialogPane` | `0 / 1` | Added four lifecycle child links; declaration/score unchanged; lease released. |
| `000000011603` | `2026-07-14T13:39:11-04:00` | UID00028Q `g_pConfig` | `0 / 1` | Added UID0004PI consumer. Five pre-existing unrelated missing-ref warnings for UID0003UA/UID0003UJ; lease released. |
| `000000011605` | `2026-07-14T13:40:40-04:00` | `by-memory/-ignored.md` | `0 / 1` | Added ten padding spans/five compiler-data rows. Existing page produced 313 missing-ref warnings; validator canonicalized UID0004PH filename and added reverse refs; lease released. |
| `000000011608` | `2026-07-14T13:41:18-04:00` | UID0002Q3 scoped validation plus authorized `--wait-generated` | `0 / 1` | `generated_refresh:completed`. Project-wide existing generator diagnostics: 14 fallback child inserts, 84 missing preferred child markers, 189 emitters with no direct code; none is a UID0002Q3 failure. |
| `000000011674` | `2026-07-14T14:30:26-04:00` | One-time UID0004PD move to `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md`, corrected Destination 5, normal file validation | `0 / 1` | `path_update:1`; UID0004PD preserved; seven known reverse links updated across UID00009D, UID0000LV, UID00019I, UID0002Q3, and `by-memory/-ignored.md`; three reverse-source paths updated; 311 pre-existing `by-memory/-ignored.md` missing-ref diagnostics surfaced during propagation; generated deferred; old-path lease released. |
| `000000011677` | `2026-07-14T14:34:41-04:00` | `by-class/NewUserDialogPane.md` corrected Destination 2 | `0 / 1` | Exact `Event` declaration/`HandlePacketEvent(Event *)` applied; class remains closed before `[[CHILDREN]]`; score/owner/emitter unchanged; generated deferred; lease released. |
| `000000011679` | `2026-07-14T14:35:14-04:00` | UID0004PI `NewUserDialogPaneHandleCreateUserReply` corrected Destination 10 | `0 / 1` | Direct 256-narrow/256-wide conversion applied; branch order/score/owner/emitter unchanged; generated deferred; lease released. |
| `000000011682` | `2026-07-14T14:35:54-04:00` | UID0002Q3 target split-index semantic synchronization | `0 / 1` | Parent remains `92/94`, false/non-emitting, owner 0000LV, blank emitter/position/C++, `Nested:4`; generated deferred; lease released. |
| `000000011684` | `2026-07-14T14:36:21-04:00` | `by-file/NewUserDialogPane.md` bounded packet/reply detail synchronization | `0 / 1` | Standalone route and `91/92` score unchanged; generated deferred; lease released. |
| `000000011687` | `2026-07-14T14:37:02-04:00` | current UID00019I path `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | `0 / 1` | Updated only NewUser packet/reply details; retained `85/88`, false/non-emitting, owner, blank formal, `Nested:-4`, and all B005/unrelated content; projected stats row refreshed; generated deferred; lease released. The alternate path named in the callback goal did not exist; this was the unique current UID00019I destination. |
| `000000011688` | `2026-07-14T14:37:37-04:00` | UID0004PP `NewUserDialogPaneVtableData` slot-name synchronization | `0 / 1` | Added UID0004PD reverse reference; score/metadata/blank formal unchanged; generated deferred; lease released. |
| `000000011690` | `2026-07-14T14:38:14-04:00` | `by-memory/-ignored.md` corrected neighboring path/conversion detail | `0 / 1` | Existing 311 missing-ref diagnostics preserved; padding/compiler rows unchanged; generated deferred; lease released. |
| `000000011691` | `2026-07-14T14:38:28-04:00` | final UID0002Q3 scoped validation with authorized `--wait-generated` | `0 / 1` | `generated_refresh:completed`; project-wide diagnostics were 14 fallback child inserts, 84 missing preferred child markers, and 184 emitters with no direct code; 281 generated metadata files refreshed; none is a UID0002Q3 error. |

- B004 waited generated snapshot: `auto-generated/NexusTK/login/NewUserDialogPane.cpp`, header command `000000011608`, refresh `2026-07-14T13:41:18-04:00`, size `9145`, SHA256 `C89E20028DE414DF1962CAF2869A3F58F8547B742A9FFEE2045B04B0F1517661`.
- Later concurrent-refresh readback, time-scoped rather than asserted indefinitely: header command `000000011617`, refresh `2026-07-14T13:42:34-04:00`, read at `2026-07-14T13:42:47-04:00`, size `9145`, SHA256 `15984E68A6460E531846C22722824C9B3BFE1F7CCD57B527AF8B5C79FA9FF42C`; source counts and all negative checks below were unchanged.
- Historical structural counts under `11608/11617`: one `class NewUserDialogPane`; one each `SendCreateAccountRequest`, constructor, destructor, rejected `OnCreateUserReplyEvent`, `OnControlCommand`, `UpdateCreateUserButtonEnabledState`, `SubmitCreateUser`, and `HandleCreateUserReply`; one UID0002X9 singleton declaration. The historical old-name count remains explicit failure evidence, not current source authority.
- B004 waited generated snapshot: `auto-generated/NexusTK/login/NewUserDialogPane.cpp`, header command `000000011691`, refresh `2026-07-14T14:38:28-04:00`, foreground-generated-refresh, file last write `2026-07-14T14:38:38.3595162-04:00`, size `9498`, SHA256 `D904F8D4A9948019B6ED8B4D34D6A27EB420673521B8E7FCD324720D078954AA`.
- A later concurrent validator refresh preserved the generated source semantics. At final B004 readback time `2026-07-14T14:46:38-04:00`, the read-only file header named command `000000011692`, refresh `2026-07-14T14:39:19-04:00`, foreground-generated-refresh, file last write `2026-07-14T14:39:28.4025510-04:00`, size `9498`, and SHA256 `AC07C072C036B9CCADACF705017A2FB7A88F9D25B3C9C390878DDD238108E149`. This is evidence-time freshness, not a durable current-file assertion.
- Semantic counts under both B004 waited command `11691` and later readback `11692`: exactly one `bool NewUserDialogPane::HandlePacketEvent(Event *event)` definition; exactly one `event->m_payload.m_packet.m_data`; zero `OnCreateUserReplyEvent`; zero standalone `PacketEvent` token (the three `HandlePacketEvent` substrings are the declaration, UID path comment, and definition); exactly one `char narrowText[256]`; exactly one `wchar_t wideText[256]`; exactly one whitespace-normalized `MultiByteToWideChar(CP_ACP, 0, narrowText, textLength, wideText, 256)`; and zero `SimpleUString::FromMbcString`.
- Structural positives under both snapshots: one class declaration, one singleton declaration, and one each of `SendCreateAccountRequest`, constructor, destructor, `HandlePacketEvent`, `OnControlCommand`, `UpdateCreateUserButtonEnabledState`, `SubmitCreateUser`, and `HandleCreateUserReply`; the class closes before emitted child definitions.
- Negative checks under both snapshots: zero UID0002Q3 occurrence, zero `Empty Emitter Marker`, zero UID0004PC/PK/PL/PM/PP compiler-child body or marker, zero `RawCleanupIsland`/`ReplySwitchTable`/`SingletonClearUnwindHelper`/`DestructorAdjustorThunks`/`VtableData` source artifact, and no duplicate source definition.
- Validator errors: none. Warnings above are preserved with exact provenance and are unrelated/pre-existing or project-wide diagnostics; every historical and current scoped command returned `ok:1`, and current corrected semantic validation passed.

## Changed Files

- Historical Gate 2 report-only repair modified only this report. The current authorized bounded implementation repair changed only the ordinary destinations listed below plus this same report; generated and validator metadata changed only as validator-owned side effects.
- Current bounded repair renamed/modified ordinary pages:
  - moved once: `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneOnCreateUserReplyEvent.md` -> `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md` (UID0004PD; old path absent; validator `000000011674`)
  - `by-class/NewUserDialogPane.md` (UID00009D; validator `000000011677`)
  - `by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md` (UID0004PI; validator `000000011679`)
  - `by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md` (UID0002Q3; validators `000000011682/11691`)
  - `by-file/NewUserDialogPane.md` (UID0000LV; validator `000000011684`)
  - `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` (unique current UID00019I path; validator `000000011687`)
  - `by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md` (UID0004PP; validator `000000011688`)
  - `by-memory/-ignored.md` (validator `000000011690`)
- Historical prior callback created and validator-registered ordinary pages:
  - `by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md` (UID0004PB)
  - `by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md` (UID0004PC)
  - `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneOnCreateUserReplyEvent.md` (UID0004PD historical creation path, now renamed and absent)
  - `by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md` (UID0004PE)
  - `by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md` (UID0004PF)
  - `by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md` (UID0004PG)
  - `by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md` (UID0004PH)
  - `by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md` (UID0004PI)
  - `by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md` (UID0004PK)
  - `by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md` (UID0004PL)
  - `by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md` (UID0004PM)
  - `by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md` (UID0004PO)
  - `by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md` (UID0004PP)
- Historical prior callback modified ordinary pages: UID0002Q3 target; `by-class/NewUserDialogPane.md`; `by-file/NewUserDialogPane.md`; `by-file/LoginDialogPane.md`; UID00019I `MainMenuLoginAndAccountDialogs`; UID00025Q `MainMenuNewUserReadOnlyData`; UID00029H `MainMenuAccountDialogSingletons`; UID0002X9 `g_pNewUserDialogPane`; UID00028Q `g_pConfig`; and `by-memory/-ignored.md`.
- Modified agent artifact in this repair: this same report; the report itself was not moved or archived.
- Historical leases: one ordinary path at a time; the UID0002Q3 parent lease covered each serial new-child creation/validation window, and each pre-existing destination used its own short lease. All 23 historical windows ended in successful immediate release. Current bounded repair used eight one-file edit windows: old UID0004PD path, UID00009D, UID0004PI, UID0002Q3, UID0000LV, UID00019I, UID0004PP, and `by-memory/-ignored.md`; each was released immediately after its scoped validator. Final waited command `11691` was a no-edit validation after release. No B004 lease remains.
- Manual coverage, generated output, tracker, audit, supervisor, validator-state, lifecycle, queue/lock, archive, and IDA files were not manually edited by B004. Generated files and validator metadata changed only as validator-owned side effects of authorized scoped commands.
- Report execution/move/archive: B004 performed none.

## Implementation Tracking Checklist

Historical report-only gate and accepted callback:

- [x] Exact pre-callback report SHA256 `5DFAED97BCEECB401EC00A3B1812363B2F44409EC022A31B6C29DDF78A7A6DA4` passed supervisor Gate 1 before any ordinary by-* edit; external lifecycle state remains supervisor/validator-owned.
- [x] Re-read UID0002Q3, UID00009D, UID0000LV, UID0000KX, UID00019I, UID00025Q, UID00029H, UID0002X9, UID00028Q, `by-memory/-ignored.md`, current manual rows, and generated NewUserDialogPane.cpp immediately before their bounded callback edits/readback.
- [x] Historical callback applied the original C01-C46 claim set at report-level detail; this report now carries C01-C48 with unaffected applied history and every bounded source-contract claim in a legal terminal state with current proof.
- [x] Reclassified UID0002Q3 to `92/94`, owner 0000LV, false, blank emitter/position/formal C++, `Nested:4`, with complete exact split index; validator `000000011587`.
- [x] Serially created/registered the thirteen exact child pages in ascending address order and captured the real UID map before support cross-references were added; validators `11562-11584`.
- [x] Replaced all thirteen temporary UID tokens throughout this report and every ordinary destination with `0004PB`, `0004PC`, `0004PD`, `0004PE`, `0004PF`, `0004PG`, `0004PH`, `0004PI`, `0004PK`, `0004PL`, `0004PM`, `0004PO`, and `0004PP`; mechanical scan found no remaining placeholder.
- [x] Applied every child score/owner/emitter/position/reconstructable/`Nested:0` value exactly as the registered Function / Child Inventory specifies.
- [x] Historical callback applied all fifteen managed destinations and kept source inside formal headers with UID00009D closed before `[[CHILDREN]]`; the bounded repair applied corrected Destinations 2/5/10 exactly and retained every unaffected block.
- [x] Updated UID00009D to `92/94` and UID0000LV to `91/92`, preserving unrelated/concurrent content and the exact standalone route; validators `11591/11594`.
- [x] Updated only NewUser-specific rows/links in UID0000KX, UID00019I, UID00025Q, UID00029H, UID0002X9, and UID00028Q; preserved listed scores/formals and B005/unrelated content; validators `11595/11596/11598/11600/11602/11603`.
- [x] Added all ten exact padding spans and five compiler/data replacement rows to `by-memory/-ignored.md` with real UIDs; validator `000000011605`.
- [x] Preserved aggregate/child hashes, CFG, callers/callees, vtable slots, singleton refs, controls/resources, packet formats, conversion limits, error/success branch ordering, retained constructor route, and exact successor boundary without compression; fresh repair evidence adds the exact Event `+0x0c` payload and direct 256/256 conversion shape.
- [x] Preserved historical/stale assumptions and rejections: old scores, earlier padding correction, no-final-name blocker, `g_pMainUiGraph`, folded Login route, raw labels, aggregate body, duplicate cleanup destructor, and handwritten compiler ABI/table/vtable alternatives.
- [x] Preserved UID0002X9 zero-fill/source declaration recommendation and session-qualified `FF` signature discrepancy; its formal declaration is unchanged.
- [x] Kept UID0002Q4/Login source pages and all verify-only dependencies unchanged; no B004 source-method edit or unrecorded reverse-reference side effect occurred there.
- [x] Coordinated shared pages through serial lease/reread/rebase and never edited through another agent's lease.
- [x] Leased only one ordinary page immediately before each edit, scoped-validated it, and released immediately; all command timestamps/results/warnings/side effects are recorded and no B004 lease remains.
- [x] Historical callback ran authorized waited refresh `000000011608`; structural positive/negative assertions passed, but the old-name/SimpleUString source now records the Gate 2 semantic failure.
- [x] Re-read historical generated `NexusTK/login/NewUserDialogPane.cpp` read-only and recorded command freshness, SHA256, size, class/method counts, compiler-child negatives, and the two rejected semantic forms; B004 never edited it manually.
- [x] Kept every manual `-coverage-report.md` file read-only and preserved exact real-UID supervisor-owned rows above for external application.
- [x] Did not manually edit generated/tracker/audit/supervisor/validator-state/lifecycle/queue/lock/archive/IDA files and did not run/probe report execution, count, move, or archive commands.

Implementation callback phase:

- [x] Exact pre-callback report artifact was accepted by the supervisor before any ordinary by-* edit.
- [x] Historical callback incorporated the then-accepted target/support detail at report-level depth; subsequent Gate 2 review identified exactly two semantic defects preserved and repaired in this artifact.
- [x] C01-C48 ledger uses legal terminal states throughout: unaffected facts remain applied/already-present/excluded-with-reason and every accepted bounded-correction claim is applied with destination/validator/generated proof.
- [x] All thirteen real UIDs are recorded and every pre-registration token is removed from the report, destinations, ignored rows, and manual coverage text.
- [x] Metadata/score/owner/emitter/split/position/nesting and unaffected formal changes remain verified; corrected UID0004PD/UID0004PI/UID00009D source semantics are verified against current ordinary docs and generated output by validators `11674/11677/11679/11691`.
- [x] Historical evidence, negative checks, ranked alternatives, score caps, and B005 collision boundary are preserved.
- [x] All scoped validators and immediate lease releases are recorded; no B004 lease remains.
- [x] Historical waited generated structural assertions and exact command/SHA/count proof are preserved as baselines and are not reused as semantic proof; current command `11691` supplies independent corrected semantic proof.
- [x] Changed Files and Validator Results distinguish historical callback, report-only repair, and current bounded implementation work and use archive-neutral lifecycle wording.
- [x] Corrected ordinary implementation is complete; no accepted implementation item remains.

Gate 2 report-only repair phase:

- [x] Called fresh `idb_list`, `server_health`, bounded lookup/decompile/disassembly/get-bytes/xrefs against NexusTK database `9df6e9a0`; all valid evidence calls succeeded at repair time.
- [x] Re-read current Event, EventHandler, DialogPane, NewUserDialogPane, LoginDialogPane, UID0004PQ, UID0004PD, UID0004PI, target/file/aggregate/vtable/ignored reverse links, and historical generated proof.
- [x] Resolved `0x004fa0f0` to `bool NewUserDialogPane::HandlePacketEvent(Event *event)`, with packet pointer `event->m_payload.m_packet.m_data` at exact `Event +0x0c`, secondary slot `+0x10`, opcode `2`, compiler-only receiver adjustment, and tail-forward behavior.
- [x] Rejected `OnCreateUserReplyEvent(const PacketEvent *)` and updated every current report claim, formal block, recommendation, score/open-question note, coverage row, validator plan, generated assertion, and checklist dependency.
- [x] Resolved `0x004fa5b0` to direct `char narrowText[256]` plus `wchar_t wideText[256]`, exact packet-byte copy, narrow terminator, direct `MultiByteToWideChar(CP_ACP, 0, ..., textLength, ..., 256)`, unsigned-byte-narrowed returned-length wide terminator, and AlertPane construction from `wideText`.
- [x] Rejected `SimpleUString::FromMbcString` because no direct call or equivalent inlined-helper proof exists and the abstraction can alter edge behavior.
- [x] Updated C01-C48, all affected formal destinations, Current/Final recommendations, support plan, score/blocker analysis, open questions, exact manual coverage text, historical validator/generated interpretation, Changed Files, and this checklist atomically.
- [x] Preserved every unaffected UID0002Q3 split, UID map, byte/hash/CFG/xref, source/compiler disposition, behavior, support history, validator, generated, and negative/rejected-alternative fact without ordinary edits.
- [x] Touched only this report; acquired no lease; ran no validator, generated refresh, IDA mutation, report execution/probe/count/move/archive, or lifecycle command.

Bounded same-report implementation repair phase:

- [x] After supervisor MCP recovery, called fresh `idb_list`, discovered database `6b2e78f3`, verified healthy server state, and repeated bounded lookup/bytes/decompile checks for both affected functions and the Login sibling without fallback evidence.
- [x] Leased the old UID0004PD path, moved it once without copying to `by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md`, applied corrected Destination 5, validated the final path with `000000011674`, confirmed the old path absent and UID0004PD unique, and released immediately.
- [x] Applied corrected Destination 2 to UID00009D and corrected Destination 10 to UID0004PI under separate immediate leases/scoped validators `000000011677/11679`, preserving scores, metadata, unrelated source, all branch behavior, and class closure before `[[CHILDREN]]`.
- [x] Updated only stale UID0004PD names/links and UID0004PI conversion detail in UID0002Q3, UID0000LV, the unique current UID00019I path, UID0004PP, `by-memory/-ignored.md`, and validator-managed reverse references; reread/rebased every destination and preserved B005/unrelated content; validators `11682/11684/11687/11688/11690`.
- [x] Ran final waited generated refresh `000000011691` and proved exactly one corrected `HandlePacketEvent(Event *)`, one Event payload access, zero old `OnCreateUserReplyEvent`/standalone `PacketEvent`, exact fixed-buffer/direct conversion, zero `SimpleUString::FromMbcString`, and every historical structural positive/negative assertion.
- [x] Released every current edit lease immediately after validation; current lease report shows no B004 lease.
- [x] Did not manually edit coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/queue/lock/archive/IDA files and did not run/probe report execution, count, move, or archive commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000011727","destination_path":"executed-b-agent-research/B004/0002Q3-NewUserDialogPaneCoreAndPacketHelpers-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002Q3-NewUserDialogPaneCoreAndPacketHelpers-empty-emitter-source-quality.md","timestamp":"2026-07-14T15:16:46-04:00","uid":"0002Q3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
