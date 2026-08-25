** TARGET-REPORT-UID:0000WD **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0000WD WideApiDispatchInit Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` as the authoritative executable startup-table route for PlatformApi wide API dispatch initialization.
- Final disposition: callback implementation applied to the UID0000WD target; `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ML`, and blank formal `RECONSTRUCTION_CPP CODE` are preserved, and the target now records `87/91`.
- Required action after supervisor Gate 2 review: verify the target by-memory page against this report/checklist, validator command `000000006622`, and unchanged blank-C++ policy before any supervisor-only report execution/archive step.
- Confidence: strong for exact range, live startup route, slot writes, PlatformApi ownership, static-object source model, and no-code wrapper policy; medium-high for the eventual final spelling of every dispatch-table typedef/global and for whether source wrote the table setup directly in `UniAPIInit::UniAPIInit()` or a private helper.

## Supporting Research

- Current lifecycle/status: supervisor Gate 1 passed and the implementation callback was applied. The UID0000WD target by-memory page was edited under a short B015 lease, the scoped target validator passed, the lease was released, and this report was updated for Gate 2 review. No support docs, coverage reports, validator state, report lifecycle/archive files, or manually edited generated files were touched.
- Current IDA MCP state after the supervisor MCP incident/restart: JSON-RPC MCP endpoint `http://127.0.0.1:13337/mcp` initialized successfully. `idb_list` reported active session `ba171fe4`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `12196`, `count:1`.
- Current `server_health` for session `ba171fe4`: status `ok`, module `NexusTK.exe`, image base `0x400000`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, auto-analysis ready, Hex-Rays ready, strings cache ready with `2067` strings.
- Historical MCP note: session `cbc24146` supplied the original report's MCP evidence before the incident/restart. It is historical only in this repaired report; all current-state MCP claims and recommendations were rechecked against session `ba171fe4`.
- Prior report search terms used before drafting: `0000WD`, `0x0041a280`, `0x0041a4a8`, `WideApiDispatchInit`, `WideApiDispatch`, `UniAPIInit`, `PlatformApi`, `WideApiDispatchTable`.
- Matching old reports opened as leads: executed B014 `0001KE-UniAPIInit-source-quality.md` and executed B007 `0000FE-UniAPIInit-class-source-quality.md`. They are lead/context material only; current UID0000WD recommendations below are based on current target docs and fresh IDA MCP checks.

## Target

- Target UID: `0000WD`.
- Target path: `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current supervisor classification: B-agent implementation callback complete for a by-memory reconstructable item, awaiting supervisor Gate 2 review.
- Current scores and parent state after callback: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ML`; generated memory coverage routes to `auto-generated/NexusTK/platform/PlatformApi.cpp` and the formal UID0000WD C++ block remains blank by no-code proof.

## Current Target State

- Metadata before callback: `85/90`, owner/emitter [UID:0000ML] `PlatformApi`, reconstructable true, formal C++ block blank.
- Metadata after callback: `87/91`, owner/emitter [UID:0000ML] `PlatformApi`, reconstructable true, formal C++ block still blank.
- Existing owner/emitter/reconstructable state: correct. The exact function is a startup-table dynamic initializer/inlined static-object initialization route for PlatformApi, not a consumer-owned file I/O, browser, input, registry, timer, or UI function.
- Existing C++/emitter state: current generated `auto-generated/NexusTK/platform/PlatformApi.cpp` already emits the [UID:0000FE] `UniAPIInit` declaration, [UID:000249] `ReadUtf16CodeUnitFromFile` and conversion helpers, and [UID:00028B] `static UniAPIInit s_uniAPIInit;`. It leaves [UID:0000WD] as an empty emitter marker.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: final dispatch-table typedef/global spellings remain descriptive in table docs; no support doc currently proves a final source body should hand-write this wrapper, and exact source factoring between `UniAPIInit::UniAPIInit()` and a private file-local helper remains inferred.
- Related target/support docs checked: `by-file/PlatformApi.md`, `by-class/UniAPIInit.md`, `by-global/WideApiDispatchTable.md`, `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`, `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`, `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`, `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`, `by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md`, `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`, and `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`.
- Current artifact/lifecycle status: implementation callback is applied and this active report artifact is awaiting supervisor Gate 2 review. `execute_report` and all lifecycle/archive commands remain supervisor-only and were not run.

## Heuristic / Inference Reanalysis And Validation

