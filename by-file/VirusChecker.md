*** UID:0000P5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# VirusChecker

## Status

- Confidence: strong for local scanner/DLL helper behavior, medium for live runtime path.
- Proposed module: `security/VirusChecker.cpp`
- Current recovered source: `source-3/simroot_v2/class_VirusChecker.cpp`
- Main address range: [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)

## File Role

`VirusChecker` is a retained AhnLab/V3-backed process, module, and file scanner. It loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, and `V3PCtrl_EnumModules`, enumerates process modules into a string-keyed tree, checks each file path, and reports detections through localized text and fatal/close UI paths.

Current IDA xrefs do not show direct callers to the constructor, DLL-load helper, or scan helper. Treat the module as real project code with uncertain live activation rather than as proven startup-critical code.

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

- IDA MCP confirms a local function island from `0x005c0460` through `0x005c0fe1`; `0x005c0ff0` begins unrelated `WaitableTimer` construction and should stay out of this file.
- IDA decompilation of `0x005c05a0` shows `LoadLibraryA("V3PRO32E.DLL")`, `LoadLibraryA("V3PCTRL.DLL")`, and `GetProcAddress` calls for the AhnLab/V3 exports.
- IDA decompilation of `0x005c07b0` shows process enumeration, `AhnExCheckFile`, `AhnExGetVirusName`, localized message formatting through [UID:0000KK][LanguageMan](by-file/LanguageMan.md), a fatal/alert call, and a screen/application close path.
- 2026-05-24 `simroot_v2` recheck: active `class_VirusChecker.cpp` still emits only the constructor, destructor, and scalar deleting destructor. The recursive tree cleanup appears separately as `recovered/DestroyVirusCheckerProcessTreeNodes_005C0FA0.cpp`, but scanner/load/tree helpers from `0x005c05a0-0x005c0ea6` are still absent from the active class file.
- 2026-05-24 IDA xref recheck found no direct code/data refs to the constructor, destructor, DLL-load helper, or scan entry point. Internal callback/helper evidence remains: `0x005c0aa0` is referenced as callback data from `0x005c07da`, `0x005c09f0` from `0x005c0aa6`, and `0x005c0ec0` from vtable data at `0x006310e0`.
- 2026-05-26 IDA vtable read confirms object vptr `0x006310e0`, RTTI pointer `0x006310dc`, and one function slot before adjacent `V3PRO32E.DLL` string data begins at `0x006310e4`.
- 2026-05-26 recheck using `simroot_v2` and IDA MCP only: active output still omits `0x005c05a0-0x005c0fe1` except for the recovered recursive cleanup; IDA still reports no direct callers for the constructor, load helper, or scan entry.

## Migration Notes

- Candidate simpath: `security/VirusChecker.cpp`.
- Attach or file-own the helper island before treating generated `class_VirusChecker.cpp` as complete source.
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
