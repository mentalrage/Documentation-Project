*** UID:00005A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FolderTreePane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane

## Current Accepted UID0004YK Tree Consumer Contract

FolderTreePane.h includes ../../util/Tree.h and embeds Tree<TreeElem> plus TreeItor<TreeElem>. TreeElem is the 12-byte payload: its default constructor default-constructs name, initializes childrenLoaded and expanded to zero, and deliberately leaves rowIndex, depth, and implicit alignment bytes uninitialized. Generic links and disabled state belong to TreeNode<TreeElem>, producing the observed 0x24 record stride.

FolderTreePane.cpp retains filesystem enumeration, row/depth calculation, paint, hit-test, visible-navigation, and visitor policy. Generic construction/reset/traversal mechanics live in Tree.h; std::vector helpers, destructor wrappers, vtables, RTTI, EH reset bodies, and pooled initialization constants are compiler consequences. Historical TreeStorage and Folder-local tree-header wording below is superseded.

## Status

- Confidence: strong for filesystem-tree control core, nested `TreeElem` ownership, resolved shared Tree.h boundary, separation from FolderSelectDialog, exact vtable boundaries, and class-shell readiness; medium-high only for exact original private Folder helper spellings.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address ranges: [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md), [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), embedded-tree destructor support [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md), and non-emitting split/index [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md)
- Vtables: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- Historical generated-source lead: `source-3/simroot_v2/class_FolderTreePane.cpp`; use as provenance/search context only, not current ownership or source-route authority.
- Historical generated-size lead: `0x17c` (`380`) bytes in Wave3/Ghidra struct data. Current class-size/layout confidence comes from IDA/by-* evidence, not from the old generated-source overlay alone.

## Class Purpose

