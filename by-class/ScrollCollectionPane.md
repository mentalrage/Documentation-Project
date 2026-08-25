*** UID:0000CG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollCollectionPane.h"
#include "ScrollBar.h"

#include "CollectionPane.h"
#include "Event.h"
#include "../../render/EPFTileContext.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "Pane.h"

class CollectionPane;
class Event;
struct RectBounds;

enum ScrollCollectionPart
{
    kScrollCollectionPartLeading = 0,
    kScrollCollectionPartPageBeforeThumb = 1,
    kScrollCollectionPartThumb = 2,
    kScrollCollectionPartPageAfterThumb = 3,
    kScrollCollectionPartTrailing = 4,
    kScrollCollectionPartNone = -1
};

class ScrollCollectionPane : public Pane
{
public:
    explicit ScrollCollectionPane(unsigned char orientation);

    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollStyle(unsigned char scrollStyle);
    void SetMaxRange(short maxRange);
    void SetScrollPosition(short position);
    void Enable();
    void Disable();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    friend class CollectionPane;

    ScrollCollectionPart HitTestScrollRegion(int localY, int localX);
    void GetPartRect(ScrollCollectionPart part, RectBounds *bounds);
    void SetHighlightedPart(ScrollCollectionPart part);
    void BeginPartInteraction(ScrollCollectionPart part,
                              int mouseY,
                              int mouseX);
    void UpdateDragScroll();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_scrollEnabled;
    signed char m_highlightPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollCollectionPane

## Status

- Accepted source file: [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), emitted as `NexusTK/ui/core/ScrollCollectionPane.cpp` and `.h`. `CollectionPane.cpp` and generic `ScrollBar.cpp` remain rejected historical alternatives.
- Address range: [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md)
- Type evidence: [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md), [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md), and exact non-emitting compiler data [UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md).
- Current generated route: `NexusTK/ui/core/ScrollCollectionPane.cpp` and `ScrollCollectionPane.h`.
- Confidence: very strong for behavior, allocation/callers, natural `0x110` layout, three vtable facets, all nineteen exact method boundaries, enum/field contracts, source route, and formal class/source topology; strong for inferred source spellings because original symbols are unavailable.

## Class Purpose

`ScrollCollectionPane` is a dedicated `Pane`-derived themed scrollbar used by `CollectionPane`. It owns orientation, skin/style, signed range and position, enabled/highlight/active state, thumb drag offset, EventHandler and TimerHandler facets, five-part geometry, repeated interaction, and EPF-backed track/thumb painting. `CollectionPane` constructs and consumes it but does not own its implementation source.

## Source-Facing Scroll Part Aliases

The accepted B005 `UpdateDragScroll` implementation reconciles the scrollbar state aliases used by the helper cluster:

| Alias | Evidence and use |
| --- | --- |
| `ScrollCollectionPart` | Source-facing type for hit-test, active, highlight, and geometry part values. |
| `kScrollCollectionPartLeading` | Part value `0`; [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses it for the leading/up-left scrollbar end rectangle. |
| `kScrollCollectionPartPageBeforeThumb` | Part value `1`; [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses it for the page/track rectangle before the thumb. |
| `kScrollCollectionPartThumb` | Part value `2`; direct thumb drag path in [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md), thumb setup in [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) / `BeginPartInteraction`, and thumb rectangle branch in [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md). |
| `kScrollCollectionPartPageAfterThumb` | Part value `3`; [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses it for the page/track rectangle after the thumb. |
| `kScrollCollectionPartTrailing` | Part value `4`; [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses it for the trailing/down-right scrollbar end rectangle. |
| `kScrollCollectionPartNone` | Part value `0xff`; used when no active/highlight part is present or hit-testing finds no matching rectangle. |
| `m_scrollSkinIndex` | Low word at `this+0xf8`; B006 [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses it as the vertical fixed-extent index into `kScrollPanePartExtentBySkin`; older `m_scrollStyle` wording is historical/descriptive. |
| `m_scrollStyle` | Byte at `this+0xfa`; [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md) compares/stores it and invalidates on change, resolving the old padding/unidentified-byte interpretation. |
| `m_thumbDragActive` | Byte at `this+0xfb`; B006 [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses it to choose live cursor minus `m_thumbDragOffset` instead of stored `m_scrollPosition` for vertical thumb geometry. |
| `m_scrollEnabled` | Byte at `this+0x102`; gates actionable page-before/page-after hit-test geometry with positive `m_scrollRange`. |
| `kScrollPanePartExtentBySkin` | Imported from `ScrollBar.h`; source-facing name for the shared [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) `0x00624144` `const int[3]` object `{38,38,38}`. [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) is one specialized consumer, not the storage owner. |
| `m_highlightPart` | Byte at `this+0x103`; invalidated/cleared by `UpdateDragScroll` and `ResetScrollState`. |
| `m_activePart` | Byte at `this+0x104`; written by input/raw start-drag setup and consumed by `UpdateDragScroll` / timer update flow. |
| `m_thumbDragOffset` | Point-like field at `this+0x108` using project `Point` order `y,x`; initialized by thumb start-drag setup from incoming cursor coordinates minus `RectBounds.top/left`, then consumed by `UpdatePositionFromCursor` as `+0x108`/`localY` and `+0x10c`/`localX`. |
| `GetPartRect` | Source-facing name for geometry helper `0x00562bf0`; the older `GetScrollRegionRect` wording is historical and should not be used for new formal C++. |
| `HitTestScrollRegion` | Source-facing hit-test helper `0x005628d0`; the helper name keeps `Region`, but the `+0x103/+0x104` fields are accepted as part fields, not conflicting `region` field names. |
| `SetHighlightedPart` | Source-facing name for raw child [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md), emitted at child position `50`; `SetHighlightedRegion` remains only a historical/generated alias. |
| `BeginPartInteraction` | Source-facing name for raw child [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md), emitted at child position `60`; the old active-region/start-drag wording is historical search context. |
| `UpdatePositionFromCursor` | Cursor-to-position helper `0x00563070`, called by `UpdateDragScroll` with project `Point` order `localY, localX`; now emits first-draft C++ at child position `80`. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollCollectionPane` | `0x00561db0-0x00561e51` | [UID:0004X3][0x00561db0-0x00561e51.ScrollCollectionPaneConstructor](by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md) constructs Pane(1), installs three facets, and initializes the natural `0x110` object. |
| `SetSkinIndex` | `0x00561e60-0x00561e87` | [UID:0004X4][0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw](by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md) raw 16-bit skin setter; no static route. |
| `SetScrollStyle` | `0x00561e90-0x00561eb4` | [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md) raw style-byte setter resolving `+0xfa`; no static route. |
| `SetMaxRange` | `0x00561ec0-0x00561f1b` | [UID:0004X7][0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange](by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md) signed clamp to `0..30000`, position clamp, store, and invalidate. |
| `SetScrollPosition` | `0x00561f20-0x00561f47` | [UID:0004X8][0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition](by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md) signed-short position store and invalidate. |
| `Enable` | `0x00561f50-0x00561f6a` | [UID:0004X9][0x00561f50-0x00561f6a.ScrollCollectionPaneEnable](by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md) false-to-true state transition with conditional invalidation. |
| `Disable` | `0x00561f70-0x00561f8a` | [UID:0004XA][0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw](by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md) raw inverse state transition; no static route. |
| `CanScroll` | `0x00561f90-0x00561faa` | [UID:0004XB][0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw](by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md) raw enabled-and-positive-signed-range predicate; no static route. |
| `HandlePointerOrMouseEvent` | `0x00561fb0-0x00562191` | [UID:0004XL][0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent](by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md) EventHandler pointer/button capture, drag, timer, and invalidation state machine. |
| `HandleKeyOrTextEvent` | `0x005621a0-0x005621a5` | [UID:0004XM][0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent](by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md) EventHandler secondary slot returning false; not `CanScroll`. |
| `OnTimer` | `0x005621b0-0x005621e3` | [UID:0004XN][0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer](by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md) TimerHandler active-part update and 30 ms repeat. |
| `OnPaint` | `0x005621f0-0x005628d0` | [UID:0004XO][0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint](by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md) clip-aware SLIDEBG track and SCRBUTT thumb rendering. |
| `HitTestScrollRegion` | `0x005628d0-0x00562bed` | [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) now emits first-draft `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` C++ at child position `40`; it builds the five candidate rectangles inline, uses `PointInRect(localY, localX, &rect)`, and returns a `ScrollCollectionPart` value `0..4` or `kScrollCollectionPartNone` / `0xff`. |
| `GetPartRect` | `0x00562bf0-0x00562e77` | [UID:0004XP][0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect](by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md) computes five-part vertical/horizontal, disabled, and live-drag geometry; `GetScrollRegionRect` is historical wording only. |
| `SetHighlightedPart` / `BeginPartInteraction` | `0x00562e80-0x00562fb0` | [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md) is a non-emitting split index over exact raw helpers [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) / `ScrollCollectionPane::SetHighlightedPart` at child position `50` and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) / `ScrollCollectionPane::BeginPartInteraction` at child position `60`; IDA does not currently model either start as a function object or expose a direct static entrypoint route. The accepted field aliases are `m_highlightPart`, `m_activePart`, and `m_thumbDragOffset`. |
| `UpdateDragScroll` | `0x00562fb0-0x00563070` | [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md); now emits first-draft `void ScrollCollectionPane::UpdateDragScroll()` C++ at child position `70`, checks cursor/active part, directly updates thumb drags, hit-tests non-thumb parts, and clears stale highlight when needed. |
| `UpdatePositionFromCursor` | `0x00563070-0x005631fd` | [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md); maps cursor coordinates to a scrollbar position, preserves two cursor/origin sentinel checks, calls `CollectionPane::OnScrollPositionChanged`, and now emits first-draft C++ at child position `80`. |
| `ResetScrollState` | `0x00563200-0x0056325c` | [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md); IDA does not currently model this start as a function object. Cancels pending timers through the `+0xa4` timer/update view, clears `m_activePart`, conditionally invalidates the stale `m_highlightPart` rectangle, and now emits first-draft `ScrollCollectionPane::ResetScrollState()` C++. |

## Complete ABI And Vtable Regeneration Contract

[UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md) is an exhaustively audited `0x88`-byte compiler-data child, not a second source emitter. Its three complete-object-locator/table views are:

| View | COL pointer / table | Complete-object offset | Callable slots | Sole constructor store |
| --- | --- | ---: | ---: | --- |
| primary | `0x00623fa0 -> 0x0064fa94`; table `0x00623fa4` | `+0` | 18 | `0x00561e01` |
| `EventHandler` | `0x00623fec -> 0x0064faf0`; table `0x00623ff0` | `+0xa0` | 11 | `0x00561e07` |
| `TimerHandler` | `0x0062401c -> 0x0064fb04`; table `0x00624020` | `+0xa4` | 2 | `0x00561e11` |

The primary table carries the inherited LObject/GrafPort/Pane contract through slot `+0x40` and class override `OnPaint()` at `+0x44`. The EventHandler table carries its shared deleting adjustor, `HandlePointerOrMouseEvent` at `+0x04`, `HandleKeyOrTextEvent` at `+0x08`, and nine inherited event bridges/accessors through `+0x28`. The TimerHandler table carries its shared deleting adjustor and `OnTimer` at `+0x04`. The source-owned entries are exactly:

| Table cell | Source declaration | Exact body |
| --- | --- | --- |
| `0x00623fe8` | `virtual void OnPaint()` | [UID:0004XO][0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint](by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md) |
| `0x00623ff4` | `virtual bool HandlePointerOrMouseEvent(Event *event)` | [UID:0004XL][0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent](by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md) |
| `0x00623ff8` | `virtual bool HandleKeyOrTextEvent(Event *event)` | [UID:0004XM][0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent](by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md), exact false-return and not `CanScroll()` |
| `0x00624024` | `virtual bool OnTimer(int timerId, int arg0, int arg1)` | [UID:0004XN][0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer](by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md) |

The deleting entries route through shared wrapper [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md) and `this-0xa0` / `this-0xa4` compiler adjustors at `0x004213f8` / `0x00421403`. Live xrefs show reuse across eight primary and eight secondary/tertiary vtable families. The wrapper performs only `Pane` teardown plus optional scalar deletion, with no ScrollCollectionPane-specific cleanup. The most plausible human source therefore keeps the current class declaration and relies on an implicit derived destructor; an explicit empty destructor declaration/body would add unsupported source shape.

Physical COL/vtable data pages [UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md) and [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md) are `RECONSTRUCTABLE:FALSE`, blank-emitter support after the B002 audit. This class declaration and exact method children are the only source route. Rejected alternatives are retained explicitly: do not emit decorated labels or pointer arrays, do not add a covered-by marker, do not assign physical data to the broad read-only aggregate, and do not give shared compiler thunks class-specific names.

## Boundary Notes

- IDA MCP confirms modeled function objects for twelve bodies. Raw starts `0x00561e60`, `0x00561e90`, `0x00561f70`, `0x00561f90`, `0x00562e80`, `0x00562ef0`, and `0x00563200` remain unmodeled and have no recovered xref/pointer route, but each is an exact aligned class-method body with formal source.
- IDA confirms the hit-test helper at `0x005628d0`; current generated output emits it exactly once as scoped method `HitTestScrollRegion` at position `40`, followed by exact geometry child `GetPartRect` at position `45`.
- Raw IDA disassembly shows complete executable bodies at all seven unmodeled starts. Exact child pages and formal source preserve those bodies while supervisor-owned function creation/rename/type/comment actions remain pending at Gate 2B.
- Current generated output emits all nineteen constructor/method definitions once in deterministic order. Earlier helper omissions are preserved only in the historical change entries below and are not current source blockers.
- Constructor stores vtables `0x00623fa4`, `0x00623ff0`, and `0x00624020`; local state offsets are recorded in [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md).
- 2026-06-11 live IDA MCP recheck confirms `CollectionPane::CollectionPane` (`0x0056e940`) allocates `272` bytes / `0x110` bytes (Verified with int_convert.py), calls the `ScrollCollectionPane` constructor at `0x0056e9b6` with orientation `0`, stores the returned child pointer at `CollectionPane + 0x108` / `this[66]`, then calls `EnableScrollbar` at `0x0056e9cb`.
- 2026-06-11 live IDA MCP recheck confirms `CollectionPane` refresh/scroll callbacks call `SetMaxRange` at `0x0056ed36`, `SetScrollPosition` at `0x0056eda2`, `0x0056f72a`, and `0x0056faac`, and route wheel/drag updates back through the stored child pointer rather than constructing an alternate scrollbar owner.
- 2026-06-11 live IDA MCP caller/callee refresh confirms the internal helper graph is self-contained: `0x00561fb0` calls hit-test/geometry/update helpers; `0x005621f0` calls the geometry helper for paint; `0x00562fb0` calls hit-test, geometry, and cursor-to-position; `0x00563070` calls the `CollectionPane` callback `0x0056fa90`.
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) is the accepted dedicated file owner at `91/92`, projected to `NexusTK/ui/core/`; `ScrollBar.cpp` remains historical/rejected rather than an active source-placement blocker.
- The executable aggregate [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) is attached to this class parent and records the function map, vtable stores, caller/callee evidence, raw helper gaps, and corrected exclusive-end boundary; exact helper children still carry their own reconstruction and final C++ gates.
- 2026-06-16 A002 live IDA MCP recheck on session `b001_mappane_0001AW_20260616` reconfirmed constructor `0x00561db0` (`0xa1` bytes), range/current/enable helpers, input handler `0x00561fb0`, paint `0x005621f0`, hit-test `0x005628d0`, geometry `0x00562bf0`, update helpers `0x00562fb0` and `0x00563070`, raw non-function starts `0x00562e80`, `0x00562ef0`, and `0x00563200`, and successor constructor `0x00563260`. Xrefs still show the only constructor caller at `0x0056e9b6`, setter callers at `0x0056ed36`, `0x0056eda2`, `0x0056f72a`, and `0x0056faac`, raw helper starts with zero xrefs, and vtable base stores to `0x00623fa4`, `0x00623ff0`, and `0x00624020` at `0x00561e01`, `0x00561e07`, and `0x00561e11`. Raw disassembly at the three unmodeled starts remains prologue-shaped; bytes at `0x00563258` are `8b e5 5d c3 cc cc cc cc`, confirming the clear-helper return and padding before the next constructor.
- 2026-06-25 B014 source-quality recheck on IDA MCP session `80de0a67` kept `0x00563200` raw/non-modeled but upgraded its source-facing identity: `lookup_funcs`, `entity_query`, `get_bytes`, `insn_query`, `xrefs_to`/`xref_query`, `decompile`, `disasm`, and `callees` reconfirm no function object, exact `0x00563200-0x0056325c` body, `0x0056325c-0x00563260` padding, 32 ownerless instructions, no external xref to the raw start, and outgoing raw callsites to `TimerHandler::RemovePendingTimers`, `ScrollCollectionPane::GetPartRect`, inherited pane invalidation slot `+0x20`, and the stack-cookie check.
- The same B014 pass ran a local PE route scan over `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (`SHA-256 9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`): no VA/RVA/start/end/interior pointer hit and no direct branch/call route to `0x00563200` were found; the only branch target inside the helper is its own `0x0056322d -> 0x0056324d` skip, while positive controls found the target's outgoing calls at `0x00563236 -> 0x00562bf0` and `0x00563219 -> 0x00597600`.
- `ClearHighlightRaw` remains a historical alias for [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) but is rejected as the final method name because the body resets more than highlight state: it removes pending timers, clears active part `+0x104`, and clears/invalidate old highlight part `+0x103`. `ResetScrollState` matches accepted sibling reset helpers; no IDA function creation or live-caller claim is made from this no-route helper.
- 2026-06-26 B005 source-quality implementation for [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) resolved the stale owner/name/code gate: live MCP evidence confirms exact `0x00562fb0-0x00563070` boundary, one `cc` at `0x00562faf`, immediate next helper `0x00563070`, three incoming xrefs, outgoing calls to cursor/screen-offset/hit-test/geometry/update helpers, active/highlight part fields, thumb direct update, non-thumb hit-test/update rule, stale-highlight invalidation, and project `Point` y/x argument order. The child now emits first-draft `ScrollCollectionPane::UpdateDragScroll()` C++ at position `70`.
- 2026-06-26 B001 source-quality implementation for [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) resolved the stale target blocker left after the B005 alias pass: the child emits first-draft `ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)` C++ at position `80`, uses `GetPartRect(kScrollCollectionPartThumb)`, `g_pEventMan->GetCursorPosition`, `GetScreenOffset`, `m_scrollPosition`, `m_scrollRange`, `m_orientation`, `m_bounds`, and `m_thumbDragOffset`, and documents the project `Point` component mapping as `+0x108`/`localY` and `+0x10c`/`localX`. The 2026-07-26 accepted callback further resolves the inherited `GetParentPane()` callback and dedicated source route; the old blank-C++ and possible-`ScrollBar.cpp` caveats are historical only.
- 2026-06-27 B002 source-quality implementation for [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md) resolves the remaining raw interaction-name blocker for the `0x00562e80-0x00562fb0` split. Live MCP session `80de0a67` reconfirmed no function objects at `0x00562e80` or `0x00562ef0`, no incoming xrefs, no exact pointer hits, and internal-only branch hits, but also confirmed the bounded bodies and accepted alias use. The exact children now emit `ScrollCollectionPane::SetHighlightedPart(ScrollCollectionPart part)` at position `50` and `ScrollCollectionPane::BeginPartInteraction(ScrollCollectionPart part, int mouseY, int mouseX)` at position `60`. The raw no-route caveat remains a confidence cap rather than a C++ blocker.
- 2026-06-27 B006 source-quality implementation for [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) resolves the stale hit-test blank-C++ blocker. Live MCP session `b001_000241_20260627` reconfirmed exact boundary/padding, the two caller sites from input and drag-update code, cursor/origin/rectangle/point-test callees, inline vertical/horizontal five-part geometry, `m_scrollSkinIndex`, `m_thumbDragActive`, `m_scrollEnabled`, `m_thumbDragOffset`, and the fact that `0x00562bf0` / `GetPartRect` is a sibling equivalence helper rather than a direct callee. The child now emits first-draft `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` C++ at position `40`.

## Parent And Score Rationale

| Item | Score | Relevance |
| --- | ---: | --- |
| [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) | `91/92` | Accepted dedicated `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}` owner with complete class/source contents and rejected alternative history. |
| [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) | `93/93` | Complete aggregate with nineteen exact children, padding map, callers, vtables, natural layout, source route, event/timer/geometry/resources, and covered-by emission. |
| [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) | `91/91` | Exact modeled five-part hit-test child at position `40`, now linked to the split-complete class and common geometry child. |
| [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) | `90/91` | Exact raw `SetHighlightedPart` at position `50`; old/new rectangle invalidation and no-route evidence retained. |
| [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) | `90/91` | Exact raw `BeginPartInteraction` at position `60`; Point offset, immediate update, initial timer, and no-route evidence retained. |
| [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) | `91/91` | Exact modeled active-part repeat/drag update at position `70`, linked to complete event/timer/geometry children. |
| [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) | `92/91` | Corrected signed-short cursor conversion and `GetParentPane()` CollectionPane callback at position `80`. |
| [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) | `90/90` | Corrected enum-typed raw reset child at deterministic position `90`; no-function/no-static-route evidence retained. |

The class is `93/93`: allocation/callers, vtable facets, natural layout, exact split, source route, formal H/CPP, and all method bodies are implementation-ready. Original spellings, seven missing static routes, and rebuilt-binary comparison remain final-audit limits, not ownership/split/source/C++ blockers. The class declaration intentionally relies on natural member layout and does not contain the withdrawn `SizeMustBe` typedef.

## Accepted Source And Rejected Alternatives

- Accepted source: dedicated `NexusTK/ui/core/ScrollCollectionPane.h` and `.cpp` through [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md). The class CPP owns its includes and consumes the shared three-entry extent table through `ScrollBar.h`; the class H owns its enum, natural fields, and method prototypes without redeclaring ScrollBar storage; exact children own method definitions.
- The existing complete H declaration grants only `friend class CollectionPane;`. This narrow support reflects direct `CollectionPane::UpdateScrollRange` and `CollectionPane::HandlePointerOrMouseEvent` reads of `m_scrollPosition` and `m_scrollRange`; it adds no accessor, field, storage, vtable entry, size, owner, or source-file change.
- Rejected `CollectionPane.cpp`: the consumer allocates and calls this reusable control but does not own its vtables or closed helper graph.
- Rejected generic `ScrollBar.cpp`: sibling scrollbar classes have independent vtables/ranges and no binary evidence merges implementations. Older possible-merge wording is preserved in history below, not current routing.
- Shared source table `kScrollPanePartExtentBySkin[3] = {38,38,38}` represents the [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) `0x00624144` slice and is defined once by [UID:0000NF][ScrollBar](by-file/ScrollBar.md); this class imports it. Paint resources remain `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL`.

## Shared ScrollBar Constant Dependency

- `ScrollCollectionPane::OnPaint`, `HitTestScrollRegion`, and `GetPartRect` consume the current/EPF part extent through `kScrollPanePartExtentBySkin[m_scrollSkinIndex]`. Their reads at `0x005622f7`, `0x005625f6`, `0x00562a5c`, and `0x00562d4b` all target the one object at `0x00624144`.
- The table is a 12-byte `const int[3]` object with values `{38,38,38}`. Generic `ScrollPane`, spell, group, collection, and inventory scrollbar families all reference the same address, so class-local ownership is disproven by the consumer graph.
- `ScrollCollectionPane.cpp` now includes `ScrollBar.h`; it neither defines the table nor supplies a private `extern`. The shared declaration and sole definition travel through [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) and UID0000NF, preserving one-definition behavior across the current multi-translation-unit reconstruction.
- Historical class-owned-table guidance arose from a generated shell that duplicated the value next to this class. That generated placement was a documentation artifact rather than binary ownership evidence and is retained here only as a rejected prior assumption. No second object, specialized table, or new constants module is introduced.
- This dependency correction does not alter any class method, layout, vtable, source file, owner/emitter route, or `93/93` score.

## Cross-References

- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- [UID:0004X3][0x00561db0-0x00561e51.ScrollCollectionPaneConstructor](by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md)
- [UID:0004X4][0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw](by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md)
- [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md)
- [UID:0004X7][0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange](by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md)
- [UID:0004X8][0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition](by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md)
- [UID:0004X9][0x00561f50-0x00561f6a.ScrollCollectionPaneEnable](by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md)
- [UID:0004XA][0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw](by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md)
- [UID:0004XB][0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw](by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md)
- [UID:0004XL][0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent](by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md)
- [UID:0004XM][0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent](by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md)
- [UID:0004XN][0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer](by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md)
- [UID:0004XO][0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint](by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md)
- [UID:0004XP][0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect](by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md)
- [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md)
- [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md)
- [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) / `SetHighlightedPart`
- [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) / `BeginPartInteraction`
- [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md)
- [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA completion callback: added only `friend class CollectionPane;` to the existing private section so the two directly evidenced CollectionPane consumers can read `m_scrollPosition` and `m_scrollRange` without invented accessors; all prior declarations, natural layout, source ownership, and `93/93` score are preserved.
- 2026-07-30 B002 accepted UID0003CQ support synchronization:
  - Added `#include "ScrollBar.h"`, removed the duplicate `kScrollPanePartExtentBySkin` definition and class-local H declaration, and documented the one shared `0x00624144` object, values, four collection-family reads, and cross-family ownership proof.
  - Historicalized the earlier class-owned-table interpretation while preserving the dedicated class source, all nineteen child methods, formal class declaration, owner/emitter route, and `93/93` score.

- 2026-07-26 B002 accepted UID0003CN implementation callback:
  - Added the exhaustive primary/EventHandler/TimerHandler ABI contract, exact COL pointers, `+0/+0xa0/+0xa4` offsets, 18/11/2 counts, sole constructor stores, and exact source-owned slot/body links.
  - Confirmed the current H declaration is sufficient and intentionally kept formal CPP/H unchanged: shared scalar wrapper/adjustors contain no class-specific teardown, so an implicit derived destructor is more plausible than an invented explicit empty destructor.
  - Recorded physical UID0003CN/UID0001YP as compiler-only nonemitters and preserved rejected literal-table, covered-by-marker, broad-aggregate-owner, and class-specific-thunk-name alternatives.

- 2026-07-26 B005 accepted UID0001GT implementation callback:
  - Before: `88/90`, blank formal C++/H, six direct method emitters, unresolved source split and `+0xfa`, stale CanScroll/key-text assignment, and incomplete event/timer/paint/geometry declarations.
  - Changed to: `93/93`, dedicated `ui/core` route, complete human class CPP/H, natural `0x110` fields without a size typedef, enum and vtable-compatible virtuals, three-entry extent table, nineteen exact method children, resources, and explicit rejected-alternative/no-route history.
  - Evidence: accepted B005 UID0001GT report and serially validated validator-assigned child pages.

- 2026-06-27 B006 `HitTestScrollRegion` implementation:
  - Before: the class knew `HitTestScrollRegion` mapped point/cursor state to region `0..4`/none, but only `kScrollCollectionPartThumb` and `kScrollCollectionPartNone` were named, the hit-test child still had blank C++, and the class score rationale did not list [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) as a source-ready child.
  - Changed to: source-facing aliases now include the full five-part enum, `m_scrollSkinIndex`, `m_thumbDragActive`, `m_scrollEnabled`, and `kScrollPanePartExtentBySkin`; method notes and parent rationale record [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) as first-draft C++ at child position `40` with `89/91` target score. Class score remains `88/90`.
  - Evidence: accepted B006 report `tools/leaser/Agents/Agent-B006/research/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md` and implemented target page; live MCP session `b001_000241_20260627` reconfirmed exact boundary, caller pair, callee set, inline hit-test geometry, and point-in-rect helper order.
- 2026-06-27 B002 `SetHighlightedPart` / `BeginPartInteraction` implementation:
  - Before: the class still described `0x00562e80-0x00562fb0` as `SetHighlightedRegion / active-part drag setup`, listed children [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) at `86/89`, and kept a class score cap on remaining raw/manual helper names.
  - Changed to: completion/confidence raised from `86/88` to `88/90`; source-facing aliases and method notes now identify [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) as `ScrollCollectionPane::SetHighlightedPart` at child position `50` and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) as `ScrollCollectionPane::BeginPartInteraction` at child position `60`; parent/score rationale records child scores `89/91` and keeps only final file placement plus no-route original-name proof as caps.
  - Evidence: accepted B002 report `tools/leaser/Agents/Agent-B002/research/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md` and implemented child pages; live MCP session `80de0a67` reconfirmed exact raw boundaries, no function objects, no direct xrefs/pointer routes, accepted `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `GetPartRect`, `UpdateDragScroll`, and `ScheduleTimer` roles, and bounded child C++ readiness.
- 2026-06-26 B001 `UpdatePositionFromCursor` implementation:
  - Before: [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) was listed only as a cursor-to-position helper and still carried stale blank-C++/helper-name blocker state.
  - Changed to: the class now records [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) as a direct child with first-draft `void ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)` C++ at position `80`, accepted helper/field names, two cursor/origin sentinel checks, `m_thumbDragOffset` project `Point` y/x mapping, range clamp, and `CollectionPane` owner callback route.
  - Evidence: accepted B001 report `tools/leaser/Agents/Agent-B001/research/0001GX-ScrollCollectionPaneUpdatePositionFromCursor-source-quality.md`; current target implementation on [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md), with MCP facts for exact boundary, callers, callees, negative pointer/boundary checks, branch math, and source-owner rejections.
- 2026-06-26 B005 `UpdateDragScroll` implementation:
  - Before: [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) still carried file owner/emitter [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), blank formal C++, `86/88`, `GetScrollRegionRect` / active-region wording, and stale unresolved-helper / `90/90+` code-gate rationale.
  - Changed to: the class now records [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) as a direct child with first-draft `void ScrollCollectionPane::UpdateDragScroll()` C++ at position `70`, accepted aliases `ScrollCollectionPart`, `kScrollCollectionPartThumb`, `kScrollCollectionPartNone`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `GetPartRect`, `HitTestScrollRegion`, and `UpdatePositionFromCursor`, and a note that `+0x103/+0x104` are part fields even though the hit-test helper name uses `Region`.
  - Evidence: accepted B005 report `tools/leaser/Agents/Agent-B005/research/0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality.md` and target implementation on [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md), with live MCP facts for exact boundary, xrefs, callees, caller roles, active/highlight fields, cursor/local conversion, and source-owner rejections.
- 2026-06-25 B014 source-quality implementation:
  - Before: the terminal helper row used `ClearHighlight`, [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) remained `85/88`, and the class rationale still treated that child as blank-C++ due to raw-helper naming/source gates.
  - Changed to: the row now uses `ResetScrollState`, links [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md), records its `87/90` score and formal child C++ emission, and preserves the raw no-function/no-static-route caveat.
  - Evidence: B014 live MCP session `80de0a67` and PE route scan reconfirmed no modeled function or static route to `0x00563200`, while the bounded body and sibling reset-helper precedent support source-facing `ScrollCollectionPane::ResetScrollState()`.
- 2026-06-13 A001 Goal 2 raw-helper split:
  - Before: this class pointed to [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md) as a broad raw-helper pair.
  - Changed to: class notes now record the exact raw children [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md), both attached directly to this class at `86/89`.
  - Evidence: live IDA MCP `lookup_funcs`, `get_bytes`, `insn_query`, and `xref_query` on session `a002_batch_clear_timer` verified both raw helper bodies and their class-local state/call graph; the class score remained `85/85` at that time because the broader standalone-vs-`ScrollBar` file placement caveat was unchanged.
- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated despite detailed method, layout, vtable, raw-helper, and boundary documentation.
  - After: Scored as high completion with medium-high confidence because behavior is well mapped, while final source-file placement and several raw helper starts remain open.
  - Evidence: Existing method notes, boundary notes, layout/vtable references, and exact by-memory child pages support the score.
- 2026-05-31: Marked reconstructable in validator metadata.
  - Before: The page documented source-owned scrollbar behavior but left `RECONSTRUCTABLE` blank.
  - After: `RECONSTRUCTABLE` is set to `TRUE`; parent UID and C++ remained blank because the standalone-vs-`ScrollBar` source placement and raw helper split were not source-quality complete.
  - Evidence: IDA MCP confirms constructor, setters, input/paint helpers, vtable stores, and associated layout offsets in the linked memory/type pages.
- 2026-06-07: Raised confidence from `78` to `80` and attached the class to [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md).
  - Before: The class had strong method/layout/vtable evidence but stayed just below the parent-attachment confidence gate.
  - Changed to: `AUTOGEN_PARENT_UID` is now `0000NG`, with added parent/score rationale explaining the file attachment, source-placement caveat, and why by-memory child pages and final C++ are not changed here.
  - Evidence: [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) records the reviewed `ui/core/` file hypothesis, [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) records the function/caller/vtable/helper evidence, and the raw-helper children preserve the completion/source-quality cap.
- 2026-06-11 A004 Batch 151 parent-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:80`; class identity was strong but not enough for strict layout-child assignment.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`; existing file parent retained, final C++ still blank.
  - Evidence: live IDA MCP rechecked `CollectionPane::CollectionPane` allocation of `272` / `0x110` bytes (Verified with int_convert.py), sole constructor/enable caller path, range/position callback callers, internal helper call graph, vtable-store xrefs, and next sibling boundary. The score remains below final-source quality because the broader `ScrollBar` source split and raw helper names remain open.
- 2026-06-13 C001 Goal 2 barrier repair:
  - Before: this page referenced aggregate [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) with stale range `0x00561db0-0x0056325b`, and the exact clear-highlight child now represented by [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) was still attached directly to the broader file root below the strict routing shape.
  - Changed to: class-level notes now reference [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md); parent/score rationale records [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) and [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) at `85/88` and attached to this class.
  - Evidence: live IDA MCP on session `a002_batch_clear_timer` verified `0x0056325b` is the raw helper `retn`, `0x0056325c-0x00563260` is padding, and the raw helper's internal calls/state match the `ScrollCollectionPane` helper cluster.
- 2026-06-14 A001 file-parent sync:
  - Before: this class page still described the file parent [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) as `82/82` after the class/type children had already cleared `85/85+`.
  - Changed to: parent-score references now use `86/85`, and the class rationale no longer caps itself on a below-gate file parent.
  - Evidence: live IDA MCP database `b001_0003gy` reconfirmed the file page's direct caller/setter/vtable evidence while preserving the unresolved standalone-vs-`ScrollBar` caveat.
- 2026-06-16 A002 class-confidence refresh:
  - Changed from `85/85` to `86/88`, retaining owner/emitter [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md).
  - Evidence: live IDA MCP reconfirmed the full function map, sole constructor caller, range/current/enable callers, internal hit-test/geometry/update helper graph, raw helper no-function/no-xref status, vtable stores, raw prologue bytes, and clear-helper tail/padding. Remaining blockers are now the real source-placement and naming limits: standalone `ScrollCollectionPane.cpp` versus `ScrollBar.cpp`, raw helper declaration names, and final field/member names.
