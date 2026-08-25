*** UID:0001U0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

# DATIndexVectorBucket

## 2026-08-17 Compiler Overlay Disposition

The two-pointer `first`/`last` shape and eight-byte stride are exact binary semantics of the old-MSVC/Dinkumware hash-container bucket array. They do not establish a project-authored `DATIndexVectorBucket` declaration. The same lowering is folded across independently typed FittingRoom, MiniMap, DATFileMgr, and MonsterImageLib containers, and no UDT, RTTI, source symbol, global, or header route exposes this private implementation type.

This page therefore remains a semantic compiler-overlay record with blank formal CPP/H, `RECONSTRUCTABLE:FALSE`, no canonical owner, and no emitter. The illustrative declaration and older custom-class route below are retained as historical field notation only; they must not be emitted into reconstructed source. Typed source uses `stdext::hash_map` and leaves this layout to the contemporary standard-library implementation.

## Status

- Entity kind: non-emitting compiler/private-library bucket-layout overlay
- Confidence: strong for observed fields and bucket-table behavior, medium for final name/header visibility.
- Canonical owner: none
- Parent attachment: none; [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a non-emitting compiler-family index.
- Header/module route: none
- Evidence basis: IDA MCP lookup/decompile checks on 2026-05-31 for `0x00457100`, `0x00457310`, and `0x00457580`; generated `simroot_v2` output is retained only as context.

## Layout Hypothesis

```cpp
struct DATIndexVectorBucket {
    DATIndexVectorNode* first; // +0x00
    DATIndexVectorNode* last;  // +0x04
};
```

Each bucket stores the first and last node in a bucket-owned contiguous range inside a single intrusive list. Empty buckets point at the list sentinel.

`DATIndexVectorBucket` is the two-dword bucket-table entry allocated and filled by `DATIndexVector::ResizeAndFill`. The B009 class-level recheck resolves the older value-table view: empty `first` and `last` both equal `DATIndexVector::m_listHead`, and the bucket table is the allocation at `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`, not a separate values array. [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) is the binary fill lowering for part of this `ResizeAndFill` operation; it is not a separate source owner for the bucket layout.

The accepted [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) first-draft body uses this exact `first`/`last` bucket declaration through the [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) class support block; no standalone type score change is required.

## IDA Evidence

IDA MCP `lookup_funcs` confirms the relevant methods as `0x00457100-0x0045730f` (`InsertNode`), `0x00457310-0x004573b3` (private remove/unlink helper), and `0x00457580-0x00457613` (`FindNodeByKey`).

IDA decompilation of `0x00457100` selects a bucket with an FNV-1a hash masked by the vector field at `this+0x18`, then reads the bucket table pointer at `this+0x0c`. It accesses the selected bucket as `bucketTable + 8 * bucketIndex`, with the first pointer at `+0x00` and the last pointer at `+0x04`. Empty buckets are initialized by writing the list sentinel from `this+0x04` into both fields.

IDA decompilation of `0x00457310` repairs these same two bucket fields when removing a node: if the removed node is both first and last, both fields are reset to the sentinel; if it is only last, the last field becomes `node->prev`; if it is only first, the first field becomes `node->next`.

IDA decompilation of `0x00457580` starts lookup from the bucket first pointer and computes the scan end from the bucket last pointer: if `last` is the sentinel, the sentinel is the end; otherwise the loop stops at `last->next`. That confirms the bucket does not own a separate node count, key, or hash value.

2026-06-16 C001 live IDA refresh:

- `lookup_funcs` reports `DATIndexVectorInsertNode` at `0x00457100-0x0045730f`, `DATIndexVectorRemoveNodeHelper` at `0x00457310-0x004573b3`, `DATIndexVectorDestructor` at `0x004573d0-0x00457429`, `DATIndexVectorFindNodeByKey` at `0x00457580-0x00457613`, and `DATIndexVectorResizeAndFill` at `0x00423b00-0x00423c3d`.
- `xrefs_to 0x00457100` still shows MiniMap update, MonsterImageLib archive-bounds, and self-rehash callers; `xrefs_to 0x00457310` is the single `InsertNode` cleanup edge at `0x00457301`; `xrefs_to 0x00457580` shows MiniMap lookup and MonsterImageLib archive-bounds callers. This supports a shared DATIndexVector helper rather than caller-local ownership.
- Decompilation reconfirmed the bucket table pointer at object `+0x0c`, bucket stride `8`, `first` at bucket `+0x00`, `last` at bucket `+0x04`, sentinel empty-state writes from object `+0x04`, removal repair for first/last cases, and lookup end calculation from `last->next`.
- Safe IDA names were applied and saved for the DATIndexVector value/bucket helpers. No member/type declaration was written into IDA because the final public-header versus private-source visibility and the value-table/hash-index class split remain unresolved.

## Consumers

- [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) updates `first` and `last` while inserting or moving nodes.
- [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) repairs boundary links when a bucket's first or last node is removed.
- [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) scans from `first` through `last->next`.

## Score Rationale

Completion is raised to `85` because the complete two-pointer bucket shape is verified through insert, remove, lookup, destructor/storage, current xrefs, strict parent route, and saved IDA helper names, including empty-bucket sentinel handling and bucket-table stride. Confidence remains `90` because the only meaningful remaining uncertainty is source-facing declaration visibility and final naming, not the binary offsets or semantics.

## Open Questions

- Whether the final bucket table was declared as a private nested struct, a typedef, or a template implementation detail.
- Whether the name should remain DAT-specific after broader caller review.
- Evidence checked for those blockers: live xrefs show DAT, MiniMap, and MonsterImageLib use through the shared [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) owner, while no current caller proves a public header declaration or a more generic original source name. Keep the source-facing type name provisional until the full class/header split is audited.

## Cross-References

- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)

