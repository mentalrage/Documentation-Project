*** UID:0000DW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellTwoArgsInputPane

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellTwoArgsInputPane.cpp`

## Class Purpose

`SpellTwoArgsInputPane` collects two numeric arguments for a spell and serializes them into an opcode `0x0f` spell-use packet. It derives from [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LR][0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor](by-memory/0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor.md) | Builds numeric-args base, installs vtables, loads spell prompt text, and stores spell index. |
| `OnConfirmInput` | [UID:0001LS][0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput](by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md) | Reads two numbers and sends a 6-byte spell packet. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b8030`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NJ][0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor](by-memory/0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor.md) | Restores spell panel state, runs base cleanup, and optionally frees `this`. |

## Evidence Notes

- IDA confirms the constructor, confirm handler, two thunks, and scalar deleting destructor.
- Constructor callers are spell inventory cast dispatch paths at `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- Disabled generated output marks `0x005b78f1` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b8030` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents the numeric spell-input role, exact constructor/confirm/destructor/thunk memory docs, constructor callers, packet shape, and ignored adjustor-thunk handling; remaining completion gap is source-ready C++ detail.
