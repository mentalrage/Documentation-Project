*** UID:0000JG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FolderTreePane

## Current Accepted UID0004YK Consumer Placement

FolderTreePane remains the ui/controls consumer of reusable NexusTK/util/Tree.h. Its header embeds Tree<FolderTreePane::TreeElem> and TreeItor<FolderTreePane::TreeElem>; its CPP owns only folder enumeration, rendering, hit testing, visible navigation, and concrete visitor/context policy. Generic links, reset, traversal skeleton, iterator movement, std::vector storage, and inline virtual destruction belong to Tree.h. Concrete 0x24 vector lowering and Tree/TreeItor destructor-vtable-RTTI-EH bodies are compiler-generated evidence, not duplicate FolderTreePane.cpp source. Historical local TreeStorage/header factoring and lifecycle prose below is superseded.

## Status

- Confidence: very strong for filesystem-tree control ownership, `FolderTreePane.h/.cpp` placement, shared Tree-header boundary, and separation from FolderSelectDialog; medium-high for exact original private spellings.
- Proposed source file: `ui/controls/FolderTreePane.cpp`
- Proposed header: `ui/controls/FolderTreePane.h`
- Historical generated-source lead: `source-3/simroot_v2/class_FolderTreePane.cpp`, plus generated template helper files. Treat these as old generated leads/provenance only, not current authority for UID0002MX, `FolderTreeStorage`, or the current `FolderTreePane.cpp` source route.
- Main class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Primary embedding dialog: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md); [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) reaches this control indirectly by opening the folder-selection dialog.
- Main address docs: [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md), [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), non-emitting split/index [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md), and [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md)
- Vtables: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- Current evidence basis: current by-* docs, accepted B-agent reports, and IDA MCP boundary/decompilation/xref checks. Wave3/simroot/recovered-source material is historical generated lead material only and must be rechecked before driving ownership, source-route, or emitted-C++ decisions.

## File Role

`FolderTreePane.cpp` owns a scrollable filesystem tree pane. It inherits from `ScrollablePane`, stores a `Tree<FolderTreePane::TreeElem>` at offset `0x130`, stores the selected iterator at offset `0x170`, loads the folder icon frame resource, expands filesystem directories lazily through `FindFirstFileA`/`FindNextFileA`, sorts child folder names, paints visible rows, handles keyboard/mouse navigation, and returns the selected path to the owning dialog.

B014's accepted 2026-06-19 FolderSelectDialog source-quality pass closes the current dialog/control split: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) owns the modal picker, drive-list setup, callback dispatch, drive-root literal/buffer, and `m_folderTreePane` member pointer; this file owns the reusable `FolderTreePane` control, `FolderTreePane::SetRootNodeName`, `FolderTreePane::SelectNodeByPath`, selected-path construction, tree/template helpers, and vtables. Do not move FolderTreePane bodies into `FolderSelectDialog.cpp` merely because the checked constructor xrefs currently show FolderSelectDialog as the direct creator.

This is a UI control, not a chat module. The active generated `class_FolderTreePane.cpp` also contains chat message, surface, screenshot capture, and help/system-message code; those sections are documented as owner pollution and should not be migrated into this file without a focused ownership review.

B006's 2026-06-29 vtable-data repair keeps [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) and [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) into this generated file, but only as formal comment-only no-code markers. `FolderTreePane.cpp` should emit the class declaration, method bodies from exact ready children, and trace comments for these compiler-emitted vtable layout/data pages; it should not hand-author raw vtable arrays, adjustor thunk bodies, constructor EH cleanup fragments, or scalar deleting destructor glue.

## Historical Superseded 2026-06-30 B010 Empty-Emitter Family Implementation

B010's accepted [UID:0000JG] family report closes the current generated empty-emitter queue for the FolderTreePane tree/template/traversal/sort family. Current MCP session `supervisor_resume_20260629` was active and healthy for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and strings cache size `2067`. The generated source checked before implementation was `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` with `validator-command-id:000000002992`, `validator-refreshed-at:2026-06-30T15:03:31-04:00`, source UID `0000JG`, and fourteen empty markers.

The accepted disposition keeps this file as the `NexusTK/ui/controls/FolderTreePane.cpp` source root and raises this page from `89/85` to `91/90`. Completion increases because every accepted empty marker now has a formal implementation disposition. Confidence increases because the current MCP pass reconfirmed function boundaries, caller/callee routes, source-authored versus compiler-generated classification, and the remaining uncertainty is limited to exact original helper names and final shared `Tree<T>` header factoring.

Applied family dispositions:

| UID | Formal generated handling | Source-quality decision |
| --- | --- | --- |
| [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) | Formal `FolderTreePane::TreeElem` declaration with `[[CHILDREN]]`. | 36-byte nested record with accepted link/name/row/depth/flag fields; `previousSiblingIndex` remains explicitly inferred. |
| [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) | Formal `TreeStorage<T>` declaration with begin/end/capacity and `[[CHILDREN]]`. | Local/template support through this file, not a standalone generated source file. |
| [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) | Formal `Tree<T>` declaration with inline empty virtual destructor, traversal method declarations, and `[[CHILDREN]]`. | Direct semantic owner of UID000158; concrete tree wrapper remains emitted through FolderTreePane while likely shared-header factoring stays a bounded caveat. |
| [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) | Formal template forward declarations and `[[CHILDREN]]`. | Concrete `TreeStorage`, `Tree`, and `TreeItor` specializations remain attached to FolderTreePane until a scored shared tree-template owner exists. |
| [UID:000346][0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal](by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md) | First-draft `Tree<FolderTreePane::TreeElem>::HitTestVisibleNodes` body. | Current MCP shows callers `sub_4B2680` and `sub_4B2DC0`, deque-backed traversal, bounds computation from row/depth/name, hit-test storage into the context, and child descent through expanded `lastChildIndex`/`previousSiblingIndex`. |
| [UID:000347][0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch](by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md) | First-draft `Tree<FolderTreePane::TreeElem>::FindVisibleNavigationNode` body. | Current MCP shows caller `sub_4B2B80`, the same pending traversal, current/target iterator comparisons, found-state update, and expanded-child descent. |
| [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) | First-draft `PaintFolderTreeNode` body. | Current MCP shows sole caller [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md), pane/context read, row/depth/name/selection drawing state, and return `0` descend or `2` skip. |
| [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) | Formal no-code comment. | Scalar deleting destructor glue regenerated by the virtual destructor, storage cleanup, and delete semantics; no ordinary callers. |
| [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) | Formal UID0000F9 covered-by marker. | Exact retained complete-object Tree destructor body selected by constructor unwind state 3; its source cause is UID0000F9's inline virtual destructor, not a handwritten vptr/member/base/EH body. |
| [UID:000348][0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt](by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md) | Formal no-code comment. | Compiler/vector insert-grow support for the local 12-byte `DirectoryEntry` scratch vector in `ExpandNode`. |
| [UID:000349][0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort](by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md) | Formal no-code comment. | MSVC/Dinkumware insertion-sort support from the high-level child-directory sort expression. |
| [UID:00034A][0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3](by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md) | Formal no-code comment. | Median/order-three compare-swap support for the same local sort expression; current filename is a historical alias. |
| [UID:00034D][0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper](by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md) | Formal no-code comment. | MSVC/Dinkumware introsort driver reached from lazy expansion and recursively from itself; source should remain the owning sort expression. |
| [UID:00034E][0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap](by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md) | Formal no-code comment. | 12-byte `DirectoryEntry` swap support called from the median/order-three helper; not handwritten project source. |

