** TARGET-REPORT-UID:0000JC **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000JC FileDownloader Empty-Emitter Family Source-Quality Report

Assignment: `B008-report-0000JC-FileDownloader-empty-emitter-family-20260701`  
Mode: report-only research; no by-* docs edited.  
Primary target: [UID:0000JC] `by-file/FileDownloader.md`  
Generated output lead: `auto-generated/NexusTK/network/FileDownloader.cpp`  
MCP database: `supervisor_resume_20260629`  
MCP endpoint: `http://127.0.0.1:13337/mcp`

## Finalized Report / Current Recommendation

- Current recommendation: resolve all nine current `FileDownloader.cpp` empty markers by turning the class and six source-authored methods into formal emitters, and by removing two compiler-generated wrapper/cleanup helpers from source emission with target-specific no-code proof.
- Final disposition: keep [UID:0000JC] as the `NexusTK/network/FileDownloader.cpp` source route. Change method-level direct ownership from broad file ownership to the [UID:00004W] `FileDownloader` class where appropriate, while keeping `EMITTER_UIDS:0000JC` for generated source output.
- Required action after supervisor validation: update the listed by-* docs only in a later implementation callback; do not edit generated files or coverage reports manually.
- Confidence: high for current binary ranges, vtable routes, singleton lifetime, message IDs, and method bodies; medium-high for exact original source spelling of inherited `Thread` helper names and method declaration style.

## Target

- Target UID: `0000JC`
- Target path: `by-file/FileDownloader.md`
- Current metadata: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`
- Current generated row: `auto-generated/-ag-research-tracker.md` reports `15` total emitters, `6` filled, `9` empty, `40.0%` complete.
- Current generated header: `auto-generated/NexusTK/network/FileDownloader.cpp`, validator command `000000003955`, refreshed `2026-07-01T15:56:42-04:00`.
- Current empty markers:
  - [UID:00004W] `by-class/FileDownloader.md`
  - [UID:0002TP] `by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md`
  - [UID:0002TQ] `by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md`
  - [UID:0002TU] `by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md`
  - [UID:0002CJ] `by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md`
  - [UID:0002CK] `by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md`
  - [UID:0002CL] `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md`
  - [UID:0000WK] `by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md`
  - [UID:0002CO] `by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md`

## Current Target State

The file route already has strong prior support: `g_pFileDownloader`, the three static WinINet worker helpers, the `FileDownloaderMessageId` enum, exact vtable data, global storage, and related literal pages are already filled or documented. The remaining generated empty markers are not due to missing source placement. They are caused by formal C++ still being blank on the class/method pages and by two compiler-generated helper pages still being marked as emitting reconstructable children.

Current support docs already reject several stale generated assumptions:

- `g_pCashShopRequest` is a historical filename/alias for `0x0067a738`; the source-facing declaration is `FileDownloader *g_pFileDownloader`.
- [UID:0000WJ] `CashShopVersionAndCatalogDownload` and [UID:0000WI] `FileDownloaderDispatch` are non-emitting inventories. Exact child pages own source output.
- `DownloadMinimapFile`, `DownloadCashShopVersion`, and `DownloadCashShopCatalog` already emit through FileDownloader and should not be duplicated by the class page or broad inventories.

## Supervisor Active Recheck

- The assignment is report-only. No leases were taken.
- No target/support by-* docs were edited.
- IDA MCP was required and was available.
- MCP `initialize` returned server `ida-pro-mcp` version `1.0.0`.
- MCP `idb_list` returned one active session: `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, owned/adopted, PID and worker PID `14860`, `is_analyzing:false`.
- MCP `server_health(database=supervisor_resume_20260629)` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and string cache size `2067`.

## Evidence Checked

IDA MCP calls used:

- `idb_list`, `server_health`, `tools/list`
- `lookup_funcs` for `0x0041a670`, `0x0041a6f0`, `0x0041b110`, `0x0041b180`, `0x0041b200`, `0x0041b270`, `0x0041b2f0`, `0x0041b610`, `0x005965e0`, `0x00596540`, `0x00596400`, `0x00596920`, and `0x00596960`
- `xrefs_to` for the nine empty-marker starts, `0x0067a738`, `0x0060d7a8`, and `0x0060d7d4`
- `callees` for all source-bearing marker starts
- `get_bytes` for `0x0041a670+0x100`, `0x0041b100+0x1d0`, `0x0041b600+0xb0`, and `0x0067a730+0x20`
- `get_int` for the FileDownloader vtable/data pointers and global slots
- `decompile` for all source-bearing marker functions and the three direct submit-helper caller contexts: `0x00451c90`, `0x0041cb70`, and `0x0041bdd0`

Documentation and generated inputs read:

- `by-file/FileDownloader.md`
- `by-class/FileDownloader.md`
- all nine empty-marker target pages listed above
- `by-global/g_pCashShopRequest.md`
- `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`
- `by-type/by-constant/DownloaderMessageIds.md`
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
- `by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md`
- `by-class/CashShopVersionRequest.md`, `by-file/CashShopVersionRequest.md`, `by-class/CashShopRequest.md`, and `by-file/FittingRoom.md`
- generated `auto-generated/NexusTK/network/FileDownloader.cpp`
- generated research tracker row for [UID:0000JC]

Old/executed reports searched:

- Search terms included `0000JC`, `00004W`, `0002TP`, `0002TQ`, `0002TU`, `0002CJ`, `0002CK`, `0002CL`, `0000WK`, `0002CO`, `FileDownloader`, `sub_41B110`, `41B180`, `41B200`, `41B270`, and `41B610`.
- Opened relevant executed reports:
  - `executed-b-agent-research/B001/0002TR-0002TS-0002TT-FileDownloaderDownloadHelpers-source-quality.md`
  - `executed-b-agent-research/B001/0000WI-FileDownloaderDispatchHiddenHelperGap.md`
  - `executed-b-agent-research/B004/0000WJ-CashShopVersionAndCatalogDownload-source-quality.md`
- Other matching reports for shared literals, unreferenced queue wrappers, and Application cleanup were treated as context only where they touched `g_pFileDownloader` or the FileDownloader inventory boundary.

