** TARGET-REPORT-UID:0001MB **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MB SayInputPane Source-Quality Report

## Report Scope

- Agent: `B005`.
- Assignment: `B005-report-say-input-pane-aggregate-source-quality-0001MB-mcp-20260623`.
- Target: [UID:0001MB] `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`.
- Required output: report-only research report at `tools/leaser/Agents/Agent-B005/research/0001MB-SayInputPane-source-quality.md`.
- Current target score: `85/87`.
- Report-only status: no by-* docs edited, no `-coverage-report.md` edited, no generated/project-level files edited, no IDA DB/tool-state edits, no reports moved to `executed`, and no subagents spawned.

## Current Target State

The target is a reviewed SayInputPane method-cluster page, not a single modeled function. Current metadata:

```text
COMPLETION:85
CONFIDENCE:87
CANONICAL_OWNER:0000C3
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000C3
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Current docs already reflect the recent B003 exact-child split:

| Range | UID | Current disposition |
| --- | --- | --- |
| `0x005b3490-0x005b34d0` | [UID:0002S7] | Raw default constructor-shaped sibling, `86/89`, owned/emitted by [UID:0000C3], blank C++. |
| `0x005b34cf-0x005b34d0` | ignored padding | One `0xcc` byte after the raw constructor. |
| `0x005b34d0-0x005b356c` | [UID:000414] | Constructor overload, `87/89`, first-draft C++ present. |
| `0x005b356c-0x005b3570` | ignored padding | Four `0xcc` bytes between exact children. |
| `0x005b3570-0x005b3670` | [UID:000415] | Key/history handler, `87/89`, first-draft C++ present. |
| `0x005b3670-0x005b37ea` | [UID:000416] | Submit/send handler, `88/90`, first-draft C++ present. |
| `0x005b37ea-0x005b37f0` | ignored padding | Six `0xcc` bytes before the adjacent raw island. |
| `0x005b37f0-0x005b38d5` | [UID:0002S8] | Adjacent no-route raw packet island, `85/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++. |

The current aggregate page and support docs still cite prior MCP session `b880584f` as their active evidence basis. This report revalidates the same split with current session `ff68e691`.

## MCP Session And Binary Baseline

Lightweight MCP health/session check completed before target evidence:

- `initialize` returned HTTP `200`, server `ida-pro-mcp` `1.0.0`, protocol `2025-06-18`.
- `tools/list` returned HTTP `200`; live tools include `server_health`, `idb_list`, `lookup_funcs`, `func_profile`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `find_bytes`, `insn_query`, `decompile`, `disasm`, `survey_binary`, and mutation tools that were not used.
- `server_health(database='ff68e691')`: `status=ok`, uptime about `558` seconds at check time, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `idb_list`: one active adopted worker session, `session_id='ff68e691'`, backend `worker`, PID/worker PID `14256`, `is_analyzing=false`.
- `survey_binary(detail_level='minimal')`: PE metadata path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, arch `32`, base `0x400000`, image size `0x2b3000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

No MCP failure occurred during this pass.

## MCP Evidence Checked

### Function And Boundary Model

`lookup_funcs` on current session `ff68e691`:

| Query | Result |
| --- | --- |
| `0x005b3490` | `Not a function`. |
| `0x005b34d0` | `sub_5B34D0`, size `0x9c`. |
| `0x005b356c` | `Not a function`. |
| `0x005b3570` | `sub_5B3570`, size `0x100`. |
| `0x005b3670` | `sub_5B3670`, size `0x17a`. |
| `0x005b37ea` | `Not a function`. |
| `0x005b37f0` | `Not a function`. |
| `0x005b38d5` | `Not a function`. |
| `0x005b38e0` | `Not a function`. |
| `0x005b3940` | `sub_5B3940`, size `0x100`, next modeled ChatInputPane neighborhood function. |
| `0x005b7b80` | `sub_5B7B80`, size `0x3b`, scalar deleting destructor body. |

`func_profile` on the three source-bearing children:

| Function | Instructions / blocks | caller_count | callee_count |
| --- | --- | --- | --- |
| `0x005b34d0` | 57 / 7 | `0` | `6` profile callees; direct `callees` lists `0x004f1c00` and `0x0058fc30`. |
| `0x005b3570` | 81 / 13 | `0` | `8` profile callees; direct `callees` lists ctype narrow, `0x005a4930`, `0x005a4990`, `0x0058f2a0`, `0x0058fc30`, cookie check, and `0x004f25a0`. |
| `0x005b3670` | 111 / 13 | `0` | `12` profile callees; direct `callees` lists `0x004f2310`, `0x004f2300`, `0x00465890`, `0x005957c0`, `0x00516030`, `0x00575380`, `WideCharToMultiByte`, `0x00516220`, `0x00574bb0`, `0x005a49e0`, cookie, and range-check failure. |

Decimal/hex conversions used below were verified with `tools/int_convert.py`: `0x108` = `264`, `0xfc` = `252`, `0xa0` = `160`, `0xa4` = `164`, `0x134102` = `1261826`, `0x9c` = `156`, `0x100` = `256`, and `0x17a` = `378`.

### Byte And Padding Evidence

`get_bytes` on current session `ff68e691`:

| Range | Evidence |
| --- | --- |
| `0x005b3490-0x005b34d0` | Raw constructor bytes begin `55 8b ec 51 56 8b f1 68 54 4c 61 00 ...` and end `5e 8b e5 5d c3 cc`. |
| `0x005b34cf-0x005b34d0` | One `cc` byte. |
| `0x005b34d0-0x005b356c` | Modeled constructor overload bytes, size `0x9c` (156, verified with `int_convert.py`). |
| `0x005b356c-0x005b3570` | Four `cc cc cc cc` bytes. |
| `0x005b3570-0x005b3670` | Modeled key/history handler bytes, size `0x100` (256, verified with `int_convert.py`). |
| `0x005b3670-0x005b37ea` | Modeled submit handler bytes, size `0x17a` (378, verified with `int_convert.py`). |
| `0x005b37ea-0x005b37f0` | Six `cc cc cc cc cc cc` bytes. |
| `0x005b37f0` | Adjacent raw island starts with `55 8b ec 81 ec 30 02 00 00 ...`; still not a function and not part of [UID:0001MB]. |
| `0x00614c54` | `3e 00 20 00 00 00 00 00`, UTF-16 `L"> "` followed by terminators. |

The current MCP `get_bytes` output does not include hash fields, but the exact bytes match the previously incorporated child ranges. Existing SHA16 values in the docs (`0fc41bb510338c08`, `77317c3876917ced`, `d7c586e0ec44b7f9`) remain useful as historical byte fingerprints and should be described as prior hashes unless recomputed in a future implementation callback.

### Decompilation And Disassembly Evidence

`decompile(0x005b34d0)` confirms:

- `sub_4F1C00(this, L"> ")`.
- `*(_WORD *)(this + 264) = -1`, where `264` = `0x108` verified with `int_convert.py`.
- Three SayInputPane vtable stores to primary `this+0`, secondary `this+160` (`0xa0`, verified), and tertiary `this+164` (`0xa4`, verified).
- `sub_58FC30(*(_DWORD *)(this + 252), a2, wcslen(a2), 0, 0)`, where `252` = `0xfc` verified with `int_convert.py`.
- Return value is `this`.

`disasm(0x005b34d0)` confirms the function starts at `push ebp`, carries compiler SEH/security-cookie setup, pushes `asc_614C54` at `0x005b34fa`, calls `sub_4F1C00` at `0x005b34ff`, and has 57 total instructions. The compiler scaffolding should not appear in source C++.

`decompile(0x005b3570)` confirms:

- It narrows event bytes through `std::ctype<char>::do_narrow(a2[8], a2[266])`.
- It handles only event byte `a2[4] == 8`, no active IME/composition byte `a2[266]`, and narrowed keys `0x81`/`0x83` (displayed as signed `-127`/`-125`).
- It calls `sub_5A4930` for previous history and `sub_5A4990` for next history using `dword_67A748`, `this+52` in the adjusted secondary view, destination `wchar_t[256]`, and count `0x100`.
- It replaces the inherited edit child through `sub_58F2A0`/`sub_58FC30` when history text is nonempty.
- It returns `1` for handled history keys and falls back to `sub_4F25A0(this, event)` otherwise.

The adjusted secondary view evidence maps `this+0x68` to the primary object `this+0x108`, matching the documented `m_chatHistoryCursor`; adjusted `this+0x5c` maps to primary `this+0xfc`, matching the inherited edit child. The primary/adjusted offset conversions were verified with `int_convert.py`.

`decompile(0x005b3670)` confirms:

- Text length gate through `sub_4F2310`.
- Send-block gate at `dword_67A748 + 1261826`, where `1261826` = `0x134102` verified with `int_convert.py`.
- Text copy through `sub_4F2300(this, WideCharStr, 255)`.
- Empty-string return when `WideCharStr[0] == 0`.
- Password-disclosure guard `sub_465890(WideCharStr)`.
- Sanitizer `sub_5957C0(WideCharStr, wcslen(WideCharStr))`.
- Packet/context setup `sub_516030`.
- Packet byte writes through `sub_575380(14, &Src)` and `sub_575380(0, &v11)`, which are opcode `0x0e` and subtype `0`.
- `WideCharToMultiByte(0, 0, WideCharStr, (__int16)wcslen(WideCharStr), MultiByteStr, 256, 0, 0)`.
- Converted length range check `< 0x100`, length byte write, payload copy through `sub_516220`, final length check `< 0x12c`, local terminator outside sent length, `sub_574BB0(dword_67A7EC, &Src, convertedLength + 3)`, and `sub_5A49E0(dword_67A748, WideCharStr)`.

`insn_query(start='0x005b3490', end='0x005b34d0')` confirms 19 raw entries outside an IDA function:

- `0x005b3497`: `push offset asc_614C54; "> "`.
- `0x005b349f`: `call sub_4F1C00`.
- `0x005b34a7`: store primary `SayInputPane` vtable at `[esi]`.
- `0x005b34ad`: store `ax == -1` to `[esi+108h]`.
- `0x005b34b6`: store secondary `SayInputPane` vtable at `[esi+0A0h]`.
- `0x005b34c0`: store tertiary `SayInputPane` vtable at `[esi+0A4h]`.
- `0x005b34ce`: `retn`.
- `0x005b34cf`: `align 10h`.

### Xref, Vtable, And Negative Route Evidence

`xrefs_to` and code-filtered `xref_query` on current session:

- `0x005b3490`: zero xrefs and zero code xrefs.
- `0x005b34d0`: zero xrefs and zero code xrefs.
- `0x005b3570`: one data xref at `0x0062fbb4`, zero code xrefs.
- `0x005b3670`: one data xref at `0x0062fba4`, zero code xrefs.
- `0x005b37ea`: zero xrefs.
- `0x005b37f0`: zero xrefs and zero code xrefs.

`get_bytes` on `0x0062fb5c` and slices around `0x0062fba4`/`0x0062fbb4` confirms the vtable cells:

- `0x0062fb5c` begins with `80 7b 5b 00`, which is `0x005b7b80`, the scalar deleting destructor.
- `0x0062fba4` bytes begin `70 36 5b 00`, which is `0x005b3670`, the submit handler.
- `0x0062fbb4` bytes begin `70 35 5b 00`, which is `0x005b3570`, the key/history handler.

`xrefs_to(0x0062fb5c)`, `xrefs_to(0x0062fbac)`, and `xrefs_to(0x0062fbdc)` confirm vtable stores from:

- Raw no-function constructor addresses `0x005b34a7`, `0x005b34b6`, and `0x005b34c0`.
- Modeled constructor overload addresses `0x005b351a`, `0x005b3520`, and `0x005b352a`.
- Construction/open-site functions `0x005a53c0`, `0x005a5bd0`, and `0x005aa3b0`.

Targeted `find_bytes` pointer checks:

- Little-endian VA/RVA patterns for `0x005b3490` (`90 34 5b 00`, `90 34 1b 00`) returned zero matches.
- Little-endian VA/RVA patterns for `0x005b37f0` (`f0 37 5b 00`, `f0 37 1b 00`) returned zero matches.
- Little-endian VA pattern for `0x005b34d0` returned zero matches.
- Little-endian VA patterns for `0x005b3570` and `0x005b3670` returned exactly the vtable cells at `0x0062fbb4` and `0x0062fba4`.

This revalidates the important negative route: the adjacent no-route raw island is not an out-of-line SayInputPane helper, and the virtual children are vtable-dispatched rather than directly called.

## Heuristic And Inference Reanalysis

### Aggregate Versus Source Body

Claim: [UID:0001MB] is a useful source-family aggregate/evidence page, but it is not one original C++ function body.

Evidence:

- IDA models three separate functions inside the target range: `sub_5B34D0`, `sub_5B3570`, and `sub_5B3670`.
- MCP byte reads confirm four bytes of padding between the constructor overload and key handler, and six bytes of padding after the submit handler.
- Each exact child now has source-bearing C++ on its own page, routed through [UID:0000C3].
- The class page [UID:0000C3] owns the declaration shell and `[[CHILDREN]]` insertion point. The parent aggregate appears in generated output only as an empty emitter marker.

Decision:

- Keep aggregate C++ blank.
- Do not paste child C++ into the aggregate.
- Do not add a parent `[[CHILDREN]]` block because [UID:0000C3] already performs child insertion. A parent by-memory insertion point would risk duplicate or confusing output routing.

### Raw Default Constructor Sibling

Claim: [UID:0002S7] is a real source-shaped default constructor sibling, not part of [UID:0001MB] and not a fall-through wrapper for `0x005b34d0`.

Evidence:

- `lookup_funcs(0x005b3490)` reports `Not a function`.
- Raw instruction query shows a complete constructor-shaped body with prompt, `LineInputPane` base call, `m_chatHistoryCursor` initialization, three vtable stores, `retn`, and one-byte alignment.
- `xrefs_to(0x005b3490)`, code-filtered `xref_query(0x005b3490)`, and pointer `find_bytes` for the VA/RVA all return zero route evidence.
- `0x005b34cf-0x005b34d0` is one `0xcc` byte before the modeled overload.

Decision:

- Keep [UID:0002S7] as a sibling support page outside the [UID:0001MB] range.
- Recommended support sync should add current session `ff68e691` evidence to [UID:0002S7] and to the [UID:0001MB] target summary.
- A separate raw-constructor C++ review is still reasonable because [UID:0002S7] clears the current score/emitter gate, but this [UID:0001MB] aggregate report does not recommend inserting that raw constructor C++ during the aggregate callback. The raw start has no IDA function object and no static route; if the supervisor wants `SayInputPane::SayInputPane()` C++, accept it through a support-specific callback or a dedicated raw-constructor pass.

### Helper, Field, And Protocol Names

The current best source-facing names remain defensible:

| Binary evidence | Recommended source-facing name | Rationale |
| --- | --- | --- |
| Primary object `this+0x108` / adjusted secondary view `this+0x68` | `m_chatHistoryCursor` | Both constructors initialize it to `-1`; key/history handler passes its address to previous/next history helpers. Offset conversion `0x108` = `264` verified with `int_convert.py`. |
| Primary object `this+0xfc` / adjusted secondary view `this+0x5c` | inherited `m_textEditPane` / `m_inputEditPane` | Constructor inserts initial text and key handler selects/replaces text through this inherited edit child. Offset conversion `0xfc` = `252` verified with `int_convert.py`. |
| `0x005a4930` / `0x005a4990` | `GetPreviousChatHistoryLine` / `GetNextChatHistoryLine` | The functions are called only for history keys `0x81`/`0x83` with `g_pCollectionData`, cursor pointer, destination buffer, and count `0x100`. |
| `0x005a49e0` | `SaveChatHistoryLine` | Submit handler calls it after successful send with the copied wide text and `g_pCollectionData`. |
| `0x004f2310` / `0x004f2300` | `LineInputPane::TextLength` / `LineInputPane::CopyText` | Inherited text-control behavior in submit handler. |
| `0x00465890` | `ValidateChatInputOrThrowPasswordError` | Shared password-disclosure guard before sending chat text. |
| `0x005957c0` | `SanitizeWideTextForChat` | Sanitizes/normalizes wide chat text before conversion. |
| `0x00575380` | `PacketBufferWriteUInt8` | Writes opcode, subtype, and length bytes. Existing source wrapper style can use destination-first even though raw ABI is value-first. |
| `0x00516220` | `CopyPacketBytes` | Copies converted payload to packet byte `3+`. |
| `0x00574bb0` / `0x0067a7ec` | `QueueAndSendPacket` / `g_packetSender` | Shared socket send funnel and sender global. |
| Opcode `0x0e`, subtype `0` | `kChatMessageOpcode`, `kSayChatSubtype` / say-default chat message | Submit method sends default local say chat. The same opcode family does not transfer ownership to ChatInputPane or Socket. |

Remaining caveat:

- These names are source-quality inferences, not recovered original symbols. Original exact spelling for the event type, helper names, field names, and method names remains unavailable, which caps confidence below final-source levels.

## Positive Evidence

- Current MCP session `ff68e691` is healthy and points at the correct IDB.
- Current PE SHA-256 is recorded.
- Function boundaries, sizes, padding, and adjacent non-functions are confirmed with MCP `lookup_funcs` and `get_bytes`.
- The raw constructor body is confirmed with bounded `insn_query`.
- Constructor/key/submit behavior is confirmed with Hex-Rays and disassembly.
- Vtable route is confirmed by current `xrefs_to`, vtable bytes, and targeted pointer `find_bytes`.
- The current split matches generated `auto-generated/-ag-memory-coverage.md`: exact children [UID:000414], [UID:000415], and [UID:000416] are coded, while [UID:0001MB] is an empty emitter marker.
- [UID:0002S8] remains excluded by zero start xrefs, zero code xrefs, zero VA/RVA pointer hits to the raw start, padding before it, and lack of class/UI/history state.

## Negative Evidence And Rejected Alternatives

- Aggregate C++ rejected: the target range contains three source methods plus padding, not one source statement or method.
- Merge with [UID:0002S7] rejected: raw default constructor ends before the target at `0x005b34cf`, and one `0xcc` byte separates it from `sub_5B34D0`.
- Merge with [UID:0002S8] rejected: six `0xcc` bytes separate the submit method from the raw island; current MCP finds no function object, xrefs, code xrefs, or VA/RVA pointer hits to `0x005b37f0`.
- `Chatting` / `ChatInputPane` ownership rejected for [UID:0001MB]: they share opcode-family semantics and physical neighborhood, but have separate prompt/vtable/singleton/class routes and active ChatInputPane methods.
- `LineInputPane` ownership rejected: it is the base constructor, fallback handler, and edit-child provider, not the owner of the SayInputPane vtables/history cursor/submit slot.
- `UserPane` / `g_pCollectionData` ownership rejected: it supplies history and send-gate state, but not the receiver or source owner.
- `Socket`, `g_packetSender`, `PacketBuffer`, `PasswordGuard`, `TextFilter`, and generic `ProtocolSend` ownership rejected: they are shared dependencies or infrastructure, not the feature-level source owner.
- Reclassifying [UID:0001MB] to no-owner rejected: vtable identity, class route, file route, prompt literal, and generated child emission all support [UID:0000C3].
- Raising the aggregate into `90+` rejected: exact method C++ lives on children, original helper/member/event spellings remain inferred, and the parent itself is a no-code aggregate/empty emitter marker.

## Ranked Ownership And Source Placement

1. [UID:0000C3] `SayInputPane`: accepted direct semantic owner and emitter for [UID:0001MB] and its exact source-bearing children. Evidence is vtable family, constructor stores, prompt literal, history cursor, submit/key vtable slots, class shell, and generated route.
2. [UID:0000N9] `SayInputPanes`: accepted source-file route, currently `NexusTK/social/SayInputPanes.cpp`. This file owns the wider social say/shout/direct-message input family.
3. [UID:0002S7] `SayInputPaneRawConstructor`: sibling source-bearing support page, not a subrange of [UID:0001MB].
4. [UID:0002S8] `ChatPacketRawSenderNoRouteRaw`: adjacent protocol-neighborhood support page only, no owner/emitter route.
5. `Chatting` / `ChatInputPane`: rejected for target ownership; sibling/default chat packet comparison only.
6. `LineInputPane`, `UserPane`, `Socket`, `PacketBuffer`, `PasswordGuard`, `TextFilter`, and generic protocol modules: rejected as direct owners; dependencies only.

## Score And Metadata Recommendation

Recommended target metadata after accepted implementation:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000C3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000C3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion can improve modestly from `85` to `86` after the current MCP pass because the report now revalidates exact boundaries, raw sibling, child decompilations, vtable slots, padding, no-route raw-island rejection, helper/field/protocol names, generated child routing, PE hash, and current session provenance.
- Confidence can improve from `87` to `89` because `ff68e691` rechecks the split with current MCP evidence and targeted pointer-negative checks. The previous `b880584f` evidence remains corroborated but should no longer be the active provenance in target/support docs.
- Keep below `90+` because the parent remains a no-code aggregate/empty emitter marker, exact original helper/event/member spellings are inferred, [UID:0002S7] raw-constructor C++ policy remains a support follow-up, and final social file split between `SayInputPanes.cpp`/other social modules is not fully final-audit complete.
- Keep `CANONICAL_OWNER:0000C3`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000C3`. Current project state treats this as a source-bearing SayInputPane method cluster with exact child emission and an empty parent marker; the evidence does not justify no-owner or moving the route to another file/class.

