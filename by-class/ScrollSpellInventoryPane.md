*** UID:0000CN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollSpellInventoryPane.h"

#include "NewSpellInventoryPane.h"
#include "../core/Event.h"
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H

#include "../core/Pane.h"

class Event;
class NewSpellInventoryPane;

enum ScrollSpellInventoryPart {
    kScrollSpellInventoryPartLeading = 0,
    kScrollSpellInventoryPartPageBeforeThumb = 1,
    kScrollSpellInventoryPartThumb = 2,
    kScrollSpellInventoryPartPageAfterThumb = 3,
    kScrollSpellInventoryPartTrailing = 4,
    kScrollSpellInventoryPartNone = -1
};

class ScrollSpellInventoryPane : public Pane
{
public:
    explicit ScrollSpellInventoryPane(unsigned char orientation);

    void SetSizeIndex(unsigned short sizeIndex);
    void SetScrollStyle(unsigned char scrollStyle);
    void SetMaxRange(short maxRange);
    void SetScrollPosition(short position);
    void Activate();
    void Deactivate();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    friend class NewSpellInventoryPane;

    ScrollSpellInventoryPart HitTestPart(int localY, int localX);
    void GetPartRect(ScrollSpellInventoryPart part, RectBounds *bounds);
    void SetHoverPart(ScrollSpellInventoryPart part);
    void BeginInteraction(ScrollSpellInventoryPart part,
                          int mouseY,
                          int mouseX);
    void UpdateDragScroll();
    void UpdateFromDrag(int localY, int localX);
    void ResetScrollState();

