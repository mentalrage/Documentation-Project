# UID0002O0 ClanAppearNameInputDialog Submit Name Source-Quality Research
** TARGET-REPORT-UID:0002O0 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Recommendation: retain [UID:0002O0] as the single source-emitting `ClanAppearNameInputDialog::OnSubmitText(const wchar_t *)` body, owned and emitted by [UID:000023] `ClanAppearNameInputDialog` through [UID:0000I8] `Clan` -> `NexusTK/social/Clan.cpp`.
- The exact target is now `94/94` with `CANONICAL_OWNER:000023`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000023`, and a blank child H channel.
- Section 22's human-source CPP is installed. It preserves the indexed terminator writes and exact conversion/write/copy/send order while omitting explicit `__report_rangecheckfailure` calls because those calls are compiler instrumentation.
- The parent class is now `93/93`; owner/emitter UID0000I8, class formal H, `[[CHILDREN]]`, and the raw constructor's separate no-entry caveat are preserved.
- Accepted ordinary implementation allocation is `52/74` checked and `22/74` unchecked supervisor-owned claims. Four ordinary pages were changed and scoped-validated; no manual coverage file, IDA database, report lifecycle state, or generated source file was edited directly.

## Supporting Research

- Project context: local preservation and faithful source reconstruction of the unsupported NexusTK client.
- Canonical read-only MCP evidence was collected on `2026-08-15` from database/session `b002_uid0000hq_rollback_20260815` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Public `runtime_attestation` returned schema `1`, `ok:true`, `errors:[]`, listener `127.0.0.1:13337` PID `14320`, stateful worker endpoint `127.0.0.1:62860` PID `20216`, and matching canonical path/session/module identities. This is dated research evidence, not permanent future Gate 2B authority.
- `server_health` returned `status:ok`, image base `0x400000`, Hex-Rays ready, and strings ready. The bounded IDB-backed queries required by this report all succeeded.
- Binary identity from `survey_binary`: 32-bit `NexusTK.exe`, image base `0x400000`, image size `0x2b3000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Historical artifacts were treated as leads and revalidated:

| Artifact | SHA256 | Disposition |
| --- | --- | --- |
| `executed-b-agent-research/B001/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md` | `0A292E308EDAA8209E8EB82FC5B8D9C77910BC9AF3381C1E68E396C933F44D31` | Family callback, packet layout, owner, and source-route leads accepted only after current target proof; stale int-return, destination-first, explicit-runtime, and old-score conclusions rejected. |
| `executed-b-agent-research/B002/000023-ClanAppearNameInputDialog-source-quality.md` | `919B9249D6D80E40D6E8E531B7F3520027C3548569746C05440C76ECE24428AF` | Class inheritance, declaration, and child-routing leads accepted; the current callback supplied the previously missing target detail and class score refresh. |
| `executed-b-agent-research/B011/0002NZ-ClanAppearNameInputDialogRawConstructor-source-quality.md` | `09148367F3CFE23612CB0D99B4B2CC4846DB2360AE5AD78D3A3D334A03E22C2B` | Separate raw-constructor bounds/vtables/inline corroboration accepted; no-route evidence does not suppress this modeled method. |
| `executed-b-agent-research/B006/0002NW-ClanExpelNameInputDialogSubmitName-source-quality.md` | `D0F5EB7C104A0FCF68E23A0C651598194EBD6A2FC9EB2E65E49083732442F8A1` | Same-family source/compiler/API pattern used as corroboration, not a substitute for UID0002O0 proof. |
| `executed-b-agent-research/B004/0002NY-ClanSummonNameInputDialogSubmitName-source-quality.md` | `B59C734967FBD5BBEFEE1E4C5A0730DE50AA9CB82A8C0DC3550F0E4C21BEA6C9` | Same-family subtype-8 evidence corroborates the independently proved subtype-9 method. |

- No Wave2/Wave3 evidence or instruction was used.

## Target

- UID: `0002O0`.
- Path: `by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md`.
- Exact entity: modeled function `[0x004893e0,0x004894ce)`, size `0xee` / 238 bytes.
- Queue basis: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, assignment-time row `86/91` and no dedicated current report.
- Direct owner/emitter: [UID:000023] `ClanAppearNameInputDialog`. Source route: [UID:0000I8] `Clan` -> `NexusTK/social/Clan.cpp`.

## Current Target State

