*** UID:0000U3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildClippedAlphaSurfaceView 0x00462320

## Status

- Confidence: strong for behavior and caller evidence, medium for final original name.
- Entity kind: function-level render helper.
- Exact range: `0x00462320-0x004623b4`.
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
- Output record: [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md).

## Behavior

`BuildClippedAlphaSurfaceView` builds a non-owning byte-buffer view over an existing alpha surface:

1. Requires a source pixel pointer and a non-null clip rectangle.
2. Intersects the requested clip against source bounds `{0,0,width,height}`.
3. Writes adjusted pixel pointer, clipped width, clipped height, and original stride into the output view.
4. Clears output ownership byte/flags at `+0x10`.

If there is no source pixel pointer, no clip rectangle, or no intersection, the output pixel pointer is set to null and the view is marked non-owning.

## IDA MCP Evidence

- `lookup_funcs 0x00462320` reports a real function size of `0x95`.
- `decompile 0x00462320` shows the source bounds initialization, rectangle intersection call, adjusted pixel pointer calculation, width/height/stride stores, and non-owning flag clear.
- `xrefs_to 0x00462320` and `callers 0x00462320` both report a live `StaticObjImageLib` caller at `0x004dd66a`.
- The function consumes the same alpha-surface object offsets documented in [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md).
- 2026-05-30 IDA MCP recheck confirms the modeled range is `0x00462320-0x004623b5`, and the only observed code xref is still [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) caller `0x004dd66a`.
- 2026-05-30 decompilation confirms output layout: pixel pointer at `+0x00`, width at `+0x04`, height at `+0x08`, stride at `+0x0c`, and non-owning flag byte at `+0x10`.

## Reconstruction Notes

Keep this with the alpha-surface/render helper module, not with `StaticObjImageLib`. The caller proves use, but the implementation is a generic clipped buffer-view builder over alpha-surface state.

Candidate source-level shape:

```cpp
void AlphaMaskSurface::BuildClippedView(AlphaSurfaceBufferView& out, const RectBounds* clip)
{
    RectBounds imageBounds(0, 0, m_width, m_height);
    RectBounds clipped;

    if (m_pixels != nullptr && clip != nullptr && imageBounds.Intersect(*clip, clipped)) {
        out.pixels = m_pixels + clipped.left + clipped.top * m_stride;
        out.width = clipped.right - clipped.left;
        out.height = clipped.bottom - clipped.top;
        out.stride = m_stride;
    } else {
        out.pixels = NULL;
    }

    out.ownsBuffer = false;
}
```

Names are provisional, but the offset behavior is IDA-backed.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously this page had behavior notes but no score; it now records the current IDA MCP range/xref/decompilation recheck, output-view offsets, and C++ reconstruction candidate.
