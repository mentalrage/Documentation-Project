*** UID:0000RN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapButtonPane

## Status

- Confidence: strong for singleton role; medium for final canonical name.
- Address: [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md), slot `0x0069b4b8`
- IDA name: `dword_69B4B8`
- Proposed name: `g_pMiniMapButtonPane`
- Owner class: [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)

## Summary

`dword_69B4B8` stores the active [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md). The constructor at `0x00503580` writes this global, the [UID:0001AM][0x00503620-0x00503648.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503648.MiniMapButtonPaneCleanup.md) at `0x00503620` and [UID:0001AN][0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md) at `0x00503800` clear it, and other minimap/UI paths read it when toggling or updating the minimap button state.

## Evidence

- IDA `xrefs_to 0x0069b4b8` includes writes from `0x00503580`, `0x00503620`, `0x00503800`, and `0x00503900`.
- Additional xrefs include `0x005047f0`, a nearby map/minimap-side helper.
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) records the exact slot as the `MiniMapButtonPane` singleton, adjacent to the `MapNamePane` singleton and `GameServerConfig` globals.
- `source-3/simroot_v2/class_MiniMapButtonPane.cpp` emits `MiniMapButtonPane* g_pMiniMapButtonPane;`, the constructor assignment at `0x00503580`, and the scalar deleting destructor clear at `0x00503900`.
- `class_MiniMapButtonPane.cpp.source_map.json` reports `global-data:g_pMiniMapButtonPane` with one memory range and zero missing memory-range lines.
- Current active `class_MiniMapButtonPane.cpp` still omits the non-deleting cleanup at `0x00503620`, the singleton-clear helper at `0x00503800`, and the destructor adjustor thunks at `0x00503821`/`0x0050382c`; use the by-memory pages for those bodies.
- Live IDA MCP was unavailable during the 2026-05-30 review, so current confidence relies on the recorded IDA MCP notes and source-map evidence rather than a fresh xref query.

## Ownership Guidance

Declare this as `MiniMapButtonPane *g_pMiniMapButtonPane;` with [UID:0000LE][MiniMap](by-file/MiniMap.md) or the adjacent map UI header. Do not assign the global to [UID:00007P][MapNamePane](by-class/MapNamePane.md) even though their destructors and thunks are physically interleaved. `InitializeMainUiGraph` constructs the pane, but it is a consumer/bootstrap owner, not the class or global-storage owner.

## Cross-References

- [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503648.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503648.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md)

## Changes

- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata even though the class and memory pages were already researched. It now links the exact `0x0069b4b8` slot in the mixed global cluster, records current source-map resolution for `global-data:g_pMiniMapButtonPane`, and separates the constructor/destructor evidence from omitted cleanup/clear helpers. Score changed to `82/84`; confidence stays below the exact storage page because live IDA MCP was unavailable and final source placement between minimap and adjacent map UI remains open.
- 2026-05-28: Updated the shared MapName/MiniMapButton memory-island reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the `0x00503900` destructor ending at `0x0050395f`; the previous end omitted the final `retn 4` immediate byte.
