*** UID:0000LE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MiniMap

## Status

- Confidence: strong for feature-folder grouping and minimap-family ownership, medium-high for exact file split
- Proposed module folder: `map/`
- Candidate files: `map/MiniMapDialog.cpp`, `map/MiniMapRenderer.cpp`, `map/MiniMapVersionManager.cpp`, `map/MiniMapDownloader.cpp`; shared download bridge in [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- Evidence basis: Wave2 readonly class/global JSON, `simroot_v2` class metadata, IDA MCP checks from 2026-05-22 through 2026-06-12, and the 2026-06-16 A001 live IDA/PE refresh.

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
| [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) | `0x00453f50-0x00454e2e` | `class_MiniMapRenderer.cpp` | Embedded runtime state at `MiniMapDialog + 0x1CC`; owns map path/code buffers, tile context, symbol/label view buffers, and `.mnm` tile-blob decode through [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md). |
| `MiniMapDownloader` | `0x00453910-0x00453dee` | `class_MiniMapDownloader.cpp` | Download thread/singleton that dispatches minimap download tasks; see [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md). |
| [UID:00008E][MiniMapImageControlPane](by-class/MiniMapImageControlPane.md) | `0x00453df0-0x00453f44` | `class_MiniMapImageControlPane.cpp` | Control widget for displaying minimap images. |
| [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) | `0x00455e60-0x004563b5` | `class_MiniMapSymbolControlPane.cpp` | Control widget for animated symbol overlays; includes constructor/destructor, `StartAnimation`, `SetCenterPosition`, `OnAnimationTick`, `OnDraw`, compiler adjustor/deleting-destructor glue, and `GetControlType`. |
| [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) | `0x00503580-0x0050395f`, interleaved with [UID:0000L2][MapNamePane](by-file/MapNamePane.md) destructor tail | `class_MiniMapButtonPane.cpp` plus exact children | Minimap UI button pane using `MMAPBUT` frame assets and mouse state transitions; exact source-bearing children now include ordinary destructor [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) and singleton helper [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md), while [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) is a non-emitting split index and [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md)/[UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) are compiler destructor glue. |
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
- 2026-06-16 A001 live IDA/PE refresh: active IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` reports `MiniMapDialog` constructor `sub_450CA0`, minimap layout helper `sub_452260`, downloader helper `sub_453AA0`, renderer helpers through `sub_4550D0`, and symbol-control terminal helper `sub_4563B0`. The generated/raw labels at `0x004517a0`, `0x00452ce0`, and `0x00454e30` still are not IDA function starts; section-mapped PE scans found zero absolute-VA/RVA pointer encodings and zero direct branches to those raw starts. Constructor reachability remains two direct branches to `0x00450ca0` from `0x005a815f` and `0x005ac049`, and the `g_pMiniMapDialog` slot at `0x0067a7c4` still has the eight constructor/teardown/packet/UI references documented by the singleton pages. This resolves the stale "current-session" evidence gap but keeps final source split and raw-helper naming open.
- 2026-06-20 B005 symbol-control source-quality sync: [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) now records the omitted `0x004560f0-0x00456175` `SetCenterPosition` method. `MiniMapDialog` calls the chain at `0x00452ee9` (`MiniMapRenderer::UpdateViewOriginFromPlayer`), `0x00452f3d` (image-control position setter), and `0x00452f4e` (`MiniMapSymbolControlPane::SetCenterPosition`). This strengthens the MiniMap file-family route while keeping final source split open between compact `MiniMap.cpp` and focused `MiniMapDialog.cpp`/`MiniMapRenderer.cpp` plus private control classes.
- 2026-06-21 B007 renderer/control source-quality sync: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) now treats the renderer/control island as a source-family split index rather than one emit-ready body. The split policy is image control, renderer, symbol control, renderer-local 80/108-byte vector support, shared 24-byte small-wide-string support, and raw `0x00454e30` WinINet no-code proof. The generic helper-name blockers for `0x004540a0` and `0x004560f0` are closed; remaining blockers are record-layout names, raw-helper reachability/function repair, image/render helper type names, and final compact-versus-split source-file shape.
- 2026-06-23 B004 MiniMapDialog source-quality sync: [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) is now `88/89` with the MiniMap file root retained and aggregate C++ still blank. MCP session `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` confirmed the `0x2b7b` / 11131-byte island, 23 modeled in-range functions, successor `0x00453820`, constructor calls at `0x005a815f` and `0x005ac049`, MiniMapDialog vtable refs, `g_pMiniMapDialog` lifecycle refs, and exact padding/table gaps. The three raw labels `0x004517a0`, `0x00452ce0`, and `0x00452ea0` are now documented as source-shaped but no-function/no-route bodies: raw refresh/re-render, symbol-pane append/add-control, and player-marker center update. The generated `EnqueueRequest` name for `0x00452ce0` is rejected. PE route controls found no direct branch or VA/RVA/raw-offset pointer route to the three raw starts, so they remain documented inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) and do not receive emitting child pages in this implementation. The compact `MiniMap.cpp` versus focused `MiniMapDialog.cpp`/`MiniMapRenderer.cpp` source-file shape remains an inferred placement choice at the file-root level; for [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) that is resolved by retaining [UID:0000LE] as the owner/emitter and leaving aggregate C++ blank.
- 2026-06-20 B005 MiniMapButtonPane cleanup/thunk split: [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) is no longer a source-bearing MiniMap emitter. Exact child [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md) carries the source-like singleton clear, [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) carries first-draft `MiniMapButtonPane::~MiniMapButtonPane()` C++, and [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md) plus [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) remain non-emitting compiler glue. This keeps the source route in `NexusTK/map/` while preventing the mixed `0001AN` range from emitting MapNamePane or compiler thunk bytes.

## Resource And Config Evidence

2026-06-12 read-only-data split: [UID:0003FP][0x006104f4-0x006108d4.MiniMapUiReadOnlyData](by-memory/0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md) now owns the MiniMap UI `.rdata` slice for `MiniMapDialog`, `MiniMapDownloader`, `MiniMapImageControlPane`, and `MiniMapSymbolControlPane`. Live IDA xrefs tie the vtable stores and resource/path strings to the minimap constructor, renderer, downloader, and symbol-control paths; the adjacent [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md) is intentionally not attached here because it belongs to [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md).

2026-06-12 A001 Batch 271 resource-string refresh: [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) contains the exact UTF-16 `MMAPBUT.EPF` literal consumed by [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) at `0x0050366c`. Keep that child parentless because the same physical string span also contains `MAPNAME.EPF`, `CMAP`, and `GM` literals owned by other map/game systems.

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

The 2026-06-16 raw-helper disassembly check does confirm the unmodeled `0x00454e30-0x00455040` helper contains a stack-cookie prologue, the shared downloader user-agent literal, WinINet calls, S3/minimap URL formatting, `.mnm` suffix handling, `HttpQueryInfoW` status `0xc8`, file writing, and cleanup/deletion paths. That is enough to keep the helper in the minimap source family, but not enough to choose a final source-facing helper name or create an IDA function/database edit safely.

B007 2026-06-21 refines that decision: the best future conceptual source name is `MiniMapRenderer::DownloadCurrentMapFile()` or `MiniMapRenderer::DownloadMapImageFile()` if liveness is later proven, but do not use `DownloadMinimapFile` because [UID:0000JC][FileDownloader](by-file/FileDownloader.md) already owns that message helper shape at `0x0041a750`. A strict raw child would need to include the return byte at `0x00455040` and alignment starts at `0x00455041`; no child split is required for the current aggregate.

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

## FileDownloader Download Helper Context

B001 2026-06-18 source-quality pass clarifies that `DownloadMinimapFile` at `0x0041a750` is a FileDownloader message `10000` worker helper, not the same source body as MiniMapDownloader's task handler. MiniMap remains feature context for request data and S3 minimap resources; [UID:0000JC][FileDownloader](by-file/FileDownloader.md) emits the HTTP worker body. The minimap worker uses a raw `FileDownloaderMinimapRequest` with `mapId`, `outputPath[0x104]`, and `mapCode[0x10]`; generated `mapCode[32]` is rejected by the submit-helper copy size and allocation boundary.

## Empty-Emitter Source Disposition

B010's accepted 2026-06-30 empty-emitter report keeps [UID:0000LE] as the active MiniMap source-family root for `auto-generated/NexusTK/map/MiniMap.cpp`. This file-root page has no formal `RECONSTRUCTION_CPP CODE` block by by-file schema; it remains the source root through `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.

The current generated MiniMap output had one filled source body and 18 empty emitter markers. [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) already emits the source destructor body `MiniMapButtonPane::~MiniMapButtonPane(){ g_pMiniMapButtonPane = NULL; }`, proving exact child-method emission is the correct MiniMap pattern. The 18 empty markers are resolved as follows:

| UID | Target | Current-pass disposition |
| --- | --- | --- |
| `00008B` | [MiniMapButtonPane](by-class/MiniMapButtonPane.md) | Formal class-index marker with `[[CHILDREN]]`; no declaration shell because base spellings, hover/down fields, tile-context ownership, and click-dispatch names are not source-quality. |
| `00008C` | [MiniMapDialog](by-class/MiniMapDialog.md) | Formal class-index marker with `[[CHILDREN]]`; [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) keeps raw no-route bodies and mixed helper evidence, so no monolithic class declaration is emitted. |
| `00028P` | [0x0067a7c4-0x0067a7c8.g_pMiniMapDialog](by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md) | Exact singleton definition `MiniMapDialog *g_pMiniMapDialog = NULL;`; no new `by-global/g_pMiniMapDialog.md` alias is created in this callback. |
| `00008D` | [MiniMapDownloader](by-class/MiniMapDownloader.md) | Formal class-index marker with `[[CHILDREN]]`; Thread base spelling and `MiniMapDownloadTask` field names block a declaration shell. |
| `00008E` | [MiniMapImageControlPane](by-class/MiniMapImageControlPane.md) | Formal class-index marker with `[[CHILDREN]]`; ControlPane base spelling, image-handle type at `+0x14c`, and render-helper names block source declaration. |
| `00008F` | [MiniMapRenderer](by-class/MiniMapRenderer.md) | Formal class-index marker with `[[CHILDREN]]`; embedded-runtime methods are documented, but record-vector layouts, `.mnm` names, and raw downloader-helper reachability block a declaration shell. |
| `00008G` | [MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) | Formal class-index marker with `[[CHILDREN]]`; accepted B005 evidence remains `88/90`, but base-subobject spelling and `+0x210/+0x214` center-coordinate order still block class-level C++. |
| `0000SY` | [GetControlLayout_452260](by-global/GetControlLayout_452260.md) | Alias marker only; exact helper body is emitted by [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md). |
| `0000RN` | [g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md) | Exact singleton definition `MiniMapButtonPane *g_pMiniMapButtonPane = NULL;`. |
| `0002XP` | [0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md) | Storage child marker covered by [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md); no duplicate pointer definition. |
| `0000RO` | [g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md) | Exact singleton definition `MiniMapDownloader *g_pMiniMapDownloader = NULL;`. |
| `00028S` | [0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader](by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md) | Storage child marker covered by [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md); no duplicate pointer definition. |
| `0000XK` | [0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) | Aggregate/source-family marker only; preserve B004 no-monolithic-body decision and raw no-route roles. |
| `0000XL` | [0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md) | First-draft exact file-local helper `static int __stdcall GetMiniMapControlLayout(short, RectBounds *)` with the recovered rectangle table. |
| `0000XN` | [0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) | Aggregate marker only; exact downloader child split plan is documented, but no method/helper body is promoted in this empty-emitter pass. |
| `0000XO` | [0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) | Aggregate/source-family marker only; preserve B007 image/renderer/symbol/helper split-index decision. |
| `0001ZZ` | [0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md) | Helper-island marker only; exact loader child split plan is documented and body promotion is excluded until `MiniMapFileLoader` fields and `.mnm` record names are accepted. |
| `00044U` | [0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString](by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md) | Shared-resource literal marker; source use belongs at FrameChrome, MapNamePane, and MiniMapButtonPane paint sites, not a standalone MiniMap-owned global string. |

The current-pass source-file split decision is also closed for implementation: keep the active output as `auto-generated/NexusTK/map/MiniMap.cpp` and do not create `MiniMapDialog.cpp`, `MiniMapRenderer.cpp`, or `MiniMapDownloader.cpp` in this callback. Broader source-file decomposition is outside this empty-emitter assignment and should not block the formal marker/global/helper repairs.

Exact child split plans are now implementation-ready, but excluded from this callback unless the supervisor authorizes split creation:

| Aggregate | Exact child ranges and current-pass exclusion |
| --- | --- |
| [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) | Constructor `0x00453910-0x00453985`, destructor `0x00453990-0x004539e1`, `OnThreadTask` `0x00453a00-0x00453a2f`, `DownloadMinimap_453AA0` `0x00453aa0-0x00453d4f`, clear helper `0x00453d50-0x00453d5b`, scalar deleting destructor `0x00453d60-0x00453def`. Bodies are excluded because Thread API names, task type/path/code fields, WinINet wrapper names, and compiler/EH cleanup status are not accepted at child-body quality. |
| [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) | Image-control methods `0x00453df0-0x00453e87`, `0x00453e90-0x00453eaf`, `0x00453eb0-0x00453ed0`; image-control compiler glue `0x00453ed0-0x00453ee6`, `0x00453ef0-0x00453f45`; renderer constructor/destructor `0x00453f50-0x00454008`, `0x00454010-0x00454071`; renderer accessors/update/version helpers `0x00454080-0x00454087`, `0x00454090-0x00454094`, `0x004540a0-0x00454143`, `0x00454150-0x004543ec`, `0x00454d80-0x00454e2f`; `BuildSymbolViews` `0x004543f0-0x00454bac`; raw downloader candidate `0x00454e30-0x00455041`; renderer-local vector helper buckets `0x004550d0-0x00455e52`; symbol-control methods `0x00455e60-0x00456031`, `0x00456040-0x0045609e`, `0x004560a0-0x004560e1`, `0x004560f0-0x00456175`, `0x00456180-0x00456293`, `0x004562a0-0x004562f8`, `0x004563b0-0x004563b5`; symbol-control compiler glue `0x004562f8-0x0045630e`, `0x00456310-0x004563af`. Bodies are excluded because record-vector layouts, shared 24-byte string-vector ownership, raw `0x00454e30` no-route status, base order, and `+0x210/+0x214` coordinate order are not final-source quality. |
| [UID:0001ZZ][0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md) | Constructor `0x00457620-0x004576a6`, destructor `0x004576b0-0x00457757`, raw reset helper `0x00457760-0x00457780`, raw transform/write helper `0x00457780-0x00457842`, load `0x00457850-0x00457953`, decode `0x00457960-0x00457a5d`. Bodies are excluded because the two raw helpers have no IDA function objects or direct xrefs, and loader field names plus `.mnm` header/version names remain unresolved. |

Rejected alternatives for this implementation are explicit: no monolithic file-root body, no class declaration shells, no class-page method bodies, no aggregate bodies for [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)/[UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md)/[UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)/[UID:0001ZZ][0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md), no source-emitting children for raw labels `0x004517a0`, `0x00452ce0`, `0x00452ea0`, `0x00454e30`, `0x00457760`, or `0x00457780`, no duplicate `GetMiniMapControlLayout` body on the by-global alias, no MiniMap-owned `FRMPART.PAL` global, and no migration of MiniMap downloader/renderer/file-loader workflows into generic `VectorHelpers` or runtime-only support docs.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The file now records the dialog, renderer/control, downloader, version-manager, button-pane, layout, singleton, `.rdata`, raw downloader-helper evidence, and the accepted B010 empty-emitter disposition map with exact formal marker/global/helper routes. It remains below final-audit range because class declarations, downloader task fields, `.mnm`/symbol-record layouts, renderer record-vector fields, and split child pages are not final-source quality. |
| Confidence | 89 | Live IDA/PE and B010 MCP evidence agree on the MiniMap source-family route, exact helper/global storage, raw no-route labels, shared-resource exclusions, and no-monolithic-body policy. Confidence stays short of final-source quality because detailed child bodies and original source-file decomposition still require accepted split/layout work. |

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
- [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Before: `86/88`; the file documented MiniMap ownership but still had generic open-question wording around source split, class declarations, helper bodies, and `.mnm`/record layout blockers.
  - After: `87/89`; added the accepted empty-emitter source-disposition section, mapped all 18 previously empty emitters to exact formal body/marker outcomes, preserved the one filled [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) destructor body, kept `MiniMap.cpp` as the active source root for this callback, converted child-body blockers into exact split plans/current-pass exclusions, and documented rejected monolithic/class/aggregate/raw/global-string/generic-helper alternatives.
- 2026-06-21 B007 MiniMapRendererAndControls Rule 26 sync:
  - Score unchanged at `86/88`.
  - Updated the renderer row to name `ImageDecodeWrappers`, added source-family split guidance, closed `0x004540a0`/`0x004560f0` as generic-name blockers, refined the raw `0x00454e30` no-code/conceptual-name decision, and narrowed the remaining open questions to record layouts, raw-helper reachability, image/render helper names, and final source split.
- 2026-06-20 B005 MiniMapSymbolControlPane support sync:
  - Score unchanged at `86/88`.
  - Updated the class inventory and IDA evidence for `MiniMapSymbolControlPane::SetCenterPosition`, the `0x00452ea0` MiniMapDialog positioning chain, and the source split policy. The final file may still be a compact `MiniMap.cpp` or focused `MiniMapDialog.cpp`/`MiniMapRenderer.cpp` plus private controls.
- 2026-06-20 B005 MiniMapButtonPane Rule 26 split sync:
  - Score unchanged at `86/88`.
  - Updated the MiniMapButtonPane inventory so [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) is a non-emitting split index, [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md) is the exact singleton-clear helper, [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) is the ordinary destructor source body, and [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md)/[UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) are compiler-generated destructor glue. The file route remains valid for source-bearing MiniMapButtonPane children, not for mixed helper/thunk ranges.
- 2026-06-18 B001 FileDownloader support sync: added the FileDownloader message `10000` worker distinction for `DownloadMinimapFile`, preserving MiniMap as request/resource feature context while rejecting MiniMap/MiniMapDownloader as the emitter for the `0x0041a750` worker body.

- 2026-06-16 A001 Goal 2 file completion refresh:
  - Before: `85/86`; the file already cleared the parent gate but still carried older evidence and unresolved raw-helper/source-split blockers.
  - After: `86/88`; added live IDA/PE evidence for main function inventory, `g_pMiniMapDialog` references, raw generated starts, the `0x00454e30` WinINet/minimap download helper, and the specific source-quality blockers that remain.
  - Summary/evidence: active IDA/PE checks confirmed raw starts `0x004517a0`, `0x00452ce0`, and `0x00454e30` are not modeled function starts and have no direct pointer/branch reachability, while `0x00454e30` disassembly still proves minimap download semantics. No IDA database edit or final C++ was made because final helper names and compact-versus-split source shape remain unresolved.
- 2026-06-07 A010 Batch032 parent-gate update:
  - Before: `82/84`; strong minimap-family evidence existed, but the corrected 85/85 gate blocked `MiniMapDialog` assignment.
  - After: `85/86`; added the live `g_pMiniMapDialog` constructor/destructor/helper/consumer evidence to the file-root record. This supports the current file root for parent-chain routing, while final `MiniMapDialog.cpp` versus compact `MiniMap.cpp` remains open and no final C++ was emitted.
- 2026-06-12 A001 Batch 271:
  - Score unchanged at `85/86`.
  - Added the exact [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) `MMAPBUT.EPF` evidence for `MiniMapButtonPane`, while preserving the parentless mixed-string-child decision.
- 2026-06-12 A004 Batch 254 read-only-data split note:
  - Score unchanged at `85/86`.
  - Added [UID:0003FP][0x006104f4-0x006108d4.MiniMapUiReadOnlyData](by-memory/0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md) as the exact MiniMap-owned `.rdata` child after live IDA confirmed the `0x006108d4` split from MiniMapVersionManager data.
- 2026-06-05: Filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/map/`.
  - Reason: `by-project-structure/proposed-source-tree.md` already places the MiniMap source family under map, and the linked IDA-backed minimap dialog/control, downloader, and `GetControlLayout_452260` caller evidence supports this source owner. This also makes the file root valid for child autogen attachment; completion/confidence scores were not changed.
- 2026-06-06 parent-chain evidence sync:
  - What existed before: the file was scored `78/82`, which kept [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md) from attaching to the staged minimap source root despite strong global/storage evidence.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: the file now explicitly carries the downloader singleton storage, constructor/destructor/helper clear evidence, exact memory/global pages, existing dialog/renderer/version-manager split notes, and the final `MiniMapDownloader.cpp` versus compact `MiniMap.cpp` caveat. This clears the 80/80 gate for global attachment without emitting final C++.
- 2026-06-07 A009 Batch 001 memory-child assignment:
  - What changed: [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) and [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) now use this file root as their documented owner/emitter route.
  - Summary/evidence: live IDA MCP reconfirmed the downloader direct minimap task path, WinINet/file callee set, renderer/control method starts, MiniMapDialog construction callers, and renderer support-helper split. This reduces unassigned minimap memory coverage while keeping final C++ blank and preserving the `MiniMapDownloader.cpp`/`MiniMapRenderer.cpp` versus compact `MiniMap.cpp` decision.
- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page had strong feature-grouping evidence but was still unevaluated by the completion/confidence header.
  - After: score reflects documented minimap dialog, renderer, downloader, version-manager, button-pane, control, file-loader, global, and read-only-data relationships while retaining open questions about exact original source split and `.mnm` format details.
  - Evidence: cross-linked IDA MCP notes on the dialog/control island, renderer construction, version-manager startup and lookup calls, downloader callers, and minimap resource/config usage are already recorded in this page and its linked memory/class pages.
- 2026-05-27: Updated MiniMap renderer/control and version-manager boundary text from `0x004563b4`/`0x00457546` to `0x004563b5`/`0x00457547`. Evidence: IDA MCP reports `sub_4563B0` ending at `0x004563b5` and `sub_457480` ending at `0x00457547`; both previous ranges omitted final `retn` immediate bytes.
- 2026-05-28: Updated `MiniMapButtonPane` local range from `0x00503580-0x0050395e` to `0x00503580-0x0050395f`. Evidence: IDA MCP reports `sub_503900` ending at `0x0050395f`; the previous end omitted the final `retn 4` immediate byte.
