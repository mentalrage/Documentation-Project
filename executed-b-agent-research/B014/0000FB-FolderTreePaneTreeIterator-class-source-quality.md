** TARGET-REPORT-UID:0000FB **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000FB FolderTreePane TreeItor Class Source-Quality Reanalysis

Agent: B014
Assignment id: `B014-goal2-folder-tree-iterator-template-class-source-quality-0000FB-20260619`
Date: 2026-06-19

Target: [UID:0000FB] `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md`
Expected report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0000FB-FolderTreePaneTreeIterator-class-source-quality.md`

Report-only compliance: this pass does not edit any `by-*` documentation, generated file, project-level file, or coverage report. The only intended writes are this report and `tools/leaser/Agents/Agent-B014/notes.md`.

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0000FB] as the concrete `TreeItor<FolderTreePane::TreeElem>` iterator specialization attached to [UID:0000JG] `FolderTreePane`, but rewrite the target page around source-facing template semantics instead of the generated filename label.

Final disposition:

- Keep `CANONICAL_OWNER:0000JG`.
- Keep `EMITTER_UIDS:0000JG`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Recommended score after accepted implementation: `COMPLETION:88`, `CONFIDENCE:90`.
- Keep the generated output route to `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- Add class-level first-draft C++ for the iterator declaration/layout, but keep compiler-generated destructor glue and vtable-data children as no-handwritten-code items.
- Populate method-body first drafts on the exact traversal children [UID:0002MZ], [UID:0002N0], and [UID:0002N1] only after the implementation callback, not in this report-only pass.

Confidence: very strong for binary behavior, direct owner/emitter route, concrete vtable identity, fields, callers, and cleanup-helper classification; medium-high for original shared-template header factoring because a second specialization exists under EventDispatcher, but no single shared template source/header owner has been modeled yet.

## Target

- Target UID: [UID:0000FB]
- Target path: `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`.
- Current C++: blank.
- Current generated output route: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- Current target summary: concrete label for `TreeItor<FolderTreePane::TreeElem>`, iterator over `FolderTreePane`'s embedded folder tree.

## Evidence Checked