Rejected alternatives preserved from the report: do not clear emitters, do not create standalone generated tree/storage source files, do not move this family to FolderSelectDialog/GrafPort/StringBase/STL ownership, do not hand-port scalar deleting destructors/EH cleanup/vector/sort internals, and do not leave live traversal helpers blank merely because context/helper names are inferred.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `FolderTreePane` | `0x004b1b90-0x004b32c9`, [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), destructor at `0x004b5a70` | Scrollable tree pane constructor, layout, paint, input, selection, and destruction. `SetSelection` now has source-shaped formal C++ using `GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition`, inherited `m_contentRect`, and `InvalidateRect(NULL)`. |
| `FolderTreePane::TreeElem` | 12-byte payload inside 36-byte `TreeNode<TreeElem>`; copy evidence [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) | Folder-owned payload declaration: name, row/depth, loaded, and expanded. Generic links and disabled state belong to `TreeNode<T>` in UID0004YK `Tree.h`; copy bodies are compiler support. |
| `std::vector<TreeNode<FolderTreePane::TreeElem> >` | UID0002MV/UID0002MW/UID0002MX and UID000447/449/44B | Direct Tree member and compiler-covered 36-byte insert/copy/destroy/free instances. There is no authored `TreeStorage<T>` or Folder-local storage helper source. |
| `Tree<FolderTreePane::TreeElem>` | ordinary destructor UID000158, scalar wrapper UID00034I, reset UID0002MY, traversal instances UID000344-347 | Complete generic source is UID0004YK `NexusTK/util/Tree.h`. FolderTreePane supplies the concrete payload, filesystem operations, visitor contexts/policies, and call sites; destructor/vector/vtable/EH bodies are compiler consequences. |
| `TreeItor<FolderTreePane::TreeElem>` | `0x004b5670`, `0x004b5a40`, `0x004b5bb0-0x004b5c3f` | Generic declaration and movement definitions come from UID0004YK `Tree.h`; FolderTreePane supplies concrete uses and binary instantiation evidence. |
| content-dimension traversal policy | [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) | `CalculateContentDimensions` creates Folder-owned context/policy and invokes generic `Tree<T>::Traverse<Visitor>`; generic deque/control-flow source is not duplicated here. |
| paint traversal policy | UID000345 and [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) | `PaintTree` creates Folder-owned context/policy and invokes generic traversal; the per-node Folder callback draws icon/text and returns descend/stop/skip state. |
| vector/string support helpers | UID00022E split children UID000446-44C | Folder-owned DirectoryEntry normalization/copy remains local. UID000447/449/44B are compiler-covered `std::vector<TreeNode<TreeElem> >` range/free instances; UID000448/44C remain shared 12-byte string-leading compiler helpers. |
| directory-entry scratch vector/sort helpers | `0x004b3fb0-0x004b57dd` | Local 12-byte `DirectoryEntry` scratch-vector and sort support for lazy expansion. [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) now emits the file-local `DirectoryEntryNameLess` comparator; neighboring sort/vector pages remain compiler/container support for the high-level child-directory sort expression. |

## Historical Binary Evidence Under Superseded Folder-Local Tree Model

