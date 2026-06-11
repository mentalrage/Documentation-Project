*** UID:00031Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Text Menu Dialog Vtables

## Status

- Entity kind: owner-specific MSVC vtable layout.
- Source owner: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- Covered classes: [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md), [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md), and [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md).
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- IDA evidence basis: B001-008 live IDA MCP `py_eval` on 2026-06-10 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Binary Evidence

| Class | Vtable bases | Complete-object locator evidence | Store/xref evidence |
| --- | --- | --- | --- |
| `TextMenuDialog` | `0x0061ecac`, `0x0061ed0c`, `0x0061ed3c` | COL pointers at `0x0061eca8`, `0x0061ed08`, `0x0061ed38` to `??_R4TextMenuDialog@@6B@` records. | Constructor `0x00517f30` stores at `0x00517fa0`, `0x00517fa6`, and `0x00517fb0`. |
| `TextMenuItemList` | `0x0061ed48`, `0x0061edd0`, `0x0061ee00` | COL pointers at `0x0061ed44`, `0x0061edcc`, `0x0061edfc` to `??_R4TextMenuItemList@@6B@` records. | Constructor `0x00519520` stores at `0x00519560`, `0x00519566`, and `0x00519570`. |
| `TextInputMenuDialog` | `0x0061ee0c`, `0x0061ee6c`, `0x0061ee9c` | COL pointers at `0x0061ee08`, `0x0061ee68`, `0x0061ee98` to `??_R4TextInputMenuDialog@@6B@` records. | Constructor `0x005198e0` stores at `0x00519950`, `0x00519956`, and `0x00519960`. |

The `TextMenuDialog` and `TextInputMenuDialog` secondary views contain the inherited `MerchantDialogPane` action-string virtual `0x00517d80` at `0x0061ed1c` and `0x0061ee7c`. The list companion does not contain that dialog-base slot, matching its list-pane role.

## Ownership Inference

These tables belong to the text-menu source owner, not to the merchant base or the item/spell/argumented variants. The constructor store sites fall entirely inside [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md), and the classes are the text and text-input menu variants that use `DLGMERC1`/`DLGMERC2` UI assets and opcode `0x39` reply helpers.

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) | selected | Direct owner bucket for the text dialog, text-input dialog, and private text list companion. |
| Individual class pages | rejected for this grouped page | Some class pages remain below `85/85`, and this page intentionally covers the coherent text-menu source group rather than one exact class. |
| [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | rejected | Provides the inherited dialog-base virtual but does not own these constructors or text/menu behavior. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory over multiple source owners. |

## Reconstruction Notes

Reconstruct these vtables from the `TextMenuDialog`, `TextInputMenuDialog`, and `TextMenuItemList` declarations inside the `TextMenuDialogs` source bucket. The vtable bytes are compiler output and should remain blank in reconstructed C++.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `TextMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor store sites, and inherited `0x00517d80` dialog-base slots for the two dialog classes.
