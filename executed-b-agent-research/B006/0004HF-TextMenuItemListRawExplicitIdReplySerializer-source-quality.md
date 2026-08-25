# 0004HF TextMenuItemList Raw Explicit-Id Reply Serializer Source-Quality Research
** TARGET-REPORT-UID:0004HF **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

Project context: this report supports local preservation and behaviorally faithful source reconstruction of the unsupported NexusTK client.

## Finalized Report / Current Recommendation

- The accepted ordinary implementation now models [UID:0004HF] as retained private source method `void TextMenuItemList::SendTextMenuReply(unsigned short itemId)` rather than a blank-emitter raw/no-route page.
- Target metadata is now `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000ET`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000ET`; the exact definition is in the target CPP channel and H remains blank because [UID:0000ET] owns the class declaration.
- [UID:0004HE] now emits the compact selected-row wrapper that calls the explicit-id helper. Its compiler-observed full serialization is documented as the helper's inlined body; the live UID0004HC expansion is documented as the transitive inline result of the action handler calling UID0004HE.
- [UID:0000ET] remains in [UID:0000OP] `TextMenuDialogs.cpp` with the private helper declaration; [UID:0000ES] retains its narrow `friend class TextMenuItemList` relation, and UID0004HC retains its source-level `SendSelectedTextMenuReply()` call.
- Recommend only deterministic address/function-comment IDA updates. Do not define or type the raw target under this report: no target-specific disposable-copy result establishes the exact generated frame/type poststate, while comment-only actions preserve the current raw item model and still record the recovered source role.
- Execution, Gate status, manual coverage application, IDA mutation, report execution, and archive state are external dynamic supervisor/validator authority.

## Supporting Research

- Dated primary evidence receipt (2026-08-15): public IDA MCP session `b002_uid0000hq_rollback_20260815` against canonical database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` returned `server_health.status:ok`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready with 2,068 entries.
- Public schema-1 `runtime_attestation` returned top-level `ok:true`, no errors, listener endpoint `127.0.0.1:13337`, active worker route `127.0.0.1:62860`, and exact matching canonical session/path. This is dated read-only provenance, not future mutation authority.
- `survey_binary` identified a 32-bit image, `.text [0x00401000,0x0060d000)`, image SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, and canonical IDB path above.
- B005 UID0004HE, B006 UID0004HB, B009 UID0001BN, and B012 UID0000ET reports were used as historical leads only. Every decisive target range, byte, hash, instruction, route, item, comment, type, support, and generated-output claim was rechecked against current evidence.
- One over-broad full-image operand scan timed out. Both MCP processes remained alive/listening, a later health call returned immediately, and no mutation was involved. The route conclusion instead uses complete 73-head `xrefs_to`, all-image exact VA/RVA/raw-offset byte searches, and the unique current target signature; no fallback-only claim is used.
- Dated authoring receipt: this report-only pass changed no ordinary by-* page, coverage report, generated file, tracker, validator state, audit/lifecycle file, goal/notes file, or IDA database.

## Target

- Primary target: [UID:0004HF] `by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md`.
- Additional target UIDs: none. UID0004HE, UID0004HC, UID0000ET, UID0000ES, UID0000OP, and UID0001BN are support destinations, not additional report-coverage claims.
- Exact body: half-open `[0x00519720,0x0051983a)`, `0x11a` / 282 bytes.
- Assignment-time metadata was `86/91`, owner `0000ET`, reconstructable `TRUE`, blank emitter, blank CPP, and blank H. Applied current metadata is `93/94`, owner/emitter `0000ET`, reconstructable `TRUE`, nonblank CPP, and blank H.
- Assignment question: resolve the raw/no-route/blank-emitter state, exact serializer behavior, source factoring, owner/emitter/source order, formal source, scores, support effects, and safe IDA disposition.

## Current Target State

- Assignment-time target snapshot was SHA256 `BAC9E131BE6C0CE3FB5E48F0D7FDC18AADC9157654916BE411B4EF7C3D1DAEA5`, 2,376 bytes, 38 physical lines. Applied current target is SHA256 `0EEF03252E7CCD43577DF21BB60D02200EFB4B234956EFAC99ED1BCD52071E50`, 15,678 bytes, 152 physical lines.
- The current page records the complete report-level opcode `0x39` contract, list receiver fields, explicit word argument, optional owner string, range guard, send route, exact neighboring padding/hashes, exhaustive zero-route evidence, source factoring, ownership, score rationale, formal source, and corrected history.
- The assignment-time conclusion that source emission would necessarily invent a call site or duplicate logic is retained only as superseded history. Current documentation uses the retained private overload whose body is inlined into UID0004HE and then transitively into live UID0004HC.
- Current IDA state: address `0x00519720` is code but not a function; entry name/type/AR/AP are absent and FR/FP are not applicable. The 73 instruction heads have zero external inbound xrefs.
- Current sibling state: UID0004HE is modeled as `TextMenuItemList__SendSelectedTextMenuReply`, typed `void __thiscall(TextMenuItemList *this)`, and documented/emitted as the retained wrapper. UID0004HC remains the modeled vtable-routed action handler with unchanged formal CPP.
- Validator command `000000024224` generated current `TextMenuDialogs.cpp` with both UID0000ET declarations, compact UID0004HE at lines 145-154, UID0004HF once at lines 157-178, helper-before-forwarder order, and the UID0004HC wrapper call. Current `TextMenuDialogs.h` remains 47 lines and contains only the sufficient `friend class TextMenuItemList;` relation for this package.

## Executive Recommendation

- Treat the retained target bytes as source-authored application code, not compiler glue or a dead documentation-only artifact.
- Preserve the applied private helper `SendTextMenuReply(unsigned short itemId)` route through UID0000ET to `TextMenuDialogs.cpp`.
- Preserve UID0004HE's compact wrapper call and UID0004HF's exact full serializer definition.
- Preserve all compiler-only stack-cookie, range-failure, raw stack-offset, and unused `GetMemoryMan` artifacts outside the human source.
- Keep the raw target unmodeled in IDA unless a future supervisor obtains target-specific deterministic function-definition/frame proof. Apply the safe comment subset now when separately authorized.

## Supervisor Active Recheck

- At assignment selection, the exact target had no other active assignment/lease and no direct/additional report in the current research tracker; this dated queue fact confers no continuing lifecycle authority.
- The target's physical body, padding, all-head xrefs, pointer encodings, unique signature, current item/comment state, sibling function state, class/file route, manual coverage state, and generated output were all re-read.
- No split, merge, new UID, new source file, or new header is required.
- The complete ordinary implementation package has been applied to one primary page and six ordinary supports. Supervisor-owned manual coverage and IDA closure remain outside B006's applied allocation; generated readback is complete.
- No unresolved "investigate later" item remains. The only deliberately unperformed action is an unsafe IDA function/type mutation whose exact poststate is not proven; the safe address-comment disposition is complete and does not block source reconstruction.

## Inference Research Guidance Check

- Binary facts, documentation facts, and inference are separated. Addresses, bytes, hashes, instructions, fields, calls, xrefs, padding, ABI cleanup, and current item state are direct facts.
- The exact original lexical spelling and private/public token are not preserved. `SendTextMenuReply(unsigned short itemId)` is the strongest human-source inference because B012 independently proposed it, existing class vocabulary uses `SendSelectedTextMenuReply`, and the body is the explicit-id overload of that operation.
- The source-factor inference is stronger than generic similarity: all nine packet/send stages align in the same order across UID0004HF, UID0004HE, and UID0004HC, while UID0004HE adds only selected-row lookup before the shared serializer.
- Runtime behavior remains exact: same item id, packet order, optional string, guard, terminator, send length, and close behavior. The source is written as plausible mid-2000s C++ rather than IDA-shaped pseudocode.
- Stale Wave2/Wave3 language was ignored and supplies no authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Does zero direct xrefs make the target dead? | The linker retained a complete nonvirtual source-shaped member body; UID0004HE repeats its entire serializer after selected-row lookup, and live UID0004HC repeats that combined path under a vtable route. MSVC already demonstrably inlined UID0004HE while retaining its standalone copy. | No. Zero direct routes describe the retained copy, not source absence. |
| Is UID0004HF an overload or unrelated duplicate? | Same receiver fields `+0x14c/+0x150/+0x154`, same opcode and writer order, same owner-string branch, same guard/terminator/send, but UID0004HF reads `[ebp+8]` and returns with `retn 4`. | Private explicit-id overload/helper. |
| How did UID0004HE likely use it? | UID0004HE adds selected-index guard and `GetItem`, then uses the selected row word in the same serializer stage sequence. | Source wrapper obtains `entry->itemId` and calls `SendTextMenuReply(itemId)`; helper was inlined. |
| How does UID0004HC relate? | Live region `[0x0051938f,0x00519492)` repeats selected lookup plus all serializer stages and is reached through vtable cell `0x0061ecf4 -> 0x00519210`. | Transitive inline expansion of `OnDialogAction -> SendSelectedTextMenuReply -> SendTextMenuReply`. |
| Exact signature/access? | ECX receiver, zero-extended word `[ebp+8]`, `retn 4`, no virtual-table pointer to target, and no external source caller. | `void TextMenuItemList::SendTextMenuReply(unsigned short itemId)`, private. |
| Exact range? | Own prologue/cookie/normal `retn 4` plus range-failure tail; three leading and six trailing CC bytes; unique signature. | Preserve `[0x00519720,0x0051983a)` only. |
| Packet length semantics? | Cursor advances 1+1+4+2, optional string writer may extend it, guard compares `<0x100`, local zero is written at `packet[cursor]`, and pre-terminator cursor is sent. | Reconstruct exactly; the terminator is not counted in sent length. |
| Should source include `GetMemoryMan` or cookie/range helper calls? | These are compiler/runtime artifacts around a fixed local packet buffer; sibling accepted source omits them. | Exclude from developer source. |
| Should IDA define/type the raw body now? | Current read-only state has no function/frame; no target-specific disposable-copy result proves deterministic `define_func`/`set_type` poststate. The workflow requires the safe subset when poststate is not deterministic. | No function/type action. Use exact address comments and support-comment corrections only. |
| Does the target need its own H block/file? | UID0000ET's file-local class declaration already resides in the CPP root; target body routes as a child. | Target H remains blank; add private declaration to UID0000ET CPP class fragment. |
| Does any score blocker remain? | Behavior, range, owner, source route, factoring, name, formal source, support edits, coverage text, and safe IDA disposition are all resolved. | Raise target to 93/94; keep below final 95 because original symbols/direct call evidence are absent. |

