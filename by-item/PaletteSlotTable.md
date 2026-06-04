*** UID:0000V4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Palette Slot Table

## Status

- Confidence: very strong for slot numbers, filenames, constructor call sites, and `Palette` parent placement; medium-high for final source-facing constant/table spelling.
- Parent attachment: attached to [UID:0000MA][Palette](by-file/Palette.md), whose current confidence is `84`.
- Owner: [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- Source file: [UID:0000MA][Palette](by-file/Palette.md), with detail notes in [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- Current evidence: live IDA MCP lookup, decompilation, xref, and UTF-16LE `.rdata` scans on 2026-06-04.
- Reconstruction note: C++ intentionally remains blank because the original spelling of the slot enum/table and source split is not at the `95/95` gate.

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

## Live IDA Evidence

- 2026-06-04 IDA MCP confirms `PaletteLib::PaletteLib` is `0x00543700-0x00543ae2` and has one direct constructor caller at `0x004f61bb` in `0x004f5fb0`.
- 2026-06-04 IDA MCP confirms `PaletteLib::LoadPaletteSet` is `0x00544210-0x0054439f` and has exactly 25 direct call sites, all from the constructor at `0x00543900-0x00543a50`.
- 2026-06-04 constructor decompilation shows each call passes a constant slot number and a wide filename literal. The call order is not numerically sorted, but the slot argument binds the filename to the slot.
- 2026-06-04 UTF-16LE `.rdata` scan over [UID:000262][0x0062179c-0x006219e8.PaletteReadOnlyData](by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) confirms `baram.pal` at `0x006217c4` plus the 25 slot filenames from `TILE.PAL` at `0x006217d8` through `BACK.PAL` at `0x006219d0`, each with a constructor xref.
- `LoadPaletteSet` stores the parsed source list at `this[slot + 420]`, clones each `DLPalette` into a runtime list, and stores that list at `this[slot + 445]`, matching the source/runtime list explanation above.

## Cross-References

- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-04: Raised from `70/85` to `84/90` and attached to [UID:0000MA][Palette](by-file/Palette.md).
  - Before: the page had the slot map, but parent attachment was blank and the evidence was not solely IDA-backed.
  - After: the page records live IDA constructor/loader boundaries, the 25 direct loader calls, exact UTF-16LE `.rdata` filename addresses/xrefs, source/runtime list storage behavior, and parent attachment rationale.
  - Evidence: IDA MCP decompilation for `0x00543700` and `0x00544210`, `py_eval` xref enumeration for the 25 loader calls, UTF-16LE scan of `0x006217c4-0x006219d0`, and [UID:0000MA][Palette](by-file/Palette.md) confidence `84`.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented palette slots and filenames, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the palette-slot table as rebuild-relevant source-declared data/control flow. Parent UID and C++ remain blank until PaletteLib and palette-list ownership are final enough for autogen attachment.
  - Evidence: IDA MCP confirms the constructor and slot-loader ranges, 25 constructor call sites into the loader, and the DAT/palette helper callee set.
