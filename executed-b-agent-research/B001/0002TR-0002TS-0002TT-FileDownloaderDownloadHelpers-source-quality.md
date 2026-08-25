** TARGET-REPORT-UID:0002TR **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-filedownloader-download-helpers-source-quality-0002TR-0002TS-0002TT-20260618

## Finalized Report / Current Recommendation

Primary targets:

- [UID:0002TR] `by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md`
- [UID:0002TS] `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`
- [UID:0002TT] `by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md`

Final recommendation:

| UID | Current | Recommended | Owner/emitter | Formal C++ |
| --- | ---: | ---: | --- | --- |
| `0002TR` | `85/88` | `88/90` | keep `CANONICAL_OWNER:0000JC`, `EMITTER_UIDS:0000JC` | populate with `DownloadMinimapFile(FileDownloaderMinimapRequest*)` draft below |
| `0002TS` | `85/89` | `88/90` | keep `CANONICAL_OWNER:0000JC`, `EMITTER_UIDS:0000JC` | populate with `DownloadCashShopVersion(CashShopVersionRequest*)` draft below |
| `0002TT` | `85/88` | `88/90` | keep `CANONICAL_OWNER:0000JC`, `EMITTER_UIDS:0000JC` | populate with `DownloadCashShopCatalog(CashShopRequest*)` draft below |

The three helpers should remain source-emitting FileDownloader-local worker helpers in `NexusTK/network/FileDownloader.cpp`. Feature-owned pages remain context owners for payload classes and consumed state, but the live caller route, dispatcher switch, thread-queue submit helpers, URL literals, WinINet behavior, and cleanup responsibilities all point to FileDownloader as the emitting source file for the helper bodies.

Source-facing names/signatures:

```cpp
static bool __stdcall DownloadMinimapFile(FileDownloaderMinimapRequest* request);
static void __stdcall DownloadCashShopVersion(CashShopVersionRequest* request);
static void __stdcall DownloadCashShopCatalog(CashShopRequest* request);
```

Best current payload/state names:

| Address/offset | Recommended source-facing name/type | Evidence and confidence |
| --- | --- | --- |
| `0x0067a738` / current `g_pCashShopRequest` | `FileDownloader* g_pFileDownloader` or, if the original header used a facade name, `FileDownloader* g_pDownloadDispatcher` | Nine code refs; five FileDownloader-family writes/clears; submit-helper callers pass this pointer as `ecx` to FileDownloader queue methods. The current `g_pCashShopRequest` name is misleading for this storage. |
| `0x0067a73c` | `FittingRoomDialog* g_pFittingRoomDialog` | Separate adjacent global; version/catalog helpers read it; fitting-room docs already use this role. |
| `FileDownloaderMinimapRequest +0x00` | `state` / `status` byte | Submit helper zeroes; download helper does not use materially. |
| `FileDownloaderMinimapRequest +0x04` | `contentLength` or reserved progress dword | Submit helper zeroes; minimap helper does not update, unlike cash-shop workers. Prefer `contentLength` only if a shared request struct is desired; otherwise `reservedLength`. |
| `FileDownloaderMinimapRequest +0x08` | `bytesDownloaded` or reserved progress dword | Submit helper zeroes; minimap helper tracks progress locally. Prefer `bytesDownloaded` only if a shared request struct is desired. |
| `FileDownloaderMinimapRequest +0x0c` | `mapId` | Used by `DownloadMinimapFile` to format the three-digit minimap directory. |
| `FileDownloaderMinimapRequest +0x10` | `wchar_t outputPath[0x104]` | Submit helper copies arg3 with `_wcscpy_s(..., 0x104)`; download helper opens this as the destination path. |
| `FileDownloaderMinimapRequest +0x218` | `wchar_t mapCode[0x10]` / `mapName[0x10]` | Submit helper copies arg2 with `_wcscpy_s(..., 0x10)`; download helper inserts it before `.mnm` in the URL. Use `mapCode` in docs because it is a short URL component, not the destination path. |
| `CashShopVersionRequest +0x04` | `state` / `status` byte | Constructor/submit helper zeroes; version helper does not set a completion flag. |
| `CashShopVersionRequest +0x08` | `contentLength` | `DownloadCashShopVersion` stores HTTP content length. |
| `CashShopVersionRequest +0x0c` | `bytesDownloaded` | `DownloadCashShopVersion` updates running bytes read. |
| `CashShopRequest +0x04` | `downloadComplete` | `DownloadCashShopCatalog` writes `1` after successful read loop. |
| `CashShopRequest +0x08` | `contentLength` | `DownloadCashShopCatalog` stores HTTP content length. |
| `CashShopRequest +0x0c` | `bytesDownloaded` | `DownloadCashShopCatalog` updates running bytes read. |
| `CashShopRequest +0x10` | `std::string responseText` / `catalogJson` | Submit helper initializes MSVC/Dinkumware small string fields; catalog helper appends downloaded chunks. Use `catalogJson` in behavior prose and `responseText` if a reused payload class declaration is preferred. |
| `FittingRoomDialog +0x790` | `m_itemShopVersion` (`std::string`-style field) | Version helper copies JSON key `version` here through `dword_67A73C + 1936`; fitting-room parser also uses the `version` key. |
| `FittingRoomDialog +0x7a8` | `m_activeCatalogRequest` (`CashShopRequest*`) | Submit helper stores the catalog payload here; catalog helper compares this pointer before self-destruction. |

The current source-quality blockers in the primary pages are resolved to a level that supports first-draft formal C++. The C++ below is not raw decompiler output: it uses source-facing payload names, FileDownloader-local static helper shape, WinINet APIs, JsonCpp/source string usage, and mid-2000s C++ style. Remaining caveats should cap the targets around `88/90`, not keep C++ blank.

