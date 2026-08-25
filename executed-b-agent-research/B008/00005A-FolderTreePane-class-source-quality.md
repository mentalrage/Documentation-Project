** TARGET-REPORT-UID:00005A **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00005A FolderTreePane Class Source-Quality Research

## Target And Scope

- Target UID: `00005A`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\FolderTreePane.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\00005A-FolderTreePane-class-source-quality.md`
- Assignment type: report-only first pass.
- File discipline: no by-* documentation files were edited, and `by-memory/-coverage-report.md` was not edited.

This report reanalyzes [UID:00005A] `FolderTreePane` at class/source-quality level. It focuses on final source split, field/type names, nested `TreeElem` and tree template/support classes, missing `SetSelection` body, helper ownership, owner-pollution exclusions, vtable/base layout, destructor/thunk shape, generated-source omissions, score recommendation, and first-draft C++ readiness.

## Executive Recommendation

Recommended target metadata after an accepted implementation callback:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `88` | The main class/source split, class layout, vtable ownership, core method inventory, nested tree record model, template-helper placement, generated-source pollution exclusions, and `SetSelection` source shape are now revalidated and can be documented at report-level detail. |
| `CONFIDENCE` | `86` | `89` | Existing live IDA-backed docs, exact vtable/data children, generated-source checks, and support-page evidence converge on one source owner and class layout. Confidence remains below final-audit range because exact original field names, tree template header factoring, and several private helper names remain inferred rather than symbol-recovered. |
| `CANONICAL_OWNER` | `0000JG` | `0000JG` | The direct source owner remains [UID:0000JG] `FolderTreePane.cpp`. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | The class is NexusTK source-authored UI control code. |
| `EMITTER_UIDS` | `0000JG` | `0000JG` | Generated output should continue through `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`. |

Source placement recommendation:

- Keep [UID:00005A] under [UID:0000JG] `FolderTreePane.cpp`.
- Keep the projected source path `NexusTK/ui/controls/` on [UID:0000JG].
- Treat `FolderTreePane` as a reusable UI control split from [UID:0000JF] `FolderSelectDialog.cpp`, even though current constructor reachability only proves construction from `FolderSelectDialog` at `0x004b178b`. The class owns enough vtables, local tree/template machinery, filesystem expansion, paint/input handling, and path construction to justify the standalone control-source split. Do not merge it into `FolderSelectDialog.cpp` unless later source evidence proves the original tree control was private to the dialog.

First-draft C++ recommendation:

- Emit a conservative class declaration shell for [UID:00005A], with `[[CHILDREN]]`, after implementation synchronizes the target/support docs.
- Do not emit large method bodies on the class page.
- Do emit or prepare first-draft method C++ on exact source-authored method/support pages where the behavior is complete enough, especially [UID:000156] `FolderTreePaneSetSelection`.
- Do not emit standalone C++ bodies for compiler-generated vtable bytes, adjustor thunks, constructor EH cleanup fragments, or MSVC/Dinkumware-style directory-entry sort internals; represent those through class declarations, local container declarations, and high-level sort/source expressions.

## Evidence Checked

Documentation and generated-source evidence checked in this pass:

- [UID:00005A] `by-class/FolderTreePane.md`.
- [UID:0000JG] `by-file/FolderTreePane.md`.
- [UID:000155] `0x004b1b90-0x004b32c9.FolderTreePaneCore.md`.
- [UID:000156] `0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md`.
- [UID:000157] `0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`.
- [UID:00022E] `0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md`.
- [UID:0001UJ] `FolderTreePane__TreeElem.md`.
- [UID:0001WP] `FolderTreePaneTreeTemplates.md`.
- [UID:0001XL] `FolderTreePaneVtables.md`.
- [UID:00036N] `FolderTreePaneClassVtables.md`.
- [UID:00036O] `0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`.
- [UID:0000F9], [UID:0000FB], and [UID:0000FC] generated tree/template class pages.
- [UID:000158] `0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`.
- [UID:000159] `0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md`.
- [UID:00034K] `0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`.
- Traversal and paint helper pages [UID:000344], [UID:000345], [UID:000346], [UID:000347], and [UID:00034H].
- Directory-entry sort report `Agent-B008/research/00034B-FolderTreeDirectoryEntrySortCore-source-quality.md`.
- [UID:0003BH] `0x0061a5e0-0x0061a5ec.FolderTreePathFragmentStrings.md`.
- [UID:0000UO] `FolderTreePaneOwnerPollution_47f280_58a8e0.md`.
- [UID:0000VD] `ScopedMarkerMissingMethodBodies.md`.
- [UID:000154], [UID:0000JF], and [UID:000059] `FolderSelectDialog` support pages.
- Active autogen output `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- Legacy generated files:
  - `source-3/simroot_v2/class_FolderTreePane.cpp`
  - `source-3/simroot_v2/class_TreeStorage_struct_FolderTreePane__TreeElem_.cpp`
  - `source-3/simroot_v2/class_TreeItor_struct_FolderTreePane__TreeElem_.cpp`
- `by-structure.md`, `by-project-structure/proposed-source-tree.md`, `inference_research.md`, `Supervisor.md`, and `Agent-B008/goal.md`.

