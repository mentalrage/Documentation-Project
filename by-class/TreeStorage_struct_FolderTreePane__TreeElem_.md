*** UID:0000FC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004YK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeNode<T> is a header-only template emitted through Tree.h. Concrete
// compiler-generated std::vector support remains consumer-owned.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
struct TreeNode
{
    TreeNode()
        : parentIndex(-1), firstChildIndex(-1), lastChildIndex(-1),
          previousSiblingIndex(-1), nextSiblingIndex(-1), disabled(0) {}

    int parentIndex;
    int firstChildIndex;
    int lastChildIndex;
    int previousSiblingIndex;
    int nextSiblingIndex;
    T data;
    unsigned char disabled;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TreeStorage_struct_FolderTreePane__TreeElem_

## Current Accepted UID0004YK Source Reclassification

This page now contributes only TreeNode<T> at Tree.h position 10. The node constructor writes all five link indices as -1 and disabled as 0 while deliberately omitting data from the initializer list: class payloads default-construct and pointer payloads remain uninitialized, matching the two concrete instances. The 0x24 Folder stride and 0x1c Event stride place data at +0x14 and disabled immediately after the payload, with only implicit alignment padding.

TreeStorage<T> is not authored source. Its three-pointer analysis UDTs describe the observed std::vector<TreeNode<T> > object representation, and the concrete insert/copy/destroy/free bodies are compiler/library lowering. Historical sections retaining the former wrapper are superseded evidence, not current source direction.

## Status

- Confidence: strong for helper responsibility, live method boundaries, 36-byte record storage, grow/destruction behavior, and the resolved UID0004YK shared owner; the generated filename and exact private token spellings remain historical/inferred.
- Source file: [UID:0004YK][Tree](by-file/Tree.md), emitted through `NexusTK/util/Tree.h`.
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), with exact 36-byte support children [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md), [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md)
- Parent attachment: [UID:0004YK][Tree](by-file/Tree.md) is the canonical `NexusTK/util/Tree.h` owner. [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is the concrete Folder consumer and binary-evidence attachment, not the generic source owner.

## Class Purpose

This page emits the generic `TreeNode<T>` declaration. Its generated `TreeStorage_struct_FolderTreePane__TreeElem_` filename remains a stable lookup alias for the concrete three-pointer vector-analysis history, but there is no authored `TreeStorage<T>` class. `Tree<FolderTreePane::TreeElem>` directly stores contiguous 36-byte `TreeNode<FolderTreePane::TreeElem>` records in `std::vector`; insert/grow/destruction bodies are compiler/library support and the nested payload itself is 12 bytes.

## Historical 2026-06-30 B010 Formal Storage Shell And Empty-Emitter Cleanup

B010's accepted [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) empty-emitter family implementation inserts the formal `TreeStorage<T>` declaration shell, keeps `CANONICAL_OWNER:0000JG` and `EMITTER_UIDS:0000JG`, and raises this page from `85/86` to `87/89`. The shell records the accepted source-facing storage pointer names `m_begin`, `m_end`, and `m_capacity`, the `InsertAt` declaration, and index operators required by existing emitted tree methods.

The `[[CHILDREN]]` route is intentional. Exact helper pages such as [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md), [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md), range-copy, range-destroy, and vector-storage-free support are compiler-lowered storage operations that should surface through the storage declaration instead of being hand-authored as standalone bodies.

Current MCP session `supervisor_resume_20260629` did not introduce any owner transfer or shared-source-file proof. The direct concrete route remains [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md); a future shared `TreeStorage<T>` header remains a factoring caveat only.

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis keeps the source-facing type as `TreeStorage<FolderTreePane::TreeElem>` and treats the generated page name as an alias only. The storage is a project-local template/support declaration attached to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not a standalone original source file.

`InsertAt` and the destructor operate on 36-byte `FolderTreePane::TreeElem` records. The accepted record names are `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `name`, `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and final `hidden`; storage relocation copies the link dwords, copy-constructs/destroys `SimpleUString` at `+0x14`, preserves row/depth and `hidden`, and omits reserved bytes. Path/paint/iterator readers skip nonzero hidden records, while reset/new construction initializes zero. `isHidden` is superseded history, `visibleTraversalSkip` descriptive only, and deletion aliases rejected. Exact storage-member names and reusable header factoring remain inferred.

B009's accepted [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation uses `m_begin`, `m_end`, and `m_capacity` as the current source-facing names for the three storage pointers. The reset method destroys names over `[m_begin, m_end)`, rewinds `m_end` to `m_begin`, then either copy-constructs the root into the available slot and increments `m_end`, or calls `InsertAt(m_end, root)` when `m_end == m_capacity`. That fast/slow append relationship is behavior-backed; the exact original member spelling remains inferred.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| vector grow/insert | [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) | Compiler-covered `std::vector<TreeNode<FolderTreePane::TreeElem> >` lowering caused by generic insertion in UID0004YK `Tree.h`. The body uses the begin/end/capacity pointer triplet, 36-byte node stride, old-capacity-plus-half growth clamped to `oldSize + 1`, capacity limit `0x71c71c7`, aligned allocation/free validation, [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) single-record copy construction, [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) prefix/suffix range-copy construction, [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) old-name/range cleanup, and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) storage release. No authored storage helper body or Folder-local generic source route exists. |
| single-record copy construction support | [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) | Marker-only compiler-emitted `FolderTreePane::TreeElem` copy-constructor support used by `InsertAt` and reset fast paths. It copies the five link dwords, copy-constructs `name` at `+0x14`, copies row/depth words and flag bytes, leaves reserved padding uncopied, and routes source through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md), not through a standalone storage-owned helper body. |
| range destroy support | [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) | Compiler-emitted 36-byte range cleanup called from insertion/relocation; releases the embedded name at `+0x14`. |
| range copy support | [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) | Compiler-emitted 36-byte range copy construction for link dwords, name, row/depth words, and flags. |
| vector-storage free support | [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) | Compiler-emitted storage free with MSVC large-allocation validation for `36 * count` bytes. |
| vector destructor | [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) | Compiler-covered `std::vector<TreeNode<FolderTreePane::TreeElem> >` destruction caused by the direct member in UID0004YK `Tree.h`. The body walks 36-byte records, destroys each node payload name at `+0x14`, validates/frees vector storage, and zeros begin/end/capacity; no standalone handwritten body is authored. |

