** TARGET-REPORT-UID:0002R3 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B001 Report: [UID:0002R3] LivingObjectPane Scalar Deleting Destructor

## Assignment

- Target: [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](../../../../../by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md)
- Mode: report-only research, no leases.
- Result: recommend keeping this exact range as a class-owned reconstructable compiler-generated ABI wrapper, with Rule 28 comment-only formal C++ covered by [UID:0002R0].
- MCP status: available. Live IDA MCP session `80de0a67` was used on 2026-06-25 against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status: ok`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

## Current Target State

Current working-tree target metadata already includes the previously accepted A001 edits:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00007B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007B`
- C++ block blank

The current page text correctly documents the exact boundary, vtable/data refs, cleanup callees, pool free target `0x0069b894`, and the ordinary cleanup relationship to `0x0053a5a0`. The `RECONSTRUCTABLE:TRUE` plus `EMITTER_UIDS:00007B` route is also consistent with scalar deleting destructor precedent. The stale part is the blank formal C++ and surrounding disposition text: this special emitter should not hand-author the ABI wrapper, but Supervisor rule 28 says a code emitter covered elsewhere should emit a comment marker instead of looking like missing code.

Generated files are also out of scope and must not be edited by this report. `auto-generated/-ag-memory-coverage.md` already projects this UID as `emits` through `00007B`, and that route should remain. Score/progress rows in generated reports should refresh only through the normal supervisor-owned generated-report flow.

## Current Docs Checked

I rechecked the exact target and support docs instead of relying on prior LivingObjectPane reports:

- Target [UID:0002R3] documents `sub_53D430` as `0x0053d430-0x0053d589`, with cleanup callees `0x0053b130`, `0x0053ab40`, `0x005373a0`, and pool free `0x004b14c0` against `0x0069b894`.
- [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](../../../../../by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) documents the ordinary non-deleting destructor body at `0x0053a5a0-0x0053a6a6`.
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](../../../../../by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) lists `0x0053d430-0x0053d589` as the LivingObjectPane scalar deleting destructor and keeps the broad aggregate non-emitting.
- [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](../../../../../by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md) records primary vtable slot `0x0062097c -> 0x0053d430`, adjusted slot `0x00620a00 -> 0x0053cf3e`, and adjusted slot `0x00620a30 -> 0x0053cf49`.
- [UID:0002WL][0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md) and [UID:0000TI][PoolAllocatorStaticInstances](../../../../../by-global/PoolAllocatorStaticInstances.md) confirm pool base `0x0069b894`, block size `0x20c` / 524, chunk count `0x20` / 32, and destructor free xref `0x0053d542`.
- Neighbor LivingObjectPane-family pages remain useful pattern evidence only; current scalar deleting destructor precedent also includes Decoder [UID:00013U], Encoder [UID:00013V], NumberInputDialog [UID:0001D0], EffectObjectPane [UID:000382], and Motion [UID:0002QZ] pages that stay reconstructable and class-owned while avoiding handwritten scalar-delete bodies.

## Scalar Destructor Precedent And Rule 28

The corrected disposition is not `RECONSTRUCTABLE:FALSE`. The analogous scalar deleting destructor pages rechecked for this correction use this pattern:

- Decoder [UID:00013U] and Encoder [UID:00013V] keep `RECONSTRUCTABLE:TRUE` with class emitters [UID:00003M] and [UID:00004F] while documenting that the source should declare/define the ordinary destructor and let MSVC regenerate the deleting wrapper.
- NumberInputDialog [UID:0001D0] explicitly keeps `RECONSTRUCTABLE:TRUE` because the wrapper is source-declared/generated-binary ABI output; its ordinary destructor body is represented separately by [UID:0001CX].
- EffectObjectPane [UID:000382] keeps `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000049`, and class ownership for the same vtable/thunk/delete-wrapper shape.
- Motion [UID:0002QZ] keeps `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008R`, and states that rebuild handling should express the normal destructor and pool-backed allocation policy rather than handwritten wrapper ABI.

[UID:0002R3] matches that precedent. It has class vtable reachability, adjusted thunks, an ordinary destructor counterpart at [UID:0002R0], duplicated destructor cleanup, and a pool-free tail generated from delete semantics. No target-specific exception proves that this one should be false/blank-emitter when the analogous pages are class-owned generated-binary wrappers.

