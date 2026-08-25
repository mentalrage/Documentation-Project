** TARGET-REPORT-UID:0002GZ **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002GZ ApplicationDestructor Empty-Emitter Source-Quality Report

Status: FINISHED_IMPLEMENTATION
Assignment: `B009-implement-0002GZ-ApplicationDestructor-empty-emitter-20260629`
Mode: accepted implementation callback. Initial research was report-only; after supervisor acceptance, B009 edited only the required target/support by-* docs and this report. Generated output was inspected read-only after scoped validator refresh. No generated files, manual coverage reports, project-level generated reports, validator/tool state, lock files, executed archives, supervisor ledgers, or IDA DB state were manually edited.

## Finalized Report / Current Recommendation

- Current recommendation: resolve [UID:0002GZ] as the ordinary source-level `Application::~Application` destructor, but do not emit an executable destructor body yet.
- Final disposition: keep owner/emitter route through [UID:00000D] `Application`, keep `RECONSTRUCTABLE:TRUE`, raise target metadata from `88/91` to `89/92`, and replace the blank formal block with a target-specific comment-only no-code marker.
- Required action if accepted: update the target and Application support docs with current MCP session `279422f0` evidence, exact range/bytes/xrefs/callee facts, the source-order blocker, generated empty-marker cause, and the exact formal marker below; then run scoped validators and inspect generated `auto-generated/NexusTK/app/Application.cpp` read-only.
- Confidence: high for exact binary behavior, owner, range, wrapper relationship, and no-code-marker disposition; medium-high for the score movement because final executable source still depends on the unresolved `Application` class declaration and cleanup factoring.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
// No first-draft body yet: Application::~Application cleanup ordering depends on the unresolved
// Application base/member declaration for StringBase, MSGHandler, g_pApplication, and LObject teardown.
```

## Target

- Target UID: `0002GZ`
- Target path: `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`
- Queue source: temporary supervisor front queue from generated `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`.
- Generated state checked read-only: `auto-generated/NexusTK/app/Application.cpp` currently shows line 710 as `// UID:0002GZ | by-memory\0x00463970-0x004639c4.ApplicationDestructor.md | Completion:88 | Confidence:91 | Empty Emitter Marker`.
- Current target metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current source route: [UID:00000D] `Application` class under [UID:0000HG] `Application` file route, generated to `NexusTK/app/Application.cpp`.

## Current Target State

The target already documents the compact destructor behavior accurately: vtable restore, close-and-zero of `Application+0x24`, two StringBase-style releases at `+0x854` and `+0x1c`, embedded/default `MSGHandler` teardown at `+0x4`, clear of `g_pApplication`, and tail jump to `LObject::~LObject`.

The empty-emitter blocker exists because the page left the formal block blank. The earlier blank reason was broad: final member names, class layout, `MSGHandler` embedding, base cleanup factoring, and exact destructor source shape were incomplete. This pass narrows that into a precise current blocker: a normal hand-written destructor body cannot reproduce the verified order without either duplicating compiler-generated member/base destruction or moving `g_pApplication = NULL` to the wrong side of `MSGHandler::~MSGHandler()`.

Support docs checked:

- `by-class/Application.md`
- `by-file/Application.md`
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md`
- `by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md`
- `by-memory/0x00528d60-0x00528e55.MSGHandler.md`
- `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
- `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`
- `auto-generated/NexusTK/app/Application.cpp` as read-only lead/generated-state material

Existing reports searched by UID/address/name/source family terms: `0002GZ`, `00463970`, `ApplicationDestructor`, `~Application`, `sub_463970`, `0002Q2`, `BaramAppScalarDeletingDestructor`, `000294`, `g_pApplication`, `0001CN`, `MSGHandler`, `0002RN`, `StringBase`, `0002GY`, `ApplicationConstructor`, and Application/BaramApp lifecycle terms. Relevant executed reports opened or matched include B010 `0002Q2-BaramAppScalarDeletingDestructor-empty-emitter-source-quality.md`, B001 `000294-g_pApplication-source-quality.md`, B009 `0001CN-MSGHandler-source-quality.md`, B014 `0002GY-ApplicationConstructor-source-quality.md` through incorporated docs, and B002 `000020-CheatDetector-class-source-quality.md` as an analogous singleton-clear/source-order lead only.

## Executive Recommendation

UID0002GZ should remain the exact `Application::~Application` source destructor, owned/emitted by [UID:00000D] `Application` through [UID:0000HG] `Application.cpp`. It should not move to BaramApp, WinMain, the cleanup thunk, `MSGHandler`, `g_pApplication`, `StringBase`, or `LObject`.

Do not emit a behavioral body such as:

- `CloseHandle(m_hSingleInstanceMutex); ... g_pApplication = NULL;`
- explicit calls to `m_osVersionLabel.~StringBase()`, `m_processorName.~StringBase()`, `MSGHandler::~MSGHandler()`, or `LObject::~LObject()`
- a decompiler-shaped sequence that manually destroys subobjects and bases

Those forms are either source-order incorrect or duplicate cleanup that the C++ compiler should generate from the eventual `Application` class declaration. Use the exact comment-only marker instead. This removes the unexplained empty emitter while preserving the blocker at source-quality detail.

## Supervisor Active Recheck

