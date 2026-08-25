*** UID:0001U6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact DIBitmap layout is emitted by the canonical class declaration [UID:00003V][DIBitmap](by-class/DIBitmap.md).
// Do not emit a duplicate class or standalone mirror structure from this support page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DIBitmap Layout

## Status

- Confidence: very strong for every offset, exact `0x3c` size, accepted source-facing fields, constructor/destructor/accessor parity, and class ownership; original private spellings remain inferred rather than source-symbol-proven.
- Owner class: [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- Likely source file: [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- Primary memory range: [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- Tiny-method cluster: [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- Vtable: [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Evidence basis: 2026-05-31 and 2026-06-08 IDA MCP `decompile`/`disasm` checks of constructor `0x004a1600`, raw destructor/accessors `0x004a1740-0x004a17ad`, scalar deleting destructor `0x004a1b10`, and PCX factory inline construction.
- Assignment: direct parent is [UID:00003V][DIBitmap](by-class/DIBitmap.md). This support page is `92/94`; the class is `92/94` and flows to source-file parent [UID:0000IV][DIBitmap](by-file/DIBitmap.md). The canonical class page emits the declaration, while this page emits only the exact no-duplicate marker.

## Confirmed Fields

| Offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | `LObject` base / vptr | Constructor writes `0x00618e54`; raw destructor and scalar deleting destructor restore the same vtable. |
| `+0x04` | `40` | embedded `BITMAPINFOHEADER` | Constructor copies a 40-byte header into object offsets `+0x04` through `+0x2b`. |
| `+0x08` | `4` | `BITMAPINFOHEADER.biWidth` / aligned width | Constructor stores the DWORD-aligned DIB width; raw accessor at `0x004a17a0` returns this field when pixels exist. |
| `+0x0c` | `4` | `BITMAPINFOHEADER.biHeight` / negative height | Constructor stores a negative height for top-down scanline order. |
| `+0x2c` | `4` | `HBITMAP m_hBitmap` | Constructor stores `CreateDIBSection` result; destructor bodies delete this handle; accessor `0x004a1770` returns it. |
| `+0x30` | `4` | `void* m_pBits` | Passed as the `CreateDIBSection` output pointer; accessor `0x004a1760` returns it; width/height accessors guard on it. |
| `+0x34` | `4` | `int m_width` / requested width | Constructor stores the caller-requested width; accessor `0x004a1780` returns it when `m_pBits` is non-null. |
| `+0x38` | `4` | `int m_height` / requested height | Constructor stores the caller-requested height; accessor `0x004a1790` returns it when `m_pBits` is non-null. |

Exact object size is `0x3c` / 60 bytes (Verified with `int_convert.py`). The last 4-byte field at `+0x38` ends at `+0x3c`, and the PCX factory allocates literal 60 bytes before inline construction. No tail or field beyond `+0x38` exists in this object.

## 2026-06-08 IDA Refresh

- IDB: `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- `lookup_funcs` confirms modeled entries at `0x004a1600` (`0x138` bytes), `0x004a1760`, `0x004a1770`, `0x004a1780`, `0x004a1790`, `0x004a1b10` (`0x4e` bytes), and `0x004a1cd0` for the adjacent `DirectX` destructor. Raw addresses `0x004a1740` and `0x004a17a0` are not standalone IDA functions, matching the tiny destructor/accessor cluster caveat.
- `xrefs_to 0x00618e54` reconfirms DIBitmap vtable writes at `0x004a1638`, `0x004a1746`, `0x004a195c`, and `0x004a1b19`. The `0x004a195c` write ties the PCX factory inline object path back to the same compact DIBitmap layout.
- The exact constructor child [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md), scalar destructor child [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md), and vtable child [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) all support the same class-level parent.

## Constructor Behavior

`DIBitmap::DIBitmap` at `0x004a1600` calls the `LObject` constructor, writes the `DIBitmap` vtable, clears `m_pBits`, builds temporary `sizeof(BITMAPINFOHEADER) + 2 * width * height` byte storage, then copies the complete header into the object. It aligns DIB width upward to a multiple of four pixels, so two-byte row stride is `2 * alignedWidth` and divisible by eight for valid positive dimensions; caller-requested dimensions remain at `+0x34/+0x38`.

`CreateDIBSection` receives a top-down one-plane 16-bpp `BI_RGB` header with no palette/bitfield masks, writes the pixel pointer into `+0x30`, and returns the `HBITMAP` stored at `+0x2c`. The PCX factory copies RGB565 words into this DIB, but the header itself remains the Win32 16-bpp `BI_RGB`/no-mask convention; no hidden mask fields exist between the 40-byte header and `m_hBitmap`.

## Destructor And Accessor Behavior

- The raw non-deleting destructor body at `0x004a1740` resets the vtable, deletes `+0x2c` when non-null, and tail-jumps to `LObject` destruction.
- The scalar deleting destructor at `0x004a1b10` performs the same bitmap-handle cleanup before optional memory release.
- `0x004a1760` returns `+0x30`.
- `0x004a1770` returns `+0x2c`.
- `0x004a1780` returns zero when `+0x30` is null, otherwise `+0x34`.
- `0x004a1790` returns zero when `+0x30` is null, otherwise `+0x38`.
- Raw helper `0x004a17a0` returns zero when `+0x30` is null, otherwise `+0x08`.

## Superseded Generated-Data Assumption

Historical `source-3/simroot_v2/class_DIBitmap.meta_wave3` reported a `0x60`/96-byte structure with noisy undefined fields. Exact factory allocation and the complete method offset family disprove that generated size; it is retained only as a labeled historical assumption. The authoritative reconstructed layout is the `0x3c` class declaration emitted by [UID:00003V][DIBitmap](by-class/DIBitmap.md).

## Score Rationale

- Completion `92` records exact field offsets/end size, accepted names/types, constructor/DIB/alignment behavior, destructor/accessors, factory size/inlining, vtable relationship, owner route, superseded generated-size assumption, and formal covered-by marker.
- Confidence `94` reflects direct instruction offsets plus the literal 60-byte allocation and canonical class declaration. It remains below 95 because original private spellings and historical header organization are not original-source-proven.
- This page remains assigned to [UID:00003V][DIBitmap](by-class/DIBitmap.md); the by-file page remains source context rather than the direct type owner.

## Reconstruction Notes

The canonical, source-bearing `class DIBitmap : public LObject` declaration now lives in [UID:00003V][DIBitmap](by-class/DIBitmap.md). This support page must not retain a body-only illustrative class or emit a standalone mirror structure, because either would duplicate the canonical declaration in generated output. Its formal comment records the covered-by disposition while this body preserves offset/type/evidence detail.

Accepted field/method names are descriptive reconstruction names supported by the complete class family. Their lack of original private symbols is a score cap, not a reason to leave the class or constructor blank.

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

- 2026-07-12 B002 accepted DIB support callback:
  - Changed `86/91 -> 92/94` and blank formal block -> exact canonical-class covered-by/no-duplicate marker.
  - Promoted `0x3c` from minimum to exact size using factory allocation proof, resolved accepted field names/types and full DIB/header relationship, and removed the body-only duplicate class sketch.
  - Preserved the historical Wave3 `0x60`/96-byte claim as explicitly superseded generated metadata.

- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP directly confirms the constructor header copy, `CreateDIBSection` output storage, bitmap handle storage, raw destructor cleanup, scalar deleting destructor cleanup, and accessor offsets. The page remains below `95+` because exact original member names, source declaration shape, PCX factory relationship, and neighboring loader ownership still need a fuller audit before final C++ is safe.
- 2026-06-08 A007 Batch 130 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, with `AUTOGEN_PARENT_UID:00003V`.
  - Summary/evidence: current IDA MCP reconfirmed DIBitmap constructor/destructor/accessor boundaries, DIBitmap vtable writes, and PCX factory inline construction. The direct class parent [UID:00003V][DIBitmap](by-class/DIBitmap.md) is now `86/87`, so both child and parent clear the corrected `85/85` gate.
