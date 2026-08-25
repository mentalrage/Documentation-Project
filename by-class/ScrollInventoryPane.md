*** UID:0000CK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "InventoryScrollPane.h"

#include "NewInventoryPane.h"
#include "../core/Event.h"
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/Pane.h"

class NewInventoryPane;
class Event;
struct RectBounds;

enum ScrollInventoryPart
{
    kScrollInventoryPartLeading = 0,
    kScrollInventoryPartPageBeforeThumb = 1,
    kScrollInventoryPartThumb = 2,
    kScrollInventoryPartPageAfterThumb = 3,
    kScrollInventoryPartTrailing = 4,
    kScrollInventoryPartNone = -1
};

class ScrollInventoryPane : public Pane
{
public:
    explicit ScrollInventoryPane(unsigned char orientation);

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
    friend class NewInventoryPane;

    ScrollInventoryPart HitTestScrollRegion(int localY, int localX);
    void GetPartRect(ScrollInventoryPart part, RectBounds *bounds);
    void SetHighlightedPart(ScrollInventoryPart part);
    void BeginPartInteraction(ScrollInventoryPart part,
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane

## NewInventoryPane Friend Contract - 2026-08-16

- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) is the sole constructor consumer and owner of one ScrollInventoryPane instance at its `+0x114` field.
- NewInventoryPane directly synchronizes `m_scrollRange` and `m_scrollPosition`, while ScrollInventoryPane calls `NewInventoryPane::OnScrollPositionChanged`. The narrow `friend class NewInventoryPane;` declaration reproduces that observed private-state contract without public fields or invented getters.
- Ownership remains standalone through [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md); friendship does not fold this class or any of its 19 definitions into NewInventoryPane.cpp.
- Completion/confidence are `90/93`: the consumer callback/private-state contract and legal header route are now explicit and validated; unrelated class behavior and source ownership remain unchanged.

## Status

- Confidence: very strong for complete behavior, the natural `0x110` layout, three compiler-generated facets, exact method/gap boundaries, standalone source placement, and the `NewInventoryPane` constructor/callback relationship.
- Accepted source file: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), emitted as `NexusTK/ui/inventory/InventoryScrollPane.cpp` and `InventoryScrollPane.h`. The former private-fold hypothesis is retained only as corrected historical evidence.
- Address range: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- Layout: [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- Vtables: [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)

## Class Purpose

`ScrollInventoryPane` is the EPF-backed scrollbar pane used by the newer item inventory UI. It manages scroll range, current position, orientation, highlighted region, drag tracking, auto-repeat timers, and scrollbar painting.

## Autogen Status

- Parent file: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- Reconstructable: `TRUE`
- The formal CPP channel owns the exact include preamble and `[[CHILDREN]]` route; exactly nineteen child pages own the definitions in address/source order.
- The formal H channel owns the complete part enum, class declaration, virtual/private/public method declarations, and natural tail fields. Child H channels remain blank to avoid duplicate declarations.
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) is `91/93` and marker-only: it indexes the exact island and never duplicates a method body.

The standalone file assignment is the accepted source-quality route. NewInventoryPane remains the sole constructor consumer and receives the position-change callback, but those relationships do not make it the class's implementation owner.

## Historical Sampled Method Notes

The table below records earlier partial coverage and old names. It is retained as historical evidence; the exhaustive current inventory and accepted source identities are in the next section.

