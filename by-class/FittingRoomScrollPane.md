*** UID:000054 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;
class FittingRoomListPane;

enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};

class FittingRoomScrollPane : public Pane
{
public:
    explicit FittingRoomScrollPane(unsigned char orientation);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool DefaultVirtualFalse(int value);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnDraw();

private:
    friend class FittingRoomListPane;

    FittingRoomScrollPart HitTestPart(int localY, int localX);
    void GetPartRect(FittingRoomScrollPart part, RectBounds *rect);
    void SetHotPart(FittingRoomScrollPart part);
    void BeginPartPress(FittingRoomScrollPart part,
                        int localY,
                        int localX);
    void ProcessActivePart();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_scrollEnabled;
    signed char m_hotPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char FittingRoomScrollPaneSizeMustBe272[
    sizeof(FittingRoomScrollPane) == 0x110 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingRoomScrollPane

## Status

- Confidence: very strong for the local `0x0041d870-0x0041eb8c` scroll-pane interaction/draw core, complete natural `0x110` declaration, Y/X Point tail, narrow list friendship, and source placement through [UID:0000JE][FittingRoom](by-file/FittingRoom.md).
- Historical projection: `class_FittingRoomScrollPane.cpp` remains useful only as prior naming context; it was not used as evidence for the 2026-06-05 score update.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md); a direct generic `ui/core/ScrollBar.cpp` reroute is rejected until future evidence finds a non-FittingRoom constructor or vtable route.
- Autogen status: reconstructable class canonically owned by [UID:0000JE][FittingRoom](by-file/FittingRoom.md) and physically emitted as the first [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md) child at position `10`. Its formal block now provides the complete class declaration, exact `0x110` size guard, narrow friendship, and `[[CHILDREN]]`; exact method bodies remain on their child pages.
- Evidence basis: existing project documentation and IDA MCP checks on 2026-05-23, 2026-05-25, 2026-05-30, the A003 live refresh on 2026-06-05, and B002 source-quality reanalysis on 2026-06-18.
- B004 empty-emitter callback status: [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md) carries its first-draft child body through this class at primary vtable slot `+0x08` (`0x0060dcdc -> 0x0041da60`). The class formal contains only the complete declaration, size guard, and `[[CHILDREN]]`; exact method bodies remain on their by-memory children.

## Role

Scrollbar pane used by fitting-room list controls. It draws EPF-backed scroll parts, tracks hot/pressed parts, handles mouse drag and auto-repeat timers, and notifies the parent list pane when scroll position changes.

## Scroll Interaction Layout / Source Names

The FittingRoomScrollPane interaction methods are class-owned under this page and emitted through [UID:0000JE][FittingRoom](by-file/FittingRoom.md) to `NexusTK/cashshop/FittingRoom.cpp`. They should not be rerouted directly to generic `ScrollBar` / `ui/core` code unless future evidence finds a non-FittingRoom constructor or vtable route. Current evidence keeps the class local: the child scroll pane is allocated inline by [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), the vtable/resource suffix is in [UID:0003AM][0x0060d9c0-0x0060e174.FittingRoomReadOnlyData](by-memory/0x0060d9c0-0x0060e174.FittingRoomReadOnlyData.md), and drag changes synchronize `FittingRoomListPane +0x108` through child pointer `+0x11c`.

The list-pane destructor/delete paths confirm the same ownership: [UID:0002DX][0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor](by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md) and generated cleanup evidence [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md) both call the child through its primary virtual destructor with deleting flag `1`, consistent with an owned `FittingRoomScrollPane *m_scrollPane` at `FittingRoomListPane +0x11c`.

UID0002DC accepts a source support declaration for `FittingRoomScrollPane::FittingRoomScrollPane(unsigned char orientation)` or an enum-equivalent constructor taking `FittingRoomScrollOrientation`. Current MCP session `e18d1e9b` keeps raw `0x0041d6c0` as no-route constructor-shaped evidence: the bytes copy the argument byte to `+0xfc`, call pane base setup `0x00544460`, install `FittingRoomScrollPane` vtables, clear `+0xf8`, clear `+0xfe/+0x100`, set word `+0x102` to `0xff01`, set `+0x104` to `0xff`, and return with `retn 4`. [UID:0002DC][0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor](by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md) performs equivalent setup inline after allocating `0x110` bytes and should be written as construction of a vertical `FittingRoomScrollPane`, not as a hand-authored raw call to `0x0041d6c0`.

The owner list pane's [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md), [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md), [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md), [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md), and [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md) consistently use child `m_scrollPosition` and `m_scrollRange`. These are the sole current source-facing names for `FittingRoomScrollPane +0xfe/+0x100`; historical `m_currentPosition`, `m_maxPosition`, and `m_maxScrollPosition` spellings are superseded aliases, not simultaneous members.

The EventHandler mouse receiver is a secondary-base pointer at object `+0xa0`; source C++ should use an ordinary `FittingRoomScrollPane::OnMouseEvent` method and normal complete-object fields rather than preserving the decompiler's `this - 0xa0` adjustment. The TimerHandler receiver is a tertiary-base pointer at object `+0xa4`; source C++ should use ordinary FittingRoomScrollPane timer/reset helpers.

Recommended source-facing scroll part enum:

```cpp
enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};
```

Recommended field aliases:

| Offset | Type | Source-facing name | Evidence |
| ---: | --- | --- | --- |
| `+0xa4` | TimerHandler view | `m_repeatTimer` / `m_timerHandler` | `OnTimer` and `ResetScrollState` call TimerHandler wrappers through this subobject. |
| `+0xf8` | `int16_t` | `m_scrollSkinIndex` | Indexes `kFittingRoomScrollPartExtentBySkin`; do not model it as a pointer or pixel extent directly. |
| `+0xfb` | bool/byte | `m_thumbDragActive` | Enables drag-anchor thumb rectangle placement; not merely an inside-pane flag. |
| `+0xfc` | `uint8_t` | `m_orientation` | `0` = vertical, nonzero = horizontal. |
| `+0xfe` | `int16_t` | `m_scrollPosition` | Current scroll value mirrored with `FittingRoomListPane +0x108`; this spelling is used consistently by every current emitted child. Historical `m_currentPosition` is superseded. |
| `+0x100` | `int16_t` | `m_scrollRange` | Maximum/range gate for scrolling; historical `m_maxPosition` and `m_maxScrollPosition` are superseded. |
| `+0x102` | bool/byte | `m_scrollEnabled` | Enables/disables hit/drag behavior. |
| `+0x103` | `int8_t` | `m_hotPart` / `m_highlightPart` | Highlighted part; invalidated and cleared separately from active part. |
| `+0x104` | `int8_t` | `m_activePart` | Pressed/tracking part; `0xff` means none and it is not just a previous-part field. |
| `+0x108` | Point | `m_thumbDragOffset` | Cursor offset within the thumb during drag. |
| owner `+0x108` | scroll integer | `FittingRoomListPane::m_scrollPosition` | [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md) writes the owner list scroll position. |
| owner `+0x11c` | `FittingRoomScrollPane *` | `FittingRoomListPane::m_scrollPane` | Constructor stores the child pointer and [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md) invalidates/synchronizes it. |

Recommended helper aliases:

| Address/slot | Source-facing role |
| --- | --- |
| `0x004a9090` | `EventManager::GetCursorPosition` |
| `0x005447c0` | `Pane::GetScreenOffset` / `Pane::GetScreenOrigin`; sentinel `(-1000,-1000)` means no valid screen placement. |
| `0x005449d0` | `Pane::CaptureMouse` |
| `0x005449f0` | `Pane::ReleaseMouseCapture`; do not model as a destructor/reset helper. |
| `0x005975e0` | `TimerHandler::ScheduleTimer`; generic wrapper, not FittingRoom-local. |
| `0x00597600` | `TimerHandler::RemovePendingTimers`; generic wrapper, not FittingRoom-local. |
| `0x004b7c30` | `InitPointPair` / `SetPoint` |
| `0x004b7c50` | `InitRectBounds` / `SetRect` |
| `0x004b7e80` | `PointInRect` |
| virtual `+0x20` | `Pane::InvalidateRect` |
| owner virtual `+0x1c` | Inherited `Pane::GetParentPane()`, followed by a source-level cast to `FittingRoomListPane *` in [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md). Historical `GetOwnerListPane` / `GetOwnerPane` labels are rejected owner-specific aliases for this inherited slot. |

The table at `0x0060dc78` is the fitting-room scroll-part extent table, best source name `kFittingRoomScrollPartExtentBySkin` / `s_scrollPartExtentBySkin`. It contains exactly three dwords `{38, 38, 38}` indexed by `m_scrollSkinIndex`; the following dword at `0x0060dc84` is `0x00640850`, an RTTI complete-object-locator pointer for the adjacent FittingRoomScrollPane vtable block, not a fourth table entry. This rejects color/palette/resource-table interpretations and rejects a generic global scrollbar-size-table owner until references outside this fitting-room scroll-pane cluster are found.

The active-part dispatcher and cursor-position updater remain separate source methods. [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md) fetches cursor/origin state, calls [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md) as `UpdatePositionFromCursor` for direct thumb activity and for a still-active non-thumb part after hit-test equality, then clears stale hot state. UID0002D9 computes `m_scrollPosition`, obtains the parent through inherited `GetParentPane`, and calls `FittingRoomListPane::OnScrollPositionChanged(m_orientation, oldPosition, m_scrollPosition)`. The compiler-inlined owner/list writes, child mirror/invalidation, `UpdateScrollBar`, and owner invalidation are binary evidence for that callback, not handwritten duplicate cross-class source. Do not merge the two methods or move UID0002D9 to `FittingRoomListPane`.

## Draw / Timer / Hit-Test Source-Quality Update

- [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md) is the timer vtable entry for the embedded `TimerHandler` at `+0xa4`, but the source-facing owner is still `FittingRoomScrollPane`. The method checks timer id `0`, gates on `m_activePart` (`+0x104`) not being `kFittingRoomScrollPartNone`, calls `ProcessActivePart()`, and reschedules the repeat timer with `ScheduleTimer(0, 30, 0, 0)`. The `30` value is the repeat interval/delay, not the timer id.
- [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) is a FittingRoom-local themed scrollbar draw virtual. `SLIDEBG.EPF` / `SLIDEBG.PAL` draw track/page regions and `SCRBUTT.EPF` / `BUTTON.PAL` draw the thumb. Track frame mapping is vertical before `{1,0}`, vertical after `{1,2}`, horizontal before `{4,3}`, and horizontal after `{4,5}`; thumb frame `1` is selected when `m_hotPart == kFittingRoomScrollPartThumb`, otherwise frame `0`.
- [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md) is a direct-call class-local helper. It builds candidate part rectangles inline for the five `FittingRoomScrollPart` values and returns `kFittingRoomScrollPartNone` for no hit. Do not model it as a call-through-only wrapper around [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md).
- Generic `ScrollBar` source ownership remains rejected for this class until a non-FittingRoom constructor, vtable, or caller route is found. Shared scrollbar art and shared GrafPort/resource helper use are support/dependency evidence only; they do not override the FittingRoom-local vtable, constructor, field, and caller route.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002D2][0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent](by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md) | `OnMouseEvent` | Vtable-only mouse handler; handles hit testing, thumb drag setup, active part state, timer/capture behavior, and mouse-up cleanup. |
| [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md) | `DefaultVirtualFalse` | First-draft child body now emits through [UID:000054] at the primary `FittingRoomScrollPane` vtable slot `+0x08` (`0x0060dcdc -> 0x0041da60`); descriptive name retained while exact original virtual spelling remains open. |
| [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md) | `OnTimer` | Auto-repeat scroll timer for held scrollbar parts. |
| [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) | `OnDraw` | Draws horizontal/vertical scrollbar background, buttons, track, and thumb with fitting-room resource tables. |
| [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md) | `HitTestPart` | Returns leading button, page before thumb, thumb, page after thumb, trailing button, or `0xff`. |
| [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md) | `GetPartRect` | Calculates button/page/thumb rectangles from orientation, range, current value, and skin size. |
| [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) | raw helper split index | Non-emitting index over exact raw children; generated starts are not IDA functions and still have no direct entry route. |
| [UID:000493][0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw](by-memory/0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw.md) | `SetHotPart` | Raw helper body that updates `m_hotPart`, invalidates old/new part rectangles, and emits through this class at position `50`. |
| [UID:000494][0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw](by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md) | `BeginPartPress` | Raw helper body that forces thumb hot state, initializes `m_thumbDragOffset`, stores `m_activePart`, calls `ProcessActivePart`, and starts the 200 ms repeat timer; emits through this class at position `60`. |
| [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md) | `ProcessActivePart` | Applies active scroll-part behavior or forwards thumb dragging. |
| [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md) | `UpdatePositionFromCursor` | Converts the active part's local Y/X cursor position into scroll state and calls the owning list pane's orientation/old/new callback. |
| [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md) | `ResetScrollState` | Raw helper that stops the repeat timer and clears active/hot scrollbar part state. |
| [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md) | scalar deleting destructor wrapper | Shared generated wrapper used by several scroll-pane-family vtables; base teardown plus optional delete. |
| `0x0045aa00-0x0045ab48` | `BeginScrollDrag` | Drag setup helper. |
| `0x0045ab50-0x0045ac0f` | `UpdateScrollOnMove` | Scroll update during drag. |
| `0x00497aa0-0x0049802f` | parent scroll helpers | Additional scroll handling remains provisional and is not treated as fitting-room-private code on this page. |

