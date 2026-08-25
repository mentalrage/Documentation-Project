** TARGET-REPORT-UID:0002BN **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B013 source-quality report: [UID:0002BN] ComBackedLauncherAuthenticationParser

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0002BN-ComBackedLauncherAuthenticationParser-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md`

Assignment: B-agent report-only source-quality / C++ readiness pass. I did not edit the target by-memory page, support by-* pages, generated files, validator state/cache, IDA database, or any coverage report.

## Executive recommendation

Keep [UID:0002BN] source-bearing, reconstructable, and owned/emitted by [UID:0000N4] `RegistryConfig`.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000N4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N4
```

Recommended C++ handling: insert first-draft C++ during a later authorized implementation callback. The COM class/interface names remain source-facing/inferred, but the parser body, field writes, helper island placement, COM failure paths, DNS path, SEH chunk, and no-direct-dispatch caveat are now live-MCP checked. This is enough for a scoped first-draft helper under `RegistryConfig.cpp` if the page clearly marks the COM type names as provisional.

Best source-facing helper name:

```text
static void ParseExciteGameLauncherAuthentication(RegistryConfig *config);
```

Safer alternate if the supervisor does not want the brand inferred from the failure text:

```text
static void ParseComBackedLauncherAuthentication(RegistryConfig *config);
```

Do not promote this to a confirmed `RegistryConfig::` method yet. The binary receives the config pointer as `this`/`ecx`, but live MCP still finds no direct xref, start pointer, or selector route to `0x00490b10`. File-static `RegistryConfig.cpp` helper placement is the best current fit.

## IDA MCP status

IDA MCP was mandatory for this assignment and was available.

Read-only checks performed:

- TCP listener on `127.0.0.1:13337` was present.
- JSON-RPC `initialize` succeeded with server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` returned active session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` reported `auto_analysis_ready:true`, `hexrays_ready:true`, module `NexusTK.exe`, imagebase `0x400000`.
- No IDA edits, renames, comments, type changes, database writes, process restarts, or MCP restarts were made.

