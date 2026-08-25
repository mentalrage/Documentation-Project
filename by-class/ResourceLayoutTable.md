*** UID:0000BY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0000BY] no class-level C++ body.
// UID00006E defines the real class and `typedef ImageLib ResourceLayoutTable`; this page preserves the non-virtual compatibility-facet method family and emits no independent class. Exact method children carry the source bodies.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutTable

## Status

- Confidence: strong for live method boundaries, lazy EPF/EPD registry behavior, row layout, `ImageLib` singleton ownership, the accepted `typedef ImageLib ResourceLayoutTable` compatibility route, and child-page attachment. Exact original alias/header spelling and several private field names remain inferred confidence caps.
- Autogen parent: [UID:0000K2][ImageLib](by-file/ImageLib.md) as the current broader source owner for class-backed methods. [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) now owns the non-method raw ResourceLayout helpers as a file-level helper grouping.
- Address range: [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md)
- Reconstruction handling: source-authored and reconstructable. This class/facet page now emits only a no-class-body marker with `[[CHILDREN]]`; exact executable method children carry the first-draft source bodies because the independent-object declaration route is not supported.

## Class Purpose

`ResourceLayoutTable` is the accepted compatibility typedef for the lazily populated EPF/EPD frame-resource lookup method cluster implemented by [UID:00006E][ImageLib](by-class/ImageLib.md). Callers pass a DAT-backed resource name such as `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, `ITEM.EPF`, or `ITEM.EPD` plus a frame index. The ImageLib object loads the resource once, stores a named bucket, and returns frame pixel and mask offsets through `EPFTileContext`.

The process-wide instance is [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical IDA alias `DAT_0067a744`. [UID:00006E][ImageLib](by-class/ImageLib.md) constructs that object, assigns `g_pEPFLib = this`, declares the complete non-virtual method surface, emits `typedef ImageLib ResourceLayoutTable`, and owns the sole `extern ImageLib *g_pEPFLib` declaration. This page preserves the recovered ResourceLayout vocabulary as compatibility-facet and method-family evidence; it does not authorize an independent class, base subobject, global type, vtable, allocation, or lifetime.

## Observed Object Shape

```text
  +0x00  int reserved0
  +0x04  int reserved1
  +0x08  int reserved2
  +0x0c  List* entryList
```

This historical method-family projection overlaps the actual `ImageLib` layout: `ImageLib` has an `LObject` base at `+0x00`, `maxEntries` at `+0x08`, and a `List* entryList` at `+0x0c`. IDA MCP confirms `ImageLib::ImageLib` constructs that field with `List::List(44, 10)`. The projection is useful for decoding method operands but is not a second source object layout.

The `entryList` owns 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows. The older [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) names are retained as documentation aliases, but current evidence says the binary uses the generic [UID:000079][List](by-class/List.md) container rather than a custom store class. The element shape is:

```text
ResourceLayoutNameRecord
  +0x00  wchar_t name[16]
  +0x20  uint16 recordCount
  +0x22  uint16 frameWidth
  +0x24  uint16 frameHeight
  +0x26  uint16 reservedHeaderWord
  +0x28  ResourceLayoutEntry* records
