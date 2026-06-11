*** UID:0000FB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeItor_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for iterator behavior, live method boundaries, vtable identity, traversal field use, cleanup-helper classification, and `FolderTreePane` ownership; medium-high for original template spelling/header factoring.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a510`
- Parent attachment: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) has a documented `NexusTK/ui/controls/` reconstruction path, scores `89/85`, and owns the folder-tree template helpers; this class page now clears the corrected child/direct-parent `85/85` gate for direct attachment to that file.

## Class Purpose

This is the current concrete label for `TreeItor<FolderTreePane::TreeElem>`, an iterator over the embedded folder tree. The iterator stores a tree pointer and current node index, then exposes visible-child/sibling/parent traversal helpers used by [UID:00005A][FolderTreePane](by-class/FolderTreePane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| destructor | `0x004b5670-0x004b5677` | Resets iterator vtable during destruction. |
| cleanup vtable reset helper | [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md) | Compiler-generated cleanup helper that stores the `TreeItor` vtable at `this+0x0c`; not source-authored behavior. |
| dual cleanup vtable reset helper | [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md) | Compiler-generated cleanup helper that stores the `TreeItor` vtable at `this+0x0c` and `this+0x00`; not source-authored behavior. |
| scalar-deleting destructor | `0x004b5a40-0x004b5a64` | Resets vtable and conditionally deletes. |
| `MoveToFirstChild` | `0x004b5bb0-0x004b5bd0` | Reads the current node's child index at record offset `+0x04`; moves when it is not `-1`. |
| `MoveToNextVisibleSibling` | `0x004b5bd0-0x004b5c13` | Follows sibling indexes at record offset `+0x10`, skipping records whose hidden/deleted byte at `+0x20` is set. |
| `MoveToParent` | `0x004b5c20-0x004b5c3f` | Reads the current node's parent index at record offset `+0x00`; moves when it is not `-1`. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact function ranges for the iterator vtable-reset destructor, scalar deleting destructor, and three traversal helpers: `0x004b5670-0x004b5677`, `0x004b5a40-0x004b5a64`, `0x004b5bb0-0x004b5bd0`, `0x004b5bd0-0x004b5c13`, and `0x004b5c20-0x004b5c3f`.
- IDA names the vtable at `0x0061a510` as `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`; slot `+0x00` points to `0x004b5a40`, and IDA reports 31 data xrefs to this vtable from `FolderTreePane` constructor, traversal, cleanup, and helper paths.
- Live xrefs show `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` each have a direct caller in `FolderTreePane` code (`0x004b2cbe`, `0x004b23f2`, and `0x004b2c92` respectively).
- Live decompilation ties traversal to the 36-byte [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) record layout: parent index `+0x00`, first child `+0x04`, next sibling `+0x10`, and hidden/deleted byte `+0x20`.
- 2026-06-08 A009 Batch117 rechecked the tiny iterator cleanup helpers: [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md) stores the `TreeItor` vtable at `this+0x0c` and [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md) stores the same vtable at `this+0x0c` and `this+0x00`. Both have no ordinary direct callers and are reached through EH cleanup jumps, so they support the iterator class/vtable model but remain non-source cleanup helpers.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The class page now records exact traversal method pages, destructor/vtable evidence, the tiny cleanup-helper split, the 36-byte tree-element field usage, and the direct `FolderTreePane` file parent. Completion remains below final-source quality because exact original template spelling and public method names are still inferred. |
| Confidence | 86 | IDA-backed method boundaries, vtable xrefs, traversal callers, field offsets, and cleanup-helper byte/xref evidence support this iterator class. Confidence is capped because the exact original header factoring remains unresolved. |
| Assignment | [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | The child is `85/86`, the direct file parent is `89/85`, and current evidence supports `FolderTreePane.cpp` as the source owner for the local tree-iterator template support. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md)
- [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the concrete iterator traversal methods, FolderTreePane ownership, tree-element/vtable/template links, and remaining uncertainty around original template spelling/source artifact.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed exact iterator method boundaries, the named `TreeItor<FolderTreePane::TreeElem>` vtable at `0x0061a510`, vtable slot/data xrefs, direct FolderTreePane traversal callers, and traversal field accesses matching the documented 36-byte tree element layout.
  - Remaining limits: scores stay below final-source level because exact original template spelling/header factoring and final public method names remain inferred.
- 2026-06-08 A009 Batch117 parent-gate refresh:
  - What existed before: score `82/84`, with stale direct-parent gate evidence and no exact child pages for the two tiny iterator cleanup helpers summarized by the aggregate.
  - Changed to: score `85/86`, retained `AUTOGEN_PARENT_UID:0000JG`, linked the exact cleanup helper pages, and added an explicit score/assignment rationale.
  - Summary/evidence: current documentation plus Batch117 IDA rechecks confirm the iterator vtable at `0x0061a510`, traversal method ranges/callers, tiny cleanup helper bodies at `0x004b57f0-0x004b57f8` and `0x004b5800-0x004b580e`, direct `FolderTreePane.cpp` file parent `89/85`, and template-context page `85/89`.
