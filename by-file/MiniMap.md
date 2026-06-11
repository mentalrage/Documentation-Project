*** UID:0000LE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MiniMap

## Status

- Confidence: strong for feature-folder grouping and minimap-family ownership, medium-high for exact file split
- Proposed module folder: `map/`
- Candidate files: `map/MiniMapDialog.cpp`, `map/MiniMapRenderer.cpp`, `map/MiniMapVersionManager.cpp`, `map/MiniMapDownloader.cpp`; shared download bridge in [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- Evidence basis: Wave2 readonly class/global JSON, `simroot_v2` class metadata, and IDA MCP checks on 2026-05-22.

## Hypothesis

The minimap classes and helpers form a coherent map/minimap subsystem. They should not remain scattered across one-class generated files and recovered one-function globals. The likely original source tree had either one larger `MiniMap.cpp` or several minimap-focused files under a map/UI folder.

## Current Generated Containers

- `class_MiniMapDialog.cpp`
- `class_MiniMapRenderer.cpp`
- `class_MiniMapDownloader.cpp`
- `class_MiniMapImageControlPane.cpp`
- `class_MiniMapSymbolControlPane.cpp`
- `class_MiniMapButtonPane.cpp`
- `class_MiniMapVersionManager.cpp`
- `DownloadMinimap_00453AA0.cpp`
- `DownloadMinimapFile_0041A750.cpp`
- `recovered/GetControlLayout_00452260.cpp`

`MiniMapDialog` also consumes generic visual controls from `ui/controls`: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md) for the X/Y coordinate readouts, [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md) for symbol-background rectangles, and [UID:0000JI][FontStyle](by-file/FontStyle.md) for static label styling. Keep those classes documented as reusable controls unless later evidence proves they were minimap-local nested helpers.

## Classes

| Class | Range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) | `0x00450ca0-0x0045381b` local island | `class_MiniMapDialog.cpp` | Main minimap window/dialog; owns background/title/toggle controls, 768x768 map region, symbol panes, timers, and embedded renderer state. |
| [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) | `0x00453f50-0x00454e2e` | `class_MiniMapRenderer.cpp` | Embedded runtime state at `MiniMapDialog + 0x1CC`; owns map path/code buffers, tile context, symbol/label view buffers, and `.mnm` tile-blob decode through the shared JPEG wrapper. |
| `MiniMapDownloader` | `0x00453910-0x00453dee` | `class_MiniMapDownloader.cpp` | Download thread/singleton that dispatches minimap download tasks; see [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md). |
| [UID:00008E][MiniMapImageControlPane](by-class/MiniMapImageControlPane.md) | `0x00453df0-0x00453f44` | `class_MiniMapImageControlPane.cpp` | Control widget for displaying minimap images. |
| [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) | `0x00455e60-0x004563b5` | `class_MiniMapSymbolControlPane.cpp` | Control widget for animated symbol overlays. |
| [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) | `0x00503580-0x0050395f`, interleaved with [UID:0000L2][MapNamePane](by-file/MapNamePane.md) destructor tail | `class_MiniMapButtonPane.cpp` | Minimap UI button pane using `MMAPBUT` frame assets and mouse state transitions; exact omitted helper pages cover [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) and [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md). |
| [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) | `0x004563c0-0x00457547` | `class_MiniMapVersionManager.cpp` | Singleton for minimap tile/hash version tracking. |

## Free Helpers

