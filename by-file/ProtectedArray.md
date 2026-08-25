*** UID:0000MU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ProtectedArray

## 2026-08-18 Complete Header-Only Source Route

- `NexusTK/util/ProtectedArray.h` is the reusable authored artifact. UID0001WR emits the complete template declaration and inline constructor, destructor, `GetAtOrDefault`, and `Resize`; there is no separately authored `ProtectedArray.cpp` compilation unit.
- Exact layout for each specialization is vptr `+0x00`, count `+0x04`, entries `+0x08`, default capacity `+0x0c`, and default entry `+0x10`, with size `0x10 + sizeof(T)`. Resize allocates, bounded-memmoves, deletes the old array, and updates entries/count; accessor returns the default entry for an out-of-range index.
- All known concrete ordinary destructors, accessors, deleting wrappers, vtables, strides, and caller groups remain retained compiler/template-instantiation evidence. The old standalone-CPP, incomplete-header, and old-human record-name blockers are historical rather than source blockers.
- This complete H route is the transitive declaration dependency used by LightObjImageLib. Score is `93/94`; unresolved old-human names remain evidence-only.

## Status

- Confidence: strong for template role and shared utility placement, medium for exact original header filename.
- Proposed source artifact: `util/ProtectedArray.h` or an adjacent container header included by render/map sources.
- Current generated sources: `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp`
- Primary documented code islands: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- B002 2026-06-29 direct empty-emitter closeout raises the page to `90/91`: the direct generated `auto-generated/NexusTK/util/ProtectedArray.cpp` family had 21 direct emitters, with [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) already filled and 20 accepted empty markers now dispositioned as exact body or no-code coverage comments.

## File Role

`ProtectedArray<T>` is a small vtable-bearing dynamic-array template with an inline fallback record. The image libraries embed concrete instantiations for asset metadata records, and `GameServerConfig` uses the same template for nation entries.

The generated one-class files are not good original source-file evidence. They represent compiler/template instantiations for concrete record types such as `ProtectedArray<HairInfo>`, `ProtectedArray<ItemInfo>`, and `ProtectedArray<GameServerConfig::NationEntry>`. Reconstructed source should keep the template declaration in a shared utility/header file, while the owning feature files keep their concrete fields and load logic.

`ProtectedArray<T>::Resize(int count)` is a positive-count dynamic-array replacement helper. It exits for `count <= 0` or unchanged count, array-allocates `T[count]`, lets `T` default construction initialize new slots, preserves `min(oldCount, count)` existing records with `memmove`, releases the old array, and updates `m_entries` / `m_count`. [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) is the concrete `GameServerConfig::NationEntry` emitted instantiation of this source body; the owning feature/output route remains [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).

B012's 2026-06-29 [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) callback makes `ProtectedArray<T>::GetAtOrDefault(int index)` the first source-bearing body in the current `ProtectedArray.cpp` empty-emitter priority. The formal generic body returns `&m_defaultEntry` for negative or out-of-range indexes and otherwise returns `&m_entries[index]`; current MCP session `3fa0535f` reconfirms the three concrete image-info instantiations at `0x004e5f20`, `0x004e5f40`, and `0x004e5f70`, with `0x10` / 16, `0x14` / 20, and `0x0c` / 12 byte strides respectively (Verified with int_convert.py). The source route remains this reusable template/header artifact even though the callers are old-human composition/render consumers.

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
- 2026-06-14 C001 IDA MCP refresh reconfirms the mixed raw/modeled shape: ordinary destructor starts `0x004e5a70`, `0x004e5a80`, and `0x004e5b60` still resolve inside broad `sub_4D2720` while the boundary helper at `0x004e5b70` is its own `0x0b` function; the three accessor starts are modeled as `0x004e5f20` size `0x20`, `0x004e5f40` size `0x25`, and `0x004e5f70` size `0x25`; image-info scalar deleting destructors at `0x004e5fa0` and `0x004e6270`, plus `GameServerConfig::NationEntry` cleanup at `0x00514d50`, are all `0x2f` functions.
- 2026-06-14 `xrefs_to` strengthens the reusable-template parent decision: `0x004e5f20` has more than 100 code refs across old-human render construction/composition consumers, `0x004e5f40` has 27 refs, and `0x004e5f70` has 3 refs; the scalar deleting destructors are vtable-data referenced from `0x0061b69c`, `0x0061b68c`, and `0x0061e704`, while `0x00514ee0` remains a concrete nation-entry resize helper called from `0x00503d4f`.
- 2026-06-14 `callees` shows the accessor trio has no callees, while scalar deleting destructors call only free/delete support and `0x00514ee0` calls allocator/memmove/free helpers. `int_convert` verifies the `0x0c` unresolved accessor stride as `12`, which keeps the template-source shape strong even though its exact old-human record name remains unresolved.
- 2026-06-29 B012 current MCP session `3fa0535f` resolves [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) from empty emitter to formal source body. `lookup_funcs` reconfirms exact accessor sizes `0x20` / 32, `0x25` / 37, and `0x25` / 37 bytes; `decompile`/`disasm` confirm the generic bounds-checked `GetAtOrDefault` body; `callees` reports no callees; `xref_query` preserves old-human constructor/composition caller groups of 105, 27, and 3 refs; `get_bytes` preserves `0xcc` alignment; `search_structs`/`type_query` still find no local type record for the unresolved 12-byte old-human accessor. Numeric conversions are verified with int_convert.py where documented.

## Source-Structure Decision

Use `ProtectedArray` as a shared template/container artifact, not as many original `.cpp` files. The final source tree can expose it as `util/ProtectedArray.h`; concrete image-library and map modules should own their actual record parsing, globals, and lifetime policy.

