*** UID:00001Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TextEditPane;
struct PaneKeyEvent;

class ChatInputPane : public MultiLineInputPane
{
public:
    ChatInputPane();
    virtual ~ChatInputPane();

protected:
    virtual bool HandleSpecialInput(PaneKeyEvent *event);
    virtual short SendChatMessage();

private:
    // The inherited LineInputPane edit child is observed at primary +0xfc.
    // The secondary key-handler view receives `this + 0xa0`, so it sees this
    // cursor at secondary +0x68.
    short m_chatHistoryCursor;        // +0x108, initialized to -1.
    unsigned char m_reserved10A[2];   // +0x10a..+0x10b alignment/tail bytes.

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChatInputPane

## Status

- Confidence: very strong for submit/history behavior, vtable identity, exact raw constructor bytes, singleton handling, packet route, and chat-source placement; medium-high for exact source-level private field/helper spellings.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md) or `social/ChatInputPane.cpp`
- Address range: [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_ChatInputPane.cpp`

## Class Purpose

`ChatInputPane` is the player chat input pane. It extends the line/multi-line input family with chat history navigation, text filtering, chat packet construction, network send, and history save.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| adjacent no-route raw packet island | [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) | Non-emitting source-shaped opcode `0x0e` subtype `0` packet body immediately before the raw constructor; no `this`, vtable, caller, pointer, or class-field route was found in the 2026-06-16 B001 IDA/raw PE audit. |
| `ChatInputPane` | [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) | Raw constructor-shaped body; installs `g_pChatInputPane`/`dword_69BF68`, initializes history cursor, and excludes the `0x005b3935-0x005b3940` padding tail. |
| prompt literal | [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md) | Class-owned UTF-16 `>` prompt passed through the raw constructor, alternate open helper, and inline UserPane open branch. |
| `HandleSpecialInput` | [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) `0x005b3940-0x005b3a40` | First-draft C++ ready secondary-vtable override; handles `0x81`/`0x83` chat-history keys, mutates `m_chatHistoryCursor` at primary `+0x108`, replaces inherited edit-child text, and falls back to `MultiLineInputPane::HandleKeyInput`. The binary returns handled/unhandled through `AL`; the current source-facing draft uses the project-wide `bool ...PaneKeyEvent` key-handler pattern. |
| `SendChatMessage` | [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) `0x005b3a40-0x005b3bba` | First-draft C++ ready primary-vtable submit method; returns a `short` status/length result, copies input text, checks `g_pCollectionData+0x134102`, applies password guard and text sanitizer, writes opcode `0x0e` subtype `0`, sends through `g_packetSender`, and saves chat history. |
| destructor thunks | `0x005b77de`, `0x005b7980` | Clear `g_pChatInputPane` and tear down the base chain. |

## Evidence Notes

- 2026-06-02 IDA MCP confirms `0x005b3940-0x005b3a40`, `0x005b3a40-0x005b3bba`, `0x005b77de-0x005b77e9`, `0x005b77e9-0x005b77f4`, and `0x005b7980-0x005b79c5`, but reports no function at `0x005b38e0`.
- 2026-06-02 IDA raw disassembly proves [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) as the constructor-shaped body with prompt `">"`, singleton store `dword_69BF68`, history cursor sentinel, and vtable stores.
- 2026-06-02 IDA vtable/data-ref evidence places submit at `0x0062fc30 -> 0x005b3a40`, key/history handling at `0x0062fc40 -> 0x005b3940`, destructor at `0x0062fbe8 -> 0x005b7980`, and constructor vtable stores to `0x0062fbe8`, `0x0062fc38`, and `0x0062fc68`.
- 2026-06-02 IDA decompile/callee evidence confirms password guard, sanitizer, `WideCharToMultiByte`, packet writers, send helper, and chat-history save in `SendChatMessage`.
- 2026-06-13 live IDA MCP refresh confirms the raw constructor's exact executable range is `0x005b38e0-0x005b3935` (`0x55` / 85 bytes, Verified with int_convert.py), followed by `0x005b3935-0x005b3940` alignment padding (`0x0b` / 11 bytes, Verified with int_convert.py).
- 2026-06-13 live IDA `xrefs_to` refresh confirms no direct refs to the raw start; prompt/global/vtable evidence ties it to the `0x005a95e0` allocation/open helper, the larger `0x005a5bd0` key/option path, `g_pChatInputPane`, and the three `ChatInputPane` vtable bases.
- 2026-06-16 B001 source-route audit for [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) keeps it as adjacent non-emitting no-route packet evidence rather than a direct `ChatInputPane` method: live IDA/raw PE found no inbound route or pointer hits to the raw helper, while the body remains a unique opcode `0x0e` subtype `0` packet primitive. Keep this page as a relationship/support reference, not canonical ownership for that helper.
- 2026-06-13 `decompile 0x005a95e0` shows the equivalent open path allocates `0x10c` / 268 bytes (Verified with int_convert.py), calls `sub_4F2C90(L">")`, writes `g_pChatInputPane`, installs the same three vtables, and sets the `this+0x108` / 264 history cursor sentinel (Verified with int_convert.py).
- 2026-06-13 B003 ownership review for [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md) rechecked all three `0x00630a14` xrefs. The apparent `UserPane` xref at `0x005a5d37` is an inline `ChatInputPane` allocation/open branch, while `0x005a962a` and raw `0x005b38e7` are the alternate open helper and raw constructor path; all three operate on the same `g_pChatInputPane`/vtable/history-sentinel pattern.
- 2026-06-19 B009 source-quality reanalysis raises the direct class confidence: [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) is exactly the two modeled virtual methods only, while [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) is a constructor sibling/child outside that target range. The secondary handler sees `m_chatHistoryCursor` at secondary `+0x68` / primary `+0x108` and the inherited edit child at secondary `+0x5c` / primary `+0xfc`.
- B009 confirms the source-facing method directions: `HandleSpecialInput` / `HandleHistoryKeyInput` for `0x005b3940` and `SendChatMessage` for `0x005b3a40`. The exact original virtual names remain inferred, but the roles are strong enough for first-draft C++ on the exact method page.
- B009 confirms the active submit packet route: `LineInputPane::TextLength`, `LineInputPane::CopyText`, [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md), [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md), [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md), [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md), [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The player/local-state byte at `g_pCollectionData+0x134102` is a proven send gate but its source field spelling remains inferred.
- B009 flags a second adjacent raw sender-shaped body at `0x005b3bc0-0x005b3ca5` with no rel32/control-flow/pointer route in local PE scans. Like [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md), it is semantic neighborhood evidence and should receive a later no-route support page; it must not be emitted through this class merely because it builds opcode `0x0e` subtype `0`.
- Generated source names such as `ChatTextFilter::Normalize`, `Packet_QueueAndSend`, and `UserPane::SaveChatHistory` remain useful lead names only; IDA evidence is the authority.
- This class should not be grouped with item command prompts despite address locality with other `0x005b*` input panes.
- 2026-06-19 B014 source-quality reanalysis rechecked the class-level route and keeps [UID:0000I5][Chatting](by-file/Chatting.md) as the source owner, with `social/ChatInputPane.cpp` only a future organizational split. It rejects `InputPanes.cpp`, `CommandInputPanes.cpp`, `SayInputPanes.cpp`, `UserPane.cpp`, `Socket.cpp`, and `PacketBuffer.cpp` as owners because those are base/caller/callee neighborhoods rather than the chat-input feature owner. B014 also closes the adjusted-this issue: secondary dispatch at primary `+0xa0` makes handler `this+0x68` equal the full-object `m_chatHistoryCursor` at `+0x108`, and handler `this+0x5c` equal the inherited edit child at primary `+0xfc`.
- B011's 2026-06-25 current MCP refresh records `g_pChatInputPane` storage as zero/null in active IDB session `80de0a67` (`get_global_value 0x0069bf68 -> 0x0`, adjacent bytes all zero) while preserving the eight open/create/constructor/destructor xrefs. The class C++ remains declaration-only/global-lifecycle aware and must not encode a permanent sentinel initializer.
- B014 keeps [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) non-emitting/no-owner after checking exact padding, absent callers, absent pointer routes, and the lack of `this`, UI validation, sanitizer, or history-save side effects. Its opcode `0x0e` subtype `0` body remains protocol comparison evidence only.

## Assignment Gate

This class is the direct parent for [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md), [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md), and [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md). The class now clears the strict `85/85` gate at `87/90`, and its source-file parent [UID:0000I5][Chatting](by-file/Chatting.md) already clears the gate at `85/88`.

## Reconstruction Notes

This class is reconstructable and attached to [UID:0000I5][Chatting](by-file/Chatting.md). Formal C++ is declaration-only: exact executable bodies remain on the by-memory children, while this page records the class shell, destructor, the two confirmed virtual method names, and the `m_chatHistoryCursor` field at primary `+0x108`. The inherited text-edit child at primary `+0xfc`, the player-state send gate at `g_pCollectionData+0x134102`, and shared packet/text helper spellings are source-facing role names rather than recovered original declarations. B014 keeps `HandleSpecialInput` in the project-wide `bool ...PaneKeyEvent` key-handler shape despite the raw `AL` return and upgrades `SendChatMessage` to a `short` status/length-returning submit method.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md)
- [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md)
- [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- What existed before: the page documented submit/history behavior and constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/78`.
- Summary and evidence: chat history and packet-send behavior are documented; constructor reachability, full base layout, and detailed packet/string field names remain incomplete.
- 2026-06-02 raw-constructor and parent update:
  - Before: the class was not reconstructable/attached and still treated the constructor as an unresolved projected start.
  - After: raised to `82/84`, marked reconstructable, attached to [UID:0000I5][Chatting](by-file/Chatting.md), and linked exact raw children [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) and [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md).
  - Evidence: current IDA function-boundary, raw constructor/helper, vtable/data-ref, decompile, and callee checks for the constructor/key/submit/destructor family.
- 2026-06-13 Goal 2 constructor exact-range refresh:
  - Before: class scoring was `82/84`, below the strict parent gate for the constructor child, and the constructor link used the old mixed `0x005b38e0-0x005b3940` range.
  - After: raised to `85/86`, kept parent [UID:0000I5][Chatting](by-file/Chatting.md), and updated the constructor child to exact body range [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md).
  - Evidence: live IDA MCP boundary, byte, instruction, xref, vtable-value, and factory-decompile refresh for the constructor/global/vtable family.
- 2026-06-13 B003 prompt-literal ownership review:
  - Before: [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md) was left parentless because one xref was documented as a `UserPane` consumer.
  - After: [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md) is attached to this class because all three xrefs are ChatInputPane construction/open paths, including the inline branch inside the larger UserPane handler.
- 2026-06-16 B001 raw sender ownership review:
  - Scores remain `85/86`; [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) stays a support relationship only.
  - Evidence: no `this`, vtable, global, direct caller, rel32, VA, or RVA pointer route ties the raw sender to this class, while the source-shaped packet primitive remains adjacent non-emitting evidence in the broader [UID:0000I5][Chatting](by-file/Chatting.md) source area.
- 2026-06-19 B009 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, formal C++ blank, and [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) still carried a stale blank-C++ rationale.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`; added declaration-only `ChatInputPane` class C++ and updated the method rows to mark `HandleSpecialInput` and `SendChatMessage` first-draft ready on the exact by-memory page.
  - Evidence: B009 local PE and document reanalysis confirmed vtable dispatch, constructor sibling boundaries, `m_chatHistoryCursor` and inherited edit-child offsets, packet opcode/subtype/length layout, sender and sanitizer dependencies, and non-emitting status for both adjacent raw opcode `0x0e` sender bodies.
- 2026-06-19 B014 Rule 26 source-quality incorporation:
  - Metadata remains `87/90`, owner/emitter [UID:0000I5][Chatting](by-file/Chatting.md). The class declaration now uses the established `PaneKeyEvent` key-event type and `short SendChatMessage()` status-returning submit signature.
  - Evidence: B014 rechecked exact constructor/method/no-route ranges, local PE pointer and rel32 negatives, prompt refs, singleton lifecycle, adjusted secondary/tertiary vtable dispatch, destructor thunks, source-placement alternatives, and protocol/helper naming. It keeps the raw packet island [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) as support-only evidence and records the `g_pChatInputPane` initializer ambiguity outside the class C++.
- 2026-06-25 B011 accepted implementation support sync:
  - Metadata and declaration-only formal class C++ remain unchanged at `87/90`, owner/emitter [UID:0000I5][Chatting](by-file/Chatting.md).
  - Evidence: MCP command ids `304`-`307` update the global lifecycle support pages to current zero/null storage and preserve the same eight refs, so the class page now records no-sentinel source guidance without changing constructor or method ownership.
