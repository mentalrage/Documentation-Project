*** UID:0000K2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ImageLib

## UID0000KA Image-Library Consumer - 2026-08-15

`InventoryPane.cpp` includes `render/ImageLib.h` and consumes the existing `g_pEPFLib`, `GetBounds`, and `CopyEntryTileContext` declarations for exact `ITEMINV.EPD`/`ITEMINV.EPF`, `SPELLBUT.EPD`, and `INVENBUT.EPF` use sites. ImageLib retains resource lookup/copy ownership; inventory retains only local frame choice, geometry, and draw order. No EpfFrame/LoadEpfFrame/DrawEpfFrame shim or score change is introduced.

## UID0000L2 Physical Header Visibility Closure - 2026-08-12

- `NexusTK/render/ImageLib.h` now receives the complete UID00006E declaration: the `ImageLib` class, `LookupLayoutEntry` and related APIs, private layout, `ResourceLayoutTable` alias, `g_pEPFLib` extern, size guard, and child declarations. This is required for `MapNamePane::OnPaint()` to call `LookupLayoutEntry` through a complete public declaration.
- `NexusTK/render/ImageLib.cpp` now begins with `#include "ImageLib.h"` and composes its implementation children. The former CPP-resident declaration was an incomplete source-tree factoring arrangement even though the declaration itself was detailed.
- The move preserves the current `91/90` file score, FILE ownership, `NexusTK/render/` path, all method/range evidence, constructor argument caveat, aliases, global ownership, and historical uncertainty. It introduces no duplicate class body or child global.

## Status

- Confidence: very strong for constructor/destructor behavior, singleton/List ownership, complete nine-method ResourceLayout facet, H-only accessor, exact row/header route, source order and generated module inventory. Original typedef/private spellings remain inferred.
- Proposed module: `render/ImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_ImageLib.cpp`
- Main address ranges: `0x004cffb0-0x004d006f`, `0x004d0070-0x004d011b`, and `0x004e64a0-0x004e6572`
- Primary global instance: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical IDA alias `DAT_0067a744`
- Confirmed type anchors: [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)

## File Role

`ImageLib` is the process-wide EPF image/library manager behind `g_pEPFLib`. Its constructor initializes an `LObject` base, assigns `g_pEPFLib = this`, installs the image-library vtable, stores the first callee argument as inferred `m_cacheLimit` at object offset `+0x08`, clears inferred `m_refCount` at `+0x04`, sets inferred `m_maxCacheSize` at `+0x10` to `1000000`, and allocates `m_pEntryList` as a [UID:0000KS][List](by-file/List.md) of 0x2c-byte entries.

Important signature correction: the generated Wave3 method currently appears as `ImageLib::ImageLib(int maxEntries)`, but the binary call site at `0x004644e8` pushes two stack arguments before calling `0x004cffb0`. Instruction order is `push 0x4e20` (`20000`), then `push 0x0f4240` (`1000000`), then `mov ecx,eax`, then `call 0x004cffb0`; IDA confirms the constructor returns with stack cleanup for two arguments. Because x86 stack arguments are consumed in reverse push order, callee `[ebp+8]` receives `1000000` and initializes `m_cacheLimit`, while callee `[ebp+0x0c]` receives `20000` and is unused by the recovered constructor body. The accepted source shape is `ImageLib::ImageLib(int cacheLimit, int)`, preserving the ABI with an unnamed second `int` rather than inventing a false source name.

The key file-ownership finding is that `ImageLib` and the recovered [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) method cluster appear to operate on the same object layout:

```text
ImageLib / g_pEPFLib object
  +0x00  LObject base / vtable
  +0x04  int m_refCount (inferred name)
  +0x08  int m_cacheLimit (inferred name)
  +0x0c  List* m_pEntryList / layout record list
  +0x10  int m_maxCacheSize (inferred name)
```

The accepted source structure is one central `ImageLib.cpp/.h` owning `ImageLib`, `g_pEPFLib`, cache-list lifecycle, nine non-virtual ResourceLayout methods, the compiler-covered row accessor, and both exact row declarations. `ResourceLayoutTable` remains a compatibility typedef, not a second object.

B001-023 source-owner audit resolves one important caveat: [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) is ResourceLayout-format code, but it is not assigned to `ImageLib`. The helper is a two-argument `__stdcall` raw-buffer parser with one caller in `UserLookPane::ParseLookPacket`; the caller preloads [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), but the callee overwrites `ecx` and does not use a `this` pointer. It now parents to file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md).

