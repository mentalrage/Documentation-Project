*** UID:0001WP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Header-only Tree template declarations and definitions are emitted through
// Tree.h; no out-of-line Tree.cpp implementation belongs to this inventory.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "LObject.h"
#include <deque>
#include <vector>

template <class T> struct TreeNode;
template <class T> class Tree;
template <class T> class TreeItor;

template <class T>
struct TreeFindFunc
{
    virtual bool IsMatch(T *candidate) = 0;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane Tree Templates

## Current Accepted UID0004YK Shared Header Preamble

This position-0 fragment is the reusable Tree.h preamble. It owns the LObject, deque, and vector includes; the TreeNode, Tree, and exact-spelling TreeItor forward declarations; and the one-slot TreeFindFunc interface. Live RTTI for TreeFindFunc<EventHandler *> and the single vtable entry at 0x00619648 support virtual bool IsMatch(T *candidate) with no virtual destructor slot. The historical FolderTreePane-local TreeStorage model below is superseded by std::vector<TreeNode<T> > while remaining research history.

## Status

- Confidence: very strong for the shared node prefix, payload/state separation, storage and iterator layouts, and symbol-backed `TreeItor` spelling; medium-high for inferred physical header spelling.
- Rebuild handling: source-authored project-local templates reconstructed in shared `NexusTK/util/Tree.h`, not standalone generated class files.
- Owner file: [UID:0004YK][Tree](by-file/Tree.md)
- Owner class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Assignment: current `93/94`, attached to UID0004YK for shared header emission. Concrete FolderTree payload and visitor specializations remain with UID00005A/UID0000JG.
- Related layout: [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- Related vtables: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- Related memory: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)

## Historical 2026-06-30 B010 Formal Template Route And Empty-Emitter Cleanup

B010's accepted [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) empty-emitter family implementation inserts formal template forward declarations plus `[[CHILDREN]]`, keeps owner/emitter [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), and raises this page from `87/90` to `88/91`.

At that dated stage the concrete route remained FolderTreePane-local: `TreeStorage<FolderTreePane::TreeElem>`, `Tree<FolderTreePane::TreeElem>`, and `TreeItor<FolderTreePane::TreeElem>` were routed through `FolderTreePane.cpp` pending a scored shared owner. Historical MCP session `supervisor_resume_20260629` reconfirmed the concrete traversal helpers [UID:000346][0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal](by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md) and [UID:000347][0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch](by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md), plus per-node paint helper [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md); those accepted bodies remain unchanged. [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) was classified as compiler scalar-wrapper support, while [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) was resolved as retained complete-object Tree destructor evidence covered by UID0000F9's inline virtual destructor. The current shared owner is UID0004YK `Tree.h`; this paragraph is retained only as the superseded route chronology.

## Current Shared Template Declaration

The shared authored declarations are reusable templates in UID0004YK `Tree.h`; generated class filenames are concrete analysis aliases, not original one-class source files:

```cpp
struct FolderTreePane::TreeElem;
template<class T> struct TreeNode;
template<class T> class Tree;
template<class T> class TreeItor;
template<class T> struct TreeFindFunc;
```

The concrete instance is effectively:

```cpp
Tree<FolderTreePane::TreeElem>
TreeItor<FolderTreePane::TreeElem>
std::vector<TreeNode<FolderTreePane::TreeElem> >
```

## Generated Names

| Generated class | Current role | Placement |
| --- | --- | --- |
| [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) | Generic `TreeNode<T>` declaration plus historical concrete-vector analysis evidence; the generated filename is not authored `TreeStorage<T>` source | Shared [UID:0004YK][Tree](by-file/Tree.md) `Tree.h`; concrete vector lowering remains child evidence. |
| [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) | Generic Tree wrapper, inline virtual destructor, reset/traversal surfaces | Shared [UID:0004YK][Tree](by-file/Tree.md) `Tree.h`; concrete specializations remain in consumer sources. |
| [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) | Generic iterator declaration and child/next-enabled-sibling/parent movement | Shared [UID:0004YK][Tree](by-file/Tree.md) `Tree.h`. |

## Exact Memory Pages

| Range page | Template role | Evidence state |
| --- | --- | --- |
| [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) | `std::vector<TreeNode<FolderTreePane::TreeElem> >` grow/insert lowering | Compiler-covered concrete vector support caused by UID0004YK `Tree.h`; no authored `TreeStorage<T>::InsertAt` or Folder-local generic source owner. Current MCP confirms 36-byte records, three capacity-exhaustion callers, 1.5x growth, helper copy/range-copy/destroy/free use, and no safe standalone handwritten full body. |
| [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) | `std::vector<TreeNode<FolderTreePane::TreeElem> >` range destruction | Compiler-covered 36-byte record cleanup from vector insertion/relocation; no authored helper. |
| [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) | `std::vector<TreeNode<FolderTreePane::TreeElem> >` range copy construction | Compiler-covered 36-byte record relocation/copy from vector insertion/relocation; no authored helper. |
| [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) | `std::vector<TreeNode<FolderTreePane::TreeElem> >` storage release | Compiler-covered storage cleanup with MSVC aligned-allocation validation; no authored helper. |
| [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) | `FolderTreePane::TreeElem` copy construction | Marker-only compiler-emitted single-record copy-constructor support through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md); restored MCP confirms five callers, sole `SimpleUString` copy callee, copied link/name/row/depth/flag fields, non-copied reserved padding, and no standalone helper body. |
| [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) | retained complete-object destructor for `Tree<FolderTreePane::TreeElem>` | Exact 25-byte IDA constructor chunk reached by completed-member unwind state 3; covered by UID0000F9's inline virtual destructor, with compiler vptr/storage/LObject/EH/scalar glue excluded from handwritten source. |
| [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) | `std::vector<TreeNode<FolderTreePane::TreeElem> >` destructor/storage cleanup | Compiler-covered concrete vector destruction caused by UID0004YK `Tree.h`; no authored `TreeStorage<T>` destructor or Folder-local generic source owner. Current MCP confirms 36-byte record walk, `+0x14` name destruction, storage free with large-allocation validation, begin/end/capacity zeroing, and no safe standalone handwritten full body. |
| [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) | `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions` | Formal concrete-specialization C++ inserted; traverses visible tree nodes to write row/depth, measure text width, and return row/max-width totals through a small context. |
| [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) | `Tree<FolderTreePane::TreeElem>::TraversePaintNodes` | Formal concrete-specialization C++ inserted; deque-backed pending traversal, `PaintFolderTreeNode` callback, stop/skip states, and `lastChildIndex`/`previousSiblingIndex` child descent. |
| [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) | `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot` | Formal concrete-specialization C++ inserted; resets storage to one root record with verified sentinel and flag writes. |
| [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) | iterator first-child traversal | Position `40`; IDA-confirmed current-index update from record offset `+0x04`. |
| [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) | iterator next-visible-sibling traversal | Position `50`; candidate-before-test sibling walk skips `hidden` at `+0x20`; sole expansion caller ignores the return and consumes iterator state. |
| [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) | iterator parent traversal | Position `60`; IDA-confirmed parent-index update from record offset `+0x00`. |

