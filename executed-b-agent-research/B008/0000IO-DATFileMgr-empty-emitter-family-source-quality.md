** TARGET-REPORT-UID:0000IO **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000IO DATFileMgr Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Target: [UID:0000IO] `by-file/DATFileMgr.md`.
- Assignment: `B008-report-0000IO-DATFileMgr-empty-emitter-family-20260701`.
- Mode: report-only research. No by-* docs, generated files, coverage/project-level files, validator/tool state, supervisor ledgers, archives, or IDA DB were edited.
- Current generated output: `auto-generated/NexusTK/archive/DATFileMgr.cpp`, header `validator-command-id: 000000003756`, refreshed `2026-07-01T07:16:39-04:00`.
- Current generated tracker row: `26` total emitters, `16` filled, `10` empty, `61.5%` filled, report count `0`.
- Recommendation: keep [UID:0000IO] as the `NexusTK/archive/DATFileMgr.cpp` file root and apply a callback that resolves all ten empty markers with declaration-level C++, no-duplicate comments, or non-emitting duplicate/index reclassification. Do not create new child pages.
- Confidence: high for the source-family route and all ten empty-marker dispositions after live MCP recheck; capped below final audit because exact original private helper spelling remains inferred.

## Target

- Target UID: [UID:0000IO].
- Target path: `by-file/DATFileMgr.md`.
- Current metadata: `COMPLETION:89`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`.
- Generated source root: `auto-generated/NexusTK/archive/DATFileMgr.cpp`.
- Current empty markers:
  - [UID:00003H] `by-class/DATFileContainer.md`
  - [UID:00003I] `by-class/DATFileMgr.md`
  - [UID:0002MA] `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`
  - [UID:00003J] `by-class/DATFileResolver.md`
  - [UID:0002MB] `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`
  - [UID:0000T0] `by-global/HasDATEntry_49C700.md`
  - [UID:0000QQ] `by-global/g_pDATFileMgr.md`
  - [UID:0001P6] `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`
  - [UID:0000UT] `by-item/HasDATEntry_0049C700.md`
  - [UID:0001XB] `by-type/by-vtable/DATManagerVtables.md`

## Current Target State

[UID:0000IO] already owns the correct source root for the DAT archive manager family. Current docs and generated output show that the method-body work has mostly moved to exact by-memory child emitters:

- Public wrapper methods: [UID:000227] `DATFileMgr::FindEntryByName`, [UID:000439] constructor, [UID:00043A] destructor, and [UID:00012C] `LoadDATFile`.
- Container methods: [UID:00043B] constructor and [UID:00043C] destructor.
- Internal manager methods/helpers: [UID:00012F], [UID:00043D], [UID:00043E], [UID:00043F], and [UID:00043H].
- Resolver methods: [UID:00043G], [UID:00012H], and [UID:00043I].
- Free helper: [UID:00012E] `HasDATEntry`.

The remaining empty markers are not missing method bodies. They are class declaration pages, source-declared/generated-binary vtable data pages, duplicate symbol/index pages, one singleton global declaration, its exact storage child, and a broad vtable inventory.

## Evidence Checked

Live IDA MCP evidence, session `supervisor_resume_20260629`:

- `initialize` and `tools/list` succeeded; server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list`: active owned/adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing=false`.
- `server_health`: `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.
- `lookup_funcs` on DAT manager family addresses reconfirmed modeled functions at `0x0049bd30`, `0x0049be70`, `0x0049be80`, `0x0049c700`, `0x0049c800`, `0x0049cad0`, `0x0049cbb0`, `0x0049ce50`, `0x0049d190`, `0x0049d2d0`, `0x0049d350`, `0x0049d3d0`, `0x0049d490`, and `0x0049d5e0`; raw starts `0x0049bd20`, `0x0049be50`, `0x0049c0d0`, and `0x0049c750` still report `Not a function`.
- `get_bytes`: `0x00618910` bytes decode as `0x0064645c, 0x0049d350, 0x00646414, 0x0049d2d0`; `0x006189c8` bytes decode as `0x006463cc, 0x0049d3d0`, then UTF-16 `"../"` bytes; `0x0067ab40` is `00 00 00 00`; `0x0049d6e8` shows `ret 8` tail followed by three `0xcc` bytes and the next prologue.
- `get_global_value 0x0067ab40`: `0x0`.
- `xrefs_to`: `0x00618914` has three vtable-store/data refs; `0x006189cc` has three vtable-store/data refs; `0x0067ab40` has 24 refs; `0x0049c700` has 17 direct code callers; scalar deleting destructor targets have one data xref each from their vtable slot.
- `decompile 0x0049c700`: `sub_49CAD0(*(_DWORD **)(unk_67AB40 + 4), String, 0) != 0`.
- `decompile 0x0049bd30`: public wrapper constructor stores `g_pDATFileMgr`, installs `DATFileMgr` and `_DATFileMgr` vtables, allocates `0x30` bytes for `_DATFileMgr`, initializes resolver state, and stores the inner pointer at public wrapper offset `+0x04`.
- `decompile 0x0049be80`: `DATFileContainer` constructor installs vtable, initializes handle/view/table fields, opens the passed path with `"../"` fallback, maps the file, reads entry count/table pointer, and reads the final boundary row offset.

