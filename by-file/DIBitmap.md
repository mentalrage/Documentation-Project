*** UID:0000IV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DIBitmap And PCX Loaders

## Status

- Confidence: strong for the complete `DIBitmap` declaration/method family, exact `0x3c` layout, vtable/compiler disposition, direct source placement, and adjacent PCX factory relationship; the far decoder remains correctly split to ImageLoaders context.
- Proposed module: `NexusTK/render/DIBitmap.cpp`, with PCX free helpers documented under [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
- Current recovered sources: `source-3/simroot_v2/class_DIBitmap.cpp` and `source-3/simroot_v2/recovered/*Pcx*.cpp`
- Main address ranges: `0x004a1600-0x004a1b5e` and `0x00549410-0x00549616`
- Primary vtable: [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md), backed by exact data [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- Confirmed object layout: [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)

## File Role

`DIBitmap` is a compact `0x3c`-byte Win32/GDI device-independent bitmap wrapper used by startup/UI PCX image loading. The adjacent ImageLoaders helpers load DAT-backed PCX files, decode 8-bit PCX data into RGB565 words, construct a top-down 16-bpp `BI_RGB`/no-mask DIB section, copy rows using the DIB's four-pixel-aligned width, and return a `DIBitmap*`. RGB565 describes the decoder's packed words; the DIB header itself does not declare RGB565 bitfields.

This is render/UI image-loader support. It depends on `DATFile`/file-buffer access for the source bytes, but the image decoding and GDI bitmap ownership do not belong in `archive/DATFile.cpp`.

## Proposed Contents

| Entity | Address | Proposed placement |
| --- | --- | --- |
| `DIBitmap` constructor | [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md) | `render/DIBitmap.cpp` |
| `DIBitmap` destructor/accessors | [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md) | `render/DIBitmap.cpp` |
| `LoadPcxImage` | [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md) | See [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md); adjacent to `DIBitmap` in memory. |
| `CreateDIBitmapFromPcxBuffer` | [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md) | See [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md); allocates/constructs `DIBitmap`. |
| `DIBitmap` scalar deleting destructor | [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md) | `render/DIBitmap.cpp` |
| `DecodePcxToRgb565Buffer` | `0x00549410` | See [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md); PCX decode utility linked far from the DIB wrapper cluster. |

## Exact DIBitmap Source Unit

- [UID:00003V][DIBitmap](by-class/DIBitmap.md) emits the canonical class declaration at position `10`: `LObject` base, virtual destructor, five accessors, embedded header, HBITMAP, bits view, and requested dimensions.
- [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md) emits `DIBitmap::DIBitmap(HDC,int,int)` at position `20`, including temporary header storage, four-pixel width alignment, top-down 16-bpp `BI_RGB` setup, GDI creation, and exact member-store order.
- [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md) emits the ordinary destructor/accessors at position `30`; the accepted method bodies are preserved unchanged.
- [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md), [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md), and [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md) emit explanatory markers only. The compiler regenerates the wrapper/vtable and the class page owns the one declaration.
- The PCX loader/factory/decoder definitions are not contents of `DIBitmap.cpp`; they remain ImageLoaders-owned despite memory adjacency and constructor inlining.

## Resource Inputs

`LoadPcxImage` is currently only observed on the startup/update-check window path for assets such as `brm_main.pcx`, `brm_st_a.pcx`, `brm_st_b.pcx`, `brm_st_c.pcx`, `brm_ex_a.pcx`, and `brm_ex_b.pcx`.

## Ownership Decision

Use this page for the `DIBitmap` wrapper class and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) for the PCX free-helper pipeline. Keep the relationship explicit because the local binary layout places `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer` between the `DIBitmap` constructor/accessors and scalar deleting destructor, while `DecodePcxToRgb565Buffer` links far away and has only one confirmed caller.

The exact `DIBitmap` vtable data is now split at [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md). IDA MCP confirms the RTTI/vtable record ends before the adjacent `DirectX` RTTI at `0x00618e60`.

Historical generated output omitted the `0x004a1740-0x004a17ad` method cluster before the accepted source-quality callbacks. The canonical docs now carry the raw non-deleting destructor body, `GetBits`, `GetBitmapHandle`, guarded width/height accessors, and guarded aligned-width accessor; generated state is validator-owned and must be verified after refresh rather than asserted from that historical snapshot.

IDA confirms embedded `BITMAPINFOHEADER` at `+0x04`, bitmap handle at `+0x2c`, DIB bits at `+0x30`, and requested dimensions at `+0x34/+0x38`. The factory allocates literal 60 bytes before inline construction, proving exact object size `0x3c` / 60 (Verified with `int_convert.py`). Historical generated `0x60`/96-byte undefined-tail metadata is superseded and must not drive reconstruction.

The constructor's out-of-line entry has no IDA xrefs, direct executable `E8/E9` destination, or stored VA/RVA/raw-offset pointer. The factory's byte-for-byte-equivalent inline construction explains this liveness result while preserving the source-facing `new DIBitmap(hdc,width,height)` call. This absence is not evidence for padding or removal from source.

The input HDC is borrowed. `m_hBitmap` owns the GDI DIB section and ordinary destruction uses `DeleteObject`; `m_pBits` is a non-owning view into GDI-managed storage. Constructor-side GDI failure is left to the factory's `GetBits()` check/delete policy. No DirectDraw surface, file-mapping handle, or source global belongs to this class.

2026-06-07 Batch 083 live IDA MCP recheck reconfirmed the direct class-parent gate for [UID:00003V][DIBitmap](by-class/DIBitmap.md): constructor `0x004a1600-0x004a1738`, scalar deleting destructor `0x004a1b10-0x004a1b5e`, modeled accessors at `0x004a1760`, `0x004a1770`, `0x004a1780`, and `0x004a1790`, and raw/non-modeled starts at `0x004a1740` and `0x004a17a0`. Vtable `0x00618e54` has live code refs from the constructor, PCX factory, scalar deleting destructor, and raw destructor bytes. The far decoder at `0x00549410-0x00549616` still has a single observed caller from `CreateDIBitmapFromPcxBuffer`, so it remains documented as ImageLoaders context while this file stays the direct DIBitmap wrapper parent.

2026-06-08 Batch 116 split recheck created exact by-memory children for the DIBitmap constructor and scalar deleting destructor, while moving the adjacent PCX loader/factory helpers to exact ImageLoaders-owned children. This confirms `DIBitmap.cpp` as the direct parent for class-owned DIB section lifecycle methods and rejects it as the direct parent for the broader mixed `0x004a1600-0x004a1b5e` aggregate.

## Score Rationale

- Completion `91` covers the exact class declaration/method/compiler-support inventory, `0x3c` layout, constructor liveness/inlining, DIB header/alignment, GDI lifetime/failure policy, source ordering, and DIBitmap/ImageLoaders split.
- Confidence `92` reflects direct instruction, allocation, vtable, API, caller/factory, and project-tree agreement. It stays below final-audit quality because this file page also tracks the adjacent/far PCX relationship and exact historical header/source organization is inferred.

## Cross-References

- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000313][0x004a1600-0x004a1738.DIBitmapConstructor](by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md)
- [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- [UID:000316][0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor](by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-07-12 B002 accepted DIB file callback:
  - Changed `86/86 -> 91/92` while preserving `NexusTK/render/` and `CANONICAL_OWNER:FILE`.
  - Added the exact class/constructor/method/marker source inventory and emitter order, exact `0x3c` layout, zero-reference/inlined-constructor explanation, DIB/GDI lifetime/failure behavior, and RGB565-word versus 16-bpp-BI_RGB/no-mask distinction.
  - Historical generated method omissions and `0x60`/96-byte tail claims are retained only as labeled superseded observations; ImageLoaders ownership remains unchanged.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: DIB wrapper role, PCX helper relationship, resource inputs, ownership decision, omitted accessor cluster, layout fields, and render/archive boundaries are documented; confidence remains below maximum because final split with the far PCX decoder is still open.
- 2026-05-31 projected path and vtable child:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page referenced only the combined DIBitmap/DirectX vtable type page.
  - Changed to: proposed path `NexusTK/render/` and exact `DIBitmap` vtable-data child reference.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `DIBitmap.cpp` under `render/`; IDA MCP confirms the exact `DIBitmap` vtable bytes and adjacent `DirectX` boundary.
- 2026-06-07 A006 Batch 083:
  - Changed score from `84/82` to `85/85`.
  - Summary/evidence: live IDA MCP reconfirmed the local DIBitmap wrapper cluster, vtable reference set, PCX factory relationship, and single-caller far decode helper. Remaining uncertainty is now limited to final source split/style details rather than direct class ownership.
- 2026-06-08 A007 Batch 116:
  - Changed score from `85/85` to `86/86`.
  - Summary/evidence: exact by-memory children now document the DIBitmap constructor and scalar deleting destructor separately from the PCX loader/factory helpers, proving this file as the direct owner for class lifecycle methods while preserving [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) as the PCX helper owner.
- 2026-06-12 A004 Batch 317 cross-reference update: added [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md) as the class-owned source-local vtable page. Scores stay `86/86`; the file remains source context while the vtable routes first to [UID:00003V][DIBitmap](by-class/DIBitmap.md).
