** TARGET-REPORT-UID:000329 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000329 RegistryConfig Scalar Deleting Destructor Source Quality


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:000329][0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor](../../../by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md) as a `RegistryConfig`-owned compiler-generated scalar deleting destructor wrapper, with no handwritten wrapper body.
- Final disposition applied by implementation callback: source-ready no-code/covered-by marker. Target metadata is `88/91`; `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, and blank `EMITTER_POSITION_OPTIONAL:` are preserved; the formal C++ block now contains the exact covered-by marker from this report.
- Applied support action: stale source-visible `ScalarDeletingDestructor(unsigned char flags)` wording was softened in [UID:0000BW][RegistryConfig](../../../by-class/RegistryConfig.md), and [UID:0000N4][RegistryConfig](../../../by-file/RegistryConfig.md) now names UID000329 as a covered-by compiler-wrapper marker through the `RegistryConfig` destructor declaration/body.
- Confidence: high. MCP session `b010_00032w_20260703` confirms the exact wrapper body, vtable-only data route, destructor callee, delete-flag branch, guard-size immediate, padding, and sibling vtable/data facts. Remaining confidence cap is source-level naming/header exactness, not ownership or behavior.

## Supporting Research
- Historical report-only pass: B007 first produced this artifact without target/support by-* edits, validators, generated edits, coverage edits, lifecycle/archive commands, or supervisor-ledger edits. The implementation callback later applied the accepted target/support changes recorded below.
- The supervisor override restored MCP and named active NexusTK session `b010_00032w_20260703`. B007 used that existing session read-only only; no `idb_open`, `idb_close`, process-management, lifecycle, archive, or `execute_report` command was run.
- Post-callback generated output `auto-generated/NexusTK/config/RegistryConfig.cpp` header records `validator-command-id: 000000005568`, `validator-refreshed-at: 2026-07-03T16:02:57-04:00`, and emits UID000329 lines 21-23 as `Completion:88 | Confidence:91` with the explicit covered-by marker before UID00032F `RegistryConfig::~RegistryConfig()`.
- Prior executed reports used as leads: B007 `0000N4-RegistryConfig-empty-emitter-family-source-quality.md` installed the current UID000329 comment-only marker; B001 `0000YU-ApplicationFunctionObject0Callbacks.md` split the exact child; B001 `000110-ConfigAndRegistryDefaults.md` split the real destructor child; B004 `00024T-ApplicationStartupReadOnlyData-source-quality.md` split the RegistryConfig RTTI/vtable data; scalar deleting destructor reports such as B009 UID0002VK and B002 UID00018V were checked for no-code/covered-by policy precedent.

## Target
- Target UID: `000329`
- Target path: `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`
- Historical source queue/report row before callback: `auto-generated/-ag-research-tracker.md`, `## by-memory` / `### Not-Covered Files - Reconstructable`, row `[UID:000329]`, score `85/89`, combined `87.0`, reconstructable `true`, reports `0`.
- Implementation callback classification: accepted Medium source-quality report applied to a reconstructable by-memory target whose emitted output is a compiler-wrapper marker.
- Implemented scores and parent state: target `88/91`; direct owner/emitter [UID:0000BW][RegistryConfig](../../../by-class/RegistryConfig.md) is `88/90` and emits through [UID:0000N4][RegistryConfig](../../../by-file/RegistryConfig.md), which is `90/90` with generated output `auto-generated/NexusTK/config/RegistryConfig.cpp`.

## Current Target State
- Implemented metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, blank `EMITTER_POSITION_OPTIONAL`.
- Implemented owner/emitter/reconstructable state: correct. The target is a class-owned `RegistryConfig` ABI wrapper and routes through the `RegistryConfig` class/file output chain.
- Implemented C++/emitter state: formal block contains the exact covered-by marker naming [UID:0000BW][RegistryConfig](../../../by-class/RegistryConfig.md) and [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](../../../by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md). It is not an empty emitter and does not emit a handwritten wrapper body.
- Remaining confidence caps: no unresolved ownership/range blocker remains. Exact original destructor declaration spelling and full class layout remain broader `RegistryConfig` caps, not UID000329 blockers.
- Related target/support docs checked: `by-class/RegistryConfig.md`, `by-file/RegistryConfig.md`, UID00032F destructor page, UID000481 vtable data page, UID0000YU parent aggregate, `g_pConfig`, `Config`, `ConfigVtableData`, `ApplicationCleanupResources`, `MemoryMan`, `OperatorDeleteWrapper`/delete-helper context, generated coverage/tracker files, and relevant executed B reports.
- Artifact/lifecycle note: this report records the implementation-applied by-* state; supervisor lifecycle and execution state are tracked externally by validator/report history.

## Executive Recommendation
UID000329 should remain owned and emitted through [UID:0000BW][RegistryConfig](../../../by-class/RegistryConfig.md), but the formal C++ block should be a covered-by marker rather than a hand-written `RegistryConfig::ScalarDeletingDestructor` body. The source-visible destructor body is [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](../../../by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md) plus the `RegistryConfig` virtual destructor declaration in [UID:0000BW].

No split, rename, parent reassignment, non-owner treatment, or non-emitting downgrade is recommended. The exact target range is a real binary function referenced from the `RegistryConfig` vtable, so it should stay reconstructable and routed through the class output, but the source body should remain compiler-regenerated glue.