- IDA confirms `FolderSelectDialog` constructs this pane at `0x004b178b`; no other constructor callers were found in the 2026-05-24 xref check.
- The constructor at `0x004b1b90` calls a `ScrollablePane` base constructor, initializes the embedded tree and iterator, loads the folder icon through `g_pEPFLibrary`, names the root node, expands it, and refreshes layout.
- `FindFirstVisibleChild` at `0x004b1d50` reconstructs the current node's full filesystem path, enumerates visible subdirectories into local 12-byte `DirectoryEntry` scratch records, calls the child-entry sort wrapper at `0x004b5280` using [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) `DirectoryEntryNameLess` and [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md) normalization support, inserts the sorted entries as persistent `TreeElem` children, and marks the node expanded.
- `SelectNodeByPath` at `0x004b2730` splits a path on `\\` and `/`, compares components case-insensitively against loaded child nodes, expands as needed, and updates selection.
- `0x004b3090` builds the selected path by walking parent links and prepending names. It is called from `FolderSelectDialog::OnCommand`.
- B004 2026-06-27 00024T split: [UID:00047Z][0x0061260c-0x00612610.SharedWidePathSeparatorLiteral](by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md) is the shared wide `L"\\"` literal used by FolderTreePane path helpers at `0x004b1d50` and `0x004b3090`. The literal lives in the mixed [UID:00024T][0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData](by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md) index but is not Application-only data.
- [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) is now documented as source-authored `void FolderTreePane::SetSelection(TreeItor<TreeElem> *selection)` with formal method C++. IDA shows it copies the iterator, computes node bounds, scrolls the selected row into view, clamps upward and downward scrolling, and invalidates the pane. The current preferred source-facing body uses inherited `ScrollablePane` helpers `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`, uses `m_contentRect.top` / `m_contentRect.bottom` for the inherited `+0x110` rectangle fields, and ends with `InvalidateRect(NULL)`. [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) remains only a stale/generated-output quality warning because current generated output has source-shaped code but generated tracker comments/rows may lag validation.
- Historical 2026-05-25 recheck: `0x004b5650` was classified only as constructor exception-unwind cleanup because it has sole EH xref `0x005fe944` and no ordinary callers. Accepted 2026-07-14 evidence preserves those facts but resolves exact `[0x004b5650,0x004b5669)` as a retained complete-object Tree destructor body reached after member construction; UID0000F9's inline virtual destructor is the human source cause.
- 2026-05-26 recheck: `0x004b59d5-0x004b59eb` are compiler-generated destructor adjustor thunks into `0x004b5a70`, not handwritten `FolderTreePane` behavior. They are documented in [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) and listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA vtable pass confirms the `Tree`, `TreeItor`, and three-view `FolderTreePane` vtables at `0x0061a500`, `0x0061a510`, `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`. Current metadata still reports `vtable_count: 0`; see [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md).
- The tertiary vtable ends before `0x0061a5c4`, where UTF-16 `TREEICON.EPF` string data begins. Do not treat `0x00520054`, `0x00450045`, or `0x00430049` string dwords as `FolderTreePane` virtual methods.
- 2026-06-29 B006 MCP session `86fb854e` reconfirmed the `FolderTreePane` class vtable names at `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`, the in-range dwords through `0x0061a5c0`, constructor/destructor xrefs for all three class views, adjustor thunk disassembly for `0x004b59d5` and `0x004b59e0`, and the `TREEICON.EPF` successor boundary at `0x0061a5c4`. That evidence supports comment-only markers on UID00036N/UID00036O rather than empty emitters or raw vtable source.
- 2026-06-08 Batch 110 IDA MCP refresh reconfirmed the direct parent gate for [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md): the concrete `Tree<FolderTreePane::TreeElem>` helper starts remain `0x004b3d50` size `0x254`, `0x004b55e0` size `0x6d`, `0x004b56e0` size `0x7f`, `0x004b5b00` size `0xae`, `0x004b5bb0` size `0x20`, `0x004b5bd0` size `0x43`, and `0x004b5c20` size `0x1f`; `Tree` vtable refs at `0x0061a500` land in constructor/cleanup/destructor paths, and the `TreeItor` vtable at `0x0061a510` has 31 refs spanning constructor, traversal, iterator cleanup, and destructor helpers.
- 2026-06-28 B009 accepted [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync: MCP session/database `agent_b009_0002my_20260628` reconfirmed reset callers at `0x004b1c18`, `0x004b1c95`, and `0x004b262a`, so the method belongs to this file's tree-template support used by the constructor/setup and `SetRootNodeName` paths. The generated output should now contain the formal `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` body rather than a `UID:0002MY` empty emitter marker.
- 2026-06-28 B006 accepted [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) implementation sync: original MCP session `supervisor_20260628_resume` plus resumed session/database `agent_b009_0002my_20260628` reconfirmed the `TreeStorage<FolderTreePane::TreeElem>::InsertAt` range `0x004b3d50-0x004b3fa4`, size `0x254`, three code xrefs, and caller contexts. Lazy expansion calls it at `0x004b227f`/`0x004b23d8` and reset-to-root calls it at `0x004b5b8f`, each only on the capacity-exhausted branch; fast paths copy-construct through [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) and advance the end pointer. The method now emits only a formal covered-by marker through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), because full body C++ would hand-port compiler-lowered allocation, relocation, EH cleanup, range-copy, destructor, and free-validation support.
- 2026-06-29 B010 accepted [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation sync: restored MCP session `992d23de` reconfirmed the `FolderTreePane::TreeElem` copy-constructor support range `0x004b55e0-0x004b564d`, size `0x6d`, five code refs from lazy expansion, `InsertAt`, and reset, sole `SimpleUString` copy callee `0x00582a90`, copied fields `+0x00..+0x10`, `+0x14`, `+0x18/+0x1a`, and `+0x1c/+0x1d/+0x20`, non-copied reserved padding, no original UDTs, and `0xcc` padding at `0x004b55d3-0x004b55e0` / `0x004b564d-0x004b5650`. The helper now emits only the accepted marker through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md); it should not be treated as an unresolved blank emitter or as a handwritten `FolderTreePane.cpp` helper body.
- 2026-06-29 B013 accepted [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) implementation sync: current MCP session `07c55da0` reconfirmed the `TreeStorage<FolderTreePane::TreeElem>` destructor/storage cleanup range `0x004b56e0-0x004b575f`, size `0x7f`, separate successor `0x004b5760`, five xrefs from constructor/EH cleanup, tree destruction, and outer pane destruction, and callees `sub_582B70`, `sub_5C7526`, and `__invalid_parameter_noinfo_noreturn`. The body walks 36-byte records, destroys names at `+0x14`, validates/frees vector storage, and zeros begin/end/capacity. It now emits only a formal covered-by marker through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), because full body C++ would hand-port compiler-lowered element cleanup/vector-storage release rather than source-facing `FolderTreePane.cpp` code.
- 2026-06-28 B013 accepted [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) implementation sync: MCP session/database `agent_b009_0002my_20260628` reconfirmed the comparator boundary/caller/callee route. [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) is now the concrete file-local `DirectoryEntryNameLess` comparator source for the lazy-expansion sort: it copies both directory-entry names, normalizes each through [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md)'s detach/uppercase support, and compares the normalized wide-string ranges. This updates the old blanket "sort helpers are compiler support" statement; UID000343 is the source comparator, while UID000349/UID00034A/UID00034B/UID00034C/UID00034D/UID00034E remain lowered sort/container support.

## Ownership Cleanup

Historical Wave3 ownership leads under `FolderTreePane` included unrelated or weakly related groups. Treat this as generated-lead cleanup, not current ownership authority:

- `0x0047f280-0x004805d4`: chat-message add/decode methods documented under [UID:0000I5][Chatting](by-file/Chatting.md) and [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).
- `0x004b8be0`, `0x004b9820-0x004ba24a`, and `0x00557140-0x00559aef`: generic DirectDraw/surface helpers documented under [UID:0000OC][Surface](by-file/Surface.md), [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md), [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md), and [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md).
- `0x00557aa0-0x00558391`: screenshot BMP/PNG capture and proof submission documented under [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) and [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md).
- `0x00585360-0x0058a8e0`: help/system-message methods documented under [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).

