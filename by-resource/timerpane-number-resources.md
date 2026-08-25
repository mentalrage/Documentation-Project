*** UID:0001RQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TimerPane Number Resources

## Status

- Confidence: very strong for resource names, call site, source/resource boundary, and current `NUMBER.EPF` package provenance; medium for the absent legacy `NUMBER.EPD` payload and visual per-frame glyph inspection.
- Related file: [UID:0000OU][TimerPane](by-file/TimerPane.md)
- Related class: [UID:0000F3][TimerPane](by-class/TimerPane.md)
- Evidence basis: IDA MCP decompile/string checks.

## Confirmed Resources

| Resource | String address | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `NUMBER.EPF` | `0x00670294` | `TimerPane::DrawDigit` | Resource-derived current-mode digit/colon atlas. Preserve the filename constant, EPF branch, and frame-index pass-through in `TimerPane.cpp`; the image bytes belong to DAT/source-asset packaging. | Used when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA `byte_66DA97` is `1`, the EPF/new asset mode branch. |
| `NUMBER.EPD` | `0x006702ac` | `TimerPane::DrawDigit` | Resource-derived legacy digit/colon atlas. Preserve the legacy filename constant and shared frame-index convention in source. | Used by the legacy/non-EPF branch. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data` and checked for loose matching files. The current EPF digit atlas is present; the legacy `.EPD` operand is not present in the audited current tree.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `NUMBER.EPF` | `bint2.dat`, entry index `52`, offset `9,204,859`, size `13,964` bytes. | EPF header begins `0b 00 48 00 48 00`, proving 11 frames of `72x72` glyph data; this matches source use of digit frames `0..9` plus colon frame `10`. |
| `NUMBER.EPD` | No matching DAT entry or loose file found in the audited current tree. | Keep the legacy branch documented from IDA string/xref evidence, but treat the payload as absent from this distribution. |

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

The implemented source/resource boundary is:

- source-owned: timer mode, seconds formatting, 2/5/8-slot layout, 35-pixel slot advance, digit/colon frame indexes, and rendering-mode branch;
- resource-owned: `NUMBER.EPF` and `NUMBER.EPD` bytes plus any DAT/archive metadata needed to load them;
- unresolved: whether the absent legacy EPD atlas used identical frame ordering beyond the documented `0..10` convention.

## String Data Contract

| Area | Source-owned declaration | Resource-owned payload |
| --- | --- | --- |
| Filename literals | [UID:0004MM][0x00598b40-0x00598bd4.TimerPaneDrawDigit](by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md) owns exact source literals `L"NUMBER.EPF"` and `L"NUMBER.EPD"`; [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md) is non-emitting compiler data. | The files named by those literals remain DAT/resource payloads rather than embedded C++ image bytes. |
| Asset-mode selection | `TimerPane::DrawDigit` owns the exact `g_useEpfAssets == 1` branch, passes the caller-provided short digit/colon frame unchanged, offsets the tile bounds, and calls `g_pfnBlitSprite` directly. | The EPF and EPD files own the visual glyph frames selected by that index. |
| Formatting contract | [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md) owns unsigned `SS`, `MM:SS`, and `HH:MM:SS` fall-through sequencing, including frame `10` colon separators, `35`-pixel slot advance, and exact 2/5/8 call counts. Historical `OnDraw` is a stale alias. | The atlas payload must provide digit frames `0..9` and colon frame `10` compatible with the source sequencing. |

## Boundary Rules

- Treat IDA labels `aNumberEpf` and `aNumberEpd` as generated string-symbol labels for the TimerPane filename constants, not as separate resources or owning globals.
- Keep the `NUMBER.*` digit atlas separate from generic font/image number rendering. This pane is a map-session countdown overlay, while generic numeric text controls and font resources have their own owners.
- The adjacent data at `0x00670268-0x00670294` and `0x006702c4+` belongs to neighboring by-memory pages. Do not widen the TimerPane string range or resource page to absorb sentinel/header data or the following vtable pointer slot.
- If asset inspection later proves branch-specific frame ordering, update this page and [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) together so source formatting and resource payload expectations stay aligned.

## Rebuild Notes

For source reconstruction, keep `TimerPane::DrawDigit` as the exact member frame renderer that receives a short digit/colon index, loads EPF only for asset flag 1, offsets copied bounds, and invokes the sprite callback directly. Do not route it through an unobserved GrafPort wrapper or fold these resources into generic font/number-string rendering.

Current package extraction proves that `NUMBER.EPF` contains 11 frames, matching the source's `0..9` digit plus `10` colon contract. Final visual extraction should still verify the rendered glyph identities and locate the legacy `NUMBER.EPD` payload in another distribution or loose resource source. If the legacy resource proves branch-specific mapping, document it here and in the TimerPane owner page.

## Open Questions

- Payload provenance for legacy `NUMBER.EPD` in another distribution or loose resource source.
- Visual confirmation that `NUMBER.EPF` frames `0..9` are digit glyphs and frame `10` is the colon, beyond the matching 11-frame header.
- Whether legacy `NUMBER.EPD` uses the same `0..9` digit and `10` colon frame ordering.

## IDA MCP Evidence

- ASCII `NUMBER.EPF` was verified at `0x00670294`, with an xref from `0x00598b6e` inside `0x00598b40-0x00598bd5`.
- ASCII `NUMBER.EPD` was verified at `0x006702ac`, with an xref from `0x00598b7f` inside the same draw helper.
- IDA decompilation of `0x00598b40-0x00598bd5` checks [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA `byte_66DA97` for `1`, then calls the resource layout renderer with `aNumberEpf` in the new/EPF branch and `aNumberEpd` in the legacy branch, passing the digit/frame index argument through unchanged.
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md) records byte-level UTF-16 decoding, one direct data reference per string, unreferenced padding words, and clean neighboring boundaries around the two filename constants.
- 2026-06-14 A003 IDA MCP refresh on database `a001_goal2_class_batch`: raw `get_bytes` over `0x00670294-0x006702c4` confirms the contiguous UTF-16 strings `NUMBER.EPF` at `0x00670294` and `NUMBER.EPD` at `0x006702ac`. `xrefs_to` reports exactly one xref to each string, `0x00598b6e` and `0x00598b7f`, both inside `sub_598B40`.
- `analyze_function 0x00598b40` in the same session reports `sub_598B40` size `0x95`, caller `sub_598960`, four basic blocks, and decompile markers `byte_66DA97`, `aNumberEpf`, and `aNumberEpd`, matching the EPF-versus-legacy branch and frame-index pass-through contract.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md)
- [UID:0004MM][0x00598b40-0x00598bd4.TimerPaneDrawDigit](by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The page now documents resource filenames, string addresses, digit/colon frame semantics, source/resource and string-data contracts, generated label handling for `aNumberEpf`/`aNumberEpd`, neighboring range boundaries, owner links, current byte/xref/function evidence, current `NUMBER.EPF` DAT provenance, and an 11-frame header matching the source frame-index contract. It remains below high completion because legacy `NUMBER.EPD` is absent from the audited package and visual per-frame glyph identities are not fully decoded. |
| Confidence | 92 | Confidence is very strong because filename strings, one-xref-per-string evidence, draw-helper branching, frame-index pass-through, exact string-data boundaries, package entry, and 11-frame EPF header are backed by current IDA evidence and direct DAT parsing. It is capped by the missing legacy `NUMBER.EPD` payload and still-unrendered visual frame audit. |

## Changes

- 2026-07-13 B003 UID0001KB callback: retained `87/92` and all package/legacy-payload/visual-audit uncertainty; corrected historical `OnDraw` to source-facing OnPaint, recorded exact 2/5/8 fall-through and 11-frame contract, direct DrawDigit sprite callback, and non-emitting pooled-string coverage by UID0004MM source literals.

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
- 2026-06-14 A003 score refresh:
  - Before: the page had exact string-data links but no current-session raw byte/xref/function refresh.
  - After: raised to `COMPLETION:85`, `CONFIDENCE:91`, with current IDA MCP byte-backed strings, one direct xref per resource, and `sub_598B40` branch markers.
  - Evidence: live IDA MCP `get_bytes`, `xrefs_to`, and `analyze_function 0x00598b40` on `a001_goal2_class_batch`; DAT/archive and payload frame audit remain open.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:91`, with current IDA string/xref evidence but no package audit for `NUMBER.*`.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:92`, with `bint2.dat` provenance for `NUMBER.EPF`, an 11-frame `72x72` EPF header matching the source digit/colon frame contract, and a negative current-package/loose-file finding for `NUMBER.EPD`.
  - Evidence: fixed-table DAT parsing of `bint2.dat` under `E:\2026\Resources\Read_Only\NexusTK\Data`.
