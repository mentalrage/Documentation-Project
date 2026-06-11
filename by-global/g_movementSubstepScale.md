*** UID:0002CF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_movementSubstepScale

## Status

- Symbol kind: process-wide movement interpolation scale byte.
- IDA address: `0x0066da96` (`byte_66DA96`).
- Storage range: [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md).
- Source owner: [UID:0000L3][MapPane](by-file/MapPane.md), specifically the MapPane coordinate/movement helper surface.
- Proposed type: `std::uint8_t` or `unsigned char`.
- Initial value in IDA data: `1`.
- Confidence: strong for storage, initial value, movement/interpolation role, separation from neighboring globals, and MapPane coordinate/movement ownership; medium for final source-level spelling.

## Role

`g_movementSubstepScale` controls the fine-grained movement and animation substep scale used by map-object, attached-object, and local-player movement paths. With the initial value `1`, a tile-direction vector is divided into four substeps. The same value is used to divide timer delays so higher values would create more substeps at shorter intervals rather than simply slowing movement.

The name is descriptive, not recovered original source evidence. Keep the IDA alias `byte_66DA96` in notes until startup/config writes are fully reviewed.

## Evidence

- IDA data inspection reports a one-byte item at `0x0066da96` with initial value `1` and 23 xrefs.
- [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md) records the exact one-byte range, image neighborhood `01 01 00 03`, and separation from [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md). It is assigned to [UID:0000L3][MapPane](by-file/MapPane.md) along with this semantic global, avoiding unsupported by-global memory parenting.
- `BalloonObjectPane::UpdatePositionForDirection` at `0x00468520` divides directional offsets by `4 * byte_66DA96`, matching the map/object and player movement interpretation.
- Map and attached-object position helpers divide direction vectors by `4 * byte_66DA96`, including `MapPane` object-position helpers at `0x005055e0`, `0x00506980`, and `0x0050b080`, attached-object helpers at `0x00538600`, `0x005386c0`, `0x0053c700`, and `0x0053c810`, and `LivingObjectPane::UpdateScreenPosition` at `0x005a88d0`.
- Local-player movement timer setup divides frame delays by `byte_66DA96` at `0x005a36f0`, `0x005a3770`, and `0x005ab410`.
- `UserPane::OnAnimationStep` at `0x005a83b0` uses `4 * byte_66DA96` as the movement subframe modulus and also divides movement timer delays by the same byte.
- 2026-06-07 A004 IDA MCP `py_eval` reconfirmed bytes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00` at `0x0066da90-0x0066daa8`, `byte_66DA96` item size `1`, value `1`, `23` xrefs across `14` functions, and strict boundaries between [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).
- 2026-06-08 B001 follow-up found exactly 23 direct instruction hits to `0x0066da96`, all reads, and no direct store/initializer encodings. The reader set is MapPane-coordinate shaped: MapPane helpers `0x005055e0`, `0x00506980`, and `0x0050b080` divide tile/object offsets by `4 * byte_66DA96`, while local-player/UserPane movement paths call back through MapPane helpers such as `0x00505080`, `0x00505100`, `0x00505130`, `0x005055e0`, `0x005058b0`, `0x005059d0`, and `0x00506980`.
- B001's nearby-global matrix found no function overlap with the folder buffer, `g_fpsDebugActive`, `g_screenWidth`, `g_useEpfAssets`, or `g_screenHeight`; the only meaningful adjacent-global overlap is with [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) in five coordinate/placement functions. That supports MapPane coordinate ownership rather than a broad initialized-data island.

## Ownership Notes

This global is a shared MapPane coordinate/movement scalar rather than part of the screen width/height pair. It sits between [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) in `.data`, but xrefs tie it to movement interpolation, attached-object placement, player animation timing, and most importantly MapPane direction/tile/viewport conversion helpers.

The executed ownership inference assigns this page to [UID:0000L3][MapPane](by-file/MapPane.md). The decisive evidence is not a writer, because no writer or debug-source metadata has been recovered; it is the coherent read surface. Every direct read is movement/placement related, the core readers are MapPane coordinate helpers, and the higher-level actor/user consumers route through the MapPane direction-coordinate API.

Do not create or assign this page to `MapMovementGlobals.cpp`, `MapMovementConfig.cpp`, `UserPane`, `LivingObjectPane`, `AttachedObjectPane`, or `AttachmentAnchorResolver` from current evidence. Those pages are consumers, partial users, or unsupported hypotheses. A smaller MapPane-owned coordinate/movement helper grouping may be useful later, but it should still resolve to `NexusTK/map/MapPane.cpp`.

The exact storage child [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md) is assigned to [UID:0000L3][MapPane](by-file/MapPane.md) directly rather than to this by-global page, because generated memory coverage does not support by-global parents. This page remains the semantic global documentation for that byte.

## Score Rationale

- Completion is raised to 89 because the page now documents exact storage, initial value, xref count, 14-function spread, read-only instruction evidence, neighboring global boundaries, movement/vector divisor behavior, timer-delay divisor behavior, exact memory-child evidence, the by-global parenting limitation, and the executed MapPane source-owner inference.
- Confidence is raised to 90 because IDA confirms the storage and movement/timer-scale role, and B001's follow-up ties the reader set to MapPane coordinate helpers with no stronger competing owner. Confidence remains below final-source quality because the original variable spelling and declaration syntax are not recovered from debug/source metadata.

## Cross-References

- [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md)
- [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md)
- [UID:0002QL][0x005058b0-0x0050593e.MapPaneScrollViewportByDirection](by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md)
- [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md)
- [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)

## Changes

- 2026-06-08 B001/supervisor ownership execution:
  - Before: score `87/89`, `AUTOGEN_PARENT_UID:` blank, source owner unresolved.
  - Changed to: score `89/90`, `AUTOGEN_PARENT_UID:0000L3`.
  - Evidence: B001's continued IDA MCP research found exactly 23 direct read refs and no direct write/initializer encodings; MapPane helpers `0x005055e0`, `0x00506980`, and `0x0050b080` use `4 * byte_66DA96` with tile/object offsets; local-player/UserPane movement readers call back through MapPane coordinate helpers; the only meaningful adjacent-global overlap is with MapTilePixelDimensions. The page now rejects standalone `MapMovementGlobals.cpp`/`MapMovementConfig.cpp` and consumer owners, and assigns the semantic global to MapPane coordinate/movement support.
- Completion/confidence scoring: existed before as `75/82` and was not changed in this pass.
- 2026-06-05: Marked reconstructable and intentionally left unassigned. Evidence: live IDA MCP reports 23 xrefs to `0x0066da96`; decompilation confirms `0x005055e0` divides map-object vectors by `4 * byte_66DA96`, `0x005a36f0` divides movement timer delay by `byte_66DA96`, and `0x005a83b0` uses the same byte for movement subframe modulus and timer scheduling. The byte is recoverable, but source ownership is still shared across map, actor, and local-player movement code.
- 2026-06-06: Raised to `80/84` after adding exact memory-range/neighborhood evidence, BalloonObjectPane coverage, neighboring global separation, and explicit rationale for leaving the parent blank. C++ remains blank because final source owner/name are still unresolved.
- 2026-06-07 A008 alias cleanup:
  - Normalized neighboring-data references to canonical [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) links.
- 2026-06-07 A004 Batch 027:
  - Before: score `80/84`, below the corrected assignment gate.
  - Changed to: score `86/88`, added fresh IDA MCP neighborhood/xref/function-spread evidence, and recorded [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md) as the exact assigned memory child.
  - Boundary: this by-global page remains unassigned upward because final source-file owner, original declaration spelling, writer/config path, and emitted declaration are still open.
- 2026-06-07 A008 Batch 075 generated-coverage repair:
  - Before: this page described [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md) as assigned here through `AUTOGEN_PARENT_UID:0002CF`.
  - After: scores remain `86/88`, and the memory child is documented as exact storage evidence but not an autogen child because generated memory coverage rejects by-global parents with `autogen_parent_unknown`.
- 2026-06-08 A005 Batch 110:
  - Before: score `86/88`, `AUTOGEN_PARENT_UID:` blank.
  - Changed to: score `87/89`, parent remains blank.
  - Summary/evidence: live IDA MCP reconfirmed exact initialized bytes, one-byte storage, and all 23 movement/timer xrefs. No assignment was made because no direct source-file owner is proven, and routing through the exact by-memory child or unsupported by-global memory parenting would violate the corrected direct-parent gate.
