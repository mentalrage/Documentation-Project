** TARGET-REPORT-UID:0002BL **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002BL] LauncherHostPortPayloadParser Source-Quality Report

Agent: Agent-B010  
Assignment: `B010-report-0002BL-LauncherHostPortPayloadParser-source-quality-20260627`  
Target: `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md`  
Report-only status: no by-* docs, generated files, manual coverage reports, validator/tool state, IDA DB, or project-level generated files were edited.

## Recommendation

Raise [UID:0002BL] from `COMPLETION:85`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, and blank `EMITTER_POSITION_OPTIONAL`.

Insert first-draft formal C++ as a file-static `RegistryConfig.cpp` helper:

```text
static void ParseLauncherHostPortPayload(RegistryConfig *config);
```

Do not promote it to a confirmed `RegistryConfig::` method. The binary receives the startup/config object in `ecx`, but live MCP still finds no direct xref, no stored VA/RVA pointer, and no recovered dispatcher route for `0x00490510`.

Do not name it from the `NWind` caption. `NWind` is the failure-message caption shared with the predecessor LG Internet path, not a selector proof. This target has no brand-specific selector comparison; it consumes and skips the first post-executable token, then uses the next four tokens as host, port, payload 1, and payload 2.

## Current Target State

Current target page metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000N4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`
- `RECONSTRUCTION_CPP CODE` is blank
- Item summary: raw exported start; five-token launcher selector/host/port/payload parser with live IDA token, DNS, IPv4, success-write, and failure-path coverage.

The current page is largely correct, but the current "leave final C++ blank" reason is now too conservative under the accepted B006/B013 pattern. The dispatcher remains unrecovered and caps the score, but the body, fields, failure path, owner route, and source-facing helper role are sufficiently resolved for first-draft C++.

One boundary detail needs correction: live bytes show the successor padding is seven `0xcc` bytes at `0x00490809-0x00490810`, not six bytes at `0x0049080a-0x00490810`.

## MCP Status

IDA MCP was mandatory and was available.

Read-only checks performed:

- TCP listener on `127.0.0.1:13337` was present.
- JSON-RPC `initialize` succeeded with server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` returned active session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, owned/adopted.
- `server_health` reported `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- No IDA edits, renames, comments, type changes, database writes, process restarts, or MCP restarts were made.

Live MCP tools used for this report included `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, `find_bytes`, `get_string`, `entity_query`, `search_text`, and `make_signature_for_range`.

`decompile 0x00490510` returned `Decompilation failed at 0x490510`, consistent with the raw non-function status. The C++ below is therefore derived from live disassembly, byte/string/xref evidence, and accepted RegistryConfig field naming, not from a hidden Hex-Rays function object.

## Evidence Checked

Target and support documentation checked:

- `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md`
- `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- `by-file/RegistryConfig.md`
- `by-class/RegistryConfig.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- Neighboring parser pages [UID:0002BH], [UID:0002BK], [UID:0002BM], [UID:0002BO], [UID:0002BP], [UID:0002BQ], and [UID:0002BR]
- Accepted/executed B006, B008, B013, and B007 reports for parser-island naming, accepted field names, and first-draft C++ policy

Live MCP target facts:

- `lookup_funcs` reports `0x00490510`, `0x00490809`, `0x00490810`, and predecessor raw start `0x00490200` as `Not a function`.
- Neighboring modeled anchors remain `sub_48FCA0` at `0x0048fca0-0x004901f0` and `sub_490B10` at `0x00490b10-0x004910c0`.
- `get_bytes 0x0049050a size 16` returns six `0xcc` bytes followed by the target prologue `55 8b ec 81 ec ac 0c 00 00 a1`.
- `get_bytes 0x00490800 size 32` shows target tail `... 6a 00 e8 86 dd 14 00`, then seven `0xcc` bytes at `0x00490809-0x00490810`, then the successor prologue at `0x00490810`.
- `xrefs_to` reports zero xrefs to `0x00490510`, zero to `0x00490809`, and zero to `0x00490810`.
- `find_bytes` reports zero matches for little-endian VA/RVA forms `10 05 49 00`, `10 05 09 00`, `10 08 49 00`, and `10 08 09 00`.
- `make_signature_for_range 0x00490510-0x00490809` returns `unique:true`; the signature starts `55 8B EC 81 EC AC 0C 00 00 A1 24 2F 67 00`.
- `get_string` resolves `0x0060de18` as space, `0x00612e38` as `.`, and `0x0061701c` as `NWind`. It reports no string object at `0x00617024`.
- `get_bytes 0x00617024 size 96` returns CP949 bytes beginning `c0 d4 b7 c2 c1 a4 ba b8 20 22 25 73 22 ...`; decoded under code page 949, the first NUL-terminated segment is a Korean input-information error format containing `%s`.
- `xrefs_to 0x00617024` returns one data ref from `0x004907c0`. `xrefs_to 0x0061701c` returns data refs from `0x004904e2` and `0x004907e1`.

