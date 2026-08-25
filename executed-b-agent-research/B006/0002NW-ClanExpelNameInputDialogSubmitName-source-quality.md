** TARGET-REPORT-UID:0002NW **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002NW ClanExpelNameInputDialog Submit Name Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: the accepted B006 documentation callback is complete. Keep this source-authored virtual method owned and emitted by [UID:00002D] `ClanExpelNameInputDialog`, retain the active `social/Clan.cpp` route through [UID:0000I8] `Clan`, and keep the target at the callback-applied `94/94` with the exact live behavior and ABI evidence below.
- Final disposition: reconstructable, class-owned, source-emitting method at `[0x00489180,0x0048926e)`, with a source-facing `void ClanExpelNameInputDialog::OnSubmitText(const wchar_t *text)` definition and no child-owned header declaration.
- Current action state: B006 applied and physically reread C2NW-001 through C2NW-047 and completed scoped validations C2NW-071 through C2NW-074. Supervisor Gate 2A verification, manual rows C2NW-048/049, generated refresh/readback C2NW-050/051, and Gate 2B A00-A11/P01-P07 closure C2NW-052 through C2NW-070 remain supervisor-owned.
- Confidence: `94/94`. The method body, vtable route, protocol bytes, conversion, guard order, queue semantics, boundaries, and source owner are directly supported. The remaining cap is original lexical spelling and the broader historical `Clan.cpp` versus `ClanDialogs.cpp` split, not behavior or reconstruction eligibility.

## Supporting Research

- Project context: local old-game preservation and faithful source reconstruction of the unsupported NexusTK client.
- Report-time MCP evidence snapshot, `2026-08-10`: session `4e22e4ac-5109-440b-bc04-5e7896fb14a2`, database `supervisor-b005-final-persisted-verify-20260810`, canonical IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The exact session/database identity is dated historical evidence only; the supervisor must dynamically re-establish current Gate 2B authority from the canonical path and fresh runtime/readback evidence.
- At that report-time snapshot, `server_health` returned `status:ok`, `hexrays_ready:true`, `strings_cache_ready:true`, image base `0x400000`; `auto_analysis_ready:false` was recorded as context and did not prevent bounded live IDB-backed queries.
- Historical reports were used only as leads: three exact older B001 artifacts, the B011 class report, B006 UID00021L, and the supervisor-validated UID0002NU report. Every target-specific conclusion below was rechecked against the then-current canonical IDB and documentation during the dated report-time research pass.
- No Wave2/Wave3 evidence or instruction was used.
- Report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

Exhaustive B001 reconciliation found exactly these three Clan submitter/raw-constructor artifacts by searching UID `0002NW`, address `0x00489180`, target/class names, helper names, and the submitter family:

| Historical B001 artifact | SHA256 | Relevant claim | Current disposition |
| --- | --- | --- | --- |
| `executed-b-agent-research/B001/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md` | `2EA63F0B4182699E307A76112802941E5BF194AB6D88F590C00B174C2556CECB` | Class owner/emitter and `Clan.cpp` route | Accepted and independently confirmed by the sole vtable xref plus current emitter graph. |
| same broad-family artifact | same | Submitter is C++ eligible despite separate raw constructors | Accepted; the target is a complete modeled method. |
| same broad-family artifact | same | Shared virtual name `OnSubmitText` | Accepted as the highest-probability source name. |
| same broad-family artifact | same | Callback returns `int` | Corrected: live body, base dispatch, sibling leaves, and queue helper prove `void`. |
| same broad-family artifact | same | Exact CP_ACP conversion | Accepted and independently revalidated. |
| same broad-family artifact | same | Unsigned thresholds `0x100` and `0x80` plus observed order | Accepted as binary/compiler evidence; explicit authored `__report_rangecheckfailure` calls are superseded by compiler-generated instrumentation around indexed source writes. |
| same broad-family artifact | same | Length byte, payload at offset 4, and unsent scratch NUL | Accepted and independently revalidated. |
| same broad-family artifact | same | Reject a higher-level string helper | Accepted; direct fixed-array conversion/copy source shape best matches the body. |
| same broad-family artifact | same | Destination-first byte-writer prototypes | Corrected: live helper type/body and cdecl pushes prove value-first calls. |
| same broad-family artifact | same | Socket queue/copy semantics and `g_packetSender` | Accepted, except the old meaningful return/`return QueueAndSendPacket` interpretation is corrected to a void statement. |
| same broad-family artifact | same | Subtype 7/action 1 and family protocol | Accepted and independently tied to outgoing action 0 plus incoming subtype-7 open/accept branches. |
| same broad-family artifact | same | Exact `0xee` range and following padding | Accepted and independently revalidated. |
| same broad-family artifact | same | UID00010K remains non-emitting and `ClanDialogs` is only a future coordinated split | Accepted. |
| same broad-family artifact | same | Historical score `86/91` | Superseded by the dedicated `94/94` recommendation. |
| same broad-family artifact | same | Historical UID0002NW formal C++ | Corrected to void, value-first calls, no explicit compiler-runtime guard calls, and no returned send expression. |
| same broad-family artifact | same | Money-only `_wtol`, UInt32BE, and `packet[8]` facts | Not applicable to UID0002NW. |
| same broad-family artifact | same | Proposed file-scope packet constants | Not applicable here because no target-specific source evidence requires additional declarations. |
| `executed-b-agent-research/B001/0002NV-ClanExpelNameInputDialogRawConstructor-empty-emitter-source-quality.md` | `75D5F236EB9B933BB747C25F625373BA4DC04A6EF7088A3D36FCE838A4CA389D` | Separate raw constructor at `0x00489140-0x00489175` has no direct route | Accepted as separate sibling evidence; it is not part of UID0002NW. |
| same raw-constructor artifact | same | Class vtable identity and inline construction | Accepted as class corroboration. |
| same raw-constructor artifact | same | UID0002NW independently emits the submit body and raw-constructor uncertainty does not block it | Accepted. |
| same raw-constructor artifact | same | Clan owner and `Clan.cpp` route; `ClanDialogs` remains uncertain | Accepted. |
| same raw-constructor artifact | same | UID0002NW required no dedicated edit because no contradiction existed | Superseded: this pass found stale no-code, sender-result, API-order, and missing target-detail defects. |
| same raw-constructor artifact | same | Raw-constructor no-code score/marker | Not applicable to this modeled target method. |
| same raw-constructor artifact | same | Generated source-order marker around UID0002NW | Accepted as route/order corroboration only. |
| `executed-b-agent-research/B001/0002NX-0002O1-clan-name-raw-constructor-source-placement.md` | `6122042519D53F8DF3687C931E3293B3C575E6F2C3E14B31DAFF855B748FF182` | UID0002NX begins at `0x00489270` as a separate retained raw Summon constructor and is not part of UID0002NW | Accepted as exact successor identity/exclusion evidence. |
| same UID0002NX/UID0002O1 artifact | same | Clan remains the stronger current family source owner while ClanDialogs is only a coordinated split candidate | Accepted and independently consistent with the current owner/emitter graph. |
| same UID0002NX/UID0002O1 artifact | same | Direct constructor owners remain their classes and UID00010K remains a non-emitting family aggregate | Accepted as family routing evidence; it does not change UID0002NW ownership. |
| same UID0002NX/UID0002O1 artifact | same | Retained raw constructors remain reconstructable but blank-C++ because reachability/source duplication is unresolved | Not applicable to UID0002NW, which is a complete modeled virtual method with a direct vtable route and exact formal C++. |
| same UID0002NX/UID0002O1 artifact | same | Wave2/fallback family observations made while live MCP was unavailable | Not accepted as target authority; stale Wave2 is ignored and every used boundary/route fact was independently revalidated through the dated report-time live MCP evidence. |

## Target

- Target UID: `0002NW`.
- Additional target UIDs: none.
- Target path: `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md`.
- Queue row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, current `86/91`, score `88.5`, zero direct/additional B-report coverage at assignment time.
- Exact entity: one modeled function at `0x00489180`, size `0xee` / 238 bytes, exclusive end `0x0048926e`.
- Direct source owner: [UID:00002D] `ClanExpelNameInputDialog`; source-file route: [UID:0000I8] `Clan` -> `social/Clan.cpp`.

## Current Target State

- Callback-applied metadata: `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:00002D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002D`, blank emitter-position override.
- Formal CPP now contains the exact Section 22 void/value-first developer-source method without explicit compiler-runtime calls; formal H remains blank because the class page owns `virtual void OnSubmitText(const wchar_t *text);`.
- The target now records exact body/hash/frame/API/guard/protocol/ownership evidence and historicalizes the former no-code, sender-result, destination-first, and explicit-runtime-source assumptions. UID00002D, UID00010K, and UID0000I8 contain the accepted target-specific support detail. Generic PacketBuffer, memmove, and queue helpers were physically verified at same-or-greater detail and left unchanged.
- Generated `auto-generated/NexusTK/social/Clan.cpp`, `Clan.h`, tracker, and generated coverage remain supervisor-owned pending C2NW-050/051 refresh/readback; ordinary callback completion is not contingent on claiming that stale generated state is current.
- Dated rollback/prestate evidence snapshot, `2026-08-10`: runtime attestation against database `supervisor-b009-uid00028d-rollback-verify-20260810` observed name `sub_489180`, type `int __stdcall(LPCWCH lpWideCharStr)`, and a code item headed at `0x489180`; no source class type, blank function/address comments, fragmented packet stack variables, one vtable data xref, and no ordinary code callers otherwise remained as recorded. This exact database identity is historical snapshot evidence, not permanent current Gate 2B authority; the supervisor must fresh-attest current canonical state before acting.
- The earlier report observation that current IDA already displayed a void-returning `__stdcall` type is superseded history. The evidence-backed final source/member ABI remains `void`, but Gate 2B must intentionally correct the current IDA return/calling-convention type from `int __stdcall` to the proposed `void __thiscall` member signature rather than treating return type as already correct.
- Historical failed-closed Gate 2B receipt, `2026-08-10`: A09 `set_type` returned `ok:true` and the function prototype read back exactly as `void __thiscall(ClanExpelNameInputDialog *this, const wchar_t *text)`, while the physical stack-frame row remained `text@+0x194`, size 4, type `LPCWCH`. The supervisor correctly stopped before A10/A11/save, retired the unsaved worker, and fresh canonical readback proved complete rollback to absent A00 type, `sub_489180`, `int __stdcall(LPCWCH lpWideCharStr)`, original frame names/types, and blank comments. This is historical evidence, not current mutated state.
- `LPCWCH` is IDA's stable physical typedef rendering for the frame argument and is semantically equivalent to the final prototype's `const wchar_t *`. A09 therefore changes only the function prototype; no additional stack `set_type` action is authorized or required, and F10 must remain physically typed `LPCWCH` after A09.
- B006 made no IDA mutation; A00-A11 and P01-P07 remain an exact supervisor Gate 2B handoff.

## Executive Recommendation

- Keep `CANONICAL_OWNER:00002D`, `EMITTER_UIDS:00002D`, and `RECONSTRUCTABLE:TRUE`.
- Raise the target to `94/94`; do not lower or preserve the old score merely because original local symbols are absent.
- Replace the formal CPP with the exact Section 22 developer-source form. It preserves both indexed writes and the observed conversion/write/copy/send order, but does not explicitly call compiler runtime helper `__report_rangecheckfailure`; matching original MSVC instrumentation must regenerate the two observed checks.
- Keep formal H blank on the by-memory child because [UID:00002D] already owns the declaration.
- Reject `CANONICAL_OWNER:NONE`, a file-local free helper, a raw retained helper, and an isolated `ClanDialogs.cpp` move. The vtable slot directly establishes a class override, and the current graph consistently routes the family through `Clan.cpp`.
- Treat `destination-first writer contract` from the assignment wording as a hypothesis that was tested and rejected: the live helper prototype and right-to-left cdecl pushes prove a value-first API.
- Treat the two range-failure branches as compiler evidence, not authored source syntax. The first is associated with `convertedName[convertedLength]`; the second occurs after `memmove` and is associated with `packet[packetLength]`. Their placement remains a hard behavioral/build-fidelity requirement even though the runtime helper calls do not appear in human-written C++.

## Supervisor Active Recheck

