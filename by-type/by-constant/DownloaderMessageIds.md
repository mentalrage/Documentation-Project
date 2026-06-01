*** UID:0001SF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DownloaderMessageIds

## Status

- Confidence: strong for observed values, medium for final enum/type name.
- Kind: recovered constants/message IDs.
- Current owner: [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- Reconstructable: yes, as source-level downloader message constants. Do not emit final C++ enum code until the final owner header/name is decided.

## Observed Values

| Value | Current meaning | Dispatch point |
| --- | --- | --- |
| `10000` | Minimap file download request for `DownloadMinimapFile_41A750`. | `FileDownloader::OnMessage` at `0x0041b110`. |
| `10001` | Cash-shop/fitting-room catalog download request for `DownloadCashShopCatalog_41AE20`. | `FileDownloader::OnMessage` at `0x0041b110`. |
| `10002` | Cash-shop/fitting-room version download request for `DownloadCashShopVersion_41AA00`. | `FileDownloader::OnMessage` at `0x0041b110`. |

## Notes

These are worker-thread/download message IDs, not game socket opcodes. The default branch of `FileDownloader::OnMessage` forwards unrecognized IDs to the base `Thread::OnMessage` path.

`MiniMapDownloader::OnThreadTask` uses message `0` for `DownloadMinimap_453AA0`; that path is currently documented with [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md) rather than this `FileDownloader` dispatch enum.

## IDA MCP Evidence

- 2026-05-31 IDA MCP `analyze_funcs` on `0x0041b110` decompiled a real `switch (a2)` with cases `10000`, `10001`, and `10002`.
- Case `10000` calls `0x0041a750` and then `0x005c7526` to release the raw task block.
- Case `10001` calls `0x0041ae20` when the request block is non-null.
- Case `10002` calls `0x0041aa00` and then invokes the request object's deleting/destructor vtable path with argument `1`.
- The default branch tail-calls `0x00596920`, matching the inherited thread-message fallback noted in the FileDownloader docs.

## Open Questions

- Final source name is still provisional. `DownloaderMessageIds` is accurate as documentation vocabulary, but the original source may have used `#define`s, an unnamed enum, or file-local constants.
- The owner header is not final because the submit helpers around `0x0041b180-0x0041b2c9` still have mixed FileDownloader/cash-shop placement evidence.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
