** TARGET-REPORT-UID:0004CR **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004CR StartupWindowOrdinaryDestructor Source-Quality Report


## Finalized Report / Current Recommendation
- Current recommendation: post-implementation callback artifact ready for supervisor verification/execute. UID0004CR is a source-owned `StartupWindow` ordinary/non-deleting destructor body and remains reconstructable/emitting through [UID:0000O5][StartupWindow](by-file/StartupWindow.md) / `NexusTK/app/StartupWindow.cpp`.
- Final disposition: accepted Gate 1 details have been applied. The target is now `88/90`; owner/emitter routing is preserved; the formal destructor C++ is the inline cleanup body from this report; StartupWindow support docs were synchronized at report-level detail.
- Required supervisor action: Gate 2 verification and supervisor-only `execute_report` if accepted. B011 did not run lifecycle/execute commands.
- Confidence: high for ownership, range, destructor role, and source placement; capped below 91 because IDA still has no function object at `0x00580810`, no direct start refs were found, and exact original member/type names remain inferred.

## Supporting Research
- Historical report-only pass: B011 produced this UID0004CR report without editing target/support by-* docs, generated files, coverage reports, validator state, lifecycle/archive state, or supervisor ledgers.
- Current artifact state: implementation callback has now been applied to the target/support by-* docs named in this report. Scoped validators ran for every changed by-* file; generated `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed through validator command `000000006384`. Generated files were not edited manually.
- The project-level `ntk-b-agent-workflow` skill and report template were read before writing this artifact. The score-blocker standard was applied: each named blocker was resolved into an implementation-ready recommendation or retained as a quantified confidence cap.
- Prior executed evidence checked:
  - B010 `0001IO-StartupWindowUpdateCheck-source-quality.md` identified `0x0058080c-0x00580810` as four `0xcc` bytes and `0x00580810-0x00580870` as valid destructor-like code with no rel32/VA/RVA start refs.
  - B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md` created UID0004CR as the exact child and inserted the first-draft destructor C++; validator `000000003697` assigned UID0004CR and refreshed generated output.
- Historical pre-callback generated output checked: `auto-generated/NexusTK/app/StartupWindow.cpp` had been refreshed by validator command `000000006343` at `2026-07-04T13:36:35-04:00` and emitted UID0004CR at `86/88` with `StartupWindow::~StartupWindow()` calling `ReleaseNoticeAssets()` and conditionally clearing `g_pStartupWindow`.
- Current post-callback generated output checked: `auto-generated/NexusTK/app/StartupWindow.cpp` now has `validator-command-id: 000000006384`, `validator-refreshed-at: 2026-07-04T17:49:11-04:00`, `validator-refresh-source: deferred-generated-refresh`, and UID0004CR emits at `88/90` with the inline image cleanup and unconditional `g_pStartupWindow = NULL`.