Rejected alternatives:

- Keep blank solely because start xrefs are zero: rejected by retained compiler output and nested inline evidence.
- Put the serializer in `TextMenuDialog`: rejected by ECX receiver fields and physical TextMenuItemList cluster.
- Put it in `ListPane`, PacketBuffer, or Socket: rejected because those dependencies do not own menu context or owner-dialog state.
- Reconstruct duplicate serialization in UID0004HE and UID0004HF: behaviorally possible but weaker as original-source recovery; it fails to explain the exact nested inline family as cleanly.
- Create `TextMenuItemList.cpp` or a new header: rejected by both constructor callers, existing file route, and current generated private-class layout.
- Preserve `sub_519720`, `_DWORD`, raw offsets, or `arg_0` in final source: rejected as reverse-engineering residue.

## Evidence Standards Used

- Direct binary evidence: current public MCP bytes, instruction heads, disassembly, item boundaries, exact xrefs, comments, types, function analyses, pointer-pattern searches, and unique signature.
- Direct documentation evidence: current target/support metadata, formal CPP/H, generated source, manual coverage, tracker, by-structure, and by-memory guidance.
- Corroborating evidence: prior accepted B-agent reports, used only after current revalidation.
- Negative evidence: zero external inbound xrefs across all 73 heads, zero VA/RVA/raw-offset encodings, no vtable cell, no symbol, no standalone source caller, and absent target IDA function model.
- Inference standard: prefer the source structure that explains all retained and inlined copies with the fewest handwritten duplicates while preserving exact execution.

## Evidence Checked

### Live IDA MCP

- `idb_list`, `server_health`, `runtime_attestation`, and `survey_binary` for canonical session/database identity. A fresh `2026-08-15T11:56:50Z` schema-1 attestation returned `ok:true`, `errors:[]`, and the exact canonical path for session `b002_uid0000hq_rollback_20260815`.
- `lookup_funcs` at `0x00519210`, `0x005195f0`, `0x00519720`, `0x00519839`, `0x0051983a`, and `0x00519840`.
- `inspect_items` at both boundaries, all planned comment addresses, UID0004HE entry, UID0004HC inline start, and `g_packetSender`.
- `get_bytes` for leading padding, the full body in two bounded regions, trailing padding, and planned comment items.
- Current public endpoint schemas were reread: `set_address_comments`, `set_address_repeatable_comments`, and `set_function_comments` each require top-level `database` plus `items:{addr,comment}` and mutate only their named comment channel.
- `insn_query` for the exact target range: 73 instruction heads, no truncation.
- `xrefs_to` for every instruction head and `xref_query` for all planned action addresses.
- `find_bytes` for little-endian target VA `20 97 51 00`, RVA `20 97 11 00`, raw file offset `20 8B 11 00`, and equivalent end forms; all returned zero matches.
- Local PE section readback established `.text` RVA `0x1000`, raw base `0x400`, and target raw file offset `0x118b20`.
- `make_signature_for_range` produced one unique wildcarded signature for `[0x00519720,0x0051983a)`.
- `analyze_function` and `disasm` for UID0004HE and UID0004HC, plus current stack frames/comments.
- `type_inspect` for `TextMenuItemList`, `TextMenuDialog`, and `Socket`; each exists as an incomplete named type.
- `inspect_items`, `get_global_value`, and `get_comments` for `g_packetSender` at `0x0067a7ec`.

### Documentation and generated artifacts

- Assignment-time primary target SHA256 was `BAC9E131BE6C0CE3FB5E48F0D7FDC18AADC9157654916BE411B4EF7C3D1DAEA5`; applied current SHA256 is `0EEF03252E7CCD43577DF21BB60D02200EFB4B234956EFAC99ED1BCD52071E50` (15,678 bytes, 152 lines).
- UID0004HE assignment-time SHA256 was `6DAB2485E0BB49D71BF96F0EFF43A7B0C42C2D84D05BB5555D57060A66A18CDD`; applied current SHA256 is `C55A4D03FD39441472C1921F305C57BD2ACEB02C19B7EF6644E786B312B26BD0` (12,092 bytes, 109 lines).
- UID0004HC assignment-time SHA256 was `4C28C641A86877EE9020F7EECD174C1492E6DDEC8794DD3680C9686FC4B392CD`; applied current SHA256 is `6521106D2E3EFDEDFA16E194A1D4406322933CFBF95778E08F14D537F587F508` (7,706 bytes, 96 lines).
- UID0000ET assignment-time SHA256 was `15ABF57395AC80F52E65954C55A56BDE70DF231BB2045AB68D26E558DD1EDDB3`; applied current SHA256 is `C10A876F6D41DA1637F5A550B7E427333CA980A7BDE6D78A94BF596C0891ADB2` (30,372 bytes, 270 lines).
- UID0000ES assignment-time SHA256 was `B2DA45BB0934EA4C358C8A53C4EA53347DDD55361D6DFA63E059531D8EDC231A`; applied current SHA256 is `6AA2DB4D0A56C76E36F59EDB9F9B9A59D2A1ED74365020CD2A001D776EC7B93C` (17,235 bytes, 141 lines).
- UID0000OP assignment-time SHA256 was `52FF662378E43131789FAD540B49E85392B173E4BEC5408F0C1F0EC7A75019C8`; applied current SHA256 is `4CADFFE9E63B7A0E91F945D8F032A2DF99F22B18CAD6A88445E5B0B8B650A059` (34,498 bytes, 187 lines).
- UID0001BN assignment-time SHA256 was `13ECB6F489514ED4345C45D94CE4CA105B90966235C77DF63E63D9C2C15E4FE3`; applied current SHA256 is `C78E27CE818BA1811BAFFC71EE0FF8D74F9A61037E262932EA7638EE6EB0B28E` (33,104 bytes, 182 lines).
- Current generated `TextMenuDialogs.cpp`: SHA256 `A48D91B801C73A9CEBDD46DD407D65DDD9F14CD0F81269D86DA6CCF675291F4F`, 19,094 bytes, 611 lines.
- Current generated `TextMenuDialogs.h`: SHA256 `54C4B6359B752E1C56469365A0F15E19FDFEA1759931E11C254041B2C9B924DB`, 1,632 bytes, 47 lines.
- Current generated receipt: owning-file validator command `000000024224`, timestamp `2026-08-15T08:27:59-04:00`, `ok:1`, generated refresh completed. Earlier command `000000024196` and hashes `24B706...` / `F5C0CD...` remain dated pre-implementation snapshots with no continuing authority.
- Supervisor-owned manual coverage remains unapplied: by-memory lacks UID0004HF and retains stale UID0001BN text; class coverage retains stale UID0000ET text. The refreshed tracker now reads UID0004HF `93/94`, UID0000ET `93/93`, and UID0001BN `92/93`; tracker state supplies no report lifecycle authority.

### Failed or skipped checks

- One unbounded-style full-image operand scan timed out and is rejected as evidence. Listener and worker remained alive/listening and current health recovered before research continued.
- No mutation endpoint, validator, lifecycle command, or fallback-only analysis was used.
- Original PDB/source-control symbols are unavailable. This limits exact spelling proof but does not leave behavior, ownership, source placement, or source shape unresolved.