Rules and policy:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B014/goal.md`
- `by-structure.md`
- `inference_research.md`

Target and direct support docs:

- `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md`
- `by-file/FolderTreePane.md`
- `by-class/FolderTreePane.md`
- `by-type/by-struct/FolderTreePane__TreeElem.md`
- `by-type/by-template/FolderTreePaneTreeTemplates.md`
- `by-type/by-vtable/FolderTreePaneVtables.md`
- `by-type/by-vtable/FolderTreePaneTreeItorVtable.md`
- `by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md`
- `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`
- `by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md`
- `by-memory/0x004b57f0-0x004b57f8.FolderTreeIteratorVtableResetHelper.md`
- `by-memory/0x004b5800-0x004b580e.FolderTreeIteratorDualVtableResetHelper.md`
- `by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md`
- `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md`
- `by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md`
- `by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md`
- `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`
- `by-class/Tree_struct_FolderTreePane__TreeElem_.md`
- `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`

Sibling/shared-template context checked:

- `by-class/TreeItor_near_class_EventHandler___.md`
- `by-class/Tree_near_class_EventHandler___.md`
- `by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`
- `by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md`
- `by-file/EventDispatcher.md`

Coverage and generated state checked:

- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-type/by-template/-coverage-report.md`
- `by-type/by-vtable/-coverage-report.md`
- `by-type/by-struct/-coverage-report.md`
- `by-memory/-coverage-report.md` read only.
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-type-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` marker lines for [UID:0000FB] and its child emitters.

Raw/cached binary evidence checked:

- Cached IDA/Ghidra export JSON under `E:\NTK\GhidraBridge\resources\exported_data\functions\`:
  - `0x004b5650.json`
  - `0x004b5670.json`
  - `0x004b5a40.json`
  - `0x004b5bb0.json`
  - `0x004b5bd0.json`
  - `0x004b5c20.json`
- Raw PE bytes from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Raw PE section map, exact bytes for iterator methods/helpers/padding, vtable dwords, abs32 references, and rel32 call/jump references.
- Prior executed research lead: `tools/leaser/Agents/Agent-B001/research/executed/older/000157-FolderTreePaneTreeAndSortHelpers.md`.

Generated Wave/simroot source was not used as authority in this pass. Some support docs contain historical generated-source notes; this report rechecks the claims against by-* docs, cached IDA exports, and raw PE evidence instead of copying generated uncertainty forward.

## Current Binary Facts

Raw PE section facts from `NexusTK.exe`:

- Image base: `0x00400000`.
- `.text`: VA `0x00401000`, vsize `0x20b4ac`, raw `0x400/0x20b600`.
- `.rdata`: VA `0x0060d000`, vsize `0x5f0be`, raw `0x20ba00/0x5f200`.
- `.data`: VA `0x0066d000`, vsize `0x2fe24`, raw `0x26ac00/0xd800`.
- `.rsrc`: VA `0x0069d000`, vsize `0x15c38`, raw `0x278400/0x15e00`.

Iterator exact code/data facts:

| Item | Range / address | Raw/check facts |
| --- | --- | --- |
| `TreeItor` vtable-reset destructor | `0x004b5670-0x004b5677` | Bytes `c7 01 10 a5 61 00 c3`; stores `0x0061a510` to `[ecx]` and returns. |
| One-store cleanup helper | `0x004b57f0-0x004b57f8` | Bytes `c7 41 0c 10 a5 61 00 c3`; stores `0x0061a510` to `[ecx+0x0c]` and returns. |
| Dual-store cleanup helper | `0x004b5800-0x004b580e` | Bytes `c7 41 0c 10 a5 61 00 c7 01 10 a5 61 00 c3`; stores `0x0061a510` to `[ecx+0x0c]` and `[ecx]`, then returns. |
| Scalar deleting destructor | `0x004b5a40-0x004b5a64` | Standard frame, writes `0x0061a510` to `[this]`, conditionally calls free helper when deleting flag bit is set, returns with `ret 4`. |
| `MoveToFirstChild` | `0x004b5bb0-0x004b5bd0` | Reads `this+0x08`, `this+0x04`, record offset `+0x04`; returns `0` on `-1`, otherwise writes current index and returns `1`. |
| `MoveToNextVisibleSibling` | `0x004b5bd0-0x004b5c13` | Reads next-sibling record offset `+0x10`; loops while target record byte `+0x20` is nonzero; writes current index for each candidate; returns `0` on `-1`, else `1`. |
| Padding before parent helper | `0x004b5c13-0x004b5c20` | Thirteen `0xcc` bytes. |
| `MoveToParent` | `0x004b5c20-0x004b5c3f` | Reads record offset `+0x00`; returns `0` on `-1`, otherwise writes current index and returns `1`. |
| Padding after parent helper | `0x004b5c3f-0x004b5c40` | One `0xcc` byte before adjacent vector support. |
| RTTI locator dword | `0x0061a50c` | Raw dword `0x00647968`; belongs before iterator vtable base. |
| Iterator vtable slot | `0x0061a510` | Raw dword `0x004b5a40`; one-slot scalar deleting destructor table. |
| Next data boundary | `0x0061a514` | Raw dword `0x00647894`; next RTTI locator for primary `FolderTreePane` vtable, not an iterator slot. |

Raw xref facts:

- Absolute dword hits to `0x0061a510`: 31, at `0x004b1c34`, `0x004b1c9d`, `0x004b1d1a`, `0x004b1da0`, `0x004b1de7`, `0x004b2632`, `0x004b26a8`, `0x004b26d9`, `0x004b27bb`, `0x004b2a4a`, `0x004b2bd9`, `0x004b2bee`, `0x004b2c2f`, `0x004b2cd9`, `0x004b2cee`, `0x004b2d2f`, `0x004b2ea2`, `0x004b2eb6`, `0x004b2ed1`, `0x004b2f91`, `0x004b30c5`, `0x004b3496`, `0x004b36e6`, `0x004b38ef`, `0x004b5672`, `0x004b57f3`, `0x004b5803`, `0x004b5809`, `0x004b5840`, `0x004b5a4c`, and `0x004b5a9d`.
- Absolute dword hits to `0x004b5a40`: one, at vtable slot `0x0061a510`.
- No absolute dword hits to `0x004b5670`, `0x004b57f0`, `0x004b5800`, `0x004b5bb0`, `0x004b5bd0`, or `0x004b5c20`.
- Rel32 hits to `0x004b5670`: 17 EH jumps at `0x005fe952`, `0x005fe95a`, `0x005fe980`, `0x005fe9ad`, `0x005fea84`, `0x005feaaf`, `0x005feae2`, `0x005feb37`, `0x005feb62`, `0x005feb72`, `0x005feb95`, `0x005feba5`, `0x005febd2`, `0x005febf5`, `0x005feceb`, `0x005fed1b`, and `0x005fefc3`.
- Rel32 hits to `0x004b57f0`: two EH jumps at `0x005feaa7` and `0x005feb9d`.
- Rel32 hits to `0x004b5800`: two EH jumps at `0x005feb5a` and `0x005feb6a`.
- Rel32 hits to `0x004b5bb0`: one direct call at `0x004b2cbe`.
- Rel32 hits to `0x004b5bd0`: one direct call at `0x004b23f2`.
- Rel32 hits to `0x004b5c20`: one direct call at `0x004b2c92`.
- Rel32 hits to `0x004b5a40`: zero; the scalar deleting destructor is vtable-data-referenced.

Adjacent support issue noticed:

- Existing [UID:000158] filename/title uses `0x004b5650-0x004b5668`, but its own 2026-06-05 body text correctly says IDA chunks include `0x004b5650-0x004b5669` and that the final tail-jump byte is at `0x004b5668`. Raw bytes confirm the terminal `jmp` at `0x004b5664` consumes bytes through `0x004b5668`, with padding beginning at `0x004b5669`. This is not a [UID:0000FB] blocker, but the support page's filename/title/range should be rechecked if a future implementation callback touches that cleanup fragment.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner | Current score | Source-quality status |
| --- | --- | --- | --- | --- | --- | --- |
| Concrete iterator class | [UID:0000FB] `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md` | `TreeItor<FolderTreePane::TreeElem>` class/layout and method inventory | TRUE | [UID:0000JG] | `85/86` | Raise to `88/90`; add source-facing class-level C++. |
| Iterator vtable-reset destructor | [UID:00034F] `0x004b5670-0x004b5677...` | Destructor-shaped vtable store reached by EH cleanup jumps | TRUE | [UID:0000FB] | `85/88` | Source-declared/generated-binary; no standalone handwritten C++ body. |
| One-store reset helper | [UID:00031C] `0x004b57f0-0x004b57f8...` | EH cleanup vtable reset helper | FALSE | NONE | `86/90` | Correct as non-emitting compiler cleanup. |
| Dual-store reset helper | [UID:00031D] `0x004b5800-0x004b580e...` | EH cleanup dual vtable reset helper | FALSE | NONE | `86/90` | Correct as non-emitting compiler cleanup. |
| Scalar deleting destructor | [UID:00034J] `0x004b5a40-0x004b5a64...` | Vtable-slot scalar deleting destructor | TRUE | [UID:0000FB] | `86/89` | Source-declared/generated-binary; source destructor declaration should generate it. |
| First-child traversal | [UID:0002MZ] `0x004b5bb0-0x004b5bd0...` | Moves to `firstChildIndex` | TRUE | [UID:0000FB] | `85/90` | Method-body first draft ready. |
| Next-visible-sibling traversal | [UID:0002N0] `0x004b5bd0-0x004b5c13...` | Moves across `nextSiblingIndex`, skipping hidden/filtered records | TRUE | [UID:0000FB] | `85/90` | Method-body first draft ready with `isHidden`/skip flag caveat. |
| Parent traversal | [UID:0002N1] `0x004b5c20-0x004b5c3f...` | Moves to `parentIndex` | TRUE | [UID:0000FB] | `85/90` | Method-body first draft ready. |
| Iterator vtable type | [UID:00036L] `FolderTreePaneTreeItorVtable.md` | One-slot concrete iterator vtable | TRUE | [UID:0000FB] | `86/92` | Source-declared/generated-binary; no raw vtable emission. |
| Iterator vtable data | [UID:00036M] `0x0061a50c-0x0061a514...` | RTTI locator plus scalar destructor slot | TRUE | [UID:0000FB] | `86/92` | Source-declared/generated-binary; no raw data C++. |

## Direct Xref / Caller Inventory

| Target | Caller/xref | Meaning |
| --- | --- | --- |
| `0x004b5bb0` | `0x004b2cbe` inside `FolderTreePane::OnKeyEvent` | Keyboard traversal can move to first child. |
| `0x004b5bd0` | `0x004b23f2` inside `FindFirstVisibleChild` / folder tree traversal | Lazy/visible traversal advances to the next visible sibling. |
| `0x004b5c20` | `0x004b2c92` inside `FolderTreePane::OnKeyEvent` | Keyboard traversal can move to parent. |
| `0x004b5670` | 17 EH jumps from constructor/traversal/paint/key/mouse/path/helper cleanup regions | Destructor-shaped vtable reset for stack/embedded iterator unwinding. |
| `0x004b57f0` | EH jumps from `0x004b2680` and `FolderTreePane::OnMouseEvent` cleanup | One-store iterator view reset helper. |
| `0x004b5800` | EH jumps from `FolderTreePane::OnKeyEvent` cleanup | Dual iterator view reset helper for multiple stack iterator slots. |
| `0x004b5a40` | Vtable data `0x0061a510` | Scalar deleting destructor reached through iterator vtable. |
| `0x0061a510` | 31 vtable-store refs across constructor/setup/traversal/cleanup/destructor paths | Confirms concrete iterator class participates throughout FolderTreePane local iterator construction/destruction. |

## Heuristic / Inference Reanalysis And Validation

### Original Template Spelling

Best source-facing spelling: `TreeItor<FolderTreePane::TreeElem>`.

Evidence:

- IDA names the vtable at `0x0061a510` as `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`, which decodes to `TreeItor<FolderTreePane::TreeElem>` rather than `TreeIterator`.
- Cached IDA decompilation for `0x004b5670` and `0x004b5a40` uses `TreeItor<FolderTreePane::TreeElem>::vftable`.
- [UID:0001WP], [UID:0001XL], [UID:00036L], and [UID:00036M] independently use the same `TreeItor<FolderTreePane::TreeElem>` spelling.
- Sibling [UID:0000FA] uses the same root spelling for `TreeItor<EventHandler*>`.

Rejected alternatives:

- `TreeIterator<FolderTreePane::TreeElem>`: rejected because the RTTI/vtable symbol preserves `TreeItor`, and changing the spelling would create a source/name mismatch with another specialization.
- `TreeItor_struct_FolderTreePane__TreeElem_`: rejected as generated documentation filename syntax, useful for lookup only.
- `cls_0x4b5bb0` / `meth_0x4b5bb0`: rejected as generated OOAnalyzer placeholders contradicted by the named vtable and surrounding template docs.

Final direction:

- The target page should use `TreeItor<FolderTreePane::TreeElem>` as the source-facing name in the heading/status/C++ discussion.
- Keep the filename unless the supervisor explicitly approves a rename, because UID links are stable and many existing docs currently reference the generated filename. A rename to a cleaner `TreeItor_FolderTreePane_TreeElem.md` would be reasonable later but is not required for this report.

### Iterator Layout

Best-supported concrete layout:

| Offset | Source-facing name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | vptr | compiler vtable pointer | Constructor/setup/destructor stores write `0x0061a510`; scalar deleting destructor frees `0x0c`-sized object. |
| `+0x04` | `m_tree` | `Tree<FolderTreePane::TreeElem> *` | Traversal helpers load `this[1]`, then access the tree's storage/vector at `tree + 4`. |
| `+0x08` | `m_currentIndex` | `int` | All three traversal helpers read and update this value as the current node index. |

Evidence:

- `MoveToFirstChild` decompilation: `*(_DWORD *)(this[1] + 4) + 36 * this[2] + 4`.
- `MoveToNextVisibleSibling` decompilation: loads `this[1]` into a tree pointer, uses `this[2]` as current index, and updates `this[2]`.
- `MoveToParent` decompilation: same tree pointer/current-index access pattern.
- EventDispatcher sibling layout [UID:0001UF] records the same iterator record shape: vtable `+0x00`, tree pointer `+0x04`, index `+0x08`.
- `TreeItor` scalar deleting destructor passes size `0x0c` to free when deleting, confirming no additional data fields.

Rejected alternatives:

- Treating the iterator as a raw pair without a vtable: rejected by the vtable at `0x0061a510` and scalar deleting destructor slot.
- Inheriting from `LObject`: not supported. The `Tree<FolderTreePane::TreeElem>` wrapper destructor chains to `LObject`, but `TreeItor<FolderTreePane::TreeElem>` destructor does not call `LObject` teardown and has only a `0x0c` object size.
- Owning storage directly: rejected because `+0x04` points to the tree object whose storage header begins at tree offset `+0x04`; the iterator does not own storage.

### Public Traversal Method Names And Signatures

Recommended method signatures:

```cpp
bool TreeItor<FolderTreePane::TreeElem>::MoveToFirstChild();
bool TreeItor<FolderTreePane::TreeElem>::MoveToNextVisibleSibling();
bool TreeItor<FolderTreePane::TreeElem>::MoveToParent();
```

Evidence:

- All three helpers are `thiscall` leaf methods, take only `this`, and return low-byte `0`/`1`. Source should use `bool`, not decompiler `char`.
- `0x004b5bb0` reads record offset `+0x04`, matching `FolderTreePane::TreeElem::firstChildIndex`; "first child" is direct evidence.
- `0x004b5bd0` reads record offset `+0x10`, then loops while byte `+0x20` is nonzero; the method finds the next sibling that is visible/eligible. `MoveToNextVisibleSibling` is therefore more accurate than plain `MoveToNextSibling`.
- `0x004b5c20` reads record offset `+0x00`, matching `parentIndex`; "parent" is direct evidence.
- Callers align with behavior: keyboard navigation calls parent and first-child traversal; lazy visible traversal calls next-visible-sibling traversal.

Rejected alternatives:

- `GetFirstChild` / `GetParent`: rejected because each method mutates `m_currentIndex`; "MoveTo" or "GoTo" is required.
- `MoveToNextSibling`: incomplete because the method explicitly skips records by byte `+0x20`.
- `FindNextVisibleSibling`: plausible, but less consistent with first-child and parent helpers because it also mutates the iterator itself.
- `Advance`: too generic and hides the tree-axis semantics.

Final direction:

- Use the current descriptive names `MoveToFirstChild`, `MoveToNextVisibleSibling`, and `MoveToParent` as accepted source-quality names. Mark them as behavior-derived/descriptive rather than symbol-proven if the docs need that distinction.

### TreeElem Field Names Used By TreeItor

Fields used directly by the iterator:

- `FolderTreePane::TreeElem::parentIndex` at `+0x00`.
- `FolderTreePane::TreeElem::firstChildIndex` at `+0x04`.
- `FolderTreePane::TreeElem::nextSiblingIndex` at `+0x10`.
- `FolderTreePane::TreeElem::isHidden` or `skipInVisibleTraversal` at `+0x20`.

Best recommendation for `+0x20`:

- Use `isHidden` as the best source-facing short field name inside first-draft C++.
- In documentation, preserve the current uncertainty as "`isHidden` / visible-traversal skip flag; historically documented as `hiddenOrDeleted`."

Evidence:

- `MoveToNextVisibleSibling` loops over sibling links while the target record byte at `+0x20` is nonzero.
- The helper's caller context and name are visible-tree traversal; it searches for a sibling that should be included in visible traversal.
- No checked evidence in this pass proves actual deletion/removal ownership for this byte. "Deleted" remains possible from generic tree storage semantics, but "hidden" is a better behavior name in FolderTreePane's UI-visible traversal.
- [UID:0001UJ] already documents `+0x20` as `hiddenOrDeleted` because only the skip behavior is fully proven; that conservative doc state is acceptable until a broader layout pass finds all writes.

Rejected alternatives:

- `isDeleted` alone: not supported because no deletion-only writer was checked here, and the observed consumer is visible traversal.
- `isVisible`: misleading because nonzero means skip/hidden, not visible.
- `unused` or padding: rejected because the byte is read by live traversal code.

### Cleanup Helper Classification

Accepted classification:

- [UID:00034F] `0x004b5670-0x004b5677` is source-declared/generated-binary destructor support. It represents a destructor-shaped vtable reset emitted for iterator cleanup, but not a meaningful handwritten method body.
- [UID:00034J] `0x004b5a40-0x004b5a64` is source-declared/generated-binary scalar deleting destructor support. It should come from a virtual destructor declaration and compiler delete glue.
- [UID:00031C] and [UID:00031D] are compiler/EH cleanup helpers and should remain `RECONSTRUCTABLE:FALSE`.

Evidence:

- `0x004b5670` has a one-store vtable reset body and 17 EH jump refs, no ordinary behavior.
- `0x004b5a40` is the sole vtable slot target at `0x0061a510`, restores the iterator vtable, conditionally frees `0x0c`, and returns `this`.
- `0x004b57f0` and `0x004b5800` have only vtable stores and EH jumps; raw scan found no normal direct calls.
- The source-level counterpart is a virtual destructor declaration on `TreeItor<T>`, not hand-authored vtable stores.

Rejected alternatives:

- Source-authored utility methods: rejected because no method semantics exist beyond vtable reset.
- Assigning [UID:00031C]/[UID:00031D] to [UID:0000FB] as reconstructable children: rejected because they are cleanup thunks with no source behavior to recreate manually.
- Marking all destructor-support pages `RECONSTRUCTABLE:FALSE`: too strong for [UID:00034F]/[UID:00034J], because equivalent destructor/vtable behavior must arise from source declarations. The correct model is source-declared/generated-binary with no standalone handwritten C++ body.

### Source/Header Placement

Current direct owner/emitter should stay [UID:0000JG] `FolderTreePane`.

Best source-header inference:

- The source-facing type is a project-local `TreeItor<T>` template, because both `TreeItor<FolderTreePane::TreeElem>` and `TreeItor<EventHandler*>` exist.
- No current by-file page owns a shared `Tree.h`/`TreeTemplates.h` source root. Under current documentation structure, concrete instantiations remain routed through their consuming source modules: [UID:0000JG] for FolderTreePane and [UID:0000J7] for EventDispatcher.
- For final reconstruction, the likely mid-2000s source shape is either:
  - a small reusable tree template declared in a private/shared UI helper header included by both `EventDispatcher.cpp` and `FolderTreePane.cpp`, or
  - local duplicate/specialized tree-template declarations emitted in each source module by the original generated/imported source organization.
- The first option is more source-natural because the `TreeItor` spelling and layout are shared; the second option is safer for current documentation because the two specializations have different record layouts and currently have separate, valid file-owner routes.

Recommendation:

- Do not create a new `TreeItor`/`TreeTemplates` source file in this report-only pass.
- Do not move [UID:0000FB] away from [UID:0000JG].
- Add a synchronization note to [UID:0001WP] and [UID:0000FB]: if a future shared tree-template header is accepted, it must absorb both the FolderTreePane and EventDispatcher specializations, or explicitly document why those instantiations remain module-local.

Rejected alternatives:

- Standalone generated source `class_TreeItor_struct_FolderTreePane__TreeElem_.cpp`: rejected as generated pollution. Original code would not normally have a one-specialization `.cpp` named after a mangled template argument.
- EventDispatcher ownership: rejected because [UID:0000FA] is a sibling specialization, not the owner of the FolderTreePane specialization.
- FolderTreePane class [UID:00005A] as canonical owner: plausible for an embedded helper, but current docs consistently attach the concrete template support classes to the file [UID:0000JG], while `TreeElem` itself attaches to the class [UID:00005A]. Keep this distinction: `TreeElem` is nested class data; `TreeItor<T>` is template support owned by the source module.

### Relationship To FolderTreePane::TreeElem

Accepted relationship:

- [UID:0001UJ] `FolderTreePane::TreeElem` is the payload/node record type over which [UID:0000FB] iterates.
- The iterator does not own `TreeElem`; it reads `TreeElem` link/visibility fields through `Tree<FolderTreePane::TreeElem>` storage.
- The iterator depends on [UID:0001UJ]'s field names and should use the same names in first-draft C++.

Impact:

- [UID:0001UJ] should absorb the source-facing name recommendation for `+0x20` as `isHidden` or `visibleTraversalSkip` while preserving the old `hiddenOrDeleted` uncertainty as historical/conservative evidence.
- [UID:0000FB] should not define `FolderTreePane::TreeElem`; it should reference [UID:0001UJ].

### Relationship To FolderTreePaneTreeTemplates

Accepted relationship:

- [UID:0001WP] is the cross-reference/type-context page for `TreeStorage<FolderTreePane::TreeElem>`, `Tree<FolderTreePane::TreeElem>`, and `TreeItor<FolderTreePane::TreeElem>`.
- [UID:0000FB] is the concrete iterator class page.
- [UID:0001WP] should carry the shared/header factoring discussion; [UID:0000FB] should carry concrete class layout, methods, vtable, children, and first-draft class declaration.

Recommended sync:

- Raise [UID:0001WP] only modestly if updated, because shared-template header placement remains not fully proven. A good support score after implementation would be `87/90`, not final-audit.
- Add [UID:0000FA] EventDispatcher sibling evidence to [UID:0001WP]'s open question closure.

### Generated-Source Pollution

Reject these names/shapes in source-facing docs:

- `TreeItor_struct_FolderTreePane__TreeElem_` as a source class spelling.
- `cls_0x4b5bb0`, `meth_0x4b5bb0`, `meth_0x4b5bd0`, `meth_0x4b5c20`.
- `FUN_004b5670`, `sub_4B5670`, `sub_4B5BB0`, `sub_4B5BD0`, `sub_4B5C20`.
- Ghidra's `MemMapBase::scalar deleting destructor` label on `0x004b5a40`; that is a library-signature/type-pollution artifact. The body targets the `TreeItor<FolderTreePane::TreeElem>` vtable.
- A standalone generated class `.cpp` for this concrete specialization.

Accepted search aliases:

- Keep generated filename/UID labels in cross-reference/history sections only so older reports can be found.
- Use `TreeItor<FolderTreePane::TreeElem>` in source-facing text and C++.

### Open-Question Closure

Original template spelling:

- Closed. Use `TreeItor<FolderTreePane::TreeElem>`.

Public traversal method names:

- Closed to high-probability descriptive names: `MoveToFirstChild`, `MoveToNextVisibleSibling`, `MoveToParent`.

Iterator fields:

- Closed: `m_tree` at `+0x04`, `m_currentIndex` at `+0x08`; vptr at `+0x00`.

`TreeElem +0x20` exact original name:

- Not fully closed by original-symbol proof. Best-supported source-facing name is `isHidden`; documentation should state it is a visible-traversal skip flag and preserve the prior `hiddenOrDeleted` uncertainty until all writers are reconciled. This does not block first-draft C++ because the method behavior is clear and the name can be marked inferred.

Shared template header factoring:

- Not fully closed. Best-supported direction is a shared `Tree<T>`/`TreeItor<T>` template header or private helper declarations reused by both FolderTreePane and EventDispatcher. Current documentation should not create a new shared owner yet because the source tree lacks a scored shared file/header node and concrete specializations already have valid consumer-file routes. This caps completion but does not block class-level draft C++.

Cleanup helper status:

- Closed. [UID:00031C]/[UID:00031D] are compiler/EH cleanup helpers; [UID:00034F]/[UID:00034J] are source-declared/generated-binary destructor support.

C++ readiness:

- Closed. [UID:0000FB] is eligible for class-level first-draft C++. Child traversal method pages are also eligible for method-body drafts. Compiler-generated destructor/vtable helper pages should not receive handwritten bodies.

## Ranked Ownership Analysis

### 1. [UID:0000JG] FolderTreePane

Evidence for:

- Target metadata already routes owner/emitter to [UID:0000JG].
- [UID:0000JG] has valid reconstruction path `NexusTK/ui/controls/`.
- [UID:0000JG] explicitly lists `TreeItor<FolderTreePane::TreeElem>` as local tree/template support.
- Iterator method callers are inside FolderTreePane methods and helper cluster: `OnKeyEvent`, `FindFirstVisibleChild`, traversal, paint, layout, selection/path cleanup, and destructor paths.
- The vtable-store refs to `0x0061a510` are all in the FolderTreePane control region for this specialization.
- [UID:0001WP] ties this exact specialization to FolderTreePane, not to a standalone generated file.

Evidence against:

- A sibling `TreeItor<EventHandler*>` specialization exists, so the generic template may have been declared in a shared header.

Decision:

- Accepted current direct owner/emitter. The possible shared header affects source factoring notes, not current direct UID ownership.

### 2. [UID:00005A] FolderTreePane class

Evidence for:

- The iterator is embedded/used by `FolderTreePane`.
- `FolderTreePane` has selected iterator at offset `+0x170`.
- `FolderTreePane::TreeElem` is nested under [UID:00005A].

Evidence against:

- Current template-support class pages [UID:0000F9], [UID:0000FB], [UID:0000FC] are consistently direct-owned by the source file [UID:0000JG], while the nested data record [UID:0001UJ] is direct-owned by the class.
- The iterator is a generic template specialization, not a nested `FolderTreePane` class in the vtable spelling.

Decision:

- Reject as canonical owner for [UID:0000FB]. Keep [UID:00005A] as class context and owner of `FolderTreePane::TreeElem`.

### 3. Shared Tree Template File/Header

Evidence for:

- `TreeItor<EventHandler*>` [UID:0000FA] and `TreeItor<FolderTreePane::TreeElem>` [UID:0000FB] share the `TreeItor` template name and iterator layout.
- EventDispatcher layout [UID:0001UF] has the same iterator record fields: vtable, tree pointer, current index.
- A reusable template header is a plausible mid-2000s C++ source structure.

Evidence against:

- No current by-file shared tree-template owner exists.
- The two specializations are tightly embedded in different source modules with different record/payload layouts and local helper islands.
- Existing coverage and emitter routes are valid through consumer modules.

Decision:

- Do not create or assign a new shared file in this pass. Record as header-factoring direction in [UID:0001WP] and revisit only if a broader tree-template owner is created.

### 4. Standalone Generated Class Source

Evidence for:

- Generated filenames use standalone class-like names.

Evidence against:

- Names are generated/mangled.
- No source-tree evidence supports one `.cpp` per concrete template instantiation.
- Vtable/caller evidence ties this specialization to FolderTreePane's module.

Decision:

- Rejected.

## First-Draft C++ Recommendation

Recommendation: populate [UID:0000FB] with class-level first-draft C++ during the implementation callback. The target meets the active gate:

- `RECONSTRUCTABLE:TRUE`
- Nonblank `EMITTER_UIDS:0000JG`
- Emitter route reaches `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`
- `(85 + 86) / 2 = 85.5`, greater than `85`

Class-page draft:

```cpp
// Concrete evidence target: TreeItor<FolderTreePane::TreeElem>.
// If a shared Tree<T>/TreeItor<T> header is later accepted, move this
// declaration there and keep this page as the FolderTreePane instantiation
// evidence.
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
    Tree<T> *m_tree;       // +0x04 in TreeItor<FolderTreePane::TreeElem>
    int m_currentIndex;    // +0x08 in TreeItor<FolderTreePane::TreeElem>
};
```

Why this is appropriate:

- It is class-level code, matching class-page emitter rules.
- It avoids method bodies in the class page.
- It uses `TreeItor`, not `TreeIterator`.
- It records the proven layout without writing decompiler-shaped raw code.
- It allows the compiler to generate the vtable, destructor reset body, scalar deleting destructor, and vtable data.

Implementation caution:

- If the supervisor wants [UID:0001WP] to emit the generic template declaration instead, then [UID:0000FB] should emit only a short comment or concrete instantiation marker to avoid duplicate generic declarations. My recommendation is to add the class-level declaration to [UID:0000FB] now, then later consolidate through [UID:0001WP] if a shared tree-template header is accepted.

Method-child first-draft bodies for later support pages:

```cpp
template <>
bool TreeItor<FolderTreePane::TreeElem>::MoveToFirstChild()
{
    int childIndex = m_tree->m_storage[m_currentIndex].firstChildIndex;
    if (childIndex == -1)
        return false;

    m_currentIndex = childIndex;
    return true;
}

