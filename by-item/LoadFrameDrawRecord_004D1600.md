*** UID:0000UX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LoadFrameDrawRecord 0x004D1600

## Status

- Confidence: strong for behavior and range, medium for final structure names.
- Entity kind: non-emitting by-item index/support page for an exact shared helper.
- Source route: [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) emitted through [UID:0000K2][ImageLib](by-file/ImageLib.md)
- Exact range: `0x004d1600-0x004d165d`
- Canonical memory page: [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)
- Owner/source route: [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), through [UID:0000K2][ImageLib](by-file/ImageLib.md). This page remains `RECONSTRUCTABLE:FALSE` and non-emitting because the exact source body belongs to [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md); emitting here would duplicate the canonical by-memory body.
- Evidence basis: IDA MCP boundary/caller/callee/xref/decompile/disassembly checks through 2026-06-03 plus the 2026-06-06 exact-memory adjacent-boundary correction.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 89 | The by-item page preserves the exact canonical memory route, range/endpoints, no-callee projection body, 81 direct xrefs, systematic `g_pEPFLib` receiver evidence, output field writes, next-record boundary/span calculation, adjacent-helper split status, and duplicate-emitter decision. |
| Confidence | 93 | IDA lookup/xref/decompile evidence, exact memory page [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md), [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md), and the cross-caller singleton-receiver audit agree. This page is non-emitting by design; final source body confidence belongs to UID0002P6. |

## Behavior

`LoadFrameDrawRecord_4D1600` extracts draw metrics for one frame from a loaded frame metadata table.

If `frameIndex` is out of range, it clears at least the output image id and baseline fields. Otherwise it reads one 0x18-byte frame-table record and fills an output draw record with:

- image/payload id or pointer value from record field `+0x10`;
- frame width from `right - left`;
- left/top/right/bottom bounds;
- baseline or payload-end field from record `+0x14`;
- payload span or vertical extent from the following boundary record's `+0x10` field minus the current record's `+0x14`.

The generated output type still contains synthetic reserved fields, so the final table/output type names and exact field names should be reviewed before source migration.

## Caller Evidence

IDA MCP reports ten caller functions:

- `0x004d1a20` map-tile draw path.
- `0x004dd2c0`, `0x004de190` static/effect image draw paths, including [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md).
- `0x004e0d70`, `0x004e21d0`, `0x004e2eb0`, `0x004e4210`, `0x004e4280` item/new-human/sprite draw paths.
- `0x004ff7d0` UI/effect frame user.
- `0x0055b5d0` [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) caustic-frame update path; B002 2026-06-17 confirms this caller passes its `CAUST.EPF` metadata table (`m_causticFrameTable`), 16-bit caustic frame index, and a stack draw record before tiled drawing with `L"CAUST.PAL"`.

IDA MCP reports no project callees for this helper; it is a pure table read/record projection.

IDA MCP recheck on 2026-05-31 confirms `sub_4D1600` starts at `0x004d1600`, ends half-open at `0x004d165d`, has no project callees, and decompiles as a bounds check plus fixed record projection. The same recheck found many raw entry references beyond the ten high-level caller functions listed above, including references in ranges that IDA has not modeled as functions. Treat caller inventory as incomplete until those references are triaged.

IDA MCP recheck on 2026-06-03 confirms the same modeled helper at `0x004d1600` with size `0x5d`, no callees, and twelve modeled call sites across ten functions. `xrefs_to 0x004d1600` also reports many raw code references in the `0x004d51xx-0x004d75xx` bands plus `0x004dcb74` and `0x004e4e21`, so modeled callers are still not the full inventory.

The 2026-06-03 disassembly resolves the prior `entry[10] - entry[5]` question: the helper reads `[record + 0x28] - [record + 0x14]`, i.e. the following 24-byte record's `+0x10` boundary/start field minus the current record's `+0x14` end/baseline field. This matches [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)'s sentinel/boundary-record model. Representative callers such as `0x004ff7d0` consume the output rectangle at `+0x10..+0x1f` and derive dimensions from those bounds, while renderer callbacks receive the whole 0x28-byte draw record.

