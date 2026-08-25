** TARGET-REPORT-UID:0000K3 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000K3 ImageLoaders Empty-Emitter Family Source-Quality Report


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0000K3] `by-file/ImageLoaders.md` as the canonical emitter for the remaining ImageLoaders wrapper/helper family, and clear all 13 current empty markers by adding first-draft C++ to exact source-bearing children or covered-by marker comments to duplicate/index pages.
- Final disposition: implemented in callback on 2026-07-01; supervisor verification/report execution still required.
- Required action: populated formal `RECONSTRUCTION_CPP CODE` blocks on exact child/source pages, added covered-by formal comments for duplicate by-item/global-slot/aggregate emitters, and updated `ImageLoaders.md` plus support docs with the live MCP facts below.
- Confidence: high for owner/emitter route and wrapper behavior; medium-high for final source spelling of local helper names in PCX/DAT and IJG/LodePNG wrapper code.

## Target
- Target UID: [UID:0000K3]
- Target path: `by-file/ImageLoaders.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`, assignment `B009-report-0000K3-ImageLoaders-empty-emitter-family-20260701`.
- Current generated output: `auto-generated/NexusTK/render/ImageLoaders.cpp`
- Report-time generated row before implementation: 16 total emitters, 3 filled, 13 empty, 18.8% complete.
- Implemented generated row after validator refresh: 16 total emitters, 16 filled, 0 empty, 100.0% complete.
- Report-time metadata: `COMPLETION:91`, `CONFIDENCE:87`, `CANONICAL_OWNER:FILE`, proposed path `NexusTK/render/`.
- Implemented metadata: `COMPLETION:93`, `CONFIDENCE:90`, `CANONICAL_OWNER:FILE`, proposed path `NexusTK/render/`.

## Current Target State
- At report time, `ImageLoaders.cpp` contained filled C++ for [UID:0002TJ] `DecodeZpfFpfToTileContext`, [UID:0002TK] `DecodeFpfToTileContext`, and [UID:0002TM] `Decode8BitBmpToTileContext`.
- The report-time empty markers were [UID:0002ZF], [UID:0000U9], [UID:0000UD], [UID:0000UZ], [UID:000314], [UID:000315], [UID:000175], [UID:0002TL], [UID:0002TN], [UID:00032P], [UID:00032O], [UID:0001F1], and [UID:00027L]. After implementation and validator refresh, `auto-generated/NexusTK/render/ImageLoaders.cpp` contains no `Empty Emitter Marker` text.
- Existing docs already route these targets to [UID:0000K3]. No ownership move is recommended.
- Existing blockers that should not be copied forward unchanged: "final source signature/name not known" is no longer sufficient by itself for first-draft C++ once the child has a valid emitter route, direct behavior, and support types. This report therefore supplies formal draft insertion text.

## Supervisor Active Recheck
- The supervisor requested a report-only research pass for [UID:0000K3] from the empty-emitter priority queue.
- IDA MCP evidence was mandatory. MCP session `supervisor_resume_20260629` was available, `idb_list` returned one active IDB, and `server_health` returned `status: ok`, `auto_analysis_ready: true`, and `hexrays_ready: true`.
- No by-* docs, generated files, queues, coverage reports, validator state, supervisor ledgers, archives, or IDA DB state were edited.

## Inference Research Guidance Check
- `by-structure.md` and the project-level `ntk-b-agent-workflow` require narrow, schema-current MCP calls, current generated-output review, and no fallback-only report. This report uses exact lookup/decompile/xref/callee/bytes/insn queries for the target ranges only.
- IDA fact, documentation evidence, and inference are separated below. Decompiler names such as `sub_4A17B0` are not treated as source names; first-draft names use the current by-* source-facing names where available.
- Wave2/Wave3 references in DIBitmap support docs are treated as historical support notes only. They do not override current by-* metadata, current generated output, or live MCP.

## Heuristic / Inference Reanalysis And Validation
- Duplicate emitters: [UID:0000UZ], [UID:0000U9], and [UID:0000UD] are by-item aliases for exact by-memory functions [UID:000314], [UID:000315], and [UID:0001F1]. They should stop producing empty markers by carrying formal covered-by comments, not duplicate bodies.
- Aggregate emitter: [UID:000175] spans multiple exact child wrappers. It should remain an emitting index only if its formal block contains a covered-by-children marker comment. The bodies belong to exact child pages.
- JPEG marker storage: [UID:0002ZF] is the semantic source global; [UID:00027L] is the exact memory slot. Emit one source declaration on [UID:0002ZF] and a covered-by storage comment on [UID:00027L] to avoid duplicate declarations.
- PCX helpers: [UID:000314], [UID:000315], and [UID:0001F1] have direct call-chain evidence, exact ranges, and enough DIBitmap/PCX behavior to receive first-draft source C++. Local DAT/string wrapper type names remain descriptive, so scores should rise modestly but not to final/perfect confidence.
- JPEG wrappers: [UID:0002TL] and [UID:0002TN] are duplicated IJG memory-decode wrappers over embedded JPF and raw JPEG buffers. Use IJG/libjpeg names in source-shaped first drafts while keeping LibJPEG itself imported through its third-party owner.
- PNG wrappers: [UID:00032P] and [UID:00032O] are project wrapper code over LodePNG file/memory front ends. They should not use third-party import directives; LodePNG internals already belong to [UID:0000KW].
- Raw function status: live IDA reports `0x004d0c60` is not a modeled function, but bounded instruction scan shows a complete `push ebp` through `retn 8` helper. Do not edit IDA DB in this report-only pass; document the raw-helper state and still populate first-draft C++ on [UID:00032P].
- Rejected owners: DIBitmap owns the DIBitmap class, EPFTileContext owns its context methods/fields, LibJPEG and LodePNG own vendored library internals, ProfileStorage/UserLookPane/MiniMap/MainMenu/StartupWindow own callers. None outranks ImageLoaders for these project-facing decode wrappers.

