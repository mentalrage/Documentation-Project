# B-Agent Research Report: [UID:0001E3] CScrollBarBackPane Scalar Deleting Destructor
** TARGET-REPORT-UID:0001E3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: malformed TARGET-REPORT-UID header **

**TARGET-REPORT-UID:** 0001E3  
**ASSIGNMENT:** B003-report-0001E3-cscrollbar-back-pane-destructor-20260624  
**TARGET DOC:** `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md`  
**REPORT PATH:** `tools/leaser/Agents/Agent-B003/research/0001E3-CScrollBarBackPaneDestructor-source-quality.md`  
**MODE:** Report-only research. No target/support by-* docs, generated files, validator state, leases, coverage reports, or IDA database state were edited.

## Final Recommendation

Keep [UID:0001E3] assigned to [UID:00003D] `CScrollBarBackPane` with `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00003D`, but do not hand-write the decompiled deleting-destructor body as C++ source. The range is an MSVC-generated scalar deleting destructor wrapper for `CScrollBarBackPane`; the source-facing teardown is represented by the class destructor/declaration and the inherited `Pane::~Pane()` base teardown.

The target's formal C++ should be populated with a comment-only emitted marker, not a function body:

```cpp
// Emitted code for this range is covered by [UID:00003D] CScrollBarBackPane.
// MSVC regenerates this scalar deleting destructor wrapper from the virtual destructor and Pane base layout.
```

Recommended post-implementation target metadata:

| Field | Recommendation |
|---|---|
| `COMPLETION` | `88` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | `00003D` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00003D` |
| `RECONSTRUCTION_CPP` | comment-only marker above |

Do not reclassify this as `NONE`: the wrapper is compiler-generated, but it is generated from the `CScrollBarBackPane` class ABI and is reachable through the `CScrollBarBackPane` vtable and adjustor thunk slots.

## Supervisor Override Compliance

Direct-scope blockers were investigated in this pass:

| Blocker | Result |
|---|---|
| IDA MCP mandatory evidence | Satisfied with read-only MCP calls against session `80de0a67`. |
| Base teardown helper identity | Resolved as ordinary `Pane::~Pane()` at `0x00544580`, not `TextButtonExControlPane`. |
| Delete helper identity | Resolved as the MemoryMan-backed operator-delete wrapper at `0x004f4ac0`. |
| Flag-bit behavior | Resolved as compiler deleting-destructor wrapper behavior; `(flags & 1)` selects delete path unless `(flags & 4)` is also set. |
| Vtable slot route | Confirmed through primary slot `0x0062101c` and adjustor slots `0x00621068`, `0x00621098`. |
| Adjustor thunk relationship | Confirmed: `0x0054259f` subtracts `0xa0` and `0x005425aa` subtracts `0xa4`, both jump to `0x00542680`. |
| C++ reconstruction policy | Resolved to comment-only emitted marker, not blank and not decompiler pseudocode. |
| Generated tracker mismatch | Identified as stale/generated state requiring validator refresh after accepted doc edits. |

## IDA MCP Evidence

MCP endpoint `http://127.0.0.1:13337/mcp` was responsive. `idb_list` showed active session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported status `ok`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

Read-only MCP facts used:

| Address | MCP result |
|---|---|
| `0x00542680` | Function `sub_542680`, size `0x55` / 85 bytes. |
| `0x0054259f` | Function `sub_54259F`, size `0xb` / 11 bytes. |
| `0x005425aa` | Function `sub_5425AA`, size `0xb` / 11 bytes. |
| `0x0053fea0` | Not an IDA function; constructor bytes are documented in the core page. |
| `0x0053fee0` | Function `sub_53FEE0`, cleanup helper, size `0x1f`. |
| `0x0053ff00` | Function `sub_53FF00`, draw method, size `0x8d` / 141 bytes. |
| `0x00544580` | Function `sub_544580`, ordinary `Pane::~Pane()` body, size `0x107` / 263 bytes. |
| `0x004f4ac0` | Function `sub_4F4AC0`, operator-delete wrapper, size `0x40`. |

`0x00542680` decompiles as a deleting-destructor wrapper:

```c
_DWORD *__thiscall sub_542680(_DWORD *Block, char a2)
{
  *Block = &CScrollBarBackPane::`vftable';
  Block[40] = &CScrollBarBackPane::`vftable';
  Block[41] = &CScrollBarBackPane::`vftable';
  sub_544580(Block);
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 )
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

Disassembly confirms the decompiler shape and the compiler-only details:

