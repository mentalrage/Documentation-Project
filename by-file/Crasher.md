*** UID:0000II | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Crasher

## Status

- Confidence: strong for class ownership, medium for final source placement.
- Proposed module: `platform/Crasher.cpp`
- Current generated source: `source-3/simroot_v2/class_Crasher.cpp`
- Main class: [UID:00003A][Crasher](by-class/Crasher.md)
- Main address doc: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- Evidence basis: `simroot_v2` generated source plus IDA MCP lookup/decompile/xref checks on 2026-05-24.

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

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: class role, singleton globals, exception-handler interaction, crash-trigger behavior, vtable/startup evidence, placement notes, and open virtual-call questions are documented; confidence remains medium-high because final source placement versus `ExceptionHandler.cpp` is unresolved.
