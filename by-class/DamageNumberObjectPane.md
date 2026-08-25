*** UID:00003F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DamageNumberObjectPane : public AttachedObjectPane
{
public:
    DamageNumberObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        int damageAmount,
        unsigned char style);
    virtual ~DamageNumberObjectPane();

    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void UpdatePosition();

private:
    unsigned char m_style;
    unsigned char m_animationFrame;
    int m_absoluteAmount;
    bool m_positive;
    char m_digitFrameOffset;
    char m_damageText[16];
};

typedef char DamageNumberObjectPaneSizeMustBe328[
    sizeof(DamageNumberObjectPane) == 0x148 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DamageNumberObjectPane

## Status

- Confidence: very strong for role, anchors, source placement, destructor path, constructor callers, exact vtable child, and static-pool support.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Address/range evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md), and [UID:0002YS][0x00620bdc-0x00620c10.DamageNumberResourceStrings](by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md)
- Parent attachment: enabled at current `90/93`; the owning [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) file route carries the complete attached-overlay family.

## Class Purpose

`DamageNumberObjectPane` displays floating damage or healing numbers attached to a map object. It chooses the display style from source/sign, formats the numeric text, schedules a short animation, computes display bounds from the owner object, and renders digit frames from `DMGNUM.EPF`.

## Class Shape

- Base family: attached combat overlay derived through [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) and [UID:00009R][ObjectPane](by-class/ObjectPane.md).
- Source placement: keep with `map/AttachedObjectPane.cpp` beside `HitBarObjectPane` and `ObjectInfoObjectPane`; it is constructed by MapPane action/damage handlers and uses attached-object cleanup.
- Primary state: inherited owner and map coordinates plus exact source-facing `m_style`, `m_animationFrame`, `m_absoluteAmount`, `m_positive`, `m_digitFrameOffset`, and 16-byte `m_damageText`; the class size is exactly `0x148`.
- Rendering role: pick digit-frame resources from `DMGNUM.EPF`, update a short floating animation, and draw the packed digit/run representation at the computed attached-object position.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0004SK][0x00539230-0x0053935e.DamageNumberObjectPaneConstructor](by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md) | `0x00539230-0x0053935e` | Exact constructor initializes AttachedObjectPane type 8/mode 3, owner/map coordinates, alpha, signed amount/style fields, `%d` text, style-dependent digit offset, and timer event 0 after 20 ms. |
| `UpdateAnimationState` | `0x00539380-0x005393f8` | Updates host/animation state around the object-pane anchor. |
| `UpdatePosition` | `0x00539400-0x005394a5` | Implements the final shared AttachedObjectPane virtual and positions the floating number relative to the attached object bounds. Historical `ComputeDisplayBounds` is a descriptive alias only. |
| `Copy128BitValue` | `0x005394b0-0x005394c3` | Copies packed draw vector values. |
| `RenderDamageText` | `0x005394d0-0x005395a7` | Loads and renders digit frames from `DMGNUM.EPF`. |
| scalar deleting destructor | `0x0053d060-0x0053d0f7` | Tears down attached-object base and frees from the object heap when requested. |
| vtable/RTTI child | [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) | Primary and two adjusted compiler-emitted vtable views generated from this class declaration. |

## Evidence Notes

- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md) records the constructor, animation update, bounds computation, packed-copy helper, and render anchor inside the attached-overlay half of the mixed object-overlay cluster.
- Constructor callers are in MapPane action/damage handlers at `0x0050ef00` and `0x00512960`; later IDA-backed notes refine those call sites to `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, and `0x00512ac2`.
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) confirms the destructor/scalar wrapper at `0x0053d060-0x0053d0f7`, adjustor refs at `0x0053cec0`/`0x0053cecb`, vtable data at `0x006207ec`, attached-pane cleanup through `0x00538100`, and the pool-free path gated by `byte_69B95C`.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) records static-pool evidence for `DamageNumberObjectPane` at `0x0069b95c`, matching the destructor pool-free guard.
- [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) ties this class's generated vtable data to the same executable anchor cluster.
- [UID:0002YS][0x00620bdc-0x00620c10.DamageNumberResourceStrings](by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md) now carries a formal source-literal marker for `%d`, `DMGNUM.EPF`, and `DMGNUM.PAL`, with direct xrefs at `0x005392e3`, `0x00539551`, and `0x00539563`; no standalone raw `.rdata` string block is authored for that exact child.
- [UID:0002WQ][0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage](by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md) now emits first-draft `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);`. Current MCP evidence reads the 40-byte storage as zero-filled and confirms startup wrapper `0x0041a060`, cleanup wrapper `0x0060c330`, allocation/unwind/destructor refs, and best-inferred name support from [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md). Exact original pool spelling/linkage remains inferred, so numeric constants stay until a final class-layout pass can safely use `sizeof(DamageNumberObjectPane)`.
- [UID:0003CC][0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables](by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md) is adjacent to `DMGNUM.PAL` and the DamageNumber animation scalar, but B001-057 rejected it as direct `DamageNumberObjectPane` ownership: constructor/update/bounds/render code does not read the table, digit rendering derives frame indices from formatted digit characters plus style offset, and the accepted route is file-local static data under [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-11 A003 Batch 169 live IDA MCP reconfirmed the in-cluster DamageNumber starts at `0x00539230`, `0x00539360`, `0x00539380`, `0x00539400`, `0x005394b0`, and `0x005394d0`, constructor callers at `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, and `0x00512ac2`, vtable/data refs for animation, bounds, packed-copy, and render helpers, and the attached-overlay split from the neighboring BowGauge HUD code.
- 2026-06-12 A005 Batch264 live IDA MCP reconfirmed exact vtable child [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md): RTTI dword target `??_R4DamageNumberObjectPane@@6B@`, primary vtable at `0x006207ec`, adjusted views at `0x00620864` and `0x00620894`, constructor stores at `0x0053927d/0x00539283/0x0053928d`, unwind restore stores at `0x00539360/0x00539366/0x00539370`, scalar-destructor restore stores at `0x0053d085/0x0053d08b/0x0053d095`, and successor boundary `0x0062089c -> ??_R4ObjectInfoObjectPane@@6B@`.
- 2026-06-29 B004 source-quality implementation keeps exact vtable child [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) owned/emitted by this class but changes the child from an empty emitter to a formal covered-by marker. Current MCP session `agent_b009_0002my_20260628` reconfirmed the three RTTI/vtable views, predecessor HitBar boundary, successor ObjectInfo boundary, constructor/unwind/destructor stores, adjustor thunks, representative slot refs, and `int_convert.py`-verified `0xb4` / 180-byte target size. The vtable/RTTI bytes are source-declared/generated-binary output of the class declaration and virtual method set, not handwritten `AttachedObjectPane.cpp` table source.

## Reconstruction State

- Attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) after the file root and class page cleared the strict 85/85 attachment gate.
- The complete managed declaration is now source-ready at `90/93`. Real child UID0004SK supplies the constructor definition; exact inherited and local fields, virtual surface, and `0x148` size close the former field/layout blocker without inventing a style enum.
- Treat vtable references as generated binary data. Reconstruct class declarations and virtual methods, not hand-authored vtable arrays.
- [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) carries the formal covered-by marker for this now-complete class declaration; no raw RTTI/vtable arrays are authored.
- [UID:0002YS][0x00620bdc-0x00620c10.DamageNumberResourceStrings](by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md) and [UID:0002WQ][0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage](by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md) remain covered by their existing source-literal/pool declarations and are not duplicated in the class block.

## UID0003TC Shared Virtual Naming Integration - 2026-07-15

