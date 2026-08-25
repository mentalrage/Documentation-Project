** TARGET-REPORT-UID:0004GP **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004GP NewUserMiscDialogPane HandlePacketEvent Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain the applied source-facing target/page identity `NewUserMiscDialogPane::HandlePacketEvent(Event *event)`, class owner/emitter [UID:00009F], and exact human C++ body in `NexusTK/login/NewUserMiscDialogPane.cpp`.
- Final disposition: the target is a source-authored EventHandler packet-family virtual override, not a free helper, packet parser, compiler thunk, or reply-body duplicate. Its machine entry receives the `EventHandler` facet at complete-object offset `+0xa0`; the `add ecx, -0xa0` instruction is compiler multiple-inheritance adjustment and does not appear in source.
- Verified implementation result: B007 applied the target rename, `93/95` metadata, owner/emitter/position, exact CPP, complete class H, and every accepted ordinary support synchronization; supervisor Gate 2A passed. Supervisor Gate 2B then applied and cataloged the deterministic IDA handoff as entry `0363`, after which B007 reconciled the exact readback into the affected ordinary docs and this report. Manual coverage operations, generated refresh/readback, fresh final gates, and execution/archive remain supervisor-owned workflow controls and are not claimed complete here.
- Confidence: very strong. Exact instructions, vtable slot, Event layout, sibling methods, reply callee, and three documented equivalent packet bridges agree. The historical `this - 0x28` statement is disproved: Hex-Rays shows `this - 40` while `this` is `int *`, and assembly independently proves byte adjustment `-0xa0`.
- Lifecycle authority: this report body does not assert current execution or archive state. Those states are authoritative only from this artifact's actual path plus validator-owned status/history and supervisor audit/catalog records. Durable completed facts are ordinary Gate 2A passage and supervisor Gate 2B catalog entry `0363`. Historical scope facts: assignment-time research changed only this report; the ordinary callback changed seven ordinary destinations; post-Gate2B reconciliation changed six directly affected ordinary destinations plus this report. B007 ran only scoped file validators, performed IDA checks read-only, and did not edit manual coverage, generated, audit/catalog, or lifecycle state.

## Supporting Research

- Pre-callback target snapshot: [UID:0004GP] `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacket.md`, SHA256 `0C8036953930208E32CEEB7EB2DFACA56B9D4C2379139A3D7C6B19B2257DC52B`, 1,832 bytes, 30 lines, metadata `86/91`, owner `00009F`, reconstructable true, blank emitter/position/CPP/H.
- Pre-callback class snapshot: [UID:00009F] `by-class/NewUserMiscDialogPane.md`, SHA256 `F5DA8E1141E5BC764C51B86080A3DA67D82E2F2C05EA22FF2CBE5AF58469CBF7`, 33,353 bytes, 141 lines, metadata `85/88`, file owner/emitter `0000LX`, class CPP comments plus `[[CHILDREN]]`, blank H.
- Pre-callback file snapshot: [UID:0000LX] `by-file/NewUserMiscDialogPane.md`, SHA256 `0453E05F7F27FBB347039B0A3F787A1621012621EBE5FEE406DEAA161253AF99`, 34,282 bytes, 147 lines, metadata `85/87`, projected path `NexusTK/login/`.
- Pre-callback split-index snapshot: [UID:0002Q7] `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`, SHA256 `409EE462D895C3DC047AF0C87596451118E8BB7861AE97A979A40EBFC8C0AAEB`, 27,840 bytes, 173 lines, metadata `88/91`, nonreconstructable and non-emitting, `Nested:13`.
- Pre-callback reply-support snapshot: [UID:0004GX] `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md`, SHA256 `C8C7A9B23212F61C590E4A1AE46BADEC2A1FF0600EBEB438F59960C47F93D306`, 2,418 bytes, 36 lines, metadata `86/91`, owner `00009F`, blank emitter/formals.
- Pre-callback vtable/data snapshot: [UID:00025Q] `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, SHA256 `C5CF8A14903952D4E5140C9F0ED3BB8E66015A7ADF38C3F166BF90E77B76A1E0`, 36,627 bytes, 196 lines, metadata `86/92`, nonreconstructable/non-emitting.
- Pre-callback singleton snapshot: [UID:0002XL] `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md`, SHA256 `C5C2E01C2D2633A4E1441EEE60D49A2BE51D70031CA8BA2BD9058F38D37D01C0`, 10,139 bytes, 86 lines, metadata `88/90`, file owner/emitter `0000LX`, CPP definition present, H blank.
- Post-callback exact ordinary identities and dispositions are authoritative in `Changed Files`; current target/class/file/index metadata are `93/95`, `90/93`, `89/92`, and `89/93`, while UID0004GX/UID00025Q/UID0002XL retain `86/91`, `86/92`, and `88/90`.
- Type/interface supports: [UID:00004L] `by-class/Event.md`, SHA256 `8C949A52AAF5D810407FDFFCDFDCE7397DF791E295E9C68D7301A4C4B1C93419`, and [UID:00004N] `by-class/EventHandler.md`, SHA256 `9113E1BE5C966238ECD9887AEDBD8FD77668D62375C4C5BE900DECC1EB70C402`.
- Assignment-time generated source checkpoint: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`, validator command `000000019068`, refreshed `2026-07-29T10:16:50-04:00`, SHA256 `650E5F07AAEC811A04E596DBC3F46FBE6E93A3C2319655D49E9505574BBB0987`, 15,940 bytes, 480 lines. Historical currentness checkpoints are command `000000019152`, refreshed `2026-07-29T10:43:18-04:00`, SHA256 `778BE1BFA12B1D267C9AC801DD3E75C5C8403F8605B6FDD641C01DF6B6D27786`, and command `000000019201`, refreshed `2026-07-29T10:58:40-04:00`, SHA256 `8137F17C3136366739B0E004EB198A3AD54AAB0FD10727B8293AC43DED244E22`; both remained 15,940 bytes and 480 lines. The latest waited checkpoint is command `000000019221`, refreshed `2026-07-29T11:05:07-04:00`, SHA256 `ADC119A6656AEC4792DFD15C744471E41EDA59ECD01D14BDB316031111E8F56D`, 15,940 bytes, 480 lines. Every checkpoint contains no UID0004GP marker/body, and no generated H exists. These are dated shared-output snapshots, not lifecycle-time guarantees.
- Assignment-time research-tracker checkpoint: command `000000019069`, refreshed `2026-07-29T10:18:32-04:00`, SHA256 `355FEED2F09C33BD4F00DBE9EAC1B528E97D3AB4E9EC453C6ED3A2218AC7ECCE`, 1,672,238 bytes, 6,616 lines. Historical shared checkpoints include command `000000019088`, command `000000019153` at SHA256 `1FE96D5A171A10D8E2BBF53F8553B94DCCF2D7E529B078EDBAC9BACF4024CB6A`, and command `000000019201` at SHA256 `3B57476E224BD2D353C4D3C6868C90C27AE79D368D3111453DB2D78E69902183`, 1,675,376 bytes, 6,629 lines. The latest waited checkpoint is command `000000019221`, refreshed `2026-07-29T11:05:07-04:00`, SHA256 `2E18D81FCA6DBFCAF8794D63066546A147437CCFD78AE812C9D9485CA4598A31`, 1,675,820 bytes, 6,631 lines. Every checkpoint shows UID0004GP at `86/91`, reconstructable true, with zero direct/additional/total research coverage. These are dated checkpoints; the supervisor's lifecycle-time readback is authoritative and B007 did not chase a moving global hash.
- Historical family reports were used only as leads and rechecked against current docs and live IDA: executed B013 `0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md`, B014 `0004GO-NewUserMiscDialogPaneHandleCommand-source-quality.md`, B005 `0004GL-NewUserMiscDialogPaneConstructor-source-quality.md`, B003 `0004GQ-NewUserMiscDialogPaneOnKeyDown-source-quality.md`, B004 `0004GR-NewUserMiscDialogPaneShowControlHelp-source-quality.md`, B010 `0002XL-g_pNewUserMiscDialogPane-source-quality.md`, and B004 sibling `00043X-NewUserDialogPane2HandleCreateUserPacketEvent-source-quality.md`.
- Analog source pages independently checked: [UID:0004PD] `NewUserDialogPane::HandlePacketEvent`, [UID:00043X] `NewUserDialogPane2::HandlePacketEvent`, and the current `CreateUserDialogPane` class contract. They use the same EventHandler slot, Event payload member, `-0xa0` compiler adjustment, opcode-2 filter, and source-facing signature.

## Target

- Target UID: `0004GP`.
- Additional target UIDs: none. UID0004GX, UID00009F, UID0000LX, UID0002Q7, UID00025Q, and UID0002XL are support destinations only and are not declared as report coverage.
- Declared-target inventory: one exact source-bearing method at `[0x004fc5c0,0x004fc5e6)`.
- Pre-callback target path: `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacket.md`.
- Current target path: `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md`; the old path is absent after UID-preserving validator registration.
- Assignment-time source queue row: the dated `auto-generated/-ag-research-tracker.md` by-memory `Not-Covered Files - Reconstructable` snapshot recorded `86/91`, research score `88.5`, and zero coverage. It predates this ordinary callback and is not asserted as current tracker state.
- Current supervisor classification: reconstructable source-quality target with exact method identity, packet layout, adjusted receiver interpretation, emitter route, formal code, ordinary Gate 2A, and IDA Gate 2B/catalog `0363` resolved.
- Current scores and parent state after ordinary callback: target `93/95`; canonical class owner/emitter [UID:00009F], position `3`; exact nested parent [UID:0002Q7] is `89/93`, reviewed non-emitting, under source file [UID:0000LX] at `89/92`.

## Current Target State

- Current metadata: `COMPLETION:93`, `CONFIDENCE:95`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, `EMITTER_POSITION_OPTIONAL:3`, populated exact CPP, blank target H, `Nested:0`.
- Current ordinary text uses `HandlePacketEvent(Event *)`, records Event packet data `+0x0c`, opcode `0x02`, EventHandler slot `+0x10`, compiler-only `-0xa0` receiver recovery, exact boundaries/bytes/hash/CFG, and the distinct UID0004GX reply relationship.
- Generic `HandlePacket`/`OnPacket`, raw `sub_*`, blank-emitter, and `this - 0x28` interpretations remain only in explicitly historical/evidence contexts. The complete class H and singleton extern are populated in UID00009F.
- Dated command-`19221` generated output still omitted UID0004GP and the class H before this callback. B007 ran every scoped validator with `--no-generated-refresh`; therefore no callback claim is made about current generated output, and supervisor refresh/readback remains authoritative.
- Verified implementation disposition: C01-C33 are reconciled from exact ordinary readback; C34-C36 are applied and C37 is independently verified already-present through supervisor Gate 2B/catalog `0363`. C38-C45 remain proposed supervisor coverage/generated operations. This content statement does not assert execution or archive state.

## Executive Recommendation

- Direct class owner/emitter: [UID:00009F] `NewUserMiscDialogPane`.
- Direct source file: [UID:0000LX] `NexusTK/login/NewUserMiscDialogPane.cpp`.
- Human signature: `bool NewUserMiscDialogPane::HandlePacketEvent(Event *event)`.
- Human body: read `event->m_payload.m_packet.m_data`, reject packet opcode other than `0x02`, and tail-return `HandleCreateCharacterReply(packet)`.
- Machine-only ABI: the vtable passes the secondary EventHandler facet at complete-object `+0xa0`; the entry subtracts `0xa0` before the reply-member tail jump. Source must not expose pointer arithmetic or an adjusted-receiver parameter.
- Header route: class declaration, `Event`/`KeyEvent`/`ControlPaneEvent` forward declarations, and singleton `extern` belong in the [UID:00009F] H block. The exact target H remains blank because the class page owns the declaration.
- No split is required. The target's exact 38 bytes are one modeled source function; `[0x004fc5e6,0x004fc5f0)` is ten bytes of `0xcc` alignment before the next child.

