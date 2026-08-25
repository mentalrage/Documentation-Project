** TARGET-REPORT-UID:0003P9 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003P9 **
# [UID:0003P9] SharedEpfSuffixString Ownership / Source Routing Research

## Finalized Report / Current Recommendation

- Current recommendation: keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:TRUE`, and add `EMITTER_UIDS:0000JA,0000L3,0000PB`.
- Final disposition: no canonical owner with three proven source-use emitters. This is not a non-emitting item, not a dead duplicate, and not a standalone global/source object.
- Required action: update the target doc metadata/evidence and the nested `by-memory/-coverage-report.md` row as specified below. Do not split, merge, reclassify, or add final C++.
- Confidence: high. IDA MCP, raw PE scan, existing by-file/by-class docs, and neighboring shared-literal precedent all agree.

## Supporting Research

## Target

- Target UID: `0003P9`
- Target path: `by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner row plus supervisor assignment row `B001-goal2-noowner-shared-epf-suffix-0003P9-20260615`.
- Current supervisor classification: assigned to B001 as a heavy pooled-literal/source-use inference problem.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank final C++.

## Executive Recommendation

The best source-structure answer is the current shared-literal model already used for [UID:0003JG] `SharedMapPaletteSuffixString`, extended with the extra FieldMapPane use:

- `CANONICAL_OWNER:NONE`: no single declaration owner is proven.
- `EMITTER_UIDS:0000JA,0000L3,0000PB`: the literal has direct source-use refs in the FieldMapPane, MapPane, and WorldMapPane source roots.
- `RECONSTRUCTION_CPP CODE`: keep blank. The physical pooled `.rdata` object should not emit as a standalone global or array; it should surface later as use-site string literals such as `L".EPF"` in the relevant reconstructed source contexts.
- Recommended score: raise to `87/92`. The prior audit blocker, "all `.EPF` suffix consumers," is now resolved for this physical address. Keep below final-audit range because original source declarations and final use-site C++ remain inferred rather than source-metadata-confirmed.

## Supervisor Active Recheck

- Supervisor instruction checked: `tools/leaser/Agents/Supervisor_notes.md` assigns [UID:0003P9] to B001 and asks whether this target should remain no-owner/no-emitter, gain multiple emitters, gain a canonical owner, split/merge/reclassify, or require further research.
- Split repair: no split is needed. The current child range is exact and half-open: `0x0061a44c-0x0061a458`. IDA and PE evidence show no interior refs to `0x0061a450`, `0x0061a452`, or `0x0061a456`, and the successor `0x0061a458` is a FolderSelectDialog RTTI locator pointer cell.
- Source-bearing child coverage: the one source-bearing child in scope is this `.EPF` literal. Its direct source-use emitters are identified below.

## Inference Research Guidance Check

