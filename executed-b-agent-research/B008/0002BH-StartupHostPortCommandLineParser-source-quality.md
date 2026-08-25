** TARGET-REPORT-UID:0002BH **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BH StartupHostPortCommandLineParser Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0002BH] `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md` from blank-C++ `85/88` to source-ready `88/90` with formal first-draft C++.
- Final disposition: keep `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N4`; keep the helper file-level/config-adjacent under `RegistryConfig.cpp`, not a confirmed `RegistryConfig::` member method.
- Required action: after supervisor validation, update the target page and support notes in [UID:000220] `RegistryCommandLineParsers`, [UID:0000N4] `RegistryConfig` by-file, and [UID:0000BW] `RegistryConfig` by-class. Do not edit generated reports manually.
- Confidence: high for behavior, boundaries, field roles, file ownership, and source-ready draft shape; capped below final audit because the launcher dispatcher/caller route remains unrecovered and helper/static names are inferred.

## Target

- Assignment id: `B008-report-0002BH-StartupHostPortCommandLineParser-source-quality-20260627`
- Target UID: `0002BH`
- Target path: `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`
- Required report path: `tools/leaser/Agents/Agent-B008/research/0002BH-StartupHostPortCommandLineParser-source-quality.md`
- Source queue row: `auto-generated/-ag-research-tracker.md` still lists this under `## by-memory` -> `### Not-Covered Files - Reconstructable` as `80/86`, average `83.0`, reconstructable `true`. The source page is already `85/88`, so the generated tracker/coverage state is stale relative to the current by-memory doc and A002 validation notes.
- Current source metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, blank formal C++.

## Current Target State

The current target page already documents the raw host/port parser behavior: it searches `GetCommandLineW()` for UTF-16 `IP` and `PO` markers, skips a three-wide-character marker prefix, finds `&` terminators, copies the host to `RegistryConfig + 0x2915c4`, converts it to ANSI, resolves it with `gethostbyname`, copies four address bytes to `+0x2915b4`, parses the port into `+0x2916c4`, writes `+0x2916ca = 1`, and writes `+0x28de28 = 5`.

The page's remaining blockers are now stale as implementation blockers. The raw start and missing dispatcher still cap final confidence, but sibling parser pages [UID:0002BI], [UID:0002BJ], and [UID:0002BN] now show that file-static first-draft C++ is acceptable when the exact child is bounded, owned, emitter-routed, and uses documented inferred helper/member names.

## Evidence Checked

IDA MCP provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Listener check: `127.0.0.1:13337` responded; listener PID reported as `13684`.
- JSON-RPC flow used: `initialize`, `tools/list`, `tools/call`.
- Active database from `idb_list`: session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `26892`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

Read-only MCP checks performed:

- `lookup_funcs` on `0x0048eed0`, `0x0048f3f1`, `0x0048f400`, `0x0048f4cf`, `0x0048f4d0`, `0x0048f6cb`, `0x0048f6d0`, `0x0048fc96`, and `0x0048fca0`.
- `insn_query` over `0x0048f4d0-0x0048f6cb`, returning 151 decoded instructions with `fn:null`.
- `xrefs_to` on `0x0048f4d0`, `0x0048f6d0`, `0x0048fca0`, and `0x0048f400`.
- `find_bytes` for little-endian VA/RVA encodings `D0 F4 48 00`, `D0 F4 08 00`, `CB F6 48 00`, `D0 F6 48 00`, and `D0 F6 08 00`.
- `get_bytes` around `0x0048f4c0`, `0x0048f6b8`, `0x0048f6cb`, `0x0061693c`, `0x00616970`, `0x00616978`, `0x00616980`, and `0x0066d468`.
- `get_string`, `get_int`, and `xrefs_to` on marker/message/data addresses `0x00616970`, `0x00616978`, `0x00616980`, `0x0061693c`, `0x0066d468`, and relevant IAT/messagebox/quit cells.
- `make_signature_for_range` on `0x0048f4d0-0x0048f6cb`, which returned a unique signature.
- `callees` and `analyze_function` on `0x0048f4d0`, both returning no function found, confirming the raw-start limitation.

