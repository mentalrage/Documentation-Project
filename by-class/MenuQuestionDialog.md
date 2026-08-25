*** UID:00007X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MenuQuestionDialog : public PursuitMessageDialogPane
{
public:
    MenuQuestionDialog(const unsigned char *packet, bool hasDescriptionText);
    virtual bool OnButtonAction(int actionId, int unused);
    virtual void UpdateConfirmButtonState();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionDialog

## Status

- Confidence: very strong for ownership, exact method boundaries, dispatcher paths, normal list-widget relationship, packet-field offsets, action/update behavior, and vtable slots; final source API/control names still need framework-wide cleanup.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main method children: [UID:0003W0][0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor](by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md), [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md), [UID:0003W2][0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState](by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md). The adjacent raw selection helper [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md) is non-emitting; [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) is now a non-emitting split index.
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). The direct parent clears at `89/85`, and this child now clears the strict child/direct-parent `85/85` gate at `86/88`.
- Declaration-level C++ is now emitted for the class shell; method-body emission remains gated on control member names, row-record names, and final `DialogPane`/`ListPane` framework APIs.

## Class Purpose

`MenuQuestionDialog` is the normal-layout menu-question dialog. It parses a packet containing a menu category byte, context object id, object descriptor, page/index state, optional description text, and a list of selectable item labels. It builds a scrollable `MenuQuestionItemList`, configures the normal `DLGMSG*` background/button layout, and sends opcode `0x3a` selection or navigation replies when the user acts.

B010 2026-07-01 resolves the empty emitter as declaration-level source with constructor/action/update virtuals and `[[CHILDREN]]`. [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) now emits factory calls to `MenuQuestionDialog(payload, hasDescriptionText)`, while the normal no-route selection packet helper remains non-emitting support evidence.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0003W0][0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor](by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md) | `MenuQuestionDialog::MenuQuestionDialog(uint8_t* packet, char hasDescriptionText)` | Packet parser, object/description/list builder, background/object/text/button layout builder. IDA reports size `0xfbd`. |
| [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md) | `OnButtonAction(int action, int unused)` | Case `1` sends the selected item reply; cases `2`, `3`, and `4` call the shared previous/next/current dialog helpers. IDA reports size `0x130`. |
| [UID:0003W2][0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState](by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md) | `UpdateConfirmButtonState()` | Enables or disables the confirm button based on the menu-list selectable-entry state. IDA reports size `0x3d`. |

## Evidence Notes

- Existing IDA MCP notes in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) confirm exact starts at `0x0054e920`, `0x0054f8e0`, and `0x0054fa20`.
- 2026-06-11 live IDA MCP `lookup_funcs` and `decompile` reconfirm `0x0054e920` as a `0xfbd` constructor, `0x0054f8e0` as a `0x130` action handler, and `0x0054fa20` as a `0x3d` confirm-state updater.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the dispatcher rule: `packet[1]` bit `0x10` selects larger-layout families and the low nibble selects the message/menu-question/text/head/proxy constructor path.
- The same dispatcher/wrapper page records two normal menu-question allocation wrappers: `0x0054c6f0-0x0054c74b` calls `0x0054e920` with final flag `1`, and `0x0054c7b0-0x0054c80b` calls `0x0054e920` with final flag `0`. The direct dispatcher caller evidence in [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) lists constructor paths at `0x0054c406` and `0x0054c445`.
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md) records constructor xrefs from this dialog at `0x0054eb04` and `0x0054f276`, tying the normal list widget to the normal dialog constructor rather than generic menu infrastructure.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the menu-question dialog vtable band at `0x006225fc-0x00622728`, the normal/larger item-list vtable band at `0x00622734-0x006228b0`, and a resource-string xref into normal menu-question layout/setup at `0x0054ec66`.
- Live IDA MCP `py_eval` dword sweep confirms the normal dialog vtable cells: primary table starts at `0x006225fc`, the action/update slots are `0x00622644 -> 0x0054f8e0` and `0x00622648 -> 0x0054fa20`, the shared object-response slot is `0x0062266c -> 0x0054caf0`, and secondary/tertiary table writes target `0x0062265c` and `0x0062268c`.
- The constructor writes vtables at the primary object plus subobject offsets `+0xa0` and `+0xa4`; IDA reports decimal offsets `160` and `164`, verified as `0xa0` and `0xa4` with `int_convert.py` (Verified with int_convert.py).
- Constructor decompilation resolves the stored packet fields: `packet[0]` is stored at `this+0x26c`, the object/context id from `packet+1` is stored at `this+0x270`, and the two post-descriptor state words are stored at `this+0x274` and `this+0x276`. IDA decimal offsets `620/624/628/630` were verified as `0x26c/0x270/0x274/0x276` with `int_convert.py` (Verified with int_convert.py).
- The constructor parses the object descriptor at `packet+6`; when the caller's description flag is set, it reads a byte-length-prefixed description, copies bytes through the local string helper, converts to UTF-16 with `MultiByteToWideChar`, and range-checks the `0x8000` buffer limit. Without the flag it uses an empty wide string.
- The item-list construction path allocates [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), reads a one-byte item count, then loops over byte-length-prefixed labels, converting each label to UTF-16 and inserting a row record whose first prefix byte is the one-based option id and whose text is consumed by the list renderer at the documented `+2` offset.
- The layout branch is now better bounded: `byte_66DA97` selects the EPF/PAL-backed path versus the EPD-backed path, the description flag shifts the normal layout rectangles, and the object-type set `1/2/3/5/6` chooses between the `DLGMSG3` and `DLGMSG31` variants. Final source-facing names for this global mode byte and the layout-control helpers remain provisional.
- The action handler's case `1` reads the selected row id from child/control id `5`, serializes opcode `0x3a`, the stored dialog fields, `this+0x276 + 1`, a selection marker byte, and the selected row id, writes a local terminator byte at `packet[12]`, sends exactly 12 bytes through `dword_67A7EC`, and closes the dialog. The zero byte is outside the counted payload, not a trailing protocol field. Cases `2`, `3`, and `4` call the shared dialog navigation helpers at `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70`.
- B004 2026-06-19 rechecked adjacent [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md) as a source-shaped `SendSelectionPacket(uint8_t selectedRowId)` candidate. Keep it no-owner/non-emitting because fresh PE and prior IDA evidence find no function, no xrefs, no rel32 branch/call route, no instruction-immediate route, and no VA/RVA pointer route; active submit behavior remains [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md).
- The confirm-state updater has no direct code callers; `xrefs_to` reports vtable data refs for `0x0054f8e0` at `0x00622644` and `0x0054fa20` at `0x00622648`. Its body fetches controls/list entries through child ids `1` and `5`, tests the list object at offset `+0x108` (IDA decimal `264`; Verified with int_convert.py), calls `0x004f3e20` (`ListPane::GetSelectionCount()` / `HasSelection()`), and dispatches to the target control enable/disable vtable slot based on whether the list has selectable entries. B002 2026-06-20 confirms this updater does not call raw helper [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md); that helper returns selected row byte `+0` as an option id and remains no-owner/non-emitting.
- Existing by-memory and file-family docs tie this dialog to the shared message/menu-question packet dispatcher under [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), not to generic menu infrastructure.
- 2026-06-16 B001 split execution created exact method children [UID:0003W0][0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor](by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md), [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md), and [UID:0003W2][0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState](by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md). The adjacent raw helper [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md) remains non-emitting because packet helper ownership/source naming is not safe.

