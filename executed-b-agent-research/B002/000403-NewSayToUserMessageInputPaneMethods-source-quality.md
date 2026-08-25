# UID000403 NewSayToUserMessageInputPane Methods Source Quality
** TARGET-REPORT-UID:000403 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Keep UID000403 as the exact reconstructable method child of UID000099 `NewSayToUserMessageInputPane`, with canonical owner/emitter UID000099 and source placement in `NexusTK/social/SayInputPanes.cpp`.
- The accepted callback has raised UID000403 from `86/90` to `94/95`, replaced the stale submit and key-handler draft with the exact formal CPP in this report, and kept target H blank because declarations belong to the class owner.
- The accepted callback has raised UID000099 from `87/90` to `93/94`, moved its clean class declaration from CPP to H, omitted the explicit derived destructor, and retained `[[CHILDREN]]` in class CPP after the module-header include.
- Preserve the constructor, exact range split, five live constructor callers, three vtable views, prompt, object layout, inline opcode `0x19` protocol, modern/legacy relationship, and compiler-artifact exclusions already documented correctly.
- Correct the submit draft to one reusable 256-byte multibyte buffer and one contiguous 300-byte packet, with compiler-generated checked-index failures rather than authored silent returns.
- Correct the secondary virtual to `bool HandleKeyOrTextEvent(Event *event)` and preserve its complete empty, unmodified Backspace cleanup flow. Reject `OnKeyInput`, `InputEvent`, `IsBackspaceKey`, `OpenSayToUserNameInputPane`, `LineInputPane::HandleKeyInput`, and an `event->m_type` gate as source for this body.
- Confidence: very high for behavior, ranges, liveness, layout, protocol, source owner, and formal target CPP; original lexical spellings remain the narrow residual uncertainty.

## Supporting Research

- Assignment authority: `tools/leaser/Agents/Agent-B002/goal.md`, SHA256 `DB031447B6997E954069AABD13FC310B713303F40B0ADA6C0A6F6AECC3C8813D`.
- Implementation authority: the supervisor accepted the exact report at SHA256 `F482B88423CFEB233D4417A98FCC99DEBE1C9FD77D9808BCB1BF3C95C46C490B` and authorized ordinary claims C001-C044 on 2026-08-14; C045-C049 remain supervisor-owned and C050 remains a no-operation boundary.
- Historical Gate 1 repair authority: exact post-callback report SHA256 `60E8A108CC2A1CC556933C97B391A42D989079A9CE33E3A6446A4A3DD90FD00F` failed because A01/A02 combined four endpoints without literal intermediate contracts. That repair split those endpoints while preserving every applied ordinary-document result, receipt, generated readback, formal source block, claim state, and file hash.
- Historical 2026-08-15 Gate 2B failure receipt: A01A-A01D and A02A produced their exact expected readbacks. The former A02B function `set_type` accepted `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)` and changed the function prototype, but physical frame row 5 remained `Block` at `+0x24`, size `0x4`, type `void *`; the required combined row rename/retype did not occur, so the report's hard stop fired. The former later comment stages and save were not attempted. The supervisor rolled back every transient A01/A02 change.
- Restored-state receipt: bounded read-only MCP reconfirmed canonical names `sub_5B1A60`/`sub_5B1C40`, original prototypes, exact 10-row/6-row frames, four comment channels, xrefs, UDTs, ranges, and body identities. The canonical disk IDB remains the pre-mutation file, SHA256 `69F1EB3530827BC54F6A4407BEF6EF3C0FB4477860AF833CF74C8C5E621BDA35`, `143,208,842` bytes.
- Disposable endpoint receipt: supervisor session `supervisor-uid000403-disposable-endpoint-test-20260815`, opened from the byte-identical prestate backup, verified the exact A02B-A02D sequence now specified in Section 21. The canonical IDB was not touched or saved by that test; this is disposable-session mutation evidence, not a claim that canonical mutation has already succeeded.
- Assignment target snapshot was re-read unchanged at SHA256 `6ECCBB42A312FD24653EE065CDEA840E64E961383D06891D20823658F65AAB28`, `10,053` bytes, `128` lines.
- Mandatory live IDA MCP was available read-only through session `supervisor-uid0000KZ-gate2b-20260814`. `server_health` returned `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, strings cache size `2068`, and `auto_analysis_ready:false`. The false auto-analysis flag did not block bounded IDB-backed reads.
- Public `runtime_attestation` returned `schema_version:1`, `ok:true`, and no errors for that exact session and canonical path at `2026-08-14T20:26:08.211680+00:00`. These are dated research receipts; later supervisor work must bind dynamically to the then-current canonical session.
- The input executable reported by IDA is `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Read-only MCP checks covered function profiles, decompilation, exact bytes, stack frames, comments, xrefs, callers/callees, vtable cells, type layouts, strings, pointer searches, and the adjacent no-route helper start.
- Current by-* docs, accepted UID000401/UID0000C6 precedent, the older UID000099 report, current generated CPP/H, manual coverage rows, and source-tree/file-owner guidance were compared. Older Wave2/Wave3 artifacts were not used as authority.
- Historical initial research-pass fact: no report lease was acquired under the then-active lease-exempt treatment. Later explicitly requested same-report repairs, including this repair, used only a short report lease and released it immediately; current lease state is authoritative only from the generated shared lease report.

## Target

- Target UID: `000403`.
- Additional target UIDs: none. Support-page recommendations do not declare additional coverage.
- Target path: `by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md`.
- Report path: `tools/leaser/Agents/Agent-B002/research/000403-NewSayToUserMessageInputPaneMethods-source-quality.md`.
- Exact covered interval: `[0x005b1990,0x005b1d42)`, 946 bytes including two internal alignment spans.
- Canonical owner/emitter: UID000099 `by-class/NewSayToUserMessageInputPane.md`.
- Compilation-unit parent: UID0000N9 `by-file/SayInputPanes.md`, proposed path `NexusTK/social/SayInputPanes.cpp` with declarations in `SayInputPanes.h`.
- Split/index parent: UID0001LY `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`.
- Assignment-time metadata: `COMPLETION:86`, `CONFIDENCE:90`, owner/emitter `000099`, reconstructable true, optional position blank, `Nested:0`.

## Current Target State

- At the accepted pre-callback SHA, the target had substantial valid evidence and a three-method CPP draft, but the submit and key bodies were materially stale.
- The pre-callback constructor source was substantially correct: base construction with null prompt, `m_recipientName[128]`, `L"To %s : "`, and `SetPromptText`. That valid source was preserved, including use of the stored member after the bounded copy.
- The superseded submit draft used two zero-initialized `char[256]` buffers, a zero-initialized `unsigned char[0x230]`, direct byte writes in place of `PacketBufferWriteUInt8`, and explicit silent returns for checked-index failures. The implemented source now reflects the proof: one reused `CHAR[256]`, one contiguous `unsigned char[0x12c]`, three byte-writer calls, and compiler-generated range-check failure paths.
- The superseded key draft declared `OnKeyInput(const InputEvent *)`, invented `IsBackspaceKey` and `OpenSayToUserNameInputPane`, dropped event translation and cleanup, and delegated to nonexistent source-facing `LineInputPane::HandleKeyInput`. The implemented target and owner now use `HandleKeyOrTextEvent(Event *)` and preserve the complete empty-Backspace flow.
- The exact current IDA method identities are constructor `0x005b1990` size `0xc1`, submit `0x005b1a60` size `0x1d2`, and key handler `0x005b1c40` size `0x102`.
- Owner UID000099 is now `93/94`, reconstructable, and routed to UID0000N9; its H owns the clean declaration and its CPP includes `SayInputPanes.h` then emits `[[CHILDREN]]`. Target UID000403 is now `94/95`, retains owner/emitter/range/reconstructable state, emits the exact three namespace-scope methods in CPP, and keeps H blank.
- UID0000C7 remains `87/91`; its existing complete class declaration is now H-visible before UID000403's direct `new SayToUserNameInputPane()` expression, while its independently stale method source remains explicitly unsolved.
- Historical generated checkpoint command `000000023549`, refreshed `2026-08-14T15:32:38-04:00`, produced malformed `SayInputPanes.cpp` SHA256 `E3C3445B0AC3E6AA7F63D695A4A374A6470C3632FA28323BCFB186A3BD7E30EA`, `16,476` bytes, `513` lines, and incomplete `SayInputPanes.h` SHA256 `A8B5FFA98E6CCA51A404BC3886902B302EDC385EBBD6114A2D550F2EDF6B13DD`, `1,550` bytes, `54` lines. Its nested-definition and missing-declaration defects remain dated correction history.
- Preserved dated post-callback generated checkpoint command `000000023637`, foreground-refreshed `2026-08-14T18:41:33-04:00`, produced coherent `SayInputPanes.cpp` SHA256 `0B27FC0ED1F9CC98F9E5B36044A99305E1E7F3BBD1C9BE44B7E5691CC3EB6001`, `16,338` bytes, `494` lines, and `SayInputPanes.h` SHA256 `E978393FF4966292C5C87AD3DE694ABC33612A0111FE589EFB72850AB75F5FC3`, `2,405` bytes, `86` lines. This is the accepted callback's physical readback receipt, not a claim about unrelated later validator refreshes.
- Report execution/archive status is supervisor-owned and authoritative only from the artifact's current path and validator-owned status/history metadata. This report body does not assert that execution is pending, not run, completed, or executed; Gate 2A, Gate 2B, coverage, and lifecycle closure remain independently supervisor-verified.

## Executive Recommendation

- Retain the implemented UID000099 direct class ownership and UID0000N9 file ownership. No new class, file, helper, split, or emitter is warranted.
- Keep the implemented target CPP equal to the three exact source-facing definitions in Section 22 and keep target H blank.
- Keep UID000099 in the implemented shared-module pattern: declaration in H, CPP include of `SayInputPanes.h` plus `[[CHILDREN]]`, namespace-scope child definitions, and no explicit derived destructor source.
- Keep `SayToUserNameInputPane` complete and H-visible before UID000403's exact direct construction. Its independently stale methods are not claimed as solved, and the direct construction must not be replaced by a helper call merely to avoid the declaration dependency.
- Keep UID000404 ownerless, non-reconstructable, and non-emitting. It is not called by submit and has no xref or pointer route.
- Gate 2B should apply only the ten dependency-ordered method stages A01A-A01D and A02A-A02F in Section 21 after fresh prestate verification; constructor state, class UDT, and compiler artifacts are protected.

## Supervisor Active Recheck

- Trigger: the supervisor accepted exact report SHA256 `F482B88423CFEB233D4417A98FCC99DEBE1C9FD77D9808BCB1BF3C95C46C490B` for ordinary-document implementation of C001-C044 while reserving C045-C049 for supervisor work and C050 as no-operation.
- Split repair was not required. UID000403 retained exact method and padding boundaries while this callback corrected source quality and owner/header topology without changing the range.
- Every source-bearing item inside the target interval has a CPP or no-code disposition: constructor, submit, and key handler emit; both `0xcc` spans do not.
- The adjacent `0x005b1d50` raw helper and distant destructor/adjustor wrappers were explicitly rechecked and excluded rather than silently deferred.
- Historical implementation-cycle fact: during the dated ordinary-document callback, six authorized ordinary by-* pages were changed under short leases and scoped validation. That callback manually edited no generated file, coverage page, tracker, audit, catalog, lifecycle file, goal, note, validator-state file, or IDA and did not run `execute_report`; its validator-managed index/stats/generated side effects are separately receipted.

## Inference Research Guidance Check