Current by-* docs checked:

- `by-file/DATFileMgr.md`
- `by-class/DATFileContainer.md`
- `by-class/DATFileMgr.md`
- `by-class/DATFileResolver.md`
- `by-class/_DATFileMgr.md`
- `by-global/HasDATEntry_49C700.md`
- `by-item/HasDATEntry_0049C700.md`
- `by-global/g_pDATFileMgr.md`
- `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`
- `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`
- `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`
- `by-type/by-vtable/DATManagerVtables.md`
- `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md`
- `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`

Generated/tracker evidence checked:

- `auto-generated/NexusTK/archive/DATFileMgr.cpp`
- `auto-generated/-ag-research-tracker.md` row for [UID:0000IO].

Old/executed report search terms:

- `TARGET-REPORT-UID:0000IO`, `DATFileMgr-empty-emitter-family`, `DATFileMgr`, `DATFileContainer`, `DATFileResolver`, `HasDATEntry`, `DATManagerVtables`, `g_pDATFileMgr`, `_DATFileMgrRawDestructor`, and `DATManagers`.

Relevant executed reports opened as support evidence:

- `executed-b-agent-research/B002/00012B-DATManagers-source-quality.md`
- `executed-b-agent-research/B015/000004-_DATFileMgr-class-source-quality.md`
- `executed-b-agent-research/B001/000227-DATFileMgrFindEntryForwarder-source-quality.md`
- `executed-b-agent-research/B005/00012H-DATFileResolverDestroy-source-quality.md` was identified as incorporated support evidence through current docs.

No exact active or executed report for `TARGET-REPORT-UID:0000IO` / `DATFileMgr-empty-emitter-family` was found.

## Positive Evidence Summary

- The file root is current and correct: [UID:0000IO] maps to `NexusTK/archive/DATFileMgr.cpp`, and generated output already contains the filled method bodies listed above.
- Current MCP confirms all important binary anchors used by the docs: public/private manager vtables, singleton storage, public constructor behavior, container constructor behavior, `HasDATEntry` body, vtable xrefs, and singleton xrefs.
- The ten empty emitters have narrow causes:
  - class pages need declaration-level C++ and `[[CHILDREN]]`;
  - exact vtable data pages need no-hand-authored-array comments;
  - `HasDATEntry` alias pages duplicate the exact [UID:00012E] source body;
  - `g_pDATFileMgr` needs one global definition while its exact storage child needs a no-duplicate comment;
  - the broad vtable inventory is an evidence/index page, not a source emitter.

## Negative Evidence Summary

- Do not split the source root to standalone `_DATFileMgr.cpp`, `DATFileContainer.cpp`, or `DATFileResolver.cpp`; current docs and MCP confirm a single archive manager source family.
- Do not move `DATFile` methods, `SimpleUStringVector` helpers, wide-string thunks, `File` destructor code, or application cleanup helper `DestroyDATFileMgr` into `DATFileMgr.cpp`; those are consumer or neighboring owners.
- Do not hand-author vtable byte arrays or scalar deleting destructor wrappers; the compiler should regenerate them from class declarations and virtual destructors.
- Do not duplicate `HasDATEntry` source C++ on [UID:0000T0] or [UID:0000UT]; [UID:00012E] already emits the formal function body.
- Do not duplicate the `g_pDATFileMgr` pointer definition on [UID:0001P6]; the global page should emit the source definition and the storage page should document exact address evidence.

## Heuristic / Inference Reanalysis And Validation

### Public / Private Manager Source Shape

The public class `DATFileMgr` is an 8-byte wrapper: vptr at `+0x00`, `_DATFileMgr *m_impl` at `+0x04`. Live MCP decompilation of `0x0049bd30` confirms `g_pDATFileMgr` receives the public wrapper pointer, not the inner implementation object. Public method children load `m_impl` and forward into `_DATFileMgr`.

The internal class `_DATFileMgr` is already declaration-ready on [UID:000004]. This report does not change that class, but [UID:00003I] should receive a matching public wrapper declaration so the public vtable marker is no longer empty.

### DATFileContainer Class Shape

`DATFileContainer` is source-level class data, not just a function bucket. Its fields are strongly documented by constructor/destructor children and MCP:

- `HANDLE m_fileHandle`
- `HANDLE m_mappingHandle`
- `void *m_mappedView`
- `unsigned int m_finalPayloadOffset`
- `unsigned int m_entryCount`
- `DATEntryRecord *m_entries`

The class page should emit only this declaration and child insertion. Constructor/destructor bodies stay on [UID:00043B] and [UID:00043C].

### DATFileResolver Class Shape

`DATFileResolver` is a source-level internal helper/member type embedded in `_DATFileMgr`, not a standalone source file. Its class page should emit a declaration with the resolver field names already accepted by current docs, plus `[[CHILDREN]]` for exact resolver member bodies. This removes the empty marker without moving resolver method bodies onto the class page.