## Claim And Incorporation Ledger

Applied ordinary/generated allocation: C4HF-001..037 are verified `applied` or `already-present`; supervisor-owned coverage, IDA/protected-state, and closure claims C4HF-038..050 remain proposed. Row order and all eight fields have an exact checklist twin.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C4HF-001 | 0004HF | Preserve exact body `[0x00519720,0x0051983a)`, 282 bytes, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`; preserve three-byte lead and six-byte trail padding. | Certain | Current MCP bytes/hashes/items. | UID0004HF Exact Range, Boundaries, Identity | incorporate | applied |
| C4HF-002 | 0004HF | Preserve the complete 73-head external inbound-xref union as count zero, exact set `{}`. | Certain | Current all-head `xrefs_to`. | UID0004HF Negative Route Evidence | incorporate | applied |
| C4HF-003 | 0004HF | Preserve zero target VA/RVA/raw-offset pointer encodings and zero end-address encodings. | Certain | Current all-image `find_bytes`; PE mapping. | UID0004HF Negative Route Evidence | incorporate | applied |
| C4HF-004 | 0004HF | Record the target wildcarded byte signature as unique in the current IDB. | Strong | Current `make_signature_for_range`. | UID0004HF Exact Range And Identity | incorporate | applied |
| C4HF-005 | 0004HF | Record ABI as receiver in ECX, one unsigned-short logical stack argument at `[ebp+8]`, `retn 4`, 0x108 local allocation, saved ESI, and security cookie. | Certain | Exact current disassembly. | UID0004HF ABI And Compiler Shape | incorporate | applied |
| C4HF-006 | 0004HF | Packet byte zero is opcode `0x39`. | Certain | Call at `0x0051974e`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-007 | 0004HF | Packet byte one is `m_menuType` from receiver `+0x14c`. | Certain | Instructions `0x00519769-0x00519771`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-008 | 0004HF | Packet bytes two through five are big-endian `m_menuId` from receiver `+0x150`. | Certain | Instructions `0x0051978c-0x00519792`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-009 | 0004HF | Packet bytes six and seven are the explicit unsigned-short `itemId` argument in big-endian order. | Certain | `[ebp+8]` zero-extension, writer call, `retn 4`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-010 | 0004HF | Receiver `+0x154` is non-owning `m_ownerDialog`. | Certain | Instruction `0x005197c2` and class layout. | UID0004HF Fields/Ownership/formal CPP | incorporate | applied |
| C4HF-011 | 0004HF | Owner byte `+0x279` gates ANSI length-8 append of owner `m_extraString` at `+0x27c`. | Certain | Branch/helper sequence `0x005197d2-0x00519800`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-012 | 0004HF | Preserve `<0x100` cursor guard and compiler range-failure tail at `0x00519835`. | Certain | `cmp/jnb` and exact tail. | UID0004HF Packet/Compiler Shape | incorporate | applied |
| C4HF-013 | 0004HF | Preserve local `packet[cursor]=0` after the guard and exclude that zero from transmitted length. | Certain | `0x00519810-0x00519820`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-014 | 0004HF | Send through `g_packetSender`/`QueueAndSendPacket` with pre-terminator cursor cast to short. | Certain | Global/call type and send sequence. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| C4HF-015 | 0004HF | Exclude `GetMemoryMan`, stack cookie, raw stack offsets, and explicit range-failure call from human source. | Very strong | Compiler pattern and accepted siblings. | UID0004HF Compiler Artifacts/CPP rationale | reject-stale | applied |
| C4HF-016 | 0004HE | UID0004HE adds selected-index guard/GetItem then repeats UID0004HF's full serializer stages. | Certain | Current HE disassembly/decompile stage map. | UID0004HF Relation; UID0004HE Source Factoring | incorporate | applied |
| C4HF-017 | 0004HC | Live UID0004HC region `[0x0051938f,0x00519492)` repeats selected lookup plus all serializer stages under vtable route `0x0061ecf4`. | Certain | Current action analysis/xref. | UID0004HF Liveness; UID0004HC Evidence | incorporate | applied |
| C4HF-018 | 0004HF | Reconstruct the source as nested calls `OnDialogAction -> SendSelectedTextMenuReply -> SendTextMenuReply(itemId)` with compiler inlining explaining the three copies. | Very strong | Exact stage alignment and retained copies. | UID0004HF Source Factoring; support docs | incorporate | applied |
| C4HF-019 | 0004HF | Use human source name/signature `void TextMenuItemList::SendTextMenuReply(unsigned short itemId)` and private access. | Strong | ABI, class vocabulary, B012 independent inference. | UID0004HF formal CPP; UID0000ET declaration | incorporate | applied |
| C4HF-020 | 0004HF | Keep canonical owner UID0000ET TextMenuItemList. | Certain | Receiver fields, physical cluster, class inventory. | UID0004HF metadata/Ownership | already-present | already-present |
| C4HF-021 | 0004HF | Keep source placement in UID0000OP TextMenuDialogs.cpp after UID0004HE and before `ForwardOwnerSelectionState`. | Very strong | Physical/source order and current emitter route. | UID0004HF Source Placement; UID0000OP | incorporate | applied |
| C4HF-022 | 0004HF | Set `EMITTER_UIDS:0000ET`; no standalone file/header route. | Certain | UID0000ET -> UID0000OP chain. | UID0004HF metadata | incorporate | applied |
| C4HF-023 | 0004HF | Raise target score from 86/91 to 93/94. | Strong | All behavior/source blockers resolved; lexical/direct-route limits retained. | UID0004HF metadata/Score Rationale | incorporate | applied |
| C4HF-024 | 0004HF | Insert the exact private explicit-id serializer definition in the target CPP channel. | Very strong | Exact packet semantics and source factoring. | UID0004HF RECONSTRUCTION_CPP CODE | incorporate | applied |
| C4HF-025 | 0004HF | Keep target H blank because declaration ownership is UID0000ET's file-local class fragment. | Certain | Current channel routing. | UID0004HF RECONSTRUCTION_H CODE | already-present | already-present |
| C4HF-026 | 0000ET | Add private declaration `void SendTextMenuReply(unsigned short itemId);`. | Very strong | Recovered helper/source access. | UID0000ET formal CPP class declaration | incorporate | applied |
| C4HF-027 | 0004HE | Replace duplicated UID0004HE serializer source with selected lookup plus `SendTextMenuReply(entry->itemId)`. | Very strong | Nested inline evidence. | UID0004HE RECONSTRUCTION_CPP CODE | incorporate | applied |
| C4HF-028 | 0004HE | Keep UID0004HE metadata 93/94, owner/emitter, and blank H unchanged. | Strong | Behavior/source role remains complete. | UID0004HE metadata | already-present | already-present |
| C4HF-029 | 0004HC | Keep UID0004HC formal CPP/metadata unchanged; update prose to identify transitive nested inlining. | Very strong | Existing source call is correct. | UID0004HC Evidence/Changes | incorporate | applied |
| C4HF-030 | 0000ES | Preserve current friend declaration and formal source; replace prose saying UID0004HF is unresolved. | Very strong | Existing access route already sufficient. | UID0000ES Relation/Changes | incorporate | applied |
| C4HF-031 | 0000ET | Raise class score 91/91 to 93/93 and replace every unresolved/no-code UID0004HF statement. | Strong | Last raw serializer blocker resolved; other class name caps remain. | UID0000ET metadata/Status/Method Map/Changes | incorporate | applied |
| C4HF-032 | 0000OP | Keep by-file score 90/86; update method inventory, source factoring/order, generated expectations, and history. | Strong | Target resolves one child but broad module caveats remain. | UID0000OP TextMenuItemList sections | incorporate | applied |
| C4HF-033 | 0001BN | Raise aggregate 90/92 to 92/93 and replace independently unresolved UID0004HF text with resolved retained helper/factoring. | Strong | Explicit named aggregate blocker removed; broad caveats remain. | UID0001BN metadata/range map/evidence/history | incorporate | applied |
| C4HF-034 | 0000ET | Expected generated class declaration contains both `SendSelectedTextMenuReply()` and private `SendTextMenuReply(unsigned short)`. | Very strong | Formal emitter route. | Generated TextMenuDialogs.cpp readback checklist | incorporate | applied |
| C4HF-035 | 0004HE | Expected generated UID0004HE body performs only guard/GetItem/helper call at source level. | Very strong | Accepted source factoring. | Generated TextMenuDialogs.cpp readback checklist | incorporate | applied |
| C4HF-036 | 0004HF | Expected generated UID0004HF definition appears once after UID0004HE and before `ForwardOwnerSelectionState`. | Certain | Child order and emitter marker. | Generated TextMenuDialogs.cpp readback checklist | incorporate | applied |
| C4HF-037 | 0000OP | Generated TextMenuDialogs.h remains unchanged; no TextMenuItemList declaration belongs there. | Very strong | Private class stays in CPP; existing friend is sufficient. | Generated TextMenuDialogs.h readback checklist | already-present | already-present |
| C4HF-038 | 0004HF | Insert exact new by-memory manual coverage row at 93% very-strong after UID0004HE. | Certain | Current row absent and address order. | by-memory/-coverage-report.md | incorporate | proposed |
| C4HF-039 | 0001BN | Replace aggregate manual coverage row with 92% very-strong resolved-helper text. | Certain | Proposed aggregate score/content. | by-memory/-coverage-report.md | incorporate | proposed |
| C4HF-040 | 0000ET | Replace class manual coverage row with 93% very-strong resolved two-helper text. | Certain | Proposed class score/content. | by-class/-coverage-report.md | incorporate | proposed |
| C4HF-041 | 0004HF | Add exact repeatable address comment at raw entry `0x00519720`; keep raw item/function state unchanged. | Very strong | Exact item/comment/xref prestate. | Supervisor Gate 2B IDA A01 | incorporate | proposed |
| C4HF-042 | 0004HF | Add exact regular address comment for `m_menuType` at `0x00519769`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A02 | incorporate | proposed |
| C4HF-043 | 0004HF | Add exact regular address comment for `m_menuId` at `0x0051978c`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A03 | incorporate | proposed |
| C4HF-044 | 0004HF | Add exact regular address comment for explicit `itemId` at `0x005197af`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A04 | incorporate | proposed |
| C4HF-045 | 0004HF | Add exact regular address comment for owner/optional-string path at `0x005197c2`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A05 | incorporate | proposed |
| C4HF-046 | 0004HF | Add exact regular address comment for guard/terminator/send semantics at `0x00519811`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A06 | incorporate | proposed |
| C4HF-047 | 0004HE | Replace UID0004HE function-regular comment with exact nested-helper factoring text only. | Very strong | Current modeled function/state. | Supervisor Gate 2B IDA A07 | incorporate | proposed |
| C4HF-048 | 0004HC | Replace `0x0051938f` regular comment with exact transitive-inline text only. | Very strong | Current inline item/comment/state. | Supervisor Gate 2B IDA A08 | incorporate | proposed |
| C4HF-049 | 0004HF | Do not define, rename, or type the raw target and do not edit stack state; no deterministic target-specific poststate proof exists. | Certain | Current no-function state and workflow safe-subset rule. | Supervisor Gate 2B protected-state contract | not-applicable | proposed |
| C4HF-050 | 0004HF | Supervisor must apply manual coverage, scoped-validate every changed ordinary page and coverage report, refresh generated output/tracker, verify CPP/H physically, perform Gate 2B separately, and exclusively own report execution/archive. | Certain | Workflow actor boundaries. | Validator/coverage/generated/lifecycle checklist | incorporate | proposed |

## Positive Evidence Summary

- Complete 282-byte ordinary thiscall-shaped body with one logical word argument, application-specific fields, packet protocol, sender global, normal return, and compiler range-failure tail.
- Exact current body hash and unique wildcarded signature.
- Exact same packet stage sequence in UID0004HE after selected-row lookup.
- Exact same selected-plus-serializer sequence in live UID0004HC, whose function is reached through vtable cell `0x0061ecf4`.
- Physical placement inside the TextMenuItemList method cluster between retained UID0004HE and a list virtual.
- Existing TextMenuItemList fields and TextMenuDialog friend relation already support the source without invented accessors.
- A simple private helper call explains all three compiler copies and produces cleaner, more plausible original source than handwritten duplication.

## IDA MCP Facts

- Canonical dated session: `b002_uid0000hq_rollback_20260815`; canonical database: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Target is not a function. Entry item `[0x00519720,0x00519721)` is one code byte `55`; name/type/AR/AP absent; FR/FP not applicable.
- Exact body is 282 bytes, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`.
- Leading `[0x0051971d,0x00519720)` is three CC bytes, SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`.
- Trailing `[0x0051983a,0x00519840)` is six CC bytes, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`.
- Target has 73 instruction heads and zero external inbound xrefs across all heads.
- No exact VA, RVA, raw-offset, or end-address byte pattern occurs anywhere in the IDB.
- Target direct callees in order: `GetMemoryMan`, `PacketBufferWriteUInt8` twice, `PacketBufferWriteUInt32BE`, `PacketBufferWriteUInt16BE`, `sub_584540`, `sub_5757D0`, `Socket_QueueAndSendPacket`, `__security_check_cookie`, and `__report_rangecheckfailure`.
- UID0004HE is currently function `TextMenuItemList__SendSelectedTextMenuReply`, size `0x12d`, type `void __thiscall(TextMenuItemList *this)`, zero callers, and exact body SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`.
- UID0004HC is function `sub_519210`, size `0x2a1`, type `void __userpurge(int@<ecx>, int@<ebx>, int, int)`, with sole inbound data xref `0x0061ecf4`.
- `g_packetSender` is `[0x0067a7ec,0x0067a7f0)`, name `g_packetSender`, type `Socket *`, value zero, regular comment present, repeatable absent.

## Function / Child Inventory

| Range / item | UID / owner | Role | Modeled | Source disposition |
| --- | --- | --- | --- | --- |
| `[0x0051938f,0x00519492)` inside UID0004HC | UID0000ES | live selected-row plus serializer inline expansion | inside modeled vtable function | compiler-covered by nested source calls |
| `[0x005195f0,0x0051971d)` | UID0004HE / UID0000ET | retained selected-row wrapper | modeled now | emits selected lookup plus helper call |
| `[0x0051971d,0x00519720)` | ignored padding | three CC bytes | data/alignment | preserve, no source |
| `[0x00519720,0x0051983a)` | UID0004HF / UID0000ET | retained explicit-id serializer | raw code, no function | emit private source helper |
| `[0x0051983a,0x00519840)` | ignored padding | six CC bytes | data/alignment | preserve, no source |
| `[0x00519840,0x0051984b)` | UID0000ET | `ForwardOwnerSelectionState` virtual | modeled | unchanged support |
| `0x0061ed48` vtable family | UID00031Y / UID0000ET | list virtual routing | data | excludes UID0004HE/UID0004HF; unchanged |

Inventory totals: two retained source methods, one live transitive inline expansion, two alignment ranges, one adjacent virtual, and one vtable support family. No new child or split is required.

## Direct Xref / Caller Inventory

| Address / stage | Exact route | Meaning |
| --- | --- | --- |
| `0x00519720` | inbound external set `{}` | retained target copy has no direct call/jump/data route |
| all 73 target heads | external union `{}` | no hidden interior entry |
| target VA/RVA/raw offset | pattern sets `{}` | no pointer/immediate/table encoding |
| `0x00519736` | call `0x00516030` | compiler/runtime setup; return unused |
| `0x0051974e` | call `0x00575380` | append opcode `0x39` |
| `0x00519771` | call `0x00575380` | append menu type |
| `0x00519792` | call `0x005753f0` | append big-endian menu id |
| `0x005197b4` | call `0x005753a0` | append big-endian explicit item id |
| `0x005197ef/0x005197f5` | calls `0x00584540/0x005757d0` | owner string data and ANSI string append |
| `0x00519820` | call `0x00574bb0` | packet send |
| `0x0051982a/0x00519835` | cookie/range-failure calls | compiler instrumentation |
| `0x005195f0` | caller set `{}` | retained selected wrapper copy |
| `0x0061ecf4 -> 0x00519210` | one data xref | live virtual handler route |

## Documentation Evidence And IDA Status

- UID0004HF's assignment-time no-code conclusion was reasonable before UID0004HE's exact inline analysis, but it is retained only as corrected historical reasoning.
- UID0004HE's earlier accepted report explicitly left UID0004HF for this independent pass and recorded the target's exact hash, ABI, no-function state, padding, and zero pointer routes; the current wrapper documentation preserves those facts while applying the resolved nested source boundary.
- UID0000ET now carries the private helper declaration, accepted name, source order, and current 93/93 metadata; former "if routed later" language is historicalized.
- UID0000OP and UID0001BN now identify UID0004HF as the resolved retained helper rather than a current class-range blocker.
- Current generated output proves the complete emitter chain and private class placement: compact UID0004HE, one UID0004HF definition in source order, both class declarations, and unchanged header ownership.
- Current IDA has enough type vocabulary for human comments, but the raw target still lacks a function/frame model. This report does not convert a source conclusion into an unsafe IDA type operation.

## Ranked Ownership Analysis

### 1. UID0000ET TextMenuItemList

- For: ECX receiver uses list fields `+0x14c/+0x150/+0x154`; physical cluster, sibling method, class inventory, constructor route, and source order agree.
- Against: no direct retained-copy caller and no original symbol.
- Decision: exact canonical owner and emitter.

### 2. UID0000ES TextMenuDialog

- For: owns the optional string fields and the live handler.
- Against: target receiver and primary context fields are TextMenuItemList; dialog only supplies back-reference state.
- Decision: support/friend/caller owner, not target owner.

### 3. UID0000OP TextMenuDialogs

- For: exact compilation-unit root and final generated destination.
- Against: broader than direct semantic owner.
- Decision: final file route through UID0000ET, not direct target owner.

### 4. ListPane / PacketBuffer / Socket

- For: inherited selection, serialization, and transport dependencies.
- Against: none owns the menu context, explicit id operation, or owner pointer.
- Decision: reject as owner/source location.

No new file or grouping is applicable.

## Source Placement

- Declaration: private section of UID0000ET `TextMenuItemList` class fragment, before private data fields.
- Definitions in physical/source order: constructor, `AddTextEntry`, UID0004HE `SendSelectedTextMenuReply`, UID0004HF `SendTextMenuReply(unsigned short)`, `ForwardOwnerSelectionState`, and `DrawListItem`.
- UID0004HE remains before UID0004HF because its retained body address precedes the helper body; class declaration permits the call regardless of definition order.
- UID0000ET's `[[CHILDREN]]` marker already places both by-memory definitions before subsequent virtual methods.
- No `TextMenuItemList.cpp` or header is created.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is half-open `[0x00519720,0x0051983a)`, size `0x11a`.
- The normal path ends at `retn 4` at `0x00519832`; the range-failure tail begins at `0x00519835` and remains part of the function.
- Leading `[0x0051971d,0x00519720)` and trailing `[0x0051983a,0x00519840)` are alignment only.
- The target is not a slice of UID0004HE or `ForwardOwnerSelectionState`; it has a distinct prologue, cookie, ABI argument, return, and tail.
- No merge/split/new UID is needed. Reclassification is blank-emitter raw helper -> retained ordinary private source method.
- The two inline copies remain compiler-covered inside their existing byte owners and do not receive duplicate by-memory children.

## Negative Evidence Summary

- No direct call, jump, data xref, interior external entry, vtable slot, VA pointer, RVA pointer, raw-offset pointer, relocation-like xref, or original symbol reaches the target.
- No original symbol proves exact method/local names or access label.
- The target's standalone body is not modeled as an IDA function.
- No independent source caller survives outside the inferred inlined call chain.
- No target-specific disposable-copy action proves an exact deterministic function-definition/type/frame poststate.
- These negatives cap confidence below 95 and constrain IDA actions. They do not justify blank source because the retained body and two-stage inline family resolve source existence and behavior.

## IDA Rename / Type / Comment Recommendations

This is a structured, non-executable supervisor handoff. Each action binds to current public endpoint fields. `AR` is regular address comment, `AP` repeatable address comment, `FR` regular function comment, and `FP` repeatable function comment. Historical session identifiers are evidence only; `<fresh runtime-attested canonical session ID>` means the exact session selected by the supervisor immediately before Gate 2B after schema-1 `runtime_attestation` returns `ok:true`, `errors:[]`, and canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. No function definition, rename, `set_type`, stack edit, byte edit, boundary edit, or save is authorized.

| Action ID | Classification | Entity and complete literal prestate | Exact public endpoint delta and complete expected poststate | Evidence and hard safety constraints |
| --- | --- | --- | --- | --- |
| A01 | apply | Raw code item `[0x00519720,0x00519721)`, size `1`, bytes `55`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable; no function; inbound xref count/set `0/{}`; outgoing xref count/set `1/{0x00519721 code}`; enclosing body `[0x00519720,0x0051983a)`, size `0x11a`, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`. | Public request: `set_address_repeatable_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x00519720",comment:"Retained TextMenuItemList::SendTextMenuReply(unsigned short itemId) source helper; serializes opcode 0x39 from list context and is compiler-inlined into SendSelectedTextMenuReply and transitively into TextMenuDialog::OnDialogAction. No direct route reaches this retained copy."})`. Complete poststate: same raw item/range/size/byte/name/type/function state/xrefs/body hash; AR absent; AP equals that exact text; FR/FP not applicable. | Only AP may change. Stop on any function/name/type/AR/FR/FP/item/range/hash/xref/padding drift or endpoint error. |
| A02 | apply | Code item `[0x00519769,0x00519770)`, size `7`, bytes `0F B6 86 4C 01 00 00`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable; incoming xref count/set `1/{0x00519768 code}`; outgoing xref count/set `1/{0x00519770 code}`; enclosing body/range/size/hash exact as A01. | Public request: `set_address_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x00519769",comment:"Read TextMenuItemList::m_menuType at +0x14c for opcode 0x39 reply byte 1."})`. Complete poststate: same item/range/size/bytes/name/type/xrefs and enclosing body identity; AR equals that exact text; AP absent; FR/FP not applicable. | Only AR may change. Stop on any other channel, item, byte, range, hash, xref, or endpoint drift. |
| A03 | apply | Code item `[0x0051978c,0x00519792)`, size `6`, bytes `FF B6 50 01 00 00`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable; incoming xref count/set `1/{0x0051978b code}`; outgoing xref count/set `1/{0x00519792 code}`; enclosing body/range/size/hash exact as A01. | Public request: `set_address_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x0051978c",comment:"Read TextMenuItemList::m_menuId at +0x150 and append it as a big-endian 32-bit field."})`. Complete poststate: same item/range/size/bytes/name/type/xrefs and enclosing body identity; AR equals that exact text; AP absent; FR/FP not applicable. | Only AR may change. Stop on any other channel, item, byte, range, hash, xref, or endpoint drift. |
| A04 | apply | Code item `[0x005197af,0x005197b3)`, size `4`, bytes `0F B7 45 08`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable; incoming xref count/set `1/{0x005197ae code}`; outgoing xref count/set `1/{0x005197b3 code}`; enclosing body/range/size/hash exact as A01. | Public request: `set_address_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x005197af",comment:"Zero-extend the explicit unsigned short itemId argument at [ebp+8] before the big-endian 16-bit packet write."})`. Complete poststate: same item/range/size/bytes/name/type/xrefs and enclosing body identity; AR equals that exact text; AP absent; FR/FP not applicable. | Only AR may change. Do not create, rename, or type a stack argument; stop on any other delta or endpoint error. |
| A05 | apply | Code item `[0x005197c2,0x005197c8)`, size `6`, bytes `8B 8E 54 01 00 00`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable; incoming xref count/set `1/{0x005197bf code}`; outgoing xref count/set `1/{0x005197c8 code}`; enclosing body/range/size/hash exact as A01. | Public request: `set_address_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x005197c2",comment:"Load non-owning m_ownerDialog at +0x154; owner +0x279 gates ANSI length-8 m_extraString at +0x27c."})`. Complete poststate: same item/range/size/bytes/name/type/xrefs and enclosing body identity; AR equals that exact text; AP absent; FR/FP not applicable. | Only AR may change. Preserve owner/global/type state and stop on any other delta or endpoint error. |
| A06 | apply | Code item `[0x00519811,0x00519819)`, size `8`, bytes `C6 84 05 FC FE FF FF 00`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable; incoming xref count/set `1/{0x00519810 code}`; outgoing xref count/set `1/{0x00519819 code}`; enclosing body/range/size/hash exact as A01. | Public request: `set_address_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x00519811",comment:"After proving cursor < 0x100, write a local trailing zero; QueueAndSendPacket receives the pre-terminator cursor length."})`. Complete poststate: same item/range/size/bytes/name/type/xrefs and enclosing body identity; AR equals that exact text; AP absent; FR/FP not applicable. | Only AR may change. Preserve guard/send behavior and stop on any other delta or endpoint error. |
| A07 | apply | Function `[0x005195f0,0x0051971d)`, size `0x12d`, body SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; name `TextMenuItemList__SendSelectedTextMenuReply`; type `void __thiscall(TextMenuItemList *this)`; frame in exact order: `var_108/+0x4/0x4/_DWORD`, `destination/+0x8/0x1/unsigned __int8`, `var_103/+0x9/0x1/_BYTE`, `var_102/+0xa/0x2/unsigned __int8[2]`, `var_100/+0xc/0x4/_DWORD`, `var_FC/+0x10/0x4/_DWORD`, `var_4/+0x108/0x4/_DWORD`, `__saved_registers/+0x10c/0x4/_DWORD`, `__return_address/+0x110/0x4/_UNKNOWN *`; entry AR absent, AP absent, FR `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`, FP absent; start incoming xref count/set `0/{}`, start outgoing count/set `1/{0x005195f1 code}`, callers `{}`, and external inbound all-head count/set `0/{}`; callee set `{ListPane_GetItem, GetMemoryMan, PacketBufferWriteUInt8, PacketBufferWriteUInt32BE, PacketBufferWriteUInt16BE, sub_584540, sub_5757D0, Socket_QueueAndSendPacket, @__security_check_cookie@4, ___report_rangecheckfailure}`. | Public request: `set_function_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x005195f0",comment:"Retained TextMenuItemList::SendSelectedTextMenuReply() wrapper; obtains the selected row itemId and source-calls SendTextMenuReply(unsigned short), whose retained body at 0x00519720 is compiler-inlined here. The combined path is then compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No direct route reaches either retained copy."})`. Complete poststate: same function range/size/hash/name/type, exact nine frame rows/order, AR/AP/FP, xref/caller/callee sets, and all internal address comments; FR alone equals the new exact text. | Only FR may change. Preserve all internal AR/AP channels, especially existing semantic comments at `0x00519606`, `0x00519615`, `0x005196a6`, `0x005196f5`, and their neighboring argument labels; stop on any name/type/frame/body/xref/callee/other-comment or endpoint drift. |
| A08 | apply | Code item `[0x0051938f,0x00519395)`, size `6`, bytes `8B 83 34 01 00 00`, name absent, type absent, AR `Compiler-inlined TextMenuItemList::SendSelectedTextMenuReply() expansion: selected-index lookup and opcode 0x39 send; retained out-of-line body is 0x005195f0-0x0051971d.`, AP absent, FR not applicable, FP not applicable; incoming xref count/set `1/{0x00519389 code}`, outgoing xref count/set `1/{0x00519395 code}`. Containing function `[0x00519210,0x005194b1)`, size `0x2a1`, body SHA256 `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860`, name `sub_519210`, type `void __userpurge(int@<ecx>, int@<ebx>, int, int)`, frame in exact order `packetSize/+0x8/0x4/__int16[2]`, `Src/+0xc/0x100/unsigned __int8[256]`, `var_4/+0x10c/0x4/_DWORD`, `__saved_registers/+0x110/0x4/_DWORD`, `__return_address/+0x114/0x4/_UNKNOWN *`, `arg_0/+0x118/0x4/_DWORD`; entry AR/AP/FR/FP absent; sole function inbound data xref `{0x0061ecf4}`. | Public request: `set_address_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x0051938f",comment:"Compiler-inlined TextMenuItemList::SendSelectedTextMenuReply() expansion, including its nested SendTextMenuReply(unsigned short) serializer; retained bodies are 0x005195f0 and 0x00519720."})`. Complete poststate: same code item/range/size/bytes/name/type/AP/FR/FP/xrefs; AR alone equals the new exact text. The containing function retains the exact range/size/hash/name/type/six-row frame/order, entry comment channels, vtable xref, callees, and every unlisted internal comment. | Only the `0x0051938f` AR may change. Stop on containing-function metadata/frame/body/xref/callee, any other comment, or endpoint drift. |

