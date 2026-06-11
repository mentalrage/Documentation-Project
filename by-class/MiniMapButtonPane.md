*** UID:00008B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapButtonPane

## Status

- Confidence: strong for class behavior, singleton handling, IDA starts, child-page boundaries, and current MiniMap parent attachment; medium-high for exact original source-unit split.
- Attached source file: [UID:0000LE][MiniMap](by-file/MiniMap.md)
- Address range: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- Parent attachment: [UID:0000LE][MiniMap](by-file/MiniMap.md) is now `82/84`, and this class is `82/82`, so the 80/80 attachment gate is met while preserving the final split caveat.

## Class Purpose

`MiniMapButtonPane` is the small in-game minimap button created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) in the newer layout. It initializes a pane/tile context, paints `MMAPBUT.EPF` with `FRMPART.PAL`, tracks mouse hover/down state, dispatches a click handler, and clears [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md) during teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00503580-0x0050361d` | Constructs `Pane`, stores `g_pMiniMapButtonPane`, installs vtables, initializes an `EPFTileContext`, and clears state fields. |
| cleanup body | [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) | Reinstalls vtables, clears the singleton, and tail-transfers to shared pane cleanup. The child page documents the true half-open end as `0x00503649` while its filename remains stale. |
| `OnPaint` | `0x00503650-0x00503691` | Loads `MMAPBUT.EPF` frame data and renders it with `FRMPART.PAL`. |
| `OnMouseEvent` | `0x005036a0-0x005037ec` | Handles hover, press, release, state repaint, and click dispatch. |
| singleton clear helper | [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) | Clears `g_pMiniMapButtonPane`. The child page documents the true half-open end as `0x00503837` while its filename remains stale. |
| adjustor thunks | [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) | MiniMapButtonPane destructor adjustors at `0x00503821-0x0050382c` and `0x0050382c-0x00503837`; compiler-generated wrappers forwarding to `0x00503900`. |
| scalar deleting destructor | `0x00503900-0x0050395f` | Runs cleanup and conditionally deletes storage; `0x0050395e` is the final `retn 4` immediate byte. |

## Boundary Notes

- IDA `callers 0x00503580` reports one constructor caller from `InitializeMainUiGraph` at `0x004f80c2`.
- The local code island is interleaved with [UID:00007P][MapNamePane](by-class/MapNamePane.md): `MapNamePane` owns `0x005031f0`, `0x005032d0`, `0x00503350`, `0x0050380b`, `0x00503816`, and `0x00503840`, while `MiniMapButtonPane` owns `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x00503800`, `0x00503821`, `0x0050382c`, and `0x00503900`.
- The older [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md) is retained for existing links, but the shared island doc is the safer migration anchor.

## Evidence Notes

- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) records the per-method split, exact padding spans, the single constructor caller from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), and `xrefs_to 0x0069b4b8` confirming constructor, cleanup, and destructor singleton writes/clears.
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) ties the cleanup body to MiniMapButtonPane vtables at receiver offsets `0`, `0xa0`, and `0xa4`, the `g_pMiniMapButtonPane` zero write, and the tail transfer to shared pane cleanup at `0x00544580`.
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) separates the MiniMapButtonPane singleton clear helper and compiler-generated destructor adjustors from neighboring MapNamePane thunks.
- [UID:00025R][0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData](by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md) provides the MiniMapButtonPane vtable and map/minimap resource-string evidence; [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) names the singleton storage slot at `0x0069b4b8`.

## Source Placement

The class is now attached to [UID:0000LE][MiniMap](by-file/MiniMap.md) because both parent and child clear the confidence/completion gate, and the singleton, vtable, resource, and button-art evidence belongs to the minimap source family. The exact original unit remains open: the class may have lived in a compact `MiniMap.cpp` or a focused minimap control source, while `ui/MainUiGraph.cpp` should cross-reference construction but not own the class.

## Open Questions

- Rename [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) and [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) to their true half-open end filenames when `by-memory/-coverage-report.md` and validator-generated refreshes are free.
- Final C++ should stay blank until the hover/down fields, tile-context ownership, and click-dispatch target have source-quality names and the class reaches the 95/95 reconstruction bar.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md)
- [UID:00025R][0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData](by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)

## Changes

- 2026-06-06: Raised from `80/78` to `82/82`, attached parent [UID:0000LE][MiniMap](by-file/MiniMap.md), removed stale generated-output provenance, and added child-page-backed evidence for singleton storage, vtables, cleanup, clear/thunk ownership, stale child filename caveats, and the remaining source-unit split.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/cleanup/paint/mouse/singleton-clear/thunk/destructor starts at `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x00503800`, `0x00503821`, `0x0050382c`, and `0x00503900`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below 80 and the likely parent [UID:0000LE][MiniMap](by-file/MiniMap.md) is below the 80 completion attachment gate.
- 2026-05-28: Corrected the scalar deleting destructor range from `0x00503900-0x0050395e` to `0x00503900-0x0050395f`. Evidence: IDA MCP reports the function end at `0x0050395f`, and raw bytes show `0x0050395e` is the `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `80/78`. Summary: the minimap button pane has detailed singleton, constructor, cleanup, paint, mouse, thunk, island-boundary, and source-placement notes, but final source placement between minimap and main UI bootstrap remains medium confidence. Evidence: linked shared MapName/MiniMapButton range, cleanup/clear/thunk memory pages, `g_pMiniMapButtonPane`, constructor caller from `InitializeMainUiGraph`, and interleaved `MapNamePane` boundary notes.