| Function | Range | Current file | Evidence |
| --- | --- | --- | --- |
| `DownloadMinimap` | `0x00453aa0-0x00453d4f` | `DownloadMinimap_00453AA0.cpp` | Wave2 says sole caller is `MiniMapDownloader::OnThreadTask`; IDA MCP `callers` confirms caller `0x00453a16` inside `sub_453A00`. |
| `DownloadMinimapFile` | `0x0041a750-0x0041a9fe` | `DownloadMinimapFile_0041A750.cpp` | Downloads one minimap file from KRU S3 into caller-provided output path; IDA MCP confirms caller at `0x0041b168` inside [UID:0000JC][FileDownloader](by-file/FileDownloader.md). |
| [UID:0000SY][GetControlLayout_452260](by-global/GetControlLayout_452260.md) | [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md) | `recovered/GetControlLayout_00452260.cpp` | Maps `MiniMapDialog` control IDs to hard-coded rectangles; IDA MCP confirms seven calls from `MiniMapDialog` constructor `sub_450CA0`. |

## IDA MCP Evidence

Verified through direct JSON-RPC `/mcp` calls on 2026-05-22:

- `lookup_funcs`:
  - `0x0041a750` -> `sub_41A750`, size `0x2ae`
  - `0x00453aa0` -> `sub_453AA0`, size `0x2af`
  - `0x004563c0` -> `sub_4563C0`, size `0xbd`
  - `0x00456a90` -> `sub_456A90`, size `0x60e`
  - `0x004570a0` -> `sub_4570A0`, size `0x4`
- `callers`:
  - `0x00453aa0` has caller `0x00453a16` in `sub_453A00`, matching `MiniMapDownloader::OnThreadTask`.
  - `0x00452260` has seven callers inside `sub_450CA0`, matching `MiniMapDialog` construction.
  - `0x004563c0` has caller `_WinMain@16` at `0x004f5d04`, matching startup singleton initialization.
  - `0x004570a0` has caller `StartupWindow__RunUpdateCheck` at `0x00580ea3`, matching update-check use of current minimap hash version.
- `callees` for `0x00453aa0` include WinINet/file APIs: `InternetOpenW`, `InternetOpenUrlW`, `InternetQueryDataAvailable`, `InternetReadFile`, `HttpQueryInfoW`, `WriteFile`, `CloseHandle`, and `InternetCloseHandle`.

Follow-up checks on 2026-05-24 tightened the dialog/control boundaries:

- `lookup_funcs` confirms the local `MiniMapDialog` method island from `0x00450ca0` through `0x004537e0`, plus adjustor thunks at `0x004537bc` and `0x004537c7`.
- IDA does not define functions at generated `MiniMapDialog` rows `0x004517a0` or `0x00452ce0`; treat those as projected/internal labels for now.
- `callers 0x00452260` shows seven calls from `MiniMapDialog::MiniMapDialog`, confirming [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md) as minimap-specific layout code.
- `callers 0x00499f10` and `0x00499f90` show `MiniMapDialog` constructing and configuring a reusable [UID:0000JI][FontStyle](by-file/FontStyle.md) for static label text.
- `callers 0x00499910` shows two constructor calls from `MiniMapDialog::MiniMapDialog` for the coordinate value controls.
- `callers 0x00499c60` shows one constructor call from `MiniMapDialog::RenderSymbols` for rectangle-backed symbol UI.
- `callers 0x00453df0`, `0x00453f50`, and `0x00455e60` tie image control, renderer, and symbol controls directly to `MiniMapDialog`.
- Helper rows emitted under `MiniMapDialog` at `0x0049db60`, `0x0049dc10`, `0x0049dca0`, `0x0049dd80`, and `0x0049ddd0` have broad cross-dialog/control caller evidence and should not be migrated as minimap-owned code.
- 2026-05-25 follow-up: `0x004570b0` is a missing active-output method on `MiniMapVersionManager`, used by `MiniMapRenderer::PrepareMapFileAndCheckVersion` and `MiniMapRenderer::HasCurrentVersion` to retrieve the expected `.mnm` header/version string for a map id.
- 2026-05-26 follow-up: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) is now split into its own focused file-placement page, with [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) storage pinned at [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md). Keep this page as the subsystem umbrella.
- 2026-06-06 parent-chain review: [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md) now clears the global-to-file attachment gate against this file root. The global and exact storage page document the constructor publish, guard clear, destructor/helper/deleting-destructor clears, zero-initialized singleton slot at `0x0067a7d8`, and minimap-worker ownership. This supports `MiniMap` as the current valid file root while preserving the later `MiniMapDownloader.cpp` versus compact `MiniMap.cpp` split decision.
- 2026-06-07 Batch 001 parent assignment: [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) and [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) now attach to this file root. The downloader page has exact worker/download helper evidence, and the renderer/control aggregate now records the image-control, renderer, symbol-control, and support-helper inventory. The attachment means this is the current valid source family root, not that the final original project definitely used one compact `MiniMap.cpp`.
- 2026-06-07 A010 parent-gate refresh: live IDA xrefs for [UID:00028P][0x0067a7c4-0x0067a7c8.g_pMiniMapDialog](by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md) show `MiniMapDialog` constructor publication at `0x00450cf6`, constructor guard clear at `0x00450cfd`, teardown clear at `0x00451774`, singleton-clear helper at `0x00453660`, and minimap packet/UI consumers at `0x005a5990`, `0x005a5bd0`, `0x005a76c0`, and `0x005ac000`. This strengthens the file root enough for the `MiniMapDialog` class and singleton storage chain while preserving the unresolved final source split.

