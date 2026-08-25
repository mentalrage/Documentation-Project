*** UID:0001RR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Totem Frame Resources

## Status

- Confidence: strong for resource names, call site, source/resource boundary, and shared-palette exclusion; medium for exact frame-index semantics and DAT provenance.
- Related file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- Related class: [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- Exact resource filename child: [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md); `0x0062e47c` is the corrected TransferServerDialogPane successor COL boundary.
- Evidence basis: IDA MCP decompile/string/xref checks.

## Confirmed Resources

| Resource | String address | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `TOTFRAME.EPD` | `0x0062e460` | `TotemFrame::OnPaint` | Resource-derived status/totem frame payload. Preserve the filename constant and frame-index call path through [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md); the image bytes belong to DAT/source-asset packaging. | Exact UTF-16 literal ends at `0x0062e47c`; no Totem trailing alignment follows it. |
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

The source literal at [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md) is routed to [UID:0000F4][TotemFrame](by-class/TotemFrame.md), not this resource page, because validator autogen source ownership should follow the class-local `OnPaint` operand. This page remains the resource-level evidence and packaging contract for `TOTFRAME.EPD`.

## Scope Boundaries

- Keep `TOTFRAME.EPD` with `TotemFrame` even if later source grouping folds the small pane beside `UserStatusPane`; the resource consumer is the totem/status frame paint path.
- Keep `NPAL7.PAL` as a shared old-HUD palette candidate across `TotemFrame`, `IconsPane`, and user-status resource pages.
- Do not assign semantic names to `TOTFRAME.EPD` frames until `OldUserStatusPane::GetSpiritId` return values are mapped.
- Do not merge this page into generic frame chrome solely because the English word "frame" overlaps; current docs keep generic frame chrome, timer overlays, and totem/status frame resources separate.

## Rebuild Notes

For source reconstruction, preserve the `OldUserStatusPane::GetSpiritId` dependency as the source-level frame selector. The resource page should not assign semantic names to the frame ids until the old user-status/totem mapping is reviewed.

Final asset extraction still needs DAT/archive review for `TOTFRAME.EPD` and the shared `NPAL7.PAL` palette. If `NPAL7.PAL` is later promoted to a shared palette page, this page should remain the owner of the `TOTFRAME.EPD` consumer relationship and link to the shared palette page.

B005's 2026-06-19 [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md) source-quality pass validates that unresolved DAT/archive provenance and exact spirit-to-frame mapping do not block first-draft `TotemFrame::OnPaint` C++. The source method should preserve `OldUserStatusPane::GetSpiritId()` as the frame selector for `TOTFRAME.EPD` and pass shared `NPAL7.PAL` to the render helper. The remaining resource questions stay here as resource-semantic follow-ups, not executable-range owner/emitter blockers.

## Open Questions

- Which DAT/archive contains `TOTFRAME.EPD` and `NPAL7.PAL`?
- What exact spirit/totem values can `OldUserStatusPane::GetSpiritId` return, and how do they map to `TOTFRAME.EPD` frames?
- Should `NPAL7.PAL` be promoted to a shared old-HUD palette resource page after all consumers are audited?

## IDA MCP Evidence

- 2026-06-14 A003 live IDA MCP session `a001_goal2_class_batch` targeted `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- UTF-16 `TOTFRAME.EPD` was verified at `0x0062e460`, with an xref from `0x00598e05` inside `0x00598dd0-0x00598e3b`.
- UTF-16 `NPAL7.PAL` was verified at `0x006152ec`, with an xref from `0x00598e11` inside the same totem-frame paint helper.
- IDA decompilation of `0x00598dd0-0x00598e3b` calls `sub_5BDC60((char *)dword_69B4EC)`, passes the returned value as the `TOTFRAME.EPD` frame index, then renders with palette `NPAL7.PAL`.
- 2026-06-12 A003 live IDA MCP session `a001-b276` reconfirmed IDA name `aTotframeEpd` at `0x0062e460`, disassembly rendered `text "UTF-16LE", 'TOTFRAME.EPD',0`, and `xrefs_to 0x0062e460` returned exactly one data xref at `0x00598e05` in `TotemFrame::OnPaint`.
- 2026-06-12 `xrefs_to 0x006152ec` returned ten palette refs including `0x00598e11`, confirming `NPAL7.PAL` is a shared old-HUD/status palette and should not be owned by TotemFrame alone.
- 2026-06-12 `xrefs_to 0x0062e480` returned only successor `TransferServerDialogPane` refs, confirming the exact `TOTFRAME.EPD` string child ends before the transfer-server read-only-data island.
- 2026-06-14 `lookup_funcs` reconfirmed the constructor start `0x00598cc0` size `0xde` / 222 bytes, paint helper `0x00598dd0` size `0x6b` / 107 bytes, and `OldUserStatusPane::GetSpiritId` helper `0x005bdc60` size `0x8` / 8 bytes (Verified with `int_convert.py`).
- 2026-06-14 `analyze_function 0x00598dd0` reconfirmed `TotemFrame::OnPaint` as a one-block paint path: initialize a tile context, read `g_pOldUserStatusPane`, call `0x005bdc60`, load `L"TOTFRAME.EPD"` through the EPF/resource helper, then draw using the pane rectangle at `this+0x44` / 68 bytes and palette `NPAL7.PAL` (Verified with `int_convert.py`).
- 2026-06-14 `analyze_function 0x005bdc60` reconfirmed the frame selector is a tiny getter returning `this[0x13e]` / byte offset 318 from `OldUserStatusPane` (Verified with `int_convert.py`), with `TotemFrame::OnPaint` as its current caller.
- 2026-06-14 `xrefs_to` reconfirmed exactly one `TOTFRAME.EPD` xref at `0x00598e05`, ten `NPAL7.PAL` refs with the TotemFrame hit at `0x00598e11`, and nine `g_pOldUserStatusPane` refs with the TotemFrame paint read at `0x00598dec`.
- 2026-06-14 `get_bytes` with MCP `regions` decoded `0x0062e460` as UTF-16 `TOTFRAME.EPD` followed by successor table data, and decoded `0x006152ec` as UTF-16 `NPAL7.PAL` followed by the adjacent `CHATSC...` string cluster; this keeps `TOTFRAME.EPD` exact but excludes neighboring data from this resource page.

## Score Rationale

- Completion is `87` because the page now separates image, palette, frame-selector, pane-lifetime, exact source-literal child, autogen-parent boundary, shared `NPAL7.PAL` exclusion, successor-range boundary responsibilities, current MCP function bounds, raw byte identity, exact xref counts, and the `OldUserStatusPane` getter offset while preserving unresolved DAT/frame mapping as explicit open questions.
- Confidence is `92` because current IDA-backed bytes, xrefs, function summaries, and linked owner docs all agree on the `TotemFrame::OnPaint` consumer path and direct source-literal owner. Confidence stays below final audit because DAT provenance, exact frame-id semantics, and shared-palette packaging remain open.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md)
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
- 2026-06-12 A003 Batch 295:
  - Before: `COMPLETION:78`, `CONFIDENCE:90`, and the exact source-literal child was still parentless.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:91`; added exact UID0003E4, now boundary-corrected at [0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md), and documented why it routes to [UID:0000F4][TotemFrame](by-class/TotemFrame.md) rather than to this resource page.
  - Summary/evidence: live IDA MCP reconfirmed the sole `TOTFRAME.EPD` xref from `TotemFrame::OnPaint`, the decompiled frame-index path through `OldUserStatusPane::GetSpiritId`, the shared `NPAL7.PAL` xref fanout, and the `TransferServerDialogPane` successor boundary.
- 2026-06-14 A003 Goal 2 refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:91`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:92`.
  - Summary/evidence: live IDA MCP reconfirmed current worker health, `TotemFrame` constructor/paint/getter function bounds, the one-block `OnPaint` resource path, `GetSpiritId` byte-offset read, exact `TOTFRAME.EPD` and `NPAL7.PAL` byte strings, single `TOTFRAME.EPD` xref, ten-ref shared-palette fanout, and the `g_pOldUserStatusPane` paint read. DAT provenance, frame-id meanings, and shared palette packaging remain open.
- 2026-06-19 B005 source-quality execution:
  - Score unchanged at `87/92`.
  - Added the explicit conclusion that DAT/archive provenance and frame-id semantics cap resource finality but do not block first-draft `TotemFrame::OnPaint` source on [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md).
  - Summary/evidence: B005 rechecked current resource/class/file/global docs, generated report leads, cached function/vtable evidence, and local PE bytes after IDA MCP was unavailable for that pass.
