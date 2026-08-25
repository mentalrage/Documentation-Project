** TARGET-REPORT-UID:00031T **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID00031T FrameRecordPayloadCopyHelper Source-Quality Report

Report timestamp: `2026-07-06T00:24:34-04:00`

## Finalized Report / Current Recommendation

Current implementation state: the accepted recommendation has been applied. [UID:00031T] `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md` remains reconstructable, source-authored ImageFrameTable helper code emitted through [UID:0000K1] `ImageFrameTable`, and its formal C++ now uses the accepted `MemoryMan` method route instead of stale unqualified `AllocateBufferMemory` / `MemmoveWrapper` helper calls.

Applied target metadata: `COMPLETION:88`, `CONFIDENCE:90`, preserving `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, blank `EMITTER_POSITION_OPTIONAL`, and current `Nested:-4`. Confidence should not move higher in this pass because current IDA still has no function object, no decompilation, no direct xrefs, and no VA/RVA pointer-pattern hits for the raw helper start/end.

No no-code reclassification was applied. Current IDA MCP reconfirms a coherent `0xa4` / 164-byte raw helper with normal prologue, two `ret 0x0c` exits, 24-byte ImageFrameTable record stride, in-range allocation/copy behavior, out-of-range pointer clearing, and dependency calls to accepted MemoryMan helpers. The generated file now contains UID00031T at `88/90` with `MemoryMan *memoryMan = GetMemoryMan()` and method calls.

## Supporting Research

Lifecycle/status:

- Gate 1 passed at SHA256 `6F4B84BC13FD0C119F285670EA623448B256659B383784815BA9E1BD718CD6F7`, and the supervisor authorized the implementation callback.
- B004 applied the accepted target and narrow support updates, then updated this report in place for supervisor execution review.
- Target/support by-* files edited by B004: `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`, `by-file/ImageFrameTable.md`, `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`, and `by-item/EPFArchiveMetadataTable.md`.
- Generated output, generated reports, coverage reports, project-level stats, validator registry/cache state, and autogen backups were touched only by scoped validator commands, not manually.
- No `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, archive moves, supervisor ledger edits, IDA DB edits, MemoryMan support edits, or ResourceLayout support edits were performed by B004.

Documents and reports checked:

- Target: `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`.
- Direct support: `by-file/ImageFrameTable.md`, `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`, `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`, `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`, and `by-item/EPFArchiveMetadataTable.md`.
- Calee/source-route support: `by-memory/0x00516030-0x00516036.GetMemoryMan.md`, `by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md`, `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`, and `by-file/MemoryMan.md`.
- Rejected-alternative support: `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` and `by-file/ResourceLayoutTable.md`.
- Generated output: `auto-generated/NexusTK/render/ImageFrameTable.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
- Historical executed reports used as context only: B001 `000174-ResourceLayoutTable.md`, B006 `0000K1-ImageFrameTable-empty-emitter-family-source-quality.md`, B010 `0002P4-LoadImageFrameTable-source-quality.md`, B007 `0001BC-GetMemoryMan-source-quality.md`, B008 `0001BD-AllocateBufferMemory-source-quality.md`, and B006 `0001BH-MemmoveWrapper-source-quality.md`.

MCP/session summary:

- MCP was available and responsive; this report is not fallback-only.
- Existing active session used: `supervisor_recovery_20260705`.
- `server_health` returned `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and string cache size `2067`.
- MCP calls were narrow and schema-current: `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, `xref_query`, `find_bytes`, `make_signature_for_range`, `int_convert`, `callees`, `insn_query`, and `analyze_function` for the successor ResourceLayout accessor.

## Target

- Target UID: `00031T`.
- Target path: `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Queue row at assignment: `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Classification: raw IDA-unmodeled but source-looking helper body in the ImageFrameTable helper neighborhood.
- Current source owner/emitter: [UID:0000K1] `ImageFrameTable`; generated path `auto-generated/NexusTK/render/ImageFrameTable.cpp`.
- Current parent/support state: [UID:0000K1] `by-file/ImageFrameTable.md` is `90/88`, and [UID:000176] `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` is a non-emitting `88/92` neighborhood/index map.

## Current Target State

Current post-callback target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000K1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000K1
EMITTER_POSITION_OPTIONAL:
Nested:-4
```

Current formal C++ is present, applied in the target, and generated with the accepted MemoryMan method-route syntax:

