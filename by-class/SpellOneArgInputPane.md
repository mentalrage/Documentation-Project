*** UID:0000DR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellOneArgInputPane

## Status

- Confidence: strong for spell argument behavior; strong that generated panel helpers and `__wtol` are not spell-input class ownership.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellOneArgInputPane.cpp`

## Class Purpose

`SpellOneArgInputPane` collects one numeric argument for a spell and serializes it into an opcode `0x0f` spell-use packet. It derives from [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LT][0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor](by-memory/0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor.md) | Builds numeric-args base, installs vtables, loads spell prompt text, and stores spell index. |
| `OnSubmitInput` | [UID:0001LU][0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput](by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md) | Parses one integer and sends a 4-byte spell packet. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7cf0`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NF][0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor](by-memory/0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor.md) | Restores spell panel state, runs base cleanup, and optionally frees `this`. |

## Ownership Caveats

- Generated `class_SpellOneArgInputPane.cpp` currently includes [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) child/tab helpers at `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650`; those should not migrate with spell input panes. Exact docs: [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) and [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md).
- Generated `SpellOneArgInputPane::__wtol` at [UID:0001O5][0x005cea43-0x005cea6d.CrtWtolWrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md) is an IDA-recognized CRT `__wtol` wrapper with broad runtime caller fanout, not a project method.
- Disabled generated output marks `0x005b7899` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7cf0` after `this - 0xa0` and `this - 0xa4`; the pair and the CRT wrapper are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents role, constructor/submit/destructor/thunk memory docs, packet behavior, generated ownership exclusions, CRT wrapper exclusion, and ignored thunk handling; remaining completion gap is source-ready C++ detail.
