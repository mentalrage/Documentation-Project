*** UID:0000JY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HumanImageLib

## Status

- Confidence: very strong for the focused header/source route, complete bounded declaration/lifetime union, source order, one-definition behavior, loader helpers, dependencies, and compiler/data exclusions; descriptive private/helper spelling caps confidence below 95.
- Proposed module: `render/HumanImageLib.cpp`
- Main address ranges: `0x004d2720-0x004dac40`, singleton clear helper `0x004e5b80-0x004e5b8b`, and scalar destructor `0x004e6460-0x004e649b`
- Primary global instance: [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`.
- Primary vtable: [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md).
- Layout anchor: [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## File Role

`HumanImageLib` is the older human body/equipment image library. It initializes ProtectedArray-style tables for body parts and equipment, loads many human sprite frame-table archives through [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md), and tears down the loaded part image-library handles.

This should remain a separate render/image source file. The class is tightly coupled to the old human asset families and is different from [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), which uses `Motion.tbl`, `Layer.tbl`, `Part.tbl`, and part-composition data.

The concrete `ProtectedArray<...Info>` helper files for old-human parts are template instantiations, not separate original modules. Keep their reusable template support under [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), while this file owns the human/equipment table loading and the embedded array fields. [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) is therefore a ProtectedArray template-source child with old-human caller/field evidence, not a direct `HumanImageLib.cpp` child. IDA confirms the adjacent old-human `ProtectedArray` vtables immediately before the class vtable at `0x0061b6d4`.

The complete bounded source union is now source-ready: UID00006A emits the declaration, UID0000R5 emits the sole zero-initialized global, UID0002TO/UID00017B emit constructor/destructor bodies, and UID0004DK/UID0004DL emit the two file-local table loaders. Singleton clear, scalar deletion, vtable/RTTI data, physical slot, and mixed aggregate remain documented compiler/data/index evidence with no duplicate source.

## Current Source Order And Dependencies

| Position | UID | Source role |
| --- | --- | --- |
| `10` | UID00006A | Complete `HumanImageLib` class declaration in `HumanImageLib.h`. |
| `20` | UID0000R5 | Sole `HumanImageLib *g_pHumanImageLib = 0;` definition. |
| `30` | UID0002TO | Authored constructor orchestration. |
| `40` | UID00017B | Authored ordinary destructor. |
| `50` | UID0004DK | File-local 12-byte HeadInfo table loader. |
| `60` | UID0004DL | File-local 16-byte WeaponInfo table loader. |

- Existing `ProtectedArray<T>`, DATFile encoded-int reading, ImageFrameTable loading/releasing, resource layout, LObject, and Singleton declarations remain dependencies, not source owners.
- Physical UID0001PM, UID00017X Singleton cleanup, UID0003M0 scalar deletion, UID0001XQ/UID00036H vtable data, and UID00017A aggregate emit no source body.
- `HumanImageLib` remains separate from NewHumanImageLib and all MapTile/Riding/Monster/Static/Effect/Item/Light image-library source families.

## 2026-06-14 C001 IDA MCP Refresh

- Current IDA MCP health reports active database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the key old-human lifetime bodies: constructor `0x004d2720` size `0x23aa` / 9130 bytes, ordinary destructor `0x004d4ad0` size `0x497` / 1175 bytes, singleton-clear helper `0x004e5b80` size `0x0b`, and scalar deleting destructor `0x004e6460` size `0x3b` / 59 bytes. Size conversions were verified with `tools/int_convert.py`.
- `analyze_component` records the constructor as a 238-basic-block, complexity-86 body with old-human table strings and calls into DAT/resource-layout, frame-table loader, `ProtectedArray` accessors, fatal cleanup, and parser helpers. The scalar deleting destructor has the only internal edge to the ordinary destructor.
- `xrefs_to` reconfirmed no direct code refs to the constructor, one executable caller of the ordinary destructor from `0x004e6466`, the scalar deleting destructor vtable slot at `0x0061b6d4`, HumanImageLib vtable stores from constructor/destructor at `0x004d278c` and `0x004d4afd`, and `g_pHumanImageLib` refs at `0x004d277b`, `0x004d2782`, `0x004d4f44`, and `0x004e5b80`.
- `find_regex` found the HumanImageLib and `Singleton<HumanImageLib>` RTTI strings at `0x00676790` and `0x006767ac`, plus old-human table strings `headtable.txt`, `headsptable.txt`, `swordtable.txt`, `speartable.txt`, `bowtable.txt`, `fantable.txt`, `shieldtable.txt`, and `arrowtable.txt` at `0x0061b944-0x0061ba54`.
- Current component shared globals show the constructor and ordinary destructor both touch the adjacent old-human `ProtectedArray<...Info>` vtables from `0x0061b674` through `0x0061b6cc`, then the `HumanImageLib` vtable at `0x0061b6d4`. This reinforces the split from [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) and the placement under `render/HumanImageLib.cpp`.

## Resource Families

The constructor calls the shared frame-table loader repeatedly for human/equipment archives. Observed merge prefixes from the shared loader include:

```text
HEAD, HEADSP, BODY, SWORD, SPEAR, BOW, FAN, SHIELD, ARROW,
FACE, HAIR, ACE1, ACE2, HELMET, MANTLE, NECLACE, SHOES, COAT
```

The destructor releases 18 body/equipment frame-library handles at object offsets `0x268` through `0x2ac`, then frees embedded `ProtectedArray` buffers for head, body, coat, weapon/equipment, face, accessory, hair, helmet, mantle, necklace, and shoe records. The [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md) records the IDA-confirmed object-relative form.

## Lifetime And Singleton

IDA confirms [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`. The constructor writes it at `0x004d277b`, the ordinary destructor clears it at `0x004d4f44`, and the tiny [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) clears it at `0x004e5b80`.

B003's 2026-06-17 cleanup audit classifies [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) as old-Human file-level constructor/static cleanup glue. The local PE bytes are exactly `c7 05 3c b4 69 00 00 00 00 00 c3`, the helper has no `this` and no callees, and it only zeros old-human `g_pHumanImageLib`; existing evidence records the constructor cleanup jump at `0x005ffaf2`. Do not emit a source helper such as `ClearHumanImageLibSingleton`: simroot's spelling is source-lead pollution, and the source-level construct is the constructor/static lifetime path that generated the cleanup thunk.

The scalar-deleting wrapper at [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md) calls the ordinary destructor, optionally deletes through `sub_4F4AC0`, and uses the guard-check path when bit `4` is set. It belongs with this file as compiler-generated destructor glue.

Do not confuse this old-human singleton with the newer table-driven human singleton at `0x0067a760`, which is cleared by `0x004e5be0` and appears in the application shutdown sequence.

2026-06-07 Batch 090 live IDA MCP reconfirmed the direct parent gate for [UID:00006A][HumanImageLib](by-class/HumanImageLib.md): constructor `0x004d2720-0x004d4aca` writes `g_pHumanImageLib` and installs `HumanImageLib` vtable `0x0061b6d4`, the ordinary destructor `0x004d4ad0-0x004d4f67` clears the singleton and restores the same vtable, the clear helper `0x004e5b80-0x004e5b8b` writes only `g_pHumanImageLib`, and the scalar deleting destructor `0x004e6460-0x004e649b` is vtable-referenced and calls the ordinary destructor before optional delete. These are all old-human image-library lifetime paths and do not overlap [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).

## Ownership Decision

The old human library should not be collapsed into `ImageLib.cpp`. It is a consumer of the shared frame-table loader, but it owns human/equipment-specific protected arrays, frame-table handles, and old-human lifetime rules.

## B004 Source-Quality Routing Notes

[UID:00006A][HumanImageLib](by-class/HumanImageLib.md) is now `92/93` and remains routed through this `91/92` file. The current source-quality split is:

- the class page is the complete declaration emitter at position 10;
- [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md) owns the authored constructor body at position 30;
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md) owns the authored ordinary destructor at position 40;
- [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) remains file-owned cleanup glue and should not emit a formal `ClearHumanImageLibSingleton` source helper;
- [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md), [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md), and [UID:00036H][0x0061b6d0-0x0061b6e0.HumanImageLibVtableData](by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md) are generated-binary artifacts that should regenerate from source declarations and virtual destructor shape.

