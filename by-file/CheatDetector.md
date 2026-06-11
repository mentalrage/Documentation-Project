*** UID:0000I6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CheatDetector

## Status

- Confidence: medium-strong for class role and startup construction, medium for final file/folder placement.
- Proposed module: `security/CheatDetector.cpp`
- Main address range: [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md)
- Projected reconstruction path: `NexusTK/security/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) and the paired [UID:0000P5][VirusChecker](by-file/VirusChecker.md) security module placement.

## File Role

`CheatDetector` is a small startup-created singleton rooted in timer/event infrastructure. The recovered active behavior is mostly lifecycle: constructor installs [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md), initializes a base timer handler, sets the `CheatDetector` vtable, and clears four state counters/fields.

The only currently visible virtual check method returns true unconditionally, so the class looks like a retained or lightly implemented anti-cheat timer hook rather than a complete detector in the recovered body. Keep it separate from [UID:0000P5][VirusChecker](by-file/VirusChecker.md): `CheatDetector` is an in-client timer singleton, while `VirusChecker` is a DLL-backed process/module/file scanner.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:000020][CheatDetector](by-class/CheatDetector.md) | `0x00483f00-0x0048402c` | Constructor, raw time-snapshot helper, disabled always-true virtual check, singleton-clear helper, scalar deleting destructor. |
| [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) | `0x00483f90-0x00483fd9` | Raw unmodeled helper that samples `GetSystemTimeAsFileTime`, stores timer/time snapshots on the object, and reads `g_pTimerMgr + 0x18`; no caller surface found. |
| [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) | `0x00483fe0-0x0048402d` | Always-true vtable slot, singleton clear helper, and scalar deleting destructor with polluted base-teardown naming. |
| [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) | `0x00615564` | Two-slot RTTI-backed vtable: scalar deleting destructor and true-return virtual check. |
| [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md) | [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md) | Process singleton set by the constructor and cleared by destructor helpers. |

## Evidence Notes

- IDA MCP confirms `0x00483f00`, `0x00483fe0`, `0x00483ff0`, and `0x00484000` as real functions.
- IDA xrefs show the constructor is called from `Application::Initialize` at `0x0046473e`.
- IDA xrefs show the virtual method and scalar deleting destructor are referenced by the vtable around `0x00615564`.
- IDA vtable read on 2026-05-26 confirms object vptr `0x00615564`, RTTI pointer `0x00615560`, slot `+0x00 -> 0x00484000`, and slot `+0x04 -> 0x00483fe0`.
- 2026-05-24 IDA recheck confirms `0x00483fe0` is a vtable-only function returning true, `0x00483ff0` clears `g_pCheatDetector`, and `0x00484000` is vtable-referenced from `0x00615564`.
- Live IDA still labels the destructor base-teardown target with a polluted local type name, while constructor and timer-helper evidence indicate timer-handler-style ownership; treat the exact base label as unresolved until inheritance is recovered from project-documentation/live IDA evidence.
- Live IDA confirms [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) as executable project code inside the `CheatDetector` island, with no IDA function record, no incoming xrefs, a `GetSystemTimeAsFileTime` import call, and a `g_pTimerMgr + 0x18` read.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `CheatDetector.cpp` and `VirusChecker.cpp` under `security/`; assigning `NexusTK/security/` here aligns the file page with that documented project-structure decision while keeping confidence capped by unresolved base-type and helper reachability questions.

## Migration Notes

- Candidate simpath: `security/CheatDetector.cpp`.
- Keep the `0x00483fe0` always-true virtual method documented; it is a real vtable slot even though its caller surface is currently only the vtable data.
- Keep [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) visible as source-authored project code, but do not emit final C++ for it until caller/reachability and field names reach the `95+` code-emission gate.
- Do not merge this into `Application.cpp`: application startup constructs it, but the singleton/vtable and timer base make it a distinct module.

## Cross-References

- [UID:000020][CheatDetector](by-class/CheatDetector.md)
- [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md)
- [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md)
- [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

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
