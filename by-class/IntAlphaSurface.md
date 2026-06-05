*** UID:00006K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IntAlphaSurface

## Status

- Confidence: strong for destructor, buffer-release slot, vtable evidence, and live IDA boundaries; medium-high for render-surface placement; medium for final constructor/source split.
- Likely source file: [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md), with possible merge into [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) or a neighboring `render/Surface.cpp` after constructor/caller recovery.
- Address range: [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- Type docs: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)

## Class Purpose

`IntAlphaSurface` appears to be a related alpha/blending surface that owns a pixel buffer when an `ownsBuffer` flag is set. Live IDA evidence proves the scalar deleting destructor, a buffer-release slot at `0x00462260`, the active owning constructor/helper at `0x00462170`, and the nearby view initializer at `0x004623c0`. The final class/source split remains open because the same vtable is written by `AlphaMaskSurface` constructor/helper code.

## Observed State

```text
0x00  vtable
0x04  RectBounds bounds
0x14  uint8_t* pixels
0x18  int width
0x1c  int height
0x20  int stride
0x24  uint8_t ownsBuffer
```

The destructor frees `m_pixelData` when `m_ownsBuffer` is true, clears the pointer, and optionally deletes object storage. Slot 1 at [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) performs the same owned-buffer release without deleting object storage.

## Vtable Evidence

IDA identifies `off_6112EC` as the `IntAlphaSurface` vtable. Slot 0 points to `0x00463270`, and slot 1 points to `0x00462260`. The vtable has data references from raw constructor-shaped bytes at `0x0046212c`, from the active constructor at `0x0046217b`, from the EH-only [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) at `0x00462237`, from the view initializer at `0x00462415`, and from the destructor reset at `0x0046327a`. IDA MCP recheck on 2026-05-25 and 2026-05-26 reports no direct code callers for either virtual target, which is expected for vtable-dispatched teardown.

2026-05-26 IDA MCP `py_eval` confirms the first four vtable dwords at `0x006112ec` are `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`.

2026-05-30 IDA MCP recheck confirms the destructor and release slot both test ownership byte `+0x24`, free pixel pointer `+0x14`, and clear the pointer. `xrefs_to 0x00463270` and `xrefs_to 0x00462260` remain vtable-only, and `callers` reports no direct code callers for either function.

2026-06-04 live IDA MCP recheck confirms:

- `0x00462120` still has no function object and no xrefs, but raw disassembly writes `off_6112EC`, clears `+0x14/+0x18/+0x1c/+0x20`, sets ownership byte `+0x24`, and calls `sub_4B7C50`.
- `sub_462170` is a real `0x00462170-0x00462227` function with four callers at `0x004df9a9`, `0x0050442c`, `0x005a288d`, and `0x005a2b8e`; decompilation writes `off_6112EC`, initializes bounds, calls the release vtable slot before reallocating, and stores width/height/stride plus a `width * height` allocation.
- `sub_4623C0` is `0x004623c0-0x00462514` and owns tail chunks `0x00462230-0x00462258` and `0x005fa580-0x005fa5be`; the only observed xref to the `0x00462230` cleanup chunk is the EH funclet xref at `0x005fa593`.
- The first four vtable dwords at `0x006112ec` remain `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`, with stores at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.

`0x004632c0` is explicitly excluded from this class. It uses vtable `0x00612574`, is reached from application global initializer/atexit cleanup paths, and should be tracked as application error-state cleanup rather than `IntAlphaSurface`.

## Cross-References

- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `76/84`. Previously the class page had recovered layout/vtable notes but no score; it now records the current IDA MCP vtable-only caller/xref recheck while keeping constructor and source-family recovery open.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: validator metadata left the reconstructable field blank.
  - After: the page is explicitly reconstructable, but parent attachment and C++ autogen code remain blank.
  - Summary/evidence: IDA MCP confirms the `off_6112EC` vtable, destructor/release methods, owned-pixel offsets, and alpha-surface constructor/helper stores. The final source-file split with `AlphaMaskSurface` is still open, so only the reconstructable classification was changed.
- 2026-06-04: Raised completion/confidence from `76/84` to `84/88`.
  - Before: the page still treated the class as mostly destructor-only and did not record the current IDA tail-chunk ownership for the cleanup block.
  - After: the class page records the active owning constructor/helper, current vtable dwords and xrefs, the raw/no-xref default-constructor caveat, and the EH-only cleanup chunk under `sub_4623C0`.
  - Summary/evidence: live IDA MCP proves the destructor/release slot behavior, vtable-only virtual targets, active constructor callers, `0x00462120` raw status, and `0x00462230` EH tail-chunk ownership. The class remains below final C++ reconstruction confidence because the original source split with `AlphaMaskSurface` is still unresolved.