- `by-structure.md` and the project inference discipline require exact by-memory children to own method bodies while the by-class owner owns declarations and `[[CHILDREN]]`; this directly determines target CPP, target H, owner CPP, and owner H dispositions.
- Existing names were treated as hypotheses unless supported by shared virtual-family documentation, typed Event layout, vtable position, direct call behavior, or accepted sibling source.
- Direct IDA fact: receiver adjustment, event fields, packet storage, bounds instrumentation, vtable cells, callers, globals, and call order. Documentation evidence: source-facing class/helper/global names and shared module route. Inference: original lexical spellings and whether simple direct field writes were wrapped by inline accessors.
- Stale assumptions challenged: `OnKeyInput`, `InputEvent`, two conversion buffers, `0x230` packet storage, authored silent bounds returns, helper-routed packet send, helper-routed recipient-name opening, and an event-type gate.
- Wave2/Wave3 names and old generated standalone `class_*.cpp` paths were treated as stale provenance only. Current by-* ownership and live binary evidence control.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Disposition |
| --- | --- | --- |
| Constructor boundary | IDA function ends at `0x005b1a51`; next 15 bytes are `0xcc`; body hash and unique vtable stores close the body. | Original-proof boundary; retain. |
| Submit boundary | IDA function is `[0x005b1a60,0x005b1c32)` followed by 14 `0xcc` bytes. | Original-proof boundary; retain. |
| Key boundary | IDA function is `[0x005b1c40,0x005b1d42)`; following 14 `0xcc` bytes precede the raw helper at `0x005b1d50`. | Original-proof boundary; target stops at `0x005b1d42`. |
| Submit liveness | No rel32 caller exists, but data xref `0x0062f7d0 -> 0x005b1a60` is the primary submit virtual slot. | Live virtual, not dead code. |
| Key liveness | No rel32 caller exists, but data xref `0x0062f7e0 -> 0x005b1c40` is secondary slot `+0x08`. | Live secondary virtual. |
| Packet storage | Stack offsets `Src@+0x208`, `destination@+0x209`, and 298 following bytes form one 300-byte packet. | Use `unsigned char packet[0x12c]`; reject `0x230`. |
| Conversion storage | `MultiByteStr@+0x334` is one `CHAR[256]` reused by two conversions. | Use one `char convertedText[256]`; reject two buffers. |
| Initialization | The compiled function does not clear either full local array before use. | Reject aggregate zero initialization as non-faithful source. |
| Range handling | Three indexed writes branch to `___report_rangecheckfailure`; fixed-array source regenerates this instrumentation. | Omit explicit checks and silent returns from human source. |
| Packet byte writes | Opcode and both one-byte lengths call `PacketBufferWriteUInt8`; payloads use the MemoryMan memmove wrapper. | Preserve byte writer; model payload copies as `memcpy`. |
| Terminators | Converted text is terminated after each conversion; packet is terminated locally at counted end but send length excludes it. | Preserve all three terminators and counted send length. |
| Submit helper route | Submit has no call/xref to `0x005b1d50`; pointer search for that VA is empty. | Serialize inline; UID000404 remains non-emitting. |
| Key signature | Input-pane secondary vtable family and base callee `0x004f25a0` establish `bool HandleKeyOrTextEvent(Event *)`. | Replace `OnKeyInput(const InputEvent *)`. |
| Receiver shape | Binary receives the secondary EventHandler facet and subtracts `0xa0` only for complete-object operations. | Source remains an ordinary class override; Gate 2B type preserves facet receiver. |
| Backspace test | Event key translation is unconditional; modifiers must be zero; translated key must equal `8`; text length must be zero. | Use translated `key != '\b'` gate; reject invented helper. |
| Event type | The body never reads `Event::m_type`. | Do not add `kEventKeyDown` gate. |
| Cleanup | Empty Backspace queues the complete pane, clears `UserPane+0x210`, conditionally resets say mode and refreshes the variety pane, directly allocates/constructs the name pane, then returns true. | Preserve complete sequence and order. |
| Active-pane write | UserPane support proves `+0x210` is `LineInputPane *m_activeLineInputPane` with inline `ClearActiveLineInputPane()`. | Inline accessor is source-safe and exact. |
| Variety refresh | The call through `g_pChattingVarietyPane` virtual `+0x48` is established as source-facing `Refresh()`. | Use accepted inferred name; note lexical uncertainty only. |
| Destructor | Shared scalar wrapper and adjustor thunks are compiler-generated and shared across pane classes. | Omit explicit derived destructor and all wrapper bodies. |
| Source file | Callers span menu, user list, UserPane mode helpers, and recipient-name flow, while siblings and file docs centralize the family. | Retain `social/SayInputPanes.cpp`; reject caller-owned files. |
| Generated output | Current nested definitions and missing declarations are emitter topology defects, not evidence for authored nested classes. | Repair formal owner channels; never edit generated files. |

No in-scope behavior, boundary, liveness, ownership, protocol, layout, or target-source blocker remains unresolved. Residual original-identifier uncertainty is explicit and does not prevent faithful source.

## Evidence Standards Used

- Highest weight: live IDA function boundaries, decompilation, raw bytes, stack frames, exact xrefs, vtable pointers, UDT offsets, function types, comments, and negative pointer/xref searches.
- Corroborating weight: independent constructor callers, accepted legacy direct-message source, shared input-pane virtual-family documentation, globals and field-layout support pages, and current generated route readback.
- Inference was accepted only when multiple independent facts constrain the same source shape. `Refresh()` and the inline UserPane clear accessor are project-source names backed by exact operations; original lexical proof is not claimed.
- Decompiler temporary boundaries were not copied blindly. The one-packet/one-conversion-buffer conclusion comes from physical stack offsets and contiguous byte accounting.
- `auto_analysis_ready:false` is recorded as context, not elevated into a failure, because health was `ok`, Hex-Rays was ready, and bounded reads returned coherent current IDB state.
- Negative evidence is used narrowly: zero xrefs and zero encoded pointers reject helper liveness, but do not alone reject the three methods because the submit/key vtable routes are positive evidence.

## Evidence Checked

- Live MCP: `idb_list`, `server_health`, public `runtime_attestation`, function profiles, decompilation, callees, xrefs, stack frames, comments, type inspection, vtable bytes/cells, strings, exact range bytes, and encoded-pointer searches.
- Functions: `0x005b1990`, `0x005b1a60`, `0x005b1c40`; neighbor `0x005b1d50`; compiler artifacts `0x005b7820`, `0x005b782b`, and `0x005b7af0`.
- Types: `NewSayToUserMessageInputPane`, `LineInputPane`, `Event`, `EventKeyPayload`, and `UserPane`; incomplete current IDA types for `ChattingHandlePane`, `ChattingVarietyPane`, and `Socket` were treated as a database limitation rather than a reason to invent fields.
- Strings: `0x00630a18` `L"To "`, `0x00630a20` `L"-> %s: "`, and `0x00630a30` `L"To %s : "`.
- Current docs: target UID000403; owner UID000099; UID0000C7, UID0000C6, UID000077; file UID0000N9; split UID0001LY; neighbor UID000404; prompt/global/Event/UserPane/vtable support; all five constructor-caller pages where present.
- Accepted reports: UID000401 method source and UID0000C6 class topology were used as same-protocol/same-layout precedent. The older UID000099 report was used only for valid preserved evidence; its unresolved key-name conclusion is superseded by the current Event-family proof.
- Current generated output and manual by-memory/by-class/by-file coverage rows were read only. No validator or report lifecycle probe was run.
- Negative checks: no direct submit/key callers, no xrefs to `0x005b1d50`, no encoded pointer to `0x005b1d50`, no constructor pointer table, unique submit/key vtable cells, no `event->m_type` load, no submit helper call, and no source-authored destructor body requirement.
- No required bounded check failed or remained unavailable. Original PDB/source symbols do not exist; that limits lexical certainty only.

## Claim And Incorporation Ledger

Actor allocation is fixed for the handoff: Agent-B002 has closed ordinary-document callback rows C001-C044; the supervisor owns pending Gate 2B rows C045-C048 and manual-coverage row C049; C050 is a checked no-operation boundary. Verification allocation is exactly 36 `applied`, 7 `already-present`, 2 `excluded-with-reason`, and 5 `proposed`. The normalized action is the disposition, while the Claim, Evidence, and Destination fields retain the exact implementation detail.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 000403 | Target identity, snapshot hash, owner/emitter, reconstructable state, and no additional UIDs are exact. | certain | goal and target readback | target metadata/status | already-present | already-present |
| C002 | 000403 | Full target is `[0x005b1990,0x005b1d42)`, 946 bytes, SHA256 `8291BBB4043B127616CA36105241F6A38D32EFF1AA94E0BDEF3F8F982E09BDB4`. | certain | PE byte extraction | target Covered Ranges/Evidence | incorporate | applied |
| C003 | 000403 | Constructor is `[0x005b1990,0x005b1a51)`, 193 bytes, hash `FBF0FDA1F3E470A3EACA05AC9D4EF0D6F12BB6543082B040FB02961DBA0BAB67`. | certain | function/bytes | target Covered Ranges | incorporate | applied |
| C004 | 000403 | `[0x005b1a51,0x005b1a60)` is 15 bytes of `0xcc` alignment, hash `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`. | certain | bytes | target Covered Ranges | incorporate | applied |
| C005 | 000403 | Submit is `[0x005b1a60,0x005b1c32)`, 466 bytes, hash `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`. | certain | function/bytes | target Covered Ranges | incorporate | applied |
| C006 | 000403 | `[0x005b1c32,0x005b1c40)` is 14 bytes of `0xcc`, hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. | certain | bytes | target Covered Ranges | incorporate | applied |
| C007 | 000403 | Key handler is `[0x005b1c40,0x005b1d42)`, 258 bytes, hash `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`. | certain | function/bytes | target Covered Ranges | incorporate | applied |
| C008 | 000403 | `[0x005b1d42,0x005b1d50)` is 14-byte successor padding outside UID000403, same hash as C006. | certain | bytes/boundary | target boundary notes | incorporate | applied |
| C009 | 000403 | `0x005b1d50` is not an IDA function and has zero xrefs; UID000404 remains a sibling no-route helper. | certain | lookup/xrefs/pointer search | target Evidence/negative history; UID000404 support | already-present | already-present |
| C010 | 000403 | Primary, secondary, tertiary vtable starts are `0x0062f788`, `0x0062f7d8`, `0x0062f808`; submit/key cells are `0x0062f7d0`/`0x0062f7e0`. | certain | ctor stores/vtable bytes/xrefs | target vtable evidence; class support | incorporate | applied |
| C011 | 000403 | Constructor is the unique text store source for the three modern vtable starts. | very high | immediate search/constructor | target liveness/layout | incorporate | applied |
| C012 | 000403 | Class is `0x208`; `LineInputPane` is `0x108`; `wchar_t m_recipientName[128]` begins at `+0x108`. | certain | UDT/type and copy bound | target/class layout | already-present | already-present |
| C013 | 000403 | Constructor copies recipient with bound `0x80`, formats `L"To %s : "`, and sets prompt after `LineInputPane(0)`. | certain | decompile/callees/string | target CPP/evidence | already-present | already-present |
| C014 | 000403 | Caller `0x00554e0a` is the Whisper row in `RightButtonMenuPane::OnEvent`. | high | xref and caller decompile/docs | target Caller Inventory | incorporate | applied |
| C015 | 000403 | Caller `0x0059edc6` is `UserListPane::OnItemActivated` modern branch. | certain | xref/caller decompile | target Caller Inventory | already-present | already-present |
| C016 | 000403 | Caller `0x005a51e9` is current-mode 2 construction in `OpenInputPaneForCurrentSayMode`. | certain | xref/caller decompile | target Caller Inventory | incorporate | applied |
| C017 | 000403 | Caller `0x005a5544` is the last-recipient direct-message opener at `0x005a54b0`. | high | xref/caller decompile/docs | target Caller Inventory | incorporate | applied |
| C018 | 000403 | Caller `0x005b4128` is the modern branch of recipient-name confirmation. | certain | xref/caller decompile | target Caller Inventory | incorporate | applied |
| C019 | 000403 | Submit gates on positive text, copies max 255 wchar, validates, then sanitizes. | certain | decompile/callees | target CPP/behavior | incorporate | applied |
| C020 | 000403 | Submit uses one contiguous 300-byte packet, not `0x230` bytes. | certain | stack-frame accounting | target CPP/stale history | reject-stale | applied |
| C021 | 000403 | Submit uses one reusable `char[256]` conversion buffer, not two zeroed buffers. | certain | stack frame/decompile | target CPP/stale history | reject-stale | applied |
| C022 | 000403 | Opcode `0x19` and both one-byte lengths use `PacketBufferWriteUInt8`. | certain | three direct calls | target CPP/protocol | already-present | already-present |
| C023 | 000403 | Recipient uses CP_ACP conversion, local terminator, one-byte length, then payload copy. | certain | decompile | target CPP/protocol | incorporate | applied |
| C024 | 000403 | Message reuses the same buffer and repeats conversion, terminator, length, and payload copy. | certain | decompile | target CPP/protocol | incorporate | applied |
| C025 | 000403 | `>=256` and `>=300` branches are checked-array instrumentation to rangecheck failure, not silent authored returns. | very high | branch target/callee/compiler pattern | target CPP/stale history | reject-stale | applied |
| C026 | 000403 | Count is recipient+message+3; packet terminator is local-only; send uses counted short length through `g_packetSender`. | certain | decompile/data flow | target CPP/protocol | incorporate | applied |
| C027 | 000403 | Submit serializes inline and never calls UID000404. | certain | callee/xref/pointer negatives | target CPP/negative evidence | reject-invalid | applied |
| C028 | 000403 | Source virtual is `bool HandleKeyOrTextEvent(Event *event)`. | very high | secondary vtable family/base callee/Event UDT | target CPP; owner H | reject-stale | applied |
| C029 | 000403 | Key translation is unconditional; any modifier, non-Backspace key, or nonempty text delegates to base. | certain | decompile/control flow | target CPP/behavior | incorporate | applied |
| C030 | 000403 | Empty unmodified Backspace queues complete pane deletion and clears active line-input state. | certain | decompile/global/field docs | target CPP/behavior | incorporate | applied |
| C031 | 000403 | Pending chat-target state resets say mode to default and calls variety-pane `Refresh()`. | very high | decompile/global support | target CPP/behavior | incorporate | applied |
| C032 | 000403 | Handler directly allocates/constructs `SayToUserNameInputPane` and returns true. | certain | operator-new/ctor calls | target CPP/behavior | incorporate | applied |
| C033 | 000403 | Handler does not read `Event::m_type`; no event-type gate belongs in source. | certain | full decompile/field access negative | target negative evidence/CPP | reject-invalid | applied |
| C034 | 000403 | The accepted pre-callback target CPP's two buffers, `0x230` packet, silent returns, invented key helpers, and dropped cleanup are superseded. | certain | C019-C033 comparison | target Changes/history | historicalize | applied |
| C035 | 000403 | Section 22 target CPP is the exact formal replacement for all three method definitions. | very high | full evidence union | target formal CPP | incorporate | applied |
| C036 | 000403 | Target formal H remains blank because UID000099 owns the declaration. | certain | emitter structure | target formal H | not-applicable | excluded-with-reason |
| C037 | 000403 | UID000099 emits its clean declaration in H with `OnSubmitInput` and `HandleKeyOrTextEvent(Event *)`, no explicit destructor; its leading `InputPanes.h` include replaces the duplicate include formerly carried by UID0000C3. | very high | vtable family/accepted UID0000C6 pattern/generated H order | class UID000099 CPP/H; UID0000C3 H | incorporate | applied |
| C038 | 000403 | UID000099 CPP includes `SayInputPanes.h` then emits `[[CHILDREN]]`, placing UID000403 definitions at namespace scope. | high | generated ordering/topology | class UID000099 CPP; file UID0000N9 | incorporate | applied |
| C039 | 000403 | `SayToUserNameInputPane` is complete in `SayInputPanes.h` before UID000403's direct new expression; its independent method-source cleanup is not target ownership. | high | C032/C038/generated order | UID0000C7/UID0000N9 support | incorporate | applied |
| C040 | 000403 | Source placement remains `NexusTK/social/SayInputPanes.cpp`/`.h`; caller-owned and standalone Whisper-file alternatives are weaker. | high | file docs/family/callers | target/class/file placement | already-present | already-present |
| C041 | 000403 | Dated pre-callback generated command 000000023549 proved the then-current nested-definition and missing-header defects; dated post-callback command 000000023637 proved their accepted repair at physical readback. | certain | physical generated readback | target/file support history | historicalize | applied |
| C042 | 000403 | UID000403 moved to `94/95`. | high | all behavioral/source blockers closed | target metadata/coverage | incorporate | applied |
| C043 | 000403 | UID000099 moved to `93/94` after declaration/topology correction. | high | exact layout/method/vtable/caller union | class metadata/coverage | incorporate | applied |
| C044 | 000403 | UID0000N9 remains `89/90`; broader shared-module topology prevents a file-level increase from this one child. | high | current file/generated inventory | file metadata/coverage | incorporate | applied |
| C045 | 000403 | Supervisor Gate 2B must preserve the constructor IDA name/type/four comment channels, complete frame, and exact five-code-xref set unchanged as Section 21 P01. | certain | live profile/comments/frame/xrefs | IDA Gate 2B | already-present | proposed |
| C046 | 000403 | Supervisor Gate 2B must normalize the submit IDA name/type/comments through dependency-ordered Section 21 stages A01A-A01D, preserving the exact body, ten-row frame, four comment-channel progression, and sole data-xref set after every endpoint. | high | vtable/body/source virtual/xrefs | IDA Gate 2B | incorporate | proposed |
| C047 | 000403 | Supervisor Gate 2B must normalize the key IDA name/type/comments through dependency-ordered Section 21 stages A02A-A02F: pure function rename, function type to `Event *Block`, stack rename `Block` to `event`, function type to `Event *event`, then FR and FP; preserve the exact body, six-row staged frames, four comment-channel progression, sole data-xref set, and secondary-facet receiver after every endpoint. | high | vtable/body/receiver adjustment/xrefs | IDA Gate 2B | incorporate | proposed |
| C048 | 000403 | Supervisor Gate 2B is bounded to Section 21 P01/A01A-A01D/A02A-A02F/P02; padding, UID000404, compiler wrappers, vtable data, globals, and support UDTs remain evidence-only no-mutation constraints outside the action tables. | certain | bytes/xrefs/compiler pattern | IDA protection/target negative evidence | already-present | proposed |
| C049 | 000403 | Supervisor must apply the four manual coverage rows using the exact replacement text in Section 28. | certain | manual coverage readback | manual coverage files | incorporate | proposed |
| C050 | 000403 | No validator, generated-file edit, report execution, IDA mutation, or lease action belonged to the original report-only pass; callback validators and short ordinary-file leases are separately receipted, while generated manual edit, execution, and IDA mutation remain excluded. | certain | explicit assignment and work log | Validator Results/Changed Files | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Three exact IDA functions, two exact internal padding spans, and one outside successor padding span account for the full interval without overlap or unexplained bytes.
- Five independent constructor callers allocate the same `0x208` object and feed recipient names from menu, user-list, mode-dispatch, last-recipient, and name-confirmation flows.
- Unique vtable data xrefs prove submit and key liveness despite zero ordinary callers.
- Constructor stores three modern-class vtable views, copies a 128-wchar recipient field at the exact post-base offset, and consumes the exact modern prompt literal.
- Physical stack accounting independently proves the packet and buffer source shape. The accepted legacy direct-message child compiles the same opcode/protocol shape from one buffer and one 300-byte packet.
- The secondary vtable family, `Event` UDT, unconditional key translation, base callee, and `-0xa0` complete-object adjustment jointly close the source virtual signature and receiver semantics.
- Exact globals and field offsets close every empty-Backspace side effect, including deferred deletion, active-input clear, pending-target mode reset, selector refresh, direct recipient-name-pane construction, and true return.

