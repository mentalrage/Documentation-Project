*** UID:0000D6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleHelpPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_SimpleHelpPane.cpp`
- Confidence: strong for purpose; medium for generated event-owner labels.

## Class Purpose

`SimpleHelpPane` is the older/simple timed text tooltip singleton. It copies a UTF-16 text buffer, measures multiline text, clamps a popup rectangle against parent and screen bounds, adds itself to the dialog/help layer, schedules a timer, and paints a bordered text popup.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpPane` | `0x004c6f90-0x004c7287` | Constructs and positions a timed text popup; writes [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md). |
| `~SimpleHelpPane` | `0x004c7290-0x004c7307` | Frees copied text buffer, clears singleton, and tears down base pane. |
| `OnPaintFrame` | `0x004c7310-0x004c743e` | Draws bordered popup and text lines. |
| `OnMouseDown` | `0x004c7440-0x004c7450` | Dismisses on mouse action in current generated view. |
| `OnTimerEvent` | `0x004c7450-0x004c7491` | Cancels or expires the timer depending on event type. |
| `OnKeyPress` | `0x004c74a0-0x004c74b0` | Dismisses on key action in current generated view. |
| `ScalarDeletingDestructor` | `0x004ce560-0x004ce618` | Destructor wrapper and optional storage delete. |

## Evidence Notes

- IDA confirms all listed function starts and sizes.
- IDA xrefs to the constructor span inventory, status, self-look, user-look, menu, and other UI callers, supporting a reusable tooltip role.
- Current generated event methods render through `BulletinSession` owner-offset types. Treat those names as type pollution until the event-handler subobject layout is reviewed.
- 2026-05-26 IDA MCP storage check confirms [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) as a 4-byte `.data` singleton with 23 data references.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents purpose, ownership, main range, constructor/destructor/paint/input/timer/destructor-wrapper methods, singleton storage, and caller fanout; confidence remains limited by generated event-owner type pollution.