`FolderTreePane` is a `ScrollablePane`-derived filesystem tree control. It lazily expands folder nodes, sorts visible directory entries, paints folder rows with an icon and indentation, handles arrow-key and mouse navigation, keeps selection visible, and exposes selected-path construction for the owning folder dialog.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004b1b90-0x004b1ce5` | Initializes `ScrollablePane`, embedded tree storage, tile/icon context, and initial root expansion. |
| `FindFirstVisibleChild` / `ExpandNode` / `EnsureChildrenLoaded` | `0x004b1d50-0x004b253a` | Generated/search alias is `FindFirstVisibleChild`; best source-facing role is lazy expansion: builds node path, enumerates child directories into local 12-byte `DirectoryEntry` scratch records, sorts them through the local wrapper at `0x004b5280` using [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) `DirectoryEntryNameLess` and [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md) normalization support, inserts persistent `TreeElem` children, sets `childrenLoaded`/`expanded`, and refreshes layout. |
| `CollapseNode` | `0x004b2540-0x004b2575` | Clears expanded flag and refreshes layout. |
| `RefreshTreeLayout` | `0x004b2580-0x004b25d9` | Recomputes dimensions/scrollbars and preserves scroll position. |
| `SetRootNodeName` | `0x004b25e0-0x004b267d` | Calls [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md), writes the new root name, creates an iterator for root index `0`, expands it, and refreshes layout. |
| traversal helper | `0x004b2680-0x004b2728` | IDA-confirmed helper around tree iterator traversal; not active in generated method output. |
| `SelectNodeByPath` | `0x004b2730-0x004b29fb` | Splits an input path, expands intermediate nodes, and selects a matching node. |
| paint/scroll virtuals | `0x004b2a00-0x004b2b7c` | `PaintTree` prepares pane paint state, creates a root `TreeItor<TreeElem>` for `m_tree` at `+0x130`, and delegates visible-row traversal to [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md); the family exposes content/viewport extents, scroll transforms/dimensions, and canonical `GetScrollDelta` at `0x004b2b50`. |
| `OnKeyEvent` | `0x004b2b80-0x004b2d8c` | Arrow/home navigation, expand/collapse, next/previous visible traversal. |
| `OnMouseEvent` | `0x004b2dc0-0x004b2f59` | Hit-test tree rows and toggle/select clicked nodes. |
| `CalculateContentDimensions` | `0x004b2f60-0x004b3006` | Creates a root `TreeItor<TreeElem>` over `m_tree` and a `{pane,rowCount,maxWidth}` context, delegates visible-row traversal to [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md), then stores content width/height from the helper-updated `maxWidth` and `rowCount`. |
| `GetNodeBounds` | `0x004b3010-0x004b3084` | Computes row rectangle from the `rowIndex`/`depth` fields written by [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) plus text width. |
| selected-path helper / `BuildSelectedPath` | `0x004b3090-0x004b3203` | Builds a full `StringBaseW` path from the selected iterator by walking parent links; the public declaration is required by `FolderSelectDialog::OnControlCommand`. |
| `SetSelection` | [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) | Source-authored `void SetSelection(TreeItor<TreeElem> *selection)`; copies `m_selection` at `+0x170`, calls `GetNodeBounds`, uses inherited `ScrollablePane` helpers `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition` to keep the selected row visible through `m_contentRect.top/bottom`, then calls `InvalidateRect(NULL)`. The exact child page carries formal method C++; [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) remains only a stale/generated-output quality warning. |
| embedded Tree ordinary destructor support | [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) | Constructor unwind state 3 adjusts the FolderTreePane receiver by `+0x130`, then invokes the retained complete-object Tree destructor body. Source is UID0000F9's inline virtual destructor; member/base teardown is automatic. |
| scalar-deleting destructor | `0x004b5a70-0x004b5af4` | Restores vtables, destroys tree storage and base pane, conditionally deletes. |
| destructor adjustor thunks | [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) | Compiler-generated secondary/tertiary thunks into the scalar deleting destructor; ignore for handwritten source. |

[UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) is the non-emitting aggregate inventory for the core method/table/padding cluster, not a method body and not a second class-shell emitter. It remains reconstructable under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), but its `EMITTER_UIDS` stays blank because [UID:00005A] already emits the declaration-level shell with `[[CHILDREN]]` and exact method bodies must live on child by-memory pages. [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) is the current exact source method child; other core methods remain inventory until exact child pages carry implementation-ready formal C++ or child-specific no-code proofs.

## Layout Notes

- `ScrollablePane` base is at offset `0x000`.
- The class size is `0x17c` (`380`) bytes.
- Primary `FolderTreePane` view is at `this+0x00`, secondary view at `this+0xa0`, and tertiary view at `this+0xa4`.
- Exact class vtable bases are `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`; [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) covers the exact data boundary.
- `0x0061a5c4` begins UTF-16 `TREEICON.EPF` data and is the successor boundary, not more virtual rows.
- [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) and [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) are compiler-emitted class vtable layout/data markers routed through this class shell. This page should keep declaration-level C++ only; do not add raw vtable arrays, scalar deleting destructor bodies, or adjustor thunk bodies to the class formal block.
- The embedded `Tree<FolderTreePane::TreeElem>` starts at offset `0x130` (`304`); source-facing field name: `m_tree`.
- Constructor `sub_4B1B90` initializes the concrete Tree vtable and direct `std::vector<TreeNode<TreeElem> >` pointer representation at FolderTreePane `+0x134/+0x138/+0x13c`. Its six-state unwind map selects UID000158 at state 3 only after `m_tree` completed construction; partial states separately destroy `LObject` and vector storage.
- UID000158's exact 25-byte body restores Tree vtable `0x0061a500`, calls UID0002MX on Tree `+4`, and tail-calls `LObject` teardown. The body SHA256 is `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99`.
- The folder icon/tile context begins around offset `0x148` (`328`) in constructor evidence; best source-facing names are `m_folderIconContext` or `m_treeIconContext`, with exact type currently represented by inferred `EPFTileContext`.
- The selected iterator starts at offset `0x170` (`368`); best source-facing name is `m_selection`, with `m_selectedIterator` retained as a descriptive alias.
- `FolderTreePane::TreeElem` is the 12-byte nested payload emitted once in this class header. Generic `TreeNode<TreeElem>` supplies five link indices and `disabled`, producing the 36-byte stored node. See [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md).
- [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) is marker-only compiler-emitted copy-constructor support for `FolderTreePane::TreeElem`. It routes through the nested record declaration and storage/template copy users; do not model it as a standalone `FolderTreePane` method body.
- [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) uses inherited `ScrollablePane` rectangle state at `+0x110`: this pass names the accessed `+0x114/+0x11c` fields as `m_contentRect.top` and `m_contentRect.bottom`. Do not add standalone `m_viewportTop` or `m_viewportBottom` fields to `FolderTreePane`; a future final `ScrollablePane` layout pass may rename the whole inherited rectangle consistently.
- IDA confirms three `FolderTreePane` vptr views at `+0x00`, `+0xa0`, and `+0xa4`, plus helper vtables for the embedded `Tree` and selected `TreeItor`; see [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md).
- The generated `virt_meth_0x430049` and `virt_meth_0x450045` rows are false virtuals derived from the adjacent UTF-16 `TREEICON.EPF` string after the tertiary vtable, not class methods.

## Historical Superseded Batch 127 TreeElem Evidence

Live IDA MCP recheck on 2026-06-08 refreshed the nested tree-element evidence while reviewing [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) and [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md):

- `FindFirstVisibleChild` at `0x004b1d50` writes child links and uses offsets `+0x04`, `+0x08`, `+0x10`, `+0x1c`, and `+0x1d` while lazily enumerating child directories.
- `CollapseNode` at `0x004b2540` clears byte `TreeElem+0x1d`, confirming that byte as the expanded flag.
- Iterator helpers read `TreeElem+0x00` as parent, `+0x04` as first child, `+0x10` as next sibling, and byte `+0x20` as final `hidden`; UID0002N0 assigns each sibling candidate before testing the byte.
- `TreeStorage<FolderTreePane::TreeElem>` helper pages tie insert/copy/destruction directly to the nested type and the concrete storage class, while [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) remains the source file parent.

## Ownership Notes

The active generated file should be treated as polluted. Only the filesystem-tree core and local tree/sort helpers should be considered strong `FolderTreePane.cpp` contents. Chat message, surface, and help/system-message methods currently emitted under this class are documented separately in [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md).

B014's accepted 2026-06-19 FolderSelectDialog source-quality pass resolves the dialog/control boundary. [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) owns the modal picker, drive-list policy, callback field, drive-root data, and `m_folderTreePane` pointer; this class owns the control implementation, `TreeElem` payload, selected-path construction, `SetRootNodeName`, `SelectNodeByPath`, filesystem/paint/hit-test/navigation policy, and concrete Tree/TreeItor members. UID0004YK owns generic Tree storage, algorithms, and iterator source. The dialog constructor call remains consumer evidence only.

The accepted UID0000JF support contract makes the existing wide-string dependency explicit in formal H: `StringBaseW` aliases `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`, and public `BuildSelectedPath(StringBaseW &outPath)` exposes the exact `0x004b3090-0x004b3203` consumer surface. This is a declaration-only support repair; ownership and implementation remain with FolderTreePane.

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation

Accepted B008 report `00005A-FolderTreePane-class-source-quality.md` raises this class to `88/89`, keeps [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) as both canonical owner and emitter, and adds declaration-level C++ only. Method bodies remain delegated to exact by-memory children; [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) is the first exact child now ready for method C++.

2026-06-26 B011 support sync updates the class-level `SetSelection` interpretation without changing the class score. The exact child now uses the accepted `ScrollablePane` helper trio directly: `GetScrollPosition(axis)`, `GetScrollMax(axis)`, and `ApplyScrollPosition(axis, oldPosition, targetPosition)`. It preserves the binary's second scroll read before applying movement, models `this+0x114`/`this+0x11c` as inherited `m_contentRect.top`/`m_contentRect.bottom`, and models the final vtable slot `+0x20` call as `InvalidateRect(NULL)`. The old wrapper-style names `GetVerticalScrollPosition`, `SetVerticalScrollPosition`, `GetMaxVerticalScrollPosition`, and `Invalidate(false)` should be treated as historical draft wording rather than the preferred class API for this method.

### Source Split And Owner Exclusions

Final source-facing placement is `NexusTK/ui/controls/FolderTreePane.cpp` with likely `FolderTreePane.h`. [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) and [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) are consumers/embedders, not owners of this control implementation. The single confirmed constructor call at `0x004b178b` and selected-path use at `0x004b197f` prove dialog integration, but the independent vtables, embedded tree, local traversal/sort helpers, paint/input handling, and file page placement support a reusable control source split.

Generated `class_FolderTreePane.cpp` pollution is closed rather than open: chat ranges route to `Chatting`/`ChattingUI`, surface/presentation/screenshot ranges route to `Surface`, `SurfacePresentation`, and `ScreenshotCapture`, and help/system-message ranges route to `SystemMessagePanes`. These polluted generated blocks must not migrate into this class/file.

### Source-Facing Fields And Types

Best-supported field/type names:

| Offset | Source-facing name | Type / role | Status |
| --- | --- | --- | --- |
| `+0x130` | `m_tree` | `Tree<FolderTreePane::TreeElem>` | Strong. |
| near `+0x148` | `m_folderIconContext` / `m_treeIconContext` | inferred `EPFTileContext`, loaded from `TREEICON.EPF` and consumed by paint helpers | Strong role, exact type/name inferred. |
| `+0x170` | `m_selection` / `m_selectedIterator` | `TreeItor<FolderTreePane::TreeElem>` | Strong persistent selection iterator. |
| `+0x114`, `+0x11c` | inherited viewport bounds | inherited `ScrollablePane` state used by `SetSelection` | Do not promote as new `FolderTreePane` fields. |

`FolderTreePane::TreeElem` uses the accepted field names `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and final `hidden`. Path selection, per-node paint, and UID0002N0 skip nonzero records; reset/new construction writes zero; copy helpers preserve the byte. `isHidden` is superseded history, `visibleTraversalSkip` descriptive, and `hiddenOrDeleted` / `deleted` rejected. The `+0x0c` previous-sibling name remains explicitly inferred.

