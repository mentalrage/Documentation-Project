** TARGET-REPORT-UID:0000JG **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0000JG] FolderTreePane Empty-Emitter Family Source-Quality Report

## Report-Only Scope

- Agent: B010.
- Assignment: `B010-report-0000JG-FolderTreePane-empty-emitter-family-20260630`.
- Primary target: [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md).
- Generated symptom: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` has 40 emitters, 26 filled, and 14 empty markers for the listed FolderTreePane tree/template/traversal/sort family.
- Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0000JG-FolderTreePane-empty-emitter-family-source-quality.md`.
- Report-only restrictions honored: no by-* docs edited, no generated reports or generated C++ edited, no manual `-coverage-report.md` edited, no validator/tool state edited, no IDA DB state edited, no leases taken, and no subagents spawned.

## Current Target State

[UID:0000JG] is the accepted source file route for `NexusTK/ui/controls/FolderTreePane.cpp`. Current by-file metadata is `COMPLETION:89`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, `RECONSTRUCTABLE:TRUE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`. The page already records FolderTreePane as a reusable filesystem tree control split from FolderSelectDialog, with local `TreeElem`, `TreeStorage`, `Tree`, `TreeItor`, directory-entry sort support, selected-node input/paint traversal, vtable no-code policy, and several implemented child bodies.

The current generated output read for this pass has header:

```text
// validator-command-id: 000000002992
// validator-refreshed-at: 2026-06-30T15:03:31-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JG
```

It still emits these empty markers:

| UID | Path | Current score | Current generated state |
| --- | --- | ---: | --- |
| `0001UJ` | `by-type/by-struct/FolderTreePane__TreeElem.md` | `86/89` | Empty marker. |
| `0000FC` | `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` | `85/86` | Empty marker. |
| `0000F9` | `by-class/Tree_struct_FolderTreePane__TreeElem_.md` | `85/88` | Empty marker. |
| `00034I` | `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md` | `85/88` | Empty marker. |
| `000346` | `by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md` | `86/88` | Empty marker. |
| `000347` | `by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md` | `86/88` | Empty marker. |
| `000348` | `by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md` | `86/88` | Empty marker. |
| `000349` | `by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md` | `86/88` | Empty marker. |
| `00034A` | `by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md` | `87/90` | Empty marker. |
| `00034D` | `by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md` | `86/88` | Empty marker. |
| `00034E` | `by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md` | `87/90` | Empty marker. |
| `000158` | `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md` | `85/88` | Empty marker. |
| `00034H` | `by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md` | `86/88` | Empty marker. |
| `0001WP` | `by-type/by-template/FolderTreePaneTreeTemplates.md` | `87/90` | Empty marker. |

## Evidence Checked

Current docs and generated state checked:

- [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md).
- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- `auto-generated/-ag-research-tracker.md`, `## Files With Empty Emitters`, row [UID:0000JG].
- All 14 listed empty-marker by-* pages.
- Direct type/class support pages [UID:00005A], [UID:0000FB], [UID:000157], [UID:000155], [UID:000156], [UID:00022E], [UID:00036J], [UID:00036K], [UID:00036N], [UID:00036O], [UID:000159], [UID:00034B], [UID:00034C], [UID:000343], [UID:000344], [UID:000345], [UID:0002MV], [UID:0002MW], [UID:0002MX], and [UID:0002MY] where relevant.
- `by-structure.md` gates for formal C++ emission, canonical owner/emitter route, `[[CHILDREN]]`, and source-declared/generated-binary no-code comments.
- Workflow references `b-agent-research-and-implementation-workflow.md` and `score-blocker-audit-standard.md`.

Report search terms used against current/active reports and `executed-b-agent-research`: `0000JG`, `FolderTreePane`, `0001UJ`, `0000FC`, `0000F9`, `00034I`, `000346`, `000347`, `000348`, `000349`, `00034A`, `00034D`, `00034E`, `000158`, `00034H`, `0001WP`, `0x004b3850`, `0x004b3af0`, `0x004b3fb0`, `0x004b4240`, `0x004b44c0`, `0x004b5280`, `0x004b5510`, `0x004b5650`, `0x004b5810`, `0x004b59f0`, `TreeElem`, `TreeStorage`, `TreeItor`, and `DirectoryEntry`.

Relevant prior reports opened or used as leads:

- B008 [UID:00005A] FolderTreePane class source-quality report: class shell, source split, `TreeElem`, template support, directory-entry sort handling, vtable/destructor policy.
- B010 [UID:000155] FolderTreePaneCore report: core range names, `ExpandNode`/`EnsureChildrenLoaded`, input/paint/calculation routes.
- B014 [UID:0000FB] TreeItor class report: `TreeItor` spelling, iterator layout, first-child/next-visible/parent methods.
- B009 [UID:0002MY] ResetToSingleRoot report: formal reset body and storage pointer names.
- B015 [UID:000344] TraverseContentDimensions report: accepted concrete tree traversal body and route.
- B007 [UID:000345] TraversePaintNodes report: accepted concrete tree traversal body, `PaintFolderTreeNode` route, stop/skip states.
- B013 [UID:000343] DirectoryEntryNameLess report: comparator and local 12-byte `DirectoryEntry` model.
- B008/B009 [UID:00034B]/[UID:00034C] sort reports: MSVC/Dinkumware introsort support and no-code policy.
- B006/B010/B013 [UID:0002MV]/[UID:0002MW]/[UID:0002MX] storage and record support reports: marker-only compiler support through struct/storage declarations.
- B001 [UID:000157] split report: exact helper family inventory and non-emitting aggregate role.

