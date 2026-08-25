** TARGET-REPORT-UID:0002H6 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Research Report: [UID:0002H6] ApplicationValidateLicense

Assignment: `B001-goal2-application-validate-license-source-quality-0002H6-20260617-refresh`  
Target: `by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md`  
Agent: `Agent-B001`  
Date: `2026-06-17`

## Summary Recommendation

`[UID:0002H6] ApplicationValidateLicense` is source-ready. The current target page already has a valid Application class owner and nonblank emitter, and its active combined score clears the code gate: `(82 + 90) / 2 = 86`.

Recommended target metadata:

| Field | Current | Recommended |
|---|---:|---:|
| `COMPLETION` | `82` | `89` |
| `CONFIDENCE` | `90` | `91` |
| `CANONICAL_OWNER` | `00000D` | `00000D` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00000D` | `00000D` |
| C++ block | blank | populate first-draft C++ |

Owner and source-placement recommendation:

- Keep direct semantic owner as `[UID:00000D] by-class/Application.md`.
- Keep emitter as `[UID:00000D]`; the class route correctly emits under `[UID:0000HG] by-file/Application.md` at `NexusTK/app/Application.cpp`.
- No split is required. The memory range is a single Application method from `0x00465430` through alignment before `0x00465650`, with no mixed helper body inside the function.
- The helper dependencies remain separate: executable-path helper `[UID:0002JX]`, standalone executable-version helper `[UID:0002JZ]`, PlatformApi wide VERSION dispatch slots, MemoryMan allocation/free helpers, and CRT integer parser/runtime support are not owned by this method.

## Evidence Checked

I checked the target, support docs, generated output, coverage rows, and direct IDA export evidence available in the second workspace root. Live IDA MCP was unavailable in this session: direct MCP HTTP probing to `127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. Because IDA export files were present, this was not a blocker.

Primary evidence files inspected:

- `by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md`
- `by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md`
- `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md`
- `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md`
- `by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md`
- `by-class/Application.md`
- `by-file/Application.md`
- `by-class/ApplicationLifecycle.md`
- `by-memory/0x00465300-0x0046530d.ApplicationGetVersionMajor.md`
- `by-memory/0x00465310-0x0046531d.ApplicationGetVersionMinor.md`
- `by-memory/0x005a03e0-0x005a0a2f.SendPositionUpdate.md`
- `by-memory/0x004ab800-0x004abb24.ExceptionCrashReportWriter.md`
- `by-file/PlatformApi.md`
- `by-memory/0x0041a300-0x0041a4a1.WideApiDispatchInit.md`
- `by-memory/0x0069bea0-0x0069bee0.WideApiDispatchTable.md`
- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md`
- `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
- `by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md`
- `auto-generated/NexusTK/app/Application.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `by-memory/-coverage-report.md`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`

I also ran `source-3/project-documentation/tools/int_convert.py` for constants and offsets. Relevant checked conversions:

- `0x0136` = `310`
- `0x02a8` = `680`
- `0x0842` = `2114`
- `0x0850` = `2128`
- `0x0104` = `260`
- `0x0010` = `16`
- `0x0014` = `20`
- `752` = `0x02f0`

## Behavior Reconstruction

`ApplicationValidateLicense` does the following:

1. Builds the executable path with `[UID:0002JX] BuildExecutablePathForVersionInfo`.
2. Uses the wide VERSION API dispatch table slots:
   - `GetFileVersionInfoSizeW`
   - `GetFileVersionInfoW`
   - `VerQueryValueW`
3. Queries the version-resource root block with `L"\\"`.
4. Reads `VS_FIXEDFILEINFO`:
   - `dwFileVersionMS` from offset `+0x10`
   - `dwFileVersionLS` from offset `+0x14`
5. Frees the version-info buffer through MemoryMan.
6. Computes a 3-digit version code from the last decimal digits of:
   - `HIWORD(dwFileVersionMS)` as the hundreds digit
   - `LOWORD(dwFileVersionMS)` as the tens digit
   - `HIWORD(dwFileVersionLS)` as the ones digit
