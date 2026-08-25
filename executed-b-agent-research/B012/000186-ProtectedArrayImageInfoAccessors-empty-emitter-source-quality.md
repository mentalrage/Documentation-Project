** TARGET-REPORT-UID:000186 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000186 ProtectedArrayImageInfoAccessors Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: repair [UID:000186] as the first source-bearing `ProtectedArray<T>::GetAtOrDefault(int index)` template accessor body emitted through [UID:0000MU] `ProtectedArray`, not as a `HumanImageLib` handwritten helper and not as a no-code marker.
- Final disposition: no split, merge, rename, owner change, or emitter-route change. The exact target remains `0x004e5f20-0x004e5f95`, containing three concrete template instantiations plus two `0xcc` alignment pads.
- Required action after supervisor acceptance: add the formal template accessor body to the target `RECONSTRUCTION_CPP CODE`, raise the target to `88/91`, refresh the target/support docs with live MCP session `3fa0535f` evidence, and validate with generated `ProtectedArray.cpp` freshness.
- Confidence: very strong for boundaries, behavior, owner/emitter route, and C++ source shape; medium-high for the exact original header basename, exact member spelling, and the concrete name of the `0x0c` / 12-byte old-human image-info record.

## Target

- Target UID: `000186`
- Target path: `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md`
- Required report path: `tools/leaser/Agents/Agent-B012/research/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`, [UID:0000MU] `by-file/ProtectedArray.md`, `auto-generated/NexusTK/util/ProtectedArray.cpp`, currently `0/21` filled.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000MU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MU`, blank `EMITTER_POSITION_OPTIONAL`, empty formal C++ block.
- Current generated state: `auto-generated/NexusTK/util/ProtectedArray.cpp` header `validator-command-id: 000000001094`, refreshed `2026-06-29T19:21:38-04:00`, with [UID:000186] shown as `Empty Emitter Marker`.

## Current Target State

The target is not empty because ownership is unknown. It is empty because the by-memory page has valid source routing through [UID:0000MU] and satisfies the current combined-score/emitter C++ gate, but the formal `RECONSTRUCTION_CPP CODE` block is blank.

Existing documentation already records the key model: these are concrete old-human image-info instantiations of a reusable `ProtectedArray<T>` template accessor. `HumanImageLib` owns the concrete fields and caller context, while `ProtectedArray` owns the reusable source body. The remaining source-quality blockers are header/name polish, not behavioral blockers.

## Executive Recommendation

Insert this exact formal C++ body into [UID:000186] if the supervisor accepts the report:

```cpp
template <class T>
T* ProtectedArray<T>::GetAtOrDefault(int index)
{
    if (index < 0 || index >= m_count)
        return &m_defaultEntry;

    return &m_entries[index];
}
```

This one generic template body is the most source-shaped representation of all three concrete binary bodies in the target range. It explains:

- `0x004e5f20`: `ProtectedArray<HairInfo>` with `0x10` / 16-byte stride (Verified with int_convert.py).
- `0x004e5f40`: `ProtectedArray<Acc2Info>` with `0x14` / 20-byte stride (Verified with int_convert.py).
- `0x004e5f70`: unresolved old-human image-info record with `0x0c` / 12-byte stride (Verified with int_convert.py).

Do not emit three handwritten concrete wrappers unless the generator cannot tolerate the template form. Three specializations would match the binary but would be less faithful to the likely original source shape.

## Supervisor Active Recheck

- Triggering instruction: supervisor assigned B012 to a report-only pass for [UID:000186] from the temporary empty-emitter priority because `ProtectedArray.cpp` is `0/21` filled.
- MCP state: `idb_list` rechecked the current active IDB-backed session before evidence use. Session `3fa0535f` is active for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `16844`, `is_analyzing:false`.
- `server_health(3fa0535f)`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, string cache size `2067`.
- Split need: no split. The range is a deliberate three-instantiation accessor cluster plus alignment. There is no missing body between `0x004e5f65-0x004e5f70`, and the next function begins at `0x004e5fa0`.
- Report-only scope: no leases, no by-* edits, no generated/manual coverage/tool/IDA/executed/supervisor edits, and no validators in this pass.

## Inference Research Guidance Check

I treated generated source and old reports as leads, not authority. The live IDA MCP recheck validates the function boundaries, decompile shape, disassembly constants, xref groups, callee absence, vtable-name evidence, type/struct negative checks, and generated empty-marker state.

No Wave2/Wave3 artifact was used as authority. The generated names `ProtectedArray_struct_*` remain search aliases and concrete instantiation labels, but the source-facing model should be `ProtectedArray<T>` in a shared utility/header source artifact.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision |
| --- | --- | --- |
| Empty emitter cause | Target has `CANONICAL_OWNER:0000MU`, `EMITTER_UIDS:0000MU`, `RECONSTRUCTABLE:TRUE`, and `85/90`; generated `ProtectedArray.cpp` still shows an empty marker. | The blocker is missing formal C++ text, not owner routing. |
| Template vs handwritten source | All three bodies have the same bounds-check/fallback/entry-index logic and differ only by `sizeof(T)` stride. | Emit one generic `ProtectedArray<T>::GetAtOrDefault(int index)` body. |
| Direct owner | Current target, parent file, template support, class instantiation docs, and caller context all route reusable source to [UID:0000MU]. | Keep `CANONICAL_OWNER:0000MU`; do not switch to `HumanImageLib`. |
| Concrete feature owner | Xrefs are old-human constructor/composition consumers; `HumanImageLib` embeds the arrays. | Keep `HumanImageLib` as concrete field/caller owner only. |
| Range and padding | `lookup_funcs` finds three exact functions and no functions at `0x004e5f65` or `0x004e5f95`; `get_bytes` shows `0xcc` padding after second and third bodies. | Keep single cluster range and document padding; no child split needed. |
| Accessor return type | Decompile returns pointer values; callers read fields through returned `eax`; source accessor returns address of fallback or dynamic entry. | `T* GetAtOrDefault(int index)` is source-shaped. |
| Member names | Layout/support docs consistently use `m_count`, `m_entries`, and `m_defaultEntry`; binary proves offsets but not exact source spelling. | Use these project-standard descriptive names in first-draft C++; keep exact spelling caveat. |
| Unknown `0x0c` record | Caller context proves it is another old-human image-info record at `this + 0x140`; `search_structs`/`type_query` find no concrete type record. | Keep concrete name unresolved. Generic template C++ avoids inventing a false type name. |
| Header basename | [UID:0000MU] proposes `util/ProtectedArray.h`; generated output is `ProtectedArray.cpp`; no source/path proof recovers exact original basename. | Continue using `ProtectedArray` source root and note likely header-style template body. |
| No-code marker alternative | The body is compact, source-shaped, reconstructable, routed, and above the current C++ gate. | Reject no-code marker. Use real first-draft C++. |

## Evidence Standards Used

- Direct IDA MCP fact: `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xref_query`, `callees`, `get_bytes`, `search_text`, `insn_query`, `search_structs`, `type_query`, and `entity_query`.
- Documentation evidence: target page, [UID:0000MU] `ProtectedArray`, [UID:0001WR] `ProtectedArrayTemplates`, [UID:0001VM] `ProtectedArrayLayout`, [UID:0000JY] `HumanImageLib`, concrete `ProtectedArray<HairInfo>` and `ProtectedArray<Acc2Info>` class docs, generated `ProtectedArray.cpp`, generated research tracker, generated by-memory coverage.
- Prior-report leads checked: executed B008 `000234-GameServerNationEntryArrayResize-source-quality.md`; executed B004 `00006A-HumanImageLib-class-source-quality.md`; broader report search found references but no prior B-agent report whose primary target was UID000186.
- Numeric conversion evidence: local `python .\tools\int_convert.py` verified `0x10` / 16, `0x14` / 20, `0x0c` / 12, `0x20` / 32, `0x25` / 37, and `0x75` / 117.

## Evidence Checked

- MCP availability: active session `3fa0535f` verified with `idb_list`; health ok.
- Function lookup: `0x004e5f20`, `0x004e5f40`, `0x004e5f65`, `0x004e5f70`, `0x004e5f95`, and successor `0x004e5fa0`.
- Decompile/disassembly: all three accessors with address markers and instruction listings.
- Xrefs: full code xref grouping for all three accessors with `count=5000`, `include_fn:true`.
- Callees: all three accessors have no callees.
- Bytes/padding: `get_bytes 0x004e5f20 size 128`.
- Caller context: exact `sub_4E5F70` callsites searched and short instruction windows checked at `0x004d5878`, `0x004d65db`, and `0x004d97df`.
- Type/name checks: `search_structs ProtectedArray`, `HairInfo`, `Acc2Info`, and `type_query` for `*ProtectedArray*`, `*HairInfo*`, `*Acc2Info*`, `*ImageInfo*` returned no local project type records; vtable names in `.rdata` confirmed concrete template identities for known image-info types.
- Report search terms: `000186`, `0x004e5f20`, `ProtectedArrayImageInfoAccessors`, `ProtectedArray.cpp`, `ProtectedArray<T>`, `ProtectedArrayImageInfo`, `GetAtOrDefault`, `0x004e5f70`, `0x0c`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000186 empty marker is caused by blank formal C++, not missing owner/emitter routing. | Very high | Target metadata plus generated `ProtectedArray.cpp` empty marker. | Target Status; Generated-state note. | incorporate | applied - target Status and 2026-06-29 B012 section identify the accepted repair as formal C++; generated `ProtectedArray.cpp` now emits UID000186 code instead of an empty marker. |
| C02 | Current MCP session is `3fa0535f`, IDB-backed, healthy, and ready. | Very high | `idb_list`, `server_health`. | Target evidence/MCP provenance. | incorporate | applied - target Status, Item Summary, and 2026-06-29 B012 section record session `3fa0535f` and health/readiness evidence. |
| C03 | Function cluster remains `0x004e5f20-0x004e5f95`, size `0x75` / 117 bytes including padding (Verified with int_convert.py). | Very high | `lookup_funcs`, `get_bytes`, int_convert.py. | Target range/boundary evidence. | incorporate | applied - target Item Summary and B012 section preserve exact cluster span, padding, and size conversion proof. |
| C04 | `0x004e5f20` is `sub_4E5F20`, size `0x20` / 32 bytes (Verified with int_convert.py), `ProtectedArray<HairInfo>` stride `0x10` / 16 bytes (Verified with int_convert.py). | Very high | `lookup_funcs`, `decompile`, `disasm`, int_convert.py. | Target function table; template support. | incorporate | applied - target B012 evidence, ProtectedArray file note, template support note, layout note, and HairInfo class sync record the function size/stride facts. |
| C05 | `0x004e5f40` is `sub_4E5F40`, size `0x25` / 37 bytes (Verified with int_convert.py), `ProtectedArray<Acc2Info>` stride `0x14` / 20 bytes (Verified with int_convert.py). | Very high | `lookup_funcs`, `decompile`, `disasm`, int_convert.py. | Target function table; template support. | incorporate | applied - target B012 evidence, ProtectedArray file note, template support note, layout note, and Acc2Info class sync record the function size/stride facts. |
| C06 | `0x004e5f70` is `sub_4E5F70`, size `0x25` / 37 bytes (Verified with int_convert.py), unresolved old-human record stride `0x0c` / 12 bytes (Verified with int_convert.py). | Very high behavior, medium type name | `lookup_funcs`, `decompile`, `disasm`, `search_structs` negative. | Target function table; layout/template caveat. | incorporate | applied - target B012 evidence, ProtectedArray file note, template support note, and layout note preserve the unresolved 12-byte record without inventing a concrete type name. |
| C07 | `0x004e5f65` and `0x004e5f95` are not function starts; padding after the second and third bodies is `0xcc`. | Very high | `lookup_funcs`, `get_bytes`. | Target range/padding section. | incorporate | applied - target B012 section records non-function starts and `0xcc` padding; range remains unsplit. |
| C08 | All three accessors compare signed `index < 0`, reject `index >= m_count`, return `&m_defaultEntry` on failure, otherwise return `&m_entries[index]`. | Very high | `decompile`, `disasm`. | Target behavior; formal C++ block. | incorporate | applied - target formal C++ block contains the accepted generic body; target/support notes describe the same behavior. |
| C09 | All three accessors have no callees. | Very high | `callees` for `0x004e5f20`, `0x004e5f40`, `0x004e5f70`. | Target negative evidence. | incorporate | applied - target B012 section, ProtectedArray file note, template note, and class sync notes record no-callee status. |
| C10 | Xrefs group as old-human constructor/composition consumers: `0x004e5f20` has 105, `0x004e5f40` has 27, `0x004e5f70` has 3. | Very high | `xref_query count=5000 include_fn:true`. | Target caller inventory; HumanImageLib support. | incorporate | applied - target B012 section and support notes preserve 105/27/3 caller grouping; optional HumanImageLib edit excluded because existing file already states the source-owner split at adequate detail. |
| C11 | `0x004e5f20` xrefs split into one `sub_4D2720` constructor ref at `0x004d4977`, 26 no-IDA-function old-human composition refs `0x004d58bd-0x004d696a`, and 78 refs in `sub_4D9180` `0x004d9348-0x004da6e8`. | High | `xref_query`. | Target caller inventory. | incorporate | applied - target B012 section records the exact split. |
| C12 | `0x004e5f40` xrefs split into three constructor refs `0x004d4860-0x004d48e4`, three no-IDA-function old-human composition refs `0x004d5947-0x004d66aa`, and 21 refs in `sub_4D9180`. | High | `xref_query`; concrete class doc corroboration. | Target caller inventory; Acc2 class doc. | incorporate | applied - target B012 section and Acc2Info support sync record the exact split/count. |
| C13 | `0x004e5f70` xrefs are `0x004d5878`, `0x004d65db`, and `0x004d97df`; the first two are currently no-IDA-function code and the last is in `sub_4D9180`. | High | `xref_query`, `search_text`, `insn_query`. | Target caller inventory; unresolved 12-byte record note. | incorporate | applied - target B012 section records the exact callsites and unresolved 12-byte record caveat. |
| C14 | The third accessor call contexts use old-human image/composition data (`word [record+4] - 0xc8`, receiver `this + 0x140`, reads from returned `+4`/`+8` fields), but do not prove the concrete record type name. | Medium-high | Instruction windows around `0x004d5878`, `0x004d65db`, `0x004d97df`; negative type searches. | Target open questions; layout/template support. | incorporate | applied - target B012 section and layout/template support preserve the source-name caveat and reject inventing a type name. |
| C15 | `.rdata` names confirm known concrete template vtables for `HeadInfo`, `BodyInfo`, `CoatInfo`, `WeaponInfo`, `FaceInfo`, `Acc1Info`, `HairInfo`, `Acc2Info`, `HelmetInfo`, `MantleInfo`, `NecklaceInfo`, `ShoeInfo`, then `HumanImageLib`; no vtable name identifies the `0x0c` accessor type. | High | `entity_query names 0x0061b670-0x0061b6d8`. | Target/type support; rejected type-name proof. | incorporate | applied - target B012 section records known vtable-name evidence and absence of a 12-byte accessor type name. |
| C16 | Direct owner/emitter should remain [UID:0000MU] `ProtectedArray`; [UID:0000JY] `HumanImageLib` remains concrete field/caller owner only. | Very high | Current docs, xref grouping, template body shape. | Target Ownership; ProtectedArray/HumanImageLib support. | incorporate | applied - target Ownership, ProtectedArray file note, template support, and existing HumanImageLib note preserve direct `ProtectedArray` source ownership and `HumanImageLib` concrete caller/field ownership. |
| C17 | Formal C++ should be the generic template `T* ProtectedArray<T>::GetAtOrDefault(int index)` body, not three handwritten wrappers and not a no-code marker. | High | Shared decompile shape, current C++ gate, source-shape inference, B008 template policy precedent. | Target C++ block; template support. | incorporate | applied - target formal block contains the generic template body; target/template/class support explicitly reject no-code and handwritten wrapper alternatives. |
| C18 | Target score should rise from `85/90` to `88/91`; owner/emitter/reconstructable fields should remain unchanged. | High | Live MCP recheck, formal C++ readiness, remaining naming/header caveats. | Target metadata and score rationale. | incorporate | applied - target metadata is `88/91`, owner/emitter/reconstructable unchanged; validator `000000001122` applied completion/confidence updates. |
| C19 | [UID:0000MU] `ProtectedArray` should record UID000186 as first accessor body to populate `ProtectedArray.cpp` and may rise `87/89 -> 88/90`. | Medium-high | Parent file current state plus target report evidence. | `by-file/ProtectedArray.md`. | incorporate | applied - `by-file/ProtectedArray.md` metadata is `88/90`, includes UID000186 source-ready accessor body note, and validator `000000001124` applied the score update. |
| C20 | [UID:0001WR] `ProtectedArrayTemplates` should add/refresh the common accessor source body row and may rise `86/90 -> 87/91`. | Medium-high | Template support current state plus live target recheck. | `by-type/by-template/ProtectedArrayTemplates.md`. | incorporate | applied - template page metadata is `87/91`, common behavior row points to UID000186, B012 refresh section records evidence, and validator `000000001126` applied the score update. |
| C21 | [UID:0001VM] `ProtectedArrayLayout` should preserve layout offsets and note current live accessor recheck; score can remain `86/90`. | High | Accessor decompile/disasm and current layout doc. | `by-type/by-struct/ProtectedArrayLayout.md`. | incorporate | applied - layout notes and Changes record B012 live accessor/layout refresh with score unchanged; validator `000000001128` returned `ok:1`. |
| C22 | `ProtectedArray_struct_HairInfo_` and `ProtectedArray_struct_Acc2Info_` should stop treating accessor source spelling as a blank-C++ blocker; their concrete accessor source is covered by UID000186's generic template body. | High | Class docs, target C++ recommendation, vtable/name evidence. | Two by-class support docs. | incorporate | applied - both class docs now state accessor C++ is covered by UID000186 generic template body while class declarations remain blank for header/member caveats; validators `000000001130` and `000000001131` returned `ok:1`. |
| C23 | No UID00017V, UID000187, or sibling empty-emitter edits are required for this UID000186 callback, except cross-references already present. | High | Scope and generated output inventory. | Report exclusion/checklist. | not-applicable | excluded-with-reason - UID00017V, UID000187, sibling ProtectedArray empty emitters, generated/manual coverage files, and optional HumanImageLib were not edited; they were outside the accepted required edit set or already had adequate reciprocal context. |

## Positive Evidence Summary

- The body is source-shaped: one conditional bounds check and one indexed pointer return.
- The compiler emits three concrete instantiations with different stride code, exactly what a C++ template accessor would generate.
- Existing owner/emitter routing is already correct and surfaces to [UID:0000MU] `ProtectedArray`.
- The support docs already have layout names and template identity strong enough for first-draft C++.
- Generic C++ avoids inventing a false source name for the unknown 12-byte old-human record.

## IDA MCP Facts

### Function / Range Facts

| Address | MCP fact | Meaning |
| --- | --- | --- |
| `0x004e5f20` | `sub_4E5F20`, size `0x20` / 32 bytes (Verified with int_convert.py) | `ProtectedArray<HairInfo>` accessor, `0x10` / 16-byte stride (Verified with int_convert.py). |
| `0x004e5f40` | `sub_4E5F40`, size `0x25` / 37 bytes (Verified with int_convert.py) | `ProtectedArray<Acc2Info>` accessor, `0x14` / 20-byte stride (Verified with int_convert.py). |
| `0x004e5f65` | not a function | Internal alignment after second accessor. |
| `0x004e5f70` | `sub_4E5F70`, size `0x25` / 37 bytes (Verified with int_convert.py) | Unresolved old-human image-info accessor, `0x0c` / 12-byte stride (Verified with int_convert.py). |
| `0x004e5f95` | not a function | Post-cluster alignment. |
| `0x004e5fa0` | `sub_4E5FA0`, size `0x2f` | Successor deleting-destructor island, not part of this target. |

The full target span `0x004e5f20-0x004e5f95` is `0x75` / 117 bytes including padding (Verified with int_convert.py).

### Decompile Facts

- `0x004e5f20`: rejects negative and out-of-range indexes, returns `this + 0x10` fallback, otherwise `this[2] + 16 * index`.
- `0x004e5f40`: same logic, otherwise `this[2] + 20 * index`.
- `0x004e5f70`: same logic, otherwise `this[2] + 12 * index`.

### Disassembly Facts

- `0x004e5f20`: `test eax,eax`; `js`; `cmp eax,[ecx+4]`; `jge`; `shl eax,4`; `add eax,[ecx+8]`; fallback `lea eax,[ecx+10h]`; `retn 4`.
- `0x004e5f40`: uses `lea ecx,[eax+eax*4]` then `lea eax,[eax+ecx*4]` for 20-byte stride.
- `0x004e5f70`: uses `lea ecx,[eax+eax*2]` then `lea eax,[eax+ecx*4]` for 12-byte stride.

### Caller / Xref Facts

| Target | Total code refs | Grouping |
| --- | --- | --- |
| `0x004e5f20` | 105 | one in `sub_4D2720` at `0x004d4977`; 26 no-IDA-function old-human composition refs `0x004d58bd-0x004d696a`; 78 in `sub_4D9180` `0x004d9348-0x004da6e8`. |
| `0x004e5f40` | 27 | three in `sub_4D2720` `0x004d4860-0x004d48e4`; three no-IDA-function refs `0x004d5947-0x004d66aa`; 21 in `sub_4D9180`. |
| `0x004e5f70` | 3 | no-IDA-function calls at `0x004d5878` and `0x004d65db`; one `sub_4D9180` call at `0x004d97df`. |

### Type / Name Facts

- `search_structs ProtectedArray`, `HairInfo`, and `Acc2Info` returned no local IDA struct records.
- `type_query *ProtectedArray*`, `*HairInfo*`, `*Acc2Info*`, and `*ImageInfo*` returned no local type records.
- `entity_query names 0x0061b670-0x0061b6d8` found mangled `ProtectedArray<...>` vtable names for the known image-info types, including `HairInfo` at `0x0061b6a4` and `Acc2Info` at `0x0061b6ac`, but no type name for the 12-byte accessor.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e5f20-0x004e5f95` | [UID:000186] target | Three emitted instantiations of `ProtectedArray<T>::GetAtOrDefault(int index)` plus alignment | TRUE | [UID:0000MU] | Recommend `88/91` | Add formal generic template C++. |
| `0x004e5f20-0x004e5f3f` | target subrange | `ProtectedArray<HairInfo>` accessor | TRUE | [UID:0000MU] | covered by target | No child split. |
| `0x004e5f40-0x004e5f65` | target subrange | `ProtectedArray<Acc2Info>` accessor | TRUE | [UID:0000MU] | covered by target | No child split. |
| `0x004e5f65-0x004e5f70` | internal padding | `0xcc` alignment | FALSE as source body | n/a | n/a | Document only. |
| `0x004e5f70-0x004e5f95` | target subrange | `ProtectedArray<unknown 12-byte old-human image info>` accessor | TRUE | [UID:0000MU] | covered by target | No child split; type name remains open. |
| `0x004e5fa0-0x004e629f` | [UID:000187] | Adjacent deleting destructors | TRUE | [UID:0000MU] | `85/91` current | Out of scope for this report. |

