*** UID:0000SH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pThreadMan

## Status

- Confidence: strong for storage and owner, medium for final linkage.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_ThreadMan.cpp`
- IDA storage: `0x0069be08`
- Proposed owner: [UID:0000OR][Thread](by-file/Thread.md)

## Observed Evidence

- `ThreadMan::ThreadMan` writes `0x0069be08` after base construction.
- IDA xrefs to `0x0069be08` include writes/uses inside `ThreadMan::ThreadMan`, raw destructor cleanup at `0x00596d5f`, the singleton-clear helper at `0x005974e0`, and `ThreadMan::ScalarDeletingDestructor`.
- Generated source names this symbol `g_pThreadMan` and clears it in the destructor.
- `ThreadMan` metadata includes RTTI for `Singleton<ThreadMan>`, supporting singleton ownership even though direct constructor xrefs were not found.
- 2026-05-26 IDA MCP recheck still shows refs at constructor offsets `0x00596c33` and `0x00596c3a`, raw destructor offset `0x00596d5f`, singleton-clear helper `0x005974e0`, and scalar deleting destructor offset `0x00597532`.
- 2026-05-31 IDA MCP recheck confirms storage name `dword_69BE08` at `0x0069be08`, five xrefs, constructor refs inside `0x00596bf0-0x00596d13`, the raw destructor cleanup ref at `0x00596d5f`, singleton-clear helper `0x005974e0-0x005974eb`, and scalar deleting destructor ref inside `0x005974f0-0x0059756e`.

## Type Hypothesis

Likely declaration:

```cpp
static ThreadMan* g_pThreadMan;
```

The `static` qualifier is provisional until final source-file linkage is reviewed.

## Ownership Hypothesis

Keep this global with `util/Thread.cpp`. It is the singleton pointer for [UID:0000EW][ThreadMan](by-class/ThreadMan.md), not a general process-global table.

## Cross-References

- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)

## Changes

- What existed before: completion/confidence were `0/0`, reconstructable state was blank, and no autogen parent was assigned.
- What it was changed to: completion `74`, confidence `82`, `RECONSTRUCTABLE:TRUE`, and parent UID [UID:0000OR][Thread](by-file/Thread.md).
- Summary/evidence: the page already documented the singleton storage role, and the 2026-05-31 IDA MCP recheck reconfirmed the exact global storage and ThreadMan constructor/cleanup/destructor xrefs. No C++ declaration was emitted because final source linkage and exact declaration form are still below the 95+ reconstruction-code threshold.
