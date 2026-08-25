** TARGET-REPORT-UID:0001MC **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Source-Quality Reanalysis: [UID:0001MC] ChatInputPane

Target: `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md`  
Report path: `tools/leaser/Agents/Agent-B009/research/0001MC-ChatInputPane-source-quality.md`  
Assignment date: 2026-06-19  
Mode: report-only for this target. No by-* pages or `by-memory/-coverage-report.md` were edited by this report pass.

## Executive Decision

[UID:0001MC] is a reconstructable `ChatInputPane` method cluster containing exactly two modeled virtual methods:

- `0x005b3940-0x005b3a40`: secondary-vtable key/history handler.
- `0x005b3a40-0x005b3bba`: primary-vtable submit/send method.

The best direct owner remains [UID:00001Q][ChatInputPane](../../../../by-class/ChatInputPane.md), with source-file routing through [UID:0000I5][Chatting](../../../../by-file/Chatting.md). A later `social/ChatInputPane.cpp` split remains plausible, but the current support docs already stage the chat UI/input family under `social/Chatting.cpp`; this target alone should not force a split.

Proposed metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00001Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001Q
```

First-draft C++ is eligible now. The remaining uncertainty is original spelling of private fields and helper APIs, not source shape, owner, packet route, or target range.

## Evidence Rechecked

Inputs read or checked:

- Target page [UID:0001MC] `0x005b3940-0x005b3bba.ChatInputPane.md`.
- Adjacent/support pages [UID:0002S8] `0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` and [UID:0002S9] `0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md`.
- Owner pages [UID:00001Q][ChatInputPane](../../../../by-class/ChatInputPane.md), [UID:0000I5][Chatting](../../../../by-file/Chatting.md), [UID:000308][g_pChatInputPane](../../../../by-global/g_pChatInputPane.md), and [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](../../../../by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md).
- Shared helper pages for `LineInputPane`, `MultiLineInputPane`, `PasswordGuard`, `TextFilter`, `PacketBuffer`, `g_packetSender`, and `g_pCollectionData`.
- Local PE `E:\NTK\Resources\NexusTK\NexusTK.exe` for current byte, pointer, vtable, and rel32 route checks.
- IDA MCP endpoint check: unavailable in this session (`Unable to connect to the remote server`), so fresh reanalysis used local PE scans plus the existing live-IDA-backed docs.

Scoped validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [0001MC-ChatInputPane-source-quality-removed.md](0001MC-ChatInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: dry run only, `ok: 1`, target UID header valid, no files written. The validator also reported project-level dry-run stats skip and a registry rebuild in memory; this was not an `--apply` run.

## Boundary And Child/Aggregate Recheck

The exact local PE boundary inventory is:

| Range | Disposition | Target relationship |
| --- | --- | --- |
| `0x005b37f0-0x005b38d5` | [UID:0002S8] no-route raw opcode `0x0e` subtype `0` packet sender-shaped body | Related support only; no caller/pointer route into target or owner emission. |
| `0x005b38d5-0x005b38e0` | `0xcc` padding | Ignored. |
| `0x005b38e0-0x005b3935` | [UID:0002S9] raw `ChatInputPane` constructor-shaped body | Related constructor sibling; not inside the target half-open range. |
| `0x005b3935-0x005b3940` | eleven `0xcc` bytes | Ignored padding before target. |
| `0x005b3940-0x005b3a40` | modeled function, history handler | Target body. |
| `0x005b3a40-0x005b3bba` | modeled function, submit/send handler | Target body. |
| `0x005b3bba-0x005b3bc0` | six `0xcc` bytes | Ignored padding after target. |
| `0x005b3bc0-0x005b3ca5` | second no-route raw opcode `0x0e` subtype `0` packet sender-shaped body, currently without an exact UID page | Outside target; should not be absorbed into [UID:0001MC]. |
| `0x005b3ca5-0x005b3cb0` | eleven `0xcc` bytes | Ignored padding before [UID:0001MD]. |
| `0x005b3cb0+` | [UID:0001MD] `SayToUserNameInputPane` | Separate SayInputPanes family target. |

Current target prose treats the raw constructor as a covered range even though the target filename/title starts at `0x005b3940`. That should be corrected during implementation: [UID:0002S9] can remain a direct `ChatInputPane` constructor child/sibling, but it is not contained by [UID:0001MC]'s address range. The target should list it under related constructor/support, not under covered target ranges.

The current coverage row for [UID:0002S9] also uses row range `0x005b38e0-0x005b3940` while the exact page/body is `0x005b38e0-0x005b3935` and `0x005b3935-0x005b3940` is separately ignored padding. That is a support-row cleanup item for the supervisor; it is not a reason to expand [UID:0001MC].

The local PE scan also exposes an uncovered source-shaped body at `0x005b3bc0-0x005b3ca5`. It is the same narrow wide-string-to-default-chat packet pattern as [UID:0002S8], with no rel32/control-flow hits and no absolute dword pointer hits to `0x005b3bc0`. Treat it as adjacent no-route support evidence requiring a later UID/split decision, not as target content.

## Caller, Vtable, And Reachability

Direct call route to the target method starts:

- `0x005b3940`: no direct rel32 call/jump hits in local PE.
- `0x005b3a40`: no direct rel32 call/jump hits in local PE.

Data/vtable route:

- `0x0062fc40 -> 0x005b3940`: secondary `ChatInputPane` vtable slot for the key/history handler.
- `0x0062fc30 -> 0x005b3a40`: primary `ChatInputPane` vtable slot for submit/send.
- `0x0062fbe8 -> 0x005b7980`: primary scalar deleting destructor slot.
- `0x0062fc38 -> 0x005b77de`: secondary destructor adjustor thunk slot.
- Local PE absolute pointer hits found exactly those vtable cells for the two target methods and destructor slots; no RVA pointer hits.

Vtable construction/publish route:

- Raw constructor [UID:0002S9] stores primary/secondary/tertiary vtable bases `0x0062fbe8`, `0x0062fc38`, and `0x0062fc68` at `0x005b3916`, `0x005b391c`, and `0x005b3926`.
- Equivalent open/allocation paths in existing docs at `0x005a5bd0` and `0x005a95e0` store the same vtable bases.
- [UID:000309] `g_pChatInputPane` at `0x0069bf68` has exactly eight local PE VA hits: `0x005a5d10`, `0x005a5d54`, `0x005a5d5c`, `0x005a9606`, `0x005a9647`, `0x005a964f`, raw constructor write `0x005b390a`, and destructor clear `0x005b7988`.

Raw no-route bodies:

- [UID:0002S8] `0x005b37f0-0x005b38d5`: no rel32 call/jump hits and no VA/RVA pointer hits to the raw start.
- Post-target body `0x005b3bc0-0x005b3ca5`: no rel32/control-flow hits into the body and no absolute dword pointer hits to `0x005b3bc0` or `0x005b3ca5`.

This supports a vtable-dispatched `ChatInputPane` implementation plus retained adjacent raw packet bodies with no proven source route.

## Raw Constructor Relationship

[UID:0002S9] is a real raw `ChatInputPane` constructor-shaped body:

- It calls `MultiLineInputPane::MultiLineInputPane` at `0x004f2c90` with prompt literal `L">"` at `0x00630a14`.
- It publishes `g_pChatInputPane` through `0x0069bf68`.
- It initializes primary-object `+0x108` to `0xffff`, the chat history cursor sentinel.
- It installs the three `ChatInputPane` vtable views at primary `+0x0`, secondary `+0xa0`, and tertiary `+0xa4`.
- It ends with `ret` at `0x005b3934`; `0x005b3935-0x005b3940` is padding.

Because [UID:0002S9] is outside `0x005b3940-0x005b3bba`, [UID:0001MC] should not claim it as covered. The relationship should be documented as:

- [UID:0002S9] = exact constructor child/sibling of [UID:00001Q].
- [UID:0001MC] = exact modeled-method cluster for the same class.
- Both route to [UID:00001Q] and then [UID:0000I5] for source placement.

## History Handler Behavior: `0x005b3940-0x005b3a40`

The method is reached through the secondary vtable at `0x0062fc40`, so its `ecx` is the secondary view (`primary this + 0xa0`). Important adjusted offsets:

- Secondary `this+0x68` maps to primary `this+0x108`, the `m_chatHistoryCursor` field initialized by the raw constructor.
- Secondary `this+0x5c` maps to primary `this+0xfc`, the inherited `LineInputPane` text-edit child.

Instruction-level behavior:

- Saves a stack cookie and receives one event pointer argument at `[ebp+8]`.
- Calls `0x004a8b10` through `dword_67A754` / locale/ctype-like narrowing support using event bytes at `event+0x08` and `event+0x10a`.
- Handles only events where:
  - `event+0x10a == 0`,
  - `event+0x04 == 8`,
  - narrowed byte is `0x81` or `0x83`.
- For `0x81`, calls `0x005a4930(g_pCollectionData, &m_chatHistoryCursor, buffer, 0x100)`.
- For `0x83`, calls `0x005a4990(g_pCollectionData, &m_chatHistoryCursor, buffer, 0x100)`.
- If the returned wide buffer is nonempty:
  - calls `0x0058f2a0(editChild, 0, 0x7fff)` to select/clear/select a broad text range,
  - computes the returned wide string length inline,
  - calls `0x0058fc30(editChild, buffer, length, 0, 0)` to insert replacement text,
  - calls `0x0058f2a0(editChild, 0, 0x7fff)` again.
- Returns `true` (`al = 1`) for handled history navigation.
- Falls back to `MultiLineInputPane::HandleKeyInput` at `0x004f2cd0` for all other events and returns that result.

Best source-facing name: `ChatInputPane::HandleSpecialInput` or `ChatInputPane::HandleHistoryKeyInput`. The existing target uses `HandleSpecialInput`; keep that unless a later vtable-name pass standardizes input callback names.

## Submit/Send Behavior: `0x005b3a40-0x005b3bba`

Instruction-level behavior:

- Calls `LineInputPane::TextLength` at `0x004f2310`. If the length is not positive, returns without side effects.
- Reads [UID:0000QK] `g_pCollectionData` / historical `dword_67A748`.
- Checks byte `g_pCollectionData + 0x134102` (decimal `1261826`, verified with `tools/int_convert.py` as `0x134102`). Nonzero blocks send.
- Copies up to `0xff` wide characters from the inherited line input through `LineInputPane::CopyText` at `0x004f2300`.
- If copied wide text is empty, returns.
- Calls [UID:0002VH] `ValidateChatInputOrThrowPasswordError` at `0x00465890`.
- Measures the wide string length inline and calls [UID:0000TK] `SanitizeWideTextForChat` at `0x005957c0`, passing `g_pTextFilter` from `0x0067adc8` as the decompiled receiver/context and the measured text length.
- Initializes packet scratch/context through `0x00516030`.
- Writes opcode `0x0e` at packet byte `0` through `PacketBufferWriteUInt8` (`0x00575380`).
- Writes zero at packet byte `1` through `PacketBufferWriteUInt16BE` (`0x005753a0`) with value `0`; because the helper writes a spare zero after the two-byte value, the later length write overwrites the scratch byte. Protocol meaning remains subtype `0`.
- Converts the sanitized UTF-16 text to multibyte via `WideCharToMultiByte`.
- Rejects converted length `>= 0x100` through `___report_rangecheckfailure`.
- Writes the one-byte converted payload length at packet byte `2` through `PacketBufferWriteUInt8` (`0x00575380`).
- Copies converted payload bytes to packet byte `3+` through `0x00516220`.
- Adds `3` to the converted length and rejects final packet length `>= 0x12c`.
- Sends through [UID:0000Q5] `g_packetSender` / `dword_67A7EC` using [UID:0001HU] `QueueAndSendPacket` at `0x00574bb0`.
- Calls `0x005a49e0(g_pCollectionData, wideText)` to save the line in chat history after the send.

Best source-facing name: `ChatInputPane::SendChatMessage`. `OnSubmitChat` is also defensible from the vtable role, but `SendChatMessage` matches current docs and the method's visible side effect.

## Opcode `0x0e` Packet Route

The active `ChatInputPane` send route is the vtable method at `0x005b3a40`, not [UID:0002S8] and not the post-target raw body at `0x005b3bc0`.

Packet format from the active method:

| Byte(s) | Source action | Meaning |
| --- | --- | --- |
| `0` | `PacketBufferWriteUInt8(packet + 0, 0x0e)` | chat opcode |
| `1` | zero written via `PacketBufferWriteUInt16BE(packet + 1, 0)` | default/talk subtype `0` |
| `2` | `PacketBufferWriteUInt8(packet + 2, convertedLength)` | one-byte multibyte payload length |
| `3..` | copy from converted local buffer | chat text payload |

Send length is `convertedLength + 3`. The local terminator/scratch zero is not transmitted because `QueueAndSendPacket` receives the explicit length.

`ShoutInputPane` uses the same opcode family but subtype `1`; `SayInputPane` uses the same opcode/subtype `0` packet family with its own source owner. That sibling comparison confirms the subtype role and rejects a Socket/PacketBuffer owner reroute for feature packet construction.

## Relation To [UID:0002S8] And Post-Target Raw Sender

[UID:0002S8] `0x005b37f0-0x005b38d5` and the local PE body at `0x005b3bc0-0x005b3ca5` both look like source-authored narrow helpers that accept a wide string argument and serialize opcode `0x0e`, subtype `0`, one-byte length, and multibyte payload through `QueueAndSendPacket`.

They are not the active `ChatInputPane` submit method:

- They have no `this`-based text read, no history cursor, no password guard, no sanitizer, no player-state gate, and no history save.
- Local PE scans found no direct rel32/control-flow hits and no absolute VA/RVA pointer hits to their raw starts.
- [UID:0002S8] has already been classified as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, non-emitting no-route evidence.
- The post-target body at `0x005b3bc0-0x005b3ca5` should receive the same no-route treatment unless a future caller/pointer/runtime route appears.

Do not emit either raw sender through `ChatInputPane` or `Chatting` merely because it is adjacent and semantically similar.

## Source-Facing Names, Types, Globals, And Fields

Best-supported names:

| Binary entity | Best source-facing name | Confidence and caveat |
| --- | --- | --- |
| `0x005b3940` | `ChatInputPane::HandleSpecialInput` / `HandleHistoryKeyInput` | Strong behavior; exact original callback spelling inferred. |
| `0x005b3a40` | `ChatInputPane::SendChatMessage` | Strong behavior; exact original virtual slot name inferred. |
| primary `this+0x108` | `m_chatHistoryCursor` | Strong field role; raw constructor initializes to `-1`, history handler passes it to previous/next helpers. |
| primary `this+0xfc` | inherited `m_textEditPane` / `m_inputEditPane` | Strong inherited role from `LineInputPane`; exact field spelling unresolved. |
| `0x0069bf68` | `g_pChatInputPane` | Strong; exact global page and xrefs exist. |
| `0x0067a7ec` | `g_packetSender` | Strong global role; best current source type `Socket *`. |
| `0x0067a748` | `g_pCollectionData` / local-player `UserPane` state pointer | Strong address and broad state role; name is a typed view, not final canonical class name. |
| `g_pCollectionData+0x134102` | chat/input send gate byte, possible `m_chatInputBlocked` / `m_localPlayerActionState` | Strong offset and gating role; source spelling unknown. Use a descriptive placeholder, not a final field. |
| `0x005a4930` | `GetPreviousChatHistoryEntry` | Strong use from Say/Chat history handlers; exact helper name inferred. |
| `0x005a4990` | `GetNextChatHistoryEntry` | Strong use from Say/Chat history handlers; exact helper name inferred. |
| `0x005a49e0` | `SaveChatHistoryEntry` / `AddChatHistoryEntry` | Strong use after successful send; exact helper name inferred. |
| `0x004f2300` | `LineInputPane::CopyText` | Existing exact child page. |
| `0x004f2310` | `LineInputPane::TextLength` | Existing exact child page. |
| `0x004f2cd0` | `MultiLineInputPane::HandleKeyInput` | Existing exact child page. |
| `0x00465890` | `ValidateChatInputOrThrowPasswordError` | Existing exact child page. |
| `0x005957c0` | `SanitizeWideTextForChat` | Existing global helper page. |
| `0x00575380` | `PacketBufferWriteUInt8` | Existing PacketBuffer child page; source name descriptive/inferred. |
| `0x005753a0` | `PacketBufferWriteUInt16BE` | Existing PacketBuffer child page; source name descriptive/inferred. |
| `0x00574bb0` | `QueueAndSendPacket` | Existing Socket-owned child page. |

Rejected generated or stale names:

- Do not use `g_pCashShopRequest` for `0x0067a7ec`; current docs normalize it to `g_packetSender`.
- Do not use a generated `SpellManager`/`g_pSpellMan`-style owner for `0x0067a748`; current docs treat it as broad local-player/UserPane state.
- Do not name the history handler as a base `LineInputPane` method; it is a `ChatInputPane` secondary-vtable override that delegates to `MultiLineInputPane` only on fallback.

## Heuristic / Inference Reanalysis And Validation

Heuristic issue: [UID:0001MC] sits in a dense command-input address band, with raw no-route packet bodies before and after the modeled methods, plus shared base input helpers and shared packet serialization helpers. The risk is over-owning adjacent source-shaped bodies or under-owning the active virtual submit method because packet bytes look generic.

Validation results:

1. Vtable evidence overrides address adjacency. `0x0062fc40 -> 0x005b3940` and `0x0062fc30 -> 0x005b3a40` are exact `ChatInputPane` vtable slots. The raw constructor and two open paths install the same table family and publish `g_pChatInputPane`.
2. The raw constructor is semantically `ChatInputPane`, but it is outside the target address range. It should be a related constructor child/sibling, not target-covered code.
3. [UID:0002S8] and `0x005b3bc0-0x005b3ca5` are source-shaped but route-less. Similar packet bytes alone are not enough to attach them to `ChatInputPane` output.
4. The submit method has feature-local UI behavior that the raw helpers lack: input length check, player/local state gate, `LineInputPane::CopyText`, password guard, sanitizer, `g_packetSender` send, and history save.
5. Shared infrastructure remains with shared owners. `LineInputPane`, `MultiLineInputPane`, `PacketBuffer`, `Socket`, `PasswordGuard`, and `TextFilter` helpers are dependencies, not owner reroutes.
6. `social/Chatting.cpp` versus `social/ChatInputPane.cpp` is a source-file organization question, not an owner blocker. Current docs already route [UID:00001Q] through [UID:0000I5]; a split can wait until the constructor, prompt, singleton, target methods, and raw no-route body policy are coordinated.

Inference confidence:

- Owner/emitter: high.
- Method boundaries: very high.
- Packet layout and route: very high.
- Field roles: high for `m_chatHistoryCursor`, medium-high for player-state gate byte name.
- Exact original source spellings: medium, hence confidence stays below final-audit range.

## Rejected Alternatives

Rejected: make [UID:0002S8] an emitted `ChatInputPane` helper.  
Reason: no caller, no pointer route, no `this`, no UI validation, no history save, no password/sanitizer path. Existing B001 audit already correctly sets owner/emitter to none.

Rejected: absorb the raw constructor into [UID:0001MC].  
Reason: constructor body is `0x005b38e0-0x005b3935`; [UID:0001MC] starts at `0x005b3940`. The constructor should remain a related exact child/sibling under [UID:00001Q].

Rejected: expand [UID:0001MC] through `0x005b3ca5` or `0x005b3cb0`.  
Reason: `0x005b3bba-0x005b3bc0` is padding, `0x005b3bc0-0x005b3ca5` is no-route raw packet sender-shaped code, and `0x005b3ca5-0x005b3cb0` is padding before a different class family.

Rejected: treat `0x005b3bc0-0x005b3ca5` as padding.  
Reason: local PE disassembly shows a complete stack-cookie protected wide-string-to-opcode-`0x0e` packet sender body. It is source-shaped no-route code, not alignment.

Rejected: move target to `InputPanes.cpp` or `CommandInputPanes.cpp`.  
Reason: inherited input helpers are dependencies only; class-specific vtables, singleton, prompt, history, and packet behavior are chat-owned.

Rejected: move target to `SayInputPanes.cpp`.  
Reason: `SayInputPane` and `ShoutInputPane` are sibling opcode-family implementations. [UID:0001MC] uses `g_pChatInputPane`, `ChatInputPane` vtables, and `Chatting` source-route docs.

Rejected: move target to `Socket.cpp`, `PacketBuffer.cpp`, or `ProtocolSend.cpp`.  
Reason: those modules own serialization/send helpers. The feature method constructs a chat input packet and has UI/history side effects.

## First-Draft C++ Eligibility

Eligible. The target clears the numeric and route gates, has a nonblank emitter route through [UID:00001Q], and the two methods are modeled functions with exact boundaries and stable dependencies. The code below is first-draft source-quality C++; it intentionally uses descriptive helper/field names where original spellings are inferred.

```cpp
bool ChatInputPane::HandleSpecialInput(InputKeyEvent *event)
{
    const unsigned char key = NarrowInputEventByte(event);

    if (event->imeActive == 0 &&
        event->eventKind == 8 &&
        (key == 0x81 || key == 0x83)) {
        wchar_t historyText[256] = {};

        if (key == 0x81) {
            GetPreviousChatHistoryEntry(g_pCollectionData, &m_chatHistoryCursor,
                                        historyText, 256);
        } else {
            GetNextChatHistoryEntry(g_pCollectionData, &m_chatHistoryCursor,
                                    historyText, 256);
        }

        if (historyText[0] != L'\0') {
            m_textEditPane->SelectText(0, 0x7fff);
            m_textEditPane->InsertText(historyText, wcslen(historyText), 0, 0);
            m_textEditPane->SelectText(0, 0x7fff);
        }

        return true;
    }

    return MultiLineInputPane::HandleKeyInput(event);
}

