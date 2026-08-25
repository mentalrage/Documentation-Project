*** UID:0001UF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// EventDispatcher Tree<EventHandler *> concrete-layout evidence marker.
// UID0004YK Tree.h owns TreeNode, std::vector-backed Tree, and TreeItor source.
// UID00022A retains only dispatcher-specific EventHandlerListNode behavior.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EventDispatcher Handler Tree Layouts

## Current Accepted UID0004YK Generic Layout Mapping

The former EventHandlerRecord is TreeNode<EventHandler *>: five links at +0x00 through +0x10, data at +0x14, disabled at +0x18, and three implicit padding bytes for a 0x1c stride. The former EventHandlerRecordVector is the observed 12-byte std::vector representation, and EventHandlerTree is Tree<EventHandler *> with its LObject-derived vptr plus vector for 0x10 bytes. EventHandlerIterator is TreeItor<EventHandler *> at 0x0c bytes. These old structure names remain useful IDA analysis views but no longer emit duplicate authored source.

## Status

- Confidence: strong for observed binary offsets, concrete helper provenance, and generic source mapping.
- Type category: concrete analysis layouts for generic Tree types plus one dispatcher-local list node.
- Generic source owner: [UID:0004YK][Tree](by-file/Tree.md); concrete evidence/consumer owner: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
- Related memory: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- Assignment gate: child `86/90`, direct parent `92/89`; strict gate clears through the EventDispatcher source file.

## Historical Superseded UID000090 Declaration Versus Implementation Ownership - 2026-07-31

- `EventDispatcher.h`, emitted by [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), is the one-definition declaration owner for `EventHandlerRecord`, `EventHandlerRecordVector`, and `EventHandlerTree` because the class contains the tree by value.
- [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md) is the implementation owner for iterator/list-node declarations and exact relink/helper bodies only. It includes and consumes `EventDispatcher.h`; it no longer repeats the three header-owned declarations.
- Exact layouts remain unchanged: record `0x1c` bytes with `isDisabled +0x18` and source-significant `reserved[3]`, vector header 12 bytes, tree 16 bytes, iterator 12 bytes, and list node 12 bytes.
- Historical claims that UID00022A emitted every declaration are retained only as superseded provenance. Duplicate CPP-local records, a PCH-only definition, and a forward-declared by-value tree are rejected.

## EventHandlerListNode

IDA MCP decompilation of `0x004a8680` confirms a 12-byte doubly linked sentinel/node shape allocated for the dispatcher handler/modal list:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | `next` | List traversal uses `node->next` and sentinel self-linking. |
| `0x04` | `prev` | Insert/remove paths maintain tail and previous links. |
| `0x08` | payload/handler value | The allocator reserves 12 bytes; list teardown at `0x004a7d00` frees each node through the sentinel chain. Final payload meaning remains tied to modal/list users. |

Active generated code allocates these nodes with `operator_new(0x0c)`.

## TreeNode<EventHandler *> Binary Layout

IDA MCP decompilation of `0x004a78f0`, `0x004a7b10`, `0x004a7e70`, `0x004a82b0`, and `0x004a8350` confirms a 28-byte handler-record vector. Records are copied as 16 + 8 + 4 bytes and all vector counts/offsets divide byte spans by 28:

| Offset | Source-facing field | Type | Evidence |
| --- | --- | --- | --- |
| `0x00` | `parentIndex` | `int` | `0x004a82b0` writes the parent/current iterator index into new child records; `0x004a8420` checks this before updating parent child endpoints. |
| `0x04` | `firstChildIndex` | `int` | `0x004a82b0` sets parent `+0x04` to the new child when creating the first child; `0x004a8420` and `0x004a7e70` enumerate descendants from `+0x04`. |
| `0x08` | `lastChildIndex` | `int` | `0x004a82b0` sets parent `+0x08` to the new child; `0x004a8350` updates parent `+0x08` when appending after the current tail; dispatch helpers start from `+0x08` to route reverse child order. |
| `0x0c` | `previousSiblingIndex` | `int` | Dispatch helpers advance from the last child through `+0x0c`; `0x004a8420` treats it as the back-link when unlinking a record. |
| `0x10` | `nextSiblingIndex` | `int` | `0x004a8350` moves the current record's `+0x10` continuation to the new record; `0x004a8420` and `0x004a7e70` follow it while enumerating the forward child list. |
| `0x14` | `data` | `EventHandler *` | `0x004a78f0` passes `record + 0x14` into `HandlerFindFunc::IsMatch`; dispatch helpers load this field before virtual handler calls. Historical analysis called it `handler`. |
| `0x18` | `disabled` | `unsigned char` | `0x004a78f0`, `0x004a7570`, and `0x004a7690` skip nonzero records; `0x004a8420` marks removed subtrees by writing `1`. Historical analysis called it `isDisabled`. |
| `0x19..0x1b` | padding | 3 bytes | Record stride is `0x1c`; vector copy helpers copy the tail dword at `+0x18`. |

