** TARGET-REPORT-UID:0002BI **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BI NetsgoStartupAuthenticationParser Source-Quality Research

Date: 2026-06-19  
Agent: B008  
Target: `source-3/project-documentation/by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0002BI-NetsgoStartupAuthenticationParser-source-quality.md`  
Status: report-only; no by-* docs or `by-memory/-coverage-report.md` edited

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BI] in the `RegistryConfig.cpp` command-line/session parser family, raise the target to `COMPLETION:88`, `CONFIDENCE:90`, and populate first-draft C++ after the support docs gain the field/API names below.
- Best source-facing helper name: `ParseNetsgoStartupAuthentication`. Under the current file-owned parser-island model, use `static void ParseNetsgoStartupAuthentication(RegistryConfig *config)`. If the whole parser island is later rehomed as private class methods, the equivalent member signature is `void RegistryConfig::ParseNetsgoStartupAuthentication()`.
- The old "validation callback" blocker is resolved: `dword_69BE80` is the platform dispatch table slot installed from `KERNEL32!GlobalGetAtomNameW`, not a Netsgo-specific unknown callback. The parser validates a numeric global atom token by calling `GlobalGetAtomNameW((ATOM)atom, output, 0x80)` and comparing the resulting atom name against another token.
- The raw-start/no-function/no-xref issue does not prove no-code or dead code. It is a family-wide artifact across the parser island: the PE has no direct static xrefs to raw starts, but `resources/exported_data/master_function_list.json` lists `0x0048f6d0`, and the body is a coherent source-authored parser with shared startup-state side effects. Keep it reconstructable.
- First-draft C++ is ready. Remaining uncertainty is final original spelling for helper/field names and the missing dispatcher edge, not enough to block source-style code.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000N4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N4
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: populate with first-draft body below after support sync
```

## Target State Checked

- Target current metadata: `85/86`, owner/emitter [UID:0000N4] `RegistryConfig`, reconstructable, blank C++.
- Parent aggregate: [UID:000220] `0x0048f400-0x00491b28.RegistryCommandLineParsers`, `86/89`, owner/emitter [UID:0000N4].
- Current generated output marker: `auto-generated/NexusTK/config/RegistryConfig.cpp` contains an empty marker for [UID:0002BI].
- Manual coverage row is stale at `78%`; exact replacement text is included below and must remain supervisor-owned.

## Evidence Checked

- Governing docs: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, and `tools/leaser/Agents/Agent-B008/goal.md`.
- Target and support docs: [UID:0002BI], parent [UID:000220], siblings [UID:0002BG] through [UID:0002BR], `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, startup string data [UID:0003FV], adapter/helper string data [UID:0003FX], `OpenTerminalPane`, `TerminalSetupPane`, `Socket` lifecycle report references, `WideApiDispatchInit`, `WideApiDispatchTable`, `WideApiDispatchPointerTable`, `PlatformApi`, CRT formatting glue [UID:0000WO], CRT `_wtol` wrapper [UID:0001O5], and MemoryMan copy helper docs.
- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Local PE/Capstone checks: exact bytes, disassembly, call contexts, field writes, import table, absolute/rel32 reference scans, string decoding, master function list refs.
- IDA MCP/tooling status: no IDA MCP namespace or resources are available in this session; `tool_search` found no IDA tool. Existing live IDA facts in the by-* docs remain valid prior evidence, and this report adds local PE verification for the key open issues.
- `int_convert.py` was run individually for `0x5c6`, `0x191c`, `0x400`, `0x100`, `0x80`, all requested offsets, `0x3e8`, `0x0b`, and `0x0c`.

## Raw Bytes, Bounds, And Xrefs

- Exact target range: `0x0048f6d0-0x0048fc96`, size `0x5c6` / 1478 bytes.
- Stack allocation immediate: `0x191c` / 6428 bytes.
- Preceding bytes at `0x0048f6cb-0x0048f6d0`: five `0xcc` bytes.
- Target prologue bytes at `0x0048f6d0`: `55 8b ec b8 1c 19 00 00 e8 63 80 13 00 ...`.
- Normal return: `0x0048fc10`.
- Trailing padding at `0x0048fc96-0x0048fca0`: ten `0xcc` bytes before [UID:0002BJ] `ThrunetStartupAuthFileParser`.
- Local scan found zero direct `E8`/`E9` rel32 calls or jumps to `0x0048f6d0`.
- Local scan found zero little-endian absolute VA and zero RVA references to `0x0048f6d0`.
- The same local no-reference result holds for adjacent raw starts `0x0048f4d0` and `0x0048fca0`, matching existing IDA notes for the island.
- `resources/exported_data/master_function_list.json` and the combined test copy both list `0x0048f6d0` as `FUN_0048f6d0`.