B001-023 applies the same decision to [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md). The helper is a three-argument `__stdcall` function over caller-provided raw record storage. The known modeled calls are in `NewHumanImageLib::CalculateCompositionBounds`, with additional old/new human composition raw xrefs, so caller modules are consumers; the direct parent is file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), not `ImageLib`.

## Shared Image-Library Load State

B001-052 assigns [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) to this file as common image-library load-error / render-suspend state. The exact public or private source symbol name is still unresolved, so the flag page emits only a formal no-standalone-definition marker, but the ownership decision is stronger than the previous parent-blank state.

The flag is a four-byte initialized `.data` slot whose first byte has `132` direct IDA refs and whose trailing three bytes have no direct refs. B001-052 split those refs into `70` read operands and `62` write operands; all raw little-endian address hits correspond to direct `.text` operand refs, and no debug/source metadata string (`RSDS`, `NB10`, `.pdb`, `.cpp`, `.cxx`, or candidate source filename) proves a more exact declaration file. Writers are spread across HumanImageLib table loading, EffectObjImageLib table loading, and Human-called `ImageLibVectorSupportHelpers`; readers guard MapTile, human/raw, Monster, riding/raw, StaticObj, Effect, and Item image drawing. That distribution makes the flag shared image-library process state rather than a field owned by one asset-family renderer.

Rejected direct owners are documented on the memory page. In short, HumanImageLib and EffectObjImageLib write the flag, other render modules consume it, `VectorHelpers` only owns helper bodies, `ImageFrameTable` and `ImageLoaders` are frame/codec support rather than process-state owners, and the adjacent Monster/Riding table objects have their own static lifetime wrappers that this flag lacks. A new one-global file such as `ImageLibraryLoadState.cpp` remains weaker than the existing common ImageLib source context because no source-tree or static-lifetime evidence supports a separate translation unit. Per-family image modules keep their loaders/renderers, while this file remains the best existing source parent for the shared declaration.

2026-05-24 IDA MCP evidence strengthens the singleton owner decision:

- `xrefs_to 0x0067a744` shows constructor writes at `0x004cffef` / `0x004cfff6` and destructor cleanup at `0x004d00fa`.
- `xrefs_to 0x0061b654` shows the `ImageLib` vtable is installed only by `ImageLib` construction/destruction paths, not by `ResourceLayoutTable`.
- `ResourceLayoutTable` methods use the object reached through `g_pEPFLib`, but they do not initialize the global.
- `ImageLib::ImageLib` constructs the `+0x0c` registry field with `List::List(44, 10)`. The suspected custom `ResourceLayoutStore` vtable is therefore the generic `List` vtable at `0x0061ce2c`.

2026-05-25 IDA MCP recheck confirms the same boundary. `sub_4CFFB0` decompiles as a three-parameter `thiscall` shape (`this`, first stack argument, second stack argument), stores the first callee stack argument at `+0x08`, leaves the second stack argument with no body use, installs vtable `0x0061b654`, and constructs the `+0x0c` list with 44-byte elements. B001's 2026-06-27 recheck adds the exact caller stack mapping: `[ebp+8]` is `1000000`, `[ebp+0x0c]` is `20000`.

## Class Boundary Caveat

Wave3 currently has two separate recovered classes:

- `ImageLib`, with constructor/destructor and `g_pEPFLib` assignment.
- `ResourceLayoutTable`, with the EPF/EPD lookup and lazy-load methods.

IDA xrefs and generated code show `ImageLib::ImageLib` writes `this` to [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), while callers pass that singleton into the method family. Constructor/layout/vtable/lifecycle and direct `+0x0c` List evidence resolve `ResourceLayoutTable` as a recovered semantic alias over ImageLib, not a base slice or independent singleton object.

The vtable also constrains the boundary. IDA shows RTTI for `ImageLib` at `0x0061b650`, a vtable starting at `0x0061b654` with only three slots (`0x004e64a0`, `0x004f4b10`, `0x0041b6c0`), and then RTTI for `MapTileImageLib` at `0x0061b660`. The `ResourceLayoutTable` methods are therefore not `ImageLib` virtual methods; if they belong to the same original class, they are non-virtual public/helper methods or a recovered non-virtual facet.

The constructor at [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) is source-ready as `ImageLib::ImageLib(int cacheLimit, int)`. The ResourceLayout method family consumes the same `m_pEntryList` field, and the complete UID00006E declaration now closes the class/facet header boundary without changing constructor ABI or field layout.

