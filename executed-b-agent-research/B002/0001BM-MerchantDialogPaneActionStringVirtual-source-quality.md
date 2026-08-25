** TARGET-REPORT-UID:0001BM **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001BM MerchantDialogPane HandlePacketEvent Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: replace the historical action-string-wrapper hypothesis with the canonical source contract `bool MerchantDialogPane::HandlePacketEvent(Event *event)`. The function at `0x00517d80` occupies the `EventHandler` secondary-view packet slot `+0x10`; its explicit stack argument is `Event *`, and the load from argument offset `+0x0c` is `event->m_payload.m_packet.m_data`.
- Final disposition: keep [UID:0001BM] reconstructable and directly owned/emitted by [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md), routed through [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md). Preserve [UID:0001BL] as the non-emitting split container and [UID:00041Q] as the separate constructor child.
- Implementation state: supervisor audit `B002 UID0001BM Exact-Artifact Gate 1 Reaudit - 2026-07-26T00:19:02-04:00` passed exact SHA256 `C4F95BD012C248DBDF11B6D91833CAF6BA31F814A08247EA093A6D4097F9C444`, after which the supervisor issued the implementation callback. B002 installed the destination-ready method body, UID000083 H declaration, separate UID000083 CPP include/children shell, Merchant support synchronization, exact UID0001FF duplicate correction, Pursuit support corrections, and PacketBuffer support facts. Supervisor-owned Gate 2B IDA actions, manual coverage rows, generated refresh/readback, Gate 2 verification, and report execution remain pending.
- Confidence: very strong. Live IDA, canonical Event/EventHandler declarations, owner-specific vtables, eight inherited data refs, an exact relocated duplicate, helper-family documentation, stack-frame shape, and boundary bytes independently agree.

## Supporting Research

- The assignment was triggered by the then-current pre-callback research queue row for UID0001BM at `87/90`, reconstructable, with no direct/additional B-report coverage and a blank formal body. That queue snapshot is historical; the ordinary callback subsequently applied `94/95` and exact CPP source.
- Historical B006 work correctly established the range, class ownership, helper calls, vtable-only reachability, and no direct callers. Its no-code conclusion is superseded only because the current Event/EventHandler documentation now resolves the previously unknown virtual slot and argument object.
- [UID:0002EU][ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) and [UID:000318][AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md) are current positive controls for the same Event packet pointer at `+0x0c` and secondary slot `+0x10`.
- [UID:0001FF][MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) is a relocated duplicate with the same 319-byte instruction/control-flow shape and the same protocol behavior. Its pre-callback `DialogObjectAction` model predated the canonical Event evidence and was not copied forward.
- Live MCP evidence used active session `f085b224`. The saved IDB was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,186,768 bytes, mtime `2026-07-25T23:14:42.2666509-04:00`, SHA256 `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`.
- `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready with 2,068 entries. Per the supervisor's explicit runtime override, `auto_analysis_ready:false` is the known post-definition/save state and did not invalidate the successful live reads.
- A fresh exhaustive return-use audit resolved the last `0x5753f0` type question. Live `xrefs_to` returned all 119 direct call sites; live post-call bytes were decoded as 32-bit x86 with Capstone 5.0.7. None reads EAX/AX/AL/AH as a helper result: 109 overwrite EAX before any read, nine reach another call that clobbers EAX first, and the sole loop-shaped case at `0x005a8dcb` overwrites EAX at `0x005a8def` on exit or at `0x005a8dc3` on the next iteration. The accepted sibling writers at `0x575380` and `0x5753a0` are already typed `void`; the integer-looking `a1 >> 8` result in the raw UInt32 decompile is therefore incidental register residue, not source API behavior.

## Target

- Target UID: `0001BM`.
- Additional target UIDs: none. UID0001FF is a required support correction, not a second declared report target.
- Declared-target inventory: [UID:0001BM] `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`, source-authored `MerchantDialogPane::HandlePacketEvent` method body.
- Target path: `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`.
- Pre-callback source queue/report snapshot: `auto-generated/-ag-research-tracker.md`, `## by-memory` / `### Not-Covered Files - Reconstructable`, row UID0001BM `87/90`, average `88.5`, reconstructable true, report counts `0/0/0`.
- Pre-callback supervisor classification: report-only source-quality research with mandatory live read-only IDA evidence and no target/support edits before Gate 1. That phase ended when the exact artifact passed Gate 1 and the supervisor issued the ordinary implementation callback.
- Pre-callback scores and parent state: target `87/90`; owner/emitter UID000083; reconstructable true; blank position, CPP, and H; `Nested:0`; class UID000083 `87/88`; file UID0000L9 `86/88`; vtable UID00031W `87/90`.

## Current Target State

- Pre-callback metadata snapshot: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:000083`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000083`, blank position/CPP/H, `Nested:0`.
- Owner/emitter/reconstructable state across both snapshots: correct and retained. MerchantDialogPane is the narrowest semantic owner; the class emits through MerchantDialogPane.cpp.
- Pre-callback C++/generated snapshot: target was an Empty Emitter Marker in generated `NexusTK/ui/dialogs/MerchantDialogPane.cpp` under validator command `000000017510`; constructor UID00041Q emitted while target/class/vtable formals were empty. This marker evidence is historical. The ordinary docs now contain the applied source formals, while validator-owned generated refresh/readback remains pending after the scoped validators reported `generated_refresh: deferred`.
- Pre-callback open questions/blockers: stale target text said the virtual name, slot, and argument object were unknown; it treated `+0x0c` as an unknown action-string pointer and therefore kept formal C++ blank. The report resolved the exact EventHandler contract, input grammar, 256-byte local response buffer, signed 16-bit trailer offset, byte `+7` read, and helper/IDA states before callback.
- Current applied target state: UID0001BM is `94/95`, retains owner/emitter UID000083, reconstructable true, blank position, `Nested:0`, exact `MerchantDialogPane::HandlePacketEvent(Event*)` CPP, and blank H. UID000083 is `92/94` with the complete class declaration in H and own/dependency includes plus `[[CHILDREN]]` in CPP; UID0000L9 is `90/90`; UID00031W is `91/94` with blank formal and canonical EventHandler slot prose.
- Current applied support state: UID0001FF is `94/95` with exact `PursuitMessageDialogPane::HandlePacketEvent(Event*)` CPP and blank H; UID0000BE remains `92/94` with its complete declaration in H and includes/children shell in CPP; UID0001YI remains `90/94` with blank formal; UID0000LA remains `92/92`; PacketBuffer scalar writer support remains `87/91` with the accepted consumer/void-return/IDA-handoff evidence.
- Related target/support docs checked: Merchant class/file/vtable/constructor/container; Event, EventHandler, DialogPane, DialogPaneVtables; ObjectStatusBlob class/file/parser; PacketBuffer scalar read/write helper families; QueueAndSendPacket and g_packetSender; all seven derived consumer class/file contexts; exact Pursuit duplicate target/class/file/vtable; the pre-callback generated Merchant snapshot; all relevant manual coverage rows; old B006 and current executed research that classifies `0x575470`.
- Current artifact/lifecycle status: exact pre-callback artifact passed Gate 1, the implementation callback has completed across all nine ordinary by-* destinations, and all nine scoped validators exited `0` with `ok: 1`. B002 performed no IDA mutation, coverage edit, generated-file edit, report execution, archival, or validator lifecycle command. Supervisor Gate 2A/2B, manual coverage/generated refresh, and execution remain pending.

## Executive Recommendation

- Direct owner: [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md).
- Source root: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md), candidate physical source `NexusTK/ui/dialogs/MerchantDialogPane.cpp`.
- Method identity: `virtual bool HandlePacketEvent(Event *event)` in UID000083 H and `bool MerchantDialogPane::HandlePacketEvent(Event *event)` in the exact memory child CPP. UID000083 CPP contains includes plus `[[CHILDREN]]`, not the class declaration.
- Input object identity: canonical [UID:00004L][Event](by-class/Event.md), packet variant. No new `MenuActionString`, `DialogAction`, or `DialogObjectAction` wrapper should be invented.
- Split/container disposition: no range split or merge. Keep target `[0x00517d80,0x00517ebf)`, constructor child `[0x00517d30,0x00517d74)`, twelve-byte constructor-to-target alignment `[0x00517d74,0x00517d80)`, one-byte target-to-successor alignment at `0x00517ebf`, and successor at `0x00517ec0` separate.
- Score/CPP disposition: raise target to `94/95`, install the formal CPP body, keep target H blank, and add the declaration shell to class UID000083.
- Support correction: UID0001FF is the same EventHandler packet override for PursuitMessageDialogPane. Replace its fake wrapper/signature, preserve its behavior evidence, use the exact 256-byte local buffer and byte-7 read, and raise it to `94/95`.

