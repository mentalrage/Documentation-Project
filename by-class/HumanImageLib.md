*** UID:00006A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HumanImageLib : public LObject, public Singleton<HumanImageLib>
{
public:
    HumanImageLib();
    virtual ~HumanImageLib();

private:
    ProtectedArray<HeadInfo> m_headInfos;
    ProtectedArray<HeadInfo> m_specialHeadInfos;
    ProtectedArray<BodyInfo> m_bodyInfos;
    ProtectedArray<CoatInfo> m_coatInfos;
    ProtectedArray<WeaponInfo> m_swordInfos;
    ProtectedArray<WeaponInfo> m_spearInfos;
    ProtectedArray<WeaponInfo> m_bowInfos;
    ProtectedArray<WeaponInfo> m_fanInfos;
    ProtectedArray<WeaponInfo> m_shieldInfos;
    ProtectedArray<WeaponInfo> m_arrowInfos;
    ProtectedArray<FaceInfo> m_faceInfos;
    ProtectedArray<Acc1Info> m_accessory1Infos;
    ProtectedArray<HairInfo> m_hairInfos;
    ProtectedArray<Acc2Info> m_accessory2Infos;
    ProtectedArray<HelmetInfo> m_helmetInfos;
    ProtectedArray<MantleInfo> m_mantleInfos;
    ProtectedArray<NecklaceInfo> m_necklaceInfos;
    ProtectedArray<ShoeInfo> m_shoeInfos;

    int m_drawOrderCount;
    int m_extendedDrawOrderCount;
    int m_extendedDrawOrder2Count;
    unsigned int *m_drawOrderEntries;
    HumanDrawOrderEntry *m_extendedDrawOrderEntries;
    HumanDrawOrderEntry *m_extendedDrawOrder2Entries;
    unsigned short m_headFrameCount;
    unsigned short m_specialHeadFrameCount;
    unsigned short m_emotionFrameCount;
    unsigned short m_specialEmotionFrameCount;
    ImageFrameTable *m_headFrames;
    ImageFrameTable *m_specialHeadFrames;
    ImageFrameTable *m_bodyFrames;
    ImageFrameTable *m_swordFrames;
    ImageFrameTable *m_spearFrames;
    ImageFrameTable *m_bowFrames;
    ImageFrameTable *m_fanFrames;
    ImageFrameTable *m_shieldFrames;
    ImageFrameTable *m_arrowFrames;
    ImageFrameTable *m_faceFrames;
    ImageFrameTable *m_accessory1Frames;
    ImageFrameTable *m_hairFrames;
    ImageFrameTable *m_accessory2Frames;
    ImageFrameTable *m_helmetFrames;
    ImageFrameTable *m_mantleFrames;
    ImageFrameTable *m_necklaceFrames;
    ImageFrameTable *m_shoeFrames;
    ImageFrameTable *m_coatFrames;
};

extern HumanImageLib *g_pHumanImageLib;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HumanImageLib

## Status

