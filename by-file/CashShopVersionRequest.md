*** UID:0000I1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CashShopVersionRequest

## Status

- Confidence: strong for request behavior, exact BaseRequest-derived layout, and coordinated FileDownloader placement.
- Current status: historical alias page with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`; active source is emitted through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
- Historical proposed module: `NexusTK/cashshop/CashShopVersionRequest.cpp`; this former split is preserved below with its evidence and correction reason.
- Main class: [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- Related globals: `DownloadCashShopVersion_41AA00`, `DownloadCashShopCatalog_41AE20`
- Evidence basis: live IDA MCP function/decompile/xref checks on 2026-06-03, plus existing IDA-backed child pages.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 92 | The page preserves the complete standalone-file hypothesis, exact vtable/destructor evidence, inherited `0x10` payload layout, FileDownloader/FittingRoom boundaries, and final no-duplicate alias disposition. |
| Confidence | 94 | RTTI proves shared BaseRequest at PMD `+4`; allocation, zeroing, submit/destructor routes, and adjacent code/vtable clusters support [UID:0000JC][FileDownloader](by-file/FileDownloader.md) as the strongest reconstruction module. Exact original file spelling remains inferred. |

## Hypothesis

`CashShopVersionRequest` is a tiny request-payload class for the fitting-room item-shop version check. Historical hypothesis placed it under `NexusTK/cashshop/` beside [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) and [UID:0000JE][FittingRoom](by-file/FittingRoom.md). The coordinated 2026-08-03 audit supersedes that split: the BaseRequest-derived declaration, HTTP workers, submit helper, and message switch now share [UID:0000JC][FileDownloader](by-file/FileDownloader.md), while this page remains a detailed alias.

The submission helper at `0x0041b270` is resolved as a FileDownloader method because live callers pass [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, whose lifetime is FileDownloader-owned. It remains payload evidence for this class but does not make this alias an emitting source file.

## Contents

Likely source-level contents:

- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md), anchored by RTTI/vtable data at `0x0060d794/0x0060d798`.
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md), the scalar deleting destructor wrapper.
- Header declaration evidence for the [UID:00050F][BaseRequest](by-class/BaseRequest.md)-derived payload initialized by [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md): derived vptr at `+0x00`, inherited `downloadComplete` at `+0x04`, `contentLength` at `+0x08`, and `bytesDownloaded` at `+0x0c`, with no derived fields.
- Exact vtable/source-declaration data from [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md), where the first project-owned vtable record contains the `CashShopVersionRequest` RTTI pointer and slot at `0x0060d798`.

Cross-linked but not yet file-owned:

- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), which allocates this payload but is called on the FileDownloader singleton.
- [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md), which downloads the item-shop version document and updates fitting-room version state.
- [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md), which downloads `itemshop.json` into a request buffer.
- [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md), which dispatches message IDs `10001` and `10002` to the catalog and version helpers.

`DownloadCashShopCatalog_41AE20` is more fitting-room catalog behavior than a pure version-request method. Keep it cross-referenced from [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

## Ownership Boundary

| Item | File handling | Rationale |
| --- | --- | --- |
| `CashShopVersionRequest` class declaration | Historical alias here; active owner [UID:0000JC][FileDownloader](by-file/FileDownloader.md) | The class page is attached to FileDownloader at position `1`; this page preserves why the `0x10` payload was formerly considered standalone. |
| `0x0041b5e0-0x0041b604` scalar deleting destructor | Active class route through FileDownloader | The single vtable slot at `0x0060d798` points here, and the compiler wrapper is regenerated from the class declaration/destructor route. |
| `0x0041b270-0x0041b2c9` submit helper | FileDownloader-owned | It allocates this payload, receives the FileDownloader singleton, and posts downloader message `10002`. |
| `0x0041aa00` / `0x0041ae20` download workers | Cross-linked to FileDownloader/FittingRoom | These helpers consume downloader messages and update fitting-room/catalog state; they are not pure payload-class behavior. |
| `0x0060d798` vtable data | Source-declared/generated-binary | Required by this class declaration, but the exact binary bytes should be compiler-emitted with the neighboring cash-shop/fitting-room vtable data. |

## Evidence

- IDA MCP `lookup_funcs` on 2026-06-03 confirms `0x0041b270-0x0041b2c9`, `0x0041b5e0-0x0041b604`, `0x0041aa00-0x0041ae1c`, `0x0041ae20-0x0041b10c`, `0x0041b110-0x0041b180`, and the fitting-room constructor `0x0041bdd0-0x0041c250`.
- IDA MCP decompilation of `0x0041b270` allocates `0x10` bytes, writes `CashShopVersionRequest::vftable`, zeroes the payload fields, and dispatches downloader message `10002`.
- IDA MCP decompilation of `0x0041b5e0` restores `CashShopVersionRequest::vftable` and conditionally deletes the object.
- IDA MCP xrefs show the `0x0060d798` vtable slot is referenced only by the payload constructor helper and the scalar deleting destructor; the dword at `0x0060d798` points to `0x0041b5e0`, and `0x0060d794` points to `??_R4CashShopVersionRequest@@6B@`.
- IDA MCP xrefs show `0x0041b270` is called only from `0x0041c21b` inside the fitting-room dialog constructor, immediately after loading `dword_67A738`.
- IDA MCP xrefs to `0x0067a738` show FileDownloader-family direct writes at `0x0041a6b1`, `0x0041a6b8`, `0x0041a722`, `0x0041b2f0`, and `0x0041b649`; fitting-room code reads the singleton and calls downloader submit helpers.
- IDA MCP decompilation of `0x0041b110` confirms message `10002` calls `0x0041aa00` and then destroys the payload through its vtable; message `10001` calls `0x0041ae20`.
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md) is already `82/88`, reconstructable, and parented to this file based on the vtable/destructor and payload allocation evidence.
- [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md) records the request vtable as source-declared/generated-binary data inside the broader [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) island.

## Historical Proposed Placement

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

## FileDownloader Version Download Context

B001's 2026-06-18 source-quality pass described the version payload as `vtable + state(+0x04) + contentLength(+0x08) + bytesDownloaded(+0x0c)`. The current hierarchy audit resolves this to derived vptr plus [UID:00050F][BaseRequest](by-class/BaseRequest.md) at `+0x04`; `state` survives only as a historical alias for inferred `downloadComplete`. The HTTP worker [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md), class declaration, submit helper, and exact children emit through [UID:0000JC][FileDownloader](by-file/FileDownloader.md). This page preserves request identity, destructor/vtable context, and the former file-boundary analysis without emitting source.

`DownloadCashShopVersion` downloads `itemshop.ver`, parses JsonCpp key `version`, and writes `g_pFittingRoomDialog->m_itemShopVersion` at `+0x790`. The dispatcher destroys the version request after the worker returns.

## Open Questions

- Whether `DownloadCashShopVersion_41AA00` and `DownloadCashShopCatalog_41AE20` were original static functions in a fitting-room source file.
- Resolved: `0x0041b270` belongs to [UID:0000JC][FileDownloader](by-file/FileDownloader.md); this class supplies its allocated payload type.
- Resolved: CashShopVersionRequest and CashShopRequest share the real non-polymorphic [UID:00050F][BaseRequest](by-class/BaseRequest.md) at derived offset `+4`.

## 2026-08-03 B008 Historical-Alias Disposition

- Changed the active path to exactly `NONE`; no standalone CashShopVersionRequest source file should be generated.
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md) emits its exact BaseRequest-derived declaration through [UID:0000JC][FileDownloader](by-file/FileDownloader.md) at position `1`; exact method support follows the same class route.
- The historical cash-shop and fitting-room placement alternatives remain above as useful source-recovery history. They are superseded by the shared PMD, exact object sizes, FileDownloader singleton receiver, contiguous code, adjacent vtables, and adjacent scalar-destructor evidence.

## Cross-References

- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- [UID:00050F][BaseRequest](by-class/BaseRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md)
- [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md)
- [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-03 B008 UID0003FS coordinated source-placement implementation:
  - Changed `85/87` to `92/94` and reconstruction path from `NexusTK/cashshop/` to `NONE`.
  - Preserved the prior standalone placement and payload investigation as historical alias evidence while routing the BaseRequest-derived class and exact children through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
  - Resolved the submit-helper and shared-base questions, while keeping original lexical/file-name uncertainty explicit below the `95/95` barrier.

- 2026-06-18 B001 FileDownloader support sync: added the resolved payload layout and clarified that FileDownloader emits the version HTTP worker while CashShopVersionRequest remains the request payload/vtable owner.

- Before: this file described the version request methods by address only.
- After: the projected path is set to `NexusTK/cashshop/`, the page documents class-owned versus cross-linked downloader contents, and the completion/confidence scores are raised with a live IDA evidence rationale.
- Summary/evidence: 2026-06-03 IDA MCP confirms the request payload vtable/destructor, fitting-room submit call, downloader message `10002`, and FileDownloader-owned singleton writes. The submit helper remains provisional because the call path uses FileDownloader-lifetime `dword_67A738`.
- 2026-06-07 A004 boundary refresh:
  - Before: score was `78/86`; the page had the main ownership caveats but did not spell out class-owned, cross-linked, and generated-binary vtable handling in one place.
  - Changed to: completion `82` with confidence unchanged at `86`, added an ownership-boundary table, linked the class page's parented `82/88` evidence, and linked the read-only vtable/data island that contains the `0x0060d798` request vtable.
  - Summary/evidence: class page [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md), scalar deleting destructor [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md), submit helper [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), and read-only data page [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) now make the payload-vs-downloader split auditable from this file page.
- 2026-06-12 A003 Batch255 vtable split:
  - Before: `82/86`; broad read-only island evidence kept the main class below the strict parent gate.
  - Changed to: `85/87`; exact [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md) and the raised class page now make the file/class route clear enough for the strict gate.
  - Summary/evidence: live IDA MCP confirmed the class RTTI/vtable dwords and xrefs, while existing submit-helper caveats remain below final-source quality but no longer block file-level ownership.