## Supervisor Active Recheck

- Supervisor instruction: research UID0001BM exhaustively, resolve all score/open-question blockers now, use healthy live IDA MCP read-only evidence, edit only this report, and return the complete literal Gate 1 template.
- Exact-artifact audit `B002 UID0001BM Exact-Artifact Gate 1 Audit - 2026-07-26T00:09:00-04:00` failed prior SHA256 `5C977DFACC01682E7F8692B15A17668A036117A3C2A541993829CE5A46F0AE8D` only on IDA handoff prestate/secondary-facet typing and H-versus-CPP declaration routing. The incrementally repaired exact SHA256 `C4F95BD012C248DBDF11B6D91833CAF6BA31F814A08247EA093A6D4097F9C444` then passed `B002 UID0001BM Exact-Artifact Gate 1 Reaudit - 2026-07-26T00:19:02-04:00`; this callback preserves all prior research, headings, formals, coverage payloads, and resolved-question work.
- Split repair: not required. Current exact child boundaries are correct and independently confirmed by live function size and bytes.
- Source-bearing children: constructor UID00041Q already exists and emits; target UID0001BM is the missing source-bearing method. Parent UID0001BL and compiler vtable data remain non-emitting by design.
- Every source-bearing item in scope now has an implementation-ready disposition. No vague future-research blocker remains.

## Inference Research Guidance Check

- `by-structure.md` discipline requires the narrowest semantic owner, source-level inheritance/virtual declarations instead of handwritten vtables, exact half-open ranges, and child-level bodies. That selects MerchantDialogPane, not a derived menu class or protocol helper.
- Existing documentation was treated as evidence, not truth. The old unknown action-object claim and UID0001FF's `DialogObjectAction` type were explicitly rechecked and rejected against newer Event/EventHandler facts.
- Direct IDA fact: function bytes, stack argument at `+8`, load from argument object `+0x0c`, `retn 4`, helper calls, vtable cells, eight data refs, local frame, boundaries, current names/types/comments.
- Documentation fact: Event packet layout, EventHandler slot order, DialogPane secondary offset, ObjectStatusBlob layout/parser contract, PacketBuffer helper semantics, source tree route.
- Inference: source-facing local names, exact physical standalone file, and neutral labels for reserved/unconsumed protocol bytes. These are marked descriptive and do not replace binary facts.
- Wave2/Wave3: stale mentions exist in historical/generated documentation. They were ignored and were not used as current evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible resolution | Evidence | Classification |
| --- | --- | --- | --- |
| Unknown virtual slot | EventHandler packet-family slot `+0x10` | Merchant secondary table cell `0x0061ec80`; canonical EventHandler order; Dispatcher packet dispatch | direct binary + canonical documentation |
| Unknown argument object | `Event *event` | explicit arg at `[ebp+8]`; data pointer at Event `+0x0c`; packet sibling methods | strongly supported source contract |
| Raw `__stdcall(int)` decompile | compiler/decompiler artifact caused by unused ECX and untyped Event | secondary vtable entry, `retn 4`, no ECX use | rejected raw signature |
| Source method name | `HandlePacketEvent` | exact EventHandler declaration and slot order | canonical descriptive interface name |
| Receiver type | `MerchantDialogPane` source method; incoming raw ECX is secondary EventHandler view at complete-object `+0xa0` | class vtables/inheritance; body does not consume ECX | source-level resolution |
| Input discriminators | `'/'` handles immediately; `'0'` parses and replies; all others false | exact comparisons `0x2f`/`0x30` | direct binary fact |
| Packet byte `+1` | reserved/unconsumed by this handler | exhaustive target disassembly has no read | negative binary fact; neutral descriptive role |
| Packet byte `+2` | response/action type byte copied to reply byte 1 | narrow-byte call and writer | direct binary fact; source name descriptive |
| Packet bytes `+3..+6` | big-endian 32-bit object/session identifier | `PacketBufferReadUInt32BE` then UInt32BE writer | direct binary fact; `objectId` high-probability descriptive name |
| Packet byte `+7` | reserved byte intentionally read and discarded | second `0x575470` call result unused | direct binary fact; neutral source local `reserved` |
| Variable payload at `+8` | `ObjectStatusBlob::ParseTaggedStatus` | typed live decompile and canonical parser docs | direct typed fact |
| Four bytes after parsed status | fixed skipped trailer-prefix region before two words | 16-bit offset starts at 8, parser length added, then +4 | direct offset fact; semantic label descriptive |
| Trailer offset width | signed 16-bit local, including narrowing/wrap before pointer additions | BX/MOVZX/MOVSX/CWDE sequence | direct machine fact |
| Outgoing local capacity | `unsigned char response[256]` | frame partition from `ebp-0x104` through `ebp-0x5`; total 256 bytes (Verified with `int_convert.py`) | direct stack-layout fact |
| Reply layout | `{0x3a, type, BE32 id, BE16 value1, BE16 value2}`, sent length 10; byte 10 local terminator | exact writer calls/offsets/send args | direct binary fact |
| `0x575470` identity | preserve MSVC `_Narrow_char_traits::to_char_type`; express source as direct byte reads | exact decorated name, 0xa body, existing two-line function comment, broad docs | protected compiler/runtime lowering |
| `0x5753f0` identity | `void PacketBufferWriteUInt32BE(value,destination)` | exact stores of four high-to-low bytes plus spare zero; all 119 live callers audited and none consumes EAX; accepted UInt8/UInt16 siblings are `void` | very-strong descriptive project helper and source type |
| Owner | MerchantDialogPane | first vtable ref is owner table; seven later refs inherit same body | direct ownership fact |
| Physical file | current MerchantDialogPane source root; standalone `.cpp` preferred, folding remains possible | current by-file route and adjacent constructor/method cluster | high-probability source placement |
| Exact duplicate | Pursuit method is also `HandlePacketEvent(Event*)`, not `DialogObjectAction` | identical instruction/control-flow shape except 15 rel32 relocation fields; secondary slot `+0x10` | direct analog correction |

Rejected alternatives:

- `MenuActionString *`, `MenuItemAction *`, `DialogAction *`, `DialogObjectAction *`, `const char *`, `void *`, and `int` are rejected by the canonical Event packet record and EventHandler slot.
- TextMenuDialog, TextInputMenuDialog, item/spell/argumented dialog classes are inheriting consumers, not owners.
- PacketBuffer, Socket, g_packetSender, and ObjectStatusBlob are dependencies, not source owners.
- A free function, static callback, direct-vtable source table, explicit `this -= 0xa0`, raw helper labels, or hand-authored stack-cookie code is rejected as compiler/decompiler pollution.
- A null check, Event type check, packet-size check, parser-failure rejection, bounds check, opcode enum, or ownership/free operation is rejected because none occurs in the body.
- A local response buffer of 11 bytes is behaviorally enough but source-shape incorrect for this binary. The exact stack frame proves 256 bytes.

## Evidence Standards Used