## Supervisor Active Recheck
- Historical triggering instruction: the initial supervisor assignment for Agent-B007 required UID000329 report-only research, mandatory MCP evidence, no by-* edits, no validators, no lifecycle/archive/execute commands, and return for supervisor Gate 1 review. The later implementation callback authorized the by-* edits and validators recorded below.
- MCP override: the supervisor restored MCP and supplied existing session `b010_00032w_20260703`; B007 verified it with read-only `idb_list` and `server_health`, then used only narrow, schema-current calls.
- Split repair: not required. MCP `lookup_funcs` shows one modeled function at `0x00467340` with size `0x3b`; predecessor and successor starts are separate; bytes prove only alignment padding around the target.
- Source-bearing child status: the only source-authored destructor body in this relationship is UID00032F. UID000329 is source-declared/generated-binary wrapper glue and should receive only a marker.

## Inference Research Guidance Check
The active `by-structure.md` reconstruction rule matters here: a by-memory page can emit C++ only for source represented by its own range, and intentionally covered compiler-generated ranges should use a formal comment marker rather than looking like empty emitters. The direct binary facts are the function body, vtable reference, destructor callee, delete-helper call, guard branch, and padding. Documentation evidence is the existing RegistryConfig class/file/destructor/vtable pages and the previous B007/B001/B004 executed reports. The source-shape inference is that original human source would declare/define `RegistryConfig::~RegistryConfig()`, not a public or private method named after the scalar deleting destructor ABI wrapper.

Existing docs were treated as leads and rechecked. Current generated output and old reports corroborate the route, but the recommendation rests on current MCP session `b010_00032w_20260703`. No Wave2/Wave3 material was used as authority.

## Heuristic / Inference Reanalysis And Validation
- Compiler-wrapper naming: `sub_467340` is the IDA function for the binary wrapper. The source-facing documentation name `RegistryConfigScalarDeletingDestructor` is useful as a by-memory title, but should not become a C++ method. The accepted source-facing description is "compiler-generated scalar deleting destructor wrapper for `RegistryConfig::~RegistryConfig()`."
- Destructor callee: MCP disassembly and decompile show the wrapper calls `sub_48E780` at `0x00467346`. Current docs and UID00032F identify that callee as the real `RegistryConfig::~RegistryConfig()` body.
- Delete-helper role: MCP decompile/disassembly of `0x004f4ac0` shows it calls `sub_516030` / `GetMemoryMan()` and then `sub_516170` / `FreeBufferMemory`. Current MemoryMan docs identify [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](../../../by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) as global `operator delete(void *block)`. UID000329 should document this as a dependency, not as the source owner.
- Delete flags: MCP disassembly shows `test al, 1`, `jz` return, `test al, 4`, `jnz` guard path, then ordinary delete through `sub_4F4AC0` only for `(flags & 1) != 0 && (flags & 4) == 0`. This is the standard scalar deleting destructor policy already used in peer pages.
- Guard/object-size path: MCP disassembly shows the `flags & 4` path pushes immediate `0x291918` and calls `@_guard_check_icall_nop@4`; `func_profile` reports constant `0x291918` decimal `2693400`. This documents object-size/guard lowering and must not become source C++.
- Vtable route: MCP `xrefs_to 0x00467340` returns exactly one data xref from `0x00612614`; vtable bytes at `0x00612610` decode as COL pointer `0x00642100`, wrapper `0x00467340`, support slots `0x004f4b10` and `0x0041b6c0`, `SaveToRegistry` `0x00491b30`, and `LoadFromRegistry` `0x004926a0`.
- Range/split: bytes at `0x00467338-0x00467340` are eight `0xcc` padding bytes after the predecessor `PasswordError` wrapper; bytes at `0x0046737b-0x00467380` are five `0xcc` padding bytes before the `DestroyDATFileMgr` successor. No internal child range or merge is supported.
- Rejected source C++ body: a function such as `RegistryConfig::ScalarDeletingDestructor(unsigned char flags)` would be decompiler-shaped ABI source and duplicate compiler-generated delete flag behavior that should be regenerated from the virtual destructor declaration/body.
- Rejected non-reconstructable/no-owner route: the wrapper is live in the class vtable and has a valid emitter route, so keeping it visible as a reconstructable covered marker is more accurate than hiding it.
- Rejected direct parent alternatives: UID0000YU is only the mixed parent aggregate; `Config` is the base/dependency, not the derived wrapper owner; `MemoryMan`/`OperatorDeleteWrapper` is only the delete dependency; adjacent PasswordError/Application/WinMain items are separate functions.

## Evidence Standards Used
The evidence ladder used current IDA MCP availability checks, exact `lookup_funcs`, bounded `get_bytes`, bounded `disasm`, `decompile`, `xrefs_to`, `callees`, `get_int`, and `func_profile`, plus current by-* docs, generated output, generated tracker/coverage rows, and matching executed B reports as leads. The strongest facts are direct MCP control-flow and data-route facts: the function body proves destructor/delete behavior, and the vtable/data xref proves class ownership. Tool limitations do not block the recommendation because the source output is intentionally a no-code marker; exact original symbol spelling would only affect final wording, not behavior or ownership.

