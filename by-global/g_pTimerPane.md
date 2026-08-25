*** UID:0000SJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TimerPane *g_pTimerPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTimerPane

## Status

- Confidence: strong for address, lifecycle, and exact storage slot.
- Address: `0x0069b4d8`
- Current IDA name: `dword_69B4D8`
- Source owner/emitter: [UID:0000OU][TimerPane](by-file/TimerPane.md), exact definition `TimerPane *g_pTimerPane = 0;`.
- Exact storage evidence: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) now records the current 40-byte singleton run as zero-initialized. Historical `ff ff ff ff` observations are superseded evidence, not a current initializer.
- Implemented score: `89/93`; owner/emitter UID0000OU, reconstructable true, blank position are preserved.

## Symbol Role

`g_pTimerPane` tracks the active in-game timer/countdown overlay. The source constructor publishes it early and the ordinary destructor clears it. Constructor-unwind cleanup and the scalar deleting wrapper repeat those effects only as compiler-generated lifecycle paths; MapPane reads the singleton to create, update, delete, or tear down the overlay.

Treat the adjacent `.data` cluster as physical storage adjacency, not as proof of a source-level aggregate. The declaration belongs with the `TimerPane` map UI module; neighboring slots belong to other message/status/menu pane owners.

## IDA MCP Evidence

Checked on 2026-05-24 and refreshed with live IDA MCP on 2026-06-04:

- `xrefs_to 0x0069b4d8` reports reads from `MapPane` packet/cleanup code at `0x00504ac2` and `0x0050884c`.
- The related timer packet helper at `0x005140a0` reads the global at `0x005140e1`.
- `TimerPane::TimerPane` publishes the global at `0x00598731`; the nearby clear-looking path at `0x00598738` belongs to compiler adjustment/EH scaffolding, not a source null/sentinel branch.
- `TimerPane` cleanup body clears it at `0x0059886a`.
- Compiler constructor-unwind child [UID:0004MO][0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton](by-memory/0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton.md) clears it at `0x00598c30`; there is no handwritten `ClearTimerPaneSingleton` API.
- Compiler scalar deleting wrapper [UID:0004MR][0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor](by-memory/0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor.md) repeats the ordinary destructor clear at `0x00598c80`.
- IDA MCP `xrefs_to 0x0069b4d8` on 2026-06-04 confirms the same 8 data xrefs matching the reads and lifecycle writes above.
- IDA MCP lookup confirms TimerPane constructor `0x005986e0` size `0x162`, cleanup `0x00598850` size `0x29`, clear helper `0x00598c30` size `0xb`, scalar deleting destructor `0x00598c60` size `0x5f`, and packet helper `0x005140a0` size `0x112`.
- IDA decompilation/disassembly of `0x005986e0` reduces to ordinary source `g_pTimerPane = this`: the apparent null/sentinel expression comes from computing the inherited-tail pointer and subtracting `0xf8`, not a source test on `this == -248`.
- IDA decompilation of `0x00598850`, `0x00598c30`, and `0x00598c60` confirms all three teardown paths clear `dword_69B4D8`.
- IDA decompilation of `0x005140a0` reads `dword_69B4D8`, allocates a 288-byte TimerPane only when the singleton is absent and the packet mode requires a pane, constructs it through `0x005986e0`, then configures or destroys it based on packet mode `0` through `3`.
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) records the full executable range map, including constructor, cleanup, `SetTimer`, timer callback, draw path, digit loader, singleton clear helper, adjustor thunks, and scalar deleting destructor.
- [UID:00028A][0x00670294-0x006702c4.TimerPaneNumberResourceStrings](by-memory/0x00670294-0x006702c4.TimerPaneNumberResourceStrings.md) confirms the `NUMBER.EPF`/`NUMBER.EPD` strings used by `TimerPane::DrawDigit`, and [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md) records the 288-byte layout and time/display fields touched by the packet/configure/draw paths.

## Ownership Notes

- Keep this global in `NexusTK/map/TimerPane.cpp`; MapPane is a consumer and packet owner, not the singleton's source owner.
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
- [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md)
- [UID:0004MH][0x00598850-0x00598878.TimerPaneDestructor](by-memory/0x00598850-0x00598878.TimerPaneDestructor.md)
- [UID:0004MO][0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton](by-memory/0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton.md)
- [UID:0004MR][0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor](by-memory/0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-13 B003 UID0001KB callback:
  - Raised `86/89 -> 89/93`, preserved source owner/emitter UID0000OU, and inserted exact definition `TimerPane *g_pTimerPane = 0;`.
  - Preserved all eight xrefs while separating source constructor/destructor effects from compiler unwind/deleting-wrapper repetitions.
  - Rejected stale `0xffffffff` initializer and source sentinel-branch wording using current UID00029Y zero-initialized cluster evidence; retained the old observation as history and kept the physical-adjacency caveat.

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
