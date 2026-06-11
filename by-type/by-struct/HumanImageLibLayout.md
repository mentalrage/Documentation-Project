*** UID:0001UR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00006A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HumanImageLib Layout

## Status

- Confidence: strong for IDA-observed offsets, medium-high for final source field names.
- Owner class: [UID:00006A][HumanImageLib](by-class/HumanImageLib.md).
- Autogen parent: attached to [UID:00006A][HumanImageLib](by-class/HumanImageLib.md); this layout is `85/87` and the direct class parent is `85/86`, so the strict child/parent gate is satisfied.
- Evidence: IDA constructor/destructor/vtable xrefs, current IDA function-boundary verification, and destructor decompilation.

## Layout Summary

`HumanImageLib` embeds many `ProtectedArray<...Info>` members followed by cached resource pointers and loaded frame-library handles. The object state reaches at least `+0x2b0`.

```text
HumanImageLib
  +0x000  LObject/vtable
  +0x004  ProtectedArray<HeadInfo> headArray
  +0x020  ProtectedArray<HeadInfo> headSpecialArray
  +0x03c  ProtectedArray<BodyInfo> bodyArray
  +0x05c  ProtectedArray<CoatInfo> coatArray
  +0x080  ProtectedArray<WeaponInfo> weaponArray0
  +0x0a0  ProtectedArray<WeaponInfo> weaponArray1
  +0x0c0  ProtectedArray<WeaponInfo> weaponArray2
  +0x0e0  ProtectedArray<WeaponInfo> weaponArray3
  +0x100  ProtectedArray<WeaponInfo> weaponArray4
  +0x120  ProtectedArray<WeaponInfo> weaponArray5
  +0x140  ProtectedArray<FaceInfo> faceArray
  +0x15c  ProtectedArray<Acc1Info> acc1Array
  +0x17c  ProtectedArray<HairInfo> hairArray
  +0x19c  ProtectedArray<Acc2Info> acc2Array
  +0x1c0  ProtectedArray<HelmetInfo> helmetArray
  +0x1e0  ProtectedArray<MantleInfo> mantleArray
  +0x200  ProtectedArray<NecklaceInfo> necklaceArray
  +0x220  ProtectedArray<ShoeInfo> shoeArray
  +0x24c  optional cached image/resource pointer 0
  +0x250  optional cached image/resource pointer 1
  +0x254  optional cached image/resource pointer 2
  +0x268  loaded frame-library handle 0
  ...
  +0x2ac  loaded frame-library handle 17
```

The six `WeaponInfo` arrays likely correspond to the old equipment families `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, and `ARROW`, but the final offset-to-family order should be taken from constructor parsing before source field names are locked.

## Frame Handle Region

The destructor releases 18 frame-library handles at these exact object offsets:

```text
+0x268, +0x26c, +0x278, +0x270, +0x274, +0x280,
+0x284, +0x27c, +0x288, +0x28c, +0x294, +0x290,
+0x298, +0x29c, +0x2a0, +0x2a4, +0x2a8, +0x2ac
```

The unusual order is the destructor release order, not necessarily source declaration order.

## Notes

- The constructor writes [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md), installs the [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md), and initializes the embedded old-human `ProtectedArray` fields.
- The constructor calls [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) repeatedly for old human/equipment frame table families.
- 2026-06-08 A008 IDA MCP `xrefs_to` reconfirmed the class-lifetime anchors used for direct parent routing: constructor vtable store `0x004d278c`, destructor vtable restore `0x004d4afd`, constructor singleton writes `0x004d277b`/`0x004d2782`, destructor singleton clear `0x004d4f44`, and static clear helper write `0x004e5b80`.
- The generated `HumanImageLibAssetBlock { uint32_t words[153]; }` is a recovery placeholder for the large constructor body, not a final source-facing type.
- The generated destructor's `imageDataBlock + 0x21c-0x260` wording should be normalized to the IDA-confirmed object offsets `+0x268-+0x2ac` unless a later constructor pass proves an inner subobject base.

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
