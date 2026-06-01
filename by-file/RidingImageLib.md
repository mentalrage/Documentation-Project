*** UID:0000N6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RidingImageLib

## Status

- Confidence: strong for class role, resource ownership, singleton/vtable evidence, and observed layout offsets; medium for exact original filename and final nested-field names.
- Proposed module: `render/RidingImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_RidingImageLib.cpp`
- Main address ranges: `0x004dc420-0x004dc721` and `0x004e68b0-0x004e6980`
- Primary global instance: [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`
- Primary vtable: [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md) at `0x0061b6f4`
- Global riding definition table: [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md) at `0x0069b430`

## File Role

`RidingImageLib` is the riding/mount sprite library. It owns the `RIDINGS.DNA` definition parser, the per-riding bucket/group tables, and the `RIDINGS.EPF` frame-table package used for riding sprite rendering.

This should remain a separate render/image module. It depends on shared DAT and EPF frame-table code, but the DNA schema, singleton global, riding definition lifetime, and default bucket seeding are riding-specific.

## Owned Helpers And Shared Dependencies

[UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md) is constructor-only. It reads the riding count, allocates the definition array, pre-seeds 21 default bucket groups with a `0..30000` range, then reads each riding definition and its nested bucket entries from `RIDINGS.DNA`.

The constructor calls [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) at `0x004d0f50` for `RIDINGS.EPF`. The current generated source names that callee `OpenResourcePackage`, but IDA MCP identifies the target as the shared EPF frame-table loader.

The bucket/group allocation helpers near `0x005289d0` and `0x00528be0` are shared with the monster image-library table family and should not be made riding-only without a separate helper-class review. The [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) page records the `0x0c` definition rows, 8-byte bucket rows, and 10-byte bucket-entry rows parsed from `RIDINGS.DNA`.

See [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) for the current shared helper-class documentation.

## IDA-Confirmed Supplemental Bodies And Data

| Range | Body/Data | Role |
| --- | --- | --- |
| `0x004dc420-0x004dc68c` | [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md) | Constructor-only `RIDINGS.DNA` parser and riding-definition table loader. |
| `0x004dc730-0x004dc7d8` | [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) | Frees the `RIDINGS.EPF` package, destroys the riding definition vector, clears the singleton, and tail-calls `LObject` cleanup. |
| `0x004e5bf0-0x004e5bfb` | [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md) | Clears `g_pRidingImageLib`. |
| `0x0069b430-0x0069b43c` | [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) | `MonsterImageLibTable_5289D0`-shaped global table seeded by `LoadRidingDefinitions`. |
| `0x0069b444-0x0069b448` | [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md) | Runtime pointer to the riding image-library singleton. |

## Resource Inputs

| Resource | Role |
| --- | --- |
| `RIDINGS.DNA` | Riding definition table: riding id, bucket count/default bucket, animation group, and nested frame bucket entries. |
| `RIDINGS.EPF` | Riding/mount sprite frame archive loaded through the shared EPF frame-table loader. |

## Cross-References

- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004e6980.RidingImageLib](by-memory/0x004dc420-0x004e6980.RidingImageLib.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers role, resource inputs, singleton/global/vtable anchors, IDA-confirmed supplemental bodies, shared helper dependencies, layout/type cross-references, and source placement; confidence remains below strong because final original filename and nested field names are still medium-confidence.

- 2026-05-31: Set the proposed reconstruction path and linked the exact parser child page.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and `LoadRidingDefinitions` was referenced by address only.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, matching `render/RidingImageLib.cpp` in the proposed source tree, and parser references point to [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md).
  - Evidence: `by-project-structure/proposed-source-tree.md` places `RidingImageLib.cpp` under `render/`; IDA MCP confirms `0x004dc420-0x004dc68c` is the constructor-only `RIDINGS.DNA` parser owned by `RidingImageLib`.