- Source-shape issue: `0x0041a280` is a real `.text` function and the only current startup-table route for wide dispatch setup. Current MCP `lookup_funcs` reports `sub_41A280`, size `0x228` / `552` (Verified with MCP `int_convert`), while `xrefs_to 0x0041a280` reports a single data xref at `0x0060d71c`.
- Wrapper-vs-source-body issue: the function contains compiler/security-cookie prologue/epilogue and registers `sub_60C440` through `_atexit`. That makes the exact binary function a compiler startup/static-lifetime wrapper around source-level PlatformApi initialization behavior, not a standalone source helper that should be hand-written with explicit `atexit` code.
- Static-object validation: [UID:0000FE] and [UID:00028B] now emit the class declaration and `static UniAPIInit s_uniAPIInit;`. Current MCP session `ba171fe4` reconfirms `0x0060c440` decompiles to only `off_6702C4 = &UniAPIInit::vftable`, `0x005997e0` only writes the vtable through `this`, and `0x00599a10` is scalar deleting destructor glue. These are generated from the class/static-object source shape.
- Dispatch-table source style: [UID:0000TQ] and child table pages correctly prefer grouped PlatformApi file-scope `g_pfn*` function-pointer globals over raw `dword_69BE*`, consumer-local declarations, or a forced runtime struct. Exact typedef/global spelling remains the remaining source-polish blocker for a complete formal constructor/helper body.
- Generated/raw projection reanalysis: current MCP `lookup_funcs` and `xrefs_to` still find no modeled function or xref route at `0x005995b0` or `0x005997f0`. B014's projection classification remains valid and should be preserved as negative evidence: those spans mirror dispatch setup but are not the live startup route.
- Rejected stale assumptions: stale Wave/Wave-generated `~UniAPIInit` or browser/transport callback interpretations do not drive this recommendation. `0x0069bec4` remains `SendMessageW`, and consumer refs do not transfer ownership away from PlatformApi.

## Evidence Standards Used

- Direct IDA MCP facts are treated as highest-weight evidence for function boundaries, decompilation, disassembly, xrefs, bytes, support helper bodies, and active session state. The active-session facts in this repaired report are from `ba171fe4`; any `cbc24146` mention is historical only.
- Current by-* docs are treated as durable project context only when their claims agree with current MCP or preserve earlier accepted IDA/PE evidence.
- Generated reports and generated C++ are treated as state evidence for current routing and emission, not as authority for source names.
- Old B reports are lead material only; useful B014/B007 conclusions were rechecked against current target/support docs and current MCP where they affect UID0000WD.
- Numeric conversions cited from `0x228`, `0x94`, and `0x98` were verified through MCP `int_convert` on `ba171fe4`; pre-repair/stale schema attempts were not used as evidence, and the current `0x98` conversion was rerun successfully with `size:2`.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `callees`, `basic_blocks`, `disasm`, `xrefs_to`, `get_bytes`, `decompile`, and `int_convert` on active session `ba171fe4`.
  - `lookup_funcs`: `0x0041a280` is `sub_41A280`, size `0x228`; `0x0041a4a8` is not a function; `0x0041a4b0` is next function `sub_41A4B0`, size `0x1d` / `29` (Verified with MCP `int_convert`); `0x005995b0` and `0x005997f0` are not functions; `0x005997e0`, `0x00599a10`, and `0x0060c440` are modeled support functions.
  - `analyze_function 0x0041a280`: size `552`, no ordinary callers, one data xref to `0x0060d71c`, callees `GetVersionExA`, `_atexit`, and security-cookie check, three basic blocks, decompilation with `OSVERSIONINFOA`, `dwPlatformId == 2`, full NT wide dispatch writes, and `_atexit(sub_60C440)`.
  - `disasm 0x0041a280`: 107 instructions; stack frame includes `VersionInformation` size `0x94` / `148` and stack allocation `0x98` / `152` (both Verified with MCP `int_convert`); writes begin at `0x0041a2b1` and tail registers `sub_60C440` at `0x0041a48d`.
  - `xrefs_to`: `0x0041a280` has only `0x0060d71c`; `0x0060c440` has only `0x0041a48d` inside `sub_41A280`; `0x005995b0` and `0x005997f0` have no xrefs; `0x00599a10` is only reached through vtable data `0x0062e57c`.
  - `get_bytes`: `0x0041a280` and projection starts `0x005995b0`/`0x005997f0` share the same `55 8b ec 81 ec 98 ...` prologue pattern; `0x0041a4a8` is eight `0xcc` bytes; `0x0060d71c` contains `80 a2 41 00 b0 a4 41 00`, matching startup entries for `0x0041a280` and next `0x0041a4b0`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target and support docs listed under `Current Target State`.
  - `auto-generated/-ag-research-tracker.md` row for `0000WD` under by-memory not-covered reconstructable.
  - `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/platform/PlatformApi.cpp` for generated route/code state.
  - Executed B014 `0001KE-UniAPIInit-source-quality.md` and executed B007 `0000FE-UniAPIInit-class-source-quality.md` as matching report leads.
- Negative checks performed:
  - No ordinary callers to `0x0041a280`; no modeled function at `0x0041a4a8`; no xrefs/functions for raw projection starts `0x005995b0` and `0x005997f0`.
  - Consumer modules read/call table entries but do not write the dispatch table or register cleanup.
  - No evidence for browser/socket/input/file-I/O ownership of the initializer or table storage.