```

`LoadResourceIndex` appends this 44-byte row through `List::Append`; lookup/count/size methods retrieve it through `List::GetElementAt`.

## Method Notes

- `LoadResourceIndex` reads the EPF/EPD table header, seeks to the raw record table, allocates `entryCount + 1` `ResourceLayoutEntry` records, converts raw bounds to `left, top, right, bottom`, adds `DATFile::GetDataBase() + 0xc` to payload offsets, appends a sentinel, and appends a 44-byte `ResourceLayoutNameRecord` to the `List` under a 16-wchar resource key.
- `LookupLayoutEntry` calls `FindResourceIndex`, falls back to `LoadResourceIndex`, bounds-checks the requested entry, and fills an `EPFTileContext` with pixel pointer, row stride, bounds, encoded-mask size, and mask pointer.
- `GetEntryRect`, `GetFrameSize`, and `GetEntryCount` all share the same lazy-load pattern.
- `FindResourceIndex` scans `ResourceLayoutNameRecord` values using `wcscmp`.
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) is the shared non-virtual `ResourceLayoutTable::LoadFrameDrawRecord` projection method. Its 81-xref caller family systematically prepares [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) `g_pEPFLib` as receiver before the call; the body bounds-checks a frame index, projects a packed archive record into `FrameDrawRecord`, and derives payload span from the following sentinel/boundary record.
- [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) is a direct `LookupLayoutEntry` consumer. It uses the accepted ImageLib pointer with ResourceLayout compatibility spelling to resolve `CHATVAR.EPF` frame `0/1` into a borrowed `EPFTileContext` before rendering `CHATVAR.PAL`; this is consumer evidence, not Chatting ownership of the API.
- [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) remains outside the direct method inventory; B001-023 assigns it to file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) because it is a two-argument raw-buffer helper with no `this` use.
- [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) likewise remains outside the direct method inventory; B001-023 assigns it to file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) because it is a three-argument raw-record helper with no `this` use.

## Live IDA Evidence

- Live IDA MCP verifies the relevant function boundaries: `ImageLib` constructor `0x004cffb0-0x004d006f`, ordinary destructor `0x004d0070-0x004d011b`, `LoadResourceIndex` `0x004d0120-0x004d02e5`, `LookupLayoutEntry` `0x004d02f0-0x004d039e`, raw-buffer lookup helper `0x004d03a0-0x004d04d0`, `CopyEntryTileContext` `0x004d04d0-0x004d0522`, `GetEntryRect` `0x004d0530-0x004d059b`, raw-record rect helper `0x004d05a0-0x004d05e6`, `GetFrameSize` `0x004d1730-0x004d1773`, `GetEntryCount` `0x004d1780-0x004d17b3`, and `FindResourceIndex` `0x004d17c0-0x004d182f`.
- Live byte audit confirms only `0xcc` padding in the local alignment gaps: `0x004d011b-0x004d0120`, `0x004d02e5-0x004d02f0`, `0x004d039e-0x004d03a0`, `0x004d0522-0x004d0530`, `0x004d059b-0x004d05a0`, `0x004d1773-0x004d1780`, and `0x004d17b3-0x004d17c0`.
- Live decompilation of `0x004cffb0` installs vtable `0x0061b654`, writes `g_pEPFLib` at `0x0067a744`, stores the constructor argument at object offset `+0x08`, sets `+0x10` to `1000000`, allocates 20 bytes, and constructs the `+0x0c` registry with `List::List(44, 10)`.
- Live xrefs to `0x0067a744` show broad consumer reads, while owner writes/clears remain in `ImageLib`: constructor write at `0x004cffef`, constructor null fallback at `0x004cfff6`, and destructor clear at `0x004d00fa`.
- Live xrefs to `0x0061b654` show the `ImageLib` vtable installed by constructor `0x004d0009`, ordinary destructor `0x004d009a`, and scalar deleting destructor `0x004e64d1`; no separate `ResourceLayoutTable` vtable was observed for the lookup family.
- Live decompilation of `LoadResourceIndex` shows an 8-byte header read, record-table offset read, allocation of `24 * (entryCount + 1)` bytes, raw top/left/bottom/right plus pixel/mask offsets per record, sentinel construction, 16-wchar key copy, and append into `this[3]`.
- Live decompilation of the lookup/accessor methods confirms the lazy-load pattern: `FindResourceIndex` first, `LoadResourceIndex` on `-1`, then `List::GetElementAt` through `this+0x0c`; `LookupLayoutEntry` maps the row to an `EPFTileContext`, `GetEntryRect` copies a rectangle or zeroes it, `GetFrameSize` returns row header words at `+0x22/+0x24`, and `GetEntryCount` returns the row count at `+0x20`.

## Important Caveats

- `ResourceLayoutTable` stores EPF/EPD frame metadata; it does not decode archive-level DAT directory records.
- `ImageLib` constructor/destructor evidence forbids moving these methods into a standalone class: the accepted source class, singleton, list field, and lifetime are already unified under UID00006E.
- The provisional `EPFLibrary` name seen in some recovered files is not a confirmed class. Its call targets resolve to `ResourceLayoutTable`.
- The resource key copy in `LoadResourceIndex` uses a 16-wchar local buffer. The earlier `wchar_t name[0x16]` overlay was a stride artifact: 44 bytes equals 22 UTF-16 code units, but the last 12 bytes are metadata and the entries pointer.
- IDA MCP xrefs on 2026-05-24 show `g_pEPFLib` is initialized and cleared by the `ImageLib` constructor/destructor family; this page remains a compatibility method/facet index, not a separate singleton owner or class emitter.
- IDA MCP decompilation on 2026-05-24 shows the `+0x0c` registry object is a generic `List`, so do not create a separate `ResourceLayoutStore` class from current evidence.

## 2026-06-30 Class/Facet Source-Disposition Audit

B011 rechecked constructor/destructor, vtable, method inventory, field, base, and child ownership routes before changing the generated disposition. No independent `ResourceLayoutTable` constructor, destructor, vtable, vtable data, global storage, or allocation route was found. All seven class-backed functions are non-virtual direct methods over the ImageLib singleton/facet pointer and use the same object `+0x0c` field that [UID:00006E][ImageLib](by-class/ImageLib.md) documents as `m_pEntryList`.

The exact executable children are now source-ready and carry method bodies: `LoadResourceIndex`, `LookupLayoutEntry`, `CopyEntryTileContext`, `GetEntryRect`, `GetFrameSize`, `GetEntryCount`, `FindResourceIndex`, and `LoadFrameDrawRecord`. The class page should not duplicate those bodies. It also should not emit a fake independent declaration with its own `m_pEntryList` field, because the object storage is constructed by ImageLib and no separate vtable/base/object evidence exists.

The accepted source shape is therefore one non-virtual ImageLib method family, one `ImageLib *g_pEPFLib` singleton, and `typedef ImageLib ResourceLayoutTable` as the compatibility spelling. Raw no-this helpers [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) remain outside this class method inventory and stay file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) concerns.

## Historical / Superseded Class-Boundary Assumptions

- Earlier active prose allowed `ResourceLayoutTable` to be an independent class, non-virtual base, embedded helper, or unresolved facet with its own pointer type. Those hypotheses predated UID00006E's complete formal ImageLib declaration and remain useful as reconstruction history only.
- No independent constructor, destructor, vtable, RTTI, allocation, storage object, or global exists. The accepted compatibility typedef preserves the recovered vocabulary without inventing those absent source artifacts.
- Original typedef/header spelling is still inferred rather than symbol-proven, so confidence remains below final audit. That lexical uncertainty does not reopen the rejected independent-object alternatives or justify blanking exact method children.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:000079][List](by-class/List.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)

## Score Rationale

- `COMPLETION:90`: live IDA research verifies exact method/helper boundaries, local padding, ImageLib owner lifecycle, row-list construction, lazy lookup behavior, accessor fields, corrected child ranges, the no-independent-object audit, source-bearing child route, and the shared UID0002P6 frame-record projection method.
- `CONFIDENCE:91`: active behavior, singleton ownership, child boundaries, lack of a separate vtable, systematic `g_pEPFLib` receiver setup across UID0002P6's 81-xref caller family, and direct UID0002FD lookup use support the compatibility method inventory. It remains below final-source certainty because exact original typedef/header and private-field spellings are inferred, not because an independent ResourceLayout object remains viable.
- `AUTOGEN_PARENT_UID:0000K2`: the parent attachment uses the current best source owner, `ImageLib`, whose file confidence is above the attachment threshold and whose constructor/destructor own `g_pEPFLib` and the 44-byte row `List`.

## Changes

## 2026-08-16 UID0000N5 Whole-File Callback

The complete facet now contains nine out-of-line `ImageLib.cpp` methods in source/address order: `LoadResourceIndex`, void `LookupLayoutEntry`, `CopyEntryTileContext`, void `GetEntryRect`, `LoadFrameDrawRecord`, `GetFrameSize`, `GetEntryCount`, public `FindResourceIndex`, and private [UID:00054V][0x004d1830-0x004d1860.ResourceLayoutTableGetEntry](by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md) `GetEntry`. The owner H additionally defines the public compiler-covered `const ResourceLayoutNameRecord *GetResourceLayout(int) const` accessor in class; its direct List-slot lowering has no standalone executable range and is not a tenth out-of-line definition.

`FindResourceIndex` is public because its 13 exact inbound calls divide into four facet-internal calls and nine external HumanImageLib/NewHumanImageLib/raw composition sites. The former private declaration is historical and cannot compile the observed external route without unsupported broad friendship. `GetEntry` remains private because it has zero inbound xrefs and exists only as a retained internal row accessor. Both use the private `List *m_pEntryList` at `+0x0c`; public row access returns a const pointer, while the private helper returns a selected mutable `ResourceLayoutEntry *`.

The class remains a compatibility facet over the one concrete `ImageLib` object and one `ImageLib *g_pEPFLib` lifecycle. No independent ResourceLayout constructor, destructor, allocation, vtable, RTTI, object storage, or global exists. The two no-`this` raw helpers remain owned by UID0000N5 `ResourceLayoutTable.cpp/.h`, not this class. Exact row declarations live once in UID00006E H: 24-byte `ResourceLayoutEntry` and 44-byte `ResourceLayoutNameRecord`; the latter's `entryCount@+0x20` and `entries@+0x28` are independently confirmed by the GFACE caller.

The score is now `94/94`: behavior, complete method inventory, source owner, public/private API split, compiler-covered accessor, row layouts, child routing, negative object/vtable evidence, and generated expectations are closed. Remaining uncertainty is lexical only: the compatibility typedef, `GetResourceLayout`, and private `GetEntry` spellings are reconstructed rather than symbol-proven.

- 2026-08-05 B006 UID0002FD compatibility-contract callback:
  - Preserved `90/91`, owner/emitter, no-independent-class marker, complete method/child inventory, object/list evidence, raw-helper exclusions, and all unrelated history.
  - Reconciled active uncertainty to UID00006E's accepted `ImageLib` class, `typedef ImageLib ResourceLayoutTable`, and sole `extern ImageLib *g_pEPFLib` contract; historical independent-class/base/facet alternatives now remain only as explicitly superseded evidence.
  - Added UID0002FD as a direct `CHATVAR.EPF` lookup consumer and restated that consumer use does not move API ownership into Chatting or authorize duplicate class/global source.
- 2026-07-22 B004 UID000438 accepted support callback:
  - Raised `89/88 -> 90/91`; owner/emitter and no-independent-class `[[CHILDREN]]` formal remain unchanged.
  - Added [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) `ResourceLayoutTable::LoadFrameDrawRecord` to the non-virtual facet inventory using systematic `g_pEPFLib` receiver proof from its 81-xref caller family.
  - Preserved the exclusion of raw no-this helpers UID0002KQ/UID0002KT and the caveat that the exact original ImageLib/ResourceLayoutTable declaration boundary remains inferred.

- 2026-06-30 B011 empty-emitter family implementation:
  - Changed score from `87/86` to `89/88` and inserted the formal no-class-body marker with `[[CHILDREN]]`.
  - Summary/evidence: B011's accepted audit found no independent constructor, destructor, vtable, base, storage, or allocation route for a standalone `ResourceLayoutTable` object. The exact method children now carry source bodies under this non-virtual ImageLib singleton/facet route, while raw helpers [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) remain file-level helper concerns.
- 2026-06-07 A008 alias cleanup:
  - Before: the class-purpose section used bare `DAT_0067a744` wording for the process-wide instance.
  - Changed to: canonical [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) wording with `DAT_0067a744` retained as the historical IDA alias.
  - Evidence: existing live IDA evidence on this page ties `0x0067a744` owner writes/clears to `ImageLib` while this method family consumes the singleton.
- 2026-06-07 A006 Batch 048 parent-gate refresh:
  - Changed completion/confidence from `86/84` to `87/86`.
  - Evidence: the split-recheck repaired five exact child filenames to IDA exclusive ends, reconfirmed the `ImageLib` singleton/list ownership chain, and found no separate `ResourceLayoutTable` vtable. With [UID:0000K2][ImageLib](by-file/ImageLib.md) now refreshed to `86/85`, this class/facet and its direct file parent satisfy the corrected `85/85` gate for exact children that also meet the child gate.
- 2026-06-08 A010 Batch120 raw-helper audit:
  - Changed to: no score change.
  - Evidence: documented why [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) remains unassigned despite reaching `85/88`: the helper is not a `thiscall` ResourceLayout method and no direct class owner is proven.
- 2026-06-08 A003 Batch132 raw-record helper audit:
  - Changed to: no score change.
  - Evidence: documented why [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) remains unassigned despite reaching `85/88`: the helper has no `this`, takes caller-provided raw record storage, and its known call evidence is human-image composition code rather than ResourceLayout class methods.
- 2026-06-10 B001-023 raw-helper routing:
  - Changed to: no score change.
  - Evidence: clarified that [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) remain excluded from this class method inventory, but now parent to file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) rather than staying unresolved.
- 2026-06-04: Raised completion/confidence from `82/76` to `86/84` and attached the reconstructable class/facet to [UID:0000K2][ImageLib](by-file/ImageLib.md) for autogen ownership. The increase is justified by fresh live IDA MCP verification of exact method boundaries, `0xcc` padding spans, ImageLib constructor/destructor ownership of `g_pEPFLib`, `List::List(44, 10)` registry construction at `+0x0c`, lazy-load decompilation for `LookupLayoutEntry`/accessors, and lack of a separate `ResourceLayoutTable` vtable.
- 2026-05-30: Changed completion/confidence from `0/0` to `82/76`.
  - Before: The page was unevaluated despite detailed documentation of lazy EPF/EPD lookup behavior, object shape, record layout, method roles, and ImageLib overlap caveats.
  - After: Scored as high completion with medium-high confidence because observed behavior is strong but the original class boundary and final field names remain partly unresolved.
  - Evidence: Existing object-shape notes, method notes, caveats, global/singleton evidence, and type/class/file cross-references support the score.
- 2026-05-31: Marked the class/facet documentation as reconstructable without adding C++.
  - Before: `RECONSTRUCTABLE` was blank even though IDA-confirmed methods and source-authored data structures require reconstruction.
  - After: set `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank because the final `ImageLib` versus `ResourceLayoutTable` source boundary is still unresolved.
  - Evidence: IDA MCP decompilation of the `0x004d0120-0x004d182f` method family confirms source-authored EPF/EPD layout-table behavior, but the same object is constructed by `ImageLib::ImageLib`.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000BY)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- ResourceLayoutTable is historical/documentation vocabulary for an ImageLib facet, not a second allocated object, vtable, or singleton. Existing lookup methods remain legal through the accepted typedef route.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-091 | 00006E | `g_pResourceMan` is rejected. Storage 0x0067a744 is ImageLib-owned `g_pEPFLib`; the strongest complete source route is `ImageLib` with `typedef ImageLib ResourceLayoutTable`, exact non-virtual lookup methods, and one `extern ImageLib *g_pEPFLib`. | Strong | ImageLib RTTI/lifecycle, sole global writes/clears, shared +0xc List, and ResourceLayout method family. | UID00006E complete formal; UID0000K2/UID0000BY/UID0000QU support; UID0002DL. | reject-invalid | implemented |
