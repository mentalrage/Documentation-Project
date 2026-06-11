*** UID:0000SH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pThreadMan

## Status

- Confidence: strong for exact storage, owner, singleton lifetime, and `ThreadMan*` role; medium-high for final source linkage/static-construction spelling.
- IDA storage: `0x0069be08`
- Proposed owner: [UID:0000OR][Thread](by-file/Thread.md)
- Exact storage: [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md)

## Observed Evidence

- `ThreadMan::ThreadMan` writes `0x0069be08` after base construction.
- IDA xrefs to `0x0069be08` include writes/uses inside `ThreadMan::ThreadMan`, raw destructor cleanup at `0x00596d5f`, the singleton-clear helper at `0x005974e0`, and `ThreadMan::ScalarDeletingDestructor`.
- `ThreadMan` metadata includes RTTI for `Singleton<ThreadMan>`, supporting singleton ownership even though direct constructor xrefs were not found.
- 2026-05-26 IDA MCP recheck still shows refs at constructor offsets `0x00596c33` and `0x00596c3a`, raw destructor offset `0x00596d5f`, singleton-clear helper `0x005974e0`, and scalar deleting destructor offset `0x00597532`.
- 2026-05-31 IDA MCP recheck confirms storage name `dword_69BE08` at `0x0069be08`, five xrefs, constructor refs inside `0x00596bf0-0x00596d13`, the raw destructor cleanup ref at `0x00596d5f`, singleton-clear helper `0x005974e0-0x005974eb`, and scalar deleting destructor ref inside `0x005974f0-0x0059756e`.
- The exact storage page [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) isolates `0x0069be08-0x0069be0c` as the active `ThreadMan` singleton pointer and explicitly keeps the adjacent timer tick globals with `TimerMgr`.
- [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md) now isolates the exact four-byte storage child from the mixed ThreadMan/TimerMgr cluster.
- [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md) documents the constructor publishing this pointer, installing the `ThreadMan` vtable, creating the watchdog list, and starting the worker thread.
- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md) records the external singleton pointer as separate from the object layout while tying the constructor/destructor field behavior back to `ThreadMan`.
- A004 Batch 056 attempted a live IDA MCP refresh, but repeated `py_eval`, `xrefs_to`, and `idb_meta` calls timed out. The score raise uses the already written IDA-backed singleton, constructor, clear, destructor, and layout evidence plus the exact storage split.

## Type Hypothesis

Likely declaration:

```cpp
static ThreadMan* g_pThreadMan;
```

The `static` qualifier is provisional until final source-file linkage is reviewed.

## Ownership Hypothesis

Keep this global with `util/Thread.cpp`. It is the singleton pointer for [UID:0000EW][ThreadMan](by-class/ThreadMan.md), not a general process-global table.

Do not merge this declaration with the adjacent timer tick globals despite the contiguous `.data` range; [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) splits ownership between `ThreadMan` and `TimerMgr`.

This page now clears the corrected `85/85` direct-parent gate for the exact storage child. Final C++ remains blank because source linkage/static-construction spelling is not final-audit quality.

## Cross-References

- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md)
- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md)
- [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md)
- [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md)
- [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md)
- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)

## Changes

- What existed before: completion/confidence were `0/0`, reconstructable state was blank, and no autogen parent was assigned.
- What it was changed to: completion `74`, confidence `82`, `RECONSTRUCTABLE:TRUE`, and parent UID [UID:0000OR][Thread](by-file/Thread.md).
- Summary/evidence: the page already documented the singleton storage role, and the 2026-05-31 IDA MCP recheck reconfirmed the exact global storage and ThreadMan constructor/cleanup/destructor xrefs. No C++ declaration was emitted because final source linkage and exact declaration form are still below the 95+ reconstruction-code threshold.
- 2026-06-06: Raised to `82/86`, removed generated-source authority wording, and added exact storage, constructor, cleanup/destructor, object-layout, and adjacent-timer split evidence from the linked project docs. C++ remains blank because the direct constructor reachability/static singleton source path and final linkage spelling are still below final-source confidence.
- 2026-06-07 A004 Batch 056 parent-gate refresh:
  - Before: `82/86`, below the corrected completion gate for exact storage assignment.
  - Changed to: `86/88`, linking exact child [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md).
  - Summary/evidence: existing IDA-backed constructor, raw cleanup, singleton clear, scalar deleting destructor, layout, and mixed-cluster evidence is now tied to the exact four-byte storage page. Live MCP refresh timed out, so no final C++ declaration was emitted.