- Current supervisor instruction: produce report-only research for [UID:0002GZ] using active IDA MCP session `279422f0`, redo/update MCP-backed evidence, and do not submit fallback-only work.
- MCP status used: current session `279422f0` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status: ok`, imagebase `0x400000`, Hex-Rays ready, strings cache ready, and bounded `lookup_funcs` succeeded.
- Split repair: no split is recommended. Current MCP confirms exact range `0x00463970-0x004639c4`, predecessor non-function/padding boundary, post-target `0xcc` alignment through `0x004639d0`, and adjacent wrapper/thunk ranges.
- Report-only compliance: no by-* docs were edited, no leases were taken, no validators were run, no generated files were modified, and no IDA DB state was changed.

## Inference Research Guidance Check

I treated existing docs and executed reports as leads and rechecked the target with current session `279422f0`. The source-quality decision separates:

- IDA/MCP facts: function boundary, size, decompile/disassembly, callee set, xrefs, vtable stores, global clear, local bytes, wrapper bytes, and integer conversions.
- Documentation evidence: Application class/file/lifecycle docs, MSGHandler and StringBase helper docs, g_pApplication docs, BaramApp deleting-wrapper report, and generated Application output.
- Inference: source-facing name for the `+0x24` closeable handle, exact class-declaration blocker, and the comment-only marker as the right generated-output repair.

No Wave2/Wave3/source-2 artifacts were used as authority. Generated output was used only as read-only queue-state evidence.

## Evidence Standards Used

Evidence types used:

- IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, `get_bytes`, and `int_convert`.
- Exact decompile/disassembly for UID0002GZ, UID0002Q2, `MSGHandler::~MSGHandler`, StringBase release wrapper, and `LObject` base cleanup.
- Xrefs to destructor start, Application vtables, BaramApp wrapper/thunk starts, and wrapper data slots.
- Current target/support docs and current generated `Application.cpp` empty-emitter state.
- Negative source-shape checks: normal destructor body ordering, manual subobject/base destructor calls, covered-by BaramApp wrapper, clearing emitter, and reconstructable-false routes.

The evidence is strong enough to repair the empty emitter with a formal no-code marker because every binary side effect is accounted for and the remaining blocker is the exact source-level representation, not unknown behavior.

## Evidence Checked

Fresh IDA MCP session `279422f0`:

- `idb_list`: one active session `279422f0`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `16380`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, string cache size `2067`.
- `lookup_funcs`: `0x00463970 -> sub_463970`, size `0x54`; `0x0046396e` not a function; `0x004639c4` not a function; successor `0x004639d0 -> sub_4639D0`; cleanup thunk `0x004f66b0 -> sub_4F66B0`, size `0x5`; BaramApp thunk/wrapper `0x004f66b5 -> sub_4F66B5`, size `0x8`, and `0x004f66c0 -> sub_4F66C0`, size `0x3b`; Application scalar deleting destructor `0x00467230 -> sub_467230`, size `0x87`; helpers `0x004f4a90`, `0x00528d80`, and `0x00582b70`.
- `analyze_function 0x00463970`: prototype `void __thiscall(int this)`, size `84`, four basic blocks, cyclomatic complexity `2`; callers `_WinMain@16` and `sub_4F66C0`; callees `CloseHandle`, `sub_582B70`, `sub_528D80`.
- `decompile 0x00463970`: writes Application vtables at `this+0` and `this+4`, conditionally closes `*(this+36)`, calls `sub_582B70((void **)(this+2132))`, `sub_582B70((void **)(this+28))`, `sub_528D80((_DWORD *)(this+4))`, clears `unk_67AB1C = 0`, and tail-calls base cleanup `sub_4F4A90`.
- `disasm 0x00463970`: confirms `mov eax,[esi+24h]`, `CloseHandle`, `mov [esi+24h],0`, `lea ecx,[esi+854h]`, `lea ecx,[esi+1Ch]`, `lea ecx,[esi+4]`, `mov dword ptr unk_67AB1C,0`, and final `jmp sub_4F4A90`.
- `xrefs_to 0x00463970`: `_WinMain@16` call at `0x004f5e44`, cleanup thunk at `0x004f66b0`, and UID0002Q2 wrapper call at `0x004f66c6`.
- `xrefs_to 0x006125e4` and `0x00612604`: constructor stores, destructor stores at `0x00463977`/`0x0046397d`, and Application scalar deleting destructor stores.
- `get_bytes 0x00463960 size 128`: two `0xcc` bytes before target start, exact 84-byte target body, twelve `0xcc` bytes from `0x004639c4` to `0x004639d0`, then successor prologue.
- `get_bytes 0x004f66a0 size 96`: cleanup jump at `0x004f66b0`, secondary adjustor at `0x004f66b5`, three `0xcc` bytes before wrapper start, UID0002Q2 body, and post-target `0xcc`.
- `decompile 0x004f66c0`: compiler wrapper calls `sub_463970(Block)`, checks delete flags, optionally calls `sub_4F4AC0(Block)`, and returns `Block`.
- `decompile 0x00528d80`: `MSGHandler::~MSGHandler` restores previous handler by calling `sub_465650((_DWORD *)unk_67AB1C, this[1])`; therefore `g_pApplication` must remain valid through MSGHandler teardown.
- `decompile 0x00582b70`: StringBase wide release wrapper forwards to `sub_5833A0(this)`.
- `decompile 0x004f4a90`: `LObject` cleanup writes `LObject::vftable`.
- `int_convert`: `84 == 0x54`, `2132 == 0x854`, `2676 == 0x0a74`, `12 == 0x0c`, and reciprocal address/size conversions were verified in-tool.

Failed/unneeded MCP check: an attempted broad `find_bytes` shape using unsupported `start`/`end` parameters was rejected by schema. This did not affect evidence because targeted `get_bytes`, xrefs, disassembly, and decompilation succeeded.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002GZ-01 | UID0002GZ is exactly `sub_463970` at `0x00463970-0x004639c4`, size `0x54` / 84 bytes, with predecessor/successor non-function boundaries and post-target alignment. | High | MCP `lookup_funcs`, `get_bytes`, `int_convert`; target doc current range. | Target IDA Evidence / Scope / Score Rationale; lifecycle child table. | incorporate | applied: target and lifecycle docs include session `279422f0` exact range, size, padding, and boundary proof; validators `000000000808` and `000000000820` returned `ok: 1`. |
| C-0002GZ-02 | UID0002GZ is the ordinary `Application::~Application` destructor, not BaramApp wrapper code, WinMain cleanup code, `MSGHandler`, `StringBase`, `g_pApplication`, or `LObject` ownership. | High | Direct `_WinMain@16` call, BaramApp wrapper delegation, Application vtable stores, constructor pair refs, g_pApplication clear, support docs. | Target Reconstruction Notes; Application class/file docs. | incorporate | applied: target, class, file, and lifecycle docs preserve ordinary Application destructor ownership and rejected owner moves; validators `000000000808`, `000000000811`, `000000000819`, and `000000000820` returned `ok: 1`. |
| C-0002GZ-03 | The body restores Application vtables, closes and zeros `Application+0x24` if non-null, releases StringBase-like members at `+0x854` and `+0x1c`, destroys embedded/default `MSGHandler` at `+0x4`, clears `g_pApplication`, then tail-jumps to `LObject`. | High | MCP decompile/disasm/callees; StringBase/MSGHandler/LObject support docs. | Target Behavior / Touched State; Application class field notes. | incorporate | applied: target behavior/touched-state, class notes, file sync, lifecycle row, and constructor support note carry cleanup order and helper roles; validators `000000000808`, `000000000811`, `000000000819`, `000000000820`, and `000000000821` returned `ok: 1`. |
| C-0002GZ-04 | The `+0x24` field is best documented as a closeable single-instance mutex handle, with preferred inferred source-facing name `m_hSingleInstanceMutex`; exact original spelling remains inferred. | Medium-high | Destructor `CloseHandle` branch; Application startup resource strings and Initialize mutex context; constructor initializes `+0x24` to zero. | Target touched-state; Application class Fields And Globals. | incorporate | applied: target, class, and constructor docs use preferred inferred `m_hSingleInstanceMutex` with spelling caveat; validators `000000000808`, `000000000811`, and `000000000821` returned `ok: 1`. |
| C-0002GZ-05 | `g_pApplication` clear at `0x004639b4` occurs after `MSGHandler::~MSGHandler()` and before the `LObject` tail cleanup. This ordering blocks a normal executable destructor body. | High | MCP disasm/decompile order; MSGHandler destructor uses `g_pApplication`; `LObject` tail jump. | Target Reconstruction Notes / First-Draft C++ Recommendation; Application support docs. | incorporate | applied: target formal rationale plus class/file/lifecycle/constructor support notes document the exact source-order blocker; all five scoped validators returned `ok: 1`. |
| C-0002GZ-06 | Formal executable destructor C++ is not source-ready because a normal destructor body statement executes before compiler-generated member/base teardown; manual subobject/base destructor calls would duplicate generated cleanup. | High | C++ destructor ordering semantics applied to verified binary order; constructor order evidence; MSGHandler and g_pApplication docs. | Target no-code proof; Application class/file/lifecycle notes. | incorporate | applied: target formal block is comment-only and support docs reject executable/manual cleanup bodies; generated `Application.cpp` emits the marker under UID0002GZ. |
| C-0002GZ-07 | The empty-emitter repair should be a formal comment-only no-code marker, not blank C++, not `RECONSTRUCTABLE:FALSE`, not clearing `EMITTER_UIDS`, and not a covered-by BaramApp marker. | High | Generated `Application.cpp` empty-marker line; exact source-authored destructor ownership; UID0002H0 and UID0002Q2 marker policy analogues; current no-code proof. | Target formal C++ block; generated-output expectation. | incorporate | applied: target formal block contains the accepted two-line marker; generated header `validator-command-id: 000000000828`, refreshed `2026-06-29T13:48:11-04:00`, shows UID0002GZ as `Completion:89 | Confidence:92` with no UID0002GZ Empty Emitter Marker match. |
| C-0002GZ-08 | BaramApp scalar deleting destructor UID0002Q2 remains a compiler wrapper over this ordinary destructor; UID0002Q2's marker does not cover UID0002GZ's ordinary cleanup body. | High | Executed B010 report; MCP `decompile 0x004f66c0`; xref `0x004f66c6`; current generated UID0002Q2 marker already present. | Target Caller And Wrapper Context; by-file Application; optional wrapper support only if needed. | incorporate | applied: target and by-file docs record wrapper relationship and rejected covered-by route; optional UID0002Q2 doc was not edited because existing support was sufficient and non-contradictory. |
| C-0002GZ-09 | Metadata should move from `88/91` to `89/92`; owner `00000D`, reconstructable `TRUE`, emitter `00000D`, and blank position remain unchanged. | Medium-high | Current MCP refresh narrows blocker and supplies implementation-ready no-code marker; source declaration blocker remains. | Target header; support rows. | incorporate | applied: target metadata is `COMPLETION:89`, `CONFIDENCE:92`, owner/emitter/reconstructable/blank optional route unchanged; validator `000000000808` reported score updates. |
| C-0002GZ-10 | Generated output currently proves the queue defect: UID0002GZ appears as an Empty Emitter Marker in `auto-generated/NexusTK/app/Application.cpp`. | High | Read-only `Select-String` on generated file line 710. | Target Changes / generated-state note; validator expectation. | incorporate | superseded by applied proof: after validators, read-only generated inspection shows UID0002GZ at lines 14-16 with the formal marker and the UID0002GZ Empty Emitter Marker search returned no matches. |

## Positive Evidence Summary

- Exact function range is compact and complete: `0x00463970-0x004639c4`, size `0x54`.
- The body is semantically complete and all calls/writes are accounted for.
- Application ownership is proven by constructor/destructor vtable parity, direct `_WinMain@16` stack-object destruction, `g_pApplication` lifecycle, Application class/file docs, and the BaramApp wrapper calling into this destructor rather than owning the cleanup.
- `MSGHandler::~MSGHandler` proves the ordering blocker is real: it still calls through `g_pApplication`, so clearing the global before MSGHandler teardown would change behavior.
- The generated empty marker is confirmed current and should be repaired by the formal marker, not by leaving the block blank.

## IDA MCP Facts

Function/range facts:

- `0x00463970 -> sub_463970`, size `0x54`; half-open range `0x00463970-0x004639c4`.
- `0x0046396e` and `0x004639c4` are not functions.
- Successor `0x004639d0 -> sub_4639D0`; bytes between `0x004639c4` and `0x004639d0` are `0xcc` padding.

Data/table/padding facts:

- Application vtable constants `0x006125e4` and `0x00612604` are stored by constructor and destructor paths.
- `g_pApplication` slot is `0x0067ab1c`; UID0002GZ clears it at `0x004639b4`.
- Cleanup thunk area around `0x004f66b0` has `0xcc` padding before/after the thunk and wrapper starts.

Xref facts:

- `0x00463970` has xrefs from `_WinMain@16`, the cleanup thunk `0x004f66b0`, and UID0002Q2 call `0x004f66c6`.
- UID0002Q2 has vtable/thunk route evidence from the executed B010 report and current MCP decompile support.

Negative IDA/source facts:

- No split repair is needed; boundaries and padding are clear.
- No evidence supports moving UID0002GZ to BaramApp, WinMain, MSGHandler, StringBase, `g_pApplication`, or LObject.
- No evidence supports a direct hand-written scalar deleting destructor body in source for this target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00463310-0x0046396e` | UID0002GY `ApplicationConstructor` | Ordinary constructor pair and class-layout lead | TRUE | Application | `89/92` | no-code proof; support for constructor order and `+0x24` init |
| `0x00463970-0x004639c4` | UID0002GZ `ApplicationDestructor` | Ordinary source-level destructor | TRUE | Application | recommend `89/92` | formal no-code marker recommended |
| `0x004639c4-0x004639d0` | padding | alignment | FALSE/ignored | ignored padding ledger | n/a | no source child |
| `0x004f66b0-0x004f66b5` | cleanup thunk | compiler cleanup jump to UID0002GZ | no separate source body | compiler support | documented | no source child |
| `0x004f66b5-0x004f66bd` | UID0002Q1 | BaramApp deleting-destructor adjustor thunk | compiler support | BaramApp | documented | wrapper support |
| `0x004f66c0-0x004f66fb` | UID0002Q2 `BaramAppScalarDeletingDestructor` | compiler scalar deleting destructor wrapper over UID0002GZ | TRUE with marker | BaramApp | `88/92` | already marker-emitting |
| `0x00467230-0x004672b7` | UID000323 `ApplicationScalarDeletingDestructor` | Application scalar deleting destructor variant | TRUE | Application | current support | separate unresolved wrapper/variant, not this target |
| `0x00528d80` | part of UID0001CN `MSGHandler` | ordinary MSGHandler destructor | TRUE | MSGHandler | `88/91` | source-ready support; uses `g_pApplication` |
| `0x00582b70` | part of UID0002RN `StringBase` | wide StringBase release wrapper | TRUE | StringBase | `91/92` | helper dependency |
| `0x0067ab1c-0x0067ab20` | UID000294 `g_pApplication` | Application singleton global | TRUE | Application file | `90/92` | source-ready global declaration |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f5e44` | `_WinMain@16` calls UID0002GZ | stack/local Application object destruction after startup/run/shutdown or early-exit path |
| `0x004f66b0` | cleanup thunk jumps to UID0002GZ | compiler cleanup support, not a new source destructor |
| `0x004f66c6` | UID0002Q2 calls UID0002GZ | BaramApp scalar deleting wrapper delegates ordinary Application cleanup |
| `0x00463989` | import call `CloseHandle` | closes `Application+0x24` when non-null |
| `0x0046399c`, `0x004639a4` | calls `sub_582B70` | releases StringBase-like members at `+0x854` and `+0x1c` |
| `0x004639ac` | calls `sub_528D80` | destroys embedded/default MSGHandler at `+0x4` |
| `0x004639b4` | writes `unk_67AB1C = 0` | clears `g_pApplication` after MSGHandler destructor |
| `0x004639bf` | jumps to `sub_4F4A90` | compiler/base cleanup for LObject |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page already records the correct behavior and current blank-C++ blocker.
- `by-class/Application.md` identifies the class as the process singleton, with `LObject` base plus `MSGHandler` subobject and `g_pApplication` lifecycle.
- `by-file/Application.md` records Application shell ownership, g_pApplication source-ready definition, constructor route, and UID0002Q2 marker route.
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` records constructor order: `LObject` shell, `g_pApplication` publish/fallback, embedded `MSGHandler` construction, Application vtable stores, StringBase initialization, and `+0x24` zero init.
- `by-memory/0x00528d60-0x00528e55.MSGHandler.md` records `MSGHandler::~MSGHandler()` as `g_pApplication->ExchangeMSGHandler(m_previousHandler)`.
- `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md` records `sub_582B70` as the wide StringBase release wrapper.
- `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` records the Application module-global definition and this destructor's clear.

