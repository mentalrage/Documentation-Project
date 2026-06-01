*** UID:0001RD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# IconsPane Icon Resources

## Status

- Confidence: strong for resource names and `IconsPane` usage, medium for exact icon semantics.
- Related file: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Related class: [UID:00006B][IconsPane](by-class/IconsPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | String address | Used by | Notes |
| --- | --- | --- | --- |
| `ICONS.EPD` | `0x0061b554` | `IconsPane::OnPaint` | Contains icon frames for the old-layout icon strip. |
| `NPAL7.PAL` | `0x006152ec` | `IconsPane::OnPaint` | Palette passed to the tile draw helper. |

## Frame Semantics

`IconsPane::OnPaint` draws icons in 20-pixel slots across a 160-pixel strip. Full mode starts at icon index `0`; reduced mode starts at icon index `6`.

The selected/pressed icon uses frame `index + 8`, so frames `0..7` appear to be normal icon states and frames `8..15` appear to be pressed/highlighted states.

## IDA MCP Evidence

- `ICONS.EPD` is a UTF-16 string at `0x0061b554`; xref `0x004cf379` lands in `0x004cf300-0x004cf3d3`.
- `NPAL7.PAL` is a UTF-16 string at `0x006152ec`; xref `0x004cf385` lands in `0x004cf300-0x004cf3d3`. Additional xrefs show the palette is shared by other panes.

## Cross-References

- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with direct IDA MCP resource string/xref evidence.
- Evidence: IDA MCP lookup of `ICONS.EPD` and `NPAL7.PAL` references in `0x004cf300-0x004cf3d3`.
