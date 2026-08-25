*** UID:0001UR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete HumanImageLib declaration is emitted once by UID00006A.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HumanImageLib Layout

## Status

- Confidence: very strong for exact offsets, field families, object size, EBO, source declaration route, and constructor/destructor agreement; descriptive private spellings cap confidence below 95.
- Owner class: [UID:00006A][HumanImageLib](by-class/HumanImageLib.md).
- Autogen parent: attached to [UID:00006A][HumanImageLib](by-class/HumanImageLib.md); this layout is `92/93` and the direct class parent is `92/93`.
- Evidence: IDA constructor/destructor/vtable xrefs, current IDA function-boundary verification, and destructor decompilation.

## Layout Summary

`HumanImageLib` has exact size `0x2b0`. The direct empty `Singleton<HumanImageLib>` base conceptually starts at `+0x04` and overlaps the first member through EBO; no explicit base-storage or padding member exists.

```text
HumanImageLib
  +0x000  LObject/vtable
  +0x004  ProtectedArray<HeadInfo> m_headInfos
  +0x020  ProtectedArray<HeadInfo> m_specialHeadInfos
  +0x03c  ProtectedArray<BodyInfo> m_bodyInfos
  +0x05c  ProtectedArray<CoatInfo> m_coatInfos
  +0x080  ProtectedArray<WeaponInfo> m_swordInfos
  +0x0a0  ProtectedArray<WeaponInfo> m_spearInfos
  +0x0c0  ProtectedArray<WeaponInfo> m_bowInfos
  +0x0e0  ProtectedArray<WeaponInfo> m_fanInfos
  +0x100  ProtectedArray<WeaponInfo> m_shieldInfos
  +0x120  ProtectedArray<WeaponInfo> m_arrowInfos
  +0x140  ProtectedArray<FaceInfo> m_faceInfos
  +0x15c  ProtectedArray<Acc1Info> m_accessory1Infos
  +0x17c  ProtectedArray<HairInfo> m_hairInfos
  +0x19c  ProtectedArray<Acc2Info> m_accessory2Infos
  +0x1c0  ProtectedArray<HelmetInfo> m_helmetInfos
  +0x1e0  ProtectedArray<MantleInfo> m_mantleInfos
  +0x200  ProtectedArray<NecklaceInfo> m_necklaceInfos
  +0x220  ProtectedArray<ShoeInfo> m_shoeInfos
  +0x240  int m_drawOrderCount
  +0x244  int m_extendedDrawOrderCount
  +0x248  int m_extendedDrawOrder2Count
  +0x24c  unsigned int *m_drawOrderEntries
  +0x250  HumanDrawOrderEntry *m_extendedDrawOrderEntries
  +0x254  HumanDrawOrderEntry *m_extendedDrawOrder2Entries
  +0x258  unsigned short m_headFrameCount
  +0x25c  unsigned short m_specialHeadFrameCount
  +0x260  unsigned short m_emotionFrameCount
  +0x264  unsigned short m_specialEmotionFrameCount
  +0x268  ImageFrameTable *m_headFrames
  +0x26c  ImageFrameTable *m_specialHeadFrames
  +0x270  ImageFrameTable *m_bodyFrames
  +0x274  ImageFrameTable *m_swordFrames
  +0x278  ImageFrameTable *m_spearFrames
  +0x27c  ImageFrameTable *m_bowFrames
  +0x280  ImageFrameTable *m_fanFrames
  +0x284  ImageFrameTable *m_shieldFrames
  +0x288  ImageFrameTable *m_arrowFrames
  +0x28c  ImageFrameTable *m_faceFrames
  +0x290  ImageFrameTable *m_accessory1Frames
  +0x294  ImageFrameTable *m_hairFrames
  +0x298  ImageFrameTable *m_accessory2Frames
  +0x29c  ImageFrameTable *m_helmetFrames
  +0x2a0  ImageFrameTable *m_mantleFrames
  +0x2a4  ImageFrameTable *m_necklaceFrames
  +0x2a8  ImageFrameTable *m_shoeFrames
  +0x2ac  ImageFrameTable *m_coatFrames
```