`Tree`, `TreeStorage`, and `TreeItor` are project-local template/support declarations attached to this control, not standalone generated source files. `TreeItor` is preferred over `TreeIterator` because generated class and vtable names consistently use that spelling. The remaining uncertainty is whether the original declarations lived in `FolderTreePane.h` or a small reusable tree header; no separate `Tree.cpp` owner is justified.

B009's accepted [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) pass makes `m_tree.ResetToSingleRoot()` formally represented as the concrete tree reset body used by the constructor/setup and `SetRootNodeName` paths. The method destroys existing node names, rewinds `m_storage`, creates one root `TreeElem`, leaves row/depth/reserved bytes untouched, clears `childrenLoaded`, `expanded`, and `hidden`, and appends by storage fast path or `InsertAt` fallback.

B006's accepted [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) pass keeps `TreeStorage<FolderTreePane::TreeElem>::InsertAt` under the [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) storage route. Lazy expansion and reset call it only when `m_end == m_capacity`; otherwise they copy-construct directly into available storage. It is marker-only formal output, not a `FolderTreePane` member body and not an unresolved empty emitter, because a full body would encode compiler-lowered allocation, relocation, EH cleanup, range-copy, destructor, and free-validation mechanics.

B010's accepted [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) pass keeps `FolderTreePane::TreeElem` copy construction under the nested [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) record route. Restored MCP session `992d23de` confirms five callers from lazy expansion, storage insertion, and reset; sole `SimpleUString` copy callee `0x00582a90`; copied link/name/row/depth/flag fields; non-copied reserved padding; and adjacent `0xcc` boundary bytes. The accepted output is a marker-only trace because the physical helper is compiler-emitted support for record copy use, not a standalone source method.

B013's accepted [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) pass keeps `TreeStorage<FolderTreePane::TreeElem>` destruction under the same [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) storage route. Partial constructor cleanup, UID000158 complete-object Tree destruction, the Tree scalar deleting destructor, and the outer `FolderTreePane` scalar deleting destructor call UID0002MX, but those callsites are ownership consumers. Source ownership remains with the concrete storage template support, and the formal output is marker-only because the binary body is compiler-lowered 36-byte element cleanup, `+0x14` name destruction, vector-storage release, and pointer zeroing rather than a standalone handwritten `FolderTreePane` method.

### Directory Entry Sort Policy

Directory-entry sort helpers operate on a local 12-byte `DirectoryEntry` / `FolderTreePane::DirectoryEntry` scratch record, not on final `TreeElem` storage. Accepted fields are `name` at `+0x00`, `row` / `rowIndex` at `+0x04`, `depth` / `depthOrIndent` at `+0x06`, `childrenLoaded` at `+0x08`, and `expanded` at `+0x09`. [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) is now the source-facing exception inside the sort cluster: it emits the private/file-local `DirectoryEntryNameLess` comparator body for the high-level `ExpandNode` / `EnsureChildrenLoaded` sort expression. The neighboring sort helpers remain compiler-generated binary support for that expression and are not public handwritten methods.

