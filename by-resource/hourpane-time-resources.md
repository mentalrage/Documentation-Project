*** UID:0001RC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HourPane Time Resources

## Status

- Confidence: strong for resource names, owner usage, and source/resource boundary; medium for exact frame atlas semantics.
- Related file: [UID:0000JX][HourPane](by-file/HourPane.md)
- Related class: [UID:000068][HourPane](by-class/HourPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- |
| `TIME.EPF` | `HourPane::OnPaint` at `0x004cf010` | Resource-derived image payload. Preserve the filename constant and EPF-mode branch in `HourPane.cpp`; the bytes belong to DAT/source-asset packaging. | Used when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`, the newer/current EPF asset-mode branch. |
| `TIME.PAL` | `HourPane::OnPaint` at `0x004cf010` | Resource-derived palette payload paired with `TIME.EPF`. Source owns the loader argument, not the palette data. | Palette passed to the EPF draw helper for `TIME.EPF`. |
| `TIME.EPD` | `HourPane::OnPaint` at `0x004cf010` | Resource-derived legacy image payload. Preserve the old-mode filename constant and frame-index call path in source. | Used when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is not `1`, the old/non-EPF branch. |

## Frame Semantics

`HourPane::OnPaint` selects a frame through `word_66DB04[(currentHour / 2) % 12]`. This implies twelve visual clock/time frames, with each frame covering a two-hour block. Current evidence does not yet name each frame or prove whether `word_66DB04` is shared outside HourPane.

When no hour is set (`currentHour == -1`), the pane does not draw a time resource:

- new/current mode sets color `0` and invalidates;
- old mode sets color `0x80` and invalidates.

## Source Ownership Notes

`HourPane.cpp` owns the time-update state, invalidation behavior, hover tooltip, rendering-mode branch, and the `(currentHour / 2) % 12` lookup through `word_66DB04`. The EPF/EPD/PAL payloads are resource packaging inputs and should not be recreated as C++ data.

The current resource boundary is:

- source-owned: resource filename constants, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` branch, no-hour draw suppression, frame lookup use, and pane invalidation;
- resource-owned: `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` bytes plus any archive metadata needed to pair the palette with the EPF image;
- unresolved: whether the twelve-entry `word_66DB04` table is a HourPane-private frame ordering table or a shared resource-layout table entry.

## Runtime Branch Matrix

| Runtime state | Resource behavior | Source behavior |
| --- | --- | --- |
| Current/EPF mode with a valid hour | Loads `TIME.EPF`, draws through the current EPF helper, and passes `TIME.PAL`. | Indexes [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) with `(currentHour / 2) % 12`. |
| Legacy/EPD mode with a valid hour | Loads `TIME.EPD` and draws through the old-mode render callback. | Uses the same current-hour field and frame-table index calculation. |
| Current/EPF mode with unset hour | No `TIME.*` resource is drawn. | Fills/invalidates with color `0`. |
| Legacy/EPD mode with unset hour | No `TIME.*` resource is drawn. | Fills/invalidates with color `0x80`. |

## Rebuild Packaging Boundary

- Package the three named `TIME.*` assets as HourPane HUD resources.
- Preserve the source-level branch on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), the unset-hour suppression, and the frame-table lookup.
- Keep the actual EPF/EPD image bytes, palette contents, and DAT placement in resource packaging rather than source declarations.
- Keep [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) as the source-declared/generated-binary frame ordering dependency until a broader resource-layout audit proves it should move elsewhere.

## Rebuild Notes

For source reconstruction, keep `TIME.EPF`/`TIME.PAL` and `TIME.EPD` as literal loader inputs in the `OnPaint` branch rather than promoting them to a generic clock asset registry before broader HUD resource review. The branch is behaviorally important because no-hour handling differs between current and old rendering modes.

Final asset extraction still needs DAT/archive review to identify the package that stores the three `TIME.*` resources and to verify whether the EPF and EPD frame ordering are identical.

## Open Questions

- Which DAT/archive contains `TIME.EPF`, `TIME.PAL`, and `TIME.EPD`?
- Does `word_66DB04` live in original source as a HourPane-local static table or in a shared resource-layout table?
- Do the EPF and EPD resources share identical twelve-frame ordering, or does the old branch need a separate frame interpretation?

## IDA MCP Evidence

- `TIME.EPF` is a UTF-16 string at `0x0061b408`; xref `0x004cf069` lands in `0x004cf010-0x004cf139`.
- `TIME.PAL` is a UTF-16 string at `0x0061b41c`; xref `0x004cf07f` lands in `0x004cf010-0x004cf139`.
- `TIME.EPD` is a UTF-16 string at `0x0061b430`; xref `0x004cf100` lands in `0x004cf010-0x004cf139`.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed HourPane/resource docs and does not claim a fresh string/xref pass.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now separates current versus legacy draw behavior, unset-hour behavior, frame-table dependency, rebuild packaging boundaries, and DAT/frame-ordering open questions. Completion remains capped because exact asset payloads, DAT provenance, and final frame-table ownership are not fully audited here. |
| Confidence `87` | Existing IDA-backed string/xref evidence and HourPane owner docs identify the resources and branch behavior. Confidence is unchanged because this pass did not add fresh IDA evidence. |

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with IDA MCP string addresses and xrefs as the evidence basis.
- Evidence: IDA MCP lookup of `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` references in `0x004cf010-0x004cf139`.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page identified the resources and frame branch but did not separate source-owned behavior from DAT/source-asset payloads.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:87`, with rebuild handling, ownership boundaries, and DAT/frame-ordering open questions.
  - Summary/evidence: existing `HourPane` file/class docs tie the resources to `HourPane.cpp`; the remaining unknowns are asset provenance and whether the frame table is local or shared.
- 2026-06-07 A002 branch-matrix pass:
  - What existed before: the page documented the branch in prose but did not isolate valid-hour versus unset-hour resource behavior or the frame-table dependency in a matrix.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:87`, with runtime branch matrix, rebuild packaging boundary, frame-table dependency note, and current-session IDA availability caveat.
  - Summary/evidence: existing [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md) method evidence records the current/legacy draw split, unset-hour colors, and frame-table lookup.
- 2026-06-07 A008 alias cleanup:
  - Normalized the HourPane time-resource mode branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the historical IDA lookup alias.
