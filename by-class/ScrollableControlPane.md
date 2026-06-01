*** UID:0000CE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollableControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- Main address ranges: `0x004985a0-0x004988cc`, destructor `0x0049b4f0-0x0049b557`, and type-id helper `0x0049b900-0x0049b905`
- Current recovered file: `source-3/simroot_v2/class_ScrollableControlPane.cpp`

## Class Purpose

`ScrollableControlPane` is a `ControlPane`-derived wrapper around scrollable child content. It owns or references a scroll-control object, delegates range and position queries to that object, refreshes the child clip/render region, and draws a focus/highlight outline in the older non-EPF UI mode.

## Observed State

Important recovered state:

```text
+0x000  primary vtable
+0x0a0  secondary/control vtable area
+0x0fb  overlay/focus enabled flag
+0x100  selection/highlight flag
+0x108  scroll control/content pointer
```

The exact layout still needs a named struct pass, but the offsets above are stable across the recovered methods.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction | `0x004985a0-0x00498655` | Calls `ControlPane`, installs vtables, initializes scroll step/page/range, calls embedded control initialize. |
| Region/range/enabled state | `0x004986e0-0x00498799` | Refresh child layout, query scroll position/range, and enable/disable with invalidation. |
| Layer/paint | `0x004987a0-0x004988cc` | Add/remove child scroll control from layer and draw older-mode focus outline. |
| Destructor | `0x0049b4f0-0x0049b557` | Destroy embedded scroll control, chain base teardown, and optionally free object memory. |
| Type id | `0x0049b900-0x0049b905` | Return control type `0x12`. |

## Evidence Notes

- Constructor calls `ControlPane::ControlPane(&this->ControlPane, 4, parentPane)`.
- IDA MCP and Wave3 xrefs report 44 direct constructor call references across many dialogs.
- `GetControlType` returns `0x12`.
- `AddToLayer` calls `Pane::AddToLayer`, converts the incoming rect to a local rect, updates render region, updates child clip rect, and delegates child layer attach.

## Current Caveats

- The generated scalar deleting destructor currently names `TextButtonExControlPane::~TextButtonExControlPane` as the base teardown. Treat that as provisional until base-subobject ownership is verified.

## Cross-References

- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:00011G][0x004985a0-0x004988cc.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md)
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md)
- [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneTypeId](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneTypeId.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/82`.
  - Before: The page was unevaluated despite documenting wrapper behavior, stable offsets, method families, constructor fanout, and base-teardown caveats.
  - After: Scored as moderate-high completion and strong confidence for the scrollable control wrapper.
  - Evidence: Existing method-family table, observed state, constructor/xref notes, control type id, and memory/file cross-references support the score.