## Evidence Checked

Read and compared current documentation:

- Supervisor/B-agent rules: `Supervisor.md`, `Agent-B001/goal.md`, `Agent-B001/notes.md`, `by-structure.md`, `Agent-B001/inference_research.md`.
- Primary target pages [UID:0002TR], [UID:0002TS], [UID:0002TT].
- File/class support: [UID:0000JC] `by-file/FileDownloader.md`, [UID:00004W] `by-class/FileDownloader.md`, [UID:0000WI] `FileDownloaderDispatch`, [UID:0002TU] `FileDownloaderOnMessage`.
- Submit helpers: [UID:0002CJ] `FileDownloaderSubmitMinimapRequest`, [UID:0002CK] `FileDownloaderSubmitCashShopCatalogRequest`, [UID:0002CL] `FileDownloaderSubmitCashShopVersionRequest`.
- Constants/global support: [UID:0001SF] `DownloaderMessageIds`, [UID:0000QH] `g_pCashShopRequest`, [UID:0001OP] `0x0067a738-0x0067a73c.g_pCashShopRequest`.
- Feature context: [UID:0000LE] `MiniMap`, [UID:00008D] `MiniMapDownloader`, [UID:0000I1]/[UID:00001I] `CashShopVersionRequest`, [UID:0000JE] `FittingRoom`, [UID:0000WU] `FittingRoomItemShopCatalogState`.
- Literal support around `0x0060d7e0-0x0060d9c0`, including [UID:0003FY], [UID:0003FZ], [UID:0003G0], [UID:0003G1], and [UID:0003G2].
- Current coverage rows in `by-memory/-coverage-report.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-type/by-constant/-coverage-report.md`.
- Generated/recovered output as leads only: `simroot_v2/recovered/DownloadMinimapFile_0041A750.cpp`, `DownloadCashShopVersion_0041AA00.cpp`, `DownloadCashShopCatalog_0041AE20.cpp`, and `auto-generated/NexusTK/network/FileDownloader.cpp`.

Live IDA MCP status:

