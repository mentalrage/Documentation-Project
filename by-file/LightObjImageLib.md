*** UID:0000KP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LightObjImageLib

## Status

- Confidence: strong for high-level behavior, singleton/vtable evidence, and observed offsets; medium for final source-level field names.
- Proposed module: `render/LightObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_LightObjImageLib.cpp`
- Main address ranges: `0x004df7e0-0x004dfd0a`, `0x004e5bb0-0x004e5bbb`, and `0x004e65e0-0x004e669d`
- Primary global instance: [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) at `0x0069b450`
- Primary vtable: [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) at `0x0061b754`

## File Role

`LightObjImageLib` is the light-source image library. Unlike the tile/item/riding libraries, it does not primarily load sprite frames from EPF archives. It reads `LIGHT.TBL`, builds per-light radial frames procedurally, and exposes two draw modes that center a prebuilt frame at a target screen position.

This should stay in render/image ownership but separate from the EPF frame-table loaders. It depends on DAT table reads, alpha-mask frame creation, and the shared [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md) helper family, but the table schema and procedural radial frame generation are light-specific.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `LIGHT.TBL` | Light source table: id/source, X/Y radii, brightness, blend value, and frame generation parameters. |

## Behavior Summary

The constructor opens `LIGHT.TBL`, reads the record count, resizes the light-info array, and decodes each light record. When both radii are positive, it creates a frame of size `(2 * radiusX + 1)` by `(2 * radiusY + 1)`, clears it, finds its center, and draws a radial light texture into the frame using brightness converted to a 0..32 alpha-like value.

`DrawLightMode1` and `DrawLightMode2` select either the requested light record or a fallback entry, compute a destination rectangle centered around `(centerX, centerY)`, and call the shared frame blitter with blend mode `1` or `2`.

The object layout is now anchored by [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md). The record table uses `0x1c`-byte [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) rows, plus an in-object fallback `LightInfo` at `this + 0x14`.

The generated `ProtectedArray_struct_LightInfo_` file is only the concrete template cleanup support for the light record table. `LightObjImageLib` owns `LIGHT.TBL` parsing and frame generation; [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) owns the reusable container pattern.

## IDA-Confirmed Bodies

| Range | Body | Role |
| --- | --- | --- |
| `0x004df7e0-0x004dfaa6` | [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) | Constructs the singleton, loads `LIGHT.TBL`, allocates `LightInfo` rows, and generates radial light frames. |
| `0x004dfab0-0x004dfb36` | [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) | Deletes generated frames, frees the `LightInfo` buffer, clears the singleton, and tail-calls `LObject` cleanup. |
| `0x004dfb40-0x004dfbb0` | [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) | Returns local light bounds derived from the selected `LightInfo` radii. |
| `0x004dfbb0-0x004dfc5a` | [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) | Draws a centered generated light frame with blend mode `1`. |
| `0x004dfc60-0x004dfd0a` | [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) | Draws a centered generated light frame with blend mode `2`. |
| `0x004e5bb0-0x004e5bbb` | [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) | Clears `g_pLightObjImageLib`. |
| `0x004e65e0-0x004e669d` | [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) | Virtual deleting destructor wrapper over the same generated-frame cleanup semantics. |
| `0x0069b450-0x0069b454` | [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md) | Runtime pointer to the light image-library singleton. |

## Caveats

Wave3's current `class_LightObjImageLib.cpp` is useful as behavior evidence but still contains modern C++ artifacts and unresolved helper names. The class-level effective grade is `41.5` even though each modeled method is imported with effective grade `97.0`. Active generated metadata reports `vtable_count: 0` and omits the ordinary destructor at `0x004dfab0`, while IDA confirms both the vtable and raw destructor body. Treat generated field names and inventory as provisional until this class is rewritten.

## Cross-References

- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:00017P][0x004df7e0-0x004e669c.LightObjImageLib](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: light image-library role, `LIGHT.TBL` resource inputs, radial frame generation, draw modes, layout/record/vtable anchors, supplemental destructor/singleton bodies, and caveats are documented; confidence is capped by final source-level field names and generated metadata omissions.
- 2026-05-31 exact method split and projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the body list only called out the ordinary destructor, singleton-clear helper, and singleton storage.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, plus exact constructor, bounds helper, draw mode, and scalar deleting destructor by-memory references.
  - Summary/evidence: proposed tree already places this module at `render/LightObjImageLib.cpp`; IDA MCP verified exact bounds and behavior for `0x004df7e0`, `0x004dfb40`, `0x004dfbb0`, `0x004dfc60`, and `0x004e65e0`. Final C++ remains blank because field/helper names and neighboring dependencies are below the `95+` final-source threshold.
