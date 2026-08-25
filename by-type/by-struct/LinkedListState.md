*** UID:0001UZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LinkedListState

## Status

- Entity kind: binary support overlay
- Confidence: medium-high for final descriptive naming, strong for observed cleanup layout and STL-list support classification.
- Direct owner: [UID:0000KR][LinkedList](by-file/LinkedList.md) as a non-emitting STL-list support index
- Proposed header/module: no emitted overlay header; direct caller-owned typed `std::list<T>` declarations carry the source semantics. This page is a binary `StdList8State` overlay, not a proven source-authored NexusTK struct.
- Name status: `StdList8State`, `sentinel`, and `count` are descriptive binary inference, not recovered original symbols or source-member spellings.
- Evidence basis: IDA MCP decompilation/disassembly of `0x00457430`, callers/xrefs, cleanup helper boundaries through 2026-08-23, and physical `simroot_v2`/generated-output path checks.

## Layout Hypothesis

```cpp
struct StdList8State {
    StdListNode8* sentinel; // +0x00
    int count;          // +0x04
};
```

The cleanup helper at `0x00457430` expects this layout. It reads the first live node through `sentinel->next`, resets the sentinel to an empty circular list, zeros `count`, frees every previous live node, then frees the sentinel itself.

## Field Evidence

| Offset | Field | Evidence | Notes |
| --- | --- | --- | --- |
| `+0x00` | `sentinel` | [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) reads `*state`, snapshots `sentinel->next`, writes `sentinel->next = sentinel`, writes `sentinel->prev = sentinel`, and finally frees the sentinel as a 16-byte [UID:0001V0][ListNode](by-type/by-struct/ListNode.md). | Confirms this is the list-state anchor pointer, not an inline node. |
| `+0x04` | `count` | The same cleanup helper writes zero to `state + 4` before walking the old node chain. | Confirmed as the live-node count/reset field; exact signedness remains provisional. |

## Assignment Gate

