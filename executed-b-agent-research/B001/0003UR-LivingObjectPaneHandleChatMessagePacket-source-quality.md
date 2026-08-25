** TARGET-REPORT-UID:0003UR **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UR **
# 0003UR LivingObjectPaneHandleChatMessagePacket Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003UR] as a reconstructable `LivingObjectPane` method under [UID:00007B][LivingObjectPane](../../../../by-class/LivingObjectPane.md), emitted through [UID:00007B] / [UID:0000KU][LivingObjectPane.cpp](../../../../by-file/LivingObjectPane.md).
- Final disposition: source-quality pass resolves the active open questions enough for first-draft C++ with role-based names. Do not move ownership to `Chatting` or `SayInputPanes`; those are support/consumer modules.
- Recommended source-facing signature: `bool LivingObjectPane::HandleChatMessagePacket(const unsigned char *packet)`. The stronger semantic alias for comments/search is `HandleIncomingWhisperSenderHistoryPacket`, because the only accepted subcase is opcode `0x0a` subtype `0` and the side effect is incoming/fallback whisper-sender history.
- Recommended score/metadata after implementation: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`. Keep the current filename unless the supervisor wants a coordinated rename to `LivingObjectPaneHandleIncomingWhisperSenderHistoryPacket`.
- C++ recommendation: populate a first-draft C++ block in the target. Exact original protocol enum and member spellings are not symbol-proven, but all control flow, payload offsets, string filters, list behavior, caller route, and source owner are now sufficiently reconstructed for role-based source.
- Confidence: high for binary behavior and route; medium-high for final original field/helper spellings.

## Supporting Research

## Target

- Target UID: `0003UR`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005ab860-0x005aba7b.LivingObjectPaneHandleChatMessagePacket.md`.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `RECONSTRUCTION_CPP`.
- Current target open questions: final packet subtype, text-buffer names, Chatting dependency names, and final C++ readiness.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003UR-LivingObjectPaneHandleChatMessagePacket-source-quality.md`.

## Executive Recommendation

`0x005ab860-0x005aba7b` is a true modeled function and should remain an exact by-memory method page. Its source owner is `LivingObjectPane`, reached from `UserPane::HandleServerMessage` by subtracting `0xa0` from the dispatcher receiver and passing the packet pointer. The dispatcher selector table maps first payload byte `0x0a` to the call at `0x005a7b3a`.

The packet body is not a general chat-display insertion helper. It accepts only subtype byte `packet[1] == 0`, reads a two-byte big-endian text length at `packet+2`, copies `packet+4` bytes into a stack ANSI buffer, converts that text to UTF-16, filters out outgoing/angle-bracket display forms, extracts the sender prefix before the chat format delimiter `L"\" "`, rejects sender prefixes containing spaces, and updates the inbound/fallback whisper-sender history list at `this+0x13eb0c`. After storing a sender, it clears `this+0x13eb10` so the direct-message name-entry UI uses the inbound/fallback sender history path.

`Chatting` owns the display-side format strings and `ChattingPane` insertion helpers, and `SayInputPanes` consumes the history lists through `SayToUserNameInputPane`, but neither owns this server-message handler. The method mutates local-player/LivingObjectPane aggregate fields and is directly called from the local UserPane server-message dispatcher.

## Supervisor Active Recheck

- This was a report-only assignment. No by-* documentation file and no `by-memory/-coverage-report.md` file was edited.
- No split execution is recommended for this target. The target itself is an exact IDA/PE-modeled function from `0x005ab860` through `0x005aba7b`.
- Adjacent-range note: the bytes immediately before and after the target are not just target padding. A pre-target raw/prologue-shaped body exists after `0x005ab75d` and before `0x005ab860`, and a post-target raw/prologue-shaped body exists after the five `0xcc` bytes at `0x005aba7b-0x005aba80` and before the separate `0x005abb20` user-list helper. Do not extend [UID:0003UR] backward or forward to absorb those bodies.
- Scoped validator baseline was run without `--apply`; see validator section.

## Inference Research Guidance Check

- `by-structure.md` gate: the target is reconstructable, has a nonblank owner/emitter route through a parent at/over `85/85`, and average child score is above the C++ draft threshold. The remaining issues are role-name polish, not ownership or range blockers.
- `inference_research.md` standard: this report separates direct executable facts from documentation evidence and role-name inference. Existing docs and older B reports were treated as leads; route, opcodes, literals, and field roles were rechecked against local PE/Capstone evidence and current by-* docs.
- MCP note: the current pass used read-only local PE bytes and current by-* evidence. The active MCP endpoint was unavailable during the run; existing support docs still provide prior IDA MCP evidence where cited. The local PE path checked was `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Wave/source-data note: no wave2/wave3 source file was used as authority. Existing by-* docs that mention generated or Wave lead material were used only for context and were revalidated against executable/disassembly evidence.