Interpretation: the start has no ordinary static xref, but this is not a no-code target. The command-line parser family has the same raw-start/no-xref profile, and the body contains complete source-authored logic with error dialogs and shared startup-state writes.

## Token Shape And Exact Parser Semantics

The current target doc is directionally right but should be sharpened:

- The parser copies `GetCommandLineW()` to a local `0x400` / 1024-wide-character buffer.
- It locates the executable token boundary using quote handling first and space fallback second.
- It builds a reconstructed launch command line in a `0x100` / 256-wide-character buffer by seeding the wide literal at `0x00616ac0`, `L"Baram.exe "`, then appending every non-executable token separated by spaces. The current shorthand "`Baram.exe ... decoder`" should be replaced with this exact behavior.
- It tokenizes into fixed `0x100`-byte token slots, equivalent to `wchar_t tokens[12][128]`.
- The `0x0c` / 12 guard is the overflow guard while scanning. The exact-shape test at `0x0048f8b0` compares the copied-token index with `0x0b` / 11.
- Source-facing wording should say: expected shape is 12 tokens including the original executable token, or 11 launcher payload arguments after the executable. The existing "expected eleven-token shape" should be clarified to "eleven launcher arguments".

Resolved token roles by stack slot:

| Stack slot | Source token role | Evidence |
| --- | --- | --- |
| `[ebp-0x1904]` | original executable token | Copied first; not appended into the reconstructed `Baram.exe ` command. |
| `[ebp-0x1804]` | launcher argument 1, currently unused by this body | Tokenized and preserved in launch command. |
| `[ebp-0x1704]` | expected global-atom name | Compared to `GlobalGetAtomNameW` output at `0x0048fa0c-0x0048fa3f`. |
| `[ebp-0x1604]` | host token | Copied to `[ebp-0x104]` at `0x0048fa45-0x0048fa58`; used by dotted-IP/DNS paths. |
| `[ebp-0x1504]` | startup port token | `_wtol` at `0x0048fbaf`; low 16 bits stored as dword at `+0x2916c4`. |
| `[ebp-0x1404]` | Netsgo/server id token | `_wtol` at `0x0048fbbe`; low 16 bits stored as word at `+0x2916c8`. |
| `[ebp-0x1304]`, `[ebp-0x1204]`, `[ebp-0x1104]` | launcher payload tokens preserved in command line | No direct field use in this body. |
| `[ebp-0x1004]` | service marker | Compared with wide `netsgo` literal at `0x00616bc4`. |
| `[ebp-0x0f04]` | global atom integer token | `_wtol`, must be `> 0`, low 16 bits passed to `GlobalGetAtomNameW`. |
| `[ebp-0x0e04]` | browser/version token | `_wtol`, must be `>= 0x3e8` / 1000. |

Rejected alternatives:

- "Callback output from unknown Netsgo DLL": rejected. The call target is a copied Win32 import slot for `GlobalGetAtomNameW`.
- "Exactly 11 total tokens": rejected. The binary expects 11 launcher arguments after the executable, plus the executable token itself.
- "Fixed `Baram.exe ... decoder` literal": rejected. The only fixed prefix is `L"Baram.exe "`; remaining payload is reconstructed from parsed arguments.

## Global Atom Validation

The strongest source-quality improvement is resolving `dword_69BE80`.

Local import parsing shows:

| Address | Installed/imported target | Evidence |
| --- | --- | --- |
| `0x0060d260` | `KERNEL32.dll!GlobalGetAtomNameW` | PE import table. |
| `0x0041a3b1-0x0041a3b6` | copies `[0x0060d260]` to `[0x0069be80]` | `WideApiDispatchInit` NT-path table write. |
| `0x005996ea-0x005996f5` and `0x00599921-0x00599926` | duplicate raw/generated table writes | Local PE contexts mirror the platform dispatch initializer. |
| `0x0048f9f8` | `call dword ptr [0x0069be80]` | Target parser call site. |

