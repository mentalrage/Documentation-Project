*** UID:0000K8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IntAlphaSurface

## Status

- Confidence: strong for destructor, buffer-release slot, vtable slots, and live IDA function-boundary evidence; medium-high for source placement; medium for the final class split.
- Proposed module: `NexusTK/render/IntAlphaSurface.cpp`, with possible merge into `NexusTK/render/AlphaMaskSurface.cpp` or `NexusTK/render/Surface.cpp` if later constructor/caller recovery proves it was not a standalone source file.
- Main address range: [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md).

## File Role

`IntAlphaSurface` appears to be an integer or per-pixel alpha surface related to the byte-mask `AlphaMaskSurface` family. Live IDA evidence proves object teardown and one vtable helper: the scalar deleting destructor resets the vtable, frees `m_pixelData` when `m_ownsBuffer` is set, clears the buffer pointer, and optionally frees the object storage; slot 1 at `0x00462260` performs the same owned-buffer release without scalar-delete semantics.

The concrete object offsets are recorded in [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), and the recovered vtable slots are recorded in [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md). These pages intentionally keep the class-name caveat visible because the same vtable is written by `AlphaMaskSurface` constructor/helper code.

The source-file split is provisional. IDA shows the `IntAlphaSurface` vtable at `0x006112ec`, with the first slot pointing at the destructor and the next slot pointing at `0x00462260`. References to that vtable come from `AlphaMaskSurface` constructor/helper code as well as the destructor, so this may be a base/sibling surface implementation rather than a large independent file.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `IntAlphaSurface::ScalarDeletingDestructor` | `0x00463270-0x004632b1` | Resets the vtable, frees owned pixel storage, and optionally deletes `this`. |
| `IntAlphaSurface::ReleaseOwnedPixels` provisional | [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) | Frees owned pixel storage at `+0x14`, clears the pointer, and leaves object storage intact. |
| `InitAlphaSurfaceView` provisional | [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) | Writes `off_6112EC` and initializes a full or clipped non-owning view object. |
| Active alpha-surface owning constructor | `0x00462170-0x00462227` | Real IDA-modeled constructor/helper that writes `off_6112EC`, initializes bounds, allocates `width * height` bytes, and ties this vtable to live alpha-surface construction. |
| Raw default-constructor-shaped block | [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) | Raw code only; writes the same vtable and zero/owning state, but IDA still has no function object or xrefs to the start. |
| `IntAlphaSurface` vtable | `0x006112ec` | Vtable slot 0 points to `0x00463270`; slot 1 points to `0x00462260`. |

## Evidence Notes

- IDA MCP reports no direct code callers to `0x00463270`, which is normal for a virtual destructor reached through a vtable.
- IDA MCP reports no direct code callers to `0x00462260`, but `xrefs_to` shows it is vtable slot 1 at `0x006112f0`.
- IDA MCP reports `0x004623c0` writes `off_6112EC` and builds full/clipped view state; keep it near this class while constructor recovery remains incomplete.
- 2026-05-26 IDA MCP raw-disassembly recheck found constructor-shaped bytes at `0x00462120-0x00462161` that also write `off_6112EC`; keep that range near the alpha-surface family but do not treat it as an IDA-confirmed `IntAlphaSurface` constructor.
- 2026-05-26 IDA MCP raw-disassembly/xref recheck found [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) as compiler EH cleanup that restores `off_6112EC` and releases owned pixels. Its only observed caller is the EH funclet at `0x005fa593`.
- `0x004632c0` is not an `IntAlphaSurface` destructor. It uses vtable `0x00612574`, frees a different object/global payload, and belongs to application error-state cleanup.
- IDA MCP reports data references to `off_6112EC` from raw `0x0046212c`, `0x0046217b`, EH cleanup store `0x00462237`, `0x00462415`, and `0x0046327a`; all but the destructor reset are in the neighboring `AlphaMaskSurface` constructor/helper region.
- 2026-05-30 IDA MCP recheck confirms the destructor and release vtable slot both free pixel pointer offset `+0x14` only when ownership byte `+0x24` is set, and that both entries remain vtable-only with no direct code callers. This supports a surface class method reconstruction while leaving the exact original file split provisional.
- 2026-06-04 live IDA MCP recheck confirms `0x00462120` still has no function object and no xrefs; the surrounding functions are `sub_461FE0` ending at `0x00462114` and `sub_462170` starting at `0x00462170`. Raw disassembly still shows `0x00462120-0x00462161` writing `off_6112EC`, clearing `+0x14/+0x18/+0x1c/+0x20`, setting ownership byte `+0x24`, and calling `sub_4B7C50`.
- 2026-06-04 live IDA MCP `decompile 0x00462170` confirms the active owning constructor/helper writes `off_6112EC`, initializes bounds, calls the vtable release slot before reallocating, stores width/height/stride, and allocates `width * height` bytes. `callers 0x00462170` reports four callers at `0x004df9a9`, `0x0050442c`, `0x005a288d`, and `0x005a2b8e`.
- 2026-06-04 live IDA MCP confirms `sub_4623C0` is `0x004623c0-0x00462514` and owns tail chunks `0x00462230-0x00462258` and `0x005fa580-0x005fa5be`; `xrefs_to 0x00462230` reports the EH funclet xref at `0x005fa593`, so the cleanup remains compiler support rather than a source method.
- 2026-06-04 live IDA MCP reads the first four vtable dwords at `0x006112ec` as `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`. `xrefs_to 0x006112ec` still reports the five data stores at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.

## Ownership Decision

Keep `IntAlphaSurface` in the render surface layer. Do not assign it to an image-library consumer such as `LightObjImageLib`; the only proven behavior is generic surface ownership and teardown. Keep the standalone `render/IntAlphaSurface.cpp` node in the proposed tree as a research anchor, but allow migration to fold it into `AlphaMaskSurface.cpp` or `Surface.cpp` if the constructor or full vtable later proves a smaller original source grouping.

The validator path is `NexusTK/render/` because [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/IntAlphaSurface.cpp` as a provisional node next to `AlphaMaskSurface.cpp`. That is a placement anchor, not proof that the original project had a separate source file.

## Cross-References

- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `74/84`. Previously the file page had recovered method/vtable evidence but no score and a stale note about the memory filename ending at `0x004632b0`; it now links the canonical `0x00463270-0x004632b1` page and records the current IDA MCP release/destructor recheck.
- 2026-06-04: Raised completion/confidence from `74/84` to `84/88` and filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/render/`.
  - Before: the page still had a blank validator path, stale one-method import wording, and older evidence that did not capture the live tail-chunk ownership for `sub_4623C0`.
  - After: the page records the provisional render placement, removes importer-derived evidence, links the canonical `0x004623c0-0x00462514` by-memory page, and documents the current IDA boundaries, vtable dwords, active constructor callers, raw-default-constructor caveat, and EH-only cleanup chunk.
  - Summary/evidence: live IDA MCP confirms the destructor/release slot behavior and vtable-only xrefs, proves the active `0x00462170` constructor/helper with four callers, proves `0x00462120` remains raw/no-xref code, and proves `0x00462230` is an EH tail chunk owned by `sub_4623C0`. Completion/confidence remain below final-code levels because the final source split between `IntAlphaSurface`, `AlphaMaskSurface`, and a broader surface module is still unresolved.
