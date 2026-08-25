*** UID:00006E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ImageLib.h"
#include "EPFTileContext.h"
#include "ImageFrameTable.h"
#include "../archive/DATFile.h"
#include "../ui/core/RectBounds.h"
#include "../util/List.h"
#include "../util/MemoryMan.h"
#include <wchar.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_IMAGELIB_H
#define NEXUSTK_RENDER_IMAGELIB_H

#include "../util/LObject.h"
#include "../util/List.h"

struct ArchiveMetadataTable;
struct EPFTileContext;
struct FrameDrawRecord;
struct RectBounds;

struct ResourceLayoutEntry
{
    int left;
    int top;
    int right;
    int bottom;
    unsigned char *pixelData;
    unsigned char *encodedMaskData;
};

struct ResourceLayoutNameRecord
{
    wchar_t name[16];
    unsigned short entryCount;
    unsigned short frameWidth;
    unsigned short frameHeight;
    unsigned short reservedHeaderWord;
    ResourceLayoutEntry *entries;
};

class ImageLib : public LObject
{
public:
    ImageLib(int cacheLimit, int);
    virtual ~ImageLib();
    int LoadResourceIndex(const wchar_t *resourceName);
    int FindResourceIndex(const wchar_t *resourceName);
    const ResourceLayoutNameRecord *GetResourceLayout(
        int resourceIndex) const
    {
        return static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    }
    void LookupLayoutEntry(
        const wchar_t *resourceName, int frameIndex,
        EPFTileContext *outContext);
    void CopyEntryTileContext(
        const wchar_t *resourceName, int frameIndex,
        EPFTileContext *destination);
    void GetEntryRect(
        const wchar_t *resourceName, int frameIndex,
        RectBounds *bounds);
    void LoadFrameDrawRecord(
        const ArchiveMetadataTable *table, int frameIndex,
        FrameDrawRecord *outRecord);
    void GetFrameSize(
        const wchar_t *resourceName,
        unsigned short *width, unsigned short *height);
    unsigned short GetEntryCount(const wchar_t *resourceName);

private:
    ResourceLayoutEntry *GetEntry(int resourceIndex, int frameIndex);
    int m_refCount;
    int m_cacheLimit;
    List *m_pEntryList;
    int m_maxCacheSize;
};

typedef ImageLib ResourceLayoutTable;
extern ImageLib *g_pEPFLib;
typedef char ImageLibSizeMustBe20[
    sizeof(ImageLib) == 0x14 ? 1 : -1];
typedef char ResourceLayoutEntrySizeMustBe24[
    sizeof(ResourceLayoutEntry) == 0x18 ? 1 : -1];
