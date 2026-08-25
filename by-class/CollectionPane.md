*** UID:00002X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "CollectionPane.h"
#include "ScrollCollectionPane.h"
#include "UserPane.h"
#include "../core/Event.h"

#include "../../config/Config.h"
#include "../../metadata/MetaMan.h"
#include "../../metadata/MetaTable.h"
#include "../../render/ImageLib.h"
#include "../../render/PaletteLib.h"
#include "../../render/Surface.h"

#include <cwchar>
#include <stdlib.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/PanelPane.h"

class Event;
class Layer;
class MetaTable;
class ScrollCollectionPane;
struct CollectionGroupRecord;

class CollectionPane : public PanelPane
{
public:
    CollectionPane();
    virtual ~CollectionPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void LoadCollectionGroupRecords(CollectionGroupRecord *group);
    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition, short newPosition);

private:
    void UpdateScrollRange();
    void SetInvalidGroupSlotRect(unsigned short visibleSlot,
                                 RectBounds *outBounds);
    void GetVisibleGroupSlotRect(unsigned short visibleSlot,
                                 RectBounds *outBounds);
    short HitTestVisibleGroupSlot(int y, int x);
    void OpenOrRequestGroupDetail(int groupIndex);

    int m_groupCount;
    MetaTable *m_collectionsTable;
    MetaTable *m_groupNamesTable;
    signed char m_firstVisibleGroup;
    signed char m_groupCountSnapshot;
    ScrollCollectionPane *m_scrollPane;
};

