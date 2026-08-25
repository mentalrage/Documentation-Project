** TARGET-REPORT-UID:0000XO **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 Research Report: [UID:0000XO] MiniMapRendererAndControls

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0000XO-MiniMapRendererAndControls-source-quality.md`  
Target path: `source-3/project-documentation/by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`  
Assignment: B007-goal2 MiniMap renderer/control aggregate source-quality pass, report-only.  
Status: research complete; no target/support by-* docs were edited; `by-memory/-coverage-report.md` was not edited.

## Current Recommendation

Keep [UID:0000XO] as a MiniMap source-family aggregate and split/describe it as class methods plus compiler/container support, not as one emit-ready C++ translation unit. The aggregate is source-authored overall, but its formal C++ block should remain blank until the supervisor chooses child emission scopes. The strongest route is:

- `MiniMapImageControlPane` methods emit with [UID:0000LE] `MiniMap`, likely source file `NexusTK/map/MiniMapRenderer.cpp` or compact `NexusTK/map/MiniMap.cpp`.
- `MiniMapRenderer` methods emit with [UID:0000LE] `MiniMap`; direct renderer methods are mostly source-ready, but `BuildSymbolViews` still needs final symbol-record type names before formal C++.
- `MiniMapSymbolControlPane` methods emit with [UID:0000LE] `MiniMap`; constructor/animation/draw/position methods are source-ready enough for a later child-page first draft if field names are accepted.
- The raw `0x00454e30` WinINet body is source-shaped and MiniMap-local, but should not emit C++ and should not be made a normal method page yet. It has no modeled function object and no incoming reachability to its start. The best high-probability conceptual name, if a later IDA/function-repair pass proves liveness, is `MiniMapRenderer::DownloadCurrentMapFile()` or `MiniMapRenderer::DownloadMapImageFile()`.
- The 80-byte and 108-byte record vector helpers are renderer-local support for `BuildSymbolViews`; the 24-byte wide-string vector helpers are shared support and must not be renamed as MiniMap methods.
- Recommended post-implementation score: raise target metadata from `86/88` to `88/90` after adding the omitted method rows, raw-helper proof, support-helper split policy, exact no-code/defer statement, and coverage row text. Keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000LE`, and `EMITTER_UIDS:0000LE`.

## Evidence Checked

- Target doc `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`.
- Support docs:
  - `by-file/MiniMap.md`
  - `by-class/MiniMapRenderer.md`
  - `by-class/MiniMapImageControlPane.md`
  - `by-class/MiniMapSymbolControlPane.md`
  - `by-class/MiniMapDialog.md`
  - `by-memory/0x00450ca0-0x00453de0.MiniMapDialog.md`
  - `by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md`
  - `by-class/MiniMapVersionManager.md`
  - `by-file/MiniMapVersionManager.md`
  - `by-global/g_pMiniMapVersionManager.md`
  - `by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md`
  - `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`
  - `by-memory/0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md`
  - `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
  - `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
  - `by-file/FileDownloader.md`
  - `by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md`
  - `by-memory/0x0041b180-0x0041b41c.SubmitMinimapRequest.md`
  - `by-memory/0x0060d8c8-0x0060d8d0.DownloaderMessageIds.md`
- Coverage rows:
  - `by-memory/-coverage-report.md` current [UID:0000XO] row.
  - `by-file/-coverage-report.md` current [UID:0000LE] row.
  - `auto-generated/-ag-memory-coverage.md` route for the target.
- Generated/leads, used only as evidence to check against IDA listings:
  - `source-3/simroot_v2/class_MiniMapRenderer.cpp`
  - `source-3/simroot_v2/class_MiniMapImageControlPane.cpp`
  - `source-3/simroot_v2/class_MiniMapSymbolControlPane.cpp`
  - `source-3/simroot_v2/MiniMap.cpp`
  - `source-3/simroot_v2/DownloadMinimap_00453AA0.cpp`
  - `source-3/simroot_v2/DownloadMinimapFile_0041A750.cpp`
