** TARGET-REPORT-UID:00015N **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 Source-Quality Report: [UID:00015N] FramePartPaneSlotCleanup

Status: FINISHED report-only pass. No target/support by-* documentation, generated/project-level file, validator state, IDA database, lease state, or coverage report was edited.

Target: `source-3/project-documentation/by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00015N-FramePartPaneSlotCleanup-source-quality.md`

## Recommendation Summary

[UID:00015N] is source-authored `FrameChrome` cleanup code, not compiler-only glue and not a no-owner raw island. The current page already has the correct owner/emitter route and reconstructable state, but the blank formal C++ rationale is now stale under the active B-agent gate.

Current target metadata:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000JL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JL`
- formal `RECONSTRUCTION_CPP CODE` blank

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000JL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JL`
- formal `RECONSTRUCTION_CPP CODE` populated with the first-draft helper below

Recommended source-facing helper name: `ReleaseFramePartPanes`. The existing target provisional name `ClearFramePartPaneSlots` describes the final pointer state, but the body performs ownership release through the `FramePartPane` scalar deleting destructor before clearing each slot. `ReleaseFramePartPanes` also matches the local [UID:0000YI] `ReleaseDynamicAboveFrame()` naming style for frame-chrome delete-through-vtable helpers. Treat the exact original private name as inferred, not symbol-proven.

Recommended source-facing storage remains the already accepted `g_framePartPanes[5]` family. The target should keep the raw addresses and slot-role table because the original declaration could have been five private statics or an array-equivalent layout, but the source C++ should use the same array name as [UID:00022F] `BuildFramePartPanes` and [UID:00015O] `FramePartPane`.

The no-function/no-route evidence is still real and should cap confidence. It does not prove no-code: the current MCP-backed body is a unique, source-shaped, five-slot file helper over project globals, and the active gate is satisfied by `RECONSTRUCTABLE:TRUE`, a valid `FrameChrome` emitter route, and current average score `87.5`.

## MCP Session And Provenance

Current IDA MCP was mandatory for this run and was available.

- `idb_list` command id `103`: active session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, created `2026-06-24T06:15:52.461765`, last accessed during this report, backend `worker`, owned/adopted, worker pid `26892`, auto-analysis not running.
- `server_health` command id `104`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
- Tool schema check command id `116`: this MCP build exposes `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, `callees`, `get_bytes`, and `make_signature_for_range`; it does not expose `callers` or `py_eval`.
- Failed MCP tool call command id `109`: attempted `callers`; MCP responded `Method 'callers' not found`. This is a tool-availability mismatch, not an MCP outage. The route analysis below therefore uses `xrefs_to` plus a fresh local PE rel32/VA/RVA scan.

Fresh local PE route scan used the MCP-reported input executable:

- File: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- `.text`: VA `0x00401000`, raw offset `0x400`, raw size `0x20b600`

## Current Target State And Tracker Mismatch

The target by-memory page is ahead of the generated research tracker. The current target file already says `86/89`, `RECONSTRUCTABLE:TRUE`, owner/emitter `0000JL`, and blank C++ with a raw/no-route rationale. The generated tracker row at `auto-generated/-ag-research-tracker.md` still lists [UID:00015N] as `74/84`, combined `79.0`, reports `0`, and not-covered. That row is stale with respect to the target page and the 2026-06-12/2026-06-22 incorporated evidence. It explains why the queue still surfaced this target, but it is not current source truth.

`auto-generated/-ag-memory-coverage.md` routes [UID:00015N] through owner/emitter `0000JL` to `auto-generated/NexusTK/ui/core/FrameChrome.cpp` and reports no generated code for the item. Generated files are out of scope for this report-only pass and should not be edited by the B-agent implementation callback except through the normal supervisor refresh process.

One support-page stale detail also needs correction if implementation is accepted: current MCP `get_bytes` command id `117` reads `0x0069b33c-0x0069b350` as twenty zero bytes, and the PE section map shows the slot cluster lies in the unbacked `.data` tail beyond `.data` raw bytes. [UID:0001PF] still states `ff ff ff ff` initial bytes from older IDA rendering. [UID:0000PN] already carries the better unbacked-tail/zero-initialized source caveat. The exact slot page should be synced to that current evidence.

## Evidence Checked

Project/process files:

- `tools/leaser/Agents/Agent-B007/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `by-structure.md`