## IDA MCP Facts

Function and boundary facts:

| Address | MCP result | Meaning |
| --- | --- | --- |
| `0x0041a670` | `sub_41A670`, size `0x75`, one caller at `0x00464767` | `FileDownloader::FileDownloader` |
| `0x0041a6f0` | `sub_41A6F0`, size `0x51`, no direct code callers | non-deleting `FileDownloader::~FileDownloader` |
| `0x0041b110` | `sub_41B110`, size `0x70`, data xref from `0x0060d7d4` | vtable-routed `FileDownloader::OnMessage` |
| `0x0041b180` | `sub_41B180`, size `0x75`, caller at `0x00451d18` | minimap submit helper |
| `0x0041b200` | `sub_41B200`, size `0x6d`, caller at `0x0041cd0f` | cash-shop catalog submit helper |
| `0x0041b270` | `sub_41B270`, size `0x59`, caller at `0x0041c21b` | cash-shop version submit helper |
| `0x0041b2f0` | `sub_41B2F0`, size `0x0b`, xref from `0x005f670e` | constructor-unwind global clear helper |
| `0x0041b610` | `sub_41B610`, size `0x8f`, data xref from `0x0060d7a8` | scalar deleting destructor wrapper |

Vtable/global facts:

- `get_int(0x0060d7a4, u32le) = 6554724`, the `FileDownloader` RTTI/COL pointer.
- `get_int(0x0060d7a8, u32le) = 4306448`, which is `0x0041b610`, the scalar deleting destructor slot.
- `get_int(0x0060d7d4, u32le) = 4305168`, which is `0x0041b110`, the `OnMessage` slot.
- `xrefs_to(0x0060d7a8)` returns constructor install `0x0041a6c8`, non-deleting destructor restore `0x0041a715`, and scalar deleting destructor restore `0x0041b63c`.
- `xrefs_to(0x0067a738)` returns exactly nine refs: five FileDownloader-family writes/clears at `0x0041a6b1`, `0x0041a6b8`, `0x0041a722`, `0x0041b2f0`, `0x0041b649`; three submit-helper reads at `0x0041c215`, `0x0041cd09`, `0x00451cf8`; and Application cleanup read/delete at `0x00464a98`.
- `get_bytes(0x0067a730+0x20)` returns all zero bytes, confirming the `0x0067a738` and `0x0067a73c` initial null pointer state.

Decompile facts:

- Constructor decompiles as `sub_596250(this, 5)`, `dword_67A738 = this` on the normal path, FileDownloader vtable install, `sub_5965E0(this)`, and return `this`.
- Non-deleting destructor restores the FileDownloader vtable, calls `sub_596540`, clears `dword_67A738`, and calls `sub_596400`.
- `OnMessage` switches on `10000`, `10001`, and `10002`, calls the minimap/catalog/version workers respectively, frees the raw minimap payload, destroys the version payload through its vtable, and forwards unknown IDs to `sub_596920`.
- Minimap submit allocates `0x238`, zeroes `+0/+4/+8`, stores map id at `+0x0c`, copies `mapCode` to `+0x218` with size `0x10`, copies `outputPath` to `+0x10` with size `0x104`, and posts message `10000` through `sub_596960`.
- Catalog submit allocates `0x28`, writes `CashShopRequest::vftable`, initializes the small string fields, posts message `10001`, and stores the request at `dword_67A73C + 1960` (`+0x7a8`) when the fitting-room dialog exists.
- Version submit allocates `0x10`, writes `CashShopVersionRequest::vftable`, zeroes fields at `+0x04/+0x08/+0x0c`, posts message `10002`, and preserves a null-allocation fallback that posts message `10002` with a null payload.
- Clear helper is only `dword_67A738 = 0`.
- Scalar deleting destructor restores the FileDownloader vtable, calls the same stop/base teardown helpers, clears `dword_67A738`, and conditionally calls `sub_4F4AC0` based on scalar/vector deleting flags.

## Positive Evidence Summary

- The file route is already correct: [UID:0000JC] owns `NexusTK/network/FileDownloader.cpp`, and current generated output already emits filled FileDownloader worker/global/enum content there.
- The class route is now strong enough for a formal source declaration: exact vtable data, constructor/destructor vtable stores, and `OnMessage` vtable slot all point to `FileDownloader`.
- The constructor/destructor/`OnMessage`/submit helpers are source-authored method bodies, not aggregate placeholders. They have exact function starts, exact sizes, direct caller/vtable routes, and decompiled behavior.
- The submit-helper names are no longer blockers. Current docs and MCP evidence support `SubmitMinimapRequest`, `SubmitCashShopCatalogRequest`, and `SubmitCashShopVersionRequest` as source-facing FileDownloader methods.
- The payload layouts are source-quality enough for first-draft C++:
  - `FileDownloaderMinimapRequest`: raw `0x238` request block, `mapId`, `outputPath[0x104]`, `mapCode[0x10]`.
  - `CashShopRequest`: `0x28` catalog payload with `downloadComplete`, `contentLength`, `bytesDownloaded`, and response string.
  - `CashShopVersionRequest`: `0x10` version payload with `state`, `contentLength`, and `bytesDownloaded`.
- The two remaining non-method empty markers have target-specific no-code proof:
  - [UID:0000WK] is constructor EH/unwind cleanup for a source assignment already expressed by the constructor.
  - [UID:0002CO] is a compiler-generated scalar deleting destructor wrapper for teardown already expressed by the non-deleting destructor.

## Negative Evidence Summary

- Do not treat [UID:0000WI] or [UID:0000WJ] as source-emitting FileDownloader aggregate bodies. Both are reviewed non-emitting inventories; exact children own source output.
- Do not move `DownloadMinimapFile`, `DownloadCashShopVersion`, or `DownloadCashShopCatalog` out of FileDownloader during this callback. Prior B001/B004 evidence and current generated output already support their filled worker bodies in `FileDownloader.cpp`.
- Do not use `g_pCashShopRequest` as the source-facing type/name for `0x0067a738`. Current docs and MCP xrefs prove FileDownloader lifetime; the actual `CashShopRequest` catalog payload is separately allocated at `0x0041b200`.
- Do not emit vtable bytes or scalar deleting wrapper code manually. Vtables and deleting destructors should be regenerated from class declarations and destructor source.
- Do not turn the constructor-unwind clear helper into a public source helper. Its only direct route is the EH/unwind block at `0x005f670e`.
- Do not route submit helpers to FittingRoom or CashShopVersionRequest as direct owners. Those pages own caller context and payload identity, but the live receiver is `dword_67A738`/`g_pFileDownloader`, and the helpers post through the FileDownloader/Thread queue.

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Ownership

