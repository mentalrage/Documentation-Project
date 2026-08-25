*** UID:0000II | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Crasher

## Status

- Confidence: very strong for class/global/method ownership, exact source order, two-base source shape, and standalone diagnostics-file placement.
- Proposed module: `platform/Crasher.cpp`
- Historical generated source: `source-3/simroot_v2/class_Crasher.cpp`; this decompiler-shaped artifact is non-authoritative and superseded by the formal UID routes below.
- Main class: [UID:00003A][Crasher](by-class/Crasher.md)
- Main address doc: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- Evidence basis: existing class/memory docs plus IDA MCP lookup/decompile/xref checks refreshed on 2026-06-06.

## Hypothesis

`Crasher` is a tiny diagnostic companion to [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). It derives directly from [UID:0000MC][Pane](by-file/Pane.md) and the storage-free shared `Singleton<Crasher>` template. Its tertiary `OnTimer(int,int,int)` override deliberately raises a null-pointer crash after calling the active exception handler's inline `SetSkipCrashReport(true)` accessor.

Keep this as a separate `platform/Crasher.cpp` companion. The class has real RTTI/vtables, a [UID:0000MC][Pane](by-file/Pane.md) base, a distinct singleton [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md), and its own constructor/destructor/callback bodies, so current evidence does not justify folding it into the `ExceptionHandler` class. Its only observed startup construction is from [UID:0000HG][Application](by-file/Application.md), and its deliberate crash path depends on [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md).

## Likely Contents

- [UID:00003A][Crasher](by-class/Crasher.md), emitter position `0`: `Crasher.h`/`ExceptionHandler.h` include preamble and the guarded class header.
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md), emitter position `1`: sole zero definition and explicit `Singleton<Crasher>` constructor/destructor specializations.
- references to [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- constructor at `0x0049bae0`
- ordinary destructor at `0x0049bb30`
- source-authored `OnTimer` override at `0x0049bb60` (historical behavior alias `TriggerCrash`)
- destructor adjustor thunks at `0x0049bb78` and `0x0049bb83`
- scalar deleting destructor at `0x0049bb90`
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md), emitter position `2`: empty derived lifecycle bodies and exact `OnTimer` source body. ABI thunks remain non-source.

## Evidence