- Local IDA exports/listings:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`
- Text/xref searches for `0x00454e30`, `0x004540a0`, and `0x004560f0` across by-memory/by-class/by-file/by-global docs.

## Boundary And Inventory

The aggregate boundary `0x00453df0-0x004563b5` is still correct as a covered source-family range. There is padding before and after it: the prior region ends at `0x00453de0`, there is padding into `0x00453df0`, and the next modeled target starts at [UID:0000XI] `0x004563c0-0x00457547.MiniMapVersionManager.md`. The terminal helper `0x004563b0` returns at `0x004563b5`; the bytes `0x004563b5-0x004563c0` are alignment/padding.

The current target method/support table is incomplete. It lists the major functions, but omits three modeled source functions and several local support helpers:

| Range/start | Recommended role/name | Evidence and action |
|---|---|---|
| `0x00453df0-0x00453e87` | `MiniMapImageControlPane::MiniMapImageControlPane(void *imageHandle, const Rect *bounds)` | Existing row is good. Constructor calls the pane/control base with control type/flags `8`, installs three vtable slots, stores the image handle at `+0x14c`, clears image state around `+0x108..+0x148`, and applies initial visibility/enabled state through the shared control helper. |
| `0x00453e90-0x00453eaf` | `MiniMapImageControlPane::~MiniMapImageControlPane()` ordinary destructor | Missing in target and `by-class/MiniMapImageControlPane.md`. `.lst` has `sub_453E90 proc` and a tail `jmp sub_544580` at `0x00453eaa`, with alignment at `0x00453eaf`. This is the ordinary destructor that scalar deleting destructor `0x00453ef0` wraps. Add it to target/class docs; emit ordinary destructor in source if a child page is made. |
| `0x00453eb0-0x00453ed0` | `MiniMapImageControlPane::OnPaint()` | Existing row is good but should use half-open `0x00453ed0`. It checks stored image handle at `+0x14c` and blits through `dword_69B3E8(image, image+0x10, this+0x44, 0, 0, 0)`. Generated fitting-room names are pollution. |
| `0x00453ed0-0x00453ee6` | adjustor/vtable thunks | Compiler-generated glue, no source C++. |
| `0x00453ef0-0x00453f45` | scalar deleting destructor | Compiler-generated glue. It restores vtables, calls ordinary destructor/base teardown, and conditionally deletes when `(flags & 1) != 0 && (flags & 4) == 0`. Source responsibility is the ordinary destructor, not this wrapper. |
| `0x00453f50-0x00454008` | `MiniMapRenderer::MiniMapRenderer()` | Existing row is good. Initializes path/code buffers, `EPFTileContext`/tile context at `+0x234`, current map id `+0x25c`, title buffer at `+0x260`, and vector/state fields around `+0x2a8..+0x2cc`. |
| `0x00454010-0x00454071` | `MiniMapRenderer::~MiniMapRenderer()` | Existing row should correct exclusive end from `0x00454070` to `0x00454071`. It releases tile context, frees the 108-byte record vector with nested string vectors, and frees the 80-byte record vectors. |
| `0x00454080-0x00454087` | `wchar_t *MiniMapRenderer::GetMapCodeBuffer()` | Existing row is good. Returns `this + 0x20a`; source name should drop address suffix. |
| `0x00454090-0x00454094` | `wchar_t *MiniMapRenderer::GetMapPathBuffer()` | Existing row is good. Returns `this + 0x02`; source name should drop address suffix. |
| `0x004540a0-0x00454143` | `MiniMapRenderer::UpdateViewOriginFromPlayer()` or `UpdateViewOffsetsFromPlayer()` | Missing in target and `by-class/MiniMapRenderer.md`. `.lst` has modeled `sub_4540A0`; `MiniMapDialog` calls it at `0x00452ee9`, immediately before it updates symbol controls. It calls the active-character/map position helper via `dword_67A748`/`sub_5374D0`, reads map tile pixel globals `word_66DA9C`/`word_66DAA0`, and stores normalized view offsets at renderer `+0x2a0/+0x2a4`. Recommended final source name: `UpdateViewOriginFromPlayer`, confidence high. |
| `0x00454150-0x004543ec` | `bool MiniMapRenderer::PrepareMapFileAndCheckVersion(int mapId)` | Existing source-facing name is acceptable. It stores map id, formats the 6-character code in `+0x20a`, prepares `%Documents%\NexusTK\MiniMapImages\%s.mnm` in `+0x02`, creates directories, opens the local file, and compares the 0x21-wide header against `MiniMapVersionManager::GetExpectedVersionForMapId(mapId)`. |
| `0x004543f0-0x00454bac` | `bool MiniMapRenderer::BuildSymbolViews(int mapId)` | Existing name is acceptable. It constructs `MiniMapFileLoader`, decodes the minimap image through [UID:0002TM] `Decode8BitBmpToTileContext`, parses title/symbol/label records, populates 80-byte/108-byte record vectors plus shared small-wide-string vectors, then recomputes view offsets. Formal C++ remains blocked by final record type names. |
| `0x00454d80-0x00454e2f` | `bool MiniMapRenderer::HasCurrentVersion() const` | Existing row is good. It reopens the renderer map path, reads the 0x21-wide version header, compares against version manager lookup for `+0x25c`, and treats missing expected version as success. |
| raw `0x00454e30`, returns at `0x00455040`, alignment at `0x00455041` | raw MiniMap WinINet download body, conceptual `MiniMapRenderer::DownloadCurrentMapFile()` if later proven live | Source-shaped but not a modeled function. See raw-helper section below. Keep inside target as a caveat, no formal C++. If a future split uses strict half-open notation, the physical child range should include the return byte through `0x00455041`; existing docs currently describe the body as `0x00454e30-0x00455040` because the return is at `0x00455040`. |
| `0x00455050-0x00455053` | tiny `return true` helper | Modeled helper after raw body. No source-facing MiniMap method proven; list as local support/stub only if target inventory expands. |
| `0x00455060-0x004550c8` | `DestroySmallWideStringRange` | Modeled support helper that destroys/reset 24-byte small-wide-string records over a range. Shared container/string support, not a MiniMap method. |
| `0x004550d0-0x004551df` | 80-byte record vector insert/grow helper | Renderer-local vector support called from `BuildSymbolViews`; source-facing container support, not a class method. Suggested doc name: `MiniMapViewRecord80VectorInsert`. |
| `0x004551e0-0x00455349` | 108-byte record vector insert/grow helper | Renderer-local vector support called from `BuildSymbolViews`; likely symbol/label view record vector. Suggested doc name: `MiniMapSymbolViewRecordVectorInsert`. |
| `0x00455350-0x004554df` | 24-byte small-wide-string vector insert/grow helper | Shared support. Called by MiniMap `BuildSymbolViews` and non-MiniMap string/vector paths. Suggested doc name: `SmallWideStringVectorInsert`; do not route as MiniMap-owned method. |
| `0x004554e0-0x00455521` | 80-byte record copy/move helper | Local support child inside the 80-byte vector cluster. |
| `0x00455530-0x00455594` | 80-byte record range copy helper | Local support child inside the 80-byte vector cluster. |
| `0x004555a0-0x004555f4` | 108-byte record range copy helper | Local support child inside the 108-byte vector cluster; preserves nested small-string/vector members. |
| `0x00455600-0x0045578d` | 24-byte small-wide-string vector copy/clone helper | Shared support. Existing row is good but should explicitly say shared, not renderer-owned. |
| `0x00455790-0x004557c7` | 108-byte record destructor helper | Local vector support, used by 108-byte vector cleanup/exception paths. |
| `0x004557f0-0x00455851` | 80-byte vector storage release/assign helper | Local support; destructor calls it for the 80-byte vectors. |
| `0x00455860-0x004558c9` | 108-byte vector storage release/assign helper | Local support; destructor calls it for the 108-byte vector and nested string vectors. |
| `0x004558f0-0x00455964` | 80-byte vector assign/free helper | Local support for record vector ownership changes. |
| `0x00455970-0x004559e2` | 108-byte vector assign/free helper | Local support for record vector ownership changes. |
| `0x004559f0-0x00455a29` | 108-byte record range destructor | Local support; destroys nested string-vector members. |
| `0x00455a30-0x00455a32` | identity/exception-cleanup helper | Compiler/support artifact, not source-facing. |
| `0x00455a40-0x00455a8f` | 80-byte record vector reserve/copy helper | Renderer-local support. Existing row is good. |
| `0x00455a90-0x00455b34` | 108-byte record vector reserve/copy helper | Renderer-local support. Existing row is good. |
| `0x00455b40-0x00455bb5` | small-wide-string vector cleanup helper | Shared support; current caveat is correct. |
| `0x00455bc0-0x00455c72` | nested string-vector copy helper | Local/shared container support used by 108-byte record handling. |
| `0x00455c80-0x00455d30` | nested string-vector copy helper | Local/shared container support used by 108-byte record handling. |
| `0x00455d40-0x00455d9e` | 80-byte vector storage allocator | Local support allocator. |
| `0x00455db0-0x00455e0b` | 108-byte vector storage allocator | Local support allocator. |
| `0x00455e20-0x00455e52` | 108-byte vector storage free helper | Local support free helper. |
| `0x00455e60-0x00456031` | `MiniMapSymbolControlPane::MiniMapSymbolControlPane(...)` | Existing row is good, but the signature can now be more specific. See symbol-control section. |
| `0x00456040-0x0045609e` | `MiniMapSymbolControlPane::~MiniMapSymbolControlPane()` | Existing row is good. It releases sprite/tile contexts and timer/control resources. |
| `0x004560a0-0x004560e1` | `MiniMapSymbolControlPane::StartAnimation(int firstFrame, int lastFrame, int intervalMs)` | Existing row is good. |
| `0x004560f0-0x00456175` | `MiniMapSymbolControlPane::SetCenterPosition(int centerX, int centerY)` or `SetMapPosition(int x, int y)` | Missing in target and `by-class/MiniMapSymbolControlPane.md`. Called from `MiniMapDialog` at `0x00452f4e` after renderer offsets are updated. It stores the center/map position fields at `+0x210/+0x214`, recomputes bounds from current sprite dimensions, and calls the virtual bounds setter. Recommended final source name: `SetCenterPosition`; confidence medium-high because the function receives display center coordinates, not raw map tile coordinates. |
| `0x00456180-0x00456293` | `MiniMapSymbolControlPane::OnAnimationTick(...)` | Existing row is good. It reloads/cycles EPF frames, adjusts bounds on size changes, invalidates owner, and reschedules timer. Extra dispatcher args are unused. |
| `0x004562a0-0x004562f8` | `MiniMapSymbolControlPane::OnDraw()` | Existing row is good. It draws the base/palette-backed sprite and label/mask path. |
| `0x004562f8-0x0045630e` | adjustor/vtable thunks | Compiler-generated glue, no source C++. |
| `0x00456310-0x004563af` | scalar deleting destructor | Compiler-generated wrapper; source responsibility is ordinary destructor at `0x00456040`. |
| `0x004563b0-0x004563b5` | `MiniMapSymbolControlPane::GetControlType()` | Existing row is good; returns `23`. |

## Raw WinINet Body `0x00454e30`

The raw body is real source-authored MiniMap code, but it is not currently a safe source-emission unit.

Evidence:

- Existing MiniMap docs and support literal docs already record that live IDA did not model a function at `0x00454e30`.
- Target and support docs report no xrefs to `0x00454e30`, and no PE absolute-VA/RVA pointer encodings or direct branches to the raw start.
- Local `.c` export has no `sub_454E30` function; `.map` does not list a symbol for it.
- `.lst` shows source-shaped code at `0x00454e30`: stack-cookie prologue, `ecx` saved as the object pointer, `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, status check for HTTP 200, local file open/write loop, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `OutputDebugStringW`, cleanup, and partial-file deletion through `dword_69BE60`.
- The body reads renderer fields directly: map path at `this + 0x02` and map code buffer at `this + 0x20a`. It formats a URL using the MiniMap S3 prefix and `.mnm` suffix. It writes the downloaded file to the renderer's prepared local path.
- It differs from [UID:0000JC]/FileDownloader routes. `DownloadMinimapFile` at `0x0041a750` is a FileDownloader worker/helper with a request object and message route. `MiniMapDownloader` at `0x00453aa0` is a modeled MiniMapDownloader worker route. The raw `0x00454e30` body is a direct renderer-side downloader shape with no proven caller.

