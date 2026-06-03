*** UID:0000I1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CashShopVersionRequest

## Status

- Confidence: strong for request behavior, medium for final file placement.
- Proposed module: `cashshop/CashShopVersionRequest.cpp`, with shared dispatch in [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
- Current Wave3 file: `class_CashShopVersionRequest.cpp`
- Main class: [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- Related globals: `DownloadCashShopVersion_41AA00`, `DownloadCashShopCatalog_41AE20`
- Evidence basis: Wave3 class/global summaries, generated `simroot_v2` source, and IDA MCP function/xref checks through 2026-05-25.

## Hypothesis

`CashShopVersionRequest` is a tiny request-payload class for the fitting-room item-shop version check. The actual HTTP work is done by free WinINet helper functions dispatched through [UID:0000JC][FileDownloader](by-file/FileDownloader.md), so the original source was probably split between a small cash-shop request companion and a shared download dispatcher. The submission helper at `0x0041b270` is still a file-boundary question because live callers pass [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, whose lifetime is FileDownloader-owned.

## Contents

Likely source-level contents:

- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), provisionally named here but linked to the FileDownloader singleton.
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md).
- `DownloadCashShopVersion_41AA00`, which downloads the item-shop version document and updates the active fitting-room version text.
- `DownloadCashShopCatalog_41AE20`, which downloads `https://secure.kru.com/itemshop/data/itemshop.json` into a request buffer.
- `FileDownloader::OnMessage` at `0x0041b110`, which dispatches message IDs `10001` and `10002` to the catalog and version helpers.

`DownloadCashShopCatalog_41AE20` is more fitting-room catalog behavior than a pure version-request method. Keep it cross-referenced from [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

## Evidence

- Wave3 reports `CashShopVersionRequest` with two methods and owner file `class_CashShopVersionRequest.cpp`.
- IDA MCP confirms `0x0041b270-0x0041b2c9` and `0x0041b5e0-0x0041b603` as real functions.
- IDA MCP reports `0x0041b270` is called by `0x0041bdd0`, the fitting-room dialog constructor.
- IDA MCP decompilation on 2026-05-25 shows the caller passes `dword_67A738` into `0x0041b270`, and the `0x0067a738` xref sweep found FileDownloader constructor/destructor-family lifetime writes.
- Wave3 global summaries identify `DownloadCashShopVersion_41AA00` at `0x0041aa00` and `DownloadCashShopCatalog_41AE20` at `0x0041ae20`.
- IDA MCP confirms `0x0041aa00-0x0041ae1b` and `0x0041ae20-0x0041b10b`; both are called by `0x0041b110`.
- IDA MCP decompilation confirms `0x0041b110` is the `FileDownloader::OnMessage` switch for downloader messages `10000`, `10001`, and `10002`.
- Generated source shows both download helpers using WinINet and item-shop/fitting-room request payload structures.

## Proposed Placement

```text
cashshop/
  CashShopVersionRequest.h
  CashShopVersionRequest.cpp
network/
  FileDownloader.cpp
```

Alternate if grouping by feature source rather than request type:

```text
cashshop/
  FittingRoom.cpp
```

## Open Questions

- Whether `DownloadCashShopVersion_41AA00` and `DownloadCashShopCatalog_41AE20` were original static functions in a fitting-room source file.
- Whether `0x0041b270` belongs with this payload class, [UID:0000JC][FileDownloader](by-file/FileDownloader.md), or a later download-request dispatcher split.
- Whether the version and catalog request payload classes share a base with `CashShopRequest` payloads.

## Cross-References

- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Before: this file described the version request methods by address only.
- After: it links to exact `by-memory` method pages for the version-submit helper and scalar deleting destructor.
- Summary/evidence: IDA MCP confirmed both function boundaries; ownership of the submit helper stays provisional because the call path uses FileDownloader-lifetime `dword_67A738`.
