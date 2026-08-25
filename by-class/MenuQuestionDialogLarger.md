*** UID:00007Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MenuQuestionDialogLarger : public PursuitMessageDialogPane
{
public:
    MenuQuestionDialogLarger(const unsigned char *packet, bool hasDescriptionText);
    virtual bool OnButtonAction(int actionId);
    virtual void UpdateConfirmButtonState();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionDialogLarger

## Status

- Confidence: strong for ownership, exact method boundaries, dispatcher paths, larger-list relationship, vtable stores, packet-field offsets, resource branches, and missing-constructor tracking; final field/control names still need method-level cleanup.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main method children: [UID:0003W4][0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor](by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md), [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md), [UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md). The adjacent raw selection helper [UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md) is best understood as a dead retained private helper candidate `SendSelectionReply(unsigned char selectedValue)` but remains no-owner/non-emitting; [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) is now a non-emitting split index.
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). The child is now `85/87` and the direct file parent is `89/85`, so the strict `85/85` child/direct-parent gate clears.
- Declaration-level C++ is now emitted for the class shell; method-body emission remains gated on source-quality packet fields, control/layout member names, list-owner names, and final `ListPane` API names.

## Class Purpose

`MenuQuestionDialogLarger` is the larger-layout variant of the menu-question dialog. It shares the same packet response model as `MenuQuestionDialog`, using action 1 for selection submission and actions 2-4 for previous/next/current navigation.

B010 2026-07-01 resolves the empty emitter as declaration-level source with constructor/action/update virtuals and `[[CHILDREN]]`. [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) now emits factory calls to `MenuQuestionDialogLarger(payload, hasDescriptionText)`, while the larger no-route selection packet helper remains non-emitting support evidence.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0003W4][0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor](by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md) | `MenuQuestionDialogLarger::MenuQuestionDialogLarger(...)` | Larger menu-question packet parser and control builder; current emitted source omits this body even though IDA/docs confirm the constructor. |
| [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md) | `OnButtonAction(int action)` | Serializes opcode `0x3a` selection replies or sends previous/next/current packets, then closes the dialog. |
| [UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md) | `UpdateButtonState()` | Enables/disables confirm button based on the list pane's enabled-entry count. |

## Non-Emitting Raw Helper Evidence

[UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md) has class-specific source shape but no route. B012's 2026-06-19 PE scan found no rel32 call/jump, absolute VA pointer, or RVA pointer to `0x00550c80`; the same scan found positive-control vtable pointers for the live action handler [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md) at `0x006226e0 -> 0x00550b00` and the live update method [UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md) at `0x006226e4 -> 0x00550c40`, plus direct constructor calls to the next live list constructor [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md).

If a route is ever proven, the best descriptive source name is `MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue)`: the helper writes opcode `0x3a`, `this+0x26c`, `this+0x270`, `this+0x274`, `this+0x276 + 1`, marker byte `1`, and the caller-supplied selected row byte, then sends 12 bytes through `g_packetSender`. Current source placement must stay hypothetical because the body is bracketed by `0xcc` padding and has no caller/pointer/fallthrough route. The live [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md) action case `1` already performs selected-row lookup, serializes the same packet, calls `QueueAndSendPacket`, closes the dialog, and returns through the vtable-routed action method.

## Evidence Notes

