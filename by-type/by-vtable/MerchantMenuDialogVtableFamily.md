*** UID:0001Y5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Merchant Menu Dialog Vtable Family

## Status

- Disposition: vtable family inventory for reconstructable NexusTK merchant/NPC menu dialog code.
- Covered source owners: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md), [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), and [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).
- Confidence: strong for table bases and RTTI presence; medium for final original source-file split.
- Verification: IDA MCP `list_globals` checks on 2026-05-26. Current `simroot_v2` metadata reports `vtable_count: 0` for every checked class in this family.

## Current IDA Recheck

IDA MCP `py_eval` on 2026-06-01 rechecked the table bases, RTTI locator pointers, slot counts, inherited slot values, and constructor/store xrefs from the current IDB. Every listed table has a decorated MSVC vtable symbol at the documented base and a `??_R4...` complete-object locator at `base - 4`.

The dialog classes `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog` all use the same view shape: 23 primary slots, 11 secondary slots, and 2 tertiary slots. Their constructor/store xrefs tie the table groups back to the expected executable owners at `0x00517d30`, `0x00517f30`, `0x005198e0`, `0x0051a520`, `0x0051b880`, `0x0051ca40`, `0x0051db40`, and `0x0051e9a0`.

The list companions `TextMenuItemList`, `ServerItemMenuItemList`, `ClientItemMenuItemList`, `ServerSpellMenuItemList`, `ClientSpellMenuItemList`, and `ArgumentedMenuMenuItemList` all use the larger list-pane shape: 33 primary slots, 11 secondary slots, and 2 tertiary slots. Their constructor/store xrefs tie back to `0x00519520`, `0x0051a520`, `0x0051c470`, `0x0051d700`, `0x0051e640`, `0x0051e9a0`, and `0x0051f290`.

The inherited `MerchantDialogPane` action-string virtual is still present as the secondary-table slot value `0x00517d80` at `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498`. This independently supports the shared-base relationship across text, item, spell, and argumented menu dialogs.

Boundary note: the listed family begins at `0x0061ec10`, immediately after the `MENUBACK.EPF` string area, and the `ArgumentedMenuMenuItemList` tertiary view ends before the next vtable global `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`. Do not extend this page's vtable family into the later argumented-item quantity input dialog tables or the merchant/menu strings in the same broader read-only data aggregate.

## Dialog Tables

These dialog classes share the `MerchantDialogPane` base shape and the inherited action-string virtual at `0x00517d80`. Each class has primary, secondary, and tertiary vtable views.

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Proposed file |
| --- | --- | --- | --- | --- |
| `MerchantDialogPane` | `0x0061ec10` | `0x0061ec70` | `0x0061eca0` | [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) |
| `TextMenuDialog` | `0x0061ecac` | `0x0061ed0c` | `0x0061ed3c` | [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) |
| `TextInputMenuDialog` | `0x0061ee0c` | `0x0061ee6c` | `0x0061ee9c` | [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) |
| `ServerItemMenuDialog` | `0x0061eea8` | `0x0061ef08` | `0x0061ef38` | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) |
| `ClientItemMenuDialog` | `0x0061f008` | `0x0061f068` | `0x0061f098` | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) |
| `ServerSpellMenuDialog` | `0x0061f168` | `0x0061f1c8` | `0x0061f1f8` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) |
| `ClientSpellMenuDialog` | `0x0061f2c8` | `0x0061f328` | `0x0061f358` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) |
| `ArgumentedMenuMenuDialog` | `0x0061f428` | `0x0061f488` | `0x0061f4b8` | [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) |

## List Tables

The list-pane subclasses are private row-list companions for the same dialog family. They also use three vtable views.

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Proposed file |
| --- | --- | --- | --- | --- |
| `TextMenuItemList` | `0x0061ed48` | `0x0061edd0` | `0x0061ee00` | [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) |
| `ServerItemMenuItemList` | `0x0061ef44` | `0x0061efcc` | `0x0061effc` | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) |
| `ClientItemMenuItemList` | `0x0061f0a4` | `0x0061f12c` | `0x0061f15c` | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) |
| `ServerSpellMenuItemList` | `0x0061f204` | `0x0061f28c` | `0x0061f2bc` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) |
| `ClientSpellMenuItemList` | `0x0061f364` | `0x0061f3ec` | `0x0061f41c` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) |
| `ArgumentedMenuMenuItemList` | `0x0061f4c4` | `0x0061f54c` | `0x0061f57c` | [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) |

## Shared Slot Evidence

- The inherited `MerchantDialogPane` virtual at `0x00517d80` has vtable data refs from `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498`.
- Those refs correspond to `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`.
- The dialog vtables therefore support a shared source adjacency decision: this is a merchant/NPC menu-dialog family, not independent one-class files.

## Layout And Boundary Notes

- `0x00517d30` is raw constructor-shaped `MerchantDialogPane` code that IDA does not currently model as a function, while `0x00517d80` is an IDA-modeled vtable-only virtual.
- `ServerItemMenuItemList` has several raw helper-shaped bodies that IDA does not currently model as function starts; the vtables still identify the class family and source placement.
- The destructor/adjustor strip around `0x00520aa5-0x00520e2b` should be used as layout evidence, not as a separate handwritten source module.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for the checked merchant menu dialog/list classes even though IDA exposes complete vtable and RTTI records for every class listed above. This is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Cross-References

- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md)

## Changes

- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:84` and `CONFIDENCE:87` after IDA MCP rechecked the decorated vtable symbols, RTTI locator placement, dialog/list slot counts, constructor/store xrefs, inherited `0x00517d80` slot values, and the read-only-data boundary before `ArgumentedItemQuantityInputDialogPane`. The score remains below the 95+ final-audit gate because final source-file split decisions and complete source declarations for every class/list companion are still open.
