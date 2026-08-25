*** UID:00003A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Crasher.h"
#include "ExceptionHandler.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_PLATFORM_CRASHER_H
#define NEXUSTK_PLATFORM_CRASHER_H

#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Crasher : public Pane, public Singleton<Crasher>
{
public:
    Crasher();
    virtual ~Crasher();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
};

extern Crasher *g_pCrasher;

typedef char CrasherSizeMustBe0xF8[
    sizeof(Crasher) == 0xf8 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Crasher

## Status

- Confidence: very strong for class identity, two-base declaration, exact size, method surface, source module, and vtable-only timer callback route.
- Likely source module: [UID:0000II][Crasher](by-file/Crasher.md)
- Base class: [UID:0000A2][Pane](by-class/Pane.md)
- Current range: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- Reconstructable: true; attached to [UID:0000II][Crasher](by-file/Crasher.md) at emitter position `0`. Formal CPP owns only the source include preamble; formal H owns the complete guarded declaration. Method bodies and the singleton definition/specializations are ordered separately through UID000129 and UID0000QM.

## Autogen Status

- Parent file: [UID:0000II][Crasher](by-file/Crasher.md).
- Reconstructable: true.
- Draft source models only source-authored class shape. Vtables, RTTI/COL data, secondary/tertiary destructor adjustor thunks, raw vtable stores, and scalar deleting destructor wrappers are compiler-generated and must not be hand-authored.
- The tertiary slot is the inherited `OnTimer(int,int,int)` surface. `TriggerCrash` remains a useful historical behavior alias, not the source declaration. The higher-level virtual dispatcher need not be a direct caller for this override to be source-complete.

## Responsibility

`Crasher` is a small [UID:0000A2][Pane](by-class/Pane.md)-derived, storage-free `Singleton<Crasher>` used to intentionally raise an exception. Before the null write, source calls `g_pCrashTarget->SetSkipCrashReport(true)`; the inline setter performs the exact offset-`+4` write to `m_skipCrashReport`, which changes how [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) handles the exception.

## Key Data

- Singleton global: [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) at `0x0067ab38`.
- Vtable data child: [UID:0002UU][0x00618858-0x006188e0.CrasherVtableData](by-memory/0x00618858-0x006188e0.CrasherVtableData.md), containing primary RTTI at `0x00618858` and vtable bases `0x0061885c`, `0x006188a8`, and `0x006188d8`.
- RTTI includes `Crasher` and `Singleton<Crasher>`.
- Startup allocation size: `0xf8` bytes.
- Vtable views are written at object offsets `0x0`, `0xa0`, and `0xa4`.

## Important Methods

| Address | Current/proposed name | Notes |
| --- | --- | --- |
| `0x0049bae0` | `Crasher::Crasher` | Source-authored derived body is empty after `Pane(0)`. Inlined `Singleton<Crasher>::Singleton()` lowering publishes the adjusted complete pointer, and the compiler installs the three Crasher vtable views. |
| `0x0049bb30` | `Crasher::~Crasher` | Source-authored ordinary destructor that clears `g_pCrasher` and destroys the [UID:0000A2][Pane](by-class/Pane.md) base. This was omitted from stale generated output and should be present in draft source. |
| `0x0049bb60` | `Crasher::OnTimer` (`TriggerCrash` historical behavior alias) | Exact tertiary `+0xa4` override; calls the inline `g_pCrashTarget->SetSkipCrashReport(true)`, writes marker `0x6675636b` through address zero, and returns true. The three parameters are unused, matching the inherited timer callback surface. |
| `0x0049bb78`, `0x0049bb83`, `0x0049bb90` | destructor adjustors / scalar deleting destructor | Compiler-generated ABI glue for secondary/tertiary destructor slots and optional delete. Do not model these as handwritten source methods. |

## Ownership Notes

- This class is not the exception filter itself. The filter and crash-report helpers belong to [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md).
- This class is not Application-owned; [UID:0000HG][Application](by-file/Application.md) constructs and cleans up the singleton but does not own its behavior, vtables, or ExceptionHandler field use.
- This class is not generic [UID:0000A2][Pane](by-class/Pane.md), EventDispatcher, or timer-manager code. Those systems provide base dispatch mechanics for the inherited callback surface, but the override body and singleton lifecycle are Crasher-specific.
- Current evidence does not support command/menu/UI/debug file ownership: no direct caller, string, hotkey, menu item, visible UI label, or registration path reaches `0x0049bb60`.
- The class is not current evidence for [UID:000020][CheatDetector](by-class/CheatDetector.md) ownership; it interacts with crash reporting rather than the compact cheat-detector singleton.
- `OnTimer` has no direct callers and is reached through `Crasher` vtable slot `0x006188dc`, matching the inherited/default tertiary Pane timer callback shape at `0x00544e90`. The absence of a recovered higher-level registration identifies only an unknown dispatcher consumer; it does not reopen the source declaration or class ownership.

## Evidence Notes

- Raw RTTI describes seven class-hierarchy descriptors: `Crasher`, direct `Pane`, inherited `ControlPane`, `EventHandler`, `TimerHandler`, `LObject`, and direct `Singleton<Crasher>`. The direct Singleton BCD has PMD `{mdisp=0xf8,pdisp=-1,vdisp=0}` and the complete allocation is `0xf8`, proving a storage-free empty base rather than a member or generic static.
- Constructor lowering receives the Singleton base facet at complete-object end and converts it back to `Crasher *` before publishing `g_pCrasher`. Reverse base destruction clears the global after the empty derived destructor body and before Pane teardown. These writes belong to explicit `Singleton<Crasher>` specializations, not handwritten derived lifecycle statements.

- [UID:0000II][Crasher](by-file/Crasher.md) keeps this as a small `platform/Crasher.cpp` companion to `ExceptionHandler`, with Application-only direct construction at `0x004646ec` and no direct `TriggerCrash` callsite.
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) now records exact constructor/destructor/trigger/scalar-deleting-destructor bodies, adjustor thunks, global xrefs, vtable installs, and padding boundaries.
- [UID:0002UU][0x00618858-0x006188e0.CrasherVtableData](by-memory/0x00618858-0x006188e0.CrasherVtableData.md) records the primary RTTI locator, the three `Crasher` vtable views, and the virtual trigger slot at `0x006188dc -> 0x0049bb60`.
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) and [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) document the singleton lifecycle and crash-suppression flag interaction used by the exception handler.
- Agent-A005 live IDA recheck on 2026-06-11 reconfirms the exact vtable-data child range as `0x00618858-0x006188e0`, a `0x88` / 136-byte `.rdata` island (Verified with `int_convert.py`), with constructor/destructor/scalar-destructor stores to `0x0061885c`, `0x006188a8`, and `0x006188d8` and the virtual trigger slot `0x006188dc -> 0x0049bb60`.
- The same pass confirms startup allocation size `0xf8` / 248 bytes and crash marker `0x6675636b` / 1718969195, little-endian ASCII `kcuf` (Verified with `int_convert.py`).
- B001 source-quality reanalysis on 2026-06-17 keeps separate [UID:0000II][Crasher](by-file/Crasher.md) source placement as the best current route. [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) owns the active crash target and `m_skipCrashReport` field; `Crasher` consumes that state through [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md).
- B001 also rechecked dispatcher and timer leads: `0x004a6ef0` / `0x004a7130` support indirect event-handler virtual dispatch, while timer wrappers `0x005975e0` / `0x00597600` route through the timer manager without a Crasher-specific registration. No direct command, string, hotkey, menu, or UI-label path to `0x0049bb60` was found, so `TriggerCrash` remains a vtable-only tertiary Pane event/update override until the higher-level trigger is recovered.
- Source reconstruction should keep constructor/destructor/trigger override code in the class and let the compiler regenerate RTTI, vtables, adjustor thunks, and scalar deleting destructor glue. The current active generated output omits the ordinary destructor and emits ABI artifacts, which is a generated-output quality issue rather than a reason to model those artifacts as hand-written source.
- B015 source-quality pass on 2026-06-22 rechecked the local PE route against `NexusTK.exe`: constructor `0x0049bae0` has one direct rel32 caller at `0x004646ec` from `Application::Initialize`; `0x0049bb60` has no rel32 code caller and only the `0x006188dc` tertiary vtable pointer hit; `0x0049bb90` is referenced by the primary vtable cell `0x0061885c`; adjustors `0x0049bb78` and `0x0049bb83` are referenced by `0x006188a8` and `0x006188d8`; rel32 hits to `0x0049bb90` are only the local adjustor jumps. The same scan confirms constructor/destructor/scalar-destructor vtable-store triads, four `g_pCrasher` immediate refs at `0x00464c50`, `0x0049bb05`, `0x0049bb4c`, and `0x0049bbb2`, nine `g_pCrashTarget` immediate refs, and no RVA/raw-offset dword encodings for `0x0049bb60`.