### HasDATEntry Duplicate Pages

[UID:00012E] already has the formal body:

```cpp
bool HasDATEntry(const wchar_t *entryName)
{
    return g_pDATFileMgr != 0 && g_pDATFileMgr->FindEntryByName(entryName, 0);
}
```

[UID:0000T0] and [UID:0000UT] are useful symbol/index pages but should no longer be reconstructable emitters. Keeping them as emitters would either duplicate [UID:00012E] or require a meaningless no-op source item. The callback should make both non-emitting duplicate/index pages with explicit prose proof and blank formal C++.

### Vtable Data Handling

The two exact by-memory vtable data pages are source-declared/generated-binary data. The best callback repair is to keep their class ownership and add formal no-array comments that document they are compiler-emitted from the class declarations and virtual destructor shape. The broad [UID:0001XB] vtable inventory covers both exact records and should become a non-emitting evidence/index page; it should not output an extra broad vtable block.

### Singleton Storage

Live MCP reads `00 00 00 00` and `get_global_value=0x0` at `0x0067ab40`. Source should emit one definition:

```cpp
DATFileMgr *g_pDATFileMgr = 0;
```

The exact storage child should emit only a no-duplicate comment when routed through [UID:0000QQ].

## Ranked Ownership Analysis

### 1. [UID:0000IO] `DATFileMgr.cpp` Source File

- Evidence for: current file root, class/global docs, generated output, live MCP function/data anchors, accepted B002/B015/B001 reports, and current method child emitters all converge on `NexusTK/archive/DATFileMgr.cpp`.
- Evidence against: none for the ten current empty markers; only exact child pages or non-emitting index pages need cleanup.
- Decision: retain [UID:0000IO] as file root and use it as final generated source route for class declarations, singleton definition, and relevant exact children.

### 2. Class Owners For Class/Vtable Children

- Evidence for: [UID:00003H], [UID:00003I], [UID:00003J], [UID:000004], [UID:0002MA], and [UID:0002MB] are class/type/vtable artifacts whose semantic owners are the corresponding classes.
- Evidence against direct file ownership for vtable data: vtables are generated from class declarations, not source-file byte arrays.
- Decision: class pages emit declarations; exact vtable data pages should be formal comments under their class route; no hand-authored arrays.

### 3. Exact [UID:00012E] `HasDATEntry` Body

- Evidence for: exact by-memory page owns the source function range and already emits accepted formal C++.
- Evidence against duplicate global/by-item emitters: [UID:0000T0] and [UID:0000UT] have no separate range or source object beyond the same function.
- Decision: make [UID:0000T0] and [UID:0000UT] non-emitting duplicate/index pages linked to [UID:00012E].

## Source Placement

- Recommended placement remains `NexusTK/archive/DATFileMgr.cpp`.
- Source declarations and bodies in this family should read as one source module containing:
  - public `DATFileMgr`;
  - private `_DATFileMgr`;
  - `DATFileContainer`;
  - internal `DATFileResolver`;
  - `g_pDATFileMgr`;
  - file-scope helper `HasDATEntry`;
  - file-local node/hash/vector support helpers already represented by exact children.
- Rejected placements:
  - `DATArchive.cpp`: subsystem umbrella, not direct source owner.
  - standalone `DATFileResolver.cpp`: all resolver evidence is embedded/member use.
  - standalone `_DATFileMgr.cpp`: Wave3 staging artifact.
  - consumer modules for `HasDATEntry`: callers are consumers only.

## Function / Child Inventory

| UID / item | Current state | Recommended disposition |
| --- | --- | --- |
| `00003H` `by-class/DATFileContainer.md` | `85/87`, reconstructable, emitter [UID:0000IO], blank formal C++ | Raise to `88/90`; insert class declaration plus `[[CHILDREN]]`. |
| `00003I` `by-class/DATFileMgr.md` | `86/86`, reconstructable, emitter [UID:0000IO], blank formal C++ | Raise to `88/90`; insert public wrapper class declaration plus `[[CHILDREN]]`. |
| `0002MA` exact public vtable data | `86/93`, owner/emitter [UID:00003I], blank formal C++ | Keep metadata; insert no-hand-authored-vtable comment. |
| `00003J` `by-class/DATFileResolver.md` | `86/89`, reconstructable, emitter [UID:0000IO], blank formal C++ | Raise to `88/91`; insert internal resolver declaration plus `[[CHILDREN]]`. |
| `0002MB` exact internal vtable data | `86/93`, owner/emitter [UID:000004], blank formal C++ | Keep metadata; insert no-hand-authored-vtable comment. |
| `0000T0` `by-global/HasDATEntry_49C700.md` | `86/91`, duplicate emitter, blank formal C++ | Reclassify non-emitting duplicate symbol page: owner [UID:00012E], `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. |
| `0000QQ` `by-global/g_pDATFileMgr.md` | `86/88`, reconstructable, emitter [UID:0000IO], blank formal C++ | Raise to `88/91`; insert `DATFileMgr *g_pDATFileMgr = 0;` plus `[[CHILDREN]]`. |
| `0001P6` exact singleton storage | `86/90`, owner/emitter [UID:0000QQ], blank formal C++ | Keep or raise to `88/91`; insert no-duplicate storage comment. |
| `0000UT` `by-item/HasDATEntry_0049C700.md` | `86/91`, duplicate emitter, blank formal C++ | Reclassify non-emitting duplicate/index page: owner [UID:00012E], `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. |
| `0001XB` `by-type/by-vtable/DATManagerVtables.md` | `86/91`, broad vtable inventory emitter, blank formal C++ | Reclassify non-emitting evidence/index page, because exact vtable children and class declarations carry generated-binary proof. |

