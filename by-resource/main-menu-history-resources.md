*** UID:0001RF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Main Menu History Resources

## Status

- Confidence: strong for resource names and code owners.
- Related files: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), and [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- Related classes: [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md), [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md), and [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | Owner/use |
| --- | --- |
| `HISTORY.EPF` | EPF/high-layout frame sequence shown by `HistoryViewingPane` from main-menu history action. |
| `HISTORY.EPD` | Legacy frame sequence shown by `HistoryViewingPane` from main-menu history action. |
| `STORY.EPF` | EPF/high-layout frame sequence shown by `HistoryViewingPane` from main-menu story action; also related to [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md). |
| `STORY.EPD` | Legacy frame sequence shown by `HistoryViewingPane` from main-menu story action; also related to [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md). |
| `NPAL4.PAL` | Palette passed by `HistoryViewingPane::OnDraw` when rendering frame data. |
| `HISTORYN.EPF` | Full-screen background/dialog resource used by `NewHistoryDialogPane`. |
| `HISTORYN.PAL` | Palette paired with `HISTORYN.EPF`. |
| `MADEBY` | Text resource loaded by `ScrolledTextControlPaneForMadeBy` inside `NewHistoryDialogPane`. |

## Layout Notes

`HistoryViewingPane` is not a modal dialog. It fills the current screen dimensions and displays frames from the selected EPF/EPD resource.

`NewHistoryDialogPane` is a full-screen `1024x768` dialog. It places the `MADEBY` scrolled text control at `(614, 156)-(950, 556)` over the `HISTORYN.EPF` background.

## Evidence Notes

- `MainMenuPane::ActivateMenuItem` constructs `HistoryViewingPane` with `STORY.EPF`/`STORY.EPD` for menu item `3` and `HISTORY.EPF`/`HISTORY.EPD` for menu item `4`.
- Retained helpers [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) and [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md) perform the same resource selection, though IDA currently reports no direct callers to those helper starts.
- `HistoryViewingPane::OnDraw` calls the EPF library for the current resource and passes `NPAL4.PAL` to the render helper.
- `NewHistoryDialogPane::NewHistoryDialogPane` constructs `EPFImageControlPane(L"HISTORYN.EPF", ..., L"HISTORYN.PAL")` and `ScrolledTextControlPaneForMadeBy(L"MADEBY", ...)`.
- `ScrolledTextControlPaneForMadeBy::OnTimerEvent` closes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) when the text finishes scrolling.

## IDA MCP Evidence

- `HISTORY.EPF` at `0x0061e150` and `HISTORY.EPD` at `0x0061e168` xref from `0x004f7a10-0x004f7ce9` and the retained helper `0x004f9140-0x004f91bf`.
- `HISTORYN.PAL` at `0x0061e4cc` and `HISTORYN.EPF` at `0x0061e4e8` xref from `0x00500410-0x005005b4`.
- `MADEBY` at `0x0061e504` xrefs from `0x00500527` inside `0x00500410-0x005005b4`.
- `NPAL4.PAL` at `0x0061e514` xrefs from `0x00500061` in `0x00500020-0x0050008b`, the history/story frame draw path.

## Cross-References

- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:75`, `CONFIDENCE:85`, with direct IDA MCP string/xref evidence.
- Evidence: IDA MCP UTF-16 byte search and xrefs for history viewer, new-history dialog, `MADEBY`, and `NPAL4.PAL` resources.
