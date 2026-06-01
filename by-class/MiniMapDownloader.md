*** UID:00008D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapDownloader

## Status

- Confidence: strong for class behavior and source-family placement.
- Current Wave3 file: `class_MiniMapDownloader.cpp`
- Proposed source module: [UID:0000LE][MiniMap](by-file/MiniMap.md), likely `map/MiniMapDownloader.cpp`
- Evidence basis: `simroot_v2`, prior Wave2 report notes, and live IDA MCP checks.

## Role

Singleton worker thread for minimap download tasks. It is minimap feature code, not a generic downloader module, even though it calls the shared `FileDownloader::StartThread` helper.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00453910-0x00453985` | `MiniMapDownloader::MiniMapDownloader` | Constructs `Thread(5)`, sets `g_pMiniMapDownloader`, installs vtable, starts the worker. |
| `0x00453990-0x004539e1` | `MiniMapDownloader::~MiniMapDownloader` | Stops thread, clears `g_pMiniMapDownloader`, destroys base thread. |
| `0x00453a00-0x00453a2f` | `MiniMapDownloader::OnThreadTask` | Message `0` calls `DownloadMinimap_453AA0` and deletes the task; nonzero messages forward to the base thread handler. |
| `0x00453d60-0x00453def` | `MiniMapDownloader::ScalarDeletingDestructor` | Destructor wrapper with optional delete. |

## Related Helper

`DownloadMinimap_453AA0` at `0x00453aa0-0x00453d4f` is the direct worker helper for this class. It downloads a `.mnm` file from the KRU S3 minimap bucket using a task layout with `mapId`, `outputPath`, and `mapCode`.

Do not confuse this with `DownloadMinimapFile_41A750`, which is dispatched by [UID:00004W][FileDownloader](by-class/FileDownloader.md) message `10000` and uses a slightly different task layout.

## IDA MCP Evidence

- `lookup_funcs` confirms the constructor at `0x00453910`, task handler at `0x00453a00`, helper at `0x00453aa0`, and deleting destructor at `0x00453d60`.
- `callers` for `0x00453aa0` reports a single direct caller at `0x00453a16` inside `MiniMapDownloader::OnThreadTask`.
- `callees` for `0x00453a00` list `0x00453aa0` and the raw delete helper.
- `callers` for `0x005965e0` include the constructor at `0x00453910`, matching the generated `FileDownloader::StartThread(this)` launch.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md)
- [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: the singleton worker-thread role, method set, direct helper, source-family placement, and FileDownloader distinction are well documented, but the task layout and helper internals are not fully expanded here. Evidence: linked MiniMapDownloader memory page, `g_pMiniMapDownloader`, IDA `lookup_funcs`/`callers`/`callees` notes, direct caller from `OnThreadTask` to `DownloadMinimap_453AA0`, and contrast with `DownloadMinimapFile_41A750`.