- Live IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm` through exported function data, `xrefs_to`, `get_bytes`, `get_int`, `get_comments`, `export_funcs`, and `type_query`; the UInt32 writer return-use pass combined all 119 live xrefs and post-call bytes with local Capstone 5.0.7 decoding.
- Binary context: exact function size, prologue/epilogue, stack frame, helper calls, virtual-table data refs, primary/secondary/tertiary view layout, adjacent padding, successor function, and relocated duplicate.
- Documentation context: canonical Event/EventHandler/DialogPane contracts, ObjectStatusBlob parser/layout, PacketBuffer helper families, source owner/file routes, generated output, and historical reports.
- Negative evidence: no direct code callers, no hidden explicit branch route, no target entry comment, no MerchantDialogPane local type, no access to packet size/type in the body, no field at packet byte `+1`, no owner-state access, no split overlap.
- Evidence strength: exact source lexical spellings are unavailable, but method/type/slot/behavior/owner/range are jointly overdetermined. Remaining lexical and physical-file uncertainty caps final confidence without blocking source.

## Evidence Checked

- IDA MCP/manual checks: live session/health; target/helper/duplicate lookup; target and duplicate decompilation; target/function export with all instructions/comments; xrefs for target and duplicate; exact target/duplicate bytes; target/duplicate byte-difference grouping; vtable cell integer reads; Event/ObjectStatusBlob local types; all four literal entry/function comment channels plus all existing line comments for target/helper/duplicate; exact proposed-name lookup and name-index collision checks; `EventHandlerFacet`/Event/complete-object type inspection; target boundaries and successor; all 119 UInt32-writer xrefs plus every post-call instruction stream, including the `0x005a8dcb` loop path.
- by-* and support docs: all Merchant target/class/file/vtable/container/constructor docs; Event/EventHandler/DialogPane/DialogPaneVtables; ObjectStatusBlob; PacketBuffer scalar read/write helpers; QueueAndSendPacket/g_packetSender; exact Pursuit duplicate and its class/file/vtable; representative HandlePacketEvent siblings.
- Generated/tracker checks during the pre-callback research snapshot: MerchantDialogPane.cpp command `000000017510`; UID0001BM research-tracker row; manual by-memory/by-class/by-file/by-vtable coverage rows.
- Negative checks: no ordinary target caller, exactly eight data refs, no target entry comments, no MerchantDialogPane local type, target does not use ECX/Event type/Event size, no additional target body after `0x00517ebf`, no evidence for the fake action wrapper.
- Initial report-only phase exclusions: no validator, ordinary/generated mutation, IDA mutation/save, report lifecycle/execution command, or target/support edit occurred before Gate 1. After callback, B002 edited only the nine accepted ordinary destinations and ran the nine scoped validators recorded below; IDA, coverage/generated files, and report lifecycle/execution remained untouched.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1BM-001 | 0001BM | Exact range is `[0x00517d80,0x00517ebf)`, size `0x13f` / 319 bytes (Verified with `int_convert.py`) | exact | live lookup/export/bytes | target Status/Range/Evidence | incorporated | implemented in UID0001BM; validator `000000017540` ok |
| C1BM-002 | 0001BM | Function is EventHandler secondary slot `+0x10` | very strong | cell `0x61ec80`, EventHandler slot map | target Virtual Contract; Merchant vtable | incorporated | implemented in UID0001BM/UID00031W; validators `000000017540`/`000000017546` ok |
| C1BM-003 | 0001BM | Source signature is `bool MerchantDialogPane::HandlePacketEvent(Event *event)` | very strong | C1BM-002, `retn 4`, Event `+0x0c` load | target CPP; UID000083 H declaration | applied | exact UID0001BM CPP and UID000083 H; validators `000000017540`/`000000017543` ok |
| C1BM-004 | 0001BM | Input data is `event->m_payload.m_packet.m_data` | exact layout | Event local type/docs and target load | target Behavior/Event ABI | incorporated | implemented in UID0001BM and UID0001FF; validators `000000017540`/`000000017548` ok |
| C1BM-005 | 0001BM | `'/'` true, non-`'0'` false, `'0'` response parse | exact | target disassembly/decompile | target Behavior | incorporated | exact branches in both formal bodies and prose; validators ok |
| C1BM-006 | 0001BM | Byte `+2`, BE32 `+3`, reserved read `+7`, ObjectStatusBlob `+8`, four skipped bytes, two BE16 trailer words | exact offsets | live decompile/disassembly | target Protocol Grammar | incorporated | exact target/duplicate grammar and support prose; validators ok |
| C1BM-007 | 0001BM | Parser offset is signed 16-bit and retains fallback 12 | exact | BX/MOVSX/CWDE path | target Behavior/CPP rationale | incorporated | exact `short trailerOffset` body/prose in UID0001BM/UID0001FF; validators ok |
| C1BM-008 | 0001BM | Response local is 256 bytes, not 11 | exact | `ebp-0x104..-0x5` stack partition | target CPP/stack evidence | applied | exact `response[256]` in both formals and support docs; validators ok |
| C1BM-009 | 0001BM | Reply is ten sent bytes plus local byte-10 terminator | exact | helper destinations and send length | target Protocol Grammar/CPP | applied | target/duplicate/PacketBuffer pages synchronized; validators `000000017540`/`000000017548`/`000000017554` ok |
| C1BM-010 | 0001BM | Direct owner/emitter UID000083 remains correct | very strong | first owner vtable ref plus seven inherited refs | target/class/file/vtable ownership | retained | metadata and complete owner chain verified; validators `000000017540`/`000000017543`/`000000017544`/`000000017546` ok |
| C1BM-011 | 0001BM | No split/merge; one trailing CC before successor | exact | live bytes/lookup | target Range section | retained | target range/padding and separate constructor/successor preserved; validator `000000017540` ok |
| C1BM-012 | 0001BM | `0x575470` remains runtime lowering, not a source packet helper | very strong | decorated symbol/body/comment/docs | target Dependencies/negative evidence | protected | target and PacketBuffer support explicitly preserve no-change runtime identity; validators ok |
| C1BM-013 | 0001BM | `0x5753f0` is void PacketBufferWriteUInt32BE with value-first ABI and spare zero | very strong | exact helper body; 119/119 caller return-use audit; void sibling writers; docs | target dependencies; PacketBuffer support; IDA handoff | docs applied | ordinary docs implemented and validator `000000017554` ok; IDA Gate 2B remains supervisor-pending |
| C1BM-014 | 0001BM | Target/duplicate raw IDA entries safely use existing opaque `EventHandlerFacet *` receivers, not complete-object class pointers | very strong | secondary-view `+0xa0` entry ABI, unused ECX, existing ordinal-742 facet type, exact prestate/collision checks | IDA Gate 2B | supervisor apply | pending supervisor |
| C1BM-015 | 0001BM | UID0001FF fake DialogObjectAction model is superseded | very strong | exact relocated duplicate and Pursuit slot +0x10 | UID0001FF/Pursuit support docs/formals | corrected | UID0001FF/UID0000BE/UID0001YI/UID0000LA synchronized; validators `000000017548`/`000000017549`/`000000017551`/`000000017553` ok |
| C1BM-016 | 0001BM | Target score should become `94/95` | strong | all blockers resolved and formal ready | target metadata/manual coverage | metadata applied | UID0001BM `94/95`; manual coverage remains supervisor-pending |
| C1BM-017 | 0001BM | Merchant class/file/vtable should become `92/94`, `90/90`, `91/94` | strong | complete class contract/source graph/slot identity | support metadata/manual coverage | metadata applied | exact scores validated; manual coverage remains supervisor-pending |
| C1BM-018 | 0001BM | Pre-callback generated Merchant source had three empty markers | exact | command `000000017510` readback | target/class/file status | historicalized in docs | ordinary docs record the superseded pre-callback marker state; scoped generated refresh deferred to supervisor/validator |
| C1BM-019 | 0001BM | UID000083 declaration belongs in H; UID000083 CPP contains its own header/dependency includes plus `[[CHILDREN]]` | exact channel rule | class-owner emission contract and method-child routing | UID000083 H/CPP | applied | exact separate H/CPP blocks verified; validator `000000017543` ok |

## Positive Evidence Summary

- Direct facts: modeled 319-byte function; one explicit pointer argument and `retn 4`; Event data load at `+0x0c`; exact branch/parser/writer/send sequence; eight vtable refs; owner cell at Merchant secondary `+0x10`; exact boundaries.
- Corroboration: canonical Event/EventHandler formal declarations, DialogPane's secondary-view ordering, current Chatting packet override, exact Pursuit duplicate, typed ObjectStatusBlob and helper docs.
- Strongest chain: EventDispatcher packet events use EventHandler `+0x10`; Merchant secondary `+0x10` points at target; Event packet data is at `+0x0c`; target reads its only explicit object argument at `+0x0c`. These four independent facts resolve both method slot and argument type without guessing.

## IDA MCP Facts

- Function/range facts: `sub_517D80`, `0x13f`; prototype currently `char __stdcall(int)`; seven basic blocks and cyclomatic complexity 2 in the live analysis; 104 exported instructions; successor `sub_517EC0` starts at `0x00517ec0`.
- Data/table/padding facts: Merchant primary/secondary/tertiary vtables are `0x0061ec10/0x0061ec70/0x0061eca0`; secondary COL is `0x0064b7d4`; secondary cells are destructor adjustor, pointer/mouse, key/text, IME, target at `+0x10`, then inherited EventHandler defaults. One `0xcc` byte is at `0x00517ebf`.
- Xref facts: exactly eight target data refs: `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, `0x0061f498`; no ordinary code caller.
- Vtable/global/type facts: Event local type is 272/`0x110` bytes with vftable `+0`, EventType `+4`, EventPayload `+8`; EventPacketPayload has data pointer `+4` within payload, hence Event `+0x0c`. ObjectStatusBlob is 68/`0x44` bytes with `m_displayStatusByte` at `+0x28`. MerchantDialogPane local type is absent. Existing local type ordinal 742 is `EventHandlerFacet`, an opaque one-byte struct with `_opaque` at `+0`; it is the safe raw IDA receiver tag because both target and duplicate enter through an EventHandler secondary view and never dereference ECX. PursuitMessageDialogPane exists as a complete-object UDT but is deliberately not used as the raw entry receiver.
- Helper facts: `0x575470` is decorated `_Narrow_char_traits<char,int>::to_char_type`, size `0xa`, returning one pointed byte. `0x5753f0` is `sub_5753F0`, size `0x29`, current stale type `unsigned int __cdecl(unsigned int,int)`, and writes four BE bytes plus a spare zero. Fresh live xrefs/post-call decoding proves none of its 119 callers consumes the apparent EAX result; 109 overwrite it, nine clobber it with another call, and the remaining loop overwrites it on both continuations. The apparent shifted return is compiler/decompiler residue, matching the already-void UInt8 and UInt16 sibling writers.
- Duplicate facts: `sub_54CAF0` is also `0x13f`, has eight vtable refs, and decompiles identically. A direct 319-byte comparison found 45 differing bytes in fifteen three-byte groups, each inside relocated call displacement fields; all non-relocation opcode/control-flow/stack bytes agree.
- Negative IDA facts: all four entry/function comment channels are empty for target, UInt32 helper, and duplicate; exact-name `lookup_funcs` returned `Not found` for all three proposed names and exact-regex `entity_query(kind=names)` returned total zero; no MerchantDialogPane type; ECX is unused; Event type/size are not checked; packet byte `+1` and Event packet size are not read; no split child inside target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00517d30-0x00517ebf` | UID0001BL MerchantDialogPaneBase | split/container index | false | none | current container state | retain non-emitting |
| `0x00517d30-0x00517d74` | UID00041Q MerchantDialogPaneConstructor | source constructor | true | UID000083 | `89/90` | existing formal retained |
| `0x00517d74-0x00517d80` | no UID | alignment | no | container | n/a | retain padding |
| `0x00517d80-0x00517ebf` | UID0001BM target | `HandlePacketEvent` source method | true | UID000083 | `87/90 -> 94/95` | formal body required |
| `0x00517ebf-0x00517ec0` | no UID | alignment | no | boundary | n/a | retain padding |
| `0x00517ec0...` | TextMenuDialog island | successor code | separate | TextMenuDialog | separate | no merge |
| MerchantDialogPane | UID000083 | class declaration/owner | true | UID0000L9 | `87/88 -> 92/94` | declaration required in H; includes/children shell required in CPP |
| MerchantDialogPaneVtables | UID00031W | generated-binary vtable support | true | UID000083 | `87/90 -> 91/94` | prose/score sync; blank formal |
| `0x0054caf0-0x0054cc2f` | UID0001FF | exact Pursuit support duplicate | true | UID0000BE | `91/94 -> 94/95` | Event/signature/source-shape correction |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061ec80` | MerchantDialogPane secondary `+0x10` -> target | direct owner and packet virtual slot |
| `0x0061ed1c` | TextMenuDialog secondary slot -> target | inherited consumer |
| `0x0061ee7c` | TextInputMenuDialog secondary slot -> target | inherited consumer |
| `0x0061ef18` | ServerItemMenuDialog secondary slot -> target | inherited consumer |
| `0x0061f078` | ClientItemMenuDialog secondary slot -> target | inherited consumer |
| `0x0061f1d8` | ServerSpellMenuDialog secondary slot -> target | inherited consumer |
| `0x0061f338` | ClientSpellMenuDialog secondary slot -> target | inherited consumer |
| `0x0061f498` | ArgumentedMenuMenuDialog secondary slot -> target | inherited consumer |
| `0x00575470` | two target calls | source byte reads at packet `+2` and `+7`; runtime lowering |
| `0x005754c0` | target call | BE32 read at packet `+3` |
| `0x004d1f30` | target call | ObjectStatusBlob tagged parse at packet `+8` |
| `0x00575480` | two target calls | BE16 trailer reads |
| `0x00575380` | two target calls | opcode/type byte writes |
| `0x005753f0` | target call | BE32 reply write |
| `0x005753a0` | two target calls | BE16 reply writes |
| `0x00574bb0` / `0x0067a7ec` | target call/global | sends exactly ten bytes through g_packetSender |