typedef char CollectionPaneSizeMustBe0x10C[
    sizeof(CollectionPane) == 0x10C ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CollectionPane

## Status

- Likely source file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Address range: [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), vtable data [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md), plus destructor [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_CollectionPane.cpp`
- Confidence: very strong for class responsibility, vtable/destructor ownership, direct file parent, exact split children, and current best source-facing helper names.

## Class Purpose

`CollectionPane` is the in-game collection summary panel. It loads `Collections` and `GroupNames` metadata, stores group records in the player-data collection block, renders five visible group rows with completion counts, owns a `ScrollCollectionPane` child, and dispatches clicks to the detailed collection dialog/request path.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionPane` | [UID:0003Y1][0x0056e940-0x0056e9e2.CollectionPaneConstructor](by-memory/0x0056e940-0x0056e9e2.CollectionPaneConstructor.md) | Constructs `PanelPane`, installs three vtable views, creates/enables the `ScrollCollectionPane` child at `+0x108`, and initializes visible-start state. |
| `~CollectionPane` body | [UID:0003Y2][0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor](by-memory/0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor.md) | Raw no-function ordinary destructor body; restores vtables, releases the scroll child, and tail-jumps to `PanelPane` cleanup. |
| `OnActivate(const unsigned char *packetData)`; behavior alias `InitializeCollectionData` | [UID:0003Y3][0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData](by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md) | Primary `+0x48` activation override. Consumes packet data, uses UID0003F1 `Collections` twice and `GroupNames` twice, populates typed group records, refreshes scroll range, and invalidates. |
| `UpdateRenderRegion` | [UID:0003Y4][0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion](by-memory/0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md) | Emits the complete body: retains the local bounds initialization, places the scroll child at `{right-20, top+27, right-7, bottom-21}`, chains `Pane::UpdateRenderRegion`, and refreshes scroll range. |
| `UpdateScrollRange` | [UID:0003Y5][0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange](by-memory/0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md) | Emits the complete body: snapshots group count, clamps range/position to signed `0..30000`, avoids redundant child setters, and synchronizes first-visible state. |
| `OnPaint` | [UID:0003Y6][0x0056edc0-0x0056f655.CollectionPaneOnPaint](by-memory/0x0056edc0-0x0056f655.CollectionPaneOnPaint.md) | Uses seven UID0003F1 literals to draw `CLTINV`/`CLTLIST` frames, resolve group names/fallback text, and format completion percentages and fractions. |
| `HandleKeyOrTextEvent` | [UID:0003Y7][0x0056f660-0x0056f665.CollectionPaneFalseStubA](by-memory/0x0056f660-0x0056f665.CollectionPaneFalseStubA.md) | Emits the exact five-byte-equivalent false-return secondary `EventHandler` key/text override at vtable slot `0x00624638`; historical `VirtualFalseStubA` is a behavior alias only. |
| `HandlePointerOrMouseEvent` | [UID:0003Y8][0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent](by-memory/0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md) | Emits the complete secondary `EventHandler` pointer/mouse override: input lock, wheel clamp/update, configured click dispatch, and coordinate-safe scroll-child forwarding. The physical `this - 0xa0` facet is compiler adjustment; historical `OnInputEvent` is a behavior alias. |
| `HandlePacketEvent` | [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) | Secondary `EventHandler` packet-event false-return override at vtable slot `0x00624640` / offset `+0x10`; `EventDispatcher::CallHandler` routes exact packet event type `18` to this slot, and the body ignores the `Event *` and returns false. |
| `LoadCollectionGroupRecords` | [UID:0003Y9][0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords](by-memory/0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md) | Copies collection item metadata from `MetaMan` into group records and uses UID0003F1 `Collections` exactly twice for metadata key/index access. |
| `OnScrollPositionChanged` | [UID:0003YA][0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged](by-memory/0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md) | Emits the complete unchanged-position guard, state synchronization, range refresh, and invalidation body while retaining the ABI orientation argument. |
| `AddToLayer` | [UID:0003YB][0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer](by-memory/0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md) | Emits exact inherited override `AddToLayer(RectBounds *, int, Pane *, Layer *)`: base-first attachment, child screen-bounds attachment, and range refresh. `AttachToLayer` remains a behavior description only. |
| `RemoveFromLayer` | [UID:0003YC][0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer](by-memory/0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md) | Emits exact inherited override `RemoveFromLayer()` with child-first then `Pane`-base removal. `DetachFromLayer` remains a behavior description only. |
| `SetInvalidGroupSlotRect` | [UID:0003YD][0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw](by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md) | Emits the complete bounded raw helper that ignores the slot and writes `RectBounds(-1,-1,-1,-1)`; missing modeled-function/xref state remains a confidence cap. |
| `GetVisibleGroupSlotRect` | [UID:0003YE][0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw](by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md) | Emits the complete bounded raw helper mapping slots `0..4` to `{6,14+50*n,161,62+50*n}` and invalid slots to four `-1` fields. |
| `HitTestVisibleGroupSlot` | [UID:0003YF][0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot](by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md) | Emits the complete five-row y/x hit-test loop and returns a 16-bit slot or `-1`. |
| `OpenOrRequestGroupDetail` | [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) | Reads the `g_pUserPane` collection group view at `groupIndex * 0x2604`, loaded flag `+0x3ec8`, and volume/type byte `+0x3ec9`; if missing, sends exact request bytes `0x27, 0, 1, groupVolumeId` with length `4` and a local-only terminator, otherwise opens `CollectionDialogPane(nullptr, groupVolumeId)`. The exact child now emits first-draft C++. |
| `~CollectionPane` | [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md) | Deletes the scroll child, chains to `PanelPane`, and optionally frees storage; scalar wrapper is now split from the neighboring mixed destructor island. |

## Class-Owned Read-Only Data

| Range | Role | Evidence |
| --- | --- | --- |
| [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md) | Complete-object-locator and three-view vtable group for this class; compiler-covered marker only, never a hand-authored object. | Live IDA sees primary, secondary, and tertiary table bases at `0x006245e0`, `0x00624630`, and `0x00624660`; constructor stores occur at `0x0056e97c`, `0x0056e982`, and `0x0056e98c`, with matching scalar deleting destructor stores at `0x0057337c`, `0x00573382`, and `0x0057338c`. The complete declaration and ordinary definitions regenerate the exact compiler data. |

## Data And Globals

- Uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) for group/entry records.
- Uses [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) for `Collections` and `GroupNames` lookups.
- Uses [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) through `OpenOrRequestGroupDetail`'s singleton gate before constructing `CollectionDialogPane(nullptr, groupVolumeId)`.
- Uses [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) through `OpenOrRequestGroupDetail`'s missing-data request packet: opcode `0x27`, bytes `0`, `1`, and the group volume/type byte, sent with explicit length `4`.
- Uses `g_pConfig + 0x28de5a` to select alternate click behavior.
- Best current field names: `+0xf8` group count, `+0xfc` `Collections` table, `+0x100` `GroupNames` table, `+0x104` visible start/scroll position, `+0x105` visible/total group-count snapshot, and `+0x108` scroll child.
- Best current player-data view names consumed by this class: `+0x1340c8` collection group count, `+0x1340c9` collection metadata loaded flag, group `+0x3ec8` loaded flag, group `+0x3ec9` group volume/type byte, group `+0x3eca` total entries, and group `+0x3ecb` collected entries.
- 2026-06-11 live IDA MCP reconfirmed constructor caller `0x004b851f`, modeled helper starts including `0x0056fc80`, and scalar deleting destructor vtable/thunk refs at `0x006245e0`, `0x00573263`, and `0x0057326e`.
- 2026-06-12 Agent-A004 live IDA MCP reconfirmed the class-owned [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md) span: `0x006245dc -> ??_R4CollectionPane@@6B@`, `0x006245e0 -> 0x00573370`, `0x00624630 -> 0x0057325d`, and `0x00624660 -> 0x00573268`.
- 2026-06-12 Agent-A001 live IDA MCP reconfirmed [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) as a class-owned virtual false stub: body bytes `32 C0 C2 04 00`, decompile `return 0`, no callers/callees, vtable slot bytes at `0x00624640` resolving to `0x0056f800`, and `0xcc` padding on both sides.
- 2026-06-25 B002 implementation callback resolves that slot's source-facing role: `0x00624640` is the secondary `EventHandler` offset `+0x10`, and `EventDispatcher::CallHandler` routes `Event::IsPacketEvent()` records, exact event type `18`, to offset `+0x10`. [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) now carries first-draft `CollectionPane::HandlePacketEvent(Event *event)` C++ for the false-return packet-event override.
- 2026-07-13 B004 UID00015Y callback resolves `0x0056ea30` as the class's primary `+0x48` implementation of the common `OnActivate(const unsigned char *packetData)` contract. Unlike several sibling panels, CollectionPane consumes the packet pointer. `InitializeCollectionData` remains the precise behavior alias for its typed collection-data work rather than a different base-slot signature.

## Source-Quality Findings

- `0x0056f800` and `0x0056fc80` are no longer open Wave3 omissions: [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) and [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) are exact class-owned children. [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) is specifically the secondary `HandlePacketEvent` false-return override, not an unidentified inherited slot. [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) now emits first-draft `CollectionPane::OpenOrRequestGroupDetail(int groupIndex)` C++ with constants for `0x2604`, `+0x3ec8`, and `+0x3ec9`.
- The `OpenOrRequestGroupDetail` source-quality blocker is closed for first-draft emission: current evidence supports the accepted `g_pUserPane` collection group view, `PacketBufferWriteUInt8`, `g_packetSender->QueueAndSendPacket(packet, 4)`, `g_pCollectionDialogPane`, and `CollectionDialogPane(nullptr, groupVolumeId)` names. Rejected source shapes are `CollectionDialogPane` ownership, a free helper, broad aggregate emission through [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), and any packet body that sends `groupIndex` rather than `groupVolumeId`.
- `ScrollCollectionPane` remains a dependency, not a `CollectionPane.cpp` ownership target; current evidence favors the generic scroll-control route.
- Formal source is now complete at first-draft quality: the CPP channel is the sole file-root include/`[[CHILDREN]]` aggregator, directly includes `../core/Event.h` and `../../config/Config.h` for the input body, and the H channel is one guarded 17-member `0x10c` declaration. `PanelPane.h` supplies inherited pane/rectangle contracts; pointer-only collaborators are forward-declared; UID0001TZ H supplies complete record definitions where method bodies need them. All ten formerly placeholder children emit complete bodies. UID00038U emits only its inert compiler-covered marker while compiler vtables/adjustors/scalar wrappers remain non-emitting objects.
- The only cross-class access support is `friend class CollectionPane;` in the existing complete ScrollCollectionPane declaration. It permits the directly evidenced `m_scrollPosition` and `m_scrollRange` reads in `UpdateScrollRange` and `HandlePointerOrMouseEvent`; no accessor, field, storage, layout, or source-owner change is introduced.

## UID0003F1 Literal Uses

The main class owns 13 of the 14 direct refs into [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md); CollectionPane2 owns the remaining shared `CLTINV.EPF` use. The physical pool remains file-owned because it crosses those classes.

| Method | Count | Exact operands and source role |
| --- | ---: | --- |
| `OnActivate` / `InitializeCollectionData` | 4 | `Collections` at `0x0056ea80` and `0x0056ead3`; `GroupNames` at `0x0056eae8` and `0x0056eb3b`; constructs and resolves the two metadata tables. |
| `OnPaint` | 7 | `CLTINV.EPF` `0x0056ee4c`; `CLTLIST.EPF` `0x0056ef6b`; `CLTLIST.PAL` `0x0056ef77`; `GroupNames` `0x0056f04a`; Korean fallback `L"\xC548\xB098\xC640"` `0x0056f1a9`; `L"%d %%"` `0x0056f3b1`; `L"%d/%d"` `0x0056f4b6`. |
| `LoadCollectionGroupRecords` | 2 | `Collections` at `0x0056f8cc` and `0x0056f966` for metadata key/index work while filling one typed group record. |

These are repeated use-site literals, not a named class array, table, member, or global. The target's four-line covered-by marker is emitted through file UID0000IC, formal H gains no resource declaration, and this evidence does not claim that the three independently scoped method bodies are otherwise complete.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md)
- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)
- [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md)
- [UID:0003Y2][0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor](by-memory/0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor.md)
- [UID:0003YD][0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw](by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md)
- [UID:0003YE][0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw](by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md)
- [UID:0003YF][0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot](by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md)
- [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md)
- [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md)
- [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA completion callback: raised `92/93 -> 94/94`, added only the direct Event/Config dependencies, incorporated complete CPP for UID0003Y4/Y5/Y7/Y8/YA/YB/YC/YD/YE/YF, and closed their blank-H/class-owned routes. UID00038U remains compiler-covered rather than hand-authored, and the narrowly supported ScrollCollectionPane friend route preserves both class layouts.
- 2026-08-16 Agent-B008 UID0003FA accepted callback: raised `89/90 -> 92/93`, inserted the sole dependency-closed file-root CPP aggregator and complete guarded `0x10c` H declaration, preserved `int m_groupCount` and natural alignment, and closed all 17 lifecycle/render/layer/input/packet/scroll/load/rectangle/detail members. The preamble directly includes `MetaTable.h` because OnActivate and the loader call public table methods while `MetaMan.h` correctly keeps only a pointer-level forward declaration. UID0003Y6 emits at position `70` and UID0003FA at `75`; `VirtualFalseStubA`, `OnInputEvent`, `AttachToLayer`, and `DetachFromLayer` are historical behavior aliases rather than current source names.
- 2026-08-15 Agent-B002 UID0003F1 accepted callback: mapped all 13 CollectionPane literal uses across OnActivate, OnPaint, and LoadCollectionGroupRecords while preserving the class's `89/90` score and independently scoped formal-source state.
- 2026-07-13 B004 UID00015Y accepted callback: score remains `89/90`; recorded UID0003Y3 as the pointer-consuming common `OnActivate` override while retaining `InitializeCollectionData` as its behavior alias, preserving the typed collection layout, all exact child identities/bodies, and the blank class formal block.
- 2026-06-12 Agent-A001 Goal 2:
  - Kept score `87/88`.
  - Updated the `HandleInput` end-exclusive boundary from `0x0056f7f3` to `0x0056f7f4` after live IDA MCP reported `sub_56F670` size `0x184` and disassembly showed `retn 4` ending at `0x0056f7f3`.
  - Recorded class ownership evidence for [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md), supporting its direct parent route to this class.
- 2026-06-12 Agent-A004 Batch 262: Raised from `85/86` to `87/88`.
  - Before: the class was just above the direct-parent gate for destructor ownership but did not explicitly own the exact `CollectionPane` vtable child.
  - After: added class-owned read-only data for [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md), refreshed constructor/destructor vtable-store evidence, and kept direct file parent [UID:0000IC][CollectionPane](by-file/CollectionPane.md).
  - Evidence: live IDA MCP `py_eval` against NexusTK.exe md5 `4247e04e20b65d6414c7238aa8ff5515`; `tools/int_convert.py` verified cited vtable sizes and thunk offsets.
- 2026-06-17 B001 report execution: Raised from `87/88` to `89/90`.
  - Added exact split children for the constructor/destructor, metadata loader, layout/scroll/paint/input methods, raw rectangle helpers, and hit-test path; recorded best current field/layout names and resolved the stale Wave3 omission note for `0x0056f800` and `0x0056fc80`.
  - Formal C++ remains deferred by class/interface/layout declaration readiness, not by unexplored naming/ownership questions.
- 2026-06-25 B002 implementation callback:
  - Score unchanged at `89/90`.
  - Updated [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) from a generic `VirtualFalseStub` row to `HandlePacketEvent`, the secondary `EventHandler` packet-event false-return override at `0x00624640` / offset `+0x10`.
  - Evidence: current MCP `CollectionPane` secondary vtable bytes and `EventDispatcher::CallHandler` routing show exact event type `18` dispatches to handler offset `+0x10`; the child body remains no-caller/no-callee/no-state and returns false.
- 2026-06-27 B002 implementation callback:
  - Score unchanged at `89/90`.
  - Recorded that [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) now emits first-draft `CollectionPane::OpenOrRequestGroupDetail(int groupIndex)` C++ through this class route.
  - Evidence: accepted MCP session `80de0a67` reconfirmed the sole input-handler caller at `0x0056f7a7`, group stride `0x2604`, loaded flag `+0x3ec8`, volume/type byte `+0x3ec9`, request bytes `0x27,0,1,groupVolumeId` with send length `4`, and loaded branch constructor `CollectionDialogPane(nullptr, groupVolumeId)`.
- 2026-06-11 Agent-A001 Batch 186 continuation: Raised from `82/84` to `85/86`.
  - Before: the class page was below the strict direct-parent gate and pointed the destructor at the mixed destructor island.
  - After: linked exact child [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md), refreshed live caller/destructor evidence, and kept direct file parent [UID:0000IC][CollectionPane](by-file/CollectionPane.md), now `87/86`.
  - Evidence: live IDA MCP `lookup_funcs`, `callers`, `xrefs_to`, and destructor decompile/callee evidence from 2026-06-11.
- Before: the destructor was listed as `0x00573370-0x005733d6`, leaving the exact IDA function end and adjustor thunks outside the class-level references.
- Changed to: the destructor endpoint is corrected to `0x005733d7`, and the collection adjustor/destructor memory pages are now cross-referenced.
- Evidence: 2026-05-28 IDA MCP reports `sub_573370` as `0x00573370-0x005733d7`, with `0x0057325d` and `0x00573268` as `-0xa0`/`-0xa4` adjustor thunks into it.
- What existed before: the page documented the collection summary panel, metadata loading, scroll behavior, draw path, omitted helper caveats, and destructor correction, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/84`.
- Summary and evidence at that time: constructor, initialization, scroll calculations, painting, hit-testing, detail request/opening, globals, and destructor island were covered; later 2026-06-17 B001 execution resolved the Wave3 omission and helper ownership/layout notes above.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IC][CollectionPane](by-file/CollectionPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IC`.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0056e940`, `0x0056ea30`, `0x0056edc0`, `0x0056f810`, `0x0056fc80`, and `0x00573370`, with a constructor caller from `GeneralPurposePanel` at `0x004b851f`; this class and the parent file both meet the 80% completion/confidence attachment gate.
