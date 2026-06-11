*** UID:0000FC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeStorage_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for helper responsibility, live method boundaries, 36-byte record storage, grow/destruction behavior, and `FolderTreePane` ownership; medium-high for original template spelling/header factoring.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Parent attachment: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) has a documented `NexusTK/ui/controls/` reconstruction path, scores `89/85`, and owns the folder-tree template helpers; this class page now clears the corrected child/direct-parent `85/85` gate for direct attachment to that file.

## Class Purpose

This is the current concrete label for the vector-like storage subobject inside `Tree<FolderTreePane::TreeElem>`. It stores contiguous 36-byte [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) records and owns insert/grow/destruction logic.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InsertAt` | [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) | Grows storage at about 1.5x capacity, copy-constructs tree records, destroys old names, frees old storage, and returns the inserted slot. |
| destructor | [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) | Destroys all `SimpleUString` node names and frees aligned storage. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact ranges `0x004b3d50-0x004b3fa4` for `InsertAt` and `0x004b56e0-0x004b575f` for the storage destructor.
- IDA reports `InsertAt` callers at `0x004b227f`, `0x004b23d8`, and `0x004b5b8f`, tying insertion to FolderTreePane population/reset paths. The storage destructor has five code xrefs, including cleanup/destructor paths at `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`.
- Live decompilation of `InsertAt` computes indexes and capacity using a 36-byte stride, grows capacity by the existing-capacity-plus-half pattern, uses aligned allocation for large buffers, calls `0x004b55e0` to copy-construct records, and destroys old `SimpleUString` names during relocation.
- Live decompilation of the storage destructor walks records by nine dwords per element, destroys the `SimpleUString` at record offset `+0x14`, validates aligned allocation headers for large buffers, frees storage, and clears begin/end/capacity pointers.
- 2026-06-08 A009 Batch117 rechecked the direct parent chain against the current scores: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is `89/85`, [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) is `85/89`, and this concrete storage class is the immediate class owner for [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md).

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The class page now links exact `InsertAt` and destructor memory pages, records the 36-byte storage role, caller/xref evidence, allocation/destruction behavior, direct file parent, and template-context evidence. Completion remains below final-source quality because final original template spelling and member names are still inferred. |
| Confidence | 86 | IDA-backed method boundaries, xrefs, 36-byte layout, and the refreshed `FolderTreePane`/template parent chain support this concrete storage class. Confidence is capped because the exact original header factoring remains unresolved. |
| Assignment | [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | The child is `85/86`, the direct file parent is `89/85`, and current evidence supports `FolderTreePane.cpp` as the source owner for the local tree-storage template support. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md)
- [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md)
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
- 2026-06-08 A009 Batch117 parent-gate refresh:
  - What existed before: score `82/84`, with stale direct-parent gate evidence even though the direct `FolderTreePane` file and template pages had since been refreshed.
  - Changed to: score `85/86`, retained `AUTOGEN_PARENT_UID:0000JG`, added exact method UID links and an explicit score/assignment rationale.
  - Summary/evidence: current documentation plus Batch117 IDA rechecks confirm `InsertAt` at `0x004b3d50-0x004b3fa4`, storage destructor at `0x004b56e0-0x004b575f`, 36-byte record semantics, the `FolderTreePane.cpp` file parent at `89/85`, and the template-context page at `85/89`.
