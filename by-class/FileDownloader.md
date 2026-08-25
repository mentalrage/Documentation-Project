*** UID:00004W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FileDownloader : public Thread
{
public:
    FileDownloader();
    virtual ~FileDownloader();

    virtual void OnMessage(int messageId, void *payload, int aux);

    bool SubmitMinimapRequest(int mapId,
                              const wchar_t *mapCode,
                              const wchar_t *outputPath);
    void SubmitCashShopCatalogRequest();
    bool SubmitCashShopVersionRequest();
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FileDownloader

## Status

- Confidence: very strong for methods, message dispatch, submit-helper callsites, singleton lifetime, primary worker payload layouts, and the coordinated four-class module; high for inferred source-facing declaration spelling.
- Current source module and autogen parent: [UID:0000JC][FileDownloader](by-file/FileDownloader.md), emitter position `3`, following [UID:00050F][BaseRequest](by-class/BaseRequest.md), [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md), and [UID:00001H][CashShopRequest](by-class/CashShopRequest.md).
- Evidence basis: live IDA MCP lookup, caller/callee, decompile, xref, byte-padding, and exact vtable-dword checks through 2026-06-23.

## Role

Thread-backed WinINet download dispatcher for small file/update requests. It is separate from [UID:0000NS][Socket](by-file/Socket.md), which owns the encrypted game transport.

## Item Summary

`FileDownloader` is the final class declaration in the coordinated `FileDownloader.h/.cpp` source module. The header begins with non-polymorphic [UID:00050F][BaseRequest](by-class/BaseRequest.md), then declares the two BaseRequest-derived payloads [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md) and [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), and finally declares this Thread-derived dispatcher and closes the include guard. This page emits only the exact H declaration. Its CPP channel is intentionally blank because constructor, destructor, dispatcher, submitters, and workers already emit through exact by-memory children attached to the FileDownloader file root; an empty class-level `[[CHILDREN]]` token generated the invalid literal `[[No Children Attached]]` even though those method bodies were present later in the same source file. Compiler-generated RTTI, vtables, EH cleanup, and scalar-deleting wrappers remain documented binary support rather than handwritten bodies.

## Class CPP Attachment Disposition

The class page must not emit a class-level CPP attachment token. Current source generation places the exact FileDownloader method children through [UID:0000JC][FileDownloader](by-file/FileDownloader.md) after the class declaration route, so the token has no attached class-channel children and materializes as invalid source text. Removing only that token preserves every generated constructor, destructor, dispatcher, submitter, and worker body while eliminating the raw marker; it does not move ownership, duplicate a method, or turn this class page into a method-body emitter.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0041a670-0x0041a6e5` | `FileDownloader::FileDownloader` | Constructs `Thread(5)`, writes `dword_67A738 = this` / `g_pCashShopRequest`, installs vtable, starts worker. |
| `0x0041a6f0-0x0041a741` | `FileDownloader::~FileDownloader` | Stops thread, clears `dword_67A738`, destroys base thread. |
| [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) | `ClearFileDownloaderRequestGlobal` | Constructor EH/unwind helper that clears `dword_67A738`; reached from the unwind block at `0x005f670e`. |
| `0x0041b110-0x0041b180` | `FileDownloader::OnMessage` | Dispatches message IDs `10000`, `10001`, and `10002`; otherwise forwards to `Thread::OnMessage`. |
| [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) | `SubmitMinimapRequest` / downloader queue submit helper | Allocates a `0x238` `FileDownloaderMinimapRequest`, copies `mapCode[0x10]` and `outputPath[0x104]`, stores `mapId`, and posts downloader message `10000`. |
| [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) | `SubmitCashShopCatalogRequest` / downloader queue submit helper | Allocates a `CashShopRequest` catalog payload, posts downloader message `10001`, and writes `FittingRoomDialog::m_activeCatalogRequest` at `+0x7a8` when the dialog singleton exists. |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | `SubmitCashShopVersionRequest` / downloader queue submit helper | Allocates a `CashShopVersionRequest` payload or posts a null fallback, then posts downloader message `10002`. |
| [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) | `FileDownloader::ScalarDeletingDestructor` | Destructor wrapper that clears `dword_67A738`, destroys the base thread, and optionally calls `operator delete`. |
| `0x005965e0-0x005965f3` | `FileDownloader::StartThread` | Calls virtual slot 5, then `ResumeThread`; ownership may later move to `Thread`. |

## Message Dispatch

`FileDownloader::OnMessage` currently maps:

- `10000`: `DownloadMinimapFile(messageData)`, then raw delete of the `FileDownloaderMinimapRequest`.
- `10001`: `DownloadCashShopCatalog(messageData)`, with conditional self-delete based on `FittingRoomDialog::m_activeCatalogRequest`.
- `10002`: `DownloadCashShopVersion(messageData)`, then virtual destroy with flag `1`.

See [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md).

## 2026-06-23 B004 Aggregate Reclassification

[UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) is now a non-emitting exact-child inventory. The FileDownloader class remains the direct source route for the exact dispatcher/worker/submit children, but it is no longer the canonical owner of the aggregate page itself.

Current MCP session `80de0a67` confirms the class-route facts:

- `FileDownloader::OnMessage` is `sub_41B110`, size `0x70`, reached through vtable slot `0x0060d7d4`, whose value is `0x0041b110`.
- The dispatcher calls `DownloadCashShopVersion` at `0x0041b13c -> 0x0041aa00` for message `10002` and `DownloadCashShopCatalog` at `0x0041b156 -> 0x0041ae20` for message `10001`; the minimap branch calls `0x0041a750` for message `10000`.
- The submit helpers remain FileDownloader receiver routes: `0x0041b180` is called from `0x00451d18`, `0x0041b200` from `0x0041cd0f`, and `0x0041b270` from `0x0041c21b`; caller windows load/pass `0x0067a738`, documented as `FileDownloader *g_pFileDownloader` with stale physical `g_pCashShopRequest` aliases.
- The request/payload facts remain support context, not aggregate ownership proof: version request payload size `0x10`, catalog request payload size `0x28`, `CashShopVersionRequest` vtable write at `0x0041b2a4`, `CashShopRequest` vtable write at `0x0041b22d`, `m_itemShopVersion` at `g_pFittingRoomDialog + 0x790`, and `m_activeCatalogRequest` at `+0x7a8`.
- The PE route scan corroborates MCP: one direct worker call to each cash-shop worker, one direct caller for each submit helper, one VA dword for the `OnMessage` vtable slot, and no VA/RVA/raw-offset pointer route that would make [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) a standalone source declaration.

Do not add class-level or aggregate C++ for [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md). Generated `FileDownloader.cpp` already emits the source-shaped worker bodies through [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md), [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md), and [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md); [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) has no single source method and is intentionally `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitter.

## Child Evidence Matrix

| Child / address | Evidence status |
| --- | --- |
| `0x0041a670-0x0041a6e5` constructor | Constructs worker thread state, writes `dword_67A738`, installs the FileDownloader vtable, and starts the worker. |
| `0x0041a6f0-0x0041a741` destructor | Stops the worker, clears `dword_67A738`, and destroys base thread state. |
| `0x0041b110-0x0041b180` `OnMessage` | Exact dispatcher for messages `10000`, `10001`, and `10002`, with default fallback to the base thread message path. |
| [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) | Live caller at `0x00451d18` passes `dword_67A738` and enqueues downloader message `10000`; final source name remains provisional. |
| [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) | Live caller at `0x0041cd0f` passes `dword_67A738` and enqueues downloader message `10001`; final source name remains provisional. |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | Live caller at `0x0041c21b` passes `dword_67A738` and enqueues downloader message `10002`; final source name remains provisional. |
| [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) | Constructor-unwind helper clearing `dword_67A738`. |
| [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) | Destructor wrapper with global clear, base thread destruction, and optional delete. |
| [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md) | Exact RTTI/vtable data with destructor slot, inherited worker/thread slots, and `OnMessage` override slot. |

## Source-Structure Decision

Keep this class with [UID:0000JC][FileDownloader](by-file/FileDownloader.md) under `NexusTK/network/`. The class owns HTTP/WinINet download dispatch and the `dword_67A738` downloader/request singleton lifetime. It should stay separate from [UID:0000NS][Socket](by-file/Socket.md), because socket transport owns encrypted game protocol framing rather than worker-thread HTTP requests.

The coordinated 2026-08-03 source-placement audit expands this source module without changing that ownership boundary. Code from `0x0041a670-0x0041b69f` clusters FileDownloader construction/destruction, three HTTP workers, `OnMessage`, and three request submitters. Adjacent `.rdata` from `0x0060d794-0x0060d7e0` orders CashShopVersionRequest, CashShopRequest, and FileDownloader RTTI/vtable records, while scalar-destructor entries at `0x0041b570`, `0x0041b5e0`, and `0x0041b610` preserve the same class adjacency. The shared BaseRequest PMD `+4`, payload sizes, and initializer order supply the missing header-level relationship. Together these facts support one human-shaped `FileDownloader.h/.cpp` family rather than separate generated `cashshop` translation units.

B001 2026-06-18 source-quality pass resolves the primary worker-helper route: [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) `DownloadMinimapFile`, [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) `DownloadCashShopVersion`, and [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md) `DownloadCashShopCatalog` are FileDownloader-local static worker helpers emitted through [UID:0000JC][FileDownloader](by-file/FileDownloader.md). MiniMap, CashShopVersionRequest, and FittingRoom remain payload/state/feature-context owners and do not emit the HTTP worker bodies.

## 2026-07-01 B008 Class Declaration And Empty-Emitter Repair

B008's accepted empty-emitter family report made this class declaration first-draft source-ready and kept method bodies on exact children. In the accepted 2026-07-01 intermediate revision, the formal C++ block emitted the class declaration and `[[CHILDREN]]`; that implementation fact is retained as history rather than current source state. The current page emits the declaration only through formal H and intentionally leaves class-level CPP blank because the former empty `[[CHILDREN]]` token produced invalid output while the constructor, destructor, `OnMessage`, and submit-helper method bodies already route through the FileDownloader file root.

Exact source-bearing method children now route through this class and emit into [UID:0000JC][FileDownloader](by-file/FileDownloader.md):

- [UID:0002TP][0x0041a670-0x0041a6e5.FileDownloaderConstructor](by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md): `FileDownloader::FileDownloader`, base `Thread(5)`, singleton publish, worker start.
- [UID:0002TQ][0x0041a6f0-0x0041a741.FileDownloaderDestructor](by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md): `FileDownloader::~FileDownloader`, worker stop, singleton clear.
- [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md): virtual message dispatcher for `10000`, `10001`, and `10002`.
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md): minimap request submission, `0x238` payload, `mapCode[0x10]`, `outputPath[0x104]`.
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md): catalog request submission, `0x28` `CashShopRequest`, `m_activeCatalogRequest +0x7a8`.
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md): version request submission, `0x10` `CashShopVersionRequest`, null-payload fallback.

[UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) is constructor EH/unwind cleanup and [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) is compiler scalar-deleting destructor support. Source should express the ordinary constructor and virtual destructor; the compiler regenerates those support shapes.

`StartThread`, `StopThread`, `DispatchRequest`, and `Thread::OnMessage` are source-facing inferred names for inherited thread helper behavior, not recovered symbols. That unresolved final spelling caps the class below final audit quality but no longer blocks formal first-draft C++ emission.

## 2026-08-03 B008 Header And Four-Class Module Consolidation

- The 2026-07-01 formal CPP declaration and the later intermediate CPP containing exactly `[[CHILDREN]]` are preserved below as historical implementation evidence; neither is the active source channel. Declarations belong in formal H, current class-level CPP is intentionally blank, and exact method definitions emit through the FileDownloader file root.
- The exact H declaration keeps the established Thread inheritance and method surface, then closes `NEXUSTK_NETWORK_FILEDOWNLOADER_H` with `#endif`. [UID:00050F][BaseRequest](by-class/BaseRequest.md) opens that guard and includes `<string>` plus `Thread.h`; request classes occupy positions `1` and `2`; FileDownloader remains position `3`.
- The coordinated layout avoids reverse-engineered duplication. Shared request state is declared once on BaseRequest, CashShopVersionRequest adds no fields, CashShopRequest adds only `responseText`, and FileDownloader owns queue/worker behavior. Exact method bodies continue to emit only from existing by-memory children.
- Historical standalone CashShopRequest and CashShopVersionRequest source pages remain detailed aliases with path `NONE`, preserving old evidence without generating duplicate translation units.

