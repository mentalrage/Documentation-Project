*** UID:000020 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheatDetector

## Status

- Confidence: medium-strong for recovered lifecycle, medium for real detection behavior.
- Likely source file: [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- Main address range: [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md)
- Current recovered file: `source-3/simroot_v2/class_CheatDetector.cpp`

## Class Purpose

`CheatDetector` is a singleton anti-cheat/timer hook created during application initialization. The currently recovered class mostly owns lifecycle state: global registration, timer-handler base setup, vtable installation, zeroed counters, a trivial virtual check method, and teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CheatDetector::CheatDetector` | `0x00483f00-0x00483f85` | Sets `g_pCheatDetector`, constructs a timer-handler style base, installs vtable, clears fields at offsets `0x10`, `0x14`, `0x18`, and `0x1c`. |
| [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) | `0x00483fe0-0x00483fe5` | Disabled in active output but IDA-confirmed; returns true unconditionally. |
| [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) | `0x00483ff0-0x00483ffb` | Clears `g_pCheatDetector`. |
| [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) | `0x00484000-0x0048402d` | Clears singleton and optionally frees object memory after base teardown. |

## Data Notes

- [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md) lives at [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md).
- IDA confirms the two-slot [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) uses object vptr `0x00615564`: slot `+0x00` is `0x00484000`, and slot `+0x04` is `0x00483fe0`.
- Current generated field names are still generic counter/state names; do not treat `m_detectionCount`, `m_lastCheckTime`, `m_suspicionLevel`, and `m_isActive` as final without more timer callback evidence.
- 2026-05-26 recheck: active output still omits or disables the linked helper page's true-return virtual and singleton clear helper; destructor base naming remains polluted.
- Current exported metadata retains historical `~CheatDetector\r` name records in transformation history even though active output uses `ScalarDeletingDestructor`; treat those history rows as stale metadata, not final names.

## Cross-References

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md)
- [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md)
- [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## Changes

- What existed before: the page documented lifecycle, singleton, vtable, and stale metadata caveats, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: constructor, singleton clear, true-return virtual, destructor, vtable, and Application/global references are documented; real detection behavior and timer callback semantics remain mostly unresolved.
