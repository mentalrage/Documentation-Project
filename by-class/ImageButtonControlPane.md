*** UID:00006D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ImageButtonControlPane

## Status

- Confidence: strong.
- Direct source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_ImageButtonControlPane.cpp`

## Class Purpose

`ImageButtonControlPane` is the generic EPF image-button control. It constructs over an image id and pane definition, tracks hover/press state, refreshes visual state on mouse transitions, and paints an EPF sprite frame based on state and skin mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ImageButtonControlPane` | `0x00495bf0-0x00495ca5` | Constructs the image button and installs the three ImageButton vtable views. |
| `SetState` | `0x00495cd0-0x00495d0b` | Changes image-button state and invalidates/refreshes through the control vtable. |
| `OnMouseEnter` | `0x00495d10-0x00495d76` | Handles hover entry and state refresh. |
| `OnMouseLeave` | `0x00495d80-0x00495de6` | Handles hover exit and state refresh. |
| `OnPaint` | `0x00495df0-0x00495f6c` | Selects EPF image frames and draws the current state through the image/surface helpers. |
| Destructor/thunks | `0x0049af69-0x0049af7f`, `0x0049b290-0x0049b2e5` | Compiler adjustor thunks and scalar deleting destructor wrapper. |

## Evidence Notes

- 2026-06-07 IDA MCP enumerates the six modeled ImageButton method bodies in `0x00495bf0-0x00495f70` at starts `0x00495bf0`, `0x00495cb0`, `0x00495cd0`, `0x00495d10`, `0x00495d80`, and `0x00495df0`. The `0x00495cb0-0x00495cc9` body is the adjacent [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md), not an ImageButton method.
- The constructor currently has 306 direct code xrefs from 74 unique caller functions, confirming this as a reusable generic UI control rather than a feature-dialog local helper.
- The primary ImageButton RTTI/vtable cells are `0x00617dc8 -> ??_R4ImageButtonControlPane@@6B@` and `0x00617dcc -> 0x0049b290`. Secondary vtable cells `0x00617e34 -> 0x0049af69` and `0x00617e64 -> 0x0049af74` route through the adjustor thunks.
- IDA xrefs show the constructor writes vtable cells at `0x00495c6f`, `0x00495c75`, and `0x00495c7f`; the scalar deleting destructor resets the same cells at `0x0049b296`, `0x0049b29c`, and `0x0049b2a6`.
- Virtual slot data references bind `OnPaint` to `0x00617e10`, `SetState` to `0x00617e14`, `OnMouseEnter` to `0x00617e18`, and `OnMouseLeave` to `0x00617e1c`.
- `OnPaint` calls the image/surface helper family at `0x00457a60`, `0x004d02f0`, `0x004b9980`, and `0x004b9660`, consistent with EPF image-frame drawing rather than text or checkbox rendering.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). The child class now clears `85/88`, the direct file parent is `86/88`, and the parent page explicitly owns the generic button/choice-control source family that includes `ImageButtonControlPane`. Final C++ stays blank because state-field names, class declarations, and original split details are not at the 95/95 reconstruction-code gate.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed image-button methods at `0x00495bf0`, `0x00495cd0`, `0x00495d10`, `0x00495df0`, adjustor thunks at `0x0049af69`/`0x0049af74`, and the deleting-destructor wrapper containing `0x0049b2a0`. Left `AUTOGEN_PARENT_UID` blank because both this class and likely parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) are below the 80 completion attachment gate.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: generic EPF image-button role, constructor/state/mouse/paint/destructor method inventory, broad reuse evidence, and source-module placement are documented with strong confidence; remaining work is detailed field layout and final C++ reconstruction. Evidence: `ButtonChoiceControlCore`, `ButtonControlPane`, Wave3 method-grade summary, and IDA constructor xref count.
- 2026-06-07 Agent-A002 Batch 091 parent-gate pass:
  - Before: `74/86`, reconstructable but unassigned, with stale method endpoints and no written vtable-slot assignment evidence.
  - Changed to: `85/88` and `AUTOGEN_PARENT_UID:0000HY`.
  - Summary/evidence: live IDA MCP rechecked exact method endpoints, confirmed 306 direct constructor code xrefs from 74 unique caller functions, mapped primary/secondary vtable cells at `0x00617dcc`, `0x00617e34`, and `0x00617e64`, separated the adjacent `SelectionControlPane` helper, and verified direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) already clears `86/88`.
