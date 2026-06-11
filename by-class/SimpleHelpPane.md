*** UID:0000D6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleHelpPane

## Status

- Source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_SimpleHelpPane.cpp`
- Confidence: strong for purpose, exact method cluster, singleton lifecycle, vtable/read-only-data neighborhood, and HelpPanes source ownership; medium-high for final event-owner type names because current generated output still pollutes those handlers with unrelated owner labels.

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
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) is attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and documents exact `SimpleHelpPane` constructor, ordinary destructor, paint, mouse, timer, and key handlers, plus the adjacent `SimpleHelpPane2` constructor/teardown/event cluster.
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) is attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and records the exact `0x0069ae00` singleton storage, initialized bytes, constructor publish/fallback clear, ordinary teardown clear, support-helper clear, scalar deleting destructor clear, close-helper read, and broad feature consumers.
- [UID:00025G][0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData](by-memory/0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData.md) places the `SimpleHelpPane` vtable in the same help/item-help read-only data span as the rest of the HelpPanes family.

## Parent And Score Rationale

| Topic | Rationale |
| --- | --- |
| Source parent | [UID:0000JU][HelpPanes](by-file/HelpPanes.md) is `90/80`, has the `NexusTK/ui/controls/` path, and owns the contiguous help/tooltip pane source family. |
| Exact method evidence | [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) records the exact method cluster and broad constructor xrefs, so the class identity is no longer dependent on generated source labels. |
| Singleton evidence | [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) and [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) document the active-pane lifecycle and feature-reader set. |
| Remaining blockers | Event-handler owner names and final event enum/field names still need cleanup, and final C++ remains below the 95/95 gate. |

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md)
- [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)
- [UID:00025G][0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData](by-memory/0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)

## Changes

- 2026-06-06 A008:
  - Before: confidence was `78` and `AUTOGEN_PARENT_UID` was blank even though the HelpPanes parent, method cluster, singleton global, and singleton storage child all passed the attachment gate.
  - After: changed confidence to `82`, attached the class to [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and added parent/score rationale while keeping completion at `84`.
  - Evidence: [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) documents exact method boundaries and constructor fanout; [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) and [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) document singleton lifecycle; [UID:0000JU][HelpPanes](by-file/HelpPanes.md) owns the tooltip/help source family at `90/80`.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The timed simple-help tooltip remained unclassified in autogen coverage despite documented constructor, paint/input/timer, singleton, and destructor-wrapper evidence.
  - After: The class is reconstructable but unassigned because the class confidence score remains below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms constructor/destructor/paint/input/timer starts at `0x004c6f90`, `0x004c7290`, `0x004c7310`, `0x004c7440`, `0x004c7450`, `0x004c74a0`, and scalar deleting destructor `0x004ce560`; existing notes keep generated event-owner type pollution open.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents purpose, ownership, main range, constructor/destructor/paint/input/timer/destructor-wrapper methods, singleton storage, and caller fanout; confidence remains limited by generated event-owner type pollution.
