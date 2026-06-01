*** UID:0001UM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontSlotStorage

## Status

- Confidence: strong for size and offsets, medium for final field names.
- Owner: [UID:00005B][FontImageLib](by-class/FontImageLib.md).
- Size: `0x40008` bytes.

## Layout

```text
FontSlotStorage
  +0x00000  DATFile* archiveFile
  +0x00004  unsigned short maxCellWidth
  +0x00006  unsigned short maxCellHeightMinus4
  +0x00008  FontGlyphRecord* glyphTable[0x10000]
  +0x40008  end
```

## Behavior

[UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) initializes this structure lazily. It opens `BA0` or `BA1`, reads the two 16-bit maximum cell metrics, subtracts four from the height field, then reads `0x10000` relative offsets. Nonzero offsets are resolved against the `DATFile` payload base and stored as [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) pointers.

The `archiveFile` pointer doubles as the loaded flag. Destructors test it before dispatching the archive object's virtual deleting destructor.

## Cross-References

- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md)
- [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md)

## Changes

- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `78/88`.
  - Summary/evidence: IDA MCP decompilation of `FontImageLib::EnsureFontSlotLoaded` proves the `0x40008` slot size, DATFile pointer-as-loaded-flag, two 16-bit metrics, and `0x10000` pointer table; destructor pages prove slot cleanup behavior.
