*** UID:0000SJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTimerPane

## Status

- Confidence: strong for address, lifecycle, and exact storage slot.
- Address: `0x0069b4d8`
- Current IDA name: `dword_69B4D8`
- Proposed owner file: [UID:0000OU][TimerPane](by-file/TimerPane.md)
- Exact storage evidence: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) records `0x0069b4d8` / `dword_69B4D8` as the `TimerPane` singleton slot inside a dense UI singleton run initialized to `0xffffffff`.

## Symbol Role

`g_pTimerPane` tracks the active in-game timer/countdown overlay. The `TimerPane` constructor stores the singleton, cleanup/destructor helpers clear it, and map/session cleanup code destroys it when the map UI is torn down or the server tells the client to close the timer.

Treat the adjacent `.data` cluster as physical storage adjacency, not as proof of a source-level aggregate. The declaration belongs with the `TimerPane` map UI module; neighboring slots belong to other message/status/menu pane owners.

## IDA MCP Evidence

Checked on 2026-05-24 and refreshed with live IDA MCP on 2026-06-04:

- `xrefs_to 0x0069b4d8` reports reads from `MapPane` packet/cleanup code at `0x00504ac2` and `0x0050884c`.
- The related timer packet helper at `0x005140a0` reads the global at `0x005140e1`.
- `TimerPane::TimerPane` stores or clears the global at `0x00598731` and `0x00598738`.
- `TimerPane` cleanup body clears it at `0x0059886a`.
- `TimerPane::ClearTimerPaneSingleton` clears it at `0x00598c30`.
- `TimerPane::ScalarDeletingDestructor` clears it at `0x00598c80`.
- IDA MCP `xrefs_to 0x0069b4d8` on 2026-06-04 confirms the same 8 data xrefs matching the reads and lifecycle writes above.
- IDA MCP lookup confirms TimerPane constructor `0x005986e0` size `0x162`, cleanup `0x00598850` size `0x29`, clear helper `0x00598c30` size `0xb`, scalar deleting destructor `0x00598c60` size `0x5f`, and packet helper `0x005140a0` size `0x112`.
- IDA decompilation of `0x005986e0` writes `dword_69B4D8 = this` at `0x00598731` and clears it at `0x00598738` on the null/sentinel path before installing TimerPane vtables and scheduling the repaint timer.
- IDA decompilation of `0x00598850`, `0x00598c30`, and `0x00598c60` confirms all three teardown paths clear `dword_69B4D8`.
- IDA decompilation of `0x005140a0` reads `dword_69B4D8`, allocates a 288-byte TimerPane only when the singleton is absent and the packet mode requires a pane, constructs it through `0x005986e0`, then configures or destroys it based on packet mode `0` through `3`.
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) records the full executable range map, including constructor, cleanup, `SetTimer`, timer callback, draw path, digit loader, singleton clear helper, adjustor thunks, and scalar deleting destructor.
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md) confirms the `NUMBER.EPF`/`NUMBER.EPD` strings used by `TimerPane::DrawDigit`, and [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md) records the 288-byte layout and time/display fields touched by the packet/configure/draw paths.

## Ownership Notes

- Keep this global with `map/TimerPane.cpp` or the TimerPane-private part of `map/MapPane.cpp`.
- Do not merge it into [UID:0000OT][TimerMgr](by-file/TimerMgr.md). The scheduler uses `g_pTimerMgr`; `g_pTimerPane` is UI overlay state.
- IDA keeps the storage name `dword_69B4D8`; use `g_pTimerPane` for documentation and source-layout discussion.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md)
- [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:72`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OU` for [UID:0000OU][TimerPane](by-file/TimerPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4d8` as a 4-byte singleton pointer with 8 data xrefs spanning map/session reads, TimerPane construction, cleanup, clear helper, and scalar deleting destructor.
- 2026-06-04 live IDA refresh:
  - Before: the page had the lifecycle xrefs but did not record current constructor/packet-helper decompilation or teardown-body details.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed exactly eight data xrefs to `0x0069b4d8`, exact TimerPane constructor/cleanup/clear/destructor/helper sizes, singleton set/clear behavior in `0x005986e0`, clears in `0x00598850`, `0x00598c30`, and `0x00598c60`, and packet mode handling in `0x005140a0`. The score remains below final reconstruction level because exact source split between `TimerPane.cpp`, `MapPane.cpp`, and packet-dispatch glue is still provisional.
- 2026-06-06: Raised `COMPLETION` from `84` to `86` and `CONFIDENCE` from `88` to `89`.
  - Added exact storage-cluster evidence, current executable-range link, TimerPane number-resource strings, layout support, and a source-adjacency caveat for the surrounding UI singleton run.
  - Evidence: existing IDA-backed docs now account for the singleton slot in [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), the full TimerPane code range in [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md), the `NUMBER.EPF`/`NUMBER.EPD` draw resources in [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md), the 288-byte TimerPane layout in [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md), map packet ownership, all eight direct singleton xrefs, and the TimerPane parent file. Final C++ remains blank because packet-helper placement and final source split are still below the 95/95 bar.
