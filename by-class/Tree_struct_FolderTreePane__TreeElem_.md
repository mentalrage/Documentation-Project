*** UID:0000F9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Tree<T> is a header-only template emitted through Tree.h. FolderTreePane.cpp
// retains only concrete payload, visitor policy, and compiler-instantiation evidence.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
class Tree : public LObject
{
public:
    Tree() { ResetToSingleRoot(); }
    virtual ~Tree() {}
    void ResetToSingleRoot()
    {
        m_nodes.clear();
        m_nodes.push_back(TreeNode<T>());
    }
    TreeNode<T>& NodeAt(int index) { return m_nodes[index]; }
    const TreeNode<T>& NodeAt(int index) const { return m_nodes[index]; }
    bool Find(TreeFindFunc<T> *predicate, TreeItor<T> *result)
    {
        for (int i = 0; i != static_cast<int>(m_nodes.size()); ++i)
            if (!m_nodes[i].disabled && predicate->IsMatch(&m_nodes[i].data))
            {
                result->Set(this, i);
                return true;
            }
        return false;
    }
    int InsertFirstChild(int parent, const T& value)
    {
        int index = static_cast<int>(m_nodes.size());
        int oldFirst = m_nodes[parent].firstChildIndex;
        TreeNode<T> node;
        node.parentIndex = parent;
        node.nextSiblingIndex = oldFirst;
        node.data = value;
        m_nodes.push_back(node);
        m_nodes[parent].firstChildIndex = index;
        if (m_nodes[parent].lastChildIndex == -1)
            m_nodes[parent].lastChildIndex = index;
        if (oldFirst != -1)
            m_nodes[oldFirst].previousSiblingIndex = index;
        return index;
    }
    int InsertAfterSibling(int sibling, const T& value)
    {
        int index = static_cast<int>(m_nodes.size());
        int parent = m_nodes[sibling].parentIndex;
        int oldNext = m_nodes[sibling].nextSiblingIndex;
        TreeNode<T> node;
        node.parentIndex = parent;
        node.previousSiblingIndex = sibling;
        node.nextSiblingIndex = oldNext;
        node.data = value;
        m_nodes.push_back(node);
        m_nodes[sibling].nextSiblingIndex = index;
        if (oldNext == -1 && parent != -1)
            m_nodes[parent].lastChildIndex = index;
        return index;
    }
    void RemoveSubtree(int index)
    {
        TreeNode<T>& node = m_nodes[index];
        if (node.previousSiblingIndex != -1)
            m_nodes[node.previousSiblingIndex].nextSiblingIndex = node.nextSiblingIndex;
        else if (node.parentIndex != -1)
            m_nodes[node.parentIndex].firstChildIndex = node.nextSiblingIndex;
        if (node.nextSiblingIndex != -1)
            m_nodes[node.nextSiblingIndex].previousSiblingIndex = node.previousSiblingIndex;
        else if (node.parentIndex != -1)
            m_nodes[node.parentIndex].lastChildIndex = node.previousSiblingIndex;
        std::deque<int> pending;
        pending.push_back(index);
        while (!pending.empty())
        {
            int current = pending.back();
            pending.pop_back();
            m_nodes[current].disabled = 1;
            for (int child = m_nodes[current].firstChildIndex; child != -1;
                 child = m_nodes[child].nextSiblingIndex)
                pending.push_back(child);
        }
    }
    template <class Visitor>
    void Traverse(TreeItor<T> *start, Visitor *visitor)
    {
        std::deque<int> pending;
        pending.push_back(start->GetIndex());
        while (!pending.empty())
        {
            int index = pending.back();
            pending.pop_back();
            TreeItor<T> current(this, index);
            int state = (*visitor)(&current);
            if (state == 1)
                return;
            if (state == 2)
                continue;
            for (int child = m_nodes[index].lastChildIndex; child != -1;
                 child = m_nodes[child].previousSiblingIndex)
                pending.push_back(child);
        }
    }
protected:
    std::vector<TreeNode<T> > m_nodes;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Tree_struct_FolderTreePane__TreeElem_

## Current Accepted UID0004YK Complete Generic Source

This position-30 fragment is the complete reusable Tree<T> definition. Tree publicly derives LObject and is a 16-byte vptr-plus-vector object for both known instantiations. Construction resets to one root; destruction is source-empty; storage is std::vector<TreeNode<T> >. Find performs an enabled vector-order predicate scan, insertion preserves the observed link writes, removal unlinks then disables a deque-walked subtree, and Traverse supplies the shared depth-first continue/stop/skip-child skeleton used by Folder consumer policies. Concrete wrappers, vector lowering, deleting destructors, vtables, RTTI, and EH actions remain compiler or consumer evidence rather than additional authored Tree.cpp source.

## Status

- Confidence: very strong for generic behavior, live vtable identity, exact ordinary/scalar destructor boundaries, resolved UID0004YK ownership, direct vector storage, and member/base destruction.
- Source file: [UID:0004YK][Tree](by-file/Tree.md), emitted through `NexusTK/util/Tree.h`.
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a500`
- Parent attachment: [UID:0004YK][Tree](by-file/Tree.md) owns the complete generic template in `NexusTK/util/Tree.h`; [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is a concrete consumer and binary-evidence attachment.
- Reconstruction handling: shared header template. The formal `Tree<T>` definition owns generic construction/reset, search, insertion, unlink/disable, traversal, node access, and iterator access. [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md), vector lowering, and scalar wrapper UID00034I are compiler-regenerated support; FolderTreePane.cpp retains only payload and visitor policy.

## Class Purpose

This generated class page documents the concrete `Tree<FolderTreePane::TreeElem>` instantiation embedded inside [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) at offset `0x130`, while emitting the reusable generic definition through UID0004YK. `Tree<T>` directly owns `std::vector<TreeNode<T> >`, resets it to one root node, and supplies the complete generic algorithms. The linked UID0000FC page emits `TreeNode<T>`; its generated `TreeStorage...` filename is a historical analysis alias, not a wrapped authored class.

## Historical 2026-06-30 B010 Formal Tree Shell And Empty-Emitter Cleanup

B010's accepted [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) empty-emitter family implementation inserts a formal `Tree<T>` declaration shell with `[[CHILDREN]]`, keeps the concrete route through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), and raises this page from `85/88` to `88/90`.

The shell names the concrete source-authored child methods emitted by exact memory pages: `ResetToSingleRoot`, `TraverseContentDimensions`, `TraversePaintNodes`, `HitTestVisibleNodes`, and `FindVisibleNavigationNode`. It also keeps compiler-generated/source-declared support in the correct class context: [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) is scalar deleting destructor glue. Historical B010 wording called [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) only constructor EH cleanup; accepted 2026-07-14 evidence refines it to a retained complete-object Tree destructor body selected by constructor unwind state 3.

Current MCP session `supervisor_resume_20260629` confirmed [UID:000346][0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal](by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md) as `sub_4B3850`, size `0x292`, called from `sub_4B2680` and `sub_4B2DC0`, and [UID:000347][0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch](by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md) as `sub_4B3AF0`, size `0x251`, called from `sub_4B2B80`. Both are tree-receiver, deque-backed visible traversal helpers, so they belong beside the existing concrete traversal methods rather than remaining blank emitters. Shared `Tree<T>` header factoring remains likely but unproved; no owner transfer is made.

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis keeps the source-facing type as `Tree<FolderTreePane::TreeElem>` and treats the generated page name `Tree_struct_FolderTreePane__TreeElem_` as an alias only. This class is not a standalone generated source file; it is project-local tree/template support emitted through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) and used by [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) as `m_tree` at `this+0x130`.

The retained ordinary destructor at `0x004b5650-0x004b5669` and scalar deleting destructor at `0x004b59f0-0x004b5a38` are generated-binary support for the inline virtual destructor and member cleanup. Do not hand-port vtable arrays, scalar deleting destructor bodies, EH cleanup actions, or explicit member/base teardown. The reset helper at `0x004b5b00-0x004b5bae` is different: B009's accepted report classifies [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) as the source-authored `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` body, now formally emitted through this tree wrapper.

The accepted `TreeElem` field model for this wrapper is the 36-byte record with `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and final `hidden`. Path selection, paint-node state, and UID0002N0 skip nonzero records; reset/new construction writes zero and copy helpers preserve the byte. `isHidden` is historical, `visibleTraversalSkip` descriptive, and deletion aliases rejected. The unresolved issue is original template header factoring, not field semantics or tree-wrapper ownership.

B001's 2026-06-28 tree-vtable empty-emitter repair keeps [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) and [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) routed through this class as comment-only no-code vtable evidence. Those pages document compiler-emitted RTTI/vtable layout and data, not raw arrays. The current formal class body is complete enough to express the accepted inline empty virtual destructor while preserving likely future shared-header factoring as a placement caveat.

B007's 2026-06-28 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation makes the paint traversal another concrete tree-wrapper method emitted by an exact child page. The binary receiver is the embedded `Tree<FolderTreePane::TreeElem>` at `FolderTreePane+0x130`, and the source-facing name is inferred `TraversePaintNodes`. That does not promote this class page to a standalone generated `Tree.cpp` owner; it strengthens the existing `FolderTreePane.cpp`/template-support route.

B015's 2026-06-28 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation makes the content-dimension traversal another concrete tree-wrapper method emitted by an exact child page. The binary receiver is the embedded `Tree<FolderTreePane::TreeElem>` at `FolderTreePane+0x130`, and the source-facing name is inferred `TraverseContentDimensions`. That does not promote this class page to a standalone generated `Tree.cpp` owner; it strengthens the existing `FolderTreePane.cpp`/template-support route.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| ordinary destructor support | [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) | Exact 25-byte retained complete-object body selected by constructor unwind state 3; resets the Tree vtable, destroys the direct `std::vector<TreeNode<T> >` member, and tail-calls `LObject` teardown. Covered by the inline virtual destructor rather than hand-ported. |
| scalar-deleting destructor | [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) | Restores tree vtable, destroys embedded storage, tears down `LObject`, and optionally deletes. |
| `ResetToSingleRoot` | [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) | Generic UID0004YK `Tree.h` method: clears `m_nodes` and appends one default `TreeNode<T>`. The Folder instance proves five `-1` links and zero disabled state; vector growth/copy is compiler lowering. |
| `Traverse<Visitor>` content instance | [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) | Concrete instantiation of the generic deque-backed traversal skeleton with Folder-owned content policy that computes depth, writes row/depth, measures names, and updates dimensions. Generic control flow remains authored once in `Tree.h`. |
| `Traverse<Visitor>` paint instance | [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) | Concrete instantiation of the generic deque-backed traversal skeleton with Folder-owned paint policy, including stop/skip results and reverse child-link enqueue order. Generic control flow remains authored once in `Tree.h`. |

## Historical Binary Evidence Under Superseded TreeStorage Analysis Label

The exact observations below are preserved as binary provenance. Any `TreeStorage`/`m_storage` spelling in this historical section is an earlier analysis name for the direct `std::vector<TreeNode<T> > m_nodes` representation and does not assert a current authored wrapper or Folder-local generic source route.

- 2026-06-04 live IDA MCP names the tree vtable at `0x0061a500` as `??_7?$Tree@UTreeElem@FolderTreePane@@@@6B@` and reads its first slots as `0x004b59f0`, `0x004f4b10`, and `0x0041b6c0`.
- Live xrefs to the tree vtable come from the `FolderTreePane` constructor/setup paths at `0x004b1bf7` and `0x004b1d1e`, the constructor cleanup fragment at `0x004b5656`, the tree scalar deleting destructor at `0x004b59f9`, and the outer `FolderTreePane` destructor at `0x004b5aa1`.
- Live IDA confirms `0x004b59f0-0x004b5a38` as a standalone scalar deleting destructor that resets the tree vtable, calls `TreeStorage<FolderTreePane::TreeElem>` destructor `0x004b56e0` on `this + 4`, tears down `LObject` through `0x004f4a90`, and conditionally deletes through `0x004f4ac0`.
- Live IDA confirms `0x004b5650-0x004b5669` is modeled as a `sub_4B1B90` constructor/EH chunk, with a sole code xref from unwind action `0x005fe944`. The six-state map selects it after the embedded Tree completed construction, establishing retained complete-object destructor support rather than an ordinary call route.
- The exact target bytes are `56 8b f1 8d 4e 04 c7 06 00 a5 61 00 e8 7f 00 00 00 8b ce 5e e9 27 f4 03 00`, SHA256 `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99`. The final jump consumes `0x004b5668`; seven `0xcc` padding bytes begin at `0x004b5669`.
- UID000158's exact sequence restores vtable `0x0061a500`, destroys `m_storage` at `this+4` through UID0002MX, and tail-calls `LObject` teardown at `0x004f4a90`. This is entirely compiler-regenerated from the inline destructor, member, and base declarations.
- Live IDA confirms `0x004b5b00-0x004b5bae` as the reset helper, with callers at `0x004b1c18`, `0x004b1c95`, and `0x004b262a`. Decompilation destroys existing record names at `record + 0x14`, rewinds storage, initializes a root record from `xmmword_619660` plus a fifth `-1`, and calls `0x004b3d50` or `0x004b55e0` depending on capacity.
- 2026-06-28 B009 accepted MCP evidence uses session/database `agent_b009_0002my_20260628` and promotes the reset helper to formal method C++. Current decompilation/disassembly prove the root object is not value-initialized: `name` is default-constructed, five link dwords are written to `-1`, `childrenLoaded`, `expanded`, and final `hidden` are cleared, and `rowIndex`, `depth`, plus reserved bytes are not written by this path. The accepted source-facing names are `ResetToSingleRoot`, `m_storage.m_begin`, `m_storage.m_end`, `m_storage.m_capacity`, and the current `FolderTreePane::TreeElem` field names.
- 2026-06-28 B015 accepted MCP evidence uses session/database `agent_b009_0002my_20260628` and promotes [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) to formal method C++. `CalculateContentDimensions` calls it at `0x004b2fbf` with receiver `this+0x130`; [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) uses a `std::deque<int>` pending container, writes `rowIndex`/`depth`, measures `name` through `GetTextWidth`, updates a context's `maxWidth` and `rowCount`, descends through expanded `lastChildIndex` / `previousSiblingIndex` links, and does not read `TreeElem+0x20`.
- 2026-06-28 B007 accepted MCP evidence uses session/database `agent_b009_0002my_20260628` and promotes [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) to formal method C++. `PaintTree` calls it at `0x004b2a67` with receiver `this+0x130`; [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) calls [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) at `0x004b375f`, uses a `std::deque<int>` pending container, and walks child links from `lastChildIndex` through `previousSiblingIndex`.
- Boundary bytes around the tree-wrapper methods are alignment/padding: `0x004b564d-0x004b5650`, `0x004b59eb-0x004b59f0`, `0x004b5a38-0x004b5a40`, `0x004b5af4-0x004b5b00`, and `0x004b5bae-0x004b5bb0`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The page records the complete generic Tree definition, inline virtual destructor source cause, exact ordinary/scalar destructor children, direct vector/base/EH relationships, all generic methods, concrete instance evidence, and compiler-glue exclusions. |
| Confidence | 93 | Binary identity, receiver layout, vtable refs, six-state EH liveness, member/base teardown, cross-instantiation evidence, and scalar-wrapper evidence agree with the resolved shared header. |
| Reconstructable | true | UID0004YK owns the complete generic source. Its inline empty virtual destructor, direct vector member, and generic algorithms regenerate ordinary, EH, vtable, member/base, scalar destruction, and concrete instantiation behavior. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md)
- [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md)
- [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md)
- [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)

