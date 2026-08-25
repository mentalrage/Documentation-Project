** TARGET-REPORT-UID:00011N **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID00011N NumericStringControlPane Destructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: populate [UID:00011N] `by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md` with formal first-draft destructor C++.
- Final disposition: keep direct owner [UID:00009M] `NumericStringControlPane`, emitter [UID:00009M], reconstructable `TRUE`; raise the target from `86/90` to `90/92`.
- Required action: update the target evidence to replace the stale opaque "font handle" wording with a MemoryMan-allocated numeric glyph buffer, record current MCP session evidence, and insert the exact formal code below.
- Confidence: high for target range, owner/emitter route, cleanup order, helper identities, and source-body shape. The remaining uncertainty is exact original field spelling, not behavior or source eligibility.

## Supporting Research

This report began as a report-only pass for `tools/leaser/Agents/Agent-B001/research/00011N-NumericStringControlPaneDestructor-source-quality.md`. After supervisor Gate 1 passed, B001 completed the implementation callback on 2026-07-09: accepted by-* target/support docs were edited under short leases, scoped validators were run, validator-owned generated refresh completed, and the report ledger/checklist was updated. B001 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, queues, locks, or IDA DB state.

MCP availability was rechecked after the supervisor reopened the IDB. `idb_list` reported active session `supervisor_nexustk_20260709` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `20864`. `server_health(database='supervisor_nexustk_20260709')` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.

The initial pause before this report was correct: an earlier MCP check returned zero IDB sessions. This report uses the restored current MCP session and does not rely on fallback-only research.

## Target

- Target UID: `00011N`
- Target path: `by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md`
- Source queue/report row before callback: `auto-generated/-ag-research-tracker.md` listed [UID:00011N] at `86/90`, combined `88.0`, reconstructable `true`, reports `0`.
- Generated state before callback: `auto-generated/NexusTK/ui/controls/NumericStringControlPane.cpp` was refreshed by validator command `000000008034` at `2026-07-08T18:01:19-04:00` and still showed [UID:00011N] as `Empty Emitter Marker`.
- Callback generated state: scoped validators with `--wait-generated` refreshed `auto-generated/NexusTK/ui/controls/NumericStringControlPane.cpp` at command `000000008062`, timestamp `2026-07-09T02:42:27-04:00`; UID00011N now shows `Completion:90 | Confidence:92` and emits the formal destructor body.
- Current supervisor classification: implementation callback complete; awaiting supervisor Gate 2 verification and supervisor-owned `execute_report`.
- Current scores and parent state after callback: target `90/92`, owner/emitter [UID:00009M] `NumericStringControlPane`; class parent `86/90`; file route [UID:0000M2] `86/88`.

## Current Target State

Current target metadata after callback:

```text
UID:00011N
COMPLETION:90
CONFIDENCE:92
CANONICAL_OWNER:00009M
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009M
RECONSTRUCTION_CPP: populated with NumericStringControlPane::~NumericStringControlPane()
```

Current body state after callback:

- The page records the half-open range `0x004999d0-0x00499a4e`, no ordinary direct xrefs, vtable restore writes, `+0x108` wide-string cleanup, `+0x114` `m_numericGlyphs` cleanup, and base Pane teardown.
- The old "font handle release" wording has been historicalized; current support and MCP evidence show `+0x114` is a `LoadDatFileBuffer` returned memory buffer for `9X11FONT.BIN`, freed through `GetMemoryMan()` / `MemoryMan::FreeBufferMemory`.
- The formal C++ block now contains the accepted guarded `m_numericGlyphs` release. The active by-structure code-entry gate is satisfied: reconstructable true, nonblank emitter route to a valid file route, and `(90 + 92) / 2 > 85`.
- Related constructor/core/scalar support pages were updated so old `95/95` reconstruction-code bar language no longer implies UID00011N is blocked.

Related target/support docs checked: [UID:00011L], [UID:00011M], [UID:00011N], [UID:00011O], [UID:000121], [UID:000124], [UID:00009M], [UID:0000M2], [UID:0003IR], [UID:0002OD], [UID:0003XD], [UID:00016G], [UID:0001BC], [UID:0001BF], [UID:0001BD], [UID:000197], [UID:0002RN], [UID:0001EA], [UID:0000A2], and [UID:0000MC].

## Executive Recommendation

The best direct owner remains [UID:00009M] `NumericStringControlPane`, emitted through [UID:0000M2] `NexusTK/ui/controls/NumericStringControlPane.cpp`. No split, merge, rename, owner change, or emitter change is required for UID00011N.

The source-authored destructor body should be represented as freeing the loaded numeric glyph buffer when non-null. The binary's vtable restores, SEH/security-cookie frame, `sub_582B70(this + 0x108)` wide-string member cleanup, `sub_544580(this)` Pane base teardown, and scalar-delete flag/free handling are compiler/member/base/destructor-wrapper output and should not be handwritten in the source body for UID00011N.

## Supervisor Active Recheck

- Supervisor assignment: UID00011N report-only pass with MCP required, followed by Gate 1 implementation callback for the accepted target/support edits.
- MCP condition: satisfied by session `supervisor_nexustk_20260709`, health `ok`.
- Split repair: not required. Current MCP confirms the target is one modeled `0x7e` function, preceded by fifteen `0xcc` bytes after the constructor and followed by two `0xcc` bytes before render.
- Source-bearing children: constructor [UID:00011L], destructor [UID:00011N], render [UID:00011O], scalar wrapper [UID:000124], vtable data [UID:0002OD], and glyph helper [UID:0003XD] are already separate pages. This report does not create child files.

