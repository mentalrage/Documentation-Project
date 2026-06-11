*** UID:00003V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIBitmap

## Status

- Confidence: strong for wrapper behavior, compact layout, vtable ownership, and direct module placement; medium-high for final private field names and the generated size caveat.
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
| `DIBitmap::DIBitmap` | [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md) | Creates a 16-bit top-down DIB section through `CreateDIBSection`. |
| `DIBitmap::~DIBitmap` non-deleting body | `0x004a1740` | Raw destructor/cleanup body; deletes the `HBITMAP` and tail-jumps to `LObject` destruction. |
| `GetBits` provisional | `0x004a1760` | Returns the DIB section pixel pointer. |
| `GetBitmapHandle` provisional | `0x004a1770` | Returns the `HBITMAP`. |
| `GetWidth` provisional | `0x004a1780` | Returns zero when no pixels exist, otherwise requested width. |
| `GetHeight` provisional | `0x004a1790` | Returns zero when no pixels exist, otherwise requested height. |
| `GetAlignedWidth` provisional | `0x004a17a0` | Raw accessor; returns zero when no pixels exist, otherwise aligned DIB width from `BITMAPINFOHEADER.biWidth`. |
| `ScalarDeletingDestructor` | [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md) | Deletes the `HBITMAP`, destroys the base object, and optionally frees memory. |

## Evidence Notes

- Wave3 metadata describes the object as 96 bytes and notes the constructor is often inlined or represented through the factory helper at `0x004a18b0`.
- IDA MCP reports no direct callers to the constructor or scalar deleting destructor symbols, while `CreateDIBitmapFromPcxBuffer` contains equivalent construction/destruction behavior in the same local cluster.
- IDA MCP confirms the primary vtable at `0x00618e54` and the omitted method cluster at `0x004a1740-0x004a17ad`; current Wave3 metadata still reports `vtable_count: 0`.
- 2026-05-31 IDA MCP confirms the exact vtable data span at `0x00618e50-0x00618e60`: RTTI pointer `??_R4DIBitmap@@6B@` at `0x00618e50`, vtable symbol `??_7DIBitmap@@6B@` at `0x00618e54`, three virtual slots, and `DirectX` RTTI beginning at `0x00618e60`.
- IDA-confirmed constructor stores, destructor loads, and tiny accessors support the compact layout through `+0x38`; the generated `0x60` size is retained only as a data caveat until verified by additional code.
- 2026-06-07 Batch 083 live IDA MCP `py_eval` reconfirmed the local class cluster: constructor `0x004a1600-0x004a1738`, scalar deleting destructor `0x004a1b10-0x004a1b5e`, tiny modeled accessors at `0x004a1760`, `0x004a1770`, `0x004a1780`, and `0x004a1790`, and raw/non-modeled starts at `0x004a1740` and `0x004a17a0`. The vtable at `0x00618e54` is referenced by the constructor, the PCX factory construction path, the scalar deleting destructor, and the raw destructor bytes at `0x004a1746`.
- The same recheck keeps `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer` adjacent to the class cluster while the far decode helper `0x00549410-0x00549616` has one caller from the PCX factory. This supports `DIBitmap.cpp` as the direct class parent and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) as the free-helper context rather than a competing class owner.
- 2026-06-08 Batch 116 split work adds exact constructor and scalar-deleting-destructor by-memory children. The PCX path loader and PCX-to-DIB factory are now exact sibling pages under [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), confirming this class owns only the DIB section wrapper methods inside the mixed aggregate.

## Assignment Decision

`AUTOGEN_PARENT_UID` is set to [UID:0000IV][DIBitmap](by-file/DIBitmap.md). This class page is now `86/87`, and the direct file parent is `86/86` after the Batch 116 split recheck. The parent owns the DIB section wrapper class and records the PCX-helper relationship without treating the free decode pipeline as class methods.

C++ remains blank because private field names, exact header shape, and final class declaration style remain below the `95/95` reconstruction-code gate.

## Score Rationale

- Completion `86`: class purpose, compact field layout, exact constructor/destructor/accessor children, vtable data, PCX factory relationship, direct parent decision, source/file boundary, generated-size caveat, and key cross-references are documented.
- Confidence `87`: current IDA evidence confirms the wrapper behavior, method boundaries, vtable references, and direct file ownership. It remains below final-audit quality because the original private field names and exact class size/header declaration are still unresolved.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md)
- [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md)
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
- 2026-06-07 A006 Batch 083:
  - Changed score from `78/82` to `85/86` and set `AUTOGEN_PARENT_UID:0000IV`.
  - Summary/evidence: live IDA MCP reconfirmed the constructor, scalar deleting destructor, accessor cluster, raw destructor/accessor starts, vtable reference set, and PCX factory/decode relationship. The direct by-file parent also clears the corrected `85/85` gate.
- 2026-06-08 A007 Batch 116:
  - Changed score from `85/86` to `86/87`.
  - Summary/evidence: exact by-memory children now document the constructor and scalar deleting destructor, while the adjacent PCX loader/factory helpers are explicitly routed to ImageLoaders. The class parent relationship is strengthened without claiming ownership of the mixed aggregate.
