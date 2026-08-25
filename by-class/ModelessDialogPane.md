*** UID:00008K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ModelessDialogPane.h"
#include "ControlPane.h"
#include "Event.h"
#include "ScreenPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_MODELESSDIALOGPANE_H
#define NEXUSTK_UI_CORE_MODELESSDIALOGPANE_H

#include "DialogPane.h"

class Event;

class ModelessDialogPane : public DialogPane
{
public:
    ModelessDialogPane(const wchar_t *titleText);
    virtual bool IsModal();
    virtual bool HandlePointerOrMouseEvent(Event *event);
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ModelessDialogPane

## Status

- Confidence: strong for recovered behavior, source route, method boundaries, vtable views, and inherited dialog-state roles.
- Likely source: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- Parent/C++ status: attached to [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), the `NexusTK/ui/core/ModelessDialogPane.cpp` shared dialog-infrastructure root. B015 source-quality recheck resolves the major class blockers, so the class page now carries a declaration/source-shape block with `[[CHILDREN]]`; exact method bodies remain owned by [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md), [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md), and [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md).
- Current recovered source: `source-3/simroot_v2/class_ModelessDialogPane.cpp`
- Memory: [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- Type docs: [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- Vtables: [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)

## Responsibility

`ModelessDialogPane` is the shared non-blocking dialog pane. It keeps the ordinary [UID:0000IT][DialogPane](by-file/DialogPane.md) control model but returns non-modal state and routes mouse events without stopping the rest of the UI.

## Current Source Contract

- The complete class declaration belongs in `ModelessDialogPane.h`; the CPP channel contains includes plus `[[CHILDREN]]`. The former CPP-local declaration and blank H channel are retained below only as historical project state.
- Secondary slot `0x00618cac` is the canonical `HandlePointerOrMouseEvent(Event *)` override. Its physical entry receives the EventHandler view at complete-object `+0xa0`, then recovers the complete object with `this - 0xa0`.
- [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) owns the full emitted body, including drag, clamp, pressed-control, double-click, release, wheel, persistence, presentation, and command-refresh behavior.
- The interaction state is inherited from `DialogPane`, not a derived tail. Corrected field order is `m_dragOriginY` at `+0x20c`, `m_dragOriginX` at `+0x210`, then clamp minX/minY/maxX/maxY at `+0x22c/+0x230/+0x234/+0x238`.
- Accepted helper spelling is `SavePosition(const RectBounds *unusedBounds)`, `RefreshActionButtonState()`, `SetSelectionVisualState`, and `g_pScreenPane->RenderPresentation()`.
- Event types 4-6 and default do not explicitly return false: they reach the common return with the original uninitialized local. This non-ideal source artifact is retained for runtime parity.

## Current Evidence And Negative Evidence

- Exact target evidence is 1102 bytes, 348 instructions, 53 blocks, complexity 27, full-byte SHA-256 `272B831D54D4AB1957322C400E6909E21A98D9A2A3FC1743CA80EEC3921EEB4C`, and the sole static entry reference at `0x00618cac`.
- No direct branch caller or constructor allocation route was found. That negative evidence supports virtual-only dispatch and remains a provenance cap, not a reason to omit source.
- The handler excludes its `66 90` alignment, eight-entry switch table, two successor adjustor thunks, padding, and scalar deleting destructor.
- `0x00557140` is ScreenPane-owned presentation, not Surface-owned notification behavior; `0x0049fe20` refreshes the action-button state rather than changing focus.

## Superseded Source Assumptions

- The 2026-06-22 B015 pass used `HandleMouseEvent(InputEvent *)`, placed the declaration in CPP, left H blank, reversed drag-origin axes, described clamp fields as top/left/bottom/right, used `UpdateFocusedControl`, and routed presentation through Surface. Those were useful intermediate hypotheses, but exact UID000312 instruction, helper, receiver, and formal-channel analysis supersedes them.
- The stale Wave-era `vtable_count:0` remains preserved as rejected metadata; constructor writes and `.rdata` prove three views.

## Layout Evidence

Generated metadata and IDA vtable refs support a `DialogPane` base with three vtable slots. B015 raw PE and .rdata recheck supersedes the stale Wave3 `vtable_count:0` value: constructor stores and vtable data prove primary, secondary, and tertiary views. See [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) for the secondary-view offset mapping used by the mouse handler.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x000` | primary vtable / `DialogPane` base | Constructor calls `DialogPane::DialogPane`, then installs vtable `0x00618c48` at `0x004a07bd`. |
| `+0x0a0` | secondary event/list subobject vtable | Constructor writes vtable `0x00618ca8` at `0x004a07c4` and registers `this + 160` with `EventDispatcher::AddToModalList`. |
| `+0x0a4` | third vtable slot | Constructor writes vtable `0x00618cd8` at `0x004a07ca`, matching the common multi-vtable `DialogPane` pattern. |
| base `+0x208..+0x238` | inherited `DialogPane` mouse/drag/pressed/selection/clamp state | `HandlePointerOrMouseEvent` runs as the secondary view (`this == object + 0xa0`), so generated `context + 0x168..0x198` accesses translate to base `DialogPane +0x208..+0x238`; these are not a `ModelessDialogPane`-specific tail. |

## Vtable Evidence

| View | Vtable | Key slots |
| --- | --- | --- |
| primary | `0x00618c48` | Inherited `DialogPane` scalar destructor `0x0048c350` at `+0x00`, dialog draw/layout/update slots through `+0x58`. |
| secondary | `0x00618ca8` | `DialogPane` adjustor thunk `0x0048c27b` at `+0x00`, `HandlePointerOrMouseEvent` `0x004a0840` at `+0x04`, `IsModal` `0x004a0830` at `+0x08`. |
| tertiary | `0x00618cd8` | `DialogPane` adjustor thunk `0x0048c286` at `+0x00`, base event slot `0x00544e90` at `+0x04`. |

The third table is only two slots long. The following dword at `0x00618ce0` belongs to neighboring `DLGFRAME.*` data/string storage, not this class.

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| [UID:000310][0x004a0760-0x004a0827.ModelessDialogPaneConstructor](by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md) | constructor | Creates a default 100x100 modeless dialog shell and registers it with the event dispatcher/list manager. |
| [UID:000311][0x004a0830-0x004a0835.ModelessDialogPaneIsModal](by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md) | `IsModal` | Reports non-modal behavior. |
| [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) | `HandlePointerOrMouseEvent` | Complete drag, hover, click, double-click, wheel, persistence, presentation, and control activation dispatcher. |

## Behavior Notes

- Mouse event type `0` handles movement; if dragging, it updates pane position and clamps to configured bounds.
- Mouse event type `1` handles mouse-down. Hit type `10` is treated as title/drag chrome; other hit types enter pressed-control state.
- Mouse event type `2` handles left-button double-click. It hit-tests the point and dispatches to the resolved control when the point is inside the dialog rectangle.
- Mouse event type `3` handles release. It ends drag mode, restores prior dialog mode, dispatches release input, calls the Surface/frame presentation helper at `0x00557140` with `dword_67A7CC`, and activates the item if the release still matches the pressed item.
- Mouse event type `7` handles mouse wheel input. It routes wheel events to the resolved control when the cursor is inside the dialog rectangle; it is not passive hover routing.

The constructor registers the secondary event/list view (`this +0xa0`) through `EventDispatcher::AddToModalList`. This is dispatcher-list registration, not proof of modal behavior; `IsModal()` returning `false` is the modeless behavior discriminator during traversal.

## Field And Helper Directions

B015 resolves the inherited state names used by the modeless handler to high-probability source roles. The current shared [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) page keeps the wider `DialogPane` canonical names where broader evidence requires them, but the Modeless handler should be read with this role map:

| Offset | Modeless handler role | Evidence |
| --- | --- | --- |
| `+0x1f8` | `m_dialogConfigId` | Constructor/base passes `0xffff`; release saves position only when this is not `0xffff`. |
| `+0x1fc` | `m_controlManager` | Hit-test and dispatch helpers operate through this manager. |
| `+0x208` | `m_titleDragActive` | Set only for title/chrome dragging and cleared on release. |
| `+0x209` | `m_savedPaneMode` | Saves `Pane +0xb5` and restores through [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md). |
| `+0x20c/+0x210` | `m_dragOriginY` / `m_dragOriginX` | Mouse Y/X origin saved on drag start and subtracted during vertical/horizontal movement. |
| `+0x214` | `m_hoverControlId` | Compared with the current hit control before interactive hover/update callback flow. |
| `+0x218` | `m_pressedControlActive` | Gates pressed-control move/release paths. |
| `+0x21c/+0x220` | `m_pressedControlId` / `m_pressedHitType` | Stores the original press target and hit type for release matching. |
| `+0x224/+0x228` | `m_selectedControlId` / `m_selectedHitType` | Selection helper and release reset use id `-1` and neutral hit type `10`. |
| `+0x229` | `m_dragClampEnabled` | Enables bounds clamping while dragging. |
| `+0x22c/+0x230/+0x234/+0x238` | `m_dragClampMinX` / `m_dragClampMinY` / `m_dragClampMaxX` / `m_dragClampMaxY` | Exact axis-ordered clamp limits used by drag movement. |

Best current helper names for this class are `DialogPane::HitTestControls`, `DialogPane::DispatchInputToControl`, `DialogPane::SavePosition(const RectBounds *unusedBounds)`, `DialogPane::RefreshActionButtonState`, `DialogPane::SetSelectionVisualState`, `Pane::SetMode`, `EventDispatcher::AddToModalList`, and [UID:00039P][0x00557140-0x00557377.SurfaceRenderPresentation](by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md) for the post-release frame refresh.

## Static Reachability

- Raw PE scan of `NexusTK.exe` found no VA/RVA/raw-offset pointer hits and no `.text` rel32 calls/jumps to constructor `0x004a0760`.
- `IsModal` and `HandlePointerOrMouseEvent` have static VA refs only from vtable data at `0x00618cb0` and `0x00618cac`.
- Constructor vtable immediates appear only as stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`.
- Absence of direct constructor callers/pointers is now negative reachability evidence and a confidence cap, not an unresolved allocation blocker or a reason to withhold first-draft constructor source.

## Rejected Alternatives And Remaining Caps

- No feature-dialog, `AlertPanes`, or `EventDispatcher` source route is supported. The dispatcher owns list traversal/routing; this pane owns its input policy.
- Do not introduce a `ModelessDialogPane`-specific derived tail for `+0x208..+0x238`; those fields are inherited `DialogPane` interaction state.
- Do not invent direct constructor callers. The raw PE scan found none.
- Do not hand-author vtable stores, RTTI, SEH, security-cookie operations, scalar-deleting wrappers, or adjustor thunks.
- Remaining caps are original allocation/factory provenance, exact source spelling for `0x00544d30` as a pane interaction/init helper, and final historical header style (`wchar_t *` versus `const wchar_t *`, and whether `override` was used).

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

- 2026-06-22 B015 source-quality incorporation:
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`, owner/emitter unchanged at [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), and declaration/source-shape C++ populated with child emission.
  - Summary/evidence: B015 local PE and support-doc reanalysis resolves the stale allocation/field/event/vtable blockers: constructor has no direct static caller/pointer route but is source-ready; mouse event type `2` is left double-click and type `7` is mouse wheel; `0x00557140` is Surface/frame presentation rather than input-manager notification; `+0x208..+0x238` are inherited `DialogPane` interaction fields with high-probability roles; and Wave3 `vtable_count:0` is stale against constructor stores and .rdata. Confidence remains below final-audit because original factory/allocation provenance, helper spelling for `0x00544d30`, and exact historical header style are still not proven.
