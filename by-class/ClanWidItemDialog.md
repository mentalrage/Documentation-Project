*** UID:00002N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanWidItemDialog

## Status

- Confidence: strong for confirmed methods.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current recovered file: `source-3/simroot_v2/class_ClanWidItemDialog.cpp`

## Class Purpose

`ClanWidItemDialog` is the clan-bank item withdraw dialog. It parses title/detail/list payload text from the packet, creates the `DL_15` dialog with a `ClanItemListPane`, reads selected item plus quantity, and sends the withdraw request packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanWidItemDialog` | `0x0048a810-0x0048ace4` | Builds the dialog, decodes packet text, constructs `ClanItemListPane`, quantity edit, and UI/input attachments. |
| vtable-reset helper | `0x0048acf0-0x0048ad0f` | Real IDA function with no Wave3 memory owner; resets class vtables before base cleanup. |
| `OnDialogAction` | `0x0048ad10-0x0048ade8` | On OK, reads selected item and quantity, calls packet sender, then OK/Cancel closes. |
| `SendWithdrawRequestPacket` | `0x0048adf0-0x0048ae64` | Sends opcode `0x4b`, subtype `12`, action `1`, item type, and quantity. |

## Evidence Notes

- IDA confirms real starts at `0x0048a810`, `0x0048acf0`, `0x0048ad10`, and `0x0048adf0`.
- The withdraw dialog constructs `ClanItemListPane`, supporting a shared `ClanBank.cpp` or `ClanItemDialogs.cpp` grouping with the deposit dialog.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md)

## Changes

- What existed before: the page documented confirmed withdraw-item dialog methods and dependencies, but metadata was still `0/0`.
- What it was changed to: scores were set to `74/84`.
- Summary and evidence: constructor, vtable reset, dialog action, packet sender, and `ClanItemListPane` dependency are covered; detailed widget field layout and final module split remain incomplete.