## Score Rationale

Completion is `93` because source placement, two-base declaration, exact `0xf8` size, constructor/destructor/`OnTimer` surface, inline ExceptionHandler setter use, Singleton specializations, compiler-generated ABI exclusions, and formal CPP/H channels are resolved. Confidence is `94` because RTTI/PMD, allocation, vtable slots, method bodies, four singleton refs, and companion-module evidence independently agree. Original header-guard and parameter spellings remain bounded inference rather than behavioral blockers.

## Cross-References

- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)

## Changes

- 2026-08-06 B005 UID000298 source-quality implementation:
  - Raised `87/89 -> 93/94`, retained owner/emitter UID0000II, and set emitter position `0`.
  - Replaced the old single-base CPP declaration with an exact include-only formal CPP preamble and guarded formal H declaring `Crasher : Pane, Singleton<Crasher>`, lifecycle, `OnTimer`, extern global, and `0xf8` size assertion.
  - Added the exact seven-descriptor hierarchy, direct Singleton PMD/EBO proof, class-specific specialization lifecycle, and inline ExceptionHandler setter source route.
  - Preserved `TriggerCrash`, the omitted Singleton base, direct-field write, and handwritten publication/clear as historical source-quality assumptions superseded by current evidence.

- 2026-06-22 B015 class source-quality incorporation:
  - Before: scored `85/86`; draft C++ stayed blank because callback-path/generated-source cleanup was treated as a blocker.
  - After: scored `87/89`; owner/emitter remain [UID:0000II][Crasher](by-file/Crasher.md), `RECONSTRUCTABLE:TRUE`.
  - Evidence: B015 revalidated `platform/Crasher.cpp` as the separate companion source route, confirmed Application construction at `0x004646ec`, vtable-only `TriggerCrash` reachability through `0x006188dc -> 0x0049bb60`, `g_pCrasher` lifecycle refs, `g_pCrashTarget` consumer-only write to `ExceptionHandler::m_skipCrashReport`, and the compiler-generated status of vtables, RTTI/COL data, adjustor thunks, scalar deleting destructor, and raw vtable stores. First-draft class declaration is now present; exact inherited callback spelling, higher-level trigger route, and singleton sentinel convention remain score caps.
