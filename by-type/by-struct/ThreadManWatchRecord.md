*** UID:0001WB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ThreadManWatchRecord

## Status

- Kind: POD/list record
- Owner class: [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- Storage: `ThreadManLayout::watchList`
- Size: `0x14` bytes
- Confidence: strong for size and access offsets, medium for final field names.

## Layout

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `threadObject` | Registration message `0x0464` stores `wParam`; unregister/probe message paths search records by this value. Fatal watchdog text prints this value with `%p`. |
| `0x04` | `registerContext` | Registration message stores `lParam`. Later direct use has not been confirmed in the worker loop. |
| `0x08` | `threadIdentity` | Registration copies `*(threadObject + 0x60)` here. Message ids `0x0467` and `0x0468` search records by this field. |
| `0x0c` | `watchdogPending` | Periodic scan sets this byte when a probe/deadline is active. Message paths clear or force it depending on record state. |
| `0x10` | `deadlineTick` | Periodic scan writes `timeGetTime() + 10000`. Message id `0x0467` writes `-1` as a sentinel. |

## Behavior

The record is managed through a `List` constructed as `List(20, 16)` by `ThreadMan::ThreadMan`. The worker loop treats the records as watchdog state for live thread objects. Under a debugger, the fatal timeout scan is skipped.

The final field names are provisional. The field at `0x08` may be a thread id, owner id, or another identity cached from the generic [UID:0000EV][Thread](by-class/Thread.md) object at offset `0x60`; more derived-thread layout review is needed before naming it in migrated source.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x00596bf0` confirms [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md) constructs the backing list as `List(20, 16)`, giving a `0x14` byte record size with 16 preallocated records.
- 2026-05-31 IDA MCP decompilation of `0x00596e10` confirms message `0x0464` stores `wParam` at `+0x00`, `lParam` at `+0x04`, copies `*(threadObject + 0x60)` to `+0x08`, clears byte `+0x0c`, and clears deadline `+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x00596e10` confirms messages `0x0465`/`0x0466` search by `+0x00`, messages `0x0467`/`0x0468` search by `+0x08`, `0x0467` sets byte `+0x0c` and deadline `+0x10` to `-1`, and `0x0468` clears byte `+0x0c`.
- 2026-05-31 IDA MCP decompilation of the periodic watchdog scan confirms byte `+0x0c` is the pending/probe flag, dword `+0x10` is the deadline tick, and the fatal timeout text prints the `+0x00` thread-object pointer with `%p`.
- 2026-06-08 Agent-A002 live IDA MCP `py_eval` reconfirmed the owning `ThreadMan` method boundaries: constructor `0x00596bf0-0x00596d13`, worker loop `0x00596e10-0x005970df`, worker entry `0x00597100-0x005971ad`, and scalar deleting destructor `0x005974f0-0x0059756e`. The raw wrapper starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` remain non-functions, so this record stays documented as a `ThreadMan` watch-list layout rather than as standalone raw helper ownership.

## Parent Assignment

Assign this record layout to [UID:0000EW][ThreadMan](by-class/ThreadMan.md). The record is the element type of `ThreadManLayout::watchList`, is allocated by the `ThreadMan` constructor as `List(20, 16)`, and is read/written only by the `ThreadMan` worker-loop/watchdog message cases documented here. The child now clears `85/88`, the direct class parent was refreshed to `86/85`, and [UID:0000OR][Thread](by-file/Thread.md) remains the source-file context at `89/85`.

## Cross-References

- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md)
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing record notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked the worker-loop message cases and watchdog scan. The score remains below final-source level because final original field names and the exact semantic name for the cached `Thread + 0x60` identity still need derived-thread layout review.
- 2026-06-08 Agent-A002 Batch 134 assignment-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, no autogen parent.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000EW`.
  - Summary/evidence: live IDA MCP reconfirmed the relevant `ThreadMan` method boundaries, raw wrapper caveats, vtable refs, and singleton refs through the class parent refresh. The record is directly owned by the `ThreadMan` watch list, so both child and direct class parent now meet the strict `85/85` gate.
