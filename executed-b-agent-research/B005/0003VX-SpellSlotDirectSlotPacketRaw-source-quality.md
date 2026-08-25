** TARGET-REPORT-UID:0003VX **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003VX SpellSlot Direct Slot Packet Raw Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0003VX] as a reconstructable private `SpellSlotInputPane` member helper in [UID:0000O0] `NexusTK/ui/dialogs/SpellInputPanes.cpp`, but replace the decompiler-shaped `SendSpellSlotPacket(signed char selectedSlot)` reconstruction with the source-facing `SendSpellUsePacket(char inventorySlot)` contract.
- Final disposition: source-authored retained helper whose only known source caller was inlined into [UID:0001LX] `SubmitSpellSlot`; absence of a remaining static route does not make the domain packet body compiler-generated or ownerless.
- Ordinary callback result: C001-C044 are incorporated and destination-verified across the exact seven-file write set; C045-C049 were re-read and remain correct without edits. All seven scoped `--no-generated-refresh` validators passed. Supervisor-owned IDA C057-C062 plus the analyzer-limitation disposition C067, manual coverage C050-C056, and generated verification C063-C064 remain outside this callback; report execution/archive state is supervisor-owned and is not asserted here.
- Scores: target `87/89 -> 93/94`; UID0001LX `89/91 -> 93/94`; class UID0000DS `91/94 -> 93/94`; aggregate/file/base scores remain unchanged for the reasons stated below.
- Confidence: very strong for behavior, class/file ownership, packet layout, field/argument types, 300-byte packet-buffer source shape, and compiler-inlined relationship; the exact original lexical spellings remain inferred and cap confidence below the `95+` final-audit gate.

## Supporting Research

- Gate 1 target checkpoint: `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md`, SHA256 `8E8AB3DE727A1B9414F625777741AACD9B5547ACBE678394838A4A59AD7FB21B`, 17,316 bytes.
- Gate 1 direct submitter checkpoint: [UID:0001LX] `by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md`, SHA256 `2C54EA05505B113007F88811C7600EF0B30B22C356001DB71C2C4BD0BDD5B0CB`, 19,227 bytes.
- Gate 1 family index checkpoint: [UID:0001LN] `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`, SHA256 `BBF642E79BDBA619640B5AAB9F9E124401C389BA7D0766FA5D243DE5980839FB`, 50,332 bytes.
- Gate 1 class checkpoint: [UID:0000DS] `by-class/SpellSlotInputPane.md`, SHA256 `79653D6A9ED6C8DDCA842C5334886F1D93E9D2930101403A94CA1EB6F7F4779F`, 15,057 bytes.
- Gate 1 file checkpoint: [UID:0000O0] `by-file/SpellInputPanes.md`, SHA256 `DBD6432292C84FD07FF577A17BD95D8AEC082927613B661013035A321102A9D1`, 78,078 bytes.
- Gate 1 base-class checkpoint: [UID:00001P] `by-class/CharInputPane.md`, SHA256 `E8CD71BFBB59CF77440FED6694CAE7EF95BB1C481716A30013A4E4570CD65ED5`, 11,379 bytes.
- Gate 1 base-file checkpoint: [UID:0000K7] `by-file/InputPanes.md`, SHA256 `77948F03FB4268780D43BB634843D556CE60093421F77ABB978B7E6354495227`, 27,985 bytes.
- Current binary-evidence checkpoint: MCP client session `78b3ca6d-f060-4631-bbb5-e5650ad8d6b2`, active database `f608d7c2`, `server_health status:ok`, Hex-Rays ready, strings cache ready, and physical IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`. This identity is a dated bounded-read checkpoint; later saved-IDB identity plus fresh target readback is authoritative at Gate 2B.
- Current generated checkpoint: validator command `000000020493`, refreshed `2026-07-31T10:40:09-04:00`; `SpellInputPanes.cpp` SHA256 `1F1BD5DA97AB4A82E5CA821DD2BE96B9BC7D757961486E937F2F59ACDA871E31`, 20,412 bytes/596 lines; `SpellInputPanes.h` absent; `InputPanes.cpp` SHA256 `03A578C9EBCA02E2A68B2FD31E6247F16A5F2E8A521464EE595574460D59BDF1`, 8,533 bytes/258 lines; `InputPanes.h` SHA256 `9E6BE047B57F2A02EAA4F088EEC4FB9FC848AB9700EC908F0F1759CB3523CFCD`, 1,237 bytes/38 lines. These are dated generated checkpoints, not durable moving-file truth.
- Current tracker checkpoint: command `000000020493`, SHA256 `13F74CBAA11133CF1CE2F061C0A9E27A70E6D18A57C7770A4F800F777AB7EDBE`, 1,690,672 bytes/6,676 lines. The UID0003VX row is `87/89`, reconstructable, with zero direct/additional/total B-report counts. Moving tracker truth remains validator-owned.
- Matching historical leads opened after UID/address/name/family search: B013 UID0003VX SHA256 `47AE89C7AE116FEBEDFF9EC633BF649A32731634B00212729CAEEA833CE1D04C`; B007 UID0001LX SHA256 `5F8D5605540E31AFD2ABE62E96444A4E8713143E8B9BB4FBC578033E7DA3EE67`; B011 UID0003VV SHA256 `6904C62FB5DE13B6C7C300341E193F424141D42B532FCC2ED6DED38951051039`. They are leads/history, not substitutes for the current live pass.

### Ordinary Callback Post-Validation Checkpoints - 2026-08-01

- [UID:0003VX] target: SHA256 `C6662A38B66068CC96BE040CECB52A83097B8129E8201D69153C02D22E5B75EA`, 22,598 bytes/164 lines after validator command `000000020496`.
- [UID:0001LX] live submitter: SHA256 `6DF3689528626C0C6A44349CC3870BAF62EE1AD466FD43FE0D5B3492960F5427`, 21,297 bytes/156 lines after command `000000020499`.
- [UID:0000DS] class: SHA256 `5635C89FE32EC3D52A2629C4BCA04F82BD299CFD2084B0D513CE27B1C60EA0C8`, 17,994 bytes/138 lines after command `000000020500`.
- [UID:0000O0] source-file page: SHA256 `1C47A2E602594CF9A890EF5CE2129AAD17FE041C7114ACCDF2315A40577FB0C9`, 79,601 bytes/304 lines after command `000000020504`.
- [UID:0001LN] family aggregate: SHA256 `ACB79FF2D02E56F7F471A1AE894BBDF50E35EF50375B30DBD565A5D2739D684B`, 51,829 bytes/254 lines after command `000000020505`.
- [UID:00001P] base class: SHA256 `39D8677B5BA88590559960C81F4F56841BFAFB6E34951B346FA22A2E638354C4`, 13,114 bytes/125 lines after command `000000020506`.
- [UID:0000K7] base source-file page: SHA256 `13ABF6D49167013EE55B971955EFA1BBE02B6E60BB03B4A6DB41D2D63DDE5D19`, 29,200 bytes/168 lines after command `000000020507`.
- The original checkpoints above remain preserved as Gate 1 pre-implementation identities. Generated/tracker/manual/IDA identities were not refreshed or mutated by B005 and remain supervisor-owned moving state.

### Failed Gate 2B F1 Readback Repair Checkpoint - 2026-08-01

- The supervisor applied F1, A1-A3, and T1 in an unsaved transaction. Function name/range/prototype/repeatable comment, all three line comments, and the `0x10c` UDT read back exactly, but `analyze_function` still reported `positive sp value has been detected`, Hex-Rays retained `v2`-through-`v9` placeholders, and `stack_frame` contained only `__saved_registers +0x134`, `__return_address +0x138`, and `inventorySlot +0x13c`. The transaction was discarded without saving because the old F1 incorrectly promised exact local-variable rendering.
- A separate earlier direct-frame experiment was rejected as unsafe and also discarded unsaved. No experimental stack member, function, name, type, comment, or UDT reached disk.
- Fresh read-only MCP database `b3b2bf88` and direct disk hashing reconfirm the restored prestate: no function at `0x005b14f0`, unnamed one-byte code head, no target frame/decompilation, and physical IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, last write `2026-07-31T06:21:13.3464834-04:00`.
- Bounded target/callee/control-function disassembly proves the machine stack is balanced. The three `PacketBufferWriteUInt8` calls push 24 caller-owned bytes and its body ends in plain `retn`; `add esp, 18h` removes exactly those bytes; `Socket_QueueAndSendPacket` consumes its two arguments with `retn 8`; `@__security_check_cookie@4` consumes no stack argument and ends in plain `retn`; `mov esp, ebp`, `pop ebp`, and `retn 4` close the target frame and one ABI argument slot.
- Current schema inspection found no supported SP-delta or frame-reanalysis operation. `declare_stack` creates members but has no dry-run/overlap/rollback contract and cannot correct SP analysis; `set_op_type(kind=stkvar)` only tags an operand and cannot select or create the required variable; local `rename`/`set_type` require an already stable decompiler local; `force_recompile` only invalidates Hex-Rays cache; destructive `undefine`/redefine is not evidence-supported. F1 is therefore narrowed to durable function metadata, comments, UDT, and protected-state readback; physical frame facts remain assembly-backed documentation rather than promised Hex-Rays presentation.

## Target

- Target UID: `0003VX`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003VX] `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md`, exact retained private packet helper body `[0x005b14f0,0x005b1568)`.
- Source queue row: `auto-generated/-ag-research-tracker.md`, command `000000020493`, line 1681, `87/89`, reconstructable, zero report counts.
- Artifact role: ordinary callback evidence plus the repaired F1 supervisor handoff. Current Gate 1/Gate 2 state is supervisor-owned and authoritative only from the exact-artifact audit ledger.
- Direct owner/emitter: [UID:0000DS] `SpellSlotInputPane`.
- Source file route: [UID:0000O0] `NexusTK/ui/dialogs/SpellInputPanes.cpp` with a newly materialized `SpellInputPanes.h` after accepted formal-H changes.
- Gate 1 metadata checkpoint: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000DS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DS`, blank emitter position. Callback poststate is `93/94` with routing metadata unchanged.

## Current Target State

- At Gate 1, the page already classified the bytes as retained source-authored no-route code and emitted a draft body, but its method/argument names, four-byte local buffer, live-submitter factoring decision, IDA disposition, and score rationale were stale or incomplete.
- Gate 1 formal CPP used `SendSpellSlotPacket(signed char selectedSlot)` and `unsigned char packet[4]`; callback formal CPP now carries the accepted `SendSpellUsePacket(char inventorySlot)` body and 300-byte scratch while formal H remains correctly blank because the declaration belongs to the class emitter.
- Current owner/emitter route is correct: UID0003VX -> UID0000DS -> UID0000O0.
- IDA does not model a function at `0x005b14f0`; the start is one unnamed code item with blank type and blank regular/repeatable address comments. There is no function frame or function-comment channel until a function is created.
- The failed unsaved Gate 2B readback does not change that physical prestate. It proves that function metadata can be installed safely but exact packet/cookie local rendering cannot be made a Gate 2B acceptance condition with the current MCP/IDA analyzer model.
- Exact body is 120 bytes with SHA256 `2CE684779DB3DC1DEF0B70344E5FBA59114A964BACA3985A0DAD7E68309707CC`.
- Exact predecessor alignment `[0x005b14e6,0x005b14f0)` is ten `0xcc` bytes, SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`.
- Exact successor alignment `[0x005b1568,0x005b1570)` is eight `0xcc` bytes, SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`.
- No entry xref, target VA/RVA/raw-offset dword, rel32 call/jump, vtable slot, or generated source marker remains. That resolves liveness as retained/no-route, not as unknown.
- Open source-quality blockers inherited from older docs were: the argument's semantic domain, plain-`char` versus explicit signed type, field identity, exact local packet storage, method spelling, live submitter factoring, class/base H routing, IDA function/type/comment state, and stale manual coverage rows. Each is resolved below.
- Current report execution/archive state is supervisor-owned and authoritative only from this artifact's actual path plus validator-owned status/history metadata.

