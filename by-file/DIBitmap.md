*** UID:0000IV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DIBitmap And PCX Loaders

## Status

- Confidence: strong for `DIBitmap` behavior and adjacent PCX helper ownership, medium for exact final file split with the far PCX decoder.
- Proposed module: `NexusTK/render/DIBitmap.cpp`, with PCX free helpers documented under [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
- Current recovered sources: `source-3/simroot_v2/class_DIBitmap.cpp` and `source-3/simroot_v2/recovered/*Pcx*.cpp`
- Main address ranges: `0x004a1600-0x004a1b5d` and `0x00549410-0x00549616`
- Primary vtable: [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md), summarized by [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Confirmed object layout: [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)

## File Role

`DIBitmap` is a Win32 device-independent bitmap wrapper used by startup/UI PCX image loading. The adjacent helpers load DAT-backed PCX files, decode 8-bit PCX data into RGB565 pixels, construct a 16-bit top-down DIB section, copy decoded rows using the DIB's aligned stride, and return a `DIBitmap*`.

This is render/UI image-loader support. It depends on `DATFile`/file-buffer access for the source bytes, but the image decoding and GDI bitmap ownership do not belong in `archive/DATFile.cpp`.

## Proposed Contents

| Entity | Address | Proposed placement |
| --- | --- | --- |
| `DIBitmap` | `0x004a1600`, `0x004a1740-0x004a17ac`, `0x004a1b10` | `render/DIBitmap.cpp` |
| `LoadPcxImage` | `0x004a17b0` | See [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md); adjacent to `DIBitmap` in memory. |
| `CreateDIBitmapFromPcxBuffer` | `0x004a18b0` | See [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md); allocates/constructs `DIBitmap`. |
| `DecodePcxToRgb565Buffer` | `0x00549410` | See [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md); PCX decode utility linked far from the DIB wrapper cluster. |

## Resource Inputs

`LoadPcxImage` is currently only observed on the startup/update-check window path for assets such as `brm_main.pcx`, `brm_st_a.pcx`, `brm_st_b.pcx`, `brm_st_c.pcx`, `brm_ex_a.pcx`, and `brm_ex_b.pcx`.

## Ownership Decision

Use this page for the `DIBitmap` wrapper class and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) for the PCX free-helper pipeline. Keep the relationship explicit because the local binary layout places `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer` between the `DIBitmap` constructor/accessors and scalar deleting destructor, while `DecodePcxToRgb565Buffer` links far away and has only one confirmed caller.

The exact `DIBitmap` vtable data is now split at [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md). IDA MCP confirms the RTTI/vtable record ends before the adjacent `DirectX` RTTI at `0x00618e60`.

IDA confirms a small `DIBitmap` method cluster at `0x004a1740-0x004a17ac` that the active generated source currently omits: a raw non-deleting destructor body, `GetBits`, `GetBitmapHandle`, guarded width/height accessors, and a guarded aligned-width accessor.

IDA also confirms the compact field layout used by that cluster and the constructor: embedded `BITMAPINFOHEADER` at `+0x04`, bitmap handle at `+0x2c`, DIB bits at `+0x30`, and requested dimensions at `+0x34/+0x38`. The current generated metadata's `0x60` struct size and undefined byte fields should not drive source reconstruction without more binary evidence.

## Cross-References

- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000136][0x004a1740-0x004a17ac.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ac.DIBitmapDestructorAndAccessors.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: DIB wrapper role, PCX helper relationship, resource inputs, ownership decision, omitted accessor cluster, layout fields, and render/archive boundaries are documented; confidence remains below maximum because final split with the far PCX decoder is still open.
- 2026-05-31 projected path and vtable child:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page referenced only the combined DIBitmap/DirectX vtable type page.
  - Changed to: proposed path `NexusTK/render/` and exact `DIBitmap` vtable-data child reference.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `DIBitmap.cpp` under `render/`; IDA MCP confirms the exact `DIBitmap` vtable bytes and adjacent `DirectX` boundary.
