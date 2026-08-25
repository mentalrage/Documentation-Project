*** UID:00003V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DIBitmap : public LObject
{
public:
    DIBitmap(HDC hdc, int width, int height);
    virtual ~DIBitmap();

    void *GetBits() const;
    HBITMAP GetBitmapHandle() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetAlignedWidth() const;

private:
    BITMAPINFOHEADER m_bmiHeader;
    HBITMAP m_hBitmap;
    void *m_pBits;
    int m_width;
    int m_height;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DIBitmap

## Status

- Confidence: very strong for wrapper behavior, exact `0x3c` layout, vtable ownership, GDI handle lifetime, method family, and direct module placement; accepted private field names remain reconstructed rather than original-symbol-proven.
- Likely source file: [UID:0000IV][DIBitmap](by-file/DIBitmap.md), with free PCX helpers in [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Address range: [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- Current recovered file: `source-3/simroot_v2/class_DIBitmap.cpp`
- Primary vtable: [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md), backed by exact data [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) and split from aggregate [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Confirmed layout: [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)

## Class Purpose

`DIBitmap` is a compact Win32/GDI wrapper for a 16-bit top-down DIB section. It stores an embedded `BITMAPINFOHEADER`, owns the `HBITMAP`, keeps a non-owning pixel pointer returned by `CreateDIBSection`, and preserves requested dimensions separately from the aligned DIB width. It does not own or retain a DirectDraw interface, DirectDraw surface, input `HDC`, file-mapping handle, or separate pixel allocation.

## Observed State

```text
0x00  LObject/vtable base
0x04  BITMAPINFOHEADER
0x2c  HBITMAP bitmap handle
0x30  void* pixels
0x34  int width
0x38  int height
```

The final field ends at `+0x3c`. [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md) allocates literal 60 bytes before inlining construction, proving exact `sizeof(DIBitmap) == 0x3c` / 60 (Verified with `int_convert.py`). The historical generated Wave3 `0x60`/96-byte undefined-tail claim is superseded and must not shape the source declaration.

The constructor aligns width to a multiple of four pixels, stores that aligned value in `m_bmiHeader.biWidth`, and preserves requested width/height in `m_width`/`m_height`. At two bytes per pixel, row stride is `2 * alignedWidth`, divisible by eight for valid positive dimensions; this is stricter than merely saying DWORD-aligned. See [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md) for offset-level evidence.

The header is top-down (`biHeight < 0`), one-plane, 16-bpp `BI_RGB`, with no palette or bitfield masks. The PCX decoder produces RGB565 words and the factory copies them unchanged, while the DIB header itself uses the Win32 16-bpp `BI_RGB`/no-mask convention associated with RGB555. This compatibility mismatch is an observed family fact, not evidence for a hidden `BI_BITFIELDS` header.

## Ownership And Lifetime

- `DIBitmap(HDC,int,int)` borrows the HDC for one `CreateDIBSection` call and does not retain it.
- With `hSection=NULL`, GDI supplies the DIB pixel storage. `m_pBits` is a non-owning view into storage governed by `m_hBitmap`.
- `DIBitmap::~DIBitmap()` calls `DeleteObject` for a non-null handle; GDI then releases the corresponding DIB storage. No separate pixel free belongs in source.
- Constructor-side GDI failure is represented by stored API output and cleared/absent bits; the ImageLoaders factory checks `GetBits()` and deletes/rejects the object.
- `LObject` base construction/destruction, DIBitmap vptr stores, scalar deleting-destructor flags, vtable bytes, SEH/EH/security-cookie operations, and explicit base cleanup are compiler/ABI output, not handwritten class methods.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DIBitmap::DIBitmap(HDC,int,int)` | [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md) | Creates a 16-bpp top-down `BI_RGB` DIB section; emitted after this declaration at position 20. |
| `DIBitmap::~DIBitmap` non-deleting body | `0x004a1740` | Raw destructor/cleanup body; deletes the `HBITMAP` and tail-jumps to `LObject` destruction. |
| `GetBits` | `0x004a1760` | Returns the DIB section pixel pointer. |
| `GetBitmapHandle` | `0x004a1770` | Returns the `HBITMAP`. |
| `GetWidth` | `0x004a1780` | Returns zero when no pixels exist, otherwise requested width. |
| `GetHeight` | `0x004a1790` | Returns zero when no pixels exist, otherwise requested height. |
| `GetAlignedWidth` | `0x004a17a0` | Returns zero when no pixels exist, otherwise aligned DIB width from `BITMAPINFOHEADER.biWidth`. |
| `ScalarDeletingDestructor` | [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md) | Deletes the `HBITMAP`, destroys the base object, and optionally frees memory. |

## Evidence Notes

- Historical Wave3 metadata described the object as 96 bytes. That claim is superseded by the factory's exact 60-byte allocation and complete offset family; only the observation that the factory inlines construction remains valid.
- Evidence-time IDA reports no direct constructor xrefs. Exhaustive executable scans also found no direct `E8/E9` target and no stored target VA/RVA/raw-offset pointer, while `CreateDIBitmapFromPcxBuffer` contains equivalent inline construction.
- IDA MCP confirms the primary vtable at `0x00618e54` and the omitted method cluster at `0x004a1740-0x004a17ad`; current Wave3 metadata still reports `vtable_count: 0`.
- 2026-05-31 IDA MCP confirms the exact vtable data span at `0x00618e50-0x00618e60`: RTTI pointer `??_R4DIBitmap@@6B@` at `0x00618e50`, vtable symbol `??_7DIBitmap@@6B@` at `0x00618e54`, three virtual slots, and `DirectX` RTTI beginning at `0x00618e60`.
- IDA-confirmed constructor stores, destructor loads, tiny accessors, and exact factory allocation prove the compact layout through `+0x38` and exact end at `+0x3c`; the generated `0x60` size is rejected rather than retained as an open caveat.
- 2026-06-07 Batch 083 live IDA MCP `py_eval` reconfirmed the local class cluster: constructor `0x004a1600-0x004a1738`, scalar deleting destructor `0x004a1b10-0x004a1b5e`, tiny modeled accessors at `0x004a1760`, `0x004a1770`, `0x004a1780`, and `0x004a1790`, and raw/non-modeled starts at `0x004a1740` and `0x004a17a0`. The vtable at `0x00618e54` is referenced by the constructor, the PCX factory construction path, the scalar deleting destructor, and the raw destructor bytes at `0x004a1746`.
- The same recheck keeps `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer` adjacent to the class cluster while the far decode helper `0x00549410-0x00549616` has one caller from the PCX factory. This supports `DIBitmap.cpp` as the direct class parent and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) as the free-helper context rather than a competing class owner.
- 2026-06-08 Batch 116 split work adds exact constructor and scalar-deleting-destructor by-memory children. The PCX path loader and PCX-to-DIB factory are now exact sibling pages under [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), confirming this class owns only the DIB section wrapper methods inside the mixed aggregate.

## Assignment Decision

`CANONICAL_OWNER:0000IV` and `EMITTER_UIDS:0000IV` preserve the direct file route. This canonical class declaration emits at position `10`; constructor UID000313 emits at `20`; accepted destructor/accessor UID000136 emits at `30`. The free PCX decode/factory pipeline remains under ImageLoaders even though its factory constructs this class.

The historical 95/95 blank-code rule is superseded by the active combined-score/emitter gate. Exact layout, accepted field/method vocabulary, and constructor/destructor/factory evidence now support the formal declaration. `virtual ~DIBitmap()` regenerates the scalar deleting destructor and vtable mechanics; support pages must not hand-emit duplicate ABI artifacts or a second class declaration.

## Score Rationale

- Completion `92`: exact declaration, `0x3c` layout, method family/order, DIB header/alignment, GDI lifetime, factory/failure relationship, compiler artifact disposition, source split, and historical corrections are documented.
- Confidence `94`: evidence-time IDA, exact allocation, API semantics, vtable refs, and accepted sibling bodies agree. The score remains below 95 because private/member spellings and original header organization are reconstructed rather than source-symbol-proven.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md)
- [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)

## Changes

- 2026-07-12 B002 accepted DIB callback:
  - Changed `86/87 -> 92/94`, emitter position blank -> `10`, and blank formal C++ -> canonical `class DIBitmap : public LObject` declaration.
  - Proved exact `0x3c`/60-byte layout, resolved field/method names using the accepted family, documented DIB format/alignment and GDI lifetime, ordered constructor/accessor emission, and recorded compiler-generated scalar/vtable handling.
  - Historical Wave3 `0x60`/96-byte tail and 95/95 blank-code claims are preserved as explicitly superseded; ImageLoaders free-helper ownership remains unchanged.
  - Waited generated verification exposed fallback child insertion before the class closing brace. Added explicit `[[CHILDREN]]` after the closed declaration so constructor/method children emit as out-of-line definitions after the class; no C++ declaration/body content changed.

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
- 2026-06-12 A004 Batch 317 cross-reference update: added [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md) as the source-local reconstructable vtable page for this class. Scores stay `86/87`; the direct class gate already clears `85/85`.
