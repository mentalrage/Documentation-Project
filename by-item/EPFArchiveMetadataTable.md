*** UID:0000UN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPF Archive Metadata Table

## Status

- Confidence: strong for observed loader/projection behavior and in-memory stride/sentinel shape, medium-high for final original type names.
- Entity kind: shared EPF/EPD frame metadata structure.
- Likely source module: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) for the shared loader; per-asset table builders remain with their image-library owners.
- Autogen parent: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
- Main helper: [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- Companion helper: [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- Related registry row: [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now ties the table layout to both current helper sides: loader allocation/merge/sentinel evidence from [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) and projection/boundary-span evidence from [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md). |
| Confidence | 88 | IDA-backed helper pages confirm the 12-byte table header, 24-byte record stride, one-extra-record sentinel, broad render consumers, and ImageFrameTable parent; confidence stays below final-source level until the final C++ structure and field names are proven. |

## Observed Layout

IDA-inspected loaders `LoadImageFrameTable_4D0F50`, `LoadTileEpfMetadata`, `BuildTilecArchiveTable`, `BuildEffectArchiveTable`, and `ResolveSpritePartPath` converge on the same in-memory table layout.

```text
ArchiveMetadataTable / FrameRecordTable
  +0x00  uint16 entryCount
  +0x02  uint16 maxMetric0
  +0x04  uint16 maxMetric1
  +0x06  uint16 reserved
  +0x08  PackedArchiveRecord* records

PackedArchiveRecord
  +0x00  int left
  +0x04  int top
  +0x08  int right
  +0x0c  int bottom
  +0x10  int payloadStart
  +0x14  int payloadEnd
```

On disk or inside a DAT-backed EPF entry, each record is read as:

```text
Raw EPF/EPD record
  +0x00  int16 top
  +0x02  int16 left
  +0x04  int16 bottom
  +0x06  int16 right
  +0x08  int32 payloadStart
  +0x0c  int32 payloadEnd
```

The loaders convert raw bounds to the in-memory `left, top, right, bottom` order with `InitRectBounds`, then add `DATFile::GetDataPointer()` to `payloadStart` and `payloadEnd`.

## Sentinel

Loaders allocate one extra `PackedArchiveRecord` and append a zero-bounds terminator. The terminator's start/end offsets are both set to the payload base plus the record-table offset. This mirrors the DAT entry-table convention of using a final boundary row, but it is an EPF/EPD frame-record sentinel rather than the DAT archive's 17-byte name record.

## Loader And Projection Synchronization

[UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) covers the producer side: it reads one direct EPF/EPD resource or merges numbered shards, allocates a 12-byte header, converts 16-byte raw records into 24-byte in-memory records, and appends the one-extra sentinel row.

[UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) covers the consumer side: it checks the 16-bit count at table `+0x00`, indexes `records + frameIndex * 24` from table `+0x08`, copies bounds into the output draw record, and computes one span as the following record's `+0x10` boundary/start minus the current record's `+0x14` end/baseline field. That resolved `[record + 0x28] - [record + 0x14]` relation is the main proof that the sentinel is source-level table semantics, not incidental cleanup padding.

The adjacent raw helpers after `0x004d165d` are separate frame-record helpers noted by [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md). They should receive their own exact memory pages later and should not be folded into this structure note.

## IDA Verification

- 2026-05-30 live IDA MCP reports [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) as `sub_4D0F50`, `0x004d0f50-0x004d15c5`, with 25 direct callers.
- Hex-Rays output for `0x004d0f50` shows allocation of a `0x0c` byte table header and `24 * (count + 1)` bytes for records, storing the record pointer at table offset `+0x08`.
- The same decompile shows `sub_4B7C50` used to initialize each bounds record, then a terminal `sub_4B7C50(record, 0, 0, 0, 0)` plus matching start/end fields for the sentinel.
- Live IDA disassembly for [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) confirms table offset `+0x08` is the record base, index bounds are checked against the `uint16` count at table offset `+0x00`, and the record address is computed as `recordBase + index * 24`.
- `LoadFrameDrawRecord` copies the 16-byte bounds block into the output record, writes payload/base fields from record offsets `+0x10` and `+0x14`, and computes one output size field from the following boundary record. That confirms the sentinel is part of normal frame-size reconstruction, not just cleanup padding.
- Live IDA MCP reports the same archive-table builder family with narrow owner call sites: `LoadTileEpfMetadata` at `0x004d1b80-0x004d1f22` has one caller from `MapTileImageLib`; `BuildTilecArchiveTable` at `0x004dda60-0x004dde02` has one caller from `StaticObjImageLib`; `BuildEffectArchiveTable` at `0x004de420-0x004de7c2` has one caller from `EffectObjImageLib`; `ResolveSpritePartPath` at `0x004e19d0-0x004e1f27` has two callers in the `NewHumanImageLib` family.
- The raw `top/left/bottom/right` field names are still reconstruction vocabulary. IDA verifies a four-field bounds transform through `InitRectBounds` and the 24-byte in-memory stride, but final C++ type and field names should remain provisional until the table readers are renamed consistently.

## Relation To ResourceLayoutTable

`ImageLib` / `ResourceLayoutTable` uses a closely related record shape for the process-wide `g_pEPFLib` registry. Its row type is documented as [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md). The major difference is ownership: this page describes the broader helper/table form used by image-library loaders, while the `g_pEPFLib` singleton owns named lazy-loaded buckets that UI and render code query directly.

Both families use the same basic raw EPF/EPD record order: top, left, bottom, right, followed by payload offsets. Both append a boundary/sentinel row so the next row can define payload size for the current row.

## Archive Families

| Helper | Archive naming | Consumer |
| --- | --- | --- |
| `LoadImageFrameTable_4D0F50` | Single resource path, or merge prefixes such as `HEAD`, `BODY`, `SWORD`, `FACE`, `HAIR`, `COAT`. | Human/riding/UI/effect image users. |
| `LoadTileEpfMetadata` | `TILE%d.EPF` | `MapTileImageLib` |
| `BuildTilecArchiveTable` | `TILEC%d.EPF` | `StaticObjImageLib` |
| [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md) | `EFFECT%d.EPF` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) |
| [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) | Numbered `<base>%d.EPF` or single `<base>.EPF` | `NewHumanImageLib` |

## Cross-References

- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)

## Changes

- 2026-06-06: Completion/confidence changed from `72/84` to `82/88`.
  - Before: the page described the table layout and sentinel, but its score and evidence text lagged behind the stronger helper pages.
  - After: the page has a score rationale and explicitly links the producer-side loader evidence to the consumer-side draw-record projection and sentinel boundary-span proof.
  - Evidence: [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) documents the IDA-confirmed allocation/merge/sentinel behavior, while [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) and [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) document the resolved next-record boundary/span calculation and adjacent-helper split caveat.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
  - Before: the shared EPF archive metadata layout was documented but unclassified in autogen coverage.
  - After: it is marked as a source-level table/record declaration needed by the image-frame helper layer; C++ remains blank because final type and field names are not at the 95/95 final-code bar.
  - Evidence: the page records live IDA allocation/stride/sentinel behavior for `sub_4D0F50`, `sub_4D1600`, `sub_4D1B80`, `sub_4DDA60`, `sub_4DE420`, and `sub_4E19D0`, and [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) already lists this layout as source content.

- What existed before: The page had `0` completion/confidence and described the layout without enough direct IDA support.
- What it was changed to: The page now scores the table from live IDA evidence and records the exact allocation, stride, sentinel, projection-helper, and owner-call-site facts.
- Summary and evidence: IDA confirms `sub_4D0F50` allocates a `0x0c` byte table header and `24 * (count + 1)` records; `sub_4D1600` indexes records as `recordBase + index * 24`; the table builders at `0x004d1b80`, `0x004dda60`, `0x004de420`, and `0x004e19d0` have the expected narrow owner call sites.