7. Formats the embedded key literal `7TK5E-KRU-2K`, extracts only ASCII digits, and parses the resulting string.
8. The extracted digit string is `752`, not `572`.
9. Stores `LOWORD(dwFileVersionLS)` into `Application + 0x842` after a successful version query.
10. If computed code equals parsed key code:
    - writes the computed code to `Application + 0x850`
    - returns the parsed/computed code
11. If computed code does not match:
    - writes `0x02a8` (`680`) to `Application + 0x850`
    - returns `680`
12. If version-size, version-load, root-query, or allocation/exception path fails:
    - writes `0x0136` (`310`) to `Application + 0x850`
    - writes `0` to `Application + 0x842`
    - returns `0`

IDA export evidence from `NexusTK.exe.lst` anchors the main target details:

- `0x00465484`: calls `sub_4651F0`, the executable-path helper.
- `0x00465497`: calls `dword_69BEB0`, the `GetFileVersionInfoSizeW` slot.
- `0x004654CA`: calls `dword_69BEB4`, the `GetFileVersionInfoW` slot.
- `0x004654EC`: calls `dword_69BEB8`, the `VerQueryValueW` slot with `L"\\"`.
- `0x00465507`: reads `dwFileVersionMS`.
- `0x0046550A`: reads `dwFileVersionLS`.
- `0x00465513`: frees the version-info block.
- `0x0046552E`: uses `a7tk5eKru2k`, the `"7TK5E-KRU-2K"` key literal.
- `0x004655AD`: calls the CRT narrow base-10 integer parser at `0x005cea6d`.
- `0x004655BB`: stores `LOWORD(dwFileVersionLS)` to `Application + 0x842`.
- `0x004655C7`: stores the success code to `Application + 0x850`.
- `0x004655D0`: sets mismatch code `0x02a8`.
- `0x004655EA`: sets version-query failure code `0x0136` and clears `+0x842`.

## Heuristic / Inference Reanalysis And Validation

### Application Offset `0x842`

Best defensible source-facing field name:

- `m_clientVersionLowWord`

Acceptable alternate names:

- `m_fileVersionRevision`
- `m_clientVersionMinor`

Rejected alternatives:

- `m_licenseStatus`: rejected because this field receives `LOWORD(dwFileVersionLS)` only after a successful version-resource query and is paired with `+0x850` by display/packet callers as a version component.
- `m_rawFileVersionLS`: rejected because only the low 16 bits are stored.
- `m_buildNumber`: too specific; the binary stores `LOWORD(dwFileVersionLS)`, which is conventionally the revision component when interpreting `VS_FIXEDFILEINFO` as major/minor/build/revision.

Validation:

- Target write: `0x004655BB` stores the low word of `dwFileVersionLS` to `[Application + 0x842]`.
- Failure write: the version-query failure path clears `[Application + 0x842]`.
- Accessor `[UID:0002GQ] ApplicationGetVersionMinor` is exactly `mov ax, [ecx+842h]; retn`.
- MainMenu paint callers format this value with the `+0x850` accessor as `V%d.%d`.
- Socket packet caller pairs this value with the `+0x850` accessor.

Recommendation:

- Keep the existing by-memory filename `ApplicationGetVersionMinor.md` unless the supervisor is doing a broader rename pass. The current accessor name is caller-compatible because consumers display/transmit it as the second version field.
- Update its semantic note to state that `+0x842` is the executable file-version low word / second client version component, not an independently computed license value.

### Application Offset `0x850`

Best defensible source-facing field name:

- `m_clientVersionCode`

Acceptable alternate names:

- `m_validatedVersionCode`
- `m_clientVersionStatus`
- `m_clientVersionMajor`

Rejected alternatives:

- `m_fileVersionMajor`: rejected because the target does not store `HIWORD(dwFileVersionMS)` directly. It stores a 3-digit computed code on success and error/status constants on failure.
- `m_licenseStatusOnly`: rejected because many consumers treat the value as the first version component, and on success it is a computed version code rather than a boolean/status.
- `m_licenseKey`: rejected because the stored value is the computed/validated numeric code or error constant, not the literal key or parsed digit string as a persistent key field.

