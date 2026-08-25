*** UID:00000M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/PoolAllocator.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_ATTACHEDOBJECTPANE_H
#define NEXUSTK_MAP_ATTACHEDOBJECTPANE_H

#include "ObjectPane.h"

class LivingObjectPane;
struct MapPoint;

class AttachedObjectPane : public ObjectPane
{
public:
    AttachedObjectPane(
        unsigned char objectType,
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX);
    virtual ~AttachedObjectPane();

    LivingObjectPane *GetLivingObjectPane() const;
    int GetLivingObjectId() const;
    void SetLivingObjectPane(LivingObjectPane *pane);
    MapPoint *GetAttachedScreenPosition(MapPoint *outPoint) const;

    virtual void SetSpriteAttribute(unsigned char value);
    virtual void UpdatePosition() = 0;

private:
    LivingObjectPane *m_livingObjectPane; // 0x128
};

typedef char AttachedObjectPaneSizeMustBe300[
    sizeof(AttachedObjectPane) == 0x12c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectPane

## 2026-08-18 Declaration Closure

The complete accepted declaration now emits in formal H, not as a CPP-local class. `MapPoint *GetAttachedScreenPosition(MapPoint *outPoint) const` is inserted after the three established accessors and before the first virtual. Existing constructor/destructor, virtual order, `m_livingObjectPane +0x128`, and `sizeof(AttachedObjectPane) == 0x12c` evidence remain unchanged. Formal CPP is the child-routing marker only; no synthetic resolver field is introduced. Score is `91/93`.

## UID0003TC Shared Virtual Integration - 2026-07-15

- The complete source-safe declaration is now `90/93`, position `10`, owned/emitted by [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), and retains `[[CHILDREN]]`. It precedes [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) at position `20`.
- Exact source layout remains `ObjectPane` base through `+0x127`, followed by borrowed `LivingObjectPane *m_livingObjectPane` at `+0x128`, for exact size `0x12c`. The size guard remains authoritative; no explicit source padding member is added.
- Constructor, virtual destructor, `GetLivingObjectPane`, null-safe `GetLivingObjectId`, one-store `SetLivingObjectPane`, and `SetSpriteAttribute` remain unchanged. The callback adds the binary-proven final primary no-argument virtual as pure `UpdatePosition()`.
- Vtable alignment proves the shared contract: AttachedObjectPane cell `0x006205b8` is `__purecall`; HitBar cell `0x006207a8` is `0x00538ec0`; DamageNumber cell `0x0062085c` is `0x00539400`; ObjectInfo cell `0x00620910` is `0x00539700`. Each derived implementation recomputes owner-relative bounds before calling `SetBounds`.
- `UpdatePosition` is the strongest common source-facing spelling because the ObjectInfo override already uses that role. Historical `UpdateHitBarBounds` and `ComputeDisplayBounds` remain class-specific descriptive aliases only and are not concurrent virtual declarations.
- This declaration does not absorb constructor/destructor/attach/detach/viewport bodies from physical aggregate UID0001D8. Exact source children remain responsible for bodies, while vtable UID000350 remains compiler-emitted RTTI/vtable data covered by this declaration rather than handwritten arrays.
- Unrelated `0x005386c0` attached-position spellings, attachment-table details, and folded scalar evidence remain preserved as broader class confidence caps; they do not block this complete required declaration surface.

## UID0003Z4 Owner-Accessor Closure - 2026-07-14

- Current score is `88/91`. The bounded declaration is source-legal and layout-complete for this callback: ObjectPane base, exact constructor/destructor, three owner accessors, first derived virtual, `LivingObjectPane *m_livingObjectPane` at `+0x128`, exact `0x12c` size guard, and child insertion marker.
- Registered retained-source accessors are [UID:0004QP][0x005385c0-0x005385c7.AttachedObjectPaneGetLivingObjectPane](by-memory/0x005385c0-0x005385c7.AttachedObjectPaneGetLivingObjectPane.md), [UID:0004QQ][0x005385d0-0x005385e4.AttachedObjectPaneGetLivingObjectId](by-memory/0x005385d0-0x005385e4.AttachedObjectPaneGetLivingObjectId.md), and [UID:0004QR][0x005385f0-0x00538600.AttachedObjectPaneSetLivingObjectPane](by-memory/0x005385f0-0x00538600.AttachedObjectPaneSetLivingObjectPane.md).
- The getter returns the borrowed owner, the ID getter maps null to zero and otherwise calls the owner's object-ID accessor, and the setter performs the exact one-store update. Full LivingObjectPane cleanup inlines the null store; that optimization is positive retention evidence rather than covered-by/compiler/no-code proof.
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) remains LivingObjectPane-owned. AttachedObjectPane destruction is only its sole caller/source-use context.
- No AddRef, ownership transfer, map lookup, field reordering, explicit padding member, invented attached-position declaration, or separate accessor source file is introduced. The unrelated `0x005386c0` spelling uncertainty remains bounded historical evidence and does not block this complete required surface.

## UID0003Z4 Accessor Child Order

