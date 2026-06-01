*** UID:0000TX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlphaSurfaceReleaseOwnedPixels 0x00462260

## Status

- Confidence: strong for behavior and vtable-slot identity, medium for final class name.
- Entity kind: virtual helper / buffer release method.
- Exact range: `0x00462260-0x00462281`.
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), with provisional [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md) ownership.
- Related vtable: [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md).

## Behavior

This helper releases owned alpha-surface pixel storage without deleting the surface object:

1. Tests ownership byte at object offset `+0x24`.
2. If owned and pixel pointer `+0x14` is non-null, calls CRT/free wrapper on the pixel pointer.
3. Clears the pixel pointer at `+0x14`.

It does not clear width, height, or stride, and it does not free `this`.

The nearby [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) performs similar owned-buffer release plus a vtable restore, but it is reached only from a compiler EH funclet and should not be modeled as this virtual slot.

## IDA MCP Evidence

- `lookup_funcs 0x00462260` reports a real function size of `0x22`.
- `decompile 0x00462260` shows the ownership flag test, `j_j_j___free_base(*(this + 0x14))`, and pixel-pointer clear.
- `xrefs_to 0x00462260` reports only the vtable data slot at `0x006112f0`.
- `callers 0x00462260` reports no direct code callers, which is expected for a vtable-only helper.
- 2026-05-30 IDA MCP recheck confirms the helper tests ownership byte `+0x24`, frees pixel pointer `+0x14`, clears that pointer, and does not delete object storage. The paired destructor at [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) performs the same owned-buffer release and then conditionally deletes `this`.

## Reconstruction Notes

Treat this as a virtual or file-local helper generated from the alpha-surface class hierarchy, not as a standalone render algorithm. The compiler can only reproduce the vtable slot if the source model keeps the release method on the same surface type as the destructor at `0x00463270`.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `86/90`. Previously this page had detailed behavior but no score; it now records the current IDA MCP offset recheck and explicitly distinguishes this release slot from the scalar deleting destructor.
