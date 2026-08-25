*** UID:0000NE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrollableControlPane

## Status

- Source root: NexusTK/ui/controls/ScrollableControlPane.cpp.
- Direct class child: [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md), complete declaration at source position 10.
- Exact human method source is emitted from 15 core children at positions 20-160 and [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md) at position 170.
- UID00011G is a non-emitting split index; [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md) and [UID:0004KR][0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks](by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md) are non-emitting compiler evidence.

## File Role

This module implements the generic ControlPane adapter that owns a polymorphic ScrollablePane, forwards scroll and EventHandler operations, synchronizes rendering/layer membership, paints the legacy focus surface, and reports fixed hit-test part 18. It belongs beside other ui/controls adapters, not in ScrollBar.cpp or feature-dialog modules.

The complete class declaration also provides inline `GetScrollablePane() const`, returning the owned `m_scrollablePane`. [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) and UID0004BO use this wrapper contract after DialogPane selector `3`; neither selector call directly returns a ListPane.

## Exact Generated Source Order

| Position | UID | Source item |
| --- | --- | --- |
| 10 | [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md) | complete ScrollableControlPane declaration and [[CHILDREN]] |
| 20 | [UID:0004KC][0x004985a0-0x00498656.ScrollableControlPaneConstructor](by-memory/0x004985a0-0x00498656.ScrollableControlPaneConstructor.md) | constructor |
| 30 | [UID:0004KD][0x00498660-0x00498695.ScrollableControlPaneDestructor](by-memory/0x00498660-0x00498695.ScrollableControlPaneDestructor.md) | ordinary destructor |
| 40 | [UID:0004KE][0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw](by-memory/0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw.md) | SetScrollTargetValue |
| 50 | [UID:0004KF][0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw](by-memory/0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw.md) | SetScrollCurrentValue |
| 60 | [UID:0004KG][0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw](by-memory/0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw.md) | GetScrollMax |
| 70 | [UID:0004KH][0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw](by-memory/0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw.md) | GetScrollPosition |
| 80 | [UID:0004KI][0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion](by-memory/0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion.md) | UpdateRenderRegion |
| 90 | [UID:0004KJ][0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent](by-memory/0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent.md) | HandlePointerOrMouseEvent |
| 100 | [UID:0004KK][0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent](by-memory/0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent.md) | HandleKeyOrTextEvent |
| 110 | [UID:0004KL][0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent](by-memory/0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent.md) | HandlePacketEvent |
| 120 | [UID:0004KM][0x00498760-0x0049877a.ScrollableControlPaneEnable](by-memory/0x00498760-0x0049877a.ScrollableControlPaneEnable.md) | Enable |
| 130 | [UID:0004KN][0x00498780-0x0049879a.ScrollableControlPaneDisable](by-memory/0x00498780-0x0049879a.ScrollableControlPaneDisable.md) | Disable |
| 140 | [UID:0004KO][0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer](by-memory/0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer.md) | AddToLayer |
| 150 | [UID:0004KP][0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer](by-memory/0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer.md) | RemoveFromLayer |
| 160 | [UID:0004KQ][0x00498880-0x004988cd.ScrollableControlPaneOnPaint](by-memory/0x00498880-0x004988cd.ScrollableControlPaneOnPaint.md) | OnPaint |
| 170 | [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md) | HitTestPart |

## Non-Emitting Evidence Items

- [UID:00011G][0x004985a0-0x004988cd.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cd.ScrollableControlPaneCore.md) covers exact core range 0x004985a0-0x004988cd as a split/evidence index and has no owner/emitter/formal source.
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md) covers scalar-deleting wrapper 0x0049b4f0-0x0049b557; deleting flags, vptr stores, Pane teardown, storage free, guard, and object-size paths are compiler ABI.
- [UID:0004KR][0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks](by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md) covers secondary/tertiary deleting-destructor adjustors 0x0049afd7-0x0049afed.
- The ordinary destructor child is the sole human source cause for all three compiler forms.

## Layout And Ownership

- ScrollableControlPane derives from ControlPane, whose base layout occupies 0x108 bytes.
- One owned ScrollablePane pointer at +0x108 produces complete object size 0x10c.
- Constructor accepts an already allocated polymorphic child; 44 refs from 26 broad feature callers allocate multiple child sizes/types while the wrapper remains 0x10c.
- Constructor transfer and ordinary/scalar virtual deletion prove exclusive ownership.
- Child +0x100/+0x104/+0x108 hold horizontal offset, vertical offset, and common scrollbar inset; all callers pass zero/zero and final values zero, 13, or 10.

## Method And ABI Summary

