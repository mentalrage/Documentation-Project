*** UID:0000CE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollableControlPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class Pane;
class ScrollablePane;
struct RectBounds;

class ScrollableControlPane : public ControlPane
{
public:
    ScrollableControlPane(const RectBounds *bounds,
                          ScrollablePane *scrollablePane,
                          int horizontalScrollBarOffset,
                          int verticalScrollBarOffset,
                          int scrollBarInset);
    virtual ~ScrollableControlPane();

    ScrollablePane *GetScrollablePane() const
    {
        return m_scrollablePane;
    }

    void SetScrollTargetValue(short targetValue, char axis);
    void SetScrollCurrentValue(short currentValue, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void Enable();
    virtual void Disable();
    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    ScrollablePane *m_scrollablePane;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollableControlPane

## 2026-08-22 UID0000KF Header-Route Closure

The complete declaration now emits through `ScrollableControlPane.h`; the CPP channel keeps the header include plus exact authored children. ItemMenuDialogs consumes `ScrollableControlPane(const RectBounds *, ScrollablePane *, int, int, int)` through class UID0000CE and file owner/emitter UID0000NE. Core UID00011G remains a false/non-emitting split evidence index and is never substituted as a declaration owner or emitter.

## Status

- Complete source class declaration owned/emitted by [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) at source position 10.
- Direct base is ControlPane; complete object size is 0x10c.
- Exact source methods are emitted by 15 UID00011G split children plus [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md) HitTestPart.
- UID00011G, [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md), and [UID:0004KR][0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks](by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md) are evidence/index/compiler pages and emit no duplicate source.

## Class Purpose

ScrollableControlPane is a ControlPane adapter that exclusively owns a caller-created polymorphic ScrollablePane. It initializes child placement/inset state, forwards scroll and EventHandler operations, keeps wrapper and child render/layer state synchronized, provides legacy non-EPF painting, and reports a fixed hit-test part.

## Verified Layout

| Offset | Field/view | Evidence |
| --- | --- | --- |
| +0x000 | primary Pane/GrafPort vtable view | constructor/destructor stores and primary table |
| +0x0a0 | secondary EventHandler vtable view | event delegate entries and adjustor 0x0049afd7 |
| +0x0a4 | tertiary interface vtable view | adjustor 0x0049afe2 |
| +0x0ff | inherited m_controlFlags | constructor writes 1 |
| +0x101 | inherited m_enabled | Enable/Disable and OnPaint; the historical `m_controlVisible` spelling is superseded |
| +0x102 | inherited m_controlActive | constructor clears and OnPaint tests |
| +0x108 | ScrollablePane *m_scrollablePane | constructor transfer, all delegates, ordinary/scalar delete |

- The accepted ControlPane base layout occupies 0x108 bytes; the one derived pointer yields complete size 0x10c.
- The child is separately allocated with multiple derived vtables/sizes. Embedded ScrollPane and borrowed Pane interpretations are rejected.
- Constructor transfer and virtual delete in both destruction forms establish exclusive raw-pointer ownership.

## Exact Source Children

| Position | UID | Method/range |
| --- | --- | --- |
| 20 | [UID:0004KC][0x004985a0-0x00498656.ScrollableControlPaneConstructor](by-memory/0x004985a0-0x00498656.ScrollableControlPaneConstructor.md) | constructor 0x004985a0-0x00498656 |
| 30 | [UID:0004KD][0x00498660-0x00498695.ScrollableControlPaneDestructor](by-memory/0x00498660-0x00498695.ScrollableControlPaneDestructor.md) | ordinary destructor 0x00498660-0x00498695 |
| 40 | [UID:0004KE][0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw](by-memory/0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw.md) | SetScrollTargetValue 0x004986a0-0x004986af |
| 50 | [UID:0004KF][0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw](by-memory/0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw.md) | SetScrollCurrentValue 0x004986b0-0x004986bf |
| 60 | [UID:0004KG][0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw](by-memory/0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw.md) | GetScrollMax 0x004986c0-0x004986cf |
| 70 | [UID:0004KH][0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw](by-memory/0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw.md) | GetScrollPosition 0x004986d0-0x004986df |
| 80 | [UID:0004KI][0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion](by-memory/0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion.md) | UpdateRenderRegion 0x004986e0-0x004986fb |
| 90 | [UID:0004KJ][0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent](by-memory/0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent.md) | HandlePointerOrMouseEvent 0x00498700-0x00498718 |
| 100 | [UID:0004KK][0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent](by-memory/0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent.md) | HandleKeyOrTextEvent 0x00498720-0x00498738 |
| 110 | [UID:0004KL][0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent](by-memory/0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent.md) | HandlePacketEvent 0x00498740-0x00498758 |
| 120 | [UID:0004KM][0x00498760-0x0049877a.ScrollableControlPaneEnable](by-memory/0x00498760-0x0049877a.ScrollableControlPaneEnable.md) | Enable 0x00498760-0x0049877a |
| 130 | [UID:0004KN][0x00498780-0x0049879a.ScrollableControlPaneDisable](by-memory/0x00498780-0x0049879a.ScrollableControlPaneDisable.md) | Disable 0x00498780-0x0049879a |
| 140 | [UID:0004KO][0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer](by-memory/0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer.md) | AddToLayer 0x004987a0-0x0049885c |
| 150 | [UID:0004KP][0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer](by-memory/0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer.md) | RemoveFromLayer 0x00498860-0x00498876 |
| 160 | [UID:0004KQ][0x00498880-0x004988cd.ScrollableControlPaneOnPaint](by-memory/0x00498880-0x004988cd.ScrollableControlPaneOnPaint.md) | OnPaint 0x00498880-0x004988cd |
| 170 | [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md) | HitTestPart 0x0049b900-0x0049b905 |

## Constructor And Scroll Contract

- Constructor calls ControlPane kind 4, stores m_scrollablePane, writes child horizontal offset +0x100, vertical offset +0x104, and common inset +0x108, then calls SetBounds(bounds, 0).
- All 44 constructor refs from 26 unique caller functions pass zero for horizontal/vertical offsets; final inset is usually zero and is 13 or 10 in supported layouts.
- Four small member delegates load m_scrollablePane and forward short/axis state to ScrollablePane selected-child helpers.
- The inline `GetScrollablePane() const` accessor exposes the owned child. [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) and UID0004BO use it after resolving DialogPane selector `3`; the selector itself returns this wrapper, not a direct ListPane.
- GetScrollMax reads the selected child's +0x100 maximum/target word; GetScrollPosition reads +0xfe current position. These are separate from inherited GetScrollRange/GetOverflowCount virtuals.
- Zero raw-start xrefs for the ordinary body and four delegates remain documented on exact children and cap confidence without deferring source.

## Virtual Behavior

- UpdateRenderRegion calls GrafPort base behavior then child UpdateRenderRegion with the same bounds argument.
- Secondary EventHandler methods forward pointer/mouse, key/text, and packet Event pointers. HandleImeEvent remains inherited.
- Enable/Disable toggle inherited `m_enabled` only on change and invalidate m_bounds. The old visible/show interpretation conflated this control-enabled gate with the separate Pane visibility field at `+0xb4`.
- AddToLayer preserves base call, two local-bounds resets, wrapper/child render updates, and child attach at order 0 after this.
- RemoveFromLayer removes the child before Pane.
- OnPaint suppresses legacy drawing when g_useEpfAssets is 1; otherwise it fills bounds and draws an active frame only when visible and active.
- HitTestPart has byte return and two int coordinates; fixed result is 18. The historical no-argument int GetControlType interpretation is ABI-incompatible.

## Destruction And Compiler Artifacts

- Human destructor source deletes m_scrollablePane exactly once on [UID:0004KD][0x00498660-0x00498695.ScrollableControlPaneDestructor](by-memory/0x00498660-0x00498695.ScrollableControlPaneDestructor.md).
- Pane ordinary teardown at 0x00544580 is implicit base destruction, not TextButtonEx inheritance and not an explicit source call.
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md) restores vtables, repeats child cleanup, handles deleting flags/deallocation/guarded size 0x10c, and is non-emitting compiler ABI output.
- [UID:0004KR][0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks](by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md) adjusts secondary/tertiary this by 0xa0/0xa4 and jumps to UID000126; it is also non-emitting.

## Vtables, Callers, And Boundaries

- Vtable island 0x00618058-0x006180fc contains primary 25-slot, secondary 11-slot, and tertiary 2-slot tables at 0x0061805c/0x006180c4/0x006180f4.
- Complete object locators are 0x00645cbc, 0x00645d1c, and 0x00645d30; type descriptor is 0x00675864.
- Constructor has 44 refs from 26 broad feature callers, proving generic ui/controls infrastructure rather than feature-local ownership.
- Core source range ends exactly at 0x004988cd followed by three 0xcc bytes; TextEditControlPane begins 0x004988d0.
- Scalar target is exact 0x0049b4f0-0x0049b557 with 11-byte prepad and 9-byte postpad; HitTestPart has 11-byte pads on both sides.

## Source Placement

Keep the class in NexusTK/ui/controls/ScrollableControlPane.cpp through [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md). ScrollablePane/ScrollBar supplies the owned child dependency and selected-child helpers but does not own this adapter. Pane, ControlPane, EventHandler, and GrafPort are inherited/dependency contracts.

## Negative Evidence And Historical Corrections

- No support remains for embedded scroll-control wording, provisional ScrollPane type, scrollStep/pageSize/range constructor names, or TextButtonEx base teardown.
- Methods at 0x00498700/20/40 are EventHandler delegates, not three scroll metrics.
- UID0002PE is HitTestPart(int,int), not GetControlType().
- Scalar deleting wrapper and adjustors contain no independently handwritten source.
- UID00011G is an exact split index and must not emit an aggregate marker/body.

## Score Rationale

Completion 92 reflects a complete compilable declaration, exact method split/order, object layout, ownership, constructor callers, scroll/event/layer/paint behavior, destruction/compiler separation, vtables, boundaries, and historical corrections. Confidence 94 reflects direct binary and current contract agreement; stripped original private/parameter spelling and zero raw-start refs cap it below final-audit scores.

## Cross-References

- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) source file.
- [UID:00011G][0x004985a0-0x004988cd.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cd.ScrollableControlPaneCore.md) exact non-emitting core index.
- [UID:000126][0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor](by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md) non-emitting scalar wrapper.
- [UID:0004KR][0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks](by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md) non-emitting adjustor pair.
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) ScrollablePane class dependency.
- [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) ScrollablePane helper/layout evidence.
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) control-family read-only data.

## Changes

- 2026-07-13 B005 UID0004BP support synchronization:
  - Preserved `92/94`, metadata, complete class declaration, method inventory, ownership, and all unrelated source evidence.
  - Added the exact inline `GetScrollablePane() const` contract used by UID0004BP/UID0004BO and corrected inherited offset `+0x101` from superseded `m_controlVisible` wording to `m_enabled`.

- 2026-07-13 B001 complete-source callback:
  - Before: 86/89, blank formal C++, comment-only generated route, embedded/provisional child wording, old three-accessor and GetControlType labels, and TextButtonEx teardown caveat.
  - After: 92/94, position 10, complete compilable class declaration with [[CHILDREN]], owned ScrollablePane pointer, all exact method declarations, and real child links.
  - Evidence: IDB 328356ab constructor/caller/layout, method/vtable/ABI, destructor, padding, sibling-slot, and exact split evidence recorded on UID00011G and children.

- Historical 2026-06-05 through 2026-06-16 score/parent/source-quality passes remain useful provenance for initial method inventory and inherited ControlPane offset corrections, but their unresolved/provisional conclusions are superseded above.
