*** UID:0000U2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildAboveFrameBorder 0x00461310

## Status

- Confidence: strong for boundary, behavior, and frame-chrome owner; medium for final source-facing helper name.
- Entity kind: free UI chrome helper/factory.
- Current Wave3 state: prewave function `0x00461310`, not emitted as a recovered source file.
- Likely source module: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Exact range: `0x00461310-0x004615aa`

## Behavior

This helper allocates and constructs multiple `AboveFrame` objects and stores them in global frame slots. In one asset-mode branch it creates four frame pieces. In the other branch it creates additional top/bottom side pieces in a loop, for a complete frame border. Constructor arguments are frame index and screen origin coordinates.

## Evidence

- IDA MCP decompilation shows repeated `operator_new(308)` calls followed by `AboveFrame::AboveFrame`.
- IDA MCP reports nine constructor calls from this function into `AboveFrame::AboveFrame`.
- IDA MCP reports two direct callers from the map/game-server startup neighborhood at `0x004f7d10`.
- 2026-05-25 IDA xrefs show writes to the [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), including single pointer slots at `0x0067a834`, `0x0067a838`, `0x0067a83c`, `0x0067a840`, `0x0067a848`, and two five-entry pointer arrays starting at `0x0067a84c` and `0x0067a860`.
- 2026-05-26 IDA recheck confirms the function boundary `0x00461310-0x004615aa`, two call sites from `0x004f7d10`, and slot writes at `0x0046137d`, `0x004613b5`, `0x004613f0`, `0x00461428`, `0x00461448`, `0x0046148b`, `0x004614c3`, `0x004614fe`, `0x0046154a`, and `0x00461579`. The tenth `AboveFrame::AboveFrame` xref is from the dynamic recreate helper at `0x004615d0`, not this factory.

## Open Questions

- Name the global frame-slot variables once their ownership is repaired.
- Determine whether this factory is old/new frame mode specific or a general border builder.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented boundary, behavior, frame-slot writes, callers, and open naming questions but remained unevaluated.
  - After: score reflects documented factory behavior and frame-chrome ownership, with remaining completion limited by final helper/slot names.
  - Evidence: IDA notes confirm repeated `AboveFrame` construction, two startup callers, exact `0x00461310-0x004615aa` boundary, and writes to [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md).