Call-site semantics:

```asm
0048f9d9  lea     eax, [ebp-0xf04]
0048f9e0  call    0x005cea43          ; _wtol
0048f9e8  movzx   eax, ax
0048f9eb  lea     ecx, [ebp-0x304]    ; atomName[128]
0048f9f1  push    0x80
0048f9f6  push    ecx
0048f9f7  push    eax
0048f9f8  call    dword ptr [0x69be80]; GlobalGetAtomNameW
0048f9fe  test    eax, eax
0048fa00  je      validation_error
0048fa0c  lea     eax, [ebp-0x1704]   ; expected atom name token
```

Source-level interpretation:

```cpp
ATOM atom = static_cast<ATOM>(_wtol(tokens[10]) & 0xffff);
wchar_t atomName[128];
if (GlobalGetAtomNameW(atom, atomName, 128) == 0 ||
    wcscmp(tokens[2], atomName) != 0)
{
    AbortWithNetsgoStartupError(kNetsgoValidationCheckError);
}
```

Recommended naming:

- `dword_69BE80` should be documented and commented as `g_pfnGlobalGetAtomNameW` or `WideApiDispatchTable::GlobalGetAtomNameW`.
- Do not keep `dword_69BE80` as an unresolved callback in [UID:0002BI].
- Do not model a source-level `NetsgoValidateTokenCallback` function.

## Startup-State Field Names

Best current field-name recommendations:

| Offset | Binary access | Recommended field name | Confidence / rationale |
| --- | --- | --- | --- |
| `+0x2915b4` | four byte writes/copies | `m_startupAddress[4]` or `m_startupIpAddress[4]` | High. All host/port parser siblings write resolved IPv4 bytes here. |
| `+0x2915c4` | wide copy and terminator for DNS hosts | `m_startupHostName[128]` | High. Difference to `+0x2916c4` is `0x100` bytes, matching a 128-wide-character host buffer. |
| `+0x2916c4` | dword store of low 16 bits from token | `m_startupPort` | High. Same offset is port in [UID:0002BH], [UID:0002BK], [UID:0002BL], [UID:0002BM], [UID:0002BO], [UID:0002BP], and [UID:0002BR]. |
| `+0x2916c8` | word store of low 16 bits from token | `m_startupServerId` | Medium. It is a Netsgo-only 16-bit numeric token after the port token; exact original semantic label is not proven. Avoid stronger names like `m_worldId` unless another consumer appears. |
| `+0x2916ca` | word store `1`; byte-tested by `OpenTerminalPane` | `m_startupReady` | High for role, medium for exact type. Binary writes a word here; consumers may test the low byte. |
| `+0x2916f0` | `_wcscpy_s(..., 0x100, launchCommand)` | `m_netsgoLaunchCommand[256]` or `m_startupLaunchCommand[256]` | High. This target alone copies the reconstructed `Baram.exe ` command into the shared config object. |
| `+0x28de28` | byte store `5` | `m_startupConnectionMode` | High for mode-selector role. Sibling launchers also write value `5`; socket/terminal docs show the same config byte gates connection/terminal modes. |

Rejected field interpretations:

- `+0x2916ca` as the only startup state: rejected. It is a ready flag; `+0x28de28` is the mode selector.
- `+0x2916f0` as a fixed resource string: rejected. It receives a reconstructed command line from stack.
- `+0x2916c8` as a 32-bit field: rejected for this body. The store is explicitly `mov word ptr [ebx+0x2916c8], si`.
- `+0x28de28` as terminal-only COM-port setup: rejected for this parser. Terminal setup also uses nearby persisted configuration, but all launcher/auth parser success paths write this byte as startup connection/auth mode.

## Host, Port, And Success Behavior

Endpoint handling:

- Host token copied from `[ebp-0x1604]` into `[ebp-0x104]`.
- If the first character is decimal, the parser loops four times:
  - `_wtol(component)` at `0x0048fa87`;
  - writes the low byte to `config + 0x2915b4 + i`;
  - finds the next `.` through `0x005ca50d`.