- Direct HTTP MCP attempt to `http://127.0.0.1:13337/mcp` failed with `MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Because the MCP endpoint was unavailable, this report uses current IDA-backed docs plus read-only local PE checks against `E:\NTK\Resources\NexusTK\NexusTK.exe`. Older IDA evidence is treated as a lead where not reconfirmed locally.

Read-only raw PE evidence collected this pass:

- PE image base is `0x00400000`; `.text` begins at `0x00401000`, `.rdata` at `0x0060d000`, `.data` at `0x0066d000`.
- `call rel32` scan over `.text` found exactly one direct call to each primary helper:
  - `DownloadMinimapFile` `0x0041a750`: caller `0x0041b168`.
  - `DownloadCashShopVersion` `0x0041aa00`: caller `0x0041b13c`.
  - `DownloadCashShopCatalog` `0x0041ae20`: caller `0x0041b156`.
- No immediate/pointer-table refs to the three helper starts were found in `.text`; the route is a normal direct dispatcher call, not a hidden callback/table route.
- Immediate refs to `0x0067a738`: nine code references at `0x0041a6b2`, `0x0041a6ba`, `0x0041a724`, `0x0041b2f2`, `0x0041b64b`, `0x0041c217`, `0x0041cd0b`, `0x00451cfa`, `0x00464a9a`.
- Immediate refs to `0x0067a73c`: sixteen code references including version/catalog helper refs at `0x0041ad76` and `0x0041b0bb`; this confirms it is a separate fitting-room global, not the FileDownloader singleton.
- Capstone disassembly of [UID:0002TR] confirmed 207 instructions and WinINet/file API calls; selected literal push `0x0060d7e0` (`HTTPTEST`) at `0x0041a773`.
- Capstone disassembly of [UID:0002TS] confirmed 275 instructions, calls to WinINet, local string helpers `0x0041b8b0`/`0x0041b740`, JsonCpp helpers `0x004298f0` and `0x00429b30`, JSON helper range `0x00424c90-0x004278e0`, and fitting-room global read at `0x0041ad75`.
- Capstone disassembly of [UID:0002TT] confirmed 215 instructions, calls to WinINet/string helpers, completion write at `0x0041b0b6`, fitting-room global read at `0x0041b0ba`, active-request compare `[eax+0x7a8]` at `0x0041b0c3`, and virtual destroy call through `[esi]` at `0x0041b0d1`.
- Capstone/byte checks of submit helpers reconfirmed:
  - `0x0041b180`: `push 0x238`, `_wcscpy_s` to `+0x218` size `0x10`, `_wcscpy_s` to `+0x10` size `0x104`, post `0x2710`.
  - `0x0041b200`: `push 0x28`, vtable store `0x0060d7a0`, small string init at `+0x10/+0x20/+0x24`, post `0x2711`, read `0x0067a73c`.
  - `0x0041b270`: `push 0x10`, vtable store `0x0060d798`, zero `+0x04/+0x08/+0x0c`, post `0x2712`, null-allocation fallback also posts `0x2712`.
- Capstone disassembly of `FileDownloader::OnMessage` at `0x0041b110-0x0041b180` reconfirmed payload null checks before all three worker calls. Message `10002` tests payload at `0x0041b137` before `call 0x0041aa00`, message `10001` tests at `0x0041b151` before `call 0x0041ae20`, and message `10000` tests at `0x0041b163` before `call 0x0041a750`.

## Heuristic / Inference Reanalysis And Validation

### Direct entry/caller route

Validated current docs. Each helper has one direct code route from `FileDownloader::OnMessage`:

- `0x0041b168 -> 0x0041a750` for message `10000`.
- `0x0041b13c -> 0x0041aa00` for message `10002`.
- `0x0041b156 -> 0x0041ae20` for message `10001`.

Rejected alternatives:

- Hidden table/callback route: rejected for the current evidence set. Raw `.text` scan found no pointer/immediate refs to the three helper starts; current docs and raw call scan both show direct dispatcher calls.
- Feature-owned direct call route: rejected for emitting ownership. MiniMap/FittingRoom paths submit requests through FileDownloader queue helpers; they do not call these worker bodies directly.

Impact: the primary pages keep `CANONICAL_OWNER:0000JC` and `EMITTER_UIDS:0000JC`.

### Message IDs and dispatcher semantics

Validated current docs and refined source names:

| Value | Recommended source constant | Submit helper | Worker helper |
| --- | --- | --- | --- |
| `10000` / `0x2710` | `kDownloadMinimapFileMessage` or `MSG_DOWNLOAD_MINIMAP_FILE` | `SubmitMinimapRequest` | `DownloadMinimapFile` |
| `10001` / `0x2711` | `kDownloadCashShopCatalogMessage` or `MSG_DOWNLOAD_CASHSHOP_CATALOG` | `SubmitCashShopCatalogRequest` | `DownloadCashShopCatalog` |
| `10002` / `0x2712` | `kDownloadCashShopVersionMessage` or `MSG_DOWNLOAD_CASHSHOP_VERSION` | `SubmitCashShopVersionRequest` | `DownloadCashShopVersion` |

Best current source style is a file-local enum in `FileDownloader.cpp`, not socket opcode docs and not a public protocol enum. Original spelling is not provable, but the enum/constant meaning is now source-quality and can replace "final enum spelling provisional" with a high-probability file-local constant recommendation.

### FileDownloader-local helper versus feature-owned helper placement

Ranked ownership:

1. **FileDownloader-local static worker helpers in `NexusTK/network/FileDownloader.cpp`**: accepted. Only direct caller is `FileDownloader::OnMessage`; submit helpers post through `sub_596960` on the FileDownloader singleton; WinINet session/timeout/status handling is shared across all three bodies; item-shop URL literal children [UID:0003G0]/[UID:0003G2] already route to FileDownloader; dispatcher request lifetime differs by message and is implemented around the FileDownloader switch.
2. **MiniMap/MiniMapDownloader ownership for [UID:0002TR]**: rejected as emitter. Minimap feature code supplies request data, and the S3 minimap literals are related to minimap behavior, but [UID:00008D] `MiniMapDownloader` has a separate singleton/task route and `DownloadMinimap_453AA0`. The `0x0041a750` body is reached by FileDownloader message `10000`, not by the MiniMapDownloader virtual task path.
3. **CashShopVersionRequest ownership for [UID:0002TS]**: rejected as emitter. The payload class is real, but the worker body is selected by FileDownloader message `10002` and uses shared FileDownloader WinINet dispatch. Keep `CashShopVersionRequest` as the payload type owner and context page.
4. **FittingRoom/catalog state ownership for [UID:0002TT]**: rejected as emitter. FittingRoom owns the active request pointer and later catalog parsing, but the HTTP worker is dispatched and run by FileDownloader.
5. **New request/payload source grouping**: not needed for these by-memory emitters. A later header could introduce `DownloadRequests.h` or cash-shop payload declarations, but it would not move the worker function bodies out of FileDownloader.

Impact: primary targets receive first-draft C++ under FileDownloader. Support docs should explicitly separate "payload type owner" from "worker function emitter".

### Payload structure names and field types

Validated and refined from submit-helper writes plus worker reads/writes:

- `FileDownloaderMinimapRequest` is a raw `0x238` allocation, not a vtable class. It is freed by the dispatcher after `DownloadMinimapFile` returns. Field names should be descriptive rather than class-method names:
  - `state` at `+0x00` remains low-impact because no meaningful use was found.
  - `contentLength` and `bytesDownloaded` at `+0x04/+0x08` are plausible shared-progress fields, but the minimap helper does not update them. Use "reserved progress fields" in docs unless a shared request type is later declared.
  - `mapId` at `+0x0c` is high confidence.
  - `outputPath[0x104]` at `+0x10` is high confidence.
  - `mapCode[0x10]` at `+0x218` is high confidence. Generated `mapCode[32]` is rejected because the submit helper copies exactly `0x10` wide characters and the allocation ends at `0x238`.
- `CashShopVersionRequest` is a `0x10` vtable payload with `state`, `contentLength`, and `bytesDownloaded`. It is destroyed by the dispatcher after the worker returns.
- `CashShopRequest` / `CashShopCatalogRequest` is a `0x28` vtable payload. The actual vtable name is `CashShopRequest`; behavior role is catalog request. Use class type `CashShopRequest` and field role `catalogJson`/`responseText`.

Rejected alternatives:

- Treating `+0x04` on `CashShopRequest` as a generic state code: rejected for docs. The catalog worker writes exactly `1` after successful completion and the active-owner check follows. `downloadComplete` is more source-facing.
- Treating minimap `+0x218` as a 32-wchar field: rejected by allocation size and `_wcscpy_s(..., 0x10)`.
- Treating `CashShopVersionRequest +0x04` as a completion flag: not supported by the version helper body; it is initialized but not set by the worker.

### `dword_67A738` source-facing name/type

Current docs already prove FileDownloader lifetime but still leave the public source name/type open. This pass raises the inference:

- Best source-facing declaration: `FileDownloader* g_pFileDownloader`.
- Acceptable alternate if supervisor wants to preserve a facade caveat: `FileDownloader* g_pDownloadDispatcher`.
- Reject `CashShopRequest* g_pCashShopRequest` as final source-facing type/name for this storage.

Evidence:

- All five direct writes/clears are FileDownloader constructor/destructor/unwind/scalar-deleting paths.
- Application cleanup deletes the object through this global.
- The three fitting-room/minimap submit callers pass this pointer as the `this` argument to FileDownloader queue helpers.
- The actual `CashShopRequest` catalog payload is a separate `0x28` object allocated inside `0x0041b200`; it is not this global.
- The separate outbound packet sender is `0x0067a7ec`, already documented as not this storage.

Remaining uncertainty: original global spelling may have been a facade name rather than exactly `g_pFileDownloader`. That uncertainty should be documented, but it should not block target C++ or keep the misleading `g_pCashShopRequest` as the primary name.

### `dword_67A73C` and fitting-room field names

Best current names:

- `0x0067a73c`: `g_pFittingRoomDialog`.
- `FittingRoomDialog +0x790`: `m_itemShopVersion`.
- `FittingRoomDialog +0x7a8`: `m_activeCatalogRequest`.

Evidence:

- `DownloadCashShopVersion` reads `dword_67A73C`, checks non-null, and writes/copies JSON key `version` to `+0x790`.
- `FileDownloaderSubmitCashShopCatalogRequest` writes the allocated catalog request to `dword_67A73C + 0x7a8`.
- `DownloadCashShopCatalog` compares `dword_67A73C + 0x7a8` with the current payload and only self-destroys the request when no active owner matches.
- FittingRoom and FittingRoomItemShopCatalogState docs already associate version/catalog parsing with fitting-room item-shop state.

Rejected alternatives:

- Treating `+0x790` as a global version string not owned by FittingRoom: rejected because the write is through the fitting-room dialog pointer.
- Treating `+0x7a8` as a generic "last request" field: lower quality than `m_activeCatalogRequest` because cleanup semantics specifically protect the active catalog request from self-deletion.

### WinINet timeout/status behavior and cleanup

Validated:

- All three helpers open WinINet with shared user-agent literal `HTTPTEST`.
- Cash-shop helpers set repeated `3000` ms timeout options, require HTTP status `200`, query content length, then stream with `InternetQueryDataAvailable` and `InternetReadFile`.
- [UID:0002TR] writes directly to a local file and deletes the partial wide path on failed stream/write completion.
- [UID:0002TS] accumulates response into a temporary string, parses JsonCpp root, reads `version`, and updates fitting-room state.
- [UID:0002TT] appends bytes into the request string, sets progress/completion fields, and conditionally destroys the request if no active fitting-room owner holds it.

Rejected alternatives:

- "Fire-and-forget URL fetcher" for [UID:0002TS]/[UID:0002TT]: too weak; content-length/progress fields and ownership cleanup are observable.
- Direct catalog parsing in [UID:0002TT]: rejected; catalog helper downloads JSON into the request string. The parser cluster lives in FittingRoom item-shop state pages.

### Generated-output/source data validation

Generated/recovered source was used only as a lead:

- `auto-generated/NexusTK/network/FileDownloader.cpp` currently has no useful formal body for these pages, matching the blank C++ state.
- Recovered helper files have useful behavior sketches but are not source authority. The minimap recovered type's `mapCode[32]` conflicts with the submit-helper `_wcscpy_s(..., 0x10)` and is rejected.
- Recovered cash-shop helper bodies use modern `nullptr`/ad-hoc JSON scanning in places; the recommended first-draft C++ below uses source-style WinINet/JsonCpp calls and avoids treating recovered output as final code.

## Open Questions Resolved Or Remaining

Resolved/high-probability:

- The three worker helpers are FileDownloader-local static source helpers and should emit in [UID:0000JC], not in MiniMap, FittingRoom, or CashShopVersionRequest pages.
- Direct caller route is only `FileDownloader::OnMessage` for each helper; no hidden pointer-table route was found.
- Message IDs `10000`, `10001`, `10002` are FileDownloader worker messages, not socket protocol opcodes.
- `0x0067a738` should be treated as FileDownloader/download-dispatch singleton storage. The current `g_pCashShopRequest` name is stale/misleading as a primary source name.
- `0x0067a73c` is the fitting-room dialog pointer; `+0x790` is item-shop version state; `+0x7a8` is active catalog request ownership.
- Payload field names and signatures are resolved for formal C++ entry.

Remaining, with impact:

- Exact original global spelling for `0x0067a738` is still not provable. Use `g_pFileDownloader` as the best source-facing name, with an explicit note that a later recovered header could expose it as a download-dispatch facade. Impact: do not push this support global above roughly `90/91`; does not block primary target C++.
- Exact original enum style for message IDs (`enum`, `#define`, unnamed constants) is not provable. Use file-local enum names in first-draft C++. Impact: [UID:0001SF] can be raised modestly but should not be treated as final original spelling.
- Exact project string typedef name is not recovered from these targets alone. The `0x28` payload layout and MSVC small-string fields fit a Dinkumware `std::string`-style object; use `std::string` or the project's known string wrapper consistently during supervisor application. Impact: C++ is first draft, not final 95+ code.

