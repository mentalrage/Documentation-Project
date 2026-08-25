// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JG
// Source by-file doc: by-file/FolderTreePane.md
// UID:00005A | by-class/FolderTreePane.md | Completion:88 | Confidence:89
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../util/StringBase.h"
#include "../../util/Tree.h"

struct FolderTreePaintTraversalContext;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class FolderTreePane : public ScrollablePane
{
public:
    struct TreeElem
    {
        TreeElem() : childrenLoaded(0), expanded(0) {}

        mystr::StringBase<wchar_t,
                          mystr::mychar_traits<wchar_t> > name;
        short rowIndex;
        short depth;
        unsigned char childrenLoaded;
        unsigned char expanded;
    };

    struct DirectoryEntry
    {
        mystr::StringBase<wchar_t,
                          mystr::mychar_traits<wchar_t> > name;
        short rowIndex;
        short depth;
        unsigned char childrenLoaded;
        unsigned char expanded;
    };

    FolderTreePane(const wchar_t *rootName);
    virtual ~FolderTreePane();

    bool ExpandNode(TreeItor<TreeElem> *node);
    bool CollapseNode(TreeItor<TreeElem> *node);
    void RefreshTreeLayout();
    void SetRootNodeName(const wchar_t *rootName);
    void SelectNodeByPath(const wchar_t *path);
    void BuildSelectedPath(StringBaseW &outPath);
    void SetSelection(TreeItor<TreeElem> *selection);

private:
    template <class T> friend class Tree;

    int GetTreeIndentLeft(short depth) const;
    int GetTreeRowTop(short rowIndex) const;
    int GetTextWidth(const wchar_t *text) const;
    void GetNodeBounds(TreeItor<TreeElem> *node,
                       RectBounds *outBounds) const;
    void DrawTreeConnector(int x, int y);
    void DrawTreeExpandGlyph(int x, int y, bool expanded);
    void DrawFolderIcon(int x, int y, bool selected);
    void DrawTreeNodeText(int x, int y,
                          const wchar_t *text, bool selected);

    static int PaintTreeNode(FolderTreePaintTraversalContext *context,
                             TreeItor<TreeElem> *node);

    Tree<TreeElem> m_tree;
    EPFTileContext m_folderIconContext;
    TreeItor<TreeElem> m_selection;
};
