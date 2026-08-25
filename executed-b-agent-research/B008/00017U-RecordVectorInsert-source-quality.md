** TARGET-REPORT-UID:00017U **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00017U RecordVectorInsert Source-Quality Research

Assignment: `B008-rework-00017U-record-vector-insert-20260625`  
Agent: `Agent-B008`  
Mode: report-only research first; no by-* edits, generated edits, coverage edits, validator state/cache edits, IDA database edits, or subagent work performed.  
Target: [UID:00017U] `by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md`  
Required report path: `tools/leaser/Agents/Agent-B008/research/00017U-RecordVectorInsert-source-quality.md`

## Executive Conclusion

[UID:00017U] is a real exact helper body, but the reworked disposition is comment-marker emission rather than blank formal C++ or metadata reclassification. Current IDA MCP evidence resolves the prior blockers: this is the out-of-line grow/relocate path for a `0x28` / 40-byte local composition-record vector used only by `NewHumanImageLib::RenderComposition`; the no-growth append/copy path is inline in that caller. A standalone helper-body reconstruction would turn compiler/template vector support into invented handwritten source and would require invented record, allocator, and helper declarations.

Option 1 from the supervisor rejection is the implementation-ready outcome: keep `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000BS`, raise the score to `86/90`, and replace the blank target formal block with an exact source-disposition marker. Option 2 is rejected because the current owner/emitter route is still valid: [UID:00017U] is NexusTK-adjacent vector support routed through [UID:0000BS] and [UID:0000P3], and generated output should not keep an empty live emitter when a range-scoped marker can document the correct source disposition.

Recommended target metadata after implementation callback:

| Field | Current target | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `86` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `0000BS` | `0000BS` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000BS` | `0000BS` |
| `RECONSTRUCTION_CPP CODE` | blank | insert exact formal source-disposition marker below |

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:00017U]:

```cpp
// Emitted code for this vector-insert slow path is covered by [UID:00017R]
// RenderComposition's local composition-record vector source, or by a
// [UID:0000P3] VectorHelpers compatibility template if the recovered typed
// source cannot regenerate this out-of-line helper.
// Do not emit a standalone decompiler-shaped insert helper body here.
```

The ownership route should stay hierarchical: [UID:00017U] -> [UID:0000BS] `RecordVector_4E57C0` -> [UID:0000P3] `VectorHelpers`. `NewHumanImageLib` owns the composition/render semantics and record-producing caller, while `VectorHelpers` remains the correct support parent for the emitted vector grow helper.

## Files And Evidence Read

Direct target/support docs read:

| Item | Use |
| --- | --- |
| `goal.md` | Assignment, report-only rule, MCP requirement, named blockers, required report path. |
| `by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md` | Current target state, rejected blank-C++ rationale, caller/copy-helper notes. |
| `by-class/RecordVector_4E57C0.md` | Immediate helper owner, utility-parent route, old source-shape caveats. |
| `by-file/VectorHelpers.md` | Shared vector/template helper policy, `NexusTK/util/` placement, generated-class caveats. |
| `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` | `RenderComposition` placement and lower NewHuman method family. |
| `by-file/NewHumanImageLib.md` | Source route and explicit note that this helper is vector support called only by `RenderComposition`. |
| `by-class/NewHumanImageLib.md` | Composition/render context and helper not-a-method note. |
| `by-type/by-struct/NewHumanImageLibLayout.md` | Current accepted NewHuman field names and lack of a named 0x28 composition-record type. |
| `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md` | `CopyRecordVector40Range` body, callers, and utility-parent route. |
| `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md` | `vector<T> too long` helper as runtime/STL support, not project source. |
| `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md` | Neighbor vector-grow precedent and source-shape comparison. |
| `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` | Composition-family context and unresolved field/helper naming precedent. |

Generated/read-only lead material checked:

- `auto-generated/NexusTK/util/VectorHelpers.cpp` is an empty-emitter marker file. It has [UID:0000BS] and [UID:00017U] markers only, with stale generated scores, and no candidate source body.
- Generated coverage/tracker rows still carry stale score/details for [UID:00017U]. These generated files were not edited and should refresh only through validator/autogen after an accepted callback.

## Current IDA MCP Session

IDA MCP was available and used. No IDA DB edits were made.

| Evidence | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` 1.0.0 |
| MCP initialize | 2026-06-25 rework probe returned `ida-pro-mcp` protocol `2025-06-18` |
| Active database | `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Worker | PID `26892`, not analyzing |
| Health | `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, uptime `112550.401` seconds at recheck |
| Auto-analysis / Hex-Rays / strings cache | ready / ready / ready (`strings_cache_size:2067`) |