## Evidence Standards Used
- IDA MCP tools used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `insn_query`, `xrefs_to`, `callees`, and `get_bytes`.
- Documentation checked: target by-file, generated `ImageLoaders.cpp`, each empty marker doc, EPFTileContext file/class support, DIBitmap file/class/layout support, LibJPEG/LodePNG file pages, generated tracker/coverage reports, and B-agent incorporation tracker rows for prior ImageLoaders callbacks.
- Negative evidence checked: zero xrefs for [UID:000175], [UID:00032P], [UID:00032O]; no modeled function at `0x004d0c60`; no ownership evidence moving wrappers into feature callers or third-party files.

## Evidence Checked
- MCP function facts: `lookup_funcs` returned `sub_4A17B0` size `0xf8`, `sub_4A18B0` size `0x25c`, `sub_549410` size `0x206`, `sub_4D05F0` size `0x133`, `sub_4D07B0` size `0x1f7`, `sub_4D0A90` size `0x1c8`, `sub_4D0D90` size `0x1ba`; `0x004d0c60` returned `Not a function`.
- MCP byte facts: `get_bytes 0x0066db3c size 4` returned `ff d9 00 00`; PNG constants at `0x61c35c` and `0x6104cc` are 255.0f and 32.0f; `0x004d0c60` bytes cover a complete stdcall helper ending `c2 08 00`.
- MCP xref facts: `LoadPcxImage` has 12 callers from `0x581100` and raw `0x5818f1`-family code; `CreateDIBitmapFromPcxBuffer` has one caller from `LoadPcxImage`; `DecodePcxToRgb565Buffer` has one caller from the DIB factory; JPF has ProfileStorage and UserLook callers; raw JPEG has one MiniMap caller; aggregate and PNG wrappers have zero direct xrefs; JPEG EOI marker has one data xref from `0x004e4e70`.
- MCP callee facts: PCX loader uses string/wide conversion, DAT entry/read helpers, and the DIB factory; PCX factory calls `DecodePcxToRgb565Buffer`, allocation, `CreateDIBSection`, free, and memmove; JPEG wrappers call IJG create/read/start/read_scanlines/finish/destroy plus `sub_4E7030`; PNG wrappers call LodePNG front ends, `AllocateRgb16PixelsWithAlpha`, free, and `NormalizePostDecodePixels`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000K3-01 | [UID:0000K3] remains the canonical file/emitter for the empty ImageLoaders family. | High | Current metadata, generated route, child docs, MCP call/caller families. | `by-file/ImageLoaders.md` Status, Proposed Contents, Evidence, Ownership Decision, Open Questions, Changes | incorporate | applied |
| C-0002ZF-01 | Emit one file-static JPEG EOI marker declaration on [UID:0002ZF]. | High | Bytes `ff d9 00 00`; callback `0x004e4e70` writes pointer to `unk_66DB3C` and length 2; `0x004e7030` installs callback. | `by-global/ImageDecodeJpegEoiMarker.md` metadata, formal C++, Role, Score Rationale, Changes | incorporate | applied |
| C-00027L-01 | [UID:00027L] is covered storage/padding evidence for [UID:0002ZF], not a second source declaration. | High | Same bytes/range; semantic duplicate; source should not declare marker twice. | `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md` formal C++, Summary, Changes | incorporate | applied |
| C-ITEM-ALIASES-01 | [UID:0000UZ], [UID:0000U9], and [UID:0000UD] should carry covered-by exact-child marker comments. | High | by-item docs duplicate exact by-memory pages and generated emits both. | `by-item/LoadPcxImage_004A17B0.md`, `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`, `by-item/DecodePcxToRgb565Buffer_00549410.md` formal C++ and Changes | incorporate | applied |
| C-000314-01 | [UID:000314] is first-draft C++ ready as `LoadPcxImage`. | Medium-high | MCP decompile/xrefs, current item/memory docs, DIBitmap/DAT relationship. | `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md` metadata, formal C++, Status, Score Rationale, Changes | incorporate | applied |
| C-000315-01 | [UID:000315] is first-draft C++ ready as `CreateDIBitmapFromPcxBuffer`. | High | MCP decompile, one caller, DIBitmap layout support, row-copy behavior. | `by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md` metadata, formal C++, Status, Parent Gate, Score Rationale, Changes | incorporate | applied |
| C-0001F1-01 | [UID:0001F1] is first-draft C++ ready as `DecodePcxToRgb565Buffer`. | High | MCP decompile, palette marker, RLE loop, transparent index, RGB565 packing. | `by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md` metadata, formal C++, Status, Reconstruction Notes, Changes | incorporate | applied |
| C-000175-01 | [UID:000175] remains an aggregate/index and should emit only a covered-by-children marker comment. | High | Child split, generated filled children, zero xrefs to aggregate start. | `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` metadata, formal C++, Status, Ownership Decision, Changes | incorporate | applied |
| C-0002TL-01 | [UID:0002TL] is first-draft C++ ready as JPF-to-EPFTileContext wrapper. | High | MCP decompile/callees/xrefs, `"JPF"` string, IJG memory source, RGB565 conversion. | `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md` metadata, formal C++, Status, Open Questions, Changes | incorporate | applied |
| C-0002TN-01 | [UID:0002TN] is first-draft C++ ready as raw JPEG-buffer wrapper. | High | MCP decompile/callees/xref, same IJG pipeline without `"JPF"` guard. | `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md` metadata, formal C++, Status, Open Questions, Changes | incorporate | applied |
| C-00032P-01 | [UID:00032P] is first-draft C++ ready despite raw/non-modeled IDA function state. | Medium-high | Bounded `insn_query` complete helper, LodePNG file front end, EPF alpha conversion, zero xrefs. | `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md` metadata, formal C++, Status, Score Rationale, Changes | incorporate | applied |
| C-00032O-01 | [UID:00032O] is first-draft C++ ready as DAT/resource PNG wrapper. | High | MCP decompile, LodePNG memory front end, DAT read staging, EPF alpha conversion, cleanup. | `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md` metadata, formal C++, Status, Score Rationale, Changes | incorporate | applied |

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| global JPEG EOI marker | [UID:0002ZF] `by-global/ImageDecodeJpegEoiMarker.md` | semantic source declaration | TRUE | 0000K3 | `88/92` -> recommend `90/93` | first-draft declaration |
| item alias | [UID:0000UZ] `by-item/LoadPcxImage_004A17B0.md` | by-item duplicate | TRUE | 0000K3 | keep `87/90` or `88/90` | covered by [UID:000314] |
| item alias | [UID:0000U9] `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md` | by-item duplicate | TRUE | 0000K3 | keep `86/91` | covered by [UID:000315] |
| item alias | [UID:0000UD] `by-item/DecodePcxToRgb565Buffer_00549410.md` | by-item duplicate | TRUE | 0000K3 | keep `85/90` or `86/90` | covered by [UID:0001F1] |
| `0x004a17b0-0x004a18a8` | [UID:000314] `LoadPcxImage` | PCX DAT loader | TRUE | 0000K3 | `87/90` -> recommend `88/90` | first-draft C++ |
| `0x004a18b0-0x004a1b0c` | [UID:000315] `CreateDIBitmapFromPcxBuffer` | PCX-to-DIB factory | TRUE | 0000K3 | `87/90` -> recommend `89/91` | first-draft C++ |
| `0x00549410-0x00549616` | [UID:0001F1] `DecodePcxToRgb565Buffer` | PCX/RLE/RGB565 decoder | TRUE | 0000K3 | `86/90` -> recommend `89/91` | first-draft C++ |
| `0x004d05f0-0x004d0f4a` | [UID:000175] `ImageDecodeWrappers` | mixed aggregate/index | TRUE | 0000K3 | `85/88` -> recommend `88/89` | covered by exact children |
| `0x004d07b0-0x004d09a7` | [UID:0002TL] `DecodeJpfImageToTileContext` | JPF embedded-JPEG wrapper | TRUE | 0000K3 | `85/88` -> recommend `88/89` | first-draft C++ |
| `0x004d0a90-0x004d0c58` | [UID:0002TN] `DecodeJpegBufferToTileContext` | raw JPEG wrapper | TRUE | 0000K3 | `85/88` -> recommend `88/89` | first-draft C++ |
| `0x004d0c60-0x004d0d89` | [UID:00032P] `DecodePngFileToTileContext` | raw PNG file wrapper | TRUE | 0000K3 | `85/88` -> recommend `88/89` | first-draft C++ |
| `0x004d0d90-0x004d0f4a` | [UID:00032O] `DecodePngResourceToTileContext` | PNG DAT/resource wrapper | TRUE | 0000K3 | `86/88` -> recommend `88/89` | first-draft C++ |
| `0x0066db3c-0x0066db40` | [UID:00027L] `ImageDecodeJpegEoiMarkerSlot` | exact data slot/alignment | TRUE | 0000K3 | keep `88/92` | covered by [UID:0002ZF] |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004a17b0` | 12 xrefs: six from `sub_581100`, six from raw `0x5818f1`-family code | startup/update PCX asset loader, still ImageLoaders-owned dependency |
| `0x004a18b0` | one xref from `0x004a1876` in `LoadPcxImage` | direct PCX loader child |
| `0x00549410` | one xref from `0x004a18f5` in DIB factory | direct PCX factory child |
| `0x004d05f0` | zero xrefs | aggregate/raw wrapper index, not caller-owned |
| `0x004d07b0` | xrefs from `0x5063e0` and `0x59f610` | ProfileStorage/UserLook consume JPF, do not own codec |
| `0x004d0a90` | one xref from `0x4543f0` | MiniMap consumes raw JPEG, does not own codec |
| `0x004d0c60` | zero xrefs, not an IDA function | raw PNG file wrapper remains source-shaped but not directly reached in current IDB |
| `0x004d0d90` | zero xrefs | modeled PNG resource wrapper remains source-shaped but not directly reached in current IDB |
| `0x0066db3c` | data xref from `0x004e4e92` | IJG source-manager callback fallback EOI marker |

## Ranked Ownership Analysis
### 1. [UID:0000K3] ImageLoaders
- Evidence for: all wrappers are file-level image decode helpers; current child metadata routes them to [UID:0000K3]; generated output route is `NexusTK/render/ImageLoaders.cpp`; prior accepted ZPF/FPF/BMP work already emits here; live MCP shows cross-feature callers rather than feature-owned logic.
- Evidence against: PCX helpers touch DIBitmap and DAT/string helpers; JPEG/PNG wrappers call third-party libraries. These are dependencies, not stronger owners.
- Decision: keep as canonical owner/emitter.

### 2. DIBitmap / EPFTileContext support owners
- Evidence for: PCX factory constructs DIBitmap; JPEG/PNG/ZPF/BMP wrappers fill EPFTileContext.
- Evidence against: support docs explicitly route PCX free helpers and image decode wrappers to ImageLoaders; support classes own data structures and methods, not file-level codec wrappers.
- Decision: support docs should be updated with producer evidence only.

### 3. LibJPEG / LodePNG third-party owners
- Evidence for: wrappers call IJG/libjpeg and LodePNG APIs.
- Evidence against: project wrappers are not vendored library source. Import directives belong to LibJPEG/LodePNG source-bearing pages, not these ImageLoaders wrapper pages.
- Decision: no third-party import directive for [UID:0000K3] or children in this report.

## Source Placement
- Recommended source file: `NexusTK/render/ImageLoaders.cpp`.
- Source contents: PCX DAT loader/factory/decoder, JPEG EOI marker, ZPF/FPF/JPF/BMP/JPEG/PNG wrappers, and small local conversion helpers/structs used only by these wrappers.
- Rejected placements: `DIBitmap.cpp` for free PCX helpers, `EPFTileContext.cpp` for decoder wrappers, feature caller files for ProfileStorage/UserLook/MiniMap/MainMenu/StartupWindow, and third-party LibJPEG/LodePNG files for project wrappers.
- Remaining uncertainty: exact original file split could have been `PcxDecode.cpp` plus a broader ImageLoaders file. The current generated route and by-file page already select [UID:0000K3], so no owner move is recommended.

## Range / Split / Padding / Reclassification Analysis
- [UID:000175] is a mixed aggregate over exact wrapper children. It should not duplicate child bodies.
- [UID:00032P] has raw source-looking bytes at `0x004d0c60-0x004d0d89` but no IDA function object. Do not force IDA changes during this report-only pass; the by-memory page can still hold the formal first-draft C++ because bytes and behavior are bounded.
- [UID:0002ZF] vs [UID:00027L] is a semantic-global/exact-slot duplicate. Emit declaration once on [UID:0002ZF]; use [UID:00027L] as exact storage/alignment evidence.
- The two trailing zero bytes at `0x0066db3e-0x0066db3f` are storage/alignment bytes for the marker slot, not a separate source object.

## Negative Evidence Summary
- Zero xrefs to [UID:000175], [UID:00032P], and [UID:00032O] do not prove no source. They prove no current direct caller/pointer route in the IDB; the bytes still form source-shaped wrapper helpers.
- PCX caller ownership is weaker than ImageLoaders ownership because the same `LoadPcxImage` helper is called from startup/update raw and modeled paths and contains the image-file pipeline itself.
- JPF/ProfileStorage, JPF/UserLook, and JPEG/MiniMap callers consume decoded image contexts. They do not contain codec-specific logic after the call.
- LodePNG/LibJPEG source ownership applies to library internals only. The project wrappers allocate EPFTileContext and convert pixels, so they remain ImageLoaders code.

## First-Draft C++ Recommendation
Eligible for draft C++: [UID:0002ZF], [UID:000314], [UID:000315], [UID:0001F1], [UID:0002TL], [UID:0002TN], [UID:00032P], and [UID:00032O].

Eligible for covered-by formal marker comments: [UID:00027L], [UID:0000UZ], [UID:0000U9], [UID:0000UD], and [UID:000175].

Third-party import directive: not applicable. ImageLoaders wrappers are project code over third-party APIs; LibJPEG and LodePNG import handling remains in their own by-file/by-memory pages.

Recommended formal insertion text:

### [UID:0002ZF] `by-global/ImageDecodeJpegEoiMarker.md`
```cpp
static unsigned char s_jpegEoiMarker[2] = { 0xff, 0xd9 };
```

### [UID:00027L] `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md`
```cpp
// Exact storage for [UID:0002ZF] ImageDecodeJpegEoiMarker is emitted by the
// by-global declaration. The two trailing zero bytes are storage/alignment
// bytes and are not a separate source object.
```

### [UID:0000UZ] `by-item/LoadPcxImage_004A17B0.md`
```cpp
// Emitted code for LoadPcxImage is covered by [UID:000314].
```

### [UID:0000U9] `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`
```cpp
// Emitted code for CreateDIBitmapFromPcxBuffer is covered by [UID:000315].
```

### [UID:0000UD] `by-item/DecodePcxToRgb565Buffer_00549410.md`
```cpp
// Emitted code for DecodePcxToRgb565Buffer is covered by [UID:0001F1].
```

### [UID:000175] `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`
```cpp
// This aggregate is an index over exact ImageLoaders wrapper children. Emitted
// bodies are carried by [UID:0002TJ], [UID:0002TK], [UID:0002TL], [UID:0002TM],
// [UID:0002TN], [UID:00032P], and [UID:00032O].
```

### [UID:000314] `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md`
```cpp
DIBitmap *LoadPcxImage(HDC hdc, const char *fileName, int transparentIndex)
{
    NtkString localName(fileName);
    NtkWideString archiveName(localName);

    if (!HasDATEntry(archiveName.c_str())) {
        return nullptr;
    }

    DATFileBuffer fileBuffer;
    fileBuffer.Open(archiveName.c_str());

    char *pcxBytes = static_cast<char *>(fileBuffer.GetBytes());
    const int pcxByteCount = fileBuffer.GetByteCount();
    fileBuffer.CloseRead();

    DIBitmap *bitmap = nullptr;
    if (pcxBytes != nullptr) {
        bitmap = CreateDIBitmapFromPcxBuffer(
            hdc,
            pcxBytes,
            pcxByteCount,
            transparentIndex);
    }

    return bitmap;
}
```

### [UID:000315] `by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md`
```cpp
DIBitmap *CreateDIBitmapFromPcxBuffer(
    HDC hdc,
    char *pcxBytes,
    int pcxByteCount,
    int transparentIndex)
{
    unsigned short *decodedPixels = nullptr;
    int width = 0;
    int height = 0;

    if (DecodePcxToRgb565Buffer(
            pcxBytes,
            pcxByteCount,
            &decodedPixels,
            &width,
            &height,
            transparentIndex,
            nullptr) < 0 ||
        width <= 0 ||
        height <= 0 ||
        decodedPixels == nullptr) {
        return nullptr;
    }

    DIBitmap *bitmap = new DIBitmap(hdc, width, height);
    if (bitmap == nullptr || bitmap->GetBits() == nullptr) {
        delete bitmap;
        free(decodedPixels);
        return nullptr;
    }

    const int copyWidth = bitmap->GetWidth() < width ? bitmap->GetWidth() : width;
    const int copyHeight = bitmap->GetHeight() < height ? bitmap->GetHeight() : height;

    unsigned char *dst = static_cast<unsigned char *>(bitmap->GetBits());
    for (int row = 0; row < copyHeight; ++row) {
        memmove(
            dst,
            decodedPixels + width * row,
            2 * copyWidth);
        dst += 2 * bitmap->GetAlignedWidth();
    }

    free(decodedPixels);
    return bitmap;
}
```

### [UID:0001F1] `by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md`
```cpp
#pragma pack(push, 1)
struct PcxHeader {
    unsigned char manufacturer;
    unsigned char version;
    unsigned char encoding;
    unsigned char bitsPerPixel;
    unsigned short xMin;
    unsigned short yMin;
    unsigned short xMax;
    unsigned short yMax;
    unsigned char reserved[112];
};
#pragma pack(pop)

