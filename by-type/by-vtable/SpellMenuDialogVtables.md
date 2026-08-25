*** UID:00031X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Spell Menu Dialog Vtables

## Status

- Entity kind: compiler-generated MSVC vtable/COL evidence index.
- Canonical owner/emitter: `NONE`; this page is false/non-emitting because no source-authored table or wrapper belongs in generated C++.
- Source cause: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) owns the four class declarations and ordinary methods that regenerate this evidence.
- Covered classes: `ServerSpellMenuDialog`, `ServerSpellMenuItemList`, `ClientSpellMenuDialog`, and `ClientSpellMenuItemList`.
- Exact source children: [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md), [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md), [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md), and [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md).
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- Score unchanged by the B001 2026-06-23 implementation; this page already had strong owner-specific vtable evidence and now links to the exact source children.

## Binary Evidence

| Class | Vtable bases | Store/xref evidence | Exact source child |
| --- | --- | --- | --- |
| `ServerSpellMenuDialog` | `0x0061f168`, `0x0061f1c8`, `0x0061f1f8` | Constructor `0x0051ca40` stores the spell dialog vptrs; command/update method slots reference `0x0051d520` and `0x0051d6c0`. | [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) |
| `ServerSpellMenuItemList` | `0x0061f204`, `0x0061f28c`, `0x0061f2bc` | Constructor `0x0051d700` stores the list vptrs; activation/draw slots reference `0x0051da20` and `0x0051da30`. | [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md) |
| `ClientSpellMenuDialog` | `0x0061f2c8`, `0x0061f328`, `0x0061f358` | Constructor `0x0051db40` stores the spell dialog vptrs; command/update method slots reference `0x0051e4e0` and `0x0051e600`. | [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) |
| `ClientSpellMenuItemList` | `0x0061f364`, `0x0061f3ec`, `0x0061f41c` | Constructor `0x0051e640` stores the list vptrs; activation/draw slots reference `0x0051e880` and `0x0051e890`. | [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md) |

Every listed base has a decorated `??_7...@@6B@` name and a complete-object-locator pointer at `base - 4`. The server and client dialog secondary views contain inherited `0x00517d80` slots at `0x0061f1d8` and `0x0061f338`.

## Ownership Inference

The spell-menu vtable subfamily is compiler evidence caused by the four classes in [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), not a separately source-authored entity. The constructor stores are inside the exact spell-menu method/list children, the broad [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md) range is now only a non-emitting split index, and no chat, item, text, or argumented owner has stronger source-cause evidence for these four tables. UID00031X itself has no canonical owner or emitter.

## Reconstruction Notes

Reconstruct these vtables through the spell-menu class declarations and list-pane companion declarations. Do not emit raw vtable data as source from this page. Both formal channels remain blank and UID00031X is false/non-emitting; the class/method pages alone supply human source.

Destructor slot detail for the spell menu item-list classes remains compiler glue: `ServerSpellMenuItemList` primary base `0x0061f204` and `ClientSpellMenuItemList` primary base `0x0061f364` route to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md). The secondary bases `0x0061f28c` and `0x0061f3ec` route to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1`, and the tertiary bases `0x0061f2bc` and `0x0061f41c` route to thunk `0x00520adc`. Do not duplicate this compiler glue in `SpellMenuDialogs.cpp`; reconstruct ordinary class declarations/destructors and the shared `ListPane` base cleanup.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md)
- [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md)
- [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md)
- [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- 2026-08-22 B002 UID0000OP Gate 2A empty-emitter closure:
  - Corrected UID00031X from file-routed reconstructable/empty CPP to `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
  - Preserved all twelve vtable/COL/store identities and exact destructor-glue exclusions; the four spell classes remain the sole human source causes.
- 2026-06-23 B001 accepted implementation: no score or metadata change. Added links to exact child pages [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md), [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md), [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md), and [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md), kept owner-specific [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) vtable evidence, and preserved the destructor-glue exclusion.