## Evidence Checked
- IDA MCP checks performed on session `b010_00032w_20260703`: `initialize`/`tools/list`; `idb_list` id `3`; `server_health` id `4`; `lookup_funcs` id `10`; `get_bytes` id `11`; `disasm` id `12`; `decompile` id `13`; `xrefs_to` id `14` and smaller `xrefs_to` ids `30..34`; `callees` id `15`; `get_int` id `16`; `func_profile` id `40`; `decompile`/`disasm` of delete helper ids `50..51`.
- by-* docs checked: target page, [UID:0000BW][RegistryConfig](../../../by-class/RegistryConfig.md), [UID:0000N4][RegistryConfig](../../../by-file/RegistryConfig.md), UID00032F destructor, UID000481 vtable data, UID0000YU parent aggregate, UID00028Q `g_pConfig`, `Config`, `ConfigVtableData`, `ApplicationCleanupResources`, and MemoryMan/operator-delete context.
- Generated docs checked: `auto-generated/NexusTK/config/RegistryConfig.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, and `auto-generated/-ag-file-coverage.md`.
- Executed reports searched with terms `000329`, `00467340`, `RegistryConfigScalarDeletingDestructor`, `scalar deleting destructor wrapper`, and `RegistryConfig scalar`. Relevant matches opened: B007 UID0000N4 family report, B001 UID0000YU parent split, B001 UID000110 split, B004 UID00024T vtable/data split, and peer scalar-deleting reports UID0002VK/UID00018V.
- Negative checks performed: `xrefs_to 0x00467340` found only the `0x00612614` data xref; `func_profile` reports `caller_count:0`; `xrefs_to 0x0048e780` found only the wrapper call at `0x00467346`; `lookup_funcs 0x0046737b` and `0x0048e85a` reported not function starts; `xrefs_to 0x0046737b` returned zero xrefs.
- Failed or skipped checks: no failed MCP evidence calls after the supervisor-provided session was restored. A broad full-binary pointer scan was intentionally skipped because direct `xrefs_to`, vtable bytes, and generated docs already proved the only class route needed for this target, and the assignment requires narrow MCP discipline.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-000329-01 | UID000329 is exact function `sub_467340` at `0x00467340`, size `0x3b`, half-open end `0x0046737b`. | high | MCP `lookup_funcs` id `10`; bounded bytes id `11`; disasm id `12`. | Target `Scope`, `IDA Evidence`, score rationale. | Incorporated exact range/function evidence in target. | applied - target validator `000000005566` ok |
| C-000329-02 | Wrapper calls real `RegistryConfig::~RegistryConfig()` at `0x0048e780` from `0x00467346`. | high | MCP disasm/decompile ids `12`, `13`; `xrefs_to 0x0048e780` id `31`; UID00032F docs. | Target behavior and UID00032F cross-reference; class/file support wording. | Incorporated callee relation and covered-by body in target, class, and file docs. UID00032F already carried caller/body evidence. | applied - validators `000000005566`, `000000005567`, `000000005568` ok; UID00032F already-present |
| C-000329-03 | Conditional delete is standard scalar deleting destructor policy: delete only when bit `1` set and bit `4` clear. | high | MCP disasm id `12` shows `test al,1`, `test al,4`, `call sub_4F4AC0`; decompile id `13`; peer scalar reports. | Target behavior/no-code proof. | Incorporated flag semantics and rejected handwritten wrapper body. | applied - target validator `000000005566` ok |
| C-000329-04 | The guard/object-size branch pushes `0x291918` and calls `@_guard_check_icall_nop@4`; constant decimal is `2693400`. | high | MCP disasm id `12`; `func_profile` id `40` constants. | Target behavior and score rationale. | Incorporated guard-size fact as compiler lowering. | applied - target validator `000000005566` ok |
| C-000329-05 | The only direct xref to target start is the RegistryConfig vtable slot at `0x00612614`. | high | MCP `xrefs_to 0x00467340` id `30`; vtable bytes/get_int ids `11`, `16`; UID000481 docs. | Target IDA evidence; RegistryConfig/vtable support docs. | Incorporated vtable-only route in target; UID000481 already recorded `0x00612614 -> 0x00467340` and required no edit. | applied - target validator `000000005566` ok; UID000481 already-present |
| C-000329-06 | Surrounding bytes prove separate predecessor/successor ranges with padding, not a split/merge issue. | high | MCP bytes id `11`; lookup of predecessor `0x00467300` and successor `0x00467380` id `10`; UID0000YU map. | Target range/split section; parent aggregate. | Preserved exact padding/no-split conclusion in target; UID0000YU already listed child range and padding gaps. | applied - target validator `000000005566` ok; UID0000YU already-present |
| C-000329-07 | `sub_4F4AC0` is the operator-delete dependency, not target owner/source body. | high | MCP delete-helper decompile/disasm ids `50`, `51`; MemoryMan docs for `GetMemoryMan`, `FreeBufferMemory`, `OperatorDeleteWrapper`. | Target dependency/rejected alternatives. | Incorporated delete-helper role and rejected MemoryMan ownership; operator-delete docs already present. | applied - target validator `000000005566` ok; delete-helper docs already-present |
| C-000329-08 | Formal C++ should be an explicit covered-by marker, not a wrapper body and not a blank/ambiguous emitter. | high | `by-structure.md` code-entry rule; generated marker; MCP proof; peer scalar reports. | Target formal `RECONSTRUCTION_CPP CODE` block and generated `RegistryConfig.cpp`. | Replaced marker with exact covered-by block; generated `RegistryConfig.cpp` lines 21-23 now contain UID000329 `88/91` marker under validator `000000005568`. | applied - target validator `000000005566` ok; generated refresh observed |
| C-000329-09 | Metadata should be `COMPLETION:88`, `CONFIDENCE:91`, with owner/emitter/reconstructable unchanged. | medium-high | All MCP evidence, owner chain, generated coverage, and no-code proof. | Target metadata/score rationale. | Applied score update and preserved `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, blank optional position. | applied - target validator `000000005566` ok with completion/confidence updates |
| C-000329-10 | Support docs mostly contain the correct route; only source-shaped wording should be refined if stale. | medium-high | `by-class/RegistryConfig.md`, `by-file/RegistryConfig.md`, UID00032F, UID000481, UID0000YU review. | Support docs. | Updated stale UID000329-specific class/file wording; UID00032F, UID000481, and UID0000YU already contained accepted relation/range evidence, so they were not edited. | applied/already-present - validators `000000005567` and `000000005568` ok |

