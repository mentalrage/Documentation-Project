*** UID:0001RI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# New Human Motion Tables

## Status

- Resource kind: DAT-backed/new-human sprite composition tables.
- Owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for table owner, vector helper relationships, and source/resource boundary; medium for exact record fields.
- Owner singleton: [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- Evidence basis: IDA MCP UTF-16 string/xref checks and focused decompilation of the NewHumanImageLib constructor/table helpers.

## Role

`Motion.tbl` is part of the newer human sprite composition model owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It should not be confused with the runtime [UID:00008R][Motion](by-class/Motion.md) class/helper output in `class_Motion.cpp`.

Current evidence shows `Motion.tbl` records are fixed-size `0x42` byte entries stored in the [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) vector at object offset `+0x1c`. [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) inserts records while loading the table, and [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) releases the vector during cleanup.

## Table Inventory

| Table/resource | Owner vector/path | Rebuild handling | Notes |
| --- | --- | --- | --- |
| `Motion.tbl` | `NewHumanImageLib +0x1c` motion vector | Resource-derived table payload. Source owns the loader, fixed record stride, vector insert path, and cleanup path. | Rows are currently known as 0x42-byte records; final field names remain open. |
| `Layer.tbl` | `NewHumanImageLib +0x10` layer vector | Resource-derived table payload. Keep separate from `Motion.tbl`; source owns the 0x20-byte row loader path. | Rows can own child-index arrays at row offset `+0x1c`. |
| `Part.tbl` | `NewHumanImageLib +0x04` part vector | Resource-derived table payload. Source owns ANSI-to-wide part-name conversion and descriptor-table dispatch. | Rows are 0x44-byte records in the layout page. |
| per-part `<part-name>.tbl` | loaded after `Part.tbl` rows | Resource-derived per-part descriptor payloads. Source owns name/path construction and descriptor vector insertion. | Descriptor details remain in NewHumanImageLib owner docs. |
| `<part-name>.EPF` / `<part-name>%d.EPF` | resolved by [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) | Resource-derived sprite frame archives. Source owns path selection and shard lookup; bytes remain DAT/source-asset packaging. | Do not treat as runtime `Motion` class data. |
| `acc2drw.tbl` | `NewHumanImageLib +0x48` vector | Resource-derived accessory-to-draw mapping table. Source owns the loader/vector storage path. | Exact entry fields are still not fully named here. |
| `HAIRCOL.TBL` | `NewHumanImageLib +0x54` integer vector | Resource-derived hair-color palette-index table. Source owns loader/vector storage and cleanup. | Also xrefs from older human/image code paths. |

## Related Tables

The same source module also owns:

- `Layer.tbl`
- `Part.tbl`
- per-part `<part-name>.tbl` descriptor files
- `acc2drw.tbl`
- `HAIRCOL.TBL`

These tables feed the new-human render/composition pipeline, not the UI dirty-region Motion helpers.

## Source Ownership Notes

[UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) owns the source-side loader orchestration, vector layout, part path resolution, composition bounds, and render dispatch. The table and EPF bytes are resource payloads and should not be reconstructed as hard-coded C++ arrays.

The `Motion.tbl` name collides with [UID:0000LL][Motion](by-file/Motion.md), but this page is specifically about `NewHumanImageLib` table data. Keep runtime UI/render dirty-region motion helpers separate from the new-human composition table model.

## Rebuild Notes

For source reconstruction, preserve the table load order from the constructor and keep the record vectors in `NewHumanImageLib` layout order: parts, layers, motions, auxiliary/per-part descriptors, accessory mapping, and hair-color entries. Record bytes remain resource-derived until exact field names and table validators are documented.

The current table documentation is strong enough to guide packaging and loader ownership, but not enough to emit final struct definitions for all rows. Final row names should wait for a field-by-field reconciliation of the table loader helpers, destructor cleanup, and render/composition consumers.

## Open Questions

- What are the exact field names and semantics inside the 0x42-byte `Motion.tbl` rows?
- Which DAT/archive contains `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptor tables, `acc2drw.tbl`, `HAIRCOL.TBL`, and the resolved part EPF archives?
- Which `HAIRCOL.TBL` fields are shared with old human-image code versus new-human-only render paths?
- Are per-part `<part-name>.tbl` descriptors best documented on this page, a broader new-human resource page, or separate resource pages once their format is decoded?

## IDA MCP Evidence

- `Motion.tbl` is a UTF-16 string at `0x0061c2e4`; xref `0x004dfe4f` lands in the NewHumanImageLib constructor range `0x004dfd10-0x004e024a`.
- The constructor calls the table loader at `0x004e0e20` with `Motion.tbl`. That helper reads a 23-byte table header, a 4-byte count, zeroes a 0x42-byte temporary record per row, reads fixed fields plus per-frame arrays, and appends each record into the vector at `this + 7` (`+0x1c` bytes).
- `0x004e5240-0x004e5415` is the vector growth helper called from `0x004e0e20`; it computes capacity and copies elements in 66-byte (`0x42`) units.
- `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, and `HAIRCOL.TBL` are UTF-16 strings at `0x0061c2fc`, `0x0061c310`, `0x0061c324`, and `0x0061c010`, all xrefing from the same constructor except `HAIRCOL.TBL`, which also xrefs from `0x004d2720-0x004d4aca`.
- Decompilation shows `Layer.tbl` uses a separate 32-byte vector path and `Part.tbl` uses a 68-byte vector path; do not merge those record layouts into the `Motion.tbl` 0x42-byte layout.

## Open Questions

- Exact `Motion.tbl` field names and per-frame data layout inside the 0x42-byte records.
- Relationship between motion ids and layer/part composition records.
- Whether any other helper besides `VectorGrowMotion` performs record validation or remapping.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:00017R][0x004dfd10-0x004e68a8.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a8.NewHumanImageLib.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0000TO][VectorGrowMotion](by-global/VectorGrowMotion.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0000PK][DestroyMotionVector](by-global/DestroyMotionVector.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- Before: page was scored `0/0` even though the Motion.tbl owner and vector helper relationship could be checked in IDA.
- Changed to: `COMPLETION:72`, `CONFIDENCE:88`, with explicit IDA MCP evidence for table strings, constructor xrefs, record size, vector offset, and sibling table caveats.
- Evidence: IDA MCP string/xref search plus decompilation of `0x004dfd10-0x004e024a`, `0x004e0e20-0x004e103f`, and `0x004e5240-0x004e5415`.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page documented `Motion.tbl` and sibling table evidence, but lacked a rebuild-oriented table inventory and source/resource boundary.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:89`, with table-level rebuild handling, loader/vector ownership notes, and DAT/record-field open questions.
  - Summary/evidence: NewHumanImageLib file/layout docs establish the owner, vector offsets, and load/cleanup relationships; exact row fields and asset package provenance remain open.
