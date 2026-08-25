*** UID:0001WR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_PROTECTEDARRAY_H
#define NEXUSTK_UTIL_PROTECTEDARRAY_H

#include <string.h>

template <class T>
class ProtectedArray
{
public:
    explicit ProtectedArray(int defaultCapacity = 10)
        : m_count(0),
          m_entries(0),
          m_defaultCapacity(defaultCapacity),
          m_defaultEntry()
    {
    }

    virtual ~ProtectedArray()
    {
        delete [] m_entries;
    }

    T *GetAtOrDefault(int index)
    {
        if (index < 0 || index >= m_count)
            return &m_defaultEntry;

        return &m_entries[index];
    }

    void Resize(int count)
    {
        if (count <= 0 || count == m_count)
            return;

        T *entries = new T[count];
        if (m_entries != 0) {
            int copyCount = m_count;
            if (count < copyCount)
                copyCount = count;

            memmove(entries, m_entries, copyCount * sizeof(T));
            delete [] m_entries;
        }

        m_entries = entries;
        m_count = count;
    }

private:
    int m_count;
    T *m_entries;
    int m_defaultCapacity;
    T m_defaultEntry;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray Templates

## 2026-08-18 Formal Source Disposition

Formal H above is the complete reusable `ProtectedArray<T>` source owned by UID0000MU. Formal CPP is intentionally blank: concrete bodies are compiler/template instantiations, not a separately authored source family. Exact types, strides, sixteen ordinary destructors, three accessor shapes, GameServer resize specialization, scalar deleting wrappers, vtables, and all xrefs remain preserved. Score is `93/94`.

## Status

- Confidence: very strong for generated-template identity and direct reusable-template ownership, medium for final declaration spelling.
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- Layout reference: [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md)
- Autogen parent: attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) after this page reached `86/90` and the direct reusable template/header parent already cleared the strict `85/85` gate.

## Template Role

`ProtectedArray<T>` is a dynamic-array wrapper with a type-specific vtable, count, backing pointer, and inline fallback/default element. It is used by render asset libraries and the map nation-table path for fixed-size metadata records loaded from DAT tables.

The current `class_ProtectedArray_struct_*.cpp` files are generated template-instantiation views. They should be used as evidence for concrete `T` record sizes and emitted code addresses, not as proof that the original project had separate hand-written source files for each instantiation.

## Common Behavior

| Method family | Evidence | Behavior |
| --- | --- | --- |
| Ordinary destructor | `0x004e5a70-0x004e5b6f` | Resets the concrete vtable and frees the backing record array at offset `+0x08`. |
| Bounds-checked accessor | [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) | Source-ready `template <class T> T* GetAtOrDefault(int index)`: returns `&m_entries[index]` when `0 <= index < m_count`, otherwise returns `&m_defaultEntry`; the three documented image-info instantiation strides are `0x10`, `0x14`, and `0x0c`. |
| Positive-count resize | `0x00514ee0` and inline default-seeder copy at `0x00503b60` | Allocates `T[count]`, default-initializes new elements, preserves the overlapping old prefix with `memmove`, frees old storage, and updates `m_entries` / `m_count`; concrete `NationEntry` stride is `0x44` / 68 bytes (Verified with int_convert.py). |
| Scalar deleting destructor | `0x004e5fa0-0x004e629f`, `0x00514d50` | Performs ordinary cleanup and conditionally deletes `this` when delete flag bit `1` is set. |

## IDA Verification Notes

- `0x004e5a70-0x004e5b6f` is a compact ordinary-destructor island in disassembly. Each `0x10`-byte body (16 bytes, Verified with int_convert.py) writes a concrete `ProtectedArray<T>` vtable, frees the backing pointer at object offset `+0x08`, and returns.
- `0x004e5f20`, `0x004e5f40`, and `0x004e5f70` decompile as bounds-checked accessors. All three read `count` at offset `+0x04`, `entries` at `+0x08`, return fallback storage at `+0x10` when out of range, and otherwise use concrete element strides (`0x10` for `HairInfo`, `0x14` for `Acc2Info`, and `0x0c` for an unresolved old-human image-info record).
- `0x004e5fa0`, `0x004e6240`, and `0x00514d50` decompile as scalar deleting destructors with the same vtable reset and backing-pointer free pattern, followed by optional delete when flag bit `1` is set.
- `0x005039f0-0x00503a41` disassembly initializes an embedded `ProtectedArray<GameServerConfig::NationEntry>` object and proves the shared layout also applies outside the image-info island.
- `0x00514ee0` decompiles as a concrete nation-entry resize helper using `0x44`-byte records (68 bytes, Verified with int_convert.py), matching the `GameServerConfig::NationEntry` protected-array instantiation.

## 2026-06-11 A006 IDA Refresh

