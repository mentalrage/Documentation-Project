*** UID:0000I6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CheatDetector

## Status

- Confidence: strong for class role, startup construction, singleton/vtable ownership, TimerHandler base relationship, helper/source-shape classification, and security module placement; medium for raw helper reachability and final field/source names.
- Proposed module: `security/CheatDetector.cpp`
- Main address range: [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- Projected reconstruction path: `NexusTK/security/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) and the paired [UID:0000P5][VirusChecker](by-file/VirusChecker.md) security module placement.

## File Role

`CheatDetector` is a small startup-created singleton rooted in timer/event infrastructure. The recovered active behavior is mostly lifecycle: constructor installs [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md), initializes a base timer handler, sets the `CheatDetector` vtable, and clears four state counters/fields.

The only currently visible virtual check method returns true unconditionally, so the class looks like a retained or lightly implemented anti-cheat timer hook rather than a complete detector in the recovered body. Keep it separate from [UID:0000P5][VirusChecker](by-file/VirusChecker.md): `CheatDetector` is an in-client timer singleton, while `VirusChecker` is a DLL-backed process/module/file scanner.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:000020][CheatDetector](by-class/CheatDetector.md) | `0x00483f00-0x0048402d` | Direct `Singleton<CheatDetector>, TimerHandler` class, 0x20 layout, inline empty destructor, and exact source/compiler children. |
| [UID:0004UO][0x00483f00-0x00483f86.CheatDetectorConstructor](by-memory/0x00483f00-0x00483f86.CheatDetectorConstructor.md) | `0x00483f00-0x00483f86` | Source constructor with direct-base lowering, early singleton publication, TimerHandler construction, derived vptr installation, and exact initializer-list state. |
| [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) | `0x00483f90-0x00483fd9` | Private retained `CheatDetector::CaptureTimeSnapshot(unsigned int*, unsigned __int64*)`; samples `GetSystemTimeAsFileTime`, stores timer/time snapshots on the object, reads `g_pTimerMgr + 0x18`, and copies both values to out-parameters. No caller surface was found, so active detection use remains unproven. |
| [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md) | `0x00483fe0-0x00483fe5` | Source `OnTimer(timerId,arg0,arg1)` override returning true. |
| [UID:0004UQ][0x00483ff0-0x00483ffb.CheatDetectorSingletonClearCompilerSupport](by-memory/0x00483ff0-0x00483ffb.CheatDetectorSingletonClearCompilerSupport.md) | `0x00483ff0-0x00483ffb` | Constructor-unwind Singleton clear; compiler-only and non-emitting. |
| [UID:0004UR][0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor](by-memory/0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor.md) | `0x00484000-0x0048402d` | Vtable-only scalar deleting destructor; compiler-only and non-emitting. |
| [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md) | `0x00615564` | Two-slot RTTI-backed vtable: scalar deleting destructor and true-return virtual check. |
| [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md) | [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md) | Process singleton set by the constructor and cleared by destructor helpers. |

## Evidence Notes

- IDA MCP confirms `0x00483f00`, `0x00483fe0`, `0x00483ff0`, and `0x00484000` as real functions.
- IDA xrefs show the constructor is called from `Application::Initialize` at `0x0046473e`.
- IDA xrefs show the virtual method and scalar deleting destructor are referenced by the vtable around `0x00615564`.
- IDA vtable read on 2026-05-26 confirms object vptr `0x00615564`, RTTI pointer `0x00615560`, slot `+0x00 -> 0x00484000`, and slot `+0x04 -> 0x00483fe0`.
- 2026-06-11 A002 Batch 206 live IDA MCP reconfirmed [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md): `0x00615560 -> ??_R4CheatDetector@@6B@`, `0x00615564 -> 0x00484000`, `0x00615568 -> 0x00483fe0`, constructor vptr-store xref `0x00483f52`, and `0x0061556c -> ??_R4ClanStatusPane@@6B@` as the successor boundary.
- 2026-05-24 IDA recheck confirms `0x00483fe0` is a vtable-only function returning true, `0x00483ff0` clears `g_pCheatDetector`, and `0x00484000` is vtable-referenced from `0x00615564`.
- The callback/compiler split is now exact: [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md) owns `bool CheatDetector::OnTimer(int timerId, int arg0, int arg1)`, while UID0004UQ owns constructor-unwind Singleton clear and UID0004UR owns the MSVC scalar deleting wrapper. The `timerId` name supersedes historical `eventId` wording because TimerMgr/ScheduledTimerEvent queue semantics provide the stronger source-facing contract.
- Live IDA now gives the timer base relationship stronger support than the older base-type caveat. Active IDB checks on 2026-06-16 show `0x00597570` writes `TimerHandler::vftable`, is called by the CheatDetector constructor and other timer-handler-style classes, and `0x00597580` is named `TimerHandler_dtor`. The decompiler prototypes remain polluted, so final C++ should use this as inheritance evidence but not as final header spelling by itself.
- Live IDA confirms [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) as executable project code inside the `CheatDetector` island, with no IDA function record, no incoming xrefs, a `GetSystemTimeAsFileTime` import call, and a `g_pTimerMgr + 0x18` read.
- 2026-06-19 B002 source-quality report resolves the file-level source shape enough for draft code: `CheatDetector.cpp` should emit the `TimerHandler`-derived class declaration, `extern CheatDetector *g_pCheatDetector`, and the private `CaptureTimeSnapshot` helper body under `NexusTK/security/`. The raw helper's missing direct-call/jump/VA/RVA route limits active detection claims, not the class/header/helper draft.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `CheatDetector.cpp` and `VirusChecker.cpp` under `security/`; assigning `NexusTK/security/` here aligns the file page with that documented project-structure decision while keeping confidence capped by raw-helper reachability, final field names, and polluted base prototypes.
- 2026-06-16 A001 active-IDB refresh on `b001_mappane_0001AW_20260616` reports named lifecycle functions at `0x00483f00` (`CheatDetectorConstructor`), `0x00483ff0` (`ClearCheatDetectorSingleton`), and `0x00484000` (`CheatDetectorScalarDeletingDestructor`), plus the true-return vtable slot at `0x00483fe0`; the raw time-snapshot helper at `0x00483f90` is still not a function and still has zero xrefs.
- `xrefs_to 0x0067ab3c` still reports the five expected singleton refs: application cleanup reader `0x00464ba0`, constructor publish/guard clear at `0x00483f33`/`0x00483f3a`, clear helper `0x00483ff0`, and scalar deleting destructor clear `0x0048400f`. `0x00615564` has the constructor vptr-store ref at `0x00483f52`, and the vtable entries still point at the deleting destructor and true-return check.

## Migration Notes

- Candidate simpath: `security/CheatDetector.cpp`.
- Emit declaration-level class C++ through [UID:000020][CheatDetector](by-class/CheatDetector.md), with method bodies owned by their by-memory children where they are source-authored and not compiler support.
- Keep the `0x00483fe0` always-true virtual method documented as the `CheatDetector::OnTimer` `TimerHandler` callback override; it is a real vtable slot even though its direct caller surface is vtable dispatch rather than ordinary direct calls.
- Do not emit `0x00483ff0` or `0x00484000` as handwritten helpers in `CheatDetector.cpp`. `ClearCheatDetectorSingleton` is constructor-unwind cleanup, and `CheatDetectorScalarDeletingDestructor` is compiler deleting-destructor glue over the ordinary destructor/base teardown source shape.
- Keep [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) visible as source-authored project code. Its first-draft helper C++ is ready as `CaptureTimeSnapshot`; final runtime interpretation remains capped because no active route to the helper has been found.
- Do not merge this into `Application.cpp`: application startup constructs it, but the singleton/vtable and timer base make it a distinct module.

## Cross-References

- [UID:000020][CheatDetector](by-class/CheatDetector.md)
- [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md)
- [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md)
- [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md)
- [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## B004 Complete Source/Compiler Union

- Source order is one zero `g_pCheatDetector` definition at position zero, the complete direct-base class declaration, constructor, retained CaptureTimeSnapshot helper, OnTimer callback, and inline empty destructor carrier.
- Direct hierarchy is `Singleton<CheatDetector>` then `TimerHandler`; RTTI PMDs establish Singleton EBO at `+4`, TimerHandler at offset zero, and a `0x20` complete object.
- The exact source definitions are UID0004UO, UID0002EN, and UID0004UP. UID0004UQ, UID0004UR, UID0003JE, and UID00024Y are compiler-generated support and emit no handwritten C++ or markers.
- UID000108 and UID000109 are false/non-emitting split indexes that preserve complete byte/range/padding/history evidence without duplicating source.
- Application startup allocates and constructs the object; Application cleanup consumes the external pointer through ordinary `delete`. TimerHandler/TimerMgr are infrastructure dependencies, not source owners.
- The helper's exhaustive no-route result is preserved as a liveness cap: the file contains retained time-snapshot source but no proven active detection rule.
- No duplicate global definition, raw address, explicit vptr/cookie/delete flag, ABI wrapper, handwritten vtable, or artificial header/source split is accepted.

## Changes

- 2026-06-11 A002 Batch 206 parent-gate refresh:
  - Before: confidence was `80`, below the strict parent gate for exact CheatDetector data children.
  - Changed to: confidence `85`, completion remains `86`.
  - Summary/evidence: live IDA MCP reconfirmed the exact [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md), constructor store xref, two-slot vtable shape, `ClanStatusPane` successor boundary, and consistency with the compact class island and `NexusTK/security/` placement. Confidence remains below final because the exact timer/event base name and raw time-snapshot helper reachability remain unresolved.
- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Changed to: completion `87`, confidence `87`.
  - Summary/evidence: active IDB checks confirmed the lifecycle function names, constructor startup caller, five singleton storage refs, vtable store/slot refs, raw helper no-function/no-xref state, and stronger TimerHandler base evidence from `0x00597570`/`0x00597580`. Final C++ remains gated by the unreachable raw helper, provisional object-field names, and polluted base prototypes.
- 2026-06-19 B012 source-quality incorporation:
  - Changed to: no file score change.
  - Summary/evidence: updated the proposed contents to the exact `0x00483f00-0x0048402d` class island and incorporated B012's [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) conclusions: `OnTimer` callback signature inference, `ClearCheatDetectorSingleton` constructor-unwind role, `CheatDetectorScalarDeletingDestructor` wrapper policy, confirmed `TimerHandler_dtor` base teardown, rejected stale EventDispatcher/boost/application-owner routes, and the reason formal C++ remains blank for the combined memory range.
- 2026-06-20 B002 Rule 26 incorporation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:88`.
  - Summary/evidence: incorporated class/header readiness, private `CaptureTimeSnapshot` helper source body, first-draft global declaration direction, `TimerHandler` inheritance, `OnTimer(eventId,arg0,arg1)` callback shape, scalar deleting-destructor policy, field layout, and the narrowed no-route caveat. The no-route helper still prevents claiming active anti-cheat behavior, but it no longer blocks draft class/helper source.
- 2026-06-12 A004 Batch 341 reference cleanup: proposed contents now use exact source-local [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md); the mixed [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) page remains only as a cross-reference index.
- 2026-06-03 parent-chain and projected-path pass:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `84/78`, and the proposed contents omitted the raw time-snapshot helper.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/"`, scores `86/80`, and contents/evidence now include [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md).
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `security/CheatDetector.cpp`, the file page already proposed `security/CheatDetector.cpp`, [UID:0000P5][VirusChecker](by-file/VirusChecker.md) is already staged under `NexusTK/security/`, and the 2026-06-03 IDA MCP raw helper pass confirmed the additional timer-snapshot helper inside the compact `CheatDetector` island. Confidence is still only `80` because exact timer/event base naming and helper reachability remain unresolved.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: file-level role, singleton/vtable/global ownership, startup construction, migration target, and base-type caveats are documented; confidence remains below strong because final source folder and the exact timer/event base label are still unresolved.
- 2026-06-05 stale-evidence cleanup:
  - Before: the status/evidence sections referenced recovered-output paths and generated-output state.
  - After: file evidence relies on project-documentation and live IDA only.
  - Evidence: live IDA confirms the constructor, raw time-snapshot helper, vtable helper, singleton-clear helper, scalar deleting destructor, vtable slots, singleton slot, startup caller, and timer-manager dependency.