Documentation and generated sources checked:

- Target: `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`.
- Required support docs: `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, `by-file/RegistryConfig.md`, and `by-class/RegistryConfig.md`.
- Data support: `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`.
- Sibling C++ precedents: [UID:0002BI] `NetsgoStartupAuthenticationParser`, [UID:0002BJ] `ThrunetStartupAuthFileParser`, and [UID:0002BN] `ComBackedLauncherAuthenticationParser`.
- Historical accepted reports: `executed-b-agent-research/B008/0002BI-NetsgoStartupAuthenticationParser-source-quality.md` and `executed-b-agent-research/B007/0002BG-CommandLineArgumentCounter-source-quality.md`.
- A002 notes for the 2026-06-15 score pass that raised `0002BH` to `85/88` while leaving C++ blank.
- Generated state: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/config/RegistryConfig.cpp`.
- Proposed source tree: `by-project-structure/proposed-source-tree.md` confirms `config/RegistryConfig.cpp` under the lower-level client configuration module.
- `project-level/-unresolved.md` still contains placeholder-name references from the target; no resolved alias page changed the source route.

No Wave2/Wave3 material was used as authority. `source-3/simroot_v2` was not present in this workspace when searched, and current generated `RegistryConfig.cpp` was treated only as stale generated-output evidence.

## IDA MCP Facts

Function and boundary facts:

- `lookup_funcs` reports `sub_48EED0` at `0x0048eed0`, size `0x521`, and `sub_48FCA0` at `0x0048fca0`, size `0x550`.
- `lookup_funcs` reports `0x0048f4d0`, `0x0048f6cb`, and `0x0048f6d0` as not functions.
- The raw body begins at `0x0048f4d0` with `push ebp; mov ebp, esp; sub esp, 2FCh`, stack-cookie setup, saved `ecx`, `MemoryMan::GetMemoryMan()` candidate call `sub_516030`, and `GetCommandLineW`.
- `0x0048f4cf` is one `0xcc` byte before this raw start. `0x0048f6cb-0x0048f6d0` is five `0xcc` bytes before the raw successor `0x0048f6d0`, which begins a separate prologue.
- `make_signature_for_range 0x0048f4d0-0x0048f6cb` returned `unique:true`.

Marker and string facts:

- `0x0048f4ff` pushes `0x00616970`; raw bytes at `0x00616970` are UTF-16 `IP`.
- `0x0048f52f` pushes `0x00616978`; raw bytes at `0x00616978` are UTF-16 `PO`.
- IDA's `get_string` renders those marker addresses as only `I` and `P`, so raw-byte decoding is the reliable evidence for the UTF-16 two-character markers.
- `0x0048f65a` pushes `0x00616980`; raw bytes begin with UTF-16 `Unitel Relay` and include the visible `host : "%s" err : %d)` format tail.
- `0x0048f6a3` pushes `off_66D468`. `get_int 0x0066d468 u32le` resolves to pointer `0x0061693c`; `xrefs_to 0x0061693c` has the data xref from `0x0066d468`. The data support page identifies this as the Unitel-only startup alert message.

Behavior facts:

- `0x0048f505` calls `_wcsstr` for `IP`, `0x0048f517` advances six bytes, and `0x0048f51d` finds `&`.
- `0x0048f535` calls `_wcsstr` for `PO`, `0x0048f547` advances six bytes, and `0x0048f54d` finds `&`.
- Missing `IP`, missing first `&`, or missing `PO` jumps to the Unitel-only message path at `0x0048f692`. Missing the port `&` jumps directly to `0x0048f6bc`, the `PostQuitMessage`/`__loaddll` path without the message-box setup.
- `0x0048f573` copies the host bytes to `config + 0x2915c4`; `0x0048f585` terminates the wide host; `0x0048f5c2` calls `WideCharToMultiByte`; `0x0048f5e2` calls `gethostbyname`.
- On DNS success, `0x0048f600` calls `sub_516220` with four bytes from `hostent->h_addr_list[0]` to `config + 0x2915b4`.
- `0x0048f613` copies the port substring into the local stack buffer; `0x0048f61a` terminates it; `0x0048f623` calls the Visual C wide integer converter; `0x0048f62e` stores the result to `config + 0x2916c4`.
- `0x0048f636` writes word `1` to `config + 0x2916ca`; `0x0048f63f` writes byte `5` to `config + 0x28de28`.
- DNS failure calls `WSAGetLastError` at `0x0048f652`, formats the Unitel Relay lookup failure at `0x0048f65a-0x0048f66b`, then uses the common message-box/quit path.
- Oversized ANSI conversion reaches `___report_rangecheckfailure` at `0x0048f68d`.

Negative route facts:

- `xrefs_to` reports zero xrefs to `0x0048f4d0`, `0x0048f6d0`, `0x0048fca0`, and `0x0048f400`.
- `find_bytes` reports zero matches for both VA/RVA encodings of `0x0048f4d0` and `0x0048f6d0`.
- `callees` and `analyze_function` cannot analyze `0x0048f4d0` because no IDA function exists there. This is a current IDA modeling limitation, not evidence that the bytes are non-source.

## Heuristic / Inference Reanalysis And Validation

Source-facing helper name:

- Best current name: `ParseUnitelRelayStartupHostPort(RegistryConfig *config)`.
- Confidence: strong inferred source-facing name, not original-symbol proof.
- Evidence: Unitel-only failure string pointer at `off_66D468`, `Unitel Relay` host lookup format at `0x00616980`, `IP`/`PO` command-line markers, and sibling parser names by vendor/launcher path: `ParseNetsgoStartupAuthentication`, `ParseThrunetStartupAuthenticationFile`, and `ParseExciteGameLauncherAuthentication`.
- Rejected: keeping `StartupHostPortCommandLineParser` as final source spelling. It is a useful documentation title but too generic now that the Unitel marker/failure route is known.
- Rejected: `RegistryConfig::ParseUnitelRelayStartupHostPort()` as the current emitted form. The incoming `ecx` is a config/startup-state pointer, but there is still no direct caller/selector/vtable route. Keep the file-static helper route until the whole parser island is rehomed consistently.

Startup-state fields:

- `+0x2915b4`: `m_startupAddress[4]` / `m_startupIpAddress[4]`, high confidence. This target and siblings write resolved IPv4 bytes here.
- `+0x2915c4`: `m_startupHostName[128]`, high confidence. The host buffer is copied as wide text before ANSI conversion; the support docs already establish the 128-wide-character field.
- `+0x2916c4`: `m_startupPort`, high confidence for this target. The store is a dword parsed from the `PO` field; [UID:0002BN] remains the documented overlay case where the same offset stores a COM token/context.
- `+0x2916ca`: `m_startupReady`, high role confidence. This target writes word `1`; [UID:0002BG] and terminal consumers show it is not an argument count.
- `+0x28de28`: `m_startupConnectionMode`, high confidence. This target writes mode byte `5`, matching the launcher/auth success mode family.

Global/helper names:

- `0x00616970`: source constant `L"IP"` / local `kUnitelIpMarker`.
- `0x00616978`: source constant `L"PO"` / local `kUnitelPortMarker`.
- `off_66D468`: `kUnitelOnlyVersionMessage` pointer, already covered by [UID:000279].
- `0x00616980`: `kUnitelRelayHostLookupFailedFormat`.
- `sub_516030`: use existing source-facing `MemoryMan::GetMemoryMan()`.
- `sub_516220`: use existing source-facing `MemoryMan::MemmoveWrapper`.
- `sub_41B9B0`, `sub_4673E0`, `sub_4651D0`, `MessageBoxW`, `PostQuitMessage`, and `__loaddll`: express through inferred local abort helpers, as sibling parser C++ already does.

