*** UID:00001U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingColorSelectPane

## Status

- Confidence: strong for local behavior and exact range split; medium for final file split.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md) or split `social/ChatColorDialog.cpp`
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingColorSelectPane.cpp`

## Class Purpose

`ChattingColorSelectPane` is the category selector inside the chat color dialog. It displays six chat color categories, draws the category labels with owner-provided color bytes, and notifies the color owner when the selected category changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002G2][0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor](by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md) | `0x00482ca0-0x00482d3c` | Constructs a `ListPane`, stores the owner pointer, and adds entries `0..5`. |
| [UID:0002G3][0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw](by-memory/0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw.md) | `0x00482d40-0x00482d4a` | Calls selector vtable slot `+0x20` with `this+0x44`. |
| [UID:0002G4][0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw](by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md) | `0x00482d50-0x00482d5a` | Forwards two zero arguments to selector vtable slot `+0x78`; final source name remains open. |
| [UID:0002G5][0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem](by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md) | `0x00482d60-0x00482f4f` | Draws category labels and foreground/background colors. |
| [UID:0002G6][0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged](by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md) | `0x00482f50-0x00482fa5` | Refreshes color list/update targets after category selection. |
| `ScalarDeletingDestructor` | `0x0047e9d0` | Existing destructor/thunk range away from the local constructor block. |

## Evidence Notes

- IDA MCP confirms exact modeled bodies at `0x00482ca0-0x00482d3c`, `0x00482d60-0x00482f4f`, and `0x00482f50-0x00482fa5`; it also confirms raw helper bodies at `0x00482d40-0x00482d4a` and `0x00482d50-0x00482d5a`.
- IDA vtable data points `0x00615164` to `DrawItem` and `0x0061515c` to `OnSelectionChanged`.
- IDA string review resolves the labels as `Talk`, `Shout`, `Whisper`, `Group`, `Clan`, and `System`.
- The standalone constructor currently has no direct xrefs, but the owner dialog constructor inlines the same construction sequence.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md)
- [UID:0002G2][0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor](by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md)
- [UID:0002G3][0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw](by-memory/0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw.md)
- [UID:0002G4][0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw](by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md)
- [UID:0002G5][0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem](by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md)
- [UID:0002G6][0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged](by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)

## Changes

- What existed before: the page documented local selector behavior and labels, but metadata still read `0/0`.
- What it was changed to: scores were set to `70/80`.
- Summary and evidence: category construction, drawing, selection, and destructor ownership are covered; final file split and exact member naming remain open.
- What existed before: the page only listed broad method anchors at `0x00482ca0`, `0x00482d60`, and `0x00482f50`.
- What it was changed to: exact by-memory child pages now cover constructor, two raw helpers, draw item, selection changed, and internal padding through `0x00482fb0`; score was updated from `70/80` to `82/88`.
- Summary and evidence: IDA MCP function iteration, decompilation, vtable data, string review, raw disassembly, and padding audit verify the selector cluster. Remaining uncertainty is the source-level names for the two unxrefed raw helpers and final file split.
