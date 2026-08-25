** TARGET-REPORT-UID:0002NU **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002NU ClanWidMoneyInputDialog Submit Withdraw Money Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation, implemented after accepted Gate 1: retain [UID:0002NU] as the reconstructable, class-owned `ClanWidMoneyInputDialog::OnSubmitText` method body, use the shared `void` callback contract, retain value-first PacketBuffer writer calls, restore the observed 128-byte source local, and document exact queue ownership and protocol behavior.
- Final disposition: `CANONICAL_OWNER:00002O`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00002O` remain correct. The active source route remains [UID:00002O] -> [UID:0000I8] -> `NexusTK/social/Clan.cpp`.
- Current closure state: B006-owned documentation implementation and supervisor-owned C2NU-037 through C2NU-048 coverage, IDA, validation, and generated readback are complete and independently verified. Report execution/archive lifecycle remains supervisor-owned and authoritative only from current path plus validator-owned status/history.
- Score disposition: target raised from `86/91` to `94/94`. This remains below the 95 barrier only because source-facing lexical names and the exact historical compilation-unit split are inferred rather than symbol-proven.
- Confidence: very strong for execution behavior, class ownership, packet layout, callback return type, local-buffer shape, sender semantics, range, and source placement; strong for historically plausible source-facing names.

## Supporting Research

- This is the dedicated report required by the current B006 assignment. The older B001 six-submitter report is historical evidence only and is not treated as current authority.
- Live research used canonical MCP session `supervisor-gate2b-batch2-20260810` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Bounded analysis, decompilation, disassembly, xref, bytes, frame, comment, and support-function queries returned successfully.
- The earlier canonical session disappeared during a bounded family query. No report conclusion relies on the disappeared session; all decisive target facts were reacquired from the replacement canonical session.
- Historical family claims that PacketBuffer calls were destination-first, that the callback returned `int`, that the sender returned a meaningful result, or that an eight-byte local best represented the source have been rejected by current helper declarations, base-call behavior, sibling bodies, stack layout, and sender semantics.
- No documentation, coverage, generated artifact, validator state, lifecycle state, or IDA database was modified during this report-only phase.
- Supervisor Gate 1 subsequently passed this exact report at `33/33`, SHA256 `5CF72F6E516CFA175F4F6BA127E2D07A4E5C94B3B426369F71D7EE6F7C3D5CAC`, and authorized C2NU-001 through C2NU-036. B006 applied and physically verified those claims; the primary supervisor later completed and independently verified C2NU-037 through C2NU-048.

## Target

- Target UID: `[UID:0002NU]`.
- Additional target UIDs: none. Related pages below are support edits required for one coherent shared virtual signature; they do not receive report coverage credit.
- Target path: `by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md`.
- Historical assignment queue row: `auto-generated/-ag-research-tracker.md` listed `86/91`, combined `88.5`, reconstructable `true`, and zero report coverage before this report's implementation and supervisor closure.
- Current generated coverage: `auto-generated/-ag-memory-coverage.md` routes the coded target through owner/emitter `00002O` to `auto-generated/NexusTK/social/Clan.cpp`.
- Current supervisor classification: not-covered reconstructable by-memory target requiring an independent source-quality pass.
- Exact modeled range: `[0x004890b0,0x00489132)`, size `0x82` / 130 bytes.

## Current Target State

- Current implemented metadata: `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:00002O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002O`.
- Historical Gate 1 prestate: formal CPP incorrectly declared an `int` return, returned a `void` sender call, and used `packet[8]`; historical prose also contradicted the already-value-first calls. These defects are retained only as labeled history.
- Current formal CPP is the exact void/value-first/128-byte body from Section 22. Formal H remains blank because the owner class page now carries the declaration in its formal H channel.
- Current support state: all seven class declarations use `virtual void OnSubmitText`, all six by-memory definitions use `void`, both money methods use 128-byte packet locals, and every QueueAndSendPacket call is a statement.
- Current supervisor closure state: the exact manual coverage rows are applied and scoped-valid; IDA A00-A05 and P01 persisted through one save and fresh-copy readback; all 16 ordinary documents were independently revalidated; broad generation completed; generated `Clan.cpp` and `Clan.h` contain the accepted body and owner declaration.
- The source-facing method name `OnSubmitText` is descriptive/inferred, not an original recovered symbol. It is nevertheless the strongest coherent name because the base dialog reads submitted text and dispatches one virtual slot shared by all six submitter implementations.
- Related pages checked: owner/base/derived class pages; the base dialog core; all six submitter children; the non-emitting family aggregate; Clan and ClanDialogs file pages; PacketBuffer UInt8/UInt32BE helpers; QueueAndSendPacket; `g_packetSender`; the historical B001 family report; manual coverage rows; generated memory/research rows.

## Executive Recommendation

- Keep this exact function as `void ClanWidMoneyInputDialog::OnSubmitText(const wchar_t *text)` under [UID:00002O].
- Emit a 128-byte local packet, parse with CRT `_wtol`, write `{0x4b,0x0b,0x01,amount32-be}`, explicitly preserve `packet[7] = 0`, and queue exactly seven bytes.
- Correct the base and all derived declarations to `virtual void OnSubmitText(const wchar_t *text)` and correct all six method definitions to `void`; remove returns of `QueueAndSendPacket`.
- Preserve value-first PacketBuffer calls. The goal's destination-first concern was tested and rejected: current support declarations and x86 push order both prove `value, destination`.
- Keep active source placement in `Clan.cpp`. `ClanDialogs.md` remains only a coordinated future split candidate and is not a valid reason to move this one class or method in isolation.

## Supervisor Active Recheck

- The current goal required independent revalidation of the packet API, source-quality defects, ownership, source placement, xrefs, range, protocol behavior, and C++ rather than restating the older family report. Each was rechecked.
- No split repair is required before this report can be implemented. The exact function range is already isolated, followed by `0xcc` alignment, and routed by one class vtable slot.
- All source-bearing support pages whose declarations or bodies would conflict with the corrected virtual type are enumerated in Sections 24 and 25 and in the claim/checklist pair.
- No target-specific blocker is deferred as "needs investigation."

## Inference Research Guidance Check

- Binary facts, documentation evidence, and inference are separated throughout this report.
- Existing docs and the old report were treated as fallible. Current live helper declarations and assembly push order overrule the historical destination-first claim; the base caller and six leaf bodies overrule the historical `int` claim.
- Source-facing names use human mid-2000s C++ style already established by the subsystem. No final C++ uses `sub_4890B0`, `var_82`, `unknown_libname_24`, or another IDA/compiler placeholder.
- The behavior-first priority is exact: `_wtol` conversion, truncation/bit-pattern behavior, write order, extra terminator writes, send length, and queue-copy ownership are preserved even where a more modern implementation might validate or clamp input.
- Wave2/Wave3 mentions are stale process artifacts and were ignored; none is used as current evidence.

## Heuristic / Inference Reanalysis And Validation

- **Packet writer order:** accepted `PacketBufferWriteUInt8(value, destination)` and `PacketBufferWriteUInt32BE(value, destination)`. Current function declarations use that order, and x86 pushes destination before value for cdecl calls. Destination-first is rejected.
- **Callback return:** accepted `void`. The base call at `0x00488eb0` dispatches vtable `+0x5c` and ignores any result; current target decompilation is `void`; all six sibling leaf callbacks have no return-value production. `int` is rejected as stale decompiler/doc pollution.
- **Local packet size:** accepted `unsigned char packet[128]`. The exact frame reserves `0x84` bytes: 128 payload-local bytes plus the security cookie. `packet[8]` is behavior-equivalent for the seven sent bytes but is rejected as less faithful to the observed source family.
- **Amount type:** accepted `unsigned long amount = _wtol(text)`. Win32 `long` and `unsigned long` are 32-bit; assigning the signed CRT result preserves its bit pattern before the unsigned BE writer. No modern range normalization is introduced.
- **Protocol role:** accepted opcode `0x4b`, subtype `0x0b`, action `1` as withdraw-amount submission. Outgoing action `0` requests the dialog; incoming subtype `11`, result/action `0` opens it; result/action `1` is accepted without another dialog.
- **Sender behavior:** accepted a `void` queue/send call. `Socket::QueueAndSendPacket` copies exactly seven caller bytes into owned heap storage, appends its own local zero, and queues command 8; no sender result is consumed or returned.
- **Source name:** `ClanWidMoneyInputDialog::OnSubmitText` remains descriptive/inferred rather than original-proof. It is preferred over address-derived names and over a money-specific method name because the shared base slot passes submitted wide text to six derived classes.
- **Source placement:** `Clan.cpp` is accepted. A separate `ClanDialogs.cpp` is plausible only as a project-wide coordinated split; moving this method alone would fragment the established owner/emitter graph.
- **Rejected modernization:** null checks, sender checks, parse-success checks, sign checks, overflow checks, bounds clamps, safer conversion APIs, and return-status branches are rejected because the binary has none.

## Evidence Standards Used

- Primary evidence: live IDA MCP function analysis, decompilation, disassembly, frame layout, bytes, inbound xrefs, vtable bytes, function/data types, comments, and bounded family/support-function analysis.
- Corroboration: current by-memory/by-class/by-file docs, formal C++ blocks, current generated routing, manual coverage, the research tracker, and the historical broad family report.
- Negative evidence: no ordinary callers, no second inbound xref, no code at the alignment bytes, no meaningful sender return, no input-validation branch, no local type suitable for source-facing packet reconstruction, and no original symbol/UDT for this class.
- The evidence is very strong because independently observed base dispatch, target body, sibling leaf shapes, helper declarations, stack layout, protocol dispatcher, and sender ownership all converge.

## Evidence Checked

- Live target: `analyze_function`, decompilation, disassembly, frame members, comments, exact body bytes/hash, successor bytes, callers/callees, and xrefs for `0x004890b0`.
- Live vtable/global: bytes and item state at `0x00615a94`; current type/name/comment state for `g_packetSender` at `0x0067a7ec`.
- Live support: `PacketBufferWriteUInt8` at `0x00575380`, `PacketBufferWriteUInt32BE` at `0x005753f0`, `Socket_QueueAndSendPacket` at `0x00574bb0`, CRT `_wtol` wrapper at `0x005cea43`, base caller at `0x00488eb0`, outgoing dispatcher at `0x00487600`, and incoming subtype-11 branch at `0x00484f70`.
- Live family: six submitter leaves at `0x00488fe0`, `0x004890b0`, `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510`.
- Documentation searches: UID/address/class/method/helper/protocol terms across by-* docs, generated reports, and executed research.
- Initial report-only phase intentionally skipped IDA mutation, validators, generated refresh, and build. Subsequent supervisor-owned IDA, validation, coverage, and generated-readback closure is recorded in Sections 21 and 31.

## Claim And Incorporation Ledger

Parity contract: the checklist in Section 33 mirrors every ledger row in the same order by Claim ID, Target UID, destination/claim identity, actor/authority, action, and verification state. Evidence text is ledger-only context.

| Claim ID | Target UID | Destination / claim identity | Actor / authority | Action | Verification state | Evidence |
| --- | --- | --- | --- | --- | --- | --- |
| C2NU-001 | 0002NU | Target / exact range and body identity | B006 after Gate 1 | Record `[0x004890b0,0x00489132)`, size `0x82`, and body SHA256 `DD45DB894501355CC30E71B4636608D43E306E011F292509931F0ABEE2EF395E`. | Applied and physically verified | Live bytes and modeled function. |
| C2NU-002 | 0002NU | Target / successor boundary | B006 after Gate 1 | Record fourteen `0xcc` bytes at `[0x00489132,0x00489140)` as alignment outside the target. | Applied and physically verified | Live byte readback. |
| C2NU-003 | 0002NU | Target / virtual route | B006 after Gate 1 | Record sole inbound data xref `0x00615a94 -> 0x004890b0` and zero ordinary callers. | Applied and physically verified | Live xrefs/callers and vtable bytes. |
| C2NU-004 | 0002NU | Target / callback return | B006 after Gate 1 | Replace stale `int` callback claims with `void`. | Applied and physically verified | Base dispatch ignores result; six leaf bodies return no value. |
| C2NU-005 | 0002NU | Target / local packet shape | B006 after Gate 1 | Replace `packet[8]` with source-faithful `packet[128]`. | Applied and physically verified | Exact `0x80` packet-local reservation plus cookie. |
| C2NU-006 | 0002NU | Target / packet layout | B006 after Gate 1 | Document `{0x4b,0x0b,1,amount32-be}` at offsets `0..6`. | Applied and physically verified | Live decompile/disassembly. |
| C2NU-007 | 0002NU | Target / PacketBuffer API | B006 after Gate 1 | Preserve value-first writer calls and reject destination-first historical prose. | Applied and physically verified | Current helper prototypes and cdecl push order. |
| C2NU-008 | 0002NU | Target / amount conversion | B006 after Gate 1 | Document `_wtol` and 32-bit signed-to-unsigned bit-pattern preservation. | Applied and physically verified | Live CRT call and UInt32BE input. |
| C2NU-009 | 0002NU | Target / validation behavior | B006 after Gate 1 | Record absence of null, parse, sign, range, overflow, and sender checks. | Applied and physically verified | Single-block body and no validation branch. |
| C2NU-010 | 0002NU | Target / spare zero and send length | B006 after Gate 1 | Record helper zero at byte 7, repeated explicit zero, and seven-byte send excluding byte 7. | Applied and physically verified | Writer and target disassembly. |
| C2NU-011 | 0002NU | Target / sender ownership | B006 after Gate 1 | Record exact seven-byte copy to Socket-owned queue storage and void return. | Applied and physically verified | QueueAndSendPacket decompile. |
| C2NU-012 | 0002NU | Target / protocol request route | B006 after Gate 1 | Record outgoing action `0` `{0x4b,0x0b,0}` as dialog request. | Applied and physically verified | Dispatcher at `0x00487600`. |
| C2NU-013 | 0002NU | Target / protocol open route | B006 after Gate 1 | Record incoming opcode `0x43`, subtype `11`, result/action `0` as dialog construction. | Applied and physically verified | Incoming branch at `0x00484f70`. |
| C2NU-014 | 0002NU | Target / protocol success route | B006 after Gate 1 | Record incoming subtype `11`, result/action `1` as accepted no-dialog path. | Applied and physically verified | Incoming switch behavior. |
| C2NU-015 | 0002NU | Target metadata / owner-emitter route | B006 after Gate 1 | Keep owner/emitter `00002O` and reconstructable true. | Applied and physically verified | Sole class-vtable route and existing graph. |
| C2NU-016 | 0002NU | Target / source placement | B006 after Gate 1 | Keep active source route `00002O -> 0000I8 -> Clan.cpp`. | Applied and physically verified | Current owner/emitter/generated route. |
| C2NU-017 | 0002NU | Target / rejected isolated split | B006 after Gate 1 | Preserve `ClanDialogs.md` only as a coordinated future split candidate. | Applied and physically verified | Existing file docs and family coupling. |
| C2NU-018 | 0002NU | Target formal RECONSTRUCTION_CPP CODE | B006 after Gate 1 | Replace with the exact void/value-first/128-byte body in Section 22. | Applied and physically verified | Complete live behavior and source-shape proof. |
| C2NU-019 | 0002NU | Target formal RECONSTRUCTION_H CODE | B006 after Gate 1 | Keep blank because the class page owns the declaration. | Applied and physically verified | Emitter layering. |
| C2NU-020 | 0002NU | Target metadata / score | B006 after Gate 1 | Raise `86/91` to `94/94`; leave all routing metadata unchanged. | Applied and physically verified | Resolved API, return, local, behavior, protocol, and ownership. |
| C2NU-021 | 0002NU | Target prose / stale assumptions | B006 after Gate 1 | Incorporate full evidence and historicalize contradicted destination-first/int/packet[8] claims. | Applied and physically verified | Current evidence supersedes old report/docs. |
| C2NU-022 | 00002O | by-class/ClanWidMoneyInputDialog.md / declaration | B006 after Gate 1 | Change `virtual int OnSubmitText` to `virtual void OnSubmitText`; keep `86/90` and route. | Applied and physically verified | Shared slot and target return proof. |
| C2NU-023 | 00002J | by-class/ClanNameInputDialog.md / base declaration | B006 after Gate 1 | Change base virtual return to `void` and document ignored-result dispatch; keep `86/89`. | Applied and physically verified | Base caller at `0x00488eb0`. |
| C2NU-024 | 00002A | by-class/ClanDepMoneyInputDialog.md / declaration | B006 after Gate 1 | Change both stale `int` declarations to `void`; document 128-byte family shape. | Applied and physically verified | Deposit leaf and shared slot. |
| C2NU-025 | 00002D | by-class/ClanExpelNameInputDialog.md / declaration | B006 after Gate 1 | Change both stale `int` declarations to `void`. | Applied and physically verified | Expel leaf and shared slot. |
| C2NU-026 | 00002M | by-class/ClanSummonNameInputDialog.md / declaration | B006 after Gate 1 | Change stale `int` declaration to `void`. | Applied and physically verified | Summon leaf and shared slot. |
| C2NU-027 | 000023 | by-class/ClanAppearNameInputDialog.md / declaration | B006 after Gate 1 | Change stale `int` declaration to `void`. | Applied and physically verified | Appear leaf and shared slot. |
| C2NU-028 | 000028 | by-class/ClanChangeNameInputDialog.md / declaration | B006 after Gate 1 | Change stale `int` declaration to `void`. | Applied and physically verified | Change-name leaf and shared slot. |
| C2NU-029 | 0002NS | Deposit submitter formal CPP | B006 after Gate 1 | Change definition to `void`, packet to 128 bytes, and final `return` call to a statement. | Applied and physically verified | Fresh six-leaf family recheck. |
| C2NU-030 | 0002NW | Expel submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified | Fresh leaf recheck. |
| C2NU-031 | 0002NY | Summon submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified | Fresh leaf recheck. |
| C2NU-032 | 0002O0 | Appear submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified | Fresh leaf recheck. |
| C2NU-033 | 0002O2 | Change-name submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified | Fresh leaf recheck. |
| C2NU-034 | 00010K | ClanNameDialogSubmitters / family contract | B006 after Gate 1 | Historicalize `int` and record six `void` overrides; keep non-emitting metadata. | Applied and physically verified | Base plus six current leaves. |
| C2NU-035 | 00010J | ClanNameInputDialogCore / dispatch evidence | B006 after Gate 1 | State that `OnSubmitText(text)` is a void virtual call and no result is consumed. | Applied and physically verified | Existing formal call and live base decompile. |
| C2NU-036 | 0000I8 | by-file/Clan.md / callback family note | B006 after Gate 1 | Add coherent void callback and value-first PacketBuffer family note; keep source route. | Applied and physically verified | Cross-page source contract. |
| C2NU-037 | 0002NU | by-memory/-coverage-report.md / target row | Supervisor only | Replace stale 82% row with exact 94% row from Section 28. | Applied and physically verified | Exact UID0002NU 94% row persisted; scoped command `000000021761` exited 0/ok 1 with two unrelated pre-existing missing refs. |
| C2NU-038 | 00002O | by-class/-coverage-report.md / owner row | Supervisor only | Replace stale 84% row with current 86% source-quality row from Section 28. | Applied and physically verified | Exact UID00002O 86% row persisted; scoped command `000000021762` exited 0/ok 1. |
| C2NU-039 | 00002J | by-class/-coverage-report.md / base row | Supervisor only | Replace stale 85% row with current 86% source-quality row from Section 28. | Applied and physically verified | Exact UID00002J 86% row persisted; scoped command `000000021762` exited 0/ok 1. |
| C2NU-040 | 0002NU | IDA A00 / class forward declaration | Supervisor Gate 2B | Declare `struct ClanWidMoneyInputDialog;` if dry-run/readback confirms absent. | Applied and physically verified | Fresh-copy readback: ordinal 1000, one incomplete tag, zero members, no invented layout. |
| C2NU-041 | 0002NU | IDA A01 / function name | Supervisor Gate 2B | Pure-rename `sub_4890B0` to `ClanWidMoneyInputDialog__OnSubmitText`. | Applied and physically verified | Pure rename persisted at `0x004890b0`; function range remains `0x82`. |
| C2NU-042 | 0002NU | IDA A02 / stack argument name and type | Supervisor Gate 2B | Rename `arg_0` to `text` and type it `const wchar_t *`. | Applied and physically verified | Fresh-copy frame reads `text@+0x90`, size 4, `const wchar_t *`; all eight other rows unchanged. |
| C2NU-043 | 0002NU | IDA A03 / function prototype | Supervisor Gate 2B | Apply exact void thiscall prototype from Section 21. | Applied and physically verified | Exact void thiscall prototype persisted in fresh-copy readback. |
| C2NU-044 | 0002NU | IDA A04 / function regular comment | Supervisor Gate 2B | Apply exact source-quality function comment from Section 21. | Applied and physically verified | Exact function-regular comment persisted; address regular/repeatable and function-repeatable remain blank; 13 internal comments unchanged. |
| C2NU-045 | 0002NU | IDA A05 / vtable slot regular comment | Supervisor Gate 2B | Apply exact source-quality comment at `0x00615a94`. | Applied and physically verified | Exact regular comment persisted; repeatable blank; vtable window remains `00 FC 49 00 B0 90 48 00 E0 4D 64 00`. |
| C2NU-046 | 0002NU | IDA P01 / protected state | Supervisor Gate 2B | Preserve body/range/hash, one data xref, zero callers, 13 internal comments, other frame rows, helpers, and globals. | Applied and physically verified | Body remains 130 bytes and SHA256 `DD45DB894501355CC30E71B4636608D43E306E011F292509931F0ABEE2EF395E`; sole data xref, zero callers, frame/range/comments protected. |
| C2NU-047 | 0002NU | Documentation validation plan | Supervisor only | Independently confirm the scoped validation receipts for every changed by-* page after callback. | Applied and physically verified | Commands `000000021745` through `000000021760`: all 16 exited 0/ok 1/generated skipped; `000000021760` retained ten unrelated pre-existing `Clan.md` missing refs. |
| C2NU-048 | 0002NU | Generated/manual readback plan | Supervisor only | Refresh generated outputs as required, inspect Clan.cpp/H, and apply manual rows only after docs validate. | Applied and physically verified | Broad command `000000021763` at `2026-08-10T13:43:16-04:00` exited 0/generated completed; generated Clan CPP/H exactly contain accepted UID0002NU body/declaration. |

## Positive Evidence Summary

- The exact body is modeled, bounded, hashable, and separated from its successor by verified `0xcc` alignment.
- One vtable data slot points to the function and no ordinary caller exists, exactly matching a derived virtual callback.
- Base code passes submitted wide text through slot `+0x5c` and consumes no result.
- All six submitter leaves produce no result, use the same packet-sender family, and preserve the same callback shape.
- Helper declarations and call-site push order independently prove value-first PacketBuffer calls.
- Outgoing request, incoming dialog-open, and submitted amount paths establish subtype/action semantics end to end.
- QueueAndSendPacket proves the seven-byte payload is copied before the stack local dies.

## IDA MCP Facts

- Current persisted IDB name: `ClanWidMoneyInputDialog__OnSubmitText`; historical prechange name `sub_4890B0`; modeled range `[0x004890b0,0x00489132)`, size 130; one basic block; cyclomatic complexity 1.
- Body SHA256: `DD45DB894501355CC30E71B4636608D43E306E011F292509931F0ABEE2EF395E`.
- Successor bytes `[0x00489132,0x00489140)`: fourteen `0xcc` bytes.
- Current persisted prototype: `void __thiscall ClanWidMoneyInputDialog__OnSubmitText(ClanWidMoneyInputDialog *this, const wchar_t *text)`. Historical analysis-summary disagreement with item/decompiler/disassembly evidence was resolved by the base caller and six-leaf family before mutation.
- Exact sole inbound xref: data `0x00615a94 -> 0x004890b0`; ordinary callers: zero.
- Vtable bytes `[0x00615a90,0x00615a9c)`: `00 FC 49 00 B0 90 48 00 E0 4D 64 00`.
- Frame: packet-local fragments begin at `Src@+0x4`; cookie is `var_4@+0x84`; persisted argument is `text@+0x90`, size 4, type `const wchar_t *`, proving a 128-byte local region plus cookie. All eight other frame rows are unchanged.
- Current function-start address regular/repeatable comments remain absent/absent. The exact function regular comment is persisted while function-repeatable remains absent and all 13 internal comments remain unchanged. The exact vtable-slot regular comment is persisted while repeatable remains absent.
- Current local type readback contains `struct ClanWidMoneyInputDialog` at ordinal 1000 as one incomplete tag with zero members and no invented layout.
- `g_packetSender` at `0x0067a7ec` is already typed `Socket *`, already source-named, and already carries source-quality regular comments; no mutation is recommended.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004890b0-0x00489132` | 0002NU / target | Withdraw amount submit virtual method | yes | 00002O | 86/91 -> 94/94 | Applied/current and physically verified. Exact formal CPP replacement was the historical pre-callback requirement. |
| `0x00615a94` | 00002O support | Primary-vtable `OnSubmitText` slot | class data | 00002O | 86/90 unchanged | Supervisor-applied regular comment persisted and physically verified; repeatable remains blank and slot bytes are unchanged. |
| `0x00488eb0` base dispatch | 00010J support | Reads text and invokes slot `+0x5c` | yes | 0000I8 | 88/91 unchanged | Confirms void shared contract. |
| `0x00488fe0` | 0002NS support | Deposit amount submit override | yes | 00002A | 86/91 unchanged | Applied/current and physically verified. Return/local source-shape correction was the historical pre-callback requirement. |
| `0x00489180` | 0002NW support | Expel name submit override | yes | 00002D | 86/91 unchanged | Applied/current and physically verified. Return correction was the historical pre-callback requirement. |
| `0x004892b0` | 0002NY support | Summon name submit override | yes | 00002M | 86/91 unchanged | Applied/current and physically verified. Return correction was the historical pre-callback requirement. |
| `0x004893e0` | 0002O0 support | Appear name submit override | yes | 000023 | 86/91 unchanged | Applied/current and physically verified. Return correction was the historical pre-callback requirement. |
| `0x00489510` | 0002O2 support | Change-name submit override | yes | 000028 | 86/91 unchanged | Applied/current and physically verified. Return correction was the historical pre-callback requirement. |
| `0x00488fe0-0x004895fe` | 00010K support aggregate | Family evidence container | no | none | 85/89 unchanged | Current non-emitting support; shared return prose correction is applied and physically verified. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00615a94` | data xref to `0x004890b0` | Sole primary-vtable route; proves class virtual ownership. |
| `0x00488eb0` | indirect call through primary vtable `+0x5c` | Base dialog supplies wide submitted text and ignores return. |
| `0x005cea43` | target callee | CRT `_wtol`; not a product helper. |
| `0x00575380` | target callee | Value-first UInt8 packet writer. |
| `0x005753f0` | target callee | Value-first UInt32BE packet writer. |
| `0x00574bb0` | target callee | Void Socket queue/copy/send method. |
| `0x0067a7ec` | target data read | Active `Socket *g_packetSender` singleton. |
| target ordinary callers | none | Expected for vtable-only dispatch. |

## Documentation Evidence And IDA Status

- Callback-applied current supporting docs establish class ownership, Clan source routing, opcode/subtype/action bytes, `_wtol`, BE amount encoding, queue/send dependencies, the `void` callback family, value-first helper calls, and the corrected money-packet storage.
- Historical pre-callback docs incorrectly retained `int` across the base/derived callback family, `return g_packetSender->QueueAndSendPacket(...)`, `packet[8]` in both money submitters, and prose claiming destination-first calls; those ordinary-document defects are now corrected and physically verified.
- The ordinary documentation callback, independent scoped revalidation, manual coverage updates, broad generated refresh, and generated CPP/H readback are complete and supervisor-verified.
- The research tracker lists no dedicated report coverage for UID0002NU, so this report fills the intended queue gap.
- Section 21 preserves the accepted narrow supervisor handoff as historical prestate/action authority and records the completed one-save persisted readback for A00-A05 and P01.

## Ranked Ownership Analysis

### 1. ClanWidMoneyInputDialog

- Evidence for: sole vtable slot at `0x00615a94`; target packet semantics match the withdraw-money dialog; current owner/emitter graph; derived shared callback slot.
- Evidence against: class lexical names are inferred, not symbol-proven.
- Decision: retain [UID:00002O] as canonical owner and emitter.

### 2. Clan file module

- Evidence for: base/derived class family, protocol dispatcher, packet actions, and generated routing are already cohesive in Clan.
- Evidence against: `Clan.cpp` is broad and a historical `ClanDialogs.cpp` split remains plausible.
- Decision: retain [UID:0000I8] and `Clan.cpp` now.

### 3. ClanDialogs split candidate

- Evidence for: dialog classes form a coherent conceptual cluster.
- Evidence against: no coordinated project-wide split has been accepted, and moving one method would break source/emitter coherence.
- Decision: reject isolated reassignment; preserve only as future coordinated work.

### Proposed new file/grouping, if applicable

- None for this target. No new owner, by-file page, or source split is needed.

## Source Placement

- Recommended placement: class method definition emitted by [UID:00002O] through [UID:0000I8] into `NexusTK/social/Clan.cpp`; class declaration emitted by the class page's H block.
- This matches the current base/derived dialog family, protocol code, owner graph, and generated source.
- Rejected placement: standalone target source file, Socket/PacketBuffer module, or isolated move to `ClanDialogs.cpp`.
- Remaining uncertainty: the final historical source tree may eventually split dialogs from Clan, but no current evidence justifies a one-method move.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is one complete modeled function `[0x004890b0,0x00489132)`.
- The next fourteen bytes are verified `0xcc` alignment and are not part of this emitter.
- No child split, merge, range expansion, ignored child, or reclassification is required.
- The raw constructor-shaped sibling remains separately documented and does not absorb this routed method.
- The family aggregate remains non-reconstructable/non-emitting evidence; executable children retain their class owners.

## Negative Evidence Summary

- No second xref or ordinary caller supports another owner.
- No original symbol proves the exact lexical spelling, but leaving `sub_4890B0` would violate the human-source goal and ignore the strong class/slot semantics.
- No meaningful `QueueAndSendPacket` result exists; returning it is invalid.
- No target branch validates text, amount, sign, overflow, sender state, or send result.
- No evidence supports destination-first PacketBuffer wrappers in the current project API.
- No evidence supports shrinking the source local to eight bytes merely because only seven bytes are sent.
- No exact source-tree evidence supports moving only this target to `ClanDialogs.cpp`.

## IDA Rename / Type / Comment Recommendations

These rows preserve the accepted supervisor-only structured handoff and literal historical prestates. B006 did not mutate IDA. The primary supervisor subsequently performed the bounded A00-A05 batch, preserved P01, saved exactly once, and verified every result from a byte-identical fresh copy opened with `run_auto_analysis:false`.

| Action | Entity / address | Literal accepted pre-state (historical) | Accepted endpoint and literal request fields | Evidence / safety constraints | Required and achieved readback |
| --- | --- | --- | --- | --- | --- |
| A00-TYPE | Local type declaration | `type_query("*ClanWidMoneyInputDialog*")` returned zero local types. | `declare_type` with `decls:"struct ClanWidMoneyInputDialog;"` and the active `database`. | Forward declaration only; do not invent members, size, inheritance layout, or vtable structure. | Type query returns the forward-declared struct without changing bytes or analysis. |
| A01-NAME | Function `0x004890b0` | Name `sub_4890B0`; range `[0x004890b0,0x00489132)`; regular/repeatable function comments absent/absent. | `rename` with `batch.func.addr:"0x004890b0"`, `batch.func.name:"ClanWidMoneyInputDialog__OnSubmitText"`, `stop_on_error:true`, `dry_run` before apply, `allow_overwrite:false`, `pure:true`, and active `database`. | Freeze body hash, range, sole data xref, zero code callers, frame, and all comments. | Function lookup/decompile show the new name; bytes/xrefs/range unchanged. |
| A02-LOCAL-NAME | Stack argument at function `0x004890b0` | `arg_0@+0x90`, size 4, current type `int`; other frame rows: `Src@+0x4`, `destination@+0x5`, `var_82@+0x6`, `var_81@+0x7`, `var_7D@+0xb`, `var_4@+0x84`, saved registers `+0x88`, return address `+0x8c`. | `rename` with `batch.stack.func_addr:"0x004890b0"`, `old:"arg_0"`, `new:"text"`, `stop_on_error:true`, dry-run before apply, `allow_overwrite:false`, `pure:false`, and active `database`. | Rename only this stable argument; do not reshape packet fragments or other frame rows. | Frame reports `text@+0x90`; all other rows and offsets unchanged. |
| A02-LOCAL-TYPE | Stack argument `text` at `0x004890b0` | After A02-LOCAL-NAME: `text@+0x90`, size 4, type `int`. | `set_type` with `edits.addr:"0x004890b0"`, `kind:"stack"`, `name:"text"`, `ty:"const wchar_t *"`, and active `database`. | Base caller supplies a wide buffer and `_wtol` consumes it. Do not type packet fragments as a synthetic small array. | Frame reports `text@+0x90`, size 4, `const wchar_t *`; all other frame rows unchanged. |
| A03-FUNCTION-TYPE | Function `0x004890b0` | Analysis endpoint says `int __thiscall(void *this, int)`; item/decompiler/disassembly state says `void __thiscall(void *this, int)`; no local class UDT exists before A00. | `set_type` with `edits.addr:"0x004890b0"`, `kind:"function"`, `signature:"void __thiscall ClanWidMoneyInputDialog__OnSubmitText(ClanWidMoneyInputDialog *this, const wchar_t *text)"`, and active `database`. | Apply only after A00/A01/A02. Freeze calling convention, range, body, xrefs, and unlisted locals. | Function type/decompile agree on exact void thiscall signature and wide-text argument. |
| A04-COMMENT | Function `0x004890b0` regular comment | Regular comment absent; repeatable comment absent. | `set_function_comments` with `items.addr:"0x004890b0"`, `items.comment:"Source virtual ClanWidMoneyInputDialog::OnSubmitText. Parses the submitted wide amount with _wtol, builds clan request {0x4b,0x0b,1,amount32-be}, and queues the seven-byte payload through g_packetSender."`, and active `database`. | Set regular function comment only; preserve repeatable absence and 13 existing internal comments. | Exact regular comment present; repeatable remains absent; internal comments unchanged. |
| A05-VTABLE-COMMENT | Data item `0x00615a94` | Four-byte vtable slot contains `0x004890b0`; physical name/type empty; regular/repeatable comments absent/absent. | `set_address_comments` with `items.addr:"0x00615a94"`, `items.comment:"ClanWidMoneyInputDialog primary-vtable OnSubmitText slot -> ClanWidMoneyInputDialog__OnSubmitText (0x004890b0)."`, and active `database`. | Comment only. Do not rename/retype/recreate the slot or neighboring entries. | Exact regular comment present; slot value, width, xref, repeatable absence, and neighbors unchanged. |
| P01-PROTECT | Target/dependencies | Target body/range/hash; sole data xref; zero callers; 13 internal comments; frame rows; helper names/types; `Socket *g_packetSender` and its existing regular comment. | No mutation outside A00-A05. | Preserve all accepted prestate and avoid helper/global churn. | Exact protected facts remain byte/type/xref/comment stable after readback. |

The accepted supervisor readback used narrow function lookup/type/frame/comment/xref/bytes calls plus address comment/item inspection. No broad overwrite or auto-analysis was authorized.

**Supervisor Gate 2B persisted closure receipt:**

| Action | Persisted fresh-copy readback |
| --- | --- |
| A00-TYPE | `struct ClanWidMoneyInputDialog` reads at ordinal 1000 as one incomplete tag with zero members and no invented layout. |
| A01-NAME | Pure rename persisted at `0x004890b0` from `sub_4890B0` to `ClanWidMoneyInputDialog__OnSubmitText`; range remains `0x82`. |
| A02-LOCAL | Stack argument persisted as `text@+0x90`, size 4, type `const wchar_t *`; all eight other frame rows are unchanged. |
| A03-FUNCTION-TYPE | Exact persisted prototype is `void __thiscall ClanWidMoneyInputDialog__OnSubmitText(ClanWidMoneyInputDialog *this, const wchar_t *text)`. |
| A04-COMMENT | The exact Section 21 function-regular comment persisted; address regular/repeatable and function-repeatable remain blank; all 13 internal comments are unchanged. |
| A05-VTABLE-COMMENT | The exact Section 21 regular comment persisted at `0x00615a94`; repeatable remains blank; vtable window remains `00 FC 49 00 B0 90 48 00 E0 4D 64 00`. |
| P01-PROTECT | Body remains 130 bytes with SHA256 `DD45DB894501355CC30E71B4636608D43E306E011F292509931F0ABEE2EF395E`; sole inbound xref remains data `0x00615a94`; callers remain zero; range, frame, and comments remain protected. |

- Canonical prechange IDB: SHA256 `4094292D7768A5DDF1BBDE721E5436D4FC4AE9F8B7EF7AE580A44FF48E6173A8`, size 143197964.
- Byte-identical prechange backup: `tools/leaser/Agents/ida-backups/NexusTK.exe.uid0002NU-prechange-20260810-133754.i64`.
- Persistence: exactly one `idb_save` succeeded.
- Canonical post-save IDB: SHA256 `927575FE95136EF5920E42327F4E9BA9D0E06567D9F89654011845BCA3D3A818`, size 143196374.
- Byte-identical fresh-copy verification database: `tools/leaser/Agents/ida-backups/NexusTK.exe.uid0002NU-postsave-verify-20260810-134006.i64`, opened with `run_auto_analysis:false` as `supervisor-b006-uid0002nu-postsave-verify-20260810`; every A00-A05/P01 readback persisted.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; this is a complete class-owned function with exact behavior and route.
- Formal `RECONSTRUCTION_CPP CODE` replacement:

```cpp
void ClanWidMoneyInputDialog::OnSubmitText(const wchar_t *text)
{
    unsigned char packet[128];
    unsigned long amount = _wtol(text);

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x0b, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);
    PacketBufferWriteUInt32BE(amount, packet + 3);
    packet[7] = 0;

    g_packetSender->QueueAndSendPacket(packet, 7);
}
```

- Formal `RECONSTRUCTION_H CODE` replacement remains blank because [UID:00002O] owns the declaration:

```cpp
```

- Exact behavior preserved: `_wtol`; 32-bit conversion; field order; BE amount; byte-seven zero; seven-byte send; no validation; no return branch; sender-owned queue copy.
- Plausible original source shape: shared virtual name, Win32-era `unsigned char`/`unsigned long`, fixed 128-byte packet scratch buffer matching sibling stack use, direct helper calls, and no decompiler temporaries.
- Naming style follows existing project class/method and packet-helper conventions. It does not leak IDA labels.
- Third-party import directive: not applicable; this is NexusTK project code.

## Final Recommendation

- All claims C2NU-001 through C2NU-048 are applied and physically verified; sibling UIDs remain support-only and are not declared as report-covered targets.
- Keep target owner/emitter/reconstructable route unchanged and raise only the primary target to `94/94`.
- The whole shared callback declaration/definition family is corrected so subsequent generated C++ cannot contain conflicting virtual types or invalid returns.
- Supervisor-owned manual coverage, IDA persistence/readback, independent validation, and generated CPP/H readback are complete. Only report execution/archive lifecycle remains supervisor-owned and path/validator authoritative.
- No item remains no-owner because of this work; the aggregate UID00010K remains intentionally non-emitting evidence.
- Future coordinated `ClanDialogs.cpp` source-tree work is outside this report and does not block the current method.

## Recommended Target Doc Changes

- Path: `by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md`.
- Metadata: `COMPLETION:94`, `CONFIDENCE:94`; keep owner `00002O`, reconstructable true, emitter `00002O`, and blank H.
- Replace formal CPP with Section 22 exactly.
- Item Summary: describe exact virtual route, void callback, 128-byte source packet local, value-first writers, `_wtol`, packet bytes, explicit seven-byte send, Socket copy ownership, and no validation without repeating metadata rendered by generated reports.
- Add exact body hash, successor padding, base/family return proof, helper API proof, protocol request/open/success chain, amount conversion semantics, spare-zero/send-length distinction, and source placement.
- Preserve historical assumptions in a clearly labeled rejected/history section: old `int`, destination-first prose, eight-byte local, sender return, and old broad report reasoning.
- Do not expand this page over alignment, raw constructor, class declaration, helper bodies, or dispatcher ranges.

## Recommended Support Doc Changes

- `by-class/ClanWidMoneyInputDialog.md`: change its formal H virtual return to `void`; add sole-slot and target behavior evidence; keep `86/90`, owner/emitter `0000I8`.
- `by-class/ClanNameInputDialog.md`: change the base virtual return to `void`; document that `OnButtonClick` invokes the slot and ignores a result; keep `86/89`.
- `by-class/ClanDepMoneyInputDialog.md`, `ClanExpelNameInputDialog.md`, `ClanSummonNameInputDialog.md`, `ClanAppearNameInputDialog.md`, and `ClanChangeNameInputDialog.md`: change every duplicate/stale `int OnSubmitText` declaration to `void`; preserve current metadata.
- `by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md`: change formal definition to `void`, use `packet[128]`, and remove `return` from QueueAndSendPacket; preserve `86/91`.
- `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md`, `0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md`, `0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md`, and `0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md`: change formal definitions to `void` and remove the final `return`; preserve current metadata.
- `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`: replace the stale `int` family claim with six void overrides; keep non-reconstructable/non-emitting `85/89`.
- `by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`: add explicit evidence that the existing `OnSubmitText(text);` call is void and no result is consumed; keep `88/91`.
- `by-file/Clan.md`: add the coherent void callback/value-first packet-helper contract and retain active source placement. No direct edit to generated `Clan.cpp` is allowed.
- `by-file/ClanDialogs.md`: no required metadata or source-route edit; mention only if its existing prose explicitly asserts `int` after callback implementation review.

## Score And Metadata Recommendation

- Historical pre-callback primary state: `86/91`, owner/emitter `00002O`, reconstructable true.
- Current callback-applied primary state: `94/94`, with the same owner/emitter/reconstructable state.
- Reason higher: exact range/hash/boundary, sole vtable route, zero callers, base dispatch, six-leaf return proof, exact frame/local shape, value-first helper declarations and push order, full packet protocol chain, queue ownership, validation absence, and source-ready formal CPP are all resolved.
- Reason not 95+: original lexical names and the exact historical compilation-unit split remain inferred; all implementation, IDA, validation, coverage, and generated-readback closure work is complete.
- Score-improvement attempt closed every target blocker named by the goal: writer order, return type, packet size, packet semantics, buffer ownership, send behavior, validation, source name, owner/emitter, range, and source placement.
- Support scores remain unchanged; only stale manual coverage percentages for classes are synchronized to current metadata.

## Open Questions With Attempted Resolution

- **Was the writer API destination-first?** No. Current prototypes and x86 push order prove value-first.
- **Was the callback `int`?** No. Base result is ignored, target is void in decompile/disassembly, and all six leaves produce no return value.
- **Was the source local only eight bytes?** No. The frame reserves exactly 128 packet-local bytes plus the cookie. Eight bytes merely suffice for the emitted payload and terminator.
- **Does action 1 mean submit?** Yes. Action 0 requests/opens the withdraw dialog; this body sends action 1 with the amount; incoming result/action 1 is accepted.
- **Does byte 7 belong to the payload?** No. Both the UInt32BE helper and explicit store zero it, but send length is seven; QueueAndSendPacket copies only offsets 0..6 and appends its own private zero.
- **Can original lexical names be proven?** No symbols survive. `OnSubmitText`, `text`, `packet`, and `amount` are high-probability descriptive names chosen from class behavior and project conventions. This rare lexical uncertainty caps the score below 95 but does not justify IDA labels in final C++.
- **Should the method move to ClanDialogs?** Not alone. Only a coordinated source-tree split could justify that future change.
- No source-quality, documentation, IDA, coverage, validation, or generated-readback blocker remains unresolved. Original lexical spelling and a possible future coordinated source-tree split remain bounded inference questions, not blockers.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-callback inspection found stale rows in `by-memory/-coverage-report.md` and `by-class/-coverage-report.md`. B006 did not edit these shared files; the supervisor subsequently applied the exact three rows below and validated them successfully.
- Replace the UID0002NU row with:

`        - [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) 0x004890b0-0x00489132 | method | ClanWidMoneyInputDialog::OnSubmitText : reconstructable : 94% : very-strong : Current live IDA proves the exact 0x82-byte body and DD45DB894501355CC30E71B4636608D43E306E011F292509931F0ABEE2EF395E hash, sole vtable route at 0x00615a94, void callback contract, 128-byte source packet local, value-first PacketBuffer calls, _wtol amount conversion, {0x4b,0x0b,1,amount32-be} layout, explicit seven-byte send, local-only byte-seven zero, Socket-owned queued copy, Clan class/file route, and source-ready formal C++ with no input clamp or send-result branch.`

- Replace the UID00002O row with:

`- [UID:00002O][ClanWidMoneyInputDialog](by-class/ClanWidMoneyInputDialog.md) : reconstructable : 86% : very-strong : Live IDA proves the primary-vtable OnSubmitText route at 0x00615a94, exact void withdraw-money submitter, 128-byte local packet shape, value-first PacketBuffer API, _wtol conversion, seven-byte Socket-owned queue copy, Clan source ownership, and separately documented raw-constructor caveat.`

- Replace the UID00002J row with:

`- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md) : reconstructable : 86% : very-strong : Live IDA proves the base text-submit dispatch through primary vtable slot +0x5c, ignored result and therefore void callback contract, exact submitted wide-text argument, six derived leaf overrides, established Clan ownership, and remaining constructor/source-split uncertainty.`

- The supervisor followed the validator-owned flow rather than manually editing `auto-generated/-ag-research-tracker.md` or `-ag-memory-coverage.md`; broad generated refresh completed after source-document validation.

## Follow-Up Actions

- Supervisor Gate 1: completed `33/33`; implementation callback accepted.
- B006 callback: C2NU-001 through C2NU-036 implemented with JIT leases and physically verified; no coverage or generated file was directly edited.
- Supervisor Gate 2B: completed. Literal prestates matched; A00-A05 persisted; P01 remained protected; exactly one save succeeded; fresh-copy readback verified every result.
- Supervisor closure: C2NU-037 through C2NU-048 completed, including exact manual rows, independent scoped validation, broad generated refresh, and generated Clan CPP/H coherence readback.
- Remaining lifecycle action, if authorized by the primary supervisor, is report execution/archive handling; its truth is authoritative only from current path plus validator-owned status/history.

## Confidence

- Behavior and protocol: very strong.
- Range, ownership, emitter, and source placement: very strong for current project routing.
- Return type, helper order, local shape, and sender ownership: very strong.
- Source-facing lexical names: strong inference, not original-symbol proof.
- Implementation, IDA persistence/readback, coverage updates, all scoped validators, broad generated refresh, and generated CPP/H readback are complete. The score remains intentionally capped at 94 only for source-facing lexical uncertainty and the exact historical compilation-unit split.

## Validator Results

- Every edited by-* file was validated from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <relative-path> --apply --no-generated-refresh --queue-timeout 240`.
- Every command exited `0` and reported `ok: 1`. Every command reported `generated_refresh: skipped` and `generated_refresh_detail: disabled by --no-generated-refresh`.
- The validator's own scoped bookkeeping reported `projected_stats_update: 1`; B006 did not manually edit tracker/stats, generated output, validator.ini, or lifecycle state and does not count that bookkeeping as completion of supervisor-owned C2NU-047/048.

