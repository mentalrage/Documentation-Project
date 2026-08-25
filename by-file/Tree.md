*** UID:0004YK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Tree

## Current Accepted UID0004YK Source Definition

- Canonical authored unit: reusable header-only NexusTK/util/Tree.h. There is no authored Tree.cpp body; a comment-only generated CPP is the correct no-source disposition.
- Semantic state: reconstructable true at 94/96. The by-file schema intentionally has no RECONSTRUCTABLE metadata key.
- Source order: UID0001WP position 0 owns LObject/deque/vector dependencies, forwards, and TreeFindFunc; UID0000FC position 10 owns TreeNode; UID0000FB position 20 owns TreeItor; UID0000F9 position 30 owns complete Tree; UID0002MZ/N0/N1 positions 40/50/60 own movement definitions.
- Authored inventory: TreeFindFunc<T>, TreeNode<T>, TreeItor<T>, Tree<T>, construction/reset, predicate search, first-child and after-sibling insertion, subtree unlink/disable, generic traversal, node access, iterator access/set/movement, and inline empty virtual destructors.
- Storage: std::vector<TreeNode<T> >. The descriptive three-pointer TreeStorage UDTs and concrete vector insert/copy/destroy/free routines are compiler-analysis views, not authored TreeStorage<T> source.
- Consumer map: EventDispatcher uses the 0x1c EventHandler* node and TreeFindFunc predicate; FolderTreePane uses the 0x24 TreeElem node and owns filesystem, paint, hit-test, visible-navigation, and visitor policy.
- Binary-only inventory: concrete template instantiations, vector lowering, ordinary/scalar deleting destructors, vtable/RTTI/EH support, and the pooled four-dword -1 constant at 0x00619660 are compiler consequences. Source writes link members and does not reproduce the pooled constant.
- Negative inventory: Tree owns no standalone global, static, string, table, resource, import, or source island. Third-party import is not applicable; this is project-authored custom template source.
- Durable state: current ordinary/generated artifacts and validator-owned metadata are authoritative. Registration, migration wave, callback, and lifecycle prose below is dated history and does not assert current supervisor or lifecycle completion.

The complete ownership map retains Event code at 0x004a6a80-0x004a88d2 and data at 0x00619628-0x00619670 as mixed generic instances, consumer wrappers, and compiler support. It retains Folder code at 0x004b3350-0x004b5ebc and data at 0x0061a4fc-0x0061a518 as mixed generic instances, Folder policy, vector lowering, destructor/vtable support, and bounded padding. Raw destructor/vtable heads and gaps are evidence boundaries, not additional authored Tree.cpp functions.

## Status

- Proposed header: `NexusTK/util/Tree.h`.
- Standalone source: none. Current evidence supports a shared template header, not `Tree.cpp`.
- Confidence: strong for the shared five-link node prefix, payload/state separation, 12-byte storage header, 12-byte iterator layout, symbol-backed `TreeItor` spelling, and header-defined generic traversal members; medium-high for the inferred `TreeNode`, `data`, `disabled`, and physical `Tree.h` spellings.
- Primary template coordinator: [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md).
- Concrete consumers: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) and EventDispatcher-family documentation.

## File Role

`Tree.h` owns the reusable project tree templates shared by at least `FolderTreePane` and EventDispatcher: `TreeFindFunc<T>`, `TreeNode<T>`, `Tree<T>`, and the symbol-backed `TreeItor<T>`. `Tree<T>` stores `std::vector<TreeNode<T> >` directly and owns generic construction, reset, search, insertion, unlink/disable, traversal, node access, and iterator mechanics. `Tree.h` does not author a `TreeStorage<T>` class. It also does not own `FolderTreePane::TreeElem`, filesystem enumeration, painting, hit testing, visible-row policy, or other FolderTree feature behavior.

## Proposed Contents

