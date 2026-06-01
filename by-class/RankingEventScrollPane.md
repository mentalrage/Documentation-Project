*** UID:0000BO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingEventScrollPane

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Vtables: [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- Layout: [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- Current recovered file: `source-3/simroot_v2/class_RankingEventScrollPane.cpp`
- Confidence: strong for role and raw/helper boundaries; medium for final raw helper names.

## Class Purpose

`RankingEventScrollPane` is the private scrollbar control used by `RankingEventListPane`. It tracks orientation, current position, max position, hover/pressed parts, drag state, and draws the `SLIDEBG` track plus `SCRBUTT` thumb/buttons.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingEventScrollPane` | `0x004598b0-0x0045990c` | Raw non-IDA constructor. Builds `Pane`, installs vtables, initializes scroll state and hover parts. |
| raw setter/test island | `0x00459910-0x00459a59` | Raw non-IDA current/max/enabled setters plus enabled/test helpers before the modeled mouse handler. |
| `OnMouseEvent` | `0x00459a60-0x00459ccd` | Handles mouse hover, press, drag, release/reset, and scroll position changes. |
| `HasActiveEffect` | `0x00459cd0-0x00459cd4` | Returns false. |
| `OnPaint` | `0x00459ce0-0x0045a3f5` | Draws track segments and thumb using `SLIDEBG.EPF` and `SCRBUTT.EPF`. |
| `HitTestScrollPart` | `0x0045a400-0x0045a70b` | Modeled helper that tests a mouse point against part codes `0..4`; missing from active generated source. |
| `GetScrollRegionRect` | `0x0045a710-0x0045a98a` | Computes scrollbar sub-rectangles for buttons, track, and thumb. |
| `SetHoverIndexRaw` | `0x0045a990-0x0045a9ff` | Raw non-IDA helper that invalidates old/new hover part rectangles. |
| raw press/drag helpers | `0x0045aa00-0x0045ac0f` | Raw non-IDA helpers that record pressed part, drag anchor, and drag-refresh state before the modeled drag calculation at `0x0045ac10`. |
| `DragToPosition` | `0x0045ac10-0x0045adc3` | Converts a mouse/track point into a clamped scroll position and refreshes the owner event list. |
| `ResetStateRaw` | `0x0045add0-0x0045ae2b` | Raw non-IDA helper that resets drag/hover state and invalidates stale hover part. |

## Evidence Notes

- `RankingEventListPane` constructs this pane as its scroll child.
- IDA confirms three class vtables at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`, installed by the raw constructor island and also by the inline child setup in `RankingEventListPane::RankingEventListPane` at `0x0045ae30`.
- Vtable slots bind `0x00459ce0` as paint, `0x00459a60` as mouse input, `0x00459cd0` as the false-return active/effect virtual, and `0x00544e90` as the inherited/default event-update slot.
- IDA reports no function object at the raw starts in `0x004598b0-0x00459a59`, `0x0045a990-0x0045ac0f`, or `0x0045add0-0x0045ae2b`, but raw disassembly shows full helper bodies.
- 2026-05-25 recheck found no direct callers/xrefs to the raw starts. `0x00459a60`, `0x0045a400`, `0x0045a710`, `0x0045ac10`, and `0x0045ae30` remain modeled IDA functions.
- Current `source-3/simroot_v2/class_RankingEventScrollPane.cpp` has an `OnMouseEvent` scoped marker at `0x00459a60`, followed by local structure declarations but no emitted C++ function body before `HasActiveEffect`.
- Current active generated source also omits the modeled hit-test helper at `0x0045a400` and modeled drag helper at `0x0045ac10`; both appear only in metadata/IDA evidence.
- 2026-05-27 IDA `py_eval` recheck strengthens the raw helper boundary evidence: constructor/setter starts `0x004598b0`, `0x00459910`, `0x00459940`, `0x00459970`, `0x004599d0`, `0x00459a00`, `0x00459a20`, `0x00459a40`, and reset start `0x0045add0` still have no IDA function objects or direct xrefs, but each has a normal body/return and local calls/field writes matching the scroll pane state model.
- The control is feature-specific in current usage, but it shares visual behavior with other custom scrollbars and may eventually share implementation names with generic scrollbar code.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md)
- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md)
- [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md)
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md)
- [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)
- [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page documented the private scrollbar role, raw/modelled method islands, vtables, resource usage, and generated-source omissions but remained unevaluated.
  - After: score reflects documented scroll state, mouse handling, painting, hit-test/geometry helpers, drag/reset behavior, vtable evidence, and raw-helper caveats. The misplaced ranking resource reference was moved into Cross-References.
  - Evidence: linked memory child pages and [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md) record IDA-confirmed modelled functions, raw helper bodies, vtable slot binding, and `SLIDEBG`/`SCRBUTT` resource use.
- 2026-05-31: Marked reconstructable and attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) without adding C++.
  - Before: the class page was scored but not connected to validator autogen/reconstruction metadata.
  - After: the class is marked as a reconstructable ranking-dialog helper class, while source emission remains blocked until final helper names and source shape are near-final.
  - Evidence: IDA-confirmed vtables, child allocation/setup from `RankingEventListPane`, and linked exact memory child pages place the class inside `RankingDialog.cpp`.
- 2026-05-27: Changed the class confidence note from medium raw helper boundaries to strong raw/helper boundaries with medium final raw helper names. Evidence: IDA `py_eval` confirmed normal raw bodies/returns for the constructor/setter island and reset helper while still reporting no modeled function objects or direct xrefs for those raw starts.
