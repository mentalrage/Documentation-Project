*** UID:0000ED | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TargetObjectWithKeyboardPane

## Status

- Confidence: strong for class behavior and IDA boundaries; medium for exact original file split.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- Address range: [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_TargetObjectWithKeyboardPane.cpp`

## Class Purpose

`TargetObjectWithKeyboardPane` is a [UID:000077][LineInputPane](by-class/LineInputPane.md)-derived target selector for the target-dispatch flow. It prompts the player to use arrow keys and press `v`, tracks the selected target id in `dword_69BF2C`, highlights the current target, and forwards target confirmation into the overlay/dispatch code.

It is close in structure to [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md), but it uses a separate singleton/state set and confirms with `v` rather than Enter.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LI][0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor](by-memory/0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor.md) | Builds the line-input base, stores the active singleton in `dword_69BF64`, installs three vtable views, chooses the initial target, highlights it, and attaches to the input capture pane. |
| non-deleting destructor | [UID:0001LJ][0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor](by-memory/0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor.md) | Resets vtables, clears `dword_69BF64`, and calls the base cleanup helper. |
| `HandleTargetKeyboardEvent` | [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md) | Handles cancel, previous/next target keys, self target, tab/`v` dispatch-mode keys, and target highlight changes. |
| `HandleTargetMouseEvent` | [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) | Converts mouse coordinates to map space, updates selected living object, and participates in target confirmation/cancel behavior. |
| adjustor thunks | [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to the scalar deleting destructor; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NL][0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor](by-memory/0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor.md) | Delete wrapper; repeats vtable/singleton cleanup, calls base cleanup, and frees when requested. |

## Evidence Notes

- `simroot_v2` emits the constructor, keyboard handler, mouse handler, one adjustor thunk, and scalar deleting destructor.
- IDA confirms the omitted non-deleting destructor at `0x005affe0` and the disabled/missing-code thunk at `0x005b791d`.
- IDA data xrefs place `0x005b0010` and `0x005b0290` in `TargetObjectWithKeyboardPane` vtable slots.
- 2026-05-26 IDA recheck confirms `0x005b7912` and `0x005b791d` forward to `0x005b81d0` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- The generated scalar destructor body references base cleanup through a generic helper; do not interpret any base-helper name pollution as source ownership outside this class.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents target-selector behavior, constructor/destructor/keyboard/mouse/destructor-thunk memory docs, vtable refs, singleton state, generated omissions, and sibling selector relationships; confidence remains capped by exact original file split.
