*** UID:0000JY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HumanImageLib

## Status

- Confidence: strong for source-module ownership, singleton/vtable/layout anchors, medium for constructor internals because the active generated file summarizes rather than emits the full constructor body.
- Proposed module: `render/HumanImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_HumanImageLib.cpp`
- Main address ranges: `0x004d2720-0x004d4f67` and `0x004e6460-0x004e649b`
- Primary global instance: [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`.
- Primary vtable: [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md).
- Layout anchor: [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## File Role

`HumanImageLib` is the older human body/equipment image library. It initializes ProtectedArray-style tables for body parts and equipment, loads many human sprite frame-table archives through [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md), and tears down the loaded part image-library handles.

This should remain a separate render/image source file. The class is tightly coupled to the old human asset families and is different from [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), which uses `Motion.tbl`, `Layer.tbl`, `Part.tbl`, and part-composition data.

The concrete `ProtectedArray<...Info>` helper files for old-human parts are template instantiations, not separate original modules. Keep their reusable template support under [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), while this file owns the human/equipment table loading and the embedded array fields. IDA confirms the adjacent old-human `ProtectedArray` vtables immediately before the class vtable at `0x0061b6d4`.

## Resource Families

The constructor calls the shared frame-table loader repeatedly for human/equipment archives. Observed merge prefixes from the shared loader include:

```text
HEAD, HEADSP, BODY, SWORD, SPEAR, BOW, FAN, SHIELD, ARROW,
FACE, HAIR, ACE1, ACE2, HELMET, MANTLE, NECLACE, SHOES, COAT
```

The destructor releases 18 body/equipment frame-library handles at object offsets `0x268` through `0x2ac`, then frees embedded `ProtectedArray` buffers for head, body, coat, weapon/equipment, face, accessory, hair, helmet, mantle, necklace, and shoe records. The active generated file describes the same handles as an inner block plus offsets `0x21c-0x260`; the [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md) records the IDA-confirmed object-relative form.

## Lifetime And Singleton

IDA confirms [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`. The constructor writes it at `0x004d277b`, the ordinary destructor clears it at `0x004d4f44`, and the tiny [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) clears it at `0x004e5b80`.

Do not confuse this old-human singleton with the newer table-driven human singleton at `0x0067a760`, which is cleared by `0x004e5be0` and appears in the application shutdown sequence.

## Ownership Decision

The old human library should not be collapsed into `ImageLib.cpp`. It is a consumer of the shared frame-table loader, but it owns human/equipment-specific protected arrays, frame-table handles, and old-human lifetime rules.

## Cross-References

- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:00017A][0x004d2720-0x004e649b.HumanImageLib](by-memory/0x004d2720-0x004e649b.HumanImageLib.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: source ownership, old-human resource families, singleton/vtable/layout anchors, destructor release behavior, and split from `NewHumanImageLib` are documented; confidence remains medium-high because constructor internals are summarized by generated output and protected-array/template boundaries still need deeper review.

- 2026-05-31 projected path and IDA range correction:
  - What existed before: projected reconstruction path was blank and main range text used one-byte-short exclusive ends.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, scores `85/82`, main ranges `0x004d2720-0x004d4f67` and `0x004e6460-0x004e649b`.
  - Summary/evidence: `proposed-source-tree.md` places `HumanImageLib.cpp` under `render/`, and IDA MCP verified the corrected function ends and singleton/vtable xrefs.