void ChatInputPane::SendChatMessage()
{
    if (LineInputPane::TextLength() <= 0) {
        return;
    }

    if (g_pCollectionData->chatInputSendBlocked != 0) {
        return;
    }

    wchar_t wideText[256] = {};
    LineInputPane::CopyText(wideText, 255);
    if (wideText[0] == L'\0') {
        return;
    }

    ValidateChatInputOrThrowPasswordError(wideText);
    SanitizeWideTextForChat(wideText, wcslen(wideText));

    unsigned char packet[300] = {};
    char multibyteText[256] = {};
    void *packetCopyContext = GetMemoryMan();

    PacketBufferWriteUInt8(packet + 0, 0x0e);
    PacketBufferWriteUInt16BE(packet + 1, 0);

    const int convertedLength = WideCharToMultiByte(
        0, 0, wideText, static_cast<int>(wcslen(wideText)),
        multibyteText, sizeof(multibyteText), 0, 0);
    if (convertedLength >= 0x100) {
        ReportRangeCheckFailure();
    }

    multibyteText[convertedLength] = '\0';
    PacketBufferWriteUInt8(packet + 2, convertedLength);
    CopyPacketBytes(packetCopyContext, packet + 3, multibyteText, convertedLength);

    const int packetLength = convertedLength + 3;
    if (packetLength >= 0x12c) {
        ReportRangeCheckFailure();
    }

    packet[packetLength] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    SaveChatHistoryEntry(g_pCollectionData, wideText);
}
```

Implementation notes for the C++:

- `InputKeyEvent`, `NarrowInputEventByte`, `m_textEditPane`, `chatInputSendBlocked`, `GetMemoryMan`, `CopyPacketBytes`, and history helper names are role names. Keep them searchable as inferred names, not recovered original spellings.
- If the project standard prefers exact helper-call parity, retain `PacketBufferWriteUInt16BE(packet + 1, 0)` for the subtype-zero write because the binary calls `0x005753a0`. If final source style abstracts this as a one-byte subtype write, document that the compiler/helper expansion still matches the observed bytes.
- `g_pCollectionData->chatInputSendBlocked` is the `+0x134102` byte. The role is proven; the source field name is not.

## Open-Question Closure

Raw constructor relationship: closed. Keep [UID:0002S9] as exact constructor sibling/child under [UID:00001Q], not inside [UID:0001MC].

History handler source role: closed. It is a `ChatInputPane` secondary-vtable override for chat history navigation, with fallback to `MultiLineInputPane::HandleKeyInput`.

Submit/send source role: closed. It is the active `ChatInputPane` vtable submit method and sends opcode `0x0e`, subtype `0`.

Opcode `0x0e` route: closed for active target. The route is `ChatInputPane::SendChatMessage -> PacketBuffer writers -> QueueAndSendPacket(g_packetSender, packet, length)`.

[UID:0002S8] relation: closed. It remains non-emitting no-route raw support evidence and is not called by the target.

Post-target raw helper: newly flagged. `0x005b3bc0-0x005b3ca5` should be split or documented as a no-route raw body when a UID/supervisor lease is available. It must not be folded into [UID:0001MC].

Chatting versus split `ChatInputPane.cpp`: closed for this implementation stage. Keep current [UID:0000I5] `Chatting` route; record `social/ChatInputPane.cpp` as a future coordinated split only.

First-draft C++: eligible. The target should no longer use the stale "blank under 95+ gate" rationale.

## Proposed Target/Support Implementation Checklist

Target [UID:0001MC]:

- Update scores to `88/90`.
- Keep `CANONICAL_OWNER:00001Q`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00001Q`.
- Add status note: source-authored `ChatInputPane` history and submit virtual methods; first-draft C++ ready; private field/helper spellings inferred.
- Replace stale blank-C++ rationale with the first-draft C++ above, or a supervisor-approved equivalent using the same packet/history semantics.
- In covered ranges, list only `0x005b3940-0x005b3a40`, `0x005b3a40-0x005b3bba`, and internal/tail padding if target format keeps padding rows. Move [UID:0002S9] to related constructor/support.
- Add explicit "not covered" note for [UID:0002S8] and post-target `0x005b3bc0-0x005b3ca5`.

