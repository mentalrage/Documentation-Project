*** UID:0000K1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ImageFrameTable

## Status

- Confidence: high for the shared `LoadImageFrameTable` owner, its first-draft large-loader body, its destroy companion, source-ready small helpers, and adjacent raw frame-record helper ownership; medium-high for inferred table/output type names and final original DATFile/local container spelling.
- Proposed module pair: `render/ImageFrameTable.cpp` and `render/ImageFrameTable.h`.
- Current implementation callback disposition: [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) supplies the complete guarded `ImageFrameTable.h` declarations for `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord`; [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) and [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) are non-emitting index pages; UID000UX follows canonical UID0002P6 to [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md). [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) carries the loader body, while [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md), [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md), and [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md) remain ImageFrameTable-owned helpers. UID0002P6 and StaticObjImageLib are declaration/type consumers of the shared H while their bodies retain their canonical file routes.
- Evidence basis: current by-* docs plus targeted IDA MCP evidence through the B006 implementation callback. Older Wave3/simroot sources are historical leads only and are superseded by the current exact by-memory pages and MCP evidence below.
- Current raw-helper sync: B004 current MCP session `supervisor_recovery_20260705` preserves UID00031T as an ImageFrameTable-owned raw helper with no modeled function/decompile/xrefs/pointer hits, but repairs the formal helper body to use `MemoryMan *memoryMan = GetMemoryMan()` with `memoryMan->AllocateBufferMemory` and `memoryMan->MemmoveWrapper` rather than stale unqualified allocation/copy helper calls. B013 current MCP session `supervisor_recovery_20260705` preserves UID00031U as an ImageFrameTable-owned raw helper at `88/90`; its `CopyFrameRecordBounds` formal body remains accurate and capped by no modeled function, no xrefs/pointer hits, and no original helper/type/linkage proof.

## File Role

This module owns the generic frame-table loader, destroy companion, shared header declarations, and adjacent raw frame-record helpers used by old human/equipment, riding, static object, UI/effect, and related image resources. `ImageFrameTable.cpp` converts DAT-backed EPF/EPD table records into in-memory frame metadata; `ImageFrameTable.h` exposes the accepted archive/output ABI to every translation unit that allocates, indexes, or dereferences it. The shared `LoadFrameDrawRecord` projection body consumes these declarations but is canonically routed as a `g_pEPFLib` ResourceLayoutTable/ImageLib-facet method.

It should not own raw DAT archive indexing. `DATFile` and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) are dependencies from the archive layer. Asset-specific one-caller table builders such as `LoadTileEpfMetadata`, `BuildTilecArchiveTable`, and `BuildEffectArchiveTable` should remain with their owning image-library files unless later evidence proves a common original source file for all EPF table builders.

## Proposed Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) / [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) | `0x004d0f50-0x004d15c5` | `render/ImageFrameTable.cpp` | Loads one EPF/EPD frame table or merges numbered archive shards. The exact by-memory page now emits first-draft `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)` C++; the by-item page is a non-emitting index to avoid duplicate output. |
| [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) | `0x004d15d0-0x004d15fc` | `render/ImageFrameTable.cpp` | Shared nested-payload cleanup helper for blocks returned by `LoadImageFrameTable`; assigned at position `20` after constructor/destructor field pairing proved this file as the direct owner; now has first-draft formal C++. |
| [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) / [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) | `0x004d1600-0x004d165d` | Declaration dependency here; body in `render/ImageLib.cpp` | Extracts one draw/metrics record through `ResourceLayoutTable::LoadFrameDrawRecord`. UID0002P6 emits through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md); UID000UX is a non-emitting index. This file retains the accepted archive table and output declarations plus adjacent raw-helper context. |
| [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md) | `0x004d1660-0x004d1704` | `render/ImageFrameTable.cpp` | Raw source-looking helper that copies two payload spans plus the first 16 frame-record bytes into an output record; still no modeled function/xrefs/pointer hits, but carries first-draft file-local helper C++ using the current MemoryMan method route. |
| [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md) | `0x004d1710-0x004d172d` | `render/ImageFrameTable.cpp` | Raw source-looking helper that copies `record->bounds` from a selected 24-byte frame record through `CopyFrameRecordBounds`; B013 current MCP recheck keeps the body accurate and ImageFrameTable-owned at `88/90`, with no modeled function/xrefs/pointer hits or original helper/type/linkage proof. |
| [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) | structure documentation | `render/ImageFrameTable.h` | Shared table/record shape used by several EPF/EPD loaders and external consumers; emits one guarded H declaration block for `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord`, includes `RectBounds.h`, and leaves formal CPP blank. |