## Historical Superseded 2026-07-29 UID0002MZ Generic Tree Reconciliation

- Formal H includes complete `LObject.h` before `Tree<T> : public LObject`; formal CPP is blank because the generic template is header-defined.
- `Tree<T>` retains protected `TreeStorage<T> m_storage`, generic reset and `Traverse<Visitor>` surfaces, and public `NodeAt` access used by `TreeItor<T>`. FolderTree-specific context names do not enter the generic header.
- UID000344-UID000347 remain explicit concrete `Traverse<Context>` specializations in `FolderTreePane.cpp`; UID0002MY remains a payload-specific reset specialization.
- Existing vtable, inline virtual destructor, ordinary/scalar destruction, member/base unwind, and method-child evidence remains valid. A 36-byte record is `TreeNode<FolderTreePane::TreeElem>` containing the 12-byte payload.
- Historical assumption: the former CPP declaration exposed four FolderTree-specific traversal names and routed the template through FolderTreePane. Shared generic use and C++ template placement evidence supersede that source shape.
- Supervisor Gate 2B catalog entry `0365` preserves exact IDA size `0x10` for `FolderTreePaneTree` while replacing only the prior raw 12-byte storage array with typed `FolderTreePaneTreeStorage m_storage` at `+0x04`; the vftable artifact remains unchanged. The typed chain now drives generic iterator decompilation through `m_storage.m_begin` and named node members.
- IDA-only `__declspec(align(4))` was required on the payload/node analysis declarations, not on the human `Tree<T>` source declaration. Formal H remains natural C++ with no synthetic padding. Saved IDB `412DA7E8...519CD` is current.