- Metadata: `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:000023`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000023`.
- Current formal CPP is exactly Section 22's human-source body. The target formal H remains blank because [UID:000023] owns `virtual void OnSubmitText(const wchar_t *text);` in `Clan.h`.
- Current target prose now records the canonical body hash and edge bytes, exact alignments, complete ten-row frame/source interpretation, vtable and all-head route audit, exact API/protocol/compiler order, Socket queue ownership, raw duplicate, owner/emitter/source route, historical corrections, and score ceiling.
- Current parent class is `93/93`; UID00010K remains non-emitting `85/89`; UID0000I8 remains file owner `90/85`. All accepted target-specific support details are present.
- Callback generated refresh completed under validator command `000000024424` at `2026-08-15T19:24:26-04:00`. Final physical reread observes the later validator-owned foreground refresh command `000000024426`, refreshed `2026-08-15T19:25:29-04:00`: `Clan.cpp` SHA256 `FD903D55446F0501C2A26BF2B8C12A8DCF7ED31AA131360399FB3064EB4D210E`, 53,070 bytes / 1,322 lines; `Clan.h` SHA256 `12543CCE33E6B9E43E1F24A4C8FEFDCFE0A96413AC79AC5580E18F39AFE16018`, 6,156 bytes / 200 lines.
- Generated CPP reports UID0002O0 at `94/94`, contains exactly one `ClanAppearNameInputDialog::OnSubmitText` definition equal to Section 22, and contains no explicit range-runtime call in that block. Generated H reports UID000023 at `93/93` and contains the exact class declaration. Generated files were validator-refreshed and physically read, never manually edited.

## Executive Recommendation

- Use normal source identity `void ClanAppearNameInputDialog::OnSubmitText(const wchar_t *text)`.
- Preserve value-first `PacketBufferWriteUInt8(value, destination)` calls and exact packet bytes `{0x4b,0x09,0x01,length,name...}`.
- Preserve `WideCharToMultiByte(CP_ACP,0,text,wcslen(text),convertedName,256,NULL,NULL)`.
- Preserve the conversion terminator before the length write, payload copy before the second compiler guard, packet terminator after the second guard, and counted send length `convertedLength + 4`.
- Do not author explicit security-cookie or range-runtime calls.
- Keep one contiguous `convertedName[256]` and one contiguous `packet[128]` in source while documenting IDA's literal physical frame fragments.
- Keep the current owner/emitter/source route. Do not emit the raw duplicate at `0x004860e0` or move one method to `ClanDialogs.cpp`.

## Supervisor Active Recheck

- Fresh Gate 1 must verify this exact post-callback artifact, all 33 headings, `74/74` ledger/checklist parity, `52 checked / 22 unchecked`, Section 21 endpoint bindings, one formal CPP block, no executable automation, and one terminal execute-control marker.
- Gate 2A must verify every checked claim against the four changed ordinary pages and commands `24421` through `24424`; manual coverage and IDA claims remain unchecked and supervisor-owned.
- Any Gate 2B work is supervisor-owned. Before mutation the supervisor must establish fresh canonical runtime authority and fresh literal prestates; the dated session above cannot authorize a future write.
- The target requires no split. Both alignment intervals and the neighboring raw constructors are outside the modeled method.

## Inference Research Guidance Check

- Binary facts, documentation facts, and inference are separated.
- Source-facing names are inferred from exact behavior, sibling naming, class declarations, and established local style; raw labels such as `MultiByteStr`, `Src`, and `var_80` are not preserved as final source merely because original symbols are stripped.
- Runtime behavior has priority. Human-source form is then reconstructed in plausible late-1999 through mid-2000s C++ style, followed by project consistency.
- The absence of a current local `ClanAppearNameInputDialog` UDT does not make the source callback uncertain. It only limits which IDA type mutation is deterministic.
- Historical incorrect assumptions are retained as explicitly superseded evidence rather than silently pruned.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution |
| --- | --- | --- |
| Function identity | Sole inbound data xref `0x00615c74 -> 0x004893e0` from the class primary vtable; base slot `+0x5c` receives submitted wide text. | `ClanAppearNameInputDialog::OnSubmitText`, very high confidence. |
| Return/calling convention | Current IDA already renders `void __thiscall(void *this,const wchar_t *text)`; body produces no return and base dispatch ignores one. | Source method returns `void`. |
| Source names | Exact uses establish converted-name array, packet header bytes, name length, and payload tail. | `text`, `convertedName`, `packet`, `convertedLength`, `packetLength`. |
| Writer order | Live helper type and cdecl pushes prove value first. | `PacketBufferWriteUInt8(value,destination)`. |
| First guard | Unsigned `convertedLength >= 0x100` branch targets range runtime immediately before indexed conversion terminator. | Compiler instrumentation around `convertedName[convertedLength] = 0`. |
| Second guard | Copy occurs first; unsigned `convertedLength + 4 >= 0x80` branch protects later indexed packet terminator. | Compiler instrumentation around `packet[packetLength] = 0`; preserve copy-before-guard order. |
| Send ownership | Queue helper allocates `length+1`, copies counted bytes, adds its own NUL, posts command 8, and returns void. | Caller arrays remain stack-owned; call is a statement. |
| Protocol | Row 10 sends subtype 9/action 0; incoming opcode `0x43` case 9 opens the appearance dialog only for byte `+2 == 0`; nonzero is accepted without opening. | This method is the corresponding action-1 submit. |
| Raw duplicate | `[0x004860e0,0x004861ce)` has the same subtype-9/action-1 semantics but no function, xref, or pointer route. | Retained no-route duplicate; no second source emitter. |
| Source placement | Class, family, owner graph, and generated route all converge on `Clan.cpp`. | Keep current route; reject target-only `ClanDialogs.cpp` move. |
| IDA receiver type | Source class is resolved, but current local type catalog has no `ClanAppearNameInputDialog` UDT and public parser durability is not proved for this target. | Preserve current safe `void *this` IDA type; improve names/comments only. |
| Score | Every behavioral, ownership, API, protocol, code-shape, and output blocker is closed. | Target `94/94`; class `93/93`. |

## Evidence Standards Used

- Exact current bounded MCP queries on one attested canonical database.
- Independent PE body hashing and exact boundary-byte comparison.
- Direct xref/caller/callee, all-instruction-head inbound-xref, pointer/immediate/raw-offset, vtable, frame, comment-channel, and local-type-catalog checks.
- Current by-* metadata/content and validator-generated CPP/H readback.
- Sibling and historical reports only after target-specific revalidation.
- Negative evidence is used to reject duplicates/alternate routes, not to excuse missing investigation.

## Evidence Checked

- `lookup_funcs`, `func_query`, `decompile`, `disasm`, `insn_query`, `stack_frame`, `callees`, `xref_query`, `xrefs_to`, `find_bytes`, `type_query`, `get_comments`, `inspect_items`, `get_bytes`, `runtime_attestation`, `server_health`, and `survey_binary`.
- Every one of the target's 76 instruction heads was checked for external inbound references.
- Exact start/end VA, RVA, and raw-file-offset pointer patterns and immediate values were checked.
- Target, class, raw constructor, family aggregate, raw duplicate strip, base dialog, PacketBuffer, memmove, queue/send, sender-global, Clan by-file, ClanDialogs index, and current generated `Clan.cpp`/`Clan.h` pages were read.
- Manual target/class coverage rows and generated research-tracker rows were read without editing.
- Historical search terms: `0002O0`, `0x004893e0`, `ClanAppearNameInputDialog`, `OnSubmitText`, `sub_4893E0`, subtype `9`, and `ClanNameDialogSubmitters`.

## Claim And Incorporation Ledger

Canonical parity contract: Section 33 mirrors all 74 rows below in identical order and with identical Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, and Verification state fields. Accepted callback allocation is 52 checked and 22 unchecked supervisor-owned rows.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2O0-001 | 0002O0 | Record exact modeled range `[0x004893e0,0x004894ce)` and size `0xee` / 238. | very high | Current function/item queries. | Target / range and identity | incorporate | applied |
| C2O0-002 | 0002O0 | Record body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8` and exact edge bytes. | very high | Canonical PE body bytes. | Target / body identity | incorporate | applied |
| C2O0-003 | 0002O0 | Exclude eleven-byte `cc` pre-alignment `[0x004893d5,0x004893e0)`. | very high | Bounded bytes/items. | Target / boundary | incorporate | applied |
| C2O0-004 | 0002O0 | Exclude two-byte `cc cc` post-alignment `[0x004894ce,0x004894d0)`. | very high | Bounded bytes/items. | Target / boundary | incorporate | applied |
| C2O0-005 | 0002O0 | Record current function name `ClanAppearNameInputDialog__OnSubmitText` as source-compatible IDA identity. | very high | Current function query. | Target / IDA state | incorporate | applied |
| C2O0-006 | 0002O0 | Resolve source ABI as void virtual member `OnSubmitText(const wchar_t *text)`. | very high | Vtable, base dispatch, current type, no-return body. | Target / callback ABI | incorporate | applied |
| C2O0-007 | 0002O0 | Record the complete ten-row physical frame and contiguous human-source array interpretation. | very high | Current stack frame and accesses. | Target / frame and source shape | incorporate | applied |
| C2O0-008 | 0002O0 | Record sole inbound data xref `0x00615c74 -> 0x004893e0`. | very high | Current xref query. | Target / vtable route | incorporate | applied |
| C2O0-009 | 0002O0 | Record zero ordinary code callers without classifying the virtual method as dead. | very high | Caller/xref queries. | Target / reachability | incorporate | applied |
| C2O0-010 | 0002O0 | Record all-head external inbound union as exactly the sole vtable xref. | very high | 76 bounded head queries. | Target / interior-xref audit | incorporate | applied |
| C2O0-011 | 0002O0 | Record zero start/end RVA, raw-offset, and immediate routes beyond the vtable VA pointer. | very high | Pointer/immediate scans. | Target / route audit | incorporate | applied |
| C2O0-012 | 0002O0 | Record the exact seven semantic/compiler callees and no strings. | very high | Callee/string queries. | Target / dependency inventory | incorporate | applied |
| C2O0-013 | 0002O0 | Record opcode `0x4b` at packet offset 0. | very high | First byte-writer call. | Target / packet layout | incorporate | applied |
| C2O0-014 | 0002O0 | Record subtype `0x09` at packet offset 1. | very high | Second byte-writer call. | Target / packet layout | incorporate | applied |
| C2O0-015 | 0002O0 | Record submit action `0x01` at packet offset 2. | very high | Third byte-writer call. | Target / packet layout | incorporate | applied |
| C2O0-016 | 0002O0 | Record narrowed converted-name length byte at packet offset 3. | very high | Fourth byte-writer call. | Target / packet layout | incorporate | applied |
| C2O0-017 | 0002O0 | Record converted payload beginning at packet offset 4. | very high | Memmove arguments. | Target / packet layout | incorporate | applied |
| C2O0-018 | 0002O0 | Record exact CP_ACP conversion arguments and `wcslen(text)` semantics. | very high | WinAPI call sequence. | Target / conversion | incorporate | applied |
| C2O0-019 | 0002O0 | Classify the `0x100` failure branch as compiler instrumentation. | very high | Indexed write and runtime target. | Target / first guard | incorporate | applied |
| C2O0-020 | 0002O0 | Preserve `convertedName[convertedLength] = 0` without authored runtime call. | high | Human-source/compiler-shape analysis. | Target formal CPP | incorporate | applied |
| C2O0-021 | 0002O0 | Preserve length write followed by payload copy. | very high | Exact instruction/call order. | Target / operation order | incorporate | applied |
| C2O0-022 | 0002O0 | Classify the post-copy `0x80` failure branch as compiler instrumentation. | very high | Indexed write and runtime target. | Target / second guard | incorporate | applied |
| C2O0-023 | 0002O0 | Preserve `packet[packetLength] = 0` after copy without authored runtime call. | high | Human-source/compiler-shape analysis. | Target formal CPP | incorporate | applied |
| C2O0-024 | 0002O0 | Record exact sent length `convertedLength + 4`. | very high | Sender call arguments. | Target / send length | incorporate | applied |
| C2O0-025 | 0002O0 | Record both source arrays and scratch NULs as caller-stack-owned and outside sent length. | very high | Frame and counted send. | Target / ownership | incorporate | applied |
| C2O0-026 | 0002O0 | Record Socket-owned queued copy, queue terminator, command 8, and void return. | very high | Current queue helper body/type. | Target / queue semantics | incorporate | applied |
| C2O0-027 | 0002O0 | Record base control path reading text and dispatching primary vtable slot `+0x5c` without consuming a return. | very high | Base `OnButtonClick` disassembly. | Target / virtual callback route | incorporate | applied |
| C2O0-028 | 0002O0 | Record row-10 request `{0x4b,9,0}`. | very high | Current row-action disassembly. | Target / protocol request | incorporate | applied |
| C2O0-029 | 0002O0 | Record incoming opcode `0x43` subtype-9 action/result 0 dialog-open route. | very high | Current dispatcher case 9. | Target / protocol open | incorporate | applied |
| C2O0-030 | 0002O0 | Record subtype-9 nonzero action/result as accepted no-open completion path. | high | Case-9 conditional/default flow. | Target / protocol completion | incorporate | applied |
| C2O0-031 | 0002O0 | Compare exact name siblings 7/8/10 and reject money-only `_wtol`/UInt32BE carryover. | very high | Current family bodies. | Target / family comparison | not-applicable | excluded-with-reason |
| C2O0-032 | 0002O0 | Record raw `[0x004860e0,0x004861ce)` as a no-route duplicate covered by this live body. | very high | Raw disassembly and zero-route checks. | Target / duplicate reconciliation | incorporate | applied |
| C2O0-033 | 0002O0 | Keep canonical owner UID000023. | very high | Sole class-vtable route. | Target metadata / owner | already-present | already-present |
| C2O0-034 | 0002O0 | Keep emitter UID000023 and reconstructable true. | very high | Complete class method and emitter graph. | Target metadata / emitter | already-present | already-present |
| C2O0-035 | 0002O0 | Keep source route UID000023 -> UID0000I8 -> `social/Clan.cpp`. | high | Current family/source graph. | Target / source placement | already-present | already-present |
| C2O0-036 | 0002O0 | Replace formal CPP with Section 22 exact human-source body. | high | Closed behavior and source-shape analysis. | Target formal CPP | incorporate | applied |
| C2O0-037 | 0002O0 | Keep target formal H blank because UID000023 owns the declaration. | very high | Emitter layering and current class H. | Target formal H | not-applicable | excluded-with-reason |
| C2O0-038 | 0002O0 | Raise target `86/91 -> 94/94` with routing unchanged. | high | All target blockers resolved. | Target metadata / scores | incorporate | applied |
| C2O0-039 | 0002O0 | Reject stale hash `4FEF...` as current authority and preserve it only as dated historical evidence. | very high | Current exact body SHA differs. | Target / history | reject-stale | applied |
| C2O0-040 | 0002O0 | Reject explicit `__report_rangecheckfailure` source blocks while preserving observed compiler checks. | high | Compiler/source-shape analysis. | Target / history and formal CPP | reject-stale | applied |
| C2O0-041 | 0002O0 | Replace broad target prose with exhaustive range/frame/API/protocol/ownership evidence. | high | Current target audit. | Target / all evidence sections | incorporate | applied |
| C2O0-042 | 0002O0 | Raise UID000023 `86/90 -> 93/93` and incorporate exact child evidence while retaining raw-constructor caveat. | high | Complete class declaration plus 92/93 constructor and 94/94 method. | by-class/ClanAppearNameInputDialog.md | incorporate | applied |
| C2O0-043 | 0002O0 | Add a UID0002O0-specific family evidence subsection without changing UID00010K's non-emitting `85/89` state. | high | Aggregate is correct but target row is shallow. | ClanNameDialogSubmitters aggregate | incorporate | applied |
| C2O0-044 | 0002O0 | Expand the Clan by-file row with exact target hash/API/compiler/protocol/owner facts without changing `90/85`. | high | Current by-file row is shallow. | by-file/Clan.md | incorporate | applied |
| C2O0-045 | 0002O0 | Verify UID00021L already records the raw subtype-9 action-1 duplicate and covered-by route. | very high | Current raw-strip page. | ClanNameActionPacketHelpers | already-present | already-present |
| C2O0-046 | 0002O0 | Verify PacketBuffer, memmove, queue/send, and sender-global support contracts already exist at same-or-greater detail. | very high | Current support pages. | Helper/global support docs | already-present | already-present |
| C2O0-047 | 0002O0 | Preserve class-owned C++98-compatible `virtual void` declaration; do not add `override` or duplicate child H. | high | Current class H and source-era style. | Class H / target H | already-present | already-present |
| C2O0-048 | 0002O0 | Supervisor replaces stale manual by-memory coverage row with Section 28's exact 94% text. | high | Current row is 82%. | by-memory/-coverage-report.md | incorporate | proposed |
| C2O0-049 | 0002O0 | Supervisor replaces stale manual class coverage row with Section 28's exact 93% text. | high | Current row is 84%. | by-class/-coverage-report.md | incorporate | proposed |
| C2O0-050 | 0002O0 | Supervisor refreshes/rechecks research tracker and generated coverage after callback. | high | Generated rows reflect old scores/report coverage. | Generated reports | incorporate | proposed |
| C2O0-051 | 0002O0 | Supervisor rereads generated `Clan.cpp`/`Clan.h` for exact body/declaration and current hashes. | high | Generated files are validator-owned. | Generated Clan CPP/H | incorporate | proposed |
| C2O0-052 | 0002O0 | Gate 2B renames `MultiByteStr` to `convertedName` only under A01. | high | Exact conversion-array role. | IDA A01 | incorporate | proposed |
| C2O0-053 | 0002O0 | Gate 2B renames `Src` to `packetOpcode` only under A02. | high | Exact packet offset-0 role. | IDA A02 | incorporate | proposed |
| C2O0-054 | 0002O0 | Gate 2B renames `destination` to `packetSubtype` only under A03. | high | Exact packet offset-1 role. | IDA A03 | incorporate | proposed |
| C2O0-055 | 0002O0 | Gate 2B renames `var_82` to `packetAction` only under A04. | high | Exact packet offset-2 role. | IDA A04 | incorporate | proposed |
| C2O0-056 | 0002O0 | Gate 2B renames `var_81` to `packetNameLength` only under A05. | high | Exact packet offset-3 role. | IDA A05 | incorporate | proposed |
| C2O0-057 | 0002O0 | Gate 2B renames `var_80` to `packetNameBytes` only under A06. | high | Exact payload-tail role. | IDA A06 | incorporate | proposed |
| C2O0-058 | 0002O0 | Gate 2B renames `lpWideCharStr` to `text` only under A07. | high | Exact callback-argument role. | IDA A07 | incorporate | proposed |
| C2O0-059 | 0002O0 | Gate 2B replaces only the function-regular comment under A08. | high | Closed target behavior. | IDA A08 | incorporate | proposed |
| C2O0-060 | 0002O0 | Gate 2B sets only the vtable-slot regular address comment under A09. | high | Sole virtual route. | IDA A09 | incorporate | proposed |
| C2O0-061 | 0002O0 | Gate 2B preserves exact target body/range/hash under P01. | very high | Literal current bytes/range. | IDA P01 | already-present | proposed |
| C2O0-062 | 0002O0 | Gate 2B preserves exact xref/caller sets under P02. | very high | Literal current route sets. | IDA P02 | already-present | proposed |
| C2O0-063 | 0002O0 | Gate 2B preserves all frame offsets/widths/types and permits only A01-A07 names under P03. | very high | Complete current frame. | IDA P03 | already-present | proposed |
| C2O0-064 | 0002O0 | Gate 2B preserves vtable bytes/value/name/type/repeatable channel under P04. | very high | Current vtable window/item. | IDA P04 | already-present | proposed |
| C2O0-065 | 0002O0 | Gate 2B preserves both alignment intervals and neighboring item heads under P05. | very high | Current boundaries/items. | IDA P05 | already-present | proposed |
| C2O0-066 | 0002O0 | Gate 2B preserves current function name/type and makes no unsafe receiver-UDT type action under P06. | high | Source ABI resolved; target UDT absent. | IDA P06 | already-present | proposed |
| C2O0-067 | 0002O0 | Gate 2B preserves callees, internal comments, non-target comment channels, and all unrelated state under P07. | very high | Current dependency/comment inventory. | IDA P07 | already-present | proposed |
| C2O0-068 | 0002O0 | Validate the target ordinary page after callback. | high | Required scoped validation. | Target validator receipt | incorporate | applied |
| C2O0-069 | 0002O0 | Validate the class ordinary page after callback. | high | Required scoped validation. | Class validator receipt | incorporate | applied |
| C2O0-070 | 0002O0 | Validate the family aggregate ordinary page after callback. | high | Required scoped validation. | Aggregate validator receipt | incorporate | applied |
| C2O0-071 | 0002O0 | Validate the Clan by-file ordinary page after callback. | high | Required scoped validation. | Clan validator receipt | incorporate | applied |
| C2O0-072 | 0002O0 | Supervisor validates manual target coverage after applying exact text. | high | Coverage is supervisor-owned. | Target coverage validator receipt | incorporate | proposed |
| C2O0-073 | 0002O0 | Supervisor validates manual class coverage after applying exact text. | high | Coverage is supervisor-owned. | Class coverage validator receipt | incorporate | proposed |
| C2O0-074 | 0002O0 | Preserve the dated report-only no-edit/no-validator/no-IDA boundary as historical pre-callback evidence; ordinary implementation and scoped validators were later applied under the accepted callback while IDA and lifecycle remained untouched. | very high | Historical assignment boundary plus current changed-file and validator receipts. | Report lifecycle boundary / callback history | incorporate | applied |

