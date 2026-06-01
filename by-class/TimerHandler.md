*** UID:0000F0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerHandler

## Status

- Likely original source: [UID:0000OT][TimerMgr](by-file/TimerMgr.md), with possible tiny companion `TimerHandler.cpp`.
- Confidence: strong for behavior; medium for final file placement.
- Current generated file: `source-3/simroot_v2/class_TimerHandler.cpp`
- Import source file: `TimerHandler.cpp`

## Responsibility

`TimerHandler` is the base class for objects that register timer callbacks with [UID:0000F1][TimerMgr](by-class/TimerMgr.md). Derived objects schedule events through thin helpers that forward to [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), and destruction unregisters all pending events for the handler.

## Method Families

| Range | Current/generated name | Role |
| --- | --- | --- |
| `0x00597570-0x00597579` | constructor | Installs the `TimerHandler` vtable. |
| `0x00597580-0x005975c3` | non-deleting destructor | Reinstalls vtable and unregisters this handler from `g_pTimerMgr`; IDA currently mislabels type as `boost::exception`. |
| `0x005975d0-0x005975d5` | default timer callback | Returns true; likely default virtual handler. |
| `0x005975e0-0x00597646` | schedule/cancel wrappers | Forward schedule/cancel/remove operations to the global `TimerMgr`. |
| `0x00597650-0x005976b3` | scalar deleting destructor | Unregisters and optionally deletes the object. |

## Generated Output Caveats

Active `class_TimerHandler.cpp` emits only the constructor and scalar deleting destructor. The non-deleting destructor, default callback, and wrapper helpers are IDA-confirmed but omitted from the active class output. Older docs assigned `0x00597580` to `EventDispatcher` and `0x00597600` to `InterfaceEfx`; current IDA body checks resolve both as timer-handler base code.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the timer-handler method family, wrapper/destructor memory links, and global timer-manager ownership; confidence remains limited by possible file-placement split and active generated-output omissions.
