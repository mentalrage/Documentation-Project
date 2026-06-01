*** UID:00008C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapDialog

## Status

- Confidence: strong for purpose and core IDA-confirmed methods; medium for final file split.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably `map/MiniMapDialog.cpp` or a combined `map/MiniMap.cpp`.
- Current recovered file: `source-3/simroot_v2/class_MiniMapDialog.cpp`
- Main memory doc: [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)

## Class Purpose

`MiniMapDialog` is the in-game minimap window. It owns the `DialogPane`-derived shell, the 768x768 map view, toggle controls for map symbol categories, coordinate display controls, tooltip/hit-test behavior, timer-driven map refresh, and the embedded [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) runtime object at dialog offset `+0x1cc`.

Its static labels use a local [UID:00005C][FontStyle](by-class/FontStyle.md) configured with `Configure(0x80, 6, 1, 0)`. That style object remains reusable UI control support, not minimap-owned code.

The class is minimap/map UI feature code. It calls map, renderer, downloader, timer, and shared dialog/control helpers, but those call edges should not move the class into [UID:00007Q][MapPane](by-class/MapPane.md), [UID:0000JC][FileDownloader](by-file/FileDownloader.md), or generic dialog-control modules.

## Method Families

| Area | Address evidence | Role |
| --- | --- | --- |
| Construction and teardown | `0x00450ca0`, `0x00451330`, `0x004537bc`, `0x004537c7`, `0x004537e0` | Builds the dialog, embedded renderer, EPF controls, coordinate numeric controls, and child panes; destructor clears child panes/runtime state. The two `0x004537bc`/`0x004537c7` functions are adjustor thunks. |
| User input and actions | `0x004518b0`, `0x004519b0`, `0x00451a10` | Toggle portal/NPC display, schedule close timer, handle keyboard close, and handle mouse map-coordinate/tooltip behavior. |
| Timer and map refresh | `0x00451c90`, generated `0x004517a0` row under review | Handles download status, map-image request/retry, tooltip timing, and refresh/re-render once minimap data is ready. |
| Layout and symbol rendering | [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md), `0x004523d0`, `0x00452d20`, `0x00452f70` | Lays out static controls, creates image/symbol/text/rectangle panes, clears panes, and toggles symbol groups. |

## Boundary Caveats

- IDA MCP recheck on 2026-05-24 does not define functions at generated method starts `0x004517a0` (`RefreshMiniMap`) or `0x00452ce0` (`EnqueueRequest`). Treat those as projected/internal labels until raw disassembly or Wave3 boundary cleanup proves otherwise.
- Active `class_MiniMapDialog.cpp` also emits broad helper methods at `0x0049db60`, `0x0049dc10`, `0x0049dca0`, `0x0049dd80`, and `0x0049ddd0`. IDA caller evidence is broad across many dialogs and controls; these are shared dialog/control helpers, not minimap-owned source.
- The generated file includes some field names that imply local ownership of downloader-like state. IDA constructor evidence confirms construction of [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) at `0x00453f50`; [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md) remains its own singleton/worker class.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md)
- [UID:00008E][MiniMapImageControlPane](by-class/MiniMapImageControlPane.md)
- [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md)
- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:0000SY][GetControlLayout_452260](by-global/GetControlLayout_452260.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page had a useful class summary and method-family inventory but remained unevaluated by the completion/confidence header.
  - After: score reflects documented class purpose, owner module, major method families, embedded renderer relationship, shared-control dependencies, and explicit boundary caveats for projected generated labels.
  - Evidence: linked memory page [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) records IDA-confirmed function starts, constructor callers, seven layout-helper calls, direct renderer construction, numeric/rectangle control constructor calls, and broad-helper exclusions.
