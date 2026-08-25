*** UID:0000T7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short g_mapTilePixelWidth = 48;
short g_mapTilePixelHeight = 48;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern short g_mapTilePixelWidth;
extern short g_mapTilePixelHeight;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Map Tile Pixel Dimensions

## Status

- Symbol kind: process-wide map tile pixel dimension globals.
- IDA storage: `word_66DA9C` and `word_66DAA0`.
- Storage ranges: [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md) and [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md).
- Proposed source symbols: `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- Initial values in IDA data: `48` and `48`.
- Confidence: strong for storage, values, tile-pixel role, and `MapPane` source ownership; medium-high for final source-level type/spelling.

## Layout

| Address | IDA symbol | Proposed source symbol | Initial value | Role |
| --- | --- | --- | --- | --- |
| `0x0066da9c` | `word_66DA9C` | `g_mapTilePixelWidth` | `48` | Horizontal map-tile pixel span and X/width centering offset. |
| `0x0066daa0` | `word_66DAA0` | `g_mapTilePixelHeight` | `48` | Vertical map-tile pixel span and Y/height centering offset. |

## Role

This pair defines the runtime pixel size of one map tile. The values are consumed by the post-login UI graph, `MapPane` setup, map coordinate helpers, item/effect image bounds helpers, and object-placement code.

[UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) is an exact cross-translation-unit consumer. It uses width as the lighting pane's horizontal local offset and height in `height / 2 - height * lightHeightClass`. Because both ObjectList and MapPane-owned code consume the same pair, the source definitions require external linkage and the H channel must expose matching `extern short` declarations; file-local `static` definitions would not satisfy the observed source route.

The strongest reconstruction is a shared display/map-layout global pair rather than `MapPane` instance fields. They sit near the process-wide screen/layout globals [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md), and callers read them directly.

## Evidence

- IDA data inspection on 2026-05-26 reports two-byte data items at `0x0066da9c` and `0x0066daa0`, both initialized to `0x30` / `48`.
- IDA xref enumeration reports 89 data refs to `word_66DA9C` and 94 data refs to `word_66DAA0`.
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) uses the pair to build the current and legacy playfield bounds before constructing [UID:0000L3][MapPane](by-file/MapPane.md).
- `0x00504110`, the current `GameServerConfig::InitializeMapPane` attribution, sizes the backing map pane using `word_66DA9C * (tileColumns + 2)` and `word_66DAA0 * (tileRows + 2)`.
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md) multiplies one in-place map offset component by `word_66DA9C` and the other by `word_66DAA0`.
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) and [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md) offset resolved archive rectangles by half this tile size, centering item and effect frames on the map tile midpoint.
- [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) uses the same pair in both roles: `ScaleDirectionOffsetToPixels` multiplies pair element 1 by `g_mapTilePixelWidth` and element 0 by `g_mapTilePixelHeight`, then the method adds half the width to cached screen X and half the height to cached screen Y after movement interpolation.
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) consumes both globals outside the MapPane implementation route, proving the pair cannot remain source-file-local `static` storage.
- 2026-06-07 live IDA MCP recheck reconfirmed `word_66DA9C` and `word_66DAA0` as two-byte data items whose word value is `0x0030` / `48`. Reading the surrounding bytes from each address gives `30 00 00 00`, but the exact children remain [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md) and [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md); the non-child bytes are documented by the intervening padding/neighboring memory pages.
- B002's 2026-06-18 [UID:00027I][0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland](by-memory/0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md) reanalysis confirms the two bytes at `0x0066daa2-0x0066daa4` after `g_mapTilePixelHeight` are [UID:0003ZK][0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding](by-memory/0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding.md), not part of the height global. The following legacy asset remap constants must not be folded into the tile-dimension global pair.
- The same recheck counted 89 xrefs to `word_66DA9C` and 94 xrefs to `word_66DAA0`. Repeated consumer groups include `0x004db5c0`, `0x004e31f0`, `0x0050bce0`, and `0x00549620` for both dimensions, plus map/UI helper groups such as `0x00468800`, `0x004de2a0`, `0x004f7d10`, `0x005059d0`, `0x00507150`, and `0x0055a990`.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000L3][MapPane](by-file/MapPane.md). The direct ownership evidence points to the MapPane coordinate/movement helper surface rather than the UI bootstrap or a standalone global file:

- [UID:0000L3][MapPane](by-file/MapPane.md) now clears `89/85` and explicitly groups tile dimensions with MapPane coordinate conversion, movement scaling, viewport conversion, object placement, and related map-layout globals.
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) now clears `86/86`, but its use of this pair is bootstrapping the current and legacy playfield bounds before constructing [UID:0000L3][MapPane](by-file/MapPane.md). It is a consumer, not the declaration owner.
- A standalone `MapMovementGlobals.cpp`, `MapMovementConfig.cpp`, or generic layout-globals file remains rejected. Current evidence shows no writer, initializer function, source-tree entry, or isolated source-owned data island; the meaningful adjacent/global overlap is with the MapPane coordinate surface.

The strict gate clears:

| Item | Completion | Confidence | Gate result |
| --- | ---: | ---: | --- |
| `MapTilePixelDimensions` child | 90 | 91 | clears child `85/85` |
| [UID:0000L3][MapPane](by-file/MapPane.md) direct source-file parent | 89 | 85 | clears parent `85/85` |

This page is now a rooted by-global parent for the exact by-memory storage children [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md) and [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md). The by-memory children can attach here because their direct semantic parent is the source-level global pair, and this by-global page now routes upward to the validated MapPane source root.

## Naming Notes

The `ScaleDirectionOffsetToPixels` helper multiplies `xyPair[1]` by the width global and `xyPair[0]` by the height global. That does not invert the width/height naming; it indicates the helper's pair is likely stored as row/column or dy/dx rather than conventional x/y.

[UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) reinforces this caveat. Its source-facing C++ may name the width-scaled element `.x` and height-scaled element `.y`, but the binary pair storage order remains observed as element 0 row/Y-like and element 1 column/X-like.

Do not confuse this pair with weather-layer marker globals currently named `g_tileColumns` and `g_tileRows` in analysis aliases. Those are separate rows in the weather overlay area, while this page documents the fixed 48-pixel map tile dimensions at `0x0066da9c` and `0x0066daa0`.

## Data Note

Current raw aliases still expose `word_66DA9C` and `word_66DAA0` beside consumers such as `GetItemGlyphBounds`, `GetSpriteBounds`, and `ScaleDirectionOffsetToPixels`. Treat those raw names as incomplete data ownership, not final source names.

## Cross-References

- [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md)
- [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md)
- [UID:0003ZK][0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding](by-memory/0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding.md)
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md)

## Changes

- 2026-08-11 B003 UID00023D support synchronization: preserved `91/92`, owner/emitter `0000L3`, reconstructable true, and blank position. Removed file-local `static` from the two CPP definitions, added exact H `extern short` declarations, and recorded the ObjectList cross-translation-unit consumer that requires external linkage.
- 2026-06-29 Agent-B004 MapPane empty-emitter callback:
  - Raised score to `91/92` and inserted the accepted signed-short declarations for `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
  - Evidence: current MCP `241`/`242` reconfirmed `word_66DA9C == 48` and `word_66DAA0 == 48`; `analyze_function`/`decompile` on `0x00505100` showed sign-extending word reads by the coordinate scaler, and the width/height exact storage children now carry covered-by comments to this by-global page.
  - Source caveat preserved: the pair-order note still applies because `ScaleDirectionOffsetToPixels` stores row/Y-like data in element `0` and column/X-like data in element `1`; this does not reverse the global names.
