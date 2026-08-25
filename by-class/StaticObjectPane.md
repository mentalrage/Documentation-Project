*** UID:0000E1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "StaticObjectPane.h"
#include "../util/PoolAllocator.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_STATICOBJECTPANE_H
#define NEXUSTK_MAP_STATICOBJECTPANE_H

#include "ObjectPane.h"

class PaneEvent;
struct Rect;
struct StaticObjectDrawRequest;

class StaticObjectPane : public ObjectPane
{
public:
    StaticObjectPane(int tileX, int tileY, unsigned short staticObjectId);
    virtual ~StaticObjectPane() {}

    bool HitTestStaticObjectPixel(int localX, int localY) const;
    virtual Rect *CopyStaticObjectBounds(Rect *scratch, Rect *out) const;
    virtual bool RenderStaticObjectForTarget(
        int renderMode,
        StaticObjectDrawRequest *request);
    virtual bool HandleStaticObjectEvent(const PaneEvent *event);

    unsigned short GetStaticObjectId() const
    {
        return m_staticObjectId;
    }

private:
    void SendInteractionPacket();
    unsigned short m_staticObjectId;
};

typedef char StaticObjectPaneSizeMustBe0x12c[
    sizeof(StaticObjectPane) == 0x12c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete 0x12c ObjectPane-derived StaticObjectPane declaration with constructor, inline virtual source destructor, hit-test/bounds/render/event methods, private packet helper, inline static-object-id accessor over the exact +0x128 field, class-before-children order, complete child route, and compiler-generated three-view vtable/scalar-delete/pool mechanics excluded. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# StaticObjectPane

## Status

- Confidence: very strong for inheritance, exact `0x12c` layout, constructor and method set, three virtual views, `+0x128` unsigned 16-bit id, inline accessor, source destructor cause, child order, and compiler/source separation; private spellings cap confidence at `92`.
- Likely source file: [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_StaticObjectPane.cpp`
- Vtable/RTTI child: [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md)

## Class Purpose

`StaticObjectPane` is the map-object wrapper for static map props. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores `m_staticObjectId` at the first subclass field area, asks [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) for bounds/render/hit-test behavior, and emits a static-object interaction packet when a click lands in the active static-object rectangle.

The complete source-era declaration now lives in the guarded H formal block, while CPP includes `StaticObjectPane.h` before namespace-scope method children. The inherited `ObjectPane` portion occupies `0x000-0x127`; `unsigned short m_staticObjectId` occupies `+0x128-+0x129`; natural tail alignment occupies `+0x12a-+0x12b`; total size is exactly `0x12c`. No raw padding member is required. [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) consumes the natural inline `GetStaticObjectId()` accessor instead of private field offsets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `StaticObjectPane::StaticObjectPane(int tileX, int tileY, uint16_t staticObjectId)` | `0x00537900-0x00537947` | Builds an `ObjectPane` with object type `5`, stores `m_staticObjectId`, and installs all three vtable views. |
| `HitTestStaticObjectPixel` | `0x00537950-0x00537970` | Calls `g_pStaticObjImageLib` with `m_staticObjectId` and caller-supplied local pixel coordinates; omitted from older generated output. |
| `CopyStaticObjectBounds` | `0x00537970-0x00537999` | Gets static-object bounds from `g_pStaticObjImageLib` and copies the four-word rectangle out. |
| `RenderStaticObjectForTarget` | `0x005379a0-0x005379cc` | Forwards rendering to the static-object image library. |
| `HandleStaticObjectEvent` | `0x005379d0-0x00537abf` | Checks click/event type, verifies bounds, and sends a static-object interaction packet. |
| [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) | `0x00537ac0-0x00537b39` | Retained private no-argument `SendInteractionPacket()` helper; no direct static callers are known, but first-draft C++ is justified because the source-authored packet-send body is exact. |
| [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md) | `0x0053d740-0x0053d7bd` | Destroys `ObjectPane` and optionally releases the object through the StaticObjectPane pool. |
| [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md) | `0x00620340-0x006203ec` | Compiler-emitted RTTI/vtable child for the primary and two adjusted `StaticObjectPane` views. |

The source destructor is the inline virtual `~StaticObjectPane() {}` declaration. The out-of-line scalar deleting body, two adjustors, vptr stores, explicit base teardown, scalar flag, and pool free are MSVC-generated ABI/lowering consequences and remain on compiler/no-code support pages rather than handwritten class source.

## Owned Static Data

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) | `0x0069b8bc-0x0069b8e4`, constructor wrapper `0x0041a160`, cleanup wrapper `0x0060c3b0`, allocation/free xrefs `0x0050f086`, `0x00514d05`, `0x0053d776` | Class-owned file-scope static object pool declaration emitted through this class route as `static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);`. The numeric constants preserve the direct wrapper values; exact original spelling/linkage remain inferred. |

## Evidence Notes

- IDA caller xrefs show construction from the map object creation path at `0x0050f030`.
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) is the exact ObjectList consumer of the H contract: it compares `m_staticObjectId`, invalidates matching panes, reads their attached `LightingObjectPane`, and removes, updates, or creates lighting according to `StaticObjEntry::lightImageIndex`.
- The class-owned static pool at [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) is the allocation source for the map object creation path and the free target for constructor-failure and scalar-deleting-destructor paths. B002 current MCP evidence used session `b001-0002wl-readonly`, confirmed writable `.data` zero-filled storage, raw operand label `unk_69B8BC`, wrapper constants `0x12c` / `300` and `0x10` / `16`, and the direct xrefs `0x0041a167`, `0x0050f086`, `0x00514d05`, `0x0053d776`, and `0x0060c3b0`.
- Vtable/data xrefs reference the virtual methods at `0x00537970`, `0x005379a0`, `0x005379d0`, and the scalar deleting destructor at `0x0053d740`.
- 2026-06-11 IDA refresh confirms exact scalar deleting destructor child [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md) at `0x0053d740-0x0053d7bd`, with adjustor refs `0x0053cf8e`/`0x0053cf99`, primary vtable ref `0x00620344`, base cleanup `0x005373a0`, and StaticObjectPane pool free through `0x004b14c0`.
- 2026-06-12 A005 Batch259 live IDA MCP reconfirmed exact vtable child [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md): RTTI dword targets `??_R4StaticObjectPane@@6B@`, `??_R4StaticObjectPane@@6B@_0`, and `??_R4StaticObjectPane@@6B@_1`; vtable bases `??_7StaticObjectPane@@6B@`, `_0`, and `_1`; constructor stores at `0x00537926`, `0x0053792c`, and `0x00537936`; destructor/adjustor targets `0x0053d740`, `0x0053cf88`, and `0x0053cf93`; and successor boundary `0x006203ec -> ??_R4ItemObjectPane@@6B@`.
- 2026-06-21 B006 Rule 26 incorporation resolves the separate helper at [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) as private non-virtual `StaticObjectPane::SendInteractionPacket()`. It sends opcode `0x43`, subcommand `0x03`, inherited `m_tileX`/`m_tileY`, and a zero flag as a length-7 payload through the packet sender. IDA still has no function record or direct static caller for `0x00537ac0`, and the vtable/data reference at `0x006203b8` still points to the checked virtual handler at `0x005379d0`, not this helper.
- 2026-06-28 B006 current MCP recheck keeps [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md) as class-owned generated-binary output covered by this class declaration. Active session `agent_b009_0002my_20260628` reported server health OK and reconfirmed `0x00620340 -> ??_R4StaticObjectPane@@6B@`, vtable bases `0x00620344`, `0x006203b4`, and `0x006203e4`, constructor stores at `0x00537926`, `0x0053792c`, and `0x00537936`, destructor/adjustor slot targets `0x0053d740`, `0x0053cf88`, and `0x0053cf93`, method slot refs through `0x00620394`, `0x006203a0`, and `0x006203b8`, and the excluded `ItemObjectPane` successor RTTI at `0x006203ec`. UID00034X therefore emits only a covered-by marker; the compiler regenerates the RTTI/vtable data from the class layout and virtual method set.
- The active source currently omits `0x00537950` and emits no body for `0x005379d0`; use the memory doc before migration.
- 2026-06-17 B003 source-quality reanalysis resolves the old helper/field caveats for [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md): `0x00537950` is best named `HitTestStaticObjectPixel`, `+0x100/+0x104` are inherited ObjectPane tile coordinate fields, `+0x128` is `m_staticObjectId`, packet words are tile coordinates, and raw caller `0x0050c691` belongs to a MapPane-owned helper inside `0x0050c5e0-0x0050c6da`.
- B003 live MCP session `64c11373` reconfirmed that constructor input and all image-library consumers treat `+0x128` as the unsigned 16-bit static-object id; target UID0003TJ compares that value against the six-byte map-tile output. The complete declaration therefore closes access without friendship or raw offset use.
- Source/compiler negative evidence rejects handwritten vptr assignment, raw RTTI/vtable arrays, adjustor bodies, deleting-destructor flags, explicit `ObjectPane` destructor calls, pool free, constructor EH cleanup, cookies, and raw layout filler. Those artifacts are regenerated from the declaration and exact child definitions.

## Cross-References

- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md)
- [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md)
- [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md)
- [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)

## Changes

- 2026-08-11 B003 UID00023D support synchronization: preserved `90/92`, owner/emitter `0000O6`, reconstructable true, blank position, and all method/pool/vtable evidence. Moved the complete class declaration and size assertion into guarded H, reduced CPP to `StaticObjectPane.h` plus `[[CHILDREN]]`, and documented the exact ObjectList lighting-refresh consumer.
- 2026-07-15 B003 UID0003TJ support callback: raised `86/88` to `90/92`, retained the UID0000O6 owner/emitter route and blank position, installed the complete class declaration with class close before `[[CHILDREN]]`, added the inline unsigned-short id accessor and exact `0x12c` layout proof, and preserved every method/static-pool/vtable/destructor/helper fact. The existing compiler children remain no-code and no raw compiler data was added.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `86`.
- Evidence: the page documents map-object role, constructor/helper/render/event/packet/destructor ranges, caller and vtable evidence, generated omissions, and packet helper ownership; remaining completion gap is source-ready field naming and C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, hit-test helper, bounds copy, render, event handler, and scalar deleting destructor at `0x00537900`, `0x00537950`, `0x00537970`, `0x005379a0`, `0x005379d0`, and `0x0053d740`; `0x00537ac0` remains a raw/not-modeled helper as documented. Both class (`84/86`) and parent file (`82/86`) meet the 80/80 gate.
- 2026-06-11 A008 Batch 171: Raised completion/confidence from `84/86` to `85/87` after exact scalar destructor child [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md) split and live IDA confirmation of destructor boundary, vtable/adjustor refs, base cleanup, and pool-free behavior. Direct parent/file gate now clears `85/85`.
- 2026-06-12 A005 Batch259: Raised completion/confidence from `85/87` to `86/88` after live IDA reconfirmed exact vtable/RTTI child [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md), including all three constructor vptr stores, destructor/adjustor targets, and the `ItemObjectPane` successor boundary. This class now directly supports assigning the vtable child under the strict `85/85` gate.
- 2026-06-17 B003 support refresh: updated method names and field semantics after [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md) source-quality execution; canonical static-object image dependency is `g_pStaticObjImageLib`, not stale generated `g_pStaticObjectManager` wording.
- 2026-06-21 B006 Rule 26 support sync: changed [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) from prior no-code/raw-start wording to a retained private `SendInteractionPacket()` helper with first-draft C++ in the child memory doc. The remaining no-caller/no-IDA-function state is a confidence cap, not a reason to omit the source-shaped body.
- 2026-06-28 B006 vtable marker support sync: preserved current MCP evidence for [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md), including all three constructor vptr stores, destructor/adjustor targets, method slot refs, and the `ItemObjectPane` successor boundary. UID00034X remains class-owned `source-declared/generated-binary` data and should emit only a covered-by marker from the `StaticObjectPane` declaration.
- 2026-07-09 B002 static-pool support sync: added [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) as class-owned static data with the first-draft declaration `static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);`; broad class behavior and method evidence remain unchanged.
