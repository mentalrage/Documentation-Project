** TARGET-REPORT-UID:0002H5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002H5] ApplicationDetectOS Empty-Emitter Source-Quality Report

Agent: B005  
Assignment: `B005-empty-emitter-report-0002H5-ApplicationDetectOS-20260629`  
Mode: report-only research first  
Target: `by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md`  
Date: 2026-06-29  

## Executive Summary

UID0002H5 is a valid Application method routed through [UID:00000D] `Application` and [UID:0000HG] `Application.cpp`. The empty-emitter queue entry is stale against the current by-memory page: the target page now carries `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000D`, while generated `auto-generated/NexusTK/app/Application.cpp` and generated coverage still show the older `82/88` empty-marker state.

Current MCP session `b6b3c97e` confirms the exact function, branch tree, field writes, string/data dependencies, caller, callees, and padding boundaries. The old B002 no-code rationale was valid at the time, but the named blocker is now narrow enough to resolve: exact original enum/member spellings are not proven, but current Application support docs already accept inferred source-facing member names for comparable first-draft Application children. The correct callback action is to add a formal first-draft C++ body for `const wchar_t *Application::DetectOS()`, raise the target to `90/92`, and update support docs to mark the enum/code constants as reconstructed rather than symbol-proven.

No target/support by-* docs, generated files, coverage files, tool state, validator state, or IDA state were edited during this report-only pass.

## Scope And Current State

Target file:

- [UID:0002H5] `by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md`

Current target metadata:

| Field | Current value |
| --- | --- |
| Completion | `87` |
| Confidence | `90` |
| Canonical owner | `00000D` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `00000D` |
| Formal C++ | blank |

Current route:

| Layer | Evidence |
| --- | --- |
| Direct owner | [UID:00000D] `by-class/Application.md`, `CANONICAL_OWNER:0000HG`, `EMITTER_UIDS:0000HG`. |
| File root | [UID:0000HG] `by-file/Application.md`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`. |
| Generated file | `auto-generated/NexusTK/app/Application.cpp`. |
| Generated memory coverage | UID0002H5 is `emits`, owner/emitter `00000D`, generated file `auto-generated/NexusTK/app/Application.cpp`, final C++ `no`. |

Current generated-output problem:

- `auto-generated/NexusTK/app/Application.cpp` still shows `// UID:0002H5 ... Completion:82 | Confidence:88 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` still lists UID0002H5 at `82/88`, average `85.0`, empty.
- `auto-generated/-ag-coverage-report-by-memory.md` still shows `emits_code:false`, `82%`, and stale text saying final enum/member/source names remain open.
- These generated files are stale read-only evidence for this report. They must not be manually edited.

## Inputs Reviewed

Current project docs reviewed:

- Target page [UID:0002H5] `ApplicationDetectOS`.
- Owner route [UID:00000D] `Application`.
- File route [UID:0000HG] `Application`.
- Writer/accessor pair [UID:0002JV] `ApplicationGetOsCode`.
- String literal pool [UID:000483] `ApplicationOsAndRuntimeStringData`.
- String append helper [UID:000325] `StringBaseAppendWideLiteral`.
- StringBase helper aggregate `0x00584160-0x005845af.StringBaseAppendAndFind`.
- OS/version global state [UID:000293] `ApplicationOsVersionState`.
- Constructor support [UID:0002GY] `ApplicationConstructor`.
- Source-ready sibling precedent pages [UID:0002H4], [UID:0002GO], [UID:0002GM], [UID:0002GP], and [UID:0002JW].
- Generated read-only reports/files: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/app/Application.cpp`.

Existing report leads searched with UID/address/name/Application lifecycle terms:

- Main historical report: `executed-b-agent-research/B002/0002H0-0002JV-application-lifecycle-source-quality.md`.
- Related StringBase report: `executed-b-agent-research/B001/000325-StringBaseAppendWideLiteral-source-quality.md`.
- Related literal-pool report: `executed-b-agent-research/B011/000483-ApplicationOsAndRuntimeStringData-empty-emitter-source-quality.md`.
- Related read-only-data split report: `executed-b-agent-research/B004/00024T-ApplicationStartupReadOnlyData-source-quality.md`.
- Active Agent-B005 research folder had no existing UID0002H5 report before this file was created.

Historical report claims were treated as leads only. The material UID0002H5 facts below were revalidated with current MCP session `b6b3c97e` and current by-* docs.

## Current MCP Evidence

MCP endpoint: `http://127.0.0.1:13337/mcp`  
Active session from `idb_list`: `b6b3c97e`  
IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`  
Module: `NexusTK.exe`  
Imagebase: `0x400000`  
Server: `ida-pro-mcp 1.0.0`  
Health: `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready, `strings_cache_size:2067`.

Function and boundary evidence:

| MCP call | Result |
| --- | --- |
| `lookup_funcs` `0x00464f50` | `sub_464F50`, size `0x1c5`, range `0x00464f50-0x00465115`. |
| `lookup_funcs` `0x00464f40` | predecessor `sub_464F40`, size `0x7`. |
| `lookup_funcs` `0x00465115` | not a function. |
| `lookup_funcs` `0x00465120` | successor `sub_465120`, size `0x4`. |
| `get_bytes 0x00464f47 size 9` | nine `0xcc` bytes before UID0002H5. |
| `get_bytes 0x00465110 size 32` | UID0002H5 tail `... 8b e5 5d c3`, then `0xcc` padding through `0x00465120`, then `8b 41 10 c3` for UID0002JV. |
| `xrefs_to 0x00464f50` | one direct code xref at `0x00463522` from `Application__Constructor`. |
| `xrefs_to 0x00465115` | zero xrefs to exclusive end. |
| `xrefs_to 0x00465120` | zero direct xrefs to the next accessor start. |

Function structure evidence:

| MCP call | Result |
| --- | --- |
| `analyze_function 0x00464f50` | prototype `int __thiscall(int this)` as decompiler ABI, size `453`, 38 basic blocks, cyclomatic complexity `19`. |
| `callees 0x00464f50` | `GetModuleHandleW`, `GetProcAddress`, `GetCurrentProcess`, `GetVersionExA`, `sub_582D20`, `sub_4671B0`, `sub_584540`, `@__security_check_cookie@4`. |
| `decompile 0x00464f50` | clears `this+0x18`, dynamically resolves `IsWow64Process`, calls `GetVersionExA` with size `148`, writes `this+0x10`, assigns `this+0x854`, appends bitness suffix for Windows 7/8, and returns `sub_584540(this+0x854)`. |
| `disasm 0x00464f50` | 132 instructions; confirms exact string refs, field offsets, branch constants, suffix selection, `sub_4671B0` call at `0x0046509f`, `sub_582D20` calls at `0x00465086`/`0x004650f9`, `sub_584540` at `0x00465100`, return at `0x00465114`. |

String and data evidence:

| Address | Current evidence |
| --- | --- |
| `0x006127f8` | ANSI `IsWow64Process`; xref from `0x00464f67`. |
| `0x00612808` | UTF-16LE `kernel32`; xref from `0x00464f6c`, plus one data ref at `0x00635268`. |
| `0x0061281c` | UTF-16LE `WindowsXP`; xref from `0x004650de`. |
| `0x00612830` | UTF-16LE `Windows2000`; xref from `0x004650a6`. |
| `0x00612848` | UTF-16LE `WindowsNT`; xref from `0x004650ec`. |
| `0x0061285c` | UTF-16LE `Windows98`; xref from `0x004650bb`. |
| `0x00612870` | UTF-16LE `Windows95`; xrefs from `0x00464fd3` and `0x004650b4`. |
| `0x00612884` | UTF-16LE `WindowsVista`; xref from `0x004650e5`. |
| `0x006128a0` | UTF-16LE `Windows7`; xref from `0x00465079`. |
| `0x006128b4` | UTF-16LE `_64bit`; xref from `0x00465094`. |
| `0x006128c4` | UTF-16LE `_32bit`; xref from `0x0046508f`. |
| `0x006128d4` | UTF-16LE `Windows8`; xref from `0x00465072`. |
| `0x006128e8` | UTF-16LE `Unknown`; xref from `0x004650d7`. |

`get_bytes 0x0061281c size 220` decoded the complete UTF-16LE label island. MCP string-cache `get_string` only returned first-character fragments for most UTF-16 labels, so raw byte decoding and current UID000483 support docs are the authority for those wide labels.

`int_convert` verified:

- `0x1c5` = `453`;
- `0x854` = `2132`;
- `0x18` = `24`;
- `0x10` = `16`;
- OS-code constants decode to compact little-endian ASCII-like tags: `0x776e3935` (`59nw`), `0x776e3938` (`89nw`), `0x776e6e74` (`tnnw`), `0x776e326b` (`k2nw`), `0x776e7870` (`pxnw`), `0x776e7674` (`tvnw`), `0x00776e37` (`7nw`), and `0x00776e38` (`8nw`).

## Behavior Reconstruction

The function is an Application instance method that detects OS version and WOW64 state, stores a compact internal OS code, writes an OS label string, appends a bitness suffix for Windows 7/8 labels, and returns the label string data pointer.

Observed state:

| State | Access |
| --- | --- |
| `Application+0x18` / `m_isWow64` | Cleared to zero at entry, then set from `IsWow64Process(GetCurrentProcess(), &localBool)` when the API exists and returns nonzero. |
| `Application+0x10` / `m_osCode` | Written with compact code constants for recognized platform/version cases. For NT `dwMajorVersion > 6`, the function reads the existing field instead of writing a new code. |
| `Application+0x854` / `m_osVersionLabel` | Assigned a wide label via `sub_582D20` / `AssignWideLiteral`; Windows 7/8 then append `_64bit` or `_32bit` through [UID:000325] `StringBaseAppendWideLiteral`; final data pointer returned through `sub_584540` / `c_str`. |

