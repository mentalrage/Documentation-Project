** TARGET-REPORT-UID:0002BM **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BM MihosoftLauncherParser Source-Quality Report

## Report Status

- Agent: B003
- Assignment: `B003-report-0002BM-MihosoftLauncherParser-source-quality-20260627`
- Mode: report-only research first
- Target: [UID:0002BM] `by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md`
- Required disposition: supervisor validation before any by-* implementation edits
- Result: implementation-ready; not a fallback-only report

## Current Target State

- Current target metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:88`
  - `CANONICAL_OWNER:0000N4`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000N4`
  - formal C++ blank
- Current target summary already identifies a raw `Mihosoft` launcher parser with exact tokenization, DNS/IPv4 handling, localized failure paths, startup address/host/port writes, ready flag, and mode byte `5`.
- Current blockers listed by the target are now partially resolved by this pass:
  - Dispatcher/caller edge remains absent after direct MCP xref and pointer searches, but this is no longer a source-draft blocker because sibling parser pages already emit source-style first-draft C++ without direct caller edges.
  - Field names are now strong enough through [UID:0000N4], [UID:0000BW], [UID:00028Q], and sibling parser docs: `m_startupAddress`, `m_startupHostName`, `m_startupPort`, `m_startupReady`, and `m_startupConnectionMode`.
  - Payload-string uncertainty is resolved as not applicable to this target. Unlike [UID:0002BL] and [UID:0002BO], this body does not write the launcher scratch/payload buffers at `+0x28d9e0` or `+0x28da20`; it consumes only selector, host, and port tokens.
  - Formal first-draft C++ is defensible as a file-static `RegistryConfig.cpp` helper.

## Sources Reviewed

- Target:
  - `by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md`
- Parent/support:
  - `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` ([UID:000220])
  - `by-file/RegistryConfig.md` ([UID:0000N4])
  - `by-class/RegistryConfig.md` ([UID:0000BW])
  - `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` ([UID:00028Q])
  - `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md` ([UID:0003FV])
- Neighboring launcher/parser children:
  - `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md` ([UID:0002BH])
  - `by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md` ([UID:0002BI])
  - `by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md` ([UID:0002BJ])
  - `by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md` ([UID:0002BK])
  - `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md` ([UID:0002BL])
  - `by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md` ([UID:0002BN])
  - `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md` ([UID:0002BO])
- Helper/name support:
  - `project-level/-resolved-multple-aliases.md`
  - `by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md`
- Generated selection source:
  - `auto-generated/-ag-research-tracker.md` still lists [UID:0002BM] under `by-memory -> Not-Covered Files - Reconstructable` as `80/86`. This appears stale relative to the live target page's current `85/88`; do not edit the generated tracker manually.

## Live IDA MCP Provenance

