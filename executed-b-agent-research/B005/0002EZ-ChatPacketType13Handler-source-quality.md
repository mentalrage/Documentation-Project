** TARGET-REPORT-UID:0002EZ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002EZ ChattingPane Handle Server Say Packet Ownership / Source-Quality Research

## Finalized Report / Current Recommendation

- The accepted callback renamed [UID:0002EZ] from `0x0047fd70-0x0047ff80.ChatPacketType13Handler.md` to `0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md`.
- Keep the existing combined half-open page `[0x0047fd70,0x0047ff80)`: source body `[0x0047fd70,0x0047ff60)`, five-entry compiler switch table `[0x0047ff60,0x0047ff74)`, and twelve bytes of `0xcc` alignment `[0x0047ff74,0x0047ff80)`. Do not split compiler data into a source emitter.
- The handler is now private `ChattingPane::HandleServerSayPacket(const unsigned char *packet)`, owned/emitted by [UID:00001X][ChattingPane](../../../../../by-class/ChattingPane.md), routed through [UID:0000I5][Chatting](../../../../../by-file/Chatting.md) to `NexusTK/social/Chatting.cpp`.
- The target is now `92/92`, reconstructable true, blank-positioned, and `Nested:0`; Destination 1 replaced provisional `ChatType13_*`, free-helper, hoisted state-byte, `[258]` decompiler-layout, and invented scratch/accessor source while preserving that material as rejected history.
- The ChattingPane declaration and router now carry the accepted target member. UID0002F0's free-helper call, path, owner, score, formal body, and independent unresolved source-quality caps remain verify-only and unchanged.
- Remove the former sender, MapPane-handler, and settings-parser changes from callback scope. UID000416, UID0001MF, UID0001MC, UID0003TN, and UID0003UL are read-only evidence dependencies with exact no-change dispositions below.
- B005's accepted ordinary-file callback and generated verification are complete. Manual coverage text and report lifecycle state remain supervisor-owned external state.

## Supporting Research

### Current direct documentation

- Before the callback, the target scored `86/90`, was reconstructable, was owned/emitted by source-file UID0000I5, and contained a provisional body with unresolved protocol/ownership/state names plus invented `InitializePacketDecodeScratch` / `GetActiveLocalObjectChatState` abstractions. That state is retained here as report-only history; the current target is `92/92` and class-owned.
- [UID:0002EU][ChattingPaneChatPacketRouter](../../../../../by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) is the secondary EventHandler packet slot and has the target's sole code xref at `0x0047f8b5`.
- [UID:0002F0][ChatPacketType10Handler](../../../../../by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md) is the adjacent opcode-10 server-message handler and shares the router, explicit ChattingPane pointer, message sink, and source file. Its current free-helper source shape remains unchanged and is not evidence for hoisting this target's state reads.
- [UID:0002EQ][ChattingPaneAddChattingMessage](../../../../../by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md) supplies the exact six-argument text/palette/style/custom-RGB sink.
- [UID:00026H][ServerPacketNameTable](../../../../../by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md) maps exact server opcode `0x0d` to `kServerSay` and `0x0a` to `kServerMessage`.
- [UID:0003TN][MapPaneHandleMovementSpeechBalloonPacket](../../../../../by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md) independently parses the same opcode-13 packet and proves the object-id/text layout plus subtype-2 balloon-only behavior.
- [UID:000416][SayInputPaneSubmitSayChat](../../../../../by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md), [UID:0001MF][ShoutInputPane](../../../../../by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md), and [UID:0001MC][ChatInputPane](../../../../../by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) send opcode `0x0e` subtype `0` or `1` and consume adjacent field `+0x134102`.

### Exact prior-report search record

- Identity/address terms searched: `0002EZ`, `0x0047fd70`, `0x0047ff60`, `0x0047ff80`, `ChatPacketType13Handler`, `ChattingPaneChatPacketType13Handler`, `ChattingPaneHandleServerSayPacket`, `HandleChatPacketType13`, `HandleServerSayPacket`, and `sub_47FD70`.
- Protocol/state terms searched: `ChatType13`, `kServerSay`, `ServerSay`, `134101`, `0x134101`, `134102`, `0x134102`, `g_activeMapPane`, `g_pUserPane`, `localChatState`, `sayDisplay`, `saySend`, `MovementSpeechBalloon`, `MapPane`, `SayInputPane`, `ShoutInputPane`, and `ChatInputPane`.
- Source-family terms searched: `ChattingPane`, `Chatting.cpp`, `ChattingUI`, `AddChattingMessage`, `ChatPacketType10Handler`, `ServerPacketNameTable`, `MapServerPacketOpcode`, and `PacketBufferReadUInt32BE`.
- Roots searched read-only:
  - `source-3/project-documentation/executed-b-agent-research`;
  - every active `source-3/project-documentation/tools/leaser/Agents/Agent-B###/research` folder;
  - `source-3/project-documentation/archived`, including legacy executed and duplicate-loose B-report roots;
  - relevant `SpecialReports`, `Older-Research`, and agent-local historical research roots where present.
- Matching reports opened:
  - `executed-b-agent-research/B001/0002ET-0002EV-0002EZ-chatting-pane-remaining-handlers-source-quality.md`: direct historical aggregate. It established core branch/color/range facts but retained provisional Type13 names, a free-helper model, and unresolved field access; those conclusions are superseded where this report has current IDA evidence.
  - `executed-b-agent-research/B001/0002EU-ChattingPaneChatPacketRouter-source-quality.md`: incidental router support. Its Event ABI, secondary-view adjustment, and byte-10/13 dispatch are current; only the target's free-helper call is superseded by this member-ABI audit, while UID0002F0 remains free.
  - `executed-b-agent-research/B001/0002EX-0002F0-chatting-source-quality-20260615.md`: incidental Type10 support. Its body behavior and current free-function signature remain useful verify-only evidence; its provisional subtype/helper source-quality surface is neither superseded nor changed by this target report.
  - `executed-b-agent-research/B001/0002EO-0002ES-chatting-message-ingress-source-quality.md`: incidental class/message-ingress support; useful for `ChattingPane` ownership and `AddChattingMessage`, not a direct target report.
  - `executed-b-agent-research/B003/0002EP-0002EU-0002EW-chatting-pane-core-source-quality.md`: incidental class/router support; useful for receiver adjustment and Chatting source route.
  - `executed-b-agent-research/B003/0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md`: incidental predecessor/range support; confirms the raw predecessor and padding before this target.
  - `executed-b-agent-research/B004/0002EV-ChattingPaneOnPaint-source-quality.md`: incidental class/source support.
  - `executed-b-agent-research/B004/0003XB-GrafPortStateAndClipRawHelpers-source-quality.md`: incidental mention only; no target-specific authority.
  - `executed-b-agent-research/B009/0002GF-ColorStringChattingMessageClone-source-quality.md`: incidental color/message-object support.
  - `executed-b-agent-research/B001/00026H-server-packet-name-table-source-routing.md`: exact protocol-name support for `kServerSay` and `kServerMessage`.
  - `executed-b-agent-research/B007/0000NS-Socket-empty-emitter-family-source-quality.md`: incidental server-packet table/source-route support.
- Active Agent research, Older-Research, SpecialReports, and legacy archived roots produced no additional direct exact-target report.
- Evidence-based conclusion: one prior direct aggregate discusses UID0002EZ, but no dedicated exact-target source-quality report exists. The aggregate is useful historical evidence and is superseded on the naming, ownership, field-route, and C++ blockers resolved here.

### 2026-07-13 Gate 1 repair evidence

- The supervisor's exact audit at `2026-07-13T18:53:15-04:00` rejected only the callback-readiness surface; the prior range, packet, subtype, state, caller, source-route, and report-search evidence remains valid.
- Fresh MCP transport session `77e49c2f-8e3c-4675-aae7-d8e924c8f73f` enumerated adopted database `supervisor_nexustk_20260713` and reconfirmed `server_health status=ok`, imagebase `0x00400000`, and ready auto-analysis, Hex-Rays, and strings.
- Target decompile request 10 and full 149-instruction disassembly request 11 prove exact evaluation order. Both layout branches call `GetMemoryMan()` before reading subtype or length. Both then convert/terminate text and load `g_activeMapPane->m_userPane` before subtype acceptance. Only subtype 0 and subtype 1 dereference `m_sayDisplayLevel`; subtype 2, 3, 4, and default do not.
- In the current-layout branch, subtype-4 custom trailer reads occur before `g_activeMapPane->m_userPane` is loaded. Thus a malformed subtype-4 trailer can fault before an invalid active-map pointer is touched. The repaired body preserves this ordering.
- Stack-frame request 9 and disassembly request 11 prove `sub esp,0x210`, security cookie at `[ebp-4]`, two dword compiler temporaries at `[ebp-0x210]` and `[ebp-0x20c]`, and text base `[ebp-0x208]`. The conversion capacity is exactly 256 and the only indexed write is a narrowed terminator index `0..255`.
- A source `wchar_t text[256]` occupies `[ebp-0x208,ebp-0x08)`, leaving four bytes `[ebp-0x08,ebp-0x04)` as alignment before the cookie. IDA coalesces that unused gap into `WCHAR[258]`; no instruction accesses elements 256 or 257.
- Same-toolchain stack-frame request 13 is the control: accepted 256-wide sender buffers at `0x005b3670` and `0x005b3a40` begin at frame offset `0x104` and the next local begins at `0x304`, while the `0x005b4260` wide buffer begins at `0x04` and the next local begins at `0x204`. IDA labels only the first `WCHAR`, yet each physical span is exactly `0x200` bytes. This proves IDA's inferred stack variable size is not original source-array evidence.
- Ranked layout result: `[256]` is highest probability and selected because capacity 256 plus a possible terminator at index 255 requires exactly 256 elements; `[258]` is a lower-probability decompiler coalescing with no accesses to the extra elements; any smaller array is rejected because a valid 255-character conversion result writes element 255.
- `0x00575470` requests 14-15 reconfirm the six-instruction byte-read helper dereferences one byte from its pointer argument. Direct packet indexing remains the least invented human source expression; the stripped helper's FLIRT `std::_Narrow_char_traits` name is not promoted into the draft.
- Current UID0003YJ proves PacketBuffer scalar writers use value-first raw ABI. Current UID0000DD/UID0001HU prove `g_packetSender` is `Socket *` and send syntax is a member call. The former Destinations 5-7 are removed rather than re-emitting unrelated sender bodies with contradicted provider syntax.
- UID00026H owns the emitted packet-name string table, not an opcode enum. UID0001SO is a MapPane-scoped, blank-formal opcode inventory with many unresolved names. Therefore neither owns a new Chatting declaration: repaired router C++ keeps observed literals `10` and `13`, while Destination 1 uses a function-local subtype enum whose scope is only the method that consumes it.