Supervisor.md rule 28 resolves the apparent conflict: when a designated code emitter is a special case whose emitted code is covered by another file/UID, keep an emitted comment marker so the auto trackers do not classify it as missing code. For this target, the marker should point at [UID:0002R0], the ordinary destructor body that carries the source-facing cleanup semantics.

## Live MCP Evidence

Function and boundary evidence:

- `lookup_funcs` reports `sub_53D430` at `0x53d430`, size `0x159` / 345 bytes, ending at `0x0053d589`.
- `lookup_funcs 0x0053d589` and `0x0053d422` return "Not a function".
- `lookup_funcs 0x0053d590` reports the next function `sub_53D590`, size `0x84`.
- `get_bytes 0x0053d422 size 0x16` shows fourteen `0xcc` bytes before the `55 8b ec` prologue at `0x0053d430`.
- `get_bytes 0x0053d580 size 0x18` shows the target epilogue ending with `c2 04 00` at `0x0053d586`, followed by seven `0xcc` bytes at `0x0053d589-0x0053d590` before the Motion wrapper prologue.

Reachability evidence:

- `xrefs_to 0x0053d430` returns exactly three inbound refs: code refs at `0x0053cf44` and `0x0053cf4f`, plus data ref `0x0062097c`.
- `disasm 0x0053cf3e` shows a two-instruction adjusted thunk: `sub ecx, 0A0h`; `jmp sub_53D430`.
- `disasm 0x0053cf49` shows the matching thunk: `sub ecx, 0A4h`; `jmp sub_53D430`.
- `xrefs_to 0x0053cf3e` returns data ref `0x00620a00`; `xrefs_to 0x0053cf49` returns data ref `0x00620a30`.
- `xrefs_to 0x0062097c`, `0x00620a00`, and `0x00620a30` return constructor/destructor vptr writes from `0x0053a110`, `0x0053a360`, `0x0053a5a0`, and `0x0053d430`, matching the LivingObjectPane vtable-data page.

Behavior evidence:

- `analyze_function 0x0053d430` reports prototype `float *__thiscall(float *this, char)`, size 345, no ordinary callers, 23 basic blocks, and cyclomatic complexity 8.
- Decompile writes LivingObjectPane vtables at `this`, `this+0xa0`, and `this+0xa4`.
- The wrapper clears active state at `this+0x1bc`, calls `0x0053b130` and virtual delete/cleanup on the active effect object when present, clears `dword_67A764+0x104` and the guarded `+0x108/+0x10c` selected/hovered-style references when they point at this pane, calls `0x0053ab40`, destroys the nested `this+0x1f0` helper through `0x004b6cb0`, and calls base `ObjectPane` cleanup `0x005373a0`.
- `callees 0x0053d430` returns `0x0053b130`, `0x0053ab40`, `0x004b6cb0`, `0x005373a0`, `0x004b14c0`, and guard-check support `0x0041b6a0`.
- The delete/free tail tests the flag byte: if `(flags & 1) != 0` and `(flags & 4) == 0`, it loads pool base `0x0069b894` at `0x0053d542` and calls `0x004b14c0` at `0x0053d54e`; otherwise it returns the original pointer. The bit-4 path does not call the pool free.

Ordinary destructor comparison:

- `lookup_funcs 0x0053a5a0` reports `sub_53A5A0` size `0x106` / 262 bytes.
- `decompile 0x0053a5a0` contains the same cleanup sequence without the delete-flag and pool-free tail: vtable restores, active-effect cleanup, map-global reference cleanup, linked-object cleanup, nested helper destructor, and `ObjectPane` destructor.
- `xrefs_to 0x0053a5a0` returns ordinary code refs from `0x005a2d5f`, `0x005b8336`, and constructor-unwind `0x0060a343`.

Pool evidence:

- `xrefs_to 0x0069b894` returns five direct refs: startup construction `0x0041a107`, allocation `0x00506071`, constructor-failure free `0x00514c85`, scalar destructor free `0x0053d542`, and static cleanup `0x0060c380`.
- `callees 0x004b14c0` reaches `EnterCriticalSection` and `LeaveCriticalSection`, matching the documented `PoolAllocator::Free` mechanics.
- MCP `int_convert` confirms `0x159` = 345, `0x20c` = 524, `0x20` = 32, `0xa0` = 160, `0xa4` = 164, `0x1f0` = 496, `0x1bc` = 444, `0x104` = 260, and `0x108` = 264.

## Blocker Investigation

The blocker is handwritten scalar-deleting-destructor source, not the class-owned emitter route. With `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and report scores above the active gate, this target fits the established "source-declared/generated-binary" scalar deleting destructor category.

Blocking facts for handwritten C++:

- The target signature is a compiler deleting-destructor ABI shape: `thiscall(this, char flags)` with `retn 4`.
- Primary reachability is vtable data plus adjusted-base thunks. There are no ordinary source call sites into `0x0053d430`.
- The body duplicates the ordinary destructor body at `0x0053a5a0` and then adds delete-flag/pool/free behavior.
- The wrapper writes generated vtable slots and handles compiler delete flags; handwritten source should express the ordinary `LivingObjectPane::~LivingObjectPane()` semantics and pool-backed allocation policy, not a method named `ScalarDeletingDestructor(char)`.
- Final field names remain descriptive, but that is no longer the main blocker. The stronger blocker is source placement: exact ABI wrapper mechanics must not be hand-authored as project source.

Therefore [UID:0002R3] should keep `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00007B`, but its formal C++ should be a Rule 28 comment-only marker pointing to [UID:0002R0]. That reconciles emitter tracking with the source-quality rule that the ordinary destructor/pool policy is the source-facing reconstruction.

## Heuristic And Ownership Reanalysis

Positive owner evidence for `LivingObjectPane`:

- Decorated vtable data names and constructor/destructor vptr stores all point to `LivingObjectPane`.
- The ordinary destructor body `0x0053a5a0` and scalar wrapper `0x0053d430` share the same LivingObjectPane cleanup sequence.
- Pool xrefs tie `0x0069b894` to LivingObjectPane allocation, unwind free, scalar destructor release, and static cleanup.
- The source root remains `NexusTK/map/LivingObjectPane.cpp` through [UID:0000KU].

Negative/rejected owner evidence:

- `ObjectPane` is a base cleanup dependency through `0x005373a0`, not the owner of this wrapper.
- `PoolAllocator` owns allocation mechanics at `0x004b14c0`, not the concrete LivingObjectPane lifetime policy.
- `MapPane`/`dword_67A764` are cleanup consumers/state holders, not destructor owners.
- The adjusted thunks `0x0053cf3e` and `0x0053cf49` are vtable ABI support, not separate source methods.

Ranked disposition:

1. Keep `CANONICAL_OWNER:00007B` for semantic ownership and cross-reference routing.
2. Keep this exact target as a reconstructable class-emitted generated-binary wrapper: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, comment-only formal C++.
3. Keep source-facing destructor semantics on [UID:0002R0] / `0x0053a5a0` and class/file support pages until a future ordinary destructor C++ pass is approved.
4. Do not move the item to `PoolAllocator`, `ObjectPane`, `MapPane`, or generated reports.

## Recommended Target Changes

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:93`
- `CANONICAL_OWNER:00007B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007B`
- `RECONSTRUCTION_CPP` comment-only marker covered by [UID:0002R0]

Exact formal C++ block to paste into [UID:0002R3]:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0002R0].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended item summary:

`Compiler-generated LivingObjectPane scalar deleting destructor ABI wrapper with exact vtable/thunk refs, ordinary-destructor cleanup duplication, delete-flag handling, pool free target 0x0069b894, and Rule 28 comment-only emitted marker covered by [UID:0002R0].`

Recommended body edits:

- Change disposition from generic "reconstructable NexusTK project code" to "reviewed class-owned compiler-generated scalar deleting destructor wrapper; source body covered by [UID:0002R0]."
- Keep the exact address/range, thunk, vtable, cleanup, and pool-free evidence.
- Add the current MCP session proof from this report.
- State explicitly that no handwritten scalar-delete C++ should be added to this page.
- Add a change-log entry explaining the score/detail update from `86/88` to `90/93`, while preserving `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and adding the Rule 28 comment marker.

## Recommended Support-Doc Sync

Apply report-level detail to these support docs during the approved implementation callback:

- [UID:0001DE][LivingObjectPaneCore](../../../../../by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md): update the [UID:0002R3] child row/core-anchor wording from generic scalar destructor/source child to class-owned compiler-generated deleting-destructor wrapper; point source semantics to [UID:0002R0] ordinary destructor `0x0053a5a0` and note the Rule 28 comment-only marker.
- [UID:0002R0][LivingObjectPaneConstructionAndCleanup](../../../../../by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md): add a support note that `0x0053a5a0` is the ordinary destructor body duplicated by the generated deleting wrapper at [UID:0002R3].
- [UID:00007B][LivingObjectPane](../../../../../by-class/LivingObjectPane.md): add a destructor/source-placement note: [UID:0002R3] is class-owned generated-binary ABI glue with comment-only emitted marker; final class source should model the normal destructor/pool policy, not a handwritten scalar-delete method.
- [UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md): update the core memory docs/proposed contents so [UID:0002R3] is listed as class-owned compiler-generated wrapper evidence under `LivingObjectPane.cpp`, with emitted comment marker covered by [UID:0002R0].
- [UID:000358][LivingObjectPaneVtableData](../../../../../by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md): keep slot addresses but clarify that the first slot points to compiler-generated deleting-destructor ABI output regenerated from the class declaration.
- [UID:0002WL][LivingObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md): keep ownership and pool/free evidence; add one sentence that the `0x0053d542` xref is from the class-owned compiler-generated wrapper [UID:0002R3].

Do not edit generated coverage/report files manually. Do not add this exact target to `by-memory/-ignored.md`; the exact by-memory page should carry the reviewed class-owned generated-wrapper disposition.

## Rejected Alternatives

- Change to `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`: rejected after correction because it conflicts with scalar deleting destructor precedent and Supervisor rule 28. This target has no exception that separates it from Decoder [UID:00013U], Encoder [UID:00013V], NumberInputDialog [UID:0001D0], EffectObjectPane [UID:000382], or Motion [UID:0002QZ] style generated-binary wrappers.
- Keep `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00007B` with a blank formal C++ block: rejected because rule 28 says special emitters covered elsewhere should carry a comment marker so auto trackers do not read the page as missing code.
- Add formal C++ as `LivingObjectPane::ScalarDeletingDestructor(char flags)`: rejected because that would hand-author vtable reset slots, delete flags, adjusted-thunk behavior, and pool-free mechanics that the compiler should generate.
- Split the target range: rejected because IDA models one exact function `0x0053d430-0x0053d589`, with padding before and after. The ordinary destructor is an existing separate function, not an internal split of this target.
- Use older LivingObjectPane reports as final proof: rejected by assignment. Current MCP evidence reconfirmed the exact function and support relationships.
- Move ownership to `PoolAllocator`, `ObjectPane`, or `MapPane`: rejected because those are dependencies/consumers, not the semantic class owner.

## Implementation Checklist

- [x] Update [UID:0002R3] metadata to `90/93`, keep `CANONICAL_OWNER:00007B`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007B`, and replace the blank formal C++ body with the exact Rule 28 comment block above.
  Proof: [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](../../../../../by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) now has `COMPLETION:90`, `CONFIDENCE:93`, unchanged owner/emitter/reconstructable metadata, exact item summary text, and exact formal comment `// Emitted code for this range is covered by [UID:0002R0].` Validator command `000000001398` normalized the bare UID into a link; after all exact validators ran, B001 restored the accepted exact formal comment and item summary.
- [x] Update [UID:0002R3] status/evidence sections with live MCP proof: session `80de0a67`, function size `0x159`, xrefs from `0x0053cf44`, `0x0053cf4f`, `0x0062097c`, thunks `0x0053cf3e`/`0x0053cf49`, pool xref `0x0053d542`, and ordinary destructor comparison `0x0053a5a0`.
  Proof: target Status/Behavior/IDA MCP Evidence now records session `80de0a67`, server health, exact `0x159` range, pre/post padding, xrefs, adjusted thunks and vtable data refs, delete/free bit behavior, pool free `0x0053d542`, and ordinary destructor `0x0053a5a0` comparison.