1. UID0004QP `[0x005385c0,0x005385c7)` uses `Nested:4`.
2. UID0004QQ `[0x005385d0,0x005385e4)` uses `Nested:0`.
3. UID0004QR `[0x005385f0,0x00538600)` uses `Nested:0`.
4. Following UID0001D9 closes the aggregate level with `Nested:-4`; these values are indentation deltas, not child counts.

## Status

- Confidence: strong for base overlay role and anchors.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Address/range evidence: [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md), [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), and [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)
- Parent attachment: enabled because this class page is `85/88` and the owning [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) file page is `85/85`, clearing the corrected child-plus-parent gate.

## Class Purpose

`AttachedObjectPane` is the shared base for object-attached overlays. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), records the linked object id, attaches or detaches payload objects, adjusts depth/offset data, invalidates map regions, and synchronizes overlay placement to map/viewport coordinates.

## Class Shape

- Base family: [UID:00009R][ObjectPane](by-class/ObjectPane.md)-derived overlay pane attached to map objects.
- Primary state: linked object id, attached payload pointer, registry/owner pointer at `+0x128`, and attachment offset/depth state.
- Derived users: balloon, object-info, hit-bar, and damage-number panes share this teardown and placement machinery.
- Source placement: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). The destructor consumes [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), but B001's 2026-06-16 source-shape pass routes that exact body to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md); [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md) remains only a rejected generated pseudo-class.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005380b0-0x005380f6` | Initializes the `ObjectPane` base and stores the linked object id. |
| destructor | `0x00538100-0x005382f8` | Releases the attached payload, invalidates its map rectangle, removes it from MapPane, calls the owner/registry detach helper at `0x0053aec0`, and calls base cleanup. |
| `AttachObject` | `0x00538300-0x0053845f` | Replaces current attachment, applies attachment-table payload deltas, and refreshes regions/back pane state. |
| `DetachObject` | `0x00538460-0x005385bc` | Removes the current attachment and reverses payload/back-pane deltas. |
| `SyncViewportToMap` | `0x00538600-0x00538692` | Converts a map-cell direction/layer offset into viewport coordinates. |
| `MaybeReleaseOwner` | `0x005386a0-0x005386bd` | Owner-release callback that optionally calls the delete thunk. |
| scalar deleting destructor | `0x0053cfa0-0x0053cfdb` | Calls the non-deleting destructor and frees memory when requested. |

## Evidence Notes

- `BalloonObjectPane::BalloonObjectPane` directly calls this constructor at `0x0046830f`.
- Derived overlay destructors for balloon, object info, hit bar, and damage number use the attached-object teardown path.
- IDA decompilation of the destructor shows `sub_53AEC0(*(this + 0x128), this)` at `0x005382b0`. The stored `+0x128` pointer is the owning `LivingObjectPane` registry receiver, so [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) is now documented as a consumed LivingObjectPane deregistration method rather than code folded into `AttachedObjectPane.cpp`.
- 2026-05-25 IDA MCP recheck reconfirmed `0x0053aec0` has no callers or xrefs outside this destructor.
- 2026-05-26 IDA MCP recheck reconfirmed the same sole caller and registry-pointer call shape, with no evidence for an original standalone `AttachedObjectPaneHelper_53AEC0` class.
- [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md) records the exact `AttachedObjectPane` RTTI pointer and three vtable views at `0x00620548`, `0x006205c0`, and `0x006205f0`; the vtable child now attaches here after this class clears the strict gate.
- 2026-06-29 B012 current MCP session `07c55da0` reconfirmed [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md) as class-owned compiler-emitted RTTI/vtable data. The child starts at `0x00620544`, uses vtable bases `0x00620548`, `0x006205c0`, and `0x006205f0`, receives constructor/destructor vptr stores from `0x005380d5`/`0x00538132`, `0x005380db`/`0x00538138`, and `0x005380e5`/`0x00538142`, and ends before the `EffectObjectPane` RTTI boundary at `0x006205f8`. It is covered by this class declaration, destructor wrappers, and virtual methods; do not add raw vtable or RTTI dword arrays.
- 2026-07-04 B010 limited callback incorporated MCP session `eb7ce28b` for [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md). UID0003Z4 now adds exact source children [UID:0004QP][0x005385c0-0x005385c7.AttachedObjectPaneGetLivingObjectPane](by-memory/0x005385c0-0x005385c7.AttachedObjectPaneGetLivingObjectPane.md), [UID:0004QQ][0x005385d0-0x005385e4.AttachedObjectPaneGetLivingObjectId](by-memory/0x005385d0-0x005385e4.AttachedObjectPaneGetLivingObjectId.md), and [UID:0004QR][0x005385f0-0x00538600.AttachedObjectPaneSetLivingObjectPane](by-memory/0x005385f0-0x00538600.AttachedObjectPaneSetLivingObjectPane.md); future exact child work remains only for constructor, destructor, attach/detach, viewport synchronization, release callback, and shared attached-position helper source. Field-role evidence identifies `+0x118` as the attached payload/object pointer, `+0x11c` as attachment height/depth adjustment, `+0x128` as `LivingObjectPane *m_livingObjectPane`, and `+0x100/+0x104` as fallback coordinates used by the attached-position helper.

