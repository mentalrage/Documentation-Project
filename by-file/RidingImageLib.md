*** UID:0000N6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RidingImageLib

## Status

- Confidence: strong for class role, resource ownership, singleton/vtable evidence, and observed layout offsets; medium for exact original filename and final nested-field names.
- Proposed module: `render/RidingImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_RidingImageLib.cpp`
- Main address ranges: `0x004dc420-0x004dca14` and `0x004e68b0-0x004e6981`
- Primary global instance: [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`
- Primary vtable: [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md) at `0x0061b6f4`
- Global riding definition table: [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md) at `0x0069b430`

## File Role

`RidingImageLib` is the riding/mount sprite library. It owns the `RIDINGS.DNA` definition parser, the per-riding bucket/group tables, and the `RIDINGS.EPF` frame-table package used for riding sprite rendering.

This should remain a separate render/image module. It depends on shared DAT and EPF frame-table code, but the DNA schema, singleton global, riding definition lifetime, and default bucket seeding are riding-specific.

## Owned Helpers And Shared Dependencies

[UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) is constructor-only. It reads the riding count, allocates the definition array, pre-seeds 21 default bucket groups with a `0..30000` range, then reads each riding definition and its nested bucket entries from `RIDINGS.DNA`.

The constructor calls [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) at `0x004d0f50` for `RIDINGS.EPF`. The current generated source names that callee `OpenResourcePackage`, but IDA MCP identifies the target as the shared EPF frame-table loader.

The bucket/group allocation helpers near `0x005289d0` and `0x00528be0` are shared with the monster image-library table family and should not be made riding-only without a separate helper-class review. The [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) page records the `0x0c` definition rows, 8-byte bucket rows, and 10-byte bucket-entry rows parsed from `RIDINGS.DNA`.

See [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) for the current shared helper-class documentation.

## IDA-Confirmed Supplemental Bodies And Data

| Range | Body/Data | Role |
| --- | --- | --- |
| `0x004dc420-0x004dc68d` | [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) | Constructor-only `RIDINGS.DNA` parser and riding-definition table loader. |
| `0x004dc690-0x004dc722` | [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md) | Singleton constructor; initializes the base/vtable, publishes `g_pRidingImageLib`, loads `RIDINGS.DNA`, and opens `RIDINGS.EPF`. |
| `0x004dc730-0x004dc7d8` | [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) | Frees the `RIDINGS.EPF` package, destroys the riding definition vector, calls `LObject` cleanup, and then clears the singleton. |
| `0x004dc7e0-0x004dca14` | [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper](by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md) | IDA-missed raw draw-frame helper: resolves a riding definition/bucket, loads `RIDINGS.EPF` frame data, adjusts rectangles, and calls sprite/composition slot `dword_69B3F0`. |
| `0x004e5bf0-0x004e5bfb` | [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md) | Clears `g_pRidingImageLib`. |
| `0x004e68b0-0x004e6981` | [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) | Vtable-owned scalar deleting destructor; mirrors the ordinary cleanup, clears `g_pRidingImageLib`, and conditionally deletes `this`. |
| `0x0069b430-0x0069b43c` | [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) | `MonsterImageLibTable_5289D0`-shaped global table seeded by `LoadRidingDefinitions`. |
| `0x0069b444-0x0069b448` | [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md) | Runtime pointer to the riding image-library singleton. |

## Parent-Gate Evidence

This page now clears the strict parent gate for the riding-definition global table and the singleton cleanup helper. The concrete global page [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md) is riding-specific storage, while [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) remains the shared helper implementation owner. The direct riding evidence is the `RIDINGS.DNA` parser child [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md), the exact default table storage [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), the riding singleton [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md), the static-lifetime clear helper [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md), and the `RIDINGS.EPF`/`RIDINGS.DNA` resource pair. Confidence remains capped at 85 rather than higher because final helper type/field names are still provisional.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `RIDINGS.DNA` | Riding definition table: riding id, bucket count/default bucket, animation group, and nested frame bucket entries. |
| `RIDINGS.EPF` | Riding/mount sprite frame archive loaded through the shared EPF frame-table loader. |

## Cross-References

- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
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
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-07 A005 Batch 047 split recheck sync:
  - Kept `85/85` but replaced the pending raw-helper/scalar-destructor rows with exact child links and updated the parser endpoint to `0x004dc68d`.
  - Evidence: A005 live IDA checks confirm the early cluster `0x004dc420-0x004dca14` and the separate scalar deleting destructor `0x004e68b0-0x004e6981`.
  - Assignment effect: supports the refreshed [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) `85/86` parent gate and the new exact child assignments.

- 2026-06-06: Corrected the scalar deleting destructor endpoint to `0x004e6981` and added it to the supplemental body table.
  - Before: the main range ended at `0x004e6980`, which is still inside `sub_4E68B0`.
  - After: the page records the half-open `0x004e68b0-0x004e6981` range and links the renamed RidingImageLib aggregate.
  - Evidence: A002 IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, and `decompile` checks for the scalar deleting destructor and `RidingImageLib` vtable/global references.

- 2026-06-06: Added the IDA-missed raw draw-frame helper at `0x004dc7e0-0x004dca14` to the supplemental body table.
  - Before: the page's main range ended at the constructor/destructor neighborhood and did not account for the executable raw helper between the ordinary destructor and `sub_4DCA20`.
  - After: the main range and supplemental table include the raw helper, while exact child-page promotion remains pending validator registration.
  - Evidence: A002 IDA MCP raw disassembly/call/data-ref pass found the helper's `RIDINGS.EPF` frame lookup, `OffsetRect` calls, `dword_69B3F0` dispatch, stack-cookie epilogue, and padding boundaries.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers role, resource inputs, singleton/global/vtable anchors, IDA-confirmed supplemental bodies, shared helper dependencies, layout/type cross-references, and source placement; confidence remains below strong because final original filename and nested field names are still medium-confidence.

- 2026-05-31: Set the proposed reconstruction path and linked the exact parser child page.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and `LoadRidingDefinitions` was referenced by address only.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, matching `render/RidingImageLib.cpp` in the proposed source tree, and parser references point to [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md).
  - Evidence: `by-project-structure/proposed-source-tree.md` places `RidingImageLib.cpp` under `render/`; IDA MCP confirms `0x004dc420-0x004dc68d` is the constructor-only `RIDINGS.DNA` parser owned by `RidingImageLib`.
- 2026-06-07 A002 Batch 042 parent-gate refresh:
  - Before: `COMPLETION:84` and `CONFIDENCE:80`.
  - After: `COMPLETION:85` and `CONFIDENCE:85`.
  - Evidence: existing exact docs now connect the riding-specific parser, global default table, singleton slot, resource inputs, destructor/singleton-clear evidence, vtable evidence, and shared-helper exclusion strongly enough for the strict parent gate. Scores remain deliberately capped because the raw draw-frame helper child is still pending new-file registration and final field/helper names are unresolved.
- 2026-06-08 A003 Batch122: Added explicit parent-gate support for [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md).
  - Before: the file listed the clear helper but did not state that the helper now clears the corrected `85/85` gate against this source root.
  - After: parent-gate evidence records the helper as direct by-file static-lifetime cleanup glue alongside the singleton global and destructor lifecycle.
  - Evidence: Batch122 IDA recheck on `0x004e5bf0` and `0x0069b444` reconfirmed the exact body, constructor cleanup jump, singleton lifecycle xrefs, and neighboring helper boundary.
