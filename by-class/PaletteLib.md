*** UID:0000A1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PaletteLib

## Status

- Confidence: strong for method roles, resource ownership, singleton storage, palette-filter helper ownership, and source-family placement; medium-high for final field names and the exact `Palette.cpp` versus `PaletteLib.cpp` split.
- Source file: [UID:0000MB][PaletteLib](by-file/PaletteLib.md), under the broader [UID:0000MA][Palette](by-file/Palette.md) umbrella
- Address ranges: [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md), with lower-only palette-filter helpers at [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_PaletteLib.cpp`

## Class Purpose

`PaletteLib` is the global palette service behind `g_pPaletteLib`. Rendering callers use it to resolve a named `.PAL` file, retrieve the current base palette, or select a palette from a numbered asset-family slot.

It depends on `DATFile` for DAT-backed palette stream reads, but owns palette policy and should be reconstructed under render/palette ownership.

## Observed State

```text
PaletteLib
  +0x00  LObject/vtable
  +0x04  screen-palette mode / filter-state field
  +0x08  List* loadedNamedPalettes / paletteBuckets / screen-palette slot-state list
          embedded DLPalette base palettes
          List* sourcePaletteSets[25]
          List* runtimePaletteSets[25]
          active palette mode byte
          palette-filter enable byte / cached filter weight near +0x758/+0x75c
          embedded DLPalette super/reserved palette arrays[7]
```

The exact offsets after `+0x08` need a field-layout pass. Generated overlays consistently show 25 source palette lists, 25 runtime palette lists, an active-mode byte, and seven source/runtime super palettes.

2026-05-26 IDA MCP recheck shows `ScreenPanePaletteState_543D30::SetMode` at `0x00543d30` and `ResetSlots` at `0x00543ee0` are invoked with `g_pPaletteLib` / `dword_67A7E0` as `this`. `PaletteLib::PaletteLib` initializes the same fields at `+0x04`, `+0x08`, and the 25-entry banks at `+0x690`/`+0x6f4`. Treat the recovered `ScreenPanePaletteState_543D30` class as a `PaletteLib`-resident facet/base helper, not as an independent singleton or a `ScreenPane.cpp`-owned object.

[UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md) is now attached to [UID:0000MB][PaletteLib](by-file/PaletteLib.md) and carries the exact aggregate function inventory, non-contiguous `DLPalette` destructor caveat, screen-palette facet routing, filter-helper split, singleton lifecycle, and `g_pPaletteLib` storage evidence. The class parent can follow the same focused source owner because both the class page and the file page are above the 80/80 attachment gate after this refresh.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ResolvePaletteIndex` | `0x005431c0` | Lazy-loads a named palette file, stores `{name, DLPalette*}` in the loaded palette list, and returns the new index. |
| `ParsePaletteDataFile` | `0x00543310` | Opens a DAT-backed palette set, reads an entry count, constructs `DLPalette` objects from the stream, and returns a list. |
| `PaletteLib::PaletteLib` | `0x00543700` | Bootstraps the singleton and preloads base, category, and optional super palettes. |
| `PaletteLib::~PaletteLib` | `0x00543af0` | Releases loaded named palettes, source/runtime slot lists, embedded palette arrays, and clears `g_pPaletteLib`. |
| `IsPaletteFilterEnabled` | `0x00543d20` | Returns a small palette-mode/filter flag at object offset `+0x04`; field name still needs care because of the `LObject` base. |
| `SetScreenPaletteMode` / `ScreenPanePaletteState_543D30::SetMode` | `0x00543d30` | Stores the screen-palette mode/filter-state value at `+0x04`; current generated output emits it as a separate helper class. |
| `GetCurrentPalette` | `0x00543d40` | Returns the source or runtime base palette depending on active palette mode. |
| `GetPaletteByName` | `0x00543d70` | Finds an already loaded named palette or lazy-loads it; falls back to current palette on failure. |
| `GetSlotPalette` | `0x00543e40` | Returns a slot palette by asset-family slot and palette index, or a super palette when `superPaletteIndex` is nonzero. |
| `ResetScreenPaletteSlots` / `ScreenPanePaletteState_543D30::ResetSlots` | `0x00543ee0` | Resets child slot states and reapplies one of the two 25-entry palette banks. Current generated output emits it as a separate helper class. |
| `SetPaletteFilterEnabled` provisional | `0x00543f60` | Stores the runtime palette-filter enable byte at `+0x758`. |
| raw cached-filter-weight getter | `0x00543f70` | Loads the cached filter weight at `+0x75c`; no observed direct xrefs in current IDA. |
| `UpdatePaletteFilterTables` provisional | `0x00543f80` | Rebuilds transformed base/super/runtime slot lookup tables from a float weight and the global color-transform callback. |
| `LoadPaletteSet` | `0x00544210` | Loads a category `.PAL` file into the source slot list and clones it into a runtime slot list. |
| constructor-unwind global clear | `0x005443a0` | Clears `g_pPaletteLib`; only referenced from constructor unwind metadata, not normal source flow. |
| `ScalarDeletingDestructor` | `0x00544420` | Calls the destructor and optionally deletes `this`. |

## Slot Mapping

See [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). The constructor loads slots for `TILE.PAL`, `TILEC.PAL`, `BODY.PAL`, `ITEM.PAL`, `EFFECT.PAL`, `ALL.PAL`, `BACK.PAL`, and the other avatar/object families.

## Parent And Score Rationale

| Topic | Rationale |
| --- | --- |
| Source parent | [UID:0000MB][PaletteLib](by-file/PaletteLib.md) is scored `86/80`, has the focused `NexusTK/render/` path, and owns the singleton lifecycle, startup role, and `PaletteLib`/`DLPalette` dependency notes. |
| Umbrella source | [UID:0000MA][Palette](by-file/Palette.md) remains the stronger umbrella page for the whole render palette family, but [UID:0000MB][PaletteLib](by-file/PaletteLib.md) is the narrower autogen parent used by the main memory aggregate and singleton. |
| Exact executable evidence | [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md) records exact method ranges, screen-palette facet ownership, filter-helper boundaries, and the non-contiguous `DLPalette` destructor caveat. |
| Singleton evidence | [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) is attached to [UID:0000MB][PaletteLib](by-file/PaletteLib.md) and documents the `0x0067a7e0` storage, constructor publish, destructor clear, unwind clear, and broad consumer fanout. |
| Remaining blockers | Final field names after `+0x08`, the `+0x758` and `+0x75c` filter fields, and the final source split between `Palette.cpp`, `PaletteLib.cpp`, and `DLPalette.cpp` are still below final-source quality, so C++ stays blank. |

## Cross-References

- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)
- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-06 A008:
  - Before: confidence was `78` and `AUTOGEN_PARENT_UID` was blank because the class had not been reconciled with the newer focused [UID:0000MB][PaletteLib](by-file/PaletteLib.md) parent and attached memory/global pages.
  - After: changed confidence to `82`, attached the class to [UID:0000MB][PaletteLib](by-file/PaletteLib.md), and added parent/score rationale while keeping completion at `84`.
  - Evidence: [UID:0000MB][PaletteLib](by-file/PaletteLib.md) is `86/80` with a focused render path; [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md) is attached there and documents exact method ranges, screen-palette facet routing, filter helpers, singleton lifecycle, and source split caveats; [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) documents the exact singleton storage and lifecycle.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed named-palette, DAT parse, constructor/destructor, current/slot palette, filter, load-set, singleton-clear, and scalar-deleting starts at `0x005431c0`, `0x00543310`, `0x00543700`, `0x00543af0`, `0x00543d20`, `0x00543d30`, `0x00543d40`, `0x00543d70`, `0x00543e40`, `0x00543ee0`, `0x00543f60`, `0x00543f80`, `0x00544210`, `0x005443a0`, and `0x00544420`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate; `0x00543f70` remains raw getter bytes rather than an IDA function start and is not used as proof.
- Before: the `PaletteLib` memory page reference ended at `0x0054445a`.
- Changed to: the page ends at `0x0054445b`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054445a` is the final operand byte of the scalar deleting destructor's `retn 4`.
- Before: completion/confidence metadata were `0/0` despite detailed method roles, singleton/resource ownership, observed state, slot mapping, and palette-filter helper evidence.
- Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
- Evidence: constructor/destructor, named palette loading, DAT palette parsing, current/slot palette lookup, screen-palette mode/reset helpers, filter-table helpers, singleton storage, and source-file split are documented; confidence remains medium-high because final field offsets and names still need a focused layout pass.