Protected no-change state:

- P01: target body, both padding hashes, 73 instruction heads, zero external all-head xrefs, zero VA/RVA/raw-offset patterns, and item boundaries remain exact.
- P02: target remains raw code and not a function; name/type/stack/function-comment channels remain absent/not applicable.
- P03: UID0004HE name/type/frame/body/xrefs and all comments except A07 FR remain exact.
- P04: UID0004HC function name/type/frame/body/vtable xref and all comments except A08 AR remain exact.
- P05: `g_packetSender` item/name/type/value/comments and all packet/helper function identities remain unchanged.
- P06: no complete UDT, local/stack rename, vtable edit, byte patch, function definition/rename/type action, save, or non-comment mutation is recommended.

## First-Draft C++ Recommendation

- Target is eligible for formal source: owner, emitter, behavior, factoring, names, and boundaries are sufficiently resolved.
- Exact UID0004HF `RECONSTRUCTION_CPP CODE` insertion:

~~~cpp
void TextMenuItemList::SendTextMenuReply(unsigned short itemId)
{
    unsigned char packet[0x100];
    int cursor = 0;

    PacketBufferAppendUInt8(0x39, packet, &cursor);
    PacketBufferAppendUInt8(m_menuType, packet, &cursor);
    PacketBufferAppendUInt32BE(m_menuId, packet, &cursor);
    PacketBufferAppendUInt16BE(itemId, packet, &cursor);

    if (m_ownerDialog->m_hasExtraString) {
        PacketBufferAppendAnsiString8(
            m_ownerDialog->m_extraString.c_str(),
            packet,
            &cursor);
    }

    packet[cursor] = 0;
    QueueAndSendPacket(g_packetSender,
                       packet,
                       static_cast<short>(cursor));
}
~~~

