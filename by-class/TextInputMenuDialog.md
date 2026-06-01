*** UID:0000ER | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextInputMenuDialog

## Status

- Confidence: strong for behavior and boundaries; generated source has method-name/control-character caveats.
- Likely source file: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_TextInputMenuDialog.cpp`

## Class Purpose

`TextInputMenuDialog` is the text-entry variant of the server-driven merchant/NPC menu dialog. It displays a merchant/object image, message text, and editable text field, validates the edit control state, and sends opcode `0x39` with the selected option and typed text.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005198e0-0x0051a275` | `TextInputMenuDialog` | Constructor and packet parser; builds `DLGMERC2` style controls, optional extra string state, and the edit control. |
| `0x0051a280-0x0051a3d4` | `OnButtonPress` | Submits text input on OK, sends cancel via `TextMenuDialog::SendMenuRequestPacket`, or closes on close/cancel. |
| `0x0051a3e0-0x0051a416` | `ValidateInput` | Updates OK/action availability based on the edit control contents. |
| [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) | `SendInputReply` | Raw helper that serializes opcode `0x39`, stored dialog fields, optional extra text, and caller-supplied input text. |
| `0x00520b29-0x00520b3e` | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| `0x00520d50-0x00520d97` | scalar deleting destructor | Tears down text-input dialog state and deletes according to flags. |

## Evidence Notes

- Wave3 identifies this as a `MerchantDialogPane -> DialogPane` class with three vtable pointers and an EPF/EPD dual asset path.
- IDA MCP confirms the constructor, two virtual methods, two thunks, and destructor starts.
- The OK path reads the edit control text. [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) contains the raw serialization body for dialog type, merchant id, selected option, optional extra string, and typed text before queuing the packet through the shared send path.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `82`.
- Evidence: the page documents text-input menu role, constructor/action/validate/reply-helper/destructor-thunk ranges, packet serialization, vtable family, and generated method-name caveats.
