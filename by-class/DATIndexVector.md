*** UID:00003K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

# DATIndexVector

## Status

- Current entity kind: non-reconstructable semantic/compiler overlay for the 0x20-byte MSVC/Dinkumware `stdext::hash_map` implementation state.
- Confidence: very strong for physical layout, method-lowering roles, shared consumer routes, pair/iterator ABI, and the absence of a project source class; exact standard-library-private lexical names remain unavailable.
- Owner/emitter: none. [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a path-`NONE` documentation index, not a source owner.
- Formal CPP/H: intentionally blank. There is no valid `DATIndexVector.cpp`, `DATIndexVector.h`, custom Node/Bucket/InsertResult declaration, or project method body to emit.
- Historical recovered file and Wave2 name: `source-3/simroot_v2/class_DATIndexVector.cpp` / `DATIndexVector.cpp`; retained only as corrected provenance.
- Evidence basis: current live IDA function/type/comment/frame/xref/callee reads, exact body hashes, all MiniMap/Monster/FittingRoom/DAT consumer routes, generated source inspection, and standard-container source precedent.

## 2026-08-17 Compiler Overlay Disposition

The 0x20 binary representation is preserved exactly as analysis evidence: maximum-load float at `+0x00`; embedded list sentinel/count at `+0x04/+0x08`; bucket-vector begin/end/capacity at `+0x0c/+0x10/+0x14`; mask/count at `+0x18/+0x1c`. Those offsets and the insert/find/erase/destructor behavior match the contemporary MSVC/Dinkumware `_Hash` implementation. They do not prove a handwritten `DATIndexVector` class or its historical recovery field names.

`DATIndexVectorNode` and `DATIndexVectorBucket` are semantic views of standard list-node and bucket-range implementation records. `DATIndexVectorInsertResult` is lowering of `std::pair<iterator,bool>`. The hidden result slot used by lookup is iterator-return lowering. Their old declarations are removed from formal H because different consumers instantiate different mapped pointer types and no original UDT, vtable, RTTI, constructor symbol, global, or source symbol supports one concrete project class.

The seven exact compiler-function pages remain independent binary records and keep all ranges, hashes, frames, callers/callees, xrefs, mask/count/list/bucket behavior, and historical names. They are non-emitting and compiler-covered; authored behavior returns to typed consumer-owned `stdext::hash_map` members and ordinary public operations. The former class declaration and method bodies below remain historical assumptions only where explicitly retained in prose.

## Historical Responsibility Model (Superseded)

The following custom-class model is preserved to explain the earlier inference. It is superseded by the compiler-overlay disposition above.

`DATIndexVector` is a reusable keyed bucket/list index helper, not a private `_DATFileMgr` subobject. The current best model is one 0x20-byte object that combines an embedded MSVC-list-style sentinel/count state at `+0x04/+0x08` with a bucket table at `+0x0c/+0x14`.

`ResizeAndFill` does not prove a second value-vector class. It resizes the bucket table as paired dword slots and fills empty bucket `first`/`last` entries with the list head/sentinel stored at `+0x04`. The old `fillValue` wording is therefore an implementation-view alias for `m_listHead`, not evidence for a separate value-vector source type. [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) is the binary lowering for part of that fill, not a standalone source helper to emit. [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) is the private source-facing capacity helper called only from `ResizeAndFill`; its raw allocator/free callees remain runtime lowering.

The class is archive-named and currently routes through [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) to `NexusTK/archive/DATIndexVector.cpp`, but broad caller fanout makes it a standalone helper rather than a private DAT manager subobject. Keep the folder as `archive/` for now because the imported/source-tree route supports it; treat `common/` or `util/` as future folder-only review questions, not ownership blockers.

## Changes

- 2026-08-17 B008 UID0000IP whole-file implementation callback:
  - Reclassified this page from an emitting reconstructable custom class to a `95/95` non-reconstructable compiler overlay with blank owner, emitter, CPP, and H channels.
  - Removed the false `DATIndexVector.cpp/.h` declaration/body route while preserving the exact 0x20 layout, seven lowering roles, consumer spread, ABI evidence, historical declarations, and correction rationale.

- 2026-08-17 B007 UID0000PA complete header-provider closure:
  - Moved the existing node, bucket, insert-result, and exact `0x20` DATIndexVector declarations into a guarded `DATIndexVector.h` payload with its `<cstdint>` dependency and size assertion.
  - `DATIndexVector.cpp` now includes its own header, includes `<stdexcept>` for implementation behavior, and emits exact method/helper children afterward.
  - This header is required because [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) embeds DATIndexVector by value; a forward declaration cannot provide the required complete `0x20` member type.

- 2026-07-09 B001 UID0000XS implementation callback:
  - No metadata change. Added `DATIndexVectorInsertResult { DATIndexVectorNode* node; bool inserted; }` and replaced the stale `DATIndexVectorNode* InsertNode(DATIndexVectorNode* node, bool* inserted)` declaration with `DATIndexVectorInsertResult InsertNode(const int& key, DATIndexVectorNode* node)`. Current B001 MCP session `supervisor_nexustk_20260709` resolves [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) as a result-slot/key-pointer/node ABI method with first-draft formal C++ now present; exact original result-type spelling remains inferred.
- 2026-07-09 B001 UID0004HG implementation callback:
  - No metadata or class C++ change. Added current evidence for [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md): B001 MCP session `supervisor_nexustk_20260709` confirms it remains a private `EnsureBucketSlotCapacity` helper called only by `ResizeAndFill` at `0x00423b34`, with zero data xrefs and zero VA/RVA pointer-byte routes. The helper keeps the accepted source-level `new[]`/`delete[]` lowering and does not change the class declaration or field model.
- 2026-07-05 B005 implementation callback:
  - No metadata change. Replaced the forward-only `DATIndexVectorNode`/`DATIndexVectorBucket` support declarations with concrete source-facing definitions and added private `DATIndexVectorNode* RemoveNodeForInsertUnwind(DATIndexVectorNode* node);` for [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md). The helper now has a first-draft formal private cleanup/unwind body on its target page while the stable documentation label remains unchanged.
- 2026-07-05 B007 implementation callback:
  - No metadata or class C++ change. Added the [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) support caveat from current MCP session `b006-0000xu`: the binary body takes a result slot plus key pointer and returns with `retn 8`; the current pointer-returning declaration remains a source-facing candidate, not a final method-body proof.
- 2026-07-05 B006 implementation callback:
  - No metadata or class C++ change. Added the [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) support note: the destructor is C++-eligible by score/emitter gate but remains a generated empty-marker/no-code target until the embedded list state is accepted as a source-level member model that can regenerate `StdListTidy8ByteList` without hand-emitting compiler/STL support.
- 2026-06-24 B001 accepted source-quality implementation:
  - No metadata or class C++ change. Updated [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) from a private helper row to non-emitting bucket-slot fill lowering used only by `ResizeAndFill`. The source expression belongs in `ResizeAndFill`, while the by-memory page preserves the exact current MCP evidence: two caller sites, no callees, no data/pointer route, and stack fill source copied from `m_listHead`. Preserved the class-level rejected alternatives: separate value-vector class, LinkedList ownership, VectorHelpers ownership, and consumer-specific MiniMap/MonsterImageLib/fitting-room/DAT manager ownership.
- 2026-07-05 B002 implementation callback:
  - Added `#include <stdexcept>` and private declaration `void EnsureBucketSlotCapacity(std::uint32_t requestedSlots);` for the accepted `ResizeAndFill` reconstruction. Added [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) as the one-caller private capacity helper documented by current MCP session `19917133`; paired DWORD slot arithmetic remains documented as low-level compiler/binary representation over source `DATIndexVectorBucket*` fields.
- 2026-06-03: Marked the class reconstructable after the live-verified [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) boundary correction reaffirmed DATIndexVector ownership. Evidence is the existing DATIndexVector class/file documentation plus the 2026-06-03 live IDA boundary correction for `sub_423B00`.

## Methods And Helpers

| Range | Method/helper | Notes |
| --- | --- | --- |
| [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) | non-emitting bucket-slot fill lowering | Used only by `ResizeAndFill` to lower a DWORD bucket-table span fill; in the DATIndexVector caller the fill source is `m_listHead`, so empty bucket `first`/`last` slots receive the sentinel. It remains a binary documentation/search label, not a class method, public helper, VectorHelpers route, or source emitter. The stale `DATIndexVectorFillSlotRaw` filename was renamed after the 2026-06-13 A003 advanced-scan review. |
| [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) | `ResizeAndFill` | Resizes/fills the two-dword bucket table, initializes empty bucket ranges from `m_listHead`, and updates `m_bucketMask`/`m_bucketCount`. A later source-polish pass may rename this `ResizeBuckets` or `ResizeBucketTable`; the current doc name is retained for continuity. |
| [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) | private `EnsureBucketSlotCapacity` helper | Called only by `ResizeAndFill` at `0x00423b34` when requested paired-DWORD bucket-slot capacity exceeds the current capacity. B001 MCP session `supervisor_nexustk_20260709` confirms this one-caller helper has no data xrefs and no VA/RVA pointer-byte route. It preserves active slots, allocates replacement storage, frees old storage through runtime lowering represented in source as `delete[]`, and commits `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`. |
| [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | `InsertNode` | Inserts an intrusive node into a bucket range, coalesces duplicate keys, and rehashes when load factor exceeds `m_maxLoadFactor`. Current B001 MCP evidence resolves the result-slot/key-pointer/node ABI enough for first-draft formal C++; the source-facing declaration is now `DATIndexVectorInsertResult InsertNode(const int& key, DATIndexVectorNode* node)`, with exact original result-type spelling still inferred. |
| [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | private `RemoveNodeForInsertUnwind` cleanup helper | First-draft formal C++ is now present on the target page. It hashes the node key, repairs bucket first/last links, unlinks and frees the node, decrements count, and returns the original next node; IDA shows only the `InsertNode` EH/unwind cleanup block calling it, while the stable documentation name remains `DATIndexVectorRemoveNodeHelper`. |
| [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) | destructor | Frees `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`, clears the bucket allocation triple, then tail-jumps into shared [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) for the embedded list state at `this + 4` (`m_listHead`, `m_nodeCount`). B006 keeps this C++-eligible destructor as an empty marker: the formal body stays blank until the embedded list state is modeled as a source member that can regenerate `StdListTidy8ByteList` without hand-emitting compiler/STL support. |
| [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) | `FindNodeByKey` | Uses the same four-byte FNV-1a hash as `InsertNode` and scans the selected bucket range for an exact integer key. Current MCP session `b006-0000xu` observes a result-slot/key-pointer ABI with both exits `retn 8`; the declaration `DATIndexVectorNode* FindNodeByKey(const int& key) const` remains a source-facing candidate, not final method-body proof. |

## Layout Notes

The current field names are:

| Offset | Field | Type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `m_maxLoadFactor` | `float` | `InsertNode` compares `nodeCount / bucketCount` against this field before rehash. |
| `+0x04` | `m_listHead` | `DATIndexVectorNode*` | Insert/find/remove use this as the intrusive-list sentinel; destructor passes `this + 4` to `StdListTidy8ByteList`; `ResizeAndFill` uses the same dword as the empty-bucket fill value for first/last slots. |
| `+0x08` | `m_nodeCount` | `std::uint32_t` | Insert/remove update this count, and generic list-state cleanup treats `this + 4` as `{ head, count }`. |
| `+0x0c` | `m_bucketsBegin` | `DATIndexVectorBucket*` | Resize/destructor manage the allocation begin; insert/find/remove index buckets from this pointer. |
| `+0x10` | `m_bucketsEnd` | `DATIndexVectorBucket*` | Resize writes the active end after `bucketCount * 2` dword fill. |
| `+0x14` | `m_bucketsCapacity` | `DATIndexVectorBucket*` | Resize/destructor manage the allocation capacity/end pointer. |
| `+0x18` | `m_bucketMask` | `std::uint32_t` | Insert/find/remove mask the FNV-1a hash with this value; `ResizeAndFill` writes `bucketCount - 1`. |
| `+0x1c` | `m_bucketCount` | `std::uint32_t` | Insert computes load factor against this count; `ResizeAndFill` writes the requested bucket count. |

The old `DATIndexVectorLayout { scalar00, fillValue, reserved08, valuesBegin, valuesEnd, valuesCapacity, lastIndex, entryCount }` view is a recovery overlay. Its fields map to the same source object as follows: `scalar00` is `m_maxLoadFactor`, `fillValue` is `m_listHead`, `reserved08` is `m_nodeCount`, `valuesBegin/valuesEnd/valuesCapacity` are `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`, `lastIndex` is `m_bucketMask`, and `entryCount` is `m_bucketCount`. Keep those old names only as historical aliases.

`DATIndexVectorBucket` is the two-pointer `{ first, last }` bucket-table entry allocated and filled by `ResizeAndFill`. Empty `first` and `last` both equal `m_listHead`. `DATIndexVectorNode` is the semantic payload overlay for the 16-byte list node used by the algorithms: `{ next, prev, key, value }`, with `key` as the four-byte value hashed by FNV-1a and `value` left generic because callers use it for different payloads.

Low-level IDA/decompiler views often describe the bucket-table allocation as paired DWORD slots. Preserve the source field types as `DATIndexVectorBucket*`; the paired-DWORD arithmetic is the compiler/binary lowering for `{ first, last }` bucket entries and for the `EnsureBucketSlotCapacity` helper.

## Generic List Boundary

`DATIndexVector` embeds a list state compatible with the non-emitting MSVC/Dinkumware support helpers documented under [UID:0000KR][LinkedList](by-file/LinkedList.md). Those `StdList*` helper bodies should not be emitted as custom DATIndexVector source. `DATIndexVector` owns the keyed FNV-1a bucket algorithms, bucket table state, node/bucket semantic overlays, and destructor storage release before delegating generic list teardown.

Rejected alternatives:

- Separate `DATIndexVectorLayout` value-vector class: rejected. The so-called values are bucket first/last pointer slots; no caller evidence supports a separate `uint32_t` value table with independent semantics.
- Two adjacent helper templates collapsed by recovery: rejected for the class-level model. Resize, insert, remove, find, and destructor use a coherent object layout.
- Moving DATIndexVector children to [UID:0000KR][LinkedList](by-file/LinkedList.md): rejected. `LinkedList` owns only non-emitting compiler/STL helper bodies.
- Consumer-specific ownership under MiniMap, MonsterImageLib, fitting-room, or DAT manager code: rejected. Those callers consume embedded indices and payloads; they do not own the reusable class.

Batch076 parent-gate review treats the exact DATIndexVector method pages as routable to this class because the documented helpers cover the bucket-table resize/fill path, bucket insert/rehash path, insert cleanup/remove helper, destructor storage release, and keyed lookup. The destructor's `this + 1` handoff still belongs to the shared linked-list cleanup page, but the freed `+0x0c/+0x10/+0x14` storage fields and sibling helper evidence are DATIndexVector state.

Support records:

- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)
- [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md)

## Caller Evidence

IDA MCP caller checks on 2026-05-24 showed:

- `ResizeAndFill` callers include fitting-room item-state helpers at `0x00422020`, `0x00422470`, and `0x00423470`, minimap version-manager code at `0x004563c0`, `0x00456480`, `0x00456700`, and `0x00457480`, DAT manager code at `0x0049bd30` and `0x0049ce50`, and monster image library code at `0x004daec0` and `0x004dc2e0`.
- `InsertNode` callers include `MiniMapVersionManager::UpdateHashList` at `0x00456a90`, `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`, and its own rehash path.
- `FindNodeByKey` callers include `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60` and [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) at `0x004570b0`.
- `VectorGrowArchiveIndex` at `0x004e5990` is separate: it grows a monster archive-index array and is called only by `MonsterImageLib::LoadMonsterArchives`.

## Score Rationale

Completion is raised to `88` because the class page now resolves the largest source-quality blocker: `ResizeAndFill` and the bucket/list helpers are one 0x20-byte object, not a split value-vector class. The page records final field names, support struct roles, caller fanout, generic `StdList*` boundary, rejected ownership alternatives, source-placement ranking, and a declaration-level first-draft C++ block.

Confidence is raised to `90` because the method/support docs agree on one object layout and caller fanout supports standalone ownership. It remains below final-source confidence because fresh IDA rename/type edits were not performed in this pass, exact original folder remains `archive/` versus `common/`/`util` reviewable, and per-method body signatures still need final polish.

## File Placement

Current best placement is a standalone [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) source module. It should not be merged into [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), because DAT-manager callers are only part of the caller set. It should also not be treated as a render-owned helper, because archive and non-render callers use the same object shape.

## Open Questions

- Whether the final folder should be `archive/` because of the imported `DATIndexVector.cpp` name, or `common/`/`utility/` because of the broad caller fanout.
- Whether `DATIndexVectorNode` and `DATIndexVectorBucket` were public header declarations, private source structs, or implementation-detail overlays.
- Exact original spelling and public/private visibility of `DATIndexVectorInsertResult`; current B001 evidence resolves the `InsertNode` ABI and formal source declaration, but not the recovered original type name.
- Exact method signature for `FindNodeByKey` key reference/pointer/return form. Current `FindNodeByKey` binary evidence uses a result slot and key pointer with `retn 8`, while the class declaration remains a source-facing pointer-return candidate.

## Cross-References

- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-21 B009 Rule 26 source-quality incorporation:
  - Before: `85/86`, blank C++, and an unresolved value-table/hash-list split caveat.
  - After: `88/90`, with a declaration-level class C++ draft under [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md).
  - Summary/evidence: rechecked the B009 class-source report against the class, file, method, support-struct, generated-output, source-tree, client-container, and prior B-agent list/minimap/DAT evidence. The previous value-table/bucket-list split is resolved as one 0x20-byte object: `ResizeAndFill` operates on two-dword bucket slots, uses the list head at `+0x04` as the empty-bucket fill value, writes `m_bucketMask` at `+0x18`, and writes `m_bucketCount` at `+0x1c`. Field names are now `m_maxLoadFactor`, `m_listHead`, `m_nodeCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount`. Generic `StdList*` helpers remain non-emitting compiler/STL support, while DATIndexVector owns keyed bucket logic and semantic node/bucket overlays.
  - Rejected alternatives: separate value-vector class, fitting-room-only storage, DATFileMgr-private ownership, consumer-specific MiniMap/MonsterImageLib ownership, and moving keyed bucket helpers to the generic [UID:0000KR][LinkedList](by-file/LinkedList.md) support root.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/80`.
  - Summary/evidence: method/helper ranges, layout views, support records, caller fanout, source-placement reasoning, and open questions are documented with IDA caller evidence; at that time the remaining uncertainty was whether the value-table and bucket/list views were one original class or conflated helper shapes. The split question was superseded by the 2026-06-21 B009 incorporation above.

- 2026-06-06 A008 parent-chain pass:
  - Before: [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md) and [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md) pointed at this class, but the class had no autogen parent, leaving both child struct pages blocked by `autogen_parent_unknown`.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), the current standalone `NexusTK/archive/DATIndexVector.cpp` source root.
  - Evidence: [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is assigned to that generated source root at `85/80`; this class is `82/80`; and method/helper ranges, support records, caller fanout, and standalone ownership evidence rule out a private `DATFileMgr` fold. The `archive/` folder and exact layout split remain provisional, so final C++ stays blank.

- 2026-06-07 A007 Batch 076 parent-gate repair:
  - Before: `82/80`; exact DATIndexVector method children could not satisfy the corrected child-and-parent `85/85` assignment gate against this class.
  - After: `85/86`; the exact core method inventory, destructor storage evidence, support struct links, caller fanout, and standalone file parent now support routing exact DATIndexVector method pages here.
  - Evidence: [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md), [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md), [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md), [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md), and [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) document a coherent shared helper while preserving final folder/layout caveats.