## Documentation Evidence And IDA Status

- [UID:000186] already has strong owner and behavior documentation but no formal C++.
- [UID:0000MU] documents `ProtectedArray<T>` as a shared utility/header artifact under `NexusTK/util/`.
- [UID:0001WR] documents the common accessor family and all known template instantiations.
- [UID:0001VM] documents `+0x04` count, `+0x08` entries, `+0x10` fallback/default record, and provisional `+0x0c`.
- `ProtectedArray_struct_HairInfo_` and `ProtectedArray_struct_Acc2Info_` already identify their exact accessor subranges and owner route, but still explain blank C++ as final declaration/accessor-name uncertainty. That is stale if this report is accepted.
- [UID:0000JY] `HumanImageLib` already says UID000186 is a ProtectedArray template-source child, not direct `HumanImageLib.cpp` source.
- Generated `ProtectedArray.cpp` is current enough for evidence and still has [UID:000186] as an empty marker.

## Ranked Ownership Analysis

### 1. [UID:0000MU] ProtectedArray

- Evidence for: current owner/emitter; shared template behavior; support docs; all three bodies differ only by type stride; source route points to `NexusTK/util/`.
- Evidence against: concrete callsites are old-human image code, not generic utility code.
- Decision: keep as direct source owner and emitter.

