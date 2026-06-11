*** UID:0000U4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildEffectArchiveTable 0x004de420

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Autogen parent: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Memory range: `0x004de420-0x004de7c2`

## Function Role

`BuildEffectArchiveTable` scans numbered `EFFECT%d.EPF` archives, merges their frame records into an `ArchiveMetadataTable`, converts payload offsets to DAT-backed absolute pointers, and appends a terminal sentinel record.

IDA xrefs show one caller: `EffectObjImageLib::EffectObjImageLib` at `0x004de007`.

The body follows the same per-asset archive-table pattern as the tile and static-object builders: probe up to 100 numbered archive shards, allocate temporary DAT readers and per-shard headers, accumulate total frame count and max metrics, allocate one contiguous record table plus a sentinel, and rebase each record's payload offsets by the owning `DATFile` payload pointer.

## Live IDA Evidence

Checked on 2026-06-06:

- `lookup_funcs` reports IDA `sub_4DE420` at `0x004de420`, size `0x3a2`; `0x004de7c2` is not a function, and the next function is `sub_4DE7D0` at `0x004de7d0`.
- `callers(0x004de420)` reports one direct caller, `0x004de007` inside [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md).
- The decompile reports `_DWORD *__stdcall sub_4DE420(int a1)` and shows a formatted `EFFECT%d.EPF` probe loop through `sub_41B9B0` plus [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), stopping at the first missing numbered archive or after 100 probes.
- The helper allocates an array of per-shard 12-byte header buffers and an array of temporary `DATFile` objects, opens each `EFFECT%d.EPF` shard through the DAT vtable open slot, and reads the first eight header bytes before accumulating the shard entry count and max metric fields.
- The returned table is a 12-byte header plus `24 * (entryCount + 1)` bytes of packed records. Each raw record is read as four 16-bit bounds fields plus two 32-bit payload offsets, normalized through `InitRectBounds` (`0x004b7c50`), and rebased by `DATFile::GetDataPointer` (`sub_49C550`).
- The final record is a zero-rectangle sentinel. Its start/end payload offsets are both set to the last shard data pointer plus the record-table offset read from that shard, matching [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md).
- Cleanup walks opened temporary `DATFile` objects in reverse, closes/destroys them, frees per-shard header storage and pointer arrays, destructs the stack DAT helper, and returns the merged table pointer.

## Callee Inventory

IDA MCP `callees(0x004de420)` reports the expected EPF archive-table builder family:

| Callee | Current interpretation |
| --- | --- |
| `sub_41B9B0` | Wide formatted path construction for `EFFECT%d.EPF`. |
| [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) / `0x0049c700` | Numbered shard existence probe. |
| `sub_49C130`, `sub_49C160`, `sub_49C550` | `DATFile` construction/destruction and payload-base access. |
| `sub_516030`, `sub_516050`, `operator new`, `j_j_j___free_base` | Memory-manager allocation and temporary-array cleanup. |
| `sub_4B7C50` | 16-byte rectangle initialization for each packed record and sentinel. |
| DAT vtable read/seek/open/close slots | Opens numbered archives, reads header/record data, and seeks to the raw record table. |

## Ownership Decision

Keep this with `render/EffectObjImageLib.cpp` unless the shared EPF archive-table loaders are later consolidated into `render/ImageFrameTable.cpp`.

## Score Rationale

- Completion is `82` because the page now records exact half-open bounds, single constructor caller, shard probe limit, DATFile lifecycle, merged header/record allocation shape, raw-to-packed record conversion, payload rebasing, sentinel semantics, cleanup flow, and the remaining promotion debt.
- Confidence is `88` because live IDA evidence matches the neighboring tile/static archive-table builders and the shared [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) layout. Confidence remains below final audit because the original helper signature, final table type names, and exact by-memory promotion are still unresolved.

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)

## Changes

- 2026-06-06 A002 live IDA evidence pass:
  - Before: the page was `78/86`, described the archive merge only at a high level, and still used the old `0x004de7c1` end spelling.
  - After: raised to `82/88`, corrected the half-open range to `0x004de420-0x004de7c2`, and documented live caller/callee, shard-probe, allocation, record-packing, sentinel, and cleanup evidence.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, and decompilation on 2026-06-06 confirm the `0x3a2`-byte helper, one constructor caller, `EFFECT%d.EPF` probe loop, DATFile temporary readers, 12-byte table header, `24 * (entryCount + 1)` record allocation, payload rebasing through `DATFile::GetDataPointer`, zero-rectangle sentinel, and cleanup sequence. C++ remains blank below the final-source gate.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and stale generated-source wording was removed.
  - Before: the effect archive-table builder was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned source under the validated EffectObjImageLib file root; C++ remains blank because final table type names and field-level reconstruction are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4DE420` at `0x004de420`, size `0x3a2`, one direct caller in `sub_4DDF60`, and archive/table-related callees including `0x0049c700`, `0x0049c160`, `0x0049c550`, `0x00516030`, and `0x00516050`.

- 2026-05-30: Grading changed from `0/0` to `78/86`.
  - Before: page documented effect archive table behavior, one caller, shared EPF pattern, and owner decision but remained unevaluated.
  - After: score reflects documented scan/merge/rebase/sentinel behavior and strong `EffectObjImageLib` ownership, with room left for deeper field-level/raw-code detail.
  - Evidence: xrefs show the sole caller from `EffectObjImageLib::EffectObjImageLib`; behavior matches the linked EPF archive metadata table/resource docs.
