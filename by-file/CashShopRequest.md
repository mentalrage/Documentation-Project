*** UID:0000I0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/cashshop/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CashShopRequest

## Status

- Confidence: strong for class ownership, medium for original module placement.
- Proposed module: `NexusTK/cashshop/CashShopRequest.cpp`, with a possible later split of the generic queue/send funnel into a base [UID:0000OR][Thread](by-file/Thread.md) request helper or network sender interface.
- Projected path status: valid current reconstruction target; source split caveats still block final-source C++.
- Main class: [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- Main address docs: [UID:0000WH][0x0041a5d0-0x0041b5da.CashShopRequestItemSetup](by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md), [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md), [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md), and [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md)
- Ownership correction: the former `0x00528290-0x005283d5` auth/directory range is now corrected to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); see [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md).
- Evidence basis: live IDA MCP lookup, raw disassembly, caller/xref, vtable, and global-reference checks through 2026-06-04.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 82 | The page now has live IDA coverage for raw constructor/destructor starts, modeled submit/send/wait boundaries, vtable placement, queue-dispatch caller counts, and current global-reference corrections. It is not higher because several helpers still need final source ownership review. |
| Confidence | 86 | Existing IDA-backed child pages, the parent class page, and the proposed source tree support `NexusTK/cashshop/` as the current reconstruction home. Confidence remains below final-source quality because queue/send, downloader-submit, and generic thread helper boundaries may later split out. |

## Evidence Map

| Evidence | What it supports | Ownership caveat |
| --- | --- | --- |
| [UID:0000WH][0x0041a5d0-0x0041b5da.CashShopRequestItemSetup](by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md) | Early constructor/destructor and request-payload setup cluster. | Aggregate page still includes provisional downloader-submit helpers. |
| [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) | Send/status helper cluster and `QueueAndSendPacket` reachability. | Generic send API is used by many feature modules and may split to a base request/network interface. |
| [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) | Synchronous wait/dispatch mechanics and the generic queue post primitive. | Current ownership is [UID:0000OR][Thread](by-file/Thread.md), so this is supporting boundary evidence rather than CashShopRequest-owned source. |
| [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) | Packet sender lifetime is Socket constructor/destructor-family owned. | Recovered `CashShopRequest*` global aliases are not final ownership proof. |
| [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) and [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md) | Downloader request singleton storage and caller argument source. | Lifetime writes point to FileDownloader, not a CashShopRequest-owned global. |
| [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) | Current projected placement under `cashshop/CashShopRequest.cpp`. | Tree also records the later `Thread`/network split candidates. |

## Hypothesis

`CashShopRequest` is a real class-centered source module, but its current name is broader than a pure cash-shop UI file. It combines cash-shop/download/auth directory request setup with a generic queued request funnel used by hundreds of packet senders across the client.