Validation:

- Accessor `[UID:0002GP] ApplicationGetVersionMajor` is exactly `mov ax, [ecx+850h]; retn`.
- Target success path writes computed code to `+0x850`.
- Target version-query failure path writes `0x0136` (`310`) to `+0x850`.
- Target mismatch path writes `0x02a8` (`680`) to `+0x850`.
- Crash-report code reads this value and prints it as the first component in `"%d.%d.Eng.R\n"`.
- MainMenu paint code reads this value and formats it as the first component in `V%d.%d`.
- Packet code reads this value as the first protocol component, with an optional decrement branch under a configuration condition.

Recommendation:

- Keep the by-memory filename `ApplicationGetVersionMajor.md` for now because it matches display/protocol usage and avoids a churn-heavy rename.
- In C++ and field documentation, model the field as `m_clientVersionCode`, not a raw version-major field.

### Version / License Status Constants

Validated constants:

- `0x0136` = `310`: version-info unavailable or failure path. This includes size/load/root-query failure and the allocation exception handler path.
- `0x02a8` = `680`: version code/key mismatch path.

Rejected alternatives:

- Treating `310` as a normal version success code is rejected. The target returns `0` on this path and clears `+0x842`, so it is an error/status value, not a validated version pair.
- Treating `680` as the embedded key result is rejected. The embedded key digit string is `752`, and `680` is only written after the computed executable version code fails the key comparison.

### Embedded Key And Version-Code Semantics

The old target page claim that the key extraction yields `572` is incorrect. The literal is:

```text
7TK5E-KRU-2K
```

The digit-filter loop scans left to right and copies ASCII digits only. The extracted digit string is:

```text
752
```

The parsed expected code is therefore `752` (`0x02f0`). This is the strongest correction required for the target page.

The computed executable version code is:

```cpp
(HIWORD(dwFileVersionMS) % 10) * 100
    + (LOWORD(dwFileVersionMS) % 10) * 10
    + (HIWORD(dwFileVersionLS) % 10)
```

The low word of `dwFileVersionLS` is stored separately in `Application + 0x842` and is not part of the 3-digit key comparison.

### VERSION API Helper / Source Names

The current raw `dword_69BEB0/B4/B8` names should not be carried forward in source-facing docs. They are PlatformApi wide-dispatch-table slots installed by `[UID:0000WD] WideApiDispatchInit`.

Recommended source-facing names:

- `g_pfnGetFileVersionInfoSizeW` for `dword_69BEB0`
- `g_pfnGetFileVersionInfoW` for `dword_69BEB4`
- `g_pfnVerQueryValueW` for `dword_69BEB8`

Acceptable alternate style if the project prefers a table object:

- `g_wideApiDispatch.GetFileVersionInfoSizeW`
- `g_wideApiDispatch.GetFileVersionInfoW`
- `g_wideApiDispatch.VerQueryValueW`

Rejected alternatives:

- Direct Win32 imports in the target method: rejected as a precise reconstruction because the binary calls through the dispatch table slots, not direct imports from this function.
- Leaving the raw IDA names in final source docs: rejected because the names are now resolvable from `WideApiDispatchInit` and `WideApiDispatchTable`.

### Parser / Allocator / Helper Ownership Boundaries

Parser:

- The parser at `0x005cea6d` is CRT/runtime support under `[UID:00024C] MsvcAcrtStdioLocaleMathSupport`.
- The target uses a narrow base-10 integer parse after digit extraction.
- Source can use `atoi`, `strtoul`, or an existing project wrapper if one is selected elsewhere. It should not create a new Application-owned parser helper for this target.

Allocator:

- Allocation and free are owned by MemoryMan:
  - `[UID:0001BD] AllocateBufferMemory`
  - `[UID:0001BF] FreeBufferMemory`