Best inference:

- If a future IDA/function-repair pass proves reachability, the source-facing method should be a private renderer helper such as `bool MiniMapRenderer::DownloadCurrentMapFile()` or `bool MiniMapRenderer::DownloadMapImageFile()`.
- Do not rename it to `DownloadMinimapFile`; that name is already better reserved for the FileDownloader helper at `0x0041a750` and would hide the different caller/request shape.
- Do not currently emit a formal C++ block for it. The no-code proof is target-specific: no modeled function, no start xrefs, no pointer/branch hits, no exported subroutine, and no direct caller to anchor signature or liveness. The source-shaped body should be described as a raw MiniMap-side support/download body and left inside [UID:0000XO] unless the supervisor authorizes an exact raw child split.

Range note:

- Current docs say `0x00454e30-0x00455040`; the listing shows the `retn` byte at `0x00455040` and alignment at `0x00455041`. If the project later creates a child with strict half-open range notation, use `0x00454e30-0x00455041` or explicitly describe `0x00455040` as the return address. The current target aggregate already covers the byte, so no coverage split is required for this report.

## Class And Source-Facing Names

### MiniMapImageControlPane

High-confidence source shape:

```cpp
MiniMapImageControlPane::MiniMapImageControlPane(void *imageHandle, const Rect *bounds);
MiniMapImageControlPane::~MiniMapImageControlPane();
void MiniMapImageControlPane::OnPaint();
```