Live MCP tools used for this report included `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `find_bytes`, `get_string`, and `make_signature_for_range`.

## Evidence checked

Target and support documentation checked:

- `by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md`
- `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- `by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md`
- `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`
- `by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md`
- `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`
- `by-memory/-ignored.md`
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-file/RegistryConfig.md`
- `by-class/RegistryConfig.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/config/RegistryConfig.cpp`
- Executed support reports `executed-b-agent-research/B007/0002BG-CommandLineArgumentCounter-source-quality.md` and `executed-b-agent-research/B008/0002BI-NetsgoStartupAuthenticationParser-source-quality.md`

Generated reports are stale for this UID: the live target page is already `85/88`, while the generated tracker/coverage rows still show `78/85`. I did not edit generated files.

## Live MCP boundary and liveness

MCP confirms the documented function/range:

- `lookup_funcs 0x00490b10` resolves to `sub_490B10`, size `0x5b0`.
- `lookup_funcs 0x004910c0` reports no function at the end boundary.
- `get_bytes 0x00490b00` shows `0xcc` padding up to the prologue at `0x00490b10`.
- `get_bytes 0x004910b0` shows the target tail followed by `0xcc` padding before successor prologue `0x004910d0`.
- `get_bytes 0x005fcd3a` shows the associated C++ SEH cleanup chunk.
- `xrefs_to 0x00490b10` returns zero xrefs.
- `xrefs_to 0x004910c0` returns zero xrefs.
- `xrefs_to 0x005fcd3a` returns one data xref at `0x0065b08c`, consistent with exception metadata rather than a semantic caller.
- `find_bytes` for little-endian VA `10 0B 49 00` and RVA `10 0B 09 00` returns zero matches.
- `make_signature_for_range 0x00490b10-0x004910c0` reports a unique signature.

Conclusion: the body is a real IDA-modeled source function with exact boundaries and an SEH chunk, but its dispatcher/selector route remains unrecovered. That caveat should stay in the target and parent pages. It is not a no-code reason because the function is modeled, source-shaped, and writes live `RegistryConfig` startup fields.

## Behavior resolution

`sub_490B10` is a COM-backed launcher authentication parser. It:

1. Copies `GetCommandLineW()` into a 1024-wide-character local buffer.
2. Skips the executable token using quote/space handling.
3. Returns if no post-executable command tail is present.
4. Calls `CoInitialize(0)`.
5. Allocates/replaces a COM holder stored through `config + 0x28d9e0`.
6. Calls `CoCreateInstance` with CLSCTX value `0x17`, `IID_IUnknown` at `0x00616db0`, and a class GUID at `0x0061712c`.
7. Runs the object through `OleRun`.
8. Queries/acquires the launcher-auth interface using GUID-like data at `0x0061711c`.
9. On COM creation/acquisition failure, shows the component-not-installed message at `0x0061713c`, posts quit, and goes through the loader/failure path.
10. Wraps the command tail in a `BSTR` and passes it to the COM object through the vtable slot represented in decompile as `+0x20`.
11. Retrieves an endpoint string through the COM wrapper helper at `0x004943a0`.
12. If the endpoint begins with a digit, tokenizes it as dotted IPv4 and writes four address bytes to `config + 0x2915b4`.
13. Otherwise copies it to `config + 0x2915c4`, converts it through `WideCharToMultiByte(CP_ACP, ...)`, calls `gethostbyname`, and copies the resolved address bytes to `config + 0x2915b4`.
14. On DNS failure, calls the ignored COM smart-pointer null-check helper at `0x00494000`, formats the host-specific Excite Game failure text at `0x00617160`, and shows a message box.
15. On success, calls the COM vtable slot represented in decompile as `+0x28` and stores the returned context/token value at `config + 0x2916c4`.
16. Writes startup ready word `1` at `config + 0x2916ca`.
17. Writes mode byte `5` at `config + 0x28de28`.
18. Runs BSTR/holder cleanup through the SEH cleanup chunk and helper `0x00494440`.

Live MCP `analyze_function` also confirms the important callees: `CoInitialize`, `CoCreateInstance`, `OleRun`, `SysAllocString`, `WideCharToMultiByte`, `gethostbyname`, `MessageBoxW`, `PostQuitMessage`, `_wcscpy_s`, `_wcstok_s`, `_wcschr`, `unknown_libname_24` wide integer conversion, `sub_494000`, `sub_4943A0`, and `sub_494440`.

## Field and data resolution

Recommended field wording for the target:

| Offset | Recommended meaning |
| --- | --- |
| `+0x28d9e0` | Launcher-auth COM holder / startup scratch overlay. Sibling parsers reuse this area for launcher payload strings, so document it as mode-dependent scratch rather than a global final field name. |
| `+0x2915b4` | `m_startupAddress[4]`; receives dotted IPv4 bytes or DNS result bytes. |
| `+0x2915c4` | `m_startupHostName[128]`; receives nonnumeric endpoint text before DNS resolution. |
| `+0x2916c4` | Target-specific returned COM context/token slot. Other parser siblings use this offset as `m_startupPort`, so document this as a union/variant use, for example `m_startupPortOrLauncherToken` in support prose and `m_launcherAuthenticationToken` in this target draft. |
| `+0x2916ca` | `m_startupReady`; startup/terminal-ready flag/state word. |
| `+0x28de28` | `m_startupConnectionMode`; success writes byte `5`, matching the no-COM/direct-mode value documented by terminal setup support pages. |

Recommended COM/data symbol wording:

| Address | Meaning |
| --- | --- |
| `0x00616db0` | `IID_IUnknown` bytes `{00000000-0000-0000-C000-000000000046}`; xrefs from this target and COM helper `0x004941e0`. |
| `0x0061712c` | CLSID-like launcher authentication COM class GUID; only target xref seen at `0x00490bff`. Keep final class name provisional. |
| `0x0061711c` | IID/interface GUID-like data used by target COM calls and helper `0x004943a0`; final interface name unresolved. |
| `0x0061713c` | Component-not-installed failure string used by the generic COM failure path. |
| `0x00617160` | Excite Game host/input failure format string used after `gethostbyname` failure. |
| `0x00612e38` | UTF-16 dot delimiter for dotted IPv4 tokenization. |

The string-data support page [UID:0003FV] currently covers nearby startup/channel literals but does not yet document the COM GUIDs/failure strings used by this target. A later implementation pass should add compact support notes there rather than leaving these anchors only in the target page.

## COM helper island

The helper page [UID:000221] should remain non-emitting runtime/support context. It correctly explains:

- `0x004943a0-0x0049443f` as the COM wrapper helper called only from `sub_490B10`.
- `0x00494440-0x0049449a` as BSTR/holder release cleanup.
- `0x004941e0-0x00494396` as `_com_ptr_t::CreateInstance`-style support.

The ignored ledger entry for `0x00494000-0x00494011` is also correct: MCP confirms its only direct xref is `0x00490f41` inside `sub_490B10`, and its body is a COM smart-pointer null-check/throw helper. Do not assign source ownership or emitted C++ to `0x00494000`; model it as a source-level null/COM error check in this parser.

## Ownership and source placement

Keep:

```text
CANONICAL_OWNER:0000N4
EMITTER_UIDS:0000N4
RECONSTRUCTABLE:TRUE
```

Reasoning:

- The parser island parent [UID:000220] is already owned/emitted by `RegistryConfig`.
- This target writes the same `RegistryConfig` startup fields as the sibling launcher parsers.
- `by-file/RegistryConfig.md` explicitly keeps command-line/session parser helpers file-level/config-adjacent until the full parser island is rehomed.
- The accepted sibling [UID:0002BI] uses file-static `ParseNetsgoStartupAuthentication(RegistryConfig *config)` with first-draft C++; this target is analogous but COM-backed.
- No direct caller or vtable route proves a class method.

Rejected alternatives:

- Compiler-generated COM glue only: rejected. The function contains command-line parsing, DNS resolution, startup field writes, failure UI, and mode state writes.
- Non-emitting helper island: rejected for the target body. Only the COM support helpers should remain non-emitting.
- Separate COM module owner: rejected. The durable side effects are `RegistryConfig` startup state, and the COM object is only an input/auth provider for that state.
- Blank formal C++ due only to unrecovered dispatcher: rejected. The dispatcher gap caps score and must be documented, but the body itself is modeled and reconstructable.

## Formal C++ recommendation

Insert the following exact text between the target page's formal `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines during a later implementation callback, if the supervisor accepts provisional COM type/constant names:

```cpp
static void ParseExciteGameLauncherAuthentication(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t endpointScratch[256];
    wchar_t *tokenContext;
    char ansiHost[128];

    const wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                              commandLine,
                                                              1024);
    if (argumentText == 0)
        return;

    CoInitialize(0);

    IUnknown *createdObject = 0;
    ILauncherAuthentication *launcher = 0;

    HRESULT hr = CoCreateInstance(CLSID_ExciteGameLauncherAuthentication,
                                  0,
                                  CLSCTX_INPROC_SERVER |
                                      CLSCTX_LOCAL_SERVER |
                                      CLSCTX_REMOTE_SERVER,
                                  IID_IUnknown,
                                  reinterpret_cast<void **>(&createdObject));
    if (SUCCEEDED(hr))
    {
        hr = OleRun(createdObject);
        if (SUCCEEDED(hr))
        {
            hr = createdObject->QueryInterface(IID_ILauncherAuthentication,
                                               reinterpret_cast<void **>(&launcher));
        }
        createdObject->Release();
    }

    if (FAILED(hr) || launcher == 0)
        AbortWithLauncherMessage(kLauncherComponentNotInstalledMessage);

    ReplaceLauncherAuthenticationObject(&config->m_launcherAuthenticationObject,
                                        launcher);

    BSTR commandText = SysAllocString(argumentText);
    hr = launcher->SetLaunchCommand(commandText);
    SysFreeString(commandText);
    if (FAILED(hr))
        RaiseComError(hr);

    const wchar_t *endpointText = launcher->GetEndpointText();
    if (endpointText[0] >= L'0' && endpointText[0] <= L'9')
    {
        wcscpy_s(endpointScratch, 256, endpointText);

        tokenContext = 0;
        wchar_t *part = wcstok_s(endpointScratch, L".", &tokenContext);
        for (int i = 0; i < 4; ++i)
        {
            if (part == 0)
                AbortWithLauncherHostMessage(kExciteGameHostErrorFormat,
                                             endpointText);

            config->m_startupAddress[i] =
                static_cast<unsigned char>(_wtol(part));

            part = wcstok_s(0, L".", &tokenContext);
        }
    }
    else
    {
        wcscpy_s(config->m_startupHostName, 128, endpointText);

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            -1,
                                            ansiHost,
                                            128,
                                            0,
                                            0);
        if (converted <= 0 || converted >= 128)
            AbortWithLauncherHostMessage(kExciteGameHostErrorFormat,
                                         endpointText);

        hostent *host = gethostbyname(ansiHost);
        if (host == 0 || host->h_addr_list == 0 || host->h_addr_list[0] == 0)
            AbortWithLauncherHostMessage(kExciteGameHostErrorFormat,
                                         launcher->GetEndpointText());

        memcpy(config->m_startupAddress, host->h_addr_list[0], 4);
    }

    config->m_launcherAuthenticationToken = launcher->GetAuthenticationToken();
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}
```