- Exact UID0004HF H disposition: keep blank. The declaration belongs to UID0000ET.
- Exact UID0000ET formal CPP class insertion under `private:`:

~~~cpp
    void SendTextMenuReply(unsigned short itemId);
~~~

- Exact UID0004HE formal CPP replacement:

~~~cpp
void TextMenuItemList::SendSelectedTextMenuReply()
{
    if (m_selectedIndex < 0)
        return;

    const TextMenuItemListEntry *entry =
        static_cast<const TextMenuItemListEntry *>(GetItem(m_selectedIndex));

    SendTextMenuReply(entry->itemId);
}
~~~

- UID0004HC formal CPP remains unchanged and continues to call `list->SendSelectedTextMenuReply()`.
- This source preserves exact runtime behavior while expressing the most plausible precompiled developer factoring. It contains no IDA names, raw stack variables, cookie code, explicit range-failure call, or decompiler-shaped temporary names.

## Final Recommendation

- Preserve the applied UID0004HF retained source-authored private TextMenuItemList helper at 93/94.
- Preserve its applied UID0000ET/UID0000OP owner/emitter route.
- Preserve UID0004HE's compact helper call and UID0004HC's transitive-inline evidence.
- Apply only the exact safe IDA comment package after supervisor Gate 2B revalidation.
- Preserve no-route evidence as a binary fact, but historicalize its former use as a blanket no-code rule.