Field/name recommendations:

- `m_imageHandle` or `m_image` at `+0x14c`; confidence high for role, medium for exact type.
- The state cleared around `+0x108..+0x148` is image/blit state. Do not force a type until shared image helper docs name it.
- `OnPaint` should not mention fitting-room helpers. Generated fitting-room casts are stale owner/name pollution from shared pane helper output.

First-draft child C++ readiness:

```cpp
void MiniMapImageControlPane::OnPaint()
{
    if (m_imageHandle != NULL)
        g_graphics->DrawImage(m_imageHandle, m_imageHandle->GetBounds(), GetClientRect(), 0, 0, 0);
}
```

This is source-style only; final code should replace `void *`/`g_graphics`/`GetBounds` with the project-approved image and draw helper names. The child page can emit once those names are locally standardized.

### MiniMapRenderer

High-confidence source shape:

```cpp
MiniMapRenderer::MiniMapRenderer();
MiniMapRenderer::~MiniMapRenderer();
wchar_t *MiniMapRenderer::GetMapCodeBuffer();
wchar_t *MiniMapRenderer::GetMapPathBuffer();
void MiniMapRenderer::UpdateViewOriginFromPlayer();
bool MiniMapRenderer::PrepareMapFileAndCheckVersion(int mapId);
bool MiniMapRenderer::BuildSymbolViews(int mapId);
bool MiniMapRenderer::HasCurrentVersion() const;
```

Recommended field names:

- `m_mapPath` at `+0x02`; wide path buffer used by prepare/version/raw download paths.
- `m_mapCode` at `+0x20a`; 6-character map code buffer used by URL/path formatting.
- `m_mapWidth`/`m_mapHeight`/`m_tileStrideOrImageSize` around `+0x218/+0x21c/+0x220`; exact names should be taken from `.mnm` header parsing in `BuildSymbolViews`.
- `m_tileContext` at `+0x234`; support docs should use `EPFTileContext`/tile context wording consistently with `MiniMapFileLoaderHelpers` and [UID:0002TM].
- `m_mapId` at `+0x25c`.
- `m_titleText[32]` at `+0x260`.
- `m_viewOriginX`/`m_viewOriginY` or `m_normalizedViewX`/`m_normalizedViewY` at `+0x2a0/+0x2a4`; confidence high for role, medium for exact source spelling.
- `m_symbolRecords` and `m_labelRecords` for the 80-byte/108-byte vectors. Do not freeze exact type names until the record layouts in `BuildSymbolViews` are documented. The 108-byte records own nested 24-byte small-wide-string vectors.