```cpp
MemoryMan *memoryMan = GetMemoryMan();
outRecord->payloadStart =
    (unsigned char *)memoryMan->AllocateBufferMemory(firstSpan);
memoryMan->MemmoveWrapper(outRecord->payloadStart,
                          record->payloadStart,
                          firstSpan);
```

After validation, the current generated file header is `validator-command-id: 000000007483`, `validator-refreshed-at: 2026-07-06T00:23:58-04:00`, `validator-refresh-source: deferred-generated-refresh`, source file UID `0000K1`. It contains UID00031T with `Completion:88 | Confidence:90`, `MemoryMan *memoryMan = GetMemoryMan()`, `memoryMan->AllocateBufferMemory`, and `memoryMan->MemmoveWrapper`. It is not an empty-marker failure.

The current support state is stronger than the current target prose reflects:

- [UID:0001BC] `GetMemoryMan` now emits formal `MemoryMan* GetMemoryMan()`.
- [UID:0001BD] `AllocateBufferMemory` now emits as `MemoryMan::AllocateBufferMemory(size_t size)`.
- [UID:0001BH] `MemmoveWrapper` now emits as `MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)`.
- UID00031T disassembly saves the `GetMemoryMan()` return and passes it in `ECX` before each allocation/copy call, so the target's best source draft should use a local `MemoryMan *memoryMan`.

## Heuristic / Inference Reanalysis And Validation

Owner/emitter: keep [UID:0000K1] `ImageFrameTable`. The helper uses the `ArchiveMetadataTable` / `PackedArchiveRecord` 24-byte record model, sits immediately after `LoadFrameDrawRecord`, shares the same sentinel next-record span relation, and has no direct ResourceLayout `this` use or caller evidence.

Reconstructable: keep `TRUE`. The body is coherent project code, not pure padding, vtable data, import glue, or compiler-only lifecycle scaffolding. Current MCP proves normal stack setup, in-range/out-of-range branches, MemoryMan dependency calls, output writes, and `ret 0x0c`.

Generated route: keep `EMITTER_UIDS:0000K1`. `ImageFrameTable.cpp` already emits UID00031T; after implementation validation it should still emit a body, but with `MemoryMan *memoryMan = GetMemoryMan()` plus method calls.

Source placement: keep `NexusTK/render/ImageFrameTable.cpp` beside `LoadFrameDrawRecord` and `CopyFrameRecordBounds`. Do not move to `MemoryMan.cpp`; MemoryMan is a callee dependency, not the helper owner.

C++ marker: do not blank the formal `RECONSTRUCTION_CPP CODE` block. The current body is source-shaped enough for a first draft after replacing stale unqualified calls with the accepted MemoryMan method route.

Route repair: the current body calls `GetMemoryMan()` but discards it in C++ even though disassembly stores the result in a local and uses it as `ECX`. This is the only target-level source-shape repair required by the new evidence.

Score blockers researched:

- No modeled function object at `0x004d1660`, `0x004d1704`, `0x004d1710`, or `0x004d172d`: confirmed current.
- Decompilation fails at `0x004d1660`: confirmed current.
- No xrefs to raw helper starts/ends and no pointer-byte hits for VA/RVA patterns: confirmed current.
- Exact original helper spelling and linkage remain unrecovered: unresolved but now a confidence cap, not a C++ blocker.
- Final field/type names remain inferred through UID0000UN: confidence cap only.

Rejected alternatives:

- No-code / non-emitting: rejected because the helper has a coherent source-looking body and already emits under current generated state.
- ResourceLayout ownership: rejected. The next modeled function at `0x004d1730` is ResourceLayout-owned, but it is a separate `thiscall` frame-size accessor with one InterfaceEfx caller and different record type; UID00031T uses ImageFrameTable record fields and MemoryMan copy dependencies.
- Merge into `LoadFrameDrawRecord`: rejected. UID0002P6 ends at `0x004d165d`, has three `0xcc` bytes before UID00031T, and current IDA does not model a larger function.
- MemoryMan ownership: rejected. `GetMemoryMan`, `AllocateBufferMemory`, and `MemmoveWrapper` are dependencies.
- Feature/caller ownership: rejected because there are no direct callers or pointer hits.
- IDA DB promotion/rename/type edit: not recommended in this report. The raw helper has no xrefs, and this assignment forbids IDA DB edits.

## Evidence Standards Used

