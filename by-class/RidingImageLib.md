*** UID:0000BZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RidingImageLib

## Status

- Confidence: strong for method roles, singleton/vtable evidence, and observed layout offsets; medium for final nested-field names.
- Likely source file: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- Address ranges: [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md) plus [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_RidingImageLib.cpp`
- Singleton: [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`
- Vtable: [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md) at `0x0061b6f4`
- Parent/C++ status: reconstructable and attached to the owning [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) source root. Keep final class C++ blank until nested field names, helper names, and the raw draw-frame helper split are final-source quality.

## Class Purpose

`RidingImageLib` is the singleton-backed riding/mount image library behind `g_pRidingImageLib`. It loads the mount animation/definition data from `RIDINGS.DNA`, loads the `RIDINGS.EPF` image frame table, and owns the lifetime of both resources.

## Observed State

```text
0x00  LObject/vtable base
0x04  RidingDefinition* riding definitions
0x08  uint32 riding definition count
0x0c  RIDINGS.EPF frame-table/package handle
```

`RidingDefinition` contains a riding id, bucket count, default bucket index, animation group id, and nested frame buckets. Each bucket entry stores frame range/stride plus direction, palette, and effect fields. See [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md) and [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) for current offsets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LoadRidingDefinitions` | [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) | Reads `RIDINGS.DNA`, allocates definition/bucket arrays, and fills nested riding bucket entries. |
| `RidingImageLib::RidingImageLib` | [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md) | Sets `g_pRidingImageLib`, initializes the base/vtable, calls `LoadRidingDefinitions`, and loads `RIDINGS.EPF`. |
| `RidingImageLib::~RidingImageLib` | `0x004dc730` | Ordinary non-deleting destructor; frees `RIDINGS.EPF`, destroys riding definitions, calls `LObject` cleanup, and clears the singleton. |
| `RidingImageLibDrawRidingFrameRawHelper` | [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper](by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md) | IDA-missed raw draw-frame helper that resolves the riding definition/bucket, loads `RIDINGS.EPF` frame data, offsets render rectangles, and dispatches through sprite/composition slot `dword_69B3F0`. |
| `ClearRidingImageLibSingleton` | `0x004e5bf0` | Tiny helper that clears `g_pRidingImageLib`; no direct callers currently modeled. |
| `DeletingDestructor` | [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) | Vtable-owned scalar deleting destructor; frees the `RIDINGS.EPF` package payload/handle, destroys the definition array, clears the singleton, and optionally deletes `this`. |

IDA MCP on 2026-05-22 confirms `LoadRidingDefinitions` has only the constructor as an executable caller, and the constructor has one startup caller at `0x004f60ed`. IDA MCP on 2026-05-26 confirms the vtable at `0x0061b6f4`, singleton storage at `0x0069b444`, the ordinary destructor at `0x004dc730`, and the singleton clear helper at `0x004e5bf0`.

IDA MCP on 2026-06-06 confirms the raw draw-frame helper has no IDA function object or direct xrefs, but the exact body is bounded by `0xcc` padding at `0x004dc7d8-0x004dc7e0` and `0x004dca14-0x004dca20`. Its calls to the bucket-entry helper `0x00528b10`, `RIDINGS.EPF` frame lookup `0x004d02f0`, `OffsetRect` `0x004b7e10`, and `dword_69B3F0` bind it to this class's rendering path.

IDA MCP on 2026-06-06 also confirms the scalar deleting destructor is `0x004e68b0-0x004e6981` half-open: `lookup_funcs` reports size `0xd1`, `0x004e6980` still resolves inside `sub_4E68B0`, and `0x004e6981` falls outside the function before the next modeled function at `0x004e6990`.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
- [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md)
- [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md)
- [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper](by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md)
- [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-07 A005 Batch 047 parent-gate refresh:
  - Before: `83/82`, with the raw draw helper still pending exact child registration and the main memory reference overbroad.
  - After: `85/86`; the parser endpoint is corrected, constructor/raw-helper/scalar-destructor exact child pages are linked, and the old broad memory page was narrowed to [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md).
  - Evidence: A005 live IDA boundary checks plus existing singleton/vtable/layout/resource docs now cover the class method inventory enough for the corrected parent gate.
  - Assignment effect: direct parent now satisfies `85/85` for [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md), [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md), [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md), [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper](by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md), and [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md).

- 2026-06-06 A008:
  - Before: the class met the 80/80 parent gate but remained unassigned, leaving child items such as [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) and [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md) with an unknown autogen parent chain.
  - After: changed completion/confidence to `83/82`, set `AUTOGEN_PARENT_UID` to [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), and documented that final class C++ remains blank pending a final naming/layout pass.
  - Evidence: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) already has a valid `NexusTK/render/` source root and `84/80` scores, while this class page records the singleton, vtable, layout offsets, parser, ordinary destructor, raw draw-frame helper, singleton-clear helper, and scalar deleting destructor evidence.

- 2026-06-06: Corrected the scalar deleting destructor range to `0x004e68b0-0x004e6981`.
  - Before: the class inventory only listed the destructor start and linked to the aggregate under the stale `0x004e6980` endpoint.
  - After: the method table records the exact half-open scalar deleting destructor range and references the renamed aggregate.
  - Evidence: A002 IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, and `decompile` checks for `sub_4E68B0`, vtable slot `0x0061b6f4`, and singleton clear `0x0069b444`.

- 2026-06-06: Added the raw draw-frame helper `0x004dc7e0-0x004dca14` to the method inventory.
  - Before: the class documented loading/lifetime helpers but omitted the executable raw body between the ordinary destructor and `sub_4DCA20`.
  - After: the method table records the raw helper and its current evidence-bound role while keeping child-page/validator registration as follow-up work.
  - Evidence: A002 IDA MCP raw disassembly, `lookup_funcs`, data-ref/call audit, and raw address-byte scan.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/80`.
  - Before: The page was unevaluated despite documenting singleton/vtable evidence, layout offsets, RIDINGS.DNA/EPF ownership, method roles, and destructor behavior.
  - After: Scored as high completion and medium-high confidence because method roles and lifetime are strong, while final nested-field names remain less certain.
  - Evidence: Existing state layout, method notes, IDA MCP constructor/vtable/singleton notes, and layout/global/memory cross-references support the score.

- 2026-05-31: Marked the class reconstructable and linked the exact `LoadRidingDefinitions` child memory page.
  - Before: `RECONSTRUCTABLE` was blank, and the parser was referenced only by its start address.
  - After: `RECONSTRUCTABLE:TRUE`, with the method table and cross-references pointing to the exact parser page.
  - Evidence: IDA MCP confirms the parser is source-authored `RidingImageLib` code, constructor-only at call site `0x004dc6f5`, and owns `RIDINGS.DNA` definition loading for this class.
