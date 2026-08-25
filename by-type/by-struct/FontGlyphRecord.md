*** UID:0001UK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FontGlyphRecord is declared before FontImageLib by [UID:00005B][FontImageLib](by-class/FontImageLib.md).
// This page remains exact resource-record layout evidence only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact variable-size FontGlyphRecord resource declaration with consumed advance/bounds fields, encoded rows at +0x0e, BARAM%02d.EFT pointer-table provenance, decoder token consumers, two reserved 16-bit fields, and one leading declaration through UID00005B; this page emits only a covered-by comment. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FontGlyphRecord

## Status

- Confidence: strong for consumed fields, encoded-row start, variable resource layout, declaration order, and covered-by route; the two unused 16-bit meanings and historical spellings remain capped.
- Owner: [UID:00005B][FontImageLib](by-class/FontImageLib.md).
- Direct autogen parent: [UID:00005B][FontImageLib](by-class/FontImageLib.md). This record page is `92/94`, the direct class parent is `94/94`, and source-file parent [UID:0000JH][FontImageLib](by-file/FontImageLib.md) is `94/94`.
- Producer resource: `BARAM00.EFT` / `BARAM01.EFT` font archives.
- Rebuild handling: source-declared resource payload record used by the rebuilt `FontImageLib` loader and decoder; record bytes come from DAT-backed font resources, but the C++ declaration/layout is needed by source.
- C++ reconstruction status: the complete struct is declared exactly once, before `FontSlotStorage` and `FontImageLib`, by [UID:00005B][FontImageLib](by-class/FontImageLib.md). This page emits the R10 covered-by comment only, preventing a duplicate late declaration while retaining exact layout/resource evidence.

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

## Field Evidence

| Field | Evidence |
| --- | --- |
| `+0x00 advance` | [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md) reads `mov ax, [record]` when the caller requests an advance output. |
| `+0x02 top` | `MeasureGlyphWidth` pushes `word ptr [record+0x02]` into the optional bounds initializer; [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) also reads this field when writing the tile-context rectangle. |
| `+0x04 left` | `MeasureGlyphWidth` uses this field with `right` to reject zero-width records and passes it to bounds output; `DecodeGlyphBitmap` uses it as the rectangle left edge and row-stride base. |
| `+0x06 bottom` | `MeasureGlyphWidth` passes this field to bounds output; `DecodeGlyphBitmap` uses it as the rectangle bottom edge. |
| `+0x08 right` | `MeasureGlyphWidth` computes `right - left` before accepting a glyph record; `DecodeGlyphBitmap` uses `right - left` for row stride. |
| `+0x0a reserved0 / unknown` | Live IDA disassembly of the measurement and decode methods does not read this word. It is preserved in the fixed header because the decoder begins the encoded stream at `record + 0x0e`. |
| `+0x0c reserved1 / unknown` | Same as `+0x0a`: code skips over it, but the row-stream start proves it exists in the on-disk/in-memory payload. |
| `+0x0e encodedRows[]` | `DecodeGlyphBitmap` executes `lea edi, [record+0x0e]`, then walks zero-terminated token streams row by row. |

[UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) does not copy records. It reads a `0x10000` offset table from the selected `BARAM%02d.EFT` payload and stores `payloadBase + offset` into [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md), so `FontGlyphRecord` remains a variable-size resource payload pointer rather than a fixed array copied into the `FontImageLib` object.

## Encoded Rows

Each glyph row is a run-token stream terminated by byte `0`. A token uses the low five bits for run length and the high three bits for a palette index. After each row terminator, the decoder advances to the next row stream.

`DecodeGlyphBitmap` applies the caller-provided palette map and clips run writes to the decoded row width. When the caller does not request a buffer clear, palette index `5` behaves as a skip/transparent run; when the buffer was cleared, palette index `0` is skipped and nonzero palette indexes are written.

Live IDA MCP on 2026-06-11 reconfirmed the decode loop instructions used for this layout: `movsx` reads from `record+0x02/+0x04/+0x06/+0x08`, `lea edi, [record+0x0e]` selects the encoded stream, `and token, 0x1f` extracts run length, `shr token, 5` extracts palette index, and the `_memset` span is clamped between the current run start and the decoded row width.

## Ownership And Score Rationale

Attach this record type to [UID:00005B][FontImageLib](by-class/FontImageLib.md) because it is a private font-resource declaration consumed only by the `FontImageLib` slot loader, glyph measurement method, and glyph decoder. The file-level owner [UID:0000JH][FontImageLib](by-file/FontImageLib.md) remains the source module above the class.

Completion is `92` because the direct-parent gate, declaration order, covered-by route, field consumer matrix, pointer-table provenance, encoded token semantics, instruction evidence, and exact single leading declaration are closed. Confidence is `94` because all consumed offsets, variable-size payload boundary, decode algorithm, and source role agree across loader/measure/decode evidence; `+0x0a/+0x0c` meanings and historical field spelling remain deliberately capped and represented as `reserved0`/`reserved1`.

## Cross-References

- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md)
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)

## Changes

- 2026-07-20 B003 UID0001P2 source-closure callback:
  - Raised `90/91` to `92/94`, preserved UID00005B owner/emitter, and replaced the duplicate late struct formal with exact R10 covered-by text.
  - The complete declaration now occurs once before `FontSlotStorage` and `FontImageLib` in UID00005B. All exact field offsets, BARAM resource provenance, pointer-table behavior, token decoding, unknown-field limits, and historical evidence remain on this page.

- 2026-06-11 Agent-A001 Batch 148 assignment-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, and no autogen parent. The page documented the main consumed fields but did not carry the direct-parent gate, field evidence matrix, or loader provenance needed to clear `85` completion.
  - After: raised to `85/90` and attached to [UID:00005B][FontImageLib](by-class/FontImageLib.md).
  - Summary/evidence: live IDA MCP rechecked `0x004b6020`, `0x004b60c0`, and `0x004b61e0`; the measurement method reads `advance/top/left/bottom/right`, the loader stores payload pointers from a `0x10000` offset table rather than copying records, and the decoder starts encoded rows at `record+0x0e` while skipping the two unresolved 16-bit fields.
- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `78/88`.
  - Summary/evidence: IDA MCP decompilation of `FontImageLib::MeasureGlyphWidth`, `EnsureFontSlotLoaded`, and `DecodeGlyphBitmap` confirms the consumed record fields, `0x10000` glyph-pointer table ownership, encoded stream start at `record + 0x0e`, and token layout. The two 16-bit fields at `+0x0a/+0x0c` remain unresolved, keeping scores below near-final.
- 2026-06-06: Corrected the producer resource names from stale `BA0` / `BA1` shorthand to `BARAM00.EFT` / `BARAM01.EFT`, based on the live loader literal evidence documented at [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md).
- 2026-06-06: Added the decoder's row-width clipping detail from [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md), which clamps each memset span against the decoded rectangle width before filling mapped palette bytes.
- 2026-06-29 B001 UID0002HP implementation callback:
  - Before: `85/90` with formal C++ blank.
  - Changed to: `90/91` with exact formal `FontGlyphRecord` declaration emitted through [UID:00005B][FontImageLib](by-class/FontImageLib.md).
  - Summary/evidence: accepted constructor support scope requires the glyph record type used by [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md). The declaration uses source-facing consumed names for `advance`, bounds fields, and `encodedRows`, while retaining `reserved0`/`reserved1` for the two verified but not semantically named 16-bit fields.