- 2026-06-17 B001 source-quality sync:
  - Score unchanged at `85/86`.
  - Updated the class notes to treat separate [UID:0000II][Crasher](by-file/Crasher.md) source placement as the best current route and `0x0049bb60` as a tertiary `+0xa4` Pane event/update callback override reached through vtable slot `0x006188dc`.
  - Remaining blockers are narrowed to exact callback/event path naming and generated-source cleanup; B005 later names the `ExceptionHandler` offset `+4` field `m_skipCrashReport` for draft source.
- 2026-06-11 A005 Batch 207 parent-gate repair:
  - Before: scored `82/84`; the exact Crasher vtable child could not attach because the direct class parent was below the corrected `85/85` gate.
  - After: scored `85/86`; the class now supports direct ownership of [UID:0002UU][0x00618858-0x006188e0.CrasherVtableData](by-memory/0x00618858-0x006188e0.CrasherVtableData.md).
  - Summary/evidence: live IDA reconfirmed the RTTI-inclusive vtable child, constructor/destructor/scalar-destructor vptr stores, virtual trigger slot, startup allocation size `0xf8` / 248, and crash marker `0x6675636b` / 1718969195 (`kcuf` little-endian ASCII), with conversions Verified with `int_convert.py`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: singleton data, vtables, constructor/destructor family, intentional crash method, exception-handler interaction, and ownership caveats are documented; remaining uncertainty is the original module placement and trigger path.
- 2026-06-07:
  - Before: score stayed at `76/82` and still referenced generated source as current context.
  - After: rescored to `82/84`, removed the generated-source dependency, and added autogen-status, evidence, and score-rationale sections.
  - Summary/evidence: class reconciliation now cites the Crasher file parent, exact method aggregate, vtable-data child, `g_pCrasher` lifecycle, `g_pCrashTarget` exception-handler interaction, and the remaining source-split/trigger-path caveats.
