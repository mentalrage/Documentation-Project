*** UID:0001U0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATIndexVectorBucket

## Status

- Entity kind: support struct
- Confidence: strong for observed fields and bucket-table behavior, medium for final name/header visibility.
- Proposed owner: [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- Proposed header/module: [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- Evidence basis: IDA MCP lookup/decompile checks on 2026-05-31 for `0x00457100`, `0x00457310`, and `0x00457580`; generated `simroot_v2` output is retained only as context.

## Layout Hypothesis

```cpp
struct DATIndexVectorBucket {
    DATIndexVectorNode* first; // +0x00
    DATIndexVectorNode* last;  // +0x04
};
```

Each bucket stores the first and last node in a bucket-owned contiguous range inside a single intrusive list. Empty buckets point at the list sentinel.

## IDA Evidence

IDA MCP `lookup_funcs` confirms the relevant methods as `0x00457100-0x0045730f` (`InsertNode`), `0x00457310-0x004573b3` (private remove/unlink helper), and `0x00457580-0x00457613` (`FindNodeByKey`).

IDA decompilation of `0x00457100` selects a bucket with an FNV-1a hash masked by the vector field at `this+0x18`, then reads the bucket table pointer at `this+0x0c`. It accesses the selected bucket as `bucketTable + 8 * bucketIndex`, with the first pointer at `+0x00` and the last pointer at `+0x04`. Empty buckets are initialized by writing the list sentinel from `this+0x04` into both fields.

IDA decompilation of `0x00457310` repairs these same two bucket fields when removing a node: if the removed node is both first and last, both fields are reset to the sentinel; if it is only last, the last field becomes `node->prev`; if it is only first, the first field becomes `node->next`.

IDA decompilation of `0x00457580` starts lookup from the bucket first pointer and computes the scan end from the bucket last pointer: if `last` is the sentinel, the sentinel is the end; otherwise the loop stops at `last->next`. That confirms the bucket does not own a separate node count, key, or hash value.

## Consumers

- [UID:0000XS][0x00457100-0x0045730e.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730e.DATIndexVectorInsertNode.md) updates `first` and `last` while inserting or moving nodes.
- [UID:0000XT][0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper.md) repairs boundary links when a bucket's first or last node is removed.
- [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) scans from `first` through `last->next`.

## Open Questions

- Whether the final bucket table was declared as a private nested struct, a typedef, or a template implementation detail.
- Whether the name should remain DAT-specific after broader caller review.

## Cross-References

- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)

## Changes

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP decompilation on 2026-05-31 verifies the two-pointer bucket shape through insert, remove, and lookup paths; final header visibility/name remains below near-final confidence.