## Attachment and Reconstruction State

- Attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) after the source-root page was refreshed above the gate and the class page recorded its durable range evidence.
- Keep the detach-registry method and anchor resolver as linked supporting pages rather than absorbing their details here; this class page should summarize base overlay ownership and point to exact by-memory pages for boundaries. [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) belongs to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) but remains a critical destructor-call dependency.
- UID0001D8 remains an aggregate/container under [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), not a monolithic class method. Its formal aggregate marker remains documented; the three exact owner-accessor children now carry their real bodies, while other method/helper bodies remain candidates for later exact children after their independent blockers are resolved.
- Preserve the B010 negative evidence: no monolithic source body belongs to the aggregate, no raw `sub_*`/`unk_*` labels belong in source, no Balloon-only or LivingObjectPane ownership is supported for the aggregate, no standalone helper-file route is supported for the raw registry accessors, and the folded `0.1f` scalar is not this class's static data.

## Score Rationale

- Completion is `88` because the class page now ties the constructor/destructor/attach/detach/viewport cluster, exact typed owner field and three accessor children, unregister dependency, scalar deleting destructor, exact vtable data, derived overlay users, and file-root source placement into one auditable declaration.
- Confidence is `91` because the base boundary, `+0x128` field, constructor store, getter/null-safe-id/setter bytes, vtable route, size guard, and generated source route agree. Unrelated attachment-table and shared-position-helper spellings still cap the broader class below final audit.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md)
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)
- [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:00009P][ObjectInfoObjectPane](by-class/ObjectInfoObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md)

## Changes

- 2026-07-04 B010 limited UID0001D8 callback:
  - Scores and metadata unchanged at `85/88`, owner/emitter [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), and blank class formal C++.
  - Added support-state note that [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md) is now a file-root aggregate with a formal no-monolithic-body marker; future exact child pages should own the real constructor/destructor/attach/detach/accessor/sync/release/position-helper bodies.
  - Evidence: current MCP session `eb7ce28b` confirmed the aggregate function inventory, raw helper byte islands, cross-overlay callers for `0x005386c0`, field roles at `+0x118`, `+0x11c`, and `+0x128`, and unresolved `unk_69B450` child-level table semantics.

- 2026-06-29 B012 accepted AttachedObjectPane vtable marker implementation:
  - Scores and metadata unchanged at `85/88`, owner/emitter [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), and blank class formal C++.
  - Added current-MCP support detail that exact child [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md) is class-owned source-declared/generated-binary RTTI/vtable data covered by the `AttachedObjectPane` class declaration and virtual methods rather than raw table source.
  - Evidence: session `07c55da0` reconfirmed the exact range, three vtable bases, constructor/destructor vptr stores, adjusted thunk views, and `EffectObjectPane` successor boundary.

- 2026-06-16 B001 source-shape execution:
  - Scores unchanged at `85/88`.
  - Updated the detach-registry wording after [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) was rerouted to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md). This class remains the sole caller/source-use context through `AttachedObjectPane +0x128`, not the canonical owner of the helper body.
  - Evidence: B001 live IDA and raw PE checks reconfirmed the sole destructor call at `0x005382b0`, receiver setup/cleanup in the LivingObjectPane field cluster, and no standalone helper-class evidence.

- 2026-06-11 A004 Batch 168 strict-gate refresh:
  - Before: `82/88`, still attached under stale 80% gate wording even though the current supervisor gate is 85/85.
  - Changed to: `85/88`, kept [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) as direct file parent, added exact vtable child evidence, and recorded score rationale.
  - Evidence: the class page now cross-checks [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md), [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), and [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md); final C++ remains blank.

- 2026-06-06 attachment/provenance refresh:
  - Before: the status block relied on recovered-source/Wave-derived scoring context and left the file parent blank because the class/file pages were below the attachment gate.
  - Changed to: `82/88`, attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), recorded durable by-memory range evidence, and added attachment/reconstruction state while keeping final C++ blank.
  - Evidence at that time: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) had been refreshed to `82/84`, [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md) covered the constructor/destructor/attach/detach/viewport cluster, [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) documented the sole detach-registry helper, and derived overlay docs supported the shared base role.
- What existed before: the page had method coverage and helper evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `78/88`, and class-shape notes were added for base family, primary fields, derived users, and source placement.
- Summary and evidence: destructor decompilation, IDA sole-caller evidence for the registry detach helper, and derived overlay call sites support strong confidence; completion remains below full until member layout and final source split are completely reconstructed.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor/destructor/attach/detach/viewport/destructor-wrapper starts at `0x005380b0`, `0x00538100`, `0x00538300`, `0x00538460`, `0x00538600`, and `0x0053cfa0`, and `callers` shows the constructor reached from the balloon overlay path. `AUTOGEN_PARENT_UID` remains blank because both this class page and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) are still below the 80+ completion attachment gate.
