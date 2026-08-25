** TARGET-REPORT-UID:0000F8 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000F8] Tree<EventHandler*> / EventDispatcher Tree Specialization Source-Quality Report

Assignment: `B008-goal2-eventdispatcher-tree-specialization-class-source-quality-0000F8-20260619`  
Agent: `Agent-B008`  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Tree_near_class_EventHandler___.md`  
Report-only pass: no by-* documentation, generated files, or coverage reports were edited.

## Recommendation

Update [UID:0000F8] from `COMPLETION:85` / `CONFIDENCE:86` to `COMPLETION:87` / `CONFIDENCE:90`. Keep:

- `CANONICAL_OWNER:0000J7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000J7`
- blank `RECONSTRUCTION_CPP CODE`

The final source-facing type name should be documented as concrete `Tree<EventHandler *>` / `Tree<EventHandler*>`. The page filename and title `Tree_near_class_EventHandler___` should remain only as the current generated documentation alias unless a broader by-class renaming policy is later applied. The `near_class` text is a Ghidra/Wave2 generated spelling artifact, not the best source-facing C++ spelling.

The class remains EventDispatcher-local for ownership/emission. The best current source route is still [UID:0000J7] `EventDispatcher` / `NexusTK/ui/core/EventDispatcher.cpp`, with the likely declaration in `EventDispatcher.h` or a shared project tree-template header included by that source. A standalone final source file such as `class_Tree_near_class_EventHandler___.cpp`, `Tree_near_class_EventHandler___.cpp`, or generic `Tree.cpp` is not supported by current caller/vtable evidence.

## Current Target State

The target page currently records:

- Generated alias: `Tree_near_class_EventHandler___`.
- Source role: generated `Tree<EventHandler*>` specialization used by `EventDispatcher`.
- Methods:
  - ordinary tree destructor currently listed as `0x004a7cd0-0x004a7ce8`;
  - scalar deleting destructor currently listed as `0x004a7d80-0x004a7dc7`.
- Owner/emitter: [UID:0000J7] `EventDispatcher`.
- C++ block: blank.
- Open-quality blockers: final template/header spelling and raw destructor function-object caveat.

The source-placement decision is directionally correct, but the class page should be strengthened with current source-facing names, field/storage names, exact byte/range corrections, vtable slot names, rejected generated alternatives, and an explicit no-code proof under the active combined-score emitter gate.

## Evidence Checked

Target and direct support docs:

- [UID:0000F8] `by-class/Tree_near_class_EventHandler___.md`
- [UID:0000FA] `by-class/TreeItor_near_class_EventHandler___.md`
- [UID:000060] `by-class/HandlerFindFunc.md`
- [UID:00004M] `by-class/EventDispatcher.md`
- [UID:0000J7] `by-file/EventDispatcher.md`
- [UID:000146] `by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md`
- [UID:000141] `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`
- [UID:000144] `by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md`
- [UID:000145] `by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md`
- [UID:000147] `by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md`
- [UID:00022A] `by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md`
- [UID:000148] `by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md`
- [UID:00022B] `by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md`
- [UID:0001UF] `by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`
- [UID:0003I5] `by-memory/0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData.md`
- [UID:000258] `by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md`
- [UID:00004N] `by-class/EventHandler.md`
- [UID:00007D] `by-class/LObject.md`
- [UID:0000KV] `by-file/LObject.md`
- [UID:000370] `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md`
- [UID:000371] `by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md`
- [UID:0000WM] `by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md`

Cross-template/source-shape comparison:

- [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md`
- [UID:0000F9] `by-class/Tree_struct_FolderTreePane__TreeElem_.md`
- `by-file/FolderTreePane.md`
- `by-type/by-vtable/FolderTreePaneTreeVtable.md`

Generated and Wave2 evidence:

- `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`
- `core/data/readonly/wave2/classes/Tree_near_class_EventHandler___.json`
- `core/data/cache/wave2/classes/Tree_near_class_EventHandler___.json`
- Builder manifests still reference old generated source names, but the corresponding `simroot` / `simroot_v2` `Tree_near_class_EventHandler___.cpp` files are not present in this checkout. Treat those manifest references as stale generated-output leads, not durable source ownership evidence.

Local PE evidence:

- Binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Relevant sections: `.text` RVA `0x1000`, `.rdata` RVA `0x20d000`.
- The local MCP endpoint `http://127.0.0.1:13337/mcp` was unavailable (`Unable to connect to the remote server`), so no new live-MCP claims are made in this report. Current by-* pages already contain prior live IDA/MCP evidence; this pass adds local PE byte verification for the target body and vtable cells.

Validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [0000F8-EventDispatcherTreeSpecialization-class-source-quality-removed.md](0000F8-EventDispatcherTreeSpecialization-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result from `source-3/project-documentation`: exit code `0`, `ok: 1`. This was a dry run; no generated or by-* files were written.

## Exact Binary Behavior And Range Validation

The executable code for the target's two tree methods is small and exact. Local PE bytes show that existing documentation uses inclusive-looking terminal addresses in several method rows even though by-structure documentation expects half-open ranges.

### Ordinary Tree Destructor

Correct half-open range: `0x004a7cd0-0x004a7ce9` (`0x19` / 25 bytes).

Local bytes:

```text
0x004a7cd0-0x004a7ce9:
56 8b f1 8d 4e 04 c7 06 2c 96 61 00 e8 bf 0a 00
00 8b ce 5e e9 a7 cd 04 00
```

Instruction-level behavior:

- Saves `esi`.
- Copies `this` into `esi`.
- Computes `ecx = this + 4`, the embedded record-vector/storage subobject.
- Stores `0x0061962c` into `[this]`, reinstalling `Tree<EventHandler *>::vftable`.
- Calls `0x004a87a0`, best source-facing `FreeHandlerRecordVector(EventHandlerRecordVector *records)`, on the vector at `this + 4`.
- Restores `ecx = this`, restores `esi`, and tail-jumps to `0x004f4a90`, the `LObject` non-deleting destructor body.

Correct padding after the ordinary destructor is `0x004a7ce9-0x004a7cf0` (`7` bytes of `0xcc`). Existing target/support text that says `0x004a7cd0-0x004a7ce8` should be corrected or explicitly marked as an inclusive terminal-byte notation.

### Iterator Destructor Neighbor

The target page does not own this method, but the neighboring support page does and it affects the sparse-island boundary.

Correct half-open range: `0x004a7cf0-0x004a7cf7` (`0x07` / 7 bytes).

Local bytes:

```text
0x004a7cf0-0x004a7cf7: c7 01 50 96 61 00 c3
0x004a7cf7-0x004a7d00: cc cc cc cc cc cc cc cc cc
```

Behavior: one vtable store to `TreeItor<EventHandler *>::vftable` at `0x00619650`, then return. This should remain with [UID:0000FA], not [UID:0000F8].

### Handler List Destructor And Vector-Free Thunk Neighbor

The support island contains `0x004a7d00-0x004a7d43` handler/modal list teardown, then an internal gap and a one-instruction thunk:

```text
0x004a7d43-0x004a7d50: cc cc cc cc cc cc cc cc cc cc cc cc cc
0x004a7d50-0x004a7d55: e9 4b 0a 00 00
0x004a7d55-0x004a7d60: cc cc cc cc cc cc cc cc cc cc cc
```

The `0x004a7d50` body is a tail jump to `0x004a87a0` (`FreeHandlerRecordVector`). It is a thunk/helper artifact inside the support island, not a `Tree<EventHandler*>` method and not separate product behavior.

### HandlerFindFunc Predicate Neighbor

Correct half-open range: `0x004a7d60-0x004a7d72` (`0x12` / 18 bytes).

Local bytes:

```text
0x004a7d60-0x004a7d72:
55 8b ec 8b 45 08 8b 00 3b 41 04 0f 94 c0 5d c2 04 00
0x004a7d72-0x004a7d80: cc cc cc cc cc cc cc cc cc cc cc cc cc cc
```

Behavior: compare `*candidate` against `this + 4`, return `true` on equality, consume one explicit argument. This remains [UID:000060] / `HandlerFindFunc`, not the tree class.

### Tree Scalar Deleting Destructor

Correct half-open range: `0x004a7d80-0x004a7dc8` (`0x48` / 72 bytes).

Local bytes:

```text
0x004a7d80-0x004a7dc8:
55 8b ec 56 8b f1 8d 4e 04 c7 06 2c 96 61 00 e8
0c 0a 00 00 8b ce e8 f5 cc 04 00 8b 45 08 a8 01
74 1f a8 04 75 10 56 e8 14 cd 04 00 83 c4 04 8b
c6 5e 5d c2 04 00 6a 10 56 e8 e2 38 f7 ff 83 c4
08 8b c6 5e 5d c2 04 00
```

Instruction-level behavior:

- Reinstalls the `Tree<EventHandler *>::vftable` at `[this]`.
- Calls `FreeHandlerRecordVector` at `0x004a87a0` on `this + 4`.
- Calls `LObject` base cleanup at `0x004f4a90`.
- Reads delete flags from stack.
- If bit `0` is clear, returns `this`.
- If bit `0` is set and bit `2` is clear, calls `0x004f4ac0` / `operator delete` wrapper and returns `this`.
- The alternate bit-2 path is vector-delete/guard-shaped compiler glue, not source-authored tree behavior.

Correct padding after this body is `0x004a7dc8-0x004a7dd0` (`8` bytes of `0xcc`). Existing target/support text that says `0x004a7d80-0x004a7dc7` should be corrected or explicitly marked as an inclusive terminal-byte notation.

### Iterator Scalar Deleting Destructor Neighbor

Correct half-open range: `0x004a7dd0-0x004a7df4` (`0x24` / 36 bytes).

Local bytes:

```text
0x004a7dd0-0x004a7df4:
55 8b ec f6 45 08 01 56 8b f1 c7 06 50 96 61 00
74 0b 6a 0c 56 e8 3c f7 11 00 83 c4 08 8b c6 5e
5d c2 04 00
0x004a7df4-0x004a7e00: cc cc cc cc cc cc cc cc cc cc cc cc
```

This neighbor belongs to [UID:0000FA]. It also means [UID:000146]'s current filename/title `0x004a7cd0-0x004a7df3...` is off by one if interpreted as half-open. The support island's correct executable terminal is `0x004a7df4`, followed by padding before `EventDispatcher` deleting-destructor code at `0x004a7e00`.

## Vtable And Inherited Slot Validation

Local `.rdata` bytes at `0x00619628-0x00619670` match [UID:0003I5]:

```text
0x00619628-0x00619670:
b4 6e 64 00 80 7d 4a 00 10 4b 4f 00 c0 b6 41 00
48 6f 64 00 00 7e 4a 00 10 71 4a 00 e8 6f 64 00
60 7d 4a 00 00 6f 64 00 d0 7d 4a 00 00 00 00 00
00 00 00 00 00 00 00 00 ff ff ff ff ff ff ff ff
ff ff ff ff ff ff ff ff
```

Dword sequence:

| Address | Value | Interpretation |
| --- | --- | --- |
| `0x00619628` | `0x00646eb4` | `Tree<EventHandler *>` complete-object-locator pointer. |
| `0x0061962c` | `0x004a7d80` | `Tree<EventHandler *>::ScalarDeletingDestructor`. |
| `0x00619630` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` / runtime-class accessor slot. |
| `0x00619634` | `0x0041b6c0` | inherited `LObject::VirtualNoop(int, int)` / default no-op slot. |
| `0x00619638` | `0x00646f48` | `EventDispatcher` COL pointer. |
| `0x0061963c` | `0x004a7e00` | `EventDispatcher` scalar deleting destructor. |
| `0x00619640` | `0x004a7110` | `EventDispatcher::OnTimerTick` / timer virtual. |
| `0x00619644` | `0x00646fe8` | `HandlerFindFunc` COL pointer. |
| `0x00619648` | `0x004a7d60` | `HandlerFindFunc::IsMatch`. |
| `0x0061964c` | `0x00646f00` | `TreeItor<EventHandler *>` COL pointer. |
| `0x00619650` | `0x004a7dd0` | `TreeItor<EventHandler *>::ScalarDeletingDestructor`. |
| `0x00619654-0x0061965c` | zero dwords | iterator table reserved/empty slots. |
| `0x00619660-0x0061966c` | `0xffffffff` repeated | iterator sentinel/reserved dwords. |

This resolves the generated/class placeholder slot names on the target page:

- `0x004f4b10` is not Tree-specific code; use inherited `LObject::GetRuntimeClass` / `LObjectRuntimeClassAccessor`.
- `0x0041b6c0` is not Tree-specific code; use inherited `LObject::VirtualNoop(int, int)` / default no-op virtual.
- The tree vtable is source-declared/generated-binary data for `Tree<EventHandler *>`, not a separate C++ source body.

## Behavior And Touched State

`Tree<EventHandler *>` is the embedded handler-record tree wrapper used by `EventDispatcher`:

- The `EventDispatcher` object contains the tree wrapper at dispatcher offset `+0x04`.
- The wrapper layout is best documented as:

```cpp
struct EventHandlerRecordVector {
    EventHandlerRecord *begin;
    EventHandlerRecord *end;
    EventHandlerRecord *capacityEnd;
};

struct EventHandlerTree {
    void *vtable;
    EventHandlerRecordVector records;
};
```

- The vector header begins at tree offset `+0x04`, which is dispatcher offsets `+0x08`, `+0x0c`, and `+0x10`.
- Existing target text saying the class wraps `TreeNodeData` should be replaced or qualified as historical/generated placeholder wording. The best current source-facing storage name is `EventHandlerRecordVector records`, backed by [UID:0001UF], [UID:00022A], [UID:000148], and [UID:00022B].
- The vector element is `EventHandlerRecord`, not an opaque `cls_0x4a87a0` / `TreeNodeData`:
  - `parentIndex`
  - `firstChildIndex`
  - `lastChildIndex`
  - `previousSiblingIndex`
  - `nextSiblingIndex`
  - `EventHandler *handler`
  - `unsigned char isDisabled`
  - `3` bytes padding/reserved
- The ordinary destructor and scalar deleting destructor both destroy only the record-vector storage and then the inherited `LObject` shell. They do not route events, search handlers, or mutate tree link fields directly.
- `EventDispatcher` constructor/destructor/rebuild paths and vtable/data refs install and use this concrete tree wrapper; no current evidence shows non-dispatcher consumers of `Tree<EventHandler *>`.

## Caller And Reachability Evidence

The target's ordinary destructor at `0x004a7cd0` is source-shaped destructor cleanup but remains a raw/no-function-object caveat in IDA:

- Current target/support pages record that `lookup_funcs 0x004a7cd0` resolves inside a broader constructor body rather than a separate IDA-promoted function.
- Wave2/Ghidra records the ordinary destructor with size `25` bytes and one unwind/call cleanup reference at `0x005fda76`.
- Current docs record xrefs from `EventDispatcher` constructor read-only/unwind data.
- Local PE bytes prove the body itself is exact and complete even though IDA does not promote a normal function object at that start.

The scalar deleting destructor at `0x004a7d80` is a modeled vtable-owned body:

- Wave2/IDA record size `72` bytes.
- The only direct data xref is from the `Tree<EventHandler *>` vtable slot at `0x0061962c`.
- It calls `0x004a87a0`, `0x004f4a90`, `0x004f4ac0`, and the guard-check/vector-delete path.
- It has no product-level direct callers because scalar deleting destructors are reached through vtable/delete semantics.

The tree vtable at `0x0061962c` has representative refs recorded by [UID:0003I5] and [UID:000258]:

- `0x004a6aea`, `0x004a6c15`, and `0x004a7e28` in EventDispatcher construction/destruction/reset-family contexts.
- `0x004a7cd6` and `0x004a7d89` from the ordinary and scalar tree destructors themselves.

The broader helper island remains dispatcher-local:

- `0x004a78f0` search helper has five direct dispatcher callers from `SetPaneOrder`, `RemovePaneEntry`, and `RouteEventToHandlers`.
- `0x004a7b10` vector insert has four dispatcher-local callers from constructor/rebuild/relink paths.
- `0x004a7d00` list teardown is called from `EventDispatcher` destruction/cleanup.
- `0x004a87a0` vector free is called from the tree destructor, tree scalar deleting destructor, dispatcher destructor, rebuild cleanup, and constructor cleanup.
- `0x004a82b0-0x004a8795` relink helpers are called by `SetPaneOrder`, `RemovePaneEntry`, constructor, record-vector insert, and rebuild paths.

This is sufficient caller/reachability evidence to keep the class under EventDispatcher source ownership and reject standalone generated source ownership.

## Ownership And Source Placement

Recommended direct owner/emitter: [UID:0000J7] `EventDispatcher`.

Reasoning:

- `EventDispatcher.cpp` already owns the UI event-routing spine, handler registration/order, traversal, modal list, route/child dispatch helpers, handler-record vector support, and `g_pEventDispatcher`.
- The concrete tree specialization is embedded at `EventDispatcher + 0x04` and has no observed non-dispatcher use.
- The adjacent `HandlerFindFunc` one-slot predicate is anonymous-namespace/file-local dispatcher support.
- The `TreeItor<EventHandler *>` stack iterator is constructed by `SetPaneOrder`, `RemovePaneEntry`, `RouteEventToHandlers`, `DispatchToChildren`, and `DispatchToTranslatedChildren`.
- The `EventDispatcherHandlerTreeVtableData` page places `Tree<EventHandler *>`, `EventDispatcher`, `HandlerFindFunc`, and `TreeItor<EventHandler *>` tables contiguously in the Event/Error read-only-data band, but the exact child routes the dispatcher-support subset through [UID:0000J7].
- `EventHandler` is an interface dependency. It is not the owner of the tree storage.
- `LObject` supplies inherited vtable slots and destructor base cleanup. It is not the owner of this concrete specialization.
- `FolderTreePane` proves a second project-local `Tree<T>` family exists, but its concrete specialization is owned by `FolderTreePane.cpp`. That cross-family pattern supports a shared template/header hypothesis, not a standalone `Tree<EventHandler*>.cpp`.

Recommended placement language:

- Keep final emitted/generated route under `NexusTK/ui/core/EventDispatcher.cpp`.
- Document possible declaration/header factoring as either:
  - `EventDispatcher.h` local support declarations for `EventHandlerRecord`, `EventHandlerRecordVector`, `Tree<EventHandler *>`, `TreeItor<EventHandler *>`, and `HandlerFindFunc`; or
  - a reusable project tree-template header used by both EventDispatcher and FolderTreePane, with concrete instantiation/source emission still attached to the owning feature modules.
- Do not create a final standalone `Tree_near_class_EventHandler___.cpp` or `class_Tree_near_class_EventHandler___.cpp` source file.

## Heuristic / Inference Reanalysis And Validation

### Original `Tree<EventHandler*>` Spelling

Best-supported source-facing spelling: `Tree<EventHandler *>` or compact `Tree<EventHandler*>`.

Evidence:

- IDA/vtable table text in [UID:000258] and [UID:0003I5] uses the MSVC-demangled template `Tree<EventHandler*>`.
- The decorated vtable name in the Error/Event aggregate is `??_7?$Tree@PAVEventHandler@@@@6B@`, which means `Tree<class EventHandler *>`.
- The generated filename `Tree_near_class_EventHandler___` and Wave2 `Tree<near class EventHandler *>` preserve Ghidra's memory-model/type-recovery artifact `near_class`; that is not how a plausible original C++ source declaration would have been written.
- FolderTreePane's parallel template pages use source-facing `Tree<FolderTreePane::TreeElem>`, not generated `Tree_struct_...`, when documenting final source shape.

Rejected alternatives:

- `Tree_near_class_EventHandler___` as final source spelling: keep only as documentation filename/generated alias.
- `Tree<near_class_EventHandler_*>`: Ghidra artifact; does not match IDA/MSVC vtable spelling.
- `EventHandlerTree` as final class replacement: useful internal layout alias for docs/draft helper code, but the vtable and generated metadata preserve `Tree<EventHandler *>` as the concrete source-facing type.

Impact: update target/support wording to lead with `Tree<EventHandler *>`, with `Tree_near_class_EventHandler___` explicitly called a generated alias.

### Field/Storage Names

Best-supported layout names:

- `EventHandlerRecordVector records` at `Tree<EventHandler *> + 0x04`.
- `EventHandlerRecordVector::begin`, `end`, `capacityEnd`.
- `EventHandlerRecord` fields:
  - `parentIndex`
  - `firstChildIndex`
  - `lastChildIndex`
  - `previousSiblingIndex`
  - `nextSiblingIndex`
  - `handler`
  - `isDisabled`
  - `reserved[3]`

Evidence:

- [UID:0001UF] and [UID:00022A] resolve the 28-byte record shape and vector layout.
- The target destructor calls `0x004a87a0` on `this + 4`; [UID:000148] resolves that helper as `FreeHandlerRecordVector(EventHandlerRecordVector *records)`.
- `0x004a78f0` search scans vector begin/end at tree offset `+0x04/+0x08`, skips record `+0x18`, and compares record `+0x14` through `HandlerFindFunc`.
- `0x004a7b10`, `0x004a82b0`, `0x004a8350`, and `0x004a8420` all use the same `0x1c` record stride and link fields.

Rejected alternatives:

- `TreeNodeData`: historical class-page placeholder; too generic after B002's support reanalysis.
- `cls_0x4a87a0`: generated class placeholder for vector/free helper ownership; not source-facing.
- `m_nodeData`: acceptable only as a transitional generic label if support docs are not yet updated; less precise than `records`.
- `Motion` base from Ghidra/GhidrAssist: superseded by `LObject` docs and `0x004f4a90` base destructor evidence.

Impact: target should stop saying simply "TreeNodeData storage" and use the resolved event-handler record vector model.

### Helper Names

Best-supported source-facing helper names:

- `FreeHandlerRecordVector(EventHandlerRecordVector *records)` for `0x004a87a0`.
- `AllocateHandlerRecordBuffer(unsigned int count)` for `0x004a8820`.
- `FreeHandlerRecordBuffer(EventHandlerRecord *records, int count)` for `0x004a8890`.
- `InsertHandlerRecord(...)` for `0x004a7b10` as the vector insert helper.
- `InsertFirstChildHandlerRecord`, `InsertHandlerRecordAfterSibling`, `RemoveHandlerRecordAndDisableSubtree`, `CreateEventHandlerListNodeLinks`, `RebindHandlerRecordVectorStorage`, and `ReserveHandlerRecordVectorStorage` for `0x004a82b0-0x004a8795`.
- `HandlerFindFunc::IsMatch` for `0x004a7d60`; `HandlerFindFunc` should remain an anonymous-namespace or file-local predicate identity.

Evidence: existing B002-applied support pages and first-draft C++ blocks on [UID:00022A], [UID:000148], and [UID:00022B].

Rejected alternatives:

- `sub_4A87A0`, `cls_0x4a87a0::~cls_0x4a87a0`, or generic `TreeNodeData::~TreeNodeData` as best source names.
- Generic vector/Deque source owner for these helpers; callers and element layout keep them under EventDispatcher handler-record storage.

Impact: target should name the helper call in the destructor as `FreeHandlerRecordVector`, not `TreeNodeData` destruction.

### EventDispatcher-Local Ownership

Best-supported owner: [UID:0000J7] `EventDispatcher`.

Evidence:

- The vtable refs, constructor/destructor stores, stack iterator construction refs, and vector helper callers are all EventDispatcher handler-tree/list/vector contexts.
- `auto-generated/NexusTK/ui/core/EventDispatcher.cpp` currently emits the accepted EventDispatcher handler-record vector support and marks [UID:0000F8] as an empty emitter marker under the EventDispatcher file route.
- The `EventDispatcher` file page explicitly lists `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` as handler traversal/support types.
- The concrete support island is between EventDispatcher route/search/vector helpers and EventDispatcher destructor/rebuild helpers.

Rejected alternatives:

- Standalone generated `class_Tree_near_class_EventHandler___.cpp`: generated artifact only; no durable source file exists in this checkout.
- Generic `Tree.cpp`: possible future template-header factoring, but no non-dispatcher use of this concrete `Tree<EventHandler *>` specialization was found.
- [UID:00004N] `EventHandler`: dependency type only.
- [UID:000258] Error/Event read-only aggregate: mixed container, not source owner.

Impact: keep target owner/emitter unchanged as [UID:0000J7].

### Template/Header Placement

Best high-probability inference:

- Original source likely had a reusable `Tree<T>` / `TreeItor<T>` template family or local tree helper declarations, because FolderTreePane has a separate concrete `Tree<FolderTreePane::TreeElem>` / `TreeItor<FolderTreePane::TreeElem>` family with similar vtable/inherited-slot patterns.
- For this concrete target, source emission should stay with `EventDispatcher.cpp` until a broader template-header/source pass proves a common header/implementation owner.
- The final header could plausibly be `EventDispatcher.h` with local support types, or a shared tree template header included by both EventDispatcher and FolderTreePane. Current evidence does not prove the original header basename.

Evidence checked:

- FolderTreePane tree-template docs and vtable pages.
- EventDispatcher source/file/class docs.
- Generated output and builder manifest leads.
- Wave2 JSON source_file names.

Why not fully closed:

- No source file or import path proving a common original `Tree.h` / `Tree.hpp` / `Tree.cpp` was found.
- The two concrete specializations differ strongly in element shape and owner feature module.
- Current generated output materializes concrete helper class aliases, not a reliable source-header map.

Impact:

- This remains the main reason not to push completion into the 90s or emit a class declaration shell from [UID:0000F8].
- It does not weaken the EventDispatcher owner/emitter decision for the concrete specialization.

### Raw Destructor Treatment

Best classification:

- `0x004a7cd0-0x004a7ce9` is a real destructor-shaped cleanup body for `Tree<EventHandler *>`, but IDA does not currently promote it as a standalone ordinary function object.
- Treat it as source-declared/generated-binary destructor/EH cleanup support for the concrete tree wrapper, not as independent feature logic.
- Do not create a separate by-memory child only for this destructor unless a future split pass renames/fixes [UID:000146] and wants exact children for every leaf body. The current support island can carry the range as long as it records the exact half-open bounds.

Evidence:

- Local PE bytes prove the complete 25-byte body and padding.
- Wave2/Ghidra records the body with size 25 and destructor name.
- Existing docs record constructor/unwind refs rather than ordinary callers.
- The body's only behavior is vtable restore, record-vector free, and tail-jump to `LObject` cleanup.

Rejected alternatives:

- Treating the range as padding or non-code: impossible because the bytes decode as full destructor logic.
- Treating it as a normal source-authored callable method with direct application callers: no ordinary call evidence.
- Emitting handwritten C++ body from the class page: unsafe because this is destructor glue tied to final template declaration/emission policy.

Impact: document exact raw destructor caveat and keep target C++ blank.

### Scalar Deleting Destructor Code Policy

Best classification:

- `0x004a7d80-0x004a7dc8` is MSVC scalar deleting destructor glue for `Tree<EventHandler *>`.
- The source-level counterpart is the tree destructor plus normal `delete` semantics, not a handwritten source method that project developers likely wrote.
- It is valid reconstructable binary behavior and vtable data, but formal source output should normally express the class/template destructor and let the compiler generate scalar deleting destructor code.

Evidence:

- Vtable slot at `0x0061962c` points to `0x004a7d80`.
- Body repeats ordinary destructor work, then conditionally calls `operator delete` according to delete flags.
- The alternate bit-2 guard path is compiler/vector-delete style and not product logic.
- FolderTreePane's analogous tree scalar deleting destructor page uses the same policy: model destructor behavior and let compiler emit scalar-deleting destructor glue.

Rejected alternatives:

- First-draft source method named `ScalarDeletingDestructor` on the class page: decompiler/generated-shaped, not plausible hand-written mid-2000s source.
- Dropping the behavior entirely: invalid because vtable and destructor sequence are reconstruction-relevant.

Impact: keep target C++ blank; document scalar deleting destructor behavior in target/support pages.

### Generated/Compiler Names

Best-supported replacements:

| Generated/compiler name | Recommended source-facing handling |
| --- | --- |
| `Tree_near_class_EventHandler___` | Documentation/generated alias for `Tree<EventHandler *>`. |
| `Tree<near class EventHandler *>` / `Tree<near_class_EventHandler_*>` | Ghidra artifact; replace in source-quality prose with `Tree<EventHandler *>`. |
| `TreeNodeData` | Replace with `EventHandlerRecordVector records` or qualify as old placeholder. |
| `cls_0x4a87a0` | Replace with `EventHandlerRecordVector` / `FreeHandlerRecordVector` context. |
| `Motion::~Motion` | Replace with `LObject::~LObject` / `LObjectDestructorBody` based on current LObject docs. |
| `sub_4A87A0` | `FreeHandlerRecordVector`. |
| `sub_4F4A90` | `LObject` non-deleting destructor body. |
| `sub_4F4AC0` | operator-delete / memory-manager delete wrapper. |
| `nullsub_18` / `0x0041b6c0` | `LObject::VirtualNoop(int, int)` inherited no-op slot. |
| `sub_4F4B10` / `0x004f4b10` | `LObject::GetRuntimeClass` / runtime-class accessor. |

Impact: these naming decisions are strong enough for target/support docs and generated-source comments, but exact original helper spellings remain below final-audit confidence.

## Rejected Alternatives

- **Standalone generated Tree source file**: rejected. Old manifests and Wave2 JSON expose `Tree_near_class_EventHandler___.cpp` / `class_Tree_near_class_EventHandler___.cpp` as generated artifacts. Direct binary use is EventDispatcher-local.
- **Generic tree source owner now**: rejected for this pass. The FolderTreePane comparison supports a reusable template/header possibility, but no current source path proves a generic implementation file owns this concrete specialization.
- **EventHandler owner**: rejected. `EventHandler` is the element/interface type stored in records; all tree lifecycle and traversal management is dispatcher-owned.
- **LObject owner**: rejected. `LObject` supplies inherited slots and base cleanup only.
- **Read-only Error/Event aggregate owner**: rejected. [UID:000258] is a mixed non-emitting data container; exact child [UID:0003I5] routes dispatcher support to EventDispatcher.
- **TreeNodeData field model**: rejected as stale/less precise. Current helper pages resolve vector/record names.
- **Handwritten `ScalarDeletingDestructor` C++ on the class page**: rejected as compiler glue and not plausible source.
- **No-code because target is not reconstructable**: rejected. The target is reconstructable; the no-code policy is about unsafe class-page source shape, not absence of source behavior.

## Open-Question Closure

| Question | Resolution |
| --- | --- |
| Original source-facing class spelling | Resolved to `Tree<EventHandler *>`; generated `near_class` spelling is an artifact. |
| EventDispatcher-local ownership | Resolved; keep [UID:0000J7] owner/emitter. |
| Embedded storage field/type name | Resolved enough for docs: `EventHandlerRecordVector records` at `+0x04`; `TreeNodeData` should be historical placeholder only. |
| Helper names touched by destructor | Resolved enough for docs: `FreeHandlerRecordVector`, `LObject` destructor body, operator-delete wrapper, inherited LObject runtime/no-op slots. |
| Raw ordinary destructor range | Resolved by PE bytes: half-open `0x004a7cd0-0x004a7ce9`, followed by `0x004a7ce9-0x004a7cf0` padding. |
| Scalar deleting destructor range | Resolved by PE bytes: half-open `0x004a7d80-0x004a7dc8`, followed by `0x004a7dc8-0x004a7dd0` padding. |
| Support island terminal range | Resolved if interpreted half-open: the final iterator scalar deleting destructor ends at `0x004a7df4`; [UID:000146] title/text should be audited from `0x004a7cd0-0x004a7df3` to `0x004a7cd0-0x004a7df4` if the project chooses to normalize half-open filenames. |
| Template/header placement | Partially resolved. High-probability shared `Tree<T>` template/header exists, but exact header basename and common declaration owner are not proven. This caps score and keeps target C++ blank. |
| First-draft C++ | Explicit defer/no-code for the target class page. The item meets the numeric/emitter gate, but the class-page code shape is unsafe until generic template/header factoring is settled. Exact support by-memory helper pages already carry C++ where behavior and source names are strong enough. |

No generic "future work" blocker remains. The only unresolved item is exact original header/template factoring, and this report records the evidence checked and score/C++ impact.

## First-Draft C++ Recommendation / Exact No-Code Proof

Do not insert formal C++ into [UID:0000F8] during the implementation callback.

Reasoning:

- The active gate `(COMPLETION + CONFIDENCE) / 2 > 85` with confirmed `EMITTER_UIDS` is a minimum eligibility gate, not permission to add weak code.
- The target is a class/specialization identity page. Class pages should emit global class-level declarations or `[[CHILDREN]]` structure, not copy child method bodies into the class page.
- The only target-owned executable bodies are destructor/destructor-glue bodies. The ordinary destructor is raw/EH cleanup shaped and not IDA-promoted as a normal function object; the scalar deleting destructor is MSVC compiler glue.
- Emitting a source method called `ScalarDeletingDestructor` would be decompiler-shaped and not plausible original C++.
- Emitting a concrete class shell such as `class Tree<EventHandler *>` is not yet safe because the generic `Tree<T>` declaration/header placement across EventDispatcher and FolderTreePane is not proven. A hand-written concrete specialization shell could conflict with a later reusable `Tree<T>` template model.
- The correct source-level behavior is already represented by exact support pages:
  - [UID:00022A], [UID:000148], and [UID:00022B] have first-draft C++ for record vector/relink/storage helpers.
  - [UID:0001UF] has the layout model.
  - [UID:0003I5] has vtable/data facts.
- Therefore [UID:0000F8] should stay blank and explicitly document why the blank block is intentional. If a marker is desired for special non-emitting emitters, use the validator's existing empty-emitter behavior or a minimal comment only after supervisor policy says to do so.

The report does not provide class-page C++ for insertion. The safest future C++ direction is a coordinated EventDispatcher tree-template pass that declares the reusable `Tree<T>` / `TreeItor<T>` pattern and lets concrete owner files emit only their feature-specific support where appropriate.

## Score Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:0000J7
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000J7
RECONSTRUCTION_CPP CODE: blank
```

Rationale:

- Completion rises because this pass adds local PE byte validation, exact half-open range corrections, inherited vtable slot naming, resolved storage/record-vector naming, generated-name rejection, source-placement reasoning, and first-draft no-code proof.
- Completion should not reach 90+ because the exact reusable `Tree<T>` header/template factoring remains unproven and [UID:000146]'s sparse-island title/range still needs a support cleanup if accepted.
- Confidence rises because the source-facing `Tree<EventHandler *>` spelling, EventDispatcher ownership, vtable slot map, destructor behavior, and touched storage are now directly cross-validated by by-* docs, Wave2 JSON, and local PE bytes.
- Confidence should not reach final-audit levels because `0x004a7cd0` remains a raw/no-function-object destructor body and exact original header placement is not proven.

## Exact Target And Support Implementation Checklist

If this report is accepted, the same-agent implementation callback should update these files. Do not edit coverage reports directly during implementation.

### Target

`by-class/Tree_near_class_EventHandler___.md`

- Change metadata to `COMPLETION:87`, `CONFIDENCE:90`; keep owner/emitter [UID:0000J7] and blank C++.
- Lead with final source-facing name `Tree<EventHandler *>`; retain `Tree_near_class_EventHandler___` as generated alias.
- Replace `TreeNodeData` storage wording with `EventHandlerRecordVector records` at tree offset `+0x04`, with a short historical-placeholder note for `TreeNodeData` / `cls_0x4a87a0`.
- Correct method half-open ranges:
  - ordinary destructor `0x004a7cd0-0x004a7ce9`;
  - scalar deleting destructor `0x004a7d80-0x004a7dc8`.
- Add local PE byte evidence and padding corrections:
  - `0x004a7ce9-0x004a7cf0` padding;
  - `0x004a7dc8-0x004a7dd0` padding.
- Add vtable slot table for `0x00619628-0x00619638`.
- Add inherited slot naming: `0x004f4b10` is `LObject::GetRuntimeClass`; `0x0041b6c0` is `LObject::VirtualNoop(int, int)`.
- Add source-placement section rejecting standalone generated class files, `near_class` spelling, generic Tree source assignment now, EventHandler ownership, LObject ownership, and read-only aggregate ownership.
- Add explicit first-draft C++ no-code proof.
- Replace stale "active 90/90+ code-entry gate" language with current combined-score gate language and target-specific no-code reason.

### Direct Class/Type Support

`by-class/TreeItor_near_class_EventHandler___.md`

- Mirror source-facing spelling policy: `TreeItor<EventHandler *>`, generated alias only for filename/title.
- Correct half-open ranges:
  - ordinary iterator destructor `0x004a7cf0-0x004a7cf7`;
  - iterator scalar deleting destructor `0x004a7dd0-0x004a7df4`.
- Add padding bytes:
  - `0x004a7cf7-0x004a7d00`;
  - `0x004a7df4-0x004a7e00`.
- Keep owner/emitter [UID:0000J7] and blank C++ unless a coordinated iterator-template pass provides safe declaration code.

`by-class/HandlerFindFunc.md`

- No score change required, but add/update a cross-note that `0x004a7d50` is the vector-free tail-jump thunk and not a predicate/tree method if [UID:000146] is updated.
- Keep `HandlerFindFunc` as anonymous-namespace/file-local predicate, not standalone source.

`by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`

- Add/confirm `EventHandlerTree` wrapper shape:
  - `void *vtable`;
  - `EventHandlerRecordVector records`.
- Add a caveat that `TreeNodeData` / `cls_0x4a87a0` is superseded generated wording for this storage.
- Add the target class's destructor relation to `FreeHandlerRecordVector`.

### Direct Memory Support

`by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md`

- Strongly recommended support cleanup:
  - Correct ordinary tree destructor row to `0x004a7cd0-0x004a7ce9`.
  - Correct iterator destructor row to `0x004a7cf0-0x004a7cf7`.
  - Add explicit `0x004a7d50-0x004a7d55` one-instruction thunk to `FreeHandlerRecordVector`.
  - Correct tree scalar deleting destructor row to `0x004a7d80-0x004a7dc8`.
  - Correct iterator scalar deleting destructor row to `0x004a7dd0-0x004a7df4`.
  - Record padding:
    - `0x004a7ce9-0x004a7cf0`;
    - `0x004a7cf7-0x004a7d00`;
    - `0x004a7d43-0x004a7d50`;
    - `0x004a7d55-0x004a7d60`;
    - `0x004a7d72-0x004a7d80`;
    - `0x004a7dc8-0x004a7dd0`;
    - `0x004a7df4-0x004a7e00`.
- If project policy requires filenames to be half-open accurate, rename this support page to `by-memory/0x004a7cd0-0x004a7df4.EventDispatcherHandlerTreeSupport.md` and update all references through validator. If rename is too disruptive for the callback, leave filename in place but explicitly document that the title currently uses an older inclusive-terminal convention and that leaf body half-open ranges are as above.
- Raise this support page only if the callback incorporates the byte/range evidence; suggested score after cleanup: `COMPLETION:87`, `CONFIDENCE:91`.
- Keep C++ blank for this aggregate/sparse island; exact helper children emit where safe.

`by-memory/0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData.md`

- Add local PE dword evidence from this report if desired.
- Clarify inherited LObject slot names for the `Tree<EventHandler *>` vtable.
- No score change required unless the page is materially expanded.

`by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md`

- Add a cross-note that the target's ordinary destructor call at `0x004a7cdc` is in the corrected `0x004a7cd0-0x004a7ce9` body, and scalar deleting destructor call at `0x004a7d8f` is in `0x004a7d80-0x004a7dc8`.
- No score change required.

### Owner/Emitter Support

`by-file/EventDispatcher.md`

- Add current source-quality note for [UID:0000F8]:
  - final source-facing spelling `Tree<EventHandler *>`;
  - generated alias rejection;
  - `EventHandlerRecordVector records` storage;
  - no standalone tree source file;
  - blank target C++ because class-page declaration/template factoring is unsafe now.
- Fix any stale parent score references in linked child evidence (`EventDispatcher` is now `89/85`, not `88/80`).

`by-class/EventDispatcher.md`

- Add/refresh the tree-support row to include corrected target score and exact range caveats.
- Keep target as handler-tree/list/vector infrastructure under EventDispatcher.

### Coverage/Report Text

Do not edit `by-memory/-coverage-report.md` or any coverage report directly in the B implementation callback. Leave the exact rows below in notes/report for supervisor-owned insertion.

## Supervisor-Owned Coverage / Report Text

### `by-class/-coverage-report.md` replacement row for [UID:0000F8]

```markdown
- [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md) : reconstructable : 87% : strong : B008 2026-06-19 source-quality reanalysis resolves the generated alias as concrete `Tree<EventHandler *>` support under [UID:0000J7] `EventDispatcher.cpp`, rejects `near_class`/standalone generated-class/source ownership, replaces stale `TreeNodeData` storage wording with the `EventHandlerRecordVector records` model at tree offset `+0x04`, verifies local PE bytes for the ordinary destructor `0x004a7cd0-0x004a7ce9` and scalar deleting destructor `0x004a7d80-0x004a7dc8`, records the `0x00619628-0x00619638` vtable/COL dwords with inherited `LObject::GetRuntimeClass` and `LObject::VirtualNoop(int,int)` slots, keeps caller/reachability local to EventDispatcher constructor/destructor/rebuild/traversal support, closes raw-destructor and scalar-deleting-destructor code policy as source-declared/generated-binary destructor glue, and keeps formal C++ blank because reusable `Tree<T>` header/template factoring remains unproven and class-page code would be unsafe duplication of exact helper children.
```

### `by-memory/-coverage-report.md` replacement row for [UID:000146] if support cleanup is accepted

```markdown
    - [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) 0x004a7cd0-0x004a7df3 | method-cluster | EventDispatcherHandlerTreeSupport : reconstructable : 87% : strong : B008 2026-06-19 source-quality reanalysis keeps this as an EventDispatcher-local sparse helper island for `Tree<EventHandler *>`, `TreeItor<EventHandler *>`, `HandlerFindFunc`, and handler-list/vector cleanup support; local PE bytes correct the leaf half-open ranges to `0x004a7cd0-0x004a7ce9`, `0x004a7cf0-0x004a7cf7`, `0x004a7d00-0x004a7d43`, `0x004a7d50-0x004a7d55`, `0x004a7d60-0x004a7d72`, `0x004a7d80-0x004a7dc8`, and `0x004a7dd0-0x004a7df4`, with all intervening spans as `0xcc` alignment; the target tree destructor destroys `EventHandlerRecordVector records` through `FreeHandlerRecordVector`, then chains to `LObject` cleanup, the scalar deleting destructor remains compiler delete glue, and final C++ stays blank for the sparse aggregate while exact vector/relink/allocation children carry safe draft code.
```

If the support file is later renamed to half-open `0x004a7cd0-0x004a7df4.EventDispatcherHandlerTreeSupport.md`, the supervisor row should use the renamed link and range instead of the current filename/range above.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [0000F8-EventDispatcherTreeSpecialization-class-source-quality-removed.md](0000F8-EventDispatcherTreeSpecialization-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Exit code: `0`  
`ok` count: `1`  
Important output:

- `ok 0000F8 by-class/Tree_near_class_EventHandler___.md UID header exists`
- dry-run only; no `--apply`

## Report-Only Edit Statement

This pass created only:

- `tools/leaser/Agents/Agent-B008/research/0000F8-EventDispatcherTreeSpecialization-class-source-quality.md`

and updates `tools/leaser/Agents/Agent-B008/notes.md` with a report handoff entry. No by-* documentation, generated files, or coverage reports were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000F8-EventDispatcherTreeSpecialization-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000F8"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000F8-EventDispatcherTreeSpecialization-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0000F8-EventDispatcherTreeSpecialization-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000F8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
