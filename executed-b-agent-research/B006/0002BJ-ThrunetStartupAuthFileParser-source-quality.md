** TARGET-REPORT-UID:0002BJ **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BJ ThrunetStartupAuthFileParser Source-Quality Report

Agent: B006  
Mode: report-only research  
Target: [UID:0002BJ] `by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md`  
Date: 2026-06-26  
Required report path: `tools/leaser/Agents/Agent-B006/research/0002BJ-ThrunetStartupAuthFileParser-source-quality.md`

## Final Recommendation

Update [UID:0002BJ] from `COMPLETION:85`, `CONFIDENCE:89` to:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `0000N4` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000N4` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Source-facing helper name | `static void ParseThrunetStartupAuthenticationFile(RegistryConfig *config)` |

Reason: current MCP evidence resolves the previous source-quality blockers for field naming, COM helper role, `_wfopen` dispatch route, BSTR conversion helpers, and first-draft C++ readiness. The function should stay file-level/config-adjacent under [UID:0000N4] `RegistryConfig`; no direct caller, selector, vtable, or stored pointer route proves a `RegistryConfig::` method.

Completion should stop at `88`, not higher, because the dispatcher/caller route remains unrecovered, the original COM interface/method spelling is inferred from `thrunet.clsURLCHK` and vtable slot behavior, and the localized failure strings are better documented by address/role than by exact source text. Confidence can rise to `90` because the behavior, boundary, state writes, helper roles, and owner route are now independently supported by current IDA MCP and live by-* support pages.

## Current Target State

Live target metadata rechecked from `by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md`:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000N4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`
- `RECONSTRUCTION_CPP CODE` is blank
- Item summary currently identifies IDA-modeled `sub_48FCA0`, file-backed Thrunet launcher/auth parsing, COM validation, and cleanup chunks.

The generated research tracker row still shows an older `78/88` score while listing the target in the not-covered reconstructable queue. Treat the live by-memory page as authoritative for this report. Do not hand-edit generated tracker output; it should refresh through validator/executed-report workflow after accepted implementation.

## MCP And Local Evidence Checked

MCP was mandatory and was available for this report. Current server check:

- Direct MCP `initialize` returned server `ida-pro-mcp` v1.0.0.
- `idb_list` returned active session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, owned/adopted, worker PID `26892`, not analyzing.
- `server_health` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.

Target MCP evidence already gathered and preserved for this report:

- `lookup_funcs 0x0048fca0` reports `sub_48FCA0`, address `0x48fca0`, size `0x550` (`1360` decimal).
- `lookup_funcs` for `0x004901f0`, `0x0048fc90`, and `0x00490200` returns no modeled function at those addresses.
- `analyze_function 0x0048fca0` reports prototype `LPVOID __thiscall(char *this)`, size `0x550`, 70 basic blocks, cyclomatic complexity 20, no callers, and strings `"%s"` and `"thrunet.clsURLCHK"`.
- `callees 0x0048fca0` includes `GetCommandLineW`, `_wcscpy_s`, `_wcschr`, `_fgetc`, `_wtol`-style wide integer conversion, `sub_516220`, `WideCharToMultiByte`, `gethostbyname`, `_memset`, `sub_4944C0`, `_fclose`, `CoInitialize`, `sub_4941E0`, `sub_494440`, `sub_5C8DD0`, `sub_5C8CB0`, `__strdup`, `_strcpy_s`, `MessageBoxW`, `PostQuitMessage`, and COM/runtime error helpers.
- `xrefs_to 0x0048fca0` returns zero cross-references. Raw little-endian VA/RVA byte scans for `0x0048fca0` also returned zero matches. This blocks a dispatcher/caller proof but not owner/source placement.
- Full target decompile shows command-line tail extraction, `_wfopen` dispatch-slot file open with mode `"ro"`, file line parsing, dotted-IP or DNS hostname handling, port parsing, COM initialization, ProgID creation for `"thrunet.clsURLCHK"`, COM vtable slot `+0x1c`, result conversion, token copy, ready/mode writes, and failure UI paths.
- Target disassembly confirms the important call/write anchors: `_wfopen` slot call at `0x0048fd7f`, MemoryMan memmove wrapper calls at `0x0048feaa` and `0x0048ff2b`, `CoInitialize`/COM creation at `0x0048ffcb-0x0048ffdd`, COM vtable call at `0x00490079`, result `__strdup` at `0x004900ef`, rejection test for leading `'*'` at `0x004900f7`, token `strcpy_s` at `0x00490127`, ready write at `0x0049012f`, mode write at `0x0049013e`, and COM release at `0x0049015e`.
- `get_bytes` confirms `0x004901f0-0x00490200` is sixteen `0xcc` bytes before the next sibling, and `0x0048fc96-0x0048fca0` is ten `0xcc` bytes before this target.
- Disassembly confirms IDA-attached cleanup chunks at `0x00493f00-0x00493f0d` and `0x005fccc2-0x005fcd3a`. They are compiler cleanup/unwind chunks, not source-body range expansion.
- `get_string 0x006113b8` returns `"ro"` and `get_string 0x00616e60` returns `"thrunet.clsURLCHK"`.
- `xrefs_to` confirms target-specific literal/message anchors: `0x00616dd0` from `0x004901a6`, `0x00616e08` from `0x0049018e`, `0x00616e60` from `0x0048ffcb`, `0x00616e74` from `0x0048fff7`, and `0x00616ea4` from `0x0049010d`.
- `xrefs_to 0x0069be14` shows the target read at `0x0048fd7f` and the dispatch-table initializer write at `0x0041a42e`, confirming a PlatformApi `_wfopen` dispatch slot rather than a local unknown global or direct import.

