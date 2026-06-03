*** UID:00001X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Autogen status: reconstructable class attached to [UID:0000I5][Chatting](by-file/Chatting.md). C++ remains blank because final field names, helper names, and source-level class declaration are below the final-source gate.

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
| `SetVisibleRowCount` | `0x0047fbd0-0x0047fc6b` | Updates visible row height, viewport rectangle, and scroll range after chat-height changes. |
| `GetLineCount` | `0x0047fc70` | Returns current message line count. |
| raw reset scroll range helper | `0x0047fd40-0x0047fd68` | IDA-unmodeled helper that reads current/max scroll values and calls the shared range setter. |
| `SetScrollPosition`, `SyncScrollbars`, `UpdateContentLayout` | `0x0055e7e0`, `0x0055e990`, `0x0055f250` | Later scroll helpers currently owned by `ChattingPane`. |

## Evidence Notes

- Existing IDA-backed memory pages confirm the local constructor, destructor, scroll metric virtuals, keyboard scroll handler, packet router, paint method, visible-row update, line-count helper, and raw reset-scroll-range helper inside the `0x0047efb0-0x0047fd68` display-pane band.
- Wave3 reports 16 methods and strong grade data for this class, but that generated data is lead material only; the score and ownership here rely on the linked IDA-backed docs.
- The constructor directly creates `ColorStringChattingMessage` instances and writes `g_pChattingDisplayPane`.
- [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md) is source-authored local chat-display support even though IDA does not model it as a function start; the existing page records exact raw bytes, the surrounding `0xcc` padding, empty callee list except the shared scroll helpers, and no direct incoming xrefs in the current pass.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `80` | The class page now records the main display-pane responsibility, likely file parent, key method inventory through the raw reset helper, singleton/message ownership, autogen handling, and source-layout caveats. Completion remains capped because final field names, some later generic scrollbar helper names, vtable layout details, and final class declaration are not fully audited here. |
| Confidence `86` | Confidence is strong because the linked exact memory pages and the file page are IDA-backed. It stays below final-audit range because some generated `FolderTreePane` ownership pollution and generic scroll helper names remain unresolved. |

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md)
- [UID:0002EX][0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount](by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md)
- [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md)
- [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)

## Changes

- What existed before: the page documented the chat display pane, scroll helpers, paint path, and related classes, but metadata remained `0/0`.
- What it was changed to: scores were set to `76/86`.
- Summary and evidence: constructor, scroll calculations, input, paint, message ownership, and later scroll helpers are covered; exact fields and final source-level layout remain incomplete.
- 2026-06-03: Raised completion from `76` to `80`, marked `RECONSTRUCTABLE:TRUE`, and attached parent [UID:0000I5][Chatting](by-file/Chatting.md).
  - Evidence: the class page now links exact IDA-backed visible-row, line-count, and raw reset-scroll helper pages; [UID:0000I5][Chatting](by-file/Chatting.md) already has a valid `NexusTK/social/` projection and confidence above the attachment gate. C++ remains blank below the final-source gate.
