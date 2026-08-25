*** UID:0000KR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LinkedList

## Status

- Proposed module: no standalone emitted source file; keep this page as a non-emitting STL-list support index
- Proposed header: none for this index; direct caller-owned typed `std::list<T>` declarations carry the source semantics
- Confidence: very strong for shared STL/Dinkumware list-support identity, non-emission, and direct standard-container source semantics; the `StdList*` names remain descriptive because no original decorated local template symbols survived.
- Dated historical recovered-source mappings, physically absent in the 2026-08-23 workspace because `source-3/simroot_v2` does not exist:
  - `source-3/simroot_v2/recovered/CreateListNode_00457550.cpp`
  - `source-3/simroot_v2/recovered/CreateListNodeWithPayload_004570E0.cpp`
- Evidence basis: IDA MCP `lookup_funcs`, `callees`, `xrefs_to`, decompilation, disassembly, bytes, frame, comments, and type/UDT checks through 2026-08-23. The absent `simroot_v2` mappings and `by-memory/-report.md` are dated leads/cross-checks, not current source authority.

## File Role

`LinkedList` is now a documentation/support index for MSVC/Dinkumware `std::list<T>` 8-byte-value node helpers, not a custom NexusTK `LinkedList.cpp` source emitter. It is separate from [UID:0000KS][List](by-file/List.md), which is the fixed-width dynamic array container, and from [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md), which is a lock-protected free-list style helper.

The compiler/library helper code allocates 16-byte nodes, optionally copies a two-word payload, and destroys a list state by freeing every node and the sentinel. It is used by unrelated systems, so it should not be owned by [UID:0000JM][FrameMgr](by-file/FrameMgr.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), or [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) just because those modules embed or call it. Those modules own typed source declarations such as minimap version records, frame scheduler entries, and monster image cache records.

## Rule 26 Inference Notes

- Selected source-facing reconstruction: these helpers come from MSVC/Dinkumware `std::list<T>` implementation support for an 8-byte value type. Caller source should use direct typed containers such as `std::list<MiniMapVersionRecord>`, `std::list<FrameScheduleEntry>`, and `std::list<MonsterArchiveCacheEntry>`. No custom UDT, wrapper symbol, product API, header, source file, or unique wrapper contract supports a thin project wrapper; that alternative is closed unless new contrary evidence appears.
- Typed payload interpretations are caller-local: MiniMapVersionManager uses `{ int mapId, wchar_t* expectedVersionString }`; older `mapKey`/`hashKey` and broad `versionText` wording is only a historical binary-analysis alias because renderer callers pass a map id and compare the returned value against the `.mnm` header/version string. FrameMgr scheduling uses `{ FrameHandler* handler, uint32_t dueFrame }`, MonsterImageLib archive-reader caching uses `{ int archiveIndex, void* archiveReaderOrDatHandle }`, and MonsterImageLib bounds caching uses `{ int archiveIndex, MonsterArchiveBoundsBucket* bucket }`.
- Rejected source alternatives: an emitted custom `NexusTK/util/LinkedList.cpp`, feature-local ownership under MiniMapVersionManager/FrameMgr/MonsterImageLib/DATIndexVector, and MemoryMan ownership. The allocation/free callees are runtime `operator new`/free thunks, the `"list<T> too long"` diagnostic ties the helpers to STL insertion code, and no one feature owns all callers.
- The old recovered names `CreateListNode`, `CreateListNodeWithPayload`, and `LinkedListState_457430` are useful binary leads only. They should not be propagated as final source names or as evidence for a handwritten game helper.
- `StdListNode8`, `StdList8State`, `StdListBuyNode8`, `StdListBuyNodeWithPayload8`, `StdListTidy8ByteList`, and their `next`/`prev`/`value0`/`value1`/`sentinel`/`count` members are descriptive binary-analysis names, not recovered original symbols or source declarations.

## Batch 129 Parent-Gate Audit

This file now clears the strict `85/85` gate for shared STL-list support classification. The direct ownership evidence is the complete helper family rather than a single caller: [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md), [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md), and [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md) form a small compiler-library support island used by frame scheduling, minimap, monster-image archive bounds, and DAT-index cleanup. The type pages [UID:0001V0][ListNode](by-type/by-struct/ListNode.md) and [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md) describe binary overlays for the node/state layout consumed by those helpers.

2026-06-08 live IDA MCP rechecked the three helper starts: `0x004570e0` is `sub_4570E0` size `0x20`, `0x00457430` is `sub_457430` size `0x43`, and `0x00457550` is `sub_457550` size `0x2d`. `callers 0x00457430` still reports the modeled `FrameMgr` destructor caller at `0x004b70cf`, while [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) records the additional tail-jump and EH-cleanup xrefs that tie the same cleanup helper to DATIndexVector, MiniMapVersionManager, and MonsterImageLib. That caller spread makes feature-local ownership less direct than the shared `LinkedList` support root.