## Exact Ranges

IDA MCP confirms:

- `0x004d0f50-0x004d15c5` for `LoadImageFrameTable_4D0F50`.
- `0x004d15d0-0x004d15fc` for `DestroyOwnedImageBlock_4D15D0`; this is the adjacent destroy companion for frame-table blocks returned by `LoadImageFrameTable`.
- `0x004d1600-0x004d165d` for `LoadFrameDrawRecord_4D1600`.
- `0x004d1660-0x004d1704` for the IDA-unmodeled raw `FrameRecordPayloadCopyHelper`.
- `0x004d1710-0x004d172d` for the IDA-unmodeled raw `FrameRecordRectCopyHelper`.

The helper file is non-contiguous in the binary because other `ResourceLayoutTable` and image-library functions live between or around these ranges.

B006 implementation callback evidence uses MCP database/session `B005_00049P_20260629`: `server_health` reported module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with size `2067`. The B006 recheck repeated full `decompile 0x004d0f50`, `callees 0x004d0f50`, `xref_query to 0x004d0f50 code include_fn`, support-callee lookups/decompiles for DATFile, MemoryMan, HasDATEntry, formatting, RectBounds, operator-new/free thunks, and raw UTF-16 prefix byte reads. That historical audit did not change the owner/path and recorded the old large-loader no-code proof; B010 2026-07-03 supersedes that hard body blocker for UID0002P4 first-draft C++.

## Evidence