## First-Draft C++ Recommendation

Populate formal C++ for all three primary targets. The snippets below assume common declarations are available once in the FileDownloader source context. If the supervisor wants each by-memory block to stand alone, keep the declarations in [UID:0000JC] support text and place only the corresponding function body in each primary `RECONSTRUCTION_CPP CODE` block.

Common FileDownloader source declarations recommended for [UID:0000JC] support:

```cpp
enum FileDownloaderMessageId {
    kDownloadMinimapFileMessage = 10000,
    kDownloadCashShopCatalogMessage = 10001,
    kDownloadCashShopVersionMessage = 10002
};

struct FileDownloaderMinimapRequest {
    unsigned char state;
    unsigned char reserved0[3];
    unsigned long contentLength;
    unsigned long bytesDownloaded;
    unsigned long mapId;
    wchar_t outputPath[0x104];
    wchar_t mapCode[0x10];
};

class CashShopVersionRequest {
public:
    virtual ~CashShopVersionRequest();

    unsigned char state;
    unsigned char reserved0[3];
    unsigned long contentLength;
    unsigned long bytesDownloaded;
};

class CashShopRequest {
public:
    virtual ~CashShopRequest();

    unsigned char downloadComplete;
    unsigned char reserved0[3];
    unsigned long contentLength;
    unsigned long bytesDownloaded;
    std::string responseText;
};

class FittingRoomDialog {
public:
    std::string m_itemShopVersion;          // recovered offset +0x790
    CashShopRequest* m_activeCatalogRequest; // recovered offset +0x7a8
};

extern FittingRoomDialog* g_pFittingRoomDialog;
```