| Entity | Documentation owner | Source disposition |
| --- | --- | --- |
| `TreeNode<T>` | [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) | Complete header declaration; the page's generated `TreeStorage...` filename is a stable historical analysis alias only. |
| `Tree<T>` | [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) | Complete generic `LObject`-derived wrapper over `std::vector<TreeNode<T> >`, including construction/reset, search, insertion, unlink/disable, traversal, node access, and iterator access. |
| `TreeItor<T>` | [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) | Header declaration and generic movement definitions. |
| `TreeItor<T>::MoveToFirstChild` | [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) | Generic header-defined member at emitter position 40. |
| `TreeItor<T>::MoveToNextVisibleSibling` | [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) | Generic header-defined member at emitter position 50 using `TreeNode<T>::disabled`. |
| `TreeItor<T>::MoveToParent` | [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) | Generic header-defined member at emitter position 60. |
| `FolderTreePane::TreeElem` and FolderTree visitors | [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | Explicitly excluded from generic ownership; declarations/visitor specializations stay in `FolderTreePane.h/.cpp`. |

## Dependency And Source Topology

- `Tree.h` includes `LObject.h` because `Tree<T>` derives from complete `LObject`.
- `FolderTreePane.h` includes `../core/ScrollBar.h`, `../../render/EPFTileContext.h`, `../../util/StringBase.h`, and `../../util/Tree.h` before declaring by-value members.
- `FolderTreePane::TreeElem::name` is the four-byte pointer-backed `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`, not the separate 24-byte SSO `SimpleUString` class.
- Generic `Tree<T>` defines the complete reusable construction/reset, search, insertion, unlink/disable, `Traverse<Visitor>`, node-access, and iterator-access surfaces in `Tree.h`. FolderTree-specific visitor/context types and callback policy remain in `FolderTreePane.h/.cpp`; those consumer types do not re-own the generic algorithms.
- `FolderTreePane::PaintTreeNode` is a private static class member; generic Tree specializations receive friendship only to preserve legal access to the pane's private state.

## Evidence

- `Tree<EventHandler *>` records are `0x1c`: five 4-byte links, a 4-byte payload, one disabled byte, and alignment.
- `Tree<FolderTreePane::TreeElem>` records are `0x24`: the same five links, a 12-byte payload, one disabled byte, and alignment.
- `TreeItor<FolderTreePane::TreeElem>` is exactly 12 bytes and its decorated vtable at `0x0061a510` preserves the `TreeItor` spelling.
- UID0002MZ, UID0002N0, and UID0002N1 access only generic node links/state and iterator fields; their source definitions therefore belong in the shared header.
- Current generated FolderTree output is historical lead material and does not prove a FolderTree-only template source file.

## Historical Registration And Migration Record

1. Registration is complete. Scoped validator command `000000018916` created the authoritative UID `0004YK`; the inserted page header and validator-owned `0004YK = by-file/Tree.md` mapping agreed exactly.
2. Generic template routes are migrated: UID0001WP, UID0000FC, UID0000F9, and UID0000FB now use [UID:0004YK][Tree](by-file/Tree.md) as canonical owner/emitter. Concrete FolderTree payload and visitor pages remain routed through UID00005A/UID0000JG.
3. The dependency/formal payloads are applied. `by-project-structure/proposed-source-tree.md` now places `LObject.h`, `StringBase.h`, and `Tree.h` immediately before `LObject.cpp` in `util/`, `EPFTileContext.h` immediately before `EPFTileContext.cpp` in `render/`, and `FolderTreePane.h` immediately before `FolderTreePane.cpp` in `ui/controls/`; it adds no `Tree.cpp`.
4. Post-migration ordinary-document readback found no temporary registration placeholder in the 36 callback destinations and no former UID0000JG owner/emitter route on UID0001WP/0000FC/0000F9/0000FB. Concrete FolderTree references to UID0000JG are intentionally retained.
5. Historical callback record: B003 ran serial scoped validators with generated refresh disabled for the then-new page and changed ordinary pages. This dated record does not describe current validation, generated output, supervisor work, or lifecycle state.

## Generated Audit Chronology

- Historical pre-callback command `000000027320`, refreshed `2026-08-23T23:56:45-04`, emitted a defective Tree header: `Tree.h` was 3,898 bytes with SHA256 `80838595C3DEE3E6B1CB12CB733693FCA701719AAEA318D722190042B6CE2F75`, and `Tree.cpp` was 1,788 bytes with SHA256 `7D1E49785373EB17D9ACBB510A842209DA9E161248E46699BDEFF15C97F0DA02`. That output still authored `TreeStorage<T>`, omitted `TreeFindFunc`, lacked required vector/deque dependencies, ordered `Tree` before `TreeItor`, and left construction, reset, search, insertion, unlink, traversal, and movement incomplete.
- Historical accepted-callback command `000000027382`, refreshed `2026-08-24T01:35:34-04` with `exit_code=0` and `ok=1`, emitted the complete header-only model: `Tree.h` was 6,818 bytes, 219 LF lines, SHA256 `2855EA901A4BC2B402A539056832275856F4605EEC9EDF205BB411709BD825B2`; comment-only `Tree.cpp` was 1,772 bytes, 29 LF lines, SHA256 `4F0BE2E6401E318A43A3102FCC1850913E55DD2F904A628C92598C1887923067`.
- Historical post-callback repair command `000000027513`, refreshed `2026-08-24T04:21:21-04` in the foreground, retained the complete physical shape: `Tree.h` was 6,818 bytes, 219 LF lines, SHA256 `4E0AE279EC961A6698CA3E50F4F703F7D2C0DEEF910FAB14BF7489F22C6A3465`; comment-only `Tree.cpp` was 1,772 bytes, 29 LF lines, SHA256 `7E4C00C3080860EC5905446C8E68B5BF010596DDB98CD2E8DCC3F959D499B0C3`.
- The final Gate 2A repair refresh/readback receipt is recorded in the immutable UID0004YK report. These command records are chronology, not lifecycle or supervisor-completion assertions.

## Historical Assumptions

- Earlier documentation grouped all concrete tree/template code under `FolderTreePane.cpp` and treated the 36-byte node as `FolderTreePane::TreeElem`. That model is superseded by cross-instantiation layout evidence; retain it only as historical reconstruction provenance.
- Before command `000000018916`, the report used a canonical temporary registration token because no UID existed for this page. That pre-registration token is historical workflow evidence only; all current ordinary routes use assigned [UID:0004YK][Tree](by-file/Tree.md).
