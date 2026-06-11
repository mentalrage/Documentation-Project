*** UID:0000JG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FolderTreePane

## Status

- Confidence: strong for filesystem-tree control ownership and `FolderTreePane.cpp` placement; medium-high for final header factoring and field names.
- Proposed source file: `ui/controls/FolderTreePane.cpp`
- Proposed header: `ui/controls/FolderTreePane.h`
- Current recovered source: `source-3/simroot_v2/class_FolderTreePane.cpp`, plus generated template helper files.
- Main class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Primary consumers: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) and [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- Main address docs: [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md), [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md), and [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md)
- Vtables: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- Evidence basis: Wave3 generated source, generated metadata, and IDA MCP boundary/decompilation/xref checks on 2026-05-24 through 2026-05-26.

## File Role

`FolderTreePane.cpp` owns a scrollable filesystem tree pane. It inherits from `ScrollablePane`, stores a `Tree<FolderTreePane::TreeElem>` at offset `0x130`, stores the selected iterator at offset `0x170`, loads the folder icon frame resource, expands filesystem directories lazily through `FindFirstFileA`/`FindNextFileA`, sorts child folder names, paints visible rows, handles keyboard/mouse navigation, and returns the selected path to the owning dialog.

This is a UI control, not a chat module. The active generated `class_FolderTreePane.cpp` also contains chat message, surface, screenshot capture, and help/system-message code; those sections are documented as owner pollution and should not be migrated into this file without a focused ownership review.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `FolderTreePane` | `0x004b1b90-0x004b32c9`, [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), destructor at `0x004b5a70` | Scrollable tree pane constructor, layout, paint, input, selection, and destruction. |
| `FolderTreePane::TreeElem` | 36-byte node record | Tree node links, display name, row/depth, loaded/expanded flags; see [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md). |
| `TreeStorage<FolderTreePane::TreeElem>` | `0x004b3d50`, `0x004b56e0` | Vector-like storage for 36-byte tree-node records; generated class [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md). |
| `Tree<FolderTreePane::TreeElem>` | cleanup `0x004b5650`, scalar destructor `0x004b59f0`, reset `0x004b5b00` | Container destructor/reset support for the embedded tree; generated class [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md). |
| `TreeItor<FolderTreePane::TreeElem>` | `0x004b5670`, `0x004b5a40`, `0x004b5bb0-0x004b5c3f` | Iterator destruction and visible traversal helpers; generated class [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md). |
| vector/string support helpers | [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) | Non-source-facing helper machinery for folder-tree node/directory-entry copy, destruction, and storage free paths; mostly generated from container/template support. |
| directory-entry scratch vector/sort helpers | `0x004b3fb0-0x004b57dd` | Local helper code used while collecting and sorting child directory names. |

## Evidence Notes

- IDA confirms `FolderSelectDialog` constructs this pane at `0x004b178b`; no other constructor callers were found in the 2026-05-24 xref check.
- The constructor at `0x004b1b90` calls a `ScrollablePane` base constructor, initializes the embedded tree and iterator, loads the folder icon through `g_pEPFLibrary`, names the root node, expands it, and refreshes layout.
- `FindFirstVisibleChild` at `0x004b1d50` reconstructs the current node's full filesystem path, enumerates visible subdirectories, sorts them, inserts child `TreeElem` records, and marks the node expanded.
- `SelectNodeByPath` at `0x004b2730` splits a path on `\\` and `/`, compares components case-insensitively against loaded child nodes, expands as needed, and updates selection.
- `0x004b3090` builds the selected path by walking parent links and prepending names. It is called from `FolderSelectDialog::OnCommand`.
- The generated source currently drops the active body for [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md); IDA shows it copies the iterator, computes node bounds, scrolls the selected row into view, and invalidates/updates the pane. Track this with the shared [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) note.
- 2026-05-25 recheck: `0x004b5650` is real destructor-shaped cleanup for the embedded tree, but IDA associates it with the `FolderTreePane` constructor exception-unwind region. It has an EH-thunk xref at `0x005fe944` and no ordinary direct callers, so treat it as tree cleanup support rather than a standalone original source method.
- 2026-05-26 recheck: `0x004b59d5-0x004b59eb` are compiler-generated destructor adjustor thunks into `0x004b5a70`, not handwritten `FolderTreePane` behavior. They are documented in [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) and listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA vtable pass confirms the `Tree`, `TreeItor`, and three-view `FolderTreePane` vtables at `0x0061a500`, `0x0061a510`, `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`. Current metadata still reports `vtable_count: 0`; see [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md).
- The tertiary vtable ends before `0x0061a5c4`, where UTF-16 `TREEICON.EPF` string data begins. Do not treat `0x00520054`, `0x00450045`, or `0x00430049` string dwords as `FolderTreePane` virtual methods.
- 2026-06-08 Batch 110 IDA MCP refresh reconfirmed the direct parent gate for [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md): the concrete `Tree<FolderTreePane::TreeElem>` helper starts remain `0x004b3d50` size `0x254`, `0x004b55e0` size `0x6d`, `0x004b56e0` size `0x7f`, `0x004b5b00` size `0xae`, `0x004b5bb0` size `0x20`, `0x004b5bd0` size `0x43`, and `0x004b5c20` size `0x1f`; `Tree` vtable refs at `0x0061a500` land in constructor/cleanup/destructor paths, and the `TreeItor` vtable at `0x0061a510` has 31 refs spanning constructor, traversal, iterator cleanup, and destructor helpers.

## Ownership Cleanup

Current active Wave3 ownership under `FolderTreePane` includes unrelated or weakly related groups:

- `0x0047f280-0x004805d4`: chat-message add/decode methods documented under [UID:0000I5][Chatting](by-file/Chatting.md) and [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).
- `0x004b8be0`, `0x004b9820-0x004ba24a`, and `0x00557140-0x00559aef`: generic DirectDraw/surface helpers documented under [UID:0000OC][Surface](by-file/Surface.md), [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md), [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md), and [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md).
- `0x00557aa0-0x00558391`: screenshot BMP/PNG capture and proof submission documented under [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) and [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md).
- `0x00585360-0x0058a8e0`: help/system-message methods documented under [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).

The local filesystem-tree source should be built from the `0x004b1b90-0x004b32c9` core plus the `0x004b3350-0x004b5c3f` tree/sort helpers and adjacent [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md), not by migrating the whole active generated `class_FolderTreePane.cpp`.

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md)
- [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: the existing file page and proposed source-tree entry treat this as a reusable filesystem tree control; IDA MCP recheck confirms construction from [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) at `0x004b178b`, vtable stores for the three `FolderTreePane` views, and selection/path helpers used by the dialog.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: filesystem tree-control role, proposed contents, core/tree/vector helper ranges, vtables/layout types, IDA evidence, generated owner-pollution exclusions, missing body notes, and control/dialog split caveat are documented; confidence is strong but exact standalone-versus-private source split remains medium.
- 2026-06-08 A005 Batch 110 parent-gate refresh:
  - What existed before: score `88/80`, below the corrected `85/85` parent-side assignment gate for the local folder-tree template page.
  - Changed to: score `89/85`.
  - Summary/evidence: live IDA MCP reconfirmed the exact concrete tree/template helper starts, `Tree` and `TreeItor` vtable refs, three `FolderTreePane` vtable stores, and the existing owner-pollution exclusions. The file page now clears the parent-side gate for direct `FolderTreePane.cpp` template-support children, while final header factoring and field names still cap confidence at `85`.