## Positive Evidence Summary
- Direct facts supporting the recommendation: one exact `.text` function at `0x00467340`; one vtable data xref from `0x00612614`; direct call to `0x0048e780`; conditional call to `0x004f4ac0`; no code callers; exact padding around the function.
- Corroborating documentation/generated-report evidence: target page already names `RegistryConfig`, UID00032F carries `RegistryConfig::~RegistryConfig()` C++, UID000481 records the vtable slot, `RegistryConfig.cpp` currently places UID000329 immediately before UID00032F, and generated coverage routes UID000329 through `auto-generated/NexusTK/config/RegistryConfig.cpp`.
- Strongest inference chain: vtable slot `0x00612614 -> 0x00467340` plus wrapper call `0x00467346 -> 0x0048e780` means this is the compiler-generated deleting-destructor wrapper for `RegistryConfig::~RegistryConfig()`. Human source should be the virtual destructor declaration/body, with compiler regeneration of the scalar deleting wrapper.

## IDA MCP Facts
- Session facts: `idb_list` id `3` returned active session `b010_00032w_20260703`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_analyzing:false`, `is_active:true`, worker PID `12964`. `server_health` id `4` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Function/range facts: `lookup_funcs` id `10` returned `0x00467340 -> sub_467340 size 0x3b`; `0x0046737b` is not a function; `0x0048e780 -> sub_48E780 size 0xda`; `0x0048e85a` is not a function; `0x004f4ac0 -> sub_4F4AC0 size 0x40`; `0x00467300 -> sub_467300 size 0x38`; `0x00467380 -> sub_467380 size 0x11`.
- Target bytes: `0x00467340-0x0046737b` bytes are `55 8b ec 56 8b f1 e8 35 74 02 00 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 64 d7 08 00 83 c4 04 8b c6 5e 5d c2 04 00 68 18 19 29 00 56 e8 2f 43 fb ff 83 c4 08 8b c6 5e 5d c2 04 00`.
- Padding facts: `get_bytes` id `11` over `0x00467338` shows eight `0xcc` bytes before the function and five `0xcc` bytes after the function before `0x00467380`.
- Vtable bytes: `get_bytes` id `11` over `0x00612610` returns `00 21 64 00 40 73 46 00 10 4b 4f 00 c0 b6 41 00 30 1b 49 00 a0 26 49 00 e0 21 64 00`, proving `0x00642100`, `0x00467340`, `0x004f4b10`, `0x0041b6c0`, `0x00491b30`, `0x004926a0`, and successor COL `0x006421e0`.
- Disassembly facts: `disasm` id `12` reports 25 instructions. Key instructions are `call sub_48E780` at `0x00467346`, `test al, 1` at `0x0046734e`, `test al, 4` at `0x00467352`, `call sub_4F4AC0` at `0x00467357`, `push 291918h` at `0x00467366`, and `call @_guard_check_icall_nop@4` at `0x0046736c`.
- Decompile facts: `decompile` id `21`/`13` renders a `void *__thiscall` wrapper that calls `sub_48E780(Block)`, returns if `(a2 & 1) == 0` or `(a2 & 4) != 0`, otherwise calls `sub_4F4AC0(Block)` and returns `Block`.
- Xref facts: `xrefs_to 0x00467340` id `30` returns one data xref from `0x00612614`; `xrefs_to 0x0048e780` id `31` returns one code xref from `0x00467346` inside `sub_467340`; `xrefs_to 0x00612614` id `32` returns one data xref from `0x0046413b` inside `sub_4639D0`; `xrefs_to 0x0046737b` id `34` returns zero xrefs.
- Callee facts: `callees` id `15` returns `sub_48E780`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4` as target callees. `func_profile` id `40` reports `caller_count:0`, `instruction_count:25`, `basic_block_count:5`, prototype `void *__thiscall(void *Block, char)`, and constants including `0x1`, `0x4`, `0x291918`, and `0x8`.
- Delete-helper facts: `decompile 0x004f4ac0` id `50` renders `sub_516030()` followed by `sub_516170(Block)`; `disasm` id `51` confirms the call sequence and SEH/security-cookie lowering around the operator-delete wrapper.
- Negative IDA facts: no code caller to `0x00467340`, no function at exclusive end `0x0046737b`, no xref to the exclusive end, and no separate function/data object inside `0x00467340-0x0046737b`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00467340-0x0046737b` | UID000329 `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md` | RegistryConfig scalar deleting destructor compiler wrapper | `TRUE` | UID0000BW RegistryConfig | implemented `88/91` | explicit covered-by marker, no handwritten body |
| `0x0048e780-0x0048e85a` | UID00032F `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md` | real `RegistryConfig::~RegistryConfig()` body | `TRUE` | UID0000BW RegistryConfig | `88/90` | already emits first-draft destructor C++ |
| `0x00612614-0x00612628` | UID000481 `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md` | RegistryConfig vtable data, including slot to UID000329 | `TRUE` | UID0000BW RegistryConfig | `88/92` | no-code vtable marker |
| `0x004671a0-0x004673f6` | UID0000YU `ApplicationFunctionObject0Callbacks` | mixed parent aggregate/neighborhood map | `FALSE` | blank/mixed | `88/90` | already lists exact child ranges |
| `0x00467300-0x00467338` | UID0002VK `PasswordErrorScalarDeletingDestructor` | predecessor scalar deleting destructor | `TRUE` | UID0000A8 PasswordError | implemented by B009 | separate neighbor, not part of UID000329 |
| `0x00467380-0x00467391` | UID0000YV `DestroyDATFileMgr` | successor cleanup helper | `TRUE` | UID0000HG Application | existing | separate neighbor, not part of UID000329 |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00467340` | one data xref from `0x00612614`; no code callers in `func_profile` | vtable-only scalar deleting destructor route |
| `0x00467346` | calls `0x0048e780` | wrapper enters real `RegistryConfig::~RegistryConfig()` |
| `0x00467357` | calls `0x004f4ac0` | optional ordinary object storage delete path |
| `0x00467366` | pushes `0x291918` | guard/object-size compiler path for `flags & 4` |
| `0x00612614` | data xref from `0x0046413b`; dword value `0x00467340` | RegistryConfig vtable slot pointing to wrapper |
| `0x00612620` | dword value `0x00491b30` | `RegistryConfig::SaveToRegistry` vtable slot, sibling vtable corroboration |
| `0x00612624` | dword value `0x004926a0` | `RegistryConfig::LoadFromRegistry` vtable slot, sibling vtable corroboration |