## Inference Research Guidance Check

Facts from current MCP:

- UID00011N decompiles to a conditional `+0x114` free, then `+0x108` wide-string destructor, then Pane base teardown.
- Constructor `0x00499910` stores `sub_4BB120(..., 99, ...)` into `+0x114`.
- Render `0x00499a50` passes `+0x114` into the numeric glyph tile-context helper at `0x004bb1e0`.
- `0x00516030` returns `g_pMemoryMan`; `0x00516170` calls CRT free and returns zero.

Documentation evidence:

- [UID:00016G] now emits `LoadDatFileBuffer` returning a `char *` allocated through `GetMemoryMan()->AllocateBufferMemory`.
- [UID:0001BC] emits `MemoryMan* GetMemoryMan()`.
- [UID:0001BF] emits `void *MemoryMan::FreeBufferMemory(void *buffer)` with `free(buffer); return 0;`.
- [UID:0002RN] documents `0x00582b70` as the wide string release/destructor wrapper.
- [UID:0001EA]/[UID:0000A2]/[UID:0000MC] document `0x00544580` as ordinary Pane base teardown.

Inference:

- The source-facing field at `+0x114` should be treated as a loaded numeric glyph buffer, not an opaque font handle. Recommended first-draft field name: `m_numericGlyphs`, type `char *`.
- The source-facing destructor body is the conditional buffer free. The rest of the binary body is compiler lowering from class members and base classes.
- Wave2/Wave3 generated material was not used as authority. Current generated C++ was used only as an empty-emitter state check.

## Heuristic / Inference Reanalysis And Validation

1. Helper identity blocker: resolved. `0x00516030` is not a font release helper; it is [UID:0001BC] `GetMemoryMan`. `0x00516170` is [UID:0001BF] `MemoryMan::FreeBufferMemory`, not a DAT or font-specific API.

2. Field naming blocker: resolved to source-ready inferred names. `+0x108` is the existing wide string member, recommended `m_text`; `+0x10c` is `m_alignment`; `+0x110` is `m_colorVariant`; `+0x114` is the `LoadDatFileBuffer` result consumed by render, recommended `m_numericGlyphs`. These are inferred names, not recovered original symbols, but they are materially better than raw offsets or "font handle" and are sufficient for first-draft destructor C++.

3. Source-body shape blocker: resolved. The body should not transcribe the decompiler. The handwritten source is only the guarded glyph-buffer free; compiler output accounts for vtable resets, member/base destructors, SEH, and security-cookie scaffolding.

4. Scalar deleting destructor relationship: resolved. [UID:000124] repeats the ordinary destructor cleanup and adds delete-flag logic. It is reached by the primary vtable slot `0x00618390` and the two adjustor thunks. UID00011N owns the ordinary source destructor body; UID000124 should document compiler wrapper behavior and must not duplicate a handwritten destructor body.

5. Reachability blocker: resolved. UID00011N has no direct xrefs, but that is normal for an ordinary non-deleting destructor retained alongside vtable/scalar wrapper machinery. The lack of direct xrefs does not make it dead code or no-owner.

6. Range/split blocker: resolved. Current MCP confirms exact function sizes and padding: constructor `0x00499910-0x004999c1`, fifteen `0xcc` bytes, destructor `0x004999d0-0x00499a4e`, two `0xcc` bytes, render `0x00499a50-0x00499be7`.

Rejected alternatives:

- Leave formal C++ blank because old docs say "95/95": rejected. Current by-structure uses combined-score/emitter eligibility and target-specific source readiness.
- Write vtable stores, `m_text` destructor, or `Pane::~Pane()` explicitly: rejected as compiler/member/base cleanup.
- Route ownership to MiniMap: rejected. MiniMap has constructor consumers only; the implementation is a reusable control.
- Route ownership to DATFile or MemoryMan: rejected. Those are helper dependencies for loading/freeing the buffer, not owners of this UI control destructor.
- Emit source through scalar wrapper [UID:000124]: rejected. UID000124 is compiler scalar-deleting destructor glue around the ordinary destructor source semantics.

## Evidence Standards Used

Evidence types used:

- Current IDA MCP `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, and `get_bytes`.
- Constructor/destructor/render/scalar comparison.
- Vtable data and vptr-store xrefs.
- Helper source pages for MemoryMan, LoadDatFileBuffer, StringBase, and Pane teardown.
- Generated C++ empty-marker state as non-authoritative current output evidence.
- Tracker/coverage rows as queue/status evidence.
- Prior executed B reports only as leads after targeted search.

The evidence is strong because the target body is small, the helper identities now have accepted source-ready support pages, current MCP confirms the exact body and xref route, and the constructor/render data flow proves what `+0x114` stores and how it is consumed. Confidence remains below final-audit range because exact original field spelling and final class header layout are inferred.

## Evidence Checked

IDA MCP checks performed against `supervisor_nexustk_20260709`:

- `idb_list`, `server_health`, `tools/list`.
- `lookup_funcs` for `0x00499910`, `0x004999c1`, `0x004999d0`, `0x00499a4e`, `0x00499a50`, `0x00499be7`, `0x0049af7f`, `0x0049af8a`, `0x0049b2f0`, `0x0049b3af`, `0x00516030`, `0x00516170`, `0x00582b70`, `0x00544580`, `0x004f4ac0`, and `0x0041b6a0`.
- `analyze_function`, `decompile`, and `disasm` for `0x004999d0`.
- `analyze_function`, `decompile`, and `disasm` for `0x0049b2f0`; `disasm` for adjustor thunks at `0x0049af7f` and `0x0049af8a`.
- `decompile` for constructor `0x00499910` and render `0x00499a50`.
- `decompile` for `0x00516030`, `0x00516170`, and `0x00582b70`; `analyze_function` for `0x00544580`.
- `xrefs_to` for `0x004999d0`, `0x0049b2f0`, `0x0049af7f`, `0x0049af8a`, `0x00499a50`, `0x00618390`, `0x006183f8`, `0x00618428`, `0x006183d4`, `0x0061838c`, `0x006183f4`, and `0x00618424`.
- `get_bytes` for padding at `0x004999c1`, `0x00499a4e`, `0x00499be7`, `0x0049b3af`, and vtable data at `0x0061838c`.

Docs/reports checked:

- Target and NumericStringControlPane support docs listed in `Current Target State`.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and generated `auto-generated/NexusTK/ui/controls/NumericStringControlPane.cpp`.
- Targeted prior report searches for `00011N`, `0x004999d0`, `NumericStringControlPaneDestructor`, `NumericStringControlPane`, `0003XD`, `00016G`, `9X11FONT`, and related address terms.

Negative checks:

- `xrefs_to 0x004999d0` returned zero xrefs.
- `xrefs_to 0x00499a50` returned only data xref `0x006183d4`.
- `xrefs_to 0x0049b2f0` returned only two adjustor-thunk code refs plus primary destructor slot data xref.
- No executed report for UID00011N was found; only related support reports for [UID:0003XD] and [UID:00016G] were relevant.

Callback checks:

- Report-only pass correctly ran no validators; implementation callback ran scoped validators for every edited by-* file.
- No IDA mutation/rename/type/comment action was attempted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00011N-01 | UID00011N exact range is `0x004999d0-0x00499a4e`, size `0x7e`, with two `0xcc` bytes before render. | Very high | MCP `lookup_funcs`, `get_bytes`, target disasm. | Target Evidence/Covered Range | incorporate | applied |
| C-00011N-02 | `+0x114` is a MemoryMan-allocated `LoadDatFileBuffer` result for `9X11FONT.BIN`, not an opaque font handle. | High | Constructor decompile, render decompile, [UID:00016G], MemoryMan helpers. | Target Teardown Order; class/file field notes | incorporate | applied |
| C-00011N-03 | First-draft destructor C++ should conditionally assign `m_numericGlyphs = GetMemoryMan()->FreeBufferMemory(m_numericGlyphs)` with a cast. | High | Target disasm/decompile, [UID:0001BC], [UID:0001BF]. | Target formal C++ | incorporate | applied |
| C-00011N-04 | Vtable stores, SEH/security-cookie code, wide-string cleanup, and Pane base teardown are not handwritten destructor source. | High | Target disasm, [UID:0002RN], [UID:0001EA], [UID:0000A2]. | Target C++ Policy/Rejected alternatives | incorporate | applied |
| C-00011N-05 | Scalar deleting destructor [UID:000124] repeats the cleanup and adds compiler delete-flag logic; it should not duplicate the ordinary destructor source body. | High | MCP scalar decompile/disasm, xrefs to scalar, support doc. | UID000124 support notes | incorporate | applied |
| C-00011N-06 | Owner/emitter route remains [UID:00009M] -> [UID:0000M2]. | Very high | Vtable names, vptr stores, class/file docs, tracker. | Target metadata/source placement | already-present | already-present |
| C-00011N-07 | Current generated `NumericStringControlPane.cpp` is stale/empty for UID00011N relative to this recommendation. | High | Generated file header `000000008034`, empty marker. | Target/support generated-state notes | incorporate | applied |
| C-00011N-08 | No split, new child, manual coverage, or tracker edit is needed in report-only pass. | High | MCP ranges/padding, existing child inventory, workflow boundary. | Checklist/Changed Files | not-applicable | not-applicable |

## Positive Evidence Summary

- Current MCP decompile of UID00011N reads `this + 0x114`, stores three NumericStringControlPane vtables, frees `+0x114` only when non-null, destroys `+0x108`, and calls Pane teardown.
- Constructor current MCP decompile stores the result of `LoadDatFileBuffer(L"9X11FONT.BIN", 99, ...)` into `+0x114`.
- Render current MCP decompile passes `+0x114` to `0x004bb1e0` and uses `+0x110` as the glyph color/style variant.
- Accepted MemoryMan support pages resolve `0x00516030` and `0x00516170` to source-facing `GetMemoryMan()` and `MemoryMan::FreeBufferMemory`.
- Vtable/xref evidence ties the destructor family directly to NumericStringControlPane and no other UI control.

## IDA MCP Facts

Function/range facts:

- `lookup_funcs 0x004999d0 -> sub_4999D0`, size `0x7e`.
- `lookup_funcs 0x00499a4e -> Not a function`; `lookup_funcs 0x00499a50 -> sub_499A50`, size `0x197`.
- `lookup_funcs 0x00499910 -> sub_499910`, size `0xb1`; `0x004999c1` is not a function.
- `lookup_funcs 0x0049b2f0 -> sub_49B2F0`, size `0xbf`; `0x0049b3af` is not a function.

Body facts:

- UID00011N instructions at `0x004999fb`, `0x00499a01`, and `0x00499a0b` write vtables `0x00618390`, `0x006183f8`, and `0x00618428`.
- `0x00499a15-0x00499a26` tests `+0x114`, calls `sub_516030`, moves returned manager to `ecx`, calls `sub_516170`, and stores returned zero to `+0x114`.
- `0x00499a2c-0x00499a32` calls `sub_582B70` on `+0x108`.
- `0x00499a37-0x00499a39` calls `sub_544580` with `this`.

Xref facts:

- `xrefs_to 0x004999d0`: zero xrefs.
- `xrefs_to 0x0049b2f0`: code xrefs at `0x0049af85` and `0x0049af90`, data xref at `0x00618390`.
- `xrefs_to 0x0049af7f`: data xref at `0x006183f8`; `xrefs_to 0x0049af8a`: data xref at `0x00618428`.
- `xrefs_to 0x00499a50`: data xref at `0x006183d4`.
- Vtable base xrefs: `0x00618390`, `0x006183f8`, and `0x00618428` are written by constructor, ordinary destructor, and scalar deleting destructor.

Padding/data facts:

- `0x004999c1-0x004999d0`: fifteen `0xcc` bytes.
- `0x00499a4e-0x00499a50`: two `0xcc` bytes.
- `0x00499be7-0x00499bf0`: nine `0xcc` bytes.
- `0x0049b3af-0x0049b3b0`: one `0xcc` byte.
- `get_bytes 0x0061838c size 164` matches the vtable cluster layout documented by [UID:0003IR]/[UID:0002OD].

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00499910-0x004999c1` | UID00011L constructor | Source constructor, initializes `m_text`, `m_alignment`, `m_colorVariant`, `m_numericGlyphs`. | TRUE | 00009M | 88/92 | Support; no code change in this report. |
| `0x004999d0-0x00499a4e` | UID00011N destructor | Source ordinary destructor body. | TRUE | 00009M | 86/90 -> 90/92 recommended | Target; formal C++ recommended. |
| `0x00499a50-0x00499be7` | UID00011O render | Source render virtual. | TRUE | 00009M | 86/90 | Support; no code change in this report. |
| `0x0049af7f-0x0049af95` | UID000121 adjustor thunks | Compiler-generated adjustor thunk pair. | FALSE | NONE | 88/92 | No source body. |
| `0x0049b2f0-0x0049b3af` | UID000124 scalar deleting destructor | Compiler deleting wrapper repeating ordinary cleanup and delete flag behavior. | TRUE current docs | 00009M | 86/90 | Support; document no duplicate source body. |
| `0x0061838c-0x00618430` | UID0002OD vtable data | Source-declared/generated-binary vtable data. | TRUE | 00009M | 88/92 | Support; no handwritten dwords. |
| `0x004bb1e0-0x004bb252` | UID0003XD glyph helper | Numeric glyph tile-context helper. | TRUE | 0000M2 | 85/88 | Support; proves render use of `m_numericGlyphs`. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004999d0` | zero xrefs | Ordinary non-deleting destructor has no direct static callers. |
| `0x0049b2f0` | `0x0049af85`, `0x0049af90`, `0x00618390` | Scalar wrapper route through adjustor thunks and primary destructor slot. |
| `0x0049af7f` | `0x006183f8` | Secondary destructor thunk slot. |
| `0x0049af8a` | `0x00618428` | Tertiary destructor thunk slot. |
| `0x00499a50` | `0x006183d4` | Render virtual slot. |
| `0x00618390` | `0x00499951`, `0x004999fb`, `0x0049b322` | Primary vptr stores in constructor/destructor/scalar wrapper. |
| `0x006183f8` | `0x00499957`, `0x00499a01`, `0x0049b328` | Secondary vptr stores. |
| `0x00618428` | `0x00499961`, `0x00499a0b`, `0x0049b332` | Tertiary vptr stores. |
| `0x00516030` | callee from target and scalar wrapper | MemoryMan singleton accessor. |
| `0x00516170` | callee from target and scalar wrapper | MemoryMan free-and-return-zero helper. |
| `0x00582b70` | callee from target and scalar wrapper | Wide string member destructor/release. |
| `0x00544580` | callee from target and scalar wrapper | Pane base ordinary destructor/teardown. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00011L] identifies constructor storage of `9X11FONT.BIN` result at `+0x114`.
- [UID:00011O] identifies render consumption of `+0x114`.
- [UID:00009M] and [UID:0000M2] provide class/file owner route.
- [UID:0003IR] and [UID:0002OD] provide vtable ownership and slot refs.
- [UID:00016G], [UID:0001BC], and [UID:0001BF] resolve loader/allocator/free helper names.
- [UID:0002RN] and [UID:0001EA] resolve wide-string and Pane cleanup as member/base cleanup.

Existing docs that are stale or incomplete:

- UID00011N and support pages say "font handle"; current evidence is a MemoryMan-allocated glyph buffer pointer.
- UID00011L, UID00011M, UID00011O, and UID000124 preserve older blank-C++ wording tied to the prior `95/95` bar. That should be historicalized or replaced with target-specific current code/no-code reasoning.
- Generated `NumericStringControlPane.cpp` was stale before callback, but validator command `000000008062` refreshed it to show UID00011N at `Completion:90 | Confidence:92` with the formal destructor body.

## Ranked Ownership Analysis

### 1. [UID:00009M] NumericStringControlPane

- Evidence for: destructor writes NumericStringControlPane vtables; constructor/render/scalar family share field layout and vtable data; class page owns the method family; file route clears through [UID:0000M2].
- Evidence against: exact original field spellings are not recovered; constructor callers are MiniMap-only in current static evidence.
- Decision: accepted direct owner. Caller specialization does not outweigh class/vtable/field evidence.

### 2. [UID:0000M2] NumericStringControlPane.cpp

- Evidence for: source-file route already owns class, constructor, destructor, render, vtable data, and glyph helper; projected path is `NexusTK/ui/controls/`.
- Evidence against: final original grouping of small UI controls is not proven beyond current file inference.
- Decision: accepted emitter route through the class to this file. No file move recommended.

### 3. [UID:0000LE] MiniMap / MiniMapDialog

- Evidence for: current direct constructor callers are minimap coordinate controls.
- Evidence against: destructor has no MiniMap-specific state; class is a reusable fixed numeric control; render and vtable routes are class-owned.
- Decision: rejected as owner. MiniMap is a consumer.

### 4. [UID:0000IN] DATFile / [UID:0000L7]/[UID:00007U] MemoryMan

- Evidence for: constructor loads through `LoadDatFileBuffer`; destructor frees through MemoryMan.
- Evidence against: these are dependencies. The receiver, field, vtables, render use, and class ownership belong to NumericStringControlPane.
- Decision: rejected as owner.

### 5. [UID:000124] Scalar deleting destructor

- Evidence for: scalar wrapper repeats the cleanup and is vtable-reached.
- Evidence against: scalar wrapper is compiler delete glue generated from the ordinary destructor and class declaration. It should not own the handwritten source body.
- Decision: support evidence only, not the source-body owner.

## Source Placement

Recommended placement: `NexusTK/ui/controls/NumericStringControlPane.cpp`, through [UID:00009M] `NumericStringControlPane`.

This placement fits the source-tree and subsystem context because the method is a class destructor for a reusable `ControlPane`-derived numeric text renderer, not a file-level DAT/MemoryMan helper or minimap-only local class. The constructor, ordinary destructor, render virtual, vtable data, and numeric glyph helper all route through the same source family.

Rejected placements:

- `MiniMap.cpp`: only consumes constructor.
- `DATFile.cpp`: owns the generic loader, not the UI field lifecycle.
- `MemoryMan.cpp`: owns allocator/free policy, not the object field.
- `GrafPort.cpp`/`FontImageLib.cpp`: render dependencies and neighboring helper context do not own the destructor.

Remaining placement uncertainty: exact original project grouping of tiny UI controls is still medium-high rather than final. This does not block the target destructor because the current route already clears source-output requirements and matches class ownership.

## Range / Split / Padding / Reclassification Analysis

No split or reclassification is recommended for UID00011N.

Exact facts:

- Constructor ends at `0x004999c1`; `0x004999c1-0x004999d0` is padding.
- UID00011N starts at `0x004999d0`, size `0x7e`, and returns at `0x00499a4d`.
- `0x00499a4e-0x00499a50` is padding.
- Render starts at `0x00499a50`.

Scalar/delete support:

- [UID:000124] is separate and non-contiguous at `0x0049b2f0-0x0049b3af`.
- [UID:000121] adjustor thunks are separate compiler glue at `0x0049af7f-0x0049af95`.
- No child creation, merge, or broad-range parent output is needed.

## Negative Evidence Summary

- No direct xrefs to `0x004999d0`: this proves no ordinary direct call route, not deadness. The destructor is represented through class destructor semantics and scalar/vtable machinery.
- MiniMap constructor callers do not prove MiniMap ownership. They allocate/use the control; they do not own its vtables or destructor.
- The presence of `LoadDatFileBuffer`, `GetMemoryMan`, `FreeBufferMemory`, StringBase, and Pane callees does not transfer owner/emitter status away from NumericStringControlPane.
- The render virtual's callback/GrafPort dependencies do not make the destructor GrafPort-owned.
- `+0x114` is not a Windows font handle or DAT manager handle; current evidence shows a raw allocated glyph buffer pointer.
- Writing decompiler-shaped code for vtable stores and base/member destructor calls would duplicate compiler output and likely hurt binary/source fidelity.

## IDA Rename / Type / Comment Recommendations

No IDA DB rename/type/comment edits are requested in this report.

Recommended source-facing names for by-* documentation and first-draft C++:

- `+0x108`: `m_text`, wide-string member.
- `+0x10c`: `m_alignment`, with values `1` right, `2` centered, otherwise left.
- `+0x110`: `m_colorVariant`, byte used by the glyph helper.
- `+0x114`: `m_numericGlyphs`, `char *` loaded from `LoadDatFileBuffer(L"9X11FONT.BIN", 99, ...)` and freed through `GetMemoryMan()->FreeBufferMemory`.

These names are inferred, not recovered original symbols. They are source-ready enough for first-draft code because they are role-accurate, consistent with current support docs, and avoid raw offsets/decompiler names.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Reason: UID00011N is reconstructable, has nonblank `EMITTER_UIDS`, clears the active combined-score gate, has current MCP proof for its exact body and boundaries, and the meaningful helper names are resolved by accepted support pages.

Exact formal insertion text for [UID:00011N]. Keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank and replace only the multiline BEGIN/END content with:

```cpp
NumericStringControlPane::~NumericStringControlPane()
{
    if (m_numericGlyphs != NULL) {
        m_numericGlyphs = static_cast<char *>(GetMemoryMan()->FreeBufferMemory(m_numericGlyphs));
    }
}
```

Reason it preserves exact original behavior:

- The null guard matches `test eax,eax; jz`.
- `GetMemoryMan()` matches `call sub_516030`.
- `FreeBufferMemory` matches `mov ecx,eax; call sub_516170`.
- Assigning the returned pointer matches the store of `EAX` back to `+0x114`; [UID:0001BF] documents that this helper returns zero.
- The cast is source-only and has no runtime effect.

Reason it matches plausible original source shape:

- It uses class/member source names instead of raw offsets.
- It avoids handwritten vtable stores, SEH, security-cookie code, scalar-delete flags, explicit member destructor calls, and explicit base destructor calls.
- It follows the accepted project pattern where MemoryMan free helpers return a null pointer used for field clearing.

Exact no-code proof for omitted binary operations:

- Vtable stores are compiler destructor lowering from the polymorphic class declaration.
- `sub_582B70(this + 0x108)` is the implicit destructor of the `m_text` wide-string member.
- `sub_544580(this)` is the implicit Pane/ControlPane base destructor chain.
- [UID:000124] owns documentation of the scalar delete-flag wrapper; UID00011N should not hand-author it.

## Final Recommendation

Recommended target changes:

- Update [UID:00011N] metadata to `COMPLETION:90`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00009M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009M`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact destructor C++ above.
- Update prose to record current MCP session `supervisor_nexustk_20260709`, helper identities, field names, no-direct-xref caveat, scalar relationship, and compiler/member/base cleanup exclusions.