C++ caveats to place near the block:

- `CopyLauncherCommandLineTail`, `ReplaceLauncherAuthenticationObject`, `AbortWithLauncherMessage`, `AbortWithLauncherHostMessage`, and `RaiseComError` are source-level helper names for already-observed command-line, COM-holder, message-box, quit, and COM-error paths.
- `ILauncherAuthentication`, `CLSID_ExciteGameLauncherAuthentication`, and `IID_ILauncherAuthentication` are provisional names for the recovered COM class/interface GUIDs. Exact original COM names remain unknown.
- `m_launcherAuthenticationObject` is a target-specific name for the `+0x28d9e0` COM holder overlay. Sibling parsers use the same offset range as startup payload buffers.
- `m_launcherAuthenticationToken` is a target-specific name for the `+0x2916c4` return value. Sibling host/port parsers use the same offset as `m_startupPort`.

If formal C++ is rejected despite this report, use this exact no-code proof:

```text
Formal C++ remains blank despite reconstructable behavior because the COM class/interface names, `+0x28d9e0` COM-holder overlay name, and `+0x2916c4` union field name remain provisional, and live IDA still finds no direct caller, dispatcher selector, or stored VA/RVA pointer to `0x00490b10`. The body is source-authored RegistryConfig parser logic, not no-code; first-draft C++ is ready in the B013 report for supervisor acceptance.
```

## Recommended target-page implementation checklist

Only after supervisor implementation callback:

1. Raise the target to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
2. Replace the stale live-MCP-timeout caveat with current MCP evidence from this report.
3. Document exact boundary facts: function `sub_490B10` size `0x5b0`, no function at `0x004910c0`, padding before/after, and SEH cleanup chunk `0x005fcd3a-0x005fcdc2`.
4. Add no-route evidence: zero `xrefs_to 0x00490b10`, zero `xrefs_to 0x004910c0`, and zero VA/RVA byte matches for `0x00490b10`.
5. Update behavior notes to include COM creation, OleRun, QueryInterface/interface GUID, command-tail BSTR, endpoint retrieval, dotted-IP branch, DNS branch, failure strings, token/context storage, ready/mode writes, and cleanup.
6. Update the state-write table with the field names recommended above, especially the target-specific `+0x2916c4` token/context overlay caveat.
7. Insert the first-draft C++ block if supervisor accepts provisional COM names; otherwise insert the exact no-code proof above.
8. Add rejected alternatives: not compiler glue, not COM-helper-only no-code, not separate COM module ownership, and not a confirmed class method.
9. Keep `0x00494000` in ignored/runtime helper context and `0x004943a0`/`0x00494440` in [UID:000221] support context.

## Recommended support-doc updates

### `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`

Add or refine the [UID:0002BN] child summary:

```text
`0x00490b10-0x004910c0` - IDA-modeled COM-backed Excite Game launcher authentication parser. It copies the command-line tail, initializes COM, creates/runs/query-acquires a launcher-auth COM object, passes the command tail as BSTR, retrieves endpoint/auth data, parses dotted IPv4 or resolves a host name, stores startup address bytes at `+0x2915b4`, stores the COM returned token/context at `+0x2916c4`, sets `+0x2916ca` and mode byte `+0x28de28 = 5`, and uses localized component/install and host failure message paths. Direct dispatcher/xrefs remain unrecovered.
```