## Positive Evidence Summary

- One exact modeled function with stable boundaries and a unique exact body.
- One class-vtable inbound pointer and zero ordinary callers, exactly matching virtual dispatch.
- Exact packet field sequence and direct helper contracts.
- Exact conversion parameters, two indexed terminator writes, compiler guard placement, counted send, and queue ownership.
- Base `OnButtonClick` proves callback slot, argument, and void consumption.
- Outgoing request and incoming subtype-9 route close the protocol lifecycle.
- The raw duplicate has identical semantics but no route, leaving one live source owner.
- Current class and source graph already provide correct declaration/definition layering.

## IDA MCP Facts

- Function: `ClanAppearNameInputDialog__OnSubmitText` at `[0x004893e0,0x004894ce)`, `0xee` bytes, 76 instruction heads, six basic blocks, cyclomatic complexity 3.
- Type: `void __thiscall(void *this, const wchar_t *text)`.
- Body SHA256: `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`.
- First 16 bytes: `55 8B EC 81 EC 84 01 00 00 A1 24 2F 67 00 33 C5`.
- Last 16 bytes: `E8 6C E2 13 00 8B E5 5D C2 04 00 E8 87 E1 13 00`.
- Function comments: AR absent; AP absent; FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`; FP absent.
- Vtable slot `0x00615c74`: four-byte unnamed/untyped data, value `0x004893e0`, AR absent, AP absent.
- Vtable window `[0x00615c6c,0x00615c80)` bytes: `E0 F2 49 00 00 FC 49 00 E0 93 48 00 84 4F 64 00 7B C2 48 00`.
- Type catalog query `*ClanAppearNameInputDialog*` returned zero rows.

## Function / Child Inventory

| Range/item | Kind | Disposition |
| --- | --- | --- |
| `[0x004893a0,0x004893d5)` | Raw constructor child UID0002NZ | Separate 53-byte source constructor evidence; not part of target. |
| `[0x004893d5,0x004893e0)` | Alignment | Eleven `cc` bytes; outside target. |
| `[0x004893e0,0x004894ce)` | Modeled virtual method UID0002O0 | Complete target source body. |
| `[0x004894ce,0x004894d0)` | Alignment | Two `cc` bytes; outside target. |
| `[0x004894d0,0x00489505)` | Raw constructor child UID0002O1 | Separate ChangeName constructor evidence; not part of target. |
| `[0x00489510,0x004895fe)` | Modeled sibling UID0002O2 | Separate subtype-10 submitter. |
| `[0x004860e0,0x004861ce)` | Retained raw semantic duplicate | No-route subtype-9/action-1 duplicate; covered by target, no second emission. |

Exact target callees: `GetMemoryMan 0x00516030`, `PacketBufferWriteUInt8 0x00575380`, `WideCharToMultiByte` IAT `0x0060d170`, `MemoryMan_MemmoveWrapper 0x00516220`, `Socket_QueueAndSendPacket 0x00574bb0`, `__security_check_cookie 0x005c772f`, and `__report_rangecheckfailure 0x005c7655`.

## Direct Xref / Caller Inventory

- Inbound target xrefs: exactly one data xref `0x00615c74 -> 0x004893e0`.
- Ordinary code callers: zero.
- External inbound references to all 76 instruction heads: exactly the same one-entry vtable set; no interior code/data refs.
- Start VA pattern `e0 93 48 00` occurs once at `0x00615c74`. Start RVA `e0 93 08 00` and raw offset `e0 87 08 00` occur zero times.
- End VA `ce 94 48 00`, RVA `ce 94 08 00`, and raw offset `ce 88 08 00` occur zero times. Start/end immediate searches return zero.
- Raw duplicate start/end has no modeled function and zero inbound xrefs/pointer routes.

## Documentation Evidence And IDA Status

- The target page now has the accepted owner/emitter/source identity, current body hash, complete frame/API/protocol evidence, compiler-instrumentation distinction, formal human-source CPP, and `94/94` metadata.
- [UID:000023] now has the accepted class inheritance/declaration/child layering, exact method detail, retained raw-constructor caveat, and `93/93` metadata.
- UID00010K correctly remains a non-emitting `85/89` aggregate; its UID0002O0 row and dedicated evidence section now match the completed family-member depth.
- UID00021L already preserves the raw duplicate/covered-by decision at same-or-greater detail.
- `Clan.md` now preserves the correct route and class row plus the accepted exact body/API/compiler/protocol closure without changing its `90/85` file-level metadata.
- Current IDA already has a good function name, return/calling convention, wide-text argument type, and a short accurate FR comment. Stack names remain raw, receiver type is generic, and the vtable slot lacks a comment.

## Ranked Ownership Analysis

### 1. ClanAppearNameInputDialog / Clan.cpp

- Sole vtable pointer, derived declaration, neighboring constructor, base callback slot, protocol subtype, current emitter graph, and generated output all agree.
- Probability: very high. Selected.

### 2. Coordinated ClanDialogs source split

- Modal-family clustering makes a historical split conceivable, but current UID0000IA is documentation-only and no source-layout artifact supports moving this one method.
- Probability: low for current routing. Rejected for this pass.

### 3. File-local packet helper, raw duplicate, PacketBuffer, Socket, or no owner

- Vtable ownership directly contradicts a free helper/no-owner interpretation. PacketBuffer and Socket are dependencies, not method owners. The raw body has no route.
- Probability: negligible. Rejected.

### Proposed new file/grouping, if applicable

- None.

## Source Placement

- Direct source owner/emitter: [UID:000023] `ClanAppearNameInputDialog`.
- Compilation-unit owner: [UID:0000I8] `Clan`.
- Definition destination: `NexusTK/social/Clan.cpp`.
- Declaration destination: class formal H -> `NexusTK/social/Clan.h`.
- Target formal H remains blank so the declaration is not duplicated.
- UID00010K remains an evidence/index aggregate and UID00021L remains a covered-by raw strip.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and indivisible: one modeled `0xee` function.
- Pre-alignment `[0x004893d5,0x004893e0)` and post-alignment `[0x004894ce,0x004894d0)` are excluded.
- Raw constructors on both sides remain separate exact children.
- No split, merge, range extension, or child creation is warranted.
- The retained raw duplicate is semantic duplicate evidence, not a child of this range and not a second emitter.

## Negative Evidence Summary

- No ordinary callers and no interior references.
- No start/end RVA, raw-offset, or immediate route beyond the one vtable VA pointer.
- No local `ClanAppearNameInputDialog` UDT.
- No original lexical symbols.
- No evidence for an authored explicit range-runtime call, destination-first writer, meaningful sender return, file-local free helper, one-off `ClanDialogs.cpp` migration, or duplicate raw emission.
- No evidence that the class's raw-constructor no-entry caveat affects the separately vtable-live submit method.
- These negatives are fully investigated and do not block target reconstruction or `94/94`.

## IDA Rename / Type / Comment Recommendations

All rows are declarative supervisor-owned Gate 2B handoff. B006 performed no mutation. A future supervisor must fresh-attest the canonical runtime, reread every literal prestate, and stop on mismatch. The report does not contain an operational transaction, backup, rollback, or save package.

Complete current physical frame:

| Frame ID | Name | Offset | Width | Type |
| --- | --- | --- | --- | --- |
| F01 | `MultiByteStr` | `+0x8` | `0x100` | `CHAR[256]` |
| F02 | `Src` | `+0x108` | `0x1` | `_BYTE` |
| F03 | `destination` | `+0x109` | `0x1` | `unsigned __int8` |
| F04 | `var_82` | `+0x10a` | `0x1` | `unsigned __int8` |
| F05 | `var_81` | `+0x10b` | `0x1` | `unsigned __int8` |
| F06 | `var_80` | `+0x10c` | `0x7c` | `_BYTE[124]` |
| F07 | `var_4` | `+0x188` | `0x4` | `_DWORD` |
| F08 | `__saved_registers` | `+0x18c` | `0x4` | `_DWORD` |
| F09 | `__return_address` | `+0x190` | `0x4` | `_UNKNOWN *` |
| F10 | `lpWideCharStr` | `+0x194` | `0x4` | `LPCWCH` |

Rows A01-A08 are individually self-contained. A01-A07 each bind the current public `rename` endpoint to one literal `batch.stack` item and explicitly place `dry_run:false`, `stop_on_error:true`, and `allow_overwrite:false` inside `batch`; `batch.pure` is omitted because pure mode does not support stack renames. A08 binds the current public `set_function_comments` endpoint to one literal `items` entry. Dependency order is mandatory, but no row relies on an abbreviated predecessor reference for its authority.

| ID | Classification | Literal prestate | Public endpoint action | Exact poststate | Stop/protection |
| --- | --- | --- | --- | --- | --- |
| A01 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `MultiByteStr@+0x8/0x100/CHAR[256]; Src@+0x108/1/_BYTE; destination@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"MultiByteStr",new:"convertedName"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; Src@+0x108/1/_BYTE; destination@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. Only F01 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, decompiler-local substitution, row addition/removal, offset/width/type change, body/range/hash/xref/caller/comment change, or any unrelated delta. |
| A02 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; Src@+0x108/1/_BYTE; destination@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"Src",new:"packetOpcode"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; destination@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. Only F02 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, decompiler-local substitution, fragment coalescence, row addition/removal, offset/width/type change, body/range/hash/xref/caller/comment change, or any unrelated delta. |
| A03 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; destination@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"destination",new:"packetSubtype"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. Only F03 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, any type action, fragment coalescence, row addition/removal, offset/width/type change, body/range/hash/xref/caller/comment change, or unrelated delta. |
| A04 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; var_82@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"var_82",new:"packetAction"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. Only F04 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, row addition/removal, offset/width/type change, fragment coalescence, body/range/hash/xref/caller/comment change, or any unrelated delta. |
| A05 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; var_81@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"var_81",new:"packetNameLength"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. Only F05 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, row addition/removal, offset/width/type change, fragment coalescence, body/range/hash/xref/caller/comment change, or any unrelated delta. |
| A06 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; var_80@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"var_80",new:"packetNameBytes"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; packetNameBytes@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. Only F06 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, row addition/removal, offset/width/type change, creation/reshaping of a physical 128-byte item, body/range/hash/xref/caller/comment change, or unrelated delta. |
| A07 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; packetNameBytes@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; lpWideCharStr@+0x194/4/LPCWCH`. | Public `rename` payload: `batch.stack:[{func_addr:"0x004893e0",old:"lpWideCharStr",new:"text"}]`, `batch.dry_run:false`, `batch.stop_on_error:true`, `batch.allow_overwrite:false`; no `batch.pure`. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; packetNameBytes@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; text@+0x194/4/LPCWCH`. Only F10 physical name changes. | Hard stop on missing old row, collision, overwrite request, endpoint failure, any `set_type` action, physical typedef change, row addition/removal, offset/width/type change, body/range/hash/xref/caller/comment change, or unrelated delta. |
| A08 | apply | Exact entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `Converts the submitted name with CP_ACP and sends clan packet {0x4b,9,1,length,name...}.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; packetNameBytes@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; text@+0x194/4/LPCWCH`. | Public `set_function_comments` payload: `items:[{addr:"0x004893e0",comment:"ClanAppearNameInputDialog::OnSubmitText converts the submitted name with CP_ACP, builds {0x4b,9,1,length,name...}, and queues convertedLength+4 bytes; the observed 0x100 and post-copy 0x80 failures are compiler range instrumentation around indexed terminator writes."}]`. This endpoint has no `batch` wrapper. | Exact poststate entity `0x004893e0`, range `[0x004893e0,0x004894ce)`, name `ClanAppearNameInputDialog__OnSubmitText`, prototype `void __thiscall(void *this,const wchar_t *text)`, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole xref `0x00615c74 -> 0x004893e0`, zero callers; AR absent, AP absent, FR `ClanAppearNameInputDialog::OnSubmitText converts the submitted name with CP_ACP, builds {0x4b,9,1,length,name...}, and queues convertedLength+4 bytes; the observed 0x100 and post-copy 0x80 failures are compiler range instrumentation around indexed terminator writes.`, FP absent; frame `convertedName@+0x8/0x100/CHAR[256]; packetOpcode@+0x108/1/_BYTE; packetSubtype@+0x109/1/unsigned __int8; packetAction@+0x10a/1/unsigned __int8; packetNameLength@+0x10b/1/unsigned __int8; packetNameBytes@+0x10c/0x7c/_BYTE[124]; var_4@+0x188/4/_DWORD; __saved_registers@+0x18c/4/_DWORD; __return_address@+0x190/4/_UNKNOWN *; text@+0x194/4/LPCWCH`. Only FR changes. | Hard stop on endpoint failure, AR/AP/FP change, frame/name/type/body/range/hash/xref/caller change, decompiler-comment creation, or any unrelated delta. |
| A09 | apply | A08 poststate; vtable `0x00615c74` unnamed/untyped four-byte data value `0x004893e0`; AR absent; AP absent. | `set_address_comments` at `0x00615c74` with `ClanAppearNameInputDialog::OnSubmitText virtual slot -> 0x004893e0.` | Only vtable AR equals exact text; AP absent; name/type/value/bytes/head unchanged. | Stop on pointer, bytes, type, name, head, AP, or neighboring-slot delta. |

