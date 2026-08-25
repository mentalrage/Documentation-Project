*** UID:0000V0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// LoadTileEpfMetadata is emitted by the exact function page [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md).
// This by-item page is an alias/index for 0x004d1b80 and must not duplicate
// the helper body in MapTileImageLib.cpp.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LoadTileEpfMetadata 0x004d1b80

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Owner/emitter route: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Memory range: [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md)
- B011's 2026-07-01 accepted callback keeps this page as an alias/index only. The exact helper body is emitted by [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md), so this page must not duplicate the formal C++ body.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page documents exact range/endpoints, padding, one-caller MapTileImageLib constructor context, shard probe loop, DATFile lifecycle, 12-byte header and 24-byte record allocation, record rebasing, sentinel write, cleanup, owner/emitter route, and accepted alias/no-duplicate formal comment. |
| Confidence | 90 | Live IDA lookup/analyze/xref/decompile evidence agrees with exact memory page [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md), [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md), and the MapTileImageLib file parent. Confidence remains below final-source level because helper signature, table type names, and field names are still provisional. |

## Function Role

`LoadTileEpfMetadata` scans numbered `TILE%d.EPF` archives, opens each present archive through `DATFile`, reads the shared EPF archive metadata header and record table, and merges all records into one `ArchiveMetadataTable` with a terminal sentinel.

Live IDA xrefs show one caller: `MapTileImageLib::MapTileImageLib`.

IDA decompilation shows the helper probes up to 100 numbered archive shards by formatting `TILE%d.EPF` and checking [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md). It then allocates the merged metadata header, opens each present archive through `DATFile`, converts raw EPF record bounds into the shared packed in-memory table, and releases temporary per-archive `DATFile` objects.

IDA MCP recheck on 2026-06-04 confirms `sub_4D1B80` starts at `0x004d1b80`, ends half-open at `0x004d1f22`, has one direct caller at `0x004d18d1` inside `sub_4D1860`, and calls [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), DATFile helpers, allocation/free helpers, and rectangle/table helpers.

B015's 2026-06-19 raw PE/source-quality pass reconfirms this helper as the final child inside [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md): range `0x004d1b80-0x004d1f22`, size `0x3a2` / 930 decimal (Verified with int_convert.py), one constructor caller at `0x004d18d1`, fourteen bytes of padding at `0x004d1f22-0x004d1f30`, and a hard successor owner boundary at [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md). This supports keeping the helper in `MapTileImageLib.cpp` instead of moving it to shared [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` reports IDA `sub_4D1B80` at `0x004d1b80`, size `0x3a2`; `0x004d1f22` is not a function, and the next function is `sub_4D1F30` at `0x004d1f30`.
- IDA Python inspection reports fourteen `0xcc` padding bytes from `0x004d1f22` through `0x004d1f2f`, confirming the half-open range.
- The live decompile reports `_DWORD *__stdcall sub_4D1B80(int a1)` and shows a probe loop for up to 100 formatted `TILE%d.EPF` paths using `sub_41B9B0` and `HasDATEntry`.
- The helper allocates per-shard header storage, allocates and constructs temporary `DATFile` objects, opens each numbered shard through the DAT vtable open slot, and reads header/record data through DAT vtable read/seek slots.
- The merged output is a 12-byte table header plus `24 * (recordCount + 1)` record storage. The body copies rectangle bounds through `sub_4B7C50`, rebases record offsets using `DATFile::GetDataPointer` (`sub_49C550`), appends a zero-rectangle terminal sentinel, closes temporary DAT files, frees temporary arrays, destructs the stack `DATFile`, and returns the merged table.
- The only direct caller is `0x004d18d1` in `sub_4D1860`, immediately after the `MapTileImageLib` vtable store and before the constructor opens `TILE.TBL`, which supports [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) ownership.
- Reconstruction C++ no longer remains blank as an unresolved blocker. B011's 2026-07-01 callback inserts a formal alias/no-duplicate comment here and emits the actual helper body from [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md).

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` resolves `0x004d1b80` to `sub_4D1B80`, size `0x3a2`; `0x004d1f22` is not a function, and the next modeled function remains `0x004d1f30`. Decimal size `930 == 0x3a2` was verified with `int_convert.py`.
- `analyze_function 0x004d1b80` reports one caller, 14 callees, and complexity 18; `xrefs_to 0x004d1b80` reports the sole direct code ref at `0x004d18d1` inside `sub_4D1860`.
- Targeted decompilation reconfirmed the `TILE%d.EPF` scan capped at `100 == 0x64`, 20-byte formatting buffer (`20 == 0x14`), DAT-entry probe through `0x0049c700`, 12-byte merged header allocation (`12 == 0x0c`), and `24 * (recordCount + 1)` record allocation (`24 == 0x18`). All listed decimal/hex constants were verified with `int_convert.py`.
- The record merge path still calls `DATFile::GetDataPointer` at `0x0049c550`, initializes each bounds block through `0x004b7c50`, appends a terminal zero rectangle sentinel, closes temporary DAT readers, and frees temporary arrays before returning the merged table.
- `get_bytes 0x004d1f22 size 14` returned fourteen `0xcc` bytes before `0x004d1f30`; `14 == 0x0e` was verified with `int_convert.py`.
- Historical note: older wording kept final reconstruction C++ blank despite the confirmed emitter route because helper signature/type/wrapper names were not final-source quality. B011's 2026-07-01 callback supersedes that with an alias/no-duplicate comment on this by-item page and a formal helper body on [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md).

## Ownership Decision

Keep this with `render/MapTileImageLib.cpp` unless a later migration creates a shared `render/ImageFrameTable.cpp` for all EPF archive-table builders.

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `85/90` to `86/90` and inserted the accepted alias/no-duplicate formal comment.
  - Documented that [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) owns the exact helper body and this by-item page must not duplicate it.
- 2026-06-04: Raised grading from `70/85` to `82/88` and attached owner/emitter route `0000L5`.
  - Before: the page had correct high-level behavior but stale provenance wording, an outdated literal endpoint, no parent attachment, and limited evidence for the packing/cleanup flow.
  - After: live IDA MCP evidence documents the exact half-open range, padding, single caller context, shard probe loop, DATFile lifecycle, merged table allocation, record packing/rebasing, sentinel write, and cleanup.
  - Evidence: `lookup_funcs`, live decompile, and IDA Python xref/disassembly inspection support the score increase. Reconstruction C++ remains blank because source-facing names and final signature details are not at source-quality evidence.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the tile EPF metadata loader, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the IDA-verified tile metadata loader. C++ remains blank because final source attachment still needs source-quality signatures and names.
  - Evidence: IDA MCP confirms the exact function range, single `MapTileImageLib` constructor-family caller, and DATFile/HasDATEntry/allocation/table helper callees.

- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had correct ownership and 2026-06-04 live evidence but still used legacy routing/code-entry wording and did not record the current endpoint/padding and constant-verification checks.
  - After: added a score rationale table, current owner/emitter wording, live IDA lookup/analyze/xref/decompile refresh, `get_bytes` padding evidence, and `int_convert.py`-verified constants.
- 2026-06-19 B015 aggregate-boundary sync:
  - Score unchanged. Added raw PE confirmation that this helper is the last child inside the [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) local-method index and that the next owner begins at ObjectStatusBlobParsers.
  - Evidence: local PE range/caller/padding scan and existing IDA-backed helper behavior agree on file-local MapTileImageLib.cpp ownership.
