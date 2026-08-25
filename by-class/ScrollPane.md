*** UID:0000CM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollBar.h"

// ScrollPane class routing is documented here; exact constructor, draw, geometry, input, timer, and raw-state source emits through child pages.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_SCROLLBAR_H
#define NEXUSTK_UI_CORE_SCROLLBAR_H

#include "Pane.h"
#include "RectBounds.h"

struct PaneMouseEvent;

typedef signed char ScrollPanePart;

static const ScrollPanePart kScrollPanePartNone = -1;
static const ScrollPanePart kScrollPanePartFirstButton = 0;
static const ScrollPanePart kScrollPanePartPageBeforeThumb = 1;
static const ScrollPanePart kScrollPanePartThumb = 2;
static const ScrollPanePart kScrollPanePartPageAfterThumb = 3;
static const ScrollPanePart kScrollPanePartSecondButton = 4;

class ScrollPane : public Pane
{
public:
    explicit ScrollPane(bool horizontal);
    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollStyle(unsigned char scrollStyle)
    {
        if (m_scrollStyle == scrollStyle)
            return;

        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_visibleBounds);
    }
    bool IsScrollThumbVisible();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool CanScroll(int value);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnDraw();

private:
    ScrollPanePart HitTestPart(int localY, int localX);
    void GetScrollPartRect(ScrollPanePart part, RectBounds *outRect);
    void SetHighlightedPart(ScrollPanePart part);
    void BeginPartPress(ScrollPanePart part, int localY, int localX);
    void ProcessActivePart();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    ScrollPanePart m_highlightPart;
    ScrollPanePart m_activePart;
    Point m_thumbDragOffset;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollPane

## C134 Header Assembly Closure

This declaration opens the shared `NEXUSTK_UI_CORE_SCROLLBAR_H` guard and emits the complete ScrollPane type before the ScrollablePane continuation. Exact ScrollPane bodies remain CPP children; the class H channel therefore has no empty child token. Removing that token prevents an invalid `[[No Children Attached]]` line between the two class declarations while preserving the established single-header assembly order.

## Status

- Confidence: strong.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address ranges: `0x0055c200-0x0055e65c`, split across input, draw, geometry, and late input/update helper pages.
- Current recovered file: `source-3/simroot_v2/class_ScrollPane.cpp`

## Class Purpose

`ScrollPane` is the visible scrollbar pane. It stores scrollbar orientation, range, current position, signed one-byte active/highlight part state, thumb visibility, drag anchor state, and style index. It draws both classic `SCRL001` scrollbar assets and newer EPF skin assets, hit-tests five source-level parts, and applies repeated button/page/thumb interactions through its owning scroll container.

## Observed State

Important recovered state:

```text
orientation  0 = vertical, 1 = horizontal
scrollRange  nonzero range enables the thumb
pressedPart  0 = start button, 2 = thumb, 4 = end button
part ids     0 = first button, 1 = track before thumb, 2 = thumb,
             3 = track after thumb, 4 = second button
```

The constructor initializes the scrollbar as a `Pane`, sets three vtable pointers, clears range, sets default flags, and stores an initial `(0, 0)` scroll position.

Current field-role aliases used by child targets: `+0xf8` is inferred `m_scrollSkinIndex`, the signed word index into shared scrollbar skin/style extent tables; `+0xfa` is the separate `m_scrollStyle` byte-style/fallback selector; `+0xfb` is `m_thumbDragActive`; `+0xfc` stores orientation; `+0xfe` stores current position; `+0x100` stores range; `+0x102` is the enabled byte; `+0x103` is signed one-byte `m_highlightPart`; `+0x104` is signed one-byte `m_activePart`; and the point at `+0x108` stores `m_thumbDragOffset`. The `m_scrollSkinIndex` spelling supersedes older target-local `m_trackStateWord` wording. The accepted `ScrollPanePart` source contract is a signed-byte typedef with typed constants `-1..4`, preserving the observed byte loads/stores and sentinel while avoiding a four-byte enum/member ABI contradiction.

## IDA Analysis State