- IDA MCP evidence is authoritative for current binary facts: session health, function existence, bytes, disassembly, xrefs, pointer-pattern hits, signature, and successor function facts.
- Current by-* docs are authoritative for accepted source-facing names, owner/emitter routing, generated file route, and support-doc state after prior supervisor-executed reports.
- Generated C++ is treated as current output state, not as proof over MCP. When generated output conflicts with current accepted MemoryMan method ownership, the by-* source docs and disassembly control the recommendation.
- Historical executed reports are used as provenance and context only. B006's UID00031T first-draft body remains useful, but the MemoryMan dependency route has advanced since that report.
- Negative evidence is explicitly capped: no modeled function/xrefs/pointer hits means no final-source confidence, but it does not erase byte-level source-body evidence.

## Evidence Checked

Current MCP facts:

- `lookup_funcs`: `0x004d1600` is `sub_4D1600`, size `0x5d`; `0x004d165d`, `0x004d1660`, `0x004d1704`, `0x004d1710`, and `0x004d172d` are not functions; `0x004d1730` is `sub_4D1730`, size `0x43`; callee support functions resolve at `0x00516030` size `0x6`, `0x00516050` size `0x7e`, and `0x00516220` size `0x18`.
- `entity_query` over `0x004d15c0-0x004d1740`: modeled functions only at `0x004d15d0`, `0x004d1600`, and `0x004d1730`.
- `get_bytes`: `0x004d165d-0x004d1660` is three `0xcc` bytes; `0x004d1660-0x004d1704` is the exact 164-byte helper body; `0x004d1704-0x004d1710` is twelve `0xcc` bytes; `0x004d1710-0x004d172d` is the rectangle-copy helper; `0x004d172d-0x004d1730` is three `0xcc` bytes.
- `disasm 0x004d1660`: `<no function>` but 63 decoded instructions from `push ebp` through the two `retn 0Ch` exits.
- `decompile 0x004d1660`: failed, as expected for an unmodeled raw helper.
- `insn_query` for calls in `0x004d1660-0x004d1704`: calls at `0x004d1665` to `sub_516030`, `0x004d169d` to `sub_516050`, `0x004d16b3` to `sub_516220`, `0x004d16cb` to `sub_516050`, and `0x004d16db` to `sub_516220`.
- `xrefs_to` / `xref_query`: zero xrefs to `0x004d1660`, `0x004d1704`, `0x004d1710`, and `0x004d172d`.
- `find_bytes`: zero matches for `60 16 4D 00`, `60 16 0D 00`, `04 17 4D 00`, `10 17 4D 00`, and `10 17 0D 00`.
- `make_signature_for_range 0x004d1660-0x004d1704`: unique wildcarded IDA signature beginning `55 8B EC 51 57 E8 ? ? ? ? ...` and ending with both `C2 0C 00` returns.
- `int_convert`: `0xa4 == 164`, `0x18 == 24`, `0x0c == 12`, `0x14 == 20`, and `0x28 == 40`.
- `callees 0x004d1660`: no function found; callee roles are therefore taken from disassembly. Support callee checks confirm `0x00516030` has no callees, `0x00516050` calls `_malloc`, `sub_4F4AA0`, `sub_4A60D0`, and `__CxxThrowException@8`, and `0x00516220` calls internal `_memmove`.
- `analyze_function 0x004d1730`: successor is a ResourceLayout `sub_4D1730` size 67, with decompiled `thiscall` frame-size behavior, callees `sub_4D17C0` and `sub_4D0120`, and one caller `sub_4E9950`.

Documentation/generated facts:

- Target has current formal C++ but stale unqualified MemoryMan helper-call shape.
- UID0000UN provides `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord` declarations at `88/91`.
- UID0002P6 `LoadFrameDrawRecord` is `88/92` and source-ready; it supports the same table/record model and next-record boundary span.
- UID00031U sibling is `86/89` and already documents the same raw/no-function/no-xref caveat for a no-callee 16-byte bounds copy.
- `ImageFrameTable.cpp` now shows the post-callback UID00031T generated state under command `000000007483`: `Completion:88 | Confidence:90`, `MemoryMan *memoryMan = GetMemoryMan()`, and method-route allocation/copy calls.

## Positive Evidence Summary

