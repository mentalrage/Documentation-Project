*** UID:0001VB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MonsterArchiveBoundsEntry
{
    RectBounds rect;
    const unsigned char *payloadStart;
    const unsigned char *payloadEnd;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterArchiveBoundsEntry

## Status

- Confidence: strong for size and field offsets.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Size: 0x18 bytes.
- Owner/emitter route: attached to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md), which now clears the strict route gate and emits through [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md).
- Evidence: IDA decompilation/disassembly of `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`, the aggregate builder at `0x004db8b0`, and cleanup at `0x004dc2e0`.
- Formal C++: emits the 24-byte source-facing entry declaration through the MonsterImageLib class route.

## Layout

```text
MonsterArchiveBoundsEntry
  +0x00  RectBounds rect
  +0x10  char* payloadStart
  +0x14  char* payloadEnd
```

## Notes

- The loader reads four 16-bit signed bounds values, initializes the shared [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) layout, then reads two 32-bit offsets for the payload start/end.
- The payload offsets are converted to pointers by adding the current archive payload base returned by the DAT reader.
- `GetArchiveBoundsBucket` allocates one extra entry after the real `entryCount`. That sentinel has zero bounds and start/end pointers equal to `payloadBase + payloadStartOffset`.
- 2026-06-27 B003 live MCP session `80de0a67` reconfirmed that the target allocates 0x18-byte rows plus one sentinel, reads four signed 16-bit bounds values and two 32-bit offsets for each real row, initializes the `RectBounds` subobject through `0x004b7c50`, rebases both offset fields by the DAT payload base, and writes the sentinel with zero bounds and both payload pointers set to the payload base plus the entry-table payload offset.

## IDA Verification Notes

- 2026-05-31 IDA MCP decompilation/disassembly of `0x004dbe60` shows the entry allocation as `(entryCount + 1) * 0x18`, proving a 0x18-byte stride.
- The entry loop reads four 2-byte values, then calls [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) initializer `sub_4B7C50` with those values before reading two 4-byte offsets into `entry + 0x10` and `entry + 0x14`.
- IDA disassembly shows both 4-byte offsets are adjusted by the DAT payload base returned by `sub_49C550`, so the in-memory fields at `+0x10` and `+0x14` are payload pointers rather than raw file offsets.
- After the loop, IDA shows a sentinel row initialized with zero bounds and both payload pointers set to `payloadBase + payloadStartOffset`.
- Scores stay below `95` because the source-level name of this record and the precise archive payload contract are still reconstruction vocabulary rather than recovered original names.
- 2026-06-14 live IDA MCP rechecked the loader and related helpers: `GetArchiveBoundsBucket` at `0x004dbe60` is size `0x315`, the unreferenced aggregate builder at `0x004db8b0` is size `0x3a2`, the resolver at `0x004dc180` is size `0xb5`, bounds computation at `0x004db5c0` is size `0x2e1`, and `ClearLoadedData` at `0x004dc2e0` is size `0x135`.
- Live disassembly of the loader at `0x004dc010-0x004dc15e` reconfirmed the 8-byte bucket header read at `0x004dc01d`, the `(entryCount + 1) * 0x18` allocation at `0x004dc020-0x004dc02e`, the entry-array store to bucket offset `+0x08` at `0x004dc03f`, four consecutive two-byte bounds reads, two four-byte payload-offset reads into entry offsets `+0x10/+0x14`, the `RectBounds` initializer call at `0x004dc0dd`, payload-base addition to both payload fields at `0x004dc0e8/0x004dc0ea`, and the zero-bounds sentinel with both payload pointers set from the payload base at `0x004dc10d-0x004dc12e`.
- 2026-06-27 B003 rechecked the same sequence against the target decompile/disassembly and support docs. The source-facing `payloadStart`/`payloadEnd` names remain the best reconstruction vocabulary; original record/field names and the full DAT payload contract remain provisional.

## Score Rationale

Completion is raised to `87` because the entry size, stride math, `RectBounds` payload, payload pointer conversion, sentinel-row behavior, loader/helper/caller context, cleanup chain, strict owner/emitter route, and formal struct declaration are all documented with current IDA evidence. Confidence is raised to `91` because loader disassembly directly proves the field offsets and stride; it remains below final-audit range because original record names and the full `DATA/MON%d.DAT` payload contract are still provisional.

## Cross-References

- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md)
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `85/90` to `87/91`.
  - Evidence: inserted the formal `MonsterArchiveBoundsEntry` struct declaration with `RectBounds rect`, `payloadStart`, and `payloadEnd`. Preserved 0x18 row stride, four signed 16-bit bounds, RectBounds initializer, two 32-bit payload-offset reads, payload-base rebasing, sentinel row, and provisional original-name caveat.
- 2026-06-27 B003 GetArchiveBoundsBucket support sync:
  - Score unchanged at `85/90`.
  - Evidence: added live MCP session `80de0a67` confirmation for 0x18-byte row allocation, four signed 16-bit bounds, two 32-bit payload offsets, RectBounds initialization, payload-base rebasing, and the zero-bounds sentinel used by [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md).
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/88`, with correct entry-layout evidence but completion still capped at the old attachment threshold.
  - Changed to: `85/90`.
  - Summary/evidence: live IDA MCP reconfirmed `GetArchiveBoundsBucket` size `0x315`, aggregate builder/resolver/bounds/cleanup helper sizes, the 8-byte bucket header read, `(entryCount + 1) * 0x18` allocation, `+0x08` entry-array pointer store, four 16-bit bounds fields, `+0x10/+0x14` payload pointers, payload-base adjustment, and sentinel-row initialization. C++ remains blank because original record/source field names and the full DAT payload contract are still not final-source quality.
- 2026-06-06: Attached the bounds entry to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md). Scores remain `80/88`; the record is class-owned archive metadata used by `MonsterImageLib::GetArchiveBoundsBucket`.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `80`, confidence `88`.
- Summary/evidence: IDA MCP on 2026-05-31 verified the 0x18 stride, four signed 16-bit rectangle inputs, shared RectBounds initializer call, two 4-byte payload offsets at `+0x10/+0x14`, conversion of offsets into payload-base pointers, and the terminal sentinel entry. Scores remain below `95` because original source names and full DAT payload semantics are not exhaustively recovered.