- Supervisor catalog entry `0359` records the UID0003A5 F1-F7/T1-T2 actions as applied and independently verified. The protected pre-mutation IDB backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B005-UID0003A5-20260729-124819.i64`, SHA256 `E9600F6C16B46FE1F5A7FEE463EF7890E415905CE465F8F6C55954FF5AA91611`, 143190173 bytes. The UID0003A5 mutation was first saved as SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, 143190452 bytes, at `2026-07-29T12:53:48.4762005-04:00`. Later unrelated saves `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, and `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69` are historical. Bounded B005 read-only checks against current session `1da2b2ae` and current authoritative SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143190676 bytes, saved `2026-07-29T14:22:15.9735862-04:00`, found no ScrollPane drift.
- `ScrollPanePart` is present in IDA as a signed one-byte typedef, not an enum or UDT; `ScrollPanePartValue` is absent. This matches the formal H contract, byte-sized fields, `-1` sentinel, and function argument/return ABI without introducing a four-byte enum.
- `ScrollPane` is an exact `0x110`-byte, 13-member analysis UDT: `Pane_base +0x000/0xf8 Pane`; `m_scrollSkinIndex +0xf8/2 unsigned __int16`; `m_scrollStyle +0xfa/1 unsigned __int8`; `m_thumbDragActive +0xfb/1 bool`; `m_orientation +0xfc/1 unsigned __int8`; `_analysisPadFD +0xfd/1 unsigned __int8`; `m_scrollPosition +0xfe/2 __int16`; `m_scrollRange +0x100/2 __int16`; `m_enabled +0x102/1 bool`; `m_highlightPart +0x103/1 ScrollPanePart`; `m_activePart +0x104/1 ScrollPanePart`; `_analysisPad105 +0x105/3 unsigned __int8[3]`; and `m_thumbDragOffset +0x108/8 Point`. Dependencies remain `Pane` size `0xf8`, `Point` size 8 with `y` then `x`, and `ScrollablePane` size `0x10c`.
- Current applied function states are:
  - `0x0055d960` `ScrollPane__HitTestPart`, size `0x76`, `ScrollPanePart __thiscall(ScrollPane *this, int localY, int localX)`; repeatable comment: `ScrollPane part hit-test: scans part IDs 0..4, derives each rectangle through GetScrollPartRect, and returns the first containing part or -1; coordinates use the project Y-first ABI.`
  - `0x0055d9e0` `ScrollPane__GetScrollPartRect`, size `0x4b9`, `void __thiscall(ScrollPane *this, ScrollPanePart part, RectBounds *outRect)`; repeatable comment: `ScrollPane part geometry: writes first-button, page-before, thumb, page-after, or second-button bounds for EPF/classic and horizontal/vertical modes.`
  - `0x0055dea0` `ScrollPane__SetHighlightedPart`, size `0x70`, `void __thiscall(ScrollPane *this, ScrollPanePart part)`; repeatable comment: `ScrollPane highlight transition: invalidates the old and new valid part rectangles and stores m_highlightPart.`
  - `0x0055df10` `ScrollPane__BeginPartPress`, size `0xbf`, `void __thiscall(ScrollPane *this, ScrollPanePart part, int localY, int localX)`; repeatable comment: `ScrollPane press initializer: records thumb drag offset when needed, stores m_activePart, processes the part immediately, and starts timer 0 with a 200-tick delay.`
  - `0x0055dfd0` `ScrollPane__ProcessActivePart`, size `0x21d`, `void __thiscall(ScrollPane *this)`; repeatable comment: `ScrollPane active-part dispatcher: localizes the cursor, handles thumb/EPF interaction, repeats classic line/page actions, clamps position, updates the owner, and maintains highlighted state.`
  - `0x0055e210` `ScrollPane__UpdatePositionFromCursor`, size `0x3e6`, `void __thiscall(ScrollPane *this, int localY, int localX)`; repeatable comment: `ScrollPane thumb-position update: converts local cursor and drag offset to a clamped scroll position using part rectangles, then applies a changed position through the owning ScrollablePane.`
  - `0x0055e600` `ScrollPane__ResetScrollState`, size `0x5c`, `void __thiscall(ScrollPane *this)`; repeatable comment: `ScrollPane interaction reset: removes pending timers, clears m_activePart, invalidates the old highlighted part, and clears m_highlightPart.`
