*** UID:0000UU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InitAlphaSurfaceView 0x004623C0

## Status

- Confidence: strong for behavior and layout writes, medium for final class/source split.
- Entity kind: constructor/helper function.
- Exact range: `0x004623c0-0x00462514`.
- Canonical memory page: [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md).
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), with provisional [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md) ownership.
- Related layout: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md).

This page is retained as a small by-item index for older references. The canonical code-bearing documentation is now [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md), so this page is no longer a reconstruction target.

## Behavior

This helper initializes an alpha-surface view object from another alpha surface:

1. Writes `off_6112EC` / [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) into the destination object.
2. Clears destination width, height, stride, and pixel pointer, then initializes zero bounds.
3. If no clip rectangle is supplied, copies the source buffer-view payload from source offsets `+0x14` through `+0x24`.
4. If a clip rectangle is supplied and intersects the source bounds, writes adjusted pixel pointer, clipped width, clipped height, and preserved stride.
5. Clears destination ownership byte at `+0x24` before returning, making the view non-owning.

## IDA MCP Evidence

- `lookup_funcs 0x004623c0` reports a real function size of `0x154`.
- `decompile 0x004623c0` shows the vtable store at `0x00462415`, zero-state initialization, optional full-view copy, optional clipped-view setup, and final owner-flag clear.
- `xrefs_to 0x004623c0` and `callers 0x004623c0` report no direct callers in the current IDA database.
- `xrefs_to 0x006112ec` reports a vtable write at `0x00462415` inside this function. The nearby `0x00462237` vtable write is now separated as [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md), an EH-only cleanup target reached from `0x005fa593`.
- IDA MCP recheck on 2026-05-31 confirms the `0x004623c0-0x00462514` half-open range, no direct callers, calls to rectangle helpers at `0x004b7c50`/`0x004b7cc0`, and the security-cookie check epilogue.

## Reconstruction Notes

Treat this as reconstructable render infrastructure despite missing direct callers. It is an IDA-modeled function that writes the same vtable and layout as the surrounding alpha-surface constructors/destructor. The safest source model is a constructor or `InitView` helper for a non-owning `IntAlphaSurface`/alpha-surface view.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/65` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the alpha-surface view initializer, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant code, while keeping parent UID and C++ blank because class/source ownership and caller context remain incomplete.
  - Evidence: IDA MCP confirms the exact function range, no direct callers, vtable store to `off_6112EC`, clipped/full-view setup, rectangle helper callees, and final owner-flag clear.
- 2026-05-31: Promoted canonical code-bearing documentation to by-memory.
  - Before: this by-item page was the only documentation page for `0x004623c0-0x00462514` and was marked `RECONSTRUCTABLE:TRUE`.
  - After: [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) is the canonical reconstructable page; this by-item index is scored `-1/-1` and marked `RECONSTRUCTABLE:FALSE` to avoid duplicate autogen targets.
  - Evidence: `by-memory` is the canonical home for exact function/range documentation, and IDA MCP verified the exact modeled function range, vtable write, callees, and no direct caller xrefs.
