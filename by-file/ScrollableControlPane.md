*** UID:0000NE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrollableControlPane

## Status

- Confidence: strong for source ownership, live IDA method clusters, broad constructor fan-in, child-control delegation, destructor/type-id evidence, and separation from scrollbar drawing.
- Proposed module: `ui/controls/ScrollableControlPane.cpp`
- Main address clusters: `0x004985a0-0x004988cc`, destructor `0x0049b4f0-0x0049b557`, and type-id helper `0x0049b900-0x0049b905`
- Corrected assignment-gate state: this file page is now `86/89`, so it can remain the direct parent for [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md), which is also at or above `85/85`.

## File Role

`ScrollableControlPane` is a generic control wrapper for scrollable child content. It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), stores a scroll/control object pointer, delegates scroll position and range queries to the embedded metrics object, and clips/adds the inner content pane when the control is attached to a layer.

This is control infrastructure rather than scrollbar drawing. The visible scrollbar pane is documented under [UID:0000NF][ScrollBar](by-file/ScrollBar.md).

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScrollableControlPane` | `0x004985a0-0x004988cc`, `0x0049b4f0-0x0049b557`, `0x0049b900-0x0049b905` | Control type `0x12`; wraps scrollable content, delegates range/position/page-or-extent metrics, enable/disable, layer add/remove, paint focus outline, destructor, and type-id virtual. |
| Adjustor thunks | `0x0049afd7`, `0x0049afe2` | Disabled thunk material around the scalar deleting destructor. |

## Ownership Decision

Keep this in `ui/controls` beside button, checkbox, image, text, and other control-pane adapters. Constructor fan-in is broad across board, mail, clan, item, menu, user list, server select, phone book, and alert dialogs, which matches a generic control wrapper.

Do not merge it into `ScrollBar.cpp`. It depends on scroll metrics/control objects, but its inheritance and behavior are `ControlPane`-centric.

## Evidence Notes

- Live IDA MCP on 2026-06-05 confirms the core constructor, region refresh, three metric accessors, enable/disable helpers, add/remove layer helpers, paint helper, scalar deleting destructor, and type-id helper as exact functions.
- `ScrollableControlPane::ScrollableControlPane` calls `ControlPane::ControlPane(&this->ControlPane, 4, parentPane)`, installs three `ScrollableControlPane` vtable bases, stores the embedded child control pointer, initializes child step/page/range state, and marks the wrapper dirty.
- `GetControlType` returns `0x12`.
- Live xrefs report 44 direct constructor call references across feature dialogs and menu panes.
- `AddToLayer` calls `Pane::AddToLayer`, updates the local render region, updates the inner content clip rect, and delegates the child add-to-layer call.
- The destructor destroys the embedded scroll control object before chaining into base pane teardown. The historical `TextButtonExControlPane` base-name artifact is treated as owner-name pollution rather than true inheritance.
- 2026-06-07 IDA MCP refresh reconfirmed the complete method inventory: constructor `0x004985a0-0x00498656`, layout helper `0x004986e0-0x004986fb`, metric accessors `0x00498700-0x00498718`, `0x00498720-0x00498738`, and `0x00498740-0x00498758`, enable/disable `0x00498760-0x0049877a` and `0x00498780-0x0049879a`, layer add/remove `0x004987a0-0x0049885c` and `0x00498860-0x00498876`, paint `0x00498880-0x004988cd`, destructor `0x0049b4f0-0x0049b557`, and type-id helper `0x0049b900-0x0049b905`.
- The same refresh found 44 constructor call sites and reconfirmed the destructor/type-id vtable refs and padding boundaries used by the child memory pages.

## Score Rationale

Completion is `86` because this file page now has proposed source placement, class/file role, exact child method inventory, constructor fan-in, destructor and type-id child pages, vtable evidence, ScrollBar separation, and corrected assignment-gate status. It remains below final-audit quality because final member names, helper names, and source-facing destructor representation are not yet complete.

Confidence is `89` because current IDA evidence verifies the module's method cluster, vtable ownership, call fan-in, and child-page boundaries. Confidence stays below `95` because final source names and the generated base-teardown artifact still need a later type-layout pass.

## Cross-References

- [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md)
- [UID:00011G][0x004985a0-0x004988cc.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md)
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md)
- [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneTypeId](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneTypeId.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-06-05 live IDA refresh:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:86`, stale recovered-source wording, and evidence text that mixed live IDA with older external xref provenance.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, with live IDA evidence for the full core/destructor/type-id cluster and the third scroll metric helper.
  - Summary/evidence: live IDA confirms method boundaries, constructor state setup, broad constructor fan-in, child metric delegation, layer/paint behavior, destructor cleanup, and the `ui/controls` ownership split from `ScrollBar.cpp`.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented `ScrollableControlPane` constructor anchor at `0x004985a0`; proposed-source-tree keeps the generic control wrapper in `ui/controls/`, separate from pane-level `ui/core/ScrollBar.cpp`.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document captures role, proposed contents, ownership decision, constructor fan-in, control type, layer behavior, generated base-name pollution, and cross-references; confidence is high because the page is narrow and strongly verified.

- 2026-06-07 A001 Batch004 parent-gate refresh:
  - Before: `84/88`, already projected to `NexusTK/ui/controls/`.
  - After: `86/89`; parent status now satisfies the corrected `85/85` gate for the ScrollableControlPane class page.
  - Summary/evidence: current IDA MCP lookup reconfirmed the complete core/destructor/type-id method inventory, 44 constructor callers, destructor/type-id vtable refs, and child padding boundaries.