For source reconstruction, keep the class in `cashshop/CashShopRequest.cpp` for now because many methods are cash-shop-specific. Mark [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and `DispatchRequest` as possible later base-thread/request-sender split candidates after class/interface cleanup. Live IDA rechecks show [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime writes belong to Socket, and [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738` lifetime writes belong to FileDownloader. Recovered `CashShopRequest*` global aliases are therefore not final ownership proof.

## Contents

Likely source-level contents:

- [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) and [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md), plus the raw non-deleting destructor body [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md).
- Item/fitting-room/named request payload allocation.
- Provisional downloader request submission helpers [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), pending separation from the FileDownloader-lifetime request singleton.
- Cash-shop item, fitting-room, named request, and packet-send request submission.
- `QueueWindowMessage`, `QueueAndSendPacket`, `SendStringCommand`, and raw/provisional [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md).
- Connection/send-disable status helpers.
- Position/status update, connection-status getter, and opcode `0x77` friend/name-list upload construction. The older `BuildAndSendInventoryData` name should remain suspect because caller evidence and [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / `g_friendNameListSyncEnabled` point away from item inventory semantics.
- Synchronous submit/wait and result-list handling.
- Request queue dispatch through a message queue plus semaphore; current source planning treats the core `0x00596960` dispatcher as [UID:0000OR][Thread](by-file/Thread.md) infrastructure until class-layout cleanup proves otherwise.

## Evidence

- 2026-06-04 live IDA MCP reports raw/non-function constructor and non-deleting destructor starts at `0x0041a5d0` and `0x0041a610`. Raw disassembly shows the constructor stores the `CashShopRequest` vtable at `+0x00`, clears state fields, initializes SSO fields at `+0x20/+0x24`, and returns at `0x0041a606`; the raw destructor restores the same vtable, releases non-SSO string storage, resets SSO fields, and returns at `0x0041a65c`.
- 2026-06-04 live IDA confirms modeled submit/destructor functions at `0x0041b180-0x0041b1f5`, `0x0041b200-0x0041b26d`, `0x0041b270-0x0041b2c9`, and `0x0041b570-0x0041b5db`. Direct callers are `0x00451d18`, `0x0041cd0f`, and `0x0041c21b` for the three submit helpers; the scalar deleting destructor is referenced from vtable slot `0x0060d7a0`.
- 2026-06-04 live IDA confirms the CashShopRequest vtable boundary: `0x0060d79c` is `??_R4CashShopRequest@@6B@`, `0x0060d7a0 -> 0x0041b570`, and `0x0060d7a4` is already the next `FileDownloader` RTTI pointer.
- 2026-06-04 live IDA confirms send/status function boundaries: `0x00574b90-0x00574ba4`, `0x00574bb0-0x00574c13`, `0x00574c20-0x00574c35`, `0x00574c40-0x00574ca1`, `0x00574cb0-0x00574cc5`, `0x00574cd0-0x00574cdb`, `0x00574ce0-0x00574cf0`, `0x00574cf0-0x00574d00`, `0x00574d40-0x00574e44`, `0x00574e50-0x0057536b`, and `0x00575370-0x00575377`.
- 2026-06-04 live IDA confirms `0x00574d00` remains a raw/non-function start with no direct code or data refs. Raw bytes allocate/copy caller data and dispatch request code `0x0e` through `0x00596960`, then return at `0x00574d3c`.
- 2026-06-04 live IDA caller counts preserve the broad send-funnel evidence: `QueueAndSendPacket` at `0x00574bb0` has 416 direct code refs; `0x00574d40` has callers `0x005542a9` and `0x0058b42f`; `0x00574e50` has callers `0x00508b14`, `0x005143ad`, and `0x0053f8ed`; `0x00575370` has three direct callers.
- 2026-06-04 live IDA confirms wait/dispatch helper boundaries at `0x00596620-0x0059675e`, `0x00596760-0x005967c7`, and `0x00596960-0x005969b0`; `0x00596960` has 22 direct callers, including the downloader submit helpers, the raw `0x00453a30` candidate, MiscWorkThread wrappers, and socket/request sender wrappers.
- 2026-06-04 live IDA global-reference checks show `0x0067a7ec` has 489 xrefs from broad packet-send call sites, `0x0067a738` has nine xrefs spanning FileDownloader lifetime and fitting-room/downloader submit reads, and `0x0066dee0` has three xrefs from the map/friend-list upload paths. These globals support the current boundary caveats rather than pure cash-shop ownership.

## File Split

Keep feature packet construction out of this file. Its 416 callers include chat, clan, board, mail, item, map, and other feature modules. Those call sites should remain in their feature files while sharing this queue/send API.

Keep final transport and encryption in [UID:0000NS][Socket](by-file/Socket.md). `CashShopRequest` currently queues work and copies buffers; `Socket::SendEncodedPacket` performs framing, transform/encryption, and transport writes. The `g_packetSender` lifetime evidence should bias future cleanup toward a network sender/request interface rather than a cash-shop-owned global.

Keep fitting-room UI/catalog state in [UID:0000JE][FittingRoom](by-file/FittingRoom.md) and [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md). `CashShopRequest::SubmitFittingRoomRequest` allocates and dispatches a request payload, but the item-shop HTTP download, `ItemShop.jbn` cache, dialog controls, and preview state belong to the fitting-room feature module.

Keep the shared HTTP download dispatcher in [UID:0000JC][FileDownloader](by-file/FileDownloader.md). Live IDA confirms the [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `0x0067a738` write/clear set belongs to the FileDownloader constructor/destructor family. That does not merge the small `CashShopRequest` payload class into `FileDownloader.cpp`; it does mean the adjacent `0x0041b180`, `0x0041b200`, and `0x0041b270` submission helpers need an explicit dispatcher/payload ownership review before migration.

## Proposed Placement

```text
cashshop/
  CashShopRequest.h
  CashShopRequest.cpp
```

Potential later split:

```text
network/
  ProtocolSend.cpp      // only if later evidence proves a real cross-feature free-send module
util/
  Thread.cpp            // generic DispatchRequest/post-message primitive if class ownership changes
cashshop/
  CashShopRequest.cpp   // cash-shop/download/auth-specific request payload methods
```

## Open Questions

- Whether `CashShopRequest` was the original class name or a recovered name applied to a broader request dispatcher.
- Whether [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) was source-named as a `FileDownloader*`, a shared request-dispatch singleton, or a cash-shop/download facade. Its address/lifetime now point to FileDownloader, but final source-facing type/name remain open.
- Whether `0x0041b180`, `0x0041b200`, and `0x0041b270` should stay in this file or move with [UID:0000JC][FileDownloader](by-file/FileDownloader.md) / a later downloader-request dispatcher split.
- Whether [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) should be typed as `Socket*` or a request-queue interface after type cleanup. Its lifetime owner is now Socket, not cash-shop-specific code.
- Whether `DispatchRequest` should be treated purely as `Thread::DispatchRequest` in final source, with derived classes only exposing thin convenience wrappers.
- Final source-facing owner for `BuildAndSendFriendNameListSync`; current evidence favors a social/account friend-name-list opcode `0x77` upload gated by [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / `g_friendNameListSyncEnabled`, rather than cash-shop catalog or item inventory state. Keep former `BuildAndSendInventoryData` only as a generated alias for old reports.
- Whether wait/result list helpers at `0x00596620-0x005969b0` were originally in this class source or a shared threaded-request helper. Current [UID:0000OR][Thread](by-file/Thread.md) docs treat the `0x00596620+` helper names as generic/polluted until final class ownership is cleaned.

## Cross-References

- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0000WH][0x0041a5d0-0x0041b5da.CashShopRequestItemSetup](by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md)
- [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md)
- [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md)
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / `g_friendNameListSyncEnabled`
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

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: source-file split notes referenced the upload flag only as historical `byte_66DEE0`.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag to the opcode `0x77` friend-name-list upload gate rather than cash-shop catalog state.
- 2026-06-04: Raised scores from `72/80` to `82/86` after live IDA MCP revalidated the raw constructor/destructor starts, modeled submit/send/wait function boundaries, CashShopRequest vtable slot and FileDownloader boundary, caller counts for `QueueAndSendPacket` and queue helpers, and current xrefs for `g_packetSender`, `g_pCashShopRequest`, and the friend-list upload flag.
  - Before: the page had useful child links and boundary caveats, but still relied on stale provenance wording and had not recorded the current live IDA xref/function-boundary pass.
  - After: evidence is based on live IDA/disassembly, the stale provenance wording is removed, the manual score aligns with the already attached class page, and C++ remains blank because raw starts, downloader-submit ownership, packet-sender typing, and generic thread-queue placement are still unresolved.
- Before: this proposed source file described the early constructor/destructor and request-submit cluster through broad ranges and address-only mentions.
- After: the contents list and cross-references point to exact `by-memory` child pages for the raw constructor/destructor, scalar deleting destructor, and three downloader request-submit helpers.
- Summary/evidence: IDA MCP and raw disassembly split the early cluster into exact children, while receiver evidence for the submit helpers still points through FileDownloader-lifetime `dword_67A738`.
- Current update: raised from `55/72` to `72/80` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/cashshop/` based on the proposed source tree plus IDA-backed child pages. C++ remains blank because final helper/class names and source split boundaries are not final-source quality.
