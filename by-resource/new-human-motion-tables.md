*** UID:0001RI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# New Human Motion Tables

## Status

- Resource kind: DAT-backed/new-human sprite composition tables.
- Owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: very strong for table owner, vector helper relationships, load order, current `char.dat` payload provenance, and source/resource boundary; medium for exact record field names.
- Owner singleton: [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- Evidence basis: IDA MCP UTF-16 string/xref checks and focused decompilation of the NewHumanImageLib constructor/table helpers.

## Role

`Motion.tbl` is part of the newer human sprite composition model owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It should not be confused with the runtime [UID:00008R][Motion](by-class/Motion.md) class/helper output in `class_Motion.cpp`.

Current evidence shows `Motion.tbl` loads into fixed-size `0x42` byte `NewHumanMotionEntry` records stored in the [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) vector at object offset `+0x1c`. The file payload itself is not a simple fixed 0x42-byte record stream: [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) reads a 33-byte fixed file prefix and then `frameCount` variable frame payloads into each 0x42-byte in-memory entry. [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) inserts records while loading the table, and [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) releases the vector during cleanup.

## Table Inventory

| Table/resource | Owner vector/path | Rebuild handling | Notes |
| --- | --- | --- | --- |
| `Motion.tbl` | `NewHumanImageLib +0x1c` motion vector | Resource-derived table payload. Source owns the loader, in-memory 0x42-byte entry stride, vector insert path, and cleanup path. | File rows use a 33-byte fixed prefix plus count-driven frame payloads; final original field spellings and the 120-byte frame block semantics remain open. |
| `Layer.tbl` | `NewHumanImageLib +0x10` layer vector | Resource-derived table payload. Keep separate from `Motion.tbl`; [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) now owns first-draft source for the retained 0x20-byte row loader path while the constructor also keeps its inline load loop. | Rows can own child-index arrays at row offset `+0x1c`. |
| `Part.tbl` | `NewHumanImageLib +0x04` part vector | Resource-derived table payload. [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) now owns first-draft source for the retained path-argument loader while the constructor also keeps its inline load loop. | File rows are 0x20-byte / 32-byte records; the layout page's `NewHumanPartEntry` remains a 0x44-byte / 68-byte in-memory row. |
| per-part `<part-name>.DSC` | loaded after `Part.tbl` rows | Resource-derived per-part descriptor payloads. Source owns name/path construction and descriptor vector insertion. | B008 confirmed the loader appends the literal `.DSC` suffix and UID00041C owns the source loader. |
| `<part-name>.EPF` / `<part-name>%d.EPF` | resolved by [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) | Resource-derived sprite frame archives. Source owns path selection and shard lookup; bytes remain DAT/source-asset packaging. | Do not treat as runtime `Motion` class data. |
| `acc2drw.tbl` | `NewHumanImageLib +0x48` vector | Resource-derived accessory-to-draw mapping table loaded by class-owned [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) at `88/90`. | ASCII rows are parsed as decimal flags and mapped into `Acc2DrwEntry.enabled[0..2]` from hundreds/tens/ones digits; row count comes from `m_partEntries[7].descriptorCount`. |
| `HAIRCOL.TBL` | `NewHumanImageLib +0x54` integer vector | Resource-derived hair-color palette-index table. Source owns loader/vector storage and cleanup. | Also xrefs from older human/image code paths. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data`. The core new-human composition tables named in this page are all present in `char.dat`; no loose duplicates were found in the audited tree.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `Motion.tbl` | `char.dat`, entry index `41`, offset `7,384,382`, size `24,109` bytes. | Header begins `MotionStandard`; the little-endian count at header offset `0x17` is `68`, matching the constructor's motion-table vector load. |
| `Layer.tbl` | `char.dat`, entry index `37`, offset `6,856,566`, size `467` bytes. | Header begins `LayerInformation`; count at header offset `0x17` is `13`, matching the separate 32-byte layer-row loader path. |
| `Part.tbl` | `char.dat`, entry index `44`, offset `7,529,802`, size `635` bytes. | Header begins `PartInformation`; count at header offset `0x17` is `19`, with 608 payload bytes after the 23-byte header and count, matching 32-byte file rows that feed 68-byte in-memory part entries. |
| `acc2drw.tbl` | `char.dat`, entry index `0`, offset `922`, size `2,580` bytes. | ASCII/CRLF text table; payload begins with repeated accessory draw flags such as `111`. |
| `HAIRCOL.TBL` | `char.dat`, entry index `30`, offset `3,930,070`, size `400` bytes. | ASCII/CRLF integer table; payload begins with palette-index values such as `0`, `6`, `7`, and `31`. |

## Related Tables

The same source module also owns:

- `Layer.tbl`
- `Part.tbl`
- per-part `<part-name>.DSC` descriptor files
- `acc2drw.tbl`
- `HAIRCOL.TBL`

These tables feed the new-human render/composition pipeline, not the UI dirty-region Motion helpers.

## Source Ownership Notes

[UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) owns the source-side loader orchestration, vector layout, part path resolution, composition bounds, and render dispatch. The table and EPF bytes are resource payloads and should not be reconstructed as hard-coded C++ arrays.

The `Motion.tbl` name collides with [UID:0000LL][Motion](by-file/Motion.md), but this page is specifically about `NewHumanImageLib` table data. Keep runtime UI/render dirty-region motion helpers separate from the new-human composition table model.

## 2026-06-25 Loader Details And Constructor Code Readiness

[UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) now carries the first-draft constructor C++ that orchestrates this table family. The constructor calls [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) for `Motion.tbl`, keeps constructor-inline loops for `Layer.tbl` and `Part.tbl`, calls [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md), calls [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md), then reads `HAIRCOL.TBL` into the integer hair-color vector. The reusable [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) helper now owns first-draft `NewHumanImageLib::LoadLayerTable` C++ for the retained path-argument loader; [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) now owns first-draft `NewHumanImageLib::LoadPartTable` C++ for the retained path-argument loader; and [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) now owns first-draft `NewHumanImageLib::LoadAcc2DrwTable` C++ for the constructor-called `acc2drw.tbl` path-argument loader. Current xrefs still do not show constructor calls to `0x004e1040` or `0x004e11b0`.

The implementation-ready row names are inferred and documented in [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md): `NewHumanMotionEntry` for 66-byte `Motion.tbl` in-memory entries, `NewHumanLayerEntry` for 32-byte `Layer.tbl` records, `NewHumanPartEntry` for 68-byte `Part.tbl` in-memory records fed by 32-byte file rows, `NewHumanPartFrameDescriptor` / `NewHumanSequenceFrameTable` / `NewHumanSequenceFrame` for per-part `.DSC` descriptor payloads, `Acc2DrwEntry` for 3-byte `acc2drw.tbl` rows, and plain integer entries for `HAIRCOL.TBL`. `LoadPartSpriteDescriptors` builds per-part `.DSC` descriptor storage after `Part.tbl`, and [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) resolves the corresponding single or numbered `.EPF` sprite archives.

The helper pages [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md), [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md), and [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) remain support pages where their exact metadata still says no-owner/non-emitting. [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md), [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md), [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md), [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md), [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md), and [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) are now excluded from the old B011 below-gate group by their 2026-06-30 source-quality implementations. Future helper-specific C++ can refine the remaining support pages, but the constructor, motion loader, layer loader, part loader, part descriptor loader, and acc2drw loader no longer depend on unresolved resource/support-page synchronization.

## Rebuild Notes

For source reconstruction, preserve the table load order from the constructor and keep the record vectors in `NewHumanImageLib` layout order: parts, layers, motions, auxiliary/per-part descriptors, accessory mapping, and hair-color entries. Record bytes remain resource-derived until exact field names and table validators are documented.

The current table documentation is strong enough to guide packaging, loader ownership, resource/source split, the accepted constructor first draft, and the [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) first-draft loader body for the NewHuman table family. Final original row field spellings and the internal structure of each 120-byte frame-data block remain open, but that caveat no longer blocks the motion loader source shape.

## Open Questions

- What are the exact original field names and 120-byte per-frame payload semantics inside the `NewHumanMotionEntry` entries? Current source-facing names `motionId`, `name`, `direction`, `fallbackMotionId`, `frameCount`, `frameOffsets`, and `frameData` are implementation-ready inference, not proof of original spelling.
- DAT/archive provenance for per-part descriptor tables and resolved part EPF archives beyond the core table entries documented here.
- Which `HAIRCOL.TBL` fields are shared with old human-image code versus new-human-only render paths?
- Are per-part `<part-name>.DSC` descriptors best documented on this page, a broader new-human resource page, or separate resource pages once their format is decoded?

## IDA MCP Evidence

- `Motion.tbl` is a UTF-16 string at `0x0061c2e4`; xref `0x004dfe4f` lands in the NewHumanImageLib constructor range `0x004dfd10-0x004e024a`.
- The constructor calls the table loader at `0x004e0e20` with `Motion.tbl`. That helper reads a 23-byte table header, a 4-byte count, zeroes a 0x42-byte temporary in-memory entry per row, reads a 33-byte fixed file prefix plus per-frame arrays, and appends each record into the vector at `this + 7` (`+0x1c` bytes).
- `0x004e5240-0x004e5415` is the vector growth helper called from `0x004e0e20`; it computes capacity and copies elements in 66-byte (`0x42`) units.
- `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, and `HAIRCOL.TBL` are UTF-16 strings at `0x0061c2fc`, `0x0061c310`, `0x0061c324`, and `0x0061c010`, all xrefing from the same constructor except `HAIRCOL.TBL`, which also xrefs from `0x004d2720-0x004d4aca`.
- Decompilation shows `Layer.tbl` uses a separate 32-byte vector path and `Part.tbl` uses a 68-byte in-memory vector path fed by 32-byte file rows; do not merge those record layouts into the `Motion.tbl` 0x42-byte layout.
- 2026-06-14 IDA MCP refresh in IDB `a001_goal2_class_batch` confirmed current function bounds for `0x004dfd10` (`sub_4DFD10`, NewHumanImageLib constructor/table orchestration), `0x004e0e20` (`sub_4E0E20`, `Motion.tbl` loader), `0x004e5240` (`sub_4E5240`, motion-vector growth), and `0x004e5dd0` (`sub_4E5DD0`, motion-vector cleanup).
- The refreshed constructor decompilation confirms load order: `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptor/path resolution, `acc2drw.tbl`, and `HAIRCOL.TBL`. `HAIRCOL.TBL` is appended into the integer vector at `NewHumanImageLib +0x54` and remains shared with older human/image code because it also has an old-human xref.
- The refreshed `0x004e0e20` decompilation confirms the `Motion.tbl` loader reads a 23-byte header and row count, zeroes a `0x42`-byte temporary in-memory entry, reads fixed fields plus count-driven child arrays, and appends the row through the `+0x1c` vector. This supports the resource table contract without hard-coding row payload arrays into source.

## 2026-06-30 Motion Loader Field Sync

B002's accepted [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) implementation promotes the motion loader to class-owned/emitting `NewHumanImageLib::LoadMotionTable` at `89/90`. Current MCP session `supervisor_resume_20260629` confirms `sub_4E0E20`, size `0x21f`, sole constructor caller `0x004dfe5a`, the `Motion.tbl` literal xref at `0x004dfe4f` / `0x0061c2e4`, and the `VectorGrowMotion` capacity-helper call at `0x004e0ff2`.

The loader's fixed file prefix maps into the 0x42-byte `NewHumanMotionEntry` at in-memory offsets `+0x17` through `+0x3e`: `motionId`, 20-byte `name`, one-byte `direction`, `fallbackMotionId`, `frameCount`, `frameOffsets`, and `frameData`. The dynamic payload is `frameCount` repetitions of one 2-byte frame offset/value and one 120-byte frame-data block. Direct read-only sampling of `E:\NTK\Resources\NexusTK\Data\char.dat` at `Motion.tbl` offset `7,384,382` confirms header `MotionStandard`, count `68`, rows such as `NormalWalkNorth`, `NormalWalkEast`, `NormalWalkSouth`, and `NormalWalkWest`, direction bytes `0..3`, and `fallbackMotionId=-1` for normal rows. The final `Test` row has fallback value `0`, so `fallbackMotionId` is the current descriptive source-facing name rather than proven original spelling.

## 2026-06-30 Layer Loader Source-Quality Sync

B006's accepted [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) implementation promotes the retained `Layer.tbl` loader to class-owned/emitting `NewHumanImageLib::LoadLayerTable` at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1040`, size `0x170`, zero direct callers, a `wchar_t *` path argument, 23-byte header/count reads, 32-byte `NewHumanLayerEntry` row fields, optional child-index allocation/read loops, and the `VectorGrowLayer` capacity-helper call at `0x004e1171`.

This page keeps the source/resource split explicit: `char.dat` entry `37`, offset `6,856,566`, size `467`, header `LayerInformation`, and count `13` are DAT payload facts; the formal loader source belongs on [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) and emits through [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) into [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). The constructor still has its inline `Layer.tbl` loop; no current xref proves that it calls `0x004e1040`.

## 2026-06-30 Part Loader Source-Quality Sync

B007's accepted [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) implementation promotes the retained `Part.tbl` loader to class-owned/emitting `NewHumanImageLib::LoadPartTable` at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E11B0`, size `0x1f7`, exact body `0x004e11b0-0x004e13a7`, padding to `0x004e13b0`, zero direct callers, a `wchar_t *` path argument, 23-byte header/count reads, 32-byte file-row fields, ANSI-to-wide name conversion, [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) callsite `0x004e12fe`, and [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) capacity-helper relation.

This page keeps the source/resource split explicit: `char.dat` entry `44`, offset `7,529,802`, size `635`, header `PartInformation`, count `19`, and 608 row-payload bytes are DAT payload facts. The formal loader source belongs on [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) and emits through [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) into [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). The constructor still has its inline `Part.tbl` loop; no current xref proves that it calls `0x004e11b0`.

## 2026-06-30 Part Sprite Descriptor Loader Sync

B008's accepted [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) implementation promotes the constructor-called `.DSC` descriptor loader to class-owned/emitting `NewHumanImageLib::LoadPartSpriteDescriptors` at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E13B0`, size `0x446`, exact body `0x004e13b0-0x004e17f6`, constructor-only caller `0x004e017c`, the UTF-16 `.DSC` byte sequence at `0x0061c33c`, and the target data xref at `0x004e1435`.

This page keeps the source/resource split explicit: per-part `<part-name>.DSC` files are resource payloads derived from `Part.tbl` names, while the loader source belongs on UID00041C and emits through [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) into [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). Each `.DSC` file contributes a 23-byte header/count, 0x20-byte descriptor rows, optional primary/secondary unsigned-short frame data, motion-indexed 0x10-byte sequence tables initialized to sentinel values, and compact 9-byte sequence-frame rows.

## 2026-06-30 LoadAcc2DrwTable Source-Quality Sync

B009's accepted [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) implementation promotes the `acc2drw.tbl` loader to class-owned/emitting `NewHumanImageLib::LoadAcc2DrwTable` at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1800`, size `0x1c5`, exact body/padding, constructor-only caller `0x004e0188`, `acc2drw.tbl` literal xref `0x004e0181` / `0x0061c324`, `m_partEntries[7].descriptorCount` row count source, and [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) marker-only full-capacity support at `0x004e195a`.

This page keeps the source/resource split explicit: `char.dat` entry `0`, offset `922`, size `2,580`, ASCII/CRLF rows, and repeated flag rows such as `111` are DAT payload facts. The formal loader source belongs on [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) and emits through [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) into [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). The loader reads one row per `m_partEntries[7].descriptorCount`, maps hundreds/tens/ones digits into `Acc2DrwEntry.enabled[0..2]`, and appends into `m_acc2drwEntries`; B010's UID00041E page remains marker-only vector-growth support.

## Remaining Field Questions

- Exact `Motion.tbl` field names and per-frame data layout inside the 0x42-byte records.
- Relationship between motion ids and layer/part composition records.
- Whether any other helper besides `VectorGrowMotion` performs record validation or remapping.
- Exact original names and semantics for the two 4-byte `Part.tbl` scalar fields after the ANSI part name.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page now documents the NewHuman table inventory, owner singleton/module, constructor load order, vector offsets, record strides, sibling-table separation, source/resource packaging boundary, shared `HAIRCOL.TBL` caveat, current `char.dat` package entries for the core tables, table header names/counts, text-table payload evidence, and exact remaining row-field questions. Completion remains capped because field names, per-frame child-array semantics, per-part descriptor semantics, and resolved part EPF archive mapping are not fully decoded. |
| Confidence | 93 | Confidence is very strong for ownership, loader behavior, and package provenance because current IDA xrefs/decompilation confirm every listed table string and direct DAT parsing confirms the `char.dat` payload entries, counts, and text-table forms. It is capped by unresolved field semantics and per-part asset mapping. |

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
- [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md)
- [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md)
- [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md)
- [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md)
- [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md)
- [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md)
- [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md)
- [UID:0000TO][VectorGrowMotion](by-global/VectorGrowMotion.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md)
- [UID:0000PK][DestroyMotionVector](by-global/DestroyMotionVector.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- 2026-06-30 B008 LoadPartSpriteDescriptors implementation sync:
  - Updated per-part descriptor resource naming from `<part-name>.tbl` to `<part-name>.DSC`, recorded UID00041C as the class-owned source loader, and added descriptor/sequence-table payload shape.
  - Evidence: current MCP confirms UID00041C constructor-only caller, exact range, `.DSC` suffix byte/xref proof, 23-byte header/count reads, descriptor-count allocation, packed descriptor fields, motion-indexed sequence table allocation/initialization, and 9-byte sequence-frame rows.
- 2026-06-30 B009 LoadAcc2DrwTable implementation sync:
  - Updated `acc2drw.tbl` notes to record that [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) now owns first-draft formal source while the resource bytes remain DAT payload evidence.
  - Evidence: current MCP confirms UID00041D body shape, constructor-only caller, `acc2drw.tbl` literal, body/padding boundaries, `m_partEntries[7].descriptorCount` row count source, `Acc2DrwEntry.enabled[0..2]` hundreds/tens/ones mapping, clear/push_back source shape, fatal short-read path, and UID00041E marker-only full-capacity support; package evidence remains `char.dat` entry `0`, offset `922`, size `2,580`, and ASCII/CRLF rows beginning with repeated flags such as `111`.
- 2026-06-30 B007 LoadPartTable implementation sync:
  - Updated `Part.tbl` notes to record that [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) now owns first-draft formal source while the resource bytes remain DAT payload evidence.
  - Evidence: current MCP confirms UID00041B body shape, no-xref caveat, `ResolveSpritePartPath` and `VectorGrowPart` callsites, body/padding boundaries, 23-byte header/count reads, and the file-row versus memory-row correction; package evidence remains `char.dat` entry `44`, offset `7,529,802`, size `635`, header `PartInformation`, count `19`, 608 payload bytes, and 32-byte file rows.
- 2026-06-30 B006 LoadLayerTable implementation sync:
  - Updated `Layer.tbl` notes to record that [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) now owns first-draft formal source while the resource bytes remain DAT payload evidence.
  - Evidence: current MCP confirms UID00041A body shape, no-xref caveat, `VectorGrowLayer` callsite, and boundary nuance; package evidence remains `char.dat` entry `37`, offset `6,856,566`, size `467`, header `LayerInformation`, count `13`, and 32-byte rows.
- 2026-06-25 B011 constructor implementation sync:
  - Score unchanged.
  - Added loader-detail support facts for the accepted [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) C++ and linked exact helper pages [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) through [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md).
  - Evidence: helper pages now document current `Motion.tbl`, `Layer.tbl`, `Part.tbl`, descriptor-table, `acc2drw.tbl`, vector-growth, and excluded-helper facts. UID000419's B011 below-gate status is superseded by the 2026-06-30 B002 loader implementation, UID00041A's B011 below-gate status is superseded by the 2026-06-30 B006 loader implementation, UID00041B's B011 below-gate status is superseded by the 2026-06-30 B007 loader implementation, and UID00041D's B011 below-gate status is superseded by the 2026-06-30 B009 loader implementation; the remaining unpromoted helpers keep their current no-owner status.
- Before: page was scored `0/0` even though the Motion.tbl owner and vector helper relationship could be checked in IDA.
- Changed to: `COMPLETION:72`, `CONFIDENCE:88`, with explicit IDA MCP evidence for table strings, constructor xrefs, record size, vector offset, and sibling table caveats.
- Evidence: IDA MCP string/xref search plus decompilation of `0x004dfd10-0x004e024a`, `0x004e0e20-0x004e103f`, and `0x004e5240-0x004e5415`.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page documented `Motion.tbl` and sibling table evidence, but lacked a rebuild-oriented table inventory and source/resource boundary.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:89`, with table-level rebuild handling, loader/vector ownership notes, and DAT/record-field open questions.
  - Summary/evidence: NewHumanImageLib file/layout docs establish the owner, vector offsets, and load/cleanup relationships; exact row fields and asset package provenance remain open.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:78` / `CONFIDENCE:89` documented the table family but left the current function-bound/load-order evidence implicit.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:91` after refreshed IDA MCP confirmed constructor load order, table string xrefs, `Motion.tbl` 23-byte header/count flow, `0x42` row stride, vector offset `+0x1c`, cleanup support, and `HAIRCOL.TBL` sharing.
  - Remaining below gate: exact row field names, per-frame child-array semantics, and DAT/archive provenance remain open.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:91`, with current IDA loader evidence but no written DAT payload provenance.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:93`, with current `char.dat` entries for `Motion.tbl`, `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, and `HAIRCOL.TBL`, plus header/count evidence for the binary tables and CRLF text-table evidence for accessory/hair-color payloads.
  - Evidence: fixed-table DAT parsing of `char.dat` under `E:\2026\Resources\Read_Only\NexusTK\Data`.