| Address | Evidence |
|---|---|
| `0x00542686` | Writes primary `CScrollBarBackPane` vtable pointer `0x0062101c` at `this+0`. |
| `0x0054268c` | Writes secondary vtable pointer `0x00621068` at `this+0xa0` / 160. |
| `0x00542696` | Writes tertiary vtable pointer `0x00621098` at `this+0xa4` / 164. |
| `0x005426a0` | Calls `sub_544580`, the ordinary `Pane::~Pane()` teardown. |
| `0x005426a8` | Tests flag bit `0x1`. |
| `0x005426ac` | Tests flag bit `0x4`. |
| `0x005426b1` | Calls `sub_4F4AC0` only on the ordinary delete path. |
| `0x005426c0` | Flag-4 path pushes object size `0xf8` / 248 and reaches `@_guard_check_icall_nop@4`; this is compiler/runtime glue, not source logic. |
| `0x005426d5` | Following bytes are `0xcc` padding until the next destructor island entry at `0x005426e0`. |

Direct xrefs to `0x00542680`:

| Xref | Meaning |
|---|---|
| `0x005425a5` | Jump from adjustor thunk `0x0054259f`. |
| `0x005425b0` | Jump from adjustor thunk `0x005425aa`. |
| `0x0062101c` | Primary `CScrollBarBackPane` vtable slot. |

Adjustor thunk MCP disassembly:

| Range | Body | Interpretation |
|---|---|---|
| `0x0054259f-0x005425aa` | `sub ecx, 0A0h; jmp sub_542680` | Secondary-base deleting-destructor adjustor for `this-0xa0`. |
| `0x005425aa-0x005425b5` | `sub ecx, 0A4h; jmp sub_542680` | Tertiary-base deleting-destructor adjustor for `this-0xa4`. |

Vtable data facts:

| Slot | Value | Meaning |
|---|---|---|
| `0x00621018` | RTTI locator `0x0064d7b0` | Primary vtable group locator. |
| `0x0062101c` | `0x00542680` | Primary deleting-destructor slot. |
| `0x00621060` | `0x0053ff00` | Draw method slot; `xrefs_to 0x0053ff00` returns data ref `0x00621060`. |
| `0x00621064` | RTTI locator `0x0064d80c` | Secondary group locator. |
| `0x00621068` | `0x0054259f` | Secondary adjustor thunk slot. |
| `0x00621094` | RTTI locator `0x0064d820` | Tertiary group locator. |
| `0x00621098` | `0x005425aa` | Tertiary adjustor thunk slot. |
| `0x0062109c` | `0x00544e90` | Inherited slot after the tertiary adjustor. |
| `0x006210a0` | RTTI locator `0x0064d834` | Successor `NewOptionPane` boundary. |

The `0x00544580` base-helper decompile restores `Pane` primary and secondary vtables (`0x006219e8`, `0x00621a34`, `0x00621a64`) and then performs `Pane` teardown. This invalidates the target page's older caveat that generated source may call `TextButtonExControlPane::~TextButtonExControlPane`; the active base teardown is `Pane::~Pane()`.

## Current Documentation State

The source target page already has substantially better metadata than generated tracker state:

| Source | Current value |
|---|---|
| Target by-memory page | `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00003D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003D`, blank formal C++. |
| Generated research tracker | Still lists UID `0001E3` as `74/84`, not-covered. |
| Generated by-memory coverage report | Still lists UID `0001E3` as `reconstructable : 74% : strong`, `emits_code:false`. |
| Generated `ScrollBar.cpp` | Shows an empty emitter marker for UID `0001E3`. |

This mismatch is generated-state drift, not a reason to edit generated files manually. After accepted by-* edits, the validator/autogen pipeline should refresh the tracker and generated `ScrollBar.cpp`.

## Inference Claim Ledger

| Claim | Evidence | Status |
|---|---|---|
| The range is a compiler-generated deleting destructor, not ordinary handwritten body logic. | Vtable restoration, base destructor call, flag-gated delete wrapper, adjustor thunk callers, MSVC shape matching neighboring destructor reports. | Proven. |
| The semantic owner is `CScrollBarBackPane`. | Vtable names and slots are `CScrollBarBackPane`; constructor/core page writes the same three vtables; adjustors route to this exact target. | Proven. |
| The emitted source route remains UID `00003D`. | The wrapper is generated from the class's virtual destructor and base layout; target is not a standalone source function. | Proven. |
| `0x00544580` is `Pane::~Pane()`, not a TextButtonEx destructor. | Decompile restores `Pane` vtables and matches `PaneCore`, `Pane` class, and `Pane` file documentation. | Proven. |
| `0x004f4ac0` is source-facing delete helper/global delete wrapper. | OperatorDeleteWrapper page documents MemoryMan-backed delete wrapper; target calls it only on `(flags & 1) && !(flags & 4)`. | Proven. |
| The flag-4 path should not be modeled as class source behavior. | Disassembly shows size push and guard/no-op runtime helper; decompile treats it as no source-level effect. | Proven for this target's reconstruction policy. |
| The target should receive a formal C++ body. | Only as a comment-only emitted marker. A function body would encode compiler ABI glue, not original source. | Resolved. |

