*** UID:00003A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Crasher

## Status

- Confidence: strong for class identity, medium for original module placement.
- Current generated file: `source-3/simroot_v2/class_Crasher.cpp`
- Likely source module: [UID:0000II][Crasher](by-file/Crasher.md)
- Base class: [UID:0000A2][Pane](by-class/Pane.md)
- Current range: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- Reconstructable: true; attached to [UID:0000II][Crasher](by-file/Crasher.md), with C++ intentionally blank until final source grouping and names are audit-ready.

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
