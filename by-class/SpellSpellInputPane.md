*** UID:0000DT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellSpellInputPane

## Status

- Confidence: strong for behavior; medium for final spell vs command-input file placement.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) or [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Address range: [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_SpellSpellInputPane.cpp`

## Class Purpose

`SpellSpellInputPane` is a spell-selection prompt used when a spell command needs another spell as the argument. It formats a prompt with the current spell name, handles help shortcut input, and converts a letter to a spell index.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellSpellInputPane` | [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md) | Constructs prompt using current spell name and installs vtables. |
| `OnKeyInput` | [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md) | Handles spell help-panel shortcut. |
| `OnAccept` | [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) | Converts letter to spell index and calls spell selection. |

## Evidence Notes

- IDA MCP confirms all three function starts.
- IDA MCP confirms three `SpellSpellInputPane` vtable views at `0x0063041c`, `0x0063046c`, and `0x0063049c`; this strengthens layout evidence but does not override the stronger spell-domain file placement.
- Wave3 generated source shows `g_pSpellMan`, current-spell prompt formatting, and tab `3` help-panel behavior.
- The 2026-05-24 spell input pass favors [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) as the final owner because this prompt is spell-domain-specific and shares prompt/panel behavior with the numeric/string spell argument panes.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `76`.
- Evidence: the page documents spell-selection prompt behavior, constructor/key/accept memory docs, vtable family, IDA-confirmed vtable views, and spell-domain placement rationale; confidence remains capped by final spell-input versus command-input source placement.