## Parent-Gate Evidence

Batch122 confirms [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) as a direct child of this reusable template/header source artifact. IDA reconfirms three bounds-checked accessor bodies with the same control flow and offsets (`count` at `+0x04`, `entries` at `+0x08`, fallback at `+0x10`) and only stride/type differences (`0x10`, `0x14`, and `0x0c`). The caller groups are old-human constructor/composition consumers, but those consumers instantiate the template; they do not own the reusable accessor source body.

Batch132 confirms [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) as another direct child of this reusable template/header artifact. IDA reconfirms all sixteen `0x2f` scalar deleting destructors, one-byte `0xcc` stride padding, concrete image-info vtable/data refs, and the common template cleanup body. The neighboring `_AUTOBUF<unsigned char>` body at `0x004e62a0` is a boundary, not part of the ProtectedArray island.

The file now clears `88/90` for strict parent routing and has one formal source-bearing accessor body through [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md). Scores remain below final-source confidence because the exact original header basename, final member spelling for the capacity/reserved field, the 12-byte old-human record type name, and the full declaration surface still need a final-source pass.

## 2026-06-29 B002 Direct Empty-Emitter Closeout

B002's accepted ProtectedArray report used live MCP session `supervisor_resume_20260629` for the current evidence pass: `server_health` was `ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays and string cache were ready, and a bounded `get_bytes` read at `0x00401000` returned `0x8b`. The report did not use fallback-only evidence.

The direct generated family inventory was `auto-generated/NexusTK/util/ProtectedArray.cpp` with 21 direct emitters, 1 filled emitter, and 20 empty emitters before this callback. The already-filled body is [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), which remains the generic `ProtectedArray<T>::GetAtOrDefault(int index)` body.

The accepted closeout does not hand-author a full template declaration. Instead:

- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) carries the shared source destructor body `ProtectedArray<T>::~ProtectedArray() { delete [] m_entries; }`.
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) is compiler-generated scalar deleting destructor coverage and should not hand-emit wrapper code or vtable writes.
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is shared template support and should not hand-author the full declaration until constructor/member-name evidence is complete.
- [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md) is layout evidence and should not emit a separate struct/layout declaration.
- The 16 image/render concrete class pages are source-declared/generated-binary template instantiation views. Their formal C++ blocks should contain no-code instantiation comments, not standalone class declarations.

The corrected concrete embedder UID/name table is:

| Instantiations | Concrete embedder |
| --- | --- |
| `Acc1Info`, `Acc2Info`, `BodyInfo`, `CoatInfo`, `FaceInfo`, `HairInfo`, `HeadInfo`, `HelmetInfo`, `MantleInfo`, `NecklaceInfo`, `ShoeInfo`, `WeaponInfo` | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `EffectInfo`, `EffectPixMapInfo` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ItemInfo` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) |
| `LightInfo` | [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) |

The stale candidate values `UID 0000JD` for `EffectObjImageLib`, `UID 0000KA` for `ItemObjImageLib`, and `UID 0000LB` for `LightObjImageLib` are rejected for this table. Current by-file headers and class pages prove the corrected UIDs above.

[UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md), [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md), [0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor](by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md), and [0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md) remain excluded from this direct callback because they route through [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md), not the direct `ProtectedArray.cpp` generated file. The latter two pages were referenced by filename rather than active UID syntax here because the scoped validator does not currently have `000372` or `0003II` in its UID registry.

The score is capped at `90/91`, not higher, because the exact original header basename, the `+0x0c` member spelling, the exact 12-byte old-human record type name, and the full safe template declaration surface remain unresolved after current MCP and type-query checks.

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
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `87/89`.
  - Summary/evidence: live IDA MCP reconfirmed raw ordinary-destructor starts inside broad image-library functions, modeled accessor/destructor/resize function sizes, high fan-in for reusable accessor instantiations, vtable-data refs for deleting destructors, and callee sets that separate simple accessors from cleanup/resize helpers. No owner/emitter routing changed; exact original header basename and final declaration spelling remain the blockers for a higher score.
- 2026-06-19 B008 [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) implementation sync:
  - Score unchanged at `87/89`.
  - Added common `ProtectedArray<T>::Resize(int count)` behavior and linked [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) as the concrete `GameServerConfig::NationEntry` emitted instantiation.
  - Summary/evidence: B008 local PE/Capstone recheck confirms the concrete body exits on nonpositive or unchanged count, allocates `T[count]`, default-initializes `NationEntry::nationId` to `-1`, preserves the overlapping old prefix with `_memmove`, frees the old array, and updates `m_entries` / `m_count`.
- 2026-06-29 B012 [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) empty-emitter implementation:
  - Raised score from `87/89` to `88/90`.
  - Added `ProtectedArray<T>::GetAtOrDefault(int index)` as a formal source-bearing template body emitted through this file's `NexusTK/util/` route.
  - Summary/evidence: current MCP session `3fa0535f` confirms the exact accessor range, stride, no-callee, caller-group, padding, and negative type/struct evidence; [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) now repairs one `ProtectedArray.cpp` empty marker without moving concrete old-human field/caller ownership away from [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
- 2026-06-29 B002 direct empty-emitter closeout:
  - Raised score from `88/90` to `90/91`.
  - Added current MCP/generated-inventory/source-disposition evidence for the direct `ProtectedArray.cpp` family, preserved unresolved declaration blockers, and recorded the corrected concrete embedder UID table.
  - Summary/evidence: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) now carries the shared destructor body, [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) carries scalar deleting destructor coverage, [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) and [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md) carry no-code support comments, and the 16 concrete image/render class pages carry no-code instantiation comments with corrected embedder UIDs.