- Historical Wave3 `show global 0x004d0f50 --summary` reported `FrameRecordTable_4D1600* __stdcall LoadImageFrameTable_4D0F50(const wchar_t* resourcePath, int mergeMode)` and described a direct-or-merged frame table loader. Current docs preserve the behavior but replace the generated `FrameRecordTable_4D1600` naming with inferred `ArchiveMetadataTable`/`PackedArchiveRecord` declarations.
- Historical Wave3 `show global 0x004d1600 --summary` identified `LoadFrameDrawRecord_4D1600` as a recovered global. Current exact memory page [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) owns the first-draft `void ResourceLayoutTable::LoadFrameDrawRecord(...)` body through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md); the by-item alias is non-emitting and this file remains a declaration dependency.
- IDA MCP caller checks find eight caller functions for `LoadImageFrameTable_4D0F50`, including `HumanImageLib`, `RidingImageLib`, `StaticObjImageLib`, and UI/effect frame users.
- IDA MCP caller checks find ten caller functions for `LoadFrameDrawRecord_4D1600`, spanning map tile draw, static/effect/item/new-human draw paths, and UI/effect frame users.
- IDA MCP callee checks show `LoadImageFrameTable_4D0F50` calls `DATFile` constructor/open/read/seek/close/destructor, `DATFile::GetDataPointer`, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), allocation/free helpers, and rect initialization.
- `LoadFrameDrawRecord_4D1600` has no project callees; it is a pure table extraction helper over already-loaded frame records.
- 2026-06-10 B001-023 IDA MCP confirms no modeled function objects or xrefs at `0x004d1660` and `0x004d1710`, but raw disassembly shows source-looking prologue/`ret 0x0c` helpers over the same 24-byte frame-record table model used by `LoadFrameDrawRecord`.
- 2026-06-11 A003 IDA MCP confirms the destroy-helper ownership chain: `ScrolledPictureControlPane::ScrolledPictureControlPane` stores `LoadImageFrameTable` at `+0x114` and its destructor/scalar-deleting destructor destroy `this[69]`; `OverlayFrameImageEffecter`, `OverlayImageOnPointEffecter`, and `OverlayMovingImageEffecter` constructors store `LoadImageFrameTable` at `+0x140` and their ordinary/scalar-deleting destructors destroy `this[80]`. Those consumers prove the helper releases ImageFrameTable-owned frame-table blocks rather than a class-private UI/effecter allocation.
- 2026-06-22 B015 refines the [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md) consumer side after accounting for its adjusted `+0x04` pane/GrafPort render receiver. The constructor stores the `LoadImageFrameTable(frameResourceName, 0)` result at complete-object `+0x140`; B010 2026-07-03 caller-disassembly evidence shows nearby `ecx = dword_67A744` / `g_pEPFLib` loads are not target parameters. Ordinary and scalar destructor paths free only that owned table block through `DestroyOwnedImageBlock`. The render body's adjusted `this+0x140` normalizes to complete `+0x144`, which is the separate EPFTileContext-compatible frame draw record filled for `GrafPort::DrawTiledBackground`. This keeps ImageFrameTable ownership on the loaded block while routing render-time draw-record use back to the effecter class.
- 2026-06-16 C001 live IDA MCP recheck reconfirmed `0x004d1600-0x004d165d` as a modeled pure projection helper with no callees, ten modeled caller functions, 81 total xrefs including raw not-yet-modeled call sites, and unchanged adjacent raw-helper no-function/no-xref state at `0x004d1660` and `0x004d1710`. C001 applied and saved the low-risk IDA function rename `sub_4D1600 -> LoadFrameDrawRecord`; raw helper starts were not promoted or renamed.
- 2026-06-29 B006 implementation callback: generated `ImageFrameTable.cpp` then had eight empty emitters under header `validator-command-id: 000000001170` / `validator-refreshed-at: 2026-06-29T20:20:23-04:00`. The empty emitters were not all the same class of source item: [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) was a declaration emitter; [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) and [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) were duplicate non-emitting by-item indexes; [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) was treated then as a reconstructable exact loader with a formal no-code proof; [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md), [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md), [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md), and [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md) were exact helper bodies ready for first-draft C++.
- Historical B006 [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) no-code proof: direct mode and merge mode were behavior-complete, including DATFile lifecycle, `24 * (count + 1)` record allocation, payload rebasing, sentinel setup, 18 EPF prefix families, and cleanup, but DATFile declarations and merge-mode object-array/EH cleanup were treated as hard blockers. B010 2026-07-03 supersedes that blocker for this target because current sibling formal bodies and support docs now use the same source-shaped DATFile array, `HasDATEntry`, `swprintf`, open/read/seek/get-data-pointer/close, sentinel, and cleanup pattern as accepted first-draft C++.
- 2026-07-06 B004 UID00031T current MCP sync: session `supervisor_recovery_20260705` reconfirmed no IDA function/decompile/xrefs/pointer hits for the raw `0x004d1660-0x004d1704` helper, exact body/padding bytes, five call instructions, a unique range signature, and separate successor ResourceLayout code at `0x004d1730`. The source route remains this file; the accepted repair is the MemoryMan method-call source shape, not no-code output, ResourceLayout ownership, MemoryMan ownership, or feature-caller ownership.
- 2026-07-06 B013 UID00031U current MCP sync: session `supervisor_recovery_20260705` reconfirmed no IDA function/decompile/callees/xrefs or VA/RVA pointer hits for the raw `0x004d1710-0x004d172d` helper, exact twelve-`CC` prepad, 29-byte body, three-`CC` postpad, 24-byte record stride, 16-byte `movups` bounds copy, `ret 0x0c`, a unique range signature, and separate successor ResourceLayout code at `0x004d1730`. The source route remains this file; `CopyFrameRecordBounds` remains the accurate first-draft body, while ResourceLayout ownership, no-code output, DATFile/MemoryMan ownership, and feature-caller ownership remain rejected.

## Ownership Decision

Group `LoadImageFrameTable_4D0F50`, `DestroyOwnedImageBlock_4D15D0`, and the raw frame-record payload/rectangle helpers as `render/ImageFrameTable.cpp`; emit the shared frame-table declarations through UID0000UN as `render/ImageFrameTable.h`. UID0002P6 is the exception: the 81-xref cross-caller audit shows systematic [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) `g_pEPFLib` receiver setup, so its body is a non-virtual [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) method emitted through [UID:0000K2][ImageLib](by-file/ImageLib.md). This module retains the common declaration/header dependency and adjacent raw-helper context; StaticObjImageLib includes the same H for complete `ArchiveMetadataTable` visibility. The previous grouping of UID0002P6 here is preserved below as historical source-placement reasoning.

