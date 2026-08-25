*** UID:0001V0 | DO NOT MODIFY OR REMOVE!!! ***
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

# ListNode

## Status

- Entity kind: binary support overlay
- Confidence: strong for observed fields, allocation size, and STL-list support classification; medium-high for final descriptive name because no original local template-helper type symbol survived.
- Direct owner: [UID:0000KR][LinkedList](by-file/LinkedList.md) as a non-emitting STL-list support index
- Proposed header/module: no emitted overlay header; direct caller-owned typed `std::list<T>` declarations carry the source semantics. This page is a binary `StdListNode8` overlay, not a proven source-authored NexusTK struct.
- Name status: `StdListNode8`, `next`, `prev`, `value0`, and `value1` are descriptive binary inference, not recovered original symbols or source-member spellings.
- Evidence basis: IDA MCP lookup/decompilation/caller/callee checks through 2026-08-23 plus physical `simroot_v2` and generated-output path checks.

## Layout Hypothesis

```cpp
struct StdListNode8 {
    StdListNode8* next; // +0x00
    StdListNode8* prev; // +0x04
    int value0;     // +0x08
    int value1;     // +0x0c
};
```

`StdListBuyNode8` allocates exactly 16 bytes. When called with `next == 0`, it self-links `next` and `prev`, producing the sentinel node used by several owning list states. `StdListBuyNodeWithPayload8` copies two caller-supplied words into `value0` and `value1`.

## Field Evidence

| Offset | Field | Evidence | Notes |
| --- | --- | --- | --- |
| `+0x00` | `next` | [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md) writes either the supplied `next` pointer or the newly allocated node itself; [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) walks this field until it reaches the sentinel. | Confirms the forward circular-list link. |
| `+0x04` | `prev` | `StdListBuyNode8` writes either the supplied `prev` pointer or the newly allocated node itself; cleanup resets the sentinel's `prev` to the sentinel. | Confirms the backward circular-list link. |
| `+0x08` | `value0` | [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md) copies `payload[0]` into `result[2]`. | Payload meaning is caller-specific, such as MiniMapVersionManager `mapId`, frame-handler pointer, or archive-bounds key. |
| `+0x0c` | `value1` | `StdListBuyNodeWithPayload8` copies `payload[1]` into `result[3]`. | Payload meaning is caller-specific, such as MiniMapVersionManager `expectedVersionString`, due-frame key, or archive-bounds pointer. |

## Assignment Gate