The 2026-06-06 exact memory page update keeps this item's assignment narrow: [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) is attached to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), while the source-looking raw helpers at `0x004d1660-0x004d1704` and `0x004d1710-0x004d172d` are separate ImageFrameTable helper pages [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md) and [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md), not part of this exact function.

### NewHuman RenderComposition Consumer

[UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) records that `NewHumanImageLib::RenderComposition` consumes the accepted `FrameDrawRecord` projection through [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) and [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md). The projected 40-byte record is then shallow copied into a local vector through the inline append path or [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) and its private [UID:0004DO][0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport](by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md).

The vector retains the helper's complete projected value: payload pointer, width/state, bounds as `sourceRect`, payload span, and end pointer. The observed append/grow path performs a trivial 40-byte shallow copy and introduces no element ownership transfer, copy hook, destructor, allocation, or cleanup.

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` resolves `0x004d1600` to `sub_4D1600`, size `0x5d`; `0x004d165d` and `0x004d1660` are not modeled functions, and the next modeled function remains `0x004d1730`. Decimal size `93 == 0x5d` was verified with `int_convert.py`.
- `analyze_function 0x004d1600` reports ten containing caller functions, no callees, and complexity 2; `xrefs_to 0x004d1600` reports 81 direct code refs (`81 == 0x51`, verified with `int_convert.py`) across those ten modeled functions plus raw/unmodeled sites.
- Targeted decompilation reconfirmed the out-of-range writes at output offsets `+0x04` and `+0x24`, record selection as `recordBase + 24 * frameIndex`, bounds copy to output `+0x10`, payload/end copy to `+0x24`, and span calculation `v3[10] - v3[5]` from next-record `+0x10` minus current-record `+0x14`.
- `24 == 0x18`, `16 == 0x10`, `20 == 0x14`, `36 == 0x24`, and `40 == 0x28` were verified with `int_convert.py` for the record stride and output/next-record offsets.
- Final reconstruction C++ stays blank despite the confirmed emitter route because the table/output type names, field names, and whether the source signature returned `void` or the computed span are not final-source quality.

2026-06-18 B002 [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) source-quality sync: the output record from this helper is consumed as a `FrameDrawRecord` / possible original `TileFrameDrawRecord` by `GrafPort::DrawTiledBackground`. The output rectangle at `+0x10..+0x1f` is the source tile rectangle for that method, and the whole record is passed to callback slot `dword_69B3E8`. This strengthens the `FrameDrawRecord` name for caller-side first-draft code while preserving the open field-name and return-value questions on this helper.

## Ownership Decision

Place the exact method with [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), emitted through [UID:0000K2][ImageLib](by-file/ImageLib.md). The broad caller family systematically prepares [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) as the receiver, which supersedes the earlier free ImageFrameTable-helper route. This by-item page remains useful for name-based navigation, but it must not emit a duplicate body because [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) owns the exact range, member formal, and validator source route.

The alias remains non-reconstructable/non-emitting to remove a false duplicate emitter without losing index evidence. [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) remains a declaration/type dependency and retains the adjacent raw-helper context; those adjacent helpers are not pulled into this item.

## Historical Ownership Assumption Superseded

- Earlier updates attached this alias and canonical body to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) because the projection consumes frame-table declarations and the callee reuses `ecx`. The later 81-xref caller-family audit found systematic `g_pEPFLib` receiver setup across unrelated consumers, making the ResourceLayoutTable/ImageLib facet route the higher-probability source shape. The former route is preserved here as historical reasoning, not current metadata.

## Open Questions

- Exact original spellings for the accepted `FrameDrawRecord` payload/boundary fields remain inferred; use the current human-readable names rather than raw offset labels.
- Keep the adjacent exact helper pages synchronized with this item once final frame-record/output type names are chosen.
- Formal C++ is intentionally blank on this by-item page. The accepted first-draft `void LoadFrameDrawRecord(...)` body lives only on [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md).

## Cross-References

- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md)
- [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md)

## Changes

- 2026-07-22 B004 UID000438 accepted support callback:
  - Raised `86/91 -> 89/93` and changed canonical owner `0000K1 -> 0000BY` while retaining `RECONSTRUCTABLE:FALSE`, blank emitters, and blank formal C++.
  - Synchronized the alias with canonical [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)'s `ResourceLayoutTable::LoadFrameDrawRecord` member/facet route and systematic `g_pEPFLib` receiver evidence.
  - Preserved ImageFrameTable ownership as a superseded historical assumption and retained it as a live declaration/adjacent-helper dependency.

- 2026-07-13 B002 UID0004DO callback synchronization:
  - Metadata, score, non-emitting index role, and exact-helper ownership remain unchanged.
  - Added the `RenderComposition`/UID0004DO consumer route and the exact shallow-copy disposition for all projected `FrameDrawRecord` fields.

- 2026-06-06: Completion/confidence changed from `76/86` to `82/88`, and owner/emitter route changed from blank to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
  - Before: generated item coverage still listed the helper as unassigned even though its exact memory page was already attached to `ImageFrameTable`.
  - After at that time: the by-item page recorded the parent assignment, score rationale, exact-memory synchronization, and adjacent-helper split caveat, while final C++ stayed blank below source-quality evidence. Superseded by B006 2026-06-29: this by-item page is now a non-emitting index, and the exact formal body lives on [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md).
  - Evidence: [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) documents the IDA-confirmed range, no-callee projection body, caller/xref inventory, sentinel-boundary span calculation, and 2026-06-06 adjacent-helper correction; [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) already lists this helper as proposed `render/ImageFrameTable.cpp` content.

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/65` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the table projection helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects verified rebuild relevance while staying conservative because output-structure names and the full caller inventory remain open.
  - Evidence: IDA MCP confirms the exact function range, no project callees, the decompiled bounds-check/record-copy behavior, and additional raw entry references that need later caller triage.