## Changes

### 2026-08-24 UID0004YK Gate 2A Generic-Tree Correction

- Current authored source is the inline UID0004YK `Tree.h` template with direct `std::vector<TreeNode<T> > m_nodes`, generic algorithms, and inline virtual destructor. This page documents the concrete Folder instantiation and its exact compiler evidence; it does not route generic source through `FolderTreePane.cpp`, author `TreeStorage<T>`, reject the vector member, or defer shared-header ownership.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below preserve exact range, vtable, destructor, traversal, and payload evidence. Their former FolderTreePane-local source route, no-vector conclusion, and shared-header uncertainty are superseded by the current UID0004YK disposition above.

- 2026-07-14 B001 UID0002N0 hidden-state synchronization:
  - Preserved `90/93`, owner/emitter UID0000JG, reconstructable true, the complete formal Tree declaration, inline destructor, every method child, and all destructor/storage evidence.
  - Finalized the wrapper's TreeElem model to `hidden`, recording the visibility readers, zero initialization, copy preservation, historical `isHidden`, descriptive `visibleTraversalSkip`, and rejected deletion aliases.
  - Updated reset prose to `root.hidden = 0` without changing its deliberately uninitialized row/depth/reserved behavior or any source route.

- 2026-07-14 B001 UID000158 ordinary-destructor source sync:
  - Changed score from `88/90` to `90/93`; owner/emitter UID0000JG and all unrelated child/method content remain unchanged.
  - Replaced the declaration-only virtual destructor with the accepted inline empty definition while preserving the complete formal class block and `[[CHILDREN]]`.
  - Incorporated corrected UID000158 path/range, exact bytes/hash, six-state constructor-unwind liveness, storage/base/scalar relationships, direct class ownership, compiler-regenerated source behavior, rejected explicit teardown/`std::vector`/new-file alternatives, and bounded shared-header uncertainty.