Also add a parent note that `+0x2916c4` is mode-dependent: port for host/port siblings, returned COM token/context for [UID:0002BN].

### `by-file/RegistryConfig.md`

Add [UID:0002BN] to the command-line/session parser helper row as a file-level helper candidate:

```text
[UID:0002BN] `ParseExciteGameLauncherAuthentication(RegistryConfig *config)` is the COM-backed launcher-auth variant: it fills the shared startup address/ready/mode fields and uses `+0x2916c4` as a returned COM token/context overlay rather than a parsed port.
```

Do not promote the whole parser island to class methods solely because this function is IDA-modeled as `__thiscall`; no direct caller proves method status.

### `by-class/RegistryConfig.md`

Add a command-line/session helper note:

```text
[UID:0002BN] is RegistryConfig-owned source logic but should stay documented as a file-level helper until a dispatcher/caller route is recovered. It shares `m_startupAddress`, `m_startupHostName`, `m_startupReady`, and `m_startupConnectionMode`, and uses a mode-specific overlay at `+0x2916c4` for the COM returned authentication token/context.
```

### `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`

Add compact data support for the target-specific COM anchors:

```text
COM-backed launcher-auth parser support: [UID:0002BN] uses `0x0061712c` as a launcher-auth CLSID, `0x0061711c` as the queried launcher-auth interface GUID, `0x00616db0` as `IID_IUnknown`, `0x0061713c` as the component-not-installed failure string, `0x00617160` as the Excite Game host/input failure format string, and `0x00612e38` as the UTF-16 dotted-IP delimiter.
```

### `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`

No score change needed. Optionally add a cross-reference that [UID:0002BN] is the only semantic caller of `0x004943a0`, and that [UID:000221] remains support-only with no emitted source body.

### `by-memory/-ignored.md`

No edit is required unless the supervisor wants a freshness note. The existing `0x00494000` ignored-helper entry is supported by current MCP: one direct xref at `0x00490f41` from [UID:0002BN].

### `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

Optional support note only if field-cluster detail is being refreshed:

```text
[UID:0002BN] is a mode-specific exception to the simple `+0x2916c4` port wording: this COM-backed parser stores the returned launcher-auth token/context at that offset after resolving/storing the startup address, then sets `+0x2916ca` and `+0x28de28 = 5`.
```

## Validator needs after implementation callback

No validators were run for this report-only pass.

