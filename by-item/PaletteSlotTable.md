*** UID:0000V4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Palette Slot Table

## Status

- Confidence: strong for slot numbers and filenames loaded by `PaletteLib::PaletteLib`.
- Owner: [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- Likely source file: [UID:0000MA][Palette](by-file/Palette.md), with detail notes in [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- Current evidence: `source-3/simroot_v2/class_PaletteLib.cpp`, `0x00543700` constructor and `0x00544210` slot loader.

## Category Slots

`PaletteLib::LoadPaletteSet(slot, fileName)` loads a DAT-backed `.PAL` file into both source and runtime lists for that slot. `GetSlotPalette(slot, paletteIndex, superPaletteIndex)` selects from these lists when `superPaletteIndex == 0`.

| Slot | File | Likely consumer family |
| --- | --- | --- |
| `0` | `TILE.PAL` | map tiles |
| `1` | `TILEC.PAL` | static map objects / tile decorations |
| `2` | `EMOTION.PAL` | emotion sprites |
| `3` | `BODY.PAL` | body sprites |
| `4` | `SWORD.PAL` | sword equipment sprites |
| `5` | `SPEAR.PAL` | spear equipment sprites |
| `6` | `BOW.PAL` | bow equipment sprites |
| `7` | `FAN.PAL` | fan equipment sprites |
| `8` | `SHIELD.PAL` | shield equipment sprites |
| `9` | `MONSTER.PAL` | monster sprites |
| `10` | `ITEM.PAL` | item sprites/icons |
| `11` | `EFFECT.PAL` | effects |
| `12` | `RIDINGS.PAL` | riding/mount sprites |
| `13` | `FACE.PAL` | face sprites |
| `14` | `HAIR.PAL` | hair sprites |
| `15` | `FACEDEC.PAL` | face decoration sprites |
| `16` | `HAIRDEC.PAL` | hair decoration sprites |
| `17` | `HELMET.PAL` | helmet sprites |
| `18` | `ARROW.PAL` | arrow/projectile sprites |
| `19` | `MANTLE.PAL` | mantle/cloak sprites |
| `20` | `NECK.PAL` | neck accessory sprites |
| `21` | `SHOES.PAL` | shoes sprites |
| `22` | `COAT.PAL` | coat sprites |
| `23` | `ALL.PAL` | shared/all-family palette set |
| `24` | `BACK.PAL` | back accessory or background-attached sprites |

## Super Palettes

The constructor probes `SUPER0.PAL` through `SUPER6.PAL`. `GetSlotPalette` treats nonzero `superPaletteIndex` as a request for `superPaletteIndex - 1` in the super-palette array, bypassing the normal slot list.

## Source/Runtime Lists

Each category slot has a source list and a runtime list. `LoadPaletteSet` parses the source file into `DLPalette` objects, then creates runtime `DLPalette` clones. The active palette mode chooses between those list families, which is why rendering paths should request palettes through `PaletteLib` rather than caching raw `DLPalette*` values indefinitely.

IDA MCP recheck on 2026-05-31 confirms `PaletteLib` construction at `0x00543700-0x00543ae2`, the slot loader at `0x00544210-0x0054439f`, one constructor-family caller for the constructor, and 25 call sites from that constructor into the slot loader. The constructor/loader callees include DATFile helpers, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), palette-object/list helpers, and allocation/string helpers.

## Cross-References

- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented palette slots and filenames, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the palette-slot table as rebuild-relevant source-declared data/control flow. Parent UID and C++ remain blank until PaletteLib and palette-list ownership are final enough for autogen attachment.
  - Evidence: IDA MCP confirms the constructor and slot-loader ranges, 25 constructor call sites into the loader, and the DAT/palette helper callee set.