Existing docs that are incomplete or should be refined:

- Target and lifecycle pages still leave UID0002GZ blank, producing the generated empty marker.
- Application class/file docs should document UID0002GZ as a formal no-code marker, not merely an unresolved blank destructor.
- Application class field notes should add the `+0x24` closeable handle as preferred inferred `m_hSingleInstanceMutex`, with exact spelling caveat.
- Lifecycle child table should carry UID0002GZ score/status detail similar to nearby current child rows.

## Ranked Ownership Analysis

### 1. Application / Application.cpp

Evidence for:

- Direct destructor vtable stores use Application vtable constants also used by the constructor.
- `_WinMain@16` destroys the stack Application object through this body.
- `g_pApplication` is constructor-published and destructor-cleared by Application lifecycle.
- BaramApp wrapper delegates into this ordinary destructor rather than owning its side effects.
- Application class/file/lifecycle docs already route this target through `NexusTK/app/Application.cpp`.

Evidence against:

- Exact class declaration layout is still not final enough for executable destructor C++.

Decision: keep as canonical owner/emitter. The layout caveat blocks the body only, not ownership.

### 2. BaramApp

Evidence for:

- UID0002Q2 BaramApp scalar deleting destructor calls UID0002GZ.

Evidence against:

- UID0002Q2 is a compiler wrapper over UID0002GZ. The ordinary body stores Application vtables, clears Application global, and matches Application constructor/destructor pair. BaramApp source should not own this cleanup sequence.