## Documentation Evidence And IDA Status

- Supporting docs already current in the pre-callback research snapshot: Event, EventHandler, DialogPane, DialogPaneVtables, ObjectStatusBlob class/parser, PacketBuffer scalar families, QueueAndSendPacket, g_packetSender, Merchant constructor/container/vtable boundaries.
- Docs found stale/incomplete in the pre-callback snapshot and corrected by this callback: UID0001BM/class/file/vtable unknown-action-object/no-code text; UID0001FF/Pursuit class/file/vtable `DialogObjectAction` and `HandleDialogObjectResponse` text; UID0001FF 11-byte response local. Current manual coverage scores/descriptions for Merchant pages remain supervisor-owned pending work.
- Pre-callback generated-state snapshot: `auto-generated/NexusTK/ui/dialogs/MerchantDialogPane.cpp` command `000000017510` emitted the constructor and three Empty Emitter Markers for class/target/vtable. That historical output was an emitter-quality gap, not owner or liveness evidence; generated refresh/readback remains supervisor-owned pending work after the completed ordinary callback.
- Current IDA status: target and duplicate remain raw `sub_` names despite historical docs claiming a prior rename for the duplicate. Gate 2B must rely on live prestate, not the stale rename statement.

## Ranked Ownership Analysis

### 1. MerchantDialogPane class UID000083

- Evidence for: owner-specific constructor installs all three vtables; first target xref is Merchant secondary packet slot; seven derived tables inherit the same target; method uses no derived-only state; exact constructor sibling and source file route already exist.
- Evidence against: no ordinary call xref and body does not use `this`; neither weakens virtual ownership.
- Decision: selected direct owner/emitter.

### 2. MerchantDialogPane file UID0000L9

- Evidence for: exact constructor/method cluster, current source route, dedicated generated source, by-file ownership already accepted.
- Evidence against: exact historical standalone `.cpp` versus folding into a broader menu-dialog translation unit is not symbol-proven.
- Decision: retained emitter/source root, not the narrower direct semantic owner.

### 3. Derived text/item/spell/argumented menu classes

- Evidence for: each has a secondary vtable cell pointing at target.
- Evidence against: all reuse one identical base body; first defining table is MerchantDialogPane; no derived state is referenced.
- Decision: rejected as owners; retain as inherited consumers.

### 4. Event/PacketBuffer/ObjectStatusBlob/Socket modules

- Evidence for: supply argument type, parser, scalar helpers, global, and send route.
- Evidence against: no ownership state or defining vtable; generic dependencies are used across many subsystems.
- Decision: rejected as owners.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Continue `NexusTK/ui/dialogs/MerchantDialogPane.cpp` through UID0000L9.
- Likely full contents: MerchantDialogPane declaration/header, constructor UID00041Q, target UID0001BM, compiler-emitted vtables/RTTI from the declaration.
- Candidate related items that belong: exact Merchant constructor and class-specific declaration/vtable support.
- Candidate related items rejected: derived dialog methods, PacketBuffer helpers, ObjectStatusBlob parser, Socket sender, raw vtable bytes.
- Source-file inference: narrow standalone file is the best current route; broader folding remains a physical-layout possibility only.

## Source Placement

- Recommended placement: exact class declaration and required `DialogPane.h` include/Event forward declaration in UID000083 H; separate `MerchantDialogPane.h`, Event, ObjectStatusBlob, PacketBuffer, and Socket includes plus `[[CHILDREN]]` in UID000083 CPP; constructor/method definitions in `NexusTK/ui/dialogs/MerchantDialogPane.cpp`, routed by UID0000L9.
- Fit: class is a DialogPane-derived shared menu base, physically adjacent constructor/method code, and separately represented in generated output.
- Rejected placements: TextMenuDialogs.cpp, ItemMenuDialogs.cpp, SpellMenuDialogs.cpp, ArgumentedMenuDialogs.cpp, Event.cpp, PacketBuffer.cpp, ObjectStatusBlob.cpp, Socket.cpp.
- Remaining uncertainty: original project may have folded MerchantDialogPane private base code into a broader menu-dialog `.cpp`. The current by-file route is still the most stable source owner and no behavior/ownership decision depends on the final physical split.

## Range / Split / Padding / Reclassification Analysis

- Exact target: `[0x00517d80,0x00517ebf)`, `0x13f` / 319 bytes (Verified with `int_convert.py`).
- Predecessor: constructor UID00041Q ends at `0x00517d74`; alignment is twelve `0xcc` bytes through `0x00517d7f`.
- Successor: one `0xcc` byte at `0x00517ebf`; modeled `sub_517EC0` begins at `0x00517ec0` and belongs to TextMenuDialog.
- Child action: no create/split/merge. Preserve existing UID and path; retitle prose/source identity to HandlePacketEvent while retaining historical title as a superseded assumption.
- Parent impact: UID0001BL remains non-reconstructable/non-emitting split index. UID00031W remains source-declared/generated-binary support and must not emit raw table data.