### Ordinary Implementation Callback Result - 2026-08-01

- [UID:0003VX], [UID:0001LX], and [UID:0000DS] now carry the accepted `93/94` source contract. The target emits exact `SendSpellUsePacket(char inventorySlot)` CPP with a 300-byte packet buffer and blank H; the submitter emits exact letter validation followed by the helper call and blank H; the class emits its complete declaration in `SpellInputPanes.h` and includes that header from CPP.
- [UID:0000O0] remains `92/94` with the accepted retained-helper/compiler-inline relationship and generated `SpellInputPanes.h` route. [UID:0001LN] remains the `90/93` non-reconstructable, non-emitting split index with every sibling and padding disposition preserved.
- [UID:00001P] remains `92/94`; its complete declaration moved from formal CPP to formal H, while CPP includes `InputPanes.h` and emits exact children. [UID:0000K7] remains `92/92` and now records that generated `InputPanes.h` supplies the complete reusable base declaration.
- Read-only recheck confirms [UID:0003YJ] still defines `void PacketBufferWriteUInt8(unsigned char, unsigned char *)`, [UID:0001HU] still defines `void Socket::QueueAndSendPacket(const void *, short)`, [UID:0000Q5] still emits `Socket *g_packetSender`, UserStatusPane still names `m_inventorySlotCount` at `+0x284`, and [UID:0000VN] still records both adjacent target padding spans.
- No contradiction expanded the write set. B005 made no manual coverage, generated/tracker, IDA, audit/catalog/lifecycle, or archive change; report execution/archive state remains supervisor-owned and is not asserted here.

## Executive Recommendation

- Preserve owner/emitter and exact range; do not merge UID0003VX into UID0001LX and do not move the body to PacketBuffer, Socket, ProtocolSend, inventory, or a generic packet-helper source file.
- Treat UID0003VX as the retained out-of-line source body of `SpellSlotInputPane::SendSpellUsePacket(char inventorySlot)`.
- Rewrite UID0001LX's source-facing formal C++ to call this helper after its exact one-character inventory-slot decode and count check. The binary still contains inline instructions because the compiler inlined the private helper; source reconstruction should represent the higher-probability precompiled source, not duplicate decompiler output.
- Use `char`, not `signed char` or `unsigned char`, for `m_spellIndex` and `inventorySlot`. `movsx` proves signed consumption while project-local declarations consistently use plain `char` for one-byte spell indices.
- Use a 300-byte packet array in both source bodies. The exact frame gives contiguous `[ebp-0x130,ebp-0x5]` storage, 300 bytes, followed by the cookie at `[ebp-4]`; the same project subsystem repeatedly documents `unsigned char packet[300]`.
- Raise the target and submitter to `93/94`, raise class completion to `93` while retaining confidence `94`, and retain broader aggregate/file/base scores because unrelated family-wide work remains.

## Supervisor Active Recheck

- The assignment specifically required fresh reanalysis of retained/no-route disposition, owner/file placement, source-authored versus compiler-retained shape, `this+0x108`, packet helpers/globals/layout, human helper naming, UID0001LX relationship, formal CPP/H, and every score/open-question blocker.
- No split is needed. UID0003VX is already an exact leaf over the complete body; both adjacent alignment ranges are already in [UID:0000VN] `by-memory/-ignored.md`.
- F1 was rechecked after the failed unsaved transaction. Its durable function/type/comment action remains valid, while its former stack-frame/Hex-Rays-local promise is removed; the current analyzer limitation is not a source-behavior, owner, range, or C++ blocker.
- Every source-bearing item required for this conclusion already exists. The callback requires edits to existing pages only; no child creation, path rename, merge, or range expansion is recommended.
- The broader sibling raw-helper family is not silently generalized. This report resolves UID0003VX because its live UID0001LX duplicate establishes its source relationship; siblings remain governed by their own evidence and reports.

## Inference Research Guidance Check

- IDA facts establish bytes, instructions, range, stack layout, callees, xrefs, comments, globals, and current types. Documentation establishes existing UIDs/routes and subsystem contracts. Inference chooses the human source factoring and lexical names.
- The old assumption that no static route requires preserving duplicate packet statements in UID0001LX was treated as uncertain. A source call can disappear through inlining while a retained out-of-line copy remains.
- The old `selectedSlot` description was treated as uncertain because UID0001LX validates the value against `UserStatusPane::m_inventorySlotCount`; it is an inventory/item slot, not a spell slot.
- The old `packet[4]` draft was treated as decompiler-minimal rather than source-shape proof. Exact stack intervals and repeated project convention support 300 bytes.
- Wave2/Wave3 material was not used. Any stale Wave2/Wave3 references encountered in older project history are ignored under current policy.
- The selected names are explicit high-probability source inference, not claimed recovered PDB spellings. This does not justify leaving raw labels in final C++.

## Heuristic / Inference Reanalysis And Validation

1. **Source-authored versus compiler/runtime:** opcode `0x0f`, class state at `+0x108`, feature packet serialization, and `g_packetSender` make the semantic body source-authored. Stack-cookie setup/check and retained/no-route status are compiler/linker consequences inside that source body, not the body's ownership.
2. **Receiver and field:** `ecx` is copied to `esi`; `movsx eax, byte ptr [esi+0x108]` matches the constructor-written [UID:0000DS] `m_spellIndex`. `CharInputPane` is exactly `0x108`; the byte is the sole derived state at `+0x108`; natural tail padding gives complete size `0x10c`.
3. **Argument meaning:** `[ebp+8]` is sign-extended before the byte writer. UID0001LX derives the same byte from `a-z -> 1..26` and `A-Z -> 27..52`, rejects `<1`, and compares to `m_inventorySlotCount`. Best source-facing name is `inventorySlot`.
4. **Argument type:** plain `char` matches the project's established `m_spellIndex` convention and the signed `jl`/`movsx` behavior. `unsigned char` contradicts the signed lower-bound branch; explicit `signed char` overstates an original spelling not used by the adjacent class declarations.
5. **Method name:** `SendSpellUsePacket` states protocol action and matches the accepted sibling helper direction. `SendSpellSlotPacket` is rejected because it conflates spell index byte 1 with inventory slot byte 2; `SendDirectSlotPacket` is tool-shaped; `SubmitSpellSlot` belongs to the virtual input handler.
6. **Packet shape:** byte 0 opcode `0x0f`; byte 1 `m_spellIndex`; byte 2 validated inventory slot; byte 3 zero terminator outside counted send length 3. `PacketBufferWriteUInt8` itself writes `destination[0]=value` and `destination[1]=0`, so each subsequent write overwrites the previous spare zero.
7. **Local buffer:** `sub esp,0x130`; packet base `[ebp-0x130]`; cookie `[ebp-4]`; exactly 300 packet bytes precede the cookie. The submitter's frame has one extra four-byte local at `-0x134`, then the same packet base/cookie relation. Use `unsigned char packet[300]` in source.
8. **UID0001LX relationship:** both bodies emit the same opcode/state/inventory-slot/terminator/send tail. The standalone private body plus exact inline duplicate is stronger evidence of source factoring plus compiler inlining than of two hand-written duplicate blocks. UID0001LX should call the helper in source while preserving exact pre-call validation.
9. **No-route disposition:** current MCP and PE scans exhaust static entry routes. Resolution is retained/no-route source, not deferred investigation and not a reason to suppress source.
10. **Header placement:** source declarations belong in formal H. `SpellSlotInputPane` needs `SpellInputPanes.h`; its complete base `CharInputPane` must be in `InputPanes.h`. Class CPP blocks should include their generated headers and retain `[[CHILDREN]]` only.
11. **Rejected no-code direction:** target is already owner/emitter eligible and behavior complete. Leaving formal C++ blank would violate the 85/85 draft-code rule and lose a real source-authored method.
12. **Rejected original-byte mimicry:** explicit cookie code, `_BYTE` arrays, `sub_` names, and a four-byte packet array chosen only from bytes used are decompiler artifacts, not plausible original developer source.
13. **IDA analyzer boundary:** exact instruction-level stack accounting is balanced and the modeled UID0001LX positive control decompiles with the same three-writer/add-`0x18`/socket/cookie pattern. The target-only positive-SP warning after function creation is an IDA analysis-presentation limitation. It must be recorded honestly, not "fixed" by changing correct callee conventions, inventing stack entries, or downgrading the recovered source.

## Evidence Standards Used

- Direct binary evidence: live bounded MCP `server_health`, `lookup_funcs`, `inspect_items`, `get_bytes`, `disasm`, `decompile`, `stack_frame`, `xrefs_to`, `xref_query`, `get_comments`, `func_profile`, `type_inspect`, `find_bytes`, and `make_signature_for_range`.
- Independent PE evidence: current executable hash, PE image-base/section mapping, full-file VA/RVA/raw-offset dword scans, and `.text` E8/E9 rel32 target scan.
- Structural evidence: exact child/parent metadata, constructor field write, live submitter vtable route, class size/layout, adjacent padding, file emitter route, packet helper/global contracts, and generated CPP/H topology.
- Historical evidence: only matching reports were opened; their conclusions were rechecked and either incorporated, refined, or explicitly rejected.
- Tool-contract evidence: current MCP schemas were inspected for `define_func`, `set_type`, `rename`, `set_op_type`, `stack_frame`, `declare_stack`, `delete_stack`, `force_recompile`, `analyze_function`, and `decompile` before rejecting an unsupported SP/local-variable mutation.
- Evidence ladder: bytes/ranges/instructions/types outrank old docs; current docs outrank generated output; generated output is a topology checkpoint; source factoring/names are inferred only after binary behavior and project conventions agree.
- Strongest remaining limitation: no original symbol/PDB/declaration text survives and no static entry route remains. This caps confidence at 94 but does not block reconstruction.

## Evidence Checked