template <>
bool TreeItor<FolderTreePane::TreeElem>::MoveToNextVisibleSibling()
{
    int siblingIndex = m_tree->m_storage[m_currentIndex].nextSiblingIndex;
    while (siblingIndex != -1)
    {
        m_currentIndex = siblingIndex;
        if (!m_tree->m_storage[siblingIndex].isHidden)
            return true;

        siblingIndex = m_tree->m_storage[siblingIndex].nextSiblingIndex;
    }

    return false;
}

template <>
bool TreeItor<FolderTreePane::TreeElem>::MoveToParent()
{
    int parentIndex = m_tree->m_storage[m_currentIndex].parentIndex;
    if (parentIndex == -1)
        return false;

    m_currentIndex = parentIndex;
    return true;
}
```

Method draft caveats:

- Replace `m_storage` with the accepted `Tree<FolderTreePane::TreeElem>` storage field name from [UID:0000F9]/[UID:0000FC].
- Replace `isHidden` if [UID:0001UJ] later proves a stronger original name for `TreeElem +0x20`.
- The method child pages should carry these bodies, not [UID:0000FB], if implementation accepts them.

Exact no-code/defer proof for destructor/vtable children:

- [UID:00034F], [UID:00034J], [UID:00036L], and [UID:00036M] should not receive handwritten vtable-store/vtable-data C++ bodies. Equivalent binary output comes from the virtual destructor declaration and class layout.
- [UID:00031C] and [UID:00031D] should remain non-reconstructable and C++ blank because they are EH cleanup helpers with no source-authored behavior.

## Score Recommendation

Recommended [UID:0000FB] score: `88/90`.

Before:

- `COMPLETION:85`
- `CONFIDENCE:86`

After:

- `COMPLETION:88`
- `CONFIDENCE:90`

Justification:

- Exact class spelling is now resolved to `TreeItor<FolderTreePane::TreeElem>`.
- Iterator layout is resolved to vptr, `m_tree`, and `m_currentIndex`.
- Public traversal names/signatures are resolved to high-probability descriptive source names.
- Cleanup helper classification is resolved.
- Direct owner/emitter route is validated against source docs, cached IDA exports, raw PE bytes, vtable data, and generated coverage.
- First-draft class C++ is ready.

Why not higher:

- Exact shared-template header factoring remains unresolved because `TreeItor<EventHandler*>` exists and there is no accepted shared template file/header owner yet.
- `TreeElem +0x20` exact original source name remains inferred; `isHidden` is best-supported but not symbol-proven.
- Child method C++ has not been incorporated into the by-memory method pages yet.
- This is not final-audit quality and should remain below `95`.

Recommended support score adjustments if accepted:

- [UID:0001WP] `FolderTreePaneTreeTemplates`: `87/90` after adding shared-template factoring and EventDispatcher sibling evidence.
- [UID:0002MZ] first-child method: `86/91` after adding first-draft method C++.
- [UID:0002N0] next-visible-sibling method: `86/90` after adding first-draft method C++ and `+0x20` skip-flag naming caveat.
- [UID:0002N1] parent method: `86/91` after adding first-draft method C++.
- [UID:00034F]/[UID:00034J]/[UID:00036L]/[UID:00036M]: no score raise required unless implementation adds clearer no-code proof text; current scores are acceptable.
- [UID:00031C]/[UID:00031D]: no score or metadata change recommended.

## Exact Implementation Checklist For Later Callback

Target [UID:0000FB] `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90` if accepted.
- Keep owner/emitter/reconstructable fields unchanged.
- Add a dedicated `## Heuristic / Inference Reanalysis And Validation` section or incorporate this report's section at report-level detail.
- Change source-facing text from generated filename label to `TreeItor<FolderTreePane::TreeElem>`.
- Add layout table: vptr `+0x00`, `Tree<FolderTreePane::TreeElem> *m_tree` `+0x04`, `int m_currentIndex` `+0x08`.
- Add public/source method signature table using `bool MoveToFirstChild()`, `bool MoveToNextVisibleSibling()`, and `bool MoveToParent()`.
- Add cleanup classification:
  - [UID:00034F] and [UID:00034J] are source-declared/generated-binary destructor support.
  - [UID:00031C] and [UID:00031D] are compiler/EH cleanup helpers and non-emitting.