Decision: rejected for UID0002GZ ownership; retain only wrapper cross-reference.

### 3. WinMain / cleanup thunk support

Evidence for:

- `_WinMain@16` directly calls the destructor and the nearby cleanup thunk jumps to it.

Evidence against:

- A caller and compiler cleanup thunk do not own the ordinary class destructor. The source declaration is Application's destructor.

Decision: rejected for ownership; keep as caller/cleanup context.

### 4. MSGHandler, StringBase, g_pApplication, or LObject

Evidence for:

- UID0002GZ calls their cleanup/update helpers.

Evidence against:

- These are subobject/helper/global/base dependencies, not owners of the enclosing Application destructor.

Decision: rejected for ownership. Keep as source-order and helper evidence.

## Source Placement

- Recommended source placement: `NexusTK/app/Application.cpp`, under `Application::~Application` ownership.
- Generated route should stay [UID:00000D] Application -> [UID:0000HG] Application file.
- Rejected placements: BaramApp source, WinMain source, MSGHandler.cpp, StringBase support, g_pApplication global page, and LObject base page.
- Remaining placement uncertainty: none for target ownership. Only the executable destructor body is blocked by class declaration/source-shape uncertainty.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x00463970-0x004639c4`.
- Predecessor boundary: `0x0046396e` is not a function; bytes at `0x0046396e-0x00463970` are `0xcc`.
- Successor boundary: `0x004639c4` is not a function; `0x004639c4-0x004639d0` is `0xcc` alignment; `0x004639d0` starts `sub_4639D0`.
- Related wrapper cluster: `0x004f66b0` is a one-instruction cleanup jump to UID0002GZ; `0x004f66b5` is the BaramApp secondary adjustor; `0x004f66c0` is UID0002Q2 wrapper.
- No new child, split, merge, reclassification, or padding ledger edit is recommended in this report.

## Negative Evidence Summary

- Clearing `EMITTER_UIDS:` is rejected because this is still a source-authored Application destructor and should remain in generated Application output with an explicit marker.
- `RECONSTRUCTABLE:FALSE` is rejected because the range is project code and source-relevant.
- A full executable body is rejected because C++ destructor body statements run before member/base destructors, while the binary clears `g_pApplication` after `MSGHandler::~MSGHandler()` but before `LObject` cleanup.
- A partial body containing only the handle close is rejected because it would under-document and under-emit known destructor side effects.
- Manual calls to StringBase, MSGHandler, or LObject destructors are rejected because they are compiler-generated subobject/base cleanup in a normal class declaration and would risk double destruction if written in source.
- A covered-by BaramApp marker is rejected because UID0002Q2 is the wrapper; UID0002GZ remains the ordinary destructor body that the wrapper calls.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested.

Source-facing names/types to use in docs:

- `Application::~Application` for UID0002GZ.
- Preferred inferred name `m_hSingleInstanceMutex` for `Application+0x24`, with exact original spelling not proven.
- Existing accepted names `m_osVersionLabel` at `+0x854`, `m_processorName` at `+0x1c`, embedded/default `MSGHandler` at `+0x4`, `g_pApplication`, and `LObject` base cleanup.

Items intentionally left unresolved:

- Exact `Application` class base/member declaration, including whether singleton/global cleanup is represented by a base/member helper or compiler-merged cleanup.
- Exact original destructor source body text, if any.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, but only as a formal comment-only no-code marker.
- Eligible for behavioral destructor body: no.
- Third-party import directive: not applicable.

Recommended code:

```cpp
// No first-draft body yet: Application::~Application cleanup ordering depends on the unresolved
// Application base/member declaration for StringBase, MSGHandler, g_pApplication, and LObject teardown.
```

Reason it preserves exact original behavior:

- It emits no executable reconstruction that could misorder `g_pApplication` relative to `MSGHandler` and `LObject` cleanup.
- It keeps the source-owned destructor visible in generated output so the empty marker is not unexplained.
- It avoids hand-writing compiler-generated subobject/base destructor calls.

Reason a behavior body is not safe:

- The binary order is:
  1. optional handle close/clear
  2. StringBase releases
  3. `MSGHandler::~MSGHandler()`
  4. `g_pApplication = 0`
  5. `LObject::~LObject()` tail cleanup
- A normal `Application::~Application()` body statement `g_pApplication = NULL;` would execute before member/base teardown, not between `MSGHandler` and `LObject`.
- `MSGHandler::~MSGHandler()` calls through `g_pApplication`, so moving the clear earlier is not source-equivalent.
- Explicitly writing member/base destructor calls in the body would be decompiler-shaped rather than source-quality and risks duplicate cleanup once class fields/bases are declared.

Exact no-code proof:

- All side effects are known and documented.
- The remaining blocker is not missing behavior; it is source-level destructor factoring across members/bases/globals.
- The marker is the minimal safe formal block that clears the generated empty-emitter defect without inventing unsafe source.

## Final Recommendation

Apply these changes only after supervisor accepts this report:

- Target UID0002GZ: set `COMPLETION:89`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank `EMITTER_POSITION_OPTIONAL`; insert the exact formal marker.
- Preserve and refresh current MCP session `279422f0` evidence at report-level detail.
- Add the precise no-code proof and rejected-body alternatives.
- Sync Application class/file/lifecycle/constructor support docs as listed below.
- Do not edit manual coverage reports or generated files.

## Recommended Target Doc Changes

Target path: `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`

Exact facts to incorporate:

- Current MCP session `279422f0` health and exact lookup/decompile/disasm/callee/xref/byte/int-convert facts.
- Exact range `0x00463970-0x004639c4`, size `0x54` / 84.
- Predecessor `0x0046396e` and successor `0x004639c4` not functions; post-target padding through `0x004639d0`.
- Behavior sequence with instruction addresses and helper names:
  - vtable stores `0x00463977` and `0x0046397d`
  - `Application+0x24` close/zero branch at `0x00463984-0x0046398f`
  - StringBase release calls at `0x0046399c` and `0x004639a4`
  - `MSGHandler::~MSGHandler` call at `0x004639ac`
  - `g_pApplication` clear at `0x004639b4`
  - `LObject` tail cleanup at `0x004639bf`
- Caller/wrapper context: `_WinMain@16` at `0x004f5e44`, cleanup thunk `0x004f66b0`, UID0002Q2 call `0x004f66c6`, and UID0002Q2 wrapper marker distinction.
- Generated empty-marker cause and exact formal no-code marker.
- Correct source-shape caveat: `g_pApplication` clear order is after MSGHandler teardown and before LObject cleanup, so a normal executable destructor body is blocked by class declaration/factoring, not by unknown side effects.

Metadata/C++ changes:

- `COMPLETION:89`
- `CONFIDENCE:92`
- owner/emitter/reconstructable unchanged
- formal block exactly:

```cpp
// No first-draft body yet: Application::~Application cleanup ordering depends on the unresolved
// Application base/member declaration for StringBase, MSGHandler, g_pApplication, and LObject teardown.
```

## Recommended Support Doc Changes

Support path: `by-class/Application.md`

- Update UID0002GZ method row to `~Application` at recommended `89/92`, formal comment-only no-code marker, exact cleanup order, and source-order caveat.
- Add field/global note for `Application+0x24` as closeable single-instance mutex handle, preferred inferred name `m_hSingleInstanceMutex`, initialized zero by constructor and closed/zeroed by destructor.
- Preserve `LObject` base plus `MSGHandler` subobject wording and state that the broad class C++ remains blank until class declaration/base/member cleanup order is resolved.

Support path: `by-file/Application.md`

- Add B009 sync note that UID0002GZ should no longer be an unresolved empty marker after implementation; it should emit the formal no-code marker through `NexusTK/app/Application.cpp`.
- Preserve unchanged Application owner/emitter route and BaramApp wrapper distinction.
- Add generated-output expectation: UID0002GZ should show `Completion:89 | Confidence:92` and marker text, not `Empty Emitter Marker`.

Support path: `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`

- Update child/status row for UID0002GZ to recommended `89/92` and formal no-code marker status.
- Add current MCP cleanup order facts and post-target padding `0x004639c4-0x004639d0`.
- Keep the aggregate no-code; do not add monolithic lifecycle C++.

Support path: `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`

- Add a narrow support note that UID0002GZ no-code proof uses constructor order: `LObject` shell, `g_pApplication` publish/fallback at `0x00463368`/`0x0046336f`, embedded `MSGHandler` constructor at `Application+0x4`, Application vtable stores, StringBase member setup, and `Application+0x24` zero initialization.
- No score/C++ change required unless supervisor chooses to refresh support score wording.

Support path: `by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md`

- No required edit if the current B010 implementation text is already sufficient. It already records UID0002Q2 as a compiler wrapper calling UID0002GZ and emitting a marker.
- If edited for cross-reference freshness, validate it and preserve B010's accepted marker disposition.

Support path: `by-memory/0x00528d60-0x00528e55.MSGHandler.md`

- No required edit. Current docs already prove `MSGHandler::~MSGHandler()` restores previous handler through `g_pApplication->ExchangeMSGHandler(m_previousHandler)`.

Support path: `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`

- No required edit. Current docs already identify `sub_582B70` as StringBase release/destructor support.

Support path: `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`

- No required edit. Current docs already record this destructor's clear and source-ready Application module-global definition. The target should reference that page rather than duplicate global C++.

Support path: `by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md`

- No required edit for this callback. Treat as related parity context only; do not broaden UID0002GZ into the scalar deleting destructor variant.

## Score And Metadata Recommendation

Current target metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- blank optional position
- blank formal C++

Recommended target metadata:

- `COMPLETION:89`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- blank optional position
- formal comment-only no-code marker

Score rationale:

- Completion rises by one because the empty-emitter condition now has an implementation-ready formal marker and exact no-code proof, rather than a blank block with broad blocker language.
- Confidence rises by one because current MCP session `279422f0` reconfirmed the exact range, bytes, side effects, helper roles, xrefs, and generated queue state.
- Score does not rise higher because executable destructor C++ remains blocked by unresolved `Application` base/member declaration and cleanup factoring.

Score-improvement attempt:

- Field names: checked Application class/file/constructor/startup docs and accepted `m_hSingleInstanceMutex` as preferred inferred name only; exact original spelling remains a confidence cap.
- Helper roles: checked current StringBase and MSGHandler support; helper roles are resolved well enough for docs, but they increase the source-order blocker for an executable body.
- Owner/source route: checked WinMain, BaramApp wrapper, Application class/file/lifecycle, constructor pair, vtable refs; owner is resolved.
- Generated-output defect: checked current `Application.cpp`; defect is real and marker repair is ready.
- Body readiness: tested normal destructor body and manual cleanup alternatives against verified order; rejected all executable bodies as source-unsafe.

## Open Questions With Attempted Resolution

Open question: exact original member name for `Application+0x24`.

- Evidence checked: destructor `CloseHandle`, constructor zero init, Application startup resource strings and mutex behavior.
- Best supported resolution: document as closeable single-instance mutex handle; preferred inferred name `m_hSingleInstanceMutex`.
- Remaining uncertainty: exact original spelling is not recoverable from current evidence and should remain a confidence cap only.

Open question: exact destructor source shape for `g_pApplication` clear.

- Evidence checked: UID0002GZ disasm/decompile, constructor order, MSGHandler destructor, g_pApplication report, Application class/file docs, singleton analogues.
- Best supported resolution: source cleanup ordering depends on unresolved `Application` declaration/factoring. Do not write a body.
- Remaining uncertainty: future class-layout proof may show a singleton base/member/helper that accounts for the clear between `MSGHandler` and `LObject`.

Open question: should UID0002GZ be covered by UID0002Q2 marker?

- Evidence checked: UID0002Q2 executed report and current MCP wrapper decompile.
- Resolution: no. UID0002Q2 is the compiler wrapper over UID0002GZ. UID0002GZ remains ordinary source destructor ownership and needs its own marker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or supervisor-owned tracker edit is recommended from this B009 report. The implementation callback should update by-* docs only and let scoped validators refresh generated/validator-owned output. If supervisor later wants a manual coverage row, it should derive from the by-* source docs after acceptance.

## Follow-Up Actions

Supervisor actions:

- Review and accept/reject the no-code-marker disposition and score recommendation.
- If accepted, issue implementation callback for the target and listed support docs.

B009 implementation actions after acceptance only:

- Take short leases for files immediately edited.
- Apply target/support doc changes at report-level detail.
- Run scoped validators listed below.
- Inspect generated `auto-generated/NexusTK/app/Application.cpp` read-only for UID0002GZ marker/freshness.
- Update this report ledger/checklist with proof.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact Application class declaration/base/member factoring and exact `+0x24` original member spelling.

## Validator Results

- Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002GZ-ApplicationDestructor-empty-emitter-source-quality-removed.md](0002GZ-ApplicationDestructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Target validator: command ID `000000000808`, timestamp `2026-06-29T13:44:48-04:00`, `ok: 1`; reported `completion_update 0002GZ ... 89`, `confidence_update 0002GZ ... 92`, registry blank-to-block update, UID link insert, and completed generated refresh.
- Class validator: command ID `000000000811`, timestamp `2026-06-29T13:45:10-04:00`, `ok: 1`; generated refresh completed.
- File validator: command ID `000000000819`, timestamp `2026-06-29T13:46:29-04:00`, `ok: 1`; generated refresh completed.
- Lifecycle support validator: command ID `000000000820`, timestamp `2026-06-29T13:46:29-04:00`, `ok: 1`; generated refresh deferred.
- Constructor support validator: command ID `000000000821`, timestamp `2026-06-29T13:46:30-04:00`, `ok: 1`; generated refresh deferred.
- Known unrelated validator noise remained in the file/class/file generated-refresh runs: stale registry entries for already-missing files, missing memory coverage metadata for already-missing files, and unrelated `autogen_emitter_has_no_code` parent/child markers. No UID0002GZ blocker remained.
- MCP blockers: none during implementation; the accepted report used current MCP session `279422f0`, and no new MCP-dependent research was required.
- Optional support validators: none run because optional UID0002Q2, MSGHandler, StringBase, g_pApplication, and UID000323 docs were not edited.

Generated-output proof after accepted implementation:

- Read-only generated inspection of `auto-generated/NexusTK/app/Application.cpp` shows header `validator-command-id: 000000000828`, `validator-refreshed-at: 2026-06-29T13:48:11-04:00`, newer than the final `--wait-generated` scoped validator.
- UID0002GZ now appears as `// UID:0002GZ | by-memory/0x00463970-0x004639c4.ApplicationDestructor.md | Completion:89 | Confidence:92`.
- The accepted marker is emitted immediately below UID0002GZ:

```cpp
// No first-draft body yet: Application::~Application cleanup ordering depends on the unresolved
// Application base/member declaration for StringBase, MSGHandler, g_pApplication, and LObject teardown.
```

- A read-only search for `UID:0002GZ.*Empty Emitter Marker|Empty Emitter Marker.*UID:0002GZ` returned no matches.

## Changed Files

Report-only pass:

- Created: `tools/leaser/Agents/Agent-B009/research/0002GZ-ApplicationDestructor-empty-emitter-source-quality.md`
- Modified outside this report: none during report-only phase.
- Renamed: none.
- Leases: none taken; report-only pass.
- Validators: none run; report-only pass.

Implementation callback pass:

- Modified: `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`
- Modified: `by-class/Application.md`
- Modified: `by-file/Application.md`
- Modified: `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- Modified: `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- Modified: `tools/leaser/Agents/Agent-B009/research/0002GZ-ApplicationDestructor-empty-emitter-source-quality.md`
- Optional support docs not edited: UID0002Q2 BaramApp scalar deleting wrapper, MSGHandler, StringBase, g_pApplication, and UID000323 were already non-contradictory and did not require narrow cross-reference edits.
- Leases: B009 leased the five required by-* docs immediately before editing and released them after the validator/generated-output batch; `python .\leaser.py B009 unlease` followed by current lease search reported `B009: No active leases`.
- Validators: scoped command IDs `000000000808`, `000000000811`, `000000000819`, `000000000820`, and `000000000821`; all returned `ok: 1`.
- Generated output: inspected read-only only; refreshed `Application.cpp` header is `validator-command-id: 000000000828`, `validator-refreshed-at: 2026-06-29T13:48:11-04:00`.