The local filesystem-tree source should be built from the `0x004b1b90-0x004b32c9` core plus the `0x004b3350-0x004b5c3f` tree/sort helpers and adjacent non-emitting split/index [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md), not by migrating the whole active generated `class_FolderTreePane.cpp`.

The UID00022E split keeps exact vector/string details on child pages: UID000446/44A are FolderTreePane-local DirectoryEntry support; UID000447/449/44B are compiler-covered `std::vector<TreeNode<FolderTreePane::TreeElem> >` instances caused by UID0004YK; UID000448/44C remain shared 12-byte string-leading compiler helpers. None establishes an authored `TreeStorage<T>` or Folder-local generic owner.

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 report `00005A-FolderTreePane-class-source-quality.md` closes the current source split at implementation level:

- Source file: `NexusTK/ui/controls/FolderTreePane.cpp`.
- Likely header: `NexusTK/ui/controls/FolderTreePane.h`.
- Main class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), now `88/89` with declaration-level class-shell C++.
- Consumer boundary: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) constructs and queries the control, but does not own the control internals.

Class and field model for this file:

- `FolderTreePane` derives from `ScrollablePane`, has size `0x17c`, and has primary/secondary/tertiary views at `+0x00`, `+0xa0`, and `+0xa4`.
- Exact class vtable bases are `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`; `0x0061a5c4` is the mandatory `TREEICON.EPF` successor boundary.
- `m_tree` at `+0x130` is `Tree<FolderTreePane::TreeElem>`.
- `m_folderIconContext` / `m_treeIconContext` near `+0x148` is an inferred EPF/tile context loaded from `TREEICON.EPF`.
- `m_selection` / `m_selectedIterator` at `+0x170` is `TreeItor<FolderTreePane::TreeElem>`.
- `ScrollablePane` viewport fields used by selection scrolling remain inherited state, not new `FolderTreePane` fields.

Nested/local type and helper placement:

- `FolderTreePane::TreeElem` is a 36-byte nested node record with `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and final `hidden`. `isHidden` is superseded history and `visibleTraversalSkip` descriptive only.
- `Tree`, `TreeStorage`, and `TreeItor` are project-local template/support declarations attached to this control, not standalone generated class sources. `TreeItor` is the accepted spelling; `TreeIterator` is not supported by the generated/vtable evidence.
- The original header factoring remains unproved: the declarations may have lived in `FolderTreePane.h` or a small reusable tree utility header, but no separate `Tree.cpp` owner is justified.

B014's accepted 2026-06-19 `TreeItor` pass makes [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) class-level C++ ready under this file route. The concrete iterator layout is vptr, `Tree<FolderTreePane::TreeElem> *m_tree` at `+0x04`, and `int m_currentIndex` at `+0x08`; the traversal children now emit first-draft `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` bodies. Keep the possible shared `Tree<T>`/`TreeItor<T>` header as a future factoring note only: [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md) proves a sibling specialization, but no scored shared tree-template by-file owner exists yet, so this concrete specialization still emits through `FolderTreePane.cpp`.

Current UID0002N0 synchronization makes the emitted iterator sequence explicit: UID00034F declaration-generated destructor support at position `30`, UID0002MZ first-child at `40`, UID0002N0 next-visible-sibling at `50`, and UID0002N1 parent at `60`. UID0002N0's sole call at `0x004b23f2` belongs to `ExpandNode` / `EnsureChildrenLoaded`; the caller ignores `AL`, consumes the target-mutated current index, and terminates on its separate 12-byte scratch-entry iterator. The target assigns each sibling candidate before checking `hidden`, returns true for the first zero-valued candidate, and leaves the iterator on the last hidden candidate if the chain exhausts.

The complete field audit establishes nonzero `hidden` as exclusion from visible sibling, path, and connector traversal. Path selection at `0x004b2846`, paint-node state at `0x004b58e6`, and UID0002N0 at `0x004b5bf9` are the semantic readers; reset/new construction writes zero; single/range copy preserves the byte; no nonzero or deletion-only route exists. These facts change no file score, owner, or formal C++ outside the accepted three destination blocks.

B007's 2026-06-28 UID00034F empty-emitter repair keeps generated `FolderTreePane.cpp` on the same source route. [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) is marker-only under [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md): the generated file should continue to receive the class-level `TreeItor` declaration and `virtual ~TreeItor()` source construct, not raw vtable-store source or a duplicate destructor body for the 7-byte cleanup helper.

Directory-entry sort/source-expression policy:

- Lazy expansion (`0x004b1d50`) should be documented with generated/search alias `FindFirstVisibleChild` and best source-facing direction `ExpandNode` / `EnsureChildrenLoaded`.
- The directory enumeration path builds local 12-byte `DirectoryEntry` scratch records, not `TreeElem` records.
- Accepted `DirectoryEntry` fields are `name` at `+0x00`, `row` / `rowIndex` at `+0x04`, `depth` / `depthOrIndent` at `+0x06`, `childrenLoaded` at `+0x08`, and `expanded` at `+0x09`.
- [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) is now the formal file-local `DirectoryEntryNameLess` comparator source for the local sort. It remains private to `FolderTreePane.cpp`, not a public `FolderTreePane` method, and its formal C++ uses copied/detached/uppercased name keys plus `WideRangeCompare`.
- [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md) supplies the detach/uppercase comparison-key normalization support used by [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md); it remains marker-only/compiler-lowered support rather than a standalone public helper.
- Neighboring sort pages [UID:000349][0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort](by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md) through [UID:00034E][0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap](by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md) remain compiler/generated binary support for sorting those local records, likely from an MSVC/Dinkumware-style sort/introsort expression. Source reconstruction should express the local `DirectoryEntry` vector population and sort expression in `ExpandNode` / `EnsureChildrenLoaded`, with UID000343 as the comparator source anchor rather than treating every sort child as blank support.
- B009's [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md) recheck confirms the depth-limit heap fallback specifically as an inferred MSVC/Dinkumware `_Adjust_heap`-style helper over `(first, holeIndex, length, value, pred)` arguments. This strengthens the no-standalone-C++ policy for sort internals: reconstruct the local `DirectoryEntry` vector population and sort expression, then let the compiler/library emit the heap fallback.

Generated-output and no-code policy:

- Do not hand-port vtable arrays, adjustor thunk bodies, constructor EH cleanup fragments, or scalar deleting destructor glue. Source declarations and normal member construction/destruction should regenerate those artifacts.
- B001's 2026-06-28 empty-emitter implementation keeps [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) attached semantically to [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) but non-emitting; `FolderTreePane.cpp` emits the iterator declaration and real traversal child bodies, not scalar deleting destructor glue.
- The same implementation keeps [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) attached semantically to [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) but non-emitting; clearing its emitter removes the generated empty marker without moving ownership to `FolderSelectDialog`, template support, or vtable-data pages.
- B010's 2026-06-28 empty-emitter repair keeps [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) as a reconstructable source-bearing aggregate/inventory under this file route but intentionally clears its emitter. The page inventories the constructor, expansion, layout, path, paint, input, bounds, selected-path, constructor EH cleanup, OnKey switch tables, alignment padding, and exact [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) child range. Generated `FolderTreePane.cpp` should not receive [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) as an empty marker or missing raw body; exact method C++ belongs on exact child pages, starting with [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), while [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) remains the declaration-level class-shell emitter with `[[CHILDREN]]`.
- B009's 2026-06-28 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation is the source-authored exception among nearby empty-emitter repairs: it keeps owner/emitter [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) and now emits a non-empty formal method body. Do not replace it with a covered-by marker, no-code disposition, or standalone generated tree class source.
- B015's 2026-06-28 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation is a source-authored exact child that now emits non-empty C++ through this file. `FolderTreePane::CalculateContentDimensions` at `0x004b2f60` prepares a three-field context `{pane,rowCount,maxWidth}`, creates a root `TreeItor<FolderTreePane::TreeElem>` over `m_tree` at `+0x130`, calls [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) at `0x004b2fbf`, then derives content width from `maxWidth` plus inherited scroll/content offsets and content height from `16 * rowCount - 4`. The emitted helper is inferred `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions`: it uses a `std::deque<int>` pending container, writes `TreeElem::rowIndex` and `TreeElem::depth`, measures `TreeElem::name` through `GetTextWidth`, updates `maxWidth`/`rowCount`, pushes children from `lastChildIndex` through `previousSiblingIndex` when `expanded` is set, and does not read `TreeElem+0x20` hidden/visible-skip state. [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) remains a non-emitting aggregate; [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) is the exact source-bearing child.
- B007's 2026-06-28 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation is another source-authored exact child that now emits non-empty C++ through this file. `FolderTreePane::PaintTree` at `0x004b2a00` prepares a paint traversal context with the pane pointer at context `+0x00`, creates a root `TreeItor<FolderTreePane::TreeElem>` over `m_tree` at `+0x130`, zeroes context slot `+0x0c`, and calls [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) at `0x004b2a67`. The emitted helper is the inferred `Tree<FolderTreePane::TreeElem>::TraversePaintNodes`: it uses a `std::deque<int>` pending container, calls [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) as `PaintFolderTreeNode`, handles traversal states `0` descend, `1` stop, and `2` skip children, pushes children from `lastChildIndex` through `previousSiblingIndex`, and does not read `TreeElem+0x20` hidden/visible-skip state. [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) remains a non-emitting aggregate; [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) is the exact source-bearing child.
- [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) and [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) are traced in generated output with comment-only no-code markers routed through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md); the source route remains class/template declarations and child method bodies, not raw tree vtable arrays.
- Do not migrate active generated `class_FolderTreePane.cpp` wholesale. Chat, surface/presentation/screenshot, and help/system-message ranges are known owner pollution and remain excluded.
- The class page emits only a conservative shell with `[[CHILDREN]]`; exact method bodies belong on child by-memory pages, starting with [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) `SetSelection`.

## 2026-06-26 B011 SetSelection Support Sync

B011's accepted source-quality implementation for [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) keeps this file as the owner/emitter route and removes the old raw-body uncertainty from the file-level source plan. Current generated `FolderTreePane.cpp` already contains source-shaped `SetSelection` code, but generated research/coverage tracker metadata may still show stale `78/86` comments until validator refresh catches up. Do not treat those stale generated rows as evidence that `FolderTreePane.cpp` still needs raw `sub_4B3210` migration.

The implemented method body should be understood as normal `FolderTreePane.cpp` source, not as a `ScrollablePane` method or an external helper. It updates `m_selection` at `+0x170`, asks local `GetNodeBounds` for the selected row rectangle, computes visibility through inherited `m_contentRect.top` / `m_contentRect.bottom`, and uses `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition` to keep the selected row visible. The final `Pane` update is `InvalidateRect(NULL)`. The exact historical name of the inherited `+0x110` rectangle remains a broader `ScrollablePane` final-audit question, but `m_contentRect` is the current accepted source-facing spelling for this implementation pass.

Rejected alternatives preserved from the accepted report: private `FolderSelectDialog.cpp` ownership for tree internals, standalone generated tree class source files, public method status for sort helper bodies, `TreeElem` ownership for 12-byte directory-entry records, `TreeIterator` spelling, hand-authored vtable/thunk C++, and treating `TREEICON.EPF` successor bytes as virtual slots.

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md)
- [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md)
- [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md)
- [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md)
- [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md)
- [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md)
- [UID:000448][0x004b5cf0-0x004b5d14.SharedStringLeadingRecordRangeDestroy](by-memory/0x004b5cf0-0x004b5d14.SharedStringLeadingRecordRangeDestroy.md)
- [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md)
- [UID:00044A][0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct](by-memory/0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct.md)
- [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md)
- [UID:00044C][0x004b5ec0-0x004b5efc.SharedStringLeadingRecordVectorStorageFree](by-memory/0x004b5ec0-0x004b5efc.SharedStringLeadingRecordVectorStorageFree.md)
- [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:00047Z][0x0061260c-0x00612610.SharedWidePathSeparatorLiteral](by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Historical Superseded 2026-07-29 UID0002MZ Shared-Template And Concrete-Consumer Reconciliation

- Current score is `92/93`. This file owns concrete `FolderTreePane.h/.cpp`; [UID:0004YK][Tree](by-file/Tree.md) independently owns shared `TreeNode<T>`, `TreeStorage<T>`, `Tree<T>`, and `TreeItor<T>` header templates.
- `FolderTreePane.h` emits the complete class and exact 12-byte nested payload. `FolderTreePane.cpp` owns filesystem enumeration, DirectoryEntry sorting, payload-specific reset, and the four concrete `Tree<T>::Traverse<Context>` specializations.
- Stored records are 36-byte `TreeNode<FolderTreePane::TreeElem>` values. Generic links and `disabled` are node-owned; name/row/depth/loaded/expanded are reached through `node.data`.
- UID000344-UID000347 are consumer-only `Traverse<Context>` specializations rather than four FolderTree-specific methods added to generic `Tree<T>`. UID00034H is the private static member `FolderTreePane::PaintTreeNode`, preserving legal access to `m_selection`.
- Complete header dependencies are `ScrollablePane`, `EPFTileContext`, pointer-backed `mystr::StringBase`, and shared `Tree.h`. The prior CPP-only class shell, 36-byte monolithic `TreeElem`, FolderTree-owned generic templates, SSO member, and file-local paint helper are retained as historical assumptions superseded by cross-specialization layout and C++ source-shape evidence.
- Existing owner-pollution exclusions, exact method ranges, vtables, compiler glue, DirectoryEntry 12-byte scratch family, and source-authored/marker-only dispositions remain unchanged.
- Supervisor Gate 2B catalog entry `0365` now realizes the exact generic FolderTree analysis UDT chain and accepted iterator names/types/comments in IDA. Current decompilation uses `m_storage.m_begin`, named generic links, and `disabled`; saved IDB `412DA7E8...519CD` is authoritative.
- IDA needed explicit `__declspec(align(4))` only for its payload/node analysis declarations. The concrete `FolderTreePane.h/.cpp` formals remain natural human C++ with implicit alignment and no synthetic padding. Earlier no-UDT/raw-name observations in this file are historical evidence, not current IDA state.

## 2026-07-30 UID0002MZ ExpandNode Source-Root Contract

This direct by-file page remains the `NexusTK/ui/controls/FolderTreePane.cpp` generated source root and therefore does not carry child-style reconstruction metadata. The selected source owner for the directory-entry comparator is the complete method at `0x004b1d50-0x004b253a`, not an artificial comparator anchor or warning-suppression shim. `AppendChild` is the highest-probability source API for the observed inline storage insertion and link repair; its spelling is inferred, while its parent/child/sibling effects are fixed by the binary. `FindClose` remains absent because the current decompile/callee inventory proves the original method does not close the search handle.

The accepted destination-ready source assembly is:

```cpp
#include "FolderTreePane.h"

