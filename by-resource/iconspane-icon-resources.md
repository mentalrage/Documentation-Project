*** UID:0001RD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# IconsPane Icon Resources

## Status

- Confidence: very strong for resource names, `IconsPane` usage, shared-palette status, source/resource boundary, current-package palette/EPF-variant provenance, and `ICONS.EPD` blocker classification; medium for legacy `ICONS.EPD` payload provenance and exact icon semantics.
- Related file: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Related class: [UID:00006B][IconsPane](by-class/IconsPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | String address | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `ICONS.EPD` | `0x0061b554` | `IconsPane::OnPaint` | Resource-derived old-layout icon-strip payload. Preserve the filename and frame-index math in `IconsPane.cpp`; the image bytes belong to DAT/source-asset packaging. | Contains icon frames for the old-layout icon strip. Live MCP session `80de0a67` reconfirmed the single code xref from `IconsPane::OnPaint` at `0x004cf379`. |
| `NPAL7.PAL` | `0x006152ec` | `IconsPane::OnPaint` | Shared palette payload. `IconsPane` is a consumer; do not make the palette icon-pane-private before auditing other `NPAL7.PAL` users. | Palette passed to the tile draw helper. Live MCP session `80de0a67` reconfirmed the `IconsPane::OnPaint` use at `0x004cf385` and ten total palette xrefs. |

## Package Provenance

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format and checked for loose matching files:

| Resource | Current package evidence |
| --- | --- |
| `ICONS.EPD` | Not found as a DAT entry or loose file in the audited current package. |
| `ICONS.EPF` | Present as `ICONS.EPF` in `bint2.dat`, entry index `4`, offset `7,153,461`, size `4,972`; EPF table header advertises `16` frames, matching the documented normal frames `0..7` and pressed/highlighted frames `8..15`. |
| `NPAL7.PAL` | Present in `bint2.dat`, entry index `49`, offset `9,160,879`, size `1,056`; payload begins with `DLPalette`. |

This proves the current-package icon atlas family and shared palette, but it does not prove the legacy EPD payload named by the old-mode paint path. Keep `ICONS.EPD` as the binary-referenced source operand and treat the EPF entry as current-package provenance for the same icon-strip asset family unless another distribution supplies the exact EPD variant.

2026-06-16 A002 table-only DAT scan across all audited current-package `.dat` archives reconfirmed the same exact entries with no parser errors: `ICON.EPF` in `bint2.dat` index `3`, offset `7,150,446`, size `3,015`; `ICONS.EPF` in `bint2.dat` index `4`, offset `7,153,461`, size `4,972`; and `NPAL7.PAL` in `bint2.dat` index `49`, offset `9,160,879`, size `1,056`. The first three `uint16` EPF header fields are `16,12,12` for `ICON.EPF` and `16,19,14` for `ICONS.EPF`, keeping `ICONS.EPF` as the strip-family variant and `ICON.EPF` as a separate smaller icon variant.

## Blocker Classification

2026-06-14 A002 reran the package audit with corrected start-offset DAT parsing, case-insensitive exact-name checks, loose-file search across `E:\2026\Resources`, and a narrow raw-name scan over the read-only client files. `ICONS.EPD` remains absent from every DAT entry name and from loose resources. The only exact `ICONS.EPD` occurrence outside IDA is the UTF-16 executable literal at raw offset `2,203,476` in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`.

2026-06-16 A002 repeated the exact legacy-name checks for this batch: no loose `ICONS.EPD` hit exists under `E:\2026\Resources`, the all-DAT table scan found no `ICONS.EPD` entry, and aligned UTF-16 executable scanning found `ICONS.EPD` only at raw offset `2,203,476` in each of `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`.

Treat the legacy `ICONS.EPD` blocker as a code-referenced but payload-missing old-layout operand in this audited distribution. The current package contains both `ICON.EPF` (`16` frames of `12x12`) and `ICONS.EPF` (`16` frames of `19x14`), plus shared `NPAL7.PAL`; the documented IconsPane strip continues to map to `ICONS.EPF` because its sixteen-frame atlas matches the normal/pressed frame split. This is a resource-packaging and final frame-name caveat, not a blocker for the [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) first-draft C++ body, because the code operands, frame indexes, and palette call are exact in the binary.

## Frame Semantics

`IconsPane::OnPaint` draws icons in 20-pixel slots across a 160-pixel strip. Full mode starts at icon index `0`; reduced mode starts at icon index `6`.

The selected/pressed icon uses frame `index + 8`, so frames `0..7` appear to be normal icon states and frames `8..15` appear to be pressed/highlighted states.

B003's 2026-06-19 `IconsPaneCore` recheck found a retained no-route helper at `0x004cf7a0-0x004cf7c9` that fills an icon rectangle as `{left=index*20, top=0, right=index*20+19, bottom=14}`. That confirms the same `20x14` icon-slot geometry used by paint, hit-test, and highlight invalidation, but it does not create new resource ownership or prove final icon names.

## Source Ownership Notes

`IconsPane.cpp` owns the full/reduced visibility mode, icon hit testing, selected/pressed state, tooltip text-id range, click dispatch, and the frame-index convention used against `ICONS.EPD`. The resource page should track the payload names and shared palette dependency without absorbing those UI behaviors.

`NPAL7.PAL` is also referenced by other HUD/status resource pages, including [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) and [UID:0001RS][user-status-resources](by-resource/user-status-resources.md). Treat it as a shared old-HUD palette candidate. The 2026-06-16 xref inventory accounts for all ten current xrefs: `ColorStringChattingMessage::Draw`, `ConnStatusPane::OnPaint`, `IconsPane::OnPaint`, `TotemFrame::OnPaint`, three `UserStatusPane::OnPaint` sites, and three `OldUserStatusPane::OnPaint` sites. This resolves the prior "unknown consumers" part of the palette blocker, but it does not by itself prove a separate source-owned palette declaration.

## UID0000IF ConnStatusPane Shared Consumer - 2026-08-22

- Shared UTF-16 literal `L"NPAL7.PAL"` is exact `[0x006152ec,0x00615300)` and has ten total cross-file consumers.
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) `OnPaint` is exactly one of those ten and passes the literal to `RenderTileFrame` with class-local `CONNSTAT.EPD`.
- ConnStatusPane consumes the palette expression only. Ownership, resource schema, `89/92` scores, and `CANONICAL_OWNER:NONE` remain unchanged; no emitter/reconstructable/formal metadata is added and no IDA palette action is authorized.

## Runtime Mode Matrix

| IconsPane mode | Visible icon range | Resource behavior | Source behavior |
| --- | --- | --- | --- |
| Full icon strip | Frames `0..7`, with pressed/highlighted frames `8..15` | Draws `ICONS.EPD` with `NPAL7.PAL` across the 160-pixel strip. | Starts at icon index `0`, advances in 20-pixel slots, and uses `index + 8` when the selected icon is pressed. |
| Reduced icon strip | Frames `6..7`, with pressed/highlighted frames `14..15` | Uses the same `ICONS.EPD` atlas and `NPAL7.PAL` palette. | Starts hit-testing/painting at icon index `6`; option UI toggles persist the full/reduced mode. |

## Rebuild Packaging Boundary

- Package `ICONS.EPD` as the old-layout icon atlas and keep `NPAL7.PAL` available as a shared old-HUD palette.
- Preserve the source-level full/reduced mode, hit-test math, tooltip id range, action dispatch, and pressed-frame offset in [UID:0000JZ][IconsPane](by-file/IconsPane.md).
- Keep exact icon semantics and click-action names in the IconsPane class/memory docs rather than encoding them as resource-page conclusions before the raw action dispatch is fully named.
- Do not split `NPAL7.PAL` into IconsPane-private data. If a shared palette page is later created, this page should remain the owner of the `ICONS.EPD` / IconsPane consumer relationship and link to that shared-palette page.

## Rebuild Notes

For source reconstruction, keep the icon atlas behavior in `IconsPane::OnPaint`: full mode starts at frame `0`, reduced mode starts at frame `6`, and pressed/highlighted icons draw `index + 8`. The EPD bytes and palette contents remain resource packaging work.

B004's 2026-06-25 implementation pass confirms that the missing exact `ICONS.EPD` payload does not require leaving `IconsPane::OnPaint` C++ blank. The source method should call `g_pEPFLib->LookupLayoutEntry(L"ICONS.EPD", frameIndex, &tileContext)` and render with `L"NPAL7.PAL"`; packaging still needs the correct asset payload or compatibility alias.

Avoid merging this page with `TabPane` or option-dialog docs. The open grouping question in the class/file pages concerns source adjacency and shared helper tails, not ownership of `ICONS.EPD`.

## Open Questions

- Find a distribution or loose-resource source for `ICONS.EPD`; the current package contains `ICONS.EPF` and shared `NPAL7.PAL` in `bint2.dat`, but not the legacy EPD operand.
- What are the final semantic names for frames `0..7` and pressed frames `8..15` after click-action helper naming is finished?
- Whether `NPAL7.PAL` should be promoted to a separate shared old-HUD palette page is now a documentation-organization question rather than an unknown-consumer blocker; current xrefs cover six consumer functions and ten ref sites, but no source-owned palette declaration is proven.

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms `ICONS.EPD` has one observed code xref inside `sub_4CF300` / `IconsPane::OnPaint`.
- `ICONS.EPD` is a UTF-16 string at `0x0061b554`; xref `0x004cf379` lands in `0x004cf300-0x004cf3d3`.
- `NPAL7.PAL` is a UTF-16 string at `0x006152ec`; xref `0x004cf385` lands in `0x004cf300-0x004cf3d3`.
- The same IDA refresh finds ten total `NPAL7.PAL` xrefs, including `sub_4836A0`, `sub_494620`, `sub_598DD0`, `sub_5B8C70`, and `sub_5BE520`, confirming this page is a consumer record for a shared old-HUD palette rather than a palette owner page.
- 2026-06-16 A002 live MCP refresh on database `b001_selflookpane_0001H7_20260616` reconfirmed `sub_4CF300` at `0x004cf300` size `0xd3`, one `ICONS.EPD` xref at `0x004cf379`, and ten `NPAL7.PAL` xrefs. Decompilation shows the full/reduced loop starts at icon index `0` or `6`, uses `index + 8` for pressed frames, calls the resource loader with `off_61B554`, and draws with palette `off_6152EC`.
- 2026-06-25 B004 live MCP session `80de0a67` reconfirmed the same `IconsPane::OnPaint` resource evidence: one `ICONS.EPD` code data xref at `0x004cf379`, `NPAL7.PAL` passed at `0x004cf385`, ten total `NPAL7.PAL` xrefs, and helper calls that map the operands to `g_pEPFLib->LookupLayoutEntry` and `RenderTileFrame`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `89` | The page separates full and reduced strip modes, pressed-frame offsets, shared `NPAL7.PAL` ownership, rebuild packaging boundaries, and unresolved icon semantics; records refreshed single-consumer atlas evidence; documents current-package `ICON.EPF`, `ICONS.EPF`, and `NPAL7.PAL` entries with header, size, offset, and palette signature evidence; classifies `ICONS.EPD` as a code-literal-only legacy blocker; and now accounts for the complete ten-ref shared-palette consumer set. Completion remains capped because exact `ICONS.EPD` payload provenance, final frame names, raw click-action naming, and a possible standalone palette-family page are not final. |
| Confidence `92` | Fresh 2026-06-16 IDA xrefs and decompilation reconfirm `ICONS.EPD` routes to `IconsPane::OnPaint`, `NPAL7.PAL` is shared outside this pane, and the draw loop uses the documented index and pressed-frame math. DAT parsing confirms the current icon atlas family has sixteen frames and the palette exists in `bint2.dat`, while repeated all-DAT/loose/executable scans strengthen the negative `ICONS.EPD` provenance. Confidence stays below final because the exact legacy payload is still absent and icon names/actions still require broader review. |

## Cross-References

- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- 2026-08-22 B003 UID0000IF support callback: preserved the resource schema and `89/92`; made the existing ConnStatusPane member of the ten-xref `NPAL7.PAL` inventory explicit without changing shared ownership.

- 2026-06-25 B004 OnPaint support sync:
  - Score unchanged at `89/92`.
  - Summary/evidence: live MCP session `80de0a67` reconfirmed `ICONS.EPD` at `0x0061b554` with the single `IconsPane::OnPaint` xref `0x004cf379`, `NPAL7.PAL` at `0x006152ec` with the `IconsPane::OnPaint` use `0x004cf385`, and ten total palette xrefs. The absent exact `ICONS.EPD` payload remains a resource-packaging/frame-name caveat, not a blocker for first-draft code in [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md).
- 2026-06-19 B003 IconsPaneCore support sync:
  - No score/owner change.
  - Summary/evidence: added the no-route `0x004cf7a0-0x004cf7c9` icon-rectangle helper as geometry support for the existing 20-pixel slot and 14-pixel icon-height notes. Resource ownership remains unchanged; `IconsPane.cpp` owns UI behavior and this page tracks the payload/palette boundary.
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
- 2026-06-14 A003 score refresh: Raised completion/confidence from `78/87` to `85/89` after live IDA MCP xrefs confirmed `ICONS.EPD` routes to `sub_4CF300` / `IconsPane::OnPaint` and `NPAL7.PAL` has ten observed consumers; DAT provenance, exact icon semantics, click-action naming, and complete shared-palette routing remain below-gate blockers.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:85` / `CONFIDENCE:89` with DAT provenance still open.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:90`.
  - Evidence: current DAT table parsing found `ICONS.EPF` and `NPAL7.PAL` in `bint2.dat`; the EPF header advertises `16` frames and the palette payload begins with `DLPalette`. No `ICONS.EPD` DAT entry or loose file was found, so the legacy paint operand remains the main payload blocker. `CANONICAL_OWNER:NONE` remains unchanged per batch owner-preservation guidance.
- 2026-06-14 A002 blocker provenance pass:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, with `ICONS.EPD` only known as absent from the first current-package audit.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:91`, after corrected DAT start-offset parsing, case-insensitive exact-name checks, loose-resource search, and raw client scan confirmed `ICONS.EPD` is present only as a UTF-16 executable literal at raw offset `2,203,476` in the packaged executables, not as a current DAT or loose payload. The same archive pass also records nearby `ICON.EPF` as a separate `16`-frame `12x12` entry, keeping `ICONS.EPF` as the strip-family variant for this page.
- 2026-06-16 A002 resource-provenance refresh:
  - Before: `COMPLETION:87`, `CONFIDENCE:91`, with shared `NPAL7.PAL` still described as not fully audited.
  - After: raised to `COMPLETION:89`, `CONFIDENCE:92`.
  - Evidence: live MCP on `b001_selflookpane_0001H7_20260616` reconfirmed `IconsPane::OnPaint` bounds, `ICONS.EPD` and `NPAL7.PAL` xrefs, and the frame-index loop; table-only package scanning reconfirmed `ICON.EPF`, `ICONS.EPF`, and `NPAL7.PAL`; executable/loose scans reconfirmed `ICONS.EPD` as literal-only; and the full ten-ref `NPAL7.PAL` consumer set is now enumerated.