- Gate 1 MCP session/database: client `78b3ca6d-f060-4631-bbb5-e5650ad8d6b2`, IDB `f608d7c2`; health `ok`; Hex-Rays ready; `auto_analysis_ready:false` recorded as context, not failure, because all bounded calls succeeded. F1 repair used fresh read-only IDB session `b3b2bf88`, also healthy and Hex-Rays ready.
- `lookup_funcs`: target start is not a function; UID0001LX is `sub_5B1410` size `0xd6`; constructor is `sub_5B1280` size `0x8d`; successor is `sub_5B1570` size `0xc1`; accepted proposed names have no collision.
- `disasm 0x005b14f0`, bounded to 80 instructions: complete target body through `retn 4` plus exact alignment/successor boundary; no function model was required for the rendered range.
- `get_bytes`: exact 10-byte prepad, 120-byte body, and 8-byte postpad.
- `make_signature_for_range`: unique wildcarded signature for `[0x005b14f0,0x005b1568)`; `unique:true`.
- `find_bytes`: exact 28-byte prologue/buffer prefix occurs at the five direct spell-argument helper starts `0x005b0a10`, `0x005b0d00`, `0x005b0fa0`, `0x005b1200`, `0x005b14f0`; target signature beyond relocatable fields is unique.
- `find_bytes` route checks: zero `F0 14 5B 00` VA, `F0 14 1B 00` RVA, and `F0 08 1B 00` raw-offset patterns.
- Independent PE scan: executable SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes, image base `0x00400000`, target RVA `0x001b14f0`, raw offset `0x001b08f0`; zero VA/RVA/raw dword hits and zero E8/E9 rel32 hits.
- `xrefs_to`: zero refs to `0x005b14f0` and `0x005b1568`; positive control `0x0062f6b8 -> 0x005b1410` proves the live submitter route is discoverable.
- `decompile`/`disasm` UID0001LX: exact letter mapping, signed lower-bound check, inventory-count upper bound, and byte-for-byte packet-tail duplicate.
- `stack_frame`: target has no frame because no function exists; UID0001LX has four-byte text local, 300-byte packet region, cookie, saved register, and return address.
- Failed supervisor F1 readback, treated as transient unsaved evidence: exact function metadata/comments/UDT succeeded; `stack_frame` returned only `__saved_registers +0x134`, `__return_address +0x138`, and `inventorySlot +0x13c`; `analyze_function` retained the positive-SP diagnostic and `v2`-through-`v9` placeholders. Both supervisor transactions were discarded, so these are analyzer-behavior observations rather than current IDB state.
- Fresh target disassembly: `sub esp,130h`, saved `esi`, three two-argument cdecl writer calls, one `add esp,18h`, two-argument thiscall socket send, cookie check, frame restore, and `retn 4`. Fresh callee disassembly confirms writer plain `retn`, socket `retn 8`, and cookie-helper plain `retn`; no protected type/byte correction is warranted.
- Positive control UID0001LX: exact same three writer calls plus one `add esp,18h`, same socket/cookie tail, a valid frame, and successful decompilation. This rules out the shared writer/socket/cookie conventions as the source of the target-only analyzer warning.
- Current MCP schema audit: no SP-delta read/write or reanalysis tool exists. `declare_stack` has only function/offset/name/type and no dry-run; `set_op_type(stkvar)` has no member selector; `set_type`/`rename` can change only existing locals; `force_recompile` invalidates cache only. Direct-frame, blind local, callee-type, and destructive range-redefinition paths were rejected for exact safety reasons.
- `type_inspect`: `SpellSlotInputPane` is only an incomplete forward; `CharInputPane` is a `0x108` opaque UDT; `LineInputPane` is a `0x108` UDT with known tail members.
- `get_comments`: all target/action address channels are blank; support helper/global comments and exact prototypes were read.
- Documentation checked: target, UID0001LX, UID0001LN, UID0001LV, UID0004UC, UID0001LW, UID0000DS, UID0000O0, UID00001P, UID0000K7, UID0003YJ, UID0001HU, UID0000Q5, UID0001PE, and UID0000VN.
- Old-report search terms: `UID:0003VX`, `0x005b14f0`, `SpellSlotDirectSlotPacketRaw`, `SendSpellSlotPacket`, `SpellSlotInputPane`, `SpellInputPanes`, `UID:0001LX`, `SendSpellUsePacket`, and sibling direct-argument family addresses. Relevant B007/B011/B013 reports were opened; no active B001-B010 duplicate report was found.
- Generated/tracker/manual files checked read-only at the dated checkpoints listed in Supporting Research.
- Failed/unavailable checks: target decompilation and stack-frame rendering are unavailable in the restored no-function prestate. The failed unsaved transaction proves current IDA can preserve exact function metadata while still failing to reconstruct stable source locals. No current MCP schema safely exposes SP-delta repair or deterministic frame/local creation, so exact Hex-Rays local rendering is explicitly not promised. Original PDB/source text and dynamic runtime reachability remain unavailable; exhaustive static routing and exact inline duplication still resolve the retained-helper source disposition.
- Intentionally skipped: no broad unbounded MCP list/search, no validator, no lifecycle command, no IDA mutation/save, no coverage/generated edit, and no Wave2/Wave3 evidence.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0003VX | Exact target range is `[0x005b14f0,0x005b1568)`, 120 bytes, body SHA256 `2CE684779DB3DC1DEF0B70344E5FBA59114A964BACA3985A0DAD7E68309707CC`. | High | MCP bytes/disasm; PE hash | `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md` Item Summary/Range | incorporate | implemented-and-verified |
| C002 | 0003VX | Prepad is `[0x005b14e6,0x005b14f0)`, ten `0xcc`, SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`. | High | MCP bytes/items; PE hash | target Boundaries | incorporate | implemented-and-verified |
| C003 | 0003VX | Postpad is `[0x005b1568,0x005b1570)`, eight `0xcc`, SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`. | High | MCP bytes/items; PE hash | target Boundaries | incorporate | implemented-and-verified |
| C004 | 0003VX | Body is source-authored domain code; only cookie mechanics are compiler-generated. | High | Opcode/state/helper/global flow | target Status/Rebuild Handling | incorporate | implemented-and-verified |
| C005 | 0003VX | No static entry route remains; helper is retained/no-route rather than ownerless. | High | MCP/PE route scans | target Liveness/Negative Evidence | incorporate | implemented-and-verified |
| C006 | 0003VX | Direct owner/emitter remains UID0000DS; file route remains UID0000O0. | High | Receiver/state/class adjacency/routes | target Ownership/Source Placement | incorporate | implemented-and-verified |
| C007 | 0003VX | Best method name is `SendSpellUsePacket`; old `SendSpellSlotPacket` is superseded descriptive history. | Medium-high | Packet semantics/sibling naming | target Source-Facing Names/History | incorporate | implemented-and-verified |
| C008 | 0003VX | Argument is plain `char inventorySlot`, not `signed char selectedSlot`. | High | UID0001LX signed validation and inventory-count check | target Type/Behavior | incorporate | implemented-and-verified |
| C009 | 0003VX | `this+0x108` is plain `char m_spellIndex`; complete class size remains `0x10c`. | High | Constructor/class/IDA UDT facts | target Field/Layout | incorporate | implemented-and-verified |
| C010 | 0003VX | Packet bytes are opcode, spell index, inventory slot, unsent zero terminator; counted length is 3. | High | Exact disasm/callee contracts | target Packet Layout | incorporate | implemented-and-verified |
| C011 | 0003VX | Source packet storage is `unsigned char packet[300]`. | High | Exact stack interval; subsystem convention | target Stack/Source Shape | incorporate | implemented-and-verified |
| C012 | 0003VX | Target formal CPP is the exact `SendSpellUsePacket(char)` body in this report. | High | Behavior/source analysis | target formal CPP | incorporate | implemented-and-verified |
| C013 | 0003VX | Target formal H remains blank because declaration belongs to UID0000DS. | High | Emitter/channel policy | target formal H | already-present | verified-current |
| C014 | 0003VX | Metadata becomes `93/94`; owner/emitter/reconstructable/position remain unchanged. | High | Blocker closure/95 gate | target metadata | incorporate | implemented-and-verified |
| C015 | 0003VX | Item Summary must replace B013 wording with current exact source-shape and IDA facts. | High | Current investigation | target Item Summary | incorporate | implemented-and-verified |
| C016 | 0003VX | Historical ownerless/no-code, four-byte buffer, selected-spell-slot, and duplicate-source assumptions remain documented as disproved history. | High | Old/current comparison | target Historical Assumptions | historicalize | historicalized-and-verified |
| C017 | 0001LX | UID0001LX remains exact range `[0x005b1410,0x005b14e6)`, vtable-routed at `0x0062f6b8`. | High | MCP function/xref | UID0001LX Evidence | already-present | verified-current |
| C018 | 0001LX | Local selected value is plain `char inventorySlot` with exact letter mapping and signed lower-bound behavior. | High | Live decompile/disasm | UID0001LX Behavior/formal CPP | incorporate | implemented-and-verified |
| C019 | 0001LX | Submitter calls `SendSpellUsePacket(inventorySlot)` after validation in source. | Medium-high | Retained body plus exact inline duplicate | UID0001LX Source Shape/formal CPP | incorporate | implemented-and-verified |
| C020 | 0001LX | Submitter source packet construction is factored out; compiler-inlined binary tail remains exact behavior evidence. | Medium-high | Inline/out-of-line comparison | UID0001LX Compiler Lowering | incorporate | implemented-and-verified |
| C021 | 0001LX | UID0001LX formal H stays blank; class declaration owns the virtual method declaration. | High | Emitter/channel policy | UID0001LX formal H | already-present | verified-current |
| C022 | 0001LX | UID0001LX becomes `93/94` with owner/emitter/reconstructable unchanged. | High | All prior blockers resolved | UID0001LX metadata | incorporate | implemented-and-verified |
| C023 | 0001LX | B007 preserve-inline decision remains as dated conservative history and is superseded for source factoring. | High | New exact 300-byte/inlining evidence | UID0001LX Historical Assumptions | historicalize | historicalized-and-verified |
| C024 | 0001LX | UID0001LX Item Summary must say inventory-slot decode and helper-call source shape, not spell-slot/raw-helper blockers. | High | Current analysis | UID0001LX Item Summary | incorporate | implemented-and-verified |
| C025 | 0000DS | Private declaration becomes `void SendSpellUsePacket(char inventorySlot);`. | High | Target/source conclusion | `by-class/SpellSlotInputPane.md` formal H | incorporate | implemented-and-verified |
| C026 | 0000DS | Complete class declaration belongs in formal H, not formal CPP. | High | Channel rule | class formal H | incorporate | implemented-and-verified |
| C027 | 0000DS | Class formal CPP becomes `#include "SpellInputPanes.h"` plus `[[CHILDREN]]`. | High | Compile-visible route pattern | class formal CPP | incorporate | implemented-and-verified |
| C028 | 0000DS | Class H includes `InputPanes.h`, forward-declares Event, preserves all methods, field, access, inheritance, and natural padding. | High | Current declaration/layout | class formal H | incorporate | implemented-and-verified |
| C029 | 0000DS | Class behavior/method inventory gains retained helper and compiler-inlined submitter relation at report detail. | High | Current target/live submitter | class Behavior/Methods | incorporate | implemented-and-verified |
| C030 | 0000DS | Class becomes `93/94`; owner/emitter/reconstructable remain unchanged. | High | Class blocker closure | class metadata | incorporate | implemented-and-verified |
| C031 | 0000DS | Old `SendSpellSlotPacket(signed char)` wording is retained only in historical correction text. | High | Superseded source inference | class History | historicalize | historicalized-and-verified |
| C032 | 0000O0 | SpellInputPanes source inventory uses `SendSpellUsePacket(char inventorySlot)` and inline-source relationship. | High | Class/target/submitter closure | `by-file/SpellInputPanes.md` Contents/Raw Helper Policy | incorporate | implemented-and-verified |
| C033 | 0000O0 | File route gains generated `SpellInputPanes.h` for UID0000DS while keeping `.cpp` source root. | High | Formal channel correction | file Source Placement/Generated Policy | incorporate | implemented-and-verified |
| C034 | 0000O0 | File remains `92/94`; unrelated family declarations/raw helpers prevent a whole-file completion raise. | High | Whole-file score rule | file score/status | already-present | verified-current |
| C035 | 0000O0 | File preserves older no-route and old-name decisions as history, not current source policy. | High | Current reanalysis | file History | historicalize | historicalized-and-verified |
| C036 | 0001LN | Aggregate remains non-reconstructable/non-emitting `90/93`. | High | Exact-child ownership | aggregate metadata | already-present | verified-current |
| C037 | 0001LN | Aggregate helper inventory updates UID0003VX name/type/source relationship and UID0001LX factoring. | High | Current family analysis | aggregate Status/Inventory | incorporate | implemented-and-verified |
| C038 | 0001LN | Aggregate retains all sibling helper dispositions independently. | High | Sibling reports/current docs | aggregate Sibling Policy | already-present | verified-current |
| C039 | 0001LN | B007/B013 wording is retained as dated history with exact supersession reason. | High | Old/current comparison | aggregate History | historicalize | historicalized-and-verified |
| C040 | 00001P | CharInputPane complete declaration moves from formal CPP to formal H without semantic changes. | High | Channel rule/base dependency | `by-class/CharInputPane.md` formal H | incorporate | implemented-and-verified |
| C041 | 00001P | CharInputPane formal CPP becomes `#include "InputPanes.h"` plus `[[CHILDREN]]`. | High | Compile-visible route pattern | CharInputPane formal CPP | incorporate | implemented-and-verified |
| C042 | 00001P | CharInputPane remains `92/94`; inheritance/methods/body ownership are unchanged. | High | Scope/whole-class score | CharInputPane metadata/status | already-present | verified-current |
| C043 | 00001P | CharInputPane page records that H placement makes feature-derived headers complete. | High | SpellSlot header dependency | CharInputPane Source Placement | incorporate | implemented-and-verified |
| C044 | 0000K7 | InputPanes file page records `CharInputPane` in generated `InputPanes.h`; score remains `92/92`. | High | Formal route correction | `by-file/InputPanes.md` Generated Policy | incorporate | implemented-and-verified |
| C045 | 0003YJ | `PacketBufferWriteUInt8` prototype/behavior is already exact and needs no edit. | High | MCP/docs | UID0003YJ | already-present | verified-current |
| C046 | 0001HU | `Socket::QueueAndSendPacket(const void *, short)` behavior is already exact and needs no edit. | High | MCP/docs | UID0001HU | already-present | verified-current |
| C047 | 0000Q5 | `Socket *g_packetSender` is already exact and needs no edit. | High | MCP/docs | UID0000Q5 | already-present | verified-current |
| C048 | 0001PE | `m_inventorySlotCount` at UserStatusPane `+0x284` is already exact and needs no edit. | High | Docs/live submitter | UID0001PE/UserStatusPane | already-present | verified-current |
| C049 | 0000VN | Both adjacent target padding ranges are already exact in ignored ledger; no edit. | High | Bytes/ignored doc | by-memory `-ignored.md` | already-present | verified-current |
| C050 | 0003VX | Insert exact new manual by-memory coverage row after UID0001LX. | High | Row absent/current order | by-memory `-coverage-report.md` | incorporate | proposed |
| C051 | 0001LX | Replace stale 82% manual row with exact 93% source-factored row. | High | Current row/doc | by-memory `-coverage-report.md` | incorporate | proposed |
| C052 | 0001LN | Replace aggregate manual row with exact UID0003VX/UID0001LX source-factor detail at unchanged 90%. | High | Current row/doc | by-memory `-coverage-report.md` | incorporate | proposed |
| C053 | 0000DS | Replace class manual row with exact H/helper/type/source relation at 93%. | High | Current row/doc | by-class `-coverage-report.md` | incorporate | proposed |
| C054 | 0000O0 | Replace file manual row with exact helper/header/source relation at unchanged 92%. | High | Current row/doc | by-file `-coverage-report.md` | incorporate | proposed |
| C055 | 00001P | Existing CharInputPane manual row remains a verified prospective no-op. | High | Current exact row | by-class `-coverage-report.md` | already-present | already-present |
| C056 | 0000K7 | Existing InputPanes manual row remains a verified prospective no-op. | High | Current exact row | by-file `-coverage-report.md` | already-present | already-present |
| C057 | 0003VX | Gate 2B defines/names/types/comments function `[0x005b14f0,0x005b1568)` exactly; durable acceptance is metadata readback, not Hex-Rays local spelling. | High | Live prestate/action plan plus failed unsaved readback | supervisor IDA Gate 2B | incorporate | proposed |
| C058 | 0003VX | Gate 2B adds exact `m_spellIndex` line comment at `0x005b151b`. | High | Exact operand/prestate | supervisor IDA Gate 2B | incorporate | proposed |
| C059 | 0003VX | Gate 2B adds exact `inventorySlot` line comment at `0x005b152f`. | High | Exact operand/prestate | supervisor IDA Gate 2B | incorporate | proposed |
| C060 | 0003VX | Gate 2B adds exact counted-length terminator comment at `0x005b1548`. | High | Exact instruction/prestate | supervisor IDA Gate 2B | incorporate | proposed |
| C061 | 0003VX | Gate 2B upgrades the incomplete SpellSlotInputPane forward to the exact `0x10c` analysis UDT; exact UDT layout is required, but target pseudocode member rendering is not. | High | Current type/layout plus exact unsaved UDT readback | supervisor IDA Gate 2B | incorporate | proposed |
| C062 | 0003VX | Protected target bytes/pads, UID0001LX, successor, helpers, global, cookie, vtable cell, and correct calling conventions must remain unchanged. | High | Current hashes/readback and balanced stack proof | supervisor IDA Gate 2B | already-present | already-present |
| C063 | 0003VX | Generated SpellInputPanes CPP must have one helper definition and no empty marker; generated H must contain one class declaration. | High | Formal emitter graph | generated readback after validators | incorporate | proposed |
| C064 | 00001P | Generated InputPanes CPP/H must each contain one CharInputPane route with no duplicate declaration. | High | Formal emitter graph | generated readback after validators | incorporate | proposed |
| C065 | 0003VX | Tracker/report counts are validator-owned and must refresh after supervisor execution, not by manual text. | High | Workflow | auto-generated tracker | not-applicable | excluded-with-reason |
| C066 | 0003VX | Third-party import is not applicable; this is NexusTK-owned game code. | High | Domain/ownership | target/report checklist | not-applicable | excluded-with-reason |
| C067 | 0003VX | Gate 2B performs no direct stack-member, lvar, operand-stkvar, SP-delta, callee-type, or destructive range mutation; the assembly-backed physical frame remains authoritative if IDA retains its positive-SP warning/minimal auto-frame/placeholders. | High | Failed unsaved readback, exact stack arithmetic, positive control, current MCP schemas | supervisor IDA Gate 2B | not-applicable | proposed |

