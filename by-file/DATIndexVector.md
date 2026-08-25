*** UID:0000IP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DATIndexVector

## Status

- Current role: reviewed, non-emitting compiler/template-family index; this page is not an original NexusTK source-file owner.
- Current reconstruction path: `NONE`; there is no proposed `DATIndexVector.cpp` or `DATIndexVector.h`.
- Confidence: very strong for the MSVC/Dinkumware `stdext::hash_map` implementation-family classification, exact 0x20 binary overlay, seven compiler-function ranges, caller spread, ABI lowering, and consumer-owned source placement; exact original typedef/include spellings remain inferred.
- Historical recovered file: `source-3/simroot_v2/class_DATIndexVector.cpp`. It is retained only as provenance for the superseded custom-class hypothesis.
- Evidence basis: complete current live IDA function/type/comment/frame/xref/callee reads, exact body hashes, all consumer routes, current by-* documentation, and generated CPP/H inspection.

## 2026-08-17 Compiler Template Family Reclassification

The historical standalone `DATIndexVector` source model is rejected. No `DATIndexVector` UDT, vtable, RTTI, constructor symbol, global object, export, or original source symbol survives in the current IDB. The observed 0x20-byte state is the old MSVC/Dinkumware hash-container implementation layout: maximum-load float, embedded list sentinel/count, bucket-vector begin/end/capacity, mask, and count. The compiler bodies implement standard list/vector/hash operations and are shared or folded across unrelated source owners.

The decisive ownership evidence is the complete caller spread. The bucket initializer at `0x00423b00` has fourteen callers in FittingRoom, MiniMapVersionManager, DATFileMgr, and MonsterImageLib. The insert, find, and destructor bodies are likewise shared by MiniMap and Monster consumers with different mapped pointer types. This is template instantiation and identical-COMDAT folding, not one handwritten project class used through a custom API.