int DecodePcxToRgb565Buffer(
    char *pcxBytes,
    int pcxByteCount,
    unsigned short **outPixels,
    int *outWidth,
    int *outHeight,
    int transparentIndex,
    const unsigned char *remapTable)
{
    if (*outPixels != nullptr) {
        return -1;
    }

    if (pcxBytes[pcxByteCount - 769] != 0x0c) {
        return -1;
    }

    const PcxHeader *header = reinterpret_cast<const PcxHeader *>(pcxBytes);
    if (header->bitsPerPixel != 8) {
        return -1;
    }

    *outWidth = header->xMax - header->xMin + 1;
    *outHeight = header->yMax - header->yMin + 1;

    const int totalPixels = *outWidth * *outHeight;
    *outPixels = static_cast<unsigned short *>(malloc(2 * totalPixels));
    if (*outPixels == nullptr) {
        return -1;
    }

    const unsigned char *rle = reinterpret_cast<unsigned char *>(pcxBytes + 128);
    const unsigned char *palette =
        reinterpret_cast<unsigned char *>(pcxBytes + pcxByteCount - 768);
    const int encodedRowWidth = *outWidth + (*outWidth & 1);

    int outputIndex = 0;
    int column = 1;
    int runLength = 0;
    unsigned char value = 0;

    while (outputIndex < totalPixels) {
        if (runLength <= 0) {
            value = *rle++;
            runLength = 1;
            if ((value & 0xc0) == 0xc0) {
                runLength = value & 0x3f;
                value = *rle++;
            }
            continue;
        }

        unsigned char paletteIndex = value;
        if (remapTable != nullptr) {
            paletteIndex = remapTable[4 * paletteIndex];
        }

        const bool paddingColumn = ((*outWidth & 1) != 0 && column == encodedRowWidth);
        if (!paddingColumn) {
            if (transparentIndex >= 0 && transparentIndex == paletteIndex) {
                (*outPixels)[outputIndex] = 0;
            } else {
                const unsigned char red = palette[3 * paletteIndex + 0];
                const unsigned char green = palette[3 * paletteIndex + 1];
                const unsigned char blue = palette[3 * paletteIndex + 2];
                (*outPixels)[outputIndex] =
                    static_cast<unsigned short>(
                        (blue >> 3) |
                        ((green & 0xfc) << 3) |
                        ((red & 0xf8) << 8));
            }
            ++outputIndex;
        }

        --runLength;
        ++column;
        if (column > encodedRowWidth) {
            column = 1;
        }
    }

    return 0;
}
```

### [UID:0002TL] `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md`
Insert the local JPEG helper plus the JPF wrapper in this formal block. [UID:0002TN] can then call the helper from the later exact child block in generated order.

```cpp
static unsigned short PackRgb888ToRgb565(
    unsigned char red,
    unsigned char green,
    unsigned char blue)
{
    return static_cast<unsigned short>(
        (blue >> 3) |
        ((green & 0xfc) << 3) |
        ((red & 0xf8) << 8));
}

