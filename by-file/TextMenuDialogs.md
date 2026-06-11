*** UID:0000OP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextMenuDialogs

## Status

- Confidence: strong for the text-menu classes as a source owner; argumented-menu classes are now treated as the separate [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) owner bucket, with only final physical file folding still provisional.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `ui/dialogs/TextMenuDialogs.cpp`; adjacent but separately owned candidates are [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) and [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- Current generated sources: `class_MerchantDialogPane.cpp`, `class_TextMenuDialog.cpp`, `class_TextInputMenuDialog.cpp`, `class_TextMenuItemList.cpp`, `class_ArgumentedMenuMenuDialog.cpp`, and `class_ArgumentedMenuMenuItemList.cpp`
- Evidence basis: Wave3 class metadata, generated `simroot_v2` source, and targeted IDA MCP checks on 2026-05-23 and 2026-05-26.
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Hypothesis

The original client likely kept server-driven NPC/merchant menu dialogs near each other, rather than as five one-class files. `TextMenuDialog`, `TextInputMenuDialog`, and `TextMenuItemList` share the merchant/NPC packet-dialog shape, response opcode `0x39`, [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)/`DialogPane` control setup, and `DLGMERC1`/`DLGMERC2` asset family.

`ArgumentedMenuMenuDialog` and `ArgumentedMenuMenuItemList` are the item-argument variant of the same feature area. They parse item entries with quantity, argument id, price, percent metadata, item image data, and display a `DLGMERC3.EPF` dialog. Their buy/confirm action opens `ArgumentedItemConfirmInputDialogPane` at `0x005200d0`, now covered by [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), so the final split may be:

```text
ui/dialogs/MerchantDialogPane.cpp
ui/dialogs/TextMenuDialogs.cpp
ui/dialogs/ArgumentedMenuDialogs.cpp
ui/dialogs/ArgumentedItemInputDialogs.cpp
```

A compact late-1999/early-2000s project could also have kept the argumented classes in the same text-menu dialog source file.

IDA confirms the dialog/list vtable family from `0x0061ec10` through `0x0061f57c`. Current generated metadata reports `vtable_count: 0` for the checked menu-dialog classes, so do not use generated vtable absence as source-layout evidence.

B001-008 ownership split: use this file as the direct owner for `TextMenuDialog`, `TextMenuItemList`, and `TextInputMenuDialog`. Keep `ArgumentedMenuMenuDialog` and `ArgumentedMenuMenuItemList` with [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) for assignment and coverage, while preserving this page's historical note that a final source migration could physically fold the argumented code into a broader text/menu dialog source.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `MerchantDialogPane` | `0x00517d30-0x00517ebf` | `class_MerchantDialogPane.cpp` plus omitted shared virtual | Shared `DialogPane` base and action-string virtual used by text, item, spell, and argumented merchant menu dialogs. |
| `MenuDialogFactoryHelpers` | [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) | omitted/dispatcher helper code | Packet subtype dispatcher and one-variant wrappers that allocate text, item, spell, and argumented menu dialogs. |
| `TextMenuDialog` | `0x00517ec0-0x00519510`, destructor island `0x00520b3f-0x00520de7` | `class_TextMenuDialog.cpp` | Server-driven NPC/merchant text menu dialog; parses menu packets, builds simple or scrollable layouts, and sends opcode `0x39` selection replies. |
| `TextMenuItemList` | `0x00519520-0x005198d0`, destructor island `0x00520b55-0x00520e2a` | `class_TextMenuItemList.cpp` | Private list pane for scrollable text-menu rows. |
| `TextInputMenuDialog` | `0x005198e0-0x0051a416`, destructor island `0x00520b29-0x00520d97` | `class_TextInputMenuDialog.cpp` | Merchant/NPC dialog that includes a text input control and submits entered text with opcode `0x39`. |
| [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) | `0x0051a420-0x0051a51c` | omitted raw helper | Raw text-input reply serializer for opcode `0x39`; likely belongs with `TextInputMenuDialog`. |
| [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) | `0x0051e9a0-0x0051fc8c`, destructor island `0x00520abb-0x00520c16` | separate owner bucket | Adjacent argumented menu dialog/list family; related to text menus but not assigned to this file under the current split. |
| [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) | `0x0051fc90-0x00520538` | separate owner bucket | Adjacent quantity/confirm input dialog flow; documented separately. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `MerchantDialogPane`: raw constructor-shaped code at `0x00517d30-0x00517d71` and IDA-modeled [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md); the virtual is referenced from merchant/text/item/spell/argumented-menu vtables.
- `MenuDialogFactoryHelpers`: [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) maps subtype bytes to `TextMenuDialog`, `TextInputMenuDialog`, item-menu, spell-menu, and argumented-menu constructors before the concrete class islands.
- `TextMenuDialog`: `0x00517ec0`, `0x00517f30`, `0x00518e20`, `0x00519210`, `0x005194c0`, thunks `0x00520b3f`/`0x00520b4a`, and destructor `0x00520da0`.
- `TextInputMenuDialog`: `0x005198e0`, `0x0051a280`, `0x0051a3e0`, thunks `0x00520b29`/`0x00520b34`, and destructor `0x00520d50`.
- `TextInputMenuDialogReplyPacketHelper`: [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) is raw code with no IDA function object, but it serializes the text-input opcode `0x39` reply shape.
- `TextMenuItemList`: `0x00519520`, `0x00519590`, `0x00519840`, `0x00519850`, thunks `0x00520b55`/`0x00520b60`, and destructor `0x00520df0`.
- `ArgumentedMenuMenuDialog`: `0x0051e9a0`, `0x0051f160`, and `0x0051f250`.
- `ArgumentedMenuMenuItemList`: `0x0051f290`, `0x0051f5b0`, `0x0051f710`, `0x0051f720`, `0x0051f840`, thunks `0x00520abb`/`0x00520ac6`, and destructor `0x00520bb0`.
- IDA reports no function at Wave3's listed `ArgumentedMenuMenuItemList` method `0x0051f310`; this is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Ownership Notes

- Keep these classes under `ui/dialogs/`, not `ui/menu/`. They are modal packet-driven dialogs, while `ui/menu/` currently covers reusable popup menu controls and right-click/menu-button panes.
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) is a shared base for text, item, spell, and argumented menu dialogs. Keep it adjacent to these modules even if final migration folds the tiny base into a broader menu-dialog source.
- The `TextMenuDialog::SendMenuRequestPacket` helper is reused by `TextInputMenuDialog` and `ArgumentedMenuMenuDialog` cancel paths, so it should remain in the same dialog-family source module.
- `TextMenuItemList` and `ArgumentedMenuMenuItemList` should migrate with their owning dialogs. Their constructors are only meaningful with owner/context fields passed by the dialog constructors.
- `ArgumentedItemConfirmInputDialogPane`, `ArgumentedItemQuantityInputDialogPane`, and their purchase helpers are documented in [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md). They should stay adjacent to this module, but their final source file may be a split `ArgumentedItemInputDialogs.cpp`.

