*** UID:00001Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChatInputPane

## Status

- Confidence: strong for submit/history behavior, vtable identity, raw constructor bytes, singleton handling, and chat-source placement; medium-high for exact source-level helper names.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md) or `social/ChatInputPane.cpp`
- Address range: [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_ChatInputPane.cpp`

## Class Purpose

`ChatInputPane` is the player chat input pane. It extends the line/multi-line input family with chat history navigation, text filtering, chat packet construction, network send, and history save.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw packet helper | [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md) | File-level helper adjacent to the constructor; sends opcode `0x0e`, subtype `0` from a wide string argument. |
| `ChatInputPane` | [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md) | Raw constructor-shaped body; installs `g_pChatInputPane`/`dword_69BF68` and initializes history cursor, but IDA does not recognize this start. |
| `HandleSpecialInput` | `0x005b3940-0x005b3a40` | Handles up/down chat history keys and replaces current text. |
| `SendChatMessage` | `0x005b3a40-0x005b3bba` | Builds opcode `0x0e` packet from normalized text, sends it, and saves chat history. |
| destructor thunks | `0x005b77de`, `0x005b7980` | Clear `g_pChatInputPane` and tear down the base chain. |

## Evidence Notes

- 2026-06-02 IDA MCP confirms `0x005b3940-0x005b3a40`, `0x005b3a40-0x005b3bba`, `0x005b77de-0x005b77e9`, `0x005b77e9-0x005b77f4`, and `0x005b7980-0x005b79c5`, but reports no function at `0x005b38e0`.
- 2026-06-02 IDA raw disassembly proves [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md) as the constructor-shaped body with prompt `">"`, singleton store `dword_69BF68`, history cursor sentinel, and vtable stores.
- 2026-06-02 IDA vtable/data-ref evidence places submit at `0x0062fc30 -> 0x005b3a40`, key/history handling at `0x0062fc40 -> 0x005b3940`, destructor at `0x0062fbe8 -> 0x005b7980`, and constructor vtable stores to `0x0062fbe8`, `0x0062fc38`, and `0x0062fc68`.
- 2026-06-02 IDA decompile/callee evidence confirms password guard, sanitizer, `WideCharToMultiByte`, packet writers, send helper, and chat-history save in `SendChatMessage`.
- Generated source names such as `ChatTextFilter::Normalize`, `Packet_QueueAndSend`, and `UserPane::SaveChatHistory` remain useful lead names only; IDA evidence is the authority.
- This class should not be grouped with item command prompts despite address locality with other `0x005b*` input panes.

## Reconstruction Notes

This class is reconstructable and attached to [UID:0000I5][Chatting](by-file/Chatting.md). Leave C++ blank until the base input layout, singleton/global name, player-state gate, and packet helper names are final-source quality.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md)
- [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- What existed before: the page documented submit/history behavior and constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/78`.
- Summary and evidence: chat history and packet-send behavior are documented; constructor reachability, full base layout, and detailed packet/string field names remain incomplete.
- 2026-06-02 raw-constructor and parent update:
  - Before: the class was not reconstructable/attached and still treated the constructor as an unresolved projected start.
  - After: raised to `82/84`, marked reconstructable, attached to [UID:0000I5][Chatting](by-file/Chatting.md), and linked exact raw children [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md) and [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md).
  - Evidence: current IDA function-boundary, raw constructor/helper, vtable/data-ref, decompile, and callee checks for the constructor/key/submit/destructor family.
