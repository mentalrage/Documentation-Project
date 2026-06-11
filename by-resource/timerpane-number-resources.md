*** UID:0001RQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TimerPane Number Resources

## Status

- Confidence: strong for resource names, call site, and source/resource boundary; medium for exact frame atlas layout.
- Related file: [UID:0000OU][TimerPane](by-file/TimerPane.md)
- Related class: [UID:0000F3][TimerPane](by-class/TimerPane.md)
- Evidence basis: IDA MCP decompile/string checks.

## Confirmed Resources

| Resource | String address | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `NUMBER.EPF` | `0x00670294` | `TimerPane::DrawDigit` | Resource-derived current-mode digit/colon atlas. Preserve the filename constant, EPF branch, and frame-index pass-through in `TimerPane.cpp`; the image bytes belong to DAT/source-asset packaging. | Used when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA `byte_66DA97` is `1`, the EPF/new asset mode branch. |
| `NUMBER.EPD` | `0x006702ac` | `TimerPane::DrawDigit` | Resource-derived legacy digit/colon atlas. Preserve the legacy filename constant and shared frame-index convention in source. | Used by the legacy/non-EPF branch. |

## Frame Semantics

`TimerPane::DrawDigit` passes a frame index to the resource layout table:

- indexes `0..9` are numeric digits;
- index `10` is the colon frame used in `MM:SS` and `HH:MM:SS`;
- each slot advances by `35` pixels;
- the pane height is `70` pixels.

The constructor chooses display width from the display format:

| Display format | Slots | Visual form |
| --- | --- | --- |
| `0` | `2` | `SS` |
| `1` | `5` | `MM:SS` |
| `2` | `8` | `HH:MM:SS` |

## Source Ownership Notes

[UID:0000OU][TimerPane](by-file/TimerPane.md) owns the timer/countdown state, display format, slot count, digit/colon sequencing, repaint scheduling, and EPF-versus-legacy branch. `NUMBER.EPF` and `NUMBER.EPD` are resource payloads and should not be reconstructed as C++ image data.

The current source/resource boundary is:

- source-owned: timer mode, seconds formatting, 2/5/8-slot layout, 35-pixel slot advance, digit/colon frame indexes, and rendering-mode branch;
- resource-owned: `NUMBER.EPF` and `NUMBER.EPD` bytes plus any DAT/archive metadata needed to load them;
- unresolved: whether the EPF and EPD atlases have identical frame ordering beyond the documented `0..10` convention.

## String Data Contract

| Area | Source-owned declaration | Resource-owned payload |
| --- | --- | --- |
| Filename constants | [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md) is attached to [UID:0000OU][TimerPane](by-file/TimerPane.md) and should rebuild as TimerPane-owned static wide filename constants. | The files named by those constants, `NUMBER.EPF` and `NUMBER.EPD`, remain DAT/resource payloads rather than embedded C++ image bytes. |
| Asset-mode selection | `TimerPane::DrawDigit` owns the branch on the client asset-mode flag and passes the caller-provided digit/colon frame index unchanged. | The EPF and EPD files own the visual glyph frames selected by that index. |
| Formatting contract | `TimerPane::OnDraw` owns `SS`, `MM:SS`, and `HH:MM:SS` sequencing, including the use of frame `10` for colon separators and a `35`-pixel slot advance. | The atlas payload must provide digit frames `0..9` and colon frame `10` compatible with the source sequencing. |

## Boundary Rules

- Treat IDA labels `aNumberEpf` and `aNumberEpd` as generated string-symbol labels for the TimerPane filename constants, not as separate resources or owning globals.
- Keep the `NUMBER.*` digit atlas separate from generic font/image number rendering. This pane is a map-session countdown overlay, while generic numeric text controls and font resources have their own owners.
- The adjacent data at `0x00670268-0x00670294` and `0x006702c4+` belongs to neighboring by-memory pages. Do not widen the TimerPane string range or resource page to absorb sentinel/header data or the following vtable pointer slot.
- If asset inspection later proves branch-specific frame ordering, update this page and [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) together so source formatting and resource payload expectations stay aligned.

## Rebuild Notes

For source reconstruction, keep `TimerPane::DrawDigit` as a small frame-index renderer that receives a digit/colon index from the formatting path. Do not fold these resources into generic font or number-string rendering: the owner docs place this pane in `NexusTK/map/` as a game-session overlay, distinct from generic numeric string controls.

Final asset extraction should verify that frames `0..9` are digit glyphs and frame `10` is colon in both asset branches. If the resource payload proves the EPF and EPD atlases differ, document any branch-specific mapping here and in the TimerPane owner page.

## Open Questions

- Which DAT/archive contains `NUMBER.EPF` and `NUMBER.EPD`?
- Do both resources use the same `0..9` digit and `10` colon frame ordering?
- Are there additional frame ids beyond `10` that the resource contains but this pane never uses?

## IDA MCP Evidence

- ASCII `NUMBER.EPF` was verified at `0x00670294`, with an xref from `0x00598b6e` inside `0x00598b40-0x00598bd5`.
- ASCII `NUMBER.EPD` was verified at `0x006702ac`, with an xref from `0x00598b7f` inside the same draw helper.
- IDA decompilation of `0x00598b40-0x00598bd5` checks [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA `byte_66DA97` for `1`, then calls the resource layout renderer with `aNumberEpf` in the new/EPF branch and `aNumberEpd` in the legacy branch, passing the digit/frame index argument through unchanged.
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md) records byte-level UTF-16 decoding, one direct data reference per string, unreferenced padding words, and clean neighboring boundaries around the two filename constants.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page now documents resource filenames, string addresses, digit/colon frame semantics, source/resource and string-data contracts, generated label handling for `aNumberEpf`/`aNumberEpd`, neighboring range boundaries, owner links, and remaining DAT/frame-audit questions. It remains below high completion because the actual EPF/EPD payloads, containing DAT archive, and any unused or branch-specific frames are not fully audited. |
| Confidence | 90 | Confidence stays strong because filename strings, xrefs, draw-helper branching, frame-index pass-through, and exact string-data boundaries are backed by IDA evidence in linked pages. It is capped by the uninspected resource payloads and open archive provenance. |

## Changes

- What existed before: the page was scored unevaluated and used generated `simroot_v2` as part of the evidence basis.
- Changed to: scored `COMPLETION:72` / `CONFIDENCE:88`, removed generated-source evidence wording, and added direct IDA MCP resource/xref/decompile evidence.
- Summary and evidence: the digit resource selection is verified in `0x00598b40`; score remains below final because the atlas frame layout has not been exhaustively checked against the asset data.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page documented digit frame semantics and branch resources but did not explicitly separate source-owned formatting from resource-derived atlas payloads.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:90`, with rebuild handling, source/resource boundaries, and DAT/atlas-frame open questions.
  - Summary/evidence: `TimerPane` owner docs establish source ownership for display formatting and map-overlay placement; final asset package and payload frame audit remain open.
- 2026-06-07 A002 string-data contract pass:
  - Before: the page did not explicitly tie the `aNumberEpf`/`aNumberEpd` generated labels to the exact by-memory string-data page or record neighboring range boundaries.
  - After: raised to `COMPLETION:80` with string-data contracts, generated-label handling, adjacent-range exclusions, score rationale, and an evidence link to the exact UTF-16 filename range.
