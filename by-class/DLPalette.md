*** UID:00003Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DLPalette

## Status

- Confidence: strong for stream format behavior and class role, medium for exact field names.
- Likely source file: [UID:0000MA][Palette](by-file/Palette.md), with detail notes in [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- Address ranges: [UID:0001E4][0x00542ac0-0x00544411.DLPalette](by-memory/0x00542ac0-0x00544411.DLPalette.md)
- Current recovered file: `source-3/simroot_v2/class_DLPalette.cpp`

## Class Purpose

`DLPalette` is the 16-bit color palette object used by sprite, tile, text, and UI rendering. It can be constructed empty, copied from existing palette data, loaded from a DAT-backed stream/file, loaded from raw RGBA, or loaded from a bitmap palette.

`PaletteLib` owns most long-lived instances, while rendering helpers consume `DLPalette` through lookup and color-mapping calls.

## Observed Layout

```text
DLPalette
  +0x00  LObject/vtable
  +0x04  uint16* entry/remap data
  +0x08  uint32 entryCount
  +0x0c  0x20-byte palette header block
  +0x2c  uint16 mappedColors[256]
```

Generated overlays name `mappedColors` at offset `0x2c`, which matches the first 44 bytes of object/header state followed by a 512-byte 16-bit lookup table.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapColor` | `0x00542ac0` | Returns `mappedColors[index]`, or zero for indexes outside 0..255. |
| `SetColor` | `0x00542ae0` | Converts RGB components to the native 16-bit color and stores the packed value. |
| `SetPackedColor` | `0x00542b50` | Stores an already packed 16-bit color. |
| `DLPalette::DLPalette` | `0x00542bb0` | Constructs an empty palette object. |
| `DLPalette::DLPalette(const DLPaletteData*)` | `0x00542be0` | Copies header/remap data and the 256-entry color lookup table. |
| `DLPalette::~DLPalette` | `0x00542ca0` | Frees optional entry/remap data and chains to `LObject`. |
| `FreePaletteData` | `0x00542cd0` | Clears entry count and frees optional entry/remap data without destroying the object. |
| `LoadFromFile` | `0x00542df0` | Opens a path through `DATFile`, loads from stream, then closes. |
| `LoadFromStream` | `0x00542e60` | Reads a palette header, optional entry data, and 256 RGBX colors, then converts them into 16-bit colors. |
| `LoadFromRawRGBA` | `0x00543020` | Stamps a `DLPalette` header and builds a lookup table from 256 raw RGBA/BGRA-style entries. |
| `LoadFromBitmapPalette` | `0x005430a0` | Extracts and converts a 256-entry bitmap palette. |
| `ScalarDeletingDestructor` | `0x005443b0-0x00544411` | Destructor glue placed near the `PaletteLib` scalar-deleting destructor. |

## Stream Format Notes

`LoadFromStream` reads a 0x20-byte header, uses a header dword as the optional entry/remap count, reads two bytes per optional entry, then reads 0x400 bytes of RGBX palette data. It converts 256 entries into native 16-bit colors, forces palette index 0 to transparent, and replaces other zero-valued colors with a default color that depends on `g_isHighColor`.

## IDA MCP Boundary Notes

2026-06-01 IDA MCP recheck records the primary DLPalette method cluster as `0x00542ac0-0x00543149` and the scalar deleting destructor island as `0x005443b0-0x00544411`. The physically adjacent helper [UID:0001E5][0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState](by-memory/0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState.md) sits between DLPalette loaders but is called by the screen-palette reset path, so it remains palette-family support rather than a DLPalette method.

## Cross-References

- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/84`.
  - Summary/evidence: palette purpose, observed layout, constructors/loaders/accessors/destructor methods, stream format, PaletteLib relationship, and DAT format links are documented; remaining uncertainty is mostly exact original field names.

- 2026-06-01:
  - Before: reconstructable/autogen parent metadata was blank and scalar deleting destructor endpoint was still documented as the stale `0x00544410` end through the memory-page link.
  - After: marked reconstructable under [UID:0000MA][Palette](by-file/Palette.md), raised to `82/86`, and recorded the exact `0x005443b0-0x00544411` scalar deleting destructor end.
  - Summary/evidence: IDA MCP `idautils.Functions`, `lookup_funcs`, decompilation, and byte checks confirmed the DLPalette method cluster, scalar deleting destructor island, contained slot-state helper boundary, and alignment padding.