## Supervisor Active Recheck

- Historical assignment recheck: B007 `goal.md` assigned report-only source-quality research for UID0004GP with all 33 literal headings and no ordinary edits during that phase. A later explicit supervisor callback authorized the ordinary changes now recorded.
- The exact target did not require a split repair. Existing [UID:0002Q7] already provides the correct broad non-emitting index, and this target is an exact child.
- Every source-bearing item in the assigned range is represented: the entire function is `[0x004fc5c0,0x004fc5e6)`; successor bytes are alignment and outside the target.
- Existing family reports were not treated as coverage. Their claims were compared to current ordinary docs, current generated output, and fresh live MCP reads.
- The requested blockers are resolved rather than restated: method identity, Event type and packet member, opcode/result layout, receiver adjustment, owner/emitter/source placement, target CPP, class H, IDA handoff, and manual coverage payload are all implementation-ready.

## Inference Research Guidance Check

- Direct IDA facts are labeled as such: bytes, ranges, instructions, xrefs, frame, comments, vtable cells, and existing types.
- Documentation evidence is labeled separately: Event/EventHandler declarations, family source pages, existing ownership routes, and generated source ordering.
- Inference is limited to original source spelling/access control and standalone source-file probability. The method name is very strong inference because the exact base virtual slot is already named `HandlePacketEvent(Event *)` and multiple sibling implementations use it.
- Existing documentation assumptions were treated as provisional. `HandlePacket`, `OnPacket`, a byte adjustment of `0x28`, a generic packet-event wrapper type, and CashShop/file folding were all independently tested and rejected where contradicted.
- Wave2/Wave3 mentions, caches, or workflow labels were ignored as stale and were not used as evidence.
- Final source prioritizes exact runtime behavior first, human mid-2000s source shape second, and project naming consistency third. No finalized source identifier retains an IDA-generated `sub_`, `arg_`, or raw pointer-arithmetic spelling.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Best resolution | Classification |
| --- | --- | --- | --- |
| Method name | Compared EventHandler slot `+0x10`, current sibling declarations, three documented 38-byte bridges, and vtable cell `0x0061d494`. | `HandlePacketEvent` | Very-strong inferred original spelling; exact interface role. |
| Event argument type | Current IDA `Event` exists as a 272-byte UDT; project EventHandler declares `bool HandlePacketEvent(Event *)`. | `Event *event` | Direct type/layout plus interface evidence. |
| Packet pointer field | Target reads `[event+0x0c]`; Event declares packet kind `+0x08`, data `+0x0c`, size `+0x10`. | `event->m_payload.m_packet.m_data` | Direct layout fact. |
| Packet layout | Target checks data byte zero for `2`; reply reads bytes `1`, `2`, and `3+`. | `[0]=opcode`, `[1]=result/status`, `[2]=ANSI byte length`, `[3..]=ANSI message` | Direct target/reply evidence. |
| Adjusted receiver | Hex-Rays `this - 40` is dword arithmetic; assembly subtracts exact byte `0xa0`; vtable base is the EventHandler facet. | compiler-only EventHandler `+0xa0` to complete-object normalization | Direct ABI fact. |
| Return behavior | Mismatch returns zero; match tail-jumps to reply helper, which returns one on every path. | `false` on non-2; helper's `bool` result on opcode 2 | Direct control flow. |
| Reply helper name | Current page and behavior agree on create-character result handling; no packet mutation occurs. | `HandleCreateCharacterReply(const unsigned char *packet)` | Strong descriptive/source-family inference. |
| Owner/emitter | Sole vtable cell belongs to NewUserMiscDialogPane's secondary table; class/file split already exists. | class owner/emitter UID00009F in file UID0000LX | Direct vtable and documentation route. |
| Source placement | Constructor, handlers, singleton, generated file, and address cluster are class-specific. | standalone `NexusTK/login/NewUserMiscDialogPane.cpp` | Strong source-tree inference. |
| Header shape | Pre-callback class H was blank and generated H absent; emitted method bodies required a declaration. | complete class declaration now present in UID00009F H; target H blank | Project source-quality rule plus sibling pattern. |
| Target filename | Existing `HandlePacket` slug no longer matches the exact interface contract. | rename suffix to `HandlePacketEvent` | Source-quality normalization. |

Rejected alternatives:

- `HandlePacket` and `OnPacket`: weaker generic names that ignore the established EventHandler virtual slot.
- `PacketEvent *`, `void *event`, or a synthetic wrapper: current canonical Event provides the exact layout and interface contract.
- `this - 0x28`: dimensionally wrong interpretation of Hex-Rays pointer subtraction and contradicted by `add ecx, -0xa0`.
- Explicit source `reinterpret_cast<char *>(this) - 0xa0`: compiler ABI lowering, not handwritten method logic.
- Free helper or static dispatcher: disproved by the sole NewUserMiscDialogPane vtable entry and adjusted facet receiver.
- CashShop ownership: the packet sender is a dependency; it does not own the dialog's virtual method.
- Fold into `CreateUserDialogs.cpp` or `NewUserDialogPane.cpp`: umbrella/caller proximity is weaker than the existing class-specific source route and generated file.
- Add Event kind, packet-size, or null guards: absent from the exact body and would alter behavior.
- Inline the reply handler: the binary preserves a distinct method at `0x004fcb10`; source should preserve that call boundary.

No source-quality blocker remains for the assigned method. UID0004GX still merits its own later exhaustive body/frame pass, but its current name, argument contract, packet fields, and return behavior are sufficient and directly verified for this caller.

## Evidence Standards Used

- Primary evidence: healthy live read-only IDA MCP calls for health, function lookup, bounded analysis, decompilation, disassembly, bytes, xrefs, item bounds, stack frame, comments, entity collision search, and type inspection.
- Secondary binary evidence: exact raw-byte SHA256, vtable pointer cluster, constructor/cleanup/destructor vtable-base xrefs, adjacent padding, and direct tail-jump relationship.
- Documentation evidence: current Event, EventHandler, class/file/index/reply/vtable/singleton pages and documented sibling packet handlers.
- Dated generated evidence: UID00009F/UID0002XL source output and absence of UID0004GP/H output at assignment command `19068`, historical preflight commands `19152`/`19201`, and the later waited pre-callback command `19221`.
- Negative evidence: no ordinary caller, no function at the exclusive end, no end xrefs, historical pre-rename collision count zero, no target class type, no Event kind/size/null access, and no packet mutation. Gate 2B added only the accepted function-repeatable comment; the other three comment channels remain absent.
- Evidence ladder result: exact machine behavior and ABI are direct; source name and file placement are high-probability inference constrained by the base interface and existing source-family structure. This supports `93/95` without claiming original symbols were recovered.

## Evidence Checked