2026-06-14 C001 live IDA MCP rechecked the helper family again. `lookup_funcs` still reports `0x004570e0` size `0x20`, `0x00457430` size `0x43`, and `0x00457550` size `0x2d`; `tools/int_convert.py` verifies those as `32`, `67`, and `45` bytes respectively. `xrefs_to` reports four payload-node wrapper references, five raw node-allocator references, and six cleanup references including the DATIndexVector tail jump, FrameMgr destructor/cleanup paths, MiniMapVersionManager EH cleanup, and MonsterImageLib EH cleanup paths. `lookup_funcs 0x00457310` still identifies the separate `0xa3` DATIndexVector-specific helper, so the generic file boundary should not absorb keyed bucket logic.

## Likely Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:0001V0][ListNode](by-type/by-struct/ListNode.md) | type-only | binary `StdListNode8` overlay | `next`, `prev`, and two caller-local payload/value words. |
| [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md) | type-only | binary `StdList8State` overlay | Sentinel pointer plus count used by cleanup helper. |
| [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md) | `0x00457550-0x0045757d` | non-emitting STL support | Allocates a node; `next == 0` creates a self-linked sentinel. |
| [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md) | `0x004570e0-0x00457100` | non-emitting STL support | Calls `StdListBuyNode8`, then copies two payload words. |
| [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) | `0x00457430-0x00457473` | non-emitting STL support | Clears a sentinel list and frees all nodes plus the sentinel. |
| alignment | `0x00457429-0x00457430` | padding/no source | Seven `0xcc` bytes before `StdListTidy8ByteList`; preserve as padding. |
| alignment | `0x00457473-0x00457480` | padding/no source | Thirteen `0xcc` bytes after `StdListTidy8ByteList`; preserve as padding. |
| alignment | `0x00457547-0x00457550` | padding/no source | Nine `0xcc` bytes before `StdListBuyNode8`; preserve as padding. |
| alignment | `0x0045757d-0x00457580` | padding/no source | Three `0xcc` bytes after `StdListBuyNode8`; preserve as padding. |
| `aListTTooLong` | `0x0060dfac-0x0060dfbd` | shared compiler literal/no target source | Seventeen-byte NUL-terminated `"list<T> too long"`; seven cross-feature xrefs prove broader compiler-library ownership. |
| decorated `operator new` | `0x005c74f6` | runtime dependency/excluded | Sole allocation dependency of `StdListBuyNode8`; allocates `0x10` bytes. |
| CRT free wrapper | `0x005c7526` | runtime dependency/excluded | Sole deallocation dependency of `StdListTidy8ByteList`; not `MemoryMan`. |
| [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) | `0x004570b0-0x004570e0` | MiniMap source/excluded | Typed lookup immediately before the payload helper. |
| [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | `0x00457100-0x0045730f` | hash-container lowering/excluded | Separate FNV/bucket insertion behavior immediately after the payload helper. |
| [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | `0x00457310-0x004573b3` | hash-container lowering/excluded | Separate erase/unwind bucket behavior. |
| [UID:0004DE][0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md) | `0x004573c0-0x004573cb` | MiniMap source/excluded | Feature-owned singleton-clear helper. |
| [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) | `0x004573d0-0x00457429` | hash-container lowering/excluded | Separate DATIndexVector destruction lowering that tail-jumps to list teardown. |
| [UID:0004DF][0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor](by-memory/0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor.md) | `0x00457480-0x00457547` | compiler wrapper/excluded | MiniMap feature-class scalar deleting destructor. |
| [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) | `0x00457580-0x00457613` | hash-container lowering/excluded | Separate keyed find behavior after node allocation. |

## Evidence

- IDA MCP `lookup_funcs` reports `0x00457550` size `0x2d`, `0x004570e0` size `0x20`, and `0x00457430` size `0x43`.
- `StdListBuyNode8` callers include `MiniMapVersionManager` setup, `StdListBuyNodeWithPayload8`, `FrameMgr` construction, and `MonsterImageLib` construction.
- `StdListBuyNodeWithPayload8` callers include minimap hash-list updates, `FrameMgr::Insert`, and two `MonsterImageLib::GetArchiveBoundsBucket` sites.
- `0x00457430` is directly called by `FrameMgr::ScalarDeletingDestructor` and reached by xrefs/tail-jump cleanup from `DATIndexVector`, `MiniMapVersionManager`, and `MonsterImageLib` teardown paths.
- The body of `0x00457430` is generic list cleanup only: reset sentinel links, zero count, free each node, then free the sentinel.
- 2026-05-31 IDA MCP recheck: helper boundaries remain `0x00457550-0x0045757d` for node allocation, `0x004570e0-0x00457100` for payload-node allocation, and `0x00457430-0x00457473` for list-state cleanup. The caller sets still cross MiniMapVersionManager, FrameMgr, MonsterImageLib, and DATIndexVector-style cleanup paths, supporting shared utility ownership rather than feature ownership.
- 2026-06-17 B001 source-quality recheck: insertion paths around these helpers use the exact diagnostic literal `"list<T> too long"`, `0x00457550` calls runtime `operator new(0x10)`, `0x00457430` calls a runtime free thunk rather than project `MemoryMan`, and the caller spread matches compiler-emitted `std::list<T>` support for unrelated typed payloads.
- 2026-08-23 B009 whole-file recheck sealed `0x004570e0-0x00457100` as 32 bytes with SHA256 `3417C834067CD8D3C358C919AFB37C85FA5A0C2CA7F23C23734AC90D8CE0F1BD`, `0x00457430-0x00457473` as 67 bytes with SHA256 `FF3AF873B592BD9E67013DC51C8F29E26EB053F27FE0B0405C017E237BCEB31F`, and `0x00457550-0x0045757d` as 45 bytes with SHA256 `2202E6AB04C19C0658921A22C6705C58912861A080B90922C76806CD8866913E`. Current IDA names were still `sub_4570E0`, `sub_457430`, and `sub_457550`; all address/function comment channels were empty, and no `LinkedList`, `ListNode`, or `StdList` UDT/function-name collision existed.
- Exact function-entry xref totals are four for `0x004570e0`, six for `0x00457430`, and five for `0x00457550`. The shared literal has seven xrefs at `0x00422e7d`, `0x0045708a`, `0x0049caba`, `0x004a6fff`, `0x004b6f04`, `0x004dc161`, and `0x004dc16b`.
- Whole-file negative inventory is zero LinkedList-owned globals, statics, initialized tables, vtables, RTTI, resources, imports, source declarations, unique literals, or generated fragments. The only literal is shared compiler-library evidence; both callees are runtime dependencies.

## Source-Structure Decision

Keep [UID:0000KR] as a non-emitting support/index grouping for these helpers. Do not generate a hand-written `util/LinkedList.cpp` body for [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md), [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md), or [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md); their source-facing effect belongs in typed caller containers or equivalent source declarations. The final project may still have had a utility/header grouping for list use, but the binary helper bodies are compiler/Dinkumware support rather than custom NexusTK source.

For reconstruction, use direct caller-owned `std::list<T>` declarations and ordinary list operations. The thin-wrapper possibility is unsupported and no longer deferred. MiniMap uses `MiniMapVersionRecord { int mapId; wchar_t* expectedVersionString; }`; FrameMgr uses `{ FrameHandler* handler; uint32_t dueFrame; }`; MonsterImageLib uses distinct archive-reader and archive-bounds records. Do not flatten those semantics into one raw payload type.

The bucket/list-specific `0x00457310` body is the insertion-unwind erase lowering for the same folded old-MSVC/Dinkumware hash-container family documented by [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md). It hashes keys and repairs bucket first/last state, so it is not part of this generic list-support index; it also has no separate `DATIndexVector.cpp` source owner.

The compiler hash-container representation embeds STL-list-compatible state and calls `StdListTidy8ByteList`, but bucket tables, FNV-1a keying, duplicate collapse, and node/bucket overlays remain non-emitting compiler-family evidence on [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) and [UID:00003K][DATIndexVector](by-class/DATIndexVector.md). Typed caller-owned standard containers provide the human source.

## Generated Output Caveats

- Active/generated views that call `LinkedList::Create` or `LinkedList::Destroy` should be treated as stale helper abstractions. The accepted source-quality route is typed caller-owned containers, with these helper bodies ignored/non-emitting.
- `by-memory/-report.md` marks the old synthetic `LinkedListState_457430` class reconstruction as `should_reconstruct=no`; that should be read as "do not create a fake feature class," not as evidence that the generic helper behavior can be ignored.
- `auto-generated/NexusTK/util/LinkedList.cpp` and `auto-generated/NexusTK/util/LinkedList.h` are physically absent, and bounded generated-tree searches find no UID0000KR/UID0000XR/UID0000XV/UID0000XW, `StdListBuyNode`, `StdListTidy`, `CreateListNode`, or `LinkedListState_457430` fragment. That zero-file/zero-fragment inventory is the expected complete output for path `NONE`.
- The selected reconstruction spelling is direct caller-owned `std::list<T>`. No standalone `LinkedList.cpp`, `LinkedList.h`, raw overlay header, split, child UID, or synthetic UDT is required.

## No-Code And No-Header Proof

The three positive bodies are folded compiler/template support: one allocates a 16-byte node, one copies an 8-byte caller-owned value, and one tears down sentinel-owned state through runtime allocation/free thunks. The exact `"list<T> too long"` diagnostic, standard sentinel/count morphology, unrelated caller fanout, absent product symbols/types/data, false/emitterless child metadata, blank formal CPP/H channels, and physically absent generated files independently converge on no custom source emission.

No sibling header is justified. `StdListNode8` and `StdList8State` are descriptive binary overlays, not source-authored records; every semantic value type is caller-specific; and no custom wrapper declaration survives. Emitting either overlay would expose compiler internals, invent a product API, and duplicate caller-owned declarations.

## Cross-References

- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001V0][ListNode](by-type/by-struct/ListNode.md)
- [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md)
- [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md)
- [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md)
- [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md)
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)

