*** UID:0000JC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FileDownloader

## Status

- Confidence: very strong for dispatcher behavior, child function boundaries, submit-helper callsites, singleton lifetime, request inheritance, and the coordinated four-class source inventory; high for exact historical file spelling and source-facing global spelling.
- Proposed module: `network/FileDownloader.h` plus `network/FileDownloader.cpp`.
- Projected reconstruction path: `NexusTK/network/`
- Main class: [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- Related constants: [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md)
- Evidence basis: live IDA MCP lookup, caller/callee, decompile, xref, byte-padding, and exact vtable-dword checks through 2026-06-23.

## Hypothesis

`FileDownloader` is a shared thread-backed HTTP download dispatcher. It should be documented as network/download infrastructure, not as part of the game socket protocol and not as a cash-shop-only class.

The original source likely grouped the `FileDownloader` class with file-local WinINet worker helpers. The strongest split is:

```text
network/FileDownloader.cpp
```

An alternate old-project layout could have used `util/FileDownloader.cpp` if the team grouped all thread helpers together, but the WinINet URLs and message dispatch behavior make `network/` the better current reconstruction target.

## Likely Contents

- [UID:00050F][BaseRequest](by-class/BaseRequest.md), a non-polymorphic `0x0c` request-state base emitted first in the header and responsible for `downloadComplete`, `contentLength`, and `bytesDownloaded`.
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md), a `0x10` polymorphic BaseRequest-derived payload with no derived fields, emitted second.
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), a `0x28` polymorphic BaseRequest-derived payload with `std::string responseText` at `+0x10`, emitted third.
- [UID:00004W][FileDownloader](by-class/FileDownloader.md), including constructor/destructor, `OnMessage`, [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md), and the currently named `StartThread` helper.
- Exact source-declared vtable data [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md), including the destructor slot and `OnMessage` override slot.
- Exact item-shop download literal children [UID:0003G0][0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) and [UID:0003G2][0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md). The neighboring `HTTPTEST`, minimap, and shared narrow `version` key literal children remain cross-linked but unassigned because their xrefs span FileDownloader, MiniMapDownloader, FittingRoom, and StartupWindow consumers.
- `DownloadMinimapFile`, the message `10000` single-file minimap worker helper.
- `DownloadCashShopCatalog`, the message `10001` item-shop catalog worker helper.
- `DownloadCashShopVersion`, the message `10002` item-shop version worker helper.
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, best source-facing name `g_pFileDownloader` or `g_pDownloadDispatcher`, the FileDownloader-lifetime worker-thread download dispatcher singleton. `g_pCashShopRequest` remains a historical/generated alias for this address, not the preferred source-facing name.
- Request submission helpers [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), now attached to this parent as high-confidence downloader queue submit helpers while preserving cash-shop/minimap payload caveats.

`MiniMapDownloader` is related but should stay in [UID:0000LE][MiniMap](by-file/MiniMap.md) or `map/MiniMapDownloader.cpp`, because it has its own singleton, virtual task handler, and minimap-specific task structure.

## Dispatch Map

| Message ID | Current target | Request lifetime behavior | Likely feature owner |
| --- | --- | --- | --- |
| `10000` | `DownloadMinimapFile` | Calls helper, then frees the raw `FileDownloaderMinimapRequest` block. | Minimap file update request submitted through FileDownloader. |
| `10001` | `DownloadCashShopCatalog` | Calls helper; helper destroys the `CashShopRequest` catalog payload unless `FittingRoomDialog::m_activeCatalogRequest` still owns it. | Cash-shop/fitting-room catalog download. |
| `10002` | `DownloadCashShopVersion` | Calls helper, then destroys the `CashShopVersionRequest` payload through its vtable. | Cash-shop/fitting-room version check. |

The message IDs are currently documented at [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md). Do not reuse them as socket opcodes.

## 2026-06-23 B004 Aggregate Reclassification

[UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) is now a non-emitting exact-child inventory, not a FileDownloader-emitted aggregate. This does not change the FileDownloader route for the exact children:

- `DownloadCashShopVersion` [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) remains a FileDownloader-local worker for message `10002`. Current MCP session `80de0a67` reports one code xref to `0x0041aa00` at `0x0041b13c` inside `FileDownloader::OnMessage`; the PE route scan found the same direct control hit and no VA/RVA/raw-offset pointer route.
- `DownloadCashShopCatalog` [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md) remains a FileDownloader-local worker for message `10001`. Current MCP reports one code xref to `0x0041ae20` at `0x0041b156` inside `FileDownloader::OnMessage`; the PE route scan found the same direct control hit and no pointer-form route.
- `FileDownloader::OnMessage` [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md) remains the FileDownloader vtable-routed dispatcher. Current MCP reads `0x0041b110` from vtable slot `0x0060d7d4`; the PE route scan found the corresponding absolute-VA dword at raw `0x20c1d4`.
- The submit helpers remain FileDownloader-routed exact children: `0x0041b180` has caller `0x00451d18`, `0x0041b200` has caller `0x0041cd0f`, and `0x0041b270` has caller `0x0041c21b`. All three caller contexts pass the FileDownloader/download-dispatcher singleton [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `0x0067a738` as the receiver.
- Current MCP preserves the fitting-room state relationship: `DownloadCashShopVersion` writes JSON key `"version"` into `g_pFittingRoomDialog + 0x790` (`m_itemShopVersion`), while `DownloadCashShopCatalog` and the catalog submit helper use `g_pFittingRoomDialog + 0x7a8` (`m_activeCatalogRequest`).

The aggregate page changed to `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitter because it is a numeric range index spanning exact worker, dispatcher, minimap submit, catalog submit, version submit, padding, payload, and fitting-room state relationships. Keep aggregate C++ blank: generated `FileDownloader.cpp` already emits the source-shaped worker bodies through exact child pages, and [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) has no single source declaration or aggregate function body. Reintroducing aggregate C++ would duplicate [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md)/[UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md) output and collapse FileDownloader, CashShop request, FittingRoom, and MiniMap context into a synthetic source unit.

## Superseded History: B001 2026-06-18 Flattened Source Declarations

B001's FileDownloader helper pass resolved the primary helper/payload blockers enough for the first-draft worker bodies on [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md), [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md), and [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md). The preserved block below is dated inference evidence, not active reconstruction source: it predates the proven non-polymorphic `BaseRequest`, flattens both request classes, uses the superseded `state`/padding model, and mixes FileDownloader, request, minimap, and FittingRoom declarations that now belong to separate formal owners. Exact behavioral/layout facts remain useful, but no declaration in this historical block may be copied into generated source merely because it appears in a C++ fence.

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
    std::string m_itemShopVersion;            // recovered offset +0x790
    CashShopRequest *m_activeCatalogRequest;  // recovered offset +0x7a8
};

extern FittingRoomDialog *g_pFittingRoomDialog;
extern FileDownloader *g_pFileDownloader;
```

### Current Disposition Of The Preserved Draft

- The active header is assembled only from formal `RECONSTRUCTION_H CODE` channels in emitter order: [UID:00050F][BaseRequest](by-class/BaseRequest.md) opens `FileDownloader.h`; [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md) and [UID:00001H][CashShopRequest](by-class/CashShopRequest.md) declare the two BaseRequest-derived payloads; [UID:00004W][FileDownloader](by-class/FileDownloader.md) declares the Thread-derived dispatcher and closes the guard.
- The active source is [UID:0000JC][FileDownloader](by-file/FileDownloader.md). BaseRequest contributes the coordinated include, request-class CPP channels attach their exact constructor/destructor children, and exact FileDownloader constructor/destructor/dispatcher/submitter/worker definitions attach through this file root. The FileDownloader class CPP channel is intentionally blank because its exact methods already route through the file root; restoring class-level `[[CHILDREN]]` would recreate the invalid literal `[[No Children Attached]]` that was previously generated ahead of the real method bodies.
- Compiler-generated RTTI, vtables, exception-cleanup helpers, and scalar-deleting wrappers remain binary support evidence. Their formal by-memory dispositions are covered-by/no-code comments where accepted, never handwritten ABI bodies or copied `.rdata` tables.
- `FileDownloader *g_pFileDownloader` is the single source-facing singleton declaration. [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) and [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md) retain the historical binary/document alias and exact storage evidence without creating a second emitted global.
- `FileDownloaderMinimapRequest`, the three message IDs, the FittingRoom offsets, worker buffer/cleanup behavior, and rejected owner alternatives remain accepted research. Their presence in the superseded block does not transfer declaration ownership away from the current formal by-class/by-type/by-global or exact by-memory channels.

Accepted source-quality details:

- `DownloadMinimapFile` is the message `10000` FileDownloader worker. It consumes a raw `0x238` request block, uses `mapId`, `outputPath[0x104]`, and `mapCode[0x10]`, downloads S3 `.mnm` data, and deletes partial output on failed transfer. The generated `mapCode[32]` form is rejected because the submit helper copies with `_wcscpy_s(..., 0x10)`.
- `DownloadCashShopVersion` is the message `10002` worker. It consumes a `0x10` `CashShopVersionRequest`, tracks content length/progress, parses JsonCpp key `version`, writes `FittingRoomDialog::m_itemShopVersion` at `+0x790`, and leaves payload destruction to the dispatcher. B007's 2026-06-26 source-quality sync supersedes the earlier simplified formal body: current MCP shows `statusLength = 256`, `wchar_t statusText[128]`, `char chunkBuffer[100000]`, null-terminated/`strlen` response appends, terminal zero-byte read logging, `reader.parse(..., true)`, `root.get("version", Json::Value())`, and WinINet handle closes only after a non-null parsed `version` value.
- `DownloadCashShopCatalog` is the message `10001` worker. It consumes a `0x28` `CashShopRequest` catalog payload, appends downloaded `itemshop.json` bytes into the response string, sets `downloadComplete`, and self-deletes only when `g_pFittingRoomDialog->m_activeCatalogRequest` at `+0x7a8` does not still own the request.
- Raw PE/Capstone recheck found one direct dispatcher call to each worker and no pointer-table/immediate route to their starts. Feature pages provide request/state context; FileDownloader emits the worker bodies.

## 2026-07-01 B008 Empty-Emitter Family Implementation

B008's accepted FileDownloader empty-emitter family report resolves the current generated-output blockers without changing the source route. The pre-callback generated baseline was `auto-generated/NexusTK/network/FileDownloader.cpp`, validator command `000000003955`, refreshed `2026-07-01T15:56:42-04:00`, with `15` total emitters, `6` filled, `9` empty, and `40.0%` filled. That audit explains the score raise to `89/91`: the remaining empty markers were not caused by wrong file placement, but by blank formal C++ on the class/method pages and by two compiler-generated helper pages still marked as source emitters.

The source route split is:

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) remains the generated `NexusTK/network/FileDownloader.cpp` file route.
- [UID:00004W][FileDownloader](by-class/FileDownloader.md) is the direct semantic owner for class declaration and method bodies.
- [UID:0002TP][0x0041a670-0x0041a6e5.FileDownloaderConstructor](by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md), [UID:0002TQ][0x0041a6f0-0x0041a741.FileDownloaderDestructor](by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md), [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md), [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) are class-owned, file-emitted exact method children.
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) is constructor EH/unwind cleanup and no longer emits standalone source.
- [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) is compiler-generated scalar deleting destructor support and no longer emits standalone source.

