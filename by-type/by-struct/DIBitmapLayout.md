*** UID:0001U6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00003V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIBitmap Layout

## Status

- Confidence: strong for offsets through `+0x38`, medium for exact original member names and final allocation idiom.
- Owner class: [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- Likely source file: [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- Primary memory range: [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- Tiny-method cluster: [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- Vtable: [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Evidence basis: 2026-05-31 and 2026-06-08 IDA MCP `decompile`/`disasm` checks of constructor `0x004a1600`, raw destructor/accessors `0x004a1740-0x004a17ad`, scalar deleting destructor `0x004a1b10`, and PCX factory inline construction.
- Assignment: direct parent is [UID:00003V][DIBitmap](by-class/DIBitmap.md). This child is `86/91`, the class parent is `86/87`, and the source-file parent [UID:0000IV][DIBitmap](by-file/DIBitmap.md) is `86/86`, so the corrected `85/85` gate is satisfied.

## Confirmed Fields

| Offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | vtable / `LObject` shell | Constructor writes `0x00618e54`; raw destructor and scalar deleting destructor restore the same vtable. |
| `+0x04` | `40` | embedded `BITMAPINFOHEADER` | Constructor copies a 40-byte header into object offsets `+0x04` through `+0x2b`. |
| `+0x08` | `4` | `BITMAPINFOHEADER.biWidth` / aligned width | Constructor stores the DWORD-aligned DIB width; raw accessor at `0x004a17a0` returns this field when pixels exist. |
| `+0x0c` | `4` | `BITMAPINFOHEADER.biHeight` / negative height | Constructor stores a negative height for top-down scanline order. |
| `+0x2c` | `4` | `HBITMAP m_hBitmap` | Constructor stores `CreateDIBSection` result; destructor bodies delete this handle; accessor `0x004a1770` returns it. |
| `+0x30` | `4` | `void* m_pBits` | Passed as the `CreateDIBSection` output pointer; accessor `0x004a1760` returns it; width/height accessors guard on it. |
| `+0x34` | `4` | requested width | Constructor stores the caller-requested width; accessor `0x004a1780` returns it when `m_pBits` is non-null. |
| `+0x38` | `4` | requested height | Constructor stores the caller-requested height; accessor `0x004a1790` returns it when `m_pBits` is non-null. |

Minimum confirmed object size is `0x3c` bytes. No IDA-confirmed method in the checked cluster requires fields beyond `+0x38`.

## 2026-06-08 IDA Refresh

- IDB: `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- `lookup_funcs` confirms modeled entries at `0x004a1600` (`0x138` bytes), `0x004a1760`, `0x004a1770`, `0x004a1780`, `0x004a1790`, `0x004a1b10` (`0x4e` bytes), and `0x004a1cd0` for the adjacent `DirectX` destructor. Raw addresses `0x004a1740` and `0x004a17a0` are not standalone IDA functions, matching the tiny destructor/accessor cluster caveat.
- `xrefs_to 0x00618e54` reconfirms DIBitmap vtable writes at `0x004a1638`, `0x004a1746`, `0x004a195c`, and `0x004a1b19`. The `0x004a195c` write ties the PCX factory inline object path back to the same compact DIBitmap layout.
- The exact constructor child [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md), scalar destructor child [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md), and vtable child [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) all support the same class-level parent.

## Constructor Behavior

`DIBitmap::DIBitmap` at `0x004a1600` calls the `LObject` constructor, writes the `DIBitmap` vtable, builds a temporary 40-byte `BITMAPINFOHEADER` plus pixel-size allocation, then copies the header into the object. The constructor aligns the DIB width upward to a multiple of four pixels for DWORD scanline alignment, but preserves the caller-requested dimensions at `+0x34` and `+0x38`.

`CreateDIBSection` receives the embedded header through the temporary header buffer and writes the pixel pointer into `+0x30`. The returned `HBITMAP` is stored at `+0x2c`.

## Destructor And Accessor Behavior

- The raw non-deleting destructor body at `0x004a1740` resets the vtable, deletes `+0x2c` when non-null, and tail-jumps to `LObject` destruction.
- The scalar deleting destructor at `0x004a1b10` performs the same bitmap-handle cleanup before optional memory release.
- `0x004a1760` returns `+0x30`.
- `0x004a1770` returns `+0x2c`.
- `0x004a1780` returns zero when `+0x30` is null, otherwise `+0x34`.
- `0x004a1790` returns zero when `+0x30` is null, otherwise `+0x38`.
- Raw helper `0x004a17a0` returns zero when `+0x30` is null, otherwise `+0x08`.

## Generated-Data Caveat

Current `source-3/simroot_v2/class_DIBitmap.meta_wave3` reports a `0x60`-byte struct with a noisy `LObject` base and large undefined byte fields. Treat that generated size/layout as provisional data, not binary truth. The offsets above are IDA-confirmed from constructor stores, destructor loads, accessor bodies, and the PCX factory's inline construction path.

## Score Rationale

- Completion is raised from `82` to `86` because the layout now has an explicit direct-parent gate, current IDA refresh evidence, and exact child support for the constructor, scalar destructor, PCX factory construction path, and vtable data.
- Confidence is raised from `90` to `91` because the refreshed xrefs and function-boundary checks reconfirm the field offsets and class ownership without changing the remaining caveat that original member names are provisional.
- This page is assigned to [UID:00003V][DIBitmap](by-class/DIBitmap.md); the broader file page remains a source-file cross-reference rather than the direct type parent.

## Reconstruction Notes

The likely original class was a compact Win32/GDI helper:

```cpp
class DIBitmap : public LObject {
public:
    DIBitmap(HDC hdc, int width, int height);
    ~DIBitmap();

    void* GetBits() const;
    HBITMAP GetBitmapHandle() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetAlignedWidth() const;

private:
    BITMAPINFOHEADER m_bmiHeader;
    HBITMAP m_hBitmap;
    void* m_pBits;
    int m_width;
    int m_height;
};
```

Keep the method names provisional until caller-side usage confirms original naming style.

## Cross-References

- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md)
- [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)

## Changes

- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP directly confirms the constructor header copy, `CreateDIBSection` output storage, bitmap handle storage, raw destructor cleanup, scalar deleting destructor cleanup, and accessor offsets. The page remains below `95+` because exact original member names, source declaration shape, PCX factory relationship, and neighboring loader ownership still need a fuller audit before final C++ is safe.
- 2026-06-08 A007 Batch 130 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, with `AUTOGEN_PARENT_UID:00003V`.
  - Summary/evidence: current IDA MCP reconfirmed DIBitmap constructor/destructor/accessor boundaries, DIBitmap vtable writes, and PCX factory inline construction. The direct class parent [UID:00003V][DIBitmap](by-class/DIBitmap.md) is now `86/87`, so both child and parent clear the corrected `85/85` gate.
