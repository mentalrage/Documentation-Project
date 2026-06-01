*** UID:0000MK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PhotoPane

## Status

- Confidence: strong for `PhotoPane` and `PictureViewPane` behavior, medium for the final original file split.
- Proposed module: `map/PhotoPane.cpp`
- Proposed header: `map/PhotoPane.h`
- Current recovered sources: `source-3/simroot_v2/class_PhotoPane.cpp` and `source-3/simroot_v2/class_PictureViewPane.cpp`
- Main address cluster: `0x00549620-0x00549bc5`

## File Role

This module owns the map-photo/viewer pane used to show a generated snapshot of a map area and avatar. `PhotoPane` builds an off-screen `GrafPort` from a map DAT entry, renders a 17 by 15 terrain/object tile preview, draws a `NewHumanImageLib` avatar over it, and later blits that cached surface during paint.

`PictureViewPane` is the immediate viewer/base pane that attaches itself to the active view pane, uses the same full-screen image-view lifecycle, and closes its owner on selected message codes. The current best migration shape keeps `PhotoPane` and `PictureViewPane` together or as adjacent sibling files because `PhotoPane` destructs through `PictureViewPane` and the functions are contiguous.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `PhotoPane` | `0x00549620-0x00549afe` plus thunks | Map-photo pane with cached `GrafPort`, map DAT load, tile/object/avatar render, paint blit, and cleanup. |
| `PictureViewPane` | `0x00549a30-0x00549bc5` plus thunks | Full-screen picture/viewer pane base used by `PhotoPane`; creates against the active view pane and handles close/delete messages. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00549620-0x00549911` | `PhotoPane::PhotoPane` | Opens `C%04d.MAP`, initializes off-screen `GrafPort`, renders terrain tiles, static objects, and one human/avatar descriptor. |
| `0x00549920-0x00549950` | `PhotoPane` raw cleanup destructor body | Non-IDA-modeled cleanup body; writes `PhotoPane` vtables, destroys cached `GrafPort` at `this + 0xf8`, then tail-jumps to `PhotoPane::~PhotoPane`; see [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md). |
| `0x00549950-0x005499a2` | `PhotoPane::OnPaint` | Blits the cached photo `GrafPort` into the visible pane. |
| `0x005499a2-0x005499b8` | `PhotoPane` adjustor thunks | Vtable glue for the paint/delete views. |
| `0x005499c0-0x00549a22` | `PhotoPane::ScalarDeletingDestructor` | Resets `PhotoPane` vtables, destroys the embedded `GrafPort`, chains to the non-deleting destructor, and optionally deletes. |
| `0x00549ae0-0x00549aff` | `PhotoPane::~PhotoPane` | Resets to `PictureViewPane` vtables and chains to pane teardown. |
| `0x00549a30-0x00549ad6` | `PictureViewPane::PictureViewPane` | Creates a pane on `g_pViewPane`, copies its bounds, sets sprite/view parent state, and calls create/show setup. |
| `0x00549b00-0x00549b22` | `PictureViewPane::HandleMessageType03Or06` | Handles message codes `3` and `6` by invoking the owner deletion helper through a `this - 0xa0` adjustment; see [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md). |
| `0x00549b30-0x00549b4d` | `PictureViewPane::HandleMessageType08` | Handles message code `8` with the same close/delete behavior. |
| `0x00549b4d-0x00549b63` | `PictureViewPane` adjustor thunks | Compiler-generated vtable glue for secondary pane views; tracked in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| `0x00549b70-0x00549bc5` | `PictureViewPane::ScalarDeletingDestructor` | Resets `PictureViewPane` vtables, tears down `Pane`, and optionally deletes. |

## Ownership Decision

Place this under `map/` rather than generic `ui/controls`. The constructor consumes map resource files (`C%04d.MAP`), terrain tile rendering, static-object rendering, and human/avatar rendering. `MapPane::HandlePacket` is a confirmed constructor caller, which makes the pane a map feature consumer rather than a reusable dialog control.

Do not group this with [UID:0000HX][BulletinSession](by-file/BulletinSession.md) based only on current generated `PictureViewPane` handler text. IDA shows the handlers call a broad owner deletion helper with a `this - 0xa0` adjustment; the generated `BulletinSession::MarkForDeletion` name is likely owner pollution.

## Evidence Notes

- IDA MCP reports `PhotoPane::PhotoPane` at `0x00549620` with callers from [UID:0000L3][MapPane](by-file/MapPane.md) packet dispatch and another nearby UI path at `0x005143c0`.
- `PhotoPane::PhotoPane` calls shared render helpers from [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- IDA MCP 2026-06-01 identifies `0x00549920-0x00549950` as raw executable destructor-shaped cleanup code not modeled as a function start; it belongs with `PhotoPane` because it writes `PhotoPane` vtables and destroys the embedded cached surface before chaining to `PictureViewPane`.
- `PhotoPane::OnPaint` only blits the cached `GrafPort`, supporting the constructor-rendered snapshot interpretation.
- `PhotoPane::~PhotoPane` resets to `PictureViewPane` vtables before base teardown.
- `PictureViewPane` constructor reads the active view/root pane, copies bounds, and attaches itself to that view; its close handlers do not access bulletin-specific article or board state.

## Current Caveats

- The exact original source split remains open. `PictureViewPane.cpp` may have been a small standalone base-view file with `PhotoPane.cpp` deriving from it, or both may have lived in one photo/viewer module.
- Generated handler names currently imply `BulletinSession` ownership. Treat those names as provisional until the owner deletion helper and `this - 0xa0` subobject relationship are fully typed.
- 2026-05-25 recheck: current `class_PictureViewPane.cpp` still emits `BulletinSession::MarkForDeletion`, but IDA decompilation of `0x00549b00` and `0x00549b30` only tests message bytes and calls `sub_544690(this - 160)`. IDA also confirms the `0x00549b4d` and `0x00549b58` functions are adjustor thunks to the scalar deleting destructor, not handwritten close logic.
- The second direct caller to `PhotoPane::PhotoPane` at `0x005143c0` needs a focused packet/UI pass before naming the exact feature path.

## Cross-References

- [UID:0000AG][PhotoPane](by-class/PhotoPane.md)
- [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md)
- [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md)
- [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md)
- [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- Before: `PictureViewPane` destructor coverage ended at `0x00549bc4`.
- Changed to: the destructor and containing photo/picture pane memory range end at `0x00549bc5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00549bc4` is the final operand byte of the `retn 4` in `sub_549B70`; the following bytes through `0x00549bd0` are alignment padding.

- Before: the function map skipped `0x00549920-0x00549950`.
- Changed to: the raw cleanup destructor body is now listed as part of `PhotoPane` and linked to [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md).
- Summary/evidence: 2026-06-01 IDA MCP disassembly shows the raw body writes `PhotoPane` vtables, destroys `this + 0xf8`, and tail-jumps to `0x00549ae0`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents the photo/viewer module role, proposed contents, function map, ownership decision, IDA evidence, generated-handler caveats, range correction, and cross-references; confidence remains capped by final split from `PictureViewPane` and one unresolved constructor caller.