- The target catches the allocation/Win32Error path and falls through to the version-query failure status.
- Final source should call the MemoryMan helpers or the local MemoryMan wrapper selected by the project; it should not inline allocator internals into `ApplicationValidateLicense`.

Executable path helper:

- `[UID:0002JX] BuildExecutablePathForVersionInfo` is a shared executable-path helper near the Application lifecycle cluster.
- It is not an Application instance method because it has cross-module/helper-style callers and no `this` dependency.
- It should remain owned/emitted through `[UID:0000YR] ApplicationLifecycle`.

Standalone executable version helper:

- `[UID:0002JZ] GetExecutableVersionLowWord` is a separate file-local helper used by crash-report writing.
- It should remain separate from `ApplicationValidateLicense`; the target duplicates the VERSION query work but stores Application fields and performs key validation, while `[UID:0002JZ]` simply returns the low word or zero.

### Source Placement Under Application

The target should stay under Application class/file reconstruction:

- It is directly called by `[UID:0002H0] ApplicationInitialize` at `0x00463ABC`.
- It mutates Application instance offsets `+0x842` and `+0x850`.
- Its direct accessor consumers are Application methods/accessors.
- Its literals are in `[UID:00024T] ApplicationStartupReadOnlyData`.
- `by-file/Application.md` already lists version/license validation as an Application responsibility.
- `auto-generated/-ag-memory-coverage.md` already routes `[UID:0002H6]` to `auto-generated/NexusTK/app/Application.cpp`.

Rejected placements:

- `platform/PlatformApi.cpp`: rejected because PlatformApi only owns the API dispatch table, not the Application validation logic.
- `MemoryMan.cpp`: rejected because allocator helpers are dependencies only.
- Diagnostics/crash-report module: rejected because diagnostics consumes version values but does not own Application field initialization.
- Runtime/CRT support: rejected because only the integer parse helper belongs there.

### First-Draft C++ Readiness

The target is first-draft C++ ready.

Reasons:

- Exact function bounds are known.
- Control flow is straightforward and single-purpose.
- All external helpers have documented ownership.
- The emitter route is valid and nonblank.
- Current combined score already clears the active code gate.
- The remaining uncertainty is source-facing naming style, not behavior or placement.

Remaining caveats that justify `89/91` rather than a 95+ score:

- Exact original member names for `+0x842` and `+0x850` are not recovered.
- Exact final PlatformApi dispatch-table naming style is project-level, though the slot meanings are known.
- Live IDA MCP was unavailable in this session; direct IDA export evidence substituted successfully.

## Companion Helper Recheck

### [UID:0002JX] BuildExecutablePathForVersionInfo

Current header recommendation remains valid:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000YR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000YR`

Behavior confirmed:

- Copies `GetCommandLineW()` into a `0x104`-wide-character path buffer.
- If the command line begins with a quote, it terminates at the closing quote.
- If unquoted, it terminates at the first space.
- Removes quotes by shifting the path string.
- Checks the last four wide characters against `.exe`.
- Appends `.exe` if missing.

This helper is correctly modeled as a shared file-local Application lifecycle helper, not as a method on `Application`.

### [UID:0002JZ] GetExecutableVersionLowWord

Current header recommendation remains valid:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000YR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000YR`

Behavior confirmed:

- Calls `[UID:0002JX]`.
- Uses the same PlatformApi VERSION dispatch slots as the target.
- Allocates through MemoryMan.
- Queries root `L"\\"`.
- Reads `dwFileVersionLS` at `VS_FIXEDFILEINFO + 0x14`.
- Returns the low 16 bits because the function return type is 16-bit.
- Returns `0` on failure.
- Direct known caller is crash-report writing at `0x004ab8f4`.

Recommended doc cleanup:

- Replace raw `dword_69BEB0/B4/B8` wording with the PlatformApi dispatch slot names listed above.

### [UID:00024T] ApplicationStartupReadOnlyData

Relevant data remains correctly placed under the Application file:

- `0x0061260c`: wide root query literal `L"\\"`
- `0x00612e54`: wide `.exe`
- `0x00612e60`: ASCII `7TK5E-KRU-2K`