static void DecodeJpegMemoryToTileContext(
    const unsigned char *jpegData,
    int jpegDataSize,
    EPFTileContext *destination)
{
    jpeg_decompress_struct cinfo;
    JpegErrorManager errorManager;

    cinfo.err = jpeg_std_error(&errorManager.pub);
    errorManager.pub.error_exit = JpegErrorExit;

    if (setjmp(errorManager.setjmpBuffer) != 0) {
        jpeg_destroy_decompress(&cinfo);
        return;
    }

    jpeg_create_decompress(&cinfo);
    jpeg_mem_src(&cinfo, jpegData, jpegDataSize);
    jpeg_read_header(&cinfo, TRUE);
    cinfo.out_color_space = JCS_RGB;
    jpeg_start_decompress(&cinfo);

    const int width = static_cast<int>(cinfo.output_width);
    const int height = static_cast<int>(cinfo.output_height);
    destination->AllocateRgb16Pixels(width, height);

    unsigned short *dst = static_cast<unsigned short *>(destination->pixelData);
    const int rowStride = 3 * width;
    JSAMPARRAY scanline = (*cinfo.mem->alloc_sarray)(
        reinterpret_cast<j_common_ptr>(&cinfo),
        JPOOL_IMAGE,
        rowStride,
        1);

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, scanline, 1);
        const unsigned char *src = scanline[0];
        for (int x = 0; x < width; ++x) {
            *dst++ = PackRgb888ToRgb565(src[0], src[1], src[2]);
            src += 3;
        }
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    destination->NormalizePostDecodePixels();
}

