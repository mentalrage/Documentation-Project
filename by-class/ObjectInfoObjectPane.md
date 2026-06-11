*** UID:00009P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectInfoObjectPane

## Status

- Confidence: strong for role, anchors, source placement, and destructor/vtable support.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Address/range evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), and [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md)
- Parent attachment: enabled because this class and the owning [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) file page now clear the 80%+ completion/confidence gate.

## Class Purpose

`ObjectInfoObjectPane` displays the floating name/object tooltip above an attached map object. It measures primary/alternate label text, uses sprite anchor information to place the label, and draws decorated or outlined label text according to config flags.

## Class Shape

- Base family: attached map-object overlay derived through [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) and [UID:00009R][ObjectPane](by-class/ObjectPane.md).
- Source placement: keep with `map/AttachedObjectPane.cpp` beside `HitBarObjectPane` and `DamageNumberObjectPane`; it is constructed from MapPane object/update packet paths and uses the same attached-object teardown path.
- Primary state: owner/attached object link from the base class, primary and alternate label strings, tooltip display flags, cached text bounds, and owner-relative anchor/offset state. Exact member offsets still need a field-layout pass.
- Runtime role: compute a text rectangle from object/sprite anchors, update the overlay position when the owner moves, and draw either normal outlined label text or decorated object-name text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005395b0-0x00539646` | Initializes attached/object label state, labels, flags, and vtables. |
| `UpdatePosition` | `0x00539700-0x0053975b` | Computes tooltip bounds and offsets them to the object screen position. |
| `ComputeTooltipRect` | `0x00539760-0x005398de` | Computes label bounds from image anchors, tile size, and selected label text. |
| `DrawTooltip` | `0x005398e0-0x00539b20` | Draws primary or alternate label text, including decorated name mode. |
| `UpdatePositionFromDirection` | `0x00539b20-0x00539bb2` | Repositions tooltip by directional screen offset. |
| scalar deleting destructor | `0x0053d620-0x0053d65b` | Tears down attached-object base and frees memory when requested. |

## Evidence Notes

- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md) records the constructor, position update, tooltip rectangle, draw, and directional-position anchors as part of the attached-overlay half of the mixed object-overlay cluster.
- IDA-backed docs show repeated constructor xrefs from `MapPane::ProcessMapPacket` around `0x0050fb00`; this is a map-object overlay, not a generic text-control class.
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) confirms the scalar deleting destructor at `0x0053d620-0x0053d65b`, adjustor refs at `0x0053cf62`/`0x0053cf6d`, vtable data at `0x006208a0`, attached-pane cleanup through `0x00538100`, and optional generic free through `0x004f4ac0`.
- [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) ties the `ObjectInfoObjectPane` virtual table data to the same executable anchors and keeps the generated vtables out of hand-written final source.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) groups this class with balloon, hit-bar, and damage-number overlays because all use attached-object placement/teardown and MapPane construction paths. [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) remains a separate HUD gauge despite physical adjacency.

## Reconstruction State

- Attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) after the file root and class page cleared the attachment gate.
- Final C++ remains blank because the class declaration, label/string field offsets, tooltip config flag names, and draw-state details are not yet final-source quality.
- Treat vtable references as generated binary data. Reconstruct the virtual method declarations/bodies; do not add manual vtable arrays.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)
- [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- 2026-06-07 A002:
  - Before: the page remained below the parent-attachment gate and still used recovered-source/Wave-derived status wording.
  - Changed to: `82/88`, attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), added durable by-memory range/destructor/vtable evidence, and documented class shape plus final-C++ gates.
  - Evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md), and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/update/rect/draw/direction/deleting-destructor starts at `0x005395b0`, `0x00539700`, `0x00539760`, `0x005398e0`, `0x00539b20`, and `0x0053d620`. Left `AUTOGEN_PARENT_UID` blank because this class and likely parent [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) are below the 80 completion attachment gate.
- Before: completion/confidence metadata were `0/0` despite purpose, method-map, caller, and source-placement notes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:82`.
- Evidence: constructor, update, rect computation, draw, direction-offset, destructor, and `MapPane` construction evidence are documented; completion remains below high because field layout, detailed draw-state data flow, and reconstructed C++ are not exhaustive.