- `lookup_funcs` reconfirms that the ordinary image-info destructors at `0x004e5a70` and `0x004e5b60` remain folded into broad stale image-library functions, while the accessor helpers are exact standalone functions: `0x004e5f20` size `0x20`, `0x004e5f40` size `0x25`, and `0x004e5f70` size `0x25`.
- The same lookup pass reconfirms representative scalar deleting destructors at `0x004e5fa0`, `0x004e6270`, and `0x00514d50` as exact `0x2f` functions, and the NationEntry resize helper at `0x00514ee0` as an exact `0x8b` function.
- Decompilation of the three accessors still shows the shared `GetAtOrDefault` shape: compare the requested index against `this[1]`, return fallback storage at `this + 4` dwords on failure, and otherwise return `this[2] + stride * index` with strides `0x10`, `0x14`, and `0x0c` (16, 20, and 12 bytes, Verified with int_convert.py).
- Decompilation of `0x004e5fa0`, `0x004e6270`, and `0x00514d50` shows the same scalar-deleting-destructor template body: read the backing pointer at `Block[2]`, restore the concrete `ProtectedArray<T>` vtable, call `j_j_j___free_base`, test delete flag bit `1`, and conditionally call `sub_5C7526`.
- `xrefs_to` reconfirms old-human caller groups for the three accessors, single concrete vtable data refs for representative image deleting destructors (`0x0061b69c` and `0x0061b68c`), the NationEntry deleting-destructor vtable slot at `0x0061e704`, and the sole parser call to the resize helper at `0x00503d4f`.
- The page is not a mixed non-emitting aggregate: it represents the source-level `ProtectedArray<T>` template declaration and reusable emitted template bodies. Concrete image-library and map/game-server pages own the fields, parsing, and table lifetimes; this page and [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) own the reusable template source identity.

## 2026-06-29 B012 Accessor Body Refresh

- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) now carries the formal generic `ProtectedArray<T>::GetAtOrDefault(int index)` body for the image-info accessor cluster.
- Current MCP session `3fa0535f` reconfirmed `0x004e5f20` size `0x20` / 32 bytes, `0x004e5f40` size `0x25` / 37 bytes, and `0x004e5f70` size `0x25` / 37 bytes, with no function starts at `0x004e5f65` or `0x004e5f95` and `0x75` / 117 bytes for the whole documented cluster including padding (Verified with int_convert.py).
- The formal template body covers `ProtectedArray<HairInfo>` (`0x10` / 16-byte stride), `ProtectedArray<Acc2Info>` (`0x14` / 20-byte stride), and the unresolved 12-byte old-human image-info record (`0x0c` / 12-byte stride), all Verified with int_convert.py.
- `callees` remains empty for the three accessors. `xref_query` preserves old-human constructor/composition consumers rather than direct source ownership: 105 refs to `0x004e5f20`, 27 refs to `0x004e5f40`, and three refs to `0x004e5f70`.
- `search_structs` and `type_query` still find no local IDA records for the exact original `ProtectedArray`, `HairInfo`, `Acc2Info`, or 12-byte record declarations. This keeps final declaration/member spelling caveats, but it no longer blocks the generic accessor source body.
- Rejected alternatives remain explicit: no no-code/template-instantiation marker for UID000186, no direct `HumanImageLib` source ownership, and no three handwritten concrete wrappers.

## Instantiation Evidence

