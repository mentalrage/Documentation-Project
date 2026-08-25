*** UID:0001RF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Main Menu History Resources

## Status

- Confidence: very strong for resource names, code owners, literal xrefs, viewer/dialog resource separation, current DAT package entries, and recovered frame counts.
- Related files: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), and [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- Related classes: [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md), [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md), and [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- Evidence basis: IDA MCP UTF-16 string byte checks, literal xrefs, function-bound checks, and owner docs; generated sources are only lead material.

## Confirmed Resources

| Resource | Owner/use |
| --- | --- |
| `HISTORY.EPF` | EPF/high-layout frame sequence shown by `HistoryViewingPane` from main-menu history action. |
| `HISTORY.EPD` | Legacy frame sequence shown by `HistoryViewingPane` from main-menu history action. |
| `STORY.EPF` | EPF/high-layout frame sequence shown by `HistoryViewingPane` from main-menu story action; also related to [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md). |
| `STORY.EPD` | Legacy frame sequence shown by `HistoryViewingPane` from main-menu story action; also related to [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md). |
| `NPAL4.PAL` | Palette passed by `HistoryViewingPane::OnPaint` through `RenderTileFrame` after `LookupLayoutEntry` resolves the selected frame. |
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

## Package Provenance

2026-06-14 A002 parsed the current DAT entry tables with start-offset semantics, searched loose files across `E:\2026\Resources`, and scanned the packaged executables for exact raw names. The current package contains the EPF/PAL/text resources for the EPF-mode viewer and newer history dialog, while the legacy EPD operands remain executable-literal-only.

| Resource | Package evidence | Payload evidence |
| --- | --- | --- |
| `HISTORY.EPF` | `bint2.dat`, entry index `0`, offset `2,214`, size `6,353,036`; no loose duplicate found. | EPF header begins with u16s `(8, 1024, 768)`, proving eight full-screen viewer frames. |
| `HISTORY.EPD` | No DAT entry or loose file found. | Exact name appears only as a UTF-16 executable literal at raw offset `2,214,760` in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`; treat as a legacy old-layout blocker. |
| `STORY.EPF` | `bint2.dat`, entry index `89`, offset `10,397,029`, size `3,970,652`; no loose duplicate found. | EPF header begins with u16s `(5, 1024, 768)`, proving five full-screen story viewer frames. |
| `STORY.EPD` | No DAT entry or loose file found. | Exact name appears only as UTF-16 executable literals at raw offsets `2,214,716` and `2,214,764`; treat as a legacy old-layout blocker. |
| `NPAL4.PAL` | `bint2.dat`, entry index `46`, offset `9,157,711`, size `1,056`; no loose duplicate found. | Payload begins with `DLPalette`, matching the viewer draw path. |
| `HISTORYN.EPF` | `bint2.dat`, entry index `1`, offset `6,355,250`, size `794,140`; no loose duplicate found. | EPF header begins with u16s `(1, 1024, 768)`, matching the newer full-screen history/credits dialog background. |
| `HISTORYN.PAL` | `bint2.dat`, entry index `2`, offset `7,149,390`, size `1,056`; no loose duplicate found. | Payload begins with `DLPalette`. |
| `MADEBY` | `baram.dat`, entry index `8`, offset `11,267,987`, size `997`; no loose duplicate found. | Text-resource payload, not image data; selected by `NewHistoryDialogPane` for the made-by scroller. |

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

- Locate legacy `HISTORY.EPD` and `STORY.EPD` in another distribution or loose resource source; the audited current package contains the EPF viewer payloads but only executable literals for the EPD names.
- Determine whether `HISTORYN.EPF`/`.PAL` and `MADEBY` were originally declared as a logical resource group despite shipping in different current DAT archives.
- Full consumer inventory for `NPAL4.PAL` outside the story/history viewer draw path.

## Evidence Notes

- `MainMenuPane::ActivateMenuItem` constructs `HistoryViewingPane` with `STORY.EPF`/`STORY.EPD` for menu item `3` and `HISTORY.EPF`/`HISTORY.EPD` for menu item `4`.
- Retained helpers [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) and [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md) perform the same resource selection, though IDA currently reports no direct callers to those helper starts.
- `HistoryViewingPane::OnPaint` resolves the selected resource/frame with `g_pEPFLib->LookupLayoutEntry` and passes `NPAL4.PAL` to `RenderTileFrame`.
- `NewHistoryDialogPane::NewHistoryDialogPane` constructs `EPFImageControlPane(L"HISTORYN.EPF", ..., L"HISTORYN.PAL")` and `ScrolledTextControlPaneForMadeBy(L"MADEBY", ...)`.
- `ScrolledTextControlPaneForMadeBy::OnTimerEvent` closes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) when the text finishes scrolling.

## IDA MCP Evidence

- `HISTORY.EPF` at `0x0061e150` and `HISTORY.EPD` at `0x0061e168` xref from `0x004f7a10-0x004f7ce9` and the retained helper `0x004f9140-0x004f91bf`.
- `HISTORYN.PAL` at `0x0061e4cc` and `HISTORYN.EPF` at `0x0061e4e8` xref from `0x00500410-0x005005b4`.
- `MADEBY` at `0x0061e504` xrefs from `0x00500527` inside `0x00500410-0x005005b4`.
- `NPAL4.PAL` at `0x0061e514` xrefs from `0x00500061` in `0x00500020-0x0050008b`, the history/story frame draw path.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed the owning function bounds: `sub_4F7A10` size `0x2d9` / 729 bytes, retained story/history helpers `sub_4F90C0` and `sub_4F9140` size `0x7f` / 127 bytes each, `HistoryViewingPane` constructor `sub_4FFD80` size `0x149` / 329 bytes, draw path `sub_500020` size `0x6b` / 107 bytes, and `NewHistoryDialogPane` constructor `sub_500410` size `0x1a4` / 420 bytes (Verified with `int_convert.py`).
- The same refresh reconfirmed history/story literal xrefs: `STORY.EPF` has refs at `0x004f7b86`, `0x004f9107`, `0x0050015d`, and `0x00500230`; `STORY.EPD` has refs at `0x004f7bbc`, `0x004f9124`, `0x00500297`, and `0x00500367`; `HISTORY.EPF` has refs at `0x004f7c00` and `0x004f9187`; `HISTORY.EPD` has refs at `0x004f7c36` and `0x004f91a4`.
- 2026-06-14 xrefs also reconfirmed `HISTORYN.PAL` at `0x005004c3`, `HISTORYN.EPF` at `0x005004d0` and `0x00500545`, `MADEBY` at `0x00500527`, and `NPAL4.PAL` at `0x00500061`.
- 2026-06-14 `get_bytes` using MCP `regions` decoded the contiguous UTF-16 literal cluster at `0x0061e128` as `STORY.EPF`, `STORY.EPD`, `HISTORY.EPF`, and `HISTORY.EPD`; the cluster at `0x0061e4b8` as `BACKTALE`, `HISTORYN.PAL`, `HISTORYN.EPF`, `MADEBY`, and `NPAL4.PAL`. This closes the prior stale-session caveat for literal identity.
- 2026-06-14 A003 resume refresh on `a001_goal2_class_batch` reconfirmed the same byte clusters with direct `get_bytes` decoding and filtered `xrefs_to`: `HISTORY.EPF` has exactly two refs, `0x004f7c00` in `sub_4F7A10` and `0x004f9187` in retained helper `sub_4F9140`; `HISTORY.EPD` has exactly two refs, `0x004f7c36` and `0x004f91a4`; `HISTORYN.PAL` has the sole `sub_500410` ref at `0x005004c3`; `HISTORYN.EPF` has `sub_500410` refs at `0x005004d0` and `0x00500545`; `MADEBY` has the sole `sub_500410` ref at `0x00500527`; `NPAL4.PAL` has the sole draw-path ref at `0x00500061`.
- The same A003 refresh used `analyze_function` to reconfirm owner roles: `sub_4F7A10` callers `sub_4F6AF0` and `sub_4F6BF0` with `STORY`/`HISTORY` and `byte_66DA97` branch markers, retained helpers `sub_4F90C0` and `sub_4F9140` as no-caller legacy launch helpers, `sub_4FFD80` called from all three launch paths, `sub_500020` carrying the `NPAL4` draw marker, and `sub_500410` carrying `HISTORYN`/new-history constructor markers.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | The page separates viewer resources, newer history-dialog resources, shared story reuse, text-resource ownership, rebuild packaging boundaries, scope caveats, exact literal addresses, current owner function bounds, exact xref counts/sites, byte-decoded UTF-16 literal clusters, retained-helper reachability caveats, and current DAT package entries for `HISTORY.EPF`, `STORY.EPF`, `HISTORYN.EPF`, `HISTORYN.PAL`, `NPAL4.PAL`, and `MADEBY`. Completion remains capped because legacy `HISTORY.EPD`/`STORY.EPD`, original source grouping, and full shared-palette inventory are still open. |
| Confidence `93` | Current IDA string bytes, filtered xrefs, function summaries, corrected DAT parsing, EPF frame headers, `DLPalette` headers, and text-resource payload locations agree with the owner docs and support the resource split. Confidence remains below final audit because the EPD payloads are absent from the audited package and original archive/source grouping is still unresolved. |

## Cross-References

- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Historical Superseded Assumptions

- Earlier source-shape notes called the paint virtual `OnDraw` and described one-off `GetFrame`/`DrawEpfFrame` helpers. Those names were plausible from the raw draw path before shared ImageLib/EPFTileContext and GrafPort contracts were reconciled. The accepted source uses `HistoryViewingPane::OnPaint`, `LookupLayoutEntry`, and `RenderTileFrame`; the resource ownership and `NPAL4.PAL` operand are unchanged.

## Historical Change Log

- 2026-08-16 UID0000JW whole-file synchronization: scores remain `90/93`. `HISTORY.EPF` and legacy `HISTORY.EPD` are constructor-selected `HistoryViewingPane` frame sequences; `NPAL4.PAL` belongs to its `OnPaint` path using `LookupLayoutEntry` and `RenderTileFrame`. The resource page remains packaging ownership, while source behavior emits through standalone `NexusTK/login/HistoryViewingPane.cpp/.h`. Earlier `OnDraw`/`GetFrame`/`DrawEpfFrame` naming is superseded source-shape history.

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:75`, `CONFIDENCE:85`, with direct IDA MCP string/xref evidence.
- Evidence: IDA MCP UTF-16 byte search and xrefs for history viewer, new-history dialog, `MADEBY`, and `NPAL4.PAL` resources.
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/85` to `78/85`.
  - Before: the page listed resources and layout notes but did not separate viewer, newer-dialog, text-resource, and story-overlap packaging boundaries.
  - After: it records a resource mode matrix, rebuild packaging boundary, scope boundaries, open questions, and a current-session IDA availability caveat.
- 2026-06-14 C001 live IDA refresh: Raised completion/confidence from `78/85` to `85/88`.
  - Before: the page still carried a stale note that the previous pass could not claim a fresh IDA string/xref pass.
  - After: the page records current IDA session evidence for owner function bounds, exact literal xrefs, byte-decoded UTF-16 clusters, and refreshed score rationale while leaving DAT/frame-count and shared-palette caveats open.
  - Evidence: live IDA MCP `idb_list`, `lookup_funcs`, `xrefs_to`, and `get_bytes` on 2026-06-14 plus `int_convert.py` size conversions.
- 2026-06-14 A003 resume refresh:
  - Raised completion/confidence from `85/88` to `87/90`.
  - Added current filtered xref counts, byte cluster decode confirmation, owner function summaries, and the explicit retained-helper/no-caller caveat.
  - Evidence: live IDA MCP `get_bytes`, `xrefs_to`, and `analyze_function` on `a001_goal2_class_batch`; DAT grouping, frame counts, and payload dimensions remain below final-audit quality.
- 2026-06-14 A002 package/frame provenance pass:
  - Before: `COMPLETION:87`, `CONFIDENCE:90`, with DAT grouping and frame counts open.
  - After: raised to `COMPLETION:90`, `CONFIDENCE:93`, after corrected DAT parsing found eight-frame `HISTORY.EPF`, five-frame `STORY.EPF`, one-frame `HISTORYN.EPF`, `HISTORYN.PAL`, `NPAL4.PAL`, and `MADEBY` payloads. `HISTORY.EPD` and `STORY.EPD` remain executable-literal-only legacy blockers in the audited package.