- Historical callback-stage fact: a prior exact UID0002NW report revision passed Gate 1 and received the documentation implementation callback; implementation did not convert the older broad family report into target authority. The current exact revision requires a fresh supervisor artifact audit before any further gate or lifecycle action.
- No split-first repair is required. The target is one complete modeled function; the two following `0xcc` bytes are alignment and the successor raw constructor starts at `0x00489270` outside this target.
- All source-bearing behavior is now represented by the target formal CPP; the owner declaration remains represented by [UID:00002D].
- Mandatory MCP evidence captured during the dated report-time pass remains research evidence. Its exact session/database identities are snapshots only; current Gate 2B authority must be dynamically re-established by the supervisor. The documentation callback used no IDA/MCP mutation.
- B006 edited only the four accepted ordinary by-* destinations and this report. No coverage/generated, audit/catalog, goal/notes, removed-code companion, IDA, or lifecycle file was edited manually. Scoped validators made their normal validator-owned registry/projected-stats updates with generated refresh disabled.

## Inference Research Guidance Check

- Binary fact, documentation evidence, and inference are separated throughout this report.
- Current documentation assumptions were treated as potentially stale, especially `destination-first`, sender-result, no-code, generated callback ABI, helper-name, and source-split wording.
- `by-structure.md` ownership rules support the exact child method under its class owner rather than duplicating the body in the family aggregate or by-file page.
- Source shape favors one normal virtual method with human names and a contiguous packet array. IDA's fragmented stack labels are compiler/decompiler artifacts, not acceptable final source.
- Original names are not required to retain `sub_489180`, `MultiByteStr`, `Src`, or `var_80`; the best context-supported human names are required when original symbols are lost.
- Wave2/Wave3 mentions in historical material were ignored as stale.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Function identity | Sole inbound data xref `0x00615b34 -> 0x00489180`; slot position matches the base submit virtual and the derived class page. | High-confidence `ClanExpelNameInputDialog::OnSubmitText`. |
| Calling convention | IDA shows `__stdcall(LPCWCH)` because ECX is unused and the body ends `retn 4`; vtable dispatch, base declaration, and six sibling leaves prove a virtual member with hidden `this`. | Source ABI is `void __thiscall ... (ClanExpelNameInputDialog *this, const wchar_t *text)` in IDA and normal member syntax in C++. |
| Return type | Decompiled body produces no return value; base dispatch consumes no result; accepted sibling declarations are void. | `void`, not historical `int`. |
| Writer order | `PacketBufferWriteUInt8` is currently typed `void __cdecl(unsigned char value, unsigned char *destination)` and writes destination byte plus spare zero; target pushes destination then value. | Source calls are value-first. Destination-first is rejected. |
| Packet layout | Four writes/copy establish `0x4b`, `7`, `1`, byte length, then name bytes. | `{0x4b,0x07,0x01,length,name...}`. |
| Text conversion | Exact `WideCharToMultiByte(0,0,text,wcslen(text),...,256,0,0)`. | CP_ACP, no flags, explicit source length excluding terminator, no default-char reporting. |
| First guard | Unsigned `cmp convertedLength,0x100` / `jnb` occurs before writing conversion terminator. | `convertedLength < 256` is mandatory. |
| First guard source shape | The branch targets compiler runtime range-failure support immediately around the indexed conversion-buffer terminator write. | Preserve `convertedName[convertedLength] = 0`; do not expose the compiler helper as developer-authored C++. Matching compiler instrumentation must recreate the check. |
| Copy and second guard | Conversion terminator, length write, and payload copy occur before `packetLength=convertedLength+4` is checked against `0x80`. | Preserve copy-before-second-guard order; do not prevalidate or reorder. |
| Second guard source shape | The second branch protects the later indexed packet scratch-NUL write after the copy. | Preserve `packet[packetLength] = 0`; matching compiler instrumentation must recreate the check after `memmove`, with no explicit runtime-helper call in source. |
| Buffer lifetime | `convertedName[256]` and the contiguous 128-byte packet are stack-owned. The caller writes a local scratch NUL after counted bytes. | No ownership transfer; queue helper copies counted bytes to Socket-owned storage. |
| Send result | `Socket::QueueAndSendPacket` returns void, appends its own copied-buffer NUL, and dispatches the copy. | Call as a statement; no return expression or success branch. |
| Protocol meaning | Outgoing row 8 sends `{0x4b,7,0}`; incoming opcode `0x43`, subtype 7 opens the expel dialog for action/result 0 and accepts action/result 1. | Target is the matching action-1 expel-name submit. |
| Sibling comparison | UID0002NY/0002O0/0002O2 share the same `0xee` conversion/send shape but use subtypes 8/9/10; UID0002NU is a distinct `0x82` `_wtol`/UInt32BE money path. | Family evidence corroborates structure without substituting for target proof. |
| Source placement | Owner chain and generated route are [UID:00002D] -> [UID:0000I8] -> `Clan.cpp`; `ClanDialogs.cpp` remains only a broader coordinated split hypothesis. | Keep current route; reject target-only move. |
| Score blockers | Exact range/hash, ABI, packet API, protocol, guards, source owner, formal CPP, and support drift were all investigated. | Raise to `94/94`; only lexical/source-file historical uncertainty remains. |

The dated `2026-08-10` Gate 2B prestate snapshot does not change the return-type conclusion: it observed a stale inferred `int` return and therefore establishes A09 as an intentional correction whenever a fresh supervisor prestate readback matches. The no-return body, base caller, sibling leaves, vtable relationship, and source declarations remain the independent evidence for final `void`.

## Evidence Standards Used

- Highest-weight evidence: current IDA function/item state, live decompilation/disassembly, exact bytes, stack frame, xrefs, vtable bytes, comments, type catalog, and helper bodies/prototypes.
- Corroborating evidence: current by-memory/by-class/by-file pages, manual coverage rows, generated Clan CPP/H, research tracker, and matching historical reports used only as leads.
- Negative evidence: zero ordinary code callers, no local class type, blank entry/vtable comments, no function at the successor raw constructor start, and no target-owned persistent field access.
- Inference is accepted only where multiple independent facts converge: member ABI and source name come from vtable/base/sibling context; local names come from exact use; source placement comes from owner/emitter/generated routing.
- The binary fully closes runtime behavior. Missing original symbols affect lexical confidence only and do not justify decompiler-shaped final source.

## Evidence Checked

- Report-time live MCP checks: `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xref_query`, `stack_frame`, `inspect_items`, `get_comments`, `get_bytes`, `type_query`, and the then-current `tools/list` schemas.
- Exact target: modeled `[0x00489180,0x0048926e)`, 238 bytes, body SHA256 `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE`, first 16 bytes `55 8B EC 81 EC 84 01 00 00 A1 24 2F 67 00 33 C5`, last 16 bytes `E8 CC E4 13 00 8B E5 5D C2 04 00 E8 E7 E3 13 00`.
- Dated Gate 2B prestate snapshot, `2026-08-10`: runtime attestation passed for database `supervisor-b009-uid00028d-rollback-verify-20260810` at canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `inspect_items(0x00489180)` returned name `sub_489180`, literal type `int __stdcall(LPCWCH lpWideCharStr)`, and a code item at head `0x489180`. That attempt stopped before backup, mutation, or save. The exact database identity is historical snapshot evidence; a future Gate 2B attempt must establish its own current authority.
- Failed-closed Gate 2B history dated `2026-08-10`: A09 accepted the exact final function prototype, but physical F10 read back as `text@+0x194`, size 4, type `LPCWCH`; the supervisor stopped before A10/A11/save. Retirement plus fresh canonical readback proved no unsaved residue and restored the complete initial prestate. The observed typedef rendering is the operative expected physical-frame poststate for this report, subject to fresh supervisor prestate/readback verification.
- Boundary: `0x0048926e-0x00489270` is two-byte data item `cc cc`; `0x00489270` is code but not a modeled function; next modeled sibling is `0x004892b0`, size `0xee`.
- Vtable: window at `0x00615b2c` is `E0 F2 49 00 00 FC 49 00 80 91 48 00 6C 4E 64 00 7B C2 48 00`; slot `0x00615b34` holds `0x00489180`.
- Helpers: `GetMemoryMan 0x00516030`, `PacketBufferWriteUInt8 0x00575380`, `WideCharToMultiByte`, `MemoryMan_MemmoveWrapper 0x00516220`, `Socket_QueueAndSendPacket 0x00574bb0`, range-check failure, and security-cookie support.
- Protocol routes: live `ClanStatusPane::SendClanStatusRowActionPacket` row 8 request and live `ClanStatusPacketDispatcher` opcode `0x43`, subtype 7 action/result branches.
- Docs: target; ClanExpel/ClanName class pages; ClanNameDialogSubmitters aggregate; ClanStatus row/dispatcher pages; PacketBuffer, memmove, queue/send, packet sender pages; `by-file/Clan.md`; manual class/memory coverage; generated Clan CPP/H; research tracker.
- Matching reports searched by `0002NW`, `0x00489180`, `ClanExpelNameInputDialog`, `PacketBufferWriteUInt8`, and the clan submitter/raw-constructor family. The exhaustive older-B001 result set was exactly the broad-family artifact SHA `2EA63F0B...CECB`, the expel raw-constructor artifact SHA `75D5F236...A389D`, and the UID0002NX/UID0002O1 source-placement artifact SHA `61220425...FF182`; every relevant claim is individually reconciled in Section 2 rather than copied as authority.
- Compiler/source-shape check: the target's two unsigned branches and shared range-failure callee were compared with the exact indexed conversion-buffer and packet-buffer writes. The developer-source recommendation retains those indexed writes and ordering while leaving runtime helper emission to matching compiler/build instrumentation.
- During the original report-only research phase, no required bounded MCP query failed and B006 attempted neither IDA mutation nor validator execution. The later documentation callback's scoped validator receipts are recorded separately under `Validator Results`.

## Claim And Incorporation Ledger

