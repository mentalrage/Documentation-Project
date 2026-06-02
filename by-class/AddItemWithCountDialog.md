*** UID:000008 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddItemWithCountDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_AddItemWithCountDialog.cpp`
- Rebuild handling: source-authored item-dialog class; C++ remains blank until constructor parameters, count field names, and inherited dialog slots are final-source quality.

## Class Purpose

`AddItemWithCountDialog` is the quantity-aware item add dialog. It is used when an item action must collect a count before dispatching the selected item operation.

## Class Shape

- Base relationship: item-dialog family sibling/variant of [UID:000007][AddItemDialog](by-class/AddItemDialog.md).
- Vtable family: primary/secondary/tertiary tables at `0x00619fec`, `0x0061a04c`, and `0x0061a07c`.
- Role split: this class owns the item-specific count dispatch path; generic numeric input behavior should remain with the reusable numeric/dialog input classes.
- Source placement: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Ownership And Boundary Evidence

| Evidence | Meaning |
| --- | --- |
| [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) lists `AddItemWithCountDialog` in the reusable item-picker/mix source cluster. | The class belongs with generic item dialog source, not with the exchange session window or inventory rendering. |
| [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md) covers `0x004af040-0x004af4b6` as the quantity-aware add-item dialog range. | The class body is physically inside the reviewed item exchange/mix dialog island. |
| [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) records constructor stores for the three dialog vfptr views. | The class is a concrete dialog variant using the same three-view layout as `AddItemDialog`, `MixItemDialog`, and `AddMixingItemDialog`. |
| [UID:00014M][0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper.md) constructs this dialog from exchange packet data. | Exchange is a caller/consumer; it should not own the picker implementation. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddItemWithCountDialog` | `0x004af040-0x004af370` | Builds quantity-aware item-add dialog for a selected item ID/type. |
| `OnDialogAction` | `0x004af380-0x004af479` | Handles dialog action IDs such as confirm/cancel. |
| `DispatchSelectionAction` | `0x004af480-0x004af4b6` | Dispatches the selected item/count action. |

## Reconstruction Notes

- Treat this as a reusable `ItemDialogs` picker variant. The exchange packet helper passes data into it, but the class implementation stays with item-dialog UI.
- Do not fold it into [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md); this class owns item-specific selection/count dispatch, while number-entry behavior remains a reusable dialog dependency.
- The current evidence supports future reconstruction, but not final emitted C++. The parameter names, inherited slot names, and item/count field layout still need method-level confirmation.

## Evidence Notes

- Wave3 notes identify this as an item-add dialog with a specified quantity.
- IDA MCP confirms all three methods as function starts.
- IDA MCP vtable checks confirm table bases at `0x00619fec`, `0x0061a04c`, and `0x0061a07c`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- The class belongs with exchange/mix item dialogs rather than generic numeric input panes because it owns the item-specific dispatch.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:00014M][0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)

## Changes

- What existed before: the page was documented but still scored as unevaluated.
- What it was changed to: scores were set to `66/84`, and a short class-shape section now records vtable anchors, family relationship, role split, and source placement.
- Summary and evidence: IDA MCP confirms the three method starts and vtable bases, but the page still needs deeper field/parameter naming and full method-level cross-links before completion should be high.
- 2026-06-02: Raised from `66/84` to `72/86` after adding ownership/boundary and reconstruction notes.
  - Added evidence tying the class to `ItemDialogs`, the exact `ItemExchangeMixDialogs` range, the item-dialog vtable family, and the exchange helper that constructs it.
  - Kept reconstruction C++ blank because source-quality parameter names, inherited slot names, and count/item field layout are still open.
