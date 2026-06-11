*** UID:0000MU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProtectedArray

## Status

- Confidence: strong for template role and shared utility placement, medium for exact original header filename.
- Proposed source artifact: `util/ProtectedArray.h` or an adjacent container header included by render/map sources.
- Current generated sources: `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp`
- Primary documented code islands: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)

## File Role

`ProtectedArray<T>` is a small vtable-bearing dynamic-array template with an inline fallback record. The image libraries embed concrete instantiations for asset metadata records, and `GameServerConfig` uses the same template for nation entries.

The generated one-class files are not good original source-file evidence. They represent compiler/template instantiations for concrete record types such as `ProtectedArray<HairInfo>`, `ProtectedArray<ItemInfo>`, and `ProtectedArray<GameServerConfig::NationEntry>`. Reconstructed source should keep the template declaration in a shared utility/header file, while the owning feature files keep their concrete fields and load logic.

2026-05-26 recheck using current `simroot_v2` and IDA MCP only: all 17 `class_ProtectedArray_struct_*.cpp` generated files are still present. The image-info files still emit mostly destructor support, `HairInfo` and `Acc2Info` still carry the only observed bounds-checked accessors, and `ProtectedArray_struct_GameServerConfig__NationEntry_` still emits only scalar deleting destructor `0x00514d50`. This remains template-instantiation evidence, not original one-file-per-type source evidence.

## Known Instantiations

| Source-level type | Current generated class | Owning module |
| --- | --- | --- |
| `ProtectedArray<Acc1Info>` | `ProtectedArray_struct_Acc1Info_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<Acc2Info>` | `ProtectedArray_struct_Acc2Info_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<BodyInfo>` | `ProtectedArray_struct_BodyInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<CoatInfo>` | `ProtectedArray_struct_CoatInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<FaceInfo>` | `ProtectedArray_struct_FaceInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HairInfo>` | `ProtectedArray_struct_HairInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HeadInfo>` | `ProtectedArray_struct_HeadInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HelmetInfo>` | `ProtectedArray_struct_HelmetInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<MantleInfo>` | `ProtectedArray_struct_MantleInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<NecklaceInfo>` | `ProtectedArray_struct_NecklaceInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<ShoeInfo>` | `ProtectedArray_struct_ShoeInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<WeaponInfo>` | `ProtectedArray_struct_WeaponInfo_` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<EffectInfo>` | `ProtectedArray_struct_EffectInfo_` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ProtectedArray<EffectPixMapInfo>` | `ProtectedArray_struct_EffectPixMapInfo_` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ProtectedArray<ItemInfo>` | `ProtectedArray_struct_ItemInfo_` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) |
| `ProtectedArray<LightInfo>` | `ProtectedArray_struct_LightInfo_` | [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) |
| `ProtectedArray<GameServerConfig::NationEntry>` | `ProtectedArray_struct_GameServerConfig__NationEntry_` | [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) |

## Evidence

- IDA disassembly confirms each ordinary image-info destructor resets the concrete `ProtectedArray<T>` vtable and frees the backing pointer at object offset `+0x08`.
- `HairInfo::GetAtOrDefault` at `0x004e5f20` uses a `0x10` byte stride and returns the fallback record at `this + 0x10` when the index is out of range.
- `Acc2Info::GetAtOrDefault` at `0x004e5f40` uses a `0x14` byte stride and the same fallback convention.
- The third image-info accessor at `0x004e5f70` uses a `0x0c` byte stride and the same fallback convention; its concrete old-human record name remains unresolved, but the source shape is the same `ProtectedArray<T>::GetAtOrDefault` template body.
- The deleting destructor island at [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) repeats the vtable reset, backing-buffer free, and conditional `operator delete` pattern for the image-info instantiations.
- `ProtectedArray<GameServerConfig::NationEntry>` has equivalent cleanup at `0x00514d50`, plus a concrete resize helper at [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md), but its code sits with the map/nation table neighborhood rather than the render image-info island.
- 2026-05-26 IDA MCP still reports ordinary image-info destructor starts inside broad image-library functions such as `sub_4D2720`, `sub_4DDF60`, `sub_4DEC30`, and `sub_4DF7E0`; the scalar deleting destructors and the two accessors are still modeled as compact standalone functions. Treat the ordinary-destructor starts as exact raw/template bodies even when IDA's owner function is too broad.

## Source-Structure Decision

Use `ProtectedArray` as a shared template/container artifact, not as many original `.cpp` files. The final source tree can expose it as `util/ProtectedArray.h`; concrete image-library and map modules should own their actual record parsing, globals, and lifetime policy.

## Parent-Gate Evidence

Batch122 confirms [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) as a direct child of this reusable template/header source artifact. IDA reconfirms three bounds-checked accessor bodies with the same control flow and offsets (`count` at `+0x04`, `entries` at `+0x08`, fallback at `+0x10`) and only stride/type differences (`0x10`, `0x14`, and `0x0c`). The caller groups are old-human constructor/composition consumers, but those consumers instantiate the template; they do not own the reusable accessor source body.

Batch132 confirms [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) as another direct child of this reusable template/header artifact. IDA reconfirms all sixteen `0x2f` scalar deleting destructors, one-byte `0xcc` stride padding, concrete image-info vtable/data refs, and the common template cleanup body. The neighboring `_AUTOBUF<unsigned char>` body at `0x004e62a0` is a boundary, not part of the ProtectedArray island.

The file now clears `85/85` for strict parent routing. Scores remain capped at `85` because the exact original header basename, final member spelling for the capacity/reserved field, and the full declaration surface still need a final-source pass.

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)

## Changes

- 2026-06-03 path and parent-link threshold update:
  - Before: confidence was `78` and projected path was blank even though the body proposed `util/ProtectedArray.h`.
  - After: confidence is `80` and projected path is `NexusTK/util/`.
  - Summary/evidence: the source-structure decision keeps reusable `ProtectedArray<T>` declarations in a shared utility/header artifact, while concrete image/map modules own their loaded record fields and parser logic. Confidence remains capped at the parent-link minimum because the exact original header basename is still inferred.
- 2026-06-08 A003 Batch122: Raised completion/confidence from `84/80` to `85/85`.
  - Before: the page documented the template role but did not include the third image-info accessor and remained below the corrected strict parent gate.
  - After: added the `0x004e5f70` `0x0c`-stride accessor, direct parent-gate evidence for [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), and exact cross-references to the image-info destructor/accessor/deleting-destructor islands.
  - Summary/evidence: Batch122 IDA `lookup_funcs`, `decompile`, xref grouping, and byte review reconfirmed the three accessors share the same template source shape while old-human code provides concrete instantiation/caller evidence.

- 2026-06-08 A003 Batch132: Added direct parent-gate evidence for [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); score unchanged at `85/85`.
  - Summary/evidence: Batch132 IDA recheck confirmed the sixteen image-info scalar deleting destructors share the reusable `ProtectedArray<T>` cleanup source shape, each has one concrete vtable-data reference, and the range ends before the separate `_AUTOBUF<unsigned char>` body.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents the template role, known instantiations, owner modules, IDA evidence, source-structure decision, and cross-references; confidence remains capped because this is template/header reconstruction evidence rather than a clean original `.cpp` file.
