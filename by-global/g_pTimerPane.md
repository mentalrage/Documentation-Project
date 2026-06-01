*** UID:0000SJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTimerPane

## Status

- Confidence: strong for address and role.
- Address: `0x0069b4d8`
- Current IDA name: `dword_69B4D8`
- Proposed owner file: [UID:0000OU][TimerPane](by-file/TimerPane.md)

## Symbol Role

`g_pTimerPane` tracks the active in-game timer/countdown overlay. The `TimerPane` constructor stores the singleton, cleanup/destructor helpers clear it, and map/session cleanup code destroys it when the map UI is torn down or the server tells the client to close the timer.

## IDA MCP Evidence

Checked on 2026-05-24:

- `xrefs_to 0x0069b4d8` reports reads from `MapPane` packet/cleanup code at `0x00504ac2` and `0x0050884c`.
- The related timer packet helper at `0x005140a0` reads the global at `0x005140e1`.
- `TimerPane::TimerPane` stores or clears the global at `0x00598731` and `0x00598738`.
- `TimerPane` cleanup body clears it at `0x0059886a`.
- `TimerPane::ClearTimerPaneSingleton` clears it at `0x00598c30`.
- `TimerPane::ScalarDeletingDestructor` clears it at `0x00598c80`.
- IDA MCP `py_eval` rechecked `0x0069b4d8` on 2026-05-31 and confirmed IDA name `dword_69B4D8`, initial dword `0xffffffff`, and 8 data xrefs matching the reads and lifecycle writes above.

## Ownership Notes

- Keep this global with `map/TimerPane.cpp` or the TimerPane-private part of `map/MapPane.cpp`.
- Do not merge it into [UID:0000OT][TimerMgr](by-file/TimerMgr.md). The scheduler uses `g_pTimerMgr`; `g_pTimerPane` is UI overlay state.
- Generated files currently alias this address as both `dword_69B4D8` and `g_pTimerPane`; use `g_pTimerPane` for documentation.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:72`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OU` for [UID:0000OU][TimerPane](by-file/TimerPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4d8` as a 4-byte singleton pointer with 8 data xrefs spanning map/session reads, TimerPane construction, cleanup, clear helper, and scalar deleting destructor.