- The class remains `86/90` with blank formal C++. Its unrelated field/style/digit-buffer/animation blockers remain, so this bounded name correction does not claim a complete class declaration.
- Fresh family/vtable evidence aligns base `AttachedObjectPane`'s final pure no-argument slot with HitBar `0x00538ec0`, this class's `0x00539400`, and ObjectInfo `0x00539700`. The accepted source-facing base/override name is `UpdatePosition`.
- `ComputeDisplayBounds` is preserved only as the historical descriptive label for the behavior at `0x00539400`; it is not a concurrent source method. The body still computes owner-relative display bounds and all constructor/animation/render/pool/vtable evidence remains unchanged.
- Compiler-generated scalar deleting destructor, adjustors, vptr stores, RTTI, and raw vtable arrays remain excluded from handwritten source. The class method declaration/definition, once its unrelated class blockers are resolved, is what regenerates the shared vtable slot.

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

- 2026-07-16 B004 UID0003TQ source-graph completion:
  - What existed before: `86/90`, blank formal C++, and stale field/layout/helper blockers despite exact constructor, callers, resources, pool, vtable, destructor, and rendering evidence.
  - Changed to: `90/93` with the complete source-clean `0x148` AttachedObjectPane-derived declaration and real constructor child UID0004SK. The block closes before `[[CHILDREN]]` and preserves the existing virtual names, attached-overlay route, resources, pool, and sibling classes.
  - The exact constructor preserves object type 8, mode 3, owner/map row/map column, alpha zero, sign/absolute `%d` formatting, style-dependent digit offset, and timer event 0 after 20 ms. Compiler allocation, vptr, EH/unwind, deleting-destructor, adjustor, RTTI, and raw-vtable mechanics remain excluded.

- 2026-06-07 A002:
  - Before: the page remained below the parent-attachment gate and retained recovered-source/Wave-derived status wording.
  - Changed to: `82/88`, attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), added durable by-memory constructor/method/destructor/vtable/static-pool evidence, and documented final-C++ blockers.
  - Evidence: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md), [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md), and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-11 A003 Batch 169:
  - Changed from: `82/88`, attached parent `0000HJ` under stale 80% wording.
  - Changed to: `85/89`, parent `0000HJ` retained under the strict 85/85 gate.
  - Evidence: live IDA reconfirmed constructor/helper/render starts, MapPane constructor callers, vtable/data refs, destructor companion evidence, static-pool support, and attached-overlay ownership through [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-12 A005 Batch264:
  - Changed from: `85/89`.
  - Changed to: `86/90`, parent `0000HJ` retained.
  - Evidence: live IDA reconfirmed exact [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md), including constructor/unwind/destructor vptr refs, next `ObjectInfoObjectPane` RTTI boundary, and source-declared vtable regeneration handling.
- 2026-06-29 B004 UID000354 marker support sync:
  - Scores unchanged at `86/90`; class-level final C++ remains blank for the existing field-name, style/sign enum, digit-buffer, animation timing, and helper-name blockers.
  - Updated the support note for [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md): the child now has a formal covered-by marker because the RTTI/vtable bytes are source-declared/generated-binary output of this class declaration and virtual method set.
  - Evidence: B004 current MCP session `agent_b009_0002my_20260628` reconfirmed the target's exact RTTI/vtable boundaries, constructor/unwind/destructor vptr stores, adjustor thunks, representative slot refs, and source route through [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-07-01 B009 accepted AttachedObjectPane empty-emitter first batch:
  - Score unchanged at `86/90`; formal class C++ remains blank for the existing field-name, style/sign enum, digit-buffer, animation-timing, and helper-name blockers.
  - Updated support evidence for [UID:0002YS][0x00620bdc-0x00620c10.DamageNumberResourceStrings](by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md) and [UID:0002WQ][0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage](by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md). The resource-string child now carries formal source-literal coverage, and the pool child now emits `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);` with current zero-filled storage evidence.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/84`.
  - Summary/evidence: overlay role, constructor, animation/bounds/render helpers, destructor, MapPane caller anchors, and sibling object-pane links are documented; remaining work is deeper field naming and the unresolved unknown caller classification.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x00539230`, `0x00539380`, `0x00539400`, `0x005394d0`, and `0x0053d060`, with constructor callers from MapPane damage/action paths at `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, and `0x00512ac2`.
