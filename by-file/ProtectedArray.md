*** UID:0000MU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProtectedArray

## Status

- Confidence: strong for template role, medium for exact original filename.
- Proposed source artifact: `util/ProtectedArray.h` or an adjacent container header included by render/map sources.
- Current generated sources: `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp`
- Primary documented code islands: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000186][0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors.md), and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)

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
- The deleting destructor island at `0x004e5fa0-0x004e629f` repeats the vtable reset, backing-buffer free, and conditional `operator delete` pattern for the image-info instantiations.
- `ProtectedArray<GameServerConfig::NationEntry>` has equivalent cleanup at `0x00514d50`, plus a concrete resize helper at [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md), but its code sits with the map/nation table neighborhood rather than the render image-info island.
- 2026-05-26 IDA MCP still reports ordinary image-info destructor starts inside broad image-library functions such as `sub_4D2720`, `sub_4DDF60`, `sub_4DEC30`, and `sub_4DF7E0`; the scalar deleting destructors and the two accessors are still modeled as compact standalone functions. Treat the ordinary-destructor starts as exact raw/template bodies even when IDA's owner function is too broad.

## Source-Structure Decision

Use `ProtectedArray` as a shared template/container artifact, not as many original `.cpp` files. The final source tree can expose it as `util/ProtectedArray.h`; concrete image-library and map modules should own their actual record parsing, globals, and lifetime policy.

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents the template role, known instantiations, owner modules, IDA evidence, source-structure decision, and cross-references; confidence remains capped because this is template/header reconstruction evidence rather than a clean original `.cpp` file.
