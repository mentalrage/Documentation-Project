*** UID:0000MA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Palette

## Status

- Confidence: strong for `DLPalette`, `PaletteLib`, `g_pPaletteLib`, palette-filter helper ownership, and the `ScreenPanePaletteState_543D30` methods being `PaletteLib`-resident; medium for the final class/facet naming.
- Proposed module: `render/Palette.cpp`
- Current recovered sources: `source-3/simroot_v2/class_DLPalette.cpp`, `class_PaletteLib.cpp`, `class_ScreenPanePaletteState_543D30.cpp`, and `ApplyPaletteEntryMovesToCollection_005435B0.cpp`
- Main code neighborhood: `0x00542ac0-0x0054445b`, ending before alignment padding and the `Pane` constructor at `0x00544460`.

## File Role

`Palette.cpp` is the best current umbrella for render palette ownership. It should contain the native 16-bit palette object, the process-wide palette manager, palette slot constants, and adjacent helper routines that clone or reset palette-slot state.

`DLPalette` owns the actual palette data: optional remap/entry data, a copied palette header, and a 256-entry native 16-bit color table. `PaletteLib` owns the runtime policy: loading `baram.pal`, category palette files, optional `SUPER0.PAL` through `SUPER6.PAL`, named lazy-loaded palettes, and source/runtime palette lists. Rendering code should request palettes through `PaletteLib` rather than opening raw `.PAL` files directly.

`ScreenPanePaletteState_543D30` is a recovered helper/facet view on the `PaletteLib` object, not a separate `ScreenPane` singleton. IDA callers pass `g_pPaletteLib` as `this`, and the `PaletteLib` constructor initializes the mode/list/bank fields used by those methods. Keep the separate class docs while Wave3 emits a separate class file, but reconstruct the code under `render/Palette.cpp` or a close `PaletteLib.cpp` split.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `DLPalette` | `0x00542ac0-0x00543149` plus `0x005443b0-0x00544411` | Native 16-bit palette data object; stream/raw/bitmap loading and color lookup. |
| `PaletteLib` | `0x005431c0-0x0054445b` | Global palette manager, category/super/named palette loader, and runtime palette-filter updater. |
| `g_pPaletteLib` | `0x0067a7e0` | Process-wide `PaletteLib*`; Wave3 type/owner are known but primary-address provenance is missing. |
| `PaletteSlotTable` constants | constructor call sites in `0x00543700` | Slot-to-file mapping for `TILE.PAL`, `ITEM.PAL`, `EFFECT.PAL`, `ALL.PAL`, `BACK.PAL`, and related sprite families. |
| `ScreenPanePaletteState_543D30` / screen-palette facet | `0x00543d30-0x00543f54` | `PaletteLib`-resident screen-level mode and 25-slot palette-bank state. |
| `ApplyPaletteEntryMovesToCollection` | `0x005435b0-0x00543665` | Applies child palette-entry move lists across a counted collection. |
| `PaletteLib` filter helpers provisional | `0x00543f60-0x005440f0` | Map-render-triggered runtime palette-filter state, raw cached-weight getter, and derived-table rebuild helpers. |

## Lower-Only Helpers To Reconcile

| Address | Current evidence | Working owner |
| --- | --- | --- |
| `0x00542fa0-0x00543020` | Real helper called only by `ScreenPanePaletteState_543D30::ResetSlots`; no active Wave3 source file. 2026-06-01 IDA MCP confirms the exact exclusive end. | Palette slot-state reset helper. |
| `0x00543450-0x00543665` | IDA-confirmed clone-list helper plus palette entry-move collection helper; `0x00543450` has no direct code xrefs in current IDA output, while `0x005435b0` is called by `ScreenPanePaletteState_543D30::ResetSlots`. | Palette list clone/move helpers; keep near `PaletteLib::LoadPaletteSet` until clone-helper use/dead-code status is proved. |
| `0x00543670-0x005436f4` | Raw function-shaped helper, not an IDA function object, that transforms paired palette collections through `dword_69B408`; no direct xrefs currently observed. | Palette collection color-transform helper candidate; keep documented but unattached until liveness is proved. |
| `0x00543f60-0x005440f0` | Real helpers called after map render paths load `g_pPaletteLib` into `ecx`, plus an unxrefed raw cached-weight getter at `0x00543f70-0x00543f77`. | `PaletteLib` palette-filter helpers, not `ScreenPanePaletteState`. |
| `0x005443a0-0x005443aa` | Constructor-unwind cleanup helper that clears `g_pPaletteLib`; only known xref is from `PaletteLib::PaletteLib` unwind metadata. | Compiler unwind cleanup artifact; document but do not model as normal source behavior. |

## Evidence Notes