Recommended support changes:

- Update [UID:00009M] and [UID:0000M2] field notes to use `m_numericGlyphs` / loaded numeric glyph buffer rather than opaque "font handle".
- Update [UID:00011L], [UID:00011O], and [UID:00011M] support wording for `+0x114` and remove stale old-code-bar wording where it specifically affects UID00011N.
- Update [UID:000124] support wording to say the ordinary destructor body is emitted by UID00011N and the scalar wrapper should not duplicate handwritten destructor code.

No manual coverage/tracker edits, no manual generated edits, and no lifecycle/report execution commands are recommended for B001. Scoped validators refreshed validator-owned generated artifacts as expected.

## Recommended Target Doc Changes

Target path: `by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md`

Exact facts to incorporate:

- Current MCP session/status and exact range/padding.
- Helper resolution: `0x00516030` -> `GetMemoryMan`; `0x00516170` -> `MemoryMan::FreeBufferMemory`; `0x00582b70` -> wide string member cleanup; `0x00544580` -> Pane base teardown.
- Field wording: `+0x114` is `m_numericGlyphs`, a MemoryMan-allocated `9X11FONT.BIN` glyph buffer.
- Source policy: formal destructor body frees only `m_numericGlyphs`; vtable stores, `m_text` destruction, base teardown, SEH/security-cookie, and scalar-delete wrapper behavior are compiler/member/base generated.
- Relationship to [UID:000124] and [UID:000121] with xref facts.