## Current MCP Evidence

IDA MCP was available and used for current evidence. No fallback-only conclusion is used.

- JSON-RPC `initialize` id `1`: succeeded, server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` id `3`: one active worker session, `supervisor_resume_20260629`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-06-30T13:18:38.172059`, last accessed `2026-06-30T14:55:09.432413`, `is_active:true`, `is_analyzing:false`, backend `worker`, PID/worker PID `24256`.
- `server_health` id `4`: `status:ok`, module `NexusTK.exe`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `tools/list` id `2`: confirmed the current schema, including `lookup_funcs`, `analyze_function`, `analyze_component`, `decompile`, `disasm`, `entity_query`, and `trace_data_flow`.

MCP `lookup_funcs` id `5`:

| Query | Result |
| --- | --- |
| `0x004b3850` | `sub_4B3850`, size `0x292`. |
| `0x004b3af0` | `sub_4B3AF0`, size `0x251`. |
| `0x004b3fb0` | `sub_4B3FB0`, size `0x282`. |
| `0x004b4240` | `sub_4B4240`, size `0x273`. |
| `0x004b44c0` | `sub_4B44C0`, size `0x5b`. |
| `0x004b5280` | `sub_4B5280`, size `0x290`. |
| `0x004b5510` | `sub_4B5510`, size `0xc3`. |
| `0x004b5650` | resolves inside `sub_4B1B90`, size `0x155`; not an independent function start. |
| `0x004b5810` | `sub_4B5810`, size `0x1c5`. |
| `0x004b59f0` | `sub_4B59F0`, size `0x48`. |

MCP `analyze_component` id `6` over the function family:

- Sort support internal edges: `0x4b44c0 -> 0x4b5510`, `0x4b5280 -> 0x4b5280`, and `0x4b5280 -> 0x4b4240`.
- Shared data: `TreeItor<FolderTreePane::TreeElem>` vtable `0x0061a510` accessed by `0x4b3850` and `0x4b5810`; security cookie used by seven helper bodies.
- Interface-style functions: `0x4b44c0`, `0x4b5280`, `0x4b3850`, `0x4b3fb0`, `0x4b3af0`, `0x4b5810`.
- Internal-only functions: `0x4b4240`, `0x4b5510`, `0x4b59f0`.

MCP `analyze_function` current caller/callee proof:

| Address | Prototype summary | Size | Callers | Callees / meaning |
| --- | --- | ---: | --- | --- |
| `0x004b3850` | `void __thiscall(__int16 *this, int, __int16 **)` | `658` | `sub_4B2680`, `sub_4B2DC0` | deque seed/grow/destroy, `GetTextWidth`, point-in-rect helper; hit-test traversal. |
| `0x004b3af0` | `void __thiscall(_DWORD *this, int, int)` | `593` | `sub_4B2B80` | deque seed/grow/destroy; keyboard visible navigation. |
| `0x004b3fb0` | `int __thiscall(int *this, int, int)` | `642` | `sub_4B1D50` | 12-byte vector insert/grow, throw/allocation/range-copy/free support. |
| `0x004b4240` | `const void **__cdecl(const void **, const void **)` | `627` | `sub_4B5280` | insertion sort over 12-byte entries. |
| `0x004b44c0` | `void __cdecl(int, int, int)` | `91` | `sub_4B4520` | median/order-three compare-swap, calls comparator and swap. |
| `0x004b5280` | `void __cdecl(unsigned int, unsigned int, int, int)` | `656` | `sub_4B1D50`, `sub_4B5280` | introsort driver / recursive sort wrapper. |
| `0x004b5510` | `void __cdecl(int, int)` | `195` | `sub_4B44C0` | 12-byte entry swap support. |
| `0x004b5810` | `int __thiscall(__int16 **this, void ***)` | `453` | `sub_4B3650` | per-node paint helper; draws folder/tree row and returns traversal state. |
| `0x004b59f0` | `void ***__thiscall(void ***Block, char)` | `72` | no ordinary callers | scalar deleting destructor glue. |

MCP `decompile` ids for the source-authored helper bodies:

- `0x004b3850` constructs a deque-like pending container, seeds from `start->m_currentIndex`, builds a temporary `TreeItor`, computes bounds from `TreeElem::depth` and `TreeElem::rowIndex`, measures `TreeElem::name`, calls a hit-test rectangle helper, stores the matched iterator at context offset `+0x0c`, and descends via `lastChildIndex` / `previousSiblingIndex` only when the node is expanded.
- `0x004b3af0` constructs the same pending traversal, tracks candidate/target iterators and `found` state in a keyboard navigation context, and descends only through expanded nodes.
- `0x004b5810` reads the paint context's pane pointer, computes row coordinates from `TreeElem::depth` and `rowIndex`, uses drawing helpers and `TREEICON`/selection state, reads `TreeElem::name`, compares against the selected iterator fields, and returns `0` when expanded or `2` when children should be skipped.

## Positive Evidence

