*** UID:0000DX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellWhoInputPane

## Status

- Confidence: strong for class behavior and IDA boundaries; medium for exact original file split.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) or a spell input pane source.
- Address range: [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SpellWhoInputPane.cpp`

## Class Purpose

`SpellWhoInputPane` is the spell-target line-input pane. It prompts for a target, lets the player traverse living map objects with keyboard or mouse input, tracks the selected target id in `dword_69BF20`, and submits the selected target back to the spell input/dispatch flow.

It is the spell-side counterpart to [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md), [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md), and [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md).

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001KX][0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor](by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md) | Builds the [UID:000077][LineInputPane](by-class/LineInputPane.md) base, installs three vtable views, attaches the spell prompt text, stores the spell index, chooses the initial living target, and highlights it. |
| non-deleting destructor | [UID:0001KZ][0x005ae380-0x005ae403.SpellWhoInputPaneDestructor](by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md) | Resets vtables, clears the active spell target state helper, and calls base cleanup. |
| `OnKeyNavigationInput` | [UID:0001L0][0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput](by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md) | Handles Enter/Escape, previous/next target keys, self target, and target highlight changes. |
| `OnPointerSelectionInput` | [UID:0001L1][0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput](by-memory/0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput.md) | Converts mouse coordinates to map space, selects/highlights hit living objects, and submits or cancels based on event type. |
| object-list refresh virtual | [UID:0001L2][0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual](by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md) | Parses underscore-prefixed object-id payloads; if the saved spell target disappears, it switches selection to the local player. |
| `DeactivateSavedSpellWhoTarget` | [UID:0001L3][0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget](by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md) | Clears highlight for the saved spell target id `dword_69BF20`. |
| adjustor thunks | [UID:0001NA][0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks](by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to the scalar deleting destructor; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NK][0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor](by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md) | Delete wrapper; resets vtables, clears active spell target state, calls base cleanup, and frees when requested. |

## Evidence Notes

- `simroot_v2` emits the constructor, key handler, pointer handler, and scalar deleting destructor.
- Active generated output omits `0x005ae380`, `0x005aea60`, and `0x005aeb00` from the class file, although `0x005aeb00` exists as a recovered global helper file.
- Disabled generated output lists `0x005b7907` as missing code, but IDA confirms it is a real 0xb adjustor thunk forwarding to `0x005b8100`.
- IDA xrefs to `0x005aeb00` come from the key and pointer handlers. IDA data xrefs place `0x005aea60`, `0x005b78fc`, and `0x005b7907` in `SpellWhoInputPane` vtables.
- 2026-05-26 IDA recheck confirms `0x005b78fc` and `0x005b7907` forward to `0x005b8100` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- The destructor selects [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) or [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md) flag clearing through the active spell panel state path, so those helpers belong near the target/spell input modules.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md)
- [UID:0001L3][0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget](by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents target-selection behavior, constructor/destructor/key/pointer/object-list/deactivate/destructor-thunk memory docs, vtable xrefs, omitted generated methods, and sibling target-input relationships; confidence remains capped by exact original source-file split.
