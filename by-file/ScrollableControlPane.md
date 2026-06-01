*** UID:0000NE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrollableControlPane

## Status

- Confidence: strong.
- Proposed module: `ui/controls/ScrollableControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_ScrollableControlPane.cpp`
- Main address clusters: `0x004985a0-0x004988cc`, destructor `0x0049b4f0-0x0049b557`, and type-id helper `0x0049b900-0x0049b905`

## File Role

`ScrollableControlPane` is a generic control wrapper for scrollable child content. It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), stores a scroll/control object pointer, delegates scroll position and range queries to the embedded metrics object, and clips/adds the inner content pane when the control is attached to a layer.

This is control infrastructure rather than scrollbar drawing. The visible scrollbar pane is documented under [UID:0000NF][ScrollBar](by-file/ScrollBar.md).

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScrollableControlPane` | `0x004985a0-0x004988cc`, `0x0049b4f0-0x0049b557`, `0x0049b900-0x0049b905` | Control type `0x12`; wraps scrollable content, delegates range/position, enable/disable, layer add/remove, paint focus outline, destructor, and type-id virtual. |
| Adjustor thunks | `0x0049afd7`, `0x0049afe2` | Disabled thunk material around the scalar deleting destructor. |

## Ownership Decision

Keep this in `ui/controls` beside button, checkbox, image, text, and other control-pane adapters. Constructor fan-in is broad across board, mail, clan, item, menu, user list, server select, phone book, and alert dialogs, which matches a generic control wrapper.

Do not merge it into `ScrollBar.cpp`. It depends on scroll metrics/control objects, but its inheritance and behavior are `ControlPane`-centric.

## Evidence Notes

- `ScrollableControlPane::ScrollableControlPane` calls `ControlPane::ControlPane(&this->ControlPane, 4, parentPane)`.
- `GetControlType` returns `0x12`.
- IDA MCP and Wave3 xrefs report 44 direct constructor call references across feature dialogs and menu panes.
- `AddToLayer` calls `Pane::AddToLayer`, updates the local render region, updates the inner content clip rect, and then delegates the child add-to-layer call.
- The destructor destroys the embedded scroll control object before chaining into generated base teardown. Current generated source names that base as `TextButtonExControlPane`, which is likely owner-name pollution rather than true inheritance.

## Cross-References

- [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md)
- [UID:00011G][0x004985a0-0x004988cc.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md)
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md)
- [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneTypeId](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneTypeId.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document captures role, proposed contents, ownership decision, constructor fan-in, control type, layer behavior, generated base-name pollution, and cross-references; confidence is high because the page is narrow and strongly verified.