- The 14 empty markers are not a single unresolved owner problem. They divide into: source-facing declaration shells (`TreeElem`, `TreeStorage`, `Tree`, tree-template context), source-authored traversal helpers (`HitTestVisibleNodes`, `FindVisibleNavigationNode`, `PaintFolderTreeNode`), and source-declared/generated-binary compiler support (tree scalar destructor, constructor EH cleanup, 12-byte directory-entry vector/sort/swap internals).
- The current owner/emitter route [UID:0000JG] is correct for all listed pages except [UID:0001UJ], whose current immediate owner is [UID:00005A] with file emission via the class/file route. No owner transfer away from FolderTreePane is supported.
- The tree receiver shape is stable. Prior accepted formal bodies already emit `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot`, `TraverseContentDimensions`, and `TraversePaintNodes`; current MCP shows [UID:000346] and [UID:000347] follow the same deque-backed visible traversal pattern.
- The nested record field model is now strong enough for a formal struct declaration. Current docs and accepted child bodies already use `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and `isHidden`.
- The tree/storage template declarations are now feasible as class shells. Existing formal children use `m_storage.m_begin`, `m_storage.m_end`, `m_storage.m_capacity`, `m_storage[index]`, `TreeItor<T>`, and concrete `Tree<FolderTreePane::TreeElem>` specializations.
- The sort-family bodies are strongly identified as MSVC/Dinkumware STL/container support generated from a high-level `FolderTreePane::ExpandNode` directory-entry collection and sort. They should get exact no-code comments, not handwritten helper bodies.
- [UID:000158] is proved by current MCP as an interior cleanup chunk of `sub_4B1B90`, not an independent source function. [UID:00034I] is a scalar deleting destructor wrapper with no ordinary callers.

## Negative Evidence

- No current evidence supports moving any listed empty marker to FolderSelectDialog, GrafPort, StringBase, generic runtime/STL ownership, or a standalone generated `Tree_struct...cpp` / `TreeStorage_struct...cpp` source file.
- No current evidence supports clearing `EMITTER_UIDS` on the source-authored traversal helpers; they are live custom UI behavior required by FolderTreePane.
- No current evidence supports raw vtable/scalar deleting destructor/EH cleanup arrays or thunk bodies as handwritten source. The correct source route is class/template declaration plus ordinary destructor semantics.
- No current evidence supports representing the directory-entry sort helpers as handwritten NexusTK functions. They have one owning call chain through `sub_4B1D50` lazy expansion and match compiler/container support.
- `0x004b5650` is not a function start in current MCP; treating [UID:000158] as a normal by-memory method body would be a false split.
- Exact historical spellings for `HitTestVisibleNodes`, `FolderTreeHitTestContext`, `FindVisibleNavigationNode`, `FolderTreeNavigationContext`, `PaintFolderTreeNode`, and `FolderTreePaintTraversalContext` are not recovered. This caps confidence but does not justify empty emitters under the current score-blocker standard.

## Heuristic / Inference Reanalysis And Validation

The previous empty-marker state is stale. The correct repair is mixed:

- For declaration pages, use formal C++ shells plus `[[CHILDREN]]` where exact child emitters should surface through the declaration route.
- For exact source-authored traversal helpers, provide first-draft formal C++ with inferred source-facing names and explicit caveats. Leaving them blank because names are inferred would violate the current score-blocker standard.
- For compiler-generated/source-declared support, provide target-specific formal no-code comments. The comments must explain why the source is regenerated by owning declarations or the high-level sort/vector expression and why a handwritten body would be less source-faithful.

The direct source file remains [UID:0000JG] `FolderTreePane.cpp`. The likely original header factoring is still broader than this one source file, especially for `Tree<T>`, `TreeStorage<T>`, and `TreeItor<T>`, but no scored shared `Tree.h`/`TreeTemplates.h` by-file owner exists. Current concrete emitters should therefore remain in `FolderTreePane.cpp` while documenting future shared-header consolidation as a caveat, not a blocker.

## Ranked Ownership And Source Placement

| Candidate | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JG] `FolderTreePane.cpp` | Accepted as source file route for this family. | Current by-file owns FolderTreePane control, local tree/template support, directory-entry sort helpers, paint/input traversal, and generated output path. Current MCP caller chains all route through FolderTreePane methods. |
| [UID:00005A] `FolderTreePane` class | Accepted as semantic class support and direct owner for nested `TreeElem`; not a replacement by-file owner. | Class page owns `m_tree`, `m_selection`, vtables, nested `TreeElem`, and private method declarations. Exact helper bodies still emit through [UID:0000JG]. |
| [UID:0001WP] tree-template context | Accepted as support context only. | It documents local/shared `TreeStorage`, `Tree`, and `TreeItor` declarations, but no standalone source file is proved. |
| [UID:000157] helper aggregate | Rejected as emitter. | It is a non-reconstructable split inventory over exact child pages. |
| Generic STL/runtime | Rejected as owner; accepted as source-shape classification for sort/vector support. | Sort helpers match Dinkumware, but concrete instantiation is caused by FolderTreePane's local `DirectoryEntry` sort. |
| FolderSelectDialog or other UI files | Rejected. | They consume FolderTreePane; they do not own local tree/template traversal or directory-entry sort internals. |

## Empty Emitter Inventory And Disposition

| UID | Before | Recommendation | Formal disposition |
| --- | ---: | --- | --- |
| `0001UJ` | `86/89` | Raise to `88/91`; keep owner `00005A`, emitter `00005A`. | Formal nested `TreeElem` struct declaration plus `[[CHILDREN]]`. |
| `0000FC` | `85/86` | Raise to `87/89`; keep owner/emitter `0000JG`. | Formal `TreeStorage<T>` shell plus `[[CHILDREN]]`. |
| `0000F9` | `85/88` | Raise to `88/90`; keep owner/emitter `0000JG`. | Formal `Tree<T>` shell plus `[[CHILDREN]]`. |
| `00034I` | `85/88` | Raise to `87/91`; keep owner `0000F9`, emitter `0000F9`. | Formal no-code scalar deleting destructor comment. |
| `000346` | `86/88` | Raise to `89/90`; keep owner/emitter `0000JG`. | First-draft formal `Tree<FolderTreePane::TreeElem>::HitTestVisibleNodes` C++. |
| `000347` | `86/88` | Raise to `89/90`; keep owner/emitter `0000JG`. | First-draft formal `Tree<FolderTreePane::TreeElem>::FindVisibleNavigationNode` C++. |
| `000348` | `86/88` | Raise to `88/91`; keep owner/emitter `0000JG`. | Formal no-code vector insert/grow comment. |
| `000349` | `86/88` | Raise to `88/91`; keep owner/emitter `0000JG`. | Formal no-code insertion-sort support comment. |
| `00034A` | `87/90` | Raise to `88/92`; keep owner/emitter `0000JG`. | Formal no-code median/order-three support comment. |
| `00034D` | `86/88` | Raise to `88/91`; keep owner/emitter `0000JG`. | Formal no-code introsort driver support comment. |
| `00034E` | `87/90` | Raise to `88/92`; keep owner/emitter `0000JG`. | Formal no-code 12-byte entry swap support comment. |
| `000158` | `85/88` | Raise to `86/90`; keep owner/emitter `0000JG`. | Formal no-code constructor EH cleanup fragment comment. |
| `00034H` | `86/88` | Raise to `89/90`; keep owner/emitter `0000JG`. | First-draft formal `PaintFolderTreeNode` C++. |
| `0001WP` | `87/90` | Raise to `88/91`; keep owner/emitter `0000JG`. | Formal template forward declarations and `[[CHILDREN]]` route marker. |

Recommended [UID:0000JG] after callback incorporation: raise from `89/85` to `91/90`. Completion should rise because all current generated empty markers have an implementation-ready formal disposition. Confidence should rise because the current MCP pass reconfirms function boundaries, callers/callees, source/compiler classification, and the remaining uncertainty is only original spelling/header factoring.

## Formal C++ / No-Code Blocks To Insert

All code below is intended as exact formal `RECONSTRUCTION_CPP CODE` content for the named target if the supervisor accepts this report. Do not place these snippets only in prose.

### [UID:0001UJ] `FolderTreePane::TreeElem`

```cpp
struct FolderTreePane::TreeElem
{
    int parentIndex;          // +0x00
    int firstChildIndex;      // +0x04
    int lastChildIndex;       // +0x08
    int previousSiblingIndex; // +0x0c, inferred source name
    int nextSiblingIndex;     // +0x10
    SimpleUString name;       // +0x14
    short rowIndex;           // +0x18
    short depth;              // +0x1a
    unsigned char childrenLoaded; // +0x1c
    unsigned char expanded;       // +0x1d
    unsigned char reserved1[2];   // +0x1e
    unsigned char isHidden;       // +0x20, visible-traversal skip
    unsigned char reserved2[3];   // +0x21
};

