*** UID:0001SR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ThreadManMessageId

## Status

- Kind: Win32 message-id group
- Owner class: [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- Likely declaring header: `util/Thread.h`
- Confidence: strong for values and dispatch sites, medium for final symbolic names.
- Reconstructable: yes, as source-level private `ThreadMan` message constants. Leave final enum code blank until the utility-thread header layout is settled.

## Values

| Value | Provisional name | Observed behavior |
| --- | --- | --- |
| `0x0464` | `THREADMAN_REGISTER_THREAD` | Adds a 20-byte [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) using `wParam`, `lParam`, and `*(wParam + 0x60)`. |
| `0x0465` | `THREADMAN_UNREGISTER_THREAD` | Finds a watch record by `threadObject == wParam` and removes it from the task list. |
| `0x0466` | `THREADMAN_CLEAR_THREAD_PROBE` | Finds a record by `threadObject == wParam`; if its deadline is not `-1`, clears the pending-watch byte. |
| `0x0467` | `THREADMAN_MARK_IDENTITY_BLOCKED` | Finds a record by `threadIdentity == wParam`, sets pending-watch true, and writes deadline sentinel `-1`. |
| `0x0468` | `THREADMAN_CLEAR_IDENTITY_PROBE` | Finds a record by `threadIdentity == wParam` and clears the pending-watch byte. |

## Notes

These are ordinary Win32 messages read by the ThreadMan worker with `PeekMessage(..., PM_REMOVE)`. They are separate from the 24-byte queue messages used by the generic [UID:0000EV][Thread](by-class/Thread.md) base.

IDA raw disassembly on 2026-05-25 shows [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) posting these ids with `PostThreadMessageW` to `ThreadManLayout::workerThreadId`.

The 2026-05-26 IDA MCP recheck still shows the wrapper starts as raw code and the worker loop dispatching the same numeric ids (`1124` through `1128`, or `0x0464` through `0x0468`).

2026-05-31 IDA MCP recheck:

- Raw disassembly at `0x00596d20-0x00596e0b` shows five `PostThreadMessageW` wrappers pushing `0x0464`, `0x0465`, `0x0466`, `0x0467`, and `0x0468`.
- IDA MCP decompilation of `0x00596e10-0x005970df` shows the worker loop using `MsgWaitForMultipleObjects(..., 0x1f4, 0x4ff)`, draining messages through the `PeekMessage` import alias at `dword_69BE8C`, and switching over cases `1124` through `1128`.
- The worker-loop case values match the wrapper-posted message values exactly.

## Open Questions

- Final symbolic names remain provisional until the `ThreadManWatchRecord` fields and all wrapper call sites are fully named.
- These are private Win32 thread messages, not the generic 24-byte queue items used by [UID:0000EV][Thread](by-class/Thread.md).

## Cross-References

- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
