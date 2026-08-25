** TARGET-REPORT-UID:0000W8 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID0000W8 InitializeOleSupport Source-Quality Report

## Finalized Report / Current Recommendation

UID0000W8 is now implemented as exact, high-confidence AutoInit/OLE startup evidence, but not as a standalone source function that emits C++ under the `InitializeOleSupport` by-memory page. The current target doc classifies `0x00419ee0-0x00419ef4` as a compiler/static-lifetime startup-table helper: it calls `OleInitialize(0)` and registers the paired `0x0060c0f0` cleanup thunk with `_atexit`. The source-level policy belongs to the AutoInit static lifetime object under [UID:0000HN] `by-file/AutoInit.md` / [UID:00000Q] `by-class/AutoInit.md`; the exact startup helper body is documented as compiler-generated glue caused by that source declaration.

Implemented callback disposition:

- Target `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md` is now `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000HN`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.
- Target prose now says no direct source-call route reaches UID0000W8; the only route is `.rdata` startup table entry `0x0060d6a4`; generated `auto-generated/NexusTK/platform/AutoInit.cpp` no longer contains a UID0000W8 empty marker after validator refresh.
- Support docs now preserve the AutoInit source policy: the source should declare a tiny file-local/static OLE lifetime object or equivalent platform startup policy whose construction initializes OLE and whose teardown calls `OleUninitialize`. They do not introduce a callable source helper named `InitializeOleSupport`.

## Supporting Research

This artifact has completed the supervisor-authorized implementation callback for UID0000W8. I edited the accepted target/support by-* docs only, ran scoped validators for each changed by-* doc, released the edit leases, checked generated `AutoInit.cpp` freshness/no UID0000W8 marker, and stopped before supervisor-only execution. I did not edit generated files by hand, coverage reports, validator state, supervisor ledgers, lifecycle state, or archives, and I did not run `execute_report` or lifecycle/probing commands.

Current MCP evidence was collected after supervisor MCP restoration from IDA MCP session `6eab6bcb`. `idb_list` reported one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, and `strings_cache_ready: true`. All MCP calls were narrow/exact-address or filtered/paged calls under the `by-structure.md` IDA MCP Output Discipline.

Local documentation searched/read:

- Target: `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md`.
- Direct support: `by-file/AutoInit.md`, `by-class/AutoInit.md`, `by-global/InitializeOleSupport.md`, `by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md`, `by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md`, `by-type/by-vtable/AutoInitVtable.md`.
- Neighboring startup wrappers: `by-memory/0x00419e56-0x00419ee0.StaticInitializerWrappersPreOle.md` and `by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md`.
- Generated lead: `auto-generated/NexusTK/platform/AutoInit.cpp`, validator-command-id `000000006061`, refreshed `2026-07-04T04:14:42-04:00`, currently containing empty emitter markers for AutoInit family UIDs including UID0000W8.
- Search terms used against current/archived reports and docs included `0000W8`, `InitializeOleSupport`, `0x00419ee0`, `00419ee0`, `0x00419ef4`, `OleInitialize`, `OleUninitialize`, `CoInitialize`, `COM initialization`, `OLE initialization`, `AutoInit`, and source-family terms around startup/application initialization.

Historical notes found:

- A003 and C001 notes already identified `0x00419ee0` as the OLE startup helper and recorded the old blocker: behavior was known, but final `AutoInit.cpp` versus `PlatformApi.cpp` fold and source-facing static object spelling were unresolved.
- Neighbor W7/W9 static initializer wrapper pages were already reclassified as `RECONSTRUCTABLE:FALSE` compiler/static-initializer glue with blank emitters. UID0000W8 differs semantically because it anchors the AutoInit OLE policy, but the exact emitted helper still has the same startup-table-only route pattern.

## Target