- All seven address-regular, address-repeatable, and function-regular comment channels remain blank. Prototype-driven argument normalization retains F1's physical `row`/`column` stack slots while the source ABI is `localY`/`localX`; F2's physical output slot may render `bounds` while the prototype is `outRect`; one-byte `ScrollPanePart` arguments are preserved in F2-F4. Nonargument locals are unchanged.
- Direct xref counts remain `4/15/1/2/2/2/2` for the seven methods. Their executable body hashes, internal F5 NOP/switch-table/padding, all alignment fences, outside successor fence, and adjacent functions remain byte-identical to the accepted UID0003A5 report; no function boundary, vtable route, caller, or source child changed during the unrelated later saves.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/state | `0x0055c200`, raw setters at `0x0055c2b0`/`0x0055c2e0`, `0x0055c3e0` | Initializes pane/vtables, emits `SetSkinIndex` for `m_scrollSkinIndex` at `+0xf8`, defines inline `SetScrollStyle` for `m_scrollStyle` at `+0xfa`, and tests whether the scroll thumb should be visible. UID00042X retains the unreferenced out-of-line compiler copy of that inline API. |
| Input/timer | `0x0055c400-0x0055c643` | First-draft EventHandler-adjusted `OnMouseEvent`, default `CanScroll`, and repeat timer callback into the owner scroll handler. |
| Drawing | [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md) | Draws classic and EPF scrollbar modes using scrollbar part rectangles; B010 confirmed first-draft C++ readiness and normalized helper roles. |
| Geometry | [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) | Computes EPF/classic button, page-before, thumb, page-after, and second-button rectangles for vertical/horizontal bars; B009 confirmed first-draft C++ readiness. |
| Input/geometry tail helpers | [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) split index, with [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md), [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md), [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md), [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md), [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md), [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md), and [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) | Seven direct `ScrollPane` methods for five-part Y-first hit testing/geometry, hover/press state, timer repeat, thumb dragging, owner position application, and reset/invalidation. |

## 2026-06-26 Input-Core Split

B004 split the mixed [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) corridor into exact child pages. `ScrollPane` directly owns [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md) constructor, [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) raw `SetSkinIndex` / `m_scrollSkinIndex` setter, [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) separate raw `+0xfa` byte-style setter, [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md) visibility predicate, [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md) EventHandler-adjusted mouse handler, [UID:000434][0x0055c600-0x0055c605.ScrollPaneCanScroll](by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md) default false `CanScroll`, and [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) TimerHandler-adjusted repeat callback. [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) now remains only a non-emitting split index; [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md)/[UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md)/[UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md)/[UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) are `ScrollWidget` children in the same old corridor.

The constructor [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md), skin-index setter [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md), EventHandler-adjusted mouse body [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md), visibility predicate [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md), false virtual [UID:000434][0x0055c600-0x0055c605.ScrollPaneCanScroll](by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md), and timer callback [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) carry formal source. UID00042W's old `NC-02` and `m_trackStateWord` wording are historical split-pass caution; `+0xf8` is `m_scrollSkinIndex`. The old `NC-03-current` unresolved-callable interpretation for UID00042X is also historical: the exact `+0xfa` compare/write/invalidate lowering is the retained out-of-line compiler copy of inline `SetScrollStyle` above. UID000433 uses `ScrollPane::OnMouseEvent(const PaneMouseEvent& event)` with inferred source-facing event/helper names from EventHandler/Event docs, exact helper decompiles, field offsets, and sibling scrollbar precedent.

Adjusted receiver notes: [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md) is reached from the EventHandler subobject at `ScrollPane+0xa0` and recovers the owning pane with `this-160`; [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) is reached from the TimerHandler subobject at `ScrollPane+0xa4` and recovers the owning pane with `this-164`.

## 2026-07-29 Input/Geometry Helper Split

[UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) is now a reviewed non-emitting split index rather than an aggregate method emitter. Its six formerly unsplit source methods are exact child pages [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md), [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md), [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md), [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md), [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md), and [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md); existing [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) is their geometry peer. All seven route directly through this class and [UID:0000NF][ScrollBar](by-file/ScrollBar.md) `ScrollBar`, use one signed-byte `ScrollPanePart` contract, and preserve Y-before-X local-coordinate order. The compiler-only fences at `0x0055d9d6-0x0055d9e0`, `0x0055de99-0x0055dea0`, `0x0055dfcf-0x0055dfd0`, `0x0055e1ed-0x0055e210`, `0x0055e5f6-0x0055e600`, and `0x0055e65c-0x0055e660` remain non-source bytes documented by [UID:0000VN][-ignored](by-memory/-ignored.md).

