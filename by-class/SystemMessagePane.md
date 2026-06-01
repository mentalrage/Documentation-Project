*** UID:0000EA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SystemMessagePane

## Status

- Confidence: strong for class role and IDA boundaries; several virtual helper names remain provisional.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Current recovered file: `source-3/simroot_v2/class_SystemMessagePane.cpp`

## Class Purpose

`SystemMessagePane` is a scrollable system-message viewport. It maintains a message list, computes scroll extents in 12-pixel rows, supports high-resolution and normal EPF-backed layouts, handles the `?` help shortcut, and paints message rows/separators with clipping.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00584ea0-0x005851d9` | `SystemMessagePane::SystemMessagePane(...)` | Constructs the scrollable pane, initializes message slots/list, and stores `g_pChattingViewport`. |
| `0x005851e0-0x00585358` | `~SystemMessagePane()` | Destroys message entries, list storage, tile contexts, and base scrollable pane state. |
| `0x005856f0-0x005858c8` | Scroll metric helpers | Computes scroll offset, message count, last item index, item offset, content size, and scroll delta. |
| `0x005858d0-0x00585920` | `OnKeyEvent` | Handles the help shortcut and loads help content. |
| `0x00585b80-0x00586200` | `OnPaint` | Paints visible message entries, separators, and clipped text rows. |
| `0x00586370-0x0058643b` | `GetTotalContentHeight` | Sums rendered row height across message entries. |
| `0x0058ab33-0x0058ab49` | Adjustor/thunk helpers | Small vtable helpers currently omitted from emitted source. |
| `0x0058af00-0x0058af3b` | `ScalarDeletingDestructor` | Destructor wrapper with scalar-delete flag handling. |

## Evidence Notes

- Wave3 grades the class at effective `96.9`.
- IDA MCP confirms all listed starts as exact functions.
- Current generated source omits markers/bodies for `0x0058ab33` and `0x0058ab3e` even though Wave3 class inspection lists them.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `82`.
- Evidence: the page documents scrollable message-pane role, constructor/destructor/scroll/key/paint/content/destructor methods, IDA-confirmed starts, generated omissions, and sibling message-pane relationships; confidence remains capped by provisional helper names.
