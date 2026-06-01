*** UID:00001Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChatInputPane

## Status

- Confidence: strong for submit/history behavior; medium for constructor boundary.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md) or `social/ChatInputPane.cpp`
- Address range: [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_ChatInputPane.cpp`

## Class Purpose

`ChatInputPane` is the player chat input pane. It extends the line/multi-line input family with chat history navigation, text filtering, chat packet construction, network send, and history save.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChatInputPane` | `0x005b38e0` | Wave3 projected constructor; installs `g_pChatInputPane` and unset chat mode, but IDA does not recognize this start. |
| `HandleSpecialInput` | `0x005b3940-0x005b3a3f` | Handles up/down chat history keys and replaces current text. |
| `SendChatMessage` | `0x005b3a40-0x005b3bb9` | Builds opcode `0x0e` packet from normalized text and sends it through `g_pNetworkSession`. |
| destructor thunks | `0x005b77de`, `0x005b7980` | Clear `g_pChatInputPane` and tear down the base chain. |

## Evidence Notes

- IDA MCP confirms `0x005b3940` and `0x005b3a40`, but reports no function at `0x005b38e0`.
- Generated source calls `ChatTextFilter::Normalize`, `ChatTextFilter::TrackRecent`, `Packet_QueueAndSend`, and `UserPane::SaveChatHistory`.
- This class should not be grouped with item command prompts despite address locality with other `0x005b*` input panes.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- What existed before: the page documented submit/history behavior and constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/78`.
- Summary and evidence: chat history and packet-send behavior are documented; constructor reachability, full base layout, and detailed packet/string field names remain incomplete.
