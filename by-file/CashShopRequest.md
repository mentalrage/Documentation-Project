*** UID:0000I0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CashShopRequest

## Status

- Confidence: strong for class ownership, inherited payload layout, emitted lifecycle source, and the coordinated FileDownloader module placement.
- Current status: historical alias page with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`; no standalone `NexusTK/cashshop/CashShopRequest.cpp` is emitted. Active source routes through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
- Historical proposed module: `NexusTK/cashshop/CashShopRequest.cpp`. This remains documented below as a superseded reconstruction choice, while stale generated Socket send-corridor references remain search/provenance links only.
- Active source status: [UID:00001H][CashShopRequest](by-class/CashShopRequest.md) emits its BaseRequest-aware declaration at position `2` through [UID:0000JC][FileDownloader](by-file/FileDownloader.md); [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) emits the constructor body through the same route. [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) remains a formal no-body comment because the compiler regenerates that wrapper from the class/destructor/vtable route.
- Main class: [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- Main address docs: [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) and exact CashShopRequest lifecycle/vtable children. The older [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md), [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) rows are retained only as stale generated-owner/search provenance for the Socket send corridor. [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) is retained only as stale generated-owner/search provenance and Thread boundary evidence.
- Ownership correction: the former `0x00528290-0x005283d5` auth/directory range is now corrected to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); see [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md).
- Evidence basis: lookup, bytes, disassembly, xref/RTTI, live worker, destructor, and SSO-helper checks captured during the 2026-07-12 mandatory IDA MCP session `e72f177b` evidence pass, plus preserved Socket/Thread global and ownership corrections. Later session availability is not asserted.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 92 | This alias page preserves the full standalone-file investigation, exact `0x28` payload/lifecycle evidence, Socket/Thread/FileDownloader boundaries, and the final coordinated route. It no longer generates a duplicate translation unit. |
| Confidence | 94 | RTTI BaseRequest PMD `+4`, request sizes, constructor/worker/destructor behavior, contiguous request/FileDownloader code and vtables, and adjacent scalar destructors support [UID:0000JC][FileDownloader](by-file/FileDownloader.md) as the strongest reconstruction module. Exact original file spelling remains below source/PDB certainty. |

## Evidence Map

| Evidence | What it supports | Ownership caveat |
| --- | --- | --- |
| [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) | Parent-blank inventory over the exact raw constructor/destructor children. | The container itself is non-emitting and unassigned; FileDownloader submit helpers are cross-linked below but no longer treated as part of this by-memory inventory. |
| [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) | Exact class RTTI/vtable source-declared data. | Split from the mixed CashShop/FileDownloader `.rdata` prefix in Batch255. |
| [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) | Historical generated send-corridor inventory and packet-helper reachability. | Final source owner for the complete corridor is [UID:0000DD][Socket](by-class/Socket.md); this row is search/provenance context only. |
| [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) | Historical generated-owner/search provenance and Thread boundary evidence. | Current ownership is [UID:0000OR][Thread](by-file/Thread.md); B003 2026-06-20 resolves it as `WaitForQueueDrain`, `WaitForResult`, wait-handle helpers, worker dispatch, and queue-post helpers, not CashShopRequest-owned source. |
| [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) | Packet sender lifetime is Socket constructor/destructor-family owned. | Recovered `CashShopRequest*` global aliases are not final ownership proof. |
| [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) and [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md) | Downloader request singleton storage and caller argument source. | Lifetime writes point to FileDownloader, not a CashShopRequest-owned global. |
| [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) | Current projected placement under `cashshop/CashShopRequest.cpp`. | Tree also records the later `Thread`/network split candidates. |

## Hypothesis

`CashShopRequest` is a real `0x28` polymorphic request-payload class, but stale generated names previously overextended it into the Socket send corridor. Its accepted declaration contains a completion byte, content-length DWORD, cumulative-byte DWORD, and 24-byte SSO string. Broad Socket queue/send helpers remain Socket-owned or inventory-only provenance.

Historical hypothesis: keep the class in `cashshop/CashShopRequest.cpp` because many behaviors are cash-shop-specific. The coordinated 2026-08-03 audit supersedes that physical split without deleting the reasoning: the payload is declared with BaseRequest and FileDownloader because code/RTTI/destructor adjacency and shared downloader dispatch outweigh feature naming. Treat [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), and related `0x00574b90-0x00575377` send-corridor names as stale generated Socket provenance unless later header evidence proves a separate sender interface. Live IDA rechecks show [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime writes belong to Socket, and [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738` lifetime writes belong to FileDownloader. Recovered `CashShopRequest*` global aliases are therefore not final ownership proof.

