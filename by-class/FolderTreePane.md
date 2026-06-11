*** UID:00005A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane

## Status

- Confidence: strong for filesystem-tree control core, nested `TreeElem` ownership, and local tree-template helper relationships; medium-high for final source split and field names.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address ranges: [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md), [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), and [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md)
- Vtables: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_FolderTreePane.cpp`
- Current size: `0x17c` (`380`) bytes in Wave3/Ghidra struct data.

## Class Purpose

`FolderTreePane` is a `ScrollablePane`-derived filesystem tree control. It lazily expands folder nodes, sorts visible directory entries, paints folder rows with an icon and indentation, handles arrow-key and mouse navigation, keeps selection visible, and exposes selected-path construction for the owning folder dialog.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004b1b90-0x004b1ce5` | Initializes `ScrollablePane`, embedded tree storage, tile/icon context, and initial root expansion. |
| `FindFirstVisibleChild` | `0x004b1d50-0x004b253a` | Builds node path, enumerates child directories, sorts names, inserts child nodes, and refreshes layout. |
| `CollapseNode` | `0x004b2540-0x004b2575` | Clears expanded flag and refreshes layout. |
| `RefreshTreeLayout` | `0x004b2580-0x004b25d9` | Recomputes dimensions/scrollbars and preserves scroll position. |
| `SetRootNodeName` | `0x004b25e0-0x004b267d` | Resets the tree to one root node and expands from a new drive/root name. |
| traversal helper | `0x004b2680-0x004b2728` | IDA-confirmed helper around tree iterator traversal; not active in generated method output. |
| `SelectNodeByPath` | `0x004b2730-0x004b29fb` | Splits an input path, expands intermediate nodes, and selects a matching node. |
| paint/scroll virtuals | `0x004b2a00-0x004b2b7c` | Paint tree, expose content/viewport extents, scroll transform, dimensions, and scroll delta. |
| `OnKeyEvent` | `0x004b2b80-0x004b2d8c` | Arrow/home navigation, expand/collapse, next/previous visible traversal. |
| `OnMouseEvent` | `0x004b2dc0-0x004b2f59` | Hit-test tree rows and toggle/select clicked nodes. |
| `CalculateContentDimensions` | `0x004b2f60-0x004b3006` | Traverses visible rows to compute width/height. |
| `GetNodeBounds` | `0x004b3010-0x004b3084` | Computes row rectangle from row/depth and text width. |
| selected-path helper | `0x004b3090-0x004b3203` | Builds a full path string from the selected iterator by walking parent links. |
| `SetSelection` | [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) | Copies iterator, scrolls selection into view, and updates display; body is currently missing from generated source. See [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md). |
| scalar-deleting destructor | `0x004b5a70-0x004b5af4` | Restores vtables, destroys tree storage and base pane, conditionally deletes. |
| destructor adjustor thunks | [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) | Compiler-generated secondary/tertiary thunks into the scalar deleting destructor; ignore for handwritten source. |

## Layout Notes

- `ScrollablePane` base is at offset `0x000`.
- The embedded `Tree<FolderTreePane::TreeElem>` starts at offset `0x130` (`304`).
- The folder icon/tile context begins around offset `0x148` (`328`) in constructor evidence.
- The selected iterator starts at offset `0x170` (`368`).
- `FolderTreePane::TreeElem` is a 36-byte nested record now attached to this class. See [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md).
- IDA confirms three `FolderTreePane` vptr views at `+0x00`, `+0xa0`, and `+0xa4`, plus helper vtables for the embedded `Tree` and selected `TreeItor`; see [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md).
- The generated `virt_meth_0x430049` and `virt_meth_0x450045` rows are false virtuals derived from the adjacent UTF-16 `TREEICON.EPF` string after the tertiary vtable, not class methods.

## Batch 127 TreeElem Evidence

Live IDA MCP recheck on 2026-06-08 refreshed the nested tree-element evidence while reviewing [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) and [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md):

- `FindFirstVisibleChild` at `0x004b1d50` writes child links and uses offsets `+0x04`, `+0x08`, `+0x10`, `+0x1c`, and `+0x1d` while lazily enumerating child directories.
- `CollapseNode` at `0x004b2540` clears byte `TreeElem+0x1d`, confirming that byte as the expanded flag.
- Iterator helpers read `TreeElem+0x00` as parent, `+0x04` as first child, `+0x10` as next visible sibling, and byte `+0x20` as the hidden/deleted skip flag.
- `TreeStorage<FolderTreePane::TreeElem>` helper pages tie insert/copy/destruction directly to the nested type and the concrete storage class, while [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) remains the source file parent.

## Ownership Notes

The active generated file should be treated as polluted. Only the filesystem-tree core and local tree/sort helpers should be considered strong `FolderTreePane.cpp` contents. Chat message, surface, and help/system-message methods currently emitted under this class are documented separately in [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md).

## Cross-References

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md)
- [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md)
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md)

## Changes

- 2026-06-08 A006 Batch 127 parent-gate repair:
  - What existed before: score `82/84`; the class was attached to the file parent but stayed below the corrected `85/85` gate for nested `TreeElem` ownership.
  - Changed to: score `85/86`.
  - Summary/evidence: live IDA refreshed `TreeElem` field use across `FindFirstVisibleChild`, `CollapseNode`, `GetNodeBounds`, the iterator traversal helpers, the copy helper, and the storage destructor. The page now supports [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) as a direct nested type under `FolderTreePane`, while final source field names and header factoring still cap the score below final-audit quality.
- Completion/confidence score update: existed before as `0/0`; changed to `82/84`. Summary: filesystem-tree role, major methods, layout offsets, vtable views, helper ownership, false virtual caveats, and pollution boundaries are extensively documented; remaining work is final source split, field naming, and full C++ reconstruction. Evidence: core/helper/vector memory pages, `FolderTreePaneVtables`, `FolderTreePane__TreeElem`, and owner-pollution note.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) because the class is `82/84` and the parent is `88/80`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts for the core/tree/paint/input/selection/destructor methods from `0x004b1b90` through `0x004b5a70`; current `callers` confirms the constructor reference at `0x004b178b`.