    unsigned short m_sizeIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_hoverPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char ScrollSpellInventoryPaneSizeMustBe272[
    sizeof(ScrollSpellInventoryPane) == 0x110 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane
## UID0000NJ Complete Class And Header Closure - 2026-08-16

This page is the sole source declaration carrier for the standalone `ScrollSpellInventoryPane.cpp/.h` unit. Its formal CPP emits the normal header and all required compilation dependencies before `[[CHILDREN]]`; its formal H emits the complete human-written class declaration. Exact method bodies are owned by nineteen bounded by-memory children in positions 10 through 190, so neither the broad aggregate nor the layout/vtable evidence pages duplicate source.

| Position | UID | Method/source role |
| --- | --- | --- |
| 10 | [UID:000538][0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor](by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md) | Constructs the `0x110` object and installs primary, EventHandler, and TimerHandler views. |
| 20 | [UID:000539][0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw](by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md) | Changed-only `m_sizeIndex` setter. |
| 30 | [UID:00053A][0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw](by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md) | Changed-only `m_scrollStyle` setter. |
| 40 | [UID:00053B][0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange](by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md) | Signed range clamp and two-stage invalidation. |
| 50 | [UID:00053C][0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition](by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md) | Changed signed position setter. |
| 60 | [UID:00053D][0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate](by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md) | Enables on transition. |
| 70 | [UID:00053E][0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw](by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md) | Disables on transition. |
| 80 | [UID:00053F][0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw](by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md) | Tests enabled state and positive range. |
| 90 | [UID:00053G][0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent](by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md) | EventHandler mouse/capture state machine. |
| 100 | [UID:00053H][0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent](by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md) | EventHandler false-return key/text slot. |
| 110 | [UID:00053I][0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer](by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md) | 30 ms repeat dispatch. |
| 120 | [UID:00053J][0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint](by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md) | EPF/PAL-backed track, caps, and thumb painting. |
| 130 | [UID:00053K][0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart](by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md) | Five-part hit testing. |
| 140 | [UID:00053L][0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect](by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md) | Orientation/range/drag-sensitive geometry. |
| 150 | [UID:00053M][0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw](by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md) | Old/new hover invalidation. |
| 160 | [UID:00053N][0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw](by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md) | Thumb anchor or page/button activation and 200 ms repeat. |
| 170 | [UID:00053O][0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll](by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md) | No-argument cursor-driven interaction dispatcher. |
| 180 | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Geometry-to-range conversion and NewSpell callback. |
| 190 | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Timer removal and active/hover reset. |

The physical tail after the inherited `Pane` base is `m_sizeIndex` +0xf8, `m_scrollStyle` +0xfa, `m_thumbDragActive` +0xfb, `m_orientation` +0xfc, alignment at +0xfd, `m_scrollPosition` +0xfe, `m_scrollRange` +0x100, `m_enabled` +0x102, signed `m_hoverPart` +0x103, signed `m_activePart` +0x104, alignment +0x105..+0x107, and `m_thumbDragOffset` +0x108. The declaration's size guard fixes the complete object at `0x110`. The three compiler facets are at `0x00623e94`, `0x00623ee0`, and `0x00623f10`; they and their RTTI are regenerated from this declaration and are not literal source arrays.

The standalone source placement is selected from the closed implementation island, dedicated class/layout/vtables, and sibling module convention. Constructor-only containment under `NewSpellInventoryPane` is preserved as a rejected historical fold hypothesis. Exact private spellings and file capitalization remain inferred, which caps the class at 89/91 without weakening the exact runtime contract.

## UID0000LU Header And Friendship Synchronization - 2026-08-15

The accepted ScrollSpellInventoryPane declaration now lives in the normal sibling H channel and the CPP includes that header before its existing children. `friend class NewSpellInventoryPane;` is the exact private-state access route for scrollbar range/position synchronization; no reduced local declaration or new public accessor is introduced.

The class remains the standalone private NewSpell companion with its existing `0x110` layout, vtables, source children, drag/update/reset behavior, and file route unchanged.

## Status

- Confidence: strong for scrollbar behavior, constructor ownership, exact `0x110` natural tail layout, vtable anchors, the `NewSpellInventoryPane` caller/callback contract, raw reset/hover boundaries, and the selected human source declaration.
- Selected source file: standalone [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), projected as `NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`. The previous possible fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) is retained as a rejected historical source-organization alternative, not current placement.
- Address range: [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- Layout: [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- Vtables: [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- Read-only-data evidence: [UID:00026D][0x00623d58-0x00624184.ScrollPaneReadOnlyData](by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md)
- Formal C++ is the declaration-level source carrier at file position `10`. It declares `Pane` as the sole direct source base, the four accepted class-specific virtuals, selected private method names, the natural tail fields, the `0x110` size guard, and `[[CHILDREN]]`. Exact method bodies remain on bounded by-memory children and are not duplicated here.

## Class Purpose

`ScrollSpellInventoryPane` is the EPF-backed scrollbar pane used by spell inventory UI. It manages scroll range, position, activation, drag/click state, repeat timers, painting, part rectangles, hover part updates, and reset-to-idle behavior.

## Lifecycle Summary

`ScrollSpellInventoryPane` is a private spell-inventory scrollbar companion. The constructor is observed from [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md), and the surrounding `SpellInventoryPane` file docs keep it under `NexusTK/ui/inventory/` rather than generic control or text-edit ownership.

| Phase | Evidence | Notes |
| --- | --- | --- |
| Construction/setup | `0x0055f450-0x0055f4f1`, `0x0055f5f0-0x0055f609` | Builds the `0x110`-byte pane tail, installs the three vtable views, records orientation/state fields, and activates the spell scrollbar from the new-spell inventory path. |
| Style/range/position | `0x0055f500-0x0055f5e6` | Raw setter `0x0055f500` updates the `+0xf8` size/skin-table index word and invalidates on change; raw setter `0x0055f530` updates unresolved `+0xfa` scroll style/state byte and invalidates on change; modeled range/current helpers clamp maximum range/current position and invalidate only on state changes. |
| Activation/availability | `0x0055f5f0-0x0055f64a` | `Activate` sets the enabled/visible byte; raw `Deactivate`/`Hide` clears `+0x102` and invalidates if active; raw `CanScroll`/`IsScrollable` tests enabled state and range before input work. |
| Input/repeat | `0x0055f650-0x0055f882`, `0x00560650-0x00560710`, [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Handles drag/click/repeat behavior, includes the source-authored false-return input/event virtual at `0x0055f840`, dispatches the active part/input bridge at `0x00560650`, converts drag geometry into scroll positions, and notifies the owning spell-inventory pane. |
| Paint/layout | `0x0055f890-0x00560516` | Draws the EPF-backed track/button assets, resolves hit-tested scrollbar parts through `0x0055ff70`, and computes part rectangles from the layout fields through `GetPartRect`. |
| Hover/active/reset | `0x00560520-0x0056064f`, [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Exact SetHoverPart/BeginInteraction children update hover/active state, invalidation, drag anchor, and repeat timing; the exact raw ResetScrollState child remains no-direct-route evidence while emitting its accepted enum-shaped body at `93/94`, position 190. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollSpellInventoryPane` | `0x0055f450-0x0055f4f1` | Constructs scrollbar pane with orientation and initial state. |
| `SetSizeIndex` | `0x0055f500-0x0055f526` | Selected source-facing setter for `unsigned short m_sizeIndex` at `+0xf8`; invalidates when the value changes. `SetScrollbarSizeIndex` remains a rejected spelling alternative. |
| `SetScrollStyle` | `0x0055f530-0x0055f553` | Selected source-facing setter for byte `m_scrollStyle` at `+0xfa`; invalidates when the value changes. `SetStateByte` remains a rejected low-information spelling. |
| `SetMaxRange` | `0x0055f560-0x0055f5ba` | Clamps max range and current position. |
| `SetScrollPosition` | `0x0055f5c0-0x0055f5e6` | Updates scroll position and invalidates. |
| `Activate` | `0x0055f5f0-0x0055f609` | Shows the scrollbar and triggers initial paint. |
| `Deactivate` | `0x0055f610-0x0055f629` | Selected source-facing helper that clears `m_enabled` at `+0x102` and invalidates if the scrollbar had been active. |
| `CanScroll` | `0x0055f630-0x0055f649` | Selected source-facing predicate that checks enabled state and range before scroll/input work. |
| `HandlePointerOrMouseEvent` | `0x0055f650-0x0055f830` | Secondary-view virtual handling mouse drag and click interactions. |
| `HandleKeyOrTextEvent` | `0x0055f840-0x0055f844` | Five-byte source-authored false-return override in the secondary input/event vtable, not compiler padding. |
| `OnTimer` | `0x0055f850-0x0055f882` | Tertiary-view virtual that auto-repeats scroll action while a button is held. |
| `OnPaint` | `0x0055f890-0x0055ff6f` | Paints track sections and scroll button. |
| `HitTestPart` | `0x0055ff70-0x0056028c` | Selected source-facing helper resolving local Y/X coordinates to a `ScrollSpellInventoryPart`. |
| `GetPartRect` | `0x00560290-0x00560516` | Calculates rectangles for scrollbar parts. |
| `SetHoverPart` | `0x00560520-0x00560590` | Raw source-shaped helper that updates hover part and invalidates affected regions. |
| `BeginInteraction` | `0x00560590-0x0056064e` | Selected source-facing helper recording `m_activePart`, storing `Point m_thumbDragOffset` in project Y/X order at `+0x108/+0x10c`, and starting repeat handling through the inherited TimerHandler facet. |
| `UpdateDragScroll` | `0x00560650-0x0056070f` | Selected input bridge name; converts screen coordinates, dispatches active-part behavior, and calls `UpdateFromDrag` at `0x005606ab` and `0x005606d4`. |
| `UpdateFromDrag` | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Exact child at `91/93` and position `180`; uses inherited `m_visibleBounds`, local Y/X and drag-offset Y/X, preserves orientation formulas, and notifies `NewSpellInventoryPane::OnScrollPositionChanged`. |
| `ResetScrollState` | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Exact raw source-bearing helper at `93/94`, position `190`. It removes timers, clears active state, conditionally invalidates the old hover part, and clears hover. Zero direct caller/VA/RVA/table/vtable routes remain negative evidence for IDA function creation, not a source-emission blocker. |

## Evidence Notes

- IDA MCP confirms constructor, range/position/activation, mouse/repeat, paint, part-rect, and drag-update function boundaries.
- IDA MCP caller check on 2026-05-24 shows the constructor `0x0055f450` is only directly called from `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`.
- IDA MCP lookup confirms the activation helper `0x0055f5f0` as a real `0x1a`-byte function.
- IDA reports no function at `0x005608a0`; previous modeled function is `0x00560710-0x0056089d`, and raw disassembly shows method-shaped reset code through `0x005608fc` before the next function at `0x00560900`. Treat the reset-helper function-table mismatch as data debt.
- IDA-backed allocation and constructor evidence records the same `0x110` scrollbar tail field pattern as the item-inventory scrollbar; see [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md).
- 2026-05-26 IDA MCP confirms vtable bases `0x00623e94`, `0x00623ee0`, and `0x00623f10`, with paint, mouse, and repeat slots mapped in [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md).
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) gives the file-level container a reviewed `90/92` score and the same projected `NexusTK/ui/inventory/` path used by the surrounding [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) module.
- 2026-06-11 IDA MCP refresh reconfirms exact function inventory from `0x0055f450` through `0x0056089d`, including one direct constructor caller at `0x0057d013`, range/current/activation helpers at `0x0055f560`, `0x0055f5c0`, and `0x0055f5f0`, vtable-slot handlers at `0x0055f650`, `0x0055f850`, and `0x0055f890`, and part/drag helpers at `0x00560290` and `0x00560710`.
- 2026-06-11 IDA MCP refresh also reconfirms `0x005608a0` is not an IDA-defined function but is method-shaped raw reset code ending before `0x005608fc`/padding and the next neighboring scrollbar constructor at `0x00560900`. The reset page's no-route caveat remains evidence and a score cap; it no longer blocks the class declaration or the already accepted bounded reset body.
- The aggregate, layout, and vtable support pages are nonreconstructable/no-emitter evidence with blank formals. Nineteen exact method children emit every authored body; UID0001GN emits at position 180 and UID0001GO at 190. Compiler vtables/RTTI are regenerated from this declaration and never duplicated as literal source.
- 2026-06-16 A002 live IDA MCP recheck on session `b001_mappane_0001AW_20260616` reconfirmed constructor `0x0055f450` (`0xa1` bytes), range/current/activate helpers, mouse/repeat/paint helpers, geometry `0x00560290`, drag updater `0x00560710`, raw non-function starts `0x00560520`, `0x00560590`, and `0x005608a0`, and successor `0x00560900`. Xrefs still show the sole constructor caller at `0x0057d013`, range/position/activate callers in `NewSpellInventoryPane`, zero xrefs to raw reset `0x005608a0`, and vtable base stores to `0x00623e94`, `0x00623ee0`, and `0x00623f10` at `0x0055f4a1`, `0x0055f4a7`, and `0x0055f4b1`. Raw bytes at `0x0056089d` show `cc cc cc 55 8b ec 83 ec`, and bytes at `0x005608f8` show `8b e5 5d c3 cc cc cc cc`, confirming padding before and after the raw reset body.
- 2026-06-18 B002 recheck for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md): local PE scan of `NexusTK.exe` confirmed exact raw boundary `0x005608a0-0x005608fb`, padding before `0x00560900`, zero VA/RVA literal references to `0x005608a0`, zero direct branch/call edges to the start, and zero external direct branches into the span. Positive controls for nearby modeled helpers and vtable entries resolved, so the no-route finding is meaningful. The helper remains a class method by field/helper/vtable semantics, with file [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) as route and [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) rejected as direct owner.
- 2026-06-20 B002 aggregate source-quality incorporation for [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md): current-session MCP was unavailable, but local PE/listing checks corroborated the aggregate boundary, the predecessor byte `0x0055f44f-0x0055f450`, the internal `0xcc` padding, the successor bytes `0x005608fc-0x00560900`, the modeled function run, raw setter pockets `0x0055f500` and `0x0055f530`, raw disable/predicate pockets `0x0055f610` and `0x0055f630`, and raw hover/active/reset pockets `0x00560520`, `0x00560590`, and `0x005608a0`. Direct rel32/VA/RVA scan again found no static route for representative raw starts while positive controls for `0x00560710`, `0x00560290`, and `0x00560650` resolved. These facts make the aggregate a class method inventory owned by this class, not a monolithic method body.
- B001 MCP session `9b0396a3` resolved [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) as an exact `0x18d`-byte member with two caller sites, fixed Y/X field mapping, accepted helper and callback names, and standalone class/file placement. The callback `0x0057d360` has three xrefs and synchronizes the child, rebuilds rows, and invalidates on change.

## Source Declaration And Inheritance Decision

- Direct source inheritance is only `Pane`. The observed adjusted EventHandler and TimerHandler views at `+0xa0/+0xa4` are inherited Pane facets, not additional direct bases.
- The four class-specific source virtuals are `OnPaint`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `OnTimer`. Their declarations let the compiler regenerate the primary/secondary/tertiary vtables; literal vtable arrays are rejected.
- Natural layout from the `Pane` base places `m_sizeIndex` at `+0xf8`, `m_scrollStyle` at `+0xfa`, `m_thumbDragActive` at `+0xfb`, `m_orientation` at `+0xfc`, `m_scrollPosition` at `+0xfe`, `m_scrollRange` at `+0x100`, `m_enabled` at `+0x102`, `m_hoverPart` at `+0x103`, `m_activePart` at `+0x104`, and `Point m_thumbDragOffset` at `+0x108/+0x10c`, for exact size `0x110`.
- Project `Point` order is Y then X: `+0x108 = m_thumbDragOffset.y` and `+0x10c = .x`. The previous opposite mapping is superseded.
- `ScrollSpellInventoryPane.cpp` is selected over the historical NewSpell fold and generic ScrollBar placement. Constructor-only feature containment is weaker than the independent class receiver, fields, vtables, layout, method island, and current file root.

## Parent And Score Rationale

| Item | Score | Relevance |
| --- | ---: | --- |
| [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) | `90/92` | Current parent: complete dedicated source root, exact nineteen-method split, CPP/H, layout/vtable/dependency routes, and rejected historical NewSpell fold. |
| [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) | `86/88` | Confirms the broader `ui/inventory/` ownership and the spell-inventory/new-spell split that hosts this scrollbar. |
| [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) | `91/93` | Complete non-emitting aggregate confirms all nineteen child ranges/hashes, constructor caller, vtable stores, fields, seven raw methods, sixteen padding spans, and successor exclusion. |
| [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | `93/94` | Exact reset behavior, raw span/hash, class owner/emitter route, source-facing fields/helpers, rejected hidden routes, enum-shaped CPP, and position 190; no modeled start/caller route remains an IDA confidence cap. |
| [UID:00026D][0x00623d58-0x00624184.ScrollPaneReadOnlyData](by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md) | `82/86` | Places the `ScrollSpellInventoryPane` RTTI/vtable band between neighboring scroll-pane families, matching the three vtable bases documented by the vtable page. |

The class is `89/91`. Its complete declaration, standalone source route, inherited facets, natural tail layout, virtual map, nineteen exact children, full CPP/H, and non-emitting support dispositions are applied and generated. The score remains below final-audit territory because stripped original spellings and historical physical-file capitalization cannot be proven, not because any source/emitter decision remains deferred.

## Cross-References

- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:00026D][0x00623d58-0x00624184.ScrollPaneReadOnlyData](by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/78`.
  - Before: The page was unevaluated despite documenting the spell-inventory scrollbar methods, caller, layout, vtables, and reset-helper mismatch.
  - After: Scored as high completion with medium-high confidence because scrollbar behavior is strong, while one raw reset-helper boundary and source placement remain unresolved.
  - Evidence: Existing method notes, IDA caller/evidence notes, layout/vtable references, and NewSpellInventoryPane relationship support the score.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: The class page documented project-owned behavior but had no validator reconstructable flag.
  - Changed to: The page is flagged as rebuild-owned while `AUTOGEN_PARENT_UID` and C++ remain blank.
  - Historical evidence, superseded for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) by the 2026-06-18 B002 source-quality pass: IDA MCP confirmed `NewSpellInventoryPane::NewSpellInventoryPane` allocates a 0x110-byte pane, calls the `0x0055f450` constructor, and owns the spell-inventory scrollbar; final source-file placement and source-quality C++ were then treated as below the 95+ gate.
- 2026-06-07: Raised confidence from `78` to `80` and attached the class to [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md).
  - Before: The class had 80 completion but stayed below the attachment confidence gate, and the matching file page also sat at 78 confidence.
  - Changed to: `AUTOGEN_PARENT_UID` is now `0000NJ`, with added parent/score rationale explaining the file attachment, raw reset-helper caveat, and why by-memory children and final C++ are not changed here.
  - Evidence: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) records the dedicated `ui/inventory/` spell-scrollbar source hypothesis, [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) corroborates module placement, [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) records caller/layout/vtable evidence, and [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) preserves the reset-helper provenance cap.
- 2026-06-07 A001 class evidence refresh:
  - Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
  - Summary/evidence: added a lifecycle summary spanning construction, range/position updates, input/repeat handling, paint/part-rect layout, and hover/reset cleanup; linked the shared scroll-pane read-only-data band for the spell-scrollbar vtables; removed stale recovered-file wording; kept the parent attachment and blank final C++ because the raw reset helper and standalone-vs-folded source split still cap final-source confidence.
- 2026-06-11 A005 parent-gate refresh:
  - Before: completion/confidence were `82/82`; the class had strong behavior evidence but did not clear the strict direct-parent side of the 85/85 gate for [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md).
  - Changed to: completion `85`, confidence `85`; retained `AUTOGEN_PARENT_UID:0000NJ` and blank final C++.
  - Evidence: live IDA MCP reconfirmed exact method boundaries, the sole constructor caller from `NewSpellInventoryPane`, the `0x110` allocation/layout, vtable bases, range/current/activation/paint/part/drag offset usage, and the raw reset-helper boundary before `0x00560900`.
- 2026-06-16 A002 class-confidence refresh:
  - Changed from `85/85` to `86/88`, retaining owner/emitter [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md).
  - Evidence: live IDA MCP reconfirmed the method inventory, sole `NewSpellInventoryPane` constructor caller, range/current/activate caller routes, geometry/drag helper graph, raw hover/reset non-function starts, zero raw reset xrefs, vtable stores, and reset-helper padding. Remaining blockers are the real source-quality limits: standalone `ScrollSpellInventoryPane.cpp` versus private fold into `NewSpellInventoryPane.cpp`, raw helper declaration names, and final scrollbar field names.
- 2026-06-18 B002 support incorporation:
  - Updated the reset-method row, lifecycle text, evidence notes, and child score table for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md).
  - Evidence: B002 resolved the raw reset helper's source-facing name/signature, class owner/emitter, `+0xa4` TimerHandler view, `m_hoverPart`/`m_activePart` fields, `GetPartRect` and Pane invalidation roles, no VA/RVA/direct/table/vtable route finding, and first-draft C++ readiness. The class page remains non-emitting class support while the child emits the exact method body.
- 2026-06-20 B002 aggregate Rule 26 support incorporation:
  - Added raw setter, disable/predicate, false-return virtual, hit-test, active/begin-interaction, and input-bridge method inventory from [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md), and updated the child score table for the aggregate's `86/88` state.
  - Evidence: B002 local PE/listing pass confirmed exact padding, raw-pocket endpoints, no static route for representative raw starts, positive-control route checks, layout fields including unresolved `+0xfa`, and the target-specific no-monolithic-C++ proof. Class declaration C++ remains a separate support decision until inherited interface, field, and source-file organization questions are ready.
- 2026-07-22 B001 UID0001GN implementation callback:
  - Retained `86/88` and the [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) owner/emitter route, set position `10`, and inserted the accepted `Pane`-derived class declaration, selected method/virtual names, natural tail fields, `0x110` size guard, and `[[CHILDREN]]` source route.
  - Resolved prior class-declaration, inherited-interface, Y/X field, standalone-file, and support-marker decisions while preserving all constructor, method-family, raw-pocket, no-route, layout, vtable, and historical score evidence.