This supports keeping the target and helpers in the Application/application-lifecycle source area.

### [UID:0002H0] ApplicationInitialize Caller

Direct IDA export evidence confirms `ApplicationInitialize` calls the target at `0x00463ABC`. The call occurs during startup after key-speed setup and before later display/patch-continuation configuration. This is strong owner evidence for Application, not a general platform or diagnostics owner.

### Generated Output And Coverage

`auto-generated/NexusTK/app/Application.cpp` currently contains only `Application::CopyWorldName` and `Application::CopyPlayerName`; the target is not emitted as C++ despite having a valid emitter route. This supports the assignment's concern: the target is reconstructable and code-gate eligible but still has a blank C++ block.

`auto-generated/-ag-memory-coverage.md` already routes:

- `[UID:0002JX]` to `auto-generated/NexusTK/app/Application.cpp`
- `[UID:0002GP]` to `auto-generated/NexusTK/app/Application.cpp`
- `[UID:0002GQ]` to `auto-generated/NexusTK/app/Application.cpp`
- `[UID:0002JZ]` to `auto-generated/NexusTK/app/Application.cpp`
- `[UID:0002H6]` to `auto-generated/NexusTK/app/Application.cpp`

The route is valid. The missing part is target C++ text and updated source-facing naming notes.

## Consumer Interaction Research

### Crash Report Writer

`[UID:00014G] ExceptionCrashReportWriter` reads:

- `Application + 0x850` through `[UID:0002GP]`
- the standalone executable version low word through `[UID:0002JZ]`

It formats a version line like `"%d.%d.Eng.R\n"`. This supports the interpretation that `+0x850` is the first client version/status component. The crash-report path deliberately asks the executable helper for the second component rather than reading `+0x842`, so the target field and standalone helper are related but not identical ownership surfaces.

### MainMenu Version Display

MainMenu paint code reads:

- `[UID:0002GP]` for `Application + 0x850`
- `[UID:0002GQ]` for `Application + 0x842`

It formats those values as `V%d.%d` in both EPF and EPD paths. This validates the current historical `GetVersionMajor` / `GetVersionMinor` accessor names as caller-compatible, even though the underlying `+0x850` field should be documented as a computed client version code/status rather than a raw file-version major.

### Socket Packet Support Doc

`[UID:0001HW] SendPositionUpdate` currently has a stale or misleading interpretation in its packet table. IDA export decompilation shows it reads `[UID:0002GP]` and `[UID:0002GQ]`, not player-coordinate helpers. The existing support doc should be corrected separately because it currently labels the fields as Player X/Y coordinates while also naming Application accessors.

Recommended exact doc change for `by-memory/0x005a03e0-0x005a0a2f.SendPositionUpdate.md`:

Replace packet-layout rows that describe offsets `1..2` and `4..5` as Player X/Y coordinates with:

```markdown
| 1..2 | `uint16` | Application client version code / validated first version component from `[UID:0002GP] ApplicationGetVersionMajor`; under the guarded config branch this value may be decremented by one before serialization. |
| 4..5 | `uint16` | Application client version low word / second version component from `[UID:0002GQ] ApplicationGetVersionMinor`. |
```

Also replace any sentence stating that the Application accessors return player coordinates with:

```markdown
The two Application accessors used in this packet read version/status fields initialized by `[UID:0002H6] ApplicationValidateLicense`, not player position coordinates.
```

This correction is support-doc cleanup and does not change target ownership.

## First-Draft C++ Recommendation

The supervisor should replace the blank C++ block in `by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md` with a first-draft implementation shaped like this. Names are source-facing recommendations; if the PlatformApi table has an adopted table-object style, substitute those names without changing behavior.