void DecodeJpfImageToTileContext(
    const unsigned char *jpfData,
    int jpfDataSize,
    EPFTileContext *destination)
{
    if (strncmp(reinterpret_cast<const char *>(jpfData), "JPF", 4) != 0) {
        return;
    }

    DecodeJpegMemoryToTileContext(jpfData + 4, jpfDataSize, destination);
}
```

### [UID:0002TN] `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md`
```cpp
void DecodeJpegBufferToTileContext(
    const unsigned char *jpegData,
    int jpegDataSize,
    EPFTileContext *destination)
{
    DecodeJpegMemoryToTileContext(jpegData, jpegDataSize, destination);
}
```

### [UID:00032P] `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md`
Insert the local PNG conversion helper plus the file-wrapper body in this formal block. [UID:00032O] can then call the helper from the later exact child block in generated order.

```cpp
static void CopyRgba32ToRgb565AndAlpha(
    const unsigned char *rgba,
    unsigned int width,
    unsigned int height,
    EPFTileContext *destination)
{
    destination->AllocateRgb16PixelsWithAlpha(width, height);

    unsigned short *dstPixels =
        static_cast<unsigned short *>(destination->pixelData);
    unsigned short *dstAlpha = destination->alphaData;

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            const unsigned int pixel = x + width * y;
            const unsigned char red = rgba[4 * pixel + 0];
            const unsigned char green = rgba[4 * pixel + 1];
            const unsigned char blue = rgba[4 * pixel + 2];
            const unsigned char alpha = rgba[4 * pixel + 3];

            *dstPixels++ = static_cast<unsigned short>(
                (blue >> 3) |
                ((green & 0xfc) << 3) |
                ((red & 0xf8) << 8));
            *dstAlpha++ = static_cast<unsigned short>(
                32 - static_cast<unsigned int>((static_cast<float>(alpha) / 255.0f) * 32.0f));
        }
    }
}