## Target

- UID: `0002EZ`.
- Historical pre-callback path: `by-memory/0x0047fd70-0x0047ff80.ChatPacketType13Handler.md`.
- Current path/title: `by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md`.
- Exact page range: `[0x0047fd70,0x0047ff80)`.
- Exact modeled source body: `[0x0047fd70,0x0047ff60)`, size `0x1f0` / 496 bytes.
- Compiler table: `[0x0047ff60,0x0047ff74)`, 20 bytes.
- Alignment: `[0x0047ff74,0x0047ff80)`, 12 bytes of `0xcc`.
- Current owner/emitter: UID00001X `ChattingPane`.
- Current source route: UID0000I5 `Chatting` -> `NexusTK/social/Chatting.cpp`.

## Current Target State

- Current metadata is `92/92`, owner/emitter UID00001X, reconstructable true, blank position, `Nested:0`, at the renamed path above.
- The page records source body `[0x0047fd70,0x0047ff60)`, compiler table `[0x0047ff60,0x0047ff74)`, twelve-byte alignment `[0x0047ff74,0x0047ff80)`, all branch colors, exact packet/state routes, and the private member ABI.
- The current formal block calls `GetMemoryMan()` once at the start of each selected layout branch before packet reads, preserves trailer-before-pointer and pointer-load/field-read parity, uses inferred `wchar_t[256]`, and keeps all unchecked failure behavior.
- Remaining lexical uncertainty is bounded to stripped original spellings and the inferred original source-array declaration; it does not block structure, ABI, packet layout, branch behavior, source placement, or compilability.

## Executive Recommendation

- Use `ServerSaySubtype` and behavior-backed subtype names: `Normal=0`, `Shout=1`, `BalloonOnly=2`, `Unfiltered=3`, and `CustomColor=4`.
- Use `ChattingPane::HandleServerSayPacket`; opcode 13's exact packet-name string is `kServerSay`. Preserve router literals `10` and `13` because neither UID00026H nor UID0001SO proves a shared emitted opcode-enum declaration.
- Express the active-object route as a branch-local pointer load followed by subtype-local field reads: load `UserPane *activeUserPane = g_activeMapPane->m_userPane` after conversion, but read `activeUserPane->m_sayDisplayLevel` only in subtype 0/1 gates. Record older `m_activeObjectPane` wording only as a superseded generic alias.
- Keep outgoing sender pages unchanged. Their `+0x134102` consumers remain read-only evidence for the adjacent send-level interpretation, not target callback destinations.
- Keep the compiler table and padding within the current page as non-source bytes. Do not create a child, table declaration, manual goto table, or nested emitter.
- Preserve exact unsafe packet behavior: no null/size/trailer checks, ACP conversion, one-byte length, narrow terminator index, big-endian custom colors, and unconditional false return.

## Supervisor Active Recheck

- Gate 1 accepted exact report SHA `E4139CEB086971C67F80CEF8B0B30003E2ADCAB289BAF380ACB3E2A039EFF60F`; the authorized implementation then changed only the seven accepted ordinary destinations plus this report.
- The required evidence pass was completed against healthy IDA MCP database `supervisor_nexustk_20260713` through transport session `7882ffdd-4cbc-4374-9a12-41606faa3a17`.
- One whole-image `search_text(pattern='134101h', start=0x00400000, end=0x00610000)` request timed out as an expensive query. It was not repeated. Fresh `idb_list`, `server_health`, bounded target bytes/xrefs/decompilation, localized field-reference scans, exact raw displacement scans, and relevant producer/consumer decompilations all succeeded afterward.
- The implementation checklist is complete. Scoped validators and final waited generation succeeded; no manual coverage/generated/tracker/supervisor/audit/lifecycle mutation and no `execute_report` action was performed.

## Inference Research Guidance Check

- Exact facts below are separated from source-facing inferences. Addresses, bytes, xrefs, calls, packet offsets, state comparisons, colors, and return behavior are direct IDA/raw-PE facts.
- `kServerSay` and `kServerMessage` are exact packet-name strings from UID00026H. They are protocol-name evidence, not proof that the original source declared enum identifiers with those spellings.
- `Normal` and `Shout` are supported by outgoing opcode-14 subtype-0/1 sender semantics and mirrored receive gates. `BalloonOnly`, `Unfiltered`, and `CustomColor` are behavior names where original stripped lexical spellings are unavailable.
- `m_sayDisplayLevel` and `m_saySendLevel` are descriptive names inferred from complete producer/consumer value matrices. They remain confidence caps, not reasons to leave raw offsets in source.
- No third-party source import applies. Web/source searches did not find relevant NexusTK original source or protocol declarations; unrelated modern projects and generic "server say" hits were rejected.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| Free vs member helper | Target receives ECX as the complete ChattingPane receiver, one packet stack argument, calls `AddChattingMessage` through that receiver, and returns with `ret 4`. Router restores complete object before tail transfer. | Private `ChattingPane` member; reject free `(pane, packet)` shape. |
| Opcode family | Exact server packet name table index 13 is string `kServerSay`; index 10 is string `kServerMessage`. The router machine code compares literal bytes. | Name only the target `HandleServerSayPacket`; preserve UID0002F0 and its current free-helper call unchanged. |
| Subtype 0 | Incoming display requires level 0; outgoing normal say is subtype 0 and is blocked by any nonzero send level. | `kServerSayNormal`. |
| Subtype 1 | Incoming display permits levels 0/1 and blocks level 2; outgoing shout is subtype 1 and is blocked only by send level 2. | `kServerSayShout`. |
| Subtype 2 | ChattingPane ignores it; MapPane still creates a speech balloon from the same text/object id. | `kServerSayBalloonOnly`; exact behavior, inferred spelling. |
| Subtype 3 | Both current and legacy ChattingPane append it without level gating; MapPane also processes it. | `kServerSayUnfiltered`; reject unsupported NPC/system/script labels. |
| Subtype 4 | Current branch reads two BE32 values after text and uses palette sentinels 253/254; legacy ignores it. | `kServerSayCustomColor`. |
| Packet object id | MapPane reads BE32 at bytes 2-5 to find the speaking object; ChattingPane skips the same bytes. | Name `targetObjectId`; document ignored by target rather than "unknown gap." |
| Text conversion | Byte 6 is length; bytes 7 onward are exact ACP input. Return from `MultiByteToWideChar` is narrowed to unsigned byte before NUL store. | Preserve exact count and narrowing; no invented packet NUL requirement. |
| Active object route | `g_activeMapPane` at `0x0067a764`; `MapPane+0x418` is set to the active UserPane and constructor also stores active map in `UserPane+0x1340f8`. | `g_activeMapPane->m_userPane`; old generic active-object alias historical only. |
| Display field | `UserPane+0x134101` has only target, MapPane sibling, live settings writer, and one unreferenced duplicate accesses. Its values gate normal/shout display exactly. | `unsigned char m_sayDisplayLevel`. |
| Send field | Adjacent `UserPane+0x134102` is initialized, written by same settings handler, and consumed by say/chat/shout senders with matching thresholds. | `unsigned char m_saySendLevel`. |
| Global at 0x67a748 | Existing canonical source identity is `UserPane *g_pUserPane`; current sender bodies use stale `g_pCollectionData`. | Use `g_pUserPane` in source-facing sender blocks. |
| GetMemoryMan call | One ignored call occurs at the start of each layout branch before subtype/length reads, including ignored/default paths. No returned context participates in decoding. | Preserve one call per current/legacy branch; reject both `InitializePacketDecodeScratch` and per-append calls. |
| Table ownership | All five table entries point inside target and implement subtype switch lowering. | Compiler data retained in combined page, no source declaration or child. |
| Active pointer order | Current branch loads `g_activeMapPane->m_userPane` at `0x47fe27-0x47fe2f` after optional subtype-4 trailer reads; legacy loads it at `0x47fef0-0x47fef5` after conversion. | Preserve pointer loads for every subtype/default, but field reads only at `0x47fe49`, `0x47fe80`, `0x47ff09`, and `0x47ff18`. |
| Null/fault parity | A null `g_activeMapPane` faults on every branch after conversion; for current subtype 4, trailer reads happen first. A null `m_userPane` faults only for subtypes 0/1 because other paths do not read the field. | Do not hoist the state byte and do not add guards. |
| Text local | IDA frame calls the physical 0x204-byte span `WCHAR[258]`, but code supplies capacity 256 and accesses only indices 0..255. Four unused bytes sit before the cookie. | Emit inferred `wchar_t text[256]`; historical `[258]` is decompiler gap coalescing, not source proof. |
| Opcode declaration owner | UID00026H emits strings; UID0001SO is a MapPane inventory with blank formal C++. Neither proves a shared enum declaration. | Router uses literals 10/13; no new opcode enum. `ServerSaySubtype` is function-local in Destination 1. |
| UID0002F0 scope | Sibling has unresolved subtype/helper/provider/source-shape work and is not needed to repair this target. | Verify-only/no rename/no owner/no formal/no score change; only preserve its existing free call. |
| UID0003TN / UID0003UL scope | Both are below 90 completion with blank formal blocks and were used only as bounded evidence providers. | Verify-only/no rename/no prose/formal/score change; no deferred callback claim remains. |
| Sender provider contracts | UID0003YJ is value-first; UID0000DD/UID0001HU require `g_packetSender->QueueAndSendPacket`. | Former sender blocks rejected and removed; UID000416/UID0001MF/UID0001MC remain unchanged evidence sources. |

### Exact packet and state matrices

| Offset | Width | Meaning | Target use |
| ---: | ---: | --- | --- |
| `0` | 1 | Server opcode `0x0d` / `kServerSay` | Router selects target; target does not reread it. |
| `1` | 1 | `ServerSaySubtype` | Five-entry switch over values `0..4`; values outside the table take default ignore. |
| `2` | 4 | Big-endian speaking/target object id | Ignored by ChattingPane; consumed by MapPane sibling. |
| `6` | 1 | Multibyte text byte count | Exact ACP input count, maximum 255. |
| `7` | `textLength` | Multibyte text bytes | Converted with codepage 0, flags 0, capacity 256; packet NUL is neither read nor required. |
| `7 + textLength` | 4 | Big-endian custom foreground RGB | Read only for current-layout subtype 4. |
| `11 + textLength` | 4 | Big-endian custom background RGB | Read only for current-layout subtype 4. |

