*** UID:0000RA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pItemObjImageLib

## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md), IDA `dword_67A758`.
- Canonical owner: [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) in [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Observed aliases: `g_pItemObjectImageLib`, `g_pItemImageLib`, and raw `dword_67A758`.

## Meaning

`g_pItemObjImageLib` is the global pointer to the item sprite library. UI item rows, item menus, look panes, inventory/fitting panes, and item-preview dialogs read this pointer before calling the shared item draw routines.

Keep this global with `render/ItemObjImageLib.cpp`. Consumers should not adopt it just because they draw item icons.

## Write Evidence

IDA MCP on 2026-05-25 reports 65 xrefs to `0x0067a758` across 29 recognized functions. The write sites are:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004dec7b` | `ItemObjImageLib::ItemObjImageLib` | Stores the constructed `ItemObjImageLib*` singleton. |
| `0x004dec82` | `ItemObjImageLib::ItemObjImageLib` | Constructor fallback/guard path clears the singleton. |
| `0x004dee3b` | [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5ba0` | [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |
| `0x004e659e` | `ItemObjImageLib::ScalarDeletingDestructor` | Clears the singleton during destruction. |

The constructor at `0x004dec30` also chooses `ITEM.TBL` versus `ITEM.TBD`, installs the `ItemObjImageLib` and `ProtectedArray<ItemInfo>` vtables, and loads the item metadata rows.

Live IDA MCP decompilation confirms the constructor, destructor/helper, singleton-clear helper, and scalar deleting destructor references to `dword_67A758`; use that storage/xref evidence as the ownership basis.

## Consumer Evidence

Known readers include:

- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) draw path `0x004aec90`, which calls `ItemObjImageLib::DrawItemImage` or `DrawItemImageScaled` after `GetItemGlyphBounds`.
- item context menu row lists around `0x0051b3e0`, `0x0051c6c0`, and related server/client item menu draw paths.
- clan item list, fitting/inventory, look-pane, ranking-reward, item-preview, and exchange/mix UI paths documented in the item rendering and dialog clusters.

## Ownership Decision

`g_pItemObjImageLib` is source-owned by `ItemObjImageLib`, not by `MyItemListPane`, `ArgumentedMenuMenuItemList`, `ClientItemMenuItemList`, `Application`, or any caller that only consumes item icons.

When rewriting source, normalize noncanonical aliases back to this canonical global unless stronger original-name evidence appears.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values while already carrying detailed IDA-backed address, owner, write-site, and consumer evidence.
- What changed: completion/confidence were raised to `88/88`, and the evidence notes now include lifecycle writes/clears and ownership caveats.
- Summary and evidence: existing by-memory notes independently record the IDA xrefs and write addresses. The score remains below complete because not all 65 reader xrefs are enumerated and the final original spelling remains slightly caveated by older aliases.
- 2026-06-05: Marked reconstructable under [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md). Evidence: live IDA MCP reports 65 xrefs to `0x0067a758`; decompilation confirms constructor `0x004dec30`, clear helper `0x004e5ba0`, and scalar deleting destructor `0x004e6580` write/clear `dword_67A758`.
