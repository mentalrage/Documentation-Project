*** UID:0000V0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadTileEpfMetadata 0x004d1b80

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Autogen parent: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Memory range: [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md)

## Function Role

`LoadTileEpfMetadata` scans numbered `TILE%d.EPF` archives, opens each present archive through `DATFile`, reads the shared EPF archive metadata header and record table, and merges all records into one `ArchiveMetadataTable` with a terminal sentinel.

Live IDA xrefs show one caller: `MapTileImageLib::MapTileImageLib`.

IDA decompilation shows the helper probes up to 100 numbered archive shards by formatting `TILE%d.EPF` and checking [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md). It then allocates the merged metadata header, opens each present archive through `DATFile`, converts raw EPF record bounds into the shared packed in-memory table, and releases temporary per-archive `DATFile` objects.

IDA MCP recheck on 2026-06-04 confirms `sub_4D1B80` starts at `0x004d1b80`, ends half-open at `0x004d1f22`, has one direct caller at `0x004d18d1` inside `sub_4D1860`, and calls [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), DATFile helpers, allocation/free helpers, and rectangle/table helpers.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` reports IDA `sub_4D1B80` at `0x004d1b80`, size `0x3a2`; `0x004d1f22` is not a function, and the next function is `sub_4D1F30` at `0x004d1f30`.
- IDA Python inspection reports fourteen `0xcc` padding bytes from `0x004d1f22` through `0x004d1f2f`, confirming the half-open range.
- The live decompile reports `_DWORD *__stdcall sub_4D1B80(int a1)` and shows a probe loop for up to 100 formatted `TILE%d.EPF` paths using `sub_41B9B0` and `HasDATEntry`.
- The helper allocates per-shard header storage, allocates and constructs temporary `DATFile` objects, opens each numbered shard through the DAT vtable open slot, and reads header/record data through DAT vtable read/seek slots.
- The merged output is a 12-byte table header plus `24 * (recordCount + 1)` record storage. The body copies rectangle bounds through `sub_4B7C50`, rebases record offsets using `DATFile::GetDataPointer` (`sub_49C550`), appends a zero-rectangle terminal sentinel, closes temporary DAT files, frees temporary arrays, destructs the stack `DATFile`, and returns the merged table.
- The only direct caller is `0x004d18d1` in `sub_4D1860`, immediately after the `MapTileImageLib` vtable store and before the constructor opens `TILE.TBL`, which supports [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) ownership.
- Reconstruction C++ remains blank because the original helper signature, final type names for the metadata table, and exact field names are still below the `95/95` reconstruction threshold.

## Ownership Decision

Keep this with `render/MapTileImageLib.cpp` unless a later migration creates a shared `render/ImageFrameTable.cpp` for all EPF archive-table builders.

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-04: Raised grading from `70/85` to `82/88` and attached `AUTOGEN_PARENT_UID:0000L5`.
  - Before: the page had correct high-level behavior but stale provenance wording, an outdated literal endpoint, no parent attachment, and limited evidence for the packing/cleanup flow.
  - After: live IDA MCP evidence documents the exact half-open range, padding, single caller context, shard probe loop, DATFile lifecycle, merged table allocation, record packing/rebasing, sentinel write, and cleanup.
  - Evidence: `lookup_funcs`, live decompile, and IDA Python xref/disassembly inspection support the score increase. Reconstruction C++ remains blank because source-facing names and final signature details are not proven to `95/95`.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the tile EPF metadata loader, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the IDA-verified tile metadata loader. Parent UID and C++ remain blank because final source attachment still needs the surrounding MapTileImageLib and EPF table code to reach the final-code gate.
  - Evidence: IDA MCP confirms the exact function range, single `MapTileImageLib` constructor-family caller, and DATFile/HasDATEntry/allocation/table helper callees.