Canonical parity contract: Section 33 mirrors all 74 rows below in identical order and with identical Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, and Verification state fields. The callback allocation is 51 checked B006 rows and 23 unchecked supervisor rows. `0002NW` is the sole declared target UID; support UIDs and paths are destinations, not additional covered targets.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2NW-001 | 0002NW | B006 records the exact modeled range `[0x00489180,0x0048926e)` and size `0xee`. | very high | Live function/item range. | Target by-memory / range and status | incorporate | applied |
| C2NW-002 | 0002NW | B006 records body SHA256 `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE` and exact first/last 16-byte receipts. | very high | Live bounded bytes and independent hash. | Target by-memory / body identity | incorporate | applied |
| C2NW-003 | 0002NW | B006 records `cc cc` at `[0x0048926e,0x00489270)` as alignment outside the target. | very high | Live bytes and item heads. | Target by-memory / boundary | incorporate | applied |
| C2NW-004 | 0002NW | B006 records the sole inbound data xref `0x00615b34 -> 0x00489180`. | very high | Live xref query and vtable bytes. | Target by-memory / virtual route | incorporate | applied |
| C2NW-005 | 0002NW | B006 records zero ordinary code callers without treating the virtual-only function as dead. | very high | Live callers and xref queries. | Target by-memory / reachability | incorporate | applied |
| C2NW-006 | 0002NW | B006 replaces current IDA `int __stdcall` framing with evidence-backed source member `void OnSubmitText(const wchar_t *text)` and explains the stale inferred return plus unused ECX. | high | No-return body, vtable, base declaration, sibling leaves, and `retn 4`. | Target by-memory / callback ABI | incorporate | applied |
| C2NW-007 | 0002NW | B006 records packet opcode `0x4b` at offset 0. | very high | Live write call and helper contract. | Target by-memory / packet opcode | incorporate | applied |
| C2NW-008 | 0002NW | B006 records expel subtype `0x07` at offset 1. | very high | Live write call and protocol routes. | Target by-memory / packet subtype | incorporate | applied |
| C2NW-009 | 0002NW | B006 records submit action `0x01` at offset 2. | very high | Live write call and protocol routes. | Target by-memory / packet action | incorporate | applied |
| C2NW-010 | 0002NW | B006 records the one-byte converted-name length at offset 3. | very high | Live fourth writer call. | Target by-memory / packet length byte | incorporate | applied |
| C2NW-011 | 0002NW | B006 records converted name bytes beginning at packet offset 4. | very high | Live memmove arguments. | Target by-memory / packet payload | incorporate | applied |
| C2NW-012 | 0002NW | B006 records exact CP_ACP conversion arguments, explicit `wcslen`, 256-byte destination, and null default-character pointers. | very high | Live WinAPI call. | Target by-memory / conversion semantics | incorporate | applied |
| C2NW-013 | 0002NW | B006 records the observed unsigned `0x100` branch as compiler range instrumentation for the indexed conversion-buffer terminator write. | very high | Live disassembly and shared runtime callee. | Target by-memory / first compiler guard evidence | incorporate | applied |
| C2NW-014 | 0002NW | B006 preserves developer-source write `convertedName[convertedLength] = 0` and excludes an explicit compiler-runtime call from formal C++. | high | Indexed source shape explains the observed first guard. | Target formal CPP / conversion terminator | incorporate | applied |
| C2NW-015 | 0002NW | B006 records the packet length-byte write before payload copy. | very high | Live instruction/call order. | Target by-memory / length write order | incorporate | applied |
| C2NW-016 | 0002NW | B006 records payload `memmove` before the second range branch. | very high | Live instruction/call order. | Target by-memory / copy order | incorporate | applied |
| C2NW-017 | 0002NW | B006 records the observed unsigned `0x80` branch as compiler range instrumentation for the later indexed packet scratch-NUL write. | very high | Live disassembly and shared runtime callee. | Target by-memory / second compiler guard evidence | incorporate | applied |
| C2NW-018 | 0002NW | B006 preserves developer-source write `packet[packetLength] = 0` after `memmove` and excludes an explicit compiler-runtime call from formal C++. | high | Indexed source shape explains the observed second guard. | Target formal CPP / packet terminator | incorporate | applied |
| C2NW-019 | 0002NW | B006 records exact counted send length `convertedLength + 4`. | very high | Live sender arguments. | Target by-memory / send length | incorporate | applied |
| C2NW-020 | 0002NW | B006 records conversion and packet source buffers as stack-owned. | very high | Complete current frame and accesses. | Target by-memory / caller buffer ownership | incorporate | applied |
| C2NW-021 | 0002NW | B006 records that Socket allocates and owns a copied queued buffer and adds its own NUL. | very high | Live queue helper body. | Target by-memory / queued buffer ownership | incorporate | applied |
| C2NW-022 | 0002NW | B006 records queue/send as void with no meaningful returned status. | very high | Live helper type/body and callsite. | Target by-memory / sender return semantics | incorporate | applied |
| C2NW-023 | 0002NW | B006 records row 8 outgoing request `{0x4b,7,0}`. | very high | Live row-action dispatcher. | Target by-memory / outgoing request route | incorporate | applied |
| C2NW-024 | 0002NW | B006 records incoming opcode `0x43`, subtype 7, action/result 0 as dialog open. | very high | Live clan-status packet dispatcher. | Target by-memory / incoming open route | incorporate | applied |
| C2NW-025 | 0002NW | B006 records incoming opcode `0x43`, subtype 7, action/result 1 as accepted path. | very high | Live clan-status packet dispatcher. | Target by-memory / incoming accept route | incorporate | applied |
| C2NW-026 | 0002NW | B006 records same-shape siblings at subtypes 8, 9, and 10 without substituting family evidence for target proof. | high | Live sibling bodies. | Target by-memory / sibling comparison | incorporate | applied |
| C2NW-027 | 0002NW | B006 records UID0002NU money conversion and UInt32BE path as not applicable to this name submitter. | very high | Live UID0002NU target comparison. | Target by-memory / rejected money-path carryover | not-applicable | excluded-with-reason |
| C2NW-028 | 0002NW | B006 documents one 256-byte conversion array and one contiguous 128-byte packet source array while preserving literal IDA frame fragments. | high | Frame layout and contiguous offset accesses. | Target by-memory / source-array shape | incorporate | applied |
| C2NW-029 | 0002NW | B006 keeps canonical owner UID00002D. | very high | Sole class-vtable route. | Target metadata / canonical owner | already-present | already-present |
| C2NW-030 | 0002NW | B006 keeps emitter UID00002D. | very high | Class owns declaration and child method route. | Target metadata / emitter | already-present | already-present |
| C2NW-031 | 0002NW | B006 keeps reconstructable true. | very high | Complete modeled source-bearing method. | Target metadata / reconstructable | already-present | already-present |
| C2NW-032 | 0002NW | B006 keeps route UID00002D -> UID0000I8 -> `social/Clan.cpp` and rejects a target-only move. | high | Current owner graph and family coupling. | Target by-memory / source placement | already-present | already-present |
| C2NW-033 | 0002NW | B006 replaces formal CPP with exact Section 22 void/value-first developer-source body without explicit compiler-runtime guard calls. | high | Closed behavior plus compiler/source-shape analysis. | Target formal RECONSTRUCTION_CPP CODE | incorporate | applied |
| C2NW-034 | 0002NW | B006 leaves formal H blank because UID00002D owns the declaration. | very high | Emitter layering and existing class H. | Target formal RECONSTRUCTION_H CODE | not-applicable | excluded-with-reason |
| C2NW-035 | 0002NW | B006 raises target metadata from `86/91` to `94/94` and leaves all routing fields unchanged. | high | Resolved behavior, ABI, protocol, source, and handoff blockers. | Target metadata / scores | incorporate | applied |
| C2NW-036 | 0002NW | B006 preserves old target no-code wording only as a contradicted historical assumption. | very high | Current modeled function and formal source eligibility. | Target by-memory / history | historicalize | applied |
| C2NW-037 | 0002NW | B006 preserves the old returned-sender-result wording only as a contradicted historical assumption. | very high | Live queue helper returns void. | Target by-memory / history | historicalize | applied |
| C2NW-038 | 0002NW | B006 rejects stale destination-first PacketBuffer syntax in favor of value-first calls. | very high | Live prototype/body and cdecl push order. | Target by-memory / API correction | reject-stale | excluded-with-reason |
| C2NW-039 | 0002NW | B006 incorporates the broad B001 artifact's accepted family facts and records every corrected, superseded, or not-applicable claim from Section 2. | high | Artifact SHA `2EA63F0B...CECB` plus independent live revalidation. | Target by-memory / historical B001 reconciliation | incorporate | applied |
| C2NW-040 | 0002NW | B006 incorporates the raw-constructor B001 artifact only as separate sibling/class evidence and records every superseded or not-applicable claim from Section 2. | high | Artifact SHA `75D5F236...A389D` plus independent live revalidation. | Target by-memory / historical B001 reconciliation | incorporate | applied |
| C2NW-041 | 0002NW | B006 incorporates the UID0002NX/UID0002O1 B001 artifact only as successor/family source-placement evidence and records every accepted or not-applicable claim from Section 2. | high | Artifact SHA `6122042519D53F8DF3687C931E3293B3C575E6F2C3E14B31DAFF855B748FF182` plus independent live revalidation. | Target by-memory / historical B001 reconciliation | incorporate | applied |
| C2NW-042 | 0002NW | B006 adds target-specific hash, value-first API, compiler-guard ordering, queue ownership, and protocol facts while retaining class `86/90`. | high | Dedicated target evidence; raw-constructor cap is separate. | by-class/ClanExpelNameInputDialog.md / target method | incorporate | applied |
| C2NW-043 | 0002NW | B006 adds a UID0002NW-specific evidence row without changing the aggregate's non-emitting state. | high | Aggregate currently carries only broad family detail. | by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md / UID0002NW | incorporate | applied |
| C2NW-044 | 0002NW | B006 adds the exact UID0002NW source method, protocol, compiler-guard, and owner facts while retaining Clan route. | high | Current by-file text is broader than this pass. | by-file/Clan.md / UID0002NW source note | incorporate | applied |
| C2NW-045 | 0002NW | B006 verifies the value-first byte-writer contract already exists at same-or-greater detail and does not duplicate target narrative. | very high | Current helper documentation. | by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md | already-present | already-present |
| C2NW-046 | 0002NW | B006 verifies the memmove wrapper contract already exists at same-or-greater detail and does not duplicate target narrative. | very high | Current helper documentation. | by-memory/0x00516220-0x00516238.MemmoveWrapper.md | already-present | already-present |
| C2NW-047 | 0002NW | B006 verifies void queue/copy ownership already exists at same-or-greater detail and does not duplicate target narrative. | very high | Current helper documentation. | by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md | already-present | already-present |
| C2NW-048 | 0002NW | Supervisor replaces the exact manual by-memory coverage row with Section 28's 94% text. | high | Current manual row is stale at 82%. | by-memory/-coverage-report.md / UID0002NW row | incorporate | proposed |
| C2NW-049 | 0002NW | Supervisor replaces the exact manual by-class coverage row with Section 28's 86% text. | high | Current manual row is stale at 84%. | by-class/-coverage-report.md / UID00002D row | incorporate | proposed |
| C2NW-050 | 0002NW | Supervisor refreshes and rereads the research tracker and generated coverage after accepted documentation changes. | high | Generated state currently reflects old metadata. | auto-generated reports / UID0002NW readback | incorporate | proposed |
| C2NW-051 | 0002NW | Supervisor rereads generated Clan CPP and H and verifies exact body/declaration routing after refresh. | high | Generated source is validator-owned. | auto-generated/NexusTK/social/Clan.cpp and Clan.h | incorporate | proposed |
| C2NW-052 | 0002NW | Supervisor Gate 2B declares only incomplete `struct ClanExpelNameInputDialog;` if fresh A00 prestate remains absent. | high | Current type query returns zero matches. | IDA A00 / local type catalog | incorporate | proposed |
| C2NW-053 | 0002NW | Supervisor Gate 2B pure-renames `sub_489180` to `ClanExpelNameInputDialog__OnSubmitText` only under A01 prestate. | high | Vtable, base, source, and protocol identity. | IDA A01 / function 0x00489180 | incorporate | proposed |
| C2NW-054 | 0002NW | Supervisor Gate 2B renames stack argument `lpWideCharStr` to `text` only under A02 prestate. | high | Exact argument use and source convention. | IDA A02 / stack argument +0x194 | incorporate | proposed |
| C2NW-055 | 0002NW | Supervisor Gate 2B renames `MultiByteStr` to `convertedName` only under A03 prestate. | high | Exact conversion destination role. | IDA A03 / stack local +0x8 | incorporate | proposed |
| C2NW-056 | 0002NW | Supervisor Gate 2B renames `Src` to `packetOpcode` only under A04 prestate. | high | Exact packet offset 0 role. | IDA A04 / stack local +0x108 | incorporate | proposed |
| C2NW-057 | 0002NW | Supervisor Gate 2B renames `destination` to `packetSubtype` only under A05 prestate. | high | Exact packet offset 1 role. | IDA A05 / stack local +0x109 | incorporate | proposed |
| C2NW-058 | 0002NW | Supervisor Gate 2B renames `var_82` to `packetAction` only under A06 prestate. | high | Exact packet offset 2 role. | IDA A06 / stack local +0x10a | incorporate | proposed |
| C2NW-059 | 0002NW | Supervisor Gate 2B renames `var_81` to `packetNameLength` only under A07 prestate. | high | Exact packet offset 3 role. | IDA A07 / stack local +0x10b | incorporate | proposed |
| C2NW-060 | 0002NW | Supervisor Gate 2B renames `var_80` to `packetNameBytes` without reshaping only under A08 prestate. | high | Exact payload role. | IDA A08 / stack local +0x10c | incorporate | proposed |
| C2NW-061 | 0002NW | Supervisor Gate 2B intentionally corrects literal current `int __stdcall(LPCWCH lpWideCharStr)` to the exact evidence-backed void-thiscall prototype only under A09 function/frame prestate, while preserving physical F10 as `text@+0x194`, size 4, type `LPCWCH`; that typedef rendering is equivalent to prototype `const wchar_t *text`. | high | No-return body, virtual route, base/sibling ABI, stack cleanup, complete frame, and failed-closed A09 readback. | IDA A09 / function type 0x00489180 | incorporate | proposed |
| C2NW-062 | 0002NW | Supervisor Gate 2B sets only the function-regular comment under A10 prestate. | high | Closed behavior and protocol. | IDA A10 / function comment 0x00489180 | incorporate | proposed |
| C2NW-063 | 0002NW | Supervisor Gate 2B sets only the regular vtable-slot comment under A11 prestate. | high | Sole virtual route. | IDA A11 / address comment 0x00615b34 | incorporate | proposed |
| C2NW-064 | 0002NW | Supervisor Gate 2B preserves exact target range, 238-byte body, and body SHA under P01. | very high | Literal current bytes and item range. | IDA P01 / target body and range | already-present | proposed |
| C2NW-065 | 0002NW | Supervisor Gate 2B preserves exact sole data xref `0x00615b34 -> 0x00489180` under P02. | very high | Literal current xref set. | IDA P02 / target xref | already-present | proposed |
| C2NW-066 | 0002NW | Supervisor Gate 2B preserves zero ordinary callers under P03. | very high | Literal current caller set. | IDA P03 / target callers | already-present | proposed |
| C2NW-067 | 0002NW | Supervisor Gate 2B preserves every physical frame offset, width, and type under P04; only A02-A08 physical names change, A09 changes only the function prototype, and F10 remains `text@+0x194`, size 4, type `LPCWCH`. | very high | Complete pre/post frame table and failed-closed physical-frame readback. | IDA P04 / function frame | already-present | proposed |
| C2NW-068 | 0002NW | Supervisor Gate 2B preserves exact vtable bytes and pointer value under P05. | very high | Literal current vtable window. | IDA P05 / vtable slot 0x00615b34 | already-present | proposed |
| C2NW-069 | 0002NW | Supervisor Gate 2B preserves exact `cc cc` alignment item under P06. | very high | Literal current bytes/item model. | IDA P06 / alignment 0x0048926e-0x00489270 | already-present | proposed |
| C2NW-070 | 0002NW | Supervisor Gate 2B preserves the raw successor item head and next modeled sibling start under P07. | very high | Literal current item/function model. | IDA P07 / successor 0x00489270 | already-present | proposed |
| C2NW-071 | 0002NW | B006 runs scoped target validation after callback and records command metadata and stable hash. | high | Required callback verification. | Target by-memory / scoped validator | incorporate | applied |
| C2NW-072 | 0002NW | B006 runs scoped validation for the class page if edited and records command metadata and stable hash. | high | Required callback verification. | by-class/ClanExpelNameInputDialog.md / scoped validator | incorporate | applied |
| C2NW-073 | 0002NW | B006 runs scoped validation for the aggregate page if edited and records command metadata and stable hash. | high | Required callback verification. | by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md / scoped validator | incorporate | applied |
| C2NW-074 | 0002NW | B006 runs scoped validation for the Clan by-file page if edited and records command metadata and stable hash. | high | Required callback verification. | by-file/Clan.md / scoped validator | incorporate | applied |

