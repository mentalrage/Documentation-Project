** TARGET-REPORT-UID:0000FW **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000FW] VirusChecker class source-quality report

Report-only B004 pass for:

- Target: `source-3/project-documentation/by-class/VirusChecker.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0000FW-VirusChecker-class-source-quality.md`
- Status: report created only. No target/support by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

## Current MCP Revision Status

This 2026-06-29 revision replaces the previous offline/local PE/Capstone authority with live IDA MCP evidence from usable session `86fb854e`. The earlier report body is preserved below as historical lead material only. Any active target/support doc text that cites the B004 local PE/Capstone pass as proof should be historicalized or replaced with the current MCP facts in a supervisor-approved implementation callback.

Current MCP session spot-check:

- `server_health` for session `86fb854e`: healthy, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready.
- `idb_list`: session `86fb854e` active for `NexusTK.exe.i64`.
- Supervisor recovery verification also confirmed `lookup_funcs 0x00401000` -> `sub_401000`, size `0x4c`.
- B004 current checks used `lookup_funcs`, `get_bytes`, `xrefs_to`, `xref_query`, `find_bytes`, `entity_query`, `insn_query`, `callees`, `imports_query`, and `analyze_function` against this session.

## Current Final Recommendation

Keep [UID:0000FW] `VirusChecker` reconstructable under file owner/emitter [UID:0000P5] `VirusChecker`, with source route:

```text
NexusTK/security/VirusChecker.cpp
```

Recommended target metadata remains:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000P5
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P5
```

The target page already carries the correct formal class-level C++ shape and should preserve it. The stale "blank C++ because below 95/95" rationale and active local PE/Capstone proof wording should be replaced. Under the current source-quality gate, this class has an emitter route, a reconstructable owner, and sufficient constructor/destructor/vtable/global/container evidence for class/source-shape C++. Confidence should remain below 90 because current MCP evidence still finds no normal static activation route for the constructor, V3 load helper, scanner entry, or direct insert helper.

## Current MCP Evidence Summary

Function boundaries and alignment:

- `lookup_funcs`: `sub_5C0460` size `0x80`, `sub_5C04E0` size `0xbd`, `sub_5C05A0` size `0x1cd`, `0x005c0770` not a function, `sub_5C07B0` size `0x187`, `sub_5C0940` size `0xac`, `sub_5C09F0` size `0xb0`, `sub_5C0AA0` size `0x20`, `sub_5C0AC0` size `0x7a`, `sub_5C0B40` size `0x154`, `sub_5C0CA0` size `0x207`, `sub_5C0EB0` size `0xb`, `sub_5C0EC0` size `0xd4`, `sub_5C0FA0` size `0x41`.
- `get_bytes`: `0x005c045b-0x005c045f`, `0x005c076d-0x005c076f`, `0x005c07af`, and `0x005c0fe1-0x005c0fef` are `int3`/alignment bytes, confirming the local island boundaries and the raw `0x005c0770-0x005c07ae` helper extent.
- `insn_query 0x005c0770-0x005c07ae`: raw reset/free helper frees `0x0069bf8c` and `0x0069bf90` when nonzero, clears `0x0069bf7c`, `0x0069bf80`, and `0x0069bf84`, and returns. It does not clear `0x0069bf88`, `0x0069bf8c`, or `0x0069bf90`.

Constructor, destructor, singleton, and vtable:

- `analyze_function 0x005c0460`: constructor writes `g_pVirusChecker` at `0x0069bf94`, installs vftable `0x006310e0`, initializes the container header/count at `this+0x04/+0x08`, and calls shared tree/string support `sub_5796D0`.
- `analyze_function 0x005c04e0`: destructor reinstalls the vtable, frees V3 module handles, clears the first three V3 function pointers, destroys the module-path tree through `sub_5C0FA0`, resets header/count state, frees the sentinel with `sub_5C7526`, and clears `g_pVirusChecker`.
- `analyze_function 0x005c0ec0`: compiler scalar deleting destructor performs the same cleanup family and conditionally frees `this` when `a2 & 1`.
- `get_bytes 0x006310dc size 8`: `08 3f 65 00 c0 0e 5c 00`, matching the RTTI/COL pointer followed by vtable slot `0x005c0ec0`.
- `entity_query`: `??_7VirusChecker@@6B@` at `0x006310e0`.
- `xrefs_to 0x006310e0`: constructor `0x005c04a7`, destructor `0x005c050c`, scalar deleting destructor `0x005c0eed`.
- `xrefs_to 0x0069bf94`: constructor set/clear sites `0x005c0496`/`0x005c049d`, destructor `0x005c0582`, clear helper `0x005c0eb0`, scalar deleting destructor `0x005c0f63`. No external singleton consumer was found.

V3 loader/scanner family:

- `analyze_function 0x005c05a0`: `VirusChecker::LoadV3Scanner` loads `V3PRO32E.DLL`, resolves `AhnExCheckFile` and `AhnExGetVirusName`, loads `V3PCTRL.DLL`, resolves `V3PCtrl_EnumProcesses` and `V3PCtrl_EnumModules`, returns true only if all required handles/functions are present, and uses localized error ids 219/220 with `MessageBoxW(..., L"Error", ...)` for missing DLL/export cases.
- `analyze_function 0x005c07b0`: `VirusChecker::ScanLoadedProcessModules` invokes the process enumeration pointer at `0x0069bf7c` with callback `sub_5C0AA0`, iterates the collected path set, calls `AhnExCheckFile`, fetches `AhnExGetVirusName(1)` on detection, formats localized id 221 text, reports the detection path/name, and requests application exit through the Application path.
- Executed B002 report `0001NV-VirusCheckerV3LoadAndScan-empty-emitter-source-quality.md` is an accepted current-MCP support report for the method-body child; this class report should not duplicate or undo that callback.

Process-tree helpers and container:

- `analyze_function 0x005c0940`: no-xref direct `InsertModulePath`-style helper normalizes/copies a path string and inserts through `sub_5C0CA0`.
- `analyze_function 0x005c09f0`: module enumeration callback normalizes/copies `char *String` and inserts it into `(context+4)`.
- `analyze_function 0x005c0aa0`: process enumeration callback calls `V3PCtrl_EnumModules(process, sub_5C09F0, context)`.
- `analyze_function 0x005c0ac0`, `0x005c0b40`, `0x005c0ca0`, and `0x005c0fa0`: allocator, insert/rebalance, lookup-or-insert, and recursive cleanup helpers form a Dinkumware-like tree/set container. Source should express this as `std::set<String>` or the project string-wrapper equivalent on the class page, not as raw generated helper names.
- Executed B012 STL support evidence is only a support lead: shared tree helper internals may support multiple owners, while the VirusChecker-specific callbacks and container ownership remain with UID0000FW/UID0000P5.

Dynamic globals and strings:

- `get_bytes 0x0069bf7c size 28`: all zero bytes. This supersedes old active `0xffffffff` initializer wording; any such wording should be historicalized.
- `entity_query`: names at `0x0069bf7c` (`V3PCtrl_EnumProcesses`), `0x0069bf84` (`AhnExCheckFile`), and `0x0069bf8c` (`hLibModule`) are IDB/generated names only. Source-facing names should remain typed static globals in `NexusTK/security/VirusChecker.cpp`.
- Proposed source-facing global names remain `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, `s_pfnAhnExCheckFile`, `s_pfnAhnExGetVirusName`, `s_hV3Pro32`, and `s_hV3PCtrl`, plus `extern VirusChecker *g_pVirusChecker` on the class page.
- `entity_query`/string cache and `get_bytes 0x006310e4 size 160`: exact V3 strings are `V3PRO32E.DLL`, `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCTRL.DLL`, `V3PCtrl_EnumProcesses`, and `V3PCtrl_EnumModules`, with wide DLL-name forms also present at the same read-only-data cluster.