## Evidence Notes

- `ScrollablePane::ScrollablePane` constructs `ScrollPane(1)` and `ScrollPane(0)` for horizontal and vertical scrollbars.
- `ScrollPane::OnDraw` loads `SCRL001.EPD`/`SCRL001.PAD` in classic mode and `SLIDEBG.EPF`, `SCRBUTT.EPF`, `SLIDEBG.PAL`, and `BUTTON.PAL` in EPF mode.
- IDA MCP reports `ScrollPane::GetScrollPartRect` has 15 direct call references, mostly from `ScrollPane::OnDraw` and `TextEditPane` scrollbar handlers.
- Generated `OnScrollTimer` subtracts `164` bytes from `this` and calls `TextEditPane::UpdateScrollbarCursor`, which suggests this pane is often embedded as a subobject inside richer scroll owners.
- 2026-06-11 A001 live IDA MCP reconfirmed the exact base vtable child [UID:0003CK][0x00623d58-0x00623de0.ScrollPaneVtableData](by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md): `0x00623d58 -> ??_R4ScrollPane@@6B@`, `0x00623d5c -> ??_7ScrollPane@@6B@`, constructor store `0x0055c251`, and `0x00623de0` as the `ScrollablePane` successor locator.
- 2026-06-12 A005 live IDA MCP reconfirmed [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) as seven modeled generic `ScrollPane` helper functions and corrected [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) to half-open end `0x0055de99` from IDA size `0x4b9` / 1209 bytes (Verified with int_convert.py).
- 2026-06-26 B004 live MCP split pass confirmed [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md) stores the primary/EventHandler/TimerHandler vtables, [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md)/[UID:000434][0x0055c600-0x0055c605.ScrollPaneCanScroll](by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md)/[UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) are reached from vtable slots `0x00623dac`, `0x00623db0`, and `0x00623ddc`, and the raw setters [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md)/[UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) are source-shaped compare/write/invalidate bodies with no current xrefs or pointer-byte route.
- 2026-06-26 B010 implementation confirmed [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md) is now source-shaped enough for first-draft formal C++. The current MCP-backed evidence keeps the route as vtable-only slot `0x00623da0 -> ScrollPane::OnDraw`, with no direct code callers, exact successor padding at `0x0055d957-0x0055d960`, EPF/classic scrollbar resources, shared constants [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md), and helper roles normalized to shared `GrafPort`/`Surface`/`ResourceLayoutTable` naming instead of generated feature-class owners.
- Historical 2026-06-29 evidence from MCP session `b6b3c97e` established UID00042X as a raw no-function setter with zero direct xrefs/pointer hits, exact compare/write of `+0xfa`, inherited-bounds invalidation through slot `+0x20`, and byte-verified padding. The 2026-08-16 closure identifies that retained body as an unreferenced compiler copy of the inline `ScrollPane::SetScrollStyle` API; its old unresolved no-body rationale is superseded without discarding the raw evidence.
- 2026-06-29 B004 current MCP session `b6b3c97e` reconfirmed [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) as a raw no-function setter with zero direct xrefs, zero VA/RVA pointer hits, exact compare/write of `+0xf8`, inherited bounds invalidation through slot `+0x20`, and byte-verified pre/post padding. `ScrollPane::OnDraw` and `ScrollPane::GetScrollPartRect` read `+0xf8` as the signed table index for shared constants `0x00624144` / `0x0062415c`, so `m_scrollSkinIndex` supersedes the old `m_trackStateWord` label and UID00042W now emits first-draft `ScrollPane::SetSkinIndex(unsigned short skinIndex)`.
- 2026-06-29 B009 implementation callback confirms [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) is now first-draft C++ ready under the existing [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) child route. Restored MCP session `B006_0002F1_20260629` reconfirmed the exact `0x4b9` / 1209-byte range, half-open endpoint, successor, padding, 15 direct xrefs, and table bytes. The method uses `m_scrollSkinIndex` for both EPF vertical `kScrollPanePartExtentBySkin` and classic vertical `kClassicScrollPanePartExtentBySkin`; `m_thumbDragActive` and `m_thumbDragOffset.y` affect only the EPF vertical drag override, where local cursor position is clamped inside the vertical track.
- 2026-07-01 B007 implementation callback confirms [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md) is first-draft C++ ready. MCP evidence records the 511-byte EventHandler-adjusted body, vtable slot `0x00623dac`, receiver adjustment `this - 0xa0`, event type/x/y fields at `+4/+8/+0xc`, EPF/classic branch split through `g_useEpfAssets`, capture/release, `HitTestPart`, `BeginPartPress`, `ResetScrollState`, `m_thumbDragActive`, and `m_bounds` invalidation. The helper-name support comes from [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md).
- 2026-07-29 B005 exact-helper implementation split [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) into six new child pages and rerouted [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) directly to this class. Read-only MCP evidence in the accepted report proves exact method ranges, caller sets, field offsets, Y-first call order, signed-byte part behavior, internal switch-table ownership, and compiler/alignment fences. The formal H block now declares the bounded accepted source surface without asserting a recovered original `sizeof(ScrollPane)` construct.
- 2026-07-29 B005 post-Gate2B currentness check used live session `1da2b2ae` against authoritative saved IDB SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`. All F1-F7 names, prototypes, repeatable comments, xrefs, `ScrollPanePart`, and the exact 13-member `ScrollPane` UDT survived unchanged after unrelated supervisor saves.

## Shared Current And Classic Part-Extent Contract

- [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) defines current/EPF `kScrollPanePartExtentBySkin[3] = {38,38,38}` and classic `kClassicScrollPanePartExtentBySkin[3] = {13,10,10}` as 12-byte `const int[3]` arrays indexed by `m_scrollSkinIndex`. The source shell includes `ScrollBar.h` before child definitions so its shared declaration governs the non-static current table definition.
- `ScrollPane::OnDraw` reads the current table at `0x0055c76c`, `0x0055cb28`, `0x0055d1b4`, and `0x0055d46e`; it reads the classic table at `0x0055c86f`, `0x0055cc47`, `0x0055d074`, `0x0055d2d1`, `0x0055d57d`, and `0x0055d8a9`. These reads size fixed buttons, thumb, and page-before/page-after regions in both orientations.
- `ScrollPane::GetScrollPartRect` reads the current table at `0x0055db61` and the classic table at `0x0055dd92`; `ScrollPane::UpdatePositionFromCursor` reads the classic table at `0x0055e2d9`, `0x0055e385`, `0x0055e4aa`, and `0x0055e556`. Thus the values are general part/thumb extents, not merely horizontal heights.
- The current table is shared across generic and specialized translation units; the classic table is used only inside the generic ScrollBar source and remains file-local. There is one binary object per table, so duplicate class-specific definitions and private redeclarations are rejected.
- Historical height-only, resolution-table, and class-local aliases remain useful search history but are superseded by current/classic mode plus part-extent semantics. This source dependency and evidence synchronization do not change class score `87/88` or owner/emitter UID0000NF.

## Current Caveats

- Historical generated source uses unrelated feature-class names for generic drawing helpers such as clip-rect, frame blit, and text color. Treat those names as search aliases only; current `ScrollPane::OnDraw` documentation uses shared `GrafPort`/`Surface`/`ResourceLayoutTable` helper roles while exact original public spellings remain inferred.
- Completion/confidence now clear the strict vtable-child and input/geometry-cluster parent gates. All seven input/geometry methods, `OnMouseEvent`, and the smaller constructor/visibility/timer/skin-index children have first-draft source. The class remains at `87/88` because this bounded split does not finalize every inherited pane interface, the no-route `+0xfa` raw setter remains intentionally excluded from invented callable APIs, and exact original lexical spellings remain inferred.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md)
- [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md)
- [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md)
- [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md)
- [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md)
- [UID:000434][0x0055c600-0x0055c605.ScrollPaneCanScroll](by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md)
- [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md)
- [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md)
- [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md)
- [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md)
- [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md)
- [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md)
- [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md)
- [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md)
- [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md)
- [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md)

## Changes

- 2026-08-16 B001 UID0002NC support callback: inserted the exact inline `SetScrollStyle(unsigned char)` definition immediately after `SetSkinIndex`, using existing `m_scrollStyle`, inherited `m_visibleBounds`, and public `InvalidateRect`; added no include, field, padding, slot, or out-of-line declaration. Historicalized UID00042X's unresolved-callable framing and documented its retained compiler-copy relationship. Score unchanged.

- 2026-07-30 B002 accepted UID0003CQ support synchronization:
  - Added `#include "ScrollBar.h"` before emitted child definitions and documented exact current/classic part-extent values, generic draw/part-geometry/cursor xrefs, `m_scrollSkinIndex` use, one-definition linkage, and rejected height-only/class-local aliases.
  - Preserved `87/88`, UID0000NF ownership/emission, all child routes, and the existing class declaration.

