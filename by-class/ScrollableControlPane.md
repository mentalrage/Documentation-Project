*** UID:0000CE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollableControlPane

## Status

- Confidence: strong for live IDA boundaries, generic wrapper ownership, embedded scroll-control state, layer/paint behavior, destructor, and type-id evidence.
- Likely source file: [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- Main address ranges: `0x004985a0-0x004988cc`, destructor `0x0049b4f0-0x0049b557`, and type-id helper `0x0049b900-0x0049b905`
- Autogen parent: [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- Corrected assignment-gate state: this class page is now `86/89`, and direct file parent [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) is `86/89`, so retaining `AUTOGEN_PARENT_UID:0000NE` is supported under the `85/85` gate.

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
| Region/range/enabled state | `0x004986e0-0x00498799` | Refresh child layout, query scroll position/range/page-or-extent, and enable/disable with invalidation. |
| Layer/paint | `0x004987a0-0x004988cc` | Add/remove child scroll control from layer and draw older-mode focus outline. |
| Destructor | `0x0049b4f0-0x0049b557` | Destroy embedded scroll control, chain base teardown, and optionally free object memory. |
| Type id | `0x0049b900-0x0049b905` | Return control type `0x12`. |

## Evidence Notes

- Live IDA MCP on 2026-06-05 confirms the core constructor, region refresh, three scroll metric accessors, enable/disable, add/remove layer, paint helper, scalar deleting destructor, and type-id helper as exact functions.
- The constructor calls `ControlPane::ControlPane(&this->ControlPane, 4, parentPane)`, installs the three `ScrollableControlPane` vtable bases, stores the embedded child control pointer at object offset `0x108`, initializes child step/page/range state, and marks the wrapper dirty.
- Live xrefs report 44 direct constructor call sites across many dialogs and menu panes, matching generic `ui/controls` infrastructure ownership.
- The metric helpers delegate through the embedded child control's metrics object; the core page now records the previously omitted third metric helper at `0x00498740`.
- `AddToLayer` calls `Pane::AddToLayer`, converts the incoming rectangle to local coordinates, updates render region and child clip rect, and delegates child layer attach. `OnPaint` draws only in the older non-EPF path and uses the enabled/focus flags for the highlighted frame.
- `GetControlType` returns `0x12`. The destructor page records the embedded child deletion, base pane teardown, secondary adjustor thunks, and scalar-delete flag behavior.
- 2026-06-07 IDA MCP refresh reconfirmed all class-owned method ranges: constructor `0x004985a0-0x00498656`, layout helper `0x004986e0-0x004986fb`, three metric accessors through `0x00498758`, enable/disable through `0x0049879a`, layer add/remove and paint through `0x004988cd`, destructor `0x0049b4f0-0x0049b557`, and type-id helper `0x0049b900-0x0049b905`.
- The same pass reconfirmed 44 constructor callers, destructor callees `sub_544580`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`, destructor/type-id vtable refs, and all immediate padding gaps around the destructor/type-id children.

## Current Caveats

- The generated scalar deleting destructor currently names `TextButtonExControlPane::~TextButtonExControlPane` as the base teardown. Treat that as provisional until base-subobject ownership is verified.

## Score Rationale

Completion is `86` because the class page now records purpose, stable offsets, method-family inventory, parent file, direct child pages, current IDA range/caller evidence, destructor/type-id details, and corrected assignment-gate status. It remains below final-source quality because the inner scroll-control field names and the generated base-teardown artifact still need a final type-layout pass.

Confidence is `89` because current IDA evidence supports the class owner, vtables, broad constructor fan-in, and all documented child boundaries. Confidence stays below `95` because final source-facing member names and helper names remain provisional.

## Cross-References

- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:00011G][0x004985a0-0x004988cc.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md)
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md)
- [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneTypeId](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneTypeId.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-06-05 live IDA refresh and parent attach:
  - Before: `COMPLETION:78`, `CONFIDENCE:82`, blank `AUTOGEN_PARENT_UID`, and stale recovered-source wording. The method-family summary did not call out the third scroll metric helper.
  - After: `COMPLETION:82`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000NE`; final C++ remains blank under the 95/95 gate.
  - Evidence: live IDA confirms core method boundaries, constructor state setup, 44 constructor callers, metric delegation including `0x00498740`, layer/paint behavior, destructor ownership cleanup, and type id `0x12`. Parent attachment now satisfies the 80/80 gate because this class is `82/88` and [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) is `82/86`.

- 2026-05-30: Changed completion/confidence from `0/0` to `78/82`.
  - Before: The page was unevaluated despite documenting wrapper behavior, stable offsets, method families, constructor fanout, and base-teardown caveats.
  - After: Scored as moderate-high completion and strong confidence for the scrollable control wrapper.
  - Evidence: Existing method-family table, observed state, constructor/xref notes, control type id, and memory/file cross-references support the score.

- 2026-06-07 A001 Batch004 parent-gate refresh:
  - Before: `82/88`, attached to [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) under the older gate.
  - After: `86/89`, retaining `AUTOGEN_PARENT_UID:0000NE` under the corrected `85/85` gate.
  - Evidence: current IDA MCP reconfirmed the complete method inventory, 44 constructor callers, destructor callees and vtable stores, type-id vtable cell, and padding boundaries used by the child memory pages.
