*** UID:0000SH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static ThreadMan *g_pThreadMan = NULL;

template <>
Singleton<ThreadMan>::Singleton()
{
    g_pThreadMan = static_cast<ThreadMan *>(this);
}

template <>
Singleton<ThreadMan>::~Singleton()
{
    g_pThreadMan = NULL;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pThreadMan

## Status

- Confidence: very strong for exact storage, owner, direct Singleton-base lifetime, source route, and formal CPP/H disposition; strong for inferred file-static linkage and exact historical spellings.
- IDA storage: `0x0069be08`
- Current IDA item: `ThreadMan *g_pThreadMan`, four bytes, five refs, zero bytes, and blank address comments
- Proposed owner: [UID:0000OR][Thread](by-file/Thread.md)
- Exact storage: [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md)
- Generated attachment: child of [UID:0000EW][ThreadMan](by-class/ThreadMan.md) at position `1`, while canonical source owner remains Thread.cpp [UID:0000OR][Thread](by-file/Thread.md). This ordering emits the storage and specializations after the complete class declaration and before ThreadMan method bodies.

## Observed Evidence

- `ThreadMan::ThreadMan` writes `0x0069be08` after base construction.
- IDA xrefs to `0x0069be08` include writes/uses inside `ThreadMan::ThreadMan`, raw destructor cleanup at `0x00596d5f`, the singleton-clear helper at `0x005974e0`, and `ThreadMan::ScalarDeletingDestructor`.
- `ThreadMan` metadata includes RTTI for `Singleton<ThreadMan>`, supporting singleton ownership even though direct constructor xrefs were not found.
- 2026-05-26 IDA MCP recheck still shows refs at constructor offsets `0x00596c33` and `0x00596c3a`, raw destructor offset `0x00596d5f`, singleton-clear helper `0x005974e0`, and scalar deleting destructor offset `0x00597532`.
- 2026-05-31 IDA MCP recheck historically confirmed storage name `dword_69BE08` at `0x0069be08`, five xrefs, constructor refs inside `0x00596bf0-0x00596d13`, the raw destructor cleanup ref at `0x00596d5f`, singleton-clear helper `0x005974e0-0x005974eb`, and scalar deleting destructor ref inside `0x005974f0-0x0059756e`. Catalog0376 supersedes only that raw current name, not the evidence.
- The exact storage page [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) isolates `0x0069be08-0x0069be0c` as the active `ThreadMan` singleton pointer and explicitly keeps the adjacent timer tick globals with `TimerMgr`.
- [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md) now isolates the exact four-byte storage child from the mixed ThreadMan/TimerMgr cluster.
- [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md) documents the constructor publishing this pointer, installing the `ThreadMan` vtable, creating the watchdog list, and starting the worker thread.
- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md) records the external singleton pointer as separate from the object layout while tying the constructor/destructor field behavior back to `ThreadMan`.
- A004 Batch 056 attempted a live IDA MCP refresh, but repeated `py_eval`, `xrefs_to`, and `idb_meta` calls timed out. The score raise uses the already written IDA-backed singleton, constructor, clear, destructor, and layout evidence plus the exact storage split.
- B003 2026-06-20 class source-quality review keeps this global in `NexusTK/util/Thread.cpp`: `ThreadMan::ThreadMan()` publishes it, the ordinary destructor body and scalar deleting destructor wrapper clear it, and [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) is compiler/EH cleanup rather than a handwritten `ThreadMan::ClearSingleton` source method.
- B008 2026-06-19 local PE immediate scan found `0x0069be08` at constructor writes `0x00596c34` and `0x00596c3c`, raw cleanup `0x00596d61`, EH clear helper `0x005974e2`, and scalar wrapper clear `0x00597534`. These are the singleton lifetime writes; source should clear `g_pThreadMan = NULL` from ordinary `ThreadMan::~ThreadMan()` semantics and let compiler/EH glue cover unwind cleanup.
- 2026-07-30 supervisor catalog0376 created protected incomplete type `ThreadMan`, applied exact item `ThreadMan *g_pThreadMan`, and verified five refs, zero bytes, blank address comments, unchanged boundaries, and no invented UDT members before saving IDB SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94`.
- 2026-07-31/2026-08-01 B007 read-only recheck used healthy MCP session `f608d7c2` and saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`. The exact item remained `ThreadMan *g_pThreadMan`, four zero bytes, absent address comments, and five writes at `0x00596c33`, `0x00596c3a`, `0x00596d5f`, `0x005974e0`, and `0x00597532`.
- ThreadMan RTTI proves a direct `Singleton<ThreadMan>` base with PMD `{4,-1,0}`. Constructor order (`LObject`, adjusted `this+4` Singleton publication, then ThreadMan vtable) and reverse ordinary/EH/scalar teardown converge on explicit class-specific Singleton constructor/destructor specializations as the source-level lifetime mechanism.
- No consumer reads, accessor, header use, class member, or generic template static cell was found. This supports translation-unit-local storage and rejects external linkage, `ThreadMan::s_instance`, `Singleton<T>::m_instance`, or duplicate storage emitted by the exact by-memory child.

