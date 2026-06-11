*** UID:000057 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FlyingObjectPane

## Status

- Confidence: strong for class identity, exact method anchors, vtable stores, pool storage, and MapPane constructor call sites; medium-high for final field names and source-ready method names.
- Source file parent: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), now assigned after both sides clear the corrected `85/85` gate.
- Core executable range: [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- Scalar deleting destructor: [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) at `0x0053d1a0-0x0053d237`
- Vtable data: [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md), `FlyingObjectPane` RTTI and vtable tables at `0x00620498`, `0x0062049c`, `0x0062050c`, and `0x0062053c`
- Pool storage: [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md)

## Class Purpose

`FlyingObjectPane` is a temporary map object for thrown or launched item visuals. It interpolates an item glyph along an arc, schedules short timer ticks, plays impact sound, triggers linked-object impact animation when applicable, and either drops a new object or removes the temporary pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00537cb0-0x00537d60` | Called from MapPane update paths at `0x0050e09b` and `0x00512ebe`; constructs the `ObjectPane` base, installs the three `FlyingObjectPane` vtable views, and initializes start/end motion state. |
| destructor/base-body shim | `0x00537d60-0x00537d7f` | Restores inherited `ItemObjectPane` vtables and delegates to `ObjectPane` cleanup; no direct current xrefs. |
| `GetBoundingRect` | `0x00537d80-0x00537f1d` | Computes the current arc-interpolated item glyph bounds using MapPane/object-list and item-image/tile globals. |
| `OnAnimationTick` | `0x00537f20-0x005380af` | Advances the flight, schedules timers, handles impact sound/effects, and resolves final drop/removal through MapPane object helpers. |
| scalar deleting destructor | `0x0053d1a0-0x0053d237` | Restores item/flying vtables, runs object-pane cleanup, and frees through the `0x0069b9d4` pool gate when requested. |

## Evidence Notes

- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) records the 2026-06-07 live IDA refresh for the constructor, destructor shim, bounds method, and animation tick, including function sizes, caller sites, data refs, and padding.
- [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) records exact `FlyingObjectPane` RTTI/vtable bases and constructor/destructor store xrefs at `0x00537d1c`, `0x00537d22`, `0x00537d2c`, and the scalar destructor path.
- [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md) confirms the exact `0x28`-byte pool storage, block size `324`, chunk count `4`, startup/cleanup wrappers, allocation paths, constructor-failure free, and scalar deleting destructor free.
- Constructor xrefs from MapPane packet/update helpers are evidence for creation, not source ownership transfer. Keep the caller-side cleanup with [UID:0000L3][MapPane](by-file/MapPane.md).

## Assignment Gate

- Child score after the Batch 089 refresh: `COMPLETION:85`, `CONFIDENCE:88`.
- Direct proposed parent: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), refreshed in the same batch to `COMPLETION:85`, `CONFIDENCE:86`.
- Assignment decision: `AUTOGEN_PARENT_UID:0000KG` is justified because `ItemObjectPane.cpp` owns the item-shaped map-object source module, this class is the temporary flying/thrown item companion to [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md), and both child and direct parent satisfy the corrected `85/85` gate.
- Final C++ remains blank because motion field names, packet/update helper names, and exact final source declarations are not yet final-audit quality.

## Cross-References

- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
- [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md)
- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: temporary thrown-item pane role, constructor, bounds, animation tick, destructor, and key caller evidence are documented with strong confidence; remaining work is deeper layout naming and final C++ reconstruction. Evidence: documented address cluster `0x00537cb0-0x005380af`, destructor `0x0053d1a0-0x0053d237`, IDA constructor xrefs, and ItemObjectPane/MapPane cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving this temporary item-flight map object unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `76/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x00537cb0`, `0x00537d80`, `0x00537f20`, and `0x0053d1a0`, with constructor callers from `0x0050e09b` and `0x00512ebe` in MapPane-side update paths.
- 2026-06-07 Batch 089 parent-gate refresh:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000KG`.
  - Summary/evidence: pulled in the current item/flying executable audit, exact FlyingObjectPane vtable-store evidence, destructor-island support, and exact pool-storage evidence. [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) was refreshed to `85/86`, satisfying the direct-parent side of the corrected gate; C++ remains blank under the final-source gate.
- 2026-06-10 B001-035 vtable split update:
  - What existed before: vtable references pointed at the former broad mixed Static/Item/Flying/Attached data group.
  - Changed to: references now point at exact [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md).
  - Evidence: fresh IDA MCP identifies `0x00620498-0x00620544` as the exact `FlyingObjectPane` RTTI/vtable range.