## Boundary Cautions

- An older projected constructor start exists at `0x0041d6c0`, but IDA MCP reports `0x0041d6c0` is not a function start. Treat that address as raw layout/code evidence only, not as a confirmed IDA function boundary or a direct target call.
- 2026-07-03 B009 / current MCP session `e18d1e9b` recheck keeps the 2026-05-25 no-route conclusion: `0x0041d6c0` has no modeled function record and no direct constructor route from UID0002DC. Its constructor-shaped body supports a source declaration for a scroll-pane constructor taking orientation byte/enum (`0` vertical, nonzero horizontal), while UID0002DC remains the source-emitting list-pane constructor that allocates `0x110` bytes and performs equivalent child setup inline.
- `OnMouseEvent` decompilation casts through `TextEditPane` and `FittingRoomDialog` helpers. That may be inherited scrollbar infrastructure rather than true fitting-room-only ownership.
- 2026-05-30 IDA MCP function inventory reports modeled scroll-pane method starts at `0x0041d870`, `0x0041da60`, `0x0041da70`, `0x0041dab0`, `0x0041e1d0`, `0x0041e4f0`, `0x0041e8b0`, and `0x0041e970`. IDA still lacks function records at `0x0041e780`, `0x0041e7f0`, and `0x0041eb30`, but byte review confirms raw helper bodies that need function-boundary repair.
- `OnMouseEvent` is reached through a vtable data xref at `0x0060dcd8`, not direct code callers. IDA decompilation uses an adjusted receiver and accesses the logical scroll-pane base at `this - 0xa0`.
- [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md) is generated binary support shared by scroll-pane-family vtables. Document it for vtable completeness, but do not hand-author a distinct source method unless a later class-layout pass proves the original source exposed one.

