*** UID:00009P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ObjectInfoObjectPane : public AttachedObjectPane
{
public:
    ObjectInfoObjectPane(
        LivingObjectPane *owner,
        int mapY,
        int mapX,
        const wchar_t *primaryName,
        int textColor,
        unsigned char outlineColor,
        unsigned char fillColor);
    virtual ~ObjectInfoObjectPane();

    void SetPrimaryName(const wchar_t *name);
    void SetSelectedName(const wchar_t *name);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void UpdatePosition();

private:
    friend class MapPane;

    bool m_tracksSelectedName;               // +0x12c
    wchar_t m_primaryName[33];               // +0x12e
    wchar_t m_selectedName[33];              // +0x170
    int m_textColor;                         // +0x1b4
    unsigned char m_outlineColor;            // +0x1b8
    unsigned char m_fillColor;               // +0x1b9
    LivingObjectPane *m_nameOwner;           // +0x1bc
};

typedef char ObjectInfoObjectPaneSizeMustBe448[
    sizeof(ObjectInfoObjectPane) == 0x1c0 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ObjectInfoObjectPane

## UID0003TX Complete Declaration Integration - 2026-07-16

- The class is a complete `0x1c0` AttachedObjectPane-derived source declaration emitted at position `40`. The layout is now closed: tracking flag `+0x12c`, 33-wide primary name `+0x12e`, 33-wide selected name `+0x170`, text color `+0x1b4`, outline/fill bytes `+0x1b8/+0x1b9`, implicit alignment, and LivingObjectPane owner pointer `+0x1bc`.
- Constructor `0x005395b0` receives owner, map row/y, map column/x, primary name, text color, outline color, and fill color. UID0003TX has four separate constructor sites at `0x0050fd17`, `0x0050fd8f`, `0x0050fdd1`, and `0x0050fe10` with colors `12`, `39`, `224`, and `55`.
- Source declarations are `SetPrimaryName`, `SetSelectedName`, inherited `ClearOutputRects(RectBounds *, RectBounds *)`, inherited `RenderFrame(GrafPort *, const RectBounds *)`, inherited one-byte `SetSpriteAttribute(unsigned char)`, and `UpdatePosition()`. These signatures preserve base slots and are compile-visible to the target.
- `SetSelectedName` at `0x00539690` performs the exact bounded fixed-array copy used for the empty alternate label. UID0003TX writes `m_tracksSelectedName` through MapPane friendship; true follows empty selected-name setup for types 1-3, while default type clears it.
- Historical `ComputeTooltipRect`, `DrawTooltip`, and `UpdatePositionFromDirection` are retained as descriptive behavior aliases only. The exact source-facing inherited identities are `ClearOutputRects`, `RenderFrame`, and byte-identical/base-slot-equivalent `SetSpriteAttribute`; the old directional spelling is rejected as an accepted declaration.
- UID0004QO owns unconditional delete-old/store-new replacement at LivingObjectPane `+0x1e4`. ObjectInfo construction, ObjectList registration, position update, bounds, and invalidation remain MapPane caller behavior.
- Compiler vtable views, adjustor thunks, scalar deleting destructor flags, storage free, vptr stores, and EH sites remain generated/non-emitting. UID000355 stays the no-raw-vtable ABI child; this class emits only source declaration and exact method children through `[[CHILDREN]]`.
- The previous blank-class, unresolved-offset, generic-virtual-name, and final-C++ blocker statements below are preserved as historical evidence but are superseded by this complete declaration and `91/93` score.

## Status

- Confidence: very strong for role, anchors, source placement, constructor/text-helper callers, and destructor/vtable support.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Address/range evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), and [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md)
- Parent attachment: enabled because this class is now `85/89` and the owning [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) file page is `85/85`, clearing the strict child/direct-parent gate.

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
- 2026-06-29 B005 implementation callback reconfirmed [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) as class-owned source-declared/generated-binary RTTI/vtable data: live MCP session `agent_b009_0002my_20260628` checked the `0xb4` / 180-byte range, primary/adjusted bases `0x006208a0`, `0x00620918`, and `0x00620948`, constructor vptr stores `0x005395df`, `0x005395e5`, and `0x005395ef`, ObjectInfo override slots `0x00539760`, `0x005398e0`, `0x00539b20`, and `0x00539700`, adjustor-thunk slots `0x0053cf5c` and `0x0053cf67`, and the `0x00620950` Motion successor boundary. The exact child now carries a formal no-raw-vtable marker; this class page still owns the declaration/method reconstruction, not hand-authored vtable arrays.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) groups this class with balloon, hit-bar, and damage-number overlays because all use attached-object placement/teardown and MapPane construction paths. [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) remains a separate HUD gauge despite physical adjacency.
- 2026-06-11 A003 Batch 169 live IDA MCP reconfirmed the in-cluster ObjectInfo starts at `0x005395b0`, `0x00539650`, `0x00539690`, `0x00539700`, `0x00539760`, `0x005398e0`, and `0x00539b20`, constructor callers from `0x0050fd17`, `0x0050fd8f`, `0x0050fdd1`, and `0x0050fe10`, short/text-helper callers at `0x0051344e`, `0x00507b3d`, `0x00507b9a`, `0x00507bfd`, and `0x0050fe29`, vtable/data refs for position/rect/draw/directional helpers, and the attached-overlay split from neighboring BowGauge HUD code.
- 2026-06-12 A003 Batch268 live IDA MCP rechecked the exact vtable child [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md): the three constructor vptr stores at `0x005395df`, `0x005395e5`, and `0x005395ef` target the primary/adjusted vtable views, the primary table carries ObjectInfo overrides at `0x00539760`, `0x005398e0`, `0x00539b20`, and `0x00539700`, and the range is bounded by DamageNumberObjectPane before it and Motion after it.