## Target
- Target UID: `0004CR`.
- Target path: `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md`.
- Source queue/report row: Medium B-agent source-quality report for a source-bearing exact child already split from the broad StartupWindow update-check aggregate.
- Current supervisor classification: implementation callback applied; ready for supervisor Gate 2 verification / supervisor-only execute.
- Current scores and parent state: target is now `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position. Parent class [UID:0000DZ] remains `88/89`; file route [UID:0000O5] remains `89/88`; aggregate [UID:0001IO] remains non-emitting split/index `88/90`.

## Current Target State
- Current metadata: `88/90`, owner [UID:0000DZ][StartupWindow](by-class/StartupWindow.md), emitter [UID:0000O5][StartupWindow](by-file/StartupWindow.md), reconstructable true, blank optional emitter position.
- Current C++/emitter state: formal C++ now uses the accepted inline destructor body: delete `m_backgroundImage`, delete the three image slots for each of two `m_buttons` entries when assets are loaded, then assign `g_pStartupWindow = NULL`.
- Superseded pre-callback state: the old formal C++ abstracted cleanup as `ReleaseNoticeAssets()` and cleared `g_pStartupWindow` only inside `if (g_pStartupWindow == this)`. Those are now historical/descriptive only; the target/support docs explicitly record current MCP evidence for inline cleanup and unconditional clear.
- Remaining confidence caps: no IDA function object at `0x00580810`; decompilation at `0x00580810` fails; no code/data/immediate ref to the raw start; exact member names and image pointer type spellings are inferred from adjacent StartupWindow children. These remain score caps, not implementation blockers.
- Current artifact/lifecycle status: implementation callback applied and scoped validators passed. B011 has not executed or moved the report; supervisor Gate 2 verification/execute remains.

## Executive Recommendation
- Keep UID0004CR assigned to `StartupWindow` and emitted by `StartupWindow.cpp`.
- Preserve the half-open range `0x00580810-0x00580870`; do not merge it into the constructor, RunUpdateCheck, scalar deleting destructor wrapper, or the broad [UID:0001IO] split/index.
- Replace the existing formal C++ with an inline destructor cleanup that directly expresses the byte-proven behavior: if assets are loaded, delete the background image and the three image slots for each of two notice buttons, then unconditionally clear `g_pStartupWindow`.
- Raise the target to `COMPLETION:88`, `CONFIDENCE:90`. Do not raise higher until IDA has an exact function object or a direct call/exception/vtable route to `0x00580810`, and until the final original member/type names are resolved.

## Supervisor Active Recheck
- Historical supervisor instruction produced the original report-only artifact for UID0004CR. Current supervisor callback accepted the report and instructed B011 to apply the accepted details to target/support by-* docs.
- The assigned item does not require a new split before Gate 1; B008 already created the exact child. This report rechecks source-quality blockers and recommends a narrow formal-C++ correction.
- Every source-bearing item directly in scope was checked and applied or marked already sufficient: the constructor predecessor, four-byte padding, UID0004CR raw destructor body, RunUpdateCheck successor, scalar deleting destructor wrapper, StartupWindow class/file docs, `g_pStartupWindow` storage/global docs, prior B008/B010 reports, and generated `StartupWindow.cpp`.

## Inference Research Guidance Check
- IDA MCP facts were treated as highest weight: function inventory, xrefs, bytes, instruction scans, decompilation success/failure, and integer conversions.
- Existing by-* docs and executed reports were treated as strong documentation evidence but revalidated where current MCP could check them. The current pass corrected the stale conditional-clear/formal-helper wording from older accepted C++.
- Generated output was used to confirm current emitter state, not as primary binary evidence.
- No Wave2/Wave3 artifacts were used as active authority.

## Heuristic / Inference Reanalysis And Validation
- Range and padding: current `lookup_funcs` confirms constructor `StartupWindow__Constructor` at `0x005807d0` size `0x3c`; `0x0058080c` and `0x00580810` are not IDA functions; `get_bytes` confirms `0x0058080c-0x00580810` is `cc cc cc cc`; `0x00580870` starts `StartupWindow__RunUpdateCheck` size `0x88d`. UID0004CR is therefore an exact raw body between padding and the RunUpdateCheck successor.
- Raw-body validity: `get_bytes` over `0x00580810` returns 96 bytes ending in `5e c3`; bounded `insn_query` finds 39 instructions from `push esi` at `0x00580810` through `retn` at `0x0058086f`. This is code, not padding or data.
- Destructor role: the raw body writes the `StartupWindow` vtable at `0x00580817`, checks `this+0x04`, releases owned pointers through four virtual deleting calls with `push 1`, iterates two 0x20-byte button groups, clears `g_pStartupWindow` at `0x00580864`, and returns without deleting `this`.
- Scalar deleting destructor relationship: `lookup_funcs` records `0x00581d30` as `sub_581D30`, size `0x82`; `xrefs_to 0x00581d30` reaches the vtable slot `0x0062d470`; decompilation shows the same cleanup shape plus `if (a2 & 1) sub_5C7526(Block)`. That wrapper is compiler/ABI support, while UID0004CR is the source-facing destructor body.
- No direct start refs: current `xrefs_to 0x00580810` is empty, and `find` for code refs, data refs, and immediates to `0x00580810` each returned zero matches. This remains a confidence cap, but B008/B010 plus current vtable/global cleanup evidence make it safe to keep the child reconstructable instead of blanking it.
- `ReleaseNoticeAssets()` naming/source shape: no call instruction in UID0004CR targets a separate helper; the body performs the release logic inline. `ReleaseNoticeAssets` can remain prose shorthand if clearly labeled descriptive, but the formal target C++ should not depend on an unsupported helper declaration.
- `g_pStartupWindow` clear semantics: current raw-body instruction at `0x00580864` and scalar deleting wrapper decompile both clear `unk_69BAC8` unconditionally. The old `if (g_pStartupWindow == this)` is a plausible source-safety idiom, but it is not the current best reconstruction of the compiled body.
- Member names/types: existing constructor/WndProc/load/draw children support `m_assetsLoaded`, `m_backgroundImage`, and `m_buttons[index].images[n]`. Exact original names and the precise `PcxImage`/image-object type remain inferred, not blockers.
- Rejected alternatives:
  - Treat as padding: rejected by bytes and 39 decoded instructions.
  - Merge into constructor: rejected by constructor size `0x3c` ending at `0x0058080c` and four padding bytes before `0x00580810`.
  - Merge into RunUpdateCheck: rejected by successor function start `0x00580870`.
  - Emit scalar deleting destructor wrapper instead: rejected by vtable slot/reference and conditional delete flag at `0x00581d30`.
  - Move ownership to Browser/ImageLoaders/PCX loader: rejected because the body only deletes StartupWindow-owned notice image pointers and updates the StartupWindow singleton; loader implementations remain separate support.

## Evidence Standards Used
- Evidence ladder used: current IDA MCP facts first; existing by-* docs and executed reports second; generated output third; inference only where binary and documentation agree.
- Strong evidence: function boundaries, raw bytes, instruction inventory, xrefs, vtable/global refs, scalar deleting destructor decompile, and current generated output.
- Negative evidence: absence of function object, decompile failure at the raw start, empty xrefs to `0x00580810`, and zero code/data/immediate matches were treated as confidence caps, not as proof of non-code.
- Tool limitations: Hex-Rays cannot decompile `0x00580810` because IDA does not own it as a function. The report therefore relies on paged `insn_query`/bytes for UID0004CR and uses `0x00581d30` decompilation only as corroborating shared-cleanup evidence.

## Evidence Checked
- MCP session: `nexustk_supervisor_20260704`; `idb_list` showed one active owned/adopted session for `NexusTK.exe.i64`, not analyzing. `server_health` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `imagebase: 0x400000`, strings cache ready.
- MCP `lookup_funcs`: `0x005807d0` `StartupWindow__Constructor` size `0x3c`; `0x0058080c` not a function; `0x00580810` not a function; `0x00580870` `StartupWindow__RunUpdateCheck` size `0x88d`; `0x005810fd` not a function; `0x00581d30` `sub_581D30` size `0x82`; `0x00581db2` not a function; `0x00582070` successor function size `0x2a`.
- MCP `xrefs_to`: `0x00580810` zero refs; `0x00580870` one caller at `_WinMain@16+0xd2` / `0x004f5d52`; `0x005807d0` one caller at `_WinMain@16+0xba` / `0x004f5d3a`; `0x00581d30` one data ref from `0x0062d470`; `0x0062d470` refs from constructor `0x005807ed`, raw UID0004CR `0x00580817`, and scalar deleting destructor `0x00581d3a`; `0x0069bac8` refs from constructor `0x005807e5`, UID0004CR `0x00580864`, WndProc `0x00581114`, and scalar deleting destructor `0x00581d94`.
- MCP `find`: code_ref/data_ref/immediate searches for `0x00580810` each returned zero matches.
- MCP `get_bytes`: `0x0058080c` four bytes `cc cc cc cc`; `0x00580810` 96-byte body beginning `56 8b f1 80 7e 04 00 c7 06 70 d4 62 00` and ending `c7 05 c8 ba 69 00 00 00 00 00 5e c3`; `0x00580870` begins the successor prologue `55 8b ec 6a ff 68 6e 89`; `0x0062d46c` contains COL/vtable data ending in pointer bytes for `0x00581d30`; `0x0069bac8` is zero in the IDB snapshot.
- MCP `insn_query`: UID0004CR produced 39 instructions, no function owner, four indirect virtual calls in the cleanup body, and an unconditional global clear at `0x00580864`. Call-only scan found calls at `0x0058082a`, `0x00580840`, `0x0058084c`, and `0x00580859`, all `call dword ptr [eax]`.
- MCP `decompile`: `0x00580810` failed with `Decompilation failed at 0x580810`; `0x00581d30` decompiled successfully and matched the same cleanup shape plus the scalar deleting destructor flag/delete call.
- MCP `int_convert`: `0x60` is decimal 96; `0x4` is decimal 4; `0x82` with size 2 is decimal 130; `0x3c` is decimal 60; `0x88d` is decimal 2189; `0x58` is decimal 88.
- Local docs checked: target UID0004CR, [UID:0000DZ] class doc, [UID:0000O5] file doc, [UID:0001IO] broad aggregate, [UID:0004CQ] constructor, [UID:0004CT] WndProc, [UID:0004D4] scalar deleting destructor, [UID:0002ZS] global, [UID:0002ZT] storage, StartupWindow `.rdata`/resource references, executed B008/B010 reports, generated `StartupWindow.cpp`.
- Historical report-only pass intentionally skipped validators and by-* edits. Current implementation callback ran scoped validators for every changed by-* file and updated generated freshness in this report.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C0004CR-01 | UID0004CR range is exact raw code `0x00580810-0x00580870`, not padding and not an IDA function. | High | MCP `lookup_funcs`, `get_bytes`, `insn_query`; B010 split evidence. | Target Status/Evidence; parent aggregate row. | incorporate | applied: target Evidence and [UID:0001IO] covered row record exact raw range, no-function state, size, and padding context; validators `000000006379` and `000000006383` passed. |
| C0004CR-02 | Predecessor `0x0058080c-0x00580810` is four-byte `0xcc` padding and successor `0x00580870` is RunUpdateCheck. | High | MCP `get_bytes`; `lookup_funcs` constructor and RunUpdateCheck sizes. | Target range/split notes; [UID:0001IO] row if stale. | incorporate | applied: target Evidence and aggregate Covered Ranges preserve four-byte padding and successor `0x00580870`; validators `000000006379`/`000000006383` passed. |
| C0004CR-03 | The body is an ordinary/non-deleting `StartupWindow::~StartupWindow` cleanup, not a free helper. | High | Vtable write at `0x00580817`, pointer releases, global clear, scalar wrapper comparison. | Target Ownership/Emission; class method notes. | incorporate | applied: target Status/C++/Ownership and [UID:0000DZ] method row now call this source-ready `StartupWindow::~StartupWindow`; validators `000000006379`/`000000006380` passed. |
| C0004CR-04 | No direct start refs exist for `0x00580810`; this is a confidence cap, not a no-code blocker. | High | MCP `xrefs_to` zero; `find` code/data/immediate zero; B008/B010 PE-scan negative evidence. | Target negative evidence; score rationale. | incorporate | applied: target Evidence, class method row, aggregate row, and score rationale preserve no-direct-start-ref as a confidence cap; validators passed. |
| C0004CR-05 | Scalar deleting destructor `0x00581d30-0x00581db2` is compiler-generated wrapper support and must not own/source-emit UID0004CR. | High | Vtable xref at `0x0062d470`; decompiled flag/delete call; size `0x82`. | Target rejected alternatives; scalar destructor support doc if stale. | incorporate | applied/already-present: target and aggregate mention scalar wrapper comparison; `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md` was checked and already sufficient, so it was not edited. |
| C0004CR-06 | Current formal `ReleaseNoticeAssets()` is descriptive abstraction only; raw body performs inline deletion logic. | Medium-high | UID0004CR call scan has only four indirect virtual calls; no helper call. | Target C++ block; support docs stale wording. | historicalize | applied: target formal C++ no longer calls `ReleaseNoticeAssets`; target/class/file prose historicalizes it as descriptive shorthand. |
| C0004CR-07 | `g_pStartupWindow` is cleared unconditionally in this body. | High | Instruction `0x00580864` and scalar wrapper decompile both write zero to `0x0069bac8` without compare. | Target C++ block/evidence; global support note if stale. | reject-stale | applied: target formal C++ assigns `g_pStartupWindow = NULL`; target/class/file/aggregate/storage child record raw unconditional clear. `by-global/g_pStartupWindow.md` was checked and already sufficient. |
| C0004CR-08 | Best formal C++ should inline null-checked deletes of `m_backgroundImage` and `m_buttons[2].images[3]`, then clear the singleton. | Medium-high | Assembly pointer offsets `+0x10`, loop over two 0x20 groups, existing WndProc/load helper names. | Target `RECONSTRUCTION_CPP CODE`. | incorporate | applied: exact formal C++ block from this report was inserted in the target and generated output now shows the same body under validator `000000006384`. |
| C0004CR-09 | Owner remains [UID:0000DZ] and emitter remains [UID:0000O5]. | High | Class vtable/global/lifecycle evidence; StartupWindow file docs; no competing owner evidence. | Target metadata; class/file docs. | incorporate | applied: target preserves `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank optional position. |
| C0004CR-10 | Recommended score is `88/90`, not higher. | Medium-high | Better C++ and current MCP close stale assumptions; no function object/direct refs and inferred field names remain. | Target metadata and score rationale. | incorporate | applied: target metadata is now `COMPLETION:88`, `CONFIDENCE:90`; validator `000000006379` reported completion/confidence updates and exit `0`. |
| C0004CR-11 | Generated `StartupWindow.cpp` should refresh from the target after callback and replace the helper/conditional-clear body. | High | Current generated file emits UID0004CR directly from target docs. | Validator/generation checklist. | incorporate | applied: generated header is `validator-command-id: 000000006384`, `validator-refreshed-at: 2026-07-04T17:49:11-04:00`, and UID0004CR emits at `88/90` with inline cleanup/no `ReleaseNoticeAssets`. |
| C0004CR-12 | No lifecycle/execute/coverage/generated edits are allowed by B011 during report-only or implementation callback. | High | Supervisor instruction and B-agent workflow. | Changed Files; Implementation Checklist. | not-applicable | applied: no generated/coverage/validator-state/supervisor-ledger/lifecycle files were manually edited; no `execute_report` or lifecycle command was run. |