Protected/no-change records:

| ID | Classification | Literal prestate and required poststate |
| --- | --- | --- |
| P01 | no change recommended | Preserve `[0x004893e0,0x004894ce)`, 238 bytes, SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, exact first/last 16 bytes, and all instruction heads. |
| P02 | no change recommended | Preserve exactly one inbound data xref `0x00615c74 -> 0x004893e0`, zero ordinary callers, and no interior external refs. |
| P03 | no change recommended | Preserve F01-F10 offsets, widths, and types exactly; permit only A01-A07 names. No row addition/removal/coalescence and no stack `set_type`. |
| P04 | no change recommended | Preserve vtable window bytes `E0 F2 49 00 00 FC 49 00 E0 93 48 00 84 4F 64 00 7B C2 48 00`, slot value/head/name/type/AP, permitting only A09 AR. |
| P05 | no change recommended | Preserve eleven-byte pre-alignment, two-byte post-alignment, raw constructor heads `0x004893a0`/`0x004894d0`, and next modeled sibling `0x00489510`. |
| P06 | no change recommended | Preserve current function name `ClanAppearNameInputDialog__OnSubmitText` and type `void __thiscall(void *this,const wchar_t *text)`. Do not install a speculative UDT or call `set_type`; source-facing class type remains documented in formal C++/H. |
| P07 | no change recommended | Preserve exact callees and 24 existing internal regular comments at `0x489405,0x489406,0x489413,0x489414,0x489421,0x489422,0x48943c,0x48943e,0x489440,0x48944d,0x489450,0x489451,0x489452,0x489454,0x489474,0x489475,0x489484,0x489486,0x489487,0x48948b,0x48949c,0x4894a8,0x4894a9,0x4894bb`; preserve every unrelated entity. |

