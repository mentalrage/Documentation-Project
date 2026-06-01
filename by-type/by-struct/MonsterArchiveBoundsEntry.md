*** UID:0001VB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterArchiveBoundsEntry

## Status

- Confidence: strong for size and field offsets.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Size: 0x18 bytes.
- Evidence: IDA decompilation of `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`.

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

## IDA Verification Notes

- 2026-05-31 IDA MCP decompilation/disassembly of `0x004dbe60` shows the entry allocation as `(entryCount + 1) * 0x18`, proving a 0x18-byte stride.
- The entry loop reads four 2-byte values, then calls [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) initializer `sub_4B7C50` with those values before reading two 4-byte offsets into `entry + 0x10` and `entry + 0x14`.
- IDA disassembly shows both 4-byte offsets are adjusted by the DAT payload base returned by `sub_49C550`, so the in-memory fields at `+0x10` and `+0x14` are payload pointers rather than raw file offsets.
- After the loop, IDA shows a sentinel row initialized with zero bounds and both payload pointers set to `payloadBase + payloadStartOffset`.
- Scores stay below `95` because the source-level name of this record and the precise archive payload contract are still reconstruction vocabulary rather than recovered original names.

## Cross-References

- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md)
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)

## Changes

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `80`, confidence `88`.
- Summary/evidence: IDA MCP on 2026-05-31 verified the 0x18 stride, four signed 16-bit rectangle inputs, shared RectBounds initializer call, two 4-byte payload offsets at `+0x10/+0x14`, conversion of offsets into payload-base pointers, and the terminal sentinel entry. Scores remain below `95` because original source names and full DAT payload semantics are not exhaustively recovered.
