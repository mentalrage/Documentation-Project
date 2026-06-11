*** UID:0001RG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Resource Mode Matrix

| Consumer mode | Resources | Owner boundary | Rebuild implication |
| --- | --- | --- | --- |
| BackStory dialog, EPF mode | `STORY.EPF`, `PAL01.PAL`, `BACKTALE` | [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) | Package as the older story text dialog background, palette, and scrolled text resource. |
| BackStory dialog, legacy mode | `STORY.EPD`, `NPAL8.PAL`, `BACKTALE` | [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) | Preserve the smaller legacy coordinate set and shared legacy palette dependency. |
| Main-menu story viewer | `STORY.EPF` or `STORY.EPD`, rendered with `NPAL4.PAL` | [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), selected by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) | Treat as a full-screen frame-sequence viewer path, not as the BackStory dialog's text-control layout. |

## Rebuild Packaging Boundary

- Keep the BackStory dialog source reconstruction limited to resource names, branch selection, child control placement, and close-button/text-control setup.
- Leave EPF/EPD image decoding, palette loading, and text-resource decoding with the shared image/resource/text systems.
- Keep `BACKTALE` as a separate text resource used by the story dialog; do not embed it into `STORY.EPF`/`STORY.EPD`.
- Keep `STORY.EPF`/`STORY.EPD` cross-referenced with the viewer path because the same archive names appear in two different UI modes.

## Scope Boundaries

- `PAL01.PAL` and `NPAL8.PAL` are documented here only for the BackStory dialog path; both can have other UI consumers.
- `NPAL4.PAL` belongs to the `HistoryViewingPane` draw path and is intentionally not the BackStory dialog palette.
- This page does not resolve why the older BackStory dialog remains present while the main-menu story action directly constructs the full-screen `HistoryViewingPane`.

## Open Questions

- Exact DAT grouping and payload relationship between dialog-mode `STORY.*` art and viewer-mode `STORY.*` frame sequences.
- Full consumer inventory for shared `PAL01.PAL` and `NPAL8.PAL`.
- Final reachability/provenance of the older BackStory dialog constructor path.

## IDA MCP Evidence

- `STORY.EPF` at `0x0061e128` and `STORY.EPD` at `0x0061e13c` xref from `0x004f7a10-0x004f7ce9`, `0x004f90c0-0x004f913f`, and `0x00500090-0x005003e3`.
- `PAL01.PAL` at `0x00618cfc` is the new-mode palette operand in the `0x00500090-0x005003e3` decompilation (`off_618CFC`); direct IDA xrefs also show this palette is shared by other UI art paths.
- `NPAL8.PAL` at `0x0061484c` is a shared legacy palette with many dialog xrefs; `0x00500090-0x005003e3` uses the legacy palette operand named `aNp` in the current IDA output.
- `BACKTALE` at `0x0061e4b8` xrefs from `0x00500200` and `0x00500337` inside `0x00500090-0x005003e3`.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed file/memory/resource docs and does not claim a fresh string/xref pass.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now separates BackStory EPF and legacy dialog modes from the full-screen story viewer reuse path, records rebuild packaging boundaries, shared palette/text-resource scope limits, and open provenance questions. Completion remains capped because DAT payload grouping, frame counts, and full shared-palette consumer coverage are not audited here. |
| Confidence `85` | Existing IDA-backed string/xref evidence and owner docs strongly identify the resources and their consumers. Confidence is unchanged because this pass did not add fresh IDA data. |

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
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/85` to `78/85`.
  - Before: the page listed the dialog resources and story-viewer reuse but did not clearly split dialog-mode palettes/text from the full-screen viewer palette path.
  - After: it records a resource mode matrix, rebuild packaging boundary, shared-resource scope boundaries, open questions, and a current-session IDA availability caveat.