## Migration Notes

Proposed dry-run sequence after class docs are reviewed:

```powershell
python source-3\wave3.py rename file class_TextMenuDialog.cpp TextMenuDialogs.cpp --dry-run
python source-3\wave3.py set file-simpath TextMenuDialogs.cpp ui/dialogs/TextMenuDialogs.cpp --dry-run
python source-3\wave3.py attach class TextMenuItemList --file TextMenuDialogs.cpp --dry-run
python source-3\wave3.py attach class TextInputMenuDialog --file TextMenuDialogs.cpp --dry-run
python source-3\wave3.py attach class ArgumentedMenuMenuDialog --file TextMenuDialogs.cpp --dry-run
python source-3\wave3.py attach class ArgumentedMenuMenuItemList --file TextMenuDialogs.cpp --dry-run
```

If the argumented-menu split is preferred, attach the two `Argumented*` classes to `ArgumentedMenuDialogs.cpp` instead. Do not run these migrations until the `0x0051f310` non-function method entry and omitted thunk/source-body caveats are resolved or explicitly marked.

## Cross-References

- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `90` and confidence to `82`.
  - Evidence: document covers dialog-family hypothesis, proposed contents, factory helpers, text/input/argumented menu classes, IDA/vtable evidence, ownership notes, migration caveats, split alternatives, and cross-references; confidence is capped by final argumented-menu split and unresolved generated method caveats.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` so reviewed child memory pages can attach to this parent without autogen path errors.
- 2026-06-10 B001-008 ownership-gate refresh:
  - Changed confidence to `86`.
  - Summary/evidence: live IDA MCP reconfirmed text-menu vtable views and constructor stores for `TextMenuDialog`, `TextMenuItemList`, and `TextInputMenuDialog`; the new split child [TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md) is assigned here. Argumented-menu classes are now explicitly routed to [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), so the previous confidence cap from argumented split ambiguity no longer blocks this text-menu owner bucket.