## IDA MCP Facts

- `0x005b1990` current name `NewSayToUserMessageInputPane__Constructor`, size `0xc1`, 67 instructions, 5 callers, current prototype `NewSayToUserMessageInputPane *__thiscall(NewSayToUserMessageInputPane *this, const wchar_t *recipientName)`.
- Constructor direct callees include `LineInputPane__Constructor@0x004f1c00`, `_wcscpy_s@0x005cd657`, formatting helper `0x0041b9b0`, `SetPromptText@0x004f20a0`, and compiler EH/cookie cleanup.
- `0x005b1a60` current name `sub_5B1A60`, size `0x1d2`, 140 instructions, 0 direct callers, current prototype `void __thiscall(WCHAR *this)`.
- Submit callees include `TextLength@0x004f2310`, `CopyText@0x004f2300`, validation `0x00465890`, sanitizer `0x005957c0`, `GetMemoryMan@0x00516030`, `PacketBufferWriteUInt8@0x00575380`, memmove wrapper `0x00516220`, queue/send `0x00574bb0`, and rangecheck failure `0x005c7655`.
- `0x005b1c40` current name `sub_5B1C40`, size `0x102`, 88 instructions, 0 direct callers, current prototype `bool __thiscall(TimerHandler *this, Event *Block)`.
- Key callees include `EventMan__TranslateEventKey@0x004a8b10`, `TextLength`, deferred deletion `0x00469180`, operator new `0x004f4aa0`, name-pane constructor `0x005b3cb0`, and `LineInputPane__HandleKeyOrTextEvent@0x004f25a0`.
- Submit stack: `WideCharStr` begins at frame `+0x8`; packet bytes begin at `+0x208`; `MultiByteStr[256]` begins at `+0x334`; cookie at `+0x434`; return at `+0x43c`.
- Key stack: `Block` at `+0x24` currently appears as `void *` in the frame while the function profile carries `Event *`; saved registers at `+0x1c`, return at `+0x20`.
- `NewSayToUserMessageInputPane` UDT exists at size `520` with `LineInputPane base@0` size `264` and `m_recipientName@0x108` size `256` as `wchar_t[128]`.
- Event key is `Event+0x8`; modifiers are `Event+0x10a`. UserPane active input is `+0x210`; current say mode is `+0x3eb4`.
- Vtable window `[0x0062f788,0x0062f810)` hash is `626B934D56E711FEDCF6060182F1A87A3A67D1A7F183F2FCB9A0AB92726B5071`.
- Pointer bytes for `0x005b1a60` occur only at `0x0062f7d0`; pointer bytes for `0x005b1c40` occur only at `0x0062f7e0`; pointer bytes for `0x005b1d50` do not occur.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | CPP/H disposition and status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b1990-0x005b1a51` constructor | UID000403 target | Modern direct-message construction/prompt | yes | UID000099 | assignment-time 86/90; implemented 94/95 | Exact CPP in Section 22 implemented; H on owner |
| `0x005b1a51-0x005b1a60` | target internal | 15-byte alignment | no source | UID000403 | n/a | Compiler/linker padding; no CPP/H |
| `0x005b1a60-0x005b1c32` submit | UID000403 target | Opcode `0x19` recipient/message serialization | yes | UID000099 | assignment-time 86/90; implemented 94/95 | Stale CPP replaced with Section 22; H on owner |
| `0x005b1c32-0x005b1c40` | target internal | 14-byte alignment | no source | UID000403 | n/a | Compiler/linker padding; no CPP/H |
| `0x005b1c40-0x005b1d42` key handler | UID000403 target | Empty-Backspace return-to-name flow and base delegate | yes | UID000099 | assignment-time 86/90; implemented 94/95 | Stale CPP replaced with Section 22; H on owner |
| `0x005b1d42-0x005b1d50` | outside target | successor alignment | no source | boundary between UID000403/UID000404 | n/a | Excluded; no CPP/H |
| `0x005b1d50` raw helper start | UID000404 | standalone no-route packet clone | no | UID0001LY index | non-reconstructable/non-emitting | Remains blank; not called by target |
| `0x005b7820-0x005b782b` | compiler support | secondary adjustor thunk | compiler-covered | UID000099 class family | n/a | No authored body |
| `0x005b782b-0x005b7836` | compiler support | tertiary adjustor thunk | compiler-covered | UID000099 class family | n/a | No authored body |
| `0x005b7af0-0x005b7b2b` | compiler support | shared scalar deleting wrapper | compiler-covered | target-message class family | n/a | Implicit destructor source cause; no body |
| `0x0062f788` / `0x0062f7d8` / `0x0062f808` | vtable/RTTI data | three class address points | compiler-generated data | UID000099 | n/a | Regenerated from class declaration; no manual data CPP |
| `0x00630a30` | UID0003JQ support | `L"To %s : "` literal | compiler-emitted literal | constructor consumer | n/a | Literal appears in constructor CPP, no separate target code |
| `NewSayToUserMessageInputPane` UDT | UID000099 | exact class declaration/layout | yes | UID0000N9 | 87/90 -> 93/94 | Move declaration to H; CPP children route |
| `SayToUserNameInputPane` complete type | UID0000C7 support | direct key-handler construction dependency | yes | UID0000N9 | retain 87/91 in this report | Must be H-visible; independent method child remains separately owned |
| `SayInputPanes.cpp/.h` generated checkpoint | UID0000N9 support | validator-routed module output | read-only | file owner | retain 89/90 | Dated command 000000023549 contained nested-definition and missing-H defects; dated post-callback command 000000023637 physically verified the accepted namespace-scope CPP and complete-H repair. Current generated truth remains subject to supervisor gate-time reread. |

Inventory totals: 3 source-bearing target methods, 2 in-target padding spans, 1 outside successor span, 1 excluded no-route sibling, 3 compiler code artifacts, 3 vtable address points, 1 literal, 2 class declarations, and 2 generated module artifacts. Every target-owned item has an explicit CPP/H or no-code disposition.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b1990` | code xref `0x00554e0a` in `sub_554C40` / documented `RightButtonMenuPane::OnEvent` | Whisper menu row constructs modern message pane for selected name. |
| `0x005b1990` | code xref `0x0059edc6` in `UserListPane_OnItemActivated` | Modern asset branch opens pane for activated list user. |
| `0x005b1990` | code xref `0x005a51e9` in `OpenInputPaneForCurrentSayMode` | Mode-2 recent-recipient route. |
| `0x005b1990` | code xref `0x005a5544` in `sub_5A54B0` | Last-recipient direct-message route. |
| `0x005b1990` | code xref `0x005b4128` in `sub_5B4080` | Recipient-name confirmation modern branch. |
| `0x005b1a60` | data xref `0x0062f7d0` only | Live primary submit virtual; no ordinary caller. |
| `0x005b1c40` | data xref `0x0062f7e0` only | Live secondary key/text virtual; no ordinary caller. |
| `0x005b1d50` | zero xrefs and zero encoded pointers | No live route from target or elsewhere. |
| constructor | `LineInputPane` ctor, bounded copy, format, prompt setter | Exact class/prompt initialization chain. |
| submit | text helpers, validator, sanitizer, byte writer, memmove wrapper, sender, rangecheck | Complete inline protocol and instrumentation chain. |
| key | key translator, text length, cleanup queue, UserPane globals, variety pane, operator new/name ctor, base handler | Complete delegate and empty-Backspace cleanup chain. |
| `0x0062f788` family | unique constructor stores | Modern class identity and liveness. |

## Documentation Evidence And IDA Status

- At accepted report SHA, target documentation correctly preserved owner/emitter, most boundaries, five constructor callers, prompt, vtable slots, globals, opcode, and neighbor exclusion.
- The accepted pre-callback target was stale where it described authored silent length failures, a `0x230` packet, two conversion arrays, `OnKeyInput`, `InputEvent`, invented key/open helpers, and an incomplete Backspace path. Current target documentation corrects each item and retains the stale forms only as superseded history.
- At accepted report SHA, UID000099 correctly owned the class/layout but had a stale formal declaration channel and key prototype. Current UID000099 has the clean H declaration and no explicit derived destructor source, while the shared compiler wrapper remains excluded from authored source.
- At accepted report SHA, UID0000N9 described intended H/CPP topology in prose while its UID000403 row still named `class_NewSayToUserMessageInputPane.cpp`. The current row is normalized to the shared module and records the complete-type dependency.
- UID0000C6/UID000401 provide accepted, same-layout, same-opcode precedent for a class-H/method-child-CPP arrangement and one-buffer/300-byte packet source.
- UID000077 and the input-pane vtable family establish `HandleKeyOrTextEvent(Event *)` and base `0x004f25a0`.
- Current IDA constructor name/type/frame/comment are strong. Submit/key names and receiver types remain decompiler-derived and are suitable for the exact supervisor actions in Section 21.
- Generated command `000000023549` is the dated structurally incomplete pre-callback snapshot. Dated post-callback validator-owned command `000000023637` was structurally coherent for the accepted scope and was physically read without manual generated-file editing.

## Ranked Ownership Analysis

### 1. UID000099 `NewSayToUserMessageInputPane` under UID0000N9 `SayInputPanes`

- Evidence for: all three vtable slots belong to the same class; constructor lays out the exact object; owner/emitter metadata already routes the child; caller flows and siblings are social say-input code; source-tree docs place the family in `NexusTK/social/`.
- Evidence against: stripped binary cannot prove original physical filename, and a separate historical Whisper file is possible.
- Decision: retain. It is the only candidate supported by class, file, vtable, layout, and project routing evidence together.