The accepted descriptive names are `g_pHumanImageLib`, the complete layout vocabulary from UID0001UR, and `LoadHumanHeadInfoTable` / `LoadHumanWeaponInfoTable`. The former `cachedResource0..2` interpretation is rejected: these fields are the three owned draw-order arrays. `sub_4F4B10` and `nullsub_18` are inherited LObject slots.

B011's split children [UID:0004DK][0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable](by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md) and [UID:0004DL][0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable](by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md) are now source-ready file-local helpers at positions 50/60. Their exact two/six constructor callsets, existing DATFile argument, narrow source-name argument, fallback records, positive-count resize, encoded-int reads, shared load-error latch, row sizes, and WeaponInfo halfword swap remain file-owned here rather than generic VectorHelpers source.

## Parent Gate Rationale

- Completion is `91`: the focused source root, complete class declaration, sole global definition, constructor/destructor, both bounded loader helpers, exact order, dependencies, compiler/data exclusions, and generated one-definition expectations are closed. Lower composition islands remain independently queued and do not block this bounded source union.
- Confidence is `92`: current IDA/PE/docs converge on ownership, boundaries, types, layout, calls, resources, and source/compiler separation; descriptive private/helper spelling prevents a 95-level lexical claim.

## Historical / Superseded Assumptions