## Positive Evidence Summary
- Direct binary facts support destructor ownership: UID0004CR writes the `StartupWindow` vtable, tests the initialized/assets flag, releases StartupWindow-owned image/button pointers through deleting virtual calls, clears the StartupWindow singleton, and returns without object free.
- Boundary facts support exact child status: constructor ends at `0x0058080c`, four `0xcc` bytes follow, UID0004CR starts at `0x00580810`, and `RunUpdateCheck` starts at `0x00580870`.
- Corroborating docs support source placement: StartupWindow class/file docs and B008/B010 executed reports already route constructor/destructor/RunUpdateCheck/WndProc/source-local helpers through `StartupWindow.cpp`.
- Strongest inference chain: the raw body is not directly referenced, but it is byte-valid, class-vtable restoring, structurally identical to the vtable-referenced scalar deleting destructor cleanup minus the delete flag, and tied to the same singleton/global lifecycle. That is sufficient for a source-authored destructor child with a no-direct-route confidence cap.

## IDA MCP Facts
- Active session: `nexustk_supervisor_20260704`.
- Function facts: constructor `0x005807d0` size `0x3c`; UID0004CR start not a function; RunUpdateCheck `0x00580870` size `0x88d`; scalar deleting destructor wrapper `0x00581d30` size `0x82`; successor `0x00582070` size `0x2a`.
- Data/table/padding facts: four `0xcc` bytes at `0x0058080c`; vtable pointer `0x0062d470` references `0x00581d30`; singleton storage `0x0069bac8` is the global cleared by both destructor bodies.
- Xref facts: no xrefs to `0x00580810`; constructor and RunUpdateCheck are called only from `_WinMain@16` in current `xrefs_to`; scalar deleting destructor has vtable data ref; `g_pStartupWindow` has constructor/raw destructor/WndProc/scalar destructor refs.
- Negative IDA facts: decompilation at `0x00580810` fails; no code/data/immediate references to the raw start.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005807d0-0x0058080c` | [UID:0004CQ][constructor](by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md) | `StartupWindow::StartupWindow(HINSTANCE)` | TRUE | [UID:0000DZ]/[UID:0000O5] | `88/90` | already source-emitting |
| `0x0058080c-0x00580810` | no standalone doc | alignment padding | FALSE/ignored | [UID:0001IO] split inventory | n/a | four `0xcc` bytes |
| `0x00580810-0x00580870` | [UID:0004CR][target](by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md) | ordinary/non-deleting destructor cleanup | TRUE | [UID:0000DZ]/[UID:0000O5] | current `86/88`, recommended `88/90` | source-ready with C++ repair |
| `0x00580870-0x005810fd` | [UID:0004CS][RunUpdateCheck](by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md) | `StartupWindow::RunUpdateCheck` | TRUE | [UID:0000DZ]/[UID:0000O5] | `88/90` | already source-emitting |
| `0x00581d30-0x00581db2` | [UID:0004D4][scalar deleting destructor](by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md) | compiler scalar deleting destructor wrapper | FALSE | [UID:0000DZ]/compiler ABI | `86/90` | non-emitting wrapper proof |
| `0x005807d0-0x0058206e` | [UID:0001IO][aggregate](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) | StartupWindow executable neighborhood split/index | FALSE | [UID:0000O5] | `88/90` | non-emitting child inventory |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00580810` | zero `xrefs_to`, zero `find code_ref/data_ref/immediate` | raw destructor body has no direct static start route in current IDA evidence |
| `0x005807d0` | `_WinMain@16` at `0x004f5d3a` | constructor source path is live from WinMain |
| `0x00580870` | `_WinMain@16` at `0x004f5d52` | RunUpdateCheck source path is live from WinMain |
| `0x00581d30` | data ref from `0x0062d470` | vtable references scalar deleting destructor wrapper |
| `0x0062d470` | refs from `0x005807ed`, `0x00580817`, `0x00581d3a` | constructor, raw destructor, and scalar wrapper write/consume StartupWindow vtable support |
| `0x0069bac8` | refs from `0x005807e5`, `0x00580864`, `0x00581114`, `0x00581d94` | singleton lifecycle spans constructor, raw destructor, WndProc, and scalar wrapper |