Generated output policy after the B006 callback:

- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) and [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) are non-emitting by-item index/support pages. They retain source owner/linkage prose but must not duplicate the exact by-memory source decisions.
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) remains reconstructable and emitted through [UID:0000K1]; after B010 2026-07-03 it emits first-draft `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)` source rather than the older comment/no-code proof.
- [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md), [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md), and [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md) emit first-draft helper bodies through this file. UID00031T specifically uses the current `MemoryMan *memoryMan = GetMemoryMan()` method-call route for its two allocation/copy spans.
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) emits its member body through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)/[UID:0000K2][ImageLib](by-file/ImageLib.md), while this file continues to supply the accepted `ArchiveMetadataTable`, `PackedArchiveRecord`, and `FrameDrawRecord` declaration context.
- UID00031U specifically uses the current `CopyFrameRecordBounds(const ArchiveMetadataTable *table, int frameIndex, RectBounds *outBounds)` body to select `table->records[frameIndex]` and copy `record->bounds`; its confidence cap is the raw no-function/no-xref/no-pointer-hit state and inferred original helper/type/linkage names.
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) emits the shared declarations through formal H, not CPP. The guarded `ImageFrameTable.h` includes `RectBounds.h` because records embed that type by value and is included by ImageFrameTable helpers, ResourceLayout consumers, StaticObjImageLib constructor/destructor children, and other translation units requiring complete table/record definitions.

Keep these related helpers outside this file for now:

- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md), owned by [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md), owned by [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) unless shared-table consolidation is later proven.
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md), owned by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) unless shared-table consolidation is later proven.
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md), owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).

## Open Questions

- Exact original type names remain unproven. Current source-facing declarations use inferred `ArchiveMetadataTable`, `PackedArchiveRecord`, and `FrameDrawRecord` names, with that caveat documented on [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md).
- `LoadFrameDrawRecord` emits as source-level `void ResourceLayoutTable::LoadFrameDrawRecord` on [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md). The complete caller audit treats IDA's residual integer as assignment residue and routes the body through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), while exact original declaration placement remains inferred.
- Shared declaration placement is resolved: the types must be complete in multiple translation units, so UID0000UN emits guarded `ImageFrameTable.h` and leaves CPP blank. The older CPP-local/private-struct possibility is retained as superseded history because it cannot satisfy StaticObjImageLib and other dereferencing consumers without duplication.

## Historical UID0002P6 Placement Assumption

- Earlier passes grouped UID0002P6 with ImageFrameTable because it consumes the shared table declarations, sits beside raw frame-record helpers, and reuses `ecx` inside the callee. The later 81-xref audit found systematic `g_pEPFLib` receiver setup across unrelated consumers. That stronger source-ABI evidence reroutes only UID0002P6/UID0000UX; it does not move the loader, destroy helper, declarations, or adjacent raw helpers from this file.
- `LoadImageFrameTable_4D0F50` now emits first-draft C++ on [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md). The older comment/no-code route was an owner/range-independent B006 dependency-audit conclusion and is retained only as historical context; exact original DATFile declaration import and array/container spelling remain confidence caps.

## Cross-References

- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md)
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)
- [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md)
- [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)

## Changes

- 2026-08-12 B005 UID000184 C184-029 implementation:
  - Raised `90/88` to `91/89` while preserving owner `FILE` and `NexusTK/render/`.
  - Established `ImageFrameTable.cpp` plus `ImageFrameTable.h` as the module pair and routed UID0000UN's complete guarded shared declarations through H with blank CPP.
  - Documented StaticObjImageLib and ResourceLayout consumers, complete-type visibility, RectBounds dependency, and why the former CPP-local/private declaration possibility is superseded, while preserving the later UID000438 placement correction and all loader/helper evidence.