After authorized by-* edits, run scoped validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002BN-ComBackedLauncherAuthenticationParser-source-quality-removed.md](0002BN-ComBackedLauncherAuthenticationParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add `by-memory\0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`, `by-memory\-ignored.md`, or `by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md` to the validator batch only if those optional support notes are edited.

Generated tracker/coverage rows should refresh through the validator pipeline; do not manually edit generated reports.

## IDA rename/type/comment recommendations

No IDA changes were made.

If an IDA-owner later applies names/comments:

```text
0x00490b10: RegistryConfig_ParseExciteGameLauncherAuthentication
0x00616db0: IID_IUnknown
0x0061712c: CLSID_ExciteGameLauncherAuthentication (provisional)
0x0061711c: IID_ILauncherAuthentication (provisional)
0x0061713c: kLauncherComponentNotInstalledMessage
0x00617160: kExciteGameHostErrorFormat
```

Suggested function type if the project accepts provisional helper typing:

```cpp
void __thiscall RegistryConfig_ParseExciteGameLauncherAuthentication(RegistryConfig *config);
```

Source-facing docs should still treat it as file-static helper placement until a caller/dispatcher route proves a class method.

## Open questions

| Question | Current resolution |
| --- | --- |
| Is the body live source? | Yes. IDA models it as a real function, it has app-specific command-line/COM/DNS/state behavior, and it writes `RegistryConfig` startup fields. |
| Is a dispatcher/caller recovered? | No. MCP found zero direct xrefs and zero VA/RVA pointer encodings for `0x00490b10`. |
| Are exact COM class/interface source names recovered? | No. GUID bytes and use sites are recovered; source names are provisional. |
| Is `+0x2916c4` a port here? | No. In this target the success path stores a returned COM token/context there. Siblings use the same offset as port storage, so support docs should mark it as mode-dependent/union-like. |
| Should COM support helpers emit C++ separately? | No. Keep `0x00494000`, `0x004943a0`, and `0x00494440` as runtime/support helpers and express them as source-level COM operations in the caller. |
| Should formal C++ remain blank? | Not preferred. A first-draft helper is supportable if provisional COM names are accepted. If rejected, use the exact no-code proof in this report. |

## Implementation tracking checklist

- [x] Supervisor accepted this implementation callback in `goal.md`; the callback selected report-level by-* incorporation with C++ insertion.
- [x] MCP was available before edits. JSON-RPC `server_health` for database `80de0a67` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, and `hexrays_ready: true`.
- [x] Leased only the immediate edit set: `by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md`, `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`, `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`. Release was attempted immediately after the edit/validator batch; the leaser reported no active B013 lease because the leases had already expired, and `current_leases.md` showed no active B013 lease.
- [x] Updated target [UID:0002BN]: completion/confidence `85/88` -> `88/90`, owner/emitter unchanged as [UID:0000N4], first-draft `ParseExciteGameLauncherAuthentication(RegistryConfig *config)` inserted, stale timeout caveat replaced with live MCP proof, state writes refreshed, COM/string anchors added, direct-route absence documented, and rejected alternatives recorded. Validators: `000000001406` at `2026-06-25T07:00:09-04:00` exit 0/ok; rerun `000000001413` at `2026-06-25T07:00:47-04:00` exit 0/ok after [UID:0003FV] registration.
- [x] Updated parent [UID:000220] child summary and `+0x2916c4` mode-dependent note. Validators: `000000001407` at `2026-06-25T07:00:11-04:00` exit 0/ok; rerun `000000001414` at `2026-06-25T07:00:58-04:00` exit 0/ok. Remaining `missing_ref_uid 0003FX` diagnostics are pre-existing support registry warnings outside this callback.
- [x] Updated `by-file/RegistryConfig.md` and `by-class/RegistryConfig.md` source-placement and field-overlay notes. Validators: by-file `000000001408` at `2026-06-25T07:00:13-04:00` exit 0/ok and rerun `000000001416` at `2026-06-25T07:01:07-04:00` exit 0/ok; by-class `000000001409` at `2026-06-25T07:00:14-04:00` exit 0/ok. Remaining `missing_ref_uid 0003FW/0003FX` diagnostics are pre-existing support registry warnings outside this callback.
- [x] Updated [UID:0003FV] string-data support for the COM GUID/failure-string anchors and the out-of-range dotted-IP delimiter caveat. Validator `000000001410` at `2026-06-25T07:00:16-04:00` exit 0/ok registered the new [UID:0003FV] mapping; remaining `missing_ref_uid 0003TY` is an existing support registry warning.
- [x] Updated optional support pages where the accepted report detail was missing: [UID:000221] now records [UID:0002BN] as the only semantic caller for `0x004943a0` while staying support-only, and [UID:00028Q] records the `+0x2916c4` launcher-token overlay. Validators: `000000001411` at `2026-06-25T07:00:17-04:00` exit 0/ok and `000000001412` at `2026-06-25T07:00:28-04:00` exit 0/ok. The ignored helper entry for `0x00494000-0x00494011` already contained same-or-greater detail and was not edited.
- [x] Generated refresh was left to the validator pipeline, not manually edited. Queue status `000000001428` at `2026-06-25T07:03:53-04:00` showed zero queued/processing generated refresh jobs; `auto-generated/NexusTK/config/RegistryConfig.cpp` header shows `validator-command-id: 000000001427`, `validator-refreshed-at: 2026-06-25T07:03:24-04:00`, and contains [UID:0002BN] with `ParseExciteGameLauncherAuthentication`.
- [x] No generated reports, project-level generated files, validator state/cache, lock files, IDA DB, or `-coverage-report.md` files were manually edited.

FINISHED_IMPLEMENTATION

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0002BN-ComBackedLauncherAuthenticationParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002BN-ComBackedLauncherAuthenticationParser-source-quality.md","timestamp":"2026-06-25T07:14:24","uid":"0002BN"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BN-ComBackedLauncherAuthenticationParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0002BN-ComBackedLauncherAuthenticationParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