Rejected direct owners remain rejected. FittingRoom is caller/state context for version/catalog request submission, not the FileDownloader method owner. `CashShopRequest` and `CashShopVersionRequest` own payload/vtable identity, not queue receiver methods. MiniMap owns feature context for map downloads, not the generic FileDownloader queue helper. The stale physical name `g_pCashShopRequest` remains a historical alias for `0x0067a738`; the source-facing role is `FileDownloader *g_pFileDownloader` or an equivalent downloader-dispatcher singleton.

No broad aggregate may duplicate these exact bodies. [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) and [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) remain non-emitting inventories because they cover mixed address neighborhoods rather than single source declarations.

## 2026-08-03 B008 Four-Class Source Inventory

The coordinated UID0003FS audit resolves the prior payload-header/file uncertainty without discarding the earlier dispatcher research. The active source order is exact:

1. [UID:00050F][BaseRequest](by-class/BaseRequest.md), emitter position `0`, opens `NEXUSTK_NETWORK_FILEDOWNLOADER_H`, includes `<string>` and `Thread.h`, defines the non-polymorphic three-field base, and contributes the only CPP include.
2. [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md), emitter position `1`, declares `CashShopVersionRequest : public BaseRequest`; exact method children remain in CPP through `[[CHILDREN]]`.
3. [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), emitter position `2`, declares `CashShopRequest : public BaseRequest` with only `responseText` as derived storage; its exact constructor/destructor support remains child-owned.
4. [UID:00004W][FileDownloader](by-class/FileDownloader.md), emitter position `3`, declares the Thread-derived dispatcher and closes the guard in formal H. Its formal CPP is intentionally blank; exact FileDownloader method bodies attach through the [UID:0000JC][FileDownloader](by-file/FileDownloader.md) file root rather than a class-level `[[CHILDREN]]` token.