### 2. Separate `WhisperInputPanes.cpp`

- Evidence for: the class implements direct-message/whisper UI and could plausibly have been separated by feature.
- Evidence against: no source metadata, section boundary, owner document, or routed sibling set supports that split; current shared mode/header APIs and accepted sibling classes use `SayInputPanes`.
- Decision: reject as weaker inference.

### 3. Caller-owned files (`UserListDialogPane.cpp`, `UserPane.cpp`, menu pane source)

- Evidence for: each contains a live construction call.
- Evidence against: each is a consumer; none owns the class vtables, method bodies, recipient field, or protocol family.
- Decision: reject.

### Proposed new file/grouping, if applicable

- No new file or grouping. Preserve `NexusTK/social/SayInputPanes.cpp` and `SayInputPanes.h`.
- Keep UID000403 as a class child, not a standalone file emitter.

## Source Placement

- Implemented source placement: UID000099 declaration in `NexusTK/social/SayInputPanes.h`; UID000403 definitions at namespace scope in `NexusTK/social/SayInputPanes.cpp` through UID000099 `[[CHILDREN]]`.
- The target H remains blank to prevent duplicate class declarations. The class owner H must include the shared `../ui/dialogs/InputPanes.h` dependency before deriving from `LineInputPane`.
- UID000099's CPP is the earliest current emitter in the generated module, so its formal CPP now includes `SayInputPanes.h` before `[[CHILDREN]]`.
- The exact direct `new SayToUserNameInputPane()` requires that class to be complete by the time the CPP is parsed. Its declaration therefore belongs in the shared H; changing the target body to call an unrelated opener is rejected because the binary directly constructs the pane.
- `UserListDialogPane.cpp`, `UserPane.cpp`, `Chatting.cpp`, `Group.cpp`, and a speculative standalone Whisper file remain callers/dependencies/alternatives, not owners.

## Range / Split / Padding / Reclassification Analysis

- Exact target composition: constructor `0x005b1990-0x005b1a51`; 15-byte alignment `0x005b1a51-0x005b1a60`; submit `0x005b1a60-0x005b1c32`; 14-byte alignment `0x005b1c32-0x005b1c40`; key `0x005b1c40-0x005b1d42`.
- The target starts and ends correctly. Do not extend to `0x005b1d50`; the intervening 14 bytes are successor padding outside UID000403.
- No child split, merge, new UID, reclassification, or ownership move is needed. The three bodies are cohesive methods of one class and the current exact child is the correct source container.
- UID000404 begins at the raw address `0x005b1d50`, is not an IDA function, has no xrefs/pointers, and remains a separate no-route/non-emitting sibling.
- Adjustor thunks and scalar deleting wrapper are outside the target interval and remain compiler-covered support. They do not expand the target or justify source methods.
- Vtable/RTTI data and prompt literal remain supporting data, not new child source emitters.

## Negative Evidence Summary

- Zero direct callers for submit/key do not imply dead code because each has one exact vtable data xref.
- Zero xrefs and pointer hits for `0x005b1d50`, combined with no target call, reject routing submit through UID000404.
- No stack evidence supports two conversion buffers or a `0x230` packet; physical offsets directly contradict both.
- No control-flow path silently returns on the three array bounds. All converge on compiler rangecheck failure.
- No load of `Event::m_type` exists in the key body; sibling handlers that do test event type cannot donate that gate here.
- No call to `OpenSayToUserNameInputPane` exists in the key body. The direct `operator new(0x10c)` plus constructor call rejects that helper abstraction for this method.
- No `IsBackspaceKey` function call exists. Translation plus literal `8` is the actual path.
- No evidence supports `InputEvent` or `OnKeyInput`; the shared vtable slot and base method support `Event *` and `HandleKeyOrTextEvent`.
- Constructor callers do not move ownership into their files. Consumers span four subsystems, while vtable/layout/source-family evidence remains class/file-local.
- Shared destructor and adjustor wrappers do not prove an explicit derived destructor declaration or authored body.

## IDA Rename / Type / Comment Recommendations

This is a read-only supervisor handoff based on the dated 2026-08-14 research snapshot and the dated 2026-08-15 failure, rollback, and disposable endpoint-test receipts. Every `apply` row requires a fresh canonical-session prestate match, and every protected row requires a no-change readback. No transaction program or IDA mutation is embedded here. The Gate 2B action table is bounded to the three target functions and the target class UDT because those are the only entities for which this report supplies complete literal prestates and deterministic readbacks.

The 2026-08-15 canonical rollback was physically reconfirmed read-only before this repair: A01 and A02 again match the literal initial states below, and canonical disk SHA256 is `69F1EB3530827BC54F6A4407BEF6EF3C0FB4477860AF833CF74C8C5E621BDA35`. The failed no-save attempt is historical evidence that a function signature's argument identifier does not by itself authorize or guarantee the physical stack-row rename expected by the old A02B contract.

The replacement A02B-A02D behavior was separately verified only in disposable session `supervisor-uid000403-disposable-endpoint-test-20260815`: first function `set_type` with `Event *Block` retyped row 5 but preserved its physical name; specialized stack `rename` then changed only the physical row name while the prototype still spelled `Block`; second function `set_type` then changed the prototype spelling to `event` while preserving the already-correct physical row. Canonical application, immediate readback, stop/rollback handling, and save remain supervisor-owned and must be repeated from the fresh canonical prestate; this report does not claim those canonical mutations have occurred.

The exact A02C public binding is `rename` with `database:<fresh canonical session>` and `batch.stack:{func_addr:"0x005b1c40",old:"Block",new:"event"}`, plus `batch.allow_overwrite:false`, `batch.dry_run:false`, and `batch.stop_on_error:true`. This inline handoff is a declarative endpoint contract, not an executable transaction package.

| ID | Address/entity | Literal current prestate | Literal current comments / protected channel state | Proposed action and public endpoint binding | Evidence / exact expected readback | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| P01 | function `0x005b1990` | name `NewSayToUserMessageInputPane__Constructor`; size `0xc1`; prototype `NewSayToUserMessageInputPane *__thiscall(NewSayToUserMessageInputPane *this, const wchar_t *recipientName)`; complete frame P01 below; current inbound xrefs total `5`: code xrefs `{0x00554e0a, 0x0059edc6, 0x005a51e9, 0x005a5544, 0x005b4128}`, data xrefs `{}` | address regular: `absent`; address repeatable: `absent`; function regular: `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName). Copies recipientName into m_recipientName[128] and sets the current direct-message prompt "To %s : ".`; function repeatable: `absent` | No endpoint. Preserve name, type, frame, xrefs, and all four comment channels exactly. | Same function/range/name/type and all ten frame rows; expected inbound xrefs total `5`: code xrefs `{0x00554e0a, 0x0059edc6, 0x005a51e9, 0x005a5544, 0x005b4128}`, data xrefs `{}`; address regular: `absent`; address repeatable: `absent`; function regular: `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName). Copies recipientName into m_recipientName[128] and sets the current direct-message prompt "To %s : ".`; function repeatable: `absent`. | already present |
| P02 | UDT `NewSayToUserMessageInputPane` | exists; size `0x208`; `base@0` type `LineInputPane` size `0x108`; `m_recipientName@0x108` type `wchar_t[128]` size `0x100`; this named UDT is deterministically not an address, data item, or function and has no address/function xref set | address regular: no channel exists; address repeatable: no channel exists; function regular: no channel exists; function repeatable: no channel exists; deterministic reason: a named local UDT is not an address/function comment entity | No endpoint. Do not redeclare, resize, rename, or move members. | Exact same UDT name, total size, member names, offsets, types, and widths; it remains a non-address/non-function named UDT with no comment channels or address/function xref set. | already present |

### A01 dependency-ordered deterministic stages

Every A01 state below repeats the full ten-row frame literally. `AR`, `AP`, `FR`, and `FP` mean address regular, address repeatable, function regular, and function repeatable. Each endpoint owns only the field named in its action cell; every other listed field is independently protected and must be reread before the next stage.

| ID | Complete required prestate | Endpoint and independently protected fields | Complete expected readback | Classification |
| --- | --- | --- | --- | --- |
| A01A | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `sub_5B1A60`; type `void __thiscall(WCHAR *this)`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | Invoke `rename` with `pure:true` to `NewSayToUserMessageInputPane__OnSubmitInput`. Owned field: function name only. Independently protect type, all ten frame rows and count, AR/AP/FR/FP, range, size, body hash/bytes, calling convention, and exact xrefs; destination-name collision or any non-name delta is a hard stop. | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall(WCHAR *this)`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | apply |
| A01B | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall(WCHAR *this)`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | Invoke `set_type` with `void __thiscall NewSayToUserMessageInputPane__OnSubmitInput(NewSayToUserMessageInputPane *this)`. Owned field: function type and non-stack ECX presentation only. Independently protect name, all ten frame rows/count, AR/AP/FR/FP, range, size, body hash/bytes, `__thiscall`, and exact xrefs; any stack-frame delta or other delta is a hard stop. | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall NewSayToUserMessageInputPane__OnSubmitInput(NewSayToUserMessageInputPane *this)` with ECX `NewSayToUserMessageInputPane *this`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | apply |
| A01C | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall NewSayToUserMessageInputPane__OnSubmitInput(NewSayToUserMessageInputPane *this)` with ECX `NewSayToUserMessageInputPane *this`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | Invoke `set_function_comments` with `NewSayToUserMessageInputPane::OnSubmitInput(). Validates and sanitizes nonempty text, serializes opcode 0x19 plus one-byte recipient/message lengths into a 300-byte packet, and queues it through g_packetSender.`. Owned field: FR only. Independently protect name, type/ECX, all ten frame rows/count, AR/AP/FP, range, size, body hash/bytes, calling convention, and exact xrefs; any non-FR delta is a hard stop. | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall NewSayToUserMessageInputPane__OnSubmitInput(NewSayToUserMessageInputPane *this)` with ECX `NewSayToUserMessageInputPane *this`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `NewSayToUserMessageInputPane::OnSubmitInput(). Validates and sanitizes nonempty text, serializes opcode 0x19 plus one-byte recipient/message lengths into a 300-byte packet, and queues it through g_packetSender.`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | apply |
| A01D | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall NewSayToUserMessageInputPane__OnSubmitInput(NewSayToUserMessageInputPane *this)` with ECX `NewSayToUserMessageInputPane *this`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `NewSayToUserMessageInputPane::OnSubmitInput(). Validates and sanitizes nonempty text, serializes opcode 0x19 plus one-byte recipient/message lengths into a 300-byte packet, and queues it through g_packetSender.`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | Invoke `set_repeatable_comments` with `NewSayToUserMessageInputPane::OnSubmitInput();`. Owned field: FP only. Independently protect name, type/ECX, all ten frame rows/count, AR/AP/FR, range, size, body hash/bytes, calling convention, and exact xrefs; any non-FP delta is a hard stop. | function range `[0x005b1a60,0x005b1c32)`, size `0x1d2`, body SHA256 `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`; name `NewSayToUserMessageInputPane__OnSubmitInput`; type `void __thiscall NewSayToUserMessageInputPane__OnSubmitInput(NewSayToUserMessageInputPane *this)` with ECX `NewSayToUserMessageInputPane *this`; frame `{1 var_434 @+0x4 size 0x4 MemoryMan *; 2 WideCharStr @+0x8 size 0x2 WCHAR; 3 Src @+0x208 size 0x1 _BYTE; 4 destination @+0x209 size 0x1 unsigned __int8; 5 var_22E @+0x20a size 0x1 _BYTE; 6 var_22D @+0x20b size 0x1 _BYTE; 7 MultiByteStr @+0x334 size 0x100 CHAR[256]; 8 var_4 @+0x434 size 0x4 _DWORD; 9 __saved_registers @+0x438 size 0x4 _DWORD; 10 __return_address @+0x43c size 0x4 _UNKNOWN *}`; AR `absent`; AP `absent`; FR `NewSayToUserMessageInputPane::OnSubmitInput(). Validates and sanitizes nonempty text, serializes opcode 0x19 plus one-byte recipient/message lengths into a 300-byte packet, and queues it through g_packetSender.`; FP `NewSayToUserMessageInputPane::OnSubmitInput();`; inbound xrefs total `1`, code `{}`, data `{0x0062f7d0}` | apply |

### A02 dependency-ordered deterministic stages

Every A02 state below repeats the full six-row frame literally. A02B changes the function prototype to use `void *eventHandlerFacet, Event *Block` and retypes physical row 5 from `void *` to `Event *` while preserving its name `Block`. A02C changes only the physical row name from `Block` to `event` while the prototype still spells `Block`. A02D changes only the prototype's second-parameter spelling from `Block` to `event`; the physical row remains `event`/`Event *`. The non-stack ECX presentation introduced at A02B must remain the secondary EventHandler facet at complete-object `+0xa0`, never a complete-object `NewSayToUserMessageInputPane *`.

