*** UID:00003A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Crasher

## Status

- Confidence: strong for class identity, medium for original module placement.
- Likely source module: [UID:0000II][Crasher](by-file/Crasher.md)
- Base class: [UID:0000A2][Pane](by-class/Pane.md)
- Current range: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- Reconstructable: true; attached to [UID:0000II][Crasher](by-file/Crasher.md), with C++ intentionally blank until final source grouping and names are audit-ready.

## Autogen Status

- Parent file: [UID:0000II][Crasher](by-file/Crasher.md).
- Reconstructable: true.
- Final C++ remains blank because the source split against `ExceptionHandler.cpp`, the original virtual trigger path, and final field/helper names are not source-quality yet.
- The stronger score is inherited from the class, file, memory, vtable, and global pages rather than from generated source text.

## Responsibility

`Crasher` is a small [UID:0000A2][Pane](by-class/Pane.md)-derived singleton used to intentionally raise an exception. Before the null write, it marks [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) at offset `+4`, which changes how [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) handles the exception.

## Key Data

- Singleton global: [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) at `0x0067ab38`.
- Vtables: `0x0061885c`, `0x006188a8`, and `0x006188d8`.
- RTTI includes `Crasher` and `Singleton<Crasher>`.
- Startup allocation size: `0xf8` bytes.
- Vtable views are written at object offsets `0x0`, `0xa0`, and `0xa4`.

## Important Methods

| Address | Current/proposed name | Notes |
| --- | --- | --- |
| `0x0049bae0` | `Crasher` | Constructs [UID:0000A2][Pane](by-class/Pane.md) base, stores singleton, installs vtables. |
| `0x0049bb30` | `~Crasher` | Clears singleton and destroys [UID:0000A2][Pane](by-class/Pane.md) base. Omitted from current active generated source. |
| `0x0049bb60` | `TriggerCrash` | Sets `[g_pCrashTarget + 4] = 1` and writes marker `0x6675636b` through address zero. |
| `0x0049bb90` | `ScalarDeletingDestructor` | Clears singleton, destroys base, optionally deletes `this`. |

## Ownership Notes

- This class is not the exception filter itself. The filter and crash-report helpers belong to [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md).
- The class is not current evidence for [UID:000020][CheatDetector](by-class/CheatDetector.md) ownership; it interacts with crash reporting rather than the compact cheat-detector singleton.
- Because `TriggerCrash` has no direct callers, later vtable analysis is needed before naming the triggering UI or command path.

## Evidence Notes

- [UID:0000II][Crasher](by-file/Crasher.md) keeps this as a small `platform/Crasher.cpp` companion to `ExceptionHandler`, with Application-only direct construction at `0x004646ec` and no direct `TriggerCrash` callsite.
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) now records exact constructor/destructor/trigger/scalar-deleting-destructor bodies, adjustor thunks, global xrefs, vtable installs, and padding boundaries.
- [UID:0002UU][0x0061885c-0x006188e0.CrasherVtableData](by-memory/0x0061885c-0x006188e0.CrasherVtableData.md) records the three `Crasher` vtable views and confirms the virtual trigger slot at `0x006188dc -> 0x0049bb60`.
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) and [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) document the singleton lifecycle and crash-suppression flag interaction used by the exception handler.

## Score Rationale

Completion is raised to `82` because the class now has an attached file parent, method inventory, singleton/global ownership, exact vtable evidence, aggregate memory coverage, Application lifecycle xrefs, and explicit ownership caveats. Confidence is raised to `84` because the durable docs agree on identity and behavior, but it remains capped by the unresolved original source grouping and the missing virtual trigger caller path.

## Cross-References

- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: singleton data, vtables, constructor/destructor family, intentional crash method, exception-handler interaction, and ownership caveats are documented; remaining uncertainty is the original module placement and trigger path.
- 2026-06-07:
  - Before: score stayed at `76/82` and still referenced generated source as current context.
  - After: rescored to `82/84`, removed the generated-source dependency, and added autogen-status, evidence, and score-rationale sections.
  - Summary/evidence: class reconciliation now cites the Crasher file parent, exact method aggregate, vtable-data child, `g_pCrasher` lifecycle, `g_pCrashTarget` exception-handler interaction, and the remaining source-split/trigger-path caveats.
