*** UID:0001V0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ListNode

## Status

- Entity kind: support struct
- Confidence: strong for observed fields and allocation size, medium for final name/header visibility.
- Proposed owner: [UID:0000KR][LinkedList](by-file/LinkedList.md)
- Proposed header/module: `util/LinkedList.h` or private declarations in [UID:0000KR][LinkedList](by-file/LinkedList.md)
- Evidence basis: IDA MCP lookup/decompilation/caller/callee checks on 2026-05-25 and 2026-05-31. `simroot_v2` recovered files remain useful search leads but are not authority.

## Layout Hypothesis

```cpp
struct ListNode {
    ListNode* next; // +0x00
    ListNode* prev; // +0x04
    int value0;     // +0x08
    int value1;     // +0x0c
};
```

`CreateListNode` allocates exactly 16 bytes. When called with `next == 0`, it self-links `next` and `prev`, producing the sentinel node used by several owning list states. `CreateListNodeWithPayload` copies two caller-supplied words into `value0` and `value1`.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_457550` size `0x2d` and `sub_4570E0` size `0x20`. Current decompile of `sub_457550` calls `operator new(0x10)`, writes `next/prev` from the caller when `next` is non-null, and self-links the node when `next` is null. Current decompile of `sub_4570E0` calls `sub_457550(next, prev)` and then writes the two payload dwords into `result[2]` and `result[3]`.

This node layout is reconstructable source-level container support. Parent attachment and C++ emission remain blank because final original header/type naming and all typed wrapper payload meanings are not yet at the 95+ final-code threshold.

## Consumers

- [UID:0000XW][0x00457550-0x0045757d.CreateListNode](by-memory/0x00457550-0x0045757d.CreateListNode.md) allocates and initializes sentinel or linked nodes.
- [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md) copies the two-word payload into the value slots.
- [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) frees every node in a sentinel-owned list.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), and [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) use this node family for unrelated payload lists.

## Open Questions

- Whether the original type was named, nested, or template-generated.
- Whether final source should split typed wrappers over the two payload words for frame scheduling, minimap hashes, and image-lib archive bounds.

## Cross-References

- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP reverified the 16-byte allocation, self-link sentinel path, linked-node path, and two-dword payload writes. Scores remain below 95 because final original type name/header placement and typed payload wrappers remain unresolved.
