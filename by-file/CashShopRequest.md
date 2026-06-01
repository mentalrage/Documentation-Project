*** UID:0000I0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:55 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CashShopRequest

## Status

- Confidence: strong for class ownership, medium for original module placement.
- Proposed module: `cashshop/CashShopRequest.cpp`, with a possible later split of the generic queue/send funnel into a base [UID:0000OR][Thread](by-file/Thread.md) request helper or network sender interface
- Current Wave3 file: `class_CashShopRequest.cpp`
- Main class: [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- Main address docs: [UID:0000WH][0x0041a5d0-0x0041b5da.CashShopRequestItemSetup](by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md), [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md), [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md), [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md), and [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md)
- Stale generated ownership note: the former `0x00528290-0x005283d4` auth/directory range is now corrected to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); see [UID:0001CK][0x00528290-0x005283d4.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d4.CashShopRequestAuthDirectory.md).
- Evidence basis: `simroot_v2` generated source, Wave3 metadata/xrefs, and IDA MCP lookup/xref checks through 2026-05-25.

## Hypothesis

`CashShopRequest` is a real class-centered source module, but its current name is broader than a pure cash-shop UI file. It combines cash-shop/download/auth directory request setup with a generic queued request funnel used by hundreds of packet senders across the client.

For source reconstruction, keep the class in `cashshop/CashShopRequest.cpp` for now because many methods are cash-shop-specific. Mark [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and `DispatchRequest` as possible later base-thread/request-sender split candidates after class/interface cleanup. A 2026-05-25 IDA recheck shows [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime writes belong to Socket, and a separate recheck shows [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738` lifetime writes belong to FileDownloader. Generated `CashShopRequest*` global types are therefore not final ownership proof.

## Contents

Likely source-level contents:

- [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) and [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md), plus the raw non-deleting destructor body [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md).
- Item/fitting-room/named request payload allocation.
- Provisional downloader request submission helpers [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), pending separation from the FileDownloader-lifetime request singleton.
- Cash-shop item, fitting-room, named request, and packet-send request submission.
- `QueueWindowMessage`, `QueueAndSendPacket`, `SendStringCommand`, and raw/provisional [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md).
- Connection/send-disable status helpers.
- Position/status update, connection-status getter, and opcode `0x77` friend/name-list upload construction. Current generated names still call the latter `BuildAndSendInventoryData`, but caller evidence and [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) now make the inventory interpretation suspect.
- Synchronous submit/wait and result-list handling.
- Request queue dispatch through a message queue plus semaphore; current `simroot_v2/class_Thread.cpp` emits the core `0x00596960` dispatcher as `Thread::DispatchRequest`.

## Evidence

- Wave3 reports `CashShopRequest` as the only class attached to `class_CashShopRequest.cpp`, with 21 included methods.
- Wave3 class notes describe a 240,208-byte structure with an embedded SSO string, queue/list/critical-section fields, and request codes for named, raw packet, string, raw data, item, fitting room, hash, auth, and directory requests.
- Wave3/simroot and IDA both report `QueueAndSendPacket` at `0x00574bb0` with 416 direct code refs from 380 unique calling functions.
- IDA MCP confirms `QueueAndSendPacket` as `0x00574bb0-0x00574c13`, `SendPositionUpdate` as `0x00574d40-0x00574e44`, `BuildAndSendInventoryData` as `0x00574e50-0x0057536b`, `GetConnectionStatus` as `0x00575370-0x00575377`, and `DispatchRequest` as `0x00596960-0x005969b0`.
- Generated source shows `QueueAndSendPacket` allocating `packetSize + 1`, copying caller data, appending a zero byte, and dispatching request code `8`.
- Current `simroot_v2/class_Thread.cpp` shows `DispatchRequest` enqueuing a small request record and releasing the base thread semaphore.
- IDA MCP `lookup_funcs` on 2026-05-25 reports generated `SendRawData` start `0x00574d00` as `Not a function`, but raw disassembly shows function-shaped code at `0x00574d00-0x00574d3f` that allocates/copies raw bytes and dispatches request code `0x0e`. No external xrefs to the raw start were found; a 2026-05-27 raw-pointer scan also found no loaded dword equal to `0x00574d00`, so keep reachability/final ownership provisional.
- IDA MCP callers on 2026-05-25 show `SendPositionUpdate` is reached from `ReconnectDialog::OnButtonClick` and the `TerminalPane` stream parser. This makes the helper a reconnect/terminal position-state upload, not a cash-shop feature.
- IDA MCP callers on 2026-05-25 show `BuildAndSendInventoryData` is reached from `MapPane::HandlePacket` case `0x6a` and `FriendListDialog::OnOkButton`. Both paths are gated by [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md), and the helper serializes the same 20 config name slots that [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) writes, so its generated `InventoryData` name should be treated as a data issue.
- IDA MCP `py_eval` on 2026-05-25 found all direct writes to `0x0067a7ec` in the Socket constructor/destructor family, even though many generated callers pass that global into this `QueueAndSendPacket` method.
- IDA MCP `py_eval` on 2026-05-25 found all direct writes to `0x0067a738` in the FileDownloader constructor/destructor family, while fitting-room callers pass that storage into the request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270`.

## File Split

Keep feature packet construction out of this file. Its 416 callers include chat, clan, board, mail, item, map, and other feature modules. Those call sites should remain in their feature files while sharing this queue/send API.

Keep final transport and encryption in [UID:0000NS][Socket](by-file/Socket.md). `CashShopRequest` currently queues work and copies buffers; `Socket::SendEncodedPacket` performs framing, transform/encryption, and transport writes. The `g_packetSender` lifetime evidence should bias future cleanup toward a network sender/request interface rather than a cash-shop-owned global.

Keep fitting-room UI/catalog state in [UID:0000JE][FittingRoom](by-file/FittingRoom.md) and [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md). `CashShopRequest::SubmitFittingRoomRequest` allocates and dispatches a request payload, but the item-shop HTTP download, `ItemShop.jbn` cache, dialog controls, and preview state belong to the fitting-room feature module.

Keep the shared HTTP download dispatcher in [UID:0000JC][FileDownloader](by-file/FileDownloader.md). Current generated code writes [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) from `FileDownloader::FileDownloader`, and live IDA confirms the `0x0067a738` write/clear set belongs to the FileDownloader constructor/destructor family. That does not merge the small `CashShopRequest` payload class into `FileDownloader.cpp`; it does mean the adjacent `0x0041b180`, `0x0041b200`, and `0x0041b270` submission helpers need an explicit dispatcher/payload ownership review before migration.

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
- Final source-facing name for `BuildAndSendInventoryData`; current evidence favors a social/account friend-name-list opcode `0x77` upload gated by [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md), rather than cash-shop catalog or item inventory state.
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
- [UID:0001CK][0x00528290-0x005283d4.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d4.CashShopRequestAuthDirectory.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
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

- Before: this proposed source file described the early constructor/destructor and request-submit cluster through broad ranges and address-only mentions.
- After: the contents list and cross-references point to exact `by-memory` child pages for the raw constructor/destructor, scalar deleting destructor, and three downloader request-submit helpers.
- Summary/evidence: IDA MCP and raw disassembly split the early cluster into exact children, while receiver evidence for the submit helpers still points through FileDownloader-lifetime `dword_67A738`.