- If nonnumeric:
  - it copies and terminates the host wide string at `config + 0x2915c4`;
  - converts through `WideCharToMultiByte` into a `0x100` / 256-byte stack buffer;
  - rejects output length `>= 0x100`;
  - calls WSOCK32 ordinal 52, `gethostbyname`;
  - copies four bytes from `hostent->h_addr_list[0]` to `config + 0x2915b4`.

Success tail:

```asm
0048fba8  lea eax, [ebp-0x1504]
0048fbaf  call 0x005cea43       ; _wtol(port token)
0048fbb4  movzx edi, ax
0048fbb7  lea eax, [ebp-0x1404]
0048fbbe  call 0x005cea43       ; _wtol(server/id token)
0048fbc3  movzx esi, ax
0048fbcd  lea eax, [ebx+0x2916f0]
0048fbd9  call 0x005cd657       ; wcscpy_s-style copy
0048fbe6  mov word ptr [ebx+0x2916c8], si
0048fbed  mov dword ptr [ebx+0x2916c4], edi
0048fbf5  mov word ptr [ebx+0x2916ca], 1
0048fc00  mov byte ptr [ebx+0x28de28], 5
```

## Source Placement And Ownership

Keep the current target owner/emitter at [UID:0000N4] `RegistryConfig` for implementation consistency with the whole parser island. The source file route should be:

- `NexusTK/config/RegistryConfig.cpp`
- file-private command-line/session parser helper family under [UID:000220]
- platform API dependency through [UID:0000ML] `PlatformApi` for `GlobalGetAtomNameW`

High-probability member-method alternative:

- The binary calling convention stores incoming `ecx` as the config object and writes `RegistryConfig` fields. If a later parser-island source pass changes all startup parsers to class methods, this target should become `void RegistryConfig::ParseNetsgoStartupAuthentication()`.
- Do not change only this one target to class owner without a sibling/parser-island callback; otherwise support docs will become inconsistent.

Sibling parser interactions:

- [UID:0002BH] provides the direct host/port/state precedent and writes `+0x2915b4`, `+0x2915c4`, `+0x2916c4`, `+0x2916ca`, `+0x28de28`.
- [UID:0002BK]/[UID:0002BL]/[UID:0002BM]/[UID:0002BO]/[UID:0002BP]/[UID:0002BR] repeat the same endpoint/ready/mode pattern with different launcher brands and payloads.
- [UID:0002BJ] and [UID:0002BN] are richer auth/session variants; they support keeping [UID:0002BI] in the same launcher-auth parser family rather than extracting a Netsgo-only file.
- [UID:0002BG] only counts arguments/sets ready and should not absorb this body.

## First-Draft C++ Readiness

This target clears the current minimum C++ gate:

- `RECONSTRUCTABLE:TRUE`
- nonblank emitter [UID:0000N4]
- current average `(85 + 86) / 2 = 85.5`, and recommended average `(88 + 90) / 2 = 89`

It should get a source-style first draft after the target/support docs incorporate the names above. The draft should avoid raw offsets, raw compiler helper names, and unknown `dword_69BE80` language.

Recommended first-draft body:

```cpp
static void ParseNetsgoStartupAuthentication(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t launchCommand[256];
    wchar_t tokens[12][128];
    wchar_t atomName[128];
    wchar_t hostScratch[128];
    char ansiHost[256];

    int tokenCount = TokenizeLauncherCommandLine(GetCommandLineW(),
                                                 commandLine,
                                                 1024,
                                                 tokens,
                                                 12,
                                                 launchCommand,
                                                 256,
                                                 L"Baram.exe ");

    if (tokenCount > 12)
        AbortWithNetsgoStartupError(kNetsgoTooManyArguments);

    // Twelve total tokens means the executable token plus eleven launcher arguments.
    if (tokenCount != 12)
        AbortWithNetsgoStartupError(kNetsgoInputError2);

    if (wcscmp(tokens[9], L"netsgo") != 0)
        AbortWithNetsgoStartupError(kNetsgoOnlyServiceMessage);

    int atomValue = _wtol(tokens[10]);
    if (atomValue <= 0)
        AbortWithNetsgoStartupError(kNetsgoInvalidNumberMessage);

    int browserVersion = _wtol(tokens[11]);
    if (browserVersion < 1000)
        AbortWithNetsgoStartupError(kNetsgoBrowserVersionMessage);

    if (GlobalGetAtomNameW(static_cast<ATOM>(atomValue & 0xffff),
                           atomName,
                           128) == 0 ||
        wcscmp(tokens[2], atomName) != 0)
    {
        AbortWithNetsgoStartupError(kNetsgoValidationCheckError);
    }

    wcscpy_s(hostScratch, 128, tokens[3]);

    if (hostScratch[0] >= L'0' && hostScratch[0] <= L'9')
    {
        const wchar_t *part = hostScratch;
        for (int i = 0; i < 4; ++i)
        {
            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(part));

            if (i != 3)
            {
                const wchar_t *dot = wcschr(part, L'.');
                if (dot == 0)
                    AbortWithNetsgoStartupError(kNetsgoInputError3);
                part = dot + 1;
            }
        }
    }
    else
    {
        wcscpy_s(config->m_startupHostName, 128, hostScratch);

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            -1,
                                            ansiHost,
                                            256,
                                            0,
                                            0);
        if (converted <= 0 || converted >= 256)
            AbortWithNetsgoStartupError(kNetsgoInputError3);

        hostent *host = gethostbyname(ansiHost);
        if (host == 0 || host->h_addr_list == 0 || host->h_addr_list[0] == 0)
            AbortWithNetsgoStartupError(kNetsgoInputError3);

        memcpy(config->m_startupAddress, host->h_addr_list[0], 4);
    }

    config->m_startupPort = static_cast<unsigned short>(_wtol(tokens[4]));
    config->m_startupServerId = static_cast<unsigned short>(_wtol(tokens[5]));
    wcscpy_s(config->m_netsgoLaunchCommand, 256, launchCommand);

    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}
```

Notes for implementation:

- `TokenizeLauncherCommandLine` and `AbortWithNetsgoStartupError` are source-style helper names. They should be declared as local helpers or comments in support docs, not as proven exported symbols.
- If the target is emitted as a private class method instead of a file-static helper, replace `config->` with direct member access and move the parameter into `this`.
- `m_startupServerId` is the least certain field spelling. If support docs prefer `m_netsgoServerId`, use that consistently, but keep the "16-bit Netsgo numeric id" caveat.

## Recommended Target Doc Changes

Update [UID:0002BI] as follows:

- Change metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`.
- Replace "validation callback" language with `GlobalGetAtomNameW` dispatch slot evidence:
  - PE import `0x0060d260 = KERNEL32!GlobalGetAtomNameW`;
  - `WideApiDispatchInit` installs it into `0x0069be80`;
  - target calls it with `(ATOM)_wtol(token)`, output buffer, and `0x80`.
- Clarify token shape: 12 total tokens including executable, 11 launcher arguments after executable; token slots listed in this report.
- Replace fixed `Baram.exe ... decoder` wording with "reconstructs command line by prefixing `L\"Baram.exe \"` and appending the parsed non-executable arguments".
- Add the field table from this report with `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupServerId`, `m_startupReady`, `m_netsgoLaunchCommand`, and `m_startupConnectionMode`.
- Add source-facing signature note:
  - preferred current-doc route: `static void ParseNetsgoStartupAuthentication(RegistryConfig *config)`;
  - future class-method equivalent: `void RegistryConfig::ParseNetsgoStartupAuthentication()`.
- Add first-draft C++ body after support docs are updated.
- Add change-log entry:

```text
- 2026-06-19 B008 source-quality report: local PE/Capstone rechecked exact raw `0x0048f6d0-0x0048fc96` body, five-byte leading and ten-byte trailing padding, zero direct VA/RVA/rel32 refs to the raw start, master-function-list retention, token-slot layout, `Baram.exe ` command reconstruction, `netsgo` marker, `_wtol` gates, `GlobalGetAtomNameW` dispatch slot at `0x0069be80`, dotted-IP/DNS endpoint paths, success writes to `+0x2915b4/+0x2915c4/+0x2916c4/+0x2916c8/+0x2916ca/+0x2916f0/+0x28de28`, sibling parser field precedent, and first-draft C++ readiness. Recommended `88/90`, keep [UID:0000N4] owner/emitter.
```

## Recommended Support-Doc Changes

