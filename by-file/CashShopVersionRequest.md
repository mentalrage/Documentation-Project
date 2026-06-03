*** UID:0000I1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/cashshop/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CashShopVersionRequest

## Status

- Confidence: strong for request behavior, medium for final file placement.
- Proposed module: `NexusTK/cashshop/CashShopVersionRequest.cpp`, with shared dispatch in [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
- Projected path status: valid current reconstruction target.
- Main class: [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- Related globals: `DownloadCashShopVersion_41AA00`, `DownloadCashShopCatalog_41AE20`
- Evidence basis: live IDA MCP function/decompile/xref checks on 2026-06-03, plus existing IDA-backed child pages.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 78 | The file page now has a valid projected reconstruction path, a reconstructable main class parent, exact vtable/destructor evidence, and clear FileDownloader/FittingRoom boundaries. It is not higher because the submit helper and download worker helpers still straddle payload, dispatcher, and fitting-room source ownership. |
| Confidence | 86 | `NexusTK/cashshop/` is supported by the sibling [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) path, [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and fresh IDA evidence that the payload exists as a cash-shop version request type. Confidence remains below final-source level because HTTP dispatch is FileDownloader-owned and the original source split could have placed this tiny class in a fitting-room companion file. |

## Hypothesis

`CashShopVersionRequest` is a tiny request-payload class for the fitting-room item-shop version check. The class itself is best kept under `NexusTK/cashshop/` beside [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) and [UID:0000JE][FittingRoom](by-file/FittingRoom.md), while the HTTP worker and message switch remain in [UID:0000JC][FileDownloader](by-file/FileDownloader.md).

The submission helper at `0x0041b270` is still a file-boundary question because live callers pass [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, whose lifetime is FileDownloader-owned. Treat it as cross-linked dispatcher/payload evidence rather than proof that the whole helper body belongs in this file.

## Contents

Likely source-level contents:

- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md), anchored by RTTI/vtable data at `0x0060d794/0x0060d798`.
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md), the scalar deleting destructor wrapper.
- Header/source declarations for the request payload fields initialized by [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md): vtable pointer, byte field at `+4`, and dwords at `+8/+0xc`.

Cross-linked but not yet file-owned:

- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), which allocates this payload but is called on the FileDownloader singleton.
- [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md), which downloads the item-shop version document and updates fitting-room version state.
- [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md), which downloads `itemshop.json` into a request buffer.
- [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md), which dispatches message IDs `10001` and `10002` to the catalog and version helpers.

`DownloadCashShopCatalog_41AE20` is more fitting-room catalog behavior than a pure version-request method. Keep it cross-referenced from [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

## Evidence

- IDA MCP `lookup_funcs` on 2026-06-03 confirms `0x0041b270-0x0041b2c9`, `0x0041b5e0-0x0041b604`, `0x0041aa00-0x0041ae1c`, `0x0041ae20-0x0041b10c`, `0x0041b110-0x0041b180`, and the fitting-room constructor `0x0041bdd0-0x0041c250`.
- IDA MCP decompilation of `0x0041b270` allocates `0x10` bytes, writes `CashShopVersionRequest::vftable`, zeroes the payload fields, and dispatches downloader message `10002`.
- IDA MCP decompilation of `0x0041b5e0` restores `CashShopVersionRequest::vftable` and conditionally deletes the object.
- IDA MCP xrefs show the `0x0060d798` vtable slot is referenced only by the payload constructor helper and the scalar deleting destructor; the dword at `0x0060d798` points to `0x0041b5e0`, and `0x0060d794` points to `??_R4CashShopVersionRequest@@6B@`.
- IDA MCP xrefs show `0x0041b270` is called only from `0x0041c21b` inside the fitting-room dialog constructor, immediately after loading `dword_67A738`.
- IDA MCP xrefs to `0x0067a738` show FileDownloader-family direct writes at `0x0041a6b1`, `0x0041a6b8`, `0x0041a722`, `0x0041b2f0`, and `0x0041b649`; fitting-room code reads the singleton and calls downloader submit helpers.
- IDA MCP decompilation of `0x0041b110` confirms message `10002` calls `0x0041aa00` and then destroys the payload through its vtable; message `10001` calls `0x0041ae20`.

## Proposed Placement

```text
NexusTK/cashshop/
  CashShopVersionRequest.h
  CashShopVersionRequest.cpp
NexusTK/network/
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
- After: the projected path is set to `NexusTK/cashshop/`, the page documents class-owned versus cross-linked downloader contents, and the completion/confidence scores are raised with a live IDA evidence rationale.
- Summary/evidence: 2026-06-03 IDA MCP confirms the request payload vtable/destructor, fitting-room submit call, downloader message `10002`, and FileDownloader-owned singleton writes. The submit helper remains provisional because the call path uses FileDownloader-lifetime `dword_67A738`.