| Exact evidence item | Current source disposition |
| --- | --- |
| [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) | Non-emitting DWORD range-fill lowering, `92/95`; no source owner or formal CPP/H. |
| [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) | Non-emitting shared `_Hash` bucket initialization, `95/97`; no source owner or formal CPP/H. |
| [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) | Non-emitting vector capacity lowering, `92/95`; no source owner or formal CPP/H. |
| [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | Non-emitting `stdext::hash_map<int,T*>::insert`/rehash and `pair<iterator,bool>` return lowering, `94/96`. |
| [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | Non-emitting insertion-unwind/list-node cleanup lowering, `92/95`. |
| [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) | Non-emitting automatic `stdext::hash_map<int,T*>` member destruction, `94/96`. |
| [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) | Non-emitting iterator/result-object lowering for `find`, `94/96`. |
| [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) | Non-reconstructable 0x20 semantic/compiler overlay, `95/95`, blank owner/emitter/formal channels. |
| [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md) | Non-reconstructable two-pointer bucket-range overlay, `93/95`; no project declaration. |
| [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md) | Non-reconstructable list-node semantic overlay, `93/95`; mapped payload varies by consumer. |

Authored source belongs to the real consumers as typed `stdext::hash_map` members and ordinary `find`, `insert`, iteration, `clear`, construction/rehash, and automatic destruction. MiniMapVersionManager owns an `int -> wchar_t *` version index; MonsterImageLib owns separate `int -> DATFile *` and `int -> MonsterArchiveBoundsBucket *` caches; FittingRoom owns its byte-keyed category map; DATFileMgr owns its archive/resolver lookup containers. Source must not reproduce bucket-vector growth, list-node allocation, FNV traversal, hidden pair/iterator result slots, unwind cleanup, or destructor lowering as project APIs.

The current exact physical ranges, bytes, frames, xrefs, callers/callees, mask/count writes, list/bucket layout, result-slot ABI, and historical recovery names remain documented. Old custom class/method/field names are preserved below as superseded analysis, not current source declarations. The validator-generated `NexusTK/archive/DATIndexVector.cpp/.h` projection is therefore a routing defect and must disappear once this path-`NONE` index and all false emitters are refreshed.

## Historical Proposed Contents (Superseded)

The following table preserves the earlier custom-source proposal as historical analysis. It is superseded by the compiler/template-family disposition above and must not drive source emission.

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) | discontiguous | `archive/DATIndexVector.cpp` | FNV-1a keyed intrusive hash/list plus bucket-table resize/fill helper. |
| [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md) | type-only | `archive/DATIndexVector.h` or private source struct | Intrusive node: next, prev, integer key, payload pointer. |
| [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md) | type-only | `archive/DATIndexVector.h` or private source struct | Per-bucket first/last pair over the shared intrusive list. |
| [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) | `0x00423c50-0x00423cf6` | private `DATIndexVector.cpp` helper | One-caller capacity helper for `ResizeAndFill`; preserves active paired-DWORD bucket slots and commits the bucket storage triple. B001 MCP session `supervisor_nexustk_20260709` reconfirms the single caller at `0x00423b34`, zero data/pointer route, and unchanged generated `EnsureBucketSlotCapacity` body in this file route. |
| `RemoveNodeForInsertUnwind` / private remove helper | `0x00457310-0x004573b3` | `archive/DATIndexVector.cpp` internal helper | First-draft formal C++ is now present on [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md); detaches/frees one keyed node, returns the original next node, and remains called only by the `DATIndexVector::InsertNode` EH/unwind cleanup block. |

## Historical Method Ranges (Superseded Source Ownership)

The ranges and behavior remain valid binary evidence. Their custom `DATIndexVector::*` source assignments below are historical aliases superseded by the non-emitting dispositions above.

| Range | Symbol | Role |
| --- | --- | --- |
| [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) | non-emitting bucket-slot fill lowering | Binary lowering for a DWORD bucket-table span fill called only by `DATIndexVector::ResizeAndFill`; source-level fill belongs in `ResizeAndFill`, and this range should not emit a standalone helper or empty marker. Renamed from stale `DATIndexVectorFillSlotRaw` during the 2026-06-13 A003 advanced-scan repair. |
| [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) | `DATIndexVector::ResizeAndFill` | Bucket-table capacity/initialization helper; now has formal C++ after Agent-B002 documented the one-caller capacity helper. Fills empty bucket first/last slots from the list head sentinel and writes `m_bucketMask`/`m_bucketCount`. |
| [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) | `DATIndexVector::EnsureBucketSlotCapacity` | Private capacity helper called only by `ResizeAndFill` at `0x00423b34`; source-level body preserves active bucket slots, allocates replacement storage, frees old storage through runtime lowering represented as `delete[]`, and commits begin/end/capacity. Current B001 evidence adds zero data xrefs, zero VA/RVA pointer-byte matches, and unchanged generated routing through `NexusTK/archive/DATIndexVector.cpp`. |
| [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | `DATIndexVector::InsertNode` | Bucket/list insert, duplicate collapse, and load-factor rehash. Current B001 MCP session `supervisor_nexustk_20260709` resolves the result-slot/key-pointer/node ABI, so this file route now uses `DATIndexVectorInsertResult InsertNode(const int& key, DATIndexVectorNode* node)` and the target page carries first-draft formal C++. |
| [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | `DATIndexVector::RemoveNodeForInsertUnwind` | Private cleanup/unwind helper with first-draft formal C++; hashes the key, repairs bucket/list links, decrements count, frees the node, and returns the original next pointer for the `InsertNode` EH cleanup path. |
| [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) | `DATIndexVector::~DATIndexVector` | Frees `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`, clears the bucket storage triple, and tail-cleans the embedded list state. B006 keeps this score/emitter-eligible method as an empty marker until the embedded list state is accepted as a source member model that can regenerate `StdListTidy8ByteList` without hand-emitting compiler/STL support. |
| [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) | `DATIndexVector::FindNodeByKey` | Key lookup in selected bucket range. Current MCP session `b006-0000xu` observes a result-slot/key-pointer ABI with `retn 8`; keep the method in `DATIndexVector.cpp`, but treat the pointer-returning declaration as a source-facing candidate until the class API chooses the final return wrapper. |

## Historical File-Level Rationale (Superseded)

The material in this section records how the former standalone hypothesis was reached. Its source-owner/folder conclusions are superseded; retained caller and layout facts remain valid.

The helper is used by several subsystems:

- DAT manager construction and `_DATFileMgr::InsertOrFindEntry`.
- `MiniMapVersionManager` initialization, teardown, and hash-list updates.
- `MonsterImageLib` archive/bounds lookup paths.
- Fitting-room item-state list/vector helpers.

That caller mix rules out a manager-private placement in [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). The imported source name `DATIndexVector.cpp` and DAT-manager use still make `archive/DATIndexVector.cpp` a reasonable first placement, but the final folder should remain reviewable if more non-DAT users are recovered.

Because this helper has non-DAT callers, it is also tracked in [UID:0001QA][client_containers](by-meta/client_containers.md) as a possible utility-container candidate. Generic sentinel-list allocation and cleanup support is tracked separately in [UID:0000KR][LinkedList](by-file/LinkedList.md); keep only DATIndexVector's bucket-aware keyed helpers here.

The B009 source-quality recheck resolves the old value-table/hash-view split as one object. `ResizeAndFill` manages the bucket table as paired dword entries, fills empty bucket `first`/`last` pointers with the list head sentinel at object offset `+0x04`, writes `m_bucketMask = bucketCount - 1` at `+0x18`, and writes `m_bucketCount = bucketCount` at `+0x1c`. The old `fillValue`/`valuesBegin`/`lastIndex` names are historical recovery aliases for `m_listHead`, `m_bucketsBegin`, and `m_bucketMask`, not a separate source class.

2026-06-24 B001 source-quality implementation updates [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) to non-emitting fill lowering. Current MCP session `80de0a67` confirms the exact `0x75`-byte body, two call sites inside `ResizeAndFill`, no callees, no data xrefs, no VA/RVA pointer-byte route, and stack fill source copied from `m_listHead`. Normal autogen should stop outputting an empty marker for [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) once the target's emitter route is cleared; the source-level bucket-table fill remains represented by `DATIndexVector::ResizeAndFill`.

2026-07-05 B002 implementation adds [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) as the private capacity helper needed by [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md). Current MCP session `19917133` confirms the helper is `sub_423C50`, size `0xa6` / 166 bytes (Verified with `tools/int_convert.py`), with exactly one caller at `0x00423b34` inside `ResizeAndFill`, and raw allocator/free callees treated as runtime lowering. The formal `ResizeAndFill` body now routes through this helper while [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) remains non-emitting fill lowering.

2026-07-09 B001 implementation resolves the [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) method-body blocker for this file route. Current MCP session `supervisor_nexustk_20260709` confirms `sub_457100` uses a caller-owned result slot, a key pointer, and a node pointer; the class/file declaration now uses the source-facing `DATIndexVectorInsertResult InsertNode(const int& key, DATIndexVectorNode* node)` form, and the target page carries first-draft formal C++ for duplicate collapse, bucket first/last repair, load-factor growth through `ResizeAndFill`, self-reinsertion, and `RemoveNodeForInsertUnwind` cleanup. The exact original result-type spelling and header visibility remain inferred source-polish questions, not a reason to keep UID0000XS blank.

2026-07-05 B007 implementation adds the current [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) ABI caveat. MCP session `b006-0000xu` observes a result slot plus key pointer and both exits `retn 8`, while generated output still prints a pointer-returning declaration and an empty marker for this UID. This affects the future method-body shape only; it does not move the method out of `DATIndexVector.cpp`.

2026-05-31 IDA MCP recheck confirms the resize/fill helper at `0x00423b00`, insert/remove/destructor/find helpers at `0x00457100`, `0x00457310`, `0x004573d0`, and `0x00457580`, and caller fan-in from DAT manager code plus minimap, fitting-room, and monster-image code. This supports a standalone source file and rules out folding the helper into `DATFileMgr.cpp`; the `NexusTK/archive/` projected path follows current proposed-source-tree ownership but remains reviewable if later evidence proves the original project placed it in a common container folder.

Batch076 parent-gate review raises the file to `86/85` for routing purposes: every current exact DATIndexVector method page is documented at `85+` completion and high confidence, and the class page now captures the shared object identity, support structs, and linked-list boundary. The confidence cap remains the projected `archive/` folder and final public/private header split, not the standalone ownership itself.

2026-06-16 A001 live IDA refresh keeps the standalone decision strong. `lookup_funcs` reports semantic names and exact sizes for the current method set: `DATIndexVectorFillValueRangeHelper` `0x004233f0` size `0x75`, `DATIndexVectorResizeAndFill` `0x00423b00` size `0x13d`, `DATIndexVectorInsertNode` `0x00457100` size `0x20f`, `DATIndexVectorRemoveNodeHelper` `0x00457310` size `0xa3`, `DATIndexVectorDestructor` `0x004573d0` size `0x59`, and `DATIndexVectorFindNodeByKey` `0x00457580` size `0x93`.

The current caller summary still rules out folding the helper into one DAT manager source file: `ResizeAndFill` is reached from fitting-room/category storage, `MiniMapVersionManager`, DAT manager code, and `MonsterImageLib`; `InsertNode` is reached by minimap hash updates, monster-image bounds lookup, and its own rehash path; `FindNodeByKey` is reached by minimap and monster-image lookup paths. `xrefs_to 0x00457310` reports exactly one caller site from `DATIndexVectorInsertNode` at `0x00457301`, preserving the private cleanup/EH-helper interpretation rather than promoting a public erase API.

Remaining source-quality blockers were checked and narrowed: IDA/docs prove the helper identity, method set, field layout, and unified bucket/list object. They still do not prove whether the original folder was `archive/` or a common container folder, or whether `DATIndexVectorNode`/`DATIndexVectorBucket` were public header declarations or private source structs.

## Exclusions

Do not place these here:

- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md): only called by `DATFile::ReadAllEntries` and `ReadAllEntriesAlt`, so it remains with [UID:0000IN][DATFile](by-file/DATFile.md) as private/static-style support.
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md) if created later: IDA shows it is called only by `MonsterImageLib::LoadMonsterArchives`, so current ownership leans [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), not this helper.
- `_DATFileMgr` resolver/string lookup methods: those remain [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) internal manager code.

## Historical Migration Notes (Superseded)

The former Wave3 rename/migration commands were removed from active documentation because Wave2/Wave3 workflows are obsolete and the proposed standalone source route proved invalid. The value-table/bucket-table split still resolves as one binary bucket/list implementation overlay, but `0x00457310` is compiler-generated insertion-unwind cleanup rather than private project source.

## Historical Open Questions (Resolved)

- Folder/file: closed as no standalone project source file; path is `NONE`.
- Node/Bucket/InsertResult visibility: closed as compiler-private standard-library representations; no project declarations are emitted.
- Find return form: closed as standard iterator/result-object return lowering; no raw-node project API is emitted.
- Exact original consumer typedef and include spellings remain lexically unrecoverable. Use descriptive owner-local aliases; this is the documented confidence cap, not an implementation blocker.

## Cross-References

- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-08-17 B008 UID0000IP whole-file implementation callback:
  - Reclassified this page to a reviewed path-`NONE`, non-emitting compiler/template-family index at `96/95` while preserving `CANONICAL_OWNER:FILE`.
  - Recorded the complete seven-function, class/struct-overlay, consumer, generated-defect, ownership, source-placement, no-code, score, and historical-correction audit.
  - Rejected the former custom `DATIndexVector.cpp/.h` route and removed obsolete executable Wave3 migration material from active guidance; all valid binary details remain preserved as evidence/history.

- 2026-08-17 B007 UID0000PA header-provider closure:
  - Added the missing complete `DATIndexVector.h` route through [UID:00003K][DATIndexVector](by-class/DATIndexVector.md). The header contains node/bucket/result support types, the exact `0x20` container declaration, methods/private helpers, members, and compile-time size check.
  - `DATIndexVector.cpp` now includes that header before `<stdexcept>` and all exact implementation children. The split prevents duplicate declarations and supplies a complete type to MiniMapVersionManager's by-value member.
  - Ownership and behavior remain in the archive utility file; the minimap consumer does not absorb or duplicate the container implementation.

- 2026-07-09 B001 UID0000XS implementation callback:
  - No path or file score change. Updated [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) in the method-range/source-context notes after target C++ insertion: current MCP session `supervisor_nexustk_20260709` resolves the result-slot/key-pointer/node ABI, the class declaration now uses `DATIndexVectorInsertResult InsertNode(const int& key, DATIndexVectorNode* node)`, and the target formal body covers FNV-1a insert, duplicate collapse, bucket/list repair, load-factor rehash, and `RemoveNodeForInsertUnwind` EH cleanup.
- 2026-07-09 B001 UID0004HG implementation callback:
  - No path or file score change. Added current support evidence for [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md): B001 MCP session `supervisor_nexustk_20260709` confirms the helper remains a private `DATIndexVector.cpp` capacity method, called only from `ResizeAndFill` at `0x00423b34`, with zero data xrefs and zero VA/RVA pointer-byte route. Generated output already includes the accepted `DATIndexVector::EnsureBucketSlotCapacity` formal body; raw allocator/free callees remain runtime lowering.
- 2026-07-05 B005 implementation callback:
  - No score or path change. Updated the [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) proposed-content and method-range rows after target C++ insertion: the accepted private source-facing helper is `DATIndexVector::RemoveNodeForInsertUnwind`, still only an `InsertNode` EH/unwind cleanup helper and not a public erase API.
- 2026-07-05 B007 implementation callback:
  - No metadata or path change. Added the [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) support caveat from current MCP session `b006-0000xu`: the binary body takes a result slot plus key pointer and returns with `retn 8`; the current pointer-returning declaration remains a source-facing candidate, not a final method-body proof or reason to move the method out of `DATIndexVector.cpp`.
- 2026-07-05 B006 implementation callback:
  - No metadata or path change. Added the [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) support note: the method is C++-eligible by score/emitter gate but remains a generated empty-marker/no-code target until the embedded list state is accepted as a source-level member model that can regenerate `StdListTidy8ByteList` without hand-emitting compiler/STL support.
- 2026-07-05 B002 implementation callback:
  - No path or file score change. Added [UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) to proposed contents and method ranges as the private capacity helper for [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md). Updated the `0000WW` row to state that formal C++ is now present after helper support was documented. Evidence is Agent-B002 current MCP session `19917133`: helper size `0xa6` / 166 bytes (Verified with `tools/int_convert.py`), only caller `0x00423b34`, allocation/copy/free/commit behavior, and runtime allocation/free callees treated as lowering.
- 2026-06-24 B001 accepted source-quality implementation:
  - No metadata/path change. Updated [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) in the method-range table from a private fill helper to non-emitting bucket-slot fill lowering used only by `ResizeAndFill`. Added generated-output handling: once target emitters are blank, [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) should not produce a standalone body or empty marker; `ResizeAndFill` owns the source-level fill. Rejected standalone helper, VectorHelpers, LinkedList/STL-list, and caller-specific owners remain preserved through the target/class docs.
- 2026-06-21 B009 Rule 26 source-quality incorporation:
  - Scores raised from `87/87` to `88/88`.
  - Evidence: B009 reconciled the class/file/method/support-struct documentation and generated output. The old value-table/hash-view split now resolves as one 0x20-byte DATIndexVector object: `ResizeAndFill` operates on two-dword bucket entries, fills empty bucket first/last pointers with the list head sentinel, and updates `m_bucketMask`/`m_bucketCount`. The file remains a standalone `NexusTK/archive/DATIndexVector.cpp` route because the imported source name and DAT-manager use are strong, while broad fitting-room/minimap/DAT/MonsterImageLib caller fanout rules out a private DAT manager or consumer-owned file. Generic `StdList*` helpers remain non-emitting [UID:0000KR][LinkedList](by-file/LinkedList.md) support.
  - Remaining caveats: final folder/header choice and public/private visibility of `DATIndexVectorNode`/`DATIndexVectorBucket`; these are source-polish questions, not class identity blockers.

- 2026-06-16 A001 low-confidence file refresh:
  - Scores raised from `86/85` to `87/87`.
  - Evidence: live IDA MCP reconfirmed all six exact function starts/sizes, broad non-DAT caller fanout, and the single `InsertNode` cleanup xref to `DATIndexVectorRemoveNodeHelper`.
  - Historical blocker state at that time: final folder/header choice, field names, and value-table versus hash-view source declarations remained unresolved source-facing questions, so owner/path metadata was unchanged and no final C++ was added. The value-table/hash-view issue was superseded by the 2026-06-21 B009 incorporation above.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: helper contents, method ranges, caller fanout, file-level rationale, exclusions, migration notes, open naming/folder questions, and archive/container cross-references are documented; confidence is medium-high because standalone ownership is strong but exact original folder/name remains uncertain.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `84/78`, and module/header paths used `archive/` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`, scores `85/80`, and proposed paths `NexusTK/archive/DATIndexVector.cpp/.h`.
  - Summary/evidence: IDA MCP reconfirmed exact helper starts and broad non-DAT caller fan-in. The path is assigned to match current `proposed-source-tree.md`, but the confidence remains below high because a future common-container folder remains plausible. No C++ reconstruction code is emitted yet because method rewrites, field names, and original folder confidence are below the `95+` final-code gate.

- 2026-06-07 A007 Batch 076 parent-gate repair:
  - What existed before: `85/80`; the standalone file was plausible but below the corrected `85/85` confidence gate for class/file routing.
  - Changed to: `86/85`.
  - Summary/evidence: exact method pages for resize/fill, insert, remove cleanup, destructor, and find now form a coherent DATIndexVector method inventory with broad non-DAT caller fan-in and a clear boundary against generic linked-list cleanup. The `archive/` folder remains provisional, so no C++ reconstruction code is emitted.

- 2026-06-07 A007 Batch 087 range-reference repair:
  - What existed before: the proposed-contents row for the private remove helper still used stale end-exclusive range `0x00457310-0x004573b2`.
  - Changed to: `0x00457310-0x004573b3`, matching [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md).
  - Summary/evidence: no score change; this only syncs the file-level inventory with the exact already-documented helper boundary.
