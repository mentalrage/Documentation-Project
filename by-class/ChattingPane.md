*** UID:00001X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingPane.cpp`

## Class Purpose

`ChattingPane` is the scrollable chat display pane. It owns the chat message list, line-count and line-height calculations, high-res versus low-res layout differences, scroll input handling, and paint dispatch for `ColorStringChattingMessage` entries.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingPane` | `0x0047efb0` | Constructs a `ScrollablePane`, seeds blank messages, sets `g_pChattingDisplayPane`, and initializes scroll state. |
| `GetScrollMaxLines` | `0x0047f520` | Computes max vertical scroll based on visible lines. |
| `GetScrollPageSize` | `0x0047f5c0` | Computes page-size scroll amount. |
| `GetLineHeight` | `0x0047f600` | Returns layout step count or default low-res value. |
| `GetContentSize` and scroll helpers | `0x0047f650-0x0047f6e4` | Converts line count to content and scroll offsets. |
| `HandleInputEvent` | `0x0047f6f0` | Handles keyboard scrolling. |
| `OnPaint` | `0x0047f8d0` | Clips and draws visible chat messages. |
| `GetLineCount` | `0x0047fc70` | Returns current message line count. |
| `SetScrollPosition`, `SyncScrollbars`, `UpdateContentLayout` | `0x0055e7e0`, `0x0055e990`, `0x0055f250` | Later scroll helpers currently owned by `ChattingPane`. |

## Evidence Notes

- IDA MCP confirms the main `0x0047efb0-0x0047fd3a` method starts.
- Wave3 reports 16 methods and strong grade data for this class.
- The constructor directly creates `ColorStringChattingMessage` instances and writes `g_pChattingDisplayPane`.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)

## Changes

- What existed before: the page documented the chat display pane, scroll helpers, paint path, and related classes, but metadata remained `0/0`.
- What it was changed to: scores were set to `76/86`.
- Summary and evidence: constructor, scroll calculations, input, paint, message ownership, and later scroll helpers are covered; exact fields and final source-level layout remain incomplete.