Mode selector relationship:

- The unresolved caller/dispatcher is not the same as `m_startupConnectionMode`. The binary writes `m_startupConnectionMode = 5` on success; the selector that decides to invoke this raw helper remains unrecovered.
- The missing dispatcher is now a confidence cap, not a no-code proof. Current sibling precedent accepts file-static C++ for bounded parser children with the same no-direct-route problem.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| The target is source-authored RegistryConfig startup parser code. | High | Raw prologue, command-line parsing, DNS, port/state writes, Unitel strings, parent island and RegistryConfig docs. | Checked runtime/helper alternatives; body is not pure CRT/COM glue and touches config startup state. | Direct dispatcher not found. |
| The helper should emit as `static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)`. | Strong inferred | Unitel Relay strings and local file-static parser naming used by accepted siblings. | Rejected generic documentation title and one-off class-method promotion. | Exact original name is not proven. |
| `+0x2916c4` is `m_startupPort` for this target. | High | `PO` marker substring is parsed through wide integer converter and stored at `0x0048f62e`. | Checked sibling overlay caveat; [UID:0002BN] is the exception, not this target. | Exact original field type/spelling remains inferred. |
| Missing dispatcher/caller does not block first-draft C++. | High | [UID:0002BI], [UID:0002BJ], and [UID:0002BN] use first-draft C++ with the same file-level route/no-direct-start caveat. | Checked xrefs and VA/RVA byte patterns; route remains absent. | Final audit still needs dispatcher recovery or a whole-island source reconstruction. |

## Ranked Ownership Analysis

### 1. [UID:0000N4] RegistryConfig file

- Evidence for: target writes RegistryConfig startup-state fields, sits in the parser island between RegistryConfig defaults and persistence, uses support strings owned by RegistryConfig, and the by-file page explicitly owns command-line/session parser helpers.
- Evidence against: no recovered dispatcher/caller and not proven as an original `RegistryConfig::` member method.
- Decision: keep as direct file-level owner/emitter.

### 2. [UID:0000BW] RegistryConfig class

- Evidence for: incoming `ecx` is a config/startup-state object and fields are class-like members.
- Evidence against: no direct caller, vtable route, stored function pointer, or whole-island class-method decision. Current support docs intentionally keep sibling parsers as file-level helpers.
- Decision: support doc should mention the helper, but do not assign the target directly to the class page.

### 3. New launcher/bootstrap module

- Evidence for: command-line/vendor-specific behavior could have come from a startup launcher source file.
- Evidence against: all durable side effects are RegistryConfig startup fields, support docs and proposed tree route this island under config, and no independent source-file evidence exists.
- Decision: reject for current implementation.

## Source Placement

Recommended placement is `NexusTK/config/RegistryConfig.cpp` as a private file-static helper:

`static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)`

If a later whole-island pass recovers the dispatcher and rehomes all parser helpers as private class methods, the equivalent member form would be `void RegistryConfig::ParseUnitelRelayStartupHostPort()`. Do not rehome only this one parser now.

## Range / Split / Padding Analysis

- No split is required.
- Source body: `0x0048f4d0-0x0048f6cb`, ending before the five-byte `0xcc` gap.
- Predecessor boundary: one `0xcc` byte at `0x0048f4cf` after [UID:0002BG].
- Successor boundary: five `0xcc` bytes at `0x0048f6cb-0x0048f6d0`; successor raw prologue begins at `0x0048f6d0`.
- Internal instructions all decode as part of one source-shaped parser; no nested data table or padding was found inside the range.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has owner/emitter [UID:0000N4], source metadata already clears the active code-entry average, and current research resolves the named helper/field blockers enough for source-style first draft.