`by-structure.md` explicitly allows `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled string literals or shared constants where no single declaration owner is proven but multiple source-use contexts are proven. That rule is the controlling rule here.

B001 standing notes also say not to use Wave2/Wave3 source data. This report does not rely on Wave2/Wave3 source. It uses existing project documentation, live IDA MCP inspection, local raw PE scanning, generated coverage state, and source-tree docs.

Facts, documentation evidence, and inference are separated below:

- IDA/PE fact: one physical UTF-16 `.EPF` object at `0x0061a44c` has exactly four direct VA immediate references, all in code.
- Documentation evidence: FieldMapPane, MapPane, and WorldMapPane by-file/by-class pages clear the relevant routing gate and place all three sources under `NexusTK/map/`.
- Inference: the original source likely had independent use-site `L".EPF"` suffix literals that the compiler/linker pooled to this address for these three contexts. No evidence supports a handwritten shared global declaration.

## Evidence Standards Used

Evidence used:

- IDA MCP `server_health`, `lookup_funcs`, `trace_data_flow`, `entity_query`, `get_bytes`, `disasm`, and `analyze_component`.
- Local PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Existing by-memory/by-class/by-file docs for FieldMapPane, MapPane, and WorldMapPane.
- Existing shared-literal precedent [UID:0003JG] `.PAL` and [UID:0003JI] `WM2`.
- Generated coverage state from `auto-generated/-ag-memory-coverage.md`.
- Proposed source-tree state from `by-project-structure/proposed-source-tree.md`.

The evidence is strong enough to add emitters because the xrefs are direct source-use operands inside cleared source roots. It is not strong enough to assign a canonical owner because PE/debug metadata is absent, identical `.EPF` byte sequences occur many times, and no code uses this object as a named shared declaration.

## IDA MCP Facts

IDA MCP session:

- Session: `c001_midiplayer_rdata_20260615`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Health: `status:"ok"`, Hex-Rays ready, strings cache ready. The inherited session reported `auto_analysis_ready:false`, so I cross-checked IDA results with raw PE evidence and existing live-IDA docs instead of treating this as the only evidence source.

### Function / Range Facts

`lookup_funcs` results:

| Query | IDA result | Meaning |
| --- | --- | --- |
| `0x004b0bb0` | `sub_4B0BB0`, size `0x17b` | FieldMapPane constructor-family function. |
| `0x004b0c12` | inside `sub_4B0BB0` | FieldMapPane `.EPF` source-use ref. |
| `0x00510960` | `sub_510960`, size `0x9e7` | MapPane map info/object-removal packet helper. |
| `0x00510b2f` | inside `sub_510960` | first MapPane `.EPF` source-use ref. |
| `0x00511019` | inside `sub_510960` | second MapPane `.EPF` source-use ref. |
| `0x005c2ac0` | `sub_5C2AC0`, size `0x7ea` | WorldMapPane constructor-family function. |
| `0x005c2df4` | inside `sub_5C2AC0` | WorldMapPane `.EPF` source-use ref. |
| `0x0061a44c` | not a function | target is data, not code. |

### Data / Padding Facts

`get_bytes` for `0x0061a44c` size `0x0c` returned:

```text
2e 00 45 00 50 00 46 00 00 00 00 00
```

That is UTF-16LE `.EPF`, a wide NUL terminator, and two alignment bytes. `get_bytes 0x0061a440 size 0x20` also shows the predecessor vtable slots and successor pointer:

```text
... 2e 00 45 00 50 00 46 00 00 00 00 00 0c 78 64 00 ...
```

`entity_query` over `0x0061a440-0x0061a460` reports:

| Address | Name | Meaning |
| --- | --- | --- |
| `0x0061a444` | `??_7FieldMapPane@@6B@_1` | FieldMapPane tertiary vtable label immediately before target. |
| `0x0061a44c` | `aE` | IDA fragment label for `.E`. |
| `0x0061a450` | `aPf_1` | IDA fragment label for `PF`; not a separate source string. |
| `0x0061a45c` | `??_7FolderSelectDialog@@6B@` | successor FolderSelectDialog vtable. |

### Xref Facts

`trace_data_flow 0x0061a44c backward max_depth=1` reports the target and exactly four code xrefs:

| Ref address | Function | Instruction | Source route |
| --- | --- | --- | --- |
| `0x004b0c12` | `sub_4B0BB0` | `push offset aE; Source` | FieldMapPane constructor -> [UID:0000JA] `FieldMapPane` file root. |
| `0x00510b2f` | `sub_510960` | `push offset aE; Source` | MapPane packet helper -> [UID:0000L3] `MapPane` file root. |
| `0x00511019` | `sub_510960` | `push offset aE; Source` | second MapPane packet-helper use -> [UID:0000L3] `MapPane` file root. |
| `0x005c2df4` | `sub_5C2AC0` | `push offset aE; Src` | WorldMapPane constructor-family -> [UID:0000PB] `WorldMapPane` file root. |

Scoped `disasm` filtering confirms the same instruction starts:

```text
0x004b0c12 push offset aE; Source
0x00510b2f push offset aE; Source
0x00511019 push offset aE; Source
0x005c2df4 push offset aE; Src
```

Interior/backward checks:

| Address | Result | Meaning |
| --- | --- | --- |
| `0x0061a450` | data node only, no edges | IDA `aPf_1` is a fragment label, not a referenced string. |
| `0x0061a452` | data node only, no edges | no interior source-use ref. |
| `0x0061a456` | `align 4`, no edges | no alignment ref. |
| `0x0061a458` | `dd offset ??_R4FolderSelectDialog@@6B@`, no backward edges to this cell | successor belongs to FolderSelectDialog child, not the `.EPF` string. |

### Component Facts

`analyze_component` over `0x004b0bb0`, `0x00510960`, and `0x005c2ac0` reports shared global:

```text
0x0061a44c aE accessed_by: sub_4B0BB0, sub_510960, sub_5C2AC0
```

The same component check reports the neighboring [UID:0003JG] `.PAL` target:

```text
0x0061ea24 aPal accessed_by: sub_510960, sub_5C2AC0
```

This aligns the current `.EPF` item with the already accepted `.PAL` no-owner/multiple-emitter pattern, with FieldMapPane as an additional proven source-use root.

## Raw PE Facts

Raw PE scan target:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- `.rdata`: RVA `0x20d000`, raw `0x20ba00`, raw size `0x5f200`
- Target VA: `0x0061a44c`
- Target RVA: `0x0021a44c`
- Target file offset: `0x218e4c`

Scan results:

| Pattern | Count | Meaning |
| --- | ---: | --- |
| exact 12 target bytes `2e 00 45 00 50 00 46 00 00 00 00 00` | 108 | The byte pattern is common; physical text bytes do not prove ownership. |
| UTF-16 `.EPF\0` 10-byte pattern | 176 | `.EPF` appears in many `.rdata` locations. |
| UTF-16 `.EPF` 8-byte pattern | 176 | same conclusion. |
| ASCII `.EPF` | 0 | this target family is wide-string data. |
| VA immediate/pointer `0x0061a44c` | 4 | matches the four IDA xrefs. |
| VA immediate/pointer `0x0061a450` | 0 | no interior `PF` refs. |
| VA immediate/pointer `0x0061a452` | 0 | no interior refs. |
| VA immediate/pointer `0x0061a456` | 0 | no alignment refs. |
| VA immediate/pointer `0x0061a458` | 0 | no raw refs to successor cell address. |
| RVA immediate `0x0021a44c` | 0 | no RVA-form hidden ref. |
| RVA immediates for `0x0021a450`, `0x0021a452`, `0x0021a456`, `0x0021a458` | 0 | no RVA-form interior/successor refs. |

The four VA immediate hits are operand bytes one byte after the `push imm32` instruction starts:

| Operand VA | Instruction start | Function |
| --- | --- | --- |
| `0x004b0c13` | `0x004b0c12` | `sub_4B0BB0` |
| `0x00510b30` | `0x00510b2f` | `sub_510960` |
| `0x0051101a` | `0x00511019` | `sub_510960` |
| `0x005c2df5` | `0x005c2df4` | `sub_5C2AC0` |

Debug/source breadcrumb scan:

| Marker | Count | Interpretation |
| --- | ---: | --- |
| `RSDS` | 0 | no embedded CodeView/PDB pointer found by raw marker scan. |
| `NB10` | 0 | no older CodeView marker found. |
| `.pdb`, `.PDB` | 0 | no PDB path string found. |
| `.cpp`, `.CPP` | 0 | no source-path string found. |
| `FieldMapPane` | 1 | RTTI/class-name-style data, not source-file metadata. |
| `WorldMapPane` | 2 | RTTI/class-name-style data, not source-file metadata. |

This resolves the source-metadata blocker negatively: no embedded source/debug path proves an original declaration owner.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061a44c-0x0061a458` | [UID:0003P9] `SharedEpfSuffixString` | pooled UTF-16 `.EPF` suffix literal | `TRUE` | `NONE` | current `85/90`, recommend `87/92` | add emitters `0000JA,0000L3,0000PB`; no final C++ |
| `0x0061a3c4-0x0061a45c` | [UID:00025B] `FieldMapPaneReadOnlyData` | mixed `.rdata` index | `FALSE` | `NONE` | `86/91` | no parent change; exact children carry decisions |
| `0x0061a3c4-0x0061a44c` | [UID:0003P8] `FieldMapPaneVtableData` | FieldMapPane vtable child | `TRUE` | [UID:00004U] | `86/91` | separate predecessor, not owner for `.EPF` |
| `0x0061a458-0x0061a45c` | [UID:0003PA] `FolderSelectDialogRttiLocatorPointer` | FolderSelectDialog COL pointer | `TRUE` | [UID:000059] | `86/91` | separate successor, not owner for `.EPF` |
| `0x0061ea24-0x0061ea30` | [UID:0003JG] `SharedMapPaletteSuffixString` | pooled `.PAL` suffix precedent | `TRUE` | `NONE` | `87/93` | existing no-owner with emitters `0000L3,0000PB` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b0c12` | `sub_4B0BB0` FieldMapPane constructor uses `push offset aE` | proves FieldMapPane source-use emitter [UID:0000JA]. |
| `0x00510b2f` | `sub_510960` MapPane packet helper uses `push offset aE` | proves first MapPane source-use emitter [UID:0000L3]. |
| `0x00511019` | `sub_510960` MapPane packet helper uses `push offset aE` | proves second MapPane source-use emitter [UID:0000L3]. |
| `0x005c2df4` | `sub_5C2AC0` WorldMapPane constructor-family uses `push offset aE` | proves WorldMapPane source-use emitter [UID:0000PB]. |
| no refs to `0x0061a450`, `0x0061a452`, `0x0061a456` | IDA and raw PE agree | rejects splitting into fragment strings. |
| no RVA immediates for target or interiors | raw PE scan | rejects hidden RVA-form source owner or table route. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0003P9] target doc already records exact bytes, four xrefs, no interior refs, and a future-work note to use multiple emitters if shared literal consumers are proven.
- [UID:00025B] parent doc says this is a mixed `.rdata` map and blocks a FieldMapPane-only owner for the suffix.
- [UID:00004U] `FieldMapPane` and [UID:0000JA] `FieldMapPane` file doc tie `sub_4B0BB0` to FieldMapPane construction and `NexusTK/map/FieldMapPane.cpp`.
- [UID:0001AW] `MapPanePacketHandlers`, [UID:00007Q] `MapPane`, and [UID:0000L3] `MapPane` tie `sub_510960` to the MapPane packet/helper family and `NexusTK/map/MapPane.cpp`.
- [UID:0001O4] `WorldMapPane`, [UID:0000G9] `WorldMapPane`, and [UID:0000PB] `WorldMapPane` tie `sub_5C2AC0` to the WorldMapPane constructor-family and `NexusTK/map/WorldMapPane.cpp`.
- [UID:00035I] `WorldMapPaneResourceStrings` proves `sub_5C2AC0` is a resource-loading constructor context with many constructor-only `.EPF`/`.PAL` resource strings nearby in source behavior, even though this exact shared suffix lives at the earlier pooled address.
- [UID:0003JG] `SharedMapPaletteSuffixString` is the closest precedent and already uses `CANONICAL_OWNER:NONE` plus MapPane/WorldMapPane file emitters.
- `by-project-structure/proposed-source-tree.md` lists `map/FieldMapPane.cpp`, `map/MapPane.cpp`, and `map/WorldMapPane.cpp`.

Existing docs that are incomplete but not contradicted:

- [UID:0003P9] currently leaves emitters blank because it was awaiting focused shared-literal placement research. That blocker is now resolved.
- Generated `auto-generated/NexusTK/map/FieldMapPane.cpp`, `MapPane.cpp`, and `WorldMapPane.cpp` are currently zero bytes because final C++ blocks are blank. This is not a route dead-end; the by-file roots have valid reconstruction paths.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently lists [UID:0003P9] as `no-owner` with blank emitters and no generated path.
- Neighboring [UID:0003JG] and [UID:0003JI] rows show the accepted no-owner/multiple-emitter shape for pooled MapPane/WorldMapPane literals.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with emitters `0000JA,0000L3,0000PB`

Evidence for:

- Direct code xrefs prove source-use in three separate source roots: FieldMapPane, MapPane, and WorldMapPane.
- All three by-file roots clear the routing gate and have valid `NexusTK/map/` reconstruction paths.
- `by-structure.md` explicitly allows no canonical owner with multiple emitters for pooled string literals.
- The adjacent accepted `.PAL` and `WM2` shared-literal docs use this model for MapPane/WorldMapPane.
- Raw PE scan finds many `.EPF` byte duplicates and no debug/source metadata, making a unique declaration-owner claim unsafe.

Evidence against:

- Original source cannot be proven to have exactly three independent literal tokens without source/debug metadata.
- Final C++ use-site code is not written yet.

Decision: accepted. This is the strongest source-routing answer and directly resolves the assigned blocker.

### 2. Canonical owner [UID:00004U] / [UID:0000JA] FieldMapPane

Evidence for:

- The target is physically adjacent to FieldMapPane vtable data.
- FieldMapPane constructor directly references the literal at `0x004b0c12`.

Evidence against:

- IDA and PE both prove three non-FieldMap refs to the same physical address.
- Parent [UID:00025B] is already a mixed `.rdata` index; adjacency is known to cross source boundaries.
- Assigning FieldMapPane would force all MapPane/WorldMapPane source-use literals under an unrelated constructor adjacency.

Decision: rejected as canonical owner. Keep FieldMapPane only as one emitter.

### 3. Canonical owner [UID:0000L3] MapPane

Evidence for:

- MapPane has two direct refs, more than the other consumers.
- MapPane already owns neighboring map resource string splits around `0x0061e9xx-0x0061eaxx`.
- [UID:0003JG] `.PAL` has MapPane refs from the same `sub_510960` helper.

Evidence against:

- FieldMapPane and WorldMapPane both materially use this exact physical literal.
- `by-structure.md` says not to force ownership to the consumer with the most xrefs when other consumers materially use the same pooled item.
- No MapPane-only declaration, table, source metadata, or unique local cluster exists for `0x0061a44c`.

Decision: rejected as canonical owner. Keep MapPane as an emitter.

### 4. Canonical owner [UID:0000PB] / [UID:0000G9] WorldMapPane

Evidence for:

- `sub_5C2AC0` is a constructor/resource-loading function and uses this suffix once.
- WorldMapPane has constructor-only resource strings containing `.EPF` and `.PAL` in [UID:00035I].

Evidence against:

- FieldMapPane and MapPane refs are material and direct.
- [UID:00035I] is a separate WorldMapPane-only resource-string child at `0x00631490-0x00631528`; it does not own the earlier pooled `.EPF` address.
- No single WorldMap declaration owner is proven.

Decision: rejected as canonical owner. Keep WorldMapPane as an emitter.

### 5. New shared owner such as `ResourceSuffixes.cpp`, `EpfResourceSuffix`, or a palette/resource helper file

Evidence for:

- `.EPF` is a common resource suffix.
- The executable contains 176 UTF-16 `.EPF` occurrences and this physical object is shared by multiple functions.

Evidence against:

- No code takes the address of a named global suffix table; all four refs are immediate string operands.
- No PDB/source path, map file, symbol, static initializer, or source-tree doc supports a standalone suffix module.
- Many duplicate `.EPF` copies argue against a single program-wide suffix object.
- Existing shared-literal policy deliberately avoids inventing a shared owner solely to avoid `NONE`.

Decision: rejected.

### 6. Non-emitting evidence only, dead/duplicate body, split, or merge

Evidence for:

- The final C++ block is blank and generated source files are currently zero bytes.
- The string bytes are duplicated elsewhere.

Evidence against:

- The physical target is live data: IDA and PE prove four direct code references to this exact address.
- It is source-authored/source-declared string literal data, not dead padding and not compiler-only RTTI/vtable glue.
- Interior refs are absent, so no split is warranted.
- The parent range is already a mixed non-emitting index; merging back would hide a source-bearing literal with its own emitter routes.

Decision: rejected. Keep reconstructable and add emitters.

## Proposed New File / Grouping

No new owner/source file is recommended.

If forced to name a grouping, it would be "shared pooled resource suffix literals," but that is a documentation behavior category, not an original source file. The evidence supports use-site literals in existing map source files, not a new `ResourceSuffixes.cpp`.

Candidate related items checked:

- [UID:0003JG] `.PAL`: already no-owner with MapPane/WorldMapPane emitters; supports the policy.
- [UID:0003JI] `WM2`: already no-owner with MapPane/WorldMapPane emitters; supports the policy.
- [UID:00035I] WorldMapPane resource strings: constructor-only WorldMapPane resource literals; they remain WorldMapPane-owned and do not absorb this shared suffix.
- Other `.EPF` byte duplicates: 176 UTF-16 `.EPF` occurrences in the PE. They are too broad and unrelated to create one owner without per-address xref research.

## Negative Evidence Summary

Checked and rejected:

- FieldMapPane-only ownership: blocked by MapPane and WorldMapPane direct xrefs.
- MapPane-only ownership: blocked by FieldMapPane and WorldMapPane direct xrefs.
- WorldMapPane-only ownership: blocked by FieldMapPane and MapPane direct xrefs.
- Source adjacency ownership: rejected because [UID:00025B] is mixed `.rdata`, and the target sits between FieldMapPane vtable data and FolderSelectDialog RTTI/vtable data.
- Interior string split: rejected because `0x0061a450`, `0x0061a452`, and `0x0061a456` have no IDA or raw PE refs.
- Successor absorption: rejected because `0x0061a458` is a FolderSelectDialog RTTI locator pointer cell and has no target-string refs.
- New shared suffix file/global: rejected because all refs are immediate string operands, no source/debug metadata exists, and `.EPF` byte duplicates are common.
- Non-emitting/dead status: rejected because live code directly references this exact address four times.
- Final C++ entry now: rejected because source should be emitted at use sites later, and this physical pooled data page should not contain a standalone global.

## Final Recommendation

Exact changes recommended:

1. Update `by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md` metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JA,0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Keep `RECONSTRUCTION_CPP CODE` blank.

3. Add target-doc evidence or change notes summarizing:

```text
- 2026-06-15 B001 source-routing audit: live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed the exact `.EPF` bytes at `0x0061a44c`, direct refs at `0x004b0c12`, `0x00510b2f`, `0x00511019`, and `0x005c2df4`, and no interior refs to `0x0061a450`, `0x0061a452`, or `0x0061a456`.
- Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed exactly four VA immediates to `0x0061a44c`, no target/interior RVA immediates, no interior VA immediates, no `RSDS`/`NB10`/`.pdb`/`.cpp` debug-source markers, and 176 duplicate UTF-16 `.EPF` byte occurrences.
- Keep `CANONICAL_OWNER:NONE`; set `EMITTER_UIDS:0000JA,0000L3,0000PB` because the literal is a pooled use-site suffix shared by FieldMapPane, MapPane, and WorldMapPane with no proven single declaration owner.
- Keep final C++ blank because the physical pooled literal should surface later as use-site `L".EPF"` literals in those source files, not as a standalone global emitted from this data page.
```

4. Recommended target-doc related documentation additions:

```text
- [UID:0001AW] MapPane packet-handler source-use context for `sub_510960`.
- [UID:0000L3] MapPane file emitter.
- [UID:0001O4] WorldMapPane constructor-family source-use context for `sub_5C2AC0`.
- [UID:0000PB] WorldMapPane file emitter.
- [UID:0003JG] Shared `.PAL` suffix precedent.
```

No support docs require direct correction. The FieldMapPane, MapPane, WorldMapPane, and `.PAL` precedent pages already support the routing decision.

## Shared Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` directly from B001. Supervisor should replace the current nested [UID:0003P9] row under [UID:00025B] `FieldMapPaneReadOnlyData`, immediately between [UID:0003P8] and [UID:0003PA], with:

```text
        - [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) 0x0061a44c-0x0061a458 | string-data | SharedEpfSuffixString : reconstructable : 87% : very strong : Exact pooled UTF-16 `.EPF` suffix literal; B001 source-routing audit confirms `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JA,0000L3,0000PB` because direct source-use refs are `0x004b0c12` in FieldMapPane constructor `sub_4B0BB0`, `0x00510b2f`/`0x00511019` in MapPane packet helper `sub_510960`, and `0x005c2df4` in WorldMapPane constructor-family `sub_5C2AC0`; live IDA and raw PE scans found no interior refs, no RVA refs, no debug/source-file metadata, and no single declaration owner, so final C++ remains blank and the literal should surface as use-site string literals through the three map file roots rather than as a standalone global.
```

## Follow-Up Actions

Supervisor actions:

- Apply the target metadata changes above.
- Add the target-doc evidence/change-note bullets above or equivalent wording with the same facts.
- Replace the `by-memory/-coverage-report.md` row with the exact row above.
- Validate after edits:

> Executable block R001 was removed from this report and preserved verbatim in [0003P9-shared-epf-suffix-source-routing-removed.md](0003P9-shared-epf-suffix-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

A-agent actions:

- No separate support-doc changes are required.
- Later final-C++ work should place `L".EPF"` at the proven use sites in FieldMapPane, MapPane, and WorldMapPane source contexts when the surrounding methods are ready for final source.

B001 future research actions:

- None for this target after the above actions. Broader `.EPF` literal deduplication across all 176 occurrences would be a separate campaign and should not block this physical address.

IDA DB actions:

- No IDA DB edits are recommended. Do not rename, create, or retype IDA entities solely for this report.

## Confidence

- Recommendation confidence: high / very strong.
- Score confidence: `87/92` is justified by resolved direct emitters, exact bytes, direct xrefs, interior negative checks, raw PE hidden-ref scan, and precedent comparison.
- Remaining uncertainty: original source could have used helper constants or macros, but no binary evidence proves that. The final reconstructed C++ use-site text remains future work, so the report does not recommend final source code.

## Validator Results

- Commands run: none. This report did not edit target/support docs or coverage reports.
- Results: not applicable.
- Any unresolved validator warnings/errors: none observed for this report scope.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003P9-shared-epf-suffix-source-routing.md`
- Modified: none outside B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003P9","source_path":"executed-b-agent-research/B001/0003P9-shared-epf-suffix-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