void __stdcall DecodePngFileToTileContext(
    const char *fileName,
    EPFTileContext *destination)
{
    unsigned char *rgba = nullptr;
    unsigned int width = 0;
    unsigned int height = 0;

    lodepng_decode32_file(&rgba, &width, &height, fileName);
    CopyRgba32ToRgb565AndAlpha(rgba, width, height, destination);

    free(rgba);
    destination->NormalizePostDecodePixels();
}
```

### [UID:00032O] `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`
```cpp
int __stdcall DecodePngResourceToTileContext(
    const wchar_t *resourceName,
    EPFTileContext *destination)
{
    DATFileBuffer fileBuffer;
    fileBuffer.Open(resourceName);

    const int byteCount = fileBuffer.GetByteCount();
    unsigned char *fileBytes =
        static_cast<unsigned char *>(NtkAlloc(byteCount));
    fileBuffer.Read(fileBytes, byteCount);

    unsigned char *rgba = nullptr;
    unsigned int width = 0;
    unsigned int height = 0;

    if (lodepng_decode32(&rgba, &width, &height, fileBytes, byteCount) == 0) {
        CopyRgba32ToRgb565AndAlpha(rgba, width, height, destination);
    }

    NtkFree(fileBytes);
    free(rgba);
    destination->NormalizePostDecodePixels();
    return fileBuffer.Close();
}
```

Reason the code preserves original behavior:
- PCX: preserves input-output pointer guard, palette marker check at `pcxByteCount - 769`, 8-bit header guard, inclusive width/height, allocation of `2 * width * height`, PCX RLE high-bit handling, odd-width padding suppression, optional remap-table first-byte lookup, transparent index zeroing, RGB565 packing, DIBSection row copy using aligned stride, and decoded-buffer free.
- JPEG/JPF: preserves `"JPF"` guard, `jpfData + 4` source pointer, IJG version-62 decompression shape, memory-source helper route, RGB output, one scanline at a time, RGB565 packing, and post-decode normalization.
- PNG: preserves LodePNG file/memory front-end split, allocation with alpha plane, RGBA to RGB565 packing, `32 - int(alpha / 255.0f * 32.0f)` alpha transform, decoded-buffer free, and post-decode normalization.
- Marker: preserves the two authored marker bytes and treats the two trailing bytes as storage/alignment.

Inferred source names/types:
- `NtkString`, `NtkWideString`, `DATFileBuffer`, `HasDATEntry`, `NtkAlloc`, and `NtkFree` are descriptive project-local names for currently documented string/DAT/allocation helpers. These are the reason PCX/DAT scores should not exceed the high-80s/low-90s yet.
- `JpegErrorManager`, `JpegErrorExit`, and `jpeg_mem_src` are source-facing wrappers around the documented IJG error/source-manager route, including `0x004e7030` and the [UID:0002ZF] EOI marker callback.

## Recommended Target Doc Changes
- `by-file/ImageLoaders.md`: update completion/confidence to approximately `93/90` after implementation if validators generate all markers as non-empty. Add that this file emits the remaining PCX helpers, JPF/raw JPEG wrappers, PNG file/resource wrappers, and JPEG EOI marker declaration through [UID:0000K3].
- Preserve the caveat that the exact original source split might have had a narrower PCX helper file, but current reconstruction route remains `NexusTK/render/ImageLoaders.cpp`.
- Record that [UID:000175] is an aggregate/index whose emitted bodies are carried by exact children.
- Record that [UID:00032P] is raw source-shaped code with no IDA function object or xrefs, but bounded bytes justify first-draft code.

## Recommended Support Doc Changes
- `by-global/ImageDecodeJpegEoiMarker.md`: raise to `90/93`, add formal marker declaration, preserve callback/use evidence.
- `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md`: keep exact range/bytes and add covered-by formal comment.
- `by-item/LoadPcxImage_004A17B0.md`, `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`, `by-item/DecodePcxToRgb565Buffer_00549410.md`: add covered-by comments pointing to exact by-memory children and keep the docs as item aliases/support evidence.
- `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md`: add first-draft C++, update evidence for DAT/string helper descriptive names and score to `88/90`.
- `by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md`: add first-draft C++, update DIBitmap layout/row-copy evidence and score to `89/91`.
- `by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md`: add first-draft C++, update PCX header/RLE/palette evidence and score to `89/91`.
- `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`: add aggregate covered-by-children comment and score to `88/89`.
- `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md`, `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md`, `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md`, and `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`: add first-draft C++, update scores to `88/89`.
- `by-class/EPFTileContext.md` and `by-file/EPFTileContext.md`: optional support update only if supervisor wants producer evidence expanded. Existing evidence already supports `pixelData`, `alphaData`, `AllocateRgb16Pixels`, `AllocateRgb16PixelsWithAlpha`, and `NormalizePostDecodePixels`.
- `by-file/DIBitmap.md`, `by-class/DIBitmap.md`, and `by-type/by-struct/DIBitmapLayout.md`: optional support update for PCX factory first-draft C++ producer evidence. Existing docs already route PCX helpers to ImageLoaders and confirm layout.

## Score And Metadata Recommendation
- [UID:0000K3] `ImageLoaders.md`: `91/87` -> recommend `93/90`; metadata unchanged (`CANONICAL_OWNER:FILE`).
- [UID:0002ZF]: `88/92` -> `90/93`, owner/emitter unchanged.
- [UID:000314]: `87/90` -> `88/90`, owner/emitter unchanged.
- [UID:000315]: `87/90` -> `89/91`, owner/emitter unchanged.
- [UID:0001F1]: `86/90` -> `89/91`, owner/emitter unchanged.
- [UID:000175]: `85/88` -> `88/89`, owner/emitter unchanged but C++ is covered-by marker only.
- [UID:0002TL], [UID:0002TN], [UID:00032P], [UID:00032O]: raise to `88/89`; owner/emitter unchanged.
- [UID:00027L]: keep `88/92`; covered-by marker avoids duplicate source declaration.
- by-item alias pages: keep current owner/emitter and scores or increase by at most one point only for duplicate-emitter cleanup; do not duplicate bodies.
- Score not higher because PCX string/DAT local type names and final IJG/local helper spelling remain inferred, and [UID:00032P] remains raw/non-modeled in IDA.

## Open Questions With Attempted Resolution
- Exact original PCX/DAT wrapper type names: MCP identifies the calls and virtual object behavior, but current docs do not prove the original names. Best supported action is descriptive first-draft names in formal C++; this limits PCX loader confidence.
- Whether `JPF` size should pass `jpfDataSize` or `jpfDataSize - 4`: decompile shows `sub_4E7030(cinfo, Str1 + 4, a2)`, so the first-draft uses the full second argument as observed.
- Whether PNG file helper should check LodePNG error return: raw bytes do not branch on `sub_443C40` return before allocation/conversion, so first-draft omits a guard to preserve behavior.
- Whether the JPEG EOI marker should be `const`: storage is in writable data and callback takes a mutable pointer route. Use non-const `static unsigned char` for first draft; do not claim final constness.

## Validator Results
- Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`; all exited `0` with `ok: 1`.
- `000000003428` at `2026-07-01T05:37:28-04:00`: `python .\tools\validator.py --mode file --file by-global/ImageDecodeJpegEoiMarker.md --apply --queue-timeout 240`.
- `000000003430` at `2026-07-01T05:37:34-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md --apply --queue-timeout 240`.
- `000000003432` at `2026-07-01T05:37:45-04:00`: `python .\tools\validator.py --mode file --file by-item/LoadPcxImage_004A17B0.md --apply --queue-timeout 240`.
- `000000003433` at `2026-07-01T05:37:57-04:00`: `python .\tools\validator.py --mode file --file by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md --apply --queue-timeout 240`.
- `000000003434` at `2026-07-01T05:37:59-04:00`: `python .\tools\validator.py --mode file --file by-item/DecodePcxToRgb565Buffer_00549410.md --apply --queue-timeout 240`.
- `000000003435` at `2026-07-01T05:38:00-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md --apply --queue-timeout 240`.
- `000000003436` at `2026-07-01T05:38:02-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md --apply --queue-timeout 240`.
- `000000003437` at `2026-07-01T05:38:04-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md --apply --queue-timeout 240`.
- `000000003438` at `2026-07-01T05:38:06-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md --apply --queue-timeout 240`.
- `000000003439` at `2026-07-01T05:38:08-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md --apply --queue-timeout 240`.
- `000000003440` at `2026-07-01T05:38:10-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md --apply --queue-timeout 240`.
- `000000003441` at `2026-07-01T05:38:11-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md --apply --queue-timeout 240`.
- `000000003442` at `2026-07-01T05:38:13-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md --apply --queue-timeout 240`.
- `000000003443` at `2026-07-01T05:38:15-04:00`: `python .\tools\validator.py --mode file --file by-file/ImageLoaders.md --apply --queue-timeout 240 --wait-generated`; generated refresh completed and updated `auto-generated/NexusTK/render/ImageLoaders.cpp`.
- `000000003444` at `2026-07-01T05:38:50-04:00`: same by-file validator with `--wait-generated`; generated refresh completed. Latest observed generated header during final verification reports foreground refresh `000000003465` at `2026-07-01T05:44:04-04:00`.
- Generated verification: `auto-generated/NexusTK/render/ImageLoaders.cpp` has no `Empty Emitter Marker`, contains `s_jpegEoiMarker`, covered-by comments for the by-item aliases/[UID:000175]/[UID:00027L], and first-draft bodies for [UID:000314], [UID:000315], [UID:0001F1], [UID:0002TL], [UID:0002TN], [UID:00032P], and [UID:00032O]. `auto-generated/-ag-research-tracker.md` reports [UID:0000K3] as `16 | 16 | 0 | 100.0%`.

