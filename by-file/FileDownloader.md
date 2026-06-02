*** UID:0000JC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FileDownloader

## Status

- Confidence: strong for dispatcher behavior, medium for final original file name.
- Proposed module: `network/FileDownloader.cpp`
- Projected reconstruction path: `NexusTK/network/`
- Current Wave3 file: `class_FileDownloader.cpp`
- Main class: [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- Related constants: [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md)
- Evidence basis: `simroot_v2`, prior Wave2 report notes, and live IDA MCP lookup/caller/callee/decompile/xref checks through 2026-05-25.

## Hypothesis

`FileDownloader` is a shared thread-backed HTTP download dispatcher. It should be documented as network/download infrastructure, not as part of the game socket protocol and not as a cash-shop-only class.

The original source likely grouped the `FileDownloader` class with file-local WinINet worker helpers. The strongest split is:

```text
network/FileDownloader.cpp
```

An alternate old-project layout could have used `util/FileDownloader.cpp` if the team grouped all thread helpers together, but the WinINet URLs and message dispatch behavior make `network/` the better current reconstruction target.

## Likely Contents

- [UID:00004W][FileDownloader](by-class/FileDownloader.md), including constructor/destructor, `OnMessage`, [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md), and the currently named `StartThread` helper.
- `DownloadMinimapFile_41A750`, the message `10000` single-file minimap download helper.
- `DownloadCashShopCatalog_41AE20`, the message `10001` item-shop catalog download helper.
- `DownloadCashShopVersion_41AA00`, the message `10002` item-shop version download helper.
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, the FileDownloader-lifetime download-request singleton with final source-facing type/name still unresolved.
- Request submission helpers [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), if later ownership cleanup keeps them with the downloader dispatcher rather than a cash-shop payload class.

`MiniMapDownloader` is related but should stay in [UID:0000LE][MiniMap](by-file/MiniMap.md) or `map/MiniMapDownloader.cpp`, because it has its own singleton, virtual task handler, and minimap-specific task structure.

## Dispatch Map

| Message ID | Current target | Request lifetime behavior | Likely feature owner |
| --- | --- | --- | --- |
| `10000` | `DownloadMinimapFile_41A750` | Calls helper, then frees the raw task block. | Shared downloader/minimap update path. |
| `10001` | `DownloadCashShopCatalog_41AE20` | Calls helper; helper may destroy request if the fitting-room dialog no longer owns it. | Cash-shop fitting-room catalog. |
| `10002` | `DownloadCashShopVersion_41AA00` | Calls helper, then destroys request through its vtable. | Cash-shop fitting-room version check. |

The message IDs are currently documented at [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md). Do not reuse them as socket opcodes.

## Ownership Evidence Matrix

| Evidence | Meaning |
| --- | --- |
| `FileDownloader::OnMessage` at `0x0041b110-0x0041b180` | Dispatches downloader messages `10000`, `10001`, and `10002` to WinINet helper families. |
| `dword_67A738` / [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) | All direct writes are FileDownloader constructor/destructor-family writes; consumers pass the singleton into downloader request submit helpers. |
| [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md) | Message IDs are documented as worker-thread/download messages, not socket opcodes. |
| [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md) contrast | Confirms the generic FileDownloader path and minimap-specific downloader path are related but not interchangeable. |
| [UID:0001QH][client_network](by-meta/client_network.md) and proposed source tree | Both place FileDownloader with network/download infrastructure rather than encrypted game transport or pure cash-shop UI. |

## Evidence

- Generated `class_FileDownloader.cpp` constructs a `Thread(5)`, assigns `g_pCashShopRequest = this`, installs the `FileDownloader` vtable, and starts the worker.
- IDA MCP confirms `0x0041b110-0x0041b180` as a real function and decompiles it as a `switch` on message IDs `10000`, `10001`, and `10002`.
- IDA MCP `callees` for `0x0041b110` include `0x0041a750`, `0x0041aa00`, and `0x0041ae20`.
- IDA MCP `callers` confirms `DownloadMinimapFile_41A750`, `DownloadCashShopVersion_41AA00`, and `DownloadCashShopCatalog_41AE20` are each called only from `0x0041b110` in the current database.
- The recovered helpers use WinINet, HTTP status checks, timeout options, and caller-supplied progress/output fields.
- `Application` startup allocates a `FileDownloader` instance size `0x68` and constructs it during subsystem initialization.
- IDA MCP `py_eval` on 2026-05-25 found 9 xrefs and 5 direct writes to `dword_67A738`; all writes are FileDownloader constructor/destructor-family writes, including the constructor-unwind clear helper [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md).
- Live IDA decompilation shows fitting-room download/version request callers passing `dword_67A738` into the request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270`, which enqueue downloader messages `10000`, `10001`, and `10002`.

## Boundary Cautions

- `FileDownloader::StartThread` at `0x005965e0` is currently owned by `FileDownloader`, but IDA callers include `FileDownloader`, `MiniMapDownloader`, browser control construction, application initialization, and `MiscWorkThread`. The body is a generic thread launch wrapper: call virtual slot 5, then `ResumeThread(this[23])`. This may ultimately belong to `Thread` or a shared worker-thread helper.
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) is a reliable alias for `dword_67A738` only when live evidence points at that address. Generated simroot files also reuse the same name for packet-send paths that IDA proves read [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`; normalize those paths before changing ownership.
- The request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` are adjacent to the small cash-shop payload constructor/destructor and still have provisional class ownership. Their consumers pass the FileDownloader-lifetime singleton, so do not migrate them blindly under `CashShopRequest.cpp`.
- The minimap has two similar WinINet helpers: `DownloadMinimapFile_41A750` through `FileDownloader::OnMessage`, and `DownloadMinimap_453AA0` through `MiniMapDownloader::OnThreadTask`. Treat them as related but not interchangeable until task structure layout is reconciled.

## Proposed Placement

```text
network/
  FileDownloader.h
  FileDownloader.cpp
```

Feature-specific payload/request definitions may stay in cash-shop or map headers if later source reconstruction needs narrower type ownership. The dispatcher itself should remain outside [UID:0000NS][Socket](by-file/Socket.md), because it is HTTP/WinINet download work, not encrypted game transport.

## Score Rationale

- Completion is raised because the projected reconstruction path, ownership evidence, message dispatch map, singleton lifetime, submit-helper caveats, and network/source-tree placement are now all recorded on the file page.
- Confidence is raised because the IDA-backed dispatcher, callee, caller, and global-lifetime evidence consistently place the dispatcher in downloader/network infrastructure.
- Confidence remains below final-source level because `StartThread` may belong to `Thread`, and the request submission helpers still straddle FileDownloader versus cash-shop payload ownership.

## Cross-References

- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md)
- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-02 documentation pass:
  - What existed before: the page documented the dispatcher but still had a blank projected reconstruction path and no explicit score rationale.
  - What it was changed to: raised `65/80` to `72/84`, set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/`, and added ownership evidence and score rationale.
  - Summary/evidence: IDA-backed `OnMessage` dispatch, downloader message constants, `dword_67A738` FileDownloader lifetime writes, and proposed-source-tree network placement support this module assignment while helper ownership caveats remain open.
- Before: likely contents named the scalar deleting destructor and request submission helpers only as class/address concepts.
- After: likely contents and cross-references link exact `by-memory` pages for the submit helpers and FileDownloader scalar deleting destructor.
- Summary/evidence: IDA MCP and xref checks tied the helpers to the downloader queue and `dword_67A738`; destructor decompilation confirms the global clear and thread cleanup sequence.
