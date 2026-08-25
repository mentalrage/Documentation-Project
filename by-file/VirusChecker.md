*** UID:0000P5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# VirusChecker

## Status

- Confidence: very strong for the source root, direct class inheritance, local scanner/DLL helper behavior, V3 global/string/vtable/container evidence, and first-draft readiness; normal activation remains an execution-path caveat.
- Proposed module: `NexusTK/security/VirusChecker.cpp`
- Main address range: [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)

## File Role

`VirusChecker` is a retained AhnLab/V3-backed process, module, and file scanner. It loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, and `V3PCtrl_EnumModules`, enumerates process modules into a string-keyed tree, checks each file path, and reports detections through localized text and fatal/close UI paths.

The source root contains a direct `VirusChecker : public Singleton<VirusChecker>` class with a virtual destructor. Current RTTI proves the direct visible non-virtual template base at PMD `+0x04`; the constructor/destructor singleton publication/clear, vptr stores, RTTI objects, one-slot vtable, and scalar deleting wrapper are compiler/template lowering rather than separate handwritten entities in this file.

The dated MCP session `e63ee655` xrefs and pointer-pattern checks do not show direct callers or pointer routes to the constructor, destructor, DLL-load helper, reset helper, scan helper, tree insert helper, or singleton clear helper, and no external `g_pVirusChecker` consumer route was found. Treat the module as real retained project code with uncertain/optional activation rather than as proven startup-critical code or no-owner dead code. The older `86fb854e` cleanup remains historical support only.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:0000FW][VirusChecker](by-class/VirusChecker.md) | `0x005c0460-0x005c0f93` | Direct `Singleton<VirusChecker>` class, virtual destructor, first-draft class/source-shape C++, authored V3/container behavior, and compiler/template lifecycle-lowering policy. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c05a0-0x005c0937` | Formal first-draft C++ for `LoadV3Scanner`, raw no-xref `ResetV3ScannerState`, and `ScanLoadedProcessModules`; localized ids `219`/`220`/`221`; V3 function-pointer typedefs; `AhnExCheckFile`; and detection shutdown route. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0940-0x005c0fe1` | Source-ready `InsertModulePath`, typed stdcall `V3ModuleEnumCallback`, and typed stdcall `V3ProcessEnumCallback` definitions over private `ModulePathString`, `ModulePathLess`, and `ModulePathSet`; node allocation/find/insert/rebalance/destruction, Singleton EH clear, and scalar deleting destructor remain compiler-generated and are documented without handwritten source. |
| [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md) | `0x006310e0` | One-slot source-declared/generated-binary vtable containing the compiler scalar deleting destructor; raw table emission is forbidden. |
| [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md) | object offsets `+0x00/+0x04/+0x08`, node offsets through `+0x10` | Exact 12-byte object: vptr, empty Singleton base/path-set-header EBO overlap, count, and red-black-tree node evidence; source-facing field is `ModulePathSet m_modulePaths`. |
| [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) | [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md) | Singleton specialization storage; the by-global page emits `VirusChecker *g_pVirusChecker;`, the class keeps `extern`, and local writes/clears are implicit template/compiler lowering. |

## Evidence Notes

