*** UID:0000RO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MiniMapDownloader *g_pMiniMapDownloader = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapDownloader

## Status

- Confidence: strong for address, class association, lifetime writes, and singleton role; medium-high for final file split.
- Address: [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md)
- Proposed owner: `map/MiniMapDownloader.cpp` or `map/MiniMap.cpp`.
- Parent attachment: [UID:0000LE][MiniMap](by-file/MiniMap.md). A focused `MiniMapDownloader.cpp` split is still possible, but the current MiniMap file root now clears the 80/80 gate.

## Observed Evidence

`MiniMapDownloader::MiniMapDownloader` sets `g_pMiniMapDownloader = this` after constructing the `Thread(5)` base and before starting the worker. Destructor paths clear the global before destroying the thread base.

`Application` startup constructs a `MiniMapDownloader` singleton after the minimap/version manager setup path, matching the global singleton pattern.

## Evidence Details

- [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md) documents the exact four-byte writable storage for the `MiniMapDownloader` singleton pointer.
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) records the constructor, destructor, `OnThreadTask`, `DownloadMinimap_453AA0`, and scalar deleting destructor method cluster.
- Live IDA MCP `xrefs_to 0x0067a7d8` on 2026-06-05 reports 5 xrefs: constructor writes at `0x00453951` / `0x00453958`, destructor clear at `0x004539c2`, clear helper at `0x00453d50`, and scalar deleting destructor clear at `0x00453d99`.
- Live IDA MCP on 2026-06-06 reconfirms the same 5 direct xrefs and shows the adjacent 16 bytes beginning at `0x0067a7d8` are zero-initialized in the loaded image.
- Decompilation shows `0x00453910` installing the `MiniMapDownloader` vtable and publishing the current object to the singleton slot, with `0x00453990`, `0x00453d50`, and `0x00453d60` clearing the slot during teardown.
- Application startup constructs a `MiniMapDownloader` during the minimap setup path, and minimap UI/dialog code uses the singleton to request updates; those consumers do not override class/file ownership.
- 2026-06-16 C001 live IDA refresh reconfirmed the exact five direct data xrefs to `0x0067a7d8`: constructor publish/guard clear at `0x00453951`/`0x00453958`, destructor clear at `0x004539c2`, clear-helper write at `0x00453d50`, and scalar-deleting-destructor clear at `0x00453d99`. `get_bytes 0x0067a7d0` again showed the surrounding singleton window is zeroed.
- C001 applied and saved the IDA names `g_pMiniMapDownloader`, `MiniMapDownloader_Constructor`, `MiniMapDownloader_Destructor`, `MiniMapDownloader_ClearSingletonHelper`, and `MiniMapDownloader_ScalarDeletingDestructor` after a successful dry run.

## Ownership Hypothesis

This is the active minimap downloader singleton. It should migrate with [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md), not with generic network downloader code. The accepted formal block emits `MiniMapDownloader *g_pMiniMapDownloader = NULL;` here, while exact storage child [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md) now emits a covered-by marker. It is attached to the broader [UID:0000LE][MiniMap](by-file/MiniMap.md) file root for autogen staging; a later focused `MiniMapDownloader.cpp` source split can move the global after that file root is created and documented.

## Current-Pass Exclusions

- Do not move the definition to generic `FileDownloader` or worker-thread support docs; the singleton xrefs and vtable route are MiniMapDownloader-specific.
- Do not emit a duplicate definition from [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md); that page is covered storage.
- Task-post wrapper and `MiniMapDownloadTask` field recovery are exact child/split work for [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md), not blockers for this singleton definition.

## Cross-References

- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md)
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `85/90` to `87/91`, inserted the accepted singleton definition, and converted generic follow-up wording into current-pass exclusions tied to [UID:00028S][0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md) covered storage and [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) child-split work.
- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata and only summarized constructor/destructor behavior. It now links the exact storage page, records the constructor/destructor/scalar-deleting-destructor lifecycle, and notes application startup and minimap UI/dialog consumer evidence. Score changed to `78/82` because identity, storage, and lifecycle are strong, while task layout and exact source split remain incomplete.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with temporary minimap-family ownership; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7d8` and decompilation of `0x00453910`, `0x00453990`, `0x00453d50`, and `0x00453d60` prove NexusTK-owned minimap downloader singleton storage owned by the minimap source family. At the time it was attached to [UID:0000LE][MiniMap](by-file/MiniMap.md); the 2026-06-06 cleanup below removes that parent until a qualifying file root is proven. No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06 source-facing cleanup:
  - What existed before: score `78/82`, stale coverage-row caveats, a raw singleton label in evidence, and a parent link to a file page below the attachment gate.
  - Changed to: score `84/88`, blank parent, refreshed live xref/byte evidence, and source-facing singleton wording.
  - Summary/evidence: current IDA MCP confirms the constructor publish, guard clear, destructor/helper/deleting-destructor clears, zero-initialized storage, and minimap-downloader ownership. Final file split remains open, so C++ stays blank and the file parent remains blank.
- 2026-06-06 parent-chain sync:
  - What existed before: the global remained unassigned even though its exact storage child pointed at this global, leaving the memory autogen parent chain without a valid file root.
  - Changed to: parent [UID:0000LE][MiniMap](by-file/MiniMap.md).
  - Summary/evidence: [UID:0000LE][MiniMap](by-file/MiniMap.md) now records the downloader singleton, method/storage evidence, and final split caveat at `82/84`, while this global remains `84/88`. This satisfies the attachment gate without adding final C++.
- 2026-06-16 C001 global/source-quality refresh:
  - What existed before: score `84/88`, exact singleton storage and minimap-worker ownership were documented, but IDA still used generated names for the singleton slot and lifecycle helpers.
  - Changed to: score `85/90`; IDA names were saved for the global and four lifecycle helpers.
  - Summary/evidence: live IDA reconfirmed the 5-xref singleton lifecycle, zeroed singleton-cluster bytes, `MiniMapDownloader` vtable-backed constructor/destructor paths, and [UID:0000LE][MiniMap](by-file/MiniMap.md) owner/emitter route. Final C++ remains blank because the task-block layout, `Thread` base API names, and `MiniMapDownloader.cpp` versus compact `MiniMap.cpp` source split remain provisional.