Live disassembly anchors:

- `0x00490510-0x00490544`: normal prologue, `0xcac` stack frame, security cookie setup, `ecx` saved in `ebx`, `MemoryMan` getter `sub_516030`, `GetCommandLineW`, and `_wcscpy_s` into a `0x400` wide-character command buffer.
- `0x00490549-0x00490578`: executable-path skip using `_wcschr`, first searching for quote and otherwise space.
- `0x0049059b-0x004905de`: `_wcstok_s` token collection with delimiter `0x0060de18`; the initial token is not stored, subsequent tokens are stored, the collector caps below eight, and parsing proceeds only when the stream ends with loop counter five.
- `0x004905e4`: host token loaded from `[ebp-0xca0]`, proving the first stored token after the skipped selector is host.
- `0x00490602-0x00490674`: numeric host branch splits on `0x00612e38`, calls the wide decimal parser at `0x005cea43`, and writes four low-byte octets to `config + 0x2915b4`.
- `0x00490679-0x00490708`: DNS branch copies the wide host to `config + 0x2915c4` via `sub_516220`, converts with `WideCharToMultiByte`, calls `gethostbyname`, and copies four resolved address bytes to `config + 0x2915b4`.
- `0x0049070d-0x00490732`: parses port token `[ebp-0xc9c]`, stores `config + 0x2916c4`, writes word `1` to `config + 0x2916ca`, and writes byte `5` to `config + 0x28de28`.
- `0x00490739-0x0049079b`: converts payload token 1 `[ebp-0xc98]` to `config + 0x28d9e0` and payload token 2 `[ebp-0xc94]` to `config + 0x28da20`, using `WideCharToMultiByte` with `0x3f` output cap and explicit NUL termination at the returned byte count.
- `0x004907b9-0x00490804`: DNS failure formats the raw CP949 `%s` input-error format at `0x00617024`, uses caption `NWind` at `0x0061701c`, calls `MessageBoxA`, then `PostQuitMessage(0)` and `__loaddll(0)`.

Numeric constants verified with `source-3/project-documentation/tools/int_convert.py`: `0x40` is 64, `0x3f` is 63, `0x80` is 128, `0x400` is 1024, `0x2328` is 9000, and `0xcac` is 3244.

## Field And Naming Resolution

Recommended field names for this target:

| Offset | Recommended target/source use | Evidence |
| --- | --- | --- |
| `+0x2915b4` | `m_startupAddress[4]` / `m_startupIpAddress[4]` | Numeric and DNS branches both write the four resolved bytes here. |
| `+0x2915c4` | `m_startupHostName[0x80]` | DNS branch copies the wide host here before ANSI conversion. |
| `+0x2916c4` | `m_startupPort` | Port token is parsed with the wide decimal helper and stored here; accepted support docs already use this as the host/port sibling port field. |
| `+0x2916ca` | `m_startupReady` | Success path writes word `1`; B007 and support docs already identify this as the startup/terminal-ready state. |
| `+0x28de28` | `m_startupConnectionMode` | Success path writes byte `5`, matching the no-COM/direct-mode startup parser family. |
| `+0x28d9e0` / `+0x28da20` | Target-local `m_launcherPayload[0][0x40]` and `m_launcherPayload[1][0x40]`, or two equivalent `char[0x40]` fields | This target and [UID:0002BO] use them as two `0x3f`-capped payload outputs plus NUL; [UID:0002BK] uses the same pair for session strings. Support docs should keep the region mode-dependent because [UID:0002BJ] and [UID:0002BN] overlay the first slot differently. |

The payload consumer search did not recover a better semantic name. Documentation search found only parser-island/support references for these offsets, and live island `search_text` shows the same region reused by Thrunet, LG Internet, this target, COM-backed launcher auth, Bixel, and KWG. Therefore the source-quality choice is a neutral target-local `m_launcherPayload` pair plus an explicit overlay caveat, not continued blank C++.

## Rejected Alternatives