- UID00031T is a coherent source-looking helper body, not padding or data.
- The exact half-open range `0x004d1660-0x004d1704` is confirmed by bytes, neighboring padding, and the next helper at `0x004d1710`.
- The body uses the same 24-byte `PackedArchiveRecord` stride and sentinel next-record relation as `LoadFrameDrawRecord`.
- It calls accepted MemoryMan helper targets and uses the saved `GetMemoryMan()` result as the receiver for allocations/copies.
- The generated ImageFrameTable route is already active and contains UID00031T, so implementation should repair source shape rather than create a route.
- Current wildcarded range signature is unique, reinforcing that the bytes are stable and target-specific even without an IDA function object.

## Negative Evidence Summary

- IDA still does not model a function at `0x004d1660` or at the target end `0x004d1704`.
- Hex-Rays decompilation fails at `0x004d1660`.
- There are zero current xrefs to the helper starts/ends checked: `0x004d1660`, `0x004d1704`, `0x004d1710`, and `0x004d172d`.
- VA/RVA pointer-byte searches for the target and sibling helper starts/target end return zero hits.
- No current evidence proves the original helper name `CopyFrameRecordPayloads`; it is the best descriptive source-facing name only.
- No current evidence supports ResourceLayout ownership, caller ownership, an IDA rename/type/comment edit, or a no-code outcome.

## Ranked Ownership Analysis

1. [UID:0000K1] `ImageFrameTable` - recommended. It owns the table/record declarations, `LoadFrameDrawRecord`, `CopyFrameRecordBounds`, and the generated `ImageFrameTable.cpp` route. UID00031T's byte-level record semantics match this family.
2. [UID:000176] `ImageFrameTable` aggregate - support/index only. It correctly records the helper neighborhood but remains `RECONSTRUCTABLE:FALSE`; emitting the aggregate would duplicate exact children.
3. [UID:0000N5] / [UID:0000BY] `ResourceLayoutTable` - rejected for UID00031T. The successor at `0x004d1730` is ResourceLayout-owned, but UID00031T is a separate raw helper over ImageFrameTable records.
4. [UID:00007U] / [UID:0000L7] `MemoryMan` - callee dependency only. The target uses MemoryMan allocation/copy APIs but does not belong in MemoryMan source.
5. Feature/caller ownership or no owner - rejected. Current xrefs and pointer searches provide no caller evidence, and locality/record semantics are stronger than assigning no owner.

## Source Placement

Keep source placement in `NexusTK/render/ImageFrameTable.cpp` through [UID:0000K1]. This is the same source family as the shared declarations, `LoadImageFrameTable`, `DestroyOwnedImageBlock`, `LoadFrameDrawRecord`, and `CopyFrameRecordBounds`.

The helper is likely file-local/private from a source perspective, but there is no recovered original linkage spelling. Do not add a `static` keyword solely from lack of xrefs in this pass; preserve the existing generated helper style unless a future source/header audit standardizes private helper linkage.

## First-Draft C++ Recommendation

Eligible for formal C++: yes.

The target formal C++ block has been replaced with this method-route-corrected first draft:

```cpp
void CopyFrameRecordPayloads(const ArchiveMetadataTable *table,
                             int frameIndex,
                             FrameDrawRecord *outRecord)
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (frameIndex < 0 || frameIndex >= table->frameCount) {
        outRecord->payloadStart = NULL;
        outRecord->payloadEnd = NULL;
        return;
    }

    const PackedArchiveRecord *record = &table->records[frameIndex];
    const int firstSpan = (int)(record->payloadEnd - record->payloadStart);
    const int secondSpan = (int)(record[1].payloadStart - record->payloadEnd);

    outRecord->payloadStart =
        (unsigned char *)memoryMan->AllocateBufferMemory(firstSpan);
    memoryMan->MemmoveWrapper(outRecord->payloadStart,
                              record->payloadStart,
                              firstSpan);

    outRecord->width = record->bounds.right - record->bounds.left;
    outRecord->sourceRect = record->bounds;

    outRecord->payloadEnd =
        (unsigned char *)memoryMan->AllocateBufferMemory(secondSpan);
    memoryMan->MemmoveWrapper(outRecord->payloadEnd,
                              record->payloadEnd,
                              secondSpan);
    outRecord->payloadSpan = secondSpan;
}
```

Why this repairs current source shape:

- `GetMemoryMan()` is not dead. IDA stores its return in `edi` / `[ebp-4]`.
- The target moves that saved pointer into `ecx` before both `sub_516050` calls and both `sub_516220` calls.
- Accepted current support docs define those callees as `MemoryMan::AllocateBufferMemory` and `MemoryMan::MemmoveWrapper`.
- The rest of the existing C++ body remains behavior-correct: bounds check, record selection, first span, second span, first 16-byte bounds copy, output pointer writes, width write, and out-of-range pointer clearing.

