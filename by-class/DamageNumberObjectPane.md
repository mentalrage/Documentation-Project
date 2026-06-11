*** UID:00003F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DamageNumberObjectPane

## Status

- Confidence: strong for role, anchors, source placement, destructor path, and static-pool/vtable support.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Address/range evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), and [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md)
- Parent attachment: enabled because this class and the owning [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) file page now clear the 80%+ completion/confidence gate.

## Class Purpose

`DamageNumberObjectPane` displays floating damage or healing numbers attached to a map object. It chooses the display style from source/sign, formats the numeric text, schedules a short animation, computes display bounds from the owner object, and renders digit frames from `DMGNUM.EPF`.

## Class Shape

- Base family: attached combat overlay derived through [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) and [UID:00009R][ObjectPane](by-class/ObjectPane.md).
- Source placement: keep with `map/AttachedObjectPane.cpp` beside `HitBarObjectPane` and `ObjectInfoObjectPane`; it is constructed by MapPane action/damage handlers and uses attached-object cleanup.
- Primary state: owner object link, damage/heal style flags, formatted numeric text or digit buffer, animation timing/state, and computed owner-relative display bounds. Exact field offsets and names still need a field-layout pass.
- Rendering role: pick digit-frame resources from `DMGNUM.EPF`, update a short floating animation, and draw the packed digit/run representation at the computed attached-object position.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00539230-0x0053935e` | Initializes owner, sign/style flags, number text, and animation timer. |
| `UpdateAnimationState` | `0x00539380-0x005393f8` | Updates host/animation state around the object-pane anchor. |
| `ComputeDisplayBounds` | `0x00539400-0x005394a5` | Positions the floating number relative to the attached object bounds. |
| `Copy128BitValue` | `0x005394b0-0x005394c3` | Copies packed draw vector values. |
| `RenderDamageText` | `0x005394d0-0x005395a7` | Loads and renders digit frames from `DMGNUM.EPF`. |
| scalar deleting destructor | `0x0053d060-0x0053d0f7` | Tears down attached-object base and frees from the object heap when requested. |

## Evidence Notes

- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md) records the constructor, animation update, bounds computation, packed-copy helper, and render anchor inside the attached-overlay half of the mixed object-overlay cluster.
- Constructor callers are in MapPane action/damage handlers at `0x0050ef00` and `0x00512960`; later IDA-backed notes refine those call sites to `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, and `0x00512ac2`.
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) confirms the destructor/scalar wrapper at `0x0053d060-0x0053d0f7`, adjustor refs at `0x0053cec0`/`0x0053cecb`, vtable data at `0x006207ec`, attached-pane cleanup through `0x00538100`, and the pool-free path gated by `byte_69B95C`.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) records static-pool evidence for `DamageNumberObjectPane` at `0x0069b95c`, matching the destructor pool-free guard.
- [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) ties this class's generated vtable data to the same executable anchor cluster.

## Reconstruction State

- Attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) after the file root and class page cleared the attachment gate.
- Final C++ remains blank because field names, style/sign enum names, digit-buffer layout, animation timing fields, and helper names are not yet final-source quality.
- Treat vtable references as generated binary data. Reconstruct class declarations and virtual methods, not hand-authored vtable arrays.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)
- [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:00009P][ObjectInfoObjectPane](by-class/ObjectInfoObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-06-07 A002:
  - Before: the page remained below the parent-attachment gate and retained recovered-source/Wave-derived status wording.
  - Changed to: `82/88`, attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), added durable by-memory constructor/method/destructor/vtable/static-pool evidence, and documented final-C++ blockers.
  - Evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md), and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/84`.
  - Summary/evidence: overlay role, constructor, animation/bounds/render helpers, destructor, MapPane caller anchors, and sibling object-pane links are documented; remaining work is deeper field naming and the unresolved unknown caller classification.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x00539230`, `0x00539380`, `0x00539400`, `0x005394d0`, and `0x0053d060`, with constructor callers from MapPane damage/action paths at `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, and `0x00512ac2`.