## Heuristic / Inference Reanalysis And Validation

### Generated Function Name `sub_5AB860`

- Best-supported source-facing name: `LivingObjectPane::HandleChatMessagePacket`.
- Stronger behavioral alias: `HandleIncomingWhisperSenderHistoryPacket`.
- Evidence: dispatcher opcode `0x0a` routes directly to `0x005ab860`; the current target and LivingObjectPane support docs already use `HandleChatMessagePacket`; the callee accepts only `packet[1] == 0`, extracts a sender name before the quote-space delimiter, and updates incoming/fallback whisper-sender history.
- Rejected alternative, `ChattingPane::HandleChatPacketType10`: this function is not called by `ChattingPaneChatPacketRouter`, does not call `AddChattingMessage`, and mutates `this+0x13eb0c/+0x13eb10` on the local-player/LivingObjectPane aggregate.
- Rejected alternative, `SayToUserNameInputPane` helper: the say-input panes consume the list but do not call this handler; the direct caller is `UserPane::HandleServerMessage`.
- Remaining uncertainty: exact original C++ method spelling is not symbol-proven. The role-based name is source-safe and better than retaining `sub_5AB860`.

### Caller / Dispatch Route

- Best-supported route: `UserPane::HandleServerMessage` opcode `0x0a` case.
- Evidence: dispatcher prologue reads `payload[0]`, subtracts `4`, maps through selector table `0x005a8324`, then jumps through table `0x005a82c0`. Decoded selector table maps opcode `0x0a` to jump index `3`, target `0x005a7b33`, where the dispatcher pushes the packet pointer and calls `0x005ab860` with `ecx = ebx - 0xa0`.
- Direct rel32 scan: exactly one direct call to target was found, `0x005a7b3a -> 0x005ab860`.
- Receiver meaning: `ecx = ebx - 0xa0` matches the adjusted LivingObjectPane receiver inside the local UserPane aggregate. This supports `LivingObjectPane` ownership for the packet body while the dispatcher method itself remains `UserPane`-owned.
- Rejected alternative, hidden table/pointer route: local PE direct rel32 scan found no other direct call to `0x005ab860`; switch decoding accounts for the live route.

### Packet Opcode, Subtype, And Payload Semantics

- Top-level opcode: `0x0a`, selected by `UserPane::HandleServerMessage` from payload byte `packet[0]`.
- Accepted subtype: `packet[1] == 0` only. The callee reads `packet+1` through `0x00575470`, a tiny byte-load/narrow-char helper. If the subtype is nonzero, it returns `false` without side effects.
- Text length: `uint16_t textByteCount = PacketBufferReadUInt16BE(packet + 2)`, implemented by `0x00575480`.
- Text payload: raw bytes begin at `packet+4`, with exactly `textByteCount` bytes copied to a `0x8000` byte stack buffer.
- Text conversion: appends a byte NUL at `ansi[textByteCount]`, then calls `MultiByteToWideChar(0, 0, ansi, textByteCount, wide, 0x8000)`. Code page `0` is CP_ACP. The converted UTF-16 text is explicitly NUL-terminated.
- Range checks: byte length `>= 0x8000` and converted wide length `>= 0x8000` route to `__report_rangecheckfailure`.
- Return: the function sets `al = 0` on all modeled normal paths. The dispatcher preserves that `al` when jumping to its common epilogue for this case. Treat return as `bool false` / consumed flag false, not as an append-success indicator.
- Rejected alternative, one-byte length: the function calls `0x00575480` on `packet+2`; byte-reader `0x00575470` is used only for subtype.
- Rejected alternative, length includes the subtype/header: copy source is `packet+4`, and length is read from the two bytes immediately before it.

### Text Filters And Format Literal Meanings

- `0x00614c54` decodes as UTF-16 `L"> "`. The target calls `wcsstr(wideText, L"> ")` and returns if found.
- The first three-character filter also rejects strings beginning with `L"-> "`. This is an explicit outgoing-whisper/direct-message prefix check before the broader `L"> "` substring search.
- `0x00615284` decodes as UTF-16 `L"\" "`. The target calls `wcsstr(wideText, L"\" ")`, requires that delimiter, and overwrites the delimiter with NUL to isolate the sender prefix.
- Current Chatting string docs already identify `0x00615284-0x006152c8` as chat message format fragments: `L"\" "`, `L") "`, `L"] "`, and format strings `%s%s"%s`, `%s%s]%s`, `%s%s>%s`. `0x00615284` has a representative `sub_5AB860` xref.
- Best semantic inference: subtype-zero messages are display-formatted as `sender" message`; this handler extracts `sender` for reply/history. The `L"> "` rejection excludes outgoing/direct prompt and angle-bracket style messages, including clan/angle display forms.
- Rejected alternative, `0x00614c54` as a unique Chatting-owned literal: it is also the SayInputPane prompt literal `L"> "`. The text value is what matters for filtering; its reuse does not transfer ownership to SayInputPanes.