- 2026-06-21 Rule 26 support sync from B008 [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md):
  - Added target-specific width/height usage: width scales pair element 1 and contributes half-tile X, height scales pair element 0 and contributes half-tile Y.
  - Preserved the coordinate-pair storage order caveat while allowing source-facing `.x/.y` names in draft C++.
- 2026-06-18 B002 Rule 26 incorporation for [UID:00027I][0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland](by-memory/0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md):
  - Added boundary evidence that `0x0066daa2-0x0066daa4` is trailing padding after `g_mapTilePixelHeight`, and that the following remap constants are separate from the tile-dimension pair.
- 2026-06-11 A001 strict-gate assignment:
  - What existed before: the page was `88/90`, reconstructable, and intentionally unassigned because older MapPane/MainUiGraph parent scores did not clear `85/85`.
  - Changed to: `COMPLETION:90`, `CONFIDENCE:91`, and `AUTOGEN_PARENT_UID:0000L3`.
  - Summary/evidence: live IDA MCP rechecked both data items as two-byte `48` globals with 89/94 xrefs and no write-like refs; [UID:0000L3][MapPane](by-file/MapPane.md) is now `89/85` and documents the tile dimensions as part of the MapPane coordinate/movement helper surface. [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) is a bootstrap consumer, while standalone global/config file candidates remain unsupported. The exact width/height memory children can now route through this by-global parent.

- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented storage, initial values, role, xref counts, consumers, naming notes, and raw-name caveat but remained unevaluated.
  - After: score reflects strong documentation of the process-wide tile pixel dimension globals, with remaining confidence limited mostly by final owner-file/source-symbol naming.
  - Evidence: IDA data inspection confirms two 48-valued word globals and high xref counts; linked consumers show map pane sizing, direction-offset scaling, item/effect bounds centering, and UI graph layout use.
- 2026-06-05: Marked reconstructable and left parent attachment blank.
  - Reason: live IDA MCP recheck confirms the two source-declared 48-pixel tile-dimension globals and broad map/render/UI consumers, but final owner-file placement is still not strong enough to attach to a single source root.
- 2026-06-07: Grading changed from `86/90` to `88/90`.
  - Before: page had strong storage/value and role evidence but did not record a fresh grouped xref recheck or the corrected parent-score gate.
  - After: score reflects live revalidation of both initialized 48-valued globals, high xref counts, repeated consumer groups, and explicit no-parent rationale under the corrected assignment rule.
- 2026-06-07 A005 Batch 028:
  - Corrected the evidence wording from four-byte data items to exact two-byte data items with surrounding non-child bytes visible in the local read.
  - Clarified that this by-global page may directly parent the exact width/height by-memory children even though the by-global page itself remains unattached to a file-level owner.
- 2026-06-07 Batch073:
  - Clarified that this page is the canonical by-global cross-reference for the width/height storage children but is not a valid autogen root while it has no file-level parent.
  - Evidence: generated memory coverage reported `autogen_parent_unknown` for the height child when it used this unattached by-global UID as `AUTOGEN_PARENT_UID`; no direct file owner for the global pair currently clears the corrected `85/85` gate.