## Recommended Target Doc Changes

1. Applied `86/91` to `93/94`, retained owner/reconstructable, and set emitter `0000ET`.
2. Applied the exact target CPP block above and kept H blank.
3. Applied retained private-method status, ABI, owner/emitter/file placement, and source-order conclusions.
4. Applied exact range/padding/size/hash/signature and 73-head route evidence.
5. Applied packet contract, stack/cookie/compiler-artifact analysis, callees, optional string, and send semantics.
6. Applied the UID0004HE/UID0004HC nested-inline stage map and source-factoring rationale.
7. Preserved zero-route/no-pointer/no-symbol evidence and historicalized only obsolete blank-emitter reasoning.
8. Applied ownership alternatives, source placement, IDA disposition, score rationale, cross-references, and dated history.

## Recommended Support Doc Changes

- UID0004HE: formal CPP now contains selected lookup plus helper call; metadata 93/94 and blank H are preserved; factoring/liveness/history retain zero-route facts.
- UID0000ET: private declaration is present, score is 93/93, and method map/packet behavior/source order/history no longer use unresolved/no-code UID0004HF as current state.
- UID0004HC: code/metadata remain unchanged; evidence now describes transitive nested inlining.
- UID0000ES: formal friend/code/metadata remain unchanged; stale unresolved-UID0004HF prose is corrected.
- UID0000OP: metadata remains 90/86; inventory, factoring/order, generated expectations, and history are current.
- UID0001BN: metadata is 92/93; target row, raw-helper evidence, source order, cap text, alternatives, and history are current while the aggregate remains non-emitting.
- Generated files remained validator-owned. Physical readback proves one private declaration, one compact UID0004HE wrapper, one UID0004HF definition, no duplicated serializer source, and unchanged structural `TextMenuDialogs.h` output.

## Score And Metadata Recommendation

| UID | Assignment-time | Applied current | Metadata disposition | Reason |
| --- | --- | --- | --- | --- |
| 0004HF | 86/91 | 93/94 | owner 0000ET; TRUE; emitter 0000ET; CPP nonblank; H blank | Behavior, range, factoring, route, source complete; lexical/direct-route limits remain. |
| 0004HE | 93/94 | 93/94 | unchanged | Better factoring; evidence level already strong. |
| 0000ET | 91/91 | 93/93 | owner/emitter/formal route retained | Last unresolved serializer closes; GrafPort/virtual spelling caps remain. |
| 0004HC | 91/93 | 91/93 | unchanged | Existing source call remains correct. |
| 0000ES | 86/86 | 86/86 | unchanged | Friend relation already sufficient; broader caveats remain. |
| 0000OP | 90/86 | 90/86 | unchanged | One omission fixed; broad module caveats remain. |
| 0001BN | 90/92 | 92/93 | non-emitting split/container retained | Named remaining raw-helper blocker closes. |

No score reaches 95 because original symbols and exact historical lexical/source-file proof remain unavailable.

## Open Questions With Attempted Resolution