## Historical Binary Evidence Under Superseded TreeStorage Analysis Label

Every `TreeStorage` spelling below is retained verbatim as a dated analysis label or earlier source hypothesis. It does not assert an authored `TreeStorage<T>` class, current Folder-local ownership, or a source-facing helper body; the current source is UID0004YK `Tree.h` with direct `std::vector<TreeNode<T> >` storage.

- 2026-06-04 live IDA MCP reports exact ranges `0x004b3d50-0x004b3fa4` for `InsertAt` and `0x004b56e0-0x004b575f` for the storage destructor.
- IDA reports `InsertAt` callers at `0x004b227f`, `0x004b23d8`, and `0x004b5b8f`, tying insertion to FolderTreePane population/reset paths. The storage destructor has five code xrefs, including cleanup/destructor paths at `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`.
- Live decompilation of `InsertAt` computes indexes and capacity using a 36-byte stride, grows capacity by the existing-capacity-plus-half pattern, uses aligned allocation for large buffers, calls `0x004b55e0` to copy-construct records, and destroys old `SimpleUString` names during relocation.
- Live decompilation of the storage destructor walks records by nine dwords per element, destroys the `SimpleUString` at record offset `+0x14`, validates aligned allocation headers for large buffers, frees storage, and clears begin/end/capacity pointers.
- 2026-06-08 A009 Batch117 rechecked the direct parent chain against the current scores: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is `89/85`, [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) is `85/89`, and this concrete storage class is the immediate class owner for [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md).
- 2026-06-26 B009 split evidence: [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) walks 36-byte records and destroys `record + 0x14`, [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) copy-constructs the five link/state dwords plus name/row/depth/flags, and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) frees `36 * count` storage with the same aligned-allocation validation used by the storage destructor.
- 2026-06-28 B009 accepted reset evidence: MCP session/database `agent_b009_0002my_20260628` shows [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) calling `InsertAt` only on the full-capacity branch at `0x004b5b8f`; otherwise it copy-constructs through `0x004b55e0` and advances `m_end` by one 36-byte record. This ties the storage pointer triple directly to the reset method's formal C++.
- 2026-06-29 B010 accepted [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) evidence under restored MCP session `992d23de` resolves the single-record copy helper as marker-only compiler support through [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md). `lookup_funcs` confirms range `0x004b55e0-0x004b564d` and size `0x6d`; xrefs are `0x004b2271`, `0x004b23ca`, `0x004b3e72`, `0x004b3ea7`, and `0x004b5b81`; the sole direct callee is `0x00582a90`; decompile/disassembly copy dwords `+0x00..+0x10`, name at `+0x14`, words `+0x18/+0x1a`, and bytes `+0x1c/+0x1d/+0x20`; and reserved bytes `+0x1e/+0x1f` / `+0x21-+0x23` are not copied. This is distinct from [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) range-copy support, which repeats the same field set over multiple records.
- 2026-06-28 B006 accepted [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) evidence: original MCP session `supervisor_20260628_resume` and resumed active session `agent_b009_0002my_20260628` both report `sub_4B3D50` as range `0x004b3d50-0x004b3fa4`, size `0x254`, with three callers from lazy expansion/reset capacity-exhaustion paths. The target decompile/disassembly confirm `begin`, `end`, and `capacity` pointer roles, 36-byte stride, capacity limit `0x71c71c7`, `oldCapacity + oldCapacity/2` growth, large-block `0x1000`/`+0x23`/32-byte alignment validation, inserted-element copy through [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md), range-copy through [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), old-name cleanup through `sub_582B70`, and old-storage release through [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md). Type checks found no original IDA UDTs for `TreeStorage`, `TreeElem`, or `FolderTreePane`, so this page keeps source-facing storage roles without pretending exact original member names are recovered.
- Full-body `InsertAt` C++ remains intentionally rejected for source quality: a literal body would have to hand-port compiler-lowered allocation, relocation, EH cleanup, range-copy, destructor, and free-validation mechanics. The formal marker on [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) documents that emitted source is covered by this `TreeStorage<FolderTreePane::TreeElem>` declaration/source route instead of leaving the target as an empty emitter.
- 2026-06-29 B013 accepted [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) evidence: current MCP session `07c55da0` reports server health OK and `sub_4B56E0` as range `0x004b56e0-0x004b575f`, size `0x7f`; `0x004b575f` is not a function and successor `0x004b5760` is separate. Current xrefs are `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`, reducing to constructor/EH cleanup, `Tree<FolderTreePane::TreeElem>` destruction, and outer `FolderTreePane` destruction. The target disassembly/decompilation confirms 36-byte record stride, `+0x14` name destruction, `0x1000`/`0x1f` large-allocation validation, free through `sub_5C7526`, and zeroing of begin/end/capacity; `search_structs` still finds no original UDTs for `TreeStorage`, `TreeElem`, or `FolderTreePane`. Full-body destructor C++ remains intentionally rejected for source quality for the same compiler-lowered storage-support reasons as `InsertAt`; the formal marker on UID0002MX documents that emitted source is covered by this `TreeStorage<FolderTreePane::TreeElem>` declaration/source route.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Exact InsertAt/destructor support, 36-byte full-node storage role, caller/xrefs, allocation/destruction behavior, node/payload field-copy model, shared route, and template context are documented. |
| Confidence | 93 | Method boundaries, xrefs, dual-instantiation storage layout, copied state, and shared ownership agree; exact original private spelling remains inferred. |
| Assignment | [UID:0004YK][Tree](by-file/Tree.md) | `Tree.h` owns `TreeNode<T>` and the direct vector member/algorithms; FolderTreePane supplies only the concrete payload, policies, callers, and binary instantiation evidence. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md)
- [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md)
- [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md)
- [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)

