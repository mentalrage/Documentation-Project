*** UID:000320 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Argumented-menu dialog/list vtables and RTTI are compiler-generated from the
// class declarations; do not emit handwritten ABI arrays or wrapper bodies.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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
| `ArgumentedMenuMenuItemList` | `0x0061f4c4`, `0x0061f54c`, `0x0061f57c` | Owner constructor stores at `0x0051eb7f`, `0x0051eb85`, `0x0051eb8f`; copy constructor stores at `0x0051f2b6`, `0x0051f2bc`, `0x0051f2c6`; retained explicit-context constructor [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) stores at `0x0051f35b`, `0x0051f361`, `0x0051f36b`; duplicate destructor glue stores at `0x0051f383`, `0x0051f389`, `0x0051f393`; destructor stores at `0x00520bb6-0x00520bc6`. |

Every listed base has a decorated `??_7...@@6B@` name and a complete-object-locator pointer at `base - 4`. The `ArgumentedMenuMenuDialog` secondary view contains inherited `0x00517d80` at `0x0061f498`.

B002 2026-06-25 source-quality recheck adds the live slot roles for the `ArgumentedMenuMenuDialog` primary table:

| Vtable slot | Target | Source meaning |
| --- | --- | --- |
| `0x0061f470` | [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) `0x0051f160` | `ArgumentedMenuMenuDialog::HandleMenuCommand`; command `1` opens the buy-confirm pane, command `2` sends the shared text-menu request/cancel packet, and command `3` closes. |
| `0x0061f474` | [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) `0x0051f250` | `ArgumentedMenuMenuDialog::UpdateActionButtonState`; enables or disables action control id `1` from list-host control id `6` selection count. |

B002 2026-08-24 source-quality recheck adds the exact tail of the `ArgumentedMenuMenuItemList` primary table:

| Vtable cell | Target | Source meaning |
| --- | --- | --- |
| `0x0061f540` | [UID:0003VM][0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate](by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md) `0x0051f710` | Primary slot index 31 / offset `+0x7c`, `ArgumentedMenuMenuItemList::OnItemActivated`; base `ListPane` dispatcher event case `2` calls this activation slot at `0x004f4284`. The 11-byte override loads `m_ownerDialog` from `+0x158` and tail-forwards to `DialogPane::ActivateFocusedControl`. |
| `0x0061f544` | [UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md) `0x0051f840` | Next and final primary-table slot, `ArgumentedMenuMenuItemList::DrawListEntry`. |

The following cell `0x0061f548` points to the secondary complete-object locator at `0x0064bef0`; the secondary vtable begins at `0x0061f54c`. This boundary prevents the `0x0061f540` activation slot from being folded into a neighboring table. These cells remain compiler-generated results of the source class declaration and must not be emitted as handwritten arrays.

The raw code-shaped island `0x0051f140-0x0051f158` has no vtable slot in the primary table bytes, no function object, and no xrefs to its start. It remains a boundary caveat on [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md), not a vtable-backed source method.

The next named vtable base after this owner-specific set is `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`, so the argumented menu vtable child stops before the separate argumented input-dialog owner.

B002 2026-06-20 support sync narrows the previous "raw/list helper stores" wording: the `0x0051f35b/0x0051f361/0x0051f36b` stores belong to the retained explicit-context constructor overload, while `0x0051f383/0x0051f389/0x0051f393` are the adjacent duplicate destructor-glue stores. Keep the constructor source ownership with [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md), and do not model the duplicate destructor glue as handwritten source.

B005 2026-06-20 destructor-route recheck adds the slot-level map for the `ArgumentedMenuMenuItemList` destructor entries:

| Vtable slot | Target | Source meaning |
| --- | --- | --- |
| `0x0061f4c4` | [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) | Primary scalar deleting destructor wrapper generated from the class destructor. |
| `0x0061f54c` | [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) thunk `0x00520abb` | Secondary `this -= 0xa0` destructor adjustor thunk. |
| `0x0061f57c` | [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) thunk `0x00520ac6` | Tertiary `this -= 0xa4` destructor adjustor thunk. |

These slots should be reproduced by the class inheritance/vtable shape. Do not emit raw vtable data, adjustor thunks, or scalar deleting wrapper bodies as handwritten source.

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

## Score Rationale

Completion is `87` because this owner-specific vtable page now records decorated vtable bases, complete-object-locator placement, constructor/list/destructor store evidence, destructor wrapper slots, the live command/update slot roles for `ArgumentedMenuMenuDialog`, and the exact activation/draw tail of the list primary table. Confidence is `91` because the slot-role evidence is backed by live vtable bytes, xrefs, base dispatch, and method disassembly. It stays below final-audit quality because exact source declarations and original helper/API spellings remain inferred through child pages rather than proven by original symbols.

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-08-24 B002 UID0003VM source-quality support incorporation:
  - Added `0x0061f540 -> 0x0051f710` as `ArgumentedMenuMenuItemList` primary slot index 31 / `+0x7c`, source-facing `OnItemActivated`, with base ListPane activation dispatch at `0x004f4284` and exact owner-forwarding behavior.
  - Recorded `0x0061f544 -> 0x0051f840` as the next/final primary slot and `0x0061f548 -> 0x0064bef0` as the secondary COL boundary before vtable base `0x0061f54c`.
  - Preserved `87/91` and the compiler-generated no-handwritten-vtable disposition.

- 2026-08-17 B010 successor-boundary closure:
  - Preserved this page's exact `ArgumentedMenuDialogs` ownership and non-raw-array disposition.
  - Linked successor [UID:00055A][0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData](by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md) as the separate argumented-input vtable/RTTI child beginning with the COL at `0x0061f584` and first table base at `0x0061f588`.
  - The `ArgumentedMenuMenuItemList` tertiary view remains the last table owned here; no argumented-input table is absorbed into this source family.

- 2026-06-25 B002 source-quality implementation:
  - Changed to: `87/91`.
  - Added `ArgumentedMenuMenuDialog` primary slot roles for `0x0061f470 -> 0x0051f160` / `HandleMenuCommand` and `0x0061f474 -> 0x0051f250` / `UpdateActionButtonState`, plus negative evidence that raw `0x0051f140` has no vtable slot, function object, or xrefs.

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `ArgumentedMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor/list/destructor store xrefs, inherited `0x00517d80`, and the `0x0061f588` successor boundary.
- 2026-06-20 B002 Rule 26 support sync:
  - Split the former raw/list-helper store span into exact retained constructor stores at `0x0051f35b`, `0x0051f361`, `0x0051f36b` and duplicate destructor-glue stores at `0x0051f383`, `0x0051f389`, `0x0051f393`.
  - Evidence: B002 local PE/Capstone recheck of [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) and surrounding padding/glue.
- 2026-06-20 B005 Rule 26 destructor-route incorporation:
  - Added slot-level destructor mapping for `ArgumentedMenuMenuItemList`: primary scalar deleting destructor slot `0x0061f4c4` and secondary/tertiary adjustor slots `0x0061f54c`/`0x0061f57c`.
  - Evidence: B005 local PE/Capstone and pointer-scan recheck of [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) and [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md).