## Negative Evidence Summary

- No ordinary code caller was found; exactly eight vtable data refs prove indirect liveness.
- No target code uses the Merchant receiver, but that does not make it static/free: the defining secondary vtable slot fixes the source virtual.
- No target code reads Event `m_type`, packet kind, packet size, or owns/frees packet memory. Dispatcher/factory infrastructure supplies the event-family guarantee.
- No packet byte `+1` read exists. Byte `+7` is read and discarded. No stronger semantic names are justified for either.
- No null/bounds/parser-error guard or exception branch exists. Draft source must not add one.
- No raw helper at `0x575470` should be renamed to a project packet helper; the current decorated runtime identity and function comments are consistent with current support docs.
- No raw vtable, COL, adjustor thunk, stack cookie, decompiler local, `sub_` label, or explicit secondary-this arithmetic belongs in source.
- No evidence supports the prior `DialogObjectAction` wrapper. Exact current Event layout directly contradicts it.

## IDA Rename / Type / Comment Recommendations

Gate 2B action table:

| Address/entity | Literal current pre-state | Proposed action | Evidence/confidence | Expected readback | Classification |
| --- | --- | --- | --- | --- | --- |
| `0x00517d80` function | Exact current half-open range `[0x00517d80,0x00517ebf)`, end `0x00517ebf`, size `0x13f` / 319. Name `sub_517D80`; prototype `char __stdcall(int)`. Literal entry/function channels: address regular `""`; address repeatable `""`; function regular `""`; function repeatable `""`. Preserve these line regular comments exactly, with repeatable `""` at every listed address: `0x517da6="StackCookie"`, `0x517dd6="buffer"`, `0x517df6="packet"`, `0x517df7="this"`, `0x517e13="packet"`, `0x517e22="packet"`, `0x517e31="destination"`, `0x517e32="value"`, `0x517e3f="destination"`, `0x517e47="value"`, `0x517e65="destination"`, `0x517e66="value"`, `0x517e72="destination"`, `0x517e73="value"`, `0x517e79="this"`, `0x517e8f="packetSize"`, `0x517e91="packetData"`, `0x517e9f="StackCookie"`, `0x517eb1="StackCookie"`; live disassembly reported no other line regular comments. Proposed-name proof: `lookup_funcs("MerchantDialogPane_HandlePacketEvent")` returned `Not found`; exact-regex name-index query returned total `0`. Type dependencies: existing `EventHandlerFacet` ordinal 742 is an opaque size-1 struct; existing `Event` is a size-`0x110` UDT. | Keep range/bytes/xrefs unchanged. Rename to `MerchantDialogPane_HandlePacketEvent`. Apply raw-entry type `bool __thiscall MerchantDialogPane_HandlePacketEvent(EventHandlerFacet *eventHandlerThis, Event *event);`. Do not declare or use a complete-object `MerchantDialogPane *` receiver in IDA: incoming ECX is the EventHandler secondary view at complete-object `+0xa0`, and the body does not consume it. `EventHandlerFacet *` records the actual facet ABI without synthetic pointer adjustment; the human source remains `MerchantDialogPane::HandlePacketEvent(Event*)`. Set function regular comment exactly: `MerchantDialogPane EventHandler secondary-slot +0x10 override. Reads packet data from Event+0x0c, handles '/' and '0' payloads, parses ObjectStatusBlob at +8, and sends a 10-byte opcode 0x3a response.` Leave address regular/repeatable and function repeatable channels empty; preserve every line comment above. | Exact secondary-slot/Event ABI, unused raw ECX, existing facet/Event types, collision-free name, and exact body; very strong | lookup exact new name; range still `[0x00517d80,0x00517ebf)` / `0x13f`; decompile has `EventHandlerFacet *eventHandlerThis` and `Event *event`, packet data through Event `+0x0c`, bool return; function regular comment exact; other entry/function channels still `""`; listed line comments exact; bytes/xrefs unchanged | apply |
| `0x005753f0` function | Exact current half-open range `[0x005753f0,0x00575419)`, end `0x00575419`, size `0x29` / 41. Name `sub_5753F0`; prototype `unsigned int __cdecl(unsigned int, int)`. Literal entry/function channels: address regular `""`; address repeatable `""`; function regular `""`; function repeatable `""`. Live disassembly reports no line comments. Proposed-name proof: `lookup_funcs("PacketBufferWriteUInt32BE")` returned `Not found`; exact-regex name-index query returned total `0`. Type dependencies are built-in `unsigned int` and `unsigned char *`; no UDT declaration is required. | Keep range/bytes/xrefs unchanged. Rename to `PacketBufferWriteUInt32BE`. Apply `void __cdecl PacketBufferWriteUInt32BE(unsigned int value, unsigned char *destination);`. Set function regular comment exactly: `Writes a 32-bit value in big-endian byte order, then writes a spare zero byte at destination+4; source ABI is value first, destination second.` Leave address regular/repeatable and function repeatable channels empty. | Exact stores, established PacketBuffer family, accepted void UInt8/UInt16 siblings, exhaustive 119-site proof that no caller consumes EAX, and collision-free name; very strong | lookup exact new name; range still `[0x005753f0,0x00575419)` / `0x29`; decompile shows four byte stores plus zero, value/destination names, void return; function regular comment exact; other channels still `""`; all 119 callers/xrefs unchanged | apply |
| `0x0054caf0` function (required support correction) | Exact current half-open range `[0x0054caf0,0x0054cc2f)`, end `0x0054cc2f`, size `0x13f` / 319. Name `sub_54CAF0`; prototype `char __stdcall(int)`. Literal entry/function channels: address regular `""`; address repeatable `""`; function regular `""`; function repeatable `""`. Preserve these line regular comments exactly, with repeatable `""` at every listed address: `0x54cb16="StackCookie"`, `0x54cb46="buffer"`, `0x54cb66="packet"`, `0x54cb67="this"`, `0x54cb83="packet"`, `0x54cb92="packet"`, `0x54cba1="destination"`, `0x54cba2="value"`, `0x54cbaf="destination"`, `0x54cbb7="value"`, `0x54cbd5="destination"`, `0x54cbd6="value"`, `0x54cbe2="destination"`, `0x54cbe3="value"`, `0x54cbe9="this"`, `0x54cbff="packetSize"`, `0x54cc01="packetData"`, `0x54cc0f="StackCookie"`, `0x54cc21="StackCookie"`; live disassembly reported no other line regular comments. Proposed-name proof: `lookup_funcs("PursuitMessageDialogPane_HandlePacketEvent")` returned `Not found`; exact-regex name-index query returned total `0`. Type dependencies: existing `EventHandlerFacet` ordinal 742 and existing size-`0x110` `Event`; the existing complete-object `PursuitMessageDialogPane` UDT is deliberately not the raw receiver. | Keep range/bytes/xrefs unchanged. Rename to `PursuitMessageDialogPane_HandlePacketEvent`. Apply raw-entry type `bool __thiscall PursuitMessageDialogPane_HandlePacketEvent(EventHandlerFacet *eventHandlerThis, Event *event);`. Do not use complete-object `PursuitMessageDialogPane *` in the raw IDA prototype: incoming ECX is its EventHandler secondary view at complete-object `+0xa0`, and the body does not consume it. The human source remains `PursuitMessageDialogPane::HandlePacketEvent(Event*)`. Set function regular comment exactly: `PursuitMessageDialogPane EventHandler secondary-slot +0x10 override; relocated duplicate of MerchantDialogPane::HandlePacketEvent with the same Event packet grammar and 10-byte opcode 0x3a response.` Leave address regular/repeatable and function repeatable channels empty; preserve every line comment above. | Exact relocated duplicate, Pursuit secondary slot, existing facet/Event types, and collision-free name; very strong | lookup exact new name; range still `[0x0054caf0,0x0054cc2f)` / `0x13f`; decompile has `EventHandlerFacet *eventHandlerThis` and `Event *event`; function regular comment exact; other entry/function channels still `""`; listed line comments exact; bytes/xrefs unchanged | apply |

Protected/no-change entity:

- `[0x00575470,0x0057547a)`, size `0x0a`: current name `?to_char_type@?$_Narrow_char_traits@DH@std@@SADABH@Z`; prototype `char __cdecl(int)`; address regular `""`; address repeatable `""`; function repeatable `""`; function regular is exactly two lines: `MSVC standard-library narrow-char lowering (_Narrow_char_traits::to_char_type), not a project packet helper.` and `STL narrow-character byte-read lowering used for direct packet byte loads; this is not a separate project packet helper.` Keep name/type/comments/function boundary unchanged.
- Existing Event local type remains unchanged: size 272/`0x110`, payload at `+0x08`, packet data at Event `+0x0c`. Do not redefine or resize Event.
- Existing ObjectStatusBlob local type remains unchanged: size 68/`0x44`, display byte at `+0x28`.
- Do not create a function at padding, change target/duplicate boundaries, overwrite line comments, hand-create vtables, rename derived vtable cells, or save/apply any unrelated IDA state.
- B002 performed no mutation. The supervisor owns Gate 2B mutation, readback, save, and catalog/checkpoint updates.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; the old signature/type blocker is closed.
- CPP block disposition: replace the blank target CPP block with exactly:

```cpp
bool MerchantDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] == '/')
        return true;

    if (packet[0] != '0')
        return false;

    ObjectStatusBlob objectStatus;
    objectStatus.m_displayStatusByte = 0x50;

    const unsigned char responseType = packet[2];
    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 3);
    const unsigned char reserved = packet[7];
    (void)reserved;

    short trailerOffset = 8;
    const int statusLength = objectStatus.ParseTaggedStatus(packet + 8);
    if (statusLength >= 0)
        trailerOffset = static_cast<short>(statusLength + 8);
    trailerOffset = static_cast<short>(trailerOffset + 4);

    const unsigned short responseValue1 =
        PacketBufferReadUInt16BE(packet + trailerOffset);
    const unsigned short responseValue2 =
        PacketBufferReadUInt16BE(packet + static_cast<short>(trailerOffset + 2));

    unsigned char response[256];
    PacketBufferWriteUInt8(0x3a, response);
    PacketBufferWriteUInt8(responseType, response + 1);
    PacketBufferWriteUInt32BE(objectId, response + 2);
    PacketBufferWriteUInt16BE(responseValue1, response + 6);
    PacketBufferWriteUInt16BE(responseValue2, response + 8);
    response[10] = 0;

    g_packetSender->QueueAndSendPacket(response, 10);
    return true;
}
```

- Target H block disposition: keep UID0001BM `RECONSTRUCTION_H` empty. This exact memory child owns only the method body.
- Required UID000083 class-owner H text. `DialogPane.h` is required because a base class must be complete at declaration; `Event` is pointer-only and is forward-declared rather than unnecessarily included:

```cpp
#include "DialogPane.h"

class Event;

class MerchantDialogPane : public DialogPane
{
public:
    MerchantDialogPane(unsigned char menuDialogType);
    virtual bool HandlePacketEvent(Event *event);

protected:
    unsigned char m_menuDialogType;
};
```

- Required UID000083 class-owner CPP text. Declarations/examples do not remain in CPP; the source includes its own header plus definitions required by emitted child method bodies, then expands the children:

```cpp
#include "MerchantDialogPane.h"

#include "Event.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"

[[CHILDREN]]
```

- Behavior preservation: literals, branch order, no guards, byte-7 touch, signed 16-bit offset, parser fallback, helper call order, spare-zero-compatible destinations, 256-byte stack local, local terminator, ten-byte send, and return values match the binary.
- Source-shape preservation: ordinary C++03 virtual/member syntax, no `override`, no IDA labels, no raw vtable/this adjustment, no manual stack cookie, and descriptive locals consistent with current project code.
- Inferred names: `responseType`, `objectId`, `reserved`, `trailerOffset`, `statusLength`, `responseValue1/2`, and `response` are descriptive, not claimed original symbols. Neutral names avoid inventing unsupported protocol semantics.
- Naming/style: existing project `m_` members, PascalCase methods, value-first PacketBuffer helpers, and `g_` global convention are retained. Behavioral fidelity and human source shape outrank cosmetic consistency.
- Third-party import directive: not applicable; this is NexusTK project code.

## Final Recommendation

Implementation callback state: every accepted ordinary by-* documentation/formal/metadata claim below is now applied at report-level specificity and has a successful scoped validator. The recommendation text is retained as the accepted design record. Supervisor-owned IDA, manual coverage, generated readback, Gate 2, and execution steps remain outstanding.

- Target UID0001BM: retain owner/emitter/reconstructable fields, raise `87/90 -> 94/95`, install exact CPP body, keep H/position/Nested unchanged, retitle prose to HandlePacketEvent while preserving the action-string title/no-code theory under historical assumptions.
- Class UID000083: raise `87/88 -> 92/94`, set a suitable declaration-order position consistent with sibling class pages if supervisor/validator requires one, install the `DialogPane.h`/`class Event;`/class declaration block in H, install the separate `MerchantDialogPane.h` plus Event/ObjectStatusBlob/PacketBuffer/Socket include and `[[CHILDREN]]` shell in CPP, and retain owner/emitter UID0000L9.
- File UID0000L9: raise `86/88 -> 90/90`; retain projected path and file ownership; document exact EventHandler method and complete generated-source graph.
- Vtable UID00031W: raise `87/90 -> 91/94`; keep blank formal; identify secondary `+0x10` exactly as HandlePacketEvent and preserve compiler-generated table policy.
- Support UID0001FF: correct to `PursuitMessageDialogPane::HandlePacketEvent(Event*)`, use 256-byte response, byte-7 read, signed-short offset, raise `91/94 -> 94/95`, and preserve all range/xref/owner evidence.
- Pursuit support class/file/vtable: remove `DialogObjectAction`, declare the canonical virtual in the class H channel, keep its CPP channel to proper header/dependency includes plus `[[CHILDREN]]`, update prose and coverage descriptions, and preserve current ownership and otherwise justified scores. Do not leave the corrected declaration/example in CPP.
- IDA: supervisor applies and verifies the three action rows using `EventHandlerFacet *` for the two raw secondary-view receivers; protected runtime helper remains unchanged.
- No items are left no-owner/non-emitting except existing compiler/generated/container artifacts outside the source method.
- Future work outside scope: exact original lexical names and final physical source-file folding may be refined only if source symbols/build artifacts appear; they do not block this implementation.

## Recommended Target Doc Changes

Implementation state: completed in UID0001BM and verified by scoped validator command `000000017540` (`2026-07-26T00:31:53-04:00`, exit `0`, `ok: 1`).

- Target path: `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`.
- Incorporate: exact EventHandler slot/signature; Event packet layout; complete input grammar; byte `+1` negative, byte `+7` touch; ObjectStatusBlob parse; short offset semantics; 256-byte local; reply/send layout; helper identities; eight inherited vtable refs; exact duplicate; range/padding; current IDA state/actions; generated marker state; ranked ownership and rejected alternatives.
- Metadata: `94/95`, owner/emitter UID000083 unchanged, reconstructable true unchanged, position blank, `Nested:0`, CPP body above, H blank.
- Proposed Item Summary: `EventHandler packet override that accepts slash actions, parses zero-prefixed merchant object responses through ObjectStatusBlob, and sends the exact ten-byte opcode 0x3a reply.`
- Preserve historically: old raw `__stdcall(int)` view, no direct callers, eight pointer refs, old action-wrapper/no-code conclusion labeled superseded, rejected owner/code forms, and exact earlier evidence dates.

## Recommended Support Doc Changes

Implementation state: completed across all listed ordinary support pages. Scoped validators `000000017543`, `000000017544`, `000000017546`, `000000017548`, `000000017549`, `000000017551`, `000000017553`, and `000000017554` all exited `0` with `ok: 1`. Manual coverage remains supervisor-owned and was not edited.

- `by-class/MerchantDialogPane.md`: install the exact H declaration/include block and separate CPP include/children block above; raise to `92/94`; replace unknown action-object/no-code wording; add EventHandler secondary offset, packet method details, exact derived inheritance, and compile/source routing.
- `by-file/MerchantDialogPane.md`: raise to `90/90`, document complete constructor/method/class source graph and retained physical split uncertainty.
- `by-type/by-vtable/MerchantDialogPaneVtables.md`: raise to `91/94`, identify secondary `+0x10` as HandlePacketEvent(Event*), list canonical EventHandler order, keep formal blank.
- `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`: replace fake wrapper/signature/body with Event contract and corrected method body; use 256-byte local and reserved read; raise to `94/95`; preserve exact duplicate/range/xref/history evidence.
- `by-class/PursuitMessageDialogPane.md`: remove `DialogObjectAction`; move/preserve its complete class declaration in H with `virtual bool HandlePacketEvent(Event *event);`; give CPP only its own/dependency includes plus `[[CHILDREN]]`; correct prose; score/owner/emitter may remain `92/94`, UID0000LA.
- `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`: identify secondary `+0x10` as EventHandler packet slot; retain `90/94`, owner/emitter UID0000BE, blank formal.
- `by-file/MessageDialogs.md`: replace stale DialogObjectAction/HandleDialogObjectResponse references with Event/HandlePacketEvent; retain `92/92` and unrelated contents.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: add the target and duplicate as UInt32BE/UInt16BE/UInt8 consumers and record Gate 2B rename/type for `0x5753f0`; retain current metadata unless broader helper implementation work changes it.
- No change to `0x575470` docs beyond adding these consumers if useful; retain compiler/runtime exclusion.

