*** UID:0000QH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCashShopRequest

## Status

- Confidence: strong for address and FileDownloader lifetime, medium for final source-facing type/name.
- Current Wave3 kind: `global-data`
- Address: `0x0067a738`
- IDA name: `dword_67A738`
- Current generated type: `CashShopRequest*`
- Current observed writer: `FileDownloader::FileDownloader`
- Proposed owner: [UID:0000JC][FileDownloader](by-file/FileDownloader.md) / download-request dispatcher, with final type/name unresolved.
- Primary memory doc: [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)

## Observed Evidence

Generated `FileDownloader::FileDownloader` writes `g_pCashShopRequest = this`, and `FileDownloader` teardown clears the pointer. Live IDA names the storage `dword_67A738`. This conflicts with the current generated declaration `CashShopRequest* g_pCashShopRequest` if that type is interpreted as the complete object type.

IDA MCP `py_eval` on 2026-05-25 found 9 xrefs to this storage and 5 direct writes. The writers are the FileDownloader constructor/destructor family, including [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md), plus the scalar deleting destructor at `0x0041b610`.

2026-05-26 IDA recheck confirms the same address facts: `0x0067a738` is a four-byte `.data` item named `dword_67A738`, initialized to zero, with writes at `0x0041a6b1`, `0x0041a6b8`, `0x0041a722`, `0x0041b2f0`, and `0x0041b649`. The remaining reads are fitting-room/download request callers at `0x0041bdd0`, `0x0041cb70`, `0x00451c90`, plus application cleanup at `0x00464a60`.

Other parts of the client use cash-shop/download request APIs through this global: `0x0041b180`, `0x0041b200`, and `0x0041b270` allocate request payloads and dispatch downloader messages `10000`, `10001`, and `10002` through the thread queue. Separately, some generated feature packet builders also use the `g_pCashShopRequest` name even though live IDA decompilation shows those paths read [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`, not this storage.

## Ownership Hypothesis

Do not treat the current name and type as settled. The global could be:

- A mislabeled `FileDownloader*` singleton.
- A broader request/download dispatcher pointer that Wave3 currently typed too narrowly.
- A legacy shared global where `FileDownloader`, cash-shop request payload classes, and downloader request submission helpers were related by a base or naming collision not yet recovered.

Current evidence favors FileDownloader/download-request dispatcher lifetime ownership. Keep the final public name/type open until the `CashShopRequest` payload class and downloader request-submission methods are separated cleanly.

## Impact On Source Reconstruction

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) should mention the global because it writes and clears it.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) should not be merged into `FileDownloader.cpp` solely because of this global name.
- Header generation should avoid committing to `CashShopRequest*` here until caller casts and uses are reviewed.
- Generated files that use `g_pCashShopRequest` for packet-send paths should be normalized to [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) when IDA shows `dword_67A7EC`.

## Follow-Up

- Split the `0x0041b180`, `0x0041b200`, and `0x0041b270` submission helpers from the small `CashShopRequest` payload class if later ownership cleanup supports a downloader/request dispatcher owner.
- Compare calls through the pointer against `FileDownloader`, `CashShopRequest`, and `Thread` vtable layouts before renaming or retyping the global.
- Recheck simroot after the next Wave3 data refresh to ensure this storage is not conflated with `dword_67A7EC`.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/78`. Summary/evidence: the page documents address, FileDownloader lifetime evidence, xrefs, conflicting generated type/name, downloader request helper relationship, reconstruction impact, and follow-up checks; final source-facing type/name remains intentionally unresolved.
