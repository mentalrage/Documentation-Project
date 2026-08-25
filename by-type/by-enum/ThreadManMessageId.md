*** UID:0001SR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ThreadManMessageId
{
    THREADMAN_REGISTER_THREAD         = WM_USER + 0x64, // 0x0464
    THREADMAN_UNREGISTER_THREAD       = WM_USER + 0x65, // 0x0465
    THREADMAN_CLEAR_THREAD_PROBE      = WM_USER + 0x66, // 0x0466
    THREADMAN_MARK_THREAD_ID_BLOCKED  = WM_USER + 0x67, // 0x0467
    THREADMAN_CLEAR_THREAD_ID_BLOCKED = WM_USER + 0x68  // 0x0468
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThreadManMessageId

## Status

- Kind: Win32 message-id group
- Owner class: [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- Likely declaring header: `util/Thread.h`
- Confidence: strong for values, dispatch sites, watch-record effects, direct class ownership, and current source-facing symbolic names.
- Assignment gate: this enum now clears `88/91`, and the direct owner [UID:0000EW][ThreadMan](by-class/ThreadMan.md) is `88/89`, so `AUTOGEN_PARENT_UID` points to `0000EW`.
- Reconstructable: yes, as source-level private `ThreadMan` message constants.

## Values

| Value | Provisional name | Observed behavior |
| --- | --- | --- |
| `0x0464` / `1124` | `THREADMAN_REGISTER_THREAD` | Adds a 20-byte [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) using `wParam`, `lParam`, and `*(wParam + 0x60)`. |
| `0x0465` / `1125` | `THREADMAN_UNREGISTER_THREAD` | Finds a watch record by `threadObject == wParam` and removes it from the task list. |
| `0x0466` / `1126` | `THREADMAN_CLEAR_THREAD_PROBE` | Finds a record by `threadObject == wParam`; if its deadline is not `-1`, clears the pending-watch byte. |
| `0x0467` / `1127` | `THREADMAN_MARK_THREAD_ID_BLOCKED` | Finds a record by `watchedThreadId == wParam`, sets pending-watch true, and writes deadline sentinel `-1`. |
| `0x0468` / `1128` | `THREADMAN_CLEAR_THREAD_ID_BLOCKED` | Finds a record by `watchedThreadId == wParam` and clears the pending-watch byte. |

## Notes

These are ordinary Win32 messages read by the ThreadMan worker with `PeekMessage(..., PM_REMOVE)`. They are separate from the 24-byte queue messages used by the generic [UID:0000EV][Thread](by-class/Thread.md) base.

IDA raw disassembly on 2026-05-25 shows [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) posting these ids with `PostThreadMessageW` to `ThreadManLayout::workerThreadId`.

The numeric values are `WM_USER + 0x64` through `WM_USER + 0x68`. The last two names use `THREAD_ID` rather than the older `IDENTITY` wording because wrapper posts pass `GetCurrentThreadId()` as `wParam`, worker-loop cases search [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) `watchedThreadId`, and registration copies that field from generic `Thread+0x60`.

The 2026-05-26 IDA MCP recheck still shows the wrapper starts as raw code and the worker loop dispatching the same numeric ids (`1124` through `1128`, or `0x0464` through `0x0468`).

2026-05-31 IDA MCP recheck:

- Raw disassembly at `0x00596d20-0x00596e0b` shows five `PostThreadMessageW` wrappers pushing `0x0464`, `0x0465`, `0x0466`, `0x0467`, and `0x0468`.
- IDA MCP decompilation of `0x00596e10-0x005970df` shows the worker loop using `MsgWaitForMultipleObjects(..., 0x1f4, 0x4ff)`, draining messages through the `PeekMessage` import alias at `dword_69BE8C`, and switching over cases `1124` through `1128`.
- The worker-loop case values match the wrapper-posted message values exactly.

2026-06-11 A004 live IDA MCP and conversion refresh:

- `py_eval` confirms the wrapper starts `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` still have no IDA function objects, preserving the raw-helper caveat documented by [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md).
- The same live check confirms the worker loop remains modeled as `sub_596E10`, range `0x00596e10-0x005970df`, and is called from worker entry `0x00597100` at `0x00597140`.
- `int_convert.py` verifies `0x0464` through `0x0468` as decimal `1124` through `1128` (Verified with int_convert.py). It also verifies the worker-loop wait constants `0x1f4` as `500` and `0x4ff` as `1279` (Verified with int_convert.py).
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) is already assigned to [UID:0000EW][ThreadMan](by-class/ThreadMan.md) and records the `0x14` / `20` byte watch-record size (Verified with int_convert.py), matching the message-case effects here.

## Parent Assignment

Assign this enum to [UID:0000EW][ThreadMan](by-class/ThreadMan.md). The numeric constants are private to the `ThreadMan` worker-message path, every value is posted by the raw `ThreadMan` wrappers, and every value is consumed by the `ThreadMan` worker loop to mutate the `ThreadMan` watch-list record. The enum now clears `88/91`; the direct class parent clears `88/89`; and the source-file context [UID:0000OR][Thread](by-file/Thread.md) is already the accepted parent for the owning class.

## Score Rationale

- Completion is `88` because the page now records exact numeric ids, `WM_USER` expressions, verified decimal forms, live raw-wrapper and worker-loop status, direct watch-record effects, the direct-owner gate, and draft enum C++.
- Confidence is `91` because current IDA MCP still agrees with the existing raw-wrapper/worker-loop evidence, the conversions were rechecked with `int_convert.py`, and the final two values now use the resolved `watchedThreadId` semantics. Confidence stays below final-source level only because exact original macro spelling cannot be recovered from the binary.

## Remaining Caveat

These are private Win32 thread messages, not the generic 24-byte queue items used by [UID:0000EV][Thread](by-class/Thread.md). Exact original macro spelling remains unknowable from the binary alone, but the current names are behavior-backed and source-facing enough for documentation and draft C++.

## Cross-References

- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)

## Changes

- 2026-06-20 B003 Rule 26 incorporation:
  - Before: `85/90`, no enum C++, and the last two values used `IDENTITY` wording.
  - After: `88/91`, added draft `ThreadManMessageId` enum code and renamed the last two values to `THREADMAN_MARK_THREAD_ID_BLOCKED` and `THREADMAN_CLEAR_THREAD_ID_BLOCKED` because the wrappers pass `GetCurrentThreadId()` and the record search key is `watchedThreadId`.
- 2026-06-11 A004 Batch 173:
  - Before: `COMPLETION:74`, `CONFIDENCE:88`, no autogen parent.
  - After: `COMPLETION:85`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:0000EW`.
  - Summary/evidence: live IDA MCP reconfirmed the raw wrapper starts as non-functions, reconfirmed the worker-loop function and worker-entry caller, and the page now ties the `0x0464-0x0468` message ids to the assigned `ThreadManWatchRecord` layout and the direct class parent [UID:0000EW][ThreadMan](by-class/ThreadMan.md). Decimal forms and size constants were verified with `int_convert.py`; final C++ remains blank because original symbolic names and header/source spelling are not at the 95/95 gate.