`CANONICAL_OWNER` points to [UID:0000KR][LinkedList](by-file/LinkedList.md). The child type page remains `88/92`, and the accepted direct file parent is `92/94`. This is a binary STL-list state overlay rather than a class-private struct or proven source-authored NexusTK struct: the state layout is consumed by shared compiler-library list helpers and embedded by several unrelated feature systems, while caller source owns direct typed `std::list<T>` containers.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_457430` size `0x43`, giving canonical end-exclusive range `0x00457430-0x00457473`. Current IDA decompile reads `*state` as the sentinel pointer, reads the first live node from `sentinel->next`, writes `sentinel->next = sentinel`, writes `sentinel->prev = sentinel`, clears `state[1]`, frees each former live node with `sub_5C7526`, and finally frees the sentinel node. IDA disassembly places the final `retn` at `0x00457472`, which is why the page filename/range should end at `0x00457473`.

2026-06-08 A002 Batch129 live IDA MCP rechecked the helper family: `lookup_funcs` still reports `sub_457430` at `0x00457430` size `0x43`, node creation at `0x00457550` size `0x2d`, and payload-node creation at `0x004570e0` size `0x20`. `callers 0x00457430` still reports the modeled `FrameMgr` destructor caller at `0x004b70cf`, and [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) records additional tail-jump/EH cleanup xrefs from DATIndexVector, MiniMapVersionManager, and MonsterImageLib. That confirms this state type is shared `std::list` support state, not feature-local storage.

This state layout is binary compiler/STL support. Parent attachment remains useful for documentation, but CPP and H emission stay blank because source-facing reconstruction uses direct typed caller-owned `std::list<T>` declarations, not a hand-authored custom list-state source struct or overlay header.

## Embedded Uses

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) embeds a frame callback list at roughly `this + 0x10`.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) uses compatible sentinel/list state as part of its bucket/list helper; its destructor tail-jumps into the generic cleanup helper on the subobject at `this + 4`.
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) and [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) use the same helper family for list teardown.

## 2026-06-16 Source-Quality Recheck

Live IDA MCP session `b001_0001KM_20260616` and generated helper sources were checked for final declaration blockers:

- `lookup_funcs` still reports the generic helper family at `0x004570e0` size `0x20`, `0x00457430` size `0x43`, and `0x00457550` size `0x2d`.
- `analyze_batch` decompilation of `0x00457430` confirms the state layout exactly: `*state` is the sentinel pointer, `sentinel->next` is snapshotted, the sentinel is reset to `next = sentinel` and `prev = sentinel`, `state[1]` is cleared, old nodes are freed, and the sentinel is freed last.
- `analyze_batch` decompilation of `0x00457550` confirms 16-byte `ListNode` allocation and self-linking sentinel behavior when `next` is null. `0x004570e0` calls that allocator and copies two payload dwords into node slots `+0x08/+0x0c`.
- `xref_query` to `0x00457430` returns six references: `DATIndexVectorDestructor` tail jump, a raw `0x004b6e7c` cleanup ref, `FrameMgr` destructor at `0x004b70cf`, `MiniMapVersionManager` EH cleanup, and two `MonsterImageLib` EH cleanup refs. This reconfirms shared utility ownership under [UID:0000KR][LinkedList](by-file/LinkedList.md), not a feature-local owner.
- `type_query` and `search_structs` for `LinkedList`, `LinkedListState`, and `ListNode` found no preserved NexusTK local UDTs.
- Historical 2026-06-16 notes treated `source-3/simroot_v2/recovered/CreateListNode_00457550.cpp` and `source-3/simroot_v2/recovered/CreateListNodeWithPayload_004570E0.cpp` as recovered helper leads agreeing with `ListNode { next, prev, value0, value1 }`. The accepted 2026-08-23 physical recheck found no `source-3/simroot_v2` directory, so both exact mappings are now retained only as dated historical evidence and are physically absent.
- `auto-generated/NexusTK/util/LinkedList.cpp` and `auto-generated/NexusTK/util/LinkedList.h` are both physically absent, not empty files. Bounded generated-tree searches found no UID0000KR/helper/overlay fragment, which is the expected complete output for this false/emitterless page with blank CPP/H.

Final CPP and H remain blank because direct caller-owned `std::list<T>` is the selected reconstruction spelling and `StdList8State` is only a descriptive binary overlay. No wrapper/header symbol, UDT, file, API, or unique contract supports a source-authored `LinkedListState`; the former wrapper/header-shape uncertainty is closed unless new contrary evidence appears.

## Open Questions

- Historical name question: a future original symbol or compiler map could refine the descriptive `StdList8State` label, but the current overlay/member names remain explicitly non-original and do not gate source reconstruction.
- Closed source-container/header question: use direct caller-owned `std::list<T>` and emit no `LinkedListState` header. Exhaustive current checks found no project wrapper UDT, symbol, header, source file, API, or unique wrapper contract; a thin wrapper or custom state header is unsupported unless new contrary evidence appears.

## Score Rationale

- Completion is `88` because sentinel/count layout, cleanup behavior, allocator/payload helper relationship, caller spread, non-emitting STL-list support classification, physical source/generated checks, and direct-container/no-header resolution are all recorded on the page.
- Confidence is `92` because current IDA decompilation, function boundaries, xrefs, runtime allocator/free lineage, `"list<T> too long"` insertion-family evidence, and path checks independently support the two-field state layout and shared support-index owner. Confidence remains below final-symbol proof only because no preserved UDT or original local template/member name exists; direct `std::list<T>` and no-header disposition are resolved.

## Cross-References

- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001V0][ListNode](by-type/by-struct/ListNode.md)
- [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-08-24 B009 accepted UID0000KR implementation callback:
  - Preserved `88/92`, owner UID0000KR, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal CPP/H.
  - Historicalized the two exact but physically absent `simroot_v2` recovered mappings and corrected the stale generated-CPP-is-empty statement: both generated `LinkedList.cpp` and `.h` are physically absent, with no helper fragment elsewhere.
  - Selected direct caller-owned `std::list<T>`, closed unsupported thin-wrapper/custom-header uncertainty, and retained `StdList8State`, `sentinel`, and `count` only as descriptive binary inference rather than original-symbol proof.
- 2026-05-31 scoring and range correction:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`; the cleanup cross-reference used `0x00457430-0x00457472`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and the cleanup reference now uses end-exclusive `0x00457430-0x00457473`.
  - Summary/evidence: current IDA MCP decompile/disassembly proves the sentinel/count layout and places the final `retn` at `0x00457472`, requiring end-exclusive `0x00457473`. Scores remain below 95 because final original type name and header ownership are not fully proven.
- 2026-06-08 A002 Batch129:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000KR`.
  - Summary/evidence: added field-level evidence for `sentinel` and `count`, recorded the strict assignment decision, and refreshed the IDA basis for the helper family. The direct parent [UID:0000KR][LinkedList](by-file/LinkedList.md) was improved to `85/85`, so the source-level state declaration can attach there while C++ remains blank below the 95/95 final-code gate.
- 2026-06-16 A002 source-quality pass:
  - Before: `85/88`.
  - After: `86/89`.
  - Summary/evidence: live IDA MCP session `b001_0001KM_20260616` reconfirmed helper starts/sizes, cleanup decompilation, node allocation and payload-copy behavior, six cleanup xrefs across unrelated consumers, and no preserved `LinkedListState`/`ListNode` local UDT. Generated recovered helpers agree on the node fields but do not settle the original state/header declaration.
- 2026-06-17 B001 source-quality execution:
  - Before: `86/89`, described as reconstructable source-level container support.
  - After: `88/92`, `RECONSTRUCTABLE:FALSE`, blank emitter, described as a binary `StdList8State` overlay for non-emitting MSVC/Dinkumware `std::list<T>` support.
  - Summary/evidence: B001 tied the helper family to exact `"list<T> too long"` diagnostics, runtime `operator new`/free thunks, standard sentinel/list-state layout, unrelated typed consumers, and blank generated output. The layout remains useful for binary documentation, but it should not be emitted as a custom NexusTK source struct.
