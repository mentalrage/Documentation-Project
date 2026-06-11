*** UID:000320 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Argumented Menu Dialog Vtables

## Status

- Entity kind: owner-specific MSVC vtable layout.
- Source owner: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).
- Covered classes: [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) and [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md).
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- IDA evidence basis: B001-008 live IDA MCP `py_eval` on 2026-06-10 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Binary Evidence

| Class | Vtable bases | Store/xref evidence |
| --- | --- | --- |
| `ArgumentedMenuMenuDialog` | `0x0061f428`, `0x0061f488`, `0x0061f4b8` | Constructor `0x0051e9a0` stores at `0x0051ea16`, `0x0051ea1c`, and `0x0051ea26`. |
| `ArgumentedMenuMenuItemList` | `0x0061f4c4`, `0x0061f54c`, `0x0061f57c` | Owner constructor stores at `0x0051eb7f`, `0x0051eb85`, `0x0051eb8f`; list constructor stores at `0x0051f2b6`, `0x0051f2bc`, `0x0051f2c6`; raw/list helper stores at `0x0051f35b-0x0051f393`; destructor stores at `0x00520bb6-0x00520bc6`. |

Every listed base has a decorated `??_7...@@6B@` name and a complete-object-locator pointer at `base - 4`. The `ArgumentedMenuMenuDialog` secondary view contains inherited `0x00517d80` at `0x0061f498`.

The next named vtable base after this owner-specific set is `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`, so the argumented menu vtable child stops before the separate argumented input-dialog owner.

## Ownership Inference

The argumented-menu vtable subfamily belongs to [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md). The dialog constructor, list constructor, list update/draw helpers, and destructor stores all land in the argumented menu executable family documented by [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md). The successor at `0x0061f588` belongs to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), not this child.

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) | selected | Direct owner bucket for the argumented menu dialog and private argumented item-list companion. |
| [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) | rejected | Related dialog-family source, but the argumented menu split has its own file root and executable/vtable cluster. |
| [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) | rejected | Owns the successor quantity/confirm input dialog vtables beginning at `0x0061f588`, not the menu dialog/list tables. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory across unrelated source owners. |

## Reconstruction Notes

Reconstruct these vtables through the argumented menu dialog and list declarations. Do not emit raw vtable data as source.

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `ArgumentedMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor/list/destructor store xrefs, inherited `0x00517d80`, and the `0x0061f588` successor boundary.