## IDA MCP Evidence

- `lookup_funcs` confirms `0x0041b110` size `0x70` and `0x005965e0` size `0x13`.
- `callees` for `0x0041b110` list the three download helpers: `0x0041a750`, `0x0041aa00`, and `0x0041ae20`.
- `callers` for `0x005965e0` include `0x0041a670`, `0x00453910`, `0x0046ff50`, `0x004f5fb0`, and `0x005281b0`, so the current `FileDownloader` owner is broader than the function body itself proves.
- `py_eval` xrefs for `0x0067a738` on 2026-06-04 found 9 refs and 5 direct writes. The writes are `FileDownloader::FileDownloader`, `FileDownloader::~FileDownloader`, [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md), and the scalar deleting destructor.
- Decompilation and call-site windows show `dword_67A738` passed into request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270`, which enqueue downloader messages `10000`, `10001`, and `10002`.
- Byte checks confirm `0xcc` alignment gaps around the FileDownloader child functions, including `0x0041b1f5-0x0041b200`, `0x0041b26d-0x0041b270`, `0x0041b2c9-0x0041b2d0`, and `0x0041b69f-0x0041b6a0`.
- 2026-06-23 B004 current-session recheck used MCP database `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, executable SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. It reconfirmed [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) child starts/sizes (`0x0041aa00` size `0x41c`, `0x0041ae20` size `0x2ec`, `0x0041b110` size `0x70`, `0x0041b180` size `0x75`, `0x0041b200` size `0x6d`, `0x0041b270` size `0x59`), padding fences, request IDs `10000`/`10001`/`10002`, and the FileDownloader receiver route for exact children while rejecting class ownership of the aggregate inventory itself.
- 2026-06-12 A003 Batch255 live IDA MCP dword/xref scan confirms exact [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md): `0x0060d7a4 -> ??_R4FileDownloader@@6B@`, `0x0060d7a8 -> sub_41B610`, inherited worker/thread slots through `0x0060d7dc`, `0x0060d7d4 -> sub_41B110`, three refs to the vtable slot, and the `0x0060d7e0` `szAgent` boundary.

