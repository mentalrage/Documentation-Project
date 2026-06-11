*** UID:0000QH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCashShopRequest

## Status

- Confidence: strong for address, FileDownloader lifetime, writer/read xrefs, and neighboring-global boundaries; medium-high for final source-facing type/name.
- Address: `0x0067a738`
- IDA name: `dword_67A738`
- Working type hypothesis in older notes: `CashShopRequest*`; current evidence favors a `FileDownloader`/download-dispatcher singleton role rather than a pure cash-shop payload object.
- Current observed writer: `FileDownloader::FileDownloader`
- Proposed owner: [UID:0000JC][FileDownloader](by-file/FileDownloader.md) / download-request dispatcher, with final type/name unresolved.
- Primary memory doc: [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)

## Observed Evidence

IDA decompilation of `FileDownloader::FileDownloader` writes this storage, and `FileDownloader` teardown clears the pointer. Live IDA names the storage `dword_67A738`. This conflicts with the narrow `CashShopRequest* g_pCashShopRequest` declaration if that type is interpreted as the complete object type.

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

## Ownership Hypothesis

Do not treat the current name and type as settled. The global could be:

- A mislabeled `FileDownloader*` singleton.
- A broader request/download dispatcher pointer that older notes typed too narrowly.
- A legacy shared global where `FileDownloader`, cash-shop request payload classes, and downloader request submission helpers were related by a base or naming collision not yet recovered.

Current evidence favors FileDownloader/download-request dispatcher lifetime ownership. Keep the final public name/type open until the `CashShopRequest` payload class and downloader request-submission methods are separated cleanly; however, the storage address, lifetime owner, consumer set, and alias boundary are now strong enough to treat this page as a high-confidence global ownership record.

## Impact On Source Reconstruction

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) should mention the global because it writes and clears it.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) should not be merged into `FileDownloader.cpp` solely because of this global name.
- Header generation should avoid committing to `CashShopRequest*` here until caller casts and uses are reviewed.
- Packet-send paths that use `g_pCashShopRequest` should be normalized to [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) when IDA shows `dword_67A7EC`.

## Follow-Up

- Split the `0x0041b180`, `0x0041b200`, and `0x0041b270` submission helpers from the small `CashShopRequest` payload class if later ownership cleanup supports a downloader/request dispatcher owner.
- Compare calls through the pointer against `FileDownloader`, `CashShopRequest`, and `Thread` vtable layouts before renaming or retyping the global.
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