- IDA MCP database session: `1da2b2ae`. The post-callback authoritative re-read used this same live session after the shared database advanced.
- Current `server_health`: `status=ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready with 2,068 entries, and the worker responsive to every bounded query. `auto_analysis_ready=false` remained a health field, not a query blocker.
- Exact supervisor Gate 2B applied checkpoint: SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`. It is historical after an unrelated later supervisor transaction, but remains the exact catalog-`0363` application checkpoint.
- Historical intermediate shared-IDB checkpoint: SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, saved `2026-07-29T14:42:53.5091352-04:00`. B007 independently rehashed it and confirmed bounded no drift; it is no longer current after supervisor UID0002MZ Gate 2B.
- Current authoritative saved IDB identity: SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`. B007 independently rehashed the physical file and performed the bounded UID0004GP target/protected comparison read-only without mutating or saving IDA.
- Exact pre-Gate2B backup: `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID0004GP-20260729-1420.i64`, SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, last write `2026-07-29T14:12:44.7229687-04:00`. Historical earlier identities include no-drift SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, post-callback SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, assignment-time SHA256 `2823AB8A51B713C9D5B98093169C692D185F2DCEDEB2F283495DD48A9269F4C3`, and any intervening `08D31F...` identity. None is asserted as current.
- MCP calls: `lookup_funcs` at target/end/reply; `analyze_function`; `decompile`; `disasm` with 32-instruction cap; `get_bytes` for target and padding; `xrefs_to` for target/end/reply/vtable cell and three vtable bases; `stack_frame`; `get_comments`; `inspect_items`; `entity_query` for target-name collisions; `type_inspect` for Event, EventHandler, NewUserMiscDialogPane, and DialogPane.
- The pre-callback docs and hashes listed in Supporting Research were read directly and remained byte-identical through command `19221`; callback-era post-validation identities are recorded separately in `Changed Files`.
- Manual by-class, by-file, and by-memory coverage rows were reread during the pre-callback currentness check; exact dated identities, observed rows/absences, and destination-ready payloads are recorded below. B007 did not edit those files.
- Generated source and tracker were reread as dated moving checkpoints only; command `19221` still omitted UID0004GP/H output and still recorded zero report coverage before this callback.
- Historical command-`19201` and command-`19221` live MCP readbacks reconfirmed the assignment-time state against the dated `2823AB...9F4C3` IDB.
- Historical post-callback re-read against `03F102...E5DA` established the same target/protected state recorded below.
- Historical no-drift re-read against `0E0AF9...AB481` established the same target/protected state recorded below.
- Historical `3C8F31...5B69` prestate: target was `sub_4FC5C0`, `[0x004fc5c0,0x004fc5e6)`, size `0x26`, declaration `char __thiscall(int *this, int)`, frame argument `arg_0 +0x8/4 _DWORD`, and all four comment channels absent. Historical Hex-Rays rendered `sub_4FC5C0(int *this, int a2)`, packet-data read at `a2 + 12`, `(Pane *)(this - 40)`, and tail call to `sub_4FCB10`; disassembly independently proved `add ecx, 0FFFFFF60h`.
- Supervisor Gate 2B catalog entry `0363` applied exact current identity `NewUserMiscDialogPane__HandlePacketEvent`, range `[0x004fc5c0,0x004fc5e6)`, size `0x26`, declaration `bool __thiscall(void *eventHandlerFacet, Event *event)`, 14 instructions, four blocks, complexity 1. First item remains one-byte code `[0x004fc5c0,0x004fc5c1)` with that name/type.
- Current frame is `__saved_registers +0x0/4 _DWORD`, `__return_address +0x4/4 _UNKNOWN *`, and `event +0x8/4 Event *`. Address-regular, address-repeatable, and function-regular comments remain absent. Function-repeatable is exactly: `NewUserMiscDialogPane EventHandler-facet HandlePacketEvent override. Reads Event packet data, accepts opcode 0x02, restores complete this by -0xA0, and tail-dispatches HandleCreateCharacterReply; other opcodes return false; packet[1] is the reply result byte.`
- Current authoritative bytes remain exact and byte-identical to this report. The target has one data xref from `0x0061d494`, the exclusive end has zero xrefs, and the reply has one code xref from tail jump `0x004fc5e1`. Vtable bases `0x0061d424`, `0x0061d484`, and `0x0061d4b4` retain the same three lifecycle refs each; cell `0x0061d494` remains unnamed/untyped four-byte data containing target address `0x004fc5c0` with absent address comments; padding and successor remain unchanged.
- Bounded `905D1A...604C1` no-drift result: target range/name/prototype/frame/function-repeatable comment, exact 38 bytes, sole vtable data xref, sole reply edge, absent end xrefs, ten-byte `0xcc` padding, successor `sub_4FC5F0`, protected reply `sub_4FCB10`, cell `0x0061d494`, all three vtable-base reference sets, and Event/EventHandler/DialogPane/NewUserMiscDialogPane type dispositions exactly match catalog `0363` and the historical `296ED...3CF8B` applied checkpoint.
- Bounded current `412DA7...519CD` no-drift result: the same complete target/protected inventory remains exact after supervisor UID0002MZ Gate 2B. Current entity queries still return one function and one name at `0x004fc5c0`; no target-specific name, prototype, frame, comment, byte, xref, padding, vtable, reply, successor, or dependency-type drift was found.
- Current types remain bounded and unchanged: `Event` is a `0x110` UDT with `m_payload +0x08`; `EventHandler` remains pointer-form size 4; `NewUserMiscDialogPane` remains absent; `DialogPane` remains a `0x26c` UDT. B007's post-Gate2B reconciliation was read-only and made no IDA mutation or save.
- Historical B007 action record for the assignment-time research pass: B007 invoked no validator, lifecycle command, IDA write, lease command, generated refresh, or report-execution command.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0004GP | Exact function range is `[0x004fc5c0,0x004fc5e6)`, 38 bytes, byte SHA256 `A6FAA4777A34C9771D6E14C1498090D2DEF228368AB55A692C54C875C446E27B`. | direct | MCP lookup/bytes/disasm | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Binary Evidence | incorporate | applied |
| C02 | 0004GP | Exclusive end is not a function and `[0x004fc5e6,0x004fc5f0)` is ten `0xcc` bytes before OnKeyDown. | direct | MCP lookup/items/bytes | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Boundaries | incorporate | applied |
| C03 | 0004GP | The target has 14 instructions, four basic blocks, and cyclomatic complexity 1. | direct | MCP disasm/analyze | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Behavior And CFG | incorporate | applied |
| C04 | 0004GP | Sole inbound route is vtable cell `0x0061d494` in EventHandler base `0x0061d484`, slot `+0x10`. | direct | MCP xrefs/vtable bytes | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Vtable And Reachability | incorporate | applied |
| C05 | 0004GP | Machine entry receives the EventHandler facet at complete object `+0xa0` and subtracts `0xa0` before reply dispatch. | direct | `add ecx,0xffffff60`; table identity | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Behavior And ABI | incorporate | applied |
| C06 | 0004GP | Human signature is `bool NewUserMiscDialogPane::HandlePacketEvent(Event *event)`. | very strong | EventHandler contract plus sibling bridges | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Status And Source Shape | incorporate | applied |
| C07 | 0004GP | Packet data is `event->m_payload.m_packet.m_data` at exact Event `+0x0c`. | direct | Event UDT/docs plus instruction read | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Packet Contract | incorporate | applied |
| C08 | 0004GP | Non-`0x02` packet opcode returns false with no side effect. | direct | exact CFG/disassembly | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Behavior | incorporate | applied |
| C09 | 0004GP | Opcode `0x02` tail-dispatches unchanged packet pointer to `HandleCreateCharacterReply`. | direct | exact tail jump/decompile/xref | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Behavior | incorporate | applied |
| C10 | 0004GP | Match path returns reply helper result; current helper returns true on every path. | direct | target/reply decompilation | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Return Semantics | incorporate | applied |
| C11 | 0004GP | Related reply packet layout is byte 0 opcode, byte 1 status, byte 2 ANSI length, bytes 3 onward ANSI text. | direct | target/reply decompilation | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Packet Contract | incorporate | applied |
| C12 | 0004GP | Target does not read Event kind/packet size, guard null, copy, mutate, retain, or free packet data. | direct negative | bounded instruction inventory | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Negative Evidence | incorporate | applied |
| C13 | 0004GP | Rename page/title from generic HandlePacket to HandlePacketEvent while preserving UID/range. | strong | exact interface naming | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / path and title | incorporate | applied |
| C14 | 0004GP | Canonical owner remains UID00009F. | direct | vtable/class route | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / `CANONICAL_OWNER` | already-present | already-present |
| C15 | 0004GP | Emitter becomes UID00009F. | very strong | source-authored method and class route | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / `EMITTER_UIDS` | incorporate | applied |
| C16 | 0004GP | Optional emitter position becomes `3`, after constructor/command and before key/help methods. | strong | physical/source order and sibling class pattern | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / `EMITTER_POSITION` | incorporate | applied |
| C17 | 0004GP | Target score becomes `93/95`. | strong | exact behavior, ABI, route, formals, and IDA handoff | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / metadata and Score Rationale | incorporate | applied |
| C18 | 0004GP | Target CPP becomes the exact formal method body in this report. | very strong | exact source mapping | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / formal `CPP` header | incorporate | applied |
| C19 | 0004GP | Target H remains blank because UID00009F owns the complete class declaration. | very strong | declaration ownership | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / formal `H` header and Source Shape | already-present | already-present |
| C20 | 0004GP | `HandlePacket`/`OnPacket` and raw `sub_*` spellings are superseded history only. | strong | interface/callee resolution | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Historical Assumptions | historicalize | applied |
| C21 | 0004GP | `this - 0x28` is invalid; `this - 40` dwords and `add ecx,-0xa0` prove `-0xa0`. | direct | decompile plus disassembly | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` / Historical Assumptions and ABI | reject-invalid | applied |
| C22 | 00009F | Class method inventory uses exact `HandlePacketEvent(Event *)`, packet contract, slot, and receiver facts. | very strong | target research | `by-class/NewUserMiscDialogPane.md` / Method Notes And Evidence | incorporate | applied |
| C23 | 00009F | Class H receives the exact complete declaration and singleton extern; CPP retains `[[CHILDREN]]`. | strong | class family and generated-source need | `by-class/NewUserMiscDialogPane.md` / formal `H` and `CPP` headers | incorporate | applied |
| C24 | 00009F | Class score becomes `90/93`. | strong | now-complete declaration plus five source-ready methods | `by-class/NewUserMiscDialogPane.md` / metadata and Score Rationale | incorporate | applied |
| C25 | 00009F | Generic wrapper names, unresolved callback identity, and deferred declaration become superseded history. | strong | exact target and header resolution | `by-class/NewUserMiscDialogPane.md` / Historical Assumptions | historicalize | applied |
| C26 | 0000LX | Standalone `NexusTK/login/NewUserMiscDialogPane.cpp` is the chosen direct source route; CreateUserDialogs stays umbrella only. | strong | existing file route, generated file, class cluster | `by-file/NewUserMiscDialogPane.md` / Status And Ownership | incorporate | applied |
| C27 | 0000LX | File inventory describes the exact packet virtual and reply contract and lists the target as source-emitting. | strong | target research | `by-file/NewUserMiscDialogPane.md` / Proposed Contents And Reconstruction Notes | incorporate | applied |
| C28 | 0000LX | File score becomes `89/92`. | strong | source route and method/header blockers closed | `by-file/NewUserMiscDialogPane.md` / metadata and Score Rationale | incorporate | applied |
| C29 | 0002Q7 | Parent index records the exact source-ready packet child, `-0xa0` ABI, packet layout, padding, and class emitter. | very strong | target evidence | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` / child inventory and source decisions | incorporate | applied |
| C30 | 0002Q7 | Parent index score becomes `89/93`; nonreconstructable/non-emitting state remains. | strong | one more exact child closed | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` / metadata and Score Rationale | incorporate | applied |
| C31 | 0004GX | Reply support records exact source signature, byte layout, caller, unchanged pointer, and always-true return; score/emitter remain unchanged because this report uses UID0004GX only as support and does not claim its separate exhaustive source-quality pass. | direct/strong | fresh reply decompile and sole xref | `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` / Status, Evidence, and C++ Disposition | incorporate | applied |
| C32 | 0002XL | Singleton page states UID00009F H owns `extern`; its CPP remains the storage definition and score/route remain `88/90`, owner/emitter `0000LX`. | strong | current page plus class-H plan | `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md` / Autogen And Ownership | incorporate | applied |
| C33 | 00025Q | Broad data page records exact NewUserMisc vtable cluster `[0x0061d420,0x0061d4bc)`, three bases, packet slot, and lifecycle refs. | direct | MCP bytes/xrefs | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` / Observed Contents And Evidence | incorporate | applied |
| C34 | 0004GP | Supervisor IDA rename action is exact `sub_4FC5C0` -> `NewUserMiscDialogPane__HandlePacketEvent`. | strong | collision-free interface identity; catalog `0363` exact readback | IDA `0x004fc5c0` / Gate 2B rename action | incorporate | applied |
| C35 | 0004GP | Supervisor IDA type action uses `bool __thiscall NewUserMiscDialogPane__HandlePacketEvent(void *eventHandlerFacet, Event *event)` without creating a fake complete class. | strong | current type state, adjusted ABI, catalog `0363` exact readback | IDA `0x004fc5c0` / Gate 2B type action | incorporate | applied |
| C36 | 0004GP | Supervisor IDA function-repeatable comment records opcode, Event data, `-0xa0`, and reply dispatch exactly. | strong | exact behavior; catalog `0363` exact readback | IDA `0x004fc5c0` / Gate 2B function-repeatable-comment action | incorporate | applied |
| C37 | 0004GP | Target bytes/bounds/frame saved/return entries/address comments/function-regular comment/vtable/padding are protected unchanged. | direct | catalog `0363` protected-state readback | IDA `0x004fc5c0` / Gate 2B protected-state constraints and readback | already-present | already-present |
| C38 | 0004GP | Insert exact target row in manual by-memory coverage after UID0002Q7. | direct | current row absent | `by-memory/-coverage-report.md` / insert UID0004GP after UID0002Q7 | incorporate | proposed |
| C39 | 0002Q7 | Replace stale parent manual row with exact `89%` non-emitting-index summary. | direct | current row stale at 82% | `by-memory/-coverage-report.md` / replace UID0002Q7 row | incorporate | proposed |
| C40 | 00009F | Replace stale class manual row with exact `90%` source-ready class/header summary. | direct | current row stale at 82% | `by-class/-coverage-report.md` / replace UID00009F row | incorporate | proposed |
| C41 | 0000LX | Replace stale file manual row with exact `89%` standalone-source summary. | direct | current row stale at 85% | `by-file/-coverage-report.md` / replace UID0000LX row | incorporate | proposed |
| C42 | 0002XL | Replace stale singleton manual row that says `0xffffffff`/85% with current null-initialized/88% state and extern route. | direct | current row contradicts current page | `by-memory/-coverage-report.md` / replace UID0002XL row | incorporate | proposed |
| C43 | 0004GX | Insert exact reply support row after UID0004GP because no manual row exists. | direct | current row absent | `by-memory/-coverage-report.md` / insert UID0004GX after UID0004GP | incorporate | proposed |
| C44 | 0004GP | Generated CPP must gain the target marker/body in source order after approved callback validation. | strong | target emitter/source route | `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` / UID0004GP marker and body readback | incorporate | proposed |
| C45 | 00009F | Generated NewUserMiscDialogPane.h must be created from class H after approved callback validation. | strong | class H route; current H absent | `auto-generated/NexusTK/login/NewUserMiscDialogPane.h` / UID00009F class declaration readback | incorporate | proposed |

Post-Gate2B ledger truth: C01-C13, C15-C18, and C20-C36 are `applied`; C14, C19, and C37 are `already-present`; supervisor-owned C38-C45 remain `proposed`. The IDA states are backed by supervisor catalog entry `0363`; no row claims manual coverage, generated, final-gate, execution, or archive completion.

## Positive Evidence Summary

- Exact target bytes and CFG implement a two-way packet opcode bridge with no unrelated work.
- Vtable cell `0x0061d494` is the sole inbound xref and sits at `+0x10` in the NewUserMiscDialogPane EventHandler secondary table based at `0x0061d484`.
- EventHandler's documented slot `+0x10` name is `HandlePacketEvent(Event *)`.
- Event's documented packet payload places `m_data` at Event `+0x0c`, exactly matching the target read.
- Assembly performs `add ecx,-0xa0`, matching the established Pane/EventHandler secondary-subobject offset.
- The match path tail-jumps to the independently modeled reply method at `0x004fcb10`; the callee consumes bytes 1/2/3+, confirming the target's byte-zero opcode role.
- Documented NewUserDialogPane, NewUserDialogPane2, and CreateUserDialogPane family handlers use the same source signature and compiler-adjusted bridge shape.
- Existing class/file/index/source outputs already establish the exact owner and standalone login source route; only this child's emitter/formals/header synchronization were missing.

## IDA MCP Facts

- Server: healthy read-only session `1da2b2ae`, Hex-Rays and string cache ready. Supervisor Gate 2B catalog entry `0363` was applied at historical checkpoint SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, saved `2026-07-29T14:22:15.9735862-04:00`. Historical intermediate no-drift checkpoint `905D1A...604C1` was superseded by current authoritative saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`; bounded target/protected readback remains unchanged.
- Function: `NewUserMiscDialogPane__HandlePacketEvent`, `[0x004fc5c0,0x004fc5e6)`, size `0x26`, prototype `bool __thiscall(void *eventHandlerFacet, Event *event)`, 14 instructions, four blocks, complexity 1.
- Exact bytes: `55 8B EC 8B 45 08 8B 50 0C 0F B6 02 83 E8 02 74 06 32 C0 5D C2 04 00 89 55 08 81 C1 60 FF FF FF 5D E9 2A 05 00 00`.
- Byte SHA256: `A6FAA4777A34C9771D6E14C1498090D2DEF228368AB55A692C54C875C446E27B`.
- First item: head `0x004fc5c0`, end `0x004fc5c1`, size 1, code, name `NewUserMiscDialogPane__HandlePacketEvent`, type `bool __thiscall(void *eventHandlerFacet, Event *event)`.
- End/padding item: head `0x004fc5e6`, end `0x004fc5f0`, size 10, data-classified `0xcc` padding, no name/type; no function or xrefs at `0x004fc5e6`.
- Current decompiler parameters: `eventHandlerFacet : void *`, `event : Event *`; no stable non-parameter local survives; decompiler user-comment map remains empty.
- Current frame: `__saved_registers +0x0`, size 4, `_DWORD`; `__return_address +0x4`, size 4, `_UNKNOWN *`; `event +0x8`, size 4, `Event *`.
- Current target comments: address-regular absent; address-repeatable absent; function-regular absent; function-repeatable exactly `NewUserMiscDialogPane EventHandler-facet HandlePacketEvent override. Reads Event packet data, accepts opcode 0x02, restores complete this by -0xA0, and tail-dispatches HandleCreateCharacterReply; other opcodes return false; packet[1] is the reply result byte.`
- Sole target xref: data cell `0x0061d494`. Sole reply xref: code tail jump `0x004fc5e1` from target to `0x004fcb10`.
- Historical pre-rename collision checks for `NewUserMiscDialogPane__HandlePacketEvent` returned functions total 0 and names total 0. Current exact entity queries return one function and one name, both at `0x004fc5c0`, as expected after application.
- Current types: `Event` exists as UDT size 272 with vftable `+0x0`, `m_type +0x4`, gap `+0x5..+0x8`, `m_payload +0x8` size 264; `DialogPane` exists as UDT size 620; `NewUserMiscDialogPane` is absent; `EventHandler` currently appears as a four-byte pointer-form type and must not be multiplied into `EventHandler **` accidentally.
- Vtable cluster bytes cover `[0x0061d420,0x0061d4bc)`. Primary base `0x0061d424`, EventHandler base `0x0061d484`, and tertiary base `0x0061d4b4` each have constructor, raw-cleanup, and scalar-destructor store refs.
- EventHandler cells include `0x0061d488 -> 0x004fc780`, `0x0061d48c -> 0x004fc5f0`, `0x0061d490 -> 0x0049ea60`, `0x0061d494 -> 0x004fc5c0`, then inherited/compiler entries.
- Reply function: `sub_4FCB10`, `[0x004fcb10,0x004fccee)`, size `0x1de`; reads status byte 1, length byte 2, ANSI bytes from 3, writes bounded 256-byte ANSI and 256-wide buffers, calls `MultiByteToWideChar`, shows alert text, closes/dismisses on success, and returns 1 on every path.
- Pre-Gate2B backup: `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID0004GP-20260729-1420.i64`, SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes. This and all earlier IDB identities are historical only.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004fc5c0,0x004fc5e6)` | UID0004GP current HandlePacketEvent page | source virtual packet bridge | true | UID0002Q7 / class UID00009F | current 93/95 | ordinary owner/emitter/formals applied and scoped-validated; Gate 2A passed; Gate 2B/catalog `0363` applied and reconciled; coverage/generated gates remain separate |
| `[0x004fc5e6,0x004fc5f0)` | no separate target | ten-byte `0xcc` alignment | no source body | UID0002Q7 context | not scored | preserve as padding evidence |
| `[0x004fc5f0,0x004fc77c)` | UID0004GQ OnKeyDown | next source virtual | true | UID0002Q7 / UID00009F | 89/91 | existing source-ready sibling |
| `[0x004fcb10,0x004fccee)` | UID0004GX HandleCreateCharacterReply | direct reply method | true | UID0002Q7 / UID00009F | 86/91 unchanged | support synchronization only |
| `[0x0061d420,0x0061d4bc)` | inside UID00025Q | NewUserMiscDialogPane RTTI/vtable cluster | compiler/data evidence | UID00025Q | 86/92 parent unchanged | non-emitting support |
| `0x0069b488` | UID0002XL | singleton pointer definition | true | UID0000LX | 88/90 unchanged | CPP definition existing; extern moves to class H route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061d494` | data cell contains `0x004fc5c0` | sole inbound target route; EventHandler slot `+0x10` |
| `0x004fc5e1` | tail `jmp 0x004fcb10` | matching packet forwards unchanged data pointer to reply member |
| `0x004fc5c0` | no ordinary code caller | expected virtual-only reachability, not dead code |
| `0x004fc5e6` | zero xrefs | exact exclusive end before alignment |
| `0x0061d424` | refs `0x004fb6ae`, `0x004fbfd3`, `0x005029f6` | primary vtable lifecycle stores |
| `0x0061d484` | refs `0x004fb6b4`, `0x004fbfd9`, `0x005029fc` | EventHandler vtable lifecycle stores |
| `0x0061d4b4` | refs `0x004fb6be`, `0x004fbfe3`, `0x00502a06` | tertiary vtable lifecycle stores |