## First-Draft C++ Recommendation

Applied formal CPP:

```cpp
void ClanAppearNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x09, packet + 1);
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

Formal H recommendation: keep the target child H channel blank. [UID:000023] already owns:

- `class ClanAppearNameInputDialog : public ClanNameInputDialog`;
- `explicit ClanAppearNameInputDialog(const unsigned char *packet);`;
- `virtual void OnSubmitText(const wchar_t *text);`.

This C++ is behaviorally faithful and plausible human-written source for the target era. It intentionally omits compiler cookie/range-runtime syntax while retaining the exact source constructs that produce those checks.

## Final Recommendation

- C2O0-001 through C2O0-047 are applied in the named ordinary docs and verified by scoped validation and physical reread.
- Keep C2O0-048 through C2O0-051 supervisor-owned. Generated `Clan.cpp`/`Clan.h` were physically reread for this callback, but those four rows remain unchecked under the accepted allocation because manual coverage/tracker closure is supervisor-owned.
- Keep C2O0-052 through C2O0-067 supervisor-owned for Gate 2B.
- C2O0-068 through C2O0-071 are complete; C2O0-072 and C2O0-073 remain supervisor-owned manual-coverage validation.
- Do not split, duplicate, re-own, or re-route the method.
- The report closes all source-quality questions; no future-investigation placeholder is needed.

## Recommended Target Doc Changes

- Applied `94/94` while preserving all routing metadata.
- Installed formal CPP exactly from Section 22 and kept H blank.
- Added exact identity/hash/boundaries, complete frame/source shape, xref/route audit, dependency inventory, packet field/order, conversion, compiler guards, send ownership, protocol lifecycle, sibling/duplicate analysis, source placement, historical reconciliation, and score rationale.
- Replaced stale/helper-uncertain language with the resolved value-first/void/Socket-owned contracts.
- Preserved the old hash and explicit-runtime version only as clearly historical/superseded evidence.

## Recommended Support Doc Changes

- [UID:000023] `by-class/ClanAppearNameInputDialog.md`: applied `93/93`; preserved owner/emitter UID0000I8, declaration H, and `[[CHILDREN]]`; added exact target method hash/route/API/compiler/protocol detail and retained the separate raw-constructor caveat.
- [UID:00010K] `ClanNameDialogSubmitters`: preserved `85/89`, non-reconstructable state, and blank owner/emitter; upgraded the UID0002O0 row and added a target-specific evidence subsection parallel to UID0002NW/UID0002NY.
- [UID:0000I8] `by-file/Clan.md`: preserved `90/85` and expanded the ClanAppear row with exact body/source facts.
- [UID:00021L] raw helper strip: no change; target duplicate/covered-by detail is already present.
- PacketBuffer/memmove/queue/global supports: no change; contracts are already present at same-or-greater detail.
- `ClanDialogs.md` and `ClanInputDialogLayouts.md`: no change; current index/layout dispositions remain correct.

## Score And Metadata Recommendation

| UID | Current | Recommended | Routing | Rationale |
| --- | --- | --- | --- | --- |
| 0002O0 | Historical assignment `86/91`; applied/current `94/94` | `94/94` applied | Keep owner/emitter 000023, reconstructable true | Exact behavior, ABI, frame, packet, compiler shape, queue semantics, protocol, duplicate resolution, source placement, and formal CPP are closed. |
| 000023 | Historical assignment `86/90`; applied/current `93/93` | `93/93` applied | Keep owner/emitter 0000I8, reconstructable true | Declaration, constructor child, method child, vtable identity, and generated H/CPP route are complete; retained constructor no-entry evidence prevents 95+. |
| 00010K | `85/89` | keep | Keep non-emitting aggregate | Target detail improves, but raw-family aggregate limits remain. |
| 0000I8 | `90/85` | keep | Keep file owner/path | This target does not close the whole large compilation unit's remaining uncertainty. |
| 00021L | `86/91` | keep | Keep Clan covered-by marker | No new live route was found. |

- Reason not higher than `94/94`: original lexical symbols and exact historical source spellings are stripped, so `OnSubmitText` and the local names remain high-probability evidence-based inference rather than recovered symbol proof. The accepted formal implementation and generated CPP/H route are now applied and physically verified, so they no longer cap the score.
- Reason not lower than `94/94`: the exact body and boundaries, sole vtable route, void member ABI, complete physical frame, packet bytes and API order, CP_ACP conversion, compiler-guard placement, queue ownership/return semantics, protocol lifecycle, raw-duplicate disposition, owner/emitter, source placement, and formal CPP are independently closed.

## Open Questions With Attempted Resolution

| Question | Evidence exhausted | Resolution |
| --- | --- | --- |
| Original lexical names | Current symbols, siblings, class docs, decompilation, frame roles, and source-era style. | Highest-probability names in Section 22; no raw IDA names in final source. |
| Return type/callback signature | Current type, body, vtable, base dispatch, sibling leaves. | Fully resolved as void member callback. |
| PacketBuffer order | Current helper type/body and target pushes. | Fully resolved as value-first. |
| Explicit guards in source | Exact branch placement, indexed writes, sibling source analysis, runtime target. | Fully resolved as compiler instrumentation, not authored calls. |
| Sender result/ownership | Queue helper type/body and command path. | Fully resolved as void copy-and-queue. |
| Raw duplicate | Raw disassembly plus all route scans and live counterpart. | Fully resolved as retained no-route duplicate, no second emitter. |
| Receiver UDT in IDA | Current type catalog and public-action determinism requirements. | Source type is resolved; unsafe IDA UDT/type enrichment is explicitly no-change. |
| Clan.cpp vs ClanDialogs.cpp | Owner graph, current by-file decisions, family coupling, generated output. | Current route remains Clan.cpp; no one-off split. |

No unresolved behavior, owner, source-placement, or formal-code blocker remains. Stripped lexical/source-form uncertainty is explicitly retained as the non-blocking reason for the `94/94` ceiling. Accepted ordinary implementation, scoped validation, and generated CPP/H physical readback are complete; manual coverage, Gate 2B, and lifecycle closure remain supervisor-owned.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Replace the current UID0002O0 row in `by-memory/-coverage-report.md` with:

>         - [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) 0x004893e0-0x004894ce | function | ClanAppearNameInputDialogSubmitName : reconstructable : 94% : very strong : Exact 238-byte vtable-backed void submitter, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, sole route `0x00615c74`, zero ordinary callers, value-first `{0x4b,9,1,length,name...}` packet, exact CP_ACP conversion/copy/compiler-guard order, Socket-owned counted queue copy, class owner/emitter, human-source CPP, and `social/Clan.cpp` placement.

Replace the current UID000023 row in `by-class/-coverage-report.md` with:

> - [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md) : reconstructable : 93% : very strong : Source-ready `ClanNameInputDialog`-derived declaration with exact packet-forwarding constructor child, exact 238-byte vtable-backed `OnSubmitText` child, subtype-9 request/open/submit lifecycle, owner/emitter routing through `Clan.cpp`/`Clan.h`, and only the retained raw-constructor no-entry caveat below the 95 barrier.

Generated research-tracker and generated coverage rows must be refreshed through the documented validator workflow, never manually edited.

## Follow-Up Actions

1. Supervisor performs fresh exact-artifact Gate 1 and Gate 2A against the accepted ordinary callback.
2. Supervisor applies and validates the exact manual coverage text in Section 28 and refreshes/rechecks generated tracker/coverage state.
3. Supervisor performs Gate 2B only from fresh canonical runtime/prestate authority and only for A01-A09/P01-P07.
4. Only the supervisor may run `execute_report` and archive the report.

## Confidence

- Identity/range/body: very high.
- Vtable/reachability: very high.
- Behavior/packet/conversion/order: very high.
- Compiler/source-shape interpretation: high.
- Queue ownership/return: very high.
- Class/source ownership: very high.
- Human lexical spelling: high-probability inference, appropriate for stripped-source reconstruction.
- Recommended target score: `94/94`.

## Validator Results

- Target validation: command `000000024421`, `2026-08-15T19:23:41-04:00`, scoped file mode with `--apply --queue-timeout 240`; exit `0`, `ok:1`.
- Class validation: command `000000024422`, `2026-08-15T19:24:02-04:00`, scoped file mode with `--apply --queue-timeout 240`; exit `0`, `ok:1`.
- Aggregate validation: command `000000024423`, `2026-08-15T19:24:09-04:00`, scoped file mode with `--apply --queue-timeout 240`; exit `0`, `ok:1`.
- Owning `Clan.md` validation: command `000000024424`, `2026-08-15T19:24:26-04:00`, scoped file mode with `--apply --queue-timeout 240 --wait-generated`; exit `0`, `ok:1`, generated refresh completed.
- Command `000000024421` normalized one target UID link; the final target identity in Section 4 and Section 31 is the physically reread post-validator artifact.
- Manual coverage validators were not run because C2O0-048/C2O0-049/C2O0-072/C2O0-073 remain supervisor-owned and unchecked.
- Validator warnings for missing UID references `000411`, `000412`, and `0003B8` in `Clan.md`, plus unrelated generated child-marker/emitter/header diagnostics, pre-existed this target callback and did not invalidate the four scoped passes.

## Changed Files

- Updated `by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md`: SHA256 `15E39E57F83F7C6F2BB6B9441312E6E415BF39D92A755F32562BAED7FFAC477D`, 18,457 bytes / 185 lines.
- Updated `by-class/ClanAppearNameInputDialog.md`: SHA256 `0BF8233CB18592ACD848AC58AD52C1FC701A17476919AED06405784C766CE45D`, 15,725 bytes / 119 lines.
- Updated `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`: SHA256 `A5CE91EEAEE680A1073FBAFCE9043F3EC4B6D879D99A620C95666166A7264B3F`, 38,690 bytes / 242 lines.
- Updated `by-file/Clan.md`: SHA256 `8BA09849A532F4F3DECB56CB4E9AE1F7299EA4A8CF6C768C7FC9E7C432054A39`, 134,373 bytes / 500 lines.
- Reconciled this same report after the accepted callback. Its final identity is established by the return audit after all report edits.
- No manual coverage, generated, tracker, audit, catalog, lifecycle, goal, or notes file was directly edited.
- No IDA mutation or save occurred.
- No executed-report or lifecycle command ran.

## Implementation Tracking Checklist

Canonical parity contract: every row below mirrors Section 11 in identical order and with identical Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, and Verification state fields. Accepted callback allocation is 52 checked and 22 unchecked supervisor-owned rows.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C2O0-001 | 0002O0 | Record exact modeled range `[0x004893e0,0x004894ce)` and size `0xee` / 238. | very high | Current function/item queries. | Target / range and identity | incorporate | applied |
| [x] | C2O0-002 | 0002O0 | Record body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8` and exact edge bytes. | very high | Canonical PE body bytes. | Target / body identity | incorporate | applied |
| [x] | C2O0-003 | 0002O0 | Exclude eleven-byte `cc` pre-alignment `[0x004893d5,0x004893e0)`. | very high | Bounded bytes/items. | Target / boundary | incorporate | applied |
| [x] | C2O0-004 | 0002O0 | Exclude two-byte `cc cc` post-alignment `[0x004894ce,0x004894d0)`. | very high | Bounded bytes/items. | Target / boundary | incorporate | applied |
| [x] | C2O0-005 | 0002O0 | Record current function name `ClanAppearNameInputDialog__OnSubmitText` as source-compatible IDA identity. | very high | Current function query. | Target / IDA state | incorporate | applied |
| [x] | C2O0-006 | 0002O0 | Resolve source ABI as void virtual member `OnSubmitText(const wchar_t *text)`. | very high | Vtable, base dispatch, current type, no-return body. | Target / callback ABI | incorporate | applied |
| [x] | C2O0-007 | 0002O0 | Record the complete ten-row physical frame and contiguous human-source array interpretation. | very high | Current stack frame and accesses. | Target / frame and source shape | incorporate | applied |
| [x] | C2O0-008 | 0002O0 | Record sole inbound data xref `0x00615c74 -> 0x004893e0`. | very high | Current xref query. | Target / vtable route | incorporate | applied |
| [x] | C2O0-009 | 0002O0 | Record zero ordinary code callers without classifying the virtual method as dead. | very high | Caller/xref queries. | Target / reachability | incorporate | applied |
| [x] | C2O0-010 | 0002O0 | Record all-head external inbound union as exactly the sole vtable xref. | very high | 76 bounded head queries. | Target / interior-xref audit | incorporate | applied |
| [x] | C2O0-011 | 0002O0 | Record zero start/end RVA, raw-offset, and immediate routes beyond the vtable VA pointer. | very high | Pointer/immediate scans. | Target / route audit | incorporate | applied |
| [x] | C2O0-012 | 0002O0 | Record the exact seven semantic/compiler callees and no strings. | very high | Callee/string queries. | Target / dependency inventory | incorporate | applied |
| [x] | C2O0-013 | 0002O0 | Record opcode `0x4b` at packet offset 0. | very high | First byte-writer call. | Target / packet layout | incorporate | applied |
| [x] | C2O0-014 | 0002O0 | Record subtype `0x09` at packet offset 1. | very high | Second byte-writer call. | Target / packet layout | incorporate | applied |
| [x] | C2O0-015 | 0002O0 | Record submit action `0x01` at packet offset 2. | very high | Third byte-writer call. | Target / packet layout | incorporate | applied |
| [x] | C2O0-016 | 0002O0 | Record narrowed converted-name length byte at packet offset 3. | very high | Fourth byte-writer call. | Target / packet layout | incorporate | applied |
| [x] | C2O0-017 | 0002O0 | Record converted payload beginning at packet offset 4. | very high | Memmove arguments. | Target / packet layout | incorporate | applied |
| [x] | C2O0-018 | 0002O0 | Record exact CP_ACP conversion arguments and `wcslen(text)` semantics. | very high | WinAPI call sequence. | Target / conversion | incorporate | applied |
| [x] | C2O0-019 | 0002O0 | Classify the `0x100` failure branch as compiler instrumentation. | very high | Indexed write and runtime target. | Target / first guard | incorporate | applied |
| [x] | C2O0-020 | 0002O0 | Preserve `convertedName[convertedLength] = 0` without authored runtime call. | high | Human-source/compiler-shape analysis. | Target formal CPP | incorporate | applied |
| [x] | C2O0-021 | 0002O0 | Preserve length write followed by payload copy. | very high | Exact instruction/call order. | Target / operation order | incorporate | applied |
| [x] | C2O0-022 | 0002O0 | Classify the post-copy `0x80` failure branch as compiler instrumentation. | very high | Indexed write and runtime target. | Target / second guard | incorporate | applied |
| [x] | C2O0-023 | 0002O0 | Preserve `packet[packetLength] = 0` after copy without authored runtime call. | high | Human-source/compiler-shape analysis. | Target formal CPP | incorporate | applied |
| [x] | C2O0-024 | 0002O0 | Record exact sent length `convertedLength + 4`. | very high | Sender call arguments. | Target / send length | incorporate | applied |
| [x] | C2O0-025 | 0002O0 | Record both source arrays and scratch NULs as caller-stack-owned and outside sent length. | very high | Frame and counted send. | Target / ownership | incorporate | applied |
| [x] | C2O0-026 | 0002O0 | Record Socket-owned queued copy, queue terminator, command 8, and void return. | very high | Current queue helper body/type. | Target / queue semantics | incorporate | applied |
| [x] | C2O0-027 | 0002O0 | Record base control path reading text and dispatching primary vtable slot `+0x5c` without consuming a return. | very high | Base `OnButtonClick` disassembly. | Target / virtual callback route | incorporate | applied |
| [x] | C2O0-028 | 0002O0 | Record row-10 request `{0x4b,9,0}`. | very high | Current row-action disassembly. | Target / protocol request | incorporate | applied |
| [x] | C2O0-029 | 0002O0 | Record incoming opcode `0x43` subtype-9 action/result 0 dialog-open route. | very high | Current dispatcher case 9. | Target / protocol open | incorporate | applied |
| [x] | C2O0-030 | 0002O0 | Record subtype-9 nonzero action/result as accepted no-open completion path. | high | Case-9 conditional/default flow. | Target / protocol completion | incorporate | applied |
| [x] | C2O0-031 | 0002O0 | Compare exact name siblings 7/8/10 and reject money-only `_wtol`/UInt32BE carryover. | very high | Current family bodies. | Target / family comparison | not-applicable | excluded-with-reason |
| [x] | C2O0-032 | 0002O0 | Record raw `[0x004860e0,0x004861ce)` as a no-route duplicate covered by this live body. | very high | Raw disassembly and zero-route checks. | Target / duplicate reconciliation | incorporate | applied |
| [x] | C2O0-033 | 0002O0 | Keep canonical owner UID000023. | very high | Sole class-vtable route. | Target metadata / owner | already-present | already-present |
| [x] | C2O0-034 | 0002O0 | Keep emitter UID000023 and reconstructable true. | very high | Complete class method and emitter graph. | Target metadata / emitter | already-present | already-present |
| [x] | C2O0-035 | 0002O0 | Keep source route UID000023 -> UID0000I8 -> `social/Clan.cpp`. | high | Current family/source graph. | Target / source placement | already-present | already-present |
| [x] | C2O0-036 | 0002O0 | Replace formal CPP with Section 22 exact human-source body. | high | Closed behavior and source-shape analysis. | Target formal CPP | incorporate | applied |
| [x] | C2O0-037 | 0002O0 | Keep target formal H blank because UID000023 owns the declaration. | very high | Emitter layering and current class H. | Target formal H | not-applicable | excluded-with-reason |
| [x] | C2O0-038 | 0002O0 | Raise target `86/91 -> 94/94` with routing unchanged. | high | All target blockers resolved. | Target metadata / scores | incorporate | applied |
| [x] | C2O0-039 | 0002O0 | Reject stale hash `4FEF...` as current authority and preserve it only as dated historical evidence. | very high | Current exact body SHA differs. | Target / history | reject-stale | applied |
| [x] | C2O0-040 | 0002O0 | Reject explicit `__report_rangecheckfailure` source blocks while preserving observed compiler checks. | high | Compiler/source-shape analysis. | Target / history and formal CPP | reject-stale | applied |
| [x] | C2O0-041 | 0002O0 | Replace broad target prose with exhaustive range/frame/API/protocol/ownership evidence. | high | Current target audit. | Target / all evidence sections | incorporate | applied |
| [x] | C2O0-042 | 0002O0 | Raise UID000023 `86/90 -> 93/93` and incorporate exact child evidence while retaining raw-constructor caveat. | high | Complete class declaration plus 92/93 constructor and 94/94 method. | by-class/ClanAppearNameInputDialog.md | incorporate | applied |
| [x] | C2O0-043 | 0002O0 | Add a UID0002O0-specific family evidence subsection without changing UID00010K's non-emitting `85/89` state. | high | Aggregate is correct but target row is shallow. | ClanNameDialogSubmitters aggregate | incorporate | applied |
| [x] | C2O0-044 | 0002O0 | Expand the Clan by-file row with exact target hash/API/compiler/protocol/owner facts without changing `90/85`. | high | Current by-file row is shallow. | by-file/Clan.md | incorporate | applied |
| [x] | C2O0-045 | 0002O0 | Verify UID00021L already records the raw subtype-9 action-1 duplicate and covered-by route. | very high | Current raw-strip page. | ClanNameActionPacketHelpers | already-present | already-present |
| [x] | C2O0-046 | 0002O0 | Verify PacketBuffer, memmove, queue/send, and sender-global support contracts already exist at same-or-greater detail. | very high | Current support pages. | Helper/global support docs | already-present | already-present |
| [x] | C2O0-047 | 0002O0 | Preserve class-owned C++98-compatible `virtual void` declaration; do not add `override` or duplicate child H. | high | Current class H and source-era style. | Class H / target H | already-present | already-present |
| [ ] | C2O0-048 | 0002O0 | Supervisor replaces stale manual by-memory coverage row with Section 28's exact 94% text. | high | Current row is 82%. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C2O0-049 | 0002O0 | Supervisor replaces stale manual class coverage row with Section 28's exact 93% text. | high | Current row is 84%. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C2O0-050 | 0002O0 | Supervisor refreshes/rechecks research tracker and generated coverage after callback. | high | Generated rows reflect old scores/report coverage. | Generated reports | incorporate | proposed |
| [ ] | C2O0-051 | 0002O0 | Supervisor rereads generated `Clan.cpp`/`Clan.h` for exact body/declaration and current hashes. | high | Generated files are validator-owned. | Generated Clan CPP/H | incorporate | proposed |
| [ ] | C2O0-052 | 0002O0 | Gate 2B renames `MultiByteStr` to `convertedName` only under A01. | high | Exact conversion-array role. | IDA A01 | incorporate | proposed |
| [ ] | C2O0-053 | 0002O0 | Gate 2B renames `Src` to `packetOpcode` only under A02. | high | Exact packet offset-0 role. | IDA A02 | incorporate | proposed |
| [ ] | C2O0-054 | 0002O0 | Gate 2B renames `destination` to `packetSubtype` only under A03. | high | Exact packet offset-1 role. | IDA A03 | incorporate | proposed |
| [ ] | C2O0-055 | 0002O0 | Gate 2B renames `var_82` to `packetAction` only under A04. | high | Exact packet offset-2 role. | IDA A04 | incorporate | proposed |
| [ ] | C2O0-056 | 0002O0 | Gate 2B renames `var_81` to `packetNameLength` only under A05. | high | Exact packet offset-3 role. | IDA A05 | incorporate | proposed |
| [ ] | C2O0-057 | 0002O0 | Gate 2B renames `var_80` to `packetNameBytes` only under A06. | high | Exact payload-tail role. | IDA A06 | incorporate | proposed |
| [ ] | C2O0-058 | 0002O0 | Gate 2B renames `lpWideCharStr` to `text` only under A07. | high | Exact callback-argument role. | IDA A07 | incorporate | proposed |
| [ ] | C2O0-059 | 0002O0 | Gate 2B replaces only the function-regular comment under A08. | high | Closed target behavior. | IDA A08 | incorporate | proposed |
| [ ] | C2O0-060 | 0002O0 | Gate 2B sets only the vtable-slot regular address comment under A09. | high | Sole virtual route. | IDA A09 | incorporate | proposed |
| [ ] | C2O0-061 | 0002O0 | Gate 2B preserves exact target body/range/hash under P01. | very high | Literal current bytes/range. | IDA P01 | already-present | proposed |
| [ ] | C2O0-062 | 0002O0 | Gate 2B preserves exact xref/caller sets under P02. | very high | Literal current route sets. | IDA P02 | already-present | proposed |
| [ ] | C2O0-063 | 0002O0 | Gate 2B preserves all frame offsets/widths/types and permits only A01-A07 names under P03. | very high | Complete current frame. | IDA P03 | already-present | proposed |
| [ ] | C2O0-064 | 0002O0 | Gate 2B preserves vtable bytes/value/name/type/repeatable channel under P04. | very high | Current vtable window/item. | IDA P04 | already-present | proposed |
| [ ] | C2O0-065 | 0002O0 | Gate 2B preserves both alignment intervals and neighboring item heads under P05. | very high | Current boundaries/items. | IDA P05 | already-present | proposed |
| [ ] | C2O0-066 | 0002O0 | Gate 2B preserves current function name/type and makes no unsafe receiver-UDT type action under P06. | high | Source ABI resolved; target UDT absent. | IDA P06 | already-present | proposed |
| [ ] | C2O0-067 | 0002O0 | Gate 2B preserves callees, internal comments, non-target comment channels, and all unrelated state under P07. | very high | Current dependency/comment inventory. | IDA P07 | already-present | proposed |
| [x] | C2O0-068 | 0002O0 | Validate the target ordinary page after callback. | high | Required scoped validation. | Target validator receipt | incorporate | applied |
| [x] | C2O0-069 | 0002O0 | Validate the class ordinary page after callback. | high | Required scoped validation. | Class validator receipt | incorporate | applied |
| [x] | C2O0-070 | 0002O0 | Validate the family aggregate ordinary page after callback. | high | Required scoped validation. | Aggregate validator receipt | incorporate | applied |
| [x] | C2O0-071 | 0002O0 | Validate the Clan by-file ordinary page after callback. | high | Required scoped validation. | Clan validator receipt | incorporate | applied |
| [ ] | C2O0-072 | 0002O0 | Supervisor validates manual target coverage after applying exact text. | high | Coverage is supervisor-owned. | Target coverage validator receipt | incorporate | proposed |
| [ ] | C2O0-073 | 0002O0 | Supervisor validates manual class coverage after applying exact text. | high | Coverage is supervisor-owned. | Class coverage validator receipt | incorporate | proposed |
| [x] | C2O0-074 | 0002O0 | Preserve the dated report-only no-edit/no-validator/no-IDA boundary as historical pre-callback evidence; ordinary implementation and scoped validators were later applied under the accepted callback while IDA and lifecycle remained untouched. | very high | Historical assignment boundary plus current changed-file and validator receipts. | Report lifecycle boundary / callback history | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000024432","destination_path":"executed-b-agent-research/B006/0002O0-ClanAppearNameInputDialogSubmitName-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002O0-ClanAppearNameInputDialogSubmitName-source-quality.md","timestamp":"2026-08-15T20:00:19-04:00","uid":"0002O0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