- IDA confirms `Crasher` vtables at `0x0061885c`, `0x006188a8`, and `0x006188d8`, plus RTTI for both `Crasher` and `Singleton<Crasher>`.
- `Application::Initialize` constructs a `0xf8` byte `Crasher` object at `0x004646ec`.
- `Crasher::Crasher` calls `Pane::Pane(this, 0)`, writes [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) at `0x0067ab38`, and installs three vtable views at object offsets `0x0`, `0xa0`, and `0xa4`.
- `Crasher::OnTimer` calls inline `g_pCrashTarget->SetSkipCrashReport(true)`, whose body is the exact byte write `[g_pCrashTarget + 4] = 1`, then writes marker `0x6675636b` through address zero and returns `1`.
- Raw RTTI contains direct bases `Pane` and `Singleton<Crasher>`; the Singleton BCD PMD is `{0xf8,-1,0}` on a `0xf8`-byte complete object. This proves empty-base optimization and explains the complete-pointer adjustment in class-specific specialization lowering.
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) checks the same byte at `[g_pCrashTarget + 4]`; when it is `1`, the filter skips the normal report-helper path.
- 2026-06-06 IDA MCP recheck confirms the exact function bodies at `0x0049bae0`, `0x0049bb30`, `0x0049bb60`, `0x0049bb78`, `0x0049bb83`, and `0x0049bb90`; direct callers list only the constructor call from `Application::Initialize` at `0x004646ec`, while `TriggerCrash` and the scalar deleting destructor have no direct callsites because they are vtable-driven.
- The same xref pass keeps [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) ownership local to Application cleanup plus Crasher construction/destruction, while [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) has broader exception/timing/filter references. This supports keeping the deliberate-crash pane as its own `platform/Crasher.cpp` companion rather than merging its singleton/vtable code into `ExceptionHandler.cpp` without further source-order evidence.
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) now records the stronger boundary, vtable, global-xref, and Application construction/cleanup evidence; this file page should inherit that evidence for source ownership while leaving final C++ blank.
- Historical 2026-06-07 A006 IDA MCP output reported [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) / `dword_67AB38` as a four-byte `.data` singleton initialized to `0xffffffff`, with exactly four direct data xrefs: Application cleanup read at `0x00464c4e`, constructor publish at `0x0049bb04`, ordinary destructor clear at `0x0049bb4a`, and scalar deleting destructor clear at `0x0049bbb0`. The current raw PE/IDB four-byte read is `00 00 00 00` and supersedes that initializer value; the four xrefs and lifecycle functions remain valid historical evidence, not initializer authority.
- The same pass confirms the relevant function objects: Application cleanup `0x00464a60-0x00464cc1`, `Crasher::Crasher` `0x0049bae0-0x0049bb2a`, ordinary destructor `0x0049bb30-0x0049bb59`, and scalar deleting destructor `0x0049bb90-0x0049bbef`. This closes the singleton ownership loop enough for parent-gated memory assignment while preserving the open virtual trigger/source-split caveats.
- 2026-06-17 B001 source-quality reanalysis keeps this file as the best current source route. `0x0049bb60` is best documented as a source-authored override of the tertiary `+0xa4` Pane event/update callback reached through vtable slot `0x006188dc`; no direct command, string, hotkey, or UI label path was found.
- The same B001 pass ranked alternatives and rejected them for direct ownership: `ExceptionHandler.cpp` owns `g_pCrashTarget` and `m_skipCrashReport` but not the Crasher Pane/vtable lifecycle; `Application.cpp` only constructs and cleans up the object; Pane/EventDispatcher/timer core are dispatch dependencies; and no command/debug/cheat feature owner is proven because no command, hotkey, string, menu, direct caller, or registration path reaches `0x0049bb60`.
- Final source expresses normal `Crasher` class code: two-base declaration, empty derived constructor/destructor bodies, class-specific singleton specializations, and the exact `OnTimer` override. Vtable bytes, RTTI, destructor adjustors, scalar deleting destructor glue, and raw vtable stores are compiler output and must not be handwritten in `platform/Crasher.cpp`.
- 2026-06-22 B015 class pass keeps `platform/Crasher.cpp` as the best route after rechecking the local PE route: `Application::Initialize` is the sole direct constructor caller at `0x004646ec`; the trigger callback is vtable-only through `0x006188dc -> 0x0049bb60`; `g_pCrasher` belongs here and records the Crasher singleton lifecycle; `g_pCrashTarget` and `m_skipCrashReport` remain [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) state consumed by Crasher. The normal source file should contain `Crasher`, `g_pCrasher`, the constructor, ordinary destructor, and the `+0xa4` Pane/TimerHandler crash-trigger callback.
- Generated source cleanup is required: stale `class_Crasher.cpp` style output emits synthetic vtable-layout overlays, raw vtable stores, and scalar deleting destructor code, omits the source-authored ordinary destructor, and writes `g_pCrashTarget + 4` instead of the resolved `m_skipCrashReport` field. Final source should contain ordinary constructor/destructor/callback bodies and let the compiler generate ABI glue.

## Score Rationale

Completion is `93` because the file page records exact class/global/method order, formal class/header source, zero global definition, explicit Singleton specializations, empty derived lifecycle, `OnTimer` body, ExceptionHandler setter dependency, compiler exclusions, and Application consumer boundary. Confidence is `94` because RTTI/PMD, allocation, vtable-only callback, zero storage, four singleton refs, and companion-module evidence independently support the same source. Original filename/guard/parameter spelling remains bounded inference only.

## Placement Notes

`platform/Crasher.cpp` is the current source-layout recommendation because the class exists to interact with process crash handling and owns its own Pane-derived singleton/vtables. `ExceptionHandler.cpp` remains the companion owner for [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), not the direct owner for this class.

## Current Source-Quality Limits

