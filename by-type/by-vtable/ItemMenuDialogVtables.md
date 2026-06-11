*** UID:00031Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Item Menu Dialog Vtables

## Status

- Entity kind: owner-specific MSVC vtable layout.
- Source owner: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
- Covered classes: `ServerItemMenuDialog`, `ServerItemMenuItemList`, `ClientItemMenuDialog`, and `ClientItemMenuItemList`.
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- IDA evidence basis: B001-008 live IDA MCP `py_eval` on 2026-06-10 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Binary Evidence

| Class | Vtable bases | Store/xref evidence |
| --- | --- | --- |
| `ServerItemMenuDialog` | `0x0061eea8`, `0x0061ef08`, `0x0061ef38` | Constructor `0x0051a520` stores at `0x0051a596`, `0x0051a59c`, and `0x0051a5a6`. |
| `ServerItemMenuItemList` | `0x0061ef44`, `0x0061efcc`, `0x0061effc` | Inline owner stores at `0x0051a6ff`, `0x0051a705`, `0x0051a70f`, raw/list constructor stores near `0x0051aedb-0x0051af13`, and destructor stores at `0x00520ce6-0x00520cf6`. |
| `ClientItemMenuDialog` | `0x0061f008`, `0x0061f068`, `0x0061f098` | Constructor `0x0051b880` stores at `0x0051b8e9`, `0x0051b8ef`, and `0x0051b8f9`. |
| `ClientItemMenuItemList` | `0x0061f0a4`, `0x0061f12c`, `0x0061f15c` | Constructor `0x0051c470` stores at `0x0051c4a7`, `0x0051c4ad`, and `0x0051c4b7`. |

Every listed base has a decorated `??_7...@@6B@` name and a complete-object-locator pointer at `base - 4`. The server and client dialog secondary views contain inherited `0x00517d80` slots at `0x0061ef18` and `0x0061f078`.

## Ownership Inference

The item-menu vtable subfamily belongs to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). Its constructor and inline list stores are inside [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md), and the existing file parent already clears the corrected `85/85` gate.

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | selected | Direct owner bucket for server/client item-menu dialogs and their private item-list companions. |
| Individual item class pages | rejected for this grouped page | Some exact class pages remain below `85/85`; this page is an owner-specific source-family page. |
| [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | rejected | Supplies inherited dialog-base virtual only. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory across unrelated source owners. |

## Reconstruction Notes

Reconstruct these vtables through the item-menu class declarations and list-pane companion declarations. Do not emit raw vtable data as source.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `ItemMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor/list/destructor store xrefs, and inherited dialog-base slots for the two dialog classes.
