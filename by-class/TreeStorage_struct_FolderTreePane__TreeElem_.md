*** UID:0000FC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeStorage_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for helper responsibility; medium for original template spelling.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_TreeStorage_struct_FolderTreePane__TreeElem_.cpp`

## Class Purpose

This is Wave3's concrete name for the vector-like storage subobject inside `Tree<FolderTreePane::TreeElem>`. It stores contiguous 36-byte [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) records and owns insert/grow/destruction logic.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InsertAt` | `0x004b3d50-0x004b3fa4` | Grows storage at about 1.5x capacity, copy-constructs tree records, destroys old names, frees old storage, and returns the inserted slot. |
| destructor | `0x004b56e0-0x004b575f` | Destroys all `SimpleUString` node names and frees aligned storage. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the insert/grow/destructor behavior, 36-byte tree-record ownership, FolderTreePane memory/type cross-references, and medium confidence on exact original template spelling.
