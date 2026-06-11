*** UID:0001UZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LinkedListState

## Status

- Entity kind: support struct
- Confidence: medium for final naming/header visibility, strong for observed cleanup layout.
- Direct owner: [UID:0000KR][LinkedList](by-file/LinkedList.md)
- Proposed header/module: `util/LinkedList.h` or private declarations in [UID:0000KR][LinkedList](by-file/LinkedList.md)
- Evidence basis: IDA MCP decompilation/disassembly of `0x00457430`, callers/xrefs, and cleanup helper boundaries on 2026-05-25 and 2026-05-31.

## Layout Hypothesis

```cpp
struct LinkedListState {
    ListNode* sentinel; // +0x00
    int count;          // +0x04
};
```

The cleanup helper at `0x00457430` expects this layout. It reads the first live node through `sentinel->next`, resets the sentinel to an empty circular list, zeros `count`, frees every previous live node, then frees the sentinel itself.

## Field Evidence

| Offset | Field | Evidence | Notes |
| --- | --- | --- | --- |
| `+0x00` | `sentinel` | [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) reads `*state`, snapshots `sentinel->next`, writes `sentinel->next = sentinel`, writes `sentinel->prev = sentinel`, and finally frees the sentinel as a 16-byte [UID:0001V0][ListNode](by-type/by-struct/ListNode.md). | Confirms this is the list-state anchor pointer, not an inline node. |
| `+0x04` | `count` | The same cleanup helper writes zero to `state + 4` before walking the old node chain. | Confirmed as the live-node count/reset field; exact signedness remains provisional. |

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000KR][LinkedList](by-file/LinkedList.md). The child type page is now `85/88`, and the direct file parent was refreshed to `85/85` in Batch 129. This is a file-level support type rather than a class-private struct: the state layout is consumed by shared sentinel-list helpers and embedded by several unrelated feature systems, while the `LinkedList` page owns the reusable declaration surface.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_457430` size `0x43`, giving canonical end-exclusive range `0x00457430-0x00457473`. Current IDA decompile reads `*state` as the sentinel pointer, reads the first live node from `sentinel->next`, writes `sentinel->next = sentinel`, writes `sentinel->prev = sentinel`, clears `state[1]`, frees each former live node with `sub_5C7526`, and finally frees the sentinel node. IDA disassembly places the final `retn` at `0x00457472`, which is why the page filename/range should end at `0x00457473`.

2026-06-08 A002 Batch129 live IDA MCP rechecked the helper family: `lookup_funcs` still reports `sub_457430` at `0x00457430` size `0x43`, node creation at `0x00457550` size `0x2d`, and payload-node creation at `0x004570e0` size `0x20`. `callers 0x00457430` still reports the modeled `FrameMgr` destructor caller at `0x004b70cf`, and [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md) records additional tail-jump/EH cleanup xrefs from DATIndexVector, MiniMapVersionManager, and MonsterImageLib. That confirms this state type is shared `LinkedList` utility state, not feature-local storage.

This state layout is reconstructable source-level container support. Parent attachment and C++ emission remain blank because final header ownership and original naming are not at the 95+ final-code threshold.

## Embedded Uses

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) embeds a frame callback list at roughly `this + 0x10`.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) uses compatible sentinel/list state as part of its bucket/list helper; its destructor tail-jumps into the generic cleanup helper on the subobject at `this + 4`.
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) and [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) use the same helper family for list teardown.

## Open Questions

- Whether this was a standalone named struct, an STL-like list base, or inlined private state in several container classes.
- Whether typed wrappers should be documented for frame-scheduler payloads and archive-bound payloads after their final source files stabilize.

## Cross-References

- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001V0][ListNode](by-type/by-struct/ListNode.md)
- [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-31 scoring and range correction:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`; the cleanup cross-reference used `0x00457430-0x00457472`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and the cleanup reference now uses end-exclusive `0x00457430-0x00457473`.
  - Summary/evidence: current IDA MCP decompile/disassembly proves the sentinel/count layout and places the final `retn` at `0x00457472`, requiring end-exclusive `0x00457473`. Scores remain below 95 because final original type name and header ownership are not fully proven.
- 2026-06-08 A002 Batch129:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000KR`.
  - Summary/evidence: added field-level evidence for `sentinel` and `count`, recorded the strict assignment decision, and refreshed the IDA basis for the helper family. The direct parent [UID:0000KR][LinkedList](by-file/LinkedList.md) was improved to `85/85`, so the source-level state declaration can attach there while C++ remains blank below the 95/95 final-code gate.