## Score And Metadata Recommendation

- Pre-callback target snapshot: `87/90`, UID000083 owner/emitter, reconstructable true, blank position/formals, `Nested:0`.
- Current applied target state: `94/95`, owner/emitter/reconstructable/position/Nested unchanged, exact formal CPP populated, H blank; scoped validator `000000017540` exited `0` with `ok: 1`.
- Reason not higher: original local/protocol lexical spellings and exact standalone-versus-folded physical source file are stripped. Neutral descriptive names are high probability but not source-symbol proof. The body is source-ready and behavior-exact despite those bounded lexical uncertainties.
- Reason not lower: exact function/range/slot/argument layout/grammar/helper path/stack local/send behavior/owner/derived refs/duplicate and destination-ready source are all independently supported.
- Score-improvement attempt:
  - Unknown virtual slot: resolved via EventHandler and vtable cells.
  - Unknown action type: resolved as Event.
  - Unknown helper at `0x575470`: resolved as protected runtime lowering/direct byte source.
  - Raw `0x5753f0`: resolved to void UInt32BE writer with exact value-first ABI, all 119 caller return uses disproved, and a destination-ready IDA handoff.
  - Unknown grammar: exhaustively mapped, including unused/reserved bytes and 16-bit offset behavior.
  - Blank C++: resolved with exact class/method formal text.
  - Misrouted class declaration: resolved by placing the complete Merchant declaration in UID000083 H and using only includes plus `[[CHILDREN]]` in UID000083 CPP.
  - Caller/reachability: resolved as vtable-only liveness, eight exact refs.
  - Source placement: resolved to existing Merchant owner route; physical folding remains nonblocking.
  - Range/padding: resolved exactly, no split needed.
- Current applied support scores: UID000083 `92/94`; UID0000L9 `90/90`; UID00031W `91/94`; UID0001FF `94/95`; Pursuit class/file/vtable remain `92/94`, `92/92`, and `90/94`; PacketBuffer support remains `87/91`.

## Open Questions With Attempted Resolution

- Original method/type question: resolved to `HandlePacketEvent(Event*)`; no remaining type blocker.
- Original local names: executable, IDB, RTTI, xrefs, current docs, duplicate, and neighboring protocol handlers were checked. No lexical symbols exist. Resolution is to use the coherent project style names in the formal body rather than IDA names; this caps confidence but does not leave source incomplete.
- Packet `+1`, `+7`, and post-status four-byte semantics: exhaustive body/duplicate/helper/support review found no read of `+1`, one discarded read of `+7`, and only a fixed skip of four bytes. Resolution is reserved/unconsumed terminology and literal offsets, not invented enum/field semantics.
- Physical file split: current by-file route, code adjacency, generated output, and class family were checked. No source archive proves standalone versus folded. Resolution is to retain UID0000L9 and preferred MerchantDialogPane.cpp; no score or code blocker remains.
- Exact EventHandler method spelling: stripped symbols prevent original proof, but the canonical project interface and multiple accepted siblings use `HandlePacketEvent`; it is the required consistent high-probability source name.
- UInt32 writer return type: resolved rather than deferred. The raw decompiler's `unsigned int` comes from an incidental final shift in EAX; every one of 119 direct call sites was audited and none consumes that value, while the already accepted UInt8/UInt16 members of the same scalar writer family are `void`. The Gate 2B type should therefore use `void`, not preserve the stale inferred integer return.
- Raw IDA receiver type: resolved to existing opaque `EventHandlerFacet *`. Both owner-specific functions are entered from the EventHandler secondary subobject at complete-object `+0xa0`; typing raw ECX as `MerchantDialogPane *` or `PursuitMessageDialogPane *` would misstate that entry ABI. The body never dereferences ECX, so the facet type preserves the binary view while source documentation retains the human complete-class member declarations.
- C++ channel routing: resolved. UID0001BM owns only its CPP method body and blank H; UID000083 H owns the complete class declaration; UID000083 CPP owns includes plus child expansion. No declaration/example remains in CPP.
- No question remains that requires deferring target implementation or keeping the score at 87.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Inspected current manual rows: UID0001BM in `by-memory/-coverage-report.md`; UID000083 in `by-class/-coverage-report.md`; UID0000L9 in `by-file/-coverage-report.md`; UID00031W in `by-type/by-vtable/-coverage-report.md`; support UID0001FF, UID0000BE, UID0000LA, and UID0001YI rows. Replace exactly after implementation:

- File `by-memory/-coverage-report.md`, replace UID0001BM row with:

```markdown
    - [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) : reconstructable : 94% : very-strong : Exact MerchantDialogPane::HandlePacketEvent(Event*) source method at EventHandler secondary slot +0x10, with eight inherited vtable refs, Event packet data at +0x0c, complete slash/zero action grammar, ObjectStatusBlob parse, signed-short trailer offset, 256-byte local response, ten-byte opcode 0x3a send, class owner/emitter UID000083, and destination-ready formal C++.
```

- File `by-class/-coverage-report.md`, replace UID000083 row with:

```markdown
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) : reconstructable : 92% : very-strong : Complete DialogPane-derived merchant/menu base with exact constructor, menu-type member, three owner vtable views, canonical EventHandler HandlePacketEvent(Event*) declaration/body route, eight derived inherited uses, compiler-only vtable lowering, and MerchantDialogPane source-file ownership.
```

- File `by-file/-coverage-report.md`, replace UID0000L9 row with:

```markdown
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) : reconstructable : 90% : very-strong : Complete MerchantDialogPane source root with class declaration, retained empty-title constructor, EventHandler packet override, exact owner-specific vtables, derived menu-family inheritance, protocol/helper dependencies, compiler-generated artifact exclusions, and bounded standalone-versus-folded physical-file uncertainty.
```

- File `by-type/by-vtable/-coverage-report.md`, replace UID00031W row with:

```markdown
- [UID:00031W][MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md) : reconstructable : 91% : very-strong : Exact MerchantDialogPane primary/EventHandler/TimerHandler vtable views with constructor stores, COL boundaries, canonical secondary +0x10 HandlePacketEvent(Event*) slot at 0x00517d80, eight inherited consumer refs, direct class owner/emitter UID000083, and source-declared/compiler-generated table policy.
```

- File `by-memory/-coverage-report.md`, replace support UID0001FF row with:

```markdown
    - [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) 0x0054caf0-0x0054cc2f | virtual handler | MessageDialogObjectResponseVirtual : reconstructable : 94% : very-strong : Exact PursuitMessageDialogPane::HandlePacketEvent(Event*) source method at EventHandler secondary slot +0x10, relocated duplicate of UID0001BM with eight inherited vtable refs, Event packet flow, ObjectStatusBlob parse, signed-short trailer offset, 256-byte local response, ten-byte opcode 0x3a send, and direct class owner/emitter UID0000BE.
```

- File `by-class/-coverage-report.md`, replace support UID0000BE row with:

```markdown
- [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md) : reconstructable : 92% : very-strong : Complete DialogPane-derived shared message/text/proxy base with exact constructor, RTTI/vtable hierarchy, 0x278 byte/dword/word/word packet-tail layout, canonical EventHandler HandlePacketEvent(Event*) override, three source-ready navigation methods, six direct derived classes, implicit virtual destructor closure through DialogPane, compiler-only wrapper/vtable exclusions, and MessageDialogs source route.
```

- File `by-type/by-vtable/-coverage-report.md`, replace support UID0001YI row with:

```markdown
- [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md) : reconstructable : 90% : very-strong : Class-owned source-declared/generated-binary PursuitMessageDialogPane RTTI/vtable inventory with exact three views/stores/slots, canonical EventHandler secondary +0x10 HandlePacketEvent(Event*) target, seven-entry base hierarchy, six RTTI-proven derived classes, implicit virtual destructor source closure, shared compiler wrapper/adjustor disposition, and direct owner/emitter UID0000BE.
```

- File `by-file/-coverage-report.md`, replace support UID0000LA row with:

```markdown
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) : reconstructable : 92% : very-strong : Message/menu-question source family with complete creator/dispatcher/class union; includes source-ready PursuitMessageDialogPane constructor, exact packet-tail layout, canonical EventHandler HandlePacketEvent(Event*) response method, previous/next/current packet methods, implicit virtual destructor closure, six direct derived classes, cross-file TextDialog/proxy consumers, and preserved split/raw/compiler/history boundaries.
```