- UID: `0000W8`.
- Target doc: `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md`.
- Current metadata after callback: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000HN`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank emitter position, blank formal C++.
- Current summary: startup OLE initializer table entry that calls `OleInitialize(0)`, registers the `0x0060c0f0` `OleUninitialize` thunk through `_atexit`, and anchors the static `AutoInit` lifetime policy.
- Current generated state: `auto-generated/NexusTK/platform/AutoInit.cpp` is refreshed at validator-command-id `000000006122`, timestamp `2026-07-04T05:14:49-04:00`, and no longer contains `UID:0000W8` or a UID0000W8 empty marker.
- Implemented disposition: keep the owner/source-policy link to AutoInit but classify the exact helper body as non-reconstructable compiler/static-lifetime glue, clear the emitter, and leave formal C++ blank.

## Current Target State

The target now has strong behavior documentation and the corrected non-emitting source route. Current docs say the function:

- starts at `0x00419ee0` and ends at `0x00419ef4`;
- calls `OleInitialize(0)`;
- pushes the `0x0060c0f0` shutdown thunk;
- calls `_atexit`;
- is referenced by startup initializer table entry `0x0060d6a4`;
- is source-related to [UID:0000HN] `AutoInit`, [UID:00000Q] `AutoInit`, the one-slot vtable at `0x0061373c`, and the static object vptr slot at `0x0066d42c`.

The stale standalone-emitter implication has been removed. Current MCP shows no ordinary callers, one startup-table data xref, and paired cleanup glue that is already non-reconstructable. Current generated output confirms the result: the AutoInit generated file no longer contains a UID0000W8 marker.

## Heuristic / Inference Reanalysis And Validation

The important reanalysis is source route versus binary behavior. The binary behavior is not in doubt; the source-shape question is whether the rebuilt project should contain a handwritten `InitializeOleSupport()` function or a file-local/static AutoInit object whose compiler-generated dynamic initializer produces this exact startup helper.

Evidence supporting generated startup glue:

- MCP `xrefs_to 0x00419ee0` returns only data xref `0x0060d6a4`, not a code caller.
- MCP `analyze_function 0x00419ee0` reports callers `[]`, one basic block, prototype `int()`, callees `_atexit` and `OleInitialize`, and xrefs-to only from the startup table.
- Neighbor pages [UID:0000W7] and [UID:0000W9] document the surrounding startup-wrapper island as compiler/static-initializer glue, also routed only through startup-table data refs.
- The paired shutdown thunk [UID:0001O6] is already `RECONSTRUCTABLE:FALSE` and source should express AutoInit/OLE lifetime policy instead of a raw cleanup function.
- The static object slot [UID:000277] and vtable [UID:0001X0] are source-declared/generated-binary support for the AutoInit object, not standalone source bodies.

Evidence supporting preserving AutoInit source semantics:

- `OleInitialize` and `OleUninitialize` are paired through the initializer and shutdown thunk.
- The shutdown thunk writes `off_66D42C = &anonymous namespace::AutoInit::vftable` and then calls `OleUninitialize`.
- Xrefs to vtable `0x0061373c` are exactly the ordinary destructor `0x0046efe0`, scalar deleting destructor store `0x00470306`, shutdown thunk `0x0060c0f0`, and static object slot `0x0066d42c`.
- `0x0066d42c` contains bytes `3c 37 61 00`, little-endian `0x0061373c`, which is the static object vptr value.

Conclusion: UID0000W8 should not be demoted to "unimportant" or detached from AutoInit. It should be reclassified from standalone reconstructable emitter to non-emitting generated startup glue with a strong source-policy owner. That resolves the empty-emitter marker without losing OLE initialization semantics.

## Evidence Standards Used

- Direct IDA MCP evidence from current session `6eab6bcb` is authoritative for function boundaries, xrefs, callees, decompile shape, imports, bytes, vtable/static-slot xrefs, and generated-helper route.
- Current by-* docs are used as documentation state and support context, not as sole proof when a current MCP check was available.
- Generated C++ is treated as lead/current-state evidence only. The current empty marker in `auto-generated/NexusTK/platform/AutoInit.cpp` is a symptom of metadata, not proof that a standalone function should exist.
- Historical A/C/B reports and notes are leads. They are cited only where current evidence agrees or where they explain why current docs carry a particular blocker.
- Numeric conversions for `0x14`/20, `0x10`/16, `0x60d6a4`/6346404, `0x0061373c`/6371132, and `0x0066d42c`/6738988 were checked with `tools/int_convert.py` and are marked where used below.

## Evidence Checked

MCP session and health:

- `idb_list`: active session `6eab6bcb`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`.
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