Activation-route negative evidence:

- `xrefs_to` finds no refs to `0x005c0460`, `0x005c04e0`, `0x005c05a0`, `0x005c0770`, `0x005c07b0`, or `0x005c0940`; expected local refs exist for `0x005c09f0`, `0x005c0aa0`, `0x005c0eb0`, `0x005c0ec0`, the vtable, globals, and callbacks.
- `find_bytes` finds no little-endian pointer pattern for constructor `60 04 5c 00`, destructor `e0 04 5c 00`, loader `a0 05 5c 00`, raw reset `70 07 5c 00`, scanner `b0 07 5c 00`, direct insert `40 09 5c 00`, or singleton clear `b0 0e 5c 00`.
- `find_bytes` does find expected local patterns for callback `0x005c09f0`, process callback `0x005c0aa0`, vtable slot `0x005c0ec0`, vtable pointer `0x006310e0`, and `g_pVirusChecker` pointer `0x0069bf94`. This supports a confidence cap, not a no-code result.

## Current Source Route And Score Audit

Source route remains `NexusTK/security/VirusChecker.cpp` through [UID:0000P5] because all class-specific behavior is the V3/AhnLab wrapper, process/module scanning, singleton, vtable, and module-path container. Do not move this class under generic STL support, Application, LanguageMan, Resource/string, Windows import wrappers, or third-party source. No static third-party import directive is needed; the binary dynamically loads external AhnLab DLLs by name.

Score audit under the current standard:

- No owner/emitter blocker: [UID:0000FW] is owned/emitted by [UID:0000P5].
- No reconstructable blocker: the class has stable constructor/destructor, vtable, globals, class layout, and behavior.
- No source-placement blocker: `NexusTK/security/VirusChecker.cpp` is already the correct route.
- No first-draft C++ blocker: the class page already has the correct formal C++ block.
- Remaining confidence blocker: current MCP evidence still does not reveal the static activation route, so confidence should remain `89` rather than `90+`.
- Recommendation: keep `88/89`; replace stale local/offline proof wording and obsolete 95/95 no-code wording rather than changing the score.

## Current Formal C++ Recommendation

Preserve the class page's existing formal block. If an implementation callback must reinsert it, use this exact target-level shape:

```cpp
class String;

class VirusChecker
{
public:
    VirusChecker();
    virtual ~VirusChecker();

    bool LoadV3Scanner();
    void ScanLoadedProcessModules();

private:
    typedef std::set<String> ModulePathSet;

    void InsertModulePath(const char *path);

    ModulePathSet m_modulePaths;
};

extern VirusChecker *g_pVirusChecker;

[[CHILDREN]]
```

Method-body C++ for `LoadV3Scanner`, scanner, raw reset helper, and callbacks belongs to the exact by-memory children, especially executed B002 UID0001NV. This class report does not require a generated C++ file edit during report-only revision.

## Historical Offline/Capstone Final Recommendation (Preserved Lead Material; Superseded By Current MCP Revision)

Keep [UID:0000FW] `VirusChecker` reconstructable under file owner/emitter [UID:0000P5] `VirusChecker`, with source route:

```text
NexusTK/security/VirusChecker.cpp
```

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000P5
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P5
```

The stale "blank C++ because below 95/95" rationale should be replaced. The current assignment gate is the combined 85/85+ source-readiness gate: the class is reconstructable, has an emitter route through [UID:0000P5], and has enough current constructor/destructor/vtable/global/container evidence for first-draft C++. Confidence should still stay below 90 because no static runtime activation route was found for the constructor, V3 load helper, or scanner entry.

The class page should get first-draft class/source-shape C++. Method-body details can be placed on the exact by-memory children during implementation if the supervisor chooses a deeper callback, but the class page should no longer be an empty emitter marker.

## Historical Offline Evidence Checked (Preserved Lead Material)

Instruction/contract files:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/goal.md`
- `.codex/AGENTS.md`

Target and direct support docs:

- `by-class/VirusChecker.md`
- `by-file/VirusChecker.md`
- `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`
- `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`
- `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
- `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`
- `by-global/g_pVirusChecker.md`
- `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`
- `by-type/by-struct/VirusCheckerProcessTreeLayout.md`
- `by-type/by-vtable/VirusCheckerVtable.md`
- `by-type/by-vtable/SecuritySingletonVtables.md`
- `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`
- `by-memory/0x006310e4-0x00631184.VirusCheckerV3StringData.md`
- `by-meta/client_anticheat.md`
- `by-meta/client_libraries.md`
- `by-resource/str-res-localized-strings.md`
- `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md`
- `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
- `by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/NexusTK/security/VirusChecker.cpp`
- `source-3/simroot_v2/class_VirusChecker.cpp`
- `by-class/-coverage-report.md`
- scoped `by-memory/-coverage-report.md` rows for VirusChecker children

Prior related report evidence checked:

- `tools/leaser/Agents/Agent-B001/research/executed/older/00026Z-VideoVirusReadOnlyData.md` via current doc references and rg excerpts.

Binary evidence checked:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Relevant sections from local PE parse:
  - `.text 0x00401000`, virtual size `0x20b4ac`
  - `.rdata 0x0060d000`, virtual size `0x5f0be`
  - `.data 0x0066d000`, virtual size `0x2fe24`, raw size `0xd800`
  - `.rsrc 0x0069d000`, virtual size `0x15c38`
- Manual PE mapping plus Capstone disassembly and direct absolute/rel32 reference scans.

IDA MCP status:

- Attempted MCP HTTP connection to `127.0.0.1:13337/mcp`.
- Result: `IDA_MCP_UNAVAILABLE: The operation has timed out`.
- Local PE disassembly and current project docs were used for this report.

## Historical Offline Source Ownership And Placement (Preserved Lead Material)

Keep the class owned by [UID:0000P5] `VirusChecker`, proposed file `NexusTK/security/VirusChecker.cpp`.

Rejected alternatives:

- Not AhnLab/V3 source ownership. The binary dynamically loads `V3PRO32E.DLL` and `V3PCTRL.DLL` with `LoadLibraryA` and calls exported functions through pointers. The project source is a wrapper/integration, not vendor scanner internals.
- Not [UID:0001QE] `client_libraries` as direct owner. That page should continue to document procurement/runtime dependency rules for AhnLab V3 DLLs.
- Not [UID:0000I6] `CheatDetector`. The security pages show `CheatDetector` and `VirusChecker` as separate compact singleton classes with different vtables and source files.
- Not [UID:0000HG] `Application`, [UID:0000KK] `LanguageMan`, or string-resource ownership. `VirusChecker` consumes the error-text setter, `Application::RequestExit`, and localized string lookup, but those are dependencies.
- Not no-owner/dead-source classification. The constructor, destructor, vtable, DLL/export strings, module-static globals, and local process-tree helper family are cohesive project code. The missing activation route caps confidence but does not make the class non-reconstructable.

## Historical Offline Runtime Activation Route (Preserved Lead Material)

The normal activation route remains unproven after a fresh local reference scan.

Evidence checked:

- No absolute or rel32 references to:
  - constructor `0x005c0460`
  - ordinary destructor `0x005c04e0`
  - V3 load helper `0x005c05a0`
  - raw reset helper `0x005c0770`
  - scanner entry `0x005c07b0`
  - direct insert helper `0x005c0940`
