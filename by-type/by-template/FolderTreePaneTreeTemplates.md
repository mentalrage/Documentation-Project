*** UID:0001WP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane Tree Templates

## Status

- Confidence: strong for `FolderTreePane` ownership and concrete helper behavior, medium for exact original template spelling/header factoring.
- Rebuild handling: `source-authored` project-local tree/template support; reconstruct as local template/helper declarations with `FolderTreePane`, not as standalone generated class files.
- Owner file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Owner class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Related layout: [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- Related vtables: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- Related memory: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)

## Declaration Hypothesis

The generated classes are concrete template/support instantiations for the filesystem tree embedded in `FolderTreePane`, not original one-class source files:

```cpp
struct FolderTreePane::TreeElem;
template<class T> class TreeStorage;
template<class T> class Tree;
template<class T> class TreeItor;
```

The concrete instance is effectively:

```cpp
Tree<FolderTreePane::TreeElem>
TreeStorage<FolderTreePane::TreeElem>
TreeItor<FolderTreePane::TreeElem>
```

## Generated Names

| Generated class | Current role | Placement |
| --- | --- | --- |
| [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) | 36-byte node storage, insert/grow, destruction | `FolderTreePane.cpp` local/template support. |
| [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) | Tree wrapper, cleanup, scalar deleting destructor, reset-to-root | `FolderTreePane.cpp` local/template support. |
| [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) | Iterator over current node, child/sibling/parent traversal | `FolderTreePane.cpp` local/template support. |

## Exact Memory Pages

| Range page | Template role | Evidence state |
| --- | --- | --- |
| [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) | `TreeStorage<FolderTreePane::TreeElem>::InsertAt` | IDA-confirmed 36-byte storage insert/grow helper. |
| [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) | `FolderTreePane::TreeElem` copy construction | IDA-confirmed link/string/flag field copy helper. |
| [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md) | constructor EH cleanup fragment for `Tree<FolderTreePane::TreeElem>` | Destructor-shaped, but IDA models it as constructor exception cleanup. |
| [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) | `TreeStorage<FolderTreePane::TreeElem>` cleanup | IDA-confirmed 36-byte element walk and storage free. |
| [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) | `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot` | IDA-confirmed root record reset/insert helper. |
| [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) | iterator first-child traversal | IDA-confirmed current-index update from record offset `+0x04`. |
| [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) | iterator next-visible-sibling traversal | IDA-confirmed sibling walk and skip of flag byte at record offset `+0x20`. |
| [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) | iterator parent traversal | IDA-confirmed parent-index update from record offset `+0x00`. |

## Evidence Notes

- `FolderTreePane` embeds the tree at offset `+0x130` and the selected iterator at `+0x170`.
- `TreeStorage<FolderTreePane::TreeElem>` uses 36-byte records and owns `InsertAt` at `0x004b3d50` and storage destruction at `0x004b56e0`.
- `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot` at `0x004b5b00` is called from the `FolderTreePane` constructor and reset/root-name paths.
- `TreeItor<FolderTreePane::TreeElem>` traversal helpers at `0x004b5bb0`, `0x004b5bd0`, and `0x004b5c20` are local to visible folder-tree traversal.
- The cleanup body at `0x004b5650` is destructor-shaped code, but IDA associates it with `FolderTreePane` constructor exception cleanup rather than an ordinary direct-called function.
- The nearby `0x004b59d5-0x004b59eb` thunks are compiler-generated `FolderTreePane` destructor adjustors, not template-owned source. See [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md).
- IDA confirms the concrete `Tree` vtable at `0x0061a500` and `TreeItor` vtable at `0x0061a510`; current generated metadata still omits them from vtable inventory.
- 2026-05-31 IDA MCP recheck confirmed exact starts/sizes for the split helper pages: `0x004b3d50` size `0x254`, `0x004b55e0` size `0x6d`, `0x004b56e0` size `0x7f`, `0x004b5b00` size `0xae`, `0x004b5bb0` size `0x20`, `0x004b5bd0` size `0x43`, and `0x004b5c20` size `0x1f`.
- IDA xrefs to `0x0061a500` and `0x0061a510` land in constructor/destructor and helper method vtable stores, supporting concrete project-local virtual helper objects rather than STL/runtime support.

## Open Questions

- Whether the original project used a reusable tree template header shared elsewhere, or whether these helper names represent compiler-specialized code from a local tree implementation.
- Final names for `TreeElem` link fields and visibility flags.

## Cross-References

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md)
- [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md)
- [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md)
- [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md)
- [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)

## Changes

- What existed before: the page had useful template hypotheses but was still scored `0/0`, had blank reconstructability metadata, and only linked the broad aggregate memory page for most helper bodies.
- What it was changed to: scored `80/88`, marked `RECONSTRUCTABLE:TRUE`, and expanded with exact by-memory pages for storage insert, element copy, storage destruction, reset-to-root, and iterator traversal helpers.
- Summary and evidence: 2026-05-31 IDA MCP verified helper starts/sizes, callers, representative decompilations, vtable xrefs, 36-byte element behavior, and iterator link offsets. Scores remain below `95` because final template header spelling, field names, and the larger directory-entry sort/helper spans still need more research before final C++ is safe.
