*** UID:0000JY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HumanImageLib

## Status

- Confidence: strong for source-module ownership, singleton/vtable/layout anchors, old-human lifetime evidence, and direct class-parent routing; medium-high for constructor internals until field names and table-row declarations are audited.
- Proposed module: `render/HumanImageLib.cpp`
- Main address ranges: `0x004d2720-0x004d4f67` and `0x004e6460-0x004e649b`
- Primary global instance: [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`.
- Primary vtable: [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md).
- Layout anchor: [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## File Role

`HumanImageLib` is the older human body/equipment image library. It initializes ProtectedArray-style tables for body parts and equipment, loads many human sprite frame-table archives through [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md), and tears down the loaded part image-library handles.

This should remain a separate render/image source file. The class is tightly coupled to the old human asset families and is different from [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), which uses `Motion.tbl`, `Layer.tbl`, `Part.tbl`, and part-composition data.

The concrete `ProtectedArray<...Info>` helper files for old-human parts are template instantiations, not separate original modules. Keep their reusable template support under [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), while this file owns the human/equipment table loading and the embedded array fields. [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) is therefore a ProtectedArray template-source child with old-human caller/field evidence, not a direct `HumanImageLib.cpp` child. IDA confirms the adjacent old-human `ProtectedArray` vtables immediately before the class vtable at `0x0061b6d4`.

The exact constructor page [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md) now carries the detailed IDA evidence for the table names, EPF validation path, singleton/vtable writes, and external helper calls. Keep final C++ out of this file until the constructor's field names and helper names reach final-audit quality.

## Resource Families

The constructor calls the shared frame-table loader repeatedly for human/equipment archives. Observed merge prefixes from the shared loader include:

```text
HEAD, HEADSP, BODY, SWORD, SPEAR, BOW, FAN, SHIELD, ARROW,
FACE, HAIR, ACE1, ACE2, HELMET, MANTLE, NECLACE, SHOES, COAT
```

The destructor releases 18 body/equipment frame-library handles at object offsets `0x268` through `0x2ac`, then frees embedded `ProtectedArray` buffers for head, body, coat, weapon/equipment, face, accessory, hair, helmet, mantle, necklace, and shoe records. The [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md) records the IDA-confirmed object-relative form.

## Lifetime And Singleton

IDA confirms [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`. The constructor writes it at `0x004d277b`, the ordinary destructor clears it at `0x004d4f44`, and the tiny [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) clears it at `0x004e5b80`.

The scalar-deleting wrapper at `0x004e6460-0x004e649b` calls the ordinary destructor, optionally deletes through `sub_4F4AC0`, and uses the guard-check path when bit `4` is set. It belongs with this file, but still needs its own validator-registered by-memory page before other pages can UID-link it.

Do not confuse this old-human singleton with the newer table-driven human singleton at `0x0067a760`, which is cleared by `0x004e5be0` and appears in the application shutdown sequence.

2026-06-07 Batch 090 live IDA MCP reconfirmed the direct parent gate for [UID:00006A][HumanImageLib](by-class/HumanImageLib.md): constructor `0x004d2720-0x004d4aca` writes `g_pHumanImageLib` and installs `HumanImageLib` vtable `0x0061b6d4`, the ordinary destructor `0x004d4ad0-0x004d4f67` clears the singleton and restores the same vtable, the clear helper `0x004e5b80-0x004e5b8b` writes only `g_pHumanImageLib`, and the scalar deleting destructor `0x004e6460-0x004e649b` is vtable-referenced and calls the ordinary destructor before optional delete. These are all old-human image-library lifetime paths and do not overlap [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).

## Ownership Decision

The old human library should not be collapsed into `ImageLib.cpp`. It is a consumer of the shared frame-table loader, but it owns human/equipment-specific protected arrays, frame-table handles, and old-human lifetime rules.

## Parent Gate Rationale

- Completion remains `85`: the source root, singleton/vtable/layout anchors, constructor/destructor/clear/scalar-wrapper boundaries, resource-family strings, ProtectedArray lifetime, and direct class routing are documented; final field names, table-row declarations, and old-human composition islands remain open.
- Confidence rises to `85`: live IDA evidence confirms the class/file lifetime anchors and direct old-human ownership strongly enough for [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) assignment, while the large constructor internals still cap confidence below higher final-audit levels.

## Cross-References

- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:00017A][0x004d2720-0x004e649b.HumanImageLib](by-memory/0x004d2720-0x004e649b.HumanImageLib.md)
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