## Boundary Cautions

- The class writes to `0x0067a738`, best source-facing name `g_pFileDownloader` (`FileDownloader*`) or `g_pDownloadDispatcher` if a later header proves a facade name. The old `g_pCashShopRequest` name is retained only as a historical/generated alias for this address; it should not type the storage as a `CashShopRequest*`.
- Some earlier recovered aliases use `g_pCashShopRequest` for packet-send paths that IDA proves read [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`. Do not conflate those globals during source ownership cleanup.
- The `0x0041b180`, `0x0041b200`, and `0x0041b270` request submission helpers remain emitted with this dispatcher for now. Payload type declarations may still be shared with cash-shop/fitting-room headers, but the live receiver and queue-post path are FileDownloader.
- `StartThread` should not be used as proof that browser or misc worker thread construction belongs in `FileDownloader.cpp`; it is a shared worker launch helper in the current model.

## Score Rationale

- Completion is `93` because the class has a coordinated file parent, reconstructable disposition, exact formal H declaration and CPP child route, four-class source inventory, child evidence matrix, attached method pages, exact child/padding boundaries, exact vtable child [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md), resolved primary worker names, and BaseRequest-aware payload layouts.
- Confidence is `94` because constructor/destructor/global lifetime, `OnMessage` dispatch, message constants, live submit-helper callers, request queue posting, adjacent code/RTTI/scalar-destructor clustering, exact vtable slot maps, PMD hierarchy, and worker behavior all agree on FileDownloader as the dispatcher and module owner.
- Confidence remains below `95/95` because inherited `Thread` helper spelling and exact original declaration/header style remain high-probability inference rather than source/PDB fact.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:00050F][BaseRequest](by-class/BaseRequest.md)
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md)
- [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-08-03 B008 UID0003FS four-class module implementation:
  - Changed `89/91` to `93/94` while preserving owner/emitter [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and position `3`.
  - Moved the accepted FileDownloader declaration from formal CPP to exact formal H, added the coordinated include-guard close, and, in that intermediate revision, reduced formal CPP to exact `[[CHILDREN]]` so definitions remained child-owned. A later correction intentionally blanked class-level CPP after the empty token generated invalid literal output; exact method definitions continue to emit through the FileDownloader file root.
  - Preserved every prior method/worker/aggregate investigation and added BaseRequest/request class order, code/vtable/scalar-destructor clustering, source-placement rationale, and the historical disposition of separate cash-shop file routes.

- 2026-06-02 documentation pass:
  - What existed before: the page had method inventory and IDA evidence but remained unparented and unmarked for reconstruction.
  - What it was changed to: raised `65/80` to `72/84`, marked reconstructable, parented to [UID:0000JC][FileDownloader](by-file/FileDownloader.md), and added child evidence/source-structure rationale.
  - Summary/evidence: constructor/destructor writes to `dword_67A738`, exact `OnMessage` dispatch, downloader message constants, submit helpers, and scalar deleting destructor support the class role; shared-thread and request-payload ownership caveats remain open.
- Before: several FileDownloader-adjacent helpers were listed by address only or only through the aggregate dispatch page.
- After: the class method inventory links exact pages for the constructor-unwind global clear helper, submit helpers, and scalar deleting destructor.
- Summary/evidence: IDA MCP confirmed the destructor boundary on 2026-05-30 and previous decompilation/xref evidence tied the submit helpers and `dword_67A738` lifetime to the FileDownloader dispatch path.
- 2026-06-04 live IDA evidence pass:
  - What existed before: `COMPLETION:72`, `CONFIDENCE:84`, stale non-IDA provenance, and submit helpers remained caveated without parent attachment metadata on their child pages.
  - What it was changed to: raised to `COMPLETION:84`, `CONFIDENCE:88`, replaced stale provenance with live IDA evidence, and documented the submit helpers as attached downloader queue helpers with provisional final source names.
  - Summary/evidence: live IDA decompilation confirms constructor/destructor/global writes, exact `OnMessage` dispatch, `sub_596960` queue posting, direct caller windows passing `dword_67A738` to `0x0041b180`, `0x0041b200`, and `0x0041b270`, and padding boundaries. C++ remains blank because `StartThread`, helper names, and payload/source split remain below the 95/95 gate.
- 2026-06-12 A003 Batch255 vtable split:
  - Before: `84/88`; the class was just below the strict parent completion gate for a class-owned vtable child.
  - Changed to: `85/89`; exact [UID:0003FT][0x0060d7a4-0x0060d7e0.FileDownloaderVtableData](by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md) now carries the RTTI/vtable dwords and routes here.
  - Summary/evidence: live IDA MCP confirmed the FileDownloader RTTI pointer, destructor slot, inherited worker/thread slots, `OnMessage` override slot, three vtable refs from constructor/destructor wrappers, and the `szAgent` boundary.
- 2026-06-18 B001 FileDownloader download-helper source-quality pass:
  - Changed from `85/89` to `86/90`.
  - Summary/evidence: incorporated B001's helper-cluster report for [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md)/[UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md)/[UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md), including the `g_pFileDownloader` source-facing singleton direction, request payload layouts, direct dispatcher route, rejected feature-emitter alternatives, and first-draft worker C++ support. Full class declaration remains blank pending a dedicated declaration pass.
- 2026-06-23 B004 [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) source-quality reclassification:
  - Score remains `86/90` for this class page; [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) changed to a `88/90` non-emitting exact-child inventory with no canonical owner or aggregate emitter.
  - Summary/evidence: current MCP/PE evidence keeps the FileDownloader class route for exact worker/dispatcher/submit children, but the aggregate range itself has no class method or source declaration. The class page therefore preserves child routing and rejects FileDownloader as canonical owner of the [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) aggregate.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `86/90` to `89/91`; set `EMITTER_POSITION_OPTIONAL:3`; populated formal class declaration C++ with `[[CHILDREN]]`.
  - Summary/evidence: the accepted B008 report resolves the class/method empty markers by placing source-bearing bodies on exact by-memory children, while this class page emits only the declaration and child route. Vtable bytes and scalar-deleting wrapper mechanics remain generated-binary support, not hand-authored class bodies.