## Current Tree<EventHandler *> Binary Layout

The embedded object is `Tree<EventHandler *>`: an `LObject`-derived vptr at `+0x00` and direct `std::vector<TreeNode<EventHandler *> >` storage at `+0x04`, for a total size of `0x10`. Generated stack iterators hold a `Tree<EventHandler *> *` and node index. Forward maintenance walks `firstChildIndex -> nextSiblingIndex`; dispatch begins at `lastChildIndex` and walks `previousSiblingIndex`.

## Historical Superseded EventHandlerTree Wrapper Draft

Generated stack iterators hold a tree pointer and index. Helper code casts the tree to a wrapper with a node pointer:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | unknown/tree header | Generated code does not resolve this field yet. |
| `0x04` | `nodes` | `GetEventHandlerTreeNode` indexes through `reinterpret_cast<EventHandlerTree*>(iterator.tree)->nodes[index]`. |

The [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) constructor installs `Tree<EventHandler*>::vftable` on the embedded tree at dispatcher offset `0x4`.

2026-06-17 B002 resolves the source-facing tree/vector shape for first-draft C++ as:

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

The vector header is at `EventHandlerTree + 0x04`, corresponding to dispatcher offsets `+0x08/+0x0c/+0x10` when the embedded tree begins at `EventDispatcher + 0x04`. Forward maintenance/rebuild walks `firstChildIndex -> nextSiblingIndex`, while event dispatch begins at `lastChildIndex` and walks `previousSiblingIndex`; this resolves the earlier apparent conflict between rebuild and dispatch traversal order.

2026-06-21 B008 revalidates this wrapper specifically for [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md): the source-facing storage name is `EventHandlerRecordVector records`, and old generated wording such as `TreeNodeData` or `cls_0x4a87a0` should be treated as superseded placeholder text for this dispatcher tree storage. The target's ordinary destructor at `0x004a7cd0-0x004a7ce9` and scalar deleting destructor at `0x004a7d80-0x004a7dc8` both destroy `records` via [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md) before chaining into `LObject` cleanup / compiler delete glue.

2026-06-21 B012 class-level reanalysis for [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) keeps these structure names as the current source-facing model for `EventDispatcher.cpp`: `EventHandlerRecord`, `EventHandlerRecordVector`, `EventHandlerTree`, `EventHandlerIterator`, and `EventHandlerListNode`. The old generated `link*`, `TreeNodeData`, `near_class`, `cls_0x4a87a0`, and raw `sub_*` labels are historical trace labels only; draft child C++ should use the resolved field names here unless a later source-quality pass proves original spellings.

The 2026-06-20 B001 aggregate audit ties the layout entries back to the exact EventDispatcher helpers that consume them:

- `0x004a78f0-0x004a7979` / [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md) scans enabled records, uses `handler` at `+0x14`, skips `isDisabled` at `+0x18`, and writes the iterator index.
- `0x004a7980-0x004a7aef` assigns/copies handler-record vectors and should be represented through this same vector header shape.
- `0x004a7af0-0x004a7b0a` creates the 12-byte handler/modal list nodes whose teardown is documented by [UID:000147][0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md).
- `0x004a7b10-0x004a7c2a` / [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md) grows and inserts `EventHandlerRecord` entries using the `0x1c` stride and begin/end/capacity header.
- `0x004a7d60-0x004a7d72` is the `HandlerFindFunc::IsMatch` predicate body used by the search helper; it compares the candidate handler value against the stored expected handler slot.
- `0x004a7e70-0x004a82a9` rebuilds traversal order from the resolved `firstChildIndex`/`nextSiblingIndex` model, while dispatch helpers walk from `lastChildIndex` through `previousSiblingIndex`.

## EventHandlerIterator

Stack iterator records observed in dispatcher traversal:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | vtable | Generated code writes `TreeItor<EventHandler*>::vftable`. |
| `0x04` | tree | Passed through recursive traversal. |
| `0x08` | index | Current tree-node index. |

## Historical Binary Evidence Under Superseded Event Record Labels

The dated observations below use `EventHandlerRecord`, `handler`, `isDisabled`, and custom vector/tree spellings as analysis labels. Current source mapping is `TreeNode<EventHandler *>`, `data`, `disabled`, direct `std::vector` storage, and `Tree<EventHandler *>` from UID0004YK.

