** TARGET-REPORT-UID:0000MU **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID0000MU ProtectedArray Direct Empty-Emitter Family Source-Quality Report

## Scope And Status

Original report-only research for `[UID:0000MU]` `by-file/ProtectedArray.md`.

This report covers the direct `auto-generated/NexusTK/util/ProtectedArray.cpp` empty-emitter family. During the report-only pass it did not edit target/support by-* docs, generated files, coverage reports, validator/tool state, IDA databases, executed archives, supervisor ledgers, lock files, or lease files.

Report-only pass status: accepted for bounded implementation callback.

Implementation callback status: accepted batch applied; see `Implementation Callback Results`, the checked `Implementation Tracking Checklist`, and the updated `Claim And Incorporation Ledger`.

## 2026-06-29 Revision After Embedder UID Pause

This report was revised in place after the first implementation callback correctly paused before editing target/support docs. The pause found stale embedder UIDs in the concrete class-page replacement table, not in the current by-* docs. The exact insertion table below is now corrected and implementation-ready again.

Current class-page recheck:

| Class pages | Correct concrete embedder | Current evidence |
|---|---|---|
| `Acc1Info`, `Acc2Info`, `BodyInfo`, `CoatInfo`, `FaceInfo`, `HairInfo`, `HeadInfo`, `HelmetInfo`, `MantleInfo`, `NecklaceInfo`, `ShoeInfo`, `WeaponInfo` | `[UID:0000JY]` `HumanImageLib` | current `by-class/ProtectedArray_struct_*Info_.md` pages and `by-file/ProtectedArray.md` known-instantiation table |
| `EffectInfo`, `EffectPixMapInfo` | `[UID:0000IY]` `EffectObjImageLib` | current `by-class/ProtectedArray_struct_EffectInfo_.md`, `by-class/ProtectedArray_struct_EffectPixMapInfo_.md`, `by-file/EffectObjImageLib.md`, and `by-file/ProtectedArray.md` |
| `ItemInfo` | `[UID:0000KH]` `ItemObjImageLib` | current `by-class/ProtectedArray_struct_ItemInfo_.md`, `by-file/ItemObjImageLib.md`, and `by-file/ProtectedArray.md` |
| `LightInfo` | `[UID:0000KP]` `LightObjImageLib` | current `by-class/ProtectedArray_struct_LightInfo_.md`, `by-file/LightObjImageLib.md`, and `by-file/ProtectedArray.md` |

Rejected stale report entries:

| Affected class rows | Stale value | Correct value |
|---|---|---|
| `EffectInfo`, `EffectPixMapInfo` | UID 0000JD / `EffectObjImageLib` | `[UID:0000IY]` `EffectObjImageLib` |
| `ItemInfo` | UID 0000KA / `ItemObjImageLib` | `[UID:0000KH]` `ItemObjImageLib` |
| `LightInfo` | UID 0000LB / `LightObjImageLib` | `[UID:0000KP]` `LightObjImageLib` |

No target/support by-* docs were edited for this revision. The accepted ProtectedArray implementation recommendations remain otherwise unchanged: UID `00017V` gets the destructor body, UID `000187` gets the scalar-deleting wrapper comment, UID `0001WR` gets the template support comment, UID `0001VM` gets the layout evidence comment, UID `000186` remains already-present, and the GameServer rows remain excluded from the direct callback.

Pre-callback generated state captured during the report revision, from `auto-generated/NexusTK/util/ProtectedArray.cpp`:

| State | Evidence |
|---|---|
| Generated command | `validator-command-id: 000000001491` |
| Generated timestamp | `validator-refreshed-at: 2026-06-29T23:10:20-04:00` |
| Filled emitter | `[UID:000186]` `ProtectedArray<T>::GetAtOrDefault(int index)` |
| Empty emitters | 20 direct markers |
| Direct generated file path | `auto-generated/NexusTK/util/ProtectedArray.cpp` |

Pre-callback tracker state captured during the report revision, from `auto-generated/-ag-research-tracker.md`:

| UID | Target | Total | Filled | Empty | Filled % | Generated file |
|---|---|---:|---:|---:|---:|---|
| `0000MU` | `ProtectedArray` | 21 | 1 | 20 | 4.8 | `auto-generated/NexusTK/util/ProtectedArray.cpp` |

## MCP Availability And Session Facts

MCP was available for this report. I did not continue with fallback-only evidence.

Current live session used for evidence:

| Fact | Value |
|---|---|
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` |
| Protocol version | `2025-06-18` |
| Active session | `supervisor_resume_20260629` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Imagebase | `0x400000` |
| Worker PID | `17592` |
| `server_health` | `status: ok` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready, size `2067` |
| Bounded memory proof | `get_bytes` at `0x00401000`, size 1 returned `0x8b` |

No stale session was used.

## Target Summary

`ProtectedArray<T>` is a small vtable-bearing dynamic-array template with:

| Offset | Meaning |
|---:|---|
| `0x00` | vtable pointer |
| `0x04` | element count |
| `0x08` | backing element pointer |
| `0x0c` | constructor-initialized count/capacity-like field, still not source-named |
| `0x10` | inline default/fallback element |

Conversions verified with `int_convert.py` during this report:

| Hex | Decimal |
|---:|---:|
| `0x0c` | 12 |
| `0x10` | 16 |
| `0x14` | 20 |
| `0x2f` | 47 |
| `0x44` | 68 |
| `0x54` | 84 |
| `0x8b` | 139 |

The proposed source artifact remains a shared `util/ProtectedArray.h` or adjacent container header, not separate original source files for each generated concrete class page. `by-project-structure/proposed-source-tree.md` lists `util/ProtectedArray.h` and notes that concrete emitted instantiations belong to image-library modules and `GameServerConfig`, not one source file per generated class.

Current target blockers that should remain documented after implementation:

| Blocker | Current disposition |
|---|---|
| Exact original header basename | still unresolved |
| Exact source name of `+0x0c` field | still unresolved |
| Exact 12-byte old-human record type name | still unresolved |
| Full safe template declaration surface | not safe to hand-author in this batch |

These blockers do not prevent closing the direct empty emitters with exact bodies or no-code coverage comments where the binary artifact is compiler-generated or already covered by a shared template body.

## Direct Empty-Emitter Inventory

The direct 20 empty markers in `ProtectedArray.cpp` are:

| UID | Page | Current role | Recommended disposition |
|---|---|---|---|
| `0000AX` | `by-class/ProtectedArray_struct_Acc1Info_.md` | concrete template instantiation | no-code coverage comment |
| `0000AY` | `by-class/ProtectedArray_struct_Acc2Info_.md` | concrete template instantiation | no-code coverage comment, mention accessor body |
| `0000AZ` | `by-class/ProtectedArray_struct_BodyInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B0` | `by-class/ProtectedArray_struct_CoatInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B1` | `by-class/ProtectedArray_struct_EffectInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B2` | `by-class/ProtectedArray_struct_EffectPixMapInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B3` | `by-class/ProtectedArray_struct_FaceInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B5` | `by-class/ProtectedArray_struct_HairInfo_.md` | concrete template instantiation | no-code coverage comment, mention accessor body |
| `0000B6` | `by-class/ProtectedArray_struct_HeadInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B7` | `by-class/ProtectedArray_struct_HelmetInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B8` | `by-class/ProtectedArray_struct_ItemInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000B9` | `by-class/ProtectedArray_struct_LightInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000BA` | `by-class/ProtectedArray_struct_MantleInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000BB` | `by-class/ProtectedArray_struct_NecklaceInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000BC` | `by-class/ProtectedArray_struct_ShoeInfo_.md` | concrete template instantiation | no-code coverage comment |
| `0000BD` | `by-class/ProtectedArray_struct_WeaponInfo_.md` | concrete template instantiation | no-code coverage comment |
| `00017V` | `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md` | ordinary destructor island | emit shared template destructor body |
| `000187` | `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md` | scalar deleting destructor island | no-code compiler-wrapper coverage comment |
| `0001VM` | `by-type/by-struct/ProtectedArrayLayout.md` | layout evidence | no-code layout evidence comment |
| `0001WR` | `by-type/by-template/ProtectedArrayTemplates.md` | shared template support | no-code template support comment |

Already-filled related emitter:

| UID | Page | State |
|---|---|---|
| `000186` | `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md` | filled generic `GetAtOrDefault` body, no new edit needed |

Excluded related items:

| UID | Page | Reason excluded from direct `ProtectedArray.cpp` callback |
|---|---|---|
| `0000B4` | `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md` | routes through `GameServerConfig`, generated under UID `0000JP`, not a current direct marker in `ProtectedArray.cpp` |
| `000234` | `by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md` | concrete `Resize` specialization already routes through `GameServerConfig` |
| `000372` | `by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md` | concrete GameServer scalar deleting destructor, owner/emitter `0000B4` |
| `0003II` | `by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md` | vtable data, compiler-generated binary artifact |

## MCP Evidence

### Function Boundaries

`lookup_funcs` evidence:

| Address or range | MCP result | Interpretation |
|---|---|---|
| `0x004e5a70` through `0x004e5b6f` | starts resolve inside broader IDA functions, next exact helper starts `0x004e5b70` | 16 separate 16-byte ordinary destructor bodies embedded in an IDA range |
| `0x004e5f20` | exact `sub_4E5F20`, size `0x20` | `HairInfo` accessor, 16-byte element stride |
| `0x004e5f40` | exact `sub_4E5F40`, size `0x25` | `Acc2Info` accessor, 20-byte element stride |
| `0x004e5f70` | exact `sub_4E5F70`, size `0x25` | 12-byte old-human accessor |
| `0x004e5fa0` through `0x004e6270` | each exact scalar deleting destructor start, size `0x2f` | 16 concrete scalar deleting destructor wrappers |
| `0x004e629f` | not a function | inclusive end byte of deleting-destructor island |
| `0x004e62a0` | exact `sub_4E62A0`, size `0x4b` | next helper is outside ProtectedArray |
| `0x00514d50` | exact `sub_514D50`, size `0x2f` | GameServer `NationEntry` scalar deleting destructor |
| `0x00514ee0` | exact `sub_514EE0`, size `0x8b` | GameServer `NationEntry` `Resize` specialization |

### Decompilation

Accessor decompilation:

| Address | Decompiled behavior | Source conclusion |
|---|---|---|
| `0x004e5f20` | if index out of range, return `this + 4`; else return `entries + 16 * index` | already covered by generic `GetAtOrDefault` body at UID `000186` |
| `0x004e5f40` | if index out of range, return `this + 4`; else return `entries + 20 * index` | already covered by generic `GetAtOrDefault` body at UID `000186` |
| `0x004e5f70` | if index out of range, return `this + 4`; else return `entries + 12 * index` | already covered by generic `GetAtOrDefault` body at UID `000186` |

Representative scalar deleting destructor decompilation:

| Address | Decompiled behavior | Source conclusion |
|---|---|---|
| `0x004e5fa0` | set concrete `ProtectedArray<Acc1Info>` vtable, free backing pointer at `this+0x08`, conditionally `operator delete(this)` when flag bit 1 is set, return `this` | compiler-generated wrapper for source destructor |
| `0x004e6270` | same pattern for `ProtectedArray<WeaponInfo>` | compiler-generated wrapper for source destructor |
| `0x00514d50` | same pattern for `ProtectedArray<GameServerConfig::NationEntry>` | same wrapper pattern outside direct ProtectedArray.cpp route |

`Resize` decompilation at `0x00514ee0`:

| Behavior | Evidence |
|---|---|
| Only resizes for positive requested count different from current count | branch on `a2 > 0 && *(this+4) != a2` |
| Allocates `68 * count` bytes | `0x44` bytes per `NationEntry`, 68 decimal verified with `int_convert.py` |
| Initializes first word of each new record to `-1` | loop stepping 34 words, 68 bytes |
| Copies `68 * min(oldCount, newCount)` bytes from old backing array | `_memmove` call |
| Frees old backing array | `j_j_j___free_base` |
| Writes new backing pointer and new count | stores at `this+8` and `this+4` |

This confirms the shared `ProtectedArray<T>` template behavior, but the concrete generated `Resize` body remains routed through `GameServerConfig`, not direct UID `0000MU`.

### Bytes

`get_bytes` evidence:

| Region | Evidence | Conclusion |
|---|---|---|
| `0x004e5a70`, size 256 | 16 consecutive ordinary destructor bytelets of the form `push [this+8]`, write concrete vtable, call free, return | one source destructor body repeated across concrete template specializations |
| `0x004e5f20`, size 128 | three accessor bodies with `0xcc` padding after non-function ends | current UID `000186` body is correct and already filled |
| `0x004e5fa0`, size 768 | sixteen `0x2f` scalar deleting destructor wrappers, each followed by `0xcc` padding and concrete delete sizes | do not hand-author wrappers |
| `0x0061b670`, size 224 | protected-array RTTI/vtable dwords for image instantiations | class pages are concrete generated instantiations |
| `0x0061e700`, size 32 | `0x0061e704` points to `0x00514d50` | GameServer instantiation is parallel evidence, not direct UID `0000MU` output |

### Call Graph And Xrefs

`callees` evidence:

| Function | Callees |
|---|---|
| Accessors `0x004e5f20`, `0x004e5f40`, `0x004e5f70` | none |
| Representative deleting destructors `0x004e5fa0`, `0x004e6270`, `0x00514d50` | `j_j_j___free_base`, `sub_5C7526` |
| `Resize` `0x00514ee0` | `unknown_libname_19`, `_memmove`, `j_j_j___free_base` |

`xrefs_to` evidence:

| Target | Key xrefs |
|---|---|
| `0x004e5f20` | 105 refs from image composition paths and `sub_4D9180` |
| `0x004e5f40` | 27 refs from old-human constructor/composition paths and `sub_4D9180` |
| `0x004e5f70` | 3 refs from old-human composition paths |
| `0x004e5fa0` | vtable slot `0x0061b69c` |
| `0x004e6270` | vtable slot `0x0061b68c` |
| `0x00514d50` | vtable slot `0x0061e704` |
| `0x00514ee0` | code caller `0x00503d4f` inside `sub_503D10` |
| `0x0061b69c` | constructor, cleanup, ordinary destructor reset, scalar destructor reset refs |
| `0x0061b6ac` | constructor, cleanup, ordinary destructor reset, scalar destructor reset refs |
| `0x0061b68c` | multiple constructor/cleanup refs plus destructor resets |
| `0x0061e704` | GameServer constructor/cleanup/destructor refs |

### Type Negative

MCP type lookup did not recover source type names for these symbols:

| Query | Result |
|---|---|
| `search_structs ProtectedArray` | empty |
| `type_query *ProtectedArray*` | empty |
| `type_query *Acc2Info*` | empty |
| `type_query *HairInfo*` | empty |
| `type_query *NationEntry*` | empty |

This supports retaining the current caveats on exact original header/member names and not hand-authoring a full `ProtectedArray<T>` class declaration in this bounded callback.

## Existing Documentation Evidence

### `by-file/ProtectedArray.md`

Current metadata:

| Field | Value |
|---|---|
| `UID` | `0000MU` |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `90` |
| `PROPOSED_RECONSTRUCTION_PATH` | `NexusTK/util/` |
| `CANONICAL_OWNER` | `FILE` |

Important existing statements:

| Statement | Incorporation decision |
|---|---|
| `ProtectedArray<T>` is a dynamic-array template with fallback/default record | preserve |
| `GetAtOrDefault` is already filled by UID `000186` | preserve as already-present |
| `Resize(int count)` behavior is documented by `GameServerConfig::NationEntry` specialization UID `000234` | preserve, do not move direct route |
| Generated one-class files are template instantiation views, not original per-type source files | preserve and use as class-page no-code basis |
| Scores remain capped by unresolved header basename, `+0x0c` member name, 12-byte record type name, and declaration surface | preserve |

### Support Pages

| Page | Current facts | Implementation use |
|---|---|---|
| `by-type/by-template/ProtectedArrayTemplates.md` | UID `0001WR`, shared template support, source-level template identity, exact body children listed | add no-code template support comment, keep blockers |
| `by-type/by-struct/ProtectedArrayLayout.md` | UID `0001VM`, layout offsets and element sizes | add no-code layout evidence comment |
| `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md` | UID `00017V`, 16 ordinary destructor bytelets | emit shared `~ProtectedArray` body |
| `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md` | UID `000187`, 16 scalar deleting destructor wrappers | add compiler-wrapper coverage comment |
| `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md` | UID `000186`, filled exact generic accessor | no edit needed |
| `by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md` | UID `000234`, concrete resize specialization | exclude from direct callback, keep as GameServer evidence |

### Executed Report Leads

| Report | Relevant conclusion | Current report use |
|---|---|---|
| `executed-b-agent-research/B012/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md` | insert exact generic `GetAtOrDefault` body, do not add wrapper comments for the three accessor variants | already applied, no new edit |
| `executed-b-agent-research/B008/000234-GameServerNationEntryArrayResize-source-quality.md` | concrete `Resize` body belongs with GameServer route | exclude from direct `ProtectedArray.cpp` implementation |

No direct executed report for `TARGET-REPORT-UID:0000MU` was found.

## Ownership And Placement Decision

Ranked ownership:

| Rank | Candidate | Decision | Reason |
|---:|---|---|---|
| 1 | `UID0000MU` `ProtectedArray` | accepted for direct family | shared template/container source root and direct generated file owner |
| 2 | `UID0001WR` `ProtectedArrayTemplates` | support, not standalone top owner | source template identity belongs under target UID `0000MU` |
| 3 | 16 concrete class pages | support comments only | generated concrete instantiation views, not original per-type source files |
| 4 | image library embedders (`HumanImageLib`, `EffectObjImageLib`, `ItemObjImageLib`, `LightObjImageLib`) | rejected as source owner for template behavior | they contain/use instances but do not own the reusable container source |
| 5 | `UID0000B4` / `UID0000JP` GameServer route | rejected for this direct batch | valid parallel specialization route, not current direct `ProtectedArray.cpp` marker |

Heuristic risks and resolutions:

| Risk | Resolution |
|---|---|
| Treating scalar deleting destructors as hand-authored source | reject; add no-code compiler-wrapper coverage comment |
| Treating class pages as original class declarations | reject; add no-code instantiation coverage comments |
| Hand-authoring a full template declaration while `+0x0c` and header name remain unresolved | reject for this bounded callback |
| Moving GameServer `Resize` into direct `ProtectedArray.cpp` | reject; it already belongs to the GameServer route |
| Leaving high-score support pages blank | reject; fill with exact body or coverage comments so the generated file no longer has empty markers |

## Exact Implementation Recommendation

### Target Metadata

Recommended target metadata update:

| Page | Field | Current | Recommended |
|---|---|---|---|
| `by-file/ProtectedArray.md` | `COMPLETION` | `88` | `90` |
| `by-file/ProtectedArray.md` | `CONFIDENCE` | `90` | `91` |

Do not raise higher in this batch because exact header basename, the `+0x0c` field name, the unresolved 12-byte record type, and full declaration surface remain open.

Recommended support-score updates:

| UID | Page family | Current | Recommended | Reason |
|---|---|---|---|---|
| `00017V` | ordinary destructor island | `85/91` | `89/92` | exact shared destructor body backed by bytes/decompile |
| `000187` | scalar deleting destructor island | `85/91` | `88/92` | compiler-wrapper disposition backed by bytes/decompile |
| `0001WR` | template support | `87/91` | `88/92` | template support no-code coverage plus current MCP evidence |
| `0001VM` | layout support | `86/90` | `87/91` | layout evidence no-code coverage plus current MCP evidence |
| `0000AX` to `0000BD` image/render class pages | concrete class supports | `86/90` | `87/91` | concrete instantiation disposition resolved |

Do not change `UID0000B4`, `UID000234`, `UID000372`, or `UID0003II` in this callback.

### UID00017V Formal C++

Insert this exact formal C++ body on `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md`:

```cpp
template <class T>
ProtectedArray<T>::~ProtectedArray()
{
    delete [] m_entries;
}
```

Evidence:

| Evidence | Match |
|---|---|
| ordinary destructor bytelets free `this+0x08` | `delete [] m_entries;` |
| repeated vtable reset is compiler lowering | omitted from source |
| no scalar-delete flag handling in ordinary destructor island | handled separately by UID `000187` as compiler wrapper |

### UID000187 Formal C++ Comment

Insert this exact formal C++ comment on `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md`:

```cpp
// Compiler-generated scalar deleting destructors for concrete ProtectedArray<T> instantiations.
// Source cleanup is represented by ProtectedArray<T>::~ProtectedArray() at [UID:00017V].
// Do not hand-emit scalar-delete wrappers or vtable writes.
```

### UID0001WR Formal C++ Comment

Insert this exact formal C++ comment on `by-type/by-template/ProtectedArrayTemplates.md`:

```cpp
// Shared source/template support for ProtectedArray<T>.
// Exact emitted bodies are represented by child evidence pages such as [UID:000186],
// [UID:00017V], [UID:000187], and the GameServer resize specialization [UID:000234].
// Do not hand-author the full template declaration until constructor/member-name evidence is complete.
```

### UID0001VM Formal C++ Comment

Insert this exact formal C++ comment on `by-type/by-struct/ProtectedArrayLayout.md`:

```cpp
// Layout evidence for ProtectedArray<T>.
// The source declaration is represented by template support [UID:0001WR] and exact child bodies.
// Do not emit a separate struct or layout declaration from this evidence page.
```

### Concrete Class Page Formal C++ Comments

For the 14 concrete image/render class pages without a direct accessor, insert this exact pattern, replacing only the class template parameter and embedder UID/name with the table values below:

```cpp
// Concrete ProtectedArray<CLASS_NAME> template instantiation.
// Reusable source cleanup is represented by [UID:00017V] and compiler-wrapper coverage [UID:000187].
// Embedded record use remains with EMBEDDER_UID EMBEDDER_NAME; do not emit a standalone original source class here.
```

For the 2 concrete image/render class pages with direct accessor evidence, insert this exact pattern:

```cpp
// Concrete ProtectedArray<CLASS_NAME> template instantiation.
// Reusable source behavior is represented by [UID:000186], [UID:00017V], and compiler-wrapper coverage [UID:000187].
// Embedded record use remains with EMBEDDER_UID EMBEDDER_NAME; do not emit a standalone original source class here.
```

Class-page replacements:

| UID | CLASS_NAME | EMBEDDER_UID | EMBEDDER_NAME | Pattern |
|---|---|---|---|---|
| `0000AX` | `Acc1Info` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000AY` | `Acc2Info` | `[UID:0000JY]` | `HumanImageLib` | direct accessor |
| `0000AZ` | `BodyInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000B0` | `CoatInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000B1` | `EffectInfo` | `[UID:0000IY]` | `EffectObjImageLib` | no direct accessor |
| `0000B2` | `EffectPixMapInfo` | `[UID:0000IY]` | `EffectObjImageLib` | no direct accessor |
| `0000B3` | `FaceInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000B5` | `HairInfo` | `[UID:0000JY]` | `HumanImageLib` | direct accessor |
| `0000B6` | `HeadInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000B7` | `HelmetInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000B8` | `ItemInfo` | `[UID:0000KH]` | `ItemObjImageLib` | no direct accessor |
| `0000B9` | `LightInfo` | `[UID:0000KP]` | `LightObjImageLib` | no direct accessor |
| `0000BA` | `MantleInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000BB` | `NecklaceInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000BC` | `ShoeInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |
| `0000BD` | `WeaponInfo` | `[UID:0000JY]` | `HumanImageLib` | no direct accessor |

### Already-Present Item

Leave `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md` unchanged unless the validator requires only report ledger maintenance. Its current generated body is correct:

```cpp
template <class T>
T* ProtectedArray<T>::GetAtOrDefault(int index)
{
    if (index < 0 || index >= m_count)
        return &m_defaultEntry;

    return &m_entries[index];
}
```

## Validator Plan For Implementation Callback

Run scoped validation after applying the bounded batch:

1. `by-structure` or equivalent scoped validator for:
   - `by-file/ProtectedArray.md`
   - `by-type/by-template/ProtectedArrayTemplates.md`
   - `by-type/by-struct/ProtectedArrayLayout.md`
   - the 16 concrete `by-class/ProtectedArray_struct_*.md` image/render pages
   - `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md`
   - `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md`
2. Run the project scoped autogen/refresh path required by `by-structure.md` for UID `0000MU`.
3. Inspect `auto-generated/NexusTK/util/ProtectedArray.cpp`.
4. Expected generated result:
   - UID `000186` body remains filled.
   - UID `00017V` destructor body appears.
   - UID `000187`, `0001WR`, `0001VM`, and the 16 concrete class pages no longer produce empty-emitter markers.
   - Direct empty count for `ProtectedArray.cpp` becomes zero unless the validator rejects comment-only support pages.
5. If metadata repair or comment-only coverage is rejected by the validator/by-structure policy, stop and report the exact validator reason. Do not invent fallback full declarations.

## Implementation Callback Results

Callback application completed on 2026-06-29.

Leases:

- B002 previously held the in-progress ProtectedArray callback leases and released them with `python .\leaser.py B002 unlease` from `tools/leaser`; the command reported `Success` for the 20 still-leased support docs.
- B002 then acquired one fresh immediate lease set for all 21 in-scope by-* docs at `2026-06-30T03:47:28Z`, expiring `2026-06-30T03:52:28Z`.
- After the edit/validator batch, `python .\leaser.py B002 unlease` reported `Success` for all 21 in-scope docs.
- A final one-file B002 lease on `by-file/ProtectedArray.md` was taken only for the last `--wait-generated` freshness pass and then released with `python .\leaser.py B002 unlease E:\NTK\GhidraBridge\source-3\project-documentation\by-file\ProtectedArray.md`, which reported `Success`.
- Final lease inspection showed no B002 leases remaining. Later unrelated B005 leases may appear in `tools/leaser/Agents/current_leases.md`; they are not part of this callback.

Scoped validators, all from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
|---|---|---|---|---|---|---|
| `by-file/ProtectedArray.md` | `python .\tools\validator.py --mode file --file by-file/ProtectedArray.md --apply --queue-timeout 240` | `000000001651` | `2026-06-29T23:47:44-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md --apply --queue-timeout 240` | `000000001652` | `2026-06-29T23:47:52-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md --apply --queue-timeout 240` | `000000001653` | `2026-06-29T23:47:59-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-type/by-template/ProtectedArrayTemplates.md` | `python .\tools\validator.py --mode file --file by-type/by-template/ProtectedArrayTemplates.md --apply --queue-timeout 240` | `000000001654` | `2026-06-29T23:48:08-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-type/by-struct/ProtectedArrayLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/ProtectedArrayLayout.md --apply --queue-timeout 240` | `000000001655` | `2026-06-29T23:48:10-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_Acc1Info_.md` | scoped file validator | `000000001656` | `2026-06-29T23:48:22-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_Acc2Info_.md` | scoped file validator | `000000001657` | `2026-06-29T23:48:29-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_BodyInfo_.md` | scoped file validator | `000000001658` | `2026-06-29T23:48:30-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_CoatInfo_.md` | scoped file validator | `000000001659` | `2026-06-29T23:48:32-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_EffectInfo_.md` | scoped file validator | `000000001660` | `2026-06-29T23:48:34-04:00` | `0` | `1` | `reference_index_remove 0000JD`; `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_EffectPixMapInfo_.md` | scoped file validator | `000000001661` | `2026-06-29T23:48:36-04:00` | `0` | `1` | `reference_index_remove 0000JD`; `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_FaceInfo_.md` | scoped file validator | `000000001662` | `2026-06-29T23:48:38-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_HairInfo_.md` | scoped file validator | `000000001663` | `2026-06-29T23:48:39-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_HeadInfo_.md` | scoped file validator | `000000001664` | `2026-06-29T23:48:51-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_HelmetInfo_.md` | scoped file validator | `000000001666` | `2026-06-29T23:48:56-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_ItemInfo_.md` | scoped file validator | `000000001668` | `2026-06-29T23:48:59-04:00` | `0` | `1` | `reference_index_remove 0000KA`; `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_LightInfo_.md` | scoped file validator | `000000001670` | `2026-06-29T23:49:02-04:00` | `0` | `1` | `reference_index_remove 0000LB`; `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_MantleInfo_.md` | scoped file validator | `000000001672` | `2026-06-29T23:49:05-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_NecklaceInfo_.md` | scoped file validator | `000000001674` | `2026-06-29T23:49:08-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_ShoeInfo_.md` | scoped file validator | `000000001676` | `2026-06-29T23:49:10-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/ProtectedArray_struct_WeaponInfo_.md` | scoped file validator | `000000001677` | `2026-06-29T23:49:21-04:00` | `0` | `1` | `projected_stats_update`; `generated_refresh: deferred`. |
| `by-file/ProtectedArray.md` generated freshness | `python .\tools\validator.py --mode file --file by-file/ProtectedArray.md --apply --queue-timeout 240 --wait-generated` | `000000001688` | `2026-06-29T23:56:15-04:00` | `0` | `1` | `generated_refresh: completed`; validator reported `autogen_emitter_has_no_code: 406` and `generated_metadata_refresh: 280`, including `generated_metadata_refresh 0000MU auto-generated/NexusTK/util/ProtectedArray.cpp generated C++ metadata refreshed`. These were broad validator autogen notices, not target-specific ProtectedArray failures. |

Generated freshness:

- After queued older generated refreshes were allowed to pass, `auto-generated/NexusTK/util/ProtectedArray.cpp` was observed with `validator-command-id: 000000001707`, `validator-refreshed-at: 2026-06-29T23:57:03-04:00`, and `validator-refresh-source: foreground-generated-refresh`, which is newer than the final B002 wait-generated command `000000001688`. A final targeted header check later observed `validator-command-id: 000000001735`, `validator-refreshed-at: 2026-06-29T23:58:54-04:00`, also newer than B002 command `000000001688`.
- Queue-status checks used to interpret freshness: `000000001680` saw older generated-refresh jobs through `000000001677`; `000000001684` confirmed that queue drained; after the final foreground refresh, unrelated activity added later generated-refresh jobs, and queue-status `000000001732` showed the remaining queued generated-refresh jobs were `000000001694` and later while the ProtectedArray header was already `000000001707`.
- The generated file contains the UID `00017V` `delete [] m_entries;` destructor body, the UID `000187` compiler-wrapper no-code comment, the UID `0001WR` no-full-template-declaration comment, the UID `0001VM` no-separate-layout comment, and all 16 corrected concrete class comments.
- `rg` found no `Empty Emitter Marker`, `TODO: Empty`, or `EMPTY` text in `auto-generated/NexusTK/util/ProtectedArray.cpp` after the wait-generated pass.

## Implementation Tracking Checklist

- [x] Lease only the immediate target/support docs needed for the accepted batch, immediately before editing. Proof: B002 acquired the final 21-file lease set at `2026-06-30T03:47:28Z`, after releasing the prior in-progress B002 leases.
- [x] Update `by-file/ProtectedArray.md` score to `90/91` and add the current MCP/source-disposition summary without removing unresolved blockers. Proof: `by-file/ProtectedArray.md` now has `COMPLETION:90`, `CONFIDENCE:91`, the B002 direct empty-emitter closeout section, corrected embedder table, rejected stale UID notes, GameServer exclusions, and preserved blockers for header basename, `+0x0c` member name, 12-byte record type, and full safe template declaration.
- [x] Add UID `00017V` exact destructor body. Proof: `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md` formal block contains `template <class T> ProtectedArray<T>::~ProtectedArray() { delete [] m_entries; }`.
- [x] Add UID `000187` scalar deleting destructor coverage comment. Proof: `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md` formal block identifies compiler-generated scalar deleting destructors, delegates source cleanup to UID `00017V`, and says not to hand-emit wrappers or vtable writes.
- [x] Add UID `0001WR` template support coverage comment. Proof: `by-type/by-template/ProtectedArrayTemplates.md` formal block records shared template support, exact child evidence pages, the GameServer resize specialization reference, and the no-full-declaration blocker.
- [x] Add UID `0001VM` layout evidence coverage comment. Proof: `by-type/by-struct/ProtectedArrayLayout.md` formal block records layout evidence for `ProtectedArray<T>` and rejects a separate struct/layout declaration.
- [x] Add concrete instantiation comments to `0000AX`, `0000AY`, `0000AZ`, `0000B0`, `0000B1`, `0000B2`, `0000B3`, `0000B5`, `0000B6`, `0000B7`, `0000B8`, `0000B9`, `0000BA`, `0000BB`, `0000BC`, and `0000BD` using the corrected current embedder UID/name table. Proof: all 16 listed `by-class/ProtectedArray_struct_*.md` formal blocks now contain concrete-instantiation no-code comments; `Acc2Info` and `HairInfo` include UID `000186`, and the corrected embedders are `[UID:0000JY]` `HumanImageLib`, `[UID:0000IY]` `EffectObjImageLib`, `[UID:0000KH]` `ItemObjImageLib`, and `[UID:0000KP]` `LightObjImageLib`.
- [x] Preserve UID `000186` exactly as already filled. Proof: `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md` was not edited; generated `ProtectedArray.cpp` still contains the accessor body.
- [x] Exclude `0000B4`, `000234`, `000372`, and `0003II` from direct edits. Proof: no edits were made to the GameServer by-* docs; `by-file/ProtectedArray.md` documents that these rows route through `GameServerConfig`, not this direct callback. The unrelated pre-existing modified `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md` was not touched or validated by this callback.
- [x] Run scoped validators. Proof: command IDs `000000001651` through `000000001678` listed above; all in-scope file validators exited `0` with `ok: 1`, and no target-specific failures remained.
- [x] Inspect regenerated `auto-generated/NexusTK/util/ProtectedArray.cpp` freshness and marker state. Proof: header is current at `validator-command-id: 000000001678`, refreshed `2026-06-29T23:49:55-04:00`; no empty-marker text remains.
- [x] Release leases immediately after the edit/validator batch. Proof: final `python .\leaser.py B002 unlease` reported `Success` for all 21 files; the later one-file freshness lease on `by-file/ProtectedArray.md` was also released successfully. Final lease inspection shows no active B002 leases; unrelated B005 leases are outside this callback.
- [x] Update this report checklist and Claim And Incorporation Ledger during implementation callback with applied/already-present/excluded-with-reason proof. Proof: this section and ledger rows below now contain callback verification states and proof.
- [x] If implementation resumes after the 2026-06-29 pause, confirm the concrete class comments copy the corrected embedder UIDs and do not reintroduce stale values. Proof: `rg` confirmed no active stale UID 0000JD, UID 0000KA, or UID 0000LB links remain in `by-file/ProtectedArray.md` or the affected Effect/Item/Light class pages; validators removed stale reference-index entries for `0000JD`, `0000KA`, and `0000LB`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Implementation action | Verification state |
|---|---|---|---|---|
| C-0000MU-001 | MCP was available and current for this report. | `initialize`, `tools/list`, `idb_list`, `server_health`, `get_bytes 0x00401000` all succeeded on `supervisor_resume_20260629`. | incorporated into `by-file/ProtectedArray.md` B002 source-disposition summary and retained in this report; no new MCP dependency was introduced during callback implementation. | applied |
| C-0000MU-002 | `ProtectedArray.cpp` has 21 total direct emitters, 1 filled and 20 empty. | generated file header and tracker row. | incorporated into `by-file/ProtectedArray.md` generated inventory; callback closes the 20 accepted direct empty emitters through formal bodies/no-code comments. | applied |
| C-0000MU-003 | UID `000186` accessor body is already correctly filled. | generated body and B012 executed report; MCP decompile of `0x004e5f20`, `0x004e5f40`, `0x004e5f70`. | left unchanged in `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md`; generated `ProtectedArray.cpp` still shows the accessor body after final B002 command `000000001688` and final observed generated header `000000001735`. | already-present |
| C-0000MU-004 | UID `00017V` should emit a shared template destructor body. | ordinary destructor bytes free `this+0x08` across 16 specializations. | incorporated into `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md` formal C++ block and generated output. | applied |
| C-0000MU-005 | UID `000187` is compiler-generated scalar deleting destructor coverage. | 16 `0x2f` wrappers, vtable writes, flag-bit conditional delete. | incorporated into `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md` formal no-code block and generated output. | applied |
| C-0000MU-006 | The 16 image/render class pages are concrete template instantiation views, not original standalone source classes. | target docs, support pages, vtable xrefs, proposed source tree, and the 2026-06-29 recheck of current class-page embedder UID/name pairs. | incorporated into all 16 listed concrete class pages with corrected embedder UID/name pairs; stale rejected UIDs are plain text, not active reference links. | applied |
| C-0000MU-007 | `ProtectedArrayTemplates` should not receive a full class declaration in this batch. | unresolved header basename, `+0x0c` member name, 12-byte record type, MCP type negative. | incorporated into `by-type/by-template/ProtectedArrayTemplates.md` formal no-code support comment and preserved as a blocker in `by-file/ProtectedArray.md`. | applied |
| C-0000MU-008 | `ProtectedArrayLayout` should not emit a separate struct/layout declaration. | layout is evidence for the template, not a separate source artifact. | incorporated into `by-type/by-struct/ProtectedArrayLayout.md` formal no-code layout comment. | applied |
| C-0000MU-009 | GameServer `NationEntry` specialization is excluded from the direct `ProtectedArray.cpp` callback. | UID `0000B4`, UID `000234`, UID `000372`, UID `0003II` route through `GameServerConfig`; current generated file has no `0000B4` marker. | excluded from direct edits with reason in `by-file/ProtectedArray.md`; no GameServer by-* doc was edited or validated for this callback. | excluded-with-reason |
| C-0000MU-010 | Target score can rise conservatively to `90/91`, not higher. | direct empty-marker disposition is implementation-ready, but declaration blockers remain. | applied to `by-file/ProtectedArray.md` metadata and score rationale; validator command `000000001651` and wait-generated command `000000001688` passed. | applied |
| C-0000MU-011 | Support pages can receive modest score updates. | current MCP evidence refresh and exact coverage disposition. | applied to UID `00017V` (`89/92`), UID `000187` (`88/92`), UID `0001WR` (`88/92`), UID `0001VM` (`87/91`), and the 16 concrete class pages (`87/91`). | applied |
| C-0000MU-012 | No fallback-only evidence was used. | live MCP evidence pass completed successfully. | retained in `by-file/ProtectedArray.md` B002 closeout and this report; implementation did not add fallback-only evidence. | applied |
| C-0000MU-013 | The original class-page insertion table contained stale embedder UID links and has been corrected before implementation. | Current `by-file/ProtectedArray.md`, current concrete class pages, and by-file headers show `EffectObjImageLib` as `[UID:0000IY]`, `ItemObjImageLib` as `[UID:0000KH]`, and `LightObjImageLib` as `[UID:0000KP]`; HumanImageLib rows remain `[UID:0000JY]`. | incorporated into `by-file/ProtectedArray.md` and all 16 concrete class comments; validators removed stale reference-index entries for `0000JD`, `0000KA`, and `0000LB`. | applied |

## Completion Criteria For This Report

This report is complete for report-only status because it provides:

| Required item | Status |
|---|---|
| Direct UID target and generated-file inventory | complete |
| MCP-backed evidence | complete |
| Existing documentation and executed-report incorporation | complete |
| Ownership and rejected-candidate analysis | complete |
| Exact implementation-ready C++ body/comment text | complete |
| Corrected concrete class embedder UID/name insertion table | complete |
| Exclusions with reasons | complete |
| Implementation callback checklist with proof | complete |
| Claim And Incorporation Ledger callback states | complete |

FINISHED_REPORT

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000MU-ProtectedArray-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000MU-ProtectedArray-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T00:02:39","uid":"0000MU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
