*** UID:0000F0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerHandler

## Status

- Likely original source: [UID:0000OT][TimerMgr](by-file/TimerMgr.md), with possible tiny companion `TimerHandler.cpp`.
- Confidence: strong for behavior, live boundaries, vtable/global anchors, destructor/wrapper caller evidence, and parent placement; medium for exact final file split.
- Parent attachment: [UID:0000OT][TimerMgr](by-file/TimerMgr.md) has a documented `NexusTK/util/` reconstruction path and owns the scheduler used by every `TimerHandler` wrapper.

## Responsibility

`TimerHandler` is the base class for objects that register timer callbacks with [UID:0000F1][TimerMgr](by-class/TimerMgr.md). Derived objects schedule events through thin helpers that forward to [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), and destruction unregisters all pending events for the handler.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00597570-0x00597579` | constructor | Installs the `TimerHandler` vtable. |
| `0x00597580-0x005975c3` | non-deleting destructor | Reinstalls vtable and unregisters this handler from `g_pTimerMgr`; IDA currently mislabels type as `boost::exception`. |
| `0x005975d0-0x005975d5` | callback-shaped return helper | Returns true, but live IDA reports no direct xrefs and the current `TimerHandler` vtable callback slot is `__purecall`; keep this as a nearby helper until ownership is proven. |
| `0x005975e0-0x005975ff` | schedule wrapper | Forwards to `TimerMgr::ScheduleTimer` through `g_pTimerMgr`. |
| `0x00597600-0x0059760d` | unregister wrapper | Forwards to the same unregister-all path used by the destructor. |
| `0x00597610-0x00597626` | cancel event wrapper | Forwards targeted timer cancellation through `g_pTimerMgr`. |
| `0x00597630-0x00597646` | cancel-except wrapper | Forwards the alternate targeted removal helper through `g_pTimerMgr`. |
| `0x00597650-0x005976b3` | scalar deleting destructor | Unregisters and optionally deletes the object. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact function ranges for constructor, destructor, callback-shaped helper, four wrappers, and scalar deleting destructor: `0x00597570-0x00597579`, `0x00597580-0x005975c3`, `0x005975d0-0x005975d5`, `0x005975e0-0x005975ff`, `0x00597600-0x0059760d`, `0x00597610-0x00597626`, `0x00597630-0x00597646`, and `0x00597650-0x005976b3`.
- Live IDA names the `TimerHandler` vtable at `0x0062e338`, with stores/xrefs at `0x00597570`, `0x005975a2`, and `0x00597675`; the first slot points to `0x00597650`, and the second slot is `__purecall`.
- Constructor has seven direct call sites. The non-deleting destructor has 15 direct callers. The schedule wrapper at `0x005975e0` has 163 direct callers, the unregister wrapper at `0x00597600` has 45, the targeted cancel wrapper at `0x00597610` has 47, and the alternate cancel wrapper at `0x00597630` has one.
- Live decompilation shows every wrapper loads [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) at `0x0067ab80` and forwards to the scheduler helper family (`0x00597910`, `0x00597a10`, `0x00597b80`, or `0x00597ca0`).
- The IDA name on `0x00597580` still carries a stale `boost::exception` label, but the body writes the `TimerHandler` vtable and unregisters the handler from `g_pTimerMgr`, matching the TimerHandler destructor role.

## Current Caveats

- Final source placement is still open between folding `TimerHandler` into `TimerMgr.cpp` and keeping a tiny companion source/header unit.
- `0x005975d0` is documented as callback-shaped only; it is not currently proven to be the live vtable callback because the `TimerHandler` vtable uses `__purecall` in that slot.
- Exact public method names remain provisional below the final-source threshold.

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
  - Summary/evidence: scored from the timer-handler method family, wrapper/destructor memory links, and global timer-manager ownership; confidence remained limited by possible file-placement split and missing wrapper coverage in earlier documentation.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OT`.
  - Evidence: live IDA MCP confirmed exact boundaries for all TimerHandler lifecycle/wrapper functions, vtable data at `0x0062e338`, constructor/destructor/wrapper caller counts, `g_pTimerMgr` forwarding behavior, scalar destructor vtable slot, and the parent scheduler relationship under [UID:0000OT][TimerMgr](by-file/TimerMgr.md).
  - Remaining limits: score stays below final-source level because the final source split and public method names are still not fully proven, and `0x005975d0` remains a no-xref callback-shaped helper rather than a proven vtable callback.
