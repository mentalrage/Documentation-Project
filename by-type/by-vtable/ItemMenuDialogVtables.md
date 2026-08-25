*** UID:00031Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Item Menu Dialog Vtables

## Status

- Entity kind: compiler-generated MSVC vtable/COL evidence index.
- Canonical owner/emitter: `NONE`; [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) owns the four human class declarations that regenerate this evidence.
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

Every listed base has a decorated `??_7...@@6B@` name and a complete-object-locator pointer at `base - 4`. The server and client dialog secondary views contain inherited `0x00517d80` slots at `0x0061ef18` and `0x0061f078`. That row is inherited `MerchantDialogPaneActionStringVirtual` glue and is not command 2; both item-dialog command-2 paths call base-owned `MerchantDialogPane::SendMenuRequestPacket` UID0004H8 at `0x00517ec0`.

### ServerItemMenuItemList Destructor First Entries

| Vtable view | Complete-object locator | First entry | Exact route and source disposition |
| --- | --- | --- | --- |
| Primary `0x0061ef44` | `0x0064ba2c` | `0x00520ce0` | Directly enters [UID:0001C2][0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor](by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md). UID0001C2 is class-owned reconstructable ABI evidence but its formal output is covered by ordinary destructor source UID0001BP. |
| Secondary `0x0061efcc` | `0x0064ba90` | `0x00520b13` | [UID:0001BZ][0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks](by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md) subtracts `0xa0` from adjusted `this`, then tail-jumps to UID0001C2. Compiler-only; no handwritten method. |
| Tertiary `0x0061effc` | `0x0064baa4` | `0x00520b1e` | UID0001BZ subtracts `0xa4` from adjusted `this`, then tail-jumps to UID0001C2. Compiler-only; no handwritten method. |

Current healthy MCP session `7be8cc9f` reconfirms these exact entries and decorated names `??_7ServerItemMenuItemList@@6B@`, `_0`, and `_1`. The three routes regenerate from ordinary `ServerItemMenuItemList::~ServerItemMenuItemList()` source in [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) plus the class's multiple-vtable layout. Do not emit raw vtable data, scalar delete flags, or adjusted-`this` thunk bodies as source.

## Ownership Inference

The item-menu vtable subfamily is exact compiler evidence for [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), but has no semantic source owner itself. Constructor and inline list stores are inside the exact ItemMenuDialogs children; class H declarations, not this page, carry source ownership.

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | source-cause relationship only | Direct owner for the four class declarations; not canonical owner/emitter of this compiler-only page. |
| Individual item class pages | rejected for this grouped page | All four exact class pages are currently `94/94`, but each owns one human class declaration rather than this grouped compiler-only evidence page. |
| [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | rejected | Supplies inherited dialog-base virtual only. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory across unrelated source owners. |

## Reconstruction Notes

Reconstruct these vtables through the item-menu class declarations and list-pane companion declarations. Do not emit raw vtable data as source.

Historical / superseded gate rationale: an earlier snapshot said some exact class pages remained below `85/85` and used that score state to reject them as owners of this grouped page. The score observation lost authority after all four class pages reached `94/94`. The rejection itself remains correct for the current, different reason recorded above: UID00031Z is a no-owner/non-emitting compiler-evidence index, while the four class pages own the human declarations that cause the compiler artifacts.

B002's 2026-06-19/20 split repair keeps this page as the dedicated item-menu vtable anchor for [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). The broad executable range [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) is now a non-emitting split index; source C++ is emitted by exact child pages [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md), [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md), [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md), and [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md). [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) remains mixed-family context, not the direct item-menu anchor.

Destructor slot detail for `ClientItemMenuItemList`: primary vtable base `0x0061f0a4` routes to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), secondary base `0x0061f12c` routes to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`), and tertiary base `0x0061f15c` routes to thunk `0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`). This is shared compiler-generated destructor glue, not an item-menu handwritten source function.

For `ServerItemMenuItemList`, ordinary source responsibility is narrower and exact: UID0001BP contains the 53-byte source-visible destructor at `[0x0051af00,0x0051af35)`, while UID0001C2 and UID0001BZ are regenerated class-specific scalar/adjustor entries. UID0001C2's formal covered-by comment prevents an empty emitter without duplicating the ordinary method.

## 2026-08-22 UID0000KF Compiler-Only Disposition

This page is a `94/96` no-owner, false/non-emitting evidence index. Its twelve decorated primary/secondary/tertiary vtable views and adjacent COL cells cover exactly `ServerItemMenuDialog`, `ServerItemMenuItemList`, `ClientItemMenuDialog`, and `ClientItemMenuItemList`. The four accepted H declarations and ordinary virtual/destructor definitions are the sole human source causes; MSVC regenerates vtables, RTTI/COLs, adjustor thunks, and scalar deleting wrappers. Both formal channels remain blank and no raw table or compiler wrapper is emitted through UID0000KF.

The existing twelve literal protected identities, ranges, bytes, hashes, comments, types, and xrefs remain unchanged for supervisor Gate 2B. This ordinary callback changes only documentation metadata/source disposition and does not mutate or reinterpret any protected IDA item.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md)
- [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `ItemMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor/list/destructor store xrefs, and inherited dialog-base slots for the two dialog classes.
- 2026-06-20 B001 Rule 26 source-quality sync: score unchanged. Added the exact `ClientItemMenuItemList` destructor slot route through [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) and the [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) secondary/tertiary adjustors.
- 2026-06-20 B002 Rule 26 split incorporation: score unchanged. Added the accepted split-index routing for [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md), direct source-bearing children [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md)/[UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md), and clarified that this page is the direct item-menu vtable anchor while [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) is broader mixed-family context.
- 2026-06-21 B013 `ClientItemMenuDialog` source-quality sync: score unchanged. Clarified that the client inherited `0x0061f078 -> 0x00517d80` slot is not command id `2`; the action handler's command id `2` path calls [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md) `TextMenuDialog::SendMenuRequestPacket`.
- 2026-07-23 B001 UID0001C2 support synchronization: score/owner/emitter/formal state unchanged at `88/92` through UID0000KF. Added exact `ServerItemMenuItemList` primary `0x0061ef44 -> 0x00520ce0`, secondary `0x0061efcc -> 0x00520b13 -> 0x00520ce0`, and tertiary `0x0061effc -> 0x00520b1e -> 0x00520ce0` routes, complete-object-locator cells, and ordinary-source/covered-by/compiler-regeneration disposition.