### 2. [UID:0000JY] HumanImageLib

- Evidence for: all caller groups are old-human constructor/composition consumers; known `HairInfo` and `Acc2Info` arrays are embedded in `HumanImageLib`.
- Evidence against: consumer/read xrefs and fields do not own the reusable template source body; moving ownership would duplicate generic `ProtectedArray<T>` logic in a feature file.
- Decision: keep as concrete field/caller owner only.

### 3. Concrete by-class instantiations (`ProtectedArray_struct_HairInfo_`, `ProtectedArray_struct_Acc2Info_`)

- Evidence for: known vtables, class docs, concrete method rows, and concrete type names.
- Evidence against: target is a cluster containing three instantiations, including one with no concrete class page/type name; a per-instantiation source body is less faithful than the generic template body.
- Decision: support docs should cross-note coverage by UID000186; do not move UID000186 under a single concrete class.

### 4. No-code / template-instantiation marker

- Evidence for: these are compiler-instantiated template bodies, and the original source likely lived in a header.
- Evidence against: the target is reconstructable, routed, above the C++ gate, and the generic source body is compact and behavior-complete.
- Decision: reject no-code marker. Use real formal template C++.

## Source Placement

Recommended placement remains `NexusTK/util/ProtectedArray.h` or the current [UID:0000MU] `NexusTK/util/` source route. The autogen file is `auto-generated/NexusTK/util/ProtectedArray.cpp`, but the report should preserve the source-shape caveat that the real original likely defined this in a reusable header-style template declaration.

