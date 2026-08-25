*** UID:0001SF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum FileDownloaderMessageId {
    kDownloadMinimapFileMessage = 10000,
    kDownloadCashShopCatalogMessage = 10001,
    kDownloadCashShopVersionMessage = 10002
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DownloaderMessageIds

## Status

- Confidence: very strong for observed values, direct `FileDownloader` ownership, dispatcher/submit-helper routes, and first-draft file-local enum names; medium only for exact original enum-vs-define spelling.
- Kind: recovered constants/message IDs.
- Assigned owner: [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- Reconstructable: yes, as source-level downloader message constants. Do not emit final C++ enum code until the final declaration spelling is decided.

## Assignment Gate

- Child score after Batch 097: `86/88`.
- Direct parent: [UID:0000JC][FileDownloader](by-file/FileDownloader.md), refreshed to `85/88`.
- Assignment decision: assign to [UID:0000JC][FileDownloader](by-file/FileDownloader.md). The constants are only observed in FileDownloader queue submit helpers and the FileDownloader `OnMessage` dispatcher, and the default branch falls back to the inherited `Thread::OnMessage` path rather than to game-socket or UI dispatch.

## Observed Values

| Value | Current meaning | Dispatch point |
| --- | --- | --- |
| `10000` | `kDownloadMinimapFileMessage`, minimap file download request for `DownloadMinimapFile`. | `FileDownloader::OnMessage` at `0x0041b110`. |
| `10001` | `kDownloadCashShopCatalogMessage`, cash-shop/fitting-room catalog download request for `DownloadCashShopCatalog`. | `FileDownloader::OnMessage` at `0x0041b110`. |
| `10002` | `kDownloadCashShopVersionMessage`, cash-shop/fitting-room version download request for `DownloadCashShopVersion`. | `FileDownloader::OnMessage` at `0x0041b110`. |

## Dispatch And Submission Evidence

| Value | Submit helper | Dispatcher target | Payload/lifetime note |
| --- | --- | --- | --- |
| `10000` / `0x2710` | [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) | [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) | Allocates a `0x238` byte minimap request block, posts the message through the downloader queue, and the dispatcher frees the raw block after download. |
| `10001` / `0x2711` | [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) | [UID:0002TT][0x0041ae20-0x0041b10c.DownloadCashShopCatalog](by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md) | Allocates a fitting-room/catalog request payload and posts it through [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`. |
| `10002` / `0x2712` | [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) | Allocates a version request payload; the dispatcher calls the version helper and then destroys the request through its vtable path. |

## Notes

These are worker-thread/download message IDs, not game socket opcodes. The default branch of `FileDownloader::OnMessage` forwards unrecognized IDs to the base `Thread::OnMessage` path.

`MiniMapDownloader::OnThreadTask` uses message `0` for `DownloadMinimap_453AA0`; that path is currently documented with [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md) rather than this `FileDownloader` dispatch enum.

## IDA MCP Evidence

- 2026-05-31 IDA MCP `analyze_funcs` on `0x0041b110` decompiled a real `switch (a2)` with cases `10000`, `10001`, and `10002`.
- Case `10000` calls `0x0041a750` and then `0x005c7526` to release the raw task block.
- Case `10001` calls `0x0041ae20` when the request block is non-null.
- Case `10002` calls `0x0041aa00` and then invokes the request object's deleting/destructor vtable path with argument `1`.
- The default branch tail-calls `0x00596920`, matching the inherited thread-message fallback noted in the FileDownloader docs.
- The aggregate FileDownloader dispatch page records that the submit helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` enqueue these same values through the worker-thread queue, and that live callers pass the FileDownloader lifetime global `dword_67A738`.

## Batch 097 IDA Recheck

- 2026-06-07 IDA MCP checked `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function lookup confirms `0x0041b110-0x0041b180` as the dispatcher, `0x0041b180-0x0041b1f5`, `0x0041b200-0x0041b26d`, and `0x0041b270-0x0041b2c9` as adjacent submit helpers.
- Dispatcher callees are `0x0041a750`, `0x0041ae20`, `0x0041aa00`, and the default thread fallback at `0x005c7526`/base worker cleanup paths. No socket opcode dispatch is present in this function.
- The `0x0041b180` submit helper allocates a `0x238` byte request, copies two wide-string fields, and posts message `10000` through the worker-thread queue helper.
- The `0x0041b200` and `0x0041b270` submit helpers call the same queue-post helper family used for messages `10001` and `10002`; the existing split pages retain the payload-specific cash-shop/version caveats.

## Open Questions

- Exact original spelling remains unproven (`enum`, unnamed enum, or `#define`s), but the source meaning and FileDownloader-local placement are now high-probability. Use `FileDownloaderMessageId`/`kDownload...Message` as first-draft source names; do not keep the values as socket opcodes or generic numeric constants.
- The enum is emitted as first-draft FileDownloader support context. Do not raise this page to a final-audit score until original declaration style is recovered or the whole FileDownloader header is assembled.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md)
- [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md)
- [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)

## Changes

- 2026-06-07 A004 Batch 097:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, parent blank.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000JC`.
  - Summary/evidence: live IDA rechecked the dispatcher and submit-helper boundaries, the `10000-10002` switch, the queue-post helper family, the download target helpers, and the inherited thread fallback. The strict assignment gate is satisfied because the direct FileDownloader parent is now `85/88`; C++ remains blank because final enum/constant spelling is still provisional.
- 2026-06-06: Raised completion from `72` to `78` after adding submission-side evidence for all three message IDs, exact submit-helper/dispatcher-target links, and the `dword_67A738` downloader singleton boundary. Confidence stays `88` because the values and switch behavior are strong, while final source form (`enum`, `#define`, or file-local constants) and owner header remain provisional.
- 2026-06-18 B001 FileDownloader download-helper source-quality pass:
  - Changed from `86/88` to `88/90`.
  - Populated first-draft file-local `FileDownloaderMessageId` enum.
  - Summary/evidence: B001 reconfirmed dispatcher and submit-helper routes for all three values, rejected socket-opcode and generic numeric-constant treatment, tied each value to the FileDownloader worker helper and request lifetime behavior, and left only original enum-vs-define spelling as a final-source caveat.