## Historical Binary Evidence Under Superseded TreeStorage Analysis Label

The dated bullets below preserve exact binary research that originally used a monolithic `TreeElem` label and a descriptive `TreeStorage` analysis label. None of the `TreeStorage` spellings in this historical section assert authored source or current ownership. Under the current accepted model, every 36-byte record reference means `TreeNode<FolderTreePane::TreeElem>`, `+0x14` begins `node.data`, node `+0x20` is generic `disabled`, and the three-pointer container is `std::vector<TreeNode<FolderTreePane::TreeElem> >`; the 12-byte nested payload owns only name/row/depth/loaded/expanded.

- `FolderTreePane` embeds the tree at offset `+0x130` and the selected iterator at `+0x170`.
- `TreeStorage<FolderTreePane::TreeElem>` uses 36-byte records and owns `InsertAt` at `0x004b3d50` and storage destruction at `0x004b56e0`. The adjacent B009 split adds exact range-destroy, range-copy, and vector-storage free children [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) for compiler-emitted support called from the same insertion/relocation path.
- `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot` at `0x004b5b00` is called from the `FolderTreePane` constructor and reset/root-name paths.
- Concrete iterator order is UID00034F declaration-generated destructor support at `30`, UID0002MZ first-child at `40`, UID0002N0 next-visible-sibling at `50`, and UID0002N1 parent at `60`. These helpers remain local to visible folder-tree traversal.
- TreeElem `+0x20` is finalized as `hidden`: path selection, per-node paint, and UID0002N0 skip nonzero records; root/new construction writes zero; single/range copy preserves it; no nonzero or deletion-only route exists. `isHidden` is historical and `visibleTraversalSkip` descriptive only.
- The exact `[0x004b5650,0x004b5669)` body is an IDA constructor chunk with sole EH xref `0x005fe944`, but the six-state map selects it after the embedded Tree at `+0x130` completed construction. It is live complete-object destructor support, not an ordinary call route or dead fragment.
- UID000158 bytes SHA256 `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99` restore Tree vtable `0x0061a500`, destroy TreeStorage at `this+4` through UID0002MX, and tail-call LObject teardown `0x004f4a90`. The inline empty virtual destructor is the source cause.
- The nearby `0x004b59d5-0x004b59eb` thunks are compiler-generated `FolderTreePane` destructor adjustors, not template-owned source. See [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md).
- IDA confirms the concrete `Tree` vtable at `0x0061a500` and `TreeItor` vtable at `0x0061a510`; current generated metadata still omits them from vtable inventory.
- 2026-05-31 IDA MCP recheck confirmed exact starts/sizes for the split helper pages: `0x004b3d50` size `0x254`, `0x004b55e0` size `0x6d`, `0x004b56e0` size `0x7f`, `0x004b5b00` size `0xae`, `0x004b5bb0` size `0x20`, `0x004b5bd0` size `0x43`, and `0x004b5c20` size `0x1f`.
- IDA xrefs to `0x0061a500` and `0x0061a510` land in constructor/destructor and helper method vtable stores, supporting concrete project-local virtual helper objects rather than STL/runtime support.
- 2026-06-08 A005 Batch 110 IDA MCP refresh reconfirmed the same concrete helper starts and sizes, plus the two tiny iterator cleanup helpers at `0x004b57f0-0x004b57f8` and `0x004b5800-0x004b580e`. A compact xref scan reports five refs to the `Tree<FolderTreePane::TreeElem>` vtable at `0x0061a500`, 31 refs to the `TreeItor<FolderTreePane::TreeElem>` vtable at `0x0061a510`, and three constructor/destructor refs for each `FolderTreePane` vtable view at `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`. This ties the template helpers directly to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not to a standalone generated class source file.
- 2026-06-28 B009 accepted reset evidence under MCP session/database `agent_b009_0002my_20260628` confirms [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) as a full source-authored concrete specialization. The method destroys old node names, rewinds `m_storage`, default-constructs the root name, writes five `-1` link sentinels, clears loaded/expanded/hidden flags, leaves row/depth/reserved bytes untouched, and uses direct copy construction or `TreeStorage<FolderTreePane::TreeElem>::InsertAt` depending on capacity.
- 2026-06-28 B015 accepted content-dimension traversal evidence under MCP session/database `agent_b009_0002my_20260628` confirms [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) as a full source-authored concrete specialization. The method seeds a `std::deque<int>` from the start `TreeItor`, computes depth through parent links, writes row/depth fields, measures names through `GetTextWidth`, updates the caller's `maxWidth`/`rowCount`, and descends through expanded children without reading the `+0x20` hidden-skip byte.
- 2026-06-28 B007 accepted paint traversal evidence under MCP session/database `agent_b009_0002my_20260628` confirms [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) as a full source-authored concrete specialization. `FolderTreePane::PaintTree` constructs a root `TreeItor<FolderTreePane::TreeElem>` for `m_tree` at `this+0x130`, then calls the tree receiver at `0x004b2a67`. The method uses a `std::deque<int>` pending container, constructs temporary iterators, calls [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md), honors stop/skip traversal states, and descends from `lastChildIndex` through inferred `previousSiblingIndex`.
- 2026-07-12 B003 UID000149 factorization evidence confirms UID000344-UID000347 already contain the correct four source expressions `pending.push_back(start->GetIndex())` on `std::deque<int>`. Their first append calls folded UID000149 while subsequent child appends inline the same Dinkumware push/grow logic. `<deque>` is emitted once here; no custom Deque declaration/body or score/route change is needed in the four children.
- 2026-06-28 B006 accepted [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) evidence under original MCP session `supervisor_20260628_resume` and resumed session/database `agent_b009_0002my_20260628` resolves that exact storage method as marker-only source-routed support. `lookup_funcs` confirms range `0x004b3d50-0x004b3fa4`, size `0x254`; xrefs remain `0x004b227f`, `0x004b23d8`, and `0x004b5b8f`; caller decompiles show lazy expansion and reset call it only when `m_end == m_capacity`. The decompile/disassembly confirm begin/end/capacity pointer roles, `36 * newCapacity`, capacity limit `0x71c71c7`, `oldCapacity + oldCapacity/2` growth, large-allocation validation, [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) single-record copy, [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) prefix/suffix range-copy, [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) cleanup, and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) storage release. This strengthens the current concrete-template route but keeps shared `Tree<T>` header factoring as future consolidation only, not a new current owner.
- 2026-06-29 B010 accepted [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) evidence under restored MCP session `992d23de` moves that exact child from blank/empty-emitter status to marker-only source-routed support. `lookup_funcs` confirms target range `0x004b55e0-0x004b564d`, size `0x6d`, with `0xcc` padding at `0x004b55d3-0x004b55e0` and `0x004b564d-0x004b5650`; `xrefs_to`/`find code_ref` confirm calls from lazy expansion, `InsertAt`, and reset; `callees` confirms sole `SimpleUString` copy callee `0x00582a90`; and the target/range-copy/insert/reset decompiles preserve the 36-byte copied-field route. This child stays owned by [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md); this template page records the concrete-template context, not a standalone helper source file.
- 2026-06-29 B013 accepted [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) evidence under current MCP session `07c55da0` resolves that exact storage destructor as marker-only source-routed support. `lookup_funcs` confirms range `0x004b56e0-0x004b575f`, size `0x7f`, with successor `0x004b5760` separate; xrefs are `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`, reducing to constructor/EH cleanup, `Tree<FolderTreePane::TreeElem>` destruction, and outer pane destruction. The decompile/disassembly confirm begin/end/capacity pointer roles, 36-byte element stride, `+0x14` name destruction, `0x1000`/`0x1f` large-allocation validation, free through `sub_5C7526`, and zeroing all three storage pointers. Type checks still find no original UDTs for `TreeStorage`, `TreeElem`, or `FolderTreePane`, so a full standalone destructor body remains rejected; the marker is covered by the storage/template declaration route.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | Shared TreeFindFunc/TreeNode/Tree/TreeItor declarations, direct `std::vector<TreeNode<T> >` storage, exact children, vtables, source route, compiler support, generic disabled semantics, and iterator ordering are documented. |
| Confidence | 94 | Dual-instantiation layout, decorated spelling, exact children, and assigned shared owner agree; original private/member and physical-header spellings remain inferred. |
| Assignment | [UID:0004YK][Tree](by-file/Tree.md) | `Tree.h` is the resolved generic declaration/definition owner. `FolderTreePane.cpp` retains only concrete payload, filesystem, paint, hit-test, navigation, and visitor policy. |

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis keeps the source-facing template names `TreeStorage`, `Tree`, and `TreeItor`; `TreeItor` is stronger than `TreeIterator` because generated class names, vtable names, and existing helper pages consistently use that spelling. The generated class filenames remain aliases only. They are not evidence for standalone source files named `class_Tree_struct_FolderTreePane__TreeElem_.cpp`, `class_TreeStorage_struct_FolderTreePane__TreeElem_.cpp`, or `class_TreeItor_struct_FolderTreePane__TreeElem_.cpp`.

