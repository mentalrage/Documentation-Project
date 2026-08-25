*** UID:00005I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000578 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000578 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FramePartPane.h"
#include "BlackHole.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "Pane.h"
#include "RectBounds.h"

class FramePartPane : public Pane
{
public:
    FramePartPane(int partIndex, const RectBounds &bounds);
    virtual ~FramePartPane();

protected:
    virtual void OnPaint();
    virtual void OnChangeMessage(LObject *owner, Message *message);

private:
    int m_partIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FramePartPane

## Status

- Confidence: strong for behavior, vtable ownership, and source-family placement; medium-high for live construction reachability.
- Likely source file: [UID:000578][FramePartPane](by-file/FramePartPane.md), reconstructed as `NexusTK/ui/core/FramePartPane.cpp` and `FramePartPane.h`.
- Address range: [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- Vtable/layout anchor: [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md); mixed index [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md); exact data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)

## Class Purpose

`FramePartPane` is a smaller frame-border pane. It stores a frame-part index, positions itself from a provided rectangle, registers for the `goog` notification, and draws one `FRMPART.EPF` or `FRMPART.EPD` image.

The five active frame-part pointers are tracked in [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md), preferably as source-facing `g_framePartPanes[5]` with index roles top strip, left side, right side, lower-left piece, and lower-right piece. [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) constructs these five objects by calling the constructor with part indexes `4, 0, 1, 2, 3` in slot order. The notification handler clears those globals after dismissing the current pane; the separate file-level [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) helper emits source-ready `ReleaseFramePartPanes()` to delete each non-null slot through the `FramePartPane` scalar deleting destructor and clear it. That helper is owned by [UID:000578][FramePartPane](by-file/FramePartPane.md), not by this class, because it has no object receiver and manages file-static FramePartPane slots.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `OnChangeMessage(LObject *, Message *)` | `0x004b73b0-0x004b7401` | Common LObject callback; handles `goog`, queues the pane for deferred deletion, and clears five global frame-part slots. |
| `OnPaintFrame` | `0x004b7410-0x004b7480` | Selects `FRMPART.EPF`/`FRMPART.EPD`, uses the part index at `+0xf8`, and draws the frame image. |
| `FramePartPane::FramePartPane` | `0x004b7480-0x004b7515` | Constructs base pane, stores part index, sets bounds, and registers `goog` notification; called five times by `BuildFramePartPanes` for the frame-part slot family. |
| `~FramePartPane` | `0x004b7520-0x004b7590` | Unregisters `goog`, detaches from layer, and destroys the pane base. |
| `ScalarDeletingDestructor` | `0x004b75b0-0x004b7661` | Destructor/delete wrapper with optional delete guard. |

## First-Draft C++ Readiness

[UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) now carries first-draft C++ readiness for the source-authored class methods: constructor, ordinary destructor, notification handler, and paint handler. The C++ body belongs to the memory child so the class page remains a class/ownership/type summary rather than a method-body emitter.

The file-level builder [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) carries first-draft C++ for the five `new FramePartPane(partIndex, bounds)` calls. That builder remains a [UID:000578][FramePartPane](by-file/FramePartPane.md) file helper, not a `FramePartPane` method, because it has no object receiver and publishes objects into file-static FramePartPane slots.

The source-authored methods are:

- `FramePartPane::FramePartPane(int partIndex, const RectBounds &bounds)`: base-constructs `Pane(1)`, stores `m_partIndex` at `+0xf8`, attaches the pane to the current frame layer/context, and calls inherited `g_pBackPane->RegisterChangeListener(this, kFramePartNotificationTag, false)`.
- `FramePartPane::~FramePartPane()`: calls the matching inherited `g_pBackPane->UnregisterChangeListener(this, kFramePartNotificationTag, false)` and removes the pane from its layer; base `Pane` cleanup is implicit in source.
- `FramePartPane::OnChangeMessage(LObject *, Message *)`: checks `message->m_type` for the `goog` tag, queues the pane for deferred deletion through BlackHole, and clears the five frame-part pane slots.
- `FramePartPane::OnPaintFrame()`: initializes an `EPFTileContext`, chooses `FRMPART.EPF` or `FRMPART.EPD` from the global EPF/EPD selection flag, looks up the record for `m_partIndex`, and dispatches the tile/frame blit callback against inherited bounds.

The scalar deleting destructor at `0x004b75b0-0x004b7661` and the secondary/tertiary adjustor thunks at `0x004b7590` and `0x004b759b` are compiler-generated ABI artifacts. They are represented by the destructor, class layout, and vtable documentation, not handwritten as separate source functions. The class score is `92/94`: the complete declaration, exact `0xfc` layout, all authored methods, five-slot lifecycle, resource behavior, compiler-product boundaries, and current source route are resolved, while absent live builder/cleanup entry routes and unproved historical basename/private spellings remain confidence caps.

## Evidence Notes

- IDA MCP reports the factory at `0x004b7120` calls the constructor five times.
- IDA MCP reports no direct callers for the factory at `0x004b7120` in the current database, so live construction is still unresolved.
- 2026-06-22 B011 local PE/cache recheck keeps the constructor relationship but strengthens the route caveat: the five constructor call sites are `0x004b718c`, `0x004b71e2`, `0x004b723b`, `0x004b7294`, and `0x004b72f0`, and no direct rel32 `call`/`jmp`, absolute VA pointer, or RVA pointer to the builder entry `0x004b7120` was recovered. This does not block first-draft source for the class methods or the file-level builder.
- 2026-06-24 B007 implementation adds the file-level release relationship for [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md): current MCP session `80de0a67` still reports no modeled function at cleanup entry `0x004b7320`, but the exact raw body reads `g_framePartPanes[0..4]`, pushes flag `1`, calls primary vtable slot `+0x00`, and clears each slot. Primary vtable slot `+0x00 -> 0x004b75b0`, and the scalar deleting destructor at `0x004b75b0` unregisters `goog`, removes the pane from its layer, runs base cleanup, and calls the delete helper when `(flags & 1) != 0` and `(flags & 4) == 0`, proving the file helper's source-level `delete` semantics.
- The `goog` notification tag and `FRMPART` resources overlap strongly with `AboveFrame`.
- IDA MCP confirms three `FramePartPane` vtable bases at `0x0061a7fc`, `0x0061a848`, and `0x0061a878`; current generated metadata reports `vtable_count: 0`.
- 2026-05-31 IDA MCP proves exact vtable-data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md), starting at the primary RTTI locator and ending before non-vtable constant `0x0061a880` and `GeneralPurposePanel` RTTI at `0x0061a884`.
- 2026-06-12 A004 split refresh adds source-local by-vtable child [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md), routed here at child `89/93` with this direct parent at `85/89`; live IDA MCP reconfirmed the three decorated `FramePartPane` table bases, constructor/destructor/scalar-destructor vptr stores, slot target sizes, unique signature, and `0x0061a880` non-vtable successor boundary.
- 2026-05-26 IDA MCP recheck corrects the exact factory span to `0x004b7120-0x004b731f` end-exclusive, confirms `0x004b7320` remains not-a-function, and confirms the five `0x0069b33c-0x0069b34c` slot xrefs still split across factory writes, raw cleanup reads/clears, and callback pointer clears.
- 2026-06-06 IDA MCP recheck of [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) confirms exact child boundaries, five factory constructor calls, vtable-only refs for notification/paint/scalar destruction, part index at `+0xf8`, three vtable-view writes at `+0x00/+0xa0/+0xa4`, `goog` unregister/detach/base cleanup, scalar optional delete, and padding around the modeled bodies.
- 2026-06-11 A005 live IDA MCP parent-gate refresh reconfirms factory `0x004b7120-0x004b731f`, no IDA function at raw cleanup start `0x004b7320`, method boundaries through scalar deleting destructor `0x004b75b0-0x004b7661`, five constructor refs from the factory, all three vtable bases, vptr stores at `0x004b74b5`/`0x004b74bb`/`0x004b74c5`, `0x004b754c`/`0x004b7552`/`0x004b755c`, and `0x004b75dc`/`0x004b75e2`/`0x004b75ec`, and the exact `0x0061a7f8-0x0061a880` boundary before the non-vtable constant and `GeneralPurposePanel` RTTI.

