*** UID:0001WB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ThreadManWatchRecord
{
    Thread *thread;
    void   *context;
    DWORD   watchedThreadId;
    bool    probePending;
    DWORD   deadlineTick;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThreadManWatchRecord

## Status

- Kind: POD/list record
- Owner class: [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- Storage: `ThreadManLayout::watchList`
- Size: `0x14` bytes
- Confidence: strong for size, access offsets, owner, and source-facing field names; medium-high for the original name of the opaque registration context.

## Layout

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `thread` | Registration message `0x0464` stores `wParam`; unregister/probe message paths search records by this value. Fatal watchdog text prints this value with `%p`. |
| `0x04` | `context` | Registration message stores `lParam`. Later direct use has not been confirmed in the worker loop, so the name remains behavior-faithful rather than domain-specific. |
| `0x08` | `watchedThreadId` | Registration copies `*(thread + 0x60)` here. The generic `Thread` constructor uses `Thread+0x60` as its worker thread-id output field, and messages `0x0467`/`0x0468` search records by this value. |
| `0x0c` | `probePending` | Periodic scan sets this byte when a probe/deadline is active. Message paths clear or force it depending on record state. |
| `0x10` | `deadlineTick` | Periodic scan writes `timeGetTime() + 10000`. Message id `0x0467` writes `-1` as a sentinel. |

## Behavior

The record is managed through a `List` constructed as `List(20, 16)` by `ThreadMan::ThreadMan`. The worker loop treats the records as watchdog state for live thread objects. Under a debugger, the fatal timeout scan is skipped.

`deadlineTick == 0xffffffff` is the blocked sentinel set by message `0x0467`; ordinary probe clears through message `0x0466` only occur when the deadline is not this sentinel. The `watchedThreadId` name is preferred over the older `threadIdentity` wording because current evidence ties `Thread+0x60` to the watched thread's worker thread id, while [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md) uses `m_workerThreadId` for the manager thread id.

B008 2026-06-19 scalar-wrapper recheck confirms that [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) deletes the heap `List` containing these records through the list object's vtable at `ThreadMan + 0x10`; it is not record-level cleanup, `delete[]`, or inline-array storage.

B012 independently rechecked the relationship from the scalar wrapper side. [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) only deletes/nulls `ThreadMan::m_watchList`; it does not iterate records, clear record fields, or prove record-level destructor behavior. Keep `watchedThreadId` for record `+0x08` to avoid confusion with [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md)'s manager `m_workerThreadId`.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x00596bf0` confirms [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md) constructs the backing list as `List(20, 16)`, giving a `0x14` byte record size with 16 preallocated records.
- 2026-05-31 IDA MCP decompilation of `0x00596e10` confirms message `0x0464` stores `wParam` at `+0x00`, `lParam` at `+0x04`, copies `*(threadObject + 0x60)` to `+0x08`, clears byte `+0x0c`, and clears deadline `+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x00596e10` confirms messages `0x0465`/`0x0466` search by `+0x00`, messages `0x0467`/`0x0468` search by `+0x08`, `0x0467` sets byte `+0x0c` and deadline `+0x10` to `-1`, and `0x0468` clears byte `+0x0c`.
- 2026-05-31 IDA MCP decompilation of the periodic watchdog scan confirms byte `+0x0c` is the pending/probe flag, dword `+0x10` is the deadline tick, and the fatal timeout text prints the `+0x00` thread-object pointer with `%p`.
- 2026-06-08 Agent-A002 live IDA MCP `py_eval` reconfirmed the owning `ThreadMan` method boundaries: constructor `0x00596bf0-0x00596d13`, worker loop `0x00596e10-0x005970df`, worker entry `0x00597100-0x005971ad`, and scalar deleting destructor `0x005974f0-0x0059756e`. The raw wrapper starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` remain non-functions, so this record stays documented as a `ThreadMan` watch-list layout rather than as standalone raw helper ownership.
- 2026-06-20 B003 source-quality review tied `+0x08` to a real watched thread id by correlating registration's copy from `Thread+0x60` with the generic `Thread` constructor's thread-id output slot. The same review selected `thread`, `context`, `watchedThreadId`, `probePending`, and `deadlineTick` as the current source-facing field names.
- 2026-06-19 B008 destructor recheck adds the list-lifetime side of this layout: the ordinary destructor and scalar deleting wrapper delete/null the owning `ThreadMan::m_watchList` pointer as a heap `List` object, while individual `ThreadManWatchRecord` elements remain plain 20-byte records managed by that list.

## Parent Assignment

Assign this record layout to [UID:0000EW][ThreadMan](by-class/ThreadMan.md). The record is the element type of `ThreadManLayout::m_watchList`, is allocated by the `ThreadMan` constructor as `List(20, 16)`, and is read/written only by the `ThreadMan` worker-loop/watchdog message cases documented here. The child now clears `88/90`, the direct class parent is `88/89`, and [UID:0000OR][Thread](by-file/Thread.md) remains the source-file context at `89/85`.

## Cross-References

- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md)
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)

## Changes

- 2026-06-20 B003 Rule 26 incorporation:
  - Before: `85/88`, field `+0x08` was still named `threadIdentity`, the final field-name blocker was open, and C++ was blank.
  - After: `88/90`, added draft `ThreadManWatchRecord` C++ and source-facing fields `thread`, `context`, `watchedThreadId`, `probePending`, and `deadlineTick`. Evidence now records that `watchedThreadId` is copied from `Thread+0x60`, the generic `Thread` worker-thread-id slot, while `0xffffffff` is the blocked sentinel deadline.
- 2026-06-21 B008 scalar-wrapper support sync:
  - Summary/evidence: added the destructor ownership note that [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) deletes the owning heap `List *m_watchList`, not the records directly. Metadata remains unchanged.
- 2026-06-22 B012 source-quality implementation:
  - Summary/evidence: added B012's recheck that the scalar wrapper deletes only the owning `List *m_watchList` object, not individual records, and preserved `watchedThreadId` as the preferred `+0x08` vocabulary. Metadata remains unchanged.
- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing record notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked the worker-loop message cases and watchdog scan. The score remains below final-source level because final original field names and the exact semantic name for the cached `Thread + 0x60` identity still need derived-thread layout review.
- 2026-06-08 Agent-A002 Batch 134 assignment-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, no autogen parent.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000EW`.
  - Summary/evidence: live IDA MCP reconfirmed the relevant `ThreadMan` method boundaries, raw wrapper caveats, vtable refs, and singleton refs through the class parent refresh. The record is directly owned by the `ThreadMan` watch list, so both child and direct class parent now meet the strict `85/85` gate.