Corrected branch mapping from current MCP:

| Win32 version evidence | Stored/read code | Label behavior |
| --- | --- | --- |
| `dwPlatformId == VER_PLATFORM_WIN32_WINDOWS`, `dwMinorVersion == 0` | writes `0x776e3935` | `Windows95` |
| `dwPlatformId == VER_PLATFORM_WIN32_WINDOWS`, `dwMinorVersion != 0` | writes `0x776e3938` | `Windows98` |
| `dwPlatformId` neither `VER_PLATFORM_WIN32_WINDOWS` nor `VER_PLATFORM_WIN32_NT` | writes `0x776e3935` | `Windows95` |
| `dwPlatformId == VER_PLATFORM_WIN32_NT`, `dwMajorVersion <= 4` | writes `0x776e6e74` | `WindowsNT` |
| NT major `5`, minor `0` | writes `0x776e326b` | `Windows2000` |
| NT major `5`, minor nonzero | writes `0x776e7870` | `WindowsXP` |
| NT major `6`, minor `0` | writes `0x776e7674` | `WindowsVista` |
| NT major `6`, minor `1` | writes `0x00776e37` | `Windows7` plus `_64bit` or `_32bit` |
| NT major `6`, minor other nonzero | writes `0x00776e38` | `Windows8` plus `_64bit` or `_32bit` |
| NT major `> 6` | reads previous `m_osCode` value | label is selected from previous code if it matches a known code, otherwise `Unknown` |
| any unmatched code during label selection | no additional code write | `Unknown` |

The old target table's broad "unmapped/default -> Unknown" wording is incomplete. The current decompile proves a separate non-WIN32/NT default that writes the Windows95 code/label, and an NT-major-greater-than-six path that preserves the previous OS code and can fall to `Unknown`.

## Positive Evidence

- The target clears the current code-entry gate: reconstructable true, nonblank emitter route to a valid generated source root, and current average score `88.5` before this report.
- Current MCP proves exact range `0x00464f50-0x00465115`, not a split or aggregate-only child.
- The only direct caller is `Application__Constructor` at `0x00463522`, matching Application ownership and constructor support docs.
- The dynamic WOW64 path is exact: `GetModuleHandleW(L"kernel32")`, `GetProcAddress(..., "IsWow64Process")`, `GetCurrentProcess()`, conditional call through the resolved pointer, and byte store to `Application+0x18`.
- The version path is exact: local `OSVERSIONINFOA`, `dwOSVersionInfoSize = 0x94` / 148, `GetVersionExA`, and branch decisions over platform/major/minor fields.
- The compact code field is exact: all writes and label switch comparisons target `Application+0x10`.
- The label field is exact: `Application+0x854` is assigned through the accepted wide StringBase literal assignment helper and returned through the accepted `c_str` / data-pointer helper.
- The suffix append dependency is exact and already source-ready in [UID:000325], with Application documented as a consumer rather than owner of the generic StringBase helper.
- The wide label bytes and xrefs are current and match [UID:000483]'s decoded literal inventory.
- Boundary padding is current: `0x00464f47-0x00464f50` and `0x00465115-0x00465120` are `0xcc` alignment, not hidden code/data.
- Sibling Application methods now emit first-draft C++ despite inferred exact original spellings when behavior, route, and source-facing names are documented. Examples include `IsExitRequested`, `IsRunning`, `GetInstanceHandle`, `GetVersionMajor`, and `ReadProcessorName`.

## Negative Evidence And Rejected Alternatives

| Alternative | Decision | Evidence |
| --- | --- | --- |
| Dead emitter / wrong route | Reject. | UID0002H5 routes through `Application` -> `Application.cpp`; generated memory coverage says `emits` with owner/emitter `00000D`. |
| BaramApp or WinMain ownership | Reject. | The only direct caller is the Application constructor; state writes are Application object fields. |
| StringBase ownership | Reject for UID0002H5. | StringBase owns `AssignWideLiteral`, `operator+=`, and `c_str` helpers; UID0002H5 owns OS policy and Application field writes. |
| `ApplicationOsVersionState` global ownership | Reject. | UID000293 is constructor/global OSVERSIONINFOW storage; UID0002H5 writes per-object fields `+0x10`, `+0x18`, and `+0x854`. |
| Raw `OSVERSIONINFOA` member at `Application+0x10` | Reject. | `+0x10` receives compact 32-bit constants and is read by UID0002JV; the OSVERSIONINFOA struct is stack-local. |
| `m_is64BitOS` name | Reject as emitted name. | Stored byte is exactly WOW64 API result, not native architecture proof. Use `m_isWow64`. |
| Required exact original enum spelling before code | Reject as a no-code blocker. | The exact code constants are binary-proven; source-facing names can be documented as reconstructed local constants. Current workflow and sibling Application pages allow first-draft bodies with inferred names when evidence is recorded. |
| `void Application::DetectOS()` | Weaker than return-pointer signature. | The binary makes a final `sub_584540` / `c_str` call and returns that value. A void source body would not need the final data-pointer accessor. |
| Covered-by/no-code marker | Reject. | No other target emits this 453-byte method body; constructor call is a separate caller, not coverage for this range. |
| Standalone enum or header declaration inside this by-memory target | Reject for the target C++ block. | The exact target range owns method code and embedded immediates, not broad class/header declarations. First-draft body should use method-local constants and support docs should describe optional future enum promotion. |
| Manual generated-file edit | Reject. | Generated files are stale validator/generator outputs and are forbidden to edit by assignment. |