## Type Hypothesis

Best current source declaration and lifetime specializations:

```cpp
static ThreadMan *g_pThreadMan = NULL;

template <>
Singleton<ThreadMan>::Singleton()
{
    g_pThreadMan = static_cast<ThreadMan *>(this);
}

template <>
Singleton<ThreadMan>::~Singleton()
{
    g_pThreadMan = NULL;
}
```

The `static` qualifier and exact lexical spellings remain evidence-backed inference because retail symbols are unavailable. They are nevertheless the most realistic human source form: the global has no observed consumer outside ThreadMan lifetime code, the accepted reusable Singleton template contains no generic storage, and the binary exposes the class-specific base lowering directly.

## Ownership Hypothesis

Keep this global with `util/Thread.cpp`. It is the singleton pointer for [UID:0000EW][ThreadMan](by-class/ThreadMan.md), not a general process-global table.

Do not merge this declaration with the adjacent timer tick globals despite the contiguous `.data` range; [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) splits ownership between `ThreadMan` and `TimerMgr`.

This page emits the one storage definition plus the two class-specific lifetime specializations. Its H channel remains blank because no external declaration or header consumer is evidenced. Static linkage remains an evidence-backed source reconstruction rather than recovered original spelling.

Do not move this global under a class-static method or add a clear helper to the class API. The current source-facing declaration remains a file/global `ThreadMan *` singleton pointer owned by [UID:0000OR][Thread](by-file/Thread.md), while the class page owns the `ThreadMan` declaration.

Historical model note: the B003/B008/B009/B012 passages below were valuable for identifying the five lifetime writes, but their assignment of publication/clear to explicit derived constructor/destructor statements predates the direct-base PMD and specialization reanalysis. Preserve them as dated history; do not use them as current source shape.

B008 keeps `static ThreadMan *g_pThreadMan;` as the best source-facing declaration, with `static` still inferred pending final linkage audit.

B009's Rule 26 recheck reaches the same declaration direction and clarifies lifetime ownership: `ThreadMan::~ThreadMan()` source should contain `g_pThreadMan = NULL`, while [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) is constructor-unwind/EH cleanup glue rather than a source-authored clear helper. The singleton remains file/global storage under [UID:0000OR][Thread](by-file/Thread.md); do not move it into the class as a static member or create a `ThreadMan::ClearSingleton()` API without new source evidence.

B012 source-quality reanalysis independently confirms the lifetime split. Constructor writes publish `g_pThreadMan`, ordinary destructor source should clear it, [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) duplicates the clear as generated wrapper cleanup, and [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) remains constructor-unwind glue. Keep `static ThreadMan *g_pThreadMan;` as the best current source-facing declaration, with `static` still inferred.

Current correction: publication and clear still occur at all observed sites, but handwritten `ThreadMan` source does not repeat those assignments. The constructor/destructor specializations above generate normal publication, normal clear, constructor-unwind clear, and scalar-wrapper clear. The EH helper and scalar deleting destructor remain compiler artifacts, not new source APIs.