The ordinary non-deleting destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) is the source-authored `ImageLib::~ImageLib()` body that should emit through `NexusTK/render/ImageLib.cpp`. B006 MCP session `80de0a67` and executed validator command `000000004093` confirm it frees each non-null `ResourceLayoutNameRecord::entries` payload from the `m_pEntryList` `List`, deletes and nulls that list, clears `g_pEPFLib = 0;`, and lets the compiler/base class regenerate vtable/base teardown. [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) remains compiler scalar deleting wrapper glue even though the vtable slot points there; its generated contribution is only the accepted formal marker comment, not a handwritten wrapper body.

Do not split this into two unrelated globals in the reconstructed source until the vtable/type boundary is resolved. The supporting type docs now track the unresolved subobject model:

- [UID:0000KS][List](by-file/List.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)

## 2026-06-30 Empty-Emitter Family Implementation

B011's accepted ImageLib empty-emitter family report resolves all 17 previously empty markers in `auto-generated/NexusTK/render/ImageLib.cpp`. Current MCP availability was rechecked through `http://127.0.0.1:13337/mcp`: active database/session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `server_health` `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

The generated file state before implementation was 20 emitters, with only constructor [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md), ordinary destructor [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md), and scalar deleting destructor marker [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) filled. The accepted implementation route is:

| UID | Disposition |
| --- | --- |
| [UID:00006E][ImageLib](by-class/ImageLib.md) | Complete CPP preamble/`[[CHILDREN]]` plus complete H: List include, exact rows, public Find/inline accessor, corrected void APIs, private GetEntry/storage, typedef, singleton extern and size guards. |
| [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) | No standalone layout body; the field layout is consumed by lifecycle and ResourceLayout facet children. |
| [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md) and [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md) | Source-declared/generated-binary vtable route; exact slot bytes remain data evidence and scalar wrapper route, not hand-authored source. |
| [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) | Non-virtual ImageLib singleton/facet method family marker with `[[CHILDREN]]`; exact executable children carry bodies. |
| [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md) through [UID:00054V][0x004d1830-0x004d1860.ResourceLayoutTableGetEntry](by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md) | Nine exact out-of-line ResourceLayout/ImageLib methods over `m_pEntryList`, with UID0002P6 interleaved at `0x004d1600`; public Find, private GetEntry, corrected void APIs and complete formal bodies. |
| [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) | Shared non-virtual `ResourceLayoutTable::LoadFrameDrawRecord` body. Its broad 81-xref caller family systematically prepares `g_pEPFLib` as receiver; it projects packed archive records into `FrameDrawRecord` and preserves next-record sentinel span semantics. |
| [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) and [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md) | Exact source declarations for the 44-byte registry row and 24-byte entry row. |
| [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) and [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md) | Semantic global/storage markers; lifecycle writes and clears are carried by ImageLib constructor/destructor children while the final pointer type remains tied to the facet boundary. |
| [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) | Shared ImageLib load-error/render-suspend state marker; current MCP bytes at `0x0069b420` are zero, correcting older all-`0xff` wording. |

Exact-boundary evidence behind the nine method bodies is: `LoadResourceIndex` `[0x004d0120,0x004d02e5)`, `LookupLayoutEntry` `[0x004d02f0,0x004d039e)`, `CopyEntryTileContext` `[0x004d04d0,0x004d0522)`, `GetEntryRect` `[0x004d0530,0x004d059b)`, `LoadFrameDrawRecord` `[0x004d1600,0x004d165d)`, `GetFrameSize` `[0x004d1730,0x004d1773)`, `GetEntryCount` `[0x004d1780,0x004d17b3)`, `FindResourceIndex` `[0x004d17c0,0x004d182f)`, and `GetEntry` `[0x004d1830,0x004d1860)`. Exact `0xcc` gaps separate every body; GetEntry has zero inbound xrefs but complete source-shaped control flow.

UID0002P6 adds the source-routed frame projection method at `0x004d1600-0x004d165d`. The accepted cross-caller ABI audit supersedes its older free ImageFrameTable-helper placement: unrelated image/render consumers consistently set [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) `g_pEPFLib` as receiver, while the method body retains exact count checks, packed-record projection, and sentinel-boundary calculations. [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) remains a declaration and adjacent-helper dependency, not the canonical source owner for this body.

