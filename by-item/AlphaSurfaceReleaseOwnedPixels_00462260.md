*** UID:0000TX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004FR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlphaSurfaceReleaseOwnedPixels 0x00462260

## Status

- Confidence: strong for behavior, exact range, vtable-slot identity, and class owner; medium for final physical source-file colocation.
- Entity kind: alias/support page for exact source-emitting by-memory method [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md).
- Exact range: `0x00462260-0x00462282`.
- Likely source module: [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md), with possible colocation under [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) or a broader render surface source file.
- Source-emitting carrier: [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md). This by-item page is intentionally non-reconstructable/non-emitting to avoid duplicate output.
- Related vtable: [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md).

## Behavior

This helper releases owned alpha-surface pixel storage without deleting the surface object. The exact source-bearing page is [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md):

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
- 2026-07-03 B006 current MCP session `b010_00032w_20260703` reconfirms the helper as `sub_462260`, size `0x22` / 34 bytes (Verified with `int_convert.py`), half-open range `0x00462260-0x00462282`, exact bytes ending in `5e c3` with `0xcc` padding after `0x00462282`, vtable-only pointer at `0x006112f0`, and no scalar-delete helper path. The formal source body now lives on [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md).

## Reconstruction Notes

Treat this as an alias/support note for the source-level virtual helper now documented on [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md). The formal source body must not be duplicated here; the by-memory page carries the `IntAlphaSurface::ReleaseOwnedPixels()` output route through [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md).

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)

## Changes

- 2026-07-03 B006 Gate 1 implementation:
  - Converted this page from a duplicate source-emitting carrier into non-reconstructable alias/support for [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md).
  - Changed owner to [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md), cleared `EMITTER_UIDS`, and raised documentation score to `88/91` because the exact by-memory page now carries the formal release helper C++.
  - Summary/evidence: current MCP session `b010_00032w_20260703` reconfirmed the half-open release-helper range, exact bytes, owned-buffer offsets, vtable-only slot, and no scalar-delete wrapper behavior.
- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md).
  - Before: the vtable-slot release helper was documented but unclassified in autogen coverage.
  - Historical after at that checkpoint: it was marked as source-level virtual/helper behavior under the provisional IntAlphaSurface file root, with C++ blank under the older `95/95` code-entry wording. Superseded by the 2026-07-03 B006 exact by-memory child [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md), which now carries the formal release-helper C++.
  - Evidence: live IDA MCP `lookup_funcs 0x00462260` reports `sub_462260` size `0x22`; `callees` reports only the CRT free wrapper; prior page evidence records the vtable-only xref and owned-pixel offset behavior.

- 2026-05-30: Raised completion/confidence from `0/0` to `86/90`. Previously this page had detailed behavior but no score; it now records the current IDA MCP offset recheck and explicitly distinguishes this release slot from the scalar deleting destructor.