Best ownership/source-placement decision:

- [UID:0000JC] remains the file/source route: `NexusTK/network/FileDownloader.cpp`.
- [UID:00004W] should be the direct semantic owner for FileDownloader method bodies.
- The method pages [UID:0002TP], [UID:0002TQ], [UID:0002TU], [UID:0002CJ], [UID:0002CK], and [UID:0002CL] should change from `CANONICAL_OWNER:0000JC` to `CANONICAL_OWNER:00004W`, while preserving `EMITTER_UIDS:0000JC`.
- [UID:0000WK] is a compiler/unwind cleanup child with source-file context but no standalone source body.
- [UID:0002CO] is compiler-generated deleting destructor support for [UID:00004W], not a hand-authored method body.

Rejected placements:

- FittingRoom as direct owner for catalog/version submit helpers: rejected because FittingRoom caller contexts load `dword_67A738` and call FileDownloader receiver methods.
- CashShopRequest/CashShopVersionRequest as direct owner for submit helpers: rejected because payload vtable identity does not own the queue receiver method.
- FileDownloader by-file as the direct semantic owner for methods: acceptable historically but less precise than class ownership under current by-structure rules. The file still remains the emitter.

### Constructor/Destructor Source Shape

The constructor and destructor are ready for first-draft method C++ despite unresolved internal `Thread` helper names. The source intent is clear:

- Constructor invokes the base `Thread` constructor with worker kind/id `5`, publishes the singleton, and starts the worker.
- Destructor stops the worker and clears the singleton; base `Thread` destruction follows normal C++ destructor chaining.

The decompiler's constructor sentinel `this == -104` is an EH/unwind artifact. It should not be emitted in source C++.

### OnMessage Signature

Hex-Rays recovers a `__thiscall` method with three stack arguments and `retn 0x0c`. The vtable slot proves class membership even though one current decompiler pass can drop the unused `this`. The best source-facing signature is:

```cpp
void FileDownloader::OnMessage(int messageId, void *payload, int aux)
```

The `payload` type is `void *` at the virtual boundary; each case casts to the exact request type.

### Submit Helper Names

The current best source names are:

- `FileDownloader::SubmitMinimapRequest`
- `FileDownloader::SubmitCashShopCatalogRequest`
- `FileDownloader::SubmitCashShopVersionRequest`

They are inferred, not original symbol proof, but they are source-quality: each name describes the caller-facing operation, message ID, and payload type without keeping `sub_` or raw address labels.

### Compiler-Generated No-Code Decisions

[UID:0000WK] and [UID:0002CO] should not keep `RECONSTRUCTABLE:TRUE` plus blank emitted code. That state creates empty generated markers while implying source should be hand-authored. The implementation-ready fix is:

- [UID:0000WK]: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; preserve no-code proof that constructor source and compiler EH cleanup regenerate the clear.
- [UID:0002CO]: `CANONICAL_OWNER:00004W`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; preserve no-code proof that [UID:0002TQ] owns source teardown and the compiler regenerates scalar deleting wrapper mechanics.

## Function / Child Inventory

| UID | Path | Current state | Recommended state |
| --- | --- | --- | --- |
| `00004W` | `by-class/FileDownloader.md` | `86/90`, emitter to file, blank class C++ | `89/91`, formal class declaration with `[[CHILDREN]]` route, no duplicate method bodies |
| `0002TP` | constructor | `85/90`, owner file, blank C++ | `88/91`, owner class, emitter file, formal constructor body |
| `0002TQ` | destructor | `85/90`, owner file, blank C++ | `88/91`, owner class, emitter file, formal destructor body |
| `0002TU` | `OnMessage` | `85/89`, owner file, blank C++ | `88/91`, owner class, emitter file, formal dispatcher body |
| `0002CJ` | minimap submit | `85/90`, owner file, blank C++ | `88/90`, owner class, emitter file, formal submit body |
| `0002CK` | catalog submit | `85/90`, owner file, blank C++ | `88/90`, owner class, emitter file, formal submit body |
| `0002CL` | version submit | `85/90`, owner file, blank C++ | `88/90`, owner class, emitter file, formal submit body |
| `0000WK` | constructor-unwind clear | `85/92`, owner file, reconstructable true, blank C++ | `86/92`, owner file, reconstructable false, no standalone source body |
| `0002CO` | scalar deleting destructor | `85/90`, owner file, reconstructable true, blank C++ | `86/91`, owner class, reconstructable false, no standalone source body |

## Ranked Ownership Analysis

### 1. FileDownloader Class Methods Under FileDownloader.cpp - Accepted

- Evidence for: vtable slot `0x0060d7d4`, vtable stores at constructor/destructor/scalar wrapper, singleton lifetime writes, source receiver on submit helpers, and exact worker dispatch map.
- Evidence against: exact original method names are not symbol-proven; inherited Thread helper names remain inferred.
- Decision: accepted. Use class direct owner and file emitter route.

### 2. FileDownloader By-File As Direct Owner For Methods - Historical, Superseded

- Evidence for: existing metadata uses [UID:0000JC] and generated output routes through `FileDownloader.cpp`.
- Evidence against: by-structure direct owner should be the class for class methods. The file is the source route, not the semantic owner.
- Decision: keep as emitter only.

### 3. FittingRoom / CashShop Payload Owners - Rejected For Method Ownership

- Evidence for: FittingRoom triggers version/catalog submit paths and owns `m_itemShopVersion`/`m_activeCatalogRequest`; payload classes own vtables and destructors.
- Evidence against: submit helper calls are made on `dword_67A738`; all writes to that singleton are FileDownloader constructor/destructor-family writes.
- Decision: support context only.