- Failed, unavailable, or intentionally skipped checks and why:
  - No MCP availability failure occurred during the repair pass. Some initial retries used stale pre-restart argument names (`address` instead of `addr`, singular address fields instead of `addrs`, and singular byte-region fields instead of `regions`); `tools/list` was rechecked and all cited MCP evidence was rerun successfully with the active `ba171fe4` schema. One `int_convert` retry for `0x98` required explicit `size:2` and then returned `152`.
  - The report-only draft ran no validators. During the approved implementation callback, the target scoped validator passed as recorded in `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | `0x0041a280-0x0041a4a8` is the exact modeled initializer function, size `0x228` / `552`, ending before padding and next wrapper `0x0041a4b0`. | Strong | Current MCP `lookup_funcs`, `disasm`, `get_bytes`, `basic_blocks`, `int_convert`. | Target `IDA MCP Evidence` / boundary notes | incorporate | applied |
| C002 | The only live route to the target is startup-table data `0x0060d71c -> 0x0041a280`; there are no ordinary callers. | Strong | Current MCP `xrefs_to 0x0041a280`, `analyze_function`, startup-table bytes. | Target evidence and source-shape notes | incorporate | applied |
| C003 | The body initializes `OSVERSIONINFOA`, calls `GetVersionExA`, always installs `ReadUtf16CodeUnitFromFile` at `0x0069be1c`, conditionally writes NT wide API slots, then registers `0x0060c440` through `_atexit`. | Strong | Current MCP decompile/disasm; target and table docs agree. | Target behavior/evidence | incorporate | applied |
| C004 | Representative dispatch slots have broad consumer xrefs: `_wfopen` slot 41, `_wstat64i32` 5, reader slot 11, `CreateFileW` 27, `CreateEventW` 12, `GlobalGetAtomNameW` 4, `PeekMessageW` 8, `SendMessageW` 17, tail slots 4 each. | Strong | Current MCP `xrefs_to` summary for slots `0x0069be14`, `0x0069be18`, `0x0069be1c`, `0x0069be34`, `0x0069be3c`, `0x0069be80`, `0x0069be8c`, `0x0069bec4`, `0x0069bec8`, `0x0069becc`. | Target evidence; support docs already have same-or-greater consumer detail | incorporate | applied |
| C005 | PlatformApi [UID:0000ML] remains the correct canonical owner/emitter; consumers and table/global docs are support evidence, not direct owner replacements. | Strong | Current by-file/table/class docs plus MCP xrefs/writes. | Target ownership/source-placement | incorporate | applied |
| C006 | Formal target C++ should stay blank for this page because exact binary wrapper includes compiler/static-lifetime startup machinery; source-authored behavior should be represented as `UniAPIInit` constructor/private helper only after complete table declarations are accepted. | Medium-high | Current MCP `_atexit` tail, support decompilations, generated output state, table docs' typedef caveat. | Target `Reconstruction Notes` / C++ section | incorporate | applied |
| C007 | Raw `0x005995b0` and `0x005997f0` projection spans remain no-route evidence and must not receive source ownership or duplicate initializer C++. | Strong | Current MCP `lookup_funcs`/`xrefs_to`; B014 support docs already incorporated. | Target rejected alternatives / cross-reference note | incorporate | applied |
| C008 | Current generated output emits the class declaration, UTF-16 reader/helper code, and static object, but leaves UID0000WD as an empty emitter marker. | Strong | Read-only generated `auto-generated/NexusTK/platform/PlatformApi.cpp`. | Target current-state/generated-output note | incorporate | applied |
| C009 | Implemented metadata after callback is `87/91`, owner/emitter unchanged, reconstructable true, C++ blank. | Medium-high | Fresh MCP validation closes current-IDB staleness without resolving final typedef/global body. | Target metadata/change log | incorporate | applied |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - Current MCP confirms `sub_41A280` is a real `.text` function, size `0x228` / `552`, with exactly one startup-table data xref and no ordinary callers.
  - The decompilation and disassembly show the exact PlatformApi dispatch assignment sequence, including `ReadUtf16CodeUnitFromFile`, `_wfopen`, `_wstat64i32`, `GlobalGetAtomNameW`, `PeekMessageW`, `SendMessageW`, `GetLocaleInfoW`, and `SetFileAttributesW`.
  - The tail `push offset sub_60C440; call _atexit` connects the initializer to `UniAPIInit` static cleanup wrapper evidence.
- Corroborating documentation/generated-report evidence:
  - [UID:0000ML], [UID:0000FE], [UID:0000TQ], [UID:000249], [UID:00028B], and table child pages already agree that PlatformApi owns the source family, grouped dispatch globals, helper island, class declaration, and file-local static object.
  - Generated PlatformApi output already emits the class/static-object/helper pieces but leaves UID0000WD empty, matching the current no-code wrapper recommendation.
- Strongest inference chain and why it is sufficient:
  - Startup-table route plus global slot writes plus broad consumer xrefs prove centralized PlatformApi dispatch initialization. The `atexit` tail and static cleanup wrapper prove compiler/static-lifetime shape. Together, they support PlatformApi ownership and no handwritten wrapper C++ while keeping the source-authored initialization behavior tied to the `UniAPIInit` constructor/helper model.

## IDA MCP Facts

- Current session and health facts:
  - Current accepted session for this report revision is `ba171fe4`. `idb_list` reports one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `12196`.
  - `server_health(database=ba171fe4)` reports status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with `2067` strings.
  - Historical predecessor session `cbc24146` is not current after the MCP incident/restart and is retained only as provenance for the original draft evidence. The bounded function, xref, byte, decompile, and conversion facts below were refreshed on `ba171fe4` and did not change the recommendation.
- Function/range facts:
  - `0x0041a280`: `sub_41A280`, size `0x228` / `552` (Verified with MCP `int_convert`), three basic blocks, 107 instructions.
  - `0x0041a4a8`: not a function; current bytes are `0xcc` padding.
  - `0x0041a4b0`: next modeled startup wrapper `sub_41A4B0`, size `0x1d` / `29` (Verified with MCP `int_convert`).
- Data/table/padding facts:
  - `0x0060d71c` bytes are `80 a2 41 00 b0 a4 41 00`, matching startup-table entries for `0x0041a280` then `0x0041a4b0`.
  - `0x0060c440` bytes are `c7 05 c4 02 67 00 7c e5 62 00 c3`, followed by `0xcc` padding.
- Xref facts:
  - `xrefs_to 0x0041a280`: one data xref at `0x0060d71c`.
  - `xrefs_to 0x0060c440`: one data xref at `0x0041a48d` inside `sub_41A280`.
  - `xrefs_to 0x005995b0` and `0x005997f0`: no xrefs.
  - `xrefs_to 0x00599a10`: one data xref at `0x0062e57c`.
- Vtable/global/type facts:
  - `decompile 0x0060c440`: writes `off_6702C4 = &UniAPIInit::vftable`.
  - `decompile 0x005997e0`: writes `*this = &UniAPIInit::vftable`.
  - `decompile 0x00599a10`: scalar deleting destructor-style body writes the vtable and conditionally frees.
- Negative IDA facts:
  - No current MCP evidence supports moving this target to consumer modules or emitting the stale raw projection spans as final source.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041a280-0x0041a4a8` | [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` | live startup dynamic initializer / inlined dispatch setup | TRUE | [UID:0000ML] PlatformApi | implemented `87/91` | evidence updated, C++ blank preserved |
| `0x0069be14-0x0069bec4` | [UID:0002AS] `WideApiDispatchPointerTable` | main dispatch pointer storage | TRUE | [UID:0000TQ] WideApiDispatchTable | `87/87` | already supports table-style source declarations |
| `0x0069bec4-0x0069bec8` | [UID:0001Q1] `g_browserControlKeyCallback` stale-name page | `SendMessageW` slot | TRUE | [UID:0000TQ] / PlatformApi | `88/90` | already preserves stale-alias correction |
| `0x0069bec8-0x0069bed0` | [UID:0002A6] `WideApiDispatchTailPointers` | `GetLocaleInfoW` and `SetFileAttributesW` slots | TRUE | [UID:0000TQ] WideApiDispatchTable | `88/88` | already supports table-style source declarations |
| `0x0060c440-0x0060c44b` | [UID:0001O9] `UniAPIInitStaticCleanupWrapper` | compiler/static cleanup wrapper | FALSE | none | `86/91` | no-code support evidence |
| `0x006702c4-0x006702c8` | [UID:00028B] `UniAPIInitVtablePointerSlot` | static object storage | TRUE | [UID:0000ML] PlatformApi | `86/90` | already emits `static UniAPIInit s_uniAPIInit;` |
| `0x005995b0-0x00599a34` | [UID:0001KE] `UniAPIInit` raw aggregate | retained projections and ABI support | TRUE caveat | [UID:0000ML] PlatformApi | `87/89` | no-code projection evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0060d71c -> 0x0041a280` | startup-table data xref | live process startup route for dispatch initialization |
| `0x0041a2a4` | call `GetVersionExA` | probes platform family before wide dispatch writes |
| `0x0041a2b1 -> 0x0069be1c` | writes `ReadUtf16CodeUnitFromFile` | fallback reader installed unconditionally after version check call |
| `0x0041a2c1-0x0041a488` | NT branch slot writes | installs wide Win32/CRT API entry points on `dwPlatformId == 2` |
| `0x0041a48d -> 0x0060c440` | pushes cleanup wrapper before `_atexit` | static-lifetime cleanup registration, not handwritten source function ownership |
| `0x0069be14` | 41 xrefs | broad `_wfopen` dispatch consumers plus initializer/projection refs |
| `0x0069be18` | 5 xrefs | `_wstat64i32` consumers plus initializer/projection refs |
| `0x0069be34` | 27 xrefs | `CreateFileW` dispatch consumers plus initializer refs |
| `0x0069bec4` | 17 xrefs | `SendMessageW` dispatch consumers plus projection refs |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000ML] already places PlatformApi under `NexusTK/platform/`, with `UniAPIInit`, dispatch globals, string conversion helpers, and platform/OLE support.
  - [UID:0000FE] already emits `class UniAPIInit { public: UniAPIInit(); virtual ~UniAPIInit(); };`.
  - [UID:00028B] already emits `static UniAPIInit s_uniAPIInit;`.
  - [UID:000249] already emits `ReadUtf16CodeUnitFromFile(FILE *)`, the `0x0069be1c` target.
  - [UID:0000TQ] and child table pages already preserve the grouped file-scope dispatch-global declaration style.
