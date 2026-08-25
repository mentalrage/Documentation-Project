*** UID:0000BX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008L | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RequestSyncGate

## Summary

`RequestSyncGate` is retained only as a historical/recovered-output support alias in the `Monitor.cpp` synchronization cluster. It is rejected as a separate original Thread field type or source class. The bytes formerly assigned to it at `0x00528710` and `0x00528720` are accepted `Monitor::Lock` and `Monitor::Unlock`; `Thread` uses `Monitor *m_resultMonitor` at `+0x54`. This page preserves the superseded interpretation and evidence without emitting duplicate declarations or bodies.

2026-06-14 live IDA MCP reconfirmed both helpers as exact modeled functions: `0x00528710` is a 12-byte wait wrapper, and `0x00528720` is a 30-byte release wrapper. B009's 2026-07-04 MCP session `eb7ce28b` reconfirmed the same starts/sizes, nine paired call refs, and no separate vtable/constructor/source route for a distinct emitted `RequestSyncGate` class.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: very strong that `Monitor` owns the functions and `Thread` uses a `Monitor *`; the alias spelling remains historical provenance only.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:00051Z][0x00528710-0x0052871c.MonitorLock](by-memory/0x00528710-0x0052871c.MonitorLock.md) | historical alias for `Monitor::Lock` | 12-byte helper. Live IDA decompiles it as `WaitForSingleObject(this[1], INFINITE)`; the exact child emits `Monitor::Lock()`. |
| [UID:000525][0x00528720-0x0052873e.MonitorUnlock](by-memory/0x00528720-0x0052873e.MonitorUnlock.md) | historical alias for `Monitor::Unlock` | 30-byte helper. Live IDA selects `ReleaseSemaphore` or `ReleaseMutex` from Monitor fields; the exact child emits `Monitor::Unlock()`. |

## Evidence

- IDA places the methods directly between [UID:00008L][Monitor](by-class/Monitor.md) construction/destruction code and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) construction.
- Live IDA shows the active field layout used by the two helpers: `+0x04` is the waited/released mutex handle, `+0x08` is the release-mode selector, and `+0x0c` is the semaphore handle.
- Behavior matches the lock/unlock side of monitor/condition control flow: the lock path waits, while the unlock path chooses `ReleaseSemaphore` or `ReleaseMutex`.
- `analyze_function` on 2026-06-14 reports the lock and unlock helpers are called together from seven synchronization consumers, including the cash-shop request wait/dispatch family at `0x00596400`, `0x00596620`, `0x00596760`, `0x00596810`, and `0x00596a00`; this supports a reusable gate helper rather than an isolated inline artifact.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the gate methods inside the exact monitor/condition synchronization cluster, including live Win32 callees, caller context, and padding around both methods.
- 2026-06-14 `lookup_funcs` reconfirmed the neighboring modeled bodies in the same executable island: `Monitor` constructor `0x005285e0-0x005286c8`, the two bodies historically labeled as RequestSyncGate at `0x00528710-0x0052873e`, `MonitorCondition` constructor `0x00528740-0x005287e0`, wait `0x00528810-0x00528855`, signal `0x00528860-0x00528892`, and scalar deleting destructors at `0x005288a0`/`0x005288f0`.
- [UID:00008L][Monitor](by-class/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) are attached to [UID:0000LI][Monitor](by-file/Monitor.md) at positions `10` and `20`, making this gate the remaining helper in the same source family.
- [UID:0000LI][Monitor](by-file/Monitor.md) has a valid `NexusTK/util/` path and retains this page only as historical alias evidence; emitted contents are Monitor and MonitorCondition.
- 2026-07-04 B009 MCP session `eb7ce28b` reconfirmed `0x00528710` size `0x0c`, `0x00528720` size `0x1e`, nine lock refs, nine unlock refs, `WaitForSingleObject` / `ReleaseSemaphore` / `ReleaseMutex` callees, clean `0xcc` padding, and the absence of any separate `RequestSyncGate` vtable, constructor, destructor, or allocation route inside UID0001CL.
- Current generated RingBuffer source uses the same behavior through `mMonitor->Lock()` and `mMonitor->Unlock()`, which is stronger source-shape evidence than the older recovered `RequestSyncGate` label for these bytes.

## Resolved Type Decision

- The Thread result synchronization field is `Monitor *m_resultMonitor`, not `RequestSyncGate *m_resultGate`. Current `Thread` construction/layout evidence, exact `Monitor` ordinal/type evidence, and accepted `Monitor::Lock`/`Unlock` ownership agree.
- No independent `RequestSyncGate` constructor, destructor, vtable, allocation route, UDT, or source declaration exists. A distinct class/type is therefore rejected rather than deferred.
- Older `RequestSyncGate` and `m_resultGate` occurrences are historical compatibility/search aliases only. They must not be copied into current declarations, draft source, IDA types, or duplicate method pages.

