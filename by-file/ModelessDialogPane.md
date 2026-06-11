*** UID:0000LH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ModelessDialogPane

## Status

- Confidence: strong for class boundary, method ownership, and behavior; medium-high for exact original filename because allocation sites are still not modeled directly.
- Proposed module: `ui/core/ModelessDialogPane.cpp`
- Proposed header: `ui/core/ModelessDialogPane.h`
- Current recovered source: `source-3/simroot_v2/class_ModelessDialogPane.cpp`
- Main memory range: [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md), now split to exact method children [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md), [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md), and [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md)
- Type docs: [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- Vtables: [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)
- Evidence basis: `simroot_v2` generated source and read-only IDA MCP checks on 2026-05-24 and 2026-05-26. `wave3.py` was not executed for this pass.

## File Role

`ModelessDialogPane` is shared dialog infrastructure, not a feature dialog. It derives from [UID:0000IT][DialogPane](by-file/DialogPane.md), initializes a non-modal dialog shell, registers it with the event dispatcher/modeless dialog list, and owns the mouse interaction path for dragging, hover state, click dispatch, and final selection activation.

Place it with `ui/core/` rather than `ui/dialogs/` because it implements reusable dialog behavior that feature dialogs build on. It should not be folded into [UID:0000HE][AlertPanes](by-file/AlertPanes.md) even though its executable range sits between `VersatileAlertPane` constructor/callback code and the later `VersatileAlertPane` destructor island.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md) | [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md), [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md), [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) | `DialogPane`-derived modeless shell and mouse-event router. |
| `g_dialogRenderContext` | generated global-data reference | Render/context object passed into dialog bounds initialization. |
| `g_globalInputManager` | generated global-data reference | Notified after click release/focus finalization. |
| `g_pEventDispatcher` | generated global-data reference | Receives the secondary-subobject pointer for modeless registration. |

## Vtable Layout

IDA confirms three `ModelessDialogPane` vtables:

| View | Vtable | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00618c48` | `0x004a07bd` | `+0x00` | Primary `DialogPane`/pane view, with inherited `DialogPane` scalar destructor at slot `+0x00`. |
| secondary | `0x00618ca8` | `0x004a07c4` | `+0xa0` | Event/input view. `HandleMouseEvent` is slot `+0x04`; `IsModal` is slot `+0x08`. |
| tertiary | `0x00618cd8` | `0x004a07ca` | `+0xa4` | Short event/update view with inherited `DialogPane` adjustor thunk and base event slot. |

The tertiary table ends before `0x00618ce0`, which is neighboring data/string storage rather than another virtual slot.

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md) | constructor | Calls `DialogPane::DialogPane(title, -1, 1)`, installs three vtables, sets default bounds `(100,100)-(200,200)`, initializes dialog bounds, initializes pane interaction, and registers the modeless entry. |
| [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md) | `IsModal` | Returns `false`. Vtable data xref at `0x618cb0`. |
| [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) | `HandleMouseEvent` | Handles move/down/up/drag-style mouse events, hit tests controls, updates hover/pressed state, commits dialog focus, and activates the selected item on release. Vtable data xref at `0x618cac`. |

## Ownership Notes

- IDA reports no direct code callers for the constructor at `0x004a0760`; the class is still real through vtable references and executable method bodies.
- The constructor stores vtables at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`, then passes `this + 0xa0` into the event-dispatcher registration path.
- The generated `HandleMouseEvent` body uses secondary-subobject `this` semantics. It computes the `DialogPane` core as `this - 160`, which matches the vtable layout and the event-list registration path.
- `HandleMouseEvent` receives the secondary view as `this == object + 0xa0`; generated offsets such as `context + 360` map back to inherited [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) offsets `+0x208` through `+0x238`, not a separate modeless tail.
- Keep `0x004a0cb0-0x004a0d37` with `VersatileAlertPane` destructor support. The gap between `0x004a0c8e` and `0x004a0cb0` is not enough evidence to merge modeless behavior into alert code.
- Current Wave3 metadata for `class_ModelessDialogPane.meta_wave3` reports `vtable_count: 0`; use IDA vtable evidence until generated metadata is corrected.

## Cross-References

- [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md)
- [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md)
- [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)

## Changes

- 2026-06-08 A005 Batch115 parent-source refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:82`, with the source file below the corrected parent confidence gate for method children.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:85`.
  - Summary/evidence: Batch 115 split [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md) into exact method pages for the constructor, `IsModal`, and `HandleMouseEvent`; each child carries direct class ownership through [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md). Cross-checks against [UID:0000IT][DialogPane](by-file/DialogPane.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md), and [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md) support this file as the actual direct source owner rather than adjacent [UID:0000HE][AlertPanes](by-file/AlertPanes.md) or the base [UID:0000IT][DialogPane](by-file/DialogPane.md). Confidence remains at `85` because direct allocation sites and final original filename proof are still open.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Summary/evidence: the page documents class role, vtable layout, function map, secondary-subobject behavior, ownership boundaries, IDA evidence, and related type/vtable docs; confidence is capped by the exact original filename and generated vtable metadata issue.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
- Changed to: `NexusTK/ui/core/`.
- Summary/evidence: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) is already listed under `ui/core/ModelessDialogPane.cpp` in [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md), and IDA evidence supports it as shared dialog infrastructure rather than a feature-dialog module.
