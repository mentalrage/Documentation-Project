// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0004YK
// Source by-file doc: by-file/Tree.md
// UID:0001WP | by-type/by-template/FolderTreePaneTreeTemplates.md | Completion:93 | Confidence:94
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

// UID:0000FC | by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md | Completion:90 | Confidence:93
template <class T>
struct TreeNode
{
    TreeNode()
        : parentIndex(-1), firstChildIndex(-1), lastChildIndex(-1),
          previousSiblingIndex(-1), nextSiblingIndex(-1), disabled(0) {}

    int parentIndex;
    int firstChildIndex;
    int lastChildIndex;
    int previousSiblingIndex;
    int nextSiblingIndex;
    T data;
    unsigned char disabled;
};

// UID:0000FB | by-class/TreeItor_struct_FolderTreePane__TreeElem_.md | Completion:91 | Confidence:94
template <class T>
class TreeItor
{
public:
    TreeItor()
        : m_tree(0),
          m_currentIndex(-1)
    {
    }

    TreeItor(Tree<T> *tree, int currentIndex)
        : m_tree(tree),
          m_currentIndex(currentIndex)
    {
    }

    virtual ~TreeItor()
    {
    }

    bool MoveToFirstChild();
    bool MoveToNextVisibleSibling();
    bool MoveToParent();

    Tree<T> *GetTree() const { return m_tree; }
    int GetIndex() const { return m_currentIndex; }
    void Set(Tree<T> *tree, int currentIndex)
    {
        m_tree = tree;
        m_currentIndex = currentIndex;
    }

private:
    Tree<T> *m_tree;
    int m_currentIndex;
};

// UID:0000F9 | by-class/Tree_struct_FolderTreePane__TreeElem_.md | Completion:91 | Confidence:93
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

// UID:0002MZ | by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md | Completion:91 | Confidence:93
template <class T>
bool TreeItor<T>::MoveToFirstChild()
{
    int childIndex = m_tree->NodeAt(m_currentIndex).firstChildIndex;
    if (childIndex == -1)
        return false;

    m_currentIndex = childIndex;
    return true;
}

// UID:0002N0 | by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md | Completion:92 | Confidence:94
template <class T>
bool TreeItor<T>::MoveToNextVisibleSibling()
{
    int siblingIndex = m_tree->NodeAt(m_currentIndex).nextSiblingIndex;
    while (siblingIndex != -1)
    {
        m_currentIndex = siblingIndex;
        if (!m_tree->NodeAt(siblingIndex).disabled)
            return true;

        siblingIndex = m_tree->NodeAt(siblingIndex).nextSiblingIndex;
    }

    return false;
}

// UID:0002N1 | by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md | Completion:91 | Confidence:93
template <class T>
bool TreeItor<T>::MoveToParent()
{
    int parentIndex = m_tree->NodeAt(m_currentIndex).parentIndex;
    if (parentIndex == -1)
        return false;

    m_currentIndex = parentIndex;
    return true;
}