- Existing docs that are stale, incomplete, or contradicted:
  - Target [UID:0000WD] currently contains earlier MCP evidence through several support syncs but lacks the 2026-07-04 MCP session evidence and generated-output state.
  - The target's formal C++ block is correctly blank, but the page should carry a stronger target-specific no-code proof so the empty emitter marker is intentional rather than a silent gap.
- Generated/coverage report state:
  - `auto-generated/-ag-research-tracker.md` lists UID0000WD as not-covered reconstructable with no report paths.
  - `auto-generated/-ag-memory-coverage.md` routes UID0000WD through [UID:0000ML] to `auto-generated/NexusTK/platform/PlatformApi.cpp`.
  - `auto-generated/-ag-coverage-report-by-memory.md` shows `emits_code:false` for UID0000WD.

## Ranked Ownership Analysis

### 1. [UID:0000ML] PlatformApi file

- Evidence for:
  - Source placement already exists as `NexusTK/platform/PlatformApi.cpp`.
  - The function initializes platform-wide Windows/CRT dispatch entries, not feature-local state.
  - The source family already includes `UniAPIInit`, `WideApiDispatchTable`, `ReadUtf16CodeUnitFromFile`, and static object storage.
  - Broad consumers across file I/O, browser/thread/message, registry/startup parser, input/IME, timer/event, screenshot/profile, and locale/file-attribute code are dependency evidence only.
