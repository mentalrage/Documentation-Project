** TARGET-REPORT-UID:00006A **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00006A] HumanImageLib Class Source-Quality Refresh

Status: FINISHED  
Agent: B004  
Assignment: Report-only source-quality refresh  
Target: `by-class/HumanImageLib.md`  
Scope followed: edited only this report. No target/support by-* pages, generated files, shared coverage reports, IDA database, or `by-memory/-coverage-report.md` were edited.

## Recommendation Summary

Promote [UID:00006A] `HumanImageLib` from `85/86` to a better-documented `88/88` class page routed through [UID:0000JY] `by-file/HumanImageLib.md`.

Exact target metadata recommendation:

```text
COMPLETION:88
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000JY
EMITTER_UIDS:0000JY
```

Keep the source placement:

```text
NexusTK/render/HumanImageLib.cpp
```

The class is reconstructable and the owner/emitter route is correct. The class-level first-draft C++ body is not ready as a real class declaration because the method bodies, concrete old-human row structs, three cached resource pointers, one inherited/shared vtable slot, and lower old-human composition islands still need child-page source-quality resolution. Do not paste constructor/destructor bodies into the class page.

Recommended target `RECONSTRUCTION_CPP` policy:

```cpp
// Class-level declaration deferred: HumanImageLib is routed through render/HumanImageLib.cpp,
// but source-quality method bodies and concrete field declarations belong on the constructor,
// destructor, layout, vtable, global, and lower old-human child pages.
```

This is a no-code/defer proof, not a no-owner proof. If the supervisor prefers to keep class pages fully blank until real declarations are ready, leave the formal C++ block empty and retain the same no-code explanation in prose. The important implementation decision is that a class declaration or method bodies are not yet source-quality at the class level.

## Evidence Rechecked

Instruction and assignment sources read:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B004/goal.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Target and direct owner/support documents read:

- `by-class/HumanImageLib.md`
- `by-file/HumanImageLib.md`
- `by-type/by-struct/HumanImageLibLayout.md`
- `by-type/by-vtable/HumanImageLibVtable.md`
- `by-global/g_pHumanImageLib.md`
- `by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md`
- `by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md`
- `by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md`
- `by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md`
- `by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md`
- `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md`
- `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`
- `by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md`

Template/resource/sibling leads read and used as evidence, not proof by themselves:

- `by-file/ProtectedArray.md`
- `by-type/by-template/ProtectedArrayTemplates.md`
- `by-type/by-struct/ProtectedArrayLayout.md`
- `by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md`
- `by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md`
- `by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md`
- `by-file/EPFImageResources.md`
- `by-file/ImageFrameTable.md`
- `by-item/LoadImageFrameTable_004D0F50.md`
- `by-file/NewHumanImageLib.md`
- `by-file/ImageLib.md`
- `by-file/MapTileImageLib.md`
- `by-file/RidingImageLib.md`
- `by-file/LightObjImageLib.md`

Generated/current status sources read:

- `auto-generated/NexusTK/render/HumanImageLib.cpp`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-type-coverage.md`
- `auto-generated/-ag-global-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/by-memory-tool-report.md`
- `project-level/-auto-completion-stats.md`
- `by-class/-coverage-report.md`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`

Related report lead checked:

- `tools/leaser/Agents/Agent-B001/research/executed/older/0003M0-HumanImageLibScalarDeletingDestructor.md`

Fresh local PE validation:

```text
E:\NTK\Resources\NexusTK\NexusTK.exe
size   2679296
SHA256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
```

Fresh IDA MCP status: attempted `POST http://127.0.0.1:13337/mcp` for `tools/list`; the endpoint was not reachable from the shell (`Unable to connect to the remote server`). This report therefore treats existing dated live IDA evidence in the by-* pages as prior proof and supplements it with the fresh local PE/validator checks below. No IDA database writes were attempted.