- [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
  - Add a source-quality note that the parser family uses shared startup-state fields `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, and `m_startupConnectionMode`.
  - Update the [UID:0002BI] child row/notes with `GlobalGetAtomNameW`, token layout, and first-draft readiness.
  - Keep the aggregate C++ blank as a mixed parser island, but do not use that blankness to block the exact child.

- [UID:0000N4] `by-file/RegistryConfig.md`
  - Add `ParseNetsgoStartupAuthentication` to the command-line/session helper list.
  - Clarify that `GlobalGetAtomNameW` is a PlatformApi dispatch dependency, not a RegistryConfig-owned callback.
  - Update generated-output notes: [UID:0002BI] is ready for source-style draft even if sibling raw parser helpers remain blank.

- [UID:0000BW] `by-class/RegistryConfig.md`
  - Add the startup-state field names above as provisional class-layout names.
  - Add the member-method alternative for parser helpers: `void RegistryConfig::ParseNetsgoStartupAuthentication()` if/when the parser island is class-owned.
  - Preserve the caveat that the current exact doc route keeps command-line helpers under the file UID until the sibling island is handled together.

- [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
  - Add Netsgo string anchors:
    - `0x00616ac0`: wide `Baram.exe ` prefix.
    - `0x00616bc4`: wide `netsgo` marker.
    - `0x00616a58`, `0x00616ad8`, `0x00616b40`, `0x00616bd4`, `0x00616c10`, `0x00616c58`, `0x00616cc0`, `0x00616d48`, `0x006169f0`: Netsgo-only localized failure messages and validation/browse/version diagnostics.
  - Keep Korean text summarized by role; no need to transcribe full strings unless another pass localizes them.

- [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`
  - Add exact row/evidence for `0x0069be80 = GlobalGetAtomNameW`, installed from IAT `0x0060d260` at `0x0041a3b1-0x0041a3b6`.
  - Note [UID:0002BI] as a concrete consumer.

- [UID:0002AS] `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`
  - Add the table slot `0x0069be80`, name `g_pfnGlobalGetAtomNameW`, installed target `GlobalGetAtomNameW`, known consumer [UID:0002BI].

- [UID:0000TQ] `by-global/WideApiDispatchTable.md`
  - Add the same `0x0069be80` row so consumer docs can stop declaring `dword_69BE80` locally.

- [UID:0000ML] `by-file/PlatformApi.md`
  - Add `GlobalGetAtomNameW` to the list of platform dispatch entries installed by `WideApiDispatchInit` and consumed by RegistryConfig's Netsgo parser.

- Optional sibling docs [UID:0002BH], [UID:0002BK], [UID:0002BL], [UID:0002BM], [UID:0002BO], [UID:0002BP], [UID:0002BR]
  - If touched later, align their startup-state field names with this report. This is a consistency cleanup, not a blocker for [UID:0002BI].

## Score Rationale

| Field | Recommendation | Rationale |
| --- | ---: | --- |
| Completion | `88` | Exact range, bytes, padding, local disassembly, token layout, platform dispatch callback identity, field roles, sibling relationships, support-doc routes, rejected alternatives, and first-draft C++ are resolved. |
| Confidence | `90` | Local PE/import/disassembly evidence and existing IDA-backed docs agree. Confidence stays below final because fresh IDA MCP was unavailable, the dispatcher edge remains absent, and original field/helper spellings are inferred. |

## Open Questions And Resolutions

| Question | Evidence checked | Resolution |
| --- | --- | --- |
| Is `0x0048f6d0` dead because there are no xrefs? | Local rel32/VA/RVA scans for target and adjacent raw starts; existing IDA no-xref docs; master function list. | Not dead/no-code. Treat as retained raw startup parser with unresolved dispatcher route, same as siblings. |
| Is `dword_69BE80` an unknown Netsgo callback? | PE import table, `WideApiDispatchInit` contexts, target call arguments. | No. It is `GlobalGetAtomNameW` in the wide API dispatch table. |
| Should the target be a `RegistryConfig` class method? | `ecx` object use, field writes, by-class and by-file docs, sibling island consistency. | High-probability member method, but keep metadata at file UID for now. Document member alternative and do not rehome only this child in isolation. |
| What is `+0x2916c8`? | Store width, token order, sibling docs. | Best provisional name `m_startupServerId`; exact original meaning not proven. |
| Should formal C++ remain blank? | Current gate, resolved callback, token layout, support routes. | No. Exact target is ready for first-draft C++ once accepted by supervisor. |

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` in this B pass. If accepted, replace the current [UID:0002BI] row with:

```markdown
        - [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) 0x0048f6d0-0x0048fc96 | raw unmodeled function | NetsgoStartupAuthenticationParser : reconstructable : 88% : very strong : B008 2026-06-19 source-quality recheck resolves this as the RegistryConfig-routed Netsgo startup authentication parser; local PE/Capstone confirms exact `0x5c6` / 1478-byte body, five-byte leading and ten-byte trailing padding, no rel32/VA/RVA refs to the raw start, master-function-list retention, 12-token shape including executable plus 11 launcher arguments, `Baram.exe ` command reconstruction, `netsgo` marker check, `_wtol` numeric/version gates including `>= 1000`, `dword_69BE80` resolved to the `GlobalGetAtomNameW` wide API dispatch slot, global-atom-name comparison against the validation token, dotted-IP/DNS host paths, success writes to `+0x2915b4/+0x2915c4/+0x2916c4/+0x2916c8/+0x2916ca/+0x2916f0/+0x28de28`, and first-draft C++ readiness with field names carried through RegistryConfig support docs.
```

## Validator Needs

Suggested implementation-callback validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002BI-NetsgoStartupAuthenticationParser-source-quality-removed.md](0002BI-NetsgoStartupAuthenticationParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only if the supervisor applies the coverage text:

> Executable block R002 was removed from this report and preserved verbatim in [0002BI-NetsgoStartupAuthenticationParser-source-quality-removed.md](0002BI-NetsgoStartupAuthenticationParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x0048f6d0` | Name/comment as `RegistryConfig_ParseNetsgoStartupAuthentication` or `RegistryConfig::ParseNetsgoStartupAuthentication` depending on final island ownership. | High for role, medium-high for exact spelling. |
| `0x0069be80` | Rename/comment as `g_pfnGlobalGetAtomNameW`; type `UINT (WINAPI *)(ATOM, LPWSTR, int)`. | Very high. |
| `0x0041a3b1-0x0041a3b6` | Comment as the `GlobalGetAtomNameW` dispatch-slot install from IAT `0x0060d260`. | Very high. |
| `[ebp-0x304]` | Local `atomName[128]`. | High. |
| `[ebp-0x504]` | Local `launchCommand[256]`. | High. |
| `[ebp-0x1904]..[ebp-0x0e04]` | Local `tokens[12][128]`. | High. |
| `config + 0x2915b4` | `m_startupAddress[4]` / `m_startupIpAddress[4]`. | High. |
| `config + 0x2915c4` | `m_startupHostName[128]`. | High. |
| `config + 0x2916c4` | `m_startupPort`. | High. |
| `config + 0x2916c8` | `m_startupServerId` / `m_netsgoServerId`; keep provisional. | Medium. |
| `config + 0x2916ca` | `m_startupReady`. | High. |
| `config + 0x2916f0` | `m_netsgoLaunchCommand[256]`. | High. |
| `config + 0x28de28` | `m_startupConnectionMode`. | High. |
| `0x00616ac0` | Comment as wide `Baram.exe ` prefix. | Very high. |
| `0x00616bc4` | Comment as wide `netsgo` marker. | Very high. |
| `0x005cea43` | Keep as CRT `_wtol` wrapper; do not assign to RegistryConfig. | Very high. |
| `0x0041b9b0` | CRT wide secure formatting wrapper; source should use normal formatted/copy APIs. | High. |
| `0x00516220` | MemoryMan-island `memmove` wrapper; source should use `memcpy`/`memmove` or string helpers as appropriate. | High. |
| `0x0060d528` / WSOCK32 ordinal 52 | Comment call consumer as `gethostbyname`. | High. |

## Implementation Readiness

Ready after supervisor review. The accepted implementation should update the target and support docs listed above, populate first-draft C++ on the exact target, preserve coverage-row text for supervisor-owned application, and run the scoped validators. No target/support docs were edited in this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002BI-NetsgoStartupAuthenticationParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002BI"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BI-NetsgoStartupAuthenticationParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0002BI-NetsgoStartupAuthenticationParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