Live tool schema was checked before use. Current read calls used `database='80de0a67'`; no mutation tools were called. The rework-only MCP calls were `server_health`, `idb_list`, `lookup_funcs`, `analyze_function`, and `search_text`.

## Current Target State

Target header read on 2026-06-25:

| Field | Value |
| --- | --- |
| UID | `00017U` |
| Range/title | `0x004e57c0-0x004e5989 RecordVector Insert` |
| Completion / confidence | `85` / `88` |
| Canonical owner | `0000BS` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `0000BS` |
| Formal C++ | blank |
| Current summary | Fixed `0x28` record-vector insert with single `RenderComposition` caller, `CopyRecordVector40Range` dependency, growth behavior, and reconstruction blockers documented. |

The live IDA half-open function object is `0x004e57c0-0x004e598a` (`size 0x1ca`). The file name/display range uses last-byte notation `0x004e5989`; no split or boundary correction is needed.

## Live Function Evidence

`lookup_funcs` confirms:

| Query | Result |
| --- | --- |
| `0x004e57c0` | `sub_4E57C0`, size `0x1ca` |
| `0x004e4c14` | inside `sub_4E4280`, size `0xaf9` |
| `0x004e4280` | `sub_4E4280`, size `0xaf9` |
| `0x004e6ff0` | `sub_4E6FF0`, size `0x36` |
| `0x004e5990` | `sub_4E5990`, size `0xd2` |
| `0x00421500` | `sub_421500`, size `0x0a` |
| `0x005c74f6` | `operator new(uint)`, size `0x30` |
| `0x005c7526` | `sub_5C7526`, size `0x0e` |
| `0x005cd607` | `__invalid_parameter_noinfo_noreturn`, size `0x1d` |

`analyze_batch` for `0x004e57c0` reports a thiscall-style helper over the vector header, insertion pointer, and record pointer, with 26 basic blocks, no strings, one caller, and five callees: `sub_421500`, `operator new(uint)`, `sub_5C7526`, `sub_4E6FF0`, and `__invalid_parameter_noinfo_noreturn`.

The 2026-06-25 rework MCP recheck reconfirmed the same target shape with `analyze_function`: prototype `int __thiscall(int *this, int, int)`, size `458`, 26 basic blocks, no strings, caller `sub_4E4280`, and callees `sub_421500`, `operator new(uint)`, `sub_5C7526`, `sub_4E6FF0`, and `__invalid_parameter_noinfo_noreturn`.

`search_text` over `0x004e4280-0x004e4d79` for `sub_4E57C0` returned exactly one hit: `.text:004E4C14 call sub_4E57C0` inside `sub_4E4280`.

`xrefs_to` reports:

| Target | Incoming xrefs |
| --- | --- |
| `0x004e57c0` | exactly one code xref at `0x004e4c14` inside `sub_4E4280` |
| `0x004e6ff0` | exactly two code xrefs at `0x004e58fa` and `0x004e590e`, both inside `sub_4E57C0` |

Boundary bytes:

| Region | Result |
| --- | --- |
| `0x004e57c0` | normal prologue bytes begin `55 8b ec ...` |
| `0x004e5980` | invalid-parameter and vector-too-long calls, then `0xcc` alignment |
| `0x004e598a` | six `0xcc` bytes before `0x004e5990` |
| `0x004e6ff0` | normal copy-helper prologue bytes |
| `0x004e7026` | ten `0xcc` bytes after the copy helper |

`int_convert` verified the relevant constants: `0x28` is 40, `0x6666666` is 107374182, `0x1000` is 4096, `0x23` is 35, and `0x1f` is 31.

## Behavior Resolved

The helper uses a three-pointer vector header:

| Header word | Role |
| --- | --- |
| `this[0]` | begin pointer |
| `this[1]` | end pointer |
| `this[2]` | capacity-end pointer |