## Assignment Gate

This class clears the strict `85/85` gate at `92/94` with [UID:000578][FramePartPane](by-file/FramePartPane.md), currently `91/93`, as the direct source root for `NexusTK/ui/core/FramePartPane.cpp` and `FramePartPane.h`. The source-local vtable page [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) and exact vtable-data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) attach to this class, while the mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) aggregate remains a historical index rather than a current class or file parent.

### Historical Assumption - Superseded FrameChrome Route

Earlier active prose used [UID:0000JL][FrameChrome](by-file/FrameChrome.md) as this class's source root. Preserve that route only in historical change/evidence context; current UID000578 metadata, source order, generated-output contract, and accepted split incorporation supersede it.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md)
- [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)
- [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)

## UID0000JL Accepted Split Incorporation - 2026-08-25

- Active documentation/source root: [UID:000578][FramePartPane](by-file/FramePartPane.md). This class page emits the complete `FramePartPane.h` declaration and the CPP include prefix at source position `0`; exact method bodies remain on [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md).
- The observed allocation size is exactly `0xfc`: the inherited `Pane` state occupies `0x000-0x0f7`, and `int m_partIndex` occupies `+0xf8-0xfb`. No larger synthetic frame-chrome aggregate or additional member is supported.
- The source-facing constructor is `FramePartPane(int partIndex, const RectBounds &bounds)`. The paint slot is `void OnPaint()`, not the decompiler-shaped `int OnPaintFrame`; the primary vtable and peer pane convention make the return value `void` despite incidental EAX state.
- The constructor adds the supplied bounds to the main layer and registers the frame-part notification. `OnPaint` chooses `FRMPART.EPF` or `FRMPART.EPD`, loads `m_partIndex`, and renders into `m_visibleBounds`. `OnChangeMessage` queues deferred deletion and clears all five slots. The destructor unregisters the listener and calls `RemoveFromLayer()`.
- Build and cleanup entry starts have zero incoming xrefs and zero stored VA/RVA pointer patterns. That negative result limits runtime-route confidence but does not erase the coherent retained class, builder, cleanup, vtables, slots, or human-source reconstruction.
- The scalar deleting destructor and two adjustor thunks are compiler generated from the declaration/vtables. Raw vtable/RTTI bytes, pooled literals, and padding remain blank formal source.
- Score `92/94` reflects the completed declaration, exact `0xfc` layout, all authored methods, five-slot lifecycle, resource behavior, exact compiler-product boundaries, and resolved source route. It remains capped by absent live factory/cleanup entry refs and unproved historical basename/private spelling.

