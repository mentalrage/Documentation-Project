*** UID:00005Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00005Z] no class-level C++ body.
// GroupPane2 behavior is documented through exact constructor/destructor/vtable child evidence;
// this class page remains the declaration/source-split audit until the final header declaration is ready.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GroupPane2

## Status

- Confidence: strong for current behavior; medium for exact original split from `GroupPane`.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md); exact vtable data [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md); destructor thunks at [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_GroupPane2.cpp`
- Autogen parent: [UID:0000JS][Group](by-file/Group.md). This class is `85/88`, and the direct file parent is `90/86` after the B002 Group empty-emitter implementation.
- Reconstruction C++: formal no class-level body marker plus `[[CHILDREN]]`; exact behavior and compiler-emitted data remain documented through child pages until the final header/source split is ready.

## Class Purpose

`GroupPane2` is an alternate group-list panel shell. It builds the same non-editable `0x174`-byte `GroupListPane` child pattern as `GroupPane`, stores the child at object offset `0xf8`, refreshes the list viewport, and draws a tab/background frame from `GROUP.EPF` with `TABS.PAL`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupPane2` | `0x0056c770-0x0056c860` | Constructs the alternate group panel and list child. |
| `~GroupPane2` | `0x0056c870-0x0056c8db` | Destroys child and base panel state. |
| `RefreshGroupListDisplayArea` | `0x0056c8e0-0x0056c96e` | Repositions and scroll-syncs the list child. |
| `OnPaint` | `0x0056c970-0x0056c9e1` | Exact child [UID:00050S][0x0056c970-0x0056c9e1.GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) resolves `TABS.PAL`, looks up frame `0` of `GROUP.EPF`, and blits the EPF context into `m_visibleBounds`. |
| predecessor LegendPane overrides | `0x0056c4a0-0x0056c4b5` | Boundary context only: exact bool `LegendPane::HandleKeyOrTextEvent(Event *)` and `LegendPane::OnMouseEvent(Event *)` source belongs to UID00023W, not GroupPane2. |
| trivial virtuals | `0x0056c9f0-0x0056c9f5`, `0x0056ca00-0x0056ca05`, `0x0056ca10-0x0056ca15` | Small return stubs in the `GroupPane2` secondary table. |
| scalar deleting destructor | `0x005733e0-0x0057348d` | Virtual destructor wrapper; documented in [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md). |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- The constructor pattern is nearly identical to `GroupPane`, supporting a same-file or same-feature original source placement.
- The constructor inlines the `GroupListPane` child setup and installs the child vtables `0x00624214`, `0x0062428c`, and `0x006242bc`.
- B001 Rule 26 reanalysis of [UID:00005X][GroupListPane](by-class/GroupListPane.md) clarifies the inline child setup: the constructor allocates a `0x174` `GroupListPane`, loads [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md), calls [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) as a `g_useEpfAssets` display-mode query, calls [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md), stores the child at `+0xf8` as `GroupListPane *m_groupListPane`, enables it with [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), and then uses `sub_58EA80` as a role-level `TextEditPane` editability/activation setter. The old "resource/context pointer from `sub_4B60B0`" interpretation is rejected.
- Secondary and tertiary destructor entries use compiler adjustor thunks at `0x00573273` and `0x0057327e`; these should be generated from the inheritance layout rather than written as source methods.
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md): the range starts at `GroupPane2` RTTI and ends before `NewGroupPane`.
- The 2026-06-07 vtable-family refresh recorded on [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md) and [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md) reconfirms all three `GroupPane2` table-base store sets from constructor `0x0056c770`, destructor `0x0056c870`, and scalar deleting destructor `0x005733e0`, plus the draw/layout/stub function extents.
- `GroupPane2` likely represents a variant shell rather than a separate gameplay feature.
- 2026-08-14 read-only MCP and exact child reconstruction confirm the former role-level `DrawTabBackground` body is the primary-vtable `GroupPane2::OnPaint` override. It spans `[0x0056c970,0x0056c9e1)`, is 113 bytes with SHA256 `FD4698757D9BFFA6D1FFD9254A7BD71D28566ACAE9B6DE5E87F4BF01FB95BDAE`, and has 43 instructions. Operands at `0x0056c999` and `0x0056c9ad` select `TABS.PAL` and [UID:0003F0][0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString](by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md); vtable slot `0x0062450c` establishes the virtual identity. The position-40 child owns the complete body and routes through the class page's existing single `[[CHILDREN]]` token.
- 2026-06-18 B001 reanalysis corrects the `0x0056c4a0` and `0x0056c4b0` stubs to `LegendPane` predecessor-boundary context. They do not belong to `GroupPane2` source content; `GroupPane2` owns the small local stubs at `0x0056c9f0`, `0x0056ca00`, and `0x0056ca10`.

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
- [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) - exact predecessor LegendPane input overrides; boundary context only.
- [UID:00005Y][GroupPane](by-class/GroupPane.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- [UID:00050S][0x0056c970-0x0056c9e1.GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) - exact source-bearing `GroupPane2::OnPaint` child.
- [UID:0003F0][0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString](by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md) - pooled `GROUP.EPF` literal reconstructed at method use sites.

## Changes

- 2026-08-14 B004 UID0003F0 accepted callback: corrected `DrawTabBackground` to the vtable-backed `GroupPane2::OnPaint` identity and exact endpoint, attached the position-40 method child through the existing unique CPP `[[CHILDREN]]` token, and retained blank formal H.
- 2026-07-16 B001 UID00023W accepted implementation callback: synchronized the predecessor boundary to the exact LegendPane key/text and mouse overrides while preserving all GroupPane2 ownership, scores, formal C++, and unrelated class evidence.
- 2026-06-30 B002 Group empty-emitter implementation:
  - Inserted the formal no class-level C++ body marker plus `[[CHILDREN]]` so exact child data/method rows still assemble under this class route.
  - Preserved the current `GroupPane2` source-split caveat against `GroupPane` while routing behavior through exact child pages.
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
- 2026-06-20 B001 GroupListPane source-quality incorporation:
  - Score unchanged at `85/88`.
  - Added corrected inline `GroupListPane` child setup semantics for `g_pFontImageLib`, `IsLegacyAssetMode`, `TextEditPane::TextEditPane`, `Pane::SetMode(1)`, `sub_58EA80`, and parent `+0xf8` child ownership.