## Positive Evidence Summary

- Exact complete `__thiscall`-shaped body with one stack argument, `this+0x108`, feature opcode `0x0f`, packet writers, `g_packetSender`, and counted send length 3.
- Exact byte-for-byte packet-tail duplicate exists inside live vtable-routed UID0001LX after inventory-slot validation.
- Target and submitter have the same 300-byte packet region relative to their cookies; submitter only adds the one-character input local.
- Constructor and class docs independently establish plain `char m_spellIndex` at `+0x108` and complete size `0x10c`.
- UserStatusPane docs independently establish `m_inventorySlotCount` at `+0x284`, proving the argument's inventory-slot domain.
- Unique target signature, exact boundaries, and clean alignment establish a complete standalone method body rather than a fragment.
- Exact target/callee stack arithmetic is balanced, and UID0001LX provides a successful modeled positive control for the shared writer/send/cookie pattern; the target-only Hex-Rays warning does not contradict the source frame.
- Existing owner/emitter/source route is already coherent and passes the routing gate.

## IDA MCP Facts

- Gate 1 database `f608d7c2` and F1-repair read-only database `b3b2bf88`; dated saved IDB checkpoint `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`; health `ok`; Hex-Rays ready.
- `0x005b14f0` has no function object. `inspect_items` reports unnamed code item `[0x005b14f0,0x005b14f1)`, blank type.
- Bounded `disasm` renders 38 target instructions from prologue through `retn 4`, then `[0x005b1568,0x005b1570)` alignment and successor `sub_5B1570`.
- Stack allocation is `0x130`; packet addresses are `-0x130`, `-0x12f`, `-0x12e`, terminator `-0x12d`, cookie `-4`.
- Physical stack facts are assembly-backed: packet `[ebp-0x130,ebp-0x5]` is 300 bytes, cookie `[ebp-4,ebp-1]`, saved ESI `[ebp-0x134,ebp-0x131]`, saved EBP `[ebp]`, return `[ebp+4]`, and the logical `char inventorySlot` occupies the four-byte ABI slot `[ebp+8,ebp+0xb]`.
- `movsx [esi+0x108]` and `movsx [ebp+8]` prove signed consumption of both one-byte values.
- `PacketBufferWriteUInt8` is `void __cdecl(unsigned __int8 value, unsigned __int8 *destination)`, size `0x11`, 188 callers.
- `Socket_QueueAndSendPacket` is `void __thiscall(Socket *this, const void *packetData, __int16 packetSize)`, size `0x63`, 207 callers.
- `g_packetSender` is `Socket *` at `0x0067a7ec`.
- Writer plain-`retn`, socket `retn 8`, cookie-helper plain-`retn`, and the target's single `add esp,18h` prove exact stack balance; none of those protected types or bodies may be altered to suppress the analyzer warning.
- The failed unsaved modeled-function readback produced the exact requested durable name/range/prototype/comment, A1-A3, and T1, but only an auto-frame with `__saved_registers +0x134`, `__return_address +0x138`, and `inventorySlot +0x13c`; positive-SP/v-placeholder presentation persisted. Current physical IDB remains the restored no-function prestate.
- Target entry and internal action addresses have blank regular/repeatable comments; target has no function-comment channels or frame because no function exists.
- `SpellSlotInputPane` exists only as an incomplete non-UDT forward. `CharInputPane` is exact `0x108`; `LineInputPane` is exact `0x108`.
- UID0001LX is `sub_5B1410`, size `0xd6`, prototype `void __thiscall(int this)`, and has one data route `0x0062f6b8 -> 0x005b1410`.
- Target entry xrefs are zero. `xref_query both` reports only ordinary continuation from `0x005b14f0` to `0x005b14f1`, not an inbound route.
- Target signature is unique and the exact 28-byte family prefix appears at five direct spell helper starts.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x005b0780,0x005b14e6)` | [UID:0001LN] `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md` | non-emitting family index | FALSE | UID0000O0 | `90/93` | keep index; update helper relation |
| `[0x005b1280,0x005b130d)` | [UID:0001LV] constructor | source constructor | TRUE | UID0000DS | `89/93` | existing exact support |
| `[0x005b1310,0x005b1393)` | [UID:0004UC] destructor | source destructor | TRUE | UID0000DS | `91/94` | existing exact support |
| `[0x005b13a0,0x005b140c)` | [UID:0001LW] key handler | virtual Event handler | TRUE | UID0000DS | `91/93` | existing exact support |
| `[0x005b1410,0x005b14e6)` | [UID:0001LX] submitter | virtual input submitter | TRUE | UID0000DS | `89/91 -> 93/94` | source-factoring update |
| `[0x005b14e6,0x005b14f0)` | [UID:0000VN] ignored ledger | alignment | FALSE | ignored ledger | N/A | ten `0xcc`; unchanged |
| `[0x005b14f0,0x005b1568)` | [UID:0003VX] target | retained private packet helper | TRUE | UID0000DS | `87/89 -> 93/94` | report target |
| `[0x005b1568,0x005b1570)` | [UID:0000VN] ignored ledger | alignment | FALSE | ignored ledger | N/A | eight `0xcc`; unchanged |
| `0x005b1570` successor | [UID:0001LY] family start | Say target-message constructor | TRUE | separate SayInputPanes family | existing | protected, no merge |
| class `0x10c` | [UID:0000DS] `by-class/SpellSlotInputPane.md` | owner/emitter/class declaration | TRUE | UID0000O0 | `91/94 -> 93/94` | formal H correction |
| source root | [UID:0000O0] `by-file/SpellInputPanes.md` | `.cpp`/`.h` route | TRUE | FILE | `92/94` | update detail, no score raise |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b14f0` | zero inbound xrefs | no remaining static call/data route |
| target PE start | zero VA/RVA/raw dword and zero E8/E9 rel32 hits | no hidden static entry route |
| `0x0062f6b8 -> 0x005b1410` | SpellSlot primary vtable data cell | live UID0001LX positive control |
| `0x005b150f`, `0x005b1523`, `0x005b1534` | `PacketBufferWriteUInt8` | writes opcode, spell index, inventory slot |
| `0x005b1539` | reads `g_packetSender` | shared Socket receiver |
| `0x005b1552` | `Socket_QueueAndSendPacket(g_packetSender, packet, 3)` | sends exactly three payload bytes |
| `0x005b155d` | `@__security_check_cookie@4` | compiler security-cookie epilogue only |
| UID0001LX tail | same three writer calls, same global/send helper | compiler-inlined source-call evidence |
| UID0001LV constructor | writes byte at object `+0x108` | establishes `m_spellIndex` ownership/type |

