*** UID:00009N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectImageButtonPane

## Status

- Confidence: strong for class role; strong for object-image source-family placement.
- Likely source file: [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), or an adjacent `ui/controls/ObjectImageButtonPane.cpp` if split out.
- Current recovered file: `source-3/simroot_v2/class_ObjectImageButtonPane.cpp`

## Class Purpose

`ObjectImageButtonPane` is a button pane that renders an object or character image centered in its bounds. It supports type id reporting, keyboard activation, visual highlight state, and scalar deleting destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetPaneTypeCode` | `0x004242f0-0x004242f4` | Returns constant `11`. |
| `ObjectImageButtonPane` | `0x00520820-0x0052086e` | Constructs vtable state and clears overlay/highlight state. |
| `OnKeyPress` | `0x00520870-0x0052090c` | Space/Enter activation with visual flash. |
| `OnPaint` | `0x00520910-0x00520a78` | Centers and renders the object/character image in bounds. |
| `SetButtonHighlight` | `0x00520a80-0x00520a8f` | Stores highlight byte and returns the new value. |
| Adjustor thunks | `0x00520ae7-0x00520afc` | This-adjustors forwarding to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x00520c60`, size `0x3b` | Calls shared pane-base teardown `0x00544580`, then conditionally frees through `0x004f4ac0`. |

## Evidence Notes

- Wave3 effective grade is 97.7.
- IDA MCP reports one direct constructor xref from `0x00551479`.
- IDA MCP confirms the destructor/thunks are non-contiguous; intervening functions in the `0x00520afd-0x00520c5a` neighborhood belong to `ObjectImageControlPane`, `ClientItemMenuItemList`, or other classes.
- 2026-05-24 IDA MCP confirms the constructor directly calls `ObjectImageControlPane::ObjectImageControlPane` at `0x00520830`, then installs three `ObjectImageButtonPane` vtable pointers and clears state bytes at `+0x102`, `+0xff`, and `+0x14c`.
- 2026-05-24 IDA MCP decompiles the deleting destructor as `sub_544580(this)` plus conditional `sub_4F4AC0(this)`. The generated `TextButtonExControlPane`/`Pane` base label is owner-name pollution.
- `SetButtonHighlight` is called by [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) paths at `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) creates paged head-selection buttons with this class and toggles highlight state as the selected head changes.

## Cross-References

- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md)
- [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already captured behavior, method boundaries, non-contiguous destructor support, callers, and source-family placement.
- Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
- Evidence: constructor, activation, painting, highlight, type-code, thunk/destructor, base-owner pollution, and `HeadSelectDialog` usage are documented; remaining gaps are detailed field names and full reconstructed C++.
