*** UID:00003V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIBitmap

## Status

- Confidence: strong for wrapper behavior, medium for private field names.
- Likely source file: [UID:0000IV][DIBitmap](by-file/DIBitmap.md), with free PCX helpers in [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Address range: [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- Current recovered file: `source-3/simroot_v2/class_DIBitmap.cpp`
- Primary vtable: [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md), summarized by [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Confirmed layout: [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)

## Class Purpose

`DIBitmap` wraps a Win32 16-bit top-down DIB section. It stores an embedded `BITMAPINFOHEADER`, the `HBITMAP`, the pixel pointer returned by `CreateDIBSection`, and the requested image dimensions.

## Observed State

```text
0x00  LObject/vtable base
0x04  BITMAPINFOHEADER
0x2c  HBITMAP bitmap handle
0x30  void* pixels
0x34  int width
0x38  int height
```

The constructor aligns the DIB section width up to a multiple of four pixels for DWORD-aligned scanlines, stores that aligned width in `BITMAPINFOHEADER.biWidth` at offset `0x08`, and preserves the requested width/height in the object fields.

See [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md) for the IDA-confirmed field evidence. Current generated Wave3 metadata reports a larger `0x60`-byte structure with noisy undefined fields; the live binary evidence only requires fields through `+0x38` in this checked method cluster.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DIBitmap::DIBitmap` | `0x004a1600` | Creates a 16-bit top-down DIB section through `CreateDIBSection`. |
| `DIBitmap::~DIBitmap` non-deleting body | `0x004a1740` | Raw destructor/cleanup body; deletes the `HBITMAP` and tail-jumps to `LObject` destruction. |
| `GetBits` provisional | `0x004a1760` | Returns the DIB section pixel pointer. |
| `GetBitmapHandle` provisional | `0x004a1770` | Returns the `HBITMAP`. |
| `GetWidth` provisional | `0x004a1780` | Returns zero when no pixels exist, otherwise requested width. |
| `GetHeight` provisional | `0x004a1790` | Returns zero when no pixels exist, otherwise requested height. |
| `GetAlignedWidth` provisional | `0x004a17a0` | Raw accessor; returns zero when no pixels exist, otherwise aligned DIB width from `BITMAPINFOHEADER.biWidth`. |
| `ScalarDeletingDestructor` | `0x004a1b10` | Deletes the `HBITMAP`, destroys the base object, and optionally frees memory. |

## Evidence Notes

- Wave3 metadata describes the object as 96 bytes and notes the constructor is often inlined or represented through the factory helper at `0x004a18b0`.
- IDA MCP reports no direct callers to the constructor or scalar deleting destructor symbols, while `CreateDIBitmapFromPcxBuffer` contains equivalent construction/destruction behavior in the same local cluster.
- IDA MCP confirms the primary vtable at `0x00618e54` and the omitted method cluster at `0x004a1740-0x004a17ac`; current Wave3 metadata still reports `vtable_count: 0`.
- 2026-05-31 IDA MCP confirms the exact vtable data span at `0x00618e50-0x00618e60`: RTTI pointer `??_R4DIBitmap@@6B@` at `0x00618e50`, vtable symbol `??_7DIBitmap@@6B@` at `0x00618e54`, three virtual slots, and `DirectX` RTTI beginning at `0x00618e60`.
- IDA-confirmed constructor stores, destructor loads, and tiny accessors support the compact layout through `+0x38`; the generated `0x60` size is retained only as a data caveat until verified by additional code.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000136][0x004a1740-0x004a17ac.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ac.DIBitmapDestructorAndAccessors.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/82`.
  - Summary/evidence: DIB-section responsibility, compact field layout, constructor/destructor/accessor methods, PCX factory relationship, vtable/layout links, and Wave3 size caveat are documented; remaining work is final private field naming and resolving the generated size mismatch.
- 2026-05-31 exact vtable split:
  - Before: the page linked only the combined vtable type page and `RECONSTRUCTABLE` was blank.
  - After: the page is marked `RECONSTRUCTABLE:TRUE` and links the exact `0x00618e50-0x00618e60` vtable-data child.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan verify the `DIBitmap` RTTI/vtable record and prove the adjacent `DirectX` boundary at `0x00618e60`.