## Ownership And Placement Analysis

Ranked owners:

1. [UID:00003D] `CScrollBarBackPane`: primary owner. All direct vtable data, adjustor thunks, and constructor/core evidence point here.
2. [UID:0000A2] `Pane`: callee/base teardown dependency only. It supplies the ordinary base destructor at `0x00544580`, but does not own this deleting wrapper.
3. [UID:000197] `OperatorDeleteWrapper`: delete-path helper only. It should remain a dependency, not an owner.
4. `NONE` / thunk-island ownership: appropriate for the adjustor thunk island parent, not for this exact vtable-addressable wrapper.

Best source placement remains `NexusTK/ui/core/ScrollBar` through the `CScrollBarBackPane` class. The target should not be moved to `Pane`, `MemoryMan`, or a no-owner compiler island.

## Source-Quality Findings

### Positive Evidence

- The target range boundaries are exact: function starts at `0x00542680`, size `0x55`, ends at `0x005426d5`, followed by `0xcc` padding before `0x005426e0`.
- Vtable/data routing is exact: primary slot `0x0062101c` targets this wrapper, draw slot `0x00621060` targets `0x0053ff00`, and secondary/tertiary slots route through the two adjustor thunks.
- The base teardown helper is resolved: `0x00544580` is ordinary `Pane::~Pane()`.
- The stale `TextButtonExControlPane` caveat can be removed from the target/class support notes.
- Existing neighboring B-agent reports on scalar deleting destructors support the same policy: represent source teardown in the class/ordinary destructor route and do not hand-port deleting-destructor glue as a normal C++ function.

### Negative Evidence

- There is no evidence for a handwritten source function corresponding one-for-one to `0x00542680`.
- There is no evidence that this wrapper belongs to `TextButtonExControlPane`.
- The vtable bytes are static compiler data and should not be hand-written in target C++.
- The adjustor thunk callers are compiler thunks and should not be assigned source bodies.
- Generated tracker and generated source rows are stale relative to the current target page; they should be regenerated, not manually patched.

## Recommended Target Doc Changes

For `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md`:

- Update the Item Summary to something like:

  `MSVC scalar deleting destructor wrapper for CScrollBarBackPane; vtable/thunk reachability, Pane::~Pane base teardown, OperatorDeleteWrapper flag path, and comment-only emitted marker policy resolved.`

- Replace the stale base-helper uncertainty with:

  `0x00544580 is the ordinary Pane::~Pane() body. IDA MCP decompile restores Pane vtables and matches PaneCore/Pane documentation; this is not TextButtonExControlPane teardown.`

- Add the exact flag behavior:

  `The wrapper calls Pane::~Pane(), then calls OperatorDeleteWrapper at 0x004f4ac0 only when (flags & 1) is set and (flags & 4) is clear. The flag-4 path is compiler/runtime glue and should not become source logic.`

- Add the exact adjustor relationship:

  `0x0054259f subtracts 0xa0 and jumps here; 0x005425aa subtracts 0xa4 and jumps here. The two thunks are referenced by vtable slots 0x00621068 and 0x00621098.`

- Populate `RECONSTRUCTION_CPP CODE` with the comment-only marker shown in the Final Recommendation.

