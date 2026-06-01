*** UID:00002J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanNameInputDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_ClanNameInputDialog.cpp`

## Class Purpose

`ClanNameInputDialog` is the shared `DLGCLAN1.EPF` modal dialog used by several clan name, money, and text-entry flows. It builds the background, OK/Cancel buttons, prompt text, and text edit control, then delegates final submission through a virtual submit hook.

The base dialog uses inherited control-host state at `+0x1fc`. Control id `1` is OK, `2` is Cancel, and `4` is the text edit field read on OK.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanNameInputDialog` | `0x00488b40-0x00488eaa` | Builds the modal input dialog from packet-provided prompt text. |
| `OnButtonClick` | `0x00488eb0-0x00488f23` | On OK, gets control text and calls the submit hook; OK and Cancel both close the dialog. |
| `UpdateOkButtonState` | `0x00488f30-0x00488f66` | Enables or disables OK depending on whether input text is empty. |
| `OnInputEvent` | `0x00488f70-0x00488f9f` | Forwards input changes and refreshes OK state. |

## Evidence Notes

- IDA confirms all four function starts and sizes.
- Derived dialogs install new primary/secondary vtables on top of this base shell, but many of their constructor starts are projected non-IDA records.
- 2026-05-26 IDA decompilation confirms `OnButtonClick` fetches control id `4` through the inherited control host at `this + 0x1fc`, then dispatches the submitted text through the primary vtable submit hook at slot `+0x5c`.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md)
- [UID:00002O][ClanWidMoneyInputDialog](by-class/ClanWidMoneyInputDialog.md)
- [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md)
- [UID:00002M][ClanSummonNameInputDialog](by-class/ClanSummonNameInputDialog.md)
- [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md)
- [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md)

## Changes

- What existed before: the page documented the shared clan input dialog shell, control ids, base storage, methods, derived classes, and layout references, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: constructor, button action, OK-state refresh, input refresh, derived submit hook, and layout docs are covered; exact member names and final header/source split remain below exhaustive.