- Four raw member delegates preserve short/axis arguments into selected-child ScrollablePane setters/getters.
- UpdateRenderRegion passes the same bounds to base and child.
- Secondary EventHandler slots delegate pointer/mouse, key/text, and packet Event pointers; IME remains inherited.
- Enable/Disable update inherited `m_enabled` at `+0x101` only on transition and invalidate bounds. Historical visible/show wording is superseded; Pane visibility is a separate field at `+0xb4`.
- AddToLayer preserves base-first call, two local bounds resets, render updates, and child order 0; RemoveFromLayer is child-first.
- Legacy OnPaint is disabled in EPF mode, otherwise fills bounds and frames only when visible/active.
- HitTestPart uses an unsigned-byte result and two coordinate arguments, returning 18. Direct mov al/retn 8 and shared vtable slot disprove the historical GetControlType interpretation.

## Binary And Vtable Evidence

- Core exact source ranges span 0x004985a0-0x004988cd with documented internal 0xcc alignment and TextEdit successor at 0x004988d0.
- Three vtable views begin 0x0061805c, 0x006180c4, and 0x006180f4 within exact island 0x00618058-0x006180fc.
- Vtable counts are 25 primary, 11 secondary, and 2 tertiary slots; complete object locators/type descriptor and all method/adjustor refs are documented by [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md), UID00011G, and exact children.
- Scalar wrapper has only two adjustor code refs and one primary-vtable data ref; raw ordinary and four tiny delegates preserve zero-start-xref negatives.

## Ownership Decision

- Keep NexusTK/ui/controls/ as the source folder. Broad callers and ControlPane inheritance prove generic UI infrastructure.
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)/[UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) ScrollablePane and ScrollBar.cpp provide child behavior and helper contracts but are dependencies, not this file's owner.
- Pane, ControlPane, EventHandler, GrafPort, RectBounds, and operator-delete pages remain shared dependencies.
- No new destructor-only, type-id, vtable, or wrapper translation unit is justified.

## Generated Verification Contract

After waited generation, ScrollableControlPane.cpp must contain:

- one complete class declaration;
- one inline `GetScrollablePane() const` accessor returning `m_scrollablePane` for wrapper consumers;
- constructor, ordinary destructor, four delegates, UpdateRenderRegion, three EventHandler delegates, Enable, Disable, AddToLayer, RemoveFromLayer, OnPaint, and HitTestPart exactly once in positions 20-170;
- no Empty Emitter Marker for UID0000CE, UID00011G, UID000126, or UID0002PE;
- no manual adjustor/scalar ABI body, no aggregate duplicate, and no old GetControlType body.

## Negative Evidence And Historical Corrections

- Embedded child, provisional ScrollPane pointer, scrollStep/pageSize/range fields, three scroll accessors at 0x00498700/20/40, TextButtonEx base teardown, source-authored scalar wrapper, and no-argument GetControlType are superseded.
- No route or source ownership moves to feature callers, ScrollBar.cpp, Pane.cpp, ControlPane.cpp, or the compiler-family aggregate.
- Zero raw-start xrefs remain evidence; they are not converted into invented callers.

## Score Rationale

Completion 91 records complete source contents/order, class and method split, compiler exclusions, layout/ownership, method ABI, vtables, callers, dependencies, boundaries, and generated verification. Confidence 93 reflects direct binary evidence with only original private/header spelling and zero-route raw helpers preventing a higher final-audit score.

## Cross-References

- [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md) class.
- [UID:00011G][0x004985a0-0x004988cd.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cd.ScrollableControlPaneCore.md) core split index.
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md) scalar compiler wrapper.
- [UID:0004KR][0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks](by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md) adjustor compiler child.
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) ScrollablePane dependency.
- [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) ScrollablePane helper evidence.
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) read-only vtable aggregate.

## Changes

- 2026-07-13 B005 UID0004BP support synchronization:
  - Preserved `91/93`, source route, exact source order, compiler exclusions, and all unrelated file evidence.
  - Added the wrapper accessor/target-consumer contract and corrected the inherited `+0x101` current-state wording to `m_enabled`, with visible/show retained only as superseded history.

- 2026-07-13 B001 complete-source callback:
  - Before: 86/89 with broad aggregate ranges, embedded/provisional child wording, old metric/type-id labels, and unresolved source/destructor representation.
  - After: 91/93 with exact source order 10-170, all real source/compiler/index links, complete layout/ownership/method evidence, and durable generated verification contract.
  - Source path and FILE ownership remain unchanged.

- Historical 2026-05-30 through 2026-06-16 scoring/path/inventory work remains provenance for initial source placement and broad fan-in; stale unresolved labels from those passes are superseded above.
