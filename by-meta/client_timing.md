*** UID:0001QU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Timing

## Scope

This page tracks client-level timing and scheduler behavior. Source ownership decisions live in `by-file`; exact address evidence lives in `by-memory`.

## Current Model

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md) is the high-level callback scheduler. It uses multimedia timer resolution setup and `timeGetTime`, stores scheduled callback records, and dispatches due events from the application helper/message-loop path.
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md) is the base class for objects that register timer callbacks. Destruction unregisters pending events.
- [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md) is an embedded sorted ring queue of [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records.
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) is a lower-level multimedia/waitable timer wrapper and should remain separate from `TimerMgr` until direct caller evidence proves a merge.
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) compares several system time sources, sends a heartbeat/status packet, and calls the crash-diagnostic text sender after repeated timer skew. IDA caller evidence now leans ownership toward [UID:0000HG][Application](by-file/Application.md) message-loop timing, with network/session and diagnostics as dependencies.
- [UID:0000OU][TimerPane](by-file/TimerPane.md) is a map UI countdown/count-up overlay that consumes timer callbacks but should not be merged into the scheduler. Its exact range is [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md), immediately after the `TimerMgr` cluster.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) is the frame-tick callback scheduler exposed through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md). It is separate from `TimerMgr`: `TimerMgr` dispatches time-based callbacks, while `FrameMgr` schedules `FrameHandler` callbacks by frame count and is pumped from application idle work.
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) is a major map-actor timer consumer. IDA confirms its sprite config, animation playback, frame stepping, and movement timer handlers use the generic `TimerHandler`/`TimerMgr` scheduler path rather than a feature-local scheduler.

## Important Caveats

- Active generated `TimerMgr` output omits several IDA-confirmed queue helper functions, especially `0x00597dc0`, `0x00597eb0`, `0x00597f20`, and `0x005980f0`.
- Active `TimerHandler` output omits the non-deleting destructor, default callback, and wrapper helpers.
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) uses crash-diagnostic reporting but should not be assigned to [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), [UID:0000I6][CheatDetector](by-file/CheatDetector.md), [UID:0000NS][Socket](by-file/Socket.md), or [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). Its only direct caller is `Application::RunMessageLoop`.
- Older docs/generated ownership assigned `0x00597580` to `EventDispatcher` and `0x00597600` to `InterfaceEfx`. IDA decompilation resolves both as generic `TimerHandler` cleanup/wrapper code through `g_pTimerMgr`.
- `0x00597610-0x00597645` is resolved as generic `TimerHandler` wrapper ownership. Active generated SoundManager output still emits these wrappers as audio methods, but IDA body/caller evidence points to the scheduler cluster.
- Active generated `class_LivingObjectPane.cpp` still calls those wrappers under `SoundManager::*` names. Treat that as stale generated naming; it does not make living-object sprite/movement timers part of `audio/SoundManager.cpp`.
- Active generated `TimerPane` output omits IDA-confirmed helper functions at `0x00598850`, `0x00598880`, and `0x00598c30`; keep the memory/class docs as the authoritative migration anchor.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:0000U8][CheckTimerSkewAndSendHeartbeat_466CA0](by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md)
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md)
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
