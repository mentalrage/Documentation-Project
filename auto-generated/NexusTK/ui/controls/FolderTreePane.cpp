// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JG
// Source by-file doc: by-file/FolderTreePane.md
// UID:00005A | by-class/FolderTreePane.md | Completion:88 | Confidence:89
#include "FolderTreePane.h"

// UID:0001UJ | by-type/by-struct/FolderTreePane__TreeElem.md | Completion:91 | Confidence:94
// FolderTreePane::TreeElem is declared once in FolderTreePane.h by UID00005A;
// this support page intentionally emits no duplicate type definition.

// UID:00036O | by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md | Completion:89 | Confidence:93
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable data.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; do not emit
// raw vtable arrays for this range.

// UID:00036N | by-type/by-vtable/FolderTreePaneClassVtables.md | Completion:89 | Confidence:93
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable layout.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; no raw vtable
// array is emitted from this type page.

// UID:0002MY | by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md | Completion:90 | Confidence:92
/* Superseded hand-lowered concrete std::vector/reset instance retained as history.
#include <new>

template <>
void Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()
{
    typedef mystr::StringBase<wchar_t,
                             mystr::mychar_traits<wchar_t> > FolderTreeName;

    for (TreeNode<FolderTreePane::TreeElem> *node = m_storage.m_begin;
         node != m_storage.m_end;
         ++node)
    {
        node->data.name.~FolderTreeName();
    }

    m_storage.m_end = m_storage.m_begin;

    TreeNode<FolderTreePane::TreeElem> root;
    root.parentIndex = -1;
    root.firstChildIndex = -1;
    root.lastChildIndex = -1;
    root.previousSiblingIndex = -1;
    root.nextSiblingIndex = -1;
    root.data.childrenLoaded = 0;
    root.data.expanded = 0;
    root.disabled = 0;

    if (m_storage.m_end == m_storage.m_capacity)
    {
        m_storage.InsertAt(m_storage.m_end, root);
    }
    else
    {
        new (m_storage.m_end) TreeNode<FolderTreePane::TreeElem>(root);
        ++m_storage.m_end;
    }
}
*/
// Compiler instance of inline Tree<FolderTreePane::TreeElem>::ResetToSingleRoot.

// UID:0002MV | by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md | Completion:88 | Confidence:91
// Compiler-covered std::vector<TreeNode<FolderTreePane::TreeElem> >
// grow/insert instance; no authored TreeStorage or standalone body.

// UID:0002MX | by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md | Completion:88 | Confidence:91
// Compiler-covered std::vector<TreeNode<FolderTreePane::TreeElem> >
// destruction instance; no authored TreeStorage or standalone body.

// UID:000447 | by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md | Completion:87 | Confidence:91
// Compiler-covered std::vector<TreeNode<FolderTreePane::TreeElem> >
// range destruction caused by UID0004YK Tree.h; no standalone helper body.

// UID:000449 | by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md | Completion:87 | Confidence:91
// Compiler-covered std::vector<TreeNode<FolderTreePane::TreeElem> > range copy
// caused by UID0004YK Tree.h and the TreeElem payload; no standalone body.

// UID:00044B | by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md | Completion:87 | Confidence:91
// Compiler-covered std::vector<TreeNode<FolderTreePane::TreeElem> > storage
// release caused by UID0004YK Tree.h; no standalone helper body.

// UID:00034F | by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md | Completion:87 | Confidence:91
// Emitted code for this range is covered by [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md).

// UID:000158 | by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md).

// UID:00034I | by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md | Completion:87 | Confidence:91
// Compiler-emitted scalar deleting destructor for Tree<FolderTreePane::TreeElem>.
// Recreated by UID0004YK Tree.h's virtual destructor, direct std::vector member,
// and normal delete semantics; no
// standalone handwritten source body is emitted for this wrapper.

// UID:00036K | by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md | Completion:88 | Confidence:93
// Compiler-emitted Tree<FolderTreePane::TreeElem> RTTI/vtable data.
// Source reconstruction is UID0004YK Tree.h via UID0000F9; do not emit a raw
// vtable array for this range.