## Documentation Evidence And IDA Status
- Implemented docs that support the conclusion: target page states the call to `~RegistryConfig`, conditional delete, vtable slot `0x00612614`, exact bytes, padding, guard/object-size path, and explicit covered-by marker; `by-class/RegistryConfig.md` records the destructor route and identifies UID000329 as compiler ABI glue; `by-file/RegistryConfig.md` says UID000329 is a covered-by compiler-wrapper marker; UID00032F documents the real destructor body and scalar-wrapper caller; UID000481 records vtable slots; UID0000YU records the child map and padding.
- Stale/incomplete docs after callback: none found in accepted scope. UID00032F, UID000481, and UID0000YU already carried the accepted relation/range evidence and were not edited.
- Generated/coverage report state after callback validators: generated `RegistryConfig.cpp` contains UID000329 marker lines 21-23 with score `88/91`, validator command `000000005568`, refreshed `2026-07-03T16:02:57-04:00`, and no `Empty Emitter Marker`.

## Ranked Ownership Analysis

### 1. [UID:0000BW] RegistryConfig
- Evidence for: target vtable slot `0x00612614` is inside RegistryConfig vtable data and points to `0x00467340`; wrapper calls UID00032F `RegistryConfig::~RegistryConfig()`; class/file docs and generated output route UID000329 through `RegistryConfig.cpp`.
- Evidence against: source code should not expose a wrapper method; this is a compiler-generated ABI artifact. That affects C++ content, not ownership.
- Decision: keep as canonical owner and emitter.

### 2. [UID:0000N4] RegistryConfig File
- Evidence for: final generated source root is `NexusTK/config/RegistryConfig.cpp`, and file page owns broader file-level helpers/literals.
- Evidence against: UID000329 has a narrower true class owner via vtable/destructor route.
- Decision: use only as output root through UID0000BW, not direct canonical owner.

### 3. [UID:0000IE] Config / MemoryMan / UID0000YU Parent Aggregate
- Evidence for: `Config` is the base class and `g_pConfig` is a base pointer; MemoryMan/operator delete frees storage; UID0000YU contains the address neighborhood.
- Evidence against: the target vtable slot is RegistryConfig's derived destructor slot; `Config` is dependency/base, MemoryMan is delete dependency, and UID0000YU is a mixed non-emitting aggregate.
- Decision: reject as direct owner.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file or grouping.
- Likely full contents: not applicable.
- Candidate related items that belong: UID00032F destructor body and UID000481 vtable data remain existing support items.
- Candidate related items rejected: adjacent PasswordError wrapper, DestroyDATFileMgr, Config base deleting destructor, and OperatorDeleteWrapper.
- Standalone, narrow, or broad source-file inference: no standalone source item. The source-level representation is narrow: `RegistryConfig` class virtual destructor declaration/body.

