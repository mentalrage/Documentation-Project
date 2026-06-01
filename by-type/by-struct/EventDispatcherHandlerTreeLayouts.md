*** UID:0001UF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EventDispatcher Handler Tree Layouts

## Status

- Confidence: strong for observed binary offsets and helper ownership; medium-high for final source-facing type names.
- Type category: event-dispatcher helper structures.
- Likely owner: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related memory: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## EventHandlerListNode

IDA MCP decompilation of `0x004a8680` confirms a 12-byte doubly linked sentinel/node shape allocated for the dispatcher handler/modal list:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | `next` | List traversal uses `node->next` and sentinel self-linking. |
| `0x04` | `prev` | Insert/remove paths maintain tail and previous links. |
| `0x08` | payload/handler value | The allocator reserves 12 bytes; list teardown at `0x004a7d00` frees each node through the sentinel chain. Final payload meaning remains tied to modal/list users. |

Active generated code allocates these nodes with `operator_new(0x0c)`.

## EventHandlerTreeNode

IDA MCP decompilation of `0x004a78f0`, `0x004a7b10`, `0x004a7e70`, `0x004a82b0`, and `0x004a8350` confirms a 28-byte handler-record vector. Records are copied as 16 + 8 + 4 bytes and all vector counts/offsets divide byte spans by 28:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | parent/record index | Insert/relink helpers copy it and update it when remapping traversal order. |
| `0x04` | first child or next child index | `0x004a7e70` follows this field while expanding child records; final semantic name remains open. |
| `0x08` | sibling/related index | Relink helpers write this when appending child records. |
| `0x0c` | parent/previous index | `0x004a8350` copies the source record index here for new relinked records. |
| `0x10` | next/sibling continuation index | `0x004a8350` reads and updates this field while threading relinked children. |
| `0x14` | `handler` | `0x004a78f0` passes `record + 0x14` into `HandlerFindFunc::IsMatch`; the predicate compares the pointed value to its stored expected handler. |
| `0x18` | `isDisabled` | `0x004a78f0` skips records when the byte at `record + 0x18` is nonzero. |

## EventHandlerTree

Generated stack iterators hold a tree pointer and index. Helper code casts the tree to a wrapper with a node pointer:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | unknown/tree header | Generated code does not resolve this field yet. |
| `0x04` | `nodes` | `GetEventHandlerTreeNode` indexes through `reinterpret_cast<EventHandlerTree*>(iterator.tree)->nodes[index]`. |

The [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) constructor installs `Tree<EventHandler*>::vftable` on the embedded tree at dispatcher offset `0x4`.

## EventHandlerIterator

Stack iterator records observed in dispatcher traversal:

| Offset | Candidate field | Evidence |
| --- | --- | --- |
| `0x00` | vtable | Generated code writes `TreeItor<EventHandler*>::vftable`. |
| `0x04` | tree | Passed through recursive traversal. |
| `0x08` | index | Current tree-node index. |

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` reports `0x004a78f0` size `0x89`, `0x004a7b10` size `0x11a`, `0x004a7d00` size `0x43`, and `0x004a87a0` size `0x70`.
- 2026-05-31 IDA MCP decompilation confirms `0x004a7b10` computes vector counts and insert offsets by dividing byte spans by `28`, copies new records as 28 bytes, and rebinds begin/end/capacity pointers.
- 2026-05-31 IDA MCP decompilation confirms `0x004a78f0` scans enabled records, skips byte `+0x18`, passes `record + 0x14` to `HandlerFindFunc::IsMatch`, and stores the matched index into iterator offset `+0x08`.
- 2026-05-31 IDA MCP disassembly confirms `0x004a7d60` compares `*arg` against `this[1]`, validating the `HandlerFindFunc` stored expected-handler slot at offset `+0x04`.
- 2026-05-31 IDA MCP decompilation confirms `0x004a8680` allocates 12-byte sentinel/list nodes and `0x004a7d00` resets `next`/`prev`, clears the wrapper count, walks the old chain, and frees each node plus the sentinel.
- 2026-05-31 IDA MCP decompilation confirms `0x004a87a0` frees and clears the 28-byte handler-record vector and is called from tree, dispatcher destructor, and traversal-rebuild cleanup paths.

## Caveats

- These layouts are generated-code views, not final C++ declarations.
- `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` are support types for event routing; do not migrate them away from UI event infrastructure unless later caller evidence shows broad generic use.
- IDA MCP recheck on 2026-05-25 confirms `0x004a7d00` destroys the handler/modal list wrapper and `0x004a87a0` frees the handler-record vector storage. Active generated helper class outputs still omit those bodies, so keep the exact by-memory docs as source-placement evidence.
- 2026-05-26 recheck: active `simroot_v2` still emits the template/predicate helpers as standalone class files and still leaves `sub_4A78F0` external from `class_EventDispatcher.cpp`. Treat these layouts as dispatcher-local infrastructure until generated ownership is refreshed.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:00004N][EventHandler](by-class/EventHandler.md)
- [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md)
- [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md)
- [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md)
- [UID:000144][0x004a78f0-0x004a7978.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7978.EventDispatcherFindHandlerIterator.md)
- [UID:000145][0x004a7b10-0x004a7c29.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c29.EventDispatcherHandlerRecordVectorInsert.md)
- [UID:000147][0x004a7d00-0x004a7d42.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d42.EventDispatcherHandlerListDestructor.md)
- [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md)

## Changes

- 2026-05-31:
  - What existed before: the page was scored `0/0`, left reconstructable blank, and described the handler records mainly as generated-code views.
  - Changed to: scored `76/86`, marked reconstructable, and updated with IDA MCP-confirmed 12-byte list-node and 28-byte handler-record evidence.
  - Summary/evidence: IDA MCP `lookup_funcs`, `decompile`, `disasm`, and xref checks on `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, `0x004a7d60`, `0x004a8680`, and `0x004a87a0` confirm the binary layout mechanics and keep the structures under EventDispatcher helper ownership.