## Recommended Target Doc Changes

Target path: `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`.

Applied metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000K1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000K1
EMITTER_POSITION_OPTIONAL:
Nested:-4
```

Applied content updates:

- Update the Item Summary to state that the helper is source-ready after current MCP refresh, but no modeled function/xrefs remain a confidence cap.
- Replace the formal C++ with the method-route-corrected block above.
- Add current MCP session `supervisor_recovery_20260705` evidence: health, exact no-function lookups, byte ranges, no decompilation, call instruction list, no xrefs, pointer-pattern negatives, unique signature, and successor ResourceLayout separation.
- Update Behavior / Callees to identify `GetMemoryMan`, `MemoryMan::AllocateBufferMemory`, and `MemoryMan::MemmoveWrapper` roles.
- Preserve negative evidence: no modeled function, no xrefs, no pointer hits, no original helper name proof, no ResourceLayout owner proof.
- Historicalize the B006 unqualified-helper formal C++ as a useful first pass that predates current MemoryMan method-route support.
- Preserve the no-code rejection: target should emit source, not blank or comment-only output.

## Recommended Support Doc Changes

Support edits applied during the implementation callback:

- `by-file/ImageFrameTable.md`: update UID00031T prose to say the helper remains source-ready and ImageFrameTable-owned, but the formal body should now use a local `MemoryMan *memoryMan = GetMemoryMan()` and method calls. Keep file scores unchanged unless validator forces a consistency correction.
- `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`: keep non-emitting aggregate status, but sync current support wording so UID0002P4 is no longer described as no-code/comment-only and UID00031T is described as the exact raw payload-copy child with the current MemoryMan method-route repair. No score movement recommended for the aggregate.
- `by-item/EPFArchiveMetadataTable.md`: update the stale note saying the adjacent raw helpers "should receive their own exact memory pages later"; they already exist as UID00031T and UID00031U. Add only narrow prose if needed to say UID00031T uses the shared declarations and MemoryMan allocation/copy dependencies.

Support docs checked and not edited because they already carried same-or-greater detail or were outside the accepted scope:

- `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`: already preserves the table/record model, adjacent raw-helper split, and source-ready support state at same-or-greater detail.
- `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`: already preserves the sibling no-function/no-xref caveat and ImageFrameTable ownership.
- MemoryMan callee docs and `by-file/MemoryMan.md`: already contain same-or-greater detail for `GetMemoryMan`, `MemoryMan::AllocateBufferMemory`, and `MemoryMan::MemmoveWrapper`; no edit recommended.
- ResourceLayoutTable docs: already distinguish the successor ResourceLayout method and raw ResourceLayout helper ownership; no edit recommended.

## Final Recommendation

Implemented a narrow target/support source-shape repair after Gate 1:

- Target UID00031T: `86/89 -> 88/90`, same owner/emitter/reconstructable route, formal C++ replaced with the method-route-corrected block.
- Support docs: ImageFrameTable file/aggregate and EPFArchiveMetadataTable stale helper-page wording were updated narrowly; ResourceLayout, MemoryMan, generated, coverage, and validator-state files were not edited manually.
- Generated observation after scoped validation: `auto-generated/NexusTK/render/ImageFrameTable.cpp` keeps UID00031T present and no longer shows the stale `GetMemoryMan(); AllocateBufferMemory(...); MemmoveWrapper(...);` shape for this target.

No split, rename, new child, owner change, IDA DB edit, by-global page, third-party import directive, or no-code marker is recommended.

## Score And Metadata Recommendation

Applied target score: `88/90`.

Completion rationale:

- Moves from `86` to `88` because current MCP refresh revalidates the exact raw body, no-function/no-xref state, pointer-search negatives, unique signature, MemoryMan method-call route, generated state, and support-context drift.
- Does not move higher because no current xref/caller source path exists and exact original helper name/linkage are unrecovered.

Confidence rationale:

- Moves from `89` to `90` because current IDA MCP and support docs make the body/source-route repair stronger than the older B006 first draft.
- Does not move higher because the target is still not an IDA-modeled function, Hex-Rays cannot decompile it, and the helper remains source-placed by locality/record semantics rather than caller evidence.

Applied metadata:

- Keep `CANONICAL_OWNER:0000K1`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000K1`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.
- Keep current `Nested:-4`; no current evidence proves this field is the source-quality blocker for UID00031T.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best current resolution | Remaining impact |
|---|---|---|---|
| Is the target live/referenced? | `xrefs_to`, `xref_query`, VA/RVA `find_bytes` for target/sibling starts/end. | No direct xrefs or pointer hits found. Treat as retained raw helper or stripped/static helper with unknown reachability. | Confidence cap; not a no-code proof. |
| Should the body remain formal C++? | Bytes, disassembly, generated state, support declarations, MemoryMan callees. | Yes. It is coherent source-authored project code and already has a route. | No-code rejected. |
| Are `CopyFrameRecordPayloads`, `ArchiveMetadataTable`, `PackedArchiveRecord`, and `FrameDrawRecord` original names? | Current docs, generated output, IDA names/type queries indirectly through support docs. | Use as source-facing inferred names. | Confidence cap only. |
| Should MemoryMan calls be methods? | Current callee docs plus UID00031T disassembly moving saved `GetMemoryMan()` result into `ECX`. | Yes for `AllocateBufferMemory` and `MemmoveWrapper`; use `MemoryMan *memoryMan = GetMemoryMan()`. | Target formal C++ should be repaired. |
| Should ResourceLayout own the helper because `0x004d1730` follows it? | Successor `analyze_function`, ResourceLayout docs, target record semantics. | No. `0x004d1730` is a separate ResourceLayout class/facet method; UID00031T uses ImageFrameTable records. | Rejected alternative. |
| Should an IDA function be created at `0x004d1660`? | No xrefs and assignment restrictions. | Not in this report. Current docs can reconstruct from raw bytes without IDA DB mutation. | Future IDA owner can revisit if desired. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C-00031T-01 | UID00031T is exactly `0x004d1660-0x004d1704`, a `0xa4` / 164-byte raw helper bracketed by padding and followed by UID00031U. | High | MCP `lookup_funcs`, `entity_query`, `get_bytes`, `int_convert`. | Target Boundary Evidence; ImageFrameTable aggregate adjacent-helper section. | incorporate | applied |
| C-00031T-02 | Current IDA does not model or decompile the target as a function. | High | `lookup_funcs` no function at start/end; `decompile 0x004d1660` failed. | Target Status and Current IDA Status. | incorporate | applied |
| C-00031T-03 | The helper has no direct xrefs or VA/RVA pointer hits at checked starts/ends. | High | `xrefs_to`, `xref_query`, `find_bytes` patterns all zero. | Target negative evidence and score rationale. | incorporate | applied |
| C-00031T-04 | Body behavior is two payload-span allocations/copies plus first 16-byte record copy, with out-of-range pointer clearing. | High | MCP disassembly and `insn_query`; existing target behavior. | Target Behavior and formal C++ block. | incorporate | applied |
| C-00031T-05 | The formal C++ should use a saved `MemoryMan *memoryMan` receiver for allocation/copy calls. | High | Target disassembly stores `GetMemoryMan()` return and moves it to `ECX`; current MemoryMan support docs make callees class methods. | Target formal `RECONSTRUCTION_CPP CODE`. | incorporate | applied |
| C-00031T-06 | Owner/emitter should remain UID0000K1 ImageFrameTable. | High | Shared record model, adjacency to UID0002P6/UID00031U, current by-file route, generated output. | Target metadata; ImageFrameTable file role. | incorporate | applied |
| C-00031T-07 | No-code/non-emitting disposition is rejected. | High | Coherent source-looking body and current generated UID00031T output. | Target Reconstruction Notes and Final Recommendation. | reject-invalid | applied |
| C-00031T-08 | ResourceLayout ownership is rejected despite successor at `0x004d1730`. | High | Successor ResourceLayout `analyze_function`; ResourceLayout docs; target record semantics. | Target Ownership Notes; support negative evidence. | reject-invalid | applied |
| C-00031T-09 | Target score should move only modestly to `88/90`. | Medium-high | Current MCP confirms body/route but no xrefs/function remain. | Target metadata and Score Rationale. | incorporate | applied |
| C-00031T-10 | Generated `ImageFrameTable.cpp` contained UID00031T but stale helper-style calls before the callback. | High | Read-only generated output header/content before and after validation. | Target Generated Output / support by-file note. | historicalize | applied |
| C-00031T-11 | `by-file/ImageFrameTable.md` should sync UID00031T current method-route source readiness. | Medium-high | Current by-file content plus MemoryMan support docs. | `by-file/ImageFrameTable.md` UID00031T row/prose. | incorporate | applied |
| C-00031T-12 | `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` has support-context drift around UID0002P4 no-code and should narrowly sync current family state if edited. | Medium-high | Current aggregate text; executed B010 UID0002P4 state; generated output. | ImageFrameTable aggregate Status / Covered Ranges / Adjacent Split Helper Island. | incorporate | applied |
| C-00031T-13 | `by-item/EPFArchiveMetadataTable.md` has stale wording that adjacent raw helper pages are future work. | Medium | Current by-item text; existing UID00031T/UID00031U exact pages. | EPFArchiveMetadataTable Loader And Projection Synchronization. | historicalize | applied |
| C-00031T-14 | MemoryMan callee docs are already at same-or-greater detail for this target's callee route. | High | Current `GetMemoryMan`, `AllocateBufferMemory`, `MemmoveWrapper`, and `MemoryMan.md` docs. | MemoryMan support docs; no edit required. | already-present | already-present |

