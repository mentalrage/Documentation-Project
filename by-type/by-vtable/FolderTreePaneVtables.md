*** UID:0001XL | DO NOT MODIFY OR REMOVE!!! ***
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

# FolderTreePane Vtables

## Status

- Entity kind: non-emitting vtable cluster for a filesystem tree control and local tree helpers.
- Covered owner: mixed; exact child pages now carry the direct class/template ownership.
- Covered source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Main class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Related templates: [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- Exact child vtable pages: [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md), [UID:00036L][FolderTreePaneTreeItorVtable](by-type/by-vtable/FolderTreePaneTreeItorVtable.md), and [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md)
- Confidence: very strong for vtable bases, RTTI locator boundaries, slot boundaries, direct-owner split, and adjacent string/data caveat.
- Rebuild handling: `source-declared/generated-binary`; the vtable bytes should be regenerated from class/template declarations, not hand-ported as raw data.
- Reconstructable: false for this aggregate itself. The source-declared vtable requirements are reconstructable on the exact child pages; this page remains a parent-blank inventory because it spans multiple direct owners.

## Vtable Inventory

| Class / helper view | Vtable address | Slots | Key slots |
| --- | --- | --- | --- |
| `Tree<FolderTreePane::TreeElem>` | `0x0061a500` | `+0x00-+0x08` | `+0x00` -> `0x004b59f0` scalar deleting destructor; `+0x04` -> `0x004f4b10`; `+0x08` -> `0x0041b6c0` no-op/null slot. |
| `TreeItor<FolderTreePane::TreeElem>` | `0x0061a510` | `+0x00` only | `+0x00` -> `0x004b5a40` scalar deleting destructor. |
| `FolderTreePane` primary | `0x0061a518` | `+0x00-+0x6c` | `+0x00` -> `0x004b5a70` scalar deleting destructor; `+0x48-+0x6c` contain the tree paint, scroll, input, and event handlers. |
| `FolderTreePane` secondary `+0xa0` view | `0x0061a58c` | `+0x00-+0x28` | `+0x00` -> `0x004b59d5` adjustor thunk into `0x004b5a70`; remaining slots are inherited `ScrollablePane`/pane callback slots. |
| `FolderTreePane` tertiary `+0xa4` view | `0x0061a5bc` | `+0x00-+0x04` | `+0x00` -> `0x004b59e0` adjustor thunk into `0x004b5a70`; `+0x04` -> inherited event/update slot `0x00544e90`. |

The tertiary table stops after `+0x04`. Address `0x0061a5c4` begins the UTF-16 string `TREEICON.EPF`, not additional virtual slots. The string dwords decode to address-like values including `0x00520054`, `0x00450045`, and `0x00430049`; these should not be interpreted as `FolderTreePane` virtual methods.

## Direct-Owner Split

| Exact vtable page | Exact data page | Direct parent | Reason |
| --- | --- | --- | --- |
| [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) | [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) | [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) | Concrete `Tree<FolderTreePane::TreeElem>` wrapper vtable and RTTI locator. |
| [UID:00036L][FolderTreePaneTreeItorVtable](by-type/by-vtable/FolderTreePaneTreeItorVtable.md) | [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md) | [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) | Concrete iterator wrapper vtable and RTTI locator. |
| [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) | [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) | [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) | Primary, secondary, and tertiary `FolderTreePane` class vtable views. |

This aggregate is intentionally parent-blank because those exact children have different direct class owners even though they share the [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) source module.

B001's 2026-06-28 empty-emitter implementation keeps this aggregate non-emitting and preserves the rejected alternatives: no aggregate C++, no hand-authored vtable arrays, and no string-derived false virtual rows after `TREEICON.EPF`. The exact `Tree<FolderTreePane::TreeElem>` layout/data pair [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) / [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) now uses formal comment-only no-code markers routed through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md), while the aggregate remains `RECONSTRUCTABLE:FALSE` because it spans `Tree`, `TreeItor`, and `FolderTreePane` direct owners.

B006's 2026-06-29 empty-emitter implementation applies the same source-declared/generated-binary policy to the `FolderTreePane` class layout/data pair [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) / [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md). Those exact pages now carry formal comment-only no-code markers routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md); this aggregate still emits nothing and still rejects aggregate C++, raw vtable arrays, and string-derived virtual rows after `TREEICON.EPF`.

## Primary `FolderTreePane` Slots

| Slot | Target | Current role |
| --- | --- | --- |
| `+0x00` | `0x004b5a70` | `FolderTreePane` scalar deleting destructor. |
| `+0x30` | `0x0055ee10` | Inherited scroll/pane virtual. |
| `+0x38` | `0x0055ef10` | Inherited scroll/pane virtual. |
| `+0x44` | `0x0055f190` | Inherited scroll/pane virtual. |
| `+0x48` | `0x004b2a80` | Content extent helper. |
| `+0x4c` | `0x004b2ab0` | Visible extent helper. |
| `+0x50` | `0x004b2af0` | Viewport size helper. |
| `+0x54` | `0x004b2b20` | Scroll value transform helper. |
| `+0x58` | `0x004b2b30` | Content dimensions helper. |
| `+0x5c` | `0x004b2b50` | Scroll delta computation. |
| `+0x60` | `0x004b2dc0` | Mouse event handler. |
| `+0x64` | `0x004b2b80` | Key event handler. |
| `+0x68` | `0x0041d6b0` | Inherited/default callback slot. |
| `+0x6c` | `0x004b2a00` | Paint visible tree rows. |

## IDA Evidence

- IDA names the vtables at `0x0061a500`, `0x0061a510`, `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`.
- IDA xrefs to the three `FolderTreePane` vtables land in constructor stores at `0x004b1bd5`, `0x004b1bdb`, and `0x004b1be5`, plus destructor stores at `0x004b5a77`, `0x004b5a83`, and `0x004b5a8d`.
- IDA xrefs to the tree helper vtables land in the constructor, tree cleanup, and scalar destructors.
- 2026-05-31 IDA MCP `xrefs_to` rechecked `0x0061a500`, `0x0061a510`, `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`. Tree vtable refs land in the constructor, cleanup fragment, scalar destructors, and local helper methods; `FolderTreePane` vtable refs land in constructor/destructor stores.
- IDA xrefs to `0x0061a5c4` land in the constructor/root-name paths that load the icon resource string, confirming `0x0061a5c4` is data for `TREEICON.EPF`.
- IDA `lookup_funcs` resolves `0x00430049`, `0x00450045`, and `0x00520054` inside unrelated real code functions, but the `FolderTreePane` references to those values are data reads from the `TREEICON.EPF` string, not virtual calls.
- 2026-06-11 A006 IDA MCP refresh corrected the RTTI/string boundary: `0x0061a4f4-0x0061a4fc` is the UTF-16 `X:\` literal, while `0x0061a4fc` is the `Tree<FolderTreePane::TreeElem>` RTTI locator dword immediately before the `0x0061a500` vtable base.
- The same refresh reads RTTI locator dwords at `0x0061a4fc`, `0x0061a50c`, `0x0061a514`, `0x0061a588`, and `0x0061a5b8`, and verifies the three exact data children listed in the split table.
- 2026-06-11 `lookup_funcs` confirms the key destructor/thunk bodies: `0x004b59f0` size `0x48`, `0x004b5a40` size `0x24`, `0x004b5a70` size `0x84`, and adjustor thunks `0x004b59d5` / `0x004b59e0` size `0x0b` each.
- 2026-06-11 disassembly confirms `0x004b5a70` restores the three `FolderTreePane` vtable views, resets embedded iterator/tree vtables at `this+0x170` and `this+0x130`, tears down tree storage and the pane base, and uses delete flag handling for the `0x17c`-sized pane.

## Generated-Data Caveat

Current `class_FolderTreePane.meta_wave3` reports `vtable_count: 0` while active generated source still emits vtable placeholder names. It also lists false virtual rows `virt_meth_0x430049` and `virt_meth_0x450045`; these appear to come from interpreting UTF-16 string data after the tertiary vtable as function pointers.

## 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis uses this page as the authoritative vtable-family boundary for `Tree`, `TreeItor`, and the three `FolderTreePane` views. Source reconstruction should model declarations, inheritance, and destructors; it should not hand-port vtable arrays or adjustor thunk bodies.

Exact class vtable bases remain `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`, with primary/secondary/tertiary `FolderTreePane` views corresponding to offsets `+0x00`, `+0xa0`, and `+0xa4` in a `0x17c`-byte class. `0x0061a5c4` begins UTF-16 `TREEICON.EPF` data and must continue to reject false generated virtual rows such as `virt_meth_0x430049` / string-derived dwords.

## Cross-References

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md)
- [UID:00036L][FolderTreePaneTreeItorVtable](by-type/by-vtable/FolderTreePaneTreeItorVtable.md)
- [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md)
- [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md)
- [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md)
- [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-29 B006 FolderTreePane class-vtable empty-emitter support sync:
  - Score unchanged at `88/92`; `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank `EMITTER_UIDS` remain correct for this mixed aggregate.
  - Added that [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) / [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) now use comment-only no-code markers through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md).
  - Preserved the rejected alternatives: no aggregate C++, no hand-authored vtable arrays, and no string-derived false virtual rows after `TREEICON.EPF`. The historical [Wave3 data issues](../../wave3_data_issues.md) cross-reference remains context only, not source-route authority.