[UID:00001Q] `ChatInputPane`:

- Add field-layout note for `m_chatHistoryCursor` at primary `+0x108`.
- Add inherited edit child note for primary `+0xfc` and secondary handler adjusted offsets `+0x68` and `+0x5c`.
- Update method rows to mark `HandleSpecialInput` and `SendChatMessage` first-draft C++ ready.
- Keep [UID:0002S8] as support relationship only and mention the post-target no-route raw body if a support page is created.

[UID:0000I5] `Chatting`:

- Keep `ChatInputPane` under current `social/Chatting.cpp` route.
- Record `social/ChatInputPane.cpp` as a possible later split only; no immediate reroute.
- Clarify that adjacent raw no-route sender bodies are semantic neighborhood evidence, not emitted Chatting helpers.

[UID:0002S9] raw constructor:

- No metadata change required.
- If touched, clarify it is a constructor sibling/child of [UID:00001Q] and not a covered range inside [UID:0001MC].

[UID:0002S8] raw sender:

- No metadata change required.
- If touched, add a note that [UID:0001MC] reanalysis again rejects it as an active `ChatInputPane` method/callee.

Post-target raw body `0x005b3bc0-0x005b3ca5`:

- Request/split a new exact support page when a UID is available, likely `ChatPacketRawSenderNoRouteRaw`-style naming with a "post-ChatInputPane duplicate/no-route" qualifier.
- Keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter unless a caller/pointer/runtime route appears.

