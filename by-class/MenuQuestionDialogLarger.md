*** UID:00007Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionDialogLarger

## Status

- Confidence: strong for ownership, exact method boundaries, dispatcher paths, larger-list relationship, and missing-constructor tracking; constructor packet-field/control naming still needs method-level cleanup.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears at `89/85`, but this child remains `82/85`, below the child completion gate.
- Final C++ gate: keep blank until the omitted constructor body is represented with source-quality packet fields, control/layout member names, list-owner names, and final `ListPane` API names.

## Class Purpose

`MenuQuestionDialogLarger` is the larger-layout variant of the menu-question dialog. It shares the same packet response model as `MenuQuestionDialog`, using action 1 for selection submission and actions 2-4 for previous/next/current navigation.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054fb30-0x00550afb` | `MenuQuestionDialogLarger::MenuQuestionDialogLarger(...)` | Larger menu-question packet parser and control builder; current emitted source omits this body even though IDA/docs confirm the constructor. |
| `0x00550b00-0x00550c30` | `OnButtonAction(int action)` | Serializes opcode `0x3a` selection replies or sends previous/next/current packets, then closes the dialog. |
| `0x00550c40-0x00550c7d` | `UpdateButtonState()` | Enables/disables confirm button based on the list pane's enabled-entry count. |

## Evidence Notes

- Existing IDA MCP notes in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) confirm exact starts at `0x0054fb30`, `0x00550b00`, and `0x00550c40`, including the missing constructor body at `0x0054fb30`.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the dispatcher rule: `packet[1]` bit `0x10` selects larger-layout families and the low nibble selects the message/menu-question/text/head/proxy constructor path.
- The same dispatcher/wrapper page records two larger menu-question allocation wrappers: `0x0054c750-0x0054c7ab` calls `0x0054fb30` with final flag `1`, and `0x0054c810-0x0054c86b` calls `0x0054fb30` with final flag `0`. Direct constructor paths recorded in [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) include `0x0054c2fa` and `0x0054c339`.
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md) records constructor xrefs from this larger dialog at `0x0054fd14` and `0x00550489`, tying the larger list widget to this constructor.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the menu-question dialog vtable band at `0x006225fc-0x00622728`, the normal/larger item-list vtable band at `0x00622734-0x006228b0`, and the `dlgmsg*` resource-string island used by the dialog layout/setup paths.
- The missing emitted constructor is tracked in [wave3_data_issues](../wave3_data_issues.md) and the shared [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) note.
- 2026-05-25 IDA recheck: constructor callers are `0x0054c2fa`/`0x0054c339` in `HandleDialogPacket_54C200` plus wrapper paths at `0x0054c795` and `0x0054c855`.
- IDA decompilation shows the omitted constructor still follows the same packet header pattern as the smaller message/question dialogs: type at `packet[0]`, object id at `packet+1`, object descriptor at `packet+6`, two state words after the descriptor, item text copied through `MultiByteToWideChar`, allocation of `MenuQuestionItemListLarger`, and larger-layout backgrounds such as `DLGMSG4.EPD`, `DLGMSG3B.EPD`, and `DLGMSG31.EPD`.

## Score And Gate Rationale

The page is now `82/85`: it documents exact method starts, dispatcher and allocation-wrapper paths, constructor caller evidence, larger list-widget construction, missing-body tracking, vtable/read-only-data support, decompiled packet/header/layout behavior, and final-C++ blockers. Completion remains below `85` because the constructor still needs a focused source-level pass for packet-field names, list/control member names, row item types, and layout asset/dimension decisions.

Do not set `AUTOGEN_PARENT_UID` yet. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `89/85`, but this child remains below the completion side of the strict `85/85` child/direct-parent gate.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)

## Changes

- 2026-06-05: Marked reconstructable because live IDA MCP confirms this larger menu-question dialog has real constructor/action/update functions in the message-dialog family. Kept `AUTOGEN_PARENT_UID` blank because the class is `76/84`, below the strict `85/85` child gate, even though [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x0054fb30`, `0x00550b00`, and `0x00550c40`; `callers` confirms constructor paths from `0x0054c2fa`, `0x0054c339`, `0x0054c795`, and `0x0054c855`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger menu-question variant has strong boundary and packet/layout evidence, but completion is limited by the constructor body still needing source-level cleanup. Evidence: IDA-confirmed constructor/action/update starts, constructor caller xrefs, decompiled packet/header/layout pattern, larger asset names, and linked missing-body tracking.
- 2026-06-10 A002 provenance/gate cleanup:
  - Before: status/evidence still referenced generated recovered output and the change log cited the old parent-attachment threshold.
  - After: status records the strict `85/85` gate and evidence now centers on IDA-confirmed starts, dispatcher xrefs, decompiled constructor behavior, and existing by-* missing-body tracking.
  - Summary/evidence: the direct parent is `89/85`, but this child remains `76/84`, so the source-owner link stays informational rather than an autogen assignment.
- 2026-06-11 A002 evidence refresh:
  - Before: `76/84`, with constructor omission noted but only sparse dispatcher/list-widget evidence.
  - After: `82/85`, `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: incorporated exact aggregate range evidence from [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), dispatcher/wrapper paths from [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), larger-list constructor xrefs from [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md), and menu-question vtable/resource evidence from [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md). Parent remains blank because this child is still below the `85` completion gate.
