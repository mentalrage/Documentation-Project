*** UID:0000DU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellStringInputPane

## Status

- Confidence: strong for behavior and IDA boundaries; medium for exact source split.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md), plus shared prompt helper [UID:00018Y][0x004f20a0-0x004f22f4.SpellPromptTextHelper](by-memory/0x004f20a0-0x004f22f4.SpellPromptTextHelper.md).
- Current recovered file: `source-3/simroot_v2/class_SpellStringInputPane.cpp`

## Class Purpose

`SpellStringInputPane` is the string-argument spell prompt. It builds a [UID:000077][LineInputPane](by-class/LineInputPane.md), displays the spell name/prompt, reads the entered text, converts it to the outbound client character form, and sends opcode `0x0f` with the spell index and string payload.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `SetPromptText` | [UID:00018Y][0x004f20a0-0x004f22f4.SpellPromptTextHelper](by-memory/0x004f20a0-0x004f22f4.SpellPromptTextHelper.md) | Shared spell prompt layout/text helper used by multiple spell input panes. |
| constructor | [UID:0001KU][0x005adf40-0x005adfcd.SpellStringInputPaneConstructor](by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md) | Builds the line-input base, installs vtables, sets spell prompt text from player spell data, and stores the spell slot index. |
| `OnConfirmInput` | [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md) | Reads input text, converts it, builds opcode `0x0f`, and queues the string spell packet. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7e90`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) | Restores panel state, runs base cleanup, and optionally frees `this`. |

## Evidence Notes

- IDA confirms `0x004f20a0`, `0x005adf40`, `0x005ae060`, `0x005b78ba`, `0x005b78c5`, and `0x005b7e90`.
- Disabled generated output marks `0x005b78c5` as missing code, but IDA decompiles it as a real adjustor thunk.
- `SetPromptText` is shared with spell target/slot/selection prompts, so it is source-owned by spell input UI, not a one-method utility source.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7e90` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents line-input behavior, shared prompt helper, constructor/confirm/destructor/thunk memory docs, opcode/string packet behavior, and ignored adjustor-thunk handling; confidence is capped by exact source split and shared helper ownership.
