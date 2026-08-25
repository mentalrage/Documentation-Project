*** UID:0000N5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ResourceLayoutTable

## Status

- Confidence: very strong for the complete source-family split: `render/ResourceLayoutTable.cpp/.h` owns exactly two external no-`this` raw helpers, while nine class/facet methods and the compiler-covered row accessor remain in `render/ImageLib.cpp/.h`.
- Proposed module: narrow `render/ResourceLayoutTable.cpp/.h` containing UID0002KQ then UID0002KT in address/source order. No class method, global, row declaration, decoder, frame helper, or compiler data item emits through this file page.
- Autogen/source-root status: the exact modeled method pages currently parent through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) to [UID:0000K2][ImageLib](by-file/ImageLib.md) and therefore assemble under `auto-generated/NexusTK/render/ImageLib.cpp`; B001-023 now uses this file page as the direct parent for the two non-method raw ResourceLayout helpers [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md).
- Main audited neighborhood: [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md), a non-emitting mixed aggregate; this file owns only the two exact helper ranges within it.
- Primary global instance: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical IDA alias `DAT_0067a744`, constructed by [UID:0000K2][ImageLib](by-file/ImageLib.md)

## File Role

`ResourceLayoutTable` is the recovered name for the shared EPF/EPD resource-layout method cluster. It should not be treated as a per-control UI helper or as raw DAT archive parsing. The methods lazily open DAT-backed EPF/EPD entries, convert their frame records into an in-memory [UID:0000KS][List](by-file/List.md) of layout-name records, and return `EPFTileContext` or rectangle data to rendering/UI code.

The current best source-file interpretation is that these methods likely lived near [UID:0000K2][ImageLib](by-file/ImageLib.md), because `ImageLib::ImageLib` assigns `g_pEPFLib = this` and initializes the same `+0x0c` list/store field used by the layout methods. The concrete object is now pinned by [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md); the layout methods are not virtual slots in that table. The likely original source file contained:

- `ImageLib`
- `ResourceLayoutTable`
- `ResourceLayoutEntry`
- private layout record structures backed by the generic `List` container
- the global instance declaration used as `g_pEPFLib`

`EPFImageControlPane`, `AboveFrame`, item glyph helpers, minimap/dialog panes, and image libraries are consumers of this registry. They should call it from their own modules rather than own the EPF record table.

The raw helpers [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) sit in this address neighborhood and consume the same 24-byte record format. They are not `thiscall` class methods, but B001-023 assigns them to this file-level helper grouping because their body/source-family evidence is stronger than caller ownership by `UserLookPane`, `HumanImageLib`, or `NewHumanImageLib`.

Historical pre-callback output populated only UID0002KT, placed it first, made it `static`, duplicated a private table type, left UID0002KQ as an Empty Emitter Marker, and emitted no sibling header. The accepted UID0000N5 reconstruction supersedes that state: both helpers are complete, externally linked, ordered KQ then KT, and declared once in the new owner H. UID0002KQ deliberately preserves its one-row initialization, uninitialized next-row read, and leaked allocation as original behavior rather than treating them as an unresolved source blocker.

## Evidence