## Documentation Evidence And IDA Status

- Current target/class/file/index docs use the exact `HandlePacketEvent(Event *)` identity, populated target CPP, complete class H, standalone file route, and source-ready parent-index child disposition. Generic wrapper/raw-name/blank-output assumptions remain only in explicitly historical sections.
- Current EventHandler source defines the packet-family virtual as `HandlePacketEvent(Event *event)` at slot `+0x10`.
- Current Event source defines `EventPacketPayload` as packet kind `+0x08`, data `+0x0c`, and size `+0x10`; this target reads only data.
- Current NewUserDialogPane source-ready analog at UID0004PD is byte-shape equivalent and uses the exact recommended source pattern.
- Current NewUserDialogPane2 source/current IDA history independently confirms the same `-0xa0` adjusted-facet model and human source signature.
- Current ordinary class H is populated with the complete declaration and singleton extern; target H remains blank under that declaration ownership. Dated generated checkpoints precede this callback and therefore still lack the corresponding generated H.
- Current IDA state now matches the report's machine-facing handoff: exact name/prototype/frame/comment are applied under catalog `0363`; target bytes, vtable cell, reply, padding, successor, and dependency types remain protected and unchanged. The prior `sub_4FC5C0`/`arg_0`/blank-comment state is historical only.
- Assignment-time generated CPP command `19068`, historical currentness commands `19152`/`19201`, and latest waited command `19221` contain UID0004GL, UID0004GO, UID0004GQ, UID0004GR, and UID0002XL but no UID0004GP; generated H is absent at every checkpoint. These are historical pre-callback facts. B007 used `--no-generated-refresh`, so a later supervisor generated refresh/readback remains required.
- Assignment-time research tracker command `19069`, historical shared commands `19088`/`19153`/`19201`, and latest waited command `19221` all record zero report coverage for UID0004GP. They are dated checkpoints only; generated/tracker currentness is authoritative from the supervisor's lifecycle-time readback, and lifecycle state is authoritative from the artifact path plus validator-owned status/history and supervisor audit/catalog records.
- Historical `this - 40` prose was not wrong as pointer arithmetic, but interpreting it as 40 bytes or `0x28` bytes was wrong. Current prose must state 40 dwords equals `0xa0` bytes.

## Ranked Ownership Analysis

### 1. NewUserMiscDialogPane class, UID00009F

- Evidence for: sole NewUserMiscDialogPane EventHandler vtable slot; constructor/cleanup/destructor installation of the same vtable base; complete-object `-0xa0` recovery; adjacent same-class methods; existing class/file/index route.
- Evidence against: original symbol is absent and the complete class UDT is not present in current IDA.
- Decision: recommended direct owner and emitter. Missing original symbols do not outweigh exact virtual-slot identity.

### 2. NewUserMiscDialogPane source file, UID0000LX

- Evidence for: exact class-specific constructor/handlers/reply cluster, singleton definition, current projected `NexusTK/login/` route, and existing generated `NewUserMiscDialogPane.cpp`.
- Evidence against: original source filename string is not present and older docs kept a CreateUserDialogs fold alternative.
- Decision: recommended direct file owner. The fold alternative is now weaker than the established standalone route and should remain historical only.

### 3. CreateUserDialogs umbrella or CashShopRequest dependency

- Evidence for: create-user call flow and shared packet sender dependencies.
- Evidence against: neither owns the NewUserMiscDialogPane vtable, receiver, singleton, or exact method family.
- Decision: reject as direct owner. CreateUserDialogs remains umbrella context; CashShopRequest remains a dependency.

### Proposed new file/grouping, if applicable

- No new by-file page is needed. Existing UID0000LX is the recommended source file.
- Likely full contents: complete class declaration in generated H; constructor, HandleCommand, HandlePacketEvent, OnKeyDown, ShowControlHelp, reply method, destructor family where source-ready, and singleton definition in CPP.
- Rejected contents: raw cleanup body, raw no-route packet sender islands, switch tables, vtable arrays, adjusted destructor thunks, and alignment bytes.
- Source-file inference: standalone narrow dialog source under `NexusTK/login/`, with CreateUserDialogs as umbrella only.

## Source Placement

