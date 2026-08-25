** TARGET-REPORT-UID:0000WP **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0000WP FittingRoomDownloadControlPane Raw Constructor Source-Quality Report

## Finalized Report / Current Recommendation

Current recommendation: promote UID0000WP from blank-C++ raw constructor evidence to a source-ready `FittingRoomDownloadControlPane` constructor body, while preserving the no-function/no-start-xref caveat as a confidence cap.

Final disposition: keep canonical owner [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md), keep source emission through [UID:000052] into [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and insert formal constructor C++ for the target's own range.

Implementation callback result: target/support docs now carry the accepted `COMPLETION:88`, `CONFIDENCE:90`, unchanged `RECONSTRUCTABLE:TRUE`, unchanged `EMITTER_UIDS:000052`, blank optional position, and the exact formal constructor block from `## First-Draft C++ Recommendation`.

Confidence: high for the byte-level constructor behavior and class/source placement; capped below final audit because MCP session `2ec9c08f` still reports no IDA function object, no start/interior xrefs to the raw body, and no absolute pointer/immediate route to `0x0041b9e0`.

## Supporting Research

Original research history: this began as a report-only research pass for UID0000WP. Post-Gate-1 implementation callback work has now been applied to the scoped target/support by-* docs, with generated output refreshed by validators only. B007 did not edit generated files, coverage reports, validator state, report lifecycle state, archives, or supervisor ledgers by hand.

Current live MCP evidence was gathered read-only through endpoint `http://127.0.0.1:13337/mcp` against supervisor-provided active session `2ec9c08f`. Read-only `idb_list` on this repair pass showed session `2ec9c08f` active for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker_pid `12188`; supervisor clarified this is the pool-restored session for this workflow. `server_health` for `2ec9c08f` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.

Historical role-boundary note: a prior revision of this report incorrectly described B007 using MCP `idb_open` as the current evidence path. That wording was a role-boundary defect and is not part of the accepted final provenance. B agents must not open, adopt, start, stop, restart, kill, or otherwise manage MCP/IDA/Python session state. This repaired report relies on the supervisor-provided existing session `2ec9c08f` and read-only schema-current calls only.

Current target/support docs reviewed:

- Target [UID:0000WP] `by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md`.
- Sibling destructor [UID:0000WQ] `by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md`.
- Parent class [UID:000052] `by-class/FittingRoomDownloadControlPane.md`.
- Source file [UID:0000JE] `by-file/FittingRoom.md`.
- Dialog constructor [UID:0002CP] `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`.
- Deleting wrapper [UID:0002EI] `by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md`.
- Aggregate/context [UID:0000WR] `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`.

Generated/read-only context reviewed:

- Historical pre-callback `auto-generated/-ag-research-tracker.md` row for UID0000WP: `85/89`, combined `87.0`, reconstructable `true`, report count `0`.
- Historical pre-callback `auto-generated/-ag-memory-coverage.md` row for UID0000WP: emitted through owner/emitter `000052`, generated output `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, but `no` generated output body.
- Current post-callback generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp` header: validator command `000000005552`, refreshed `2026-07-03T15:18:23-04:00`; UID0000WP now appears as formal constructor output at lines around `706-711`, not as an empty emitter marker.
- The same generated file already has dialog constructor source that calls `new FittingRoomDownloadControlPane(7, &bounds); downloadPane->SetProgressPercent(0);`, which is source-facing lead material, not direct binary proof for the target signature.

Executed report leads reviewed:

- B004 `0000JE-FittingRoom-empty-emitter-family-source-quality.md` explicitly left UID0000WP and UID0000WQ blank because the raw constructor/destructor had no start route at that time. Its useful conclusion remains valid as historical evidence, but current B007 reanalysis adds the matching inline constructor sequence in UID0002CP as positive source-shape evidence.
- B003 `0002CP-0002CQ-0002CS-0002CU-0002CV-0002CX-FittingRoomDialogCore-source-quality.md` uses a source-level `FittingRoomDownloadControlPane` allocation in dialog constructor code. B007 treats that as a source-shape lead and rechecks it against MCP session `2ec9c08f`.

## Target

- Target UID: `0000WP`.
- Target path: `by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md`.
- Range: `0x0041b9e0-0x0041ba20`, 64 bytes.
- Historical source queue/report row at assignment time: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, score `85/89`, combined `87.0`, reports `0`.
- Current artifact state: implementation callback applied; report execution/lifecycle state remains supervisor-owned and external to this report text.
- Current owner/emitter state: canonical owner `000052`, reconstructable `TRUE`, emitter `000052`, formal constructor C++ populated.

## Current Target State

Current implemented metadata:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `000052` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `000052` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | formal constructor block populated; inline header remains empty marker syntax |

Remaining confidence caps:

- MCP still confirms no IDA function object at `0x0041b9e0`, `0x0041b9f2`, or `0x0041ba14`.
- MCP still confirms no xrefs to `0x0041b9e0`, `0x0041b9f2`, `0x0041ba14`, or sibling `0x0041ba20`.
- Pointer/immediate search for the raw start bytes `e0 b9 41 00` returned zero matches, so no absolute pointer route was recovered.

Current reanalysis result: the no-start-route blocker still caps confidence but no longer justifies blank C++. The exact constructor body is present as both an unreferenced raw body and an inline constructor sequence inside the live `FittingRoomDialog` constructor at `0x0041c17c-0x0041c19b`, proving the source-level constructor semantics strongly enough for first-draft formal C++.

## Executive Recommendation

Best direct owner: [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md).

Recommended metadata: raise target to `COMPLETION:88`, `CONFIDENCE:90`. Keep `CANONICAL_OWNER:000052`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000052`, and blank `EMITTER_POSITION_OPTIONAL`.

Recommended C++ disposition: insert the formal constructor body in this report. The code uses a source-level base-constructor call and a descriptive `m_progressPercent` field name for `this+0x108`. The secondary vtable writes at `+0xa0/+0xa4` are compiler multiple-inheritance artifacts and should not appear as source assignments.

Remaining condition before higher confidence: recover an ordinary call, vtable, pointer, or function-object route to the raw `0x0041b9e0` body, or correct IDA/function-boundary modeling in a way that proves this raw out-of-line constructor is callable rather than an unreferenced emitted copy.

## Supervisor Active Recheck

Historical assignment context: supervisor assigned UID0000WP as a new Medium report-only research target and required MCP-backed evidence. The target did not require split repair before this report: the existing half-open range is exact, predecessor padding is two `0xcc` bytes at `0x0041b9de-0x0041b9e0`, the target body ends at `retn 4` at `0x0041ba1d`, and the next modeled function starts at `0x0041ba20`.

Every source-bearing question in scope was checked:

- Raw body bytes and disassembly were refreshed with MCP.
- Start/interior xrefs and immediate/pointer routes were checked and remain absent.
- Dialog constructor inline construction was checked and matches the target body.
- Vtable family refs were checked and tie raw constructor, raw destructor, dialog constructor inline body, and deleting wrapper together.

## Inference Research Guidance Check

The workflow and `by-structure.md` require C++ only when owner/emitter, score, boundaries, source placement, and names are strong enough. UID0000WP already meets the combined-score/emitter gate, and B007 rechecked the remaining source-quality blocker rather than copying old blank-C++ language forward.

Direct IDA facts:

- Bytes, instructions, function-object absence, xrefs, vtable refs, sibling/destructor/dialog/deleting-wrapper ranges, and decompiler output from MCP session `2ec9c08f`.

Documentation evidence:

- Current by-* docs already assign the target to UID000052/UID0000JE and identify the progress word and vtable family.
- Existing generated dialog constructor source already models a `FittingRoomDownloadControlPane` object and progress reset.

Inference:

- The raw body is the out-of-line constructor shape for the same source-level constructor that UID0002CP currently inlines at `0x0041c17c-0x0041c19b`.
- The source-facing constructor should be expressed as a normal C++ constructor, not as raw vtable writes or a helper named after `sub_41B9E0`.

Wave2/Wave3 generated-source material was treated only as historical lead material. Current IDA MCP and current by-* docs drive the recommendation.

## Heuristic / Inference Reanalysis And Validation

Issue: no IDA function object at the raw constructor start.

- Evidence: `lookup_funcs` on `0x0041b9e0`, `0x0041b9f2`, and `0x0041ba14` returned `Not a function`.
- Validation: `disasm 0x0041b9e0` still decodes a complete constructor-shaped body through `retn 4`.
- Decision: keep a confidence cap and preserve the raw-body caveat; do not block source C++ because the same constructor operations appear inline in a modeled caller.

Issue: no start/interior xrefs.

- Evidence: `xrefs_to` returned zero xrefs for `0x0041b9e0`, `0x0041b9f2`, `0x0041ba14`, and `0x0041ba20`.
- Additional negative check: `find_bytes e0 b9 41 00` and `find_bytes 20 ba 41 00` returned zero matches.
- Decision: no route to raw helper body; report must not claim ordinary call reachability.

Issue: source constructor parameter/order.

- Evidence: raw body pushes `[ebp+8]` and immediate `8` before `call sub_4949E0`; the inline dialog sequence calls `sub_4949E0(v20, 8, v23)` at `0x0041c17c`.
- Decision: formal source body should use one explicit constructor parameter, `const RectBounds *bounds`, and a base `ControlPane(8, bounds)` call. Existing generated `new FittingRoomDownloadControlPane(7, &bounds)` should be treated as stale/provisional for this target because MCP shows no constructor parameter for child id `7`.

Issue: progress field naming/type.

- Evidence: target writes `word ptr [esi+108h], 0`; inline dialog constructor writes `*(_WORD *)(v20 + 264) = 0`; OnPaint/progress support uses the same `+0x108` state as the progress byte/word consumed by the progress drawing path.
- Decision: use descriptive `m_progressPercent` in the first-draft C++ and document that exact original spelling and byte-vs-word declaration are still inferred. Do not use decompiler names or raw `field_108`.

Issue: vtable writes.

- Evidence: target writes vtables at `this+0x00`, `this+0xa0`, and `this+0xa4`; inline dialog constructor writes the same three vtables; raw destructor and deleting wrapper restore the same addresses.
- Decision: vtable writes prove class identity but should not appear in source C++.

Rejected alternatives:

- `sub_41B9E0` raw helper source: rejected because source should be a constructor, not a hand-called helper.
- No-code/blank C++ retained: rejected because current MCP proves a complete constructor body and the same construction sequence inside UID0002CP.
- Direct file owner [UID:0000JE] only: rejected because the body is class lifecycle code; file route remains through the class emitter.
- No-owner/non-emitting: rejected because owner/emitter and class/source route are already above gate and freshly corroborated.
- `FittingRoomDialog` ownership: rejected because UID0002CP is a consumer/inline construction site, not the semantic owner of the constructed class.
- Generic `ControlPane` ownership: rejected because the target writes `FittingRoomDownloadControlPane` vtables and initializes the download-progress member after the shared base setup.

## Evidence Standards Used

Evidence types used:

- MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, `xref_query`, `find_bytes`, and `func_profile`, all read-only against supervisor-provided session `2ec9c08f`.
- Current by-* docs for target, class, file, sibling destructor, dialog constructor, deleting wrapper, and aggregate.
- Validator-generated `FittingRoom.cpp`, memory coverage, and research tracker as read-only generated context.
- Executed B reports only as leads.

The evidence is strong enough for first-draft C++ because the target bytes and inline dialog-constructor sequence agree instruction-for-instruction on the source semantics: base ControlPane setup with type `8`, three class vtable views, and progress field clear. The evidence is not strong enough for `95/95` or exact original field spelling because the raw body still has no modeled function and no inbound route.

## Evidence Checked

IDA MCP checks performed:

- `idb_list`: supervisor-provided active session `2ec9c08f` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker_pid `12188`; no B007 session-management command was used for this repaired evidence pass.
- `server_health`: OK, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
- `lookup_funcs`: `0x0041b9b0` is `sub_41B9B0` size `0x2e`; `0x0041b9de`, `0x0041b9e0`, `0x0041b9f2`, and `0x0041ba14` are not functions; `0x0041ba20` is `sub_41BA20` size `0x1f`; `0x0041ba40` is `sub_41BA40` size `0x38e`; `0x0041bdd0` is `sub_41BDD0` size `0x480`; `0x0041d580` is `sub_41D580` size `0x55`; `0x004949e0` is `sub_4949E0` size `0xa1`.
- `get_bytes`: predecessor padding `0x0041b9de-0x0041b9e0` is `cc cc`; target bytes match the existing exact 64-byte sequence; sibling destructor bytes match the existing `0x1f` sequence.
- `disasm 0x0041b9e0`: no function, but complete constructor-shaped instruction stream through `retn 4`.
- `xrefs_to`: zero xrefs to `0x0041b9e0`, `0x0041b9f2`, `0x0041ba14`, and `0x0041ba20`.
- `xrefs_to` vtables: each of `0x0060d9c4`, `0x0060da2c`, and `0x0060da5c` has exactly four refs: raw constructor, raw destructor, dialog constructor, deleting wrapper.
- `find_bytes`: no matches for raw start pointer `e0 b9 41 00` or destructor start pointer `20 ba 41 00`; vtable immediate matches occur at raw constructor, raw destructor, dialog constructor, and deleting wrapper.
- `decompile 0x0041bdd0`: inline construction sequence at `0x0041c17c-0x0041c19b` calls `sub_4949E0(v20, 8, v23)`, writes all three download-control vtables, and clears `*(WORD *)(v20+264)`.
- `decompile 0x004949e0`: shared ControlPane setup sets type byte `this+254` from argument `a2`, writes base ControlPane vtables, applies bounds when `a3` is non-null, and initializes inherited state.
- `decompile 0x0041ba20` and `0x0041d580`: sibling/wrapper restore the same three vtables and call shared teardown `0x00544580`.
- `func_profile`: `0x0041ba20` has zero callers, one callee; `0x0041ba40` has zero ordinary callers but vtable role is documented elsewhere; `0x0041d580` has zero ordinary callers, compiler wrapper callees and constants including `0x10c` allocation size evidence.

Docs and generated context checked:

- Target, class, file, raw destructor, deleting wrapper, aggregate, dialog constructor docs.
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.
- `auto-generated/-ag-research-tracker.md`.
- `auto-generated/-ag-memory-coverage.md`.
- B004 FittingRoom empty-emitter family report and B003 FittingRoom dialog core report as leads.

Skipped checks:

- During original research, no validator commands were run because the assignment was report-only. Post-callback scoped validator results are recorded under `## Validator Results`.
- No IDA DB edits, `define_func`, rename, type, lifecycle, archive, or process-management commands were run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000WP-01 | UID0000WP remains exact raw range `0x0041b9e0-0x0041ba20`, with predecessor padding `0xcc 0xcc` and successor `sub_41BA20` at `0x0041ba20`. | High | MCP `lookup_funcs`, `get_bytes`, `disasm` session `2ec9c08f`. | Target Evidence/Covered Range; by-file FittingRoom raw-body note. | Incorporated refreshed session facts and preserved exact bytes/boundaries in target and file route. | applied |
| C-0000WP-02 | Raw start and sampled interiors still have no IDA function object or xrefs. | High | `lookup_funcs` and `xrefs_to` for `0x0041b9e0`, `0x0041b9f2`, `0x0041ba14`; `find_bytes e0 b9 41 00` zero matches. | Target Status/Evidence; score rationale. | Preserved as confidence cap, not as blank-C++ blocker, in target/class/file docs. | applied |
| C-0000WP-03 | The raw body performs `ControlPane` setup with type `8`, installs three download-control vtables, clears `this+0x108`, and returns `this`. | High | MCP bytes/disasm at `0x0041b9e0`; call to `sub_4949E0`; vtable refs. | Target Behavior/Evidence; formal C++ block. | Added source-ready constructor summary and formal C++ block in target; generated output now contains constructor body. | applied |
| C-0000WP-04 | Dialog constructor contains an inline sequence matching the raw constructor at `0x0041c17c-0x0041c19b`. | High | MCP `decompile 0x0041bdd0`; vtable refs at `0x0041c181`, `0x0041c187`, `0x0041c191`; progress clear at `0x0041c19b`. | Target Evidence; by-memory UID0002CP support note; by-file generated-output note. | Incorporated in target, class, file route, and UID0002CP caveat. | applied |
| C-0000WP-05 | Vtable family refs tie raw constructor, raw destructor, dialog constructor, and deleting wrapper together. | High | `xrefs_to 0x0060d9c4/0x0060da2c/0x0060da5c`; `find_bytes` vtable immediate matches. | Target Evidence; class page lifecycle row. | Preserved exact refs and owner proof in target/class/file docs; UID0000WQ page already had B008 vtable-family detail. | applied |
| C-0000WP-06 | Formal source body should be a constructor, not `sub_41B9E0` or manual vtable writes. | Medium-high | Source-shape inference from constructor bytes and inline UID0002CP route. | Target `RECONSTRUCTION_CPP CODE`; class/source placement docs. | Inserted formal constructor block with base call and progress field clear; class/file docs describe source-ready constructor route. | applied |
| C-0000WP-07 | Parameter/name confidence remains capped: explicit parameter is bounds; child id `7` in generated dialog source is not present in the raw constructor body. | Medium | Raw body has only `[ebp+8]`; inline sequence calls `sub_4949E0(v20, 8, v23)`; generated file has `FittingRoomDownloadControlPane(7, &bounds)` as source lead but not binary proof. | Target caveats; by-memory UID0002CP/generated-output support note. | Documented conservative signature and child-id caveat in target, by-file, and UID0002CP support note; exact formal UID0002CP body left unchanged as out-of-scope existing source sketch. | applied |
| C-0000WP-08 | Owner/emitter remain UID000052 under UID0000JE; FittingRoomDialog, ControlPane, generic helper, no-owner, and direct-file-only alternatives are rejected. | High | Current by-* ownership, vtable names, dialog consumer role, base setup call. | Target metadata; class/file support docs. | Metadata route kept; rejected alternatives preserved in target/class/file support text. | applied |

## Positive Evidence Summary

- The target bytes are a complete constructor-shaped body with prologue, base setup call, vtable installations, progress-field clear, and `retn 4`.
- The same body is repeated inline in `FittingRoomDialog` constructor: allocation of 268 bytes, `sub_4949E0(v20, 8, v23)`, vtable writes, progress clear, and `AddControl`.
- The three download-control vtable addresses are referenced only from the four expected lifecycle sites: raw constructor, raw destructor, dialog constructor inline path, and deleting wrapper.
- Existing owner/emitter route through UID000052/UID0000JE already clears the reconstruction gate and generated output currently contains an empty marker for UID0000WP, making this a source-quality/C++ readiness issue rather than an ownership discovery issue.

## IDA MCP Facts

Function/range facts:

- `0x0041b9b0`: `sub_41B9B0`, size `0x2e`; ends at `0x0041b9de`.
- `0x0041b9de`: not a function; two bytes before target are `cc cc`.
- `0x0041b9e0`, `0x0041b9f2`, `0x0041ba14`: not functions.
- `0x0041ba20`: `sub_41BA20`, size `0x1f`.
- `0x0041ba40`: `sub_41BA40`, size `0x38e`.
- `0x0041bdd0`: `sub_41BDD0`, size `0x480`.
- `0x0041d580`: `sub_41D580`, size `0x55`.
- `0x004949e0`: `sub_4949E0`, size `0xa1`.

Byte facts:

- Target bytes: `55 8b ec 51 56 ff 75 08 8b f1 6a 08 89 75 fc e8 ec 8f 07 00 c7 06 c4 d9 60 00 8b c6 c7 86 a0 00 00 00 2c da 60 00 c7 86 a4 00 00 00 5c da 60 00 66 c7 86 08 01 00 00 00 00 5e 8b e5 5d c2 04 00`.
- Raw destructor bytes at successor: `c7 01 c4 d9 60 00 c7 81 a0 00 00 00 2c da 60 00 c7 81 a4 00 00 00 5c da 60 00 e9 41 8b 12 00`.

Xref facts:

- `xrefs_to 0x0041b9e0`, `0x0041b9f2`, `0x0041ba14`, `0x0041ba20`: zero.
- `xrefs_to 0x0060d9c4`: `0x0041b9f4`, `0x0041ba20`, `0x0041c181`, `0x0041d586`.
- `xrefs_to 0x0060da2c`: `0x0041b9fc`, `0x0041ba26`, `0x0041c187`, `0x0041d58c`.
- `xrefs_to 0x0060da5c`: `0x0041ba06`, `0x0041ba30`, `0x0041c191`, `0x0041d596`.
- `find_bytes` for vtable immediates produced the same four sites for each vtable address.

Negative IDA facts:

- No pointer/immediate match for the raw constructor start `0x0041b9e0`.
- No pointer/immediate match for the raw destructor start `0x0041ba20`.
- No ordinary caller to the raw destructor or deleting wrapper in `func_profile`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041b9e0-0x0041ba20` | UID0000WP target | Raw/out-of-line constructor body | TRUE | UID000052 | `88/90` implemented | Source-ready constructor C++ with route caveat |
| `0x0041ba20-0x0041ba3f` | UID0000WQ | Raw non-deleting destructor | TRUE | UID000052 | `86/91` | Already resolved by B008 as blank destructor no-code body |
| `0x0041ba40-0x0041bdce` | UID0000WR / child notes | Download control OnPaint in aggregate context | TRUE | UID0000JE/UID000052 child context | `88/89` aggregate | Blank-C++ aggregate; child naming is stale in some support text |
| `0x0041bdd0-0x0041c250` | UID0002CP | FittingRoomDialog constructor | TRUE | UID000050 | `86/91` | Contains inline download-control construction |
| `0x0041d580-0x0041d5d5` | UID0002EI | Compiler scalar deleting destructor wrapper | FALSE | NONE | `88/92` | Compiler-generated, no source body |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041b9ef` | call from target to `sub_4949E0` | Shared ControlPane setup/base constructor with type `8` and bounds argument |
| `0x0041b9f4` | raw constructor writes `0x0060d9c4` | Primary FittingRoomDownloadControlPane vtable proof |
| `0x0041b9fc` | raw constructor writes `0x0060da2c` | Secondary vtable proof |
| `0x0041ba06` | raw constructor writes `0x0060da5c` | Tertiary vtable proof |
| `0x0041ba10` | raw constructor clears `word ptr [this+0x108]` | Progress/state field initialization |
| `0x0041c17c` | dialog constructor calls `sub_4949E0(v20, 8, v23)` | Inline constructor sequence in actual caller |
| `0x0041c181/87/91` | dialog constructor writes same three vtables | Proves source-level construction without raw call |
| `0x0041c19b` | dialog constructor clears `v20+0x108` | Same progress/state field initialization |
| `0x0041d586/8c/96` | deleting wrapper writes same vtables | Destructor/layout corroboration |

## Documentation Evidence And IDA Status

Existing docs supporting the conclusion:

- Target and class pages already assign UID0000WP to UID000052 and source route UID0000JE.
- Raw destructor and deleting wrapper pages document matching vtable restoration and shared teardown.
- FittingRoom file page lists the raw constructor/destructor as `FittingRoomDownloadControlPane` lifecycle evidence.
- Generated FittingRoom.cpp already contains a source-level download-pane allocation in UID0002CP output.

Docs that are stale or incomplete:

- Historical pre-callback target text said C++ must remain blank until function-start reachability is recovered; implementation now replaces that policy with source-ready constructor evidence while preserving reachability as a confidence cap.
- Historical pre-callback `by-file/FittingRoom.md` said to treat the raw constructor as raw layout/code evidence until function-boundary correction; implementation now says UID0000WP is source-ready constructor evidence, not an ordinary callable helper route.
- `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md` and generated output still present `FittingRoomDownloadControlPane(7, &bounds)` as an existing source sketch, but implementation added a support caveat that child id `7` is a dialog/control-manager role, not proven as a UID0000WP constructor parameter.
- `by-class/FittingRoomDownloadControlPane.md` has a stale/misleading child row label for UID00041P path/title; left unchanged as excluded-with-reason because correcting that sibling row would broaden beyond UID0000WP support sync.

Generated/coverage report state:

- UID0000WP is now generated as formal constructor source in `auto-generated/NexusTK/cashshop/FittingRoom.cpp` under validator command `000000005552`, refreshed `2026-07-03T15:18:23-04:00`.
- The target is no longer an empty emitter marker in the generated file.

## Ranked Ownership Analysis

### 1. UID000052 FittingRoomDownloadControlPane

Evidence for:

- Target writes three `FittingRoomDownloadControlPane` vtable views.
- Raw destructor and deleting wrapper restore the same vtables.
- Dialog constructor inline body constructs the same object and passes it to the dialog control collection.
- Class page owns the progress field and OnPaint/progress behavior.

Evidence against:

- Raw body has no function object or direct start xrefs.
- Exact original constructor signature/field spelling remains inferred.

Decision: best owner; keep canonical owner and emitter.

### 2. UID0000JE FittingRoom direct file owner

Evidence for:

- FittingRoom source file owns the feature module and generated output path.
- Dialog constructor uses the download pane locally.

Evidence against:

- Constructor is class lifecycle code, not a free helper or file-global function.

Decision: use as source file route through class emitter, not direct canonical owner.

### 3. UID000050 FittingRoomDialog

Evidence for:

- Inline construction sequence is inside `FittingRoomDialog::FittingRoomDialog`.

Evidence against:

- The dialog is a consumer/allocator. Vtables and field at `+0x108` belong to `FittingRoomDownloadControlPane`.

Decision: reject as owner; update support only to explain the inline construction/caller role.

### 4. ControlPane / generic UI base owner

Evidence for:

- Target calls `sub_4949E0`, the ControlPane setup/base constructor.

Evidence against:

- Target overwrites base vtables with download-control vtables and initializes a subclass progress field.

Decision: reject; ControlPane is a dependency/base.

### 5. No-owner/non-emitting or raw helper

Evidence for:

- No raw start route remains.

Evidence against:

- Owner/emitter is already above gate, and inline constructor sequence proves source semantics.

Decision: reject no-owner/non-emitting and reject raw `sub_41B9E0` helper naming.

## Source Placement

Recommended source placement: class constructor under [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md), emitted through [UID:0000JE][FittingRoom](by-file/FittingRoom.md) into `NexusTK/cashshop/FittingRoom.cpp`.

Why this placement fits:

- The class belongs to the fitting-room/cashshop module.
- The dialog constructor allocates the pane as a child control inside the fitting-room UI.
- The class's OnPaint/progress behavior and destructor wrapper are documented in the same source family.

Rejected placements:

- `FittingRoomDialog.cpp` direct ownership: caller-only.
- `ControlPane.cpp`: base helper-only.
- Generic UI/core helper: contradicted by class vtables and FittingRoom-local lifecycle.
- No-owner/non-emitting: contradicted by source-ready constructor evidence.

Remaining placement uncertainty: exact original declaration location (`FittingRoom.cpp` private class section versus header) remains inferred. The current project route through UID000052/UID0000JE is sufficient for generated source output.

## Range / Split / Padding / Reclassification Analysis

No split is recommended.

Exact boundary facts:

- Previous function `sub_41B9B0` starts at `0x0041b9b0`, size `0x2e`, ending `0x0041b9de`.
- `0x0041b9de-0x0041b9e0` is two `0xcc` bytes.
- Target body starts at `0x0041b9e0`, ends with `retn 4` at `0x0041ba1d`, half-open end `0x0041ba20`.
- Successor `sub_41BA20` starts exactly at `0x0041ba20`.
- The raw destructor is followed by alignment at `0x0041ba3f` and paint routine `sub_41BA40` at `0x0041ba40`.

Parent/container impact:

- No parent range changes are required.
- UID0000WR aggregate should continue to list the raw constructor/destructor as pre-core lifecycle pages.

## Negative Evidence Summary

- No IDA function object at the raw constructor or sampled interior addresses.
- No xrefs to raw constructor start, sampled interiors, or raw destructor start.
- No absolute pointer/immediate route to `0x0041b9e0` or `0x0041ba20`.
- No proof that child id `7` is a constructor parameter; raw body only receives the bounds pointer and hard-codes ControlPane type `8`.
- No evidence that manual vtable writes belong in source; they are compiler output from class construction.
- No evidence for FittingRoomDialog ownership; it only allocates and adds the control.

## IDA Rename / Type / Comment Recommendations

No IDA DB edit was requested or performed.

Source-facing names/types recommended for documentation:

- Constructor: `FittingRoomDownloadControlPane::FittingRoomDownloadControlPane`.
- Parameter: `const RectBounds *bounds` or equivalent pointer/reference spelling; confidence medium because the original exact spelling is unrecovered.
- Base call: `ControlPane(8, bounds)`; `8` is documented as the ControlPane setup type/id argument from MCP, not as child control id `7`.
- Field: `m_progressPercent`; confidence medium because the binary clears a word at `+0x108`, while OnPaint/progress rendering consumes progress state from the same offset.

Intentionally unchanged:

- No IDA rename to a function object at `0x0041b9e0` because IDA still does not model it as a function and the assignment forbids IDA DB process-management/edit work.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. UID0000WP is reconstructable, has a confirmed nonblank emitter route, exceeds the combined-score gate, has exact byte boundaries, and now has source-shape corroboration from the inline `FittingRoomDialog` construction path.

Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text for the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FittingRoomDownloadControlPane::FittingRoomDownloadControlPane(const RectBounds *bounds)
    : ControlPane(8, bounds),
      m_progressPercent(0)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves behavior:

- `ControlPane(8, bounds)` represents the `push [ebp+8]`, `push 8`, `call sub_4949E0` sequence.
- `m_progressPercent(0)` represents `word ptr [this+0x108] = 0`.
- Compiler-generated vtable writes are omitted from source because C++ construction will generate them.
- Return of `this` and `retn 4` are ABI/compiler output and should not be source.

Reason it matches plausible mid-2000s source:

- A normal class constructor with an initializer list is a plausible VC6/VC7-era class source representation.
- It avoids decompiler labels, raw address names, manual vtable stores, and fake helper calls.
- It keeps exact unknowns conservative: `bounds` and `m_progressPercent` are descriptive names, not claimed original symbol spellings.

Reason not higher confidence:

- Raw out-of-line constructor still has no modeled function object or inbound route.
- The exact original constructor signature might use `RectBounds *` rather than `const RectBounds *`.
- Exact progress field type/spelling remains inferred; target evidence proves the offset and clear, not the original member declaration.

## Final Recommendation

Exact implemented changes:

- Target UID0000WP: set `COMPLETION:88`, `CONFIDENCE:90`; kept `CANONICAL_OWNER:000052`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000052`, and blank optional position; inserted the formal constructor C++ block above.
- Preserve raw-body evidence, exact bytes, no-function/no-xref/no-pointer-route caveats, and vtable-family refs.
- Replace stale "blank final C++ until function-start reachability is recovered" policy with "source-ready constructor body; raw-start reachability remains confidence cap."

Parent assignment disposition:

- Keep parent/class [UID:000052] and file route [UID:0000JE].
- No no-owner/non-emitting disposition applies.

Future work outside this UID0000WP assignment:

- Separate callback/research should review UID0000WQ destructor source policy.
- Separate support cleanup should fix stale/misleading UID00041P OnPaint path/title text if still present.
- Higher confidence would require a recovered raw-body route or corrected IDA function modeling.

## Recommended Target Doc Changes

Target path: `by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md`.

Implemented target changes:

- `COMPLETION:88`.
- `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:000052`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:000052`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Replace blank formal C++ with the exact block from `## First-Draft C++ Recommendation`.
- Added MCP session `2ec9c08f` evidence: supervisor-provided session provenance, no-function results, exact bytes, predecessor padding, successor destructor, no start/interior xrefs, no pointer/immediate matches, vtable refs, and inline UID0002CP constructor sequence.
- Preserved rejected alternatives and caveats: not raw `sub_41B9E0`, not FittingRoomDialog-owned, not ControlPane-owned, not no-owner/non-emitting, not exact original field spelling, and no ordinary route to raw start.

## Recommended Support Doc Changes

Support path: `by-class/FittingRoomDownloadControlPane.md`.

- Applied: updated the UID0000WP strong-method row, lifecycle text, IDA snapshot, boundary cautions, score rationale, and changes so the constructor is source-ready through UID000052 with `88/90`, while raw-start no-function/no-xref remains a confidence cap.
- Already present/applied: sibling UID0000WQ is preserved as B008-accepted blank destructor no-code evidence.
- Excluded-with-reason: UID00041P row/path/title mismatch remains untouched because it is a sibling support cleanup and would broaden beyond this UID0000WP callback.

Support path: `by-file/FittingRoom.md`.

- Applied: updated the FittingRoomDownloadControlPane bullet, boundary cautions, generated-output/family notes, and change log so UID0000WP is no longer listed as a follow-up empty marker blocked solely by raw no-xref status.
- Applied: preserved the file route through `NexusTK/cashshop/FittingRoom.cpp`.
- Already present/applied: UID0000WQ remains a separate B008-accepted blank/raw destructor no-code item.

Support path: `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`.

- Applied: updated the download-pane construction note and reconstruction notes so MCP-proven UID0000WP constructor shape is bounds plus fixed ControlPane type `8`; child id `7` is documented as dialog/control-manager role, not proven target constructor parameter.
- Applied: preserved the dialog as caller/consumer, not target owner.

Support path: `by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md`.

- Excluded-with-reason/already-present: vtable-family evidence remains current in UID0000WQ from B008; no metadata or C++ change was required or made.

Generated files:

- Generated `FittingRoom.cpp` was not edited by hand. It refreshed through scoped validator command `000000005552` and now contains UID0000WP constructor output.

## Score And Metadata Recommendation

Historical pre-callback score/metadata: `85/89`, owner `000052`, reconstructable `TRUE`, emitter `000052`, blank C++.

Implemented score/metadata: `88/90`, owner/emitter unchanged, formal C++ populated.

Reason to raise completion:

- The previous score was capped by blank C++ and unresolved raw-start reachability. B007 resolved the source-body question by proving the raw body matches the inline dialog construction sequence and by providing formal C++.

Reason to raise confidence modestly:

- Fresh MCP confirms all prior byte/vtable/boundary facts and adds no contradictory evidence.
- Confidence remains capped at `90`, not higher, because no raw start route/function object was recovered and field/signature spellings remain inferred.

Score-improvement attempt:

- Function-object blocker: checked with `lookup_funcs`; unresolved, remains cap.
- Start/interior xref blocker: checked with `xrefs_to`; unresolved, remains cap.
- Pointer/immediate route blocker: checked with `find_bytes`; unresolved, remains cap.
- C++ readiness blocker: resolved by matching target body to dialog inline construction sequence and formalizing source body.
- Field/name blocker: resolved enough for descriptive `m_progressPercent`, but exact original spelling remains cap.

## Open Questions With Attempted Resolution

Question: Is the raw `0x0041b9e0` body callable?

- Evidence checked: `lookup_funcs`, `xrefs_to`, `xref_query`, `find_bytes`.
- Resolution: no current evidence proves callable route. Treat as unreferenced/out-of-line constructor copy or IDA-unmodeled raw body; keep confidence cap.

Question: Does the constructor take child id `7`?

- Evidence checked: raw constructor bytes and dialog decompile.
- Resolution: not proven. Raw body has one explicit stack parameter, the bounds pointer, and hard-codes ControlPane type `8`. Existing generated dialog source uses `7` as a source lead but should not be preserved as a proven constructor parameter for UID0000WP without separate support review.

Question: What is the exact field name/type at `+0x108`?

- Evidence checked: raw target write, inline dialog write, OnPaint/progress support docs.
- Resolution: source-facing role is download progress percent/state. Use descriptive `m_progressPercent`; exact original spelling and byte-vs-word declaration remain unresolved and cap confidence.

Question: Should UID0000WQ also receive destructor C++?

- Evidence checked: sibling docs, MCP decompile, no-xrefs.
- Resolution: out of scope. UID0000WQ remains separate and should not be changed by this report except optional support sync.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No manual coverage-report or supervisor-owned tracker edit is requested or performed. Validator-owned `auto-generated/-ag-*` files and generated C++ refreshed from source by-* metadata and scoped validators only.

## Follow-Up Actions

Supervisor actions:

- Use this report and the changed by-* docs for supervisor Gate 2 verification and execution lifecycle decisions.

B007 callback actions:

- Completed: leased only edited by-* files, applied target formal C++ and support sync, ran scoped validators for every changed by-* file, and updated this report's ledger/checklist states to applied/already-present/excluded-with-reason.

Future research actions:

- UID0000WQ destructor C++/no-code policy.
- FittingRoomDownloadControlPane field declaration audit for `m_progressPercent`.
- Cleanup of stale UID00041P OnPaint support label if not already handled by another report.

## Confidence

Recommendation confidence: 90.

Score confidence: 90.

Remaining uncertainty: no raw-body route, no IDA function object, exact constructor signature spelling, exact `+0x108` member spelling/type, and generated dialog `7` argument role.

## Validator Results

Scoped validator commands run from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md --apply --queue-timeout 240`
  - `command_id: 000000005549`
  - `command_timestamp: 2026-07-03T15:17:57-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none in scoped output.
  - Side effects: `completion_update 0000WP 88`, `confidence_update 0000WP 90`, autogen registry hash update to `80333f80abdc5e1d5decaa57ece05d6601bf005c325fa72087148a2cc48a915f`, autogen registry output state `blank -> block`, reference-index additions for `000050` and `0002CP`, stats row remove for by-memory reconstructable queue, projected stats update, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-class/FittingRoomDownloadControlPane.md --apply --queue-timeout 240`
  - `command_id: 000000005550`
  - `command_timestamp: 2026-07-03T15:18:03-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none in scoped output.
  - Side effects: stats incremental noop for UID000052, projected stats update, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240`
  - `command_id: 000000005551`
  - `command_timestamp: 2026-07-03T15:18:15-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: four existing `missing_ref_uid 0003AM` diagnostics from `by-file/FittingRoom.md`; no UID0000WP-specific validator failure.
  - Side effects: stats incremental noop for UID0000JE, projected stats update, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md --apply --queue-timeout 240`
  - `command_id: 000000005552`
  - `command_timestamp: 2026-07-03T15:18:23-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none in scoped output.
  - Side effects: reference-index addition for `0000WP`, stats incremental noop for UID0002CP, projected stats update, generated refresh deferred.

Generated freshness:

- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` header records `validator-command-id: 000000005552`, `validator-refreshed-at: 2026-07-03T15:18:23-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- UID0000WP appears in generated output as constructor code at lines around `706-711` with `Completion:88 | Confidence:90`; it is no longer an `Empty Emitter Marker`.
- Generated files were not edited manually.

Unresolved validator warnings/errors:

- `by-file/FittingRoom.md` still reports four pre-existing `missing_ref_uid 0003AM` warnings. This callback did not edit validator registry state or run lifecycle cleanup commands.

## Changed Files

Created during original report-only pass:

- `tools/leaser/Agents/Agent-B007/research/0000WP-FittingRoomDownloadControlPaneRawConstructor-source-quality.md`

Modified during implementation callback:

- `by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md`
- `by-class/FittingRoomDownloadControlPane.md`
- `by-file/FittingRoom.md`
- `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`
- `tools/leaser/Agents/Agent-B007/research/0000WP-FittingRoomDownloadControlPaneRawConstructor-source-quality.md`

Validator/tool-owned side effects observed:

- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` refreshed from scoped validators and now contains UID0000WP constructor output.
- Validator/project generated stats and registry/index state were updated by validator commands; B007 did not edit validator state by hand.

Renamed:

- None.

Report execution: not run. B007 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or archive commands.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: Gate 1 passed at SHA256 `9564D7BA3DCF61D805ABE1789842B29B69EAB2B093D5279E70762A789948FE83`; supervisor issued implementation callback.
- [x] Target/support docs to update: target UID0000WP, `by-class/FittingRoomDownloadControlPane.md`, `by-file/FittingRoom.md`, and `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md` were updated; UID0000WQ was inspected and excluded as already current from B008.
- [x] Current target state and actual evidence checked recorded: historical `85/89`, owner/emitter `000052`, blank C++ and current implemented `88/90`, formal C++; MCP session `2ec9c08f` facts recorded in this report and target/support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: all accepted rows are `applied`; UID0000WQ and UID00041P optional items are accounted for as already-present/excluded-with-reason in support recommendations.
- [x] Metadata/score changes applied: UID0000WP set to `COMPLETION:88`, `CONFIDENCE:90`.
- [x] Score-limiting blockers researched to resolution: no-function/no-xref/no-pointer route remain confidence caps; C++ readiness resolved by inline constructor evidence.
- [x] Owner/emitter/reconstructable changes applied: kept `CANONICAL_OWNER:000052`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000052`, blank optional position.
- [x] Split/rename/new-child changes applied: none required.
- [x] Source-placement/range/padding/reclassification changes applied: kept exact `0x0041b9e0-0x0041ba20` range; preserved predecessor padding and successor destructor evidence.
- [x] First-draft C++ applied: inserted exact formal constructor block from `## First-Draft C++ Recommendation`.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts incorporated: MCP `2ec9c08f` health/session provenance, exact bytes, no function objects, no xrefs, no pointer/immediate route, vtable-family refs, inline dialog constructor match, fixed ControlPane type `8`, `+0x108` progress clear.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: blank-C++ policy superseded; raw-start no-route retained; rejected raw helper, FittingRoomDialog owner, ControlPane owner, direct-file-only owner, no-owner/non-emitting, and child-id `7` as proven target parameter.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated/Wave3-style constructor names used as leads only; current MCP/by-* evidence controls.
- [x] Open questions documented: raw-body route, exact field type/name, exact parameter spelling, UID0000WQ destructor source policy.
- [x] Validators run after callback: commands `000000005549` through `000000005552` recorded in `## Validator Results`.
- [x] Generated report refresh completed by validator: `auto-generated/NexusTK/cashshop/FittingRoom.cpp` header now records command `000000005552`, refreshed `2026-07-03T15:18:23-04:00`, and contains UID0000WP constructor code.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator and confirmed current.
- [x] Remaining unapplied accepted items listed with exact blocker: none for accepted UID0000WP claims; optional UID0000WQ row sync excluded because B008 details were already current, and UID00041P cleanup excluded as sibling/out-of-scope support cleanup.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000005560","destination_path":"executed-b-agent-research/B007/0000WP-FittingRoomDownloadControlPaneRawConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000WP-FittingRoomDownloadControlPaneRawConstructor-source-quality.md","timestamp":"2026-07-03T15:30:07-04:00","uid":"0000WP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