Rejected alternatives remain important: do not create `ResourceLayoutStore` as a separate object, do not move raw helpers UID0002KQ/UID0002KT into ImageLib, do not hand-port vtable data or singleton storage definitions, do not emit a separate `class ResourceLayoutTable`, and do not duplicate row declarations in CPP. The complete `class ImageLib` owner H is now proven and required.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md)
- [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md)
- [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md)
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)

## Changes

## 2026-08-16 UID0000N5 Complete File Inventory

`ImageLib.cpp` must preserve the existing constructor/destructor/compiler-marker/lifecycle children and contain exactly nine out-of-line ResourceLayout facet definitions in address/source order, including UID0002P6 and new UID00054V. `ImageLib.h` directly includes `../util/List.h`, declares 24-byte `ResourceLayoutEntry` and 44-byte `ResourceLayoutNameRecord` before class use, exposes public `FindResourceIndex` and one in-class const row accessor, declares corrected void lookup/bounds APIs, and retains private `GetEntry` plus the exact 0x14 storage.

`GetResourceLayout` has no CPP body: GFACE and another caller lower it directly to the List virtual slot `+0x10`. `FindResourceIndex` is public because nine of its thirteen callers are external; only four are facet-internal. The old private declaration, incomplete List forward, late CPP row definitions, eight-method output, pointer-returning APIs and repeated finder List calls are historical pre-callback states.

Raw no-`this` helpers remain exclusively in `ResourceLayoutTable.cpp/.h`; decoder/frame functions and compiler vtable/RTTI/global storage retain their existing owners. Score `94/93` reflects complete file/source/header/generated inventory and compile closure, with only lexical typedef/private/accessor spelling uncertainty remaining.

- 2026-07-22 B004 UID000438 accepted support callback:
  - Raised `90/88 -> 91/90`.
  - Added [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) `ResourceLayoutTable::LoadFrameDrawRecord` to the [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) child/source inventory using the systematic `g_pEPFLib` receiver audit and exact 81-xref projection evidence.
  - Preserved the ImageLib/ResourceLayoutTable declaration-boundary caveat, raw no-this helper exclusions, and [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) as a declaration/adjacent-helper dependency rather than canonical owner.

- 2026-06-30 B011 empty-emitter family implementation:
  - Changed score from `87/86` to `90/88`.
  - Summary/evidence: accepted B011 report `0000K2-ImageLib-empty-emitter-family-source-quality.md` resolved the 17 empty generated markers in `ImageLib.cpp`: class/layout/vtable/global/data pages now carry exact formal markers; seven `ResourceLayoutTable` method children carry first-draft source bodies; `ResourceLayoutNameRecord` and `ResourceLayoutEntry` carry formal struct declarations; and `ImageLibraryLoadErrorFlag` now records current zero-byte IDB evidence. Confidence remains below final-audit range because the full `ImageLib`/`ResourceLayoutTable` declaration and `g_pEPFLib` pointer type remain source-shape caps.
- 2026-06-27 B005 scalar-wrapper marker implementation:
  - Changed to: `ImageLib.cpp` should continue to get source `ImageLib::~ImageLib()` from [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md), while [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) contributes only a formal marker comment for the compiler scalar deleting wrapper route.
  - Evidence: B005 MCP/session evidence reconfirmed `0x0061b654 -> 0x004e64a0`, no VA/RVA pointer route to `0x004d0070`, exact `0x004e64a0-0x004e6572` function bounds, and ordinary-destructor cleanup parity with [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md).
- 2026-06-27 B006 destructor source-quality implementation:
  - What existed before: this file still said the ordinary destructor was real but omitted from active Wave3 source, with C++ blank pending rewrite-quality review.
  - Changed to: `ImageLib.cpp` should emit [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) as source `ImageLib::~ImageLib()`, while [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) remains compiler wrapper/no-code.
  - Evidence: MCP session `80de0a67` confirmed exact `0xab` ordinary body, five-byte padding before `0x004d0120`, `m_pEntryList`/`ResourceLayoutNameRecord::entries` cleanup, `g_pEPFLib` clear at `0x004d00fa`, no VA/RVA pointer route to the ordinary destructor, and the expected vtable slot route `0x0061b654 -> 0x004e64a0`.
- 2026-06-27 B001 constructor source-quality implementation:
  - What existed before: this file still described the constructor signature as incomplete and left the second argument, private field names, and `ResourceLayoutTable` boundary as constructor C++ blockers.
  - Changed to: `ImageLib.cpp` should emit [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) as source `ImageLib::ImageLib(int cacheLimit, int)`, with inferred `m_refCount`, inferred `m_cacheLimit`, strongly supported `m_pEntryList`, and inferred `m_maxCacheSize`.
  - Evidence: B001 live MCP database `80de0a67` corrected the call-site push order to callee stack mapping, proved `1000000` is the first callee argument stored at `+0x08`, proved `20000` is the unused second callee argument, checked ResourceLayout methods for object-field reads, and used B006's executed destructor evidence for `m_pEntryList`. Scores remain unchanged because file-level class/facet/header factoring is still broader than this constructor child.
