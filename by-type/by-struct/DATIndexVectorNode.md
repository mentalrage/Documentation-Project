*** UID:0001U1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00003K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATIndexVectorNode

## Status

- Entity kind: support struct
- Confidence: strong for observed fields and intrusive-list behavior, medium for final name/header visibility.
- Proposed owner: [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- Parent attachment: attached to [UID:00003K][DATIndexVector](by-class/DATIndexVector.md), which is scored `82/80`; this node page is now at the `80/80` child attachment gate.
- Proposed header/module: [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- Evidence basis: IDA MCP lookup/decompile checks on 2026-05-31 for `0x00457100`, `0x00457310`, and `0x00457580`; generated `simroot_v2` output is retained only as context.

## Layout Hypothesis

```cpp
struct DATIndexVectorNode {
    DATIndexVectorNode* next; // +0x00
    DATIndexVectorNode* prev; // +0x04
    int32_t key;              // +0x08
    void* value;              // +0x0c
};
```

The node is intrusive: insert, remove, and lookup manipulate the same `next`/`prev` links used by the shared list sentinel. The key is hashed as exactly four bytes with FNV-1a.

## IDA Evidence

IDA MCP `lookup_funcs` confirms the relevant methods as `0x00457100-0x0045730f` (`InsertNode`), `0x00457310-0x004573b3` (private remove/unlink helper), and `0x00457580-0x00457613` (`FindNodeByKey`).

IDA decompilation of `0x00457100` treats the insertion node as an intrusive list node: it reads `*Block` as the next link and `Block[1]` as the previous link, relinks those two fields while moving the node into the selected bucket range, and frees the new node on duplicate-key collapse. During rehash the function recursively reinserts each existing node by passing `node + 0x08` as the key pointer, confirming the key begins at offset `+0x08`.

IDA decompilation of `0x00457310` hashes four bytes beginning at `Block+0x08`, uses `Block[0]` and `Block[1]` as next/prev links, compares the node against bucket first/last pointers, updates neighboring links with `*prev = next` and `next->prev = prev`, decrements the vector count, and frees the 16-byte node allocation.

IDA decompilation of `0x00457580` scans `v6` nodes from the selected bucket, compares `v6[2]` against the requested four-byte key, advances with `v6 = (_DWORD *)*v6`, and returns the matching node or the list sentinel. This verifies `+0x00` as `next`, `+0x04` as `prev`, and `+0x08` as the 32-bit key. The payload at `+0x0c` is not directly consumed by these three helpers, but the 16-byte allocation and caller use support a pointer-sized value slot.

## Consumers

- [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) inserts, moves, and duplicate-collapses nodes.
- [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) detaches/frees nodes.
- [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) scans nodes in the selected bucket range.

## Score Rationale

The page is scored at the attachment threshold because the 16-byte allocation, intrusive `next`/`prev` links, four-byte key offset, key hashing, duplicate-key collapse, removal, and lookup behavior are documented. Completion remains lower than the companion bucket page because the payload slot at `+0x0c` still needs caller-focused naming/type confirmation.

## Open Questions

- Whether `value` is always a pointer-sized payload or a union of pointer/integer fields in some callers.
- Whether the final name is DAT-specific or a generic index/list node type reused by multiple modules.

## Cross-References

- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md)

## Changes

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP decompilation on 2026-05-31 verifies the `next`, `prev`, and `key` offsets through insert, remove, and lookup paths; payload type and final header visibility remain below near-final confidence.
- 2026-06-06: Completion changed from `74` to `80`, and `AUTOGEN_PARENT_UID` was set to [UID:00003K][DATIndexVector](by-class/DATIndexVector.md). Confidence remains `88`.
  - Before: the intrusive-node field evidence was documented, but the page remained below the parent-child attachment gate and the manual by-struct row still showed a stale `50%`.
  - After: the page records the parent gate, score rationale, and coverage report sync while preserving the payload-type caveat.
  - Evidence: `0x00457100`, `0x00457310`, and `0x00457580` verify the 16-byte node, `next`/`prev`, and four-byte key behavior; caller-specific payload semantics remain open.