## First-Draft C++ / Formal No-Code Recommendation

### [UID:00003H] `by-class/DATFileContainer.md`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
struct DATEntryRecord;

class DATFileContainer {
public:
    DATFileContainer(const wchar_t *path);
    virtual ~DATFileContainer();

private:
    HANDLE m_fileHandle;
    HANDLE m_mappingHandle;
    void *m_mappedView;
    unsigned int m_finalPayloadOffset;
    unsigned int m_entryCount;
    DATEntryRecord *m_entries;
};

[[CHILDREN]]
```

Reason: class declaration is source-authored; exact constructor/destructor bodies already emit from children.

### [UID:00003I] `by-class/DATFileMgr.md`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
class _DATFileMgr;
struct DATEntryLocation;

class DATFileMgr {
public:
    DATFileMgr();
    virtual ~DATFileMgr();

    bool LoadDATFile(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation);

private:
    _DATFileMgr *m_impl;
};

[[CHILDREN]]
```

Reason: live MCP and child docs confirm public wrapper `m_impl` at `+0x04` and the two public forwarding methods. Exact method bodies remain on by-memory children.

### [UID:0002MA] `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`

Recommended metadata: keep `86/93`, `CANONICAL_OWNER:00003I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003I`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
// The DATFileMgr RTTI pointer and one-slot vtable at 0x00618910-0x00618918
// are compiler-emitted from the DATFileMgr class declaration and virtual
// destructor. Do not hand-author this record as a source array.
```

Reason: exact data is source-declared/generated-binary, not handwritten table source.

### [UID:00003J] `by-class/DATFileResolver.md`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
class SimpleUString;
struct DATBucketRecord;
struct DATEntryNode;
struct DATFileResolverResult;

class DATFileResolver {
public:
    ~DATFileResolver();

    DATFileResolverResult InsertOrFindEntry(DATEntryNode *node);
    DATEntryNode *FindNodeByKey(const SimpleUString& entryName) const;

private:
    float m_maxLoadFactor;
    DATEntryNode *m_entryListSentinel;
    unsigned int m_entryCount;
    DATBucketRecord *m_bucketsBegin;
    DATBucketRecord *m_bucketsEnd;
    DATBucketRecord *m_bucketsCapacity;
    unsigned int m_bucketMask;
    unsigned int m_bucketCount;
};

[[CHILDREN]]
```

Reason: source-level internal helper/member type is now documented strongly enough for a declaration. Exact resolver bodies remain on by-memory children.

### [UID:0002MB] `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`

Recommended metadata: keep `86/93`, `CANONICAL_OWNER:000004`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000004`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
// The _DATFileMgr RTTI pointer and one-slot vtable at 0x006189c8-0x006189d0
// are compiler-emitted from the _DATFileMgr class declaration and virtual
// destructor. Do not hand-author this record as a source array.
```

Reason: exact data is source-declared/generated-binary; `0x006189d0` is UTF-16 `"../"` data, not a slot.

### [UID:0000T0] `by-global/HasDATEntry_49C700.md`

Recommended metadata: keep score `86/91`, set `CANONICAL_OWNER:00012E`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.

Formal C++ disposition: keep the formal block blank after metadata reclassification. Add prose proof that [UID:00012E] is the only source-bearing `HasDATEntry` emitter and already contains the exact body. This page remains a symbol/global index and must not duplicate the body.

### [UID:0000QQ] `by-global/g_pDATFileMgr.md`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
DATFileMgr *g_pDATFileMgr = 0;
[[CHILDREN]]
```

Reason: current live IDB storage is zero; constructor/destructor paths publish/clear this public wrapper singleton.

### [UID:0001P6] `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000QQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QQ`.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
// Exact storage for g_pDATFileMgr at 0x0067ab40.
// The source definition is emitted by [UID:0000QQ] g_pDATFileMgr;
// do not duplicate the pointer definition from this storage child.
```

Reason: one source definition belongs on the global page; this exact address page preserves byte/xref proof.

### [UID:0000UT] `by-item/HasDATEntry_0049C700.md`

Recommended metadata: keep score `86/91`, set `CANONICAL_OWNER:00012E`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.

Formal C++ disposition: keep the formal block blank after metadata reclassification. Add prose proof that this is a duplicate by-item tracker for [UID:00012E], not another source object.

### [UID:0001XB] `by-type/by-vtable/DATManagerVtables.md`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000IO`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.