- Recommended source: `NexusTK/login/NewUserMiscDialogPane.cpp` and generated peer header `NexusTK/login/NewUserMiscDialogPane.h`.
- The exact target body belongs between HandleCommand and OnKeyDown in physical/source order.
- UID00009F owns the complete declaration; UID0004GP owns only the method definition.
- UID0002XL continues to own the singleton storage definition while its extern declaration is centralized with the complete class declaration.
- Rejected placements: `CashShopRequest.cpp`, `CreateUserDialogs.cpp`, `NewUserDialogPane.cpp`, EventDispatcher source, and a standalone packet helper file.
- Remaining placement uncertainty: none material to current reconstruction. No original filename string was found, so the precise historical filename is inferred, but the current standalone route is the highest-probability and internally consistent choice.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and must not expand: `[0x004fc5c0,0x004fc5e6)`.
- Predecessor attached command-switch data ends at `0x004fc5c0`; it belongs to UID0004GO context and must not be absorbed.
- Successor `[0x004fc5e6,0x004fc5f0)` is exactly ten `0xcc` bytes and must remain non-source padding.
- Successor function UID0004GQ begins exactly at `0x004fc5f0` and remains separate.
- No child creation, merge, range extension, duplicate body, or target reclassification is required.
- Parent UID0002Q7 remains a non-emitting index. Its `Nested:13` count does not change because this exact child already exists.
- Target reclassification is only semantic/source-quality: generic HandlePacket page becomes exact HandlePacketEvent source method while retaining UID/range.

## Negative Evidence Summary

- No ordinary direct caller exists; that does not imply dead code because the vtable data xref is exact and unique.
- No function or xref exists at `0x004fc5e6`; the ten successor bytes are not hidden code.
- Historical pre-rename collision queries returned zero exact-name functions and zero exact-name entries. Current post-Gate2B entity queries return exactly one function and one name at `0x004fc5c0`, which is the required applied state rather than a collision.
- No `NewUserMiscDialogPane` IDA UDT exists; this prevents a safe full class declaration in IDA but does not block a pointer-only adjusted-facet target prototype.
- Current EventHandler type is pointer-form, so using `EventHandler *` in the IDA prototype risks a false double pointer and is rejected.
- Target does not inspect Event `m_type`, packet kind, packet size, status byte, message length, or message text. Those belong to dispatcher/reply layers.
- Target does not null-check Event or packet data. Adding guards would change exact behavior.
- Target does not own, copy, retain, mutate, or free packet data.
- Raw sender islands at `0x004fca20` and `0x004fcac0` are unrelated no-route evidence and do not own this virtual method.
- Generic packet helper, reply-inline, CashShop, and CreateUserDialogs ownership alternatives were checked and rejected.

## IDA Rename / Type / Comment Recommendations

The target had one deterministic Gate 2B mutation row, applied and read back by the supervisor under catalog entry `0363`. Dependencies needing no mutation are listed separately so the action table remains atomic.

| Entity | Literal historical prestate | Supervisor action classification | Exact action | Collision/dependency evidence | Exact applied readback | Negative constraints |
| --- | --- | --- | --- | --- | --- | --- |
| Function `[0x004fc5c0,0x004fc5e6)`; first item `[0x004fc5c0,0x004fc5c1)` | Name `sub_4FC5C0`; declaration `char __thiscall(int *this, int)`; first item size 1/code; Hex-Rays parameters `this : int *`, `a2 : int`; no stable non-parameter local; decompiler user-comment map empty; frame `__saved_registers +0x0/4 _DWORD`, `__return_address +0x4/4 _UNKNOWN *`, `arg_0 +0x8/4 _DWORD`; address-regular absent; address-repeatable absent; function-regular absent; function-repeatable absent. | apply | Rename to `NewUserMiscDialogPane__HandlePacketEvent`; apply exact declaration `bool __thiscall NewUserMiscDialogPane__HandlePacketEvent(void *eventHandlerFacet, Event *event)`; set exact function-repeatable comment `NewUserMiscDialogPane EventHandler-facet HandlePacketEvent override. Reads Event packet data, accepts opcode 0x02, restores complete this by -0xA0, and tail-dispatches HandleCreateCharacterReply; other opcodes return false; packet[1] is the reply result byte.` Leave the other three comment channels absent. | Historical exact-name function query total 0 and names query total 0. `Event` exists once as size `0x110`; `NewUserMiscDialogPane` is absent; EventHandler is pointer-form, so `void *eventHandlerFacet` is the safe exact adjusted receiver without a fake full layout or double pointer. | Catalog `0363` readback matches exactly: name/prototype applied; parameters `eventHandlerFacet : void *`, `event : Event *`; frame argument at `+0x8/4` named `event` and typed `Event *`; saved/return frame members unchanged; no new locals; function-repeatable comment exact; address-regular absent; address-repeatable absent; function-regular absent; bytes/range/xrefs unchanged. Current exact entity queries return one function/name at `0x004fc5c0`. Hex-Rays exposes Event packet data and explicit byte adjustment on the facet; human source remains the member method. | Do not create a full NewUserMiscDialogPane UDT; do not change Event/EventHandler/DialogPane; do not create code at end/padding; do not alter vtable cells; do not rename/type/comment UID0004GX in this target callback; do not add null guards or source semantics to IDA comments; do not change bytes, boundaries, or stack saved/return entries. |

Read-only dependencies/protected facts verified unchanged by Gate 2B:

- `Event`: already exists, size `0x110`; `m_payload` starts at `+0x08`; packet data is `+0x0c`. No change recommended.
- `DialogPane`: already exists, size `0x26c`; this matches constructor allocation and no-added-field evidence. No change recommended.
- `NewUserMiscDialogPane`: absent. Do not invent a full or zero-size layout in this target pass; the safe target prototype does not require it.
- `EventHandler`: current type inspection reports pointer-form size 4. Do not apply another pointer layer.
- `0x0061d494`: item `[0x0061d494,0x0061d498)`, size 4, data, unnamed/untyped; address-regular absent; address-repeatable absent; function comment channels not applicable because it is data. Preserve exact cell value `0x004fc5c0`; no action recommended.
- `0x004fcb10`: current `sub_4FCB10`, range `[0x004fcb10,0x004fccee)`, address-regular absent, address-repeatable absent, function-regular absent, function-repeatable absent. It is a protected support dependency. A separate UID0004GX pass should own any eventual exhaustive IDA mutation.
- Protected predecessor/successor: command switch material before `0x004fc5c0`, ten `0xcc` bytes `[0x004fc5e6,0x004fc5f0)`, and UID0004GQ start `0x004fc5f0` remain byte-for-byte unchanged.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Behavior, signature, owner, emitter, source placement, and callee contract are resolved.
- Target CPP block exact insertion text:

```cpp
bool NewUserMiscDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] != 0x02)
    {
        return false;
    }

    return HandleCreateCharacterReply(packet);
}
```

- Target H block disposition: remain blank. The declaration belongs in the class page H block, not in the method page or prose-only sample.
- UID00009F class H block exact insertion text:

```cpp
class ControlPaneEvent;
class Event;
class KeyEvent;
class NewUserMiscDialogPane;

extern NewUserMiscDialogPane *g_pNewUserMiscDialogPane;

class NewUserMiscDialogPane : public DialogPane
{
public:
    NewUserMiscDialogPane();
    virtual ~NewUserMiscDialogPane();

protected:
    virtual void HandleCommand(int commandId, int notifyCode);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnKeyDown(KeyEvent *event);
    virtual bool ShowControlHelp(ControlPaneEvent *event);

private:
    bool HandleCreateCharacterReply(const unsigned char *packet);
};
```

- UID00009F CPP block retains its current comments and `[[CHILDREN]]`; no class declaration is duplicated in CPP.
- UID0002XL CPP retains exact definition `NewUserMiscDialogPane *g_pNewUserMiscDialogPane;`; UID0002XL H remains blank because the extern is centralized in UID00009F H.
- Exact behavior preservation: the source performs only the packet-data read, opcode comparison, false mismatch return, and reply call. The compiler supplies the secondary-receiver adjustment and tail-call lowering.
- Human source shape: the code follows the documented Event/EventHandler family, uses a named packet pointer, hides ABI arithmetic, and resembles ordinary mid-2000s C++ rather than decompiler output.
- No synthetic guards, packet wrapper, status parsing, or ownership logic is introduced.
- Third-party import directive: not applicable; this is first-party NexusTK UI source.

## Final Recommendation

- Retain the applied UID0004GP page/title/method `NewUserMiscDialogPaneHandlePacketEvent` / `NewUserMiscDialogPane::HandlePacketEvent`, preserved UID/range, `93/95`, owner/emitter `00009F`, optional position `3`, exact CPP, and blank target H.
- Retain UID00009F's exact complete H declaration/singleton extern and `90/93` score, with CPP comments plus `[[CHILDREN]]` unchanged.
- Retain UID0000LX's resolved standalone route, exact inventory, and `89/92` score.
- Retain UID0002Q7's exact packet child facts and `89/93`, nonreconstructable/non-emitting state, and `Nested:13`.
- Retain UID0004GX's synchronized caller/signature/packet-layout facts with unchanged `86/91` and blank emitter/formals.
- Retain UID0002XL's class-H extern route, CPP definition, and unchanged `88/90` metadata.
- Retain UID00025Q's exact NewUserMisc vtable cluster/base/slot/lifecycle facts and unchanged `86/92` non-emitting state.
- Retain the supervisor-applied target IDA row exactly as cataloged in entry `0363`: `NewUserMiscDialogPane__HandlePacketEvent`, the accepted adjusted-facet prototype, exact function-repeatable comment, and `event +0x8 : Event *` frame readback. The protected reply function, vtable/dependency types, bytes, xrefs, padding, and neighboring functions remain unchanged.
- Timeless supervisor workflow control: manual coverage application, generated refresh/current readback, and fresh final gates must precede any supervisor execution/archive action. Ordinary Gate 2A and IDA Gate 2B are durable completed facts; this control makes no claim that the remaining supervisor stages are complete.

## Recommended Target Doc Changes

- Pre-callback path: `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacket.md`; it is absent after the UID-preserving rename.
- Current path: `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md`.
- Applied readback preserves UID `0004GP`, exact range, `Nested:0`, owner `00009F`, reconstructable true, and all still-valid historical evidence.
- Applied readback is `93/95`, emitter `00009F`, optional position `3`, and the exact formal CPP.
- Target H remains blank with explicit proof that UID00009F H owns the declaration.
- Current target sections cover exact status, behavior/ABI, packet layout, bytes/hash/CFG, vtable/xrefs, frame/comments, source shape, rejected alternatives, support relationships, scores, and current IDA disposition.
- Generic HandlePacket/OnPacket names, raw `sub_*` names, unresolved packet-wrapper assumptions, blank-emitter rationale, and the invalid `0x28` interpretation are preserved only as superseded history with reasons.
- Negative constraints remain explicit: no guards, no Event-kind/size reads, no packet mutation/ownership, no reply inlining, no source-level receiver arithmetic, and no range expansion.

## Recommended Support Doc Changes