[[CHILDREN]]
```

### [UID:0000FC] `TreeStorage<FolderTreePane::TreeElem>`

```cpp
template <class T>
class TreeStorage
{
public:
    TreeStorage()
        : m_begin(0),
          m_end(0),
          m_capacity(0)
    {
    }

    ~TreeStorage();

    T *InsertAt(T *position, const T& value);

    T& operator[](int index) { return m_begin[index]; }
    const T& operator[](int index) const { return m_begin[index]; }

    T *m_begin;
    T *m_end;
    T *m_capacity;
};

[[CHILDREN]]
```

### [UID:0000F9] `Tree<FolderTreePane::TreeElem>`

```cpp
template <class T> class TreeItor;

struct FolderTreeContentDimensionsContext;
struct FolderTreePaintTraversalContext;
struct FolderTreeHitTestContext;
struct FolderTreeNavigationContext;

template <class T>
class Tree : public LObject
{
public:
    Tree();
    virtual ~Tree();

    void ResetToSingleRoot();
    void TraverseContentDimensions(TreeItor<T> *start,
                                   FolderTreeContentDimensionsContext *context);
    void TraversePaintNodes(TreeItor<T> *start,
                            FolderTreePaintTraversalContext *context);
    void HitTestVisibleNodes(TreeItor<T> *start,
                             FolderTreeHitTestContext *context);
    void FindVisibleNavigationNode(TreeItor<T> *start,
                                   FolderTreeNavigationContext *context);

    TreeStorage<T> m_storage;
};

[[CHILDREN]]
```

### [UID:00034I] `FolderTreeScalarDeletingDestructor`

```cpp
// Compiler-emitted scalar deleting destructor for Tree<FolderTreePane::TreeElem>.
// Recreated by the Tree<FolderTreePane::TreeElem> virtual destructor declaration,
// TreeStorage<FolderTreePane::TreeElem> cleanup, and normal delete semantics; no
// standalone handwritten source body is emitted for this wrapper.
```

### [UID:000346] `FolderTreeHitTestTraversal`

```cpp
struct FolderTreeHitTestContext
{
    FolderTreePane *pane;
    int x;
    int y;
    TreeItor<FolderTreePane::TreeElem> result;
};

