*** UID:0001U1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATIndexVectorNode

## 2026-08-17 Compiler Overlay Disposition

The sixteen-byte `next`/`prev`/four-byte-key/payload shape is exact semantic evidence for the old-MSVC/Dinkumware hash-container list node. The mapped payload type varies by consumer (`wchar_t *`, `DATFile *`, archive-bounds pointers, and other typed values), which directly contradicts a single project-authored `DATIndexVectorNode` declaration. No UDT, RTTI, source symbol, global, or header route exposes this private implementation type.

This page is therefore an ownerless compiler-overlay record with blank formal CPP/H, `RECONSTRUCTABLE:FALSE`, and no emitter. The illustrative declaration and older custom-class statements below are retained as historical field notation only and must not enter reconstructed source. Typed source declares `stdext::hash_map<Key, Value>` and relies on the contemporary standard library to produce the observed private node layout.

## Status

- Entity kind: non-emitting compiler/private-library list-node overlay
- Confidence: strong for observed fields and intrusive-list behavior, medium for final name/header visibility.
- Canonical owner: none
- Parent attachment: none; [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a non-emitting compiler-family index.
- Header/module route: none
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

`DATIndexVectorNode` is the semantic payload overlay for the 16-byte list node used by the DATIndexVector algorithms. Its `key` is always the four-byte value hashed by FNV-1a; `value` is caller-specific and should stay `void*` at this generic level. MiniMap, MonsterImageLib, and DAT manager callers can interpret the payload differently, so narrowing it to one feature type would be incorrect.

[UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) does not define or refine this node layout. That range only copies the `m_listHead` sentinel pointer value into bucket `first`/`last` slots during `ResizeAndFill`; node fields remain proven by insert/remove/find/cleanup behavior.

The accepted [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) first-draft body uses this exact `next`, `prev`, `key`, and `value` source-facing declaration through the [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) class support block; no standalone type score change is required.

## IDA Evidence

IDA MCP `lookup_funcs` confirms the relevant methods as `0x00457100-0x0045730f` (`InsertNode`), `0x00457310-0x004573b3` (private remove/unlink helper), and `0x00457580-0x00457613` (`FindNodeByKey`).

IDA decompilation of `0x00457100` treats the insertion node as an intrusive list node: it reads `*Block` as the next link and `Block[1]` as the previous link, relinks those two fields while moving the node into the selected bucket range, and frees the new node on duplicate-key collapse. During rehash the function recursively reinserts each existing node by passing `node + 0x08` as the key pointer, confirming the key begins at offset `+0x08`.

IDA decompilation of `0x00457310` hashes four bytes beginning at `Block+0x08`, uses `Block[0]` and `Block[1]` as next/prev links, compares the node against bucket first/last pointers, updates neighboring links with `*prev = next` and `next->prev = prev`, decrements the vector count, and frees the 16-byte node allocation.

IDA decompilation of `0x00457580` scans `v6` nodes from the selected bucket, compares `v6[2]` against the requested four-byte key, advances with `v6 = (_DWORD *)*v6`, and returns the matching node or the list sentinel. This verifies `+0x00` as `next`, `+0x04` as `prev`, and `+0x08` as the 32-bit key. The payload at `+0x0c` is not directly consumed by these three helpers, but the 16-byte allocation and caller use support a pointer-sized value slot.

2026-06-14 live IDA MCP rechecked the same helper set. `lookup_funcs` reports `0x00457100` size `0x20f`, `0x00457310` size `0xa3`, and `0x00457580` size `0x93`. `analyze_function 0x00457100` shows FNV-1a hashing of exactly four key bytes, duplicate-key collapse that unlinks/frees the candidate node, bucket relinking through `Block[0]` and `Block[1]`, and rehash reinsertion by passing `node + 0x08` as the key pointer. `analyze_function 0x00457310` hashes `Block+0x08`, updates bucket first/last entries, splices the intrusive links, decrements the count, and frees the node. `analyze_function 0x00457580` scans the selected bucket range, compares `v6[2]` to the key, advances through `*v6`, and returns either the matching node or the sentinel.

## Consumers

- [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) inserts, moves, and duplicate-collapses nodes.
- [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) detaches/frees nodes.
- [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) scans nodes in the selected bucket range.

## Score Rationale

The page is raised to `85/89` because the 16-byte node extent, intrusive `next`/`prev` links, four-byte key offset, FNV-1a key hashing, duplicate-key collapse, removal, lookup, rehash reinsertion, strict owner/emitter route, and payload-slot caveat are all documented with current IDA evidence. Completion and confidence remain below final-source status because the `+0x0c` payload type/name and public-header versus private-source visibility still need caller-focused confirmation.

## Open Questions

- Whether `value` is always a pointer-sized payload or a union of pointer/integer fields in some callers.
- Whether the final name is DAT-specific or a generic index/list node type reused by multiple modules.

## Cross-References

- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md)

## Changes

- 2026-08-17 B008 UID0000IP implementation callback:
  - Reclassified the exact sixteen-byte intrusive node shape as an ownerless compiler/private-library overlay whose mapped payload type is consumer-specific. Raised documentation scores to `93/95`, cleared the stale owner/emitter route, marked the page nonreconstructable as direct source, and preserved all exact layout/behavior evidence with blank formal CPP/H.

- 2026-07-05 B005 implementation callback:
  - No metadata/C++ change. Recorded that the accepted [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) body relies on this concrete 16-byte node declaration through the DATIndexVector class support block.
- 2026-06-24 B001 accepted source-quality implementation:
  - No metadata/C++ change. Added the accepted boundary note that [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) copies the sentinel value into bucket slots and does not define `DATIndexVectorNode` layout. Node field evidence remains the insert/remove/find and list-cleanup paths.
- 2026-06-21 B009 Rule 26 incorporation:
  - No score change. Added the class-level semantic overlay decision: keep `key` as the four-byte FNV-1a input and keep `value` generic because the same DATIndexVector helper serves multiple caller payload types.
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/88`, with correct intrusive-node evidence but completion capped at the old attachment threshold.
  - Changed to: `85/89`.
  - Summary/evidence: live IDA MCP reconfirmed insert/remove/find helper sizes, four-byte FNV-1a key hashing, bucket relinking, duplicate collapse, node free paths, rehash reinsertion through `node+0x08`, lookup compare at `v6[2]`, and the strict DATIndexVector owner/emitter route. C++ remains blank because the `+0x0c` payload declaration and final header/source visibility are still not source-quality.
- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP decompilation on 2026-05-31 verifies the `next`, `prev`, and `key` offsets through insert, remove, and lookup paths; payload type and final header visibility remain below near-final confidence.
- 2026-06-06: Completion changed from `74` to `80`, and `AUTOGEN_PARENT_UID` was set to [UID:00003K][DATIndexVector](by-class/DATIndexVector.md). Confidence remains `88`.
  - Before: the intrusive-node field evidence was documented, but the page remained below the parent-child attachment gate and the manual by-struct row still showed a stale `50%`.
  - After: the page records the parent gate, score rationale, and coverage report sync while preserving the payload-type caveat.
  - Evidence: `0x00457100`, `0x00457310`, and `0x00457580` verify the 16-byte node, `next`/`prev`, and four-byte key behavior; caller-specific payload semantics remain open.