- MCP endpoint: `127.0.0.1:13337`
- Server: `ida-pro-mcp`
- Active database session: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Health: `server_health` reported `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, and `strings_cache_ready: true`.

MCP/tool evidence checked:

- `lookup_funcs`
  - `0x00490810`, `0x00490b01`, and `0x00490b02`: not modeled functions.
  - `0x00490b10`: modeled sibling `sub_490B10`, size `0x5b0`.
  - Confirms [UID:0002BM] is a retained raw code body rather than an IDA-modeled function object.
- `xrefs_to`
  - Zero xrefs to `0x00490810`, `0x00490b01`, `0x00490b02`, and successor `0x00490b10`.
  - `0x00617048` `Mihosoft` literal has one target xref at `0x004908e4`.
  - `0x00617060` generic input-error text has one target xref at `0x00490a50`.
  - `0x006170b8` host-specific error format has one target xref at `0x00490aaf`.
  - `0x00612e38` UTF-16 dot delimiter has target xrefs at `0x00490923` and `0x00490957`, plus sibling parser xrefs.
  - `0x0060de18` UTF-16 space delimiter has target xrefs at `0x00490889` and `0x004908c1`, plus sibling parser xrefs.
- `find_bytes`
  - No VA/RVA/raw pointer hits for `0x00490810`, `0x00490b01`, `0x00490b02`, or `0x00490b10`.
  - This exhausts the reasonable pointer-route check for caller/dispatcher recovery in this pass.
- `get_bytes`
  - `0x00490809..0x0049080f` is `0xcc` padding before the target prologue.
  - `0x00490810` starts `55 8b ec 81 ec ac 0a 00 00 ...`, a normal frame/security-cookie prologue.
  - `0x00490b01..0x00490b0f` is `0xcc` padding before [UID:0002BN] at `0x00490b10`.
- `decompile`
  - `0x00490810` decompilation fails as expected because IDA does not model the raw start as a function.
- `insn_query`
  - Scoped `0x00490810..0x00490b01` returned a coherent 210-instruction raw body with no function metadata.
  - The instruction stream confirms exact tokenization, selector compare, dotted IPv4 parse, DNS branch, port/ready/mode writes, and failure paths.
- `entity_query`
  - No source symbols or named non-function entities were found in the parser island.
  - Modeled functions in the wider `0x0048f400..0x00491b30` island are only the already-known modeled siblings, not this target.
- `make_signature_for_range`
  - `0x00490810..0x00490b01` signature is unique, supporting exact range identity.
- Direct UTF-16 byte decoding
  - IDA string typing is partial for some of the Korean wide strings, so direct byte decoding was used for literal roles.
  - `0x00617048`: `Mihosoft`
  - `0x00617060`: generic dedicated-client/input-error message.
  - `0x006170b8`: dedicated-client/input-error format with `%s` host insertion.
  - `0x00612e38`: `.`
  - `0x0060de18`: space delimiter.

## Behavior Evidence

- Entry and local setup:
  - `0x00490810` starts a raw but complete stack-frame function.
  - `0x00490826` calls `sub_516030`, resolved in project aliases as `GetMemoryMan`.
  - `0x00490831` calls `GetCommandLineW`.
  - `0x00490844` copies the command line into a local wide buffer through `_wcscpy_s`.
  - `0x00490852` and `0x0049086e` scan for the quoted executable path/argument delimiter. Missing delimiter returns quietly at `0x00490a40`.
- Tokenization:
  - `0x00490889` and `0x004908c1` call `_wcstok_s` with the UTF-16 space delimiter at `0x0060de18`.
  - The loop stores up to eight post-executable tokens. If it reaches the eighth slot, it returns quietly rather than raising the localized input-error message.
  - Fewer than three tokens falls into the generic input-error path.
  - Token zero is compared case-insensitively against `Mihosoft` at `0x00617048` through `__wcsicmp`; mismatch uses the same generic input-error path.
- Host token:
  - Token one is the host/address string.
  - If the first character is decimal, the body tokenizes this host string on the UTF-16 dot delimiter at `0x00612e38`.
  - Each of four dotted components is parsed through `unknown_libname_24` / `_wtol`, and the low byte is written to `config + 0x2915b4 + index`.
  - If a dotted component is missing before four bytes are written, the function returns quietly.
  - Extra dotted components after the fourth are ignored, matching the sibling parser pattern.
- DNS/hostname token:
  - Nonnumeric hosts are copied as wide text to `config + 0x2915c4`, then terminated.
  - The copy path uses `sub_516220`, resolved in project aliases as the memory/memmove wrapper.
  - `WideCharToMultiByte(CP_ACP, ...)` converts exactly the host-length characters into a 128-byte ANSI stack buffer.
  - If the converted byte count is `>= 128`, the binary calls the MSVC range-check failure routine at `0x00490afc`.
  - The ANSI buffer is explicitly null-terminated at the converted length.
  - `gethostbyname` resolves the ANSI host; null return uses the host-specific localized format at `0x006170b8`.
  - On success, four bytes from `hostent->h_addr_list[0]` are copied to `config + 0x2915b4`.
- Port/state writes:
  - Token two is parsed through `_wtol` and stored at `config + 0x2916c4`.
  - `0x00490a30` writes word `1` to `config + 0x2916ca`.
  - `0x00490a39` writes byte `5` to `config + 0x28de28`.
- Failure paths:
  - Generic selector/count/input failure formats the text at `0x00617060`, shows a message box, posts quit, and enters the existing load/error helper path.
  - DNS failure formats the host-specific text at `0x006170b8` with token one, then follows the same message-box/quit/error route.

## Positive Evidence

- Boundary is exact:
  - Start is preceded by `0xcc` padding and a clear prologue.
  - End is followed by `0xcc` padding up to modeled sibling [UID:0002BN].
- Parent/source placement is strong:
  - The body sits inside the documented [UID:000220] RegistryConfig command-line/session parser island.
  - It uses the same startup state fields as the already source-emitting Netsgo, Thrunet, and COM-backed parser siblings.
  - It takes the RegistryConfig/startup-state pointer in `ecx`, matching sibling `RegistryConfig.cpp` helper shape.
- Field names are now strong enough for draft C++:
  - `+0x2915b4`: `m_startupAddress[4]`.
  - `+0x2915c4`: `m_startupHostName[128]`.
  - `+0x2916c4`: `m_startupPort` for this normal host/port parser, not the [UID:0002BN] COM token overlay.
  - `+0x2916ca`: `m_startupReady`.
  - `+0x28de28`: `m_startupConnectionMode`.
- Helper names are strong enough for draft C++:
  - `sub_516030`: `MemoryMan::GetMemoryMan()` / `GetMemoryMan`.
  - `sub_516220`: memory/memmove wrapper.
  - `unknown_libname_24` at `0x005cea43`: CRT `_wtol`.
  - `CopyLauncherCommandLineTail`, `AbortWithLauncherMessage`, and `AbortWithLauncherHostMessage` are already used or implied by sibling source-style parser drafts and are appropriate source-facing extraction helpers for this parser family.
- Payload-string blocker resolved:
  - There is no write to `+0x28d9e0`, `+0x28da20`, or other payload scratch fields in this body.
  - This target is selector/host/port only. Extra command-line tokens four through seven are ignored, and eight or more post-executable tokens cause a quiet return.

## Negative Evidence And Rejected Alternatives

- Rejected: treat [UID:0002BM] as a non-emitting raw island with blank C++.
  - Reason rejected: raw/no-function status is already true for source-emitting parser siblings such as [UID:0002BI] and does not by itself prevent scoped first-draft C++ when behavior, boundaries, owner, and field names are clear.
- Rejected: route through a new class method immediately.
  - Reason rejected: MCP finds no direct caller, dispatcher, vtable, or pointer route to the raw start. A file-static `RegistryConfig.cpp` helper is the least-claiming source placement and matches current sibling practice.
- Rejected: model token three or later as payload inputs.
  - Reason rejected: instruction evidence consumes only `tokens[0]`, `tokens[1]`, and `tokens[2]`; no later-token reads or payload-buffer writes exist in the scoped instruction range.
- Rejected: use raw names such as `sub_516220`, `unknown_libname_24`, `dword` fields, or address-named globals in formal C++.
  - Reason rejected: the project already has source-facing aliases and sibling field inventories for these roles. Raw compiler/IDA names should not appear in draft source when a realistic project-style name is available.
- Rejected: promote confidence to final-audit quality.
  - Reason rejected: original source symbol names and the dispatcher route remain unrecovered after MCP symbol/xref/pointer searches. These are confidence caps, not draft-C++ blockers.

## Heuristic And Inference Reanalysis

- Best source-facing helper name:
  - Recommended: `ParseMihosoftLauncher(RegistryConfig *config)`.
  - Rationale: the selector literal is exactly `Mihosoft`, the function is in the launcher/startup parser island, and sibling docs use concise file-static parser names such as `ParseNetsgoStartupAuthentication`, `ParseThrunetStartupAuthenticationFile`, and `ParseExciteGameLauncherAuthentication`.
  - Rejected alternative: `MihosoftLauncherParser` as a function name. It mirrors the documentation page title but reads like a reverse-engineered label rather than a source function.
  - Rejected alternative: `RegistryConfig::ParseMihosoftLauncher()`. It remains plausible, but no caller/member route was recovered, so file-static is the safer current source shape.
- Best literal/source names:
  - `kMihosoftSelector` or direct `L"Mihosoft"` are both reasonable. The sibling parser drafts use direct visible marker strings and named failure constants; direct `L"Mihosoft"` in the draft C++ is acceptable.
  - `kMihosoftInputErrorMessage` for `0x00617060`.
  - `kMihosoftHostErrorFormat` for `0x006170b8`.
- Best host/endpoint field names:
  - Use `m_startupAddress`, not a raw `byte_...` or `ipBytes`, because parent/support docs already use `m_startupAddress[4]` for this offset.
  - Use `m_startupHostName`, `m_startupPort`, `m_startupReady`, and `m_startupConnectionMode` as the support docs already establish these names across siblings.
- Range-check source shape:
  - The binary calls the MSVC range-check failure path when `WideCharToMultiByte` reports `>= 128` bytes before null termination. A first-draft source helper such as `ReportRangeCheckFailure()` is acceptable here because it expresses a real runtime path without preserving the raw decorated CRT label.
  - Do not replace this with a normal launcher host error; the binary does not use the message-box host failure for this length overflow case.

## Source Placement Decision

- Keep `CANONICAL_OWNER:0000N4`.
- Keep `EMITTER_UIDS:0000N4`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Treat the target as source-authored `RegistryConfig.cpp` parser-family logic, file-static for now:
  - `static void ParseMihosoftLauncher(RegistryConfig *config)`
- Keep [UID:000220] as the parser-island evidence parent/support page.
- Do not move the owner to [UID:0000BW] yet. The `ecx` object shape supports RegistryConfig adjacency, but no recovered dispatcher/caller proves a class method route.
- Do not split this target. The current half-open range is exact and has no uncovered live internal child requiring separate ownership.

## Score And Metadata Recommendation

- Target [UID:0002BM]:
  - Change `COMPLETION:85 -> 88`.
  - Change `CONFIDENCE:88 -> 90`.
  - Keep `CANONICAL_OWNER:0000N4`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000N4`.
  - Insert formal first-draft C++ in the existing C++ header.