Recommended exact formal insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t portText[12];
    char ansiHost[128];

    const wchar_t *commandLine = GetCommandLineW();

    const wchar_t *hostText = wcsstr(commandLine, L"IP");
    if (hostText == NULL)
        AbortWithLauncherMessage(kUnitelOnlyVersionMessage);

    hostText += 3;
    const wchar_t *hostEnd = wcschr(hostText, L'&');
    if (hostEnd == NULL)
        AbortWithLauncherMessage(kUnitelOnlyVersionMessage);

    const wchar_t *portStart = wcsstr(commandLine, L"PO");
    if (portStart == NULL)
        AbortWithLauncherMessage(kUnitelOnlyVersionMessage);

    portStart += 3;
    const wchar_t *portEnd = wcschr(portStart, L'&');
    if (portEnd == NULL)
        AbortLauncherStartupWithoutMessage();

    size_t hostLength = static_cast<size_t>(hostEnd - hostText);
    memmove(config->m_startupHostName,
            hostText,
            hostLength * sizeof(wchar_t));
    config->m_startupHostName[hostLength] = L'\0';

    int converted = WideCharToMultiByte(CP_ACP,
                                        0,
                                        config->m_startupHostName,
                                        static_cast<int>(hostLength),
                                        ansiHost,
                                        127,
                                        NULL,
                                        NULL);
    if (converted >= 128)
        __report_rangecheckfailure();
    ansiHost[converted] = '\0';

    hostent *host = gethostbyname(ansiHost);
    if (host == NULL)
    {
        AbortWithLauncherHostMessage(kUnitelRelayHostLookupFailedFormat,
                                     config->m_startupHostName,
                                     WSAGetLastError());
    }

    memoryMan->MemmoveWrapper(config->m_startupAddress,
                              host->h_addr_list[0],
                              4);

    size_t portLength = static_cast<size_t>(portEnd - portStart);
    memmove(portText, portStart, portLength * sizeof(wchar_t));
    portText[portLength] = L'\0';

    config->m_startupPort = _wtol(portText);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior preservation notes:

- The `IP`/`PO` search plus `+3` wide-character advance preserves the binary's six-byte advance after the two-character marker.
- Missing `IP`, missing host terminator, and missing `PO` use the Unitel-only message path; missing port terminator uses the message-less quit/load path.
- DNS failure preserves the `WSAGetLastError`-formatted Unitel Relay failure route.
- The code intentionally keeps `m_startupPort` as the normal host/port field and does not apply the [UID:0002BN] COM-token overlay to this target.
- Helper names are inferred source-facing names, not proven binary functions, matching accepted sibling parser style.

## Score And Metadata Recommendation

- Current source doc: `85/88`, owner `0000N4`, reconstructable `TRUE`, emitter `0000N4`, blank C++.
- Generated tracker/coverage row: stale `80/86`.
- Recommended source doc: `COMPLETION:88`, `CONFIDENCE:90`, owner `0000N4`, reconstructable `TRUE`, emitter `0000N4`, formal C++ populated as above.
- Reason for raise: current MCP rechecked raw-start status, exact boundary/padding, marker bytes/xrefs, DNS/port/state writes, failure paths, no xref/pointer route, and unique signature; support docs now resolve field names and sibling first-draft policy.
- Reason not higher: no direct dispatcher/caller route, no original symbol/source-file proof, and helper/message constants remain inferred.

## Recommended Target Doc Changes

Target path: `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`

Apply these facts:

- Metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
- Replace blank formal C++ with the exact formal C++ above.
- Update status/rebuild handling to say first-draft source C++ is now defensible despite the no-dispatch caveat.
- Add source-facing helper name `static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)`, with class-method alternative only as a future whole-island option.
- Update behavior/evidence with MCP session `80de0a67`, raw instruction count, no-function status, xrefs/pointer-search negatives, raw UTF-16 marker decoding, unique signature, and support-doc field names.
- Preserve negative evidence: no IDA function, no direct xrefs to `0x0048f4d0` or successor, no simple VA/RVA pointer byte matches.
- Add rejected alternatives: generic final name, class-method-only route, blank C++ because of dispatcher absence, treating `+0x2916c4` as COM token overlay, and trusting IDA's narrow string rendering for UTF-16 markers.

