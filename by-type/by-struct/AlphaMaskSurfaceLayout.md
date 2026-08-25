*** UID:0001TP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlphaMaskSurface Layout

## Final Layout-Evidence Disposition

This page records the exact 0x28-byte layout of [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). `AlphaMaskSurfaceLayout` is a historical documentation name, not a second source type. Unique `IntAlphaSurface` RTTI, one hierarchy/vtable, and identical field use across every constructor, view, fill, blit, release, and destructor resolve the declaration name and owner.

The exact layout is vptr `+0x00`, `RectBounds` `+0x04..+0x13`, pixel pointer `+0x14`, width `+0x18`, height `+0x1c`, stride `+0x20`, ownership byte `+0x24`, and three bytes of tail padding. The formal [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) H class shell emits this layout. This duplicate evidence page is therefore `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps CPP/H blank while retaining every prior offset and dataflow observation.

## Historical Pre-Callback Status

Any retained assertion below that leaves the class name or AlphaMaskSurface/IntAlphaSurface relationship unresolved is a historical checkpoint superseded by the final disposition above.

- Confidence: strong for observed offsets and release/constructor behavior; medium-high for final type/class name.
- Likely owner header: `render/AlphaMaskSurface.h` or a broader render surface header.
- Primary file docs: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- Parent attachment: attached to [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md), which is scored `85/90`; this layout page is scored `86/90`, so both sides clear the active direct-parent gate.
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
- 2026-06-16 A001 live IDA refresh against `b001_selflookpane_0001H7_20260616` reconfirmed modeled starts for `0x00462170` size `0xb7`, release helper `0x00462260` size `0x22`, `GetBufferInfo` `0x00462300` size `0x17`, clipped-view helper `0x00462320` size `0x95`, view initializer `0x004623c0` size `0x154`, `DrawFrameWithBlendMode` `0x00462e10` size `0x10e`, `DrawEncodedAlphaFrame` `0x00462f20` size `0x332`, and scalar destructor `0x00463270` size `0x41`; raw `0x00462120` remains not a function.
- The same 2026-06-16 pass reconfirmed no IDA xrefs to raw `0x00462120`, one live caller to `0x00462320` from the `StaticObjImageLib` render body, no direct xrefs to `0x004623c0`, two `LightObjImageLib` callers for `0x00462e10`, and nine `0x00462f20` callers with three still-raw image-library call sites.
- 2026-06-16 constructor decompilation again shows byte `+0x24` (36 decimal; verified with `tools/int_convert.py`) as the ownership flag, writes width/height/stride at `+0x18/+0x1c/+0x20`, and stores pixels at `+0x14`. Clipped-view and view-initializer decompilation again build non-owning views by preserving the source stride and clearing the view ownership byte.
- 2026-06-28 B009 source-quality implementation resolves [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) as an AlphaMaskSurface-owned helper that placement-initializes a caller-supplied `IntAlphaSurface` view. Current MCP session `b001_000241_20260627` proves `ECX` is the source alpha surface, the destination object receives the `off_6112EC` vtable at `+0x00`, bounds are initialized at `+0x04`, payload fields are written at `+0x14/+0x18/+0x1c/+0x20`, and the non-owning byte at `+0x24` is cleared before return.
- A 2026-06-16 section-mapped PE scan found no absolute VA, RVA, or rel32 call/jump references to raw `0x00462120` or `0x004623c0`. That keeps the default-constructor and `InitAlphaSurfaceView` source-shape caveats real while confirming the object layout itself is not the blocker.
- 2026-07-03 B006 current MCP session `b010_00032w_20260703` reconfirmed [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) and [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md) as source-ready users of this layout. Both functions test ownership byte `+0x24` and free/clear pixel pointer `+0x14`; formal source now standardizes these as `m_ownsBuffer` and `m_pixels`.

## Naming Notes

Current docs keep the high-level class name `AlphaMaskSurface`, while the vtable at `0x006112ec` is tracked provisionally as `IntAlphaSurface`. IDA evidence shows the same vtable is written by the `AlphaMaskSurface` constructor/helper region, so final source may use a base/sibling type name rather than two unrelated classes.

Current evidence is enough to reconstruct the physical layout, but not enough to pick a final source-facing declaration name for the shared `AlphaMaskSurface`/`IntAlphaSurface` relationship. The no-xref view initializer [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) now has an AlphaMaskSurface-owned helper disposition and formal C++ on its by-memory page; do not use it as an unresolved layout blocker. The remaining type/header caveat is the raw default-constructor-shaped range and broader `IntAlphaSurface` physical source colocation.

## Cross-References

- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)

## Changes

- 2026-07-03 B006 Gate 1 implementation support sync:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: recorded that UID0000YP and UID0004FR now carry source-ready destructor/release C++ using `m_pixels` and `m_ownsBuffer`, while this layout page remains the shared offset evidence rather than a standalone function body.
- 2026-06-28 B009 [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) source-shape application:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: added that the former no-xref view-initializer caveat is resolved for layout purposes. [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) now documents `AlphaMaskSurface::InitAlphaSurfaceView(IntAlphaSurface *view, const RectBounds *clipBounds) const`, with the destination `IntAlphaSurface` layout still using offsets `+0x00/+0x04/+0x14/+0x18/+0x1c/+0x20/+0x24`. The raw default constructor and final header/type-name split remain caveats.
- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously this page documented the observed layout but had no score; it now records the current raw-constructor and clipped-view IDA MCP rechecks while preserving the final type-name caveat.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: the page already has IDA-backed constructor, destructor/release, and clipped-view evidence for a real source-level layout declaration; the remaining uncertainty is naming/ownership, so no parent attachment or C++ emission was added.
- 2026-06-06: Set `AUTOGEN_PARENT_UID` to [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md) without changing scores.
  - Before: the page met the `80/80` attachment gate but had no parent.
  - After: the layout contributes under the `AlphaMaskSurface` class while preserving the final `IntAlphaSurface` naming/split caveat.
  - Evidence: the class page is scored `84/89` and already links this layout; this page documents the constructor, release/destructor, and clipped-view uses of the same offsets.
- 2026-06-16 A001 Goal 2 type/layout refresh:
  - Before: `84/88`.
  - Changed to: `86/90`; owner/emitter remain [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md).
  - Evidence: live IDA reconfirmed all modeled alpha-surface helper starts/sizes, raw `0x00462120` no-function/no-xref status, vtable-write family, constructor/release/view field use, clipped-view caller evidence, and current blitter caller spread. A section-mapped PE scan found no VA/RVA/rel32 refs to raw `0x00462120` or no-xref `0x004623c0`, so final source-shape and `IntAlphaSurface` split caveats remain documented instead of being promoted to final C++.