- 2026-07-29 B005 UID0003A5 post-Gate2B reconciliation: recorded catalog entry `0359`, exact backup and save chronology, current authoritative `296ED21C...` readback, signed-byte `ScrollPanePart`, complete `ScrollPane` UDT, all seven applied names/prototypes/comments, frame normalization, xref preservation, byte/fence protection, and no-drift survival after unrelated IDB changes.

- 2026-07-29 B005 UID0003A5 implementation callback:
  - Preserved `87/88`, [UID:0000NF][ScrollBar](by-file/ScrollBar.md) ownership/emission, and the class-level CPP child route while adding a source-ready formal H declaration for the accepted bounded `ScrollPane` surface.
  - Replaced the broad late-helper description with six newly registered method children plus directly rerouted [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md), documented exact `+0x103/+0x104/+0x108` state, signed-byte `ScrollPanePart`, Y-first geometry/input order, and all compiler-only fences.
  - No unsupported source-level size assertion was introduced; the separate no-route `+0xfa` raw setter remains outside invented callable APIs.

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented scrollbar responsibility, observed state, method families, constructor users, drawing resources, and current helper-owner caveats.
  - After: changed completion/confidence to `78/82`.
  - Evidence: existing method-family table, evidence notes, generated-source caveats, endpoint correction, and ScrollablePane/ScrollWidget cross-references support strong behavior confidence with moderate remaining helper-owner cleanup.