## Source Placement
- Recommended source file/class/global/module placement: keep under `RegistryConfig` class, output through `NexusTK/config/RegistryConfig.cpp`.
- Why this placement fits source-tree and subsystem context: the wrapper is the vtable destructor entry for the derived registry-backed config class; the neighboring vtable slots are `RegistryConfig::SaveToRegistry` and `RegistryConfig::LoadFromRegistry`; the real destructor body already lives in the same generated `RegistryConfig.cpp` output.
- Rejected placements and why: `Application`/UID0000YU is only the mixed parent neighborhood; `Config` is the base; `MemoryMan`/OperatorDeleteWrapper is a dependency; `WinMain`, DATFileMgr, PasswordError, and FunctionObject0 are adjacent or sibling owners only.
- Remaining placement uncertainty: none material for owner/emitter/source file. Exact original header spelling for the destructor declaration and full class layout remain broader RegistryConfig confidence caps.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: modeled function begins at `0x00467340`, size `0x3b`, exclusive end `0x0046737b`. Predecessor `0x00467300` has size `0x38`; successor `0x00467380` has size `0x11`. Padding is `0x00467338-0x00467340` eight `0xcc` bytes and `0x0046737b-0x00467380` five `0xcc` bytes.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. UID000329 is already exact.
- Padding/table/data/code distinctions: UID000329 is `.text` code. UID000481 is separate `.rdata` vtable data that points to it. Padding remains alignment only.
- Parent/container impact: UID0000YU remains a non-emitting mixed neighborhood map; no parent metadata change is recommended.

## Negative Evidence Summary
- Not a human-written `RegistryConfig::ScalarDeletingDestructor(unsigned char)` method: no source-facing call route; only vtable data points to it; body is pure MSVC delete-flag/guard lowering around the real destructor.
- Not `Config`-owned: the real callee is `RegistryConfig::~RegistryConfig()` and the vtable slot is RegistryConfig's derived slot, even though `Config` is the base class and `g_pConfig` is a base pointer.
- Not MemoryMan/operator-delete owned: `sub_4F4AC0` is called only on the optional delete branch and is already documented as global `operator delete`; it is a dependency, not owner evidence.
- Not UID0000YU/Application-owned: the parent aggregate is mixed and non-emitting, and the direct data route is RegistryConfig's vtable.
- Not padding or dead code: the function is in a live vtable slot and is reached by virtual destruction.
- Not a split candidate: exact bytes and lookup results show one bounded function with only alignment before/after.
- Not a downgrade to `RECONSTRUCTABLE:FALSE`: generated visibility is useful because the rebuilt class declaration/destructor will regenerate this binary-level wrapper, and the marker prevents the target from looking accidentally blank.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: documentation can use `RegistryConfig scalar deleting destructor wrapper`, `RegistryConfig::~RegistryConfig()` for UID00032F, `OperatorDeleteWrapper` for `0x004f4ac0`, and `deleteFlags`/`flags` for the wrapper byte in prose.
- Evidence for each proposed name/type/comment: vtable/dtor route for RegistryConfig, UID00032F real destructor body, MemoryMan docs for operator delete, and MCP flag tests.
- Items intentionally left unchanged and why: no IDA database rename/type/comment edits are requested. The target by-memory title is useful; the source output should avoid raw function names and avoid a wrapper source signature.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested for this UID000329 assignment.

## First-Draft C++ Recommendation
- Eligible for draft C++: the target clears the combined score/emitter gate and has a valid output route, but the target-specific no-code proof requires a formal marker only.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated RegistryConfig scalar deleting destructor wrapper.
// Emitted code for this range is covered by [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) and [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: the original source behavior is represented by the virtual destructor declaration/body; MSVC regenerates the scalar deleting destructor wrapper, vtable slot, delete-flag tests, operator-delete branch, and guard/object-size lowering.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: developers would write `RegistryConfig::~RegistryConfig()` and a virtual destructor declaration, not a hand-authored scalar deleting destructor method with ABI flags.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: only the accepted `RegistryConfig` and `RegistryConfig::~RegistryConfig()` names are used; no new field or parameter names are introduced.
- Naming/coding style convention used and evidence for consistency: the marker follows current by-structure covered-by policy and peer scalar deleting destructor no-code markers.
- Reason code should remain blank/comment-only: the function body is compiler ABI glue and duplicates destructor/delete semantics already represented by UID00032F and the class declaration.
- Exact no-code proof: current MCP proves only one vtable/data route to the wrapper, no code callers, a body consisting of call-to-real-destructor plus scalar delete flags plus guard-size runtime lowering, and a separate real destructor child that already emits source C++. A handwritten wrapper body would be decompiler-shaped and less faithful than compiler regeneration.