The accepted source shape keeps the comparator local to `FolderTreePane.cpp`: `DirectoryEntryNameLess(const FolderTreePane::DirectoryEntry&, const FolderTreePane::DirectoryEntry&)` copies the two `name` fields, normalizes those copies through [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md)'s detach/uppercase helper, and compares them with `WideRangeCompare`. This is distinct from persistent 36-byte `TreeElem` storage; the sorted `DirectoryEntry` scratch records are later inserted as `TreeElem` children through the tree/storage paths.

B009's source-quality pass on [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md) narrows the depth-limit helper from a stale partition label to an inferred MSVC/Dinkumware `_Adjust_heap` / heap sift-down instantiation. It receives the local record base, hole index, heap length, saved value pointer, and optimized-away comparator state, then walks heap child/parent indices. The class source should keep this as compiler-generated sort support and express the behavior through the local `DirectoryEntry` sort in the expansion method.

B009's [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) implementation split gives the class exact child pages for the remaining adjacent vector/string helper cluster. [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md) and [UID:00044A][0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct](by-memory/0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct.md) are FolderTreePane-local `DirectoryEntry` support routed through the file-level source expression. [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) are 36-byte `TreeElem` storage helpers routed through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md). [UID:000448][0x004b5cf0-0x004b5d14.SharedStringLeadingRecordRangeDestroy](by-memory/0x004b5cf0-0x004b5d14.SharedStringLeadingRecordRangeDestroy.md) and [UID:00044C][0x004b5ec0-0x004b5efc.SharedStringLeadingRecordVectorStorageFree](by-memory/0x004b5ec0-0x004b5efc.SharedStringLeadingRecordVectorStorageFree.md) are shared with SpelledPane and stay non-emitting.

### Vtables, Destructors, And C++ Boundary

The class shell in the formal C++ block is intentionally declaration-level. It captures the `ScrollablePane` inheritance, constructor/destructor, source-facing method names, `m_tree`, inferred icon context, and `m_selection`. The `[[CHILDREN]]` insertion marker is placed after the class shell because current emitted children include non-member method bodies and generated-binary support markers; exact method bodies remain outside the class declaration on their by-memory pages. UID000158 is owned by the nested UID0000F9 Tree class, not this outer class shell. Vtable data, scalar deleting destructors, constructor EH invocation, explicit member/base teardown, and adjustor thunks are source-declared/generated-binary support and should not be hand-ported.

B001's 2026-06-28 empty-emitter implementation makes [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) explicit non-emitting metadata: it keeps owner [UID:00005A], keeps `RECONSTRUCTABLE:TRUE`, clears `EMITTER_UIDS:`, and leaves formal C++ blank with no comment marker. Its source representation is this class declaration's `virtual ~FolderTreePane();`; vptr restores, adjustor-thunk routing, scalar-delete flags, guard-delete path, and the `0x17c` object-size delete are MSVC destructor glue, not source-authored body text.

B010's 2026-06-28 empty-emitter repair makes [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) explicit non-emitting aggregate metadata: it keeps owner [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), keeps `RECONSTRUCTABLE:TRUE`, clears `EMITTER_UIDS:`, and leaves formal C++ blank with no comment marker. The page's source representation is this class shell plus child method pages, not monolithic aggregate C++, duplicated [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) source, constructor EH cleanup, OnKey switch table data, or marker-only output. Preserved rejected alternatives are `FolderSelectDialog.cpp` ownership for control internals, standalone `Tree.cpp` ownership for this aggregate, wholesale migration of polluted generated `class_FolderTreePane.cpp`, handwritten vtables/thunks/EH/switch tables, treating `0x004b1cf0` as padding/source method, and duplicating [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md).

B007's 2026-06-28 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation sync resolves the paint traversal empty-emitter without changing this class page's metadata. `PaintTree` at `0x004b2a00` stores this pane in a paint traversal context at `+0x00`, creates a root `TreeItor<TreeElem>` over `m_tree`, zeroes context slot `+0x0c`, and calls [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) at `0x004b2a67`. [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) is private/file-local support emitted through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) as inferred `Tree<FolderTreePane::TreeElem>::TraversePaintNodes`, not a public virtual method on `FolderTreePane`. It owns the deque-backed visible traversal, temporary iterator construction, [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) callback route, state `0` descend / `1` stop / `2` skip child handling, `lastChildIndex` / `previousSiblingIndex` descent, and negative evidence that this traversal does not read `TreeElem+0x20` hidden/visible-skip state.

B015's 2026-06-28 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation sync resolves the content-dimension traversal empty-emitter without changing this class page's metadata. `CalculateContentDimensions` at `0x004b2f60` stores this pane in a content-dimension context, initializes `rowCount` and `maxWidth` to zero, creates a root `TreeItor<TreeElem>` over `m_tree`, and calls [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) at `0x004b2fbf`. [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) is private/file-local tree support emitted through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) as inferred `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions`, not a public `FolderTreePane` method. It owns the deque-backed visible traversal, parent-chain depth calculation, `rowIndex`/`depth` writes, node-name `GetTextWidth` measurement, `maxWidth`/`rowCount` updates, `lastChildIndex` / `previousSiblingIndex` descent for expanded nodes, and negative evidence that this traversal does not read `TreeElem+0x20` hidden/visible-skip state.

## Historical Superseded Heuristic / Inference Reanalysis And Validation