- Add source/header factoring text:
  - `TreeItor` is likely a shared project template because [UID:0000FA] exists.
  - Current concrete FolderTreePane specialization remains under [UID:0000JG].
  - Do not create a standalone generated class `.cpp`.
- Insert the class-level first-draft C++ block or, if supervisor decides [UID:0001WP] owns the generic declaration instead, insert an explicit comment-only no-duplicate marker and state [UID:0001WP] will emit the template.

Support [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md`:

- Add `TreeItor<EventHandler*>` sibling evidence from [UID:0000FA] and [UID:0001UF].
- Replace open-ended "whether reusable tree template header shared elsewhere" with the current best inference: shared template header is likely, but no by-file owner exists and concrete specializations remain routed through consumer modules for now.
- Record that `TreeItor` spelling is symbol-backed and should not be normalized to `TreeIterator`.
- If scoring is changed, use `87/90` and explain the remaining cap.

Support [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`:

- Keep `parentIndex`, `firstChildIndex`, and `nextSiblingIndex`.
- Refine `+0x20` from `hiddenOrDeleted` to "best source-facing `isHidden` / visible-traversal skip flag; historical `hiddenOrDeleted` remains a conservative earlier label until all writers are reconciled."
- Cross-link [UID:0000FB] traversal method evidence.

Support [UID:0000JG] `by-file/FolderTreePane.md`:

- Add the source-quality conclusion that [UID:0000FB] is class-level C++ ready.
- Add the shared-template/header caveat and the current decision not to create a standalone `TreeItor` source file.
- Keep `FolderTreePane.cpp` and `FolderTreePane.h` as the current reconstruction home for this concrete specialization.

Support [UID:00005A] `by-class/FolderTreePane.md`:

- Sync iterator field/member references: embedded selected iterator at `+0x170`, concrete iterator type `TreeItor<FolderTreePane::TreeElem>`, methods `MoveToFirstChild`, `MoveToNextVisibleSibling`, `MoveToParent`.
- Do not make [UID:00005A] the direct owner of [UID:0000FB]; keep file ownership.

Support child traversal methods:

- [UID:0002MZ] `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md`
  - Add first-draft method body using `firstChildIndex`.
  - Raise to `86/91` if accepted.
- [UID:0002N0] `by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md`
  - Add first-draft method body using `nextSiblingIndex` and `isHidden` / visible-traversal skip flag.
  - Raise to `86/90` if accepted.
- [UID:0002N1] `by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md`
  - Add first-draft method body using `parentIndex`.
  - Raise to `86/91` if accepted.

Support destructor/vtable docs:

- [UID:00034F] `0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md`
  - Add explicit no-handwritten-code proof: source virtual destructor emits this reset during EH cleanup.
- [UID:00034J] `0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md`
  - Add explicit no-handwritten-code proof: compiler scalar deleting destructor emitted from virtual destructor and delete expressions.
- [UID:00036L] `FolderTreePaneTreeItorVtable.md`
  - Add source-declared/generated-binary note tied to [UID:0000FB] C++ declaration.
- [UID:00036M] `0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md`
  - Add no-raw-vtable-C++ proof and keep exact data as generated by class declarations.
- [UID:00031C] and [UID:00031D]
  - No metadata change required; optionally add cross-reference to this report's cleanup-helper classification.

Support [UID:000158] `0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`:

- If touched during callback, recheck filename/title half-open range. Its body text already says the IDA chunk is `0x004b5650-0x004b5669` and raw bytes confirm byte `0x004b5668` is part of the terminal jump immediate. This is adjacent `Tree<T>` cleanup, not [UID:0000FB], so do not block target implementation on it.

Support [UID:0000FA] / EventDispatcher tree docs:

- Do not edit unless the implementation callback explicitly expands shared-template scope.
- If touched, add a reciprocal note that `TreeItor<EventHandler*>` and `TreeItor<FolderTreePane::TreeElem>` likely share a project tree-template spelling, while their concrete emitter routes remain module-local.

Generated files:

- Do not manually edit `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- After accepted by-* edits, run the scoped validators listed below and let validator-owned generated files update only through validator.

Coverage:

- B014 must not edit `by-memory/-coverage-report.md`.
- Use the exact row text in the next section for supervisor-owned coverage changes.

## Exact Supervisor-Owned Coverage Row Text

Current target by-class row observed before this report:

```md
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) : reconstructable : 85% : strong : Folder-tree iterator specialization with live IDA method boundaries, named `TreeItor<FolderTreePane::TreeElem>` vtable, 31 vtable data xrefs, direct FolderTreePane traversal callers, 36-byte tree-node field usage, Batch117 cleanup-helper split links, and direct parent attachment to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) now justified under the strict `85/85` gate.
```

Recommended target by-class replacement row:

```md
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality reanalysis resolves the source-facing `TreeItor<FolderTreePane::TreeElem>` spelling, `+0x04` tree pointer and `+0x08` current-index layout, `bool` traversal method signatures (`MoveToFirstChild`, `MoveToNextVisibleSibling`, `MoveToParent`), direct FolderTreePane.cpp owner/emitter route, EventDispatcher sibling-template factoring caveat, vtable/RTTI data ownership, EH cleanup-helper rejection, source-declared destructor glue policy, and class-level first-draft C++ readiness; remaining cap is shared template-header ownership and final `TreeElem +0x20` field spelling.
```

Recommended by-type template row if [UID:0001WP] is updated:

```md
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) : reconstructable : 87% : very strong : B014 2026-06-19 reanalysis keeps concrete `TreeStorage<FolderTreePane::TreeElem>`, `Tree<FolderTreePane::TreeElem>`, and `TreeItor<FolderTreePane::TreeElem>` support under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), resolves `TreeItor` spelling and iterator class/method roles, records sibling `TreeItor<EventHandler*>` evidence as likely shared-template/header factoring, and keeps final shared-header ownership open because no scored generic tree-template file owner exists yet.
```

Recommended by-memory traversal rows if method-body C++ is accepted:

```md
        - [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) 0x004b5bb0-0x004b5bd0 | template method | FolderTreeIteratorMoveToFirstChild : reconstructable : 86% : very strong : B014 2026-06-19 source-quality pass confirms `bool TreeItor<FolderTreePane::TreeElem>::MoveToFirstChild()`, exact leaf body, caller `0x004b2cbe`, `m_tree` at iterator `+0x04`, `m_currentIndex` at `+0x08`, `FolderTreePane::TreeElem::firstChildIndex` at `+0x04`, and first-draft C++ readiness under [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md).