Formal C++ disposition: keep the formal block blank after metadata reclassification. Add prose proof that this broad vtable inventory is an evidence/index page; exact vtable data pages and class declarations carry the source-declared/generated-binary handling.

## Recommended Target Doc Changes

`by-file/DATFileMgr.md`:

- Add a `2026-07-01 B008 Generated Output Audit` recording generated header `000000003756`, refreshed `2026-07-01T07:16:39-04:00`, tracker row `26` total / `16` filled / `10` empty / `61.5%` / reports `0`.
- Preserve source route `NexusTK/archive/DATFileMgr.cpp`; update score to `COMPLETION:90`, `CONFIDENCE:88` if supervisor accepts this audit.
- Add the ten-empty-marker disposition table from this report.
- Preserve rejected owners: `DATFile`, `DATArchive`, `DATIndexVector`, StringUtil/wide-string helpers, `File`, application cleanup, and all resource/image/sound/UI consumers.
- Preserve no-duplicate policy: class pages emit declarations, exact by-memory children emit method bodies, vtable data pages emit no-array comments, duplicate alias pages become non-emitting.

## Recommended Support Doc Changes

- `by-class/DATFileContainer.md`: metadata `88/90`; insert declaration block above; preserve constructor/destructor child ownership and vtable evidence.
- `by-class/DATFileMgr.md`: metadata `88/90`; insert public wrapper declaration block; preserve [UID:000227], [UID:000439], [UID:00043A], and [UID:00012C] as exact method body emitters.
- `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`: insert no-hand-authored-array formal comment; no metadata change required.
- `by-class/DATFileResolver.md`: metadata `88/91`; insert internal resolver declaration block; preserve embedded `_DATFileMgr + 4` source-shape proof.
- `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`: insert no-hand-authored-array formal comment; no metadata change required.
- `by-global/HasDATEntry_49C700.md`: set owner to [UID:00012E], `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++; preserve 17-caller evidence as symbol-index prose.
- `by-global/g_pDATFileMgr.md`: metadata `88/91`; insert singleton definition plus `[[CHILDREN]]`; preserve current zero-byte MCP proof.
- `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`: metadata `88/91`; insert no-duplicate storage comment; keep current zero-byte/xref proof.
- `by-item/HasDATEntry_0049C700.md`: set owner to [UID:00012E], `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++; preserve as duplicate/tracker note only.
- `by-type/by-vtable/DATManagerVtables.md`: metadata `88/92`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++; preserve public/private vtable inventory evidence as non-emitting index.

## Score And Metadata Recommendation

| UID | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `0000IO` | `89/85`, file root | `90/88`, file root unchanged | Empty-marker family audit resolves current output blockers while preserving source route. |
| `00003H` | `85/87`, true, emits to `0000IO` | `88/90`, true, emits to `0000IO` | Class declaration and child route are now implementation-ready. |
| `00003I` | `86/86`, true, emits to `0000IO` | `88/90`, true, emits to `0000IO` | Public wrapper declaration and child route are implementation-ready. |
| `0002MA` | `86/93`, true, emits to `00003I` | unchanged metadata; formal no-array comment | Exact vtable data is generated from class declaration. |
| `00003J` | `86/89`, true, emits to `0000IO` | `88/91`, true, emits to `0000IO` | Internal resolver declaration is implementation-ready. |
| `0002MB` | `86/93`, true, emits to `000004` | unchanged metadata; formal no-array comment | Exact vtable data is generated from class declaration. |
| `0000T0` | `86/91`, true, emits to `0000IO` | `86/91`, owner `00012E`, `RECONSTRUCTABLE:FALSE`, blank emitter | Duplicate symbol page; [UID:00012E] emits the body. |
| `0000QQ` | `86/88`, true, emits to `0000IO` | `88/91`, true, emits to `0000IO` | Singleton definition is source-ready. |
| `0001P6` | `86/90`, true, emits to `0000QQ` | `88/91`, true, emits to `0000QQ` | Storage child no-duplicate proof is source-ready. |
| `0000UT` | `86/91`, true, emits to `0000IO` | `86/91`, owner `00012E`, `RECONSTRUCTABLE:FALSE`, blank emitter | Duplicate by-item tracker; [UID:00012E] emits the body. |
| `0001XB` | `86/91`, true, emits to `0000IO` | `88/92`, `RECONSTRUCTABLE:FALSE`, blank emitter | Broad vtable inventory, not a separate source emitter. |

## Open Questions With Attempted Resolution