## Positive Evidence Summary

- The target is a complete modeled 238-byte function with a stable exact hash and bounded alignment.
- Its only inbound route is the `ClanExpelNameInputDialog` primary-vtable submit slot; no ordinary caller competes with that interpretation.
- Base dispatch and all six leaf bodies establish a void wide-text virtual callback. The dated `2026-08-10` canonical prestate snapshot showed IDA inferring `int __stdcall`; the unused ECX explains the lowered calling convention, while the no-return body and caller/sibling evidence require an intentional Gate 2B correction to source-member `void` when fresh prestate matches.
- Every packet byte and side effect is visible: opcode `0x4b`, subtype 7, action 1, one-byte converted length, payload, local scratch NUL, and counted queue length.
- The conversion and both unsigned guards are exact, including the non-obvious fact that the payload copy precedes the second guard.
- The helper bodies independently prove value-first PacketBuffer calls and a void Socket-owned queue/copy handoff.
- Outgoing action 0 and incoming subtype 7 branches establish the request/open/submit/accept protocol state machine.
- Current owner/emitter/generated routing already converges on `ClanExpelNameInputDialog` in `social/Clan.cpp`.

## IDA MCP Facts

- Function: `sub_489180`, `[0x00489180,0x0048926e)`, size `0xee`, six basic blocks, cyclomatic complexity 3.
- Current item type: `int __stdcall(LPCWCH lpWideCharStr)`; no `ClanExpelNameInputDialog` local type currently exists. The former void-current observation is superseded, while the proposed final void member ABI remains evidence-backed.
- Xrefs/callers: exactly one inbound data xref from `0x00615b34`; zero ordinary callers.
- Callees: `GetMemoryMan`, `PacketBufferWriteUInt8`, `WideCharToMultiByte`, `MemoryMan_MemmoveWrapper`, `Socket_QueueAndSendPacket`, `___report_rangecheckfailure`, and security-cookie support.
- Current frame: `MultiByteStr@+0x8 CHAR[256]`; `Src@+0x108 _BYTE`; `destination@+0x109 unsigned __int8`; `var_82@+0x10a unsigned __int8`; `var_81@+0x10b unsigned __int8`; `var_80@+0x10c _BYTE[124]`; `var_4@+0x188 _DWORD`; saved registers `+0x18c`; return address `+0x190`; `lpWideCharStr@+0x194 LPCWCH`.
- Failed-closed A09 readback proved that IDA preserves the physical F10 typedef spelling as `LPCWCH` after accepting the final function prototype with `const wchar_t *text`. These are equivalent type renderings at different IDA presentation layers; the final handoff requires the exact prototype spelling and the exact physical-frame typedef spelling simultaneously.
- Entry comments: address regular blank, address repeatable blank, function regular blank, function repeatable blank. Vtable-slot regular/repeatable comments are blank.
- Internal comments: 24 existing regular comments covering cdecl writer arguments, WinAPI arguments, memmove arguments, sender arguments, receiver, and stack cookie; these are protected.
- Boundary items: `0x0048926e` is a two-byte data item; `0x00489270` is code but not a function; next modeled function is sibling `0x004892b0` size `0xee`.
- `auto_analysis_ready:false` coexisted with successful bounded function, xref, decompile, byte, frame, item, comment, and type queries; it is not treated as an MCP outage.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00489180-0x0048926e` | UID0002NW target | Complete expel-name submit override | true | UID00002D | current callback-applied `94/94` | Source-bearing; exact CPP applied and physically verified. |
| `0x0048926e-0x00489270` | UID0000VN ignored alignment | Two `0xcc` bytes | false | none | N/A | Outside target; preserve as alignment. |
| `0x00489270-0x004892a5` | UID0002NX raw constructor sibling | Summon-dialog retained constructor-shaped body | true evidence / separate disposition | UID00002M | separate target | Excluded from UID0002NW; not a child or gap. |
| `0x00615b34` | UID0001X9 vtable support | Primary virtual submit slot pointer | data support | UID00002D | support | Sole target route; no source body here. |
| `ClanExpelNameInputDialog` declaration | UID00002D class page | Owns constructor and virtual declaration | true | UID0000I8 | `86/90` | Already emits H declaration and `[[CHILDREN]]`. |

- Inventory total for this by-memory target: one source-bearing function, one immediate two-byte alignment item, one external successor sibling, one vtable data anchor, and one class declaration owner. No target-owned global, persistent field, table, string, resource, thunk, EH child, or additional source body was found.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00615b34 -> 0x00489180` | one inbound data xref | Exact virtual dispatch ownership. |
| ordinary code callers | zero | Expected for vtable-only callback; not dead-code evidence. |
| `0x0048919d -> 0x00516030` | `GetMemoryMan` | Supplies receiver for memmove wrapper. |
| `0x004891a8/1b6/1c4/214 -> 0x00575380` | four byte-writer calls | Writes opcode, subtype, action, and payload length. |
| `0x004891fc -> WideCharToMultiByte` | CP_ACP conversion | Produces counted multibyte name. |
| `0x0048922b -> 0x00516220` | memmove wrapper | Copies converted bytes to packet offset 4. |
| `0x00489252 -> 0x00574bb0` | queue/send | Copies and queues exactly `convertedLength+4` bytes. |
| `0x00489269 -> 0x005c7655` | range failure | Shared tail for both unsigned guards. |
| `0x00615b34` incoming refs | none required | Vtable slot is the pointer source, not a function caller. |

## Documentation Evidence And IDA Status

- Supporting current docs now identify class ownership, void callback shape, packet family, exact CP_ACP conversion, value-first API, compiler/source guard distinction, Socket copy ownership, protocol lifecycle, and Clan source route at report-level detail.
- Target documentation now replaces the former incomplete/stale current wording. The old `no-code rationale`, returned queue result, destination-first API, and explicit compiler-runtime source forms survive only as contradicted historical assumptions with reasons.
- The class row in manual `by-class/-coverage-report.md` is stale at `84%` while the class page is `86/90`; the target manual row is stale at `82%` and repeats no-code wording.
- Generated Clan CPP/H and generated reports remain pending supervisor refresh/readback; no generated-current claim is made from the callback.
- Current IDA remains unmutated. The raw name/type/comments and fragmented frame are recorded literally in Section 21 for Gate 2B.
- All three matching older B001 artifacts are now reconciled in the target history as accepted, corrected, superseded, rejected as current authority, or not applicable; none is treated as direct coverage authority.

## Ranked Ownership Analysis

### 1. ClanExpelNameInputDialog / Clan.cpp

- Evidence for: sole class-vtable slot, inherited submit dispatch, exact expel subtype, existing owner/emitter graph, class declaration, adjacent clan-dialog family, and current generated source placement.
- Evidence against: no recovered original symbol and the wider project still considers a coordinated `ClanDialogs.cpp` split.
- Decision: direct semantic and emitter owner UID00002D; active source module UID0000I8 `Clan.cpp`. The contrary evidence affects historical filename confidence only.

### 2. ClanDialogs.cpp coordinated future split

- Evidence for: the dialog family is cohesive enough that a dedicated historic compilation unit is plausible.
- Evidence against: no target-specific binary boundary, symbol, object-file evidence, or completed coordinated emitter move proves it; current validated graph routes all related source through Clan.
- Decision: preserve as a future project-wide hypothesis, not an active target route.

### 3. File-local helper / PacketBuffer / Socket / no owner

- Evidence for: the function does not dereference ECX and uses generic packet helpers.
- Evidence against: the vtable directly points to it; helper dependencies are generic callees; base virtual dispatch supplies the text argument; subtype 7 is class-specific business behavior.
- Decision: rejected. Unused ECX is optimization, not evidence against a virtual member.

### Proposed new file/grouping, if applicable

- Not applicable. Do not create a one-method file or move only UID0002NW. Any future ClanDialogs split must be coordinated across the complete dialog family and emitter graph.

## Source Placement

- Recommended placement: definition in `social/Clan.cpp` through UID00002D/UID0000I8; declaration in the UID00002D formal H channel and generated `social/Clan.h`.
- The by-memory target supplies only the definition because duplicating the declaration would break emitter layering.
- Placement fits the contiguous clan-dialog implementation neighborhood, opcode `0x4b` feature family, inbound clan-status dispatcher, and existing owner graph.
- Rejected: PacketBuffer.cpp and Socket.cpp own generic helpers, not expel behavior; ClanDialogs.cpp is not independently proven; a free helper loses the virtual relationship; no-owner loses reconstructable class behavior.
- Remaining uncertainty: exact original translation-unit filename. It does not block current coherent source placement or the reconstructed method.

## Range / Split / Padding / Reclassification Analysis

- Exact target is `[0x00489180,0x0048926e)`, one modeled function, no internal padding or mixed data.
- Body SHA256 is `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE`.
- `[0x0048926e,0x00489270)` is exactly `cc cc` alignment and must remain outside the target.
- `0x00489270` begins separate raw constructor-shaped UID0002NX; the next modeled submitter begins `0x004892b0`.
- No split, merge, child creation, reclassification, or range expansion is recommended.
- The family aggregate UID00010K remains a non-emitting evidence/index page and must not duplicate this method body.

## Negative Evidence Summary