`0x004540a0` source-name decision:

- Preferred: `UpdateViewOriginFromPlayer()`.
- Rejected: `CenterOnPlayer()` is too UI-specific because the function only computes renderer offsets and does not directly move child controls.
- Rejected: `UpdateMapPosition()` is too broad and conflicts with the symbol-control position helper.
- Evidence: direct call from `MiniMapDialog` after renderer build/update logic, use of `dword_67A748` current-character/map position helper, use of map tile pixel globals, and stores to renderer offsets `+0x2a0/+0x2a4`.

First-draft child C++ readiness for simple renderer methods:

```cpp
wchar_t *MiniMapRenderer::GetMapCodeBuffer()
{
    return m_mapCode;
}

wchar_t *MiniMapRenderer::GetMapPathBuffer()
{
    return m_mapPath;
}

void MiniMapRenderer::UpdateViewOriginFromPlayer()
{
    Point mapPos;

    g_playerContext->GetMapPosition(&mapPos);
    m_viewOriginX = (mapPos.x - m_mapOriginX) * m_mapScaleX / g_mapTilePixelWidth;

    g_playerContext->GetMapPosition(&mapPos);
    m_viewOriginY = (mapPos.y - m_mapOriginY) * m_mapScaleY / g_mapTilePixelHeight;
}
```

This draft captures the source shape but should not be pasted into the aggregate. It needs final names for `g_playerContext`, `m_mapOriginX/Y`, and `m_mapScaleX/Y` before a child page emits.

`PrepareMapFileAndCheckVersion` and `HasCurrentVersion` are also first-draft eligible as child pages because the behavior and version-manager route are now stable. `BuildSymbolViews` should not emit yet because the source-quality blockers are record type names and vector member names, not behavior.

### MiniMapSymbolControlPane

High-confidence source shape:

```cpp
MiniMapSymbolControlPane::MiniMapSymbolControlPane(
    const wchar_t *label,
    int symbolType,
    const Point *center,
    const wchar_t *epfFileName,
    short initialFrame,
    bool visible,
    const wchar_t *paletteName);

MiniMapSymbolControlPane::~MiniMapSymbolControlPane();
void MiniMapSymbolControlPane::StartAnimation(int firstFrame, int lastFrame, int intervalMs);
void MiniMapSymbolControlPane::SetCenterPosition(int centerX, int centerY);
bool MiniMapSymbolControlPane::OnAnimationTick(int eventId, int unused1, int unused2);
void MiniMapSymbolControlPane::OnDraw();
unsigned char MiniMapSymbolControlPane::GetControlType() const;
```

Recommended field names:

- `m_symbolType` at `+0x130`; constructor stores the second integer argument here.
- `m_epfFileName` at `+0x13c`.
- `m_paletteName` at `+0x17e`; defaults to `BARAM.PAL` when the constructor palette argument is null.
- `m_label` or `m_symbolName` at `+0x1be`; copied with `_wcscpy_s(..., 0x20)`.
- `m_animationEnabled` at `+0x1fe` or nearby byte state; exact byte offset should be checked in the child pass because the decompiler names it as a byte around the frame fields.
- `m_firstFrame`, `m_lastFrame`, `m_currentFrame`, and `m_timerIntervalMs` around `+0x200/+0x204/+0x208/+0x20c`.
- `m_centerX`/`m_centerY` at `+0x210/+0x214`; the setter argument order needs one final child-level check because the decompiler stores `a2/a3` into adjacent dwords and then recomputes a centered rectangle.

`0x004560f0` source-name decision:

- Preferred: `SetCenterPosition(int centerX, int centerY)`.
- Acceptable alternative: `SetMapPosition(int x, int y)` if support docs decide these are already minimap-display coordinates.
- Rejected: `MoveTo()` is too generic and hides the centered-bounds recomputation around the sprite dimensions.
- Evidence: direct call from `MiniMapDialog` after `MiniMapRenderer::UpdateViewOriginFromPlayer`, stores the two position dwords, computes `left/top/right/bottom` from current sprite dimensions, and calls the virtual bounds setter.

First-draft child C++ readiness:

```cpp
void MiniMapSymbolControlPane::StartAnimation(int firstFrame, int lastFrame, int intervalMs)
{
    m_firstFrame = firstFrame;
    m_lastFrame = lastFrame;
    m_currentFrame = firstFrame;
    m_timerIntervalMs = intervalMs;
    m_animationEnabled = true;
    m_timer.Start(intervalMs);
}

void MiniMapSymbolControlPane::SetCenterPosition(int centerX, int centerY)
{
    m_centerX = centerX;
    m_centerY = centerY;

    Rect bounds;
    bounds.left = centerX - m_spriteBounds.Width() / 2;
    bounds.top = centerY - m_spriteBounds.Height() / 2;
    bounds.right = bounds.left + m_spriteBounds.Width();
    bounds.bottom = bounds.top + m_spriteBounds.Height();
    SetBounds(&bounds);
}
```

