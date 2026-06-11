# 000157 FolderTreePaneTreeAndSortHelpers Ownership / Split Research

## Finalized Report / Current Recommendation

- Final disposition: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) is now a parent-blank non-emitting inventory/container at `88/90`, `RECONSTRUCTABLE:FALSE`.
- Split result: every source-bearing range in `0x004b3350-0x004b5c3f` now has an exact child page or an existing exact child page. No additional child page is required by the final range audit.
- Parent-gate result: children are assigned only when both child and direct parent clear `85/85`. Shared or compiler-cleanup ranges remain blank/ignored as documented.
- Final confidence: high for split coverage, direct parent-gate decisions, and `FolderTreePane` ownership of traversal/sort helpers; medium-high for original source spellings of optimized sort/vector helpers.

## Target

- Target UID: `000157`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`
- Final target metadata: `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank.
- Direct parent context: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is `89/85`; [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) is `85/86`; [UID:0000FC] and [UID:0000FB] are `85/86`; [UID:0000F9] was repaired to `85/88`.

## IDA Evidence

- IDB: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, md5 `4247e04e20b65d6414c7238aa8ff5515`, sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function boundaries: IDA MCP `lookup_funcs` confirmed independent starts for `0x004b3350`, `0x004b3400`, `0x004b3650`, `0x004b3850`, `0x004b3af0`, `0x004b3d50`, `0x004b3fb0`, `0x004b4240`, `0x004b44c0`, `0x004b4520`, `0x004b4fd0`, `0x004b5280`, `0x004b5510`, `0x004b55e0`, `0x004b5670`, `0x004b56e0`, `0x004b5760`, `0x004b57e0`, `0x004b57f0`, `0x004b5800`, `0x004b5810`, `0x004b59d5`, `0x004b59e0`, `0x004b59f0`, `0x004b5a40`, `0x004b5a70`, `0x004b5b00`, `0x004b5bb0`, `0x004b5bd0`, and `0x004b5c20`.
- Caller/callee evidence: traversal helpers are called from `FolderTreePane` content-size, paint, hit-test/mouse, and key paths; directory-entry vector/sort helpers are called from `FindFirstVisibleChild`; `0x004b5760` has an ordinary non-folder-tree caller at `0x00573820`.
- Vtable evidence: `0x0061a500` is the `Tree<FolderTreePane::TreeElem>` vtable, `0x0061a510` is the `TreeItor<FolderTreePane::TreeElem>` vtable, and `0x0061a518`/`0x0061a58c`/`0x0061a5bc` are `FolderTreePane` vtable views. Destructors at `0x004b59f0`, `0x004b5a40`, and `0x004b5a70` are vtable/data-referenced destructor support.
- Padding/cleanup evidence: `0x004b57dd-0x004b57e0`, `0x004b57e8-0x004b57f0`, `0x004b57f8-0x004b5800`, and `0x004b580e-0x004b5810` are padding around exact cleanup helper pages. EH cleanup thunks and adjustor thunks are documented as non-emitting support.

