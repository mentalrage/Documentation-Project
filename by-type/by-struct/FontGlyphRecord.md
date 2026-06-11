*** UID:0001UK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontGlyphRecord

## Status

- Confidence: strong for consumed fields and encoded-row start, medium for the two unused 16-bit fields.
- Owner: [UID:00005B][FontImageLib](by-class/FontImageLib.md).
- Producer resource: `BARAM00.EFT` / `BARAM01.EFT` font archives.

## Layout

```text
FontGlyphRecord
  +0x00  short advance
  +0x02  short top
  +0x04  short left
  +0x06  short bottom
  +0x08  short right
  +0x0a  short reserved0 / unknown
  +0x0c  short reserved1 / unknown
  +0x0e  unsigned char encodedRows[]
```

IDA-confirmed code uses `advance`, `top`, `left`, `bottom`, and `right`. [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) starts row decoding at `record + 0x0e`, proving two 16-bit fields exist between `right` and the encoded stream, but their meaning is still open.

## Encoded Rows

Each glyph row is a run-token stream terminated by byte `0`. A token uses the low five bits for run length and the high three bits for a palette index. After each row terminator, the decoder advances to the next row stream.

`DecodeGlyphBitmap` applies the caller-provided palette map and clips run writes to the decoded row width. When the caller does not request a buffer clear, palette index `5` behaves as a skip/transparent run; when the buffer was cleared, palette index `0` is skipped and nonzero palette indexes are written.

## Cross-References

- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md)
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)

## Changes

- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `78/88`.
  - Summary/evidence: IDA MCP decompilation of `FontImageLib::MeasureGlyphWidth`, `EnsureFontSlotLoaded`, and `DecodeGlyphBitmap` confirms the consumed record fields, `0x10000` glyph-pointer table ownership, encoded stream start at `record + 0x0e`, and token layout. The two 16-bit fields at `+0x0a/+0x0c` remain unresolved, keeping scores below near-final.
- 2026-06-06: Corrected the producer resource names from stale `BA0` / `BA1` shorthand to `BARAM00.EFT` / `BARAM01.EFT`, based on the live loader literal evidence documented at [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md).
- 2026-06-06: Added the decoder's row-width clipping detail from [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md), which clamps each memset span against the decoded rectangle width before filling mapped palette bytes.
