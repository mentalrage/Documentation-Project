*** UID:0000CT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectObjectWithKeyboardPane

## Status

- Confidence: strong for class behavior and IDA boundaries; medium for exact original file split.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- Address range: [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SelectObjectWithKeyboardPane.cpp`

## Class Purpose

`SelectObjectWithKeyboardPane` is a [UID:000077][LineInputPane](by-class/LineInputPane.md)-derived object selector. It displays the prompt to use arrow keys and Enter, tracks the current target object id in `dword_69BF28`, highlights the selected `LivingObjectPane`, and confirms by dismissing the input pane and interacting with the selected object.

The pane also supports vi-style movement keys, arrow keys, home/self selection, tab/view shortcuts, and mouse picking over the map.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LB][0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor](by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md) | Builds the line-input base, stores the active singleton in `dword_69BF60`, installs three vtable views, chooses the initial target, and highlights it. |
| non-deleting destructor | [UID:0001LC][0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor](by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md) | Resets vtables, clears `dword_69BF60`, and calls the base cleanup helper. |
| `OnKeyEvent` | [UID:0001LD][0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent](by-memory/0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent.md) | Handles Enter/Escape/space/tab, previous/next target keys, self target, and target interaction. |
| `OnMouseEvent` | [UID:0001LE][0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent](by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md) | Converts mouse coordinates into map space, highlights clicked/hovered living objects, and confirms or cancels selection. |
| object-list refresh virtual | [UID:0001LF][0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual](by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md) | Parses underscore-prefixed object-id payloads; if the current target disappears, it switches selection to the local player object. |
| clear-current-target helper | [UID:0001LG][0x005afd30-0x005afd4f.SelectObjectWithKeyboardPaneClearCurrentTarget](by-memory/0x005afd30-0x005afd4f.SelectObjectWithKeyboardPaneClearCurrentTarget.md) | Clears highlight for `dword_69BF28` through `MapPane` and `LivingObjectPane`. |
| forward-to-line-input helper | [UID:0001LH][0x005afe70-0x005afeee.SelectObjectWithKeyboardPaneForwardTabKey](by-memory/0x005afe70-0x005afeee.SelectObjectWithKeyboardPaneForwardTabKey.md) | Primes map action state for event type `8`, dismisses the capture pane, and forwards the key to the line-input base as Tab. |
| adjustor thunks | [UID:0001N8][0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to the scalar deleting destructor; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001ND][0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor](by-memory/0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor.md) | Delete wrapper; repeats vtable/singleton cleanup, calls base cleanup, and frees when requested. |

## Evidence Notes

- `simroot_v2` emits the constructor, key handler, mouse handler, and scalar deleting destructor, but the active generated file omits `0x005af6e0`, `0x005afc90`, `0x005afd30`, and `0x005afe70`.
- IDA xrefs tie `0x005afd30` and `0x005afe70` directly to `SelectObjectWithKeyboardPane::OnKeyEvent`/`OnMouseEvent`.
- IDA data xrefs place `0x005afc90`, `0x005b7862`, and `0x005b786d` in `SelectObjectWithKeyboardPane` vtables.
- Disabled generated output lists `0x005b786d` as missing code, but IDA confirms it is a real destructor adjustor thunk.
- 2026-05-26 IDA recheck confirms `0x005b7862` and `0x005b786d` forward to `0x005b7bc0` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:0001N8][0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md)
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000OH`.
  - Before: The keyboard/mouse target selector remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `TargetSelectionInputPanes.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor/destructor/key/mouse/object-list/helper starts from `0x005af5f0` through `0x005afe70`, destructor thunks at `0x005b7862` and `0x005b786d`, and scalar deleting destructor `0x005b7bc0`; parent [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) owns the target-selection input family.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `80`.
- Evidence: the page documents constructor, destructor, key/mouse handlers, object-list refresh, helper functions, destructor thunks, global target state, and IDA-backed vtable/call evidence; remaining uncertainty is exact original file split.
