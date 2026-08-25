*** UID:0001VV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef ImageAnimationGroup RidingBucket;
typedef ImageAnimationFrame RidingBucketEntry;

struct RidingDefinition
{
    unsigned int ridingId;
    unsigned char bucketCount;
    unsigned char defaultBucketIndex;
    unsigned short animationGroupId;
    RidingBucket *buckets;

    RidingBucketEntry *GetFrame(
        unsigned int groupIndex,
        unsigned int frameIndex);
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RidingDefinition

## Status

- Confidence: very strong for sizes, offsets, parser/default-table/RenderRiding uses, exact GetFrame contract, and direct owner; strong for inferred field spellings.
- Direct owner class: [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md).
- Source placement: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), with nested table helpers from [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
- Rebuild handling: `source-authored` POD layouts parsed from `RIDINGS.DNA`.

## RidingDefinition Layout

```text
RidingDefinition
  +0x00  uint32 ridingId
  +0x04  uint8 bucketCount
  +0x05  uint8 defaultBucketIndex
  +0x06  uint16 animationGroupId
  +0x08  RidingBucket* buckets
  sizeof = 0x0c
```

The `+0x08` field is managed by the shared 12-byte outer table helper currently documented under [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md). The type itself is riding-specific because the record is parsed from `RIDINGS.DNA`, stored at `RidingImageLib+0x04`, counted at `RidingImageLib+0x08`, and consumed by the riding draw path.

## RidingBucket Layout

```text
RidingBucket
  +0x00  RidingBucketEntry* entries
  +0x04  uint16 entryCount
  +0x06  uint16 helperStateOrPadding
  sizeof = 0x08
```

The `+0x00` field is managed by the 8-byte child table helper currently named `MonsterImageLibTable_528BE0`.

## RidingBucketEntry Layout

```text
RidingBucketEntry
  +0x00  int16 frameOffset
  +0x02  int16 frameDuration
  +0x04  uint8 blendAlphaOrRenderFlag
  +0x05  uint8 reservedOrPadding
  +0x06  int16 auxFrameId
  +0x08  uint8 paletteIndex
  +0x09  uint8 effectIndex
  sizeof = 0x0a
```

The `RidingBucketEntry` names are synchronized with the shared monster/riding frame-entry evidence from the accepted B001 `LoadMonsterTables` rework. `frameOffset`, `frameDuration`, and the shared alpha/flag byte are stronger than `auxFrameId`, `paletteIndex`, and `effectIndex`. Older local wording that called `+0x02` `endFrame` or `+0x04` `direction` is retained only as historical context and should not be used as the shared source-facing type name.

## Field Evidence

- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) is the constructor-only `RIDINGS.DNA` parser and reads definition records in the exact order `+0x00` dword, `+0x04` byte, `+0x05` byte, and `+0x06` word.
- The definition vector allocation uses `count * 0x0c`, and the destructor iterator uses element size `0x0c`.
- The parser stores the definition vector pointer/count at [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) object offsets `+0x04` and `+0x08`, which makes the class the direct owner of the loaded layout.
- For each definition, the parser calls `0x005289d0` with the byte at `+0x04` to allocate `bucketCount` 8-byte child rows.
- For each child row, the parser reads entry count at `+0x04`, calls `0x00528be0`, then reads each 10-byte entry at offsets `+0x00`, `+0x02`, `+0x06`, `+0x04`, `+0x08`, and `+0x09`.
- The global default riding table at [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) seeds 21 default 8-byte child rows with one `RidingBucketEntry` whose `frameOffset` is `0`, `frameDuration` is `30000`, and shared alpha/flag byte is zero.
- [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) converts `ObjectStatusBlob::m_appearanceId + 0x8000` through unsigned-16 wrap, checks the index against the definition count, and selects this exact 12-byte record.
- RenderRiding calls `GetFrame(animationGroup, animationFrame)` twice on the selected record. The first returned `RidingBucketEntry *` supplies signed `frameOffset`; the second result is discarded but is behaviorally required because the same duplicate sequence exists in modeled `MonsterImageLib::RenderMonster` and the out-of-line helper is not proven pure.
- The target adds `ridingId` to `frameOffset`, rejects negative results, passes the signed low 16 bits to the `RIDINGS.EPF` layout lookup, and reads `defaultBucketIndex` as a centered-projection/suppression flag. The field spelling remains historical/current project terminology; its exact render role is now direct consumer evidence.
- B001's 2026-06-25 accepted monster-loader rework checked shared consumers outside the riding parser: entry `+0x02` feeds scheduler/timing calls through `sub_528D00`, and monster render treats entry `+0x04` as alpha/mode intensity. That evidence supersedes the older shared `endFrame` / `direction` names while leaving riding-specific value-domain details open.

## IDA MCP Verification Notes

- 2026-05-31 and 2026-06-07 `lookup_funcs` reports `0x004dc420` as a function with size `0x26d`, matching the parser range `0x004dc420-0x004dc68d` half-open.
- 2026-05-31 `callers` reports the parser is called only from the `RidingImageLib` constructor at `0x004dc6f5`.
- 2026-05-31 parser decompilation verifies the fixed 12-byte definition row, 8-byte bucket row, and 10-byte bucket-entry row sizes and the read/write offsets documented above.
- 2026-05-31 `xrefs_to` confirms `0x0069b438` is referenced only as the global table object's `+0x08` entry-pointer field inside the parser.
- [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) independently confirms the fallback/default table object, static lifetime, default `0x15` group allocation, and repeated render/lookup fallback use of the same 12-byte outer-table shape.
- 2026-07-14 live target/sibling analysis establishes the callable source interface as `RidingBucketEntry *GetFrame(unsigned int groupIndex, unsigned int frameIndex)`. Shared implementation `0x00528b10` remains under UID0001CM/MonsterImageLibTables; this page declares the member because both riding and monster definition records use the ABI-compatible outer-table shape.