Target and support docs:

- `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`
- `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`
- `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`
- `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`
- `by-file/FrameChrome.md`
- `by-class/FramePartPane.md`
- `by-global/FrameChromeSlots.md`
- `by-item/BuildFramePartPanes_004B7120.md`
- `by-type/by-vtable/FramePartPaneVtables.md`
- `by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md`
- `by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md`
- `by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md`
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-memory-coverage.md`, read-only, only to explain queue/generated state

Executed B-agent reports used as leads:

- `executed-b-agent-research/B011/00022F-BuildFramePartPanes-source-quality.md`
- `executed-b-agent-research/B002/00015O-FramePartPane-source-quality.md`

Current MCP and local commands:

- MCP ids `103`, `104`, `105`, `106`, `108`, `110`, `111`, `112`, `113`, `114`, `115`, `116`, `117`, `118`, and `119`
- Local PE route scan over `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- `tools/int_convert.py` conversions for `0x83`, `0x0d`, `0x1ff`, `0xb1`, `0xa0`, `0xa4`, `0xf8`, `0xfc`, and `0x676f6f67`

## Binary Facts Rechecked

### Exact Range, Boundary, And Bytes

MCP `lookup_funcs` command id `105` reports:

- `0x004b7120` is modeled as `sub_4B7120`, size `0x1ff` / 511 bytes.
- `0x004b731f` is not a function.
- `0x004b7320` is not a function.
- `0x004b73a2` is not a function.
- `0x004b73a3` is not a function.
- `0x004b73b0` is modeled as `sub_4B73B0`, size `0x51`.

MCP `disasm` command id `106` disassembles `0x004b7320` as `<no function>` in `.text`, beginning at `0x004b7320`, and shows five repeated slot cleanup sequences followed by `retn` at `0x004b73a2` and alignment at `0x004b73a3`.

MCP `get_bytes` command id `117` returns:

- `0x004b7320-0x004b73a3`: `0x83` / 131 bytes.
- `0x004b73a3-0x004b73b0`: thirteen `0xcc` bytes.
- `0x0069b33c-0x0069b350`: twenty zero bytes in the current IDB.

MCP `make_signature_for_range` command id `118` over `0x004b7320-0x004b73a3`, with operand wildcarding disabled, returns a unique literal IDA signature. That unique signature is the five copies of `mov ecx, [slot]`, `test`, conditional branch, `mov eax, [ecx]`, `push 1`, indirect vtable call, and clear-to-zero, ending in `C3`.

The half-open target range `0x004b7320-0x004b73a3` is correct. It starts after the builder's `0xcc` boundary at `0x004b731f`, includes the final `ret` byte at `0x004b73a2`, and ends before the thirteen-byte padding run to `0x004b73b0`.

### Raw Body Behavior

The raw body has no receiver, parameters, local variables, security cookie, EH state, or stack frame. It is five unrolled copies over:

- `0x0069b33c`
- `0x0069b340`
- `0x0069b344`
- `0x0069b348`
- `0x0069b34c`

For each slot it:

1. Loads the slot pointer into `ecx`.
2. Tests the pointer and skips to the next slot if it is zero.
3. Loads the object's vtable from `[ecx]`.
4. Pushes delete flag `1`.
5. Calls vtable slot `0`.
6. Stores zero back to the same slot.

The exact read/clear sites are:

| Slot | Read/test/call sequence starts | Clear site |
| --- | --- | --- |
| `0x0069b33c` | `0x004b7320` | `0x004b7330` |
| `0x0069b340` | `0x004b733a` | `0x004b734a` |
| `0x0069b344` | `0x004b7354` | `0x004b7364` |
| `0x0069b348` | `0x004b736e` | `0x004b737e` |
| `0x0069b34c` | `0x004b7388` | `0x004b7398` |

Because the zero store is inside each non-null branch, the exact source reconstruction should not be an unconditional clear after a delete-null-safe expression. Use explicit per-slot conditional delete-and-clear blocks.

### Slot Lifecycle

MCP `xrefs_to` command id `108` reports no xrefs to cleanup entry `0x004b7320`. It also reports the complete five-slot lifecycle:

- Slot `0x0069b33c`: builder write `0x004b719b`; cleanup read `0x004b7320`; cleanup clear `0x004b7330`; notification clear `0x004b73cb`.
- Slot `0x0069b340`: builder write `0x004b71f1`; cleanup read `0x004b733a`; cleanup clear `0x004b734a`; notification clear `0x004b73d5`.
- Slot `0x0069b344`: builder write `0x004b724a`; cleanup read `0x004b7354`; cleanup clear `0x004b7364`; notification clear `0x004b73df`.
- Slot `0x0069b348`: builder write `0x004b72a3`; cleanup read `0x004b736e`; cleanup clear `0x004b737e`; notification clear `0x004b73e9`.
- Slot `0x0069b34c`: builder write `0x004b72f5`; builder allocation-failure clear `0x004b72fc`; cleanup read `0x004b7388`; cleanup clear `0x004b7398`; notification clear `0x004b73f3`.

This confirms that [UID:00015N] is the release complement to [UID:00022F] `BuildFramePartPanes`, while [UID:00015O] `FramePartPane::OnNotification` is a peer pointer-clearer that does not delete all five panes.

MCP `decompile` command id `112` for `0x004b7120` confirms the builder allocates `0xfc` / 252 bytes for each object, calls `0x004b7480` five times, and writes the same five globals. The part indexes and layout data remain:

| Source slot | Raw global | Part index | Rect before offset | Offset |
| --- | --- | ---: | --- | --- |
| `g_framePartPanes[0]` | `0x0069b33c` | 4 | `(0,0,198,6)` | `(118,12)` |
| `g_framePartPanes[1]` | `0x0069b340` | 0 | `(0,0,56,93)` | `(14,12)` |
| `g_framePartPanes[2]` | `0x0069b344` | 1 | `(0,0,57,93)` | `(365,12)` |
| `g_framePartPanes[3]` | `0x0069b348` | 2 | `(0,0,77,37)` | `(14,335)` |
| `g_framePartPanes[4]` | `0x0069b34c` | 3 | `(0,0,79,39)` | `(343,333)` |

MCP `decompile` command id `111` for `0x004b73b0` confirms `FramePartPane::OnNotification` checks tag `0x676f6f67` / decimal `1735356263` / ASCII `goog`, queues the current pane through `0x00469180`, and clears the same five globals without deleting them.

### Destructor And Vtable Slot Semantics

MCP `xrefs_to` command id `108` reports:

- `0x004b75b0` has a data xref from primary vtable base `0x0061a7fc` and code xrefs from adjustor thunks `0x004b7590` and `0x004b759b`.
- `0x0061a7fc` has vptr-store xrefs from constructor `0x004b7480`, ordinary destructor `0x004b7520`, and scalar deleting destructor `0x004b75b0`.
- `0x004b7480` has exactly five builder call xrefs from `0x004b718c`, `0x004b71e2`, `0x004b723b`, `0x004b7294`, and `0x004b72f0`.

The vtable support pages already document primary vtable slot `+0x00 -> 0x004b75b0`, secondary slot `+0x00 -> 0x004b7590`, and tertiary slot `+0x00 -> 0x004b759b`.