## Historical Superseded 2026-07-29 UID0002MZ Node And Storage Reconciliation

- The 12-byte storage header contains begin/end/capacity pointers to `TreeNode<T>`, not bare payload `T`; indexed access returns a node reference.
- `TreeNode<T>` owns `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, `T data`, and `disabled`. FolderTree nodes are `0x24`; EventDispatcher pointer-payload nodes are `0x1c`.
- Existing insert/grow/copy/range-destroy/range-copy/free evidence remains valid. Its 36-byte stride describes full `TreeNode<FolderTreePane::TreeElem>` records; the pointer-backed name is reached as `node.data.name` at concrete `+0x14`.
- Historical assumption: the former declaration stored bare `T` and described the full record as `FolderTreePane::TreeElem`. Cross-specialization sizes and iterator/state offsets disprove that model; it remains only as superseded reconstruction history.
- Formal CPP is blank because these are header templates. Formal H contains the destination-ready declaration and child route.
- Supervisor Gate 2B catalog entry `0365` now realizes the same analysis chain in IDA: exact `FolderTreePaneTreeNode` size `0x24`, exact `FolderTreePaneTreeStorage` size `0x0c` with typed begin/end/capacity pointers, and exact `FolderTreePaneTree` size `0x10` with typed storage at `+0x04`. Current iterator decompilation reaches `m_storage.m_begin` and named link/state members.
- U02/U03 required explicit `__declspec(align(4))` only in IDA's declarations to materialize their implicit tails; no synthetic padding members were introduced. Formal human C++ remains natural-alignment template source and does not adopt IDA-only syntax. Saved IDB `412DA7E8...519CD` supersedes the older absent-UDT snapshots, which remain historical evidence about unrecovered original symbols.

## Changes

### 2026-08-24 UID0004YK Gate 2A Analysis-Alias Correction

- This page's stable generated filename remains an analysis lookup alias, but current authored source is `TreeNode<T>` in UID0004YK `Tree.h`; `Tree<T>` directly owns `std::vector<TreeNode<T> >`. Concrete begin/end/capacity layouts and insert/copy/destroy/free bodies remain vector compiler/library evidence, not an authored `TreeStorage<T>` class or FolderTreePane source route.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below preserve exact binary and validation history. Any source-owner, formal-shell, future-shared-header, or FolderTreePane.cpp conclusion for `TreeStorage<T>` is superseded by the current analysis-alias/direct-vector disposition above.

- 2026-07-14 B001 UID0002N0 hidden-state synchronization:
  - Preserved `87/89`, owner/emitter UID0000JG, reconstructable true, the complete formal storage block, and every unrelated insert/destructor/range helper fact.
  - Finalized copied record state as `hidden`, including nonzero visibility reads, zero initialization, single/range-copy preservation, reserved-byte exclusions, historical `isHidden`, descriptive `visibleTraversalSkip`, and rejected deletion aliases.
  - Corrected the score-rationale table to the already-current metadata without changing metadata or route.

- 2026-06-29 B010 [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation sync:
  - Score unchanged at `85/86`.
  - Added UID0002MW as single-record copy-construction support used by storage insertion and reset fast paths, distinct from UID000449 range-copy support. Source ownership remains the nested [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md); this storage page documents the caller/support route rather than taking direct ownership.
  - Evidence: B010 restored MCP session `992d23de` confirmed the helper boundary, five refs, sole `SimpleUString` callee, copied-field set, non-copied reserved padding, and marker-only/no-standalone-body disposition.

- 2026-06-29 B013 [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) implementation sync:
  - Score unchanged at `85/86`.
  - Updated the destructor method row and evidence notes so UID0002MX is no longer an unresolved empty emitter. It now carries a marker-only covered-by disposition through this storage class and the current [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) concrete-template route.
  - Evidence: B013 current MCP session `07c55da0` confirmed the destructor boundary, caller categories, callee set, 36-byte stride, `+0x14` name destruction, large-allocation validation/free behavior, begin/end/capacity zeroing, missing original UDTs, and rejected full-body / alternate-owner / non-emitting dispositions.

- 2026-06-28 B006 [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) implementation sync:
  - Score unchanged at `85/86`.
  - Updated `InsertAt` from unresolved blank formal wording to marker-only source-routed grow-insert support under this storage class.
  - Evidence: B006 MCP passes `supervisor_20260628_resume` and `agent_b009_0002my_20260628` confirmed the three-pointer storage roles, 36-byte stride, capacity/growth math, copy/range-copy/range-destroy/free helper use, three capacity-exhaustion callers, absent original UDTs, and full-body no-code proof.

- 2026-06-28 B009 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync:
  - Score unchanged at `85/86`.
  - Added reset-method evidence for the storage pointer names `m_begin`, `m_end`, and `m_capacity`, plus the direct append relationship: reset rewinds `m_end`, copy-constructs into available capacity, and calls `InsertAt` only for the full-capacity slow path.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirmed the `0x004b5b00` decompilation/disassembly, callee fan-out to `0x004b55e0` and `0x004b3d50`, and xrefs placing `InsertAt` calls both in folder expansion and reset.

- 2026-06-26 B009 [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) support sync:
  - Score unchanged.
  - Added exact 36-byte range-destroy, range-copy, and vector-storage free child pages [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) under the `TreeStorage<FolderTreePane::TreeElem>` source route.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the insert/grow/destructor behavior, 36-byte tree-record ownership, FolderTreePane memory/type cross-references, and medium confidence on exact original template spelling.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed exact `InsertAt` and destructor boundaries, caller sets, 36-byte storage stride, grow/allocation behavior, record copy construction, `SimpleUString` cleanup at offset `+0x14`, and `FolderTreePane` ownership through the surrounding tree-template aggregate.
  - Remaining limits: scores stay below final-source level because exact original template spelling/header factoring and final field/member names remain inferred.
- 2026-06-08 A009 Batch117 parent-gate refresh:
  - What existed before: score `82/84`, with stale direct-parent gate evidence even though the direct `FolderTreePane` file and template pages had since been refreshed.
  - Changed to: score `85/86`, retained `AUTOGEN_PARENT_UID:0000JG`, added exact method UID links and an explicit score/assignment rationale.
  - Summary/evidence: current documentation plus Batch117 IDA rechecks confirm `InsertAt` at `0x004b3d50-0x004b3fa4`, storage destructor at `0x004b56e0-0x004b575f`, 36-byte record semantics, the `FolderTreePane.cpp` file parent at `89/85`, and the template-context page at `85/89`.
