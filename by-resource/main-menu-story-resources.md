*** UID:0001RG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Main Menu Story Resources

## Status

- Confidence: very strong for retained `BackStoryDialogPane` resources, shared palette fanout, active `HistoryViewingPane` story resource reuse, and current DAT package evidence for the EPF/text/palette payloads.
- Related files: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) and [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- Related classes: [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md) and [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- Evidence basis: IDA MCP UTF-16 string byte checks, literal xrefs, function-bound checks, and owner docs; generated sources are only lead material.

## Confirmed Resources

| Resource | Use |
| --- | --- |
| `STORY.EPF` | EPF/high-layout background art for `BackStoryDialogPane`; also a frame-sequence resource passed to `HistoryViewingPane` from the main-menu story action. |
| `PAL01.PAL` | Palette paired with `STORY.EPF`. |
| `STORY.EPD` | Legacy background art for `BackStoryDialogPane`; also a frame-sequence resource passed to `HistoryViewingPane` from the main-menu story action. |
| `NPAL8.PAL` | Palette paired with `STORY.EPD`. |
| `BACKTALE` | Scrolled text resource unique to the retained `BackStoryDialogPane` text dialog. |

## Layout Notes

EPF mode uses a `384x341` art/control rectangle with the scrolled text at `25,56,361,278`. Legacy mode uses a `267x337` art/control rectangle with the scrolled text at `36,71,228,265`.

The [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) story path uses `STORY.EPF` or `STORY.EPD` as a full-screen frame sequence; `OnPaint` resolves entries through `LookupLayoutEntry` and renders them through `RenderTileFrame` with `NPAL4.PAL`. See [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) for that viewer-centered resource set.

## Resource Mode Matrix

| Consumer mode | Resources | Owner boundary | Rebuild implication |
| --- | --- | --- | --- |
| BackStory dialog, EPF mode | `STORY.EPF`, `PAL01.PAL`, `BACKTALE` | [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) | Package as the older story text dialog background, palette, and scrolled text resource. |
| BackStory dialog, legacy mode | `STORY.EPD`, `NPAL8.PAL`, `BACKTALE` | [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) | Preserve the smaller legacy coordinate set and shared legacy palette dependency. |
| Main-menu story viewer | `STORY.EPF` or `STORY.EPD`, rendered with `NPAL4.PAL` | [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), selected by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) | Treat as a full-screen frame-sequence viewer path, not as the BackStory dialog's text-control layout. |

B014 2026-06-19 source-quality reanalysis resolves the older BackStory constructor reachability caveat as retained/compatibility code: current active story/history menu branches and retained wrappers construct `HistoryViewingPane`, while [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) still owns the one-page `BACKTALE` dialog layout and resource use.

## Package Provenance

2026-06-14 A002 parsed the current DAT entry tables with start-offset semantics, searched loose files across `E:\2026\Resources`, and scanned the packaged executables for exact raw names. The current package contains the EPF/text/palette payloads needed by the documented EPF-mode story surfaces, while the legacy EPD operand remains executable-literal-only.

| Resource | Package evidence | Payload evidence |
| --- | --- | --- |
| `STORY.EPF` | `bint2.dat`, entry index `89`, offset `10,397,029`, size `3,970,652`; no loose duplicate found. | EPF header begins with u16s `(5, 1024, 768)`, proving five full-screen story frames. |
| `STORY.PAL` | `bint2.dat`, entry index `90`, offset `14,367,681`, size `1,056`; no loose duplicate found. | Payload begins with `DLPalette`; current package companion palette, but not the palette operand currently proven for `BackStoryDialogPane`. |
| `PAL01.PAL` | `bint2.dat`, entry index `56`, offset `9,276,430`, size `1,056`; no loose duplicate found. | Payload begins with `DLPalette`, matching the BackStory EPF-mode palette operand. |
| `STORY.EPD` | No DAT entry or loose file found. | Exact name appears only as UTF-16 executable literals at raw offsets `2,214,716` and `2,214,764` in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`; treat as a legacy old-layout blocker. |
| `NPAL8.PAL` | `bint2.dat`, entry index `50`, offset `9,161,935`, size `1,056`; no loose duplicate found. | Payload begins with `DLPalette`, matching the BackStory legacy-mode palette operand and shared legacy-dialog usage. |
| `BACKTALE` | `baram.dat`, entry index `0`, offset `191`, size `522`; no loose duplicate found. | Text-resource payload selected by `BackStoryDialogPane`, not embedded image data. |

`STORY.EPF` has full-screen dimensions in the current package even though `BackStoryDialogPane` uses smaller dialog coordinates. Keep both source paths documented against the same resource name until an older package explains whether the original project reused a full-screen atlas, cropped it, or had a different legacy payload split.

## Rebuild Packaging Boundary

- Keep the BackStory dialog source reconstruction limited to resource names, branch selection, child control placement, and close-button/text-control setup.
- Leave EPF/EPD image decoding, palette loading, and text-resource decoding with the shared image/resource/text systems.
- Keep `BACKTALE` as a separate text resource used by the story dialog; do not embed it into `STORY.EPF`/`STORY.EPD`.
- Keep `STORY.EPF`/`STORY.EPD` cross-referenced with the viewer path because the same archive names appear in two different UI modes.

## Scope Boundaries

- `PAL01.PAL` and `NPAL8.PAL` are documented here only for the BackStory dialog path. [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md) is the central authority for the complete 23-operand/sixteen-function PAL01 inventory; NPAL8 remains a broader shared legacy-palette dependency.
- `NPAL4.PAL` belongs to the `HistoryViewingPane::OnPaint`/`RenderTileFrame` path and is intentionally not the BackStory dialog palette.
- The older BackStory dialog is now treated as retained/compatibility code. This page still does not resolve the original launcher, if any, or the historical package relationship between dialog-mode `STORY.*` art and the full-screen `HistoryViewingPane` frame sequence.

## Open Questions

- Exact legacy `STORY.EPD` payload provenance and the original payload relationship between dialog-mode `STORY.*` art and viewer-mode full-screen `STORY.EPF` frames.
- Full `PAL01.PAL` consumer inventory is resolved and linked through UID0004SY. A complete NPAL8 consumer-family audit remains outside this story-specific page and does not alter the BackStory role recorded here.
- Original launcher, if any, for the older BackStory dialog constructor path.

## IDA MCP Evidence

- `STORY.EPF` at `0x0061e128` and `STORY.EPD` at `0x0061e13c` xref from `0x004f7a10-0x004f7ce9`, `0x004f90c0-0x004f913f`, and `0x00500090-0x005003e3`.
- `PAL01.PAL` at `0x00618cfc` is the new-mode palette operand in the `0x00500090-0x005003e3` decompilation (`off_618CFC`). UID0004SY and physical child [UID:0004SU][0x00618cfc-0x00618d10.Pal01PaletteResourceString](by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md) record the exact 23 operands, sixteen containing functions, DLPalette package payload, no-owner pooling, and zero-xref `L01.PAL` suffix rejection.
- `NPAL8.PAL` at `0x0061484c` is a shared legacy palette with many dialog xrefs; `0x00500090-0x005003e3` uses the legacy palette operand named `aNp` in the current IDA output.
- `BACKTALE` at `0x0061e4b8` xrefs from `0x00500200` and `0x00500337` inside `0x00500090-0x005003e3`.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed the owning function bounds: `sub_4F7A10` size `0x2d9` / 729 bytes, retained story helper `sub_4F90C0` size `0x7f` / 127 bytes, `HistoryViewingPane` constructor `sub_4FFD80` size `0x149` / 329 bytes, frame draw path `sub_500020` size `0x6b` / 107 bytes, and `BackStoryDialogPane` constructor `sub_500090` size `0x353` / 851 bytes (Verified with `int_convert.py`).
- The same refresh reconfirmed `STORY.EPF` refs at `0x004f7b86`, `0x004f9107`, `0x0050015d`, and `0x00500230`; `STORY.EPD` refs at `0x004f7bbc`, `0x004f9124`, `0x00500297`, and `0x00500367`; and `BACKTALE` refs at `0x00500200` and `0x00500337`.
- `xrefs_to 0x00618cfc` reconfirmed `PAL01.PAL` as a shared palette with 23 refs, including the BackStory EPF-branch ref at `0x00500150`; `xrefs_to 0x0061484c` reconfirmed `NPAL8.PAL` as a shared legacy palette with 60 refs, including the BackStory legacy-branch ref at `0x0050028a`.
- 2026-06-14 `get_bytes` using MCP `regions` decoded the UTF-16 literal cluster at `0x0061e128` as `STORY.EPF`, `STORY.EPD`, `HISTORY.EPF`, and `HISTORY.EPD`, and decoded `BACKTALE` at `0x0061e4b8`, `PAL01.PAL` at `0x00618cfc`, and `NPAL8.PAL` at `0x0061484c`. This closes the prior stale-session caveat for literal identity.
- 2026-06-14 A003 resume refresh on `a001_goal2_class_batch` reconfirmed exact story/backstory xrefs: `STORY.EPF` has four refs at `0x004f7b86`, `0x004f9107`, `0x0050015d`, and `0x00500230`; `STORY.EPD` has four refs at `0x004f7bbc`, `0x004f9124`, `0x00500297`, and `0x00500367`; `BACKTALE` has two refs at `0x00500200` and `0x00500337`; `PAL01.PAL` remains a 23-ref shared palette with BackStory hit `0x00500150`; `NPAL8.PAL` remains a 60-ref shared palette with BackStory hit `0x0050028a`.
- The same A003 refresh used `analyze_function` to reconfirm `sub_4F7A10` as the active main-menu selector with `STORY`/`HISTORY` and `byte_66DA97` branch markers, retained `sub_4F90C0` as the story helper with no ordinary callers, `sub_4FFD80` as the viewer constructor called from the selector/helpers, and `sub_500090` as the `BackStoryDialogPane` constructor with `byte_66DA97` asset-mode branching.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `89` | The page separates BackStory EPF and legacy dialog modes from the full-screen story viewer reuse path, records rebuild packaging boundaries, shared palette/text-resource scope limits, exact literal addresses, current xref counts/sites, current owner function bounds, byte-decoded UTF-16 evidence, retained-helper reachability caveats, current package entries for `STORY.EPF`, `STORY.PAL`, `PAL01.PAL`, `NPAL8.PAL`, and `BACKTALE`, and a central link to the complete PAL01 consumer authority. Completion remains capped because `STORY.EPD`, the broader NPAL8 inventory, original dialog-versus-viewer payload relation, and older BackStory reachability are not fully resolved. |
| Confidence `92` | Current IDA bytes, filtered xrefs, function summaries, corrected DAT parsing, EPF frame headers, `DLPalette` headers, and text-resource payload location agree with the BackStory and HistoryViewingPane owner docs. Confidence stays below final audit because the exact `STORY.EPD` payload is absent and the older BackStory constructor reachability remains open. |

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md)
- [UID:0004SU][0x00618cfc-0x00618d10.Pal01PaletteResourceString](by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Historical Superseded Assumptions

- Earlier notes described the viewer generically as a draw path and, in related pages, used `OnDraw`/`GetFrame`/`DrawEpfFrame`. The accepted source-facing route is `OnPaint` with `LookupLayoutEntry` and `RenderTileFrame`; this naming correction does not change the `STORY.*` or `NPAL4.PAL` resource evidence.

## Historical Change Log

- 2026-08-16 UID0000JW whole-file synchronization: scores remain `89/92`. `STORY.EPF` and legacy `STORY.EPD` are also accepted `HistoryViewingPane` constructor inputs for the full-screen story viewer, whose `OnPaint` path uses `NPAL4.PAL`; the BackStory dialog's `PAL01.PAL`/`NPAL8.PAL` and `BACKTALE` ownership remains separate. Retained `OpenStoryViewingPane` and active MainMenu case 3 remain MainMenu source consumers, not History source members.

- 2026-07-16 B003 UID0003AX bounded support synchronization:
  - Scores `89/92` and all story-specific source/resource facts remain unchanged.
  - Replaced the open PAL01 full-inventory question with exact UID0004SY/UID0004SU links covering 23 operands, sixteen functions, package payload, pooling, and false interior suffix evidence.
  - Preserved STORY EPF/EPD, BACKTALE, NPAL8/NPAL4 roles, retained/active split, missing STORY.EPD payload, dialog-versus-viewer boundary, and older launcher uncertainty.

- Before: page was scored `0/0` and mixed IDA and generated-source evidence wording.
- Changed to: `COMPLETION:75`, `CONFIDENCE:85`, with direct IDA MCP string/xref evidence.
- Evidence: IDA MCP UTF-16 byte search, xrefs for `STORY.EPF`/`STORY.EPD`/`BACKTALE`, and decompilation of `0x00500090-0x005003e3` for the palette operands.
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/85` to `78/85`.
  - Before: the page listed the dialog resources and story-viewer reuse but did not clearly split dialog-mode palettes/text from the full-screen viewer palette path.
  - After: it records a resource mode matrix, rebuild packaging boundary, shared-resource scope boundaries, open questions, and a current-session IDA availability caveat.
- 2026-06-14 C001 live IDA refresh: Raised completion/confidence from `78/85` to `85/88`.
  - Before: the page still carried a stale note that the previous pass could not claim a fresh IDA string/xref pass.
  - After: the page records current IDA session evidence for owner function bounds, exact literal xrefs, shared-palette fanout counts, byte-decoded UTF-16 clusters, and refreshed score rationale while leaving DAT grouping and older-constructor reachability caveats open.
  - Evidence: live IDA MCP `idb_list`, `lookup_funcs`, `xrefs_to`, and `get_bytes` on 2026-06-14 plus `int_convert.py` size conversions.
- 2026-06-14 A003 resume refresh:
  - Raised completion/confidence from `85/88` to `87/90`.
  - Added current filtered xref counts, byte cluster decode confirmation, owner function summaries, and a retained story-helper/no-caller caveat.
  - Evidence: live IDA MCP `get_bytes`, `xrefs_to`, and `analyze_function` on `a001_goal2_class_batch`; DAT grouping, frame counts, shared-palette inventory, and older BackStory reachability remain below final-audit quality.
- 2026-06-14 A002 package/frame provenance pass:
  - Before: `COMPLETION:87`, `CONFIDENCE:90`, with DAT grouping and frame counts open.
  - After: raised to `COMPLETION:89`, `CONFIDENCE:92`, after corrected DAT parsing found five-frame `STORY.EPF`, package companion `STORY.PAL`, BackStory palette operands `PAL01.PAL` and `NPAL8.PAL`, and `BACKTALE` in `baram.dat`. `STORY.EPD` remains an executable-literal-only legacy blocker in the audited package.
- 2026-06-22 Rule 26 incorporation of B014 report `0001A2-BackStoryDialogPaneCore-source-quality`: kept score unchanged, but clarified `BACKTALE` as unique to retained `BackStoryDialogPane`, separated active `HistoryViewingPane` story routing from the older BackStory text dialog, and replaced the stale "final reachability" wording with "original launcher, if any".