Scoped validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [00005A-FolderTreePane-class-source-quality-removed.md](00005A-FolderTreePane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit code `0`, `ok: 1`. This was a dry run (`apply: False`), so it did not edit by-* docs or generated reports.

## Current Target State

[UID:00005A] currently documents `FolderTreePane` as a `ScrollablePane`-derived filesystem tree control at `85/86`, with owner/emitter [UID:0000JG]. Its current formal C++ block is blank.

The class page already records the correct broad shape:

- Core range [UID:000155] `0x004b1b90-0x004b32c9`.
- `SetSelection` exact child [UID:000156] `0x004b3210-0x004b32c9`.
- Tree/sort helper aggregate [UID:000157] `0x004b3350-0x004b5c3f`.
- Vector/string support [UID:00022E] `0x004b5c40-0x004b5efc`.
- Nested [UID:0001UJ] `FolderTreePane::TreeElem`, size `0x24`.
- Vtable/base views in [UID:0001XL], exact class vtables in [UID:00036N], exact data in [UID:00036O].
- Class size `0x17c`.
- Embedded `Tree<FolderTreePane::TreeElem>` at `this+0x130`.
- Selected iterator at `this+0x170`.

The remaining class-level source-quality blockers are narrower than the current wording suggests:

- The final source file split is now strong enough to prefer `ui/controls/FolderTreePane.cpp`.
- The generated-source pollution is no longer an open source-placement question; it is a known excluded artifact.
- Field names remain inferred, but the highest-probability source-facing names can now be stated rather than left as generic offsets.
- `SetSelection` is not missing from the binary; it is missing/poor in generated output. Its body is source-authored and reconstructable on [UID:000156].
- The directory-entry sort helpers are not handwritten public methods; they are source-declared/generated-binary template support caused by sorting a local directory-entry vector.

## Source Split, Ownership, And Reachability

### Recommended Source File

Best source placement remains:

- Source: `NexusTK/ui/controls/FolderTreePane.cpp`
- Header: `NexusTK/ui/controls/FolderTreePane.h`
- Source owner page: [UID:0000JG] `by-file/FolderTreePane.md`

Evidence for this placement:

- [UID:0000JG] already has valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`.
- The class is a standalone scrollable control with primary, secondary, and tertiary vtable views.
- It has a local tree record type, local tree/storage/iterator template instantiations, filesystem traversal, lazy expansion, name sorting, drawing, keyboard navigation, mouse hit-testing, selected-path construction, and destructor/base cleanup.
- The constructor is called from [UID:000154] `FolderSelectDialog` at `0x004b178b`, and the selected-path helper is called from `FolderSelectDialog::OnCommand` at `0x004b197f`.
- [UID:0000JF] `FolderSelectDialog.cpp` remains the modal dialog owner: it owns drive-list population, dialog controls, callback dispatch, `asc_66DA88`, and the OK/cancel policy. It consumes `FolderTreePane`; it does not semantically own the tree-control internals.
- The generated `class_FolderTreePane.cpp` contains unrelated chat/help/surface output. This is explicit owner pollution, not evidence for source co-location.

Negative evidence and caveat:

- Only one constructor caller is currently confirmed, from `FolderSelectDialog` at `0x004b178b`.
- Current [UID:0000JF] still notes a medium caveat that `FolderTreePane` might have been compiled in a neighboring control `.cpp` or privately beside the dialog.
- The stronger current inference is to keep `FolderTreePane.cpp` as a reusable control file because of the class's independent vtables, local tree support, generated by-file path, and source-tree placement. Confidence should stay below final-audit until original project source or wider constructor callers are found.

### Caller And Dispatch Evidence

External and virtual reachability is as follows:

| Function or behavior | Evidence |
| --- | --- |
| Constructor `0x004b1b90` | Single direct caller at `0x004b178b` inside `FolderSelectDialog` construction. |
| Selected-path helper `0x004b3090` | Called at `0x004b197f` inside `FolderSelectDialog::OnCommand` to build the confirmed selected folder path from `tree+0x170`. |
| `SetSelection` `0x004b3210` | Three normal direct callers: `0x004b296a` in `SelectNodeByPath`, `0x004b2d70` in `OnKeyEvent`, and `0x004b2f2f` in `OnMouseEvent`. |
| Paint/input virtuals | Primary vtable slots at `0x0061a518 + 0x60`, `+0x64`, and `+0x6c` route mouse, key, and paint behavior. |
| Content/scroll virtuals | Primary vtable slots `+0x48` through `+0x5c` route content extent, viewport, dimensions, and scroll-delta helpers. |
| Directory-entry sort | Sort driver [UID:00034D] is called from lazy expansion at `0x004b214e`; the partition target [UID:00034B] has sole direct caller `0x004b52e0` inside that sort driver. |

## Class Layout And Vtable Model

### Base And Size

Best-supported class model:

- `FolderTreePane` derives from `ScrollablePane`.
- Class size is `0x17c` / 380 bytes.
- Primary base/view starts at `this+0x00`.
- Secondary vtable view starts at `this+0xa0`.
- Tertiary vtable view starts at `this+0xa4`.
- The embedded tree starts at `this+0x130`.
- The selected iterator starts at `this+0x170`.

The vtable evidence is exact:

- `0x0061a514` RTTI locator for primary `FolderTreePane`; `0x0061a518` primary vtable base.
- `0x0061a588` RTTI locator for secondary view; `0x0061a58c` secondary vtable base.
- `0x0061a5b8` RTTI locator for tertiary view; `0x0061a5bc` tertiary vtable base.
- `0x0061a5c0` is the inherited event/update slot in the tertiary view.
- `0x0061a5c4` begins UTF-16 `TREEICON.EPF` and is not vtable data.

Primary `FolderTreePane` slots that should drive the class declaration:

| Slot | Target | Best source-facing role |
| --- | --- | --- |
| `+0x00` | `0x004b5a70` | scalar deleting destructor generated from `~FolderTreePane`. |
| `+0x30` | `0x0055ee10` | inherited `ScrollablePane` virtual. |
| `+0x38` | `0x0055ef10` | inherited `ScrollablePane` virtual. |
| `+0x44` | `0x0055f190` | inherited `ScrollablePane` virtual. |
| `+0x48` | `0x004b2a80` | content extent helper. |
| `+0x4c` | `0x004b2ab0` | visible extent helper. |
| `+0x50` | `0x004b2af0` | viewport size helper. |
| `+0x54` | `0x004b2b20` | scroll value transform helper. |
| `+0x58` | `0x004b2b30` | content dimensions helper/copy. |
| `+0x5c` | `0x004b2b50` | scroll delta computation. |
| `+0x60` | `0x004b2dc0` | mouse event handler. |
| `+0x64` | `0x004b2b80` | key event handler. |
| `+0x68` | `0x0041d6b0` | inherited/default callback slot. |
| `+0x6c` | `0x004b2a00` | paint visible tree rows. |

### Destructor And Thunks

Best source-facing destructor model:

- `FolderTreePane::~FolderTreePane()` is source-declared.
- `0x004b5a70-0x004b5af4` is the compiler scalar-deleting destructor support for that source destructor.
- It restores the three `FolderTreePane` vtable views, resets embedded iterator/tree vtables at `this+0x170` and `this+0x130`, destroys `TreeStorage<FolderTreePane::TreeElem>`, tears down the `Tree`/`LObject` view, calls outer pane/base cleanup, and conditionally frees `this`.
- `0x004b59d5-0x004b59eb` is compiler-generated destructor adjustor thunk glue. It should stay non-reconstructable and should not be emitted as source.
- `0x004b5650-0x004b5668` is constructor EH cleanup for the embedded `Tree<FolderTreePane::TreeElem>` at `this+0x130`. It is destructor-shaped but not a normal standalone source method. It should be represented by member cleanup and tree/template declarations, not by a handwritten function body.

## Best-Supported Names And Types

### Class Fields

The following names should be used in target/support docs as source-facing descriptive names. Original symbol proof is unavailable, so documents should explicitly say these are best-supported/inferred names.

| Offset | Best name | Type | Evidence and caveat |
| --- | --- | --- | --- |
| `this+0x130` | `m_tree` | `Tree<FolderTreePane::TreeElem>` | Constructor, reset, cleanup, scalar destructor, iterator helpers, and `Tree` vtable evidence all converge. |
| `this+0x148` approx. | `m_folderIconContext` or `m_treeIconContext` | EPF/tile frame context | Constructor/root setup references `TREEICON.EPF`; paint helper draws folder/tree graphics from this context. Exact class of the resource context is inferred; do not name it as a generic pointer. |
| `this+0x170` | `m_selection` / `m_selectedIterator` | `TreeItor<FolderTreePane::TreeElem>` | `SetSelection`, selected-path helper, key/mouse selection, and `FolderSelectDialog` selected-path call all use this iterator. Prefer `m_selection` for source-style brevity and mention `m_selectedIterator` as a descriptive alias. |
| `this+0x114`, `this+0x11c` | inherited viewport vertical bounds | inherited `ScrollablePane` fields | Used by `SetSelection` to compute visible bottom. Do not promote these as `FolderTreePane` fields unless `ScrollablePane` docs establish member names. |

Rejected field alternatives:

- `m_treeIterator` for `this+0x170`: generated source uses this early, but its behavior is persistent selection, not a generic iterator.
- `m_selectedNodeIndex` for `this+0x170`: rejected because the object stores iterator payload fields, not just an index.
- A raw `void*` folder icon member: rejected because constructor and paint flow consistently treat it as a loaded EPF/tile context around `TREEICON.EPF`.

### Nested `TreeElem` Record

Best-supported `TreeElem` model:

```cpp
struct FolderTreePane::TreeElem {
    int parentIndex;          // +0x00
    int firstChildIndex;      // +0x04
    int lastChildIndex;       // +0x08
    int previousSiblingIndex; // +0x0c, best inference
    int nextSiblingIndex;     // +0x10
    SimpleUString name;       // +0x14
    short rowIndex;           // +0x18
    short depth;              // +0x1a
    unsigned char childrenLoaded; // +0x1c
    unsigned char expanded;       // +0x1d
    unsigned char reserved1[2];   // +0x1e
    unsigned char hidden;         // +0x20, skip-visible-traversal flag
    unsigned char reserved2[3];   // +0x21
};
```

Evidence:

- Size is `0x24` / 36 bytes.
- `TreeStorage` insert/destructor helpers use 36-byte stride and destroy `SimpleUString` at `+0x14`.
- Reset initializes the first five dwords to `-1`.
- `MoveToParent` reads `+0x00`.
- `MoveToFirstChild` reads `+0x04`.
- Batch 127 expansion evidence shows first child writes parent `+0x04` and `+0x08`, later appends update previous node `+0x10` and parent `+0x08`; this supports `lastChildIndex` at `+0x08` and `nextSiblingIndex` at `+0x10`.
- `+0x0c` is copied by storage helpers and is most likely `previousSiblingIndex`, but direct traversal evidence is weaker than for `+0x08` and `+0x10`.
- `GetNodeBounds` uses word `+0x18` for Y row and word `+0x1a` for indentation/depth.
- Lazy expansion checks/sets byte `+0x1c`; best source name is `childrenLoaded` or `childrenEnumerated`.
- `CollapseNode` clears byte `+0x1d`; expansion and key/mouse logic read/set it; best source name is `expanded`.
- `MoveToNextVisibleSibling` skips byte `+0x20`; best source name is `hidden` or `skipVisibleTraversal`. `hiddenOrDeleted` remains a cautious doc alias, but `deleted` is not directly proven.

### Tree Template / Iterator / Storage Names

Recommended source-facing template names:

- `template<class T> class TreeStorage;`
- `template<class T> class Tree;`
- `template<class T> class TreeItor;`
- Concrete specializations:
  - `TreeStorage<FolderTreePane::TreeElem>`
  - `Tree<FolderTreePane::TreeElem>`
  - `TreeItor<FolderTreePane::TreeElem>`

`TreeItor` is the strongest spelling lead because generated class names, vtable names, and existing docs consistently use `TreeItor`, not `TreeIterator`.

Placement:

- Keep these as project-local template/support declarations attached to `FolderTreePane.cpp`/`FolderTreePane.h`.
- Do not create standalone source files from generated class names `Tree_struct_FolderTreePane__TreeElem_`, `TreeStorage_struct_FolderTreePane__TreeElem_`, or `TreeItor_struct_FolderTreePane__TreeElem_`.

Remaining caveat:

- It is still unproved whether the original project had a reusable tree template header shared beyond `FolderTreePane`. The current concrete evidence only proves this instantiation. Keep score below final-audit until other `Tree<T>` users or source symbols are found.

### Directory Entry Scratch Record

Adopt the source shape from the accepted [UID:00034B] report:

- Best local type name: `FolderTreePane::DirectoryEntry` or file-local `DirectoryEntry`.
- Documentation alias: `FolderTreeDirectoryEntry`.
- Size: `0x0c` / 12 bytes.
- Fields:
  - `+0x00`: `name`, a `SimpleUString`-style string handle.
  - `+0x04`: `row` or `rowIndex`, copied into `TreeElem+0x18`.
  - `+0x06`: `depth` / `depthOrIndent`, copied into `TreeElem+0x1a`.
  - `+0x08`: `childrenLoaded` default byte, copied into `TreeElem+0x1c`.
  - `+0x09`: `expanded` default byte, copied into `TreeElem+0x1d`.

The directory-entry sort helpers are compiler/generated-binary support from a high-level sort expression over these local records. They should be documented as support for `FolderTreePane::ExpandNode` / current `FindFirstVisibleChild`, not as user-facing class methods.

## Core Method Names And Source Shape

The current docs and generated source already use many stable names. The following source-facing recommendations should be applied or recorded as aliases:

| Address | Current doc/generated name | Recommended source-facing name | Confidence |
| --- | --- | --- | --- |
| `0x004b1b90` | `FolderTreePane::FolderTreePane` | `FolderTreePane::FolderTreePane(const wchar_t* rootName)` | High for constructor and root-name pointer; exact parameter type could be project string wrapper but `const wchar_t*` is the best current signature. |
| `0x004b1d50` | `FindFirstVisibleChild` | `ExpandNode(TreeItor<TreeElem>* node)` or `EnsureChildrenLoaded(TreeItor<TreeElem>* node)` | Behavior is lazy filesystem child enumeration plus expansion. Current name is a useful search alias but not the best source-facing description. |
| `0x004b2540` | `CollapseNode` | `CollapseNode(TreeItor<TreeElem>* node)` | Strong. |
| `0x004b2580` | `RefreshTreeLayout` | `RefreshTreeLayout()` | Strong descriptive name. |
| `0x004b25e0` | `SetRootNodeName` | `SetRootNodeName(const wchar_t* rootName)` or `SetRootName` | Strong behavior, exact original spelling not proved. |
| `0x004b2680` | traversal helper | `FindVisibleNode` / `FindVisibleNodeByBounds` support helper | Medium. It routes through hit-test traversal; keep helper/private. |
| `0x004b2730` | `SelectNodeByPath` | `SelectNodeByPath(const wchar_t* path)` | Strong. |
| `0x004b2a00` | `PaintTree` | `OnPaint` / `PaintTree` | Strong for paint behavior; exact virtual slot name depends on base `ScrollablePane` naming. |
| `0x004b2b80` | `OnKeyEvent` | `OnKeyEvent(KeyEvent*)` | Strong role, exact event type name inferred. |
| `0x004b2dc0` | `OnMouseEvent` | `OnMouseEvent(MouseEvent*)` | Strong role, exact event type name inferred. |
| `0x004b2f60` | `CalculateContentDimensions` | `CalculateContentDimensions()` | Strong. |
| `0x004b3010` | `GetNodeBounds` | `GetNodeBounds(TreeItor<TreeElem>*, Rect*)` | Strong role, exact rect type name inferred. |
| `0x004b3090` | selected-path helper | `BuildSelectedPath` / `GetSelectedPath` | Strong behavior; should be a method/helper that walks parent links from `m_selection`. |
| `0x004b3210` | `SetSelection` | `SetSelection(TreeItor<TreeElem>* selection)` | Strong behavior. Best return type is `void`; decompiler's `int` return from final invalidate is not known to be observed. |

The implementation can keep old page/file names where a rename would be too disruptive, but the prose should state the best source-facing names and explicitly mark old names as generated/search aliases where needed.

## Helper Ownership And Source Placement

### FolderTreePane-owned source helpers

These should remain under [UID:0000JG] `FolderTreePane.cpp` as private/local helpers or compiler-emitted support for the class:

- [UID:000343] `FolderTreeDirectoryEntryNameLess`: local comparator/name-less predicate.
- [UID:000344] `FolderTreeContentDimensionsTraversal`: file-local traversal helper called only from `CalculateContentDimensions`.
- [UID:000345] `FolderTreePaintTraversalCallback`: file-local visible-tree paint traversal helper called only from `PaintTree`.
- [UID:000346] `FolderTreeHitTestTraversal`: file-local hit-test traversal helper called from `0x004b2680` and `OnMouseEvent`.
- [UID:000347] `FolderTreeVisibleNavigationSearch`: file-local keyboard navigation helper called only from `OnKeyEvent`.
- [UID:000348] directory-entry vector insert: local vector support for 12-byte `DirectoryEntry`.
- [UID:000349] insertion sort cutoff helper.
- [UID:00034A] median/order-three helper; old `CompareSwap3` is behaviorally correct but less source-facing.
- [UID:00034B] unguarded partition; do not emit standalone function body.
- [UID:00034C] heap adjust/sift-down fallback; current `SortPartition` is stale per the B008 `00034B` report.
- [UID:00034D] introsort/sort-loop driver called from lazy expansion.
- [UID:00034E] directory-entry record swap helper.
- [UID:00034H] per-node paint helper called only by paint traversal.
- [UID:00022E] vector/string support helpers, emitted by local container/template mechanics.
- [UID:0003BH] folder-tree path fragment strings `\`, `*.*`, and slash/backslash material.

### Template/class support pages

These should stay source-owned by [UID:0000JG] but should not become standalone project files:

- [UID:0000F9] `Tree_struct_FolderTreePane__TreeElem_`: concrete `Tree<FolderTreePane::TreeElem>` wrapper support.
- [UID:0000FB] `TreeItor_struct_FolderTreePane__TreeElem_`: concrete iterator support.
- [UID:0000FC] `TreeStorage_struct_FolderTreePane__TreeElem_`: concrete storage support.
- [UID:0001WP] `FolderTreePaneTreeTemplates`: source-template context page.

### Class-owned source-declared/generated-binary children

These should stay owned by [UID:00005A]:

- [UID:0001UJ] `FolderTreePane::TreeElem`.
- [UID:00036N] `FolderTreePaneClassVtables`.
- [UID:00036O] `FolderTreePaneVtableData`.
- [UID:00034K] `FolderTreePaneScalarDeletingDestructor`.

### Non-emitting/compiler glue

These should not emit source C++:

- [UID:000159] adjustor thunks: compiler-generated `this` adjustment to `0x004b5a70`.
- Exact vtable data bytes: regenerated from declarations, not hand-written.
- Constructor EH cleanup fragment [UID:000158] as a standalone function: source declarations/member cleanup generate equivalent bytes; do not hand-port it.
- Sort internals such as [UID:00034B]: source should express a high-level sort over `DirectoryEntry` records.

## Generated-Source State And Omissions

The current validator-generated `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` contains only empty emitter markers for the class and routed children. That is expected for the current by-* state and confirms that first-draft C++ has not yet been supplied.

The legacy `source-3/simroot_v2/class_FolderTreePane.cpp` is useful only as a lead:

- It contains heavy owner pollution from chat, help/system-message, surface/presentation, screenshot/proof, and other unrelated systems.
- It uses the class name `FolderTreePane` for methods that have since been routed to other owners.
- It does include a decompiler-shaped `SetSelection` body at `0x004b3210`, but it is emitted as `int __thiscall sub_4B3210(int this, int a2)` with generated locals.
- Its `SetSelection` body confirms the high-level behavior recorded in [UID:000156]: copy selected iterator fields, call `GetNodeBounds`, read/update scroll, clamp to max, and invalidate/update through vtable slot `+0x20`.
- Its generated `TreeStorageFolderTreeElemRecord` has a `static_assert(sizeof(...) == 36)` but leaves fields as `field_00` etc. and disagrees with stronger IDA-backed layout around the later flag bytes.
- Its generated `TreeItor` helpers agree with the core offsets: first child at `+0x04`, next sibling at `+0x10`, hidden/skip flag at `+0x20`, and parent at `+0x00`.

Conclusion: generated source supports the route and several type spellings, but it is not migration-ready source. Do not copy it wholesale.

## Heuristic / Inference Reanalysis And Validation

### Source File Split

- Candidates checked: standalone `ui/controls/FolderTreePane.cpp`; private helper inside `FolderSelectDialog.cpp`; generated `class_FolderTreePane.cpp` as a broad source unit; new tree/template source file.
- Best inference: standalone `ui/controls/FolderTreePane.cpp` with `ui/controls/FolderTreePane.h`.
- Evidence for: independent `ScrollablePane`-derived vtables; class size/layout; local tree/template support; resource string `TREEICON.EPF`; path-fragment strings; filesystem expansion; paint/input/selection behavior; current by-file route and proposed-source-tree placement.
- Evidence against private `FolderSelectDialog` ownership: `FolderSelectDialog` uses the tree through constructor and selected-path helper but owns different dialog-specific state and callback policy.
- Evidence against generated `class_FolderTreePane.cpp`: explicit owner pollution ledger proves large chat/help/surface/system-message ranges are unrelated.
- Remaining blocker: no original file path or PDB symbol; only one confirmed constructor caller. Score impact: keep confidence below final-audit.

### Class Name And Base Type

- Candidate names checked: `FolderTreePane`, folder select tree pane, directory tree pane.
- Best inference: `FolderTreePane`.
- Evidence: validator target, generated class, vtable names, by-file path, and user-facing role all converge.
- Base type: `ScrollablePane`, not a generic `ControlPane` or plain `DialogPane`.
- Evidence: constructor/base calls, inherited scroll virtual slots, `SetSelection` scroll helper calls, and vtable slot layout.

### Control Fields

- `m_tree` at `+0x130`: closed as best-supported.
- `m_folderIconContext` / `m_treeIconContext` near `+0x148`: best-supported for the `TREEICON.EPF` loaded frame/tile context; exact type name remains inferred.
- `m_selection` at `+0x170`: closed as best-supported persistent selected iterator.
- Viewport fields at `+0x114/+0x11c`: do not name as class fields until inherited `ScrollablePane` layout names are authoritative.

Rejected alternatives:

- Treating `+0x170` as temporary iterator: rejected because selected-path, key, mouse, and `SetSelection` all use it persistently.
- Treating `TREEICON.EPF` dwords after `0x0061a5c4` as virtuals: rejected by exact vtable/data split and string xrefs.

### Nested `TreeElem`

- Best source type name: `FolderTreePane::TreeElem`.
- Evidence: generated nested spelling, template vtable names, [UID:0001UJ] owner route, and 36-byte storage.
- Field naming status:
  - `parentIndex`, `firstChildIndex`, `lastChildIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, and `expanded` are strong enough for implementation prose and first-draft struct C++.
  - `previousSiblingIndex` at `+0x0c` is the best-supported name but should remain explicitly inferred.
  - `hidden` at `+0x20` is better than `hiddenOrDeleted` for source-facing docs, but the doc can retain `hidden/skipVisibleTraversal` caveat because no direct delete semantics were found.

### Tree Template Names

- Best template names: `TreeStorage`, `Tree`, and `TreeItor`.
- Evidence: generated class names, vtable names, helper pages, and iterator method names.
- Rejected source placement: standalone `Tree.cpp` or separate generated class files. There is only one concrete instantiation and it is tied to `FolderTreePane`.
- Remaining blocker: no proof that these templates were declared locally versus in a small project utility header. Score impact: target can improve, but template pages should stay below final-source scores.

### Lazy Expansion Method Name

- Current name checked: `FindFirstVisibleChild`.
- Best source-facing descriptive name: `ExpandNode` or `EnsureChildrenLoaded`.
- Evidence: the function builds the current node path, enumerates subdirectories through `FindFirstFileA`/`FindNextFileA`, sorts local records, inserts child nodes, marks children loaded and expanded, and refreshes layout. Callers are constructor/root reset, path selection, right-arrow expansion, and mouse expansion.
- Rejected final interpretation: plain "find first child"; it does more than find and mutates tree state.
- Implementation recommendation: keep current file/page names if renaming is out of scope, but add a source-name note and use `ExpandNode`/`EnsureChildrenLoaded` as best-supported names in prose and future C++.

### `SetSelection`

- Best name: `FolderTreePane::SetSelection`.
- Best signature: `void SetSelection(TreeItor<TreeElem>* selection)` or `void SetSelection(const TreeItor<TreeElem>& selection)`. The generated call sites use pointer form (`&iter`, `&this->m_selection`), so pointer form is safest for first-draft C++.
- Return type: best source-facing return is `void`. Decompiler reports the final invalidate/update return value, but known callers use it for side effects.
- Evidence: direct callers from path selection, key navigation, and mouse selection; exact `0xb9` / 185-byte function; selected iterator comparison and copy; `GetNodeBounds`; current scroll read; max-scroll clamp; scroll update; final vtable `+0x20` update.
- Generated-source state: active validator output has only an empty marker; legacy simroot has decompiler-shaped `sub_4B3210`. The by-memory page should receive the reconstructed body, not the class page.

### Helper Ownership

- Best owner for traversal/sort/path helpers: [UID:0000JG] `FolderTreePane.cpp`.
- Rejected owners:
  - [UID:00005A] for all helpers: too narrow for file-local traversal callbacks, template-generated sort internals, and container helpers with no `this` parameter.
  - [UID:0001UJ] for directory-entry sort: rejected because sort operates on 12-byte temporary directory records, not the final 36-byte `TreeElem`.
  - [UID:0001WP] for directory-entry sort: rejected because that page covers 36-byte tree template support, not local scratch-vector sort internals.
  - A common sort/source file: rejected by single top-level reachability from `FolderTreePane` lazy expansion.

### Vtables, Destructor, And Thunks

- Best model: vtables are source-declared/generated-binary class data; destructor thunks are compiler glue.
- Evidence: exact RTTI/vtable splits, constructor/cleanup/destructor stores, adjustor thunk xrefs, destructor body stores, and `TREEICON.EPF` successor boundary.
- Rejected action: hand-porting vtable arrays or adjustor thunk functions. Source declarations should regenerate them.

### Owner Pollution

- Generated-source pollution is closed, not open.
- Excluded ranges:
  - Chat `0x0047f280-0x00480640` routes to `ChattingPane`/`Chatting.cpp`.
  - Surface/presentation ranges route to `Surface`, `SurfacePresentation`, screenshot, or rendering owners.
  - System/help/message ranges route to `SystemMessagePanes`.
- Evidence: [UID:0000UO] owner-pollution ledger, direct canonical pages, live function inventories, and xref sets.
- Implementation impact: target and file pages should state "do not migrate active generated `class_FolderTreePane.cpp` wholesale."

### First-Draft C++ Gate

- Minimum gate: [UID:00005A] is reconstructable, has nonblank emitter [UID:0000JG], and average score is already above 85.
- Source-quality condition: class-level shell is now defensible; full method bodies on the class page are not.
- Recommendation: yes, emit conservative class declaration shell with fields and `[[CHILDREN]]`; emit exact method bodies only through child memory pages whose source body is mature enough.

## Open-Question Closure

| Question | Closure |
| --- | --- |
| Is `FolderTreePane` a real source class or generated owner pollution? | Real source class. Generated pollution exists but is separable and should not be migrated into this class. |
| Should the source file be `FolderTreePane.cpp` or `FolderSelectDialog.cpp`? | Prefer `FolderTreePane.cpp` under `NexusTK/ui/controls/`; keep a confidence cap because only one constructor caller is currently proven. |
| What are the main class fields? | `m_tree`, `m_folderIconContext`/`m_treeIconContext`, and `m_selection` are best-supported; inherited viewport fields should stay with `ScrollablePane`. |
| Is `SetSelection` missing from the binary? | No. The binary body is exact and documented; generated output is the quality problem. |
| Should `SetSelection` emit C++? | Yes, on [UID:000156] after support update. Do not leave it blank only because generated source was poor. |
| Are directory-entry sort helpers handwritten methods? | No. They are compiler/generated-binary template support for a high-level sort over local `DirectoryEntry` records. |
| Are `Tree`, `TreeStorage`, and `TreeItor` standalone classes/files? | No standalone source file is justified. Keep them as project-local template/support declarations with this control. |
| Are vtables and adjustor thunks source? | Source-declared/generated-binary only. Model class/base/destructor declarations, not table/thunk bodies. |
| Can exact original private helper names be recovered? | Not fully. Descriptive names are defensible from behavior and should be documented; original spellings remain unproved and cap scores below final-audit. |

## First-Draft C++ Recommendation

Recommended target [UID:00005A] formal C++ shape after implementation review:

```cpp
class FolderTreePane : public ScrollablePane
{
public:
    struct TreeElem;

    FolderTreePane(const wchar_t* rootName);
    virtual ~FolderTreePane();

    bool ExpandNode(TreeItor<TreeElem>* node);
    bool CollapseNode(TreeItor<TreeElem>* node);
    void RefreshTreeLayout();
    void SetRootNodeName(const wchar_t* rootName);
    void SelectNodeByPath(const wchar_t* path);
    void SetSelection(TreeItor<TreeElem>* selection);

private:
    Tree<TreeElem> m_tree;                 // +0x130
    EPFTileContext m_folderIconContext;    // near +0x148; exact type/name inferred
    TreeItor<TreeElem> m_selection;        // +0x170

    [[CHILDREN]]
};
```

Notes for implementation:

- If `[[CHILDREN]]` placement inside the class would incorrectly insert non-member support snippets, place it after the class shell and keep nested `TreeElem` emitted from [UID:0001UJ] according to validator behavior. The documentation must explain the intended nesting either way.
- Do not add full method bodies to [UID:00005A].
- If the implementation team is uncomfortable exposing `ExpandNode` before renaming support docs, use `FindFirstVisibleChild` in the formal shell and add a comment/prose note that `ExpandNode` is the best descriptive source name. The report recommendation remains that `ExpandNode`/`EnsureChildrenLoaded` is more source-faithful than `FindFirstVisibleChild`.
- `EPFTileContext` is a best-supported descriptive type. If no validated type page exists at implementation time, use a forward-declared placeholder type only with an explicit caveat in the prose.

Recommended [UID:000156] first-draft method body should express:

- Compare incoming iterator against `m_selection`.
- Copy the iterator payload if it differs.
- Compute selected node bounds through `GetNodeBounds`.
- Read current vertical scroll.
- Scroll upward when selected top is above the viewport.
- Scroll downward when selected bottom is below viewport bottom, clamped to max scroll.
- Invalidate/update the pane.

Do not copy the legacy `sub_4B3210` generated body with raw locals. Reconstruct it in source terms.

## Proposed Score And Metadata Summary

| UID | Page | Recommended metadata / score |
| --- | --- | --- |
| `00005A` | `by-class/FolderTreePane.md` | `88/89`, owner/emitter [UID:0000JG], first-draft class shell as above. |
| `0000JG` | `by-file/FolderTreePane.md` | Consider `90/88` after incorporating this report's source split, owner-pollution closure, field/type decisions, and generated-source omission analysis. Keep `NexusTK/ui/controls/`. |
| `000156` | `FolderTreePaneSetSelection` | Consider `88/90` and first-draft method C++ after naming scroll/selection helpers in source terms. |
| `0001UJ` | `FolderTreePane::TreeElem` | Consider `88/90` after replacing generic uncertainty with the best-supported field names and caveats above; first-draft struct C++ is defensible. |
| `0001WP` | `FolderTreePaneTreeTemplates` | Consider `87/90` after documenting local-template-versus-standalone-source conclusion and remaining reusable-header caveat. |
| `0000F9`, `0000FB`, `0000FC` | Concrete tree support classes | Keep attached to [UID:0000JG]; update prose names and no-standalone-file rationale. |
| `00036N`, `00036O` | Class vtable pages | Scores can remain; ensure target page references them as source-declared/generated-binary and not hand-coded. |
| `000159` | Adjustor thunks | Keep non-reconstructable/non-emitting. |
| `000158` | Tree destructor cleanup | Keep reconstructable source-declared/generated-binary cleanup support but no standalone formal C++. |
| Sort helper pages | `000343`, `000348`, `000349`, `00034A`-`00034E` | Incorporate the `DirectoryEntry` and introsort/source-expression conclusions, especially [UID:00034B] report outcomes. |

## Target / Support Implementation Checklist

If the supervisor accepts this report, the implementation callback should require claim-by-claim incorporation, not a compressed summary.

Target page [UID:00005A] `by-class/FolderTreePane.md`:

1. Update metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter [UID:0000JG].
2. Add the final source split recommendation: `FolderTreePane.cpp` / `FolderTreePane.h` in `NexusTK/ui/controls/`, with `FolderSelectDialog` as consumer and not owner.
3. Add class layout: `ScrollablePane` base, size `0x17c`, vtable views at `+0x00/+0xa0/+0xa4`, `m_tree` at `+0x130`, icon/tile context near `+0x148`, `m_selection` at `+0x170`.
4. Add vtable summary with exact `0x0061a518`, `0x0061a58c`, `0x0061a5bc`, and `TREEICON.EPF` successor boundary.
5. Replace generic "field/header spelling caveat" with the best-supported field/type names and explicit remaining caveats from this report.
6. Add source-facing method-name recommendations, especially `ExpandNode` / `EnsureChildrenLoaded` as the best name for current `FindFirstVisibleChild`.
7. Add generated-source pollution exclusions: chat, surface/presentation/screenshot, and system-message/help code must not be migrated into `FolderTreePane`.
8. Add first-draft class shell with `[[CHILDREN]]` if implementation policy accepts the placeholder type caveats. Do not add method bodies to the class page.

Support docs to update:

1. [UID:0000JG] `by-file/FolderTreePane.md`: incorporate source split closure, owner-pollution closure, local tree/template support, `DirectoryEntry` sort shape, and generated-source quality warning.
2. [UID:000155] `FolderTreePaneCore`: update source-facing method-name notes, especially `ExpandNode`/`EnsureChildrenLoaded`, `BuildSelectedPath`, and `SetSelection` support.
3. [UID:000156] `FolderTreePaneSetSelection`: update name/signature and source-level body narrative; add first-draft method C++ if accepted.
4. [UID:0001UJ] `FolderTreePane::TreeElem`: update field names to `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, `hidden`; keep evidence caveats for `previousSiblingIndex` and `hidden`.
5. [UID:0001WP] `FolderTreePaneTreeTemplates`: state that `Tree`, `TreeStorage`, and `TreeItor` are project-local template/support declarations attached to `FolderTreePane`, not standalone generated classes.
6. [UID:0000F9], [UID:0000FB], [UID:0000FC]: synchronize template/source placement and naming caveats.
7. [UID:000344], [UID:000345], [UID:000346], [UID:000347], [UID:00034H]: keep file-local helper ownership and add best source-facing helper roles where current names are only descriptive.
8. [UID:000343], [UID:000348], [UID:000349], [UID:00034A], [UID:00034B], [UID:00034C], [UID:00034D], [UID:00034E], and [UID:00022E]: synchronize with the 12-byte `DirectoryEntry` record and `std::sort`/introsort source-expression model from `00034B`.
9. [UID:000158]: keep as constructor EH cleanup support, no standalone C++.
10. [UID:000159]: keep non-reconstructable adjustor thunk glue.
11. [UID:00036N], [UID:00036O], and [UID:0001XL]: ensure target class links to exact vtable/data pages and false `TREEICON.EPF` virtual rows are rejected.
12. [UID:0003BH]: link path fragments to lazy expansion and path selection.
13. [UID:0000UO]: optionally update destination snapshot if implementation changes target/file wording; keep it non-reconstructable.
14. [UID:0000VD]: update the `SetSelection` row only if implementation supplies final source-quality C++ or changes the generated-output status.

Validator commands expected for implementation:

> Executable block R002 was removed from this report and preserved verbatim in [00005A-FolderTreePane-class-source-quality-removed.md](00005A-FolderTreePane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the same file-mode apply validator for every additional by-* support doc edited from the checklist. Report each command, exit code, and `ok` count. Do not edit `by-memory/-coverage-report.md`; if memory rows change, leave exact supervisor-owned text.

## Exact Supervisor-Owned Coverage Row

Placement context: replace the current [UID:00005A] row in `by-class/-coverage-report.md`.

```markdown
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) : reconstructable : 88% : strong : B008 2026-06-19 source-quality reanalysis validates `FolderTreePane` as a standalone `ScrollablePane`-derived filesystem tree control under [UID:0000JG] `FolderTreePane.cpp` / `NexusTK/ui/controls/`, with `FolderSelectDialog` as consumer rather than owner; closes the generated `class_FolderTreePane.cpp` pollution route by excluding chat, surface/presentation/screenshot, and help/system-message ranges; records the class size `0x17c`, three vtable views at `0x0061a518/0x0061a58c/0x0061a5bc`, `TREEICON.EPF` successor boundary, `m_tree` at `+0x130`, inferred icon/tile context near `+0x148`, `m_selection` at `+0x170`, source-facing `TreeElem` field names, local `Tree`/`TreeStorage`/`TreeItor` template-support placement, `SetSelection` body readiness from the exact `0x004b3210-0x004b32c9` child, directory-entry sort/source-expression handling from the B008 `00034B` report, compiler/EH no-code handling for vtables/thunks/cleanup fragments, and conservative class-shell first-draft C++ readiness while full method bodies remain delegated to exact by-memory children.
```

If the implementation also changes memory-page scores, the supervisor should apply separate `by-memory/-coverage-report.md` rows for those memory pages. This report did not edit or propose a direct edit to `by-memory/-coverage-report.md`.

## Validator Baseline Result

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R003 was removed from this report and preserved verbatim in [00005A-FolderTreePane-class-source-quality-removed.md](00005A-FolderTreePane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `ok: 1`
- `apply: False`
- Scanned markdown files: `1`
- Target line: `ok 00005A by-class/FolderTreePane.md UID header exists`
- No by-* docs were edited by this dry-run validator baseline.

## Changed Files In This Report Pass

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\00005A-FolderTreePane-class-source-quality.md`
- Updated: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\notes.md`
- Not edited: any by-* docs.
- Not edited: `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00005A"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00005A-FolderTreePane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00005A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