## Autogen And Reconstruction Notes

- Retained as a non-reconstructable support page owned by [UID:00008L][Monitor](by-class/Monitor.md), with no emitter position or formal source.
- The lock/unlock behavior is source-authored synchronization logic with exact Win32 call behavior, but exact children UID00051Z and UID000525 reconstruct it as `Monitor::Lock` / `Monitor::Unlock`.
- `RECONSTRUCTION_CPP CODE` remains blank intentionally. The accepted source model excludes duplicate `RequestSyncGate` output for `0x00528710` / `0x00528720`; this page is support/provenance only, while [UID:00008L][Monitor](by-class/Monitor.md) and [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) own the actual declarations and bodies.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The page records both exact helpers, field behavior, nine paired callers, cluster boundaries, resolved Thread field type, direct Monitor child routes, and explicit non-reconstructable/no-emitter/no-duplicate disposition. |
| Confidence `95` | Live IDA places both helpers inside the Monitor island and exposes no independent constructor, type, vtable, RTTI, object, or allocation route; the historical alias classification is closed. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)

## Changes

- 2026-08-15 B004 UID0000LI callback:
  - Closed the historical-alias decision at `92/95`: no independent constructor, UDT, vtable, RTTI, object, storage, or caller route supports a source `RequestSyncGate` class.
  - Canonical owner is now [UID:00008L][Monitor](by-class/Monitor.md), reconstructable is false, emitter and formal CPP/H remain blank, and exact children UID00051Z/UID000525 own `Monitor::Lock`/`Monitor::Unlock` without duplication.

- 2026-08-01 B008 accepted ThreadProc support incorporation:
  - Explicitly rejected `RequestSyncGate` as a separate Thread field type/source class and recorded current `Monitor *m_resultMonitor` at `Thread+0x54`.
  - Replaced the open/deferred type question with a resolved decision backed by absent independent construction/vtable/type evidence and accepted Monitor ownership.
  - Preserved all historical alias evidence, scores, owner/emitter attachment, and blank formal C++; no duplicate lock/unlock source is emitted from this page.
- 2026-07-04 B009 UID0001CL callback:
  - Historicalized `RequestSyncGate` for `0x00528710` / `0x00528720` as a recovered-output/support alias; UID0001CL emits these bytes as `Monitor::Lock` and `Monitor::Unlock`.
  - Evidence: MCP session `eb7ce28b` reconfirmed starts/sizes, nine paired refs, Win32 callees, padding, and no separate vtable/constructor/allocation route; generated RingBuffer source already calls `mMonitor->Lock()` and `mMonitor->Unlock()`.
  - No metadata change: this support page remains attached to [UID:0000LI][Monitor](by-file/Monitor.md), but its formal C++ stays blank to avoid duplicate emission.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: scored `78/86`.
  - After: scored `85/87`; owner/emitter remains [UID:0000LI][Monitor](by-file/Monitor.md); final C++ remains blank below the active `90/90+` code-entry gate.
  - Evidence: live IDA MCP `analyze_function` confirmed `0x00528710` size `0x0c` with `WaitForSingleObject(this[1], INFINITE)`, `0x00528720` size `0x1e` with `ReleaseSemaphore`/`ReleaseMutex` selected by `this + 8`, identical paired caller families, and `lookup_funcs` reconfirmed neighboring `Monitor`/`MonitorCondition` cluster functions through `0x00528929`.
- 2026-06-07 A004 evidence/position refresh:
  - Before: scored `74/84`, attached to [UID:0000LI][Monitor](by-file/Monitor.md), but left the child position blank and summarized only the high-level lock/unlock behavior.
  - After: scored `78/86`, set position `30`, added a method table with exact wait/release behavior, linked the updated `Monitor` and `MonitorCondition` sibling attachments, and documented the final-C++ blockers.
  - Evidence: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the gate methods, live `WaitForSingleObject`/`ReleaseMutex`/`ReleaseSemaphore` callees, placement between monitor and condition bodies, and padding; [UID:00008L][Monitor](by-class/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) are now attached under the same parent at positions `10` and `20`.
- 2026-06-02:
  - Before: scored `68/72`, reconstructability and parent blank.
  - After: scored `74/84`, marked reconstructable, and attached to [UID:0000LI][Monitor](by-file/Monitor.md) with C++ blank.
  - Why: the exact monitor/condition aggregate and updated Monitor file page support high-confidence ownership, while the final helper declaration shape remains unresolved.
- 2026-05-30: Changed completion/confidence from `0/0` to `68/72`.
  - Before: The page was unevaluated despite documenting lock/unlock behavior, observed layout, placement, and open class-identity caveats.
  - After: Scored as moderate completion and confidence because method behavior is clear but whether this was a real original named class remains unresolved.
  - Evidence: Existing method list, IDA locality notes, generated layout, and Monitor/MonitorCondition cross-references establish the helper behavior and ownership uncertainty.