| Subtype | Proposed name | Current `g_useEpfAssets == 1` | Legacy | Independent evidence |
| ---: | --- | --- | --- | --- |
| `0` | `kServerSayNormal` | Append only at display level 0 with palette `143/128`. | Append only at level 0 with `128/143`. | Outgoing normal say is opcode `0x0e`, subtype 0, blocked by any nonzero send level. |
| `1` | `kServerSayShout` | Append unless display level 2 with `14/128`. | Append unless level 2 with `12/143`. | Outgoing shout is opcode `0x0e`, subtype 1, blocked only by send level 2. |
| `2` | `kServerSayBalloonOnly` | Chat log ignores. | Chat log ignores. | MapPane consumes object id/text and creates the speech balloon. |
| `3` | `kServerSayUnfiltered` | Append unconditionally with `143/128`. | Append unconditionally with `128/143`. | Both Chatting layouts and MapPane accept without the normal/shout display gate. |
| `4` | `kServerSayCustomColor` | Append unconditionally with palette sentinels `253/254` plus two BE32 colors. | Ignore. | Direct trailer reads and custom arguments. |
| other | default | Ignore. | Ignore. | Switch default `0x0047ff4b`. |

Exact runtime dereference/evaluation parity is:

| Layout / subtype | `GetMemoryMan()` | Optional trailer reads | `g_activeMapPane->m_userPane` load | `m_sayDisplayLevel` read | Final target action |
| --- | --- | --- | --- | --- | --- |
| Current / `0` | Once before packet reads | None | Yes, after conversion | Yes, only in case `0` | Append only at level `0`. |
| Current / `1` | Once before packet reads | None | Yes, after conversion | Yes, only in case `1` | Append unless level `2`. |
| Current / `2` | Once before packet reads | None | Yes, after conversion | No | Ignore. |
| Current / `3` | Once before packet reads | None | Yes, after conversion | No | Append unconditionally. |
| Current / `4` | Once before packet reads | Two unchecked BE32 reads | Yes, after both trailer reads | No | Append custom colors unconditionally. |
| Current / other | Once before packet reads | None | Yes, after conversion | No | Ignore. |
| Legacy / `0` | Once before packet reads | None | Yes, after conversion | Yes, only in case `0` | Append only at level `0`. |
| Legacy / `1` | Once before packet reads | None | Yes, after conversion | Yes, only in case `1` | Append unless level `2`. |
| Legacy / `2` | Once before packet reads | None | Yes, after conversion | No | Ignore. |
| Legacy / `3` | Once before packet reads | None | Yes, after conversion | No | Append unconditionally. |
| Legacy / `4` | Once before packet reads | None | Yes, after conversion | No | Ignore. |
| Legacy / other | Once before packet reads | None | Yes, after conversion | No | Ignore. |

The pointer-load column dereferences `g_activeMapPane` but only obtains a `UserPane *`; it does not dereference that `UserPane`. Therefore a null `g_activeMapPane` faults on every current/legacy subtype/default after conversion, with current subtype `4` performing its unchecked trailer reads first. A null `m_userPane` faults only in subtype `0` or `1`, where the field byte is actually read. Destination 1 preserves all of these distinctions.

| Level | `m_sayDisplayLevel` receive effect | `m_saySendLevel` outgoing effect |
| ---: | --- | --- |
| `0` | Show normal and shout. | Allow normal and shout. |
| `1` | Suppress normal; show shout. | Block normal; allow shout. |
| `2` | Suppress normal and shout. | Block normal and shout. |

Subtype 3 and current subtype 4 bypass the receive display-level gate. Conversion failure returns zero and therefore writes `text[0] = L'\0'`; no branch rejects the empty converted text. The one-byte length bounds the conversion result and 16-bit custom offsets well below wrap, but truncated payloads or absent custom trailers still cause unchecked reads.

## Evidence Standards Used

- Mandatory live IDA MCP: database enumeration, health, bounded byte reads, function analysis, decompilation, disassembly, xrefs, callees, strings, exact local searches, and relevant producer/consumer functions.
- Raw PE corroboration: exact target/table/padding hashes, exact displacement occurrence inventory, and localized instruction addresses.
- Source-layout controls: exact frame offsets, cookie position, all local spans and accesses, conversion capacity/index bounds, plus three same-toolchain chat sender frames whose accepted 256-wide buffers expose IDA stack-type limitations.
- Provider-contract controls: current UID0003YJ value-first scalar-writer ABI and UID0000DD/UID0001HU Socket member-send declarations were treated as binding source interfaces for any proposed block.
- Current project docs/generated source: ownership, source routes, accepted class/global/type declarations, current formal blocks, and stale contradictions.
- Prior reports: searched and classified as direct, incidental, current, or superseded.
- Inference: only after the direct fact inventory; each proposed protocol/field name has an explicit confidence basis and rejected alternatives.

## Evidence Checked

- `idb_list` request 217: one active/adopted `supervisor_nexustk_20260713` database, NexusTK IDB, worker PID 2236.
- MCP `tools/list` request 218: current schemas loaded successfully.
- `server_health` request 219: `status=ok`; imagebase `0x00400000`; auto-analysis, Hex-Rays, and string cache ready.
- `get_bytes` request 220: 528 target bytes, eight predecessor bytes, table, and alignment retrieved successfully.
- `xref` requests 221-222: target, table, globals, scalar reader, caller, and callee routes retrieved successfully.
- `analyze_function` request 223: complete target CFG/decompile/disassembly facts.
- `analyze_function` request 224: adjacent opcode-10 sibling member ABI and router route.
- Exact string bytes request 225: UTF-16 `kServerSay` at `0x0062566e`.
- Earlier bounded requests 209-216 after MCP recovery: localized `+0x134101/+0x134102` uses, active-object writer, live settings producer `0x005aa480`, packet dispatcher, MapPane opcode-13 sibling `0x00511710`, and UserPane constructor.
- Gate 1 repair MCP initialize created transport `77e49c2f-8e3c-4675-aae7-d8e924c8f73f`; `idb_list` request 6 returned the one adopted `supervisor_nexustk_20260713` worker and `server_health` request 7 returned ready analysis/Hex-Rays/strings.
- Target `analyze_function` request 8 timed out after its bounded deadline, but the worker remained available and the narrower replacements succeeded: stack frame request 9, addressed decompile request 10, and complete 149-instruction disassembly request 11.
- Request 9 returned frame reserve `0x210`, two dword temporaries, physical text span from `[ebp-0x208]`, and cookie at `[ebp-4]`. Request 11 proved the only indexed text write uses a narrowed `MultiByteToWideChar` result and that the API capacity is 256.
- Request 13 compared `0x005b3670`, `0x005b3a40`, and `0x005b4260`: each accepted 256-wide sender buffer occupies an exact `0x200`-byte interval even where IDA labels only one `WCHAR`. This is the same-toolchain control selecting `[256]` over IDA's `[258]`.
- Requests 14-15 reconfirmed `0x00575470` as a six-instruction one-byte pointer read; its FLIRT `std::_Narrow_char_traits` label is not promoted into source.
- Read-only provider checks opened UID0003YJ, UID0000DD, and UID0001HU. They prove value-first `PacketBufferWriteUInt8/UInt16BE` raw source order and `Socket *g_packetSender` member syntax. No sender destination remains in the repaired callback scope.
- Raw PE SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Target body SHA256: `0c78eab0fca6cee8efa4cd105ff115466c252744dd61aa140634639df624d6eb`.
- Switch-table SHA256: `c3096e8b3b2bc14cb70834f7a5b8e465b7e5007d4b911e72b11638102b84a191`.
- Alignment SHA256: `a0d08a155aa4e9aadd5da959565de99acc8dc9dbda96ec3852dde76c97330902`.
- Combined page SHA256: `8fa27ea820b5f5fb3b35835c44a0f521612ccddcaff2f2b37b6a1bacc7177ce1`.
- Predecessor padding SHA256: `3d2f424783df5853c8d7121b1371650c04241f318e1b0cd46bedbc805b9164c3`.
- Current docs checked include target, UID00001X, UID0000I5, UID000104, UID0002EU, UID0002F0, UID0002EQ, UID0002EY, UID0003TN, UID0003UL, UID0001SO, UID00026H, UID0003YK, UID00007Q, UID0000S1, UID00009B, UID0000I9, UID0000QK, UID0000SW, UID000416, UID0001MF, UID0001MC, their class/file/aggregate pages, and current manual/generated outputs read-only.

## Claim And Incorporation Ledger