- 2026-06-11 IDA MCP live refresh confirms the active helper boundaries and caller sets: `0x004a78f0-0x004a7979` has five EventDispatcher callers, `0x004a7b10-0x004a7c2a` has four constructor/relink/vector callers, `0x004a7d00-0x004a7d43` is reached from destructor/cleanup paths, `0x004a87a0-0x004a8810` has six tree/destructor/rebuild cleanup callers, and the allocation helpers at `0x004a8820-0x004a88d2` remain inside the same vector-management family.
- 2026-06-11 disassembly reconfirms the handler-record stride and fields: `0x004a78f0` uses the `0x92492493` division-by-28 reciprocal, skips byte `+0x18`, passes `record + 0x14` to the predicate, and advances by `0x1c`; `0x004a7b10`, `0x004a82b0`, and `0x004a8350` repeat the same `0x1c` vector stride and copy/update the record tail through `+0x18`.
- 2026-06-11 disassembly reconfirms list-node shape: `0x004a8680` calls `operator new(0x0c)` and `0x004a7d00` frees 12-byte nodes while resetting the circular list wrapper.
- 2026-06-11 allocation-helper refresh confirms the record-vector count guard at `0x09249249` and allocation calls in `0x004a8820`, keeping the 28-byte element size as a binary invariant rather than a generated-source guess.
- 2026-06-11 padding/boundary audit confirms exact helper endpoints for the relink/allocation/free band from `0x004a82b0` through `0x004a88d2`; earlier non-`0xcc` gaps before `0x004a7cd0` are already covered by dispatcher route/rebuild support and do not extend this layout page's exact helper rows.
- 2026-05-31 IDA MCP `lookup_funcs` reports `0x004a78f0` size `0x89`, `0x004a7b10` size `0x11a`, `0x004a7d00` size `0x43`, and `0x004a87a0` size `0x70`.
- 2026-05-31 IDA MCP decompilation confirms `0x004a7b10` computes vector counts and insert offsets by dividing byte spans by `28`, copies new records as 28 bytes, and rebinds begin/end/capacity pointers.
- 2026-05-31 IDA MCP decompilation confirms `0x004a78f0` scans enabled records, skips byte `+0x18`, passes `record + 0x14` to `HandlerFindFunc::IsMatch`, and stores the matched index into iterator offset `+0x08`.
- 2026-05-31 IDA MCP disassembly confirms `0x004a7d60` compares `*arg` against `this[1]`, validating the `HandlerFindFunc` stored expected-handler slot at offset `+0x04`.
- 2026-05-31 IDA MCP decompilation confirms `0x004a8680` allocates 12-byte sentinel/list nodes and `0x004a7d00` resets `next`/`prev`, clears the wrapper count, walks the old chain, and frees each node plus the sentinel.
- 2026-05-31 IDA MCP decompilation confirms `0x004a87a0` frees and clears the 28-byte handler-record vector and is called from tree, dispatcher destructor, and traversal-rebuild cleanup paths.

## Caveats

- These layouts are evidence and route support, not duplicate owning C++ declarations. UID0004YK emits TreeNode/Tree/TreeItor; vector helper pages are compiler-covered, while UID00022A retains only dispatcher-specific list-node evidence.
- `Tree<EventHandler*>` and `TreeItor<EventHandler*>` are generic template instantiations from `Tree.h`; `HandlerFindFunc` remains dispatcher-local source.

### Historical Superseded Generated-Route Observations

- IDA MCP recheck on 2026-05-25 confirms `0x004a7d00` destroys the handler/modal list wrapper and `0x004a87a0` frees the handler-record vector storage. Active generated helper class outputs still omit those bodies, so keep the exact by-memory docs as source-placement evidence.
- 2026-05-26 recheck: active `simroot_v2` still emits the template/predicate helpers as standalone class files and still leaves `sub_4A78F0` external from `class_EventDispatcher.cpp`. Treat these layouts as dispatcher-local infrastructure until generated ownership is refreshed.
- 2026-06-17 B002 recheck: the old `+0x04 first child or next child` and `+0x08 sibling/related` language is superseded by the first/last child and previous/next sibling model above. Do not preserve generic `link*` names for first-draft C++; use the resolved source-facing fields while reserving exact original spelling for final audit.

## Assignment Decision

This page remains routed through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) as concrete layout/evidence inventory because it also spans the dispatcher-local list wrapper and predicate context. That route does not transfer generic declaration ownership: [UID:0004YK][Tree](by-file/Tree.md) emits TreeNode/Tree/TreeItor, while the narrower vector/relink pages are compiler-instantiation views rather than standalone source owners.

## Score Rationale