- 2026-06-28 B015 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation support sync:
  - Score unchanged at `85/88`; class-level formal C++ remains blank pending broader `Tree<T>` declaration/header factoring.
  - Added `TraverseContentDimensions` as an exact source-authored child method for the concrete `Tree<FolderTreePane::TreeElem>` wrapper, emitted through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). Preserved rejected alternatives: standalone generated tree source, owner transfer away from FolderTreePane, public `FolderTreePane` method status, aggregate emitter status, and raw `sub_` naming.
  - Evidence: B015 MCP session/database `agent_b009_0002my_20260628` confirmed the tree receiver at `FolderTreePane+0x130`, callsite `0x004b2fbf`, content context fields, pending deque traversal, row/depth writes, text-width accumulation, and child-link descent.

- 2026-06-28 B007 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation support sync:
  - Score unchanged at `85/88`; class-level formal C++ remains blank pending broader `Tree<T>` declaration/header factoring.
  - Added `TraversePaintNodes` as an exact source-authored child method for the concrete `Tree<FolderTreePane::TreeElem>` wrapper, emitted through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). Preserved rejected alternatives: standalone generated tree source, owner transfer away from FolderTreePane, public `FolderTreePane` method status, and raw `sub_` naming.
  - Evidence: B007 MCP session/database `agent_b009_0002my_20260628` confirmed the tree receiver at `FolderTreePane+0x130`, callsite `0x004b2a67`, helper call `0x004b375f`, pending deque traversal, stop/skip states, and child-link descent.