The six `WeaponInfo` arrays correspond to `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, and `ARROW` in exact address order. Record-size closure is `HeadInfo 0x0c`, `BodyInfo 0x10`, `CoatInfo 0x14`, `WeaponInfo 0x10`, `FaceInfo 0x0c`, `Acc1Info 0x10`, `HairInfo 0x10`, `Acc2Info 0x14`, and each remaining equipment record `0x10`.

## Frame Handle Region

The destructor releases 18 frame-library handles at these exact object offsets:

```text
+0x268, +0x26c, +0x278, +0x270, +0x274, +0x280,
+0x284, +0x27c, +0x288, +0x28c, +0x294, +0x290,
+0x298, +0x29c, +0x2a0, +0x2a4, +0x2a8, +0x2ac
```

The destructor release order is non-monotonic, but constructor stores establish the source declaration order shown in the complete layout above.

## Notes

- The constructor writes [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md), installs the [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md), and initializes the embedded old-human `ProtectedArray` fields.
- The constructor calls [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) repeatedly for old human/equipment frame table families.
- 2026-06-08 A008 IDA MCP `xrefs_to` reconfirmed the class-lifetime anchors used for direct parent routing: constructor vtable store `0x004d278c`, destructor vtable restore `0x004d4afd`, constructor singleton writes `0x004d277b`/`0x004d2782`, destructor singleton clear `0x004d4f44`, and static clear helper write `0x004e5b80`.
- The generated `HumanImageLibAssetBlock { uint32_t words[153]; }` is a recovery placeholder for the large constructor body, not a final source-facing type.
- The generated destructor's `imageDataBlock + 0x21c-0x260` wording should be normalized to the IDA-confirmed object offsets `+0x268-+0x2ac` unless a later constructor pass proves an inner subobject base.
- `+0x24c/+0x250/+0x254` are three owned draw-order arrays paired with counts at `+0x240/+0x244/+0x248`, not optional cached resources. DRWORDER retains 4-byte rows; XDRWORD/XDRWORD2 retain 12-byte rows from 13-byte disk records.
- Constructor call order plus resource prefixes establish all eighteen frame-handle member names and declaration order; destructor release order remains separate cleanup evidence.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed key function objects: constructor `0x004d2720` size `0x23aa`, ordinary destructor `0x004d4ad0` size `0x497`, singleton-clear helper `0x004e5b80` size `0x0b`, and scalar deleting destructor `0x004e6460` size `0x3b`; the constructor still has no direct caller xrefs.
- 2026-06-16 constructor disassembly resolves the six `WeaponInfo` array family offsets: `swordtable.txt` at `0x004d2d61` passes `[edi+0x80]`, `speartable.txt` at `0x004d2d9b` passes `[edi+0xa0]`, `bowtable.txt` at `0x004d2dd5` passes `[edi+0xc0]`, `fantable.txt` at `0x004d2e0f` passes `[edi+0xe0]`, `shieldtable.txt` at `0x004d2e49` passes `[edi+0x100]`, and `arrowtable.txt` at `0x004d2e89` passes `[edi+0x120]` to the same `WeaponInfo` loader helper family.
- 2026-06-16 destructor disassembly reconfirmed all 18 frame-handle release offsets and three owned arrays at `+0x24c/+0x250/+0x254`. The absent local IDA UDT is preserved as negative symbol evidence; constructor/destructor/helper agreement closes the source layout independently.

## Score Rationale

Completion is `92` because the page records exact `0x2b0` size, direct Singleton EBO, all eighteen typed ProtectedArray members, three count/pointer pairs, four naturally aligned 16-bit counts, all eighteen named frame handles, constructor/destructor agreement, and class-covered declaration route. Confidence is `93`; exact offsets/types/roles are closed while original private spellings remain descriptive.

## Historical / Superseded Assumptions

- `cachedResource0..2`, at-least-`0x2b0`, and declaration-order-unresolved wording are superseded by the accepted draw-order and constructor/source-order analysis.
- No explicit Singleton field, EBO pad, short-alignment reserve, raw asset block, or generated vtable member belongs in source.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)

## Changes

### 2026-05-31 - Scored layout after current IDA verification

- What existed before: the layout page had detailed offset notes but was still scored `0/0` and not marked reconstructable.
- Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP on 2026-05-31 confirmed the HumanImageLib constructor, ordinary destructor, singleton-clear helper, and scalar deleting destructor function objects plus vtable/singleton xrefs. Existing destructor evidence documents the embedded `ProtectedArray` offsets, handle offsets, optional cached resource pointers, singleton clear, and vtable restore. Scores remain below 95 because final source field names, constructor declaration order, and the three cached pointer meanings are not exhaustively audited.

### 2026-06-08 - Batch 128 parent-gate layout refresh

- What existed before: the layout was `82/86` and reconstructable, but `AUTOGEN_PARENT_UID` was blank.
- Changed to: `COMPLETION:85`, `CONFIDENCE:87`, and `AUTOGEN_PARENT_UID:00006A`.
- Summary/evidence: A008 rechecked the direct parent [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) at `85/86` and used live IDA MCP `xrefs_to` to reconfirm constructor/destructor vtable stores and singleton writes/clears. The constructor page supplies table/resource-family evidence, while the destructor page supplies the exact embedded `ProtectedArray` cleanup offsets, optional cached-resource offsets, and 18 frame-handle offsets. The layout stays below the final-source gate because original member names, constructor declaration order, and cached pointer meanings remain open.

### 2026-06-16 - A002 Goal 2 source-quality refresh

- What existed before: the layout was `85/87`; the six `WeaponInfo` arrays were documented as likely family order rather than constructor-proven field mapping.
- Changed to: `COMPLETION:87`, `CONFIDENCE:89`, with the six equipment-family offsets recorded directly.
- Summary/evidence: live IDA MCP reconfirmed constructor/destructor/helper/scalar-wrapper function status, no direct constructor caller, vtable/singleton support, constructor xrefs for `swordtable.txt`, `speartable.txt`, `bowtable.txt`, `fantable.txt`, `shieldtable.txt`, and `arrowtable.txt` to object offsets `+0x80`, `+0xa0`, `+0xc0`, `+0xe0`, `+0x100`, and `+0x120`, destructor frame-handle cleanup offsets through `+0x2ac`, and the absence of a local `HumanImageLib` UDT. Final member names remain provisional.

### 2026-06-20 - B004 Rule 26 layout normalization

- What existed before: cached resources were described generically and the class parent score reference was stale.
- Changed to: kept source-facing layout family names, normalized the cached-resource placeholders to `cachedResource0..2`, updated the parent gate to [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) `88/88`, and made the destructor-release-order caveat explicit.
- Summary/evidence: B004 reanalysis accepts the current field family map but keeps final cached-resource names, all frame-handle member names, and declaration order unresolved.

### 2026-07-21 - B001 accepted UID0001PM layout closure

- Raised to `92/93`, inserted the class-covered formal marker, documented the exact EBO/object/member layout through `+0x2ac`, replaced cached-resource placeholders with draw-order arrays, fixed all frame handle names/order, and preserved historical negative-type evidence.