| ID | Claim | Action | Evidence | Destination | Verification state |
| --- | --- | --- | --- | --- | --- |
| C01 | Body is `[0x47fd70,0x47ff60)`, size `0x1f0`. | incorporate | MCP bytes/hash/disassembly | UID0002EZ | applied |
| C02 | Table is `[0x47ff60,0x47ff74)` and alignment `[0x47ff74,0x47ff80)`. | incorporate | Exact bytes/targets/hashes | UID0002EZ | applied |
| C03 | Target is a one-argument ChattingPane member returning false. | incorporate | ECX, `ret 4`, router adjustment, sink calls | Target/class/router | applied |
| C04 | Sole entry xref is router `0x47f8b5`. | incorporate | Xrefs | UID0002EZ | applied |
| C05 | Callees are GetMemoryMan, byte loader, ACP conversion, BE32 reader, AddChattingMessage, and cookie support. | incorporate | MCP decompile/disassembly | UID0002EZ | applied |
| C06 | Packet layout is opcode, subtype, BE32 object id, u8 length, text, optional two BE32 colors. | incorporate | Target plus read-only MapPane sibling | UID0002EZ | applied |
| C07 | Conversion uses codepage 0, flags 0, exact input length, output capacity 256, narrowed terminator index. | incorporate | Disassembly/decompile | UID0002EZ | applied |
| C08 | No null, size, conversion-failure, or custom-trailer bounds guard exists. | incorporate | Complete CFG/disassembly | UID0002EZ | applied |
| C09 | Current branch accepts 0/1/3/4 with exact gates/colors and exact trailer-before-active-pointer order. | incorporate | Addresses `0x47fda1-0x47fea7` | UID0002EZ | applied |
| C10 | Legacy branch accepts 0/1/3 with exact gates/colors and loads the active pointer before acceptance. | incorporate | Addresses `0x47feac-0x47ff4b` | UID0002EZ | applied |
| C11 | Custom colors are BE32 at `7+length` and `11+length`, palette 253/254. | incorporate | Reader calls/offsets | UID0002EZ | applied |
| C12 | Every path returns false. | incorporate | CFG/returns/router | Target/router | applied |
| C13 | Opcode 13's exact packet-name string is `kServerSay`; that does not prove an emitted enum. | incorporate | UID00026H table/string | Target prose/router literal | applied |
| C14 | Subtypes 0/1 are Normal/Shout. | incorporate | Incoming gates plus read-only outgoing senders | UID0002EZ | applied |
| C15 | Subtype 2 is balloon-only. | incorporate | Chatting ignore plus read-only MapPane accept | UID0002EZ | applied |
| C16 | Subtype 3 is unfiltered display. | incorporate | Both layout branches bypass field gate | UID0002EZ | applied |
| C17 | Subtype 4 is custom-color current-only. | incorporate | Trailer/color behavior | UID0002EZ | applied |
| C18 | Each layout branch loads `UserPane *` through `g_activeMapPane+0x418`; only subtype 0/1 reads its display field. | incorporate | Exact instructions `0x47fe27-0x47fe80`, `0x47fef0-0x47ff18` | UID0002EZ | applied |
| C19 | `UserPane+0x134101` is inferred `m_sayDisplayLevel`. | incorporate | Complete consumer/producer inventory | UID0002EZ | applied |
| C20 | Adjacent `UserPane+0x134102` is inferred `m_saySendLevel`; sender pages are evidence-only. | incorporate | Constructor/settings/sender inventory | UID0002EZ evidence | applied |
| C21 | Live settings producer is `0x5aa480`; `0x5ab760` is unreferenced duplicate. | incorporate | Dispatcher xref and negative xrefs | UID0002EZ evidence | applied |
| C22 | Raw displacement inventory is exhaustive for both adjacent bytes. | incorporate | Exact PE scans | UID0002EZ | applied |
| C23 | Address `0x67a748` is canonically `g_pUserPane`; no callback change is proposed to its page. | already-present | Current UID0000QK/UID0001OR | Verify-only support | already-present |
| C24 | Canonical target owner/emitter becomes UID00001X. | incorporate | Member ABI/class/sink/router | UID0002EZ | applied |
| C25 | Rename only UID0002EZ; preserve UID0002F0 path/name/owner/formal body. | incorporate | Target protocol evidence and sibling scope exclusion | Target/backlinks | applied |
| C26 | Raise target `86/90 -> 92/92`; confidence is capped by inferred lexical names and source array declaration. | incorporate | Repaired blockers and explicit caps | UID0002EZ | applied |
| C27 | Keep combined page and `Nested:0`; no child. | already-present | Compiler-only table/padding | UID0002EZ | already-present |
| C28 | Predecessor padding and successor UID0002F0 remain excluded. | already-present | Exact boundaries | UID0002EZ | already-present |
| C29 | `InitializePacketDecodeScratch`, per-append GetMemoryMan calls, and a hoisted display byte are invalid. | reject-invalid | Exact runtime order | Target formal/history | excluded-with-reason |
| C30 | Repaired Destination 1 uses `[256]`, one call per layout branch, pointer-load/field-read parity, and a function-local subtype enum. | incorporate | Requests 9-11/13 and complete CFG | UID0002EZ | applied |
| C31 | Repaired Destination 2 adds only the target private member and preserves the existing free UID0002F0 declaration. | incorporate | Current class plus target ABI | UID00001X | applied |
| C32 | Repaired Destination 3 keeps literal 10/13 comparisons, current free UID0002F0 call, and target member call. | incorporate | Router bytes plus declaration-owner audit | UID0002EU | applied |
| C33 | UID0002F0 is not renamed/memberized/rewritten/scored by this report; only renamed-target backlinks may change. | not-applicable | Unresolved subtype/helper/provider surface and independent score | Verify-only UID0002F0 | excluded-with-reason |
| C34 | UID000416/UID0001MF/UID0001MC receive no formal or prose changes from this report. | not-applicable | Their provider contracts exposed the invalid former blocks; adjacent-field use remains evidence | Verify-only senders | excluded-with-reason |
| C35 | No shared opcode enum is emitted; UID00026H owns strings, UID0001SO remains a blank MapPane inventory, and subtype enum scope is target-local. | incorporate | Current formal/generated ownership audit | Target/router/type support | applied |
| C36 | Source local is inferred `wchar_t[256]`, not IDA `WCHAR[258]`; four bytes are alignment before the cookie. | incorporate | Frame/access/sibling controls | UID0002EZ | applied |
| C37 | UID0003TN is verify-only/no-change: no rename, score, prose, metadata, or formal edit. | not-applicable | Below-90 blank emitter used only for bounded sibling evidence | Verify-only UID0003TN | excluded-with-reason |
| C38 | UID0003UL is verify-only/no-change: no score, prose, metadata, or formal edit. | not-applicable | Below-90 blank emitter used only for bounded producer evidence | Verify-only UID0003UL | excluded-with-reason |
| C39 | UID0003YJ, UID0000DD, UID0001HU, UID0000QK, UID0001SO, and UID00026H are verify-only provider/type/global evidence. | already-present | Current accepted provider and ownership contracts | Verify-only support | already-present |
| C40 | Chatting class/router/file/aggregate and exact target backlinks receive synchronized member/source/range evidence. | incorporate | Source ownership and compilable order | Named Chatting support | applied |
| C41 | NPC/system/script names, hoisted field read, `[258]`, file-scope enums in method/class emitters, Type10 expansion, sender rewrites, and old owner pollution are rejected. | reject-stale | Negative and repair evidence | Target/support prose | excluded-with-reason |
| C42 | Exact supervisor-owned manual coverage rows and verify-only destinations are supplied below. | incorporate | Current manual rows read-only | Manual coverage text | applied |
| C43 | No validator or implementation action belongs to report-only Gate 1. | not-applicable | Assignment restriction | Validator/results/checklist | already-present |

### Callback Verification Notes

| ID | Current destination proof |
| --- | --- |
| C01 | UID0002EZ `Range / Split / Padding` records the exact `0x1f0` source body. |
| C02 | UID0002EZ records the 20-byte table, five targets, hashes, and twelve-byte alignment. |
| C03 | Destinations 1-3 are byte-identical to target/class/router formal blocks; generated lines 884/1093/1247 show member declaration, member call, and definition. |
| C04 | UID0002EZ retains sole router xref `0x0047f8b5`; UID0002EU records vtable-only router liveness. |
| C05 | UID0002EZ retains the complete decompile/disassembly callee inventory and compiler-support distinction. |
| C06 | UID0002EZ packet table records opcode/subtype/object-id/length/text/custom trailer; UID000104 and UID0000I5 synchronize the bounded disposition. |
| C07 | UID0002EZ formal/body evidence emits codepage/flags zero, byte count, capacity 256, and narrowed terminator. |
| C08 | UID0002EZ unsafe-edge and negative-evidence sections explicitly reject every absent guard. |
| C09 | UID0002EZ formal block and matrix preserve current 0/1/3/4 gates, palettes, and trailer-before-pointer order. |
| C10 | UID0002EZ formal block and matrix preserve legacy 0/1/3 behavior and pointer-load parity. |
| C11 | UID0002EZ and UID0002EQ record offsets `7+length`/`11+length`, BE32 reads, and palettes `253/254`. |
| C12 | UID0002EZ and UID0002EU formal blocks retain false returns on every path. |
| C13 | Target/router/file prose keeps literal opcode 13 and treats UID00026H `kServerSay` as string evidence only. |
| C14 | Target local enum and both layout matrices emit Normal/Shout values 0/1. |
| C15 | Target local enum and negative paths emit BalloonOnly value 2 with no append case. |
| C16 | Target local enum and both layout matrices emit Unfiltered value 3 without a field gate. |
| C17 | Target local enum and current-only trailer branch emit CustomColor value 4; legacy has no case. |
| C18 | Target formal block loads `g_activeMapPane->m_userPane` on all subtype/default routes and dereferences display state only in cases 0/1. |
| C19 | UID0002EZ records inferred `m_sayDisplayLevel`, value matrix, producers/consumers, and lexical cap. |
| C20 | UID0002EZ records adjacent `m_saySendLevel` evidence while sender pages remain unmodified. |
| C21 | UID0002EZ preserves live `0x005aa480` producer and unreferenced `0x005ab760` duplicate evidence. |
| C22 | UID0002EZ preserves the exhaustive raw-displacement inventory and negative hits. |
| C23 | UID0000QK/UID0001OR were verified read-only; no callback destination or mutation exists. |
| C24 | UID0002EZ metadata now names owner/emitter UID00001X; validator `000000010584` registered the owner/path update. |
| C25 | UID0002EZ alone was renamed; UID0002F0 remains at its accepted path and UID0002EY now links the renamed successor. |
| C26 | UID0002EZ metadata is `92/92`; its rationale retains lexical/source-array confidence caps. |
| C27 | UID0002EZ retains combined range and `Nested:0`; no child/UID was created. |
| C28 | UID0002EY remains `[0x0047fd40,0x0047fd68)` plus excluded eight-byte padding; UID0002F0 begins at `0x0047ff80`. |
| C29 | Invalid scratch/accessor/per-append/hoisted forms were removed from current source and retained only as rejected history. |
| C30 | Destination 1 exactly matches UID0002EZ and generated output: `[256]`, two layout-entry calls, pointer/field parity, local enum. |
| C31 | Destination 2 exactly matches UID00001X; generated class has private target member and post-class free UID0002F0 prototype. |
| C32 | Destination 3 exactly matches UID0002EU; generated router preserves literal 10 free call then literal 13 member call. |
| C33 | UID0002F0 was not leased, edited, renamed, rescored, or validated; generated declaration/body remain present in prior accepted form. |
| C34 | UID000416/UID0001MF/UID0001MC were not leased, edited, or validated; they remain evidence-only. |
| C35 | Generated Chatting.cpp has one method-local `ServerSaySubtype` and zero `ServerPacketOpcode`/shared enum declarations. |
| C36 | UID0002EZ and UID0000I5 record `[256]` plus four-byte pre-cookie alignment; generated source contains one `wchar_t text[256]`. |
| C37 | UID0003TN was not leased, edited, or validated and remains exact verify-only sibling evidence. |
| C38 | UID0003UL was not leased, edited, or validated and remains exact verify-only producer evidence. |
| C39 | Provider/type/global pages were read-only and excluded from the exact seven-file ordinary edit set. |
| C40 | UID00001X, UID0002EU, UID0000I5, UID000104, UID0002EQ, and UID0002EY contain the accepted bounded synchronization and each passed scoped validation. |
| C41 | Current target/support prose marks stale names, `[258]`, hoists, shared enums, sender rewrites, and owner pollution rejected/superseded; no such generated source remains. |
| C42 | Exact supervisor-owned manual rows remain in this report; no manual coverage file was edited. |
| C43 | The no-validator fact remains explicitly historical to Gate 1; callback validators `000000010584` through `000000010625` are recorded below. |

