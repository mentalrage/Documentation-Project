*** UID:0000QH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FileDownloader *g_pFileDownloader;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pFileDownloader (stale filename alias: g_pCashShopRequest)

## Status

- Confidence: very strong for address, FileDownloader lifetime, writer/read xrefs, neighboring-global boundaries, saved lifecycle helper labels, and best current source-facing type/name direction.
- Address: `0x0067a738`
- IDA name: `dword_67A738`
- Working type hypothesis in older notes: `CashShopRequest*`; B001 2026-06-18 rejects that as the primary source type. Best current declaration is `FileDownloader *g_pFileDownloader`, with `g_pDownloadDispatcher` retained only as an alternate facade-name caveat.
- Current observed writer: `FileDownloader::FileDownloader`
- Proposed owner: [UID:0000JC][FileDownloader](by-file/FileDownloader.md) / download-request dispatcher, with stale `g_pCashShopRequest` retained only as historical/generated alias text.
- Primary memory doc: [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)

## Observed Evidence

IDA decompilation of `FileDownloader::FileDownloader` writes this storage, and `FileDownloader` teardown clears the pointer. Live IDA still leaves the storage named `dword_67A738`; C001 dry-run verified that a `g_pFileDownloader` rename would technically succeed, but the rename was skipped because the final source-facing global name/type is still unresolved. This conflicts with the narrow `CashShopRequest* g_pCashShopRequest` declaration if that type is interpreted as the complete object type.

B001 2026-06-18 source-quality reanalysis resolves the primary type/name direction: keep the current filename as historical for now, but document the storage as `FileDownloader *g_pFileDownloader` / download-dispatcher singleton state. The actual `CashShopRequest` catalog payload is a separate `0x28` vtable object allocated by the submit helper, not this global. If a later recovered header proves a facade name, `g_pDownloadDispatcher` is the plausible alternate; `CashShopRequest *g_pCashShopRequest` is rejected as the primary declaration for this address.

IDA MCP `py_eval` on 2026-05-25 found 9 xrefs to this storage and 5 direct writes. The writers are the FileDownloader constructor/destructor family, including [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md), plus the scalar deleting destructor at `0x0041b610`.

2026-05-26 IDA recheck confirms the same address facts: `0x0067a738` is a four-byte `.data` item named `dword_67A738`, initialized to zero, with writes at `0x0041a6b1`, `0x0041a6b8`, `0x0041a722`, `0x0041b2f0`, and `0x0041b649`. The remaining reads are fitting-room/download request callers at `0x0041bdd0`, `0x0041cb70`, `0x00451c90`, plus application cleanup at `0x00464a60`.