| ID | Complete required prestate | Endpoint and independently protected fields | Complete expected readback | Classification |
| --- | --- | --- | --- | --- |
| A02A | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `sub_5B1C40`; type `bool __thiscall(TimerHandler *this, Event *Block)` with ECX `TimerHandler *this`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 Block @+0x24 size 0x4 void *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | Invoke `rename` with `pure:true` to `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`. Owned field: function name only. Independently protect type/ECX secondary-facet presentation, all six current frame rows/count, AR/AP/FR/FP, range, size, body hash/bytes, calling convention, and exact xrefs; destination-name collision or any non-name delta is a hard stop. | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall(TimerHandler *this, Event *Block)` with ECX `TimerHandler *this`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 Block @+0x24 size 0x4 void *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | apply |
| A02B | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall(TimerHandler *this, Event *Block)` with ECX `TimerHandler *this`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 Block @+0x24 size 0x4 void *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | Invoke function `set_type` with `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)`. Owned fields: function prototype, non-stack ECX presentation, and physical frame row 5 type only. The signature intentionally preserves parameter spelling `Block`; physical row 5 name `Block` is independently protected. Also protect function name, frame rows 1-4 and 6, all six offsets/sizes/count, AR/AP/FR/FP, range, size, body hash/bytes, `__thiscall`, exact xrefs, and secondary-facet semantics. Any row-name change, non-row-5 frame delta, or other protected delta is a hard stop. | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 Block @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | apply |
| A02C | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 Block @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | Invoke public `rename` with stack batch `func_addr:"0x005b1c40", old:"Block", new:"event"`, `allow_overwrite:false`, `dry_run:false`, and `stop_on_error:true`. Owned field: physical frame row 5 name only. Independently protect the prototype spelling `Event *Block`, ECX/secondary-facet constraint, row 5 type/offset/size, frame rows 1-4 and 6, row count, function name, AR/AP/FR/FP, range, size, body hash/bytes, calling convention, and exact xrefs. Any prototype delta, type delta, collision, or other protected delta is a hard stop. | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | apply |
| A02D | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | Invoke function `set_type` with `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)`. Owned field: function prototype second-parameter spelling only. Independently protect the function name, ECX/secondary-facet constraint, complete six-row frame including physical row 5 `event`/`Event *`, all offsets/sizes/count, AR/AP/FR/FP, range, size, body hash/bytes, calling convention, and exact xrefs. Any physical frame delta or other protected delta is a hard stop. | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | apply |
| A02E | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `absent`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | Invoke `set_function_comments` with `NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event). The incoming receiver is the EventHandler facet at complete-object +0xa0; empty unmodified Backspace closes this pane and constructs SayToUserNameInputPane, otherwise delegates to LineInputPane.`. Owned field: FR only. Independently protect name, type/ECX and secondary-facet constraint, all six final frame rows/count, AR/AP/FP, range, size, body hash/bytes, calling convention, and exact xrefs; any non-FR delta is a hard stop. | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event). The incoming receiver is the EventHandler facet at complete-object +0xa0; empty unmodified Backspace closes this pane and constructs SayToUserNameInputPane, otherwise delegates to LineInputPane.`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | apply |
| A02F | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event). The incoming receiver is the EventHandler facet at complete-object +0xa0; empty unmodified Backspace closes this pane and constructs SayToUserNameInputPane, otherwise delegates to LineInputPane.`; FP `absent`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | Invoke `set_repeatable_comments` with `NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event); secondary EventHandler facet receiver at +0xa0.`. Owned field: FP only. Independently protect name, type/ECX and secondary-facet constraint, all six final frame rows/count, AR/AP/FR, range, size, body hash/bytes, calling convention, and exact xrefs; any non-FP delta is a hard stop. | function range `[0x005b1c40,0x005b1d42)`, size `0x102`, body SHA256 `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`; name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`; type `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)` with ECX `void *eventHandlerFacet`, constrained to the secondary EventHandler facet at complete-object `+0xa0`; frame `{1 var_C @+0x10 size 0x4 _DWORD; 2 var_4 @+0x18 size 0x4 _DWORD; 3 __saved_registers @+0x1c size 0x4 _DWORD; 4 __return_address @+0x20 size 0x4 _UNKNOWN *; 5 event @+0x24 size 0x4 Event *; 6 arg_4 @+0x28 size 0x4 _DWORD}`; AR `absent`; AP `absent`; FR `NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event). The incoming receiver is the EventHandler facet at complete-object +0xa0; empty unmodified Backspace closes this pane and constructs SayToUserNameInputPane, otherwise delegates to LineInputPane.`; FP `NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event); secondary EventHandler facet receiver at +0xa0.`; inbound xrefs total `1`, code `{}`, data `{0x0062f7e0}` | apply |

The Section 21 classification allocation is exact: 12 rows total, with 10 `apply` stages and 2 `already present` protections. Dependency order is P01 verification, A01A, A01B, A01C, A01D, A02A, A02B, A02C, A02D, A02E, A02F, and P02 verification; P01 and P02 remain protected throughout every stage.

Evidence-only scope boundary: the padding spans, raw no-route UID000404 helper, compiler adjustor/scalar wrappers, vtable cells/address points, globals, and support UDTs remain fully documented in Sections 13-20 and the claim ledger. They are not Gate 2B entities in this report, no comment/xref prestate or mutable readback is asserted for them here, and no endpoint is authorized for them. Any attempt to widen Gate 2B beyond P01, A01A-A01D, A02A-A02F, and P02 is a hard stop.

### Complete stack-frame contracts

Frame P01, constructor protection:

| Row | Complete current row | Exact expected row | Permitted delta |
| --- | --- | --- | --- |
| 1 | `var_118`, offset `+0x10`, size `0x4`, type `LineInputPane *` | `var_118`, offset `+0x10`, size `0x4`, type `LineInputPane *` | none |
| 2 | `var_114`, offset `+0x14`, size `0x4`, type `_DWORD` | `var_114`, offset `+0x14`, size `0x4`, type `_DWORD` | none |
| 3 | `promptText`, offset `+0x18`, size `0x2`, type `wchar_t` | `promptText`, offset `+0x18`, size `0x2`, type `wchar_t` | none |
| 4 | `var_10`, offset `+0x118`, size `0x4`, type `_DWORD` | `var_10`, offset `+0x118`, size `0x4`, type `_DWORD` | none |
| 5 | `var_C`, offset `+0x11c`, size `0x4`, type `_DWORD` | `var_C`, offset `+0x11c`, size `0x4`, type `_DWORD` | none |
| 6 | `var_4`, offset `+0x124`, size `0x4`, type `_DWORD` | `var_4`, offset `+0x124`, size `0x4`, type `_DWORD` | none |
| 7 | `__saved_registers`, offset `+0x128`, size `0x4`, type `_DWORD` | `__saved_registers`, offset `+0x128`, size `0x4`, type `_DWORD` | none |
| 8 | `__return_address`, offset `+0x12c`, size `0x4`, type `_UNKNOWN *` | `__return_address`, offset `+0x12c`, size `0x4`, type `_UNKNOWN *` | none |
| 9 | `recipientName`, offset `+0x130`, size `0x4`, type `const wchar_t *` | `recipientName`, offset `+0x130`, size `0x4`, type `const wchar_t *` | none |
| 10 | `arg_4`, offset `+0x134`, size `0x4`, type `_DWORD` | `arg_4`, offset `+0x134`, size `0x4`, type `_DWORD` | none |

P01 frame counts: current 10, expected 10, added 0, removed 0, renamed 0, retyped 0, shifted 0, resized 0. Stop if any row, count, prototype, function range, name, comment channel, or exact five-code-xref/zero-data-xref set differs; P01 authorizes no endpoint.

Frame A01B, submit `set_type` contract:

| Row | Complete current row | Exact expected row | Permitted delta |
| --- | --- | --- | --- |
| 1 | `var_434`, offset `+0x4`, size `0x4`, type `MemoryMan *` | `var_434`, offset `+0x4`, size `0x4`, type `MemoryMan *` | none |
| 2 | `WideCharStr`, offset `+0x8`, size `0x2`, type `WCHAR` | `WideCharStr`, offset `+0x8`, size `0x2`, type `WCHAR` | none |
| 3 | `Src`, offset `+0x208`, size `0x1`, type `_BYTE` | `Src`, offset `+0x208`, size `0x1`, type `_BYTE` | none |
| 4 | `destination`, offset `+0x209`, size `0x1`, type `unsigned __int8` | `destination`, offset `+0x209`, size `0x1`, type `unsigned __int8` | none |
| 5 | `var_22E`, offset `+0x20a`, size `0x1`, type `_BYTE` | `var_22E`, offset `+0x20a`, size `0x1`, type `_BYTE` | none |
| 6 | `var_22D`, offset `+0x20b`, size `0x1`, type `_BYTE` | `var_22D`, offset `+0x20b`, size `0x1`, type `_BYTE` | none |
| 7 | `MultiByteStr`, offset `+0x334`, size `0x100`, type `CHAR[256]` | `MultiByteStr`, offset `+0x334`, size `0x100`, type `CHAR[256]` | none |
| 8 | `var_4`, offset `+0x434`, size `0x4`, type `_DWORD` | `var_4`, offset `+0x434`, size `0x4`, type `_DWORD` | none |
| 9 | `__saved_registers`, offset `+0x438`, size `0x4`, type `_DWORD` | `__saved_registers`, offset `+0x438`, size `0x4`, type `_DWORD` | none |
| 10 | `__return_address`, offset `+0x43c`, size `0x4`, type `_UNKNOWN *` | `__return_address`, offset `+0x43c`, size `0x4`, type `_UNKNOWN *` | none |

A01B frame counts: current 10, expected 10, added 0, removed 0, renamed 0, retyped 0, shifted 0, resized 0. The only type delta is the non-stack ECX receiver presentation from `WCHAR *this` to `NewSayToUserMessageInputPane *this`. Stop before A01C if `set_type` changes any stack row, count, function range, bytes, xrefs, calling convention, name, or comment channel.

Frame A02B, key/text first function `set_type` contract:

| Row | Complete current row | Exact expected row | Permitted delta |
| --- | --- | --- | --- |
| 1 | `var_C`, offset `+0x10`, size `0x4`, type `_DWORD` | `var_C`, offset `+0x10`, size `0x4`, type `_DWORD` | none |
| 2 | `var_4`, offset `+0x18`, size `0x4`, type `_DWORD` | `var_4`, offset `+0x18`, size `0x4`, type `_DWORD` | none |
| 3 | `__saved_registers`, offset `+0x1c`, size `0x4`, type `_DWORD` | `__saved_registers`, offset `+0x1c`, size `0x4`, type `_DWORD` | none |
| 4 | `__return_address`, offset `+0x20`, size `0x4`, type `_UNKNOWN *` | `__return_address`, offset `+0x20`, size `0x4`, type `_UNKNOWN *` | none |
| 5 | `Block`, offset `+0x24`, size `0x4`, type `void *` | `Block`, offset `+0x24`, size `0x4`, type `Event *` | retype `void *` to `Event *`; preserve physical name `Block` and offset/size |
| 6 | `arg_4`, offset `+0x28`, size `0x4`, type `_DWORD` | `arg_4`, offset `+0x28`, size `0x4`, type `_DWORD` | none |

A02B frame counts: current 6, expected 6, added 0, removed 0, renamed 0, retyped 1, shifted 0, resized 0. The exact function prototype changes to `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)` while the physical row name remains `Block`; ECX must remain the secondary EventHandler facet at complete-object `+0xa0`, never a complete `NewSayToUserMessageInputPane *`. Stop before A02C unless row 5 is exactly `Block`/`Event *` and every other frame/comment/xref/range/body field is exact.

Frame A02C, key/text specialized stack `rename` contract:

| Row | Complete current row | Exact expected row | Permitted delta |
| --- | --- | --- | --- |
| 1 | `var_C`, offset `+0x10`, size `0x4`, type `_DWORD` | `var_C`, offset `+0x10`, size `0x4`, type `_DWORD` | none |
| 2 | `var_4`, offset `+0x18`, size `0x4`, type `_DWORD` | `var_4`, offset `+0x18`, size `0x4`, type `_DWORD` | none |
| 3 | `__saved_registers`, offset `+0x1c`, size `0x4`, type `_DWORD` | `__saved_registers`, offset `+0x1c`, size `0x4`, type `_DWORD` | none |
| 4 | `__return_address`, offset `+0x20`, size `0x4`, type `_UNKNOWN *` | `__return_address`, offset `+0x20`, size `0x4`, type `_UNKNOWN *` | none |
| 5 | `Block`, offset `+0x24`, size `0x4`, type `Event *` | `event`, offset `+0x24`, size `0x4`, type `Event *` | rename physical row `Block` to `event`; preserve type/offset/size |
| 6 | `arg_4`, offset `+0x28`, size `0x4`, type `_DWORD` | `arg_4`, offset `+0x28`, size `0x4`, type `_DWORD` | none |

A02C frame counts: current 6, expected 6, added 0, removed 0, renamed 1, retyped 0, shifted 0, resized 0. The function prototype must remain exactly `bool __thiscall NewSayToUserMessageInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *Block)` even though the physical row now reads `event`/`Event *`. Stop before A02D on any prototype, frame type/offset/size/count, ECX, comment, xref, range, or body delta beyond that one row-name change.

Frame A02D, key/text second function `set_type` contract:

| Row | Complete current row | Exact expected row | Permitted delta |
| --- | --- | --- | --- |
| 1 | `var_C`, offset `+0x10`, size `0x4`, type `_DWORD` | `var_C`, offset `+0x10`, size `0x4`, type `_DWORD` | none |
| 2 | `var_4`, offset `+0x18`, size `0x4`, type `_DWORD` | `var_4`, offset `+0x18`, size `0x4`, type `_DWORD` | none |
| 3 | `__saved_registers`, offset `+0x1c`, size `0x4`, type `_DWORD` | `__saved_registers`, offset `+0x1c`, size `0x4`, type `_DWORD` | none |
| 4 | `__return_address`, offset `+0x20`, size `0x4`, type `_UNKNOWN *` | `__return_address`, offset `+0x20`, size `0x4`, type `_UNKNOWN *` | none |
| 5 | `event`, offset `+0x24`, size `0x4`, type `Event *` | `event`, offset `+0x24`, size `0x4`, type `Event *` | none |
| 6 | `arg_4`, offset `+0x28`, size `0x4`, type `_DWORD` | `arg_4`, offset `+0x28`, size `0x4`, type `_DWORD` | none |

A02D frame counts: current 6, expected 6, added 0, removed 0, renamed 0, retyped 0, shifted 0, resized 0. The only permitted delta is the function prototype's second-parameter spelling from `Event *Block` to `Event *event`; ECX, the complete physical frame, comments, xrefs, range, and body remain exact. Stop before A02E unless both prototype and physical row now spell `event` and every protected field is exact.

### Endpoint order, readback, and stop conditions

- Before A01A and A02A, require the exact current function range/size/body hash, name, prototype/ECX presentation, complete current frame, AR/AP/FR/FP, and exact inbound code/data xref sets stated in those rows. Require each destination name to be collision-free. A mismatch or collision is a hard stop, not an invitation to coerce state.
- Invoke only one public semantic endpoint per stage. A01 order is A01A function `rename` with `pure:true`, A01B function `set_type`, A01C `set_function_comments`, then A01D `set_repeatable_comments`. A02 order is A02A function `rename` with `pure:true`, A02B function `set_type` to `Event *Block`, A02C specialized stack `rename` from `Block` to `event`, A02D function `set_type` to `Event *event`, A02E `set_function_comments`, then A02F `set_repeatable_comments`. After every endpoint, read back the complete expected state printed in that row and require byte-for-byte state continuity with the next row's complete required prestate. Do not use address-comment endpoints because AR and AP must remain `absent` throughout.
- A01D succeeds only with name `NewSayToUserMessageInputPane__OnSubmitInput`, exact proposed prototype/ECX, exact FR/FP, AR/AP absent, exact unchanged ten-row frame, body identity, range/size, and one-data-xref set. A02F succeeds only with name `NewSayToUserMessageInputPane__HandleKeyOrTextEvent`, exact final prototype, secondary-facet ECX at complete-object `+0xa0`, exact FR/FP, AR/AP absent, exact six-row final frame with row 5 `event`/`Event *`, body identity, range/size, and one-data-xref set.
- Stop before any later endpoint or save if a requested endpoint changes bytes, function range, xrefs, calling convention, an unpermitted frame field, an address comment, or any protected P-row entity. Gate 2B backup/save/rollback mechanics remain supervisor-owned and are not encoded in this report.
- Do not force packet locals into invented noncontiguous arrays. A01A-A01D change only the explicitly owned semantic fields; the physical packet remains represented by the protected split frame labels while Section 22 carries the human-source array.

## First-Draft C++ Recommendation

- Eligible: all three target methods are source-bearing and behaviorally closed.
- UID000403 formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)
    : LineInputPane(0)
{
    wchar_t prompt[128];

    wcscpy_s(m_recipientName, _countof(m_recipientName), recipientName);
    swprintf_s(prompt, _countof(prompt), L"To %s : ", m_recipientName);
    SetPromptText(prompt);
}

void NewSayToUserMessageInputPane::OnSubmitInput()
{
    if (TextLength() > 0) {
        wchar_t messageText[256];
        char convertedText[256];
        unsigned char packet[0x12c];

        CopyText(messageText, 255);
        ValidateChatInputOrThrowPasswordError(messageText);
        SanitizeWideTextForChat(messageText, wcslen(messageText));

        int packetLength = 0;
        PacketBufferWriteUInt8(0x19, packet + packetLength++);

        const unsigned int recipientLength = WideCharToMultiByte(
            CP_ACP, 0, m_recipientName,
            static_cast<int>(wcslen(m_recipientName)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[recipientLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(recipientLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, recipientLength);
        packetLength += recipientLength;

        const unsigned int messageLength = WideCharToMultiByte(
            CP_ACP, 0, messageText,
            static_cast<int>(wcslen(messageText)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[messageLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(messageLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, messageLength);
        packetLength += messageLength;

        packet[packetLength] = 0;
        g_packetSender->QueueAndSendPacket(
            packet, static_cast<short>(packetLength));
    }
}

bool NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

    if (event->m_payload.m_key.m_modifiers != 0 ||
        key != '\b' ||
        TextLength() > 0) {
        return LineInputPane::HandleKeyOrTextEvent(event);
    }

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    g_pUserPane->ClearActiveLineInputPane();

    if (g_pChattingHandlePane->m_chatTargetPending) {
        g_pUserPane->m_currentSayMode = kSayInputModeDefault;
        g_pChattingVarietyPane->Refresh();
    }

    new SayToUserNameInputPane();
    return true;
}
```