## Positive Evidence Summary

- Exact body/table/padding bytes and hashes close every range boundary.
- Router tail-jumps to the target after restoring the complete ChattingPane receiver; target has no independent ordinary caller.
- Exact packet-name table establishes `kServerSay`; outgoing sender and MapPane sibling behavior resolve all five subtype roles without deferral.
- MapPane's sibling parser proves the ignored target-object-id bytes and balloon-only subtype.
- Complete displacement scans plus live producer/consumer decompilation resolve both adjacent state bytes and reject unrelated object/global routes.
- Full disassembly proves both layout branches call `GetMemoryMan()` before packet reads, current subtype `4` reads its trailer before the active-map load, all subtype/default paths load `g_activeMapPane->m_userPane`, and only subtype `0`/`1` dereference the nested display field.
- Exact frame/access controls select inferred source `wchar_t text[256]`: capacity and writes require indices `0..255`, elements `256/257` are never accessed, and four bytes between that array and the cookie are alignment rather than source array evidence.
- Existing class/source infrastructure already emits ChattingPane in `NexusTK/social/Chatting.cpp`; no new source file is needed.
- The complete first draft below preserves unsafe edge behavior rather than sanitizing the recovered program.

## IDA MCP Facts

- Database: `supervisor_nexustk_20260713`; transport session used for the final pass: `7882ffdd-4cbc-4374-9a12-41606faa3a17`.
- Target prototype reported by IDA: `char __thiscall(__int128 *this, int)`. Source reconstruction corrects the decompiler's receiver and integer packet temporary to `bool ChattingPane::HandleServerSayPacket(const unsigned char *packet)`.
- Target metrics: 496 bytes, 25 basic blocks, cyclomatic complexity 16.
- Stack reserves `0x210` bytes. IDA coalesces text base `[ebp-0x208]` through the four-byte pre-cookie gap as `WCHAR[258]`, but direct accesses and same-toolchain controls select inferred source `wchar_t text[256]` plus four bytes of alignment; conversion capacity is 256.
- Direct calls: `0x00516030`, `0x00575470`, imported `MultiByteToWideChar`, `0x005754c0`, `0x0047f280`, and stack-cookie support.
- Exact `+0x134101` hits: `0x47fe4b`, `0x47fe82`, `0x47ff0b`, `0x47ff1a`, `0x5117a6`, `0x5117db`, `0x5aa550`, `0x5ab7e6`.
- Exact `+0x134102` hits: `0x5a264e`, `0x5aa566`, `0x5ab7ee`, `0x5b369f`, `0x5b3a6f`, `0x5b428d`.
- `0x005aa480` is reached from the active UserPane packet dispatcher for server opcode 8. `0x005ab760` has no code/data/pointer route and is retained only as raw duplicate evidence.
- Target table entries are `0x0047fe45`, `0x0047fe45`, `0x0047ff4b`, `0x0047fe45`, `0x0047fe45` for indices 0..4.
- Table raw bytes are `45 fe 47 00 45 fe 47 00 4b ff 47 00 45 fe 47 00 45 fe 47 00`. The predecessor span is eight `cc` bytes and the target's trailing alignment span is twelve `cc` bytes.
- Exact UTF-16 packet-name bytes at `0x0062566e` decode to `kServerSay`.

## Function / Child Inventory

| Span/address | Classification | Disposition |
| --- | --- | --- |
| `[0x47fd68,0x47fd70)` | Eight `0xcc` bytes after UID0002EY | Predecessor alignment, excluded. |
| `[0x47fd70,0x47ff60)` | `ChattingPane::HandleServerSayPacket` | Source body; target emitter. |
| `[0x47ff60,0x47ff74)` | Five-entry subtype switch table | Compiler lowering; retained in target page, no C++. |
| `[0x47ff74,0x47ff80)` | Twelve `0xcc` bytes | Alignment retained in target page. |
| `[0x47ff80,0x4805d6)` | Adjacent opcode-10 body | Separate UID0002F0 free helper; verify-only/no change. |
| `[0x4805d6,0x480632)` | UID0002F0 compiler tables | Separate sibling page. |
| `[0x480632,0x480640)` | UID0002F0 alignment | Separate sibling page. |

- No new child UID is warranted. The target remains one combined source body/compiler-tail page with `Nested:0`.

## Direct Xref / Caller Inventory

| From | To | Meaning |
| --- | --- | --- |
| `0x0047f8b5` | `0x0047fd70` | Sole target entry from ChattingPane packet router after `ecx -= 0xa0`. |
| `0x0047f8c4` | `0x0047ff80` | Sole adjacent Type10 entry from the same router. |
| Target branches | `0x0047f280` | Accepted server-say text forwarded to `ChattingPane::AddChattingMessage`. |
| Target custom branch | `0x005754c0` | Two BE32 custom color reads. |
| Current/legacy layout entries | `0x00516030` | Ignored `GetMemoryMan()` call once at the start of each layout branch, before packet reads, including ignored/default paths. |
| UserPane dispatcher | `0x005aa480` | Live settings producer route. |
| No route | `0x005ab760` | Raw duplicate producer; no active caller/pointer. |

- There are no ordinary external callers, vtable entries, callback pointers, exports, exception handlers, or raw VA/RVA pointer hits to the target start beyond the router transfer.

## Documentation Evidence And IDA Status

- IDA initially labels the target and sibling as `sub_47FD70` / `sub_47FF80` with inaccurate `__int128 *` receiver types. Those names/types are analysis placeholders, not source evidence.
- Current docs already have exact ChattingPane, Event router, message sink, PacketBuffer scalar reader, UserPane, MapPane, and source-file pages. The required change is synchronization, not a new ownership family.
- Current generated Chatting source is useful only as a read-only consistency check. It presently reflects the old free-helper declarations and provisional names; proposed blocks are designed to compile in existing address order.
- IDA remained healthy through all final bounded target calls. No IDA rename, type mutation, comment mutation, function creation, or segment change was performed.

## Ranked Ownership Analysis

| Rank | Candidate | Result |
| ---: | --- | --- |
| 1 | `ChattingPane` member in Chatting.cpp | Accepted: receiver ABI, router adjustment, message sink, local address band, and source class agree. |
| 2 | File-local free helper in Chatting.cpp | Rejected current shape: would require passing the pane separately, but binary preserves receiver in ECX and one stack argument. |
| 3 | MapPane/UserPane packet method | Rejected: they supply state and sibling evidence but target receiver and AddChattingMessage sink are ChattingPane. |
| 4 | FolderTreePane | Rejected stale generated owner pollution; no filesystem-tree behavior or receiver. |
| 5 | Socket/PacketBuffer/EventDispatcher | Rejected infrastructure owners; they transport/read packets but do not own this UI behavior. |
| 6 | New protocol source file | Rejected duplication; existing Chatting route covers router, target, sibling, and sink. |

## Source Placement

- Canonical class owner/emitter: UID00001X `ChattingPane`.
- Canonical file: UID0000I5 `Chatting`.
- Generated route: `NexusTK/social/Chatting.cpp`.
- Source order is viable after Destination 2: the class declares the private target member and preserves the existing post-class free UID0002F0 prototype before `[[CHILDREN]]`; address-ordered Destination 3 calls the free Type10 helper and target member, and Destination 1 emits the target member definition.
- No shared opcode declaration is proposed. UID00026H emits packet-name strings, UID0001SO remains a MapPane-scoped inventory with blank formal C++, the router preserves literal `10`/`13`, and the target-only subtype enum is local to Destination 1.

## Range / Split / Padding / Reclassification Analysis

- Preserve page start `0x0047fd70`; the eight preceding `0xcc` bytes belong to predecessor alignment and are excluded.
- Preserve page end `0x0047ff80`; it is the exact next modeled function start.
- The five table dwords all target labels inside the source body and are consumed only by its subtype switch. Splitting them would create a non-source compiler-data page and would not improve generated C++.
- Twelve trailing `0xcc` bytes are ordinary function alignment. They remain documented but emit nothing.
- No internal orphan code, EH funclet, literal pool, second source method, hidden raw helper, table pointer consumer, or unrelated byte run exists.
- Keep `Nested:0`; this field is relative/cumulative ordering metadata, not a child count, and this recommendation creates no children.

## Negative Evidence Summary

- No original PDB, map, header, symbol, or relevant third-party source was found.
- No source evidence supports `ChatType13_State0Only`, `HighlightUnlessState2`, `UngatedDefault`, NPC, scripted, system, forced, or movement speech as original subtype spellings.
- No call result from `GetMemoryMan()` participates in conversion or copying; `InitializePacketDecodeScratch` is invented.
- No dedicated `GetActiveLocalObjectChatState` function exists in the binary.
- No instruction accesses source-array candidates `text[256]` or `text[257]`; IDA's `WCHAR[258]` label spans an unused pre-cookie gap and is not original declaration proof. A smaller array is behaviorally impossible because valid conversion/termination can write element `255`.
- No packet-name-table string or MapPane opcode inventory proves that `kServerSay`, `kServerMessage`, or a shared packet opcode enum was declared in Chatting source. File-scope enum proposals in the method/class emitters are rejected.
- No packet size or null pointer is read by the target. Adding safety checks would change malformed-packet behavior.
- No conversion success guard exists. A zero conversion result writes `text[0]=0`; the narrowed return is preserved.
- No target-object-id read occurs in ChattingPane. The field is nevertheless not padding because MapPane consumes it.
- No code or data evidence supports owner UID0000I5 as a free source-file emitter after the member ABI audit.
- No direct evidence recovers exact original lexical spellings for the three inferred subtype names or two state fields; scores remain below certainty accordingly.
- No complete source-quality basis was established for renaming/memberizing UID0002F0 or changing UID0003TN/UID0003UL. They remain exact verify-only/no-change evidence dependencies rather than deferred changed destinations.
- No target requirement justifies rewriting UID000416, UID0001MF, or UID0001MC. Their accepted value-first PacketBuffer and `Socket::QueueAndSendPacket` contracts disprove the former blocks, which are removed rather than repaired as unrelated sender work.

## IDA Rename / Type / Comment Recommendations