- No ordinary caller was found; this supports virtual-only dispatch and does not support dead-code/no-owner classification.
- No `ClanExpelNameInputDialog` type exists in the current local type catalog; the supervisor must declare only an incomplete forward type, not invent a layout.
- No entry or vtable comments currently supply source identity.
- No target-owned persistent field access exists; do not invent class members.
- No evidence supports destination-first PacketBuffer source syntax.
- No evidence supports a meaningful queue/send return value, success test, or ownership transfer.
- No evidence supports including conversion-buffer NUL, packet scratch NUL, or queue-copy NUL in the protocol length.
- No evidence supports reordering the memmove after the second guard; the binary copies first.
- No evidence supports a target-only ClanDialogs split, PacketBuffer/Socket ownership, or duplicate header declaration in the child.
- No hidden source-bearing bytes exist inside the two-byte successor alignment.

## IDA Rename / Type / Comment Recommendations

| Record | Declarative evidence / disposition |
| --- | --- |
| Archive | Exact removed runtime/session/request/backup/save/reopen/rollback material is preserved only in [0002NW-ClanExpelNameInputDialogSubmitName-source-quality-removed.md](./0002NW-ClanExpelNameInputDialogSubmitName-source-quality-removed.md); that companion is non-authoritative and must never be executed. |
| Scope | B006 supplied evidence only. The rows below are declarative entity prestates, human outcomes, protections, and expected readbacks; no endpoint request or transaction order is authoritative here. |

| ID | Actor | Exact entity/address | Literal current prestate | Exact action or no-change disposition | Evidence | Confidence | Atomic safety constraints | Expected direct readback |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| A00 | Supervisor Gate 2B | Local type catalog | `type_query('*ClanExpelNameInputDialog*')` returns zero rows; no UDT, typedef, or forward tag exists | Declare the incomplete `ClanExpelNameInputDialog` analysis struct/tag only if absent; no members or unrelated types change. | Vtable ownership and A09 require only an incomplete receiver type | high | Create one incomplete struct tag only; no size, members, inheritance, ordinal assumption, or layout | Exactly one incomplete `ClanExpelNameInputDialog` struct/tag with zero members |
| A01 | Supervisor Gate 2B | Function `0x00489180`, modeled `[0x00489180,0x0048926e)` | Name `sub_489180`; type `int __stdcall(LPCWCH lpWideCharStr)`; size `0xee`; code item head `0x489180`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; sole inbound data xref `0x00615b34 -> 0x00489180`; zero code callers | Rename function `0x00489180` to `ClanExpelNameInputDialog__OnSubmitText`. | Sole vtable slot, base declaration, sibling ABI, subtype-7 behavior, Clan route | high | No overwrite or collision; preserve current `int __stdcall` type until A09, frame, body, range, code head, all four comment channels, sole xref, and zero callers | New physical function name at the same range; old exact physical name absent; type remains `int __stdcall(LPCWCH lpWideCharStr)` until A09; every other literal prestate remains unchanged |
| A02 | Supervisor Gate 2B | Stack argument `0x00489180:+0x194` | Function `sub_489180`, range `0xee`, type `int __stdcall(LPCWCH lpWideCharStr)`; row `lpWideCharStr@+0x194`, width 4, type `LPCWCH` | Rename only `lpWideCharStr` to `text` through `rename.batch.stack` | Wide-text callback use and class declaration | high | Preserve offset, width, current `int __stdcall` function type until A09, and every other frame row | `text@+0x194`, width 4, type `LPCWCH`; function type remains `int __stdcall(LPCWCH text)` before A09 |
| A03 | Supervisor Gate 2B | Stack local `0x00489180:+0x8` | Function `sub_489180`, range `0xee`; row `MultiByteStr@+0x8`, width `0x100`, type `CHAR[256]` | Rename only to `convertedName` through `rename.batch.stack` | Exact CP_ACP destination role | high | Preserve offset, width, type, and all neighboring rows | `convertedName@+0x8`, width `0x100`, type `CHAR[256]` |
| A04 | Supervisor Gate 2B | Stack local `0x00489180:+0x108` | Function `sub_489180`, range `0xee`; row `Src@+0x108`, width 1, type `_BYTE` | Rename only to `packetOpcode` through `rename.batch.stack` | Exact packet offset-0 role | high | Preserve offset, width, type; do not coalesce packet fragments | `packetOpcode@+0x108`, width 1, type `_BYTE` |
| A05 | Supervisor Gate 2B | Stack local `0x00489180:+0x109` | Function `sub_489180`, range `0xee`; row `destination@+0x109`, width 1, type `unsigned __int8` | Rename only to `packetSubtype` through `rename.batch.stack` | Exact packet offset-1 role | high | Preserve offset, width, type; do not coalesce packet fragments | `packetSubtype@+0x109`, width 1, type `unsigned __int8` |
| A06 | Supervisor Gate 2B | Stack local `0x00489180:+0x10a` | Function `sub_489180`, range `0xee`; row `var_82@+0x10a`, width 1, type `unsigned __int8` | Rename only to `packetAction` through `rename.batch.stack` | Exact packet offset-2 role | high | Preserve offset, width, type; do not coalesce packet fragments | `packetAction@+0x10a`, width 1, type `unsigned __int8` |
| A07 | Supervisor Gate 2B | Stack local `0x00489180:+0x10b` | Function `sub_489180`, range `0xee`; row `var_81@+0x10b`, width 1, type `unsigned __int8` | Rename only to `packetNameLength` through `rename.batch.stack` | Exact packet offset-3 role | high | Preserve offset, width, type; do not coalesce packet fragments | `packetNameLength@+0x10b`, width 1, type `unsigned __int8` |
| A08 | Supervisor Gate 2B | Stack local `0x00489180:+0x10c` | Function `sub_489180`, range `0xee`; row `var_80@+0x10c`, width `0x7c`, type `_BYTE[124]` | Rename only to `packetNameBytes` through `rename.batch.stack` | Exact packet payload role | high | Preserve offset, width, type; do not manufacture or reshape a 128-byte physical array item | `packetNameBytes@+0x10c`, width `0x7c`, type `_BYTE[124]` |
| A09 | Supervisor Gate 2B | Function type `0x00489180` | Name `sub_489180` before A01; range `[0x00489180,0x0048926e)`; type `int __stdcall(LPCWCH lpWideCharStr)`; code item head `0x489180`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; frame: `MultiByteStr@+0x8` width `0x100` `CHAR[256]`, `Src@+0x108` width 1 `_BYTE`, `destination@+0x109` width 1 `unsigned __int8`, `var_82@+0x10a` width 1 `unsigned __int8`, `var_81@+0x10b` width 1 `unsigned __int8`, `var_80@+0x10c` width `0x7c` `_BYTE[124]`, `var_4@+0x188` width 4 `_DWORD`, `__saved_registers@+0x18c` width 4 `_DWORD`, `__return_address@+0x190` width 4 `_UNKNOWN *`, `lpWideCharStr@+0x194` width 4 `LPCWCH` | Set the exact function signature stated in this row and preserve all unlisted frame/body/comment state. | No-return body, base caller consumes no result, six sibling leaves are void, vtable ownership, source member ABI, return cleanup, complete frame, and failed-closed A09 readback | high | Preserve body/range/code head/xrefs/comments and all calling behavior; permit only the intentional `int`-to-`void` return correction, `__stdcall`-to-member-`__thiscall` type correction, A02's F10 name change, and hidden register `this`; preserve every physical frame offset/width/type and F01-F09 names after A03-A08 renames; do not add a stack-row `set_type` action | Exact type `void __thiscall ClanExpelNameInputDialog__OnSubmitText(ClanExpelNameInputDialog *this, const wchar_t *text)`; stale `int __stdcall` type absent; frame: `convertedName@+0x8` width `0x100` `CHAR[256]`, `packetOpcode@+0x108` width 1 `_BYTE`, `packetSubtype@+0x109` width 1 `unsigned __int8`, `packetAction@+0x10a` width 1 `unsigned __int8`, `packetNameLength@+0x10b` width 1 `unsigned __int8`, `packetNameBytes@+0x10c` width `0x7c` `_BYTE[124]`, `var_4@+0x188` width 4 `_DWORD`, `__saved_registers@+0x18c` width 4 `_DWORD`, `__return_address@+0x190` width 4 `_UNKNOWN *`, `text@+0x194` width 4 `LPCWCH`; the physical typedef rendering is equivalent to prototype `const wchar_t *text`; all four comment channels still absent |
| A10 | Supervisor Gate 2B | Function regular-comment channel `0x00489180` | Initial canonical prestate: name `sub_489180`, range `0xee`, type `int __stdcall(LPCWCH lpWideCharStr)`, code item head `0x489180`, address regular absent, address repeatable absent, function regular absent, function repeatable absent; after authorized A01/A02/A09, name/type are expected to be the exact final function name and void-thiscall signature | Set only the function-regular comment to `ClanExpelNameInputDialog::OnSubmitText converts the submitted name with CP_ACP, builds {0x4b,7,1,length,name...}, and queues convertedLength+4 bytes; the observed 0x100 and post-copy 0x80 failures are compiler range instrumentation around indexed terminator writes.` | Closed conversion, packet, compiler-instrumentation, and send behavior | high | Do not alter address channels, function-repeatable channel, body, frame, xrefs, code head, internal comments, or function type beyond the already-authorized A09 correction | Function regular equals exact text; final void-thiscall type remains unchanged from A09; other three entry channels remain absent |
| A11 | Supervisor Gate 2B | Vtable slot `0x00615b34` | Four-byte data item; physical name absent; physical type absent; value `0x00489180`; bytes `80 91 48 00`; address regular absent; address repeatable absent | Set only the address-regular comment to `ClanExpelNameInputDialog::OnSubmitText virtual slot -> 0x00489180.` | Sole virtual route to target | high | No rename/type/value/bytes/item-boundary/repeatable-comment change | Exact regular text; repeatable absent; pointer value/bytes and sole xref unchanged |
| P01 | Supervisor Gate 2B | Target body and function range `[0x00489180,0x0048926e)` | Range size 238; body SHA256 `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE`; first/last receipts in Section 10 | No change | Exact live bytes and modeled function | very high | Abort before save on any byte, head, tail, range, or hash mismatch | Exact same 238-byte range and SHA |
| P02 | Supervisor Gate 2B | Inbound xref set for `0x00489180` | Exactly one inbound data xref `0x00615b34 -> 0x00489180` | No change | Live xref query | very high | No added, removed, retyped, or moved xref | Exact same one-entry data-xref set |
| P03 | Supervisor Gate 2B | Ordinary caller set for `0x00489180` | Zero ordinary code callers | No change | Live callers query | very high | No new function/code caller | Zero ordinary code callers |
| P04 | Supervisor Gate 2B | Complete physical frame for `0x00489180` | Exact F01-F10 current rows below | Preserve all offsets, widths, and physical types; permit only A02-A08 literal physical-name deltas, while A09 changes only the function prototype | Live stack-frame readback and failed-closed A09 attempt | very high | Abort on row addition/removal, offset/width movement, local overlap, any physical type delta, or unlisted name delta; do not add a stack-row `set_type` action | Exact F01-F10 poststate rows below, including F10 `text@+0x194`, size 4, type `LPCWCH` |
| P05 | Supervisor Gate 2B | Vtable window `0x00615b2c-0x00615b40` | Bytes `E0 F2 49 00 00 FC 49 00 80 91 48 00 6C 4E 64 00 7B C2 48 00`; slot `0x00615b34` value `0x00489180` | No change except A11 regular comment channel | Live bytes/items | very high | Preserve all bytes, item heads, neighboring values, target value, name/type, and repeatable channel | Byte-identical window and same target value; only A11 regular comment differs |
| P06 | Supervisor Gate 2B | Alignment item `[0x0048926e,0x00489270)` | One two-byte data item with bytes `cc cc` | No change | Live bytes/items | very high | Do not absorb into function, create code/function, or alter bytes/type/head | Same two-byte data item and bytes |
| P07 | Supervisor Gate 2B | Successor item head `0x00489270` | Code item, not a modeled function; next modeled sibling starts `0x004892b0` | No change | Live item/function query | very high | Do not create a function, merge ranges, or move item heads | Same raw code item and same next modeled sibling |