Other parts of the client use cash-shop/download request APIs through this global: `0x0041b180`, `0x0041b200`, and `0x0041b270` allocate request payloads and dispatch downloader messages `10000`, `10001`, and `10002` through the thread queue. Separately, some feature packet builders use the `g_pCashShopRequest` name even though live IDA decompilation shows those paths read [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`, not this storage.

## Xref Matrix

The current evidence supports one live four-byte storage slot, not a family of aliases:

| Address | Access | Evidence meaning |
| --- | --- | --- |
| `0x0041a6b1` | write `this` | `FileDownloader::FileDownloader` publishes the downloader instance. |
| `0x0041a6b8` | write `0` | Constructor fallback clears the global if startup fails. |
| `0x0041a722` | write `0` | `FileDownloader::~FileDownloader` clears the singleton after stopping the worker. |
| `0x0041b2f0` | write `0` | Constructor-unwind helper clears the partially constructed singleton. |
| `0x0041b649` | write `0` | Scalar deleting destructor clears before optional delete. |
| `0x0041c215` | read | Fitting-room constructor submits downloader message `10002` through `0x0041b270`. |
| `0x0041cd09` | read | Fitting-room action handling submits downloader message `10001` through `0x0041b200`. |
| `0x00451cf8` | read | Fitting-room download control submits message `10000` through `0x0041b180`. |
| `0x00464a98` | read/delete | Application cleanup checks the pointer and deletes the live downloader through virtual slot `0`. |

The message IDs are the worker-thread constants documented in [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md), not socket opcodes. The adjacent globals stay separate: `0x0067a73c` is the fitting-room dialog pointer, `0x0067a740` is the BackPane singleton pointer, and `0x0067a7ec` is the packet sender [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

## 2026-06-16 C001 IDA Refresh

Live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the storage and narrowed the rename/type blocker without removing it:

- `get_bytes 0x0067a730-0x0067a750` returned 32 zero bytes, so this slot and the neighboring pointer cluster remain zero-initialized writable `.data`.
- `xrefs_to 0x0067a738` returned exactly nine direct data xrefs: five FileDownloader-family writes/clears, three fitting-room/item-shop submit reads, and one application cleanup virtual-delete read.
- Saved IDA function labels now identify the lifecycle writers as `FileDownloader_Constructor` at `0x0041a670`, `FileDownloader_Destructor` at `0x0041a6f0`, `ClearFileDownloaderRequestGlobal` at `0x0041b2f0`, and `FileDownloader_ScalarDeletingDestructor` at `0x0041b610`.
- Decompilation still shows the submit helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` allocate request payloads and post downloader messages `10000`, `10001`, and `10002` through `sub_596960`, with callers passing this FileDownloader-lifetime singleton.
- IDA data rename skipped: `dword_67A738 -> g_pFileDownloader` passed dry-run but was not applied because the original global could still have been named for a cash-shop/download facade or dispatcher rather than for the concrete `FileDownloader` class.

## Ownership Hypothesis

Do not treat the current filename as source-facing. The remaining spelling uncertainty is now narrowed to either:

- `FileDownloader *g_pFileDownloader`, accepted as the first-draft declaration.
- A broader facade name such as `FileDownloader *g_pDownloadDispatcher`, if a later header proves that style.

Rejected: treating the storage as a `CashShopRequest*` singleton. Current evidence favors FileDownloader/download-request dispatcher lifetime ownership: the storage address, lifetime owner, consumer set, saved lifecycle labels, alias boundary, and primary worker helper routes are now strong enough to emit first-draft `FileDownloader *g_pFileDownloader;`.

## Impact On Source Reconstruction

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) should mention the global because it writes and clears it.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) should not be merged into `FileDownloader.cpp` solely because of this global name.
- Header generation should use `FileDownloader *g_pFileDownloader` as the first-draft declaration, with the facade-name caveat retained in prose.
- Packet-send paths that use `g_pCashShopRequest` should be normalized to [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) when IDA shows `dword_67A7EC`.

## Follow-Up

- Keep the `0x0041b180`, `0x0041b200`, and `0x0041b270` submission helpers with FileDownloader dispatch unless later header evidence proves a different facade; payload classes remain separate context.
- If the file is later renamed, rename this page to `g_pFileDownloader.md` and update the linked memory page filename in the same pass.
- Recheck address aliasing after the downloader/request-dispatch boundary is cleaned up to ensure this storage is not conflated with `dword_67A7EC`.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/78`. Summary/evidence: the page documents address, FileDownloader lifetime evidence, xrefs, conflicting type/name, downloader request helper relationship, reconstruction impact, and follow-up checks; final source-facing type/name remains intentionally unresolved.
- 2026-06-05: Marked reconstructable under [UID:0000JC][FileDownloader](by-file/FileDownloader.md). Evidence: live IDA MCP reports nine xrefs to `0x0067a738`; decompilation confirms `0x0041a670` writes `dword_67A738 = this`, `0x0041b2f0` clears the constructor-unwind global, and `0x0041b610` clears the pointer during scalar deleting teardown.
- 2026-06-06: Raised to `88/84` and added the exact xref matrix plus neighboring-global boundaries. Evidence: the linked storage page records all five FileDownloader-family writes, the three fitting-room/downloader submit reads, the application cleanup delete read, and the `g_packetSender`/`dword_67A7EC` separation; confidence stays below final-source level because the public source name/type remains provisional.
- 2026-06-16 C001 global/IDA refresh:
  - Changed from `88/84` to `89/86`.
  - Summary/evidence: live IDA reconfirmed the nine-xref matrix and zeroed neighboring storage, saved FileDownloader lifecycle labels for the four writer/clearer functions, rechecked submit helper decompilation, and skipped the technically valid `dword_67A738 -> g_pFileDownloader` data rename because the final public global name/type remains an actual source-facing blocker.
- 2026-06-18 B001 FileDownloader download-helper source-quality pass:
  - Changed from `89/86` to `90/91`.
  - Summary/evidence: B001 rechecked the nine code refs, five FileDownloader-family writes/clears, three request-submit reads, application cleanup delete, neighboring `g_pFittingRoomDialog` boundary, and the actual separate `CashShopRequest` payload allocation. The page keeps the historical filename for now but treats `g_pCashShopRequest` as stale alias text and emits first-draft `FileDownloader *g_pFileDownloader;`.