MCP `decompile` command id `110` for `0x004b75b0` shows the scalar deleting destructor restores all three `FramePartPane` vtable views, unregisters the `goog` listener through `0x004f4b50`, removes the pane from the layer through `0x00544ce0`, runs base cleanup through `0x00544580`, and then calls the delete helper `0x004f4ac0` when `(flags & 1) != 0` and `(flags & 4) == 0`.

The cleanup body pushes flag `1` before calling `[vtable+0]`, so the call is source-equivalent to deleting each non-null `FramePartPane*`: the ordinary destructor path runs and the delete helper is invoked. This is stronger than a generic virtual callback claim and supports a source-level `delete` expression in the formal C++.

### Route Search

MCP `xrefs_to` command ids `108` and `115` report:

- No cross-references to raw cleanup start `0x004b7320`.
- No cross-references to builder entry `0x004b7120`.
- Vtable data refs exist for `0x004b73b0` notification and `0x004b7410` paint, which is expected for virtual methods.
- No ordinary modeled refs to ordinary destructor body `0x004b7520`, which is expected because destructor invocation is represented through the scalar deleting destructor and vtables.

The local PE route scan gives the current byte-level negative proof:

| Target | rel32 call/jump refs | absolute VA dword refs | RVA dword refs | Notes |
| --- | ---: | ---: | ---: | --- |
| `0x004b7120` builder | 0 | 0 | 0 | File offset `0xb6520`, `.text`. |
| `0x004b7320` cleanup | 0 | 0 | 0 | File offset `0xb6720`, `.text`. |
| `0x004b73b0` notification | 0 | 1 | 0 | Positive control: vtable data at `.rdata` VA `0x0061a804`. |
| `0x004b7480` constructor | 5 | 0 | 0 | Positive control: five calls from builder at `0x004b718c`, `0x004b71e2`, `0x004b723b`, `0x004b7294`, `0x004b72f0`. |
| `0x004b75b0` scalar deleting destructor | 2 | 1 | 0 | Positive control: two adjustor thunk jumps and vtable data at `.rdata` VA `0x0061a7fc`. |

Conclusion: the no-route evidence is current and should stay in the target as a confidence cap. It does not prove the cleanup body is compiler-only or no-code. The byte scan also proves the scanner can find known positive rel32/vtable refs in the same neighborhood, so the zero result for `0x004b7320` is meaningful.

## Source-Quality Reanalysis

### Source-Bearing Versus No-Code

Recommended disposition: source-bearing, formal first-draft C++ ready.

Reasons:

- The body is not an adjustor thunk, scalar deleting destructor wrapper, EH funclet, security-cookie epilogue, or vtable-data artifact.
- It has no EH state variable, no stack cleanup record, no constructor-unwind table reference, and no hidden object-local temporary cleanup pattern.
- It operates over five file-global `FramePartPane*` slots with high-level object lifetime semantics.
- The vtable-slot evidence proves the indirect call is destructor/delete behavior, not an arbitrary callback.
- The adjacent builder now emits source C++ despite the same no-route result; the cleanup body is the matching release helper for those same globals.
- The current target satisfies the active gate: reconstructable, valid file emitter, and average score above 85.

Rejected no-code alternative: keeping the formal block blank solely because `0x004b7320` is not an IDA function and has no incoming ref is too conservative now. Those facts cap confidence and require an inferred helper name, but they are not a rare exact proof that no source representation is recoverable.

### Ownership And Source Placement

Keep:

- `CANONICAL_OWNER:0000JL`
- `EMITTER_UIDS:0000JL`
- source route: [UID:0000JL] `FrameChrome`, proposed `NexusTK/ui/core/FrameChrome.cpp`

Rejected owner/source alternatives:

- [UID:00005I] `FramePartPane`: too narrow. The cleanup has no `this`, no method receiver, and manages file-global slot storage.
- [UID:0000JM] `FrameMgr`: no scheduling/frame callback state is touched.
- `Pane` or generic pane manager: the body is specific to the five frame-part globals and `FramePartPane` vtable semantics.
- `ResourceLayoutTable`, EPF/ImageLib, or asset ownership: no resource lookup or layout loading occurs here.
- [UID:00022F] `BuildFramePartPanes`: the builder ends at `0x004b731f`; cleanup starts after the `0xcc` boundary and should remain a separate helper.
- [UID:00015O] `FramePartPane::OnNotification`: notification clears the same slots after queueing one pane for deferred deletion, but it does not release every live slot. The cleanup body deletes all non-null slots and clears them.
- `NONE`: too conservative. The source owner/emitter route is already established and the behavior is project source.

### Helper Name And Shape

Recommended name: `ReleaseFramePartPanes`.

The existing provisional `ClearFramePartPaneSlots` is a useful alias in evidence prose, but the source-facing helper should communicate that the body performs deletion. The closest accepted local style is [UID:0000YI] `ReleaseDynamicAboveFrame()`, which lowers to a vtable-slot delete helper in the same `FrameChrome` file family.

Recommended shape: five explicit conditional delete-and-clear blocks, not a loop. The source could have been authored as a loop over an array, but the binary is fully unrolled, and the target documentation standard favors a first draft that preserves observed control/data flow when the original spelling is not symbol-proven. Explicit blocks also preserve that the clear happens only on non-null input.

## Recommended Formal C++

The following is the exact formal `RECONSTRUCTION_CPP CODE` insertion text recommended for the target page if the supervisor accepts implementation. Do not include other sample C++ in the target outside the formal block.

```cpp
void ReleaseFramePartPanes()
{
    if (g_framePartPanes[0] != 0) {
        delete g_framePartPanes[0];
        g_framePartPanes[0] = 0;
    }

    if (g_framePartPanes[1] != 0) {
        delete g_framePartPanes[1];
        g_framePartPanes[1] = 0;
    }

    if (g_framePartPanes[2] != 0) {
        delete g_framePartPanes[2];
        g_framePartPanes[2] = 0;
    }

    if (g_framePartPanes[3] != 0) {
        delete g_framePartPanes[3];
        g_framePartPanes[3] = 0;
    }

    if (g_framePartPanes[4] != 0) {
        delete g_framePartPanes[4];
        g_framePartPanes[4] = 0;
    }
}
```

Rationale for exact draft choices:

- `ReleaseFramePartPanes` is inferred and should be documented as inferred, but it matches local `ReleaseDynamicAboveFrame` style better than a clear-only name.
- `g_framePartPanes[5]` is the accepted source-facing slot family used by the builder and class docs.
- `0` is used instead of a newer null token to match existing local first-draft style.
- The unrolled conditional blocks preserve the observed delete-and-clear branch placement.
- No manual vtable calls, raw labels, decompiler temporaries, or destructor wrapper names should appear in formal C++.

## Score Rationale

Recommended `COMPLETION:88`:

- Adds current mandatory MCP session/provenance.
- Rechecks the exact no-function boundary and byte range in the current IDB.
- Adds current unique literal signature proof.
- Rechecks slot xrefs, producer path, peer notification clearer, vtable slot, scalar deleting destructor, and positive-control route scan.
- Resolves the stale blank-C++ rationale by providing a formal first-draft helper.
- Still below `90` because no modeled function object, no direct/static route, and no original helper symbol/name were recovered.

Recommended `CONFIDENCE:90`:

- Strong agreement across current MCP disassembly, bytes, signature, decompilation, xrefs, support docs, and local PE scan.
- Confidence can reach `90` because the source behavior is exact and the delete semantics are proven through the scalar deleting destructor.
- Do not raise above `90` in this pass because the helper entry remains raw/unmodeled and unreferenced by direct rel32, VA, or RVA route.