```cpp
int Application::ValidateLicense()
{
    const WORD kVersionInfoFailureCode = 0x0136;
    const WORD kVersionCodeMismatch = 0x02a8;

    wchar_t executablePath[0x104];
    DWORD versionHandle = 0;
    UINT fixedInfoLength = 0;
    VS_FIXEDFILEINFO *fixedInfo = NULL;
    void *versionInfo = NULL;

    BuildExecutablePathForVersionInfo(executablePath);

    const DWORD versionInfoSize =
        g_pfnGetFileVersionInfoSizeW(executablePath, &versionHandle);
    if (versionInfoSize == 0) {
        m_clientVersionCode = kVersionInfoFailureCode;
        m_clientVersionLowWord = 0;
        return 0;
    }

    try {
        versionInfo = AllocateBufferMemory(versionInfoSize);
    } catch (Win32Error *error) {
        delete error;
        m_clientVersionCode = kVersionInfoFailureCode;
        m_clientVersionLowWord = 0;
        return 0;
    }

    if (!g_pfnGetFileVersionInfoW(executablePath, 0, versionInfoSize, versionInfo) ||
        !g_pfnVerQueryValueW(versionInfo, L"\\",
                             reinterpret_cast<void **>(&fixedInfo),
                             &fixedInfoLength)) {
        FreeBufferMemory(versionInfo);
        m_clientVersionCode = kVersionInfoFailureCode;
        m_clientVersionLowWord = 0;
        return 0;
    }

    const WORD fileMajor = HIWORD(fixedInfo->dwFileVersionMS);
    const WORD fileMinor = LOWORD(fixedInfo->dwFileVersionMS);
    const WORD fileBuild = HIWORD(fixedInfo->dwFileVersionLS);
    const WORD fileRevision = LOWORD(fixedInfo->dwFileVersionLS);

    FreeBufferMemory(versionInfo);

    const WORD computedCode = static_cast<WORD>(
        (fileMajor % 10) * 100 +
        (fileMinor % 10) * 10 +
        (fileBuild % 10));

    char keyText[0x100];
    sprintf_s(keyText, _countof(keyText), "%s", "7TK5E-KRU-2K");

    char digits[0x100];
    char *digitOut = digits;
    for (const char *cursor = keyText; *cursor != '\0'; ++cursor) {
        if (*cursor >= '0' && *cursor <= '9') {
            *digitOut++ = *cursor;
        }
    }
    *digitOut = '\0';

    const int expectedCode = atoi(digits);
    m_clientVersionLowWord = fileRevision;

    if (computedCode == expectedCode) {
        m_clientVersionCode = computedCode;
        return expectedCode;
    }

    m_clientVersionCode = kVersionCodeMismatch;
    return kVersionCodeMismatch;
}
```

Notes for supervisor application:

- If the project has already adopted a wrapper around the wide dispatch table, use that wrapper instead of the `g_pfn...` names.
- The helper `[UID:0002JX]` is shown with its binary-shaped single output-buffer argument. If the supervisor creates a safer source wrapper that also takes a count, substitute that wrapper consistently.
- If the MemoryMan allocator wrapper returns a typed buffer or RAII owner, the cleanup may be expressed with that wrapper, but the binary behavior frees the version-info block before key parsing.
- `Win32Error *` pointer deletion is modeled because the IDA export catch path deletes the thrown object before setting the failure fields.
- Do not insert helper implementations into this target block.

## Recommended By-* Doc Changes

Do not edit these by-* docs as part of this B-agent assignment; the following is exact guidance for supervisor execution.

### Target: `by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md`

Recommended header changes:

```yaml
COMPLETION: 89
CONFIDENCE: 91
CANONICAL_OWNER: 00000D
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 00000D
```

Recommended behavior text replacement:

Replace the stale key-extraction claim that the embedded key produces `572` with:

```markdown
The method formats the embedded ASCII key literal `"7TK5E-KRU-2K"`, copies only ASCII digits in left-to-right order, and parses the resulting digit string `"752"` as a base-10 integer. The extracted key code is therefore `752` (`0x02f0`), not `572`.
```

Add this field-semantics paragraph near the field write discussion:

```markdown
`Application + 0x842` is best modeled as `m_clientVersionLowWord`: it receives `LOWORD(VS_FIXEDFILEINFO.dwFileVersionLS)` after a successful version query and is cleared to zero on version-query failure. `Application + 0x850` is best modeled as `m_clientVersionCode`: it receives the computed 3-digit version code on success, `0x0136` (`310`) on version-query/allocation failure, or `0x02a8` (`680`) on key/version-code mismatch. Existing `GetVersionMajor` / `GetVersionMinor` accessor names are caller-compatible display/protocol names, but `+0x850` is not a raw file-version major field.
```

Replace the current C++ blocker note with:

```markdown
First-draft C++ is now recommended. Behavior, helper ownership, status constants, key semantics, and source placement are resolved to high confidence. Remaining uncertainty is limited to final project naming style for the Application fields and PlatformApi dispatch-table slots.
```

### Target: `by-class/Application.md`

Recommended replacement for offset notes:

```markdown
- `+0x842` is the client version low word / second displayed-transmitted version component. `[UID:0002H6] ApplicationValidateLicense` writes `LOWORD(VS_FIXEDFILEINFO.dwFileVersionLS)` here after a successful version query and clears it on version-query failure.
- `+0x850` is the client version code / first displayed-transmitted version component. `[UID:0002H6]` writes the computed 3-digit validation code here on success, `0x0136` (`310`) on version-query/allocation failure, or `0x02a8` (`680`) on key/version-code mismatch.
```

Recommended accessor note:

```markdown
The historical names `ApplicationGetVersionMajor` and `ApplicationGetVersionMinor` remain caller-compatible because UI, crash-report, and packet code consume the values as a version pair. They should not be interpreted as direct raw `VS_FIXEDFILEINFO` major/minor accessors.
```

### Target: `by-file/Application.md`

Recommended responsibility/source-placement addition:

```markdown
`ApplicationValidateLicense` is source-ready in `NexusTK/app/Application.cpp`. It owns Application field initialization for the client version code/status pair, while executable-path construction, wide VERSION API dispatch, MemoryMan allocation/free, and CRT integer parsing remain separate helper dependencies.
```

### Target: `by-class/ApplicationLifecycle.md`

Recommended reconstruction-note replacement:

```markdown
The previous open naming issue around the Application version accessors is resolved to source-ready field semantics for `[UID:0002H6]`: `+0x850` is the client version code / first version-status component and `+0x842` is the client version low word / second version component. Helper `[UID:0002JX]` remains a shared executable-path builder and helper `[UID:0002JZ]` remains a standalone executable low-word reader.
```

### Target: `by-memory/0x00465300-0x0046530d.ApplicationGetVersionMajor.md`

Recommended behavior replacement:

```markdown
Returns the 16-bit value at `Application + 0x850`. This field is best modeled as `m_clientVersionCode`: `[UID:0002H6] ApplicationValidateLicense` writes the computed 3-digit code on success, `0x0136` (`310`) on version-query/allocation failure, or `0x02a8` (`680`) on key/version-code mismatch. Consumers display or transmit it as the first client version/status component, so the historical `GetVersionMajor` name remains caller-compatible but does not mean raw `VS_FIXEDFILEINFO.dwFileVersionMS` major.
```

### Target: `by-memory/0x00465310-0x0046531d.ApplicationGetVersionMinor.md`

Recommended behavior replacement:

```markdown
Returns the 16-bit value at `Application + 0x842`. This field is best modeled as `m_clientVersionLowWord`: `[UID:0002H6] ApplicationValidateLicense` writes `LOWORD(VS_FIXEDFILEINFO.dwFileVersionLS)` after a successful version query and clears it to zero on version-query failure. Consumers display or transmit it as the second client version component.
```

### Target: `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md`

Recommended helper-name replacement:

```markdown
The raw dispatch-table slots `dword_69BEB0`, `dword_69BEB4`, and `dword_69BEB8` correspond to the PlatformApi wide VERSION API slots `GetFileVersionInfoSizeW`, `GetFileVersionInfoW`, and `VerQueryValueW`, installed by `[UID:0000WD] WideApiDispatchInit`. Source-facing code should use the project-selected dispatch names rather than raw IDA data labels.
```

## Exact Coverage Row Replacement Text