Metadata/C++ changes:

- `COMPLETION:90`
- `CONFIDENCE:92`
- owner/emitter/reconstructable unchanged
- formal C++ insertion exactly as in `First-Draft C++ Recommendation`

## Recommended Support Doc Changes

Support path: `by-class/NumericStringControlPane.md`

- Update observed state to source-facing names: `m_text`, `m_alignment`, `m_colorVariant`, `m_numericGlyphs`.
- Update destructor row: source-authored destructor frees `m_numericGlyphs`; `m_text` and Pane cleanup are implicit member/base destruction.
- Mention current B001 MCP recheck and score movement on UID00011N; no class score change required from this target alone.

Support path: `by-file/NumericStringControlPane.md`

- Update file role/proposed contents to say `+0x114` is a loaded numeric glyph buffer from `9X11FONT.BIN`, not a font handle.
- Note that UID00011N is source-ready and should emit the ordinary destructor body in `NumericStringControlPane.cpp`.
- Keep file score `86/88`; constructor/render/final file grouping remain broader source-family blockers.

Support path: `by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md`

- Update field table row `+0x114` to `m_numericGlyphs`, loaded by `LoadDatFileBuffer`.
- Avoid old "95/95 reconstruction-code bar" wording where it could imply UID00011N is still blocked.

