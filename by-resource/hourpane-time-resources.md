*** UID:0001RC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HourPane Time Resources

## Status

- Confidence: strong for resource names and HourPane usage, medium for exact frame atlas semantics.
- Related file: [UID:0000JX][HourPane](by-file/HourPane.md)
- Related class: [UID:000068][HourPane](by-class/HourPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | Used by | Notes |
| --- | --- | --- |
| `TIME.EPF` | `HourPane::OnPaint` at `0x004cf010` | Used when `byte_66DA97 == 1`, the newer/current EPF asset-mode branch. |
| `TIME.PAL` | `HourPane::OnPaint` at `0x004cf010` | Palette passed to the EPF draw helper for `TIME.EPF`. |
| `TIME.EPD` | `HourPane::OnPaint` at `0x004cf010` | Used when `byte_66DA97 != 1`, the old/non-EPF branch. |

## Frame Semantics

`HourPane::OnPaint` selects a frame through `word_66DB04[(currentHour / 2) % 12]`. This implies twelve visual clock/time frames, with each frame covering a two-hour block. Current evidence does not yet name each frame or prove whether `word_66DB04` is shared outside HourPane.

When no hour is set (`currentHour == -1`), the pane does not draw a time resource:

- new/current mode sets color `0` and invalidates;
- old mode sets color `0x80` and invalidates.

## IDA MCP Evidence

- `TIME.EPF` is a UTF-16 string at `0x0061b408`; xref `0x004cf069` lands in `0x004cf010-0x004cf139`.
- `TIME.PAL` is a UTF-16 string at `0x0061b41c`; xref `0x004cf07f` lands in `0x004cf010-0x004cf139`.
- `TIME.EPD` is a UTF-16 string at `0x0061b430`; xref `0x004cf100` lands in `0x004cf010-0x004cf139`.

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with IDA MCP string addresses and xrefs as the evidence basis.
- Evidence: IDA MCP lookup of `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` references in `0x004cf010-0x004cf139`.
