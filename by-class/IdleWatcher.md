*** UID:00006C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class IdleWatcher : public Pane, public Singleton<IdleWatcher>
{
public:
    explicit IdleWatcher(unsigned int idleIntervalMs);
    virtual ~IdleWatcher();

    bool IsIdle() const { return m_isIdle; }
    void ResetIdleTimer();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    bool m_isIdle;
    unsigned int m_idleIntervalMs;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IdleWatcher

## Summary

`IdleWatcher` is a `0x100`-byte `Pane`-derived, `Singleton<IdleWatcher>` app helper. User pointer/key activity clears idle state and restarts timer ID 0; the inherited TimerHandler callback marks the object idle, rearms the same interval, and returns true. An inline `IsIdle()` exposes the state to MainMenu without an out-of-line body.

## Likely Original Placement

- Source: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md), projected as `NexusTK/app/IdleWatcher.cpp`.
- Caller context: [UID:0000HG][Application](by-file/Application.md) constructs the singleton from `Application::Startup`, but current source-structure docs keep `IdleWatcher` separate from `Application.cpp`.
- Placement decision: standalone `NexusTK/app/IdleWatcher.cpp`, not `Application.cpp`. Application owns startup/shutdown callsites only.
- Confidence: very strong for behavior, class shape, source/compiler split, timer contract, global lifecycle, and placement; exact private identifier spelling remains inferred and caps the score below 95.

## Methods

- [UID:0004LE][0x004cfe60-0x004cfeba.IdleWatcherConstructor](by-memory/0x004cfe60-0x004cfeba.IdleWatcherConstructor.md) - `Pane(4)`, Singleton base, initial idle state, and caller-supplied interval.
- [UID:0004LF][0x004cfec0-0x004cfee9.IdleWatcherDestructor](by-memory/0x004cfec0-0x004cfee9.IdleWatcherDestructor.md) - empty authored body; implicit Singleton clear and Pane teardown.
- [UID:0004LG][0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer](by-memory/0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md) - clears idle, removes pending owner timers, and schedules `(0, interval, 0, 0)`.
- [UID:0004LH][0x004cff20-0x004cff37.IdleWatcherOnTimer](by-memory/0x004cff20-0x004cff37.IdleWatcherOnTimer.md) - marks idle, rearms `(0, interval, 0, 0)`, returns true, and ignores callback arguments.
- [UID:0004LI][0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks](by-memory/0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks.md) and [UID:0004LJ][0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor](by-memory/0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor.md) are compiler-only, non-emitting children.

## Inheritance And Complete Layout

| Offset | Source role | Evidence |
| ---: | --- | --- |
| `+0x00` | `Pane` primary base, including GrafPort/LObject chain | Primary RTTI/vtable view; constructor calls `Pane(4)`. |
| `+0xa0` | inherited EventHandler subobject | RTTI PMD and `this - 0xa0` destructor adjustor. |
| `+0xa4` | inherited TimerHandler subobject | RTTI PMD, `this - 0xa4` adjustor, and OnTimer tertiary slot. |
| `+0xf8` | empty `Singleton<IdleWatcher>` base plus first derived `bool m_isIdle` through EBO | Singleton RTTI PMD and all flag reads/writes. |
| `+0xf9-+0xfb` | natural compiler alignment | Places following unsigned dword at `+0xfc`; no explicit source field. |
| `+0xfc` | `unsigned int m_idleIntervalMs` | Startup 20000 and both ScheduleTimer delay arguments. |