- 2026-07-22 B004 UID000438 accepted support callback:
  - Score remains `90/88`.
  - Removed canonical/source-body ownership of [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) and its non-emitting alias [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) after the cross-caller receiver audit routed them to [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)/[UID:0000K2][ImageLib](by-file/ImageLib.md).
  - Retained the archive/output declarations, loader, destroy helper, adjacent raw helpers, and the prior ImageFrameTable grouping as historical source-placement reasoning.

- 2026-07-06 B013 UID00031U support sync:
  - Score unchanged at `90/88`.
  - Summary/evidence: applied the accepted UID00031U support sync from B013 report SHA256 `E90FC625499F26770755B3BB0E57BEEF1F8CD6E6D26F62C8CD23F0CF683DE9A9`. Current MCP session `supervisor_recovery_20260705` preserved the ImageFrameTable route, exact raw helper range, no-function/no-decompile/no-xref/no-pointer-hit caveat, generated source route, and existing `CopyFrameRecordBounds` body. ResourceLayout, no-code, DATFile/MemoryMan, and feature-caller ownership alternatives remain rejected.

- 2026-07-06 B004 UID00031T method-route sync:
  - Score unchanged at `90/88`.
  - Summary/evidence: applied the accepted UID00031T support sync from B004 report SHA256 `6F4B84BC13FD0C119F285670EA623448B256659B383784815BA9E1BD718CD6F7`. Current MCP session `supervisor_recovery_20260705` preserved the ImageFrameTable route, exact raw helper range, no-function/no-xref caveat, and generated source route, while repairing the target body from stale unqualified MemoryMan helper calls to `MemoryMan` method calls.

- 2026-06-22 B015 OverlayFrameImageEffecter consumer clarification:
  - Score unchanged at `89/86`.
  - Summary/evidence: recorded the corrected complete-object separation for [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md): complete `+0x140` is the owned ImageFrameTable block returned by `LoadImageFrameTable` and freed by `DestroyOwnedImageBlock`, while complete `+0x144` is the frame draw record reached through the adjusted pane/GrafPort render receiver. This preserves ImageFrameTable ownership of the loaded block and avoids misrouting the effecter draw-record field into this file.

- 2026-06-16 C001 LoadFrameDrawRecord support refresh:
  - Score unchanged at `89/86`.
  - Summary/evidence: live IDA MCP reconfirmed the current `LoadFrameDrawRecord` modeled function boundary, broad caller/xref fan-in, adjacent raw-helper split state, and [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) ownership. IDA now carries the saved function name `LoadFrameDrawRecord`; the file-level caveats remain final table/output-record type names and possible helper visibility.

- 2026-06-11 A003 cleanup-helper owner audit:
  - Score remains `89/86`.
  - Summary/evidence: live IDA MCP paired `LoadImageFrameTable` constructor stores with `DestroyOwnedImageBlock` destructor calls in `ScrolledPictureControlPane` and the three overlay-image effecter classes. [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) now attaches here at position `20`; consumer classes remain cross-references, not source owners.

- 2026-06-10 B001-023 raw frame-record helper ownership:
  - Changed score from `88/82` to `89/86`.
  - Summary/evidence: live IDA MCP reconfirmed raw source-looking helper bodies at `0x004d1660-0x004d1704` and `0x004d1710-0x004d172d`, no modeled functions/xrefs, 24-byte frame-record stride, and placement immediately after [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md). The file now clears the strict parent gate for [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md) and [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md); [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) was later resolved by the 2026-06-11 A003 audit.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: shared frame-table helper ownership, exact ranges, caller/callee evidence, DAT/resource dependencies, excluded adjacent helpers, open questions, and cross-references are documented; confidence is capped by final filename and unresolved table/helper type names.

- 2026-06-01 reconstruction path and adjacent cleanup helper update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the `0x004d15d0-0x004d15fc` helper between the two frame-table functions was not listed in this page.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, and [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) is recorded as an adjacent source-authored cleanup helper under source-placement review.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already lists `render/ImageFrameTable.cpp`; IDA MCP `lookup_funcs` and decompilation on 2026-06-01 confirm `0x004d15d0-0x004d15fc` is a real nested-payload cleanup function between the two frame-table helpers.