- Completion is `86` because the page now has direct-parent assignment, exact list-node and handler-record field tables, iterator/predicate offsets, live helper-boundary/caller evidence, sibling exact memory cross-references, a clear ownership decision, and an accepted `[[CHILDREN]]` evidence-route marker.
- Confidence is `90` because current IDA evidence independently confirms the numeric invariants (`0x0c` list nodes, `0x1c` records, `+0x14` handler, `+0x18` disabled byte, `0x09249249` max count) and keeps the helper family under EventDispatcher callers.
- Generic Tree and vector behavior is emitted only by UID0004YK `Tree.h` and compiler/library lowering. Exact by-memory pages retain binary evidence; UID00022A emits only dispatcher-specific list behavior where appropriate. This page remains a layout evidence marker to avoid duplicate declarations.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:00004N][EventHandler](by-class/EventHandler.md)
- [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md)
- [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md)
- [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md)
- [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md)
- [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md)
- [UID:000147][0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md)
- [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md)

## Changes

- 2026-06-30 B010 accepted EventDispatcher implementation callback:
  - Before: `COMPLETION:85`, `CONFIDENCE:89`, with layout evidence but no formal route marker.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`; owner/emitter unchanged as [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and formal `RECONSTRUCTION_CPP` now emits an accepted layout evidence marker with `[[CHILDREN]]`.
  - Evidence: accepted B010 report used the resolved handler-record/vector/tree/list layout evidence while routing concrete declarations to UID00022A and exact helper bodies to EventDispatcher child pages.
- 2026-05-31:
  - What existed before: the page was scored `0/0`, left reconstructable blank, and described the handler records mainly as generated-code views.
  - Changed to: scored `76/86`, marked reconstructable, and updated with IDA MCP-confirmed 12-byte list-node and 28-byte handler-record evidence.
  - Summary/evidence: IDA MCP `lookup_funcs`, `decompile`, `disasm`, and xref checks on `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, `0x004a7d60`, `0x004a8680`, and `0x004a87a0` confirm the binary layout mechanics and keep the structures under EventDispatcher helper ownership.
- 2026-06-11 A004 normal task:
  - What existed before: the page was still `76/86`, had no `AUTOGEN_PARENT_UID`, and relied mostly on the earlier 2026-05-31 layout audit.
  - Changed to: raised to `85/89`, assigned to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), added strict-gate status, refreshed live IDA MCP helper-boundary/caller evidence, and documented why the by-file parent owns the full layout family.
  - Summary/evidence: IDA MCP rechecked handler search, vector insert, list destructor, relink, node allocation, vector free, and vector allocation helpers from `0x004a78f0` through `0x004a88d2`; the pass reconfirmed 12-byte list nodes, 28-byte records, handler/disabled offsets, count guards, and dispatcher-local ownership. Formal C++ remained blank in that earlier pass; the later 2026-06-17 and 2026-06-20 notes clarify that `95+` is final-audit quality, not a first-draft blocker.
- 2026-06-17 B002 source-quality execution:
  - What existed before: the handler-record table still carried ambiguous names for several index fields and the score rationale treated the final-audit score target as a first-draft blocker.
  - Changed to: replaced the handler-record table with source-facing `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `handler`, `isDisabled`, and padding fields; added the vector/tree draft shape and clarified that `95+` is final-audit quality, not a first-draft blocker.
  - Summary/evidence: B002 reviewed EventDispatcher target/support docs, exported decompilation, direct PE refs, and padding spans for the relink/free/allocation helper cluster; the report resolves the apparent traversal-direction conflict and supports first-draft C++ in the emitting by-memory helpers.
- 2026-06-20 B001 EventDispatcher aggregate source-quality execution:
  - Score unchanged at `85/89`.
  - Summary/evidence: B001's [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) report connected the layout to the exact search, assignment/copy, list-node create, vector-insert, predicate, list-destructor, and traversal-rebuild helper ranges. The layout page now records those helper consumers so future C++ emission can use the resolved record/list/tree fields instead of generic generated names.
- 2026-06-21 Rule 26 incorporation of B008 source-quality report:
  - Score unchanged at `85/89`.
  - Summary/evidence: B008's Tree specialization pass independently revalidated the `EventHandlerTree` wrapper as `void *vtable` plus `EventHandlerRecordVector records`, superseding `TreeNodeData`/`cls_0x4a87a0` wording for this storage and tying the tree destructor pair directly to `FreeHandlerRecordVector`.
- 2026-06-21 B012 EventDispatcher class source-quality sync:
  - Score unchanged at `85/89`.
  - Summary/evidence: B012's [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) reanalysis confirms these layout names are the dispatcher source-family model to use for child C++ and documentation, while preserving old generated names only as historical trace labels.