- RTTI hierarchy `0x00648610` enumerates IdleWatcher, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<IdleWatcher>`.
- Allocation size is exactly `0x100`; the class adds no storage beyond `m_idleIntervalMs`.

## Touched State

| State or data | Evidence | Notes |
| --- | --- | --- |
| singleton pointer | constructor/destructor behavior plus [UID:0002VY][0x0069af1c-0x0069af20.g_pIdleWatcher](by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md) | Existing exact global page emits the zero-initialized definition. Publication/clear are inlined Singleton base effects, not handwritten assignments. |
| pane base/vtables | constructor, destructor, and [UID:00025H][0x0061b340-0x0061b660.HourIconsIdleReadOnlyData](by-memory/0x0061b340-0x0061b660.HourIconsIdleReadOnlyData.md) | Confirms this is a pane-derived class with a vtable island in the mixed UI `.rdata` range. |
| idle flag | `0x004cfef0`, `0x004cff20`, MainMenu `0x004f7679` | Activity clears `m_isIdle`, timer expiry sets it, and inline `IsIdle()` explains the external direct load while retaining private storage. |
| interval | constructor `+0xfc`, both scheduling sites | Unsigned millisecond delay; initial value 20000 from Application startup. |
| timer manager path | [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) | The scheduling callee is generic `TimerHandler`/`TimerMgr` code, so timer dependency does not move ownership out of `app/`. |

## Live IDA Evidence

- Rechecked on 2026-07-13 against live session `c81909be`; all exact ranges, calls, bytes, xrefs, RTTI/PMDs, slots, and field routes used by the accepted split succeeded.
- `lookup_funcs` confirms `0x004cfe60` size `0x5a`, `0x004cfec0` size `0x29`, `0x004cfef0` size `0x30`, `0x004cff20` size `0x17`, `0x004cff37` and `0x004cff42` size `0xb`, and `0x004cff50` size `0x5f`; `0x004cffaf` is not a function and is the following padding byte.
- IDA MCP shows the constructor is called from `Application::Startup` at `0x004f5ffe`.
- `0x004cfef0` has direct callers at `0x004a72f6` after pointer-event classification and `0x004a7490` after key/text-event classification.
- Decorated RTTI/vtable names exist for `IdleWatcher` at primary vtable `0x0061b56c`, secondary vtable `0x0061b5b8`, and tertiary vtable `0x0061b5e8`. Constructor, non-deleting destructor, and scalar deleting destructor write all three vtable pointers.
- Vtable slots anchor the source methods: primary slot `0x0061b56c -> 0x004cff50`, secondary slot `0x0061b5b8 -> 0x004cff37`, tertiary destructor slot `0x0061b5e8 -> 0x004cff42`, and tertiary callback slot `0x0061b5ec -> 0x004cff20`.
- `xrefs_to 0x0069af1c` confirms constructor assignment at `0x004cfe85`, clears at `0x004cfeda` and `0x004cff70`, application idle reads at `0x004a72f0` and `0x004a748a`, and application shutdown/session reads at `0x004f6652` and `0x004f7679`.
- Constructor decompilation shows base `Pane` construction, singleton assignment, active flag initialization at `+0xf8`, interval/argument storage at `+0xfc`, and three `IdleWatcher` vtable stores.
- `0x004cfec0` decompiles as the non-deleting destructor: restore all three vtables, clear the singleton, and call base teardown.
- `0x004cfef0` decompiles as timer reset/schedule behavior: clear `+0xf8`, call `sub_597600(this + 0xa4)`, then call `sub_5975e0(this + 0xa4, 0, *(this + 0xfc), 0, 0)`.
- `0x004cff20` is the TimerHandler tertiary `OnTimer` override: set idle, rearm the interval, and return true.
- Raw byte checks confirm internal `0x004cfeba-0x004cfec0`, `0x004cfee9-0x004cfef0`, `0x004cff4d-0x004cff50`, and outer `0x004cffaf-0x004cffb0` alignment.
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) records `Application::Startup` as the lifecycle context and lists `IdleWatcher` among startup singleton constructors rather than application-shell method bodies.
- [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md) now carries the projected path `NexusTK/app/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md).
- [UID:00025H][0x0061b340-0x0061b660.HourIconsIdleReadOnlyData](by-memory/0x0061b340-0x0061b660.HourIconsIdleReadOnlyData.md) records the `IdleWatcher` vtable/read-only data island in the broader UI `.rdata` span.
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) documents the timer schedule wrapper as generic `TimerHandler` code with broad caller fan-in.

## Boundary And Padding Notes

