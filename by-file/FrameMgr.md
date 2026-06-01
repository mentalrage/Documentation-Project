*** UID:0000JM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FrameMgr And FrameHandler

## Status

- Confidence: strong for scheduler role and class grouping.
- Proposed module: `ui/core/FrameMgr.cpp` or `util/FrameMgr.cpp`
- Current recovered sources: `source-3/simroot_v2/class_FrameMgr.cpp` and `class_FrameHandler.cpp`
- Main address range: `0x004b6cb0-0x004b7112`

## File Role

This module owns the client frame-callback scheduler. `FrameMgr` is a singleton list manager stored in `g_frameRegistry`; `FrameHandler` is the small base/handler object that unregisters itself from the registry when destroyed. The scheduler stores handlers in due-frame order and dispatches callbacks as the global frame tick advances.

The name "frame" here means animation/frame-tick scheduling, not UI border artwork. Keep it separate from [UID:0000JL][FrameChrome](by-file/FrameChrome.md), which owns visible frame-border panes and `FRMPART`/`TABS` art.

The queue storage is backed by the shared [UID:0000KR][LinkedList](by-file/LinkedList.md) utility helpers. `FrameMgr.cpp` should own frame-specific ordering, dispatch, and `FrameHandler` lifetime logic; generic node allocation and list cleanup belong with `util/LinkedList.cpp`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `FrameHandler` | `0x004b6cb0-0x004b6db2` | Handler base/destructor that unregisters from `g_frameRegistry`. |
| `FrameMgr` | `0x004b6dc0-0x004b7111` | Singleton frame callback queue with sorted insertion, removal, dispatch, and teardown. |
| [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) | `0x0069ae10` | Global scheduler singleton installed by `FrameMgr::FrameMgr`; active `ApplicationHelper_4A6C40` output aliases it as `g_pIdleDispatchQueue`. |
| schedule wrapper helpers | `0x004b6d00`, `0x004b6d20`, `0x004b6d30` neighborhood | Thin helpers that call `FrameMgr::Insert`/`RemoveFrame`; `0x004b6d30` is the delayed `ScreenPane::ScheduleFrameCallback` wrapper. |

## Evidence Notes

- Wave3 metadata says `FrameMgr` is a 24-byte `LObject`-based singleton with a circular linked list at offset `0x10`.
- IDA MCP reports `FrameMgr::FrameMgr` has one direct constructor caller and `DispatchDueFrameCallbacks` is called from the application/event dispatch path.
- IDA MCP xrefs on 2026-05-26 confirm `dword_69AE10` is written by `FrameMgr::FrameMgr`, cleared by `FrameMgr::ScalarDeletingDestructor`, used by the `FrameHandler` wrappers, and used by [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md).
- IDA labels `FrameHandler` functions as Boost exception symbols, but call patterns and `g_frameRegistry` use match project frame-handler logic.
- `ScreenPane`, `WorldMapPane`, and other frame-driven objects embed or use `FrameHandler`.
- IDA MCP on 2026-05-24 confirms `0x004b6d00` schedules the current handler at `currentFrame + 1`, `0x004b6d20` removes the current handler from the registry, and both have broad callers outside `WorldMapPane`. Treat WorldMap ownership for those wrappers as generated caller-biased noise.

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
