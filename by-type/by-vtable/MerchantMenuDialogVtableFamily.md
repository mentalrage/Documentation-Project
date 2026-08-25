*** UID:0001Y5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Merchant Menu Dialog Vtable Family

## Status

- Disposition: reviewed non-emitting vtable-family index. Exact owner-specific children carry the reconstructable merchant/NPC menu dialog vtable declarations.
- Covered source owners: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md), [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), and [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).
- Current classification: `reviewed-non-emitting-ownership-split`; this mixed family intentionally keeps `AUTOGEN_PARENT_UID` blank while exact owner-specific child pages route to direct file owners.
- Confidence: strong for table bases, RTTI presence, constructor/store refs, source-owner split, and the successor boundary before argumented-item input dialogs.
- Verification: IDA MCP `list_globals`/`py_eval` checks on 2026-05-26, 2026-06-01, 2026-06-08, and 2026-06-10, plus A004 live IDA MCP `entity_query`, `lookup_funcs`, `trace_data_flow`, and `make_signature_for_range` checks on 2026-06-12 against session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Current `simroot_v2` metadata reports `vtable_count: 0` for every checked class in this family, so IDA evidence and by-* docs are the controlling evidence.

## Current IDA Recheck

IDA MCP `py_eval` on 2026-06-01 rechecked the table bases, RTTI locator pointers, slot counts, inherited slot values, and constructor/store xrefs from the current IDB. Every listed table has a decorated MSVC vtable symbol at the documented base and a `??_R4...` complete-object locator at `base - 4`.

The dialog classes `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog` all use the same view shape: 23 primary slots, 11 secondary slots, and 2 tertiary slots. Their constructor/store xrefs tie the table groups back to the expected executable owners at `0x00517d30`, `0x00517f30`, `0x005198e0`, `0x0051a520`, `0x0051b880`, `0x0051ca40`, `0x0051db40`, and `0x0051e9a0`.

The list companions `TextMenuItemList`, `ServerItemMenuItemList`, `ClientItemMenuItemList`, `ServerSpellMenuItemList`, `ClientSpellMenuItemList`, and `ArgumentedMenuMenuItemList` all use the larger list-pane shape: 33 primary slots, 11 secondary slots, and 2 tertiary slots. Their constructor/store xrefs tie back to `0x00519520`, `0x0051a520`, `0x0051c470`, `0x0051d700`, `0x0051e640`, `0x0051e9a0`, and `0x0051f290`.

The inherited `MerchantDialogPane` action-string virtual is still present as the secondary-table slot value `0x00517d80` at `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498`. This independently supports the shared-base relationship across text, item, spell, and argumented menu dialogs.

Boundary note: the listed family begins at `0x0061ec10`, immediately after the `MENUBACK.EPF` string area, and the `ArgumentedMenuMenuItemList` tertiary view ends before the next vtable global `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`. Do not extend this page's vtable family into the later argumented-item quantity input dialog tables or the merchant/menu strings in the same broader read-only data aggregate.

2026-06-08 A009 Batch 125 live IDA MCP `py_eval` rechecked all 42 menu-family table bases from `0x0061ec10` through `0x0061f57c`. Each base still has a decorated `??_7...@@6B@` symbol, a complete-object-locator pointer at `base - 4`, and constructor/store refs matching its executable family. The inherited action-string slots at `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498` all still contain `0x00517d80`. The same recheck reconfirmed first bytes `70 0b 52 00 10 4b 4f 00 c0 b6 41 00 20 8e 4b 00`, the next vtable after the menu family as `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`, and the broader read-only successor `??_7Message@@6B@` at `0x0061fa3c`.

2026-06-10 B001 live IDA MCP `py_eval` against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` rechecked the same 42 bases and grouped them by direct source owner. The evidence supports five owner-specific child pages rather than one broad parent: the three `MerchantDialogPane` bases store from raw constructor-shaped code at `0x00517d53`, `0x00517d59`, and `0x00517d63`; the text-menu bases store from `0x00517f30`, `0x00519520`, and `0x005198e0` families; item-menu bases store from `0x0051a520`, `0x0051b880`, and `0x0051c470` families; spell-menu bases store from `0x0051ca40`, `0x0051d700`, `0x0051db40`, and `0x0051e640` families; argumented-menu bases store from `0x0051e9a0`, `0x0051f290`, raw list stores near `0x0051f35b-0x0051f393`, and destructor stores near `0x00520bb6-0x00520bc6`. The next named vtable remains `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`, outside this family.

2026-06-12 A004 live IDA MCP split refresh used session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` and reconfirmed the non-emitting master decision:

- `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
- `entity_query 0x0061ec00-0x0061f5a0` reports exactly 42 merchant/text/item/spell/argumented menu vtable names from `??_7MerchantDialogPane@@6B@` at `0x0061ec10` through `??_7ArgumentedMenuMenuItemList@@6B@_1` at `0x0061f57c`, followed by successor `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0061f588`.
- `lookup_funcs` reconfirmed the direct owner neighborhoods: raw `0x00517d30` is not an IDA function, shared virtual `0x00517d80` is a `0x13f`-byte function, text-menu constructors/helpers at `0x00517f30`, `0x00519520`, and `0x005198e0`, item-menu families at `0x0051a520`, `0x0051b880`, and `0x0051c470`, spell-menu families at `0x0051ca40`, `0x0051d700`, `0x0051db40`, and `0x0051e640`, argumented-menu families at `0x0051e9a0`, `0x0051f290`, and destructor support at `0x00520bb0`.
- `trace_data_flow backward` reconfirmed representative primary vptr stores for every owner group and the successor at `0x0061f588`: `MerchantDialogPane` raw store at `0x00517d53`, text-menu stores at `0x00517fa0`, `0x00519560`, and `0x00519950`, item-menu stores at `0x0051a596`, `0x0051a6ff`, `0x0051b8e9`, and `0x0051c4bb`, spell-menu stores at `0x0051caaf`, `0x0051d74b`, `0x0051dba9`, and `0x0051e68b`, and argumented-menu stores at `0x0051ea16` and `0x0051eb7f`.
- `make_signature_for_range` returned unique signatures for the main owner strips `0x0061ec0c-0x0061eea8`, `0x0061eea8-0x0061f168`, `0x0061f168-0x0061f428`, and `0x0061f428-0x0061f588`.
- `int_convert.py` verified `0xa0` as 160, `0xa4` as 164, `0x60` as 96, `0x88` as 136, `0x30` as 48, and `0x0c` as 12 for the repeated base offsets and table spans.

## B001-008 Split Result

This page is not assigned to one parent because the binary evidence shows five direct source owners. The exact child pages below now carry the source-owner assignments. The master page is therefore a non-emitting index, not a separate source artifact to reconstruct.

2026-06-23 B001 spell-menu implementation note: [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md) is the direct spell-menu vtable anchor for [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md). This mixed-family page remains context only for that range; the exact spell source-bearing children are [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md), [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md), [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md), and [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md).

| Child page | Covered vtables | Direct owner | Score | Basis |
| --- | --- | --- | --- | --- |
| [UID:00031W][MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md) | `0x0061ec10`, `0x0061ec70`, `0x0061eca0` | [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | `86/90` | Constructor-shaped stores at `0x00517d53`, `0x00517d59`, `0x00517d63`; shared virtual `0x00517d80`. |
| [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md) | `TextMenuDialog`, `TextMenuItemList`, `TextInputMenuDialog` tables from `0x0061ecac-0x0061ee9c` | [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) | `87/91` | Store refs in the text-menu executable families at `0x00517f30`, `0x00519520`, and `0x005198e0`. |
| [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md) | Server/client item dialog and item-list tables from `0x0061eea8-0x0061f15c` | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | `88/92` | Store refs in item-menu constructor/list/destructor families at `0x0051a520`, `0x0051b880`, `0x0051c470`, and related raw/destructor stores. |
| [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md) | Server/client spell dialog and spell-list tables from `0x0061f168-0x0061f41c` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) | `88/92` | Store refs in spell-menu constructor/list families at `0x0051ca40`, `0x0051d700`, `0x0051db40`, and `0x0051e640`. |
| [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md) | `ArgumentedMenuMenuDialog` and `ArgumentedMenuMenuItemList` tables from `0x0061f428-0x0061f57c` | [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) | `86/90` | Store refs in argumented-menu dialog/list/destructor families and successor boundary at `0x0061f588`. |

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
- Default destructor split: [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) is the primary scalar deleting destructor slot for `MerchantDialogPane`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`; their secondary/tertiary destructor slots route through [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md). Adjacent `TextMenuDialog`/`TextInputMenuDialog` are part of this vtable family but are not included in this exact `0x00520b70` primary-slot consumer set in the local export search.
- TextInputMenuDialog destructor split: primary vtable `0x0061ee0c` starts with [UID:00037D][0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor](by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md), while secondary `0x0061ee6c` and tertiary `0x0061ee9c` start with [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md) adjustors. These first slots are compiler output regenerated from `TextInputMenuDialog::~TextInputMenuDialog()` and inherited subobject offsets `0xa0`/`0xa4`.
- TextMenuItemList destructor split: primary vtable `0x0061ed48` starts with [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md), while secondary `0x0061edd0` and tertiary `0x0061ee00` start with [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) adjustors. B010 records the actual [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) half-open byte coverage as `0x00520b55-0x00520b6b`; these first slots are compiler output regenerated from `TextMenuItemList::~TextMenuItemList()` and the list-pane inherited subobject layout, with best current secondary/tertiary offset inference `0xa0`/`0xa4`.

## Layout And Boundary Notes

- `0x00517d30` is raw constructor-shaped `MerchantDialogPane` code that IDA does not currently model as a function, while `0x00517d80` is an IDA-modeled vtable-only virtual.
- `ServerItemMenuItemList` has several raw helper-shaped bodies that IDA does not currently model as function starts; the vtables still identify the class family and source placement.
- The destructor/adjustor strip around `0x00520aa5-0x00520e2b` should be used as layout evidence, not as a separate handwritten source module.

