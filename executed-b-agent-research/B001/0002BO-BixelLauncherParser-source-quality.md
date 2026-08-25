** TARGET-REPORT-UID:0002BO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002BO] BixelLauncherParser Source-Quality Report

Agent: Agent-B001  
Assignment: `B001-report-0002BO-BixelLauncherParser-source-quality-20260627`  
Target: `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`  
Mode: report-only research. No by-* docs, generated files, manual coverage reports, validator/tool state, or IDA DB state were edited.

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002BO] from `COMPLETION:85`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:90`.
- Metadata: keep `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, and blank `EMITTER_POSITION_OPTIONAL`.
- Source placement: keep this child as a file-static/config-adjacent parser under [UID:0000N4] `RegistryConfig.cpp`; do not promote it alone to a confirmed `RegistryConfig::` method.
- First-draft C++: insert formal child-level C++ as `static void ParseBixelLauncher(RegistryConfig *config)` if the supervisor accepts this report.
- Confidence: high for behavior, field writes, string refs, boundaries, owner/emitter route, and first-draft source shape; still capped below final audit because no direct dispatcher/caller/xref/stored pointer route to the raw start has been recovered.

The current target page correctly documents much of the local behavior, but its C++ disposition is now too conservative. The same blocker pattern was already resolved for accepted sibling parsers: raw no-function status and no direct dispatch pointer cap confidence, but they do not block child-level first-draft C++ when the body, owner, field writes, string anchors, and source-facing helper role are otherwise resolved.

## Current Target State

- Target path: `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, blank C++.
- Current owner/emitter route: [UID:0000N4] `by-file/RegistryConfig.md`, with [UID:000220] `RegistryCommandLineParsers` as the aggregate parser-island evidence page.
- Existing blocker carried by the target: final C++ was blank because the raw start has no modeled function object, no recovered caller/dispatcher route, and the source-facing helper name was described as pending whole-island audit.
- Current report disposition: those blockers were investigated in this pass. They remain confidence caps, not first-draft C++ blockers, because accepted sibling pages [UID:0002BK], [UID:0002BL], and [UID:0002BM] already use the file-static `Parse*Launcher(RegistryConfig *config)` pattern under the same evidence shape.

## MCP Status And Tooling Provenance

IDA MCP was mandatory and was available for the final evidence pass.

- JSON-RPC `initialize` succeeded against `http://127.0.0.1:13337/mcp`.
- `idb_list` returned exactly one active session, `398b87c1`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe.i64`, backend worker PID `2704`, not analyzing.
- `server_health` with `database=398b87c1` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- The current `tools/list` schema was checked before byte reads. The current `get_bytes` schema requires `regions`, so the earlier failed `addr`/`size` byte-read shape was discarded and redone with the active schema.
- A transient timeout occurred before the supervisor recheck; it is treated as busy/transient. This final report uses the subsequent responsive `398b87c1` checks only.
- No IDA edits, renames, comments, type changes, function definitions, patching, save operations, process restarts, or MCP restarts were performed.

MCP tools used: `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `get_string`, `decompile`, `make_signature_for_range`, and scoped `insn_query`.

## Evidence Checked

Target/support docs checked:

