*** UID:0000K8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IntAlphaSurface

## Status

- Confidence: strong for destructor, buffer-release slot, and vtable evidence; medium for constructor and full source-file grouping.
- Proposed module: `render/IntAlphaSurface.cpp`, with possible merge into `render/AlphaMaskSurface.cpp` or `render/Surface.cpp` if later constructor/caller recovery proves it was not a standalone source file.
- Current recovered source: `source-3/simroot_v2/class_IntAlphaSurface.cpp`
- Main address range: [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md).

## File Role

`IntAlphaSurface` appears to be an integer or per-pixel alpha surface related to the byte-mask `AlphaMaskSurface` family. Current code recovery proves object teardown and one vtable helper: the scalar deleting destructor resets the vtable, frees `m_pixelData` when `m_ownsBuffer` is set, clears the buffer pointer, and optionally frees the object storage; slot 1 at `0x00462260` performs the same owned-buffer release without scalar-delete semantics.

The concrete object offsets are recorded in [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), and the recovered vtable slots are recorded in [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md). These pages intentionally keep the class-name caveat visible because the same vtable is written by `AlphaMaskSurface` constructor/helper code.

The source-file split is provisional. IDA shows the `IntAlphaSurface` vtable at `0x006112ec`, with the first slot pointing at the destructor and the next slot pointing at `0x00462260`. References to that vtable come from `AlphaMaskSurface` constructor/helper code as well as the destructor, so this may be a base/sibling surface implementation rather than a large independent file.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `IntAlphaSurface::ScalarDeletingDestructor` | `0x00463270-0x004632b1` | Resets the vtable, frees owned pixel storage, and optionally deletes `this`. |
| `IntAlphaSurface::ReleaseOwnedPixels` provisional | [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) | Frees owned pixel storage at `+0x14`, clears the pointer, and leaves object storage intact. |
| `InitAlphaSurfaceView` provisional | [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md) | Writes `off_6112EC` and initializes a full or clipped non-owning view object. |
| `IntAlphaSurface` vtable | `0x006112ec` | Vtable slot 0 points to `0x00463270`; slot 1 points to `0x00462260`. |

## Evidence Notes

- Wave3 imports this as a one-method class with manual grade 95/effective grade 95 on the destructor and class effective grade 97.5.
- Wave3 reports no missing references for the class, but this only means no unresolved callees are attached to the single recovered destructor.
- IDA MCP reports no direct code callers to `0x00463270`, which is normal for a virtual destructor reached through a vtable.
- IDA MCP reports no direct code callers to `0x00462260`, but `xrefs_to` shows it is vtable slot 1 at `0x006112f0`.
- IDA MCP reports `0x004623c0` writes `off_6112EC` and builds full/clipped view state; keep it near this class while constructor recovery remains incomplete.
- 2026-05-26 IDA MCP raw-disassembly recheck found constructor-shaped bytes at `0x00462120-0x00462161` that also write `off_6112EC`; keep that range near the alpha-surface family but do not treat it as an IDA-confirmed `IntAlphaSurface` constructor.
- 2026-05-26 IDA MCP raw-disassembly/xref recheck found [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) as a compiler-generated EH cleanup target that restores `off_6112EC` and releases owned pixels. Its only observed caller is the EH funclet at `0x005fa593`.
- `0x004632c0` is not an `IntAlphaSurface` destructor. It uses vtable `0x00612574`, frees a different object/global payload, and belongs to application error-state cleanup.
- IDA MCP reports data references to `off_6112EC` from raw `0x0046212c`, `0x0046217b`, EH cleanup store `0x00462237`, `0x00462415`, and `0x0046327a`; all but the destructor reset are in the neighboring `AlphaMaskSurface` constructor/helper region.
- 2026-05-30 IDA MCP recheck confirms the destructor and release vtable slot both free pixel pointer offset `+0x14` only when ownership byte `+0x24` is set, and that both entries remain vtable-only with no direct code callers. This supports a surface class method reconstruction while leaving the exact original file split provisional.

## Ownership Decision

Keep `IntAlphaSurface` in the render surface layer. Do not assign it to an image-library consumer such as `LightObjImageLib`; the only proven behavior is generic surface ownership and teardown. Keep the standalone `render/IntAlphaSurface.cpp` node in the proposed tree as a research anchor, but allow migration to fold it into `AlphaMaskSurface.cpp` or `Surface.cpp` if the constructor or full vtable later proves a smaller original source grouping.

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