- Exact original private spelling for `_DATFileMgr` and `DATFileResolver` is still not source-proven. Current labels and accepted docs support keeping these names for source-facing declarations; changing to `DATFileMgrImpl` or folding the resolver into raw fields would be less defensible now.
- Exact final helper typedef names such as `SimpleUString`, `DATEntryNode`, `DATBucketRecord`, and `DATFileResolverResult` are inferred from accepted current docs. They are sufficient for class declarations because exact method bodies already use them; they remain confidence-capping rather than blocking.
- `HasDATEntry` original exposure as a header API versus file-local helper is not source-proven, but [UID:00012E] already uses the accepted formal free-helper source shape. Duplicate alias pages should not emit.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`, one scoped file at a time with `--wait-generated`.

| File | Command ID | Timestamp | Exit | Ok | Generated refresh | Notes |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-file/DATFileMgr.md` | `000000003809` | `2026-07-01T15:12:48-04:00` | `0` | `1` | completed, same command/timestamp | Metadata/audit/disposition table accepted. |
| `by-class/DATFileContainer.md` | `000000003810` | `2026-07-01T15:12:58-04:00` | `0` | `1` | completed, same command/timestamp | Metadata/formal declaration accepted; validator also reported pre-existing `missing_ref_uid 0003B6` references. |
| `by-class/DATFileMgr.md` | `000000003811` | `2026-07-01T15:13:09-04:00` | `0` | `1` | completed, same command/timestamp | Metadata/formal public wrapper declaration accepted. |
| `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md` | `000000003813` | `2026-07-01T15:13:20-04:00` | `0` | `1` | completed, same command/timestamp | Formal no-hand-authored-vtable comment accepted. |
| `by-class/DATFileResolver.md` | `000000003814` | `2026-07-01T15:13:30-04:00` | `0` | `1` | completed, same command/timestamp | Metadata/formal internal resolver declaration accepted. |
| `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md` | `000000003816` | `2026-07-01T15:13:54-04:00` | `0` | `1` | completed, same command/timestamp | Formal no-hand-authored-vtable comment accepted; prior compact capture attempt `000000003815` returned exit `1`, then immediate full rerun succeeded with `ok:1`. |
| `by-global/HasDATEntry_49C700.md` | `000000003817` | `2026-07-01T15:14:17-04:00` | `0` | `1` | completed, same command/timestamp | Non-emitting duplicate-symbol reclassification accepted. |
| `by-global/g_pDATFileMgr.md` | `000000003818` | `2026-07-01T15:14:27-04:00` | `0` | `1` | completed, same command/timestamp | Metadata/formal singleton definition accepted. |
| `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md` | `000000003819` | `2026-07-01T15:14:38-04:00` | `0` | `1` | completed, same command/timestamp | Metadata/formal no-duplicate storage comment accepted. |
| `by-item/HasDATEntry_0049C700.md` | `000000003821` | `2026-07-01T15:14:48-04:00` | `0` | `1` | completed, same command/timestamp | Non-emitting duplicate by-item tracker reclassification accepted. |
| `by-type/by-vtable/DATManagerVtables.md` | `000000003822` | `2026-07-01T15:14:58-04:00` | `0` | `1` | completed, same command/timestamp | Non-emitting broad vtable inventory reclassification accepted. |

Generated output verification after the final validator:

- `auto-generated/NexusTK/archive/DATFileMgr.cpp` header is `validator-command-id: 000000003822`, `validator-refreshed-at: 2026-07-01T15:14:58-04:00`, newer than the pre-callback baseline `000000003756` / `2026-07-01T07:16:39-04:00`.
- `rg "Empty Emitter Marker|UID:00003H|UID:00003I|UID:0002MA|UID:00003J|UID:0002MB|UID:0000T0|UID:0000QQ|UID:0001P6|UID:0000UT|UID:0001XB|HasDATEntry\(" auto-generated/NexusTK/archive/DATFileMgr.cpp` shows the source-bearing audited UIDs `00003H`, `00003I`, `0002MA`, `00003J`, `0002MB`, `0000QQ`, and `0001P6` as generated source/comment sections, and no `Empty Emitter Marker` rows for any audited UID.
- Non-emitting duplicate/index UIDs `0000T0`, `0000UT`, and `0001XB` do not appear as generated source sections after reclassification.
- [UID:00012E] remains the single source-bearing `bool HasDATEntry(const wchar_t *entryName)` body; no duplicate body emits from [UID:0000T0] or [UID:0000UT].
- Vtable data pages emit proof comments only: `Do not hand-author this record as a source array`; no hand-authored arrays or duplicate scalar deleting destructor bodies were generated.

## Changed Files

Modified during implementation callback:

- `by-file/DATFileMgr.md`
- `by-class/DATFileContainer.md`
- `by-class/DATFileMgr.md`
- `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`
- `by-class/DATFileResolver.md`
- `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`
- `by-global/HasDATEntry_49C700.md`
- `by-global/g_pDATFileMgr.md`
- `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`
- `by-item/HasDATEntry_0049C700.md`
- `by-type/by-vtable/DATManagerVtables.md`
- `tools/leaser/Agents/Agent-B008/research/0000IO-DATFileMgr-empty-emitter-family-source-quality.md`

Leases:

- B008 acquired leases for all accepted target/support by-* docs plus this report before the edit/validator batch.
- The B008 lease rows were absent from `tools/leaser/Agents/current_leases.md` when checked during correction; they had expired by then. Only unrelated B010/B011 rows were present.
- Explicit cleanup command `python .\tools\leaser\leaser.py B008 unlease` returned `B008: No active leases`; no B008 by-* or report lease remained active at the correction check.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Generated baseline is command `000000003756`, refreshed `2026-07-01T07:16:39-04:00`, with `26` total emitters, `16` filled, `10` empty, `61.5%`, reports `0`. | High | Generated header and tracker row. | `by-file/DATFileMgr.md` generated-output audit. | incorporate | applied: audit section added to `by-file/DATFileMgr.md`; final generated header now `000000003822` / `2026-07-01T15:14:58-04:00`. |
| C02 | The ten empty markers are UIDs `00003H`, `00003I`, `0002MA`, `00003J`, `0002MB`, `0000T0`, `0000QQ`, `0001P6`, `0000UT`, and `0001XB`. | High | Generated `DATFileMgr.cpp` and goal.md. | `by-file/DATFileMgr.md` empty-marker disposition table. | incorporate | applied: disposition table added; generated search shows no `Empty Emitter Marker` for the ten audited UIDs. |
| C03 | [UID:0000IO] remains the `NexusTK/archive/DATFileMgr.cpp` file root; route must not split to `_DATFileMgr.cpp`, `DATFileContainer.cpp`, or `DATFileResolver.cpp`. | High | Current docs, B002/B015, live MCP. | `by-file/DATFileMgr.md`. | incorporate | applied: route/no-split policy added to B008 audit section; validator `000000003809` ok. |
| C04 | [UID:00003H] should emit a `DATFileContainer` declaration plus `[[CHILDREN]]`, not method bodies. | High | Class doc, child constructor/destructor pages, live container decompile. | `by-class/DATFileContainer.md` metadata/formal C++. | incorporate | applied: metadata `88/90`, formal declaration inserted, generated section UID00003H emits declaration only before child constructor/destructor bodies. |
| C05 | [UID:00003I] should emit a public `DATFileMgr` declaration plus `[[CHILDREN]]`, not duplicate child method bodies. | High | Public wrapper decompile, class docs, child wrappers. | `by-class/DATFileMgr.md` metadata/formal C++. | incorporate | applied: metadata `88/90`, formal declaration inserted, generated section UID00003I emits declaration before exact child wrappers. |
| C06 | [UID:0002MA] is exact public-wrapper RTTI/vtable generated from the `DATFileMgr` class declaration; no static array or scalar-deleting body should be hand-authored. | High | `get_bytes`, xrefs to `0x00618914`, class/vtable docs. | `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`. | incorporate | applied: formal no-hand-authored-vtable comment inserted; generated section UID0002MA emits comment only. |
| C07 | [UID:00003J] should emit an internal `DATFileResolver` declaration plus `[[CHILDREN]]`, not standalone file/source bodies. | High | Resolver docs, B005/B015, live function map. | `by-class/DATFileResolver.md` metadata/formal C++. | incorporate | applied: metadata `88/91`, formal declaration inserted, generated section UID00003J emits declaration before exact resolver children. |
| C08 | [UID:0002MB] is exact internal-manager RTTI/vtable generated from `_DATFileMgr`; `0x006189d0` starts UTF-16 `"../"` data, not another slot. | High | `get_bytes`, xrefs to `0x006189cc`, vtable docs. | `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`. | incorporate | applied: formal no-hand-authored-vtable comment inserted; generated section UID0002MB emits comment only. |
| C09 | [UID:0000T0] is a duplicate/global symbol page for [UID:00012E] and should become non-emitting, not duplicate the body. | High | Exact [UID:00012E] formal body; by-global docs. | `by-global/HasDATEntry_49C700.md`. | incorporate | applied: owner set to `00012E`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal block; generated output contains no UID0000T0 section and UID00012E is the only `HasDATEntry` body. |
| C10 | [UID:0000QQ] should emit `DATFileMgr *g_pDATFileMgr = 0;` plus `[[CHILDREN]]`. | High | `get_bytes`/`get_global_value` zero storage; 24 xrefs. | `by-global/g_pDATFileMgr.md`. | incorporate | applied: metadata `88/91`, formal singleton definition plus child marker inserted; generated section UID0000QQ emits `DATFileMgr *g_pDATFileMgr = 0;`. |
| C11 | [UID:0001P6] should emit only a no-duplicate storage comment under [UID:0000QQ]. | High | Exact storage page, singleton xrefs, global declaration route. | `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`. | incorporate | applied: metadata `88/91`, formal no-duplicate storage comment inserted; generated section UID0001P6 emits comment only. |
| C12 | [UID:0000UT] is a duplicate by-item tracker for [UID:00012E] and should become non-emitting. | High | Exact [UID:00012E] formal body; by-item docs. | `by-item/HasDATEntry_0049C700.md`. | incorporate | applied: owner set to `00012E`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal block; generated output contains no UID0000UT section and no duplicate `HasDATEntry` body. |
| C13 | [UID:0001XB] is a broad vtable evidence/index page and should be non-emitting; exact vtable pages and class declarations carry source-declared/generated-binary handling. | High | Vtable inventory, exact vtable data pages, live bytes/xrefs. | `by-type/by-vtable/DATManagerVtables.md`. | incorporate | applied: metadata `88/92`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal block; generated output contains no UID0001XB source section. |
| C14 | Existing filled method/helper bodies should remain on exact by-memory pages; no broad class/file/type page should duplicate them. | High | Generated output, B002/B001/B015 reports. | `by-file/DATFileMgr.md`; all support docs. | incorporate | applied: generated DATFileMgr.cpp still emits exact children such as UID00043B, UID00043C, UID000227, UID000439, UID00043A, UID00012C, UID00043G, UID00043I, UID00012E, UID00043F, and UID00043H; broad pages emit declarations/comments only. |
| C15 | Generated reports, generated C++, project-level reports, coverage reports, validator/tool state, archives, supervisor ledgers, and IDA DB must not be manually edited. | High | Assignment and workflow. | Callback scope/checklist. | not-applicable | excluded-with-reason: no manual edits were made to prohibited files; generated files and validator state changed only through scoped validator commands. |

