*** UID:000080 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionItemListLarger

## Status

- Confidence: strong for support-widget ownership.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears at `89/85`, but this child remains `82/85`, below the child completion gate.
- Final C++ gate: keep blank until the list row record type, paired-list field, and `ListPane` draw/selection method names are audited at method level.

## Class Purpose

`MenuQuestionItemListLarger` is the larger-layout list widget used by `MenuQuestionDialogLarger`. It wraps a `ListPane`, delegates current-item selection to its paired question list, and draws selected entries with the same highlight/background palette pattern as the normal list.

It is the larger-layout sibling of [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), and both are private support widgets for the menu-question constructors in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). This class should not be promoted to generic list infrastructure unless later xrefs show reuse outside the NPC message/menu-question dialog family.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00550ed0-0x00550f1f` | `MenuQuestionItemListLarger::MenuQuestionItemListLarger(int32_t questionItemList)` | Constructs the list pane and stores the paired list pointer. |
| `0x00550f90-0x00550f9b` | `SelectCurrentItem()` | Delegates selection confirmation to the inner question item list. |
| `0x00550fa0-0x00551021` | `DrawEntry(...)` | Draws a row label from the wide string at item-data offset `+2`. |

## Evidence Notes

- IDA MCP confirms all three functions as exact starts.
- Constructor xrefs are from the larger menu-question constructor at `0x0054fd14` and `0x00550489` inside the `0x0054fb30` constructor range.
- The class remains a private support widget for [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md); no broader reuse is documented.
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) records this class as the tail of the message/menu-question executable aggregate: constructor `0x00550ed0-0x00550f1f`, selection delegation helper `0x00550f90-0x00550f9b`, and row renderer `0x00550fa0-0x00551021`.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the normal/larger menu-question item-list vtable band at `0x00622734-0x006228b0`, with ownership routed through `MessageDialogs`.
- The row renderer reads a wide-string label from item-data offset `+2`, matching the normal item-list sibling. The exact row record declaration remains open.

## Score And Gate Rationale

The page is now `82/85`: it documents the exact constructor/delegation/draw ranges, constructor xrefs, paired-list relationship, row-label offset, sibling parity, vtable/read-only-data evidence, and final-C++ blockers. Completion remains below `85` because the row record type, paired-list field name, and final `ListPane` override names still need a focused method-level audit.

Do not set `AUTOGEN_PARENT_UID` yet. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `89/85`, but this child remains below the completion side of the strict `85/85` child/direct-parent gate.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- 2026-06-05: Marked reconstructable because live IDA MCP confirms this larger menu-question list widget is source-owned UI support for [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md). Kept `AUTOGEN_PARENT_UID` blank because the class is `76/84`, below the strict `85/85` child gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00550ed0`, `0x00550f90`, and `0x00550fa0`; `callers` confirms constructor calls from `0x0054fd14` and `0x00550489` inside `MenuQuestionDialogLarger`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger question-list widget has clear ownership, constructor, delegated selection, row drawing, and constructor-caller evidence, but row data layout and final source-level details are not exhaustive. Evidence: linked message-dialog memory range, IDA-confirmed method starts, constructor xref from `MenuQuestionDialogLarger`, and paired-list relationship.
- 2026-06-10 A002 provenance/gate cleanup:
  - Before: status/evidence still referenced generated recovered output and the change log cited the old parent-attachment threshold.
  - After: status records the strict `85/85` gate and evidence now centers on IDA-confirmed starts, constructor xrefs, and the private support-widget relationship to `MenuQuestionDialogLarger`.
  - Summary/evidence: the direct parent is `89/85`, but this child remains `76/84`, so the source-owner link stays informational rather than an autogen assignment.
- 2026-06-11 A002 evidence refresh:
  - Before: `76/84`, with sparse method and ownership notes.
  - After: `82/85`, `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: incorporated exact aggregate range evidence from [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), constructor xrefs at `0x0054fd14` and `0x00550489`, sibling/paired-list relationship to [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), and the menu-question item-list vtable band from [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md). Parent remains blank because this child is still below the `85` completion gate.