- Evidence against:
  - The source-authored body may have been written as `UniAPIInit::UniAPIInit()` rather than as a file-local free helper, but the exact binary target is a startup-table wrapper with no `this` parameter and explicit static cleanup registration.
- Decision: accepted. Keep `CANONICAL_OWNER:0000ML` and `EMITTER_UIDS:0000ML`.

### 2. [UID:0000FE] UniAPIInit class

- Evidence for:
  - The static object/class declaration explains the cleanup wrapper, vtable data, scalar deleting destructor, and current generated output.
  - A source constructor or constructor-called helper is the best source-level explanation for the dispatch setup.
- Evidence against:
  - The exact `0x0041a280` function is a startup dynamic initializer wrapper, not a modeled `thiscall` constructor. It has no ordinary callers and registers cleanup directly.
  - The dispatch table storage is file/global state, not a class member table.
- Decision: support/source-shape owner only. Do not change target canonical owner from PlatformApi file to class.

### 3. [UID:0000TQ] WideApiDispatchTable global

- Evidence for:
  - The global table owns the contiguous dispatch-pointer storage and source declaration style.
  - The target's main behavior is writing that table.
- Evidence against:
  - The target is executable startup initialization logic, not table storage itself.
  - [UID:0000TQ] is a child/global under PlatformApi and should not own the wrapper/source-route page directly.
- Decision: support doc and storage owner. Do not use as target canonical owner.

### 4. Consumer files/classes

- Evidence for:
  - Many consumers call through individual dispatch entries.
- Evidence against:
  - Consumers do not initialize the table, do not register cleanup, and usually touch only one or a few entries.
  - Current slot xref counts prove broad shared use rather than local ownership.
- Decision: rejected for ownership. Preserve as consumer evidence only.

## Source Placement

- Recommended source file/class/global/module placement: keep UID0000WD in `platform/PlatformApi.cpp` source family. Source-authored semantics should be represented as `UniAPIInit::UniAPIInit()` or a private PlatformApi helper such as `InstallWideApiDispatchTable()` called by the file-local static object, but the by-memory page itself should document the binary startup wrapper and keep formal C++ blank until a complete table-declaration/body implementation is accepted.
- Why this placement fits source-tree and subsystem context: the initializer is platform compatibility code for Windows API dispatch and ANSI/Unicode fallback. It is used across many unrelated subsystems, which is exactly the shape of a central platform layer.
- Rejected placements and why: `StdioFile`, `PathUtil`, `Browser`, `InputMan`, `Application`, registry parser, timer/thread, and screenshot/profile modules are consumer contexts only; they neither own the dispatch table nor control startup lifetime.
- Remaining placement uncertainty, if any: exact original source spelling and factoring are inferred. This affects final C++ style, not owner/emitter routing.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - `0x0041a280-0x0041a4a8` is one modeled function with exact end `0x0041a4a8`.
  - `0x0041a4a8` begins padding; current `get_bytes` read eight `0xcc` bytes there.
  - `0x0041a4b0` is the next modeled startup constructor wrapper.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - No split is recommended for UID0000WD. The target is already exact and internally coherent: version probe, table writes, cleanup registration.
  - Related table storage is already split into [UID:0002AS], [UID:0001Q1], and [UID:0002A6].