- `0x005c0eb0` has one rel32 jump reference from `0x0060bc76`, which is compiler EH cleanup/functor area, not a normal source call path.
- `0x005c0ec0` is referenced only from the one-slot vtable at `0x006310e0`.
- `0x0069bf94` / `g_pVirusChecker` has exactly the expected lifecycle writes/clears in the constructor/destructor/clear/scalar-destructor paths; no external read/consumer route was found.
- `0x005c09f0` and `0x005c0aa0` are referenced as callback immediates from the scanner path and process callback, so their reachability depends on `0x005c07b0`.

Best-supported conclusion:

`VirusChecker` is retained optional security/scanner code compiled into the client but not statically wired into the currently documented normal startup path. The most likely explanations are a disabled/unused optional AhnLab integration, distribution-specific activation removed from this build, or a static-analysis metadata gap. A hidden computed call is possible but not supported by the current evidence because no function pointer data or singleton consumer was found.

## Historical Offline Function And Helper Findings (Preserved Lead Material)

| Range | Recommended source-facing role | Finding |
| --- | --- | --- |
| `0x005c0460-0x005c04e0` | `VirusChecker::VirusChecker()` | Publishes `g_pVirusChecker = this`, installs vtable `0x006310e0`, initializes the embedded path-set wrapper at `this+0x04/+0x08`, and allocates the sentinel through `0x005796d0`. |
| `0x005c04e0-0x005c059d` | `VirusChecker::~VirusChecker()` | Restores vtable, frees both V3 module handles if nonzero, clears `EnumProcesses`, `EnumModules`, and `AhnExCheckFile`, destroys the path tree, frees the sentinel, clears `g_pVirusChecker`. |
| `0x005c05a0-0x005c076d` | `bool VirusChecker::LoadV3Scanner()` / `LoadV3ScannerDlls()` | Calls `LoadLibraryA`, resolves four exports via `GetProcAddress`, reports localized MessageBoxW errors for missing DLL/export. |
| `0x005c0770-0x005c07af` | source-local `ResetV3ScannerState()` / `FreeV3ScannerLibraries()` helper | Raw non-IDA-modeled helper. Frees `s_hV3Pro32` and `s_hV3PCtrl` if nonzero, then clears `EnumProcesses`, `EnumModules`, and `AhnExCheckFile`. No static caller found. |
| `0x005c07b0-0x005c0937` | `void VirusChecker::ScanLoadedProcessModules()` | Calls process enumeration, iterates the path set, checks each path with `AhnExCheckFile`, formats localized detection text id `221`, calls Application error-text setter `0x00465af0`, then `Application::RequestExit` at `0x00464e40`. |
| `0x005c0940-0x005c09ec` | `VirusChecker::InsertModulePath(const char *path)` | Direct source-style insertion helper, no static caller found. Copies/normalizes an ANSI/module path string, inserts into set. |
| `0x005c09f0-0x005c0aa0` | `V3ModuleEnumCallback` | Four-argument stdcall callback. Uses arg at `[ebp+0x10]` as module path and `[ebp+0x14]` as `VirusChecker *` context; inserts path and returns `1`. |
| `0x005c0aa0-0x005c0ac0` | `V3ProcessEnumCallback` | Five-argument stdcall callback. Passes process arg `[ebp+8]`, module callback `0x005c09f0`, and context `[ebp+0x18]` to `s_pfnV3PCtrlEnumModules`; returns `1`. |
| `0x005c0ac0-0x005c0b3a` | path-set node allocation | Allocates 0x14-byte node and constructs path string payload at node `+0x10`. Compiler/container helper shape, not a public source method. |
| `0x005c0b40-0x005c0c94` | path-set insert/rebalance | Red-black-tree insert/rebalance, throws `"map/set<T> too long"` on overflow. Express as source container behavior, not hand-port as public API. |
| `0x005c0ca0-0x005c0ea7` | path-set lookup-or-insert | Compares path strings and calls insert/rebalance only when missing. Internal container helper. |
| `0x005c0eb0-0x005c0ebb` | singleton clear EH helper | Writes zero to `g_pVirusChecker`; only external edge is EH cleanup at `0x0060bc76`. |
| `0x005c0ec0-0x005c0f94` | scalar deleting destructor | Compiler artifact. Duplicates destructor side effects and conditionally frees `this` when deletion flag bit 0 is set. Source should be virtual destructor, not a named source method. |
| `0x005c0fa0-0x005c0fe1` | path-set recursive node cleanup | Destroys right branch recursively, advances left, destroys string payload at `node+0x10`, frees 0x14-byte node. Express through container destructor/clear. |

Boundary notes remain correct:

- `0x005c045b-0x005c0460` is padding before the constructor.
- `0x005c076d-0x005c0770` and `0x005c07af-0x005c07b0` bracket the raw reset helper.
- `0x005c0fe1-0x005c0ff0` is fifteen `0xcc` bytes before `WaitableTimer`.

## Historical Offline V3 DLL Globals And Function Pointer Names (Preserved Lead Material)

Recommended source-facing module-static names:

| Address | Current/common name | Recommended name | Type/role |
| --- | --- | --- | --- |
| `0x0069bf7c` | `V3PCtrl_EnumProcesses` | `s_pfnV3PCtrlEnumProcesses` | function pointer from `V3PCTRL.DLL`; called by scanner with process callback and `this`. |
| `0x0069bf80` | `dword_69BF80` | `s_pfnV3PCtrlEnumModules` | function pointer from `V3PCTRL.DLL`; called by process callback with process id/handle, module callback, context. |
| `0x0069bf84` | `AhnExCheckFile` | `s_pfnAhnExCheckFile` | function pointer from `V3PRO32E.DLL`; called once per collected module path. |
| `0x0069bf88` | `dword_69BF88` | `s_pfnAhnExGetVirusName` | function pointer from `V3PRO32E.DLL`; called with argument `1` on detection. |
| `0x0069bf8c` | `hLibModule` | `s_hV3Pro32` / `s_hV3ProModule` | `HMODULE` for `V3PRO32E.DLL`. |
| `0x0069bf90` | `dword_69BF90` | `s_hV3PCtrl` | `HMODULE` for `V3PCTRL.DLL`. |

Important correction: the current raw PE places these globals in the virtual zero-filled tail of `.data`. The local section map has `.data` raw bytes only through VA `0x0067a800`, while these slots are at `0x0069bf7c-0x0069bf94`. Treat any `0xffffffff` initial-value wording as stale unless a future live IDB/runtime-state pass proves a separate initializer. The source declaration should be ordinary zero-initialized module-static pointers/handles.