### [UID:0002TR] `DownloadMinimapFile`

```cpp
static bool __stdcall DownloadMinimapFile(FileDownloaderMinimapRequest* request)
{
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return false;
    }

    wchar_t directory[4];
    wchar_t url[MAX_PATH * 2];

    wsprintfW(directory, L"%03d", request->mapId / 1000);
    wsprintfW(url,
              L"%s%s/%s%s",
              L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/",
              directory,
              request->mapCode,
              L".mnm");

    HINTERNET remoteFile = InternetOpenUrlW(internet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return false;
    }

    unsigned long statusLength = 16;
    wchar_t statusText[16];
    bool ok = false;

    if (HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL) &&
        _wtoi(statusText) == HTTP_STATUS_OK) {
        HANDLE localFile = CreateFileW(request->outputPath,
                                       GENERIC_WRITE,
                                       0,
                                       NULL,
                                       CREATE_ALWAYS,
                                       FILE_ATTRIBUTE_NORMAL,
                                       NULL);
        if (localFile != INVALID_HANDLE_VALUE) {
            char buffer[0x4000];
            unsigned long totalBytes = 0;

            for (;;) {
                unsigned long available = 0;
                unsigned long bytesRead = 0;
                unsigned long bytesWritten = 0;

                if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0)) {
                    break;
                }

                if (available == 0) {
                    ok = true;
                    break;
                }

                if (available > sizeof(buffer)) {
                    available = sizeof(buffer);
                }

                if (!InternetReadFile(remoteFile, buffer, available, &bytesRead)) {
                    break;
                }

                if (bytesRead == 0) {
                    ok = true;
                    break;
                }

                if (!WriteFile(localFile, buffer, bytesRead, &bytesWritten, NULL) ||
                    bytesWritten != bytesRead) {
                    break;
                }

                totalBytes += bytesWritten;

                wchar_t progress[64];
                wsprintfW(progress, L"Downloading : %d\n", totalBytes);
                OutputDebugStringW(progress);
            }

            CloseHandle(localFile);
        }
    }

    InternetCloseHandle(remoteFile);
    InternetCloseHandle(internet);

    if (!ok) {
        DeleteFileW(request->outputPath);
    }

    return ok;
}
```

Notes for supervisor application:

- If exact binary modeling wants to preserve the decompiled `void*` return, use `bool` in support prose and `void*` only as a compiler artifact. The dispatcher ignores the result; the source-style helper naturally returns success/failure.
- The body deliberately uses `mapCode[0x10]`, not generated `mapCode[32]`.

### [UID:0002TS] `DownloadCashShopVersion`

```cpp
static void __stdcall DownloadCashShopVersion(CashShopVersionRequest* request)
{
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return;
    }

    HINTERNET remoteFile = InternetOpenUrlW(internet,
                                            L"https://secure.kru.com/itemshop/data/itemshop.ver",
                                            NULL,
                                            0,
                                            INTERNET_FLAG_RELOAD,
                                            0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return;
    }

    unsigned long timeout = 3000;
    InternetSetOptionW(remoteFile, INTERNET_OPTION_CONNECT_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

    unsigned long statusLength = 16;
    wchar_t statusText[16];

    if (HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL) &&
        _wtoi(statusText) == HTTP_STATUS_OK) {
        unsigned long lengthSize = sizeof(request->contentLength);
        request->contentLength = 0;
        request->bytesDownloaded = 0;
        HttpQueryInfoW(remoteFile,
                       HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER,
                       &request->contentLength,
                       &lengthSize,
                       NULL);

        std::string responseText;
        char buffer[0x4000];

        for (;;) {
            unsigned long available = 0;
            unsigned long bytesRead = 0;

            if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0)) {
                break;
            }

            if (available == 0) {
                break;
            }

            if (available > sizeof(buffer)) {
                available = sizeof(buffer);
            }

            if (!InternetReadFile(remoteFile, buffer, available, &bytesRead) || bytesRead == 0) {
                break;
            }

            responseText.append(buffer, bytesRead);
            request->bytesDownloaded += bytesRead;

            wchar_t progress[64];
            wsprintfW(progress,
                      L"Downloading : %d / %d\n",
                      request->bytesDownloaded,
                      request->contentLength);
            OutputDebugStringW(progress);
        }

        Json::Reader reader;
        Json::Value root;
        if (reader.parse(responseText, root)) {
            const Json::Value& versionValue = root["version"];
            if (!versionValue.isNull() && g_pFittingRoomDialog != NULL) {
                g_pFittingRoomDialog->m_itemShopVersion = versionValue.asString();
            }
        }
    }

    InternetCloseHandle(remoteFile);
    InternetCloseHandle(internet);
}
```

Notes for supervisor application:

- If the project has a named SSO string wrapper instead of direct `std::string`, replace `std::string` mechanically. The binary layout and helper calls support an MSVC/Dinkumware small-string object; the source intent is "accumulate response text then parse with JsonCpp."
- The worker does not delete `request`; the dispatcher destroys the version payload after this helper returns.

### [UID:0002TT] `DownloadCashShopCatalog`

