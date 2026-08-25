*** UID:00009A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "NewSpellInventoryPane.h"
#include "ScrollSpellInventoryPane.h"
#include "../MainUiGraph.h"
#include "../controls/HelpPanes.h"
#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../dialogs/SpellInputPanes.h"
#include "../dialogs/TargetSelectionInputPanes.h"
#include "../panels/UserPane.h"
#include "../../config/Config.h"
#include "../../map/BackPane.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../map/ObjectPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

#include <cwchar>

namespace
{
    const int kSpellSlotCount = 52;
    const int kCollapsedRowCount = 13;
    const int kExpandedRowCount = 26;

    void SendSwapSpellPacket(unsigned char fromSlot, unsigned char toSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    bool GetButtonRect(short part, RectBounds *bounds);
    short HitTestButton(int localX, int localY);
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_INVENTORY_NEWSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_NEWSPELLINVENTORYPANE_H

#include "../core/PanelPane.h"

class Event;
class Layer;
class ScrollSpellInventoryPane;

class NewSpellInventoryPane : public PanelPane
{
public:
    NewSpellInventoryPane();
    virtual ~NewSpellInventoryPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(RectBounds *bounds, const RectBounds *parentBounds);
    virtual void AddToLayer(const RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *activationData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnTimer(int timerId, int elapsed, int userData);

    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition, short newPosition);

private:
    void RebuildSpellList();
    void ActivateSpellSlot(int spellSlot);
    bool BuildSpellRowRect(int row, RectBounds *bounds) const;
    int HitTestSpellRow(int localX, int localY) const;
    int ResolveVisibleSpellSlot(short visibleOrdinal) const;
    void BuildSpellRowOrigin(Point *origin, int row) const;
    void StopActiveRepeatTimer();
    void ToggleExpandedMode();

    signed char m_scrollPosition;
    unsigned char m_spellListCount;
    bool m_spellInputActive;
    unsigned char m_reservedFB[5];
    ScrollSpellInventoryPane *m_scrollPane;
    unsigned char m_visibleSpellSlots[53];
    signed char m_hoverSpellSlot;
    signed char m_selectedSpellSlot;
    unsigned char m_reserved13B;
    int m_activeRepeatTimer;
    int m_expandButtonState;
    bool m_expanded;
    bool m_draggedSincePress;
    unsigned char m_tailPadding[2];
};

typedef char NewSpellInventoryPane_size_must_be_0x148[
    sizeof(NewSpellInventoryPane) == 0x148 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewSpellInventoryPane
## UID0000LU Complete Class And Child Inventory - 2026-08-15

NewSpellInventoryPane is a complete `ui/inventory/` source route with one class owner, the allocator-proven UID000534 layout comment at position 5, and the following 25 exact source definitions. The by-file and broad-core formal channels stay blank; UID00009A owns the preamble/H declaration and each exact child owns one CPP definition.

| Position | Exact child | Range | Source disposition |
| ---: | --- | --- | --- |
| 10 | [UID:00052F][0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor](by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md) | `[0x0057cf70,0x0057d03f)` | source-authored recognized function; formal CPP child, blank H |
| 20 | [UID:00052G][0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor](by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md) | `[0x0057d040,0x0057d075)` | source-authored raw code item; formal CPP child, blank H |
| 30 | [UID:00052H][0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate](by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md) | `[0x0057d080,0x0057d097)` | source-authored recognized function; formal CPP child, blank H |
| 40 | [UID:00052I][0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion](by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md) | `[0x0057d0c0,0x0057d148)` | source-authored recognized function; formal CPP child, blank H |
| 50 | [UID:00052J][0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds](by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md) | `[0x0057d150,0x0057d1f5)` | source-authored recognized function; formal CPP child, blank H |
| 60 | [UID:00052K][0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList](by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md) | `[0x0057d200,0x0057d360)` | source-authored recognized function; formal CPP child, blank H |
| 70 | [UID:00052L][0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged](by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md) | `[0x0057d360,0x0057d398)` | source-authored recognized function; formal CPP child, blank H |
| 80 | [UID:00052M][0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer](by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md) | `[0x0057d3a0,0x0057d406)` | source-authored recognized function; formal CPP child, blank H |
| 90 | [UID:00052N][0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer](by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md) | `[0x0057d410,0x0057d426)` | source-authored recognized function; formal CPP child, blank H |
| 100 | [UID:00052O][0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint](by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md) | `[0x0057d430,0x0057d8c4)` | source-authored recognized function; formal CPP child, blank H |
| 110 | [UID:00052P][0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent](by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md) | `[0x0057d8d0,0x0057d9b1)` | source-authored recognized function; formal CPP child, blank H |
| 120 | [UID:00052Q][0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent](by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md) | `[0x0057d9c0,0x0057e18f)` | source-authored recognized function; formal CPP child, blank H |
| 130 | [UID:00052R][0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent](by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md) | `[0x0057e1b0,0x0057e1d8)` | source-authored recognized function; formal CPP child, blank H |
| 140 | [UID:00052S][0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer](by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md) | `[0x0057e1e0,0x0057e2c1)` | source-authored recognized function; formal CPP child, blank H |
| 150 | [UID:00052T][0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot](by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md) | `[0x0057e2d0,0x0057e56d)` | source-authored recognized function; formal CPP child, blank H |
| 160 | [UID:00052U][0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket](by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md) | `[0x0057e5a0,0x0057e615)` | source-authored raw code item; formal CPP child, blank H |
| 170 | [UID:00052V][0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket](by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md) | `[0x0057e620,0x0057e689)` | source-authored recognized function; formal CPP child, blank H |
| 180 | [UID:00052W][0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect](by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md) | `[0x0057e690,0x0057e6e7)` | source-authored recognized function; formal CPP child, blank H |
| 190 | [UID:00052X][0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect](by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md) | `[0x0057e6f0,0x0057e75a)` | source-authored raw code item; formal CPP child, blank H |
| 200 | [UID:00052Y][0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton](by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md) | `[0x0057e760,0x0057e7f4)` | source-authored raw code item; formal CPP child, blank H |
| 210 | [UID:00052Z][0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow](by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md) | `[0x0057e800,0x0057e8c8)` | source-authored recognized function; formal CPP child, blank H |
| 220 | [UID:000530][0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot](by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md) | `[0x0057e8d0,0x0057e955)` | source-authored recognized function; formal CPP child, blank H |
| 230 | [UID:000531][0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin](by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md) | `[0x0057e960,0x0057e99a)` | source-authored raw code item; formal CPP child, blank H |
| 240 | [UID:000532][0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer](by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md) | `[0x0057e9a0,0x0057e9c5)` | source-authored recognized function; formal CPP child, blank H |
| 250 | [UID:000533][0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode](by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md) | `[0x0057e9d0,0x0057ea57)` | source-authored recognized function; formal CPP child, blank H |

### Mixed-Range Exclusions

- Foreign `[0x0057d0a0,0x0057d0b0)` remains UID0001IJ TargetSelectionInputPanes source and is not a NewSpell child.
- Disconnected `nullsub_54 [0x0057d0b0,0x0057d0b1)` is an ownerless one-byte `ret` with zero incoming/outgoing edges, no pointer/vtable route, no source declaration, no child, and no emitter.
- Exact one-byte padding `[0x0057e18f,0x0057e190)` separates UID00052Q from switch table `[0x0057e190,0x0057e1b0)`. That byte, the second switch table `[0x0057e570,0x0057e594)`, the complete 27 documented pre/internal/post alignment spans, vtable cluster, scalar-deleting wrapper, two adjustor thunks, and three EH/cookie records remain compiler/data artifacts with no handwritten body.
- UID0002RL owns compiler wrappers only; UID00026J preserves the 35-dword NewSpell vtable cluster; UID0003BX preserves resource literals. None emits NewSpell handwritten source.

### Behavior And Dependency Closure

The source covers construction/destruction, activation and layout, child Scroll attachment, learned/expanded row rebuilding, painting, key/pointer/packet/timer handling, slot activation, packet sends, hit testing, row geometry, repeat-timer cleanup, and expanded-mode relayout. UID0000CN remains a separate ScrollSpellInventoryPane translation unit with a normal H declaration and NewSpell friendship.

Direct owner headers now supply UserPane record access by friendship, all spell-input and SpellWho declarations, WillBeChangedSpellPane, the targeted-action packet helper, signed `g_activeDialogCount`, `g_activeMapPane`, the complete LivingObjectPane declaration, and BackPane/`g_pBackPane`. SpellInputPanes includes `InputPanes.h` before deriving any NumberArgs pane, and SpellInputPanes, TargetSelectionInputPanes, MapPane, LivingObjectPane, BackPane, and UserPane each contribute exactly one guard around their assembled header. The NewSpell translation unit's direct UserPane include and indirect re-entry through MapPane are therefore declaration-safe. Report-only wrapper names and duplicate globals are rejected.

### Historical Corrections

The former empty-emitter, source-gate, raw-no-route exclusion, `0x100/+0xfc` layout, and folded-Scroll hypotheses are retained in older history below as superseded assumptions. Current allocation/body/header evidence supports the complete `0x148` standalone implementation.
## UID0000LU Whole-File Implementation - 2026-08-15

This class now owns the complete dependency-closed NewSpellInventoryPane preamble and the sole natural `0x148` header declaration. Its 25 exact by-memory children emit every source-authored definition at positions 10 through 250; the layout page UID000534 emits only a covered-by comment at position 5.

Allocator evidence fixes `PanelPane` storage at `[+0x000,+0x0f8)`, the private Scroll pointer at `+0x100`, visible slots at `+0x104`, and interaction state through `+0x145`. Reserved and tail bytes remain explicit so no unsupported private semantics are invented.

The prior empty formal channels and stale `0x100/+0xfc` projection are historicalized as superseded. Compiler vtable stores, deleting wrappers, switch tables, EH/cookie data, resources, foreign code, `nullsub_54`, and padding remain excluded from handwritten source.

## Historical Pre-Callback Research Snapshot (Superseded 2026-08-15)

Everything from this heading through `## Changes` is preserved as a dated 2026-06-26 pre-callback research snapshot. Present-tense blank/blocked C++, old method and field names, contextual-only raw-body, and score-`85/88` claims in that snapshot are superseded by the accepted whole-file implementation and current synchronization above; they are historical evidence only, not current source or generated-output authority.

- Confidence: strong for behavior, inventory-module placement, child-scrollbar relationship, vtable ownership, visible spell-list rebuild, cast dispatch fanout, exact child-scroll callback ABI/behavior/xrefs, and current file parent; medium-high for exact original field/enum spellings.
- Source file route: [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md), projected as `NexusTK/ui/inventory/NewSpellInventoryPane.cpp`.
- Direct method-island owner/emitter: [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) now attaches directly to this class as `CANONICAL_OWNER:00009A` / `EMITTER_UIDS:00009A`; the by-file page is the route, not the direct memory owner.
- Address range: source-bearing core [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md), with compiler scalar-wrapper refs in [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md). The broad [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) parent is a non-emitting split/index.
- Current recovered file lead: `source-3/simroot_v2/class_NewSpellInventoryPane.cpp`; use it as a lead only, not as authority for final names.

## Class Purpose

`NewSpellInventoryPane` is the newer spell inventory pane. It owns an embedded [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) child pointer at `+0x100`, rebuilds the visible learned-spell list, supports collapsed and expanded row counts, handles hover/drag/quick-cast/swap interactions, forwards adjusted pane-local events to the child scrollbar, and dispatches spell activation to direct packet or spell-specific input-pane flows.

## Autogen And C++ Policy

- Reconstructable: true; this is NexusTK-owned UI source.
- Class owner/emitter route: this class emits through [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).
- [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) direct attachment: the broad core island now directly owns/emits through this class, not through the file page alone.
- Aggregate C++ policy: [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) remains formal-C++ blank despite clearing the active score/emitter gate. It contains 22 IDA functions, switch-support data, raw no-xref helper-shaped blocks, and embedded foreign [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md). Exact method child pages are required before method bodies can be emitted.
- This class page also keeps its formal C++ block blank until the class declaration, fields, method children, and source-shape insertion points are finalized. Do not paste a partial method bundle here to bypass [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md)'s no-code proof.
- Header/declaration visibility requirement: the complete normal `NewSpellInventoryPane` class declaration must expose `void OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition);` to `ScrollSpellInventoryPane.cpp`. Do not create a reduced duplicate `NewSpellInventoryPane` declaration in the ScrollSpell implementation unit. This exact member declaration is accepted even though the full NewSpell class formal remains blocked by the broader unsplit method island.

## Source Ownership

Attach this class to [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) for source-file reconstruction. Keep [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) as the selected standalone companion root. The former fold into `NewSpellInventoryPane.cpp` is retained as rejected historical source-organization evidence; the scrollbar is a companion/private class with its own source file, not a generic scrollbar module and not an independent feature owner.

The broader [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) aggregate is a non-emitting split/index over legacy, new, alternate, embedded shared state-helper, and destructor-tail children. Use exact children for boundaries and output routing; do not treat the aggregate parent as evidence that this class should be folded into the legacy spell inventory source by default.

Rejected owners for [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) remain: [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) as direct memory owner is too coarse; [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) is non-emitting; `ScrollSpellInventoryPane` owns its own scroll methods only; `SpellInputPanes` and `TargetSelectionInputPanes` own prompt panes and [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md), not this dispatcher; `SpellInventoryPane`, `SpellInventoryPane2`, a generic shared spell inventory bucket, and `g_pUserPane` are not supported by the vtable/caller/field evidence as owners for this class.

## Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle/layout | `NewSpellInventoryPane`, `OnRefresh`, `OnResize`, `SetBoundsForMode`, `OnLayout`, `OnHide`, `ScalarDeletingDestructor` | Creates child scrollbar, installs three vtable views, clears row/input/timer state, and keeps collapsed/expanded layout synchronized. |
| Spell list model | `RebuildSpellList`, `ResolveVisibleSpellSlot`, `HitTestSpellRow` | Scans player spell data, maps visible rows to one-based spell slots, syncs scrollbar range/current position, and resolves row hit-tests. |
| Rendering | `OnPaint`, `GetButtonRect` | Draws spell inventory list, selection/hover state, key labels, names, and expand toggle. |
| Input/timers | `OnKeyEvent`, `OnMouseEvent`, `OnTimerEvent`, `OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition)`, `StopActiveRepeatTimer` | Handles page keys, mouse interactions, stale-highlight cleanup, scroll repeat, child-scroll forwarding, and timer cleanup. The scroll callback retains all three ABI parameters even though its body does not consume `orientation`. |

## Scroll Callback Contract

- Exact callback body range: `0x0057d360-0x0057d398`, currently inventoried inside [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md).
- Selected source member: `void OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition)`.
- Callers/xrefs: [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) at `0x00560885`, plus two NewSpell mouse-handler calls at `0x0057da5e` and `0x0057da79`.
- Behavior: when `oldPosition != newPosition`, store the new owner scroll/top-visible byte at `+0xf8`, call child `ScrollSpellInventoryPane::SetScrollPosition` at `0x0055f5c0` through `m_scrollPane`, rebuild visible rows through `RebuildSpellList` at `0x0057d200`, and invalidate through the inherited owner virtual slot `+0x20`. The body performs none of those actions when the values are equal.
- ABI/source decision: `orientation` remains the first parameter because every current caller supplies the same three-argument contract; its non-use in this body does not justify deleting it. Position parameters are signed `short`, matching the child range/position model and caller ABI.
- Source visibility: the declaration belongs in the complete normal NewSpell inventory header/class route exposed to standalone `ScrollSpellInventoryPane.cpp`. It must not be represented by a reduced local class, free-function surrogate, or duplicated callback body.
| Spell activation | `CastSpell`, `SendDirectSpellCastPacket`, `ToggleExpandedMode` | Dispatches spell use, sends direct two-byte spell-cast packets, and toggles expanded display. |

## Field And Data Aliases

Use these source-facing aliases consistently across [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) and this class page:

| Offset | Accepted alias | Evidence and caveat |
| --- | --- | --- |
| `+0xf8` | `m_scrollPosition` / `m_topVisibleIndex` | Written by constructor, list sync, key handling, scroll callback, and expand toggle. |
| `+0xf9` | `m_spellListCount` | `RebuildSpellList` writes learned-count in collapsed mode or 52 in expanded mode. |
| `+0xfa` | `m_pendingSpellInput` | Prompt paths set it, direct-cast paths clear it. Do not reuse [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) `ItemWhoInputPaneState::m_active`; that helper writes the same offset on a different object. |
| `+0x100` | `m_scrollPane` | Pointer to embedded [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) `ScrollSpellInventoryPane`; constructor allocates 272 bytes, stores the pointer, and activates it. |
| `+0x104` | `m_visibleSpellSlots` | Byte array filled with one-based learned spell slot ids. |
| `+0x139` | `m_hoverSpellSlot` | Initialized to `0xff` and used by paint/mouse hover. |
| `+0x13a` | `m_selectedOrDragSpellSlot` | Initialized with `+0x139` and used for selected/drag-source comparisons. |
| `+0x13c` | `m_activeRepeatTimer` | Cleared by `StopActiveRepeatTimer` through `0x00597610`. |
| `+0x140` | `m_expandButtonState` | Drives expand/collapse button frame; toggle writes state 2. |
| `+0x144` | `m_expanded` | Chooses collapsed 13-row mode or expanded 26-row/52-slot behavior. |

Data model names:

- `g_pUserPane` is the accepted name for historical `dword_67A748`; reject `g_pCollectionData`, `g_pSpellMan`, and `SpellManager` here.
- Spell records are one-based at `g_pUserPane + 0x13a6ec + slot * 0x148`; `0x148` is 328 bytes (Verified with int_convert.py). Learned/active byte is record `+0`, route/type dword is record `+4`, and display string is record `+8`. Existing support also records active byte material at `+0x13a834 + slot * 0x148`.
- `Point` storage and helper callsites use y/x ordering in several places, while `RectBounds` remains left/top/right/bottom. Preserve that convention when method C++ is later written.

## Helper And Route Names

Accepted helper names for this class:

- `RebuildSpellList`
- `HitTestSpellRow`
- `ResolveVisibleSpellSlot`
- `CastSpell`
- `SendDirectSpellCastPacket`
- `GetButtonRect`
- `ToggleExpandedMode`
- `StopActiveRepeatTimer`

Spell route names remain descriptive rather than symbol-proven: `StringPrompt`, `TargetPromptOrDirectTargetedAction`, `FourArgsPrompt`, `ThreeArgsPrompt`, `DirectCast`, `TwoArgsPrompt`, `OneArgPrompt`, and `SpellSlotPrompt`. Prompt/helper names should match current support: `SpellStringInputPane`, `SpellWhoInputPane`, `SpellFourArgsInputPane`, `SpellThreeArgsInputPane`, `SpellTwoArgsInputPane`, `SpellOneArgInputPane`, `SpellSlotInputPane`, and `SendTargetedActionPacket`.

## Core Evidence Notes

- [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) covers exact `0x0057cf70-0x0057ea57`. Previous legacy `sub_57CF10` returns at `0x0057cf68`, `0x0057cf6b-0x0057cf70` is pre-target alignment, `0x0057ea57-0x0057ea60` is post-target alignment, and `0x0057ea60` starts [SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) bytes.
- Live IDA reports 22 functions in the target span. Important sizes include constructor `0xcf` / 207 bytes, list helper `0x160` / 352 bytes, paint `0x494` / 1172 bytes, mouse/input `0x7cf` / 1999 bytes, cast dispatcher `0x29d` / 669 bytes, and spell-record stride `0x148` / 328 bytes (Verified with int_convert.py).
- Constructor `0x0057cf70` has one code xref at `0x004b84cb`, installs vtables `0x0062d068`, `0x0062d0b8`, and `0x0062d0e8`, clears key state fields, constructs [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) through `0x0055f450` at `0x0057d013`, and activates it through `0x0055f5f0` at `0x0057d028`.
- B001 MCP session `9b0396a3` reconfirmed callback `0x0057d360` as a `0x38`-byte method and all three xrefs at `0x00560885`, `0x0057da5e`, and `0x0057da79`. Its old/new compare, child position synchronization, row rebuild, and invalidation establish the source-facing `OnScrollPositionChanged` role independently of the ScrollSpell caller.
- Vtable evidence: `0x0062d068 -> 0x0057f5d0` scalar deleting destructor wrapper in [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md); primary entries route to `0x0057d0c0`, `0x0057d150`, `0x0057d3a0`, `0x0057d410`, `0x0057d430`, and `0x0057d080`; secondary/tertiary entries route to `0x0057d9c0`, `0x0057d8d0`, `0x0057e1b0`, and `0x0057e1e0`.
- `RebuildSpellList` scans 52 one-based spell slots, fills `m_visibleSpellSlots`, stores `m_spellListCount`, uses 13 rows collapsed and 26 rows expanded, calls child scroll helpers `0x0055f560` and `0x0055f5c0`, clamps current offset to `0..30000`, and mirrors it to `m_scrollPosition`.
- Paint uses `SPELLINV.EPF` collapsed and table `0x0061c97c` expanded, draws key labels via `SlotIndexToHotkeyLetter` candidate `0x005a4090`, and draws expand/collapse button `[168,37,185,54]`.
- Mouse input calls row hit-test `0x0057e800`, visible-slot resolver `0x0057e8d0`, button rect `0x0057e690`, timer cleanup `0x0057e9a0`, toggle `0x0057e9d0`, drag/selection helper `0x004c7f90`, direct packet helpers `0x00575380`/`0x00574bb0`, cast dispatcher `0x0057e2d0`, and forwards adjusted events to child scroll pane virtual input at `m_scrollPane + 0xa0`.
- Cast dispatcher validates slots `1..52`, branches on record `+4`, allocates prompt panes for cases 0, 1, 2, 3, 5, 6, and 7, uses direct packet helper for cases 4 and 8, and uses switch table support at `0x0057e570-0x0057e594`.
- Raw no-xref helper-shaped blocks at `0x0057d040`, `0x0057e5a0`, `0x0057e6f0`, `0x0057e760`, and `0x0057e960` have no IDA function object and zero incoming xrefs. Keep them as [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) context until future evidence proves callers or pointers.
- [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) `0x0057d0a0-0x0057d0af` has size `0x10`, writes argument byte to `[ecx+0xfa]`, has 17 direct external xrefs from target-selection/spell-input/item-input families, and stays foreign to this class.

## Score Rationale

| Field | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | Purpose, method families, source route, player-spell model, child scrollbar relation, exact scroll callback declaration/behavior/xrefs, aggregate/core/destructor split, vtable ownership, field/helper aliases, and C++ no-code policy are documented. Completion remains below final-source quality because most exact method children and the complete class declaration C++ are not created. |
| Confidence | `88` | Live IDA-backed docs agree on constructor/paint/input/cast boundaries, `ui/inventory/` placement, vtable stores, child scrollbar construction/activation, list rebuild, cast fanout, raw no-xref exclusions, and foreign [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) route. Confidence stays below final audit because some original field/enum spellings remain inferred. |

## Cross-References

- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md)
- [SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md)
- [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md)
- [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed representative newer spell-inventory lifecycle/list/render/input/activation method starts at `0x0057cf70`, `0x0057d430`, `0x0057d9c0`, and `0x0057e2d0`. Left old parent metadata blank because the class was below the attachment gate.
- 2026-06-07 A006 parent attachment and source-ownership pass:
  - Before: reconstructable but parentless.
  - Changed to: `COMPLETION:80`, attached to [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md), added autogen/source ownership sections, score rationale, and blank C++.
- 2026-06-13 Agent-A001 Goal 2 file-quality support pass:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`; parent remains [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).
  - Evidence: [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) live IDA MCP refresh recorded exact method sizes, vtable refs, learned-spell list rebuild, child-scrollbar construction, cast dispatch fanout, and expanded-mode toggle.
- 2026-06-21 Rule 26 B011 parent split/index sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: replaced stale `95+` emission-gate wording with current reconstruction-code gate analysis, while keeping C++ blank for real blockers: broad method island, field/helper names, embedded [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) overlap, and method/source split. The broad [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) parent is non-emitting and should not own this class's output.
- 2026-06-26 Agent-B005 implementation callback for report `0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality.md`:
  - Score unchanged at `85/88`.
  - Summary/evidence: reconciled [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) direct owner/emitter as this class, kept [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) as source-file route, added accepted field/helper aliases, child scrollbar relation, [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) foreign-child exclusion, raw no-xref helper context, method split inventory implications, and aggregate no-code policy.
- 2026-07-22 B001 UID0001GN implementation callback:
  - Retained `85/88` and the UID0000LU route; documented the exact `OnScrollPositionChanged(unsigned char, short, short)` declaration requirement, `0x0057d360-0x0057d398` behavior, all three xrefs, signed position contract, unused-orientation ABI retention, and normal NewSpell header visibility required by standalone `ScrollSpellInventoryPane.cpp`.
  - Preserved the blank full-class formal and UID0002RJ aggregate no-code policy: no reduced duplicate class, free-function surrogate, or aggregate method body was introduced.