## Documentation Evidence And IDA Status

- Target, class, file, aggregate, constructor, and submitter docs agree on direct semantic ownership and source file.
- Target doc is stale on method spelling, argument meaning/type, local buffer size, source factoring, score, and IDA action readiness.
- UID0001LX is stale on the B007 preserve-inline source decision and calls the value a selected spell slot; its binary behavior itself is correct.
- Class formal declaration is in CPP instead of H and uses stale private method spelling/type.
- CharInputPane formal declaration is also in CPP; moving it to InputPanes.h is required for a complete SpellSlotInputPane base in SpellInputPanes.h.
- Generated command20493 currently emits target and all class declarations into CPP, has no SpellInputPanes.h, and has an InputPanes.h without CharInputPane. This is input evidence, not an edit target.
- Manual by-memory row for UID0001LX is stale at 82% and says packet layout/final C++ blockers remain. UID0003VX has no manual row. Class/file rows retain old helper name/type.
- IDA lacks durable target function/UDT detail but has exact helper/global types and sufficient raw code for the narrowed durable F1/A1-A3/T1 transaction. Current tools do not support a separately safe deterministic SP/lvar repair, so analyzer presentation is an explicit no-mutation disposition rather than an uninvestigated blocker.

## Ranked Ownership Analysis

### 1. UID0000DS SpellSlotInputPane

- Evidence for: `thiscall` receiver, sole derived byte at `+0x108`, constructor write, live submitter duplicate, class adjacency, same opcode and feature semantics, existing canonical owner/emitter.
- Evidence against: no static route to retained body and no original declaration spelling.
- Decision: direct semantic/source owner with very strong confidence; route absence is a liveness/history fact, not an ownership veto.

### 2. UID0000O0 SpellInputPanes

- Evidence for: owns the complete spell prompt family and generated `NexusTK/ui/dialogs/SpellInputPanes.cpp` route.
- Evidence against: a by-file page is a source root, not the direct method owner.
- Decision: retain as source-file route through UID0000DS.

### 3. PacketBuffer / Socket / ProtocolSend

- Evidence for: target calls their writer and sender services.
- Evidence against: utilities do not own opcode `0x0f`, `m_spellIndex`, inventory-slot validation, or SpellSlotInputPane state.
- Decision: reject as owner/source placement; retain as dependencies only.

### 4. Ownerless/no-emitter or generic SpellPacketHelpers.cpp

- Evidence for: no static route survives and sibling raw islands exist.
- Evidence against: target has exact class receiver/state and live inlined counterpart; a generic file would erase class-private context and produce tool-shaped organization.
- Decision: reject.

### Proposed new file/grouping, if applicable

- No new source grouping. Materialize `SpellInputPanes.h` as the declaration channel paired with existing `SpellInputPanes.cpp`.
- Do not create a separate helper file, protocol file, or raw-range file.

## Source Placement

- Recommended source placement: private member definition in `NexusTK/ui/dialogs/SpellInputPanes.cpp`, declaration in `NexusTK/ui/dialogs/SpellInputPanes.h` on UID0000DS.
- Base placement: `CharInputPane` declaration in existing `NexusTK/ui/dialogs/InputPanes.h`; definitions remain in `InputPanes.cpp`.
- This matches late-1999 through mid-2000s C++ organization: feature class owns packet action; reusable input base remains in its base module; packet utilities remain shared dependencies.
- Rejected placements: PacketBuffer, Socket, ProtocolSend, SpellInventoryPane, SayTargetMessageInputPanes, standalone `SpellPacketHelpers.cpp`, or raw-address-organized source.
- Remaining uncertainty is only original filename/include ordering and lexical spelling; existing file routes are strong enough and no alternative has comparable evidence.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and complete; no split, merge, or range extension is required.
- Predecessor UID0001LX ends at `0x005b14e6`; ten-byte alignment ends exactly at target start.
- Target ends at `0x005b1568`; eight-byte alignment ends exactly at successor start `0x005b1570`.
- Both pads are compiler/linker-generated alignment already recorded in UID0000VN and remain non-emitting.
- Reclassification already occurred historically from ownerless/non-reconstructable to source-authored reconstructable; this report keeps that direction and improves source quality rather than changing range ownership.
- Aggregate UID0001LN remains a non-reconstructable split index with blank formal code because exact children own bodies.

## Negative Evidence Summary

- No IDA function object, inbound xref, target pointer, vtable cell, direct call/jump, or generated marker remains for the target.
- No VA/RVA/raw-offset dword or E8/E9 rel32 route exists in the current executable.
- No collision exists for `SpellSlotInputPane__SendSpellUsePacket`, `SpellSlotInputPane_SendSpellUsePacket`, or `SendSpellUsePacket`.
- No evidence supports PacketBuffer/Socket ownership; their high caller counts confirm generic utility roles.
- No evidence supports treating inventory slot as spell slot; the live upper-bound field is explicitly the inventory slot count.
- No evidence supports `unsigned char` source semantics for the decoded slot; the lower-bound test is signed.
- No evidence supports a four-byte source buffer; exact frame allocation and repeated project packet buffers support 300 bytes.
- No evidence requires hand-written duplicate packet code in UID0001LX; lack of a binary call is expected after inlining.
- No evidence supports merging adjacent alignment or successor bytes into the target.
- No binary or positive-control evidence supports changing `PacketBufferWriteUInt8`, `Socket_QueueAndSendPacket`, or `@__security_check_cookie@4` calling conventions to silence the target-only positive-SP diagnostic.
- No current MCP operation can safely promise the old F1 packet/cookie/`this`/argument Hex-Rays rendering: direct frame creation lacks dry-run and does not repair SP deltas, local operations require stable existing locals, operand `stkvar` tagging cannot select/create members, and destructive undefine/redefine would exceed the evidence.
- No original symbol/PDB survives. This rejects claims of exact lexical recovery but not the obligation to choose human names.

## IDA Rename / Type / Comment Recommendations

The following is a supervisor-only Gate 2B handoff. B005 performed no mutation or save.

Bounded F1 repair-path audit:

- **Re-run durable F1 only:** supported. `define_func` and function `set_type` expose exact range/prototype operations, and the failed unsaved transaction proved the name/range/prototype/repeatable-comment readback succeeds. This remains F1.
- **Direct packet/cookie frame declarations:** rejected. The only evidence-aligned candidates would use frame-pointer displacements `-0x130` for `unsigned char packet[300]` and `-0x4` for a compiler cookie. Current `declare_stack` has no dry-run, replace/overlap control, or rollback result; a prior experiment was unsafe; and creating members cannot repair an SP delta. Do not attempt these declarations under this report.
- **Rename/type `v2`-through-`v9`:** rejected. Those are unstable Hex-Rays placeholders from the failed analyzer state, not persistent semantic identities. `rename` dry-run and local `set_type` both require an existing exact local name and cannot merge placeholders into one 300-byte array or repair SP analysis.
- **Tag EBP operands as stack variables:** rejected. `set_op_type(kind=stkvar)` has no schema field selecting the intended frame member and cannot create the packet/cookie or change SP deltas. Blindly tagging operands at `0x005b1500`, `0x005b1504`, `0x005b1514`, `0x005b1528`, `0x005b152f`, `0x005b153f`, `0x005b1548`, or `0x005b1557` would not supply an exact readback contract.
- **Force Hex-Rays recompilation:** insufficient. `force_recompile` invalidates only the decompiler cache; the supervisor already obtained a fresh `analyze_function` result with the positive-SP diagnostic after exact metadata application. Cache invalidation is not a frame/SP correction and cannot promise local rendering.
- **Change writer/socket/cookie conventions:** rejected as false. Bounded callee disassembly and UID0001LX prove the current cdecl/plain-`retn`, thiscall/`retn 8`, and fastcall/plain-`retn` models are correct and stack-balanced.
- **Undefine/redefine/reanalyze the body:** rejected. The current API offers no read-only preview of resulting SP/frame state, while `undefine` would destructively discard established code-item analysis and could disturb xrefs/comments. Exact bytes alone do not make that analysis mutation safe.
- **Supported conclusion:** persist only F1/A1-A3/T1, preserve P1-P8, and record F1L without direct frame/lvar/SP mutation. The physical frame remains exact assembly-backed evidence even when IDA's automatic presentation is minimal.