typedef char ResourceLayoutNameRecordSizeMustBe44[
    sizeof(ResourceLayoutNameRecord) == 0x2c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ImageLib

## Status

- Confidence: very strong for constructor/destructor, vtable ownership, singleton storage, exact field layout, complete nine-method ResourceLayout facet, public/private API split, row declarations, and compiler-covered accessor. Exact private/accessor spellings remain inferred.
- Likely source file: [UID:0000K2][ImageLib](by-file/ImageLib.md)
- Address ranges: [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md) plus exact scalar deleting destructor [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- Confirmed type anchors: [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- Exact vtable data: [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md)

## Class Purpose

`ImageLib` is the EPF image-library manager singleton installed as [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md). It owns a list-based cache of image/layout entries and releases cached payloads during destruction.

## Observed Layout

```text
ImageLib
  +0x00  LObject base
  +0x04  int m_refCount (inferred name)
  +0x08  int m_cacheLimit (inferred name)
  +0x0c  List* m_pEntryList
  +0x10  int m_maxCacheSize (inferred name)
```

`ResourceLayoutTable` method-local overlays name the `+0x0c` field as `recordStore`; `ImageLib` constructor names the same field as `m_pEntryList`. Treat these as the same storage until proven otherwise.

2026-05-24 IDA MCP follow-up resolved the storage type: `ImageLib::ImageLib` allocates a 20-byte [UID:000079][List](by-class/List.md), calls `List::List(44, 10)`, and stores it at `+0x0c`. The list elements are [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows.

The constructor signature in older generated data is incomplete. The application call site at `0x004644e8` pushes `0x4e20` (`20000`) first and `0x0f4240` (`1000000`) second before calling `0x004cffb0`; IDA confirms the constructor cleans two stack arguments with `retn 8`. Because x86 stack arguments are consumed in reverse push order, callee `[ebp+8]` receives `1000000` and is stored at `+0x08` / inferred `m_cacheLimit`. Callee `[ebp+0x0c]` receives `20000` and is unused in the recovered constructor body, so the constructor source keeps the ABI as `ImageLib::ImageLib(int cacheLimit, int)` with an unnamed second `int`.

The exact original private member spellings remain inferred for `m_refCount`, `m_cacheLimit`, and `m_maxCacheSize`. `m_pEntryList` is stronger than a provisional name because B006's executed destructor implementation and the ResourceLayout consumer checks both use the same `+0x0c` generic `List*` registry.

See [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) for the rebuild-oriented field ledger.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ImageLib::ImageLib` | [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) | Initializes the singleton, assigns `g_pEPFLib = this`, stores `cacheLimit` in inferred `m_cacheLimit`, clears inferred `m_refCount`, initializes inferred `m_maxCacheSize`, and allocates the 44-byte-row `m_pEntryList`. Formal first-draft source is `ImageLib::ImageLib(int cacheLimit, int)`. |
| `ImageLib::~ImageLib` | [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) | Source-authored ordinary destructor body; releases `ResourceLayoutNameRecord::entries` payloads, deletes `m_pEntryList`, clears `g_pEPFLib`, and owns first-draft destructor C++. |
| `ImageLib::ScalarDeletingDestructor` | [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) | Compiler scalar deleting wrapper route; repeats the cleanup sequence and adds optional delete-flag/guard handling. It now carries only a formal marker comment, while source C++ remains on the ordinary destructor child. |

## Ownership Notes

The recovered [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) methods are non-virtual methods on this concrete class, with `typedef ImageLib ResourceLayoutTable` preserving compatibility vocabulary. Constructor, layout, singleton, field-use, vtable and negative lifecycle evidence reject a second class/base/helper object.

IDA vtable evidence shows only three `ImageLib` virtual slots at `0x0061b654`, followed immediately by `MapTileImageLib` RTTI. This means the `ResourceLayoutTable` lookup family is not virtual on `ImageLib`; it is either non-virtual `ImageLib` API, a helper/base slice, or a recovered type-alias artifact.

IDA MCP xrefs to `0x0067a744` on 2026-05-24 confirm the global storage is written by this constructor/destructor family while `ResourceLayoutTable` methods consume it. Treat [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) as generated/provisional aliases over the [UID:000079][List](by-class/List.md)-backed [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) model until the exact header split is proved.

## 2026-06-08 Vtable Gate Recheck

Batch 139 added the exact [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md) child for the compiler-emitted RTTI/vtable dwords. That child confirms `0x0061b650 -> ??_R4ImageLib@@6B@`, `0x0061b654 -> 0x004e64a0`, `0x0061b658 -> 0x004f4b10`, `0x0061b65c -> nullsub_18`, xrefs from constructor/destructor/scalar-deleting-destructor code, and the `MapTileImageLib` boundary at `0x0061b660`.

This class is the direct source owner for [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md). The vtable confirms that ResourceLayout APIs are non-virtual; the complete split is resolved by the one ImageLib layout/lifecycle and direct `+0x0c` List use, not by adding virtual slots or an independent object.

## Autogen Status

Attach this class to [UID:0000K2][ImageLib](by-file/ImageLib.md) as the complete `render/ImageLib.cpp/.h` owner. CPP supplies all required includes and `[[CHILDREN]]`; exact child pages supply lifecycle and nine out-of-line methods. H supplies both exact row declarations before class use, public `FindResourceIndex`, the in-class compiler-covered `GetResourceLayout`, corrected void APIs, private `GetEntry` and storage, compatibility typedef, singleton extern and size guards.

## 2026-06-30 Class-Level Source-Disposition Audit

B011 checked every class-declaration route before applying the marker. The constructor route is already source-ready and proves `LObject` construction, singleton assignment, vtable install, inferred `m_refCount`, inferred `m_cacheLimit`, strongly supported `m_pEntryList`, and inferred `m_maxCacheSize`. The destructor route is already source-ready and proves `m_pEntryList` cleanup, `ResourceLayoutNameRecord::entries` payload release, list deletion, and `g_pEPFLib` clear. The scalar deleting destructor route is compiler-generated wrapper evidence only, with the vtable slot pointing at `0x004e64a0`.

The vtable audit remains narrow: `0x0061b654 -> 0x004e64a0`, `0x0061b658 -> 0x004f4b10`, and `0x0061b65c -> 0x0041b6c0`, with `MapTileImageLib` beginning at `0x0061b660`. No ResourceLayout API appears as a virtual slot. The field audit remains `+0x00` vtable/base, `+0x04 m_refCount`, `+0x08 m_cacheLimit`, `+0x0c m_pEntryList`, and `+0x10 m_maxCacheSize`.

The former blank/deferred class-shell concern is resolved by the complete ImageLib declaration above. It exposes the observed non-virtual ResourceLayout surface without asserting a second base/facet object. A separate `ResourceLayoutTable` class remains unsupported; the compatibility typedef preserves the vocabulary without changing object layout.

## 2026-06-27 Destructor Source Split

B006 MCP session `80de0a67` confirms the ordinary destructor at `0x004d0070-0x004d011b` as the source-authored cleanup body: it uses the `+0x0c` list field as `m_pEntryList`, snapshots the list count, calls the list `GetElementAt` slot for each 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md), frees non-null `entries` at row `+0x28`, deletes the list, clears `m_pEntryList`, and clears [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md). The vtable slot at `0x0061b654` still points to [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md), so the scalar wrapper remains compiler glue and should not replace or absorb the ordinary destructor's source body. B005's accepted implementation records [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) as source-declared/generated-binary scalar deleting destructor glue with a formal marker comment only; the marker accounts for the routed emitter without hand-writing compiler ABI code.

## 2026-06-27 Constructor Source Shape

B001 MCP/database evidence for [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) resolves the constructor source shape enough for formal C++. The sole caller pushes `0x4e20` then `0x0f4240`, so callee `[ebp+8]` is `1000000` and initializes inferred `m_cacheLimit`; callee `[ebp+0x0c]` is `20000` and is unused. The constructor source keeps the binary ABI as an unnamed second `int`, clears inferred `m_refCount`, initializes inferred `m_maxCacheSize` to `1000000`, and allocates `m_pEntryList` with `new List(sizeof(ResourceLayoutNameRecord), 10)`.

ResourceLayout methods checked by B001 (`0x004d0120`, `0x004d02f0`, `0x004d0530`, `0x004d1730`, `0x004d1780`, and `0x004d17c0`) consume object `+0x0c` as the layout-entry list and do not read ImageLib object fields `+0x04`, `+0x08`, or `+0x10`. That narrows the class/header caveat: `ResourceLayoutTable` remains a likely non-virtual API/facet or recovered alias over the ImageLib singleton, but it no longer blocks emitting this constructor body.

## Cross-References

- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

## 2026-08-16 UID0000N5 Complete Class And Header Contract

The complete non-virtual ResourceLayout surface is nine out-of-line methods: loader, void entry lookup, tile-context copy, void bounds lookup, frame-record projection, frame-size and count accessors, public one-lookup name finder, and private UID00054V `GetEntry`. The H-only `GetResourceLayout` accessor is separately counted because the GFACE caller lowers it directly to `m_pEntryList->GetElementAt(resourceIndex)`; no out-of-line accessor body or binary UID exists.

`FindResourceIndex` is public. Its 13 inbound calls divide into four facet-internal calls and nine external Human/NewHuman/raw composition sites, which rejects the old private declaration and broad speculative friendship. `GetEntry` remains private and zero-xref. `m_pEntryList` remains private at `+0x0c`; UID000079 `List.h` is included directly because the inline accessor invokes its complete virtual API.

The exact 24-byte `ResourceLayoutEntry` and 44-byte `ResourceLayoutNameRecord` declarations now precede class use. The GFACE branch independently confirms `entryCount@+0x20` and `entries@+0x28`; the undefined `ResourceLayoutRecord` convenience type and late CPP duplicates are rejected. Size guards preserve object and row widths.

Score `92/93` reflects complete class/API/header/compiler-lowering closure. Existing lifecycle, vtable, constructor/destructor and field history is preserved; prior blank-shell/private-Find/incomplete-row statements are historical pre-callback states.

- 2026-08-12 B003 UID0000L2 physical header channel repair:
  - Moved the complete accepted `ImageLib` declaration from the CPP channel into guarded `NEXUSTK_RENDER_IMAGELIB_H`; CPP now includes `ImageLib.h` and composes `[[CHILDREN]]`.
  - Preserved every forward declaration, API signature, private field, `ResourceLayoutTable` alias, `g_pEPFLib` extern, `0x14` size guard, and child output including `g_imageLibraryLoadError`.
  - This is a visibility/source-factoring correction required by `MapNamePane::OnPaint()` and other `LookupLayoutEntry` consumers. It does not resolve or erase the documented private-name/facet uncertainty and changes no score, owner, emitter, position, or behavior.

- 2026-06-30 B011 empty-emitter family implementation:
  - Changed score from `86/86` to `87/88` and inserted the formal no-class-body marker with `[[CHILDREN]]`.
  - Summary/evidence: B011's accepted class audit checked constructor/destructor/scalar-wrapper routes, vtable slots, fields, base class, ResourceLayout child ownership, and declaration-shell safety. The class remains reconstructable and emits through [UID:0000K2][ImageLib](by-file/ImageLib.md), but a standalone class declaration is excluded because it would either omit the ResourceLayoutTable non-virtual API surface or invent an unsupported base/facet declaration.
- 2026-06-27 B005 scalar-wrapper marker implementation: no score change. Updated the method/disposition notes for [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) to say the wrapper now carries only a formal marker comment while [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) remains the source-authored `ImageLib::~ImageLib()` body.
- 2026-06-27 B006 destructor source-quality implementation:
  - What existed before: the method notes treated `ImageLib::~ImageLib` as lower/prewave cleanup and class Autogen Status still implied class-level C++ was blank because destructor/deleting-destructor source shape was unresolved.
  - Changed to: [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) owns first-draft destructor C++, while this class page stays blank only for broader constructor/API/header/private-field questions.
  - Summary/evidence: MCP session `80de0a67` proved the `m_pEntryList` cleanup loop, `ResourceLayoutNameRecord::entries` free, list delete/null, `g_pEPFLib` clear, no pointer route to `0x004d0070`, and scalar-wrapper vtable route to [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md). Scores remain unchanged because class-level constructor/API/header factoring is still outside this exact child implementation.
- 2026-06-27 B001 constructor source-quality implementation:
  - What existed before: the observed layout still used provisional constructor/private-field wording and treated the unused second constructor argument plus `ResourceLayoutTable` split as constructor C++ blockers.
  - Changed to: constructor child [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) owns first-draft `ImageLib::ImageLib(int cacheLimit, int)` C++; the class layout records inferred `m_refCount`, `m_cacheLimit`, strongly supported `m_pEntryList`, and inferred `m_maxCacheSize`.
  - Summary/evidence: B001 live MCP database `80de0a67` corrected the call-site push/callee-stack mapping, proved the unused second callee argument disposition, checked ResourceLayout consumers for object-field reads, and used B006's executed destructor evidence for `m_pEntryList`. Scores remain unchanged because this class-level page still has broader declaration/header/facet questions outside the constructor child.
- 2026-06-08 A007 Batch 139 vtable-parent gate update:
  - What existed before: class scores were `82/82`, below the strict direct-parent gate for [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md).
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, an exact vtable-data child link, and a vtable gate recheck section.
  - Summary/evidence: [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md) records the RTTI/vtable dwords, slot target sizes, vptr-store xrefs, and `MapTileImageLib` boundary. Scores remain below `95` because the `ResourceLayoutTable` helper/API relationship and final private source names remain unresolved.
- Completion/confidence score update: existed before as `0/0`; changed to `80/78`. Summary: EPF image-library singleton role, observed layout, constructor/destructor signatures, list-backed resource records, vtable evidence, global storage, and ResourceLayoutTable ownership caveats are documented; confidence remains limited by full method-membership and helper/base split questions. Evidence: `ImageLib`, `ImageLibDestructor`, `ImageLibLayout`, `ImageLibVtable`, `g_pEPFLib`, `ResourceLayoutNameRecord`, and ResourceLayout alias/type pages.
- 2026-05-31 range correction and reconstructable update:
  - What existed before: class used old child bounds, lacked exact constructor/scalar-deleting destructor page references, and `RECONSTRUCTABLE:` was blank.
  - Changed to: `RECONSTRUCTABLE:TRUE`, `COMPLETION:82`, `CONFIDENCE:82`, exact child references for constructor/destructor/scalar-deleting destructor, and corrected aggregate range `0x004cffb0-0x004e6572`.
  - Summary/evidence: IDA MCP confirmed function bounds, constructor/deleting-destructor behavior, vtable xrefs, and singleton writes/clears on 2026-05-31. Scores stay below final level because `ResourceLayoutTable` membership and final source-facing private names remain open.
- 2026-06-02 parent attachment:
  - What existed before: class metadata was reconstructable but had no autogen parent.
  - Changed to: attached to [UID:0000K2][ImageLib](by-file/ImageLib.md), leaving C++ blank.
  - Summary/evidence: class and file scores are both above the 80 confidence attachment threshold and agree on `render/ImageLib.cpp` ownership while documenting unresolved source-shape caveats.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: class range summary now points at the non-emitting local lifecycle cluster and exact scalar deleting destructor, not the old broad crossing aggregate.
  - Evidence: live IDA `entity_query` showed the broad `0x004cffb0-0x004e6572` aggregate crossed sibling image-library owners.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (00006E)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The complete ImageLib declaration and typedef ImageLib ResourceLayoutTable facet are installed. The sole typed global is g_pEPFLib; no independent ResourceLayout object or g_pResourceMan source global is introduced.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-091 | 00006E | `g_pResourceMan` is rejected. Storage 0x0067a744 is ImageLib-owned `g_pEPFLib`; the strongest complete source route is `ImageLib` with `typedef ImageLib ResourceLayoutTable`, exact non-virtual lookup methods, and one `extern ImageLib *g_pEPFLib`. | Strong | ImageLib RTTI/lifecycle, sole global writes/clears, shared +0xc List, and ResourceLayout method family. | UID00006E complete formal; UID0000K2/UID0000BY/UID0000QU support; UID0002DL. | reject-invalid | implemented |
