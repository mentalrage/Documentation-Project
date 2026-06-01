*** UID:0000FB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeItor_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for iterator behavior; medium for original template spelling.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a510`
- Current recovered file: `source-3/simroot_v2/class_TreeItor_struct_FolderTreePane__TreeElem_.cpp`

## Class Purpose

This is Wave3's concrete name for `TreeItor<FolderTreePane::TreeElem>`, an iterator over the embedded folder tree. The iterator stores a tree pointer and current node index, then exposes visible-child/sibling/parent traversal helpers used by [UID:00005A][FolderTreePane](by-class/FolderTreePane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| destructor | `0x004b5670-0x004b5677` | Resets iterator vtable during destruction. |
| scalar-deleting destructor | `0x004b5a40-0x004b5a64` | Resets vtable and conditionally deletes. |
| `MoveToFirstChild` | `0x004b5bb0-0x004b5bd0` | Moves to the current node's first child when one exists. |
| `MoveToNextVisibleSibling` | `0x004b5bd0-0x004b5c13` | Advances across siblings, skipping nodes with the hidden/deleted flag. |
| `MoveToParent` | `0x004b5c20-0x004b5c3f` | Moves to the current node's parent when one exists. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the concrete iterator traversal methods, FolderTreePane ownership, tree-element/vtable/template links, and remaining uncertainty around original template spelling/source artifact.