| ID | Entity | Literal current pre-state | Proposed supervisor action | Expected readback / protections |
| --- | --- | --- | --- | --- |
| F1 | function `[0x005b14f0,0x005b1568)` | Restored durable prestate: no function; start item unnamed code `[0x005b14f0,0x005b14f1)`, type absent; address regular `""`, address repeatable `""`; function regular/repeatable channels absent because no function; no frame. Name collisions for `SpellSlotInputPane__SendSpellUsePacket`, `SpellSlotInputPane_SendSpellUsePacket`, and `SendSpellUsePacket`: none. Physical IDB remains SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`. | Define exact function range; name `SpellSlotInputPane__SendSpellUsePacket`; apply `void __thiscall SpellSlotInputPane__SendSpellUsePacket(SpellSlotInputPane *this, char inventorySlot)`; set function-repeatable comment exactly `Retained SpellSlotInputPane packet helper: sends opcode 0x0f with m_spellIndex and one validated inventory slot; the live submitter contains an inline duplicate and no static entry/pointer route remains.` Leave function-regular and address regular/repeatable comments blank. Do not add any frame/lvar/SP/operand mutation under F1. | Durable acceptance: exact name, range, prototype, function-repeatable comment, blank nonselected comment channels, and unchanged body/pads. The automatic `stack_frame` may remain the observed minimal three-row model (`__saved_registers +0x134`, `__return_address +0x138`, `inventorySlot +0x13c`), and fresh analysis may retain `positive sp value has been detected` plus `v2`-through-`v9` placeholders. Neither presentation is a rollback condition. Physical packet/cookie/saved-register/argument facts remain exact assembly-backed documentation and are not promised Hex-Rays-local readback. |
| F1L | target stack/Hex-Rays presentation | In the discarded unsaved transaction, F1 metadata read back exactly, while `analyze_function` retained the positive-SP diagnostic and placeholder locals; `stack_frame` exposed only the three rows listed in F1. Restored current IDB has no function/frame. Current MCP has no SP-delta tool; `declare_stack` has no dry-run/overlap contract; `set_op_type(stkvar)` cannot select/create a member; local rename/type requires stable existing locals; `force_recompile` only invalidates cache. | No mutation. Do not call `declare_stack`, `delete_stack`, local/stack `rename`, local `set_type`, `set_op_type(kind=stkvar)`, `undefine`, `define_code`, `patch`, or alter protected callee conventions for this target. Record the fresh analyzer/frame result after F1, but accept it as presentation-only when durable F1/A1-A3/T1/P1-P8 readback is exact. | Exact no-action readback: no extra manual frame members or user lvar overrides; correct target/callee bytes and conventions unchanged. Assembly remains authoritative for packet `[ebp-0x130,ebp-0x5]`, cookie `[ebp-4,ebp-1]`, saved ESI `[ebp-0x134,ebp-0x131]`, saved EBP/return, and the `[ebp+8,ebp+0xb]` argument slot. A positive-SP warning/minimal auto-frame/placeholders are recorded as an IDA analyzer limitation, not a source or score blocker. |
| A1 | address `0x005b151b` | unnamed instruction `movsx eax, byte ptr [esi+108h]`; regular `""`; repeatable `""`. | Set address regular comment exactly `m_spellIndex`; leave repeatable blank. | Same instruction bytes and exact regular comment. |
| A2 | address `0x005b152f` | unnamed instruction `movsx eax, byte ptr [ebp+8]`; regular `""`; repeatable `""`. | Set address regular comment exactly `inventorySlot`; leave repeatable blank. | Same instruction bytes and exact regular comment. |
| A3 | address `0x005b1548` | unnamed instruction `mov byte ptr [ebp-12Dh], 0`; regular `""`; repeatable `""`. | Set address regular comment exactly `packet terminator; excluded from the counted 3-byte payload`; leave repeatable blank. | Same instruction bytes and exact regular comment. |
| T1 | type `SpellSlotInputPane` | Name exists only as incomplete non-UDT forward, invalid/unknown size, zero members. `CharInputPane` is UDT size `0x108` with one `_opaque[264]`; no `m_spellIndex` member collision. | Replace/complete analysis UDT as `struct SpellSlotInputPane { CharInputPane base; char m_spellIndex; unsigned char _tailPadding[3]; };`. `_tailPadding` is analysis-only compiler alignment, not a source member. | Durable acceptance: UDT size `0x10c`; base `[0x0,0x108)`, `m_spellIndex` `+0x108` size 1 type `char`, tail `+0x109..+0x10b`. Target pseudocode member rendering is not required because F1L separately records the analyzer limitation. |
| P1 | target bytes and fences | Body SHA `2CE684779DB3DC1DEF0B70344E5FBA59114A964BACA3985A0DAD7E68309707CC`; prepad SHA `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`; postpad SHA `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`. | No change recommended. | All three exact hashes/ranges unchanged; no boundary widening. |
| P2 | live UID0001LX `0x005b1410` | `sub_5B1410`, size `0xd6`, prototype `void __thiscall(int this)`, all four comment channels blank, body SHA `ADE0D3B0CA78238D238DE603F15DD0E1E7A268A6DBE61798F7DE8BFC67DA605E`. | Protected dependency; no action under this report. | Name/type/comments/bytes/xref `0x62f6b8` unchanged. |
| P3 | successor `0x005b1570` | `sub_5B1570`, size `0xc1`, prototype `char *__thiscall(char *this, wchar_t *Source)`, all four comment channels blank, body SHA `E3564FA5956BB8CA814AE7593653E1086CF2B4D3405D51205BA2C3F8709CA4BB`. | No change recommended. | Exact successor start/name/type/bytes unchanged. |
| P4 | `0x00575380` | `PacketBufferWriteUInt8`, size `0x11`, prototype `void __cdecl(unsigned __int8 value, unsigned __int8 *destination)`, function regular comment `Shared value-first PacketBufferWriteUInt8 helper. Writes the low byte to destination and a local zero terminator after it; callers control transmitted length.`, function repeatable blank, body SHA `071C3585478373BDFDBAF2EF7405EAEB2972B69714CF3B146768F317535D5CDE`. | No change recommended. | Exact name/type/comment/body unchanged. |
| P5 | `0x00574bb0` | `Socket_QueueAndSendPacket`, size `0x63`, prototype `void __thiscall(Socket *this, const void *packetData, __int16 packetSize)`, function regular comment `Source: Socket::QueueAndSendPacket(const void *, short). Copies exactly caller length, appends its own zero byte, and dispatches length+1.`, function repeatable blank, body SHA `ACFD959C6C3C771F8CB8DD3A5ABEDAF200D87816DA848CEA44F6997B6EF588F3`. | No change recommended. | Exact name/type/comment/body unchanged. |
| P6 | global `0x0067a7ec` | `g_packetSender`, type `Socket *`, regular comment `Active packet-sender Socket singleton used by UserPane.cpp retained packet helpers.` newline `Canonical Socket *g_packetSender singleton used by packet serializer methods.`, repeatable blank. | No change recommended. | Exact name/type/two-line regular comment unchanged. |
| P7 | cookie/global helper | `___security_cookie` at `0x00672f24`, type `uintptr_t`; `@__security_check_cookie@4` at `0x005c772f`, size `0x11`, prototype `void __fastcall(uintptr_t StackCookie)`, all four comments blank, body SHA `7D2869F94F310B70F9964FEDA643CDCBBE7DA46E4F49BDBD6061EDD330DB3E66`. | No change recommended. | Exact compiler/runtime identities and bytes unchanged. |
| P8 | vtable cell `0x0062f6b8` | unnamed four-byte data cell, comments blank, points to `sub_5B1410`; no target pointer cell. | No change recommended. | Cell remains `0x005b1410`; do not point it to UID0003VX. |

Gate 2B stop conditions: any body/pad/successor hash drift; a newly occupied proposed name; changed target/function boundary; different `CharInputPane` size; a newly existing incompatible SpellSlotInputPane UDT; changed helper/global prototypes/calling conventions; a newly discovered inbound route; or any extra manual frame/lvar/operand mutation. Back up the current IDB, perform only F1/A1-A3/T1 serially, read back every durable row plus F1L/P1-P8, and do not roll back solely because the observed positive-SP/minimal-frame/placeholder presentation persists. Save once only after all durable readbacks pass, hash the saved IDB, and record dated pre/post identities and the exact analyzer diagnostic. A future deterministic SP/local repair requires a separate evidence-backed recommendation and must not be improvised in this transaction.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Target and UID0001LX are reconstructable source bodies above 85/85 with resolved behavior, ownership, types, and source placement.
- Third-party import: not applicable; this is NexusTK-owned game code.

Target [UID:0003VX] formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
void SpellSlotInputPane::SendSpellUsePacket(char inventorySlot)
{
    unsigned char packet[300];

    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt8(inventorySlot, packet + 2);
    packet[3] = 0;

    g_packetSender->QueueAndSendPacket(packet, 3);
}
```

Target [UID:0003VX] formal `RECONSTRUCTION_H CODE`: blank. The declaration belongs to UID0000DS.