## Final Recommendation
- Exact changes applied: target metadata is `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter/reconstructable fields are unchanged; the formal C++ block contains the exact covered-by marker above; the target page records accepted MCP session `b010_00032w_20260703` evidence for function bytes, xrefs, vtable bytes, delete flags, guard path, destructor callee, delete-helper role, padding, and generated-output state.
- Exact parent assignments applied: direct parent remains [UID:0000BW][RegistryConfig](../../../by-class/RegistryConfig.md); output route remains through UID0000BW to UID0000N4 `RegistryConfig.cpp`.
- Exact items left no-owner/non-emitting and why: none for UID000329. The parent UID0000YU remains non-emitting mixed aggregate, but this target remains reconstructable with a covered-by marker.
- Exact future work outside this assignment scope: broader `RegistryConfig` final class-layout/header audit and exact original destructor declaration spelling remain outside this target. They do not block UID000329's no-code marker or score update.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`
- Exact report facts applied: accepted MCP session/health; function `sub_467340` size `0x3b`; exact target bytes and padding; call to `sub_48E780` at `0x00467346`; delete flag tests and `sub_4F4AC0` call; guard/object-size immediate `0x291918`; vtable xref at `0x00612614`; `xrefs_to 0x0048e780` only from wrapper; delete helper decompile to `GetMemoryMan`/`FreeBufferMemory`; generated output marker lines 21-23; no code caller/no split proof.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, blank `EMITTER_POSITION_OPTIONAL`, and the exact formal covered-by marker block from this report.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: the wrapper is compiler-generated, not hand-written; UID00032F is the real destructor body; Config/MemoryMan/Application/UID0000YU ownership is rejected; standalone wrapper C++ is rejected; guard/object-size path remains compiler lowering.

## Recommended Support Doc Changes
- Support path: `by-class/RegistryConfig.md`
- Exact report facts applied: UID000329 method row now describes a compiler scalar deleting destructor wrapper for `RegistryConfig::~RegistryConfig()` with source covered by the destructor declaration and UID00032F. Vtable slot `0x00612614` and class score/route are preserved.
- Metadata/link/score/coverage/source-placement changes: no metadata change.

- Support path: `by-file/RegistryConfig.md`
- Exact report facts applied: generated-output/source-family notes now describe UID000329 as a covered-by compiler-wrapper marker, with source body represented by UID00032F and the class declaration.
- Metadata/link/score/coverage/source-placement changes: no metadata change.

- Support path: `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`
- Exact report facts already present: slot `0x00612614 -> 0x00467340`, support slots, Save/Load slots, and no-code vtable proof. No edit needed.
- Metadata/link/score/coverage/source-placement changes: none.

- Support path: `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`
- Exact report facts already present: scalar wrapper caller at `0x00467346` and emitting `RegistryConfig::~RegistryConfig()` source body. No edit needed.
- Metadata/link/score/coverage/source-placement changes: none.

- Support path: `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`
- Exact report facts already present: UID000329 child row and padding gaps around `0x00467338-0x00467340` / `0x0046737b-0x00467380`. No edit needed.
- Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation
- Implemented score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, blank `EMITTER_POSITION_OPTIONAL`, formal explicit covered-by marker.
- Historical pre-callback score/metadata: `COMPLETION:85`, `CONFIDENCE:89`; owner/emitter/reconstructable fields were already correct.
- Score rationale and reason not higher/lower: completion rose because the report and target docs refresh exact MCP proof for bytes, range, vtable xref, destructor callee, delete helper, flags, guard size, padding, generated output, and no-code policy. Confidence rose because all direct routes agree and no owner/split ambiguity remains. It should not go higher because this exact range has no handwritten source body, exact original header/declaration spelling is still represented through the broader class docs, and the full `RegistryConfig` layout remains a broader confidence cap.
- Score-improvement attempt: checked body, range, xrefs, vtable bytes, delete-helper role, guard/object size, parent aggregate, generated output, support docs, old reports, and code-entry policy. Each named blocker resolves to either a target update or already-present support evidence. No "needs more investigation" blocker remains for this target.
- Metadata fields changed or left unchanged: changed completion/confidence and formal marker/evidence body; left owner, reconstructable, emitter, and emitter position unchanged.

## Open Questions With Attempted Resolution
- Open question: should UID000329 emit a source C++ body? Resolution: no. MCP and source-shape evidence prove it is compiler wrapper glue. Formal marker only.
- Open question: is the existing marker sufficient? Resolution: behaviorally yes, but implementation should make it explicit as covered by UID0000BW and UID00032F so generated output is auditable under current code-entry rules.
- Open question: does the guard-size immediate identify object size and affect source C++? Resolution: it identifies compiler/runtime lowering (`0x291918`, decimal `2693400`) and should be documented as evidence, not emitted as source.
- Open question: could `Config`, `MemoryMan`, Application/UID0000YU, or adjacent functions be the owner? Resolution: no. Current vtable xref, destructor callee, generated route, and support docs reject those alternatives.
- Questions remaining unresolved: exact original source spelling of the destructor declaration and full RegistryConfig class layout are unresolved in the broader class family, but neither affects this target's no-code/covered-by disposition. Future evidence required would be original source symbols/headers or a final class-layout audit.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit is required from B007. Validator-owned generated reports refreshed during the scoped callback validators; B007 did not edit generated or coverage files manually.

## Follow-Up Actions
- Supervisor actions: lifecycle/execution handling remains external to this report artifact.
- A-agent actions: none.
- B007 future research actions: none for UID000329 unless supervisor returns this artifact for repair.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `88/91`.
- Remaining uncertainty: exact original `RegistryConfig` header spelling and full field layout are broader class-family caps; no target-specific owner/range/source-disposition uncertainty remains.