```cpp
static void __stdcall DownloadCashShopCatalog(CashShopRequest* request)
{
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return;
    }

    HINTERNET remoteFile = InternetOpenUrlW(internet,
                                            L"https://secure.kru.com/itemshop/data/itemshop.json",
                                            NULL,
                                            0,
                                            INTERNET_FLAG_RELOAD,
                                            0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return;
    }

    unsigned long timeout = 3000;
    InternetSetOptionW(remoteFile, INTERNET_OPTION_CONNECT_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

    unsigned long statusLength = 16;
    wchar_t statusText[16];

    if (HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL) &&
        _wtoi(statusText) == HTTP_STATUS_OK) {
        unsigned long lengthSize = sizeof(request->contentLength);
        request->contentLength = 0;
        request->bytesDownloaded = 0;
        HttpQueryInfoW(remoteFile,
                       HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER,
                       &request->contentLength,
                       &lengthSize,
                       NULL);

        char buffer[0x4000];

        for (;;) {
            unsigned long available = 0;
            unsigned long bytesRead = 0;

            if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0)) {
                break;
            }

            if (available == 0) {
                request->downloadComplete = 1;
                break;
            }

            if (available > sizeof(buffer)) {
                available = sizeof(buffer);
            }

            if (!InternetReadFile(remoteFile, buffer, available, &bytesRead) || bytesRead == 0) {
                request->downloadComplete = 1;
                break;
            }

            request->responseText.append(buffer, bytesRead);
            request->bytesDownloaded += bytesRead;

            wchar_t progress[64];
            wsprintfW(progress,
                      L"Downloading : %d / %d\n",
                      request->bytesDownloaded,
                      request->contentLength);
            OutputDebugStringW(progress);
        }
    }

    InternetCloseHandle(remoteFile);
    InternetCloseHandle(internet);

    if (request->downloadComplete &&
        (g_pFittingRoomDialog == NULL ||
         g_pFittingRoomDialog->m_activeCatalogRequest != request)) {
        delete request;
    }
}
```

Notes for supervisor application:

- The request type should remain `CashShopRequest` if matching the existing vtable class; document "catalog request role" in behavior prose.
- The conditional delete is important source shape: this helper self-disposes only when the fitting-room dialog does not still own the active catalog request.

## Exact Supervisor Changes Required

### Primary target metadata

Apply:

- [UID:0002TR] change `COMPLETION:85` to `COMPLETION:88`; change `CONFIDENCE:88` to `CONFIDENCE:90`; keep owner/emitter; populate formal C++ with the [UID:0002TR] body above.
- [UID:0002TS] change `COMPLETION:85` to `COMPLETION:88`; change `CONFIDENCE:89` to `CONFIDENCE:90`; keep owner/emitter; populate formal C++ with the [UID:0002TS] body above.
- [UID:0002TT] change `COMPLETION:85` to `COMPLETION:88`; change `CONFIDENCE:88` to `CONFIDENCE:90`; keep owner/emitter; populate formal C++ with the [UID:0002TT] body above.

Add to each primary page under `## Confidence And Open Questions`, replacing the open source-placement/payload blocker bullets:

```text
- Resolved by B001 2026-06-18: keep the helper as a FileDownloader-local worker emitted through [UID:0000JC][FileDownloader](by-file/FileDownloader.md). The only confirmed direct caller is `FileDownloader::OnMessage`; feature pages own payload/state context but do not emit this worker body.
- Resolved by B001 2026-06-18: source-facing payload names and fields are sufficient for first-draft C++. Use the request layouts recorded in the B001 FileDownloader download-helper report; remaining exact original spelling caveats cap the target around `88/90` but no longer justify blank formal C++.
```

For [UID:0002TR], add the specific payload note:

```text
- `FileDownloaderMinimapRequest` is a raw `0x238` block. Best current fields: `state` at `+0x00`, reserved/progress dwords at `+0x04/+0x08`, `mapId` at `+0x0c`, `outputPath[0x104]` at `+0x10`, and `mapCode[0x10]` at `+0x218`. Reject generated `mapCode[32]`; `_wcscpy_s` receives size `0x10` and the allocation ends at `0x238`.
```

For [UID:0002TS], add:

```text
- `CashShopVersionRequest` is a `0x10` vtable payload with `state` at `+0x04`, `contentLength` at `+0x08`, and `bytesDownloaded` at `+0x0c`. The worker downloads `itemshop.ver`, parses JSON key `version`, and writes the result to `g_pFittingRoomDialog->m_itemShopVersion` (`dword_67A73C + 0x790`). The dispatcher, not this worker, destroys the version request after return.
```

For [UID:0002TT], add:

```text
- `CashShopRequest` is a `0x28` vtable payload used here as the catalog download request. Best current fields: `downloadComplete` at `+0x04`, `contentLength` at `+0x08`, `bytesDownloaded` at `+0x0c`, and `responseText`/`catalogJson` at `+0x10`. The fitting-room active-owner slot is `g_pFittingRoomDialog->m_activeCatalogRequest` (`dword_67A73C + 0x7a8`); this worker deletes the request only when that slot does not still point to the current payload.
```

### Support doc changes

[UID:0000JC] `by-file/FileDownloader.md`:

- Recommended metadata: keep at least `85/88`; better update to `87/90` after applying this report because the helper/payload/global blockers listed in the current score rationale are resolved. Do not exceed `87/90` until `StartThread` ownership and class declarations are separately finalized.
- In `Likely Contents`, replace address-suffixed helper names:

```text
- `DownloadMinimapFile`, the message `10000` single-file minimap worker helper.
- `DownloadCashShopCatalog`, the message `10001` item-shop catalog worker helper.
- `DownloadCashShopVersion`, the message `10002` item-shop version worker helper.
- `g_pFileDownloader` / `0x0067a738`, the FileDownloader-lifetime worker-thread download dispatcher singleton. `g_pCashShopRequest` remains a historical/generated alias for this address, not the preferred source-facing name.
```