- UID000403 formal `RECONSTRUCTION_H CODE` remains blank. The class owner supplies the declaration.
- UID000099 formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
#include "SayInputPanes.h"

[[CHILDREN]]
```

- UID000099 formal `RECONSTRUCTION_H CODE` replacement:

```cpp
#include "../ui/dialogs/InputPanes.h"

class NewSayToUserMessageInputPane : public LineInputPane
{
public:
    explicit NewSayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_recipientName[128];
};
```

- UID0000C3 `SayInputPane` currently carries the same `#include "../ui/dialogs/InputPanes.h"` at the start of its H block. Once UID000099 is the earliest H emitter, remove that one duplicate include from UID0000C3 while preserving its complete class declaration byte-for-byte; the combined generated header must contain exactly one such include before the first derived declaration.
- The exact support dependency is a complete `SayToUserNameInputPane` declaration in `SayInputPanes.h` before the CPP is parsed. Move the existing UID0000C7 declaration from CPP to H and leave its CPP `[[CHILDREN]]`; do not duplicate that declaration on UID000403 and do not replace the direct construction with a helper call. UID0000C7's own method-body naming is separate source-quality ownership and receives no additional-target credit here.
- Fixed arrays and indexed writes regenerate the observed range-check instrumentation; explicit calls or silent bounds returns do not belong in source.
- `PacketBufferWriteUInt8` is retained for opcode and length bytes. `memcpy` is the human-source representation of the recovered MemoryMan wrapper.
- The key body deliberately lacks an event-type gate because the binary lacks one. The current Event payload layout makes its direct key/modifier reads exact.
- Third-party import is not applicable.

## Final Recommendation

- UID000403: the callback retained range/owner/emitter/reconstructable state, set `94/95`, replaced complete CPP with Section 22, and kept H blank.
- UID000099: the callback set `93/94`, moved the clean declaration to H, made CPP include the shared header and emit children, and removed explicit derived-destructor and stale `InputEvent`/`OnKeyInput` source from this owner.
- UID0000N9: the callback retained `89/90` and updated the modern class/source-topology detail; dated validator-owned command `000000023637` and its physical readback proved the generated module structurally coherent for the accepted scope at callback completion.
- UID0000C7: the callback made the existing complete declaration H-visible as the direct-construction dependency without claiming closure of its independently stale method child.
- UID000404 and compiler artifacts remain ownerless/non-emitting or compiler-covered exactly as documented.
- No new UID, split, merge, file, owner, or emitter is recommended. No in-scope target research remains deferred.

## Recommended Target Doc Changes

- Path: `by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md`.
- Applied metadata `COMPLETION:94`, `CONFIDENCE:95`; preserved owner/emitter `000099`, reconstructable true, optional position blank, and `Nested:0`.
- Replaced the entire formal CPP with Section 22 target code and kept formal H blank.
- Corrected the key method name/signature in status, ranges, evidence, and summaries to `HandleKeyOrTextEvent(Event *event)`.
- Added exact stack facts, body/padding/full-range hashes, vtable window hash, all five caller roles, function types/comments prestate, and generated checkpoints.
- Replaced packet-shape prose with one reusable 256-byte conversion buffer, one 300-byte packet, three `PacketBufferWriteUInt8` calls, two payload copies, compiler range-check instrumentation, both converted-string terminators, local packet terminator, and counted send length.
- Expanded empty-Backspace behavior to include unconditional translation, modifier/key/text gates, base delegation, deferred deletion, active-input clear, conditional mode reset/refresh, direct name-pane construction, and true return; explicitly recorded that no event-type gate exists.
- Preserved stale two-buffer/`0x230`/silent-return/helper/key-signature assumptions as superseded history rather than deleting the correction trail.

## Recommended Support Doc Changes

- `by-class/NewSayToUserMessageInputPane.md`: applied `93/94` and Section 22 owner CPP/H; updated method table, exact receiver/signature, packet source shape, cleanup order, UDT/vtable/caller facts, generated history, and compiler-only destructor/thunk policy.
- `by-class/SayInputPane.md`: removed only its leading `#include "../ui/dialogs/InputPanes.h"`; preserved the complete declaration, score, owner/emitter, and children. The earlier UID000099 H fragment now provides exactly one required include before all derived declarations.
- `by-file/SayInputPanes.md`: retained `89/90`; replaced standalone-path wording with shared `SayInputPanes.h` declaration / `SayInputPanes.cpp` namespace-scope child topology; recorded UID0000C7's complete-type dependency and the dated pre-callback generated defect.
- `by-class/SayToUserNameInputPane.md`: moved the existing complete declaration to formal H and kept formal CPP children-only. Behavior/layout and independently stale method-source status were preserved without claiming UID0000C7 source-quality coverage.
- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`: corrected modern Event/key terminology and retained the UID000403 live exact-child / UID000404 zero-route distinction without a score, owner, or emitter change.
- `by-type/by-vtable/InputPaneBaseVtableFamily.md` and `by-class/LineInputPane.md`: no edit is required; their already accepted `HandleKeyOrTextEvent(Event *)` contract is same-or-greater support evidence and must not be changed.
- Caller, global, Event, UserPane, ChattingVarietyPane, prompt, Socket, and packet-helper pages already contain same-or-greater dependency facts; no metadata or formal-source changes are justified solely by this report.
- Manual coverage changes are supervisor-owned and supplied exactly in Section 28. Generated files, trackers, audit/lifecycle files, and catalogs remain untouched.

## Score And Metadata Recommendation

- UID000403 is now `94/95`, raised from assignment-time `86/90`. Completion rises because all three bodies now have exact source-facing code, every byte/range has a disposition, packet locals and instrumentation are corrected, and the key body is behaviorally complete. Confidence is capped at 95 because original symbols and exact lexical names are unavailable.
- UID000099 is now `93/94`, raised from assignment-time `87/90` after owner CPP/H correction. Exact class size, member, constructor, methods, vtables, callers, compiler wrappers, and source route are closed. Confidence is one point below the child because the historical physical filename cannot be proven.
- UID0000N9 remains `89/90`. This child strengthens the file and the accepted-scope generated topology is now coherent, but broader file-quality items outside UID000403 remain independently owned, so no file-level increase is defensible here.
- UID0000C7 remains `87/91` in this report. Moving its existing complete type to H solves the direct-construction dependency but does not independently close its full method source.
- Owner/emitter/reconstructable/optional-position/Nested values remain unchanged for UID000403. No additional UID is declared.
- Score blockers resolved and implemented: exact key signature, complete cleanup, packet storage, conversion-buffer count, bounds semantics, helper liveness, receiver adjustment, caller identities, vtable liveness, class layout, source topology, and generated readback.
- Residual non-blockers: original identifier spellings, possible historical Whisper file split, and unrelated module-wide generated defects. Each is reflected in confidence or file-level score rather than deferred as target research.

## Open Questions With Attempted Resolution

- Was the original key method named `OnKeyInput`, `HandleKeyInput`, or `HandleKeyOrTextEvent`? Shared vtable-family documentation, accepted `LineInputPane`, and the exact base callee resolve it to `HandleKeyOrTextEvent(Event *)`; no open target question remains.
- Was there an `event->m_type == kEventKeyDown` gate? Full decompilation and field-access inspection show no type read. Resolution: omit it even though sibling handlers may use one.
- Did source silently reject long converted strings? All three failure branches target `___report_rangecheckfailure`, and fixed-array indexed source explains them. Resolution: no authored silent returns.
- Was packet capacity `0x230`? Stack offsets prove exactly 300 contiguous bytes. Resolution: `0x12c`.
- Were recipient and message conversions held in separate arrays? One physical `CHAR[256]` is reused. Resolution: one buffer.
- Did submit call UID000404? Callees, xrefs, and encoded-pointer searches are negative. Resolution: inline serialization and non-emitting neighbor.
- Should empty Backspace call the named opener? The body directly calls operator new and `0x005b3cb0`; no opener call exists. Resolution: direct construction.
- Can `ClearActiveLineInputPane()` and `Refresh()` be used? Current support docs prove the exact inline clear operation and virtual bounds-invalidation operation. Resolution: use accepted source-facing names while labeling lexical inference.
- Is a separate Whisper source file stronger? No current source metadata or ownership route supports it. Resolution: retain `SayInputPanes` and reflect residual filename uncertainty only in confidence.
- Does UID0000C7's stale independent method source block UID000403 research? No. Its complete class type must be H-visible for direct construction, but its own method body remains a separately owned source-quality item. The exact target body and binary behavior are not uncertain.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The current manual rows were read at `by-memory/-coverage-report.md:4072`, `by-memory/-coverage-report.md:4075`, `by-class/-coverage-report.md:285`, `by-class/-coverage-report.md:359`, `by-class/-coverage-report.md:461`, `by-class/-coverage-report.md:465`, and `by-file/-coverage-report.md:235`. The UID0001LY row at line 4072 already states exact-child emission and no-route helper exclusion; the UID000077 row at line 285 already states the canonical Event contract; and the UID0000C3 row at line 461 already accurately describes its class-H/child-CPP topology without assigning ownership of the shared include. Those three rows need no change. Apply these four exact one-line replacements after accepted ordinary-doc implementation:

- File/placement: replace the UID000403 row in `by-memory/-coverage-report.md`.

`        - [UID:000403][0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods](by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md) 0x005b1990-0x005b1d42 | class method cluster | NewSayToUserMessageInputPane methods : reconstructable : 94% : very-strong : Exact modern direct-message constructor, one-buffer 300-byte opcode 0x19 submit serialization, and Event-based HandleKeyOrTextEvent empty-Backspace cleanup; five constructor callers, submit/key vtable liveness, m_recipientName[128], prompt, padding, compiler range-check behavior, and no-route helper/compiler-artifact exclusions are closed.`

- File/placement: replace the UID000099 row in `by-class/-coverage-report.md`.

`- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md) : reconstructable : 93% : very-strong : Complete 0x208 modern direct-message class with SayInputPanes.h declaration, namespace-scope exact-child definitions, m_recipientName[128] at +0x108, five constructor routes, three vtable views, opcode 0x19 submit, Event-based empty-Backspace return-to-name cleanup, and compiler-only destructor/adjustor handling.`

- File/placement: replace the UID0000C7 row in `by-class/-coverage-report.md` to synchronize its current metadata and H-visible dependency role without claiming additional report coverage.

`- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) : reconstructable : 87% : very-strong : Recipient-name input pane with exact constructor/history/confirmation boundaries, recent and fallback recipient cursors, modern/legacy follow-up construction, and a complete SayInputPanes.h-visible class type required by NewSayToUserMessageInputPane's direct empty-Backspace transition; its independently owned method-source refinements remain separate.`