The physical evidence matches that source shape: raw CashShopRequest lifecycle code at `0x0041a5d0-0x0041a662` directly precedes FileDownloader construction at `0x0041a670`; workers/dispatcher/submitters continue through `0x0041b2c9`; request/FileDownloader scalar-destructor wrappers cluster at `0x0041b570`, `0x0041b5e0`, and `0x0041b610`; and the three RTTI/vtable records are contiguous at `0x0060d794-0x0060d7e0`. BaseRequest BCD PMD `+4` appears in both request hierarchies, while exact object sizes distinguish the no-derived-field version payload from the string-bearing catalog payload.

The former [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) and [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) standalone paths now read `NONE` and remain historical alias documents. This prevents duplicate generated CPP files while preserving all investigation detail and rejected Socket/FittingRoom alternatives.

## Ownership Evidence Matrix

| Evidence | Meaning |
| --- | --- |
| `FileDownloader::OnMessage` at `0x0041b110-0x0041b180` | Dispatches downloader messages `10000`, `10001`, and `10002` to WinINet helper families. |
| `dword_67A738` / [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) | All direct writes are FileDownloader constructor/destructor-family writes; consumers pass the singleton into downloader request submit helpers. |
| [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md) | Message IDs are documented as worker-thread/download messages, not socket opcodes. |
| [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md) contrast | Confirms the generic FileDownloader path and minimap-specific downloader path are related but not interchangeable. |
| [UID:0001QH][client_network](by-meta/client_network.md) and proposed source tree | Both place FileDownloader with network/download infrastructure rather than encrypted game transport or pure cash-shop UI. |

## Evidence

