*** UID:000092 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewHumanImageLib

## Status

- Confidence: strong for method families, medium for final field/type names.
- Likely source file: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Autogen parent: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). Class declaration/source ownership is confirmed, but final C++ remains blank until field and helper names reach final-source quality.
- Address ranges: [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_NewHumanImageLib.cpp`
- Singleton: [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) at `0x0067a760`
- Vtable: [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md) at `0x0061b76c`
- Layout: [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)

## Class Purpose

`NewHumanImageLib` is the singleton-backed updated human composition/rendering library behind [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md). It loads a table-driven model of motions, layers, parts, part descriptors, accessory draw mappings, and hair colors, then builds and renders composed human sprite commands.

## Observed State

The constructor initializes several vector triplets and a small list/sentinel state:

```text
0x04  part entries begin/end/cap
0x10  layer entries begin/end/cap
0x1c  motion entries begin/end/cap
0x28  auxiliary entries begin/end/cap
0x34  pending/list state
0x48  acc2drw entries begin/end/cap
0x54  hair color entries begin/end/cap
```

Field names are generated/reconstructed and should be refined during a layout pass.

## Method Families

| Method | Address | Role |
| --- | --- | --- |
| `NewHumanImageLib::NewHumanImageLib` | [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) | Initializes vectors/list state and loads `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptors, `acc2drw.tbl`, and `HAIRCOL.TBL`. |
| `~NewHumanImageLib` | `0x004e0250` | [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) that releases part resources, descriptors, motion entries, hair colors, vectors, and singleton state. |
| `Draw` / `RenderHuman` | `0x004e06a0`, `0x004e0900` | High-level draw entry points that select/render a human composition. |
| `CalculateBounds` / `ComputeOverlayBounds` | `0x004e09e0`, `0x004e0b90` | Bounds calculation for base and overlay draw paths. |
| `LoadMotionTable` | `0x004e0e20` | Parses motion entries and frame data. |
| `LoadPartSpriteDescriptors` | `0x004e13b0` | Loads per-part `.tbl` descriptor data. |
| `LoadAcc2DrwTable` | `0x004e1800` | Parses `acc2drw.tbl` into packed accessory draw mappings. |
| `BuildCompositionDrawCommands` | `0x004e21d0` | Builds draw commands for a composed human sprite. |
| `BuildPartDrawCommand` | `0x004e2eb0` | Builds one part draw command. |
| `RenderPreparedComposition` | `0x004e2fe0` | Renders a prepared composition command list. |
| [UID:0002V8][0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md) | `0x004e31f0` | Computes full composition bounds, including overlay-resource rectangle lookup through [UID:0002KT][0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect.md). |
| `RenderComposition` | `0x004e4280` | Full composition render path. |
| [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md) insert helper | `0x004e57c0` | Vector insert support called from `RenderComposition`; not a NewHumanImageLib method but source-adjacent support. |
| [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) | `0x004e5240` | Source-adjacent `Motion.tbl` vector growth helper called only from `LoadMotionTable`. |
| [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) | `0x004e5dd0` | Source-adjacent `Motion.tbl` vector cleanup helper called from the destructor. |
| `ScalarDeletingDestructor` | `0x004e6870` | Destructor thunk with optional delete; first [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md) slot. |

Singleton/static-lifetime support:

| Function | Address | Role |
| --- | --- | --- |
| `NewHumanImageLibSingletonClearHelper` | `0x004e5be0` | [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md) that clears `g_pNewHumanImageLib` / `dword_67A760`. |

Disabled/excluded but still owner-relevant:

| Method | Address | Role |
| --- | --- | --- |
| `LoadPartFrameDrawRecord` | `0x004e0d70` | Loads one part-specific frame draw record through the shared frame-record helper at `0x004d1600`. |
| `GetHeadCount` | `0x004e0dd0` | Tiny count accessor used by UI/look code. |

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:0002V8][0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md)
- [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite substantial singleton, layout, method-family, and resource-table documentation.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: the page records constructor/destructor ownership, render/bounds/load families, singleton and vtable references, vector helpers, and observed field offsets; confidence remains medium because final field/type names and exact layout semantics still need a dedicated pass.
- Before: the class page did not mark the confirmed source-owned class as reconstructable and referenced the constructor only by start address.
- Changed to: `RECONSTRUCTABLE:TRUE`, `COMPLETION:82`, `CONFIDENCE:82`, and the exact constructor page/range link.
- Evidence: IDA MCP `lookup_funcs 0x004dfd10` reports `0x004dfd10-0x004e024a`, with constructor resource loads and object-layout writes documented in [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md). Scores remain below 95 because final field/type names and full method-by-method reconstruction are still incomplete.
- Before: `AUTOGEN_PARENT_UID` was blank even though both the class page and file page had 80+ confidence and agreed on ownership.
- Changed to: `AUTOGEN_PARENT_UID:0000LR`.
- Evidence: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) owns `NexusTK/render/NewHumanImageLib.cpp`, and this class page records the matching singleton, vtable, layout, method family, and resource-table evidence. The reconstruction C++ block stays blank because final field names and member declarations remain below the 95+ final-source threshold.
- Before: `CalculateCompositionBounds` was listed only by address.
- Changed to: the method-family table links [UID:0002V8][0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md).
- Evidence: IDA MCP on 2026-06-03 confirmed the method boundary, callers, callees, and two overlay-resource rectangle calls to [UID:0002KT][0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e5.ResourceLayoutRawRecordGetEntryRect.md).