- **Blank formal C++ because the start is raw:** rejected. B006/B013 established that an unrecovered dispatcher caps score but does not by itself block first-draft C++ when owner, fields, helper role, and behavior are resolved.
- **Name from `NWind`:** rejected. `NWind` is a message-box caption and also appears in the predecessor LG Internet failure path; there is no target selector comparison to `NWind`.
- **Brand-specific source helper:** rejected for this pass. Unlike `/Bixel`, `/KWG`, `/GameBill`, and `Mihosoft` siblings, this range contains no brand literal comparison.
- **Confirmed `RegistryConfig::` method:** rejected. The receiver shape is `thiscall`-like through `ecx`, but no vtable, method record, direct caller, or stored pointer route has been recovered.
- **Separate networking module:** rejected. The parser sits inside the RegistryConfig command-line parser island and writes RegistryConfig startup fields directly.
- **Final semantic payload names:** rejected. The two payload slots have no recovered non-parser consumer name, and the first slot is a known mode-dependent overlay in sibling parsers.

## Formal C++ Recommendation

Insert the following exact text between the target page's formal `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines during a later implementation callback, if the supervisor accepts the neutral helper/field names:

```cpp
static void ParseLauncherHostPortPayload(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[0x400];
    wchar_t *tokenContext = NULL;
    wchar_t *dotContext = NULL;
    wchar_t *tokens[8] = {};
    char ansiHost[0x80];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    wchar_t *selector = wcstok_s(argumentText, L" ", &tokenContext);
    if (selector == NULL)
        return;

    int tokenCount = 0;
    wchar_t *token = NULL;
    do
    {
        ++tokenCount;
        if (tokenCount >= 8)
            return;

        token = wcstok_s(NULL, L" ", &tokenContext);
        tokens[tokenCount] = token;
    } while (token != NULL);

    if (tokenCount != 5)
        return;

    wchar_t *hostToken = tokens[1];
    wchar_t *portToken = tokens[2];
    wchar_t *payloadToken1 = tokens[3];
    wchar_t *payloadToken2 = tokens[4];

    if (hostToken[0] >= L'0' && hostToken[0] <= L'9')
    {
        wchar_t *octet = wcstok_s(hostToken, L".", &dotContext);
        if (octet == NULL)
            return;

        config->m_startupAddress[0] = static_cast<unsigned char>(_wtol(octet));
        for (int i = 1; i < 4; ++i)
        {
            octet = wcstok_s(NULL, L".", &dotContext);
            if (octet == NULL)
                return;

            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(octet));
        }
    }
    else
    {
        size_t hostLength = wcslen(hostToken);
        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  hostToken,
                                  hostLength * sizeof(wchar_t));
        config->m_startupHostName[hostLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(hostLength),
                                            ansiHost,
                                            _countof(ansiHost),
                                            NULL,
                                            NULL);
        if (converted >= _countof(ansiHost))
            _report_rangecheckfailure();

        ansiHost[converted] = '\0';

        hostent *host = gethostbyname(ansiHost);
        if (host == NULL)
        {
            char message[0x400];
            sprintf_s(message,
                      _countof(message),
                      kLauncherHostInputErrorFormat,
                      ansiHost);
            MessageBoxA(ApplicationGetMainWindowHandle(),
                        message,
                        kNWindCaption,
                        0);
            PostQuitMessage(0);
            __loaddll(0);
            return;
        }

        memoryMan->MemmoveWrapper(config->m_startupAddress,
                                  host->h_addr_list[0],
                                  4);
    }

    config->m_startupPort = _wtol(portToken);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;

    int payloadLength = static_cast<int>(wcslen(payloadToken1));
    int payloadBytes = WideCharToMultiByte(CP_ACP,
                                           0,
                                           payloadToken1,
                                           payloadLength,
                                           config->m_launcherPayload[0],
                                           0x3f,
                                           NULL,
                                           NULL);
    config->m_launcherPayload[0][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken2));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken2,
                                       payloadLength,
                                       config->m_launcherPayload[1],
                                       0x3f,
                                       NULL,
                                       NULL);
    config->m_launcherPayload[1][payloadBytes] = '\0';
}
```

Notes for implementer:

- `CopyLauncherCommandLineTail`, `MemoryMan::GetMemoryMan`, `MemmoveWrapper`, `ApplicationGetMainWindowHandle`, `kLauncherHostInputErrorFormat`, and `kNWindCaption` are source-facing reconstruction names. Target notes should state they are inferred/provisional where original symbol proof is unavailable.
- If the supervisor rejects the two-dimensional `m_launcherPayload[2][0x40]` spelling, use two target-local `char[0x40]` field names while keeping support prose mode-dependent.
- If the supervisor rejects all provisional helper/field names, do not leave the page as simple no-code. Insert an explicit no-code proof stating that first-draft C++ is ready in this B010 report but was deferred only because the neutral payload field spelling or helper name was not accepted.

## Recommended Target-Page Implementation Checklist

Only after supervisor implementation callback:

1. Lease each file immediately before editing and release leases immediately after validation. Do not edit generated files, project-level generated files, manual coverage reports, validator/tool state, or IDA DB.
2. Update target metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
3. Insert the formal C++ block above, or the explicit no-code proof only if the supervisor rejects the provisional names.
4. Update the target item summary to mention first-draft `RegistryConfig.cpp` helper C++, skipped selector/no brand comparison, host/port/two-payload layout, corrected seven-byte successor padding, current MCP session `80de0a67`, and no direct xref/pointer route.
5. Fix the boundary prose: predecessor gap is six `0xcc` bytes at `0x0049050a-0x00490510`; successor gap is seven `0xcc` bytes at `0x00490809-0x00490810`.
6. Replace or extend the 2026-06-15 verification section with current MCP evidence from this report: health/session, raw non-function lookups, boundary bytes, zero xrefs, zero VA/RVA pattern hits, failed decompile, unique signature, and raw CP949 failure-format bytes.
7. Add field table notes for `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, `m_startupConnectionMode`, and mode-dependent payload slots at `+0x28d9e0/+0x28da20`.
8. Add rejected alternatives from this report: not `NWind`-named, not confirmed class method, not separate network module, not compiler glue/no-code, not final semantic payload names.

## Recommended Support-Doc Updates

Only after supervisor implementation callback:

- `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`: update the [UID:0002BL] child row to state that first-draft C++ is ready as `ParseLauncherHostPortPayload(RegistryConfig *config)`, the first token is skipped rather than compared, the next four tokens are host/port/payload/payload, and the target has seven `0xcc` bytes before `0x00490810`.
- `by-file/RegistryConfig.md`: add [UID:0002BL] beside the existing parser helper notes as a file-static/config-adjacent helper candidate; do not claim a confirmed class method. Add payload-slot prose that `+0x28d9e0/+0x28da20` are mode-dependent launcher payload/session slots for [UID:0002BK], [UID:0002BL], and [UID:0002BO], with [UID:0002BJ]/[UID:0002BN] overlay caveats.
- `by-class/RegistryConfig.md`: add the same class-scope caveat and startup field inventory refinement for the two payload slots. Keep the helper out of confirmed class-method status.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: refine the global config field notes for `+0x28d9e0/+0x28da20` as mode-dependent launcher payload/session slots and keep `+0x2916c4` as `m_startupPort` for this target.
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`: split/refine the current `0x0061701c` row so `0x0061701c` is the ANSI `NWind` caption and `0x00617024` is the raw CP949 `%s` host/input-error format used by [UID:0002BL] at `0x004907c0`. Record that `get_string` returns no string object at `0x00617024`, so the bytes/role are stronger evidence than IDA string typing.

Generated/project-level/manual coverage files:

- Do not hand-edit generated trackers, project-level generated files, or manual coverage reports.
- If implementation is accepted, rely on the validator/executed-report workflow for generated refreshes and tracker movement.

Validators after implementation:

- Run scoped validators from `source-3/project-documentation` for every changed by-* file.
- Record validator command IDs, timestamps, exit codes, and `ok` counts in the implementation callback response.
- Supervisor-only after verification: execute/archive the report through the executed-report lifecycle. B010 should not manually move this report into executed research during report-only work.

## Score Rationale

`COMPLETION:88` is appropriate because current live MCP now resolves the exact body shape, token layout, raw boundaries, corrected successor padding, numeric and DNS host paths, state writes, two payload outputs, failure bytes, owner route, field names, and first-draft formal C++.

Do not raise above `88` yet because no dispatcher/caller route, direct xref, stored VA/RVA pointer, or brand selector comparison has been recovered, and the two payload slots still require neutral mode-dependent names.

`CONFIDENCE:90` is appropriate because the behavior is independently supported by disassembly, boundary bytes, string/byte refs, xref absence, pointer-pattern absence, parent/sibling parser context, accepted RegistryConfig field naming, and a unique range signature.