| Frame row | Current name | Offset | Width | Current type | Expected poststate |
| --- | --- | --- | --- | --- | --- |
| F01 | `MultiByteStr` | `+0x8` | `0x100` | `CHAR[256]` | `convertedName`, same offset/width/type |
| F02 | `Src` | `+0x108` | 1 | `_BYTE` | `packetOpcode`, same offset/width/type |
| F03 | `destination` | `+0x109` | 1 | `unsigned __int8` | `packetSubtype`, same offset/width/type |
| F04 | `var_82` | `+0x10a` | 1 | `unsigned __int8` | `packetAction`, same offset/width/type |
| F05 | `var_81` | `+0x10b` | 1 | `unsigned __int8` | `packetNameLength`, same offset/width/type |
| F06 | `var_80` | `+0x10c` | `0x7c` | `_BYTE[124]` | `packetNameBytes`, same offset/width/type |
| F07 | `var_4` | `+0x188` | 4 | `_DWORD` | unchanged |
| F08 | `__saved_registers` | `+0x18c` | 4 | `_DWORD` | unchanged |
| F09 | `__return_address` | `+0x190` | 4 | `_UNKNOWN *` | unchanged |
| F10 | `lpWideCharStr` | `+0x194` | 4 | `LPCWCH` | `text`, same offset/width/type `LPCWCH`; this physical typedef rendering is equivalent to the final function prototype's `const wchar_t *text` |

| Protection ID | Declarative no-change boundary |
| --- | --- |
| P08 | Evidence-only dependencies are deliberately outside the mutation/protected-action ledger because no Gate 2B write targets them: calls to `GetMemoryMan 0x00516030`, `PacketBufferWriteUInt8 0x00575380`, `MemoryMan_MemmoveWrapper 0x00516220`, `Socket_QueueAndSendPacket 0x00574bb0`, WinAPI conversion, range runtime, security-cookie support, and the packet-sender global load. The 24 existing internal regular comments remain observational evidence rather than proposed comment actions; they occur at `0x4891a5`, `0x4891a6`, `0x4891b3`, `0x4891b4`, `0x4891c1`, `0x4891c2`, `0x4891dc`, `0x4891de`, `0x4891e0`, `0x4891ed`, `0x4891f0`, `0x4891f1`, `0x4891f2`, `0x4891f4`, `0x489214`, `0x489215`, `0x489224`, `0x489226`, `0x489227`, `0x48922b`, `0x48923c`, `0x489248`, `0x489249`, and `0x48925b`. Any collateral change outside A00-A11, including to these evidence-only entities, is an unexpected side effect and requires rejection of the proposed outcome; it is not an additional report action. |

## First-Draft C++ Recommendation

- Eligible for draft/finalizing C++: yes. The complete method is modeled, behaviorally closed, and correctly routed.
- Exact formal `RECONSTRUCTION_CPP CODE` replacement/insertion text:

```cpp
void ClanExpelNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x07, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

- Exact formal `RECONSTRUCTION_H CODE` disposition: leave blank. The declaration already belongs to UID00002D as `virtual void OnSubmitText(const wchar_t *text);`.
- Behavior fidelity: preserves the value-first writes, explicit-length CP_ACP conversion, indexed conversion terminator, length write, payload copy, indexed post-copy packet terminator, and exact counted queue length in the observed order. Under matching original MSVC build instrumentation, the two indexed writes regenerate the observed unsigned `0x100` and post-copy `0x80` range-failure branches.
- Source shape: normal mid-2000s C++ member code with descriptive local names and fixed stack arrays; no `sub_`, `var_`, address, or decompiler labels.
- `__report_rangecheckfailure` is compiler-inserted runtime instrumentation, not a plausible developer-authored call. It remains documented as binary evidence but is intentionally absent from formal reconstructed source.
- The direct source `memmove` call is the plausible developer-level form of the observed memory-manager wrapper route documented by the shared helper page.
- Naming style follows current accepted Clan/PacketBuffer/Socket source conventions. Behavioral fidelity and human source shape take precedence over speculative stylistic churn.

## Final Recommendation

- Target: callback-applied `94/94`, owner/emitter UID00002D, reconstructable true, same range, same source route, exact Section 22 developer-source CPP, and blank child H.
- Target prose: callback-applied exact function, packet, conversion, compiler-guard, indexed-write, buffer, queue, protocol, boundary, xref, ABI, historical-artifact reconciliation, and negative evidence; stale no-code/sender-result framing is historical only.
- Support: callback-applied full target-specific details to UID00002D, UID00010K, and UID0000I8 without duplicating source bodies or changing routes. Generic helper pages were reread at same-or-greater detail and required no edit.
- Manual coverage: supervisor replaces the exact UID0002NW and UID00002D rows in Section 28.
- IDA: supervisor applies only A00-A11 after each literal prestate check and preserves each atomic P01-P07 entity; evidence-only helpers/internal comments are not separate mutation actions.
- No target remains no-owner/non-emitting. No split, child, global, field, resource, or extra declaration is required.
- Future work outside scope: only a coordinated project-wide decision on a historic ClanDialogs translation unit and later lexical polish if original symbols emerge.

## Recommended Target Doc Changes

- Applied path: `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md`.
- Applied metadata: `86/91 -> 94/94`; every other metadata field remains unchanged.
- Applied formal channels: exact Section 22 CPP with indexed terminator writes and no explicit compiler-runtime range-failure calls; blank child H.
- Applied detail: class-owned source-emitting summary, body hash/range and byte receipts, vtable route, zero callers, packet/conversion/compiler-guard/copy/write/send behavior, full frame/source arrays, boundary, void queue ownership, protocol lifecycle, and Clan route.
- Applied history/open questions: all three B001 artifacts and every accepted/corrected/superseded/not-applicable disposition are retained; stale no-code, explicit-runtime-source, destination-first, and returned-send-result interpretations are historicalized. Only lexical/source-file historical uncertainty remains.

## Recommended Support Doc Changes

- `by-class/ClanExpelNameInputDialog.md` UID00002D: applied exact body hash/range, value-first proof, CP_ACP semantics, copy-before-second-guard order, indexed writes, local/queued NUL ownership, subtype-7 lifecycle, and void ABI; retained `86/90`, UID0000I8 route, declaration, and separate raw-constructor cap.
- `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md` UID00010K: applied a dedicated UID0002NW row/section with exact hash, guard thresholds/order, value-first writes, subtype-7 route, and Socket-owned copy; retained `85/89`, non-reconstructable/no-emitter aggregate state, and no duplicated body.
- `by-file/Clan.md` UID0000I8: applied the exact UID0002NW source note while preserving `90/85`, Clan ownership, broader inventory, and ClanDialogs only as a coordinated future split.
- `PacketBufferHelpers.md`, `MemmoveWrapper.md`, and `QueueAndSendPacket.md`: physically reread unchanged at same-or-greater generic detail; no duplicate target narrative was added.
- `by-class/ClanNameInputDialog.md`, sibling class/submitter pages, row-action dispatcher, and packet dispatcher: evidence-only for this target; no edit is required because their current relevant facts are already correct at same-or-greater detail.

## Score And Metadata Recommendation

- Historical pre-callback: `86/91`, owner/emitter UID00002D, reconstructable true.
- Current callback-applied: `94/94`, same owner/emitter/reconstructable/range/position.
- Completion increase is justified by resolving and documenting exact body identity/hash, member ABI, packet API order, complete conversion/copy/indexed-write/compiler-guard order, local/queued buffer semantics, exact protocol lifecycle, source placement, formal source, both older B001 artifact dispositions, support drift, and implementation-ready IDA handoff.
- Confidence increase is justified by current live target/helper/sibling/protocol evidence rather than family assumption.
- Reason not higher: original function/local spelling is inferred rather than symbol-proven, and the original translation-unit name remains uncertain between current Clan and a possible coordinated ClanDialogs split. These do not affect execution.
- Reason not lower: every runtime branch, byte, length, copy, side effect, caller route, dependency, boundary, and owner/emitter decision is directly observed or multiply corroborated.
- Score-improvement implementation: all resolved findings are now present in the target/support docs and passed four scoped validators. `__stdcall` is documented as unused-this member lowering; destination-first and sender-result assumptions are historicalized; packet source shape, protocol meaning, range/source owner, indexed-write/compiler instrumentation, and formal source are physically present. Only supervisor generated refresh/readback and IDA Gate 2B remain outside B006 authority.

## Open Questions With Attempted Resolution

- Original function/local names: no symbols were found. Current class, virtual, protocol, and use context make `ClanExpelNameInputDialog::OnSubmitText`, `text`, `convertedName`, and packet-role names the highest-probability human source choices. This caps lexical confidence only; raw labels are rejected.
- Calling convention: IDA's `__stdcall` display was tested against vtable/base/sibling evidence. The source is a virtual member; unused ECX explains the lowered presentation. Resolved.
- Function-prototype versus physical-frame spelling: the failed-closed A09 attempt proved that IDA accepts the exact final `const wchar_t *text` prototype while retaining the physical argument row as size-4 `LPCWCH`. `LPCWCH` is the equivalent typedef rendering, not a source or ABI conflict. Resolved; no extra stack-row `set_type` action is permitted.
- Packet writer order: live helper type/body and target pushes prove value-first. The assignment's destination-first phrase is rejected. Resolved.
- Packet layout/source array: fragmented frame items form one 128-byte packet span used by contiguous offsets. Formal source uses `packet[128]`; IDA handoff preserves fragments to avoid unsafe reshaping. Resolved.
- Range-check source shape: direct disassembly proves unsigned `0x100` and post-copy `0x80` failures around the two indexed terminator writes. The shared runtime helper is compiler-inserted, so formal source keeps `convertedName[convertedLength]` and `packet[packetLength]` but no explicit helper call. Resolved without losing binary order.
- Second guard ordering: direct disassembly shows memmove before the `0x80` test. Formal source preserves the copy before the indexed packet terminator, allowing matching compiler instrumentation to recreate the guard after the copy. Resolved.
- Buffer ownership: queue helper copies exact counted bytes and owns/frees the queued allocation. Caller stack buffers are not transferred. Resolved.
- Source module: active coherent route is Clan.cpp; no exact object/source symbol proves the historical filename. Best current direction is keep Clan, with coordinated split only if future project-wide evidence supports it. No implementation blocker.
- No remaining target-scoped behavior, owner, emitter, type, protocol, split, range, or formal-C++ blocker remains.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only comparison found two stale manual rows. B006 must not edit either coverage report.

- Replace the exact UID0002NW row in `by-memory/-coverage-report.md` with:

`        - [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) 0x00489180-0x0048926e | function | ClanExpelNameInputDialogSubmitName : reconstructable : 94% : very-strong : Live IDA proves the exact 0xee-byte body/hash, sole vtable xref and zero callers, void member ABI, value-first packet writes, CP_ACP conversion, exact compiler-instrumented 0x100 and post-copy 0x80 guard order around indexed terminator writes, packet bytes {0x4b,7,1,length,name...}, Socket-owned queued copy, protocol request/open/accept route, class ownership, Clan source placement, and exact human-written formal C++ without explicit compiler-runtime calls.`

- Replace the exact UID00002D row in `by-class/-coverage-report.md` with:

`- [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md) : reconstructable : 86% : very-strong : The class declaration, vtable identity, inherited layout, live inline construction sites, exact UID0002NW void submit override, value-first CP_ACP packet path, guard/copy/send behavior, and Clan ownership are source-ready; only the separate retained raw-constructor no-route caveat and historical source-file split uncertainty cap the class.`

- `auto-generated/-ag-research-tracker.md`, generated coverage, and generated Clan CPP/H are validator-owned. Do not hand-edit them; refresh/read back after accepted documentation changes.

## Follow-Up Actions

1. Supervisor performs Gate 2A claim-by-claim verification of C2NW-001 through C2NW-047 and validator receipts C2NW-071 through C2NW-074 against the stable callback artifacts.
2. Supervisor applies the exact manual rows C2NW-048/049 and refreshes/inspects generated tracker, coverage, and Clan CPP/H for C2NW-050/051.
3. C2NW-052 through C2NW-070 remain supervisor-owned declarative IDA outcomes and protected readbacks; no report text supplies mutation, persistence, recovery, or lifecycle authority.
4. If any literal IDA pre-state differs, stop the affected action; preserve the report evidence and return the exact mismatch instead of forcing a mutation.
5. Report execution/archive state remains supervisor-owned; B006 does not run or probe `execute_report`.

## Confidence

- Range/body/boundary: 99%.
- Vtable/class ownership and void member ABI: 97%.
- Packet bytes, conversion, copy/indexed-write/compiler-guard order, send length, and buffer ownership: 99%.
- Source owner/emitter and current Clan.cpp placement: 95%.
- Human source shape: 94%; explicit compiler-runtime helper calls are excluded while the source constructs that generated them remain.
- Original lexical spelling and historical translation-unit filename: below proof level, but resolved by highest-probability consistent names and current route rather than decompiler residue.
- Overall recommendation: current callback-applied `94/94`; ordinary implementation and scoped validation are complete. No target-scoped blocker remains; only supervisor manual/generated/IDA/lifecycle closure is pending.

## Validator Results

- All commands ran from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <relative-path> --apply --no-generated-refresh --queue-timeout 240`.
- C2NW-071 target: command `000000021790`, timestamp `2026-08-10T15:41:15-04:00`, exit `0`, `ok: 1`, generated refresh skipped; stable SHA256 `E3227E79C90CAD23805887352EC433263CFA644ED08F1C1B04836D2510E4AB59`.
- C2NW-072 class: command `000000021791`, timestamp `2026-08-10T15:41:29-04:00`, exit `0`, `ok: 1`, generated refresh skipped; stable SHA256 `2E37639C85A26E434570638B64180658D24C97F61975857FB88121657E2C176A`.
- C2NW-073 aggregate: command `000000021792`, timestamp `2026-08-10T15:41:44-04:00`, exit `0`, `ok: 1`, generated refresh skipped; stable SHA256 `3BDC96260DEE2B8BFF7D1110A6B5064BD5B8C347352ACBF19D2C87F37D27AA39`.
- C2NW-074 Clan file: command `000000021793`, timestamp `2026-08-10T15:41:58-04:00`, exit `0`, `ok: 1`, generated refresh skipped; stable SHA256 `3D6ACC16748F549086662E27A8F881E2DF78ED129F798637DF7F22D0BAE6A934`. The validator retained ten unrelated pre-existing missing references for UIDs `000411`, `000412`, and `0003B8`; none was introduced by UID0002NW.
- Validator-owned side effects were limited to normal registry/reference/projected-stats updates; callback-time receipts dated `2026-08-10` were `project-level/-auto-completion-stats.md` SHA256 `ECF4F9ABFAD49769CFDCE821AAD7D5E734F2C893AB8A0F5E5AF11E4C27B242A7` and `tools/validator.ini` SHA256 `3F08E54C08C93ED6ED3C5FFA139AFC4FBB588E53C94C595D135A670443C6C614`. These are historical command receipts rather than permanently current project-state identities; B006 did not edit either manually.
- No broad generated refresh, manual coverage edit, IDA mutation, lifecycle command, or `execute_report` call was performed. Report execution/archive state remains supervisor-owned and authoritative only from current path plus validator-owned status/history metadata.
- The dated `2026-08-10` same-report Gate 2B prestate repair ran no validator and performed no backup, IDA mutation, save, generated refresh, or lifecycle command.
- This `2026-08-11` Gate 1 lifecycle/state wording repair changed only this report and ran no validator, IDA/MCP action, generated refresh, or lifecycle command.