Score rationale: `92/94` reflects exact storage/type/bytes, all five xrefs, direct Singleton-base PMD/order, normal/EH/scalar lifetime convergence, file ownership, emitter ordering, and complete formal CPP/H. Confidence remains below certainty only because retail linkage/private spellings are not preserved and the ordinary destructor function still awaits supervisor Gate 2B modeling.

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

- 2026-08-01 B007 UID000305 accepted-report ordinary callback:
  - Raised `88/89` to `92/94`; retained canonical Thread.cpp owner UID0000OR.
  - Reattached generated emission to UID0000EW at position `1` so the exact definition/specializations follow the complete class declaration.
  - Replaced the formal CPP with the one file-static definition, explicit `Singleton<ThreadMan>` constructor/destructor specializations, and child stream; H remains blank.
  - Incorporated exact current storage/xref/RTTI/PMD evidence, source-linkage alternatives, output-order reasoning, and the historical correction from explicit derived assignments to specialization-generated lifetime code.

- 2026-07-30 B010 UID0002AP post-Gate2B reconciliation:
  - Replaced `dword_69BE08` as current IDA state with catalog0376-applied `ThreadMan *g_pThreadMan`, preserving the raw alias as dated history and all five constructor/destructor/EH/wrapper refs.
  - Recorded protected incomplete-type and saved-IDB evidence; retained formal source, Thread.cpp ownership, `88/89`, and the compiler-glue versus source-destructor lifetime distinction.

- 2026-06-20 B003 Rule 26 incorporation:
  - Summary/evidence: added constructor-publish/destructor-clear/EH-cleanup policy from the ThreadMan source-quality report and explicitly rejected a `ThreadMan::ClearSingleton` source helper. Metadata remains `86/88` with file/global ownership through [UID:0000OR][Thread](by-file/Thread.md).
- 2026-06-21 B008 scalar-wrapper support sync:
  - Summary/evidence: added B008's local PE immediate-hit set for `0x0069be08`, the ordinary-destructor clear policy, and the provisional `static ThreadMan *g_pThreadMan` declaration/linkage note. Metadata remains unchanged.
- 2026-06-21 B009 Rule 26 older-report reconciliation:
  - Summary/evidence: added B009's lifetime/source-policy distinction between ordinary destructor clear, constructor-unwind glue, and file/global declaration ownership. Metadata and blank formal C++ remain unchanged pending final linkage/static-construction spelling.
- 2026-06-22 B012 source-quality implementation:
  - Summary/evidence: added B012's independent singleton lifetime split and preserved `static ThreadMan *g_pThreadMan;` as the current best declaration with inferred linkage. Metadata and blank formal C++ remain unchanged.
- What existed before: completion/confidence were `0/0`, reconstructable state was blank, and no autogen parent was assigned.
- What it was changed to: completion `74`, confidence `82`, `RECONSTRUCTABLE:TRUE`, and parent UID [UID:0000OR][Thread](by-file/Thread.md).
- Summary/evidence: the page already documented the singleton storage role, and the 2026-05-31 IDA MCP recheck reconfirmed the exact global storage and ThreadMan constructor/cleanup/destructor xrefs. No C++ declaration was emitted because final source linkage and exact declaration form are still below the 95+ reconstruction-code threshold.
- 2026-06-06: Raised to `82/86`, removed generated-source authority wording, and added exact storage, constructor, cleanup/destructor, object-layout, and adjacent-timer split evidence from the linked project docs. C++ remains blank because the direct constructor reachability/static singleton source path and final linkage spelling are still below final-source confidence.
- 2026-06-07 A004 Batch 056 parent-gate refresh:
  - Before: `82/86`, below the corrected completion gate for exact storage assignment.
  - Changed to: `86/88`, linking exact child [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md).
  - Summary/evidence: existing IDA-backed constructor, raw cleanup, singleton clear, scalar deleting destructor, layout, and mixed-cluster evidence is now tied to the exact four-byte storage page. Live MCP refresh timed out, so no final C++ declaration was emitted.