Also correct overbroad cleanup wording: observed destructor/reset paths clear `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, and `s_pfnAhnExCheckFile`; they do not explicitly zero `s_pfnAhnExGetVirusName` or the two `HMODULE` globals after `FreeLibrary`.

## Historical Offline DLL/String/Localized Behavior (Preserved Lead Material)

V3 static string data is exact and should stay with [UID:0000P5]:

- `0x006310e4`: `"V3PRO32E.DLL"`
- `0x006310f4`: `"AhnExCheckFile"`
- `0x00631104`: `"AhnExGetVirusName"`
- `0x00631118`: `"V3PCTRL.DLL"`
- `0x00631124`: `"V3PCtrl_EnumProcesses"`
- `0x0063113c`: `"V3PCtrl_EnumModules"`

Import table roles confirmed by local PE import parse:

- `0x0060d1b4`: `KERNEL32.dll!FreeLibrary`
- `0x0060d1b8`: `KERNEL32.dll!LoadLibraryA`
- `0x0060d128`: `KERNEL32.dll!GetProcAddress`
- `0x0060d44c`: `USER32.dll!MessageBoxW`

Localized error behavior:

- Failure to load either V3 DLL uses LanguageMan id `219` (`0xdb`) and formats the missing DLL name (`V3PRO32E.DLL` or `V3PCTRL.DLL`) before `MessageBoxW(..., L"Error", 0)`.
- Failure to resolve expected exports uses LanguageMan id `220` (`0xdc`) and formats the relevant DLL name.
- Virus detection uses LanguageMan copy helper `0x004f0380` with id `221` (`0xdd`), formats it with the detected path and virus name, stores it through Application error-text setter `0x00465af0`, then calls `Application::RequestExit` at `0x00464e40`.

## Historical Offline Class Layout And Container Shape (Preserved Lead Material)

Recommended high-probability class layout:

| Offset | Best source role | Evidence |
| --- | --- | --- |
| `+0x00` | vptr | Constructor/destructor/scalar destructor write `0x006310e0`; exact vtable has one scalar deleting destructor slot. |
| `+0x04` | `m_modulePaths` header/sentinel pointer | Constructor calls `0x005796d0` and stores sentinel; callbacks pass `this+0x04` into path-set helpers. |
| `+0x08` | `m_modulePaths` node count | Constructor clears; insert helper increments container count; destructor clears after reset. |

Best source-level type:

```cpp
std::set<String> m_modulePaths;
```

where `String` means the project ANSI string wrapper used by the `0x00582xxx/0x00584xxx` string helpers. Exact original string typedef spelling is not proven. Avoid final names like `m_state`; offset `+0x08` is a path-set size/count, not generic state.

Node layout remains an implementation detail of the compiler/container:

- `+0x00/+0x04/+0x08`: left/parent/right links
- `+0x0c`: red/black color byte
- `+0x0d`: nil/header flag byte
- `+0x10`: 4-byte project string payload

## Historical Offline Vtable And Compiler-Generated Names (Preserved Lead Material)

The source class has a virtual destructor. The backing vtable is compiler-emitted:

- `0x006310dc`: RTTI/COL pointer for `VirusChecker`
- `0x006310e0`: one-slot object vtable, slot target `0x005c0ec0`
- `0x006310e4`: V3 string data begins, not another virtual slot

Do not use generated names as source:

- Replace `ScalarDeletingDestructor` with "compiler scalar deleting destructor for `VirusChecker::~VirusChecker`".
- Treat `~VirusChecker\r` and other control-character historical metadata as stale export/name pollution.
- Do not hand-emit vtable bytes or scalar deleting destructor source bodies.

## Historical Offline First-Draft C++ Readiness (Preserved Lead Material)

First-draft C++ is justified for the class/source shape under the current 85/85 gate. It should remain below final-source score because runtime activation, exact project string typedef spelling, and exact original helper names are still unresolved.

Recommended class-page first-draft C++ shape, adapting `String` to the repository's current canonical project ANSI string type if one is chosen during implementation:

```cpp
class VirusChecker
{
public:
    VirusChecker();
    virtual ~VirusChecker();

    bool LoadV3Scanner();
    void ScanLoadedProcessModules();

private:
    typedef std::set<String> ModulePathSet;

    void InsertModulePath(const char *path);

    ModulePathSet m_modulePaths;
};

extern VirusChecker *g_pVirusChecker;
```

Recommended file-scope support declarations for `VirusChecker.cpp`:

```cpp
typedef int (__stdcall *V3PCtrlEnumProcessesProc)(void *callback, void *context);
typedef int (__stdcall *V3PCtrlEnumModulesProc)(unsigned long processId, void *callback, void *context);
typedef int (__stdcall *AhnExCheckFileProc)(const char *path);
typedef const char *(__stdcall *AhnExGetVirusNameProc)(int index);

static V3PCtrlEnumProcessesProc s_pfnV3PCtrlEnumProcesses;
static V3PCtrlEnumModulesProc s_pfnV3PCtrlEnumModules;
static AhnExCheckFileProc s_pfnAhnExCheckFile;
static AhnExGetVirusNameProc s_pfnAhnExGetVirusName;
static HMODULE s_hV3Pro32;
static HMODULE s_hV3PCtrl;
```

Recommended behavior-faithful method-body drafts for child by-memory pages, if the implementation callback includes them:

```cpp
VirusChecker::VirusChecker()
{
    g_pVirusChecker = this;
}

VirusChecker::~VirusChecker()
{
    if (s_hV3Pro32 != 0) {
        FreeLibrary(s_hV3Pro32);
    }
    if (s_hV3PCtrl != 0) {
        FreeLibrary(s_hV3PCtrl);
    }

    s_pfnV3PCtrlEnumProcesses = 0;
    s_pfnV3PCtrlEnumModules = 0;
    s_pfnAhnExCheckFile = 0;

    m_modulePaths.clear();
    g_pVirusChecker = 0;
}