UID0001LX formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
void SpellSlotInputPane::SubmitSpellSlot()
{
    if (GetTextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    char inventorySlot = -1;
    if (ch >= L'a' && ch <= L'z') {
        inventorySlot = static_cast<char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        inventorySlot = static_cast<char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (inventorySlot < 1 ||
        inventorySlot > g_activeUserStatusPane->m_inventorySlotCount) {
        return;
    }

    SendSpellUsePacket(inventorySlot);
}
```

UID0001LX formal H: blank; declaration belongs to UID0000DS.

UID0000DS formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
#include "SpellInputPanes.h"

[[CHILDREN]]
```

UID0000DS formal `RECONSTRUCTION_H CODE` replacement:

```cpp
#include "InputPanes.h"

class Event;

class SpellSlotInputPane : public CharInputPane
{
public:
    explicit SpellSlotInputPane(char spellIndex);
    virtual ~SpellSlotInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void SubmitSpellSlot();

private:
    void SendSpellUsePacket(char inventorySlot);

    char m_spellIndex;
};
```

UID00001P formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
#include "InputPanes.h"

[[CHILDREN]]
```

UID00001P formal `RECONSTRUCTION_H CODE` replacement:

```cpp
class Event;

class CharInputPane : public LineInputPane
{
public:
    CharInputPane(const wchar_t *promptText);
    virtual ~CharInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnAccept() {}
};
```

- Exact behavior preservation: validation remains in UID0001LX; helper emits the same three counted bytes and unsent terminator; `char` values are in valid range 1..52 before the call; compiler may inline the private helper to reproduce the observed binary tail.
- Human-source shape: private member helper, normal class/header separation, shared base header, source-level names, and 300-byte subsystem packet scratch buffer are plausible for the original era and codebase.
- Compiler-only omissions: no explicit cookie, frame, `movsx`, vptr, padding member, or raw address labels appear in human source.
- Naming convention: `SendSpellUsePacket`, `inventorySlot`, and `m_spellIndex` follow nearby verb/object/member conventions and avoid mixed decompiler naming.
- IDA presentation does not override this formal source: the positive-SP warning and placeholder locals are analyzer output for an otherwise balanced body, not evidence for assembly-shaped C++ or a smaller packet buffer.

## Final Recommendation

- C001-C044 target/support ordinary documentation and formal-channel changes are implemented and destination-verified after supervisor Gate 1.
- C045-C049 support facts were re-read and verified current without edits.
- Apply supervisor-only manual operations C050-C054; preserve C055-C056 as verified no-ops.
- Apply/verify supervisor-only durable IDA actions C057-C061, all C062 protections, and the explicit C067/F1L no-frame-mutation disposition during Gate 2B.
- Refresh generated output through scoped validators and verify C063-C064; never edit generated files directly.
- Do not change ranges, owner/emitter IDs, reconstructable state, aggregate emitter state, padding, vtable routes, PacketBuffer/Socket/global types, or sibling raw-helper dispositions.
- No material target open question remains. Exact lexical spelling is unavailable but resolved to the best human-facing inference and retained as a sub-95 confidence cap; unstable Hex-Rays local rendering is separately classified as an IDA analyzer limitation and does not reopen source behavior.

## Recommended Target Doc Changes

- Path: `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md`.
- Implemented metadata: `COMPLETION:93`, `CONFIDENCE:94`; owner/emitter/reconstructable/position remain unchanged.
- Implemented Item Summary records complete current range/hash, retained/no-route source disposition, plain-char field/argument, 300-byte buffer, exact packet bytes, helper/global contracts, UID0001LX inlining relation, and source/class/file route.
- Formal CPP exactly matches the target block above; formal H remains blank.
- Exact live IDA prestate, narrowed durable function/type/comment handoff, failed unsaved analyzer readback, no-frame-mutation disposition, PE route scan, signature/family result, source-placement rationale, score rationale, and rejected alternatives are incorporated.
- Old ownerless/non-emitting, selected-spell-slot, four-byte-buffer, and `SendSpellSlotPacket` claims remain in dated historical-assumptions text with exact rejection reasons.

## Recommended Support Doc Changes

- `by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md`: C017-C024, exact helper-call formal CPP, `93/94`, and B007 historical correction are implemented and verified.
- `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`: C036-C039 are implemented and verified with all sibling dispositions and `90/93` non-emitting aggregate metadata preserved.
- `by-class/SpellSlotInputPane.md`: C025-C031, exact CPP/H blocks, method inventory, layout/type proof, and `93/94` are implemented and verified.
- `by-file/SpellInputPanes.md`: C032-C035, exact `.cpp/.h` route, retained-helper/inline-source relationship, and unchanged `92/94` are implemented and verified.
- `by-class/CharInputPane.md`: C040-C043 are implemented and verified; the exact declaration is in H at unchanged `92/94`.
- `by-file/InputPanes.md`: C044 is implemented and verified; generated H placement is documented at unchanged `92/92`.
- UID0003YJ, UID0001HU, UID0000Q5, UID0001PE/UserStatusPane, and UID0000VN: no ordinary edit; current detail is already same-or-greater and is protected support evidence.
- No generated, tracker, manual coverage, audit, catalog, lifecycle, goal, or notes file may be edited by B005.

## Score And Metadata Recommendation

- UID0003VX moved from Gate 1 `87/89` to callback poststate `93/94`. Completion rises because exact source name/type/buffer/factoring/formals/IDA plan/manual rows/open questions are closed. Confidence rises because live MCP, raw PE, current docs, and family evidence agree. It remains below 95 because original symbols and a surviving route are unavailable.
- UID0001LX moved from Gate 1 `89/91` to callback poststate `93/94`. Exact signed slot semantics and source factoring are now resolved; binary behavior/range/vtable were already strong. It remains below 95 because lexical names/factoring are inferred rather than recovered source.
- UID0000DS moved from Gate 1 `91/94` to callback poststate `93/94`. Completion rises for complete H routing and helper contract. Confidence remains 94 under the final-audit gate.
- UID0000O0 remains `92/94`: this target improves one class/helper but the broad file still contains unrelated declarations/raw-helper policies and is not fully final-audited.
- UID0001LN remains `90/93`: it is a broad non-emitting index with independently unresolved sibling helper dispositions.
- UID00001P remains `92/94`: only declaration channel moves; behavior/layout evidence does not materially change.
- UID0000K7 remains `92/92`: exact original include/file split and wider family final compile closure remain broader concerns.
- Metadata unchanged unless listed: UID0003VX/UID0001LX keep owner `0000DS`, reconstructable true, emitter `0000DS`; UID0000DS keeps owner/emitter `0000O0`; aggregate remains reconstructable false with no emitter; file roots remain `FILE`.
- Score-improvement attempts closed every assigned blocker: live no-route scan, exact type/layout, packet fields, buffer extent, source naming, UID0001LX factoring, CPP/H placement, support rows, durable IDA plan, and manual coverage plan. The bounded F1 repair proves the remaining positive-SP/local-placeholder issue is analyzer presentation rather than missing source research. No unchanged-target-score exception is used.

## Open Questions With Attempted Resolution

- **Is the helper live?** Static entry/pointer/vtable/rel32 scans are exhaustively negative. Resolution: retained/no-route out-of-line source body whose live source call was inlined; do not claim runtime entry liveness.
- **Is it source-authored?** Feature-specific packet construction and class state disprove pure compiler/runtime ownership. Resolution: source-authored method with compiler cookie/inlining consequences.
- **What is `this+0x108`?** Constructor/class/family evidence all identify plain `char m_spellIndex`. Resolved.
- **What is `[ebp+8]`?** UID0001LX's exact decode and `m_inventorySlotCount` check identify a one-based inventory slot. Resolved as `char inventorySlot`.
- **What is the best method name?** `SendSpellUsePacket` best separates the spell index from inventory slot and matches sibling direction. `SendSpellSlotPacket`, `SendDirectSlotPacket`, raw-address names, and `SubmitSpellSlot` are rejected for precise reasons. Resolved as high-probability inference.
- **Four-byte or 300-byte source buffer?** Exact frame intervals and subsystem convention prove 300-byte scratch storage. Resolved.
- **Duplicate source or inlined helper?** Retained out-of-line body, exact live duplicate, private helper role, and identical 300-byte layout make source call plus compiler inlining the higher-probability source. Resolved; preserve B007's duplicate-body policy only as history.
- **Where do declarations go?** Formal H on class emitters; complete base in InputPanes.h; class CPP includes generated H and emits children. Resolved.
- **Should target filename be renamed?** No. Stable UID/path and historical links outweigh cosmetic path churn; human source name lives in content/formal C++/IDA. Resolved.
- **Can Gate 2B safely force `this`, `inventorySlot`, `packet[300]`, and cookie rendering?** No with the current supported MCP/IDA model. Exact stack arithmetic and the UID0001LX control prove the frame semantics, but no SP-delta tool exists; direct frame declaration has no dry-run and cannot correct SP analysis; operand/local tools require stable modeled members; destructive redefinition and correct-callee convention changes are unsafe. Resolution: persist exact function/type/comment/UDT metadata, prohibit direct frame/lvar mutation, record the analyzer warning/minimal frame honestly, and keep assembly-backed physical frame facts authoritative.
- **What remains unavailable?** Exact original symbols/PDB and dynamic call history. Neither blocks source behavior/name inference; they cap confidence at 94.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only checkpoint identities: by-memory `-coverage-report.md` SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, 2,134,111 bytes/4,803 lines; by-class SHA256 `0A2F8F0BF6EF28ECB9633E504A0C2B59BCBF022B31201B33A1AAAB319B15D272`, 275,060 bytes/625 lines; by-file SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`, 166,582 bytes/319 lines. These are dated read checkpoints; exact UID rows/anchors must be re-read before supervisor application because whole-file hashes and line numbers can move.

**M01: insert UID0003VX in by-memory coverage immediately after the UID0001LX row and before UID0001LY:**

```text
    - [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) 0x005b14f0-0x005b1568 | retained member packet helper | SpellSlotInputPaneSendSpellUsePacket : reconstructable : 93% : very-strong : Exact retained no-route SpellSlotInputPane::SendSpellUsePacket(char inventorySlot) body with 0x78/120-byte SHA256 2CE684779DB3DC1DEF0B70344E5FBA59114A964BACA3985A0DAD7E68309707CC range, exact 300-byte packet scratch, opcode 0x0f, plain-char m_spellIndex at +0x108, validated inventory-slot argument, unsent terminator, length-3 Socket send, PacketBuffer/global dependencies, ten/eight-byte alignment fences, exhaustive static no-route proof, UID0001LX compiler-inline relationship, SpellSlotInputPane/SpellInputPanes owner-emitter route, formal source, and complete supervisor IDA handoff.
```

**M02: replace the existing UID0001LX by-memory row:**

```text
    - [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md) 0x005b1410-0x005b14e6 | virtual input submit handler | SpellSlotInputPaneSubmitSpellSlot : reconstructable : 93% : very-strong : Exact vtable-routed SpellSlotInputPane submitter with one-character a-z/A-Z inventory-slot decode, signed plain-char lower-bound behavior, UserStatusPane inventory-slot-count upper bound, compiler-inlined call-equivalent tail for UID0003VX SendSpellUsePacket, opcode 0x0f three-byte payload, 300-byte packet scratch, m_spellIndex, PacketBufferWriteUInt8, g_packetSender/QueueAndSendPacket, exact range/padding, formal source, and historicalized duplicate-source assumption.
```

**M03: replace the existing UID0001LN by-memory row at unchanged 90%:**

```text
    - [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md) 0x005b0780-0x005b14e6 | non-emitting class-method aggregate | SpellArgumentInputPanes : not_reconstructable : 90% : very-strong : Exact spell argument input-pane split index with five signed one-byte prompt constructors, five local direct/scalar destructor pairs, exact confirm/submit children and nineteen internal padding spans; UID0003VX is the retained SpellSlotInputPane::SendSpellUsePacket(char inventorySlot) source helper whose source call is compiler-inlined in UID0001LX, while each sibling direct-helper disposition remains independently evidence-bound; aggregate stays blank/non-emitting because exact children own source.
```

**M04: replace the existing UID0000DS by-class row:**

```text
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md) : reconstructable : 93% : very-strong : Complete 0x10c CharInputPane-derived declaration in SpellInputPanes.h with plain char m_spellIndex at +0x108, natural tail alignment, constructor, virtual destructor, canonical EventHandler, SubmitSpellSlot, private SendSpellUsePacket(char inventorySlot), exact retained helper/UID0001LX compiler-inline relationship, direct destructor, scalar/adjustor/vtable compiler separation, formal CPP/H routes, and class closure before children.
```

**M05: replace the existing UID0000O0 by-file row at unchanged 92%:**

```text
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) : reconstructable : 92% : very-strong : NexusTK/ui/dialogs/SpellInputPanes.cpp source root with generated SpellInputPanes.h declaration route for SpellSlotInputPane, complete class/child ownership, canonical EventHandler signatures, six signed-index prompt families and exact direct/scalar destructor pairs, exact prompt/accessor/confirm/submit bodies, retained UID0003VX SendSpellUsePacket(char inventorySlot) helper with UID0001LX compiler-inline source relationship, independent sibling raw-helper dispositions, and compiler-only scalar/adjustor/vtable/EH/cookie artifacts excluded.
```

**N01: verified prospective no-op, by-class UID00001P.** Current row already says reconstructable 92%, very-strong, InputPanes ownership, complete human source, exact handler behavior, inheritance, and compiler-thunk separation. Moving the same declaration from CPP to H does not make its row semantically stale.

**N02: verified prospective no-op, by-file UID0000K7.** Current row already says reconstructable 92%, very-strong, and complete `InputPanes.cpp/InputPanes.h` route. The CharInputPane H-channel correction makes that existing description more exact without requiring row replacement.

The B agent must not apply M01-M05 directly because all manual `-coverage-report.md` files are supervisor-owned collision points. The supervisor must re-read exact UID anchors, apply only still-applicable operations, and classify an already-exact row as a no-op.

## Follow-Up Actions

- Supervisor Gate 1 passed exact pre-callback report SHA256 `38F80FCEE109087F46DE9E9D72528FD4E9A18B781AABEE51994C380A988FAC27`; B005 completed the exact seven-file ordinary callback and reconciled this same report.
- Manual coverage disposition: M01-M05 and N01-N02 are supervisor-owned; their authoritative state comes from current manual-row readback and supervisor records. B005 does not edit manual coverage files.
- IDA disposition: F1/A1-A3/T1, F1L, and P1-P8 are supervisor-owned; their authoritative persisted state comes from live IDB readback, the saved-IDB hash, and the supervisor IDA catalog. This report supplies the exact action/protection contract without asserting its current lifecycle state.
- Generated disposition: generated topology is authoritative from current validator command metadata and generated-file headers. The required topology is one target definition, one helper declaration, one CharInputPane declaration, no duplicate class/definition, and no UID0003VX empty marker; generated files are never manual edit targets.
- Agent assignment disposition: scheduling is supervisor-owned and authoritative from each agent's current `goal.md`; this report neither assigns an A agent nor selects a new B005 target.

## Confidence

- Behavior/range/packet confidence: very strong, direct bytes/disassembly/helpers.
- Owner/emitter/source placement confidence: very strong, exact receiver/state/live duplicate/class/file route.
- Field/argument type confidence: very strong, constructor plus signed instructions and inventory-count semantics.
- Source factoring confidence: strong to very strong; exact retained body plus inline duplicate and matching stack-buffer shape make helper-call source more probable than hand duplication.
- Source-facing lexical-name confidence: strong inference, not original-symbol proof.
- Durable IDA metadata confidence: high for function range/name/prototype/comments and exact UDT. Hex-Rays local-presentation confidence is intentionally not scored as source evidence because the current analyzer retains a target-only positive-SP warning despite balanced assembly and a successful modeled sibling control.
- Score confidence: high for `93/94`; `95+` is deliberately rejected because lexical symbols and a surviving route are absent and full final-binary reproduction has not been audited.
- Remaining uncertainty: exact original method/local spellings and compiler inlining decision flags only; no material behavior/ownership/formal-source blocker remains.

## Validator Results

- All commands ran serially from `source-3/project-documentation` with `--apply --queue-timeout 240 --no-generated-refresh`. B005 did not run a generated refresh, report validator, lifecycle command, or `execute_report`.
- `000000020496`, `2026-08-01T03:25:54-04:00`: target file command exited `0`, `ok: 1`; generated refresh explicitly skipped. Poststate SHA256 `C6662A38B66068CC96BE040CECB52A83097B8129E8201D69153C02D22E5B75EA`, 22,598 bytes/164 lines.
- `000000020499`, `2026-08-01T03:27:39-04:00`: UID0001LX command exited `0`, `ok: 1`; generated refresh explicitly skipped. Poststate SHA256 `6DF3689528626C0C6A44349CC3870BAF62EE1AD466FD43FE0D5B3492960F5427`, 21,297 bytes/156 lines.
- `000000020500`, `2026-08-01T03:28:59-04:00`: UID0000DS command exited `0`, `ok: 1`; generated refresh explicitly skipped. Poststate SHA256 `5635C89FE32EC3D52A2629C4BCA04F82BD299CFD2084B0D513CE27B1C60EA0C8`, 17,994 bytes/138 lines.
- `000000020504`, `2026-08-01T03:31:16-04:00`: UID0000O0 command exited `0`, `ok: 1`; generated refresh explicitly skipped. Poststate SHA256 `1C47A2E602594CF9A890EF5CE2129AAD17FE041C7114ACCDF2315A40577FB0C9`, 79,601 bytes/304 lines.
- `000000020505`, `2026-08-01T03:33:18-04:00`: UID0001LN command exited `0`, `ok: 1`; generated refresh explicitly skipped. Poststate SHA256 `ACB79FF2D02E56F7F471A1AE894BBDF50E35EF50375B30DBD565A5D2739D684B`, 51,829 bytes/254 lines.
- `000000020506`, `2026-08-01T03:35:26-04:00`: UID00001P command exited `0`, `ok: 1`; generated refresh explicitly skipped. Diagnostics were two pre-existing missing-reference UIDs (`000363`, `00036F`) plus validator-owned registry/reference/projected-stat updates. Poststate SHA256 `39D8677B5BA88590559960C81F4F56841BFAFB6E34951B346FA22A2E638354C4`, 13,114 bytes/125 lines.
- `000000020507`, `2026-08-01T03:36:23-04:00`: UID0000K7 command exited `0`, `ok: 1`; generated refresh explicitly skipped. Diagnostics were 24 pre-existing missing-reference UIDs, ten displayed and fourteen suppressed, plus validator-owned projected-stat maintenance. Poststate SHA256 `13ABF6D49167013EE55B971955EFA1BBE02B6E60BB03B4A6DB41D2D63DDE5D19`, 29,200 bytes/168 lines.
- Validator-owned registry/reference/projected-stat maintenance is a side effect of the seven authorized scoped commands, not a manual B005 edit. No validator reported `ok: 0`, a nonzero exit, or a callback contradiction.
- No validator was run for this narrow report-only F1 readback repair because no by-* destination changed. The prior seven callback validator records remain exact and are not rerun or relabeled as current repair evidence.
- Generated truth is authoritative from current validator command metadata and generated-file headers. B005 did not run the supervisor-owned generated-refresh/wait operation during the ordinary callback or this report repair and does not assert its current lifecycle state; report lifecycle commands remain supervisor-only.

## Changed Files

- Modified ordinary docs: the exact seven callback destinations listed in the post-validation checkpoint section; no destination outside that write set was edited.
- Modified report: this same `tools/leaser/Agents/Agent-B005/research/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md` artifact, additively reconciled after destination verification.
- Narrow F1-repair sections changed in this revision: `Finalized Report / Current Recommendation`, `Supporting Research`, `Target`, `Current Target State`, `Supervisor Active Recheck`, `Heuristic / Inference Reanalysis And Validation`, `Evidence Standards Used`, `Evidence Checked`, `Claim And Incorporation Ledger`, `Positive Evidence Summary`, `IDA MCP Facts`, `Documentation Evidence And IDA Status`, `Negative Evidence Summary`, `IDA Rename / Type / Comment Recommendations`, `First-Draft C++ Recommendation`, `Final Recommendation`, `Recommended Target Doc Changes`, `Score And Metadata Recommendation`, `Open Questions With Attempted Resolution`, `Follow-Up Actions`, `Confidence`, `Validator Results`, `Changed Files`, and `Implementation Tracking Checklist`. All edits are additive or narrowly corrective; ordinary callback research, formal code, manual coverage payloads, and destination evidence remain intact.
- Manually modified IDA/manual coverage/generated/tracker/project-state/audit/catalog/lifecycle/goal/notes files: none.
- Authorized scoped validators performed their normal validator-owned registry/reference/projected-stat maintenance; B005 did not manually edit or inspect those moving files as callback destinations.
- Renamed/moved files: none.
- Lease discipline: each ordinary destination was leased only for its own edit/validator/reopen cycle and released immediately. No lease is required for B005's own report-only F1 repair; no ordinary destination was opened for edit in this revision.
- Report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. B005 did not run or probe any report lifecycle command.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 validated exact pre-callback SHA256 `38F80FCEE109087F46DE9E9D72528FD4E9A18B781AABEE51994C380A988FAC27` before implementation.
- [x] Applied C001-C016 to `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md` at report-level detail.
- [x] Replaced target metadata with `93/94` while preserving owner `0000DS`, reconstructable true, emitter `0000DS`, and blank position.
- [x] Replaced target formal CPP exactly; preserved target formal H blank.
- [x] Applied C017-C024 to `by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md`.
- [x] Replaced UID0001LX formal CPP with exact validated decode plus helper-call source; kept H blank; set `93/94`.
- [x] Applied C025-C031 to `by-class/SpellSlotInputPane.md`, including exact formal CPP/H and `93/94`.
- [x] Applied C032-C035 to `by-file/SpellInputPanes.md` without raising `92/94`.
- [x] Applied C036-C039 to `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md` without changing non-emitting `90/93` metadata.
- [x] Applied C040-C043 to `by-class/CharInputPane.md`, moving exact declaration to H while keeping `92/94`.
- [x] Applied C044 to `by-file/InputPanes.md` while keeping `92/92`.
- [x] Verified C045-C049 remain present at same-or-greater detail; made no unnecessary support edits.
- [x] Preserved all old ownerless/no-code, `SendSpellSlotPacket`, `selectedSlot`, four-byte-buffer, and B007 duplicate-source assumptions as dated disproved history with exact rejection reasons.
- [x] Preserved every sibling direct-helper disposition; did not generalize UID0003VX conclusions to UID0003VT/VU/VV/VW without their own evidence.
- **Manual coverage disposition:** M01-M05 authoritative application state comes from current manual-row readback and supervisor records; B005 never edits coverage files.
- **Manual no-op disposition:** N01-N02 authoritative no-op state comes from current manual-row readback and supervisor records.
- [x] Reinvestigated failed F1 readback with fresh read-only MCP session `b3b2bf88`, current tool schemas, exact target/callee disassembly, current restored prestate, direct IDB hash, and UID0001LX modeled positive control.
- [x] Proved exact machine-stack balance and rejected callee-type changes, direct frame/local/operand mutations, and destructive range redefinition with itemized safety/tool-contract reasons.
- [x] Narrowed F1/T1 durable readback, added F1L and C067, and removed the unachievable Hex-Rays/local-variable rendering promise without changing any accepted source or ordinary callback fact.
- **IDA action disposition:** narrowed durable F1/A1-A3/T1 and F1L are supervisor-owned; authoritative application state comes from live IDB readback, saved-IDB identity, and the supervisor IDA catalog.
- **IDA protection disposition:** P1-P8/C062, backup/save/hash evidence, analyzer diagnostics, and absence of unauthorized stack/local mutation are supervisor-owned readback facts; positive-SP/minimal-frame/placeholders alone are not rollback conditions.
- [x] Source placement/header topology verified in ordinary documents: SpellSlot declaration routes to `SpellInputPanes.h`, CharInputPane declaration routes to `InputPanes.h`, and definitions route to paired CPP files. Generated-file readback remains supervisor-owned C063-C064.
- [x] Exact formal CPP/H payloads were copied into formal channels, not prose/example side sections.
- [x] Third-party import confirmed not applicable; no `third_party_embeds` directive was introduced.
- [x] All ordinary score blockers/open questions remain closed or explicitly evidence-capped below 95.
- [x] Ran all seven listed scoped validators serially with `--no-generated-refresh`; recorded command IDs/timestamps/exit/ok/diagnostics/side effects.
- [x] Recomputed exact SHA256/bytes/lines for every changed ordinary doc; final report identity is recomputed after its terminal write and returned in the B005 handoff because embedding it would change that identity.
- [x] Updated C001-C049 ledger states only after destination-level verification; preserved supervisor-owned C050-C064 and workflow C065-C066 states, then added supervisor-owned C067 for the exact analyzer/no-mutation disposition without claiming completion.
- **Generated disposition:** SpellInputPanes.cpp/.h and InputPanes.cpp/.h topology plus moving tracker state are authoritative from current validator command metadata, generated headers, and generated readback; B005 does not perform or claim the supervisor-owned refresh lifecycle.
- [x] Confirmed no generated, tracker, stats, coverage, audit, catalog, lifecycle, goal, or notes file was manually edited by B005.
- [x] Confirmed no IDA mutation/save and no report validator/lifecycle/execute command was performed by B005 during this callback.
- [x] Confirmed report body remains lifecycle-neutral across validator-controlled movement.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000020544","destination_path":"executed-b-agent-research/B005/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md","timestamp":"2026-08-01T05:48:00-04:00","uid":"0003VX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