## Heuristic / Inference Reanalysis And Validation

### Named Blocker Audit

| Named blocker from goal/current docs | Evidence route checked | Resolution |
| --- | --- | --- |
| Empty-emitter blocker | Target metadata, generated `Application.cpp`, generated memory coverage, research tracker. | Valid route and score gate exist; formal C++ is blank and generated outputs are stale. Callback should add method C++ to target then run scoped validators/generator refresh. |
| Owner/emitter through Application/Application.cpp | Target, by-class, by-file, generated memory coverage, MCP caller. | Confirmed. Keep `CANONICAL_OWNER:00000D`, `EMITTER_UIDS:00000D`; file root remains [UID:0000HG] `NexusTK/app/Application.cpp`. |
| Score movement | Current target `87/90`, current evidence, sibling source-ready methods. | Raise to `90/92` after formal body and branch-correction edits. Do not raise to 95+ because original enum/member spelling and class/header declaration still require broader audit. |
| First-draft C++ readiness | MCP exact function, dependencies, field names, route, generated state, sibling precedent. | Ready. Use method-local constants and documented inferred member names; return `m_osVersionLabel.c_str()`. |
| OS/WOW64 field/type/name inference | Class/file field notes, target decompile, UID0002JV, UID000293. | `m_osCode` is a 32-bit compact code field; `ApplicationOsCode` remains reconstructed/optional. `m_isWow64` and `m_osVersionLabel` are source-facing inferred names with enough support for first-draft body. |
| Formal body vs no-code proof | Final `c_str` return, no alternate emitter, route valid. | Formal method body is correct. No-code proof is rejected. |
| "Final enum/member/source names remain open" | Current docs and old B002 rationale. | Historicalized as stale/no-longer-blocking for first-draft. Preserve caveat as a below-95 confidence cap, not as blank-C++ reason. |

### Source-Facing Name Decisions

| Binary fact | Recommended source-facing representation | Caveat |
| --- | --- | --- |
| `this+0x10` compact code writes | `m_osCode` field, first-draft as unsigned 32-bit code. | `ApplicationOsCode` is a reconstructed type/enum name, not proven original. Do not require a header enum before first-draft body. |
| `this+0x18` byte write from `IsWow64Process` | `m_isWow64` boolean/byte field. | Exact original member spelling not recovered. |
| `this+0x854` StringBase assignment/append/c_str | `m_osVersionLabel`. | Exact StringBase facade type spelling belongs to support docs. |
| `sub_582D20` | `AssignWideLiteral`. | Accepted StringBase support name, not target-local helper. |
| `sub_4671B0` | `operator+=(const wchar_t*)` / `StringBaseAppendWideLiteral`. | Helper emits through StringBase; Application only uses it. |
| `sub_584540` | `c_str()` / data-pointer accessor. | The return-pointer signature should be `const wchar_t *Application::DetectOS()`. |

## Score And Metadata Recommendation

Recommended target metadata after supervisor acceptance:

| Field | Recommended value | Reason |
| --- | --- | --- |
| `COMPLETION` | `90` | Current report closes the empty-emitter audit, corrects the default branch nuance, supplies exact formal C++ text, records current MCP evidence, and lists implementation-ready support edits. |
| `CONFIDENCE` | `92` | Current MCP proves behavior, dependencies, boundaries, and route. Confidence remains below 95 because exact original enum/member/header spelling is inferred and broader class declaration remains incomplete. |
| `CANONICAL_OWNER` | `00000D` | Application owns the method and fields. |
| `RECONSTRUCTABLE` | `TRUE` | Source-authored Application method. |
| `EMITTER_UIDS` | `00000D` | Application class surfaces to [UID:0000HG] Application file root. |
| `RECONSTRUCTION_CPP CODE` | populate with first-draft body below | Formal method body is ready; no-code proof rejected. |

Recommended item summary:

```text
Source-ready Application OS/WOW64 detection method; current MCP confirms exact 0x1c5-byte body, constructor caller, dynamic IsWow64Process/GetVersionExA flow, m_osCode/m_isWow64/m_osVersionLabel writes, Windows label mapping, StringBase suffix append, final c_str return, and adjacent padding. Exact enum/member spellings remain reconstructed caveats, not C++ blockers.
```

## Proposed Formal C++ For Target

Insert this exact body into the target's multiline `RECONSTRUCTION_CPP CODE` block if accepted:

```cpp
const wchar_t *Application::DetectOS()
{
    typedef BOOL (WINAPI *IsWow64ProcessProc)(HANDLE, PBOOL);

    static const unsigned int kApplicationOsWindows95 = 0x776e3935;
    static const unsigned int kApplicationOsWindows98 = 0x776e3938;
    static const unsigned int kApplicationOsWindowsNT = 0x776e6e74;
    static const unsigned int kApplicationOsWindows2000 = 0x776e326b;
    static const unsigned int kApplicationOsWindowsXP = 0x776e7870;
    static const unsigned int kApplicationOsWindowsVista = 0x776e7674;
    static const unsigned int kApplicationOsWindows7 = 0x00776e37;
    static const unsigned int kApplicationOsWindows8 = 0x00776e38;

    m_isWow64 = false;

    IsWow64ProcessProc isWow64Process =
        reinterpret_cast<IsWow64ProcessProc>(
            GetProcAddress(GetModuleHandleW(L"kernel32"), "IsWow64Process"));
    if (isWow64Process != NULL) {
        BOOL isWow64;
        if (isWow64Process(GetCurrentProcess(), &isWow64) != FALSE) {
            m_isWow64 = (isWow64 != FALSE);
        }
    }

    OSVERSIONINFOA versionInfo;
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExA(&versionInfo);

    if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) {
        m_osCode = (versionInfo.dwMinorVersion != 0)
            ? kApplicationOsWindows98
            : kApplicationOsWindows95;
    } else if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        if (versionInfo.dwMajorVersion == 6) {
            if (versionInfo.dwMinorVersion == 0) {
                m_osCode = kApplicationOsWindowsVista;
            } else {
                m_osCode = (versionInfo.dwMinorVersion == 1)
                    ? kApplicationOsWindows7
                    : kApplicationOsWindows8;
            }
        } else if (versionInfo.dwMajorVersion == 5) {
            m_osCode = (versionInfo.dwMinorVersion != 0)
                ? kApplicationOsWindowsXP
                : kApplicationOsWindows2000;
        } else if (versionInfo.dwMajorVersion <= 4) {
            m_osCode = kApplicationOsWindowsNT;
        }
    } else {
        m_osCode = kApplicationOsWindows95;
    }

    const wchar_t *label = L"Unknown";
    bool appendBitnessSuffix = false;

    switch (m_osCode) {
    case kApplicationOsWindows95:
        label = L"Windows95";
        break;
    case kApplicationOsWindows98:
        label = L"Windows98";
        break;
    case kApplicationOsWindowsNT:
        label = L"WindowsNT";
        break;
    case kApplicationOsWindows2000:
        label = L"Windows2000";
        break;
    case kApplicationOsWindowsXP:
        label = L"WindowsXP";
        break;
    case kApplicationOsWindowsVista:
        label = L"WindowsVista";
        break;
    case kApplicationOsWindows7:
        label = L"Windows7";
        appendBitnessSuffix = true;
        break;
    case kApplicationOsWindows8:
        label = L"Windows8";
        appendBitnessSuffix = true;
        break;
    }

    m_osVersionLabel.AssignWideLiteral(label);
    if (appendBitnessSuffix) {
        m_osVersionLabel += (m_isWow64 ? L"_64bit" : L"_32bit");
    }

    return m_osVersionLabel.c_str();
}
```

C++ notes:

- The uninitialized `BOOL isWow64` and `OSVERSIONINFOA versionInfo` locals intentionally match the binary's lack of local zeroing before the API writes.
- The `GetVersionExA` return value is intentionally ignored.
- NT major-version values greater than `6` intentionally preserve the previous `m_osCode` value, matching the binary's no-write path.
- Method-local constants avoid declaring a project-wide enum in a by-memory method body. Support docs can keep `ApplicationOsCode` as a reconstructed type name or later promote it during a class/header declaration pass.
- The final `c_str()` return is required by the target bytes and supports `const wchar_t *Application::DetectOS()` over a void signature.

## Target And Support Edits Needed If Accepted

Target [UID:0002H5] `by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md`:

- Update `COMPLETION` from `87` to `90`.
- Update `CONFIDENCE` from `90` to `92`.
- Keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank emitter position.
- Fill the multiline formal C++ block with the exact body above.
- Update the item summary to remove the stale "final enum/member/source names remain open" no-code phrasing.
- In `Behavior`, add the current MCP-corrected default/NT-major-greater-than-six branch behavior.
- In `IDA Evidence`, add current session `b6b3c97e` evidence: health, range `0x1c5`, 38 blocks/complexity 19, constructor caller, callees, boundary bytes, string xrefs, and final `c_str` return.
- In `Reconstruction Notes`, replace "final C++ should wait" with "first-draft formal body is ready; exact enum/member/header spelling remains below-95 caveat."
- In `Score Rationale`, explain `90/92` and why not 95+.
- Add a change-log entry for this accepted report if/when implemented.