bool VirusChecker::LoadV3Scanner()
{
    s_hV3Pro32 = LoadLibraryA("V3PRO32E.DLL");
    if (s_hV3Pro32 == 0) {
        ShowV3LoadError(219, L"V3PRO32E.DLL");
        return false;
    }

    s_pfnAhnExCheckFile =
        (AhnExCheckFileProc)GetProcAddress(s_hV3Pro32, "AhnExCheckFile");
    s_pfnAhnExGetVirusName =
        (AhnExGetVirusNameProc)GetProcAddress(s_hV3Pro32, "AhnExGetVirusName");
    if (s_pfnAhnExCheckFile == 0 || s_pfnAhnExGetVirusName == 0) {
        ShowV3LoadError(220, L"V3PRO32E.DLL");
        return false;
    }

    s_hV3PCtrl = LoadLibraryA("V3PCTRL.DLL");
    if (s_hV3PCtrl == 0) {
        ShowV3LoadError(219, L"V3PCTRL.DLL");
        return false;
    }

    s_pfnV3PCtrlEnumProcesses =
        (V3PCtrlEnumProcessesProc)GetProcAddress(s_hV3PCtrl, "V3PCtrl_EnumProcesses");
    s_pfnV3PCtrlEnumModules =
        (V3PCtrlEnumModulesProc)GetProcAddress(s_hV3PCtrl, "V3PCtrl_EnumModules");
    if (s_pfnV3PCtrlEnumProcesses == 0 || s_pfnV3PCtrlEnumModules == 0) {
        ShowV3LoadError(220, L"V3PCTRL.DLL");
        return false;
    }

    return true;
}
```

The code above is intentionally first-draft. It should be adjusted to the project's actual `String`, formatter, `LanguageMan`, and `Application` helper names during implementation. It should not include the scalar deleting destructor as handwritten source.

## Historical Offline Recommended Target/Support Doc Changes (Preserved Lead Material)

Target `by-class/VirusChecker.md`:

- Set `COMPLETION:88`, `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000P5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P5`.
- Replace the below-95 no-code blocker with current 85/85 gate analysis and first-draft C++ readiness.
- Add the runtime activation conclusion: no static constructor/load/scan route found; retained optional/disabled scanner is the best inference.
- Replace `m_state` wording for object offset `+0x08` with path-set node count / `m_modulePaths` count.
- Correct V3 global names and cleanup details as above.
- Mark historical control-character method metadata (`~VirusChecker\r`) as stale.
- Add first-draft class declaration/source-shape C++.

Support docs:

- `by-file/VirusChecker.md`: update status to first-draft ready, not waiting for 95/95; add no-activation conclusion, V3 global cleanup correction, raw reset helper role, and zero-filled `.data` evidence for the six V3 slots.
- `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`: add source-facing method names, first-draft eligibility, zero-filled globals correction, and scalar deleting destructor compiler policy. If C++ is added here, keep it as a compact class-island overview and put full method bodies in exact child pages.
- `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`: rename roles to `LoadV3Scanner`, `ResetV3ScannerState`, `ScanLoadedProcessModules`; add function pointer typedef recommendations, id 219/220/221 behavior, and first-draft method code or implementation notes.
- `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`: resolve source names for `InsertModulePath`, `V3ModuleEnumCallback`, `V3ProcessEnumCallback`, path-set internal helpers, and compiler-generated scalar deleting destructor policy.
- `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`: replace `0xffffffff` initialization with raw PE zero-filled virtual `.data` evidence unless a new live IDB proves otherwise; add exact source-facing names and cleanup caveat.
- `by-global/g_pVirusChecker.md` and `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`: keep zero-filled singleton evidence, add that no external consumer/read route was found.
- `by-type/by-struct/VirusCheckerProcessTreeLayout.md`: replace `m_state` caveat with `m_modulePaths` count; document `std::set<String>` / project string wrapper as best source type.
- `by-type/by-vtable/VirusCheckerVtable.md` and `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`: keep one-slot vtable, but update text to say class declaration/virtual destructor first-draft is ready and vtable bytes remain compiler-emitted.
- `by-meta/client_anticheat.md` and `by-meta/client_libraries.md`: preserve optional AhnLab integration wording; update activation conclusion if desired.
- `by-project-structure/proposed-source-tree.md`: no structural change needed; optionally update the VirusChecker bullet to mention first-draft readiness and no-activation cap.
- `auto-generated/NexusTK/security/VirusChecker.cpp`: do not hand-edit. Let validator/autogen update it if accepted C++ is implemented.

## Historical Offline Score Rationale (Preserved Lead Material)

Recommended `88/89`:

- Completion increases because the class can now carry first-draft C++, current source-shape names, corrected V3 globals, compiler-artifact policy, and resolved owner/source placement.
- Confidence increases from the old parent-gate minimum because local PE evidence independently reconfirms exact ranges, vtable data, function/global refs, import names, string literals, and no-caller state.
- Confidence remains below 90 because no normal activation route was found and exact original project string/helper typedef names are still inferred.
- Do not raise to final-source territory. Runtime activation, source helper names, and exact vendor callback typedefs remain below final audit.

## Historical Offline IDA Rename/Type/Comment Recommendations (Preserved Lead Material)

High confidence:

- `dword_69BF94` -> `g_pVirusChecker`
- `dword_69BF7C` / current `V3PCtrl_EnumProcesses` -> `s_pfnV3PCtrlEnumProcesses`
- `dword_69BF80` -> `s_pfnV3PCtrlEnumModules`
- `dword_69BF84` / current `AhnExCheckFile` -> `s_pfnAhnExCheckFile`
- `dword_69BF88` -> `s_pfnAhnExGetVirusName`
- `dword_69BF8C` / `hLibModule` -> `s_hV3Pro32`
- `dword_69BF90` -> `s_hV3PCtrl`
- `0x005c0460` -> `VirusChecker::VirusChecker`
- `0x005c04e0` -> `VirusChecker::~VirusChecker`
- `0x005c05a0` -> `VirusChecker::LoadV3Scanner`
- `0x005c07b0` -> `VirusChecker::ScanLoadedProcessModules`
- `0x005c0aa0` -> `V3ProcessEnumCallback`
- `0x005c09f0` -> `V3ModuleEnumCallback`
- `0x005c0ec0` -> compiler scalar deleting destructor for `VirusChecker`
- `0x005c0fa0` -> `DestroyModulePathSetNodes`

Medium/high confidence:

- `0x005c0770` -> `ResetV3ScannerState` or `FreeV3ScannerLibraries`; no static caller found.
- `0x005c0940` -> `VirusChecker::InsertModulePath`; no static caller found.
- `0x005c0ca0` -> `ModulePathSetFindOrInsert`
- `0x005c0b40` -> `ModulePathSetInsertRebalance`
- `0x005c0ac0` -> `ModulePathSetAllocateNode`

Comments to add:

- At `0x005c05a0`: "Load optional AhnLab V3 scanner/control DLLs; ids 219/220 report missing DLL/export."
- At `0x005c07b0`: "Enumerate process modules, scan each path, set Application error text with localized id 221 on detection, request exit."
- At `0x005c0770`: "Raw no-xref V3 reset helper; frees module handles and clears three call pointers only."
- At `0x0069bf7c-0x0069bf94`: "Module-static zero-initialized V3 handles/function pointers; current source should not preserve generated dword names or stale 0xffffffff wording."

## Historical Offline Coverage Text (Preserved Lead Material; Supervisor-Owned)

Supervisor-owned replacement row for `by-class/-coverage-report.md`:

```text
- [UID:0000FW][VirusChecker](by-class/VirusChecker.md) : reconstructable : 88% : strong : B004 2026-06-19 source-quality pass raises the class to `88/89` and removes the stale 95/95 no-code blocker. Local PE/Capstone verification of `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms the exact constructor/destructor/load/scan/tree/scalar-destructor island, one-slot vtable at `0x006310e0`, V3 LoadLibraryA/GetProcAddress string/export globals, localized error/detection path, `std::set`-like module-path container at `this+0x04/+0x08`, zero-filled singleton/global storage, and source route through [UID:0000P5][VirusChecker](by-file/VirusChecker.md) to `NexusTK/security/VirusChecker.cpp`; no direct constructor/load/scan activation route was found, so confidence remains capped below 90 while first-draft class/source-shape C++ is ready.
```

Supervisor-owned replacement row for `by-file/-coverage-report.md` if the file page is updated:

```text
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md) : reconstructable : 88% : strong : B004 2026-06-19 source-quality pass keeps `NexusTK/security/VirusChecker.cpp` as the source owner and records first-draft readiness for the retained AhnLab/V3 scanner wrapper. Evidence covers constructor/destructor/source-local scalar-destructor generation, V3 DLL/export load helper, raw no-xref reset helper, scan/detection exit path, process/module callbacks, module-path tree helpers, one-slot vtable and V3 string children, typed module-static V3 globals, `g_pVirusChecker`, and the no-normal-activation caveat.
```

Supervisor-owned `by-memory/-coverage-report.md` rows if implementation touches these memory docs:

```text
    - [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md) 0x005c0460-0x005c0fe1 | class/helper island | VirusChecker : reconstructable : 88% : strong : B004 2026-06-19 source-quality pass replaces stale below-95 no-code reasoning with current 85/85 gate analysis; local PE/Capstone checks confirm constructor/destructor/load/scan/tree/helper/scalar-destructor boundaries, raw reset helper `0x005c0770-0x005c07af`, callback refs, one-slot vtable refs, V3 globals/strings, zero-filled singleton/global storage, compiler-generated scalar destructor policy, source route through [UID:0000FW][VirusChecker](by-class/VirusChecker.md), and the unresolved no-direct-activation cap.
    - [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) 0x005c05a0-0x005c0937 | scanner load/scan helpers | VirusCheckerV3LoadAndScan : reconstructable : 88% : strong : B004 2026-06-19 source-quality pass resolves `0x005c05a0` as `VirusChecker::LoadV3Scanner`, raw no-xref `0x005c0770` as a V3 reset/free helper, and `0x005c07b0` as `VirusChecker::ScanLoadedProcessModules`; evidence includes LoadLibraryA/GetProcAddress imports, exact V3 DLL/export strings, localized ids 219/220/221, typed module-static function pointers/handles, detection error-text/RequestExit path, callback refs, first-draft code readiness, and no static caller for load/scan.
    - [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) 0x005c0940-0x005c0fe1 | process/module path-set helpers | VirusCheckerProcessTreeHelpers : reconstructable : 87% : very-strong : B004 2026-06-19 source-quality pass resolves source-facing callback/helper roles: `InsertModulePath`, `V3ModuleEnumCallback`, `V3ProcessEnumCallback`, internal path-set allocation/lookup/insert/rebalance/cleanup helpers, EH singleton clear helper, and compiler scalar deleting destructor; source should express the container as `std::set<String>` or the project string-wrapper equivalent, not hand-port raw STL helper names.
    - [UID:0002A5][0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals](by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md) 0x0069bf7c-0x0069bf94 | global-data cluster | VirusCheckerDynamicLibraryGlobals : reconstructable : 88% : very-strong : B004 2026-06-19 source-quality pass assigns source-facing names `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, `s_pfnAhnExCheckFile`, `s_pfnAhnExGetVirusName`, `s_hV3Pro32`, and `s_hV3PCtrl`; local PE section mapping shows this range is zero-filled virtual `.data`, superseding stale `0xffffffff` initial-value wording, and observed cleanup clears only the first three function pointers while module handles and `AhnExGetVirusName` are not explicitly zeroed.