`by-memory/-coverage-report.md` is supervisor-owned and was not edited. Replace the existing stale rows for the Application version helper cluster with the following text in the same location under the Application/ApplicationLifecycle section.

```markdown
        - [UID:0002JX](0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md) | 0x004651f0-0x004652dc | file-local helper function | BuildExecutablePathForVersionInfo : reconstructable : 86% : strong : Exact shared executable-path helper now attached through [UID:0000YR](../by-class/ApplicationLifecycle.md); IDA export/disassembly and prior MCP evidence confirm `GetCommandLineW`, quote/space command-line parsing, quote stripping, `.exe` suffix test/append, full caller set across Application validation, executable-version helper, diagnostics, ImageHlp, and MainMenu paths; final C++ remains blank pending shared static-helper declaration style.
        - [UID:0002GP](0x00465300-0x0046530d.ApplicationGetVersionMajor.md) | 0x00465300-0x0046530d | member function | ApplicationGetVersionMajor : reconstructable : 85% : strong : Exact 16-bit accessor for `Application + 0x850`, best described as client version code / validated first version component: `[UID:0002H6]` writes the computed 3-digit code on success, `0x0136`/310 on version-query failure, or `0x02a8`/680 on key/version mismatch, while crash-report, main-menu, packet, and user-look consumers read it as the first version/status field; retain `GetVersionMajor` as historical/caller-compatible name but do not model the field as raw `VS_FIXEDFILEINFO` major.
        - [UID:0002GQ](0x00465310-0x0046531d.ApplicationGetVersionMinor.md) | 0x00465310-0x0046531d | member function | ApplicationGetVersionMinor : reconstructable : 85% : strong : Exact 16-bit accessor for `Application + 0x842`, best described as client version low word / second displayed-transmitted version component; `[UID:0002H6]` writes `LOWORD(VS_FIXEDFILEINFO.dwFileVersionLS)` on successful query and zero on version-query failure, and MainMenu/packet callers pair it with `[UID:0002GP]`.
        - [UID:0002JZ](0x00465320-0x00465424.GetExecutableVersionLowWord.md) | 0x00465320-0x00465424 | file-local helper function | GetExecutableVersionLowWord : reconstructable : 86% : strong : Exact file-local executable version low-word reader attached through [UID:0000YR](../by-class/ApplicationLifecycle.md); IDA export/disassembly and prior MCP evidence confirm path helper dependency, PlatformApi/WideApiDispatchTable VERSION slots (`GetFileVersionInfoSizeW`, `GetFileVersionInfoW`, `VerQueryValueW`), MemoryMan allocation/free, root `L"\\"` query, `dwFileVersionLS` offset `+0x14`, low-word return, sole crash-report caller, and failure return 0; final C++ remains blank pending shared helper declaration style.
        - [UID:0002H6](0x00465430-0x0046564c.ApplicationValidateLicense.md) | 0x00465430-0x0046564c | member function | ApplicationValidateLicense : reconstructable : 89% : strong : Exact Application method now source-ready: validates the executable VERSION root against key literal `7TK5E-KRU-2K`, extracts digits `752`, computes the version code from last digits of file major/minor/build, writes `Application + 0x842` with `LOWORD(dwFileVersionLS)`, writes `Application + 0x850` with the success code or status constants `0x0136`/310 and `0x02a8`/680, has a valid Application class emitter route, and should receive first-draft C++ from the B001 report.
```

## Validation / Non-Edits

Files created by this assignment:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002H6-ApplicationValidateLicense-source-quality-refresh.md`

Files intentionally not edited:

- `by-memory/-coverage-report.md`
- all `by-memory`, `by-class`, `by-file`, `project-level`, and `auto-generated` documentation targets

No project validator was run because this is a report-only B-agent assignment and no by-* or generated files were modified. The report content was validated by direct inspection of target/support docs, generated coverage, IDA export `.lst/.c/.map` evidence, and `int_convert.py` conversions.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002H6-ApplicationValidateLicense-source-quality-refresh.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002H6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