Do not raise to final-audit confidence because IDA still has no function object at `0x00490510`, Hex-Rays decompilation fails at the raw start, and the original source dispatcher/helper name remains unrecovered.

## Implementation Tracking Checklist

- [x] Lease discipline followed. Initial B010 lease batch covered the target page, `g_pConfig`, and string-data page; the aggregate/by-file/by-class docs were still leased by B008 until `2026-06-27T15:19:11Z`, so B010 edited only the files it held, then later leased the remaining support batch after B008's lease expired. B010 released all active support leases after validation; `tools/leaser/Agents/current_leases.md` showed no active B010 rows after cleanup.
- [x] Target metadata and routing applied in `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md`: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Formal first-draft C++ inserted in the target `RECONSTRUCTION_CPP CODE:BEGIN/END` block as file-static `ParseLauncherHostPortPayload(RegistryConfig *config)`.
- [x] Target summary, boundary prose, current MCP evidence, field table, and rejected alternatives applied in `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md`: skipped selector/no brand comparison, current MCP session `80de0a67`, no direct xref or stored VA/RVA pointer route, six-byte predecessor padding, corrected seven-byte successor padding, failed decompile, unique signature, CP949 host/input-error bytes, startup fields, and `NWind` caption-only caveat.
- [x] Aggregate support doc updated in `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`: [UID:0002BL] child row and source reconstruction notes now state first-draft `ParseLauncherHostPortPayload(RegistryConfig *config)`, skipped selector, host/port/payload/payload layout, seven-byte successor padding, mode-dependent payload slots, no confirmed class-method status, and aggregate C++ remains blank.
- [x] File support doc updated in `by-file/RegistryConfig.md`: [UID:0002BL] is included in command-line/session helper notes as file-static/config-adjacent `ParseLauncherHostPortPayload(RegistryConfig *config)`, with no confirmed class-method claim, payload-slot prose for `+0x28d9e0/+0x28da20`, and [UID:0002BJ]/[UID:0002BN] overlay caveats.
- [x] Class support doc updated in `by-class/RegistryConfig.md`: [UID:0002BL] is included in class-scope helper and ownership notes while remaining file-level/config-adjacent; startup field inventory now includes the mode-dependent payload/session slot pair and keeps the helper out of confirmed class-method status.
- [x] Global config support doc updated in `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: `+0x28d9e0/+0x28da20` are documented as mode-dependent launcher payload/session slots for [UID:0002BK], [UID:0002BL], and [UID:0002BO], with [UID:0002BJ]/[UID:0002BN] overlay caveats; `+0x2916c4` remains normal `m_startupPort` for [UID:0002BL].
- [x] String-data support doc updated in `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`: `0x0061701c` is split/refined as ANSI `NWind` caption, and `0x00617024` is documented as raw CP949 `%s` host/input-error format used by [UID:0002BL] at `0x004907c0`, with `get_string` no-object caveat.
- [x] Manual edit exclusions followed: no generated reports, generated C++ output, project-level generated files, manual `-coverage-report.md`, validator/tool state, IDA DB, or unrelated docs were hand-edited.
- [x] Target validator run: `python .\tools\validator.py --mode file --file by-memory\0x00490510-0x00490809.LauncherHostPortPayloadParser.md --apply --queue-timeout 240 --wait-generated`; `command_id:000000004169`, `command_timestamp:2026-06-27T11:19:30-04:00`, exit code `0`, `ok:1`, generated refresh `completed` with matching `generated_refresh_command_id:000000004169`.
- [x] Support validators run: aggregate `command_id:000000004176`, by-file `000000004177`, by-class `000000004178`, `g_pConfig` `000000004179`, and string-data `000000004180`; all used `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240`, all exited `0`, all reported `ok:1`, and each support run reported generated refresh `deferred`.
- [x] Generated-output freshness checked: `auto-generated/NexusTK/config/RegistryConfig.cpp` is validator-owned, was not hand-edited, and its header shows `validator-command-id:000000004181`, `validator-refreshed-at:2026-06-27T11:24:37-04:00`, which is newer than the target/support validator commands. The generated file contains the `// UID:0002BL` block with `ParseLauncherHostPortPayload(RegistryConfig *config)` and the accepted `m_launcherPayload[0]` / `m_launcherPayload[1]` writes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002BL-LauncherHostPortPayloadParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002BL-LauncherHostPortPayloadParser-source-quality.md","timestamp":"2026-06-27T11:31:12","uid":"0002BL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