- 2026-06-28 B009 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync:
  - Score unchanged at `85/88`.
  - Updated method/C++ status so `ResetToSingleRoot` is no longer treated as an empty-emitter or generated-binary-only helper. The exact child now emits the concrete `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` body through this wrapper, while vtable data, scalar deleting destructor glue, and constructor EH cleanup remain source-declared/generated-binary support.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirmed the reset range, three callers, decompilation/disassembly, sentinel bytes, fast copy path, `InsertAt` slow path, and row/depth non-initialization.

- 2026-06-28 B001 [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md)/[UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) tree-vtable support sync:
  - Score unchanged at `85/88`.
  - Added the accepted no-code vtable evidence route: [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) and [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) now emit comment-only no-code markers through this class, while this page itself does not receive a `Tree<T>` formal body from the vtable-data report.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the embedded tree purpose, destructor cleanup, scalar deleting destructor, reset-to-root helper, FolderTreePane offsets, type/template/vtable links, and the cleanup-ownership caveat.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed the named tree vtable at `0x0061a500`, vtable slots and xrefs from `FolderTreePane` construction/destruction/cleanup, scalar deleting destructor range and storage/base teardown behavior, reset helper callers and root-record initialization, EH-only cleanup fragment xref, and padding around the helper methods.
  - Remaining limits: final C++ stays blank because exact original template spelling/header factoring and field names are still below the final-source bar.
- 2026-06-10 B001-028 parent-gate repair:
  - Changed to: `COMPLETION:85`, retaining `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: the B001-028 split created [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md), giving this class page an exact child for the scalar deleting destructor in addition to the existing reset and EH-cleanup evidence.
  - Gate decision: the child class now clears the strict `85/85` gate against [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), so dependent tree-wrapper children may attach when they also clear `85/85`.
