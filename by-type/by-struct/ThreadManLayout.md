*** UID:0001WA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ThreadManLayout

## Status

- Kind: class object layout
- Owner class: [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- Likely declaring header: `util/Thread.h`
- Confidence: strong for observed fields through `0x14`, medium for final names.

## Layout

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `vtable` / `LObject` base head | Constructor calls the common `LObject` constructor and installs `ThreadMan::vftable`; destructor reinstalls the same vtable before teardown. |
| `0x04` | `isDebuggerPresent` | Constructor clears this byte, optionally calls `IsDebuggerPresent`, and stores the result. Worker loop skips the fatal watchdog pass when this byte is nonzero. |
| `0x08` | `workerThreadHandle` | Constructor stores the `CreateThread` handle here; scalar deleting destructor calls `TerminateThread` and `CloseHandle` on it. |
| `0x0c` | `workerThreadId` | Passed as the `CreateThread` thread-id output parameter. |
| `0x10` | `watchList` | Constructor allocates `List(20, 16)` and stores the pointer here; worker loop scans and mutates 20-byte watchdog records. |

## Notes

IDA exposes RTTI for both `ThreadMan` and `Singleton<ThreadMan>`. No additional singleton base storage has been observed in this object; the singleton pointer is the external [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) at `0x0069be08`.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x00596bf0` confirms the constructor writes [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) at `0x0069be08`, installs `ThreadMan::vftable` at `+0x00`, clears debugger byte `+0x04`, stores `IsDebuggerPresent()` there when available, constructs `List(20, 16)`, stores it at `+0x10`, starts the worker thread with `CreateThread`, stores the handle at `+0x08`, and passes `+0x0c` as the thread-id out parameter.
- 2026-05-31 IDA MCP decompilation of `0x00596e10` confirms the worker loop reads debugger byte `+0x04` to skip the fatal watchdog scan and iterates the list at `+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x005974f0` confirms the scalar deleting destructor reinstalls `ThreadMan::vftable`, terminates/closes the handle at `+0x08`, releases the list at `+0x10`, clears [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md), and calls the common `LObject` destructor.

## Cross-References

- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, worker-loop, and destructor field use. The score remains below final-source level because the raw message-wrapper island and exact original type names still need a broader source audit.
