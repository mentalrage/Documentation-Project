** TARGET-REPORT-UID:0000K2 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B011 Research Report: UID 0000K2 ImageLib Empty-Emitter Family

## Assignment

- Assignment ID: `B011-report-0000K2-ImageLib-empty-emitter-family-20260630`
- Mode: report-only research first; no by-* docs edited, no generated files edited, no leases taken.
- Target: [UID:0000K2] `by-file/ImageLib.md`
- Generated output inspected read-only: `auto-generated/NexusTK/render/ImageLib.cpp`
- Required report path: `tools/leaser/Agents/Agent-B011/research/0000K2-ImageLib-empty-emitter-family-source-quality.md`

## Current Target State And Queue Row

Current generated row for [UID:0000K2] reports 20 emitters, 3 filled, 17 empty, 15.0 percent complete. The current generated file header is `auto-generated/NexusTK/render/ImageLib.cpp`, refreshed by validator command `000000002458` at `2026-06-30T05:46:05-04:00`.

Filled emitters already present in generated output:

| UID | Doc | Current generated disposition |
| --- | --- | --- |
| `0002IN` | `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md` | First-draft `ImageLib::ImageLib(int cacheLimit, int)` source is already emitted at `91/92`. |
| `000173` | `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md` | First-draft `ImageLib::~ImageLib()` source is already emitted at `90/92`. |
| `0002IO` | `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md` | Compiler-generated scalar deleting destructor marker already emitted at `88/92`. |

Current empty emitters requiring disposition:

| UID | Path | Current score | Disposition in this report |
| --- | --- | ---: | --- |
| `00006E` | `by-class/ImageLib.md` | `86/86` | No class-level body marker with `[[CHILDREN]]`; exact class declaration is unsafe because the ImageLib object also carries the ResourceLayoutTable non-virtual facet. |
| `0001US` | `by-type/by-struct/ImageLibLayout.md` | `85/89` | No standalone layout C++ marker; field layout is consumed by lifecycle and method children. |
| `0001XR` | `by-type/by-vtable/ImageLibVtable.md` | `87/92` | No standalone vtable C++ marker with `[[CHILDREN]]`; vtable data is compiler output. |
| `00031R` | `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md` | `88/92` | No standalone vtable-data marker. |
| `0000BY` | `by-class/ResourceLayoutTable.md` | `87/86` | No independent class declaration marker with `[[CHILDREN]]`; child methods should emit bodies. |
| `0002KO` | `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` | `85/88` | First-draft method body. |
| `0002KP` | `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` | `85/90` | First-draft method body. |
| `0002KR` | `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `86/90` | First-draft method body. |
| `0002KS` | `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` | `85/88` | First-draft method body. |
| `0002KU` | `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` | `85/91` | First-draft method body. |
| `0002KV` | `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` | `85/92` | First-draft method body. |
| `0002KW` | `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` | `85/90` | First-draft method body. |
| `0001VT` | `by-type/by-struct/ResourceLayoutNameRecord.md` | `86/90` | Exact 44-byte struct declaration. |
| `0000QU` | `by-global/g_pEPFLib.md` | `89/87` | No standalone global definition marker with `[[CHILDREN]]`; final pointer type remains the ImageLib/ResourceLayoutTable facet decision. |
| `0001OQ` | `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` | `86/90` | No standalone storage marker. |
| `0000VB` | `by-item/ResourceLayoutEntry.md` | `86/90` | Exact 24-byte row declaration. |
| `00029J` | `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md` | `88/92` | No standalone global definition marker; support refresh should correct current initialized bytes to zero. |

## Evidence Checked

### Workflow And Local Docs

- Read current `Agent-B011/goal.md`; it requires report-only research, no leases, no by-* edits, current MCP evidence, full 17-marker inventory, and implementation-ready C++ or target-specific no-code proof.
- Used project skill `ntk-b-agent-workflow` and the source-quality/research workflow references.
- Read current target/support docs for all 17 empty emitters plus current filled lifecycle children, `by-file/ResourceLayoutTable.md`, ResourceLayout aggregate docs, List, EPFTileContext, DATFile, DATFile aggregate, and DATArchive umbrella.
- Opened matching executed reports as leads only: B001 ImageLib constructor, B006 ImageLib destructor, B005 scalar deleting destructor, B001 ImageLibraryLoadErrorFlag, and B001 ResourceLayoutTable aggregate. Current docs/MCP supersede stale conclusions where they differ.

### MCP Session And Calls

MCP was available and schema-current. No `PAUSED_MCP_*` condition occurred.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`, imagebase `0x400000`
- `server_health(database=supervisor_resume_20260629)`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`, `is_analyzing:false`.
- Current schema requires `database` on IDB-backed calls; calls used schema-current forms such as `lookup_funcs(database, queries)`, `xrefs_to(database, addrs, limit)`, `decompile(database, addr, include_addresses)`, `get_bytes(database, regions)`, `callees(database, addrs, limit)`, and `analyze_component(database, addrs)`.

### Boundary And Byte Evidence

`lookup_funcs` confirmed exact modeled function starts/sizes and non-function endpoints:

| Address | MCP result |
| --- | --- |
| `0x004cffb0` | `sub_4CFFB0`, size `0xbf`; `0x004d006f` is not a function. |
| `0x004d0070` | `sub_4D0070`, size `0xab`; `0x004d011b` is not a function. |
| `0x004d0120` | `sub_4D0120`, size `0x1c5`; `0x004d02e5` is not a function. |
| `0x004d02f0` | `sub_4D02F0`, size `0xae`; `0x004d039e` is not a function. |
| `0x004d04d0` | `sub_4D04D0`, size `0x52`; `0x004d0522` is not a function. |
| `0x004d0530` | `sub_4D0530`, size `0x6b`; `0x004d059b` is not a function. |
| `0x004d1730` | `sub_4D1730`, size `0x43`; `0x004d1773` is not a function. |
| `0x004d1780` | `sub_4D1780`, size `0x33`; `0x004d17b3` is not a function. |
| `0x004d17c0` | `sub_4D17C0`, size `0x6f`; `0x004d182f` is not a function. |
| `0x004e64a0` | `sub_4E64A0`, size `0xd2`; `0x004e6572` is not a function. |
| `0x0061b650`, `0x0061b654`, `0x0061b660`, `0x0067a744`, `0x0069b420`, `0x0069b424` | not functions; data/storage only. |

`get_bytes` confirmed compiler/data states:

- `0x0061b650-0x0061b660`: `d4 86 64 00 a0 64 4e 00 10 4b 4f 00 c0 b6 41 00`, interpreted as RTTI/COL pointer, scalar deleting destructor `0x004e64a0`, inherited/shared virtual `0x004f4b10`, and inherited no-op `0x0041b6c0`.
- `0x0067a744-0x0067a754`: all zero, consistent with runtime singleton pointer storage.
- `0x0069b418-0x0069b430`: all zero in current IDB. This corrects the older `00029J` wording that described `0xff` static bytes. The ownership and xref evidence remain unchanged.
- Post-function padding is `0xcc`: `0x004d02e5` has eleven bytes, `0x004d039e` two, `0x004d0522` fourteen, `0x004d059b` five, `0x004d1773` thirteen, `0x004d17b3` thirteen, `0x004d182f` one, and `0x004e6572` fourteen.

### Xref Evidence

Key `xrefs_to` counts:

- `0x004d0120` has 13 refs. The lazy-load callers include local accessors at `0x004d030a`, `0x004d054a`, `0x004d174a`, and `0x004d179a`; Human/NewHuman composition callers at `0x004d42e4`, `0x004d434e`, `0x004e22aa`, and `0x004e341a`; plus raw/orphan image-family callers at `0x004d80d2`, `0x004d819a`, `0x004d8a62`, `0x004d8b20`, and `0x004e3bdd`.
- `0x004d02f0` has `xref_count 440`, no data refs, proving a broad central ResourceLayout lookup surface.
- `0x004d04d0` has `xref_count 25`, no data refs.
- `0x004d0530` has 11 refs, including modeled call sites and two old-human raw/orphan refs at `0x004d8130` and `0x004d8aba`.
- `0x004d1730` has one direct ref at `0x004e99b4`, `InterfaceEfx::Play`.
- `0x004d1780` has six refs at `0x004e9888`, `0x004ffe27`, `0x00595538`, `0x00595559`, `0x00598f82`, and `0x0059909b`.
- `0x004d17c0` has 13 refs, including local lazy accessors, Human/NewHuman composition callers, and raw/orphan image-family callers.
- `0x004e64a0` has one data xref from the vtable slot at `0x0061b654`.
- `0x0061b654` has three refs: constructor vptr store `0x004d0009`, ordinary destructor vptr reset `0x004d009a`, and scalar deleting destructor vptr reset `0x004e64d1`.
- `0x0067a744` has `xref_count 231`, consistent with `g_pEPFLib` as a shared singleton pointer.
- `0x0069b420` has `xref_count 132`; neighboring bytes `0x0069b421-0x0069b423` have zero xrefs, while neighboring globals at `0x0069b418`, `0x0069b41c`, `0x0069b424`, and `0x0069b42c` have independent refs. This supports a byte/flag-like storage interpretation at `0x0069b420`, not a broad 4-byte initialized table.

### Decompile And Callee Evidence

Current decompilation confirms:

- `ImageLib::ImageLib`: base setup, `g_pEPFLib = this`, vtable install, `m_refCount = 0`, constructor argument to `m_cacheLimit`, `m_maxCacheSize = 1000000`, and `m_pEntryList = new List(44, 10)`.
- `ImageLib::~ImageLib`: vtable reset, `GetMemoryMan`, loop over `m_pEntryList->GetCount()`, `GetElementAt(index)`, free and null each `ResourceLayoutNameRecord::entries`, delete list, clear `m_pEntryList`, clear `g_pEPFLib`, base cleanup.
- `ImageLib` scalar deleting destructor: same cleanup plus compiler delete flag/guard handling; source cleanup remains represented by `ImageLib::~ImageLib()`.
- `ResourceLayoutTable::LoadResourceIndex`: constructs/opens `DATFile`, reads an 8-byte header and table offset, seeks, allocates `(entryCount + 1) * 24` bytes, reads top/left/bottom/right plus payload and mask offsets, normalizes bounds to left/top/right/bottom, rebases pointers from `DATFile::GetDataPointer() + 12`, installs a sentinel row, copies the 16-wide-character resource name, appends one 44-byte `ResourceLayoutNameRecord` to the `List`, closes/destroys `DATFile`, and returns `m_pEntryList->GetCount() - 1`.
- `ResourceLayoutTable::LookupLayoutEntry`: `FindResourceIndex`, fallback `LoadResourceIndex`, list `GetElementAt`, signed frame index validation against `entryCount`, EPFTileContext mapping (`pixelData`, `rowStridePixels`, bounds, `encodedMaskByteCount`, `encodedMaskBytes`), invalid-output zeroing.
- `ResourceLayoutTable::CopyEntryTileContext`: stack `EPFTileContext`, `Initialize`, `LookupLayoutEntry`, optional `CopyTo(destination)`.
- `ResourceLayoutTable::GetEntryRect`: lazy find/load, list row lookup, frame bounds check, copy first 16 bytes of `ResourceLayoutEntry` or zero output rectangle.
- `ResourceLayoutTable::GetFrameSize`: lazy find/load, list row lookup, write record `frameWidth` at `+0x22` and `frameHeight` at `+0x24`.
- `ResourceLayoutTable::GetEntryCount`: lazy find/load, list row lookup, return unsigned 16-bit count at record `+0x20`.
- `ResourceLayoutTable::FindResourceIndex`: linear `wcscmp` over 44-byte rows; no static callees.

`callees` confirmed direct dependencies:

- `0x004d0120`: `DATFile` constructor/open/read/seek/get-data/close/destructor, MemoryMan allocation, rectangle initializer, `_wcscpy_s`, and security cookie.
- `0x004d02f0`: only `0x004d17c0`, `0x004d0120`, and rectangle zero initializer `0x004b7c50`.
- `0x004d04d0`: `EPFTileContext::Initialize`, `0x004d02f0`, `EPFTileContext::CopyTo`, and security cookie.
- `0x004d0530`: `0x004d17c0`, `0x004d0120`, and rectangle zero initializer.
- `0x004d1730` and `0x004d1780`: `0x004d17c0` and `0x004d0120`.
- `0x004d17c0`: no direct static callees; the wide-string compare is inlined.

`analyze_component` over the seven ResourceLayout methods returned all seven as interface functions and no internal-only nodes. This supports treating each exact by-memory page as the source-bearing child rather than burying behavior in the aggregate page.

## Positive Evidence

- The ImageLib lifecycle children already provide source-quality constructor/destructor bodies and prove `m_pEntryList` is the object field at `+0x0c`.
- `List` docs now provide accepted source-facing `List(int elementSize, int pageSize)`, `GetCount`, `GetElementAt`, and `Append` vocabulary. That removes the prior ResourceLayoutStore blocker.
- `EPFTileContext` docs now provide accepted source-facing layout and method names (`Initialize`, `CopyTo`, `rowStridePixels`, `encodedMaskByteCount`, `encodedMaskBytes`, `RectBounds`). That removes the prior generic-output-field blocker for `0002KP` and `0002KR`.
- `DATFile` docs confirm ResourceLayout loader code is a DAT consumer, not archive-owned code. `LoadResourceIndex` belongs with render/ImageLib ResourceLayout behavior while using `DATFile` API.
- `ResourceLayoutNameRecord` and `ResourceLayoutEntry` layouts are exact enough for declarations: constructor allocates `List(44, 10)`, loader appends 44-byte rows, destructor frees row `+0x28`, accessors use count/size fields, and lookup methods depend on the 24-byte entry stride and sentinel row.

## Negative And Counter-Evidence

- No independent `ResourceLayoutTable` constructor, destructor, vtable, vtable data, global storage, or allocation route was found. The method family is method-shaped and uses `this+0x0c`, but that field is proven as `ImageLib::m_pEntryList`.
- Raw ResourceLayout helpers `0002KQ` and `0002KT` belong to file-level [UID:0000N5] `ResourceLayoutTable`, not the ImageLib empty-emitter family. They are not part of the current 17-marker generated output.
- `ResourceLayoutStore` is rejected by current List docs: it is an overlay over a generic `List*`, not a separately constructed object.
- Emitting a full `class ResourceLayoutTable` declaration with fields would invent an unsupported independent object. Emitting all ResourceLayout methods as child bodies under the existing class/facet owner is supported because the exact by-memory pages are already owned by [UID:0000BY] and emit through `ImageLib.cpp`.
- Emitting a full `class ImageLib` declaration now would either omit the ResourceLayout method surface that uses the same object or force an unsupported base/facet declaration. The safe implementation is a class-level marker plus source-bearing children.
- Emitting standalone vtable/vtable-data or raw global storage definitions would hand-port compiler/data artifacts and duplicate class/global semantic pages.
- Current MCP bytes for `0x0069b420` are zero, not the older `0xff` bytes. This is a support-refresh correction, not a reason to change ownership away from ImageLib.

## Heuristic And Inference Reanalysis

The old blocker wording across this family was too broad: final original class names and private member spellings are not enough by themselves to keep exact methods blank. Current supporting docs now settle the main source-facing vocabulary:

- `List` is the actual container; do not invent `ResourceLayoutStore`.
- `ResourceLayoutNameRecord` and `ResourceLayoutEntry` are exact row types.
- `EPFTileContext` field names are source-quality descriptive names.
- `DATFile` is a dependency, not the owner.

Therefore the executable ResourceLayout methods should move from empty emitters to first-draft source bodies. The class/type/data/global pages should not be forced into fake declarations or definitions; they should receive specific no-code markers that explain the compiler/data/facet reason and route to children where appropriate.

## Ranked Ownership And Source Placement

1. `render/ImageLib.cpp` / [UID:0000K2] remains the correct generated output for this family. It owns the ImageLib lifecycle, `g_pEPFLib`, ResourceLayoutTable facet methods, ResourceLayout rows, and load-error flag.
2. [UID:00006E] `ImageLib` remains the class owner for lifecycle/vtable/layout children but should not emit a class declaration until the ResourceLayoutTable facet/header route is final.
3. [UID:0000BY] `ResourceLayoutTable` remains the method-family/facet owner for the seven exact ResourceLayout methods. It should not emit an independent class declaration, but its method children should emit bodies.
4. [UID:0000N5] `by-file/ResourceLayoutTable.md` remains the owner for raw no-this helper pages outside this generated output. It should be support-refreshed only to clarify that the class-backed method bodies emit through `ImageLib.cpp`; it should not steal this family.
5. DAT archive owners, EPFTileContext, List, MemoryMan, Rect helpers, Human/NewHuman/InterfaceEfx callers, and raw orphan callers are dependencies or consumers, not owners of the ImageLib empty-emitter family.

## Per-Class Audits

### UID 00006E ImageLib

Audit routes checked:

- Constructor route: exact first-draft `ImageLib::ImageLib(int cacheLimit, int)` already emitted; it initializes base `LObject`, `g_pEPFLib`, vtable, `m_refCount`, `m_cacheLimit`, `m_maxCacheSize`, and `m_pEntryList = new List(44, 10)`.
- Destructor route: exact first-draft `ImageLib::~ImageLib()` already emitted; it drains `ResourceLayoutNameRecord::entries`, deletes `m_pEntryList`, and clears `g_pEPFLib`.
- Scalar deleting destructor route: exact compiler-generated marker already emitted; vtable slot points to wrapper, not ordinary destructor.
- Vtable slots: `0x0061b654 -> 0x004e64a0`, `0x0061b658 -> 0x004f4b10`, `0x0061b65c -> 0x0041b6c0`; no method slot for ResourceLayout APIs.
- Fields/offsets: `+0x00` vtable/LObject, `+0x04 m_refCount`, `+0x08 m_cacheLimit`, `+0x0c m_pEntryList`, `+0x10 m_maxCacheSize`.
- Base class: `LObject`, supported by constructor/destructor calls and inherited vtable slots.
- Direct child method ownership: constructor/destructor/scalar wrapper are class-owned; ResourceLayout methods are currently owned by [UID:0000BY] and use the same object storage.
- Declaration shell safety: unsafe now. A shell containing only lifecycle fields hides the public ResourceLayout method surface seen by `g_pEPFLib` consumers. A shell that includes ResourceLayout methods or a `ResourceLayoutTable` base/facet would assert a source class hierarchy not supported by constructor/vtable/layout evidence.

Implementation-ready recommendation:

- Keep ImageLib class page reconstructable and emitting through `ImageLib.cpp`.
- Insert a no class-level C++ marker with `[[CHILDREN]]`.
- Raise metadata modestly to `COMPLETION:87`, `CONFIDENCE:88` after recording the exact class audit and child routing.

### UID 0000BY ResourceLayoutTable

Audit routes checked:

- Constructor/destructor route: none found. No allocation or vtable installation creates an independent `ResourceLayoutTable` object.
- Vtable slots: none found for ResourceLayoutTable. All seven methods are non-virtual direct calls using the ImageLib singleton/facet pointer as `this`.
- Method inventory: `LoadResourceIndex`, `LookupLayoutEntry`, `CopyEntryTileContext`, `GetEntryRect`, `GetFrameSize`, `GetEntryCount`, and `FindResourceIndex`. All seven have exact function boundaries and current MCP evidence.
- Fields/offsets: methods use only `this+0x0c`, which is the same `m_pEntryList` field proven by ImageLib constructor/destructor.
- Base class: no independent base was found. Treating ResourceLayoutTable as a source base of ImageLib is plausible but not proven by binary evidence.
- Direct child method ownership: current docs attach all seven methods to [UID:0000BY]; this is still the best method-family owner, with generated output under ImageLib.
- Declaration shell safety: unsafe as an independent class because it would require declaring `m_pEntryList` on a class that has no constructor/vtable/storage route. It is also unsafe to move the methods directly to ImageLib in this report because current owner docs already route them through [UID:0000BY] and the file-level [UID:0000N5] raw-helper split depends on that distinction.

Implementation-ready recommendation:

- Keep [UID:0000BY] as a non-virtual ImageLib singleton/facet method owner.
- Insert a no class-level body marker with `[[CHILDREN]]`.
- Insert first-draft bodies on the seven exact method pages.
- Raise metadata to `COMPLETION:89`, `CONFIDENCE:88`.

## Exact Formal C++ / No-Code Recommendations

The following blocks are the exact recommended `RECONSTRUCTION_CPP CODE:BEGIN/END` insertion text for implementation callback.

### UID 00006E by-class/ImageLib.md

```cpp
// [UID:00006E] no class-level C++ body.
// ImageLib lifecycle bodies, vtable/compiler wrapper evidence, and ResourceLayoutTable facet methods are emitted by exact child pages. A standalone class declaration is not source-safe until the ImageLib/ResourceLayoutTable facet boundary is represented without inventing an unsupported base or duplicate field layout.
[[CHILDREN]]
```

### UID 0001US by-type/by-struct/ImageLibLayout.md

```cpp
// [UID:0001US] no standalone layout C++ body.
// The ImageLib field layout is consumed by the ImageLib lifecycle and ResourceLayoutTable facet children; emitting a duplicate layout struct would conflict with the pending class/facet declaration route.
```

### UID 0001XR by-type/by-vtable/ImageLibVtable.md

```cpp
// [UID:0001XR] no standalone vtable C++ body.
// The ImageLib vtable is compiler-emitted from the class declaration; exact slot data is documented by the vtable-data child and scalar deleting destructor route.
[[CHILDREN]]
```

### UID 00031R by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md

```cpp
// [UID:00031R] no standalone C++ body.
// Compiler-emitted ImageLib RTTI/vtable data is covered by the ImageLib class route, vtable type page, and scalar deleting destructor slot.
```

### UID 0000BY by-class/ResourceLayoutTable.md

```cpp
// [UID:0000BY] no class-level C++ body.
// Current evidence supports ResourceLayoutTable as a non-virtual ImageLib singleton/facet method family, not as an independently constructed object. Exact method children carry the source bodies.
[[CHILDREN]]
```

### UID 0002KO by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md

```cpp
int ResourceLayoutTable::LoadResourceIndex(const wchar_t *resourceName)
{
    DATFile file;

    if (!file.Open(resourceName)) {
        return -1;
    }

    unsigned short header[4];
    int entryTableOffset = 0;

    file.Read(header, sizeof(header));
    file.Read(&entryTableOffset, sizeof(entryTableOffset));
    file.Seek(entryTableOffset, 0);

    const int entryCount = header[0];
    ResourceLayoutEntry *entries = static_cast<ResourceLayoutEntry *>(
        GetMemoryMan()->AllocateBufferMemory(sizeof(ResourceLayoutEntry) * (entryCount + 1)));
    unsigned char *payloadBase = static_cast<unsigned char *>(file.GetDataPointer()) + 12;

    for (int index = 0; index < entryCount; ++index) {
        int top = 0;
        int left = 0;
        int bottom = 0;
        int right = 0;
        int pixelDataOffset = 0;
        int encodedMaskOffset = 0;

        file.Read(&top, sizeof(top));
        file.Read(&left, sizeof(left));
        file.Read(&bottom, sizeof(bottom));
        file.Read(&right, sizeof(right));
        file.Read(&pixelDataOffset, sizeof(pixelDataOffset));
        file.Read(&encodedMaskOffset, sizeof(encodedMaskOffset));

        entries[index].left = left;
        entries[index].top = top;
        entries[index].right = right;
        entries[index].bottom = bottom;
        entries[index].pixelData = payloadBase + pixelDataOffset;
        entries[index].encodedMaskData = payloadBase + encodedMaskOffset;
    }

    entries[entryCount].left = 0;
    entries[entryCount].top = 0;
    entries[entryCount].right = 0;
    entries[entryCount].bottom = 0;
    entries[entryCount].pixelData = payloadBase + entryTableOffset;
    entries[entryCount].encodedMaskData = payloadBase + entryTableOffset;

    ResourceLayoutNameRecord record = {};
    wcscpy_s(record.name, 16, resourceName);
    record.entryCount = header[0];
    record.frameWidth = header[1];
    record.frameHeight = header[2];
    record.reservedHeaderWord = header[3];
    record.entries = entries;

    m_pEntryList->Append(1, &record);
    file.Close();

    return m_pEntryList->GetCount() - 1;
}
```

Notes for implementation: `DATFile::Seek(entryTableOffset, 0)` represents the current entry seek-to-beginning call; if the local DATFile API declaration in docs prefers a named origin enum, use that name without changing the body semantics. `GetMemoryMan()->AllocateBufferMemory` is the same allocator family used by destructor-side `FreeBufferMemory`.

### UID 0002KP by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md

```cpp
ResourceLayoutEntry *ResourceLayoutTable::LookupLayoutEntry(
    const wchar_t *resourceName,
    int frameIndex,
    EPFTileContext *tileContext)
{
    int resourceIndex = FindResourceIndex(resourceName);

    if (resourceIndex == -1) {
        resourceIndex = LoadResourceIndex(resourceName);
    }

    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(resourceIndex));
    ResourceLayoutEntry *entry = 0;

    if (frameIndex >= 0 && frameIndex < record->entryCount) {
        entry = &record->entries[frameIndex];
    }

    if (tileContext != 0) {
        if (entry != 0) {
            tileContext->pixelData = entry->pixelData;
            tileContext->rowStridePixels = entry->right - entry->left;
            tileContext->bounds.left = entry->left;
            tileContext->bounds.top = entry->top;
            tileContext->bounds.right = entry->right;
            tileContext->bounds.bottom = entry->bottom;
            tileContext->encodedMaskByteCount =
                static_cast<int>(record->entries[frameIndex + 1].pixelData - entry->encodedMaskData);
            tileContext->encodedMaskBytes = entry->encodedMaskData;
        } else {
            tileContext->pixelData = 0;
            tileContext->rowStridePixels = 0;
            tileContext->bounds.left = 0;
            tileContext->bounds.top = 0;
            tileContext->bounds.right = 0;
            tileContext->bounds.bottom = 0;
            tileContext->encodedMaskByteCount = 0;
            tileContext->encodedMaskBytes = 0;
        }
    }

    return entry;
}
```

### UID 0002KR by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md

```cpp
void ResourceLayoutTable::CopyEntryTileContext(
    const wchar_t *resourceName,
    int frameIndex,
    EPFTileContext *destination)
{
    EPFTileContext tileContext;

    tileContext.Initialize();
    LookupLayoutEntry(resourceName, frameIndex, &tileContext);

    if (destination != 0) {
        tileContext.CopyTo(destination);
    }
}
```

### UID 0002KS by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md

```cpp
RectBounds *ResourceLayoutTable::GetEntryRect(
    const wchar_t *resourceName,
    int frameIndex,
    RectBounds *bounds)
{
    int resourceIndex = FindResourceIndex(resourceName);

    if (resourceIndex == -1) {
        resourceIndex = LoadResourceIndex(resourceName);
    }

    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(resourceIndex));

    if (frameIndex >= 0 && frameIndex < record->entryCount) {
        const ResourceLayoutEntry *entry = &record->entries[frameIndex];

        bounds->left = entry->left;
        bounds->top = entry->top;
        bounds->right = entry->right;
        bounds->bottom = entry->bottom;
    } else {
        bounds->left = 0;
        bounds->top = 0;
        bounds->right = 0;
        bounds->bottom = 0;
    }

    return bounds;
}
```

### UID 0002KU by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md

```cpp
void ResourceLayoutTable::GetFrameSize(
    const wchar_t *resourceName,
    unsigned short *width,
    unsigned short *height)
{
    int resourceIndex = FindResourceIndex(resourceName);

    if (resourceIndex == -1) {
        resourceIndex = LoadResourceIndex(resourceName);
    }

    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(resourceIndex));

    *width = record->frameWidth;
    *height = record->frameHeight;
}
```

### UID 0002KV by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md

```cpp
unsigned short ResourceLayoutTable::GetEntryCount(const wchar_t *resourceName)
{
    int resourceIndex = FindResourceIndex(resourceName);

    if (resourceIndex == -1) {
        resourceIndex = LoadResourceIndex(resourceName);
    }

    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(resourceIndex));

    return record->entryCount;
}
```

### UID 0002KW by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md

```cpp
int ResourceLayoutTable::FindResourceIndex(const wchar_t *resourceName)
{
    const int count = m_pEntryList->GetCount();

    for (int index = 0; index < count; ++index) {
        ResourceLayoutNameRecord *record =
            static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(index));

        if (wcscmp(record->name, resourceName) == 0) {
            return index;
        }
    }

    return -1;
}
```

### UID 0001VT by-type/by-struct/ResourceLayoutNameRecord.md

```cpp
struct ResourceLayoutNameRecord {
    wchar_t name[16];
    unsigned short entryCount;
    unsigned short frameWidth;
    unsigned short frameHeight;
    unsigned short reservedHeaderWord;
    ResourceLayoutEntry *entries;
};
```

### UID 0000QU by-global/g_pEPFLib.md

```cpp
// [UID:0000QU] no standalone global definition.
// g_pEPFLib storage and lifecycle are exact, but the final source-facing pointer type remains tied to the ImageLib/ResourceLayoutTable facet boundary. Constructor/destructor and storage children carry the concrete writes, clears, and address evidence.
[[CHILDREN]]
```

### UID 0001OQ by-memory/0x0067a744-0x0067a748.g_pEPFLib.md

```cpp
// [UID:0001OQ] no standalone C++ body.
// Exact storage for g_pEPFLib at 0x0067a744 is covered by the semantic global page and ImageLib lifecycle children.
```

### UID 0000VB by-item/ResourceLayoutEntry.md

```cpp
struct ResourceLayoutEntry {
    int left;
    int top;
    int right;
    int bottom;
    unsigned char *pixelData;
    unsigned char *encodedMaskData;
};
```

### UID 00029J by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md

```cpp
// [UID:00029J] no standalone global definition.
// Shared ImageLib load-error/render-suspend state is exact at 0x0069b420, but the final symbol name and linkage are not source-quality. Current IDA bytes at 0x0069b420 are zero; consumers carry the behavioral evidence.
```

## Score And Metadata Disposition

Recommended metadata after implementation callback:

| UID | Metadata recommendation | Reason |
| --- | --- | --- |
| `0000K2` | `COMPLETION:90`, `CONFIDENCE:88`, owner `FILE` unchanged | The family would have constructor/destructor, seven ResourceLayout method bodies, two struct declarations, and exact no-code markers for compiler/data/global artifacts. Confidence remains capped by class/facet declaration and `g_pEPFLib` final pointer type. |
| `00006E` | `87/88` | Class audit now resolves why no standalone declaration is safe and routes to children. |
| `0001US` | `86/90` | Layout facts are exact and marker prevents duplicate layout emission. |
| `0001XR` | `88/93` | Vtable slots and child route are exact. |
| `00031R` | `89/93` | Data bytes and compiler-generated disposition are exact. |
| `0000BY` | `89/88` | Class/facet audit plus child method bodies resolve current empty-emitter role without inventing object layout. |
| `0002KO` | `90/90` | Exact loader behavior now has first-draft source; confidence capped by DATFile seek/open declaration spelling. |
| `0002KP` | `90/91` | Central lookup body is source-ready using accepted EPFTileContext field names. |
| `0002KR` | `90/91` | Stack EPFTileContext wrapper body is exact and small. |
| `0002KS` | `89/90` | Bounds accessor body is exact; orphan old-human callsites remain caller-owner caveat only. |
| `0002KU` | `90/92` | Frame-size accessor body is exact and single-caller semantics are strong. |
| `0002KV` | `90/93` | Count accessor body and unsigned return convention are exact. |
| `0002KW` | `90/92` | Linear scan body has no callees and is source-ready. |
| `0001VT` | `90/92` | 44-byte struct declaration exactly matches loader/destructor/accessor use. |
| `0000QU` | `89/88` | Global remains exact but final type is capped. |
| `0001OQ` | `87/91` | Storage marker closes empty emitter; semantic global carries source route. |
| `0000VB` | `90/92` | 24-byte struct declaration exactly matches lookup/rect/mask behavior. |
| `00029J` | `88/93` | Keep completion capped by name/linkage; current IDB byte correction improves confidence in storage facts. |

Support docs after acceptance:

- `by-file/ResourceLayoutTable.md`: refresh wording so class-backed ResourceLayout methods emit through [UID:0000BY] into `ImageLib.cpp`, while raw no-this helpers remain file-level [UID:0000N5]. No score change required unless validator expects a generated-state note.
- `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`: optionally add a one-paragraph sync that exact children now carry method bodies and the aggregate remains non-emitting. No score change required.
- `by-type/by-struct/ResourceLayoutStore.md` and `ResourceLayoutBucket.md`: no edit needed; current rejection/alias wording is consistent.
- `by-class/List.md`, `by-class/EPFTileContext.md`, `by-class/DATFile.md`: no edit needed; they already provide support vocabulary used by the proposed C++.

## Generated Output Expectation

After implementation and scoped validation/refresh, `auto-generated/NexusTK/render/ImageLib.cpp` should show:

- Existing filled blocks for `ImageLib::ImageLib`, `ImageLib::~ImageLib`, and the ImageLib scalar deleting destructor marker preserved.
- No class body markers for `ImageLib`, `ImageLibLayout`, `ImageLibVtable`, `ImageLibVtableData`, `ResourceLayoutTable`, `g_pEPFLib`, `0x0067a744`, and `0x0069b420`.
- First-draft method bodies for all seven ResourceLayoutTable exact method pages.
- Struct declarations for `ResourceLayoutNameRecord` and `ResourceLayoutEntry`.
- The generated filled count should rise from 3/20 to 20/20 for this file-family row, assuming all 17 markers are accepted and no generator rule suppresses comment-only marker pages.

## Implementation Callback Result

Supervisor accepted this report and B011 implemented it on 2026-06-30. The implementation applied all accepted in-scope claims to by-* docs, refreshed support docs where the current text needed the ImageLib/ResourceLayout split, ran scoped validators with `--wait-generated`, and left no active B011 leases in `tools/leaser/Agents/current_leases.md`.

Generated freshness after validation:

- `auto-generated/NexusTK/render/ImageLib.cpp`: `validator-command-id: 000000002635`, `validator-refreshed-at: 2026-06-30T06:46:27-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- `auto-generated/NexusTK/render/ResourceLayoutTable.cpp`: same generated freshness marker, and still contains only raw helper empty-marker entries for [UID:0002KQ] and [UID:0002KT].
- The generated `ImageLib.cpp` file now contains the accepted class/data/global markers, the seven `ResourceLayoutTable` method bodies, `ResourceLayoutNameRecord`, and `ResourceLayoutEntry`.

