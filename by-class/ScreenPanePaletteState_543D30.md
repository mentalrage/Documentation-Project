*** UID:0000CC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenPanePaletteState_543D30

## Status

- Confidence: strong for method behavior, `PaletteLib`-resident ownership, caller contexts, and bank-table offsets; medium only for final source-facing facet name.
- Likely source file: [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md), with focused notes in [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md).
- Address ranges: [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md)

## Class Purpose

`ScreenPanePaletteState_543D30` tracks screen-level palette bank state as a recovered `PaletteLib`-resident facet/helper. Live IDA evidence shows `ScreenPane::HandleMessage` passes `g_pPaletteLib` as `this` when switching mode and resetting one of two 25-slot palette banks.

## Observed Layout

```text
ScreenPanePaletteState_543D30
  +0x00  unknown / object header
  +0x04  int mode
  +0x08  List* slotList
  +0x690 int* slotBankA[25]
  +0x6f4 int* slotBankB[25]
```

The `ResetSlots` method chooses `slotBankA` or `slotBankB` by reading a config byte from `g_pConfig + 0x28de5e`, then applies a palette-entry helper to each of the 25 entries. `PaletteLib::LoadPaletteSlot` (`0x00544210-0x0054439f`) populates the same `+0x690` and `+0x6f4` tables while the constructor calls it for palette ids `0..24`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetMode` | `0x00543d30-0x00543d3d` | Stores a mode value at object offset `+0x04` and returns with `retn 4`. |
| `ResetSlots` | `0x00543ee0-0x00543f55` | Resets child slot states, chooses a 25-entry palette bank from config, and applies palette-entry moves to each collection. |

## Evidence Notes

- 2026-06-04 live IDA MCP recheck on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms `sub_543D30` as `0x00543d30-0x00543d3d` and `sub_543EE0` as `0x00543ee0-0x00543f55`.
- `SetMode` disassembly loads the single argument and writes it to `[ecx+0x04]`; live callers are `0x00556dcb`, `0x00556e0f`, `0x005593c0`, and `0x00559405`.
- `ResetSlots` walks the list pointer at `[this+0x08]` backwards, calls the child virtual accessor at vtable slot `+0x10`, then calls [UID:0001E5][0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState](by-memory/0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState.md).
- `ResetSlots` tests `byte ptr [g_pConfig+0x28de5e]`; the nonzero branch iterates 25 dword entries from `[this+0x690]`, and the zero branch iterates 25 dword entries from `[this+0x6f4]`, with both branches calling [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md) at `0x005435b0`.
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
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

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