- Confidence: very strong for direct bases, EBO, exact `0x2b0` layout, virtual surface, field families, source ownership, singleton, vtable, and lifetime children; descriptive private spellings cap confidence below 95.
- Likely source file: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- Address ranges: [UID:00017A][0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster](by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md), singleton clear helper [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md), and scalar deleting destructor [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md)
- Singleton: [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`.
- Vtable: [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) at `0x0061b6d4`.
- Layout: [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## Class Purpose

`HumanImageLib` is the legacy human character image library. It owns old-format human body/equipment image table handles and ProtectedArray metadata for parts such as body, face, hair, weapon, shield, helmet, mantle, necklace, shoes, and coat.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HumanImageLib::HumanImageLib` | [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md) | Large startup table loader; initializes human/equipment arrays and calls the shared frame-table loader for old human asset families. |
| `HumanImageLib::~HumanImageLib` | [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md) | Releases 18 body-part image-library handles, optional cached resources, and ProtectedArray buffers. |
| `HumanImageLib singleton clear thunk` | [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) | Tiny cleanup/static-lifetime thunk that clears `g_pHumanImageLib`; descriptive binary-page alias only, not a source-facing `HumanImageLib::ClearSingleton` method. |
| `ScalarDeletingDestructor` | [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md) | Compiler-emitted HumanImageLib scalar deleting destructor; class-owned generated-binary support that calls the ordinary destructor, conditionally deletes `this` through `sub_4F4AC0`, and stays blank in final C++ because the class destructor/vtable shape should regenerate it. |

IDA MCP on 2026-05-26 confirms the class vtable at `0x0061b6d4`, adjacent old-human `ProtectedArray` vtables at `0x0061b674-0x0061b6cc`, and singleton storage at `0x0069b43c`. The constructor still has no direct code refs in the IDA code-ref query, which is likely because startup/static initialization invokes it through placement/new or a recovered construction wrapper.

IDA MCP on 2026-06-06 reconfirms the constructor, ordinary destructor, singleton-clear helper, and scalar-deleting wrapper boundaries. The same pass confirms the scalar wrapper calls [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md), conditionally calls `sub_4F4AC0`, uses `@_guard_check_icall_nop@4` for the guarded flag path, and ends at `0x004e649b` before five `0xcc` padding bytes.

IDA MCP on 2026-06-07 Batch 090 reconfirms the same function objects in the current IDB: constructor `0x004d2720-0x004d4aca`, ordinary destructor `0x004d4ad0-0x004d4f67`, singleton clear helper `0x004e5b80-0x004e5b8b`, and scalar deleting destructor `0x004e6460-0x004e649b`. The constructor still has no direct caller xrefs, but it writes `g_pHumanImageLib` at `0x0069b43c`, installs the vtable at `0x0061b6d4`, calls the DAT/frame-table/resource loader family, and references the old-human table/error string cluster. The ordinary destructor restores the same vtable, clears `g_pHumanImageLib`, and tears down the ProtectedArray/frame-library state. The scalar wrapper is vtable-referenced from `0x0061b6d4` and calls the ordinary destructor before optional delete.

Direct parent assignment is finalized to [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md): this class is `92/93`, and the focused file parent is `91/92` with matching old-human singleton, vtable, constructor/destructor, loader-helper, resource-family, and `NewHumanImageLib` separation evidence.

## Rule 26 Source-Quality Audit

The accepted source-quality closure raises this class from `88/88` to `92/93`. Direct `LObject` and `Singleton<HumanImageLib>` bases, Singleton PMD `{4,-1,0}`, +0x04 EBO, exact `0x2b0` layout, eighteen ProtectedArray members, three draw-order arrays, four validation counts, eighteen frame-table handles, virtual destructor, complete source union, compiler exclusions, and old/new HumanImageLib separation are now explicit. Concrete record declarations belong to the focused HumanImageLib header while shared `ProtectedArray<T>` remains a dependency; exact original private identifiers remain a lexical confidence cap, not a source blocker.

Accepted source-facing names and raw/generated-name decisions:

| Raw/generated name | Current source-quality treatment |
| --- | --- |
| `sub_4D2720` | [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md); exact class-owned constructor source. |
| `sub_4D4AD0` | [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md); exact class-owned ordinary destructor source. |
| `sub_4E5B80` / `ClearHumanImageLibSingleton` | Static constructor-cleanup singleton clear thunk; keep file-owned [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), do not emit a hand-authored source helper named `ClearHumanImageLibSingleton`. |
| `sub_4E6460` | Compiler-emitted scalar deleting destructor; class-owned generated-binary support that should regenerate from the virtual destructor/class shape. |
| `dword_69B43C` | Best descriptive source-facing symbol is [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md), while exact original symbol spelling remains unproven. |
| `??_7HumanImageLib@@6B@` / `??_R4HumanImageLib@@6B@` | Compiler-emitted vtable/RTTI artifacts, not handwritten source tables. |
| `sub_4F4AC0` and `@_guard_check_icall_nop@4` | Shared delete/operator-delete support and compiler/guard support reached by the deleting wrapper, not HumanImageLib source. |
| `sub_4F4B10` and `nullsub_18` | Inherited `LObject::GetRuntimeClass` and `LObject::VirtualNoop(int,int)` slots; no duplicate HumanImageLib declaration is emitted for either. |
| `sub_4E6AE0` / `sub_4E6C50` | Exact source-ready file-local children [UID:0004DK][0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable](by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md) and [UID:0004DL][0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable](by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md). The first reads 12-byte HeadInfo rows at two constructor calls; the second reads 16-byte WeaponInfo rows at six equipment-family calls. Both use an existing DATFile stream, positive-count resize, fallback records, encoded-int reads, and [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) on failure. |

Final descriptive field vocabulary is the managed declaration's `m_headInfos` through `m_shoeInfos`, three draw-order count/pointer pairs, four frame-count shorts, and `m_headFrames` through `m_coatFrames`. The prior `cachedResource0..2` interpretation is superseded: `+0x24c/+0x250/+0x254` are the three owned draw-order arrays. Binary resource spellings `ACE1`, `ACE2`, `NECLACE`, and `EMOTIOSP` remain exact when quoting literals.

The constructor references old-human table inputs including `DRWORDER.TBL`, `HEAD.TBL`, `HEADSP.TBL`, `BODY.TBL`, `SWORD.TBL`, `SPEAR.TBL`, `BOW.TBL`, `FAN.TBL`, `SHIELD.TBL`, `ARROW.TBL`, `XDRWORD.TBL`, `XDRWORD2.TBL`, `FACE.TBL`, `HAIR.TBL`, `ACE1.TBL`, `ACE2.TBL`, `HELMET.TBL`, `MANTLE.TBL`, `NECLACE.TBL`, `SHOES.TBL`, `COAT.TBL`, `ACC2DRW.TBL`, and `HAIRCOL.TBL`; it also loads EPF/frame families `HEAD`, `EMOTION`, `HEADSP`, `EMOTIOSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`.

`HumanImageLib` remains separate from [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md), and sibling image libraries such as `MapTileImageLib`, `RidingImageLib`, `LightObjImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, and `ItemObjImageLib`. Those pages own reusable helpers or separate asset families; this class owns only the legacy old-human/equipment concrete fields and lifetime route.

The class page now emits the complete declaration once at position 10. Constructor/destructor bodies remain on their exact children; table loaders remain file-local children; Singleton cleanup, scalar deleting wrapper, vtable, and RTTI bytes regenerate from the direct bases and virtual destructor and therefore remain non-emitting. Lower old-human composition islands remain outside this bounded lifetime/declaration callback and do not duplicate this class declaration.

## Historical / Superseded Assumptions

- The former comment-only class scaffold and below-90 cap are superseded by the accepted declaration/layout/source closure.
- `cachedResource0..2`, unresolved inherited slots, public clear-helper naming, and handwritten scalar-wrapper source are rejected by current draw-order, LObject, Singleton, and compiler-artifact evidence.

## Relationship To NewHumanImageLib

`HumanImageLib` and [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) should be separate source modules. They both render human characters, but their data models differ: old human uses archive-family frame tables and protected arrays, while new human uses motion/layer/part composition tables.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0004DK][0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable](by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md)
- [UID:0004DL][0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable](by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/82`. Summary: legacy human image library role, singleton, vtable, layout, constructor/destructor/static cleanup methods, owned resource families, and separation from `NewHumanImageLib` are documented; completion is capped because this large asset system still lacks exhaustive field/resource-family internals and final field names. Evidence: `0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster`, destructor page, `g_pHumanImageLib`, `HumanImageLibVtable`, `HumanImageLibLayout`, `LoadImageFrameTable`, and ProtectedArray references.

- 2026-05-31 range correction and reconstructable marking:
  - What existed before: class was not marked reconstructable and still pointed at the one-byte-short aggregate label.
  - Changed to: `RECONSTRUCTABLE:TRUE`, scores `78/84`, and references will be validator-resolved to the corrected local aggregate.
  - Summary/evidence: IDA MCP confirmed constructor/destructor/scalar-deleting destructor ends and vtable/singleton xrefs. Scores remain below 95 because the large constructor and final source field names are not fully audited.

- 2026-06-03 constructor child link:
  - What existed before: the constructor row was only an address-level method note under the broad aggregate.
  - Changed to: the method inventory and cross-reference list now link to [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md).
  - Summary/evidence: IDA MCP on 2026-06-03 confirmed the exact constructor range, resource/table evidence, callee families, singleton/vtable refs, and post-body padding. The class score is unchanged because final field names and source declarations remain unresolved.

- 2026-06-06 stale provenance cleanup and method UID refresh:
  - What existed before: the status still named an obsolete source-path provenance file, and the destructor/clear-helper method rows were address-only instead of UID-linked.
  - Changed to: removed the obsolete source-path status line, linked the ordinary destructor and singleton-clear helper to their by-memory pages, and documented the scalar-deleting wrapper behavior and pending standalone page.
  - Summary/evidence: IDA MCP on 2026-06-06 reconfirmed the modeled ranges, `g_pHumanImageLib` and vtable xrefs, scalar-wrapper callees, and post-wrapper padding. Scores are unchanged because class fields and source declarations still need final audit.

- 2026-06-07 Batch 090 parent-gate refresh:
  - Before: scores were `78/84`, and `AUTOGEN_PARENT_UID` was blank.
  - Changed to: scores `85/86` and `AUTOGEN_PARENT_UID:0000JY`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/destructor/clear/scalar-wrapper bounds, `g_pHumanImageLib` refs, `HumanImageLib` vtable refs, constructor resource-loader dependencies, destructor cleanup behavior, and the direct `render/HumanImageLib.cpp` parent. Final C++ stays blank because constructor field names, table declarations, cached resources, inherited vtable slots, and old-human composition islands remain unresolved.

- 2026-06-13 B001 scalar-deleting wrapper routing:
  - What existed before: the scalar deleting destructor method row still said the exact standalone by-memory page was pending.
  - Changed to: linked [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md) and documented it as class-owned generated-binary support routed through this class.
  - Summary/evidence: B001 live IDA MCP reconfirmed the HumanImageLib vtable slot `0x0061b6d4 -> 0x004e6460`, constructor/destructor vptr-store refs at `0x004d278c` and `0x004d4afd`, ordinary destructor callee `0x004d4ad0`, optional delete helper `0x004f4ac0`, and exact padding boundaries. Scores are unchanged because this only removes stale method-row wording; broader class field/source declaration audit remains open.

- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - What existed before: the class was `85/86`, still used a `HumanImageLib::ClearSingleton` method label, and left the no-code reason at the stale final-code-gate level.
  - Changed to: `88/88`, a comment-only class-level C++ defer marker, cleanup-thunk wording for [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md), and a consolidated source-quality section for raw/generated names, old-human resource families, ProtectedArray-vs-concrete-field boundaries, sibling exclusions, unresolved cached resources/frame handles/inherited vtable slot, and exact child-page code ownership.
  - Summary/evidence: B004 rechecked the target/support pages, generated coverage, and local PE ranges/dwords/rel32 scans. Constructor/destructor/clear/scalar-wrapper ranges, singleton/vtable/global/layout anchors, and owner/emitter routing are source-quality enough for the class gate; real declarations and method bodies remain child-page work.
- 2026-07-21 B001 accepted UID0001PM callback: raised to `92/93`, position 10, inserted the complete direct-base/member declaration and `[[CHILDREN]]`, synchronized exact `0x2b0` layout and source/compiler method ownership, and historicalized the former comment-only/placeholder-field conclusions.
