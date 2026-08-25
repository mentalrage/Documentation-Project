*** UID:00001H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CashShopRequest : public BaseRequest
{
public:
    CashShopRequest();
    virtual ~CashShopRequest() {}

    std::string responseText;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CashShopRequest

## Status

- Confidence: strong for class ownership, exact `0x28` layout, lifecycle, and runtime roles; medium-high for inferred member spelling/access and original physical module.
- Current reconstruction source module: [UID:0000JC][FileDownloader](by-file/FileDownloader.md) at `NexusTK/network/`, after the coordinated BaseRequest/request/FileDownloader source-placement audit. [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) is retained as a historical alias page with reconstruction path `NONE`.
- Autogen status: reconstructable/attached at emitter position `2`; the formal header declares `CashShopRequest : public BaseRequest`, while the CPP channel is exactly `[[CHILDREN]]` so constructor and other source-bearing definitions remain on exact by-memory children. Child [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) intentionally keeps its formal no-body comment because the compiler regenerates that wrapper from the class/destructor/vtable route.
- Current relevant CashShopRequest ranges: `0x0041a5d0-0x0041a662`, `0x0041b570-0x0041b5db`, and `0x00453a30-0x00453a9c`. The former `0x00574b90-0x00575377` send corridor, [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) are retained only as stale generated-owner/search provenance for Socket-owned helpers. [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) is retained only as stale filename/search provenance and caller-boundary evidence; its source owner is [UID:0000OR][Thread](by-file/Thread.md).
- Ownership correction: `0x00528290-0x005283d5` is now corrected to [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md); keep [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md) only as a correction record.
- Evidence basis: function, byte, xref, RTTI, worker, destructor, and SSO-helper checks captured during the 2026-07-12 mandatory IDA MCP session `e72f177b` evidence pass, plus preserved Socket/Thread ownership corrections. Later session availability is not asserted.

## Item Summary

`CashShopRequest` is the polymorphic catalog-download payload used by the FileDownloader request family. The reconstructed source class is owned and emitted by [UID:0000JC][FileDownloader](by-file/FileDownloader.md) at emitter position `2`; [UID:00001H] remains the class declaration owner for compiler-generated class artifacts such as [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md). The complete 32-bit object is exactly `0x28` bytes and has this source-to-binary layout:

- `+0x00`: the derived `CashShopRequest` vptr.
- `+0x04..+0x0f`: the inherited, non-polymorphic [UID:00050F][BaseRequest](by-class/BaseRequest.md) subobject. Its human-shaped source fields are `bool downloadComplete`, implicit alignment through `+0x07`, `unsigned long contentLength` at `+0x08`, and `unsigned long bytesDownloaded` at `+0x0c`; both counters remain four-byte fields in the 32-bit target layout, and BaseRequest source size is `0x0c`.
- `+0x10..+0x27`: the only derived data member, `std::string responseText`, using the observed 24-byte MSVC/Dinkumware SSO-15 representation with size at complete-object `+0x20` and capacity at `+0x24`.

The layout is not inferred from one decompiler view. RTTI records the derived class plus BaseRequest at PMD `4/-1/0`; raw constructor [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md), live catalog allocation in [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), raw destructor [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md), SSO assign/append helpers, and the HTTP worker's field accesses all agree on the same offsets, initialization order, total size, and string representation. The message-`10001` submit path and catalog worker consume the class as a payload; the submit helper and worker remain FileDownloader-owned methods rather than members of the payload class.

The class's one virtual slot is source-caused by its virtual destructor. Exact compiler data [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) contains hidden complete-object-locator pointer `0x0060d79c -> ??_R4CashShopRequest@@6B@` followed by vftable slot `0x0060d7a0 -> 0x0041b570`. [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) is the compiler-generated scalar deleting wrapper that restores the vtable, performs the ordinary string cleanup path, and optionally frees `this`; it is class-owned binary evidence, not a handwritten source body. The hidden RTTI pointer, vftable data, and scalar deleting wrapper must therefore be regenerated from the class declaration/destructor route rather than emitted as raw source objects or a manually reproduced thunk.

The formal source disposition is exact and intentionally split by channel. The H block declares `class CashShopRequest : public BaseRequest`, its constructor, inline virtual destructor, and only `std::string responseText`. The class CPP block is exactly `[[CHILDREN]]`, leaving constructor and other source-bearing definitions to their exact by-memory children and preventing duplicate method bodies. This preserves normal late-1990s/mid-2000s C++ source shape while maintaining the observed ABI. Completion/confidence remains `93/94`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JC`, and `EMITTER_UIDS:0000JC`; uncertainty is limited to original lexical spelling/access and historical physical file boundaries, not layout or runtime behavior.

Rejected historical assumptions are retained rather than erased. The former flattened declaration that placed `downloadComplete`, `contentLength`, and `bytesDownloaded` directly in `CashShopRequest` described complete-object offsets but not the original inheritance-aware source shape. The historical `state` spelling is superseded by the shared `downloadComplete` BaseRequest field. [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) remains a detailed historical alias with reconstruction path `NONE`; the class is not restored to a speculative standalone `NexusTK/cashshop/CashShopRequest.cpp` unit because the BaseRequest, CashShopVersionRequest, CashShopRequest, FileDownloader code, adjacent RTTI/vtables, and scalar-destructor wrappers form one coordinated FileDownloader source family. Likewise, stale generated CashShop ownership for the broad Socket send corridor, Thread wait/dispatch helpers, and MiscWorkThread auth-directory range remains correction/search provenance only. Final source must not introduce explicit padding members, raw RTTI/vtable objects, scalar deleting thunk code, decompiler labels, or the rejected large queue/result object model.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 93 | The class has an inheritance-aware formal H declaration, exact `0x28` layout, non-polymorphic [UID:00050F][BaseRequest](by-class/BaseRequest.md) subobject, `responseText` derived member, raw/inline constructor evidence, ordinary/scalar destructor routes, worker semantics, SSO helper behavior, and coordinated FileDownloader module route. Unrelated historical send/wait helpers remain documented as external ownership boundaries. |
| Confidence | 94 | Raw bytes, allocation size, RTTI PMDs, live inline construction, worker writes, both destructor forms, and assign/append helpers converge on the inherited layout. Confidence remains below source/PDB certainty because exact original lexical identifiers/access control and historical physical file boundaries are inferred. |
| Reconstructable | TRUE | The inheritance-aware class declaration is behavior/layout-compatible and emits through [UID:0000JC][FileDownloader](by-file/FileDownloader.md) at position `2`. |

## Evidence Map

| Evidence | What it supports | Boundary note |
| --- | --- | --- |
| [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) | Valid current file parent under `NexusTK/cashshop/`. | File page keeps generic queue/send split candidates explicit. |
| [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) | Parent-blank inventory over the raw constructor and raw non-deleting destructor children. | The exact child methods route here through the `CashShopRequest` class, but the `0000WH` container itself is non-emitting and unassigned. Downloader-submit helpers are documented in the FileDownloader/request-dispatch neighborhood instead. |
| [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) | Exact RTTI/vtable source-declared data for this class. | Split from the mixed CashShop/FileDownloader `.rdata` prefix in Batch255. |
| [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) | Queue/send API and send/status helper cluster. | Many callers are non-cash-shop features, so final API placement can still move. |
| [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) | Historical generated-owner/search provenance and Thread boundary evidence. | B003 2026-06-20 resolves the full range as [UID:0000OR][Thread](by-file/Thread.md) infrastructure: `WaitForQueueDrain`, `WaitForResult`, wait-handle helpers, worker dispatch, and queue-post helpers. Do not use it as CashShop-owned source. |
| [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) | Packet sender lifetime correction. | Lifetime owner is Socket; recovered `CashShopRequest*` types cannot be trusted alone. |
| [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) | Downloader singleton storage correction. | Lifetime owner is FileDownloader; request-submit helpers need explicit split review. |

## Responsibility

`CashShopRequest` is a class-centered cash-shop/request payload module with stale generated links to a broad Socket send funnel. Current source ownership no longer treats the packet send corridor as active CashShopRequest contents: [UID:0000DD][Socket](by-class/Socket.md) owns `QueueAndSendPacket`, adjacent Socket command helpers, raw command `14` / `QueueHandshakeBlock`, position/status send, friend-name-list sync send, and `GetConnectionStatus`, while [UID:0000OR][Thread](by-file/Thread.md) owns the base queue post primitive at `0x00596960`.

IDA MCP evidence from 2026-05-25 and the B006 pass show [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime writes are all Socket constructor/destructor-family writes, even though many packet builders pass that global into `QueueAndSendPacket`. A fresh 2026-06-04 pass still shows 489 xrefs to `0x0067a7ec`, dominated by broad packet-builder reads. A separate `0x0067a738` pass shows [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) lifetime writes are FileDownloader constructor/destructor-family writes, and the 2026-06-04 xrefs still show downloader/fitting-room request-submit paths reading that storage. Do not type `g_packetSender` as `CashShopRequest *`, `Thread *`, or final `void *`; use `Socket *` unless later header evidence proves a wrapper interface.

## Key Data

The class-specific request payload is exactly `0x28` bytes under the target 32-bit MSVC ABI:

| Offset | Size | First-draft declaration | Evidence-backed role |
| --- | ---: | --- | --- |
| `+0x00` | `4` | implicit vptr | `CashShopRequest` vtable `0x0060d7a0`. |
| `+0x04` | `1` | inherited `BaseRequest::downloadComplete` | Constructor clears it; catalog worker sets/tests completion. This is the first field of the non-polymorphic BaseRequest subobject at PMD `+4`. |
| `+0x05..+0x07` | `3` | implicit alignment | Aligns the first DWORD; no synthetic source member. |
| `+0x08` | `4` | inherited `BaseRequest::contentLength` | WinINet content-length result. |
| `+0x0c` | `4` | inherited `BaseRequest::bytesDownloaded` | Cumulative bytes read by the catalog worker. |
| `+0x10..+0x27` | `0x18` | `std::string responseText` | 24-byte MSVC/Dinkumware SSO-15 string with size at `+0x20` and capacity at `+0x24`. |

Historical generated notes describing a 240,208-byte request queue/result/semaphore object belong to the stale Socket send-corridor recovery, not this payload. Keep that rejected large-object interpretation as provenance only: `g_packetSender` is Socket-owned and generic wait/dispatch primitives are Thread-owned. The four submitted names and `public` access are behavior-compatible first-draft inferences; offsets, widths, order, and total size are direct binary facts.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) | `CashShopRequest::CashShopRequest()` | Initializes `downloadComplete`, `contentLength`, `bytesDownloaded`, and the embedded `responseText` SSO string; live `sub_41B200` duplicates the exact initialization for a `0x28` allocation. |
| [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md) | raw non-deleting destructor | Releases embedded string heap storage if not SSO and resets inline string state. |
| [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) | `SubmitItemRequest` / minimap submit helper | Allocates item/minimap-style request node and enqueues downloader message `10000`; final owner is provisional because callers pass `dword_67A738`. |
| [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) | `SubmitCashShopCatalogRequest` / catalog submit helper | Allocates a `0x28` `CashShopRequest` catalog payload, enqueues downloader message `10001`, and links it to the fitting room dialog as `m_activeCatalogRequest`; accepted payload fields are `downloadComplete`, `contentLength`, `bytesDownloaded`, and `responseText`/`catalogJson`. Final method owner is FileDownloader, but this row supplies the payload layout context for the `CashShopRequest` destructor wrappers. |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | `SubmitVersionRequest` | Allocates a version-request payload and enqueues downloader message `10002`; currently cross-linked to `CashShopVersionRequest` and FileDownloader. |
| [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) | compiler scalar deleting destructor | Vtable slot `0x0060d7a0 -> 0x0041b570`; the historical 2026-07-05 MCP pass using session `19917133` reconfirmed `sub_41B570` size `0x6b`, no direct code callers, embedded string cleanup, and optional scalar-delete `this` free. This is class-specific generated-binary ABI output routed through this class with a formal no-body comment, not a handwritten source method body. |
| `0x00453a30` | raw `SubmitNamedRequest` candidate | Raw unmodeled start that allocates a named request node and calls `0x00596960` from `0x00453a92`; no IDA function object or direct start xrefs exist in the current database. |
| `0x00574bb0` | historical `QueueAndSendPacket` CashShop alias | Exact page: [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Current source owner is [UID:0000DD][Socket](by-class/Socket.md); copies caller packet bytes, appends a scratch terminator, and posts command `8` consumed by `Socket::HandleSocketCommand`. |
| `0x00574d00` | historical `SendRawData` CashShop alias | Raw/provisional page: [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md). Current source role is retained Socket `QueueHandshakeBlock` / `QueuePacketTransformSeedBlock`; no function object, external xrefs, pointer refs, or direct rel32 route are known. |
| `0x00574d40` | historical `SendPositionUpdate` CashShop alias | Exact page: [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md). Treat as Socket-owned send-corridor provenance, not active CashShopRequest class content. |
| `0x00574e50` | historical `BuildAndSendFriendNameListSync` CashShop alias | Exact page: [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md). Treat as Socket-owned send-corridor provenance; former `BuildAndSendInventoryData` evidence points to friend-name-list opcode `0x77`, not item inventory. |
| `0x00575370` | historical `GetConnectionStatus` CashShop alias | Exact page: [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md). Current source owner is [UID:0000DD][Socket](by-class/Socket.md); returns `Socket::m_connectionStatus`. |
| `0x00596620` | historical `SubmitAndWait` alias for `Thread::WaitForQueueDrain()` | Stale generated CashShop alias only. B003 proves this queues message id `2` as a base Thread queue-drain barrier. |
| `0x00596760` | `Thread::WaitForResult(HANDLE)` | Thread-owned result-list helper; CashShop docs keep this row only for search/provenance because older generated output used CashShop names. |
| `0x00596960` | `Thread::DispatchRequest` | Live IDA confirms 22 direct callers, request-record enqueue work, and `ReleaseSemaphore`; source owner is [UID:0000OR][Thread](by-file/Thread.md), not CashShopRequest. |

## 2026-07-05 B001 Scalar Deleting Destructor Route

[UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) is class-specific scalar deleting destructor ABI output for this class. During the historical 2026-07-05 MCP pass, session `19917133` reconfirmed the target as `sub_41B570`, size `0x6b`, with the only direct incoming reference from the `CashShopRequest` vtable slot at `0x0060d7a0`; pointer search found no other VA/RVA route to `0x0041b570`. The slot itself is also referenced by the raw constructor write at `0x0041a5e8`, raw non-deleting destructor restore at `0x0041a613`, catalog request payload setup at `0x0041b22d`, and the wrapper's own vtable restore at `0x0041b576`.

The wrapper's body is compiler glue, not original handwritten NexusTK source. Ordinary cleanup semantics live on [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md); [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) owns the RTTI/vtable data; and [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) adds only the scalar-delete flag and optional `this` free path. Per `by-structure.md` line 263, the child stays `RECONSTRUCTABLE:TRUE` and emitted through this class as the source cause, but its formal C++ block contains only a no-body trace comment instead of an empty marker or a handwritten wrapper.

The earlier field/layout blocker is resolved enough for this wrapper route. [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) emits accepted source-facing catalog payload construction using `CashShopRequest *request = new CashShopRequest;` and names the request fields as `downloadComplete`, `contentLength`, `bytesDownloaded`, and `responseText`/`catalogJson`. The historical 2026-07-05 `decompile 0x0041b200` result from session `19917133` matched that route: `0x28` allocation, `CashShopRequest::vftable` store, zeroed `+0x04/+0x08/+0x0c` fields, SSO string initialization at `+0x10/+0x20/+0x24`, downloader message `10001`, and fitting-room handoff at `+0x7a8`.

## Live IDA Evidence

- 2026-06-04 live IDA MCP recheck used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA does not model `0x0041a5d0` or `0x0041a610` as functions, but the bytes decode as constructor/destructor-shaped raw starts; `0x0041a607-0x0041a610` is `0xcc` padding after the constructor child.
- IDA confirms exact modeled submit/destructor functions at `0x0041b180-0x0041b1f5`, `0x0041b200-0x0041b26d`, `0x0041b270-0x0041b2c9`, and `0x0041b570-0x0041b5db`. The submit helpers call `0x00596960`; the scalar deleting destructor is reached through the `0x0060d7a0` CashShopRequest vtable.
- 2026-06-12 A003 Batch255 live IDA MCP dword/xref scan confirms exact [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md): `0x0060d79c -> ??_R4CashShopRequest@@6B@`, `0x0060d7a0 -> sub_41B570`, four refs to the vtable slot, and the `0x0060d7a4` FileDownloader boundary.
- IDA still does not model `0x00453a30` or `0x00574d00` as functions. The raw `0x00574d00` start has no external start xrefs and no loaded dword references equal to `0x00574d00`; keep it provisional despite function-shaped bytes.
- IDA confirms `QueueAndSendPacket` at `0x00574bb0-0x00574c13` with 416 direct code xrefs, packet-buffer helper calls at `0x00516030`, `0x00516050`, and `0x00516220`, and queue dispatch through `0x00596960`.
- IDA confirms `SendPositionUpdate` at `0x00574d40-0x00574e44` with two callers, `BuildAndSendFriendNameListSync` at `0x00574e50-0x0057536b` with friend-list/map callers, and `GetConnectionStatus` at `0x00575370-0x00575377` with three callers.
- IDA confirms wait/dispatch helpers at `0x00596620-0x0059675e`, `0x00596760-0x005967c7`, and `0x00596960-0x005969b0`; the first two use `WaitForSingleObject`/`CloseHandle`, while `0x00596960` enqueues work and calls `ReleaseSemaphore`.
- Current global xrefs show `0x0067a7ec` has 489 references from broad packet-send call sites, `0x0067a738` has FileDownloader/fitting-room request-submit reads and writes, and `0x0066dee0` has three xrefs from the MapPane/friend-list upload paths.

## Ownership Notes

- Cash-shop/download/auth-specific payload creation should remain with this class.
- Downloader request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` should remain provisional until the FileDownloader singleton and payload class split is settled.
- `QueueAndSendPacket`, raw command `14`, `SendPositionUpdate`, `BuildAndSendFriendNameListSync`, `GetConnectionStatus`, and adjacent command helpers are now Socket-owned search/provenance links, not active CashShopRequest methods.
- `SendPositionUpdate`, `BuildAndSendFriendNameListSync`, and `GetConnectionStatus` are currently in the same send/status cluster, but their callers are reconnect/terminal/map/friend-list paths rather than cash-shop UI paths.
- `0x00596620-0x005969b0` and adjacent helper siblings should be treated as generic [UID:0000OR][Thread](by-file/Thread.md) queue/result/wait infrastructure. The current best names are `WaitForQueueDrain`, `WaitForResult`, `AddWaitHandle`, `RemoveLastWaitHandle`, `ThreadProc`, `OnMessage`, `OnMessageEx`, and `DispatchRequest`; the old `SubmitAndWait`/CashShop names are generated provenance only.
- Final packet transport and encryption belong to [UID:0000DD][Socket](by-class/Socket.md).
- Big-endian packet scalar helpers belong to [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), not this class.
- `0x00528290`, `0x00528310`, and raw `0x005283b0` are [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) request-submission wrappers, not `CashShopRequest` methods.
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime belongs to [UID:0000DD][Socket](by-class/Socket.md); do not use recovered `CashShopRequest*` global typing as final ownership evidence.

## 2026-07-12 B003 Layout And Source-Quality Resolution

- During the 2026-07-12 mandatory-session `e72f177b` evidence pass, IDA showed no modeled function or direct xref at raw constructor `0x0041a5d0`, but did show a unique 55-byte constructor signature and a live inline duplicate in `sub_41B200`. The live path allocates `0x28`, initializes the same vptr/fields/string, dispatches message `10001`, and stores the request in fitting-room state at `+0x7a8`; later session availability is not asserted.
- The vtable at `0x0060d7a0` has exactly four refs from raw construction, ordinary destruction, live inline construction, and scalar deleting destruction. RTTI names `CashShopRequest`; the one-slot vtable points to [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md).
- `FileDownloader::OnMessage` sends message `10001` to the catalog worker. The worker stores content length at `+0x08`, cumulative bytes at `+0x0c`, assigns/appends bytes through `+0x10`, and sets `+0x04` on completion.
- [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md), the scalar wrapper, assign helper `0x0041b8b0`, and append helper `0x0041b740` prove a 16-byte inline/pointer union, length/capacity DWORDs, SSO threshold `0x10`, and empty capacity `0x0f`. The embedded member is therefore a 24-byte `std::string`.
- In the 2026-07-12 B003 session, no IDA `CashShopRequest` or `basic_string` UDT was recovered. Preserve that as dated history rather than current state: the 2026-07-28 B006 refresh below finds exact-size `CashShopRequest` and `StdString24` UDTs. Exact original names and access remain not source-proven; `downloadComplete`, `contentLength`, `bytesDownloaded`, `responseText`, and `public` remain the highest-probability human-shaped declarations supported by the reconstructed consumers.
- Historical pre-2026-08-03 disposition: preserve canonical owner and emitter [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). That one-class move was correctly rejected at the time because identically colocated `CashShopVersionRequest` would have remained behind. The coordinated four-class audit now supplies the missing evidence and routes [UID:00050F][BaseRequest](by-class/BaseRequest.md), CashShopVersionRequest, CashShopRequest, and FileDownloader together through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
- Preserve [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) as non-emitting inventory and preserve UID0002CI, UID0002CM, UID0002CK, and UID0003FS as separate lifecycle/runtime/data support children without score or ownership changes.

## 2026-07-28 B006 Current IDA Type Readback

- This is a bounded support sync for [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md). The executed B003 class declaration, layout analysis, ownership, source route, score `89/91`, and emitted C++ remain authoritative and unchanged.
- Live MCP session `5a570ede` reports `CashShopRequest`, ordinal `448`, at exactly `40` / `0x28` bytes with no surfaced base relationship. The current members are `vftable` (`void *`, `+0x00`, size `4`), `downloadComplete` (`bool`, `+0x04`, size `1`), `alignment_05` (`unsigned __int8[3]`, `+0x05`, size `3`), `contentLength` (`unsigned int`, `+0x08`, size `4`), `bytesDownloaded` (`unsigned int`, `+0x0c`, size `4`), and `responseText` (`unsigned __int8[24]`, `+0x10`, size `24`). This exactly matches the accepted class size, alignment, field order, and widths.
- The same type catalog contains `StdString24`, ordinal `880`, at exactly `24` / `0x18` bytes with `_msvcStringStorage` (`unsigned __int8[24]`, `+0x00`, size `24`). Combined with the constructor, both destructors, assign/append helpers, and worker behavior, this independently corroborates the source declaration `std::string responseText` rather than making the raw array a source-facing field type.
- IDA UDT disposition is exact `NO_CHANGE_VERIFIED`. The pre-Gate2B reason was that read-only type interfaces did not expose the UDT-level or six member-level comment prestates, so a whole-UDT replacement could not guarantee comment preservation. Supervisor Gate2B therefore performed no UDT/member mutation and read back `CashShopRequest` at exact size `0x28` with all six members unchanged and `StdString24` at exact size `0x18` unchanged.
- Gate2B authority: supervisor audit and IDA implementation catalog entry `0340` record the verified no-change result in active IDB session `5a570ede`. Backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B006-UID0002CH-20260728_1641.i64` is SHA-256 `6237D5D3448850A7CCA1AA636600BAE1C561BF17E58E0B7FE4BC72B8B27192BD`, size `143189451`; saved poststate is SHA-256 `990FFCBF017C1DA0F614664432D0E3560E9683A9D7318AE486A972E33FD094D2`, the same size, last write `2026-07-28T16:38:59.8339104-04:00`. No further IDA type action is required by UID0002CH.
- The raw `alignment_05` member is IDA's explicit physical padding representation, not a source member. The formal class continues to rely on compiler alignment after `bool downloadComplete` and must not emit a synthetic alignment field.
- Current UID0002CH score is `92/93`; that child retains its exact initializer-list constructor and blank method-level formal H. The class remains `89/91` because original member spelling/access and coordinated original translation-unit placement remain broader class-level inference caps.

## 2026-08-03 B008 BaseRequest And Module Consolidation

- Live RTTI records resolve the earlier flattened source model. `CashShopRequest` has a two-entry hierarchy containing itself at PMD `0/-1/0` and non-polymorphic `BaseRequest` at PMD `4/-1/0`; the derived object remains exactly `0x28` bytes.
- [UID:00050F][BaseRequest](by-class/BaseRequest.md) owns `downloadComplete`, `contentLength`, and `bytesDownloaded` in its `0x0c` source layout. Within the polymorphic derived object those inherited fields occupy `+0x04`, `+0x08`, and `+0x0c`; `CashShopRequest` contributes only the `0x18`-byte `std::string responseText` at `+0x10`.
- The formal declaration is therefore inheritance-aware rather than a flattened reverse-engineered member list. The exact H channel declares `class CashShopRequest : public BaseRequest`, its constructor, inline virtual destructor, and `responseText`; the CPP channel is exactly `[[CHILDREN]]` so exact method pages remain the sole body emitters.
- Physical clustering resolves the prior translation-unit question only as a coordinated family decision: BaseRequest declaration/constructor evidence, CashShopVersionRequest, CashShopRequest, FileDownloader code, adjacent RTTI/vtables, and scalar-destructor wrappers are represented together by [UID:0000JC][FileDownloader](by-file/FileDownloader.md). The old standalone [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) route remains preserved as historical documentation, not an active output path.
- The generated flattened class body that placed `downloadComplete`, `contentLength`, and `bytesDownloaded` directly in `CashShopRequest` was valid physical-layout evidence but invalid final source shape. It is retained in the older change history below and superseded by the BaseRequest-aware formal H/CPP split.
- This consolidation raises the page from `89/91` to `93/94`. It remains below `95/95` because original lexical spelling/access and the exact historical file split cannot be recovered from symbols, while runtime layout, inheritance, source route, and emitted first-draft source are now resolved.

## Open Questions

- Exact original spelling/access for the four submitted fields remains unavailable without source headers/PDB. This caps confidence but no longer blocks the accepted first-draft class declaration.
- `CashShopRequest` class identity is supported by RTTI/vtable/lifecycle evidence. The coordinated reconstruction route is now [UID:0000JC][FileDownloader](by-file/FileDownloader.md); exact historical physical-file spelling remains inferential rather than a blocker.
- Future header evidence could still reveal a narrow Socket sender/request interface wrapper, but current documentation should route the packet send corridor through [UID:0000DD][Socket](by-class/Socket.md), not CashShopRequest.
- Keep historical search links for old `CashShopRequestWaitDispatch` generated labels while ensuring source ownership remains [UID:0000OR][Thread](by-file/Thread.md).
- Resolved for current source placement: `0x0041b180`, `0x0041b200`, and `0x0041b270` are FileDownloader receiver/request-submission methods. CashShopRequest remains the message-`10001` payload class and does not absorb those methods.
- Confirm ownership of globals `g_cashShopRequestPending`, `g_isHighResMode`, `g_pApplication`, and `g_pConfig`; current file ownership should not be treated as final.
- Review the final source-facing owner for `BuildAndSendFriendNameListSync`; current evidence favors social/account friend-name-list opcode `0x77` upload semantics, with [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled` as the server-controlled upload flag. The former `BuildAndSendInventoryData` name should remain only as a searchable generated alias.

## Cross-References

- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:00050F][BaseRequest](by-class/BaseRequest.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
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
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-08-03 B008 UID0003FS inheritance/module implementation:
  - Changed `89/91` to `93/94`, owner/emitter from historical alias [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) to coordinated module [UID:0000JC][FileDownloader](by-file/FileDownloader.md), and emitter position from blank to `2`.
  - Replaced the flattened CPP declaration with exact `[[CHILDREN]]` and added the inheritance-aware H declaration `CashShopRequest : public BaseRequest` with only `responseText` as derived storage.
  - Preserved the older flattened-layout and standalone-file conclusions as dated history while recording why RTTI PMD `+4`, the three shared base fields, class sizes, constructor order, and physical clustering now support [UID:00050F][BaseRequest](by-class/BaseRequest.md) and the FileDownloader module route.

- 2026-07-28 B006 post-IDA type reconciliation:
  - Updated the current UDT disposition from pending `NO_CHANGE` rationale to supervisor-verified `NO_CHANGE_VERIFIED` under catalog entry `0340`, with exact backup/save identities and persisted size/member readback.
  - Class score, owner/emitter, formal declaration, source route, analysis-only padding distinction, and executed B003 authority remain unchanged. No second UDT recommendation was created.
- 2026-07-28 B006 bounded type-support sync:
  - Scores, owner/emitter, class declaration, and source route remain unchanged at `89/91`, [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md), and the accepted B003 C++.
  - Added the current exact `CashShopRequest` ordinal/member inventory, exact-size `StdString24` corroboration, and deterministic IDA `NO_CHANGE` disposition. Historicalized the B003-era no-UDT statement without deleting it.
  - No IDA mutation, coverage change, helper rewrite, aggregate rewrite, or duplicate constructor implementation occurred.
- 2026-07-12 B003 accepted UID0002CH class support callback:
  - Before: `85/88`, blank class C++, generic state/pending-result/semaphore constructor wording, and unresolved field/layout/source blockers.
  - Changed to: `89/91`; inserted the accepted class declaration with constructor, virtual destructor, `downloadComplete`, `contentLength`, `bytesDownloaded`, `responseText`, and `[[CHILDREN]]`; canonical owner/emitter and optional position unchanged.
  - Evidence: the 2026-07-12 mandatory-session `e72f177b` pass proved the `0x28` allocation/layout, four vtable refs, live inline construction and message `10001` route, worker field semantics, ordinary/scalar destruction, and 24-byte SSO assign/append behavior. Exact name/access and original-TU limits remain explicit.
- 2026-06-20 B003 Thread dispatch helper support update:
  - Removed [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) from current CashShop-owned range wording and kept it only as stale generated-owner/search provenance. Updated the helper rows to `Thread::WaitForQueueDrain`, `Thread::WaitForResult`, and `Thread::DispatchRequest`, all owned by [UID:0000OR][Thread](by-file/Thread.md).
- 2026-06-20 B006 Socket support sync:
  - Moved the former Socket send-corridor rows out of active CashShopRequest method ownership and marked `QueueAndSendPacket`, raw command `14`, `SendPositionUpdate`, `BuildAndSendFriendNameListSync`, `GetConnectionStatus`, and adjacent command helpers as Socket-owned search/provenance links.
  - Evidence: B006 report reconfirmed `g_packetSender` as `Socket *`, rejected generated CashShopRequest aliases, and tied command helper consumers to `Socket::HandleSocketCommand`.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: send-queue/friend-list caveats referenced the upload flag only as historical `byte_66DEE0`.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag to map/friend-list upload paths rather than cash-shop inventory.
- 2026-06-04: Raised completion/confidence from `72/80` to `82/86`; reconstructable and parent attachment remain unchanged.
  - Before: the page had useful child links and ownership caveats, but still used stale provenance wording and did not record fresh IDA evidence for the raw starts, caller counts, global xrefs, and queue-dispatch boundary.
  - After: live IDA evidence records the binary identity, modeled and raw method starts, submit helper callers, `QueueAndSendPacket` reachability, wait/dispatch helper ranges, `g_packetSender`/`g_pCashShopRequest`/friend-upload flag xrefs, and the lack of loaded references for raw `0x00574d00`.
  - Reasoning: the class is better documented as reconstructable project code and can leave the low queue, but final C++ remains blank because raw starts, downloader-submit ownership, packet-sender typing, and generic thread-queue placement are still below the 95/95 bar.
- 2026-06-12 A003 Batch255 vtable split:
  - Before: `82/86`; the class had vtable evidence only through broad read-only-data references.
  - Changed to: `85/88`; exact [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) now carries the RTTI/vtable dwords and routes here.
  - Summary/evidence: live IDA MCP confirmed the RTTI pointer, scalar deleting destructor slot, four vtable refs from constructor/destructor/catalog submit/destructor wrapper sites, and the neighboring `FileDownloader` boundary. The file parent is raised to the strict gate in the same pass.
- Before: the early `0x0041a5d0` cluster was represented by a broad aggregate range and address-only rows for constructor, submit helpers, and scalar deleting destructor.
- After: the class method inventory points to exact `by-memory` pages for the raw constructor/destructor body, the three downloader submit helpers, and the scalar deleting destructor.
- Summary/evidence: IDA MCP and raw disassembly split the cluster into exact child ranges; the submit helpers remain provisional because live callers pass FileDownloader-lifetime `dword_67A738`.
- Current update: raised from `55/72` to `72/80`, marked reconstructable, and attached to [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). C++ remains blank because final field/helper names and source split decisions are not strong enough.
- 2026-06-12 B001 memory-range repair:
  - Before: [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) was a broad `0x0041a5d0-0x0041b5da` reconstructable aggregate parented to this class, even though it crossed FileDownloader and helper regions.
  - Changed to: the `0000WH` page is now a parent-blank, non-emitting inventory over only the exact raw constructor/destructor children and padding; [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) remains this class's direct exact child outside that narrowed inventory.
  - Summary/evidence: B001's IDA-backed audit confirmed raw start boundaries at `0x0041a5d0` and `0x0041a610`, the FileDownloader successor boundary at `0x0041a670`, and the separate modeled scalar deleting destructor at `0x0041b570-0x0041b5db`.
