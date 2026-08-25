*** UID:000020 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CheatDetector : public Singleton<CheatDetector>, public TimerHandler
{
public:
    CheatDetector();
    virtual ~CheatDetector() {}

    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void CaptureTimeSnapshot(unsigned int *timerTick, unsigned __int64 *systemFileTime);

    unsigned __int64 m_lastSystemFileTime;
    unsigned int m_lastTimerTick;
    unsigned int m_baselineTimerTick;
    unsigned __int64 m_baselineSystemFileTime;
};

extern CheatDetector *g_pCheatDetector;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheatDetector

## Status

- Confidence: strong for lifecycle, singleton, vtable, raw helper behavior, TimerHandler base relationship, and teardown support; medium for real detection behavior, final field names, and raw helper reachability.
- Likely source file: [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- Main address range: [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- Autogen status: reconstructable class attached to [UID:0000I6][CheatDetector](by-file/CheatDetector.md); first-draft declaration-level C++ is ready. The raw time-snapshot helper has no route to active execution, so active anti-cheat behavior remains unproven, but that no-route caveat no longer blocks the class declaration. The former base-teardown ambiguity is resolved to `TimerHandler`.

## Class Purpose

`CheatDetector` is a singleton anti-cheat/timer hook created during application initialization. The currently recovered class mostly owns lifecycle state: global registration, timer-handler base setup, vtable installation, zeroed counters, a trivial virtual check method, and teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CheatDetector::CheatDetector` | `0x00483f00-0x00483f85` | Sets `g_pCheatDetector` before base construction, constructs the `TimerHandler` base through `0x00597570`, installs vtable `0x00615564`, and clears fields at offsets `+0x10`, `+0x14`, `+0x18`, and `+0x1c`; constructor-unwind metadata at `0x005fc446` protects the early singleton publication. |
| [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) | `0x00483f90-0x00483fd9` | Private retained helper best named `CheatDetector::CaptureTimeSnapshot(unsigned int *timerTick, unsigned __int64 *systemFileTime)`. It snapshots `GetSystemTimeAsFileTime`, stores time fields at `+0x08/+0x0c`, samples `g_pTimerMgr + 0x18`, stores `+0x10`, and copies both snapshots to out-parameters; no incoming direct call, jump, VA pointer, or RVA pointer route was found. |
| [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md) | `0x00483fe0-0x00483fe5` | Exact `TimerHandler` override `bool CheatDetector::OnTimer(int timerId, int arg0, int arg1)` with unused receiver/arguments and unconditional `true` return. |
| [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) | `0x00483ff0-0x00483ffb` | `ClearCheatDetectorSingleton`, a no-argument constructor-unwind cleanup helper that clears `g_pCheatDetector` after early singleton publication if construction unwinds. |
| [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) | `0x00484000-0x0048402d` | `CheatDetectorScalarDeletingDestructor`; source semantic is `CheatDetector::~CheatDetector`, but the observed range is MSVC deleting-destructor glue over confirmed `TimerHandler_dtor`, singleton clear, delete flag, and optional free. |

## Data Notes

- [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md) lives at [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md).
- IDA confirms the two-slot [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md) / [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md) record: COL `0x00615560 -> ??_R4CheatDetector@@6B@`, object vptr `0x00615564`, slot `+0x00 -> 0x00484000`, slot `+0x04 -> 0x00483fe0`, and successor COL `0x0061556c -> ??_R4ClanStatusPane@@6B@`.
- Field names remain descriptive rather than proven original identifiers. Do not treat detection-count, last-check-time, suspicion-level, or active-state style labels as final without more timer callback evidence.
- Best current class layout:

| Offset | Field | Evidence and caveat |
| --- | --- | --- |
| `+0x00` | `TimerHandler` base/vptr | Base constructor writes the `TimerHandler` vtable, then the derived constructor writes `0x00615564`. |
| `+0x04` | alignment gap | The first source field is best modeled as an 8-byte file-time value at `+0x08`; MSVC default packing naturally leaves a 4-byte gap after the vptr before an `unsigned __int64`. |
| `+0x08` | `unsigned __int64 m_lastSystemFileTime` | [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) writes the low/high `FILETIME` dwords at `+0x08/+0x0c`. |
| `+0x10` | `unsigned int m_lastTimerTick` | The raw helper stores `[g_pTimerMgr + 0x18]` here and mirrors it to the first out-parameter. |
| `+0x14` | `unsigned int m_baselineTimerTick` | Constructor zeroing and adjacency to the tick/time comparison state support a baseline/comparison tick role; no later read is proven in the compact island. |
| `+0x18` | `unsigned __int64 m_baselineSystemFileTime` | Constructor zeroes `+0x18/+0x1c`, matching a second 64-bit file-time/baseline field; exact original name remains inferred. |

- The class declaration intentionally uses `unsigned __int64` for the file-time fields instead of `FILETIME` members. A `FILETIME` struct would normally align to 4 and would not explain the observed `+0x08` start without an explicit padding dword; an 8-byte integer field matches the observed vptr, padding, and field offsets.
- Source-facing destructor policy: declare `virtual ~CheatDetector()` and let MSVC regenerate the scalar deleting-destructor wrapper. Do not model `CheatDetectorScalarDeletingDestructor(unsigned int flags)` as handwritten source.
- Live IDA confirms [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) is still not modeled as a function and has no incoming xrefs, but its instruction-level behavior is stable and ties the class to [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) through singleton address `0x0067ab80` field `+0x18`.
- Live IDA confirms the true-return virtual slot at `0x00483fe0`, the singleton-clear helper at `0x00483ff0`, and the scalar deleting destructor at `0x00484000`. The 2026-06-16 A001 active-IDB refresh strengthens the base evidence: `0x00597570` writes `TimerHandler::vftable`, `0x00597580` is named `TimerHandler_dtor`, and both are shared by other timer-handler-style classes. The decompiler prototypes remain polluted, so final source headers should not copy those prototypes directly.
- 2026-06-19 B012 source-quality reanalysis resolves the [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) helper names and source-shape policy. `0x00483fe0` is the `TimerHandler` callback override because vtable slot `+0x04`, `retn 0x0c`, and the `ScheduledTimerEvent`/`TimerMgr::DispatchDueTimers` record shape imply three explicit callback arguments. `0x00483ff0` is constructor-unwind singleton cleanup, not an ordinary public method. `0x00484000` is scalar deleting-destructor glue; class-level source should model the ordinary destructor and let the compiler regenerate wrapper/delete-flag mechanics.
- 2026-06-11 A002 Batch 206 live IDA MCP reconfirmed the constructor vptr-store xref at `0x00483f52` to `0x00615564` and the vtable slot data refs to `0x00484000` and `0x00483fe0`, supporting direct assignment of [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md) to this class after the strict `85/85` gate.

## Cross-References

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md)
- [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md)
- [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md)
- [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## B004 Complete Source And ABI Closure

- Direct RTTI bases are `Singleton<CheatDetector>` PMD `+4,-1,0` and `TimerHandler` PMD `0,-1,0`, both attributes `0x40`. Source declaration order is Singleton then TimerHandler; polymorphic TimerHandler occupies offset zero while Singleton uses empty-base overlap at `+4`.
- `sizeof(CheatDetector)==0x20`, independently fixed by Application allocation and scalar-wrapper free size. State is `m_lastSystemFileTime` at `+0x08`, `m_lastTimerTick` at `+0x10`, `m_baselineTimerTick` at `+0x14`, and `m_baselineSystemFileTime` at `+0x18`.
- Source children are [UID:0004UO][0x00483f00-0x00483f86.CheatDetectorConstructor](by-memory/0x00483f00-0x00483f86.CheatDetectorConstructor.md), retained [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md), and [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md).
- Compiler-only children are [UID:0004UQ][0x00483ff0-0x00483ffb.CheatDetectorSingletonClearCompilerSupport](by-memory/0x00483ff0-0x00483ffb.CheatDetectorSingletonClearCompilerSupport.md) and [UID:0004UR][0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor](by-memory/0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor.md); neither emits C++ or a proof marker.
- The exact two-slot vtable is scalar deleting destructor at `+0x00` and `OnTimer(int,int,int)` at `+0x04`. The inline empty virtual destructor is the ordinary source carrier and regenerates deleting-wrapper/base teardown behavior.
- Constructor source initializes only `m_lastTimerTick`, `m_baselineTimerTick`, and `m_baselineSystemFileTime`. It intentionally does not initialize `m_lastSystemFileTime`, matching exact stores.
- `CaptureTimeSnapshot` remains source-authored but has exhaustive zero incoming call/jump/VA/RVA/raw-pointer routes; this caps active anti-cheat behavior confidence without changing ownership or source disposition.
- `OnTimer` returns true unconditionally and uses `timerId` as the best TimerMgr-facing parameter name. Anti-cheat check names and added state mutation are rejected.
- Header/source one-definition policy is `extern CheatDetector *g_pCheatDetector;` here and one zero definition in UID0000QJ. No explicit vptr, cookie, delete flag, global assignment, ABI helper, or padding field belongs in source.

## Changes

- 2026-06-11 A002 Batch 206 parent-gate refresh:
  - Before: class scores were `82/84`, below the strict parent gate for [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md).
  - Changed to: `85/86`.
  - Summary/evidence: live IDA MCP reconfirmed exact vtable/COL dwords, constructor store xref, slot targets, successor clan boundary, and consistency with the constructor/virtual/destructor class island. Remaining uncertainty is documented and confined to polluted base prototypes, raw helper reachability, and final field names, not the class/vtable ownership.
- 2026-06-16 A001 support refresh:
  - Changed to: no score change.
  - Summary/evidence: active IDB checks resolved the former base-name wording to strong `TimerHandler` inheritance evidence through `0x00597570` and `0x00597580`, while preserving the real blockers: raw time-snapshot helper reachability, final field names, and polluted decompiler prototypes.
- 2026-06-19 B012 source-quality incorporation:
  - Changed to: no class score change.
  - Summary/evidence: incorporated B012's resolved names for `CheatDetector::OnTimer`, `ClearCheatDetectorSingleton`, and `CheatDetectorScalarDeletingDestructor`; documented `TimerHandler_dtor` as the base teardown; rejected stale EventDispatcher/boost/free-function/application-owner readings; and kept class C++ blank because the raw time-snapshot helper, final fields, and final class/header split remain unresolved.
- 2026-06-20 B002 Rule 26 incorporation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: incorporated B002's class source-quality report, populated declaration-level C++ with `TimerHandler` inheritance, `OnTimer(int eventId, int arg0, int arg1)`, private `CaptureTimeSnapshot(unsigned int*, unsigned __int64*)`, `unsigned __int64` file-time fields, baseline timer fields, an out-of-class `[[CHILDREN]]` expansion point for method bodies/support children, and `extern CheatDetector *g_pCheatDetector`. The raw helper still has no direct call/jump/VA/RVA route, so active detection behavior remains unproven; that now caps runtime confidence instead of blocking class/header reconstruction.
- 2026-06-12 A004 Batch 341 reference cleanup: added exact source-local [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md) as the concrete type-vtable page; [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) is now retained only as a non-emitting mixed security-vtable index.
- 2026-06-05 live evidence refresh:
  - Before: the class page scored `76/80`, contained a stale recovered-file pointer, and still referenced generated-output and historical metadata state.
  - Changed to: `82/84`, with evidence anchored to live IDA and project-documentation only.
  - Summary/evidence: live IDA confirms constructor `0x00483f00`, raw helper bytes `0x00483f90-0x00483fd9`, vtable helper `0x00483fe0`, singleton-clear helper `0x00483ff0`, scalar deleting destructor `0x00484000`, vtable slots `0x00615564/0x00615568`, singleton slot `0x0067ab3c`, timer singleton `0x0067ab80`, startup caller `0x0046473e`, and all local padding boundaries. Remaining uncertainty is base type, raw helper reachability, and final field names.
- 2026-06-03 low-confidence evidence refresh: Existing class metadata was `72/78`, reconstructable was blank, and the method inventory omitted the raw time-snapshot helper. Changed scores to `76/80`, marked the class reconstructable, added [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) to the method table, and recorded the `g_pTimerMgr` dependency. Evidence: IDA MCP review of `0x00483f90-0x00483fd9` confirmed the complete raw `retn 8` helper body, no incoming xrefs/literal refs, `GetSystemTimeAsFileTime` import use, and timer singleton `0x0067ab80` field `+0x18` read; [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) documents that singleton.
- 2026-06-03 parent attachment: Existing class autogen parent was blank because [UID:0000I6][CheatDetector](by-file/CheatDetector.md) had not yet reached the confidence gate or projected path. Changed `AUTOGEN_PARENT_UID` to [UID:0000I6][CheatDetector](by-file/CheatDetector.md). Evidence: the file page now has `CONFIDENCE:80`, a valid `NexusTK/security/` path already supported by [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md), and matching IDA evidence for the class island and raw time-snapshot helper.
- What existed before: the page documented lifecycle, singleton, vtable, and stale metadata caveats, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: constructor, singleton clear, true-return virtual, destructor, vtable, and Application/global references are documented; real detection behavior and timer callback semantics remain mostly unresolved.