## Validator Results

Scoped validators were run from `source-3/project-documentation` after the by-* edit batch:

| command_id | timestamp | Command | Exit | ok | Notes |
|---|---|---|---:|---:|---|
| `000000007480` | `2026-07-06T00:23:29-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md --apply --queue-timeout 240 --wait-generated` | 0 | 1 | Applied target `completion_update 88`, `confidence_update 90`, registry update, `autogen_cpp_update 0000K1`, tracker/coverage/projected-stats validator-owned updates, and `generated_refresh: completed`. Warnings were existing generated-pipeline diagnostics: `autogen_children_fallback_insert`, `autogen_children_marker_missing`, and `autogen_emitter_has_no_code`. |
| `000000007481` | `2026-07-06T00:23:45-04:00` | `python .\tools\validator.py --mode file --file by-file/ImageFrameTable.md --apply --queue-timeout 240` | 0 | 1 | Direct scoped support validation passed; `generated_refresh: deferred`; projected stats validator-owned update reported. |
| `000000007482` | `2026-07-06T00:23:50-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md --apply --queue-timeout 240` | 0 | 1 | Direct scoped support validation passed; `generated_refresh: deferred`; projected stats validator-owned update reported. |
| `000000007483` | `2026-07-06T00:23:58-04:00` | `python .\tools\validator.py --mode file --file by-item/EPFArchiveMetadataTable.md --apply --queue-timeout 240` | 0 | 1 | Direct scoped support validation passed; `reference_index_add` for UID00031T/UID00031U and stats update reported; `generated_refresh: deferred`. |