| Issue | Accepted inference / closure | Evidence and rejected alternatives |
| --- | --- | --- |
| Source file split | Keep `FolderTreePane.cpp` / likely `FolderTreePane.h` under `NexusTK/ui/controls/`. | Independent control class, vtables, tree/template helpers, painting/input, path building, file page route, and pollution ledger outweigh the single constructor caller from `FolderSelectDialog`. Rejected folding into `FolderSelectDialog.cpp`. |
| Generated owner pollution | Active generated `class_FolderTreePane.cpp` is polluted and must be filtered. | Chat, surface/presentation/screenshot, and help/system-message ranges have better owners. Rejected wholesale migration from generated class source. |
| Main fields | `m_tree`, `m_folderIconContext` / `m_treeIconContext`, and `m_selection`. | Constructor/destructor/tree helper refs, `TREEICON.EPF`, paint use, `SetSelection`, selected-path helper, key/mouse callers. Rejected generic `m_treeIterator` and `m_selectedNodeIndex` for `+0x170`. |
| `TreeElem` fields | Use accepted names above; only `previousSiblingIndex` remains explicitly inferred. | Insert/append evidence proves `lastChildIndex` and `nextSiblingIndex`; three readers plus initialization/copy evidence finalize `hidden`; bounds prove row/depth. Rejected `isHidden` as current spelling, deletion aliases, and inconsistent generated overlays. |
| `ResetToSingleRoot` | [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) now emits formal `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()` C++. | B009 MCP session `agent_b009_0002my_20260628` proves three callers, root sentinel writes, storage rewind, fast copy/`InsertAt` branch, and row/depth non-initialization. Rejected marker-only/no-code, generated wrapper structs, value-initialized root records, standalone generated tree source, and moving ownership away from [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md). |
| `InsertAt` storage support | [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) now emits a marker-only covered-by disposition through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md). | B006 MCP sessions `supervisor_20260628_resume` and `agent_b009_0002my_20260628` prove the `0x004b3d50-0x004b3fa4` range, three capacity-exhaustion callers from lazy expansion/reset, 36-byte stride, capacity limit/growth math, copy/range-copy/range-destroy/free helper fan-out, adjacent `0xcc` padding, and missing original UDTs. Rejected full decompiler-shaped body, blank marker state, clearing emitter/non-emitting, direct `FolderTreePane` ownership, `TreeElem` ownership, new shared tree-template owner, and standalone generated storage source. |
| Content-dimension traversal helper | [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) now emits formal `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions()` C++ through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). | B015 MCP session `agent_b009_0002my_20260628` proves the sole `CalculateContentDimensions` callsite, tree receiver, content context, `std::deque<int>` pending traversal, parent-chain depth calculation, row/depth writes, text-width accumulation, expanded-child order, row/depth consumer, and no `+0x20` hidden-skip read. Rejected public class method status, blank C++, owner/emitter clearing, broad aggregate emitter, standalone tree source ownership, and raw `sub_` names. |
| Paint traversal helper | [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) now emits formal `Tree<FolderTreePane::TreeElem>::TraversePaintNodes()` C++ through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). | B007 MCP session `agent_b009_0002my_20260628` proves the sole `PaintTree` callsite, tree receiver, paint context, `std::deque<int>` pending traversal, [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) callback route, stop/skip states, child-link order, and no `+0x20` hidden-skip read. Rejected public class method status, blank C++, owner/emitter clearing, folding into [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md), standalone tree source ownership, and raw `sub_` names. |

### TreeItor Support Sync

B014's accepted `0000FB` pass keeps `TreeItor<FolderTreePane::TreeElem>` attached through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) and synchronizes this class context with the concrete iterator support. The persistent selected iterator at `+0x170` remains `m_selection` / `m_selectedIterator`; the iterator itself stores `m_tree` at `+0x04` and `m_currentIndex` at `+0x08`, then exposes `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` as bool-returning traversal members. The sibling `TreeItor<EventHandler *>` specialization makes shared header factoring likely, but this class should continue to treat `TreeItor<FolderTreePane::TreeElem>` as local template support until a scored shared tree-template owner exists.

UID0002N0 reanalysis closes the iterator's current behavior and source order. UID00034F is declaration-generated destructor support at position `30`, UID0002MZ is first-child traversal at `40`, UID0002N0 is next-visible-sibling traversal at `50`, and UID0002N1 is parent traversal at `60`. The sole UID0002N0 call at `0x004b23f2` is in the best-named `ExpandNode` / `EnsureChildrenLoaded` path; that caller ignores the return and consumes `m_currentIndex`, while its 12-byte scratch iterator controls loop termination.

The class page still emits only the `FolderTreePane` shell. [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) emits the iterator class-level draft, and [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md), [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md), and [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) emit the exact method-body drafts. Destructor/vtable helper pages remain source-declared/generated-binary support and should not be hand-authored as source methods.
| Template/support placement | `Tree`, `TreeStorage`, and `TreeItor` stay attached to `FolderTreePane` as project-local template support. | Only concrete instantiation evidence is local to this control; generated filenames are aliases. Rejected standalone generated source files and unproved common `Tree.cpp`. |
| Lazy expansion name | `ExpandNode` / `EnsureChildrenLoaded` is best source-facing direction; keep `FindFirstVisibleChild` as search alias. | Body enumerates filesystem children, sorts, inserts, marks loaded/expanded, and refreshes. Rejected plain "find first child" as too narrow. |
| `SetSelection` | Exact source-authored body ready on [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md). | Three ordinary callers, selection iterator copy, bounds calculation, direct inherited scroll helpers `GetScrollPosition`/`GetScrollMax`/`ApplyScrollPosition`, inherited `m_contentRect` top/bottom fields, final `InvalidateRect(NULL)`. Rejected "missing binary behavior"; stale raw/generated rows are quality-tracker issues only. |
| Directory-entry sort | UID000343 is the private/file-local `DirectoryEntryNameLess` comparator source for the high-level sort over local 12-byte `DirectoryEntry` records; neighboring sort/vector pages remain compiler/container support. | Expansion calls the sort wrapper after building scratch records, UID000343 compares copied/normalized names through UID000446, and sorted scratch records are then inserted as persistent `TreeElem` children. Rejected public `FolderTreePane` method status, `TreeElem` ownership for the 12-byte records, and full handwritten bodies for partition/heap/swap helpers. |
| Vtables/thunks | Source-declared/generated-binary support. | Exact vtable bases and `TREEICON.EPF` boundary; adjustor thunks dispatch to scalar destructor. Rejected hand-porting arrays/thunks. |