## Changes

- 2026-08-17 B008 UID0000IP implementation callback:
  - Reclassified the exact eight-byte first/last bucket shape as an ownerless compiler/private-library overlay. Raised documentation scores to `93/95`, cleared the stale owner/emitter route, marked the page nonreconstructable as direct source, and preserved all exact layout/behavior evidence with blank formal CPP/H.

- 2026-07-05 B005 implementation callback:
  - No metadata/C++ change. Recorded that the accepted [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) body relies on this concrete two-pointer bucket declaration through the DATIndexVector class support block.
- 2026-06-24 B001 accepted source-quality implementation:
  - No metadata/C++ change. Added the [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) cross-reference: `ResizeAndFill` fills empty bucket `first`/`last` slots from `m_listHead`, and [UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) is only the non-emitting binary lowering for that operation. The struct layout remains the two-pointer bucket entry; no new owner or helper source body is introduced.
- 2026-06-21 B009 Rule 26 incorporation:
  - No score change. Added the class-level bucket-table interpretation: this struct is the paired `first`/`last` bucket entry filled from `m_listHead`; the old values-array wording is only a recovery alias.
- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP decompilation on 2026-05-31 verifies the two-pointer bucket shape through insert, remove, and lookup paths; final header visibility/name remains below near-final confidence.
- 2026-06-06: Completion/confidence changed from `74/88` to `82/90`, and `AUTOGEN_PARENT_UID` was set to [UID:00003K][DATIndexVector](by-class/DATIndexVector.md).
  - Before: the two-pointer bucket layout was documented, but the page remained below the parent-child attachment gate and the manual by-struct row still showed a stale `50%`.
  - After: the page records the parent gate, score rationale, and coverage report sync.
  - Evidence: `0x00457100`, `0x00457310`, and `0x00457580` use the bucket as exactly `first`/`last` pointers over the shared intrusive list.
- 2026-06-16 C001: Completion changed from `82` to `85`.
  - Evidence: live IDA reconfirmed insert/remove/find/destructor/resize helper starts, caller spread, FNV-bucket indexing, two-pointer bucket repair semantics, sentinel empty-state handling, and parent/file route support. Safe IDA function names were saved; type/member edits were skipped because the final declaration visibility and generic-versus-DAT naming remain provisional.