Resolved behavior:

1. Computes insertion index from `position - begin` divided by 40.
2. Computes current size and capacity from the vector triplet, also divided by 40.
3. Throws through `sub_421500` when current size reaches `107374182` (`0x6666666`), the MSVC `vector<T> too long` path.
4. Chooses new capacity as capacity plus half capacity when possible, with a clamp to at least `size + 1`.
5. Allocates `newCapacity * 40` bytes through `operator new(uint)`.
6. For large allocations (`>= 0x1000` bytes), requests `size + 0x23`, aligns the returned address to 32 bytes, and stores the raw allocation pointer in the preceding dword.
7. Copies the inserted value as two 16-byte lanes plus one 8-byte tail.
8. If inserting at the old end, copies the old range with an inline 40-byte loop.
9. If inserting before the old end, calls `sub_4E6FF0` twice to copy prefix and suffix around the inserted record.
10. Frees old storage through `sub_5C7526`, with the same large-allocation header validation pattern before freeing aligned storage.
11. Updates begin/end/capacity and returns the inserted element pointer in the new storage.

`sub_4E6FF0` decompiles as a pure 40-byte range-copy loop with no callees. It copies each element as 16 bytes, 16 bytes, and 8 bytes, increments source/destination by 40, and returns the final destination pointer. `analyze_batch` reports 3 basic blocks, no strings, no callees, and constants `0x28` / 40.

## Caller And Record Semantics

The sole caller is `sub_4E4280`, documented by project files as `NewHumanImageLib::RenderComposition`. Current decompilation resolves the important vector source shape:

- `RenderComposition` initializes a stack vector triplet at locals `Block`, `v39`, and `v40`.
- It builds candidate stack records in a 40-byte local span represented by `v55`, `v56`, and `v57`.
- It appends a record only when the record's second dword is nonzero.
- If `end != capacity`, the caller writes the 40-byte record inline at the current end and advances the end pointer by 40.
- If `end == capacity`, the caller invokes the helper at `0x004e4c14` with the stack vector header, current end pointer, and candidate record, then reloads the vector end/capacity locals.
- After the loop, the caller iterates the vector as 40-byte records. It uses the 16 bytes at record offset `+0x10` as rectangle-like coordinates and passes both record `+0x00` and `+0x10` into the render callback at `unk_69B3F0`.
- The caller releases the stack vector storage through the same large-allocation validation and `sub_5C7526` free pattern.

This resolves the `0x28` record semantics enough to name the broad role: a `RenderComposition` local composition/render record. It does not resolve an original source type name or field declaration. The strongest current working prose is "40-byte NewHuman composition render record"; formal C++ should not commit that as a struct name yet.

## Blocker Reanalysis

| Blocker | Current resolution |
| --- | --- |
| Source-authored helper vs template instantiation | Resolved as compiler/template or compatibility-vector grow support, not a handwritten feature method. The no-growth copy path is inline in `RenderComposition`; only the grow/relocate slow path is out-of-line. |
| Realistic record/vector type names | The record is a 40-byte `RenderComposition` local composition/render record. No exact source type name is proven. `RecordVector_4E57C0` remains a documentation/helper bucket, not a product-domain class. |
| `0x28` record semantics | Proven 40-byte records; caller later treats `+0x10` as rectangle-like coordinates and uses `+0x00` as the render source payload. Field names remain unsafe. |
| Allocation/free helper naming | Use runtime terms only in docs: `operator new(uint)`, `sub_5C7526` free wrapper, `__invalid_parameter_noinfo_noreturn`, and MSVC `vector<T> too long`. `sub_5C7526` decompiles to `j_j___free_base(Block)` and has hundreds of xrefs, so it is not target-local source. |
| `CopyRecordVector40Range` relationship | Proven as `sub_4E6FF0`, a no-callee 40-byte range copy helper called only twice by this target. It is an internal helper dependency, not a separate source owner. |
| Single-caller source placement | The only caller is `RenderComposition`; NewHumanImageLib owns the composition record semantics, while VectorHelpers owns the reusable vector-support bucket. |
| Generated C++ lead | `auto-generated/NexusTK/util/VectorHelpers.cpp` contains empty markers only; no generated body is available or trustworthy as source text. |
| Emitter/C++ disposition | Resolved by formal comment-marker emission. Keeping the live route with a marker is safer than blank C++; reclassification to non-reconstructable or non-emitting is not justified because this exact range is still the emitted compatibility/template slow path for a source-owned local vector. |
| Split/child updates | No new split needed. The target and copy helper are exact. The fast append path belongs in `RenderComposition`, not in this target page. |