## Notes

The helper class names remain monster-biased because the same nested table machinery is shared by monster and riding parsers. Final source should use neutral names or keep these as local nested structs under the sprite animation table helper. The currently accepted neutral method-level names are `ImageAnimationGroup` and `ImageAnimationFrame`.

The three POD layouts here are riding-specific declarations, but the allocator/destructor/lookup helper implementation is shared with [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md). Do not move or duplicate that implementation under `RidingImageLib` solely because the riding parser and RenderRiding call it. The formal C++ uses `typedef` aliases from accepted shared helper types and declares `GetFrame` on the ABI-compatible outer record; UID0001CM remains the single implementation owner.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md). This child is `90/92`, its direct class parent is `91/92`, and source-file parent [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) is `91/92`, so the strict child/direct-parent gate clears. The relationship is direct because `RidingImageLib` owns the loaded definition vector/count, `RIDINGS.DNA` parser, `RIDINGS.EPF` render path, retained RenderRiding consumer, and fallback/default riding definition table. [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) remains the shared helper implementation owner rather than the semantic parent for this riding resource layout.

## 2026-06-30 B008 Source-Quality Callback

B008's accepted report resolves the blank type-emitter marker by adding formal riding-specific declarations. `RidingDefinition` remains the 12-byte record parsed from `RIDINGS.DNA`; `RidingBucket` and `RidingBucketEntry` are source aliases to accepted shared `ImageAnimationGroup` and `ImageAnimationFrame` shapes. This preserves the exact parser offsets and allocation sizes while avoiding duplicate helper implementation under RidingImageLib.

Weak field names remain caveated: `frameDuration`, `blendAlpha`, `auxFrameId`, `paletteIndex`, and `effectIndex` are inferred source-facing names. The parser order and row sizes are stronger than those exact original spellings.

## UID0003U8 Shared Signed Duration Synchronization - 2026-07-15

- Because `RidingBucketEntry` aliases the shared `ImageAnimationFrame`, its `+0x02` timing field is signed `int16`/C++ `short frameDuration`. This synchronization changes no RidingDefinition formal declaration, owner/emitter route, score, record size, parser order, RenderRiding behavior, or shared-helper ownership.
- Five shared timing consumers at `0x0053a30b`, `0x0053aaae`, `0x0053b780`, `0x0053ba59`, and `0x005a37d6` sign-extend frame word `+2`. [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md) is the final listed consumer and routes the signed value into TimerMgr event `20`.
- The riding parser still reads two bytes and default riding buckets still write decimal `30000`; signedness therefore preserves serialized width and default value. Historical `uint16 frameDuration` wording is superseded while all weak exact-spelling caveats remain.

## Score Rationale

- Completion is `90` because the three nested record sizes, field offsets, parser order, vector storage, default-table seeding, exact RenderRiding selection/GetFrame/frameOffset consumer, complete callable declaration, source owner, shared-helper boundary, accepted frame-entry corrections, and parent gate are documented.
- Confidence is `92` because parser, class layout, global table, target and RenderMonster sibling bodies, shared helper, and B001 frame-entry evidence agree on record shapes, method ABI, and ownership. It remains below final lexical confidence because `auxFrameId`, `paletteIndex`, `effectIndex`, `defaultBucketIndex`, and riding-specific value-domain spellings are provisional.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md)
- [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)

## Changes

- 2026-07-14 B003 UID0002Y1 source-quality callback:
  - Raised `88/90` to `90/92` and installed the accepted complete declaration with `RidingBucketEntry *GetFrame(unsigned int, unsigned int)`.
  - Added exact RenderRiding unsigned-16 definition selection, duplicate GetFrame calls, frameOffset/ridingId arithmetic, negative exit, signed-low-16 RIDINGS lookup, and `defaultBucketIndex` render-role evidence.
  - Preserved the exact 12/8/10-byte layouts, aliases, parser/default-table/destructor evidence, weak field-name caveats, and UID0001CM as the single shared helper implementation owner.

- 2026-06-25 B001 implementation callback:
  - Score unchanged at `85/88`.
  - Evidence: synchronized the `RidingBucketEntry` layout with accepted [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) shared-frame evidence. Replaced stale `+0x02=endFrame` and `+0x04=direction` shared names with `frameDuration` and `blendAlphaOrRenderFlag`, and marked `auxFrameId`, `paletteIndex`, and `effectIndex` as weaker inferred fields.
- 2026-05-31: Changed completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: the page contained useful layout notes but was still scored as unevaluated and did not explicitly mark the type as reconstructable.
  - After: the page is scored as a strongly verified but non-final layout and `RECONSTRUCTABLE:TRUE`; owner/emitter routing and code remained blank at that time because final source names and helper ownership were not yet ready.
  - Evidence: IDA MCP verification of `0x004dc420-0x004dc68d`, helper calls at `0x005289d0`/`0x00528be0`, default table xrefs, and exact parser read offsets.
- 2026-06-11 A001 strict-gate assignment:
  - What existed before: scores were `78/84`, current owner/emitter routing was blank, and the page did not document why the riding-specific layout should attach to `RidingImageLib` instead of the shared helper file.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, and current owner/emitter route [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md); added assignment-gate and score-rationale sections plus draw-helper/global-table consumption evidence.
  - Summary/evidence: [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md), [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md), [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), and [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) agree that `RidingImageLib` owns the loaded definitions while [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) owns the shared helper implementation.