// UID:00036J | by-type/by-vtable/FolderTreePaneTreeVtable.md | Completion:88 | Confidence:93
// Compiler-emitted Tree<FolderTreePane::TreeElem> RTTI/vtable layout.
// Source reconstruction is routed through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md); no raw vtable array is emitted from this type page.

// UID:00036L | by-type/by-vtable/FolderTreePaneTreeItorVtable.md | Completion:86 | Confidence:92
// Compiler-emitted TreeItor<FolderTreePane::TreeElem> RTTI/vtable layout.
// Recreated by the TreeItor<T> virtual destructor declaration in Tree.h; no
// raw vtable array or standalone source definition is emitted from this page.

// UID:00036M | by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md | Completion:86 | Confidence:92
// Compiler-emitted TreeItor<FolderTreePane::TreeElem> RTTI/vtable data.
// Recreated by the TreeItor<T> virtual destructor declaration in Tree.h; no
// raw vtable array or standalone source definition is emitted for this range.

// UID:000156 | by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md | Completion:90 | Confidence:91
void FolderTreePane::SetSelection(TreeItor<TreeElem> *selection)
{
    const unsigned char kVerticalAxis = 0;

    if (selection != &m_selection)
        m_selection = *selection;

    RectBounds selectedBounds;
    GetNodeBounds(&m_selection, &selectedBounds);

    const int scrollTop = GetScrollPosition(kVerticalAxis);
    const int scrollBottom =
        scrollTop + (m_contentRect.bottom - m_contentRect.top);
    const int oldScrollTop = GetScrollPosition(kVerticalAxis);

    if (selectedBounds.top < scrollTop)
    {
        int newScrollTop = oldScrollTop + selectedBounds.top - scrollTop;
        if (newScrollTop < 0)
            newScrollTop = 0;

        ApplyScrollPosition(
            kVerticalAxis,
            static_cast<unsigned short>(oldScrollTop),
            static_cast<unsigned short>(newScrollTop));
    }
    else if (selectedBounds.bottom > scrollBottom)
    {
        int newScrollTop =
            oldScrollTop + selectedBounds.bottom - scrollBottom;
        const int maxScrollTop = GetScrollMax(kVerticalAxis);
        if (newScrollTop > maxScrollTop)
            newScrollTop = maxScrollTop;

        ApplyScrollPosition(
            kVerticalAxis,
            static_cast<unsigned short>(oldScrollTop),
            static_cast<unsigned short>(newScrollTop));
    }

    InvalidateRect(NULL);
}

// UID:000343 | by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md | Completion:90 | Confidence:91
namespace {

static mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
MakeDirectoryEntryCompareName(
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >& name)
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > key(name);
    key.DetachWideIfShared();
    _wcsupr_s(const_cast<wchar_t *>(key.c_str()), key.length() + 1);
    return key;
}

static bool DirectoryEntryNameLess(const FolderTreePane::DirectoryEntry& lhs,
                                   const FolderTreePane::DirectoryEntry& rhs)
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > lhsName =
        MakeDirectoryEntryCompareName(lhs.name);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > rhsName =
        MakeDirectoryEntryCompareName(rhs.name);

    return mystr::WideRangeCompare(
               lhsName.c_str(), lhsName.c_str() + lhsName.length(),
               rhsName.c_str(), rhsName.c_str() + rhsName.length()) < 0;
}

} // namespace

// UID:000344 | by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md | Completion:90 | Confidence:91
#include <deque>

