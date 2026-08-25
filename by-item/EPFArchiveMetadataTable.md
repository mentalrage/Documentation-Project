*** UID:0000UN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_IMAGEFRAMETABLE_H
#define NEXUSTK_RENDER_IMAGEFRAMETABLE_H

#include "../ui/core/RectBounds.h"

struct PackedArchiveRecord
{
    RectBounds bounds;
    unsigned char *payloadStart;
    unsigned char *payloadEnd;
};

struct ArchiveMetadataTable
{
    unsigned short frameCount;
    unsigned short maxWidth;
    unsigned short maxHeight;
    unsigned short reserved;
    PackedArchiveRecord *records;
};

struct FrameDrawRecord
{
    int reserved0;
    unsigned char *payloadStart;
    int reserved8;
    int width;
    RectBounds sourceRect;
    int payloadSpan;
    unsigned char *payloadEnd;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EPF Archive Metadata Table

## Status

- Confidence: strong for observed loader/projection behavior, in-memory stride/sentinel shape, and shared-header placement; medium-high for final original type names.
- Entity kind: shared EPF/EPD frame metadata structure.
- Source placement: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) owns `NexusTK/render/ImageFrameTable.h` for this shared declaration block and `ImageFrameTable.cpp` for shared loader/helper bodies; per-asset table builders remain with their image-library owners and include the header rather than duplicating declarations.
- Owner/emitter route: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
- Main helper: [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- Companion helper: [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- Related registry row: [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The page ties the table layout to both current helper sides: loader allocation/merge/sentinel evidence from [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md), projection/boundary-span evidence from [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md), refreshed IDA checks for record stride and next-record boundary use, and one complete guarded `ImageFrameTable.h` declaration block consumed by ImageFrameTable, StaticObjImageLib, and other render translation units. CPP is blank because this item owns shared declarations, not definitions. |
| Confidence | 92 | IDA-backed helper pages and live MCP refresh confirm the 12-byte table header, 24-byte record stride, one-extra-record sentinel, broad render consumers, and ImageFrameTable parent. Cross-translation-unit complete-type use resolves header placement. Confidence stays below final-source level because `ArchiveMetadataTable`, `PackedArchiveRecord`, `FrameDrawRecord`, and field names remain source-facing inferred names rather than recovered original symbols. |

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

## Formal Declarations

The formal `RECONSTRUCTION_H CODE` block emits one guarded `NexusTK/render/ImageFrameTable.h` declaration surface used by the accepted ImageFrameTable helper bodies and external consumers. The formal CPP channel is intentionally blank because these are shared type declarations rather than `ImageFrameTable.cpp`-local definitions:

- `PackedArchiveRecord`: 24-byte in-memory record with a `RectBounds` block and two payload boundary pointers.
- `ArchiveMetadataTable`: 12-byte header with 16-bit count/dimension fields and a pointer to records.
- `FrameDrawRecord`: caller-facing output record consumed by draw paths such as `GrafPort::DrawTiledBackground`.

These names are inferred, not original-symbol proof. They are stronger than raw generated names such as `FrameRecordTable_4D1600` because related accepted docs and callers already use `FrameDrawRecord`, the table is not tile-only, and the loader/projector serve broad UI/effect/human/riding/static-object consumers.

The H block includes `../ui/core/RectBounds.h` because both `PackedArchiveRecord` and `FrameDrawRecord` embed `RectBounds` by value and therefore require its complete definition. StaticObjImageLib may forward-declare `ArchiveMetadataTable` in its class H because it stores only a pointer, but its CPP includes this shared H before constructor/destructor children that allocate or dereference the table.

## Sentinel

Loaders allocate one extra `PackedArchiveRecord` and append a zero-bounds terminator. The terminator's start/end offsets are both set to the payload base plus the record-table offset. This mirrors the DAT entry-table convention of using a final boundary row, but it is an EPF/EPD frame-record sentinel rather than the DAT archive's 17-byte name record.

## Loader And Projection Synchronization

[UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) covers the producer side: it reads one direct EPF/EPD resource or merges numbered shards, allocates a 12-byte header, converts 16-byte raw records into 24-byte in-memory records, and appends the one-extra sentinel row.

[UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) covers the consumer side: it checks the 16-bit count at table `+0x00`, indexes `records + frameIndex * 24` from table `+0x08`, copies bounds into the output draw record, and computes one span as the following record's `+0x10` boundary/start minus the current record's `+0x14` end/baseline field. That resolved `[record + 0x28] - [record + 0x14]` relation is the main proof that the sentinel is source-level table semantics, not incidental cleanup padding.

The adjacent raw helpers after `0x004d165d` are separate frame-record helpers noted by [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md), and they now have exact child pages: [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md) and [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md). UID00031T uses these shared declarations while copying two payload spans into a `FrameDrawRecord` through `MemoryMan` allocation/copy methods; UID00031U copies the 16-byte bounds block. These helpers should not be folded into this structure note.

## NewHuman RenderComposition Consumer

[UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) records `NewHumanImageLib::RenderComposition`, which uses `FrameDrawRecord` as the 40-byte, trivially shallow-copied element of its local vector. [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md), [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md), and [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md) populate or adjust that element before the compiler-generated vector helpers [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) and [UID:0004DO][0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport](by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md) copy it shallowly.

The 40-byte `FrameDrawRecord` is ABI-compatible in size with [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), and both are initialized through the same raw 40-byte zero-initialization helper. They are not the same semantic type: `FrameDrawRecord` carries `payloadStart`, `payloadEnd`, `payloadSpan`, and `sourceRect`, while `EPFTileContext` carries a rendering surface context including distinct fields at `+0x20` and `+0x24`. Collapsing the declarations would erase observed producer/consumer meaning and is rejected.

## IDA Verification

- 2026-05-30 live IDA MCP reports [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) as `sub_4D0F50`, `0x004d0f50-0x004d15c5`, with 25 direct callers.
- Hex-Rays output for `0x004d0f50` shows allocation of a `0x0c` byte table header and `24 * (count + 1)` bytes for records, storing the record pointer at table offset `+0x08`.
- The same decompile shows `sub_4B7C50` used to initialize each bounds record, then a terminal `sub_4B7C50(record, 0, 0, 0, 0)` plus matching start/end fields for the sentinel.
- Live IDA disassembly for [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) confirms table offset `+0x08` is the record base, index bounds are checked against the `uint16` count at table offset `+0x00`, and the record address is computed as `recordBase + index * 24`.
- `LoadFrameDrawRecord` copies the 16-byte bounds block into the output record, writes payload/base fields from record offsets `+0x10` and `+0x14`, and computes one output size field from the following boundary record. That confirms the sentinel is part of normal frame-size reconstruction, not just cleanup padding.
- Live IDA MCP reports the same archive-table builder family with narrow owner call sites: `LoadTileEpfMetadata` at `0x004d1b80-0x004d1f22` has one caller from `MapTileImageLib`; `BuildTilecArchiveTable` at `0x004dda60-0x004dde02` has one caller from `StaticObjImageLib`; `BuildEffectArchiveTable` at `0x004de420-0x004de7c2` has one caller from `EffectObjImageLib`; `ResolveSpritePartPath` at `0x004e19d0-0x004e1f27` has two callers in the `NewHumanImageLib` family.
- The raw `top/left/bottom/right` field names are still reconstruction vocabulary. IDA verifies a four-field bounds transform through `InitRectBounds` and the 24-byte in-memory stride, but final C++ type and field names should remain provisional until the table readers are renamed consistently.

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` resolves `0x004d0f50` to `sub_4D0F50`, size `0x675`; `0x004d15c5` is not a function, and the adjacent functions remain `0x004d15d0` size `0x2c` and `0x004d1600` size `0x5d`.
- `analyze_function 0x004d0f50` reports size `1653`, eight containing caller functions, and 18 callees; `xrefs_to 0x004d0f50` reports 25 direct code refs. Decimal size `1653 == 0x675` was verified with `int_convert.py`.
- Targeted decompilation of `0x004d0f50` reconfirmed a shard scan capped at `100 == 0x64`, a 12-byte table/header allocation (`12 == 0x0c`), `24 * (count + 1)` frame-record allocation (`24 == 0x18`), DAT-entry probing through `0x0049c700`, and terminal zero-rectangle sentinel setup through `0x004b7c50`; all listed decimal/hex equivalences were verified with `int_convert.py`.
- `analyze_function 0x004d1600` reports size `0x5d`, ten containing caller functions, and no callees; `xrefs_to 0x004d1600` reports 81 direct code refs across ten modeled functions.
- Decompilation of `0x004d1600` confirms record address calculation as `recordBase + 24 * frameIndex`, bounds copy from current record offsets `+0x00..+0x0f`, current payload/end field at `+0x14`, and output span from the next record's `+0x10` boundary (`v3[10]`, offset `0x28`) minus current `+0x14`; `16 == 0x10`, `20 == 0x14`, `24 == 0x18`, and `40 == 0x28` were verified with `int_convert.py`.
- Final reconstruction C++ now emits the inferred declaration block. Exact original struct and field names remain below final-source proof, so the score remains under final-audit confidence rather than blocking useful helper output.
- The declaration block's former CPP placement is historical. It left cross-translation-unit consumers with an incomplete `ArchiveMetadataTable` at dereference sites. Moving the same accepted declarations to guarded `ImageFrameTable.h` resolves visibility without duplicating types or changing their measured ABI.

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

- 2026-08-12 B005 UID000184 C184-029 implementation:
  - Raised `88/91` to `90/92` while preserving owner/emitter UID0000K1, reconstructability, and blank emitter position.
  - Moved the complete accepted `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord` declarations from formal CPP to a guarded formal `ImageFrameTable.h` H block with the required `RectBounds.h` include; formal CPP is now blank.
  - Documented shared-header source placement, StaticObjImageLib complete-type consumption, and the historical reason CPP-local declarations were insufficient while retaining all ABI, sentinel, loader, projection, consumer, and inferred-name evidence.

- 2026-07-13 B002 UID0004DO callback synchronization:
  - Metadata, score, owner/emitter routing, and the accepted `FrameDrawRecord` declaration are unchanged.
  - Added the `NewHumanImageLib::RenderComposition` consumer route: `FrameDrawRecord` is the 40-byte shallow vector element populated by the accepted loader/resolver helpers and copied by UID00017U/UID0004DO compiler support.
  - Recorded why equal size and a shared raw initializer do not justify collapsing `FrameDrawRecord` into `EPFTileContext`; the observed fields and source roles remain distinct.

- 2026-07-06 B004 UID00031T helper-page sync:
  - Score unchanged at `88/91`.
  - Summary/evidence: historicalized the stale statement that adjacent raw helpers still needed exact pages. UID00031T and UID00031U now have exact by-memory pages; UID00031T uses this shared table/record declaration shape with the accepted MemoryMan method-route payload-copy body.

- 2026-06-06: Completion/confidence changed from `72/84` to `82/88`.
  - Before: the page described the table layout and sentinel, but its score and evidence text lagged behind the stronger helper pages.
  - After: the page has a score rationale and explicitly links the producer-side loader evidence to the consumer-side draw-record projection and sentinel boundary-span proof.
  - Evidence: [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) documents the IDA-confirmed allocation/merge/sentinel behavior, while [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) and [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) document the resolved next-record boundary/span calculation and adjacent-helper split caveat.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
  - Before: the shared EPF archive metadata layout was documented but unclassified in autogen coverage.
  - After at that time: it was marked as a source-level table/record declaration needed by the image-frame helper layer, while C++ stayed blank because final type and field names were not yet at source-quality evidence. Superseded by B006 2026-06-29, which adds inferred formal declarations while preserving the inferred-name caveat.
  - Evidence: the page records live IDA allocation/stride/sentinel behavior for `sub_4D0F50`, `sub_4D1600`, `sub_4D1B80`, `sub_4DDA60`, `sub_4DE420`, and `sub_4E19D0`, and [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) already lists this layout as source content.

- What existed before: The page had `0` completion/confidence and described the layout without enough direct IDA support.
- What it was changed to: The page now scores the table from live IDA evidence and records the exact allocation, stride, sentinel, projection-helper, and owner-call-site facts.
- Summary and evidence: IDA confirms `sub_4D0F50` allocates a `0x0c` byte table header and `24 * (count + 1)` records; `sub_4D1600` indexes records as `recordBase + index * 24`; the table builders at `0x004d1b80`, `0x004dda60`, `0x004de420`, and `0x004e19d0` have the expected narrow owner call sites.

- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page already linked the producer and consumer helpers but did not record the current IDA refresh or `int_convert.py` checks for the header/stride/span constants.
  - After at that time: updated the score rationale, added fresh `lookup_funcs`, `analyze_function`, `xrefs_to`, and decompile evidence for the loader/projection pair, and documented why final C++ remained blank under the then-active source-quality gate. Superseded by B006 2026-06-29 formal declaration insertion.
