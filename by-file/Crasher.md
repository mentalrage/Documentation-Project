*** UID:0000II | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Crasher

## Status

- Confidence: strong for class ownership and standalone diagnostics-file fit, medium for the unresolved virtual trigger path and final split from `ExceptionHandler.cpp`.
- Proposed module: `platform/Crasher.cpp`
- Current generated source: `source-3/simroot_v2/class_Crasher.cpp`
- Main class: [UID:00003A][Crasher](by-class/Crasher.md)
- Main address doc: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- Evidence basis: existing class/memory docs plus IDA MCP lookup/decompile/xref checks refreshed on 2026-06-06.

## Hypothesis

`Crasher` is a tiny diagnostic companion to [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). It is a [UID:0000MC][Pane](by-file/Pane.md)-derived singleton that can deliberately raise a null-pointer crash after setting the active exception-handler object's suppress/report flag at offset `+4`.

Keep this as a separate `platform/Crasher.cpp` companion for now. The class has real RTTI/vtables and a [UID:0000MC][Pane](by-file/Pane.md) base, so it should not be folded blindly into the `ExceptionHandler` class. Its only observed startup construction is from [UID:0000HG][Application](by-file/Application.md), and its deliberate crash path depends on [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md).

## Likely Contents

- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md)
- references to [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- constructor at `0x0049bae0`
- ordinary destructor at `0x0049bb30`
- crash-trigger virtual at `0x0049bb60`
- destructor adjustor thunks at `0x0049bb78` and `0x0049bb83`
- scalar deleting destructor at `0x0049bb90`

## Evidence

- IDA confirms `Crasher` vtables at `0x0061885c`, `0x006188a8`, and `0x006188d8`, plus RTTI for both `Crasher` and `Singleton<Crasher>`.
- `Application::Initialize` constructs a `0xf8` byte `Crasher` object at `0x004646ec`.
- `Crasher::Crasher` calls `Pane::Pane(this, 0)`, writes [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) at `0x0067ab38`, and installs three vtable views at object offsets `0x0`, `0xa0`, and `0xa4`.
- `Crasher::TriggerCrash` sets byte `[g_pCrashTarget + 4]` to `1`, writes marker `0x6675636b` through address zero, and returns `1`.
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) checks the same byte at `[g_pCrashTarget + 4]`; when it is `1`, the filter skips the normal report-helper path.
- 2026-06-06 IDA MCP recheck confirms the exact function bodies at `0x0049bae0`, `0x0049bb30`, `0x0049bb60`, `0x0049bb78`, `0x0049bb83`, and `0x0049bb90`; direct callers list only the constructor call from `Application::Initialize` at `0x004646ec`, while `TriggerCrash` and the scalar deleting destructor have no direct callsites because they are vtable-driven.
- The same xref pass keeps [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) ownership local to Application cleanup plus Crasher construction/destruction, while [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) has broader exception/timing/filter references. This supports keeping the deliberate-crash pane as its own `platform/Crasher.cpp` companion rather than merging its singleton/vtable code into `ExceptionHandler.cpp` without further source-order evidence.
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) now records the stronger boundary, vtable, global-xref, and Application construction/cleanup evidence; this file page should inherit that evidence for source ownership while leaving final C++ blank.
- 2026-06-07 A006 IDA MCP recheck confirms [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) / `dword_67AB38` is a four-byte `.data` singleton initialized to `0xffffffff`, with exactly four direct data xrefs: Application cleanup read at `0x00464c4e`, constructor publish at `0x0049bb04`, ordinary destructor clear at `0x0049bb4a`, and scalar deleting destructor clear at `0x0049bbb0`.
- The same pass confirms the relevant function objects: Application cleanup `0x00464a60-0x00464cc1`, `Crasher::Crasher` `0x0049bae0-0x0049bb2a`, ordinary destructor `0x0049bb30-0x0049bb59`, and scalar deleting destructor `0x0049bb90-0x0049bbef`. This closes the singleton ownership loop enough for parent-gated memory assignment while preserving the open virtual trigger/source-split caveats.

## Score Rationale

Completion is raised to `86` because the file page now records exact singleton storage evidence in addition to the class/method/vtable inventory, Application construction and cleanup, deliberate-crash behavior, and source-placement caveats. Confidence is raised to `86` because live IDA confirms the four `g_pCrasher` lifecycle xrefs and exact Crasher function boundaries; it remains below final audit because the original virtual trigger path and final standalone-vs-ExceptionHandler source split are still unresolved.

## Placement Notes

`platform/Crasher.cpp` is the current source-layout hypothesis because the class exists to interact with process crash handling. If later vtable-slot review shows it is a hidden UI pane command/debug control, `app/Crasher.cpp` or a small diagnostics folder may be more accurate.

## Open Questions

- Which vtable slot or event path invokes `TriggerCrash`; IDA reports no direct code callers, so the call is likely virtual.
- Whether the original source colocated this class with `ExceptionHandler.cpp` or kept it as its own small file.
- Whether the null-write marker value should be treated as a developer-only crash tag, an anti-tamper path, or a retained debug helper.

## Cross-References

- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)

## Changes

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