### 4. Thread Base Class - Rejected For These Bodies

- Evidence for: constructor/destructor and dispatcher use inherited Thread helpers.
- Evidence against: vtable/class identity, singleton lifetime, and submit methods are FileDownloader-specific.
- Decision: Thread owns helper implementations such as queue post and base fallback, not the FileDownloader method bodies.

### 5. Compiler-Generated Helpers - Accepted No-Code For [UID:0000WK] And [UID:0002CO]

- Evidence for: [UID:0000WK] only has an EH/unwind jump route; [UID:0002CO] is vtable deleting-destructor support with delete flags.
- Evidence against: both touch meaningful FileDownloader state, so they must remain documented and cross-linked.
- Decision: document as no-code/compiler-generated support; remove source emission.

## Source Placement

Recommended source layout remains:

```text
NexusTK/network/
  FileDownloader.h
  FileDownloader.cpp
```

Implementation should not create a new source file. If a later header split is needed, request payload declarations can move to a shared header, but the method bodies and static worker helpers still route through [UID:0000JC] for this report.

## First-Draft C++ Recommendation

### [UID:00004W] `by-class/FileDownloader.md`

Recommended metadata:

```text
COMPLETION:89
CONFIDENCE:91
CANONICAL_OWNER:0000JC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:3
```

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:00004W | FileDownloader source-level worker class declaration.
// Exact method bodies emit through their by-memory children in FileDownloader.cpp.

class FileDownloader : public Thread {
public:
    FileDownloader();
    virtual ~FileDownloader();

    virtual void OnMessage(int messageId, void *payload, int aux);

    bool SubmitMinimapRequest(int mapId,
                              const wchar_t *mapCode,
                              const wchar_t *outputPath);
    void SubmitCashShopCatalogRequest();
    bool SubmitCashShopVersionRequest();
};

[[CHILDREN]]
```

### [UID:0002TP] `FileDownloaderConstructor`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:10
```

Recommended formal C++:

```cpp
FileDownloader::FileDownloader()
    : Thread(5)
{
    g_pFileDownloader = this;
    StartThread();
}
```

Rationale: `Thread(5)` is the source-level base construction for `sub_596250(this, 5)`. `StartThread()` is the current best source-facing name for `sub_5965E0`; the unresolved possibility that `StartThread` is inherited/shared caps score but does not justify blank C++.

### [UID:0002TQ] `FileDownloaderDestructor`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:11
```

Recommended formal C++:

```cpp
FileDownloader::~FileDownloader()
{
    StopThread();
    g_pFileDownloader = 0;
}
```

Rationale: `StopThread()` is the source-level teardown for `sub_596540`. The base `Thread` destructor should run through normal C++ destructor chaining rather than an explicit `sub_596400` call.

### [UID:0002TU] `FileDownloaderOnMessage`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:12
```

Recommended formal C++:

```cpp
void FileDownloader::OnMessage(int messageId, void *payload, int aux)
{
    switch (messageId) {
    case kDownloadMinimapFileMessage:
        if (payload != NULL) {
            DownloadMinimapFile(static_cast<FileDownloaderMinimapRequest *>(payload));
            operator delete(payload);
        }
        break;

    case kDownloadCashShopCatalogMessage:
        if (payload != NULL) {
            DownloadCashShopCatalog(static_cast<CashShopRequest *>(payload));
        }
        break;

    case kDownloadCashShopVersionMessage:
        if (payload != NULL) {
            CashShopVersionRequest *request =
                static_cast<CashShopVersionRequest *>(payload);
            DownloadCashShopVersion(request);
            delete request;
        }
        break;

    default:
        Thread::OnMessage(messageId, payload, aux);
        break;
    }
}
```

Rationale: preserves all three cases, null guards, minimap raw payload delete, version virtual destruction, catalog self-cleanup responsibility, and base-thread fallback.

### [UID:0002CJ] `FileDownloaderSubmitMinimapRequest`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:13
```

Recommended formal C++:

```cpp
bool FileDownloader::SubmitMinimapRequest(int mapId,
                                          const wchar_t *mapCode,
                                          const wchar_t *outputPath)
{
    FileDownloaderMinimapRequest *request = new FileDownloaderMinimapRequest;
    request->state = 0;
    request->contentLength = 0;
    request->bytesDownloaded = 0;
    request->mapId = mapId;
    wcscpy_s(request->mapCode, 0x10, mapCode);
    wcscpy_s(request->outputPath, 0x104, outputPath);

    return DispatchRequest(kDownloadMinimapFileMessage, request, 0);
}
```

Rationale: preserves `0x238` allocation semantics at source level, the `0x10` and `0x104` wide-buffer sizes, and message `10000`. The decompiler's null-allocation path is not source-shaped for normal throwing `new`; the binary's checks are compiler/runtime lowering.

### [UID:0002CK] `FileDownloaderSubmitCashShopCatalogRequest`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:14
```

Recommended formal C++:

```cpp
void FileDownloader::SubmitCashShopCatalogRequest()
{
    CashShopRequest *request = new CashShopRequest;
    DispatchRequest(kDownloadCashShopCatalogMessage, request, 0);

    if (g_pFittingRoomDialog != NULL) {
        g_pFittingRoomDialog->m_activeCatalogRequest = request;
    }
}
```

Rationale: preserves the `0x28` catalog payload allocation, queue post for message `10001`, and FittingRoom active catalog handoff at `+0x7a8`.

