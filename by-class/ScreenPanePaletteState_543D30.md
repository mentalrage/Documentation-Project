*** UID:0000CC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenPanePaletteState_543D30

## Status

- Confidence: very strong that this recovered spelling is a historical alias rather than an independent source class; exact method behavior, caller contexts, PaletteLib receiver/layout, bank offsets, and focused source route are closed.
- Source disposition: no class/file emitter. [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md) emits both bodies as `PaletteLib` methods through focused [UID:0000MB][PaletteLib](by-file/PaletteLib.md); broad [UID:0000MA][Palette](by-file/Palette.md) is helper support only.
- Address ranges: [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md)

## Class Purpose

`ScreenPanePaletteState_543D30` is retained only as a historical recovered search alias for two ordinary [UID:0000A1][PaletteLib](by-class/PaletteLib.md) methods. Live IDA evidence shows every caller passes `g_pPaletteLib` as `this` when switching mode and resetting one of two 25-slot palette banks. No construction, vtable, storage, RTTI, size, or independent receiver supports a source class/facet/helper declaration.

## Observed Layout

```text
PaletteLib
  +0x000 LObject / primary vptr
  +0x004 int m_screenPaletteMode
  +0x008 List *m_loadedPalettes
  +0x690 List *m_sourcePaletteSets[25]
  +0x6f4 List *m_runtimePaletteSets[25]
  ... exact object end +0x25c8
```

The `ResetSlots` method chooses `slotBankA` or `slotBankB` by reading a config byte from `g_pConfig + 0x28de5e`. Before the 25-entry bank loop, it walks the list at `+0x08` and calls [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) on the `DLPalette *` reached from each returned list entry at `+0x04`. `PaletteLib::LoadPaletteSlot` (`0x00544210-0x0054439f`) populates the same `+0x690` and `+0x6f4` tables while the constructor calls it for palette ids `0..24`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Historical `SetMode`; current `PaletteLib::SetScreenPaletteMode` | `0x00543d30-0x00543d3d` | Stores a mode value at object offset `+0x04`, returns with `retn 4`, exact SHA256 `DE8F7DA299F04A4488AFC2EB5581093BE8A8C778C1BFA0A2FF76D4F1B6FCEC1E`. |
| Historical `ResetSlots`; current `PaletteLib::ResetScreenPaletteSlots` | `0x00543ee0-0x00543f55` | Reverse-walks loaded records, applies each child `DLPalette` move table, selects a 25-list bank from Config, and applies collection moves; exact SHA256 `729B504AE82D630888B527FC3766A9377785C1D6DA5F34248AD9D2A6CDD711FA`. |

## B001 UID00028T Historical-Alias Disposition - 2026-07-20

- All four setter callers (`0x00556dcb`, `0x00556e0f`, `0x005593c0`, `0x00559405`) and both reset callers (`0x00556dd2`, `0x005593c7`) pass global `g_pPaletteLib`; none refers to a separate object.
- PaletteLib construction initializes the same `+0x04`, `+0x08`, `+0x690`, and `+0x6f4` fields. Complete RTTI contains `PaletteLib`, `LObject`, and `Singleton<PaletteLib>` only; no `ScreenPanePaletteState_543D30` RTTI or vtable exists.
- `PaletteLibLoadedEntry` is eight bytes with name at `+0x00` and palette pointer at `+0x04`. Reset walks `m_loadedPalettes` backward without guards, invokes `DLPalette::ApplyPaletteEntryMoves`, tests `g_pConfig->m_shadowEnabled`, and processes exactly 25 source or runtime lists through free `ApplyPaletteEntryMovesToCollection`.
- Exact source ownership is UID0000A1/UID0000MB. This alias remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitter, position, and formal C++; it must not generate a class declaration, independent file, duplicate method body, or broad recovered-class source.
- Historical facet/base/helper, standalone ScreenPane source, broad Palette emitter, and unresolved naming alternatives are rejected by receiver identity, complete layout, all callers, and the exact destination bodies. The old name is retained only for provenance and searches.

## Evidence Notes

