*** UID:00004W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:65 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FileDownloader

## Status

- Confidence: strong for methods and message dispatch, medium for inherited `StartThread` ownership.
- Current Wave3 file: `class_FileDownloader.cpp`
- Proposed source module: [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- Evidence basis: `simroot_v2`, prior Wave2 report notes, and live IDA MCP checks through 2026-05-25.

## Role

Thread-backed WinINet download dispatcher for small file/update requests. It is separate from [UID:0000NS][Socket](by-file/Socket.md), which owns the encrypted game transport.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0041a670-0x0041a6e5` | `FileDownloader::FileDownloader` | Constructs `Thread(5)`, writes `dword_67A738 = this` / `g_pCashShopRequest`, installs vtable, starts worker. |
| `0x0041a6f0-0x0041a741` | `FileDownloader::~FileDownloader` | Stops thread, clears `dword_67A738`, destroys base thread. |
| [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) | `ClearFileDownloaderRequestGlobal` | Constructor EH/unwind helper that clears `dword_67A738`; reached from the unwind block at `0x005f670e`. |
| `0x0041b110-0x0041b180` | `FileDownloader::OnMessage` | Dispatches message IDs `10000`, `10001`, and `10002`; otherwise forwards to `Thread::OnMessage`. |
| [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) | `SubmitMinimapRequest` / provisional submit helper | Allocates a request payload and posts downloader message `10000`. |
| [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) | `SubmitCashShopCatalogRequest` / provisional submit helper | Allocates a catalog request payload and posts downloader message `10001`. |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | `SubmitCashShopVersionRequest` / provisional submit helper | Allocates a version request payload and posts downloader message `10002`. |
| [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) | `FileDownloader::ScalarDeletingDestructor` | Destructor wrapper that clears `dword_67A738`, destroys the base thread, and optionally calls `operator delete`. |
| `0x005965e0-0x005965f3` | `FileDownloader::StartThread` | Calls virtual slot 5, then `ResumeThread`; ownership may later move to `Thread`. |

## Message Dispatch

`FileDownloader::OnMessage` currently maps:

- `10000`: `DownloadMinimapFile_41A750(messageData)`, then raw delete.
- `10001`: `DownloadCashShopCatalog_41AE20(messageData)`.
- `10002`: `DownloadCashShopVersion_41AA00(messageData)`, then virtual destroy with flag `1`.

See [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md).

## IDA MCP Evidence

- `lookup_funcs` confirms `0x0041b110` size `0x70` and `0x005965e0` size `0x13`.
- `callees` for `0x0041b110` list the three download helpers: `0x0041a750`, `0x0041aa00`, and `0x0041ae20`.
- `callers` for `0x005965e0` include `0x0041a670`, `0x00453910`, `0x0046ff50`, `0x004f5fb0`, and `0x005281b0`, so the current `FileDownloader` owner is broader than the function body itself proves.
- `py_eval` xrefs for `0x0067a738` found 9 refs and 5 direct writes. The writes are `FileDownloader::FileDownloader`, `FileDownloader::~FileDownloader`, [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md), and the scalar deleting destructor.
- Decompilation of fitting-room callers shows `dword_67A738` passed into request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270`, which enqueue downloader messages `10000`, `10001`, and `10002`.

## Boundary Cautions

- The class writes to [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`. The address and FileDownloader lifetime are now reliable, but the final C++ type/name remains open.
- Some generated files use `g_pCashShopRequest` for packet-send paths that IDA proves read [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`. Do not conflate those globals during source ownership cleanup.
- The `0x0041b180`, `0x0041b200`, and `0x0041b270` request submission helpers may belong with this dispatcher or with cash-shop request payload support; keep their final owner provisional.
- `StartThread` should not be used as proof that browser or misc worker thread construction belongs in `FileDownloader.cpp`; it is a shared worker launch helper in the current model.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- Before: several FileDownloader-adjacent helpers were listed by address only or only through the aggregate dispatch page.
- After: the class method inventory links exact pages for the constructor-unwind global clear helper, submit helpers, and scalar deleting destructor.
- Summary/evidence: IDA MCP confirmed the destructor boundary on 2026-05-30 and previous decompilation/xref evidence tied the submit helpers and `dword_67A738` lifetime to the FileDownloader dispatch path.