- 2026-06-01: Completion/confidence changed from `50/65` to `68/80`.
  - Before: the page relied on the broad aggregate memory range for canonical details.
  - After: the page points to exact memory documentation for `0x004d1600-0x004d165d`.
  - Evidence: [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) records IDA MCP function boundary, caller/callee inventory, the decompiled projection body, confirmed table offsets, and the unresolved `v3[10] - v3[5]` field relation.

- 2026-06-03: Completion/confidence changed from `68/80` to `76/86`.
  - Before: the page still treated the `entry[10] - entry[5]` relation as unresolved and listed only the modeled caller inventory.
  - After: the page records the exact disassembly-level boundary-record read and the broader raw xref inventory while keeping final type names open.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `decompile`, `disasm`, and representative caller decompilation confirm the helper reads `[record + 0x28] - [record + 0x14]`, has no callees, feeds broad render callbacks, and still has raw unmodeled references beyond the formal caller list.

- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had strong range/projection evidence but still used legacy routing/code-entry wording and treated adjacent helper splits as pending.
  - After: added current owner/emitter wording, refreshed live IDA lookup/analyze/xref/decompile evidence, `int_convert.py`-verified stride/offset constants, and updated adjacent helper references to the exact pages now present.
- 2026-06-17 B002 WaterFilterEffecter support sync:
  - Score unchanged.
  - Summary/evidence: [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) now records this helper as the CAUST frame metadata projection call before GrafPort tiled drawing; ImageFrameTable ownership and final type-name blockers remain unchanged.
- 2026-06-18 B002 DrawTiledBackground support sync:
  - Score unchanged.
  - Summary/evidence: [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) now records this helper's output as the frame/tile draw record consumed by `GrafPort::DrawTiledBackground`, with the `+0x10..+0x1f` rectangle used for tile dimensions and the whole record passed through `dword_69B3E8`.
