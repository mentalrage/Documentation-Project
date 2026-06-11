*** UID:0001V0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ListNode

## Status

- Entity kind: support struct
- Confidence: strong for observed fields and allocation size, medium for final name/header visibility.
- Direct owner: [UID:0000KR][LinkedList](by-file/LinkedList.md)
- Proposed header/module: `util/LinkedList.h` or private declarations in [UID:0000KR][LinkedList](by-file/LinkedList.md)
- Evidence basis: IDA MCP lookup/decompilation/caller/callee checks on 2026-05-25, 2026-05-31, and 2026-06-08.

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

## Field Evidence

| Offset | Field | Evidence | Notes |
| --- | --- | --- | --- |
| `+0x00` | `next` | [UID:0000XW][0x00457550-0x0045757d.CreateListNode](by-memory/0x00457550-0x0045757d.CreateListNode.md) writes either the supplied `next` pointer or the newly allocated node itself; [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) walks this field until it reaches the sentinel. | Confirms the forward circular-list link. |
| `+0x04` | `prev` | `CreateListNode` writes either the supplied `prev` pointer or the newly allocated node itself; cleanup resets the sentinel's `prev` to the sentinel. | Confirms the backward circular-list link. |
| `+0x08` | `value0` | [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md) copies `payload[0]` into `result[2]`. | Payload meaning is caller-specific, such as minimap key, frame-handler pointer, or archive-bounds key. |
| `+0x0c` | `value1` | `CreateListNodeWithPayload` copies `payload[1]` into `result[3]`. | Payload meaning is caller-specific, such as version text pointer, due-frame key, or archive-bounds pointer. |

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000KR][LinkedList](by-file/LinkedList.md). The child type page now clears `85/90`, and the direct file parent is `85/85`. This is a file-level support type rather than a feature-local nested struct: the same node declaration is used by the shared create, payload-create, and cleanup helpers, with caller spread across minimap, frame scheduling, MonsterImageLib archive bounds, and DAT-index cleanup.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_457550` size `0x2d` and `sub_4570E0` size `0x20`. Current decompile of `sub_457550` calls `operator new(0x10)`, writes `next/prev` from the caller when `next` is non-null, and self-links the node when `next` is null. Current decompile of `sub_4570E0` calls `sub_457550(next, prev)` and then writes the two payload dwords into `result[2]` and `result[3]`.

This node layout is reconstructable source-level container support attached to [UID:0000KR][LinkedList](by-file/LinkedList.md). C++ emission remains blank because final original header/type naming and all typed wrapper payload meanings are not yet at the 95+ final-code threshold.

## 2026-06-08 IDA Refresh

A006 Batch140 live IDA MCP reconfirmed the three helper starts used by this layout: `0x00457550` is `sub_457550` size `0x2d`, `0x004570e0` is `sub_4570E0` size `0x20`, and `0x00457430` is `sub_457430` size `0x43`. `callers` still reports five references to the raw node allocator and four references to the payload wrapper, while [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) records the additional cleanup xrefs that prove shared ownership. The callee sets remain minimal: node creation calls only `operator new`, the payload wrapper calls node creation, and cleanup calls only the free helper.

## Consumers

- [UID:0000XW][0x00457550-0x0045757d.CreateListNode](by-memory/0x00457550-0x0045757d.CreateListNode.md) allocates and initializes sentinel or linked nodes.
- [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md) copies the two-word payload into the value slots.
- [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) frees every node in a sentinel-owned list.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), and [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) use this node family for unrelated payload lists.

## Open Questions

- Whether the original type was named, nested, or template-generated.
- Whether final source should split typed wrappers over the two payload words for frame scheduling, minimap hashes, and image-lib archive bounds.

## Score Rationale

- Completion is `85` because the page now records the 16-byte layout, field-level evidence, sentinel self-link behavior, payload-copy behavior, cleanup traversal, live helper-boundary refresh, sibling [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md) consistency, and a direct `LinkedList` assignment decision.
- Confidence is `90` because allocation size, field offsets, helper bodies, caller spread, and parent ownership all agree. Confidence remains below final confidence because the original source typedef/name and typed payload wrappers are still provisional.

## Cross-References

- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP reverified the 16-byte allocation, self-link sentinel path, linked-node path, and two-dword payload writes. Scores remain below 95 because final original type name/header placement and typed payload wrappers remain unresolved.
- 2026-06-08 A006 Batch140 parent-gate update:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:0000KR`.
  - Summary/evidence: added field-level evidence, strict assignment-gate rationale, and live IDA refresh for the node allocator, payload wrapper, and cleanup helper. The direct parent [UID:0000KR][LinkedList](by-file/LinkedList.md) is `85/85`, so the support type can attach there while final C++ remains blank below the `95/95` gate.
