*** UID:00008K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ModelessDialogPane

## Status

- Confidence: strong for recovered behavior and method boundaries.
- Likely source: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- Parent/C++ status: attached to [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), the `NexusTK/ui/core/ModelessDialogPane.cpp` shared dialog-infrastructure root. Batch 115 refreshed the file parent to `89/85`, so this class/file chain now clears the corrected `85/85` gate. Final C++ remains blank until inherited `DialogPane` field names, event-dispatcher interaction state, and allocation sites are fully audited.
- Current recovered source: `source-3/simroot_v2/class_ModelessDialogPane.cpp`
- Memory: [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- Type docs: [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- Vtables: [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)

## Responsibility

`ModelessDialogPane` is the shared non-blocking dialog pane. It keeps the ordinary [UID:0000IT][DialogPane](by-file/DialogPane.md) control model but returns non-modal state and routes mouse events without stopping the rest of the UI.

## Layout Evidence

Generated metadata and IDA vtable refs support a `DialogPane` base with three vtable slots. See [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) for the secondary-view offset mapping used by the mouse handler.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x000` | primary vtable / `DialogPane` base | Constructor calls `DialogPane::DialogPane`, then installs vtable `0x00618c48` at `0x004a07bd`. |
| `+0x0a0` | secondary event/list subobject vtable | Constructor writes vtable `0x00618ca8` at `0x004a07c4` and registers `this + 160` with `EventDispatcher::AddToModalList`. |
| `+0x0a4` | third vtable slot | Constructor writes vtable `0x00618cd8` at `0x004a07ca`, matching the common multi-vtable `DialogPane` pattern. |
| base `+0x208..+0x238` | inherited mouse/drag/pressed/clamp state | `HandleMouseEvent` runs as the secondary view (`this == object + 0xa0`), so generated `context + 0x168..0x198` accesses translate to base `DialogPane +0x208..+0x238`. |

## Vtable Evidence

| View | Vtable | Key slots |
| --- | --- | --- |
| primary | `0x00618c48` | Inherited `DialogPane` scalar destructor `0x0048c350` at `+0x00`, dialog draw/layout/update slots through `+0x58`. |
| secondary | `0x00618ca8` | `DialogPane` adjustor thunk `0x0048c27b` at `+0x00`, `HandleMouseEvent` `0x004a0840` at `+0x04`, `IsModal` `0x004a0830` at `+0x08`. |
| tertiary | `0x00618cd8` | `DialogPane` adjustor thunk `0x0048c286` at `+0x00`, base event slot `0x00544e90` at `+0x04`. |

The third table is only two slots long. The following dword at `0x00618ce0` belongs to neighboring data/string storage, not this class.

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md) | constructor | Creates a default 100x100 modeless dialog shell and registers it with the event dispatcher/list manager. |
| [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md) | `IsModal` | Reports non-modal behavior. |
| [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) | `HandleMouseEvent` | Drag, hover, click, focus-commit, and control activation dispatcher. |

## Behavior Notes

- Mouse event type `0` handles movement; if dragging, it updates pane position and clamps to configured bounds.
- Mouse event type `1` handles mouse-down. Hit type `10` is treated as title/drag chrome; other hit types enter pressed-control state.
- Mouse event type `3` handles release. It ends drag mode, restores prior dialog mode, dispatches release input, notifies the global input manager, and activates the item if the release still matches the pressed item.
- Mouse event type `7` routes a passive/hover-style event if the cursor is inside the dialog rect.

## Unresolved

- No direct constructor callers were found in IDA during this pass. The vtable data refs and constructor body are enough to keep the class, but live allocation sites remain open.
- Exact field names for the secondary-subobject interaction state should wait until the shared `DialogPane` and event-dispatcher structures are named consistently.
- Wave3 metadata currently reports `vtable_count: 0` for this class even though IDA confirms all three vtables.

## Cross-References

- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md)
- [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md)
- [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)

## Changes

- 2026-06-08 A005 Batch115 split/parent refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`, attached under an older parent gate while exact method children were missing.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:85`, with exact method children [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md), [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md), and [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) assigned to this class.
  - Evidence: the exact child pages preserve the IDA-backed constructor/function sizes, vtable slots, secondary-view offset mapping, event-dispatcher registration, and switch-table exclusion; [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) was refreshed to `89/85`, so this class now has a direct source-file parent that satisfies the corrected gate. Confidence remains only at the gate because allocation sites and final inherited field names remain open.

- Completion/confidence score update: existed before as `0/0`; changed to `86/84`. Summary: the non-modal dialog pane is documented in high detail across responsibility, layout, vtable slots, secondary-subobject mapping, mouse behavior, method families, and unresolved allocation/field naming caveats. Evidence: linked `ModelessDialogPane` memory page, struct/vtable type docs, constructor vtable stores, event dispatcher registration, secondary-view offset translation, and vtable data refs.

- Before: `RECONSTRUCTABLE` was blank.
- Changed to: `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP confirms executable class methods, constructor vtable stores, and vtable data references for the class. It is NexusTK-owned UI infrastructure that must be represented in the rebuilt source even though final C++ and parent attachment remain deferred below the `95+` final-audit gate.

- 2026-06-06 A008 parent-chain pass:
  - Before: [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) pointed at this class, but the class had no autogen parent, leaving the layout blocked by `autogen_parent_unknown`.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), the `NexusTK/ui/core/ModelessDialogPane.cpp` root.
  - Evidence: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) is assigned to that generated source root at `88/84`; this class is `86/84`; and the constructor, `IsModal`, mouse-event handler, secondary-view layout mapping, vtable cluster, and shared dialog-infrastructure role all align with that file.