- Live IDA decompilation of `0x0041a670-0x0041a6e5` constructs the base thread with argument `5`, writes `dword_67A738 = this`, installs the `FileDownloader` vtable, and calls the worker-start helper.
- Live IDA confirms `0x0041b110-0x0041b180` as a real function and decompiles it as a `switch` on message IDs `10000`, `10001`, and `10002`.
- Live IDA caller/callee checks for `0x0041b110` show calls to `0x0041a750`, `0x0041aa00`, and `0x0041ae20`, with those download helpers each called only from the dispatcher in the current database.
- The recovered helpers use WinINet, HTTP status checks, timeout options, and caller-supplied progress/output fields.
- `Application` startup allocates a `FileDownloader` instance size `0x68` and constructs it during subsystem initialization.
- Live IDA xrefs on 2026-06-04 found 9 xrefs and 5 direct writes to `dword_67A738`; all writes are FileDownloader constructor/destructor-family writes, including the constructor-unwind clear helper [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md).
- Live IDA decompilation and call-site windows show fitting-room/minimap callers passing `dword_67A738` into request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270`, which enqueue downloader messages `10000`, `10001`, and `10002`.
- Live IDA byte checks confirm the nested function split and `0xcc` padding boundaries across `0x0041a670-0x0041b69f`, including non-padding real code at `0x0041b2d0`.
- 2026-06-23 B004 MCP-backed recheck used session `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, executable SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. It reconfirmed [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) as a non-emitting exact-child inventory: `sub_41AA00` size `0x41c`, `sub_41AE20` size `0x2ec`, `sub_41B110` size `0x70`, `sub_41B180` size `0x75`, `sub_41B200` size `0x6d`, `sub_41B270` size `0x59`, no functions at padding fences `0x0041b1f5`, `0x0041b26d`, and `0x0041b2c9`, and successor `0x0041b2d0` outside the subset range. The current route evidence is FileDownloader-specific for the exact children, but it rejects [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) itself as the canonical FileDownloader owner/emitter because the page is an aggregate index with no single source unit.
- 2026-06-26 B007 [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) support sync used the same live MCP session `80de0a67`, with `server_health` still `status:"ok"`, to refine the `DownloadCashShopVersion` worker body without changing this file page's metadata. The exact FileDownloader route remains message `10002` from `FileDownloader::OnMessage` at `0x0041b13c`; route scans preserve no hidden VA/RVA/pointer-table path to `0x0041aa00`. The accepted source body now records the 256-byte status query, 128-wide-character status buffer, 100000-byte chunk buffer, `strlen` append semantics, terminal zero-byte logging, JsonCpp `collectComments = true`, `root.get("version", Json::Value())`, and target-specific cleanup path. The old B001 high-level ownership/route conclusion remains valid, but its `0x4000` buffer, binary append, status-return guard, and common cleanup shape are superseded.
- 2026-06-07 Batch 097 live IDA recheck against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the `0x0041b110-0x0041b180` dispatcher switch, adjacent submit-helper ranges `0x0041b180-0x0041b1f5`, `0x0041b200-0x0041b26d`, and `0x0041b270-0x0041b2c9`, message IDs `10000-10002`, the `0x0041a750` / `0x0041ae20` / `0x0041aa00` download-helper targets, and inherited worker-thread fallback behavior. This is sufficient to make [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md) a direct child of this file page under the strict 85/85 assignment gate.
- 2026-06-12 A003 Batch255 live IDA MCP dword/xref scan confirms exact [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md): `0x0060d7a4 -> ??_R4FileDownloader@@6B@`, `0x0060d7a8 -> sub_41B610`, inherited worker/thread slots through `0x0060d7dc`, `0x0060d7d4 -> sub_41B110`, three refs to the vtable slot, and the `0x0060d7e0` `szAgent` boundary.
- 2026-06-12 A003 Batch261 live IDA MCP literal/xref scan confirms the item-shop URL literals as FileDownloader children: `0x0060d8b8` `itemshop.ver` is referenced from `0x0041aa64` in `DownloadCashShopVersion_41AA00`, `0x0060d91c` progress text is referenced from `0x0041aca3` and `0x0041b086` in the version/catalog helpers, and `0x0060d958` `itemshop.json` is referenced from `0x0041ae84` in `DownloadCashShopCatalog_41AE20`. The adjacent shared `version` key is not assigned here because it also has FittingRoom and StartupWindow parsing refs.

## Boundary Cautions