#include <algorithm>
#include <vector>
#include <windows.h>
#include <wchar.h>

bool FolderTreePane::ExpandNode(TreeItor<TreeElem> *node)
{
    typedef mystr::StringBase<char, mystr::mychar_traits<char> > NarrowString;
    typedef mystr::StringBase<wchar_t,
                             mystr::mychar_traits<wchar_t> > WideString;

    TreeNode<TreeElem>& treeNode = m_tree.NodeAt(node->GetIndex());
    if (!treeNode.data.childrenLoaded)
    {
        WideString path(treeNode.data.name);
        TreeItor<TreeElem> parent(*node);
        while (parent.MoveToParent())
        {
            const WideString& component =
                m_tree.NodeAt(parent.GetIndex()).data.name;
            path.insert(0, L"\\");
            path.insert(0, component);
        }

        NarrowString searchPath(path);
        if (searchPath.empty() ||
            searchPath.c_str()[searchPath.length() - 1] != '\\')
        {
            searchPath.append("\\");
        }
        searchPath.append("*.*");

        WIN32_FIND_DATAA findData;
        HANDLE findHandle = FindFirstFileA(searchPath.c_str(), &findData);
        if (findHandle == INVALID_HANDLE_VALUE)
            return false;

        std::vector<DirectoryEntry> entries;
        do
        {
            if ((findData.dwFileAttributes & 0x12) == FILE_ATTRIBUTE_DIRECTORY &&
                findData.cFileName[0] != '.')
            {
                wchar_t wideName[MAX_PATH];
                MultiByteToWideChar(CP_ACP, 0, findData.cFileName, -1,
                                    wideName, MAX_PATH);

                DirectoryEntry entry;
                entry.name = wideName;
                entry.rowIndex = 0;
                entry.depth = 0;
                entry.childrenLoaded = 0;
                entry.expanded = 0;
                entries.push_back(entry);
            }
        } while (FindNextFileA(findHandle, &findData));

        std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess);

        for (std::vector<DirectoryEntry>::const_iterator it = entries.begin();
             it != entries.end(); ++it)
        {
            TreeElem child;
            child.name = it->name;
            child.rowIndex = it->rowIndex;
            child.depth = it->depth;
            child.childrenLoaded = it->childrenLoaded;
            child.expanded = it->expanded;
            m_tree.AppendChild(node, child);
        }

        m_tree.NodeAt(node->GetIndex()).data.childrenLoaded = 1;
    }

    TreeNode<TreeElem>& updatedNode = m_tree.NodeAt(node->GetIndex());
    if (updatedNode.firstChildIndex == -1)
        return false;

    updatedNode.data.expanded = 1;
    RefreshTreeLayout();
    return true;
}

[[CHILDREN]]
```

The payload preserves the exact directory mask `(attributes & 0x12) == 0x10`, dot-entry exclusion, ANSI enumeration, local 12-byte `DirectoryEntry` construction, comparator-wrapper source expression, exact `std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess)` consumer, sorted child insertion, `childrenLoaded`/`expanded` transitions, first-child failure, layout refresh, and binary-observed absence of `FindClose`. Original API/local spellings remain inference-scored, but no compiler or IDA labels are part of the source contract.

## Changes

### 2026-08-24 UID0004YK Gate 2A Consumer-Boundary Correction

- UID0004YK `NexusTK/util/Tree.h` now owns all reusable TreeFindFunc/TreeNode/Tree/TreeItor source and direct vector storage. This file remains the concrete consumer for `FolderTreePane::TreeElem`, filesystem enumeration, rendering, hit-test/navigation, and visitor/context policy. UID0002MV/UID0002MX and related ranges are vector/compiler evidence; there is no authored `TreeStorage<T>` or Folder-local generic template route.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below preserve implementation chronology and exact consumer evidence. Their former FolderTreePane.cpp generic-template placement, `TreeStorage<T>` source routes, direct-vector rejection, and future shared-header deferral are explicitly superseded by the current consumer boundary above.

- 2026-07-14 B001 UID0002N0 source-family synchronization:
  - Preserved `91/90`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`, `CANONICAL_OWNER:FILE`, all formal C++, and every unrelated source-family fact.
  - Finalized TreeElem `hidden` semantics/history, added exact `30/40/50/60` iterator order and UID0002N0's sole expansion caller/ignored-return/current-index contract, and retained concrete FolderTreePane.cpp emission.
  - Preserved likely shared-header factoring as nonblocking historical uncertainty and rejected duplicate aggregate/class/standalone source ownership.

