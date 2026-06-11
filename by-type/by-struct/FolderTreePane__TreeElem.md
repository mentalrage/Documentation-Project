*** UID:0001UJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00005A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane::TreeElem

## Status

- Confidence: strong for size and major fields; medium for exact field names.
- Owner class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Owner file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Related memory: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Current generated aliases: `TreeStorageFolderTreeElemRecord`, `struct_FolderTreePane::TreeElem`
- Reconstructable: true. This is a NexusTK-authored tree node record required by `FolderTreePane`; it is attached to the owning `FolderTreePane` class after Batch 127 raised the class parent to `85/86`.

## Layout Hypothesis

Generated storage helpers and IDA decompilation agree that each tree node record is 36 bytes (`0x24`). The first five dwords are tree links/state, followed by a `SimpleUString`-style name object and visible-row metadata.

| Offset | Size | Provisional field | Evidence |
| --- | --- | --- | --- |
| `0x00` | 4 | `parentIndex` | `MoveToParent` reads this field; root is initialized to `-1`. |
| `0x04` | 4 | `firstChildIndex` | `MoveToFirstChild` reads this field; root/reset initializes to `-1`. |
| `0x08` | 4 | `lastChildIndex` | `FindFirstVisibleChild` seeds this with the first inserted child and later updates the parent record when another child is appended. |
| `0x0c` | 4 | `prevSiblingIndex` | Link/state field copied by storage helpers; Batch 127 insertion-context review supports previous-sibling semantics, but final source name remains provisional. |
| `0x10` | 4 | `nextSiblingIndex` | `MoveToNextVisibleSibling` reads this field. |
| `0x14` | 4 | `name` | Ref-counted/simple string handle copied by `sub_582A90`, destroyed by `sub_582B70`, and read by `GetNodeBounds` through `sub_584540`. |
| `0x18` | 2 | `row` | `GetNodeBounds` multiplies this signed word by `16` for the top Y coordinate. |
| `0x1a` | 2 | `depthOrIndent` | `GetNodeBounds` multiplies this signed word by `16` for left indentation. |
| `0x1c` | 1 | `childrenEnumerated` | `FindFirstVisibleChild` checks this before enumerating children and sets it to `1` after a successful lazy directory scan. |
| `0x1d` | 1 | `isExpanded` | `FindFirstVisibleChild` sets this when expansion succeeds; `CollapseNode` clears `node + 0x1d`; key/mouse logic reads the same flag. |
| `0x1e` | 2 | padding/reserved | Not named yet. |
| `0x20` | 1 | `hiddenOrDeleted` | `MoveToNextVisibleSibling` skips records when this byte is nonzero. IDA recheck confirms this exact byte. |
| `0x21` | 3 | padding/reserved | Required to reach 36-byte size. |

## Evidence Notes