Additional helper MCP evidence collected for this pass:

- `decompile 0x004941e0` confirms `sub_4941E0` converts an ANSI ProgID/CLSID string to wide text, calls `CLSIDFromString` or `CLSIDFromProgID`, creates COM objects with `CoCreateInstance`, uses `OleRun` when `dwClsContext & 0x14`, queries interface `stru_616DC0`, and returns `HRESULT`. This supports source-facing `CreateComObjectFromProgId`.
- `decompile 0x004944c0` confirms `sub_4944C0` is a varargs narrow CRT scan/format wrapper; in this target it represents the `fscanf(file, "%s", authRequest)` read, not a NexusTK semantic helper.
- `decompile 0x005c8dd0` confirms `sub_5C8DD0` is ANSI string to `BSTR` conversion via `MultiByteToWideChar` and `SysAllocString`. This supports `_bstr_t` or `_com_util::ConvertStringToBSTR` source spelling.
- `decompile 0x005c8cb0` confirms `sub_5C8CB0` is wide/BSTR to ANSI conversion via `WideCharToMultiByte` and heap allocation. This supports `_bstr_t` ANSI conversion or `_com_util::ConvertBSTRToString` source spelling.

Local docs and leads checked:

- Current target page, parent [UID:000220] `RegistryCommandLineParsers`, [UID:0000N4] `by-file/RegistryConfig.md`, [UID:0000BW] `by-class/RegistryConfig.md`, [UID:000221] `MsvcComAndFormattingHelpers`, `RegistryConfigChannelStartupStringData`, `WideApiDispatchTable`, and `WideApiDispatchPointerTable`.
- Accepted nearby incorporated work for [UID:0002BI] Netsgo and [UID:0002BN] COM-backed Excite Game parser was used only as a lead and style precedent; target claims here were revalidated against current MCP where they determine 0002BJ's score/C++ readiness.
- `tools/int_convert.py` checked `0x550=1360`, `0x100=256`, `0x400=1024`, `0x40=64`, `0x0a=10`, `0x17=23`, `0x2915b4=2692532`, `0x2915c4=2692548`, `0x2916c4=2692804`, `0x2916ca=2692810`, `0x28d9e0=2677216`, and `0x28de28=2678312`.

## Behavior Reconstruction

`sub_48FCA0` is the Thrunet file-backed launcher authentication parser in the RegistryConfig startup parser island.

High-level flow:

1. Save `this` as the config/startup-state pointer and fetch `MemoryMan::GetMemoryMan()` for wrapper copies.
2. Copy `GetCommandLineW()` into a 1024-wide-character local buffer and skip the executable token using quote-aware or space-delimited logic.
3. Copy the remaining command-line tail into a 128-wide-character auth-file path buffer with the binary's `0x100` byte limit.
4. Open that path through PlatformApi dispatch slot `0x0069be14`, source-facing `g_pfnWideOpenFile` / `_wfopen`, with mode string `L"ro"`.
5. Read the first file line byte-by-byte with `_fgetc` into a wide-character local buffer until LF (`0x0a`).
6. If the first character is numeric, parse four dotted-IP components with the `_wtol`-style helper and store the bytes at `config + 0x2915b4`.
7. If the first character is not numeric, copy the host name portion up to the first space into `config + 0x2915c4`, convert it to ANSI with `WideCharToMultiByte(CP_ACP, ...)`, resolve it with `gethostbyname`, and copy four resolved address bytes to `config + 0x2915b4`.
8. Read the second file line, convert it with the `_wtol`-style helper, and store the full dword at `config + 0x2916c4`; for this target this offset is `m_startupPort`, not the [UID:0002BN] COM token overlay.
9. Clear a 256-byte narrow buffer, read the next token with `sub_4944C0(file, "%s", buffer)`, then close the file.
10. Call `CoInitialize(0)`, create/query the COM object from ProgID `"thrunet.clsURLCHK"` through `sub_4941E0(&ppv, ..., 0, 0x17)`, and fail through the localized message/quit path if creation fails.
11. Convert the file token to a `BSTR`, call COM vtable slot `+0x1c` with the request BSTR and a BSTR out parameter, raise a COM error via runtime helper on failure, convert the returned BSTR to ANSI, and duplicate/cache the result.
12. If the returned text starts with `'*'`, take the authentication-rejected message path.
13. Otherwise copy the token text into `config + 0x28d9e0` with `strcpy_s(..., 0x40, ...)`, write `1` to `config + 0x2916ca`, write `5` to `config + 0x28de28`, release the COM pointer, and return.

Failure behavior is user-visible. Do not collapse file-open, DNS, COM-create, or rejected-token paths into silent returns. The exact localized Korean text should be documented by address/role unless a separate text-localization pass decodes and validates the strings.

## Field And Helper Naming Recommendations

Use these source-facing names in the target/support docs. Names marked inferred are source-quality names based on behavior and sibling parser style, not original-symbol proof.

| Offset/helper | Recommended source-facing name | Evidence and scope |
| --- | --- | --- |
| Function | `ParseThrunetStartupAuthenticationFile(RegistryConfig *config)` | Inferred from Thrunet ProgID, file-backed parser shape, and RegistryConfig parser-island ownership. Keep file-static unless a caller/selector proves method status. |
| `config + 0x2915b4` | `m_startupAddress[4]` / `m_startupIpAddress[4]` | Same startup IPv4 byte field used by sibling parsers; dotted-IP and DNS paths write here. |
| `config + 0x2915c4` | `m_startupHostName[128]` | Nonnumeric host branch stores a wide hostname; the `0x100` byte gap to `+0x2916c4` matches 128 UTF-16 characters. |
| `config + 0x2916c4` | `m_startupPort` | This target stores the parsed file port here. Preserve the support-doc caveat that [UID:0002BN] uses the same offset as a mode-specific COM token/context overlay. |
| `config + 0x2916ca` | `m_startupReady` | Success path writes word `1`; sibling docs already reject argument-count naming. |
| `config + 0x28de28` | `m_startupConnectionMode` | Success path writes byte `5`. |
| `config + 0x28d9e0` | `m_thrunetAuthenticationToken[64]` | This target copies the validated returned token string here with `_strcpy_s` size `0x40`; [UID:0002BN] uses this region differently as COM holder/scratch. |
| `0x0069be14` | `g_pfnWideOpenFile` / `_wfopen` dispatch slot | The target reads this PlatformApi slot and passes file path plus mode `"ro"`. |
| `sub_516220` calls | `MemoryMan::MemmoveWrapper` | Calls use the MemoryMan owner pointer and copy hostname/resolved IPv4 bytes; do not emit raw `sub_516220`. |
| `0x004941e0` | `CreateComObjectFromProgId` / MSVC COM helper | Decompile proves ProgID/CLSID conversion, `CoCreateInstance`, `OleRun`, QueryInterface, and `HRESULT` behavior. |
| `0x004944c0` | CRT `fscanf`/scan wrapper | Used for the narrow `"%s"` file token. |
| `0x005c8dd0` | `_com_util::ConvertStringToBSTR` / `_bstr_t` construction | Converts ANSI auth request text to `BSTR`. |
| `0x005c8cb0` | `_com_util::ConvertBSTRToString` / `_bstr_t` ANSI conversion | Converts returned `BSTR` token to ANSI before `_strdup`. |
| COM interface | `IThrunetUrlCheck` and `CheckUrl` | Inferred from ProgID `thrunet.clsURLCHK` and vtable slot `+0x1c`; document as provisional. |

