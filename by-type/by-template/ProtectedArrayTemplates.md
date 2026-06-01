*** UID:0001WR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray Templates

## Status

- Confidence: strong for generated-template identity, medium for final declaration spelling.
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- Layout reference: [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md)

## Template Role

`ProtectedArray<T>` is a dynamic-array wrapper with a type-specific vtable, count, backing pointer, and inline fallback/default element. It is used by render asset libraries and the map nation-table path for fixed-size metadata records loaded from DAT tables.

The current `class_ProtectedArray_struct_*.cpp` files are generated template-instantiation views. They should be used as evidence for concrete `T` record sizes and emitted code addresses, not as proof that the original project had separate hand-written source files for each instantiation.

## Common Behavior

| Method family | Evidence | Behavior |
| --- | --- | --- |
| Ordinary destructor | `0x004e5a70-0x004e5b6f` | Resets the concrete vtable and frees the backing record array at offset `+0x08`. |
| Bounds-checked accessor | `0x004e5f20`, `0x004e5f40` | Returns `m_entries[index]` when `0 <= index < count`, otherwise returns the inline default record at `this + 0x10`. |
| Scalar deleting destructor | `0x004e5fa0-0x004e629f`, `0x00514d50` | Performs ordinary cleanup and conditionally deletes `this` when delete flag bit `1` is set. |

## IDA Verification Notes

- `0x004e5a70-0x004e5b6f` is a compact ordinary-destructor island in disassembly. Each 16-byte body writes a concrete `ProtectedArray<T>` vtable, frees the backing pointer at object offset `+0x08`, and returns.
- `0x004e5f20` and `0x004e5f40` decompile as bounds-checked accessors. Both read `count` at offset `+0x04`, `entries` at `+0x08`, return fallback storage at `+0x10` when out of range, and otherwise use concrete element strides (`0x10` for `HairInfo`, `0x14` for `Acc2Info`).
- `0x004e5fa0`, `0x004e6240`, and `0x00514d50` decompile as scalar deleting destructors with the same vtable reset and backing-pointer free pattern, followed by optional delete when flag bit `1` is set.
- `0x005039f0-0x00503a41` disassembly initializes an embedded `ProtectedArray<GameServerConfig::NationEntry>` object and proves the shared layout also applies outside the image-info island.
- `0x00514ee0` decompiles as a concrete nation-entry resize helper using 68-byte records, matching the `GameServerConfig::NationEntry` protected-array instantiation.

## Instantiation Evidence

| Instantiation | Ordinary destructor | Accessor | Deleting destructor | Owner |
| --- | --- | --- | --- | --- |
| `ProtectedArray<Acc1Info>` | `0x004e5a70` | - | `0x004e5fa0` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<Acc2Info>` | `0x004e5a80` | `0x004e5f40` | `0x004e5fd0` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<BodyInfo>` | `0x004e5a90` | - | `0x004e6000` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<CoatInfo>` | `0x004e5aa0` | - | `0x004e6030` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<EffectInfo>` | `0x004e5ab0` | - | `0x004e6060` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ProtectedArray<EffectPixMapInfo>` | `0x004e5ac0` | - | `0x004e6090` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ProtectedArray<FaceInfo>` | `0x004e5ad0` | - | `0x004e60c0` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HairInfo>` | `0x004e5ae0` | `0x004e5f20` | `0x004e60f0` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HeadInfo>` | `0x004e5af0` | - | `0x004e6120` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HelmetInfo>` | `0x004e5b00` | - | `0x004e6150` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<ItemInfo>` | `0x004e5b10` | - | `0x004e6180` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) |
| `ProtectedArray<LightInfo>` | `0x004e5b20` | - | `0x004e61b0` | [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) |
| `ProtectedArray<MantleInfo>` | `0x004e5b30` | - | `0x004e61e0` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<NecklaceInfo>` | `0x004e5b40` | - | `0x004e6210` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<ShoeInfo>` | `0x004e5b50` | - | `0x004e6240` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<WeaponInfo>` | `0x004e5b60` | - | `0x004e6270` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<GameServerConfig::NationEntry>` | - | - | `0x00514d50` | [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) |

## Generation Caveats

- 2026-05-26 current `class_ProtectedArray_struct_ShoeInfo_.cpp` now emits a normal scoped marker for ordinary destructor `0x004e5b50`, but the body is still omitted with a `WAVE3 OMITTED METHOD BODY` note. IDA still resolves `0x004e5b50` inside the broad old-human image-library function, so use [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) for the exact ordinary destructor body.
- IDA still confirms `0x004e6240-0x004e626f` as the `ProtectedArray<ShoeInfo>` scalar deleting destructor pattern.
- `ProtectedArray<GameServerConfig::NationEntry>` remains a concrete instantiation under map/server configuration ownership. Its generated file emits only scalar deleting destructor `0x00514d50`; do not move nation table records into the old render image-info island.

## Cross-References

- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000186][0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)

## Changes

- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `78`, confidence `86`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP verification now records the ordinary destructor island, accessor pair, scalar deleting destructors, GameServerConfig constructor bytes, and nation-entry resize helper. Scores remain below `95` because the original header spelling, complete declaration surface, and every concrete owner integration point still need a final audit before reconstructed C++ should be emitted.