Lease state:

- B011 leased the exact in-scope by-* file set before the final required validator batch and released the same set immediately afterward.
- Final release command returned `Success` for all 20 leased by-* paths.

## Claim And Incorporation Ledger

| Claim | Evidence | Implementation action | Status |
| --- | --- | --- | --- |
| MCP was available and current. | `idb_list`/`server_health` on `supervisor_resume_20260629` ok; `get_bytes` on 2026-06-30 reconfirmed current zero bytes around `0x0069b420`. | Preserved MCP session details on `by-file/ImageLib.md` and corrected `00029J` byte evidence. | Applied. |
| ImageLib class declaration is unsafe now. | Constructor/destructor fields exact, but ResourceLayout method family shares object `this+0x0c` with no vtable/base declaration proof. | `by-class/ImageLib.md` now has `87/88`, formal no-class-body marker with `[[CHILDREN]]`, and class audit text. | Applied. |
| ImageLib layout should not emit duplicate struct. | Layout consumed by lifecycle and ResourceLayout methods; no standalone source type observed. | `by-type/by-struct/ImageLibLayout.md` now has `86/90` and a no-standalone-layout marker. | Applied. |
| ImageLib vtable and vtable data are compiler/data artifacts. | Bytes and vtable xrefs exact; scalar deleting destructor child owns source route. | `by-type/by-vtable/ImageLibVtable.md` now has `88/93` and marker with `[[CHILDREN]]`; `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md` now has `89/93` and data marker. | Applied. |
| ResourceLayoutTable is a method-family/facet, not independent object. | No constructor/destructor/vtable/storage; seven methods use ImageLib `m_pEntryList`. | `by-class/ResourceLayoutTable.md` now has `89/88`, formal no-class-body marker with `[[CHILDREN]]`, and class/facet audit text. | Applied. |
| Seven ResourceLayout executable children are source-ready. | Current MCP decompile/callee/xref/boundary evidence; List/EPFTileContext/DATFile docs supply source-facing names. | Inserted first-draft bodies and score updates on all seven child pages: `0002KO 90/90`, `0002KP 90/91`, `0002KR 90/91`, `0002KS 89/90`, `0002KU 90/92`, `0002KV 90/93`, `0002KW 90/92`. | Applied. |
| `ResourceLayoutNameRecord` declaration is exact. | `List(44,10)`, row stride 44, loader fields, destructor frees `entries`, accessors use offsets. | `by-type/by-struct/ResourceLayoutNameRecord.md` now has `90/92`, formal struct declaration, and source declaration proof. | Applied. |
| `ResourceLayoutEntry` declaration is exact. | 24-byte row stride, lookup maps bounds/pixel/mask fields, sentinel supports mask-size computation. | `by-item/ResourceLayoutEntry.md` now has `90/92`, formal struct declaration, and row/sentinel evidence. | Applied. |
| `g_pEPFLib` should not emit a standalone definition. | 231 xrefs and lifecycle writes exact; final pointer type depends on ImageLib/ResourceLayoutTable facet. | `by-global/g_pEPFLib.md` now has `89/88` with marker plus `[[CHILDREN]]`; storage child `0x0067a744-0x0067a748` now has `87/91` and storage marker. | Applied. |
| `ImageLibraryLoadErrorFlag` should not emit a standalone definition. | 132 xrefs to `0x0069b420`, no refs to trailing bytes; current bytes are zero; final name/linkage unresolved. | `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md` now has `88/93`, formal no-standalone-definition marker, and corrected current zero-byte evidence. | Applied. |
| Raw ResourceLayout helpers are out of this family. | Current generated `ImageLib.cpp` empty list excludes `0002KQ` and `0002KT`; file-level [UID:0000N5] owns them. | `by-file/ResourceLayoutTable.md` and aggregate `0x004d0120-0x004d182f` now explicitly preserve class-backed-vs-raw-helper split. Raw helper pages were not edited. | Applied/excluded with reason. |
| Support docs should be refreshed only where needed. | Current support text needed explicit sync for `ResourceLayoutTable` file and aggregate, plus stale score/no-code wording in row/global pages. | Refreshed `by-file/ResourceLayoutTable.md`, `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`, `by-global/g_pEPFLib.md`, `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`, and row type pages. | Applied. |
| Generated reports/C++/tool state/IDA DB/supervisor ledgers/archives/locks must not be hand-edited. | Manual edits were limited to by-* docs and this B011 research report. Validator refreshed generated artifacts itself. | Generated files were read only; no manual generated/tool-state edits were made. | Applied. |