- `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`
- `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- `by-file/RegistryConfig.md`
- `by-class/RegistryConfig.md`
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- Accepted neighboring source-quality reports/docs for [UID:0002BK] `LgInternetSessionLauncherParser`, [UID:0002BL] `LauncherHostPortPayloadParser`, and [UID:0002BM] `MihosoftLauncherParser`.
- Project alias reports confirming `sub_516030` -> `GetMemoryMan` and `sub_516220` -> `MemoryMan::MemmoveWrapper` / `memmove` wrapper context.

Current MCP facts:

- `lookup_funcs` on `0x004910d0`, `0x00491445`, `0x00491446`, and `0x00491450` returns `Not a function`.
- Neighbor anchors remain `sub_490B10` at `0x00490b10`, size `0x5b0`, and `sub_4918E0` at `0x004918e0`, size `0x248`.
- `xrefs_to` returns zero xrefs to `0x004910d0`, `0x00491445`, `0x00491446`, and `0x00491450`.
- Literal refs are exact and local: `/Bixel` at `0x006171d0` has one data ref from `0x004911a5`; generic Bixel failure text at `0x006171e0` has one data ref from `0x00491394`; host-specific Bixel failure text at `0x00617238` has one data ref from `0x004913f3`.
- `find_bytes` finds zero matches for the little-endian VA/RVA pointer forms `d0 10 49 00`, `d0 10 09 00`, `45 14 49 00`, `50 14 49 00`, and `50 14 09 00`.
- `get_bytes` at `0x004910c0` shows sixteen `0xcc` bytes followed by the raw prologue `55 8b ec 81 ec ac 0a 00 00 a1 24 2f 67 00 33 c5`.
- `get_bytes` at `0x00491430` shows the failure-tail `PostQuitMessage` / `__loaddll` sequence, then `0xcc` padding before the successor raw prologue at `0x00491450`.
- `get_bytes` at `0x006171d0` gives the UTF-16LE `/Bixel` bytes.
- `get_bytes` at `0x006171e0` and `0x00617238` gives UTF-16LE Korean Bixel failure text and host-format text. `get_string` returns only `t` for both due IDA string typing, so the byte-level UTF-16LE role evidence is stronger than IDA's string object result.
- Manual byte decoding of the two Bixel text regions confirms the generic Bixel dedicated-client input-error text and the host/input-error format containing `%s`.
- `get_string` confirms delimiter strings: `0x0060de18` is `" "`, and `0x00612e38` is `"."`.
- `decompile` at `0x004910d0` fails with `Decompilation failed at 0x4910d0`, consistent with raw non-function status.
- `make_signature_for_range 0x004910d0-0x00491445` returns `unique:true`; the signature begins `55 8B EC 81 EC AC 0A 00 00 A1 ? ? ? ? 33 C5`.
- Scoped `insn_query` over `0x004910d0-0x00491445` returned 253 instructions, scanned 253, `truncated:false`.
- Numeric conversions cited below were checked with `tools/int_convert.py`: `0x400` is 1024, `0x3f` is 63, `0x40` is 64, `0x80` is 128, and `0xaac` is 2732.

Stale Wave2/Wave3 material: none was needed for the recommendation. Current support docs mention older generated-output gaps only as historical lead/context; this report uses current docs plus active IDA MCP evidence.

## Behavior Reconstruction

The body is a RegistryConfig startup launcher parser for the `/Bixel` command-line mode.

Command-line handling:

- `0x004910d0-0x00491104`: normal prologue, `0xaac` stack frame, security cookie setup, `ecx` saved in `ebx` as the startup/config object, `GetMemoryMan`, `GetCommandLineW`, and `_wcscpy_s` into a `0x400` wide-character stack command buffer.
- `0x00491109-0x00491138`: executable-path skip. It first looks for a quote and otherwise a space with `_wcschr`; missing tail returns quietly.
- `0x0049113e-0x0049119f`: `_wcstok_s` token loop using the space delimiter at `0x0060de18`. The body stores up to eight token slots. A missing first token is a generic Bixel input-error failure; reaching the token cap returns quietly; parsing proceeds only when exactly five non-null post-executable tokens were found.
- `0x004911a5-0x004911ba`: token 0 must case-insensitively match UTF-16 `/Bixel` at `0x006171d0`; mismatch is the generic Bixel input-error failure.

Accepted token layout:

| Token | Use |
| --- | --- |
| token 0 | `/Bixel` selector |
| token 1 | host token |
| token 2 | port token |
| token 3 | launcher payload 1 |
| token 4 | launcher payload 2 |

Host handling:

- Numeric host path at `0x004911cd-0x00491254`: if the first host wide character is in `'0'..'9'`, split the host token on `.` at `0x00612e38`, parse four decimal parts with the CRT wide decimal helper (`unknown_libname_24`, source-facing `_wtol`/wide decimal parse), and write the low byte of each octet to `config + 0x2915b4`. Missing any required octet returns quietly; extra octets are ignored after the fourth write.
- DNS host path at `0x00491259-0x004912e8`: copy the wide host to `config + 0x2915c4` through `MemoryMan::MemmoveWrapper`, write a wide NUL terminator, convert the host to an ANSI `0x80` scratch buffer with `WideCharToMultiByte`, range-check returned byte count `>= 0x80`, NUL-terminate, call `gethostbyname`, and copy four address bytes from `hostent->h_addr_list[0]` to `config + 0x2915b4`. DNS failure uses the host-specific Bixel input-error text at `0x00617238`.

Success writes:

- `0x004912ed-0x00491303`: parse token 2 with the same wide decimal helper and write `config + 0x2916c4`.
- `0x00491309`: write word `1` to `config + 0x2916ca`.
- `0x00491312`: write byte `5` to `config + 0x28de28`.
- `0x00491319-0x0049134c`: convert token 3 to multibyte at `config + 0x28d9e0` with `0x3f` byte output cap and explicit NUL at the returned count.
- `0x00491354-0x0049137b`: convert token 4 to multibyte at `config + 0x28da20` with the same `0x3f` cap and explicit NUL.

Failure paths:

- Generic failure at `0x00491394-0x004913e2`: format the UTF-16LE Bixel dedicated-client input-error text from `0x006171e0`, show `MessageBoxW`, then call `PostQuitMessage(0)` and `__loaddll(0)`.
- Host failure at `0x004913e7-0x0049143b`: format the UTF-16LE Bixel host/input-error format from `0x00617238` with the original host token, show `MessageBoxW`, then call the same quit/load-exit path.
- Range-check failure at `0x00491440`: `___report_rangecheckfailure` if ANSI host conversion returns at least `0x80`.

## Heuristic / Inference Reanalysis And Validation

### Source-facing helper name

Best current name: `static void ParseBixelLauncher(RegistryConfig *config)`.

Evidence:

- Sibling accepted parser names in the same source route are file-static `ParseLgInternetSessionLauncher`, `ParseLauncherHostPortPayload`, and `ParseMihosoftLauncher`.
- This body has an explicit `/Bixel` selector comparison before accepting the mode, unlike [UID:0002BL], whose name deliberately avoids a brand because no selector is compared there.
- The body operates on the incoming `ecx` config/startup object and writes the same RegistryConfig startup fields as the neighboring parser family.

Rejected alternatives:

- `BixelLauncherParser` as final source name: keep only as page title/search label. Local project style for accepted siblings uses verb-first `Parse*` helper names.
- `RegistryConfig::ParseBixelLauncher()`: plausible future source shape because `ecx` is the config object, but not confirmed. No direct call, vtable route, stored pointer route, or dispatcher edge currently proves class-method status, and rehoming only this child would conflict with the accepted sibling route.
- Blank/no-code because of raw start: rejected. The raw/no-dispatch state was attacked with current function lookup, xrefs, pointer scans, bytes, decompile failure, signature, and sibling comparison. It remains a confidence cap, not a C++ blocker.

### Field and helper names

Recommended source-facing fields:

| Offset | Recommended target/source use | Evidence and caveat |
| --- | --- | --- |
| `+0x2915b4` | `m_startupAddress[4]` / `m_startupIpAddress[4]` | Numeric and DNS branches both write four address bytes here. |
| `+0x2915c4` | `m_startupHostName[0x80]` | DNS branch copies the wide host here and the next field is `0x100` bytes later, matching 128 wide characters. |
| `+0x2916c4` | `m_startupPort` for this child | Token 2 is parsed as a wide decimal port. Support docs keep an overlay caveat because [UID:0002BN] uses the same offset as a COM token/context. |
| `+0x2916ca` | `m_startupReady` | Word write of `1`; same accepted startup-ready field as sibling parsers. |
| `+0x28de28` | `m_startupConnectionMode` | Byte write of `5`, matching the direct/no-COM startup parser family. |
| `+0x28d9e0` / `+0x28da20` | `m_launcherPayload[0][0x40]` and `m_launcherPayload[1][0x40]`, or equivalent target-local two-field spelling | Bixel and [UID:0002BL] write two `0x3f`-capped payload outputs plus NUL. Broader class docs should keep the slots mode-dependent because [UID:0002BK] uses them as LG session strings and [UID:0002BJ]/[UID:0002BN] overlay nearby storage differently. |

Recommended helper names:

- `GetMemoryMan` for `sub_516030`, already resolved in project alias docs and MemoryMan docs.
- `MemoryMan::MemmoveWrapper` or project-standard memmove wrapper for `sub_516220`, already resolved in MemoryMan docs.
- `_wtol` or `WideDecimalToLong` source-facing role for `unknown_libname_24` / `0x005cea43`; the ignored/runtime docs classify this as CRT `__wtol` support, not NexusTK product code.
- `CopyLauncherCommandLineTail`, `ApplicationGetMainWindowHandle`, and message/caption constants are source-facing reconstruction names for repeated command-line and UI formatting patterns. They must be documented as inferred if inserted before a whole-file helper extraction pass.

### Open questions with attempted resolution

- Caller/dispatcher route: current MCP found zero xrefs to the raw start and no stored VA/RVA pointer-byte matches. This remains unresolved, but it is no longer a C++ blocker because all checked siblings use the same file-static route under the same no-dispatch caveat.
- Original exact helper names: no original symbols were recovered. Use the best local source-facing names above and mark them inferred/provisional in target/support docs rather than keeping raw labels in formal C++.
- Payload semantic names: no non-parser consumer currently proves stronger names than the neutral launcher-payload pair. This report adopts the same target-local neutral spelling accepted by [UID:0002BL] and leaves broader class layout prose mode-dependent.
- Class-method versus file-static placement: direct method status remains unproven. Keep file-static until the whole parser island is rehomed consistently.
- String text transcription: IDA `get_string` misreads the two Bixel UTF-16LE message blocks as `t`; byte decoding proves their roles. Target docs should document roles and raw byte/string evidence instead of relying on IDA string objects.

## Positive Evidence Summary

- The exact raw range is bounded by `0xcc` padding and neighboring parser starts.
- The current session verifies no IDA function object at the start/end/successor, decompile failure at the raw start, and unique full-range signature.
- Scoped instruction evidence covers command-line extraction, token gating, `/Bixel` selector comparison, numeric IPv4 parsing, DNS resolution, port/state/payload writes, generic and host-specific failure paths, and range-check failure.
- Literal xrefs are exact and local to this range: `/Bixel`, generic Bixel input-error text, and host-specific Bixel input-error format.
- The target writes the same startup-state field family as accepted RegistryConfig parser siblings.
- Accepted sibling docs already resolve the same raw/no-dispatch blocker as a score cap rather than a C++ blocker.

## Negative / Counter-Evidence Summary

- No direct xrefs to `0x004910d0`, `0x00491445`, `0x00491446`, or `0x00491450`.
- No stored VA/RVA pointer-byte patterns for the target start/end/successor forms checked in current MCP.
- No Hex-Rays decompilation because IDA still does not model this raw start as a function.
- No original symbol, source filename, dispatcher name, or class-method proof was recovered.
- No stronger semantic payload-field consumer was recovered; therefore final broad class layout names must remain neutral/mode-dependent.

None of this negative evidence supports no-code handling. It only caps confidence and prevents a stronger class-method/source-route claim.

## Ranked Ownership And Source Placement

### 1. [UID:0000N4] `RegistryConfig.cpp` file-static helper

- Evidence for: parser island placement, incoming config object, shared RegistryConfig startup fields, support docs, exact sibling pattern, and string-data ownership.
- Evidence against: no direct dispatcher route or recovered original source symbol.
- Decision: accepted. Use `static void ParseBixelLauncher(RegistryConfig *config)`.

### 2. [UID:0000BW] `RegistryConfig` class method

- Evidence for: `ecx` is the config object and the body writes deep RegistryConfig fields.
- Evidence against: no direct call/vtable/pointer route and siblings are currently routed as file-level/config-adjacent helpers.
- Decision: plausible future rehome only if the whole parser island is rehomed consistently.

### 3. Separate launcher/networking module

- Evidence for: function performs command-line launcher and DNS work.
- Evidence against: it is embedded inside the RegistryConfig parser island and directly writes RegistryConfig startup state.
- Decision: rejected.

## Score And Metadata Recommendation

| Field | Before | After | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 85 | 88 | The score-limiting blocker was researched rather than deferred. Current MCP confirms raw status, exact xrefs/negative route evidence, boundary bytes, unique signature, scoped instruction behavior, string roles, field names, sibling pattern, and first-draft C++ readiness. |
| `CONFIDENCE` | 88 | 90 | Behavior, source placement, and draft source shape are strongly supported by current-session evidence and accepted sibling precedent. Confidence remains below final-audit level because original symbols and direct dispatcher/caller route are still absent. |
| `CANONICAL_OWNER` | `0000N4` | `0000N4` | RegistryConfig file route remains the best direct source owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored launcher parser logic. |
| `EMITTER_UIDS` | `0000N4` | `0000N4` | Child should emit through `RegistryConfig.cpp`, like accepted siblings. |
| Formal C++ | blank | nonblank | Raw/no-dispatch status is now a confidence cap, not a draft-C++ blocker. |

Support docs can remain at their current scores unless the supervisor decides Bixel support sync warrants a local score bump. This report's required support edits are detail/cross-reference updates, not new ownership changes.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a valid emitter route, clears the combined-score gate after this report, and has enough behavior/field/source-placement evidence for scoped child-level code.

Recommended formal `RECONSTRUCTION_CPP CODE:BEGIN` / `END` insertion text:

```cpp
static void ParseBixelLauncher(RegistryConfig *config)
{
    MemoryMan *memoryMan = GetMemoryMan();
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

    wchar_t *token = wcstok_s(argumentText, L" ", &tokenContext);
    tokens[0] = token;
    if (token == NULL)
    {
        wchar_t message[0x100];
        swprintf_s(message, _countof(message), kBixelInputErrorMessage);
        MessageBoxW(ApplicationGetMainWindowHandle(),
                    message,
                    ApplicationGetMessageCaptionW(),
                    0);
        PostQuitMessage(0);
        __loaddll(0);
        return;
    }

    int tokenCount = 0;
    do
    {
        ++tokenCount;
        if (tokenCount >= 8)
            return;

        token = wcstok_s(NULL, L" ", &tokenContext);
        tokens[tokenCount] = token;
    } while (token != NULL);

    if (tokenCount != 5 || _wcsicmp(tokens[0], L"/Bixel") != 0)
    {
        wchar_t message[0x100];
        swprintf_s(message, _countof(message), kBixelInputErrorMessage);
        MessageBoxW(ApplicationGetMainWindowHandle(),
                    message,
                    ApplicationGetMessageCaptionW(),
                    0);
        PostQuitMessage(0);
        __loaddll(0);
        return;
    }

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
            wchar_t message[0x100];
            swprintf_s(message,
                       _countof(message),
                       kBixelHostInputErrorFormat,
                       hostToken);
            MessageBoxW(ApplicationGetMainWindowHandle(),
                        message,
                        ApplicationGetMessageCaptionW(),
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

Implementation notes for the supervisor callback:

- `CopyLauncherCommandLineTail`, `ApplicationGetMainWindowHandle`, `ApplicationGetMessageCaptionW`, `kBixelInputErrorMessage`, and `kBixelHostInputErrorFormat` are source-facing reconstruction names. They must be documented as inferred/provisional unless the implementation pass finds stronger existing declarations.
- The code intentionally keeps the quiet-return behavior for missing command tail, token cap, and incomplete dotted IPv4 tokens.
- The code intentionally keeps the `0x3f` payload conversion cap with NUL write into a `0x40` payload slot.
- If the supervisor rejects `m_launcherPayload[2][0x40]`, use two target-local `char[0x40]` fields but preserve the same support-doc overlay caveat.
- Do not substitute raw labels such as `sub_516030`, `sub_516220`, `unknown_libname_24`, `unk_6171E0`, `unk_617238`, or `param_1` into formal C++.

## Recommended Target And Support Doc Changes

After supervisor validation and implementation callback, update these docs:

1. `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`
   - Change metadata to `COMPLETION:88`, `CONFIDENCE:90`.
   - Keep owner/emitter/reconstructable metadata unchanged.
   - Replace the blank-C++ rationale with the resolved conclusion: raw/no-dispatch status remains a score cap, not a C++ blocker.
   - Insert the formal first-draft `ParseBixelLauncher(RegistryConfig *config)` C++ block.
   - Update item summary/status/behavior/source-shape/evidence/score sections with current MCP session `398b87c1`, current schema-correct `get_bytes`, scoped `insn_query`, literal xrefs, and current negative route checks.

2. `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
   - Update the [UID:0002BO] child table row from bare `/Bixel` launcher parser to source-ready file-static `ParseBixelLauncher(RegistryConfig *config)`.
   - Add a source reconstruction note matching siblings: file-static/config-adjacent helper; no direct dispatcher/xref/pointer route; do not rehome it alone to a class method.
   - Add behavior details: `/Bixel` selector, host/port/two-payload layout, numeric/DNS host branches, Bixel generic and host-specific wide failure messages, `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, `m_startupConnectionMode = 5`, and two launcher payload slots.

3. `by-file/RegistryConfig.md`
   - Add [UID:0002BO] beside the existing parser helper notes as provisional `static void ParseBixelLauncher(RegistryConfig *config)`.
   - Preserve file-level/config-adjacent route and class-method caveat.
   - Update startup parser field inventory/change log so Bixel is an explicit positive user of the same startup address/host/port/ready/mode fields and the two mode-dependent launcher payload slots.

4. `by-class/RegistryConfig.md`
   - Add [UID:0002BO] to the command-line helper/method inventory with the same file-level caveat.
   - Add Bixel to the startup parser field inventory as a positive writer for `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, `m_startupConnectionMode`, and the two launcher payload slots.

5. `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
   - Expand the `0x006171d0` `/Bixel` row to cite [UID:0002BO] and selector comparison at `0x004911a5`.
   - Add rows for `0x006171e0` and `0x00617238` as the generic Bixel input-error text and host-specific Bixel input-error format, with xrefs `0x00491394` and `0x004913f3`.
   - Add a Bixel parser support subsection, parallel to the Mihosoft and LauncherHostPort support sections, warning that IDA `get_string` misreads these UTF-16LE Korean strings as `t`.

6. `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
   - Add a change-log/support-sync line for Bixel if the implementation touches this support page.
   - Existing field inventory already mentions [UID:0002BO] for the two payload slots; implementation should preserve or refine that at report-level detail rather than duplicating short summaries.

No manual `-coverage-report.md` edit is requested. Generated research/coverage state should be refreshed by validator/executed-report lifecycle commands, not manual row edits.

## Expected Validators After Implementation Callback

Run scoped validators from `source-3/project-documentation` after by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002BO-BixelLauncherParser-source-quality-removed.md](0002BO-BixelLauncherParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated C++ freshness matters after inserting the formal C++ block, the implementation pass should use `--wait-generated` on the target file validation or have the supervisor inspect generated command metadata after execution.

## Implementation Tracking Checklist

Implementation callback proof added by B001 on 2026-06-27.

- [x] Target doc `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`: updated metadata to `COMPLETION:88`, `CONFIDENCE:90`; kept `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, and blank emitter position. Proof: target header now has `88/90`; validator `000000004359`, `2026-06-27T13:19:44-04:00`, exit 0, `ok: 1`.
- [x] Target doc: replaced the blank-C++/raw-start blocker with the current conclusion that raw/no-dispatch status caps confidence but does not block child-level first-draft C++. Proof: target `Rebuild Handling`, `Reconstruction Notes`, `Score Rationale`, and `Changes` sections now state this explicitly.
- [x] Target doc: inserted formal `RECONSTRUCTION_CPP CODE` for `static void ParseBixelLauncher(RegistryConfig *config)` using source-facing names, not IDA/decompiler labels. Proof: target formal C++ block uses `GetMemoryMan`, `MemoryMan::MemmoveWrapper`, `_wtol`, `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, `m_startupConnectionMode`, and `m_launcherPayload`; raw labels are only mentioned as rejected alternatives/evidence labels, not emitted code.
- [x] Target doc: preserved current MCP session `398b87c1` evidence, including `idb_list`, `server_health`, current `tools/list` schema recheck, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `get_string`, `decompile`, `make_signature_for_range`, and scoped `insn_query`. Proof: target `Evidence` section now records session `398b87c1`, health/session data, schema-correct `get_bytes`, literal/xref checks, decompile failure, unique signature, and 253-instruction scoped `insn_query`.
- [x] Target doc: documented token layout, quiet-return cases, generic/host-specific failure cases, numeric/DNS host handling, port/ready/mode writes, and two payload conversions at report-level detail. Proof: target `Behavior` section now has accepted token table, quiet-return paragraph, numeric/DNS host field writes, failure paths, and two `0x3f`-capped payload conversions.
- [x] Target doc: documented field/helper-name decisions and rejected alternatives, including file-static route over class-method route, `ParseBixelLauncher` over page-title/raw names, and neutral `m_launcherPayload` pair over stronger unproven semantics. Proof: target `Reconstruction Notes` records the file-static decision, class-method caveat, source-facing fields/helpers, neutral payload names, and rejected raw/page-title alternatives.
- [x] Parent aggregate `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`: updated the child table and source reconstruction notes for [UID:0002BO] as source-ready `ParseBixelLauncher(RegistryConfig *config)`. Proof: aggregate child table, evidence list, source reconstruction note, and change log now include Bixel source-ready details; validator `000000004361`, `2026-06-27T13:19:51-04:00`, exit 0, `ok: 1`.
- [x] File doc `by-file/RegistryConfig.md`: added/updated [UID:0002BO] command-line parser source-placement notes and startup field inventory details. Proof: `Command-Line Parser Source Placement`, startup parser field table, and change log now include `ParseBixelLauncher`; validator `000000004363`, `2026-06-27T13:20:00-04:00`, exit 0, `ok: 1`.
- [x] Class doc `by-class/RegistryConfig.md`: added/updated [UID:0002BO] command-line helper and startup field inventory details while preserving file-level helper caveat. Proof: `Methods`, `Ownership Notes`, `Startup Parser Field Inventory`, and change log now include Bixel with file-level caveat; clean rerun validator `000000004394`, `2026-06-27T13:25:53-04:00`, exit 0, `ok: 1`.
- [x] String-data doc `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`: expanded `/Bixel` row and added generic/host-specific Bixel failure text rows with xrefs and IDA string-typing caveat. Proof: literal table has `0x006171d0`, `0x006171e0`, and `0x00617238` Bixel rows; `Bixel Launcher Parser Support` records `get_string` caveat; validator `000000004370`, `2026-06-27T13:20:29-04:00`, exit 0, `ok: 1`.
- [x] Global support doc `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: added Bixel support-sync/change-log line and preserved mode-dependent payload-slot caveats. Proof: field rows for `+0x2915b4`, `+0x2915c4`, `+0x2916c4`, `+0x2916ca`, and existing `+0x28d9e0/+0x28da20` include Bixel; change log has B001 support sync; clean rerun validator `000000004396`, `2026-06-27T13:26:07-04:00`, exit 0, `ok: 1`.
- [x] Do not edit any manual `-coverage-report.md` file or generated/project-level report by hand. Proof: no manual coverage-report file was edited; generated/project-level effects were validator side effects only (`projected_stats_update`, deferred generated refresh).
- [x] Run scoped validators listed above after implementation and record command, exit code, `command_id`, `command_timestamp`, `ok` count, generated-refresh state, and side effects. Proof: commands ran from `source-3/project-documentation`; every command exited 0 with `ok: 1`; generated refresh was `deferred` for every run; side effects included validator-owned `projected_stats_update` and reference/autogen registry updates as reported.
- [x] Supervisor verifies implementation claim by claim, then executes the report through validator lifecycle rather than manual moving. Proof: B001 did not manually move or execute this report and did not edit validator state; implementation is ready for supervisor verification and validator lifecycle execution.

## Final Checkpoint

- Report path: `tools/leaser/Agents/Agent-B001/research/0002BO-BixelLauncherParser-source-quality.md`
- Implementation changed docs: `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`, `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`.
- Generated/project-level/coverage files manually changed: none. Validator side effects reported `projected_stats_update` and deferred generated refresh; no manual `-coverage-report.md` edit was made.
- IDA DB changes: none.
- Leases used: B001 took short edit/validator leases for the six by-* docs, then a clean rerun lease for `by-class/RegistryConfig.md` and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`; final lease report after release showed no active B001 lease.
- Validators run: target `000000004359`, aggregate `000000004361`, file doc `000000004363`, class doc clean rerun `000000004394`, string-data doc `000000004370`, and global support clean rerun `000000004396`; all exit 0, `ok: 1`, generated refresh deferred.
- Score implemented: [UID:0002BO] `85/88 -> 88/90`.
- Owner/emitter implemented: no change, kept [UID:0000N4] `RegistryConfig`.
- C++ implemented: inserted first-draft formal file-static `ParseBixelLauncher(RegistryConfig *config)`.
- Remaining uncertainty: dispatcher/caller route and original exact symbol spelling remain unrecovered; they cap confidence below final audit but do not block child-level C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BO-BixelLauncherParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002BO-BixelLauncherParser-source-quality.md","timestamp":"2026-06-27T13:31:07","uid":"0002BO"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BO-BixelLauncherParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002BO-BixelLauncherParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