- File/placement: replace the UID0000N9 row in `by-file/-coverage-report.md`.

`- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) : reconstructable : 89% : very-strong : Shared social input-pane module whose class declarations belong in SayInputPanes.h and exact method children emit at namespace scope in SayInputPanes.cpp; UID000401 closes the legacy direct-message source shape and UID000403 closes the modern constructor/submit/key shape while no-route helper clones remain non-emitting.`

These manual files are supervisor-owned for this workflow. No validator-owned `auto-generated/-ag-*` row text is proposed.

## Follow-Up Actions

- Supervisor Gate 2A: audit this exact post-callback report artifact, its 33 headings, 50/50 twin parity, 45 checked/5 unchecked allocation, current ordinary-document hashes, validator receipts, and generated `SayInputPanes.cpp/.h` readback. Generated output was refreshed only through validators and was never edited directly.
- Supervisor manual coverage work remains C049 and must use the four exact rows in Section 28; no manual coverage page was changed by Agent-B002.
- Supervisor Gate 2B: dynamically re-attest the canonical IDB, verify the fully restored literal prestates, preserve P01/P02 and negative constraints, apply A01A-A01D then the disposable-proven A02A-A02F sequence through the supervisor workflow, and require each complete staged readback before any later endpoint or save.
- No A-agent action or new B-agent research target is required for UID000403. UID0000C7's independent method-source refinement remains under its own UID and is not silently claimed here.

## Confidence

- Recommendation confidence: `95/100`.
- Score confidence: `94/100` for UID000403 `94/95`; `92/100` for UID000099 `93/94`.
- Exact behavior/range/layout/protocol/liveness confidence: `99/100`.
- Source-placement confidence: `92/100` because stripped binaries cannot prove original filenames, while current family and project routing strongly support `SayInputPanes`.
- Remaining uncertainty is lexical and module-wide, not behavioral: exact original helper/accessor names and the historical physical source partition. It does not block target CPP.

## Validator Results

| Command ID | Command timestamp | Exact working directory | Exact single-line command | Exit / ok | Command-specific warnings and errors | Generated-refresh state | Relevant side effects | Final physical reread / hash |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `000000023620` | `2026-08-14T18:28:24-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md --apply` | Exit `0`; `ok: 1`. | Direct warning: `missing_ref_uid` for UID0003JQ; no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID000403 and the same target path, exit `0`, with one root/one report and registry rebuild `5,534` nodes/`4,291` edges. | Accepted `94/95` and temporarily emitted `reference_index_remove` for exactly UID0002VH, UID0000SG, UID0000QK, UID0002X5, and UID0002XE because their explicit Markdown links had been dropped from the edited target prose. Agent-B002 restored those five links in that same target before command `000000023621`; no support page was changed. Worker effects were memory-coverage metadata refresh, `SayInputPanes.cpp` update, `SayInputPanes.h` metadata refresh, research-tracker update, and by-memory auto-coverage update. | Final physical reread of `by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md`: SHA256 `6887213193C62051F8044D71E4AE7D237466B838BB86694AC1137505234C7E62`, `14,299` bytes, `156` lines. |
| `000000023621` | `2026-08-14T18:28:55-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md --apply` | Exit `0`; `ok: 1`. | Direct warning: `missing_ref_uid` for UID0003JQ; no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID000403 and the same target path, exit `0`, with one root/one report and registry rebuild `5,534` nodes/`4,291` edges. | Emitted the corresponding `reference_index_add` results for exactly the restored UID0002VH, UID0000SG, UID0000QK, UID0002X5, and UID0002XE links; final target content and `94/95` were accepted. Worker effects were memory-coverage metadata refresh, `SayInputPanes.cpp` metadata refresh, `SayInputPanes.h` metadata refresh, research-tracker metadata refresh, and by-memory auto-coverage update. | Final physical reread of `by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md`: SHA256 `6887213193C62051F8044D71E4AE7D237466B838BB86694AC1137505234C7E62`, `14,299` bytes, `156` lines. |
| `000000023622` | `2026-08-14T18:30:07-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-class/NewSayToUserMessageInputPane.md --apply` | Exit `0`; `ok: 1`. | Direct warning: `missing_ref_uid` for UID0003JQ; no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID000099 and the same owner path, exit `0`, with one root/one report and registry rebuild `5,534` nodes/`4,291` edges. | Accepted owner CPP/H routing and `93/94`. Worker effects were class auto-coverage update, `SayInputPanes.cpp` update, `SayInputPanes.h` update, and research-tracker update. | Final physical reread of `by-class/NewSayToUserMessageInputPane.md`: SHA256 `5818B3B81767A6B969468DB39B22DB923750560502AFE1F7EA00C2A9B7E48072`, `15,638` bytes, `122` lines. |
| `000000023623` | `2026-08-14T18:30:29-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-class/SayInputPane.md --apply` | Exit `0`; `ok: 1`. | No direct command-specific warning and no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID0000C3 and the same class path, exit `0`, with one root/one report and registry rebuild `5,534` nodes/`4,291` edges. | Accepted removal of the one duplicate leading include without score/emitter change. Worker effects were class-coverage metadata refresh, `SayInputPanes.cpp` metadata refresh, `SayInputPanes.h` update, and research-tracker metadata refresh. | Final physical reread of `by-class/SayInputPane.md`: SHA256 `B63BAE0EFF3D47DE57CED49760E3983DC2D6B31CE868BFC088EC30A3DBE50999`, `24,418` bytes, `139` lines. |
| `000000023624` | `2026-08-14T18:31:36-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-file/SayInputPanes.md --apply` | Exit `0`; `ok: 1`. | Direct warnings: `missing_ref_uid` for UID0003JM, UID0003JQ, UID000406, and UID0003JR; no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID0000N9 and the same file path, exit `0`, with one root/one report and registry rebuild `5,534` nodes/`4,291` edges. | Accepted shared CPP/H topology and dated history. Worker effects were file-coverage metadata refresh, `SayInputPanes.cpp` metadata refresh, `SayInputPanes.h` metadata refresh, and research-tracker metadata refresh. | Final physical reread of `by-file/SayInputPanes.md`: SHA256 `FB37E52891F71DD58F825EE60831563DA8B53F4DE2C31A41694469D795F4795B`, `56,325` bytes, `266` lines. |
| `000000023625` | `2026-08-14T18:32:11-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-class/SayToUserNameInputPane.md --apply` | Exit `0`; `ok: 1`. | No direct command-specific warning and no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID0000C7 and the same class path, exit `0`, with one root/one report and registry rebuild `5,534` nodes/`4,291` edges; that generated state was later superseded by the separately preserved command `000000023637` header provenance. | Accepted the complete declaration move to H and children-only CPP without claiming the independently stale method body solved. Worker effects were class auto-coverage update, `SayInputPanes.cpp` update, `SayInputPanes.h` update, and research-tracker metadata refresh. | Final physical reread of `by-class/SayToUserNameInputPane.md`: SHA256 `FD802635E0A7E55D129BE2C1083CDD630AE389F36CED85BD128D59258AE0DBB9`, `15,688` bytes, `132` lines. |
| `000000023628` | `2026-08-14T18:34:15-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python tools/validator.py --mode file --file by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md --apply` | Exit `0`; `ok: 1`. | Direct `missing_ref_uid` warnings were UID000406 twice and UID0003JM, UID0003JQ, and UID0003JR once each; no validator error. Deferred worker warnings on this receipt: `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, and `autogen_children_fallback_insert: 9`; worker `stderr` was empty. | Direct result was `generated_refresh: deferred` bound to this command ID/timestamp. Its later worker result was file-incremental for UID0001LY and the same aggregate path, exit `0`, with zero roots/one report and registry rebuild `5,535` nodes/`4,292` edges. | Direct side effects were `reference_index_add` for newly explicit UID000402, `stats_incremental_noop` because UID0001LY was absent from generated stats lists, and `projected_stats_update`; Event/key terminology and the UID000403/UID000404 route distinction were accepted. Worker effects were memory-coverage metadata refresh, research-tracker metadata refresh, and by-memory auto-coverage update; it did not regenerate `SayInputPanes.cpp` or `.h`. | Final physical reread of `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`: SHA256 `CB70BB1CD4F0105CEDCCE8319D042A365ED23D3335DDD5BA21A482E1D8F9AA19`, `23,716` bytes, `192` lines. |

- **Generated-header provenance, not invoked by Agent-B002:** preserved physical post-callback generated readback from validator-owned command `000000023637`: `auto-generated/NexusTK/social/SayInputPanes.cpp` carried `validator-command-id: 000000023637`, refresh timestamp `2026-08-14T18:41:33-04:00`, refresh source `foreground-generated-refresh`, disk last-write `2026-08-14T18:41:53.8344233-04:00`, SHA256 `0B27FC0ED1F9CC98F9E5B36044A99305E1E7F3BBD1C9BE44B7E5691CC3EB6001`, `16,338` bytes, `494` lines. `SayInputPanes.h` carried the same validator metadata, disk last-write `2026-08-14T18:41:53.9038981-04:00`, SHA256 `E978393FF4966292C5C87AD3DE694ABC33612A0111FE589EFB72850AB75F5FC3`, `2,405` bytes, `86` lines. Command `000000023637` is not an Agent-B002 scoped-command receipt and is not authority over unrelated later refreshes.
- Generated structural proof: H has exactly one `#include "../ui/dialogs/InputPanes.h"`, one complete `NewSayToUserMessageInputPane` declaration, and one complete `SayToUserNameInputPane` declaration. CPP has exactly one `#include "SayInputPanes.h"` and exactly one column-zero namespace-scope definition each for the UID000403 constructor, `OnSubmitInput`, and `HandleKeyOrTextEvent(Event *)`; no indented/nested UID000403 definition exists. The pair has zero `[[CHILDREN]]`, `[[EMPTY]]`, TODO, placeholder, stub, or not-implemented markers, zero stale UID000403 `InputEvent`/`OnKeyInput` signatures, and no duplicate target body or required class declaration. UID0000C7's independently stale method body remains present once, as explicitly preserved rather than claimed solved.
- Historical implementation-cycle fact: during the dated ordinary-document callback, generated files were physically reread only and were not manually edited; that callback ran no lifecycle validator or `execute_report` command.
- Historical same-report repair fact: the dated Gate 1 Section 21 repair ran no validator, generated refresh, IDA operation, coverage/lifecycle command, or `execute_report`; the callback receipts and generated hashes above remain dated evidence of that repair cycle.
- Historical same-report Gate 2B repair fact: the 2026-08-15 handoff repair edited only this report and ran no validator, generated refresh, IDA mutation, coverage/lifecycle command, or `execute_report`; bounded read-only MCP only reconfirmed the restored canonical state and the supervisor's disposable endpoint-test result.

## Changed Files