## Changed Files
- Modified report: `tools/leaser/Agents/Agent-B009/research/0000K3-ImageLoaders-empty-emitter-family-source-quality.md`.
- Modified target/support docs: `by-file/ImageLoaders.md`; `by-global/ImageDecodeJpegEoiMarker.md`; `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md`; `by-item/LoadPcxImage_004A17B0.md`; `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`; `by-item/DecodePcxToRgb565Buffer_00549410.md`; `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md`; `by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md`; `by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md`; `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`; `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md`; `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md`; `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md`; `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`.
- Validator-owned generated refresh side effects: generated C++ and generated tracking/coverage artifacts refreshed by validator only; no generated file was edited manually.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update identified.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply recorded.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair recommendation, or exact evidence-backed lower-score rationale.
- [x] Owner/emitter/reconstructable changes to apply: no owner/emitter route changes; formal C++/marker comments only.
- [x] Split/rename/new-child changes to apply: none; use existing children and duplicate/index marker comments.
- [x] Source-placement, range/split/padding/reclassification, and raw-helper status recorded.
- [x] First-draft C++ or no-code/covered-by proof to apply supplied in formal insertion shape.
- [x] Third-party import directive confirmed not applicable for ImageLoaders wrappers.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 mentions encountered in support docs and ignored as stale.
- [x] Open questions closed or documented with evidence-backed unresolved rationale.
- [x] Validators to run deferred to implementation callback.
- [x] Generated report refresh expected after implementation and validation.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] Missing goal-required header lines added: `TARGET-REPORT-UID:0000K3` and `AUTHOR-AGENT-ID:B009`.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; generated ImageLoaders output verified fresh and empty-marker-free.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000K3-ImageLoaders-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000K3-ImageLoaders-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T05:48:49","uid":"0000K3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