## Resource And Config Evidence

Wave2 class notes identify:

- `MiniMapDialog` uses `MMAPBACK.EPF`, `MNTITLE.EPF`, `MNSYMBOL.EPF`, and `ONOFFBUT.EPF`.
- Dialog map region is 768x768.
- Symbol groups are `0=Player`, `1=NPC`, `2=Portal`, `3=Party`.
- Config flags live in `RegistryConfig`/config offsets:
  - `0x291915` show portals
  - `0x291916` show NPCs
  - `0x291917` show party members
- `MiniMapVersionManager` persists/updates the minimap hash cache; prior report notes mention `%APPDATA%\NexusTK\MiniMap\mnmhs.hs`.
- `MiniMapVersionManager` uses [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) storage helpers for the hash-list cache, but the helper itself is shared with DAT manager and monster image code. Its sentinel-node allocation and two-word payload-node helpers belong to shared [UID:0000KR][LinkedList](by-file/LinkedList.md) utility support.

IDA string search found `MiniMap` string matches, but did not directly find the wide asset names or `mnmhs.hs` with the simple string-search query used here. Treat the asset/path strings above as Wave2/report-backed evidence until a deeper IDA string encoding search is done.

## Proposed Source Split

Preferred initial structure:

```text
map/MiniMapDialog.cpp
map/MiniMapRenderer.cpp
map/MiniMapDownloader.cpp
map/MiniMapVersionManager.cpp
```

Possible compact legacy structure:

```text
map/MiniMap.cpp
```

Use separate files if Wave3 ownership migration needs smaller review batches. Keep the feature under `map/` either way.

Keep `DownloadMinimap_453AA0` with `map/MiniMapDownloader.cpp`. Treat `DownloadMinimapFile_41A750` as a shared [UID:0000JC][FileDownloader](by-file/FileDownloader.md) helper unless later caller/task-structure review proves it was a minimap-private static helper.

## Open Questions

- Whether `MiniMapButtonPane`, `MiniMapImageControlPane`, and `MiniMapSymbolControlPane` were declared in the minimap files or in a generic UI controls file.
- Whether `DownloadMinimap_453AA0` and `DownloadMinimapFile_41A750` are old/new duplicate minimap paths or two separate update workflows.
- Exact local file format of `.mnm` and hash-list format should get a `by-item` or `by-memory` page when researched. The `.mnm` tile-blob prefix is now partially identified: `MiniMapRenderer::BuildSymbolViews` reads a 32-bit tile-blob size at document offset `0x1c`, then passes `cursor + 0x20` and that size to [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) at `0x004d0a90`.
- Whether renderer support helpers around `0x004550d0-0x00455b40` should be file-local minimap helpers or generic collection/string support.
- Confirm wide-string/resource references in IDA with a deeper string/operand scan.

