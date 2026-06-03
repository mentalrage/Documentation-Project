*** UID:0000LR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewHumanImageLib

## Status

- Confidence: strong for file ownership and resource families, medium for final field/type names.
- Proposed module: `render/NewHumanImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_NewHumanImageLib.cpp`
- Main address ranges: `0x004dfd10-0x004e4d78` and `0x004e6870-0x004e68a7`
- Primary global instance: [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) at `0x0067a760`
- Primary vtable: [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md) at `0x0061b76c`
- Object layout: [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)

## File Role

`NewHumanImageLib` is the updated human sprite composition library. It owns the newer table-driven character composition system: motion records, layer records, part records, per-part sprite descriptors, accessory-to-draw mapping, hair-color indices, composition draw commands, bounds calculation, and render dispatch.

This is a separate source module from [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Both are human character image libraries, but `NewHumanImageLib` has its own data model around `Motion.tbl`, `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, and part-specific descriptor tables.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `Motion.tbl` | Motion entries and per-frame data used by composition/render methods. |
| `Layer.tbl` | Layer definitions and child layer lists. |
| `Part.tbl` | Part ids/names plus descriptor counts; names are converted from ANSI to wide strings. |
| `<part-name>.tbl` | Per-part sprite descriptor tables loaded by `LoadPartSpriteDescriptors`. |
| `<part-name>.EPF` / `<part-name>%d.EPF` | Sprite part frame archives resolved by [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md). |
| `acc2drw.tbl` | Accessory-to-draw mapping table. |
| `HAIRCOL.TBL` | Hair color palette-index table. |

## Owned And Nearby Helpers

[UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) is a free helper, but it is tightly coupled to this module: it is called by the constructor and by an ANSI/wide wrapper path to resolve either numbered `<part>%d.EPF` archive shards or a single `<part>.EPF`.

`Motion.tbl` vector helpers [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) and [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) belong to this module. They are not methods on the runtime [UID:00008R][Motion](by-class/Motion.md) class despite the name overlap.

[UID:0002V8][0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md) belongs to this module. It computes composition bounds, calls the shared ResourceLayout raw rectangle helper [UID:0002KT][0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect.md) for overlay-resource rectangles, and is reached by the base/overlay bounds wrappers at `0x004e0b6e` and `0x004e0d01`.

The tiny [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md) also belongs here. It clears `dword_67A760`, not the old [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) singleton.

The disabled/excluded methods `LoadPartFrameDrawRecord` at `0x004e0d70` and `GetHeadCount` at `0x004e0dd0` are still real `NewHumanImageLib` owner evidence and should be kept with this module when reviewing file layout. They are disabled from active emission, not evidence for another class.

[UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md) is a compiler/vector insert helper called only from `RenderComposition` at `0x004e4c14`. Keep the composition record behavior here while treating the helper body as [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) support.

## Ownership Decision

Keep `NewHumanImageLib` as its own render/image source file. It is too large and data-model-specific to merge into `ImageLib.cpp`, and its helper/resource set differs enough from the old [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) that the original code likely used separate files or at least separate class sections.

## Cross-References

- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
- [UID:0002V8][0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md)
- [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000TO][VectorGrowMotion](by-global/VectorGrowMotion.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0000PK][DestroyMotionVector](by-global/DestroyMotionVector.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents resource families, owned and nearby helpers, singleton/vtable/layout anchors, split from old `HumanImageLib`, and vector/helper ownership; confidence remains capped by final field/type naming and disabled helper review.
- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though this page and the proposed tree both place the file under `render/NewHumanImageLib.cpp`.
- Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"` and added the exact constructor page link.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` lists `render/NewHumanImageLib.cpp`, and IDA MCP rechecked the constructor at `0x004dfd10-0x004e024a`.
- Before: the file page did not link the exact composition-bounds child page.
- Changed to: added [UID:0002V8][0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md) to owned helpers/cross-references.
- Summary/evidence: IDA MCP on 2026-06-03 confirmed the `0x004e31f0-0x004e3a2e` boundary, callers, callees, and two overlay-resource rectangle lookups through [UID:0002KT][0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect.md).