## Positive And Negative Evidence

Positive evidence for keeping the current owner route:

- The target is a modeled executable function with a clean boundary, exact size, and alignment after the last byte.
- The caller is source-owned `NewHumanImageLib::RenderComposition`, so the helper is NexusTK-adjacent support rather than third-party library code.
- The immediate owner [UID:0000BS] and utility parent [UID:0000P3] already document this as shared vector-helper support.
- `CopyRecordVector40Range` is already documented in [UID:00022R], the same utility-parent family.
- The live emitter route is valid and above the code-entry gate, so generated output should carry a deliberate source-disposition marker instead of an empty marker.

Negative evidence against a standalone helper-body formal C++ implementation:

- The function has no semantic strings, globals, feature branches, table parsing, or source-specific logic beyond vector grow/copy/free mechanics.
- The only source-facing call site uses an inline fast path and calls this body only when the local vector is full, matching compiler-generated vector insertion support.
- The record name and fields are not recovered; a standalone body would require inventing a byte-array record type or using raw byte arrays.
- A standalone body would also require choosing allocation/free helper spelling that is contradicted by the runtime helper fan-in.
- The generated `VectorHelpers.cpp` file has empty markers only and therefore does not prove a real `VectorHelpers.cpp` source body.

## Ranked Source / Owner Decision

| Rank | Candidate | Decision |
| ---: | --- | --- |
| 1 | [UID:0000BS] `RecordVector_4E57C0` under [UID:0000P3] `VectorHelpers` | Keep as immediate documentation owner/emitter route for this exact helper, but emit only the target-level source-disposition marker. It is the least misleading bucket for the compiler/vector slow path. |
| 2 | [UID:0000LR] `NewHumanImageLib` / `RenderComposition` | Owns the composition record semantics and should eventually express the local vector use in `RenderComposition`, but should not own this helper body as a class method. |
| 3 | [UID:00022R] `ImageLibVectorSupportHelpers` | Provides the copy helper and adjacent image/vector support context, but the exact insert helper already has its own page and class bucket. |
| 4 | Runtime/MSVC support | Explains `sub_421500`, `operator new`, `sub_5C7526`, and invalid-parameter handling, but does not own the project-local instantiation page. |
| Rejected | New standalone product class or feature source file | No evidence supports a real source class named `RecordVector_4E57C0` or a handwritten feature helper. |

## First-Draft C++ Recommendation / Formal Source-Disposition Marker

[UID:00017U] clears the active code-entry gate because it remains `RECONSTRUCTABLE:TRUE`, has `EMITTER_UIDS:0000BS`, and should be raised to `86/90`. The correct formal block is not a standalone helper body and not blank; it is this exact comment marker:

```cpp
// Emitted code for this vector-insert slow path is covered by [UID:00017R]
// RenderComposition's local composition-record vector source, or by a
// [UID:0000P3] VectorHelpers compatibility template if the recovered typed
// source cannot regenerate this out-of-line helper.
// Do not emit a standalone decompiler-shaped insert helper body here.
```

Target-specific source-disposition proof:

1. Current MCP shows the sole caller `RenderComposition` implements the source-level vector append flow inline when capacity remains and calls `0x004e57c0` only for the grow/relocate slow path. That is template/compiler support shape, not a full source-authored `Insert` method.
2. The target body contains only vector capacity math, allocation, 40-byte element copying, range relocation, and runtime free/error paths. It has no source-specific branch or state beyond the vector triplet and input record.
3. The record type is not source-quality. Current evidence proves a 40-byte composition/render record and rectangle-like fields at `+0x10`, but not an original struct name or full field list.
4. The allocator/free paths are runtime support. `sub_421500` is the documented MSVC `vector<T> too long` helper, `operator new(uint)` has broad fan-in, and `sub_5C7526` is a broad free wrapper. Handwritten C++ for this target would either expose those runtime names directly or invent a compatibility allocator layer.
5. The current generated `VectorHelpers.cpp` output contains only empty markers for this UID and its owner; it provides no source body to preserve.

