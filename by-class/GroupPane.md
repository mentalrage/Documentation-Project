*** UID:00005Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:81 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupPane

## Status

- Confidence: strong for current behavior; medium for relationship to `GroupPane2` and `NewGroupPane`.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md); exact vtable data [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md); destructor thunks at [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_GroupPane.cpp`

## Class Purpose

`GroupPane` is an older group-list panel shell. It constructs a panel, allocates a `0x174`-byte `GroupListPane`/text child at object offset `0xf8`, keeps the child visible and non-editable, refreshes a fixed viewport, and paints the `GROUP.EPF` background.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupPane` | `0x0056c4c0-0x0056c5b0` | Constructs the panel and list child. |
| `~GroupPane` | `0x0056c5c0-0x0056c62b` | Destroys the child and base panel. |
| `RefreshGroupListDisplayArea` | `0x0056c630-0x0056c6be` | Repositions the list child and invalidates the panel. |
| `OnPaint` | `0x0056c6c0-0x0056c730` | Loads and draws `GROUP.EPF`. |
| false/default virtual stub | `0x0056c4a0-0x0056c4a5` or sibling slot | Tiny `return false` stub adjacent to the group pane constructors; exact class slot still open. |
| trivial virtuals | `0x0056c740`, `0x0056c750` | Small return stubs in IDA. |
| scalar deleting destructor | `0x00573490-0x0057353d` | Virtual destructor wrapper; documented in [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md). |

## Evidence Notes

- IDA MCP confirms all listed function starts except no separate evidence for a named source file.
- `GroupPane2` mirrors most of this behavior with a separate constructor/destructor and tab/background draw path.
- The constructor inlines the `GroupListPane` child setup and installs the child vtables `0x00624214`, `0x0062428c`, and `0x006242bc`.
- The separate `GroupListPane` constructor at `0x0056baa0` is a raw/manual IDA boundary with no call xrefs, not an arbitrary data range.
- Secondary and tertiary destructor entries use compiler adjustor thunks at `0x00573289` and `0x00573294`; these should be generated from the inheritance layout rather than written as source methods.
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md): the range starts after `LegendPane` and ends before `GroupPane2`.
- 2026-05-28 IDA MCP identifies two adjacent false virtual stubs at `0x0056c4a0` and `0x0056c4b0` before the `GroupPane` constructor range. Their exact slot ownership across `GroupPane`/`GroupPane2` remains open, but they belong with the group pane family rather than `LegendPane`.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs](by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md)
- [UID:00005Z][GroupPane2](by-class/GroupPane2.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- [UID:00005X][GroupListPane](by-class/GroupListPane.md)

## Changes

- 2026-05-28: Added the adjacent `0x0056c4a0-0x0056c4b5` false virtual stub island.
  - Before: `GroupPane` documentation began at `0x0056c4c0` and did not account for the real stubs immediately before it.
  - After: the stubs are recorded as group-pane-family support code while the constructor range remains unchanged.
  - Evidence: IDA MCP reports two `xor al, al; retn 4` functions at `0x0056c4a0` and `0x0056c4b0`.
- 2026-05-28: Corrected the scalar deleting destructor endpoint.
  - Before: this page listed `0x00573490-0x0057353c`.
  - After: the destructor is `0x00573490-0x0057353d` and is linked through [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md).
  - Evidence: IDA MCP reports `sub_573490` as ending at `0x0057353d`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/80`. Summary: class purpose, child layout, method inventory, destructor/thunk handling, raw child constructor relationship, and false-virtual stub island are documented; confidence is capped by the still-open relationship to `GroupPane2` and `NewGroupPane`. Evidence: `GroupPanes`, `GroupPaneFamilyVtables`, `GroupPaneAdjustorThunks`, `CollectionAndGroupPaneDestructors`, and `GroupPaneFalseVirtualStubs` cross-references.
- 2026-05-31: Added exact vtable-data child and raised metadata from `78/80` to `81/86`.
  - Before: vtable evidence was only linked through the family page.
  - After: exact vtable-data bounds, constructor/destructor stores, and adjustor-thunk slots are linked directly.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks on `0x00624438-0x006244c4` confirmed the RTTI boundaries and store sites.