- Existing IDA MCP notes in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) confirm exact starts at `0x0054fb30`, `0x00550b00`, and `0x00550c40`, including the missing constructor body at `0x0054fb30`.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the dispatcher rule: `packet[1]` bit `0x10` selects larger-layout families and the low nibble selects the message/menu-question/text/head/proxy constructor path.
- The same dispatcher/wrapper page records two larger menu-question allocation wrappers: `0x0054c750-0x0054c7ab` calls `0x0054fb30` with final flag `1`, and `0x0054c810-0x0054c86b` calls `0x0054fb30` with final flag `0`. Direct constructor paths recorded in [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) include `0x0054c2fa` and `0x0054c339`.
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md) records constructor xrefs from this larger dialog at `0x0054fd14` and `0x00550489`, tying the larger list widget to this constructor.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the menu-question dialog vtable band at `0x006225fc-0x00622728`, the normal/larger item-list vtable band at `0x00622734-0x006228b0`, and the `dlgmsg*` resource-string island used by the dialog layout/setup paths.
- The missing emitted constructor is tracked in [wave3_data_issues](../wave3_data_issues.md) and the shared [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) note.
- 2026-05-25 IDA recheck: constructor callers are `0x0054c2fa`/`0x0054c339` in `HandleDialogPacket_54C200` plus wrapper paths at `0x0054c795` and `0x0054c855`.
- IDA decompilation shows the omitted constructor still follows the same packet header pattern as the smaller message/question dialogs: type at `packet[0]`, object id at `packet+1`, object descriptor at `packet+6`, two state words after the descriptor, item text copied through `MultiByteToWideChar`, allocation of `MenuQuestionItemListLarger`, and larger-layout backgrounds such as `DLGMSG4.EPD`, `DLGMSG3B.EPD`, and `DLGMSG31.EPD`.
- 2026-06-11 A003 IDA MCP recheck: `0x0054fb30` is still modeled as `0x0054fb30-0x00550afb` with callers at `0x0054c2fa`, `0x0054c339`, `0x0054c795`, and `0x0054c855`; the constructor stores the `MenuQuestionDialogLarger` primary/secondary/tertiary vtable triple at `0x00622698`, `0x006226f8`, and `0x00622728`.
- The same pass records constructor field writes at object offsets `+0x26c`, `+0x270`, `+0x274`, and `+0x276` (decimal 620/624/628/630; Verified with int_convert.py), matching dialog type, object id, and two state words after the variable-length object descriptor.
- IDA data refs from the constructor prove both large-resource branches: `.EPF` resources `DLGMSG4.EPF`, `DLGMSG3B.EPF`, and `DLGMSG31.EPF`, and `.EPD` resources `DLGMSG4.EPD`, `DLGMSG3B.EPD`, and `DLGMSG31.EPD`, with `DLGMSG3.PAL` palette support on the `.EPF` branch.
- IDA call refs show two `MenuQuestionItemListLarger` constructions at `0x0054fd14` and `0x00550489`, plus three `MultiByteToWideChar` conversions in the constructor path. `OnButtonAction` at `0x00550b00-0x00550c30` is vtable-referenced at `0x006226e0`, dispatches actions 2/3/4 through the shared navigation helpers, and serializes selection action 1 as decimal 58 / `0x3a` (Verified with int_convert.py) before calling the packet send helper at `0x00574bb0`. `UpdateButtonState` at `0x00550c40-0x00550c7d` is vtable-referenced at `0x006226e4`, calls `0x004f3e20` (`ListPane::GetSelectionCount()` / `HasSelection()`) through the embedded list-pane state, and toggles the confirm button. B002 2026-06-20 confirms this updater does not call raw helper [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md); that helper returns selected row byte `+0` as an option id and remains no-owner/non-emitting.
- 2026-06-16 B001 split execution created exact method children [UID:0003W4][0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor](by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md), [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md), and [UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md). The adjacent raw helper [UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md) remains non-emitting because packet helper ownership/source naming is not safe.

## Score And Gate Rationale

The page is now `85/87`: it documents exact method starts, dispatcher and allocation-wrapper paths, constructor caller evidence, vtable stores, larger list-widget construction, missing-body tracking, read-only-data support, packet/header offsets, resource branches, action serialization, and final-C++ blockers. Completion clears the assignment gate but remains capped at `85` because the constructor still needs a focused source-level pass for packet-field names, list/control member names, row item types, and layout asset/dimension decisions.

`AUTOGEN_PARENT_UID` is set to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). The direct parent is `89/85`, and this class now clears `85/87`; this is a documentation ownership assignment only, not permission to emit final C++.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0003W4][0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor](by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md)
- [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md)
- [UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md)
- [UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)

## Changes

- 2026-07-01 Agent-B010 implementation callback: raised `85/87 -> 86/88`, set emitter position `70`, and added the accepted declaration shell for `MenuQuestionDialogLarger(const unsigned char *packet, bool hasDescriptionText)`, `OnButtonAction(int actionId)`, `UpdateConfirmButtonState()`, and `[[CHILDREN]]`; retained the larger no-route selection helper caveat.
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
- 2026-06-11 A003 Batch 150 parent-gate repair:
  - Before: `82/85`, `AUTOGEN_PARENT_UID` blank because the child did not clear the strict `85/85` completion gate.
  - After: `85/87`, `AUTOGEN_PARENT_UID:0000LA`.
  - Summary/evidence: live IDA MCP reconfirmed the constructor/action/update ranges, four constructor caller sites, constructor vtable stores at `0x00622698`, `0x006226f8`, and `0x00622728`, field offsets `+0x26c/+0x270/+0x274/+0x276`, `.EPF`/`.EPD` large-layout resource branches, two `MenuQuestionItemListLarger` construction calls, action serialization as decimal 58 / `0x3a` (Verified with int_convert.py), and vtable refs for the action/update methods. Superseded by the 2026-07-01 B010 callback, which emits the declaration shell while keeping method bodies below the final-source gate.
- 2026-06-16 B001 split execution:
  - Score remains `85/87`.
  - Summary/evidence: linked exact method children [UID:0003W4][0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor](by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md), [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md), and [UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md); [UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md) is recorded as non-emitting raw helper evidence.
- 2026-06-20 B002 Rule 26 support sync:
  - Score unchanged. Clarified that confirm-button state uses shared ListPane selection-count helper `0x004f3e20`, not [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md).
  - Evidence: B002 PE/source-routing report distinguishes the live updater path from the no-route selected-option-id helper.
- 2026-06-21 supervisor-worker Rule 26 incorporation of B012 `0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md`:
  - Score unchanged. Clarified that [UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md) is a dead retained private-helper candidate, not an emitting class method.
  - Evidence: B012 PE scan found no rel32/VA/RVA route to `0x00550c80` while positive controls found vtable refs for [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md)/[UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md) and direct constructor calls to [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md); [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md) remains the active inline submit-and-close path.