## Recommended Implementation Edits If Accepted

Target doc:

- `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`
  - Change metadata to `88/90`, owner/emitter unchanged.
  - Update item summary to state formal C++ is now ready and current MCP/PE evidence keeps no-route as a confidence cap.
  - Replace stale "formal C++ remains blank" rationale with current gate analysis.
  - Add current MCP session id `80de0a67`, active IDB path, server health, exact byte/signature proof, and local PE route scan results.
  - Add destructor/vtable-slot proof: primary vtable slot 0 points to `0x004b75b0`, scalar deleting destructor deletes when flag `1` is pushed.
  - Preserve the no-function/no-entry-xref evidence, but mark it as confidence cap rather than no-code proof.
  - Insert the formal C++ block exactly as recommended above.
  - Record `ReleaseFramePartPanes` as inferred/source-facing, with `ClearFramePartPaneSlots` as a descriptive legacy/provisional alias.

Support docs:

- `by-file/FrameChrome.md`
  - Update the proposed contents and C++ placement notes so [UID:00015N] is a source-ready file-level release helper that emits through `FrameChrome`, while still raw/no-route.
  - Preserve rejection of `FramePartPane`, `FrameMgr`, resource, and generic pane-manager ownership.

- `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`
  - Sync the stale initial-byte wording with current MCP `get_bytes` and PE section evidence: current slot bytes are zero/unbacked `.data` tail, not a source `0xffffffff` initializer.
  - Add [UID:00015N] as source-ready `ReleaseFramePartPanes` and keep the exact read/clear xref table.
  - Preserve `g_framePartPanes[5]` as the preferred source-facing family and exact original declaration caveat.

- `by-global/FrameChromeSlots.md`
  - Add that [UID:00015N] is now first-draft source-ready as the release complement for `g_framePartPanes[5]`.
  - Keep the unbacked-tail/initializer caveat consistent with the exact slot page.

- `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`
  - Cross-reference [UID:00015N] as the accepted release/delete complement to `BuildFramePartPanes`, not part of the builder body because of the `0xcc` boundary and separate raw helper range.

- `by-item/BuildFramePartPanes_004B7120.md`
  - Update the retained index to say the cleanup counterpart is now source-ready on [UID:00015N], while the builder entry and cleanup entry both still lack static routes.

- `by-class/FramePartPane.md`
  - Add or refresh a short lifecycle note: file-level [UID:00015N] deletes all five global `FramePartPane*` slots through the scalar deleting destructor; ownership remains `FrameChrome`, not the class.

- `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`
  - Add or refresh distinction between `OnNotification` clearing the slot pointers and [UID:00015N] releasing/deleting all non-null slots.
  - Ensure the scalar deleting destructor and adjustor thunks remain compiler-generated source artifacts, while cleanup uses normal source-level delete.

- `by-type/by-vtable/FramePartPaneVtables.md` and `by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md`
  - No score change is required. If touched, only add a cross-reference from primary slot `+0x00 -> 0x004b75b0` to [UID:00015N]'s delete-through-vtable evidence; current slot facts are already sufficient.

Generated/project-level files and coverage reports:

- Do not edit generated files, project-level generated files, validator/tool state, IDA DB, or any `-coverage-report.md`.
- The generated tracker mismatch should be resolved only by supervisor/tool refresh after accepted by-* implementation.

## Implementation Tracking Checklist

