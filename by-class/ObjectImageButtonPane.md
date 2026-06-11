*** UID:00009N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectImageButtonPane

## Status

- Confidence: strong for class role; strong for object-image source-family placement.
- Likely source file: [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), or an adjacent `ui/controls/ObjectImageButtonPane.cpp` if split out.
- Address/range evidence: [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md)
- Parent attachment: enabled because the class, memory range, and owning file page all meet the 80%+ completion/confidence gate.

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

- [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md) documents the constructor, key handler, paint method, highlight setter, adjustor thunks, scalar deleting destructor, padding boundary, HeadSelectDialog callers, vtable support, and final C++ gate.
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) documents the object-image control source family and why this button subclass should live adjacent to the reusable preview control instead of the generic specialized-button bucket.
- IDA MCP reports one direct constructor xref from `0x00551479`.
- IDA MCP confirms the destructor/thunks are non-contiguous; intervening functions in the `0x00520afd-0x00520c5a` neighborhood belong to `ObjectImageControlPane`, `ClientItemMenuItemList`, or other classes.
- 2026-05-24 IDA MCP confirms the constructor directly calls `ObjectImageControlPane::ObjectImageControlPane` at `0x00520830`, then installs three `ObjectImageButtonPane` vtable pointers and clears state bytes at `+0x102`, `+0xff`, and `+0x14c`.
- 2026-05-24 IDA MCP decompiles the deleting destructor as `sub_544580(this)` plus conditional `sub_4F4AC0(this)`. The generated `TextButtonExControlPane`/`Pane` base label is owner-name pollution.
- `SetButtonHighlight` is called by [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) paths at `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) creates paged head-selection buttons with this class and toggles highlight state as the selected head changes.

## Attachment and Reconstruction State

- Attached to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) after the class page was refreshed from the reviewed memory page and the object-image control file owner.
- Keep [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) as a historical cross-reference only; current by-* evidence favors the object-image source family.
- Final C++ remains withheld because the class declaration, exact pane field names, and image descriptor structure are not yet proven to the 95/95 gate.

## Cross-References

- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md)
- [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md)

## Changes

- 2026-06-06: Raised completion from `78` to `82`, attached the class to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), replaced generated-source/Wave-derived evidence framing with the reviewed by-memory/by-file basis, and added attachment/reconstruction state. Confidence stays `84` because role, methods, callers, and source-family placement are strong while final field names and source-quality declarations remain open.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed type-code, constructor, key, paint, highlight, thunk, and deleting-destructor functions at `0x004242f0`, `0x00520820`, `0x00520870`, `0x00520910`, `0x00520a80`, `0x00520ae7`, `0x00520af2`, and `0x00520c60`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate.
- Before: completion/confidence metadata were `0/0` even though the page already captured behavior, method boundaries, non-contiguous destructor support, callers, and source-family placement.
- Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
- Evidence: constructor, activation, painting, highlight, type-code, thunk/destructor, base-owner pollution, and `HeadSelectDialog` usage are documented; remaining gaps are detailed field names and full reconstructed C++.