- 2026-06-08 A010 Batch120 parent/source audit:
  - Changed from `86/85` to `87/86`.
  - Evidence: documented the unresolved raw-buffer helper [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) as ResourceLayout-format/ImageLib-neighborhood code that still lacks direct `thiscall` or source-owner proof. This improves the ImageLib/ResourceLayout boundary evidence while preserving the no-assignment decision for that raw helper.
- 2026-06-08 A003 Batch132 raw-record helper audit:
  - Changed to: no score change.
  - Evidence: documented [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) as another ImageLib/ResourceLayout-neighborhood helper whose child score now clears `85/88` but whose direct ownership remains unresolved because it has no `this` and its known callers are human-image composition paths.
- 2026-06-10 B001-023 raw-helper routing:
  - Changed to: no score change.
  - Evidence: clarified that [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) are not ImageLib class methods and now parent to file-level [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md).
- 2026-06-12 B001-052 shared load-error flag routing:
  - Changed to: no score change.
  - Evidence: documented [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) as shared ImageLib-owned image-library load-error/render-suspend state after B001 ranked the common ImageLib source context above HumanImageLib, EffectObjImageLib, Monster/Riding adjacency, VectorHelpers, and a hypothetical one-global source file.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad ImageLib memory aggregate is now [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md), a non-emitting local lifecycle cluster; the scalar deleting destructor remains [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md).
  - Evidence: live IDA `entity_query` on 2026-06-12 proved the previous broad `0x004cffb0-0x004e6572` range crossed sibling image-library owners and was a structure error rather than valid containment.
- 2026-06-07 A008 alias cleanup:
  - Before: the page exposed bare `DAT_0067a744` wording in the primary-global and class-boundary notes.
  - Changed to: canonical [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) wording while retaining `DAT_0067a744` as the historical IDA alias.
  - Evidence: existing IDA xref notes on this page and the global page both identify `0x0067a744` as the `ImageLib`-owned singleton consumed by the `ResourceLayoutTable` method family.
- 2026-06-07 A006 Batch 048 parent-gate refresh:
  - Changed confidence from `82` to `85`.
  - Evidence: the split-recheck reconfirmed that the `ResourceLayoutTable` method family operates on the `g_pEPFLib` object initialized by `ImageLib`, and the five corrected ResourceLayout child filenames now match IDA exclusive ends. Confidence clears the corrected parent gate for the `ResourceLayoutTable` facet while staying below final-source confidence because the exact helper/file split and second constructor argument remain unresolved.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: constructor/destructor behavior, `g_pEPFLib`, vtable/layout anchors, cache-list lifecycle, call-site signature correction, and `ResourceLayoutTable` relationship are documented; confidence is capped by unresolved class/facet boundary and second constructor-argument semantics.
- 2026-05-31 projected path and range correction:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the main ranges used old ends `0x004d006e`, `0x004d011a`, and `0x004e6571`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, corrected exclusive-end ranges `0x004d006f`, `0x004d011b`, and `0x004e6572`, and `CONFIDENCE:82`.
  - Summary/evidence: IDA MCP confirmed exact function bounds and decompilation for constructor, ordinary destructor, and scalar deleting destructor. The projected folder follows the documented render/image-library source grouping already used for neighboring image-library modules.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000K2)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- ImageLib.cpp remains the sole source/lifetime owner for g_pEPFLib and the ResourceLayoutTable facet. Raw no-this helpers stay excluded, while the old independent-object/g_pResourceMan reading is historicalized.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-091 | 00006E | `g_pResourceMan` is rejected. Storage 0x0067a744 is ImageLib-owned `g_pEPFLib`; the strongest complete source route is `ImageLib` with `typedef ImageLib ResourceLayoutTable`, exact non-virtual lookup methods, and one `extern ImageLib *g_pEPFLib`. | Strong | ImageLib RTTI/lifecycle, sole global writes/clears, shared +0xc List, and ResourceLayout method family. | UID00006E complete formal; UID0000K2/UID0000BY/UID0000QU support; UID0002DL. | reject-invalid | implemented |
