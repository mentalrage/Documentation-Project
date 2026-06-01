*** UID:0000DM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellInputPaneState

## Status

- Confidence: strong for helper behavior; medium for final owner source file.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) or a spell input pane source.
- Address range: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- Current recovered file: `source-3/simroot_v2/class_SpellInputPaneState.cpp`

## Class Purpose

`SpellInputPaneState` is currently represented by one small helper that writes an input-mode byte at offset `+0xfa`. The caller fanout sits in spell and shared target-input flows, so this should be treated as a state/layout helper rather than a standalone feature module.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetInputModeFlag` | `0x0057c430-0x0057c43f` | Stores the passed byte to `this + 0xfa`. |

## Evidence Notes

- IDA confirms `0x0057c430` as a real 0x10-byte function.
- `simroot_v2` emits only this helper in `class_SpellInputPaneState.cpp`.
- IDA xrefs come from spell input methods and destructor/helper paths, which supports shared state-helper placement near spell/target input code.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the page documents the exact helper behavior, field offset, IDA function size, and caller-family placement; completion stays limited because this is probably a state/layout helper rather than a standalone class and the final owner source is open.