Remaining source-quality caveats are exact original private helper spellings, exact `EPFTileContext` type spelling, and reusable template header factoring. They cap confidence below final audit but do not block the class-shell C++ or owner/emitter state.

## Cross-References

### 2026-07-13 B005 Inherited GetScrollDelta Support

- `0x004b2b50-0x004b2b7c` is the FolderTreePane override of inherited primary slot `+0x5c`, source-facing `Point *GetScrollDelta(Point *outDelta, char axis, short oldPosition, short newPosition)`.
- The body writes unscaled `oldPosition - newPosition` to the selected y/x axis and zeroes the other component. It shares the base/direct-family ABI with ChattingPane, ListPane, SystemMessagePane, OldSystemMessagePane, and TextEditPane.
- Project `Point` is y/x; old/current precedes new/target. Historical generic "scroll-delta family" wording is now resolved to `GetScrollDelta`, while `ConvertScrollDelta` remains only superseded base-history prose.
- This support synchronization does not add a new class declaration or body, change the current formal block, score, metadata, tree fields, SetSelection helper names, range, or source route. Exact method splitting/body work remains outside UID0002ES scope.
- [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md) is the exact sibling source body and cross-family naming proof.

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md)
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
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md)
- [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md)
- [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md)
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md)

## Historical Superseded 2026-07-29 UID0002MZ Header And Node/Payload Reconciliation

- Formal CPP contains only `#include "FolderTreePane.h"` plus `[[CHILDREN]]`; formal H contains the complete class declaration and child route for `NexusTK/ui/controls/FolderTreePane.h`. Exact method bodies remain child-owned rather than duplicated on this class page.
- The header includes complete `ScrollablePane`, `EPFTileContext`, pointer-backed `StringBase`, and shared [UID:0004YK][Tree](by-file/Tree.md) dependencies before by-value members are declared.
- Nested `TreeElem` is exactly 12 bytes: one-pointer wide `StringBase`, row/depth words, loaded/expanded bytes, and implicit alignment. The separate 24-byte SSO `SimpleUString` and prior 36-byte monolithic payload are superseded assumptions.
- `m_tree` stores generic 36-byte `TreeNode<TreeElem>` records; generic links/state belong to the node, and concrete payload fields are reached through `.data`.
- `PaintTreeNode` is a private static member, not a file-local function illegally reaching `m_selection`; `Tree<T>` friendship permits concrete traversal specialization access without exposing private storage.
- The accepted UID0002MZ compile callback also declares the exact nested 12-byte `DirectoryEntry` scratch record and private `GetNodeBounds(const TreeItor<TreeElem> *, RectBounds *) const` dependency required by the source-root expansion and selection bodies.
- Scores and owner/emitter stay `88/89`, UID0000JG. Existing class layout, vtable, method, pollution-exclusion, and compiler-glue evidence is preserved.
- Supervisor Gate 2B catalog entry `0365` now realizes the exact nested payload/node/storage/tree chain in IDA and types the three iterator methods through it. Current decompilation exposes `m_storage.m_begin`, generic link members, and `disabled`; method bytes, caller/xref sets, and surrounding pane behavior are unchanged.
- IDA required `__declspec(align(4))` only on its payload/node analysis declarations to obtain `0x0c`/`0x24` implicit tails. The class's human-source formal H remains natural mid-2000s C++ with the nested payload declaration above, no analysis-tool syntax, and no synthetic padding members. Saved IDB `412DA7E8...519CD` is the dated catalog0365 transaction checkpoint, not a durable current-global assertion; later bounded report readbacks preserved these target-local facts.

## Changes

### 2026-08-24 UID0004YK Gate 2A Source-Ownership Correction

- Current source authority is [UID:0004YK][Tree](by-file/Tree.md) `NexusTK/util/Tree.h`: `Tree<T>` directly owns `std::vector<TreeNode<T> >`, while UID0000FC preserves `TreeNode<T>` and concrete vector-analysis evidence only. UID0002MV/UID0002MX and related copy/destroy/free ranges are compiler/library lowerings, not authored `TreeStorage<T>` methods. `FolderTreePane.cpp` retains only the nested payload and consumer-specific filesystem, rendering, hit-test, navigation, and visitor policy.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below preserve accepted binary evidence and callback chronology. Any statement below that assigns authored source to `TreeStorage<T>`, rejects the direct vector member, defers a scored shared Tree owner, or routes generic template source through `FolderTreePane.cpp` is superseded by the current UID0004YK contract above.

