** TARGET-REPORT-UID:0001C7 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B008 Research Report: 0001C7 MessageShowPane Scalar Deleting Destructor Source Quality

Assignment: `B008-report-0001C7-MessageShowPaneScalarDeletingDestructor-source-quality-20260627`
Agent: `Agent-B008`
Mode: report-only, no leases, no by-* edits
Target: [UID:0001C7] `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`

## Result

IDA MCP was available and used against the active `NexusTK.exe.i64` database. This is not a fallback-only report.

The current `0001C7` source-quality blocker is resolved as a no-code wrapper disposition, not as a request for more helper-name research. Reclassify [UID:0001C7] as compiler-generated MSVC scalar-deleting-destructor glue with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. The present owner/emitter route through [UID:000087] is useful context but is not correct metadata for this exact range because the range is not handwritten source.

The source-authored destructor body should be split from the existing `MessageShowPaneMethods` aggregate as a new exact child:

`by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`

That child should be the code-emitting destructor page under [UID:000087] `MessageShowPane`. Use the first-draft formal C++ below on that new child, not on `0001C7`:

```cpp
MessageShowPane::~MessageShowPane()
{
    RemoveFromLayer();
    g_pMessageShowPane = NULL;
}
```

This source shape accounts for the observed ordinary destructor order: MSVC vtable reinstall, source call to `Pane::RemoveFromLayer`, source singleton clear, then implicit `Pane::~Pane()` base destruction. It intentionally omits explicit vtable writes, `Pane::~Pane()`, `OperatorDeleteWrapper`, delete-flag tests, and the flag-4 guard path because those are compiler-generated effects around the source destructor.

## MCP Session

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Session header: `f712fc1e-b940-4445-b9e3-e80715f9dd8c`
- Active database: `b001_000241_20260627`
- IDB path reported by MCP: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Health: `ok`; module `NexusTK.exe`; image base `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready.
- Main tools used: `server_health`, `idb_list`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, and `make_signature_for_range`.
- Corrected tool checks: one initial PowerShell helper accidentally sent an empty argument object by using the reserved `$args` variable name, then one retry exposed current parameter names (`addr`, `addrs`, `start`, `end`). This report relies only on corrected successful MCP results.

## Evidence Read

- Target: `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`
- Source/class/file support: `by-class/MessageShowPane.md`, `by-file/MessageShowPane.md`, `by-file/MessageDialogs.md`
- Parent aggregate and method cluster: `by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md`, `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`
- Compiler support siblings: `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`, `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`
- Data/global support: `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md`, `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`, `by-global/g_pMessageShowPane.md`
- Base/delete support: `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`
- Precedent: `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`, plus `MessageDialogs.md` shared dialog scalar-destructor guidance.
- Generated-state leads only: `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`, `auto-generated/-ag-research-tracker.md`, and generated coverage rows were read as stale-state evidence only and must not be manually edited.

## Current State

[UID:0001C7] currently has:

- `COMPLETION:85`, `CONFIDENCE:90`
- `CANONICAL_OWNER:000087`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000087`
- blank formal C++

The page body already admits the exact scalar wrapper and says final C++ is blocked on helper/base names and scalar-deleting-wrapper decomposition. That blocker is now too broad. The helper/base names are sufficiently resolved, and the correct decomposition is to move handwritten C++ to the ordinary destructor range while making this scalar wrapper no-code.

The generated tracker and generated `MessageShowPane.cpp` are stale relative to the current by-* target: the tracker still reports old `82/85` state and generated output contains only empty emitter markers for this family. Do not edit generated files by hand; validators/generation should refresh them after accepted by-* edits.

## IDA Findings

`lookup_funcs` on the active IDB confirms the relevant modeled boundaries:

| Address | IDA name | Size | Disposition |
| --- | --- | --- | --- |
| `0x00521da0` | `sub_521DA0` | `0x220` | `MessageShowPane` constructor |
| `0x00521fc0` | `sub_521FC0` | `0x65` | ordinary non-deleting destructor body |
| `0x005226f0` | `sub_5226F0` | `0x0b` | constructor EH singleton-clear helper |
| `0x005226fb` | `sub_5226FB` | `0x0b` | secondary destructor adjustor thunk |
| `0x00522706` | `sub_522706` | `0x0b` | tertiary destructor adjustor thunk |
| `0x00522711` | not a function | n/a | 15-byte `0xcc` gap before scalar wrapper |
| `0x00522720` | `sub_522720` | `0xa6` | scalar deleting destructor wrapper |
| `0x005227c6` | not a function | n/a | `0xcc` padding after scalar wrapper |
| `0x00544ce0` | `sub_544CE0` | `0x4a` | documented `Pane::RemoveFromLayer` |
| `0x00544580` | `sub_544580` | `0x107` | documented ordinary `Pane::~Pane` |
| `0x004f4ac0` | `sub_4F4AC0` | `0x40` | documented `OperatorDeleteWrapper` |