## Ownership And Source Placement

Ranked placement:

1. **[UID:0000N4] `RegistryConfig` file-level helper**: best current owner/emitter. The function is in the `0x0048f400-0x00491b28` startup command-line/session parser island, mutates RegistryConfig startup fields, shares field names and success writes with nearby parser children, and is source-authored application logic.
2. **[UID:0000BW] `RegistryConfig` class method**: plausible but not proven. IDA renders `__thiscall`, but no direct caller, vtable route, selector, or stored function pointer proves this should become `RegistryConfig::ParseThrunetStartupAuthenticationFile()`.
3. **COM/runtime helper ownership**: rejected. The body performs launcher file parsing, DNS resolution, RegistryConfig field writes, user-visible failure UI, and mode-state updates. Only callees such as `0x004941e0`, `0x00494440`, `0x004944c0`, `0x005c8dd0`, and `0x005c8cb0` are COM/CRT support.
4. **PlatformApi owner**: rejected. `0x0069be14` is a PlatformApi `_wfopen` dispatch slot, but this target only consumes it.

Keep `CANONICAL_OWNER:0000N4` and `EMITTER_UIDS:0000N4`. Do not promote the whole parser island to class methods solely because this child is IDA-modeled as `__thiscall`.

## Boundary, Chunks, And Range

The main target range remains exactly `0x0048fca0-0x004901f0`.

- `0x0048fca0` is the modeled function start.
- `0x004901f0-0x00490200` is sixteen `0xcc` bytes of alignment before [UID:0002BK].
- `0x0048fc96-0x0048fca0` is ten `0xcc` bytes after the previous sibling and before this target.
- `0x00493f00-0x00493f0d` is an IDA-attached COM pointer release cleanup tail.
- `0x005fccc2-0x005fcd3a` is an IDA-attached EH/unwind cleanup chunk.

Do not expand this by-memory page's source range to include cleanup chunks. Document them as compiler-generated support assigned by IDA to the function, already routed through ignored/compiler coverage handling.

## Rejected Alternatives

- **Leave C++ blank**: rejected. The active blockers from the current page were startup-state field names and COM/helper names. Current MCP plus live sibling/support pages resolve those to implementation-ready inferred names with documented confidence cap.
- **Treat `0x0069be14` as an unknown global**: rejected. MCP xrefs and WideApi dispatch docs tie it to the PlatformApi `_wfopen` slot initialized by `WideApiDispatchInit`.
- **Treat `0x2916c4` as the COM token/context overlay here**: rejected for this target. In [UID:0002BJ] it is written immediately after parsing the second file line and is the startup port. The COM-returned token string is copied to `+0x28d9e0`.
- **Treat `0x28d9e0` as only a COM object holder**: rejected for this target. [UID:0002BN] uses that region as COM holder/scratch, but [UID:0002BJ] writes a `0x40` byte token string there with `_strcpy_s`.
- **Promote to a confirmed class method**: rejected for now. There is no caller/selector/vtable route despite direct xref and VA/RVA pointer checks.
- **Model COM helper callees as NexusTK source helpers**: rejected. `0x004941e0`, `0x004944c0`, `0x005c8dd0`, and `0x005c8cb0` are MSVC/CRT/COM support idioms; the target source should express normal COM and CRT operations.
- **Collapse error paths**: rejected. File open, DNS failure, COM creation failure, COM call failure, and rejected token paths are observed and user-visible.

