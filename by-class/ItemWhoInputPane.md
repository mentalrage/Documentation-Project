*** UID:00006X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPane

## Status

- Confidence: strong for target-selection behavior; medium for final file placement.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) or [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md), destructor [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md), object-list virtual [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- Current recovered file: `source-3/simroot_v2/class_ItemWhoInputPane.cpp`

## Class Purpose

`ItemWhoInputPane` is a target-selection input pane used by the use-on-target flow. It accepts a typed target name or mouse-selected map object, tracks the current selected target, and sends a use-spell-or-item packet for the stored slot/target.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ItemWhoInputPane` | `0x005aec60-0x005aed3d` | Builds the line-input prompt, stores the item slot, and initializes target state. |
| Non-deleting destructor | `0x005aed40-0x005aedcb` | Restores vtables, reconciles saved target state, clears item target input-mode state, and calls base cleanup. |
| `HandleKeyInput` | `0x005aedd0-0x005aefaf` | Handles typed target selection, current target shortcuts, and packet dispatch. |
| `HandleMouseInput` | `0x005af050-0x005af2e7` | Handles map-object hover/selection and auto-use behavior. |
| Object-list virtual | `0x005af2f0-0x005af383` | Handles underscore-prefixed object-list payloads for saved item target state. |
| `ScalarDeletingDestructor` | `0x005b7a20-0x005b7aec` | Delete wrapper and cleanup path. |

## Evidence Notes

- Wave3 generated source shows calls to `MapPane::FindObjectAtPoint`, `MapPane::FindObjectById`, target-id globals, and `Packet_SendUseSpellOrItem`.
- IDA MCP confirms the constructor, key handler, mouse handler, thunks at `0x005b780a`/`0x005b7815`, and scalar deleting destructor.
- IDA recheck on 2026-05-26 confirms `0x005aed40` as the non-deleting destructor and `0x005af2f0` as a vtable-dispatched object-list helper. Wave3 active output still lacks stable owners for those two functions.
- The 2026-05-24 target-selection pass identifies `0x005af390` as the saved-item-target clear helper.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md)
- [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md)
- [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `80/80`. Summary: target-selection input role, constructor/destructor/key/mouse/object-list/scalar-destructor methods, target-state helper relationship, packet dispatch, and Wave3 owner gaps are documented; confidence remains limited by final source-file placement between target-selection and item-action modules. Evidence: `ItemWhoInputPane`, `ItemWhoInputPaneDestructor`, `ItemWhoInputPaneObjectListVirtual`, `TargetSelectionInputPanes`, `ItemActionInputPanes`, and related target-input classes.