## Documentation Evidence And IDA Status
- Supporting docs already correct enough: [UID:0000DZ] class and [UID:0000O5] file route exact child bodies through StartupWindow; [UID:0001IO] marks the broad range as non-emitting split/index; [UID:0004D4] identifies the scalar deleting destructor wrapper as compiler-generated.
- Stale/incomplete target wording: UID0004CR says `ReleaseNoticeAssets()` in formal C++ and says the global is cleared when it still points to this object. Current MCP supports inline cleanup and unconditional clear instead.
- Generated output state: `StartupWindow.cpp` currently emits UID0004CR, so this is not an empty-marker issue; generated freshness after implementation should show the replacement destructor body, not a blank marker.

## Ranked Ownership Analysis

### 1. [UID:0000DZ] StartupWindow class / [UID:0000O5] StartupWindow.cpp
- Evidence for: vtable write, class singleton clear, matching scalar deleting destructor wrapper, constructor/WndProc/load/draw helper support, and existing source route.
- Evidence against: no direct start refs and no IDA function object at `0x00580810`.
- Decision: best owner/emitter pair; keep metadata owner/emitter unchanged.

### 2. [UID:0004D4] StartupWindow scalar deleting destructor wrapper
- Evidence for: same cleanup shape and vtable connection.
- Evidence against: wrapper has compiler delete flag, object free call, vtable slot reference, and `retn 4`; it is ABI-generated support and is already non-emitting.
- Decision: reject as source owner; use only as corroborating evidence for destructor source shape.