## Formal Reconstruction C++ Recommendation

Insert this in the target's formal `RECONSTRUCTION_CPP CODE` block if the report is accepted. The helper names and COM interface/method names are inferred source-facing names; target notes should state they are provisional where original symbol proof is unavailable.

```cpp
static void ParseThrunetStartupAuthenticationFile(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[1024];
    wchar_t authFilePath[128];
    wchar_t serverLine[128];
    wchar_t portLine[128];
    char authRequest[256];
    char hostName[256];

    const wchar_t *fileArgument = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                              commandLine,
                                                              _countof(commandLine));
    CopyLauncherWideArgument(authFilePath, _countof(authFilePath), fileArgument);

    FILE *authFile = g_pfnWideOpenFile(authFilePath, L"ro");
    if (authFile == NULL)
        AbortWithLauncherMessage(kThrunetAuthFileOpenFailedMessage);

    ReadByteLineAsWide(authFile, serverLine, _countof(serverLine));

    if (serverLine[0] >= L'0' && serverLine[0] <= L'9')
    {
        const wchar_t *part = serverLine;

        for (int i = 0; i < 4; ++i)
        {
            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(part));
            if (i != 3)
                part = wcschr(part, L'.') + 1;
        }
    }
    else
    {
        const wchar_t *space = wcschr(serverLine, L' ');
        size_t hostLength = space != NULL ? static_cast<size_t>(space - serverLine)
                                          : wcslen(serverLine);

        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  serverLine,
                                  hostLength * sizeof(wchar_t));
        config->m_startupHostName[hostLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(hostLength),
                                            hostName,
                                            _countof(hostName),
                                            NULL,
                                            NULL);
        hostName[converted] = '\0';

        hostent *host = gethostbyname(hostName);
        if (host == NULL)
            AbortWithLauncherMessage(kThrunetHostLookupFailedMessage);

        memoryMan->MemmoveWrapper(config->m_startupAddress, host->h_addr_list[0], 4);
    }

    ReadByteLineAsWide(authFile, portLine, _countof(portLine), 10);
    config->m_startupPort = _wtol(portLine);

    memset(authRequest, 0, sizeof(authRequest));
    fscanf(authFile, "%s", authRequest);
    fclose(authFile);

    CoInitialize(NULL);

    IThrunetUrlCheck *urlCheck = NULL;
    HRESULT hr = CreateComObjectFromProgId(reinterpret_cast<void **>(&urlCheck),
                                           kThrunetUrlCheckProgId,
                                           NULL,
                                           CLSCTX_INPROC_SERVER |
                                               CLSCTX_INPROC_HANDLER |
                                               CLSCTX_LOCAL_SERVER |
                                               CLSCTX_REMOTE_SERVER);
    if (FAILED(hr))
        AbortWithLauncherMessage(kThrunetComponentNotInstalledMessage);

    _bstr_t request(authRequest);
    BSTR rawResponse = NULL;
    hr = urlCheck->CheckUrl(request, &rawResponse);
    if (FAILED(hr))
        _com_issue_errorex(hr, urlCheck, __uuidof(IThrunetUrlCheck));

    _bstr_t response(rawResponse, false);
    char *tokenText = _strdup(static_cast<const char *>(response));
    if (tokenText[0] == '*')
        AbortWithLauncherMessage(kThrunetAuthenticationRejectedMessage);

    strcpy_s(config->m_thrunetAuthenticationToken, 64, tokenText);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;

    free(tokenText);
    urlCheck->Release();
}
```

## Recommended Target And Support Doc Changes

Target `by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md`:

- Set metadata to `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged at `0000N4`, reconstructable `TRUE`.
- Insert the formal C++ block above.
- Update the item summary to mention first-draft `RegistryConfig.cpp` helper C++, `_wfopen` dispatch route, COM/BSTR helper resolution, port/token field distinction, exact padding, cleanup chunks, no direct xref/pointer route, and confidence cap.
- Expand behavior/evidence with the full flow: command-line file path, `_wfopen` mode `"ro"`, first-line dotted-IP/DNS handling, second-line port at `+0x2916c4`, `%s` auth request token, `thrunet.clsURLCHK`, COM slot `+0x1c`, BSTR conversion, rejection on leading `'*'`, token copy to `+0x28d9e0`, ready/mode writes.
- Add rejected alternatives from this report.

Support docs:

- `by-file/RegistryConfig.md`: add [UID:0002BJ] beside the Netsgo and Excite parser notes as provisional `ParseThrunetStartupAuthenticationFile(RegistryConfig *config)`; state it is file-level/config-adjacent, not confirmed class method; record `+0x28d9e0` as a mode-specific Thrunet token string buffer and `+0x2916c4` as port for this target.
- `by-class/RegistryConfig.md`: add the same class-scope caveat and field-use note, keeping the target out of confirmed class-method status.
- `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`: expand the child row for [UID:0002BJ] and shared field notes with the file-backed Thrunet behavior, `_wfopen` path, port/token distinction, COM ProgID, and formal C++ readiness.
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`: expand the `0x00616e60` ProgID entry and add role entries for `0x00616dd0` file-open failure, `0x00616e08` host lookup failure, `0x00616e74` COM creation/component failure, and `0x00616ea4` returned-token rejection. Note that the failure text should be recorded by role unless separately decoded/validated.
- `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`: add [UID:0002BJ] as a semantic caller of `sub_4941E0` ProgID/COM creation, `sub_4944C0` narrow CRT scan, and BSTR conversion helpers `0x005c8dd0`/`0x005c8cb0`; keep the helper island non-emitting/runtime support.
- `by-global/WideApiDispatchTable.md`: add [UID:0002BJ] as a concrete `_wfopen` dispatch-slot consumer at `0x0069be14`, opening the Thrunet auth file path with mode `"ro"`.
- `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`: add the same concrete consumer note for the `_wfopen` slot.

Generated/project-level/manual coverage files:

- Do not edit `auto-generated/-ag-research-tracker.md`, project-level stats, validator/tool state, IDA DB, or any `-coverage-report.md`. The stale generated tracker row should be refreshed only by the validator/executed-report lifecycle after implementation and supervisor verification.

## Implementation Tracking Checklist

Implementation callback completed by B006 on 2026-06-26. Proof below is tied to the scoped validator batch and post-cleanup lease report.

