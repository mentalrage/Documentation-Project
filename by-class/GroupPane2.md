*** UID:00005Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupPane2

## Status

- Confidence: strong for current behavior; medium for exact original split from `GroupPane`.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md); exact vtable data [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md); destructor thunks at [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_GroupPane2.cpp`
- Autogen parent: [UID:0000JS][Group](by-file/Group.md). This class is `85/88`, and the direct file parent is `89/85` after the Batch 067 parent-gate refresh.

## Class Purpose

`GroupPane2` is an alternate group-list panel shell. It builds the same non-editable `0x174`-byte `GroupListPane` child pattern as `GroupPane`, stores the child at object offset `0xf8`, refreshes the list viewport, and draws a tab/background frame from `GROUP.EPF` with `TABS.PAL`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupPane2` | `0x0056c770-0x0056c860` | Constructs the alternate group panel and list child. |
| `~GroupPane2` | `0x0056c870-0x0056c8db` | Destroys child and base panel state. |
| `RefreshGroupListDisplayArea` | `0x0056c8e0-0x0056c96e` | Repositions and scroll-syncs the list child. |
| `DrawTabBackground` | `0x0056c970-0x0056c9e0` | Draws tab/background art through EPF and palette managers. |
| false/default virtual stub | `0x0056c4a0-0x0056c4b5` sibling island | Tiny `return false` stubs adjacent to the group pane constructors; exact class slot still open. |
| trivial virtuals | `0x0056c9f0`, `0x0056ca00` | Small return stubs in IDA. |
| scalar deleting destructor | `0x005733e0-0x0057348d` | Virtual destructor wrapper; documented in [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md). |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- The constructor pattern is nearly identical to `GroupPane`, supporting a same-file or same-feature original source placement.
- The constructor inlines the `GroupListPane` child setup and installs the child vtables `0x00624214`, `0x0062428c`, and `0x006242bc`.
- Secondary and tertiary destructor entries use compiler adjustor thunks at `0x00573273` and `0x0057327e`; these should be generated from the inheritance layout rather than written as source methods.
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md): the range starts at `GroupPane2` RTTI and ends before `NewGroupPane`.
- The 2026-06-07 vtable-family refresh recorded on [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md) and [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md) reconfirms all three `GroupPane2` table-base store sets from constructor `0x0056c770`, destructor `0x0056c870`, and scalar deleting destructor `0x005733e0`, plus the draw/layout/stub function extents.
- `GroupPane2` likely represents a variant shell rather than a separate gameplay feature.
- 2026-05-28 IDA MCP identifies the adjacent `0x0056c4a0` and `0x0056c4b0` false virtual stubs; keep them with the group pane family until exact slot ownership is confirmed.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The class page now records constructor/destructor/layout/draw/stub/scalar-destructor coverage, exact vtable-data child, adjustor thunk children, sibling false-virtual caveat, and direct source-file parent route. Completion stays below final because the exact original split from `GroupPane`, final field names, and full class declaration remain unresolved. |
| Confidence `88` | Existing IDA-backed memory pages and the 2026-06-07 vtable refresh strongly support `GroupPane2` method and vtable ownership. Confidence remains below final because the class is an alternate shell with some source-split uncertainty against `GroupPane` and inherited pane/control slots. |

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs](by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md)
- [UID:00005Y][GroupPane](by-class/GroupPane.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)

## Changes

- 2026-06-07 Batch 067 parent-chain repair:
  - Before: `COMPLETION:81`, `CONFIDENCE:86`, and blank `AUTOGEN_PARENT_UID`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000JS`.
  - Evidence: this page now uses the exact [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md) child, destructor/thunk pages, method inventory, and refreshed [UID:0000JS][Group](by-file/Group.md) parent gate to support class routing.
- 2026-05-28: Added the adjacent `0x0056c4a0-0x0056c4b5` false virtual stub island.
  - Before: `GroupPane2` documentation did not account for the two real false-return stubs before `GroupPane`.
  - After: the stubs are recorded as group-pane-family support code with exact slot ownership still open.
  - Evidence: IDA MCP reports two `xor al, al; retn 4` functions at `0x0056c4a0` and `0x0056c4b0`.
- 2026-05-28: Corrected the scalar deleting destructor endpoint.
  - Before: this page listed `0x005733e0-0x0057348c`.
  - After: the destructor is `0x005733e0-0x0057348d` and is linked through [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md).
  - Evidence: IDA MCP reports `sub_5733e0` as ending at `0x0057348d`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/80`. Summary: alternate group-panel behavior, list-child setup, method inventory, destructor/thunk handling, vtable family, and false-virtual stubs are documented; exact original split from `GroupPane` remains medium-confidence. Evidence: `GroupPanes`, `GroupPaneFamilyVtables`, `GroupPaneAdjustorThunks`, `CollectionAndGroupPaneDestructors`, and sibling `GroupPane` cross-references.
- 2026-05-31: Added exact vtable-data child and raised metadata from `78/80` to `81/86`.
  - Before: vtable evidence was only linked through the family page.
  - After: exact vtable-data bounds, constructor/destructor stores, and adjustor-thunk slots are linked directly.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks on `0x006244c4-0x00624550` confirmed the RTTI boundaries and store sites.
