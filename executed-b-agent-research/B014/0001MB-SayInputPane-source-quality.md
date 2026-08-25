** TARGET-REPORT-UID:0001MB **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B014 Source-Quality Report: 0001MB SayInputPane

Assignment: `B014-goal2-SayInputPane-source-quality-0001MB-20260619`  
Target: [UID:0001MB] `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`  
Report-only status: no by-* documentation edits and no `by-memory/-coverage-report.md` edit were made in this pass.

## Executive Decision

Keep [UID:0001MB] as a reconstructable `SayInputPane` class-method cluster owned by [UID:0000C3][SayInputPane] and emitted through [UID:0000N9][SayInputPanes] / `NexusTK/social/SayInputPanes.cpp`.

The target should not receive formal `RECONSTRUCTION_CPP` in its current aggregate/cluster form. It meets the current numeric route gate (`RECONSTRUCTABLE:TRUE`, nonblank emitter, `(85 + 87) / 2 = 86`), but the source-quality decision is to split exact method children before adding final C++:

- `0x005b34d0-0x005b356c` as the constructor overload `SayInputPane::SayInputPane(const wchar_t *initialText)`.
- `0x005b3570-0x005b3670` as the history key handler.
- `0x005b3670-0x005b37ea` as the submit/send handler.

The raw default constructor [UID:0002S7] is already split at `0x005b3490-0x005b34d0`. The successor no-route raw packet island [UID:0002S8] remains excluded from SayInputPane ownership and emission.

Recommended metadata for the target stays:

```text
COMPLETION:85
CONFIDENCE:87
CANONICAL_OWNER:0000C3
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000C3
```

The coverage row should be refreshed because the current row still says `78%` and refers to the old `95+` C++ gate.

## Exact Aggregate And Child Boundaries

The current target page is a cluster over three modeled functions plus one internal padding span. It also documents adjacent support ranges outside its half-open target range.

Target-owned half-open range:

| Range | Status | Source-quality decision |
| --- | --- | --- |
| `0x005b34d0-0x005b356c` | IDA modeled function `sub_5B34D0`, size `0x9c` | Source-authored constructor overload. Should be exact child before final C++. |
| `0x005b356c-0x005b3570` | four `0xcc` bytes | Internal alignment padding. If children are split, this belongs to ignored/padding coverage, not C++. |
| `0x005b3570-0x005b3670` | IDA modeled function `sub_5B3570`, size `0x100` | Source-authored key/history handler. Should be exact child before final C++. |
| `0x005b3670-0x005b37ea` | IDA modeled function `sub_5B3670`, size `0x17a` | Source-authored submit handler. Should be exact child before final C++. |

Adjacent support/boundary ranges:

| Range | Status | Decision |
| --- | --- | --- |
| `0x005b3490-0x005b34d0` | [UID:0002S7] raw default constructor. IDA has no function at `0x005b3490`; raw bytes end with one `0xcc` at `0x005b34cf`. | Sibling/child of `SayInputPane`, not part of target-owned range. Keep as exact raw constructor page. |
| `0x005b34cf-0x005b34d0` | one-byte padding before `sub_5B34D0` | Already covered by [UID:0002S7] range/page body as terminal alignment, but conceptually padding. Do not include in target C++. |
| `0x005b37ea-0x005b37f0` | six `0xcc` bytes before [UID:0002S8] | Successor padding. It is documented in the target page as boundary evidence, but coverage should keep it as ignored/padding rather than target-owned code. |
| `0x005b37f0-0x005b38d5` | [UID:0002S8] `ChatPacketRawSenderNoRouteRaw` | Non-emitting no-route raw packet island; do not merge into SayInputPane or ChatInputPane. |

This target is therefore not a single source body. It is reconstructable as evidence, but source emission should move to exact method children.

## Raw Constructor Relationship

[UID:0002S7] `0x005b3490-0x005b34d0.SayInputPaneRawConstructor` is the raw default constructor-shaped sibling:

- IDA does not model a function at `0x005b3490`.
- No direct xrefs to `0x005b3490` were found in the existing IDA refreshes.
- Raw instructions call `LineInputPane` base construction at `0x004f1c00` with prompt literal `"> "` at `0x00614c54`.
- It stores `-1` to `this+0x108`.
- It installs the three SayInputPane vtable views:
  - primary `0x0062fb5c` at `this+0x00`
  - secondary `0x0062fbac` at `this+0xa0`
  - tertiary `0x0062fbdc` at `this+0xa4`
- It returns at `0x005b34ce`; `0x005b34cf` is `0xcc` alignment before the modeled overload at `0x005b34d0`.

Best source interpretation: this is `SayInputPane::SayInputPane()` compiled as a raw/unmodeled constructor body. It is not a fall-through into the modeled overload, and the modeled overload does not call it. The two bodies duplicate the base-prompt/vtable/history initialization, with the overload adding initial-text insertion.

## Constructor Overload

Modeled body: `0x005b34d0-0x005b356c`, IDA `sub_5B34D0`.

Best source-facing name:

```cpp
SayInputPane::SayInputPane(const wchar_t *initialText)
```

Confirmed behavior:

- Calls `LineInputPane` base constructor `0x004f1c00` with prompt `"> "` / `0x00614c54`.
- Installs the same primary/secondary/tertiary vtables as the raw default constructor.
- Initializes the derived chat-history cursor/sentinel at `this+0x108` to `-1`.
- Inserts the supplied wide string into the embedded edit-control child via `0x0058fc30`.

Field/name decisions:

- `this+0xf8`: inherited `LineInputPane` prompt label child, established by LineInputPane docs.
- `this+0xfc`: inherited `LineInputPane` edit child. Source-facing field should be something like `m_editPane` or `m_textEdit`, but exact original spelling is not proven.
- `this+0x108`: derived SayInputPane chat history cursor. Best current source-facing field: `m_chatHistoryCursor` or `m_historyCursor`. Use `m_chatHistoryCursor` in future source drafts because it distinguishes this field from recipient-history cursors in `SayToUserNameInputPane`.
- Prompt string: source literal `L"> "` for SayInputPane, distinct from ChatInputPane's `L">"` prompt child and ShoutInputPane's `L"! "`.

Rejected constructor interpretations:

- Not a copy constructor: it calls the base prompt constructor and inserts a wide string; there is no object copy pattern.
- Not a factory helper: it writes SayInputPane vtables directly and returns `this`.
- Not a wrapper around the raw default constructor: no direct call/fall-through edge connects `0x005b34d0` with `0x005b3490`.

## History Key Handler

Modeled body: `0x005b3570-0x005b3670`, IDA `sub_5B3570`.

Best source-facing name:

```cpp
bool SayInputPane::HandleKeyInput(const KeyEvent *event)
```

The exact event type is still a project-specific input-event structure, so `KeyEvent` is a placeholder. The function is vtable-reached through `0x0062fbb4 -> 0x005b3570`, with no direct code callers.

Confirmed behavior:

- Normalizes the event key through `std::ctype<char>::do_narrow`.
- Handles two chat-history navigation key values after narrowing.
- Calls `0x005a4930` and `0x005a4990` to retrieve previous/next chat history into a local wide buffer.
- If the returned line is nonempty, clears/selects/replaces the edit child text through `0x0058f2a0` and `0x0058fc30`.
- If not handled, delegates to `LineInputPane::HandleKeyInput` at `0x004f25a0`.

Best-supported helper names:

| Address | Best current role/name | Owner/source decision |
| --- | --- | --- |
| `0x005a4930` | `GetPreviousChatHistoryLine` / previous chat-history fetch | Chat/history helper under review for `SayInputPanes` or `Chatting`; not `UserPane` just because nearby ranges touch local-player state. |
| `0x005a4990` | `GetNextChatHistoryLine` / next chat-history fetch | Same as above. |
| `0x0058f2a0` | TextEditPane clear/select helper used before and after insertion | `TextEditPane` dependency through inherited edit child, not SayInputPane-owned code. Exact public name unresolved. |
| `0x0058fc30` | TextEditPane wide-text insert/append helper | `TextEditPane` dependency through inherited edit child, not SayInputPane-owned code. Exact public name unresolved. |
| `0x004f25a0` | `LineInputPane::HandleKeyInput` | Inherited base fallback in `InputPanes`. |