- `TreeStorage_struct_FolderTreePane__TreeElem_::InsertAt` copy-constructs records at 36-byte stride and copy-constructs/destroys the `SimpleUString` at offset `0x14`.
- `Tree_struct_FolderTreePane__TreeElem_::ResetToSingleRoot` creates one record and initializes the first five dwords to `-1`.
- `TreeItor_struct_FolderTreePane__TreeElem_::MoveToParent`, `MoveToFirstChild`, and `MoveToNextVisibleSibling` read offsets `0x00`, `0x04`, and `0x10`.
- The generated `OnKeyEvent`, `OnMouseEvent`, `GetNodeBounds`, and copy-constructor helper views disagree slightly on the inline `SimpleUString`/metadata split. Treat offsets `0x1c-0x21` as provisional until a focused layout pass reconciles loaded, expanded, hidden, and deleted semantics.
- 2026-05-31 IDA MCP `lookup_funcs` confirms exact starts/sizes for the main layout users: insert `0x004b3d50` size `0x254`, copy constructor helper `0x004b55e0` size `0x6d`, storage destructor `0x004b56e0` size `0x7f`, reset-to-root `0x004b5b00` size `0xae`, iterator first-child `0x004b5bb0` size `0x20`, next-visible-sibling `0x004b5bd0` size `0x43`, and parent `0x004b5c20` size `0x1f`.
- 2026-05-31 IDA MCP decompilation of `0x004b55e0` proves the 36-byte record copy shape: five dwords at `+0x00..+0x10`, string handle at `+0x14`, words at `+0x18/+0x1a`, bytes at `+0x1c/+0x1d`, and byte at `+0x20`.
- 2026-05-31 IDA MCP decompilation of `0x004b5b00` destroys each record string at `record + 0x14`, rewinds storage, and creates one root record. Direct IDA byte read of `xmmword_619660` shows the first four root dwords are all `-1`, with the fifth dword also initialized to `-1` by the local `v6` before insertion.
- 2026-05-31 IDA MCP decompilation confirms iterator accessors: `0x004b5bb0` reads `record + 0x04` as first child, `0x004b5bd0` reads `record + 0x10` as next sibling and skips records with byte `+0x20` set, and `0x004b5c20` reads `record + 0x00` as parent.
- 2026-05-31 IDA MCP decompilation confirms UI field use: `CollapseNode` at `0x004b2540` clears byte `+0x1d`, and `GetNodeBounds` at `0x004b3010` uses word `+0x1a` for left indentation and word `+0x18` for row Y position.
- 2026-06-08 Batch 127 IDA MCP decompilation of `FindFirstVisibleChild` at `0x004b1d50` confirms byte `+0x1c` gates lazy child enumeration and is set to `1` after the child directory scan, while byte `+0x1d` is set when the node becomes expanded. The same pass shows the first/last child linkage: a first inserted child updates parent offsets `+0x04` and `+0x08`, later sibling appends update the previous node's `+0x10` next link and the parent's `+0x08` last-child link.
- Batch 127 also reconfirmed `0x004b55e0` as the exact copy-constructor helper for this 36-byte record and `0x004b56e0` as the storage destructor that destroys only the embedded string handle at `+0x14` before freeing storage.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | Exact size, owner class/file, field offsets, nested tree/template users, copy construction, destruction, lazy-enumeration flags, child/sibling/parent links, row/depth use, and direct parent gate are documented. Completion remains below final-source quality because the exact original field names and reusable-template declaration spelling remain provisional. |
| Confidence | 88 | Live IDA evidence consistently matches the 36-byte layout across construction, insertion, copy, destruction, expand/collapse, bounds, and iterator traversal paths. Confidence remains below final audit because some source-facing names are inferred from behavior rather than recovered symbols. |
| Assignment | [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) | The struct is a nested `FolderTreePane::TreeElem`; the child now scores `85/88`, the owning class scores `85/86`, and [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is the file parent at `89/85`. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md)
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md)
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)

## Changes

- 2026-06-08 A006 Batch 127 layout and parent-gate refresh:
  - What existed before: score `76/86`, reconstructable, with `AUTOGEN_PARENT_UID` blank and several flag/link fields still weakly named.
  - Changed to: score `85/88` and `AUTOGEN_PARENT_UID:00005A`.
  - Summary/evidence: live IDA decompilation of `FindFirstVisibleChild`, `CollapseNode`, `GetNodeBounds`, iterator helpers, copy construction, and storage destruction resolved the lazy-enumeration byte at `+0x1c`, expanded byte at `+0x1d`, last-child link at `+0x08`, next-sibling link at `+0x10`, hidden/deleted byte at `+0x20`, and string lifetime at `+0x14`. The direct class parent now clears the corrected gate.
- 2026-05-31:
  - What existed before: the page had a useful generated-layout hypothesis but was still scored `0/0`, had `RECONSTRUCTABLE` blank, and treated the string/metadata split at `+0x14` as uncertain.
  - Changed to: scored `76/86`, marked reconstructable, and refined the proven field split from IDA MCP decompilation of copy, reset, iterator, collapse, and bounds helpers.
  - Summary/evidence: IDA confirms the 36-byte record stride, five leading link/state dwords, 4-byte string handle at `+0x14`, row/depth words at `+0x18/+0x1a`, expanded byte at `+0x1d`, and hidden/deleted byte at `+0x20`. Final names for `+0x08`, `+0x0c`, and `+0x1c` remain below the 95+ threshold.
