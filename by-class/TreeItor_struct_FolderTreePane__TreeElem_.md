*** UID:0000FB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeItor_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for iterator behavior, live method boundaries, vtable identity, traversal field use, and `FolderTreePane` ownership; medium for original template spelling/header factoring.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a510`
- Parent attachment: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) has a documented `NexusTK/ui/controls/` reconstruction path and owns the folder-tree template helpers.

## Class Purpose

This is the current concrete label for `TreeItor<FolderTreePane::TreeElem>`, an iterator over the embedded folder tree. The iterator stores a tree pointer and current node index, then exposes visible-child/sibling/parent traversal helpers used by [UID:00005A][FolderTreePane](by-class/FolderTreePane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| destructor | `0x004b5670-0x004b5677` | Resets iterator vtable during destruction. |
| scalar-deleting destructor | `0x004b5a40-0x004b5a64` | Resets vtable and conditionally deletes. |
| `MoveToFirstChild` | `0x004b5bb0-0x004b5bd0` | Reads the current node's child index at record offset `+0x04`; moves when it is not `-1`. |
| `MoveToNextVisibleSibling` | `0x004b5bd0-0x004b5c13` | Follows sibling indexes at record offset `+0x10`, skipping records whose hidden/deleted byte at `+0x20` is set. |
| `MoveToParent` | `0x004b5c20-0x004b5c3f` | Reads the current node's parent index at record offset `+0x00`; moves when it is not `-1`. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact function ranges for the iterator vtable-reset destructor, scalar deleting destructor, and three traversal helpers: `0x004b5670-0x004b5677`, `0x004b5a40-0x004b5a64`, `0x004b5bb0-0x004b5bd0`, `0x004b5bd0-0x004b5c13`, and `0x004b5c20-0x004b5c3f`.
- IDA names the vtable at `0x0061a510` as `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`; slot `+0x00` points to `0x004b5a40`, and IDA reports 31 data xrefs to this vtable from `FolderTreePane` constructor, traversal, cleanup, and helper paths.
- Live xrefs show `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` each have a direct caller in `FolderTreePane` code (`0x004b2cbe`, `0x004b23f2`, and `0x004b2c92` respectively).
- Live decompilation ties traversal to the 36-byte [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) record layout: parent index `+0x00`, first child `+0x04`, next sibling `+0x10`, and hidden/deleted byte `+0x20`.

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
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed exact iterator method boundaries, the named `TreeItor<FolderTreePane::TreeElem>` vtable at `0x0061a510`, vtable slot/data xrefs, direct FolderTreePane traversal callers, and traversal field accesses matching the documented 36-byte tree element layout.
  - Remaining limits: scores stay below final-source level because exact original template spelling/header factoring and final public method names remain inferred.