Suggested concise `Item Summary` replacement:

`Assigned to RegistryConfig; live MCP verifies the raw Unitel Relay IP/PO host-port parser, UTF-16 marker bytes, DNS and port paths, startup address/port/ready/mode writes, localized failure branches, exact padding, no direct xref/pointer route, unique signature, and first-draft RegistryConfig.cpp helper C++.`

## Recommended Support Doc Changes

Support path: `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`

- Update the [UID:0002BH] table row from generic host/port parser to Unitel Relay startup host/port parser.
- Add source reconstruction note parallel to [UID:0002BI]/[UID:0002BJ]/[UID:0002BN]: represent [UID:0002BH] as `static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)` under the current file-owned route; member-method equivalent only if the whole parser island is rehomed.
- Update the shared startup-state naming direction to mention [UID:0002BH] as a direct `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, and `m_startupConnectionMode` precedent.
- Keep aggregate formal C++ blank.

Support path: `by-file/RegistryConfig.md`

- In `Method Families` and `Command-Line Parser Source Placement`, add [UID:0002BH] as provisional `static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)`.
- Record Unitel Relay behavior: `IP`/`PO` marker extraction, DNS host lookup, normal `m_startupPort`, `m_startupReady`, and `m_startupConnectionMode = 5`.
- Preserve the file-level/config-adjacent route and no-direct-dispatch caveat.

Support path: `by-class/RegistryConfig.md`

- In `Ownership Notes`, add [UID:0002BH] as RegistryConfig-owned source logic currently represented as file-static `ParseUnitelRelayStartupHostPort(RegistryConfig *config)`.
- In `Startup Parser Field Inventory`, mention that [UID:0002BH] is a direct host/port precedent for `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, and `m_startupConnectionMode`.
- Do not change class metadata or promote the target to direct class ownership.

Generated output:

- `auto-generated/NexusTK/config/RegistryConfig.cpp` currently has header `validator-command-id: 000000004124`, `validator-refreshed-at: 2026-06-27T10:41:09-04:00`, but still lists `UID:0002BH` as `Completion:80 | Confidence:86 | Empty Emitter Marker`. After implementation, run scoped validators with generated refresh and treat continued stale generated values as a validator/generated-state issue, not a manual-edit target.

No manual coverage-report text is required. Do not edit `auto-generated/-ag-*` or any manual `-coverage-report.md`.

## Open Questions With Attempted Resolution

- Dispatcher/caller route: still unresolved. Current MCP xrefs and VA/RVA byte searches are negative; sibling parser docs show the same no-direct-route pattern. This caps confidence but does not block first-draft C++.
- Original helper name: unresolved. Best source-facing inference is `ParseUnitelRelayStartupHostPort`, supported by Unitel strings and sibling naming. Exact original symbol proof is unavailable.
- Class method versus file-static helper: unresolved at final-source level. Current implementation should stay file-static to match the parser island route.
- UTF-16 marker rendering: resolved by raw bytes. IDA `get_string` renders only the first narrow character at `0x00616970`/`0x00616978`, so the report and docs should cite raw bytes for `IP`/`PO`.

## Implementation Validator Results

Validators were run from `source-3/project-documentation` after the accepted edits:

| File | Command | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md` | `python .\tools\validator.py --mode file --file by-memory\0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md --apply --queue-timeout 240 --wait-generated` | `000000004136` | `2026-06-27T10:57:01-04:00` | 0 | 1 | `completed`, `generated_refresh_command_id: 000000004136` |
| `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` | `python .\tools\validator.py --mode file --file by-memory\0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240 --wait-generated` | `000000004137` | `2026-06-27T10:57:18-04:00` | 0 | 1 | `completed`, `generated_refresh_command_id: 000000004137` |
| `by-file/RegistryConfig.md` | `python .\tools\validator.py --mode file --file by-file\RegistryConfig.md --apply --queue-timeout 240 --wait-generated` | `000000004138` | `2026-06-27T10:57:33-04:00` | 0 | 1 | `completed`, `generated_refresh_command_id: 000000004138` |
| `by-class/RegistryConfig.md` | `python .\tools\validator.py --mode file --file by-class\RegistryConfig.md --apply --queue-timeout 240 --wait-generated` | `000000004140` | `2026-06-27T10:57:48-04:00` | 0 | 1 | `completed`, `generated_refresh_command_id: 000000004140` |

Validator caveats observed, all outside this target's accepted scope: the aggregate/file/class support runs still report existing missing-ref warnings for `0003FW` / `0003FX`, and each generated refresh reports pre-existing registry stale/missing-file coverage entries. The edited files still passed with `ok: 1`.

Resume verification rerun on 2026-06-27, after confirming the implementation was already present, used the same scoped commands under a short B008 lease:

| File | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md` | `000000004148` | `2026-06-27T11:15:26-04:00` | 0 | 1 | `--wait-generated`; final generated header current at `000000004151` |
| `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` | `000000004149` | `2026-06-27T11:15:37-04:00` | 0 | 1 | `--wait-generated`; final generated header current at `000000004151` |
| `by-file/RegistryConfig.md` | `000000004150` | `2026-06-27T11:15:47-04:00` | 0 | 1 | `--wait-generated`; final generated header current at `000000004151` |
| `by-class/RegistryConfig.md` | `000000004151` | `2026-06-27T11:15:59-04:00` | 0 | 1 | `--wait-generated`; generated `RegistryConfig.cpp` header equals this command |

Resume-run caveats were unchanged and outside this target's accepted scope: existing missing-ref warnings for `0003FW` / `0003FX` on the aggregate/file/class support pages and pre-existing stale/missing-file autogen registry entries. All four edited files still passed with `ok: 1`.

Generated output freshness check:

- Read-only checked `auto-generated/NexusTK/config/RegistryConfig.cpp` after validation.
- Header now records `validator-command-id: 000000004140` and `validator-refreshed-at: 2026-06-27T10:57:48-04:00`, matching the final validator batch.
- The generated file now includes `// UID:0002BH | by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md | Completion:88 | Confidence:90` followed by `static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)`.
- The generated body includes the accepted Unitel Relay host/port code path: `L"IP"` / `L"PO"` marker searches, `+3` marker advances, `&` terminators, `WideCharToMultiByte`, `gethostbyname`, `AbortWithLauncherHostMessage(kUnitelRelayHostLookupFailedFormat, ...)`, `MemmoveWrapper(config->m_startupAddress, ...)`, `_wtol(portText)`, `m_startupReady = 1`, and `m_startupConnectionMode = 5`.
- No generated file was edited manually.
- Resume verification rerun refreshed the generated header to `validator-command-id: 000000004151` and `validator-refreshed-at: 2026-06-27T11:15:59-04:00`; the UID0002BH metadata and `ParseUnitelRelayStartupHostPort` body remain present.

## Changed Files