## Live IDA Evidence

- 2026-06-05 A003 IDA MCP refresh confirms the modeled method starts in the local cluster: `0x0041d870`, `0x0041da60`, `0x0041da70`, `0x0041dab0`, `0x0041e1d0`, `0x0041e4f0`, `0x0041e8b0`, and `0x0041e970`. IDA still reports no function records at raw helper starts `0x0041e780`, `0x0041e7f0`, and `0x0041eb30`.
- The `OnDraw` vtable slot at `0x0060dccc` points to `0x0041dab0`; `OnMouseEvent` remains in the same virtual cluster at `0x0041d870`. The `OnDraw` function has no direct code callers, has `int3` padding before and after, and references fitting-room scrollbar resource data at `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL`; the older partial label inside `BUTTON.PAL` is not a source literal.
- The class remains source-reconstructable because the interaction, timer, drawing, hit-test, geometry, active-part, drag-update, and reset behavior is anchored by exact local pages. It remains below final-source confidence because the constructor boundary is still raw/non-modeled and the scrollbar could share original source with generic UI infrastructure.
- 2026-06-28 B001 raw-helper split implementation supersedes the old aggregate-only raw helper route: [UID:000493][0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw](by-memory/0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw.md) now owns `SetHotPart`, and [UID:000494][0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw](by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md) now owns `BeginPartPress`. [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) remains only as the non-emitting split index and range-level no-route evidence home.
- 2026-06-15 A001 Wave2 method-analysis for the raw helper island reports `0x0041e780` as effective `SetHotPart` with strong method evidence and `0x0041e7f0` as effective `DrawScrollbarPart` / begin-press-style tracking helper with calls to `GetScrollPartRect`, `SetPoint`, `ProcessActivePart`, `ScheduleTimer`, and the security-cookie check. Live IDA on the same pass reconfirms no IDA functions at the raw starts, the modeled successor `sub_41E8B0` at `0x0041e8b0-0x0041e970`, and the in-body call from the raw island to `0x0041e8b0` at `0x0041e882`.
- 2026-06-18 B002 source-quality reanalysis keeps the cluster under `FittingRoomScrollPane` / `FittingRoom.cpp`: no non-FittingRoom constructor or caller route was found, the child is allocated inline by `FittingRoomListPane`, the relevant vtable/resource suffix is in FittingRoom read-only data, and generic-looking scroll/timer/pane helpers are dependency idioms rather than source-owner proof.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The local mouse, timer, draw, hit-test, geometry, hot/active raw-helper, active-part, drag-update, reset, and deleting-destructor evidence is split into exact pages, with the draw path, raw helper island, scroll-part enum, field/helper aliases, three-entry extent table, receiver adjustments, and FittingRoom-local source placement documented. Completion remains below final because the historical raw constructor boundary and exact original class/header names are still not preserved. |
| Confidence `90` | Modeled function starts, vtable data xrefs, sibling cross-calls, fitting-room resource tables, PE read-only-data bytes, raw no-route scans, and B002 source-quality reanalysis consistently identify this scroll-pane class and its field/helper roles. Confidence is not higher because some exact original helper spellings and the raw constructor/function-boundary repairs remain unresolved. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0002D2][0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent](by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md)
- [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md)
- [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md)
- [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md)
- [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md)
- [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md)
- [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md)
- [UID:000493][0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw](by-memory/0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw.md)
- [UID:000494][0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw](by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md)
- [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md)
- [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md)
- [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md)
- [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md)

