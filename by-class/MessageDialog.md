*** UID:000085 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MessageDialog : public PursuitMessageDialogPane
{
public:
    MessageDialog(const unsigned char *packet, bool hasText);
    virtual bool OnButtonAction(int actionId);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MessageDialog

## Status

- Confidence: strong for ownership and boundaries; generated source is not migration-ready.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main method children: [UID:0003VY][0x0054ce10-0x0054db3e.MessageDialogConstructor](by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md), [UID:0003VZ][0x0054db40-0x0054db8b.MessageDialogActionHandler](by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md). The former broad aggregate [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) is now a non-emitting split index.
- Vtable data: [UID:0003D1][0x006224c0-0x0062255c.MessageDialogVtableData](by-memory/0x006224c0-0x0062255c.MessageDialogVtableData.md)
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). The B010 callback raised this class to `87/89`; the direct file parent is `91/88`, so the strict child/direct-parent gate clears.

## Class Purpose

`MessageDialog` is the normal NPC/system message dialog. It parses packet data for a message type, object descriptor, optional text body, layout flags, and navigation button state, then builds `DialogPane` controls for the background, object image, text, and previous/next/current buttons.

B010 2026-07-01 resolves the empty emitter as declaration-level source with a constructor and action virtual shell. The dispatcher/wrapper page [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) now emits factory calls to `MessageDialog(payload, hasText)`, while exact constructor/action behavior remains on this class's by-memory children.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0003VY][0x0054ce10-0x0054db3e.MessageDialogConstructor](by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md) | `MessageDialog::MessageDialog(uint8_t* packet, char compactLayout)` | Packet parser and dialog/control builder; live IDA reports size `0xd2e` / 3374 bytes (verified with `int_convert.py`). |
| [UID:0003VZ][0x0054db40-0x0054db8b.MessageDialogActionHandler](by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md) | `OnDialogAction(int actionId)` | Vtable-only action handler; live IDA reports size `0x4b` / 75 bytes (verified with `int_convert.py`). |

## Evidence Notes

- IDA MCP confirms both functions as exact starts.
- Existing project documentation records direct callers from the packet-driven dialog dispatch path around `0x0054c200`.
- Current reconstruction notes still treat source output placeholders for packet offsets/resource arguments as unresolved; rely on IDA-backed by-* evidence for boundaries and behavior until those expressions are audited.
- 2026-05-25 IDA decompilation resolves the key omitted packet offsets: the constructor reads message type from `packet[0]`, object id from `packet+1`, a display/object flag from `packet[5]`, parses the variable object descriptor at `packet+6`, then reads the two state words at `packet + descriptorLength + 10` and `packet + descriptorLength + 12`.
- In the text-bearing branch, IDA reads the text byte length at `packet + descriptorLength + 16`, copies bytes from `packet + descriptorLength + 18`, converts them through `MultiByteToWideChar`, and builds the text control. Current `simroot_v2/class_MessageDialog.cpp` still emits omitted placeholder comments for these offsets.
- 2026-06-12 Batch 260 live IDA MCP `py_eval` reconfirmed the constructor range `0x0054ce10-0x0054db3e`, action-handler range `0x0054db40-0x0054db8b`, constructor callers at `0x0054c388`/`0x0054c3c7` from the main dispatcher plus wrapper calls at `0x0054c5b5`/`0x0054c675`, and the constructor's three vtable stores to `0x006224c4`, `0x00622524`, and `0x00622554`.
- The same pass tied the class to read-only resources used by the constructor: `DLGMSG1.PAL`, `DLGMSG11.EPF`, `DLGMSG1.EPF`, `DLGMSG2.EPF`, `DLGMSG11.EPD`, `DLGMSG1.EPD`, and `DLGMSG2.EPD`.
- 2026-06-16 B001 split execution created exact method children [UID:0003VY][0x0054ce10-0x0054db3e.MessageDialogConstructor](by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md) and [UID:0003VZ][0x0054db40-0x0054db8b.MessageDialogActionHandler](by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md); [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) remains only the non-emitting family index.

## Vtable And Action Evidence

The exact vtable child [UID:0003D1][0x006224c0-0x0062255c.MessageDialogVtableData](by-memory/0x006224c0-0x0062255c.MessageDialogVtableData.md) now supplies the missing direct class-layout evidence:

| Vtable view | Constructor store | Key slots |
| --- | --- | --- |
| `0x006224c4` primary `MessageDialog` view | `0x0054ce61` | scalar deleting destructor slot `0x00520b70`; action slot at `0x0062250c -> 0x0054db40`; shared base/UI virtuals inherited from the dialog hierarchy. |
| `0x00622524` adjusted view | `0x0054ce67` | destructor thunk `0x00520aa5`; shared object-response virtual slot `0x00622534 -> 0x0054caf0`; support slots through `0x0062254c`. |
| `0x00622554` tertiary view | `0x0054ce71` | destructor thunk `0x00520ab0` and one support slot `0x00544e90`; the next complete-object locator at `0x0062255c` starts `MessageDialogLarger`. |

IDA MCP decompilation of `0x0054db40` maps action ids precisely: case `1` calls [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) previous helper `0x0054cc30`, case `2` calls next helper `0x0054ccd0`, and case `3` calls current helper `0x0054cd70`; all handled cases then call the dialog close helper at `0x0049dad0`.

## Assignment Gate

`MessageDialog` now clears the strict gate at `87/89`, and the direct source-file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) already clears at `91/88`. The class can attach to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and the exact vtable child [UID:0003D1][0x006224c0-0x0062255c.MessageDialogVtableData](by-memory/0x006224c0-0x0062255c.MessageDialogVtableData.md) can attach here as the direct semantic owner. The declaration shell now emits; constructor/action method bodies remain gated on source-quality packet/control names and a method-level rewrite pass.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:000086][MessageDialogLarger](by-class/MessageDialogLarger.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:0003VY][0x0054ce10-0x0054db3e.MessageDialogConstructor](by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md)
- [UID:0003VZ][0x0054db40-0x0054db8b.MessageDialogActionHandler](by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md)
- [UID:0003D1][0x006224c0-0x0062255c.MessageDialogVtableData](by-memory/0x006224c0-0x0062255c.MessageDialogVtableData.md)

## Changes

- 2026-07-01 Agent-B010 implementation callback: raised `86/88 -> 87/89`, set emitter position `40`, and added the accepted declaration shell for `MessageDialog(const unsigned char *packet, bool hasText)`, `OnButtonAction(int actionId)`, and `[[CHILDREN]]`.
- Completion/confidence score update: existed before as `0/0`; changed to `80/82`. Summary: the normal packet-driven message dialog has strong ownership, exact boundaries, constructor/action behavior, packet offset details, and generated-source caveats documented, but source migration remains blocked by placeholder expressions in current output. Evidence: linked NPC message/menu-question range, IDA-confirmed starts, packet dispatch callers, 2026-05-25 offset decompilation notes, and `simroot_v2` placeholder caveat.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) under the older gate because the class was `80/82` and the parent was `88/80`. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0054ce10` and `0x0054db40`; current `callers` confirms constructor references from the shared packet-dialog dispatch around `0x0054c200`.
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000LA` attached this class to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and the status/evidence still carried generated-output provenance.
  - After: `AUTOGEN_PARENT_UID:` is blank and the status records the strict `85/85` gate; score remains `80/82`.
  - Summary/evidence: the direct parent is now `89/85`, but this child remains below the child side of the current gate. The source-owner link remains as evidence, backed by IDA-confirmed starts, packet-dispatch constructor xrefs, and the documented packet-offset decompilation notes.
- 2026-06-12 A001 Batch 260 parent-gate repair:
  - Before: `80/82`, `AUTOGEN_PARENT_UID:` blank, and the exact [UID:0003D1][0x006224c0-0x0062255c.MessageDialogVtableData](by-memory/0x006224c0-0x0062255c.MessageDialogVtableData.md) vtable child was parent-blocked.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000LA`; the exact vtable child can attach to this class.
  - Summary/evidence: live IDA MCP reconfirmed constructor/action ranges, dispatcher and wrapper constructor callers, constructor stores to the three `MessageDialog` vtable views, key vtable slots, DLGMSG resource references, and action handler command-id mapping to previous/next/current packet helpers plus dialog close.
- 2026-06-16 B001 split execution:
  - Score remains `86/88`.
  - Summary/evidence: linked exact method children [UID:0003VY][0x0054ce10-0x0054db3e.MessageDialogConstructor](by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md) and [UID:0003VZ][0x0054db40-0x0054db8b.MessageDialogActionHandler](by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md). The prior [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) page is now a non-emitting split index.