- Wave3 class inspection summarizes this class as a shared layout-resource table that resolves named EPF/EPD records by index.
- `ResourceLayoutTable::LookupLayoutEntry` at `0x004d02f0` has very broad fan-in: hundreds of callers across UI panes, image libraries, and sprite/effect code.
- `EPFImageControlPane::LoadAndRenderImage` calls the same `0x004d02f0` target through `g_pEPFLib`.
- `AboveFrame` uses `g_pEPFLib` for `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD`.
- `ImageLib::ImageLib` at `0x004cffb0` assigns `g_pEPFLib = this`, allocates a 20-byte `List`, and calls `List::List(44, 10)` before storing it at object offset `+0x0c`; `ImageLib::ScalarDeletingDestructor` clears that global.
- Application shutdown deletes [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical IDA alias `DAT_0067a744`, which matches a process-wide image/resource registry lifetime.
- IDA MCP xrefs to `0x0067a744` on 2026-05-24 show many consumers but the owner writes remain in the `ImageLib` constructor/destructor family.
- IDA MCP vtable review on 2026-05-24 resolves the suspected `ResourceLayoutStore` vtable as the generic `List` vtable at `0x0061ce2c`; `LoadResourceIndex` uses `List::Append` and lookup paths use `List::GetElementAt`.
- IDA MCP on 2026-06-10 confirms [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) as a two-argument raw-buffer helper with one `UserLookPane::ParseLookPacket` caller and no `this` use.
- IDA MCP on 2026-06-10 confirms [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) as a no-callee raw record-rectangle helper, with two modeled `NewHumanImageLib::CalculateCompositionBounds` callsites and additional orphan human-image composition callsites.

## Public API Shape

| Method | Address | Role |
| --- | --- | --- |
| `LoadResourceIndex` | [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md) | Opens a named EPF/EPD resource through `DATFile`, reads its frame records, normalizes offsets, registers a bucket, and now attaches through the class/facet to `ImageLib.cpp`. |
| `LookupLayoutEntry` | [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) | Lazy-loads a resource when needed, fills an `EPFTileContext` for one entry, and now attaches through the class/facet to `ImageLib.cpp`. |
| `CopyEntryTileContext` | `0x004d04d0` | Loads an entry into a temporary context and copies it to the caller. |
| `GetEntryRect` | `0x004d0530` | Lazy-loads a resource and returns only the stored frame bounds. |
| `GetFrameSize` | [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md) | Returns bucket-wide frame width/height metadata and now attaches through the class/facet to `ImageLib.cpp`. |
| `GetEntryCount` | [UID:0002KV][0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount](by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md) | Returns bucket record count and now attaches through the class/facet to `ImageLib.cpp`. |
| `FindResourceIndex` | [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md) | Scans registered resource names, returns the bucket index, and now attaches through the class/facet to `ImageLib.cpp`. |

Attachment status as of B001-023: [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md), [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md), [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md), [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md), [UID:0002KV][0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount](by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md), and [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md) meet the child gate and parent through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md). [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) attach directly to this file page as raw file-level ResourceLayout helpers. They intentionally do not parent through the class page because neither is a `thiscall` method.

## Ownership Decision

Use `render/ImageLib.cpp` as the broader owner for the class-backed singleton methods. B011's accepted empty-emitter implementation puts first-draft source bodies on the seven exact method children through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) and [UID:0000K2][ImageLib](by-file/ImageLib.md), so those methods assemble under `auto-generated/NexusTK/render/ImageLib.cpp`. Use this file page only as a narrow `render/ResourceLayoutTable.cpp`/private helper grouping for raw ResourceLayout-format helpers that are not class methods. Current constructor/global evidence still says the main layout methods operate on the `ImageLib` singleton object behind `g_pEPFLib`; the raw helpers are assigned here because their direct class/global/caller alternatives are weaker.

Do not reconstruct a standalone `ResourceLayoutStore` class. The registry field should be modeled as `List*` with 44-byte `ResourceLayoutNameRecord` elements unless later evidence proves the original source wrapped the list in a typed helper.

Do not create an `EPFLibrary` class from current generated references. The generated `EPFLibrary::LoadFrame` call sites are naming artifacts for calls into `ResourceLayoutTable::LookupLayoutEntry`.

Do not absorb the nearby [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) into this class. They are physically interleaved in the `0x004d` resource neighborhood, but their callers and behavior are shared image-loader glue, not EPF layout-table methods.

## Cross-References

- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md)
- [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md)
- [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md)
- [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md)
- [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md)
- [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md)
- [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md)
- [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md)
- [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md)
- [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

## 2026-08-16 UID0000N5 Whole-File Implementation

This page is the complete file owner for exactly two authored definitions:

1. UID0002KQ `ResourceLayoutRawBufferLookupEntry` `[0x004d03a0,0x004d04d0)`, 304 bytes, position 10. It parses one raw layout row from a buffer, allocates `header[0]+1` 24-byte entries without zeroing, initializes only row zero, returns borrowed pixel/mask pointers through `EPFTileContext`, computes mask length from uninitialized `entries[1].pixelData`, and never frees the allocation. The absence of a loop, sentinel initialization, zero-fill, free, and extra guard is exact negative evidence and must be preserved as a historical client defect.
2. UID0002KT `ResourceLayoutRawRecordGetEntryRect` `[0x004d05a0,0x004d05e6)`, 70 bytes, position 20. It is an external `RectBounds *__stdcall` helper over `const ArchiveMetadataTable *`, copies the selected 24-byte record's leading bounds when `entryIndex < frameCount`, otherwise calls `InitRectBounds(0,0,0,0)`, and returns the caller's `bounds` pointer. Its 28 callers establish shared cross-file linkage; the old `static` duplicate-table reconstruction is rejected.

`ResourceLayoutTable.h` is centralized on UID0002KQ and contains exactly the necessary forwards plus both external declarations. UID0002KT's H channel remains blank to prevent a second declaration route. `ResourceLayoutTable.cpp` includes that H and the exact EPFTileContext, ImageFrameTable, ImageLib, RectBounds, and MemoryMan dependencies before the two children. No third-party source import applies.

The complete related family is nine out-of-line ImageLib/facet methods, these two file helpers, and one H-only inline row accessor. There is no ResourceLayout-owned global, static table, string, constant, vtable, RTTI, lifecycle object, or separate storage. The seven image decoders and four frame-table helpers interleaved in the corrected aggregate retain ImageLoaders/ImageFrameTable ownership, and all 20 `0xcc` gaps remain non-source.

Expected generated output is one `NexusTK/render/ResourceLayoutTable.cpp` containing exactly corrected KQ then KT, plus one `ResourceLayoutTable.h` containing exactly both declarations. It must contain no Empty Emitter Marker, `static` cross-file helper, duplicate table/row definition, class method, reversed child order, or undeclared dependency. The former one-body/one-marker CPP and absent-H state remains dated history only.

Score `95/93` reflects complete whole-file function/data/type/gap/owner/source/emitter and generated-output closure. Filename and recovered helper spelling remain inferred confidence caps; ABI, behavior, placement, and module contents are exact.

- 2026-07-02 B013 UID0002KT implementation sync:
  - Score unchanged for this file page.
  - Updated raw-helper role text to record that [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) now emits first-draft formal C++ through this file-level raw-helper owner, while [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) remains blank under its separate raw-buffer next-row/mask-size blocker.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms UID0002KT as a `0x46` byte, no-callee, three-argument raw-record rectangle helper with three basic blocks, 21 instructions, 28 xrefs, 24-byte `ResourceLayoutEntry` stride, and predecessor/successor padding. Ownership remains file-level UID0000N5; class, ImageLib, Human/NewHuman caller, aggregate, and generated Ranking/callsite ownership remain rejected.
- 2026-06-30 B011 ImageLib empty-emitter family sync:
  - Score unchanged.
  - Summary/evidence: the class-backed `ResourceLayoutTable` methods are now source-bearing exact children of [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) and emit through [UID:0000K2][ImageLib](by-file/ImageLib.md) into `ImageLib.cpp`. This file page remains the direct owner only for no-this raw helpers [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md), preserving the class-backed-vs-raw-helper split.
- 2026-06-10 B001-023 raw-helper parent inference:
  - Changed score from `86/83` to `88/86`.
  - Evidence: live IDA MCP reconfirmed [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) as `__stdcall` raw ResourceLayout-format helpers with no `this`; their caller modules are consumers, while the shared 24-byte record format and address clustering make this file-level ResourceLayout helper grouping the strongest direct owner. This parent now clears the `85/85` gate for those two children without claiming they are class methods.
- 2026-06-08 A010 Batch120 parent/source audit:
  - Changed confidence from `80` to `82`.
  - Evidence: updated the attachment status for [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md). The child now clears `85/88`, but this file remains only a possible helper split because the raw helper has no `this` use and no proven direct source owner. This narrows the blocker from child-score failure to ownership uncertainty without promoting the standalone `ResourceLayoutTable.cpp` file split.
- 2026-06-08 A003 Batch132 raw-record helper audit:
  - Changed confidence from `82` to `83`.
  - Evidence: updated [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) after it reached `85/88` and documented why this page was not yet a proven direct source owner at that time: the helper has no `this`, is called by human-image composition paths, and was then only physically/source-family adjacent to the ResourceLayout/ImageLib method cluster.
  - B013 2026-07-02 historical note: this older uncertainty is superseded for UID0002KT by the current first-draft source-quality pass. UID0002KT remains directly owned by this file-level helper grouping with formal C++; the human-image callsites remain consumer evidence rather than direct ownership.
- 2026-06-07 A006 Batch 048 split-recheck:
  - Before: several public API, evidence, and cross-reference links still used old inclusive-looking filenames for five ResourceLayout child pages.
  - Changed to: canonical IDA-exclusive filenames for [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md), [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md), [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md), and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md). At that time, the file score remained `86/80` because the helper-file split and raw/accessor ownership questions remained open; B001-023 and the B013 UID0002KT callback supersede the UID0002KT ownership/C++ uncertainty.
  - Evidence: live IDA boundary map uses exclusive ends `0x004d02e5`, `0x004d039e`, `0x004d0522`, `0x004d059b`, and `0x004d05e6`; the child docs and aggregate now use the same convention.