## 2026-07-23 B001 Complete Declaration, Friendship, And Cursor Contract

- The natural `Pane`-derived tail is exact through object size `0x110`: `m_scrollSkinIndex +0xf8`, `m_scrollStyle +0xfa`, `m_thumbDragActive +0xfb`, `m_orientation +0xfc`, `m_scrollPosition +0xfe`, `m_scrollRange +0x100`, `m_scrollEnabled +0x102`, `m_hotPart +0x103`, `m_activePart +0x104`, and Y/X `Point m_thumbDragOffset +0x108/+0x10c`.
- Constructor-shaped bytes at raw `0x0041d6c0`, inline construction in [UID:0002DC][0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor](by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md), deleting-destructor evidence, child methods, and the `0x110` allocation independently support the declaration and size guard.
- The source method contract is Y-first: `HitTestPart(int localY, int localX)`, `BeginPartPress(..., int localY, int localX)`, and `UpdatePositionFromCursor(int localY, int localX)`. `m_thumbDragOffset.y` is at `+0x108`; X is at `+0x10c`.
- `friend class FittingRoomListPane` is the narrow legal access mechanism for repeated direct list-owned synchronization in UID0002DF, UID0002DH, UID0002DI, UID0002DN, and UID0002DS. Public raw fields and invented setter methods are rejected because the executable repeatedly exposes direct owner-to-child state access.
- Canonical source ownership remains [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Physical emission changes to [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md) at child position `10` solely to produce dependency-safe source order: complete list declaration, complete scroll declaration and children, then later list child definitions.
- Scroll child source order remains exact for this interaction tail: UID000493 `SetHotPart` at `50`, UID000494 `BeginPartPress` at `60`, UID0002D5 `ProcessActivePart` at `70`, UID0002D9 `UpdatePositionFromCursor` at `80`, and UID0002DB `ResetScrollState` at `90`.
- The callback contract is `FittingRoomListPane::OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition)`. UID0002D9 expresses its instruction-equivalent tail as this source callback through inherited `GetParentPane`, while UID0002DH retains the standalone body.
- Scores rise from `88/90` to `90/92` because the blank-class marker, declaration, layout, Y/X signature, dependency order, and legal private-access blockers are resolved. Exact original lexical spellings and historical header/source separation remain confidence caps.
- Historical statements that the class C++ must remain blank are retained only as chronology and are superseded by the accepted complete declaration. The class formal contains no duplicated child bodies.

## Changes

- 2026-07-23 B001 Gate 2 vocabulary-closure callback: kept `90/92` and the existing owner/emitter/position/formal declaration; selected `m_scrollPosition` and `m_scrollRange` as the only current `+0xfe/+0x100` member names across every emitted child; replaced owner-specific slot aliases with inherited `GetParentPane`; replaced the current method-table/source-shape wording with `UpdatePositionFromCursor` plus `OnScrollPositionChanged`; and retained `m_currentPosition`, `m_maxPosition`, `m_maxScrollPosition`, `GetOwnerListPane`, `GetOwnerPane`, and `UpdateThumbDragScroll` only as explicitly superseded history.

- 2026-07-23 B001 accepted UID0002D9 callback: raised `88/90` to `90/92`, retained canonical owner UID0000JE, nested physical emission under UID000053 at position `10`, added the complete Pane-derived `0x110` declaration with `friend class FittingRoomListPane`, fixed Y/X method contracts and interaction source order, and superseded the prior blank-class/empty-marker policy while preserving constructor, vtable, field, method, and source-routing evidence.

- 2026-07-03 B009 UID0002DC support sync: Scores unchanged at `88/90`. Added the accepted support declaration direction for `FittingRoomScrollPane::FittingRoomScrollPane(unsigned char orientation)` or enum equivalent, with `0` as vertical orientation. Preserved the raw `0x0041d6c0` no-function/no-xref/no-direct-call caveat while documenting the constructor-shaped evidence from MCP session `e18d1e9b`: pane base setup call `0x00544460`, vtable writes, `+0xfc` orientation byte, `+0xf8` clear, `+0xfe/+0x100` current/range clears, `+0x102 = 0xff01`, `+0x104 = 0xff`, and `retn 4`. UID0002DC should emit the source-level child construction, not raw vtable/setup scaffolding.
- 2026-07-03 B010 UID0002DI support sync, superseded in vocabulary by the 2026-07-23 B001 closure above: Scores were unchanged at `88/90`. The pass added UID0002DI owner-list synchronization evidence and used `m_currentPosition` as a then-current alias for child `+0xfe`; current source now uses only `m_scrollPosition` before invalidating the child and calling `UpdateScrollBar()`.
- 2026-06-29 B004 empty-emitter implementation callback: Updated [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md) from a stale open-name/blank-emitter row to a first-draft child method routed through this class at primary vtable slot `+0x08`; kept class-level C++ blank by declaration-container policy.
- 2026-06-28 B001 split implementation: Class metadata unchanged. Replaced the single raw-helper method row for [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) with a non-emitting split-index row plus exact child method rows [UID:000493][0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw](by-memory/0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw.md) and [UID:000494][0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw](by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md). Preserved the raw no-function/no-route caveat while moving formal source bodies to the exact child pages at emitter positions `50` and `60`.
- 2026-06-21 B011 Rule 26 support incorporation: Scores unchanged. Added the destructor/delete-path ownership note tying [UID:0002DX][0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor](by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md) and [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md) to a primary virtual destructor call with deleting flag `1` for the owned `FittingRoomScrollPane *m_scrollPane` at `FittingRoomListPane +0x11c`.
- 2026-06-18 B003 remaining list-pane lifecycle incorporation: added owner-list synchronization cross-note from [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md) and [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md), confirming child current/range offsets `+0xfe/+0x100` and keeping synchronization source ownership on [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md).
- 2026-06-18 B002 draw/timer/hit-test incorporation: preserved class score `88/90` while adding source-quality details for [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md), [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md), and [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md). The class now records the TimerHandler-adjusted `OnTimer` receiver, timer id/interval distinction, `SLIDEBG`/`SCRBUTT` resource roles, vertical/horizontal frame mapping, thumb-highlight frame selection, inline hit-test rectangle source shape, and generic `ScrollBar` reroute rejection. The three child pages carry first-draft C++.
- 2026-06-18 B002 source-quality incorporation: raised `85/89` to `88/90`. Added scroll-part enum, field/helper aliases, EventHandler/TimerHandler receiver-adjustment policy, `kFittingRoomScrollPartExtentBySkin[3]` interpretation, active-part/drag-update split, FittingRoom-local source-placement evidence, and rejected generic `ScrollBar`/file-owner alternatives. Class-level C++ stays blank while source-bearing child pages carry first-draft C++.
- 2026-06-15 A001 Goal 2 support refresh: raised `82/88` to `85/89` to clear the direct-parent support gate for [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md). Wave2 method-analysis now documents `0x0041e780` as a strong hot-part setter candidate and `0x0041e7f0` as a begin-press/thumb tracking helper candidate, while live IDA keeps the raw-start/no-function caveat and confirms the modeled successor/callee at `0x0041e8b0`.
- 2026-06-05: Raised the class page to 82/88 after A003 live IDA MCP refreshed the scroll-pane cluster, `OnDraw` vtable slot, resource refs, raw-helper gaps, and exact padding around `0x0041dab0-0x0041e1c6`. Kept C++ blank because final field names, constructor boundary, and generic-scrollbar source placement remain open.
- 2026-06-02: Raised the class page to 72/84, marked it reconstructable, and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Added score rationale and kept C++ blank because the class layout and possible generic scrollbar source split are not final.
- 2026-05-30: Existing `OnMouseEvent` row used an address-only range ending at `0x0041da50`. Changed it to an exact by-memory UID link ending at `0x0041da51` and recorded the vtable-only caller model. Evidence: IDA MCP `py_eval`, `decompile`, `callees`, `callers`, and `xrefs_to` for `0x0041d870`.
- 2026-05-30: Existing method rows for timer, draw, geometry, hot-part state, and reset state were address-only and left most of the local core unresolved. Changed them to exact by-memory UID links for all modeled `0x0041d870-0x0041eb24` functions and raw helper pages for `0x0041e780-0x0041e8af` and `0x0041eb30-0x0041eb8c`. Evidence: IDA MCP function inventory, decompilation/xrefs/callees, and byte/disassembly review across the helper gaps.
- 2026-05-30: Added the shared scroll-pane-family scalar deleting destructor wrapper from the mixed `0x00421310-0x004216cb` island for vtable completeness. Evidence: IDA MCP data refs from scroll-pane-family vtables and decompilation of `0x00421480`.