### 3. ImageLoaders/PCX resource helpers or Browser/update features
- Evidence for: the body releases image-like pointers loaded/drawn by startup notice code.
- Evidence against: no loader implementation lives here; pointers are fields of `StartupWindow`; Browser/update features consume or support the notice workflow but do not own the destructor.
- Decision: reject as direct owners.

### Proposed new file/grouping, if applicable
- No new file is needed. The source route remains `NexusTK/app/StartupWindow.cpp`.

## Source Placement
- Recommended source file/class/module placement: `StartupWindow::~StartupWindow()` in `NexusTK/app/StartupWindow.cpp`, under the `StartupWindow` class body emitted by exact by-memory child UID0004CR.
- Why this placement fits: constructor, RunUpdateCheck, WndProc, notice helpers, globals, and resource strings all already route through StartupWindow; the raw body manipulates StartupWindow fields and singleton state only.
- Rejected placements: scalar deleting destructor wrapper, broad [UID:0001IO] aggregate, Browser, ImageLoaders, PCX loader, and no-owner/non-reconstructable downgrade.
- Remaining placement uncertainty: none material to source file; the only cap is exact original member/type spelling.

## Range / Split / Padding / Reclassification Analysis
- Exact range: `0x00580810-0x00580870`, decimal size 96 (`0x60`), ending at the byte before `RunUpdateCheck`.
- Predecessor: constructor `0x005807d0-0x0058080c`, decimal size 60 (`0x3c`).
- Padding: `0x0058080c-0x00580810` is exactly four bytes of `0xcc`.
- Successor: `StartupWindow__RunUpdateCheck` starts at `0x00580870`, decimal size 2189 (`0x88d`).
- Reclassification: none needed; UID0004CR is already an exact source-bearing child. The implementation callback should update content/score, not split or move the range.

