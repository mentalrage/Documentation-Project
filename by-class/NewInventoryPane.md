*** UID:000093 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "NewInventoryPane.h"
#include "InventoryScrollPane.h"
#include "../MainUiGraph.h"
#include "../controls/HelpPanes.h"
#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../dialogs/ItemActionInputPanes.h"
#include "../panels/UserPane.h"
#include "../panels/UserStatusPane.h"
#include "../../config/Config.h"
#include "../../map/BackPane.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/ItemObjImageLib.h"
#include "../../render/Surface.h"

#include <cwchar>

namespace
{
    const int kInventorySlotCount = 52;
    const int kCollapsedGridRows = 5;
    const int kExpandedGridRows = 9;
    const int kCollapsedListRows = 13;
    const int kExpandedListRows = 26;

    bool GetButtonRect(short part, RectBounds *bounds);
    short HitTestButton(int localY, int localX);
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_INVENTORY_NEWINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_NEWINVENTORYPANE_H

#include "../core/PanelPane.h"

class Event;
class Layer;
class ScrollInventoryPane;

class NewInventoryPane : public PanelPane
{
public:
    NewInventoryPane();
    virtual ~NewInventoryPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(RectBounds *bounds,
                           const RectBounds *previousBounds);
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
    enum InventoryViewMode
    {
        kInventoryViewList = 0,
        kInventoryViewGrid = 1
    };

    void RebuildInventoryList();
    static void __stdcall SendUseItemSlotPacket(unsigned char slot);
    static void __stdcall SendDropItemPacket(unsigned char slot);
    static void __stdcall SendItemToObjectPacket(
        unsigned char slot, unsigned int objectId);
    bool BuildInventorySlotRect(int cell, RectBounds *bounds) const;
    int HitTestInventorySlot(int localX, int localY) const;
    int ResolveVisibleInventorySlot(short visibleOrdinal) const;
    static void __stdcall SendSwapItemPacket(
        signed char destinationSlot, signed char sourceSlot);
    Point *BuildInventorySlotOrigin(Point *origin,
                                    unsigned short cell) const;
    void StopActiveRepeatTimer();
    void ToggleExpandedMode();