Fresh scoped validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [00006A-HumanImageLib-class-source-quality-removed.md](00006A-HumanImageLib-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result summary: dry run, `ok: 1`; UID header accepted. Generated metadata was rebuilt in memory; dry run reported no target validation failure and left generated outputs unchanged because `--apply` was not passed.

## Current State

The target currently has:

```text
COMPLETION:85
CONFIDENCE:86
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000JY
EMITTER_UIDS:0000JY
```

The class page already records the correct high-level role: old human/equipment image library, singleton at `0x0069b43c`, vtable at `0x0061b6d4`, layout page, constructor/destructor/clear/scalar-wrapper child pages, and separation from `NewHumanImageLib`. Its main stale items are:

- the score has not caught up with the stronger file/layout/vtable/global/method evidence now available;
- it still references an obsolete "95/95 final-code gate" instead of the current source-quality/no-code reasoning;
- it uses `HumanImageLib::ClearSingleton` as if the clear helper were source-facing, while current file evidence says it is static cleanup glue;
- it does not consolidate the latest source-facing field/resource-family inferences and unresolved blockers;
- it does not say exactly which child pages should carry eventual C++.

The generated file currently contains only empty markers for the class and related children:

```text
auto-generated/NexusTK/render/HumanImageLib.cpp
```

The marker route is correct, but class-level source should remain comment-only or blank until the declaration and child method bodies are ready.

## Binary Facts

Fresh local PE checks revalidated the important ranges:

```text
0x004d2720-0x004d4aca len=9130 sha1=5c0bc3ccdc3d1fde727c29ad177d9ff91efaeb86
0x004d4aca-0x004d4ad0 len=6    bytes=cc cc cc cc cc cc
0x004d4ad0-0x004d4f67 len=1175 sha1=ec743b84a8dd3fec9d4ae23fa1da4b427c12c7a0
0x004d4f67-0x004d4f70 len=9    bytes=cc cc cc cc cc cc cc cc cc
0x004e5b80-0x004e5b8b len=11   sha1=a425938d554f4d08f295658bba87f4f371c6dec5
0x004e6460-0x004e649b len=59   sha1=d56aebb94acd210fa335176df3bf32cfd29c4343
0x004e649b-0x004e64a0 len=5    bytes=cc cc cc cc cc
0x0061b6d0-0x0061b6e0 len=16   sha1=5e86522497b41b85e8ec29a70b7ca5a33e78d55c
```

Fresh vtable dwords:

```text
0x0061b6d0: 0x00648814
0x0061b6d4: 0x004e6460
0x0061b6d8: 0x004f4b10
0x0061b6dc: 0x0041b6c0
```

Fresh rel32 scan:

```text
rel32_to_0x004d2720: none
rel32_to_0x004d4ad0: 0x004e6466 call
rel32_to_0x004e5b80: 0x005ffaf2 jump
rel32_to_0x004e6460: none
```

Interpretation:

- The constructor still has no direct executable caller evidence in the raw scan, matching existing IDA evidence.
- The ordinary destructor is directly called by the scalar deleting destructor.
- The singleton-clear helper is reached from the constructor cleanup funclet.
- The scalar deleting destructor is vtable-referenced rather than direct-call referenced.
- The vtable range and padding/range boundaries are exact enough for metadata and source routing.

The raw file did not expose reliable initialized bytes for `0x0069b43c` in this local scan because that storage is in the virtual data tail; the current global/backing pages remain the authority for the singleton storage xrefs and initialization note.

## Metadata And Score Justification

Recommended `88/88` is above the current `85/86` because the class role, owner, emitter route, class/file placement, exact lifetime children, vtable, singleton, layout, ProtectedArray template boundary, ImageFrameTable helper boundary, old/new human split, and sibling library exclusions are now all supported by multiple current pages plus fresh PE range checks.

Do not use `85/85` as a stopping point. The target is no longer merely "reconstructable if squinting"; it has:

- exact constructor/destructor/helper/scalar-wrapper ranges and padding;
- a direct vtable row with RTTI pointer and three slot targets;
- singleton write/clear lifecycle evidence;
- a mapped embedded layout through `+0x2b0`;
- a concrete source file route in `render/HumanImageLib.cpp`;
- clear rejection of `NewHumanImageLib`, `ImageLib`, `ImageFrameTable`, `EPFImageResources`, `ProtectedArray`, and sibling image-library owners.

The recommendation stays below `90` because the class still lacks safe final declarations for the old-human row structs, exact cached resource pointer names at `+0x24c/+0x250/+0x254`, one inherited/shared vtable slot at `0x004f4b10`, exact source names for several shared table helpers, and lower composition child splits from the broad local cluster.

Owner/emitter recommendation:

- Keep `CANONICAL_OWNER:0000JY` on the class page because the class belongs to the `HumanImageLib.cpp` source file.
- Keep `EMITTER_UIDS:0000JY` so the generated destination remains `auto-generated/NexusTK/render/HumanImageLib.cpp`.
- Keep [UID:0002TO] constructor and [UID:0003M0] scalar deleting destructor routed through class [UID:00006A].
- Change [UID:00017B] ordinary destructor direct owner/emitter from file [UID:0000JY] to class [UID:00006A] in a later implementation pass; it is a class destructor, and the old "class below gate" reason is stale.
- Keep [UID:00017X] clear helper owner/emitter at file [UID:0000JY]; it is static cleanup glue with no `this`.

## Heuristic / Inference Reanalysis And Validation

### Raw And Compiler-Generated Names

`sub_4D2720` is safely `HumanImageLib::HumanImageLib`. Evidence checked: target class, file page, constructor page, local method cluster, fresh PE range/padding, singleton store, vtable install, DAT/table initialization, and no direct caller evidence. No alternate source owner is stronger.

`sub_4D4AD0` is safely `HumanImageLib::~HumanImageLib`. Evidence checked: destructor page, scalar deleting destructor call at `0x004e6466`, vtable restore, singleton clear, frame-handle releases, ProtectedArray cleanup, and fresh range/padding scan. Its by-memory metadata should be rerouted to class [UID:00006A].

`sub_4E5B80` / `ClearHumanImageLibSingleton` should not become a source-facing helper name. Evidence checked: clear-helper page, file cleanup audit, fresh bytes `c7 05 3c b4 69 00 00 00 00 00 c3`, no `this`, no callees, and constructor cleanup jump at `0x005ffaf2`. Best source-facing treatment: static cleanup thunk generated by the constructor/static lifetime path. Keep the descriptive page name but do not emit `ClearHumanImageLibSingleton` as hand-authored C++.

`sub_4E6460` is the compiler-emitted scalar deleting destructor. Evidence checked: class/vtable/scalar pages and the executed scalar-wrapper report. It should remain class-owned generated-binary support with no handwritten source body.

`dword_69B43C` is best documented as `g_pHumanImageLib`. Evidence checked: global/backing pages record exactly constructor publish/null-clear, destructor clear, and clear-helper clear. Final original symbol spelling is not proven, but `g_pHumanImageLib` is the best source-facing name for docs and generated comments.

`??_7HumanImageLib@@6B@` and `??_R4HumanImageLib@@6B@` are compiler artifacts from the class declaration and RTTI, not hand-authored tables. Keep vtable/data pages blank or comment-only; the future class declaration should produce the vtable.

`sub_4F4AC0` is a shared delete/operator-delete support function reached by the scalar deleting destructor. It is not HumanImageLib source.

`@_guard_check_icall_nop@4` is compiler/guard support, not HumanImageLib source.

`sub_4F4B10` and `nullsub_18` remain unresolved inherited/shared vtable slots. Evidence checked: vtable page, vtable data page, surrounding RTTI/vtable boundary, project unresolved list, and sibling source docs. There is not enough proof to assign final source names. Use descriptive labels such as "inherited/shared virtual slot at 0x004f4b10" and "no-op virtual slot" until the base class/vtable family is audited.

`sub_4E6AE0` and `sub_4E6C50` are shared old-human table loaders used by the constructor. Best high-probability inference: `0x004e6ae0` loads head/head-special style old-human image-info tables; `0x004e6c50` loads weapon/equipment table families. Do not promote final names yet because their source-facing declarations and broader caller ownership are not audited.

`ProtectedArray_struct_*` names are generated template-instantiation names. Source-facing type model should be `ProtectedArray<T>` with concrete record types such as `HeadInfo`, `BodyInfo`, `WeaponInfo`, etc. The reusable template support belongs to [UID:0000MU] `ProtectedArray`; HumanImageLib owns the embedded concrete fields and caller context.

### Field, Type, And Resource-Family Names

Use the current layout names as the best source-facing field family:

```text
+0x004 headArray
+0x020 headSpecialArray
+0x03c bodyArray
+0x05c coatArray
+0x080 swordWeaponArray
+0x0a0 spearWeaponArray
+0x0c0 bowWeaponArray
+0x0e0 fanWeaponArray
+0x100 shieldWeaponArray
+0x120 arrowWeaponArray
+0x140 faceArray
+0x15c acc1Array
+0x17c hairArray
+0x19c acc2Array
+0x1c0 helmetArray
+0x1e0 mantleArray
+0x200 necklaceArray
+0x220 shoeArray
+0x24c cachedResource0
+0x250 cachedResource1
+0x254 cachedResource2
+0x268..+0x2ac loaded frame-library handles
```

The weapon/equipment offsets are strongly supported by constructor table-string evidence:

```text
swordtable  -> +0x080
speartable  -> +0x0a0
bowtable    -> +0x0c0
fantable    -> +0x0e0
shieldtable -> +0x100
arrowtable  -> +0x120
```

The `ACE1`/`ACE2` strings are best represented as `acc1Array` and `acc2Array`; `Accessory1`/`Accessory2` are acceptable prose alternatives, but the shorter names align with the binary resource names. `NECLACE` and `EMOTIOSP` must remain exact when quoting file/resource strings, while source-facing prose can use `Necklace` and `EmotionSpecial`.

Do not lock the three cached pointer names beyond `cachedResource0..2` or equivalent placeholders. Evidence checked: layout/destructor pages show optional cleanup at `+0x24c`, `+0x250`, and `+0x254`, but no current support page identifies the exact resource family or field names. This is a real score/C++ limiter.

Do not lock a final declaration order for the 18 frame handles solely from destructor release order. The destructor releases offsets in the observed order:

```text
+0x268, +0x26c, +0x278, +0x270, +0x274, +0x280, +0x284, +0x27c,
+0x288, +0x28c, +0x294, +0x290, +0x298, +0x29c, +0x2a0, +0x2a4,
+0x2a8, +0x2ac
```

This confirms the field block and cleanup behavior, but not enough by itself to assign every handle a final member name. Constructor call order and `LoadImageFrameTable` resource-family prefixes should be cross-checked before writing a class declaration.

### Old-Human Table Declarations

The constructor references old-human table and EPF families including:

```text
DRWORDER.TBL, HEAD.TBL, HEADSP.TBL, BODY.TBL, SWORD.TBL, SPEAR.TBL,
BOW.TBL, FAN.TBL, SHIELD.TBL, ARROW.TBL, XDRWORD.TBL, XDRWORD2.TBL,
FACE.TBL, HAIR.TBL, ACE1.TBL, ACE2.TBL, HELMET.TBL, MANTLE.TBL,
NECLACE.TBL, SHOES.TBL, COAT.TBL, ACC2DRW.TBL, HAIRCOL.TBL
```

and EPF/frame families including:

```text
HEAD, EMOTION, HEADSP, EMOTIOSP, BODY, SWORD, SPEAR, BOW, FAN, SHIELD,
ARROW, FACE, HAIR, ACE1, ACE2, HELMET, MANTLE, NECLACE, SHOES, COAT
```

The best high-probability row-type names are:

```text
HeadInfo, BodyInfo, CoatInfo, WeaponInfo, FaceInfo, Acc1Info, HairInfo,
Acc2Info, HelmetInfo, MantleInfo, NecklaceInfo, ShoeInfo
```

However, the current evidence does not prove exact source struct declarations or all member names. `ProtectedArrayTemplates` still records an old-human `0x0c` stride accessor with unknown exact record type/name. This blocks a source-quality class declaration and constructor C++ but does not block class metadata/owner cleanup.

### Constructor Source Structure

The constructor child [UID:0002TO] is the correct future owner for constructor C++. It should be emitted as phased source, not as a raw decompiler dump:

1. base `LObject` setup and singleton/vtable publication;
2. `ProtectedArray<T>` member initialization;
3. DAT table open/read/close phases;
4. frame-table loading through `LoadImageFrameTable`;
5. EPF/count validation and error flag handling;
6. old-human accessory/color table parsing;
7. fatal messagebox/load-dll path and EH cleanup funclets.

The class page should not absorb this body. The constructor remains below first-draft C++ readiness because helper names, row declarations, and lower composition boundaries are not source-quality.

### Destructor, Singleton, Vtable, And Scalar Wrapper

Relationship decision:

- `HumanImageLib::~HumanImageLib` belongs under class [UID:00006A].
- The scalar deleting destructor belongs under class [UID:00006A] as generated-binary support with no hand-authored source.
- The singleton global belongs to the file/class context but emits through file [UID:0000JY].
- The clear helper is static cleanup glue and should stay file-owned [UID:0000JY].
- Vtable data and RTTI should stay source-declared/generated-binary; do not emit raw dword tables.

The ordinary destructor is the best first method-body C++ candidate after support routing is corrected, because its behavior is much smaller and more deterministic than the constructor. It still should not be emitted at class level.

### Active Old-Human Boundary And Sibling Exclusions

Keep `HumanImageLib` separate from:

- [UID:0000LR] `NewHumanImageLib`: new table-driven motion/layer/part model and distinct singleton at `0x0067a760`;
- [UID:0000K2] `ImageLib`: broad shared image library concerns, not old-human owner;
- [UID:0000K1] `ImageFrameTable`: owns the reusable `LoadImageFrameTable` helper, not the HumanImageLib caller fields;
- [UID:0000MU] `ProtectedArray`: owns reusable template support, not concrete old-human member fields;
- `EPFImageResources`: umbrella/resource evidence only, not source owner;
- sibling image libraries such as `MapTileImageLib`, `RidingImageLib`, and `LightObjImageLib`: each has its own file/global/vtable/resource family.

The broad local cluster [UID:00017A] still contains lower old-human composition code and child functions beyond the constructor/destructor. That cluster proves the source file boundary but should not cause class-level C++ emission. Future child splits should be made for at least the old-human composition island around `0x004d58bd-0x004d696a` and modeled lower functions such as `0x004d8ee0`, `0x004d8ef0`, `0x004d8f40`, `0x004d8fb0`, `0x004d90e0`, `0x004d9180`, and `0x004da850`.

## Class-Level C++ Readiness Decision

Class-level first-draft C++ is not ready as a real declaration or implementation.

Target-specific defer proof:

- The class page is an ownership and routing node, while method bodies belong on exact child pages.
- Constructor C++ would require unresolved table row declarations, helper names, EH cleanup structure, and lower composition child boundaries.
- Destructor C++ is a better first body candidate, but it belongs on [UID:00017B], not on the class page.
- The layout page has strong offsets but still lacks final member names for cached resources and all frame handles.
- The vtable page has one inherited/shared slot without a final source name.
- The scalar deleting destructor and vtable data are compiler-generated and should regenerate from class/destructor shape, not be hand-coded.

Exact child pages that should carry future code:

- [UID:0002TO] `by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md`: eventual constructor body after table row structs/helper names are resolved.
- [UID:00017B] `by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md`: likely first method-body C++ candidate after owner/emitter reroute to [UID:00006A] and field names are normalized.
- [UID:0001UR] `by-type/by-struct/HumanImageLibLayout.md`: eventual field declaration support, not method code, after cached resource and frame-handle names are safer.
- [UID:0001XQ] `by-type/by-vtable/HumanImageLibVtable.md` and [UID:00036H] vtable data: no raw table C++; class declaration/virtual method shape should regenerate these.
- [UID:0000R5]/[UID:0001PM] singleton docs: eventual declaration only if the global/source initialization form is coordinated; do not emit duplicate definitions ad hoc.
- [UID:00017X] clear helper and [UID:0003M0] scalar deleting destructor: remain blank/comment-only no-code generated/static-cleanup proofs.

## Exact Implementation Checklist

### Target `by-class/HumanImageLib.md`

1. Set metadata to:

```text
COMPLETION:88
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000JY
EMITTER_UIDS:0000JY
```

2. Replace stale `95/95 final-code gate` wording with the current no-code/defer proof from this report.
3. Add a dedicated heuristic/source-quality section covering:
   - raw/generated names and accepted source-facing names;
   - constructor/destructor/clear/scalar relationship;
   - old-human row/table/resource-family inferences;
   - active old-human vs NewHumanImageLib split;
   - ProtectedArray template-vs-concrete-field boundary;
   - sibling image-library owner exclusions;
   - unresolved cached resources/frame handles/inherited vtable slot.
4. Change the method row label from `HumanImageLib::ClearSingleton` to prose such as `HumanImageLib singleton clear thunk` or `static cleanup singleton clear helper`; make clear it is not a source-facing method.
5. Add the comment-only `RECONSTRUCTION_CPP` block if supervisor wants non-empty no-code emitters; otherwise leave formal C++ blank and retain the defer proof.
6. Add Rule 26 history entry summarizing the B004 report and metadata/no-code decision.

### Support Docs

1. `by-file/HumanImageLib.md`
   - Update class reference from `85/86` to `88/88`.
   - Replace "constructor field names and helper names reach final-audit quality" with a more exact no-code reason: class declaration/method bodies deferred to children; cached resources, row structs, inherited slot, and lower composition splits remain unresolved.
   - Clarify again that `ClearHumanImageLibSingleton` is descriptive cleanup-thunk wording, not a formal source helper.
   - Add Rule 26 history.

2. `by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md`
   - Change `CANONICAL_OWNER` and `EMITTER_UIDS` from [UID:0000JY] to [UID:00006A].
   - Remove stale "class below gate" parent explanation.
   - Keep score `86/91` unless the implementation pass adds new evidence.
   - Add note that this child, not the class page, is the likely first destructor C++ candidate.
   - Add Rule 26 history.

3. `by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md`
   - Replace stale final-code-gate wording with current source-shape blockers.
   - Add the best field/resource-family names and rejected raw helper/name alternatives.
   - Keep owner/emitter [UID:00006A].
   - Add Rule 26 history.

4. `by-type/by-struct/HumanImageLibLayout.md`
   - Normalize field names listed in this report.
   - Keep cached resources explicitly unresolved.
   - State destructor release order is cleanup order, not final declaration proof.
   - Add Rule 26 history.

5. `by-type/by-vtable/HumanImageLibVtable.md`
   - Replace stale direct-parent score references with `88/88`.
   - Preserve unresolved `0x004f4b10` and `nullsub_18` caveats.
   - Add Rule 26 history.

6. `by-global/g_pHumanImageLib.md` and `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md`
   - No owner change recommended.
   - Optionally add that `g_pHumanImageLib` is the accepted source-facing descriptive name while exact original symbol spelling remains unproven.
   - Do not emit a duplicate global definition until global/source initialization is coordinated.

7. `by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md`
   - No owner/emitter change.
   - Keep formal C++ blank/comment-only.
   - Confirm descriptive alias only; no source-facing `ClearHumanImageLibSingleton`.

8. `by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md`
   - No owner/emitter change.
   - Keep formal C++ blank/comment-only as compiler-generated scalar deleting destructor.

9. `by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md`
   - No owner/emitter change.
   - Keep raw dword C++ blank/comment-only; class declaration should regenerate it.

10. ProtectedArray support pages
    - No metadata change required.
    - Only add cross-reference wording if implementing target-level links; reusable template source remains [UID:0000MU].

### Supervisor-Owned Coverage Row

Do not edit `by-class/-coverage-report.md` during report-only work. Exact replacement row for supervisor/later implementation:

```text
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) : reconstructable : 88% : strong : Legacy old-human/equipment image-library class routed through [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md); B004 source-quality reanalysis validates the render/HumanImageLib.cpp owner, old/new human split, singleton/vtable/global/layout anchors, constructor/destructor/clear/scalar-wrapper relationships, ProtectedArray template-vs-concrete-field boundaries, old-human table/resource-family names, and sibling image-library exclusions; class-level formal C++ remains comment-only/deferred because method bodies belong to constructor/destructor child pages and exact row structs, cached resources, inherited virtual slot, and lower composition child splits remain unresolved.
```

### Validator Commands After Implementation

Run these with `--apply` for edited by-* docs:

> Executable block R002 was removed from this report and preserved verbatim in [00006A-HumanImageLib-class-source-quality-removed.md](00006A-HumanImageLib-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If supervisor applies the coverage row, also run:

> Executable block R003 was removed from this report and preserved verbatim in [00006A-HumanImageLib-class-source-quality-removed.md](00006A-HumanImageLib-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-generation inspections:

_Executable command block removed from the research report; preserved in [00006A-HumanImageLib-class-source-quality-removed.md](00006A-HumanImageLib-class-source-quality-removed.md)._

## Completion Note

This report resolves the target-level source-quality question: HumanImageLib should be `88/88`, remain owned/emitted through `HumanImageLib.cpp`, avoid class-level real C++ for now, and delegate future method bodies to exact children. The unresolved issues are now documented as targeted blockers rather than generic open questions.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00006A-HumanImageLib-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00006A"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00006A-HumanImageLib-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00006A-HumanImageLib-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00006A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
