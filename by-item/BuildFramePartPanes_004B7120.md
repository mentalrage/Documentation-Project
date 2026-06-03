*** UID:0000U5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildFramePartPanes 0x004B7120

## Status

- Confidence: strong for boundary, behavior, and frame-chrome owner; weak for live reachability and final source-facing helper name.
- Entity kind: free UI chrome helper/factory.
- Current Wave3 state: prewave function `0x004b7120`, not emitted as a recovered source file.
- Likely source module: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Canonical memory page: [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md)
- Exact range: `0x004b7120-0x004b731f` end-exclusive in IDA.

This page is retained as a small by-item index for older references. The canonical code-bearing documentation is now [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md), so this page is not a separate reconstruction target.

## Behavior

This helper builds five `FramePartPane` objects at fixed rectangles. It initializes a rectangle, offsets it to a fixed screen position, allocates a `FramePartPane`, passes a part index, and stores the resulting pointer in one of five global frame-part slots.

## Evidence

- IDA MCP decompilation shows five `operator_new(252)` calls followed by `FramePartPane::FramePartPane`.
- IDA MCP reports all five constructor call refs come from this helper.
- The hard-coded rectangles and `FRMPART` resource use match a UI frame-border/chrome factory.
- 2026-05-25 IDA MCP `callers 0x004b7120` currently reports no direct callers, so this helper remains retained or indirectly reached until a live caller is recovered.
- `xrefs_to 0x0069b33c-0x0069b34c` confirms this helper writes the five [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md).
- 2026-05-26 recheck corrects the exact end: IDA models `sub_4B7120` as `0x004b7120-0x004b731f` end-exclusive, not the shorter `0x004b7311` boundary used in older notes. `callers` remains empty, and the following raw cleanup body at `0x004b7320` remains outside IDA's function model.
- 2026-05-26 exact slot-write recheck confirms writes to `dword_69B33C`, `dword_69B340`, `dword_69B344`, `dword_69B348`, and `dword_69B34C`; an allocation-failure path also clears `dword_69B34C`.
- 2026-06-03 IDA MCP reconfirmed `sub_4B7120` as size `0x1ff`, `0x004b731f`/`0x004b7320` as non-function starts, no xrefs/callers to the helper entry, and five `FramePartPane` constructor calls from `0x004b718c`, `0x004b71e2`, `0x004b723b`, `0x004b7294`, and `0x004b72f0`.
- 2026-06-03 IDA MCP `xrefs_to` for `0x0069b33c-0x0069b34c` reconfirmed factory writes, raw cleanup reads/clears at `0x004b7320` through `0x004b7398`, and `FramePartPane::OnNotification` clears at `0x004b73cb` through `0x004b73f3`.
- 2026-06-03 IDA MCP disassembly shows associated compiler EH cleanup funclets in the ignored MSVC SEH/EH island near `0x005ff150`; the source semantics remain the five allocation/constructor blocks in the canonical memory page.

## Open Questions

- Recover the direct or indirect caller for this factory, or prove it is retained old/new-interface setup code.
- Decide final names for the five frame-part slot globals.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md)
- [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `68/78`.
  - Before: page documented boundary, behavior, slot writes, owner, and no-caller caveat but remained unevaluated.
  - After: score reflects documented frame-part factory behavior and slot ownership, with lower completion/confidence because direct/indirect live reachability and final helper/slot names remain open.
  - Evidence: IDA notes confirm five `FramePartPane` constructor calls, exact `0x004b7120-0x004b731f` range, five slot writes, and no direct callers in the current database.
- 2026-06-03: Promoted canonical code-bearing documentation to by-memory.
  - Before: this by-item page was scored `68/78`, had blank reconstructable metadata, and still appeared as a separate low-score reconstruction target.
  - After: this retained index is scored `-1/-1` and marked `RECONSTRUCTABLE:FALSE`; [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) remains the canonical reconstructable page.
  - Evidence: `by-memory` is the canonical home for exact function/range documentation, and fresh IDA MCP checks reconfirmed the exact modeled function, constructor calls, slot lifecycle xrefs, no direct entry callers, and associated compiler EH funclets.