Therefore, the implementation callback should replace the blank formal block with the comment marker above. The marker is inside the target's range/role because it documents this helper-range emission as covered by the caller's local vector source or the shared compatibility-template route, and it prevents generated output from treating an above-gate live emitter as empty. The unresolved future `VectorHelpers` template decision does not block the marker route, and it does not justify reclassifying this target as non-reconstructable or non-emitting now.

## Score And Metadata Recommendation

| Item | Recommendation |
| --- | --- |
| [UID:00017U] target | Raise to `86/90`, keep `CANONICAL_OWNER:0000BS`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000BS`, and insert the exact formal source-disposition marker in `RECONSTRUCTION_CPP CODE`. |
| [UID:0000BS] `RecordVector_4E57C0` | Required support-prose update, no metadata change: replace the stale passive blank-C++/old-gate rationale with the accepted disposition that [UID:00017U] emits a marker because the helper is compiler/vector slow-path support, not a product class. |
| [UID:0000P3] `VectorHelpers` | Required support-prose update, no score change required: add one concise child note that [UID:00017U] uses comment-marker emission while final source is represented through `RenderComposition` local typed vector source or a `VectorHelpers` compatibility template. |
| [UID:00022R] copy-helper cluster | No target-support edit required; the existing report evidence is enough for this callback. |
| [UID:0000LR] `NewHumanImageLib` / [UID:000092] class | No target-support edit required. The existing report can preserve that `RenderComposition` owns the composition-record semantics while this page owns vector support; do not move target ownership to NewHumanImageLib. |
| Generated files | Do not edit manually. Let validator/autogen refresh after accepted by-* docs. |

Suggested validators after accepted implementation:

| File | Command shape |
| --- | --- |
| `by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md` | `python .\tools\validator.py --mode file --file .\by-memory\0x004e57c0-0x004e5989.RecordVectorInsert.md --apply --queue-timeout 240` |
| `by-class/RecordVector_4E57C0.md` | `python .\tools\validator.py --mode file --file .\by-class\RecordVector_4E57C0.md --apply --queue-timeout 240` |
| `by-file/VectorHelpers.md` | `python .\tools\validator.py --mode file --file .\by-file\VectorHelpers.md --apply --queue-timeout 240` |

## Residual Risks

- The 40-byte record's original source type and field names are still unrecovered. This no longer blocks the target because the accepted formal content is a range-scoped source-disposition marker, not a fabricated struct/helper body.
- If the project later chooses a compatibility `VectorHelpers.h` template or explicit binary-compat helper layer, the helper could be represented there; that decision should be project-wide and should not start from a decompiler-shaped standalone body on this page.
- Generated coverage/tracker rows are stale relative to the live target state and should refresh through the normal validator/autogen path only.

## Implementation Tracking Checklist

Implementation callback completed 2026-06-25 after supervisor acceptance. Items below are checked with proof for supervisor verification.

| Step | Required callback work |
| --- | --- |
| [x] Supervisor validation | Accepted by user callback on 2026-06-25; implementation proceeded only after acceptance. |
| [x] Lease target/support docs | Initial leases acquired with `python .\tools\leaser\leaser.py B008 lease ...` for `by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md`, `by-class/RecordVector_4E57C0.md`, and `by-file/VectorHelpers.md`; shared lease report showed B008 rows created `2026-06-25T17:42:02Z`, expiring `2026-06-25T17:47:02Z`. Released all three with `python .\tools\leaser\leaser.py B008 unlease ...`, each `Success`. A second short target-only lease was acquired/released to restore the exact marker after validator reference rewriting; final shared lease report had no B008 rows. |
| [x] Update [UID:00017U] target | `by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md` now has `COMPLETION:86`, `CONFIDENCE:90`, unchanged `CANONICAL_OWNER:0000BS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BS`, blank `EMITTER_POSITION_OPTIONAL`, and the exact formal marker from this report in `RECONSTRUCTION_CPP CODE`. |
| [x] Preserve target evidence | Target Evidence/Behavior/Reconstruction sections now incorporate current MCP proof: endpoint/server/database/worker/health, `lookup_funcs` sizes for `0x004e57c0`/`0x004e4280`/`0x004e6ff0`, `analyze_function` prototype/size/basic-block/caller/callee/no-string facts, `search_text` hit at `0x004e4c14`, `xrefs_to` for `0x004e57c0` and `0x004e6ff0`, boundary bytes/padding, 40-byte record behavior, allocator/free/runtime helper facts, copy-helper relation, and `RenderComposition` inline fast path versus grow slow path. |
| [x] Replace stale target rationale | Target now supersedes the old `90/90+` blank-C++ rationale and records marker emission as the implementation-ready disposition. It explicitly rejects standalone helper-body C++, product-domain class promotion, NewHumanImageLib method ownership for the helper body, runtime/MSVC ownership, and non-reconstructable/non-emitting reclassification. |
| [x] Update [UID:0000BS] support prose | `by-class/RecordVector_4E57C0.md` metadata unchanged at `85/86`, `CANONICAL_OWNER:0000P3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P3`. Prose now records that [UID:00017U] emits the marker because it is compiler/vector grow slow-path support for `RenderComposition` local records, while `RecordVector_4E57C0` remains a helper bucket under [UID:0000P3]. |
| [x] Update [UID:0000P3] support prose | `by-file/VectorHelpers.md` metadata unchanged. Added `RecordVector_4E57C0 Source-Disposition Notes` and updated the covered-helper/reconstruction notes: [UID:00017U] remains utility/template support and now emits a comment marker; final behavior belongs in `RenderComposition` local typed vector source or a project-wide `VectorHelpers` compatibility template, not a standalone decompiler-shaped helper body. |
| [x] No extra support edits | Checked [UID:00022R], [UID:0000LR], and [UID:000092] for direct stale contradiction. No callback edit was required: [UID:00022R]'s blank-C++ note applies to its own helper island, and the NewHumanImageLib docs already keep this helper as vector support rather than a method body. |
| [x] Do not edit generated/state/coverage files | No manual edits made to `auto-generated/*`, generated C++ files, project-level generated files, validator state/cache/lock files, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. Generated/project-level outputs changed only through validator-owned refreshes. |
| [x] Run scoped validators | Ran the required scoped validators from `source-3/project-documentation`: target command `000000001481`, timestamp `2026-06-25T13:45:13-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`; class support command `000000001485`, timestamp `2026-06-25T13:45:33-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`; file support command `000000001488`, timestamp `2026-06-25T13:45:51-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`. `VectorHelpers.md` validator reported existing `missing_ref_uid 0003SC`; unrelated stale/missing registry rows were also reported during generated refresh. |
| [x] Preserve exact marker after validator reference phase | The normal reference-phase validator expanded `[UID:...]` tokens inside the formal C++ comment. Restored the exact accepted marker under a target-only lease, then ran `python .\tools\validator.py --mode file --file by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md --uid-only --apply --queue-timeout 240`: command `000000001512`, timestamp `2026-06-25T13:47:50-04:00`, exit `0`, `ok:1`, `reference phase: False`, generated refresh skipped by `--uid-only`. |
| [x] Generated refresh expectation | Ran validator-owned `python .\tools\validator.py --mode autogen --apply --queue-timeout 240` after restoring the exact marker: command `000000001513`, timestamp `2026-06-25T13:47:55-04:00`, exit `0`, generated refresh completed. Final sanity read found `auto-generated/NexusTK/util/VectorHelpers.cpp` at newer validator-owned header metadata `validator-command-id: 000000001519`, `validator-refreshed-at: 2026-06-25T13:49:28-04:00`, with [UID:00017U] emitting the exact marker instead of an empty emitter marker. |
| [x] Report implementation results | This checklist records changed files, lease acquire/release proof, validator IDs/timestamps/exit/ok/generated-refresh state, generated-output proof, no manual generated/state/coverage edits, and no IDA DB edits. No accepted implementation items remain unchecked. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00017U-RecordVectorInsert-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00017U-RecordVectorInsert-source-quality.md","timestamp":"2026-06-25T13:53:45","uid":"00017U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