### [UID:0002CL] `FileDownloaderSubmitCashShopVersionRequest`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC
EMITTER_POSITION_OPTIONAL:15
```

Recommended formal C++:

```cpp
bool FileDownloader::SubmitCashShopVersionRequest()
{
    CashShopVersionRequest *request = new CashShopVersionRequest;
    return DispatchRequest(kDownloadCashShopVersionMessage, request, 0);
}
```

Rationale: preserves the source-level intent for allocating the `0x10` request and posting message `10002`. The binary null-allocation fallback is compiler/runtime lowering around allocation failure and should stay documented in prose rather than making final source decompiler-shaped.

### [UID:0000WK] `ClearFileDownloaderRequestGlobal`

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:0000JC
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

Recommended formal C++ disposition: leave the formal C++ block blank after changing `RECONSTRUCTABLE:FALSE`.

No-code proof to incorporate:

```text
This is constructor EH/unwind cleanup for [UID:0002TP] FileDownloader::FileDownloader, reached from unwind address 0x005f670e and consisting only of dword_67A738 = 0. The source assignment is represented by the constructor and destructor/global docs; the compiler regenerates EH cleanup. Do not hand-author a public ClearFileDownloaderRequestGlobal helper or emit duplicate singleton-clear source.
```

### [UID:0002CO] `FileDownloaderScalarDeletingDestructor`

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00004W
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

Recommended formal C++ disposition: leave the formal C++ block blank after changing `RECONSTRUCTABLE:FALSE`.

No-code proof to incorporate:

```text
This is the compiler-generated scalar deleting destructor wrapper reached from the FileDownloader vtable slot at 0x0060d7a8. It restores the vtable, runs the same teardown represented by [UID:0002TQ] FileDownloader::~FileDownloader, clears g_pFileDownloader, and conditionally calls operator delete based on delete flags. Rebuild source should emit the ordinary virtual destructor; the compiler regenerates the deleting-destructor wrapper. Do not hand-author this wrapper as standalone source.
```

## Recommended Target Doc Changes

### `by-file/FileDownloader.md`

Recommended metadata: `COMPLETION:89`, `CONFIDENCE:91`.

Add a `2026-07-01 B008 Empty-Emitter Family Recheck` section preserving:

- Generated baseline: command `000000003955`, refreshed `2026-07-01T15:56:42-04:00`, `15` total, `6` filled, `9` empty, `40.0%` complete.
- Source route split: [UID:0000JC] is the `NexusTK/network/FileDownloader.cpp` route; [UID:00004W] owns class/method semantics; exact worker/static helpers remain FileDownloader-routed.
- Empty-marker repair plan: class declaration and six method bodies emit; [UID:0000WK]/[UID:0002CO] become compiler-generated no-code/non-emitting support.
- Preserve rejected owners: FittingRoom/CashShopRequest/CashShopVersionRequest/MiniMap are caller, payload, or feature-context owners, not direct emitters for these FileDownloader methods.
- Preserve no-duplicate policy: do not reintroduce [UID:0000WI] or [UID:0000WJ] aggregate emission.

### `by-class/FileDownloader.md`

Recommended metadata and formal code are listed in the C++ section. Also update prose to state:

- The class declaration is now first-draft source-ready.
- Constructor/destructor/`OnMessage`/submit helper method pages should be class-owned and file-emitted.
- Scalar deleting destructor and vtable bytes are compiler/generated-binary support and should not duplicate method bodies.
- `StartThread`, `StopThread`, `DispatchRequest`, and base `Thread::OnMessage` names are source-facing inferred Thread helper names, not recovered symbols; this caps score below final audit but no longer blocks first-draft C++.

### Method by-memory pages

For [UID:0002TP], [UID:0002TQ], [UID:0002TU], [UID:0002CJ], [UID:0002CK], and [UID:0002CL]:

- Change `CANONICAL_OWNER` to `00004W`.
- Preserve `RECONSTRUCTABLE:TRUE`.
- Preserve `EMITTER_UIDS:0000JC`.
- Add the formal C++ body listed above.
- Add a source-quality note preserving exact MCP proof: function size, caller/vtable route, callees, xrefs, decompile facts, and rejected feature/payload direct ownership.

### No-code by-memory pages

For [UID:0000WK]:

- Change `RECONSTRUCTABLE:FALSE`.
- Blank `EMITTER_UIDS`.
- Keep `CANONICAL_OWNER:0000JC`.
- Preserve the unwind-helper proof and state that the constructor owns source representation.

For [UID:0002CO]:

- Change `CANONICAL_OWNER:00004W`.
- Change `RECONSTRUCTABLE:FALSE`.
- Blank `EMITTER_UIDS`.
- Preserve the deleting-destructor proof and state that [UID:0002TQ] owns source teardown.

## Recommended Support Doc Changes

### Already-present or support-only pages

- `by-global/g_pCashShopRequest.md`: already emits `FileDownloader *g_pFileDownloader;`; no metadata change required. If touched during implementation, add only a cross-reference note that the B008 method repair removes the remaining class/method empty markers without changing the stale filename caveat.
- `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`: already emits the same global declaration and preserves the nine-xref matrix; no change required unless the supervisor wants a cross-reference.
- `by-type/by-constant/DownloaderMessageIds.md`: already emits `FileDownloaderMessageId`; no change required.
- `by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md`: no metadata change required; add only if needed that the class declaration and virtual destructor now explain the table and [UID:0002CO] should not emit wrapper C++.

### Aggregate support pages

- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`: add a support note that B008 resolves the remaining exact FileDownloader child empty markers by class/method bodies and no-code compiler wrapper cleanup; keep the aggregate `RECONSTRUCTABLE:FALSE`.
- `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`: no change required unless stale generated-output wording appears; its current B004 non-emitting model remains correct.

### Feature/payload context pages

- `by-class/CashShopVersionRequest.md` and `by-file/CashShopVersionRequest.md`: support note only if implementation touches them. State that [UID:0002CL] remains FileDownloader-owned method output; this class owns the `0x10` payload/vtable/destructor identity.
- `by-class/CashShopRequest.md`: support note only if touched. State that [UID:0002CK] remains FileDownloader-owned method output; the `CashShopRequest` class owns catalog payload identity and destructor/string layout.
- `by-file/FittingRoom.md`: no required change. It already records `m_itemShopVersion +0x790`, `m_activeCatalogRequest +0x7a8`, and FileDownloader-vs-FittingRoom split.

## Score And Metadata Recommendation