- 2026-06-04 live IDA identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Live IDA confirms a local function island from `0x005c0460` through `0x005c0fe1`: constructor `0x005c0460-0x005c04e0`, destructor `0x005c04e0-0x005c059d`, DLL/export loader `0x005c05a0-0x005c076d`, scanner `0x005c07b0-0x005c0937`, tree/path helpers `0x005c0940-0x005c0ea7`, singleton clear helper `0x005c0eb0-0x005c0ebb`, and scalar deleting destructor `0x005c0ec0-0x005c0f94`.
- `0x005c0fe1-0x005c0ff0` is fifteen `0xcc` bytes, and `0x005c0ff0` begins the next `WaitableTimer` constructor, so the file boundary remains exact.
- Live xrefs still show no direct callers for the constructor `0x005c0460`, destructor `0x005c04e0`, loader `0x005c05a0`, scanner `0x005c07b0`, tree insert `0x005c0940`, process callback `0x005c0aa0`, or scalar deleting destructor `0x005c0ec0`; the only `0x005c0eb0` code xref is a compiler EH cleanup thunk at `0x0060bc76`.
- Internal callback refs remain exact: `0x005c07da` passes `0x005c0aa0` to `V3PCtrl_EnumProcesses`, and `0x005c0aa6` passes `0x005c09f0` to `V3PCtrl_EnumModules`.
- Constructor and teardown evidence is live: `0x005c0460` writes `g_pVirusChecker` at `0x0069bf94`, installs vtable `0x006310e0`, initializes the embedded path tree, and calls `0x005796d0`; `0x005c04e0` and `0x005c0ec0` free V3 modules, clear V3 function pointers, destroy tree nodes, free the sentinel, and clear `g_pVirusChecker`.
- Read-only V3 evidence is exact: `0x006310e4` `V3PRO32E.DLL`, `0x006310f4` `AhnExCheckFile`, `0x00631104` `AhnExGetVirusName`, `0x00631118` `V3PCTRL.DLL`, `0x00631124` `V3PCtrl_EnumProcesses`, and `0x0063113c` `V3PCtrl_EnumModules`.
- Dynamic-library globals at `0x0069bf7c-0x0069bf94` and [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md) are zero-filled in dated MCP session `e63ee655` (`get_bytes 0x0069bf7c size 28`), superseding stale `0xffffffff` initialization wording and historicalizing the older `86fb854e` then-current state snapshot. Source-facing names are `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, `s_pfnAhnExCheckFile`, `s_pfnAhnExGetVirusName`, `s_hV3Pro32`, `s_hV3PCtrl`, and `g_pVirusChecker`.
- IDA decompilation of `0x005c05a0` shows `LoadLibraryA`, `GetProcAddress`, localized error formatting through [UID:0000KK][LanguageMan](by-file/LanguageMan.md), and `MessageBoxW` failure reporting for missing V3 DLLs or exports.
- IDA decompilation of `0x005c07b0` shows process enumeration, module enumeration through callback `0x005c0aa0`, path-tree iteration, `AhnExCheckFile`, `AhnExGetVirusName`, localized detection text key `221`, a fatal/alert call, and a screen/application close path.
- 2026-06-29 B002 accepted implementation used dated MCP session `agent_b009_0002my_20260628` to reconfirm UID0001NV loader size `0x1cd`, scanner size `0x187`, raw reset helper liveness and cleanup semantics, V3 string xrefs, zero-filled dynamic globals, LanguageMan ids `219`/`220`/`221`, `SetApplicationErrorText`, `Application::RequestExit`, and the no-direct-activation caveat. UID0001NV now emits the first-draft method bodies for this file route.
- 2026-06-07 A002 parent-gate follow-up rechecked the Batch 024 vtable/literal evidence: `0x006310dc-0x006310e4` is the exact one-slot `VirusChecker` RTTI/vtable fragment, constructor/destructor/deleting-destructor refs target the table at `0x006310e0`, and adjacent V3 DLL/export strings remain owned by this file. This supports raising confidence to the strict assignment threshold, while unresolved live activation still prevents a higher confidence score.
- 2026-07-23 B005 dated MCP session `7be8cc9f` supersedes earlier sessions for the class-hierarchy/vtable source shape. It proves the two-entry VirusChecker/Singleton hierarchy, base PMD `{4,-1,0}`, visible non-virtual direct inheritance, constructor EBO adjustment, one-slot table, three vptr stores, and 12-byte complete-object deletion size.
- The same pass confirms exact read-only boundaries: VideoPlayerPane's final tertiary slot precedes the VirusChecker COL at `0x006310dc`, and `V3PRO32E.DLL` begins immediately after the sole slot at `0x006310e4`. No raw vtable/RTTI source object or separate vtable source file is justified.

## Migration Notes

- Candidate reconstruction path: `NexusTK/security/VirusChecker.cpp`.
- Keep the constructor, scanner, callback, tree, teardown, vtable, static strings, typed globals, and singleton owned by this file unless later live xrefs prove split ownership.
- Keep the AhnLab module handles and function pointers module-local to this file unless later xrefs prove broader use. Observed destructor/reset paths clear `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, and `s_pfnAhnExCheckFile`; they free the two module handles when present but do not explicitly zero `s_pfnAhnExGetVirusName` or the two `HMODULE` globals.
- Current first-draft C++ readiness is complete across the sibling files. [UID:0000FW][VirusChecker](by-class/VirusChecker.md) emits `VirusChecker.h` and the CPP include/children shell; [UID:0002A5][0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals](by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md) emits typed module statics at position `10`; UID0001NV emits V3 load/reset/scan definitions at position `20`; and UID0001NW emits `InsertModulePath` plus both callbacks at position `30`. Scalar deleting destructor, EH clear, vtable/RTTI, and Dinkumware container lowering remain compiler-generated.
- The class declaration now includes `public Singleton<VirusChecker>`. Preserve human-authored V3/container behavior while allowing MSVC/template code generation to supply publication/clear, EBO adjustment, RTTI/COL, vptr stores, the one-slot table, and the scalar deleting wrapper.
- No `third_party_embeds/` import applies: this is project-owned wrapper code that dynamically loads external AhnLab DLLs.