- 2026-06-07 A006 Batch 048 corrected-gate repair:
  - Before: the attachment list still left [UID:0002KV][0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount](by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md) unattached because the child completion side was below the corrected gate.
  - Changed to: `GetEntryCount` now links its exact page and attaches through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) after that child reached `85/92` and the direct parent reached `87/86`. At that time, the file score remained `86/80` because the standalone helper-file split and raw helper ownership questions remained open; B001-023 and the B013 UID0002KT callback supersede the UID0002KT ownership/C++ uncertainty.
- 2026-06-07 A008 alias cleanup:
  - Before: status and evidence lines used bare `DAT_0067a744` wording for the layout-registry singleton.
  - Changed to: canonical [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) wording with `DAT_0067a744` retained as the historical IDA alias.
  - Evidence: the page already documents `ImageLib` constructor/destructor ownership of the singleton and broad `ResourceLayoutTable` consumer use.
- 2026-06-05: Assigned projected reconstruction folder.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - After: set the folder to `NexusTK/render/`.
  - Evidence: live IDA MCP lookup confirms the documented layout-table anchors at `0x004d0120` and `0x004d02f0`; proposed-source-tree currently stages `ResourceLayoutTable.cpp` under render resource support. The existing ImageLib-vs-helper split caveat remains open, so this is a folder/source-family assignment rather than a final claim that the original build had an independent class file.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document now captures role, proposed contents, public API shape, singleton/global ownership, IDA-backed evidence, ownership exclusions, and cross-references; confidence remains capped by unresolved original class/file boundary between `ImageLib` and a possible helper split.
- 2026-06-03: Added the raw record-rectangle helper caller caveat.
  - Before: the file page did not mention that the nearby `0x004d05a0` raw helper is consumed by human-image composition code.
  - After: added [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) and [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) cross-references, while final source ownership was still open at that time. B001-023 and the B013 UID0002KT callback supersede that ownership/C++ uncertainty for UID0002KT.
  - Evidence: IDA MCP `callers`, `xrefs_to`, `decompile`, and `disasm` on 2026-06-03 confirm the helper's no-callee rectangle-copy body, modeled NewHuman callsites, and orphan old/new human composition xrefs.
- 2026-06-07 A007 child attachment status:
  - What existed before: status still referenced the recovered generated source, and the public API table used bare start addresses for methods whose exact by-memory pages now have attachment-ready evidence.
  - Changed to: status now explains the current autogen split: this page remains a `ResourceLayoutTable.cpp` helper-split placeholder, while the exact modeled method pages attach through [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) to [UID:0000K2][ImageLib](by-file/ImageLib.md). Public API and cross-reference sections now point at the attached exact memory pages.
  - Evidence: validator accepted [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md), [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md), [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md), [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md), and [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md) as children of class/facet UID `0000BY`; generated memory coverage reports them assigned to `auto-generated/NexusTK/render/ImageLib.cpp`. File score remains `86/80` because the standalone helper-file split and several raw/accessor children remain open.
