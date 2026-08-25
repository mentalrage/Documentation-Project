*** UID:0004ZO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TimerHandler

## Status

- Proposed module: `NexusTK/util/TimerHandler.h` and `NexusTK/util/TimerHandler.cpp`.
- Confidence: strong for the separate interface/source route, four-byte abstract layout, callback/wrapper API, TimerMgr dependency, broad derived consumers, and exact body ownership.
- Primary class: [UID:0000F0][TimerHandler](by-class/TimerHandler.md).
- Exact destructor body: [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md).

## File Role

`TimerHandler.h` owns the fieldless, one-vptr timer callback interface shared by panes, event routing, effects, sound, and application objects. It declares a pure virtual three-argument `OnTimer` callback plus four concrete scheduling/cancellation wrappers.

`TimerHandler.cpp` includes `TimerHandler.h` and complete `TimerMgr.h`, then receives exact constructor/destructor/pure-body/wrapper definitions through the TimerHandler class emitter. This keeps the reusable handler interface separate from TimerMgr's scheduler/container declaration while preserving the observed binary adjacency.

## Header Contract

- Exact size is four bytes, guarded by `TimerHandlerSizeMustBe4`.
- `OnTimer(int timerId, int arg0, int arg1)` is pure virtual; its retained out-of-line true-return body remains exact child evidence and does not make the class concrete.
- Concrete wrappers are `ScheduleTimer`, `RemovePendingTimers`, `CancelTimer`, and `CancelPendingTimersExceptEvent`.
- Destructor and wrappers use `g_pTimerMgr` through complete `TimerMgr.h`; no partial duplicate manager declaration is emitted.

## Ownership Boundaries

- [UID:0000F0][TimerHandler](by-class/TimerHandler.md) owns the declaration and routes source-authored bodies here.
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md) and sibling exact pages own their address-ranged bodies.
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md) owns scheduler/container declarations and bodies, not the TimerHandler interface.
- TimerHandler vtable/deleting-destructor bytes are compiler-generated consequences and are not handwritten raw tables/functions.

## Rejected Alternatives

- Folding the declaration only into `TimerMgr.h`, a PCH-only interface, and a feature-local Pane/EventDispatcher declaration are rejected because the base has broad independent consumers.
- A concrete default callback, raw lowered deque fields, or a hand-authored scalar-deleting destructor are rejected.

## Implementation Contract

The class CPP formal is:

```cpp
#include "TimerHandler.h"
#include "TimerMgr.h"

[[CHILDREN]]
```

Exact body order and byte ownership remain on the by-memory children. The separate file route is a source-structure decision, not a binary range split or behavior change.

## Historical Assumptions

- Earlier documentation routed TimerHandler directly through TimerMgr and left a companion source as an unresolved possibility. UID000090 dependency closure selects the explicit `TimerHandler.h/.cpp` route required by Pane and EventDispatcher complete-base declarations.
- Historical Boost, EventDispatcher, NewHumanImageLib, and feature-owner labels remain rejected caller/decompiler pollution.

## Cross-References

- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