- `FileDownloader::StartThread` at `0x005965e0` is currently owned by `FileDownloader`, but IDA callers include `FileDownloader`, `MiniMapDownloader`, browser control construction, application initialization, and `MiscWorkThread`. The body is a generic thread launch wrapper: call virtual slot 5, then `ResumeThread(this[23])`. This may ultimately belong to `Thread` or a shared worker-thread helper.
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) is a reliable alias for `dword_67A738` only when live evidence points at that address. Earlier recovered aliases also reuse the same name for packet-send paths that IDA proves read [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`; normalize those paths before changing ownership.
- The request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` are FileDownloader receiver methods in the coordinated module. Their consumers pass the FileDownloader-lifetime singleton; payload classes provide types and state only, and historical standalone CashShop pages must not absorb or duplicate these bodies.
- The minimap has two similar WinINet helpers: `DownloadMinimapFile_41A750` through `FileDownloader::OnMessage`, and `DownloadMinimap_453AA0` through `MiniMapDownloader::OnThreadTask`. Treat them as related but not interchangeable until task structure layout is reconciled.

## Proposed Placement

```text
network/
  FileDownloader.h    // BaseRequest, CashShopVersionRequest, CashShopRequest, FileDownloader
  FileDownloader.cpp  // include, exact child-owned constructors/destructors/workers/dispatcher/submitters
```

The earlier possibility of feature-specific cash-shop payload headers is preserved as historical uncertainty, but the active reconstruction uses the coordinated header above because the shared BaseRequest hierarchy and physical clustering are stronger than feature-name grouping. The dispatcher remains outside [UID:0000NS][Socket](by-file/Socket.md), because it is HTTP/WinINet download work, not encrypted game transport.

## Score Rationale

- Completion is `94` because the projected reconstruction path, exact four-class CPP/H order, BaseRequest hierarchy, ownership evidence, child split, message dispatch map, singleton lifetime, attached submit-helper pages, exact vtable data, direct [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md) routing, network/source-tree placement, historical alias disposition, and prior empty-emitter repairs are all recorded.
- Confidence is `94` because live dispatcher/caller/callee evidence, `dword_67A738` xrefs, submit-helper callsites, byte-padding checks, code/vtable/scalar-destructor adjacency, BaseRequest PMDs, object sizes, item-shop literals, and the class/method/no-code split consistently place this source family in `NexusTK/network/FileDownloader.h/.cpp`.
- The page remains below `95/95` because `StartThread`, `StopThread`, `DispatchRequest`, `Thread::OnMessage`, exact global spelling, and historical header style are inferred rather than recovered from source/PDB data.

## Cross-References

- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:00050F][BaseRequest](by-class/BaseRequest.md)
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md)
- [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md)
- [UID:0003G0][0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md)
- [UID:0003G2][0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md)
- [UID:0003AL][0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals](by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md)
- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-06 B008 UID0003FS C050 implementation callback:
  - Preserved the complete B001 declaration sketch and all behavioral/layout evidence, but reclassified the sketch as explicit superseded history rather than active source.
  - Added the exact active formal-H ownership order, BaseRequest/request inheritance disposition, intentionally blank FileDownloader class CPP rationale, file-root method attachment, compiler-generated no-body policy, and single `g_pFileDownloader` global route.
  - Corrected the active four-class inventory so FileDownloader no longer claims class-level `[[CHILDREN]]`; this is a documentation/source-route correction only and does not change `94/94`, `NexusTK/network/`, or any formal by-file code channel.

- 2026-08-03 B008 UID0003FS coordinated module implementation:
  - Changed `89/91` to `94/94` while retaining `NexusTK/network/` and canonical file ownership.
  - Added the exact four-class emitter order, BaseRequest/source layouts, header/source responsibilities, physical clustering, and the no-duplicate disposition for historical CashShopRequest and CashShopVersionRequest file aliases.
  - Preserved all prior worker, message, singleton, aggregate, literal, and empty-emitter research; only superseded provisional ownership/file-split statements were historicalized or resolved.