- Replace the current `Dispatch Map` rows with:

```text
| `10000` | `DownloadMinimapFile` | Calls helper, then frees the raw `FileDownloaderMinimapRequest` block. | Minimap file update request submitted through FileDownloader. |
| `10001` | `DownloadCashShopCatalog` | Calls helper; helper destroys the `CashShopRequest` catalog payload unless `FittingRoomDialog::m_activeCatalogRequest` still owns it. | Cash-shop/fitting-room catalog download. |
| `10002` | `DownloadCashShopVersion` | Calls helper, then destroys the `CashShopVersionRequest` payload through its vtable. | Cash-shop/fitting-room version check. |
```

- Replace the score caveat "StartThread, source-facing singleton type/name, and payload/request declarations are still provisional" with:

```text
Completion remains below final-source level because `StartThread` may still belong to shared `Thread` infrastructure and the exact original declaration style for FileDownloader message constants/string typedefs is not proven. The downloader singleton role and the primary request payload layouts are now source-quality: `0x0067a738` should be documented as a FileDownloader/download-dispatcher singleton, the primary worker helpers emit in this file, and the minimap/version/catalog payload field names are sufficient for first-draft C++.
```

[UID:00004W] `by-class/FileDownloader.md`:

- Recommended metadata: `86/90` if the support text is updated, but do not populate a full class declaration solely from this report. The three primary by-memory functions can receive C++ now; the whole class still needs a dedicated class-declaration pass.
- Replace current boundary caution:

```text
- The class writes to [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`. The address and FileDownloader lifetime are now reliable, but the final C++ type/name remains open.
```

with:

```text
- The class writes to `0x0067a738`, best source-facing name `g_pFileDownloader` (`FileDownloader*`) or `g_pDownloadDispatcher` if a later header proves a facade name. The old `g_pCashShopRequest` name is retained only as a historical/generated alias for this address; it should not type the storage as a `CashShopRequest*`.
```

[UID:0001SF] `DownloaderMessageIds`:

- Recommended metadata: `88/90`.
- Populate or support a file-local enum, if the supervisor is comfortable entering constants:

```cpp
enum FileDownloaderMessageId {
    kDownloadMinimapFileMessage = 10000,
    kDownloadCashShopCatalogMessage = 10001,
    kDownloadCashShopVersionMessage = 10002
};
```

- Replace `Open Questions` with:

```text
- Exact original spelling remains unproven (`enum`, unnamed enum, or `#define`s), but the source meaning and FileDownloader-local placement are now high-probability. Use `FileDownloaderMessageId`/`kDownload...Message` as first-draft source names; do not keep the values as socket opcodes or generic numeric constants.
```

[UID:0000QH] and [UID:0001OP] global/storage pages:

- Recommended rename:
  - `by-global/g_pCashShopRequest.md` -> `by-global/g_pFileDownloader.md`
  - `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md` -> `by-memory/0x0067a738-0x0067a73c.g_pFileDownloader.md`
- Keep UID values unchanged.
- Recommended metadata after rename/support update:
  - [UID:0000QH] `90/91`
  - [UID:0001OP] `89/91`
- Recommended C++ declaration:

```cpp
FileDownloader* g_pFileDownloader;
```

- If the supervisor does not want a file rename yet, replace the page title/status text while keeping the current filenames, and add:

```text
Current filename is stale. The storage at `0x0067a738` has FileDownloader lifetime and should be treated as `FileDownloader* g_pFileDownloader` / download-dispatcher singleton state. `g_pCashShopRequest` is a historical/generated alias only.
```

[UID:0002CJ]/[UID:0002CK]/[UID:0002CL] submit-helper pages:

- Metadata can remain `85/90`; this report is not a full submit-helper formal C++ pass.
- Replace "final source-facing helper/request names remain provisional" with:

```text
B001 2026-06-18 source-quality pass recommends `SubmitMinimapRequest`, `SubmitCashShopCatalogRequest`, and `SubmitCashShopVersionRequest` as source-facing FileDownloader queue helper names. Payload class/field names should match the FileDownloader download-helper report: `FileDownloaderMinimapRequest`, `CashShopRequest` catalog payload, and `CashShopVersionRequest`.
```

[UID:0000LE]/[UID:00008D] MiniMap/MiniMapDownloader:

- No metadata change required.
- Add support note:

```text
`DownloadMinimapFile` at `0x0041a750` is a FileDownloader message `10000` worker helper, not the same source body as MiniMapDownloader's task handler. MiniMap remains feature context for the request data and S3 minimap resources; FileDownloader emits the worker body.
```

[UID:0000I1]/[UID:00001I] CashShopVersionRequest:

- No metadata change required unless supervisor wants to raise after support text.
- Add support note:

```text
The version payload layout is `vtable + state(+0x04) + contentLength(+0x08) + bytesDownloaded(+0x0c)`. The HTTP worker `DownloadCashShopVersion` remains FileDownloader-owned; this class owns the small request payload and destructor/vtable identity.
```

[UID:0000JE]/[UID:0000WU] FittingRoom/FittingRoomItemShopCatalogState:

- No metadata change required.
- Add support note:

```text
FileDownloader item-shop helpers update fitting-room state through `g_pFittingRoomDialog`: `DownloadCashShopVersion` copies JSON key `version` into `FittingRoomDialog::m_itemShopVersion` at `+0x790`, while catalog request submission/cleanup use `FittingRoomDialog::m_activeCatalogRequest` at `+0x7a8`. The catalog parser remains in the fitting-room item-shop state cluster; the HTTP worker remains in FileDownloader.
```

Literal pages [UID:0003FY]/[UID:0003FZ]/[UID:0003G0]/[UID:0003G1]/[UID:0003G2]:

- No ownership/metadata change required from this report. Current split remains valid: `HTTPTEST`, minimap URL fragments, and `version` are shared/cross-linked; `itemshop.ver` and `itemshop.json` remain FileDownloader children.

## Coverage Report Replacement Text

Do not edit coverage files directly from this B-agent report. Apply these rows only through supervisor workflow.

### `by-memory/-coverage-report.md`

Replace current primary rows in place:

```text
        - [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) 0x0041a750-0x0041a9fe | function | DownloadMinimapFile : reconstructable : 88% : very-strong : FileDownloader message `10000` worker; downloads S3 minimap `.mnm` data to the request `outputPath`, uses `mapId`/`mapCode` from a `0x238` raw request block, deletes partial output on failure, and now has first-draft FileDownloader-local C++.
            - [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) 0x0041aa00-0x0041ae1c | function | DownloadCashShopVersion : reconstructable : 88% : very-strong : FileDownloader message `10002` worker; downloads `itemshop.ver`, tracks `CashShopVersionRequest` content length/progress, parses JsonCpp key `version`, updates `FittingRoomDialog::m_itemShopVersion`, and now has first-draft FileDownloader-local C++.
            - [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md) 0x0041ae20-0x0041b10c | function | DownloadCashShopCatalog : reconstructable : 88% : very-strong : FileDownloader message `10001` worker; downloads `itemshop.json` into the `CashShopRequest` response string, tracks content length/progress, sets `downloadComplete`, preserves the active fitting-room catalog request at `+0x7a8`, and now has first-draft FileDownloader-local C++.