This is ready as a child-page draft after final member names are accepted. It should not be placed in the aggregate target.

## Renderer Support Helpers And Split Policy

Recommended helper routing:

- `0x004550d0`, `0x00455a40`, `0x00455d40`, and associated 80-byte copy/free helpers are renderer-local record-vector support. They can be described in the target and `MiniMapRenderer` class page as `MiniMapViewRecord80Vector*` helpers. They are not handwritten `MiniMapRenderer` methods.
- `0x004551e0`, `0x00455790`, `0x00455860`, `0x00455970`, `0x004559f0`, `0x00455a90`, `0x00455db0`, and `0x00455e20` are renderer-local 108-byte record-vector support. These records own nested 24-byte small-wide-string vector members and are likely symbol/label view records. Do not emit until the record layouts are named.
- `0x00455350`, `0x00455600`, `0x00455b40`, and `0x00455060` are shared 24-byte small-wide-string vector support. Evidence includes non-MiniMap callers noted in the target and support docs. These should route to shared string/vector support if split, not to MiniMap.
- `0x00455050` and `0x00455a30` are tiny support artifacts/exception helpers. They should be recorded as modeled starts only if the inventory is expanded; do not create source-facing names beyond a factual role note.

Recommended child split, if the supervisor wants exact split pages later:

- Keep `0x00453df0-0x00453f45` under a `MiniMapImageControlPane` child or class-method grouping, with ordinary destructor added.
- Keep `0x00453f50-0x00454e2f` under a `MiniMapRenderer` child/class grouping, adding `0x004540a0`.
- Do not split `0x00454e30` yet. If forced, create a raw/no-code child named `MiniMapRendererRawDownloadCurrentMapFile` with the no-xref proof and the return-address range note.
- Keep `0x00455050-0x00455e52` documented as support-helper cluster unless a dedicated vector-support audit is assigned. If split, separate renderer-local 80/108-byte vector support from shared small-wide-string vector support.
- Keep `0x00455e60-0x004563b5` under a `MiniMapSymbolControlPane` child/class grouping, adding `0x004560f0`.

## Version Manager And File Loader Routing

The target should keep linking version logic to [UID:0000XQ] `MiniMapVersionManager::GetExpectedVersionForMapId(int mapId) const`, not to renderer-local lookup code.

Evidence:

- `PrepareMapFileAndCheckVersion` calls version lookup around `0x0045433c` after building the local `.mnm` path.
- `HasCurrentVersion` calls the same lookup around `0x00454dad` using the renderer's current map id at `+0x25c`.
- [UID:0000XQ] has a settled first-draft C++ body using `m_versionIndex.FindNodeByKey(mapId)`, list-head sentinel, and `expectedVersionString`.
- This proves the source route: `MiniMapRenderer` asks `MiniMapVersionManager`; it does not own the version map or declaration.

The target should also tie `BuildSymbolViews` to [UID:0001ZZ] `MiniMapFileLoaderHelpers` and [UID:0002TM] `Decode8BitBmpToTileContext`:

- Loader object fields at `+0x00`, `+0x18`, `+0x30`, and `+0x34` represent path, expected version, payload pointer, and payload length.
- `.mnm` payload decode calls `Decode8BitBmpToTileContext` into the renderer's tile context.
- Symbol/label view vectors are renderer-owned outputs; loader construction/destruction and BMP decode are external helper routes.

## Rejected Alternatives

- Rejected aggregate-level formal C++: the range combines three classes, compiler thunks, scalar deleting destructors, vector/storage helpers, shared small-wide-string support, and a raw unreferenced downloader body. A single C++ block would be an artificial generated amalgam.
- Rejected FileDownloader ownership for `0x00454e30`: the raw body directly reads renderer map-code/path fields and has no FileDownloader request/message object. FileDownloader owns `0x0041a750` and related request helpers, not this raw body.
- Rejected treating `0x00454e30` as compiler glue: it is source-authored WinINet/file I/O logic with literals and cleanup paths. The no-code recommendation is due to reachability/signature proof, not because it is generated.
- Rejected naming 24-byte vector helpers as MiniMap helpers: the target and support docs record non-MiniMap callers. They are shared small-wide-string/vector support.
- Rejected leaving `0x004540a0` and `0x004560f0` as generic `sub_` blockers: both have modeled IDA functions, direct MiniMapDialog call sites, and clear side effects. They should be named and inventoried.
- Rejected keeping `MiniMapImageControlPane` scalar deleting destructor as the source destructor: the ordinary destructor at `0x00453e90` is the source destructor; the scalar wrapper is compiler glue.

## Recommended Target Doc Changes

Apply these only after supervisor implementation callback:

1. Header/metadata:
   - `COMPLETION: 88`
   - `CONFIDENCE: 90`
   - Keep `RECONSTRUCTABLE: TRUE`
   - Keep `CANONICAL_OWNER: 0000LE`
   - Keep `EMITTER_UIDS: 0000LE`
   - Keep formal C++ blank at aggregate level, with an explicit aggregate no-code/defer proof.

2. Add/repair method inventory rows:
   - Add `0x00453e90-0x00453eaf` as `MiniMapImageControlPane::~MiniMapImageControlPane`.
   - Correct `MiniMapImageControlPane::OnPaint` to half-open `0x00453eb0-0x00453ed0` if the row currently implies an inclusive end.
   - Correct `MiniMapRenderer::~MiniMapRenderer` to half-open `0x00454010-0x00454071`.
   - Add `0x004540a0-0x00454143` as `MiniMapRenderer::UpdateViewOriginFromPlayer`.
   - Add `0x004560f0-0x00456175` as `MiniMapSymbolControlPane::SetCenterPosition`.
   - Add an expanded support-helper table for the modeled starts from `0x00455050` through `0x00455e52`, or at minimum add a note that these additional modeled helpers exist and are covered by the support-helper cluster.

3. Update raw helper text:
   - State that `0x00454e30` is source-authored MiniMap WinINet download code, likely a private renderer method if later proven live.
   - State the exact no-code proof: no modeled function object, no start xrefs, no PE VA/RVA/direct-branch hits, no exported `sub_454E30`, no caller-owned signature.
   - State the range nuance: return at `0x00455040`, alignment at `0x00455041`.
   - Avoid final name `DownloadMinimapFile`; prefer conceptual `DownloadCurrentMapFile`/`DownloadMapImageFile`.

4. Update source-facing name/signature guidance:
   - Image control constructor: `MiniMapImageControlPane(void *imageHandle, const Rect *bounds)` until image type is named.
   - Renderer: add `UpdateViewOriginFromPlayer`, `GetMapCodeBuffer`, `GetMapPathBuffer`, `PrepareMapFileAndCheckVersion`, `BuildSymbolViews`, `HasCurrentVersion`.
   - Symbol control constructor with `label`, `symbolType`, `Point *center`, `epfFileName`, `initialFrame`, `visible`, `paletteName`; add `SetCenterPosition`.

5. Update source/C++ policy:
   - Say child methods are first-draft eligible, but aggregate formal C++ remains blank because this target is a cross-class/support-helper aggregate.
   - Say `BuildSymbolViews` is behavior-complete but C++ is still blocked by final record/vector type names.
   - Say scalar deleting destructors, adjustor thunks, and tiny support artifacts are no-code generated/support.

## Recommended Support Doc Changes

Apply these only after supervisor implementation callback:

- `by-file/MiniMap.md`
  - Add B007 2026-06-19 note that source split is now better resolved: image control, renderer, symbol control, renderer-local vector support, shared small-wide-string support, and raw `0x00454e30` no-code proof.
  - Update remaining blockers to remove generic helper-name blockers for `0x004540a0` and `0x004560f0`; the remaining blockers are record layout names and raw helper reachability.
  - Keep source route under `NexusTK/map/`, with likely split files `MiniMapRenderer.cpp`, `MiniMapDialog.cpp`, `MiniMapVersionManager.cpp`, `MiniMapDownloader.cpp`, or compact `MiniMap.cpp`.

- `by-class/MiniMapRenderer.md`
  - Add method row `0x004540a0-0x00454143` `UpdateViewOriginFromPlayer`.
  - Add field/source-name section for `m_mapPath`, `m_mapCode`, `m_tileContext`, `m_mapId`, `m_titleText`, `m_viewOriginX/Y`, and renderer-owned record vectors.
  - Explicitly route version lookup to `MiniMapVersionManager::GetExpectedVersionForMapId`.
  - Explicitly route `BuildSymbolViews` loader/decode helpers to `MiniMapFileLoaderHelpers` and `Decode8BitBmpToTileContext`.
  - Clarify raw `0x00454e30` is likely renderer-private but no-code/unreferenced.

- `by-class/MiniMapImageControlPane.md`
  - Add ordinary destructor `0x00453e90-0x00453eaf`.
  - Distinguish ordinary destructor from scalar deleting wrapper.
  - Add image handle field at `+0x14c`, confidence high for role but medium for type.
  - Remove or mark stale fitting-room/generated helper names as pollution.

- `by-class/MiniMapSymbolControlPane.md`
  - Add `0x004560f0-0x00456175` as `SetCenterPosition`/`SetMapPosition`.
  - Add constructor signature and fields listed above.
  - Clarify `StartAnimation`, `OnAnimationTick`, and `OnDraw` source shape.
  - Mark scalar deleting destructor/adjustor thunks as generated no-code.

- `by-memory/0x00450ca0-0x00453de0.MiniMapDialog.md` and `by-class/MiniMapDialog.md`
  - Update call-site notes: `0x00452ee9` calls `MiniMapRenderer::UpdateViewOriginFromPlayer`; `0x00452f4e` calls `MiniMapSymbolControlPane::SetCenterPosition`.
  - Preserve MiniMapDialog ownership and embedded renderer/control semantics.

