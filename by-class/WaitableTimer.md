*** UID:0000FY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WaitableTimer

## Summary

`WaitableTimer` is a Win32 multimedia timer/event wrapper. It owns a completion event, a critical section, a running flag, a multimedia timer id, and a short-lived callback gate event.

## Likely Original Placement

- Source: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- Proposed path: `util/WaitableTimer.cpp`
- Confidence: very strong for layout, binary range, vtable identity, and utility source ownership; medium for final public method names and live caller path.

## Methods

- `0x005c0ff0-0x005c109c`: constructor.
- `0x005c10a0-0x005c1111`: non-deleting cleanup body.
- `0x005c1120-0x005c1167`: raw start/register helper; no IDA function object.
- `0x005c1170-0x005c11b4`: raw cancel/reset helper; no IDA function object.
- `0x005c11c0-0x005c120e`: timer callback/completion helper.
- `0x005c1210-0x005c129a`: scalar deleting destructor.

## Layout

See [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md). The important current correction is field `+0x28`: generated metadata calls it `m_hWorkerThread`, but IDA shows the field is created through `g_pfnCreateEventW` / `dword_69BE3C`, signaled by the raw start helper after `timeSetEvent` succeeds, waited and closed by the callback, and closed by cancel/destructor paths. Treat it as a callback gate event, not a thread handle.

## Vtable

IDA confirms a one-slot table `??_7WaitableTimer@@6B@` at `0x00631188`, with RTTI pointer at `0x00631184` and deleting destructor slot `0x005c1210`. Constructor/cleanup/destructor stores land at `0x005c1020`, `0x005c10a8`, and `0x005c121b`.

See [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md). The dword at `0x0063118c` is the complete-object locator for `WeatherLayerPane`, not a second `WaitableTimer` virtual slot.

## Evidence

- Constructor creates an unnamed auto-reset event and initializes a critical section.
- `0x005c1120` registers the callback through `timeSetEvent`, stores the timer id at `+0x24`, and uses a secondary event at `+0x28` to prevent the callback from racing ahead of registration.
- `0x005c1170` cancels the active multimedia timer and resets the event fields without deleting the critical section or completion event.
- Callback clears running state, waits/closes the callback gate event, resets fields, sets the completion event, and leaves the critical section.
- Destructor kills the multimedia timer through `timeKillEvent`, closes handles, and deletes the critical section.
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md) is already attached to [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) and records the complete executable island inventory, exact raw helper splits, Wave2/prewave cross-checks, callback xref, and the reason final C++ remains below the reconstruction gate.
- [UID:0001NY][0x005c1120-0x005c11b4.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b4.WaitableTimerRawStartStop.md), [UID:0002L8][0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer.md), and [UID:0002L9][0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer.md) separate the two raw non-IDA-modeled helper bodies from the modeled constructor/cleanup/callback/destructor functions.
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md) resolves the `+0x28` generated-name error as a callback gate event, and [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md) proves the one-slot vtable boundary before `WeatherLayerPane` RTTI.
- 2026-06-10 B001-037 live IDA MCP reconfirmed modeled function ranges at `0x005c0ff0-0x005c109c`, `0x005c10a0-0x005c1111`, `0x005c11c0-0x005c120e`, and `0x005c1210-0x005c129a`; raw helper starts `0x005c1120` and `0x005c1170` still have no IDA function objects; the callback xref from `0x005c1149` reaches `0x005c11c0`; and the one-slot vtable at `0x00631188` has constructor/cleanup/destructor store xrefs from `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- Current `source-3/simroot_v2/class_WaitableTimer.cpp` emits `0x005c10a0` as `WaitableTimer::Cleanup` and `0x005c11c0` as global `WaitableTimerCompletion_5C11C0`, but omits raw helper starts `0x005c1120` and `0x005c1170`; names remain provisional.
- No direct constructor callers were found in this pass.

## Parent Attachment Decision

Attach this class to [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md). The file page is scored `86/80`, proposes `NexusTK/util/`, and documents the same compact Win32 multimedia timer/event island. The executable aggregate is already attached to that file root, while the layout and vtable pages both point to the same owner module.

Keep `RECONSTRUCTION_CPP` blank. The binary proves this is reconstructable source, but the live caller/lifetime path, final public names for the raw start/cancel helpers, and final method spelling for the callback/cleanup body are still below the final-source threshold.

## Open Questions

- Live owner/caller path for `WaitableTimer`.
- Final source spelling for the raw start/register and cancel/reset helpers.
- Whether this should merge with [UID:0000OT][TimerMgr](by-file/TimerMgr.md) or remain an independent utility wrapper. Current evidence favors independent utility placement.

## Cross-References

- File: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- Memory: [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- Raw helpers: [UID:0001NY][0x005c1120-0x005c11b4.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b4.WaitableTimerRawStartStop.md)
- Start helper: [UID:0002L8][0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer.md)
- Cancel helper: [UID:0002L9][0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer.md)
- Layout: [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- Vtable: [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- Related: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the constructor/cleanup/raw start-stop/callback/destructor method list, field-layout correction for `+0x28`, vtable evidence, timer/event behavior, and simroot omission notes; confidence remains capped by missing constructor callers and provisional raw helper names.

- 2026-05-31 reconstructable metadata and raw helper split:
  - What existed before: reconstructable status was blank and the raw start/cancel bodies were represented only through the combined raw helper range.
  - Changed to: `RECONSTRUCTABLE:TRUE` with no parent/code attachment, plus exact child links for the start/register and cancel/reset raw helpers.
  - Summary/evidence: IDA MCP verifies these are NexusTK-owned source bodies, but final source names and caller path remain below the 95+ attachment/code gate.
- 2026-06-07 A008 parent-chain refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:78`, and no autogen parent even though the file page and exact child/type evidence already identified `util/WaitableTimer.cpp` as the source root.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:82`, and `AUTOGEN_PARENT_UID:0000P7`.
  - Summary/evidence: existing IDA-backed by-memory/type pages document the full executable island, raw start/cancel helper split, callback-gate event correction at `+0x28`, one-slot vtable boundary, `CreateEventW` dispatch dependency, generated-output omissions, and the separate `TimerMgr` ownership caveat. C++ remains blank because live callers and final helper names are unresolved.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed the modeled method ranges, raw-helper non-function status, callback xref, one-slot vtable dword, vtable-store xrefs, and the `0x0063118c` `WeatherLayerPane` successor boundary. The class now clears the direct-parent gate for exact `WaitableTimer` vtable data, while C++ remains blank because live callers and final helper names are still below final-source quality.