- 2026-05-28: Corrected `ScrollPane` input/draw memory endpoints.
  - Before: cross-references used `0x0055c200-0x0055c642` and `0x0055c650-0x0055d956`.
  - After: IDA-backed endpoints are `0x0055c200-0x0055c643` and `0x0055c650-0x0055d957`; following bytes are padding.
  - Evidence: 2026-05-28 IDA MCP reports `sub_55C610` as `0x0055c610-0x0055c643` and `sub_55C650` as `0x0055c650-0x0055d957`.
- [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- 2026-06-03: Attached class metadata and expanded input-core state helpers.
  - Before: the page was `78/82`, but reconstructability and parent metadata were blank, and the input-core summary omitted raw setter-shaped bodies at `0x0055c2b0` and `0x0055c2e0`.
  - After: marked reconstructable, attached to [UID:0000NF][ScrollBar](by-file/ScrollBar.md) at position `10`, and updated the input/timer range to the corrected half-open `0x0055c400-0x0055c643`.
  - Evidence: IDA MCP `py_eval` on 2026-06-03 confirms constructor callers from `ScrollablePane`, raw state setters at `0x0055c2b0` and `0x0055c2e0`, `IsScrollThumbVisible` at `0x0055c3e0-0x0055c3fa`, `CanScroll` at `0x0055c600-0x0055c605`, and vtable refs for mouse/timer/default virtual methods.
- 2026-06-11 A001 Batch 224 parent-gate refresh:
  - Before: `78/82`, below the strict gate for exact vtable-data assignment.
  - After: `85/86`, parent remains [UID:0000NF][ScrollBar](by-file/ScrollBar.md), C++ remains blank.
  - Evidence: live IDA reconfirmed the exact [UID:0003CK][0x00623d58-0x00623de0.ScrollPaneVtableData](by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md) locator/vtable/store boundary, and the file parent was refreshed to `89/85`.
- 2026-06-12 A005 Batch245:
  - Raised `85/86` to `86/87` after adding the late input/geometry helper cluster [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) and corrected geometry child [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md).
  - Evidence: live IDA MCP reconfirmed the seven-function cluster, `GetScrollPartRect` size/end, caller/callee anchors, and direct class ownership. Final class-level C++ remained blank because method/helper declarations were not ready.
- 2026-06-26 B004 implementation callback:
  - Before: this page linked only the broad [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) input-core family and retained stale code-gate wording.
  - After: added exact child links and receiver notes for constructor, raw setters, visibility predicate, EventHandler mouse handling, default false virtual, and TimerHandler repeat callback. Score unchanged at `86/87`.
  - Evidence: accepted B004 report and live MCP session `80de0a67` confirmed direct `ScrollPane` ownership for [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md), [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md), [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md), [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md), [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md), [UID:000434][0x0055c600-0x0055c605.ScrollPaneCanScroll](by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md), and [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md).
- 2026-06-26 B010 ScrollPaneOnDraw implementation callback:
  - Before: the drawing family row and caveats still treated first-draft draw C++ as blocked by generic helper-owner pollution.
  - After: score unchanged at `86/87`; this class now records [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md) as current MCP-backed first-draft C++ ready, with helper naming normalized to shared renderer/resource roles.
  - Evidence: accepted B010 report and target update record vtable slot `0x00623da0`, exact `0x0055c650-0x0055d957` range, EPF/classic draw resources, [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) and [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md) dependencies, and remaining uncertainty limited to exact original helper spellings.
- 2026-06-29 B006 UID00042X empty-emitter implementation callback:
  - Before: this class grouped [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) with raw setters whose formal C++ blocks stayed blank.
  - After: score unchanged at `86/87`; [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) is still no-body/no-standalone-method under `NC-03-current`, but it now carries a formal comment-only marker on the target page to clear the generated empty-emitter row. At that point [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) still remained blank under `NC-02`; that historical state is superseded by the later B004 UID00042W callback below.
  - Evidence: accepted B006 report, current MCP session `b6b3c97e`, and B010 draw evidence confirm the raw body, negative route checks, `+0xfa` style-byte role, and the rejected guessed-setter/no-owner/parent-emitter alternatives.
- 2026-06-29 B004 UID00042W empty-emitter implementation callback:
  - Before: this class still described [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) as a raw range/track word setter with blank formal C++ under `NC-02`.
  - After: score unchanged at `86/87`; field-role notes now name `+0xf8` as `m_scrollSkinIndex`, constructor/child docs use that source-facing alias, and UID00042W emits first-draft `ScrollPane::SetSkinIndex(unsigned short skinIndex)` while no-route/no-original-name facts remain score caps.
  - Evidence: accepted B004 report, current MCP session `b6b3c97e`, exact UID00042W raw body and padding bytes, zero xrefs/pointer hits, `ScrollPane::OnDraw` / `GetScrollPartRect` table-index consumers, and rejected `SetRange` / `m_trackStateWord` / UID00042X-merge alternatives.
- 2026-06-29 B009 UID0001GK implementation callback:
  - Before: the geometry row still treated [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) as formula-blocked even after `m_scrollSkinIndex` was resolved.
  - After: score unchanged at `86/87`; this class records UID0001GK as first-draft C++ ready, preserves the existing [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) child route, and documents that `m_thumbDragActive` is used only by the EPF vertical drag-override geometry path.
  - Evidence: accepted B009 report and restored MCP session `B006_0002F1_20260629`, which reconfirmed UID0001GK range, padding, successor, 15 direct callers, and shared constant bytes; the target page now carries the formal geometry body and exact EPF/classic formulas.
- 2026-07-01 B007 UID000433 empty-emitter implementation callback:
  - Before: this class described UID000433 as routed but blank under a target-specific no-code proof.
  - After: raised class score from `86/87` to `87/88`, inserted the formal class-route comment marker with `[[CHILDREN]]`, and records UID000433 as first-draft `ScrollPane::OnMouseEvent` output through the exact child page.
  - Evidence: accepted B007 report, current MCP proof of the 511-byte EventHandler-adjusted body, helper-name support in UID0003A5, and sibling handler naming precedent.