- [x] Update [UID:0001DE] child/core-anchor wording so [UID:0002R3] is class-owned compiler-generated ABI wrapper evidence with source semantics covered by [UID:0002R0], not a handwritten source method child.
  Proof: [UID:0001DE][LivingObjectPaneCore](../../../../../by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) now has updated exact-child and core-anchor rows plus a `Scalar Deleting Destructor Wrapper Policy` section.
- [x] Update [UID:0002R0] with a note that `0x0053a5a0` is the ordinary destructor body duplicated by [UID:0002R3].
  Proof: [UID:0002R0][LivingObjectPaneConstructionAndCleanup](../../../../../by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) now has a `Scalar Deleting Wrapper Relationship` section and cross-reference to [UID:0002R3].
- [x] Update [UID:00007B] and [UID:0000KU] support notes to preserve class/file ownership while blocking handwritten scalar-deleting-wrapper emission and pointing the emitted marker to [UID:0002R0].
  Proof: [UID:00007B][LivingObjectPane](../../../../../by-class/LivingObjectPane.md) now has `Destructor Wrapper Policy`; [UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md) now has the constructor/destructor lifetime-cluster row and cross-references.
- [x] Update [UID:000358] and [UID:0002WL] to keep vtable/pool xref evidence synchronized with the generated-wrapper disposition.
  Proof: [UID:000358][LivingObjectPaneVtableData](../../../../../by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md) now identifies primary slot `0x0062097c` as [UID:0002R3] compiler-generated deleting-destructor output and notes adjusted thunks; [UID:0002WL][LivingObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md) now states xref `0x0053d542` comes from that generated wrapper.
- [x] Run these exact scoped validators only for changed by-* files during the later implementation callback and record validator proof in this checklist/report before returning implementation completion:

> Executable block R001 was removed from this report and preserved verbatim in [0002R3-LivingObjectPaneScalarDeletingDestructor-report-removed.md](0002R3-LivingObjectPaneScalarDeletingDestructor-report-removed.md). The archived block is non-authoritative and must not be executed.
  Proof: all seven exact commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with exit code `0`, `ok: 1`, and `generated_refresh: deferred`: target `command_id 000000001398`, `2026-06-25T06:48:28-04:00`; core `000000001399`, `2026-06-25T06:48:34-04:00`; construction `000000001400`, `2026-06-25T06:48:45-04:00`; class `000000001401`, `2026-06-25T06:48:55-04:00`; file `000000001402`, `2026-06-25T06:49:05-04:00`; vtable `000000001403`, `2026-06-25T06:49:12-04:00`; pool `000000001404`, `2026-06-25T06:49:17-04:00`. Core/class/file/vtable validators reported pre-existing missing-ref warnings, but each completed with `ok: 1`.

## Implementation Callback Proof

- MCP mandatory check passed before implementation: `tools/list`, `idb_list`, and `server_health` confirmed active IDA MCP session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `status: ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Lease command `python leaser.py B001 lease ...` returned `Success` for all seven changed by-* paths immediately before edits. Release command `python leaser.py B001 unlease` returned `B001: No active leases`; `current_leases.md` now shows `No active leases`.
- No generated files, coverage reports, validator cache/state, IDA DB, or project-level docs were manually edited. Validator-driven `--apply` refreshes were limited to the exact scoped validator commands above.
- All accepted items were applied. No accepted item was excluded or blocked.

## Report-Only Proof

- No leases were taken.
- No by-* docs, generated files, project-level files, validator state/cache, coverage reports, or IDA DB state were edited by this report-only pass. Existing by-* working-tree modifications were left untouched.
- Validators were not run because report-only work changed no target/support docs.
- The only intended write from this assignment is this report file under `tools/leaser/Agents/Agent-B001/research/`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002R3-LivingObjectPaneScalarDeletingDestructor-report.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002R3-LivingObjectPaneScalarDeletingDestructor-report.md","timestamp":"2026-06-25T07:01:08","uid":"0002R3"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002R3-LivingObjectPaneScalarDeletingDestructor-report-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002R3-LivingObjectPaneScalarDeletingDestructor-report.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002R3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