| Path | Command ID | Timestamp | Exit | ok | Stable SHA256 | Bytes | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md` | `000000021711` | `2026-08-10T12:38:28-04:00` | 0 | 1 | `F2A85293F3ABF599028CA1EB8BDA8A89056D738AE3E5C3517E19D6805A71AA55` | 15144 | No warnings; generated refresh skipped. |
| `by-class/ClanNameInputDialog.md` | `000000021713` | `2026-08-10T12:39:17-04:00` | 0 | 1 | `73CAF6805A9995BAAB33A952D2FDFA1B4F82E8EC384F06C37B45DF161C188190` | 11667 | No warnings; generated refresh skipped. |
| `by-class/ClanWidMoneyInputDialog.md` | `000000021715` | `2026-08-10T12:39:51-04:00` | 0 | 1 | `2C3C8CA59A2DB978E09A61006874078AB499A6A17F7BE9ABD5BEB1F45D87E74F` | 14354 | No warnings; generated refresh skipped. |
| `by-class/ClanDepMoneyInputDialog.md` | `000000021716` | `2026-08-10T12:40:17-04:00` | 0 | 1 | `04B87AB7F2C030DEDDD20A6BF7FC94DAA37EE887DCFBE51CF730F17C9C3D4A88` | 18844 | No warnings; generated refresh skipped. |
| `by-class/ClanExpelNameInputDialog.md` | `000000021718` | `2026-08-10T12:40:39-04:00` | 0 | 1 | `42BBD523705073CB8B53C5EB93FCD823D5D3DEB3AE033D447E63B35D9C2D0407` | 16530 | No warnings; generated refresh skipped. |
| `by-class/ClanSummonNameInputDialog.md` | `000000021721` | `2026-08-10T12:41:01-04:00` | 0 | 1 | `3CA1A32D427233F178616C1688DED00A89786E8669A0EB8EE4C3020D2536F7A0` | 13804 | No warnings; generated refresh skipped. |
| `by-class/ClanAppearNameInputDialog.md` | `000000021723` | `2026-08-10T12:41:50-04:00` | 0 | 1 | `1E3C6BC235A8ED15B32618036A382A942161B7DF325DAD2267B9597805777605` | 12536 | No warnings; generated refresh skipped. |
| `by-class/ClanChangeNameInputDialog.md` | `000000021724` | `2026-08-10T12:42:13-04:00` | 0 | 1 | `24CF13C0B5D371557CFF889A30C505425979CB0F202521AE269836852ADBC152` | 15044 | No warnings; generated refresh skipped. |
| `by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md` | `000000021725` | `2026-08-10T12:42:48-04:00` | 0 | 1 | `42322AD3CECDCC42A6A0BF6E6465F88A532497E995BAED7CA42374190A60E8D4` | 9809 | No warnings; generated refresh skipped. |
| `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md` | `000000021726` | `2026-08-10T12:43:10-04:00` | 0 | 1 | `C857C43E3799B98B993157FD93D2304A690EAA5CF6E0A6A188DB954ACA57C5FE` | 10524 | No warnings; generated refresh skipped. |
| `by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md` | `000000021727` | `2026-08-10T12:43:35-04:00` | 0 | 1 | `4197D33C9CE9118F8FEE7AAA6FD3DA1D8DB262DA748F306AA565529FFD70A020` | 10551 | No warnings; generated refresh skipped. |
| `by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md` | `000000021728` | `2026-08-10T12:43:59-04:00` | 0 | 1 | `957407C53600234FEBCADEBF5C26DD9441FE5F39EF604BCD38BCE771614E55C7` | 10884 | No warnings; generated refresh skipped. |
| `by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md` | `000000021729` | `2026-08-10T12:44:20-04:00` | 0 | 1 | `88434CB6C987F1C7F6D1CE807B590967D06705B7F5EE44765FA07FA7FE055B98` | 10517 | No warnings; generated refresh skipped. |
| `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md` | `000000021730` | `2026-08-10T12:44:54-04:00` | 0 | 1 | `3F08B979308026BB735D69301E10CD34BEE827AF7E432DAE1D676C1F70EB9468` | 26274 | No warnings; generated refresh skipped. |
| `by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md` | `000000021731` | `2026-08-10T12:45:18-04:00` | 0 | 1 | `018DEBA1C1F564B8D99799BB56F815E3F383F31C586F6BF3D1F2E79943443486` | 16096 | No warnings; generated refresh skipped. |
| `by-file/Clan.md` | `000000021732` | `2026-08-10T12:46:02-04:00` | 0 | 1 | `0A3C131E760F86C90415D2241BE3C8C9CD1CDBA0F25A77A737E140588304AD6F` | 121342 | `missing_ref_uid: 10` for pre-existing `000411`, `000412`, and `0003B8`; validator still reported `ok: 1`; generated refresh skipped. |

- The ten `Clan.md` missing-reference notices predate and are unrelated to this callback; none references a UID or link introduced by B006.
- Supervisor independent revalidation commands `000000021745` through `000000021760` covered all 16 changed ordinary documents; every command exited 0, reported `ok: 1`, and skipped generated refresh. Command `000000021760` retained ten unrelated pre-existing `Clan.md` missing refs.
- Manual coverage receipt C2NU-037: exact UID0002NU 94% row applied; scoped command `000000021761` exited 0/ok 1 and retained two unrelated pre-existing missing refs.
- Manual coverage receipts C2NU-038/C2NU-039: exact UID00002O and UID00002J 86% rows applied; scoped command `000000021762` exited 0/ok 1.
- Broad generation receipt C2NU-048: command `000000021763`, timestamp `2026-08-10T13:43:16-04:00`, exited 0 with generated refresh completed. `auto-generated/NexusTK/social/Clan.cpp` contains exactly the accepted UID0002NU 94/94 body, and `Clan.h` contains owner declaration `virtual void OnSubmitText(const wchar_t *text);`.
- Report lifecycle truth is represented by the current report path plus validator-owned status/history; this closure update does not claim that the report has been executed or archived.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/0002NU-ClanWidMoneyInputDialogSubmitWithdrawMoney-source-quality.md`.
- Modified during the accepted B006 callback: the primary target, seven listed `by-class/Clan*InputDialog.md` pages, five listed sibling submitter pages, `ClanNameDialogSubmitters.md`, `ClanNameInputDialogCore.md`, `by-file/Clan.md`, and this report. Exact callback hashes are in Section 31.
- Supervisor-confirmed closure artifacts, not edited by B006 in this report-only update: exact manual coverage rows, canonical IDB metadata/comments/types with pre/post backups, independently revalidated ordinary docs, and validator-generated reports plus `NexusTK/social/Clan.cpp`/`Clan.h` readback.
- Renamed: none.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned lifecycle metadata. B006 did not and will not run `execute_report`, `invalidate_execute`, registry lifecycle commands, or manual report movement.
- Stable artifact identity is recomputed after the final physical reread and reported to the supervisor; it is not embedded as self-referential mutable authority.

