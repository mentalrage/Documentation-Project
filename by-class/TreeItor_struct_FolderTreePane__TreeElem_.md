*** UID:0000FB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeItor<T> is a header-only template emitted through Tree.h.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TreeItor_struct_FolderTreePane__TreeElem_

## Current Accepted UID0004YK Header Ownership

TreeItor is the exact spelling preserved by decorated Event and Folder vtables. This complete declaration emits at Tree.h position 20 before Tree, owns the vptr at +0, Tree<T>* at +4, and current index at +8, and retains its inline constructors, empty virtual destructor, accessors, Set, and three movement declarations. The movement definitions emit directly through UID0004YK at positions 40, 50, and 60; this page no longer nests those children.

## Status

- Confidence: very strong for iterator behavior, live method boundaries, vtable identity, traversal field use, cleanup-helper classification, source-facing `TreeItor` spelling, and resolved UID0004YK shared-header ownership.
- Source file: [UID:0004YK][Tree](by-file/Tree.md), emitted through `NexusTK/util/Tree.h`.
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a510`
- Parent attachment: [UID:0004YK][Tree](by-file/Tree.md) owns the generic declaration and movement definitions in `NexusTK/util/Tree.h`. [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) remains the concrete consumer and binary-evidence attachment only.

## Class Purpose

This is the current concrete label for `TreeItor<FolderTreePane::TreeElem>`, an iterator over the embedded folder tree. The iterator stores a tree pointer and current node index, then exposes visible-child/sibling/parent traversal helpers used by [UID:00005A][FolderTreePane](by-class/FolderTreePane.md).

## 2026-07-14 B001 UID0002N0 Implementation Sync

The complete concrete iterator sequence is now explicit: UID00034F declaration-generated destructor support at position `30`, UID0002MZ `MoveToFirstChild` at `40`, UID0002N0 `MoveToNextVisibleSibling` at `50`, and UID0002N1 `MoveToParent` at `60`. The class declaration above remains unchanged and is the source cause for compiler destructor/vtable support; ordinary traversal bodies remain on their exact by-memory children.

UID0002N0 is a 67-byte leaf `thiscall` with one caller at `0x004b23f2` in the best-named `ExpandNode` / `EnsureChildrenLoaded` path. That caller ignores `AL` and consumes only `m_currentIndex`: each sibling candidate is assigned before its `hidden` byte is tested, the first non-hidden candidate returns true, an absent initial sibling returns false without mutation, and an exhausted hidden run returns false with the iterator left on the last hidden candidate.

The final `TreeElem +0x20` source-facing token is `hidden`. Path selection at `0x004b2846`, per-node paint at `0x004b58e6`, and UID0002N0 at `0x004b5bf9` all skip nonzero records; reset/lazy construction writes zero; single-record and range-copy helpers preserve the byte; no nonzero writer or deletion-only reader exists in the bounded family. `isHidden` is the superseded B014 emitted spelling, `visibleTraversalSkip` is descriptive history, and `hiddenOrDeleted` / `deleted` are rejected. UID0004YK resolves physical shared-header ownership to `NexusTK/util/Tree.h`; the Folder instance remains consumer evidence rather than a separate emitter.

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis keeps `TreeItor<FolderTreePane::TreeElem>` as the best source-facing spelling. The generated page name is an alias, not a standalone source-file name. This iterator is local/project-template support under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), used by `FolderTreePane::m_selection` / `m_selectedIterator` at `this+0x170` and by temporary traversal state in expand, key, mouse, paint, and path-selection methods.

Historical B008 state used `isHidden` / visible-traversal skip for `+0x20` before all writers were reconciled. Current source-facing traversal names remain `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent`; the final field spelling and complete semantics are recorded in the 2026-07-14 sync above. Cleanup reset helpers and the scalar deleting destructor remain compiler-generated support and must not be hand-authored as source methods.

## Historical Superseded 2026-06-19 B014 TreeItor Source-Quality Implementation

B014 reanalysis resolves this page as the concrete `TreeItor<FolderTreePane::TreeElem>` specialization and rejects the generated filename spelling as source text. The generated page name remains only a stable UID/lookup alias. The current owner/emitter stays [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) because all ordinary traversal callers and vtable stores are in the `FolderTreePane` control region, while the sibling [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md) only proves likely shared template-header factoring, not ownership transfer.

### Concrete Layout

| Offset | Source-facing name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | vptr | compiler vtable pointer | Constructor/setup/destructor stores write `0x0061a510`; the scalar deleting destructor frees a `0x0c`-byte object when the delete flag is set. |
| `+0x04` | `m_tree` | `Tree<FolderTreePane::TreeElem> *` | Traversal helpers load `this+0x04` and then read the tree storage/vector at tree offset `+0x04`. |
| `+0x08` | `m_currentIndex` | `int` | `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` all read/update this value as the current node index. |

The iterator does not own `FolderTreePane::TreeElem`; it reads link and visibility fields through the direct `std::vector<TreeNode<FolderTreePane::TreeElem> >` member of `Tree<FolderTreePane::TreeElem>`. EventDispatcher's sibling iterator layout uses the same vptr/tree/current-index shape and corroborates the resolved shared `TreeItor<T>` owner in UID0004YK `Tree.h`.

### Source-Facing Method Names

| Method | Binary evidence | Source-quality decision |
| --- | --- | --- |
| `bool MoveToFirstChild()` | `0x004b5bb0-0x004b5bd0`; direct call at `0x004b2cbe`; reads `TreeElem::firstChildIndex` at `+0x04`. | Name/signature accepted. This mutates `m_currentIndex`, so `GetFirstChild` is rejected. |
| `bool MoveToNextVisibleSibling()` | `0x004b5bd0-0x004b5c13`; direct call at `0x004b23f2`; follows `TreeElem::nextSiblingIndex` at `+0x10` and skips records whose `+0x20` byte is set. | Name/signature accepted. Plain `MoveToNextSibling` is incomplete because visible traversal skip logic is explicit. |
| `bool MoveToParent()` | `0x004b5c20-0x004b5c3f`; direct call at `0x004b2c92`; reads `TreeElem::parentIndex` at `+0x00`. | Name/signature accepted. This mutates the iterator and returns false on `-1`. |

Current field decision: `TreeElem +0x20` is `hidden`, nonzero for exclusion from visible sibling/path/connector traversal. The former `isHidden` spelling is historical, `visibleTraversalSkip` is descriptive only, and `hiddenOrDeleted` / `deleted` are rejected after the complete writer audit.

### Cleanup, Vtable, And No-Code Policy

[UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) and [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) are source-declared/generated-binary destructor support. Equivalent code should come from the virtual destructor declaration above and compiler delete glue, not from handwritten vtable-store C++.

B001's 2026-06-28 empty-emitter implementation makes [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) explicitly non-emitting metadata: blank `EMITTER_UIDS:`, blank formal C++, and no comment marker. Its source representation is the existing `virtual ~TreeItor()` declaration on this page.

B007's 2026-06-28 UID00034F empty-emitter repair keeps that policy intact while giving the routed by-memory child a formal covered-by marker. [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) remains source-declared/generated-binary destructor support under this class: live MCP session `supervisor_20260628_resume` reconfirmed the `0x7`-byte body as one store of `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@` to `[ecx]` plus `ret`, with no callees, no strings, no ordinary source callers, 17 EH cleanup/lifetime xrefs, and 31 vtable references to `0x0061a510`. Its formal marker points back here because the source-bearing construct is still this page's `virtual ~TreeItor()` declaration. Do not add a separate child destructor body or vtable-store source for UID00034F.

[UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md) and [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md) remain compiler/EH cleanup helpers with no source-authored behavior. They should stay non-emitting unless later source evidence proves ordinary behavior.

The one-slot vtable at `0x0061a510` is generated by this declaration. Do not hand-port [UID:00036L][FolderTreePaneTreeItorVtable](by-type/by-vtable/FolderTreePaneTreeItorVtable.md) or [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md) as raw arrays.

### Resolved Header Ownership And Rejected Names

The resolved source owner is [UID:0004YK][Tree](by-file/Tree.md): project-local `TreeItor<T>` is declared and its generic movement methods are defined in `NexusTK/util/Tree.h`. FolderTreePane and EventDispatcher are concrete consumers/instantiation evidence, not competing source owners. No generic TreeItor body belongs in either consumer CPP.

Rejected source-facing names include `TreeIterator<FolderTreePane::TreeElem>` (contradicted by the RTTI/vtable symbol), `TreeItor_struct_FolderTreePane__TreeElem_` (documentation filename syntax), `cls_0x4b5bb0`, `meth_0x4b5bb0`, `sub_4B5BB0`, `sub_4B5BD0`, `sub_4B5C20`, and the stale `MemMapBase::scalar deleting destructor` label for `0x004b5a40`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| destructor | `0x004b5670-0x004b5677` | Position `30`; declaration-generated iterator-vtable reset covered by `virtual ~TreeItor()`. |
| cleanup vtable reset helper | [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md) | Compiler-generated cleanup helper that stores the `TreeItor` vtable at `this+0x0c`; not source-authored behavior. |
| dual cleanup vtable reset helper | [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md) | Compiler-generated cleanup helper that stores the `TreeItor` vtable at `this+0x0c` and `this+0x00`; not source-authored behavior. |
| scalar-deleting destructor | `0x004b5a40-0x004b5a64` | Resets vtable and conditionally deletes. |
| `MoveToFirstChild` | `0x004b5bb0-0x004b5bd0` | Position `40`; reads the current node's child index at record offset `+0x04` and moves when it is not `-1`. |
| `MoveToNextVisibleSibling` | `0x004b5bd0-0x004b5c13` | Position `50`; follows sibling indexes at `+0x10`, assigns each candidate before testing `hidden` at `+0x20`, and returns only for a non-hidden sibling. |
| `MoveToParent` | `0x004b5c20-0x004b5c3f` | Position `60`; reads the current node's parent index at record offset `+0x00` and moves when it is not `-1`. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact function ranges for the iterator vtable-reset destructor, scalar deleting destructor, and three traversal helpers: `0x004b5670-0x004b5677`, `0x004b5a40-0x004b5a64`, `0x004b5bb0-0x004b5bd0`, `0x004b5bd0-0x004b5c13`, and `0x004b5c20-0x004b5c3f`.
- IDA names the vtable at `0x0061a510` as `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`; slot `+0x00` points to `0x004b5a40`, and IDA reports 31 data xrefs to this vtable from `FolderTreePane` constructor, traversal, cleanup, and helper paths.
- Live xrefs show `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` each have a direct caller in `FolderTreePane` code (`0x004b2cbe`, `0x004b23f2`, and `0x004b2c92` respectively).
- Live decompilation ties traversal to the 36-byte [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) record layout: parent index `+0x00`, first child `+0x04`, next sibling `+0x10`, and final `hidden` byte `+0x20`. Three semantic readers skip nonzero records; zero initialization and copy preservation complete the field model.
- 2026-06-08 A009 Batch117 rechecked the tiny iterator cleanup helpers: [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md) stores the `TreeItor` vtable at `this+0x0c` and [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md) stores the same vtable at `this+0x0c` and `this+0x00`. Both have no ordinary direct callers and are reached through EH cleanup jumps, so they support the iterator class/vtable model but remain non-source cleanup helpers.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The complete header declaration/layout, concrete RTTI/vtable identity, compiler-support policy, exact generic traversal methods, `disabled` semantics, caller state contract, and explicit `30/40/50/60` source order are implemented. |
| Confidence | 94 | Binary layout, callers, vtable references, state readers, cross-specialization evidence, and the registered shared-header route agree; original private/member spelling remains inferred. |
| Assignment | [UID:0004YK][Tree](by-file/Tree.md) | Generic declaration and movement definitions emit once through `Tree.h`; FolderTreePane remains the concrete payload/policy consumer. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:00031C][0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper](by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md)
- [UID:00031D][0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper](by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md)

## 2026-07-29 UID0002MZ Generic Iterator Reconciliation

- The decorated vtable at `0x0061a510` proves the source spelling `TreeItor`. The class remains exactly 12 bytes: compiler-managed vptr, `Tree<T> *m_tree`, and `int m_currentIndex`.
- Formal H owns the human declaration and child route; compiler-managed vptr state is not written as a source member. Formal CPP is blank.
- `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` are generic H definitions at emitter positions 40/50/60. They use `Tree<T>::NodeAt`, generic link members, and the generic `disabled` state.
- Existing constructor/destructor/vtable/scalar-delete evidence remains valid. The former FolderTree-local CPP declaration and `TreeElem.hidden` wording are retained as historical assumptions superseded by shared-template and EventDispatcher evidence.
- Supervisor Gate 2B catalog entry `0365` preserves the exact 12-byte `TreeItorFolderTreePaneTreeElem` analysis UDT and applies the accepted A01/A02 names, exact `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)` types, and regular function comments. A03 retains its accepted name/type with the generic `TreeNode<T>::disabled` comment; A04 remains protected and unchanged.
- Current decompilation under saved IDB `412DA7E8...519CD` renders `m_storage.m_begin`, `firstChildIndex`, `parentIndex`, `nextSiblingIndex`, and `disabled`. Function bytes, one-xref sets, frames, bounds, and nonselected comment channels are unchanged. IDA's explicit alignment syntax belongs only to U02/U03 analysis declarations and does not alter the natural human-source formal H above.

## Changes

### 2026-08-24 UID0004YK Gate 2A Iterator-Owner Correction

- Current generic `TreeItor<T>` declaration, layout, destructor source cause, and movement definitions belong to UID0004YK `Tree.h`. This page documents the concrete Folder payload instance and exact binary evidence; `FolderTreePane.cpp` retains consumer policy only, and shared-header ownership is resolved rather than deferred.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below retain exact iterator behavior and layout evidence. Their former FolderTreePane-local generic route and unresolved shared-header conclusions are explicitly superseded by the current UID0004YK owner above.

- 2026-07-14 B001 UID0002N0 source-quality support sync:
  - Changed score `88/90` to `90/93`; preserved owner/emitter UID0000JG, reconstructable true, and the complete declaration block.
  - Added exact `30/40/50/60` destructor/traversal ordering, UID0002N0's sole-caller ignored-return contract and candidate state transitions, and the complete `+0x20` reader/writer disposition.
  - Finalized the source-facing field as `hidden`; historicalized `isHidden` and descriptive `visibleTraversalSkip`, rejected `hiddenOrDeleted` / `deleted`, and retained shared physical-header uncertainty without changing the concrete source route.

- 2026-06-28 B001 [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) empty-emitter support sync:
  - Score unchanged at `88/90`.
  - Added the accepted scalar deleting destructor disposition: [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) is non-emitting blank-emitter metadata covered by this page's iterator virtual destructor declaration, not a standalone C++ emitter or comment marker.

- 2026-06-28 B007 UID00034F support sync:
  - Score/metadata unchanged at `88/90`, owner/emitter [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
  - Added the UID00034F empty-emitter repair note: [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) now carries a formal covered-by marker to this class, while this page's `virtual ~TreeItor()` declaration remains the source-bearing construct. The child must not emit a separate vtable-store or handwritten destructor body.

- 2026-06-19 B014 TreeItor source-quality implementation:
  - Before: `85/86`, blank formal C++, with B008 template evidence but unresolved source-facing class declaration and method-body readiness.
  - After: `88/90`, owner/emitter unchanged at [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), `RECONSTRUCTABLE:TRUE`, and class-level first-draft C++ added.
  - Summary/evidence: B014 resolved the `TreeItor<FolderTreePane::TreeElem>` spelling, `m_tree`/`m_currentIndex` layout, bool traversal signatures, `TreeElem +0x20` as inferred `isHidden`/visible-traversal skip flag, source-declared/generated-binary destructor/vtable policy, EventDispatcher sibling-template/header caveat, and generated-name rejection. Remaining caps are shared template-header ownership and final `+0x20` field spelling.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the concrete iterator traversal methods, FolderTreePane ownership, tree-element/vtable/template links, and remaining uncertainty around original template spelling/source artifact.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed exact iterator method boundaries, the named `TreeItor<FolderTreePane::TreeElem>` vtable at `0x0061a510`, vtable slot/data xrefs, direct FolderTreePane traversal callers, and traversal field accesses matching the documented 36-byte tree element layout.
  - Remaining limits: scores stay below final-source level because exact original template spelling/header factoring and final public method names remain inferred.
- 2026-06-08 A009 Batch117 parent-gate refresh:
  - What existed before: score `82/84`, with stale direct-parent gate evidence and no exact child pages for the two tiny iterator cleanup helpers summarized by the aggregate.
  - Changed to: score `85/86`, retained `AUTOGEN_PARENT_UID:0000JG`, linked the exact cleanup helper pages, and added an explicit score/assignment rationale.
  - Summary/evidence: current documentation plus Batch117 IDA rechecks confirm the iterator vtable at `0x0061a510`, traversal method ranges/callers, tiny cleanup helper bodies at `0x004b57f0-0x004b57f8` and `0x004b5800-0x004b580e`, direct `FolderTreePane.cpp` file parent `89/85`, and template-context page `85/89`.
