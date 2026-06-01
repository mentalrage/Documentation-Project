*** UID:0000FW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VirusChecker

## Status

- Confidence: strong for recovered behavior, medium for live activation.
- Likely source file: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- Main address range: [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- Current recovered file: `source-3/simroot_v2/class_VirusChecker.cpp`

## Class Purpose

`VirusChecker` is a small singleton wrapper around AhnLab/V3 scanning DLLs. It owns a tree of process/module paths, scans those paths with `AhnExCheckFile`, reports detections with the virus name from `AhnExGetVirusName`, and frees the V3 modules/function pointers during teardown.

## Method And Helper Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `VirusChecker::VirusChecker` | `0x005c0460-0x005c04df` | Sets singleton, installs vtable, initializes state, allocates process-tree sentinel. |
| `~VirusChecker` | `0x005c04e0-0x005c059c` | Frees V3 DLL modules, clears function pointers, destroys process tree, clears singleton. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c05a0-0x005c076d` | Loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves scan/enumeration exports, shows localized errors on failure. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c07b0-0x005c0937` | Uses V3 process/module enumeration callbacks, checks module paths, reports detection, closes/terminates client path. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0940-0x005c09ec` | Inserts a module path into the process-tree set. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c09f0-0x005c0aa0` | Converts a module path and inserts it into the checker tree. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0aa0-0x005c0ac0` | Calls V3 module enumeration for each process. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0ac0-0x005c0fe1` | Allocates, inserts, balances, and destroys process-tree nodes. |
| scalar deleting destructor | `0x005c0ec0-0x005c0f93` | Calls destructor and frees object when requested. |

## Data Notes

- [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) is at [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md).
- IDA confirms the one-slot [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) uses object vptr `0x006310e0`; the only function slot is scalar deleting destructor `0x005c0ec0`.
- The observed object and path-tree fields are recorded in [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md). In particular, object offset `+0x08` behaves as a tree node count, so the active generated name `m_state` is provisional.
- Module/function pointer globals in IDA include `dword_69BF90` for `V3PCTRL.DLL`, `dword_69BF80` for `V3PCtrl_EnumModules`, `AhnExCheckFile`, and `dword_69BF88` for `AhnExGetVirusName`.
- 2026-05-26 recheck: active `simroot_v2/class_VirusChecker.cpp` still omits the V3 load/scan and tree helper pages linked above, except for the recovered recursive cleanup helper.
- Current exported metadata still contains historical control-character name records such as `~VirusChecker\r` and old name-control grade reasons. The active generated source uses clean canonical names, so treat the metadata history rows as stale and prefer IDA plus current active code for naming.
- 2026-05-31 IDA MCP recheck confirms the object layout, V3 DLL load/scan helpers, process/module callback chain, red-black-tree-style path set, singleton xrefs, and boundary before `WaitableTimer`. The class is reconstructable project code, but parent/code attachment remains blank until live activation and final source names are near-final.

## Cross-References

- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md)
- [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the singleton constructor/destructor, V3 load/scan helpers, process-tree helpers, global function/module pointers, vtable/layout evidence, simroot omission notes, and stale metadata caveats; confidence remains capped by medium live-activation evidence.
- 2026-05-31 reconstructable flag:
  - What existed before: blank `RECONSTRUCTABLE`.
  - Changed to: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms this class as NexusTK-owned wrapper/source code around dynamically loaded V3 scanner DLLs, with local singleton lifecycle and process-tree ownership.