## Implementation Tracking Checklist

- [x] Supervisor validation accepted the report before implementation; implementation callback assignment was `B008-implement-0000IO-DATFileMgr-empty-emitter-family-20260701`.
- [x] `by-file/DATFileMgr.md`: added `2026-07-01 B008 Generated Output Audit` with generated command `000000003756`, refreshed `2026-07-01T07:16:39-04:00`, `26` total / `16` filled / `10` empty / `61.5%` / reports `0`; preserved source root `NexusTK/archive/`.
- [x] `by-file/DATFileMgr.md`: updated metadata to `COMPLETION:90`, `CONFIDENCE:88`; preserved `CANONICAL_OWNER:FILE`.
- [x] `by-file/DATFileMgr.md`: added ten-empty-marker disposition table naming exact destinations and no-duplicate policy; preserved rejected owners/dependencies.
- [x] `by-class/DATFileContainer.md`: updated to `88/90`; inserted exact `DATFileContainer` declaration block with `[[CHILDREN]]`; no child method body duplication.
- [x] `by-class/DATFileMgr.md`: updated to `88/90`; inserted exact public `DATFileMgr` declaration block with `[[CHILDREN]]`; preserved [UID:000227], [UID:000439], [UID:00043A], and [UID:00012C] as exact method emitters.
- [x] `by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md`: inserted exact no-hand-authored-vtable comment; metadata unchanged at `86/93`.
- [x] `by-class/DATFileResolver.md`: updated to `88/91`; inserted exact internal resolver declaration block with `[[CHILDREN]]`; preserved embedded `_DATFileMgr + 4` proof.
- [x] `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`: inserted exact no-hand-authored-vtable comment; metadata unchanged at `86/93`.
- [x] `by-global/HasDATEntry_49C700.md`: set `CANONICAL_OWNER:00012E`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; added duplicate-symbol/no-duplicate-body proof.
- [x] `by-global/g_pDATFileMgr.md`: updated to `88/91`; inserted `DATFileMgr *g_pDATFileMgr = 0;` plus `[[CHILDREN]]`; preserved live zero-byte and 24-xref proof.
- [x] `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`: updated to `88/91`; inserted exact no-duplicate storage comment; preserved current zero-byte/xref proof and stale `ff ff ff ff` historical caveat.
- [x] `by-item/HasDATEntry_0049C700.md`: set `CANONICAL_OWNER:00012E`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; preserved as duplicate/tracker note only.
- [x] `by-type/by-vtable/DATManagerVtables.md`: updated to `88/92`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; preserved public/private manager vtable inventory as non-emitting evidence.
- [x] Ran all scoped validators listed in `Validator Results`, using `--wait-generated`; recorded command ids, timestamps, exit codes, ok counts, generated-refresh state, and the one `0003B6` missing-ref warning on `by-class/DATFileContainer.md`.
- [x] Inspected generated `auto-generated/NexusTK/archive/DATFileMgr.cpp`; header is `validator-command-id: 000000003822`, `validator-refreshed-at: 2026-07-01T15:14:58-04:00`, newer than command `000000003756` / `2026-07-01T07:16:39-04:00`.
- [x] Inspected generated `DATFileMgr.cpp`; UIDs `00003H`, `00003I`, `0002MA`, `00003J`, `0002MB`, `0000T0`, `0000QQ`, `0001P6`, `0000UT`, and `0001XB` no longer appear as `Empty Emitter Marker`.
- [x] Inspected generated `DATFileMgr.cpp`; [UID:00012E] remains the single source-bearing `HasDATEntry` body, and no duplicate body emits from [UID:0000T0] or [UID:0000UT].
- [x] Inspected generated `DATFileMgr.cpp`; vtable pages emit comments/proof only, not hand-authored arrays or scalar deleting destructor bodies.
- [x] Did not manually edit generated reports, generated `auto-generated/NexusTK/**` files, project-level generated reports, coverage reports, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB; validator-owned generated refreshes were produced only by scoped validators.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000IO-DATFileMgr-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000IO-DATFileMgr-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T15:18:31","uid":"0000IO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