```

```md
        - [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) 0x004b5bd0-0x004b5c13 | template method | FolderTreeIteratorMoveToNextVisibleSibling : reconstructable : 86% : very strong : B014 2026-06-19 source-quality pass confirms `bool TreeItor<FolderTreePane::TreeElem>::MoveToNextVisibleSibling()`, exact leaf body, caller `0x004b23f2`, `nextSiblingIndex` at `TreeElem +0x10`, visible-traversal skip byte at `TreeElem +0x20` best named `isHidden`/skip flag, and first-draft C++ readiness under [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) with final `+0x20` spelling caveat.
```

```md
        - [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) 0x004b5c20-0x004b5c3f | template method | FolderTreeIteratorMoveToParent : reconstructable : 86% : very strong : B014 2026-06-19 source-quality pass confirms `bool TreeItor<FolderTreePane::TreeElem>::MoveToParent()`, exact leaf body, caller `0x004b2c92`, `m_tree` at iterator `+0x04`, `m_currentIndex` at `+0x08`, `FolderTreePane::TreeElem::parentIndex` at `+0x00`, and first-draft C++ readiness under [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md).
```

No by-memory coverage row changes are required for [UID:00031C] or [UID:00031D]. Their current ignored/non-emitting classification is correct.

Optional support row if [UID:00034F] is updated:

```md
        - [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) 0x004b5670-0x004b5677 | iterator destructor support | FolderTreeIteratorVtableResetDestructor : reconstructable : 85% : strong : Source-declared/generated-binary destructor support assigned to [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md); raw body stores the `TreeItor<FolderTreePane::TreeElem>` vtable and is reached by EH cleanup jumps, so final source should declare the virtual destructor and not hand-port the vtable store as standalone C++.