```

If the supervisor accepts the `0x0067a738` rename, replace [UID:0001OP] row:

```text
    - [UID:0001OP][0x0067a738-0x0067a73c.g_pFileDownloader](by-memory/0x0067a738-0x0067a73c.g_pFileDownloader.md) 0x0067a738-0x0067a73c | global pointer | g_pFileDownloader : reconstructable : 89% : very-strong : FileDownloader/download-dispatcher singleton pointer with exact zero storage, nine code refs, five FileDownloader-family writes/clears, three request-submit reads, application cleanup delete, neighboring `g_pFittingRoomDialog` boundary, stale `g_pCashShopRequest` alias rejection, and source declaration `FileDownloader* g_pFileDownloader`.
```

If filename rename is deferred, use the same row text but keep the existing link target:

```text
    - [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md) 0x0067a738-0x0067a73c | global pointer | g_pFileDownloader / stale alias g_pCashShopRequest : reconstructable : 89% : very-strong : FileDownloader/download-dispatcher singleton pointer with exact zero storage, nine code refs, five FileDownloader-family writes/clears, three request-submit reads, application cleanup delete, neighboring `g_pFittingRoomDialog` boundary, stale `g_pCashShopRequest` alias rejection, and source declaration `FileDownloader* g_pFileDownloader`.
```

### `by-file/-coverage-report.md`

If applying [UID:0000JC] score update, replace:

```text
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) : reconstructable : 87% : very-strong : `NexusTK/network/FileDownloader.cpp` thread-backed HTTP downloader with OnMessage cases `10000-10002`, FileDownloader-local minimap/version/catalog WinINet workers, source-quality request payload field layouts, first-draft helper C++, singleton `g_pFileDownloader` lifetime evidence, exact vtable/literal children, and remaining shared `StartThread`/final declaration caveats.
```

### `by-class/-coverage-report.md`

If applying [UID:00004W] score update, replace:

```text
- [UID:00004W][FileDownloader](by-class/FileDownloader.md) : reconstructable : 86% : very-strong : Thread-backed HTTP downloader class with constructor/destructor/global lifetime, OnMessage dispatch, submit-helper callsites, singleton `g_pFileDownloader` boundary, exact vtable child [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md), source-quality download worker names/payload fields, and remaining inherited `StartThread`/class-declaration caveats.
```

Leave [UID:00008D] and [UID:00001I] coverage rows unchanged unless supervisor applies support-only text without score changes.

### `by-global/-coverage-report.md`

If applying [UID:0000QH] rename, replace:

```text
- [UID:0000QH][g_pFileDownloader](by-global/g_pFileDownloader.md) : reconstructable : 90% : very-strong : FileDownloader/download-dispatcher singleton at `0x0067a738` with exact nine-ref writer/read matrix, five FileDownloader-family writes/clears, three request-submit reads, application cleanup delete, neighboring-global separation, stale `g_pCashShopRequest` alias rejection, and source declaration `FileDownloader* g_pFileDownloader`.
```

If filename rename is deferred:

```text
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) : reconstructable : 90% : very-strong : FileDownloader/download-dispatcher singleton at `0x0067a738`, best source name `g_pFileDownloader`, with exact nine-ref writer/read matrix, five FileDownloader-family writes/clears, three request-submit reads, application cleanup delete, neighboring-global separation, stale `g_pCashShopRequest` alias caveat, and source declaration `FileDownloader* g_pFileDownloader`.
```

### `by-type/by-constant/-coverage-report.md`

If applying [UID:0001SF] score update, replace:

```text
- [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md) : reconstructable : 88% : very-strong : FileDownloader worker-thread message constants `10000`/`10001`/`10002` for minimap file, cash-shop catalog, and cash-shop version downloads; dispatcher/submit-helper routes and first-draft file-local enum names are resolved, with only exact original enum-vs-define spelling still caveated.
```

## Files Changed By This Agent

- Created this report only: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002TR-0002TS-0002TT-FileDownloaderDownloadHelpers-source-quality.md`.

No by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002TR-0002TS-0002TT-FileDownloaderDownloadHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002TR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