- The exact higher-level object or registration that dispatches the tertiary timer callback is not recovered. This is a consumer-discovery limit only: inherited slot shape, three-argument ABI, and vtable route establish the source declaration `OnTimer(int,int,int)`.
- The null-write marker `0x6675636b` is an intentional developer/diagnostic crash tag. Current evidence rejects CheatDetector, anti-tamper, generic EventDispatcher, Application, and ExceptionHandler as direct source owners.
- Exact original filename, header guard, and parameter spellings are not retained in the executable. The chosen source shape follows the established platform and callback conventions without leaving decompiler artifacts.

## Final Source Order And One-Definition Policy

1. UID00003A at position `0` emits `#include "Crasher.h"`, `#include "ExceptionHandler.h"`, and the complete guarded header declaration.
2. UID0000QM at position `1` emits `Crasher *g_pCrasher = 0;`, both explicit `Singleton<Crasher>` lifecycle specializations, and then `[[CHILDREN]]`.
3. UID000129 at position `2` emits the empty derived constructor/destructor and exact `OnTimer` body.

UID000298 is the physical global slot and emits only a covered-by comment; UID0002UU is compiler-generated vtable/RTTI data and emits nothing. Application owns startup/cleanup order only. This order prevents duplicate globals, duplicate externs, handwritten ABI data, and derived-body duplication of Singleton specialization effects.

## Cross-References

- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)

## Changes

- 2026-08-06 B005 UID000298 source-quality implementation:
  - Raised `87/88 -> 93/94` with path and file ownership unchanged.
  - Closed the exact source order: class/header position `0`, global/specializations position `1`, methods position `2`; physical storage and compiler vtable data remain non-duplicating support pages.
  - Added direct Singleton PMD/EBO evidence, zero-initialized global source shape, `OnTimer` naming, inline ExceptionHandler setter dependency, one-definition policy, and compiler exclusions.
  - Retained the earlier `0xffffffff`, single-base, `TriggerCrash`, direct-field access, and handwritten singleton writes as dated historical assumptions rather than current source guidance.

- 2026-06-22 B015 class source-quality incorporation:
  - Before: scored `86/86` with source shape described but still effectively blocked by callback-path/generated-source cleanup.
  - After: scored `87/88`.
  - Evidence: B015 confirmed the separate `platform/Crasher.cpp` route, Application-only construction, vtable-only tertiary callback reachability, `g_pCrasher` ownership, `g_pCrashTarget->m_skipCrashReport` consumer use, generated-source cleanup needs, and rejected `ExceptionHandler.cpp`, `Application.cpp`, Pane/EventDispatcher/TimerMgr, command/menu/UI/debug, and CheatDetector as direct owners.
- 2026-06-17 B001 source-quality sync:
  - Score unchanged at `86/86`.
  - Replaced the broad standalone-vs-ExceptionHandler split caveat with the current best route: keep separate `platform/Crasher.cpp` and treat `ExceptionHandler.cpp` as a companion dependency.
  - Documented `TriggerCrash` as vtable-only tertiary Pane event/update callback behavior rather than a directly called helper.
- 2026-06-06 A004 live IDA refresh:
  - Before: file-level score stayed at `82/78` and still described the evidence basis as the older generated-source plus 2026-05-24 check.
  - After: raised to `84/82`, updated the evidence basis, and added live function-boundary, caller, singleton-global, vtable, and source-tree separation rationale.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `xrefs_to`, and `decompile` confirm the constructor/destructor/trigger family, the Application-only direct construction site, no direct `TriggerCrash` caller, local `g_pCrasher` lifecycle ownership, and the cross-file `g_pCrashTarget` exception-handler interaction. Confidence remains below the surrounding strong pages because the original virtual trigger path and final standalone-vs-ExceptionHandler source split are still not closed.
- 2026-06-07 A006 parent-gate refresh:
  - Before: file-level score was `84/82`, below the Batch 035 parent gate for associated singleton assignment.
  - After: raised to `86/86` after adding live singleton storage/xref evidence and a score rationale.
  - Evidence: IDA MCP rechecked `dword_67AB38`, its four direct lifecycle xrefs, and the Application cleanup / Crasher constructor / destructor / scalar-deleting-destructor function boundaries.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: class role, singleton globals, exception-handler interaction, crash-trigger behavior, vtable/startup evidence, placement notes, and open virtual-call questions are documented; confidence remains medium-high because final source placement versus `ExceptionHandler.cpp` is unresolved.