Ignored/padding docs:

- Preserve `0x005b3bba-0x005b3bc0` padding.
- Add/confirm `0x005b3ca5-0x005b3cb0` padding after the post-target raw body if that support split is performed.

Coverage:

- Do not edit `by-memory/-coverage-report.md` in a B-agent implementation pass. Use the row below for supervisor application.

## Exact Supervisor-Owned Coverage Row

```text
    - [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) 0x005b3940-0x005b3bba | class-method cluster | ChatInputPane : reconstructable : 88% : very strong : B009 2026-06-19 source-quality reanalysis keeps direct owner/emitter [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) with current source route [UID:0000I5][Chatting](by-file/Chatting.md); local PE bytes confirm two modeled vtable methods, secondary-view history navigation at `0x005b3940-0x005b3a40` using `m_chatHistoryCursor` primary `+0x108`, fallback to `MultiLineInputPane::HandleKeyInput`, and primary submit/send at `0x005b3a40-0x005b3bba` with `LineInputPane` text reads, `g_pCollectionData+0x134102` send gate, password guard, `SanitizeWideTextForChat`, opcode `0x0e` subtype `0`, one-byte length-prefixed MBCS payload, `QueueAndSendPacket(g_packetSender, packet, length+3)`, and chat-history save; raw constructor [UID:0002S9] remains a related exact sibling outside the target range, [UID:0002S8] and the post-target `0x005b3bc0-0x005b3ca5` raw sender-shaped body remain no-route/non-emitting support evidence, and first-draft `HandleSpecialInput`/`SendChatMessage` C++ is now eligible with inferred field/helper spellings.
```

## Files Not Edited

This report pass created only:

```text
tools/leaser/Agents/Agent-B009/research/0001MC-ChatInputPane-source-quality.md
```

No by-* docs and no `by-memory/-coverage-report.md` were edited for [UID:0001MC].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001MC-ChatInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0001MC"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MC-ChatInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0001MC-ChatInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