- `by-class/NewUserMiscDialogPane.md` [UID00009F]: exact H declaration installed; CPP `[[CHILDREN]]` retained; generic method row replaced; target ABI/packet/vtable evidence, source-ready status, generated-H expectation, historical assumptions, and `90/93` score applied. Post-Gate2B reconciliation now records catalog `0363`, the exact function identity/prototype/frame/comment, protected no-drift evidence, backup/current IDB identities, and historical `3C8F...5B69` prestate.
- `by-file/NewUserMiscDialogPane.md` [UID0000LX]: standalone login file applied as the resolved direct route; generic reply-wrapper row replaced with exact HandlePacketEvent signature/body/slot; generated H and source order recorded; fold uncertainty historicalized; score `89/92` applied. Post-Gate2B source evidence uses the cataloged function identity while retaining source-level `HandlePacketEvent(Event *)`.
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` [UID0002Q7]: target child row, fresh MCP facts, packet layout, `-0xa0` explanation, exact padding, source-ready route, and `89/93` applied; nonreconstructable/non-emitting metadata and all raw/table/padding exclusions retained. Its current inventory and xrefs now use the applied target IDA identity and explicitly preserve the protected reply/padding/successor state.
- `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` [UID0004GX]: exact source signature, sole caller/tail route, status/length/text byte layout, no packet mutation, always-true return, and class-declaration relationship applied; `86/91`, owner `00009F`, and blank emitter/formals retained because this report contributes support facts without claiming UID0004GX's separate exhaustive source-quality pass. The caller evidence now names the applied catalog-0363 function while `sub_4FCB10` remains intentionally protected for its own future pass.
- `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` [UID00025Q]: incomplete NewUserMisc-following prose replaced with exact cluster `[0x0061d420,0x0061d4bc)`, three vtable bases, EventHandler slot `0x0061d494`, and lifecycle store refs; score/metadata retained. Post-Gate2B text records the exact cataloged slot target and confirms all cell bytes/base xrefs remained unchanged.
- `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md` [UID0002XL]: inspected after Gate 2B and left byte-identical because its class-H extern ownership, CPP storage definition, null/lifecycle evidence, and `88/90` owner/emitter route were already exact.
- `by-class/Event.md` and `by-class/EventHandler.md`: inspected after Gate 2B with no content or metadata change. They already contain the documented contract and their current IDA dependency states remained protected.
- No changes to raw cleanup/sender/table/padding pages. They remain separate evidence/no-code artifacts.

## Score And Metadata Recommendation

| Page | Pre-callback | Current ordinary state | Metadata disposition | Rationale |
| --- | --- | --- | --- | --- |
| UID0004GP target | 86/91 | 93/95 | owner unchanged; emitter `00009F`; position `3`; reconstructable true; CPP exact; H blank | All behavior, ABI, signature, route, formals, ordinary documentation, Gate 2A, and cataloged IDA Gate 2B are resolved; manual coverage/generated/final gates remain supervisor work. |
| UID00009F class | 85/88 | 90/93 | owner/emitter `0000LX` unchanged; H populated; CPP children retained | Complete declaration and exact packet virtual close major source/output blockers; reply/destructor bodies remain separate work. |
| UID0000LX file | 85/87 | 89/92 | path/FILE owner unchanged | Standalone route, exact method inventory, header output, and packet bridge are now resolved. |
| UID0002Q7 index | 88/91 | 89/93 | nonreconstructable/non-emitting/Nested13 unchanged | Exact target child and family ABI/packet facts improve the index without making the aggregate source-emitting. |
| UID0004GX reply | 86/91 | unchanged | owner/reconstructable unchanged; emitter/formals remain blank | Synchronized caller/layout facts are support-only, not a full exhaustive reply report. |
| UID00025Q vtable parent | 86/92 | unchanged | no owner/emitter change | Exact NewUserMisc subcluster detail does not resolve the broad mixed range. |
| UID0002XL singleton | 88/90 | unchanged | owner/emitter `0000LX`; CPP retained; own H blank | Extern centralization improves source organization without changing storage confidence. |

Reason target is not lower:

- Exact bytes/hash/range/CFG, vtable-only route, interface slot, Event field, opcode, callee, return, and compiler adjustment are direct.
- Source name and body match multiple documented sibling bridges and current base declarations.
- Owner/emitter/file/header/manual/IDA plans are complete.

Reason target is not higher:

- Original PDB/source spelling and access-control order are not recovered.
- The complete NewUserMiscDialogPane UDT is absent in current IDA, so the applied Gate 2B prototype intentionally uses `void *eventHandlerFacet` rather than inventing a layout or double pointer.
- UID0004GX's full source body and destructor family remain outside this target's exhaustive scope.
- Supervisor validation requirements still include final manual coverage application, generated H/CPP readback, and fresh final gates; the IDA readback is complete under catalog `0363`.

Score-improvement attempt:

- Generic name blocker: resolved through EventHandler slot and sibling source comparison.
- Packet type/layout blocker: resolved through current Event UDT/docs and reply decompile.
- Receiver blocker: resolved dimensionally and by exact `-0xa0` assembly/vtable evidence.
- Emitter/source blocker: resolved through unique class vtable plus established UID00009F/UID0000LX route.
- C++/header blocker: resolved with exact target CPP and complete class H payload.
- IDA blocker: resolved and applied with one deterministic collision-free mutation row that avoids unsafe type creation; catalog `0363` and historical applied checkpoint `296ED2...3CF8B` are exact. Historical intermediate `905D1A...604C1` and current shared IDB `412DA7...519CD` both retain the same bounded target/protected readback without drift.

## Open Questions With Attempted Resolution

- What is the virtual name? Resolved as `HandlePacketEvent` from exact EventHandler slot `+0x10` and documented siblings.
- What is the argument type? Resolved as `Event *`; the current Event UDT is exact size `0x110` and supplies packet data at `+0x0c`.
- Is packet byte zero a marker or result? Resolved as opcode `0x02`; reply handler reads result/status at byte 1.
- What are the remaining packet fields? Resolved for this relationship: byte 2 is one-byte ANSI length and bytes 3 onward are ANSI message data.
- Is the receiver adjustment `0x28`, 40 bytes, or `0xa0`? Resolved as `0xa0` bytes. Hex-Rays subtracts 40 `int` elements and assembly subtracts `0xa0` directly.
- Should source expose the adjusted receiver? Resolved no; it is compiler multiple-inheritance lowering.
- Is the function a member, helper, or thunk? Resolved as a source virtual member bridge. The body is source logic even though its entry receives an adjusted facet.
- Who emits it? Resolved as class UID00009F through file UID0000LX.
- Where does the declaration belong? Resolved in UID00009F H; target H stays blank.
- Should the reply body be inlined? Resolved no; preserve distinct `HandleCreateCharacterReply` method boundary.
- Should the file remain standalone or folded? Resolved to current standalone `NexusTK/login/NewUserMiscDialogPane.cpp`; umbrella relationship remains contextual only.
- Questions remaining unresolved: no blocker remains for this target. Original private/protected spelling order and exact historical filename are not provable, but the recommended choices are high-probability, consistent, and do not justify decompiler-like final source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Assignment-time manual report identities inspected:

- `by-memory/-coverage-report.md`: SHA256 `14C3CAABD4FF3C2DD1243DBF5A4893C3C5F56C57798AE7FCF47F1A4593A3D96E`, 2,075,138 bytes, 4,711 lines, last write `2026-07-29T10:16:28.0056533-04:00`.
- `by-class/-coverage-report.md`: SHA256 `60CA40088F6B790D9E08428B529483A9013DC5A1E288794D5E0F4A864EAFCAE4`, 270,422 bytes, 625 lines, last write `2026-07-29T10:16:28.0213855-04:00`.
- `by-file/-coverage-report.md`: SHA256 `73784B99C54064D578653DB15F996806F93FF4E967CCFC886A8C12345A46BEE6`, 162,550 bytes, 317 lines, last write `2026-07-29T10:16:28.0284780-04:00`.

Dated currentness-preflight snapshots at `2026-07-29T10:52:52-04:00`:

- `by-memory/-coverage-report.md`: SHA256 `C7C2CBFDC6BCDF2E83ADDC07CC04F140E8A53625D41CF8D6AF46DD472253C9D8`, 2,078,812 bytes, 4,716 lines, last write `2026-07-29T10:42:54.3507462-04:00`.
- `by-class/-coverage-report.md`: SHA256 `3181A460DA51C7CDDF6FC722229EA4A9713494B330DE2240DB1C0BF42EB68736`, 270,665 bytes, 625 lines, last write `2026-07-29T10:42:54.3580551-04:00`.
- `by-file/-coverage-report.md`: SHA256 `14E853356D3B3367B4FB99092AF8FC4987092F048DB1F343C8F251C1AE8E88DD`, 162,710 bytes, 317 lines, last write `2026-07-29T10:42:54.3670434-04:00`.
- Exact rows/absences remained applicable: UID0002Q7 is the stale `82%` row at line 2167; UID0004GP and UID0004GX remain absent and belong immediately after UID0002Q7 before UID00019V; UID0002XL is the stale `85%`/`0xffffffff` row at line 4624; UID00009F is stale `82%` at class line 363; UID0000LX is stale `85%` at file line 186; UID00025Q remains an accurate ignored `86%` no-op at memory line 4216. Shared files may advance again, so the supervisor must repeat literal anchor checks immediately before applying the payloads.

Command-`19201` Gate 1 currentness snapshots at `2026-07-29T11:03:46-04:00`:

- `by-memory/-coverage-report.md`: SHA256 `A4CB3B979D1BA221FB8A40B27497992D37880BF5C0B54F7143F34148091FB5FD`, 2,082,115 bytes, 4,722 lines, last write `2026-07-29T10:57:49.6067119-04:00`.
- `by-class/-coverage-report.md`: SHA256 `91E531941902D7EB9D4C3BCBB9CC58B7385F223C1E82B17C70FE7069FBA99354`, 270,961 bytes, 625 lines, last write `2026-07-29T10:57:49.6180705-04:00`.
- `by-file/-coverage-report.md`: SHA256 `7ED5B1C29EDB238363AE743F78AF63871102F8B5AC6E0D688D397A2A00E3D511`, 162,827 bytes, 317 lines, last write `2026-07-29T10:57:49.6240708-04:00`.
- Exact operations remain applicable after concurrent additions: UID0002Q7 is still the stale `82%` row at line 2167; UID0004GP and UID0004GX remain absent and still belong immediately after UID0002Q7 before UID00019V; UID0002XL is still the stale `85%`/`0xffffffff` row, now at line 4630; UID00009F remains stale `82%` at class line 363; UID0000LX remains stale `85%` at file line 186; UID00025Q remains an accurate ignored `86%` no-op, now at memory line 4222. The exact UID0002Q7 replacement below deliberately uses classification `ignored`, matching its ordinary nonreconstructable/non-emitting split-index state and direct split-index analogs. The supervisor must still repeat literal anchor checks immediately before application.

Latest command-`19221` final-preflight snapshots at `2026-07-29T11:10:42-04:00`:

- `by-memory/-coverage-report.md`: SHA256 `4590B3D98DBA30CB219E064E793186C941E766EE4B539856B3D6ADAD16DFC8FE`, 2,082,208 bytes, 4,722 lines, last write `2026-07-29T11:04:41.0920698-04:00`.
- `by-class/-coverage-report.md`: SHA256 `91E531941902D7EB9D4C3BCBB9CC58B7385F223C1E82B17C70FE7069FBA99354`, 270,961 bytes, 625 lines, last write `2026-07-29T10:57:49.6180705-04:00`.
- `by-file/-coverage-report.md`: SHA256 `7ED5B1C29EDB238363AE743F78AF63871102F8B5AC6E0D688D397A2A00E3D511`, 162,827 bytes, 317 lines, last write `2026-07-29T10:57:49.6240708-04:00`.
- Exact operations and anchors remain unchanged from the command-`19201` checkpoint: UID0002Q7 is stale `82%` at memory line 2167; UID0004GP/UID0004GX are absent immediately after that row; UID0002XL is stale at memory line 4630; UID00025Q remains an ignored `86%` no-op at memory line 4222; UID00009F remains stale at class line 363; UID0000LX remains stale at file line 186. The replacement payload remains exact and keeps UID0002Q7 classified `ignored`.

1. Replace the current UID0002Q7 by-memory row exactly:

```text
        - [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) 0x004fb630-0x004fccee | class method/helper cluster | NewUserMiscDialogPaneCoreAndPacketHelpers : ignored : 89% : very-strong : Reviewed non-emitting nested index for the NewUserMiscDialogPane constructor, exact virtual handlers, reply path, raw no-route cleanup/packet islands, tables, and padding; UID0004GP is the source-ready EventHandler HandlePacketEvent override at slot +0x10 with Event packet data +0x0c, opcode 0x02, compiler-only -0xa0 receiver normalization, class emitter UID00009F, and exact human C++.