The `0x005a4930-0x005a5791` neighborhood has mixed chat-history, say-mode, IconsPane, and client-state helpers. Existing `UserPane` docs explicitly warn to keep chat/say-input helpers such as most of this span with `SayInputPanes` or `Chatting` unless later evidence proves original `UserPane` grouping. For this target, those helpers are dependencies; they do not move SayInputPane under `UserPane`.

## Submit-Chat Packet Body

Modeled body: `0x005b3670-0x005b37ea`, IDA `sub_5B3670`.

Best source-facing name:

```cpp
void SayInputPane::OnSubmitChat()
```

Alternative acceptable descriptive name: `SubmitSayChat`. The vtable slot evidence `0x0062fba4 -> 0x005b3670` supports virtual submit/action handling.

Confirmed packet behavior:

- Reads the current pending wide text length via `LineInputPane::TextLength` / `0x004f2310`.
- Copies up to `255` wide characters through `LineInputPane::CopyText` / `0x004f2300`.
- Calls `ValidateChatInputOrThrowPasswordError` at `0x00465890`.
- Calls `SanitizeWideTextForChat` at `0x005957c0`.
- Converts the sanitized wide text through `WideCharToMultiByte`.
- Builds a length-prefixed chat packet:
  - opcode byte `0x0e`
  - subtype byte `0`
  - one-byte payload length
  - converted multibyte payload
- Sends `length + 3` bytes through `QueueAndSendPacket(g_packetSender, packet, length + 3)`, where IDA names are `sub_574BB0(dword_67A7EC, ...)`.
- Saves the submitted wide line through `0x005a49e0`.
- Contains compiler security-cookie setup/check and range-check failure support; those are not source-authored SayInputPane logic.

Protocol naming:

- Best protocol name for opcode `0x0e`, subtype `0`: `SayChatMessage`.
- For helper names, use:
  - `kChatMessageOpcode = 0x0e`
  - `kSayChatSubtype = 0`
  - `kShoutChatSubtype = 1` for the sibling ShoutInputPane body.
- Do not name this packet generically as "ChatInputPane packet" because ChatInputPane and SayInputPane both send opcode `0x0e` subtype `0` from different UI/source owners.

Range/length guard:

- The copied wide text cap is `255` code units.
- Converted payload length is serialized as one byte.
- Final send length is payload length plus 3 header bytes.

Best-supported helper names:

| Address/global | Best source-facing name | Owner/source decision |
| --- | --- | --- |
| `0x004f2310` | `LineInputPane::GetTextLength` / `TextLength` | `InputPanes`, inherited base helper. |
| `0x004f2300` | `LineInputPane::CopyText` | `InputPanes`, inherited base helper. |
| `0x00465890` | `ValidateChatInputOrThrowPasswordError` | `PasswordGuard`, source-authored shared guard. |
| `0x005957c0` | `SanitizeWideTextForChat` | `TextFilter`, shared sanitizer. |
| `0x00575380` | `PacketBufferWriteUInt8` | `PacketBuffer` scalar writer helper. Historical IDA name `sub_575380`. |
| `0x005753a0` | `PacketBufferWriteUInt16BE` | Not used by SayInputPane target, but relevant for sibling ChatInputPane docs. |
| `0x00574bb0` | `Socket::QueueAndSendPacket` / `QueueAndSendPacket` | Socket-owned queue/send funnel. Historical IDA name `sub_574BB0`. |
| `0x0067a7ec` | `g_packetSender` | Socket-owned `Socket *` global. Historical IDA name `dword_67A7EC`. |
| `0x005a49e0` | `SaveChatHistoryLine` / submitted chat-history save | Chat/history helper under review for `SayInputPanes` or `Chatting`. |

The PacketBuffer helper `0x00575380` writes a payload byte and a spare zero byte; the spare zero is local/scratch and not a separate protocol field. The explicit send length controls what reaches the socket queue.

## Adjacent No-Route Raw Packet Island

[UID:0002S8] `0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw` is immediately after six bytes of padding at `0x005b37ea-0x005b37f0`.

