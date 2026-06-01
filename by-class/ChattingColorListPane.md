*** UID:00001S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingColorListPane

## Status

- Confidence: strong for exact local child pages through `0x00483490`; low for many later currently attached methods.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md) or split `social/ChatColorDialog.cpp`
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingColorListPane.cpp`

## Class Purpose

`ChattingColorListPane` is the color swatch list used by the chat color dialog. It selects the current color from a table, finds color entries by value, draws color swatches, and writes the selected color into the owner object's primary or secondary color arrays.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md) | `0x00482fb0-0x00483206` | Constructs the color list pane, stores owner/mode state, and appends 80 swatch entries. |
| [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) | `0x00483210-0x0048325b` | Selects the row matching the owner's current category color. |
| [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md) | `0x00483260-0x0048326f` | Raw unmodeled helper returning the selected item's stored color value; no direct xrefs currently. |
| [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) | `0x00483270-0x004832b9` | Finds a color swatch index by stored color value. |
| [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md) | `0x004832c0-0x00483414` | Draws color swatch rectangles and hover/selection borders. |
| [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md) | `0x00483420-0x00483487` | Stores selected color into the color owner and refreshes the target. |
| `ScalarDeletingDestructor` | `0x00483b00` | Local deletion helper. |

## Data Notes

- Wave3 currently attaches 42 methods to this class, including many methods from board/article, item menu, user list, and other domains.
- Treat only the exact local `0x00482fb0-0x00483490` child pages and destructor/thunks as strong chat color-list ownership until a caller/owner pass cleans up the rest.
- `0x00574510` is currently emitted as `ChattingColorListPane::ApplySelectedColor`, but a 2026-05-24 IDA MCP recheck shows only `ServerSelectPane::OnDialogAction` callers and server-select packet/config behavior. Treat it as [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md), not chat-color code.
- `ClientSpellMenuDialog::UpdateActionButtonState` currently uses a generated local `ChattingColorListPane*` spelling for its child-slot `6` list pointer. 2026-05-24 IDA evidence shows that pointer is a spell-list object from [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md), not this class.
- `0x0051f450` is currently emitted as `ChattingColorListPane::ShowBuyConfirmDialog`, but a 2026-05-24 IDA MCP recheck shows it creates `ArgumentedItemConfirmInputDialogPane` from selected argumented menu-entry fields. Treat it as an [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md), not chat-color code.

## Evidence Notes

- IDA MCP confirms exact child bodies at `0x00482fb0-0x00483206`, `0x00483210-0x0048325b`, `0x00483270-0x004832b9`, `0x004832c0-0x00483414`, `0x00483420-0x00483487`, and the scalar deleting destructor at `0x00483b00`.
- IDA raw-byte review confirms the unmodeled helper at `0x00483260-0x0048326f` and `0xcc` alignment gaps at `0x00483206-0x00483210`, `0x0048325b-0x00483260`, `0x0048326f-0x00483270`, `0x004832b9-0x004832c0`, `0x00483414-0x00483420`, and `0x00483487-0x00483490`.
- IDA vtable data points `0x00615220` to `0x00483420` and `0x00615228` to `0x004832c0`, confirming the selected-item and draw-item virtual ownership.
- IDA xrefs to the constructor are only the two `ChattingColorPane` constructor allocation sites at `0x00482837` and `0x0048295d`.
- The constructor uses constants near `0x00615460-0x00615550` to build the 80-entry color table, then zeroes index `0` for the secondary list.
- Generated source for the local core uses color-table and color-owner fields consistent with chat color customization.
- IDA MCP confirms `0x00574510` at the later address is real code, but ownership belongs to the server-select cluster by caller and data-flow evidence.
- IDA MCP confirms `0x0051f450` is a real function of size `0xae`; `xrefs_to` reports no direct callers in the current IDB, and decompilation is an argumented buy-confirm path.
- `xrefs_to 0x00482fb0` reports chat-color pane constructor callers at `0x00482837` and `0x0048295d`; no spell-menu constructor path reaches the real chat color-list constructor.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md)
- [UID:00001U][ChattingColorSelectPane](by-class/ChattingColorSelectPane.md)
- [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md)
- [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md)
- [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md)
- [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md)
- [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md)
- [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)

## Changes

- What existed before: the page documented the reliable chat color-list core and several wrong-owner generated attachments, but metadata remained `0/0`.
- What it was changed to: scores were set to `74/78`.
- Summary and evidence: local color-list methods, constructor callers, and polluted helper exclusions are documented; confidence is capped by the still-polluted generated file and remaining owner cleanup.
- 2026-05-31: Updated completion/confidence from `74/78` to `86/88`.
  - Before: the reliable local core was summarized as a broad `0x00482fb0-0x00483486` range with method starts only.
  - After: exact by-memory child pages cover the constructor, select-current helper, raw selected-color accessor, find-index helper, draw-item virtual, selected-item virtual, and internal padding through `0x00483490`.
  - Summary and evidence: IDA MCP function iteration, decompilation, xref review, vtable-slot review, color-table constant review, and raw byte audit support the split; confidence remains below 100 because later generated class attachments remain polluted and destructor/thunk cleanup still needs a focused pass.
