*** UID:00008D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapDownloader

## Status

- Confidence: strong for class behavior, source-family placement, singleton lifetime, and worker dispatch boundaries.
- Proposed source module: [UID:0000LE][MiniMap](by-file/MiniMap.md), likely a focused `map/MiniMapDownloader.cpp` split or a compact `map/MiniMap.cpp`.
- Evidence basis: existing MiniMap documentation plus Batch 092 live IDA MCP checks on function bounds, singleton xrefs, vtable xrefs, direct helper callers/callees, and boundary padding.

## Role

Singleton worker thread for minimap download tasks. It is minimap feature code, not a generic downloader module, even though it calls the shared `FileDownloader::StartThread` helper.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00453910-0x00453985` | `MiniMapDownloader::MiniMapDownloader` | Constructs `Thread(5)`, sets `g_pMiniMapDownloader`, installs vtable, starts the worker. |
| `0x00453990-0x004539e1` | `MiniMapDownloader::~MiniMapDownloader` | Stops thread, clears `g_pMiniMapDownloader`, destroys base thread. |
| `0x00453a00-0x00453a2f` | `MiniMapDownloader::OnThreadTask` | Message `0` calls `DownloadMinimap_453AA0` and deletes the task; nonzero messages forward to the base thread handler. |
| `0x00453d50-0x00453d5b` | `ClearMiniMapDownloaderSingleton` | Tiny local clear helper referenced by constructor exception metadata; belongs with this singleton class. |
| `0x00453d60-0x00453def` | `MiniMapDownloader::ScalarDeletingDestructor` | Destructor wrapper with optional delete. |

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000LE][MiniMap](by-file/MiniMap.md). This class is now scored `85/88`, and the direct file parent is scored `85/86`, so both sides satisfy the corrected 85/85 gate. The parent is direct because the file page owns the minimap downloader singleton, the `.mnm` download worker path, [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md), and the final split caveat between `MiniMapDownloader.cpp` and compact `MiniMap.cpp`.

## Related Helper

`DownloadMinimap_453AA0` at `0x00453aa0-0x00453d4f` is the direct worker helper for this class. It downloads a `.mnm` file from the KRU S3 minimap bucket using a task layout with `mapId`, `outputPath`, and `mapCode`.

Do not confuse this with `DownloadMinimapFile_41A750`, which is dispatched by [UID:00004W][FileDownloader](by-class/FileDownloader.md) message `10000` and uses a slightly different task layout.

## IDA MCP Evidence

- `lookup_funcs` confirms the constructor at `0x00453910`, task handler at `0x00453a00`, helper at `0x00453aa0`, and deleting destructor at `0x00453d60`.
- `callers` for `0x00453aa0` reports a single direct caller at `0x00453a16` inside `MiniMapDownloader::OnThreadTask`.
- `callees` for `0x00453a00` list `0x00453aa0` and the raw delete helper.
- `callers` for `0x005965e0` include the constructor at `0x00453910`, matching the shared worker-thread start launch.
- Batch 092 live IDA MCP reconfirmed the six-function island: `0x00453910-0x00453985`, `0x00453990-0x004539e1`, `0x00453a00-0x00453a2f`, `0x00453aa0-0x00453d4f`, `0x00453d50-0x00453d5b`, and `0x00453d60-0x00453def`, with twelve `0xcc` bytes before the constructor and one `0xcc` byte before the following image-control range.
- Batch 092 xrefs to `g_pMiniMapDownloader` at `0x0067a7d8` show constructor publish/guard writes at `0x00453951` and `0x00453958`, destructor clear at `0x004539c2`, clear-helper write at `0x00453d50`, and scalar-deleting-destructor clear at `0x00453d99`.
- Batch 092 found the vtable-backed task handler data xref at `0x006106fc`; `OnThreadTask` calls the local download helper, the shared thread fallback at `0x00596920`, and the task free helper at `0x005c7526`.
- Batch 092 callee evidence keeps base-thread helpers `0x00596250`, `0x00596400`, `0x005965e0`, and `0x00596920` outside the class while keeping the S3 `.mnm` helper in the minimap downloader source family.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The class page now records the complete function island including the clear helper, exact IDA bounds/padding, singleton lifecycle writes, vtable dispatch, direct download-helper ownership, source-family parent, and generic downloader exclusion. It remains below final-source quality because the task-block layout and exact final source split are unresolved. |
| Confidence | 88 | Confidence is strong from live IDA function, caller/callee, data-xref, and memory-page evidence. It is capped below the memory page because this class page does not fully expand the WinINet helper internals or task struct names. |

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md)
- [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the downloader constructor/destructor/task/helper/deleting-destructor starts at `0x00453910`, `0x00453990`, `0x00453a00`, `0x00453aa0`, and `0x00453d60`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion gate and likely parent [UID:0000LE][MiniMap](by-file/MiniMap.md) is also below the 80 completion attachment gate.
- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: the singleton worker-thread role, method set, direct helper, source-family placement, and FileDownloader distinction are well documented, but the task layout and helper internals are not fully expanded here. Evidence: linked MiniMapDownloader memory page, `g_pMiniMapDownloader`, IDA `lookup_funcs`/`callers`/`callees` notes, direct caller from `OnThreadTask` to `DownloadMinimap_453AA0`, and contrast with `DownloadMinimapFile_41A750`.
- 2026-06-07 A008 Batch 092 class-coverage pass:
  - Before: `78/86`, `AUTOGEN_PARENT_UID:` blank, and status text still named generated/Wave artifacts as evidence.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000LE`.
  - Summary/evidence: live IDA MCP reconfirmed all six function bounds, singleton slot xrefs, vtable-backed task dispatch, direct `0x00453aa0` caller, base-thread exclusions, and boundary padding. The direct parent [UID:0000LE][MiniMap](by-file/MiniMap.md) is `85/86`, so the corrected 85/85 gate is satisfied without emitting final C++.
