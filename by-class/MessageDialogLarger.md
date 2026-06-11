*** UID:000086 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MessageDialogLarger

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears at `89/85`, but this child remains `82/85`, below the child completion gate.
- Final C++ gate: keep blank until the larger-layout packet fields, control construction arguments, and command identifiers are audited at method level.

## Class Purpose

`MessageDialogLarger` is the larger-layout variant of the packet-driven message dialog. It parses a message header and portrait/body data, builds backdrop/buttons/portrait/body controls, configures default actions, and closes after a command is handled.

It is the larger-layout sibling of [UID:000085][MessageDialog](by-class/MessageDialog.md) in the NPC message/menu-question dialog family. The packet dispatcher selects this constructor through the same dialog packet mode byte used for `MessageDialog`, `MenuQuestionDialog`, and `MenuQuestionDialogLarger`; the larger branch uses distinct `DLGMSG*` read-only resources and a `0x278`-byte allocation wrapper.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054db90-0x0054e8c7` | `MessageDialogLarger::MessageDialogLarger(unsigned char* packetData, char compactMode)` | Larger message packet parser and UI builder. |
| `0x0054e8d0-0x0054e91b` | `OnCommand(int commandId)` | Handles primary, secondary, or tertiary action and closes the dialog. |

## Evidence Notes

- IDA MCP confirms both functions as exact starts.
- Constructor xrefs come from the same packet dispatch area as `MessageDialog`, supporting same-source ownership.
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) records the dispatcher rule: `packet[1]` bit `0x10` selects the larger dialog family, while the low nibble selects message versus menu-question variants. Constructors receive `packet + 2` plus a final layout/text-mode flag.
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) records exact constructor callers at `0x0054c27c` and `0x0054c2bb` and keeps the `0x0054db90-0x0054e91b` range grouped with the other message/menu-question constructors and action handlers.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) documents the small wrappers at `0x0054c5d0-0x0054c62b` and `0x0054c690-0x0054c6eb`: both allocate `0x278` bytes and call `0x0054db90`, passing final flags `1` and `0` respectively.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records `MessageDialogLarger` vtables at `0x00622560-0x006225f0`, `DLGMSG1.PAL` references from `0x0054db90`, and `DLGMSG1B.EPF` references from `0x0054db90`.
- Virtual/action helpers for this family are vtable-referenced in the `0x00622500-0x00622878` band, with shared object-response behavior documented separately at [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md).

## Score And Gate Rationale

The page is now `82/85`: it documents the exact method ranges, dispatcher selection, allocation wrappers, direct constructor caller evidence, vtable/read-only resource evidence, sibling relationship, and final-C++ blockers. Completion remains below `85` because the larger constructor still needs a focused method-level pass for packet offsets, portrait/body control construction arguments, and command id names.

Do not set `AUTOGEN_PARENT_UID` yet. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `89/85`, but this child remains below the completion side of the strict `85/85` child/direct-parent gate.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:000085][MessageDialog](by-class/MessageDialog.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger message-dialog variant has role, constructor/action boundaries, packet-layout role, and same-source ownership documented, but it lacks the deeper packet offset detail already present on the normal `MessageDialog` page. Evidence: linked NPC message/menu-question range, IDA-confirmed starts, and constructor xrefs from the shared packet dispatch area.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `76/84`, below the strict `85/85` child gate, even though [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0054db90` and `0x0054e8d0`; current `callers` confirms constructor references from the shared packet-dialog dispatch around `0x0054c200`.
- 2026-06-10 A002 provenance/gate cleanup:
  - Before: status/evidence still referenced generated recovered output and the change log cited the old parent-attachment threshold.
  - After: status records the strict `85/85` gate and evidence now centers on IDA-confirmed starts, packet-dispatch constructor xrefs, and the linked message/menu-question aggregate.
  - Summary/evidence: the direct parent is `89/85`, but this child remains `76/84`, so the source-owner link stays informational rather than an autogen assignment.
- 2026-06-11 A002 evidence refresh:
  - Before: `76/84`, with only role, method boundary, and broad dispatcher evidence.
  - After: `82/85`, `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: incorporated the existing IDA-backed dispatcher rule from [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), exact caller/wrapper evidence from [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), aggregate range evidence from [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), and vtable/resource evidence from [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md). Parent remains blank because this child is still below the `85` completion gate.