## Implementation Tracking Checklist

- [x] Take leases only for files being edited immediately. Proof: final implementation/validator batch leased only the 20 in-scope by-* files and released all 20 with `Success`.
- [x] Edit `by-file/ImageLib.md`: added empty-emitter family disposition, MCP evidence summary, score `90/88`, generated expectation, raw-helper exclusions, and cross-links.
- [x] Edit `by-class/ImageLib.md`: added class audit and exact marker; score is `87/88`.
- [x] Edit `by-type/by-struct/ImageLibLayout.md`: added marker and support note; score is `86/90`.
- [x] Edit `by-type/by-vtable/ImageLibVtable.md`: added marker with `[[CHILDREN]]`; score is `88/93`; updated gate wording to current parent/file scores.
- [x] Edit `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`: added marker; score is `89/93`.
- [x] Edit `by-class/ResourceLayoutTable.md`: added class/facet audit, marker with `[[CHILDREN]]`, method-body child route, and score `89/88`.
- [x] Edit `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md`: inserted first-draft C++; score is `90/90`; preserved boundary/callee/caller evidence.
- [x] Edit `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`: inserted first-draft C++; score is `90/91`.
- [x] Edit `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md`: inserted first-draft C++; score is `90/91`.
- [x] Edit `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md`: inserted first-draft C++; score is `89/90`.
- [x] Edit `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md`: inserted first-draft C++; score is `90/92`.
- [x] Edit `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md`: inserted first-draft C++; score is `90/93`.
- [x] Edit `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md`: inserted first-draft C++; score is `90/92`.
- [x] Edit `by-type/by-struct/ResourceLayoutNameRecord.md`: inserted struct declaration; score is `90/92`; preserved 44-byte row evidence.
- [x] Edit `by-global/g_pEPFLib.md`: added no-standalone global marker with `[[CHILDREN]]`; score is `89/88`.
- [x] Edit `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`: added storage marker; score is `87/91`.
- [x] Edit `by-item/ResourceLayoutEntry.md`: inserted struct declaration; score is `90/92`; preserved 24-byte row/sentinel evidence.
- [x] Edit `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md`: added marker, corrected current IDB bytes to zero, and set score `88/93`.
- [x] Support-refresh `by-file/ResourceLayoutTable.md`: updated to say class-backed methods emit through `ImageLib.cpp`; raw no-this helpers remain file-level [UID:0000N5].
- [x] Support-refresh `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`: added sync that exact class-backed children now carry method bodies while the aggregate remains non-emitting mixed inventory.
- [x] Do not edit `ResourceLayoutStore`, `ResourceLayoutBucket`, raw helper pages `0002KQ`/`0002KT`, generated files, coverage reports, validator/tool state, IDA DB, supervisor ledgers, archives, or lock files. Proof: raw helpers and excluded support pages were not changed; generated files were validator-refreshed only.
- [x] Run scoped validators from `E:/NTK/GhidraBridge/source-3/project-documentation` for every changed by-* file. Proof: commands `000000002616` through `000000002635`, all exit `0`, `ok:1`.
- [x] Use `--wait-generated` on target/file validators where generated `ImageLib.cpp` freshness matters. Proof: every recorded validator command includes `generated_refresh_command_id` equal to its command id.
- [x] Re-open generated `ImageLib.cpp` read-only after validation. Proof: header shows `validator-command-id: 000000002635`, and content starts with the accepted ImageLib marker, constructor/destructor, and subsequent emitted family content.
- [x] Release every lease immediately after edit/validator batch. Proof: release command returned `Success` for all 20 in-scope by-* files.
- [x] Update this report ledger/checklist with applied/excluded states and proof. Proof: this implementation callback result, ledger, checklist, and validator table are now present.

