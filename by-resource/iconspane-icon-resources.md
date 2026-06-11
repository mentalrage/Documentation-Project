*** UID:0001RD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# IconsPane Icon Resources

## Status

- Confidence: strong for resource names, `IconsPane` usage, and source/resource boundary; medium for exact icon semantics.
- Related file: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Related class: [UID:00006B][IconsPane](by-class/IconsPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | String address | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `ICONS.EPD` | `0x0061b554` | `IconsPane::OnPaint` | Resource-derived old-layout icon-strip payload. Preserve the filename and frame-index math in `IconsPane.cpp`; the image bytes belong to DAT/source-asset packaging. | Contains icon frames for the old-layout icon strip. |
| `NPAL7.PAL` | `0x006152ec` | `IconsPane::OnPaint` | Shared palette payload. `IconsPane` is a consumer; do not make the palette icon-pane-private before auditing other `NPAL7.PAL` users. | Palette passed to the tile draw helper. |

## Frame Semantics

`IconsPane::OnPaint` draws icons in 20-pixel slots across a 160-pixel strip. Full mode starts at icon index `0`; reduced mode starts at icon index `6`.

The selected/pressed icon uses frame `index + 8`, so frames `0..7` appear to be normal icon states and frames `8..15` appear to be pressed/highlighted states.

## Source Ownership Notes

`IconsPane.cpp` owns the full/reduced visibility mode, icon hit testing, selected/pressed state, tooltip text-id range, click dispatch, and the frame-index convention used against `ICONS.EPD`. The resource page should track the payload names and shared palette dependency without absorbing those UI behaviors.

`NPAL7.PAL` is also referenced by other HUD/status resource pages, including [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) and [UID:0001RS][user-status-resources](by-resource/user-status-resources.md). Treat it as a shared old-HUD palette candidate until the remaining consumers are audited.

## Runtime Mode Matrix

| IconsPane mode | Visible icon range | Resource behavior | Source behavior |
| --- | --- | --- | --- |
| Full icon strip | Frames `0..7`, with pressed/highlighted frames `8..15` | Draws `ICONS.EPD` with `NPAL7.PAL` across the 160-pixel strip. | Starts at icon index `0`, advances in 20-pixel slots, and uses `index + 8` when the selected icon is pressed. |
| Reduced icon strip | Frames `6..7`, with pressed/highlighted frames `14..15` | Uses the same `ICONS.EPD` atlas and `NPAL7.PAL` palette. | Starts hit-testing/painting at icon index `6`; option UI toggles persist the full/reduced mode. |

## Rebuild Packaging Boundary

- Package `ICONS.EPD` as the old-layout icon atlas and keep `NPAL7.PAL` available as a shared old-HUD palette.
- Preserve the source-level full/reduced mode, hit-test math, tooltip id range, action dispatch, and pressed-frame offset in [UID:0000JZ][IconsPane](by-file/IconsPane.md).
- Keep exact icon semantics and click-action names in the IconsPane class/memory docs rather than encoding them as resource-page conclusions before the raw action dispatch is fully named.
- Do not split `NPAL7.PAL` into IconsPane-private data until TotemFrame and user-status consumers are fully reconciled.

## Rebuild Notes

For source reconstruction, keep the icon atlas behavior in `IconsPane::OnPaint`: full mode starts at frame `0`, reduced mode starts at frame `6`, and pressed/highlighted icons draw `index + 8`. The EPD bytes and palette contents remain resource packaging work.

Avoid merging this page with `TabPane` or option-dialog docs. The open grouping question in the class/file pages concerns source adjacency and shared helper tails, not ownership of `ICONS.EPD`.

## Open Questions

- Which DAT/archive contains `ICONS.EPD` and the shared `NPAL7.PAL` palette?
- What are the final semantic names for frames `0..7` and pressed frames `8..15` after click-action helper naming is finished?
- Should `NPAL7.PAL` be promoted to a shared old-HUD palette resource page after `TotemFrame`, `IconsPane`, and user-status consumers are fully reconciled?

## IDA MCP Evidence

- `ICONS.EPD` is a UTF-16 string at `0x0061b554`; xref `0x004cf379` lands in `0x004cf300-0x004cf3d3`.
- `NPAL7.PAL` is a UTF-16 string at `0x006152ec`; xref `0x004cf385` lands in `0x004cf300-0x004cf3d3`. Additional xrefs show the palette is shared by other panes.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed IconsPane/resource docs and does not claim a fresh string/xref pass.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now separates full and reduced strip modes, pressed-frame offsets, shared `NPAL7.PAL` ownership, rebuild packaging boundaries, and unresolved icon semantics. Completion remains capped because exact frame names, DAT provenance, raw click-action naming, and full shared-palette consumers are not fully audited here. |
| Confidence `87` | Existing IDA-backed string/xref evidence and IconsPane owner docs identify the resource names and draw behavior. Confidence is unchanged because this pass did not add fresh IDA evidence. |

## Cross-References

- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with direct IDA MCP resource string/xref evidence.
- Evidence: IDA MCP lookup of `ICONS.EPD` and `NPAL7.PAL` references in `0x004cf300-0x004cf3d3`.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page identified the icon atlas and palette but did not spell out source-owned behavior versus shared resource payloads.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:87`, with rebuild handling, shared `NPAL7.PAL` caveat, and DAT/frame-naming open questions.
  - Summary/evidence: existing `IconsPane` file/class docs tie the atlas frame math and UI behavior to `IconsPane.cpp`; resource provenance and exact icon semantics remain open.
- 2026-06-07 A002 mode-matrix pass:
  - What existed before: the page documented frame math in prose but did not separate full/reduced strip modes or pressed-frame offsets in a compact rebuild-facing form.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:87`, with runtime mode matrix, rebuild packaging boundary, shared-palette boundary, and current-session IDA availability caveat.
  - Summary/evidence: existing [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) and exact child method pages record the draw mode, hit-test, selected icon, and pressed-frame behavior.