- Padding/table/data/code distinctions:
  - The target is code. `0x0060d71c` is startup table data; dispatch entries `0x0069be14-0x0069bed0` are source-declared/generated-binary writable global storage; `0x0060c440` is compiler/static-lifetime cleanup glue.
- Parent/container impact:
  - No parent split or coverage repair is required. The target should receive a source-quality evidence refresh, not a new child-page split.

## Negative Evidence Summary

- `0x0041a280` has no ordinary call-site owner; its single route is startup table data, so ordinary caller ownership cannot be inferred.
- `0x005995b0` and `0x005997f0` have no current modeled functions or xrefs, so they remain projection evidence and should not receive target C++ or ownership.
- Consumer xrefs to dispatch slots are widespread and cross subsystem boundaries. They prove dependency usage, not storage or initializer ownership.
- The `_atexit(sub_60C440)` tail is compiler/static-lifetime output. Hand-writing that tail in final C++ would preserve binary scaffolding rather than plausible source.
- A forced runtime `struct WideApiDispatchTable` remains weaker than grouped file-scope function-pointer globals because current code uses direct absolute slot references rather than base/index access.

## First-Draft C++ Recommendation

- Eligible for draft C++: minimum metadata/emitter gate is satisfied, but target-specific source-shape safety still blocks formal target C++.
- Recommended code: keep UID0000WD formal `RECONSTRUCTION_CPP CODE` blank for this implementation. Do not insert a body-only sample in this report.
- Reason it preserves exact original behavior:
  - The current generated source already emits the static object, class declaration, and reader helper. The missing dispatch-body source is real work, but this exact by-memory range includes compiler startup wrapper behavior that should not be hand-written.
  - A behavior-preserving final implementation should add a complete `UniAPIInit::UniAPIInit()` or private helper body only when the table's file-scope globals/typedefs and all slot names are accepted as formal source declarations.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape:
  - Source likely declared a file-local static `UniAPIInit` object and ordinary function-pointer globals, not a manually named startup wrapper that calls `_atexit`.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels:
  - Use `UniAPIInit`, `s_uniAPIInit`, `ReadUtf16CodeUnitFromFile`, `g_pfnWideOpenFile`, `g_pfnWideStat`, `g_pfnGlobalGetAtomNameW`, `g_pfnPeekMessage`, `g_pfnSendMessageW`, and grouped `g_pfn*` PlatformApi names where already accepted by table docs.
- Naming/coding style convention used and evidence for consistency:
  - Current project output uses `static UniAPIInit s_uniAPIInit;` and PlatformApi static helper naming. Preserve that style rather than raw `unk_69BE*`/`dword_69BE*`.
- Reason code should remain blank, if applicable:
  - This exact function is a compiler/startup dynamic initializer with security-cookie and `_atexit` mechanics.
  - The accepted source-authored pieces are split across class/static object/helper/table docs, and the final complete dispatch assignment body still depends on table declaration/typedef polish.
  - Partial formal C++ here would either omit many slots or use unstable raw/descriptive names, making generated output look more complete than it is.
- Exact no-code proof, if not eligible:
  - Current MCP proves the live route is startup table `0x0060d71c -> 0x0041a280`, the tail registers generated cleanup wrapper `0x0060c440`, and no route reaches the raw projection starts `0x005995b0`/`0x005997f0`.
  - Current generated output already emits `UniAPIInit` declaration and `static UniAPIInit s_uniAPIInit`, so an empty UID0000WD block is currently a deliberate "do not hand-port wrapper" decision, not a missing owner/emitter failure.

## Final Recommendation

- Exact changes recommended:
  - Applied only UID0000WD target by-memory page by default; no support docs were required or edited.
  - Added a B015 MCP refresh section with active session `ba171fe4`, function/boundary facts, xref facts, slot xref counts, bytes, and current generated-output state. The predecessor session `cbc24146` is historical-only after the MCP incident/restart.
  - Added target-specific no-code proof and C++ readiness explanation.
  - Updated metadata to `COMPLETION:87`, `CONFIDENCE:91`; owner, emitter, reconstructable, and C++ block remained unchanged.
- Exact parent assignments recommended:
  - Keep `CANONICAL_OWNER:0000ML`.
  - Keep `EMITTER_UIDS:0000ML`.
- Exact items left no-owner/non-emitting and why:
  - None for UID0000WD. The target remains owned/emitting through PlatformApi even with blank formal code.
