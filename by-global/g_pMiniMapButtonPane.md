*** UID:0000RN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MiniMapButtonPane *g_pMiniMapButtonPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapButtonPane

## Status

- Confidence: strong for singleton role, exact slot, current six-ref set, constructor writes, cleanup/helper/destructor clears, and MiniMap ownership; medium-high for final source placement.
- Address: [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md), slot `0x0069b4b8`
- IDA name: `dword_69B4B8`
- Proposed name: `g_pMiniMapButtonPane`
- Owner class: [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)

## Summary

`dword_69B4B8` stores the active [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md). The constructor at `0x00503580` writes this global, the ordinary destructor body [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) at `0x00503620`, exact singleton helper [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md) at `0x00503800`, and compiler wrapper [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) at `0x00503920` clear it, and other minimap/UI paths read it when toggling or updating the minimap button state.

## Evidence

- Live IDA MCP `xrefs_to 0x0069b4b8` on 2026-06-05 reports 6 xrefs: constructor writes at `0x005035c7` / `0x005035ce`, cleanup clears at `0x0050363a`, `0x00503800`, and `0x00503920`, plus a nearby map/minimap-side helper at `0x00504a54`.
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) records the exact slot as the `MiniMapButtonPane` singleton, adjacent to the `MapNamePane` singleton and `GameServerConfig` globals.
- Decompilation on 2026-06-05 shows `0x00503580` storing `this` into `dword_69B4B8` and installing the `MiniMapButtonPane` vtable, while `0x00503620`, `0x00503800`, and `0x00503900` clear the slot during cleanup/destruction.
- The non-deleting cleanup at `0x00503620`, singleton-clear helper at `0x00503800`, MiniMapButtonPane destructor adjustor thunks at `0x00503821`/`0x0050382c`, and scalar deleting destructor at `0x00503900` are now anchored by exact pages [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md), [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md), [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md), and [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md). [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) remains a non-emitting split/index only.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4b8-0x0069b4bc` with the same six xrefs. IDA MCP `get_bytes` on 2026-06-12 A003 Batch 342 supersedes the older byte note for the active `b001_nexustk` database: the exact storage slot is `00 00 00 00`. The exact split memory page is [UID:0002XP][0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md).
- Live IDA MCP on 2026-06-14 rechecked the current six direct refs: constructor publish/fallback writes at `0x005035c7` and `0x005035ce`, cleanup/helper/destructor clears at `0x0050363a`, `0x00503800`, and `0x00503920`, and map/minimap-side consumer read at `0x00504a54`. The constructor at `0x00503580` is a `0x9e`-byte, 158 decimal byte (Verified with int_convert.py), `InitializeMainUiGraph`-called `MiniMapButtonPane` constructor; the clear helper at `0x00503800` remains an 11-byte singleton clear.

## Ownership Guidance

Declare this as `MiniMapButtonPane *g_pMiniMapButtonPane = NULL;` with [UID:0000LE][MiniMap](by-file/MiniMap.md) or the adjacent map UI header. The exact storage child [UID:0002XP][0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md) now emits a covered-by marker to avoid a duplicate definition. Do not assign the global to [UID:00007P][MapNamePane](by-class/MapNamePane.md) even though their destructors and thunks are physically interleaved. `InitializeMainUiGraph` constructs the pane, but it is a consumer/bootstrap owner, not the class or global-storage owner.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page records exact storage, active-IDB zero initialization, current six-ref set, constructor publish/fallback writes, cleanup/helper/destructor clears, external map/minimap consumer, exact storage child, parent/emitter route, and the accepted singleton source definition. |
| Confidence | 90 | Live IDA MCP on 2026-06-14 matches the exact storage page [UID:0002XP][0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md), MiniMapButtonPane class evidence, and parent [UID:0000LE][MiniMap](by-file/MiniMap.md). Confidence stays below final-source level only because the original declaration placement between compact `MiniMap.cpp` and smaller minimap UI files remains open. |
| Parent | [UID:0000LE][MiniMap](by-file/MiniMap.md) | Child `86/88` and direct parent `85/86` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/map/MiniMap.cpp`. |

## Cross-References

- [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md)
- [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md)
- [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md)
- [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `86/88` to `88/90` and inserted the accepted singleton definition `MiniMapButtonPane *g_pMiniMapButtonPane = NULL;`.
  - Documented [UID:0002XP][0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md) as covered storage rather than a duplicate source definition.
- 2026-06-20 Rule 26 incorporation from B005 report: replaced the mixed [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) clear-helper reference with exact child [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md), added exact compiler-glue siblings [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md)/[UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md), and preserved the same six-reference singleton lifecycle. Score unchanged; the ownership and storage facts were already strong.
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
- 2026-06-12 A003 Batch 342: Corrected the active-IDB initial storage bytes from the stale `0xffffffff` note to `0x00000000`; xrefs and ownership remain unchanged.
- 2026-06-14 A003 score refresh:
  - Before: `85/86`; the target page did not cite a current full-xref confirmation after the storage-byte correction.
  - Changed to: `86/88`, retaining [UID:0000LE][MiniMap](by-file/MiniMap.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked all six direct refs to `0x0069b4b8`, constructor `0x00503580`, cleanup `0x00503620`, and clear helper `0x00503800`. Final declaration placement in the compact minimap source split remains the blocker below final code entry.
