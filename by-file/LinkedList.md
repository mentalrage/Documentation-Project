*** UID:0000KR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LinkedList

## Status

- Proposed module: `util/LinkedList.cpp`
- Proposed header: `util/LinkedList.h`
- Confidence: medium for standalone file, strong for utility ownership.
- Current recovered sources:
  - `source-3/simroot_v2/recovered/CreateListNode_00457550.cpp`
  - `source-3/simroot_v2/recovered/CreateListNodeWithPayload_004570E0.cpp`
- Evidence basis: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, decompilation, and disassembly checks on 2026-05-25 and 2026-05-31. `simroot_v2` recovered globals and `by-memory/-report.md` are treated as leads/cross-checks, not authority.

## File Role

`LinkedList.cpp` is the current reconstruction target for a tiny sentinel-based intrusive doubly-linked-list helper family. It is separate from [UID:0000KS][List](by-file/List.md), which is the fixed-width dynamic array container, and from [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md), which is a lock-protected free-list style helper.

The helper allocates 16-byte nodes, optionally copies a two-word payload, and destroys a list state by freeing every node and the sentinel. It is used by unrelated systems, so it should not be owned by [UID:0000JM][FrameMgr](by-file/FrameMgr.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), or [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) just because those modules embed or call it.

## Likely Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:0001V0][ListNode](by-type/by-struct/ListNode.md) | type-only | `util/LinkedList.h` or private source struct | `next`, `prev`, and two payload/value words. |
| [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md) | type-only | `util/LinkedList.h` or private source struct | Sentinel pointer plus count used by cleanup helper. |
| [UID:0000XW][0x00457550-0x0045757d.CreateListNode](by-memory/0x00457550-0x0045757d.CreateListNode.md) | `0x00457550-0x0045757d` | `util/LinkedList.cpp` | Allocates a node; `next == 0` creates a self-linked sentinel. |
| [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md) | `0x004570e0-0x004570ff` | `util/LinkedList.cpp` | Calls `CreateListNode`, then copies two payload words. |
| [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) | `0x00457430-0x00457473` | `util/LinkedList.cpp` or inline private helper | Clears a sentinel list and frees all nodes plus the sentinel. |

## Evidence

- IDA MCP `lookup_funcs` reports `0x00457550` size `0x2d`, `0x004570e0` size `0x20`, and `0x00457430` size `0x43`.
- `CreateListNode` callers include `MiniMapVersionManager` setup, `CreateListNodeWithPayload`, `FrameMgr` construction, and `MonsterImageLib` construction.
- `CreateListNodeWithPayload` callers include minimap hash-list updates, `FrameMgr::Insert`, and two `MonsterImageLib::GetArchiveBoundsBucket` sites.
- `0x00457430` is directly called by `FrameMgr::ScalarDeletingDestructor` and reached by xrefs/tail-jump cleanup from `DATIndexVector`, `MiniMapVersionManager`, and `MonsterImageLib` teardown paths.
- The body of `0x00457430` is generic list cleanup only: reset sentinel links, zero count, free each node, then free the sentinel.
- 2026-05-31 IDA MCP recheck: helper boundaries remain `0x00457550-0x0045757d` for node allocation, `0x004570e0-0x00457100` for payload-node allocation, and `0x00457430-0x00457473` for list-state cleanup. The caller sets still cross MiniMapVersionManager, FrameMgr, MonsterImageLib, and DATIndexVector-style cleanup paths, supporting shared utility ownership rather than feature ownership.

## Source-Structure Decision

Use `util/LinkedList.cpp` as the current file-level grouping for these helpers. The final original project may have implemented this as inline template/list support inside a broader utility header, but the helper family is too broadly used to leave as one recovered global file per address or to fold into any feature module.

Keep [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)'s bucket/list-specific `0x00457310` remove helper with `DATIndexVector.cpp`; it hashes bucket keys and repairs bucket first/last state, which is more specific than this generic sentinel-list helper.

## Generated Output Caveats

- Active `class_FrameMgr.cpp` calls `LinkedList::Create` and `LinkedList::Destroy`, but the generated active view does not provide a coherent `LinkedList` source module yet.
- `by-memory/-report.md` marks the old synthetic `LinkedListState_457430` class reconstruction as `should_reconstruct=no`; that should be read as "do not create a fake feature class," not as evidence that the generic helper behavior can be ignored.
- The original source name may have been `List.cpp`, `LinkList.cpp`, or a header-only utility. The `LinkedList.cpp` filename is a working reconstruction target.

## Cross-References

- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001V0][ListNode](by-type/by-struct/ListNode.md)
- [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md)
- [UID:0000XW][0x00457550-0x0045757d.CreateListNode](by-memory/0x00457550-0x0045757d.CreateListNode.md)
- [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md)
- [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md)
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)

## Changes

- 2026-05-27: Updated `CreateListNode` range text from `0x00457550-0x0045757c` to `0x00457550-0x0045757d`. Evidence: IDA MCP reports `sub_457550` size `0x2d`, ending at `0x0045757d`; the prior range omitted the last byte of `retn 8`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: generic sentinel-list role, node/state types, helper ranges, callers, cleanup behavior, source-structure decision, generated caveats, and range correction are documented; confidence is capped by uncertainty around the exact original filename versus a header utility.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `LinkedList.cpp` under `util/`, and the 2026-05-31 IDA MCP pass reconfirms this is shared sentinel-list support used across unrelated modules.
- 2026-05-31 cleanup helper range correction:
  - What existed before: the cleanup helper table and references used `0x00457430-0x00457472`.
  - Changed to: `0x00457430-0x00457473`.
  - Summary/evidence: IDA MCP reports `sub_457430` size `0x43`, and disassembly shows the final `retn` at `0x00457472`, making `0x00457473` the correct end-exclusive bound.