| Method | Address | Role |
| --- | --- | --- |
| `ScrollInventoryPane` | `0x00563260-0x00563301` | Constructs scrollbar pane with vertical or horizontal orientation. |
| `SetMaxRange` | `0x00563370-0x005633ca` | Clamps max range and current position. |
| `SetScrollPosition` | `0x005633d0-0x005633f6` | Updates scroll position and invalidates. |
| `EnableScrollbar` | `0x00563400-0x00563419` | Enables the control and invalidates. |
| `OnMouseEvent` | `0x00563460-0x00563640` | Handles drag and click interactions. |
| `OnTimerEvent` | `0x00563660-0x00563692` | Handles held-button auto-scroll. |
| `OnPaint` | `0x005636a0-0x00563d7f` | Paints track, thumb, and arrows with EPF assets. |
| `GetScrollbarRegionRect` | `0x005640a0-0x00564326` | Returns rectangles for arrow, track, and thumb parts. |
| `SetHighlightRegion` | `0x00564330-0x0056439f` | Updates highlighted region and invalidates. |
| `UpdateFromDrag` | [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | Superseded historical approximation `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)`. B008 `aa3930bd` MCP evidence fixed the exact modeled range/callers/fields/callback/padding; the exhaustive callback later corrected the source identity to `UpdatePositionFromCursor(int localY, int localX)` and standalone InventoryScrollPane placement. |
| `ResetScrollState` | [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | Exact raw source-bearing helper. Removes pending timers through the `+0xa4` TimerHandler view, clears `m_activePart` at `+0x104`, conditionally invalidates the old `m_highlightPart` at `+0x103` through `GetPartRect` and Pane invalidation, then clears `m_highlightPart`. B003 PE scan found no direct caller, VA/RVA literal, pointer-table route, vtable route, or external direct branch into the span; no-route status limits score and IDA function creation but no longer blocks first-draft C++ after the `86/89` update. |

## Accepted Nineteen-Method Inventory

| Pos | Exact child | Source identity | Binary/evidence disposition |
| ---: | --- | --- | --- |
| 10 | [UID:00051C][0x00563260-0x00563301.ScrollInventoryPaneConstructor](by-memory/0x00563260-0x00563301.ScrollInventoryPaneConstructor.md) | `ScrollInventoryPane(unsigned char orientation)` | Modeled constructor; sole caller `0x004eb4e4`; exact three-vtable and `0x110` initialization. |
| 20 | [UID:00051D][0x00563310-0x00563337.ScrollInventoryPaneSetSkinIndexRaw](by-memory/0x00563310-0x00563337.ScrollInventoryPaneSetSkinIndexRaw.md) | `SetSkinIndex(unsigned short)` | Retained raw/no-start-route body; exact `+0xf8` compare/store and conditional invalidation. |
| 30 | [UID:00051E][0x00563340-0x00563364.ScrollInventoryPaneSetScrollStyleRaw](by-memory/0x00563340-0x00563364.ScrollInventoryPaneSetScrollStyleRaw.md) | `SetScrollStyle(unsigned char)` | Retained raw/no-start-route body; exact `+0xfa` compare/store and conditional invalidation. |
| 40 | [UID:00051F][0x00563370-0x005633cb.ScrollInventoryPaneSetMaxRange](by-memory/0x00563370-0x005633cb.ScrollInventoryPaneSetMaxRange.md) | `SetMaxRange(short)` | Modeled; clamps `0..30000`, then position/range with binary-order invalidations. |
| 50 | [UID:00051G][0x005633d0-0x005633f7.ScrollInventoryPaneSetScrollPosition](by-memory/0x005633d0-0x005633f7.ScrollInventoryPaneSetScrollPosition.md) | `SetScrollPosition(short)` | Modeled; four callers; changed signed position and visible-bounds invalidation. |
| 60 | [UID:00051I][0x00563400-0x0056341a.ScrollInventoryPaneEnable](by-memory/0x00563400-0x0056341a.ScrollInventoryPaneEnable.md) | `Enable()` | Modeled; constructor consumer caller; transition-only invalidation. |
| 70 | [UID:00051J][0x00563420-0x0056343a.ScrollInventoryPaneDisableRaw](by-memory/0x00563420-0x0056343a.ScrollInventoryPaneDisableRaw.md) | `Disable()` | Retained raw/no-start-route inverse transition. |
| 80 | [UID:00051K][0x00563440-0x0056345a.ScrollInventoryPaneCanScrollRaw](by-memory/0x00563440-0x0056345a.ScrollInventoryPaneCanScrollRaw.md) | `CanScroll() const` | Retained raw predicate: enabled and signed range greater than zero. |
| 90 | [UID:00051L][0x00563460-0x00563641.ScrollInventoryPaneHandlePointerOrMouseEvent](by-memory/0x00563460-0x00563641.ScrollInventoryPaneHandlePointerOrMouseEvent.md) | `HandlePointerOrMouseEvent(Event *)` | EventHandler slot `0x0062407c`; complete pointer/capture/drag/timer-release state machine. |
| 100 | [UID:00051M][0x00563650-0x00563655.ScrollInventoryPaneHandleKeyOrTextEvent](by-memory/0x00563650-0x00563655.ScrollInventoryPaneHandleKeyOrTextEvent.md) | `HandleKeyOrTextEvent(Event *)` | EventHandler slot `0x00624080`; exact unconditional false override. |
| 110 | [UID:00051N][0x00563660-0x00563693.ScrollInventoryPaneOnTimer](by-memory/0x00563660-0x00563693.ScrollInventoryPaneOnTimer.md) | `OnTimer(int,int,int)` | TimerHandler slot `0x006240ac`; timer 0 repeat and 30-ms reschedule. |
| 120 | [UID:00051O][0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint](by-memory/0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md) | `OnPaint()` | Primary slot `0x00624070`; full clipped SLIDEBG/SCRBUTT rendering path. |
| 130 | [UID:00051P][0x00563d80-0x0056409d.ScrollInventoryPaneHitTestScrollRegion](by-memory/0x00563d80-0x0056409d.ScrollInventoryPaneHitTestScrollRegion.md) | `HitTestScrollRegion(int localY,int localX)` | Two direct callers; exact five-part orientation/drag geometry. |
| 140 | [UID:00051Q][0x005640a0-0x00564327.ScrollInventoryPaneGetPartRect](by-memory/0x005640a0-0x00564327.ScrollInventoryPaneGetPartRect.md) | `GetPartRect(ScrollInventoryPart,RectBounds *)` | Thirteen internal callers; complete part rectangle contract. |
| 150 | [UID:00051R][0x00564330-0x005643a0.ScrollInventoryPaneSetHighlightedPartRaw](by-memory/0x00564330-0x005643a0.ScrollInventoryPaneSetHighlightedPartRaw.md) | `SetHighlightedPart(ScrollInventoryPart)` | Retained raw/no-start-route body; invalidates old/new parts before store. |
| 160 | [UID:00051S][0x005643a0-0x0056445f.ScrollInventoryPaneBeginPartInteractionRaw](by-memory/0x005643a0-0x0056445f.ScrollInventoryPaneBeginPartInteractionRaw.md) | `BeginPartInteraction(ScrollInventoryPart,int,int)` | Retained raw interaction setup; immediate update and 200-ms timer. |
| 170 | [UID:00051T][0x00564460-0x00564520.ScrollInventoryPaneUpdateDragScroll](by-memory/0x00564460-0x00564520.ScrollInventoryPaneUpdateDragScroll.md) | `UpdateDragScroll()` | Three callers; cursor-local update and stale-highlight invalidation. |
| 180 | [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | `UpdatePositionFromCursor(int localY,int localX)` | Two callers; exact orientation-specific position math and NewInventoryPane callback. |
| 190 | [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | `ResetScrollState()` | Retained raw/no-start-route cleanup; timers, active/highlight state and invalidation. |

All nineteen definition children use formal CPP only and blank H channels. Their deterministic positions preserve the binary/source order; the sixteen inter-method spans are compiler alignment and emit no source. The file excludes literal vtables/RTTI/EH, a class-local shared extent table, resource-string definitions, a destructor not found in the range, and the `0x00564710` ScrollVolumePane successor.

## Accepted Layout, Vtables, And Dependencies

- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) records the natural `0x110` object, Pane base through `+0xf7`, fields at `+0xf8..+0x104`, natural padding, and `Point +0x108`.
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md) records compiler-generated primary/EventHandler/TimerHandler tables at `0x0062402c/0x00624078/0x006240a8`; it is non-reconstructable and emits no literal arrays.
- Shared `kScrollPanePartExtentBySkin[3] = {38,38,38}` at `0x00624144` is owned by [UID:0000NF][ScrollBar](by-file/ScrollBar.md) and imported through `../core/ScrollBar.h`.
- `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL` remain shared resource dependencies, not class-owned data.
- The accepted whole-file SHA256 is `0a13dff3ec18ec9fbe5a5398e08cd6cd1a669ecfa3665ed18025b07c6949d443`; 5138/5292 bytes match the equal-length ScrollCollectionPane family, with 154 bytes in 77 differing runs (`97.090%`).

## Corrected Source And Header Contract

- Bounds are inherited as `GrafPort::m_visibleBounds`; there is no ScrollInventoryPane- or Pane-local `m_bounds` field.
- Pointer input uses `Event::m_payload.m_pointer` and `kEventCursorMove`; EventMan owns `GetCursorPosition(Point *)` in Event.h, and Pane owns protected `CaptureMouse()`/`ReleaseMouseCapture()` in Pane.h.
- Painting uses `EPFTileContext::Initialize()`, `ImageLib::LookupLayoutEntry`, the imported `g_pfnFillRect` surface procedure, and GrafPort's six-argument `RenderTileFrame` contract. The CPP preamble therefore includes `ImageLib.h` and `Surface.h` in addition to the established Event, ScrollBar and EPFTileContext headers.
- NewInventoryPane owns a complete normal 0x158 class declaration and the `OnScrollPositionChanged(unsigned char, short, short)` callback; InventoryScrollPane consumes that declaration rather than emitting a local shim.
- The older generated bodies using `m_bounds`, direct Event payload aliases, free EPF initialization, unqualified fill and four-argument rendering are retained only as a superseded callback checkpoint.

## Evidence Notes

- IDA MCP confirms constructor, paint, and region-rect functions.
- IDA MCP caller check on 2026-05-24 shows the constructor `0x00563260` is only directly called from `NewInventoryPane::NewInventoryPane` at `0x004eb4e4`.
- IDA MCP lookup confirms the activation helper `0x00563400` as a real `0x1a`-byte function.
- IDA reports no function at `0x005646b0`; previous modeled function is `0x00564520-0x005646ad`, and raw disassembly shows method-shaped reset code through `0x0056470c` before the next function at `0x00564710`. Treat the reset-helper function-table mismatch as data debt.
- IDA-backed allocation and constructor evidence records a `0x110`-byte pane object with the scrollbar tail layout now tracked in [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md). The generated `m_highlightRegion` name at `+0x104` is weaker than the raw reset evidence, which treats `+0x103` as the stale hover/highlight part and `+0x104` as active state.
- 2026-05-26 IDA MCP confirms vtable bases `0x0062402c`, `0x00624078`, and `0x006240a8`, with paint, mouse, and timer slots mapped in [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) gives the standalone file-level container a reviewed `90/92` score and the same `NexusTK/ui/inventory/` path used by the surrounding [UID:0000KA][InventoryPane](by-file/InventoryPane.md) module.
- The raw reset helper and aggregate/update child pages remain useful evidence. [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) is `91/93` with a marker-only aggregate block; [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) is `91/93` and emits the accepted `UpdatePositionFromCursor` C++ after the B005 source-contract callback; [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) keeps a function-table/caller-provenance caveat while emitting first-draft `ResetScrollState()` C++.
- 2026-07-04 B007 `aa3930bd` source-quality callback confirms the UID0001GZ aggregate has the same one `NewInventoryPane` constructor caller at `0x004eb4e4`, current modeled/raw function inventory, constructor vtable refs at `0x0062402c/0x00624078/0x006240a8`, UID0001H0 dispatcher xrefs at `0x005644bb/0x005644e4`, zero xrefs to raw reset `0x005646b0`, and marker-only generated-output policy. Direct `NewInventoryPane`, generic `ScrollBar`, no-owner/non-emitting, broad-body, `[[CHILDREN]]`, and child-C++ copy remain rejected for the aggregate; UID0001H0 is now intentionally handled on its own child page by B008.
- 2026-07-04 B008 source-quality callback resolves [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) as source-ready through this class. The target now records `aa3930bd` range, caller, callee, field, callback, and padding evidence; historicalizes stale unassigned/below-gate/empty-marker language; and preserves exact-name, point-member, and file-split caveats below final-audit confidence.
- 2026-06-11 IDA MCP recheck confirms the `NewInventoryPane` constructor allocates `272` bytes (`0x110`, verified with `int_convert.py`) before calling `0x00563260`, `callers 0x00563260` still reports only `0x004eb4e4`, and `xrefs_to` confirms constructor stores to the three vtable bases at `0x0062402c`, `0x00624078`, and `0x006240a8`.
- 2026-06-11 IDA MCP decompilation reconfirms the constructor writes orientation/current/range/enabled/hover/active/drag-tail fields at `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108`; the associated layout is now assigned through [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md).
- 2026-06-18 B003 source-quality update resolves [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) as an exact source-bearing class method `ScrollInventoryPane::ResetScrollState()`. The raw helper still has no IDA function object, no direct raw-start caller, no VA/RVA pointer route, no vtable slot, and no external direct branch into the range, so IDA function creation remains unsafe. That caveat no longer blocks first-draft C++ under the active combined-score/emitter gate once the child is raised to `86/89` and routed through this class. The method uses `m_highlightPart` at `+0x103`, `m_activePart` at `+0x104`, the `+0xa4` TimerHandler view, `GetPartRect`, and Pane invalidation.

## Superseded Historical Parent And Score Rationale

The following table and `85/86` prose are retained as dated project history only. They do not describe the current exhaustive class state or current score.

| Item | Score | Relevance |
| --- | ---: | --- |
| [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) | `86/88` | Historical parent checkpoint: documented the then-provisional dedicated scrollbar file hypothesis, projected path, method family, layout/vtable refs, one-caller evidence, and possible fold into `NewInventoryPane`. |
| [UID:0000KA][InventoryPane](by-file/InventoryPane.md) | `85/86` | Confirms the broader `ui/inventory/` ownership and the item-inventory/new-inventory split that hosts this scrollbar. |
| [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) | `86/90` | Confirms the executable range, constructor caller, vtable stores, field offsets, owner-chain rationale, raw helper islands, generated Empty Emitter Marker repair, and marker-only no-standalone-body policy; direct owner/emitter remains this class. |
| [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | `88/91` | Source-ready drag/update helper. It has a modeled function body, two dispatcher callers, class-local field and `GetPartRect` usage, exact owner callback route, formal first-draft C++, and rejected direct `NewInventoryPane`, generic scrollbar, no-owner/no-code, sibling merge, and padding-extension alternatives. |
| [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | `86/89` | Strong evidence for the reset behavior, exact raw span, class owner/emitter route, source-facing field/helper names, rejected hidden routes and false pointer artifacts, and bounded first-draft C++; still caps final-audit confidence because no modeled function start or caller provenance exists. |

The class confidence is `86`, not higher, because the local behavior, layout/vtable anchors, parent page, and aggregate memory page now agree under live IDA recheck, but the original source split and broader class declaration are still not final-source quality. The reset child now has source-quality first-draft C++ despite retaining its raw no-direct-route caveat.

Completion is `85` because the class page covers parent metadata, method inventory, layout and vtable evidence, constructor caller, update/reset child pages, strict-gate status, and source-split caveat. It remains below final-source readiness until remaining exact method child pages/raw helper islands are complete, the reset helper has stronger provenance, and the standalone/folded source decision is closed.

## Current Score Rationale

- Completion `89`: class ownership, standalone file placement, 19-method/16-gap inventory, 0x110 layout, three compiler vtable facets, shared dependencies, complete enum/class H, corrected CPP preamble, exact child order, and all affected source contracts are documented. Validator command `000000024570` completed coherent generated CPP/H verification.
- Confidence `91`: binary boundaries, hashes, clone ratio, behavior, layout and owner graph are very strong; seven raw starts lack direct static liveness, exact original spellings remain inferred, and rebuilt-binary comparison remains absent.
- The earlier `94/95` source-ready checkpoint is historical because its generated bodies used rejected project APIs. The corrected formal source and normal dependency-owner declarations supersede those bodies without discarding the valid binary research.

## Cross-References

- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)

## Changes

- 2026-08-15 B005 accepted UID0000KB implementation callback:
  - Raised `85/86` to `94/95`, finalized standalone `InventoryScrollPane.cpp/.h` placement, and historicalized the former private-fold uncertainty.
  - Added the exact CPP include/child preamble and complete H enum/class declaration, including all nineteen declarations and natural tail fields.
  - Attached the seventeen validator-assigned new children plus UID0001H0/UID0001H1 in exact source order and documented all padding, clone, vtable, shared-data/resource, consumer/callback and successor exclusions.
  - Preserved compiler-generated vtables as non-emitting and did not invent a destructor or duplicate shared constants/resources.
- 2026-08-15 B005 source-contract callback:
  - Corrected the CPP preamble with ImageLib/Surface dependencies while retaining the complete enum/class H and exact child marker.
  - Routed inherited bounds, Event payload/enumerator, EventMan cursor access, Pane capture, NewInventoryPane callback and render/fill APIs through their natural declarations.
  - Historicalized the stale `85/86` and invalid `94/95` source-ready checkpoints, adopted `89/91`, and completed coherent generated CPP/H verification under validator command `000000024570`.

- 2026-05-30: Changed completion/confidence from `0/0` to `80/78`.
  - Before: The page was unevaluated despite documenting the inventory scrollbar methods, owner/caller, layout, vtables, and reset-helper mismatch.
  - After: Scored as high completion with medium-high confidence because scrollbar behavior is strong, while one raw reset-helper boundary and source placement remain unresolved.
  - Evidence: Existing method notes, IDA caller/evidence notes, layout/vtable references, and NewInventoryPane relationship support the score.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: The class page documented project-owned behavior but had no validator reconstructable flag.
  - Changed to: The page is flagged as rebuild-owned while `AUTOGEN_PARENT_UID` and C++ remain blank.
  - Historical evidence, superseded for [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) by the 2026-06-18 B003 source-quality pass: IDA MCP confirmed `NewInventoryPane::NewInventoryPane` allocates a 0x110-byte pane, calls the `0x00563260` constructor, and stores the result as an owned item-inventory scrollbar; final source-file placement and source-quality C++ were then treated as below the 95+ gate.
- 2026-06-07: Raised confidence from `78` to `80` and attached the class to [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md).
  - Before: The class had 80 completion but stayed below the attachment confidence gate, even though its proposed file parent had already reached `84/80`.
  - Changed to: `AUTOGEN_PARENT_UID` is now `0000KB`, with added parent/score rationale explaining the file attachment, raw reset-helper caveat, and why by-memory children and final C++ are not changed here.
  - Evidence: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) records the dedicated `ui/inventory/` scrollbar source hypothesis, [UID:0000KA][InventoryPane](by-file/InventoryPane.md) corroborates module placement, [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) records caller/layout/vtable evidence, and [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) preserves the reset-helper provenance cap.
- 2026-06-07: Reconciled class status with the strengthened aggregate/layout/vtable pages.
  - Before: The page still cited recovered generated source directly and kept the class at `80/80` despite the aggregate memory page now documenting a stronger `78/84` owner chain and raw reset-helper evidence.
  - Changed to: raised to `82/82`, added autogen-status notes, removed direct generated-source dependency from the status block, refreshed the aggregate-memory score in the rationale table, and kept C++ blank.
  - Evidence: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) now records the owner chain and boundary evidence at `78/84`; [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) records the `0x110` object size and tail fields; [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md) records the three constructor-installed vtable views.
- 2026-06-11 A008 Batch 155 strict-gate refresh:
  - Before: the class was `82/82`, already attached to [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), while the file parent was only `84/80` and [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) remained unassigned.
  - Changed to: `85/86`, with updated parent/score rationale, live IDA refresh notes, and support for assigning the layout page to this class.
  - Evidence: live IDA MCP rechecked the sole constructor caller, `0x110` allocation, vtable store xrefs, constructor field writes, and the existing raw helper/reset caveats; [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) now clears `85/85`.
- 2026-06-18 B003 support incorporation:
  - Updated the reset-method row, autogen status, evidence notes, and child score table for [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md).
  - Evidence: B003 resolved the raw reset helper's source-facing name/signature, class owner/emitter, `+0xa4` TimerHandler view, `m_highlightPart`/`m_activePart` fields, `GetPartRect` and Pane invalidation roles, no VA/RVA/direct/table/vtable route finding, rejected unaligned instruction-byte pointer artifacts, and first-draft C++ readiness. The class page remains non-emitting class support while the child emits the exact method body.
- 2026-07-04 B007 UID0001GZ marker-only support sync:
  - Updated aggregate status and score references for [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) after it moved to `86/90` with a formal no-standalone-body marker.
  - Evidence: B007 MCP session `aa3930bd` confirmed active IDB health, modeled/raw function inventory, one `NewInventoryPane` constructor caller, constructor vtable refs, UID0001H0 dispatcher/update xrefs, UID0001H1 zero-xref raw reset state, byte/padding facts, and generated Empty Emitter Marker state. At that historical B007 checkpoint, UID0001H0 C++ was intentionally left untouched because B008 owned the active child report; the 2026-07-04 B008 support sync below supersedes that child state.
- 2026-07-04 B008 UID0001H0 source-ready support sync:
  - Updated the method row, evidence notes, and score table for [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) after it moved to `88/91` and populated formal first-draft `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` C++.
  - Evidence: B008 accepted report SHA256 `69712D40417BB6D53A4351D1A350C5BCC1ED46F2CB06A8887B748A5E4E470908` and target implementation record exact range `0x00564520-0x005646ad`, two dispatcher calls `0x005644bb/0x005644e4`, class fields `+0xfc/+0xfe/+0x100/+0x108/+0x10c`, `GetPartRect`, cursor/origin helpers, owner callback `0x004eba00`, successor padding, and rejected direct `NewInventoryPane`, generic scrollbar, no-owner/no-code, sibling merge, and range-extension alternatives.
