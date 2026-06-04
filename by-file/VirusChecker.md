*** UID:0000P5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# VirusChecker

## Status

- Confidence: strong for local scanner/DLL helper behavior and file ownership, medium for live runtime path.
- Proposed module: `NexusTK/security/VirusChecker.cpp`
- Main address range: [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)

## File Role

`VirusChecker` is a retained AhnLab/V3-backed process, module, and file scanner. It loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, and `V3PCtrl_EnumModules`, enumerates process modules into a string-keyed tree, checks each file path, and reports detections through localized text and fatal/close UI paths.

Live IDA xrefs do not show direct callers to the constructor, DLL-load helper, or scan helper. Treat the module as real project code with uncertain live activation rather than as proven startup-critical code.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:0000FW][VirusChecker](by-class/VirusChecker.md) | `0x005c0460-0x005c0f93` | Singleton lifecycle, V3 module cleanup, scalar deleting destructor. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c05a0-0x005c0937` | Loads V3 DLLs, resolves exports, reports localized load/entrypoint errors, enumerates processes/modules, calls `AhnExCheckFile`, and reports a virus name. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0940-0x005c0fe1` | Inserts callback paths and allocates/inserts/destroys red-black-tree style nodes that store scanned module path strings. |
| [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) | `0x006310e0` | One-slot RTTI-backed vtable containing the scalar deleting destructor. |
| [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md) | object offsets `+0x04/+0x08`, node offsets through `+0x10` | Embedded ordered path-set header/count and red-black-tree node layout for scanned module paths. |
| [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) | [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md) | Singleton pointer set and cleared by lifecycle helpers. |

## Evidence Notes

- 2026-06-04 live IDA identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Live IDA confirms a local function island from `0x005c0460` through `0x005c0fe1`: constructor `0x005c0460-0x005c04e0`, destructor `0x005c04e0-0x005c059d`, DLL/export loader `0x005c05a0-0x005c076d`, scanner `0x005c07b0-0x005c0937`, tree/path helpers `0x005c0940-0x005c0ea7`, singleton clear helper `0x005c0eb0-0x005c0ebb`, and scalar deleting destructor `0x005c0ec0-0x005c0f94`.
- `0x005c0fe1-0x005c0ff0` is fifteen `0xcc` bytes, and `0x005c0ff0` begins the next `WaitableTimer` constructor, so the file boundary remains exact.
- Live xrefs still show no direct callers for the constructor `0x005c0460`, destructor `0x005c04e0`, loader `0x005c05a0`, scanner `0x005c07b0`, tree insert `0x005c0940`, process callback `0x005c0aa0`, or scalar deleting destructor `0x005c0ec0`; the only `0x005c0eb0` code xref is a compiler EH cleanup thunk at `0x0060bc76`.
- Internal callback refs remain exact: `0x005c07da` passes `0x005c0aa0` to `V3PCtrl_EnumProcesses`, and `0x005c0aa6` passes `0x005c09f0` to `V3PCtrl_EnumModules`.
- Constructor and teardown evidence is live: `0x005c0460` writes `g_pVirusChecker` at `0x0069bf94`, installs vtable `0x006310e0`, initializes the embedded path tree, and calls `0x005796d0`; `0x005c04e0` and `0x005c0ec0` free V3 modules, clear V3 function pointers, destroy tree nodes, free the sentinel, and clear `g_pVirusChecker`.
- Read-only V3 evidence is exact: `0x006310e4` `V3PRO32E.DLL`, `0x006310f4` `AhnExCheckFile`, `0x00631104` `AhnExGetVirusName`, `0x00631118` `V3PCTRL.DLL`, `0x00631124` `V3PCtrl_EnumProcesses`, and `0x0063113c` `V3PCtrl_EnumModules`.
- Dynamic-library globals at `0x0069bf7c-0x0069bf94` start as `0xffffffff` dwords and are referenced only by the local loader/scanner/teardown code: enum-processes, enum-modules, check-file, get-virus-name, module handles, and `g_pVirusChecker`.
- IDA decompilation of `0x005c05a0` shows `LoadLibraryA`, `GetProcAddress`, localized error formatting through [UID:0000KK][LanguageMan](by-file/LanguageMan.md), and `MessageBoxW` failure reporting for missing V3 DLLs or exports.
- IDA decompilation of `0x005c07b0` shows process enumeration, module enumeration through callback `0x005c0aa0`, path-tree iteration, `AhnExCheckFile`, `AhnExGetVirusName`, localized detection text key `221`, a fatal/alert call, and a screen/application close path.

## Migration Notes

- Candidate reconstruction path: `NexusTK/security/VirusChecker.cpp`.
- Keep the constructor, scanner, callback, tree, teardown, vtable, and globals owned by this file unless later live xrefs prove split ownership.
- Keep the AhnLab module handles and function pointers module-local to this file unless later xrefs prove broader use.

## Cross-References

- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md)
- [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/76`. Summary/evidence: the page captures the scanner/DLL wrapper role, method contents, IDA evidence, and anticheat refs; live invocation and final runtime path are still uncertain.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `VirusChecker.cpp` under `security`; IDA confirms the AhnLab/V3 scanner wrapper range and singleton lifecycle, while live activation remains open.
- 2026-06-04: Raised file score and replaced stale source-output notes with fresh live IDA evidence.
  - Before: `COMPLETION:84` and `CONFIDENCE:76`.
  - After: `COMPLETION:86` and `CONFIDENCE:84`.
  - Evidence: IDA MCP rechecked the exact function island, no-direct-caller state, EH cleanup thunk, V3 DLL/export strings, dynamic-library globals, constructor/destructor/vtable refs, callback chain, process-tree helpers, and padding boundary before `WaitableTimer`. Confidence remains capped below 90 because normal runtime activation is still not proven.
