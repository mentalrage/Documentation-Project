** TARGET-REPORT-UID:0003O7 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003O7 SelfSaveInputPaneSendSelfSavePacketRaw Ownership / Split Research

## Finalized Report / Current Recommendation

- Current implementation: the exact `[0x005b6870,0x005b68b1)` child retains direct owner/emitter UID0000CW, position `30`, `Nested:0`, and standalone UID0000NM file route; its source disposition is now the retained out-of-line definition of private nonvirtual member `SelfSaveInputPane::SendSelfSavePacket()`.
- Final disposition: source-bearing NexusTK project code. UID0003O6 now contains the human source call `SendSelfSavePacket();`; the documentation separately preserves that the observed release binary inlined the complete send tail there while retaining the out-of-line member body at the target range.
- Source-layout decision: exact binary facts are frame `0x14`, packet base `-0x14`, cookie `-4`, writes at offsets `0/1`, and send length `1`. Same-binary controls prevent treating that interval as declaration proof, while the closest available x86 MSVC matrix reproduces the tuple only for `[16]`; use inferred `unsigned char packet[16]` and retain `[2]` plus exact-toolchain padding as the bounded runner-up.
- Callback result: the target, UID0003O6, UID0001MU, UID0000CW, UID0000NM, bounded SelfSave vtable/constructor/factory support, and packet-provider/global consumer evidence were synchronized; all three exact managed formal blocks were applied. No second helper, child merge, or handwritten vtable/runtime mechanics were introduced.
- Current scores: target `92/92`; UID0003O6 `92/93`; UID0001MU `91/92`; UID0000CW `91/93`; UID0000NM `91/92`. Provider, vtable, constructor, factory, and global/storage scores remain unchanged.
- Confidence: very strong for exact bytes, range, packet behavior, duplicate-tail identity, owner/emitter, source route, and private-member family convention; strong for the inferred original member spelling, release inlining explanation, and highest-probability `unsigned char packet[16]` declaration. The source array capacity is inferred from controlled layout evidence, not proven by the frame interval alone.

## Supporting Research