- 2026-06-07 A004 Batch 097 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA rechecked the FileDownloader dispatcher, submit-helper ranges, queued message IDs, target helper calls, and base-thread fallback. This raises the parent just enough for the strict direct-parent gate used by [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md); completion remains capped above 85 because `StartThread`, source-facing singleton type/name, and payload/request declarations are still provisional.
- 2026-06-02 documentation pass:
  - What existed before: the page documented the dispatcher but still had a blank projected reconstruction path and no explicit score rationale.
  - What it was changed to: raised `65/80` to `72/84`, set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/`, and added ownership evidence and score rationale.
  - Summary/evidence: IDA-backed `OnMessage` dispatch, downloader message constants, `dword_67A738` FileDownloader lifetime writes, and proposed-source-tree network placement support this module assignment while helper ownership caveats remain open.
- Before: likely contents named the scalar deleting destructor and request submission helpers only as class/address concepts.
- After: likely contents and cross-references link exact `by-memory` pages for the submit helpers and FileDownloader scalar deleting destructor.
- Summary/evidence: IDA MCP and xref checks tied the helpers to the downloader queue and `dword_67A738`; destructor decompilation confirms the global clear and thread cleanup sequence.
- 2026-06-04 live IDA evidence pass:
  - What existed before: `COMPLETION:72`, `CONFIDENCE:84`, stale non-IDA provenance, and submit-helper ownership remained recorded as a caveat instead of an autogen attachment decision.
  - What it was changed to: raised to `COMPLETION:84`, `CONFIDENCE:88`, replaced stale provenance with live IDA evidence, and documented the high-confidence FileDownloader attachment for the submit helpers.
  - Summary/evidence: live IDA decompilation confirms constructor/destructor/global writes, the `OnMessage` switch, `sub_596960` queue posting, callers at `0x451d18`, `0x41cd0f`, and `0x41c21b` using `dword_67A738`, exact function boundaries, and nested `0xcc` padding. C++ remains blank because `StartThread`, final source names, and payload ownership stay below the 95/95 gate.
- 2026-06-12 A003 Batch255 vtable split:
  - Score remains `85/88`; exact [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md) was added as class/file evidence.
  - Summary/evidence: live IDA MCP confirmed the FileDownloader RTTI pointer, destructor slot, inherited worker/thread slots, `OnMessage` override slot, three vtable refs from constructor/destructor wrappers, and the `szAgent` boundary. The class page is raised to `85/89`, clearing the direct parent gate for the vtable child.
- 2026-06-12 A003 Batch261 literal split:
  - Score remains `85/88`; exact item-shop literal children [UID:0003G0][0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) and [UID:0003G2][0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md) were added as FileDownloader evidence and direct children. Shared literal siblings from the same mixed block remain unassigned.
  - Summary/evidence: live IDA MCP xrefs place `itemshop.ver`, the item-shop progress format, and `itemshop.json` in the `DownloadCashShopVersion` / `DownloadCashShopCatalog` helper paths dispatched by `FileDownloader::OnMessage`, while the `version` key and minimap/user-agent literals have multi-owner refs.
- 2026-06-18 B001 FileDownloader download-helper source-quality pass:
  - Changed from `85/88` to `87/90`.
  - Summary/evidence: incorporated B001's report-level details for the primary worker helpers [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md)/[UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md)/[UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md), the `FileDownloaderMessageId` first-draft enum, request layouts, `g_pFileDownloader` source-facing singleton name, fitting-room item-shop fields, direct dispatcher route/no-pointer-table evidence, and rejected MiniMap/FittingRoom/CashShopVersionRequest emitter alternatives. `StartThread` and exact original declaration spelling remain final-source caveats.
- 2026-06-23 B004 [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) source-quality reclassification:
  - Score remains `87/90` for this file page; [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) changed from an emitting FileDownloader aggregate to a `88/90` non-emitting exact-child inventory.
  - Summary/evidence: current MCP session `80de0a67` and PE route scan keep FileDownloader as the source route for exact worker/dispatcher/submit children while rejecting aggregate FileDownloader ownership for [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md). Exact children keep their own source ownership/emission decisions; aggregate C++ remains blank with a no-single-source-unit/no-duplicate-output proof.
- 2026-06-26 B007 [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) implementation sync:
  - Score remains `87/90` for this file page; the target [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) changes to `91/93` under the existing FileDownloader owner/emitter route.
  - Summary/evidence: incorporated the refined worker-body facts for `DownloadCashShopVersion`, preserving message `10002`, one dispatcher xref at `0x0041b13c`, no alternate route scans, payload destruction in the dispatcher, submit-helper initialization/posting at `0x0041b270`, fitting-room write to `m_itemShopVersion +0x790`, and rejected stale B001 body alternatives. No file-level source placement or singleton naming change is made.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `87/90` to `89/91`.
  - Summary/evidence: incorporated the accepted B008 report for generated baseline command `000000003955` refreshed `2026-07-01T15:56:42-04:00` with `15/6/9/40.0%`. At that historical revision [UID:00004W][FileDownloader](by-class/FileDownloader.md) emitted the class declaration while six exact method children emitted source bodies through this file route; the later coordinated-H migration moved the declaration into formal H and intentionally blanked the class CPP without changing the file-root method route. [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) and [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) are no-code compiler/EH support, and broad aggregate inventories remain non-emitting to avoid duplicate FileDownloader bodies.