Report execution: not run by B009; user explicitly instructed not to run `execute_report`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: completed; supervisor accepted UID0002GZ for implementation callback.
- [x] Target/support docs to update: required target `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`; required support `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, and `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`; optional cross-reference edits were reviewed as unnecessary because no contradictions required editing.
- [x] Current target state and actual evidence checked recorded: current MCP session `279422f0`, health OK, lookup/decompile/disasm/callees/xrefs/bytes/int-convert facts, target/support docs, old reports, and generated empty-marker state are recorded above and incorporated into docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger rows C-0002GZ-01 through C-0002GZ-10 are now applied/superseded with proof.
- [x] Metadata/score changes to apply: target `88/91 -> 89/92`, confirmed by validator `000000000808`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed no-improvement proof: executable destructor body rejected by verified source-order blocker; formal marker applied.
- [x] Owner/emitter/reconstructable changes to apply: none; target keeps owner/emitter [UID:00000D], `RECONSTRUCTABLE:TRUE`, blank optional position.
- [x] Split/rename/new-child changes to apply: none; range/padding proof preserved.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement remains Application.cpp; no IDA DB edits.
- [x] First-draft C++ or no-code proof to apply: exact comment-only marker applied in target formal block and generated output.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: applied to the five required target/support docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old blank-C++ broad blocker narrowed; rejected body, partial body, manual subobject/base destruction, owner move, clearing emitter, reconstructable false, and BaramApp covered-by marker are preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: none used as authority; generated output used only read-only.
- [x] Open questions to close or document as evidence-backed unresolved: exact `+0x24` name and Application declaration/factoring documented as unresolved score caps.
- [x] Validators to run: scoped validators completed with command IDs `000000000808`, `000000000811`, `000000000819`, `000000000820`, and `000000000821`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated Application output refreshed through validators; no manual coverage/tracker text edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator and inspected read-only.
- [x] Remaining unapplied accepted items listed with exact blocker: none; optional support docs were not edited because no contradictions required edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002GZ-ApplicationDestructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002GZ-ApplicationDestructor-empty-emitter-source-quality.md","timestamp":"2026-06-29T14:01:02","uid":"0002GZ"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GZ-ApplicationDestructor-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002GZ-ApplicationDestructor-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