## Changes

- 2026-08-24 B009 accepted UID0000KR implementation callback:
  - Before: `COMPLETION:88`, `CONFIDENCE:90`; active text retained absent recovered paths as current leads, deferred direct `std::list<T>` versus wrapper spelling, omitted the complete padding/dependency/exclusion inventory, and did not explicitly prove physical absence of both generated files.
  - After: `COMPLETION:92`, `CONFIDENCE:94`, path `NONE` and owner `FILE` unchanged. The page now records all three exact helper bodies and byte seals, both descriptive overlays, four padding spans, shared literal and seven xrefs, two runtime dependencies, seven exact excluded neighboring functions, four caller payload meanings, zero file-owned data/type/resource inventory, exact historical-but-absent `simroot_v2` mappings, physically absent generated CPP/H, selected direct caller-owned `std::list<T>`, and complete no-code/no-header proof.
  - Score rationale: completion rises for exhaustive inventory, destination/source-spelling closure, generated-output audit, and formal no-code/no-header disposition. Confidence rises because current bounded IDA bytes, boundaries, xrefs, callees, comments, collision/UDT negatives, runtime lineage, and physical path checks agree. Scores remain below 95 because descriptive `StdList*`/overlay/member names are not original decorated-symbol proof; that limitation does not reopen source placement or emission.