Support [UID:00000D] `by-class/Application.md`:

- Update the UID0002H5 method bullet to state it is source-ready as `const wchar_t *Application::DetectOS()` after acceptance.
- In fields, keep `m_osCode` / reconstructed `ApplicationOsCode` at `0x10`, `m_isWow64` at `0x18`, and `m_osVersionLabel` at `0x854`; add that the first-draft method uses method-local constants because exact enum spelling is reconstructed.
- Add or update a change entry tying UID0002H5 to MCP session `b6b3c97e`, the formal C++ body, and `90/92`.

Support [UID:0000HG] `by-file/Application.md`:

- Remove UID0002H5 from the "larger lifecycle children still blocked on source-facing enum/member spelling" no-code list.
- Add UID0002H5 to the list of exact Application children that now emit first-draft bodies despite inferred support-name caveats.
- Record that generated `Application.cpp` was stale at report time and must be refreshed through validator/generator output only.
- Add a change entry for UID0002H5 implementation if accepted.

Support [UID:000293] `ApplicationOsVersionState`:

- Preserve the distinction between global OSVERSIONINFOW state and per-object UID0002H5 state.
- If edited, add a short note that UID0002H5 now emits using method-local reconstructed constants while `ApplicationOsCode` remains a reconstructed source-facing type name.

Generated outputs:

- Do not edit manually.
- After target/support edits and validators, inspect `auto-generated/NexusTK/app/Application.cpp` read-only and verify UID0002H5 no longer shows `Empty Emitter Marker` and includes the formal body.

## Claim And Incorporation Ledger

| ID | Claim / fact | Action | Target/support destination | Verification state | Evidence |
| --- | --- | --- | --- | --- | --- |
| L1 | UID0002H5 is exact range `0x00464f50-0x00465115`, `0x1c5` / 453 bytes. | incorporate | Target IDA Evidence, Scope, Score Rationale | applied | Target metadata/IDA Evidence/Score Rationale updated; validator `000000000560` ok:1. |
| L2 | Active MCP session is `b6b3c97e`, health ok, Hex-Rays/string cache ready. | incorporate | Target IDA Evidence and change entry | applied | Target IDA Evidence and 2026-06-29 change entry record MCP session `b6b3c97e`; validator `000000000560` ok:1. |
| L3 | Function has 38 basic blocks and cyclomatic complexity 19. | incorporate | Target IDA Evidence | applied | Target IDA Evidence preserves the 38-block/complexity-19 accepted metric. |
| L4 | Only direct caller is `Application__Constructor` at `0x00463522`. | incorporate | Target IDA Evidence, Application class/file support | applied | Target, class, and file support pages record constructor caller `0x00463522`; validators `000000000560`/`000000000561`/`000000000562` ok:1. |
| L5 | Callees are Win32 API resolver/version/process calls plus StringBase assign/append/c_str and security cookie. | incorporate | Target IDA Evidence | applied | Target IDA Evidence and formal C++ preserve Win32 resolver/version/process calls, StringBase assign/append/c_str route, and helper boundaries. |
| L6 | Pre-target `0x00464f47-0x00464f50` and post-target `0x00465115-0x00465120` are `0xcc` padding. | incorporate | Target Boundary Context / IDA Evidence | applied | Target Boundary Context and IDA Evidence preserve neighboring padding proof. |
| L7 | `Application+0x18` is cleared and populated from dynamic `IsWow64Process`; recommended field name `m_isWow64`. | incorporate | Target Behavior, Application class fields | applied | Target Behavior/formal C++ and class/file support preserve `m_isWow64`; generated `Application.cpp` lines 163-171 show the field path. |
| L8 | `Application+0x10` is compact OS-code state written by UID0002H5 and read by UID0002JV. | incorporate | Target Behavior, Application class fields, ApplicationOsVersionState | applied | Target/class/file support preserve `m_osCode` / reconstructed `ApplicationOsCode`; UID000293 already preserves global-vs-per-object distinction. |
| L9 | `Application+0x854` is StringBase-style OS label state assigned/appended/returned by UID0002H5. | incorporate | Target Behavior, Application class fields | applied | Target/class/file support and generated `Application.cpp` lines 235-240 preserve `m_osVersionLabel` assignment, suffix append, and `c_str()` return. |
| L10 | Non-WIN32/NT platform writes Windows95 code/label, while NT major >6 preserves prior `m_osCode` and may fall to Unknown. | incorporate | Target Behavior mapping table | applied | Target Behavior mapping and Reconstruction Notes record both corrected cases; formal C++ preserves the branch shape. |
| L11 | Literal refs at `0x006127f8-0x006128e8` provide `IsWow64Process`, `kernel32`, Windows labels, suffixes, and Unknown. | incorporate | Target IDA Evidence; cross-reference UID000483 | applied | Target IDA Evidence records string/data dependencies; file support preserves UID000483 as the literal route. |
| L12 | `sub_4671B0` remains StringBase-owned [UID:000325]; Application is only the suffix-append consumer. | already-present | Target Reconstruction Notes, Cross-References | already-present | Target Reconstruction Notes and class field map already preserved UID000325 helper ownership at same-or-greater detail. |
| L13 | Final `sub_584540` call means source-ready signature should return `const wchar_t *`, not `void`. | incorporate | Target Reconstruction Notes and formal C++ | applied | Target formal C++ emits `const wchar_t *Application::DetectOS()`; generated `Application.cpp` lines 149-150 and 240 confirm signature and return. |
| L14 | Old B002 no-code reason was valid historically but is stale as a first-draft blocker under current code-entry policy. | historicalize | Target Reconstruction Notes; Application file support | applied | Target Reconstruction Notes and Application file support historicalize the stale blocker and keep the spelling caveat. |
| L15 | Exact original enum/member/header spelling is still not proven. | incorporate | Target Score Rationale, Application class/file support | applied | Target Score Rationale and class/file support keep exact original spelling as a confidence/support caveat. |
| L16 | The formal body should use method-local constants instead of a new project-wide enum declaration. | incorporate | Target formal C++ and Reconstruction Notes | applied | Target and generated C++ use method-local `kApplicationOsWindows*` constants; no project-wide enum was added. |
| L17 | Generated Application.cpp/reports are stale and must not be manually edited. | incorporate | Application file support and implementation checklist | applied | Generated output refreshed through validators only; `Application.cpp` header shows command `000000000562`, not manual edit. |
| L18 | No-code / covered-by marker is invalid for UID0002H5 because no other range emits the method body. | reject-invalid | Target Reconstruction Notes | excluded-with-reason | Rejected in target Rejected Alternatives/Reconstruction Notes; generated `Application.cpp` now has real UID0002H5 code and no UID0002H5 empty marker. |
| L19 | Owner transfer to BaramApp, WinMain, StringBase, or UID000293 is invalid. | reject-invalid | Target Rejected Alternatives; Application support docs | excluded-with-reason | Target Rejected Alternatives and support docs reject these owner transfers; UID000293 remained no-edit because it already distinguishes global OS state. |
| L20 | Recommended target score after implementation is `90/92`. | incorporate | Target metadata and Score Rationale | applied | Target metadata is `COMPLETION:90`, `CONFIDENCE:92`; validator `000000000560` confirmed both. |