- The former comment-only class, eventual constructor/destructor, cached-resource placeholders, unresolved inherited slots, and comment-only table-helper conclusions are superseded by the accepted UID0001PM source-quality closure.
- Historical Wave2/Wave3 source shapes remain non-authoritative and are not imported into this focused module.

## Cross-References

- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:00017A][0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster](by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md)
- [UID:0004DK][0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable](by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md)
- [UID:0004DL][0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable](by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md)
- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: source ownership, old-human resource families, singleton/vtable/layout anchors, destructor release behavior, and split from `NewHumanImageLib` are documented; confidence remains medium-high because constructor row structures, final field names, and protected-array/template boundaries still need deeper review.

- 2026-05-31 projected path and IDA range correction:
  - What existed before: projected reconstruction path was blank and main range text used one-byte-short exclusive ends.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, scores `85/82`, main ranges `0x004d2720-0x004d4f67` and `0x004e6460-0x004e649b`.
  - Summary/evidence: `proposed-source-tree.md` places `HumanImageLib.cpp` under `render/`, and IDA MCP verified the corrected function ends and singleton/vtable xrefs.

- 2026-06-06 stale provenance cleanup and wrapper note:
  - What existed before: status and resource notes still pointed at obsolete non-IDA source provenance, and the file cross-references omitted the singleton clear-helper page.
  - Changed to: removed the obsolete source-path provenance, replaced the non-IDA handle note with the IDA-confirmed layout reference, added the [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) cross-reference, and recorded the scalar-deleting wrapper behavior as pending a standalone by-memory page.
  - Summary/evidence: IDA MCP on 2026-06-06 reconfirmed the constructor/destructor/helper/scalar-wrapper bounds, the `g_pHumanImageLib` and vtable xrefs, and the scalar wrapper's ordinary-destructor, delete, and guard-check callees. Scores are unchanged because constructor internals and final source declarations still need deeper audit.

- 2026-06-07 A006 Batch 090 parent-gate refresh:
  - Before: score was `85/82`, below the corrected confidence gate for assigning [UID:00006A][HumanImageLib](by-class/HumanImageLib.md).
  - Changed to: score `85/85` with direct class-parent routing evidence.
  - Summary/evidence: live IDA MCP reconfirmed constructor/destructor/clear/scalar-wrapper bounds, singleton writes/clears, vtable refs, old-human resource-loader dependencies, and separation from `NewHumanImageLib`. Remaining constructor field/table-name work keeps the score conservative and final C++ blank.
- 2026-06-08 A003 Batch122: Added reciprocal ownership clarification for [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md).
  - Before: the file stated that ProtectedArray helper files are template instantiations but did not link the exact accessor cluster.
  - After: the file role and cross-references clarify that HumanImageLib owns the concrete old-human fields/callers, while [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) owns the reusable accessor source body.
  - Summary/evidence: Batch122 IDA xref grouping shows the accessors are used by the HumanImageLib constructor and old-human composition code, but their common body is the shared `ProtectedArray<T>` fallback accessor template.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad HumanImageLib memory aggregate is now [UID:00017A][0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster](by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md), and the scalar deleting destructor now has [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md).
  - Evidence: live IDA `entity_query` on 2026-06-12 proved the old `0x004d2720-0x004e649b` aggregate crossed Monster/Static/Effect/Item/Light/NewHuman sibling owners.
- 2026-06-14 C001 Goal 2 score pass: Raised `85/85 -> 87/88`.
  - Summary/evidence: current IDA 9.1 MCP reconfirmed constructor/destructor/clear/scalar-wrapper sizes, scalar-to-ordinary destructor edge, vtable and singleton xrefs, HumanImageLib RTTI strings, old-human table strings, and shared `ProtectedArray<...Info>` vtable touches. No owner/emitter route changed.
- 2026-06-17 B003 singleton-clear cleanup audit:
  - Score unchanged at `87/88`.
  - Summary/evidence: incorporated the no-code source-form proof for [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md): exact singleton-zero PE bytes, constructor cleanup jump evidence, no `this`, no callees, old-human singleton-only write, file-owner route, and rejection of simroot's clear-helper spelling as formal source.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Score unchanged at `87/88`, but the class reference is now [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) `88/88`.
  - Summary/evidence: incorporated the source-quality routing policy from B004: class-level C++ is comment-only/deferred, constructor/destructor method bodies belong to exact children, clear helper spelling is descriptive cleanup-thunk wording only, scalar/vtable bytes are generated artifacts, and unresolved cached resources, row structs, inherited virtual slot, shared helper names, and lower composition splits remain the real C++ blockers.
- 2026-07-21 B001 accepted UID0001PM callback: raised to `91/92`, established the complete `HumanImageLib.h/.cpp` union and positions 10-60, synchronized the sole global/class/lifetime/helper emitters and all compiler/data exclusions, and historicalized the former deferred/placeholder conclusions without removing lower-island history.