struct FolderTreeContentDimensionsContext
{
    FolderTreePane *pane;
    int rowCount;
    int maxWidth;
};

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreeContentDimensionsContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeContentDimensionsContext *context)
{
    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_nodes[nodeIndex];
        FolderTreePane::TreeElem& node = treeNode.data;

        int depth = 0;
        for (int parentIndex = treeNode.parentIndex; parentIndex != -1;
             parentIndex = m_nodes[parentIndex].parentIndex)
        {
            ++depth;
        }

        node.depth = static_cast<short>(depth);
        node.rowIndex = static_cast<short>(context->rowCount);

        const int rowWidth =
            context->pane->GetTextWidth(node.name.c_str()) + (16 * (depth + 1));
        if (context->maxWidth < rowWidth)
        {
            context->maxWidth = rowWidth;
        }

        ++context->rowCount;

        if (node.expanded && treeNode.lastChildIndex != -1)
        {
            for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
                 childIndex = m_nodes[childIndex].previousSiblingIndex)
            {
                pending.push_back(childIndex);
            }
        }
    }
}

// UID:000345 | by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md | Completion:90 | Confidence:91
struct FolderTreePaintTraversalContext;

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreePaintTraversalContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreePaintTraversalContext *context)
{
    const int kStopTraversal = 1;
    const int kSkipChildren = 2;

    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeItor<FolderTreePane::TreeElem> node(this, nodeIndex);
        const int traversalState =
            FolderTreePane::PaintTreeNode(context, &node);
        if (traversalState == kStopTraversal)
            break;

        if (traversalState == kSkipChildren)
            continue;

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_nodes[nodeIndex];
        for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
             childIndex = m_nodes[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}

// UID:000346 | by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md | Completion:89 | Confidence:90
struct FolderTreeHitTestContext
{
    FolderTreePane *pane;
    int x;
    int y;
    TreeItor<FolderTreePane::TreeElem> result;
};

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreeHitTestContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeHitTestContext *context)
{
    const int kStopTraversal = 1;
    const int kSkipChildren = 2;

    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_nodes[nodeIndex];
        FolderTreePane::TreeElem& node = treeNode.data;

        RectBounds bounds;
        bounds.left = context->pane->GetTreeIndentLeft(node.depth);
        bounds.top = context->pane->GetTreeRowTop(node.rowIndex);
        bounds.right = bounds.left + 16 + context->pane->GetTextWidth(node.name.c_str());
        bounds.bottom = bounds.top + 16;

        int traversalState = kSkipChildren;
        if (bounds.ContainsPoint(context->y, context->x))
        {
            context->result.Set(this, nodeIndex);
            traversalState = kStopTraversal;
        }
        else if (node.expanded)
        {
            traversalState = 0;
        }

        if (traversalState == kStopTraversal)
            break;

        if (traversalState == kSkipChildren || treeNode.lastChildIndex == -1)
            continue;

        for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
             childIndex = m_nodes[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}

// UID:000347 | by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md | Completion:89 | Confidence:90
struct FolderTreeNavigationContext
{
    TreeItor<FolderTreePane::TreeElem> candidate;
    TreeItor<FolderTreePane::TreeElem> target;
    bool returnPrevious;
    bool found;
};

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreeNavigationContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeNavigationContext *context)
{
    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    bool targetSeen = false;

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeItor<FolderTreePane::TreeElem> current(this, nodeIndex);

        if (context->returnPrevious)
        {
            if (current.GetTree() == context->target.GetTree() &&
                current.GetIndex() == context->target.GetIndex())
            {
                context->found = context->candidate.GetIndex() != -1;
                break;
            }

            context->candidate = current;
        }
        else if (targetSeen)
        {
            context->candidate = current;
            context->found = true;
            break;
        }
        else if (current.GetTree() == context->target.GetTree() &&
                 current.GetIndex() == context->target.GetIndex())
        {
            targetSeen = true;
        }

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_nodes[nodeIndex];
        if (!treeNode.data.expanded || treeNode.lastChildIndex == -1)
            continue;

        for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
             childIndex = m_nodes[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}

// UID:000348 | by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md | Completion:88 | Confidence:91
// Compiler-emitted vector insert/grow support for the FolderTreePane
// child-directory DirectoryEntry scratch vector.
// Recreated by FolderTreePane::ExpandNode collecting DirectoryEntry records
// into a local vector and sorting them; no standalone handwritten source body
// is emitted for this allocator/relocation helper.

// UID:000349 | by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md | Completion:88 | Confidence:91
// Compiler-emitted MSVC/Dinkumware insertion-sort helper for FolderTreePane
// child-directory DirectoryEntry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no
// standalone handwritten source body is emitted for this internal algorithm.

// UID:00034A | by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md | Completion:88 | Confidence:92
// Compiler-emitted MSVC/Dinkumware median/order-three compare-swap helper for
// FolderTreePane child-directory DirectoryEntry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression and
// DirectoryEntryNameLess comparator; no standalone handwritten source body is
// emitted for this internal algorithm.

// UID:00034B | by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md | Completion:90 | Confidence:91
// Compiler-emitted std::sort/introsort unguarded partition specialization for
// FolderTreePane child-directory entries. Reconstructed by the high-level
// FolderTreePane::ExpandNode / EnsureChildrenLoaded directory-entry sort
// expression; no standalone handwritten source function should be emitted for
// this range.

// UID:00034C | by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md | Completion:88 | Confidence:91
// Compiler-emitted MSVC/Dinkumware std::_Adjust_heap instantiation for
// FolderTreePane child-directory entry sorting. Recreated by the owning
// FolderTreePane child-directory sort expression; no standalone handwritten source.

// UID:00034D | by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md | Completion:88 | Confidence:91
// Compiler-emitted MSVC/Dinkumware introsort driver for FolderTreePane
// child-directory DirectoryEntry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no
// standalone handwritten source body is emitted for this internal algorithm.

// UID:00034E | by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md | Completion:88 | Confidence:92
// Compiler-emitted 12-byte DirectoryEntry swap support for FolderTreePane
// child-directory sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no
// standalone handwritten source body is emitted for this internal helper.

// UID:00034H | by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md | Completion:89 | Confidence:90
struct FolderTreePaintTraversalContext
{
    FolderTreePane *pane;
    int firstVisibleRow;
    int lastVisibleRow;
    TreeItor<FolderTreePane::TreeElem> current;
};

int FolderTreePane::PaintTreeNode(
    FolderTreePaintTraversalContext *context,
    TreeItor<FolderTreePane::TreeElem> *node)
{
    const int kDescendIntoChildren = 0;
    const int kSkipChildren = 2;

    FolderTreePane *pane = context->pane;
    TreeNode<FolderTreePane::TreeElem>& treeNode =
        node->GetTree()->NodeAt(node->GetIndex());
    FolderTreePane::TreeElem& data = treeNode.data;

    const int left = pane->GetTreeIndentLeft(data.depth);
    const int top = pane->GetTreeRowTop(data.rowIndex);

    pane->DrawTreeConnector(left + 8, top + 8);

    if (treeNode.firstChildIndex != -1)
    {
        pane->DrawTreeExpandGlyph(left, top, data.expanded != 0);
    }

    const bool selected =
        pane->m_selection.GetTree() == node->GetTree() &&
        pane->m_selection.GetIndex() == node->GetIndex();

    pane->DrawFolderIcon(left + 16, top, selected);
    pane->DrawTreeNodeText(left + 32, top, data.name.c_str(), selected);

    return data.expanded ? kDescendIntoChildren : kSkipChildren;
}

// UID:000446 | by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md | Completion:88 | Confidence:91
// Compiler-emitted FolderTreePane child-directory name-normalization support.
// Reconstructed by [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) and the [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) FolderTreePane
// child-directory sort expression; no standalone helper body is emitted here.

// UID:00044A | by-memory/0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct.md | Completion:87 | Confidence:91
// Compiler-emitted FolderTreePane DirectoryEntry range-copy support.
// Reconstructed by [UID:000348][0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt](by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md) and the [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) child-directory
// vector source expression; no standalone helper body is emitted here.

// UID:00047Z | by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md | Completion:90 | Confidence:94
// Shared pooled wide path-separator literal is emitted at source use sites such as version-resource root queries and path construction; no standalone data definition is emitted here.

// UID:0003BH | by-memory\0x0061a5e0-0x0061a5ec.FolderTreePathFragmentStrings.md | Completion:85 | Confidence:91 | Empty Emitter Marker