- 2026-07-14 B001 UID0002N0 class-context synchronization:
  - Preserved `88/89`, owner/emitter UID0000JG, reconstructable true, the complete class shell, and all unrelated inherited/control/tree facts.
  - Finalized TreeElem `hidden` semantics/history, synchronized reset to `root.hidden`, and preserved the uninitialized row/depth/reserved behavior.
  - Added exact iterator order `30/40/50/60`, UID0002N0's sole expansion caller, ignored-return/current-index contract, scratch-loop termination, and nonblocking shared-header uncertainty.

- 2026-07-14 B001 UID000158 embedded-member lifetime synchronization:
  - Preserved `88/89`, owner/emitter UID0000JG, reconstructable true, blank position, and the complete existing FolderTreePane formal class block.
  - Added UID000158's corrected range/title and exact relation to `m_tree` at `+0x130`, constructor storage pointers, six-state unwind map, UID0002MX member destruction, LObject base teardown, Tree/scalar-wrapper vtables, and automatic reverse-order member lifetime.
  - Direct ownership stays with UID0000F9 and source-family routing stays with UID0000JG. No outer-class score/formal/metadata change, new shared file, explicit member/base teardown, scalar/EH wrapper body, or `std::vector` substitution was introduced.
- 2026-06-29 B010 [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation support sync:
  - Score unchanged at `88/89`.
  - Added class-level support that `FolderTreePane::TreeElem` copy construction is covered by the UID0002MW marker through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md), rather than a standalone class method body or unresolved empty emitter. Storage/template pages remain caller/support context.
  - Evidence: B010 restored MCP session `992d23de` confirmed UID0002MW range `0x004b55e0-0x004b564d`, five refs, sole `0x00582a90` callee, copied field order, non-copied reserved padding, predecessor/successor `0xcc` bytes, absent original UDTs, and rejected full-body / alternate-owner dispositions.

- 2026-06-29 B006 [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md) / [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) support sync:
  - Score unchanged at `88/89`.
  - Added class-level vtable/destructor/C++ boundary wording: UID00036N/UID00036O are compiler-emitted class vtable layout/data markers routed through this class shell, while the class formal C++ remains declaration-level only.
  - Preserved existing historical generated-source lead wording for `source-3/simroot_v2/class_FolderTreePane.cpp` and Wave3/Ghidra size data as provenance only, not current source-route authority. No raw vtable array, scalar deleting destructor body, or adjustor thunk body was added.

- 2026-06-29 B013 [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) implementation support sync:
  - Score unchanged at `88/89`.
  - Historicalized the active recovered-file and Wave3/Ghidra-size wording as generated-source lead material only, not current proof for UID0002MX ownership or source placement.
  - Added class-level caller/source-owner support: constructor/EH cleanup, `Tree<FolderTreePane::TreeElem>` destruction, and outer `FolderTreePane` destruction call UID0002MX, but source ownership remains [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md). The accepted output is marker-only storage destructor cleanup, not a direct `FolderTreePane` member body.
  - Evidence: B013 current MCP session `07c55da0` confirmed UID0002MX range `0x004b56e0-0x004b575f`, xrefs `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`, callees `sub_582B70`, `sub_5C7526`, and `__invalid_parameter_noinfo_noreturn`, 36-byte stride, `+0x14` name destruction, storage free/zeroing, and rejected full-body / alternate-owner dispositions.

- 2026-06-28 B013 [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) implementation support sync:
  - Added class-level source placement for `DirectoryEntryNameLess`: it is private/file-local comparator source emitted through [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not a public `FolderTreePane` method and not a generic blank sort-helper marker.
  - Updated the lazy expansion and directory-entry sort policy to preserve the 12-byte scratch `DirectoryEntry` versus 36-byte `TreeElem` distinction, [UID:000446][0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare](by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md) normalization support, and the high-level expansion sort expression.
  - Evidence: B013 accepted MCP-backed report evidence from session/database `agent_b009_0002my_20260628`; the formal comparator body belongs on exact child [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md).

- 2026-06-28 B006 [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) implementation support sync:
  - Score unchanged at `88/89`.
  - Added class-level tree/template support that `TreeStorage<FolderTreePane::TreeElem>::InsertAt` is now marker-only through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), reached from lazy expansion and reset capacity-exhaustion paths, and not a direct `FolderTreePane` member body.
  - Evidence: B006 MCP sessions `supervisor_20260628_resume` and `agent_b009_0002my_20260628` confirmed range, callers, helper fan-out, 36-byte layout use, padding, type-negative evidence, and rejected full body / blank formal / non-emitting / alternate-owner dispositions.

- 2026-06-28 B015 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation support sync:
  - Score unchanged at `88/89`.
  - Added class-level support that `CalculateContentDimensions` initializes the content-dimension context and root iterator, then delegates visible-node row/depth and width accumulation to the exact child [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md). The helper remains private/file-local source under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not a public `FolderTreePane` method. The accepted source-facing body is inferred `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions()` with `std::deque<int>` pending traversal, parent-depth calculation, `rowIndex`/`depth` writes, text-width accumulation, and last-child/previous-sibling child descent.
  - Evidence: B015 MCP session/database `agent_b009_0002my_20260628` confirmed the content-dimension caller at `0x004b2fbf`, target size `0x245`, context fields `pane`, `rowCount`, and `maxWidth`, row/depth consumer `GetNodeBounds`, exact range padding, and absence of a `TreeElem+0x20` hidden-skip read in [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md).