- Direct caller: no surviving direct route; resolved as compiler-inlined source call by UID0004HE suffix and live UID0004HC transitive expansion.
- Exact method name: no symbol; resolved to `SendTextMenuReply(unsigned short itemId)` by class vocabulary, overload role, independent prior inference, and project style.
- Access: no source token; resolved private because only class-internal factoring is evidenced.
- Duplication versus factoring: exact stage alignment plus demonstrated compiler inlining makes wrapper/helper factoring highest probability.
- IDA model: deterministic define/type poststate is unavailable without forbidden mutation; resolved with safe comment-only actions and explicit no-function/type disposition.
- Header/source placement: existing UID0000ET/UID0000OP chain resolves placement; no new file/header.
- Score: all material documentation/source blockers close; remaining uncertainty is lexical/direct-route confidence only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Insert after UID0004HE in `by-memory/-coverage-report.md`:

`    - [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md) 0x00519720-0x0051983a | retained raw class helper | TextMenuItemListRawExplicitIdReplySerializer : reconstructable : 93% : very-strong : Source-ready retained TextMenuItemList SendTextMenuReply(unsigned short itemId) private helper with exact 282-byte body, opcode 0x39 field order, optional owner ANSI text, guarded non-sent terminator, exhaustive zero-route/pointer evidence, nested compiler-inline relation through SendSelectedTextMenuReply and live OnDialogAction, class owner/emitter UID0000ET, and complete formal C++ source.`

Replace UID0001BN row:

`    - [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md) 0x00517ec0-0x0051a417 | class-method/raw-helper aggregate | TextMenuDialogs : reconstructable : 92% : very-strong : Text-menu dialog aggregate with exact request/constructor/paint/action/update children, source-emitting retained TextMenuDialog and both TextMenuItemList opcode 0x39 serializers, nested compiler-inline factoring, TextInputMenuDialog methods, factory callers, vtable-family evidence, source order, and adjacent text-input reply helper documented.`

Replace UID0000ET row in `by-class/-coverage-report.md`:

`- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md) : reconstructable : 93% : very-strong : Private TextMenuDialogs.cpp list class with exact 0x202 row layout, constructor/add/forward/draw methods, retained SendSelectedTextMenuReply wrapper plus private SendTextMenuReply(unsigned short) serializer, nested live OnDialogAction inline evidence, three-view vtable/destructor policy, owner context fields, formal C++, and remaining GrafPort/virtual spelling caps documented.`

Do not manually edit `auto-generated/-ag-research-tracker.md`; validator refresh owns its later transition.

## Follow-Up Actions

1. Supervisor performs fresh exact-artifact Gate 1 on this implemented report and its 50-row twin.
2. Supervisor independently verifies the seven ordinary destinations and current generated CPP/H readback.
3. Supervisor applies and validates the three manual coverage rows C4HF-038..040.
4. Supervisor independently performs the eight comment-only Gate 2B actions C4HF-041..048 and protected-state check C4HF-049 under fresh canonical readback or rejects drift.
5. Supervisor alone completes C4HF-050 and report execution/archive lifecycle.

## Confidence

- Behavior/range/ABI/packet/send semantics: certain.
- Owner/emitter/file route: certain.
- Retained source existence and nested inline relation: very strong.
- Source factoring/access: very strong.
- Exact method spelling: strong, not symbol-proven.
- IDA action safety: very strong; comment-only with literal pre/post/protection.
- Overall target confidence recommendation: 94.

## Validator Results

- Scoped validators completed with `exit 0` and `ok:1`: UID0004HF command `000000024214` (`2026-08-15T08:18:49-04:00`), UID0004HE `000000024215` (`08:21:18`), UID0004HC `000000024216` (`08:22:25`), UID0000ET `000000024218` (`08:23:45`), UID0000ES `000000024219` (`08:24:19`), UID0000OP `000000024221` (`08:25:55`), and UID0001BN `000000024222` (`08:27:33`).
- Owning-file command `000000024224` (`2026-08-15T08:27:59-04:00`) completed with `exit 0`, `ok:1`, and generated refresh completed. Its nonfatal missing-reference diagnostics concern pre-existing support UIDs, not callback syntax or metadata failure.
- Physical generated readback: `TextMenuDialogs.cpp` SHA256 `A48D91B801C73A9CEBDD46DD407D65DDD9F14CD0F81269D86DA6CCF675291F4F`, 19,094 bytes, 611 lines; UID0000ET declaration lines 90-119, UID0004HE lines 144-154, UID0004HF lines 156-178, `ForwardOwnerSelectionState` starts line 180, and UID0004HC calls the wrapper at line 580.
- Physical header readback: `TextMenuDialogs.h` SHA256 `54C4B6359B752E1C56469365A0F15E19FDFEA1759931E11C254041B2C9B924DB`, 1,632 bytes, 47 lines, with existing `friend class TextMenuItemList;` at line 21 and no TextMenuItemList declaration/definition.
- Manual coverage validation is intentionally absent because C4HF-038..040 remain supervisor-owned and unchecked.
- Report execution/archive state is exclusively supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Changed Files

- Applied ordinary changes to UID0004HF, UID0004HE, UID0004HC, UID0000ET, UID0000ES, UID0000OP, and UID0001BN, then reconciled this same report.
- Validators refreshed validator-owned generated/registry/tracker metadata. No generated file, coverage report, tracker, validator registry, audit/lifecycle file, goal/notes file, or IDA database was manually edited.
- Every ordinary destination lease was taken only immediately before its edit/validation and explicitly released immediately afterward. Report lease authority is external to this prose and must be confirmed from the leaser receipt/current lease state.

## Implementation Tracking Checklist

