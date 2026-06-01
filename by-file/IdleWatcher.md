*** UID:0000K0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IdleWatcher

## Status

- Confidence: strong for behavior and anchors; medium for original file split.
- Proposed module: `app/IdleWatcher.cpp` or a small adjacent app/startup helper file.
- Current generated source: `class_IdleWatcher.cpp`
- Primary class doc: [UID:00006C][IdleWatcher](by-class/IdleWatcher.md)
- Main address doc: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)

## File Role

`IdleWatcher` is a small `Pane`-derived singleton created from `Application::Startup`. It stores `g_pIdleWatcher`, schedules idle/timer callbacks, and tears itself down through pane/base destruction.

The class is startup-owned, but it should not be absorbed into [UID:0000HG][Application](by-file/Application.md) unless the original source is proven to have kept singleton helper classes in the application file. Its behavior is a separate timer/idle pane helper.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `IdleWatcher` | `0x004cfe60-0x004cffaf` | Startup-created idle/timer watcher singleton. |
| adjustor thunks | `0x004cff37-0x004cff4d` | Disabled compiler/vtable thunks forwarding to the scalar deleting destructor. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction | `0x004cfe60` | Constructs pane base, installs vtables, and sets `g_pIdleWatcher`. |
| Activation/timer setup | `0x004cff20` | Marks the watcher active and schedules timer callback work. |
| Destruction | `0x004cff37`, `0x004cff42`, `0x004cff50` | Two disabled thunk entries forward to the scalar deleting destructor. |

## Boundary Notes

- IDA confirms exact starts at `0x004cfe60`, `0x004cff20`, `0x004cff37`, `0x004cff42`, and `0x004cff50`.
- `list missing-ref --class IdleWatcher` returns zero entries.
- Wave3 currently lowers `IdleWatcher` completion because disabled/excluded thunks overflow the class aggregate ranges and because child rollup uses low auto grades despite high manual grades. This is tracked in [wave3_noticed_problems](../wave3_noticed_problems.md).

## Cross-References

- [UID:00006C][IdleWatcher](by-class/IdleWatcher.md)
- [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: startup-created pane singleton role, construction/timer/destruction anchors, boundary notes, and neighboring app/event/timer dependencies are documented; completion is lower because the file is small and lacks deeper raw-code/source-form detail for the timer callback behavior.