- 2026-06-28 B001 tree-vtable empty-emitter support sync:
  - Score unchanged at `88/92`.
  - Preserved the non-emitting mixed aggregate classification and added that [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) / [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) now carry comment-only no-code markers through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md). No aggregate C++, raw vtable array, or string-derived virtual-row interpretation is introduced.

- What existed before: the vtable page had strong inventory content but was still scored `0/0` with blank reconstructability metadata.
- What it was changed to: scored `78/90` and marked `RECONSTRUCTABLE:TRUE` as source-declared/generated-binary vtable evidence.
- Summary and evidence: 2026-05-31 IDA MCP rechecked vtable xrefs for the tree helper and `FolderTreePane` tables, confirming the stop before `TREEICON.EPF` string data and supporting the source-declared vtable classification. Scores stay below `95` because final class declarations and several helper names are not yet near-final.
- 2026-06-11 A006 split repair:
  - What existed before: score `78/90`, `RECONSTRUCTABLE:TRUE`, parent blank, and one aggregate page mixed `Tree`, `TreeItor`, and `FolderTreePane` direct owners.
  - Changed to: score `88/92`, `RECONSTRUCTABLE:FALSE` for the aggregate, with exact reconstructable child pages [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md), [UID:00036L][FolderTreePaneTreeItorVtable](by-type/by-vtable/FolderTreePaneTreeItorVtable.md), and [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md).
  - Summary/evidence: live IDA reconfirmed RTTI locator dwords, vtable slots, constructor/cleanup/destructor xrefs, destructor/thunk function sizes, destructor store behavior, and the corrected `X:\` versus `Tree` RTTI boundary at `0x0061a4fc`. The aggregate remains parent-blank because the exact children have different direct owners.