MCP target checks:

- `lookup_funcs` for `0x00419ee0`, `0x00419ef4`, `0x0060c0f0`, `0x0060c100`, `0x0046efe0`, `0x00470300`: `0x00419ee0` is `sub_419EE0` size `0x14`; `0x00419ef4` is not a function; `0x0060c0f0` is `sub_60C0F0` size `0x10`; `0x0060c100` is successor `sub_60C100`; the ordinary/scalar destructor bodies are `0x0046efe0` size `0x0c` and `0x00470300` size `0x2a`.
- `analyze_function 0x00419ee0`: decompiles as `OleInitialize(0); return atexit(sub_60C0F0);`, size 20 decimal / `0x14` (Verified with `int_convert.py`), no callers, callees `_atexit` and `OleInitialize`, xref-to `0x0060d6a4`.
- `disasm 0x00419ee0`, capped 12 instructions: six instructions, `push 0`, `call ds:OleInitialize`, `push offset sub_60C0F0`, `call _atexit`, `pop ecx`, `retn`.
- `decompile 0x00419ee0` with addresses disabled: same two-operation body and refs to `OleInitialize`, `_atexit`, and `sub_60C0F0`.
- `xrefs_to 0x00419ee0`: one data xref from `0x0060d6a4`.
- `xrefs_to 0x0060c0f0`: one data xref from `0x00419ee8` inside `sub_419EE0`.
- `analyze_function 0x0060c0f0`: size 16 decimal / `0x10` (Verified with `int_convert.py`), decompile writes `off_66D42C = &anonymous namespace::AutoInit::vftable; OleUninitialize();`, assembly is `mov off_66D42C, offset ??_7AutoInit@?A0xbc51848c@@6B@` then `jmp ds:OleUninitialize`.
- `imports_query`: `ole32!OleInitialize` at `0x0060d668`; `ole32!OleUninitialize` at `0x0060d650`.
- `xrefs_to 0x0060d668`: refs from `0x00419ee2` inside `sub_419EE0`.
- `xrefs_to 0x0060d650`: refs from AutoInit ordinary destructor, scalar deleting destructor, and static shutdown thunk paths.
- `get_bytes 0x00419ed0 size 48`: shows predecessor tail, `0xcc` padding before `0x00419ee0`, target bytes `6a 00 ff 15 68 d6 60 00 68 f0 c0 60 00 e8 b1 dc 1a 00 59 c3`, and `0xcc` padding after `0x00419ef4`.
- `get_bytes 0x0060d6a0 size 12`: `c0 9e 41 00 e0 9e 41 00 00 9f 41 00`, i.e. startup table neighbors `0x00419ec0`, `0x00419ee0`, `0x00419f00`.
- `get_bytes 0x0066d42c size 4`: `3c 37 61 00`, pointer to `0x0061373c`.
- `get_bytes 0x00613738 size 12`: `4c 31 64 00 00 03 47 00 5c 32 64 00`, showing RTTI pointer, `0x00470300` vtable slot, and adjacent data.

Local/generator checks:

- `auto-generated/NexusTK/platform/AutoInit.cpp` currently contains empty markers for [UID:00000Q], [UID:0001X0], [UID:0000T3], [UID:0000W8], [UID:0000ZE], [UID:0000ZG], and [UID:000277].
- `rg` across executed and active reports found no prior B013 report for UID0000W8, but found relevant A003/C001 notes and older B Browser/OLE aggregate reports confirming AutoInit should not be owned by Browser instance code.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| W8-C01 | UID0000W8 is exact range `0x00419ee0-0x00419ef4`; size is `0x14` / 20 decimal (Verified with `int_convert.py`), and `0x00419ef4` is not a function start. | 0.99 | MCP `lookup_funcs`, `analyze_function`, disasm, byte check. | Target `Scope`, `Evidence`, `Address Map`, `Score Rationale`. | incorporate | applied: target `Scope`, `Evidence`, `Address Map`, and `Score Rationale` carry exact range/size and `0x00419ef4` non-function proof. |
| W8-C02 | The body calls `OleInitialize(0)` then returns `_atexit(0x0060c0f0)`; it has one basic block, no strings, no constants requiring source names, and callees `_atexit`/`OleInitialize`. | 0.99 | MCP `analyze_function`, `decompile`, `disasm`; import query for `ole32!OleInitialize`. | Target `Behavior`, `Raw Code Evidence`. | incorporate | applied: target `Behavior`, `Address Map`, `Evidence`, and `Raw Code Evidence` document the exact call/register body and imports. |
| W8-C03 | Reachability is startup-table only: `xrefs_to 0x00419ee0` returns one data xref from `0x0060d6a4`; there are no ordinary source callers. | 0.98 | MCP `xrefs_to`, `analyze_function` callers `[]`; startup table bytes. | Target `Evidence`, `Reconstruction Notes`; support `AutoInit` file/class notes. | incorporate | applied: target `Evidence` and `Source-Shape / Reconstruction Notes`, plus `by-file/AutoInit.md` and `by-class/AutoInit.md`, record startup-table-only/no ordinary caller route. |
| W8-C04 | Startup table neighbors are `0x0060d6a0 -> 0x00419ec0`, `0x0060d6a4 -> 0x00419ee0`, `0x0060d6a8 -> 0x00419f00`; neighboring W7/W9 wrappers are compiler/static-initializer glue. | 0.97 | MCP `get_bytes 0x0060d6a0`, `lookup_funcs`, W7/W9 docs. | Target `Evidence`; support `AutoInit` boundary notes. | incorporate | applied: target `Evidence` and raw startup-table byte block include the neighbor entries; AutoInit support notes preserve this boundary context. |
| W8-C05 | The paired thunk `0x0060c0f0` is `0x10` / 16 decimal bytes (Verified with `int_convert.py`), referenced only from `0x00419ee8`, writes `off_66D42C`, and jumps to `OleUninitialize`. | 0.99 | MCP `lookup_funcs`, `xrefs_to 0x0060c0f0`, `analyze_function 0x0060c0f0`; import query for `OleUninitialize`. | Target `Evidence`; support shutdown thunk cross-reference. | already-present | already-present/applied: shutdown thunk page already had same-or-greater non-emitting proof; target now incorporates paired thunk size, xref, write, and tail jump facts. |
| W8-C06 | Vtable/static-slot chain supports AutoInit source policy: vtable `0x0061373c` is referenced from ordinary destructor, scalar deleting destructor, shutdown thunk, and static object slot; `0x0066d42c` stores `3c 37 61 00`. | 0.97 | MCP `xrefs_to 0x0061373c`, `xrefs_to 0x0066d42c`, `get_bytes`; static slot/vtable docs. | Target `Reconstruction Notes`; support `AutoInit`, `AutoInitVtable`, static object vptr docs if stale. | incorporate | applied/already-present: target and AutoInit file/class pages include the chain; static slot/vtable pages were inspected and already present at same-or-greater detail. |
| W8-C07 | Source ownership should remain AutoInit/platform OLE policy, not Browser, BrowserThread, PlatformApi alone, import data, or neighboring static-wrapper pages. | 0.90 | Process-wide startup table route, AutoInit vtable/static slot/destructor evidence, Browser docs warning against browser ownership. | Target `Cross-References`; support `by-file/AutoInit.md`, `by-class/AutoInit.md`, `by-global/InitializeOleSupport.md`. | incorporate | applied: target and support docs keep AutoInit source-policy ownership, preserve PlatformApi as fold caveat only, and reject Browser/import/static-wrapper ownership. |
| W8-C08 | Exact UID0000W8 should be non-emitting compiler/static-lifetime startup glue; formal C++ for this by-memory page should remain blank. | 0.88 | Startup-table-only xref, no ordinary caller, W7/W9/0001O6 classification, generated empty marker, source policy represented by static AutoInit object. | Target metadata and `Reconstruction Notes`; generated output after supervisor callback. | incorporate | applied: target is `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++; generated `AutoInit.cpp` no longer has UID0000W8 marker. |
| W8-C09 | Current IDA names in session `6eab6bcb` are raw `sub_419EE0`/`sub_60C0F0`; source-facing names `InitializeOleSupport` and `AutoInit_StaticShutdownThunk` are documentation/descriptive names, not current-symbol proof in this session. | 0.94 | MCP `lookup_funcs` results; current docs use descriptive names. | Target `Evidence` and naming caveat. | incorporate | applied: target `Scope` and `Source-Shape / Reconstruction Notes` record current raw MCP names and documentation/descriptive name caveat; support docs avoid relying on current-symbol proof. |
| W8-C10 | Historical pre-callback generated `AutoInit.cpp` had a UID0000W8 empty marker; after accepted non-reconstructable/blank-emitter reclassification, that marker should be absent. | 0.90 | Pre-callback local generated header was `000000006061`; post-callback generated header is `000000006122` with no UID0000W8 match. | Target `Current generated state`; implementation checklist generated freshness note. | incorporate | applied: generated `auto-generated/NexusTK/platform/AutoInit.cpp` header is `validator-command-id: 000000006122`, refreshed `2026-07-04T05:14:49-04:00`, and `Select-String` found no `0000W8`/`InitializeOleSupport` marker. |

## Positive Evidence Summary

- Exact function boundary is stable: `0x00419ee0-0x00419ef4`, size `0x14` / 20 decimal (Verified with `int_convert.py`), with `0x00419ef4` not a function.
- Behavior is exact: `OleInitialize(0)` then `_atexit(sub_60C0F0)`.
- The startup-table entry at `0x0060d6a4` is the sole direct route to the target; bytes around `0x0060d6a0` encode `0x00419ec0`, `0x00419ee0`, and `0x00419f00`.
- Paired teardown is exact: `0x0060c0f0` writes the AutoInit vtable pointer to `off_66D42C` and tail-jumps to `OleUninitialize`.
- The AutoInit vtable/static-object chain is coherent: `0x0061373c` is the one-slot vtable target chain, `0x0066d42c` stores `0x0061373c`, and destructor/shutdown xrefs all converge on the same OLE lifetime helper.
- Current docs already reject Browser-instance ownership; current evidence confirms process-wide startup support.

## Negative Evidence Summary

- No ordinary source caller reaches `0x00419ee0`; MCP callers are empty and xrefs are data-only from the startup table.
- No evidence shows a source-authored callable function named `InitializeOleSupport`; current session still reports raw function name `sub_419EE0`.
- The low-level helper body is surrounded by startup-wrapper glue pages W7/W9, both already non-reconstructable, making a standalone source-function emission inconsistent with adjacent classification.
- The paired cleanup thunk is already non-reconstructable compiler/static-lifetime glue; emitting the initializer helper but not the teardown helper would split one source-level static-object policy into artificial low-level functions.
- Browser/BrowserThread COM usage is consumer context only; it does not own the process startup table entry.
- PlatformApi is a plausible fold target for the final source file, but not enough to replace AutoInit as the current canonical policy owner.
- Import-data ownership is rejected; `OleInitialize`/`OleUninitialize` imports are dependencies, not source owners.

## Ranked Ownership Analysis

1. [UID:0000HN] `by-file/AutoInit.md` / [UID:00000Q] `by-class/AutoInit.md` as source-policy owner: strongest. The initializer, static shutdown thunk, ordinary destructor, scalar deleting destructor, vtable, and static object slot all describe one AutoInit/OLE lifetime policy. Keep `CANONICAL_OWNER:0000HN` on the target if the project wants a durable owner for the source policy, even while the exact by-memory helper is non-emitting.
2. [UID:0000ML] `PlatformApi.md` fold candidate: plausible later source-layout bucket. It may be where a real project placed generic OLE/platform initialization, but current docs do not prove a stronger direct route than AutoInit.
3. [UID:0000HV] `Browser.md` / BrowserThread/browser OLE family: rejected as owner. Browser code uses COM/OLE heavily, but the target is process startup table glue before any browser pane instance route.
4. Neighbor static initializer wrappers W7/W9: rejected as owner but important classification precedent. They prove this address neighborhood is startup-wrapper glue, not an authored feature module.
5. `by-memory/0x0060d000-0x0060d670.ImportDataSection.md`: rejected. `OleInitialize` and `OleUninitialize` imports are dependency endpoints only.
6. Unknown/no-owner: rejected as too weak. AutoInit source-policy ownership is well supported; only standalone emission is rejected.

## Source Placement

Recommended durable source placement is `NexusTK/platform/AutoInit.cpp` unless a later source-layout pass proves this OLE lifetime guard was folded into `PlatformApi.cpp`. The source-facing unit should be a tiny file-local/static OLE lifetime guard, not a callable helper exported to the rest of the project.

Source placement should preserve these distinctions:

- `AutoInit` file/class/static object: source policy and declarations.
- UID0000W8: generated startup initializer helper caused by static lifetime, no standalone source body.
- UID0001O6: generated static cleanup thunk, no standalone source body.
- UID000277 and UID0001X0: source-declared/generated-binary static object/vtable artifacts.

## First-Draft C++ Recommendation

No formal C++ should be inserted into UID0000W8's `RECONSTRUCTION_CPP CODE` block.

Reason: a standalone body such as `int InitializeOleSupport() { OleInitialize(nullptr); return atexit(...); }` would reproduce the decompiler-visible helper, but it would misrepresent the most likely source route. The function has no source-style callers, is reached only through the startup initializer table, and pairs with a cleanup thunk already classified as compiler/static-lifetime glue. The correct source-level expression is the AutoInit lifetime object or equivalent platform OLE policy in the owning source file. That broader source declaration should be handled through AutoInit class/file documentation when final object spelling is ready; UID0000W8 should stay blank and non-emitting.

This is not a behavior blocker. It is a source-shape blocker: emitting the raw helper would create a callable function route that current binary evidence does not support as handwritten source.

## Final Recommendation

Reclassify UID0000W8 from reconstructable empty-emitter helper to non-reconstructable generated startup helper with strong AutoInit ownership context:

- `COMPLETION:89`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000HN`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- formal C++ blank