- Wave3 imports `PaletteLib` as an 11-method class with effective grade 97.8 and zero missing refs.
- Wave3 imports `DLPalette` as a 12-method class with effective grade 96.9; rerun serial missing-ref query returned zero entries.
- Wave3 imports `ScreenPanePaletteState_543D30` as a two-method class with effective grade 97.8; rerun serial missing-ref query returned zero entries.
- IDA MCP lists the contiguous function neighborhood from `0x00542ac0` through `0x0054445b`, then the unrelated `Pane` constructor starts at `0x00544460`.
- IDA MCP confirms `0x00543450` deep-copies `DLPalette`-sized objects into a `List`, which supports keeping it in the palette source family even though current xrefs are absent.
- IDA MCP recheck on 2026-06-01 corrects [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md) to exact endpoints `0x00543450-0x005435a5` and `0x005435b0-0x00543665`, and splits raw helper [UID:0002R4][0x00543670-0x005436f4.PaletteCollectionColorTransformRaw](by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md).
- IDA MCP recheck on 2026-05-25 identifies `g_pPaletteLib` at `0x0067a7e0` and reports 83 data refs. Constructor/destructor/unwind code writes or clears this storage at `0x00543743`, `0x00543cfe`, and `0x005443a0`.
- IDA MCP recheck on 2026-06-01 keeps `0x00543f60` and `0x00543f80` in `PaletteLib`: every observed caller loads `g_pPaletteLib` into `ecx` before the call, `0x00543f80` calls `dword_69B408`, and raw getter-shaped bytes at `0x00543f70-0x00543f77` read the cached filter weight at `+0x75c`.
- IDA MCP recheck on 2026-05-26 shows `ScreenPane::HandleMessage` also calls `0x00543d30` and `0x00543ee0` with `g_pPaletteLib` as `this`; `PaletteLib::PaletteLib` sets `g_pPaletteLib`, initializes `+0x04` and `+0x08`, and constructs the same palette-bank arrays consumed by `ResetSlots`.
- IDA MCP recheck on 2026-06-01 corrects the `DLPalette` scalar deleting destructor endpoint to `0x00544411`, confirms the primary contiguous DLPalette method cluster ends at `0x00543149`, and confirms `0x00544411-0x00544420` is alignment before `PaletteLib::ScalarDeletingDestructor`.

## Ownership Decision

Keep `DLPalette`, `PaletteLib`, `g_pPaletteLib`, the `ScreenPanePaletteState_543D30` facet methods, the slot table, palette-filter helpers, and palette clone/reset helpers under `render/Palette.cpp`. Do not merge these into DAT/archive code: palette files are DAT-backed resources, but palette parsing, color conversion, runtime palette selection, and screen-palette bank reset policy are render/palette behavior.

## Cross-References

- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)
- [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md)
- [UID:0001E4][0x00542ac0-0x00544411.DLPalette](by-memory/0x00542ac0-0x00544411.DLPalette.md)
- [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md)
- [UID:0001E5][0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState](by-memory/0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState.md)
- [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md)
- [UID:0002R4][0x00543670-0x005436f4.PaletteCollectionColorTransformRaw](by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Before: the palette neighborhood and `PaletteLib` page ended at `0x0054445a`.
- Changed to: the `PaletteLib` page ends at `0x0054445b`; the following bytes before `Pane` are alignment padding.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054445a` is the final operand byte of the `retn 4` in `PaletteLib::ScalarDeletingDestructor`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `90`, confidence `84`.
- Summary/evidence: the page documents the umbrella palette source role, DLPalette/PaletteLib/screen-state ownership, lower-only helpers, IDA evidence, ownership decision, range correction, and cross-references; confidence remains below exhaustive because final class/facet names and exact source split are still open.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank despite the page naming `render/Palette.cpp`, and the DLPalette row used the broad aggregate `0x00542ac0-0x00544411` range.
- Changed to: proposed path is `NexusTK/render/`, and the DLPalette row now separates the primary method cluster from the scalar deleting destructor island.
- Summary/evidence: existing ownership notes already place the palette source under render; 2026-06-01 IDA MCP range review confirms `DLPalette` is non-contiguous across `0x00542ac0-0x00543149` plus `0x005443b0-0x00544411`.

- Before: the lower-only helper table listed only `0x00543450-0x005435a4` and did not split the raw helper at `0x00543670`.
- Changed to: the helper table now records `0x00543450-0x00543665` and adds raw helper `0x00543670-0x005436f4`.
- Summary/evidence: 2026-06-01 IDA MCP `lookup_funcs`, disassembly, decompilation, callers/callees, xrefs, and byte checks confirm the exact helper endpoints and padding.

- Before: the `PaletteLib` filter-helper row used the old `0x00543f60-0x005440ef` range and omitted the raw cached-weight getter.
- Changed to: the row now uses exclusive end `0x005440f0` and notes `0x00543f70-0x00543f77`.
- Summary/evidence: 2026-06-01 IDA MCP confirms `sub_543F60` at `0x00543f60-0x00543f70`, no IDA function object or direct xrefs at `0x00543f70`, `sub_543F80` at `0x00543f80-0x005440f0`, and `0xcc` padding around the helper bodies.