    signed char m_scrollPosition;
    unsigned char m_inventoryListCount;
    unsigned char m_reservedFA[2];
    InventoryViewMode m_viewMode;
    int m_unusedState;
    int m_listButtonState;
    int m_gridButtonState;
    int m_expandButtonState;
    int m_actionButtonState;
    ScrollInventoryPane *m_scrollPane;
    unsigned char m_visibleInventorySlots[53];
    signed char m_hoverInventorySlot;
    signed char m_selectedInventorySlot;
    unsigned char m_reserved14F;
    int m_activeRepeatTimer;
    bool m_draggedSincePress;
    bool m_expanded;
    unsigned char m_tailPadding[2];
};

typedef char NewInventoryPane_size_must_be_0x158[
    sizeof(NewInventoryPane) == 0x158 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewInventoryPane
## Current Exact Class Contract - 2026-08-16

- Exact object size: `0x158`; [UID:00054F][NewInventoryPaneLayout](by-type/by-struct/NewInventoryPaneLayout.md) records every offset and width without duplicating class emission.
- Direct file owner/emitter: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). The CPP channel supplies only includes, constants, file-local helper declarations, and `[[CHILDREN]]`; the 26 exact children own all method/helper bodies.
- Three inheritance views are represented by compiler RTTI/vtable storage [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md). No explicit vptr/vtable source object is emitted.
- The header uses source-facing fields at `+0xf8..+0x157`, preserves unknown storage as `m_unusedState`, and declares four private static `__stdcall` packet serializers. It does not retain decompiler `_DWORD`, adjusted-base, raw-offset, or reserve-array substitutes for proven roles.
- InventoryScrollPane remains separate. Exact friendship permits this class to synchronize the companion's private scroll range/position without publicizing fields or inventing getters.

## Exact Child Definitions

| Position | Child | Source identity | Role |
| ---: | --- | --- | --- |
| 10 | [UID:00053P][0x004eb420-0x004eb510.NewInventoryPaneConstructor](by-memory/0x004eb420-0x004eb510.NewInventoryPaneConstructor.md) | `NewInventoryPane` | constructor |
| 20 | [UID:00053Q][0x004eb510-0x004eb545.NewInventoryPaneDestructor](by-memory/0x004eb510-0x004eb545.NewInventoryPaneDestructor.md) | `~NewInventoryPane` | ordinary destructor |
| 30 | [UID:00053R][0x004eb550-0x004eb567.NewInventoryPaneOnActivate](by-memory/0x004eb550-0x004eb567.NewInventoryPaneOnActivate.md) | `OnActivate` | activation override |
| 40 | [UID:00053S][0x004eb580-0x004eb608.NewInventoryPaneUpdateRenderRegion](by-memory/0x004eb580-0x004eb608.NewInventoryPaneUpdateRenderRegion.md) | `UpdateRenderRegion` | render-region override |
| 50 | [UID:00053T][0x004eb610-0x004eb6b5.NewInventoryPaneSetBounds](by-memory/0x004eb610-0x004eb6b5.NewInventoryPaneSetBounds.md) | `SetBounds` | fixed bounds override |
| 60 | [UID:00053U][0x004eb6c0-0x004eb9f9.NewInventoryPaneRebuildInventoryList](by-memory/0x004eb6c0-0x004eb9f9.NewInventoryPaneRebuildInventoryList.md) | `RebuildInventoryList` | visible-slot and scroll synchronization |
| 70 | [UID:00053V][0x004eba00-0x004eba8d.NewInventoryPaneOnScrollPositionChanged](by-memory/0x004eba00-0x004eba8d.NewInventoryPaneOnScrollPositionChanged.md) | `OnScrollPositionChanged` | scrollbar callback |
| 80 | [UID:00053W][0x004eba90-0x004ebaf6.NewInventoryPaneAddToLayer](by-memory/0x004eba90-0x004ebaf6.NewInventoryPaneAddToLayer.md) | `AddToLayer` | layer insertion override |
| 90 | [UID:00053X][0x004ebb00-0x004ebb16.NewInventoryPaneRemoveFromLayer](by-memory/0x004ebb00-0x004ebb16.NewInventoryPaneRemoveFromLayer.md) | `RemoveFromLayer` | layer removal override |
| 100 | [UID:00053Y][0x004ebb20-0x004ec913.NewInventoryPaneOnPaint](by-memory/0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md) | `OnPaint` | complete renderer |
| 110 | [UID:00053Z][0x004ec920-0x004ecb44.NewInventoryPaneHandleKeyOrTextEvent](by-memory/0x004ec920-0x004ecb44.NewInventoryPaneHandleKeyOrTextEvent.md) | `HandleKeyOrTextEvent` | key/text override |
| 120 | [UID:000540][0x004ecb50-0x004ed9c4.NewInventoryPaneHandlePointerOrMouseEvent](by-memory/0x004ecb50-0x004ed9c4.NewInventoryPaneHandlePointerOrMouseEvent.md) | `HandlePointerOrMouseEvent` | complete pointer/mouse state machine |
| 130 | [UID:000541][0x004ed9f0-0x004edb62.NewInventoryPaneHandlePacketEvent](by-memory/0x004ed9f0-0x004edb62.NewInventoryPaneHandlePacketEvent.md) | `HandlePacketEvent` | packet/help override |
| 140 | [UID:000542][0x004edb70-0x004edcc5.NewInventoryPaneOnTimer](by-memory/0x004edb70-0x004edcc5.NewInventoryPaneOnTimer.md) | `OnTimer` | repeat timer override |
| 150 | [UID:000543][0x004edcd0-0x004edd39.NewInventoryPaneSendUseItemSlotPacket](by-memory/0x004edcd0-0x004edd39.NewInventoryPaneSendUseItemSlotPacket.md) | `SendUseItemSlotPacket` | private static packet helper |
| 160 | [UID:000544][0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket](by-memory/0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket.md) | `SendDropItemPacket` | private static packet helper |
| 170 | [UID:000545][0x004eddd0-0x004ede74.NewInventoryPaneSendItemToObjectPacket](by-memory/0x004eddd0-0x004ede74.NewInventoryPaneSendItemToObjectPacket.md) | `SendItemToObjectPacket` | private static retained packet helper |
| 180 | [UID:000546][0x004edfb0-0x004ee080.NewInventoryPaneGetButtonRect](by-memory/0x004edfb0-0x004ee080.NewInventoryPaneGetButtonRect.md) | `GetButtonRect` | file-local geometry helper |
| 190 | [UID:000547][0x004ee0a0-0x004ee13c.NewInventoryPaneBuildInventorySlotRect](by-memory/0x004ee0a0-0x004ee13c.NewInventoryPaneBuildInventorySlotRect.md) | `BuildInventorySlotRect` | private geometry member |
| 200 | [UID:000548][0x004ee140-0x004ee20b.NewInventoryPaneHitTestButton](by-memory/0x004ee140-0x004ee20b.NewInventoryPaneHitTestButton.md) | `HitTestButton` | file-local hit-test helper |
| 210 | [UID:000549][0x004ee230-0x004ee3b7.NewInventoryPaneHitTestInventorySlot](by-memory/0x004ee230-0x004ee3b7.NewInventoryPaneHitTestInventorySlot.md) | `HitTestInventorySlot` | private hit-test member |
| 220 | [UID:00054A][0x004ee3c0-0x004ee464.NewInventoryPaneResolveVisibleInventorySlot](by-memory/0x004ee3c0-0x004ee464.NewInventoryPaneResolveVisibleInventorySlot.md) | `ResolveVisibleInventorySlot` | private one-based slot mapper |
| 230 | [UID:00054B][0x004ee470-0x004ee4ee.NewInventoryPaneSendSwapItemPacket](by-memory/0x004ee470-0x004ee4ee.NewInventoryPaneSendSwapItemPacket.md) | `SendSwapItemPacket` | private static packet helper |
| 240 | [UID:00054C][0x004ee4f0-0x004ee56f.NewInventoryPaneBuildInventorySlotOrigin](by-memory/0x004ee4f0-0x004ee56f.NewInventoryPaneBuildInventorySlotOrigin.md) | `BuildInventorySlotOrigin` | private point helper |
| 250 | [UID:00054D][0x004ee570-0x004ee595.NewInventoryPaneStopActiveRepeatTimer](by-memory/0x004ee570-0x004ee595.NewInventoryPaneStopActiveRepeatTimer.md) | `StopActiveRepeatTimer` | private timer helper |
| 260 | [UID:00054E][0x004ee5a0-0x004ee643.NewInventoryPaneToggleExpandedMode](by-memory/0x004ee5a0-0x004ee643.NewInventoryPaneToggleExpandedMode.md) | `ToggleExpandedMode` | private relayout helper |

## Current Behavior And Layout

- Lifecycle creates/enables and deletes the owned scrollbar.
- Layout fixes collapsed/expanded rectangles and synchronizes child bounds.
- Slot state scans one-based inventory records, keeps the one-based active map, and implements exact list/grid pagination.
- Paint/input preserve exact shared resource literals, geometry, hotkeys, quantities, button states, drag/drop/swap/use/help/wheel/repeat behavior, and the observed expanded-list hit-test quirk.
- Packet helpers preserve opcode `0x1c`, `0x08`, `0x66`, and `0x30` payloads and gates. The uncalled item-to-object body remains source-authored but receives no speculative call.

## Current Score Rationale

- Completion `94`: exact class declaration, full child inventory, formal source/header channels, support declarations, friends, and compiler/data exclusions are complete.
- Confidence `95`: allocator size, constructor writes, cross-method offsets, three vtable views, boundaries, callers/callees, and source order agree. Final lexical and compile/layout readback retain the cap.

## Historical Assumptions Preserved

Older reserve-only names, broad method-family rows, scrollbar-fold uncertainty, exact-child backlog, and empty CPP rationale are superseded. The dated text below is retained as provenance rather than current authority.

## Historical Status Before Exact Class Closure

- Confidence: strong for behavior, inventory-module placement, companion scrollbar relationship, and vtable/resource-data relationship; medium for final field names, exact child method splits, and source-quality class declaration.
- Likely source file: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md), under the [UID:0000KA][InventoryPane](by-file/InventoryPane.md) umbrella
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewInventoryPane.cpp`

## Historical Autogen Status

- Reconstructable: true; this is NexusTK-owned source class code and should be rebuilt as part of the item-inventory UI.
- Autogen parent: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). The file page now has a projected `NexusTK/ui/inventory/` path and records the same IDA-backed constructor, paint, input, scrollbar, and vtable/resource evidence.
- C++ emission: the formal H channel now owns the complete normal `NewInventoryPane.h` declaration, including the `0x158` size guard and `OnScrollPositionChanged` callback required by InventoryScrollPane. Method definitions remain owned by exact children through UID0000LS; this page does not emit ScrollInventoryPane definitions.

## Class Purpose

`NewInventoryPane` is the newer player item inventory pane. It owns a pointer to one [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), builds filtered visible slot lists, supports list/grid layouts, paints item icons/names/counts/tab buttons, and handles hover, drag/drop, right-click context, scroll wheel, and view-mode toggling.

B006 resolves the item-slot record dependency as [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). This class consumes `LocalInventorySlotRecord` fields for visible-slot filtering and rendering, while `LivingObjectPane` owns the local-player storage accessor.

## Source Ownership

Attach this class to [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) is the finalized standalone source root for the companion scrollbar; this class consumes it but does not own its definitions.

Do not infer final ownership from the broad [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) aggregate alone. That range physically interleaves legacy inventory code, `NewInventoryPane`, `InventoryPane2`, and three BackPane help-packet helpers; the class/file child pages are the source-layout authority for this pane.

## ScrollInventoryPane Relationship

- `NewInventoryPane` stores `ScrollInventoryPane *m_scrollInventoryPane` at `+0x114`. Its constructor allocates `0x110` bytes for that object, calls `ScrollInventoryPane::ScrollInventoryPane` at `0x004eb4e4`, and retains the returned pointer.
- `NewInventoryPane::OnScrollPositionChanged` at `0x004eba00` is the source-facing callback used by `ScrollInventoryPane::UpdatePositionFromCursor(int localY, int localX)` when the signed scroll position changes. The callback receives orientation, old position, and new position and synchronizes the inventory view.
- The pointer/callback relation is consumer ownership only. ScrollInventoryPane's declaration and 19 definitions remain in standalone `InventoryScrollPane.h/.cpp`; they must not be duplicated or folded into this class's formal channels.
- Historical documentation that called the scrollbar embedded or treated a private fold as unresolved is superseded by the exact pointer field, constructor allocation, callback route, complete method island, and dedicated source root.

## Historical Partial Header Layout Contract

- The `PanelPane` base occupies `[+0x000,+0x0f8)`. The declaration fixes view mode at `+0xfc`, four button-state dwords at `+0x104..+0x110`, the `ScrollInventoryPane *` at `+0x114`, 53 visible-slot bytes at `+0x118..+0x14c`, interaction bytes at `+0x14d/+0x14e`, timer state at `+0x150`, and booleans at `+0x154/+0x155`.
- No audited method references the four bytes at `+0x100`; `m_unusedState` is intentionally conservative human-source vocabulary rather than invented behavior. This unresolved original member spelling is retained as a confidence cap.
- The complete declaration is the natural NewInventoryPane.h owner. A reduced callback shim would discard class/layout evidence and is rejected; ScrollInventoryPane only includes this header to invoke the callback.

## Historical Broad Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle/layout | `NewInventoryPane`, `OnRefresh`, `OnResize`, `OnLayout`, `OnShow`, `ScalarDeletingDestructor` | Creates child scrollbar and keeps layout/visibility synchronized. |
| Slot model | `RebuildSlotList`, `TransformCoordinates`, `MapVisualToPhysicalSlot`, `HitTestSlot` | Maps visible slots to physical inventory slots and supports list/grid layouts. |
| Rendering | `OnPaint`, `GetButtonRect`, `GetSlotRect` | Draws slots, item icons, text, counts, and tab buttons. |
| Input | `OnKeyEvent`, `OnMouseEvent`, `OnScrollPositionChanged`, `ScrollToDirection` | Handles keyboard paging, mouse interactions, scrollbar sync, and repeat scrolling. |
| Audio/view mode | `StopSound`, `ToggleViewMode` | Stops item sound and toggles list/grid display. |

## Evidence Notes

- IDA MCP confirms `0x004eb420-0x004eb510`, `0x004ebb20-0x004ec913`, `0x004ecb50-0x004ed9c4`, and `0x004ee230-0x004ee3b7`.
- Wave3 notes describe a 344-byte `PanelPane`-derived object with scrollbar pointer at `0x114`, slot-map array around `0x118-0x14c`, hover slot at `0x14d`, and compact/expanded toggle byte around `0x155`.
- The class remains incomplete in Wave3 due to low automated grade, so method names are useful but not final for rename-heavy work.
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records the exact inventory-pane function inventory, keeps BackPane packet helpers out of this class, and assigns the `0x004eb420-0x004ee595` subrange to `NewInventoryPane`.
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) records that `NewInventoryPane::NewInventoryPane` is the only observed direct constructor caller for the owned scrollbar pane.
- [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md) records the exact `NewInventoryPane` RTTI/vtable island, including locator cells at `0x0061c7e0`, `0x0061c830`, and `0x0061c860` plus vtable bases at `0x0061c7e4`, `0x0061c834`, and `0x0061c864`.
- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) now records the current source-split decision: keep `NewInventoryPane.cpp` as the primary root, keep `InventoryScrollPane.cpp` as a private companion root for now, and avoid treating interleaved BackPane helper children as inventory-owned source.
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) records the complete companion scrollbar island, exact children, standalone source route, and constructor/callback relation to this class.
- 2026-06-11 A002 Batch216 live IDA MCP reconfirmed the constructor, paint, input, layout/helper, and scalar deleting destructor anchors at `0x004eb420`, `0x004ebb20`, `0x004ecb50`, `0x004edb70`, and `0x004efb50`; the one direct `ScrollInventoryPane` constructor caller at `0x004eb4e4`; and the three `NewInventoryPane` vtable store/restore xref sets at `0x004eb45c/462/46c`, `0x004eb519/51f/529`, and `0x004efb5c/562/56c`.
- Fresh IDA MCP was unavailable on 2026-06-03, and `wave3.py inspect class NewInventoryPane` timed out. The score update is based on already written IDA-backed documentation, not new Wave3 output.

## Historical Score Rationale

| Field | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | Purpose, method families, source placement, owned scrollbar relationship, aggregate boundaries, exact vtable child [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md), current source split, complete 0x158 formal H, and callback declaration are documented. Completion remains capped by broader unsplit method children and unresolved exact names outside this callback. |
| Confidence | `86` | Multiple IDA-backed pages agree on constructor/paint/input/helper ranges, source folder, companion scrollbar relationship, exact header offsets and locator-backed vtable data. Confidence remains below final-audit quality because some method/member spellings, especially the unused `+0x100` dword, remain inferred; the scrollbar split and callback declaration are resolved. |

## Cross-References

- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md)
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)

## Changes

- 2026-08-15 B005 UID0000KB support callback: preserved `85/86`, documented `ScrollInventoryPane *m_scrollInventoryPane` at `+0x114` and `NewInventoryPane::OnScrollPositionChanged` at `0x004eba00`, and finalized this class as consumer/instance owner rather than source owner of standalone `InventoryScrollPane.cpp/.h`.
- 2026-08-15 B005 source-contract callback: installed the complete normal `NewInventoryPane.h` declaration, exact `0x158` size guard, natural layout, and `OnScrollPositionChanged(unsigned char, short, short)` declaration. The conservative `m_unusedState` name records the unreferenced `+0x100` dword without inventing behavior; score remains `85/86` for the broader class pass.

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the local inventory slot record dependency for visible-slot filtering/rendering and kept accessor ownership with `LivingObjectPane`.
- Before: completion/confidence metadata were `0/0` while the page already summarized class purpose, major method families, evidence, and cross-references.
- Changed to: `COMPLETION:72` and `CONFIDENCE:74`.
- Evidence: behavior, embedded scrollbar ownership, visible-slot model, rendering, input, and field-offset leads are documented; confidence remains medium because final method names, full field layout, and exact source split are not fully resolved.
- 2026-06-03 confidence and autogen pass:
  - Before: the page was scored `72/74` with blank reconstructable and parent metadata.
  - Changed to: `76/80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LS`, while leaving C++ blank.
  - Evidence: the [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) aggregate, [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md), and [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) support the class owner, source file, companion scrollbar, and vtable data; exact field names and final class declaration are still not source-emission ready.
- 2026-06-07 A006 source-ownership refresh:
  - Before: the page recorded the class purpose and owned scrollbar relationship, but did not explicitly route source ownership through the strengthened `NewInventoryPane.cpp` / `InventoryScrollPane.cpp` split guidance.
  - Changed to: score `80/82`, source ownership section, updated score rationale, and cross-reference to the companion `InventoryScrollPane` file.
  - Evidence: existing UID-linked documentation records the `0x004eb420-0x004ee595` executable subrange, `0x004efb50-0x004efbb7` destructor, one-caller scrollbar constructor relationship, corrected `NewInventoryPane` vtable addresses, and the mixed aggregate caveat that keeps BackPane helpers out of this class.
- 2026-06-11 A002 Batch216 parent-gate repair:
  - Before: score `80/82`, below the strict gate for assigning exact vtable-data child [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md).
  - Changed to: score `85/86`.
  - Evidence: live IDA MCP reconfirmed representative method boundaries, one-caller scrollbar construction, locator/vtable boundaries, and vtable store/restore xrefs. Final C++ stays blank because field names and exact method child pages remain incomplete.