- 2026-06-21 B009 Rule 26 incorporation:
  - No score change. Added a cross-reference boundary note confirming that DATIndexVector's embedded list state uses this non-emitting support, while keyed bucket algorithms and semantic node/bucket overlays stay with [UID:00003K][DATIndexVector](by-class/DATIndexVector.md).
- 2026-06-14 C001 Goal 2 by-file score refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed helper starts/sizes, direct xref spread, the separation from the DATIndexVector-specific `0x00457310` helper, and shared caller coverage across minimap, frame scheduling, monster-image, and DATIndexVector cleanup paths. Scores remain below final-audit quality because the exact original source/header name and payload-typing model remain provisional.
- 2026-06-17 B001 source-quality execution:
  - Before: `COMPLETION:87`, `CONFIDENCE:88`, described as a custom `util/LinkedList.cpp` helper target.
  - After: `COMPLETION:88`, `CONFIDENCE:90`, reclassified as a non-emitting MSVC/Dinkumware `std::list<T>` support index.
  - Summary/evidence: B001 tied the three helper bodies to exact `"list<T> too long"` diagnostics, runtime `operator new`/free thunks, standard sentinel/list-node layout, unrelated typed consumers, and blank generated output. The address grouping remains useful, but formal C++ should not be emitted for the helper bodies.
- 2026-05-27: Updated the former `CreateListNode` range text, now [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md), from `0x00457550-0x0045757c` to `0x00457550-0x0045757d`. Evidence: IDA MCP reports `sub_457550` size `0x2d`, ending at `0x0045757d`; the prior range omitted the last byte of `retn 8`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: generic sentinel-list role, node/state types, helper ranges, callers, cleanup behavior, source-structure decision, generated caveats, and range correction are documented; confidence is capped by uncertainty around the exact original filename versus a header utility.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` placed the support grouping under `util/`, and the 2026-05-31 IDA MCP pass reconfirmed this was shared sentinel-list support used across unrelated modules. This was superseded by the 2026-06-17 B001 non-emitting STL-list classification.
- 2026-05-31 cleanup helper range correction:
  - What existed before: the cleanup helper table and references used `0x00457430-0x00457472`.
  - Changed to: `0x00457430-0x00457473`.
  - Summary/evidence: IDA MCP reports `sub_457430` size `0x43`, and disassembly shows the final `retn` at `0x00457472`, making `0x00457473` the correct end-exclusive bound.
- 2026-06-08 A002 Batch129 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`; below the strict parent gate for [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md).
  - After: `COMPLETION:85`, `CONFIDENCE:85`.
  - Summary/evidence: added the parent-gate audit tying the node allocator, payload-node allocator, and state cleanup helper into one shared utility owner. Live IDA MCP reconfirmed the three helper starts and sizes on 2026-06-08, and the exact memory pages document the cross-feature caller/xref spread. This custom-source interpretation was superseded by the 2026-06-17 B001 non-emitting STL-list classification.