`analyze_function 0x00521fc0` decompiles the ordinary destructor as:

```text
void __thiscall sub_521FC0(_DWORD *this)
{
  *this = &MessageShowPane::`vftable';          /* 0x521fe5 */
  this[40] = &MessageShowPane::`vftable';       /* 0x521feb */
  this[41] = &MessageShowPane::`vftable';       /* 0x521ff5 */
  sub_544CE0(this);                             /* 0x521fff */
  unk_69B4F4 = 0;                               /* 0x522006 */
  sub_544580(this);                             /* 0x522010 */
}
```

The same tool reports no modeled direct xrefs to `0x00521fc0`. That does not make the body a raw helper; it is the compiler-emitted non-deleting destructor form. It is the exact range whose source body corresponds to `MessageShowPane::~MessageShowPane()`.

`analyze_function 0x00522720` decompiles the target scalar wrapper as:

```text
_DWORD *__thiscall sub_522720(_DWORD *Block, char flags)
{
  *Block = &MessageShowPane::`vftable';          /* 0x52274c */
  Block[40] = &MessageShowPane::`vftable';       /* 0x522752 */
  Block[41] = &MessageShowPane::`vftable';       /* 0x52275c */
  sub_544CE0(Block);                             /* 0x522766 */
  unk_69B4F4 = 0;                                /* 0x52276d */
  sub_544580(Block);                             /* 0x522777 */
  if ((flags & 1) == 0 || (flags & 4) != 0)
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

The wrapper has only generated reachability:

- `xrefs_to 0x00522720` reports the secondary/tertiary adjustor-thunk code refs at `0x00522701` and `0x0052270c`, plus the primary vtable/data ref at `0x0061fa4c`.
- `xrefs_to 0x0061fa4c`, `0x0061fa98`, and `0x0061fac8` ties the three MessageShowPane vtable bases to constructor stores, ordinary destructor stores, and scalar-wrapper stores.
- `xrefs_to 0x0069b4f4` reports the singleton lifecycle refs: UI cleanup `0x005048c4`, constructor writes/clear `0x00521e01` and `0x00521e08`, ordinary destructor clear `0x00522006`, EH helper clear `0x005226f0`, scalar wrapper clear `0x0052276d`, and packet-handler reads `0x005ac0bc` and `0x005ac13f`.

The target's disassembly confirms the source/ABI split:

- `0x0052274c`, `0x00522752`, and `0x0052275c` are vtable restores, not source statements.
- `0x00522766` calls `0x00544ce0` / `Pane::RemoveFromLayer`.
- `0x0052276d` clears `g_pMessageShowPane`.
- `0x00522777` calls `0x00544580` / implicit base `Pane::~Pane`.
- `0x00522785` and `0x00522788` implement scalar-delete flag policy.
- `0x00522788` calls `0x004f4ac0` / `OperatorDeleteWrapper` only for `(flags & 1) != 0 && (flags & 4) == 0`.
- `0x005227a4` pushes object size `0x10104` and reaches the compiler/runtime guard/no-op path for flag `4`.

Raw boundary checks:

- `make_signature_for_range 0x00522711-0x00522720` returns fifteen `CC` bytes.
- `make_signature_for_range 0x005227c6-0x005227d0` returns ten `CC` bytes.
- `make_signature_for_range 0x00521fc0-0x00522025` returns a unique signature for the ordinary destructor range.
- The earlier `0x00522720-0x005227c6` target signature was also unique and matches the vtable stores, helper calls, singleton clear, flag tests, delete-wrapper call, guard branch, and `retn 4`.

## Helper And Base Name Closure

The helper/base names that blocked the current page are resolved enough for implementation:

| Binary address | Source-facing disposition | Use in source C++ |
| --- | --- | --- |
| `0x00544ce0` | `Pane::RemoveFromLayer`; documented in `PaneCore.md` and confirmed by MCP decompile as layer/focus removal around `this+0xa0` and layer pointer `this+0xa8`. | Explicit call in `MessageShowPane::~MessageShowPane()`. |
| `0x00544580` | ordinary `Pane::~Pane`; documented in `PaneCore.md`, with three Pane vtable restores and base/member teardown. | Implicit base destructor after derived destructor body; do not call explicitly. |
| `0x004f4ac0` | `OperatorDeleteWrapper`; documented global MemoryMan-backed delete wrapper. | Scalar wrapper only; do not call from source destructor body. |
| `@_guard_check_icall_nop@4` / `0x0041b6a0` path | compiler/runtime flag-4 path with size operand `0x10104`. | No source expression. |
| `0x005226fb` / `0x00522706` | compiler adjustor thunks. | Generated by inheritance/vtable layout; no source methods. |
| `0x005226f0` | constructor EH singleton-clear helper. | Generated cleanup; no source method. |

The final source does not need an invented `MessageShowPane::ScalarDeletingDestructor(char)` method. It needs a normal destructor definition plus class inheritance sufficient for MSVC to regenerate the vtable slot, adjustor thunks, scalar wrapper, and base-destructor tail.

## Heuristic Reanalysis

Positive evidence for no-code scalar wrapper:

- The target has vtable/thunk reachability but no ordinary source caller shape.
- The target exactly duplicates the ordinary destructor body at `0x00521fc0` and then adds MSVC deleting-destructor flag behavior.
- The target takes an extra `char flags` parameter and returns `this` with `retn 4`, matching MSVC scalar-deleting-destructor ABI rather than handwritten project code.
- Its extra behavior is storage-release policy: `(flags & 1)` normal delete, `(flags & 4)` guarded/no-op path, `OperatorDeleteWrapper`, and object-size push. None of those are source statements in `MessageShowPane::~MessageShowPane()`.
- Sibling pages [UID:0001C5] and [UID:0001C6] already use the correct `NONE/FALSE/blank` policy for generated EH/thunk glue. The scalar wrapper should align with that pattern.
- `MessageDialogs.md` already documents the same policy for shared dialog scalar destructors: declare/default source destructors and do not copy scalar-deleting wrapper bodies.
- `ThreadManScalarDeletingDestructor.md` provides a direct precedent: useful wrapper evidence can remain blank while the source body belongs to an ordinary destructor range or exact split.

Negative evidence and remaining limits:

- Do not mark `0001C7` dead or padding. It is live vtable destructor glue and must remain documented.
- Do not leave `0001C7` as `RECONSTRUCTABLE:TRUE` merely because it is regenerated from source declarations. In current by-structure rules, a generated glue page with no formal C++ should be `RECONSTRUCTABLE:FALSE` with blank emitter metadata.
- Do not put the ordinary destructor C++ on `0001C7`; that would place source text outside the target's own range and would make the formal block represent only a subset of the wrapper behavior.
- Do not block on `Pane::~Pane` spelling. The base destructor is already documented at `0x00544580-0x00544687`, and C++ source should express it implicitly.
- Do not block on `RemoveFromLayer` spelling. `PaneCore.md` already names `0x00544ce0-0x00544d2a` as `Pane::RemoveFromLayer`, and MCP decompile matches layer detachment behavior.

## Metadata Recommendation

For [UID:0001C7] `0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`:

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Change `CANONICAL_OWNER:000087` to `CANONICAL_OWNER:NONE`.
- Change `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`.
- Change `EMITTER_UIDS:000087` to blank `EMITTER_UIDS:`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep `RECONSTRUCTION_CPP` blank.
- Rewrite the item summary/status/reconstruction guidance to say this is compiler-generated scalar-deleting-destructor glue generated from `MessageShowPane::~MessageShowPane()` and vtable layout, not a handwritten method.

For the new exact ordinary destructor child `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`:

- New UID: allocate with the project mechanism during implementation.
- Recommended score: `COMPLETION:89`, `CONFIDENCE:91`.
- `CANONICAL_OWNER:000087`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:000087`.
- Formal C++:

```cpp
MessageShowPane::~MessageShowPane()
{
    RemoveFromLayer();
    g_pMessageShowPane = NULL;
}
```

Score rationale: exact boundary, unique bytes, clear ordinary destructor decompile, accepted `Pane::RemoveFromLayer`, accepted `Pane::~Pane`, and exact singleton write are strong. Keep confidence below final because the broader class still has open source-file split and text-builder/member-name questions.

## Required Support Updates

These are the implementation-ready support edits the callback should make if this report is accepted:

| File | Required update |
| --- | --- |
| `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md` | Reclassify to no-code generated wrapper with the metadata above; replace stale final-C++ blocker wording with the wrapper proof and cross-link the new ordinary destructor child. |
| `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md` | Create exact child for the ordinary destructor, with the metadata and C++ above. Record vtable restores and `Pane::~Pane` as compiler effects, `RemoveFromLayer()` and `g_pMessageShowPane = NULL` as source body. |
| `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md` | Add/link the new destructor child row; update the `0001C7` row to "compiler scalar-deleting destructor wrapper"; remove the generic destructor source blocker from this range while preserving broader constructor/text-builder blockers. |
| `by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md` | Update child inventory so the broad mixed island points to the new destructor child and treats `0001C7` as no-code compiler support. Keep the broad island non-emitting. |
| `by-class/MessageShowPane.md` | Replace the scalar-destructor method row with generated-wrapper wording; link the ordinary destructor row to the new child and state the destructor body is source-ready. Keep class-level formal C++ blank because constructor/text-builder/source-file split remain broader blockers. |
| `by-file/MessageShowPane.md` | Update proposed contents/boundary notes so `MessageShowPane.cpp` owns the ordinary destructor source child, while `0001C7`, `0001C6`, and `0001C5` are generated support. Preserve the standalone-vs-compact `MessageDialogs.cpp` caveat. |
| `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md` | No metadata change. Update reconstruction guidance to say the target thunk forwards to the generated scalar wrapper and source body lives in the new ordinary destructor child, not `0001C7`. |
| `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md` | No metadata change. Optionally update reconstruction guidance to cross-link the new ordinary destructor child as the source singleton-clear body. |
| `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md` | Fill the blank item summary and add that the vtable primary destructor slot reaches the generated scalar wrapper while the source destructor is the new ordinary child. Keep no vtable-array C++. |
| `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md` | Preserve metadata. Update lifecycle wording so ordinary destructor child owns the source clear; scalar wrapper/EH helper are generated duplicate clears. |
| `by-global/g_pMessageShowPane.md` | Preserve metadata and blank global C++; update lifecycle wording to distinguish source destructor clear from generated scalar-wrapper clear. |
| `by-file/MessageDialogs.md` | Optional support-only sync if edited: add that `MessageShowPane` now follows the same scalar-destructor no-code policy already documented for shared message dialog default destructors. |

Do not edit `PaneCore.md` or `OperatorDeleteWrapper.md` for this callback unless the supervisor explicitly expands the accepted work. Their current names already support the recommendation.

## Rejected Alternatives

- Reject keeping `0001C7` as `CANONICAL_OWNER:000087` / `RECONSTRUCTABLE:TRUE` with blank C++. That preserves the old contradiction: a code-eligible source owner whose exact range should not receive handwritten source.
- Reject emitting `MessageShowPane::ScalarDeletingDestructor(char flags)` or any decompiler-shaped wrapper. The flags, return value, vtable stores, optional `OperatorDeleteWrapper`, and guard branch are generated ABI behavior.
- Reject placing the destructor body on `0001C7`. The source body maps to `0x00521fc0-0x00522025`; `0001C7` contains extra generated delete policy.
- Reject explicit `Pane::~Pane()` in `MessageShowPane::~MessageShowPane()`. The base destructor call at `0x00544580` is compiler-generated after the derived destructor body.
- Reject explicit source calls to `OperatorDeleteWrapper` or the flag-4 guard helper. They are scalar-delete wrapper behavior.
- Reject leaving the report as "helper/base names unresolved." The accepted names are sufficient: `Pane::RemoveFromLayer`, `Pane::~Pane`, `g_pMessageShowPane`, and `OperatorDeleteWrapper`.

## Implementation Checklist

Accepted implementation callback completed on 2026-06-27.

- [x] Acquire leases only for files about to be edited immediately. Required core files are the target `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`, the new ordinary destructor child path, and support docs the callback authorizes.
- [x] Create `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md` with a newly allocated UID, `89/91`, owner/emitter [UID:000087], reconstructable `TRUE`, the exact ordinary destructor evidence, and the formal C++ block from this report.
- [x] Update [UID:0001C7] to `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++; rewrite the page as generated scalar-deleting-destructor support.
- [x] Update [UID:0002Y8] `MessageShowPaneMethods` and [UID:0001C3] `MessageAndMessageShowPane` child inventories to include the new ordinary destructor child and mark `0001C7` as generated support.
- [x] Update [UID:000087] `MessageShowPane` and [UID:0000LB] `MessageShowPane` file docs so the ordinary destructor is source-ready and `0001C7`/adjustor/EH helpers are no-code generated artifacts.
- [x] Update [UID:0001C6] adjustor thunk guidance and [UID:0001C5] EH helper guidance only as needed for cross-link consistency; preserve their `NONE/FALSE/blank` metadata.
- [x] Update [UID:0003PC] vtable data summary/reconstruction notes to distinguish vtable slot wrapper generation from the ordinary destructor source child.
- [x] Update [UID:0001PX] memory global page and [UID:0000RK] global page lifecycle wording so `g_pMessageShowPane = NULL` is source-owned by the ordinary destructor and duplicated by generated wrapper/EH paths.
- [x] Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, IDA DB, or MCP process state. Generated files and validator state were changed only by validator `--wait-generated`.
- [x] Run scoped validators from `source-3/project-documentation` for each edited by-* file only; used the local supported `--apply --lock-timeout 240 --wait-generated` form because this validator build does not expose `--queue-timeout`.
- [x] Re-read changed files, update/check off this report checklist only during the accepted implementation callback, capture validator proof, and release leases immediately after the edit/validator batch.

## Implementation Proof

New child UID allocation:

- Validator command `000000004791`, timestamp `2026-06-27T23:32:58-04:00`, inserted [UID:000492] for `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md` without a guessed UID, then refreshed generated outputs.

Final scoped validator rerun, all from `source-3/project-documentation`, all exited `0`; filtered proof did not emit `ok:` rows, but every command reported `generated_refresh: completed`:

| File | command_id | command_timestamp | generated_refresh |
| --- | --- | --- | --- |
| `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md` | `000000004811` | `2026-06-27T23:45:01-04:00` | completed |
| `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md` | `000000004812` | `2026-06-27T23:45:12-04:00` | completed |
| `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md` | `000000004813` | `2026-06-27T23:45:22-04:00` | completed |
| `by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md` | `000000004814` | `2026-06-27T23:45:32-04:00` | completed |
| `by-class/MessageShowPane.md` | `000000004815` | `2026-06-27T23:45:43-04:00` | completed |
| `by-file/MessageShowPane.md` | `000000004816` | `2026-06-27T23:45:53-04:00` | completed |
| `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md` | `000000004817` | `2026-06-27T23:46:03-04:00` | completed |
| `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md` | `000000004818` | `2026-06-27T23:46:14-04:00` | completed |
| `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md` | `000000004819` | `2026-06-27T23:46:24-04:00` | completed |
| `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md` | `000000004820` | `2026-06-27T23:46:35-04:00` | completed |
| `by-global/g_pMessageShowPane.md` | `000000004821` | `2026-06-27T23:46:46-04:00` | completed |

Generated-output proof:

- `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp` now contains `UID:000492 | by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md | Completion:89 | Confidence:91` followed by the accepted destructor body.
- `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp` no longer contains a stale [UID:0001C7] empty-emitter marker because [UID:0001C7] is now no-owner/no-emitter generated glue.
- `auto-generated/-ag-research-tracker.md` records [UID:000492] as `89/91`, reconstructable `true`, and [UID:0001C7] as `88/92`, reconstructable `false`.
- `auto-generated/-ag-memory-coverage.md` records [UID:000492] as `coded`, owner/emitter `000087`, output `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`, and [UID:0001C7] as `not_reconstructable`, owner `NONE`, no output file.

Lease proof:

- Fresh B008 leases were acquired for the edited by-* files before the edit/validator batch.
- Post-validator `unlease` reported no active B008 lease for each path because the lease window had already expired during validation.
- `tools/leaser/Agents/current_leases.md` recheck after the unlease attempt showed no B008 rows; only unrelated B005/B013 leases were present.

Executed validator command shape:

> Executable block R001 was removed from this report and preserved verbatim in [0001C7-MessageShowPaneScalarDeletingDestructor-source-quality-removed.md](0001C7-MessageShowPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

`--lock-timeout 240` was used in place of the report's earlier `--queue-timeout 240` suggestion because the current validator help exposes `--lock-timeout` and does not expose `--queue-timeout`.

## Residual Risks

- The ordinary destructor `0x00521fc0` currently has no direct modeled xrefs. The source-shape evidence is still strong because it is the exact non-deleting destructor body, but this is why the new child recommendation stays below final confidence.
- The class/file split between standalone `MessageShowPane.cpp` and compact `MessageDialogs.cpp` remains open. This does not block the destructor body because both candidate file routes still go through [UID:000087] and [UID:0000LB].
- Broader constructor, text-builder, and field-name questions remain separate blockers for class-level C++ and should not be folded into this scalar-wrapper callback.
- Generated tracker and generated C++ state were refreshed by validator/autogen. Future stale generated state must still be refreshed by validator, not by manual edits.

## Implementation Callback Status

Accepted implementation callback is complete. No B008 leases remain. Generated files and validator state were updated only through scoped validator runs with `--wait-generated`; no generated files, manual coverage reports, project-level generated files, MCP state, or IDA DB were hand-edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001C7-MessageShowPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0001C7-MessageShowPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-06-27T23:50:38","uid":"0001C7"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001C7-MessageShowPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001C7-MessageShowPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001C7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