## Negative Evidence Summary
- No IDA function object at `0x00580810`; Hex-Rays decompilation fails at the raw start.
- No direct code xrefs, data xrefs, or immediate references to `0x00580810` were found in current MCP checks.
- No direct helper call supports `ReleaseNoticeAssets()` as an actual separately emitted helper in this body.
- The scalar deleting destructor wrapper is related but not source-emitting for UID0004CR because it contains compiler ABI delete-flag behavior.
- These negatives limit confidence but do not prove no-code; the body has exact class destructor semantics and current generated output already emits it.

## IDA Rename / Type / Comment Recommendations
- No IDA database rename/type/comment edits are requested for this report or callback.
- Source-facing names/types for docs/C++:
  - Keep method name `StartupWindow::~StartupWindow`.
  - Use existing support names `m_assetsLoaded`, `m_backgroundImage`, and `m_buttons[index].images[n]` because adjacent constructor/WndProc/load-helper docs already use them.
  - Historicalize `ReleaseNoticeAssets` as descriptive prose only unless a future pass creates a real source helper declaration/body.
- Items intentionally left inferred: exact original image pointer class and button-image member names.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. This is a source-owned class destructor body with exact range, field-access pattern, and source route.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for the target.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StartupWindow::~StartupWindow()
{
    if (m_assetsLoaded) {
        if (m_backgroundImage != NULL) {
            delete m_backgroundImage;
        }

        for (int buttonIndex = 0; buttonIndex < 2; ++buttonIndex) {
            for (int imageIndex = 0; imageIndex < 3; ++imageIndex) {
                if (m_buttons[buttonIndex].images[imageIndex] != NULL) {
                    delete m_buttons[buttonIndex].images[imageIndex];
                }
            }
        }
    }

    g_pStartupWindow = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: MSVC emits null checks and scalar-deleting virtual calls for `delete` on non-null owned image pointers; the loop count and pointer layout match the raw body's background pointer plus two groups of three image slots; the singleton clear is unconditional as compiled.
- Reason it matches plausible original source shape: source destructors normally express field deletes and singleton cleanup, while vtable restoration and scalar-deleting-wrapper flags are compiler output.
- Inferred source-facing names/types: `m_assetsLoaded`, `m_backgroundImage`, and `m_buttons[index].images[n]` come from existing constructor/WndProc/load-helper pages and generated StartupWindow output; exact original names remain a confidence cap.
- Reason current target helper should not remain formal C++: no direct call to `ReleaseNoticeAssets()` exists in UID0004CR, and leaving it as the only formal implementation requires an unsupported private helper declaration.

## Final Recommendation
- Applied target metadata `COMPLETION:88`, `CONFIDENCE:90`.
- Preserved `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replaced the target formal C++ with the exact inline destructor block above.
- Incorporated current MCP session `nexustk_supervisor_20260704` facts into target/support docs: range `0x00580810-0x00580870`, size `0x60`/96, no IDA function/decompile failure, no direct start refs, four-byte predecessor padding, successor `0x00580870`, vtable/global refs, pointer-release loop, scalar deleting destructor comparison, and generated-current state.
- Historicalized stale assumptions: `ReleaseNoticeAssets()` as a direct helper and conditional `g_pStartupWindow == this` clear are superseded/descriptive, not current formal source.
- Kept no-direct-start-ref and inferred member/type names as score rationale, not implementation blockers.
- Not applied because already sufficient: scalar deleting destructor wrapper doc already stated compiler-generated/non-emitting status; `by-global/g_pStartupWindow.md` already preserved the raw UID0004CR lifecycle ref without conditional-clear contradiction.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md`.
- Applied exact report facts:
  - Current MCP session `nexustk_supervisor_20260704`, health ready.
  - `lookup_funcs` results for constructor, raw target, successor, scalar deleting destructor.
  - `get_bytes` four-byte padding and 96-byte raw body.
  - `insn_query` body sequence: vtable write, assets flag, one background release, two button groups with three image-slot releases, unconditional singleton clear, `retn`.
  - Negative xref/find evidence for `0x00580810`.
  - Scalar deleting destructor wrapper at `0x00581d30` is related compiler support, not target source body.
- Applied metadata/C++ changes:
  - `COMPLETION:88`, `CONFIDENCE:90`.
  - Owner/emitter/reconstructable unchanged.
  - Replace formal C++ with the exact block in this report.
- Historical/stale assumptions preserved:
  - B008/B010 no-direct-route caveat.
  - `ReleaseNoticeAssets()` as superseded descriptive shorthand.
  - Conditional singleton clear as superseded by current MCP instruction evidence.

## Recommended Support Doc Changes
- `by-class/StartupWindow.md`: applied UID0004CR method-row/detail update to source-ready `StartupWindow::~StartupWindow`; recorded inline notice image/button cleanup, unconditional `g_pStartupWindow` clear, no-direct-start-ref confidence cap, and scalar-wrapper distinction.
- `by-file/StartupWindow.md`: applied generated/source route update so UID0004CR is a source-ready exact child with corrected inline destructor body under `StartupWindow.cpp`; broad StartupWindow split/index context remains preserved.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`: applied support sync to the UID0004CR covered row, B010 historical section, B003 historical section, behavior summary, and changes log while preserving `RECONSTRUCTABLE:FALSE`, blank emitter, blank formal C++, and no-monolithic-C++ state.
- `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md`: checked and already sufficient; no edit. It continues to say the wrapper is compiler-generated, non-emitting, and should not duplicate UID0004CR source.
- `by-global/g_pStartupWindow.md`: checked and already sufficient; no edit. It records the raw `0x00580864` lifecycle evidence without conditional-clear contradiction.
- `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`: applied narrow support sync because the storage child still carried pre-acceptance no-emission wording for UID0004CR. It now records the accepted exact-child route and raw unconditional singleton clear while remaining a no-duplicate storage marker.
- Generated `auto-generated/NexusTK/app/StartupWindow.cpp`: not manually edited. Validator deferred-generated refresh updated it to command `000000006384` and the UID0004CR inline destructor body.

## Score And Metadata Recommendation
- Pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, owner `0000DZ`, reconstructable true, emitter `0000O5`, blank optional position.
- Applied score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged.
- Score rationale and reason higher: current MCP closes stale current-target issues, confirms exact bytes/instructions, confirms unconditional global clear, and supports replacing the unsupported helper call with inline formal destructor C++.
- Reason not higher: no IDA function object, raw decompile failure, no direct static start route, and inferred exact member/type names remain.
- Score-improvement attempt:
  - No function/decompile blocker: checked `lookup_funcs` and `decompile`; resolved by bounded bytes/instruction evidence, not fully removed.
  - No direct route blocker: checked `xrefs_to` and `find` code/data/immediate; remains a confidence cap.
  - Helper-name blocker: checked call instructions and support docs; resolved by recommending inline C++ and historicalizing helper shorthand.
  - Singleton-clear ambiguity: checked raw disassembly and scalar wrapper decompile; resolved as unconditional clear.

## Open Questions With Attempted Resolution
- Is UID0004CR reachable by a direct call or table route? Current answer: no direct static route found. Evidence checked: `xrefs_to`, `find code_ref`, `find data_ref`, `find immediate`, prior B008/B010 PE scans. Impact: confidence cap only.
- Is `ReleaseNoticeAssets()` an actual source helper? Current answer: not proven and not supported by this body; call scan shows only indirect deleting calls. Impact: replace formal helper call with inline cleanup.
- Should `g_pStartupWindow` clear be conditional? Current answer: compiled body clears unconditionally; conditional source idiom should be historicalized unless future original source proves otherwise.
- Are exact field/type names original? Current answer: best inferred from adjacent accepted StartupWindow children. Impact: confidence cap only; not a C++ blocker.

## Follow-Up Actions
- Supervisor action: perform Gate 2 verification against changed docs, validators, generated freshness, and this updated ledger/checklist; then supervisor-only `execute_report` if accepted.
- B011 action complete: implementation callback applied, scoped validators run, generated freshness checked, report ledger/checklist updated, leases released.
- Future adjacent work only if separately assigned: remaining StartupWindow raw helper/source-name refinements outside UID0004CR.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high for `88/90`.
- Remaining uncertainty: direct reachability and exact original field/type names.

## Validator Results
- Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md --apply --queue-timeout 240`
    - `command_id: 000000006379`; `command_timestamp: 2026-07-04T17:48:32-04:00`; exit `0`; `ok: 1`.
    - Updates: `completion_update 0004CR ... 88`; `confidence_update 0004CR ... 90`; `autogen_registry_update 0004CR ...`; `projected_stats_update`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006380`; `command_timestamp: 2026-07-04T17:48:37-04:00`; exit `0`; `ok: 1`.
    - Updates: `projected_stats_update`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006382`; `command_timestamp: 2026-07-04T17:48:49-04:00`; exit `0`; `ok: 1`.
    - Updates: `projected_stats_update`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240`
    - `command_id: 000000006383`; `command_timestamp: 2026-07-04T17:49:01-04:00`; exit `0`; `ok: 1`.
    - Updates: `projected_stats_update`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006384`; `command_timestamp: 2026-07-04T17:49:11-04:00`; exit `0`; `ok: 1`.
    - Updates: `autogen_registry_update 0002ZT ...`; `reference_index_add 0004CR ...`; `projected_stats_update`; `generated_refresh: deferred`.
- Warnings/errors: none reported by scoped validators.
- Generated freshness: `auto-generated/NexusTK/app/StartupWindow.cpp` now has `validator-command-id: 000000006384`, `validator-refreshed-at: 2026-07-04T17:49:11-04:00`, `validator-refresh-source: deferred-generated-refresh`. UID0004CR now emits at `Completion:88 | Confidence:90` with the inline destructor body; no `ReleaseNoticeAssets` or `g_pStartupWindow == this` remains in generated output.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B011/research/0004CR-StartupWindowOrdinaryDestructor-source-quality.md` during the initial report-only pass.
- Modified by B011 in this implementation callback:
  - `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md`
  - `by-class/StartupWindow.md`
  - `by-file/StartupWindow.md`
  - `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
  - `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`
  - `tools/leaser/Agents/Agent-B011/research/0004CR-StartupWindowOrdinaryDestructor-source-quality.md`
- Renamed: none.
- Checked but not edited: `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md`, `by-global/g_pStartupWindow.md`.
- Leases used/released:
  - Acquired with `python .\leaser.py B011 lease ...`: target, `by-class/StartupWindow.md`, `by-file/StartupWindow.md`, aggregate `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, and storage child `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`; each returned `Success`.
  - Released with `python .\leaser.py B011 unlease ...`; each returned `Success`.
- Generated/tool side effects from validators only:
  - `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed by validator command `000000006384`.
  - `project-level/-auto-completion-stats.md` updated by scoped validator projected-stats refresh.
  - Validator output also reported autogen registry/reference-index updates internally.
  - B011 did not manually edit generated/project-level files, coverage reports, validator state, supervisor ledgers, lifecycle/archive state, or generated C++.
- Report execution: not run. B011 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, or report moves.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update recorded: target UID0004CR, class/file StartupWindow, parent aggregate, scalar destructor/global check-only docs.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply recorded: `86/88` to `88/90`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched: no function/decompile, no direct refs, helper naming, singleton-clear semantics, member/type names.
- [x] Owner/emitter/reconstructable changes to apply recorded: none, preserve `0000DZ`/`0000O5`/`TRUE`.
- [x] Split/rename/new-child changes to apply recorded: none; exact child already exists.
- [x] Source-placement/range/padding/reclassification findings recorded.
- [x] First-draft C++ to apply supplied as exact formal `RECONSTRUCTION_CPP CODE` insertion text.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence recorded.
- [x] Wave2/Wave3 mentions or artifacts: none used as active evidence.
- [x] Open questions closed or documented as evidence-backed unresolved with score impact.
- [x] Validators to run during implementation callback identified.
- [x] Generated refresh expectation recorded for `auto-generated/NexusTK/app/StartupWindow.cpp`.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: callback approved after Gate 1 for UID0004CR.
- [x] All accepted target/support doc details incorporated at report-level detail: target, class, file route, aggregate, and singleton storage child updated; scalar wrapper/global declaration checked as already sufficient.
- [x] Claim And Incorporation Ledger updated with applied/already-present/excluded verification states.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason: target now `88/90`, owner/emitter/reconstructable/blank optional position preserved, exact formal inline destructor C++ inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: `ReleaseNoticeAssets()` and conditional singleton clear historicalized; no-direct-start-ref and inferred member/type names kept as confidence caps; scalar wrapper/no-owner/alternate owners rejected.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: direct route and exact names remain confidence caps only; no C++ blocker remains.
- [x] Scoped validators run and results recorded: commands `000000006379`, `000000006380`, `000000006382`, `000000006383`, `000000006384`, all exit `0`, all `ok: 1`.
- [x] Generated report refresh completed by validator or exact refresh-lag state recorded: generated `StartupWindow.cpp` header is current at command `000000006384` / `2026-07-04T17:49:11-04:00` and emits UID0004CR inline destructor body.
- [x] Remaining unapplied accepted items listed with exact blocker: none. Items not edited were already sufficient (`StartupWindowScalarDeletingDestructor.md`, `by-global/g_pStartupWindow.md`).

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000006386","destination_path":"executed-b-agent-research/B011/0004CR-StartupWindowOrdinaryDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0004CR-StartupWindowOrdinaryDestructor-source-quality.md","timestamp":"2026-07-04T17:57:34-04:00","uid":"0004CR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
