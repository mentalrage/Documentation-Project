*** UID:0000RO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapDownloader

## Status

- Confidence: strong for class association, medium for exact storage owner.
- Current Wave3 kind: `global-data`
- Current Wave3 owner file: `class_MiniMapDownloader.cpp`
- Address: [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md)
- Proposed owner: `map/MiniMapDownloader.cpp` or `map/MiniMap.cpp`.

## Observed Evidence

Generated `MiniMapDownloader::MiniMapDownloader` sets `g_pMiniMapDownloader = this` after constructing the `Thread(5)` base and before starting the worker. Generated destructor paths clear the global before destroying the thread base.

`Application` startup constructs a `MiniMapDownloader` singleton after the minimap/version manager setup path, matching the global singleton pattern.

## Evidence Details

- [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md) documents the exact four-byte `.data` storage as `MiniMapDownloader *g_pMiniMapDownloader;`.
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) records the constructor, destructor, `OnThreadTask`, `DownloadMinimap_453AA0`, and scalar deleting destructor method cluster.
- `source-3/simroot_v2/class_MiniMapDownloader.cpp` shows constructor assignment at `0x00453910`, destructor clear at `0x00453990`, and scalar deleting destructor clear at `0x00453d60`.
- `source-3/simroot_v2/class_Application.cpp` constructs a `MiniMapDownloader` during application startup, and `class_MiniMapDialog.cpp` uses `g_pMiniMapDownloader` to request minimap updates.
- `class_MiniMapDialog.cpp.source_map.json` has `global-data:g_pMiniMapDownloader` as an unresolved marker, so it is consumer evidence only, not a storage-owner proof.
- No `class_MiniMapDownloader.cpp.source_map.json` exists in current `simroot_v2`, and live IDA MCP was unavailable during the 2026-05-30 review. Keep confidence below the exact storage page until the owner source-map or fresh IDA xrefs are available.

## Ownership Hypothesis

This is the active minimap downloader singleton. It should migrate with [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md), not with generic network downloader code.

## Follow-Up

- Review all data/code xrefs to confirm whether UI code posts work directly through this global or through a wrapper.
- Decide whether the final type should be `MiniMapDownloader*` or a base worker-thread pointer.
- If a `MiniMapDownloadTask` struct is recovered, cross-link its queue/post callers here.

## Cross-References

- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md)
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md)

## Changes

- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata and only summarized generated constructor/destructor behavior. It now links the exact storage page, records the constructor/destructor/scalar-deleting-destructor lifecycle, notes `Application` startup and `MiniMapDialog` consumer evidence, and documents the missing owner source-map and unavailable live IDA MCP caveats. Score changed to `78/82` because identity, storage, and lifecycle are strong, while task layout and source-map/xref freshness remain incomplete.