| UID | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `0000JC` | `87/90` | `89/91` | Empty-marker family source route resolved; only inherited Thread helper exact spelling and final declaration style cap score. |
| `00004W` | `86/90` | `89/91` | Class declaration and vtable/method ownership are implementation-ready. |
| `0002TP` | `85/90` | `88/91` | Constructor source shape ready; EH sentinel rejected. |
| `0002TQ` | `85/90` | `88/91` | Destructor source shape ready; base destructor implicit. |
| `0002TU` | `85/89` | `88/91` | Dispatch switch and vtable route ready; final Thread handler type still inferred. |
| `0002CJ` | `85/90` | `88/90` | Minimap submit source shape ready with exact request layout. |
| `0002CK` | `85/90` | `88/90` | Catalog submit source shape ready with exact FittingRoom active-request handoff. |
| `0002CL` | `85/90` | `88/90` | Version submit source shape ready with exact payload and null-fallback note. |
| `0000WK` | `85/92` | `86/92` + `RECONSTRUCTABLE:FALSE` | Better documented as compiler EH cleanup, not source emitter. |
| `0002CO` | `85/90` | `86/91` + `RECONSTRUCTABLE:FALSE` | Better documented as compiler deleting-destructor wrapper, not source emitter. |

Do not raise any target to `95+`. The report resolves the current blockers but does not prove original symbol spelling, full header layout, or exhaustive final-audit quality.

## Open Questions With Attempted Resolution

- Exact original spelling of `StartThread`, `StopThread`, `DispatchRequest`, and `Thread::OnMessage`: unresolved but bounded. Current names are source-facing inferred names based on behavior and existing docs. This caps score but does not block formal C++.
- Exact original class declaration order and header split: unresolved. Recommendation uses a conservative class declaration in `FileDownloader.cpp`/header context and does not create a new file.
- Whether submit helpers were originally private methods or file-local wrappers taking `FileDownloader *`: current `__thiscall` decompilation, receiver route, and class role make private/public method form the better first draft.
- Whether [UID:0000WK] should stay reconstructable as a helper: resolved negative. It is EH cleanup and should not emit.
- Whether [UID:0002CO] should emit deleting destructor C++: resolved negative. The ordinary virtual destructor and compiler wrapper generation cover it.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`. Logs are under `tools/leaser/Agents/Agent-B008/validation-logs/0000JC-implementation/`.

| File | Command ID | Timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/FileDownloader.md` | `000000004022` | `2026-07-01T16:17:26-04:00` | `0` | `1` | completed, same command |
| `by-class/FileDownloader.md` | `000000004023` | `2026-07-01T16:17:37-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md` | `000000004024` | `2026-07-01T16:17:48-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md` | `000000004025` | `2026-07-01T16:17:59-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md` | `000000004027` | `2026-07-01T16:18:11-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md` | `000000004029` | `2026-07-01T16:18:31-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md` | `000000004032` | `2026-07-01T16:18:51-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md` | `000000004034` | `2026-07-01T16:19:13-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md` | `000000004036` | `2026-07-01T16:19:34-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md` | `000000004038` | `2026-07-01T16:19:53-04:00` | `0` | `1` | completed, same command |
| `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` | `000000004040` | `2026-07-01T16:20:13-04:00` | `0` | `1` | completed, same command |

Warnings observed were pre-existing/global-style validator diagnostics, not target-specific failures: missing UID references such as `0003FT`, `0003G0`, `0003G2`, `0003AL`, `0003GY`, `0003GZ`, and `0003H0` are not present in `validator.ini`; broad `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` warnings remain elsewhere in the project.

Generated output inspection after validators:

- `auto-generated/NexusTK/network/FileDownloader.cpp` header is `validator-command-id: 000000004043`, refreshed `2026-07-01T16:20:52-04:00`, newer than the final scoped validator `000000004040` at `2026-07-01T16:20:13-04:00`.
- The generated file contains [UID:00004W] class declaration, [UID:0002TP] constructor, [UID:0002TQ] destructor, [UID:0002TU] `OnMessage`, [UID:0002CJ] `SubmitMinimapRequest`, [UID:0002CK] `SubmitCashShopCatalogRequest`, and [UID:0002CL] `SubmitCashShopVersionRequest`.
- `rg` found no `Empty Emitter Marker` for [UID:00004W], [UID:0002TP], [UID:0002TQ], [UID:0002TU], [UID:0002CJ], [UID:0002CK], [UID:0002CL], [UID:0000WK], or [UID:0002CO].
- [UID:0000WK] and [UID:0002CO] no longer appear as generated source bodies. [UID:0000WI] does not emit a duplicate broad aggregate body.

## Changed Files

Modified:

- `by-file/FileDownloader.md`
- `by-class/FileDownloader.md`
- `by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md`
- `by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md`
- `by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md`
- `by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md`
- `by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md`
- `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md`
- `by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md`
- `by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md`
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
- `tools/leaser/Agents/Agent-B008/research/0000JC-FileDownloader-empty-emitter-family-source-quality.md`
- `tools/leaser/Agents/Agent-B008/validation-logs/0000JC-implementation/*.log`

Validator-owned/generated side effects observed during scoped validation:

- `auto-generated/NexusTK/network/FileDownloader.cpp` refreshed by validator/autogen; B008 did not edit it manually.
- Validator-owned coverage/tracker/generated metadata files refreshed as part of validator execution; B008 did not edit generated reports or validator/tool state by hand.

Leases:

- Lease command succeeded for the eleven accepted by-* edit files before edits/validators.
- Release command after validators returned `Rejected[No active lease]` for each FileDownloader path, meaning the short leases were already absent/expired by release time.
- `tools/leaser/Agents/current_leases.md` confirmed `No active leases` after validation; no B008 leases remain.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | Generated baseline is `15` emitters, `6` filled, `9` empty, `40.0%`, command `000000003955`, refreshed `2026-07-01T15:56:42-04:00`. | High | Generated header and tracker row. | `by-file/FileDownloader.md` generated audit section | incorporate | applied: `by-file/FileDownloader.md` has `2026-07-01 B008 Empty-Emitter Family Implementation` with the exact baseline; validator `000000004022` exit `0`, `ok:1`. |
| C2 | [UID:0000JC] remains the `NexusTK/network/FileDownloader.cpp` source route; [UID:00004W] is the correct class owner for method semantics. | High | Current by-file/class docs, vtable refs, MCP xrefs. | `by-file/FileDownloader.md`, `by-class/FileDownloader.md`, method pages | incorporate | applied: by-file route split section preserves [UID:0000JC] file route, class page is `89/91`, and method pages have `CANONICAL_OWNER:00004W` with `EMITTER_UIDS:0000JC`; generated header still says source by-file UID `0000JC`. |
| C3 | [UID:00004W] should emit a formal `FileDownloader : public Thread` declaration with `[[CHILDREN]]` and no duplicate method bodies. | High | Vtable data [UID:0003FT], constructor/destructor/OnMessage routes. | `by-class/FileDownloader.md` formal C++ block | applied | applied: `by-class/FileDownloader.md` formal block contains exact class declaration and `[[CHILDREN]]`; generated `FileDownloader.cpp` command `000000004043` contains the declaration and no duplicated class-level method bodies. |
| C4 | [UID:0002TP] constructor is source-authored and first-draft C++ ready as `Thread(5)`, singleton publish, and `StartThread()`. | High | MCP decompile `0x0041a670`, callees `0x596250/0x5965e0`, xrefs to `0x0067a738/0x0060d7a8`. | `by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md` | incorporate | applied: metadata `88/91`, owner `00004W`, position `10`, formal constructor body inserted, EH-sentinel rejection note added; validator `000000004024` exit `0`, `ok:1`. |
| C5 | [UID:0002TQ] destructor is source-authored and first-draft C++ ready as `StopThread()` plus `g_pFileDownloader = 0`. | High | MCP decompile `0x0041a6f0`, vtable restore, callees `0x596540/0x596400`, global clear. | `by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md` | incorporate | applied: metadata `88/91`, owner `00004W`, position `11`, formal destructor body inserted, scalar-wrapper duplicate policy added; validator `000000004025` exit `0`, `ok:1`. |
| C6 | [UID:0002TU] `OnMessage` is source-authored and first-draft C++ ready with cases `10000`, `10001`, `10002`, payload cleanup, and `Thread::OnMessage` fallback. | High | MCP vtable xref from `0x0060d7d4`, decompile `0x0041b110`, callees to worker helpers. | `by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md` | incorporate | applied: metadata `88/91`, owner `00004W`, position `12`, formal dispatcher C++ inserted and vtable-slot proof preserved; validator `000000004027` exit `0`, `ok:1`. |
| C7 | [UID:0002CJ] minimap submit helper is source-authored and first-draft C++ ready as `SubmitMinimapRequest`. | High | MCP decompile `0x0041b180`, caller `0x00451d18`, `0x238` allocation, `wcscpy_s` sizes, message `10000`. | `by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md` | incorporate | applied: metadata `88/90`, owner `00004W`, position `13`, formal `SubmitMinimapRequest` body inserted with `0x10`, `0x104`, and `kDownloadMinimapFileMessage`; validator `000000004029` exit `0`, `ok:1`. |
| C8 | [UID:0002CK] catalog submit helper is source-authored and first-draft C++ ready as `SubmitCashShopCatalogRequest`. | High | MCP decompile `0x0041b200`, caller `0x0041cd0f`, `0x28` allocation, FittingRoom `+0x7a8` store, message `10001`. | `by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md` | incorporate | applied: metadata `88/90`, owner `00004W`, position `14`, formal `SubmitCashShopCatalogRequest` body inserted with `m_activeCatalogRequest`; validator `000000004032` exit `0`, `ok:1`. |
| C9 | [UID:0002CL] version submit helper is source-authored and first-draft C++ ready as `SubmitCashShopVersionRequest`. | High | MCP decompile `0x0041b270`, caller `0x0041c21b`, `0x10` allocation, vtable write, null fallback, message `10002`. | `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md` | incorporate | applied: metadata `88/90`, owner `00004W`, position `15`, formal `SubmitCashShopVersionRequest` body inserted and null-fallback evidence preserved in prose; validator `000000004034` exit `0`, `ok:1`. |
| C10 | [UID:0000WK] should be non-emitting compiler EH/unwind cleanup, not a public source helper. | High | MCP xref only from `0x005f670e`, decompile single global clear, constructor owns source assignment. | `by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md` | incorporate | applied: metadata `86/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, no-code proof added; validator `000000004036` exit `0`, `ok:1`; generated output has no [UID:0000WK] empty marker/body. |
| C11 | [UID:0002CO] should be non-emitting compiler-generated scalar deleting destructor wrapper. | High | MCP vtable xref `0x0060d7a8`, delete flag decompile, ordinary destructor owns source teardown. | `by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md` | incorporate | applied: metadata `86/91`, owner `00004W`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, no-code proof added; validator `000000004038` exit `0`, `ok:1`; generated output has no [UID:0002CO] empty marker/body. |
| C12 | `g_pCashShopRequest` is stale alias text for `FileDownloader *g_pFileDownloader`; no global route change is needed. | High | Current global/storage docs and MCP nine-xref matrix. | `by-file/FileDownloader.md`, optional global/storage support note | already-present | already-present: `by-global/g_pCashShopRequest.md` and `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md` already emit `FileDownloader *g_pFileDownloader;`; by-file B008 section preserves stale-alias policy. |
| C13 | [UID:0000WI] and [UID:0000WJ] remain non-emitting inventories and must not duplicate exact child bodies. | High | Executed B001/B004 reports and current aggregate docs. | `by-file/FileDownloader.md`, `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` | incorporate | applied: by-file no-duplicate policy added; `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` has B008 support note and remains `RECONSTRUCTABLE:FALSE`; generated output has no [UID:0000WI] broad body. |
| C14 | FittingRoom, CashShopRequest, CashShopVersionRequest, and MiniMap are support/payload/caller contexts, not direct emitters for these method bodies. | High | Current docs and MCP caller contexts loading `dword_67A738`. | `by-file/FileDownloader.md`, class/method pages | incorporate | applied: by-file B008 section preserves rejected owners; method pages keep feature/payload context notes while using class owner `00004W` and file emitter `0000JC`. |
| C15 | Generated C++ and coverage/project-level reports remain validator/supervisor-owned; B008 should not edit them manually. | High | Workflow and assignment prohibitions. | Implementation checklist / final checkpoint | not-applicable | not-applicable: B008 manually edited only by-* docs and this B008 report; generated `FileDownloader.cpp` and coverage/tracker files were validator-owned side effects only. |

## Implementation Tracking Checklist

- [x] Supervisor validation required before any by-* implementation edits. Proof: supervisor sent implementation callback assignment `B008-implement-0000JC-FileDownloader-empty-emitter-family-20260701`.
- [x] Edit `by-file/FileDownloader.md`: set score to `89/91`; add the 2026-07-01 generated-output audit with command `000000003955`, refreshed `2026-07-01T15:56:42-04:00`, `15/6/9/40.0%`; record the class/method/no-code split; preserve rejected owners and no-duplicate aggregate policy. Proof: section `2026-07-01 B008 Empty-Emitter Family Implementation`; validator `000000004022`, exit `0`, `ok:1`.
- [x] Edit `by-class/FileDownloader.md`: set score to `89/91`; set `EMITTER_POSITION_OPTIONAL:3`; insert the exact formal class declaration C++ with `[[CHILDREN]]`; add prose that method bodies emit through exact by-memory children and vtable/deleting wrappers are generated-binary support. Proof: formal block populated; section `2026-07-01 B008 Class Declaration And Empty-Emitter Repair`; validator `000000004023`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md`: set `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004W`, `EMITTER_POSITION_OPTIONAL:10`; insert the exact formal constructor body; preserve MCP proof and EH-sentinel rejection. Proof: formal constructor inserted and B008 disposition section added; validator `000000004024`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md`: set `88/91`, `CANONICAL_OWNER:00004W`, `EMITTER_POSITION_OPTIONAL:11`; insert the exact formal destructor body; preserve base-thread teardown proof. Proof: formal destructor inserted and B008 disposition section added; validator `000000004025`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md`: set `88/91`, `CANONICAL_OWNER:00004W`, `EMITTER_POSITION_OPTIONAL:12`; insert the exact formal dispatcher body; preserve vtable-slot, cleanup, and fallback evidence. Proof: formal dispatcher inserted and vtable/fallback proof preserved; validator `000000004027`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md`: set `88/90`, `CANONICAL_OWNER:00004W`, `EMITTER_POSITION_OPTIONAL:13`; insert the exact formal `SubmitMinimapRequest` body; preserve `0x238`, `0x10`, `0x104`, and message `10000` proof. Proof: formal submit body inserted; validator `000000004029`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md`: set `88/90`, `CANONICAL_OWNER:00004W`, `EMITTER_POSITION_OPTIONAL:14`; insert the exact formal `SubmitCashShopCatalogRequest` body; preserve `0x28`, `CashShopRequest`, FittingRoom `+0x7a8`, and message `10001` proof. Proof: formal submit body inserted; validator `000000004032`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md`: set `88/90`, `CANONICAL_OWNER:00004W`, `EMITTER_POSITION_OPTIONAL:15`; insert the exact formal `SubmitCashShopVersionRequest` body; preserve `0x10`, `CashShopVersionRequest`, null fallback, and message `10002` proof. Proof: formal submit body inserted and null fallback retained in prose; validator `000000004034`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md`: set `86/92`; change `RECONSTRUCTABLE:FALSE`; blank `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL`; keep formal C++ blank; add the exact EH/unwind no-code proof. Proof: no-code section added, emitter blank; validator `000000004036`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md`: set `86/91`; change `CANONICAL_OWNER:00004W`; change `RECONSTRUCTABLE:FALSE`; blank `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL`; keep formal C++ blank; add the exact scalar-deleting-wrapper no-code proof. Proof: no-code section added, emitter blank; validator `000000004038`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`: add support note that B008 resolves the exact FileDownloader child empty markers and keeps the aggregate non-emitting; preserve [UID:0000WI] mixed-inventory proof. Proof: section `2026-07-01 B008 Exact-Child Empty-Emitter Repair`; validator `000000004040`, exit `0`, `ok:1`.
- [x] Confirm already-present support in `by-global/g_pCashShopRequest.md`, `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`, `by-type/by-constant/DownloaderMessageIds.md`, and `by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md`; edit only if the implementation callback explicitly requests cross-reference notes. Proof: inspected all four; support facts already present, no stale contradiction found, no edits made.
- [x] Do not edit feature/payload support docs unless a stale contradiction is found during implementation; `by-class/CashShopVersionRequest.md`, `by-file/CashShopVersionRequest.md`, `by-class/CashShopRequest.md`, and `by-file/FittingRoom.md` are currently sufficient support context. Proof: no stale contradiction found during accepted-scope implementation; no edits made.
- [x] Run scoped validators with `--wait-generated` for every edited by-* doc listed in `Validator Results`. Proof: all eleven commands listed above exited `0` with `ok:1`.
- [x] Verify generated `auto-generated/NexusTK/network/FileDownloader.cpp`: header command is newer/equal to final validator; no `Empty Emitter Marker` remains for [UID:00004W], [UID:0002TP], [UID:0002TQ], [UID:0002TU], [UID:0002CJ], [UID:0002CK], [UID:0002CL], [UID:0000WK], or [UID:0002CO]; no duplicate broad aggregate bodies are emitted. Proof: header command `000000004043`, refreshed `2026-07-01T16:20:52-04:00`; `rg` found class and six method bodies, no audited empty markers, no [UID:0000WK]/[UID:0002CO] bodies, and no [UID:0000WI] aggregate body.
- [x] Update this report's `Claim And Incorporation Ledger` to callback verification states with proof during the implementation callback. Proof: all ledger rows updated above; no blockers.
- [x] Check off this implementation checklist with target paths, sections touched, validator command IDs/timestamps/exit/ok counts, generated freshness proof, and any exact blockers during the implementation callback. Proof: this checklist is updated; no exact blockers remain.
- [x] Do not edit generated reports, generated `auto-generated/NexusTK/**` C++, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB. Proof: no manual edits to excluded files; generated/coverage/tracker refreshes were validator-owned side effects of scoped validation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000JC-FileDownloader-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000JC-FileDownloader-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T16:26:09","uid":"0000JC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