- [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md) records the corrected exclusive end at `0x004cffaf`; byte `0x004cffae` is the final operand byte of the `retn 4`.
- [by-memory/-ignored.md](by-memory/-ignored.md) records `0x004cfe5f-0x004cfe60` as padding before the constructor and `0x004cffaf-0x004cffb0` as padding before `ImageLib`.
- It also records the three internal pads separating constructor/destructor/reset/scalar children.
- The two adjustor thunks and scalar deleting destructor remain compiler-only and are regenerated from this class declaration.

## Resolved Source Questions And Negative Evidence

- `Activate` is superseded by TimerHandler `OnTimer`; `ResetIdleTimer` is the activity helper.
- `m_isIdle`, inline `IsIdle() const`, and `m_idleIntervalMs` are the best source-facing names. Exact original spelling remains inferred but no behavioral/type blocker remains.
- Public-field and friendship models are rejected; the established inline-accessor pattern exactly explains MainMenu's direct load.
- Do not emit raw global assignments/clears, vptrs, explicit padding, adjustors, scalar wrapper, RTTI, or vtable arrays.
- Do not absorb the class into Application.cpp or create a duplicate by-global page.

## Cross-References

- File: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md)
- Caller/module context: [UID:0000HG][Application](by-file/Application.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:0000A2][Pane](by-class/Pane.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Memory: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md), [UID:00025H][0x0061b340-0x0061b660.HourIconsIdleReadOnlyData](by-memory/0x0061b340-0x0061b660.HourIconsIdleReadOnlyData.md), [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- Exact children: UID0004LE, UID0004LF, UID0004LG, UID0004LH, UID0004LI, and UID0004LJ as linked under Methods.
- Source structure: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-13 B001 Gate-1-accepted class/source implementation:
  - Changed from `86/90`, blank position/formal C++, provisional active/Activate/global/placement language, and no complete layout.
  - Changed to `92/94`, emitter position 10, complete `Pane, Singleton<IdleWatcher>` declaration with inline `IsIdle`, exact fields/virtuals, `[[CHILDREN]]`, real child links, and complete RTTI/layout/source/compiler evidence.
  - Historical manual-global, public-field, Application absorption, unresolved callback, and handwritten compiler-glue assumptions are preserved above as rejected/superseded alternatives.

- Completion/confidence score update: existed before as `0/0`; changed to `66/74`. Summary: singleton purpose, startup construction, method list, IDA-confirmed boundaries, and open timer/source-placement questions are documented, but the page is still a compact summary and timer callback semantics remain unresolved. Evidence: `0x004cfe60-0x004cffaf.IdleWatcher`, Application startup caller, Pane/EventDispatcher relationships, and open `0x005975e0` timer target.
- 2026-06-02 documentation expansion:
  - What existed before: the page was a compact summary scored `66/74`, with unresolved source placement and timer-target wording.
  - Changed to: scores `72/80`, app helper placement through [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md), touched-state table, vtable/read-only data evidence, timer-wrapper dependency evidence, and boundary/padding notes.
  - Summary/evidence: existing IDA-backed pages confirm startup construction, corrected function end, adjacent padding, generic timer-handler scheduling, and `IdleWatcher` vtable data. `RECONSTRUCTABLE` and C++ remain blank because the class declaration, field names, and timer event names are not final-source quality.
- 2026-06-05 live IDA rescore:
  - Changed from: `COMPLETION:72`, `CONFIDENCE:80`, reconstructable/parent unset.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000K0`.
  - Reason for score increase: live IDA confirmed the previously omitted `0x004cfec0` non-deleting destructor and `0x004cfef0` timer reset/schedule helper, exact sizes for all local methods, constructor and idle-scheduler callers, three decorated `IdleWatcher` vtables, vtable slots for destructor thunks and callback/activation, singleton reads/writes at `0x0069af1c`, timer remove/schedule calls on the `+0xa4` subobject, stored interval field at `+0xfc`, active flag at `+0xf8`, and padding around the local functions. The score remains below final reconstruction because final source-facing field names and callback names are still inferred from behavior.