## State And Dependencies

| Field/dependency | Evidence/role | Reconstruction note |
| --- | --- | --- |
| `this+0x26c` dialog/menu category byte | Stored from `packet[0]` and serialized into the selection reply. | Best field direction is `m_dialogType` or `m_menuCategory`; keep as a packet-header field until the message/menu packet struct is named. |
| `this+0x270` object/context id | Stored from the little-endian dword at `packet+1`; serialized into the reply. | Best field direction is `m_objectId` or `m_contextObjectId`; same source-level packet field as the message-dialog object/context id. |
| `this+0x274` and `this+0x276` state words | Read after the variable object descriptor; the second word is incremented before serialization. | Best directions are `m_dialogState` and `m_pageIndex`; selection serializes `m_pageIndex + 1`, but final field names remain open. |
| Child/control id `5` | Constructor inserts the `MenuQuestionItemList`; action/update paths use the same id to read selection and selectable-entry state. | Confirms the list is private dialog state, not a generic menu singleton. |
| `byte_66DA97` asset-mode branch | Constructor switches between EPF/PAL and EPD resource families. | Do not rename here while the dedicated global documentation is being handled separately. |

## Score And Gate Rationale

The page is now `86/88`: it documents exact method starts and sizes, dispatcher and allocation-wrapper paths, constructor caller evidence, normal list-widget ownership, vtable slot addresses, constructor packet-field offsets, item-list row creation, description-text decoding, layout resource branches, action-packet serialization, confirm-button state logic, and final-C++ blockers.

`AUTOGEN_PARENT_UID` is set to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) because the direct parent is `89/85` and this child now clears the strict child/direct-parent `85/85` gate. Completion remains below final-audit quality because final source-facing control names, packet struct names, row-record names, and broader `DialogPane`/`ListPane` API names are still not settled.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0003W0][0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor](by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md)
- [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md)
- [UID:0003W2][0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState](by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md)
- [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)

## Changes

- 2026-07-01 Agent-B010 implementation callback: raised `86/88 -> 87/89`, set emitter position `60`, and added the accepted declaration shell for `MenuQuestionDialog(const unsigned char *packet, bool hasDescriptionText)`, `OnButtonAction(int actionId, int unused)`, `UpdateConfirmButtonState()`, and `[[CHILDREN]]`; retained the normal no-route selection helper caveat.
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
- 2026-06-11 A001 method-level parent-gate pass:
  - Before: `82/85`, with `AUTOGEN_PARENT_UID` blank because the child did not clear the completion side of the strict gate.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000LA`.
  - Summary/evidence: live IDA MCP reconfirmed method sizes, constructor callers, vtable slots, constructor vtable stores, packet-field offsets, optional description decoding, row item insertion, EPF/PAL versus EPD resource branch, action case serialization, navigation helper calls, and confirm-button enable/disable logic. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) already clears `89/85`, so this class now attaches under the strict child/direct-parent `85/85` gate.
- 2026-06-16 B001 split execution:
  - Score remains `86/88`.
  - Summary/evidence: linked exact method children [UID:0003W0][0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor](by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md), [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md), and [UID:0003W2][0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState](by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md); [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md) is recorded as non-emitting raw helper evidence.
- 2026-06-20 B002 Rule 26 support sync:
  - Score unchanged. Clarified that confirm-button state uses shared ListPane selection-count helper `0x004f3e20`, not [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md).
  - Evidence: B002 PE/source-routing report distinguishes the live updater path from the no-route selected-option-id helper.
- 2026-06-20 B004 Rule 26 support sync:
  - Score unchanged. Corrected selection-packet wording so `packet[12] = 0` is documented as a local terminator outside the 12-byte send length, added the no-route [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md) `SendSelectionPacket(uint8_t)` candidate caveat, and refined field-name directions for `this+0x26c..0x276`.
  - Evidence: B004 PE/source-routing report distinguishes active routed [UID:0003W1][0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler](by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md) submit behavior from the adjacent no-route raw helper and confirms no route to `0x0054fa60`.