## Validator Results
- Target validator command: `python .\tools\validator.py --mode file --file by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md --apply --wait-generated --queue-timeout 240`
  - `command_id: 000000005566`; `command_timestamp: 2026-07-03T16:02:36-04:00`; exit code `0`; `ok: 1`.
  - Key applied effects: `completion_update 000329 ... 88`; `confidence_update 000329 ... 91`; `autogen_registry_update 000329`; `uid_link_update 00032F`; `reference_index_add 000197`; `reference_index_add 000481`; `autogen_cpp_update 0000N4 auto-generated/NexusTK/config/RegistryConfig.cpp`; generated refresh completed.
  - Warnings/side effects: validator reported existing project-wide `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` rows unrelated to UID000329. No target validation error.
- Class validator command: `python .\tools\validator.py --mode file --file by-class/RegistryConfig.md --apply --queue-timeout 240`
  - `command_id: 000000005567`; `command_timestamp: 2026-07-03T16:02:52-04:00`; exit code `0`; `ok: 1`.
  - Key applied effects: `stats_incremental_noop 0000BW`; `projected_stats_update`; generated refresh deferred.
  - Warnings/errors: none for the scanned file.
- File validator command: `python .\tools\validator.py --mode file --file by-file/RegistryConfig.md --apply --queue-timeout 240`
  - `command_id: 000000005568`; `command_timestamp: 2026-07-03T16:02:57-04:00`; exit code `0`; `ok: 1`.
  - Key applied effects: `stats_incremental_noop 0000N4`; `projected_stats_update`; generated refresh deferred.
  - Warnings/errors: none for the scanned file.
- Generated freshness observation: `auto-generated/NexusTK/config/RegistryConfig.cpp` header records `validator-command-id: 000000005568`, `validator-refreshed-at: 2026-07-03T16:02:57-04:00`, and `validator-refresh-source: deferred-generated-refresh`; UID000329 appears at lines 21-23 with `Completion:88 | Confidence:91` and the exact covered-by marker. No `Empty Emitter Marker` appears for UID000329.

## Changed Files
- Modified by B007 manual edits: `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`; `by-class/RegistryConfig.md`; `by-file/RegistryConfig.md`; `tools/leaser/Agents/Agent-B007/research/000329-RegistryConfigScalarDeletingDestructor-source-quality.md`.
- Validator-owned generated refresh observed: `auto-generated/NexusTK/config/RegistryConfig.cpp` and normal validator generated reports/metadata refreshed under commands `000000005566` through `000000005568`; no manual generated or coverage edits were made.
- Support docs inspected but not edited because accepted evidence was already present: `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`, `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`, and `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`.
- Leases used and released: B007 leased `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`, `by-class/RegistryConfig.md`, and `by-file/RegistryConfig.md`; all three unlease commands returned `Success` after validators.
- Renamed: none.
- Report execution: not run. B007 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or archive commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Gate 1 passed for SHA256 `DE44C78BC9B16C0BE403FFF8351D520990430EB463F45FEDAEF4B2E4BBF9A202`; implementation callback was authorized.
- [x] Target/support docs to update: target `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`; support docs `by-class/RegistryConfig.md` and `by-file/RegistryConfig.md` edited; UID000481 vtable data, UID00032F destructor, and UID0000YU parent aggregate confirmed already-present.
- [x] Current target state and actual evidence checked recorded: MCP session `b010_00032w_20260703`, health/session facts, exact bytes, vtable bytes, xrefs, callees, disasm/decompile, generated output, support docs, and old reports are recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C-000329-01 through C-000329-10 are `applied`, `already-present`, or `applied/already-present`.
- [x] Metadata/score changes applied: target `COMPLETION:88`, `CONFIDENCE:91`.
- [x] Score-limiting blockers researched to resolution: owner, range, split, vtable, destructor callee, delete helper, guard size, generated marker, and support-doc wording are resolved.
- [x] Owner/emitter/reconstructable changes applied: no change; preserved `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Split/rename/new-child changes applied: none; no split/merge/new-child needed.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: no-split padding facts incorporated; no IDA edits requested.
- [x] First-draft C++/no-code proof applied: formal C++ block replaced with exact covered-by marker text from `## First-Draft C++ Recommendation`; no handwritten wrapper body emitted.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP facts, bytes, vtable/data xrefs, caller/callee facts, no-code proof, rejected alternatives, and score rationale applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: wrapper-body/source API alternative rejected; Config/MemoryMan/Application/parent aggregate ownership rejected; guard path remains compiler lowering.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: no Wave2/Wave3 authority used.
- [x] Open questions closed or documented as evidence-backed unresolved: exact original header spelling/full class layout remains broader support cap only.
- [x] Validators run after callback: scoped validators `000000005566`, `000000005567`, and `000000005568` completed with exit code `0`, `ok:1`.
- [x] Generated report refresh completed by validator: `RegistryConfig.cpp` refreshed at `2026-07-03T16:02:57-04:00` with command `000000005568`; auto-generated tracker/coverage refresh was validator-owned, not manual.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; generated UID000329 marker freshness confirmed.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000005612","destination_path":"executed-b-agent-research/B007/000329-RegistryConfigScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000329-RegistryConfigScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-03T16:19:14-04:00","uid":"000329"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