## Changes

- 2026-08-25 UID0000JL callback: changed `87/92 -> 92/94`, routed owner/emitter to UID000578 at position `0`, added the complete H declaration and required CPP includes, corrected `RectBounds`/`void OnPaint`, and preserved the retained/no-entry distinction and generated no-code products.

- 2026-07-13 Agent-B003 UID0000ZW support synchronization:
  - Changed `86/90` to `87/92`; synchronized the class method inventory with `OnChangeMessage(LObject *, Message *)` and inherited BackPane registration/unregistration using `false`.
  - Preserved the five-slot pointer-clear versus release/delete distinction, complete paint/resource behavior, exact method ranges, vtable evidence, FrameChrome route, raw factory caveat, and generated destructor/thunk exclusions.
  - The complete source-authored formal bodies remain on UID00015O; this class page remains intentionally blank to avoid duplicate method emission.

- 2026-06-24 B007 FramePartPaneSlotCleanup implementation support:
  - Score unchanged at `86/90`.
  - Summary/evidence: added the accepted [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) file-level release/delete relationship. The class remains owner/emitter for `FramePartPane` methods and vtable-derived destructor semantics, while `ReleaseFramePartPanes()` stays a [UID:0000JL][FrameChrome](by-file/FrameChrome.md) file helper over global slots. Preserved the distinction between notification pointer clears and cleanup release/delete behavior.