## Changed Files

- Changed target `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md`: SHA256 `E3227E79C90CAD23805887352EC433263CFA644ED08F1C1B04836D2510E4AB59`, 21,839 bytes, 220 lines.
- Changed class `by-class/ClanExpelNameInputDialog.md`: SHA256 `2E37639C85A26E434570638B64180658D24C97F61975857FB88121657E2C176A`, 20,542 bytes, 153 lines.
- Changed aggregate `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`: SHA256 `3BDC96260DEE2B8BFF7D1110A6B5064BD5B8C347352ACBF19D2C87F37D27AA39`, 29,580 bytes, 199 lines.
- Changed source route `by-file/Clan.md`: SHA256 `3D6ACC16748F549086662E27A8F881E2DF78ED129F798637DF7F22D0BAE6A934`, 124,219 bytes, 456 lines.
- Read-only same-or-greater helper verification: `PacketBufferHelpers.md` SHA256 `211A76A55A5E2F1CAABDA3AEE66AA7A13C868866BF63783079BDB428341395B3`; `MemmoveWrapper.md` SHA256 `CD420DEF5C5968EE4381B47040ADC403E0DCD7A22496C54E2A0BB5BF3639B685`; `QueueAndSendPacket.md` SHA256 `07F58FAB8C240719965F3E3E749742FDD2D3DE750E46E1CB8EFE30BC0D0D3E9B`.
- During the dated `2026-08-10` callback stage, this same report was updated with callback receipts and physically verified claim/checklist states; its then-current marker represented that stage only. The current exact revision requires a fresh supervisor Gate 1 artifact audit.
- The dated `2026-08-10` same-report Gate 2B prestate repair changed only this report: it rebased the snapshot IDA type from the superseded void-current observation to attested `int __stdcall(LPCWCH lpWideCharStr)` while preserving the evidence-backed final void member ABI and all prior documentation claims/checkmarks.
- This `2026-08-11` Gate 1 lifecycle/state repair changed only this report's dated-session qualifiers, phase qualifiers, lifecycle wording, and terminal marker; it did not change research conclusions, formal C++, the 74-row ledger/checklist, callback artifacts, or the structured IDA handoff.
- No coverage/generated file, IDA database, audit/catalog, goal/notes, removed-code companion, or lifecycle state was edited. Scoped validators performed only their recorded tool-owned registry/reference/projected-stats updates.
- The report contains no executable PowerShell, Python, C#, JavaScript, batch/cmd, transaction package, process launcher, hostile suite, or fixture. Its sole fenced source block is formal C++ insertion text.
- Artifact identity is computed only after final stable reread and reported externally; it is not embedded as self-referential authority.

## Implementation Tracking Checklist

