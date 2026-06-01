*** UID:0001VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageEntry

## Status

- Confidence: strong for size and observed offsets, medium for final field names.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Size: 0x0c bytes.
- Evidence: `LoadMonsterTables` parsing and `MonsterImageLib` destructor iterator on 2026-05-26.

## Layout

```text
MonsterImageEntry
  +0x00  int32 baseFrameIndex
  +0x04  uint8 groupCountOrPaletteCount
  +0x05  uint8 anchorModeOrVariantFlags
  +0x06  uint16 animationGroup
  +0x08  void* nestedTable
```

## Notes

- `LoadMonsterTables` reads the first eight bytes of each row from `MONSTER.DNA` or `MONSTER.DND`, then allocates/fills nested palette/frame records behind the pointer at `+0x08`.
- `RenderMonster` and `RenderMonsterImage` add frame offsets from nested frame records to `baseFrameIndex` before retrieving sprite payload and bounds data.
- The generated name `MonsterImageLibEntry` is plausible, but the final original name may have been closer to a monster table row or monster animation record.
- The destructor uses MSVC vector destructor iterator with element size `0x0c` and row destructor `0x00528950`, confirming the row size.

## IDA Verification Notes

- 2026-05-31 IDA MCP `lookup_funcs 0x004dac40` reports `sub_4DAC40` size `0x27d`, so [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) is the exact loader range.
- IDA MCP decompilation of `0x004dac40` shows the main vector allocation as `12 * rowCount + 4` with MSVC vector constructor element size `0x0c`.
- The loader writes the vector pointer to `MonsterImageLib +0x04` and the row count to `MonsterImageLib +0x08`.
- Per row, IDA shows reads of 4 bytes into `entry +0x00`, 1 byte into `entry +0x04`, 1 byte into `entry +0x05`, and 2 bytes into `entry +0x06`.
- IDA MCP decompilation of helper `0x005289d0` shows nested 8-byte record allocation using `entry +0x04` as the count and writes the nested pointer to `entry +0x08`.
- IDA MCP decompilation of helper `0x00528950` shows the row destructor frees the nested 8-byte records and resets the count byte at `+0x04` and pointer at `+0x08`.
- Scores stay below `95` because the original source names for the row and nested records are still not recovered, and downstream render/bounds uses have not been exhaustively audited against every field.

## Cross-References

- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)

## Changes

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `78`, confidence `86`.
- Summary/evidence: IDA MCP on 2026-05-31 verified the exact `LoadMonsterTables` child range, 0x0c row stride, field reads at `+0x00/+0x04/+0x05/+0x06`, nested pointer at `+0x08`, and destructor cleanup behavior. Scores remain below `95` because final source names and all downstream field semantics are not yet exhaustively recovered.