Applied ordinary/generated allocation: 37 claims are checked (`applied` or `already-present`) and 13 supervisor-owned claims remain unchecked/proposed. Row order and all eight fields are exact ledger twins after removing `Done`.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C4HF-001 | 0004HF | Preserve exact body `[0x00519720,0x0051983a)`, 282 bytes, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`; preserve three-byte lead and six-byte trail padding. | Certain | Current MCP bytes/hashes/items. | UID0004HF Exact Range, Boundaries, Identity | incorporate | applied |
| [x] | C4HF-002 | 0004HF | Preserve the complete 73-head external inbound-xref union as count zero, exact set `{}`. | Certain | Current all-head `xrefs_to`. | UID0004HF Negative Route Evidence | incorporate | applied |
| [x] | C4HF-003 | 0004HF | Preserve zero target VA/RVA/raw-offset pointer encodings and zero end-address encodings. | Certain | Current all-image `find_bytes`; PE mapping. | UID0004HF Negative Route Evidence | incorporate | applied |
| [x] | C4HF-004 | 0004HF | Record the target wildcarded byte signature as unique in the current IDB. | Strong | Current `make_signature_for_range`. | UID0004HF Exact Range And Identity | incorporate | applied |
| [x] | C4HF-005 | 0004HF | Record ABI as receiver in ECX, one unsigned-short logical stack argument at `[ebp+8]`, `retn 4`, 0x108 local allocation, saved ESI, and security cookie. | Certain | Exact current disassembly. | UID0004HF ABI And Compiler Shape | incorporate | applied |
| [x] | C4HF-006 | 0004HF | Packet byte zero is opcode `0x39`. | Certain | Call at `0x0051974e`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-007 | 0004HF | Packet byte one is `m_menuType` from receiver `+0x14c`. | Certain | Instructions `0x00519769-0x00519771`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-008 | 0004HF | Packet bytes two through five are big-endian `m_menuId` from receiver `+0x150`. | Certain | Instructions `0x0051978c-0x00519792`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-009 | 0004HF | Packet bytes six and seven are the explicit unsigned-short `itemId` argument in big-endian order. | Certain | `[ebp+8]` zero-extension, writer call, `retn 4`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-010 | 0004HF | Receiver `+0x154` is non-owning `m_ownerDialog`. | Certain | Instruction `0x005197c2` and class layout. | UID0004HF Fields/Ownership/formal CPP | incorporate | applied |
| [x] | C4HF-011 | 0004HF | Owner byte `+0x279` gates ANSI length-8 append of owner `m_extraString` at `+0x27c`. | Certain | Branch/helper sequence `0x005197d2-0x00519800`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-012 | 0004HF | Preserve `<0x100` cursor guard and compiler range-failure tail at `0x00519835`. | Certain | `cmp/jnb` and exact tail. | UID0004HF Packet/Compiler Shape | incorporate | applied |
| [x] | C4HF-013 | 0004HF | Preserve local `packet[cursor]=0` after the guard and exclude that zero from transmitted length. | Certain | `0x00519810-0x00519820`. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-014 | 0004HF | Send through `g_packetSender`/`QueueAndSendPacket` with pre-terminator cursor cast to short. | Certain | Global/call type and send sequence. | UID0004HF Packet Contract/formal CPP | incorporate | applied |
| [x] | C4HF-015 | 0004HF | Exclude `GetMemoryMan`, stack cookie, raw stack offsets, and explicit range-failure call from human source. | Very strong | Compiler pattern and accepted siblings. | UID0004HF Compiler Artifacts/CPP rationale | reject-stale | applied |
| [x] | C4HF-016 | 0004HE | UID0004HE adds selected-index guard/GetItem then repeats UID0004HF's full serializer stages. | Certain | Current HE disassembly/decompile stage map. | UID0004HF Relation; UID0004HE Source Factoring | incorporate | applied |
| [x] | C4HF-017 | 0004HC | Live UID0004HC region `[0x0051938f,0x00519492)` repeats selected lookup plus all serializer stages under vtable route `0x0061ecf4`. | Certain | Current action analysis/xref. | UID0004HF Liveness; UID0004HC Evidence | incorporate | applied |
| [x] | C4HF-018 | 0004HF | Reconstruct the source as nested calls `OnDialogAction -> SendSelectedTextMenuReply -> SendTextMenuReply(itemId)` with compiler inlining explaining the three copies. | Very strong | Exact stage alignment and retained copies. | UID0004HF Source Factoring; support docs | incorporate | applied |
| [x] | C4HF-019 | 0004HF | Use human source name/signature `void TextMenuItemList::SendTextMenuReply(unsigned short itemId)` and private access. | Strong | ABI, class vocabulary, B012 independent inference. | UID0004HF formal CPP; UID0000ET declaration | incorporate | applied |
| [x] | C4HF-020 | 0004HF | Keep canonical owner UID0000ET TextMenuItemList. | Certain | Receiver fields, physical cluster, class inventory. | UID0004HF metadata/Ownership | already-present | already-present |
| [x] | C4HF-021 | 0004HF | Keep source placement in UID0000OP TextMenuDialogs.cpp after UID0004HE and before `ForwardOwnerSelectionState`. | Very strong | Physical/source order and current emitter route. | UID0004HF Source Placement; UID0000OP | incorporate | applied |
| [x] | C4HF-022 | 0004HF | Set `EMITTER_UIDS:0000ET`; no standalone file/header route. | Certain | UID0000ET -> UID0000OP chain. | UID0004HF metadata | incorporate | applied |
| [x] | C4HF-023 | 0004HF | Raise target score from 86/91 to 93/94. | Strong | All behavior/source blockers resolved; lexical/direct-route limits retained. | UID0004HF metadata/Score Rationale | incorporate | applied |
| [x] | C4HF-024 | 0004HF | Insert the exact private explicit-id serializer definition in the target CPP channel. | Very strong | Exact packet semantics and source factoring. | UID0004HF RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C4HF-025 | 0004HF | Keep target H blank because declaration ownership is UID0000ET's file-local class fragment. | Certain | Current channel routing. | UID0004HF RECONSTRUCTION_H CODE | already-present | already-present |
| [x] | C4HF-026 | 0000ET | Add private declaration `void SendTextMenuReply(unsigned short itemId);`. | Very strong | Recovered helper/source access. | UID0000ET formal CPP class declaration | incorporate | applied |
| [x] | C4HF-027 | 0004HE | Replace duplicated UID0004HE serializer source with selected lookup plus `SendTextMenuReply(entry->itemId)`. | Very strong | Nested inline evidence. | UID0004HE RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C4HF-028 | 0004HE | Keep UID0004HE metadata 93/94, owner/emitter, and blank H unchanged. | Strong | Behavior/source role remains complete. | UID0004HE metadata | already-present | already-present |
| [x] | C4HF-029 | 0004HC | Keep UID0004HC formal CPP/metadata unchanged; update prose to identify transitive nested inlining. | Very strong | Existing source call is correct. | UID0004HC Evidence/Changes | incorporate | applied |
| [x] | C4HF-030 | 0000ES | Preserve current friend declaration and formal source; replace prose saying UID0004HF is unresolved. | Very strong | Existing access route already sufficient. | UID0000ES Relation/Changes | incorporate | applied |
| [x] | C4HF-031 | 0000ET | Raise class score 91/91 to 93/93 and replace every unresolved/no-code UID0004HF statement. | Strong | Last raw serializer blocker resolved; other class name caps remain. | UID0000ET metadata/Status/Method Map/Changes | incorporate | applied |
| [x] | C4HF-032 | 0000OP | Keep by-file score 90/86; update method inventory, source factoring/order, generated expectations, and history. | Strong | Target resolves one child but broad module caveats remain. | UID0000OP TextMenuItemList sections | incorporate | applied |
| [x] | C4HF-033 | 0001BN | Raise aggregate 90/92 to 92/93 and replace independently unresolved UID0004HF text with resolved retained helper/factoring. | Strong | Explicit named aggregate blocker removed; broad caveats remain. | UID0001BN metadata/range map/evidence/history | incorporate | applied |
| [x] | C4HF-034 | 0000ET | Expected generated class declaration contains both `SendSelectedTextMenuReply()` and private `SendTextMenuReply(unsigned short)`. | Very strong | Formal emitter route. | Generated TextMenuDialogs.cpp readback checklist | incorporate | applied |
| [x] | C4HF-035 | 0004HE | Expected generated UID0004HE body performs only guard/GetItem/helper call at source level. | Very strong | Accepted source factoring. | Generated TextMenuDialogs.cpp readback checklist | incorporate | applied |
| [x] | C4HF-036 | 0004HF | Expected generated UID0004HF definition appears once after UID0004HE and before `ForwardOwnerSelectionState`. | Certain | Child order and emitter marker. | Generated TextMenuDialogs.cpp readback checklist | incorporate | applied |
| [x] | C4HF-037 | 0000OP | Generated TextMenuDialogs.h remains unchanged; no TextMenuItemList declaration belongs there. | Very strong | Private class stays in CPP; existing friend is sufficient. | Generated TextMenuDialogs.h readback checklist | already-present | already-present |
| [ ] | C4HF-038 | 0004HF | Insert exact new by-memory manual coverage row at 93% very-strong after UID0004HE. | Certain | Current row absent and address order. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C4HF-039 | 0001BN | Replace aggregate manual coverage row with 92% very-strong resolved-helper text. | Certain | Proposed aggregate score/content. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C4HF-040 | 0000ET | Replace class manual coverage row with 93% very-strong resolved two-helper text. | Certain | Proposed class score/content. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C4HF-041 | 0004HF | Add exact repeatable address comment at raw entry `0x00519720`; keep raw item/function state unchanged. | Very strong | Exact item/comment/xref prestate. | Supervisor Gate 2B IDA A01 | incorporate | proposed |
| [ ] | C4HF-042 | 0004HF | Add exact regular address comment for `m_menuType` at `0x00519769`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A02 | incorporate | proposed |
| [ ] | C4HF-043 | 0004HF | Add exact regular address comment for `m_menuId` at `0x0051978c`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A03 | incorporate | proposed |
| [ ] | C4HF-044 | 0004HF | Add exact regular address comment for explicit `itemId` at `0x005197af`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A04 | incorporate | proposed |
| [ ] | C4HF-045 | 0004HF | Add exact regular address comment for owner/optional-string path at `0x005197c2`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A05 | incorporate | proposed |
| [ ] | C4HF-046 | 0004HF | Add exact regular address comment for guard/terminator/send semantics at `0x00519811`. | Certain | Exact instruction/item prestate. | Supervisor Gate 2B IDA A06 | incorporate | proposed |
| [ ] | C4HF-047 | 0004HE | Replace UID0004HE function-regular comment with exact nested-helper factoring text only. | Very strong | Current modeled function/state. | Supervisor Gate 2B IDA A07 | incorporate | proposed |
| [ ] | C4HF-048 | 0004HC | Replace `0x0051938f` regular comment with exact transitive-inline text only. | Very strong | Current inline item/comment/state. | Supervisor Gate 2B IDA A08 | incorporate | proposed |
| [ ] | C4HF-049 | 0004HF | Do not define, rename, or type the raw target and do not edit stack state; no deterministic target-specific poststate proof exists. | Certain | Current no-function state and workflow safe-subset rule. | Supervisor Gate 2B protected-state contract | not-applicable | proposed |
| [ ] | C4HF-050 | 0004HF | Supervisor must apply manual coverage, scoped-validate every changed ordinary page and coverage report, refresh generated output/tracker, verify CPP/H physically, perform Gate 2B separately, and exclusively own report execution/archive. | Certain | Workflow actor boundaries. | Validator/coverage/generated/lifecycle checklist | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000024288","destination_path":"executed-b-agent-research/B006/0004HF-TextMenuItemListRawExplicitIdReplySerializer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0004HF-TextMenuItemListRawExplicitIdReplySerializer-source-quality.md","timestamp":"2026-08-15T09:27:41-04:00","uid":"0004HF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