- Rename IDA function `sub_47FD70` to `ChattingPane__HandleServerSayPacket` and type it as `bool __thiscall(ChattingPane *, const unsigned char *)` only in a separately authorized IDA-mutation workflow; this report did not mutate IDA.
- Leave `sub_47FF80` unchanged in this assignment. UID0002F0's provisional subtype/helper/type surface has not received an independent source-quality pass, so an IDA rename would exceed this target's evidence-backed callback scope.
- `MapPane *g_activeMapPane`, `UserPane *m_userPane`, and descriptive `m_sayDisplayLevel` / `m_saySendLevel` are source-facing target-report inferences only. No IDA global/structure/field mutation is requested by this report.
- Comment `[0x47ff60,0x47ff74)` as the compiler switch table for server-say subtype 0..4 and `[0x47ff74,0x47ff80)` as alignment.
- Do not create functions at table entries, rename compiler labels as methods, add a raw helper, or force the table into a source structure.

## First-Draft C++ Recommendation

Exactly three source destinations were accepted and applied. Every declaration/body change is confined to one literal managed block below, and each block is byte-identical to its current destination. Prose examples outside these blocks are descriptive only and are not additional C++.

### Destination 1 - UID0002EZ applied renamed target

Destination path: `by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ChattingPane::HandleServerSayPacket(const unsigned char *packet)
{
    enum ServerSaySubtype
    {
        kServerSayNormal = 0,
        kServerSayShout = 1,
        kServerSayBalloonOnly = 2,
        kServerSayUnfiltered = 3,
        kServerSayCustomColor = 4
    };

    wchar_t text[256];

    if (g_useEpfAssets == 1) {
        GetMemoryMan();

        const unsigned char subtype = packet[1];
        const unsigned char textLength = packet[6];
        const int convertedLength = MultiByteToWideChar(
            0,
            0,
            reinterpret_cast<const char *>(packet + 7),
            textLength,
            text,
            256);
        text[static_cast<unsigned char>(convertedLength)] = L'\0';

        unsigned int foreground;
        unsigned int background;
        if (subtype == kServerSayCustomColor) {
            const unsigned short foregroundOffset =
                static_cast<unsigned short>(textLength + 7);
            const unsigned short backgroundOffset =
                static_cast<unsigned short>(textLength + 11);
            foreground = PacketBufferReadUInt32BE(packet + foregroundOffset);
            background = PacketBufferReadUInt32BE(packet + backgroundOffset);
        }

        UserPane *activeUserPane = g_activeMapPane->m_userPane;

        switch (subtype) {
        case kServerSayNormal:
            if (activeUserPane->m_sayDisplayLevel != 0)
                return false;
            AddChattingMessage(text, 143, 128, 0, 0, 0);
            return false;

        case kServerSayShout:
            if (activeUserPane->m_sayDisplayLevel == 2)
                return false;
            AddChattingMessage(text, 14, 128, 0, 0, 0);
            return false;

        case kServerSayUnfiltered:
            AddChattingMessage(text, 143, 128, 0, 0, 0);
            return false;

        case kServerSayCustomColor:
            AddChattingMessage(text, 253, 254, 0, foreground, background);
            return false;
        }

        return false;
    }

    GetMemoryMan();

    const unsigned char subtype = packet[1];
    const unsigned char textLength = packet[6];
    const int convertedLength = MultiByteToWideChar(
        0,
        0,
        reinterpret_cast<const char *>(packet + 7),
        textLength,
        text,
        256);
    text[static_cast<unsigned char>(convertedLength)] = L'\0';

    UserPane *activeUserPane = g_activeMapPane->m_userPane;

    switch (subtype) {
    case kServerSayNormal:
        if (activeUserPane->m_sayDisplayLevel != 0)
            return false;
        AddChattingMessage(text, 128, 143, 0, 0, 0);
        return false;

    case kServerSayShout:
        if (activeUserPane->m_sayDisplayLevel == 2)
            return false;
        AddChattingMessage(text, 12, 143, 0, 0, 0);
        return false;

    case kServerSayUnfiltered:
        AddChattingMessage(text, 128, 143, 0, 0, 0);
        return false;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID00001X ChattingPane class

Destination path: `by-class/ChattingPane.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class ChattingMessage;
struct PaneKeyEvent;
struct Point;

class ChattingPane : public ScrollablePane
{
public:
    ChattingPane();
    virtual ~ChattingPane();

    void AddChattingMessage(const wchar_t *text,
                            int foregroundColor,
                            int backgroundColor,
                            unsigned char textStyleFlag,
                            int customForegroundRgb,
                            int customBackgroundRgb);
    void AddIncomingMessage(ChattingMessage *message);
    void SetVisibleRowCount(int visibleRows);
    short ComputeLineCount() const;
    void ScrollToBottom();

protected:
    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta,
                                  char axis,
                                  short oldPosition,
                                  short newPosition);
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool HandleServerSayPacket(const unsigned char *packet);

    List *m_pChatMessageList;
    int m_visibleChatPixelHeight;
};

bool HandleChatPacketType10(ChattingPane *pane, const unsigned char *packet);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0002EU router