## Validators For Implementation Callback

All commands were run from `E:/NTK/GhidraBridge/source-3/project-documentation` as:

> Executable block R001 was removed from this report and preserved verbatim in [0000K2-ImageLib-empty-emitter-family-source-quality-removed.md](0000K2-ImageLib-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| File | Command ID | Timestamp | Exit | OK | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/ImageLib.md` | `000000002616` | `2026-06-30T06:43:02-04:00` | 0 | 1 | `000000002616` |
| `by-class/ImageLib.md` | `000000002617` | `2026-06-30T06:43:14-04:00` | 0 | 1 | `000000002617` |
| `by-type/by-struct/ImageLibLayout.md` | `000000002618` | `2026-06-30T06:43:25-04:00` | 0 | 1 | `000000002618` |
| `by-type/by-vtable/ImageLibVtable.md` | `000000002619` | `2026-06-30T06:43:35-04:00` | 0 | 1 | `000000002619` |
| `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md` | `000000002620` | `2026-06-30T06:43:46-04:00` | 0 | 1 | `000000002620` |
| `by-class/ResourceLayoutTable.md` | `000000002621` | `2026-06-30T06:43:58-04:00` | 0 | 1 | `000000002621` |
| `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` | `000000002622` | `2026-06-30T06:44:10-04:00` | 0 | 1 | `000000002622` |
| `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` | `000000002623` | `2026-06-30T06:44:20-04:00` | 0 | 1 | `000000002623` |
| `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `000000002624` | `2026-06-30T06:44:31-04:00` | 0 | 1 | `000000002624` |
| `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` | `000000002625` | `2026-06-30T06:44:41-04:00` | 0 | 1 | `000000002625` |
| `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` | `000000002626` | `2026-06-30T06:44:52-04:00` | 0 | 1 | `000000002626` |
| `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` | `000000002627` | `2026-06-30T06:45:02-04:00` | 0 | 1 | `000000002627` |
| `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` | `000000002628` | `2026-06-30T06:45:13-04:00` | 0 | 1 | `000000002628` |
| `by-type/by-struct/ResourceLayoutNameRecord.md` | `000000002629` | `2026-06-30T06:45:23-04:00` | 0 | 1 | `000000002629` |
| `by-global/g_pEPFLib.md` | `000000002630` | `2026-06-30T06:45:34-04:00` | 0 | 1 | `000000002630` |
| `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` | `000000002631` | `2026-06-30T06:45:45-04:00` | 0 | 1 | `000000002631` |
| `by-item/ResourceLayoutEntry.md` | `000000002632` | `2026-06-30T06:45:56-04:00` | 0 | 1 | `000000002632` |
| `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md` | `000000002633` | `2026-06-30T06:46:06-04:00` | 0 | 1 | `000000002633` |
| `by-file/ResourceLayoutTable.md` | `000000002634` | `2026-06-30T06:46:17-04:00` | 0 | 1 | `000000002634` |
| `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` | `000000002635` | `2026-06-30T06:46:27-04:00` | 0 | 1 | `000000002635` |

Validator warnings were project-wide generated-refresh warnings unrelated to the ImageLib callback, such as existing `autogen_emitter_has_no_code` and `autogen_children_marker_missing` rows on other files. No scoped command failed.

## Unchecked Or Deferred Items

No accepted in-scope item remains unchecked or deferred.

Explicit exclusions preserved by implementation:

- Raw helper pages `0002KQ` and `0002KT`: excluded because they are not current empty emitters in `ImageLib.cpp` and belong to file-level [UID:0000N5].
- Final full `class ImageLib` and `class ResourceLayoutTable` declarations: excluded by no-code proof, not deferred as an unchecked blocker. Current evidence supports child bodies and markers, not a safe standalone class declaration.
- Final original private member spellings and exact `g_pEPFLib` pointer type: confidence caps only. They do not block the implemented method bodies/markers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000K2-ImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000K2-ImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T13:13:05","uid":"0000K2"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000K2-ImageLib-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000K2-ImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000K2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