The direct source placement remains [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), with declarations most likely in `FolderTreePane.h` or a small project-local tree header included by that control. Current evidence proves this concrete instantiation and its vtables, reset/destructor/iterator helpers, and 36-byte storage behavior; it does not prove a reusable project-wide `Tree<T>` owner separate from `FolderTreePane.cpp`. Therefore the templates should be reconstructed as local/template support attached to the control and not migrated into standalone generated sources.

The accepted `TreeElem` names used by this template context are `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and final `hidden` for the `+0x20` exclusion byte. The former `isHidden` / descriptive `visibleTraversalSkip` terms remain historical. The remaining caveat is original header factoring, not concrete field meaning or the current route.

B009's accepted reset implementation follows the same concrete-specialization policy: [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) emits `template <> void Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` through the current `FolderTreePane.cpp` route. B015's accepted content-dimension implementation adds [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) as `template <> void Tree<FolderTreePane::TreeElem>::TraverseContentDimensions(...)` through that same route, and B007's accepted paint traversal implementation adds [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) as `template <> void Tree<FolderTreePane::TreeElem>::TraversePaintNodes(...)`. These exact child methods strengthen the local template support model without closing the future shared-header question; a future shared tree-template owner would need to absorb the concrete `FolderTreePane` and sibling `EventDispatcher` evidence together.

## Historical Superseded 2026-06-19 B014 TreeItor Source-Quality Sync

B014 reanalysis resolves the concrete iterator class [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) without creating a new shared source owner. The source-facing spelling is `TreeItor<FolderTreePane::TreeElem>`; do not normalize it to `TreeIterator` because the RTTI/vtable symbol `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`, cached IDA decompilation, generated class aliases, and sibling EventDispatcher specialization all preserve `TreeItor`.

The current best source model is:

```cpp
template<class T> class TreeStorage;
template<class T> class Tree;
template<class T> class TreeItor;
```

For this module, the concrete specializations remain `TreeStorage<FolderTreePane::TreeElem>`, `Tree<FolderTreePane::TreeElem>`, and `TreeItor<FolderTreePane::TreeElem>` under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). The sibling [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md) and [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) show the same vptr/tree/current-index iterator shape for `TreeItor<EventHandler *>`, so a reusable tree-template header is likely. That evidence affects final header factoring, but it does not justify moving this concrete specialization away from `FolderTreePane.cpp` while no scored shared `Tree.h` or `TreeTemplates.h` by-file owner exists.

B014 closes the prior shared-template question to this current direction: shared header factoring is likely and should be preserved as a future consolidation path, but current documentation should keep concrete specializations routed through their consumer modules. A future shared tree-template owner must absorb both FolderTreePane and EventDispatcher specializations, or explicitly document why the instantiations remain module-local.

The iterator child pages now carry first-draft method C++ for `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent`. Destructor/vtable support pages remain source-declared/generated-binary; the generic declarations should regenerate vtables, scalar deleting destructors, and EH cleanup stores rather than hand-porting those bytes as standalone C++.

## Current Resolution And Historical Open Questions

- Closed by UID0004YK: the reusable owner is the scored [UID:0004YK][Tree](by-file/Tree.md) page and physical `NexusTK/util/Tree.h`. `TreeItor<EventHandler *>` and `TreeItor<FolderTreePane::TreeElem>` share spelling/layout; construction, reset, search, insertion, unlink/disable, traversal, node access, iterator access, and iterator movement are generic header definitions. FolderTree consumer policy remains in FolderTreePane documentation.
- Closed: final documentation names for the main `TreeElem` link fields and visibility flags are now recorded above; only original symbol spelling remains unknown.

## Cross-References

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md)
- [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md)
- [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md)
- [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md)
- [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md)
- [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md)
- [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md)
- [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md)
- [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md)
- [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md)
- [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)

## Historical Superseded 2026-07-29 UID0002MZ Shared Tree Header Reconciliation

- Validator command `18916` registered [UID:0004YK][Tree](by-file/Tree.md) at `NexusTK/util/`; the inserted page header and validator UID mapping independently returned the same UID before route migration.
- `TreeNode<T>` owns five signed link indices, `T data`, and one `disabled` byte. Cross-instantiation arithmetic proves 28-byte nodes for pointer payloads and 36-byte nodes for the 12-byte FolderTree payload.
- `TreeStorage<T>` owns a 12-byte begin/end/capacity header over `TreeNode<T>` records. `Tree<T>` owns that storage; `TreeItor<T>` is the symbol-backed 12-byte iterator spelling.
- Generic iterator movement and generic declarations emit through `Tree.h`. `FolderTreePane::TreeElem`, filesystem enumeration, paint/hit-test/navigation visitors, and payload-specific reset remain concrete consumer declarations or `FolderTreePane.cpp` specializations.
- The prior FolderTree-only ownership and CPP-local template model above is retained as historical provenance. It was superseded because FolderTree and EventDispatcher instantiate the same node/link/state shape and the generic iterator methods touch no FolderTree payload fields.
- Formal CPP is intentionally blank. Formal H carries the exact shared declarations and child route; no standalone `Tree.cpp` is supported.
- Supervisor Gate 2B catalog entry `0365` now provides the complete matching IDA analysis chain: `StringBaseWide` `0x04`, payload `0x0c`, node `0x24` with `disabled +0x20`, storage `0x0c`, tree `0x10` with typed storage, and unchanged iterator `0x0c`. A01/A02/A03 read back with accepted names/types/comments, and current decompilation exposes the named storage/link/state fields.
- IDA required explicit `struct __declspec(align(4))` declarations for only the payload and node analysis UDTs because its parser otherwise materialized `0x0a`/`0x20`. Those annotations are tool-specific; the formal shared header remains natural C++ with implicit alignment and no synthetic padding. Saved IDB `412DA7E8...519CD` is current, while absent/raw earlier IDA states are historical.

## Changes

### 2026-08-24 UID0004YK Gate 2A Shared-Header Correction

- Current generic source is the scored UID0004YK `NexusTK/util/Tree.h`: TreeFindFunc/TreeNode/Tree/TreeItor declarations and definitions, direct `std::vector<TreeNode<T> >` storage, reset/search/insertion/removal/traversal, and iterator movement emit there. FolderTreePane keeps only `TreeElem` and concrete filesystem/rendering/visitor policy; there is no authored `TreeStorage<T>` or `Tree.cpp`.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below retain useful callback and binary chronology. Their former FolderTreePane-local generic route, future-shared-owner deferral, authored `TreeStorage<T>` model, direct-vector rejection, and concrete-specialization source shape are superseded by the current shared-header contract above.

- 2026-07-14 B001 UID0002N0 template-context synchronization:
  - Changed score `88/91` to `89/92`; preserved owner/emitter UID0000JG, reconstructable true, blank position, `<deque>`, the full forward-declaration/`[[CHILDREN]]` block, and every unrelated child.
  - Finalized TreeElem `hidden` semantics and recorded exact iterator order: UID00034F `30`, UID0002MZ `40`, UID0002N0 `50`, UID0002N1 `60`.
  - Added UID0002N0's candidate-before-test and ignored-return caller contract, while preserving concrete FolderTreePane emission and likely shared-header factoring as nonblocking historical uncertainty.

- 2026-07-14 B001 UID000158 template-context synchronization:
  - Preserved `88/91`, owner/emitter UID0000JG, reconstructable true, blank position, the complete existing formal forward-declaration block, `<deque>`, and every unrelated child/template fact.
  - Corrected UID000158's exact path/range and role from historical EH-only cleanup to retained complete-object Tree destructor support directly owned by UID0000F9. Recorded exact state-3 liveness, vtable/storage/LObject sequence, inline virtual destructor source cause, and scalar-wrapper distinction.
  - Preserved concrete FolderTreePane.cpp placement and likely shared-header caveat. Rejected new shared-file creation, explicit compiler teardown, scalar/EH wrapper bodies, and `std::vector` substitution.
- 2026-07-12 B003 UID000149 caller synchronization:
  - Added `<deque>` once before the concrete template declarations/`[[CHILDREN]]`.
  - Preserved score `88/91`, owner/emitter route, and every existing child body; documented the four UID000149 call expressions and later caller-local append inlining as compiler/STL factorization.

- 2026-06-29 B010 [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation support sync:
  - Score unchanged at `87/90`.
  - Updated the exact memory table and evidence notes so UID0002MW is no longer generic/blank helper wording. It is marker-only compiler-emitted `FolderTreePane::TreeElem` copy-constructor support routed through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md), with this page carrying only the concrete-template context.
  - Evidence: B010 restored MCP session `992d23de` confirmed five refs, sole `SimpleUString` callee, copied fields, non-copied reserved padding, support decompiles, and no-standalone-body proof. Shared tree-template header factoring remains a future consolidation caveat rather than a current owner transfer.

- 2026-06-29 B013 [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) implementation support sync:
  - Score unchanged at `87/90`.
  - Updated the exact memory table and evidence notes so UID0002MX is no longer an unresolved empty emitter. It now carries a marker-only covered-by disposition through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) and the current [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) concrete-template route.
  - Evidence: B013 current MCP session `07c55da0` confirmed the storage destructor range, caller categories, callee set, storage cleanup/decompile behavior, missing original UDTs, and no-standalone-full-body proof. Shared tree-template header factoring remains a future consolidation caveat rather than a current owner transfer.

- 2026-06-28 B015 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation sync:
  - Score unchanged at `87/90`.
  - Updated the exact memory table and template notes so [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) is no longer an empty emitter; it now emits a formal concrete `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions()` specialization through the current `FolderTreePane.cpp` route.
  - Evidence: B015 MCP session `agent_b009_0002my_20260628` confirmed the content traversal range, sole caller, callee set, caller context, row/depth writes, text-width accumulation, expanded child descent, and no hidden-skip read. Shared header factoring remains a future consolidation caveat rather than a blocker for this concrete emitted method.

- 2026-06-28 B006 [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) implementation support sync:
  - Score unchanged at `87/90`.
  - Updated the exact memory table and evidence notes so [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) is no longer an unresolved empty emitter. It now carries a marker-only covered-by disposition through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) and the current [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) concrete-template route.
  - Evidence: B006 MCP sessions `supervisor_20260628_resume` and `agent_b009_0002my_20260628` confirmed the storage insert range, three callers, helper fan-out, capacity/growth/allocation behavior, missing original UDTs, and no-standalone-full-body proof. Shared tree-template header factoring remains a future consolidation caveat rather than a current owner transfer.

- 2026-06-28 B007 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation support sync:
  - Score unchanged at `87/90`.
  - Updated the exact memory table and template notes so [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) is no longer an empty emitter; it now emits a formal concrete `Tree<FolderTreePane::TreeElem>::TraversePaintNodes()` specialization through the current `FolderTreePane.cpp` route.
  - Evidence: B007 MCP session/database `agent_b009_0002my_20260628` confirmed the paint caller at `0x004b2a67`, receiver at `FolderTreePane+0x130`, deque-backed pending traversal, [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) callback, stop/skip states, child-link order, and no `TreeElem+0x20` hidden-skip read. Shared header factoring remains a future consolidation caveat rather than a blocker for this concrete emitted method.
- 2026-06-28 B009 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync:
  - Score unchanged at `87/90`.
  - Updated the exact memory table and template notes so [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) is no longer an empty emitter; it now emits a formal concrete `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` specialization through the current `FolderTreePane.cpp` route.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirmed the reset range, callers, callee set, sentinel bytes, storage fast/slow append, and row/depth non-initialization. Shared header factoring remains a future consolidation caveat rather than a blocker for this concrete emitted method.

- 2026-06-26 B009 [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) 36-byte helper sync:
  - Score unchanged.
  - Added exact child pages [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) as the 36-byte `TreeStorage<FolderTreePane::TreeElem>` range-destroy, range-copy, and storage-free support produced by the insert/relocation expression.
- 2026-06-19 B014 TreeItor source-quality sync:
  - Before: `85/89`, with the shared-template question open and no EventDispatcher sibling evidence on this context page.
  - After: `87/90`, owner/emitter unchanged at [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
  - Summary/evidence: B014 resolved source-facing `TreeItor<FolderTreePane::TreeElem>` spelling, attached the iterator class-level C++ to [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md), recorded `TreeItor<EventHandler *>` sibling specialization evidence, kept the current concrete owner route through `FolderTreePane.cpp`, and preserved the likely shared-header caveat as a future consolidation path rather than creating a standalone generated class source.

- What existed before: the page had useful template hypotheses but was still scored `0/0`, had blank reconstructability metadata, and only linked the broad aggregate memory page for most helper bodies.
- What it was changed to: scored `80/88`, marked `RECONSTRUCTABLE:TRUE`, and expanded with exact by-memory pages for storage insert, element copy, storage destruction, reset-to-root, and iterator traversal helpers.
- Summary and evidence: 2026-05-31 IDA MCP verified helper starts/sizes, callers, representative decompilations, vtable xrefs, 36-byte element behavior, and iterator link offsets. Scores remain below `95` because final template header spelling, field names, and the larger directory-entry sort/helper spans still need more research before final C++ is safe.
- 2026-06-08 A005 Batch 110:
  - Before: score `80/88`, `AUTOGEN_PARENT_UID:` blank; direct parent [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) was `88/80`, below the corrected parent-side `85/85` gate.
  - Changed to: score `85/89`, `AUTOGEN_PARENT_UID:0000JG`.
  - Summary/evidence: live IDA MCP reconfirmed concrete tree/template helper starts, `Tree` and `TreeItor` vtable ref counts, three-view `FolderTreePane` vtable refs, and tiny iterator cleanup helper bounds. The refreshed [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) parent now scores `89/85`, so both child and direct parent satisfy the corrected gate.
