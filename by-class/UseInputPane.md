*** UID:0000FG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UseInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_UseInputPane.cpp`

## Class Purpose

`UseInputPane` is the item-use prompt. It accepts a single inventory slot letter and dispatches the use flow for that slot, which may lead into target-selection handling for usable items.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `UseInputPane` | `0x005b5ca0-0x005b5d67` | Constructs the prompt with player name and installs vtables. |
| `OnCharInput` | `0x005b5d70-0x005b5ddc` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmitInput` | `0x005b5de0-0x005b5e5c` | Converts slot letter and dispatches item-use slot handling. |

## Evidence Notes

- Wave3 generated source shows a direct call into `LivingObjectPane::UseSpellSlot` for the selected slot.
- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x09`, calls `CharInputPane::CharInputPane`, gets the local player name from `dword_67A748`, formats the prompt, and installs vtables `0x00630304`, `0x00630354`, and `0x00630384`.
- IDA decompilation of `0x005b5de0` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value is bounded by [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`.
- The submit path calls [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md) with `dword_67A748` and the validated slot. Current generated name `LivingObjectPane::UseSpellSlot` remains provisional because macro docs tie this address to inventory/item-tab state.
- Targeted use flow should cross-reference [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: scored from IDA-confirmed constructor/char/submit methods, prompt id, vtable stores, slot validation, inventory-use dispatch target, and item-action input grouping.