- 2026-06-04 live IDA MCP recheck on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms `sub_543D30` as `0x00543d30-0x00543d3d` and `sub_543EE0` as `0x00543ee0-0x00543f55`.
- `SetMode` disassembly loads the single argument and writes it to `[ecx+0x04]`; live callers are `0x00556dcb`, `0x00556e0f`, `0x005593c0`, and `0x00559405`.
- `ResetSlots` walks the list pointer at `[this+0x08]` backwards, calls the child virtual accessor at vtable slot `+0x10`, loads the `DLPalette *` from the returned entry at `+0x04`, then calls [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md).
- `ResetSlots` tests `byte ptr [g_pConfig+0x28de5e]`; the nonzero branch iterates 25 dword entries from `[this+0x690]`, and the zero branch iterates 25 dword entries from `[this+0x6f4]`, with both branches calling [UID:0003LT][0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection](by-memory/0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection.md) at `0x005435b0`.
- `ScreenPane::HandleMessage` / `sub_556d50` loads `dword_67A7E0` / [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md), calls `SetMode(1)`, calls `ResetSlots`, refreshes the active child pane through `dword_67A764`, optionally calls the root update helper through `dword_67A874`, then calls `SetMode(0)`.
- The raw `0x005593c0-0x0055940b` block is not modeled as an IDA function, but live disassembly shows the same `g_pPaletteLib` refresh sequence as the modeled `ScreenPane::HandleMessage` branch.
- `PaletteLib::PaletteLib` at `0x00543700-0x00543ae2` stores `dword_67A7E0`, zeroes field `+0x04`, allocates/stores the list at `+0x08`, and calls `0x00544210` for palette ids `0..24`; `0x00544210` stores loaded collections into `[this+index*4+0x690]` and `[this+index*4+0x6f4]`.

## Excluded Adjacent Helpers

`0x00543f60` and `0x00543f80` were previously suspected to be lower-only methods on this helper because they sit immediately after `ResetSlots`. They also operate on `g_pPaletteLib`, but their offsets and callers identify them as [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md), not part of the `SetMode`/`ResetSlots` screen-palette reset facet.

## Cross-References

- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md)
- [UID:0003LT][0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection](by-memory/0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-07-20 B001 UID00028T callback: raised documentation quality to `90/94`; preserved NONE/FALSE/blank emitter/position/formal; made the recovered name definitively historical, synchronized exact current PaletteLib method names/hashes/receiver/layout/callers/list/config/bank behavior, and rejected standalone class/file/duplicate emission without removing earlier evidence.
- 2026-06-05: Changed autogen reconstructability from blank to `FALSE`.
  - Before: the page documented this as a recovered PaletteLib-resident facet/helper, but blank metadata left it unclassified in `-ag-class-coverage.md`.
  - After: no standalone class declaration is emitted from this recovered name; any source representation should stay folded into [UID:0000A1][PaletteLib](by-class/PaletteLib.md), [UID:0000MA][Palette](by-file/Palette.md), or [UID:0000MB][PaletteLib](by-file/PaletteLib.md) until a real original type name is proven.
  - Evidence: live IDA MCP on 2026-06-05 confirms `sub_543D30` at `0x00543d30` (`0xd` bytes), `sub_543EE0` at `0x00543ee0` (`0x75` bytes), and callers from `sub_556D50`, matching the documented `g_pPaletteLib` reset facet rather than an independently reconstructable class.
- 2026-05-30: Changed completion/confidence from `0/0` to `76/76`.
  - Before: The page was unevaluated despite documenting the two imported methods, observed layout, PaletteLib ownership, excluded adjacent helpers, and caller evidence.
  - After: Scored as moderate-high completion and confidence because behavior and ownership are strong, while final class/facet naming remains uncertain.
  - Evidence: Existing layout notes, method notes, IDA caller evidence, PaletteLib constructor relationship, and excluded-helper section support the score.
- 2026-06-04: Changed completion/confidence from `76/76` to `84/88`.
  - Before: The page still depended on stale recovered-source wording and older caller notes, and it did not document exact IDA extents, ResetSlots loop details, or how the `+0x690/+0x6f4` tables are populated.
  - After: Scored higher because live IDA confirms the two method bodies, all direct callers, the `g_pPaletteLib` call sequence, the child-slot and collection helper callees, the config-selected 25-entry bank loops, and the `PaletteLib` constructor/load-slot path that fills the bank-table offsets.
  - Remaining uncertainty: the page stays below final reconstruction confidence because `ScreenPanePaletteState_543D30` is still a recovered facet name rather than a proven original C++ type name.
- 2026-06-12 A001 reference refresh:
  - Before: the `ResetSlots` evidence pointed at mixed aggregate [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md) for the `0x005435b0` calls.
  - After: the same evidence points at exact child [UID:0003LT][0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection](by-memory/0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection.md), created after live IDA reconfirmed the helper-pair split and internal padding.
- 2026-06-25 B014 reset-callee sync:
  - Score unchanged.
  - Updated the first `ResetSlots` callee to [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md), a `DLPalette` method reached through the list entry's `+0x04` pointer.
  - Evidence: accepted B014 report rejects the old standalone slot-state type because the callee's receiver fields match DLPalette loader/copy/raw-RGBA layout.