Then update target/support prose so the source-policy facts are not lost: process startup initializes OLE; shutdown uninitializes OLE through the AutoInit teardown path; the source should express a static/file-local AutoInit lifetime object or equivalent platform OLE policy; the exact helper and cleanup thunk are compiler/static-lifetime artifacts.

## Recommended Target Doc Changes

For `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md`:

Implemented during callback:

- Updated metadata to the final recommendation above.
- Changed `Disposition`/`Reconstruction Notes` from standalone reconstructable startup support to non-emitting compiler/static-lifetime startup glue caused by the AutoInit source policy.
- Preserved exact behavior, raw disassembly, startup table xref, startup table neighbor bytes, paired thunk, static slot/vtable chain, and OLE import facts.
- Added current MCP session `6eab6bcb` evidence with the exact checks/results listed in this report.
- Historicalized the old generated/recovered function-body shape as behavior evidence and superseded source-emission guidance, not final source text.
- Noted that source-facing names `InitializeOleSupport` / `AutoInit_StaticShutdownThunk` are descriptive/inferred in documentation because current session lookup returns raw `sub_419EE0` and `sub_60C0F0`.
- Generated `AutoInit.cpp` was refreshed and no longer contains UID0000W8.

## Recommended Support Doc Changes

Implemented or resolved during callback:

- `by-file/AutoInit.md`: updated so UID0000W8 is AutoInit source-policy evidence but non-emitting startup glue; preserved `AutoInit.cpp` versus later `PlatformApi.cpp` fold caveat.
- `by-class/AutoInit.md`: updated method/source notes so `InitializeOleSupport` is the compiler-emitted startup initializer equivalent of construction/static lifetime, not a source-callable method/function body.
- `by-global/InitializeOleSupport.md`: updated to `86/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and name-centric/non-emitting index wording with blank C++.
- `by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md`: inspected and already present at same-or-greater detail; no edit.
- `by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md` and `by-type/by-vtable/AutoInitVtable.md`: inspected and already present at same-or-greater detail; no edit.
- Browser docs were not edited because no current direct contradiction was found.

## Score And Metadata Recommendation

Implemented target score: `89/92`.

Completion rationale: raise from 85 to 89 because the remaining source-quality question has been resolved into an implementation-ready metadata/no-code recommendation. Current report evidence covers exact range, size, bytes, disassembly, decompile, startup-table xref, lack of ordinary callers, import addresses, paired cleanup thunk, static slot/vtable chain, current generated marker state, neighboring wrapper classification, rejected owners, and support-doc incorporation plan.

Confidence rationale: raise from 90 to 92 because current IDA MCP session `6eab6bcb` reconfirms all direct binary facts and resolves the source-route decision. Keep below 95 because exact original source spelling and final `AutoInit.cpp` versus `PlatformApi.cpp` fold remain inferred rather than proven by source metadata.

Metadata:

- `CANONICAL_OWNER:0000HN`: keep as source-policy owner.
- `RECONSTRUCTABLE:FALSE`: exact by-memory helper is compiler/static-lifetime generated glue, not a standalone handwritten source function.
- `EMITTER_UIDS:` blank: no standalone emitter for UID0000W8.
- `RECONSTRUCTION_CPP CODE`: blank: no formal C++ for this target.

## Open Questions With Attempted Resolution

| Question | Investigation | Resolution / impact |
| --- | --- | --- |
| Is `InitializeOleSupport` a source-authored helper function? | Checked current MCP callers/xrefs, disassembly, decompile, startup table bytes, neighboring wrapper docs. | No direct source-call route found; startup-table-only data xref supports generated helper. Formal C++ blank. |
| Should AutoInit ownership be removed because the exact helper is generated? | Checked vtable/static slot/destructor/shutdown chain and AutoInit docs. | No. Keep AutoInit as source-policy owner; only remove standalone emitter/reconstructable status from exact helper. |
| Should Browser own it because Browser code uses COM? | Checked Browser docs and process-wide startup route. | No. Browser is a COM consumer; UID0000W8 runs from startup table and belongs to process-wide OLE lifetime policy. |
| Should PlatformApi replace AutoInit as owner? | Checked AutoInit and PlatformApi caveats in docs. | Not now. PlatformApi remains possible later fold target, but AutoInit has stronger direct vtable/static-object/destructor evidence. |
| Can we safely write a low-level first-draft C++ function? | Compared decompiler body with source-route evidence and paired thunk classification. | No. It would be behavior-equivalent but source-shape misleading. |
| Is there a split/range issue? | `lookup_funcs` confirms `0x00419ee0` size `0x14`; `0x00419ef4` not a function; bytes show padding before/after and startup table neighbors. | No split needed. Range is exact. |

## Validator Results

Scoped validators run from `source-3/project-documentation`; all exited `0` with `ok: 1`. No `execute_report`, dry-run/probing lifecycle command, registry lifecycle command, manual report move, generated-file edit, coverage edit, or validator-state edit was run.

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md` | `python .\tools\validator.py --mode file --file by-memory\0x00419ee0-0x00419ef4.InitializeOleSupport.md --apply --queue-timeout 240 --wait-generated` | `000000006120` | `2026-07-04T05:14:28-04:00` | 0 | 1 | Applied `0000W8` completion/confidence, reconstructable `true -> false`, emitter `0000HN ->`; generated refresh completed and updated `auto-generated/NexusTK/platform/AutoInit.cpp`. Warnings were broad existing autogen marker/no-code diagnostics, not target-specific failures. |
| `by-file/AutoInit.md` | `python .\tools\validator.py --mode file --file by-file\AutoInit.md --apply --queue-timeout 240` | `000000006121` | `2026-07-04T05:14:43-04:00` | 0 | 1 | Support text validated; generated refresh deferred. |
| `by-class/AutoInit.md` | `python .\tools\validator.py --mode file --file by-class\AutoInit.md --apply --queue-timeout 240` | `000000006122` | `2026-07-04T05:14:49-04:00` | 0 | 1 | Support text validated; generated refresh deferred; generated `AutoInit.cpp` header later observed at this command id. |
| `by-global/InitializeOleSupport.md` | `python .\tools\validator.py --mode file --file by-global\InitializeOleSupport.md --apply --queue-timeout 240` | `000000006123` | `2026-07-04T05:14:56-04:00` | 0 | 1 | Applied `0000T3` `86/92`, reconstructable `true -> false`, emitter `0000HN ->`; generated refresh deferred. |

