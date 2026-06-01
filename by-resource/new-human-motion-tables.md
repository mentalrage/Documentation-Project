*** UID:0001RI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# New Human Motion Tables

## Status

- Resource kind: DAT-backed/new-human sprite composition tables.
- Owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for `Motion.tbl` owner and vector helper relationship, medium for exact record fields.
- Owner singleton: [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- Evidence basis: IDA MCP UTF-16 string/xref checks and focused decompilation of the NewHumanImageLib constructor/table helpers.

## Role

`Motion.tbl` is part of the newer human sprite composition model owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It should not be confused with the runtime [UID:00008R][Motion](by-class/Motion.md) class/helper output in `class_Motion.cpp`.

Current evidence shows `Motion.tbl` records are fixed-size `0x42` byte entries stored in the [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) vector at object offset `+0x1c`. [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) inserts records while loading the table, and [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) releases the vector during cleanup.

## Related Tables

The same source module also owns:

- `Layer.tbl`
- `Part.tbl`
- per-part `<part-name>.tbl` descriptor files
- `acc2drw.tbl`
- `HAIRCOL.TBL`

These tables feed the new-human render/composition pipeline, not the UI dirty-region Motion helpers.

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
- [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md)
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
