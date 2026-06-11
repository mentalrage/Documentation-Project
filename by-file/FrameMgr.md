*** UID:0000JM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FrameMgr And FrameHandler

## Status

- Confidence: strong for scheduler role, class grouping, singleton ownership, and direct file-root assignment.
- Proposed module: `ui/core/FrameMgr.cpp`
- Alternate placement considered: `util/FrameMgr.cpp`
- Main address range: `0x004b6cb0-0x004b7112`

## File Role

This module owns the client frame-callback scheduler. `FrameMgr` is a singleton list manager stored in `g_frameRegistry`; `FrameHandler` is the small base/handler object that unregisters itself from the registry when destroyed. The scheduler stores handlers in due-frame order and dispatches callbacks as the global frame tick advances.

The name "frame" here means animation/frame-tick scheduling, not UI border artwork. Keep it separate from [UID:0000JL][FrameChrome](by-file/FrameChrome.md), which owns visible frame-border panes and `FRMPART`/`TABS` art.

The queue storage is backed by the shared [UID:0000KR][LinkedList](by-file/LinkedList.md) utility helpers. `FrameMgr.cpp` should own frame-specific ordering, dispatch, and `FrameHandler` lifetime logic; generic node allocation and list cleanup belong with `util/LinkedList.cpp`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `FrameHandler` | `0x004b6cb0-0x004b6db2` | Handler base/destructor that unregisters from `g_frameRegistry`. |
| `FrameMgr` | `0x004b6dc0-0x004b7112` | Singleton frame callback queue with sorted insertion, removal, dispatch, and teardown. |
| [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) | `0x0069ae10` | Global scheduler singleton installed by `FrameMgr::FrameMgr`; idle-dispatch notes also alias it as `g_pIdleDispatchQueue`. |
| schedule wrapper helpers | `0x004b6d00`, `0x004b6d20`, `0x004b6d30` neighborhood | Thin helpers that call `FrameMgr::Insert`/`RemoveFrame`; `0x004b6d30` is the delayed `ScreenPane::ScheduleFrameCallback` wrapper. |

## Evidence Notes

- IDA storage and call patterns show `FrameMgr` is an `LObject`-based singleton with a circular linked list at offset `0x10`.
- IDA MCP reports `FrameMgr::FrameMgr` has one direct constructor caller and `DispatchDueFrameCallbacks` is called from the application/event dispatch path.
- IDA MCP xrefs on 2026-05-26 confirm `dword_69AE10` is written by `FrameMgr::FrameMgr`, cleared by `FrameMgr::ScalarDeletingDestructor`, used by the `FrameHandler` wrappers, and used by [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md).
- IDA labels `FrameHandler` functions as Boost exception symbols, but call patterns and `g_frameRegistry` use match project frame-handler logic.
- `ScreenPane`, `WorldMapPane`, and other frame-driven objects embed or use `FrameHandler`.
- IDA MCP on 2026-05-24 confirms `0x004b6d00` schedules the current handler at `currentFrame + 1`, `0x004b6d20` removes the current handler from the registry, and both have broad callers outside `WorldMapPane`. Treat WorldMap ownership for those wrappers as generated caller-biased noise.
- 2026-06-07 Batch 004 IDA MCP gate audit reconfirmed all scheduler method boundaries: `0x004b6cb0-0x004b6cf3`, `0x004b6d00-0x004b6d14`, `0x004b6d20-0x004b6d2d`, `0x004b6d30-0x004b6d4c`, `0x004b6d50-0x004b6db3`, `0x004b6dc0-0x004b6e63`, `0x004b6ea0-0x004b6f0e`, `0x004b6f10-0x004b6f56`, `0x004b6f60-0x004b703d`, and `0x004b70c0-0x004b7112`.
- The same audit reconfirmed constructor call-in from `0x004a6b9c`, idle-dispatch call-in from `0x004a6cd0`, broad frame-driven callers for the handler schedule/remove wrappers, `g_frameRegistry` refs at `0x0069ae10`, vtable refs for `FrameHandler` base `0x0061a7e0` and `FrameMgr` base `0x0061a7ec`, one `0xcc` byte before the scheduler range, and `0xcc` padding at `0x004b7112-0x004b7120`.

## Corrected Parent Gate Audit

- Current file-root score after this audit: `COMPLETION:85`, `CONFIDENCE:86`.
- Direct child now eligible: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md), whose Batch 004 audit raises it to `85/90`.
- Assignment basis: `FrameMgr.cpp` is the direct source root for the scheduler aggregate because the range owns both `FrameHandler` wrappers and `FrameMgr` queue policy, all direct scheduler calls route through `g_frameRegistry`, and the proposed source tree already places `FrameMgr.cpp` under `NexusTK/ui/core/`.
- Remaining caveat: final field names and every embedding-owner layout are still below the final-source bar, so this page stays below `95/95` and no C++ is emitted.

## Cross-References

- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:84`.
  - Summary/evidence: frame-callback scheduler role, FrameMgr/FrameHandler grouping, global scheduler ownership, wrapper helper roles, IDA/global xref evidence, frame-chrome distinction, LinkedList boundary, and cross-references are documented; completion is moderate because the page is compact and lacks exhaustive per-method pseudocode.
- 2026-06-05 path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, which left the file row in error state despite the proposed tree placing `FrameMgr.cpp` under `ui/core`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` lists `FrameMgr.cpp` beside `EventDispatcher`, `FrameChrome`, and other UI core scheduler/pane infrastructure; live IDA MCP xrefs to [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) confirm the singleton is constructed/cleared by the frame scheduler and used by the application idle scheduler.
- 2026-06-07 Batch 004 gate audit:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`; the page had a valid path and scheduler summary but was below the corrected direct-parent assignment gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA reconfirmed all `FrameHandler`/`FrameMgr` function endpoints, direct constructor/dispatch callers, broad wrapper callers, singleton refs, vtable refs, proposed source-tree placement, and boundary padding. The page now explicitly supports direct parenting for the FrameScheduler aggregate while leaving final C++ blank.