template <>
void Tree<FolderTreePane::TreeElem>::HitTestVisibleNodes(
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

        FolderTreePane::TreeElem& node = m_storage[nodeIndex];

        Rect bounds;
        bounds.left = context->pane->GetTreeIndentLeft(node.depth);
        bounds.top = context->pane->GetTreeRowTop(node.rowIndex);
        bounds.right = bounds.left + 16 + context->pane->GetTextWidth(node.name.c_str());
        bounds.bottom = bounds.top + 16;

        int traversalState = kSkipChildren;
        if (bounds.Contains(context->x, context->y))
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

        if (traversalState == kSkipChildren || node.lastChildIndex == -1)
            continue;

        for (int childIndex = node.lastChildIndex; childIndex != -1;
             childIndex = m_storage[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}
```

Implementation caveat: `GetTreeIndentLeft`, `GetTreeRowTop`, and `Rect::Contains` are source-facing names for the current pane offset and rectangle-test operations. The binary evidence proves the offset/row/name-width/point-test behavior; exact helper spelling remains inferred.

### [UID:000347] `FolderTreeVisibleNavigationSearch`

```cpp
struct FolderTreeNavigationContext
{
    TreeItor<FolderTreePane::TreeElem> candidate;
    TreeItor<FolderTreePane::TreeElem> target;
    bool returnPrevious;
    bool found;
};

template <>
void Tree<FolderTreePane::TreeElem>::FindVisibleNavigationNode(
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

        FolderTreePane::TreeElem& node = m_storage[nodeIndex];
        if (!node.expanded || node.lastChildIndex == -1)
            continue;

        for (int childIndex = node.lastChildIndex; childIndex != -1;
             childIndex = m_storage[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}
```

Implementation caveat: field names in `FolderTreeNavigationContext` are inferred from current MCP offset behavior. The binary proves two iterator-like pairs, a direction byte at context offset `+0x18`, and a found byte at `+0x19`.

### [UID:000348] `FolderTreeDirectoryEntryVectorInsertAt`

```cpp
// Compiler-emitted vector insert/grow support for the FolderTreePane
// child-directory DirectoryEntry scratch vector.
// Recreated by FolderTreePane::ExpandNode collecting DirectoryEntry records
// into a local vector and sorting them; no standalone handwritten source body
// is emitted for this allocator/relocation helper.
```

### [UID:000349] `FolderTreeDirectoryEntryInsertionSort`

```cpp
// Compiler-emitted MSVC/Dinkumware insertion-sort helper for FolderTreePane
// child-directory DirectoryEntry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no
// standalone handwritten source body is emitted for this internal algorithm.
```

### [UID:00034A] `FolderTreeDirectoryEntryMedian3`

```cpp
// Compiler-emitted MSVC/Dinkumware median/order-three compare-swap helper for
// FolderTreePane child-directory DirectoryEntry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression and
// DirectoryEntryNameLess comparator; no standalone handwritten source body is
// emitted for this internal algorithm.
```

### [UID:00034D] `FolderTreeDirectoryEntrySortWrapper`

```cpp
// Compiler-emitted MSVC/Dinkumware introsort driver for FolderTreePane
// child-directory DirectoryEntry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no
// standalone handwritten source body is emitted for this internal algorithm.
```

### [UID:00034E] `FolderTreeDirectoryEntrySwap`

```cpp
// Compiler-emitted 12-byte DirectoryEntry swap support for FolderTreePane
// child-directory sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no
// standalone handwritten source body is emitted for this internal helper.
```

### [UID:000158] `FolderTreePaneTreeDestructorCleanup`

```cpp
// Constructor exception-cleanup fragment for the embedded
// Tree<FolderTreePane::TreeElem> member at FolderTreePane+0x130.
// IDA currently models 0x004b5650 inside sub_4B1B90 rather than as an
// independent function. Recreated by FolderTreePane construction/destruction
// and Tree<FolderTreePane::TreeElem> member cleanup; no standalone handwritten
// source body is emitted for this EH fragment.
```

### [UID:00034H] `FolderTreePaintNodeHelper`

```cpp
struct FolderTreePaintTraversalContext
{
    FolderTreePane *pane;
    int firstVisibleRow;
    int lastVisibleRow;
    TreeItor<FolderTreePane::TreeElem> current;
};

static int PaintFolderTreeNode(FolderTreePaintTraversalContext *context,
                               TreeItor<FolderTreePane::TreeElem> *node)
{
    const int kDescendIntoChildren = 0;
    const int kSkipChildren = 2;

    FolderTreePane *pane = context->pane;
    FolderTreePane::TreeElem& treeNode =
        node->GetTree()->m_storage[node->GetIndex()];

    const int left = pane->GetTreeIndentLeft(treeNode.depth);
    const int top = pane->GetTreeRowTop(treeNode.rowIndex);

    pane->DrawTreeConnector(left + 8, top + 8);

    if (treeNode.firstChildIndex != -1)
    {
        pane->DrawTreeExpandGlyph(left, top, treeNode.expanded != 0);
    }

    const bool selected =
        pane->m_selection.GetTree() == node->GetTree() &&
        pane->m_selection.GetIndex() == node->GetIndex();

    pane->DrawFolderIcon(left + 16, top, selected);
    pane->DrawTreeNodeText(left + 32, top, treeNode.name.c_str(), selected);

    return treeNode.expanded ? kDescendIntoChildren : kSkipChildren;
}
```

Implementation caveat: drawing helper names are inferred source-facing names for the current calls to `0x004b9600`, `0x004b9660`, `0x0069b3e4`, `0x004b98f0`, `0x004b99f0`, and `0x004bab70`. Current MCP proves coordinate computation, selection comparison, name rendering, and return state; exact historical helper spelling is not recovered.

### [UID:0001WP] `FolderTreePaneTreeTemplates`

```cpp
struct FolderTreePane::TreeElem;

template <class T> class TreeStorage;
template <class T> class Tree;
template <class T> class TreeItor;

// Concrete FolderTreePane specializations remain emitted through
// FolderTreePane.cpp until a scored shared Tree<T> header/source owner is
// accepted for both FolderTreePane and sibling tree users.
[[CHILDREN]]
```

## Rejected Alternatives

- Leave all markers blank because the original source symbols are not recovered: rejected. Current rules require first-draft formal C++ or exact no-code proof for eligible emitters.
- Move tree/template declarations to a new shared source file now: rejected. A shared template header is likely, but no scored by-file owner exists and current concrete evidence is FolderTreePane-local.
- Emit full bodies for scalar deleting destructor, constructor EH cleanup, vector insert/grow, insertion sort, median helper, sort wrapper, or swap: rejected. These are source-declared/generated-binary or compiler/STL support and should be regenerated from declarations/high-level source expressions.
- Treat [UID:000346], [UID:000347], or [UID:00034H] as no-code only because helper/context names are inferred: rejected. Current MCP proves live custom traversal/paint behavior and source route; inferred names are a confidence cap, not a blank-emitter justification.
- Clear `EMITTER_UIDS` for any listed support page: rejected. Each marker has a valid route through FolderTreePane class/file/template declarations or the by-file source expression.
- Split [UID:000158] into a normal method page: rejected. Current MCP resolves `0x004b5650` as an address inside `sub_4B1B90`, not an independent function start.
- Rename current by-memory files during this report: not recommended for this callback. Some stale names, such as `CompareSwap3` versus median/order-three, should be documented, but file renames are supervisor-controlled and not needed for empty-marker cleanup.

## Recommended Target / Support Doc Changes

If accepted, implementation should update only by-* docs in the target/support set, not generated files or manual coverage reports.

- [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md): add this family-level empty-emitter cleanup note, current MCP provenance, current generated header/marker inventory, source/compiler classification, all score before/after recommendations, and generated output expectation that the 14 markers are removed or converted to no-code comments/formal bodies.
- [UID:0001UJ][FolderTreePane__TreeElem](../../../../../by-type/by-struct/FolderTreePane__TreeElem.md): insert formal struct C++ plus `[[CHILDREN]]`; raise to `88/91`; document [UID:000346]/[UID:000347]/[UID:00034H] field-use evidence.
- [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](../../../../../by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md): insert formal storage shell plus `[[CHILDREN]]`; raise to `87/89`; keep concrete-template route through [UID:0000JG].
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](../../../../../by-class/Tree_struct_FolderTreePane__TreeElem_.md): insert formal tree shell plus `[[CHILDREN]]`; raise to `88/90`; add [UID:000346] and [UID:000347] as additional concrete source-authored traversal methods, while [UID:00034I]/[UID:000158] remain generated support.
- [UID:00034I], [UID:000158], [UID:000348], [UID:000349], [UID:00034A], [UID:00034D], [UID:00034E]: insert the exact no-code comments above, update current MCP proof and rejected handwritten-body rationale, and raise scores as listed.
- [UID:000346], [UID:000347], [UID:00034H]: insert the exact first-draft formal C++ above, update MCP evidence, caller/callee details, source-facing name caveats, and raise scores as listed.
- [UID:0001WP][FolderTreePaneTreeTemplates](../../../../../by-type/by-template/FolderTreePaneTreeTemplates.md): insert template forward declaration route marker plus `[[CHILDREN]]`; raise to `88/91`; preserve likely shared-header future consolidation without moving the current concrete route.
- Support sync where edited by callback scope: [UID:00005A] class should mention the formal `TreeElem`/tree shells and private helper bodies; [UID:000157] aggregate should mark these children as no longer empty; [UID:000155] core should preserve caller routes for hit-test/navigation/sort; [UID:000345] should already point to [UID:00034H] and needs no score change unless the supervisor accepts support sync.

## Validator And Generated Output Plan For Callback

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file. Minimum expected commands if the supervisor accepts the full report:

> Executable block R001 was removed from this report and preserved verbatim in [0000JG-FolderTreePane-empty-emitter-family-source-quality-removed.md](0000JG-FolderTreePane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validation, inspect `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` and prove:

- [UID:0001UJ], [UID:0000FC], [UID:0000F9], [UID:000346], [UID:000347], [UID:00034H], and [UID:0001WP] emit the accepted formal blocks.
- [UID:00034I], [UID:000348], [UID:000349], [UID:00034A], [UID:00034D], [UID:00034E], and [UID:000158] emit the accepted formal no-code comments.
- No listed UID remains as `Empty Emitter Marker`.
- The generated file header command id/timestamp is equal to or newer than the validator command that refreshed the route.

## Claim And Incorporation Ledger

| Claim | Destination | Action | Verification state |
| --- | --- | --- | --- |
| MCP session `supervisor_resume_20260629` is active/healthy and backs this report. | `by-file/FolderTreePane.md`; each changed target as local evidence. | applied | `by-file/FolderTreePane.md` records current MCP provenance; target pages record the accepted MCP-backed source/compiler disposition. |
| Current generated `FolderTreePane.cpp` header was command `000000002992`, refreshed `2026-06-30T15:03:31-04:00`, and had 14 listed empty markers before implementation. | `by-file/FolderTreePane.md`; target change notes. | applied | Family note in `by-file/FolderTreePane.md` preserves the before-state inventory and accepted generated-output expectation. |
| [UID:0001UJ] should emit a formal 36-byte `TreeElem` declaration with `[[CHILDREN]]`. | `by-type/by-struct/FolderTreePane__TreeElem.md`. | applied | Formal block inserted; score now `88/91`; validator `000000003100` ok. |
| [UID:0000FC] should emit a formal `TreeStorage<T>` shell with begin/end/capacity and `[[CHILDREN]]`. | `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`. | applied | Formal block inserted; score now `87/89`; validator `000000003101` ok. |
| [UID:0000F9] should emit a formal `Tree<T>` shell with traversal declarations and `[[CHILDREN]]`. | `by-class/Tree_struct_FolderTreePane__TreeElem_.md`. | applied | Formal block inserted; score now `88/90`; validator `000000003102` ok. |
| [UID:00034I] is scalar deleting destructor glue with no ordinary callers. | `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`. | applied | Formal no-code comment and accepted wrapper proof inserted; score now `87/91`; validator `000000003103` ok. |
| [UID:000346] is live source-authored hit-test traversal called from `sub_4B2680` and `OnMouseEvent`/`sub_4B2DC0`. | target [UID:000346], [UID:0000JG], [UID:0000F9]. | applied | First-draft `HitTestVisibleNodes` formal C++ and caveats inserted; score now `89/90`; validator `000000003104` ok. |
| [UID:000347] is live source-authored keyboard visible navigation traversal called from `OnKeyEvent`/`sub_4B2B80`. | target [UID:000347], [UID:0000JG], [UID:0000F9]. | applied | First-draft `FindVisibleNavigationNode` formal C++ and caveats inserted; score now `89/90`; validator `000000003105` ok. |
| [UID:000348] is compiler/vector insert-grow support for local `DirectoryEntry` vector in expansion. | target [UID:000348], [UID:0000JG], sort/vector support notes. | applied | Formal no-code comment and high-level source-expression route inserted; score now `88/91`; validator `000000003106` ok. |
| [UID:000349], [UID:00034A], [UID:00034D], [UID:00034E] are compiler/Dinkumware sort support for local `DirectoryEntry` sorting. | each target and [UID:0000JG]. | applied | Formal no-code comments inserted; scores now `000349=88/91`, `00034A=88/92`, `00034D=88/91`, `00034E=88/92`; validators `000000003107`, `000000003108`, `000000003110`, and `000000003112` ok. |
| [UID:000158] is constructor EH cleanup inside `sub_4B1B90`, not an independent function. | target [UID:000158], [UID:0000F9], [UID:0001WP]. | applied | Formal EH cleanup no-code comment and inside-function proof inserted; score now `86/90`; validator `000000003114` ok. |
| [UID:00034H] is live source-authored per-node paint helper called from [UID:000345], returns descend/skip states. | target [UID:00034H], [UID:0000JG]. | applied | First-draft `PaintFolderTreeNode` formal C++ and B007 supersession note inserted; score now `89/90`; validator `000000003116` ok. |
| [UID:0001WP] remains concrete template support through FolderTreePane with future shared-header caveat. | `by-type/by-template/FolderTreePaneTreeTemplates.md`. | applied | Formal forward-declaration route with `[[CHILDREN]]` inserted; score now `88/91`; validator `000000003118` ok. |
| [UID:0000JG] recommended score rises to `91/90`; support scores rise as listed. | target/support headers. | applied | All accepted header score changes are present; final `by-file/FolderTreePane.md` validator `000000003130` ok. |
| Implementation did not edit generated reports, generated C++ by hand, manual coverage files, validator/tool state, queue/lock files, IDA DB, supervisor ledgers, or unrelated docs. | callback execution. | applied | Only accepted by-* docs and this report were manually edited; generated `FolderTreePane.cpp` was refreshed by validator-owned generation only. |

## Implementation Validation Evidence

All validators were run from `source-3/project-documentation` with:

> Executable block R002 was removed from this report and preserved verbatim in [0000JG-FolderTreePane-empty-emitter-family-source-quality-removed.md](0000JG-FolderTreePane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| File | command_id | command_timestamp | Exit | ok | Warnings | Generated refresh |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-file/FolderTreePane.md` | `000000003130` | `2026-06-30T15:39:52-04:00` | 0 | 1 | none reported | `generated_metadata_refresh 0000JG auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` |
| `by-type/by-struct/FolderTreePane__TreeElem.md` | `000000003100` | `2026-06-30T15:32:15-04:00` | 0 | 1 | none reported | same |
| `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` | `000000003101` | `2026-06-30T15:32:25-04:00` | 0 | 1 | none reported | same |
| `by-class/Tree_struct_FolderTreePane__TreeElem_.md` | `000000003102` | `2026-06-30T15:32:36-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md` | `000000003103` | `2026-06-30T15:32:46-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md` | `000000003104` | `2026-06-30T15:32:57-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md` | `000000003105` | `2026-06-30T15:33:08-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md` | `000000003106` | `2026-06-30T15:33:19-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md` | `000000003107` | `2026-06-30T15:33:30-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md` | `000000003108` | `2026-06-30T15:33:40-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md` | `000000003110` | `2026-06-30T15:33:51-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md` | `000000003112` | `2026-06-30T15:34:11-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md` | `000000003114` | `2026-06-30T15:34:30-04:00` | 0 | 1 | none reported | same |
| `by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md` | `000000003116` | `2026-06-30T15:34:49-04:00` | 0 | 1 | none reported | same |
| `by-type/by-template/FolderTreePaneTreeTemplates.md` | `000000003118` | `2026-06-30T15:35:09-04:00` | 0 | 1 | none reported | same |

Generated freshness check: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` last-write time is `2026-06-30T15:39:57.6474861-04:00`, after final by-file validator `000000003130`. `Select-String` found no `Empty Emitter Marker` matches for accepted UID family `0000JG|0001UJ|0000FC|0000F9|00034I|000346|000347|000348|000349|00034A|00034D|00034E|000158|00034H|0001WP`.

Lease state: B010 leased the accepted by-* edit batch before editing. After validation, `python tools\leaser\leaser.py B010 unlease <accepted paths>` reported `Rejected[No active lease]` for every accepted path, indicating the short leases had already expired. `tools/leaser/Agents/current_leases.md` has no B010/FolderTreePane target entries; `tools/leaser/Agents/Agent-B010/current_leases.md` only lists unrelated stale Supervisor leases from `2026-06-18`.

## Implementation Tracking Checklist

- [x] Lease only accepted by-* files immediately before implementation edits.
- [x] Update [UID:0000JG] `by-file/FolderTreePane.md`: family-level MCP evidence, generated header/empty-marker inventory, source/compiler classification, score before/after table, rejected alternatives, and generated-output expectation; score `91/90`.
- [x] Update [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`: formal struct C++ plus `[[CHILDREN]]`, field-use evidence, score `88/91`.
- [x] Update [UID:0000FC] `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`: formal `TreeStorage<T>` shell plus `[[CHILDREN]]`, owner/emitter `0000JG`, score `87/89`.
- [x] Update [UID:0000F9] `by-class/Tree_struct_FolderTreePane__TreeElem_.md`: formal `Tree<T>` shell plus `[[CHILDREN]]`, traversal method roles and generated-support distinction, score `88/90`.
- [x] Update [UID:00034I] with current MCP size/callee/no-ordinary-caller proof, scalar deleting destructor no-code comment, score `87/91`.
- [x] Update [UID:000346] with current MCP caller/callee/decompile proof, first-draft `HitTestVisibleNodes` formal C++, inferred-name caveats, rejected no-code route, score `89/90`.
- [x] Update [UID:000347] with current MCP caller/callee/decompile proof, first-draft `FindVisibleNavigationNode` formal C++, inferred-context caveats, rejected no-code route, score `89/90`.
- [x] Update [UID:000348] with current MCP caller/callee proof, vector insert/grow no-code comment, high-level `ExpandNode` source-expression route, score `88/91`.
- [x] Update [UID:000349] with current MCP proof, insertion-sort no-code comment, score `88/91`.
- [x] Update [UID:00034A] with current MCP proof, median/order-three no-code comment, stale filename/title caveat retained in prose, score `88/92`.
- [x] Update [UID:00034D] with current MCP proof, introsort driver no-code comment, recursive/self caller note, score `88/91`.
- [x] Update [UID:00034E] with current MCP proof, 12-byte entry swap no-code comment, score `88/92`.
- [x] Update [UID:000158] with current MCP proof that `0x004b5650` resolves inside `sub_4B1B90`, EH cleanup no-code comment, score `86/90`.
- [x] Update [UID:00034H] with current MCP caller/callee/decompile proof, first-draft `PaintFolderTreeNode` formal C++, inferred drawing-helper caveats, score `89/90`.
- [x] Update [UID:0001WP] with template forward declarations, `[[CHILDREN]]`, concrete/sibling shared-header caveat, score `88/91`.
- [x] No support edits were made outside the accepted target/support list; [UID:00005A], [UID:000155], [UID:000157], and [UID:000345] were not edited because the callback did not require those extra sync pages in the lease/edit set.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`; command IDs, timestamps, exit codes, ok counts, warnings, and generated-refresh state are recorded above.
- [x] Ensure final `by-file\FolderTreePane.md` validator with `--wait-generated`; inspect `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` and prove all accepted empty markers are gone or converted to accepted formal comments/bodies.
- [x] Confirm all leases are released or expired after implementation; exact lease state is recorded above.
- [x] Update this report's Claim And Incorporation Ledger and checklist with `applied`, `already-present`, or `excluded-with-reason` proof for every accepted claim.

## Blockers

No implementation blocker remains. Residual source uncertainty is limited to exact original helper/context/drawing method spellings and final shared tree-template header factoring. That uncertainty is recorded in the formal first-draft caveats and score caps; it is not a reason to leave any listed marker empty.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000JG-FolderTreePane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000JG-FolderTreePane-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T15:45:36","uid":"0000JG"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000JG-FolderTreePane-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0000JG-FolderTreePane-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000JG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