Generated freshness checked read-only after validation:

- `auto-generated/NexusTK/render/ImageFrameTable.cpp` header now reports `validator-command-id: 000000007483`, `validator-refreshed-at: 2026-07-06T00:23:58-04:00`, `validator-refresh-source: deferred-generated-refresh`, source file UID `0000K1`.
- UID00031T appears as `Completion:88 | Confidence:90`.
- UID00031T body contains `MemoryMan *memoryMan = GetMemoryMan()`, `memoryMan->AllocateBufferMemory`, and `memoryMan->MemmoveWrapper`.
- The stale unqualified `GetMemoryMan(); AllocateBufferMemory(...); MemmoveWrapper(...);` target shape is no longer present in the UID00031T generated body.

## Changed Files

Manual edits by B004:

- `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`
- `by-file/ImageFrameTable.md`
- `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`
- `by-item/EPFArchiveMetadataTable.md`
- `tools/leaser/Agents/Agent-B004/research/00031T-FrameRecordPayloadCopyHelper-source-quality.md`

Validator-owned side effects observed, not manually edited:

- `auto-generated/NexusTK/render/ImageFrameTable.cpp` refreshed for UID00031T.
- Validator reported generated metadata coverage refreshes, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, projected stats, validator registry rebuild/update, reference-index updates, and validator autogen backups as validator-owned effects.

Not manually changed by B004:

- Generated C++ or generated reports.
- Coverage reports or any `-coverage-report.md`.
- Validator state, tracker files, project-level generated files, supervisor ledgers, lifecycle headers/footers, executed archives, or report archive/move locations.
- IDA DB state.
- MemoryMan or ResourceLayout support docs.

Lease status:

- Leased immediately before the edit/validator batch: `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`, `by-file/ImageFrameTable.md`, `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`, and `by-item/EPFArchiveMetadataTable.md`.
- Released immediately after validators with successful `unlease` results for all four paths.
- Read-only `tools/leaser/Agents/current_leases.md` check after release shows no B004 lease entries.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update identified: target UID00031T; support `by-file/ImageFrameTable.md`; optional/narrow support `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` and `by-item/EPFArchiveMetadataTable.md`; no MemoryMan/ResourceLayout edits recommended.
- [x] Current target state and actual evidence checked recorded: target metadata, generated state, MCP health/session, bytes, function lookups, disassembly, decompile failure, xrefs, pointer searches, signature, and support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply recorded: target `86/89 -> 88/90`; owner/emitter/reconstructable/position/nested preserved.
- [x] Score-limiting blockers researched to resolution or exact cap: no function, no decompile, zero xrefs/pointer hits, no original name/linkage proof, inferred field/type names.
- [x] Owner/emitter/reconstructable changes to apply or confirm unchanged recorded: keep `0000K1`, `TRUE`, `0000K1`.
- [x] Split/rename/new-child changes to apply or confirm not applicable recorded: no split/rename/new child; keep half-open range.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment decisions recorded: keep `ImageFrameTable.cpp`; no IDA DB edits.
- [x] First-draft C++ recommendation supplied: method-route-corrected `CopyFrameRecordPayloads` block.
- [x] Third-party import directive not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail listed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B006 unqualified helper-call shape historicalized; no-code, ResourceLayout, MemoryMan-owner, feature-owner, and merge alternatives rejected.
- [x] Wave2/Wave3 artifacts encountered only as historical/support context; current MCP/by-* docs control recommendation.
- [x] Open questions closed or documented as evidence-backed unresolved caps.
- [x] Validators to run listed for every then-proposed changed by-* file.
- [x] Generated refresh expectation recorded: `ImageFrameTable.cpp` should keep UID00031T but refresh to the MemoryMan method-call shape; generated/tracker/coverage text remains validator/supervisor-owned.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: Gate 1 passed SHA256 `6F4B84BC13FD0C119F285670EA623448B256659B383784815BA9E1BD718CD6F7`.
- [x] Lease each by-* file only immediately before editing and release immediately after the edit/validator batch: leased and released target plus three support docs; `current_leases.md` shows no B004 lease entries after release.
- [x] Target UID00031T metadata/prose/C++ incorporated at report-level detail: target is `88/90`, owner/emitter/reconstructable/nested preserved, and formal C++ uses `MemoryMan *memoryMan = GetMemoryMan()` with method calls.
- [x] Accepted support doc details incorporated at report-level detail: `by-file/ImageFrameTable.md`, `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`, and `by-item/EPFArchiveMetadataTable.md` were updated narrowly; MemoryMan and ResourceLayout docs were already-present/out of scope and not edited.
- [x] Claim And Incorporation Ledger updated with `applied` or `already-present` states for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: only target score/C++ changed; no split, rename, owner/emitter change, IDA DB edit, by-global page, or no-code marker.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved in target/support docs: B006 unqualified helper-call shape historicalized; no-code, ResourceLayout owner, MemoryMan owner, and feature-owner alternatives rejected; no-function/no-decompile/no-xref/no-pointer-hit caps preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact original helper/type/linkage names and reachability remain confidence caps only.
- [x] Scoped validators run for every edited by-* file and results recorded with command id, timestamp, exit, `ok`, warnings, and generated refresh state: `000000007480`, `000000007481`, `000000007482`, and `000000007483`, all exit `0`, `ok:1`.
- [x] Generated `auto-generated/NexusTK/render/ImageFrameTable.cpp` freshness checked read-only: final header `000000007483` / `2026-07-06T00:23:58-04:00`, UID00031T `88/90`, method-route body present, stale unqualified target shape gone.
- [x] Remaining unapplied accepted items listed with exact blocker, if any: none.

## Final Implementation Callback Status

Implementation callback artifact is ready for supervisor execution review. B004 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, archive moves, supervisor ledger edits, manual generated edits, manual coverage edits, or IDA DB edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007490","destination_path":"executed-b-agent-research/B004/00031T-FrameRecordPayloadCopyHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00031T-FrameRecordPayloadCopyHelper-source-quality.md","timestamp":"2026-07-06T00:33:25-04:00","uid":"00031T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
