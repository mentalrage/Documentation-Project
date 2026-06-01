*** UID:0001XL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane Vtables

## Status

- Entity kind: vtable cluster for a filesystem tree control and local tree helpers.
- Covered owner: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Main class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Related templates: [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- Confidence: strong for vtable bases, slot boundaries, and adjacent string/data caveat.
- Rebuild handling: `source-declared/generated-binary`; the vtable bytes should be regenerated from class/template declarations, not hand-ported as raw data.

## Vtable Inventory

| Class / helper view | Vtable address | Slots | Key slots |
| --- | --- | --- | --- |
| `Tree<FolderTreePane::TreeElem>` | `0x0061a500` | `+0x00-+0x08` | `+0x00` -> `0x004b59f0` scalar deleting destructor; `+0x04` -> `0x004f4b10`; `+0x08` -> `0x0041b6c0` no-op/null slot. |
| `TreeItor<FolderTreePane::TreeElem>` | `0x0061a510` | `+0x00` only | `+0x00` -> `0x004b5a40` scalar deleting destructor. |
| `FolderTreePane` primary | `0x0061a518` | `+0x00-+0x6c` | `+0x00` -> `0x004b5a70` scalar deleting destructor; `+0x48-+0x6c` contain the tree paint, scroll, input, and event handlers. |
| `FolderTreePane` secondary `+0xa0` view | `0x0061a58c` | `+0x00-+0x28` | `+0x00` -> `0x004b59d5` adjustor thunk into `0x004b5a70`; remaining slots are inherited `ScrollablePane`/pane callback slots. |
| `FolderTreePane` tertiary `+0xa4` view | `0x0061a5bc` | `+0x00-+0x04` | `+0x00` -> `0x004b59e0` adjustor thunk into `0x004b5a70`; `+0x04` -> inherited event/update slot `0x00544e90`. |

The tertiary table stops after `+0x04`. Address `0x0061a5c4` begins the UTF-16 string `TREEICON.EPF`, not additional virtual slots. The string dwords decode to address-like values including `0x00520054`, `0x00450045`, and `0x00430049`; these should not be interpreted as `FolderTreePane` virtual methods.

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

## Generated-Data Caveat

Current `class_FolderTreePane.meta_wave3` reports `vtable_count: 0` while active generated source still emits vtable placeholder names. It also lists false virtual rows `virt_meth_0x430049` and `virt_meth_0x450045`; these appear to come from interpreting UTF-16 string data after the tertiary vtable as function pointers.

## Cross-References

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- What existed before: the vtable page had strong inventory content but was still scored `0/0` with blank reconstructability metadata.
- What it was changed to: scored `78/90` and marked `RECONSTRUCTABLE:TRUE` as source-declared/generated-binary vtable evidence.
- Summary and evidence: 2026-05-31 IDA MCP rechecked vtable xrefs for the tree helper and `FolderTreePane` tables, confirming the stop before `TREEICON.EPF` string data and supporting the source-declared vtable classification. Scores stay below `95` because final class declarations and several helper names are not yet near-final.