## Proposed Wave3 Migration Batch

Do not run until reviewed:

```powershell
python E:\NTK\GhidraBridge\source-3\wave3.py create file MiniMap.cpp --kind source --simpath map
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapDialog --to-file MiniMap.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapRenderer --to-file MiniMap.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapDownloader --to-file MiniMap.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapImageControlPane --to-file MiniMap.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapSymbolControlPane --to-file MiniMap.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapButtonPane --to-file MiniMap.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class MiniMapVersionManager --to-file MiniMap.cpp
```

Free helper/global ownership needs review with Wave3 global ownership commands before applying.

## Cross-References

- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:0000SY][GetControlLayout_452260](by-global/GetControlLayout_452260.md)
- [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md)
- [UID:00008E][MiniMapImageControlPane](by-class/MiniMapImageControlPane.md)
- [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-07 A010 Batch032 parent-gate update:
  - Before: `82/84`; strong minimap-family evidence existed, but the corrected 85/85 gate blocked `MiniMapDialog` assignment.
  - After: `85/86`; added the live `g_pMiniMapDialog` constructor/destructor/helper/consumer evidence to the file-root record. This supports the current file root for parent-chain routing, while final `MiniMapDialog.cpp` versus compact `MiniMap.cpp` remains open and no final C++ was emitted.
- 2026-06-05: Filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/map/`.
  - Reason: `by-project-structure/proposed-source-tree.md` already places the MiniMap source family under map, and the linked IDA-backed minimap dialog/control, downloader, and `GetControlLayout_452260` caller evidence supports this source owner. This also makes the file root valid for child autogen attachment; completion/confidence scores were not changed.
- 2026-06-06 parent-chain evidence sync:
  - What existed before: the file was scored `78/82`, which kept [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md) from attaching to the staged minimap source root despite strong global/storage evidence.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: the file now explicitly carries the downloader singleton storage, constructor/destructor/helper clear evidence, exact memory/global pages, existing dialog/renderer/version-manager split notes, and the final `MiniMapDownloader.cpp` versus compact `MiniMap.cpp` caveat. This clears the 80/80 gate for global attachment without emitting final C++.
- 2026-06-07 A009 Batch 001 memory-child assignment:
  - What changed: [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) and [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) now use this file root as `AUTOGEN_PARENT_UID`.
  - Summary/evidence: live IDA MCP reconfirmed the downloader direct minimap task path, WinINet/file callee set, renderer/control method starts, MiniMapDialog construction callers, and renderer support-helper split. This reduces unassigned minimap memory coverage while keeping final C++ blank and preserving the `MiniMapDownloader.cpp`/`MiniMapRenderer.cpp` versus compact `MiniMap.cpp` decision.
- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page had strong feature-grouping evidence but was still unevaluated by the completion/confidence header.
  - After: score reflects documented minimap dialog, renderer, downloader, version-manager, button-pane, control, file-loader, global, and read-only-data relationships while retaining open questions about exact original source split and `.mnm` format details.
  - Evidence: cross-linked IDA MCP notes on the dialog/control island, renderer construction, version-manager startup and lookup calls, downloader callers, and minimap resource/config usage are already recorded in this page and its linked memory/class pages.
- 2026-05-27: Updated MiniMap renderer/control and version-manager boundary text from `0x004563b4`/`0x00457546` to `0x004563b5`/`0x00457547`. Evidence: IDA MCP reports `sub_4563B0` ending at `0x004563b5` and `sub_457480` ending at `0x00457547`; both previous ranges omitted final `retn` immediate bytes.
- 2026-05-28: Updated `MiniMapButtonPane` local range from `0x00503580-0x0050395e` to `0x00503580-0x0050395f`. Evidence: IDA MCP reports `sub_503900` ending at `0x0050395f`; the previous end omitted the final `retn 4` immediate byte.