Destination path: `by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ChattingPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] == 10)
        return HandleChatPacketType10(this, packet);

    if (packet[0] == 13)
        return HandleServerSayPacket(packet);

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 1 is the only target body. Its local enum cannot leak into another emitter or collide with unrelated protocol inventories.
- Destination 1 preserves both unconditional layout-entry `GetMemoryMan()` calls, current subtype-4 trailer-before-pointer order, active-map pointer loads for every subtype/default, subtype-local display-field reads, unchecked failures, and always-false return.
- Its two custom-color locals are deliberately uninitialized until the subtype-4 pre-switch read block; initializing them would add stores absent from the binary, while the same subtype value guarantees they are consumed only after assignment.
- The inferred `wchar_t text[256]` is the highest-ranked human declaration. The physical four-byte gap before the cookie is compiler alignment, not a claimed array tail.
- Destination 2 preserves the current complete class surface and free UID0002F0 declaration while replacing only the obsolete free target declaration with the private member.
- Destination 3 preserves observed opcode literals and UID0002F0's current free ABI; only opcode 13 changes to the accepted target member call.
- No third-party import directive applies.
## Final Recommendation

- C01-C43 are applied, already present, or excluded with reason at report-level detail under the accepted callback.
- Only UID0002EZ was renamed/memberized; Destinations 1-3 and the bounded Chatting class/router/file/aggregate/sink/predecessor synchronizations are applied without reducing independent evidence.
- Preserve UID0002F0 unchanged as the router's existing free helper. Preserve UID0003TN, UID0003UL, UID000416, UID0001MF, and UID0001MC unchanged as read-only evidence dependencies; this report proposes no rename, score, owner, metadata, prose, or formal change to them.
- Preserve target range, compiler table, padding, `Nested:0`, reconstructable state, Chatting source route, exact unsafe edge behavior, branch-local dereference/evaluation order, inferred `wchar_t[256]` plus alignment disposition, all raw displacement/caller/callee facts, and every historical/rejected disposition.
- Do not introduce a new child, protocol source file, shared opcode enum, packet wrapper, bounds guard, active-state accessor, scratch initializer, manual switch table, sender rewrite, or third-party import.
- Scoped validation and generated inspection completed successfully. Report lifecycle execution remains supervisor-owned external state and is not part of B005's callback work.

## Recommended Target Doc Changes

- UID0002EZ is renamed to `0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md` and titled `0x0047fd70-0x0047ff80 ChattingPane Handle Server Say Packet`.
- Completion/confidence are `92/92`; canonical owner/emitter are UID00001X; reconstructable true, blank position, and `Nested:0` are preserved.
- Destination 1 is applied exactly and byte-compared to the current target formal block.
- The Item Summary is:
  `Private ChattingPane server-say packet handler with a combined source body/compiler switch tail/alignment disposition; exact object-id/length/ACP text and custom-color trailer layout; Normal/Shout/BalloonOnly/Unfiltered/CustomColor behavior; current/legacy palette and suppression matrices; one ignored GetMemoryMan call before packet reads in each layout branch; current custom trailer reads before the active-map load; active UserPane pointer load on every subtype/default path but display-level dereference only for Normal/Shout; inferred wchar_t[256] plus pre-cookie alignment; unchecked malformed-packet behavior; and unconditional false return.`
- Raw hashes, exact table targets, all branch colors, conversion details, caller/callee inventory, current/legacy distinction, custom trailer, state producer/consumer evidence, rejected subtype names, owner-pollution history, and original-spelling/source-array confidence caps are preserved.
- The old free/static helper, `ChatType13_*`, `InitializePacketDecodeScratch`, `GetActiveLocalObjectChatState`, hoisted display-byte read, IDA `WCHAR[258]` source claim, and unresolved-blocker claims are historicalized as superseded rather than deleted.

## Recommended Support Doc Changes

| Destination | Exact applied/verified synchronization |
| --- | --- |
| UID00001X `by-class/ChattingPane.md` | Destination 2 is applied exactly; `91/93`, owner/emitter UID0000I5, all class declarations/fields/evidence, the free UID0002F0 declaration, and `[[CHILDREN]]` placement remain. Only the free target prototype became private `HandleServerSayPacket`; mixed ABI and local subtype-enum ownership are documented. |
| UID0002EU router | Destination 3 is applied exactly; `92/94`, owner/emitter UID00001X, range, Event ABI, secondary-view adjustment, false semantics, and `Nested:0` remain. Literal `10`/`13` and the free UID0002F0 call remain; only opcode 13 now calls the target member. |
| UID0000I5 `by-file/Chatting.md` | `87/90` and `NexusTK/social/` remain; the private member, free Type10 helper, address-ordered route, compiler-tail disposition, and rejected ownership/free-target history are documented. Its formal block is unchanged. |
| UID000104 ChattingUI aggregate | Score/metadata/range/nesting remain; only UID0002EZ's title/member owner/no-split disposition was synchronized, while UID0002F0 remains unchanged. |
| UID0002EQ AddChattingMessage | `90/92` and formal body remain; the exact accepted palette/custom-color matrix and once-per-layout-entry `GetMemoryMan()` caller context are applied. |
| UID0002EY predecessor | Raw body/padding evidence remains unchanged; only the renamed successor backlink/title was synchronized. |
| UID0002F0 sibling | Verify-only/no-change: retain path `0x0047ff80-0x00480640.ChatPacketType10Handler.md`, title, `87/90`, owner/emitter UID0000I5, current formal body, compiler tails, `Nested:0`, and unresolved subtype/helper source-quality caps. No Destination 4 exists. |
| UID0003TN MapPane packet handler | Verify-only/no-change: retain `by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md`, its current title, `87/91`, owner/emitter UID00007Q, blank formal block, blank position, `Nested:0`, and current prose. It supplies bounded packet/balloon evidence only; this report neither defers nor proposes its source completion. |
| UID0003UL player-settings parser | Verify-only/no-change: retain `by-memory/0x005aa480-0x005aa702.LivingObjectPaneParsePlayerSettingsPacket.md`, its current title, `86/88`, owner/emitter UID00007B, blank formal block, blank position, `Nested:8`, and current prose. Its live writer and raw duplicate are target evidence only; this report neither defers nor proposes its source completion. |
| UID000416, UID0001MF, UID0001MC senders | Verify-only/no-change: retain every current path/title/score/owner/emitter/range/nesting/formal/prose state. Their subtype and adjacent-send-level behavior is independent naming evidence; no sender destination or callback edit remains. |
| UID0003YJ, UID0000DD, UID0001HU | Verify-only/no-change provider contracts: value-first PacketBuffer scalar writers and `g_packetSender->QueueAndSendPacket(...)` remain binding. They reject the removed sender blocks and require no callback edit. |
| UID00026H ServerPacketNameTable | Verify-only/no-change: its emitted strings establish packet-name evidence but not a shared enum declaration. |
| UID0001SO MapServerPacketOpcode | Verify-only/no-change: retain `86/88`, owner/emitter UID0000L3, MapPane scope, current path/title/description, and blank formal block. No shared Chatting opcode enum or manual coverage change is proposed. |
| UID00007Q/UID0000L3 MapPane, UID0000FQ/UID0000P1 UserPane, UID0001KL/UID00007B aggregates, UID0000PR/UID0000QK globals | Verify-only/no-change: their current scores, metadata, declarations, and prose remain untouched. The target report carries the exact active-pointer/state evidence without creating new class/global layout work. |
| UID0000C3/UID0000D5/UID00001Q classes, UID0000N9 SayInputPanes file, raw sender/constructor siblings | Verify-only/no-change: preserve all current formal/prose/score/routes. No adjacent send-field synchronization is proposed. |
| UID0003YK PacketBuffer scalar reader and UID0000SW `g_useEpfAssets` | Verify-only/no-change: current BE32 reader and layout-mode evidence is already sufficient. |

No support destination beyond Destinations 2-3 received C++. The prose-only callback destinations were UID0000I5, UID000104, UID0002EQ, and the exact renamed-successor backlink in UID0002EY. Every other named support page above remained exact read-only/no-change evidence.

## Score And Metadata Recommendation

| Page | Historical | Current | Metadata disposition |
| --- | ---: | ---: | --- |
| UID0002EZ target | `86/90` | `92/92` | Owner/emitter UID00001X; reconstructable true; blank position; `Nested:0`; renamed path; Destination 1 applied. |
| UID00001X ChattingPane | `91/93` | unchanged | Owner/emitter UID0000I5; Destination 2 only. |
| UID0002EU router | `92/94` | unchanged | Owner/emitter UID00001X; Destination 3 only. |
| UID0000I5 Chatting file | `87/90` | unchanged | Existing social route; prose synchronization only. |
| UID000104, UID0002EQ, UID0002EY | current | unchanged | Bounded title/link/caller-context synchronization only; preserve all metadata and formal content. |
| UID0002F0, UID0003TN, UID0003UL, UID000416, UID0001MF, UID0001MC | current | unchanged | Exact verify-only/no-change; no rename, owner, formal, prose, score, or metadata action. |
| All other support | current | unchanged | Verify-only evidence; preserve owner/emitter/routes/nesting/formal/prose state. |

Completion reaches `92` because the body, ABI, packet layout, state route, source ownership, evaluation parity, split disposition, and complete first draft are resolved. Confidence is `92`, not `93` or higher, because the original subtype/field lexical spellings and exact source declaration behind the evidence-backed `wchar_t[256]` remain inferred even though behavior and physical layout are closed.

## Open Questions With Attempted Resolution

| Question | Checks performed | Resolution |
| --- | --- | --- |
| What does opcode 13 mean, and where are constants declared? | Exact UID00026H packet-name string/table, UID0001SO inventory/formal state, router bytes, current generated source, class/file emitter order. | Closed: the string is `kServerSay`, but no shared emitted enum is proven. Preserve router literals `10`/`13`; keep `ServerSaySubtype` local to Destination 1. |
| Is the target helper static/free/member? | Router adjustment, ECX propagation, stack args, return cleanup, sink calls, sibling audit. | Closed: private ChattingPane member. UID0002F0 independently remains free. |
| What are bytes 2-5? | Target disassembly and MapPane same-packet parser. | Closed: BE32 speaking/target object id, intentionally unused by target. |
| Is text NUL terminated in packet? | Conversion call parameters and terminator store. | Closed: no packet NUL required; exact byte count is used. |
| Is the source local `[256]` or `[258]`? | Exact frame reserve, cookie, two dword temporaries, text base, every indexed access, conversion capacity, terminator bound, and three same-toolchain sender frames. | Closed for source reconstruction: `wchar_t text[256]` ranks first; `[258]` is lower-probability IDA gap coalescing; smaller is impossible because element 255 can be written. This inference is an explicit confidence cap. |
| Can conversion index exceed the local output? | Length is u8 max 255; output capacity 256; return narrowed to u8. | Closed: valid conversion writes at most index 255; failure writes index 0; preserve narrowing. |
| Can custom offset wrap? | u8 length plus 7/11 and 16-bit narrowing. | Closed: it cannot wrap for a one-byte length, but exact casts and absent trailer bounds checks remain. |
| When do active pointers and display fields dereference? | Full 149-instruction disassembly and branch address matrix for both layouts and subtype 0-4/default. | Closed: each layout loads the active UserPane after conversion; current subtype 4 reads trailer first; only subtype 0/1 dereferences `m_sayDisplayLevel`. No hoist or null guard is legal. |
| What are subtype names? | Outgoing sender behavior, incoming gates, MapPane balloon behavior, both layout branches, string/source/report searches. | Closed with evidence-backed descriptive names and explicit lexical confidence cap. |
| What are `+0x134101/+0x134102`? | Every displacement hit, constructor/settings producer, Chatting/MapPane receivers, senders. | Closed descriptively as say display/send levels. Only the receive field is emitted by this target; support pages remain unchanged. |
| Is `0x5ab760` live? | Code/data xrefs, pointer scans, dispatcher audit. | Closed: unreferenced raw duplicate; negative target evidence only. |
| Should the target table split? | Exact bytes, targets, xrefs, neighboring functions, source impact. | Closed: no split/new child. |
| Must UID0002F0 be renamed or completed here? | Current formal/body, unresolved helper/type surface, router ABI, scope dependency analysis. | Closed: no. Preserve it byte-for-byte except ordinary renamed-target backlinks if any. This is a no-change disposition, not deferred work. |
| Must UID0003TN or UID0003UL change? | Current scores/formal blocks and the exact evidence consumed by this target. | Closed: no. They are bounded evidence providers with exact verify-only/no-change dispositions; no source blocker is carried as a callback claim. |
| Must sender bodies change? | Current UID0003YJ/UID0000DD/UID0001HU provider contracts and target dependency analysis. | Closed: no. Removed blocks were contradicted and unrelated; all sender pages remain unchanged. |
| Does a third-party import apply? | Web/source searches and repository provenance search. | Closed: no relevant original source found; no import. |

No in-scope question remains deferred. Remaining uncertainty is lexical/source-declaration confidence, not a body, ABI, compile, ownership, range, or callback blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B005 did not manually edit manual coverage or tracker files. The callback made only the four rows below require synchronization; exact supervisor-owned replacements remain supplied independent of whether external lifecycle work has since applied them. All other named rows are explicitly verify-only and receive no replacement/addition/deletion. Validator `000000010584` did mechanically refresh target path references in `by-memory/-coverage-report.md` as an authorized validator side effect; B005 made no manual coverage edit.

### `by-memory/-coverage-report.md`

Replace the existing UID0002EZ row:

`        - [UID:0002EZ][0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket](by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md) 0x0047fd70-0x0047ff80 | ChattingPane member packet handler + compiler switch data | ChattingPaneHandleServerSayPacket : reconstructable : 92% : very-strong : Private server-say member with exact combined body/table/alignment, router-only receiver route, object-id/length/ACP text and custom-trailer layout, five behavior-resolved subtypes, current/legacy gates and colors, one layout-entry GetMemoryMan call, exact active-pointer/display-field dereference parity, inferred wchar_t[256] plus pre-cookie alignment, unchecked malformed-packet behavior, and unconditional false return.`

Replace the existing UID0002EU row:

`        - [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) 0x0047f890-0x0047f8c9 | method | ChattingPaneChatPacketRouter : reconstructable : 92% : very-strong : Exact Event packet router with secondary-view compiler adjustment, literal opcode 10 free-helper dispatch, literal opcode 13 private-member dispatch, false default/helper semantics, vtable-only liveness, exact range, and seven-byte alignment before OnPaint.`

Verify-only/no manual row change: UID0002F0 retains its current path/title/manual row because no callback state changes. UID000104, UID0002EQ, and UID0002EY retain their current manual rows because bounded prose/backlink synchronization does not change their path, title, score, confidence, reconstructable state, or source-quality classification.

### `by-class/-coverage-report.md`

Replace the existing UID00001X row:

`- [UID:00001X][ChattingPane](by-class/ChattingPane.md) : reconstructable : 91% : very-strong : Scrollable chat display pane attached to Chatting.cpp with complete class surface, exact scroll/input/paint/message methods, two proven fields, private HandleServerSayPacket member, preserved free HandleChatPacketType10 helper declaration, mixed-ABI Event router, compiler-tail dispositions, and preserved source order.`

Verify-only/no manual row change: MapPane, UserPane, ChatInputPane, SayInputPane, and ShoutInputPane classes are not callback destinations.

### `by-file/-coverage-report.md`

Replace the existing UID0000I5 row:

`- [UID:0000I5][Chatting](by-file/Chatting.md) : reconstructable : 87% : strong : NexusTK/social/Chatting.cpp owns ChattingPane, exact Event packet routing, private server-say member handling, preserved free Type10 helper, message insertion, compiler switch-table tails, input/history dependencies, and current/legacy layout behavior with stripped subtype/field/source-array spellings retained as bounded confidence caps.`

Verify-only/no manual row change: MapPane, UserPane, and SayInputPanes files are not callback destinations.

### `by-type/by-enum/-coverage-report.md`

The exact current UID0001SO row at line 22 was inspected read-only:

```text
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) : reconstructable : 86% : strong : MapPane inbound opcode index; B014 updates opcode `0x5a` to the PhotoPane/map-photo snapshot packet with `uint16 mapId`, `uint16`/low-byte avatar shape, `uint8 avatarDirection`, `uint8 avatarTileX`, and `uint8 avatarTileY`, while preserving MapPane as router and [UID:0000MK][PhotoPane](by-file/PhotoPane.md) as implementation owner.
```

This row remains exact verify-only text. No replacement, addition, or deletion is proposed because UID0001SO is not changed and this report emits no shared opcode enum. This exact file is the manual enum-coverage destination; the former ambiguous `by-type/-coverage-report.md or enum manual coverage` instruction is rejected.

No `by-global/-coverage-report.md` row changes: UID0000PR and UID0000QK remain untouched. No manual rows are proposed for UID0003TN, UID0003UL, UID000416, UID0001MF, or UID0001MC because those ordinary pages remain unchanged.

The final waited validators refreshed generated coverage/tracker state mechanically. This report does not assert a durable lifecycle count or prescribe manual tracker edits.

## Follow-Up Actions

- C01-C43 and Destinations 1-3 were completed one ordinary page at a time under short leases.
- Prose-only synchronization was limited to UID0000I5, UID000104, UID0002EQ, and UID0002EY's renamed-successor backlink.
- UID0002F0, UID0003TN, UID0003UL, UID000416, UID0001MF, UID0001MC, and provider/type/global evidence pages remained unchanged and unleased.
- Every changed ordinary page passed scoped validation; final waited refresh `000000010625` completed and all B005 leases were released.
- Generated `NexusTK/social/Chatting.cpp` was inspected read-only and satisfies the exact positive/negative assertions recorded below.
- Manual coverage synchronization, independent review, execution, movement, archival, and durable tracker state remain supervisor-owned external state rather than pending B005 report work.

## Confidence

| Area | Confidence | Basis / cap |
| --- | --- | --- |
| Range/table/padding | 100 | Exact bytes, modeled boundaries, internal table targets, hashes. |
| Member ABI/owner/source | 97 | Receiver/caller/sink/address band/class/file all agree. |
| Packet layout/branches/colors | 99 | Target and independent MapPane sibling plus complete CFG. |
| Runtime dereference/evaluation parity | 99 | Complete addressed disassembly for both layouts and subtype 0-4/default. |
| Source local `wchar_t[256]` | 90 | Capacity/access/frame/sibling controls select it; original declaration is stripped. |
| State-byte roles/value matrix | 96 | Exhaustive displacement inventory, live producer, all consumers. |
| Protocol family name | 99 | Exact packet-name table string `kServerSay`. |
| Normal/Shout names | 96 | Mirrored outgoing sender and incoming gate semantics. |
| BalloonOnly/Unfiltered spellings | 88 | Behavior is exact; original lexical names are stripped. |
| `m_sayDisplayLevel` / `m_saySendLevel` spellings | 91 | Roles/value ranges exact; original field spellings stripped. |
| First-draft behavioral fidelity | 95 | Complete body preserves evaluation order, unchecked faults, conversion/trailer behavior, and omissions. |

Current target confidence is `92`.

## Validator Results

- Historical Gate 1 fact: no implementation validator or lease was used during report-only research; MCP calls were research evidence, and interrupted broad requests were followed by successful bounded calls rather than fallback-only completion.
- `000000010584` at `2026-07-14T03:16:36-04:00`: renamed UID0002EZ scoped validation, exit `0`, `ok:1`; registered path update, `92/92`, owner UID00001X, deferred generation, and mechanically refreshed inbound references including the manual by-memory coverage link.
- `000000010593` at `2026-07-14T03:19:05-04:00`: UID00001X class scoped validation, exit `0`, `ok:1`; registry/projected-stat refresh, generation deferred.
- `000000010598` at `2026-07-14T03:20:48-04:00`: UID0002EU scoped validation, exit `0`, `ok:1`; registry/reference/link refresh, generation deferred.
- `000000010604` at `2026-07-14T03:21:54-04:00`: UID0000I5 scoped validation, exit `0`, `ok:1`; reference/link/projected-stat refresh, generation deferred.
- `000000010608` at `2026-07-14T03:22:54-04:00`: UID000104 scoped validation, exit `0`, `ok:1`; link/projected-stat refresh, generation deferred.
- `000000010610` at `2026-07-14T03:23:39-04:00`: UID0002EQ scoped validation, exit `0`, `ok:1`; generation deferred. `000000010616` at `2026-07-14T03:25:12-04:00` revalidated the corrected exact custom-style argument, exit `0`, `ok:1`.
- `000000010613` at `2026-07-14T03:24:12-04:00`: UID0002EY scoped validation, exit `0`, `ok:1`; generation deferred.
- `000000010617` at `2026-07-14T03:25:22-04:00`: first authorized waited target refresh, exit `0`, `ok:1`, generated refresh completed. The consistency pass then caught two support-prose boundary/offset transcription defects rather than accepting them.
- `000000010623` at `2026-07-14T03:26:59-04:00`: UID0000I5 correction validation, exit `0`, `ok:1`; exact text offset `+7`, trailer offsets `7+length`/`11+length`, table end `0x47ff74`, and twelve-byte alignment restored.
- `000000010624` at `2026-07-14T03:27:21-04:00`: UID000104 correction validation, exit `0`, `ok:1`; exact table/alignment bounds restored.
- `000000010625` at `2026-07-14T03:27:36-04:00`: final authorized waited target refresh, exit `0`, `ok:1`; registry rebuilt with 4,741 nodes/3,840 edges and generated refresh completed. Existing project-wide warnings were `autogen_children_fallback_insert`, `autogen_children_marker_missing`, and `autogen_emitter_has_no_code`; none names UID0002EZ as an empty emitter or invalid target.
- Lease proof: each ordinary page was the sole B005 lease while it was reread, edited, and scoped-validated; each explicit `B005 unlease` returned `Success` before the next ordinary page was leased. The final target lease around `000000010625` also returned `Success`, and the final `current_leases.md` read contains no B005 entry.
- Validator side effects, not manual edits: validator registry/projected statistics/reference indexes, `by-memory/-coverage-report.md` path/link refresh, generated metadata/coverage reports, generated research tracker, and generated C++ including `NexusTK/social/Chatting.cpp` were refreshed. No coverage/generated/tracker/audit/supervisor/lifecycle file was manually edited.
- Final generated assertions: B005's waited refresh was `000000010625`. A later post-B005 read-only verification observed concurrent validator header command `000000010640` at `2026-07-14T03:33:05-04:00` and reconfirmed one private target declaration, one target definition, one target UID marker, one method-local `ServerSaySubtype`, and one `wchar_t text[256]`; router order was literal 10 free call then literal 13 member call; free UID0002F0 declaration/body remained after the target; old `HandleChatPacketType13`, shared `ServerPacketOpcode`, target Empty Emitter Marker, source switch-table declaration, and manual padding source were absent. The later command is observed external validator state, not claimed as B005 work.

## Changed Files

- Manually renamed `by-memory/0x0047fd70-0x0047ff80.ChatPacketType13Handler.md` to `by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md` and edited the renamed page.
- Manually edited `by-class/ChattingPane.md`, `by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md`, `by-file/Chatting.md`, `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`, `by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md`, and `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`.
- Updated `tools/leaser/Agents/Agent-B005/research/0002EZ-ChatPacketType13Handler-source-quality.md`, the same lifecycle artifact.
- Validator-owned side effects include `by-memory/-coverage-report.md`, generated coverage/metadata/registry/tracker state, and `auto-generated/NexusTK/social/Chatting.cpp`; these were not manually edited. No verify-only ordinary page, supervisor/audit/lifecycle file, or IDA database was changed.

## Implementation Tracking Checklist

- [x] Supervisor accepted C01-C43 and the repaired three-destination scope at Gate 1 SHA `E4139CEB086971C67F80CEF8B0B30003E2ADCAB289BAF380ACB3E2A039EFF60F`.
- [x] Re-read/leased UID0002EZ; applied rename, `92/92`, owner/emitter UID00001X, Item Summary, full evidence/history, and Destination 1.
- [x] Validated UID0002EZ and released its lease; final waited validation is `000000010625`.
- [x] Re-read/leased/applied/validated/released UID00001X with exact Destination 2 and preserved free UID0002F0 declaration.
- [x] Re-read/leased/applied/validated/released UID0002EU with exact Destination 3, literal opcodes, mixed calls, and preserved evidence.
- [x] Re-read/leased/applied/validated/released UID0000I5, UID000104, UID0002EQ, and UID0002EY only for accepted bounded prose/backlink changes.
- [x] Verified UID0002F0 unchanged in path/title/`87/90`/owner/emitter/formal body/range/table/alignment/nesting and independent source-quality state.
- [x] Verified UID0003TN and UID0003UL unchanged in path/title/score/owner/emitter/formal/prose/metadata/nesting.
- [x] Verified UID000416, UID0001MF, UID0001MC, UID0003YJ, UID0000DD, and UID0001HU unchanged; no sender/provider destination exists.
- [x] Verified UID00026H and UID0001SO unchanged; no shared opcode enum or type-page callback change exists.
- [x] Preserved evaluation/dereference parity, `wchar_t[256]` ranking, exact range/table/padding, packet/state matrices, unsafe edges, rejected alternatives, negative evidence, and historical assumptions.
- [x] Confirmed exactly three managed destination blocks, each byte-identical to its destination formal block, and no additional proposed C++.
- [x] Confirmed no third-party import directive applies.
- [x] Ran scoped validation for every changed ordinary page while leased; command IDs, timestamps, results, side effects, and release status are recorded above.
- [x] Ran final authorized waited generated refresh `000000010625` only after all scoped validations passed.
- [x] Verified generated Chatting.cpp read-only for every stated positive and negative assertion.
- [x] Updated this report to legal callback states, claim-specific proof, exact changed-file/validator evidence, checked responsibilities, and archive-neutral lifecycle wording.
- [x] Made no manual coverage/tracker/generated/supervisor/audit/lifecycle edits and ran no execute/probe/move/archive action; external lifecycle state remains supervisor-owned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000010718","destination_path":"executed-b-agent-research/B005/0002EZ-ChatPacketType13Handler-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002EZ-ChatPacketType13Handler-source-quality.md","timestamp":"2026-07-14T04:18:07-04:00","uid":"0002EZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