### Sender Name Extraction And Limits

- After replacing the quote-space delimiter with NUL, the handler copies the prefix from the large converted buffer into a local wide buffer through `0x005ddbec`, the CRT `wcsncpy_s` implementation.
- It then explicitly writes NUL to the local buffer slot corresponding to `[ebp-0xbe]`. Relative to the local name scratch start at `[ebp-0x104]`, this is index `35` in `wchar_t` units. Treat this as a defensive sender-name truncation/write barrier, not as proof that the stored list element is 128 wide characters.
- It rejects the candidate sender if `wcschr(sender, L' ')` finds a space. This strongly supports "player name / sender name" rather than arbitrary message prefix.
- The history list elements are constructed as `List(0x40, 0x0a)` in `UserPane` constructor arms, so the stored element width is `0x40` bytes with a capacity/page size of ten. Final source should not model this as `std::wstring`; use a fixed-width `List` entry or a project-specific name slot type.
- Remaining uncertainty: exact original name-slot typedef is not recovered. Best role name is `WhisperNameHistoryEntry` or `FixedWideNameSlot`, backed by a generic `List`.

### History Fields And List Helper Roles

- `this+0x13eb08`: outgoing/recent direct-message recipient history. Evidence: `sub_5A4B60` deduplicates/caps/inserts into this list and sets `this+0x13eb10 = 1`; `SayToUserNameInputPane` confirmation handlers call `sub_5A4B60` after the user enters a recipient.
- `this+0x13eb0c`: incoming/fallback whisper-sender history. Evidence: target [UID:0003UR] deduplicates/caps/inserts into this list and sets `this+0x13eb10 = 0`; `sub_5A4C30` and one branch of `SayToUserNameInputPaneHistoryNavigation` read this list as the fallback/inbound path.
- `this+0x13eb10`: current whisper-history source selector byte. Evidence: `sub_5A4B60` sets it to `1` after storing an outgoing recipient, while target clears it after storing an incoming sender. `SayToUserNameInputPane` constructor checks it: set uses the `+0x13eb08` path (`sub_5A4AB0`), clear uses the `+0x13eb0c` path (`sub_5A4C30`).
- List operations:
  - `list+0x0c` is count.
  - vslot `+0x10` returns element address by index (`ListGetElementAt`).
  - vslot `+0x18` inserts a one-element range at index `1` (`ListInsertRange` / insert).
  - vslot `+0x1c` removes a one-element range (`ListRemoveRange`).
- Target algorithm: scan existing entries; if duplicate found, remove duplicate; if not duplicate and count is at least ten, remove index `0`; insert the new sender at index `1`; clear selector byte to inbound/fallback.
- Rejected alternative, append-only history: the handler explicitly scans for duplicates, removes old duplicate positions, trims when count reaches ten, and inserts at index `1`, not append-at-end.
- Rejected alternative, `+0x13eb0c` is generic chat display history: it is consumed by direct-message name-entry helpers, not by `ChattingPane`.

### Helper / Runtime Name Resolution

| Address / generated name | Best-supported name | Evidence / decision |
| --- | --- | --- |
| `0x00575470` | `std::_Narrow_char_traits<char,int>::to_char_type` / byte load | Disassembly is `mov al, [arg]`. PacketBuffer docs classify it as runtime/STL helper adjacent to PacketBuffer helpers. In C++ draft, use `packet[1]`. |
| `0x00575480` / `sub_575480` | `PacketBufferReadUInt16BE` | Disassembly reads `(p[0] * 0x100) + p[1]`; PacketBuffer scalar read docs name this helper. |
| `0x00516030` / `sub_516030` | `GetMemoryMan` / memory-manager touch | Existing MemoryMan/List/Encoder docs resolve it as process memory-manager accessor. |
| `0x00516220` / `sub_516220` | `MemmoveWrapper` / `MemoryMan::CopyBytes` | Existing docs and call shape copy `textByteCount` bytes from packet to stack buffer. |
| `MultiByteToWideChar` IAT `0x0060d120` | Win32 ANSI-to-wide conversion | Direct imported call with code page and flags both zero. |
| `0x005ca676` | `wcsstr` | Wide substring search; target uses it for `L"> "` and `L"\" "`. |
| `0x005ddbec` / thunk to `0x005ddb1f` | `wcsncpy_s` | Disassembly matches secure wide copy signature `(dst, dstSize, src, count)`. |
| `0x005ca50d` | `wcschr` | Wide character search; target passes `0x20` for space. |
| `0x005c7655` | `__report_rangecheckfailure` | Range-check failure tail after stack buffer bounds checks. |
| `0x005c7740` / `0x005c772f` | `__alloca_probe` / stack-cookie check | Compiler/runtime stack allocation and security cookie support. |

