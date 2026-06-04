*** UID:0000FC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeStorage_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for helper responsibility, live method boundaries, 36-byte record storage, grow/destruction behavior, and `FolderTreePane` ownership; medium for original template spelling/header factoring.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Parent attachment: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) has a documented `NexusTK/ui/controls/` reconstruction path and owns the folder-tree template helpers.

## Class Purpose

This is the current concrete label for the vector-like storage subobject inside `Tree<FolderTreePane::TreeElem>`. It stores contiguous 36-byte [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) records and owns insert/grow/destruction logic.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InsertAt` | `0x004b3d50-0x004b3fa4` | Grows storage at about 1.5x capacity, copy-constructs tree records, destroys old names, frees old storage, and returns the inserted slot. |
| destructor | `0x004b56e0-0x004b575f` | Destroys all `SimpleUString` node names and frees aligned storage. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact ranges `0x004b3d50-0x004b3fa4` for `InsertAt` and `0x004b56e0-0x004b575f` for the storage destructor.
- IDA reports `InsertAt` callers at `0x004b227f`, `0x004b23d8`, and `0x004b5b8f`, tying insertion to FolderTreePane population/reset paths. The storage destructor has five code xrefs, including cleanup/destructor paths at `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`.
- Live decompilation of `InsertAt` computes indexes and capacity using a 36-byte stride, grows capacity by the existing-capacity-plus-half pattern, uses aligned allocation for large buffers, calls `0x004b55e0` to copy-construct records, and destroys old `SimpleUString` names during relocation.
- Live decompilation of the storage destructor walks records by nine dwords per element, destroys the `SimpleUString` at record offset `+0x14`, validates aligned allocation headers for large buffers, frees storage, and clears begin/end/capacity pointers.

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
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed exact `InsertAt` and destructor boundaries, caller sets, 36-byte storage stride, grow/allocation behavior, record copy construction, `SimpleUString` cleanup at offset `+0x14`, and `FolderTreePane` ownership through the surrounding tree-template aggregate.
  - Remaining limits: scores stay below final-source level because exact original template spelling/header factoring and final field/member names remain inferred.