- Reason B agent must not apply directly: all `-coverage-report.md` files are supervisor-owned collision surfaces. Auto-generated tracker/coverage rows must be refreshed by validator, not manually edited.

## Follow-Up Actions

- Supervisor: Gate 1 passed exact pre-callback SHA256 `C4F95BD012C248DBDF11B6D91833CAF6BA31F814A08247EA093A6D4097F9C444`; implementation callback completed.
- Supervisor: perform Gate 2A claim-by-claim readback against the nine ordinary destinations and the validator results below.
- Supervisor: perform the Gate 2B action table, read back exact names/types/comments/ranges/bytes/xrefs, save/checkpoint, and catalog the result. B002 did not mutate IDA.
- Supervisor: apply the exact manual coverage rows, request/inspect the validator-owned generated Merchant and MessageDialogs refresh, and validate coverage/generated results.
- Supervisor: execute/archive the report only after current exact-artifact Gate 1 re-audit as required and explicit Gate 2A/2B pass. B002 did not invoke or probe `execute_report` or any lifecycle command.
- A-agent actions: none.
- B002 future work: only exact supervisor-requested same-report reconciliation. Do not start unrelated work.

## Confidence

- Recommendation confidence: very strong (`95` target confidence recommendation).
- Score confidence: strong; `94/95` reflects complete current evidence without crossing the final `95/95` barrier.
- Remaining uncertainty: stripped original lexical spellings and final physical file folding only. Neutral inferred names are source-clean and do not alter execution.

## Validator Results

- Working directory: `source-3/project-documentation`; every command used `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240` and ran serially.
- `000000017540` at `2026-07-26T00:31:53-04:00`: `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`; exit `0`; `ok: 1`; completion/confidence `94/95`; generated refresh deferred.
- `000000017543` at `2026-07-26T00:32:11-04:00`: `by-class/MerchantDialogPane.md`; exit `0`; `ok: 1`; completion/confidence `92/94`; generated refresh deferred.
- `000000017544` at `2026-07-26T00:32:21-04:00`: `by-file/MerchantDialogPane.md`; exit `0`; `ok: 1`; completion/confidence `90/90`; generated refresh deferred.
- `000000017546` at `2026-07-26T00:32:31-04:00`: `by-type/by-vtable/MerchantDialogPaneVtables.md`; exit `0`; `ok: 1`; completion/confidence `91/94`; generated refresh deferred.
- `000000017548` at `2026-07-26T00:32:43-04:00`: `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`; exit `0`; `ok: 1`; completion/confidence `94/95`; generated refresh deferred.
- `000000017549` at `2026-07-26T00:33:02-04:00`: `by-class/PursuitMessageDialogPane.md`; exit `0`; `ok: 1`; score retained `92/94`; generated refresh deferred.
- `000000017551` at `2026-07-26T00:33:17-04:00`: `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`; exit `0`; `ok: 1`; score retained `90/94`; formal registry changed from block to blank; generated refresh deferred.
- `000000017553` at `2026-07-26T00:33:32-04:00`: `by-file/MessageDialogs.md`; exit `0`; `ok: 1`; score retained `92/92`; validator corrected UID0003PB's stale linked endpoint; 69 existing missing-reference UID warnings remain and were not introduced or manually suppressed; generated refresh deferred.
- `000000017554` at `2026-07-26T00:33:54-04:00`: `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`; exit `0`; `ok: 1`; score retained `87/91`; generated refresh deferred.
- Validator side effects were validator-owned registry/reference-index/projected-stats updates. B002 did not hand-edit generated files, coverage reports, validator state, or projected stats.
- Unresolved validation state: no scoped file failed. The 69 pre-existing MessageDialogs missing-reference warnings and deferred generated refresh require supervisor/validator follow-up but do not represent an omitted accepted ordinary-doc claim.
- Live MCP read-only result: healthy under supervisor override; all required lookups/decompiles/xrefs/bytes/types/comments completed successfully.

## Changed Files

- Created: none.
- Modified ordinary docs:
  - `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`
  - `by-class/MerchantDialogPane.md`
  - `by-file/MerchantDialogPane.md`
  - `by-type/by-vtable/MerchantDialogPaneVtables.md`
  - `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`
  - `by-class/PursuitMessageDialogPane.md`
  - `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`
  - `by-file/MessageDialogs.md`
  - `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- Modified report: `tools/leaser/Agents/Agent-B002/research/0001BM-MerchantDialogPaneActionStringVirtual-source-quality.md`, incrementally; all prior research/headings/formals/coverage payloads are retained and callback state is appended/reconciled.
- Renamed: none.
- Leases: B002 leased each ordinary page only immediately before its edit and released it immediately afterward; no B002 lease remains. No lease was needed for this report in B002's own research folder.
- Validator-owned side effects: registry/reference-index/projected-stats and one stale UID link correction; not manually edited or claimed as B002 ordinary-doc scope.
- Report execution: not run. B002 did not invoke/probe `execute_report`, validator lifecycle commands, manual moves, IDA mutation/save, coverage edits, generated edits, or tracker/audit/goal edits.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; exact SHA256 `C4F95BD012C248DBDF11B6D91833CAF6BA31F814A08247EA093A6D4097F9C444` passed the named Gate 1 reaudit before callback.
- [x] Target/support docs to update: UID0001BM, UID000083, UID0000L9, UID00031W, UID0001FF, UID0000BE, UID0001YI, UID0000LA, and PacketBuffer write-helper support.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: none declared; UID0001FF is support only.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `94/95`; Merchant class `92/94`; file `90/90`; vtable `91/94`; support duplicate `94/95`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted.
- [x] Owner/emitter/reconstructable changes to apply: target fields retained; no owner change.
- [x] Split/rename/new-child changes to apply: no range child; source/IDA method renames and stale-title historicalization specified.
- [x] Source-placement/range/IDA handoff is destination-ready: every actionable function has an exact half-open range/end/size, four literal entry/function comment channels, existing line-comment preservation, exact proposed-name collision proof, safe raw receiver/dependency type, action, and expected readback.
- [ ] Supervisor Gate 2B IDA handoff lists every exact address/entity, pre-state, proposed action, supporting type, safety constraint, and expected readback; leave this row unchecked for the supervisor.
- [x] First-draft channels fully specified: UID0001BM CPP method body; UID0001BM H blank; UID000083 H base include/Event forward/class declaration; UID000083 CPP own/dependency includes plus `[[CHILDREN]]`; no declaration/example left in CPP.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable; project-owned source and nonblank CPP method body.
- [x] Exact target/support doc facts to incorporate at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale.
- [x] Open questions closed or documented as evidence-backed bounded lexical/physical-file uncertainty.
- [x] Validators to run: scoped file validation for every callback destination; supervisor coverage validation; generated source/readback inspection.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply.

Implementation callback pass:

- [ ] Supervisor-owned IDA changes remain pending and were not applied by the B agent.
- [x] Report accepted by supervisor for implementation under `B002 UID0001BM Exact-Artifact Gate 1 Reaudit - 2026-07-26T00:19:02-04:00`.
- [x] All accepted target/support ordinary-doc details incorporated at report-level detail across the nine destinations.
- [x] Declared primary UID0001BM and required support UIDs independently verified against the ledger and post-validator destination docs; no additional report target UID was declared.
- [x] Claim And Incorporation Ledger updated with destination, command ID, and implementation state for every accepted claim; C1BM-014 remains supervisor-owned.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied exactly or retained with documented reason; manual coverage and IDA names/types remain supervisor-owned.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, exact ranges, ownership, and prior evidence dates preserved.
- [x] Open questions resolved or retained only as bounded lexical/physical-file uncertainties that do not block implementation.
- [x] Nine scoped validators run serially; every command exited `0` with `ok: 1`, and warnings/deferred work are recorded above.
- [ ] Generated CPP/H and report refresh completed by validator; each affected generated file's command ID is current, or explicit manual supervisor-owned coverage/tracker text is supplied/confirmed unchanged.
- [x] Remaining unapplied items listed exactly: supervisor Gate 2B IDA actions/readback/save/catalog; manual coverage rows and coverage validation; validator-owned generated refresh/readback; supervisor Gate 2A/2B pass; supervisor-only execute/archive lifecycle.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000017663","destination_path":"executed-b-agent-research/B002/0001BM-MerchantDialogPaneActionStringVirtual-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001BM-MerchantDialogPaneActionStringVirtual-source-quality.md","timestamp":"2026-07-26T01:13:18-04:00","uid":"0001BM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
