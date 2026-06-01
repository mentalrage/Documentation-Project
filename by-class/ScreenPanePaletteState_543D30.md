*** UID:0000CC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenPanePaletteState_543D30

## Status

- Confidence: strong for the two imported methods and `PaletteLib`-resident ownership, medium for final class/facet naming.
- Likely source file: [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md), with focused notes in [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md).
- Address ranges: [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md)
- Current recovered file: `source-3/simroot_v2/class_ScreenPanePaletteState_543D30.cpp`

## Class Purpose

`ScreenPanePaletteState_543D30` tracks screen-level palette bank state as a recovered `PaletteLib`-resident facet/helper. Wave3 emits it as a separate class, but IDA shows `ScreenPane::HandleMessage` passes `g_pPaletteLib` as `this` when switching mode and resetting one of two 25-slot palette banks.

## Observed Layout

```text
ScreenPanePaletteState_543D30
  +0x00  unknown / object header
  +0x04  int mode
  +0x08  List* slotList
  +0x690 int* slotBankA[25]
  +0x6f4 int* slotBankB[25]
```

The `ResetSlots` method chooses `slotBankA` or `slotBankB` by reading a config byte from `g_pConfig + 0x28de5e`, then applies a palette-entry helper to each of the 25 entries.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetMode` | `0x00543d30` | Stores a mode value at object offset `+0x04`. |
| `ResetSlots` | `0x00543ee0` | Resets child slot states, chooses a 25-entry palette bank from config, and applies palette-entry moves to each collection. |

## Excluded Adjacent Helpers

## Evidence Notes

- 2026-05-26 IDA MCP recheck shows `SetMode` modeled callers at `0x00556dcb` and `0x00556e0f` inside `ScreenPane::HandleMessage` / `sub_556d50`, and raw calls at `0x005593c0` and `0x00559405`.
- 2026-05-26 IDA MCP recheck shows `ResetSlots` modeled caller `0x00556dd2` inside the same `ScreenPane::HandleMessage` branch, plus raw call `0x005593c7`.
- The `ScreenPane::HandleMessage` decompilation loads `dword_67A7E0` / [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) into a register before calling `SetMode` and `ResetSlots`.
- `PaletteLib::PaletteLib` at `0x00543700` sets `g_pPaletteLib`, initializes field `+0x04`, allocates/stores the list at `+0x08`, and constructs the embedded palette-bank arrays later used by `ResetSlots`.

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

- 2026-05-30: Changed completion/confidence from `0/0` to `76/76`.
  - Before: The page was unevaluated despite documenting the two imported methods, observed layout, PaletteLib ownership, excluded adjacent helpers, and caller evidence.
  - After: Scored as moderate-high completion and confidence because behavior and ownership are strong, while final class/facet naming remains uncertain.
  - Evidence: Existing layout notes, method notes, IDA caller evidence, PaletteLib constructor relationship, and excluded-helper section support the score.
