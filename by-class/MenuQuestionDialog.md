*** UID:00007X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionDialog

## Status

- Confidence: strong for ownership, exact method boundaries, dispatcher paths, and list-widget relationship; constructor packet-field and layout-control names still need method-level cleanup.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears at `89/85`, but this child remains `82/85`, below the child completion gate.
- Final C++ gate: keep blank until packet fields, control/layout member names, item-record handling, and `ListPane` interaction names are audited at method level.

## Class Purpose

`MenuQuestionDialog` is the normal-layout menu-question dialog. It parses a packet containing a menu category, context object, page/index state, optional description text, and a list of selectable item labels. It builds a scrollable `MenuQuestionItemList` and sends a selection packet when the user confirms.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054e920-0x0054f8dd` | `MenuQuestionDialog::MenuQuestionDialog(uint8_t* packet, char hasDescriptionText)` | Packet parser, item-list builder, background/object/text/button layout builder. |
| `0x0054f8e0-0x0054fa10` | `OnButtonAction(int action, int unused)` | Sends selected item reply or previous/next/current dialog packets. |
| `0x0054fa20-0x0054fa5d` | `ValidateMenuSelection()` | Enables/disables the confirm button based on enabled list-entry count. |

## Evidence Notes

- Existing IDA MCP notes in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) confirm exact starts at `0x0054e920`, `0x0054f8e0`, and `0x0054fa20`.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the dispatcher rule: `packet[1]` bit `0x10` selects larger-layout families and the low nibble selects the message/menu-question/text/head/proxy constructor path.
- The same dispatcher/wrapper page records two normal menu-question allocation wrappers: `0x0054c6f0-0x0054c74b` calls `0x0054e920` with final flag `1`, and `0x0054c7b0-0x0054c80b` calls `0x0054e920` with final flag `0`. The direct dispatcher caller evidence in [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) lists constructor paths at `0x0054c406` and `0x0054c445`.
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md) records constructor xrefs from this dialog at `0x0054eb04` and `0x0054f276`, tying the normal list widget to the normal dialog constructor rather than generic menu infrastructure.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the menu-question dialog vtable band at `0x006225fc-0x00622728`, the normal/larger item-list vtable band at `0x00622734-0x006228b0`, and a resource-string xref into normal menu-question layout/setup at `0x0054ec66`.
- The branch using the high-resolution layout flag is documented but not source-ready: low/high layout label names remain provisional until the constructor's asset dimensions and control placement are reviewed in detail.
- Existing by-memory and file-family docs tie this dialog to the shared message/menu-question packet dispatcher under [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), not to generic menu infrastructure.

## Score And Gate Rationale

The page is now `82/85`: it documents exact method starts, dispatcher and allocation-wrapper paths, constructor caller evidence, normal list-widget ownership, vtable/read-only-data support, and final-C++ blockers. Completion remains below `85` because the constructor still needs a focused method-level audit for packet-field names, control member names, layout asset/dimension decisions, and final `ListPane` API naming.

Do not set `AUTOGEN_PARENT_UID` yet. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `89/85`, but this child remains below the completion side of the strict `85/85` child/direct-parent gate.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)

## Changes

- 2026-06-05: Marked reconstructable because live IDA MCP confirms this normal-layout menu-question dialog is NexusTK-owned packet/UI behavior. Kept `AUTOGEN_PARENT_UID` blank because the class is `76/82`, below the strict `85/85` child gate, even though [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x0054e920`, `0x0054f8e0`, and `0x0054fa20`; `callers` confirms constructor paths from `0x0054c406`, `0x0054c445`, `0x0054c735`, and `0x0054c7f5`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/82`. Summary: the normal menu-question dialog has source ownership, packet role, method boundaries, list widget relationship, and layout caveats documented, but constructor internals and high/low layout labels still need cleanup review. Evidence: linked `NpcMessageAndMenuQuestionDialogs` range, IDA-confirmed starts, dispatcher constructor xrefs, and the documented layout-branch caveat.
- 2026-06-10 A002 provenance/gate cleanup:
  - Before: status/evidence still referenced generated recovered output and the change log cited the old parent-attachment threshold.
  - After: status records the strict `85/85` gate, generated-output provenance was removed, and evidence now points to IDA-confirmed starts, dispatcher xrefs, and existing by-* ownership docs.
  - Summary/evidence: the direct parent is `89/85`, but this child remains `76/82`, so the source-owner link stays informational rather than an autogen assignment.
- 2026-06-11 A002 evidence refresh:
  - Before: `76/82`, with only shallow dispatcher and list-widget evidence.
  - After: `82/85`, `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: incorporated exact aggregate range evidence from [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), dispatcher/wrapper paths from [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), constructor/list-widget xrefs from [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), and menu-question vtable/resource evidence from [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md). Parent remains blank because this child is still below the `85` completion gate.
