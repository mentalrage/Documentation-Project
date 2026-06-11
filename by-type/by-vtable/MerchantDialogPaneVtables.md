*** UID:00031W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MerchantDialogPane Vtables

## Status

- Entity kind: owner-specific MSVC vtable layout.
- Source owner: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md).
- Covered class: [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md).
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- IDA evidence basis: B001-008 live IDA MCP `py_eval` on 2026-06-10 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Binary Evidence

| View | Vtable base | Complete-object locator | Store/xref evidence |
| --- | --- | --- | --- |
| primary | `0x0061ec10` `??_7MerchantDialogPane@@6B@` | `0x0061ec0c -> 0x0064b774` `??_R4MerchantDialogPane@@6B@` | raw constructor-shaped code at `0x00517d53`. |
| secondary | `0x0061ec70` `??_7MerchantDialogPane@@6B@_0` | `0x0061ec6c -> 0x0064b7d4` `??_R4MerchantDialogPane@@6B@_0` | raw constructor-shaped code at `0x00517d59`. |
| tertiary | `0x0061eca0` `??_7MerchantDialogPane@@6B@_1` | `0x0061ec9c -> 0x0064b7e8` `??_R4MerchantDialogPane@@6B@_1` | raw constructor-shaped code at `0x00517d63`. |

The secondary view slot at `0x0061ec80` contains `0x00517d80` (`sub_517D80`), the shared `MerchantDialogPane` action-string virtual. IDA reports eight data refs to that function from the merchant/text/item/spell/argumented dialog-family secondary tables.

## Ownership Inference

The direct source owner is the `MerchantDialogPane` source bucket, not the full merchant menu vtable family. IDA ties all three table writes to the raw constructor-shaped `0x00517d30` body documented in [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md), and the shared virtual at `0x00517d80` is documented as [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md).

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | selected | The page owns the constructor and shared virtual that materialize these three vtable views. |
| [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) | rejected for now | The class page remains below `85/85`; by-file routing is the stronger current owner bucket until the class page is independently raised. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory over five source owners, not the direct source owner for this class. |
| [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md) | rejected | Contiguous `.rdata` aggregate crosses menu, input, object-image, and string owners. |

## Reconstruction Notes

Reconstruct these vtables through the `MerchantDialogPane` class declaration, inheritance shape, constructor, and virtual destructor/action-string declarations. Do not hand-port the raw vtable bytes into C++.

## Cross-References

- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)

## Changes

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `MerchantDialogPane` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, raw constructor store sites, and the inherited `0x00517d80` secondary slot.