```

## Historical Offline Validation Commands For Implementation Callback (Preserved Lead Material)

Run from `source-3/project-documentation` for every touched doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000FW-VirusChecker-class-source-quality-removed.md](0000FW-VirusChecker-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `RECONSTRUCTION_CPP CODE` is added or changed, inspect `auto-generated/NexusTK/security/VirusChecker.cpp` and report any generated/stat file changes. Do not hand-edit generated files unless the repository workflow explicitly requires it.

## Historical Offline Implementation Readiness (Preserved Lead Material)

Ready for supervisor implementation callback.

Implementation should:

- update target metadata and source-quality notes;
- add first-draft class/source-shape C++;
- correct V3 global names and stale initialization/cleanup wording;
- preserve the no-direct-activation caveat;
- preserve compiler-generated scalar destructor/vtable policy;
- validate every touched doc with `--apply --queue-timeout 240`;
- leave `by-memory/-coverage-report.md` to supervisor-owned coverage application.

## Current Related Report And Stale-Source Audit

Executed and archived reports were searched for `0000FW`, `VirusChecker`, V3 loader/scanner terms, `0x005c0460`, `0x005c05a0`, `0x006310dc`, `g_pVirusChecker`, and source-family terms. These reports are leads unless they were accepted/executed with current evidence:

- `executed-b-agent-research/B002/0001NV-VirusCheckerV3LoadAndScan-empty-emitter-source-quality.md`: accepted support report for UID0001NV. It upgrades the V3 load/scan child to `91/91` and supplies method-body-level C++ support. Treat as already-present support evidence; do not duplicate or revert it.
- `executed-b-agent-research/B001/00026Z-VideoVirusReadOnlyData.md`: support lead for the exact vtable data child `0x006310dc-0x006310e4` and V3 string data child `0x006310e4-0x00631184`. Current MCP rechecked the vtable/string bytes for this class report.
- `executed-b-agent-research/B012/000245-StlTreeStringMapSupport-source-routing.md`: support lead for shared Dinkumware tree helper behavior. Use it only to justify not hand-porting raw STL internals; VirusChecker-specific callbacks/container ownership still route through UID0000FW/UID0000P5.
- B002/B012 CheatDetector reports were adjacent security-source context only and do not change this target's owner/emitter/source route.

Target/support stale-source check:

- `by-class/VirusChecker.md`, `by-file/VirusChecker.md`, `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`, `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`, `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`, `by-global/g_pVirusChecker.md`, `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`, and VirusChecker-specific meta support text contain active B004 local PE/Capstone wording. Implementation should replace those active proof statements with current MCP session `86fb854e` facts and keep the old pass as history only when useful.
- `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md` and related notes contain or refer to stale `0xffffffff` initialization wording. Current MCP `get_bytes 0x0069bf7c size 28` shows zero bytes; implementation should reject stale nonzero-initializer claims.
- VirusChecker-specific `simroot_v2`, Wave2/Wave3, and recovered-source mentions should not be used as proof. Preserve them only as generated-output history or future generated-source caveats if the target/support page already needs that context.
- Project-wide Wave/simroot text outside the VirusChecker target/support scope is not applicable to this report-only callback unless the supervisor explicitly broadens scope.

## Claim And Incorporation Ledger

| Claim ID | Claim / fact to apply or preserve | Evidence | Target/support destination | Action | Verification state |
|---|---|---|---|---|---|
| VC-001 | Replace B004 local PE/Capstone authority with current MCP session `86fb854e` as the active proof source. | Applied in `by-class`, `by-file`, aggregate/helper/global/type/meta support docs; validator commands `000000000331`-`000000000347` all exit 0 with `ok: 1`. | `by-class/VirusChecker.md`, `by-file/VirusChecker.md`, direct by-memory/global/type/meta support docs. | incorporate | applied |
| VC-002 | Preserve metadata `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000P5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P5`. | Already present and unchanged in `by-class/VirusChecker.md`; validator `000000000331` exit 0, `ok: 1`. | `by-class/VirusChecker.md`; coverage text remains supervisor-owned. | already-present | already-present |
| VC-003 | Preserve source route `NexusTK/security/VirusChecker.cpp`; do not move to STL, Application, LanguageMan, resource, import-wrapper, or third-party source. | Already present in `by-file/VirusChecker.md` and reinforced in class/file/meta text; no `by-project-structure` edit made. Validator `000000000332` exit 0, `ok: 1`. | `by-class/VirusChecker.md`, `by-file/VirusChecker.md`; `by-project-structure/proposed-source-tree.md` not touched. | already-present | already-present |
| VC-004 | Preserve exact formal class C++ block with `String` forward declaration, `std::set<String>` typedef, constructor/destructor, `LoadV3Scanner`, `ScanLoadedProcessModules`, private `InsertModulePath`, `m_modulePaths`, and `extern VirusChecker *g_pVirusChecker`. | Already present and intentionally unchanged in `by-class/VirusChecker.md`; no formal class C++ or generated C++ edit made. | `by-class/VirusChecker.md`. | already-present | already-present |
| VC-005 | Constructor at `0x005c0460` writes singleton, installs vtable, initializes container header/count, and calls shared tree/string support. | Present in target and aggregate; active proof source updated to current MCP `86fb854e`. Validators `000000000331` and `000000000333` exit 0, `ok: 1`. | `by-class/VirusChecker.md`, `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`. | incorporate | applied |
| VC-006 | Destructor at `0x005c04e0` and scalar deleting destructor at `0x005c0ec0` free handles, clear selected V3 pointers, destroy path tree, free sentinel/this, and clear singleton. | Preserved in class/aggregate/helper/vtable support and active proof refreshed to current MCP. Validators `000000000331`, `000000000333`, `000000000336`, `000000000341`-`000000000343` exit 0, `ok: 1`. | `by-class/VirusChecker.md`, aggregate memory doc, helper and vtable docs. | incorporate | applied |
| VC-007 | Vtable data is one source-facing `VirusChecker` vtable slot at `0x006310e0`, with preceding RTTI/COL pointer at `0x006310dc`. | Applied in vtable type/index/data pages with current MCP `86fb854e` bytes `08 3f 65 00 c0 0e 5c 00`; validators `000000000341`, `000000000342`, `000000000343` exit 0, `ok: 1`. | `by-type/by-vtable/VirusCheckerVtable.md`, `by-type/by-vtable/SecuritySingletonVtables.md`, `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`. | incorporate | applied |
| VC-008 | `LoadV3Scanner` at `0x005c05a0` dynamically loads AhnLab V3 DLLs and resolves exact exports; localized ids 219/220 report failures. | Already present at same-or-greater detail in UID0001NV and class/file; stale B004 local proof wording replaced. Validators `000000000331`, `000000000332`, `000000000335` exit 0, `ok: 1`. | `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`, class/file notes. | already-present | applied |
| VC-009 | `ScanLoadedProcessModules` at `0x005c07b0` enumerates processes/modules, scans module paths, formats localized id 221 detection text, and requests exit. | Already present at same-or-greater detail in UID0001NV and class/file; stale generated-output caveat historicalized. Validators `000000000331`, `000000000332`, `000000000335` exit 0, `ok: 1`. | `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`, class/file notes. | already-present | applied |
| VC-010 | Raw helper `0x005c0770-0x005c07ae` frees module handles and clears only three function pointers; it has no static xref and is not a normal function entry in IDA. | Applied in UID0001NV, aggregate, and globals cleanup; validators `000000000333`, `000000000335`, `000000000337` exit 0, `ok: 1`. | UID0001NV support, aggregate memory doc, globals doc. | incorporate | applied |
| VC-011 | `InsertModulePath`, module callback, process callback, and tree helpers are a class-owned module-path set; source should be `std::set<String>` or project equivalent, not raw helper names. | Applied in helper and struct support, class block preserved; validators `000000000336`, `000000000340`, `000000000331` exit 0, `ok: 1`. | `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`, `by-type/by-struct/VirusCheckerProcessTreeLayout.md`, class C++ block. | incorporate | applied |
| VC-012 | Dynamic global cluster `0x0069bf7c-0x0069bf94` is zero-initialized static storage for four function pointers and two handles. | Applied in dynamic globals and file doc with current MCP `get_bytes` proof; validators `000000000337` and `000000000332` exit 0, `ok: 1`. | `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`, `by-file/VirusChecker.md`. | incorporate | applied |
| VC-013 | Old `0xffffffff` global initializer wording is stale and should not remain as active evidence. | Rejected as stale in dynamic globals, singleton, class/file, and support docs; current zero-byte MCP proof is active. Validators `000000000337`, `000000000338`, `000000000339` exit 0, `ok: 1`. | Dynamic globals and mirrored singleton/file/class support notes. | reject-stale | excluded-with-reason |
| VC-014 | Use source-facing global names `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, `s_pfnAhnExCheckFile`, `s_pfnAhnExGetVirusName`, `s_hV3Pro32`, `s_hV3PCtrl`; do not preserve generated IDB names as source API. | Already present and preserved in dynamic globals/file/class/UID0001NV; validators `000000000331`, `000000000332`, `000000000335`, `000000000337` exit 0, `ok: 1`. | Globals doc, file doc, class/file C++ notes. | incorporate | applied |
| VC-015 | V3 read-only strings at `0x006310e4-0x00631184` include exact DLL/export names and wide DLL-name forms. | Applied with current MCP session `86fb854e` byte/string proof in V3 string data page and preserved in file/meta notes; validators `000000000344`, `000000000332`, `000000000347` exit 0, `ok: 1`. | `by-memory/0x006310e4-0x00631184.VirusCheckerV3StringData.md`, by-file/meta notes. | incorporate | applied |
| VC-016 | `g_pVirusChecker` has only local lifecycle refs; no external singleton consumer or static activation path was found. | Applied in global and exact singleton memory page with current MCP `86fb854e` wording; validators `000000000338` and `000000000339` exit 0, `ok: 1`. | `by-global/g_pVirusChecker.md`, `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`, class confidence rationale. | incorporate | applied |
| VC-017 | No direct constructor/load/scan/insert activation route was found; this is the reason confidence remains capped below 90. | Applied in class/file/aggregate/helper/singleton docs; target score unchanged. Validators `000000000331`-`000000000339` for affected docs exit 0, `ok: 1`. | `by-class/VirusChecker.md`, `by-file/VirusChecker.md`, aggregate memory doc, singleton docs. | incorporate | applied |
| VC-018 | B002 UID0001NV method-body implementation details are accepted support evidence and should be preserved, not replaced by this class report. | Already present; UID0001NV formal C++ was not changed. Only stale B004/local and old generated-output wording was historicalized. Validator `000000000335` exit 0, `ok: 1`. | UID0001NV support page and generated C++ freshness context. | already-present | already-present |
| VC-019 | Prior B004 fallback/local PE text is historical lead material only and must not be active proof in target/support docs. | Historicalized or replaced in all edited active docs; old report body preserved as historical lead. Validator set `000000000331`-`000000000347` exit 0. | B004 report body, target/support changelog/history notes. | historicalize | applied |
| VC-020 | VirusChecker-specific Wave2/Wave3/simroot/recovered-source mentions are generated-output history or caveats only, not evidence authority. | Applied in aggregate/helper/UID0001NV and meta anticheat docs; project-wide unrelated Wave/simroot text left untouched. Validators `000000000333`, `000000000335`, `000000000336`, `000000000345` exit 0, `ok: 1`. | VirusChecker support docs and meta docs where target-specific. | reject-stale | excluded-with-reason |
| VC-021 | Project-wide Wave/simroot text outside the VirusChecker target/support scope is not part of this callback. | Excluded by goal scope; no project-wide generated/manual coverage or by-project-structure edits were made. Validator-driven `project-level/-auto-completion-stats.md` updates were tool side effects only. | Project-level/generated/manual coverage docs. | not-applicable | excluded-with-reason |
| VC-022 | No static third-party import directive is required for this class. | Preserved in file/meta notes: VirusChecker dynamically loads AhnLab DLLs via `LoadLibraryA`/`GetProcAddress`; no `third_party_embeds/` directive added. Validators `000000000332`, `000000000345`, `000000000347` exit 0, `ok: 1`. | Class/file/source-route notes. | not-applicable | excluded-with-reason |
| VC-023 | Do not edit generated files, manual coverage reports, tool state, lock files, IDA DB, or executed reports during callback except validator-owned side effects. | No manual edits to generated/manual coverage/tool/lock/executed/IDA files. Scoped validators produced normal `project-level/-auto-completion-stats.md` and `tools/validator.ini` side effects, reported here. | This report and implementation result. | not-applicable | applied |

## Implementation Callback Validator Results

All commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240`; every edited by-* file returned exit code `0` and `ok: 1`.

| File | command_id | command_timestamp | Notes |
|---|---:|---|---|
| `by-class/VirusChecker.md` | `000000000331` | `2026-06-29T02:15:40-04:00` | Existing `missing_ref_uid 0003JF`; generated refresh deferred. |
| `by-file/VirusChecker.md` | `000000000332` | `2026-06-29T02:15:42-04:00` | Existing `missing_ref_uid 0003JF`; generated refresh deferred. |
| `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md` | `000000000333` | `2026-06-29T02:15:44-04:00` | Generated refresh deferred. |
| `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md` | `000000000335` | `2026-06-29T02:15:50-04:00` | Generated refresh deferred. |
| `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md` | `000000000336` | `2026-06-29T02:15:59-04:00` | Generated refresh deferred. |
| `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md` | `000000000337` | `2026-06-29T02:16:04-04:00` | Generated refresh deferred. |
| `by-global/g_pVirusChecker.md` | `000000000338` | `2026-06-29T02:16:12-04:00` | Validator-owned autogen registry/stats side effects. |
| `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md` | `000000000339` | `2026-06-29T02:16:21-04:00` | Validator inserted blank header spacer and updated registry. |
| `by-type/by-struct/VirusCheckerProcessTreeLayout.md` | `000000000340` | `2026-06-29T02:16:22-04:00` | Validator-owned registry side effects. |
| `by-type/by-vtable/VirusCheckerVtable.md` | `000000000341` | `2026-06-29T02:16:24-04:00` | Validator added UID mapping/reference index for existing page. |
| `by-type/by-vtable/SecuritySingletonVtables.md` | `000000000342` | `2026-06-29T02:16:26-04:00` | Existing `missing_ref_uid 0003JE` and missing CheatDetector target path. |
| `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md` | `000000000343` | `2026-06-29T02:16:27-04:00` | Validator inserted blank header spacer and updated registry. |
| `by-memory/0x006310e4-0x00631184.VirusCheckerV3StringData.md` | `000000000344` | `2026-06-29T02:16:29-04:00` | Generated refresh deferred. |
| `by-meta/client_anticheat.md` | `000000000345` | `2026-06-29T02:16:30-04:00` | Existing missing CheatDetector target path. |
| `by-meta/client_libraries.md` | `000000000347` | `2026-06-29T02:16:40-04:00` | Existing `missing_ref_uid` values for unrelated library refs. |

## Implementation Tracking Checklist

- [x] Supervisor validates this revised report and sends an implementation callback before any target/support by-* edit. Proof: `goal.md` assignment `B004-implementation-callback-0000FW-VirusChecker-class-source-quality-20260629` accepted this report for implementation.
- [x] Preserve the existing report body as historical lead material; do not delete the old offline report evidence. Proof: historical offline sections remain in this report and were not rewritten from scratch.
- [x] In `by-class/VirusChecker.md`, replace active B004 local PE/Capstone proof wording with current MCP session `86fb854e` proof while preserving metadata `88/89`, owner/emitter `0000P5`, reconstructable `TRUE`, and the existing formal C++ block. Proof: edited class purpose/data/change notes; validator `000000000331`, exit 0, `ok: 1`.
- [x] In `by-file/VirusChecker.md`, replace active local PE/Capstone source-quality wording with current MCP evidence and preserve source route `NexusTK/security/VirusChecker.cpp`. Proof: edited file role/evidence/change notes; validator `000000000332`, exit 0, `ok: 1`.
- [x] In `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`, update constructor/destructor/vtable/global/container evidence to current MCP wording and historicalize the fallback-only proof source. Proof: edited boundary/evidence/gate/change notes; validator `000000000333`, exit 0, `ok: 1`.
- [x] In `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`, verify B002 current-MCP details remain present; edit only if this callback finds a contradictory or stale B004-local proof statement. Proof: B002 formal C++ preserved unchanged; stale local/generated-output wording historicalized; validator `000000000335`, exit 0, `ok: 1`.
- [x] In `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`, replace active local PE/Capstone wording, keep the source-facing path-set/container model, and preserve any Wave/simroot text only as generated-output history. Proof: edited status/function/evidence/ownership/change notes; validator `000000000336`, exit 0, `ok: 1`.
- [x] In `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`, record current zero-initialized bytes, reject stale `0xffffffff` initializer wording, and keep source-facing static global names. Proof: edited item summary/summary/evidence/change notes; validator `000000000337`, exit 0, `ok: 1`.
- [x] In `by-global/g_pVirusChecker.md` and `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`, replace fallback-only no-consumer wording with current `xrefs_to`/`find_bytes` evidence and keep the no-activation confidence cap. Proof: edited both singleton docs; validators `000000000338` and `000000000339`, exit 0, `ok: 1`.
- [x] In `by-type/by-struct/VirusCheckerProcessTreeLayout.md`, preserve the `std::set<String>`/path-set source model and historicalize obsolete below-95 no-code wording if it is still active. Proof: edited evidence/caveat/gate/change notes; validator `000000000340`, exit 0, `ok: 1`.
- [x] In `by-type/by-vtable/VirusCheckerVtable.md`, `by-type/by-vtable/SecuritySingletonVtables.md`, and `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`, preserve the one-slot `VirusChecker` vtable facts and add current MCP byte/xref support if missing. Proof: edited all three vtable support docs; validators `000000000341`, `000000000342`, and `000000000343`, exit 0, `ok: 1`.
- [x] In `by-memory/0x006310e4-0x00631184.VirusCheckerV3StringData.md`, preserve the exact V3 DLL/export string facts and replace any local-only proof wording if active. Proof: exact string facts preserved, current MCP `86fb854e` evidence added; validator `000000000344`, exit 0, `ok: 1`.
- [x] In VirusChecker-specific `by-meta/client_anticheat.md` and `by-meta/client_libraries.md` notes, replace B004 local PE/Capstone proof wording with current MCP or mark it historical; leave unrelated project-wide Wave/simroot text untouched. Proof: edited VirusChecker-specific bullets only; validators `000000000345` and `000000000347`, exit 0, `ok: 1`.
- [x] Do not edit `by-project-structure/proposed-source-tree.md` unless the supervisor explicitly scopes it; no source-tree move is recommended. Proof: no by-project-structure source-tree edit was made.
- [x] Do not edit generated reports, generated C++ files, manual `-coverage-report.md` files, project-level generated files, validator/tool state, lock files, executed reports, or IDA DB. Proof: no manual edits to those files; scoped validators produced normal `project-level/-auto-completion-stats.md` and `tools/validator.ini` side effects only.
- [x] If an implementation callback edits by-* docs, use short leases only when ready to edit and release them immediately after the edit/validator batch. Proof: B004 leased 15 by-* files immediately before editing; lease expired during validation and `unlease` reported `Rejected[No active lease]` for each; current lease report contains no B004 entries.
- [x] Run scoped validators only for touched docs, for example `python .\tools\validator.py --mode file --file .\by-class\VirusChecker.md --apply --queue-timeout 240` from `source-3/project-documentation`; include analogous commands for every touched by-file/by-memory/by-global/by-type/by-meta support doc. Proof: validator table above lists all 15 touched by-* files, command IDs, timestamps, exit 0, and `ok: 1`.
- [x] After validators, perform generated freshness checks for `auto-generated/NexusTK/security/VirusChecker.cpp` only if class/file C++ marker content or emitter state is touched; do not hand-edit generated files. Proof: formal class C++ and emitter metadata were not changed, so no generated C++ freshness check was required; validator reported generated refresh deferred but no generated file was used as proof.
- [x] Record any generated-refresh or validator result in the callback report; do not run `execute_report`. Proof: validator results are recorded above; `execute_report` was not run.
- [x] Implementation callback status: accepted edits applied or verified already present; ledger VC-001 through VC-023 updated to callback states; no unresolved accepted checklist item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0000FW-VirusChecker-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000FW-VirusChecker-class-source-quality.md","timestamp":"2026-06-29T02:22:43","uid":"0000FW"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FW-VirusChecker-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0000FW-VirusChecker-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