Canonical parity contract: every row below mirrors Section 11 in identical order and with identical Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, and Verification state fields. The callback allocation is 51 checked B006 rows and 23 unchecked supervisor rows; only physically verified B006 documentation/helper/validator claims are checked, while manual coverage, generated refresh/readback, and IDA Gate 2B remain pending.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C2NW-001 | 0002NW | B006 records the exact modeled range `[0x00489180,0x0048926e)` and size `0xee`. | very high | Live function/item range. | Target by-memory / range and status | incorporate | applied |
| [x] | C2NW-002 | 0002NW | B006 records body SHA256 `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE` and exact first/last 16-byte receipts. | very high | Live bounded bytes and independent hash. | Target by-memory / body identity | incorporate | applied |
| [x] | C2NW-003 | 0002NW | B006 records `cc cc` at `[0x0048926e,0x00489270)` as alignment outside the target. | very high | Live bytes and item heads. | Target by-memory / boundary | incorporate | applied |
| [x] | C2NW-004 | 0002NW | B006 records the sole inbound data xref `0x00615b34 -> 0x00489180`. | very high | Live xref query and vtable bytes. | Target by-memory / virtual route | incorporate | applied |
| [x] | C2NW-005 | 0002NW | B006 records zero ordinary code callers without treating the virtual-only function as dead. | very high | Live callers and xref queries. | Target by-memory / reachability | incorporate | applied |
| [x] | C2NW-006 | 0002NW | B006 replaces current IDA `int __stdcall` framing with evidence-backed source member `void OnSubmitText(const wchar_t *text)` and explains the stale inferred return plus unused ECX. | high | No-return body, vtable, base declaration, sibling leaves, and `retn 4`. | Target by-memory / callback ABI | incorporate | applied |
| [x] | C2NW-007 | 0002NW | B006 records packet opcode `0x4b` at offset 0. | very high | Live write call and helper contract. | Target by-memory / packet opcode | incorporate | applied |
| [x] | C2NW-008 | 0002NW | B006 records expel subtype `0x07` at offset 1. | very high | Live write call and protocol routes. | Target by-memory / packet subtype | incorporate | applied |
| [x] | C2NW-009 | 0002NW | B006 records submit action `0x01` at offset 2. | very high | Live write call and protocol routes. | Target by-memory / packet action | incorporate | applied |
| [x] | C2NW-010 | 0002NW | B006 records the one-byte converted-name length at offset 3. | very high | Live fourth writer call. | Target by-memory / packet length byte | incorporate | applied |
| [x] | C2NW-011 | 0002NW | B006 records converted name bytes beginning at packet offset 4. | very high | Live memmove arguments. | Target by-memory / packet payload | incorporate | applied |
| [x] | C2NW-012 | 0002NW | B006 records exact CP_ACP conversion arguments, explicit `wcslen`, 256-byte destination, and null default-character pointers. | very high | Live WinAPI call. | Target by-memory / conversion semantics | incorporate | applied |
| [x] | C2NW-013 | 0002NW | B006 records the observed unsigned `0x100` branch as compiler range instrumentation for the indexed conversion-buffer terminator write. | very high | Live disassembly and shared runtime callee. | Target by-memory / first compiler guard evidence | incorporate | applied |
| [x] | C2NW-014 | 0002NW | B006 preserves developer-source write `convertedName[convertedLength] = 0` and excludes an explicit compiler-runtime call from formal C++. | high | Indexed source shape explains the observed first guard. | Target formal CPP / conversion terminator | incorporate | applied |
| [x] | C2NW-015 | 0002NW | B006 records the packet length-byte write before payload copy. | very high | Live instruction/call order. | Target by-memory / length write order | incorporate | applied |
| [x] | C2NW-016 | 0002NW | B006 records payload `memmove` before the second range branch. | very high | Live instruction/call order. | Target by-memory / copy order | incorporate | applied |
| [x] | C2NW-017 | 0002NW | B006 records the observed unsigned `0x80` branch as compiler range instrumentation for the later indexed packet scratch-NUL write. | very high | Live disassembly and shared runtime callee. | Target by-memory / second compiler guard evidence | incorporate | applied |
| [x] | C2NW-018 | 0002NW | B006 preserves developer-source write `packet[packetLength] = 0` after `memmove` and excludes an explicit compiler-runtime call from formal C++. | high | Indexed source shape explains the observed second guard. | Target formal CPP / packet terminator | incorporate | applied |
| [x] | C2NW-019 | 0002NW | B006 records exact counted send length `convertedLength + 4`. | very high | Live sender arguments. | Target by-memory / send length | incorporate | applied |
| [x] | C2NW-020 | 0002NW | B006 records conversion and packet source buffers as stack-owned. | very high | Complete current frame and accesses. | Target by-memory / caller buffer ownership | incorporate | applied |
| [x] | C2NW-021 | 0002NW | B006 records that Socket allocates and owns a copied queued buffer and adds its own NUL. | very high | Live queue helper body. | Target by-memory / queued buffer ownership | incorporate | applied |
| [x] | C2NW-022 | 0002NW | B006 records queue/send as void with no meaningful returned status. | very high | Live helper type/body and callsite. | Target by-memory / sender return semantics | incorporate | applied |
| [x] | C2NW-023 | 0002NW | B006 records row 8 outgoing request `{0x4b,7,0}`. | very high | Live row-action dispatcher. | Target by-memory / outgoing request route | incorporate | applied |
| [x] | C2NW-024 | 0002NW | B006 records incoming opcode `0x43`, subtype 7, action/result 0 as dialog open. | very high | Live clan-status packet dispatcher. | Target by-memory / incoming open route | incorporate | applied |
| [x] | C2NW-025 | 0002NW | B006 records incoming opcode `0x43`, subtype 7, action/result 1 as accepted path. | very high | Live clan-status packet dispatcher. | Target by-memory / incoming accept route | incorporate | applied |
| [x] | C2NW-026 | 0002NW | B006 records same-shape siblings at subtypes 8, 9, and 10 without substituting family evidence for target proof. | high | Live sibling bodies. | Target by-memory / sibling comparison | incorporate | applied |
| [x] | C2NW-027 | 0002NW | B006 records UID0002NU money conversion and UInt32BE path as not applicable to this name submitter. | very high | Live UID0002NU target comparison. | Target by-memory / rejected money-path carryover | not-applicable | excluded-with-reason |
| [x] | C2NW-028 | 0002NW | B006 documents one 256-byte conversion array and one contiguous 128-byte packet source array while preserving literal IDA frame fragments. | high | Frame layout and contiguous offset accesses. | Target by-memory / source-array shape | incorporate | applied |
| [x] | C2NW-029 | 0002NW | B006 keeps canonical owner UID00002D. | very high | Sole class-vtable route. | Target metadata / canonical owner | already-present | already-present |
| [x] | C2NW-030 | 0002NW | B006 keeps emitter UID00002D. | very high | Class owns declaration and child method route. | Target metadata / emitter | already-present | already-present |
| [x] | C2NW-031 | 0002NW | B006 keeps reconstructable true. | very high | Complete modeled source-bearing method. | Target metadata / reconstructable | already-present | already-present |
| [x] | C2NW-032 | 0002NW | B006 keeps route UID00002D -> UID0000I8 -> `social/Clan.cpp` and rejects a target-only move. | high | Current owner graph and family coupling. | Target by-memory / source placement | already-present | already-present |
| [x] | C2NW-033 | 0002NW | B006 replaces formal CPP with exact Section 22 void/value-first developer-source body without explicit compiler-runtime guard calls. | high | Closed behavior plus compiler/source-shape analysis. | Target formal RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C2NW-034 | 0002NW | B006 leaves formal H blank because UID00002D owns the declaration. | very high | Emitter layering and existing class H. | Target formal RECONSTRUCTION_H CODE | not-applicable | excluded-with-reason |
| [x] | C2NW-035 | 0002NW | B006 raises target metadata from `86/91` to `94/94` and leaves all routing fields unchanged. | high | Resolved behavior, ABI, protocol, source, and handoff blockers. | Target metadata / scores | incorporate | applied |
| [x] | C2NW-036 | 0002NW | B006 preserves old target no-code wording only as a contradicted historical assumption. | very high | Current modeled function and formal source eligibility. | Target by-memory / history | historicalize | applied |
| [x] | C2NW-037 | 0002NW | B006 preserves the old returned-sender-result wording only as a contradicted historical assumption. | very high | Live queue helper returns void. | Target by-memory / history | historicalize | applied |
| [x] | C2NW-038 | 0002NW | B006 rejects stale destination-first PacketBuffer syntax in favor of value-first calls. | very high | Live prototype/body and cdecl push order. | Target by-memory / API correction | reject-stale | excluded-with-reason |
| [x] | C2NW-039 | 0002NW | B006 incorporates the broad B001 artifact's accepted family facts and records every corrected, superseded, or not-applicable claim from Section 2. | high | Artifact SHA `2EA63F0B...CECB` plus independent live revalidation. | Target by-memory / historical B001 reconciliation | incorporate | applied |
| [x] | C2NW-040 | 0002NW | B006 incorporates the raw-constructor B001 artifact only as separate sibling/class evidence and records every superseded or not-applicable claim from Section 2. | high | Artifact SHA `75D5F236...A389D` plus independent live revalidation. | Target by-memory / historical B001 reconciliation | incorporate | applied |
| [x] | C2NW-041 | 0002NW | B006 incorporates the UID0002NX/UID0002O1 B001 artifact only as successor/family source-placement evidence and records every accepted or not-applicable claim from Section 2. | high | Artifact SHA `6122042519D53F8DF3687C931E3293B3C575E6F2C3E14B31DAFF855B748FF182` plus independent live revalidation. | Target by-memory / historical B001 reconciliation | incorporate | applied |
| [x] | C2NW-042 | 0002NW | B006 adds target-specific hash, value-first API, compiler-guard ordering, queue ownership, and protocol facts while retaining class `86/90`. | high | Dedicated target evidence; raw-constructor cap is separate. | by-class/ClanExpelNameInputDialog.md / target method | incorporate | applied |
| [x] | C2NW-043 | 0002NW | B006 adds a UID0002NW-specific evidence row without changing the aggregate's non-emitting state. | high | Aggregate currently carries only broad family detail. | by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md / UID0002NW | incorporate | applied |
| [x] | C2NW-044 | 0002NW | B006 adds the exact UID0002NW source method, protocol, compiler-guard, and owner facts while retaining Clan route. | high | Current by-file text is broader than this pass. | by-file/Clan.md / UID0002NW source note | incorporate | applied |
| [x] | C2NW-045 | 0002NW | B006 verifies the value-first byte-writer contract already exists at same-or-greater detail and does not duplicate target narrative. | very high | Current helper documentation. | by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md | already-present | already-present |
| [x] | C2NW-046 | 0002NW | B006 verifies the memmove wrapper contract already exists at same-or-greater detail and does not duplicate target narrative. | very high | Current helper documentation. | by-memory/0x00516220-0x00516238.MemmoveWrapper.md | already-present | already-present |
| [x] | C2NW-047 | 0002NW | B006 verifies void queue/copy ownership already exists at same-or-greater detail and does not duplicate target narrative. | very high | Current helper documentation. | by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md | already-present | already-present |
| [ ] | C2NW-048 | 0002NW | Supervisor replaces the exact manual by-memory coverage row with Section 28's 94% text. | high | Current manual row is stale at 82%. | by-memory/-coverage-report.md / UID0002NW row | incorporate | proposed |
| [ ] | C2NW-049 | 0002NW | Supervisor replaces the exact manual by-class coverage row with Section 28's 86% text. | high | Current manual row is stale at 84%. | by-class/-coverage-report.md / UID00002D row | incorporate | proposed |
| [ ] | C2NW-050 | 0002NW | Supervisor refreshes and rereads the research tracker and generated coverage after accepted documentation changes. | high | Generated state currently reflects old metadata. | auto-generated reports / UID0002NW readback | incorporate | proposed |
| [ ] | C2NW-051 | 0002NW | Supervisor rereads generated Clan CPP and H and verifies exact body/declaration routing after refresh. | high | Generated source is validator-owned. | auto-generated/NexusTK/social/Clan.cpp and Clan.h | incorporate | proposed |
| [ ] | C2NW-052 | 0002NW | Supervisor Gate 2B declares only incomplete `struct ClanExpelNameInputDialog;` if fresh A00 prestate remains absent. | high | Current type query returns zero matches. | IDA A00 / local type catalog | incorporate | proposed |
| [ ] | C2NW-053 | 0002NW | Supervisor Gate 2B pure-renames `sub_489180` to `ClanExpelNameInputDialog__OnSubmitText` only under A01 prestate. | high | Vtable, base, source, and protocol identity. | IDA A01 / function 0x00489180 | incorporate | proposed |
| [ ] | C2NW-054 | 0002NW | Supervisor Gate 2B renames stack argument `lpWideCharStr` to `text` only under A02 prestate. | high | Exact argument use and source convention. | IDA A02 / stack argument +0x194 | incorporate | proposed |
| [ ] | C2NW-055 | 0002NW | Supervisor Gate 2B renames `MultiByteStr` to `convertedName` only under A03 prestate. | high | Exact conversion destination role. | IDA A03 / stack local +0x8 | incorporate | proposed |
| [ ] | C2NW-056 | 0002NW | Supervisor Gate 2B renames `Src` to `packetOpcode` only under A04 prestate. | high | Exact packet offset 0 role. | IDA A04 / stack local +0x108 | incorporate | proposed |
| [ ] | C2NW-057 | 0002NW | Supervisor Gate 2B renames `destination` to `packetSubtype` only under A05 prestate. | high | Exact packet offset 1 role. | IDA A05 / stack local +0x109 | incorporate | proposed |
| [ ] | C2NW-058 | 0002NW | Supervisor Gate 2B renames `var_82` to `packetAction` only under A06 prestate. | high | Exact packet offset 2 role. | IDA A06 / stack local +0x10a | incorporate | proposed |
| [ ] | C2NW-059 | 0002NW | Supervisor Gate 2B renames `var_81` to `packetNameLength` only under A07 prestate. | high | Exact packet offset 3 role. | IDA A07 / stack local +0x10b | incorporate | proposed |
| [ ] | C2NW-060 | 0002NW | Supervisor Gate 2B renames `var_80` to `packetNameBytes` without reshaping only under A08 prestate. | high | Exact payload role. | IDA A08 / stack local +0x10c | incorporate | proposed |
| [ ] | C2NW-061 | 0002NW | Supervisor Gate 2B intentionally corrects literal current `int __stdcall(LPCWCH lpWideCharStr)` to the exact evidence-backed void-thiscall prototype only under A09 function/frame prestate, while preserving physical F10 as `text@+0x194`, size 4, type `LPCWCH`; that typedef rendering is equivalent to prototype `const wchar_t *text`. | high | No-return body, virtual route, base/sibling ABI, stack cleanup, complete frame, and failed-closed A09 readback. | IDA A09 / function type 0x00489180 | incorporate | proposed |
| [ ] | C2NW-062 | 0002NW | Supervisor Gate 2B sets only the function-regular comment under A10 prestate. | high | Closed behavior and protocol. | IDA A10 / function comment 0x00489180 | incorporate | proposed |
| [ ] | C2NW-063 | 0002NW | Supervisor Gate 2B sets only the regular vtable-slot comment under A11 prestate. | high | Sole virtual route. | IDA A11 / address comment 0x00615b34 | incorporate | proposed |
| [ ] | C2NW-064 | 0002NW | Supervisor Gate 2B preserves exact target range, 238-byte body, and body SHA under P01. | very high | Literal current bytes and item range. | IDA P01 / target body and range | already-present | proposed |
| [ ] | C2NW-065 | 0002NW | Supervisor Gate 2B preserves exact sole data xref `0x00615b34 -> 0x00489180` under P02. | very high | Literal current xref set. | IDA P02 / target xref | already-present | proposed |
| [ ] | C2NW-066 | 0002NW | Supervisor Gate 2B preserves zero ordinary callers under P03. | very high | Literal current caller set. | IDA P03 / target callers | already-present | proposed |
| [ ] | C2NW-067 | 0002NW | Supervisor Gate 2B preserves every physical frame offset, width, and type under P04; only A02-A08 physical names change, A09 changes only the function prototype, and F10 remains `text@+0x194`, size 4, type `LPCWCH`. | very high | Complete pre/post frame table and failed-closed physical-frame readback. | IDA P04 / function frame | already-present | proposed |
| [ ] | C2NW-068 | 0002NW | Supervisor Gate 2B preserves exact vtable bytes and pointer value under P05. | very high | Literal current vtable window. | IDA P05 / vtable slot 0x00615b34 | already-present | proposed |
| [ ] | C2NW-069 | 0002NW | Supervisor Gate 2B preserves exact `cc cc` alignment item under P06. | very high | Literal current bytes/item model. | IDA P06 / alignment 0x0048926e-0x00489270 | already-present | proposed |
| [ ] | C2NW-070 | 0002NW | Supervisor Gate 2B preserves the raw successor item head and next modeled sibling start under P07. | very high | Literal current item/function model. | IDA P07 / successor 0x00489270 | already-present | proposed |
| [x] | C2NW-071 | 0002NW | B006 runs scoped target validation after callback and records command metadata and stable hash. | high | Required callback verification. | Target by-memory / scoped validator | incorporate | applied |
| [x] | C2NW-072 | 0002NW | B006 runs scoped validation for the class page if edited and records command metadata and stable hash. | high | Required callback verification. | by-class/ClanExpelNameInputDialog.md / scoped validator | incorporate | applied |
| [x] | C2NW-073 | 0002NW | B006 runs scoped validation for the aggregate page if edited and records command metadata and stable hash. | high | Required callback verification. | by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md / scoped validator | incorporate | applied |
| [x] | C2NW-074 | 0002NW | B006 runs scoped validation for the Clan by-file page if edited and records command metadata and stable hash. | high | Required callback verification. | by-file/Clan.md / scoped validator | incorporate | applied |

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000021865","destination_path":"executed-b-agent-research/B006/0002NW-ClanExpelNameInputDialogSubmitName-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002NW-ClanExpelNameInputDialogSubmitName-source-quality.md","timestamp":"2026-08-11T09:35:06-04:00","uid":"0002NW"} -->
<!-- {"agent":"B006","command_id":"000000023052","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002NW-ClanExpelNameInputDialogSubmitName-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002NW-ClanExpelNameInputDialogSubmitName-source-quality.md","timestamp":"2026-08-13T03:35:41-04:00","uid":"0002NW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