- Historical 2026-08-15 Gate 2B handoff repair fact: only this same report was edited to record the failed no-save attempt, clean rollback, disposable endpoint proof, and corrected A02 staging. No by-* document, coverage/tracker/generated artifact, validator/lifecycle state, canonical IDB, or MCP process was changed by Agent-B002.
- Historical same-report repair fact: in the repair from rejected SHA256 `60E8A108CC2A1CC556933C97B391A42D989079A9CE33E3A6446A4A3DD90FD00F`, only this report changed. That repair did not edit the six ordinary by-* artifacts or validator-owned generated pair; the exact dated callback hashes remain preserved below without asserting control over unrelated later validator refreshes.
- Modified ordinary target: `by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md`, SHA256 `6887213193C62051F8044D71E4AE7D237466B838BB86694AC1137505234C7E62`, `14,299` bytes, `156` lines.
- Modified ordinary owner: `by-class/NewSayToUserMessageInputPane.md`, SHA256 `5818B3B81767A6B969468DB39B22DB923750560502AFE1F7EA00C2A9B7E48072`, `15,638` bytes, `122` lines.
- Modified ordinary include owner: `by-class/SayInputPane.md`, SHA256 `B63BAE0EFF3D47DE57CED49760E3983DC2D6B31CE868BFC088EC30A3DBE50999`, `24,418` bytes, `139` lines.
- Modified ordinary file page: `by-file/SayInputPanes.md`, SHA256 `FB37E52891F71DD58F825EE60831563DA8B53F4DE2C31A41694469D795F4795B`, `56,325` bytes, `266` lines.
- Modified ordinary complete-type support: `by-class/SayToUserNameInputPane.md`, SHA256 `FD802635E0A7E55D129BE2C1083CDD630AE389F36CED85BD128D59258AE0DBB9`, `15,688` bytes, `132` lines.
- Modified ordinary aggregate support: `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`, SHA256 `CB70BB1CD4F0105CEDCCE8319D042A365ED23D3335DDD5BA21A482E1D8F9AA19`, `23,716` bytes, `192` lines.
- Historical implementation-cycle fact: Agent-B002 modified this same report during the dated callback and later same-report repairs; Agent-B002 created no additional report artifact during those edits. The current artifact path and validator-owned status/history metadata are authoritative for report lifecycle state; ordinary report prose makes no current execution/archive assertion.
- Historical implementation-cycle fact: the dated callback produced the validator-owned `SayInputPanes.cpp/.h` generated side effect listed in Validator Results from the ordinary formal channels; neither generated file was manually edited during that callback.
- Historical implementation-cycle fact: Agent-B002 renamed no file during the dated callback. That callback manually edited no coverage, tracker, audit/catalog/lifecycle, goal/note, validator-state, or IDA file; scoped validator-managed index/stats/generated side effects were left as produced. This records that implementation cycle only and makes no current report execution/archive assertion.
- Historical implementation-cycle fact: each ordinary page was leased only for its dated edit/validation batch and released immediately afterward; the post-callback shared lease readback then recorded no active Agent-B002 row.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 000403 | Target identity, snapshot hash, owner/emitter, reconstructable state, and no additional UIDs are exact. | certain | goal and target readback | target metadata/status | already-present | already-present |
| [x] | C002 | 000403 | Full target is `[0x005b1990,0x005b1d42)`, 946 bytes, SHA256 `8291BBB4043B127616CA36105241F6A38D32EFF1AA94E0BDEF3F8F982E09BDB4`. | certain | PE byte extraction | target Covered Ranges/Evidence | incorporate | applied |
| [x] | C003 | 000403 | Constructor is `[0x005b1990,0x005b1a51)`, 193 bytes, hash `FBF0FDA1F3E470A3EACA05AC9D4EF0D6F12BB6543082B040FB02961DBA0BAB67`. | certain | function/bytes | target Covered Ranges | incorporate | applied |
| [x] | C004 | 000403 | `[0x005b1a51,0x005b1a60)` is 15 bytes of `0xcc` alignment, hash `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`. | certain | bytes | target Covered Ranges | incorporate | applied |
| [x] | C005 | 000403 | Submit is `[0x005b1a60,0x005b1c32)`, 466 bytes, hash `6A083D5EEBAEF795F5BA4F9E93EC5076BE44B289C42921C240D06F2269E9416D`. | certain | function/bytes | target Covered Ranges | incorporate | applied |
| [x] | C006 | 000403 | `[0x005b1c32,0x005b1c40)` is 14 bytes of `0xcc`, hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. | certain | bytes | target Covered Ranges | incorporate | applied |
| [x] | C007 | 000403 | Key handler is `[0x005b1c40,0x005b1d42)`, 258 bytes, hash `98FEAB4A374EA51A1CBB5C432B72F6C1AC631C7B9E41714619B7947485FE986A`. | certain | function/bytes | target Covered Ranges | incorporate | applied |
| [x] | C008 | 000403 | `[0x005b1d42,0x005b1d50)` is 14-byte successor padding outside UID000403, same hash as C006. | certain | bytes/boundary | target boundary notes | incorporate | applied |
| [x] | C009 | 000403 | `0x005b1d50` is not an IDA function and has zero xrefs; UID000404 remains a sibling no-route helper. | certain | lookup/xrefs/pointer search | target Evidence/negative history; UID000404 support | already-present | already-present |
| [x] | C010 | 000403 | Primary, secondary, tertiary vtable starts are `0x0062f788`, `0x0062f7d8`, `0x0062f808`; submit/key cells are `0x0062f7d0`/`0x0062f7e0`. | certain | ctor stores/vtable bytes/xrefs | target vtable evidence; class support | incorporate | applied |
| [x] | C011 | 000403 | Constructor is the unique text store source for the three modern vtable starts. | very high | immediate search/constructor | target liveness/layout | incorporate | applied |
| [x] | C012 | 000403 | Class is `0x208`; `LineInputPane` is `0x108`; `wchar_t m_recipientName[128]` begins at `+0x108`. | certain | UDT/type and copy bound | target/class layout | already-present | already-present |
| [x] | C013 | 000403 | Constructor copies recipient with bound `0x80`, formats `L"To %s : "`, and sets prompt after `LineInputPane(0)`. | certain | decompile/callees/string | target CPP/evidence | already-present | already-present |
| [x] | C014 | 000403 | Caller `0x00554e0a` is the Whisper row in `RightButtonMenuPane::OnEvent`. | high | xref and caller decompile/docs | target Caller Inventory | incorporate | applied |
| [x] | C015 | 000403 | Caller `0x0059edc6` is `UserListPane::OnItemActivated` modern branch. | certain | xref/caller decompile | target Caller Inventory | already-present | already-present |
| [x] | C016 | 000403 | Caller `0x005a51e9` is current-mode 2 construction in `OpenInputPaneForCurrentSayMode`. | certain | xref/caller decompile | target Caller Inventory | incorporate | applied |
| [x] | C017 | 000403 | Caller `0x005a5544` is the last-recipient direct-message opener at `0x005a54b0`. | high | xref/caller decompile/docs | target Caller Inventory | incorporate | applied |
| [x] | C018 | 000403 | Caller `0x005b4128` is the modern branch of recipient-name confirmation. | certain | xref/caller decompile | target Caller Inventory | incorporate | applied |
| [x] | C019 | 000403 | Submit gates on positive text, copies max 255 wchar, validates, then sanitizes. | certain | decompile/callees | target CPP/behavior | incorporate | applied |
| [x] | C020 | 000403 | Submit uses one contiguous 300-byte packet, not `0x230` bytes. | certain | stack-frame accounting | target CPP/stale history | reject-stale | applied |
| [x] | C021 | 000403 | Submit uses one reusable `char[256]` conversion buffer, not two zeroed buffers. | certain | stack frame/decompile | target CPP/stale history | reject-stale | applied |
| [x] | C022 | 000403 | Opcode `0x19` and both one-byte lengths use `PacketBufferWriteUInt8`. | certain | three direct calls | target CPP/protocol | already-present | already-present |
| [x] | C023 | 000403 | Recipient uses CP_ACP conversion, local terminator, one-byte length, then payload copy. | certain | decompile | target CPP/protocol | incorporate | applied |
| [x] | C024 | 000403 | Message reuses the same buffer and repeats conversion, terminator, length, and payload copy. | certain | decompile | target CPP/protocol | incorporate | applied |
| [x] | C025 | 000403 | `>=256` and `>=300` branches are checked-array instrumentation to rangecheck failure, not silent authored returns. | very high | branch target/callee/compiler pattern | target CPP/stale history | reject-stale | applied |
| [x] | C026 | 000403 | Count is recipient+message+3; packet terminator is local-only; send uses counted short length through `g_packetSender`. | certain | decompile/data flow | target CPP/protocol | incorporate | applied |
| [x] | C027 | 000403 | Submit serializes inline and never calls UID000404. | certain | callee/xref/pointer negatives | target CPP/negative evidence | reject-invalid | applied |
| [x] | C028 | 000403 | Source virtual is `bool HandleKeyOrTextEvent(Event *event)`. | very high | secondary vtable family/base callee/Event UDT | target CPP; owner H | reject-stale | applied |
| [x] | C029 | 000403 | Key translation is unconditional; any modifier, non-Backspace key, or nonempty text delegates to base. | certain | decompile/control flow | target CPP/behavior | incorporate | applied |
| [x] | C030 | 000403 | Empty unmodified Backspace queues complete pane deletion and clears active line-input state. | certain | decompile/global/field docs | target CPP/behavior | incorporate | applied |
| [x] | C031 | 000403 | Pending chat-target state resets say mode to default and calls variety-pane `Refresh()`. | very high | decompile/global support | target CPP/behavior | incorporate | applied |
| [x] | C032 | 000403 | Handler directly allocates/constructs `SayToUserNameInputPane` and returns true. | certain | operator-new/ctor calls | target CPP/behavior | incorporate | applied |
| [x] | C033 | 000403 | Handler does not read `Event::m_type`; no event-type gate belongs in source. | certain | full decompile/field access negative | target negative evidence/CPP | reject-invalid | applied |
| [x] | C034 | 000403 | The accepted pre-callback target CPP's two buffers, `0x230` packet, silent returns, invented key helpers, and dropped cleanup are superseded. | certain | C019-C033 comparison | target Changes/history | historicalize | applied |
| [x] | C035 | 000403 | Section 22 target CPP is the exact formal replacement for all three method definitions. | very high | full evidence union | target formal CPP | incorporate | applied |
| [x] | C036 | 000403 | Target formal H remains blank because UID000099 owns the declaration. | certain | emitter structure | target formal H | not-applicable | excluded-with-reason |
| [x] | C037 | 000403 | UID000099 emits its clean declaration in H with `OnSubmitInput` and `HandleKeyOrTextEvent(Event *)`, no explicit destructor; its leading `InputPanes.h` include replaces the duplicate include formerly carried by UID0000C3. | very high | vtable family/accepted UID0000C6 pattern/generated H order | class UID000099 CPP/H; UID0000C3 H | incorporate | applied |
| [x] | C038 | 000403 | UID000099 CPP includes `SayInputPanes.h` then emits `[[CHILDREN]]`, placing UID000403 definitions at namespace scope. | high | generated ordering/topology | class UID000099 CPP; file UID0000N9 | incorporate | applied |
| [x] | C039 | 000403 | `SayToUserNameInputPane` is complete in `SayInputPanes.h` before UID000403's direct new expression; its independent method-source cleanup is not target ownership. | high | C032/C038/generated order | UID0000C7/UID0000N9 support | incorporate | applied |
| [x] | C040 | 000403 | Source placement remains `NexusTK/social/SayInputPanes.cpp`/`.h`; caller-owned and standalone Whisper-file alternatives are weaker. | high | file docs/family/callers | target/class/file placement | already-present | already-present |
| [x] | C041 | 000403 | Dated pre-callback generated command 000000023549 proved the then-current nested-definition and missing-header defects; dated post-callback command 000000023637 proved their accepted repair at physical readback. | certain | physical generated readback | target/file support history | historicalize | applied |
| [x] | C042 | 000403 | UID000403 moved to `94/95`. | high | all behavioral/source blockers closed | target metadata/coverage | incorporate | applied |
| [x] | C043 | 000403 | UID000099 moved to `93/94` after declaration/topology correction. | high | exact layout/method/vtable/caller union | class metadata/coverage | incorporate | applied |
| [x] | C044 | 000403 | UID0000N9 remains `89/90`; broader shared-module topology prevents a file-level increase from this one child. | high | current file/generated inventory | file metadata/coverage | incorporate | applied |
| [ ] | C045 | 000403 | Supervisor Gate 2B must preserve the constructor IDA name/type/four comment channels, complete frame, and exact five-code-xref set unchanged as Section 21 P01. | certain | live profile/comments/frame/xrefs | IDA Gate 2B | already-present | proposed |
| [ ] | C046 | 000403 | Supervisor Gate 2B must normalize the submit IDA name/type/comments through dependency-ordered Section 21 stages A01A-A01D, preserving the exact body, ten-row frame, four comment-channel progression, and sole data-xref set after every endpoint. | high | vtable/body/source virtual/xrefs | IDA Gate 2B | incorporate | proposed |
| [ ] | C047 | 000403 | Supervisor Gate 2B must normalize the key IDA name/type/comments through dependency-ordered Section 21 stages A02A-A02F: pure function rename, function type to `Event *Block`, stack rename `Block` to `event`, function type to `Event *event`, then FR and FP; preserve the exact body, six-row staged frames, four comment-channel progression, sole data-xref set, and secondary-facet receiver after every endpoint. | high | vtable/body/receiver adjustment/xrefs | IDA Gate 2B | incorporate | proposed |
| [ ] | C048 | 000403 | Supervisor Gate 2B is bounded to Section 21 P01/A01A-A01D/A02A-A02F/P02; padding, UID000404, compiler wrappers, vtable data, globals, and support UDTs remain evidence-only no-mutation constraints outside the action tables. | certain | bytes/xrefs/compiler pattern | IDA protection/target negative evidence | already-present | proposed |
| [ ] | C049 | 000403 | Supervisor must apply the four manual coverage rows using the exact replacement text in Section 28. | certain | manual coverage readback | manual coverage files | incorporate | proposed |
| [x] | C050 | 000403 | No validator, generated-file edit, report execution, IDA mutation, or lease action belonged to the original report-only pass; callback validators and short ordinary-file leases are separately receipted, while generated manual edit, execution, and IDA mutation remain excluded. | certain | explicit assignment and work log | Validator Results/Changed Files | not-applicable | excluded-with-reason |

Checklist allocation is exactly 45 checked rows (C001-C044 and no-operation C050) and 5 supervisor-owned unchecked rows (C045-C049); its nine non-Done fields are exact twins of the 50 Section 11 ledger rows.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000023751","destination_path":"executed-b-agent-research/B002/000403-NewSayToUserMessageInputPaneMethods-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/000403-NewSayToUserMessageInputPaneMethods-source-quality.md","timestamp":"2026-08-14T22:23:09-04:00","uid":"000403"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