- [x] Target metadata updated to `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged. Proof: `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md` now keeps `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`, blank optional position, and validator `000000000589` confirmed the metadata.
- [x] Target formal `RECONSTRUCTION_CPP CODE` populated with the exact `ReleaseFramePartPanes` block from this report. Proof: the target block now contains the five explicit non-null `delete`/zero slot clauses and validator `000000000589` changed the autogen registry state from blank to block.
- [x] Target records current MCP session `80de0a67`, command ids/evidence, exact range `0x004b7320-0x004b73a3`, `0x83` body size, and `0x0d` padding. Proof: target evidence cites the current MCP session, commands `103`, `104`, `105`, `106`, `108`, `110`, `111`, `112`, `113`, `114`, `115`, `116`, `117`, `118`, `119`, and implementation health command `201`.
- [x] Target records no-function/no-entry-xref/no-rel32/no-VA/no-RVA route evidence as a confidence cap, not a no-code proof. Proof: the target status, confidence cap, reconstruction notes, and score rationale now state that the missing modeled function/route evidence limits confidence but no longer blocks formal C++.
- [x] Target records scalar deleting destructor proof for source-level `delete`. Proof: target evidence and C++ rationale cite primary vtable slot `+0x00 -> 0x004b75b0`, flag `1` calls from the cleanup body, destructor chaining, and delete-helper behavior.
- [x] Target records producer/peer-clearer relationship with [UID:00022F] builder and [UID:00015O] notification handler. Proof: target summary and reconstruction notes distinguish builder allocation, notification pointer clearing, and this helper's file-level release/delete role.
- [x] Target records inferred helper-name rationale and rejected alternatives. Proof: target now treats `ReleaseFramePartPanes` as inferred/source-facing, keeps `ClearFramePartPaneSlots` as a descriptive legacy/provisional alias, and rejects class method, builder tail, and memory-only no-code interpretations.
- [x] `by-file/FrameChrome.md` synced with source-ready release helper and owner/emitter reasoning. Proof: the FrameChrome contents/evidence/placement notes now route [UID:00015N] through `FrameChrome.cpp` as a file-level `ReleaseFramePartPanes()` emitted by [UID:0000JL]; validator `000000000590` passed.
- [x] `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md` synced, including current zero/unbacked-tail storage correction. Proof: the slot page body records current MCP zero bytes, PE unbacked-tail context, superseded older `0xffffffff` source-initializer wording, and [UID:00015N]'s release role. 2026-06-25 correction proof: normal `--apply` validator `000000000688` exited `0`/`ok: 1` but reproduced the stale registry-backed `0xffffffff` summary, so the source line was corrected after the mutating validator and after queue status showed no pending generated refresh. Final `Select-String` readback: `by-memory\0x0069b33c-0x0069b350.FramePartPaneSlots.md:11:*** Item Summary: Five `FramePartPane*` slot globals in the PE-unbacked `.data` tail; current MCP reads twenty zero bytes, older `0xffffffff` rendering is superseded, the builder writes the slots, `ReleaseFramePartPanes` deletes non-null slots, and notification clears pointers. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`. Final scoped read-only validator `000000000701` at `2026-06-25T00:10:35-04:00` exited `0`/`ok: 1` without mutating the corrected line.
- [x] `by-global/FrameChromeSlots.md` synced with [UID:00015N] source-ready release role and storage caveat. Proof: global slot roles now separate builder writes, notification pointer-clears, and cleanup release/delete/clear behavior while carrying the current storage caveat; validator `000000000592` passed.
- [x] `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md` synced with cleanup complement note. Proof: the builder doc now keeps [UID:00015N] as the post-padding release/delete complement instead of folding it into the builder; validator `000000000593` passed.
- [x] `by-item/BuildFramePartPanes_004B7120.md` synced because the retained index still needed the cleanup-counterpart update. Proof: it now records [UID:00015N] as accepted source-ready `ReleaseFramePartPanes()` while preserving the retained non-emitting index disposition; validator `000000000594` passed.
- [x] `by-class/FramePartPane.md` synced with file-level release/delete note without changing class ownership. Proof: the class page records the cleanup helper as FrameChrome-owned/file-level and uses the vtable/delete evidence only to explain object deletion semantics; validator `000000000595` passed.
- [x] `by-memory/0x004b73b0-0x004b7661.FramePartPane.md` synced with notification-clear versus release/delete distinction. Proof: the memory page body distinguishes notification pointer clearing from the separate [UID:00015N] all-slot release/delete helper, preserves class ownership, and adds the release/delete complement in Nearby Helpers and Changes. 2026-06-25 correction proof: normal `--apply` validator `000000000689` exited `0`/`ok: 1` but reproduced the stale registry-backed "final C++ remains blank" summary, so the source line was corrected after the mutating validator and after queue status showed no pending generated refresh. Final `Select-String` readback: `by-memory\0x004b73b0-0x004b7661.FramePartPane.md:47:*** Item Summary: FramePartPane aggregate with notification, paint, constructor, destructor, compiler adjustor, and scalar wrapper evidence; formal C++ is present for the source-authored methods, and `ReleaseFramePartPanes` is documented separately as the file-level all-slot release/delete counterpart. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`. Final scoped read-only validator `000000000702` at `2026-06-25T00:10:41-04:00` exited `0`/`ok: 1` without mutating the corrected line.
- [x] Vtable support pages reviewed; no edit needed. Proof: `by-type/by-vtable/FramePartPaneVtables.md` and `by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md` already document primary vtable slot `+0x00 -> 0x004b75b0` as the scalar deleting destructor at same-or-greater detail.
- [x] Scoped file validators run with `--mode file --apply --queue-timeout 240` for each changed by-* file during implementation callback. Proof: all prior changed by-* files exited `0` with `ok: 1` as previously recorded. 2026-06-25 correction validators: `python .\tools\validator.py --mode file --file by-memory\0x0069b33c-0x0069b350.FramePartPaneSlots.md --apply --queue-timeout 240` returned `command_id: 000000000688`, `command_timestamp: 2026-06-25T00:05:32-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; `python .\tools\validator.py --mode file --file by-memory\0x004b73b0-0x004b7661.FramePartPane.md --apply --queue-timeout 240` returned `command_id: 000000000689`, `command_timestamp: 2026-06-25T00:05:37-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`. Because those mutating runs restored stale source summaries from validator-owned state, the final corrected source lines were checked with read-only scoped validators: `000000000701` at `2026-06-25T00:10:35-04:00` for the slot page and `000000000702` at `2026-06-25T00:10:41-04:00` for the FramePartPane page, both exit `0`/`ok: 1`, `generated_refresh: would-defer`.
- [x] Do not edit generated/project-level files, validator/tool state, IDA DB, leases, or any `-coverage-report.md`. Proof: no manual edits were made outside the target/support by-* docs and this B007 report; validator `--apply` reported standard registry/projected-stat side effects and deferred generated refresh; B007 leased only the two stale by-memory files for immediate edit/validator batches and released both. The current lease report after release has no active B007 entries. The stale `Item Summary` registry behavior was documented rather than repaired through forbidden manual edits to `tools/validator.ini` or tool-state files.

## Blockers

No source-documentation blocker remains for the current by-* files: the actual E-path source docs now carry the accepted [UID:00015N] details, including the corrected `Item Summary` lines read back after validation. Tool-state caveat for supervisor follow-up: normal `--apply` validation still restores stale registry-backed Item Summary text for `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md` (`000000000688`) and `by-memory/0x004b73b0-0x004b7661.FramePartPane.md` (`000000000689`) despite exit `0`/`ok: 1`; the final source pages were corrected after those `--apply` runs and read-only scoped validators `000000000701` and `000000000702` exited `0`/`ok: 1` without mutating them. Updating the validator-owned registry copy would require a forbidden manual tool-state edit by B007, so future `--apply` runs may need supervisor-approved validator-state repair if they reintroduce the stale summaries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00015N-FramePartPaneSlotCleanup-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00015N-FramePartPaneSlotCleanup-source-quality.md","timestamp":"2026-06-25T00:11:54","uid":"00015N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