- Recommended metadata after edits: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00003D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003D`.

## Recommended Support Doc Changes

For `by-class/CScrollBarBackPane.md`:

- Update the scalar deleting destructor row to say this range is compiler-generated wrapper glue covered by the class destructor/declaration route.
- Remove or rewrite the stale `TextButtonExControlPane` ambiguity. The base destructor call is `Pane::~Pane()`.
- Keep class/file C++ cautious if constructor/draw helper/global names are still synthetic, but do not treat `0x00544580` as unresolved.

For `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md`:

- Update constructor/cleanup/destructor-support notes to identify `0x00544460` and `0x00544580` as `Pane::Pane()` and `Pane::~Pane()` dependencies.
- Keep remaining caution on draw helper `0x004b9600`, global `dword_69B3E4`, and final class declaration/source placement names if still unresolved.

For `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md`:

- Add a nonblank Item Summary, for example:

  `CScrollBarBackPane primary, secondary, and tertiary vtable groups with deleting-destructor, draw, adjustor-thunk, inherited-slot, RTTI, and NewOptionPane successor-boundary evidence.`

- Keep formal C++ blank or comment-only per local policy for static vtable data; class declaration should regenerate the table.

For `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md`:

- Add current MCP confirmation for the first two thunks if the implementer is touching support docs: `sub ecx,0xa0; jmp 0x00542680` and `sub ecx,0xa4; jmp 0x00542680`.
- Keep the island parent `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`.

For `by-file/ScrollBar.md`:

- Keep `CScrollBarBackPane` placed in `NexusTK/ui/core/ScrollBar`.
- Note that the deleting destructor wrapper is generated from the class ABI and should appear as a comment-only emitted marker, not a handwritten function.

Do not edit generated `auto-generated/*`, validator command state, IDA DB names/comments/types, or any `-coverage-report.md` by hand.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were performed. If a later IDA annotation pass is authorized, the useful non-destructive names would be:

| Address | Suggested label |
|---|---|
| `0x00542680` | `CScrollBarBackPane_scalar_deleting_destructor` |
| `0x0054259f` | `CScrollBarBackPane_dtor_adjustor_a0` |
| `0x005425aa` | `CScrollBarBackPane_dtor_adjustor_a4` |
| `0x00544580` | `Pane_destructor` / `Pane::~Pane` |
| `0x004f4ac0` | `OperatorDeleteWrapper` |

These are recommendations only. They were not applied in this report-only pass.

## Validator And Generated State

Implementation callback applied on 2026-06-25. Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`; all listed commands exited `0` with `ok: 1`.

| File | Final relevant validator proof |
| --- | --- |
| `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md` | Default post-vtable pass: `python .\tools\validator.py --mode file --file by-memory\0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000737`, `command_timestamp:2026-06-25T00:26:01-04:00`, generated refresh completed. Final normal retry after supervisor-owned legacy coverage row correction and validator-worker restart: `python .\tools\validator.py --mode file --file by-memory\0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000801`, `command_timestamp:2026-06-25T00:41:54-04:00`, exit `0`, `ok: 1`, generated refresh completed. Readback after this normal path preserved `COMPLETION:88`, `CONFIDENCE:92`, the accepted Item Summary, and the comment-only formal C++ block. |
| `by-class/CScrollBarBackPane.md` | `python .\tools\validator.py --mode file --file by-class\CScrollBarBackPane.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000755`, `command_timestamp:2026-06-25T00:30:15-04:00`, generated refresh completed. |
| `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory\0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000757`, `command_timestamp:2026-06-25T00:30:37-04:00`, generated refresh completed. |
| `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000734`, `command_timestamp:2026-06-25T00:24:54-04:00`, generated refresh completed and registered UID `0003LR`. |
| `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` | `python .\tools\validator.py --mode file --file by-memory\0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000735`, `command_timestamp:2026-06-25T00:25:15-04:00`, generated refresh completed. |
| `by-file/ScrollBar.md` | `python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000736`, `command_timestamp:2026-06-25T00:25:33-04:00`, generated refresh completed. |

Validator note: an intermediate normal retry `000000000783` still reverted the target `Item Summary` because the validator worker retained stale manual-coverage defaults. After the supervisor restarted the worker, normal retry `000000000801` preserved the accepted summary through generated refresh. The normal reference phase still linkifies bare `[UID:00003D]` inside the comment-only C++ marker, but the formal block remains comment-only and no post-validator `--uid-only` preservation path was used.

Exact manual supervisor-owned coverage/tracker text: not applicable. No generated tracker, generated source, validator cache/state, IDA DB, project-level file, or `-coverage-report.md` file was manually edited; validator-owned refreshes/backups were allowed side effects.

## Changed Files In This Pass

- Updated `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md`.
- Updated `by-class/CScrollBarBackPane.md`.
- Updated `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md`.
- Updated `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md`.
- Updated `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md`.
- Updated `by-file/ScrollBar.md`.
- Updated this implementation checklist in `tools/leaser/Agents/Agent-B003/research/0001E3-CScrollBarBackPaneDestructor-source-quality.md`.

Leases were taken only for exact by-* files being edited. The first six-file batch expired during the long edit/validator cycle; a second batch covered final validation, and the remaining leases were released after the validator batch.

## Implementation Tracking Checklist

- [x] Update target Item Summary with the resolved scalar-deleting-destructor, `Pane::~Pane`, operator-delete, thunk, and comment-marker policy. Proof: target header now preserves the supervisor-accepted text `MSVC scalar deleting destructor wrapper for CScrollBarBackPane; vtable/thunk reachability, Pane::~Pane base teardown, OperatorDeleteWrapper flag path, and comment-only emitted marker policy resolved.` Normal validator retry `000000000801` / `2026-06-25T00:41:54-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Replace the target's stale `TextButtonExControlPane` base-helper caveat with the resolved `Pane::~Pane()` evidence. Proof: target `Touched State`, `Current Caveats`, and `Negative Evidence And Rejected Alternatives` identify `0x00544580` as ordinary `Pane::~Pane()` and classify `TextButtonExControlPane` as stale generated-name pollution.
- [x] Add the exact flag-bit behavior and flag-4 compiler/runtime-glue classification to the target evidence. Proof: target `Flag And Delete Semantics` records `(flags & 1) != 0` plus `(flags & 4) == 0` for `OperatorDeleteWrapper`, and records the flag-4 path as compiler/runtime glue rather than source logic.
- [x] Add current IDA MCP provenance for session `80de0a67`, target decompile/disasm, xrefs, bytes, and thunk disassembly. Proof: target `IDA MCP Evidence` has the 2026-06-25 B003 session, endpoint/IDB health, lookup/decompile/disasm/callees/xrefs/get_bytes/get_int/Pane destructor/thunk evidence.
- [x] Insert the exact comment-only `RECONSTRUCTION_CPP CODE` marker from this report. Proof: the formal block remains comment-only after normal validator retry `000000000801`; the normal reference phase linkifies `[UID:00003D]` inside the first comment line, but the emitted content remains comment-only and no function body was introduced.
- [x] Update target metadata to recommended `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00003D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003D`. Proof: target header has `88/92`, owner/emitter `00003D`, reconstructable `TRUE`, and blank optional position.
- [x] Update `by-class/CScrollBarBackPane.md` to remove stale base-helper ambiguity and document wrapper generation policy. Proof: class evidence and reconstruction notes resolve `0x00544580` as `Pane::~Pane()`, record the generated deleting-destructor wrapper, and keep the wrapper as a comment-marker route instead of handwritten source. Validator `000000000755` / `2026-06-25T00:30:15-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Update `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` with resolved `Pane::Pane()` / `Pane::~Pane()` dependency names while keeping unresolved draw-helper/global cautions. Proof: constructor/cleanup notes name `0x00544460` as `Pane::Pane()` and `0x00544580` as `Pane::~Pane()`; draw helper `0x004b9600` and `dword_69B3E4` cautions remain. Validator `000000000757` / `2026-06-25T00:30:37-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Add a nonblank Item Summary and refreshed vtable-slot notes to `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md`. Proof: vtable page now summarizes primary/secondary/tertiary vtable groups, deleting destructor, draw slot, adjustor thunks, inherited slot, RTTI, and NewOptionPane successor boundary; formal C++ remains blank/comment-only per static-vtable policy. Validator `000000000734` / `2026-06-25T00:24:54-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Optionally add current MCP confirmation for the first two thunks in `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md`. Proof: thunk page now records `sub ecx,0xa0; jmp 0x00542680` and `sub ecx,0xa4; jmp 0x00542680`, with vtable refs, while preserving `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`. Validator `000000000735` / `2026-06-25T00:25:15-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Update `by-file/ScrollBar.md` placement notes so the wrapper is covered through `CScrollBarBackPane` class ABI rather than a handwritten function. Proof: file role/evidence notes keep `CScrollBarBackPane` in `NexusTK/ui/core/ScrollBar` and document the deleting destructor as generated class-ABI glue with a comment-only marker. Validator `000000000736` / `2026-06-25T00:25:33-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Run the scoped validator/autogen refresh after by-* implementation edits; do not manually edit generated tracker, generated source, or coverage files. Proof: validators above ran for every changed by-* file. The final required normal target retry `000000000801` after supervisor-owned coverage-row correction and worker restart preserved the accepted summary with generated refresh completed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001E3-CScrollBarBackPaneDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001E3-CScrollBarBackPaneDestructor-source-quality.md","timestamp":"2026-06-25T00:50:25","uid":"0001E3"} -->
<!-- {"agent":"B003","command_id":"000000023041","details":"report marked for revalidation","event":"needs-revalidation","issue":"malformed TARGET-REPORT-UID header","source_path":"executed-b-agent-research/B003/0001E3-CScrollBarBackPaneDestructor-source-quality.md","timestamp":"2026-08-13T00:49:38-04:00","uid":"0001E3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
