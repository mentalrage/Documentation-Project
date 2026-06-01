*** UID:000024 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanAttrInputDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_ClanAttrInputDialog.cpp`

## Class Purpose

`ClanAttrInputDialog` is the `DLGCLAN2.EPF` multi-field clan attribute dialog. It creates five labels, three required edit controls, OK/Cancel buttons, stores submitted text/value fields, validates that required inputs are populated, and delegates final confirmation to a derived virtual.

The persistent submitted-field storage is at `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`. `ClanChangeInputDialog::SubmitClanChange` passes those fields to the opcode `0x4b` subtype `10` helper.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanAttrInputDialog` | `0x00489600-0x00489de0` | Builds the dialog and decodes packet-provided initial text/labels. |
| `OnDialogAction` | `0x00489df0-0x00489eb6` | On OK, reads fields `8`, `9`, `10`, stores text/value data, and calls confirmation hook; OK and Cancel close the dialog. |
| `ValidateInputFields` | `0x00489ec0-0x00489f45` | Enables/disables OK based on required edit fields. |
| `OnInputEvent` | `0x00489f50-0x00489f80` | Refreshes validation after input changes. |
| destructor/thunks | `0x0048c291`, `0x0048c29c`, `0x0048c390-0x0048c3ca` | Vtable thunks and scalar deleting destructor. |

## Evidence Notes

- IDA confirms all four core function starts and the destructor.
- `ClanChangeInputDialog` derives from this dialog and sends the final multi-field attribute change through helper `0x00486330`.
- 2026-05-26 IDA decompilation confirms `OnDialogAction` reads controls `8`, `9`, and `10`, copies the two text fields into `+0x46c` and `+0x66c`, parses the numeric value into `+0x86c`, and dispatches the confirmation virtual.
- 2026-05-27 IDA boundary check reports `OnInputEvent` (`sub_489F50`) at `0x00489f50-0x00489f80`; byte `0x00489f7f` is the last byte of `retn 4`.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)

## Changes

- 2026-05-27: Corrected `OnInputEvent` from `0x00489f50-0x00489f7f` to exclusive end `0x00489f80`. Evidence: IDA MCP reports `sub_489F50` at `0x00489f50-0x00489f80`, with `retn 4` occupying bytes `0x00489f7d-0x00489f7f`.
- What existed before: the page documented the multi-field clan attribute dialog, core method boundaries, submitted-field storage, layout docs, and IDA-backed range correction, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: constructor, action, validation, input refresh, destructor/thunk family, field offsets, derived submit use, and layout references are covered; exact final source/header form and some widget field names remain below exhaustive.
