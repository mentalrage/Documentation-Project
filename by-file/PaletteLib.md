*** UID:0000MB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PaletteLib

## Status

- Confidence: strong for class roles, palette-slot loading, global singleton storage, and palette-filter helper ownership; medium for exact original filename split.
- Proposed module: [UID:0000MA][Palette](by-file/Palette.md), either as `render/Palette.cpp` or a small `render/palette/` pair containing `PaletteLib.cpp` and `DLPalette.cpp`.
- Current recovered sources: `source-3/simroot_v2/class_PaletteLib.cpp` and `source-3/simroot_v2/class_DLPalette.cpp`.
- Main ranges: `0x005431c0-0x0054445b` for `PaletteLib` methods, including lower-only filter helpers at `0x00543f60-0x005440f0`, and `0x00542ac0-0x00543149` plus `0x005443b0-0x00544411` for `DLPalette`.
- Primary global instance: `g_pPaletteLib` at `0x0067a7e0`.

## File Role

`PaletteLib` is the process-wide palette manager used by sprite, tile, UI, and image-control rendering. It owns named palette loading, per-asset-family palette slots, source/runtime palette lists, base palettes, and optional `SUPER0.PAL` through `SUPER6.PAL` palettes.

`DLPalette` is the data object used by `PaletteLib`: it reads DAT-backed palette streams, stores optional remap entries, converts RGB palette data to the client native 16-bit color lookup table, and exposes simple color lookup/set helpers.

These two classes should stay together during file-ownership reconstruction. `PaletteLib` constructs and destroys many embedded `DLPalette` objects, calls `DLPalette::LoadFromStream` during bootstrap, and clones `DLPalette` instances when building runtime palette sets. A later source split into `DLPalette.cpp` is plausible, but this is render/palette code, not raw DAT archive ownership.

Adjacent code also contains [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md), a recovered screen-palette-state facet over the same `PaletteLib` object. A 2026-05-26 IDA recheck shows its two imported methods are called with `g_pPaletteLib` as `this`, and `PaletteLib::PaletteLib` initializes the fields they use. Keep the separate docs while generated output still emits `class_ScreenPanePaletteState_543D30.cpp`, but reconstruct it under the palette manager source family rather than as a standalone screen object.

## Startup And Ownership

Wave3 xrefs show `PaletteLib::PaletteLib` has one executable caller, `Application::Startup` / `sub_4F5FB0`, with the IDA call at `0x004f61bb`. The startup path allocates a large `PaletteLib` object (`0x25c8` bytes in the recovered application metadata), constructs it after the major image libraries and `MetaMan`, and later shutdown paths destroy `g_pPaletteLib` through its vtable.

The constructor:

- chains to `LObject`;
- sets `g_pPaletteLib = this`;
- installs the `PaletteLib` vtable;
- resets three embedded base palettes from `baram.pal`;
- constructs super/reserved palette arrays;
- allocates a `List(8, 10)` for loaded named palettes;
- loads 25 category palette files into indexed slots;
- probes `SUPER0.PAL` through `SUPER6.PAL` and loads present super palettes.

The destructor clears `g_pPaletteLib`. The tiny helper at `0x005443a0` also clears the global, but IDA only references it from constructor unwind metadata, so treat it as cleanup support rather than a normal source method.

## Likely Original Source Group

```text
render/Palette.cpp
  class DLPalette
  class PaletteLib
  PaletteLib runtime palette-filter helpers
  PaletteLib screen-palette-state facet/base helper
  struct LoadedPaletteEntry
  Palette slot constants / file-name table
  g_pPaletteLib
```

The current generated one-class files are staging artifacts. The palette manager's file should cross-reference EPF/image rendering modules because consumers frequently combine `g_pEPFLib` frame lookup with `g_pPaletteLib` palette selection. See [UID:0000MA][Palette](by-file/Palette.md) for the higher-level original-source grouping and the lower-only helper caveats around `0x00542fa0`, `0x00543450`, and `0x005443a0`.

## Cross-References

- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md)
- [UID:0001E4][0x00542ac0-0x00544411.DLPalette](by-memory/0x00542ac0-0x00544411.DLPalette.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md)
- [UID:0002R4][0x00543670-0x005436f4.PaletteCollectionColorTransformRaw](by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Before: the `PaletteLib` memory page ended at `0x0054445a`.
- Changed to: the page ends at `0x0054445b`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054445a` is the final operand byte of the `retn 4` in `PaletteLib::ScalarDeletingDestructor`; `0x0054445b-0x00544460` is alignment padding.

- Before: the related DLPalette range summary ended the primary DLPalette cluster at `0x00543148`.
- Changed to: the related DLPalette range summary now ends the primary cluster at `0x00543149`.
- Summary/evidence: 2026-06-01 IDA MCP `idautils.Functions` reports `DLPalette::LoadFromBitmapPalette` as `0x005430a0-0x00543149`; the following bytes through `0x005431c0` are alignment before `PaletteLib::ResolvePaletteIndex`.

- Before: the filter-helper cross-reference used the old inclusive-style `0x00543f60-0x005440ef` range.
- Changed to: the range is now `0x00543f60-0x005440f0` and includes the unxrefed raw cached-weight getter at `0x00543f70-0x00543f77`.
- Summary/evidence: 2026-06-01 IDA MCP boundary and byte checks confirm `sub_543F60`, raw getter bytes, `sub_543F80`, and the intervening `0xcc` padding.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents class roles, startup ownership, likely source group, singleton behavior, Palette umbrella relationship, range correction, and cross-references; confidence remains capped by exact original split between `Palette.cpp`, `PaletteLib.cpp`, and `DLPalette.cpp`.