- Updated target: `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`
- Updated support: `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- Updated support: `by-file/RegistryConfig.md`
- Updated support: `by-class/RegistryConfig.md`
- Updated report checklist/proof: `tools/leaser/Agents/Agent-B008/research/0002BH-StartupHostPortCommandLineParser-source-quality.md`
- Generated output was refreshed by validator only; no generated files were edited manually.
- No manual coverage report, validator state/config, or project-level generated files were edited manually.
- No IDA DB edits made.
- Leases used only for the exact edited files during the accepted edit/validator/report-update batch.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: implementation callback accepted the report for [UID:0002BH] on 2026-06-27.
- [x] Update `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md` metadata to `88/90`, keep owner/emitter/reconstructable unchanged, and replace blank formal C++ with `ParseUnitelRelayStartupHostPort(RegistryConfig *config)`. Proof: validator `000000004136` reported `completion_update 0002BH ... 88`, `confidence_update ... 90`, `canonical_owner_update ... 0000N4`, and `autogen_registry_update ... blank -> block`.
- [x] Preserve current target state and actual evidence checked: MCP session `80de0a67`, raw no-function status, exact boundary/padding, 151 decoded instructions, marker bytes/xrefs, DNS/port/state writes, failure paths, no xref/pointer route, and unique signature. Proof: target page now has `2026-06-27 Source-Quality Verification` with each of these items.
- [x] Incorporate source-facing names and rejected alternatives: Unitel Relay helper name, `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, `m_startupConnectionMode`, inferred abort helpers, rejected class-method-only route, rejected blank-C++ deferral, and rejected COM-token overlay for `+0x2916c4`. Proof: target `Reconstruction Notes`, support field inventories, and generated `RegistryConfig.cpp` now use these names and preserve the rejected alternatives.
- [x] Update `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` child row and reconstruction notes for [UID:0002BH] as first-draft C++ ready while keeping aggregate C++ blank. Proof: validator `000000004137`, exit 0, `ok: 1`, generated refresh completed.
- [x] Update `by-file/RegistryConfig.md` command-line parser source-placement notes with `ParseUnitelRelayStartupHostPort(RegistryConfig *config)` and Unitel Relay field behavior. Proof: validator `000000004138`, exit 0, `ok: 1`, `reference_index_add 0002BH by-file/RegistryConfig.md`.
- [x] Update `by-class/RegistryConfig.md` ownership/field inventory notes for [UID:0002BH] without changing class metadata or direct owner route. Proof: validator `000000004140`, exit 0, `ok: 1`, `reference_index_add 0002BH by-class/RegistryConfig.md`.
- [x] Run the scoped validators listed in the validator plan with `--wait-generated`, and record command metadata/results. Proof: validator result table above records all four commands, IDs, timestamps, exit codes, `ok` counts, and generated-refresh state.
- [x] Confirm generated `auto-generated/NexusTK/config/RegistryConfig.cpp` freshness for [UID:0002BH]; if it remains stale after validation, report the validator/generated-state issue rather than editing generated files. Proof: read-only check found header `validator-command-id: 000000004140`, refreshed at `2026-06-27T10:57:48-04:00`, with `UID:0002BH | Completion:88 | Confidence:90` and `ParseUnitelRelayStartupHostPort` body present.
- [x] No manual coverage-report or validator-owned tracker text to apply. Proof: no manual coverage report, validator state/config, or project-level generated files were edited manually; generated refresh was validator-owned.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback assignment `B008-implement-0002BH-StartupHostPortCommandLineParser-source-quality-20260627`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target and three support docs include Unitel Relay behavior, helper/source placement, field names, negative route evidence, rejected alternatives, and support references.
- [x] Metadata/score/formal C++ changes applied or explicitly not applied with reason. Proof: target is `88/90`, owner/emitter/reconstructable unchanged, and formal C++ block populated; aggregate/class/file support metadata intentionally unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target history marks old blank-C++ deferral as superseded, while no-function/no-xref/no-pointer and dispatcher caveats remain in target/support docs.
- [x] Validators run and results recorded. Proof: validator result table above.
- [x] Generated report refresh completed by validator or stale generated state reported with evidence. Proof: generated `RegistryConfig.cpp` refreshed to `000000004140` and contains the accepted UID0002BH metadata/code, so no stale generated-state issue remains for this target.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; all accepted items were applied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002BH-StartupHostPortCommandLineParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002BH-StartupHostPortCommandLineParser-source-quality.md","timestamp":"2026-06-27T11:18:47","uid":"0002BH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
