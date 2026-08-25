*** UID:00031Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-covered by TextMenuDialog, TextMenuItemList,
// TextInputMenuDialog, and MerchantDialogCreator source declarations.
// No raw vtable, COL, RTTI, thunk, or deleting-destructor arrays are authored.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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

## Destructor Slot Detail

`TextMenuDialog` primary vtable `0x0061ecac` starts with scalar deleting destructor [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md); secondary vtable `0x0061ed0c` starts with adjustor thunk `0x00520b3f`; tertiary vtable `0x0061ed3c` starts with adjustor thunk `0x00520b4a`. The constructor stores at `0x00517fa0`, `0x00517fa6`, and `0x00517fb0` materialize the three views at complete-object offsets `0`, `0xa0`, and `0xa4`. The secondary/tertiary first slots are not source-visible methods; they are MSVC-generated destructor adjustors regenerated from the ordinary `TextMenuDialog` destructor and inherited `EventHandler`/`TimerHandler` layout.

`TextInputMenuDialog` primary vtable `0x0061ee0c` starts with the scalar deleting destructor `0x00520d50`; secondary vtable `0x0061ee6c` starts with adjustor thunk `0x00520b29`; tertiary vtable `0x0061ee9c` starts with adjustor thunk `0x00520b34`. The constructor stores at `0x00519950`, `0x00519956`, and `0x00519960` materialize the three views at complete-object offsets `0`, `0xa0`, and `0xa4`. The secondary/tertiary first slots are not source-visible methods; they are MSVC-generated destructor adjustors regenerated from the ordinary `TextInputMenuDialog` destructor and inherited `EventHandler`/`TimerHandler` layout.

`TextMenuItemList` primary vtable `0x0061ed48` starts with scalar deleting destructor [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md); secondary vtable `0x0061edd0` starts with [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) function `0x00520b55`; tertiary vtable `0x0061ee00` starts with [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) function `0x00520b60`. The constructor stores at `0x00519560`, `0x00519566`, and `0x00519570` materialize the three views. B010 source-routing review keeps the current [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) filename but records actual half-open byte coverage `0x00520b55-0x00520b6b`; the strongest inherited-layout inference is secondary `this - 0xa0` and tertiary `this - 0xa4` before forwarding to `0x00520df0`. These first slots are compiler output regenerated from the ordinary `TextMenuItemList` destructor and list-pane inherited layout.

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

## B002 UID0000OP Accepted Whole-File Reconciliation

| Inventory | Class view | Vtable | Constructor store | Destructor route |
| --- | --- | --- | --- | --- |
| I039 | `TextMenuDialog` primary | `0x0061ecac` | `0x00517fa0` | scalar wrapper `0x00520da0` |
| I040 | `TextMenuDialog` secondary | `0x0061ed0c` | `0x00517fa6` | adjustor `0x00520b3f` |
| I041 | `TextMenuDialog` tertiary | `0x0061ed3c` | `0x00517fb0` | adjustor `0x00520b4a` |
| I042 | `TextMenuItemList` primary | `0x0061ed48` | `0x00519560` | scalar wrapper `0x00520df0` |
| I043 | `TextMenuItemList` secondary | `0x0061edd0` | `0x00519566` | adjustor `0x00520b55` |
| I044 | `TextMenuItemList` tertiary | `0x0061ee00` | `0x00519570` | adjustor `0x00520b60` |
| I045 | `TextInputMenuDialog` primary | `0x0061ee0c` | `0x00519950` | scalar wrapper `0x00520d50` |
| I046 | `TextInputMenuDialog` secondary | `0x0061ee6c` | `0x00519956` | adjustor `0x00520b29` |
| I047 | `TextInputMenuDialog` tertiary | `0x0061ee9c` | `0x00519960` | adjustor `0x00520b34` |

The accepted inherited source-slot identities are `OnControlCommand` and `UpdateActionButton` for the dialog views, and `OnItemActivated` and `DrawListEntry` for the list view. The two dialog secondary views retain the inherited `MerchantDialogPane::SendMenuRequestPacket` context through the shared base declaration; no derived class authors a duplicate request method or dialog-id field. These nine views, their COL/RTTI records, and all destructor entries are compiler-covered by the ordinary class declarations and destructors. The formal C++ marker above records that disposition without hand-authoring ABI arrays.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-08-21 B002 UID0000OP accepted whole-file callback:
  - Raised `87/91` to `93/94`, added the exact nine-view inventory with constructor stores and destructor routes, reconciled inherited source-slot identities, and emitted the accepted compiler-covered marker while keeping H blank.
- 2026-06-10 B001-008 split:
  - Created as the owner-specific `TextMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor store sites, and inherited `0x00517d80` dialog-base slots for the two dialog classes.
- 2026-06-21 Rule 26 incorporation:
  - Score unchanged at `87/91`.
  - Added the TextInputMenuDialog destructor first-slot mapping for `0x0061ee0c`, `0x0061ee6c`, and `0x0061ee9c`, plus the constructor-store and generated-adjustor source policy from B007.
- 2026-06-21 B008 Rule 26 source-routing sync:
  - Score unchanged at `87/91`.
  - Added the TextMenuDialog destructor first-slot mapping for `0x0061ecac`, `0x0061ed0c`, and `0x0061ed3c`, plus constructor-store offsets and generated-adjustor source policy from the B008 local PE/Capstone report.
- 2026-06-21 B010 Rule 26 source-routing sync:
  - Score unchanged at `87/91`.
  - Added the TextMenuItemList destructor first-slot mapping for `0x0061ed48`, `0x0061edd0`, and `0x0061ee00`, plus constructor-store offsets, [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) half-open endpoint caveat, inherited-layout adjustor inference, and generated-adjustor source policy.