- Exact future work outside this assignment scope:
  - A later implementation or PlatformApi-wide pass can add a complete constructor/helper body only after [UID:0000TQ] dispatch declarations and slot typedef/global names are finalized for formal C++.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`.
- Exact report facts to incorporate:
  - Current MCP session `ba171fe4` and health state, with any `cbc24146` note labeled historical-only.
  - Exact function/boundary/bytes/basic-block/decompilation facts listed in `IDA MCP Facts`.
  - Xref and slot-consumer summary listed in `Direct Xref / Caller Inventory`.
  - Current generated output state: class/helper/static object emitted, UID0000WD empty marker.
  - Target-specific no-code proof and source-placement explanation.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION:85` to `COMPLETION:87`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:91`.
  - Leave `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ML`, `EMITTER_POSITION_OPTIONAL:` unchanged.
  - Leave formal `RECONSTRUCTION_CPP CODE` header and block blank.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve raw projection/no-route evidence for `0x005995b0` and `0x005997f0`.
  - Preserve rejection of consumer ownership and `SendMessageW` stale alias.
  - Preserve rejection of hand-written `_atexit` wrapper code.

## Recommended Support Doc Changes

- Support path: no required support-doc edit for the default callback.
- Exact report facts to incorporate: not applicable by default because [UID:0000ML], [UID:0000FE], [UID:0000TQ], [UID:000249], [UID:00028B], [UID:0001KE], [UID:0001O9], [UID:0002AS], and [UID:0002A6] already contain the same-or-greater support facts needed for this target recommendation.
- Metadata/link/score/coverage/source-placement changes: none required. If the supervisor chooses optional support sync, add only a concise cross-note to [UID:0000TQ] that B015 current MCP reconfirmed the slot xref counts and UID0000WD empty-marker/no-code blocker; no score change is needed.

## Score And Metadata Recommendation

- Pre-callback score/metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ML`, blank C++.
- Implemented score/metadata: `COMPLETION:87`, `CONFIDENCE:91`, same owner/emitter/reconstructable/C++ state.
- Score rationale and reason not higher/lower:
  - Completion rises because the target now has current-session MCP evidence, generated-output state, C++/no-code proof, xref counts, and a final source-placement decision under the current report template.
  - Confidence rises because current MCP session `ba171fe4` directly confirms earlier documented facts, including boundary, route, slot writes, and negative projection status.
  - The Gate 1 repair changes only current-session provenance: session `ba171fe4` reconfirmed the prior facts, so the recommended `87/91` score remains unchanged.
  - Completion should not rise higher because final formal dispatch initialization C++ remains deferred and exact dispatch typedef/global spellings are still not final-source complete.
  - Confidence should not rise above `91` because exact original source factoring and many exact original symbol spellings remain inferred.
- Score-improvement attempt:
  - Current-IDB freshness blocker: resolved by `server_health(database=ba171fe4)` plus function/decompilation/disassembly/xref/byte checks on active MCP session `ba171fe4`.
  - C++ blocker: resolved to a target-specific no-code proof for this exact wrapper, with a future implementation-ready condition for constructor/helper code.
  - Owner/emitter blocker: resolved unchanged as PlatformApi because startup route and broad table consumers reject alternatives.
  - Split/range blocker: resolved unchanged because MCP confirms exact function end and neighboring padding/next wrapper.
- Metadata fields to change or leave unchanged:
  - Changed only completion/confidence.
  - Leave owner/emitter/reconstructable/C++ block unchanged.

## Open Questions With Attempted Resolution

- Open question: Should UID0000WD receive formal C++ now?
  - Evidence checked: current MCP wrapper tail, current generated PlatformApi output, `UniAPIInit` class/static object pages, WideApiDispatchTable source style, raw projection no-route evidence.
  - Best supported resolution: no. Keep the formal block blank for this target until a complete dispatch-table declaration/body implementation is accepted. Do not hand-write the compiler startup wrapper.
  - Score/C++ impact: completion remains below 90; C++ remains empty by proof, not by missing owner.
- Open question: Should canonical owner move to [UID:0000FE] `UniAPIInit`?
  - Evidence checked: startup-table route, no ordinary callers, no `this` parameter in `0x0041a280`, class/static object docs, cleanup wrapper evidence.
  - Best supported resolution: no. `UniAPIInit` is the source-shape class, but the exact binary target is the PlatformApi startup initializer/wrapper and should stay with file owner [UID:0000ML].
  - Score/C++ impact: owner/emitter unchanged.
- Open question: Does any consumer module own the table or initializer?
  - Evidence checked: broad slot xrefs and current table docs.
  - Best supported resolution: no. Consumers read/call entries only.
  - Score/C++ impact: rejected alternatives preserve confidence in PlatformApi ownership.
- Remaining unresolved issue: exact original spelling of every dispatch pointer typedef/global and exact constructor-vs-helper factoring.
  - Exhaustive current evidence proving why no final answer is safe now: table docs still mark typedef naming as the remaining refinement, no symbols prove final names, and emitted PlatformApi currently lacks accepted declarations/body for the dispatch setup.
  - Future evidence required: accepted PlatformApi dispatch declaration convention or a broader implementation callback that updates [UID:0000TQ] and UID0000WD together.

## Validator Results

- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md --apply --queue-timeout 240`
- Result:
  - Exit code: `0`.
  - `command_id: 000000006622`.
  - `command_timestamp: 2026-07-04T21:00:51-04:00`.
  - `ok: 1`; scanned markdown files: `1`.
  - `completion_update: 1` for UID0000WD to `87`.
  - `confidence_update: 1` for UID0000WD to `91`.
  - `projected_stats_update: 1`; validator reported `project-level/-auto-completion-stats.md` projected path completion section updated.
  - `generated_refresh: deferred`, `generated_refresh_command_id: 000000006622`, `generated_refresh_timestamp: 2026-07-04T21:00:51-04:00`.
- Any unresolved validator warnings/errors:
  - None observed for the target; scoped validator returned `ok: 1`.
  - `--wait-generated` was not used because this callback preserves a blank UID0000WD C++ block and does not depend on refreshed generated PlatformApi output for the implementation claim.
- Leases:
  - B015 leased `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` at `2026-07-05T00:59:30Z` with expiration `2026-07-05T01:04:30Z`, ran the edit/validator batch under that lease, released it immediately afterward, and rechecked `tools/leaser/Agents/current_leases.md`; it reported no active leases.

## Changed Files

- Created during callback:
  - None.
- Modified during callback:
  - `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`: applied metadata `87/91`, current `ba171fe4` MCP evidence, exact boundary/xref/byte/decompilation facts, representative slot xref counts, no-code proof, and rejected alternatives.
  - `tools/leaser/Agents/Agent-B015/research/0000WD-WideApiDispatchInit-source-quality.md`: updated current-state text, Claim And Incorporation Ledger, Validator Results, Changed Files, and Implementation Tracking Checklist for Gate 2 review.
- Validator-owned generated side effect:
  - `project-level/-auto-completion-stats.md` projected path completion section was updated by validator command `000000006622`; this was validator output, not a manual edit.
- Renamed:
  - None.
- Report execution: not run. B agents must not run `execute_report`, dry-run/probing execute variants, report lifecycle/archive commands, manual report moves, or equivalent report execution/archive commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: Gate 1 passed and callback was issued by the supervisor.
- [x] Target/support docs to update: updated `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`; no support-doc edit was required because support docs already contained same-or-greater source-shape facts and no new stale support issue was found.
- [x] Current target state and actual evidence checked recorded: incorporated MCP session `ba171fe4`, health, lookup, analyze/decompile/disasm, xrefs, bytes, int conversions, generated-output state, and prior report search terms; `cbc24146` appears only as historical predecessor-session provenance.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: claims C001-C009 now record `applied`.
- [x] Metadata/score changes to apply: changed UID0000WD from `85/90` to `87/91`; owner/emitter/reconstructable/C++ remained unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof: C++ blocker is documented as a target-specific no-code proof; exact typedef/body work remains deferred to a future PlatformApi dispatch implementation condition.
- [x] Owner/emitter/reconstructable changes to apply: none; preserved `0000ML` owner/emitter and `RECONSTRUCTABLE:TRUE`.
- [x] Split/rename/new-child changes to apply: none; target range and next-wrapper boundary were documented without file split or rename.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: added PlatformApi source-placement/no-code proof; no IDA DB edits requested or made.
- [x] First-draft C++ or no-code proof to apply: formal C++ block remains blank and the exact no-code proof from `First-Draft C++ Recommendation` was added to the target.
- [x] Third-party import directive to apply or confirm not applicable: not applicable; this is NexusTK PlatformApi source, not third-party static import.
- [x] Exact target/support doc facts to incorporate at report-level detail: incorporated facts in `Recommended Target Doc Changes` and claims C001-C009 into the target; no support edit needed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserved raw `0x005995b0`/`0x005997f0` projection no-route evidence, rejected consumer ownership, rejected forced struct, rejected handwritten `_atexit` wrapper, stale `SendMessageW` alias correction, and unsupported source-body emission now.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: historical generated `~UniAPIInit`/projection caveat remains only as stale provenance and was not used as source ownership proof.
- [x] Open questions to close or document as evidence-backed unresolved: owner/range/C++ wrapper questions closed as above; exact typedef/global spelling and constructor-vs-helper factoring remain nonblocking source-polish uncertainties.
- [x] Validators to run: scoped target validator command `000000006622` passed with `ok: 1`; no support scoped validators were needed because no support docs were edited.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual coverage/tracker text; validator reported `generated_refresh: deferred` and a validator-owned projected stats update. Generated PlatformApi output freshness was not required because UID0000WD formal C++ remains blank.

Implementation callback pass, authorized and applied:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail; support docs were excluded as already same-or-greater/not required by default.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh state recorded; no manual supervisor-owned coverage/tracker text supplied because none was required.
- [x] Remaining unapplied accepted items listed with exact blocker: none; no accepted implementation item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000006634","destination_path":"executed-b-agent-research/B015/0000WD-WideApiDispatchInit-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/0000WD-WideApiDispatchInit-source-quality.md","timestamp":"2026-07-04T21:09:43-04:00","uid":"0000WD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
