*** UID:0000RN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

`dword_69B4B8` stores the active [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md). The constructor at `0x00503580` writes this global, the [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) at `0x00503620` and [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) at `0x00503800` clear it, and other minimap/UI paths read it when toggling or updating the minimap button state.

## Evidence

- Live IDA MCP `xrefs_to 0x0069b4b8` on 2026-06-05 reports 6 xrefs: constructor writes at `0x005035c7` / `0x005035ce`, cleanup clears at `0x0050363a`, `0x00503800`, and `0x00503920`, plus a nearby map/minimap-side helper at `0x00504a54`.
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) records the exact slot as the `MiniMapButtonPane` singleton, adjacent to the `MapNamePane` singleton and `GameServerConfig` globals.
- Decompilation on 2026-06-05 shows `0x00503580` storing `this` into `dword_69B4B8` and installing the `MiniMapButtonPane` vtable, while `0x00503620`, `0x00503800`, and `0x00503900` clear the slot during cleanup/destruction.
- The non-deleting cleanup at `0x00503620`, singleton-clear helper at `0x00503800`, and destructor adjustor thunks at `0x00503821`/`0x0050382c` should remain anchored by the by-memory pages for those bodies.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4b8-0x0069b4bc`, bytes `ff ff ff ff`, initial dword `0xffffffff`, and the same six xrefs. The exact split memory page is [UID:0002XP][0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md).

## Ownership Guidance

Declare this as `MiniMapButtonPane *g_pMiniMapButtonPane;` with [UID:0000LE][MiniMap](by-file/MiniMap.md) or the adjacent map UI header. Do not assign the global to [UID:00007P][MapNamePane](by-class/MapNamePane.md) even though their destructors and thunks are physically interleaved. `InitializeMainUiGraph` constructs the pane, but it is a consumer/bootstrap owner, not the class or global-storage owner.

## Cross-References

- [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md)

## Changes

- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata even though the class and memory pages were already researched. It now links the exact `0x0069b4b8` slot in the mixed global cluster and separates the constructor/destructor evidence from omitted cleanup/clear helpers. Score changed to `82/84`; confidence stays below the exact storage page because final source placement between minimap and adjacent map UI remains open.
- 2026-05-28: Updated the shared MapName/MiniMapButton memory-island reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the `0x00503900` destructor ending at `0x0050395f`; the previous end omitted the final `retn 4` immediate byte.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LE`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b4b8` and decompilation of `0x00503580`, `0x00503620`, `0x00503800`, and `0x00503900` prove NexusTK-owned minimap button singleton storage owned by [UID:0000LE][MiniMap](by-file/MiniMap.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `82/84`, below the corrected `85/85` gate for assigning the exact storage child.
  - After: `85/86`.
  - Evidence: live IDA MCP reconfirmed the exact four-byte item, initial bytes/dword, and constructor/cleanup/destructor/map-helper xrefs. The remaining caveat is final source placement between compact `MiniMap.cpp` and smaller minimap UI files, not the direct global ownership.
