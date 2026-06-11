*** UID:0000AN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PopupMenuControlPane

## Status

- Confidence: strong for class role, live IDA boundaries, owned-menu behavior, callback dispatch, draw/input flow, and destructor/type-id evidence.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:00011F][0x00498040-0x0049b8e5.PopupMenuControlPane](by-memory/0x00498040-0x0049b8e5.PopupMenuControlPane.md)
- Autogen parent: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Parent-gate status: reconstructable class attached to direct file parent [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), now `86/85`; this class now clears the corrected `85/85` gate for direct PopupMenu destructor children.

## Class Purpose

`PopupMenuControlPane` is a control widget that owns a `MenuPane`, draws `POPUP_MENU` EPF pieces, renders the selected menu item label, and maps mouse/key input to item selection.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00498040-0x0049812b` | `PopupMenuControlPane::PopupMenuControlPane(int menuType, int* parentBlock)` | Constructs the base control, callback object, owned `MenuPane`, and selected-index state. |
| `0x00498170-0x0049817f` | `AddOrLayoutItem(...)` | Forwards item insertion/layout to the owned `MenuPane`. |
| `0x00498180-0x0049818f` | `GetItemByIndex(int)` | Forwards indexed item lookup to the owned `MenuPane`. |
| `0x00498190-0x0049819b` | `GetItemCount()` | Reads the owned menu item count. |
| `0x004981a0-0x004981a7` | `GetSelectedIndex()` | Returns the selected-index field. |
| `0x00498220-0x0049826d` | `OnSelectionChanged(long)` | Callback target that updates the selected index and notifies the parent. |
| `0x00498270-0x004984bc` | `OnDraw()` | Draws popup menu art and selected item text. |
| `0x004984c0-0x0049851a` | `OnMouseEvent(Event*)` | Handles click selection. |
| `0x00498520-0x00498599` | `OnKeyEvent(Event*)` | Handles keyboard selection from scroll position. |
| `0x0049af95-0x0049afab` | Destructor adjustor/thunk helpers | Secondary-vtable deleting-destructor thunks. |
| `0x0049b3b0-0x0049b417` | `~PopupMenuControlPane()` | Releases the owned `MenuPane` and base pane state. |
| `0x0049b8e0-0x0049b8e5` | `GetControlType()` | Returns control type `12`. |

## Evidence Notes

- Live IDA MCP on 2026-06-05 confirms the constructor, five helper/accessor routines, draw routine, mouse/key handlers, destructor adjustor thunks, destructor body, and control-type helper as exact functions.
- The constructor installs three popup-control vtable bases, stores the menu type, allocates a member-function callback object, binds its target to `0x00498220`, constructs the owned `MenuPane`, initializes selected index `-1`, and marks the control dirty.
- The helper/accessor routines forward item insertion/layout and indexed item lookup into the owned `MenuPane`, read the owned item count, and return the selected-index field. Live code xrefs show broad dialog/menu setup use, supporting source-level API status.
- `OnSelectionChanged` updates the selected index, invalidates the control rect, locates the parent, and sends notification code `10`. [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) documents the compiler-generated invoke wrapper around this target.
- `OnDraw` loads `POPUP_MENU` art frames, draws the selected item's text, and applies highlight/frame color behavior. Mouse and key handlers both route accepted input into the `MenuPane` selection/scroll helper at `0x00516510`.
- The destructor thunks forward from secondary vtables to the destructor body; the destructor deletes the owned `MenuPane`, tears down base pane state, and conditionally frees the object. `GetControlType` returns `12`.
- 2026-06-08 A004 Batch 114 IDA recheck confirmed the same ownership cluster: constructor `0x00498040` creates the callback/menu helper pair, selection callback `0x00498220` updates selected index and notifies the parent, draw/mouse/key methods consume the same state, and scalar deleting destructor `0x0049b3b0` destroys the owned helper at `+264` before base/control teardown and conditional allocator free. This establishes the actual direct parent for [UID:0002YA][0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor](by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md).

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)

## Score Rationale

- Completion is `86` because the page now records exact constructor/destructor/method ranges, owned helper layout, callback target, vtable/read-only-data ownership, helper fan-in, and direct file parent; final source field names and reconstructed C++ remain intentionally absent.
- Confidence is `88` because live IDA callers, callees, data xrefs, and decompilation consistently support `PopupMenuControlPane` as the direct class owner under [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), with no competing direct parent evidenced.

## Changes

- 2026-06-08 A004 Batch 114 strict parent-gate update:
  - Changed completion from `82` to `86`; confidence remains `88`; kept `AUTOGEN_PARENT_UID:0000MN`.
  - Evidence: live IDA rechecked constructor/callback/draw/mouse/key/destructor sizes and behavior, owned `MenuPane` field cleanup, constructor and selection callback fan-in, vtable data ownership, and direct parent [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) at `86/85`. Final C++ remains blank pending full field layout and source-quality names.

- 2026-06-05 live IDA refresh and parent attach:
  - Before: `COMPLETION:76`, `CONFIDENCE:84`, and blank `AUTOGEN_PARENT_UID`; the method map omitted public helper/accessor routines and retained stale generated-source provenance.
  - After: `COMPLETION:82`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000MN`; final C++ remains blank under the 95/95 gate.
  - Evidence: live IDA confirms the exact method starts, constructor callback binding, owned `MenuPane` field use, helper caller fanout, vtable-only draw/input/destructor refs, destructor ownership cleanup, and control type `12`. Parent attachment now satisfies the 80/80 gate because this class is `82/88` and [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) is `84/80`.

- Before: completion/confidence metadata were `0/0` despite class role, method map, source-file placement, IDA boundaries, and callback-helper links.
- Changed to: `COMPLETION:76` and `CONFIDENCE:84`.
- Evidence: constructor, drawing, mouse/key event handling, destructor thunks, destructor, control type id, owned `MenuPane`, and selection callback are documented; remaining gaps are field layout and full reconstructed C++.
