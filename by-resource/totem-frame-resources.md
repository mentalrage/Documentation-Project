*** UID:0001RR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Totem Frame Resources

## Status

- Confidence: strong for resource names, call site, and source/resource boundary; medium for exact frame-index semantics.
- Related file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- Related class: [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- Evidence basis: IDA MCP decompile/string checks.

## Confirmed Resources

| Resource | String address | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `TOTFRAME.EPD` | `0x0062e460` | `TotemFrame::OnPaint` | Resource-derived status/totem frame payload. Preserve the filename constant and frame-index call path in `TotemFrame.cpp`; the image bytes belong to DAT/source-asset packaging. | Totem/status frame image resource. |
| `NPAL7.PAL` | `0x006152ec` | `TotemFrame::OnPaint` | Shared old-HUD palette payload. `TotemFrame` is a consumer; do not make the palette totem-private before auditing other `NPAL7.PAL` users. | Palette passed to the tile-frame render helper. |

## Render Role Matrix

| Runtime role | Resource/input | Source behavior to preserve | Boundary notes |
| --- | --- | --- | --- |
| Totem/status frame image | `TOTFRAME.EPD` | `TotemFrame::OnPaint` loads the frame resource and renders the frame selected by old-status state. | Image frames stay in resource packaging; source owns the filename and draw call. |
| Shared old-HUD palette | `NPAL7.PAL` | `OnPaint` passes the palette into the tile-frame render helper. | Palette is shared with icon/status consumers and should not be duplicated as totem-private data. |
| Frame selector | `OldUserStatusPane::GetSpiritId` result | `OnPaint` reads `g_pOldUserStatusPane`, calls the getter, and forwards that value as the frame index. | Exact frame-id meanings remain unresolved and should be documented from the status/totem UI pass, not inferred from the EPD name alone. |
| Pane lifetime and placement | `g_pTotemFrame`, fixed pane bounds | Constructor/destructor helpers publish/clear the singleton and keep the pane at the right-side status-frame bounds. | Lifecycle and placement are source behavior; they do not imply ownership of the palette. |

## Frame Index

`TotemFrame::OnPaint` calls [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) at `0x005bdc60` through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) at `0x0069b4ec`. The returned value is passed as the `TOTFRAME.EPD` frame index. Exact frame-index meanings still need a focused status/totem UI pass.

## Source Ownership Notes

[UID:0000OV][TotemFrame](by-file/TotemFrame.md) owns the singleton pane, fixed bounds, old-status-pane lookup, and frame-index use. `TOTFRAME.EPD` and `NPAL7.PAL` remain resource payloads and should not be reconstructed as hand-authored C++ arrays.

`NPAL7.PAL` is shared with other old-HUD/status consumers, including [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md) and [UID:0001RS][user-status-resources](by-resource/user-status-resources.md). Treat the palette as a shared old-HUD palette candidate until the user-status and icon-strip consumers are reconciled.

## Scope Boundaries

- Keep `TOTFRAME.EPD` with `TotemFrame` even if later source grouping folds the small pane beside `UserStatusPane`; the resource consumer is the totem/status frame paint path.
- Keep `NPAL7.PAL` as a shared old-HUD palette candidate across `TotemFrame`, `IconsPane`, and user-status resource pages.
- Do not assign semantic names to `TOTFRAME.EPD` frames until `OldUserStatusPane::GetSpiritId` return values are mapped.
- Do not merge this page into generic frame chrome solely because the English word "frame" overlaps; current docs keep generic frame chrome, timer overlays, and totem/status frame resources separate.

## Rebuild Notes

For source reconstruction, preserve the `OldUserStatusPane::GetSpiritId` dependency as the source-level frame selector. The resource page should not assign semantic names to the frame ids until the old user-status/totem mapping is reviewed.

Final asset extraction still needs DAT/archive review for `TOTFRAME.EPD` and the shared `NPAL7.PAL` palette. If `NPAL7.PAL` is later promoted to a shared palette page, this page should remain the owner of the `TOTFRAME.EPD` consumer relationship and link to the shared palette page.

## Open Questions

- Which DAT/archive contains `TOTFRAME.EPD` and `NPAL7.PAL`?
- What exact spirit/totem values can `OldUserStatusPane::GetSpiritId` return, and how do they map to `TOTFRAME.EPD` frames?
- Should `NPAL7.PAL` be promoted to a shared old-HUD palette resource page after all consumers are audited?

## IDA MCP Evidence

- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed TotemFrame/resource docs and does not claim a fresh string/xref pass.
- ASCII `TOTFRAME.EPD` was verified at `0x0062e460`, with an xref from `0x00598e05` inside `0x00598dd0-0x00598e3b`.
- UTF-16 `NPAL7.PAL` was verified at `0x006152ec`, with an xref from `0x00598e11` inside the same totem-frame paint helper.
- IDA decompilation of `0x00598dd0-0x00598e3b` calls `sub_5BDC60((char *)dword_69B4EC)`, passes the returned value as the `TOTFRAME.EPD` frame index, then renders with palette `NPAL7.PAL`.

## Score Rationale

- Completion is `78` because the page now separates image, palette, frame-selector, and pane-lifetime responsibilities; records shared `NPAL7.PAL` and generic-frame exclusions; and preserves the unresolved status-to-frame mapping as an explicit cap.
- Confidence remains `90` because existing IDA-backed filename/xref/decompile evidence strongly supports the `TotemFrame::OnPaint` consumer path, but current DAT provenance and exact frame semantics are still open.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- What existed before: the page was scored unevaluated and cited generated `simroot_v2` in the evidence basis.
- Changed to: scored `COMPLETION:70` / `CONFIDENCE:88`, removed generated-source evidence wording, and added direct IDA MCP evidence.
- Summary and evidence: `TOTFRAME.EPD` and `NPAL7.PAL` are directly tied to `0x00598dd0`; score remains below final because the status-to-frame mapping still needs a focused UI semantics pass.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page identified the resources and frame-index call site but did not document the source/resource split or shared-palette caveat.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:90`, with rebuild handling, `NPAL7.PAL` shared-palette notes, and DAT/frame-mapping open questions.
  - Summary/evidence: `TotemFrame` file/class docs strongly establish the consumer path and source-owned frame selector; final frame semantics and asset package provenance remain open.
- 2026-06-07 render-role pass:
  - What existed before: the page documented the confirmed resources and frame-index source, but lacked a render-role matrix, scope boundaries, current-session IDA caveat, and score rationale.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:90`, with image/palette/selector/lifetime roles and explicit generic-frame/shared-palette exclusions.
  - Summary/evidence: existing TotemFrame, OldUserStatusPane, global, and resource docs support the `TOTFRAME.EPD` consumer path, shared `NPAL7.PAL` dependency, and unresolved `GetSpiritId` frame mapping.