## 2026-08-02 Final Header/Source And Ordering Model

- Source root is `NexusTK/security/VirusChecker.cpp` with sibling `VirusChecker.h`. The class page owns the complete header declaration; the CPP includes `<windows.h>` and `VirusChecker.h`, then receives only child definitions and module statics.
- Ordered source children are: dynamic-library typedefs/statics [UID:0002A5][0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals](by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md) at position `10`; V3 loader/reset/scanner [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) at `20`; module-path insertion and process/module callbacks [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) at `30`. [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) remains the source definition routed through this file.
- All four dynamically loaded AhnLab/V3 exports are caller-cleaned `__cdecl` pointers. `V3ProcessEnumCallback` and `V3ModuleEnumCallback` are class-private `__stdcall` callbacks with exact 20-byte and 16-byte callee cleanup respectively. Keeping exports and callbacks distinct avoids the former all-stdcall/`void *callback` draft.
- Human-authored source comprises construction/destruction intent, DLL/export load and reset, process/module enumeration, lower-case path insertion, ordered unique storage, file scanning, and detection handling. Lower-case insertion consumes the shared header-visible inline `StringBase<char>::ToLower() const` specialization from `StringBase.h` or an included `.inl`; VirusChecker is an inline consumer and does not own that definition in `VirusChecker.cpp` or `StringBase.cpp`. Singleton publication/clear, EBO adjustment, vptr/RTTI/vtable materialization, scalar deleting destructor, red-black node allocation/search/rebalance/destruction, and EH cleanup are compiler/template consequences and are not written as separate source functions.
- The detection formatter at UID0001NV consumes `g_pLanguageMan->CopyLocalizedString(221)` as a const by-value `mystr::StringBase<wchar_t,...>` result. Its explicit pointer at machine call `0x005c08a2` is hidden-sret lowering, not a source output `SimpleUString`; subsequent `format.c_str()` and destruction preserve the exact lifetime while the surrounding virus-name/module-path/final-message objects remain SimpleUString.
- Historical superseded state: UID0001NW was previously kept blank pending a helper-specific naming pass. The 2026-08 source-quality research resolved the private StringBase alias, lexical comparator, set alias, callback ABI, exact definitions, generated-body partition, and shared header specialization route; that deferral no longer applies.
- No normal activation route was recovered. This remains a runtime-use confidence cap, not a reason to change file ownership, omit source-ready definitions, or classify the retained scanner as third-party code.

All named MCP sessions in this page are dated evidence snapshots, not permanent current authority. Future IDA-dependent decisions require a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback.

## Cross-References

- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md)
- [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md)
- [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- 2026-08-24 B005 UID0000KK support sync: synchronized UID0001NV's corrected by-value LanguageMan/StringBase dependency for localized id `221`, preserving all V3 scanner behavior and unrelated SimpleUString uses while rejecting only the stale explicit output-object call.

- 2026-08-06 B003 UID0001NW placement callback: propagated the shared header-visible StringBase ToLower specialization into the file source model, preserved VirusChecker as an inline consumer, and historicalized named MCP sessions without deleting dated findings.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/76`. Summary/evidence: the page captures the scanner/DLL wrapper role, method contents, IDA evidence, and anticheat refs; live invocation and final runtime path are still uncertain.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `VirusChecker.cpp` under `security`; IDA confirms the AhnLab/V3 scanner wrapper range and singleton lifecycle, while live activation remains open.
- 2026-06-04: Raised file score and replaced stale source-output notes with fresh live IDA evidence.
  - Before: `COMPLETION:84` and `CONFIDENCE:76`.
  - After: `COMPLETION:86` and `CONFIDENCE:84`.
  - Evidence: IDA MCP rechecked the exact function island, no-direct-caller state, EH cleanup thunk, V3 DLL/export strings, dynamic-library globals, constructor/destructor/vtable refs, callback chain, process-tree helpers, and padding boundary before `WaitableTimer`. Confidence remains capped below 90 because normal runtime activation is still not proven.
- 2026-06-07 A002 Batch 024 parent-gate follow-up:
  - Before: `COMPLETION:86` and `CONFIDENCE:84`.
  - After: `COMPLETION:86` and `CONFIDENCE:85`.
  - Evidence: the exact `VirusChecker` vtable child, adjacent V3 literal block, constructor/destructor/deleting-destructor refs, and existing file-island evidence now justify the strict 85-confidence parent gate; confidence remains deliberately capped below 90 because direct runtime activation is still unresolved.
- 2026-06-12 A004 Batch 341 reference cleanup: proposed contents now use exact source-local [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md); the mixed [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) page remains only as a cross-reference index.
- 2026-06-14 A001 Goal 2 global score pass: score remains `86/85`.
  - Summary/evidence: synced current-byte wording for [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md); live IDA now reads the singleton slot as zero-filled, while the local lifecycle refs and no-normal-startup-caller caveat remain unchanged.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: superseded by the 2026-06-29 B004 dated MCP evidence cleanup and the 2026-07-03 UID0001Q3 singleton refresh below. The old local PE/Capstone pass is historical lead material only.
- 2026-06-29 B002 accepted implementation sync:
  - Score unchanged at `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: updated the file route after UID0001NV was raised to `91/91` and populated with formal first-draft C++ for `LoadV3Scanner`, raw `ResetV3ScannerState`, and `ScanLoadedProcessModules`; generated `NexusTK/security/VirusChecker.cpp` should be trusted only after scoped validator refresh confirms current command metadata.
- 2026-06-29 B004 dated MCP evidence source-quality cleanup:
  - Score and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/"` were preserved unchanged.
  - Summary/evidence: then-dated MCP session `86fb854e` reconfirmed the VirusChecker source route, class island boundaries, callback refs, V3 string/global data, zero-filled dynamic globals, one-slot vtable, local singleton lifecycle refs, and no direct constructor/load/scan/direct-insert activation route. The wrapper remains project-owned optional scanner integration that dynamically loads AhnLab DLLs; no `third_party_embeds/` import applies.
- 2026-07-03 B004 UID0001Q3 singleton implementation sync:
  - Score and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/security/"` were preserved unchanged.
  - Summary/evidence: dated MCP session `e63ee655` superseded `86fb854e` as the then-current singleton snapshot, reconfirming zero-filled V3 dynamic globals and `g_pVirusChecker` storage, exact five singleton lifecycle refs, no interior refs, separate successor `0x0069bf98` ref, vtable/scalar-deleting-destructor refs, and no activation xref or pointer-pattern route. [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) now emits the source definition `VirusChecker *g_pVirusChecker;` through this `NexusTK/security/VirusChecker.cpp` file route.
- 2026-07-23 B005 UID0002OT accepted support implementation:
  - Raised completion/confidence from `88/89` to `90/91`; preserved `NexusTK/security/` placement and file ownership.
  - Added direct `Singleton<VirusChecker>` RTTI/PMD/EBO evidence, corrected class/vtable/layout/global source roles, and explicitly separated authored V3/container behavior from compiler/template singleton, RTTI, vtable, vptr, and scalar-destructor lowering.
  - The former missing-normal-activation cap remains documented as a runtime-use uncertainty, not a source-root, inheritance, or static-data confidence blocker.