- 2026-06-22 B011 BuildFramePartPanes support incorporation:
  - Score unchanged at `86/90`.
  - Summary/evidence: added the accepted builder relationship: `BuildFramePartPanes` calls `FramePartPane::FramePartPane` five times with part indexes `4, 0, 1, 2, 3` and stores the resulting objects in source-facing `g_framePartPanes[5]`. Preserved class ownership for methods/vtables while keeping the builder as a file-level `FrameChrome` helper; added the stronger no-rel32/no-VA/no-RVA route caveat as confidence evidence rather than a first-draft blocker.
- Completion/confidence score update: existed before as `0/0`; changed to `82/84`. Summary: frame-part role, global slot ownership, constructor/factory/destructor/paint/notification methods, vtable family, resource behavior, and unresolved live-construction caveat are documented; remaining uncertainty is exact construction reachability. Evidence: FramePartPane memory pages, slot globals, `FrameChromeVtableFamily`, factory/call notes, and `AboveFrame` overlap.
- 2026-05-31:
  - Before: class metadata did not explicitly mark the class reconstructable, and vtable evidence named the bases without an exact `.rdata` child.
  - After: class metadata is reconstructable, scoring is `84/88`, and the exact vtable-data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) is linked.
  - Summary/evidence: IDA MCP dword and xref checks prove the exact RTTI/vtable span and exclude the non-vtable constant at `0x0061a880` and next `GeneralPurposePanel` RTTI from the class vtable.
- 2026-06-06:
  - Before: class autogen parent was blank and the method table still used inclusive-looking destructor/scalar destructor endpoint text.
  - After: class autogen parent is [UID:0000JL][FrameChrome](by-file/FrameChrome.md), the generated-source filename note was removed, and method ranges use exact end-exclusive boundaries.
  - Summary/evidence: the class and file pages are both above the parent-attachment threshold, and the linked memory aggregate now records the live IDA function sizes and boundary bytes.
- 2026-06-11:
  - Before: the class had strong local evidence but remained at `84/88`, which blocked the exact `FramePartPane` vtable-data page under the strict child/direct-parent gate.
  - After: scoring is `85/89`, and the assignment-gate text identifies this class as the direct parent for [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md).
  - Summary/evidence: live IDA MCP reconfirmed method/factory boundaries, the five constructor refs, all three vtable bases, constructor/destructor/scalar-destructor vtable stores, and the exact boundary before the `0x0061a880` constant and `GeneralPurposePanel` RTTI.
- 2026-06-12:
  - Before: this class pointed at the mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) page as the only by-vtable anchor.
  - After: this class points at [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) as its source-local by-vtable child; score remains `85/89`.
  - Summary/evidence: A004 live IDA MCP rechecked the `0x0061a7f8-0x0061a880` `FramePartPane` cluster, lifecycle vptr stores, slot target sizes, unique signature, and `0x0061a880` non-vtable successor boundary, proving the child can route here under the strict gate.
- 2026-06-19 B002 source-quality implementation:
  - Before: score was `85/89`, and the class page documented behavior but not first-draft C++ readiness for the method aggregate.
  - After: score is `86/90`; the class page records that [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) now emits first-draft source-authored constructor/destructor/notification/paint methods while scalar deleting destructor and adjustor thunks remain compiler-generated ABI artifacts.
  - Summary/evidence: accepted B002 report revalidated the method inventory, raw subranges, vtable layout, source-file route through [UID:0000JL][FrameChrome](by-file/FrameChrome.md), slot lifecycle, and remaining confidence caps.