## Assignment Gate

Assignment decision after A004 Batch 330: `reviewed-non-emitting-ownership-split`. The vtable-family page clears the evidence gate (`90/93`), but it intentionally spans five direct source owners instead of one actual parent. The owner-specific child pages now carry the assignments, and all selected file parents meet the corrected gate: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) (`85/86`), [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) (`90/86`), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) (`86/85`), [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) (`88/86`), and [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) (`85/88`). The associated read-only aggregate [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md) remains the broader `.rdata` range evidence page at `85/91`, but it is broader than this vtable family and also remains unassigned. No single direct parent owns every merchant/text/item/spell/argumented table, so this page's `AUTOGEN_PARENT_UID` remains blank by design and `RECONSTRUCTABLE` is `FALSE` for the mixed index.

Rejected single-owner options:

- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md): selected only for the base-class child; it supplies inherited slot `0x00517d80`, but text/item/spell/argumented constructors materialize their own tables in later source families.
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md): selected only for the text child; assigning the whole family here would incorrectly absorb item, spell, and argumented source owners.
- New broad `MerchantMenuDialogs.cpp`: rejected for current documentation because IDA store clusters and existing file roots already provide stronger owner-specific routing. A broad source file would be a possible final-source consolidation choice, not the best ownership parent for this by-type family.
- [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md): rejected as parent because it is a memory evidence aggregate crossing vtables, strings, argumented-input tables, object-image tables, and the `Message` successor boundary.

Score rationale: completion is raised because the page now records the current A004 IDA recheck, unique signatures for each owner strip, the exact successor vtable boundary, the child/direct-parent gate evidence, and the explicit non-emitting classification. Confidence is raised because the 2026-06-12 evidence agrees with the B001 split-first routing and confirms this is an index over five source owners, not a single source-owned vtable family.

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
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md)
- [UID:00031W][MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md)
- [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md)
- [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md)
- [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md)
- [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md)

## Changes

- 2026-08-17 B010 successor-boundary closure:
  - Preserved the mixed-family `90/93`, non-reconstructable, non-emitting classification and all 42 menu-family tables.
  - Linked [UID:00055A][0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData](by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md) as the exact separate successor child. The menu family ends after [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md); the COL at `0x0061f584` and first table at `0x0061f588` belong to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).

- 2026-06-21 B007 Rule 26 source-routing sync:
  - No score, parent, or reconstructable change.
  - Added the TextInputMenuDialog first-slot destructor split for primary `0x0061ee0c -> 0x00520d50`, secondary `0x0061ee6c -> 0x00520b29`, and tertiary `0x0061ee9c -> 0x00520b34`, with the same ordinary-destructor-only rebuild policy.
- 2026-06-21 B010 Rule 26 source-routing sync:
  - No score, parent, or reconstructable change.
  - Added the TextMenuItemList first-slot destructor split for primary `0x0061ed48 -> 0x00520df0`, secondary `0x0061edd0 -> 0x00520b55`, and tertiary `0x0061ee00 -> 0x00520b60`, plus the [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) endpoint caveat and ordinary-destructor-only rebuild policy.
- 2026-06-12 A004 Batch 330:
  - Changed score from `88/91` to `90/93`.
  - Changed `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`.
  - Reclassified the master from a reconstructable ownership-split inventory to a non-emitting mixed-owner index because [UID:00031W][MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md), [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md), [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md), [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md), and [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md) already carry the reconstructable source declarations and no single direct parent owns all five child groups.
  - A004 live IDA MCP reconfirmed all 42 decorated bases, representative vptr stores for each owner group, unique strip signatures, and the `0x0061f588` successor boundary before `ArgumentedItemQuantityInputDialogPane`.
- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:84` and `CONFIDENCE:87` after IDA MCP rechecked the decorated vtable symbols, RTTI locator placement, dialog/list slot counts, constructor/store xrefs, inherited `0x00517d80` slot values, and the read-only-data boundary before `ArgumentedItemQuantityInputDialogPane`. The score remains below the 95+ final-audit gate because final source-file split decisions and complete source declarations for every class/list companion are still open.
- 2026-06-08 A009 Batch 125:
  - Changed score from `84/87` to `85/88`.
  - Rechecked all 42 documented table bases, locator pointers, constructor/store refs, inherited `0x00517d80` secondary slots, and boundary symbols through live IDA MCP.
  - At that time, left `AUTOGEN_PARENT_UID` blank because the family was already recognized as cross-owner; the refreshed [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md) aggregate carried the mixed read-only range evidence, but exact owner-specific child pages did not yet exist.
- 2026-06-10 B001-008 split-first ownership repair:
  - Changed score from `85/88` to `88/91`.
  - Created exact owner-specific vtable children [UID:00031W][MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md), [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md), [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md), [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md), and [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md).
  - Refreshed parent gates for [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md), [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), and [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).
  - Kept this master page unparented as a mixed split index, now with concrete assigned child pages rather than a passive ownership-unknown recommendation.