Generated freshness:

- `auto-generated/NexusTK/platform/AutoInit.cpp` header after validators: `validator-command-id: 000000006122`, `validator-refreshed-at: 2026-07-04T05:14:49-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- `Select-String` for `0000W8|InitializeOleSupport` in generated `AutoInit.cpp` returned no matches, so the UID0000W8 empty marker is gone.
- `python .\tools\validator.py --queue-status` returned command_id `000000006124`, timestamp `2026-07-04T05:15:11-04:00`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.

## Changed Files

Implementation callback changed:

- `tools/leaser/Agents/Agent-B013/research/0000W8-InitializeOleSupport-source-quality.md`
- `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md`
- `by-file/AutoInit.md`
- `by-class/AutoInit.md`
- `by-global/InitializeOleSupport.md`

Inspected and left unchanged as already present at same-or-greater detail:

- `by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md`
- `by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md`
- `by-type/by-vtable/AutoInitVtable.md`

No generated files were edited manually. Validator-generated files refreshed through scoped validation only. No coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited manually.

## Implementation Tracking Checklist

- [x] Target metadata: in `by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md`, set `COMPLETION:89`, `CONFIDENCE:92`, kept `CANONICAL_OWNER:0000HN`, set `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, kept `EMITTER_POSITION_OPTIONAL` blank, and kept formal C++ blank. Validator `000000006120` confirmed completion/confidence and registry updates.
- [x] Target evidence: added current MCP session `6eab6bcb` facts for active session/health, function size/range, no ordinary callers, startup-table xref `0x0060d6a4`, disassembly/decompile body, import addresses, raw bytes, table neighbors, and paired thunk/static slot/vtable evidence.
- [x] Target source-shape wording: replaced standalone reconstructable helper wording with non-emitting compiler/static-lifetime startup glue caused by the AutoInit source policy.
- [x] Target historicalization: preserved old `InitializeOleSupport` body as behavior evidence and marked low-level helper C++ / generated empty marker as superseded source-emission guidance, not final source text.
- [x] Support `by-file/AutoInit.md`: updated so UID0000W8 is AutoInit source-policy evidence but non-emitting startup glue; preserved `AutoInit.cpp` versus `PlatformApi.cpp` caveat. Validator `000000006121` passed.
- [x] Support `by-class/AutoInit.md`: updated method inventory/source notes so `InitializeOleSupport` is startup initializer equivalent of construction/static lifetime, not a source-callable method needing its own body. Validator `000000006122` passed.
- [x] Support `by-global/InitializeOleSupport.md`: updated stale reconstructable/global-helper wording to name-centric/non-emitting status; metadata set to `86/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++. Validator `000000006123` passed.
- [x] Support `by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md`, `by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md`, and `by-type/by-vtable/AutoInitVtable.md`: inspected during callback and left unchanged because each already carries same-or-greater non-emitting/generated-binary detail.
- [x] Rejected owners: preserved rejection of Browser/BrowserThread, PlatformApi-as-direct-owner, import data, neighboring startup wrapper pages, and unknown/no-owner in target/support docs.
- [x] Validators: ran scoped validators only for changed by-* docs from `source-3/project-documentation`; command ids/timestamps/exits/ok counts/warnings/generated effects recorded in `Validator Results`.
- [x] Generated freshness: confirmed `auto-generated/NexusTK/platform/AutoInit.cpp` is refreshed (`validator-command-id: 000000006122`, `validator-refreshed-at: 2026-07-04T05:14:49-04:00`) and no longer contains a UID0000W8 empty marker; queue status showed no pending generated refresh jobs.
- [x] Ledger: updated every Claim And Incorporation Ledger row from `proposed` to `applied` or `already-present` with exact proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000006131","destination_path":"executed-b-agent-research/B013/0000W8-InitializeOleSupport-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0000W8-InitializeOleSupport-source-quality.md","timestamp":"2026-07-04T05:20:10-04:00","uid":"0000W8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