Relationship to this target:

- It is semantically similar to the SayInputPane submit body because it builds opcode `0x0e`, subtype `0`, length-prefixed payload and sends through `g_packetSender` / `QueueAndSendPacket`.
- It is not called by SayInputPane. The active SayInputPane submit body ends at `0x005b37ea`; six `0xcc` bytes separate it from the raw island.
- Existing B001/0002S8 evidence reports no IDA function at `0x005b37f0`, no inbound xrefs, no rel32 call/jump hits to the body/interior, no VA/RVA pointer hits, and no class `this` evidence.
- ChatInputPane's active submit method is at `0x005b3a40`, also with full UI/state/history behavior and no route into `0x005b37f0`.
- ShoutInputPane is excluded because it sends subtype `1`.

Decision: keep [UID:0002S8] as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++. It is source-shaped retained bytes, not a source-emitting helper for SayInputPane.

## Owner And Source Placement

Keep target owner/emitter route:

```text
0001MB -> 0000C3 SayInputPane -> 0000N9 SayInputPanes -> NexusTK/social/SayInputPanes.cpp
```

Reasons:

- Vtable identities are SayInputPane-specific: constructor writes `0x0062fb5c`, `0x0062fbac`, `0x0062fbdc`; key slot points from `0x0062fbb4`; submit slot points from `0x0062fba4`.
- Raw constructor, overload, key handler, submit handler, and scalar deleting destructor are all documented under `SayInputPane`.
- `SayInputPanes` file page owns the social input family and specifically lists SayInputPane raw constructor, modeled cluster, and destructor.
- ShoutInputPane, direct-message panes, and current-mode opener evidence support a shared `social/SayInputPanes.cpp` source family.

Rejected owner/source alternatives:

| Alternative | Rejection |
| --- | --- |
| `Chatting.cpp` / `ChatInputPane` | ChatInputPane is physically adjacent and uses opcode `0x0e` subtype `0`, but it has its own raw constructor, singleton `g_pChatInputPane`, multiline base, vtable slots, and source route through [UID:0000I5][Chatting]. SayInputPane has separate vtables and constructor/destructor evidence. |
| Central packet helper / `ProtocolSend` | The packet bytes are built inside a UI submit handler with text reads, password guard, sanitizer, and history save. Calling PacketBuffer and Socket helpers does not transfer ownership. |
| `Socket` | `Socket` owns `g_packetSender` and `QueueAndSendPacket`, not feature packet builders. |
| `PacketBuffer` | `PacketBufferWriteUInt8` is a shared scalar writer, not the owner of chat packet submit logic. |
| `PasswordGuard` | `0x00465890` is a shared validation dependency only. |
| `TextFilter` | `0x005957c0` is a shared sanitizer dependency only. |
| `LineInputPane` / `InputPanes` | Base construction, text access, and fallback key handling are inherited dependencies. SayInputPane-owned vtables and derived history cursor prove the direct owner. |
| `UserPane` | Existing UserPane docs explicitly caution against folding `0x005a4930-0x005a5791` chat/history/say helpers into UserPane without final caller proof. This target's class-specific vtables and methods are not UserPane code. |
| [UID:0002S8] no-route raw island | No call/pointer route. Similar bytes are insufficient for ownership. |

## Fields, Types, Globals, And Placeholders

Recommended source-facing names for a future child-level C++ draft:

| Binary evidence | Best current name | Confidence | Notes |
| --- | --- | --- | --- |
| `this+0xf8` inherited from `LineInputPane` | `m_promptLabel` | medium-high | LineInputPane docs confirm prompt label child slot. Exact spelling unresolved. |
| `this+0xfc` inherited from `LineInputPane` | `m_editPane` / `m_textEdit` | medium-high | LineInputPane docs confirm editable child slot; target inserts/replaces text through this child. |
| `this+0x108 = -1` | `m_chatHistoryCursor` | high | Derived SayInputPane field initialized by both constructors and passed to history fetch helpers. |
| `0x00614c54` | `L"> "` | high | SayInputPane prompt literal, shared by raw and overload constructors. |
| `0x0062fb5c` | SayInputPane primary vtable | high | Constructor store and destructor/submit/key slot neighborhood. |
| `0x0062fbac` | SayInputPane secondary view vtable | high | Constructor store. |
| `0x0062fbdc` | SayInputPane tertiary view vtable | high | Constructor store. |
| `0x0062fbb4` | key-handler vtable cell | high | Points to `0x005b3570`. |
| `0x0062fba4` | submit/action vtable cell | high | Points to `0x005b3670`. |
| `dword_67A7EC` / `0x0067a7ec` | `g_packetSender` | high | Best type `Socket *`; owner `Socket`. |
| `dword_67A748 + 1261826` | player/session chat gate | medium | Present in ChatInputPane/ShoutInputPane submit docs. The SayInputPane submit page does not currently foreground this gate; do not invent a final name here without decompilation-specific confirmation. |

Generated/compiler names to preserve as search aliases, not final source names:

- `sub_5B34D0`: constructor overload.
- `sub_5B3570`: key/history handler.
- `sub_5B3670`: submit handler.
- `sub_5B7B80`: scalar deleting destructor target.
- `sub_4F1C00`: `LineInputPane` constructor.
- `sub_4F25A0`: `LineInputPane::HandleKeyInput`.
- `sub_4F2300`: `LineInputPane::CopyText`.
- `sub_4F2310`: `LineInputPane::TextLength`.
- `sub_575380`: `PacketBufferWriteUInt8`.
- `sub_574BB0`: `QueueAndSendPacket`.
- `dword_67A7EC`: `g_packetSender`.
- `std::ctype<char>::do_narrow`: runtime/library key normalization, not a project helper.
- `WideCharToMultiByte`: Win32 conversion API.
- security-cookie check and range-check failure calls: compiler/runtime support, not SayInputPane source logic.

## Heuristic / Inference Reanalysis And Validation

Heuristic classification checks:

1. Vtable ownership beats physical adjacency.
   - SayInputPane vtable stores and slots identify the owner of `0x005b34d0`, `0x005b3570`, and `0x005b3670`.
   - Physical adjacency to ChatInputPane and the no-route raw packet island is not enough to transfer ownership.

2. Dependencies do not become source owners.
   - PacketBuffer, Socket, PasswordGuard, TextFilter, LineInputPane, and TextEditPane helpers are all real callees.
   - Their shared-helper role is independently documented and should stay separate.

3. Similar packet layout does not prove common helper ownership.
   - SayInputPane, ChatInputPane, and [UID:0002S8] all build opcode `0x0e` subtype `0` payloads.
   - Active UI submit methods have class state, vtables, text reads, validation, sanitizer, history save, and explicit send calls.
   - [UID:0002S8] lacks route evidence and class state.

4. Raw constructor status is a modeling issue, not a source-owner blocker.
   - [UID:0002S7] is source-shaped and class-specific despite no IDA function object.
   - The target overload at `0x005b34d0` remains a normal modeled function.

5. Current C++ gate is necessary but not sufficient for this cluster.
   - The target clears the active minimum route gate.
   - However, the cluster combines multiple source methods plus padding. A single `RECONSTRUCTION_CPP` block would be awkward source placement and would hide exact child ownership.
   - Child splits are the safer source-quality action before implementation.

Rejected inference alternatives:

- "The no-route raw packet island is an out-of-line SayInputPane helper": rejected by no xrefs/pointers/branches and by active in-method submit body.
- "The target should move to Chatting because ChatInputPane sends the same opcode": rejected by vtable/class/source route evidence.
- "The chat-history helpers make this UserPane code": rejected by existing UserPane boundary docs and direct SayInputPane vtables.
- "The constructor overload is just a wrapper or thunk": rejected by full constructor behavior and vtable writes.
- "PacketBuffer spare zero byte is a protocol terminator": rejected by PacketBuffer docs and explicit send length.
- "Security-cookie/range-check code belongs in source C++": rejected as compiler/runtime support.

Validation status from this report pass:

- Scoped validator command:

> Executable block R001 was removed from this report and preserved verbatim in [0001MB-SayInputPane-source-quality-removed.md](0001MB-SayInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `ok: 1`.
- Important validator line: `ok 0001MB by-memory/0x005b34d0-0x005b37ea.SayInputPane.md UID header exists`.
- Validator was dry-run only; no files were written.

Git status note:

- `git -C E:\NTK\GhidraBridge status ...` failed because `E:\NTK\GhidraBridge` is not a git repository root in this environment. I therefore verified by direct write scope: the only intended write in this pass is this report file.

## First-Draft C++ Eligibility Or No-Code Proof

No formal C++ should be added to [UID:0001MB] in its current form.

Exact proof:

1. The target is a class-method cluster, not one source function.
   - It contains three modeled functions and one internal padding span.
   - The current target range is `0x005b34d0-0x005b37ea`; it also documents successor padding `0x005b37ea-0x005b37f0` as boundary evidence.

2. The raw default constructor is already split.
   - [UID:0002S7] owns `0x005b3490-0x005b34d0`.
   - Adding constructor overload/key/submit C++ to the parent cluster would create inconsistent granularity.

3. Exact child split is straightforward and should precede C++.
   - Child pages can each carry a precise signature, helper-name caveats, and scoped C++.
   - Padding can move to ignored coverage rows cleanly.

4. Final helper and event names are still source-quality blockers.
   - `0x005a4930`, `0x005a4990`, and `0x005a49e0` roles are clear, but final original names/source split are not.
   - `0x0058f2a0` and `0x0058fc30` are TextEditPane operations, but public names are not final.
   - The key event type and exact virtual method declaration are still inferred.

5. The active gate does not require unsafe aggregate emission.
   - The page's route and score allow implementation consideration, but source code must be final project source.
   - Current best action is child split plus first-draft code on exact children, not one aggregate block.

Recommended child-level C++ readiness:

| Future child | Eligibility after split | Remaining caveats |
| --- | --- | --- |
| Constructor overload `0x005b34d0-0x005b356c` | Eligible for first-draft C++ | Field names for edit child/history cursor remain descriptive. |
| Key handler `0x005b3570-0x005b3670` | Eligible for first-draft C++ | Key-event struct and history helper names remain descriptive. |
| Submit handler `0x005b3670-0x005b37ea` | Eligible for first-draft C++ | Packet helper names can use current PacketBuffer/Socket names; chat-history save helper remains descriptive. |

Do not include [UID:0002S8] code in any child draft.

## Open-Question Closure

| Question | Closure |
| --- | --- |
| Does target start at `0x005b34d0` or include raw constructor bytes? | Starts at `0x005b34d0`; raw constructor is [UID:0002S7] sibling support. |
| Is `0x005b34cf-0x005b34d0` source code? | No, one-byte `0xcc` alignment after raw constructor. |
| Does target own `0x005b37ea-0x005b37f0`? | No source code; successor alignment before [UID:0002S8]. Keep as ignored/padding in coverage. |
| Is [UID:0002S8] a SayInputPane helper? | No. It is a no-route raw island with no proven call/pointer route. |
| Should owner be `SayInputPanes` or `Chatting`? | `SayInputPanes` through SayInputPane. ChatInputPane remains in `Chatting`; sibling behavior is only cross-reference evidence. |
| What is `this+0x108`? | Derived chat-history cursor/sentinel; best name `m_chatHistoryCursor`. |
| What is the prompt? | `L"> "`, with a space; distinct from ChatInputPane prompt docs. |
| What are `0x005a4930` and `0x005a4990`? | Previous/next chat-history fetch helpers; final symbol/source split unresolved. |
| What is `0x005a49e0`? | Save submitted chat-history line helper; final symbol/source split unresolved. |
| What should opcode `0x0e`, subtype `0` be called? | `SayChatMessage` or "say chat packet"; use constants `kChatMessageOpcode` and `kSayChatSubtype` in future drafts. |
| Are `sub_575380`/`sub_574BB0` final names? | No. Prefer `PacketBufferWriteUInt8` and `QueueAndSendPacket` / `Socket::QueueAndSendPacket`, while retaining IDA aliases for traceability. |
| Is C++ currently safe on this target page? | No. Split exact method children first. |

## Proposed Coverage Row

Exact current supervisor-owned row text:

```text
    - [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) 0x005b34d0-0x005b37ea | class-method cluster | SayInputPane : reconstructable : 78% : strong : Default say input constructor overload, history key handler, submit handler, vtable refs, packet opcode `0x0e` subtype `0`, and alignment padding documented; C++ blank under the 95+ gate.
```

Proposed exact replacement row text:

```text
    - [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) 0x005b34d0-0x005b37ea | class-method cluster | SayInputPane : reconstructable : 85% : strong : B014 source-quality reanalysis preserves SayInputPane/SayInputPanes ownership, confirms exact constructor-overload/key-handler/submit-handler boundaries, raw constructor sibling relationship, vtable-only reachability, prompt/history cursor fields, opcode `0x0e` subtype `0` say-chat packet construction, PacketBuffer/g_packetSender helper names, adjacent [UID:0002S8] no-route raw island exclusion, and cluster no-code/child-split proof under the active C++ gate.
```

Coverage side notes for supervisor:

- Keep [UID:0002S8] row unchanged except if separately requested; current no-route classification is support evidence for this target.
- Consider a later cleanup for the target page's "Covered Ranges" wording because it lists `0x005b37ea-0x005b37f0` boundary padding even though the target filename/range ends at `0x005b37ea`.
- If exact child pages are created, split internal padding `0x005b356c-0x005b3570` into ignored/padding coverage and keep successor padding `0x005b37ea-0x005b37f0` separate.

## Target Implementation Checklist

If accepted for implementation callback:

- Do not edit this target's C++ block directly as an aggregate.
- Create or update exact child pages for:
  - `0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText`
  - `0x005b3570-0x005b3670.SayInputPaneHandleKeyInput`
  - `0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat`
- Keep [UID:0002S7] as the raw default constructor child.
- Keep [UID:0002S8] as non-emitting no-route raw island with `CANONICAL_OWNER:NONE`.
- Move/record `0x005b356c-0x005b3570` as padding if method children are split.
- Preserve target metadata unless child split changes target disposition to a non-emitting index.
- Add child-level first-draft C++ only where exact child ranges and helper caveats are carried in the child page.
- Use descriptive but traceable names:
  - `m_chatHistoryCursor`
  - `LineInputPane::CopyText`
  - `LineInputPane::GetTextLength`
  - `SanitizeWideTextForChat`
  - `ValidateChatInputOrThrowPasswordError`
  - `PacketBufferWriteUInt8`
  - `QueueAndSendPacket`
  - `g_packetSender`
- Keep IDA aliases in evidence notes: `sub_5B34D0`, `sub_5B3570`, `sub_5B3670`, `sub_575380`, `sub_574BB0`, `dword_67A7EC`.
- Run scoped validator after doc changes and include result in implementation report.

## Support-Doc Checklist

Recommended support docs to update only during an accepted implementation callback:

| Doc | Action |
| --- | --- |
| `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md` | Update C++ gate wording from old `95+` language to active child-split decision; clarify successor padding ownership if allowed. |
| `by-class/SayInputPane.md` | Add B014 source-quality note: target remains owner/emitter, but exact children should be split before C++. |
| `by-file/SayInputPanes.md` | Add B014 note preserving SayInputPane ownership and [UID:0002S8] exclusion. |
| `by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md` | Optional support note that raw constructor is sibling/default overload and should not be merged into target cluster C++. |
| `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` | No required change; optionally cross-reference this report's exclusion if supervisor wants support sync. |
| `by-memory/-coverage-report.md` | Supervisor-only replacement of the target row with the exact row above. B014 did not edit it. |
| Exact new child pages | Create if implementation callback authorizes method split. |
| `auto-generated/NexusTK/social/SayInputPanes.cpp` | Regenerate only via validator/autogen flow after by-* changes; do not hand edit. |

## Report-Only File Touches

Created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0001MB-SayInputPane-source-quality.md
```

Not edited:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b34d0-0x005b37ea.SayInputPane.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001MB-SayInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001MB"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MB-SayInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001MB-SayInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
