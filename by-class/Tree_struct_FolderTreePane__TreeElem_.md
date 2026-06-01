*** UID:0000F9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Tree_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for helper responsibility; medium for original template spelling.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a500`
- Current recovered file: `source-3/simroot_v2/class_Tree_struct_FolderTreePane__TreeElem_.cpp`

## Class Purpose

This is Wave3's concrete name for `Tree<FolderTreePane::TreeElem>`, embedded inside [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) at offset `0x130`. It wraps [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), owns reset/destruction behavior, and keeps the root node alive.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| destructor cleanup fragment | `0x004b5650-0x004b5668` | Resets the tree vtable, destroys embedded storage, and jumps to `LObject` teardown. IDA associates this block with `FolderTreePane` constructor EH cleanup, so it is not a clean direct-called standalone function. |
| scalar-deleting destructor | `0x004b59f0-0x004b5a38` | Restores tree vtable, destroys embedded storage, tears down `LObject`, and optionally deletes. |
| `ResetToSingleRoot` | `0x004b5b00-0x004b5bae` | Destroys existing node names, rewinds storage, and creates one root record with link fields set to `-1`. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [Wave3 data issue](../wave3_data_issues.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the embedded tree purpose, destructor cleanup, scalar deleting destructor, reset-to-root helper, FolderTreePane offsets, type/template/vtable links, and the noted Wave3 data issue around cleanup ownership.