## Implementation Tracking Checklist

- [x] Acquire short leases only when ready to edit: target [UID:0002H5], support [UID:00000D], support [UID:0000HG], and [UID:000293] only if edited. Proof: B005 leased the target/class/file docs immediately before the validator batch on 2026-06-29; UID000293 was not edited because it already contained same-or-greater detail.
- [x] Update target [UID:0002H5] metadata from `87/90` to `90/92`, preserving owner/emitter/reconstructable routing. Proof: target metadata now `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`; validator `000000000560` ok:1 confirmed updates.
- [x] Insert the exact formal `const wchar_t *Application::DetectOS()` C++ block into UID0002H5. Proof: target formal block contains accepted body; generated `Application.cpp` lines 149-240 show the emitted method.
- [x] Update target Behavior with the corrected non-WIN32/NT and NT-major-greater-than-six branch mapping. Proof: target Behavior mapping includes explicit non-WIN32/NT Windows95 fallback and NT major greater than six prior-code/Unknown behavior.
- [x] Update target IDA Evidence with MCP session `b6b3c97e` proof: health, range, caller, callees, blocks/complexity, bytes, string refs, suffix append, and c_str return. Proof: target IDA Evidence records session `b6b3c97e`, `sub_464F50` size `0x1c5`, 38 blocks/complexity 19, caller `0x00463522`, string/data dependencies, suffix append, and `sub_584540` return.
- [x] Update target Reconstruction Notes to historicalize the old enum/member no-code blocker and reject no-code/covered-by status. Proof: target Reconstruction Notes and Rejected Alternatives historicalize the spelling blocker and reject no-code/covered-by, BaramApp/WinMain/StringBase/UID000293 ownership, and generated manual edits.
- [x] Update target Score Rationale and Changes with report-level proof. Proof: target Score Rationale is `90/92` with current evidence/caveats; 2026-06-29 B005 change entry cites accepted report and MCP proof.
- [x] Update [UID:00000D] Application method list/field notes to mark UID0002H5 as source-ready and preserve `m_osCode`/`ApplicationOsCode` as reconstructed naming. Proof: `by-class/Application.md` method list, field notes, inference map, evidence, and changes record source-ready UID0002H5 and reconstructed `ApplicationOsCode`.
- [x] Update [UID:0000HG] Application file support to remove UID0002H5 from the blocked-lifecycle list and add it to exact source-ready children. Proof: `by-file/Application.md` responsibilities, source-placement audit, broad-C++ blocker paragraph, likely-file contents, and changes record UID0002H5 as exact source-ready `Application::DetectOS()` and no longer a stale enum/member no-code blocker.
- [x] Update [UID:000293] only if necessary, preserving the global-vs-per-object OS state distinction. Proof: no edit needed; `by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md` already states global constructor OS-version state is separate from per-object `m_osCode` / reconstructed `ApplicationOsCode`, `m_isWow64`, and `m_osVersionLabel`.
- [x] Update this report ledger during implementation: change incorporated rows to `applied`, unchanged support facts to `already-present`, stale/no-code rows to `excluded-with-reason`, or any conflict to `blocked`. Proof: ledger rows L1-L20 updated above.
- [x] Update this report checklist during implementation with proof for each target/support edit. Proof: this checklist now records target/class/file/optional support proof, validator IDs, generated proof, execute_report exclusion, and lease release proof.
- [x] Run scoped validators after edits, using queued validator frontend, not direct state edits. Expected minimum: target by-memory file, `by-class/Application.md`, `by-file/Application.md`, and any support file edited. Proof: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-memory\0x00464f50-0x00465115.ApplicationDetectOS.md --apply --queue-timeout 240 --wait-generated` -> command `000000000560`, timestamp `2026-06-29T10:19:50-04:00`, exit `0`, `ok: 1`, generated refresh completed; ran `python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240` -> command `000000000561`, timestamp `2026-06-29T10:20:06-04:00`, exit `0`, `ok: 1`; ran `python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240 --wait-generated` -> command `000000000562`, timestamp `2026-06-29T10:20:12-04:00`, exit `0`, `ok: 1`, generated refresh completed. No UID000293 validator was required because that page was not edited.
- [x] Inspect generated `auto-generated/NexusTK/app/Application.cpp` read-only after validator/generator refresh and verify UID0002H5 no longer has an empty marker and shows the formal method body. Proof: generated header shows `validator-command-id: 000000000562` and `validator-refreshed-at: 2026-06-29T10:20:12-04:00`; UID0002H5 appears at generated lines 149-240 as real `const wchar_t *Application::DetectOS()` code with final `return m_osVersionLabel.c_str();`; no UID0002H5 Empty Emitter Marker is present.
- [x] Do not run `execute_report`. Proof: no `execute_report` command was run; supervisor owns execution/archive.
- [x] Release leases immediately after each edit/validator batch. Proof: `python leaser.py B005 unlease ...ApplicationDetectOS.md ...Application.md ...Application.md` returned `Success` for all three leased files after validators/generated inspection.

## Validator Plan For Callback

Report-only pass ran no validators and made no by-* edits.

Implementation callback validator results:

> Executable block R001 was removed from this report and preserved verbatim in [0002H5-ApplicationDetectOS-empty-emitter-source-quality-removed.md](0002H5-ApplicationDetectOS-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

[UID:000293] was not edited and therefore did not need a scoped validator.

Generated output was inspected read-only:

> Executable block R002 was removed from this report and preserved verbatim in [0002H5-ApplicationDetectOS-empty-emitter-source-quality-removed.md](0002H5-ApplicationDetectOS-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Proof: generated `Application.cpp` header is `validator-command-id: 000000000562`, `validator-refreshed-at: 2026-06-29T10:20:12-04:00`; UID0002H5 appears as real `const wchar_t *Application::DetectOS()` code at generated lines 149-240, and no UID0002H5 Empty Emitter Marker appears.

## Residual Caveats

- Exact original enum/type spelling for `m_osCode` is not proven. This is a below-95 confidence cap, not a first-draft C++ blocker.
- Exact original member spelling for `m_isWow64` and `m_osVersionLabel` is inferred. Current support docs already accept those names as best source-facing reconstruction.
- Exact header exposure for `Application::DetectOS` is not proven. The binary return path supports `const wchar_t *Application::DetectOS()`, and the constructor can legally ignore that return.
- Generated outputs are stale and must be refreshed only by validator/generator flow after supervisor accepts implementation.

## Report-Only Status

Report complete for supervisor validation. No leases were acquired. No by-* docs, generated files, coverage reports, validator/tool state, lock files, or IDA state were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002H5-ApplicationDetectOS-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002H5-ApplicationDetectOS-empty-emitter-source-quality.md","timestamp":"2026-06-29T10:24:02","uid":"0002H5"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002H5-ApplicationDetectOS-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002H5-ApplicationDetectOS-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002H5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
