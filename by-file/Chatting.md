*** UID:0000I5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:83 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Chatting

## Status

- Confidence: strong for the core chat UI classes and message rendering; medium for the final split between `social/Chatting.cpp`, a generic `FolderTreePane.cpp`, and smaller chat color/input files.
- Proposed module folder: `social/`
- Proposed source file: `social/Chatting.cpp`
- Possible split files: `social/ChatInputPane.cpp`, `social/ChatColorDialog.cpp`; the real filesystem tree control is documented separately as [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
- Evidence basis: IDA MCP function-boundary, decompilation, xref, vtable, and raw-byte checks. Wave3/generated `simroot_v2` sources are lead material only and must not override IDA evidence.

## Hypothesis

The `Chatting*` classes form a coherent chat UI source module: the scrolling display pane, background pane, resize handle, mode selector, chat handle buttons, color picker panes, and colored message object all sit in the compact `0x0047efb0-0x00483ef7` address neighborhood.

The line input pane is physically later at `0x005b3940-0x005b3bba`, but it is behaviorally part of the same feature because it owns chat history navigation, opcode `0x0e` packet send, and `g_pChatInputPane`.

The current `FolderTreePane` owner for `AddChattingMessage`, `AddIncomingMessage`, `SetVisibleRowCount`, and `HandleChatPacketType10` should not be ignored. Existing Wave2 notes treated that owner as authoritative, and Wave3 still models those methods under `FolderTreePane`. For source layout, keep them as a boundary question for chat-message ownership; do not confuse them with the filesystem [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) control core at `0x004b1b90-0x004b32c9`.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ChattingPane` | `0x0047efb0-0x0047fd68`, plus scroll helpers at `0x0055e7e0+` | `class_ChattingPane.cpp` | Scrollable chat display pane, message list allocation, line measurement, input scroll navigation, paint, scrollbar sync, and the raw reset-scroll-range helper [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md). |
| `FolderTreePane` chat-message subset | `0x0047f280-0x004805d4` | `class_FolderTreePane.cpp` | Creates `ColorStringChattingMessage` objects, adds incoming messages, resizes visible rows, and decodes chat packet subtype `10`. |
| `ChattingBackPane` | `0x00480640-0x004807aa`, destructor at `0x00483aa0` | `class_ChattingBackPane.cpp` | Transparent chat background pane tied to chat handle visibility/mode state. |
| `ChattingModifyHeightPane` | `0x004807b0-0x00480c45`, helper at [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md), destructor at `0x00483c00` | `class_ChattingModifyHeightPane.cpp` plus generated `class_BackPane.cpp` owner caveat | Drag handle for changing visible chat line count, recomputing the scroll viewport from BackPane/root bounds, and persisting it to config. |
| `ChattingVarietyPane` | `0x00480c50-0x0048100a`, destructor at `0x00483d50`, helper at `0x004b9670` | `class_ChattingVarietyPane.cpp` | Compact chat mode button that opens the mode selector and paints the current Talk/Shout/Whisper/Group/Clan label. |
| `ChattingVarietySelectPane` | confirmed `0x004811c0-0x00481b5b`, projected constructor `0x004810f0` | `class_ChattingVarietySelectPane.cpp` | Popup selector for Talk, Shout, Whisper, Group, Clan, and Color, including the six-row [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md). |
| `ChattingHandlePane` | exact child pages through `0x004824e0`, destructor at `0x00483ba0` | `class_ChattingHandlePane.cpp` | Chat handle buttons for display/filter/bubble or mode toggles, persisted config state, raw rectangle helper, and hit-test helper with switch-table tail. |
| [UID:0000SX][GetChatButtonAtPoint](by-global/GetChatButtonAtPoint.md) | [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) | `recovered/GetChatButtonAtPoint_00482400.cpp` | File-local chat handle hit-test helper; recovered signature is coordinate based. |
| `ChattingColorPane` | exact child pages through `0x00482ca0`, destructor at `0x00483b40` | `class_ChattingColorPane.cpp` | Color picker dialog shell; local constructor/destructor body/button handler/raw helpers are split, but generated file remains polluted with unrelated methods. |
| `ChattingColorSelectPane` | exact child pages through `0x00482fb0`, destructor at `0x0047e9d0` | `class_ChattingColorSelectPane.cpp` | Selects and draws chat color categories: Talk/Shout/Whisper/Group/Clan/System. |
| `ChattingColorListPane` | exact child pages through `0x00483490`, destructor at `0x00483b00` | `class_ChattingColorListPane.cpp` | Displays selectable color swatches and writes selected colors into the color owner object. |
| `ColorStringChattingMessage` | exact child pages through `0x004839c0`, scalar destructor in glue through `0x00483ef7` | `class_ColorStringChattingMessage.cpp` | Chat message object storing wide text and palette/custom RGB state, with low-res and high-res drawing paths. |
| `ChatInputPane` | raw packet helper [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md), raw constructor [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md), confirmed submit/history block [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) | `class_ChatInputPane.cpp` | Multi-line chat input with history navigation, text normalization, packet send, and history save. |

## Boundary And Data Notes

- IDA MCP confirms the real function starts for the core chat UI block, including `0x0047efb0`, `0x0047f280`, `0x0047ff80`, `0x00480640`, `0x004807b0`, `0x00480c50`, `0x004811c0`, `0x00481c10`, `0x00482400`, `0x004824e0`, `0x00482ca0`, `0x00482fb0`, `0x00483490`, `0x004836a0`, and the destructor family through `0x00483e60`.
- IDA reports no function at Wave3's `ChattingVarietySelectPane::ChattingVarietySelectPane` start `0x004810f0`; the next real function is `0x00481150`, followed by the confirmed `OnMouseEvent` at `0x004811c0`.
- IDA MCP on 2026-05-26 resolves `0x00481ad0-0x00481b5b` as the `ChattingVarietySelectPane` six-row hit-test helper, with both callers inside `OnMouseEvent`.
- IDA MCP on 2026-05-26 resolves generated `BackPane::SetScrollViewport` at `0x004806d0` as a chat-height layout helper: its only direct caller is `ChattingModifyHeightPane::OnMouseEvent` at `0x0048093e`.
- IDA reports no function at the recovered `ChatInputPane::ChatInputPane` start `0x005b38e0`; 2026-06-02 raw byte/disassembly review confirms [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md) as a constructor-shaped body and confirms the method cluster at `0x005b3940-0x005b3bba`.
- 2026-06-02 IDA raw byte/disassembly review also confirms adjacent file-level chat packet helper [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md), which sends opcode `0x0e`, subtype `0` from a wide string argument.
- `class_ChattingColorPane.cpp` currently contains unrelated `SpellInventoryPane`, history viewing, music control, and localized alert methods. Treat only the exact `0x004824e0-0x00482ca0` local core and local destructor/thunk ranges as strong chat-color evidence until the polluted generated owner is repaired.
- `class_ChattingColorListPane.cpp` includes a strong local color-list core, but many later methods are owner pollution from list/menu/user-list domains. `0x00574510`, currently emitted as `ChattingColorListPane::ApplySelectedColor`, is now documented as a [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md).
- 2026-05-26 IDA recheck resolves the `GetChatButtonAtPoint` signature mismatch: [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) takes `mouseX, mouseY`; the generated `ChattingHandlePane` call-site spelling `GetChatButtonAtPoint(this, eventData)` is wrong because the binary pushes `eventData + 0x08` and `eventData + 0x0c` coordinate fields before the call.
- 2026-05-31 IDA split pass resolves the `ChattingHandlePane` child range from `0x00481c10-0x004824e0`, including constructor/destructor body, mouse/paint methods, tiny refresh forwarder, raw button rectangle helper, and `GetChatButtonAtPoint` switch-table tail.
- 2026-05-31 IDA split pass resolves the `ChattingColorPane` local core from `0x004824e0-0x00482ca0`, including constructor, destructor body, button response, raw selector refresh helper, raw list sync helper, and internal `0xcc` alignment padding.
- 2026-05-31 IDA split pass resolves the `ChattingColorSelectPane` local cluster from `0x00482ca0-0x00482fb0`, including constructor, two raw helper bodies, draw-item virtual, selection-changed virtual, Talk/Shout/Whisper/Group/Clan/System label strings, vtable slots, and internal `0xcc` alignment padding.
- 2026-05-31 IDA split pass resolves the `ChattingColorListPane` local cluster from `0x00482fb0-0x00483490`, including constructor, select-current helper, raw selected-color accessor, find-index helper, draw-item virtual, selected-item virtual, color-table constants, vtable slots, and internal `0xcc` alignment padding.
- 2026-05-31 IDA split pass resolves `ColorStringChattingMessage` from `0x00483490-0x004839c0`, including constructor, destructor body, clone virtual, line-count virtual, draw virtual, draw switch/mapping tail tables, and the trailing compiler-generated chat UI destructor glue family through `0x00483ef7`.

## Migration Notes

Do not run ownership migrations until the color-pane pollution and projected constructor starts are corrected or explicitly marked projected. Start with a dry-run file creation, then only run the attach operations after reviewing the resulting plan. Current `wave3.py --help` advertises dry-run for `create file`, but not for `attach class`.

```powershell
python source-3\wave3.py create file Chatting.cpp --kind source --simpath social/Chatting.cpp --dry-run
python source-3\wave3.py attach class ChattingPane --to-file Chatting.cpp
python source-3\wave3.py attach class ChattingBackPane --to-file Chatting.cpp
python source-3\wave3.py attach class ChattingModifyHeightPane --to-file Chatting.cpp
python source-3\wave3.py attach class ChattingVarietyPane --to-file Chatting.cpp
python source-3\wave3.py attach class ChattingVarietySelectPane --to-file Chatting.cpp
python source-3\wave3.py attach class ChattingHandlePane --to-file Chatting.cpp
python source-3\wave3.py attach class ColorStringChattingMessage --to-file Chatting.cpp
```

Keep `ChattingColorPane`, `ChattingColorSelectPane`, and `ChattingColorListPane` in a possible split `ChatColorDialog.cpp` if their file stays large after data cleanup.

## Cross-References

- [UID:00001X][ChattingPane](by-class/ChattingPane.md)
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md)
- [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md)
- [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md)
- [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md)
- [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:0000SX][GetChatButtonAtPoint](by-global/GetChatButtonAtPoint.md)
- [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md)
- [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md)
- [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md)
- [UID:0002FW][0x00482310-0x00482400.ChatButtonRectHelperRaw](by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md)
- [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md)
- [UID:0002FX][0x004824e0-0x00482b01.ChattingColorPaneConstructor](by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md)
- [UID:0002FY][0x00482b10-0x00482b2f.ChattingColorPaneDestructor](by-memory/0x00482b10-0x00482b2f.ChattingColorPaneDestructor.md)
- [UID:0002FZ][0x00482b30-0x00482c32.ChattingColorPaneOnButtonResponse](by-memory/0x00482b30-0x00482c32.ChattingColorPaneOnButtonResponse.md)
- [UID:0002G0][0x00482c40-0x00482c54.ChattingColorPaneRefreshColorSelectHelperRaw](by-memory/0x00482c40-0x00482c54.ChattingColorPaneRefreshColorSelectHelperRaw.md)
- [UID:0002G1][0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListSelectionHelperRaw](by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListSelectionHelperRaw.md)
- [UID:00001U][ChattingColorSelectPane](by-class/ChattingColorSelectPane.md)
- [UID:0002G2][0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor](by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md)
- [UID:0002G3][0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw](by-memory/0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw.md)
- [UID:0002G4][0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw](by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md)
- [UID:0002G5][0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem](by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md)
- [UID:0002G6][0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged](by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)
- [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md)
- [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md)
- [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md)
- [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md)
- [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md)
- [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md)
- [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md)
- [UID:0002GD][0x00483490-0x00483541.ColorStringChattingMessageConstructor](by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md)
- [UID:0002GE][0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody](by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md)
- [UID:0002GF][0x004835b0-0x0048362b.ColorStringChattingMessageClone](by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md)
- [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md)
- [UID:0002GH][0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables](by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md)
- [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md)
- [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page documented chat UI grouping, proposed split, entity table, boundary/data notes, migration cautions, and cross-references but remained unevaluated.
  - After: score reflects documented chat panes, handle/color/message/input relationships, key memory ranges, projected-constructor caveats, FolderTreePane ownership question, and generated owner-pollution exclusions.
  - Evidence: recorded IDA checks confirm core chat UI starts, hit-test helper ownership, chat-height layout helper caller, `GetChatButtonAtPoint` signature correction, and strong links to chat UI/input memory pages.
- 2026-05-31: Grading changed from `78/82` to `80/84`.
  - Before: `ChattingColorPane` was still described as a broad core range through `0x00482c31`.
  - After: the page records exact child pages through `0x00482ca0` and clarifies that Wave3/simroot are lead sources only.
  - Evidence: IDA MCP confirms the color-pane constructor, destructor body, button response, raw selector refresh helper, raw list sync helper, vtable ownership for `0x00482b30`, and internal `0xcc` padding.
- 2026-05-31: Grading changed from `80/84` to `81/85`.
  - Before: `ChattingColorSelectPane` was only listed as a broad `0x00482ca0-0x00482fa5` selector block.
  - After: the page records exact child pages through `0x00482fb0`, including raw helpers and padding.
  - Evidence: IDA MCP confirms selector constructor/draw/selection function bounds, vtable slots, label strings, raw helper disassembly, and `0xcc` alignment.
- 2026-05-31: Grading changed from `81/85` to `82/86`.
  - Before: `ChattingColorListPane` was listed as a broad strong core range through `0x00483486`.
  - After: the page records exact child pages through `0x00483490`, including the raw selected-color accessor and padding.
  - Evidence: IDA MCP confirms constructor/select/find/draw/selected function bounds, vtable slots, color-table constants, raw helper disassembly, xrefs, and `0xcc` alignment.
- 2026-05-31: Grading changed from `82/86` to `83/87`.
  - Before: `ColorStringChattingMessage` remained a broad `0x00483490-0x00483ef7` block.
  - After: the page records exact child pages for the message constructor/destructor/clone/line-count/draw methods and the trailing compiler-generated destructor glue family.
  - Evidence: IDA MCP confirms method bounds, vtable slots, draw tail-table xrefs, scalar deleting destructor wrappers, adjustor thunks, singleton-clear helpers, and `0xcc` alignment.
- 2026-06-02 `ChatInputPane` constructor/helper split:
  - Before: the proposed contents only described `0x005b38e0` as a projected constructor start.
  - After: linked exact raw packet helper [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md), raw constructor child [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md), and confirmed method cluster [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md).
  - Evidence: IDA raw bytes, vtable stores, decompilation, and callee maps confirm the helper/constructor/method boundaries.
- 2026-06-03 `ChattingPane` raw helper ownership:
  - Before: the proposed contents row stopped at `0x0047fd3a`, before the already documented raw reset-scroll-range helper.
  - After: the row extends through [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md).
  - Evidence: the exact memory page and [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) record the raw helper bytes, padding before/after, and shared scroll-helper behavior inside the chat display pane band.