- 2026-07-14 B001 UID000158 source-family synchronization:
  - Preserved by-file score `91/90`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`, `CANONICAL_OWNER:FILE`, and all unrelated file content; no file-root reconstruction metadata was added.
  - Recorded UID0000F9 as UID000158's direct class owner while retaining this page as the final FolderTreePane.cpp route. Corrected the exact range/title and changed historical EH-only/file-direct wording to retained complete-object destructor support.
  - The accepted inline empty virtual destructor regenerates TreeStorage destruction, LObject teardown, constructor-unwind invocation, vtable transitions, and scalar deleting wrapper behavior. Explicit vptr/member/base/EH/scalar bodies, `std::vector` substitution, a new generated Tree source, and aggregate emission remain rejected.
  - Exact evidence preserved here by reference: body SHA256 `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99`, sole state-3 EH route `0x005fe944`, Tree at FolderTreePane `+0x130`, storage at Tree `+4`, vtable `0x0061a500`, storage destructor `0x004b56e0`, and LObject teardown `0x004f4a90`.
- 2026-06-29 B010 [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation support sync:
  - Score unchanged at `89/85`.
  - Added file-level source-route support that UID0002MW is no longer unresolved blank C++. It is marker-only `FolderTreePane::TreeElem` copy-constructor support through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md), used by storage insertion and reset copy paths, and not a standalone `FolderTreePane` member/helper body.
  - Evidence: B010 restored MCP session `992d23de` confirmed the function boundary, five refs, sole callee, copied-field set, non-copied reserved padding, adjacent `0xcc` bytes, missing original UDTs, and rejected full helper body / direct file ownership / non-emitting dispositions.

- 2026-06-29 B006 [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) / [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) implementation support sync:
  - Score unchanged at `89/85`.
  - Added generated-output/no-code policy: UID00036N/UID00036O route through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) into this file as comment-only markers, not raw vtable arrays, adjustor thunk bodies, constructor EH cleanup fragments, or scalar deleting destructor glue.
  - Preserved existing historicalized Wave3/simroot/recovered-source wording as old generated lead material only. Current support comes from by-* documentation and MCP session `86fb854e` evidence.

- 2026-06-29 B013 [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) implementation support sync:
  - Score unchanged at `89/85`.
  - Historicalized the active `Current recovered source`, `Evidence basis: Wave3 generated source`, and `Current active Wave3 ownership` wording as generated-source leads only. Current source-route authority for UID0002MX is current by-* documentation plus MCP-backed evidence, not Wave3/simroot/recovered source.
  - Added file-level source-route support that UID0002MX is no longer an unresolved empty emitter. It is marker-only `TreeStorage<FolderTreePane::TreeElem>` destructor/storage cleanup through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), called from constructor/EH cleanup, tree destruction, and pane destruction paths.
  - Evidence: B013 current MCP session `07c55da0` confirmed function boundary, caller categories, callee set, 36-byte element walk, `+0x14` name destruction, large-allocation validation/free behavior, missing original UDTs, and rejected full decompiler-shaped body / direct `FolderTreePane` member ownership / standalone generated tree-storage source alternatives.

- 2026-06-28 B013 [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) implementation support sync:
  - Updated the file-level directory-entry sort policy so [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) is the formal `DirectoryEntryNameLess` comparator body emitted through this file, while [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md) remains normalization support and the rest of the sort/vector helper pages remain compiler/container support.
  - Added the accepted lazy-expansion route: `0x004b1d50` builds local 12-byte `DirectoryEntry` records, sorts them through `0x004b5280` using UID000343/UID000446, and only then inserts persistent `TreeElem` children.
  - Evidence: B013 accepted MCP-backed report evidence from session/database `agent_b009_0002my_20260628`; generated `FolderTreePane.cpp` should contain UID000343 comparator C++ rather than a UID000343 empty-emitter marker.

- 2026-06-28 B006 [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) implementation sync:
  - Score unchanged at `89/85`.
  - Added file-level source-route support that [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) is no longer an unresolved empty emitter. It is marker-only `TreeStorage<FolderTreePane::TreeElem>::InsertAt` support through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), reached from lazy expansion and reset only when storage capacity is exhausted.
  - Evidence: B006 MCP sessions `supervisor_20260628_resume` and `agent_b009_0002my_20260628` confirmed the function boundary, three caller sites, storage growth/decompile behavior, helper fan-out, padding, missing original UDTs, and rejected full decompiler-shaped body / direct `FolderTreePane` member ownership / standalone generated tree-storage source alternatives.

- 2026-06-28 B015 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation sync:
  - Score unchanged at `89/85`.
  - Added file-level support that [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) is now a formal source emitter through `FolderTreePane.cpp` as inferred `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions`, not an empty marker or no-code ownership repair. Preserved the `CalculateContentDimensions` callsite/context evidence, `std::deque<int>` pending traversal, row/depth writes, text-width accumulation, expanded child descent, negative `+0x20` hidden-skip evidence, and the fact that [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) remains the non-emitting aggregate while [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) owns the exact body.
  - Evidence: B015 MCP session/database `agent_b009_0002my_20260628` confirmed the target range `0x004b3400-0x004b3645`, sole caller at `0x004b2fbf`, tree receiver at `FolderTreePane+0x130`, caller context fields `pane`, `rowCount`, and `maxWidth`, row/depth consumer `GetNodeBounds`, and no boundary refs.

- 2026-06-28 B007 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation sync:
  - Score unchanged at `89/85`.
  - Added file-level support that [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) is now a formal source emitter through `FolderTreePane.cpp` as inferred `Tree<FolderTreePane::TreeElem>::TraversePaintNodes`, not an empty marker or no-code ownership repair. Preserved the `PaintTree` callsite/context evidence, `std::deque<int>` pending traversal, dependency on [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) `PaintFolderTreeNode`, stop/skip states, last-child/previous-sibling child push order, negative `+0x20` hidden-skip evidence, and the fact that [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) remains the non-emitting aggregate while [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) owns the exact body.
  - Evidence: B007 MCP session/database `agent_b009_0002my_20260628` confirmed the target range `0x004b3650-0x004b3848`, sole caller at `0x004b2a67`, tree receiver at `FolderTreePane+0x130`, helper call at `0x004b375f`, and sibling traversal family.

- 2026-06-28 B009 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync:
  - Score unchanged at `89/85`.
  - Updated the file-level source route so [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) no longer remains an empty emitter. The accepted output is a formal `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` body emitted through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md), while adjacent vtables, scalar deleting destructors, and aggregate pages keep their accepted no-code or non-emitting dispositions.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirmed reset callers from constructor/setup and `SetRootNodeName`, storage rewind, root sentinel bytes, fast copy path, `InsertAt` fallback, and row/depth non-initialization.

- 2026-06-28 B010 [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) empty-emitter support sync:
  - Score unchanged at `89/85`.
  - Added file-level no-code routing support for [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md): it remains a reconstructable `FolderTreePane.cpp` aggregate/inventory but is intentionally non-emitting so generated `FolderTreePane.cpp` no longer receives an empty marker or treats the aggregate as a missing method body. Exact method bodies belong on exact child pages, [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) already emits through this file, [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) remains the class-shell `[[CHILDREN]]` route, and vtables/thunks/EH cleanup/switch tables remain generated-binary support rather than handwritten source.

- 2026-06-28 B001 FolderTree empty-emitter support sync:
  - Score unchanged at `89/85`.
  - Added combined no-code policy for accepted FolderTree empty-emitter repairs: [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) and [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) are semantic children with blank emitters/formal C++, while [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) and [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) carry trace-only no-code markers through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md). The file still rejects scalar deleting destructor glue, adjustor thunk bodies, EH cleanup fragments, and raw vtable arrays as handwritten source.

- 2026-06-28 B007 UID00034F support sync:
  - Score unchanged at `89/85`.
  - Added file-level sync that [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) is a marker-only covered-by range under [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md). `FolderTreePane.cpp` should keep receiving the class-level `TreeItor` declaration/virtual destructor, not raw vtable-store source.

- 2026-06-27 B004 00024T shared path-separator support sync:
  - Score unchanged at `89/85`.
  - Added [UID:00047Z][0x0061260c-0x00612610.SharedWidePathSeparatorLiteral](by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md) as the shared `L"\\"` literal used by FolderTreePane helpers `0x004b1d50` and `0x004b3090`, with source-use routed through this file and the mixed parent [UID:00024T][0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData](by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md) kept no-owner.

- 2026-06-26 B011 [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) implementation support sync:
  - Score unchanged at `89/85`.
  - Updated file-level `SetSelection` support so this file no longer implies raw `sub_4B3210` generated-body uncertainty. The exact child now emits source-shaped C++ through this file with direct `ScrollablePane` helper names, inherited `m_contentRect`, and `InvalidateRect(NULL)`; stale generated tracker rows are validator refresh state only.
- 2026-06-26 B009 [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) split implementation:
  - Score unchanged at `89/85`.
  - Updated the file-level vector/string support description so [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) is treated as a non-emitting split/index. Exact child pages now carry FolderTreePane `DirectoryEntry`, `TreeStorage<FolderTreePane::TreeElem>`, and shared string-leading helper dispositions.
- 2026-06-19 B014 TreeItor support sync:
  - Score unchanged at `89/85`.
  - Added the accepted `TreeItor<FolderTreePane::TreeElem>` implementation decision: [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) now carries class-level draft C++, traversal method bodies live on exact by-memory children, destructor/vtable helper bytes remain generated-binary support, and likely shared-template header factoring remains a future consolidation note rather than a current owner transfer.

- 2026-06-19 B008 accepted source-quality implementation sync:
  - Score unchanged at `89/85`; [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) carries the accepted target score change to `88/89`.
  - Added source split closure, generated-source pollution closure, class field/type model, local tree/template placement, `DirectoryEntry` sort shape, generated-support no-code policy, and rejected alternatives from the accepted B008 report.
- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: the existing file page and proposed source-tree entry treat this as a reusable filesystem tree control; IDA MCP recheck confirms construction from [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) at `0x004b178b`, vtable stores for the three `FolderTreePane` views, and selection/path helpers used by the dialog.

- 2026-06-19 B014 FolderSelectDialog support sync:
  - Score unchanged at `89/85`.
  - Added the accepted dialog/control split from the FolderSelectDialog implementation callback: `FolderSelectDialog.cpp` owns the modal folder picker and drive/callback policy, while `FolderTreePane.cpp` remains the separate reusable control source. MusicControlDialog reaches this control only indirectly through the folder picker.
- 2026-06-21 Rule 26 B009 `00034C` support sync:
  - Score unchanged at `89/85`.
  - Added the accepted `_Adjust_heap` interpretation for [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md), keeping the source-level implementation as the owning `FolderTreePane` child-directory sort expression rather than a handwritten helper body.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: filesystem tree-control role, proposed contents, core/tree/vector helper ranges, vtables/layout types, IDA evidence, generated owner-pollution exclusions, missing body notes, and control/dialog split caveat are documented; confidence is strong but exact standalone-versus-private source split remains medium.
- 2026-06-08 A005 Batch 110 parent-gate refresh:
  - What existed before: score `88/80`, below the corrected `85/85` parent-side assignment gate for the local folder-tree template page.
  - Changed to: score `89/85`.
  - Summary/evidence: live IDA MCP reconfirmed the exact concrete tree/template helper starts, `Tree` and `TreeItor` vtable refs, three `FolderTreePane` vtable stores, and the existing owner-pollution exclusions. The file page now clears the parent-side gate for direct `FolderTreePane.cpp` template-support children, while final header factoring and field names still cap confidence at `85`.