Support path: `by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md`

- Update behavior wording to say render consumes `m_numericGlyphs` and `m_colorVariant`.
- Keep render C++ blank; render helper/type names remain a separate blocker.

Support path: `by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md`

- Update cluster status to say UID00011N now has a source-ready ordinary destructor body while constructor/render/core aggregate remain blank.
- Preserve exact padding and child inventory.

Support path: `by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md`

- Add current relationship note: source cleanup is emitted by UID00011N; this page documents the compiler scalar deleting wrapper route and delete-flag behavior.
- Do not insert the full destructor body here. If the supervisor wants to remove the generated empty marker for UID000124 in the same callback, use a formal no-duplicate comment rather than code:

```cpp
// Compiler-generated scalar deleting-destructor wrapper for NumericStringControlPane.
// Source cleanup is emitted by [UID:00011N] NumericStringControlPane::~NumericStringControlPane().
```

Support path: `by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md`

- No required edit; already documents compiler thunk status. Optional support sync can cite the current MCP xrefs if the scalar page is edited.

## Score And Metadata Recommendation

Pre-callback target score/metadata: `COMPLETION:86`, `CONFIDENCE:90`, owner/emitter [UID:00009M], reconstructable `TRUE`, blank C++.

Implemented target score/metadata: `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter unchanged, reconstructable unchanged, formal destructor C++ populated.

Reason for increase:

- Current MCP rechecked the exact function, disassembly, decompilation, xrefs, scalar route, and padding.
- The old helper-name blocker is resolved by accepted MemoryMan pages.
- The old "font handle" ambiguity is resolved to MemoryMan-allocated numeric glyph buffer.
- The source-body/no-code boundary is now explicit: free the buffer in source, omit compiler/member/base cleanup.

Reason not higher:

- Exact original field names are inferred, not symbol-recovered.
- The class declaration/header shape is not final.
- Constructor/render methods remain blank and require their own source-quality decisions.
- Final original source grouping of small UI controls remains medium-high rather than final.

Support scores:

- Keep [UID:00009M] at `86/90` and [UID:0000M2] at `86/88` unless the supervisor expands the callback to broader constructor/render/class-field implementation.
- Keep [UID:00011L], [UID:00011O], [UID:00011M], and [UID:000124] scores unchanged unless their prose/C++ policy updates are accepted as score-bearing support repairs.

## Open Questions With Attempted Resolution

Open question: exact original field name for `+0x114`.

- Evidence checked: constructor load, render use, destructor free, [UID:00016G] return type, MemoryMan free helper, analogous glyph-buffer reports.
- Resolution: use inferred `m_numericGlyphs` as first-draft source-facing name. It is role-accurate and source-quality enough for formal C++.
- Remaining impact: prevents final-audit 95+ confidence, but does not block first-draft source.

Open question: should source explicitly destroy `m_text` or call base teardown?

- Evidence checked: target body order, StringBase docs, PaneCore docs, analogous destructor reports.
- Resolution: no. Those are compiler/member/base operations and must not be handwritten.
- Remaining impact: none for UID00011N.

Open question: should the scalar deleting destructor receive the same C++ body?

- Evidence checked: scalar decompile/disasm, xrefs, adjustor thunk route, vtable data.
- Resolution: no. The ordinary destructor body belongs to UID00011N; scalar wrapper docs should preserve compiler wrapper/no-duplicate policy.
- Remaining impact: UID000124 may still need a support cleanup/comment if the supervisor wants to eliminate its empty marker, but that is not a blocker to UID00011N source readiness.

Open question: should ownership move to MiniMap because only minimap constructor callers are known?

- Evidence checked: class/vtable/field docs, constructor callers, render behavior, source file context.
- Resolution: no. MiniMap is a consumer; NumericStringControlPane is a reusable UI control.
- Remaining impact: none.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. The source by-* metadata/prose and scoped validators should drive generated tracker/coverage updates. B001 should not manually edit auto-generated tracker/coverage files or manual `-coverage-report.md` files.

## Follow-Up Actions

Implementation callback is complete.

- Supervisor should perform Gate 2 claim-by-claim verification against this report, the changed by-* docs, validator output, and generated refresh observations.
- If Gate 2 passes, supervisor owns any `execute_report` lifecycle action.
- B001 stopped at `READY_FOR_SUPERVISOR_EXECUTE` and did not run report execution, dry-run/probing execution, archive moves, registry lifecycle commands, or manual report moves.

## Confidence

Recommendation confidence: high.

Score confidence: high for `90/92` target score.

Remaining uncertainty: exact original field names and final class/header shape. These are documented inference limits and do not block first-draft destructor source.

## Validator Results

Working directory for all commands: `E:\NTK\GhidraBridge\source-3\project-documentation`.

All validators exited `0` with `ok: 1` and `generated_refresh: completed`.

| File | Command ID | Timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- |
| `by-memory\0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md` | `000000008056` | `2026-07-09T02:40:53-04:00` | `0` | `1` | Updated UID00011N completion/confidence to `90/92`, registry hash, and generated C++; validator normalized UID links. |
| `by-class\NumericStringControlPane.md` | `000000008057` | `2026-07-09T02:41:11-04:00` | `0` | `1` | Pre-existing `missing_ref_uid 0003IR` reported three times; no target-specific failure. |
| `by-file\NumericStringControlPane.md` | `000000008058` | `2026-07-09T02:41:25-04:00` | `0` | `1` | Pre-existing `missing_ref_uid 0003IR`/`0003XD` references reported six times; no target-specific failure. |
| `by-memory\0x00499910-0x004999c1.NumericStringControlPaneConstructor.md` | `000000008059` | `2026-07-09T02:41:40-04:00` | `0` | `1` | Validator normalized UID link labels for UID00016G and UID00011N. |
| `by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` | `000000008060` | `2026-07-09T02:41:56-04:00` | `0` | `1` | No target-specific warnings. |
| `by-memory\0x00499910-0x00499be7.NumericStringControlPaneCore.md` | `000000008061` | `2026-07-09T02:42:10-04:00` | `0` | `1` | Validator inserted a UID00011N link label. |
| `by-memory\0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md` | `000000008062` | `2026-07-09T02:42:27-04:00` | `0` | `1` | Validator inserted/normalized UID00011N link labels. |

Shared validator warnings/side effects: project-wide `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` rows remain unrelated background warnings. Scoped validators rebuilt validator-owned generated metadata/reports, updated projected stats, rebuilt `validator.ini`, and created validator autogen backups as normal validator-owned side effects.

Generated refresh observation: `auto-generated/NexusTK/ui/controls/NumericStringControlPane.cpp` header now shows `validator-command-id: 000000008062`, `validator-refreshed-at: 2026-07-09T02:42:27-04:00`, `validator-refresh-source: foreground-generated-refresh`. UID00011N now appears as `Completion:90 | Confidence:92` followed by:

```cpp
NumericStringControlPane::~NumericStringControlPane()
{
    if (m_numericGlyphs != NULL) {
        m_numericGlyphs = static_cast<char *>(GetMemoryMan()->FreeBufferMemory(m_numericGlyphs));
    }
}
```

UID00011N no longer remains only an empty emitter marker. Other NumericStringControlPane entries that were not accepted for C++ in this callback remain empty emitter markers.

## Changed Files

Manual B001 edits:

- `tools/leaser/Agents/Agent-B001/research/00011N-NumericStringControlPaneDestructor-source-quality.md`
- `by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md`
- `by-class/NumericStringControlPane.md`
- `by-file/NumericStringControlPane.md`
- `by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md`
- `by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md`
- `by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md`
- `by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md`

Not edited: `by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md`; existing compiler-thunk/no-source disposition already satisfied the callback.

Validator-owned generated/state side effects observed, not manually edited by B001: generated C++/coverage/tracker/report metadata refresh, projected stats update, `validator.ini` registry rebuild, and `tools/validator_autogen_backup/*` backup creation reported by scoped validators.

Leases used and released: B001 leased the seven edited by-* docs for the immediate edit/validator batch at `2026-07-09T06:38:31Z`; all seven were released successfully after validation. `tools/leaser/Agents/current_leases.md` reports no active leases.

Report execution: not run. B001 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle/archive commands, manual report moves, archive moves, or equivalent lifecycle commands.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Supervisor validation required before implementation. Gate 1 passed before callback per `goal.md` entry `2026-07-09T02:41:00-04:00 - B001 UID00011N Gate 1 Audit`.
- [x] Target doc updated: `by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md`.
- [x] In target, set `COMPLETION:90`, `CONFIDENCE:92`; kept `CANONICAL_OWNER:00009M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009M`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- [x] In target, inserted exact formal destructor C++ from `First-Draft C++ Recommendation`; inline one-line C++ header remained blank.
- [x] In target, updated evidence/prose with current MCP session `supervisor_nexustk_20260709`, exact range/padding, helper identities, field role `m_numericGlyphs`, scalar-wrapper relation, no-direct-xref caveat, and compiler/member/base cleanup exclusions.
- [x] Updated `by-class/NumericStringControlPane.md` field notes and destructor method row to use `m_text`, `m_alignment`, `m_colorVariant`, and `m_numericGlyphs`; class score unchanged at `86/90`.
- [x] Updated `by-file/NumericStringControlPane.md` to record UID00011N source-ready destructor and `m_numericGlyphs` loaded glyph-buffer wording; file score unchanged at `86/88`.
- [x] Updated `by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md` row for `+0x114` and historicalized stale code-bar wording for UID00011N.
- [x] Updated `by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` wording for `m_numericGlyphs` and `m_colorVariant`; render C++ remains blank.
- [x] Updated `by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md` to note UID00011N is source-ready while constructor/render/core aggregate remain separate/blank.
- [x] Updated `by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md` with scalar-wrapper/no-duplicate relationship; optional formal no-duplicate comment was intentionally not inserted because the support page should remain blank and avoid duplicate source output.
- [x] Confirmed `by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md` needed no edit; existing compiler-thunk/no-source disposition was already sufficient.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Score-limiting blockers researched to resolution: helper identities, field role, source-body shape, scalar relation, direct xrefs, and range/padding.
- [x] Owner/emitter/reconstructable changes to apply: none beyond target score and C++ population; route remains [UID:00009M] -> [UID:0000M2].
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement/range/padding/reclassification changes to apply: no split; padding facts preserved.
- [x] First-draft C++ applied: exact destructor body using `m_numericGlyphs`.
- [x] Third-party import directive: not applicable.
- [x] Historical/stale assumptions corrected: old `95/95` code bar is historical/stale for UID00011N; "font handle" is superseded by loaded numeric glyph buffer pointer.
- [x] Open questions documented: exact original field names remain inferred and cap final-audit confidence only.
- [x] Validators run after callback for every edited by-* file from `source-3/project-documentation`, with `--wait-generated` used for generated freshness.
- [x] Generated refresh verified: `auto-generated/NexusTK/ui/controls/NumericStringControlPane.cpp` shows UID00011N with `Completion:90 | Confidence:92` and the formal destructor body instead of `Empty Emitter Marker`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000008065","destination_path":"executed-b-agent-research/B001/00011N-NumericStringControlPaneDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00011N-NumericStringControlPaneDestructor-source-quality.md","timestamp":"2026-07-09T11:50:21-04:00","uid":"00011N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