```

2. Immediately after that UID0002Q7 row, insert these two child rows in this order:

```text
            - [UID:0004GP][0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent](by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md) 0x004fc5c0-0x004fc5e6 | virtual method | NewUserMiscDialogPane::HandlePacketEvent : reconstructable : 93% : very-strong : Exact 38-byte EventHandler packet-family override at secondary slot +0x10; reads Event::m_payload.m_packet.m_data at +0x0c, rejects opcodes other than 0x02, compiler-normalizes the +0xa0 EventHandler receiver, and tail-returns HandleCreateCharacterReply with the unchanged packet pointer.
            - [UID:0004GX][0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply](by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md) 0x004fcb10-0x004fccee | class method | NewUserMiscDialogPane::HandleCreateCharacterReply : reconstructable : 86% : very-strong : Direct reply method reached only by UID0004GP; reads result byte 1 and ANSI length byte 2, copies bytes from offset 3 into bounded 256-byte narrow and wide buffers, converts with MultiByteToWideChar, shows alert text, closes/dismisses on success, and returns true.
```

3. Replace the current UID00009F class row exactly:

```text
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md) : reconstructable : 90% : very-strong : Source-ready login/create-user customization dialog class with complete H declaration and singleton extern, exact no-added-field DialogPane layout, constructor/command/HandlePacketEvent/key/help method routes, opcode-0x02 Event packet bridge at secondary slot +0x10, reply packet layout, singleton/vtable lifecycle evidence, non-emitting raw/compiler islands, exact child split, and standalone UID0000LX source placement.
```

4. Replace the current UID0000LX file row exactly:

```text
- [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md) : reconstructable : 89% : very-strong : Standalone NexusTK/login/NewUserMiscDialogPane.cpp/.h source route with complete class declaration, singleton extern/definition, exact constructor and virtual method children, source-ready HandlePacketEvent(Event *) opcode-0x02 bridge, direct reply relationship, non-emitting raw cleanup/sender/table exclusions, and CreateUserDialogs retained only as umbrella context.
```

5. Replace the current UID0002XL by-memory row exactly:

```text
        - [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md) 0x0069b488-0x0069b48c | global pointer | g_pNewUserMiscDialogPane : reconstructable : 88% : very-strong : Exact zero-initialized NewUserMiscDialogPane singleton pointer slot with lifecycle refs at 0x004fb687, 0x004fb68e, 0x004fbfff, 0x00502400, and 0x00502a22; CPP storage definition emits through UID0000LX and the extern declaration is centralized in UID00009F's complete class H block.
```

6. UID00025Q current manual row was inspected. No replacement is required because its path, score `86%`, ignored/non-emitting broad disposition, and mixed-owner summary remain accurate; target-specific vtable detail belongs in the ordinary UID00025Q page and exact UID0004GP row.

7. Generated tracker/report rows must not be edited manually. Supervisor should refresh them through approved validator/lifecycle flow after ordinary implementation and manual coverage work.

Reason B007 must not apply these rows: all `-coverage-report.md` files are supervisor-owned collision points under the active workflow.

## Follow-Up Actions

- The following entries are timeless role/workflow controls. Their presence does not assert current lifecycle completion; gate, execution, and archive state is authoritative only from the artifact path, validator-owned status/history, and supervisor audit/catalog records.
- Historical ordinary callback result: B007 leased, edited, scoped-validated, and released each accepted ordinary destination; C01-C33 and exact post-callback identities are reconciled below.
- Historical completed Gate 2A fact: the supervisor independently verified the applied ordinary claims, formals, metadata, historicalization, validator results, and unchanged dependencies.
- Historical completed Gate 2B fact: the supervisor applied and verified the single exact target IDA row, saved the database, preserved protected dependencies, and cataloged the result as entry `0363`; B007 then reconciled that readback into the six affected ordinary docs and this report.
- Supervisor: apply the exact manual coverage operations after current-row recheck.
- Supervisor: perform final generated CPP/H refresh and physical readback; commands `19068`/`19069`, `19152`/`19153`, `19201`, and `19221` remain dated pre-callback checkpoints only.
- Supervisor: run fresh final report gates and execute/archive lifecycle only after all independent checks pass.
- Future separate B-agent work: UID0004GX full source-quality/body/frame/IDA pass and NewUserMiscDialogPane destructor-family source-quality pass. These do not block UID0004GP.

## Confidence

- Recommendation confidence: very strong (`95`). The exact interface slot, bytes, Event layout, receiver adjustment, reply edge, and sibling methods converge.
- Score confidence: strong. `93/95` reflects complete target research/formals plus passed ordinary Gate 2A and cataloged IDA Gate 2B, while preserving caps for absent original symbols, the incomplete UID0004GX/destructor-family scope, and still-pending manual/generated/final supervisor readbacks.
- Packet-layout confidence: direct for all four fields relevant to this relationship.
- Owner/emitter confidence: direct at class level and strong at standalone file level.
- Remaining uncertainty: original access-control ordering and exact historical filename are inferred, not recovered. They do not require raw/decompiler names in final source and do not block implementation.

## Validator Results

- Historical assignment-time fact: B007 invoked no validator during report-only research.
- Callback working directory for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`; validator reported physical root `C:\FastStorage\NTK_Sources\source-3\project-documentation`.

| Command ID | Timestamp | Exact scoped command target | Exit / result | Generated effect |
| --- | --- | --- | --- | --- |
| `000000019263` | `2026-07-29T12:45:58-04:00` | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` | exit `0`, `ok:1`; registered UID-preserving path change, `93/95`, emitter `00009F`, position `3`, CPP block, and rewrote three UID links | skipped by `--no-generated-refresh` |
| `000000019265` | `2026-07-29T12:47:29-04:00` | `by-class/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; registered `90/93`, H block, and retained CPP block | skipped |
| `000000019267` | `2026-07-29T12:48:39-04:00` | `by-file/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; registered `89/92` | skipped |
| `000000019268` | `2026-07-29T12:49:36-04:00` | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | exit `0`, `ok:1`; registered `89/93` | skipped |
| `000000019269` | `2026-07-29T12:50:12-04:00` | `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` | exit `0`, `ok:1`; metadata unchanged | skipped |
| `000000019270` | `2026-07-29T12:51:12-04:00` | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` | exit `1`; validator state serialization raised `MemoryError` before a document result | no successful refresh |
| no command ID | immediately after `19270` | same UID00025Q scoped retry | process startup failed with CLR HRESULT `0x80004005`; no validator job was created | none |
| `000000019271` | `2026-07-29T12:52:12-04:00` | `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md` | exit `0`, `ok:1`; metadata unchanged | skipped |
| `000000019272` | `2026-07-29T12:52:29-04:00` | UID00025Q retry | exit `0`, `ok:1`; existing missing reference UID00036V warning remained bounded to pre-existing page content | skipped |

- Fresh post-IDB-reconciliation scoped validation batch, run serially with an immediate B007 lease/release around each file:

| Command ID | Timestamp | Exact scoped command target | Exit / result | Generated effect |
| --- | --- | --- | --- | --- |
| `000000019291` | `2026-07-29T13:54:23-04:00` | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` | exit `0`, `ok:1`; exact `93/95` target state retained | skipped by `--no-generated-refresh` |
| `000000019293` | `2026-07-29T13:54:26-04:00` | `by-class/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; exact `90/93` class state retained | skipped |
| `000000019294` | `2026-07-29T13:54:29-04:00` | `by-file/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; exact `89/92` file state retained | skipped |
| `000000019295` | `2026-07-29T13:54:32-04:00` | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | exit `0`, `ok:1`; exact `89/93` parent-index state retained | skipped |
| `000000019296` | `2026-07-29T13:54:35-04:00` | `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` | exit `0`, `ok:1`; metadata unchanged | skipped |
| `000000019297` | `2026-07-29T13:54:38-04:00` | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` | exit `0`, `ok:1`; existing missing reference UID00036V warning remained bounded to pre-existing page content | skipped |
| `000000019298` | `2026-07-29T13:54:42-04:00` | `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md` | exit `0`, `ok:1`; metadata unchanged | skipped |

- Post-Gate2B reconciliation validation batch, run serially with immediate B007 lease/release around each changed ordinary file:

| Command ID | Timestamp | Exact scoped command target | Exit / result | Generated effect |
| --- | --- | --- | --- | --- |
| `000000019452` | `2026-07-29T14:28:25-04:00` | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` | exit `0`, `ok:1`; exact catalog-0363 target identity/frame/comment and protected no-drift evidence retained | skipped by `--no-generated-refresh` |
| `000000019465` | `2026-07-29T14:29:09-04:00` | `by-class/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; current `90/93` class state and post-Gate2B evidence retained | skipped |
| `000000019475` | `2026-07-29T14:29:42-04:00` | `by-file/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; current `89/92` source route and cataloged method identity retained | skipped |
| `000000019485` | `2026-07-29T14:30:39-04:00` | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | exit `0`, `ok:1`; current `89/93` index and protected reply/padding/successor facts retained | skipped |
| `000000019496` | `2026-07-29T14:31:33-04:00` | `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` | exit `0`, `ok:1`; support-only caller/current IDA relationship retained with metadata/formals unchanged | skipped |
| `000000019502` | `2026-07-29T14:32:22-04:00` | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` | exit `0`, `ok:1`; bounded pre-existing missing-reference warning for UID00036V remained; exact vtable readback retained | skipped |

- Historical later-shared-IDB currentness reconciliation batch, run serially after bounded read-only no-drift comparison of then-current `905D1A...604C1` against the historical `296ED...3CF8B` applied checkpoint:

| Command ID | Timestamp | Exact scoped command target | Exit / result | Generated effect |
| --- | --- | --- | --- | --- |
| `000000019518` | `2026-07-29T14:47:34-04:00` | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` | exit `0`, `ok:1`; current/applied-checkpoint distinction and complete bounded no-drift evidence retained | skipped by `--no-generated-refresh` |
| `000000019521` | `2026-07-29T14:48:13-04:00` | `by-class/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; class current-IDB evidence rebased without metadata/formal change | skipped |
| `000000019524` | `2026-07-29T14:48:45-04:00` | `by-file/NewUserMiscDialogPane.md` | exit `0`, `ok:1`; file source route and target-specific no-drift evidence retained | skipped |
| `000000019527` | `2026-07-29T14:49:15-04:00` | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | exit `0`, `ok:1`; parent-index current IDB identity and target/protected state retained | skipped |
| `000000019531` | `2026-07-29T14:49:51-04:00` | `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` | exit `0`, `ok:1`; protected reply identity/comments/sole caller edge retained | skipped |
| `000000019534` | `2026-07-29T14:50:27-04:00` | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` | exit `0`, `ok:1`; bounded pre-existing missing-reference warning for UID00036V remained; exact cell/base/xref no-drift state retained | skipped |

- Exact command form for each successful scoped pass: `python .\tools\validator.py --mode file --file <relative-path> --apply --no-generated-refresh --queue-timeout 240`.
- The post-Gate2B commands also performed validator-owned projected-stat/incremental updates as normal side effects; B007 did not edit those generated/project-level files by hand. No generated refresh, lifecycle command, `execute_report`, IDA mutation/save, or manual coverage edit was run by B007.

## Changed Files

- Historical report-only scope: only this report changed before callback. Historical authorized callback scope: seven ordinary destinations below plus this same report. Post-Gate2B reconciliation and the later `905D1A...604C1` currentness pass changed the six directly affected ordinary destinations (target, class, file, parent index, reply support, and vtable aggregate) plus this report; UID0002XL, Event, and EventHandler were inspected and needed no edit. B007 did not edit manual coverage, generated/project-level files directly, IDA, audit/catalog/lifecycle files, goal/notes, or validator runtime state by hand.
- Rename readback: old target path `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacket.md` is absent; current UID0004GP path is the `HandlePacketEvent` path below.
- All immediate B007 edit/validator leases were released. Final shared lease report contained no B007 row for these destinations.

| UID | Ordinary target/support path | Pre-callback SHA256 | Current post-Gate2 reconciliation SHA256 | Current bytes / lines | Claim mapping and exact disposition |
| --- | --- | --- | --- | ---: | --- |
| 0004GP | `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md` | `0C8036953930208E32CEEB7EB2DFACA56B9D4C2379139A3D7C6B19B2257DC52B` at old HandlePacket path | `5793B8BFAAA6A7739BA15EA991F232DCF1A48B131B7417FF425981C62718B2D3` | 12638 / 113 | C01-C13, C15-C18, C20-C21 and C34-C36 applied; C14, C19, and C37 read back already-present; exact CPP only in formal block; target H blank; catalog `0363`, historical applied checkpoint, current IDB, and protected no-drift evidence incorporated. |
| 00009F | `by-class/NewUserMiscDialogPane.md` | `F5DA8E1141E5BC764C51B86080A3DA67D82E2F2C05EA22FF2CBE5AF58469CBF7` | `12E645794E64F595BD887F93F22E01210D9A5FC8CBBF4099A1DA9BA041AF3876` | 37932 / 171 | C22-C25 applied; exact complete H/extern installed, CPP `[[CHILDREN]]` retained, history preserved, and catalog/current-IDB no-drift evidence reconciled. |
| 0000LX | `by-file/NewUserMiscDialogPane.md` | `0453E05F7F27FBB347039B0A3F787A1621012621EBE5FEE406DEAA161253AF99` | `73435535872241E5C8B1CE572B2B0885D263F5B8B41CB45E8A5DE5C8AF1FF48E` | 37322 / 154 | C26-C28 applied; standalone source route, exact inventory/order, history, `89/92`, and current cataloged IDA method/source relationship read back without drift. |
| 0002Q7 | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `409EE462D895C3DC047AF0C87596451118E8BB7861AE97A979A40EBFC8C0AAEB` | `BB9FAC092F04E935137356AD6BD5B83F2A8D7904E4CBB8C2F94AE3FD04734A78` | 31846 / 184 | C29-C30 applied; exact child/ABI/packet/padding facts, `89/93`, cataloged target identity, current IDB, and protected reply/successor state; false/non-emitting/Nested13 preserved. |
| 0004GX | `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` | `C8C7A9B23212F61C590E4A1AE46BADEC2A1FF0600EBEB438F59960C47F93D306` | `EA58DC04C80B4AA6ABC2D9EC2FAF94EDB9092C8DA0DCF4F36BC5275F49F09192` | 6141 / 53 | C31 applied as support-only signature/caller/layout/return evidence; current caller name/prototype and protected reply/comments/sole-edge no-drift state recorded; `86/91`, owner, blank emitter/formals preserved. |
| 00025Q | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` | `C5CF8A14903952D4E5140C9F0ED3BB8E66015A7ADF38C3F166BF90E77B76A1E0` | `D0758800A80C399B47BE8302EDA0B1B3F47493391846C848BB6C25302DAAAC5A` | 40399 / 201 | C33 applied; exact `[0x0061d420,0x0061d4bc)` cluster/bases/cells/lifecycle refs, cataloged target identity, and later-current cell/base/xref no-drift state; `86/92` false/non-emitting metadata preserved. |
| 0002XL | `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md` | `C5C2E01C2D2633A4E1441EEE60D49A2BE51D70031CA8BA2BD9058F38D37D01C0` | `2D03D14E8E0A3EFE33221820F2DFA8093D954D70DA9AFFCEC6B06231852A0495` | 10744 / 87 | C32 applied; class-H extern route synchronized; exact CPP definition, blank local H, `88/90`, owner/emitter preserved. |
| 00004L | `by-class/Event.md` | `8C949A52AAF5D810407FDFFCDFDCE7397DF791E295E9C68D7301A4C4B1C93419` | same | 25015 / 328 | Read-only type/layout dependency; exact no-edit readback. |
| 00004N | `by-class/EventHandler.md` | `9113E1BE5C966238ECD9887AEDBD8FD77668D62375C4C5BE900DECC1EB70C402` | same | 21122 / 177 | Read-only interface/adjusted-receiver dependency; exact no-edit readback. |

- Ledger summary after ordinary and IDA readback: C01-C13, C15-C18, and C20-C36 are `applied` (`34` rows); C14, C19, and C37 are `already-present` (`3` rows); supervisor-owned C38-C45 remain `proposed` (`8` rows).

## Implementation Tracking Checklist

Report-content checklist:

- [x] Historical callback prerequisite: the supervisor explicitly validated the exact SHA and authorized this ordinary-document implementation callback.
- [x] Target/support docs to update are identified with exact paths, sections, metadata, formals, and historicalization requirements.
- [x] Additional target UIDs are none; support UIDs are explicitly not declared as report coverage.
- [x] Current target state and exact current artifact identities are recorded.
- [x] Historical post-callback IDB re-read against saved SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA` reconfirmed every target/protected prestate without mutation.
- [x] Historical no-drift IDB re-read against saved SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481` reconfirmed every target/protected prestate without mutation.
- [x] Historical pre-Gate2B backup identity is `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`; it is not current.
- [x] Historical exact applied checkpoint is session `1da2b2ae`, saved SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, saved `2026-07-29T14:22:15.9735862-04:00`; it matches catalog `0363` but is no longer the current shared IDB identity.
- [x] Historical intermediate bounded read-only recheck used session `1da2b2ae` and saved SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, saved `2026-07-29T14:42:53.5091352-04:00`; every target/protected Gate2B fact remained unchanged with no B007 mutation/save.
- [x] Current authoritative bounded read-only recheck used session `1da2b2ae` and saved SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`; every UID0004GP target/protected Gate2B fact remained unchanged after supervisor UID0002MZ work with no B007 mutation/save.
- [x] Claim And Incorporation Ledger contains 45 atomic rows with canonical actions; C01-C13, C15-C18, and C20-C36 are applied, C14/C19/C37 are already-present, and only supervisor coverage/generated C38-C45 remain proposed.
- [x] Metadata/score changes are exact for target/class/file/index and unchanged supports are explicit.
- [x] Score-limiting blockers were researched and resolved rather than deferred.
- [x] Owner/emitter/reconstructable decisions are exact.
- [x] Target rename/no-split/padding/source placement decisions are exact.
- [x] IDA facts, inference, documentation evidence, and negative evidence are separated.
- [x] Supervisor Gate 2B task completed: exact handoff applied/read back, database saved, protected state preserved, and audit/catalog evidence recorded as entry `0363`; B007 reconciled the readback without mutating IDA.
- [x] Target CPP, target H no-code proof, class H, class CPP disposition, and singleton declaration/definition route are exact.
- [x] Third-party import directive is not applicable.
- [x] Exact target/support facts to incorporate are recorded at report-level detail.
- [x] Historical/stale assumptions and rejected alternatives are preserved with reasons.
- [x] Wave2/Wave3 artifacts were ignored as stale.
- [x] Open questions were investigated to defensible resolution; no assigned-method blocker remains.
- [x] Callback validator plan is exact; historical B007 scope fact: B007 invoked no validator during assignment-time report-only work.
- [x] Manual supervisor-owned coverage payload, UID00025Q ignored `86%` no-op disposition, UID0002Q7 C39 replacement, and command-`19221` dated generated/tracker currentness are exact.

Implementation callback and supervisor-owned completion tasks:

- [x] Historical supervisor authorization: ordinary-document callback was explicitly authorized for report SHA `5D025E1247DE49E4188CA8B74C522405A20319A1D1446EB4786D239DC7A38036`.
- [x] B007 callback task: renamed the target UID-preservingly and applied exact target content/formals/metadata; old path absence and current hash were read back.
- [x] B007 callback task: applied UID00009F class H/CPP/method/evidence/score content without pruning existing valid detail.
- [x] B007 callback task: applied UID0000LX file source-route/inventory/evidence/score content.
- [x] B007 callback task: applied UID0002Q7 parent child/evidence/padding/score content while preserving non-emitting state.
- [x] B007 callback task: applied UID0004GX support-only signature/layout/caller facts with score/emitter unchanged.
- [x] B007 callback task: applied UID00025Q vtable subcluster facts with broad metadata unchanged.
- [x] B007 callback task: applied UID0002XL extern-route facts with CPP definition/metadata unchanged.
- [x] B007 callback task: reconciled ordinary C01-C33 and post-Gate2B C34-C37 to exact destinations/readbacks; only supervisor coverage/generated C38-C45 remain proposed.
- [x] B007 callback task: preserved historical assumptions, negative constraints, and unrelated concurrent detail.
- [x] B007 callback task: acquired only immediate edit/validator leases and released every B007 lease.
- [x] B007 callback task: ran the original seven scoped ordinary validators, the historical post-IDB-reconciliation seven-file batch (`19291`, `19293`-`19298`), the post-Gate2B six-file batch (`19452`, `19465`, `19475`, `19485`, `19496`, `19502`), and the later-current-IDB six-file batch (`19518`, `19521`, `19524`, `19527`, `19531`, `19534`) serially; every successful pass returned `ok:1`, and all generated refreshes were skipped.
- [x] Supervisor Gate 2A task completed: ordinary-document implementation independently passed claim-by-claim review.
- [x] Supervisor Gate 2B task completed: target mutation/readback, protected-state verification, IDB save, backup, and catalog entry `0363` are reconciled.
- [ ] Supervisor manual coverage task: replace the exact UID0002Q7 row in `by-memory/-coverage-report.md` (C39).
- [ ] Supervisor manual coverage task: insert the exact UID0004GP row after UID0002Q7 in `by-memory/-coverage-report.md` (C38).
- [ ] Supervisor manual coverage task: insert the exact UID0004GX row after UID0004GP in `by-memory/-coverage-report.md` (C43).
- [ ] Supervisor manual coverage task: replace the exact UID0002XL row in `by-memory/-coverage-report.md` (C42).
- [ ] Supervisor manual coverage task: recheck UID00025Q in `by-memory/-coverage-report.md` and preserve the exact no-change disposition recorded in the manual payload.
- [ ] Supervisor manual coverage task: replace the exact UID00009F row in `by-class/-coverage-report.md` (C40).
- [ ] Supervisor manual coverage task: replace the exact UID0000LX row in `by-file/-coverage-report.md` (C41).
- [ ] Supervisor generated-output task: refresh generated output and verify the UID0004GP marker/body in `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` (C44).
- [ ] Supervisor generated-output task: refresh generated output and verify the UID00009F class declaration in `auto-generated/NexusTK/login/NewUserMiscDialogPane.h` (C45).
- [ ] Supervisor final-gate task: complete fresh final report gates before any execution/archive action.
- [x] Lifecycle boundary recorded: execution/archive is supervisor-only and B007 must not run it; current lifecycle state is authoritative only from the artifact path plus validator-owned status/history and supervisor audit/catalog records.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000019691","destination_path":"executed-b-agent-research/B007/0004GP-NewUserMiscDialogPaneHandlePacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0004GP-NewUserMiscDialogPaneHandlePacket-source-quality.md","timestamp":"2026-07-29T15:12:15-04:00","uid":"0004GP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
