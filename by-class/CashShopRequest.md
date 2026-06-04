*** UID:00001H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CashShopRequest

## Status

- Confidence: strong for class ownership, medium for final original module split.
- Current reconstruction source module: [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) at `NexusTK/cashshop/`.
- Autogen status: reconstructable/attached for placeholder routing only; C++ remains blank because field/helper names and source split boundaries are not final-source quality.
- Current relevant ranges: `0x0041a5d0-0x0041b5da`, `0x00453a30-0x00453a9c`, `0x00574b90-0x00575377`, and `0x00596620-0x005969b0`
- Ownership correction: `0x00528290-0x005283d4` is now corrected to [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md); keep [UID:0001CK][0x00528290-0x005283d4.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d4.CashShopRequestAuthDirectory.md) only as a correction record.
- Evidence basis: live IDA MCP function, xref, raw-byte, and global-reference checks through 2026-06-04.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 82 | The class now has live IDA coverage for modeled and raw starts, exact caller counts for the send/wait helpers, queue-dispatch callee evidence, and current global-reference corrections. It is not higher because several helper starts remain raw or source-split provisional. |
| Confidence | 86 | IDA evidence strongly supports this class as the current cash-shop/request-dispatch owner and the parent path is valid. Confidence is capped below final-source quality by the downloader-submit, packet-sender, and generic thread-queue boundaries. |
| Reconstructable | TRUE | The class can be routed to the current CashShopRequest source placeholder. The reconstruction body is intentionally blank until final class layout, helper names, and split decisions are stronger. |

## Evidence Map

| Evidence | What it supports | Boundary note |
| --- | --- | --- |
| [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) | Valid current file parent under `NexusTK/cashshop/`. | File page keeps generic queue/send split candidates explicit. |
| [UID:0000WH][0x0041a5d0-0x0041b5da.CashShopRequestItemSetup](by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md) | Constructor/destructor and request-payload setup ownership. | Aggregate still contains provisional downloader helper ownership. |
| [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) | Queue/send API and send/status helper cluster. | Many callers are non-cash-shop features, so final API placement can still move. |
| [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) | Request wait/dispatch mechanics adjacent to this class. | Current source planning treats the queue post primitive as [UID:0000OR][Thread](by-file/Thread.md). |
| [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) | Packet sender lifetime correction. | Lifetime owner is Socket; recovered `CashShopRequest*` types cannot be trusted alone. |
| [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) | Downloader singleton storage correction. | Lifetime owner is FileDownloader; request-submit helpers need explicit split review. |

## Responsibility

`CashShopRequest` is a threaded request/packet dispatcher with cash-shop-specific payload helpers and a broad generic send funnel. It allocates request payloads and exposes `QueueAndSendPacket`, which many feature modules use for outbound packets. Live IDA confirms the core queue post primitive at `0x00596960` has 22 direct callers and releases the worker semaphore, so CashShopRequest likely consumes inherited/base-thread queue infrastructure rather than owning every dispatch helper outright.

