*** UID:0000T7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Map Tile Pixel Dimensions

## Status

- Symbol kind: process-wide map tile pixel dimension globals.
- IDA storage: `word_66DA9C` and `word_66DAA0`.
- Storage ranges: [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md) and [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md).
- Proposed source symbols: `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- Initial values in IDA data: `48` and `48`.
- Confidence: strong for storage, values, and tile-pixel role; medium for final source-level names and owner file.

## Layout

| Address | IDA symbol | Proposed source symbol | Initial value | Role |
| --- | --- | --- | --- | --- |
| `0x0066da9c` | `word_66DA9C` | `g_mapTilePixelWidth` | `48` | Horizontal map-tile pixel span and X/width centering offset. |
| `0x0066daa0` | `word_66DAA0` | `g_mapTilePixelHeight` | `48` | Vertical map-tile pixel span and Y/height centering offset. |

## Role

This pair defines the runtime pixel size of one map tile. The values are consumed by the post-login UI graph, `MapPane` setup, map coordinate helpers, item/effect image bounds helpers, and object-placement code.

The strongest reconstruction is a shared display/map-layout global pair rather than `MapPane` instance fields. They sit near the process-wide screen/layout globals [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md), and callers read them directly.

## Evidence

- IDA data inspection on 2026-05-26 reports two-byte data items at `0x0066da9c` and `0x0066daa0`, both initialized to `0x30` / `48`.
- IDA xref enumeration reports 89 data refs to `word_66DA9C` and 94 data refs to `word_66DAA0`.
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) uses the pair to build the current and legacy playfield bounds before constructing [UID:0000L3][MapPane](by-file/MapPane.md).
- `0x00504110`, the current `GameServerConfig::InitializeMapPane` attribution, sizes the backing map pane using `word_66DA9C * (tileColumns + 2)` and `word_66DAA0 * (tileRows + 2)`.
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md) multiplies one in-place map offset component by `word_66DA9C` and the other by `word_66DAA0`.
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md) and [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md) offset resolved archive rectangles by half this tile size, centering item and effect frames on the map tile midpoint.

## Naming Notes

The `ScaleDirectionOffsetToPixels` helper multiplies `xyPair[1]` by the width global and `xyPair[0]` by the height global. That does not invert the width/height naming; it indicates the helper's pair is likely stored as row/column or dy/dx rather than conventional x/y.

Do not confuse this pair with weather-layer marker globals currently named `g_tileColumns` and `g_tileRows` in generated output. Those are separate generated rows in the weather overlay area, while this page documents the fixed 48-pixel map tile dimensions at `0x0066da9c` and `0x0066daa0`.

## Wave3 Data Note

Current generated `simroot_v2` files still emit raw `global-data word_66DA9C` and `global-data word_66DAA0` rows beside consumers such as `GetItemGlyphBounds`, `GetSpriteBounds`, and `ScaleDirectionOffsetToPixels`. Treat those raw names as incomplete data ownership, not final source names.

## Cross-References

- [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md)
- [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md)
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented storage, initial values, role, xref counts, consumers, naming notes, and Wave3 raw-name caveat but remained unevaluated.
  - After: score reflects strong documentation of the process-wide tile pixel dimension globals, with remaining confidence limited mostly by final owner-file/source-symbol naming.
  - Evidence: IDA data inspection confirms two 48-valued word globals and high xref counts; linked consumers show map pane sizing, direction-offset scaling, item/effect bounds centering, and UI graph layout use.