## Reconstruction State

- Attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) after the file root and class page cleared the strict 85/85 attachment gate.
- Exact vtable child [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) now attaches directly to this class after the child reached `88/92` and this page remains `85/89`.
- Final C++ remains blank because the class declaration, label/string field offsets, tooltip config flag names, and draw-state details are not yet final-source quality.
- Treat vtable references as generated binary data. [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) now resolves its own empty-emitter state with a formal no-raw-vtable marker; reconstruct the virtual method declarations/bodies here and do not add manual vtable arrays.

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

- 2026-06-29 B005 accepted implementation callback:
  - Scores and metadata unchanged at `85/89`, owner/emitter [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), and blank class formal C++.
  - Added current MCP confirmation that [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) remains the class-owned RTTI/vtable child, now carrying a formal no-raw-vtable marker while this class page retains the declaration/method reconstruction blockers.
- 2026-06-12 A003 Batch268:
  - Scores unchanged at `85/89`.
  - Updated the vtable evidence and reconstruction state to reflect [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) now attaching directly to this class under the strict gate.
  - Evidence: live IDA MCP rechecked the three ObjectInfo vtable views, constructor stores, ObjectInfo override slots, and clean neighboring DamageNumber/Motion boundaries.
- 2026-06-07 A002:
  - Before: the page remained below the parent-attachment gate and still used recovered-source/Wave-derived status wording.
  - Changed to: `82/88`, attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), added durable by-memory range/destructor/vtable evidence, and documented class shape plus final-C++ gates.
  - Evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md), and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-11 A003 Batch 169:
  - Changed from: `82/88`, attached parent `0000HJ` under stale 80% wording.
  - Changed to: `85/89`, parent `0000HJ` retained under the strict 85/85 gate.
  - Evidence: live IDA reconfirmed constructor/text/update/rect/draw/directional starts, MapPane constructor and text-helper callers, vtable/data refs, destructor companion evidence, and attached-overlay ownership through [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/update/rect/draw/direction/deleting-destructor starts at `0x005395b0`, `0x00539700`, `0x00539760`, `0x005398e0`, `0x00539b20`, and `0x0053d620`. Left `AUTOGEN_PARENT_UID` blank because this class and likely parent [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) are below the 80 completion attachment gate.
- Before: completion/confidence metadata were `0/0` despite purpose, method-map, caller, and source-placement notes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:82`.
- Evidence: constructor, update, rect computation, draw, direction-offset, destructor, and `MapPane` construction evidence are documented; completion remains below high because field layout, detailed draw-state data flow, and reconstructed C++ are not exhaustive.
