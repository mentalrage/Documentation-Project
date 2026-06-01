*** UID:0000DS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellSlotInputPane

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellSlotInputPane.cpp`

## Class Purpose

`SpellSlotInputPane` is a spell-slot letter prompt. It maps a typed letter to an allowed spell slot and sends an opcode `0x0f` packet containing the selected slot.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LV][0x005b1280-0x005b130d.SpellSlotInputPaneConstructor](by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md) | Builds [UID:00001P][CharInputPane](by-class/CharInputPane.md), installs vtables, sets spell prompt text, and stores the spell bar index. |
| `OnKeyInput` | [UID:0001LW][0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput](by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md) | Handles help/panel shortcut before forwarding to the char input base. |
| `SubmitSpellSlot` | [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md) | Decodes a typed slot letter, validates against max spell slots, and sends opcode `0x0f`. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7dc0`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NG][0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor](by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md) | Restores spell panel state, runs base cleanup, and optionally frees `this`. |

## Evidence Notes

- IDA confirms the constructor, key handler, submit handler, two thunks, and scalar deleting destructor.
- Constructor callers are spell inventory cast dispatch paths at `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- Disabled generated output marks `0x005b78af` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7dc0` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents role, constructor/key/submit/destructor/thunk memory docs, spell-slot packet behavior, constructor callers, and ignored adjustor-thunk handling; remaining completion gap is source-ready C++ detail.