## First-Draft C++ / No-Code Disposition

For [UID:0001MB] itself, keep the aggregate `RECONSTRUCTION_CPP` blank.

No-code proof:

- The target range is not one original source body.
- It contains exact source-bearing child functions [UID:000414], [UID:000415], and [UID:000416].
- It contains internal/successor padding that cannot appear as C++.
- The child bodies already carry first-draft C++ through [UID:0000C3] and [UID:0000N9].
- The class page [UID:0000C3] is the correct declaration-level `[[CHILDREN]]` insertion point.
- Adding aggregate C++ would either duplicate child output or falsely collapse separate methods into one body.

Child C++ disposition:

- [UID:000414] constructor overload: keep existing first-draft C++.
- [UID:000415] key/history handler: keep existing first-draft C++.
- [UID:000416] submit/send handler: keep existing first-draft C++.
- [UID:0002S7] raw default constructor: no target-level change in this report; add current evidence and keep blank unless the supervisor explicitly broadens implementation to raw-constructor C++.
- [UID:0002S8] no-route raw island: keep blank C++, `RECONSTRUCTABLE:FALSE`, no owner/emitter.

## Recommended Target And Support Doc Changes

| Path | Recommended change after supervisor acceptance |
| --- | --- |
| `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md` | Raise target to `86/89`; keep owner/emitter/reconstructable metadata unchanged; replace active `b880584f` provenance with current `ff68e691`; add PE SHA-256; add current function/range/body evidence, byte/padding evidence, vtable bytes/cells, xrefs/no-xrefs, `find_bytes` pointer negative checks, decompiler behavior for all three children, raw constructor sibling proof, [UID:0002S8] no-route rejection, helper/field/protocol name table, and aggregate no-code proof. |
| `by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md` | Add current session `ff68e691` evidence: no IDA function at `0x005b3490`, bounded raw instruction query, bytes ending in `retn` plus `0xcc`, no xrefs/code xrefs/VA/RVA pointer hits to the raw start, prompt/vtable stores, and sibling relationship to [UID:0001MB]. Keep score/C++ unchanged unless the supervisor accepts a broader raw-constructor C++ update. |
| `by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md` | If accepted, update active evidence provenance from `b880584f` to `ff68e691`; preserve current `87/89`, owner/emitter, and first-draft C++; add current PE hash and current decompile/xref/padding confirmation if not already present at same-or-greater detail. |
| `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md` | If accepted, update active evidence provenance from `b880584f` to `ff68e691`; preserve current `87/89`, owner/emitter, and first-draft C++; add current adjusted-view offset proof, vtable cell `0x0062fbb4`, no code xrefs, and helper/event-name caveats if not already present. |
| `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md` | If accepted, update active evidence provenance from `b880584f` to `ff68e691`; preserve current `88/90`, owner/emitter, and first-draft C++; add current submit decompile facts, send gate `+0x134102`, opcode/subtype layout, `g_packetSender`, and [UID:0002S8] no-route rejection if not already present. |
| `by-class/SayInputPane.md` | Add a current `ff68e691` evidence note summarizing the exact child split, raw sibling, method C++ placement, `m_chatHistoryCursor` offset proof, vtable cells, and aggregate no-code rule; no required class score change in this target callback. |
| `by-file/SayInputPanes.md` | Refresh the default `SayInputPane` row/evidence note to cite current `ff68e691`, exact child split, parent aggregate no-code, prompt/history/opcode names, and [UID:0002S8] exclusion; no required file score change. |
| `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` | Optional support sync only if supervisor wants all adjacent stale provenance replaced: add current `ff68e691` no-function/no-xref/no-pointer-hit confirmation and preserve `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++. |

Do not edit generated/project-level files manually. Validator-owned side effects are acceptable only during a later implementation callback.

## Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` as B005. If accepted, replace the existing [UID:0001MB] row with:

```text
    - [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) 0x005b34d0-0x005b37ea | class-method cluster | SayInputPane : reconstructable : 86% : very strong : B005 MCP session `ff68e691` confirms PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, SayInputPane/SayInputPanes ownership, [UID:0000C3][SayInputPane](by-class/SayInputPane.md) owner/emitter route, aggregate blank C++/no-code proof, exact modeled child functions `sub_5B34D0` size `0x9c`, `sub_5B3570` size `0x100`, and `sub_5B3670` size `0x17a`, current decompilation of prompt/history/opcode behavior, vtable cells `0x0062fbb4 -> 0x005b3570` and `0x0062fba4 -> 0x005b3670`, zero direct code xrefs to child starts, one/four/six-byte padding boundaries, raw default-constructor sibling [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md), helper/field/protocol names including `m_chatHistoryCursor`, opcode `0x0e` subtype `0`, `PacketBufferWriteUInt8`, `QueueAndSendPacket`, and `g_packetSender`, and [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) no-route raw island exclusion while indexing exact source-bearing child pages [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md), [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md), and [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md).
```

Optional supervisor-owned coverage cleanup noticed during this pass: the current [UID:0002S7] coverage row still shows `74%` even though the by-memory page is `86/89`. If the supervisor chooses to repair that adjacent support row during the same coverage maintenance window, replace it with:

```text
    - [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) 0x005b3490-0x005b34d0 | raw constructor | SayInputPaneRawConstructor : reconstructable : 86% : very strong : Current MCP session `ff68e691` confirms no IDA function at `0x005b3490`, zero xrefs/code xrefs and zero VA/RVA pointer hits to the raw start, raw constructor-shaped instructions with `L"> "` prompt, `LineInputPane` base construction, `m_chatHistoryCursor` initialization at `this+0x108`, primary/secondary/tertiary SayInputPane vtable stores to `0x0062fb5c`/`0x0062fbac`/`0x0062fbdc`, `retn` at `0x005b34ce`, one `0xcc` alignment byte at `0x005b34cf`, and sibling status before [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md); C++ remains blank pending a separate raw-constructor C++ policy decision.
```

## Expected Validators After Accepted Implementation

Run validators only for changed by-* docs from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001MB-SayInputPane-source-quality-removed.md](0001MB-SayInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` is touched for optional stale-provenance cleanup, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0001MB-SayInputPane-source-quality-removed.md](0001MB-SayInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run validators during this report-only pass.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read current `Agent-B005/goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` skill and read the B-agent research workflow reference.
- [x] Performed lightweight MCP health/session check for current session `ff68e691`.
- [x] Verified current IDB path, module, imagebase, readiness, active session, PE MD5/SHA-256.
- [x] Read current target [UID:0001MB], exact child/support pages [UID:0002S7], [UID:000414], [UID:000415], [UID:000416], [UID:0002S8], class [UID:0000C3], file [UID:0000N9], coverage row context, generated memory coverage, and generated `SayInputPanes.cpp` route.
- [x] Rechecked function/range/body state with MCP `lookup_funcs`, `func_profile`, `callees`, `get_bytes`, `decompile`, `disasm`, and bounded `insn_query`.
- [x] Rechecked xrefs and negative route evidence with MCP `xrefs_to`, code-filtered `xref_query`, vtable byte reads, and targeted `find_bytes` pointer checks.
- [x] Rechecked numeric conversions with `tools/int_convert.py`.
- [x] Completed heuristic/source-quality reanalysis, ownership/source-placement ranking, score/metadata recommendation, first-draft C++/no-code disposition, support-doc recommendations, coverage text, expected validators, and implementation checklist.
- [x] Did not edit by-* docs, generated/project-level files, IDA DB/tool state, unrelated docs, or any `-coverage-report.md`.

Accepted implementation callback items:

- [x] Lease check/take: leased the exact required by-* file set before editing: `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`, `by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md`, `by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md`, `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md`, `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md`, `by-class/SayInputPane.md`, and `by-file/SayInputPanes.md`; all returned `Success`. Release command later returned `Rejected[No active lease]` for each, and `tools/leaser/Agents/current_leases.md` showed no active B005 lease.
- [x] `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`: raised metadata to `86/89`, kept `CANONICAL_OWNER:0000C3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C3`, blank emitter position, and blank aggregate C++; added `B005 2026-06-23 Current MCP Revalidation` with current session `ff68e691`, PE SHA-256, exact function/range/body evidence, byte/padding evidence, decompiler behavior for all three children, bounded raw-constructor sibling proof, xrefs/no-xrefs, vtable cells, targeted pointer-negative checks, helper/field/protocol names, rejected owner routes, [UID:0002S8] no-route exclusion, and aggregate no-code proof.
- [x] `by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md`: added current `ff68e691` support evidence for no IDA function at `0x005b3490`, raw bytes ending in `retn` plus `0xcc`, bounded instruction landmarks, prompt/vtable/cursor stores, zero xrefs/code xrefs, zero VA/RVA pointer hits, and sibling relationship to [UID:0001MB]; kept score and blank C++ unchanged.
- [x] `by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md`: refreshed active provenance to `ff68e691`, added PE SHA-256 and pointer-negative proof, and preserved current `87/89`, owner/emitter route, first-draft constructor C++, prompt/history-cursor/vtable/initial-text behavior, and `0x005b356c-0x005b3570` padding.
- [x] `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md`: refreshed active provenance to `ff68e691`, added PE SHA-256, vtable-only pointer proof for `0x0062fbb4`, no direct code xrefs, adjusted-view mapping from secondary `+0x68/+0x5c` to primary `+0x108/+0xfc`, and preserved current `87/89`, owner/emitter route, and first-draft key/history C++.
- [x] `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md`: refreshed active provenance to `ff68e691`, added PE SHA-256, vtable-only pointer proof for `0x0062fba4`, zero VA/RVA pointer hits for adjacent `0x005b37f0`, submit packet/send/history facts, opcode `0x0e` subtype `0`, `g_packetSender`, and [UID:0002S8] no-route rejection; preserved current `88/90`, owner/emitter route, and first-draft submit C++.
- [x] `by-class/SayInputPane.md`: added current `ff68e691` evidence note for the exact child split, raw sibling, PE SHA-256, `m_chatHistoryCursor` offset proof, vtable cells, no-route raw-island exclusion, child C++ placement, and parent aggregate no-code policy; no score change required.
- [x] `by-file/SayInputPanes.md`: refreshed the default SayInputPane row/evidence to current session `ff68e691`, recorded PE SHA-256, target `86/89`, exact child split, raw constructor sibling, prompt/history/opcode names, child C++ placement, aggregate no-code policy, and [UID:0002S8] exclusion; no score change required.
- [x] Optional `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md`: not touched. The accepted optional criterion was "only if stale provenance/no-route wording is materially incomplete"; the required no-route facts are now incorporated at report-level detail into the target, submit child, class, and file pages, and the existing [UID:0002S8] page already carries the no-owner/non-emitting no-route disposition.
- [x] Preserved rejected alternatives and negative evidence: no aggregate C++, no merge with raw constructor, no merge with no-route raw island, no Chatting/ChatInputPane/LineInputPane/UserPane/Socket/PacketBuffer/TextFilter/PasswordGuard ownership, and no direct-call route for the virtual children.
- [x] Did not edit any `-coverage-report.md`; supervisor-owned [UID:0001MB] replacement row and optional [UID:0002S7] cleanup row remain supplied above for supervisor application.
- [x] Validators run for every changed by-* doc from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x005b34d0-0x005b37ea.SayInputPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\SayInputPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\SayInputPanes.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- [x] Implementation blockers: none. No MCP calls were needed during implementation; no lease conflict occurred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001MB-SayInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0001MB"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MB-SayInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001MB-SayInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