The queue/send boundary is still provisional. IDA MCP evidence from 2026-05-25 shows [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime writes are all Socket constructor/destructor-family writes, even though many packet builders pass that global into `QueueAndSendPacket`. A fresh 2026-06-04 pass still shows 489 xrefs to `0x0067a7ec`, dominated by broad packet-builder reads. A separate `0x0067a738` pass shows [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) lifetime writes are FileDownloader constructor/destructor-family writes, and the 2026-06-04 xrefs still show downloader/fitting-room request-submit paths reading that storage.

## Key Data

Existing layout notes identify a large 240,208-byte object with:

- Embedded small-string state near offset `0x10`.
- Request queue and result-list/monitor/critical-section style fields.
- A semaphore/event path for worker wakeup and synchronous waits.
- Request codes for named requests, raw packet sends, string commands, raw data, item requests, fitting-room requests, hash/auth/directory requests, and queued window messages.

Field names should remain provisional until layout review is fast enough to run safely.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) | `CashShopRequest` raw constructor | Initializes vtable, state byte, pending result, semaphore, and embedded SSO string state. |
| [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md) | raw non-deleting destructor | Releases embedded string heap storage if not SSO and resets inline string state. |
| [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) | `SubmitItemRequest` / minimap submit helper | Allocates item/minimap-style request node and enqueues downloader message `10000`; final owner is provisional because callers pass `dword_67A738`. |
| [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) | `SubmitFittingRoomRequest` / catalog submit helper | Allocates request payload, enqueues downloader message `10001`, and links it to the fitting room dialog if present; final owner is provisional because callers pass `dword_67A738`. |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | `SubmitVersionRequest` | Allocates a version-request payload and enqueues downloader message `10002`; currently cross-linked to `CashShopVersionRequest` and FileDownloader. |
| [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | Releases embedded string heap storage if not SSO and optionally deletes `this`. |
| `0x00453a30` | raw `SubmitNamedRequest` candidate | Raw unmodeled start that allocates a named request node and calls `0x00596960` from `0x00453a92`; no IDA function object or direct start xrefs exist in the current database. |
| `0x00574bb0` | `QueueAndSendPacket` | Exact page: [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Copies packet bytes, appends a zero byte, and dispatches request code `8`; IDA confirms 416 direct code refs. |
| `0x00574d00` | `SendRawData` | Raw/provisional page: [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md). IDA has no function object, no external xrefs to the start, and no loaded dword refs equal to `0x00574d00`; raw bytes allocate/copy data and dispatch request code `0x0e`. |
| `0x00574d40` | `SendPositionUpdate` | Exact page: [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md). Builds an 8-byte position/status upload and dispatches it through request code `8`; callers are reconnect and terminal-stream paths. |
| `0x00574e50` | `BuildAndSendInventoryData` | Exact page: [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md). Builds opcode `0x77` records from 20 config name slots; caller evidence and [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) point to [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md), not item inventory. |
| `0x00575370` | `GetConnectionStatus` | Exact page: [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md). Returns the connection-status byte at `this + 240207`. |
| `0x00596620` | `SubmitAndWait` | Creates an event, enqueues a synchronous request, waits, removes result entry, and closes the event. |
| `0x00596760` | `WaitForResult` | Waits for a matching result-list entry and returns the result payload/handle. |
| `0x00596960` | queue dispatch helper | Live IDA confirms 22 direct callers, request-record enqueue work, and `ReleaseSemaphore`; source planning still treats this as a possible [UID:0000OR][Thread](by-file/Thread.md) queue post primitive rather than a final CashShopRequest-owned body. |

## Live IDA Evidence

- 2026-06-04 live IDA MCP recheck used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA does not model `0x0041a5d0` or `0x0041a610` as functions, but the bytes decode as constructor/destructor-shaped raw starts; `0x0041a607-0x0041a610` is `0xcc` padding after the constructor child.
- IDA confirms exact modeled submit/destructor functions at `0x0041b180-0x0041b1f5`, `0x0041b200-0x0041b26d`, `0x0041b270-0x0041b2c9`, and `0x0041b570-0x0041b5db`. The submit helpers call `0x00596960`; the scalar deleting destructor is reached through the `0x0060d7a0` CashShopRequest vtable.
- IDA still does not model `0x00453a30` or `0x00574d00` as functions. The raw `0x00574d00` start has no external start xrefs and no loaded dword references equal to `0x00574d00`; keep it provisional despite function-shaped bytes.
- IDA confirms `QueueAndSendPacket` at `0x00574bb0-0x00574c13` with 416 direct code xrefs, packet-buffer helper calls at `0x00516030`, `0x00516050`, and `0x00516220`, and queue dispatch through `0x00596960`.
- IDA confirms `SendPositionUpdate` at `0x00574d40-0x00574e44` with two callers, `BuildAndSendInventoryData` at `0x00574e50-0x0057536b` with three callers, and `GetConnectionStatus` at `0x00575370-0x00575377` with three callers.
- IDA confirms wait/dispatch helpers at `0x00596620-0x0059675e`, `0x00596760-0x005967c7`, and `0x00596960-0x005969b0`; the first two use `WaitForSingleObject`/`CloseHandle`, while `0x00596960` enqueues work and calls `ReleaseSemaphore`.
- Current global xrefs show `0x0067a7ec` has 489 references from broad packet-send call sites, `0x0067a738` has FileDownloader/fitting-room request-submit reads and writes, and `0x0066dee0` has three xrefs from the MapPane/friend-list upload paths.

## Ownership Notes

- Cash-shop/download/auth-specific payload creation should remain with this class.
- Downloader request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` should remain provisional until the FileDownloader singleton and payload class split is settled.
- `QueueAndSendPacket` is heavily cross-feature; keep it here until a clearer base queue or network send class is recovered.
- `SendPositionUpdate`, `BuildAndSendInventoryData`, and `GetConnectionStatus` are currently in the same send/status cluster, but their callers are reconnect/terminal/map/friend-list paths rather than cash-shop UI paths.
- `0x00596960` should be treated as a generic [UID:0000OR][Thread](by-file/Thread.md) queue post helper in source-layout planning unless a later class-layout pass proves a CashShopRequest override/wrapper.
- Final packet transport and encryption belong to [UID:0000DD][Socket](by-class/Socket.md).
- Big-endian packet scalar helpers belong to [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), not this class.
- `0x00528290`, `0x00528310`, and raw `0x005283b0` are [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) request-submission wrappers, not `CashShopRequest` methods.
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime belongs to [UID:0000DD][Socket](by-class/Socket.md); keep `QueueAndSendPacket` under this class for current reconstruction, but do not use recovered `CashShopRequest*` global typing as final ownership evidence.

## Open Questions

- Confirm whether the original class name was really `CashShopRequest` or whether this is a recovered owner name for a broader request dispatcher.
- Determine if `QueueAndSendPacket` should become part of a base request queue/interface or Socket-owned sender interface in source reconstruction.
- Reconcile the generic queue-dispatch role at `0x00596960` with older CashShopRequest ownership notes.
- Decide whether `0x0041b180`, `0x0041b200`, and `0x0041b270` belong to this class or to [UID:0000JC][FileDownloader](by-file/FileDownloader.md) / a download-request dispatcher.
- Confirm ownership of globals `g_cashShopRequestPending`, `g_isHighResMode`, `g_pApplication`, and `g_pConfig`; current file ownership should not be treated as final.
- Review a final name for `BuildAndSendInventoryData`; current evidence favors social/account friend-name-list opcode `0x77` upload semantics, with [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) as the server-controlled upload flag.

## Cross-References

- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
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
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-06-04: Raised completion/confidence from `72/80` to `82/86`; reconstructable and parent attachment remain unchanged.
  - Before: the page had useful child links and ownership caveats, but still used stale provenance wording and did not record fresh IDA evidence for the raw starts, caller counts, global xrefs, and queue-dispatch boundary.
  - After: live IDA evidence records the binary identity, modeled and raw method starts, submit helper callers, `QueueAndSendPacket` reachability, wait/dispatch helper ranges, `g_packetSender`/`g_pCashShopRequest`/friend-upload flag xrefs, and the lack of loaded references for raw `0x00574d00`.
  - Reasoning: the class is better documented as reconstructable project code and can leave the low queue, but final C++ remains blank because raw starts, downloader-submit ownership, packet-sender typing, and generic thread-queue placement are still below the 95/95 bar.
- Before: the early `0x0041a5d0` cluster was represented by a broad aggregate range and address-only rows for constructor, submit helpers, and scalar deleting destructor.
- After: the class method inventory points to exact `by-memory` pages for the raw constructor/destructor body, the three downloader submit helpers, and the scalar deleting destructor.
- Summary/evidence: IDA MCP and raw disassembly split the cluster into exact child ranges; the submit helpers remain provisional because live callers pass FileDownloader-lifetime `dword_67A738`.
- Current update: raised from `55/72` to `72/80`, marked reconstructable, and attached to [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). C++ remains blank because final field/helper names and source split decisions are not strong enough.
