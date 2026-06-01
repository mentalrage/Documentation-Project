*** UID:0000U5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