`CANONICAL_OWNER` is set to [UID:0000KR][LinkedList](by-file/LinkedList.md). The child type page remains `88/92`, and the accepted direct file parent is `92/94`. This is a binary STL-list node overlay rather than a feature-local nested struct or proven source-authored NexusTK struct: the same node layout is used by the shared allocation, payload-allocation, and cleanup helpers, with caller spread across minimap, frame scheduling, MonsterImageLib archive bounds, and DAT-index cleanup.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_457550` size `0x2d` and `sub_4570E0` size `0x20`. Current decompile of `sub_457550` calls `operator new(0x10)`, writes `next/prev` from the caller when `next` is non-null, and self-links the node when `next` is null. Current decompile of `sub_4570E0` calls `sub_457550(next, prev)` and then writes the two payload dwords into `result[2]` and `result[3]`.

This node layout is documented as binary compiler/STL support attached to [UID:0000KR][LinkedList](by-file/LinkedList.md). C++ emission remains blank because source-facing reconstruction should use typed caller containers, and no preserved NexusTK source-authored node typedef or original local template type symbol has been found.

## 2026-06-08 IDA Refresh

A006 Batch140 live IDA MCP reconfirmed the three helper starts used by this layout: `0x00457550` is `sub_457550` size `0x2d`, `0x004570e0` is `sub_4570E0` size `0x20`, and `0x00457430` is `sub_457430` size `0x43`. `callers` still reports five references to the raw node allocator and four references to the payload wrapper, while [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) records the additional cleanup xrefs that prove shared ownership. The callee sets remain minimal: node creation calls only `operator new`, the payload wrapper calls node creation, and cleanup calls only the free helper.

## 2026-08-23 Physical Source And Generated Audit

The accepted B009 whole-file recheck found no `source-3/simroot_v2` directory. The established mappings `source-3/simroot_v2/recovered/CreateListNode_00457550.cpp` and `source-3/simroot_v2/recovered/CreateListNodeWithPayload_004570E0.cpp` are retained only as dated historical evidence and are physically absent from the current workspace.

`auto-generated/NexusTK/util/LinkedList.cpp` and `auto-generated/NexusTK/util/LinkedList.h` are both physically absent, not empty files. Bounded generated-tree searches also found no UID0000KR/UID0000XR/UID0000XV/UID0000XW or `StdListBuyNode`/`StdListTidy`/`CreateListNode`/`LinkedListState_457430` fragment. This zero-file/zero-fragment state is the expected complete output for the non-emitting overlay.

## Consumers

- [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md) allocates and initializes sentinel or linked nodes.
- [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md) copies the two-word payload into the value slots.
- [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) frees every node in a sentinel-owned list.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), and [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) use this node family for unrelated payload lists.

## Typed Payload Interpretations

| Consumer | `value0` | `value1` | Source-facing container direction |
| --- | --- | --- | --- |
| [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) hash/version list | `mapId` parsed from minimap hash-list records and validated by renderer callers passing `MiniMapRenderer +0x25c` | `wchar_t* expectedVersionString` compared against the 33-wide-character `.mnm` header/version string | direct `std::list<MiniMapVersionRecord>` |
| [UID:0000JM][FrameMgr](by-file/FrameMgr.md) scheduler list | `FrameHandler*` callback/handler pointer | Due-frame or scheduling key | direct `std::list<FrameScheduleEntry>` |
| [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) archive-reader cache | Archive index | Archive reader / DAT handle payload | direct `std::list<MonsterArchiveCacheEntry>` |
| [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) archive-bounds cache | Archive index | `MonsterArchiveBoundsBucket*` payload | direct `std::list<MonsterArchiveBoundsBucketEntry>` |

Do not collapse these into one universal NexusTK source struct. The shared 16-byte node shape is compiler/STL implementation storage; semantic field names belong to the typed caller records.

## Open Questions

- Historical name question: a future original symbol or compiler map could refine the descriptive `StdListNode8` label, but the current overlay/member names remain explicitly non-original and do not gate source reconstruction.
- Closed source-container question: use direct caller-owned `std::list<T>`. Exhaustive current checks found no project wrapper UDT, symbol, header, source file, API, or unique wrapper contract; a thin wrapper is unsupported unless new contrary evidence appears.

## Score Rationale

- Completion is `88` because the page now records the 16-byte layout, field-level evidence, sentinel self-link behavior, payload-copy behavior, cleanup traversal, live helper-boundary refresh, sibling [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md) consistency, non-emitting STL-list support classification, and caller-local payload meanings.
- Confidence is `92` because allocation size, field offsets, helper bodies, caller spread, runtime allocator/free lineage, `"list<T> too long"` insertion-family evidence, and parent support-index ownership all agree. Confidence remains below final-symbol proof only because the original overlay/type/member spellings did not survive; direct `std::list<T>` and the exact caller-local semantic records are resolved for reconstruction.

## Cross-References

- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-08-24 B009 accepted UID0000KR implementation callback:
  - Preserved `88/92`, owner UID0000KR, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal CPP/H.
  - Historicalized the two exact but physically absent `simroot_v2` recovered mappings; recorded that generated `LinkedList.cpp` and `.h` are physically absent and no helper fragment exists.
  - Selected direct caller-owned `std::list<T>`, closed unsupported thin-wrapper uncertainty, and retained `StdListNode8` plus all member names only as descriptive binary inference rather than original-symbol proof.
- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP reverified the 16-byte allocation, self-link sentinel path, linked-node path, and two-dword payload writes. Scores remain below 95 because final original type name/header placement and typed payload wrappers remain unresolved.
- 2026-06-08 A006 Batch140 parent-gate update:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:0000KR`.
  - Summary/evidence: added field-level evidence, strict assignment-gate rationale, and live IDA refresh for the node allocator, payload wrapper, and cleanup helper. The direct parent [UID:0000KR][LinkedList](by-file/LinkedList.md) is `85/85`, so the support type can attach there while final C++ remains blank below the `95/95` gate.
- 2026-06-17 B001 source-quality execution:
  - Before: `85/90`, described as reconstructable source-level container support.
  - After: `88/92`, `RECONSTRUCTABLE:FALSE`, blank emitter, described as a binary `StdListNode8` overlay for non-emitting MSVC/Dinkumware `std::list<T>` support.
  - Summary/evidence: B001 tied the node helpers to exact `"list<T> too long"` diagnostics, runtime `operator new`/free thunks, standard sentinel/list-node layout, unrelated typed consumers, and blank generated output. The layout remains useful for binary documentation, but it should not be emitted as a custom NexusTK source struct.
