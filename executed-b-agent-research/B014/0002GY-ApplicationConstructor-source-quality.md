** TARGET-REPORT-UID:0002GY **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002GY] ApplicationConstructor source-quality report

## Report Status

- Agent: B014
- Assignment id: `B014-implement-0002GY-application-constructor-source-quality-20260626`
- Mode: implementation callback applied; accepted report details were incorporated into the target/support by-* docs, formal constructor C++ remains blank, scoped validators were run, and no generated files, coverage reports, or IDA DB files were manually edited.
- Target: [UID:0002GY] `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- Required report path: `tools/leaser/Agents/Agent-B014/research/0002GY-ApplicationConstructor-source-quality.md`
- Current target metadata after implementation: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, formal C++ blank.
- Implementation result: target/support docs carry the accepted source-quality details; the constructor formal C++ block remains blank with the target-specific no-code proof below.

## MCP Evidence

IDA MCP was mandatory and was used. No fallback-only report was produced.

Current resume availability on 2026-06-26:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- `tools/list` request `b014-tools-list-0002gy-retry` returned 65 tools.
- `idb_list` request `b014-idb-list-0002gy-retry` returned active session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, backend `worker`, PID/worker PID `26892`, `is_active:true`, and `is_analyzing:false`.
- `server_health` request `b014-health-0002gy-retry` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.
- Corrected `lookup_funcs` request `b014-lookup-0002gy-boundaries-corrected` returned:
  - `0x00463310 -> Application__Constructor`, size `0x65e`;
  - `0x0046396e -> Not a function`;
  - `0x00463970 -> sub_463970`, size `0x54`;
  - `0x004f5c80 -> _WinMain@16`, size `0x297`;
  - `0x004f5f20 -> Not a function`.

Preserved live MCP evidence from this assignment's pre-pause state was re-used after the current health check:

- `analyze_function 0x00463310` on session `80de0a67` reported size `0x65e` / 1630 bytes, 68 basic blocks, cyclomatic complexity 20, and code xrefs from `_WinMain@16` plus the raw BaramApp forwarding body.
- Decompile/disassembly showed the constructor sequence: base `LObject` shell construction, `g_pApplication` publish/fallback clear, embedded `MSGHandler` construction, Application vtable writes, StringBase-style member initialization, timing and OS-version global setup, Application field writes, CPU registry read, startup path copies, DAT manager construction, duplicated executable-directory/registry update blocks, `DATA/BARAMST.DAT` fatal path, range-check exits, normal return, and constructor-unwind fragments.
- Byte reads confirmed `0x0046396e-0x00463970` is two `0xcc` padding bytes before the destructor, and raw UTF-16 operands decode to `.DAT`, `.SND`, `TestServer`, `Software\Nexon`, `Barampath`, and `DATA/BARAMST.DAT`.
- Xref checks confirmed `0x00463310` has two code call sites, `0x004f4a80` has broad constructor refs including `0x00463352`, `0x00528d60` is called by this constructor at `0x00463380`, `0x0049bd30` is called by this constructor at `0x00463655`, `0x00612730` has only the constructor store xref at `0x00463518`, and `0x0067ab1c` includes constructor publish/fallback writes at `0x00463368` and `0x0046336f`.

One initial local PowerShell MCP wrapper call used the reserved `$args` variable and sent the wrong JSON shape to `idb_list`; a later lookup used `addrs` instead of the current `queries` schema. Both were client call-shape errors after `tools/list` had already succeeded, and corrected MCP calls completed. They are not evidence of MCP unavailability.

## Current State Reviewed

I reviewed the target page, Application class/file/lifecycle docs, and support pages for current source-quality state:

- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `by-class/Application.md`
- `by-file/Application.md`
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md`
- `by-memory/0x00528d60-0x00528e55.MSGHandler.md`
- `by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md`
- `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
- `by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md`
- `by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md`
- `by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md`
- current and historical Agent reports/notes mentioning `0002GY`, Application lifecycle, `g_pApplication`, and constructor field naming.

The generated tracker/coverage state is stale in places: older generated rows still mention the pre-refresh `76/89` style state while the target page is already `86/91`. Do not edit generated or coverage files in this callback; scoped validators/generator flow should refresh them later if the supervisor executes the accepted by-* edits.

## Resolved Constructor Shape

The old target wording says final C++ is blocked by broad unresolved field/helper names. That wording is stale after the recent Application and helper passes. The best current source-facing shape is:

- `sub_4F4A80` is the `LObject` base constructor shell. It writes the `LObject` vtable and is used by many constructors, including this one at `0x00463352`. Source reconstruction should model it as base construction, not as a manual helper call in the constructor body.
- `sub_528D60` is `MSGHandler::MSGHandler` for the embedded/default handler subobject at Application offset `+0x4`. The Application constructor later stores `this + 0x4` into `Application+0x844`, best source-facing `m_activeMessageHandler`.
- The Application vtable writes at `this+0` and `this+4` are compiler output from constructing the complete Application object with the embedded/secondary handler view. They should be documented, not handwritten in formal C++.
- `sub_582B20` is `InitializeEmptyWide`; it initializes wide StringBase-style members including the CPU processor-name string owner around `Application+0x1c` and the per-object OS label member at `Application+0x854`.
- `sub_582D20` is `AssignWideLiteral`; in this constructor it assigns the CPU `ProcessorNameString` read from the registry to the `Application+0x1c` string owner and assigns `TestServer` into the server display/name buffer at `Application+0x858`.
- `sub_49BD30` is `DATFileMgr::DATFileMgr`. The Application constructor allocates 8 bytes, calls the DAT manager constructor, and the DAT manager publishes `g_pDATFileMgr`; there is no Application member store for the allocation result.
- The path buffers are fixed 256-wide-character buffers:
  - `Application+0x28`: world/server name copied from the `Source` constructor argument;
  - `Application+0x228`: player/base name copied from the third constructor argument;
  - `Application+0x428`: DAT filename, third argument plus `.DAT`;
  - `Application+0x628`: SND filename, third argument plus `.SND`;
  - `Application+0x858`: initialized from `TestServer`.
- The source-facing field names already supported elsewhere should be used in documentation:
  - `m_hInstance` at `+0x20`;
  - `m_hMainWnd` at `+0x828`;
  - `m_hLoadingDlg` at `+0x82c`;
  - `m_isRunning` at `+0x838`;
  - `m_exitRequested` at `+0x83a`;
  - `m_hShutdownEvent` at `+0x83c`;
  - `m_activeMessageHandler` at `+0x844`;
  - `m_osVersionLabel` at `+0x854`;
  - `m_clientVersionLowWord` at `+0x842` and `m_clientVersionCode` at `+0x850`, with the writer relationship owned by `Application::ValidateLicense`, not by constructor logic alone.

The constructor starts enough of the object layout to document it at report-level detail, but it does not yet have a safe formal source body.

## Behavior To Carry Into Target Docs

The target page should keep and sharpen these exact behavior points:

- The constructor range is exactly `0x00463310-0x0046396e`; `0x0046396e-0x00463970` is padding; the destructor starts at `0x00463970`.
- Direct callers are `_WinMain@16` at `0x004f5cca` and the raw/no-function BaramApp forwarding body at `0x004f5f33`. WinMain and BaramApp are callers/forwarders, not owners.
- The singleton global `g_pApplication` is a module global emitted through the Application file. The constructor publishes `this` at `0x00463368` or clears the slot at `0x0046336f`; the exact data page owns the declaration.
- Construction order is source-significant: base shell, singleton publish, embedded `MSGHandler`, Application vtable writes, StringBase-style members, screen defaults, timing globals, OS-version globals, object state fields, OS detection, processor-name string, fixed startup buffers, DAT manager singleton, path/registry updates, startup DAT check.
- The duplicated command-line/path/registry blocks parse `GetCommandLineW`, choose a bounded executable directory, call the dispatch-table `SetCurrentDirectoryW`, call `GetModuleHandleA(NULL)` and `GetModuleFileNameW`, create/open `HKCU\Software\Nexon`, and write the `Barampath` `REG_SZ` value. Current target/file docs should not preserve older `NexusTK.bin`, `\Data\`, `\Save\`, or `temp` source-looking claims for this constructor.
- The startup DAT check calls `ForwardLoadDATFileIndex` on `DATA/BARAMST.DAT`; failure formats `File not found : %s` and calls the Application fatal/error helper at `0x00465cb0`.
- Compiler-generated constructor-unwind fragments at `0x005fa5c0-0x005fa646` are evidence for subobject/allocation lifetime, but they are not source code to paste into this page.

## Target-Specific No-Code Proof

Do not add a formal constructor C++ body in the implementation callback. This is not because the old names are uninvestigated; the major names are now resolved or narrowed. The exact reason is that the remaining unresolved items affect source shape, declaration layout, and generated unwind output for a large constructor.

Current no-code proof:

- The constructor is a 1630-byte function with 68 basic blocks and complexity 20. It is not a small accessor or isolated leaf where an inferred field name can safely complete a body.
- The member declaration layout needed to regenerate the constructor is not final. `LObject`, embedded `MSGHandler`, two StringBase-style fields, fixed wide buffers, scalar fields, and the `+0xa70` pointer/table slot all participate in construction order and unwind state. A formal body without a final class layout would either omit construction semantics or duplicate compiler output.
- `Application+0xa70` is still not source-identifiable. Live evidence shows the constructor stores `0x00612730` at `0x00463518`; xrefs to `0x00612730` show only that constructor store; raw bytes there are not a string and no current support doc proves a defensible member/source name. This is an audited no-improvement point, not an unchased blocker.
- `ApplicationOsVersionState` is itself an assigned no-code data page at `88/91`. The constructor writes `OSVERSIONINFOW` and a compact label buffer, but the final source grouping could be separate statics or an environment-state struct with sentinel initialization. A constructor body would have to choose one.
- The duplicated command-line/path/registry blocks are exact binary behavior, but no source-level helper boundary or original helper name is recovered. A formal body must choose between literal duplication, a local helper, a macro-like helper, or a compiler/inlining artifact. The current evidence proves behavior, not original source factoring.
- The StringBase helper identities are resolved, but the Application member facade/type spelling is still documented as StringBase-style rather than final Application header text. That is sufficient for docs and field-role evidence, not for a complete constructor formal block.
- The DAT manager allocation is now understood as construction of a global singleton, but the source expression and exception/unwind relationship depend on the project allocation wrapper and DAT manager declaration policy. Hand-pasting the decompiler sequence would be lower quality than a blank formal block with exact evidence.

Therefore the accepted implementation should replace stale broad "field/helper-name audit" wording with this narrower no-code proof and leave `RECONSTRUCTION_CPP CODE` empty for [UID:0002GY].

## Rejected Alternatives

- Reject a decompiler-to-C++ rewrite for this constructor. It would preserve vtable writes, raw offsets, dispatch slots, and EH state artifacts as source, which is not project source-quality reconstruction.
- Reject moving the constructor to `WinMain` or `BaramApp`. `_WinMain@16` stack-constructs/calls it, and the raw BaramApp body forwards to it, but the object fields, singleton publish, and lifecycle ownership are Application-owned.
- Reject moving the embedded message-handler construction to the `MSGHandler` page. `MSGHandler` owns its class constructor/destructor/dispatch, while Application owns the containing object construction and `m_activeMessageHandler` field initialization.
- Reject moving the DAT manager allocation/store to an Application member. The allocation path calls `DATFileMgr::DATFileMgr`, whose constructor publishes `g_pDATFileMgr`; no Application field receives the allocated pointer.
- Reject class-static `g_pApplication` wording. The accepted global page emits a module-global Application pointer through the Application file; consumers use a process global.
- Reject interpreting `GetVersionMajor`/`GetVersionMinor` as raw `VS_FIXEDFILEINFO` major/minor fields. Current docs prove caller-compatible version-component names with `m_clientVersionCode` and `m_clientVersionLowWord`.
- Reject retaining `NexusTK.bin` or unrelated generated Wave2 path claims in constructor support text. Live constructor evidence uses `GetModuleHandleA(NULL)`, `GetModuleFileNameW`, `.DAT`, `.SND`, `TestServer`, `Software\Nexon`, `Barampath`, and `DATA/BARAMST.DAT`.

## Score And Metadata Disposition

Recommended target metadata:

- `COMPLETION:89`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- `RECONSTRUCTION_CPP CODE`: keep blank.

Why `89/92`:

- Completion should move from `86` to `89` because this pass resolves the main old blocker categories: base constructor identity, embedded `MSGHandler` role, StringBase helper names, DAT manager constructor role, source-facing Application field names, version-field relationship, caller/owner route, stale generated/path claims, and a precise no-code proof.
- Completion should not move to `90+` because the constructor still cannot carry formal C++ and still has source-shape blockers that affect a real body: `+0xa70` identity, OS-version global declaration shape, Application class declaration/member facade, duplicated registry/path factoring, and EH/unwind-compatible construction order.
- Confidence should move from `91` to `92` because current session `80de0a67` revalidated MCP health and boundary facts, while multiple accepted support reports now converge on field/helper roles. It should remain below `95` because original source layout and declaration spellings are still not symbol-proven.

No coverage/manual/generated file edits are part of this report-only phase.

## Implementation Checklist

Implementation callback applied on 2026-06-26. Checked items below are backed by the by-* edits and validator proof recorded here.

- [x] Target `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`: raised header to `89/92`; owner/emitter/reconstructable unchanged; formal C++ remains blank.
  - Proof: validator command `000000003241`, timestamp `2026-06-26T19:48:50-04:00`, `ok: 1`, `completion_update 0002GY ... 89`, `confidence_update 0002GY ... 92`, `canonical_owner_update ... 00000D`.
- [x] Target item summary: replaced stale "field/helper-name audit" wording with resolved helper/field wording and target-specific no-code proof.
  - Proof: target summary now states source-facing field/helper names are resolved where defensible while formal C++ stays blank for class layout, raw `Application+0xa70`, and constructor-unwind/source-helper uncertainty.
- [x] Target constructor phases: updated `sub_4F4A80` to `LObject` base constructor shell; `sub_528D60` to embedded `MSGHandler::MSGHandler`; `sub_582B20`/`sub_582D20` to `InitializeEmptyWide`/`AssignWideLiteral`; `sub_49BD30` to `DATFileMgr::DATFileMgr`.
- [x] Target touched-state table: used current source-facing field names for `m_hInstance`, `m_hMainWnd`, `m_hLoadingDlg`, `m_isRunning`, `m_exitRequested`, `m_hShutdownEvent`, `m_activeMessageHandler`, `m_osVersionLabel`, fixed startup buffers, `m_clientVersionLowWord`, and `m_clientVersionCode`; kept `+0xa70` unresolved with one-xref proof.
- [x] Target behavior/evidence: added current session `80de0a67` boundary proof, caller set, padding boundary, duplicated path/registry behavior, DAT fatal path, and constructor-unwind/no-code evidence.
- [x] Target reconstruction notes: removed the old broad "names remain unresolved" rationale and added the target-specific no-code proof from this report.
- [x] Target score rationale/change log: documented the `86/91 -> 89/92` movement and why no formal C++ is authorized.
- [x] `by-class/Application.md`: added B014 constructor source-quality sync note; method/fields now reflect resolved constructor dependencies and the no-code constructor cap without weakening source-ready accessor children.
  - Proof: validator command `000000003243`, timestamp `2026-06-26T19:48:50-04:00`, `ok: 1`. Pre-existing missing-reference warnings remain for stale `ApplicationCopyProcessorName` links.
- [x] `by-file/Application.md`: adjusted constructor support under `NexusTK/app/Application.cpp`; replaced stale `NexusTK.bin` constructor wording with observed `GetModuleHandleA(NULL)`/`GetModuleFileNameW` executable-path behavior; preserved `g_pApplication` as a module-global Application file definition.
  - Proof: validator command `000000003239`, timestamp `2026-06-26T19:48:49-04:00`, `ok: 1`, `reference_index_add 0002GY by-file/Application.md`. Pre-existing missing-reference warnings remain for stale `ApplicationCopyProcessorName`, `ImageLib`, and missing `0003OY` validator entry.
- [x] `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`: updated the child row/status for [UID:0002GY] to `89/92`, with constructor no-code proof and unchanged aggregate no-code disposition.
  - Proof: validator command `000000003240`, timestamp `2026-06-26T19:48:49-04:00`, `ok: 1`. Pre-existing missing-reference warnings remain for stale `ApplicationCopyProcessorName` links.
- [x] Optional support cleanup: corrected `by-memory/0x00528d60-0x00528e55.MSGHandler.md` item-summary wording that still said "blank final C++" even though its formal C++ block is populated; ownership unchanged.
  - Proof: validator command `000000003242`, timestamp `2026-06-26T19:48:50-04:00`, `ok: 1`, `canonical_owner_update ... 00008S`. Pre-existing missing-reference warnings remain for `0001CO`, `0002GL`, and missing `00040O` validator entry.
- [x] Did not edit `by-memory/-coverage-report.md`, any `-coverage-report.md`, generated/project-level reports, IDA DB, or generated `auto-generated/NexusTK/app/Application.cpp` manually.
- [x] During implementation callback only: leased exactly the by-* files being edited immediately and checked lease state after the edit/validator batch.
  - Proof: B014 lease acquisition succeeded for the five edited by-* files before edits. Explicit unlease attempt at `2026-06-26T19:50:07.5643955-04:00` returned `Rejected[No active lease]` for all five files; `tools/leaser/Agents/current_leases.md` read immediately afterward showed no B014 active leases.
- [x] During implementation callback only: ran scoped validators from `source-3/project-documentation` for every edited by-* file and recorded command IDs/timestamps/results above.

## Implementation Closeout

Implementation callback is ready for supervisor verification. Changed docs are the exact constructor target, Application class support page, Application file support page, Application lifecycle aggregate, optional MSGHandler support summary, and this report checklist.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002GY-ApplicationConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002GY-ApplicationConstructor-source-quality.md","timestamp":"2026-06-26T19:54:56","uid":"0002GY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