- 2026-06-28 B007 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation support sync:
  - Score unchanged at `88/89`.
  - Added class-level support that `PaintTree` initializes the paint traversal context and root iterator, then delegates visible-node walking to the exact child [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md). The helper remains private/file-local source under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not a public `FolderTreePane` virtual method. The accepted source-facing body is inferred `Tree<FolderTreePane::TreeElem>::TraversePaintNodes()` with [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) as `PaintFolderTreeNode`, state `0` descend, state `1` stop, state `2` skip, and last-child/previous-sibling child descent.
  - Evidence: B007 MCP session/database `agent_b009_0002my_20260628` confirmed the paint caller at `0x004b2a67`, target size `0x1f8`, per-node helper call at `0x004b375f`, sibling traversal family, and absence of a `TreeElem+0x20` hidden-skip read in [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md).

- 2026-06-28 B009 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync:
  - Score unchanged at `88/89`.
  - Added class-level support that `m_tree.ResetToSingleRoot()` is now formally represented by [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) through the `Tree<FolderTreePane::TreeElem>` route. This removes the old empty-emitter state for the reset method while preserving non-emitting dispositions for unrelated scalar deleting destructors, vtable data, EH cleanup, and broad aggregates.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirmed constructor/setup callers, `SetRootNodeName` caller behavior, root sentinel writes, storage fast/slow append, and row/depth non-initialization.

- 2026-06-28 B010 [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) empty-emitter support sync:
  - Score unchanged at `88/89`.
  - Added class-level support that [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) is a non-emitting aggregate inventory, not a method body or second `[[CHILDREN]]`/comment-marker route. [UID:00005A] remains the declaration-level class-shell emitter, [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) remains the exact source method child, other core methods stay inventory until exact child pages are ready, and compiler-generated cleanup/switch/vtable/thunk data is not handwritten source.

- 2026-06-28 B001 [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) empty-emitter support sync:
  - Score unchanged at `88/89`.
  - Added the accepted no-code disposition for [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md): blank emitter/formal C++ with no comment marker, covered by this page's `virtual ~FolderTreePane();` declaration rather than a decompiler-shaped destructor body.

- 2026-06-26 B011 [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) support sync:
  - Score unchanged at `88/89`.
  - Updated `SetSelection` support to use the accepted direct `ScrollablePane` helper names `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`, inherited `m_contentRect.top`/`m_contentRect.bottom` for the `+0x110` rectangle, and `InvalidateRect(NULL)` for the final `Pane` invalidation call. The old vertical wrapper names remain historical draft wording only.
- 2026-07-13 B005 UID0002ES support synchronization: kept `88/89`, metadata, formal class block, and all FolderTree evidence unchanged; resolved inherited slot `+0x5c` / `0x004b2b50` prose to canonical `GetScrollDelta` with Point y/x and old-before-new ABI, retaining `ConvertScrollDelta` only as superseded history.
- 2026-06-26 B009 [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) support sync:
  - Score unchanged at `88/89`.
  - Added the accepted split disposition for adjacent vector/string helpers: [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) is a non-emitting index, exact child pages now carry FolderTreePane `DirectoryEntry`, `TreeStorage<FolderTreePane::TreeElem>`, and shared SpelledPane-reused helper details.
- 2026-06-19 B014 TreeItor support sync:
  - Score unchanged at `88/89`.
  - Added the accepted iterator implementation split: this class keeps `m_selection` / `m_selectedIterator` at `+0x170`, [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) owns the concrete `TreeItor<FolderTreePane::TreeElem>` class-level draft, exact traversal children emit method bodies, and the possible shared `TreeItor<T>` header remains a future factoring caveat.

- 2026-06-19 B008 accepted source-quality implementation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, blank formal C++.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`, owner/emitter unchanged at [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), and declaration-level class-shell C++ added.
  - Summary/evidence: incorporated B008 source split, owner-pollution exclusions, field/type names, `TreeElem` model, local tree/template placement, `ExpandNode` / `EnsureChildrenLoaded` direction, `BuildSelectedPath`, `SetSelection` first-draft readiness on [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), 12-byte `DirectoryEntry` sort/source-expression policy, exact vtable bases and `TREEICON.EPF` boundary, compiler cleanup/thunk no-code policy, rejected alternatives, and remaining inference caveats.
- 2026-06-19 B014 FolderSelectDialog support sync:
  - Score unchanged at `85/86`.
  - Added accepted source-split wording: `FolderTreePane` remains under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) / `NexusTK/ui/controls/FolderTreePane.cpp`, while [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) owns only the hosted-control pointer and dialog/callback policy.
- 2026-06-21 Rule 26 B009 `00034C` support sync:
  - Score unchanged at `88/89`.
  - Added the accepted [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md) `_Adjust_heap` interpretation and no-standalone-helper policy to the class-level directory-entry sort notes.
- 2026-06-08 A006 Batch 127 parent-gate repair:
  - What existed before: score `82/84`; the class was attached to the file parent but stayed below the corrected `85/85` gate for nested `TreeElem` ownership.
  - Changed to: score `85/86`.
  - Summary/evidence: live IDA refreshed `TreeElem` field use across `FindFirstVisibleChild`, `CollapseNode`, `GetNodeBounds`, the iterator traversal helpers, the copy helper, and the storage destructor. The page now supports [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) as a direct nested type under `FolderTreePane`, while final source field names and header factoring still cap the score below final-audit quality.
- Completion/confidence score update: existed before as `0/0`; changed to `82/84`. Summary: filesystem-tree role, major methods, layout offsets, vtable views, helper ownership, false virtual caveats, and pollution boundaries are extensively documented; remaining work is final source split, field naming, and full C++ reconstruction. Evidence: core/helper/vector memory pages, `FolderTreePaneVtables`, `FolderTreePane__TreeElem`, and owner-pollution note.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) because the class is `82/84` and the parent is `88/80`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts for the core/tree/paint/input/selection/destructor methods from `0x004b1b90` through `0x004b5a70`; current `callers` confirms the constructor reference at `0x004b178b`.
