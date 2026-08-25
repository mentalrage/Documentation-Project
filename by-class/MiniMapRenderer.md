*** UID:00008F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapRenderer class declaration is intentionally withheld: the embedded runtime
// object and method inventory are documented, but renderer record-vector layouts,
// .mnm field names, and raw downloader-helper reachability are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapRenderer

## Status

- Confidence: strong for embedded-runtime role, method starts, MiniMapDialog call sites, version-manager dependency, and `.mnm` loader workflow; medium-high for exact helper ownership in the surrounding runtime-support gap.
- Direct source parent: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably a focused `map/MiniMapRenderer.cpp` split or a compact `map/MiniMap.cpp`.
- Main memory doc: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- Autogen status: reconstructable project class attached to the current [UID:0000LE][MiniMap](by-file/MiniMap.md) feature root; formal C++ is marker-only because field names, record layouts, and helper splits are not final-source quality.

## Class Purpose

`MiniMapRenderer` is the embedded runtime object used by [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) at offset `+0x1cc`. It owns the active map code/path buffers, tile context, loaded minimap document path, normalized view coordinates, symbol-view vector, label-view vector, and cached title text used by the dialog render/timer path.

Recommended source-facing field names after the B007 source-quality pass: `m_mapPath` at `+0x02`, `m_mapCode` at `+0x20a`, map dimension/header fields around `+0x218/+0x21c/+0x220`, `m_tileContext` at `+0x234`, `m_mapId` at `+0x25c`, `m_titleText[32]` at `+0x260`, and `m_viewOriginX`/`m_viewOriginY` or `m_normalizedViewX`/`m_normalizedViewY` at `+0x2a0/+0x2a4`. The path/code/id/title/tile-context roles are strong; the exact source spelling for the view-origin and record-vector fields remains medium because `BuildSymbolViews` still needs a focused record-layout pass.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00453f50-0x00454008` | constructor | Clears path/code buffers, initializes tile context state, and clears view/vector state. |
| `0x00454010-0x00454071` | destructor | Destroys tile context and frees renderer-owned symbol/label/view buffers. |
| `0x00454080-0x00454087` | `GetMapCodeBuffer` | Returns the short map-code buffer used for `.mnm` naming. |
| `0x00454090-0x00454094` | `GetMapPathBuffer` | Returns the full cached `.mnm` path buffer. |
| `0x004540a0-0x00454143` | `UpdateViewOriginFromPlayer` | Updates renderer view-origin/display-space offsets from current player/map position before dialog code positions the minimap image and symbol controls. |
| `0x00454150-0x004543ec` | `PrepareMapFileAndCheckVersion` | Formats map code/path under `NexusTK\MiniMapImages`, ensures the directory, and checks the cached file version. |
| `0x004543f0-0x00454bac` | `BuildSymbolViews` | Parses the loaded `.mnm` document, rebuilds symbol/label views, keyed lookup data, title text, and normalized view offsets. |
| `0x00454d80-0x00454e2f` | `HasCurrentVersion` | Opens the current `.mnm` file and compares its stored version header against [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) state. |

## Boundary Caveats

- The support helpers called by `BuildSymbolViews`, such as vector insertion/growth helpers and `MiniMapFileLoader` helpers around `0x004550d0-0x00455b40` and `0x00457620-0x00457850`, should not automatically become `MiniMapRenderer` methods. They are renderer-local candidates, but some have generic collection/string behavior and need a focused ownership pass.
- The dedicated file-loader helper island at [UID:0001ZZ][0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md) is semantically renderer-local because its constructor/destructor/load/decode functions are called by `MiniMapRenderer::BuildSymbolViews` and operate on `.mnm` documents consumed by this renderer. Batch 092 synced that helper page to the [UID:0000LE][MiniMap](by-file/MiniMap.md) source-file root after both the helper and direct file parent cleared the corrected 85/85 gate.
- The `0x0067a7dc` storage read by the renderer version checks is the minimap version-manager singleton slot used for expected-version lookup. Keep it with [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), not the renderer.
- `0x004570b0` is the manager-owned lookup helper used by `PrepareMapFileAndCheckVersion` and `HasCurrentVersion`; see [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md).
- The raw body at `0x00454e30` is likely a private renderer-side downloader such as `DownloadCurrentMapFile` only if a later IDA/function-repair pass proves liveness. It reads `this+0x02` and `this+0x20a`, formats the minimap S3 URL and `.mnm` suffix, and writes to the renderer path, but it is not currently safe to emit or rename as a method: no IDA function object, no start xrefs, no PE VA/RVA/direct-branch hits, no exported `sub_454E30`, and no caller-owned signature exist.

## Symbol Positioning Context

B005 2026-06-20 symbol-control reanalysis confirms `0x004540a0-0x00454143` as the renderer update immediately before symbol positioning. `MiniMapDialog` calls it at `0x00452ee9`, then calls the image-control position setter at `0x00452f3d` and [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) `SetCenterPosition` at `0x00452f4e`. The coordinates passed to the symbol control are therefore display-space centers after renderer view-origin conversion, not raw map tile coordinates.

## B010 Declaration-Shell Audit And C++ Disposition

Current evidence supports a class-index marker with `[[CHILDREN]]`, not a declaration shell or inline method snippets. MiniMapRenderer is an embedded runtime object, not currently a vtable-backed pane class; [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) constructs it at dialog offset `+0x1cc`. Known method inventory is constructor `0x00453f50`, destructor `0x00454010`, accessors `0x00454080` and `0x00454090`, `UpdateViewOriginFromPlayer` `0x004540a0`, `PrepareMapFileAndCheckVersion` `0x00454150`, `BuildSymbolViews` `0x004543f0`, and `HasCurrentVersion` `0x00454d80`, plus file-loader dependency [UID:0001ZZ][0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md).

The class declaration is intentionally withheld because renderer record-vector layouts, exact `m_viewOrigin*` spelling, 80-byte and 108-byte record fields, raw `0x00454e30` reachability, and `.mnm` format names remain unresolved. Accessors, view-origin update, prepare/version, and current-version helpers are later child-body candidates only if split creation is authorized and field names are accepted. `BuildSymbolViews` is behavior-complete but not source-ready; record layouts and `.mnm` names still block source-body promotion. The old source-style snippets are removed from this class page to keep C++ emission inside exact formal child pages.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:0001ZZ][0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000LE][MiniMap](by-file/MiniMap.md). This class is now scored `86/88`, and the direct file parent is scored `87/89`, so both sides satisfy the corrected 85/85 gate. The parent is direct because `MiniMap.md` owns the renderer/control aggregate, MiniMapDialog embeds this runtime object, and the file root explicitly preserves the current-pass compact `MiniMap.cpp` route without moving the class to version-manager or generic collection support.

## Batch 092 IDA Evidence

- Live IDA MCP reconfirmed renderer method bounds: constructor `0x00453f50-0x00454008`, destructor `0x00454010-0x00454071`, accessors `0x00454080-0x00454087` and `0x00454090-0x00454094`, prepare/version path `0x00454150-0x004543ec`, symbol-view builder `0x004543f0-0x00454bac`, and current-version check `0x00454d80-0x00454e2f`.
- `MiniMapDialog` call sites still own renderer use: construction at `0x00450d2b`, prepare call at `0x00451cdf`, build call at `0x00451d37` plus a projected/non-function code ref at `0x004517c9`, and version check at `0x00451e0b`.
- `BuildSymbolViews` calls the local support helpers at `0x004550d0`, `0x004551e0`, `0x00455350`, `0x00455600`, `0x00455a40`, `0x00455a90`, and `0x00455b40`, file-loader helpers at `0x00457620`, `0x004576b0`, and `0x00457850`, and image decode wrapper `0x004d0a90`.
- Version checks call [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) at `0x0045433c` and `0x00454dad`; `g_pMiniMapVersionManager` reads at `0x00454336` and `0x00454da0` keep the manager ownership outside this renderer class.
- Boundary bytes show eleven `0xcc` bytes before the renderer constructor and eleven `0xcc` bytes after the aggregate's symbol-control tail at `0x004563b5`, matching the enclosing renderer/control memory page.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now has current method bounds, MiniMapDialog caller evidence, version-manager dependency evidence, `.mnm` loader and image-decode callee evidence, helper-ownership caveats, a direct parent assignment, cross-links to the exact aggregate/helper pages, formal class-index marker, and declaration/body split policy. It remains below final-source quality because support-helper splits, field names, and record layouts are unresolved. |
| Confidence | 88 | Confidence is strong for renderer identity and MiniMap ownership from live IDA caller/callee/global-xref evidence and the already assigned aggregate memory page. It is capped by shared vector/string helper reuse, raw downloader-helper no-route status, and unresolved final source-file decomposition. |

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `85/86` to `86/88`, inserted the accepted formal class-index marker with `[[CHILDREN]]`, added the declaration-shell audit, and replaced non-formal source-style snippets with exact child-body conditions and current-pass exclusions.
- 2026-06-21 B007 Rule 26 source-quality incorporation:
  - Added renderer field/name guidance, raw `0x00454e30` no-code/private-helper caveat, and child-level C++ readiness notes. `0x004540a0` remains closed as `UpdateViewOriginFromPlayer`; remaining blockers are record-vector layouts, raw-helper reachability, and exact final source-file split.
- 2026-06-20 B005 MiniMapSymbolControlPane support sync:
  - Score unchanged at `85/86`.
  - Added `0x004540a0-0x00454143` as `MiniMapRenderer::UpdateViewOriginFromPlayer` and documented its caller-side role before `MiniMapSymbolControlPane::SetCenterPosition`. This supports the symbol-control center-setter name without changing the renderer source split or emitting C++.
- 2026-05-30: Grading changed from `0/0` to `76/80`.
  - Before: page documented the embedded renderer role and methods but remained unevaluated by the completion/confidence header.
  - After: score reflects documented renderer purpose, method ranges, `.mnm` path/version workflow, symbol-view rebuild responsibility, version-manager dependency, and helper-ownership caveats.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed starts, construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), `.mnm` parsing callees, and manager-owned lookup calls.
- 2026-06-02: Marked `RECONSTRUCTABLE:TRUE` and raised confidence from `80` to `82`.
  - Before: the page documented a project-owned embedded renderer class but had blank reconstructable metadata.
  - After: the page is marked reconstructable while keeping parent/source-file metadata and C++ blank.
  - Evidence: the class page and linked memory docs identify constructor/destructor/accessor/render/version-check methods, `MiniMapDialog` embedding, `.mnm` loader use, and `MiniMapVersionManager` dependency. Confidence is still capped by exact helper ownership and final `MiniMap.cpp` versus split-file placement.
- 2026-06-07 A008 Batch 092 class-coverage pass:
  - Before: `76/82`, `AUTOGEN_PARENT_UID:` blank, and status text still used generated recovered-file wording.
  - After: `85/86`, `AUTOGEN_PARENT_UID:0000LE`.
  - Summary/evidence: live IDA MCP reconfirmed renderer method bounds, MiniMapDialog construction/timer call sites, `BuildSymbolViews` support-helper and file-loader callee set, version-manager lookup calls and global reads, and aggregate padding. The direct MiniMap parent is `85/86`, so the corrected 85/85 assignment gate is satisfied while final C++ remains blank.