| Instantiation | Ordinary destructor | Accessor | Deleting destructor | Resize | Owner |
| --- | --- | --- | --- | --- | --- |
| `ProtectedArray<Acc1Info>` | `0x004e5a70` | - | `0x004e5fa0` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<Acc2Info>` | `0x004e5a80` | `0x004e5f40` | `0x004e5fd0` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<BodyInfo>` | `0x004e5a90` | - | `0x004e6000` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<CoatInfo>` | `0x004e5aa0` | - | `0x004e6030` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<EffectInfo>` | `0x004e5ab0` | - | `0x004e6060` | - | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ProtectedArray<EffectPixMapInfo>` | `0x004e5ac0` | - | `0x004e6090` | - | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| `ProtectedArray<FaceInfo>` | `0x004e5ad0` | - | `0x004e60c0` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HairInfo>` | `0x004e5ae0` | `0x004e5f20` | `0x004e60f0` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HeadInfo>` | `0x004e5af0` | - | `0x004e6120` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<HelmetInfo>` | `0x004e5b00` | - | `0x004e6150` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<ItemInfo>` | `0x004e5b10` | - | `0x004e6180` | - | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) |
| `ProtectedArray<LightInfo>` | `0x004e5b20` | - | `0x004e61b0` | - | [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) |
| `ProtectedArray<MantleInfo>` | `0x004e5b30` | - | `0x004e61e0` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<NecklaceInfo>` | `0x004e5b40` | - | `0x004e6210` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<ShoeInfo>` | `0x004e5b50` | - | `0x004e6240` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<WeaponInfo>` | `0x004e5b60` | - | `0x004e6270` | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<unknown 0x0c-byte old-human image info>` (12 bytes, Verified with int_convert.py) | - | `0x004e5f70` | - | - | [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) |
| `ProtectedArray<GameServerConfig::NationEntry>` | - | - | `0x00514d50` | `0x00514ee0` | [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) |

## Generation Caveats

- 2026-05-26 current `class_ProtectedArray_struct_ShoeInfo_.cpp` now emits a normal scoped marker for ordinary destructor `0x004e5b50`, but the body is still omitted with a `WAVE3 OMITTED METHOD BODY` note. IDA still resolves `0x004e5b50` inside the broad old-human image-library function, so use [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) for the exact ordinary destructor body.
- IDA still confirms `0x004e6240-0x004e626f` as the `ProtectedArray<ShoeInfo>` scalar deleting destructor pattern.
- `ProtectedArray<GameServerConfig::NationEntry>` remains a concrete instantiation under map/server configuration ownership. Its generated file emits only scalar deleting destructor `0x00514d50`; do not move nation table records into the old render image-info island.

## Cross-References

- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now records the shared template role, exact direct parent, layout offsets, ordinary/accessor/deleting-destructor families, representative image and NationEntry instantiations, caller/vtable evidence, and the first formal source-bearing `GetAtOrDefault` template body through [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md). |
| Confidence `91` | Current MCP session `3fa0535f` reconfirms the accessor boundaries, source body, no-callee status, xrefs, padding, negative type/struct searches, and NationEntry resize support. Confidence stays below final-audit range because the original header basename, final member names, 12-byte old-human record type, and full declaration surface remain unresolved. |

## 2026-06-29 B002 Empty-Emitter Implementation

This template support page now carries a formal no-code support comment. The reusable emitted bodies are represented by exact child pages: [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) for `GetAtOrDefault`, [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) for the ordinary destructor source body, [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) for compiler-generated scalar deleting destructor coverage, and [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) as the concrete GameServer resize specialization.

The page remains a source-level template identity page, but this bounded callback intentionally does not emit a full `ProtectedArray<T>` class declaration. Current blockers are still the exact original header basename, final member names, the unresolved 12-byte old-human record type, and the full safe declaration surface. The score rises to `88/92` because the empty-emitter state is resolved with a precise support marker while the declaration blockers are preserved.

## Changes

- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `78`, confidence `86`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP verification now records the ordinary destructor island, accessor pair, scalar deleting destructors, GameServerConfig constructor bytes, and nation-entry resize helper. Scores remain below `95` because the original header spelling, complete declaration surface, and every concrete owner integration point still need a final audit before reconstructed C++ should be emitted.
- 2026-06-08 A003 Batch122: Raised completion/confidence from `78/86` to `82/88`.
  - Before: the template page still listed only the `0x004e5f20` and `0x004e5f40` accessors.
  - After: added the `0x004e5f70` `0x0c`-stride accessor, recorded it in the common behavior and instantiation evidence tables, and clarified that its concrete old-human record name remains unresolved.
  - Summary/evidence: Batch122 IDA `lookup_funcs`, `decompile`, xref grouping, and byte review reconfirmed the third accessor and its shared `ProtectedArray<T>::GetAtOrDefault` shape.
- 2026-06-11 A006: Raised completion/confidence from `82/88` to `86/90` and set `AUTOGEN_PARENT_UID:0000MU`.
  - Before: the page had enough supporting evidence for the shared template but remained unassigned and did not explain why the type overview itself is a source-level template page rather than a mixed aggregate.
  - After: recorded the strict `85/85` gate decision through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), added a live IDA refresh covering accessor/deleting-destructor/NationEntry evidence, added score rationale, and left reconstruction C++ blank below the final-source `95/95` bar.
  - Summary/evidence: A006 IDA MCP `lookup_funcs`, `decompile`, `callees`, and `xrefs_to` reconfirmed the exact accessor sizes, `0x10`/`0x14`/`0x0c` strides, representative scalar deleting destructors, `0x0061e704` NationEntry vtable refs, sole resize parser call, and reusable-template ownership.
- 2026-06-19 B008 [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) implementation sync:
  - Score unchanged at `86/90`.
  - Added positive-count `Resize(int count)` as common template behavior and updated the `ProtectedArray<GameServerConfig::NationEntry>` evidence row to include deleting destructor `0x00514d50` and resize instantiation `0x00514ee0` through [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).
  - Summary/evidence: B008 local PE/Capstone confirmed the concrete resize body, the sole parser caller at `0x00503d4f` with `ecx = this + 4`, and the default-seeder's inline count-2 copy of the same template algorithm.
- 2026-06-29 B012 [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) implementation sync:
  - Raised score from `86/90` to `87/91`.
  - Added the accepted formal `ProtectedArray<T>::GetAtOrDefault(int index)` body as common template behavior for the three image-info accessor instantiations.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed exact function sizes, `0x10` / 16, `0x14` / 20, and `0x0c` / 12 byte strides, no callees, old-human caller groups, `0xcc` padding, and negative local type/struct evidence for the unresolved 12-byte record (Verified with int_convert.py where noted).
- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `87/91` to `88/92`.
  - Added the formal shared template support comment and preserved the no-full-declaration decision.
  - Summary/evidence: exact bodies now live on [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md), and the GameServer resize specialization [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md); full class declaration output remains blocked by unresolved header/member/type evidence.