```

Optional support row if [UID:00034J] is updated:

```md
        - [UID:00034J][0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor](by-memory/0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md) 0x004b5a40-0x004b5a64 | scalar deleting destructor | FolderTreeIteratorScalarDeletingDestructor : reconstructable : 86% : strong : Source-declared/generated-binary scalar deleting destructor support assigned to [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md); vtable slot `0x0061a510` points here, raw body resets the iterator vtable and conditionally frees the `0x0c`-sized object, so source reconstruction belongs to the `TreeItor<T>` virtual destructor declaration rather than a handwritten method body.
```

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md](0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- Mode: `file`.
- Apply: `False`.
- Scanned markdown files: `1`.
- `ok: 1`.
- Target OK line: `ok 0000FB by-class/TreeItor_struct_FolderTreePane__TreeElem_.md UID header exists`.
- Dry-run incremental stats skipped: `stats_incremental_skip 0000FB project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows`.
- Autogen registry rebuilt in dry run: `4693 metadata nodes, 4083 edges`.
- Relevant generated output marker state: [UID:0000FB] and its iterator child pages currently appear as `Empty Emitter Marker` entries in `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- Dry-run validator reported `autogen_cpp_update 0000P1 auto-generated/NexusTK/ui/panels/UserPane.cpp validator-owned generated file` and `autogen_report_update auto-generated/-ag-memory-coverage.md validator-owned generated file`; because this was a dry run, no generated files were written.
- No target-specific validator failure was observed.

Recommended callback validators after accepted by-* implementation:

> Executable block R002 was removed from this report and preserved verbatim in [0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md](0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation touches vtable/destructor support pages, additionally run:

> Executable block R003 was removed from this report and preserved verbatim in [0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md](0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files In This Report-Only Pass

Created:

- `tools/leaser/Agents/Agent-B014/research/0000FB-FolderTreePaneTreeIterator-class-source-quality.md`

Modified:

- `tools/leaser/Agents/Agent-B014/notes.md`

Not edited:

- No `by-*` documentation files were edited.
- No generated files were edited.
- No coverage reports were edited.
- `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0000FB"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FB-FolderTreePaneTreeIterator-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
