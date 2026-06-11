*** UID:0001RF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Resource Mode Matrix

| Surface | Resource set | Owner boundary | Rebuild implication |
| --- | --- | --- | --- |
| Main-menu story viewer | `STORY.EPF` or `STORY.EPD`, rendered with `NPAL4.PAL` | [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), selected by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) and retained launch helpers | Package as a full-screen frame sequence for the viewer path; do not treat it as the older BackStory dialog layout even though the archive names overlap. |
| Main-menu history viewer | `HISTORY.EPF` or `HISTORY.EPD`, rendered with `NPAL4.PAL` | [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) and [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md) | Package as the history frame-sequence counterpart to the story viewer branch. |
| New history/credits dialog | `HISTORYN.EPF`, `HISTORYN.PAL`, `MADEBY` | [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), with text scrolling owned by [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md) | Package as a full-screen dialog background plus a separate text resource consumed by the made-by scroller. |

## Rebuild Packaging Boundary

- Keep `HISTORY.EPF`, `HISTORY.EPD`, `STORY.EPF`, and `STORY.EPD` available to the `HistoryViewingPane` frame viewer; this path renders with `NPAL4.PAL`.
- Keep `HISTORYN.EPF` paired with `HISTORYN.PAL` for the newer full-screen history/credits dialog.
- Keep `MADEBY` as a text resource routed through `ScrolledTextControlPaneForMadeBy`, not as image payload embedded in `HISTORYN.EPF`.
- Do not merge the viewer-centered story resources into the BackStory dialog resource ownership. That overlap is tracked explicitly by [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md).

## Scope Boundaries

- This page is centered on the history viewer and newer history/credits dialog. It references story-viewer resources only because `HistoryViewingPane` uses them.
- `NPAL4.PAL` is documented here as the viewer palette. The older BackStory dialog uses different palette operands and is covered by [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md).
- `ScrolledTextControlPane` owns made-by scrolling behavior; this resource page only records the `MADEBY` resource dependency and placement.

## Open Questions

- Exact frame counts and per-frame dimensions for `HISTORY.EPF`, `HISTORY.EPD`, `STORY.EPF`, and `STORY.EPD` in viewer mode.
- Whether `HISTORYN.EPF` and `HISTORYN.PAL` always ship with `MADEBY` in the same archive family.
- Full consumer inventory for `NPAL4.PAL` outside the story/history viewer draw path.

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
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed file/memory/resource docs and does not claim a fresh string/xref pass.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now separates viewer resources, newer history-dialog resources, shared story reuse, text-resource ownership, rebuild packaging boundaries, scope caveats, and open payload questions. Completion remains capped because frame counts, DAT grouping, and full `NPAL4.PAL` consumer coverage are not audited here. |
| Confidence `85` | Existing IDA-backed string/xref evidence and owner docs strongly identify the resource names and consumers. Confidence is unchanged because this pass did not add fresh IDA data. |

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
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/85` to `78/85`.
  - Before: the page listed resources and layout notes but did not separate viewer, newer-dialog, text-resource, and story-overlap packaging boundaries.
  - After: it records a resource mode matrix, rebuild packaging boundary, scope boundaries, open questions, and a current-session IDA availability caveat.