- [x] Update target metadata in `by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md` to `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged at `0000N4`, reconstructable `TRUE`, blank emitter position. Proof: validator command `000000003230` at `2026-06-26T19:47:54-04:00` reported `completion_update 0002BJ ... 88`, `confidence_update ... 90`, `canonical_owner_update ... 0000N4`, and exit `0` / `ok: 1`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block for `ParseThrunetStartupAuthenticationFile(RegistryConfig *config)`. Proof: target now contains the formal C++ block beginning with `static void ParseThrunetStartupAuthenticationFile(RegistryConfig *config)` and validated under command `000000003230`.
- [x] Update target item summary, behavior, state-write table, external dependencies, boundary/chunk notes, evidence, reconstruction notes, rejected alternatives, and score rationale with the MCP-backed details in this report. Proof: target now records `_wfopen` slot `0x0069be14`, COM ProgID `thrunet.clsURLCHK`, COM vtable `+0x1c`, BSTR conversion dependencies `0x005c8dd0`/`0x005c8cb0`, exact helper/call anchors, field writes, cleanup chunks, rejected alternatives, and confidence cap; validated under command `000000003230`.
- [x] Update `by-file/RegistryConfig.md` with the file-static 0002BJ route, source-facing helper name, class-method caveat, and field-use notes for `+0x28d9e0` token string and `+0x2916c4` port. Proof: command `000000003231` at `2026-06-26T19:47:56-04:00`, exit `0` / `ok: 1`.
- [x] Update `by-class/RegistryConfig.md` with the same class-scope caveat and startup field inventory refinements. Proof: command `000000003232` at `2026-06-26T19:47:57-04:00`, exit `0` / `ok: 1`.
- [x] Update parent `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` child row/shared field notes for Thrunet auth-file parsing, COM validation, field writes, and C++ readiness. Proof: command `000000003233` at `2026-06-26T19:47:59-04:00`, exit `0` / `ok: 1`.
- [x] Update `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md` with `0x00616dd0`, `0x00616e08`, `0x00616e60`, `0x00616e74`, and `0x00616ea4` roles. Proof: command `000000003234` at `2026-06-26T19:48:01-04:00`, exit `0` / `ok: 1`.
- [x] Update `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md` with the 0002BJ COM/CRT/BSTR helper caller details. Proof: command `000000003235` at `2026-06-26T19:48:11-04:00`, exit `0` / `ok: 1`; callback correction applied so only in-range helpers `0x004941e0`, `0x00494440`, and `0x004944c0` are documented on that page, while BSTR helpers `0x005c8dd0`/`0x005c8cb0` remain target dependency facts outside this support range.
- [x] Update `by-global/WideApiDispatchTable.md` with 0002BJ as an `_wfopen` dispatch-slot consumer. Proof: command `000000003236` at `2026-06-26T19:48:19-04:00`, exit `0` / `ok: 1`.
- [x] Update `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` with the concrete 0002BJ `_wfopen` consumer note. Proof: command `000000003237` at `2026-06-26T19:48:21-04:00`, exit `0` / `ok: 1`.
- [x] Do not edit generated/project-level/manual coverage/tool-state/IDA DB files. Proof: B006 manual edits were limited to the accepted by-* docs and this report checklist; scoped validator output reported `generated_refresh: deferred` and validator-owned projected stats updates, with no manual generated/project-level/tool-state/IDA DB/-coverage-report edits.
- [x] During implementation only, lease each file immediately before editing and release leases immediately after the edit/validator batch. Proof: B006 leased the eight by-* docs immediately before editing; cleanup command `python .\leaser.py B006 unlease` returned `B006: No active leases`, and `tools/leaser/Agents/current_leases.md` read after cleanup contains no B006 rows.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* file:
  - [x] `python .\tools\validator.py --mode file --file by-memory\0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md --apply --queue-timeout 240` -> command `000000003230`, `2026-06-26T19:47:54-04:00`, exit `0`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-file\RegistryConfig.md --apply --queue-timeout 240` -> command `000000003231`, `2026-06-26T19:47:56-04:00`, exit `0`, `ok: 1`; pre-existing missing-ref warnings for `0003FW`/`0003FX` remained.
  - [x] `python .\tools\validator.py --mode file --file by-class\RegistryConfig.md --apply --queue-timeout 240` -> command `000000003232`, `2026-06-26T19:47:57-04:00`, exit `0`, `ok: 1`; pre-existing missing-ref warnings for `0003FW` remained.
  - [x] `python .\tools\validator.py --mode file --file by-memory\0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240` -> command `000000003233`, `2026-06-26T19:47:59-04:00`, exit `0`, `ok: 1`; pre-existing missing-ref warning for `0003FX` remained.
  - [x] `python .\tools\validator.py --mode file --file by-memory\0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply --queue-timeout 240` -> command `000000003234`, `2026-06-26T19:48:01-04:00`, exit `0`, `ok: 1`; pre-existing missing-ref warning for `0003TY` remained.
  - [x] `python .\tools\validator.py --mode file --file by-memory\0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md --apply --queue-timeout 240` -> command `000000003235`, `2026-06-26T19:48:11-04:00`, exit `0`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply --queue-timeout 240` -> command `000000003236`, `2026-06-26T19:48:19-04:00`, exit `0`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-memory\0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md --apply --queue-timeout 240` -> command `000000003237`, `2026-06-26T19:48:21-04:00`, exit `0`, `ok: 1`.
- [x] Report validator command ids, timestamps, exit codes, and `ok` counts after implementation. Proof: recorded above and included in the FINISHED_IMPLEMENTATION checkpoint.
- [x] Supervisor-only after verification: execute/archive the report through the validator executed-report lifecycle; do not manually edit generated tracker rows. Proof: B006 did not execute/archive the report and did not manually edit generated tracker rows; this remains correctly supervisor-owned after B006 implementation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002BJ-ThrunetStartupAuthFileParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002BJ-ThrunetStartupAuthFileParser-source-quality.md","timestamp":"2026-06-26T19:52:35","uid":"0002BJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