- Reason not lower:
  - Live MCP reconfirmed exact raw boundary, uniqueness, no hidden internal split, tokenization, selector, dotted-IP path, DNS path, failure strings, port/ready/mode writes, and field/helper naming support.
  - Payload uncertainty is resolved as not applicable.
  - Field names are now aligned with current support docs and source-emitting siblings.
- Reason not higher:
  - No direct caller/dispatcher/pointer route is recovered.
  - No original source symbols or exact original helper names are recovered.
  - The file-static versus future class-method choice remains a source-placement confidence cap.
  - The range-check source expression remains a first-draft source representation of a compiler/runtime path, not final original source proof.

Support metadata:

- [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
  - Recommend no metadata score change unless supervisor wants an aggregate bump after several sibling support syncs.
  - Add a child/source note for [UID:0002BM] as `ParseMihosoftLauncher(RegistryConfig *config)`, selector/host/port only, no payload writes, and source-ready first-draft C++.
- [UID:0000N4] `by-file/RegistryConfig.md`
  - Recommend no metadata score change.
  - Add [UID:0002BM] to the command-line parser/source-placement notes with the same file-static helper disposition.
- [UID:0000BW] `by-class/RegistryConfig.md`
  - Recommend no metadata score change.
  - Add [UID:0002BM] to the startup parser ownership notes and field inventory if the section is being updated in the same implementation callback.
- [UID:0003FV] `RegistryConfigChannelStartupStringData`
  - Recommend no metadata score change.
  - Add the `Mihosoft`, generic input-error, and host-error format anchors if not already present.
- [UID:00028Q] `g_pConfig`
  - No required update. Existing startup field inventory already supports this target.

## Formal First-Draft C++ Recommendation

Insert this into [UID:0002BM]'s `RECONSTRUCTION_CPP CODE:BEGIN/END` block if supervisor accepts the report:

```cpp
static void ParseMihosoftLauncher(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[1024];
    wchar_t *tokens[8];
    wchar_t *tokenContext;
    char ansiHost[128];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    int tokenCount = 0;
    tokenContext = NULL;

    wchar_t *token = wcstok_s(argumentText, L" ", &tokenContext);
    while (token != NULL)
    {
        if (tokenCount >= _countof(tokens))
            return;

        tokens[tokenCount++] = token;
        token = wcstok_s(NULL, L" ", &tokenContext);
    }

    if (tokenCount < 3 || _wcsicmp(tokens[0], L"Mihosoft") != 0)
        AbortWithLauncherMessage(kMihosoftInputErrorMessage);

    wchar_t *hostText = tokens[1];
    wchar_t *portText = tokens[2];

    if (hostText[0] >= L'0' && hostText[0] <= L'9')
    {
        tokenContext = NULL;
        wchar_t *part = wcstok_s(hostText, L".", &tokenContext);

        for (int i = 0; i < 4; ++i)
        {
            if (part == NULL)
                return;

            config->m_startupAddress[i] =
                static_cast<unsigned char>(_wtol(part));

            part = wcstok_s(NULL, L".", &tokenContext);
        }
    }
    else
    {
        size_t hostLength = wcslen(hostText);
        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  hostText,
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
            ReportRangeCheckFailure();

        ansiHost[converted] = '\0';

        hostent *host = gethostbyname(ansiHost);
        if (host == NULL)
            AbortWithLauncherHostMessage(kMihosoftHostErrorFormat, hostText);

        memoryMan->MemmoveWrapper(config->m_startupAddress,
                                  host->h_addr_list[0],
                                  4);
    }

    config->m_startupPort = _wtol(portText);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}
```

Notes for supervisor validation:

- This is intentionally first-draft source-style code, not final audited original source.
- It avoids raw IDA names and uses the existing sibling-parser style.
- It preserves the target's unusual quiet returns for missing command-tail, too many tokens, and incomplete dotted IPv4 input.
- It keeps the range-check failure distinct from the host message-box failure.
- The exact implementation callback may adjust helper names if the supervisor prefers project-wide spelling such as `ReportSecurityRangeCheckFailure` over `ReportRangeCheckFailure`, but it should not regress to raw decorated CRT labels.

## Target/Support Documentation To Update After Acceptance

1. `by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md`
   - Update metadata to `88/90`.
   - Insert the formal first-draft C++ above in the formal C++ header.
   - Update item summary/status/rebuild handling to say first-draft `ParseMihosoftLauncher(RegistryConfig *config)` is now present.
   - Add live MCP provenance from session `80de0a67`.
   - Add behavior sections covering token limit, selector, dotted IPv4, DNS, port, ready/mode, failure paths, quiet-return cases, and no payload writes.
   - Replace old blank-C++ blocker wording with the current residual confidence caps.
2. `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
   - Expand the [UID:0002BM] child row from generic `Mihosoft launcher parser` to the exact selector/host/port parser behavior.
   - Add a source reconstruction note for `static void ParseMihosoftLauncher(RegistryConfig *config)`.
   - State that [UID:0002BM] shares normal startup fields and does not use payload/token scratch buffers.
3. `by-file/RegistryConfig.md`
   - Add [UID:0002BM] to command-line/session helper ownership notes as file-static `ParseMihosoftLauncher(RegistryConfig *config)`.
   - Preserve the class-method caveat: no direct dispatcher/caller route recovered.
4. `by-class/RegistryConfig.md`
   - Add [UID:0002BM] to the startup parser ownership/field notes if the implementation batch touches this section.
   - No score change required.
5. `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
   - Add [UID:0002BM] anchors:
     - `0x00617048`: `Mihosoft` selector.
     - `0x00617060`: generic dedicated-client/input-error message.
     - `0x006170b8`: host-specific input-error format.
   - Mention that direct byte decoding was used for the Korean UTF-16 messages because IDA automatic string typing is partial in this region.

Do not update generated files, generated C++ output, project-level generated files, validator/tool state, IDA DB, or any `-coverage-report.md` files during the agent implementation callback unless the supervisor explicitly overrides.

## Validator Plan

Run after accepted implementation edits, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002BM-MihosoftLauncherParser-source-quality-removed.md](0002BM-MihosoftLauncherParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation callback skips the optional `by-class/RegistryConfig.md` update, skip that validator line. Do not manually edit `project-level/-auto-completion-stats.md`; let the supervisor refresh generated/project stats through the documented validator mode when needed.

## Implementation Tracking Checklist

Supervisor should validate this checklist before sending the implementation callback. B003 should check each item only after applying it during the accepted implementation pass.

- [x] Target metadata changed to `COMPLETION:88` and `CONFIDENCE:90`; owner/emitter/reconstructable fields unchanged. Proof: target validator `000000004170` at `2026-06-27T11:21:54-04:00` applied `completion_update 0002BM 88`, `confidence_update 0002BM 90`, and `canonical_owner_update 0002BM 0000N4`; target metadata keeps [UID:0000N4] owner/emitter and `RECONSTRUCTABLE:TRUE`.
- [x] Target formal C++ block contains `static void ParseMihosoftLauncher(RegistryConfig *config)` with no raw IDA/compiler-generated names. Proof: [UID:0002BM] now emits the file-static helper body; target validator `000000004170` passed with `ok: 1` and `generated_refresh: completed`.
- [x] Target prose incorporates all report-level behavior detail: command-line tail extraction, token cap, selector, host/port roles, dotted IPv4 path, DNS path, range-check path, general/host failure paths, quiet returns, and no payload writes. Proof: [UID:0002BM] now has implementation verification prose for active MCP session `80de0a67`, exact raw boundaries, no-function/no-xref/no-pointer negatives, selector/count/host failures, startup field writes, quiet returns, and `+0x28d9e0/+0x28da20` no-write evidence.
- [x] Target score rationale explains why the target is no longer blank-C++ blocked and why it remains below final-audit confidence. Proof: [UID:0002BM] score rationale now states completion `88`/confidence `90`, cites the formal C++ block and supporting behavior evidence, and keeps the cap for missing direct caller/dispatcher route and raw-start status.
- [x] [UID:000220] parent parser island records [UID:0002BM] as selector/host/port only and source-ready under `RegistryConfig.cpp`. Proof: final correction validator `000000004244` at `2026-06-27T11:40:45-04:00` passed with `ok: 1`; page records file-static `ParseMihosoftLauncher(RegistryConfig *config)`, selector/host/port-only behavior, quiet missing-tail/token-cap/incomplete-dotted-IPv4 returns, generic/host-specific failure UI paths, shared startup writes, and no payload writes.
- [x] [UID:0000N4] RegistryConfig file page records [UID:0002BM] as file-static `ParseMihosoftLauncher(RegistryConfig *config)` and preserves the no-dispatcher/class-method caveat. Proof: final correction validator `000000004245` at `2026-06-27T11:41:04-04:00` passed with `ok: 1`; page records the file-owned route, no direct caller/dispatcher/vtable/stored-pointer proof, normal `m_startupPort`, precise quiet-return/failure-UI split, and no payload-slot writes.
- [x] [UID:0000BW] RegistryConfig class page is updated only if touched for startup parser ownership/field consistency; no score change required. Proof: touched for consistency and final validator `000000004225` at `2026-06-27T11:37:12-04:00` passed with `ok: 1`; page records 0002BM as RegistryConfig-owned file-static source logic while preserving the class-method caveat and no score change.
- [x] [UID:0003FV] string-data page records the `Mihosoft` selector and two Mihosoft failure-message anchors. Proof: final validator `000000004227` at `2026-06-27T11:37:20-04:00` passed with `ok: 1`; page records `0x00617048` `Mihosoft`, `0x00617060`, and `0x006170b8` with 0002BM xrefs/roles.
- [x] Optional [UID:00028Q] field/global support was updated at same-detail level. Proof: final validator `000000004230` at `2026-06-27T11:37:27-04:00` passed with `ok: 1`; page records `+0x2915b4`, `+0x2915c4`, `+0x2916c4`, `+0x2916ca`, `+0x28de28`, and the `+0x28d9e0/+0x28da20` no-write caveat for 0002BM.
- [x] No generated files, project-level generated files, IDA DB, validator/tool state, or `-coverage-report.md` files were manually edited. Proof: manual `apply_patch` edits were limited to the target/support by-* docs and this research checklist; validator-managed side effects were limited to scoped `--apply` runs, with the target run using required `--wait-generated`.
- [x] Leases, if any are needed during implementation, are acquired only immediately before edit and released immediately after the edit/validator batch. Proof: target lease was released successfully after target validator; support final verification lease for five support pages was acquired after B009 expiry and released successfully; correction lease for [UID:000220]/[UID:0000N4] was acquired immediately before the wording fix and released successfully; `current_leases.md` after release shows no B003 rows.
- [x] Scoped validators run for every by-* file actually changed, and their results are recorded in the implementation callback response. Proof: target `000000004170` passed with `ok: 1` and `generated_refresh: completed`; final support validators passed with `ok: 1` for `000000004244`, `000000004245`, `000000004225`, `000000004227`, and `000000004230`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BM-MihosoftLauncherParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002BM-MihosoftLauncherParser-source-quality.md","timestamp":"2026-06-27T11:46:06","uid":"0002BM"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BM-MihosoftLauncherParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002BM-MihosoftLauncherParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
