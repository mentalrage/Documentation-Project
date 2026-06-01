*** UID:0000BZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RidingImageLib

## Status

- Confidence: strong for method roles, singleton/vtable evidence, and observed layout offsets; medium for final nested-field names.
- Likely source file: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- Address ranges: [UID:00017F][0x004dc420-0x004e6980.RidingImageLib](by-memory/0x004dc420-0x004e6980.RidingImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_RidingImageLib.cpp`
- Singleton: [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`
- Vtable: [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md) at `0x0061b6f4`

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
| `LoadRidingDefinitions` | [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md) | Reads `RIDINGS.DNA`, allocates definition/bucket arrays, and fills nested riding bucket entries. |
| `RidingImageLib::RidingImageLib` | `0x004dc690` | Sets `g_pRidingImageLib`, initializes the base/vtable, calls `LoadRidingDefinitions`, and loads `RIDINGS.EPF`. |
| `RidingImageLib::~RidingImageLib` | `0x004dc730` | Ordinary non-deleting destructor; frees `RIDINGS.EPF`, destroys riding definitions, calls `LObject` cleanup, and clears the singleton. |
| `ClearRidingImageLibSingleton` | `0x004e5bf0` | Tiny helper that clears `g_pRidingImageLib`; no direct callers currently modeled. |
| `DeletingDestructor` | `0x004e68b0` | Frees the `RIDINGS.EPF` package payload/handle, destroys the definition array, clears the singleton, and optionally deletes `this`. |

IDA MCP on 2026-05-22 confirms `LoadRidingDefinitions` has only the constructor as an executable caller, and the constructor has one startup caller at `0x004f60ed`. IDA MCP on 2026-05-26 confirms the vtable at `0x0061b6f4`, singleton storage at `0x0069b444`, the ordinary destructor at `0x004dc730`, and the singleton clear helper at `0x004e5bf0`.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004e6980.RidingImageLib](by-memory/0x004dc420-0x004e6980.RidingImageLib.md)
- [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/80`.
  - Before: The page was unevaluated despite documenting singleton/vtable evidence, layout offsets, RIDINGS.DNA/EPF ownership, method roles, and destructor behavior.
  - After: Scored as high completion and medium-high confidence because method roles and lifetime are strong, while final nested-field names remain less certain.
  - Evidence: Existing state layout, method notes, IDA MCP constructor/vtable/singleton notes, and layout/global/memory cross-references support the score.

- 2026-05-31: Marked the class reconstructable and linked the exact `LoadRidingDefinitions` child memory page.
  - Before: `RECONSTRUCTABLE` was blank, and the parser was referenced only by its start address.
  - After: `RECONSTRUCTABLE:TRUE`, with the method table and cross-references pointing to the exact parser page.
  - Evidence: IDA MCP confirms the parser is source-authored `RidingImageLib` code, constructor-only at call site `0x004dc6f5`, and owns `RIDINGS.DNA` definition loading for this class.