Do not create a new source file or move the body to `render/HumanImageLib.cpp`.

## Range / Split / Padding / Reclassification Analysis

No split is recommended. The page is a source-bearing template-instantiation cluster:

- `0x004e5f20-0x004e5f3f`: first accessor body.
- `0x004e5f40-0x004e5f65`: second accessor body.
- `0x004e5f65-0x004e5f70`: alignment padding.
- `0x004e5f70-0x004e5f95`: third accessor body.
- `0x004e5f95-0x004e5fa0`: post-cluster alignment before [UID:000187].

The current single page is useful because one formal generic template body covers all three concrete instantiations. Splitting into three child by-memory pages would make the source representation worse and would still leave the unknown 12-byte record name unresolved.

## Negative Evidence Summary

- No owner-route failure: target already has `CANONICAL_OWNER:0000MU` and `EMITTER_UIDS:0000MU`.
- No missing function at `0x004e5f65` or `0x004e5f95`.
- No callees inside any accessor.
- No local IDA struct/type record proves original `ProtectedArray`, `HairInfo`, `Acc2Info`, or the 12-byte record declarations.
- No vtable/name evidence identifies the `0x0c` / 12-byte accessor's concrete type.
- No evidence supports direct `HumanImageLib` ownership of the reusable accessor source body.
- No evidence supports leaving this as a no-code placeholder now that the generic body is source-ready.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Current average score is `(85 + 90) / 2 = 87.5`, owner/emitter route is valid, range and behavior are exact, and remaining naming caveats do not affect behavior.
- Recommended formal insertion text:

```cpp
template <class T>
T* ProtectedArray<T>::GetAtOrDefault(int index)
{
    if (index < 0 || index >= m_count)
        return &m_defaultEntry;

    return &m_entries[index];
}
```

Reason it preserves original behavior:

- Negative indexes and indexes `>= m_count` return fallback storage at object offset `+0x10`.
- Valid indexes return `m_entries + sizeof(T) * index`, matching all three concrete strides.
- It has no calls, allocation, mutation, exception behavior, or fallback initialization not present in the binary.

Reason it matches plausible original source:

- A reusable `ProtectedArray<T>` accessor is exactly the source construct that would produce the repeated concrete bodies.
- It avoids generated names such as `sub_4E5F20` or `ProtectedArray_struct_HairInfo_`.
- It avoids a false concrete name for the 12-byte old-human record.

## Final Recommendation

- Target [UID:000186]: update metadata `85/90 -> 88/91`; keep `CANONICAL_OWNER:0000MU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MU`, blank `EMITTER_POSITION_OPTIONAL`.
- Target C++: insert the generic template body above into the formal block.
- Target docs: add current MCP session `3fa0535f`, function boundary proof, caller grouping, padding proof, type-search negative evidence, and no-code rejection.
- [UID:0000MU] `ProtectedArray`: add that UID000186 is the first source-ready `GetAtOrDefault` body for the current `ProtectedArray.cpp` empty-emitter priority; recommend `87/89 -> 88/90`.
- [UID:0001WR] `ProtectedArrayTemplates`: add/refresh common accessor body evidence and state that the generic source body covers the three UID000186 instantiations; recommend `86/90 -> 87/91`.
- [UID:0001VM] `ProtectedArrayLayout`: add a short live session refresh; keep score `86/90`.
- `ProtectedArray_struct_HairInfo_` and `ProtectedArray_struct_Acc2Info_`: update blank-C++ blocker wording to say their accessor source is now supplied by UID000186's generic template body; keep scores unless supervisor wants broader class-empty cleanup.
- [UID:0000JY] `HumanImageLib`: optional reciprocal note only; no score change required because it already captures the source-owner split.
- No edits to [UID:00017V], [UID:000187], generated reports, manual coverage reports, or other `ProtectedArray.cpp` empty emitters are required for this UID000186 report.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md`

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended formal C++ block:

```cpp
template <class T>
T* ProtectedArray<T>::GetAtOrDefault(int index)
{
    if (index < 0 || index >= m_count)
        return &m_defaultEntry;

    return &m_entries[index];
}
```

Recommended source-quality facts to incorporate:

- MCP session `3fa0535f` is current and healthy.
- Exact lookup/decompile/disasm facts for all three bodies.
- Caller grouping and `0x004e5f70` callsite context.
- Negative type/struct search results.
- Rejected no-code marker, rejected direct `HumanImageLib` ownership, rejected three-handwritten-wrapper source shape.
- Score rationale: raises completion for first-draft C++ readiness and current live evidence; confidence remains below final audit because original header basename, member spelling, and 12-byte concrete record name remain inferred/open.

## Recommended Support Doc Changes

### `by-file/ProtectedArray.md`

- Add a B012 source-quality note that [UID:000186] now has enough evidence for a formal generic `ProtectedArray<T>::GetAtOrDefault(int index)` body.
- Record that this should change `ProtectedArray.cpp` from `0/21` filled to at least one source-bearing marker after validation.
- Recommend score `87/89 -> 88/90`; keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and `CANONICAL_OWNER:FILE`.

### `by-type/by-template/ProtectedArrayTemplates.md`

- Add the common accessor source body as a source-ready template method.
- State that UID000186 covers the `HairInfo`, `Acc2Info`, and unresolved 12-byte old-human image-info accessor instantiations.
- Recommend score `86/90 -> 87/91`; keep owner/emitter [UID:0000MU].

### `by-type/by-struct/ProtectedArrayLayout.md`

- Add B012 live session `3fa0535f` recheck of `+0x04` count, `+0x08` entries, `+0x10` default entry, and strides.
- Keep `+0x0c` provisional and score unchanged at `86/90`.

### `by-class/ProtectedArray_struct_HairInfo_.md`

- Update status/output-route wording so the `GetAtOrDefault` C++ blocker is resolved through [UID:000186]'s generic template body.
- Keep concrete `HairInfo` declaration/header-name caveats; no score change required.

### `by-class/ProtectedArray_struct_Acc2Info_.md`

- Update status/output-route wording so the `GetAtOrDefault` C++ blocker is resolved through [UID:000186]'s generic template body.
- Keep concrete `Acc2Info` declaration/header-name caveats; no score change required.

### `by-file/HumanImageLib.md`

- Optional no-score note: live B012 MCP recheck still supports `HumanImageLib` as concrete field/caller owner only; [UID:000186] remains a `ProtectedArray` template-source child.

## Score And Metadata Recommendation

- Target current: `85/90`, owner/emitter [UID:0000MU], reconstructable true, blank C++.
- Target recommended: `88/91`, owner/emitter unchanged, reconstructable unchanged, formal generic C++ present.
- Reason completion rises: the report resolves the empty-emitter blocker, supplies formal source-shaped C++, refreshes MCP evidence, adds negative type/name checks, and clarifies support-doc incorporation.
- Reason confidence rises only modestly: binary behavior and owner route are very strong, but exact original header basename, exact member names, and the 12-byte record type name remain unresolved.
- Reason not higher: no local IDA type records; one concrete accessor type remains unnamed; this is not final-audit source declaration coverage for the whole `ProtectedArray` template.

## Open Questions With Attempted Resolution

- Exact original header basename: checked [UID:0000MU], [UID:0001WR], generated output, and prior B008 report. Best current artifact remains `ProtectedArray` under `NexusTK/util/`, likely header-style. This does not block the accessor body.
- Exact member names: checked layout/template/class docs and live decompile. `m_count`, `m_entries`, and `m_defaultEntry` are project-standard descriptive names; original spelling is not proven. This caps confidence but does not block behavior.
- `0x0c` / 12-byte old-human record type: checked caller contexts, vtable names, `search_structs`, and `type_query`. The record is old-human image/composition data, but no concrete type name is defensible. Generic template C++ avoids needing one.
- Whether to use no-code marker: rejected because the source body is compact, source-authored, reconstructable, routed, and above the current gate.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage/tracker edit is requested. The relevant generated reports should refresh from scoped validators during the implementation callback.

Expected generated result after implementation and validation:

- `auto-generated/NexusTK/util/ProtectedArray.cpp` should no longer show [UID:000186] as `Empty Emitter Marker`.
- The same file should contain the UID000186 marker followed by the generic `ProtectedArray<T>::GetAtOrDefault(int index)` body.
- `auto-generated/-ag-research-tracker.md` should no longer show [UID:0000MU] `ProtectedArray.cpp` as `0/21` if generated refresh completes after UID000186 implementation; sibling empty emitters may remain.

## Validator Results

Report-only pass: no validators were run.

Implementation callback validators after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R002 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R003 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R004 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R005 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R006 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated freshness proof: final read-only check of `auto-generated/NexusTK/util/ProtectedArray.cpp` found header `validator-command-id: 000000001131`, `validator-refreshed-at: 2026-06-29T19:49:32-04:00`, `validator-refresh-source: deferred-generated-refresh`. This is equal/newer than target validator `000000001122` and shows UID000186 at `Completion:88 | Confidence:91` with `template <class T> T* ProtectedArray<T>::GetAtOrDefault(int index)`. UID000186 no longer appears as an `Empty Emitter Marker`; unrelated sibling ProtectedArray empty markers remain out of scope.

Validator-owned side effects included generated C++/report refreshes, projected stats updates, `validator.ini` autogen registry rebuild/update, generated metadata refreshes, UID link insertions, and validator autogen backups. These were tool-owned effects from scoped validators, not manual edits.

Original recommended implementation validators after accepted edits:

> Executable block R007 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-file/HumanImageLib.md` receives the optional reciprocal note, validate it too:

> Executable block R008 was removed from this report and preserved verbatim in [000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md](000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B012/research/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md
```

Implementation callback modified:

```text
by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md
by-file/ProtectedArray.md
by-type/by-template/ProtectedArrayTemplates.md
by-type/by-struct/ProtectedArrayLayout.md
by-class/ProtectedArray_struct_HairInfo_.md
by-class/ProtectedArray_struct_Acc2Info_.md
tools/leaser/Agents/Agent-B012/research/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md
```

Leases: B012 leased and released the six required by-* docs listed above. Final unlease command returned `Success` for all six.

Report execution: not performed. The supervisor executes/archives accepted reports.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and updated `Agent-B012/goal.md` to implementation callback mode.
- [x] Lease only immediate implementation files after supervisor callback; no leases during report-only research. Proof: B012 leased only the six required by-* docs immediately before editing and released all six immediately after validators.
- [x] Update `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md` metadata from `85/90` to `88/91`; keep owner/emitter/reconstructable fields unchanged. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000MU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MU`, blank `EMITTER_POSITION_OPTIONAL`; validator `000000001122`, exit `0`, `ok:1`.
- [x] Insert the exact formal generic `ProtectedArray<T>::GetAtOrDefault(int index)` C++ body from this report into the target formal block. Proof: target formal C++ block contains the accepted template body; generated `ProtectedArray.cpp` lines 7-15 emit the same body for UID000186.
- [x] Update target evidence sections with current MCP session `3fa0535f`, `server_health`, `lookup_funcs`, decompile/disasm, callees, xref grouping, padding bytes, type/name negative checks, and score rationale. Proof: target Item Summary, Status, 2026-06-29 B012 section, Ownership, and Changes record those details.
- [x] Preserve target range as `0x004e5f20-0x004e5f95`; do not split or rename the by-memory file. Proof: same target path/range validated by command `000000001122`.
- [x] Update `by-file/ProtectedArray.md` with the UID000186 source-ready accessor body decision and recommended `88/90` score. Proof: file metadata is `88/90`, new B012 source-ready accessor body note and Changes entry added; validator `000000001124`, exit `0`, `ok:1`.
- [x] Update `by-type/by-template/ProtectedArrayTemplates.md` with the common accessor source body and recommended `87/91` score. Proof: template metadata is `87/91`, common behavior row and B012 Accessor Body Refresh section added; validator `000000001126`, exit `0`, `ok:1`.
- [x] Update `by-type/by-struct/ProtectedArrayLayout.md` with the B012 live accessor/layout refresh; keep `+0x0c` provisional and score unchanged. Proof: layout note and Changes entry added, header remains `86/90`; validator `000000001128`, exit `0`, `ok:1`.
- [x] Update `by-class/ProtectedArray_struct_HairInfo_.md` so its accessor C++ blocker is resolved by UID000186's generic template body. Proof: output-route/status wording, evidence note, and Changes entry updated; validator `000000001130`, exit `0`, `ok:1`.
- [x] Update `by-class/ProtectedArray_struct_Acc2Info_.md` so its accessor C++ blocker is resolved by UID000186's generic template body. Proof: output-route/status wording, evidence note, and Changes entry updated; validator `000000001131`, exit `0`, `ok:1`.
- [x] Optionally update `by-file/HumanImageLib.md` with a reciprocal no-score note if supervisor wants aggregate support synchronization. Proof: intentionally excluded; current HumanImageLib already states UID000186 is a `ProtectedArray` template-source child and `HumanImageLib` is concrete field/caller owner, so it was not materially below accepted detail.
- [x] Do not edit [UID:00017V], [UID:000187], sibling `ProtectedArray.cpp` empty emitters, generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files. Proof: no manual edits to excluded docs/files; generated/project/tool-state changes were validator-owned side effects only.
- [x] Run scoped validators listed in `Validator Results`; run target with `--wait-generated`. Proof: validators `000000001122`, `000000001124`, `000000001126`, `000000001128`, `000000001130`, and `000000001131` all exited `0`, `ok:1`; target used `--wait-generated`.
- [x] Confirm generated `auto-generated/NexusTK/util/ProtectedArray.cpp` header is equal/newer than the target validator command and that UID000186 no longer has an empty marker. Proof: final generated header is `validator-command-id: 000000001131`, `validator-refreshed-at: 2026-06-29T19:49:32-04:00`, equal/newer than target `000000001122`; UID000186 emits C++ and no UID000186 empty marker remains.
- [x] Record validator command strings, command IDs, timestamps, exit codes, ok counts, warnings, generated-refresh state, and any validator-owned side effects in the callback response. Proof: recorded in `Validator Results` and final response.
- [x] Update this report's Claim And Incorporation Ledger during callback so each accepted row is `applied`, `already-present`, `excluded-with-reason`, or `blocked` with proof. Proof: C01-C22 are `applied`; C23 is `excluded-with-reason`; no accepted row remains `proposed` or `blocked`.
- [x] Update this checklist during callback with proof for every accepted item; leave no accepted item unchecked unless blocked with exact reason. Proof: all checklist items are checked with proof.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` is implementation callback for this accepted report.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, ProtectedArray file, template support, layout support, HairInfo support, and Acc2Info support docs updated; optional HumanImageLib excluded as already adequate.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger rows C01-C23 updated after validators.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target `88/91`, ProtectedArray `88/90`, ProtectedArrayTemplates `87/91`; no owner/emitter/split/rename changes; C++ inserted; layout/classes unchanged in score as intended.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve rejected no-code marker, direct HumanImageLib ownership, three wrapper bodies, unresolved 12-byte type, and negative type/struct evidence.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: original header/member spelling and 12-byte record type remain documented caveats with negative evidence.
- [x] Validators run and results recorded. Proof: six scoped validators recorded above, all `ok:1`.
- [x] Generated report refresh completed by validator or explicit generated freshness state recorded. Proof: generated `ProtectedArray.cpp` freshness recorded above; target generated refresh completed and later deferred refresh header is newer than target validator.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted required item remains unapplied; optional HumanImageLib edit intentionally excluded because existing reciprocal note was adequate.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md","timestamp":"2026-06-29T19:56:53","uid":"000186"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/000186-ProtectedArrayImageInfoAccessors-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000186"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
