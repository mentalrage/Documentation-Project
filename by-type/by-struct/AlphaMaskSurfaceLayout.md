*** UID:0001TP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlphaMaskSurface Layout

## Status

- Confidence: strong for observed offsets and release/constructor behavior; medium-high for final type/class name.
- Likely owner header: `render/AlphaMaskSurface.h` or a broader render surface header.
- Primary file docs: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- Exact memory docs: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md), [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- Reconstructable: true as a source-level layout declaration; C++ body remains blank because this page is type/layout documentation, not a standalone function implementation.

## Layout

Observed object layout used by `AlphaMaskSurface` and the adjacent provisional `IntAlphaSurface` view/destructor helpers:

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | vtable pointer | Constructor and view initializer write [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) `0x006112ec`; destructor restores it. |
| `0x04` | [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) bounds | Constructor and view initializer call `RectBounds` init at `0x004b7c50` over `this + 0x04`. |
| `0x14` | `uint8_t* pixels` | Allocation constructor writes `unknown_libname_19(width * height)` here; release helpers free and clear it. |
| `0x18` | `int width` | Constructor writes requested width; clipped view helpers copy clipped width here. |
| `0x1c` | `int height` | Constructor writes requested height; clipped view helpers copy clipped height here. |
| `0x20` | `int stride` | Constructor writes width as stride; clipped view helpers preserve source stride. |
| `0x24` | `uint8_t ownsBuffer` plus padding | Constructor sets this byte to `1`; clipped/view helpers clear it to `0`; release/destructor helpers test it before freeing `pixels`. |

The minimum observed object size is `0x25` bytes; practical C++ layout is likely `0x28` with padding after the ownership byte.

## Evidence

- 2026-05-26 IDA MCP raw disassembly of [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) writes `off_6112EC`, initializes zero bounds at `+0x04`, clears pixels/width/height/stride, and sets byte `+0x24`.
- 2026-05-26 IDA MCP decompilation of `0x00462170` writes `off_6112EC`, initializes bounds at `+0x04`, allocates `width * height`, stores width/height/stride at `+0x18/+0x1c/+0x20`, and sets byte `+0x24`.
- 2026-05-26 IDA MCP decompilation of `0x00462260` and `0x00463270` frees `*(this + 0x14)` only when byte `+0x24` is set.
- 2026-05-26 IDA MCP decompilation of `0x004623c0` initializes the same object layout for a full or clipped non-owning view and clears byte `+0x24`.
- `GetBufferInfo` at `0x00462300` copies the contiguous payload at `+0x14` through `+0x24` into a smaller [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md) record.
- 2026-05-30 IDA MCP raw disassembly recheck of [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) confirms the zero-size constructor-shaped range writes vtable `0x006112ec`, clears offsets `+0x14/+0x18/+0x1c/+0x20`, sets ownership byte `+0x24`, and calls `RectBounds` init at `this + 0x04`.
- 2026-05-30 IDA MCP decompilation recheck of [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) confirms clipped-view consumers read source offsets `+0x14/+0x18/+0x1c/+0x20` and build the [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md) record.

## Naming Notes

Current docs keep the high-level class name `AlphaMaskSurface`, while the vtable at `0x006112ec` is tracked provisionally as `IntAlphaSurface`. IDA evidence shows the same vtable is written by the `AlphaMaskSurface` constructor/helper region, so final source may use a base/sibling type name rather than two unrelated classes.

## Cross-References

- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously this page documented the observed layout but had no score; it now records the current raw-constructor and clipped-view IDA MCP rechecks while preserving the final type-name caveat.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: the page already has IDA-backed constructor, destructor/release, and clipped-view evidence for a real source-level layout declaration; the remaining uncertainty is naming/ownership, so no parent attachment or C++ emission was added.