## Contents

Likely source-level contents:

- [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md), [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md), and separate [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md). [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) is only the non-emitting inventory for the early raw pair. The `0002CM` by-memory page emits only a formal no-body trace comment because the scalar deleting destructor is compiler-generated class ABI output, while ordinary cleanup remains with `0002CI`.
- Item/fitting-room/named request payload allocation.
- Downloader request submission helpers [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) are now resolved as FileDownloader receiver methods in the coordinated module. `0002CK` supplies the accepted inherited `downloadComplete`, `contentLength`, `bytesDownloaded`, and derived `responseText` names; the 2026-07-12 mandatory-session `e72f177b` pass reconfirmed the `0x28` allocation, vtable store, exact zero/SSO initialization, message `10001`, and fitting-room handoff at `+0x7a8`.
- Cash-shop item, fitting-room, named request, and packet-send request submission.
- Stale generated Socket send-corridor references: [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md), [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md), and adjacent command helpers remain useful search/provenance links only. Their current direct source owner is [UID:0000DD][Socket](by-class/Socket.md), or a parent-blank non-emitting Socket split inventory, while [UID:0000OR][Thread](by-file/Thread.md) owns only the generic queue primitive. The real `g_pCashShopRequest` / nearby legacy alias confusion must not be used to type [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- Stale generated synchronous submit/wait provenance only: [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) now belongs to [UID:0000OR][Thread](by-file/Thread.md) as base queue-drain/result-wait/dispatch infrastructure.
- Request queue dispatch through a message queue plus semaphore; current source planning treats the core `0x00596960` dispatcher as `Thread::DispatchRequest`.

## Evidence

- The 2026-07-12 mandatory-session `e72f177b` pass reconfirmed the exact 55-byte raw constructor, unique signature, no direct raw-start xref, four `0x0060d7a0` vtable refs, live `0x28` inline construction, message `10001` worker route, four field roles, ordinary/scalar destruction, and 24-byte SSO assign/append layout. Later session availability is not asserted.
- Historical pre-callback generated command `000000008342`, refreshed `2026-07-12T17:30:01-04:00`, carried UID0002CH as an `Empty Emitter Marker`; this was not a zero-byte file. Verified post-callback command `000000008358`, refreshed `2026-07-12T17:47:59-04:00`, emits UID00001H at `89/91` and UID0002CH at `90/92` with the accepted class and constructor text; UID0002CH is not an empty marker in that output.
- 2026-06-04 live IDA MCP reports raw/non-function constructor and non-deleting destructor starts at `0x0041a5d0` and `0x0041a610`. Raw disassembly shows the constructor stores the `CashShopRequest` vtable at `+0x00`, clears state fields, initializes SSO fields at `+0x20/+0x24`, and returns at `0x0041a606`; the raw destructor restores the same vtable, releases non-SSO string storage, resets SSO fields, and returns at `0x0041a65c`.
- 2026-06-12 A003 Batch255 live IDA MCP dword/xref scan confirms exact [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md): `0x0060d79c -> ??_R4CashShopRequest@@6B@`, `0x0060d7a0 -> sub_41B570`, four vtable-slot refs, and the `0x0060d7a4` FileDownloader boundary.
- 2026-06-04 live IDA confirms modeled submit/destructor functions at `0x0041b180-0x0041b1f5`, `0x0041b200-0x0041b26d`, `0x0041b270-0x0041b2c9`, and `0x0041b570-0x0041b5db`. Direct callers are `0x00451d18`, `0x0041cd0f`, and `0x0041c21b` for the three submit helpers; the scalar deleting destructor is referenced from vtable slot `0x0060d7a0`.
- 2026-06-04 live IDA confirms the CashShopRequest vtable boundary: `0x0060d79c` is `??_R4CashShopRequest@@6B@`, `0x0060d7a0 -> 0x0041b570`, and `0x0060d7a4` is already the next `FileDownloader` RTTI pointer.
- 2026-06-04 live IDA confirms send/status function boundaries: `0x00574b90-0x00574ba4`, `0x00574bb0-0x00574c13`, `0x00574c20-0x00574c35`, `0x00574c40-0x00574ca1`, `0x00574cb0-0x00574cc5`, `0x00574cd0-0x00574cdb`, `0x00574ce0-0x00574cf0`, `0x00574cf0-0x00574d00`, `0x00574d40-0x00574e44`, `0x00574e50-0x0057536b`, and `0x00575370-0x00575377`.
- 2026-06-04 live IDA confirms `0x00574d00` remains a raw/non-function start with no direct code or data refs. Raw bytes allocate/copy caller data and dispatch request code `0x0e` through `0x00596960`, then return at `0x00574d3c`.
- 2026-06-04 live IDA caller counts preserve the broad send-funnel evidence: `QueueAndSendPacket` at `0x00574bb0` has 416 direct code refs; `0x00574d40` has callers `0x005542a9` and `0x0058b42f`; `0x00574e50` has callers `0x00508b14`, `0x005143ad`, and `0x0053f8ed`; `0x00575370` has three direct callers.
- 2026-06-04 live IDA confirmed wait/dispatch helper boundaries at `0x00596620-0x0059675e`, `0x00596760-0x005967c7`, and `0x00596960-0x005969b0`; B003 2026-06-20 resolves these as base `Thread::WaitForQueueDrain`, `Thread::WaitForResult`, and `Thread::DispatchRequest`, with old CashShop names kept only for search/provenance.
- 2026-06-04 live IDA global-reference checks show `0x0067a7ec` has 489 xrefs from broad packet-send call sites, `0x0067a738` has nine xrefs spanning FileDownloader lifetime and fitting-room/downloader submit reads, and `0x0066dee0` has three xrefs from the map/friend-list upload paths. These globals support the current boundary caveats rather than pure cash-shop ownership.

## File Split

Keep feature packet construction out of this file. The former Socket send-corridor rows have 416 broad `QueueAndSendPacket` callers across chat, clan, board, mail, item, map, and other feature modules. Those call sites should remain in their feature files and send through [UID:0000DD][Socket](by-class/Socket.md), not through a CashShopRequest-owned API.

Keep final transport and encryption in [UID:0000NS][Socket](by-file/Socket.md). Former generated CashShopRequest send-corridor docs describe buffer-copy/queue behavior, but current ownership places that queue-send corridor with Socket and inherited Thread queue infrastructure. `Socket::SendEncodedPacket` performs framing, transform/encryption, and transport writes. The `g_packetSender` lifetime evidence should bias future cleanup toward Socket/network ownership rather than a cash-shop-owned global.

The final UID0000MV decision makes the Socket route definitive: `g_packetSender` is `Socket *`; generated `CashShopRequest *`, `Thread *`, and `void *` aliases are rejected or historical. `QueueAndSendPacket`, retained command `14` (`QueueHandshakeBlock`), `QueueClientVersionStatusPacket`, `BuildAndSendFriendNameListSync`, `GetConnectionStatus`, and adjacent command helpers are Socket-owned.

Keep fitting-room UI/catalog state in [UID:0000JE][FittingRoom](by-file/FittingRoom.md) and [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md). `CashShopRequest::SubmitFittingRoomRequest` allocates and dispatches a request payload, but the item-shop HTTP download, `ItemShop.jbn` cache, dialog controls, and preview state belong to the fitting-room feature module.

Keep the shared HTTP download dispatcher in [UID:0000JC][FileDownloader](by-file/FileDownloader.md). Live IDA confirms the [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `0x0067a738` write/clear set belongs to the FileDownloader constructor/destructor family.

`FileDownloader.cpp` is the active coordinated reconstruction translation unit for the payload class cluster: `CashShopVersionRequest`, `CashShopRequest`, and `FileDownloader` RTTI/vtables are contiguous; their scalar deleting destructors are contiguous; the raw request lifecycle directly precedes `FileDownloader` construction; the live catalog producer/consumer path is downloader-local; and both request classes share [UID:00050F][BaseRequest](by-class/BaseRequest.md). The earlier instruction to preserve a standalone CashShopRequest route is retained as historical pre-audit guidance; the required coordinated audit has now been completed.

## 2026-07-05 B001 Source Split For Scalar Deleting Destructor

[UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) remains routed through this file via [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), but it does not contribute a handwritten source function body to `CashShopRequest.cpp`. During the historical 2026-07-05 MCP pass, session `19917133` reconfirmed the function as `sub_41B570`, size `0x6b`, with the only direct xref from vtable slot `0x0060d7a0`; no other VA/RVA pointer route to `0x0041b570` was found. The vtable slot also ties the wrapper to the raw constructor, raw non-deleting destructor, catalog payload setup, and wrapper restore sites at `0x0041a5e8`, `0x0041a613`, `0x0041b22d`, and `0x0041b576`.

The source split is therefore: ordinary destructor cleanup semantics are documented on [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md), vtable data on [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md), and scalar-delete flag/delete glue on `0002CM`. Per `by-structure.md` line 263, the `0002CM` formal C++ block should emit a minimal trace comment rather than remain an empty marker or duplicate compiler-generated ABI glue as handwritten C++.

## Historical Proposed Placement

```text
cashshop/
  CashShopRequest.h
  CashShopRequest.cpp
```

Potential later split:

```text
network/
util/
  Thread.cpp            // generic DispatchRequest/post-message primitive if class ownership changes
cashshop/
  CashShopRequest.cpp   // cash-shop/download/auth-specific request payload methods
```

This was the accepted pre-2026-08-03 reconstruction decision for UID0002CH. It is preserved as historical evidence, not current output. The coordinated UID0003FS family audit moved both request declarations and their exact children together through [UID:0000JC][FileDownloader](by-file/FileDownloader.md), avoiding the previously rejected one-off migration.

## 2026-08-03 B008 Historical-Alias Disposition

- This page remains the all-encompassing record of the former standalone CashShopRequest source hypothesis, lifecycle evidence, and rejected Socket/Thread ownership pollution, but its reconstruction path is now exactly `NONE`.
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md) is BaseRequest-derived at emitter position `2` under [UID:0000JC][FileDownloader](by-file/FileDownloader.md). Exact constructor and support children follow that class route; this by-file alias does not emit duplicate source.
- The move is coordinated rather than cosmetic: [UID:00050F][BaseRequest](by-class/BaseRequest.md), CashShopVersionRequest, CashShopRequest, and FileDownloader share one source inventory supported by request object sizes, BaseRequest PMDs, code adjacency, contiguous RTTI/vtables, and contiguous scalar-destructor wrappers.
- Historical `cashshop/CashShopRequest.h/.cpp`, flattened-field, and provisional submit-helper conclusions remain above with explicit correction context. They are not pruned because they explain how the final route was selected and which generated aliases must stay rejected.

## Open Questions

- Exact original field spelling/access and physical translation unit remain unavailable without source headers/PDB; class identity and the `0x28` layout are resolved by RTTI/lifecycle/runtime evidence.
- Whether [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) was source-named as a `FileDownloader*`, a shared request-dispatch singleton, or a cash-shop/download facade. Its address/lifetime now point to FileDownloader, but final source-facing type/name remain open.
- Resolved: the coordinated audit moves `CashShopRequest`, `CashShopVersionRequest`, and related exact source children together through [UID:0000JC][FileDownloader](by-file/FileDownloader.md); no one-off UID0002CH move remains pending.
- Current best type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) is `Socket *`. A later request-queue typedef/interface wrapper is still possible, but its lifetime owner and direct command helpers are Socket, not cash-shop-specific code.
- Whether any source-level CashShop or request-sender facade wrapped `Thread::DispatchRequest`; the helper itself is now Thread-owned.
- Final source-facing owner for `BuildAndSendFriendNameListSync`; current evidence favors a social/account friend-name-list opcode `0x77` upload gated by [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`, rather than cash-shop catalog or item inventory state. Keep former `BuildAndSendInventoryData` only as a generated alias for old reports.
- Keep historical search links for old `CashShopRequestWaitDispatch` generated labels while ensuring source ownership remains [UID:0000OR][Thread](by-file/Thread.md).

## Cross-References

- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md)
- [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md)
- [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md)
- [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md)
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md)
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`
- [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## 2026-08-17 B003 UID0000MV Final Exclusion

Exhaustive corridor and source-unit research closes `0x00574ae0-0x00575377` under Socket. UID0001HT remains a non-emitting historical split inventory; UID0001HV emits retained `QueueHandshakeBlock`; UID0001HW is `QueueClientVersionStatusPacket`; UID0001HX is the friend-name sync builder. None is CashShopRequest source, and no separate ProtocolSend module mediates them. CashShopRequest remains limited to its real request-payload/download evidence and accepted BaseRequest/FileDownloader declaration route.

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: finalized the Socket-corridor and ProtocolSend exclusions; preserved all former CashShopRequest generated names as historical provenance only.
- 2026-08-03 B008 UID0003FS coordinated source-placement implementation:
  - Changed `85/87` to `92/94` and reconstruction path from `NexusTK/cashshop/` to `NONE`.
  - Preserved this page as a detailed historical alias while routing [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), its constructor, and related source children through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
  - Historicalized the standalone file tree, flattened request fields, and provisional helper ownership; added the BaseRequest relationship and exact coordinated-cluster rationale without pruning prior evidence.

- 2026-07-12 B003 accepted UID0002CH file support callback:
  - Score, `CANONICAL_OWNER:FILE`, projected path `NexusTK/cashshop/`, and all current child routes remain unchanged at `85/87`.
  - Replaced stale class/file-level no-code and zero-byte current-state wording with accepted class/constructor emission, exact `0x28` four-field/SSO evidence, and the validator-owned pre-callback empty-marker state from command `000000008342`.
  - Recorded `FileDownloader.cpp` as the strongest original-TU candidate while rejecting a one-off move; migration requires a coordinated `CashShopRequest`/`CashShopVersionRequest`/`FileDownloader` audit. UID0000WH, UID0002CI, UID0002CM, UID0002CK, UID0003FS, and FileDownloader support remain unchanged.
- 2026-06-20 B003 Thread dispatch helper support update:
  - Removed [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) from main CashShop-owned address docs and kept it only as stale generated-owner/search provenance. Updated wait/result/dispatch wording to the Thread-owned names from [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md).
- 2026-06-20 B006 Socket support sync:
  - Moved the former Socket send-corridor rows out of active CashShopRequest contents and marked `QueueAndSendPacket`, raw command `14`, `SendPositionUpdate`, `BuildAndSendFriendNameListSync`, `GetConnectionStatus`, and adjacent command helpers as Socket-owned search/provenance links.
  - Evidence: B006 report reconfirmed `g_packetSender` as `Socket *`, rejected generated CashShopRequest aliases, and tied command helper consumers to `Socket::HandleSocketCommand`.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: source-file split notes referenced the upload flag only as historical `byte_66DEE0`.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag to the opcode `0x77` friend-name-list upload gate rather than cash-shop catalog state.
- 2026-06-04: Raised scores from `72/80` to `82/86` after live IDA MCP revalidated the raw constructor/destructor starts, modeled submit/send/wait function boundaries, CashShopRequest vtable slot and FileDownloader boundary, caller counts for `QueueAndSendPacket` and queue helpers, and current xrefs for `g_packetSender`, `g_pCashShopRequest`, and the friend-list upload flag.
  - Before: the page had useful child links and boundary caveats, but still relied on stale provenance wording and had not recorded the current live IDA xref/function-boundary pass.
  - After: evidence is based on live IDA/disassembly, the stale provenance wording is removed, the manual score aligns with the already attached class page, and C++ remains blank because raw starts, downloader-submit ownership, packet-sender typing, and generic thread-queue placement are still unresolved.
- 2026-06-12 A003 Batch255 vtable split:
  - Before: `82/86`; direct class/file chain was below the strict gate for a class-owned vtable child.
  - Changed to: `85/87`; exact [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) and raised class page now support the route.
  - Summary/evidence: live IDA MCP confirmed the class RTTI/vtable dwords and four vtable-slot refs. Existing queue/send/downloader caveats remain, but they do not block the exact vtable ownership claim.
- Before: this proposed source file described the early constructor/destructor and request-submit cluster through broad ranges and address-only mentions.
- After: the contents list and cross-references point to exact `by-memory` child pages for the raw constructor/destructor, scalar deleting destructor, and three downloader request-submit helpers.
- Summary/evidence: IDA MCP and raw disassembly split the early cluster into exact children, while receiver evidence for the submit helpers still points through FileDownloader-lifetime `dword_67A738`.
- Current update: raised from `55/72` to `72/80` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/cashshop/` based on the proposed source tree plus IDA-backed child pages. C++ remains blank because final helper/class names and source split boundaries are not final-source quality.
- 2026-06-12 B001 memory-range repair:
  - Before: [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) was a broad reconstructable `0x0041a5d0-0x0041b5da` page and could be read as file ownership over FileDownloader/helper spans.
  - Changed to: `0000WH` is now a parent-blank, non-emitting `0x0041a5d0-0x0041a662` raw-lifecycle inventory; the exact raw constructor/destructor children and separate scalar deleting destructor remain the CashShopRequest-owned source-bearing pages.
  - Summary/evidence: B001's IDA-backed audit confirmed the successor FileDownloader constructor at `0x0041a670`, the separate scalar deleting destructor at `0x0041b570-0x0041b5db`, and padding boundaries around the narrowed raw lifecycle container.
- 2026-06-17 B003 Socket lifecycle source-quality pass:
  - Before: this file still listed broad Socket send-corridor helpers as likely CashShopRequest contents.
  - After: those helpers are explicitly search/provenance links only; the current direct owner is [UID:0000DD][Socket](by-class/Socket.md), with [UID:0000OR][Thread](by-file/Thread.md) owning only the generic queue primitive.
  - Evidence: B003 reconfirmed `g_packetSender` as high-probability `Socket *`, Socket-only lifetime writes, command-consumer cases, and real `g_pCashShopRequest` separation at `0x0067a738`.
