*** UID:0002CF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static char g_movementSubstepScale = 1;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_movementSubstepScale

## Status

- Symbol kind: process-wide movement interpolation scale byte.
- IDA address: `0x0066da96` (`byte_66DA96`).
- Storage range: [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md).
- Source owner: [UID:0000L3][MapPane](by-file/MapPane.md), specifically the MapPane coordinate/movement helper surface.
- Current source type: plain `char`. Every direct reader sign-extends the byte, and plain signed-by-default `char` is the strongest MSVC-era source form. Explicit `signed char` is the behavior-equivalent runner-up; `unsigned char` and `std::uint8_t` are rejected because they imply unsigned promotion/zero-extension.
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
- B004's 2026-07-15 bounded signedness audit re-read all 23 direct instructions across all 14 reader functions. Every load is `movsx`; no reader uses `movzx`, an unsigned load, or an unsigned conversion. Exact refs are `0x00468577/0x00468644`, `0x005055f7`, `0x00506a1e`, `0x0050b0f5/0x0050b11c`, `0x0053864f`, `0x00538744/0x0053875d`, `0x00539b6f`, `0x0053c773/0x0053c78f`, `0x0053c895`, `0x005a3725`, `0x005a3836`, `0x005a840e/0x005a846b/0x005a84cc/0x005a85fe/0x005a865b/0x005a86bc`, `0x005a8923`, and `0x005ab554`.
- B001's nearby-global matrix found no function overlap with the folder buffer, `g_fpsDebugActive`, `g_screenWidth`, `g_useEpfAssets`, or `g_screenHeight`; the only meaningful adjacent-global overlap is with [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) in five coordinate/placement functions. That supports MapPane coordinate ownership rather than a broad initialized-data island.

## Rule 26 Ownership Audit Detail

B001's older ownership report was rechecked claim-by-claim for this retry. The valid direct xref inventory is:

| Function start | Direct refs | Current documentation lead | Role confirmed from IDA |
| --- | --- | --- | --- |
| `0x00468520` | `0x00468577`, `0x00468644` | `BalloonObjectPane` / [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) | Attached/balloon object position interpolation using `4 * scale`. |
| `0x005055e0` | `0x005055f7` | [UID:0000L3][MapPane](by-file/MapPane.md) | Map object coordinate helper using tile dimensions and `4 * scale`. |
| `0x00506980` | `0x00506a1e` | [UID:0000L3][MapPane](by-file/MapPane.md) | Map/object placement helper using movement-offset divisor. |
| `0x0050b080` | `0x0050b0f5`, `0x0050b11c` | [UID:0000L3][MapPane](by-file/MapPane.md) | Object screen-coordinate correction using tile dimensions and direction state. |
| `0x00538600` | `0x0053864f` | [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) | Attached-object position update using `4 * scale`. |
| `0x005386c0` | `0x00538744`, `0x0053875d` | [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) | Attached-object screen-position helper. |
| `0x00539b20` | `0x00539b6f` | [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) / object overlays | Object label/overlay placement. |
| `0x0053c700` | `0x0053c773`, `0x0053c78f` | [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) | Anchor offset scaling using `4 * scale`. |
| `0x0053c810` | `0x0053c895` | [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) | Anchor/bounds helper using moving-source offset. |
| `0x005a36f0` | `0x005a3725` | [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) | Movement animation/timer start; delay divided by scale. |
| `0x005a3770` | `0x005a3836` | [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) | Directional movement/timer start; delay divided by scale. |
| `0x005a83b0` | `0x005a840e`, `0x005a846b`, `0x005a84cc`, `0x005a85fe`, `0x005a865b`, `0x005a86bc` | [UID:0000P1][UserPane](by-file/UserPane.md) | Animation-step movement subframe/timer math. |
| `0x005a88d0` | `0x005a8923` | [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) | Local-player screen/hit-bounds update. |
| `0x005ab410` | `0x005ab554` | [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) | Movement packet/correction delay scheduling. |

The direct readers prove a shared global, not declaration ownership by the highest-volume consumer. The decisive owner signal is that every major consumer either is a MapPane coordinate/object-placement helper or calls back into the MapPane direction-coordinate API. The core helper set is `0x00505080`, [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md) / [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md), the unsplit `0x00505130` tile/viewport-to-screen helper, `0x005055e0`, [UID:0002QL][0x005058b0-0x0050593e.MapPaneScrollViewportByDirection](by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md), [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md), `0x00506980`, and `0x0050b080`.

The ownership ranking from the report is retained as follows:

| Candidate | Result | Reason |
| --- | --- | --- |
| [UID:0000L3][MapPane](by-file/MapPane.md) / `NexusTK/map/MapPane.cpp` | Accepted best owner. | Direct MapPane helper reads, tile-dimension coupling, MapPane source-tree fit, and all higher-level consumers route through MapPane coordinate helpers. |
| MapPane-owned coordinate/movement helper grouping | Acceptable documentation fallback only. | Useful if a narrower parent is later needed, but it must still resolve to `MapPane.cpp`; it is not proof of a new source file. |
| `MapMovementGlobals.cpp` / `MapMovementConfig.cpp` | Rejected. | No writer, initializer, source metadata, source-tree entry, or isolated data cluster supports an independent file. |
| [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) | Rejected as owner; confirmed consumer. | Local-player/timer paths read the byte but call MapPane placement helpers and do not own declaration evidence. |
| [UID:0000P1][UserPane](by-file/UserPane.md) | Rejected as owner; confirmed consumer. | `0x005a83b0` has many reads, but it is one high-traffic consumer and calls MapPane helpers. |
| [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) / [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) | Rejected as owner; confirmed consumers. | Attached/anchor placement reads are a subset and do not cover local-player or MapPane coordinate paths. |
| [UID:0000HG][Application](by-file/Application.md), config/startup files, [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md), and neighboring display/EPF globals | Rejected from current evidence. | A process-wide byte could abstractly live in config/startup, but IDA found no direct reads or writes there, and neighboring data has distinct xref populations. |
| [UID:0000JK][FpsPane](by-file/FpsPane.md), [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md), or address-island-only parents | Rejected. | These are adjacency-only candidates with unrelated xref sets. |

The low-confidence items are now resolved to the current evidence limit: the literal original source spelling is not recovered from PDB/source metadata, no direct writer/config initializer has been found, and a private MapPane helper translation unit remains possible but weaker than `MapPane.cpp` because the current source tree has no such companion. `g_movementSubstepScale` is therefore the best reconstructed name, not a recovered symbol.

## Ownership Notes

This global is a shared MapPane coordinate/movement scalar rather than part of the screen width/height pair. It sits between [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) in `.data`, but xrefs tie it to movement interpolation, attached-object placement, player animation timing, and most importantly MapPane direction/tile/viewport conversion helpers.

The executed ownership inference assigns this page to [UID:0000L3][MapPane](by-file/MapPane.md). The decisive evidence is not a writer, because no writer or debug-source metadata has been recovered; it is the coherent read surface. Every direct read is movement/placement related, the core readers are MapPane coordinate helpers, and the higher-level actor/user consumers route through the MapPane direction-coordinate API.

Do not create or assign this page to `MapMovementGlobals.cpp`, `MapMovementConfig.cpp`, `UserPane`, `LivingObjectPane`, `AttachedObjectPane`, or `AttachmentAnchorResolver` from current evidence. Those pages are consumers, partial users, or unsupported hypotheses. A smaller MapPane-owned coordinate/movement helper grouping may be useful later, but it should still resolve to `NexusTK/map/MapPane.cpp`.

The exact storage child [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md) is assigned to [UID:0000L3][MapPane](by-file/MapPane.md) directly rather than to this by-global page, because generated memory coverage does not support by-global parents. This page remains the semantic global documentation for that byte.

## Reconstruction Notes

- The only emitted declaration is the managed formal block at the top of this page. The exact memory page stays non-duplicating: it records the storage byte and owner route, while this semantic global is the declaration emitter.
- Plain `char` is primary because all 23 readers sign-extend the byte and the observed MSVC-era source style uses ordinary fundamental types. Explicit `signed char` would preserve behavior but is a lower-probability lexical form. Historical `unsigned char` and modern `std::uint8_t` are rejected because their integer promotion does not explain the universal signed loads.
- Initial value remains exactly 1. No direct writer or configuration path was found, and consumers contain no zero/negative guard. Reconstructed source must preserve the direct arithmetic rather than inventing validation.
- `g_movementSubstepScale` remains a descriptive stripped-name reconstruction. MapPane ownership is retained from the coherent coordinate/movement reader surface; signedness evidence does not create a standalone movement-global file or transfer ownership to high-volume UserPane/LivingObjectPane consumers.

## Score Rationale

- Completion `91`: exact storage, initial value, all 23 read addresses, 14-function spread, universal signed-load form, no-writer evidence, neighboring global boundaries, movement/vector and timer-delay divisors, exact memory child, by-global parenting limitation, MapPane source ownership, rejected owner/file/type alternatives, and the single formal declaration are documented.
- Confidence `93`: IDA confirms one-byte signed consumption at every direct reader and current source behavior is type-complete. Confidence remains below 95 because the stripped binary does not recover the original symbol spelling, plain-versus-explicit signed-char lexical choice, or a direct source initializer/writer record.

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

- 2026-07-15 Agent-B004 UID0003U7 signedness callback:
  - Raised `89/90 -> 91/93` and changed the sole managed declaration from historical unsigned byte to file-static plain `char`, initialized to 1.
  - Added the complete 23-reference/14-function `movsx` inventory, explicit `signed char` runner-up, unsigned/`std::uint8_t` rejection, no-writer/no-guard evidence, and score caps.
  - Retained UID0000L3 MapPane owner/emitter, exact UID00027F storage route, blank position, descriptive symbol caveat, neighboring-global separation, and rejected standalone/consumer owners.
- 2026-06-22 Rule 26 retry for B001 older report `0002CF-g_movementSubstepScale`:
  - Added the full direct xref inventory, owner-ranking/rejection matrix, low-confidence resolution, and first-draft `static unsigned char g_movementSubstepScale = 1;` declaration.
  - Kept [UID:0000L3][MapPane](by-file/MapPane.md) as owner/emitter, with the exact storage child remaining non-duplicating. Application/screen-dimension, EPF, FPS, attached-object, living-object, UserPane, and standalone movement-global owners remain rejected or consumer-only.
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