## Implementation Tracking Checklist

Checklist parity: every row below mirrors the Section 11 ledger in identical order by Claim ID, Target UID, destination/claim identity, actor/authority, action, and verification state. Closure state is 48 checked claims and zero pending claims.

| Done | Claim ID | Target UID | Destination / claim identity | Actor / authority | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| [x] | C2NU-001 | 0002NU | Target / exact range and body identity | B006 after Gate 1 | Record `[0x004890b0,0x00489132)`, size `0x82`, and body SHA256 `DD45DB894501355CC30E71B4636608D43E306E011F292509931F0ABEE2EF395E`. | Applied and physically verified |
| [x] | C2NU-002 | 0002NU | Target / successor boundary | B006 after Gate 1 | Record fourteen `0xcc` bytes at `[0x00489132,0x00489140)` as alignment outside the target. | Applied and physically verified |
| [x] | C2NU-003 | 0002NU | Target / virtual route | B006 after Gate 1 | Record sole inbound data xref `0x00615a94 -> 0x004890b0` and zero ordinary callers. | Applied and physically verified |
| [x] | C2NU-004 | 0002NU | Target / callback return | B006 after Gate 1 | Replace stale `int` callback claims with `void`. | Applied and physically verified |
| [x] | C2NU-005 | 0002NU | Target / local packet shape | B006 after Gate 1 | Replace `packet[8]` with source-faithful `packet[128]`. | Applied and physically verified |
| [x] | C2NU-006 | 0002NU | Target / packet layout | B006 after Gate 1 | Document `{0x4b,0x0b,1,amount32-be}` at offsets `0..6`. | Applied and physically verified |
| [x] | C2NU-007 | 0002NU | Target / PacketBuffer API | B006 after Gate 1 | Preserve value-first writer calls and reject destination-first historical prose. | Applied and physically verified |
| [x] | C2NU-008 | 0002NU | Target / amount conversion | B006 after Gate 1 | Document `_wtol` and 32-bit signed-to-unsigned bit-pattern preservation. | Applied and physically verified |
| [x] | C2NU-009 | 0002NU | Target / validation behavior | B006 after Gate 1 | Record absence of null, parse, sign, range, overflow, and sender checks. | Applied and physically verified |
| [x] | C2NU-010 | 0002NU | Target / spare zero and send length | B006 after Gate 1 | Record helper zero at byte 7, repeated explicit zero, and seven-byte send excluding byte 7. | Applied and physically verified |
| [x] | C2NU-011 | 0002NU | Target / sender ownership | B006 after Gate 1 | Record exact seven-byte copy to Socket-owned queue storage and void return. | Applied and physically verified |
| [x] | C2NU-012 | 0002NU | Target / protocol request route | B006 after Gate 1 | Record outgoing action `0` `{0x4b,0x0b,0}` as dialog request. | Applied and physically verified |
| [x] | C2NU-013 | 0002NU | Target / protocol open route | B006 after Gate 1 | Record incoming opcode `0x43`, subtype `11`, result/action `0` as dialog construction. | Applied and physically verified |
| [x] | C2NU-014 | 0002NU | Target / protocol success route | B006 after Gate 1 | Record incoming subtype `11`, result/action `1` as accepted no-dialog path. | Applied and physically verified |
| [x] | C2NU-015 | 0002NU | Target metadata / owner-emitter route | B006 after Gate 1 | Keep owner/emitter `00002O` and reconstructable true. | Applied and physically verified |
| [x] | C2NU-016 | 0002NU | Target / source placement | B006 after Gate 1 | Keep active source route `00002O -> 0000I8 -> Clan.cpp`. | Applied and physically verified |
| [x] | C2NU-017 | 0002NU | Target / rejected isolated split | B006 after Gate 1 | Preserve `ClanDialogs.md` only as a coordinated future split candidate. | Applied and physically verified |
| [x] | C2NU-018 | 0002NU | Target formal RECONSTRUCTION_CPP CODE | B006 after Gate 1 | Replace with the exact void/value-first/128-byte body in Section 22. | Applied and physically verified |
| [x] | C2NU-019 | 0002NU | Target formal RECONSTRUCTION_H CODE | B006 after Gate 1 | Keep blank because the class page owns the declaration. | Applied and physically verified |
| [x] | C2NU-020 | 0002NU | Target metadata / score | B006 after Gate 1 | Raise `86/91` to `94/94`; leave all routing metadata unchanged. | Applied and physically verified |
| [x] | C2NU-021 | 0002NU | Target prose / stale assumptions | B006 after Gate 1 | Incorporate full evidence and historicalize contradicted destination-first/int/packet[8] claims. | Applied and physically verified |
| [x] | C2NU-022 | 00002O | by-class/ClanWidMoneyInputDialog.md / declaration | B006 after Gate 1 | Change `virtual int OnSubmitText` to `virtual void OnSubmitText`; keep `86/90` and route. | Applied and physically verified |
| [x] | C2NU-023 | 00002J | by-class/ClanNameInputDialog.md / base declaration | B006 after Gate 1 | Change base virtual return to `void` and document ignored-result dispatch; keep `86/89`. | Applied and physically verified |
| [x] | C2NU-024 | 00002A | by-class/ClanDepMoneyInputDialog.md / declaration | B006 after Gate 1 | Change both stale `int` declarations to `void`; document 128-byte family shape. | Applied and physically verified |
| [x] | C2NU-025 | 00002D | by-class/ClanExpelNameInputDialog.md / declaration | B006 after Gate 1 | Change both stale `int` declarations to `void`. | Applied and physically verified |
| [x] | C2NU-026 | 00002M | by-class/ClanSummonNameInputDialog.md / declaration | B006 after Gate 1 | Change stale `int` declaration to `void`. | Applied and physically verified |
| [x] | C2NU-027 | 000023 | by-class/ClanAppearNameInputDialog.md / declaration | B006 after Gate 1 | Change stale `int` declaration to `void`. | Applied and physically verified |
| [x] | C2NU-028 | 000028 | by-class/ClanChangeNameInputDialog.md / declaration | B006 after Gate 1 | Change stale `int` declaration to `void`. | Applied and physically verified |
| [x] | C2NU-029 | 0002NS | Deposit submitter formal CPP | B006 after Gate 1 | Change definition to `void`, packet to 128 bytes, and final `return` call to a statement. | Applied and physically verified |
| [x] | C2NU-030 | 0002NW | Expel submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified |
| [x] | C2NU-031 | 0002NY | Summon submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified |
| [x] | C2NU-032 | 0002O0 | Appear submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified |
| [x] | C2NU-033 | 0002O2 | Change-name submitter formal CPP | B006 after Gate 1 | Change definition to `void` and final `return` call to a statement. | Applied and physically verified |
| [x] | C2NU-034 | 00010K | ClanNameDialogSubmitters / family contract | B006 after Gate 1 | Historicalize `int` and record six `void` overrides; keep non-emitting metadata. | Applied and physically verified |
| [x] | C2NU-035 | 00010J | ClanNameInputDialogCore / dispatch evidence | B006 after Gate 1 | State that `OnSubmitText(text)` is a void virtual call and no result is consumed. | Applied and physically verified |
| [x] | C2NU-036 | 0000I8 | by-file/Clan.md / callback family note | B006 after Gate 1 | Add coherent void callback and value-first PacketBuffer family note; keep source route. | Applied and physically verified |
| [x] | C2NU-037 | 0002NU | by-memory/-coverage-report.md / target row | Supervisor only | Replace stale 82% row with exact 94% row from Section 28. | Applied and physically verified |
| [x] | C2NU-038 | 00002O | by-class/-coverage-report.md / owner row | Supervisor only | Replace stale 84% row with current 86% source-quality row from Section 28. | Applied and physically verified |
| [x] | C2NU-039 | 00002J | by-class/-coverage-report.md / base row | Supervisor only | Replace stale 85% row with current 86% source-quality row from Section 28. | Applied and physically verified |
| [x] | C2NU-040 | 0002NU | IDA A00 / class forward declaration | Supervisor Gate 2B | Declare `struct ClanWidMoneyInputDialog;` if dry-run/readback confirms absent. | Applied and physically verified |
| [x] | C2NU-041 | 0002NU | IDA A01 / function name | Supervisor Gate 2B | Pure-rename `sub_4890B0` to `ClanWidMoneyInputDialog__OnSubmitText`. | Applied and physically verified |
| [x] | C2NU-042 | 0002NU | IDA A02 / stack argument name and type | Supervisor Gate 2B | Rename `arg_0` to `text` and type it `const wchar_t *`. | Applied and physically verified |
| [x] | C2NU-043 | 0002NU | IDA A03 / function prototype | Supervisor Gate 2B | Apply exact void thiscall prototype from Section 21. | Applied and physically verified |
| [x] | C2NU-044 | 0002NU | IDA A04 / function regular comment | Supervisor Gate 2B | Apply exact source-quality function comment from Section 21. | Applied and physically verified |
| [x] | C2NU-045 | 0002NU | IDA A05 / vtable slot regular comment | Supervisor Gate 2B | Apply exact source-quality comment at `0x00615a94`. | Applied and physically verified |
| [x] | C2NU-046 | 0002NU | IDA P01 / protected state | Supervisor Gate 2B | Preserve body/range/hash, one data xref, zero callers, 13 internal comments, other frame rows, helpers, and globals. | Applied and physically verified |
| [x] | C2NU-047 | 0002NU | Documentation validation plan | Supervisor only | Independently confirm the scoped validation receipts for every changed by-* page after callback. | Applied and physically verified |
| [x] | C2NU-048 | 0002NU | Generated/manual readback plan | Supervisor only | Refresh generated outputs as required, inspect Clan.cpp/H, and apply manual rows only after docs validate. | Applied and physically verified |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000021775","destination_path":"executed-b-agent-research/B006/0002NU-ClanWidMoneyInputDialogSubmitWithdrawMoney-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002NU-ClanWidMoneyInputDialogSubmitWithdrawMoney-source-quality.md","timestamp":"2026-08-10T14:09:03-04:00","uid":"0002NU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