- `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`
  - Add backlink that `MiniMapRenderer::BuildSymbolViews` is the direct consumer of loader construction/load/destruction and `Decode8BitBmpToTileContext`.

- `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` and `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
  - Keep no-owner/two-emitter policy.
  - Add the `0x00454e30` range nuance if desired: return at `0x00455040`, no strict child split yet.

## IDA Rename/Type/Comment Recommendations

No IDA DB edits were made. Recommended future comments/renames:

- Rename/comment `sub_453E90` as `MiniMapImageControlPane::~MiniMapImageControlPane`, confidence high.
- Rename/comment `sub_4540A0` as `MiniMapRenderer::UpdateViewOriginFromPlayer`, confidence high.
- Rename/comment `sub_4560F0` as `MiniMapSymbolControlPane::SetCenterPosition`, confidence medium-high.
- Keep `sub_453EF0` and `sub_456310` as scalar deleting destructor wrappers; generated no-code.
- Keep adjustor thunks around `0x00453ed0` and `0x004562f8` as generated thunk labels.
- Do not create a function at `0x00454e30` without a focused IDA/function-repair decision. If a comment is allowed without function creation, add: `raw MiniMap renderer-side WinINet download body, no xrefs/function object; uses this+0x02 path and this+0x20a map code`.
- Comment `0x00455060`, `0x00455350`, `0x00455600`, and `0x00455b40` as shared 24-byte small-wide-string vector support, not MiniMap methods.
- Comment `0x004550d0`/`0x00455a40`/`0x00455d40` cluster as 80-byte renderer record-vector support.
- Comment `0x004551e0`/`0x00455790`/`0x00455860`/`0x00455970`/`0x004559f0`/`0x00455a90`/`0x00455db0`/`0x00455e20` cluster as 108-byte renderer record-vector support with nested small-string/vector cleanup.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during research. If the supervisor accepts the implementation, replace the current [UID:0000XO] row with:

```md
    - [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) 0x00453df0-0x004563b5 | class aggregate | MiniMapRendererAndControls : reconstructable : 88% : very strong : B007 source-quality pass resolves the aggregate as a MiniMap source-family split index rather than one emit-ready class body; local export/listing checks add omitted ordinary/helper methods `0x00453e90`, `0x004540a0`, and `0x004560f0`, preserve class-owned renderer/image/symbol methods, route `MiniMapVersionManager::GetExpectedVersionForMapId` outside the renderer, classify `0x00454e30-0x00455040` as a source-shaped but unreferenced MiniMap-side WinINet body with no modeled function/entry xrefs and no formal C++, and split support helpers between renderer-local 80/108-byte vector support and shared 24-byte small-wide-string vector support.
```

No by-file coverage row change is required unless the supervisor updates `by-file/MiniMap.md` score. If it is updated, keep the MiniMap file row at `86%` or raise only after a broader MiniMap file audit; this target-level pass does not require it.

## Validator Commands Expected After Implementation

Run from `source-3/project-documentation` after the supervisor-authorized implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000XO-MiniMapRendererAndControls-source-quality-removed.md](0000XO-MiniMapRendererAndControls-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result for each command after implementation: `ok: 1` or equivalent file-scoped success with no UID/link/metadata errors. If a child page is created for the raw body or helper clusters, validate those child pages before validating `by-memory/-coverage-report.md`.

## Open Questions Closed Or Remaining

- Ordinary destructor placement: closed. `0x00453e90` is the source ordinary destructor for `MiniMapImageControlPane`; scalar wrapper remains generated glue.
- Renderer helper `0x004540a0`: closed to high probability. It is `MiniMapRenderer::UpdateViewOriginFromPlayer` or equivalent; not a generic blocker.
- Symbol helper `0x004560f0`: closed to medium-high probability. It is a centered-position setter for `MiniMapSymbolControlPane`.
- Raw `0x00454e30` liveness: closed for this pass as no-code/unreferenced. The body is source-shaped but not safe to emit because there is no function object or caller.
- Vector helper ownership: closed for target-level routing. 80/108-byte record-vector helpers are renderer-local support; 24-byte small-wide-string helpers are shared support.
- Exact symbol/vector record type names: still a legitimate blocker for `BuildSymbolViews` formal C++. Evidence checked above; safe final names require a focused record-layout child pass.
- Exact image handle type and graphics helper names: still require a shared graphics/image type naming pass, but this does not block documenting `MiniMapImageControlPane` behavior.
- Compact `MiniMap.cpp` versus split `MiniMapRenderer.cpp` source file: best current recommendation is split files under `NexusTK/map/`, but compact `MiniMap.cpp` remains plausible. This target should route to owner/emitter [UID:0000LE] either way.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000XO-MiniMapRendererAndControls-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000XO"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000XO-MiniMapRendererAndControls-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000XO-MiniMapRendererAndControls-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000XO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
