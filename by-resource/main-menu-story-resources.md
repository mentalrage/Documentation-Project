*** UID:0001RG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Main Menu Story Resources

## Status

- Confidence: strong for `BackStoryDialogPane` resources and `HistoryViewingPane` story resource reuse.
- Related files: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) and [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- Related classes: [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md) and [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | Use |
| --- | --- |
| `STORY.EPF` | EPF/high-layout background art for `BackStoryDialogPane`; also a frame-sequence resource passed to `HistoryViewingPane` from the main-menu story action. |
| `PAL01.PAL` | Palette paired with `STORY.EPF`. |
| `STORY.EPD` | Legacy background art for `BackStoryDialogPane`; also a frame-sequence resource passed to `HistoryViewingPane` from the main-menu story action. |
| `NPAL8.PAL` | Palette paired with `STORY.EPD`. |
| `BACKTALE` | Scrolled text resource shown inside the story dialog. |

## Layout Notes

EPF mode uses a `384x341` art/control rectangle with the scrolled text at `25,56,361,278`. Legacy mode uses a `267x337` art/control rectangle with the scrolled text at `36,71,228,265`.

The [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) story path uses `STORY.EPF` or `STORY.EPD` as a full-screen frame sequence and renders frames with `NPAL4.PAL`; see [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) for that viewer-centered resource set.

## IDA MCP Evidence

- `STORY.EPF` at `0x0061e128` and `STORY.EPD` at `0x0061e13c` xref from `0x004f7a10-0x004f7ce9`, `0x004f90c0-0x004f913f`, and `0x00500090-0x005003e3`.
- `PAL01.PAL` at `0x00618cfc` is the new-mode palette operand in the `0x00500090-0x005003e3` decompilation (`off_618CFC`); direct IDA xrefs also show this palette is shared by other UI art paths.
- `NPAL8.PAL` at `0x0061484c` is a shared legacy palette with many dialog xrefs; `0x00500090-0x005003e3` uses the legacy palette operand named `aNp` in the current IDA output.
- `BACKTALE` at `0x0061e4b8` xrefs from `0x00500200` and `0x00500337` inside `0x00500090-0x005003e3`.

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- Before: page was scored `0/0` and mixed IDA and generated-source evidence wording.
- Changed to: `COMPLETION:75`, `CONFIDENCE:85`, with direct IDA MCP string/xref evidence.
- Evidence: IDA MCP UTF-16 byte search, xrefs for `STORY.EPF`/`STORY.EPD`/`BACKTALE`, and decompilation of `0x00500090-0x005003e3` for the palette operands.