## Final Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Final Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b3350-0x004b33fc` | [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) | directory-entry name compare | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b3400-0x004b3645` | [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) | content-dimension traversal callback | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b3650-0x004b3848` | [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) | paint traversal callback | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b3850-0x004b3ae2` | [UID:000346][0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal](by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md) | hit-test/search traversal helper | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b3af0-0x004b3d41` | [UID:000347][0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch](by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md) | key navigation visible search | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b3d50-0x004b3fa4` | [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) | `TreeStorage::InsertAt` | yes | [UID:0000FC] | `85/90` | existing child assigned |
| `0x004b3fb0-0x004b4232` | [UID:000348][0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt](by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md) | 12-byte entry vector insert/grow | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b4240-0x004b44b3` | [UID:000349][0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort](by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md) | directory-entry insertion sort | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b44c0-0x004b451b` | [UID:00034A][0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3](by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md) | compare/swap dispatcher | yes | [UID:0000JG] | `87/90` | created and assigned |
| `0x004b4520-0x004b4fc5` | [UID:00034B][0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore](by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md) | sort core | yes | [UID:0000JG] | `85/87` | created and assigned |
| `0x004b4fd0-0x004b5271` | [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md) | sort partition/merge helper | yes | [UID:0000JG] | `85/87` | created and assigned |
| `0x004b5280-0x004b5510` | [UID:00034D][0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper](by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md) | child-entry sort wrapper | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b5510-0x004b55d3` | [UID:00034E][0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap](by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md) | directory-entry swap | yes | [UID:0000JG] | `87/90` | created and assigned |
| `0x004b55e0-0x004b564d` | [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) | `TreeElem` copy construction | yes | [UID:0001UJ] | `85/90` | rechecked; already valid |
| `0x004b5650-0x004b5668` | [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md) | constructor EH tree cleanup | source-declared/generated-binary | [UID:0000JG] | `85/88` | repaired from below-gate score |
| `0x004b5670-0x004b5677` | [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) | `TreeItor` destructor vtable reset | source-declared/generated-binary | [UID:0000FB] | `85/88` | created and assigned |
| `0x004b56e0-0x004b575f` | [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) | `TreeStorage` destructor | yes | [UID:0000FC] | `85/90` | existing child assigned |
| `0x004b5760-0x004b57dd` | [UID:00034G][0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor](by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md) | shared 12-byte string-entry vector destructor | yes/shared support | blank | `86/88` | created; parent blank because ownership is shared with SpelledPane |
| `0x004b57e0-0x004b57e8` | [UID:00031B][0x004b57e0-0x004b57e8.FolderTreeDirectoryEntryNameCleanupThunk](by-memory/0x004b57e0-0x004b57e8.FolderTreeDirectoryEntryNameCleanupThunk.md) | EH string cleanup thunk | no | blank | `85/88` | existing non-emitting cleanup child |
| `0x004b57f0-0x004b57f8` | [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md) | iterator vtable cleanup helper | no | blank | `85/88` | existing non-emitting cleanup child |
| `0x004b5800-0x004b580e` | [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md) | dual iterator vtable cleanup helper | no | blank | `85/88` | existing non-emitting cleanup child |
| `0x004b5810-0x004b59d5` | [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) | paint node helper | yes | [UID:0000JG] | `86/88` | created and assigned |
| `0x004b59d5-0x004b59eb` | [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) | adjustor thunks | no | blank/ignored | `85/88` | existing non-emitting thunk child |
| `0x004b59f0-0x004b5a38` | [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) | `Tree` scalar deleting destructor | source-declared/generated-binary | [UID:0000F9] | `85/88` | created and assigned after parent repair |
| `0x004b5a40-0x004b5a64` | [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) | `TreeItor` scalar deleting destructor | source-declared/generated-binary | [UID:0000FB] | `86/89` | created and assigned |
| `0x004b5a70-0x004b5af4` | [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) | `FolderTreePane` scalar deleting destructor | yes/destructor support | [UID:00005A] | `86/89` | created and assigned |
| `0x004b5b00-0x004b5bae` | [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) | reset to single root | yes | [UID:0000F9] | `85/90` | repaired from below-gate score |
| `0x004b5bb0-0x004b5bd0` | [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) | iterator first child | yes | [UID:0000FB] | `85/90` | repaired from below-gate score |
| `0x004b5bd0-0x004b5c13` | [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) | iterator next visible sibling | yes | [UID:0000FB] | `85/90` | rechecked and repaired |
| `0x004b5c20-0x004b5c3f` | [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) | iterator parent | yes | [UID:0000FB] | `85/90` | rechecked and repaired |

## Ownership Decisions

1. [UID:0000JG] `FolderTreePane.cpp`: owns traversal callbacks, directory-entry sort/vector helpers, paint helper, local cleanup fragment [UID:000158], and file-local source support where no narrower class/type parent applies. Direct parent gate is `89/85`.
2. [UID:0000FC], [UID:0000F9], [UID:0000FB], [UID:0001UJ]: own storage, tree wrapper, iterator, and nested record methods respectively when direct child and parent both clear `85/85`. [UID:0000F9] was repaired to `85/88`, enabling [UID:00034I] and [UID:0002MY].
3. Shared support: [UID:00034G] remains parent blank because IDA shows an ordinary SpelledPane caller at `0x00573820` plus a FolderTreePane EH xref. No exclusive direct owner clears `85/85`.
4. Non-emitting cleanup/thunks: [UID:00031B], [UID:00031C], [UID:00031D], and [UID:000159] remain blank/ignored according to their exact compiler cleanup/thunk classification.

## Negative Evidence

- The aggregate is not one IDA function and should not be assigned or emitted as a source unit.
- Address adjacency does not prove single ownership; child assignments use caller/callee/vtable evidence and strict parent gates.
- EH-only xrefs identify cleanup support rather than ordinary source-authored callable methods.
- Vtable-only refs to scalar deleting destructors prove destructor support, not standalone handwritten methods.
- `0x004b5760` cannot be assigned to `FolderTreePane.cpp` exclusively because of the ordinary non-folder-tree caller at `0x00573820`.

## Validator Results

- UID assignment scans:
  - `000343` assigned to `0x004b3350-0x004b33fc`.
  - `000344` through `000347` assigned to traversal/search pages.
  - `000348` through `00034E` assigned to directory-entry vector/sort/swap pages.
  - `00034F` through `00034K` assigned to iterator/shared/paint/destructor helper pages.
- Normal targeted validator scans run with `python .\tools\validator.py --mode file --file <path> --apply`.
- Final normal scans completed with exit code `0` for all 26 targeted files: all created pages `000343` through `00034K`, rechecked [UID:0002MW], repaired [UID:000158], [UID:0002MY], [UID:0002MZ], [UID:0002N0], [UID:0002N1], repaired parent [UID:0000F9], and the aggregate [UID:000157].
- Unresolved validator errors: none observed in targeted scans.

## Changed Files

- Created by B001-028: `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md`; `by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md`; `by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md`; `by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md`; `by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md`; `by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md`; `by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md`; `by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md`; `by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md`; `by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md`; `by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md`; `by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md`; `by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md`; `by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md`; `by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md`; `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`; `by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md`; `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`.
- Modified by B001-028: `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`; `by-class/Tree_struct_FolderTreePane__TreeElem_.md`; `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`; `by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md`; `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md`; `by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md`; `by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md`; this research report.
- Validator refreshed generated coverage/reference artifacts as part of targeted scans.
- Not changed: `Supervisor_notes.md`.
- Report moved to executed: no.

## Final Status

READY FOR SUPERVISOR REVIEW.