### Ownership And Source Placement

- Accepted owner: [UID:00007B] `LivingObjectPane`.
- Accepted source file: [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Evidence for LivingObjectPane: direct dispatcher call adjusts the receiver to the LivingObjectPane subobject; the body mutates local-player/LivingObjectPane aggregate fields; current class/file docs define server packet handlers in this method family; parent and file route satisfy the strict gate.
- Evidence against `Chatting`: no `ChattingPane` receiver, no `g_pChattingDisplayPane`, no call to `AddChattingMessage` or `AddIncomingMessage`; uses only shared Chatting format literals as parsing delimiters.
- Evidence against `SayInputPanes`: no SayInputPane receiver/caller; SayInputPanes only reads the history lists later to prefill or navigate recipient names.
- Evidence against `UserPane`: the caller is UserPane-owned, but it adjusts `this` to the LivingObjectPane subobject before calling; current LivingObjectPane docs treat local-player server packet helpers as LivingObjectPane methods even when reached through `UserPane::HandleServerMessage`.

### Range / Split Decisions

- Keep [UID:0003UR] range exactly `0x005ab860-0x005aba7b`.
- Do not split inside the function. All code from prologue through `ret 4` belongs to one cohesive handler.
- Do not extend backward. `0x005ab75d-0x005ab860` contains three `0xcc` bytes followed by a separate prologue-shaped/raw body before this target.
- Do not extend forward. `0x005aba7b-0x005aba80` is five `0xcc` bytes, then a separate prologue-shaped/raw body appears before the standalone `0x005abb20` user-list packet helper.
- The post-target raw body and the retained no-route `0x005abb20` user-list helper are neighboring packet-tail issues, not part of [UID:0003UR].

### Final C++ Readiness

- First-draft C++ is now safe. The method is an exact modeled function with a live caller, fixed packet layout, concrete field side effects, and owner/emitter route.
- Remaining uncertain spellings should be represented as descriptive role names, not as hard blockers: `ServerOpcode_ChatMessage`, `ChatMessageSubtype_Whisper`, `m_recentWhisperRecipients`, `m_incomingWhisperSenders`, and `m_whisperHistorySource`.
- C++ should not pretend this method appends visible chat lines. It only updates reply/history state.
- C++ should not include `PacketBufferReadByte` for `0x00575470`; direct `packet[1]` is closer to source form.

## Evidence Standards Used

- Local PE/Capstone disassembly of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Direct rel32 scan for callers.
- Decoded `UserPane::HandleServerMessage` selector table at `0x005a82c0` and selector byte table at `0x005a8324`.
- UTF-16 literal decoding from `.rdata`.
- Current by-* support docs for `LivingObjectPane`, `UserPane`, `Chatting`, `SayInputPanes`, `List`, and PacketBuffer helpers.
- Existing B001/B-agent reports were used as leads only where current by-* docs or PE evidence agreed.
- Negative evidence: no `ChattingPane` insertion call, no alternate direct rel32 caller, no reason to absorb adjacent raw/prologue-shaped bodies into this page.

## IDA / PE Facts

### Function / Range Facts

- Target disassembly starts at `0x005ab860` with normal prologue and `__alloca_probe(0x18108)`.
- Target returns at `0x005aba68` with `ret 4`; final instruction before the function end is range-failure call at `0x005aba76`.
- Exact covered bytes are `0x005ab860-0x005aba7b`.
- Stack locals:
  - wide text buffer at `[ebp-0x18104]`, `0x8000` UTF-16 code units.
  - ANSI byte buffer at `[ebp-0x8104]`, `0x8000` bytes plus explicit byte NUL.
  - sender scratch at `[ebp-0x104]`.
- The handler sets `al = 0` before its normal epilogue.

### Dispatch Facts

- Dispatcher first-byte decode: `movzx eax, byte ptr [edi]`; `add eax, -4`; bounds `<= 0x7f`; selector byte at `0x005a8324`; jump table at `0x005a82c0`.
- Selector table mapping: opcode `0x0a` maps to index `3`, jump target `0x005a7b33`.
- At `0x005a7b33`: `push edi`; `lea ecx, [ebx-0xa0]`; `call 0x005ab860`; `jmp 0x005a829a`.
- Direct rel32 scan: one target call, `0x005a7b3a`.

### Literal Facts

- `0x00614c54`: UTF-16 `"> "`.
- `0x00615284`: UTF-16 `" "`, represented in C++ as `L"\" "`.
- `0x00615298`: `%s%s"%s`.
- `0x006152b0`: `%s%s]%s`.
- `0x006152c0`: `%s%s>%s`.

### List / Field Facts

- `UserPane` constructor arms allocate three `List` objects:
  - `this+0x13eb04` constructed as `List(0x200, 0x0a)`.
  - `this+0x13eb08` constructed as `List(0x40, 0x0a)`.
  - `this+0x13eb0c` constructed as `List(0x40, 0x0a)`.
- `this+0x13eb10` initialized to zero in constructor arms.
- `sub_5A4B60` uses `this+0x13eb08`, deduplicates/caps/inserts at index `1`, and sets `this+0x13eb10 = 1`.
- Target uses `this+0x13eb0c`, deduplicates/caps/inserts at index `1`, and sets `this+0x13eb10 = 0`.
- `sub_5A4C30` reads `this+0x13eb0c` as the fallback/inbound history path.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005ab860-0x005aba7b` | [UID:0003UR] `LivingObjectPaneHandleChatMessagePacket` | opcode `0x0a`, subtype `0`, incoming whisper sender-history updater | yes | [UID:00007B] `LivingObjectPane` | `88/91` | keep, update details and add C++ |
| `0x005a76c0-0x005a82bd` | [UID:0003VB] `UserPaneHandleServerMessage` | dispatcher/caller | yes | [UID:0000FQ] `UserPane` | no target rescore required | add opcode `0x0a` route detail if implementation callback includes support docs |
| `0x005a82bd-0x005a83b0` | [UID:0003VC] `UserPaneHandleServerMessageSwitchTables` | compiler selector/jump tables | no | none | no target rescore required | add decoded opcode `0x0a -> 0x005a7b33` if touched |
| `0x005a4b60-0x005a5791` | [UID:0001KO] `SayModeHelpers` | outgoing/fallback whisper history helpers | no aggregate | mixed | no target rescore required | add field-name cross-reference if touched |
| `0x005b3cb0-0x005b4219` | [UID:0001MD] `SayToUserNameInputPane` | consumes history selector/list paths | yes | [UID:0000C7] | no target rescore required | add `+0x13eb08/+0x13eb0c/+0x13eb10` names if touched |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a7b3a` | direct call to `0x005ab860` | live opcode `0x0a` dispatcher case |
| `0x005ab882` | call `0x00575470` | reads subtype byte at `packet+1`; source should be `packet[1]` |
| `0x005ab897` | call `0x00575480` | reads `uint16_t` text byte length at `packet+2` |
| `0x005ab8ae` / `0x005ab8b5` | calls `0x00516030` / `0x00516220` | memory-manager touch and copy from packet text bytes to stack buffer |
| `0x005ab8e6` | imported `MultiByteToWideChar` | ANSI/ACP bytes to UTF-16 |
| `0x005ab932`, `0x005ab94e` | calls `0x005ca676` | wide substring search for `L"> "` and `L"\" "` |
| `0x005ab97b` | call `0x005ddbec` | secure wide copy into sender scratch |
| `0x005ab992` | call `0x005ca50d` | reject sender if it contains space |
| `0x005ab9d4` | list vslot `+0x10` | get element by index |
| `0x005aba38`, `0x005aba74` | list vslot `+0x1c` | remove one history entry |
| `0x005aba4c` | list vslot `+0x18` | insert one history entry at index `1` |

## Documentation Evidence And Current Status

- Target page [UID:0003UR] currently has the correct range and ownership but only says "chat-message packet" and leaves subtype/text/helper names open. This report resolves those open questions.
- [UID:00007B] `LivingObjectPane` says `Chatting` and `SayInputPanes` consume some packet outcomes but should not be inferred as owners of `LivingObjectPane::HandleChatMessagePacket`. PE evidence confirms that warning.
- [UID:0000KU] `LivingObjectPane.cpp` lists `0x005ab860` among server packet handlers and explicitly keeps `Chatting`/`SayInputPanes` separate.
- [UID:0003VB] `UserPaneHandleServerMessage` lists `0x005ab860` as a delegated LivingObjectPane packet handler but does not currently name opcode `0x0a`; implementation should add the decoded route.
- [UID:0003VC] switch-table docs say the selector table exists and targets inside the dispatcher; implementation should add the decoded `0x0a` case if support-doc scope is accepted.
- [UID:0003AU] `ChattingStringResourceData` already identifies `0x00615284` as quote-space prefix and notes the `sub_5AB860` reference at aggregate level through [UID:00024X]. Target implementation should cross-link this use but does not need to change ownership.
- [UID:0001KO], [UID:0001MD], and [UID:0001ME] already document the `+0x13eb08/+0x13eb0c` history paths; this target refines the names by proving `+0x13eb0c` is populated by incoming subtype-zero chat/whisper sender messages and clears the selector byte.

## Ranked Ownership Analysis

### 1. LivingObjectPane / `map/LivingObjectPane.cpp` - Accepted

- Evidence for: direct adjusted receiver call from `UserPane::HandleServerMessage`; body mutates `this+0x13eb0c/+0x13eb10`; current LivingObjectPane class/file docs already own local-player server packet handlers; parent class/file pass the gate.
- Evidence against: function uses Chatting format literals and feeds SayInputPane history. These are dependencies, not owner routes.
- Decision: keep [UID:0003UR] owner/emitter [UID:00007B].

### 2. Chatting / `social/Chatting.cpp` - Rejected

- Evidence for: uses chat-format delimiter `L"\" "` and top-level opcode value overlaps the Chatting type-10 packet domain.
- Evidence against: no ChattingPane receiver, no message-list field mutation, no AddChattingMessage/AddIncomingMessage call, no Chatting router caller, and side effect is reply history, not display insertion.
- Decision: keep as support dependency only.

### 3. SayInputPanes / `social/SayInputPanes.cpp` - Rejected

- Evidence for: SayToUserNameInputPane reads the `+0x13eb0c` path and uses `+0x13eb10` to choose which list to preload/navigate.
- Evidence against: SayInputPanes only consumes the state; the server-message handler is called from the UserPane dispatcher and writes LivingObjectPane/UserPane aggregate fields.
- Decision: support docs should reference the field relationship, but owner stays LivingObjectPane.

### 4. UserPane / `ui/panels/UserPane.cpp` - Rejected As Direct Owner

- Evidence for: the only live caller is `UserPane::HandleServerMessage`; fields live in the large local-player/UserPane aggregate layout.
- Evidence against: the dispatcher explicitly adjusts the receiver to `ebx-0xa0`, matching LivingObjectPane subobject method dispatch used by sibling packet handlers; existing docs separate UserPane dispatcher ownership from delegated LivingObjectPane packet bodies.
- Decision: UserPane owns the dispatcher, not this callee.

## Negative Evidence Summary

- No direct route from `ChattingPaneChatPacketRouter` to `0x005ab860`.
- No call from target to `ChattingPane::AddChattingMessage` or `ChattingPane::AddIncomingMessage`.
- No evidence target owns `Chatting` strings; it only reads shared Chatting-owned read-only literals.
- No evidence target should absorb adjacent raw/prologue-shaped pre/post bodies.
- No evidence `0x00575470` should be renamed as a PacketBuffer byte reader in this context; PacketBuffer docs mark it as runtime/STL byte-load helper.
- No evidence return `false` means failure. Sibling chat packet handlers also return zero after accepted and ignored paths.

## First-Draft C++ Recommendation

Use role names and keep exact original spellings provisional:

```cpp
bool LivingObjectPane::HandleChatMessagePacket(const unsigned char *packet)
{
    if (packet[1] != 0)
        return false;

    const unsigned int textByteCount = PacketBufferReadUInt16BE(packet + 2);
    if (textByteCount >= 0x8000)
        __report_rangecheckfailure();

    char ansiText[0x8000];
    wchar_t wideText[0x8000];
    wchar_t senderScratch[128];

    GetMemoryMan();
    MemmoveWrapper(ansiText, packet + 4, textByteCount);
    ansiText[textByteCount] = '\0';

    const int wideCount = MultiByteToWideChar(
        0, 0,
        ansiText,
        static_cast<int>(textByteCount),
        wideText,
        0x8000);
    if (static_cast<unsigned int>(static_cast<unsigned short>(wideCount)) >= 0x8000)
        __report_rangecheckfailure();
    wideText[static_cast<unsigned short>(wideCount)] = L'\0';

    if ((wideText[0] == L'-' && wideText[1] == L'>' && wideText[2] == L' ') ||
        wcsstr(wideText, L"> ") != NULL) {
        return false;
    }

    wchar_t *quoteSpace = wcsstr(wideText, L"\" ");
    if (quoteSpace == NULL)
        return false;

    *quoteSpace = L'\0';
    wcsncpy_s(senderScratch, 128, wideText, 128);
    senderScratch[35] = L'\0';

    if (wcschr(senderScratch, L' ') != NULL)
        return false;

    List *senders = m_incomingWhisperSenderHistory;
    int foundIndex = -1;
    const int count = senders->GetCount();

    for (int i = 0; i < count; ++i) {
        const wchar_t *stored = static_cast<const wchar_t *>(senders->GetElementAt(i));
        if (wcscmp(stored, senderScratch) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        senders->RemoveRange(foundIndex, 1);
    } else if (count >= 10) {
        senders->RemoveRange(0, 1);
    }

    senders->InsertRange(1, senderScratch, 1);
    m_whisperHistorySource = WhisperHistorySource_IncomingSender;
    return false;
}
```

Implementation notes for the C++ block:

- If the accepted project API uses `ListInsertRange(index, value)` instead of `InsertRange(index, value, count)`, adjust the call spelling but keep the binary semantics.
- If the accepted field model uses raw pointers, name fields as `m_recentWhisperRecipients` (`+0x13eb08`), `m_incomingWhisperSenderHistory` (`+0x13eb0c`), and `m_whisperHistorySource` or `m_useOutgoingWhisperHistory` (`+0x13eb10`).
- Do not replace this with `std::vector<std::wstring>`; executable evidence is the project `List` container with fixed `0x40` byte elements and ten-entry history.
- Keep return `false` even after insertion, matching observed `al = 0` behavior.

## Open Question Closure

- Packet subtype/opcode: closed. Top-level opcode is `0x0a`; accepted subtype is byte `0` at `packet+1`.
- Full payload semantics: closed for modeled subtype `0`: `packet+2` uint16 big-endian byte length, `packet+4` ANSI/ACP text payload, converted to wide, parsed for sender.
- Text-buffer/string conversion names: closed to role level: `PacketBufferReadUInt16BE`, `MemmoveWrapper`/`MemoryMan::CopyBytes`, `MultiByteToWideChar(CP_ACP)`, `wcsstr`, `wcsncpy_s`, `wcschr`.
- Chatting dependency: closed. Chatting supplies/display-owns the `L"\" "` format delimiter and related message format strings; no ownership transfer.
- Field/helper names: closed to role level; original exact field spellings remain unproven but best names are provided above and are suitable for by-* docs.
- Caller/reachability: closed. Direct caller is `UserPane::HandleServerMessage` opcode `0x0a`; one rel32 call found.
- Owner/source placement: closed. Owner/emitter remain [UID:00007B] / `LivingObjectPane.cpp`.
- Split/range: closed. Keep exact target range; adjacent raw bodies are outside.
- C++ readiness: closed. First-draft C++ is recommended now.

## Proposed Score / Metadata

- `COMPLETION:88`: behavior, route, payload, fields, helper roles, dependencies, split/range, and C++ draft are resolved. Completion remains below final because exact original protocol enum/member spellings and final container typedef are inferred.
- `CONFIDENCE:91`: direct byte/disassembly, decoded switch table, literal decoding, direct caller scan, and support-doc agreement strongly validate the conclusions. Confidence remains below final audit because MCP was unavailable in this run and original names are not symbol-proven.
- `CANONICAL_OWNER:00007B`: unchanged.
- `RECONSTRUCTABLE:TRUE`: unchanged.
- `EMITTER_UIDS:00007B`: unchanged.
- `RECONSTRUCTION_CPP`: populate with first-draft C++ after supervisor acceptance.

## Exact Target / Support Implementation Checklist

For [UID:0003UR] `by-memory/0x005ab860-0x005aba7b.LivingObjectPaneHandleChatMessagePacket.md`:

- Replace shallow summary with detailed behavior: opcode `0x0a`, subtype `0`, length/text layout, ANSI-to-wide conversion, string filters, sender extraction, space rejection, list update, selector byte clear, false return.
- Resolve `sub_5AB860` as `LivingObjectPane::HandleChatMessagePacket`, with semantic alias `HandleIncomingWhisperSenderHistoryPacket`.
- Add caller route: `UserPane::HandleServerMessage` opcode `0x0a`, direct call at `0x005a7b3a`, receiver adjustment `ecx = ebx - 0xa0`.
- Add helper names: `0x00575470` byte load/runtime helper, `PacketBufferReadUInt16BE`, `GetMemoryMan`, `MemmoveWrapper`/copy, `MultiByteToWideChar`, `wcsstr`, `wcsncpy_s`, `wcschr`, `__report_rangecheckfailure`.
- Add literal meanings: `0x00614c54 = L"> "`, `0x00615284 = L"\" "`.
- Add field names/roles: `+0x13eb08` outgoing/recent whisper recipient list; `+0x13eb0c` incoming/fallback whisper sender list; `+0x13eb10` history-source selector byte.
- Add list behavior: shared `List`, element width `0x40`, capacity/page size ten, `count` at `+0x0c`, vslots `+0x10/+0x18/+0x1c`, duplicate removal, cap to ten, insert index `1`.
- Replace open questions with closed evidence-backed conclusions; only keep exact original symbol spellings as final polish uncertainty.
- Raise to `COMPLETION:88`, `CONFIDENCE:91`.
- Insert first-draft C++ using the draft above, adjusted to the accepted local `List`/helper naming style.

For [UID:0003VB] `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`:

- Add the decoded opcode `0x0a` route: selector table index `3`, jump target `0x005a7b33`, direct call `0x005a7b3a -> 0x005ab860`.
- Clarify that opcode `0x0a` delegates to the LivingObjectPane adjusted receiver and should not be modeled as a ChattingPane router call.
- No score change required unless the dispatcher source-quality section is broadly refreshed.

For [UID:0003VC] `by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md`:

- Add decoded selector entry for `0x0a -> index 3 -> 0x005a7b33`.
- If the table inventory is updated, keep opcode `0x36` inline user-list route as previously resolved and add `0x0a` as the `LivingObjectPane::HandleChatMessagePacket` route.
- No score change required.

For [UID:00007B] `by-class/LivingObjectPane.md` and [UID:0000KU] `by-file/LivingObjectPane.md`:

- Update the server packet handler bullet for `0x005ab860` to say it is opcode `0x0a` subtype `0` incoming whisper/sender-history handling.
- Add the field names/roles for `+0x13eb08/+0x13eb0c/+0x13eb10` if the local-player field section is touched.
- Preserve the boundary note that Chatting and SayInputPanes are dependencies/support, not owners.

For [UID:0000FQ] `by-class/UserPane.md`:

- If support docs are in scope, add that constructor-created `+0x13eb08` and `+0x13eb0c` are ten-entry fixed-width `List(0x40, 0x0a)` name-history lists, with `+0x13eb10` selecting the most recent history source.
- No ownership change.

For [UID:0001KO] `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`, [UID:0001MD] `SayToUserNameInputPane`, and [UID:0001ME] `SayToUserNameInputPaneHistoryNavigation`:

- Add cross-reference that [UID:0003UR] populates the `+0x13eb0c` incoming/fallback sender list and clears `+0x13eb10`, while `sub_5A4B60` populates `+0x13eb08` and sets the byte.
- No score change required.

For [UID:0003AU] `ChattingStringResourceData` / [UID:00024X] `ChattingReadOnlyData`:

- Optional one-line cross-reference: `0x00615284` `L"\" "` is used by [UID:0003UR] to split `sender" message` text and extract the sender. No ownership change.

For `by-memory/-coverage-report.md`:

- Do not edit directly as B001. Supervisor should insert the exact row below.

## Exact Supervisor-Owned Coverage Row

Current live `by-memory/-coverage-report.md` search found no existing [UID:0003UR] row. Insert this row under [UID:0001KM] in address order after [UID:0003VB] `0x005a76c0-0x005a82bd.UserPaneHandleServerMessage` and before [UID:0003US] `0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket`:

```markdown
        - [UID:0003UR][0x005ab860-0x005aba7b.LivingObjectPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.LivingObjectPaneHandleChatMessagePacket.md) 0x005ab860-0x005aba7b | method | LivingObjectPaneHandleChatMessagePacket : reconstructable : 88% : very-strong : B001 2026-06-19 source-quality reanalysis resolves UserPane dispatcher opcode 0x0a jump-table route, direct call at 0x005a7b3a with adjusted LivingObjectPane receiver, subtype byte packet+1 accepted only when zero, PacketBufferReadUInt16BE text length at packet+2, ANSI payload at packet+4 converted through MultiByteToWideChar, filters for outgoing `L"-> "` and any `L"> "` marker, requires the quote-space delimiter `L"\" "` from Chatting string data, extracts/truncates a space-free sender name, deduplicates and caps the incoming/fallback whisper sender history List at `this+0x13eb0c` to ten fixed 0x40-byte slots, inserts the sender at index 1, clears history-mode byte `this+0x13eb10` to select the inbound/fallback history path consumed by SayToUserNameInputPane helpers, keeps Chatting and SayInputPanes as dependencies/support rather than owners, and first-draft C++ is now safe with role-based names while exact original enum/field spellings remain inferred.
```

## Validator Results

- Command run:

> Executable block R001 was removed from this report and preserved verbatim in [0003UR-LivingObjectPaneHandleChatMessagePacket-source-quality-removed.md](0003UR-LivingObjectPaneHandleChatMessagePacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`.
- Scope: one file scanned.
- Apply: `False`.
- Key result: `ok: 1`, `ok 0003UR ... UID header exists`.
- Dry-run side effects only: validator reported generated/autogen noops and dry-run registry/report messages; no files were written because `--apply` was not passed.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003UR-LivingObjectPaneHandleChatMessagePacket-source-quality.md`.
- Modified: none outside this report.
- by-* docs edited: none.
- `by-memory/-coverage-report.md` edited: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UR","source_path":"executed-b-agent-research/B001/0003UR-LivingObjectPaneHandleChatMessagePacket-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