- Historical assignment source: B004 `goal.md` selected the report-only UID0003O7 pass from a generated research queue snapshot at `87/88`. That evidence-time snapshot said report count `0`; exact report-root searching found a historical executed B007 exact-target artifact, so the queue count was stale provenance context rather than proof that no prior research existed.
- Historical Gate 1 repair scope: the supervisor rejected only the prior inference that the packet-to-cookie interval alone proved `unsigned char packet[16]`. That additive report revision preserved the valid source-disposition research, added sibling/IDA/toolchain/compiler controls, ranked realistic declarations, and propagated the resulting inferred `[16]` choice and confidence cap before the callback implemented the accepted result.
- Mandatory live MCP evidence was collected from database `supervisor_nexustk_20260713`. A fresh `idb_list` identified the configured NexusTK IDB, and evidence-time `server_health` at 2026-07-13 17:09 EDT returned `status=ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache. Bounded target byte/function queries and a real vtable read succeeded. This is evidence-time health, not an indefinite availability assertion.
- Exact old-report search terms: `UID0003O7`, `UID:0003O7`, `0x005b6870`, `0x005b68b1`, `5b6870`, `SelfSaveInputPaneSendSelfSavePacketRaw`, `SendSelfSavePacket`, `SelfSaveInputPane`, `UID0000CW`, `UID0000NM`, and `opcode 0x25`.
- Evidence-time active report roots `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`: no matching report when searched. B004's then-current `goal.md` was assignment metadata, not a prior report.
- `tools/leaser/Agents/Older-Research/**`: no match. `tools/leaser/Agents/SpecialReports/**`: no match. `archived/**`: no match.
- Direct historical report opened: `executed-b-agent-research/B007/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`. It correctly repaired the one-byte-short range and established no-route evidence, opcode, owner, and initial formal source, but selected file-static solely from absence of a `this` read. Its validator history marks it `needs-revalidation` for `target_uid_unknown`; it is a historical lead, not an accepted substitute for this report. It did not audit the Wield call site's explicit `ECX=this`, the Wear parallel, normalized duplicate-tail hashes, source-array-versus-padding alternatives, compiler layout controls, or current Socket member-call syntax.
- Relevant historical support reports opened and classified:
  - `executed-b-agent-research/B002/0002N8-SelfSaveInputPaneVtableData-source-quality.md`: proves the active handler slot, exact three-view vtable, class ownership, and absence of a helper slot. Its file-static helper wording is superseded by this focused source-family audit; a private nonvirtual member is not expected in a vtable.
  - `executed-b-agent-research/B005/0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md`: confirms the same class/file route, exact method-island order, and `SendSelfSavePacket` private-helper name lead. It does not decide member versus file-static.
  - `executed-b-agent-research/B012/0001KQ-SelfSaveInputPaneFactory-source-quality.md`: confirms the retained no-route factory and complete SelfSave source-unit placement. It does not route or own the packet helper.
  - `executed-b-agent-research/B012/0001MS-SendWieldPacket-source-quality.md`: records the Wield `sub esp,0x84`, packet base `-0x84`, cookie `-4`, three touched bytes, and accepted 128-byte local. Live MCP during research revalidated the modeled Wield frame; the report is a sibling source-shape lead, not proof of SelfSave capacity.
  - `executed-b-agent-research/B009/0001M4-SendEmotionPacket-source-quality.md`: records the Emotion `0x84/-0x84/-4` layout and accepted 128-byte local. Its older interval-to-declaration reasoning is not adopted as proof; this repair uses it only after same-binary and compiler controls.
  - `executed-b-agent-research/B005/0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md`: relevant duplicate/inlining precedent only; it distinguishes human source ownership from the binary copy that realizes it.
  - `executed-b-agent-research/B001/00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md` and `executed-b-agent-research/B005/0002QB-RawPasswordChangePacketWithAccount-source-quality.md`: cite UID0003O7 as a retained packet-helper precedent but add no direct target evidence.
  - `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md`, `B001/0002SB-GroupInputPaneRawConstructor-source-quality.md`, `B002/0001MV-BlockListenInputPaneConstructor-source-quality.md`, `B004/0001AY-SelfSaveOKPaneFactory-source-quality.md`, and `B007/0001M0-TakeOffInputPaneRawConstructor-source-quality.md`: family, boundary, or no-route precedents only; none supplies a direct target route or original symbol.
- Historical Wave3 references in the SelfSave docs read during research were treated as stale evidence-only artifacts. No Wave2/Wave3 score, source file, or generated body controlled this recommendation.

## Target

- Target UID: `0003O7`.
- Target path: `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md`.
- Historical B004 research/implementation-callback artifact path before supervisor lifecycle: `tools/leaser/Agents/Agent-B004/research/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`.
- Historical source queue/report row: the evidence-time generated tracker snapshot listed `Not-Covered Files - Reconstructable`, `87/88`, combined `87.5`; its report-count field was stale because the historical B007 exact-target artifact existed. It is not a current post-callback score/count assertion.
- Historical supervisor classification: the exact Gate 1 artifact was accepted for implementation. The callback is now complete; report validation, execution, counting, path, move, and archive state remain external supervisor/validator-owned state and are not asserted by this artifact.
- Current scores and parent state: target `92/92`, `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CW`, position `30`, `Nested:0`; owner UID0000CW is `91/93`, emitter/file UID0000NM is `91/92`.

## Current Target State

- Current metadata: exact half-open range and `ret` endpoint remain corrected; owner/emitter/position/Nested remain structurally correct; target score is `92/92`.
- Current owner/emitter/reconstructable state: retained unchanged. The target is class-owned source code emitted through the class to UID0000NM.
- Current C++/emitter state: emits `void SelfSaveInputPane::SendSelfSavePacket()` with inferred `unsigned char packet[16]` and member call `g_packetSender->QueueAndSendPacket(packet, 1)`. UID0003O6 emits one source helper call; generated command `000000010487` readback confirms the release-inline packet body is documented as binary evidence rather than duplicated handwritten source.
- Historical blockers corrected by the research and callback:
  - “no xref” was incorrectly treated as the endpoint of liveness analysis;
  - absence of an observable `ECX` read was incorrectly treated as proof against membership;
  - source duplicates the same human packet body instead of representing the inlined call relationship;
  - pre-callback `packet[2]` was minimally sufficient for the two touched bytes, but prior research did not test it against same-binary stack-layout controls or a comparable compiler; conversely, the 16-byte packet-to-cookie interval alone does not prove a 16-element source array;
  - free-function sender syntax contradicts accepted `Socket::QueueAndSendPacket` and `Socket *g_packetSender` support;
  - pre-callback docs stated that using a source helper call would necessarily change the binary call graph, ignoring optimization/inlining.
- Related target/support docs checked and, where accepted, synchronized: UID0003O6, UID0001MU, UID0000CW, UID0000NM, UID0000ID, UID0003O5, UID0001KQ, UID0002N8, UID0003HM, UID0003YJ, UID0001HU, UID0000Q5, UID0001P0, Wield UID0001MS/UID0001MR/UID0000G4, Wear UID0002YP/UID0001MT/UID0000G0, and generated `SelfSaveInputPane.cpp`.
- Current artifact/lifecycle boundary: implementation and scoped validation are complete, all B004 leases were released, and waited generated readback is recorded below. B004 performed no `execute_report`, report-lifecycle probe, move, or archive command. External report validation/execution/count/path/archive state is supervisor/validator-owned and must be read from external lifecycle records rather than inferred from this artifact.

## Executive Recommendation

- Direct semantic owner/emitter remains UID0000CW `SelfSaveInputPane`; immediate file route remains UID0000NM `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`.
- Treat `0x005b6870` as an IDA-missing but complete private nonvirtual member function, not a file-local helper, class-static helper, compiler-only clone, or no-code/covered-by body.
- Preserve exact child range, path, position `30`, and `Nested:0`; no split, merge, padding transfer, new child, or source-file migration is justified.
- The callback replaced duplicate human source with a private declaration, one out-of-line member definition, and an active-handler source call. The release compiler's inlining explains the second binary copy without requiring duplicate source.
- The material residual uncertainties are original spelling, exact array capacity, and whether the compiler had an unseen declaration/build attribute. Controlled evidence selects `unsigned char packet[16]` as the highest-probability human source form, but capacity remains an explicitly bounded inference and caps target confidence at 92; it does not leave the formal C++ undecided.

## Supervisor Active Recheck

- Historical trigger: B004 `goal.md` required the report-only pass to exhaust no-route, retained-helper, duplicate-inline-tail, source-name/signature, owner/emitter, source-placement, score, and formal-C++ questions. Gate 1 accepted that result, and the authorized callback has now applied it.
- Split repair: no new split is required. The exact target, four-byte predecessor alignment, and fifteen-byte successor alignment are already correctly separated.
- Every source-bearing child in scope has a complete disposition: constructor UID0003O5 remains source-ready; active handler UID0003O6 has the source call; target UID0003O7 is the retained member definition; factory UID0001KQ remains separate retained construction source; vtable pages remain generated-binary disposition pages.

## Inference Research Guidance Check

- `by-structure.md` requires evidence-based owner/emitter routing, source-shaped C++, and explicit distinction between source and generated binary. That discipline supports the applied one-human-helper-definition plus inlined-call model over two handwritten copies.
- Existing assumptions treated as uncertain: file-static declaration, two-byte source buffer, 16-byte declaration inferred from frame span alone, free sender wrapper syntax, no-call requirement, and the claim that no `this` read disproves membership.
- Direct IDA facts are separated below from documentation facts and inference. The private-member result is an inference supported by direct caller ABI evidence from the immediately preceding Wield family, exact normalized duplicate bytes, class adjacency, and link-time retention behavior.
- Stale Wave2/Wave3 material was found in support prose and ignored as authority. Evidence-time ordinary docs, generated source, raw PE, live MCP, and project rules controlled the research result; callback readback now proves the applied ordinary/generated state.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Raw/unmodeled start | Live MCP reports `0x005b6870` is not a defined function, but decodes one coherent prologue/body/cookie/epilogue ending in plain `ret`; exact bytes are unique. | IDA function-definition omission, not padding or no-code disposition. Recommend function creation/type after approval. |
| No ordinary route | Live xrefs, whole-image direct-branch scan, absolute VA/RVA/raw-offset scans, and every-interior-byte scans find zero target entries; positive controls find the active vtable slot, 416 queue/send calls, and 489 sender-global references. | Preserve no-route as a liveness/confidence fact; do not use it to discard coherent source. |
| Duplicate inline tail | The active and retained 35-byte cores differ only in their two rel32 call displacements. After zeroing those displacements, both hash to `3844f03d9ccc79066d190bb05f2908454eeaaee2844c1b056762124a3f57b093`; wildcard search finds exactly two hits. | One human helper call was inlined into UID0003O6 while one out-of-line definition was retained. |
| File-static versus member | Target does not read `ECX`, but Wield's sole call at `0x005b64e6` is immediately preceded by `mov ecx, esi`, where `ESI` is the Wield object; its helper also does not read `ECX`. Wear has the same adjacent out-of-line/inline family shape. | Private nonvirtual member is highest probability. An unused file-static helper is weaker because it fails to explain the source-family `this` setup convention. |
| Static member | A class-static helper also would not read `ECX`, but Wield's explicit object setup would be unnecessary and is strong contrary evidence. | Reject class-static. |
| Compiler-only outlined clone | Body has project opcode/global/provider semantics, source-family adjacency, normal source member ABI, and a retained out-of-line family precedent. | Reject compiler-only/no-code. Compiler optimization explains binary duplication, not source ownership. |
| Source signature | No stack parameters, plain `ret`, ignored object state, and fixed packet. Accepted sender API is void; incidental `EAX` is not stable across active-handler returns. | `void SelfSaveInputPane::SendSelfSavePacket()`; implicit `this`, no explicit parameters, private, nonvirtual. |
| Exact local-frame facts | Target executes `sub esp,0x14`, takes the packet address at `[ebp-0x14]`, stores the cookie at `[ebp-4]`, writes packet offsets `0` and `1`, and sends length `1`. UID0003O6 has response storage at `-0x18`, the packet base at `-0x14`, and the cookie at `-4`. | These instructions prove a 16-byte available interval before the cookie and only two touched packet bytes. They do not by themselves prove the original array declaration. |
| Trustworthy IDA local boundaries | `stack_frame(0x005b6800)` models one-byte `Src` and one-byte `var_13` at the packet base, then leaves the rest of the interval untyped before the cookie. Hex-Rays renders `_BYTE Src[16]` by extending the address-taken local to the cookie. The unmodeled target has no stack-frame object. | Treat Hex-Rays `[16]` as a useful layout hypothesis, not source proof. IDA independently proves the two touched bytes and the cookie boundary only. |
| Same-binary packet controls | MainMenu `0x004f7660` has the same `sub esp,0x14`, packet base `-0x14`, cookie `-4`, and Hex-Rays `_BYTE Src[16]`, while its accepted formal source currently uses `packet[1]`. Option `0x0053e380` uses four packet bytes in a 12-byte packet-to-cookie interval and accepted `packet[4]`. Wield `0x005b6500`, Wear retained helper `0x005b6760`, Wear active inline body `0x005b66a0`, and Emotion `0x005b2f70` use accepted 128-byte source forms where packet base `-0x84` and cookie `-4` agree; the active Wear method adds a separate response local at `-0x88`. | Smaller-array-plus-padding is realistic in this binary and defeats interval-only proof. The MainMenu/Option declarations are reconstructed source, not surviving headers, so they are controls against overclaiming rather than proof that SelfSave used the same capacity; the Wield/Wear/Emotion 128-byte controls show that exact large packet intervals can also reflect intentional source capacity. |
| Comparable compiler control | PE headers identify x86 and linker `14.16`; no matching 14.16 `cl.exe` is installed. The closest available x86 MSVC 14.44 probe used `/O2 /GS /Oy-`, `#pragma strict_gs_check(on)`, and the same address-taken writer/explicit-byte-one/send pattern. It produced frame/base/cookie layouts: `[1] -> 0x8/-0x5/-0x4`, `[2] -> 0x8/-0x8/-0x4`, `[4] -> 0x8/-0x8/-0x4`, `[8] -> 0xc/-0xc/-0x4`, `[16] -> 0x14/-0x14/-0x4`. | Only `[16]` reproduced the target frame/base/cookie tuple under the closest available compiler. Version mismatch and unknown exact flags prevent proof, but this is positive evidence beyond the raw interval. |
| Ranked source capacity | `packet[1]` is invalid because source explicitly writes offset `1`. `packet[2]` is minimally sufficient and the strongest smaller-array candidate. `packet[16]` uniquely matches the comparable compiler layout and the observed target tuple. | Select inferred `unsigned char packet[16]` as highest probability; keep `packet[2]` plus compiler padding as the bounded runner-up. The sent length remains exactly one. |
| Packet writer ABI | Callee `0x00575380` reads value first and destination second; it writes byte 0 and a spare zero byte. Caller pushes destination then `0x25`, matching cdecl right-to-left order. | `PacketBufferWriteUInt8(0x25, packet)`. Preserve the explicit second zero write because it exists in both binary copies. |
| Sender call | Target loads `g_packetSender` into `ECX` then calls `0x00574bb0`; accepted UID0001HU source is `Socket::QueueAndSendPacket(const void *, short)`. | Use `g_packetSender->QueueAndSendPacket(packet, 1)`, not a three-argument free function. |
| Return type | Queue/send support is accepted as void; target ends after cookie check; active handler returns differing incidental register values on its early exits. | Source return is void. Reject decompiler-inferred `int`/`short` based on incidental registers. |
| Source name | Existing family terms use Wield/Wear `Send...Packet`; target sends only the SelfSave request. | Keep inferred source name `SendSelfSavePacket`; reject raw/generated labels and broader `Submit`/`Queue` names. |
| Source placement | Constructor, virtual handler, target, vtable data/type, and factory already emit as one ordered UID0000NM unit. | Keep standalone SelfSave source now. CommandInputPanes is only a coordinated whole-unit alternative, not a target-only move. |
| Generated pollution | Historical pre-callback generated source contained two handwritten packet bodies, two `char packet[2]`, two free sender calls, and an unnamed-namespace helper. | The applied formal destination blocks remove the pollution while retaining one source definition and one source call; final command `000000010487` readback proves the corrected counts. |
| Scores | Previous `87/88` omitted family ABI, exact clone identity, source-layout controls, correct sender syntax, and resolved formal source. | Raise target to `92/92`; completion reaches 92, while confidence is capped because array capacity remains inferred and the exact 14.16 compiler is unavailable. Bounded support increases only where source quality materially improves. |

Source-capacity ranking:

| Rank | Candidate | Positive evidence | Negative evidence / cap | Decision |
| --- | --- | --- | --- | --- |
| 1 | `unsigned char packet[16]` | Exact target tuple is frame `0x14`, base `-0x14`, cookie `-4`; Hex-Rays independently chooses 16; closest x86 MSVC control reproduces that tuple only for `[16]`; Wield/Emotion show this family can retain oversized fixed scratch arrays. | No instruction accesses beyond offset `1`; no original header/source survives; available compiler is 14.44 rather than linker-era 14.16. | Highest-probability human source declaration, explicitly inferred rather than proven. |
| 2 | `unsigned char packet[2]` | Smallest valid declaration for writes at offsets `0` and `1`; pre-callback target/active formal source used two; protocol sends one byte and retains a spare zero. | Closest compiler produces frame `0x8`, packet base `-0x8`, not the observed `0x14/-0x14`; no other target source local accounts for the additional `0xc` bytes. | Plausible runner-up only if exact compiler flags inserted otherwise-unobserved padding. |
| 3 | smaller array plus implicit padding/alignment | Same-binary MainMenu and Option reconstructions demonstrate that touched byte count can be smaller than the pre-cookie interval; IDA leaves the SelfSave gap untyped. | Their declarations are reconstructions, not original source; the closest compiler does not pad `[2]` to the target tuple; target has no identified extra local or alignment declaration. | Realistic mechanism, retained as a confidence cap, but weaker than `[16]` for this exact target. |

Rejected alternatives:

- Retain the pre-callback file-static helper: rejected because the Wield member-family call explicitly prepares `this`, the target is class-adjacent, and a non-inline member naturally explains retained out-of-line code after call-site inlining.
- Put the body only in UID0003O6 and blank the target: rejected because the target is a complete unique out-of-line source body, not generated glue, and source membership explains its retention.
- Emit both full bodies as handwritten source: rejected because exact normalized identity and family convention support inlining from one source helper; duplicate source is less plausible and less maintainable.
- Make the member virtual: rejected because exact vtable data has no helper slot and no dynamic-dispatch need exists.
- Make the member static: rejected by Wield's explicit `ECX=this` call convention.
- Move ownership to Socket, PacketBuffer, `g_packetSender`, SelfSaveOKPane, CommandInputPanes alone, or BlockListen: rejected because those are providers, adjacent families, or broader grouping candidates rather than the direct behavior owner.
- Select `packet[2]` as final source: not selected after controls. It is minimally sufficient and remains the runner-up, but the closest x86 MSVC layout produces `0x8/-0x8/-0x4`, not the target `0x14/-0x14/-0x4` tuple.
- Treat smaller-array-plus-padding as impossible: rejected. Same-binary MainMenu/Option evidence proves that pre-cookie span can exceed reconstructed source capacity. This mechanism remains a bounded alternative and is why `[16]` is inferred rather than certain.
- Use `packet[1]`: rejected because the explicit source-preserved `packet[1] = 0` would be out of bounds.
- Remove the explicit `packet[1] = 0`: rejected because it appears after the writer in both exact copies even though the writer also stores a spare zero.

## Evidence Standards Used

- Evidence types: evidence-time live IDA MCP health, lookup, raw bytes, instruction queries, xrefs, vtable bytes, modeled active function/decompile, IDA stack-frame variable boundaries, same-binary packet-frame controls, PE toolchain fingerprint, controlled x86 MSVC layout compilation, local-range entity inventory, whole-image Capstone direct branch/call scan, PE pointer/signature scans with positive controls, exact hashes, normalized duplicate-body comparison, then-current ordinary docs, generated source, manual coverage rows, and matching historical reports.
- Evidence ladder: exact bytes/ranges and direct xrefs first; caller ABI and duplicate identity second; source-family and compiler behavior third; original spelling remains inference.
- Strength: the member disposition is not based on adjacency alone. It combines exact identical lowered behavior, one real same-family object-call convention, a second same-family inline/retained pair, correct class/source order, and expected private nonvirtual vtable absence.
- Limitations: stripped symbols cannot prove original capitalization or access specifier text. Private is the narrowest plausible source contract and matches usage. No original header/source or exact linker-era 14.16 compiler is available, so `[16]` is the highest-probability declaration selected from controls, not an exact source fact.

## Evidence Checked

- Live IDA MCP on `supervisor_nexustk_20260713`:
  - `idb_list`, `server_health`, `lookup_funcs(0x005b6870)`, bounded `get_bytes`, target and UID0003O6 instruction/function analysis, xrefs to target/active/Wield helper/callees/global, local function inventory, target-byte searches, vtable read `0x00630608 -> 00 68 5b 00`, and repair-time `stack_frame`/`decompile` controls for SelfSave, MainMenu, Option, Wield, and Emotion packet senders.
  - Target: no IDA function object; UID0003O6 is `sub_5B6800`, size `0x6c`; local range contains no hidden modeled target function.
  - Evidence-time follow-up health at 17:09 EDT remained `ok`; repair-time `idb_list` at 17:32 EDT returned the same active worker and `server_health` returned `ok` with analysis, Hex-Rays, and string cache ready. Client-side PowerShell parsing/schema mistakes were discarded and corrected; they were not MCP/IDB outages and supply no evidence.
- Source-layout controls checked:
  - UID0003O6 stack variables are one-byte `Src` at packet offset `0`, one-byte `var_13` at offset `1`, and cookie `var_4` at frame offset `0x18`; the intervening bytes are not typed as a declared array by `stack_frame`. Hex-Rays nevertheless guesses `_BYTE Src[16]` from the available interval.
  - MainMenu `0x004f7660` has the exact `0x14/-0x14/-0x4` tuple and Hex-Rays `_BYTE Src[16]`, while current accepted formal C++ uses `unsigned char packet[1]`. The disagreement demonstrates that the decompiler rendering cannot serve as original-source proof; the formal declaration is itself a reconstruction and is used only as a control against overclaiming.
  - Option `0x0053e380` has four touched packet bytes at `-0x10..-0xd`, cookie `-4`, a 12-byte interval, and accepted formal `packet[4]`.
  - Wield `0x005b6500` and Emotion `0x005b2f70` have packet bases `-0x84`, cookies `-4`, and accepted 128-byte source forms. The unmodeled Wear retained helper `0x005b6760` was re-read byte-for-byte and by raw `insn_query`: `sub esp,0x84`, packet base `-0x84`, writes offsets `0/1/2`, cookie `-4`, send length `2`, `retn 4`. Active Wear `0x005b66a0` uses frame `0x88`, response local `-0x88`, packet base `-0x84`, cookie `-4`, and Hex-Rays one byte plus a 127-byte tail. This directly corroborates the retained/inlined 128-byte sibling layout.
  - PE `dumpbin /headers` reports x86 and linker version `14.16`. Searches under the workspace, `C:\Users\admin\Desktop\CTools`, and installed Visual Studio roots found no matching 14.16 compiler; only x86 MSVC 14.44 is available.
  - A temporary agent-local 14.44 probe compiled with `/O2 /GS /Oy- /FAsc` and `#pragma strict_gs_check(on)` compared otherwise identical `[1]`, `[2]`, `[4]`, `[8]`, and `[16]` functions. Only `[16]` emitted `sub esp,0x14`, packet base `-0x14`, cookie `-4`; the temporary source, assembly, and object were removed after readback. This is a closest-available compiler control, not exact 14.16 proof.
- Raw PE/Capstone:
  - input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, size `2679296`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, image base `0x00400000`, target raw offset `0x001b5c70`;
  - exact target bytes/hash, predecessor/successor padding, whole-image signature counts, absolute VA/RVA/raw-offset target/interior scans, and decoded direct branch/call scan;
  - positive controls: active handler VA pointer at `0x00630608`, 416 decoded direct calls to `0x00574bb0`, and 489 absolute references to `0x0067a7ec`.
- Evidence-time docs opened: target and every support page named in Current Target State; sibling Wield/Wear method/helper/class/file pages; `by-structure.md`; B workflow/template/score standard; then-current tracker and manual coverage rows.
- Generated source opened read-only: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`, validator command `000000010404`, refreshed `2026-07-13T17:05:31-04:00`, SHA256 `9F6A80517E8EF4E19E93F794B8D8B482857E5DAA5DE39B7E29A163981BAFD938`.
- Negative checks: no direct target xref, no direct branch into any target byte, no VA/RVA/raw-offset target/interior pointer, no helper vtable slot, no factory/constructor route to target, no target string, no target-specific class field, no null guard, no close/reset, no second sent byte, no access beyond packet offset `1`, no identified target local that accounts for smaller-array padding, no original declaration, no exact 14.16 compiler, no alternate target signature, and no then-active/older/special/archive exact report beyond historical B007 at research time.
- Intentionally not done: no IDA mutation, by-* edit, lease, validator, generation, coverage edit, tracker edit, or lifecycle command. No external source/header was found that could prove the exact original spelling.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target remains `[0x005b6870,0x005b68b1)`, 65 bytes. | certain | bytes, final `ret`, hashes | UID0003O7 range | already-present | already-present |
| C02 | Exact target SHA256 is `dc9ae9a3ddef298473476fe633df122c17a9cc7d91d8e266c6f0c77549224c4f`. | certain | MCP/PE bytes | UID0003O7 raw evidence | incorporate | applied |
| C03 | `0x005b686c-0x005b6870` is four `0xcc` predecessor-alignment bytes. | certain | raw bytes | UID0003O7/UID0001MU | already-present | already-present |
| C04 | `0x005b68b1-0x005b68c0` is fifteen `0xcc` successor-alignment bytes. | certain | raw bytes | UID0003O7/UID0001MU | already-present | already-present |
| C05 | Target is one function-shaped source body missing only an IDA function object. | very high | prologue/body/cookie/epilogue | UID0003O7 status/IDA | incorporate | applied |
| C06 | Best signature is private nonvirtual `void SelfSaveInputPane::SendSelfSavePacket()`. | high | Wield `ECX=this`, family order, no args | UID0003O7/UID0000CW | incorporate | applied |
| C07 | Return type is void; incidental `EAX` is not a source result. | high | accepted sender API, varying UID0003O6 exits | UID0003O7 | incorporate | applied |
| C08 | Exact binary facts are frame `0x14`, packet base `-0x14`, cookie `-4`, writes at offsets `0/1`, and send length `1`; highest-probability source is inferred `unsigned char packet[16]`, with `packet[2]` plus padding retained as the bounded runner-up. | high | IDA stack frames/decompiles, same-binary controls, x86 MSVC 14.44 layout matrix, missing exact 14.16 compiler | UID0003O7 formal/UID0003O6 evidence | incorporate | applied |
| C09 | Packet opcode is exact `0x25` / decimal 37. | certain | immediate operand, duplicate tail | UID0003O7/UID0003O6 | already-present | already-present |
| C10 | `PacketBufferWriteUInt8` is value-first and writes a spare zero. | certain | callee ABI, call pushes | UID0003O7/UID0003YJ | incorporate | applied |
| C11 | Explicit `packet[1]=0` must remain although the writer also zeros it. | certain | both exact copies | UID0003O7 formal | incorporate | applied |
| C12 | `g_packetSender` is `Socket *` storage at `0x0067a7ec`. | very high | global/storage/provider docs, 489 refs | UID0003O7/UID0000Q5/UID0001P0 | incorporate | applied |
| C13 | Source send call is member syntax and explicit length one. | very high | `ECX` global load, UID0001HU type | UID0003O7/UID0001HU | incorporate | applied |
| C14 | Target has no input read, null guard, pane close, reset, field write, branch, or second payload byte. | certain | full instruction inventory | UID0003O7 behavior | incorporate | applied |
| C15 | UID0003O6 accepts only one UTF-16 `y`/`Y` before the send. | certain | modeled function/decompile/disassembly | UID0003O6 | already-present | already-present |
| C16 | Target/active 35-byte send cores are identical after only rel32 normalization. | certain | two hashes and wildcard two-hit scan | UID0003O7/UID0003O6 | incorporate | applied |
| C17 | Human UID0003O6 source should call the helper; compiler inlining explains the binary duplicate. | high | C16, Wield/Wear source family | UID0003O6 formal | incorporate | applied |
| C18 | Target has zero ordinary direct/pointer/interior routes. | certain | MCP + PE + Capstone scans | UID0003O7 liveness | incorporate | applied |
| C19 | Active vtable, queue calls, and sender references are positive controls for negative scans. | certain | `0x00630608`, 416, 489 counts | UID0003O7 liveness | incorporate | applied |
| C20 | Wield's sole helper call prepares `ECX=this` despite no callee `ECX` read. | certain | callsite `0x005b64e6`, xref total one | UID0003O7 family evidence | incorporate | applied |
| C21 | Wear supplies a second adjacent inline/out-of-line helper-family parallel. | high | UID0001MT/UID0002YP bytes/docs | UID0003O7 family evidence | incorporate | applied |
| C22 | File-static, class-static, and virtual dispositions are weaker/rejected. | high | family ABI and vtable absence | target rejected alternatives | reject-stale | applied |
| C23 | No-code/covered-by disposition is rejected; target remains a source definition. | very high | coherent unique source body | UID0003O7 | reject-invalid | applied |
| C24 | Duplicate handwritten active/helper packet bodies are rejected. | high | exact normalized identity/inlining | UID0003O6/UID0003O7 | reject-stale | applied |
| C25 | Owner/emitter remain UID0000CW, reconstructable true. | very high | class behavior and current route | UID0003O7 metadata | already-present | already-present |
| C26 | Immediate source route remains UID0000NM standalone SelfSave file. | high | complete ordered unit | UID0000NM/UID0003O7 | already-present | already-present |
| C27 | Position `30` and `Nested:0` remain exact. | certain | current child order/range | UID0003O7 metadata | already-present | already-present |
| C28 | Target moves `87/88 -> 92/92`; Item Summary becomes source-current and labels array capacity inferred. | high | all resolved blockers plus source-layout confidence cap | UID0003O7 metadata | incorporate | applied |
| C29 | UID0003O6 moves `90/92 -> 92/93` and gets the exact source call block. | high | active route and inline proof | UID0003O6 | incorporate | applied |
| C30 | UID0000CW moves `90/92 -> 91/93` and declares the private member. | high | class/vtable/family evidence | UID0000CW | incorporate | applied |
| C31 | UID0001MU stays false/non-emitting but moves `88/89 -> 91/92` and records source/binary relation. | high | complete exact child inventory | UID0001MU | incorporate | applied |
| C32 | UID0000NM moves `89/91 -> 91/92` and replaces stale static/no-call prose. | high | resolved source unit | UID0000NM | incorporate | applied |
| C33 | UID0002N8/UID0003HM scores and compiler-only formal markers remain; prose explains nonvirtual absence. | very high | exact tables/slot inventory | vtable support | incorporate | applied |
| C34 | UID0003O5/UID0001KQ scores/formal bodies remain; stale file-static cross-prose is historicalized. | high | constructor/factory roles | constructor/factory support | historicalize | applied |
| C35 | UID0003YJ/UID0001HU scores/formal policies remain; add exact target consumer evidence and correct API syntax. | very high | callee ABI/calls | provider support | incorporate | applied |
| C36 | UID0000Q5/UID0001P0 scores/formal storage remain; add both target callsites and source member syntax. | very high | loads/xrefs | global support | incorporate | applied |
| C37 | Generated callback proof shows one member definition, one active source call, and no duplicate static/free form. | high | command `000000010487` generated readback | generated readback only | incorporate | applied |
| C38 | Exact stale/absent manual coverage text is supplied read-only below. | certain | row-by-row inspection | supervisor-owned coverage | already-present | already-present |
| C39 | IDA may safely create/name/type the target after approval; no DB edit occurs here. | high | exact boundaries/signature | IDA recommendation | not-applicable | excluded-with-reason |
| C40 | Historical no-route, inferred spelling, grouping caveat, rejected alternatives, and exact binary facts must be retained. | certain | full evidence matrix | all changed docs | incorporate | applied |

Callback claim-by-claim destination proof:

| Claim | Applied/readback proof |
| --- | --- |
| C01 | UID0003O7 readback retains `[0x005b6870,0x005b68b1)` and its 65-byte range; validator `000000010460` passed. |
| C02 | UID0003O7 now records exact SHA256 `dc9ae9a3ddef298473476fe633df122c17a9cc7d91d8e266c6f0c77549224c4f`; validator `000000010460` passed. |
| C03 | UID0003O7 and UID0001MU retain the four predecessor `0xcc` bytes outside the target; validators `000000010460` and `000000010471` passed. |
| C04 | UID0003O7 and UID0001MU retain the fifteen successor `0xcc` bytes outside the target; validators `000000010460` and `000000010471` passed. |
| C05 | UID0003O7 explicitly classifies the coherent prologue/body/cookie/epilogue as source despite the missing IDA function object; validator `000000010460` passed. |
| C06 | UID0003O7 emits the exact private nonvirtual member definition and UID0000CW declares it under `private:`; validators `000000010460` and `000000010466` passed. |
| C07 | UID0003O7 formal and behavior prose use `void` and retain the incidental-register rejection; validator `000000010460` passed. |
| C08 | UID0003O7, UID0003O6, UID0000NM, UID0003YJ, and UID0001P0 separate exact frame/base/cookie/write/send facts from inferred `[16]` and preserve `[2]` plus padding as the bounded runner-up; validators `000000010460`, `000000010462`, `000000010474`, `000000010481`, and `000000010486` passed. |
| C09 | UID0003O7 and UID0003O6 retain exact opcode `0x25`; validators `000000010460` and `000000010462` passed. |
| C10 | UID0003O7 uses value-first `PacketBufferWriteUInt8(0x25, packet)`, and UID0003YJ records both exact consumer callsites and spare-zero behavior; validators `000000010460` and `000000010481` passed. |
| C11 | UID0003O7 formal retains explicit `packet[1] = 0;`; generated readback after `000000010487` finds it exactly once. |
| C12 | UID0003O7, UID0000Q5, and UID0001P0 retain `Socket *` and exact storage `0x0067a7ec`; validators `000000010460`, `000000010485`, and `000000010486` passed. |
| C13 | UID0003O7 and UID0001HU use/record member syntax with explicit length one; validators `000000010460` and `000000010482` passed. |
| C14 | UID0003O7 retains the complete negative behavior inventory; validator `000000010460` passed. |
| C15 | UID0003O6 retains one-character UTF-16 `y`/`Y` gating before its source call; validator `000000010462` passed. |
| C16 | UID0003O7 and UID0003O6 retain the active hash, target hash, rel32-normalized shared hash, and two-hit interpretation; validators `000000010460` and `000000010462` passed. |
| C17 | UID0003O6 emits exactly one `SendSelfSavePacket();` source call while its evidence preserves the exact inlined release body; validator `000000010462` and generated command `000000010487` passed/read back. |
| C18 | UID0003O7 retains the exhaustive zero ordinary/pointer/interior route matrix; validator `000000010460` passed. |
| C19 | UID0003O7 retains active vtable pointer `0x00630608`, 416 queue-call, and 489 sender-reference positive controls; validator `000000010460` passed. |
| C20 | UID0003O7 retains Wield callsite `0x005b64e6` and `ECX=this` family evidence; validator `000000010460` passed. |
| C21 | UID0003O7 retains the Wear adjacent inline/out-of-line family parallel; validator `000000010460` passed. |
| C22 | UID0003O7 and UID0000CW reject file-static/class-static/virtual alternatives while retaining historical file-static evidence under explicit historical labels; validators `000000010460` and `000000010466` passed. |
| C23 | UID0003O7 remains reconstructable source with a full formal body; generated readback after `000000010487` has no target Empty Emitter Marker. |
| C24 | UID0003O6 emits only the source call and UID0003O7 emits the sole packet body; generated readback after `000000010487` finds one opcode writer and one member send. |
| C25 | UID0003O7 readback retains owner/emitter `0000CW` and `RECONSTRUCTABLE:TRUE`; validator `000000010460` passed. |
| C26 | UID0000NM retains standalone `NexusTK/ui/dialogs/` routing and full `0/10/20/30/40/50/60` order; validator `000000010474` passed. |
| C27 | UID0003O7 readback retains position `30` and `Nested:0`; validator `000000010460` passed. |
| C28 | UID0003O7 is `92/92`, has the accepted source-current Item Summary, and preserves the capacity inference cap; validator `000000010460` passed. |
| C29 | UID0003O6 is `92/93` with the exact accepted formal call block; validator `000000010462` passed. |
| C30 | UID0000CW is `91/93` with the exact accepted complete class block; validator `000000010466` passed. |
| C31 | UID0001MU is `91/92`, false/non-emitting with blank formal/emitter/position, and records one source call/definition versus two exact binary bodies; validator `000000010471` passed. |
| C32 | UID0000NM is `91/92` and its current sections use private-member/inlining/member-sender source shape while historical static/no-call material is labeled; validator `000000010474` passed. |
| C33 | UID0002N8 and UID0003HM retain scores/formal compiler-only markers and explain why the private nonvirtual helper has no slot; validators `000000010475` and `000000010477` passed. |
| C34 | UID0003O5 and UID0001KQ retain scores/formal bodies/no-route evidence and historicalize stale helper-shape prose; validators `000000010478` and `000000010479` passed. |
| C35 | UID0003YJ and UID0001HU retain scores/formal policies and now record exact SelfSave calls, value-first/member ABI, one-byte send, and capacity distinction; validators `000000010481` and `000000010482` passed. |
| C36 | UID0000Q5 and UID0001P0 retain scores/formal storage, 489-reference/five-write evidence, and record both lowered SelfSave load/call pairs plus one human source relation; validators `000000010485` and `000000010486` passed. |
| C37 | Generated `SelfSaveInputPane.cpp` header is command `000000010487`; exact counts are one class, helper declaration, helper call, helper definition, `[16]` declaration, opcode writer, byte-one clear, and member send, with all required negatives at zero. |
| C38 | The exact manual supervisor-owned coverage replacement/addition text remains unchanged below; B004 did not edit any manual coverage file. |
| C39 | The IDA create/name/type recommendation remains documented, but the callback authorized no IDA database edit; it is therefore excluded with reason and no MCP mutation was performed. |
| C40 | All thirteen ordinary destinations preserve historical no-route, inferred spelling/grouping, rejected alternatives, exact binary/provider/global facts, and the explicit `[2]`-plus-padding confidence cap; their scoped validators passed. |

## Positive Evidence Summary

- Exact 65-byte coherent function body, unique whole-image signature, exact cookie mechanics, and clean padding boundaries prove a real retained source body.
- The active handler's send core and target core become byte-identical after normalizing only position-dependent call displacements; no semantic instruction differs.
- Wield's actual object call proves this source family uses nonvirtual instance packet helpers even when a helper never reads `this`. Wear corroborates the adjacent retained/inlined source shape.
- Source-layout evidence is positive but bounded: raw SelfSave facts establish the tuple and touched bytes, Wield/Wear/Emotion corroborate intentional large fixed packet locals, and the closest x86 MSVC probe reproduces the target tuple only for `[16]`; MainMenu/Option controls prevent upgrading that inference to certainty.
- Current class/file/emitter order already places the target exactly where an out-of-line private member definition belongs.
- Accepted provider docs independently resolve value-first packet writing, `Socket *g_packetSender`, and Socket member queue/send syntax.

## IDA MCP Facts

- Function/range facts: `lookup_funcs(0x005b6870)` reports not a function; `insn_query` decodes 23 instructions from `push ebp` through `ret`. UID0003O6 is modeled at `0x005b6800`, size `0x6c`, with five basic blocks and cyclomatic complexity four.
- Exact target bytes:

```text
55 8B EC 83 EC 14 A1 24 2F 67 00 33 C5 89 45 FC
8D 45 EC 50 6A 25 E8 F5 EA FB FF 8B 0D EC A7 67
00 8D 45 EC 83 C4 08 C6 45 ED 00 6A 01 50 E8 0D
E3 FB FF 8B 4D FC 33 CD E8 82 0E 01 00 8B E5 5D
C3
```

- Target instruction semantics by address:

| Address | Instruction / meaning |
| --- | --- |
| `0x005b6870-0x005b687d` | frame, `sub esp,0x14`, security cookie at `[ebp-4]` |
| `0x005b6880-0x005b6886` | packet address `[ebp-0x14]`, value `0x25`, call writer `0x00575380` |
| `0x005b688b` | load `ECX = [0x0067a7ec]`, the Socket sender object |
| `0x005b6891-0x005b6897` | recover packet pointer, caller cleanup for cdecl writer, explicit byte-one zero |
| `0x005b689b-0x005b689e` | push length one and packet pointer, call `0x00574bb0` with `ECX` sender |
| `0x005b68a3-0x005b68b0` | cookie check and plain `ret` |

- Data/table/padding facts: four leading and fifteen trailing `0xcc`; no overlap. Vtable cell `0x00630608` contains little-endian pointer `0x005b6800`; no cell contains `0x005b6870`.
- Xref facts: target start and every target byte have zero external inbound xrefs; active handler has one data route from the primary vtable; Wield helper has one code route from `0x005b64e6`.
- Vtable/global/type facts: target is private/nonvirtual under the recommended model; no vtable slot is required. `0x0067a7ec` is the shared `Socket *` sender storage.
- Negative IDA facts: no hidden local function, caller, string, table, factory edge, constructor edge, or mid-body route was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b67c0-0x005b6800` | UID0003O5 | constructor definition | true | UID0000CW | `88/90` | unchanged source-ready child |
| `0x005b6800-0x005b686c` | UID0003O6 | active virtual confirmation method | true | UID0000CW | `90/92 -> 92/93` | source calls private helper; binary inlines it |
| `0x005b686c-0x005b6870` | UID0000VN ignored row | alignment | false | aggregate | `100` | unchanged four `0xcc` bytes |
| `0x005b6870-0x005b68b1` | UID0003O7 target | private nonvirtual packet method | true | UID0000CW | `87/88 -> 92/92` | retained out-of-line source definition; `[16]` capacity inferred from ranked controls |
| `0x005b67c0-0x005b68b1` | UID0001MU | non-emitting method-island index | false | UID0000CW | `88/89 -> 91/92` | exact inventory only |
| `0x005aa140-0x005aa1bf` | UID0001KQ | retained factory | true | UID0000NM | `87/88` | unchanged, no packet send |
| `0x006305c0-0x00630648` | UID0002N8 | compiler vtable/RTTI data | true marker | UID0000CW | `91/94` | unchanged formal disposition; prose sync |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b6870` | zero direct callers/xrefs | out-of-line target has no ordinary entry route in this image |
| every byte `0x005b6870-0x005b68b0` | zero external inbound refs | no interior thunk/table route |
| `0x00630608 -> 0x005b6800` | SelfSave primary vtable slot | active UID0003O6 route positive control |
| `0x005b6886` and `0x005b6840` | calls `0x00575380` | target and active copies write opcode through same byte writer |
| `0x005b689e` and `0x005b6858` | calls `0x00574bb0` | target and active copies send one byte through same Socket method |
| `0x005b64e6 -> 0x005b6500` | sole Wield helper caller | callsite prepares `ECX=ESI` object before nonvirtual helper call |
| `0x0067a7ec` | 489 absolute refs | sender-global positive control and broad provider role |
| `0x00574bb0` | 416 decoded direct calls | queue/send scan positive control |

## Documentation Evidence And IDA Status

- Supporting current docs: exact class hierarchy/vtable, constructor/factory, packet writer, Socket sender method, and global storage facts all agree with the recommended owner and behavior.
- Historical pre-callback stale/incomplete docs: target, active handler, aggregate, class, file, and vtable prose encoded “file-local static” and “must not call” as conclusions. They also encoded two-byte source buffers and free-function sender calls. Constructor/factory cross-prose repeated the historical static lead. The callback corrected or explicitly historicalized these statements in every bounded destination.
- IDA status: active handler and provider callees are modeled; target and Wear retained helper are not. IDA omission is documented and may be repaired separately after supervisor approval.
- Historical pre-callback generated state: `SelfSaveInputPane.cpp` contained one UID0003O6 definition, one static target helper, two full queue/send packet bodies, two `char packet[2]`, no target Empty Emitter Marker, and no member declaration. Final command `000000010487` replaced that source-disposition-stale form; current generated counts are recorded under Validator Results.
- Manual coverage state: target/active/aggregate/class/file rows preserve the stale static/no-call decision; provider coverage also has preexisting score/owner drift. Exact read-only replacement/addition text appears below.

## Ranked Ownership Analysis

### 1. UID0000CW SelfSaveInputPane

- Evidence for: class-specific fixed opcode, exact adjacency after the class virtual method, same class emitter order, Wield/Wear member-helper convention, target name/behavior, and no cross-feature callers.
- Evidence against: target does not read object state and no direct target call survives.
- Decision: direct semantic owner and emitter. Lack of object-state reads is normal for a member whose current implementation needs no fields; the source call is inlined.

### 2. UID0000NM SelfSaveInputPane source file

- Evidence for: current complete standalone source unit emits class, constructor, active method, target, vtable/type dispositions, and factory in deterministic order.
- Evidence against: historical command-input grouping could have placed the whole family in a broader translation unit.
- Decision: immediate source route, not the semantic class owner. Keep current path until whole-family evidence supports a coordinated move.

### 3. UID0000ID CommandInputPanes or provider ownership

- Evidence for: neighborhood/grouping history for CommandInputPanes; Socket/PacketBuffer/global providers implement dependencies.
- Evidence against: no evidence supports moving only this child; providers do not own feature packet construction.
- Decision: reject as direct target owner/emitter. Preserve UID0000ID only as a whole-unit historical grouping caveat.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. Keep UID0000NM and `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`.
- Likely full contents: existing ordered class/constructor/confirm/helper/vtable/type/factory unit.
- Candidate related items rejected: moving only UID0003O7, moving providers into this file, or moving this source into Socket/PacketBuffer.
- Standalone inference: strongest current reconstructable route; broad grouping remains bounded historical uncertainty only.

## Source Placement

- Recommended placement: private declaration in `SelfSaveInputPane`, out-of-line definition in `SelfSaveInputPane.cpp`, active call inside `SelfSaveInputPane::OnConfirmInput`.
- Fit: exact object/source family, deterministic current emission positions `0/10/20/30/40/50/60`, and member-helper convention.
- Rejected: unnamed namespace/file-static, central ProtocolSend, Socket, PacketBuffer, SelfSaveOKPane, BlockListen, and target-only CommandInputPanes migration.
- Remaining uncertainty: original translation-unit grouping is not symbol-proven. It does not affect current owner/emitter or formal method shape.

## Range / Split / Padding / Reclassification Analysis

- Exact range: target 65 bytes, decimal verified with `int_convert.py`; no end change.
- Predecessor: UID0003O6 ends at `0x005b686c`; four `0xcc` bytes end immediately before target.
- Successor: target `ret` at `0x005b68b0`; fifteen `0xcc` bytes lead to BlockListen constructor at `0x005b68c0`.
- Children: no new page, split, merge, or padding child. Keep UID0001MU as false/non-emitting exact index.
- Reclassification: change source declaration/disposition only: file-static retained helper -> private nonvirtual retained member definition. Binary range kind remains retained raw function-shaped code.

## Negative Evidence Summary

- No ordinary code/data route to target or any target interior byte.
- No vtable slot; this rejects virtual, not private nonvirtual, membership.
- No object-state read; this rejects a state-dependent implementation, not an implicit object calling convention.
- No target-specific string, field, factory edge, constructor edge, pointer table, import/export, or callback registration.
- No second transmitted byte; buffer capacity and scratch terminator are not protocol length.
- No instruction accesses packet offset `2` or above, no original source declaration survives, and no exact 14.16 compiler is installed. These negatives prevent promoting inferred `[16]` to certainty even though the closest compiler control favors it.
- No evidence for central network ownership, SelfSaveOKPane ownership, or successor BlockListen ownership.
- No original symbol/header/source file. Exact spelling remains inferred, but the family name and behavior make `SendSelfSavePacket` the narrowest defensible name.

## IDA Rename / Type / Comment Recommendations

- After approval, define one function at `0x005b6870-0x005b68b1` and name it `SelfSaveInputPane::SendSelfSavePacket` or IDA-compatible equivalent.
- Apply source type equivalent to a void `__thiscall` member with implicit `SelfSaveInputPane *this` and no explicit parameters. Do not add a stack parameter or integer result.
- Comment: private nonvirtual SelfSave packet member; writes opcode `0x25` into a highest-probability inferred 16-byte local scratch buffer, explicitly clears byte one, and sends length one through `g_packetSender`; exact binary facts are frame `0x14`, packet base `-0x14`, cookie `-4`, and writes at offsets `0/1`; no surviving direct route because the active virtual handler contains the exact compiler-inlined body.
- Keep `0x005b6800` as the active virtual `SelfSaveInputPane::OnConfirmInput` and document its source helper call/inlined release realization.
- IDA edits are safe in principle because boundaries are exact, but none was requested or performed in the research pass or authorized implementation callback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Three exact managed destination blocks were required and are now applied. These remain the only C++ drafts in this report.
- Target UID0003O7 exact managed replacement block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfSaveInputPane::SendSelfSavePacket()
{
    unsigned char packet[16];

    PacketBufferWriteUInt8(0x25, packet);
    packet[1] = 0;

    g_packetSender->QueueAndSendPacket(packet, 1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0003O6 exact managed replacement block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfSaveInputPane::OnConfirmInput()
{
    if (TextLength() != 1)
        return;

    wchar_t response = 0;
    CopyText(&response, 1);
    if (response != L'y' && response != L'Y')
        return;

    SendSelfSavePacket();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0000CW exact complete managed replacement block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfSaveInputPane : public CharInputPane
{
public:
    SelfSaveInputPane();

protected:
    virtual void OnConfirmInput();

    static const int kSelfSavePromptStringId = 0x26;

private:
    void SendSelfSavePacket();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior parity: release optimization can inline the private call into UID0003O6 while retaining the externally linked out-of-line member body. The target definition preserves exact opcode, redundant zero, sender object, and one-byte send. Its `unsigned char packet[16]` is the selected highest-probability source declaration from the ranked controls; the binary proves the 16-byte available interval but not declaration size in isolation.
- Period/source shape: ordinary private nonvirtual method, fixed-size local array, simple early returns, and no decompiler temporaries or explicit `this` are plausible mid-2000s C++.
- Inferred names/types: `SendSelfSavePacket`, `response`, and `packet`; accepted provider names are used rather than `sub_575380`, `dword_67A7EC`, and `sub_574BB0`.
- Style: braces and declaration/access layout match the existing accepted SelfSave class and method blocks; no modern `override`, `auto`, span, lambda, or scoped enum is introduced.
- Third-party import directive: not applicable; this is NexusTK project code, not a static third-party source embed.

## Final Recommendation

- C01-C40 were applied or explicitly excluded with reason after exact-artifact supervisor acceptance.
- The callback retained the exact target path/range/UID, owner/emitter, reconstructable state, position, and Nested while applying the accepted source disposition, score, Item Summary, prose, and formal block.
- The target formal block now uses inferred `unsigned char packet[16]`; exact frame/base/cookie/write/send facts remain separate, and `[2]` plus compiler padding remains the confidence-capping runner-up rather than claimed exact source proof.
- UID0003O6 now emits the exact call block while preserving its observed inlined binary tail as evidence.
- UID0000CW now contains the private declaration, and UID0001MU/UID0000NM plus bounded vtable/provider/global support are synchronized.
- UID0000ID, UID0003O5 formal body/score, UID0001KQ formal body/score, UID0002N8/UID0003HM formal markers/scores, UID0003YJ formal policy/score, UID0001HU formal body/score, and global/storage formal bodies/scores remain unchanged except for the explicitly accepted prose synchronization.
- Outside assignment scope: correcting Wield/Wear static/int formal source is a separately evidenced sibling issue. This report uses their direct ABI as comparative proof but does not request those pages be changed.

## Recommended Target Doc Changes

- Callback status: every accepted target change below is applied and validated; the wording is retained as the exact accepted destination specification.
- Target path: `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md`; no path rename.
- Metadata: `COMPLETION:92`, `CONFIDENCE:92`; retain owner `0000CW`, true, emitter `0000CW`, position `30`, `Nested:0`.
- Exact Item Summary replacement: `Private nonvirtual SelfSaveInputPane packet member retained out of line after its call was inlined into OnConfirmInput; exact 65-byte body uses opcode 0x25, frame/base/cookie tuple 0x14/-0x14/-4, writes offsets 0/1, explicitly clears byte one, and sends length one through Socket-owned g_packetSender; ranked same-binary and compiler controls select inferred unsigned char packet[16] while preserving smaller-array-plus-padding as a confidence cap, and exhaustive no-route evidence retains active-vtable/queue/global positive controls.`
- Formal C++: the UID0003O7 block above was applied exactly.
- The page incorporates the full exact bytes/hash/instruction table, normalized duplicate proof, Wield/Wear family ABI, source call/inlining explanation, provider syntax, no-route matrix, and score rationale.
- Historical facts preserved: B007 range repair; all no-route scans; inferred spelling; standalone-versus-CommandInputPanes caveat; no vtable slot; constructor/factory distinctions; rejected Socket/PacketBuffer/SelfSaveOK/BlockListen ownership.
- Historical/stale claims corrected without silent deletion: file-static was a prior inference based on no observable `this` read; current family callsite evidence supersedes it. The old “do not rewrite active as a call” rule confused human source with optimized binary realization.

## Recommended Support Doc Changes

- Callback status: every change in the bounded support list below is applied and validated; verify-only pages outside that list remain unchanged.
- `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md`:
  - is `92/93` with the exact UID0003O6 block;
  - retains all input/vtable/early-return/binary-tail evidence;
  - states the source call was inlined and lists exact active core hash `78de75976ffd7c0f4e8b3a5aaa654f693d04f3ec56a9745de3917306c8e17988` and normalized shared hash;
  - replaces two-byte/free-function source wording while preserving exact observed callsites and separates exact inlined frame/base/cookie/writes/send facts from inferred `[16]` source capacity.
- `by-class/SelfSaveInputPane.md`:
  - is `91/93` with the exact complete class block;
  - preserves inheritance, constructor, prompt constant, `virtual` (not `override`), layout/vtable/destructor facts, `[[CHILDREN]]`, positions, factory, and grouping caveat;
  - replaces all current file-static/no-member claims with the private nonvirtual/inlined-call result while historicalizing prior claims.
- `by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md`:
  - is `91/92` and retains false, blank emitter/position/formal C++, owner `0000CW`, `Nested:0`, ranges, padding, and exact inventory;
  - explains that exact children remain separate binary bodies while human source has one private definition and one call.
- `by-file/SelfSaveInputPane.md`:
  - is `91/92` and retains path and complete order `0/10/20/30/40/50/60`;
  - replaces current static/no-call/two-byte/free-sender prose with private-member, inlining, highest-probability inferred 16-byte source scratch, exact frame facts, confidence cap, and member sender syntax;
  - preserves constructor/factory no-route, vtable generated disposition, and coordinated-only CommandInputPanes caveat.
- `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md` and `by-type/by-vtable/SelfSaveInputPaneVtables.md`:
  - retain unchanged scores/formal markers;
  - preserve every slot/RTTI/store/compiler ABI fact;
  - historicalize the prior “must not be rewritten to call”/file-static inference and state that no helper slot is expected because the member is private and nonvirtual, while the active slot still points to the inlined binary realization.
- `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md` and `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`:
  - retain unchanged scores/formal bodies;
  - historicalize stale helper cross-prose and use private nonvirtual member in current prose while preserving all constructor/factory evidence and no-route caveats.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`:
  - retains unchanged score/formal policy;
  - records target and active callsites as exact value-first one-byte consumers, exact caller frame/base/cookie and touched offsets, inferred `[16]` source capacity, and redundant explicit byte-one zero without changing writer ownership.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`:
  - retains unchanged score/formal body;
  - records calls at `0x005b6858`/`0x005b689e`, explicit one-byte payload, and accepted source member syntax while preserving Socket ownership, queue copy, command 8, and local terminator behavior.
- `by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`:
  - retain unchanged scores/formal storage;
  - record SelfSave loads at `0x005b6845`/`0x005b688b`, two lowered callsites from one human helper call/definition, and `Socket *` member syntax while preserving 489-xref and Socket-lifetime evidence.
- `by-file/CommandInputPanes.md`, UID0001KQ coverage semantics, UID0003O5 formal source, Wield/Wear pages, and other provider/class pages: verify-only; no change requested beyond the named bounded support list.

## Score And Metadata Recommendation

- Historical pre-callback target: `87/88`, owner/emitter `0000CW`, true, position `30`, `Nested:0`.
- Current implemented target: `92/92`; all non-score metadata remains unchanged.
- Target completion rises five points because function shape, exact full hash, full route matrix, normalized duplicate identity, ranked source-layout decision, member signature, inlining relationship, correct sender syntax, formal block, and support plan are now closed.
- Target confidence rises four points because Wield supplies direct same-family object-call ABI, Wear corroborates the duplicate-inline/retained pattern, and the comparable compiler favors `[16]`. It remains at 92 because no original symbol/header survives, the target call itself was inlined away, exact 14.16 compilation is unavailable, and smaller-array-plus-padding cannot be eliminated absolutely.
- Support score movement is limited to pages whose source model materially changes: UID0003O6 `92/93`, UID0001MU `91/92`, UID0000CW `91/93`, UID0000NM `91/92`. Provider/vtable/constructor/factory scores remain unchanged.
- Score-improvement attempts:
  - no-route: exhausted direct xrefs, all-byte inbound refs, rel32, VA, RVA, raw-offset, signature, vtable, factory, constructor, and positive controls; result is resolved liveness evidence, not a blocker;
  - declaration style: audited Wield callsite and Wear parallel; result private nonvirtual member;
  - duplicate source: normalized exact cores and searched whole image; result one source call plus retained definition;
  - local size: separated exact frame/base/cookie/writes/send facts from declaration size, audited IDA stack-variable boundaries and same-binary packet controls, fingerprinted linker 14.16, searched unsuccessfully for exact 14.16 `cl.exe`, and compiled a closest-available x86 MSVC 14.44 matrix; result is inferred `[16]` as highest probability with `[2]` plus padding retained as the bounded runner-up;
  - provider syntax/type: re-read accepted writer/sender/global docs and live call setup; result value-first writer and Socket member send;
  - source placement: audited complete class/file/factory/vtable unit and broader grouping; result keep UID0000NM;
  - name: compared family names and rejected generated/overbroad alternatives; result `SendSelfSavePacket` with bounded inference caveat.

## Open Questions With Attempted Resolution

- Is the target live? No ordinary binary entry route survives. Exhaustive current scans prove that negative. Source-level liveness is resolved as an inlined call with retained out-of-line definition; runtime entry liveness remains absent and is preserved as evidence.
- Static or member? Resolved to private nonvirtual member by Wield's explicit object setup, Wear parallel, and class-local order.
- Why no target call? Resolved by exact normalized inline identity; optimized output need not retain the call instruction.
- Why retain an out-of-line body? A non-inline member has linkable out-of-line definition semantics, and this compiler/source neighborhood demonstrably retains adjacent helpers. Exact original compiler flags are unavailable but no stronger competing source shape explains all evidence.
- Buffer size? The binary alone proves frame `0x14`, packet base `-0x14`, cookie `-4`, writes at offsets `0/1`, and send length one. Same-binary controls prove interval-only reasoning is insufficient, while the closest x86 MSVC matrix reproduces the exact tuple only for `[16]`. The implementation-ready choice is therefore inferred `unsigned char packet[16]`, not a proven declaration; `packet[2]` plus exact-toolchain padding is the bounded runner-up and caps confidence rather than remaining an open blocker.
- Return type? Resolved to void from accepted provider contract and unstable incidental registers.
- Original name/access spelling? `SendSelfSavePacket` and private are strongest inference, not symbol proof. No current evidence can recover capitalization or declaration order beyond that; this caps confidence but does not block C++.
- Standalone versus CommandInputPanes? Keep current complete standalone unit. Only a future whole-family source/header artifact could justify coordinated migration; no target-specific work remains blocked.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only rows inspected: `by-memory/-coverage-report.md` UID0001MU, UID0003O5, UID0003O6, UID0003O7, UID0001KQ, UID0002N8, UID0001HU, UID0001P0, and absent UID0003YJ; `by-class/-coverage-report.md` UID0000CW; `by-file/-coverage-report.md` UID0000NM; `by-type/by-vtable/-coverage-report.md` UID0003HM; `by-global/-coverage-report.md` UID0000Q5.
- UID0003O5, UID0001KQ, and UID0002N8 rows do not assert the stale static/no-call result and need no replacement. All other affected stale/absent rows should use the exact text below.
- In `by-memory/-coverage-report.md`, replace UID0001MU/UID0003O6/UID0003O7 rows in the existing `0x005b67c0` island with:

```text
    - [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md) 0x005b67c0-0x005b68b1 | class method island | SelfSaveInputPane : ignored : 91% : very-strong : Non-emitting exact SelfSave method inventory; source has one private nonvirtual SendSelfSavePacket definition and one OnConfirmInput call, while the release binary retains the out-of-line body and inlines its exact send tail into the active handler; constructor, four-byte alignment, helper boundary, no-route evidence, and child ownership remain explicit.
        - [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) 0x005b6800-0x005b686c | virtual method | SelfSaveInputPane::OnConfirmInput : reconstructable : 92% : very-strong : Active vtable-routed one-character y/Y confirmation source calls private SendSelfSavePacket; exact release bytes inline opcode 0x25, frame/base/cookie tuple 0x18/-0x14/-4, writes offsets 0/1, explicit byte-one zero, and one-byte Socket send, while ranked controls select inferred packet[16] source capacity.
        - [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) 0x005b6870-0x005b68b1 | retained private member body | SelfSaveInputPane::SendSelfSavePacket : reconstructable : 92% : very-strong : Exact 65-byte private nonvirtual member definition retained after its active call was inlined; exact frame/base/cookie tuple is 0x14/-0x14/-4 with writes at offsets 0/1 and length-one send through Socket *g_packetSender; same-binary and closest-compiler controls select inferred unsigned char packet[16] while retaining smaller-array padding as a confidence cap, and exhaustive zero-route evidence includes active-vtable, queue-call, and sender-global positive controls.
```

- In `by-class/-coverage-report.md`, replace UID0000CW with:

```text
- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) : reconstructable : 91% : very-strong : CharInputPane-derived self-save confirmation class with exact 0x108 inherited extent, prompt id 0x26, virtual OnConfirmInput, private nonvirtual SendSelfSavePacket, source-call/release-inlining relationship, constructor/factory route, and compiler-generated destructor/vtable disposition.
```

- In `by-file/-coverage-report.md`, replace UID0000NM with:

```text
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) : reconstructable : 91% : very-strong : Immediate NexusTK/ui/dialogs/SelfSaveInputPane.cpp route for class, constructor, active confirmation method, retained private packet-member definition, generated vtable/RTTI dispositions, and factory; source has one helper call/definition while exact release output inlines the send tail, with prompt id 0x26, opcode 0x25, no-route caps, and coordinated-only CommandInputPanes caveat preserved.
```

- In `by-type/by-vtable/-coverage-report.md`, replace UID0003HM with:

```text
- [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) : reconstructable : 90% : very-strong : Source-local index over exact UID0002N8 primary/EventHandler/TimerHandler views; active OnConfirmInput occupies the class-specific virtual slot, private nonvirtual SendSelfSavePacket correctly has no slot, and complete RTTI/store/implicit-destructor/adjustor/no-handwritten-table dispositions are documented.
```

- In `by-global/-coverage-report.md`, replace UID0000Q5 with:

```text
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) : reconstructable : 90% : very-strong : Canonical Socket * outbound packet sender at 0x0067a7ec with Socket-owned lifetime, 489-reference fanout, canonical source storage, alias rejection, and exact SelfSave active/retained one-byte send consumers documented.
```

- In `by-memory/-coverage-report.md`, replace UID0001HU and UID0001P0 with:

```text
    - [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) 0x00574bb0-0x00574c13 | Socket member helper | Socket::QueueAndSendPacket : reconstructable : 91% : very-strong : Socket-owned queued-copy send funnel with exact allocation/copy/local-terminator/command-8 dispatch behavior, 416 direct calls, and SelfSave active/retained one-byte member-call consumers at 0x005b6858/0x005b689e.
    - [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) 0x0067a7ec-0x0067a7f0 | global pointer | g_packetSender : reconstructable : 87% : very-strong : Socket-owned outbound packet sender storage with canonical by-global definition, zero initialization, Socket lifetime writes, 489 xrefs, broad feature/UI reads, and exact SelfSave loads at 0x005b6845/0x005b688b.
```

- In `by-memory/-coverage-report.md`, add UID0003YJ immediately under the existing PacketBuffer helper aggregate at the address-sorted `0x00575380` position:

```text
        - [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) 0x00575380-0x00575470 | scalar writer family | PacketBufferScalarBigEndianWriteHelpers : reconstructable : 87% : very-strong : Five value-first scalar big-endian writers with exact widths/xrefs and local spare-zero semantics; SelfSave calls at 0x005b6840/0x005b6886 use UInt8 for opcode 0x25 with exact packet bases at -0x14, writes offsets 0/1, inferred packet[16] source capacity from ranked controls, an explicit redundant byte-one zero, and one-byte send.
```

- Reason B004 must not apply these directly: all manual `by-*/-coverage-report.md` files are supervisor-owned under the current workflow. Generated coverage refresh does not replace this row audit. No auto-generated tracker row text is proposed.

## Follow-Up Actions

- Implementation, scoped validation, lease release, and waited generated readback are complete; no accepted implementation item remains.
- Report review, validation, execution, counting, current path, move, archive, and manual coverage application are external supervisor/validator-owned state. This artifact neither asserts nor directs those lifecycle outcomes.
- B004 performed no IDA database mutation, `execute_report`, report-lifecycle probe, move, or archive command. The optional IDA function/name/type recommendation remains outside this callback by explicit scope.

## Confidence

- Recommendation confidence: high/very strong. Exact binary behavior is certain; private nonvirtual source disposition is strongly triangulated rather than symbol-proven.
- Score confidence: high. `92/92` reflects closure of all named current blockers while retaining appropriate caps for stripped original spelling, absent surviving call instruction, and inferred rather than proven source array capacity.
- Remaining uncertainty: original declaration ordering/capitalization, exact `[16]` capacity, exact compiler flags/version, and historical standalone-versus-broader translation unit. The array question has a ranked implementation-ready answer and bounded runner-up; none changes current owner/emitter, exact runtime behavior, range, or selected formal method contract.

## Validator Results

- Every changed ordinary by-* page received a scoped file-mode validator from `source-3/project-documentation`, and every command exited `0` with `ok: 1`:

| Command ID | Timestamp | Scoped path | Result and recorded side effects |
| --- | --- | --- | --- |
| `000000010460` | `2026-07-13T17:51:30-04:00` | `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md` | exit `0`, ok `1`; completion/confidence and registry hash updates, projected stats update, generated refresh deferred. |
| `000000010462` | `2026-07-13T17:52:10-04:00` | `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md` | exit `0`, ok `1`; completion/confidence/registry/projected-stats updates, generated refresh deferred. |
| `000000010466` | `2026-07-13T17:53:07-04:00` | `by-class/SelfSaveInputPane.md` | exit `0`, ok `1`; completion/confidence/registry/projected-stats updates, generated refresh deferred. |
| `000000010471` | `2026-07-13T17:53:49-04:00` | `by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md` | exit `0`, ok `1`; completion/confidence updates, reverse-index additions for UID0003HM/UID0003O5/UID0003O6/UID0003O7, projected stats update, generated refresh deferred. |
| `000000010474` | `2026-07-13T17:54:38-04:00` | `by-file/SelfSaveInputPane.md` | exit `0`, ok `1`; completion/confidence update, reverse-index removal of stale UID0001QH relation, projected stats update, generated refresh deferred; three pre-existing missing-UID000363 warnings recorded. |
| `000000010475` | `2026-07-13T17:55:19-04:00` | `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md` | exit `0`, ok `1`; projected stats update, generated refresh deferred. |
| `000000010477` | `2026-07-13T17:55:46-04:00` | `by-type/by-vtable/SelfSaveInputPaneVtables.md` | exit `0`, ok `1`; projected stats update, generated refresh deferred. |
| `000000010478` | `2026-07-13T17:56:09-04:00` | `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md` | exit `0`, ok `1`; projected stats update, generated refresh deferred; two pre-existing missing-UID000363 warnings recorded. |
| `000000010479` | `2026-07-13T17:56:32-04:00` | `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md` | exit `0`, ok `1`; projected stats update, generated refresh deferred; three pre-existing missing-UID000363 warnings recorded. |
| `000000010481` | `2026-07-13T17:57:04-04:00` | `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` | exit `0`, ok `1`; reverse-index additions for UID0003O6/UID0003O7, projected stats update, generated refresh deferred. |
| `000000010482` | `2026-07-13T17:57:35-04:00` | `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` | exit `0`, ok `1`; reverse-index additions for UID0003O6/UID0003O7, projected stats update, generated refresh deferred; three pre-existing missing-UID0003UT warnings recorded. |
| `000000010485` | `2026-07-13T17:59:18-04:00` | `by-global/g_packetSender.md` | exit `0`, ok `1`; projected stats update, generated refresh deferred; two pre-existing missing-UID0003UT warnings recorded. |
| `000000010486` | `2026-07-13T17:59:54-04:00` | `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md` | exit `0`, ok `1`; projected stats update, generated refresh deferred. |
| `000000010487` | `2026-07-13T18:00:32-04:00` | final target `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md` with `--wait-generated` | exit `0`, ok `1`; generated refresh completed, validator registry rebuilt, 280 generated metadata records refreshed, projected stats updated, unrelated validator-owned `ItemDialogs.cpp` content refresh reported, and unrelated missing UID00033X plus repository-wide autogen marker warnings recorded. |

- Exact final command: `python .\tools\validator.py --mode file --file by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md --apply --queue-timeout 240 --wait-generated`.
- Generated readback path: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`; header has `validator-command-id: 000000010487`, `validator-refreshed-at: 2026-07-13T18:00:32-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
- Positive counts in the final generated file: class definition `1`; private helper declaration `1`; UID0003O6 `OnConfirmInput` definition `1`; source `SendSelfSavePacket();` call `1`; UID0003O7 member definition `1`; `unsigned char packet[16];` `1`; `PacketBufferWriteUInt8(0x25, packet);` `1`; `packet[1] = 0;` `1`; `g_packetSender->QueueAndSendPacket(packet, 1);` `1`.
- Negative counts in the final generated file: `static void SendSelfSavePacket` `0`; unnamed `namespace {` `0`; `char packet[2]`/`unsigned char packet[2]` `0`; free `QueueAndSendPacket(g_packetSender,...)` `0`; UID0003O7 Empty Emitter Marker `0`; explicit `SelfSaveInputPane::~SelfSaveInputPane` `0`; explicit vptr/`_vftable` source `0`; explicit vtable array `0`; explicit RTTI locator definition `0`; explicit adjustor definition `0`; explicit scalar-deleting-destructor definition `0`. The single opcode writer/member-send count also proves no duplicate active handwritten packet body.
- Remaining warnings are unrelated missing-UID/autogen-marker conditions listed above; no target-specific validator error remains.

## Changed Files

- Ordinary by-* pages edited and scoped-validated:
  - `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md`
  - `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md`
  - `by-class/SelfSaveInputPane.md`
  - `by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md`
  - `by-file/SelfSaveInputPane.md`
  - `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md`
  - `by-type/by-vtable/SelfSaveInputPaneVtables.md`
  - `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md`
  - `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`
  - `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - `by-global/g_packetSender.md`
  - `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- Same report updated in place: `tools/leaser/Agents/Agent-B004/research/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`.
- Renamed/created ordinary by-* pages: none. Manual `by-*/-coverage-report.md` pages were not edited.
- Validator-owned generated/state side effects are recorded under Validator Results; B004 did not manually edit generated, tracker, audit, registry/state, queue/lock, lifecycle, or archive files.
- Lease proof: each of the thirteen ordinary pages was leased only for its immediate reread/edit/scoped-validation batch and unleased successfully immediately afterward. Final readback of `tools/leaser/Agents/Agent-B004/current_leases.md` contains no B004 lease.
- Lifecycle boundary: B004 did not run `execute_report`, a report-lifecycle probe, move, or archive command.

## Implementation Tracking Checklist

Historical report-only phase:
- [x] Exact pre-callback artifact was supervisor-accepted at SHA256 `6A5211ED2915542A76777603FE903A026DD3539251F2EF09BA1D6E5D5E48C10B` before implementation.
- [x] Target/support destinations were bounded to UID0003O7, UID0003O6, UID0001MU, UID0000CW, UID0000NM, UID0002N8, UID0003HM, UID0003O5, UID0001KQ, UID0003YJ, UID0001HU, UID0000Q5, and UID0001P0.
- [x] Exact bytes/hash/instructions, active duplicate, Wield/Wear family ABI, IDA stack-frame boundaries, same-binary controls, PE linker fingerprint, closest-compiler matrix, routes, providers, generated source, reports, and manual coverage rows were checked.
- [x] C01-C40 originally recorded exact destination and report-only proposed state; the callback ledger now carries legal final states plus separate claim proof.
- [x] Accepted score plan recorded target `92/92`, active `92/93`, aggregate `91/92`, class `91/93`, and file `91/92`, with all other named scores retained.
- [x] No-route, duplicate tail, member/static, source capacity, compiler padding, return type, provider syntax, owner/emitter, placement, name, and formal-C++ blockers were researched to resolution; exact binary facts remain separate from inferred `[16]`, and `[2]` plus exact-toolchain padding remains the bounded runner-up.
- [x] Owner/emitter/reconstructable fields required no change and remain target `0000CW/TRUE/0000CW` with exact rationale.
- [x] No split, rename, or new child was required; exact path/range/padding/position `30`/`Nested:0` were preserved.
- [x] Source-placement, range/split/padding/reclassification, and IDA name/type/comment recommendations were recorded.
- [x] Exactly three complete managed blocks were supplied for UID0003O7, UID0003O6, and UID0000CW.
- [x] Third-party import was correctly classified not applicable because this is NexusTK project code.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, Wave2/Wave3 rejection, and all confidence caps were preserved.
- [x] Exact manual supervisor-owned coverage replacements/addition remain supplied unchanged; generated refresh does not satisfy or apply them.

Implementation callback phase:
- [x] The supervisor authorized implementation of the exact Gate 1 artifact.
- [x] C01-C40 and all accepted target/support details were incorporated at report-level depth without deleting the research evidence.
- [x] Ledger Action and Verification cells use legal final literals for every C01-C40 claim, with detailed proof outside those normalized state cells.
- [x] Target, active, aggregate, class, and file scores are `92/92`, `92/93`, `91/92`, `91/93`, and `91/92`; all accepted owner/emitter/range/position/Nested/formal policies are confirmed.
- [x] Exact UID0003O7, UID0003O6, and UID0000CW managed blocks match the accepted report byte-for-byte in their managed regions.
- [x] UID0002N8/UID0003HM, UID0003O5/UID0001KQ, UID0003YJ/UID0001HU, and UID0000Q5/UID0001P0 support detail is synchronized while their accepted scores/formal policies remain unchanged.
- [x] Exact binary facts remain distinct from inferred `unsigned char packet[16]`; `packet[2]` plus exact-toolchain padding/alignment remains the bounded runner-up and confidence cap in all affected current sections.
- [x] Historical no-route, optimized inline-copy, compiler ABI, standalone/grouping, rejected ownership/signature/no-code alternatives, and provider/global evidence are preserved.
- [x] One scoped validator passed for every changed ordinary page; all command IDs/timestamps/exits/ok/side effects are recorded.
- [x] Every one-file lease was released immediately after its edit/validator batch; current lease readback contains no B004 lease.
- [x] Waited generated command `000000010487` completed and exact positive/negative `SelfSaveInputPane.cpp` counts are recorded.
- [x] Manual coverage remained read-only; no generated/tracker/audit/lifecycle/state file was manually edited.
- [x] B004 ran no `execute_report`, lifecycle probe, move, or archive command.
- [x] No accepted implementation item remains blocked or unapplied; IDA mutation and manual coverage are explicitly external/out of callback scope rather than pending B004 work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000010560","destination_path":"executed-b-agent-research/B004/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md","timestamp":"2026-07-13T18:46:24-04:00","uid":"0003O7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
