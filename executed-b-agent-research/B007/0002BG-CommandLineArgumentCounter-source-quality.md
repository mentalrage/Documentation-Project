** TARGET-REPORT-UID:0002BG **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 source-quality report: [UID:0002BG] CommandLineArgumentCounter

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0002BG-CommandLineArgumentCounter-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x0048f400-0x0048f4cf.CommandLineArgumentCounter.md`

Assignment: B-agent report-only source-quality / heuristic pass. I did not edit the target by-memory page, support by-* pages, or `by-memory/-coverage-report.md`.

## Executive recommendation

Keep this page source-bearing and reconstructable under [UID:0000N4] `RegistryConfig`, but reframe it from "argument counter" to a raw, no-direct-xref RegistryConfig startup command-line token-limit scanner. It is not compiler glue and not generated no-code. The body is ordinary source logic duplicated almost exactly in `RegistryConfig::LoadOrInitialize` at `0x0048e89b-0x0048e94e`.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000N4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N4
```

Recommended C++ handling: first-draft helper C++ is feasible and included below, but I would not yet force it into the target `RECONSTRUCTION_CPP` block unless the supervisor accepts a provisional file-static helper name. The behavior is fully reconstructable; the remaining cap is source-facing route/name, not code semantics. If the project prefers C++ for every 85+ source-bearing page, use the draft body under a clearly provisional helper name.

Best source-facing interpretation:

```text
static void ScanStartupCommandLineTokenLimit(RegistryConfig *config);
```

Alternative acceptable spelling:

```text
static void MarkStartupReadyAfterCommandLineTokenScan(RegistryConfig *config);
```

Avoid finalizing `CommandLineArgumentCounter` as a source name. The code does not store a count and does not return a meaningful count; it scans the command line after the executable token up to the eighth token and writes the startup/terminal-ready flag at `config + 0x2916ca`.

## Evidence checked

Target and support documentation checked:

- `source-3/project-documentation/by-memory/0x0048f400-0x0048f4cf.CommandLineArgumentCounter.md`
- `source-3/project-documentation/by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- `source-3/project-documentation/by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`
- `source-3/project-documentation/by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md`
- `source-3/project-documentation/by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`
- `source-3/project-documentation/by-file/RegistryConfig.md`
- `source-3/project-documentation/by-class/RegistryConfig.md`
- `source-3/project-documentation/by-memory/0x004f7c50-0x004f7cf9.OpenTerminalPane.md`
- `source-3/project-documentation/by-memory/0x0058ae60-0x0058b859.TerminalPaneAndSetup.md`
- `source-3/project-documentation/by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/auto-generated/NexusTK/config/RegistryConfig.cpp`
- `source-3/simroot_v2/class_RegistryConfig.cpp`

Export and disassembly evidence checked:

- `resources/exported_data/functions/0x0048f400.json`
- `resources/exported_data/master_function_list.json`
- `resources/exported_data/master_names.json`
- `resources/exported_data/detection_differences.json`
- Local IDA `.lst` export around `0x0048f400`, `0x0048f4d0`, `0x0048e860`, and references to `2916CAh`.

Current-session live MCP check:

- Attempted local MCP connection to `http://127.0.0.1:13337/mcp`.
- Result: unavailable / connection refused. I therefore relied on the target page's prior live-MCP evidence plus local exported listings and JSON exports for this report.

Prior live-MCP evidence already preserved in the target and aggregate pages:

- `0x0048f400` is not modeled as an IDA function object.
- `0x0048f400` and `0x0048f4d0` had zero direct xrefs.
- Loaded-segment pointer scans found no stored VA/RVA pointers to these raw starts.
- Raw bytes show a normal body at `0x0048f400`, a `ret` at `0x0048f4ce`, and one `0xcc` byte at `0x0048f4cf` before the next raw start.

## Exact range and boundary

The filename range `0x0048f400-0x0048f4cf` is correct as the documented inclusive by-memory span. The executable body is effectively half-open `0x0048f400-0x0048f4cf`; `0x0048f4cf` is the single-byte `0xcc` alignment before the next exported/raw parser start at `0x0048f4d0`.

Important boundary facts to preserve:

- `0x0048f400`: raw body start, `push ebp`.
- `0x0048f403`: `sub esp, 0x828`, matching a stack cookie frame plus a 1024-wide-character command-line buffer and tokenizer context.
- `0x0048f41b`: first write to `word ptr [edi+0x2916ca] = 1`.
- `0x0048f424`: `GetCommandLineW`.
- `0x0048f437`: `_wcscpy_s(commandLine, 0x400, GetCommandLineW())`.
- `0x0048f445` and following: `_wcschr` search for quote or space delimiter around the executable token.
- `0x0048f486`: `_wcstok_s(firstArg, L" ", &context)`.
- `0x0048f49f`: token-count compare against `8`.
- `0x0048f4b6`: second write to `word ptr [edi+0x2916ca] = 1` on exhausted-token path.
- `0x0048f4ce`: `ret`.
- `0x0048f4cf`: `0xcc`.

Ghidra models this as `FUN_0048f400` with signature `undefined __fastcall FUN_0048f400(int param_1)`, size 207 bytes, no callers, and callees `FUN_00516030`, `GetCommandLineW`, `_wcscpy_s`, `_wcschr`/`FUN_005ca50d`, `_wcstok_s`, and `__security_check_cookie`. That is useful mechanical evidence but should not leak into source-facing docs as a final name or type.

## Behavior resolution

The routine is better described as a command-line token-limit scanner, not a counter.

Observed behavior:

1. Takes the caller-supplied config/startup-state pointer in `ecx` and preserves it in `edi`.
2. Calls `sub_516030` / memory-manager bootstrap helper before touching command-line state.
3. Writes `1` to the word at `config + 0x2916ca`.
4. Copies the current process command line into a 1024-wide-character local buffer with `_wcscpy_s`.
5. Finds the end of the executable token:
   - If the command line starts or contains a quote, find the next quote after the first quoted segment.
   - Otherwise find the first space.
6. If no delimiter is found, return with the flag already set.
7. Tokenize the remaining command line with `_wcstok_s(..., L" ", &context)`.
8. If the first token is absent, write the same flag again and return.
9. For each token found, increment a local counter and stop when the counter reaches `8`.
10. If the tokenizer exhausts before count `8`, write the flag again and return.

Important source-quality correction:

- The body does not store an argument count.
- The body does not return an argument count.
- The body does not visibly clear or reject via `+0x2916ca`; it sets the flag before tokenization, so the "too many args" path leaves the flag set by the entry write.
- The loop semantics are still meaningful: it distinguishes "found an eighth token" from "token stream exhausted before the eighth token", but the standalone body has no visible failure side effect. If a caller expected a return value, it would be using incidental `eax`, and no direct caller currently proves that.

Recommended behavior wording for the target page:

```text
This raw helper copies the process command line, skips the executable token, tokenizes the remaining wide command line on spaces, and scans up to the eighth startup token. It writes the RegistryConfig startup/terminal-ready flag at `+0x2916ca` before scanning and repeats the same write when the token stream is exhausted before the cap. No persistent argument count or meaningful return value is visible in this body.
```

## `+0x2916ca` field semantics

The field at `config + 0x2916ca` should not be documented as an argument count. It is a startup/terminal/launcher-ready flag or state word whose low byte is consumed by terminal-launch paths.

Evidence:

- `CommandLineArgumentCounter` writes `word ptr [edi+0x2916ca] = 1` at `0x0048f41b` and `0x0048f4b6`.
- `RegistryConfig::LoadOrInitialize` contains the same tokenizer tail and writes `word ptr [edi+0x2916ca] = 1` at `0x0048e89b` and `0x0048e936`.
- Sibling command-line parsers write the same field on launcher/host/port success paths, including observed writes near `0x0048f636`, `0x0048fbf5`, `0x0049012f`, `0x00490430`, `0x00490729`, `0x00490a30`, `0x00490ff2`, `0x00491309`, `0x004916c1`, `0x00491869`, and `0x00491ae0`.
- `OpenTerminalPane` reads `*(byte *)(g_pConfig + 0x2916ca)`. If nonzero, it requests exit instead of constructing a new terminal pane. If zero, it constructs the terminal pane.
- `TerminalPane` setup writes/checks the same low byte while initializing terminal state.

Best field-name recommendation:

```text
m_startupTerminalReady
```

Safer provisional documentation name:

```text
startup/terminal-ready flag at `+0x2916ca`
```

I recommend the safer prose name in by-* documentation until the larger `RegistryConfig` layout is named. For IDA comments, use `startupTerminalReadyFlag_2916CA` or `m_startupTerminalReady_2916CA` as provisional, not final source member spelling.

## Caller, liveness, and no-xref route

Direct liveness remains unresolved, but the evidence supports "source-authored retained helper" more strongly than dead/no-code:

- Local Ghidra export sees a normal callable function body at `0x0048f400`.
- IDA does not model it as a function and direct xref/pointer scans are zero.
- The surrounding parser island is a series of raw or partially modeled startup parser entries with the same no-direct-xref problem.
- The exact tokenizer body is duplicated inline in the modeled `RegistryConfig::LoadOrInitialize` method. That establishes source shape and field semantics even though it is not a call-xref to the raw start.
- The sibling parsers are stateful startup/launcher routines that set host, port, mode, account, and ready fields. This helper fits that family as a lightweight token-count/limit probe.

Best route hypothesis:

```text
RegistryConfig.cpp owns this as a file-local startup parser helper or a retained callable helper emitted next to the larger command-line/session parser family. It is not currently proven to be a RegistryConfig member function. The source may also have carried this logic inline in `RegistryConfig::LoadOrInitialize`, with the raw helper retained for an unmodeled dispatcher or an optimized/unused command-line validation route.
```

Rejected alternatives:

- Compiler-generated thunk/glue: rejected. The body contains command-line API calls, tokenizer logic, stack-cookie local buffer setup, and application-state writes.
- Data island / generated binary data: rejected. The byte stream decodes as normal code with a prologue, external calls, loop, cookie check, and `ret`.
- Pure argument counter: rejected. No count is stored or returned; the count is local and only gates scanning to eight tokens.
- Confirmed class method: not proven. The `ecx` argument matches a `this`-style pointer, but no call site or vtable/ref evidence proves a class method rather than a file-local helper using `__fastcall`/register argument convention.

## Relationship to `RegistryConfig::LoadOrInitialize`

`source-3/project-documentation/by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md` is the best support page for source shape. The modeled method performs registry/default initialization and then executes the same command-line tokenizer tail:

- `GetMemoryMan_516030` / `sub_516030`.
- Entry write to `+0x2916ca`.
- `GetCommandLineW`.
- 1024-wide-character stack copy.
- quote-or-space executable-token skip.
- `_wcstok_s` tokenizer with delimiter `L" "`.
- local token scan capped at `8`.
- exhausted-token rewrite to `+0x2916ca`.

Recommended support-doc update:

```text
Add a cross-reference note: The command-line normalization tail at `0x0048e89b-0x0048e94e` is duplicated by raw parser helper [UID:0002BG] `0x0048f400-0x0048f4cf`. This duplication is source-shape evidence for the raw helper but not a direct call edge; direct xrefs to `0x0048f400` remain absent.
```

## Relationship to sibling command-line parsers

The sibling parsers under [UID:000220] `RegistryCommandLineParsers` parse specific launcher/session modes and write related fields such as host/port/account/session mode and the same startup-ready flag. This target is the generic token-limit scanner at the front of that island.

Specific recommendations:

- Keep the parent aggregate [UID:000220] as the parser-island evidence page.
- Update the [UID:000220] child summary for [UID:0002BG] to mention "token-limit scanner" instead of "argument counter".
- Keep [UID:0002BG] attached to [UID:0000N4] `RegistryConfig`, but describe it as file-level/config-adjacent unless a future direct caller proves a member function.
- Link [UID:0002BG] to [UID:0002BH] `StartupHostPortCommandLineParser` as a sibling that sets the same `+0x2916ca` field after parsing concrete startup arguments.

## Source-facing name and signature

Recommended source-facing name:

```cpp
static void ScanStartupCommandLineTokenLimit(RegistryConfig *config);
```

Why:

- "Scan" fits the absence of persistent count output.
- "StartupCommandLine" ties it to `RegistryConfig` and sibling launcher parsers.
- "TokenLimit" captures the compare against `8` without claiming rejection behavior.
- `void` fits Ghidra's call graph and the lack of meaningful returned value evidence.
- `RegistryConfig *config` fits the field offsets and parent/source ownership.

Second-best source-facing name:

```cpp
static void MarkStartupReadyAfterCommandLineTokenScan(RegistryConfig *config);
```

Names to avoid:

- `CommandLineArgumentCounter`: useful page title, but too strong as source name because no count survives.
- `ParseCommandLine`: too broad for the actual behavior; sibling helpers parse concrete host/port/mode fields.
- `ValidateCommandLineArgumentCount`: implies a visible success/failure result that is not present in this body.
- `FUN_0048f400`, `sub_48f400`, `param_1`, or Ghidra/IDA-generated names.

Calling convention:

- Binary: first argument in `ecx`, no stack arguments.
- Source policy: document as a `RegistryConfig *` helper. If an IDA type is applied before a caller is found, `void __fastcall RegistryConfig_ScanStartupCommandLineTokenLimit(RegistryConfig *config)` is the mechanically safest type. If later promoted to a class method, `void __thiscall RegistryConfig::ScanStartupCommandLineTokenLimit()` is source-cleaner.

## First-draft C++

This is feasible first-draft C++ if the implementation pass accepts provisional helper/member names. It intentionally uses mid-2000s C++ style and keeps unresolved source names conservative.

```cpp
static void ScanStartupCommandLineTokenLimit(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t *scan;
    wchar_t *context;
    wchar_t *token;
    int tokenCount;

    GetMemoryMan_516030();
    config->m_startupTerminalReady = 1;

    wcscpy_s(commandLine, 1024, GetCommandLineW());

    scan = wcschr(commandLine, L'"');
    if (scan != NULL)
        scan = wcschr(scan + 1, L'"');
    else
        scan = wcschr(commandLine, L' ');

    if (scan == NULL)
        return;

    context = NULL;
    token = wcstok_s(scan + 1, L" ", &context);
    if (token == NULL) {
        config->m_startupTerminalReady = 1;
        return;
    }

    tokenCount = 0;
    do {
        ++tokenCount;
        if (tokenCount >= 8)
            return;

        token = wcstok_s(NULL, L" ", &context);
    } while (token != NULL);

    config->m_startupTerminalReady = 1;
}
```

Implementation notes for this draft:

- `GetMemoryMan_516030` is still a placeholder support name for `sub_516030`; use whatever final memory-manager bootstrap helper name the project standardizes.
- `m_startupTerminalReady` is a provisional field name for `+0x2916ca`; the binary writes a word here in parser paths while terminal paths consume the low byte.
- If exact assembly fidelity is required, keep the redundant `+0x2916ca` writes. They are visible at both entry and exhausted-token paths.
- The C++ body should not claim that the helper returns a boolean or stores a count.

If the target page keeps formal C++ blank during the next implementation pass, the proof should be:

```text
Formal C++ is intentionally deferred despite reconstructable behavior because the raw start has no IDA function object, no direct entry/pointer xrefs, no proven caller convention beyond ECX, and a source-facing helper name that remains inferred from sibling parser context and the duplicated `RegistryConfig::LoadOrInitialize` tokenizer tail. The report includes a ready first-draft helper body for supervisor acceptance.
```

## Recommended target-page implementation checklist

Apply these changes to `source-3/project-documentation/by-memory/0x0048f400-0x0048f4cf.CommandLineArgumentCounter.md` only after supervisor callback:

1. Raise metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter/reconstructable unchanged.
2. Change behavior summary from "counts up to eight startup arguments" to "scans command-line tokens up to the eighth token; no persistent count or meaningful return is visible."
3. Add explicit source-quality correction that `+0x2916ca` is not the token count; it is a startup/terminal-ready flag/state word whose low byte is read by terminal-launch paths.
4. Add `RegistryConfig::LoadOrInitialize` duplication evidence as a core source-shape point.
5. Update C++ handling:
   - Either insert the first-draft helper body above under the provisional name `ScanStartupCommandLineTokenLimit`.
   - Or leave the reconstruction block blank and add the exact deferral proof from this report.
6. Replace `CommandLineArgumentCounter` source-name language with provisional source-facing helper names:
   - preferred: `ScanStartupCommandLineTokenLimit`
   - alternate: `MarkStartupReadyAfterCommandLineTokenScan`
7. Preserve the raw-boundary facts: no IDA function object, Ghidra-only function detection, zero direct xrefs/pointers, `ret` at `0x0048f4ce`, `0xcc` at `0x0048f4cf`.
8. Add rejected alternatives:
   - not compiler-generated glue
   - not generated binary data/no-code
   - not a confirmed class method
   - not a true stored argument counter

Exact target-page text candidates:

```text
Source-facing name/signature recommendation: treat the raw start as a RegistryConfig-owned file helper, provisionally `static void ScanStartupCommandLineTokenLimit(RegistryConfig *config)`. The binary receives the config/startup-state pointer in `ecx`, but no direct caller proves a class method; keep the name provisional and avoid leaking `FUN_0048f400`/`param_1`.
```

```text
Field note: `+0x2916ca` is a startup/terminal-ready flag/state word, not the argument count. This helper and the sibling startup parsers write it; terminal-launch paths read the low byte to decide whether to request exit or construct `TerminalPane`.
```

```text
Token semantics: the local counter only scans up to the eighth post-executable token. The helper does not persist a count and does not visibly clear a failure state when the eighth token is found because the flag is already set at entry.
```

## Recommended support-doc updates

### `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`

Update the [UID:0002BG] child summary:

```text
`0x0048f400-0x0048f4cf` - raw Ghidra-only startup command-line token-limit scanner. It duplicates the `RegistryConfig::LoadOrInitialize` tokenizer tail, skips the executable token with quote/space handling, scans up to the eighth post-executable token with `_wcstok_s`, and writes the startup/terminal-ready flag at `+0x2916ca`; no persistent argument count or meaningful return is visible.
```

Add source-quality note:

```text
The front helper [UID:0002BG] is source-authored but no-direct-xref. It should stay RegistryConfig-owned/file-level unless a dispatcher/caller is later recovered; do not promote `CommandLineArgumentCounter` to a final source name.
```

### `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`

Add cross-reference note:

```text
The command-line normalization tail in this method is duplicated by raw helper [UID:0002BG] `0x0048f400-0x0048f4cf`. Use this duplication as source-shape and field-semantics evidence for the raw helper, but not as a call edge; direct xrefs/pointers to `0x0048f400` remain absent.
```

### `by-file/RegistryConfig.md`

Update command-line/session parser row:

```text
`0x0048f400-0x00491b28` - RegistryConfig-adjacent startup command-line/session parser island. Includes raw no-direct-xref helper [UID:0002BG], whose tokenizer tail matches `RegistryConfig::LoadOrInitialize`, plus concrete host/port/session-mode parsers that set shared startup fields such as `+0x2916ca`.
```

Add source-placement warning:

```text
Keep [UID:0002BG] as a file-level/config-adjacent helper unless a future caller proves a class method. Its ECX config pointer is real, but direct call and pointer references are not currently recovered.
```

### `by-class/RegistryConfig.md`

Add note under command-line/session helper coverage:

```text
[UID:0002BG] is RegistryConfig-owned source logic but not a confirmed class method. It is best documented as a file-level helper that operates on a RegistryConfig/startup-state pointer and duplicates the tokenizer tail used by `RegistryConfig::LoadOrInitialize`.
```

### `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

Add known field cluster entry:

```text
`+0x2916ca` - startup/terminal-ready flag/state word. Written as a word by `RegistryConfig::LoadOrInitialize`, [UID:0002BG], and sibling command-line parser success paths; read as a byte by terminal-launch paths such as `OpenTerminalPane`, and touched by `TerminalPane` setup. Do not document this as an argument count.
```

### `by-memory/0x004f7c50-0x004f7cf9.OpenTerminalPane.md`

Add or refine cross-reference:

```text
The `g_pConfig + 0x2916ca` byte consumed here is the same startup/terminal-ready state written by RegistryConfig command-line parser helpers, including [UID:0002BG]. This consumer evidence supports naming the field as a startup/terminal-ready flag rather than an argument count.
```

## Exact pending coverage text

Do not edit `by-memory/-coverage-report.md` during report-only work. When the supervisor authorizes implementation, replace the existing [UID:0002BG] child row with this exact row:

```text
        - [UID:0002BG][0x0048f400-0x0048f4cf.CommandLineArgumentCounter](by-memory/0x0048f400-0x0048f4cf.CommandLineArgumentCounter.md) 0x0048f400-0x0048f4cf | raw unmodeled file helper | CommandLineArgumentCounter : reconstructable : 88% : strong : RegistryConfig startup command-line token-limit scanner; local IDA/Ghidra exports and prior live MCP confirm exact raw non-IDA-function body, no direct entry/pointer xrefs, duplicate inline tokenizer in `RegistryConfig::LoadOrInitialize`, quoted-executable skip, 0x400-wide buffer, `_wcstok_s` token scan capped at the eighth token, startup/terminal-ready writes to `+0x2916ca`, and file-level RegistryConfig ownership with final source name/signature still provisional.
```

The parent [UID:000220] aggregate row is also stale in current coverage output. If that row is updated in the same pass, use:

```text
    - [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) 0x0048f400-0x00491b28 | aggregate / parser island | RegistryCommandLineParsers : reconstructable : 86% : strong : RegistryConfig-owned command-line/session parser island; child starts and padding verified, all entries remain no-direct-xref/raw or partially modeled helpers, and child pages cover token-limit, host/port, DNS, session/account, and launcher-mode state writes.
```

## Validator needs

After an implementation pass, run:

> Executable block R001 was removed from this report and preserved verbatim in [0002BG-CommandLineArgumentCounter-source-quality-removed.md](0002BG-CommandLineArgumentCounter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended live IDA/MCP validation if the server is available:

```text
lookup function/object at 0x0048f400, 0x0048f4cf, 0x0048f4d0, and 0x0048e860
disassemble/get_bytes 0x0048f400 size 0xd0
xrefs_to 0x0048f400
loaded-segment pointer scan for VA/RVA 0x0048f400 and 0x0048f4d0
decompile/disassemble 0x0048e860 and compare tokenizer tail with 0x0048f400
search disassembly references to 2916CAh
```

## IDA rename/type/comment recommendations

No IDA changes were made in this report-only pass.

If the IDA owner accepts raw function creation/renaming:

- Create or label `0x0048f400` as:

```text
RegistryConfig_ScanStartupCommandLineTokenLimit_48F400
```

- Apply tentative type only if local conventions allow raw helper typing:

```cpp
void __fastcall RegistryConfig_ScanStartupCommandLineTokenLimit_48F400(RegistryConfig *config);
```

- Alternative if later proven a class method:

```cpp
void __thiscall RegistryConfig::ScanStartupCommandLineTokenLimit();
```

- Add a repeatable comment at `0x0048f400`:

```text
Raw Ghidra-only RegistryConfig parser helper; no direct xrefs/pointers found. Duplicates LoadOrInitialize command-line tokenizer tail, skips executable token, scans post-executable tokens up to 8, and writes startup/terminal-ready flag at config+0x2916ca.
```

- Add field comment for `+0x2916ca`:

```text
startupTerminalReadyFlag_2916CA; written as word by RegistryConfig startup parsers, read as byte by terminal launch/setup paths; not an argument count.
```

- Keep `FUN_0048f400`, `param_1`, and `CommandLineArgumentCounter` out of final source-facing names.

## Open questions and attempted resolution

| Question | Resolution |
| --- | --- |
| Should this stay source-bearing? | Yes. It is source-authored command-line/tokenizer logic with application field writes, not compiler glue or generated data. |
| Is `CommandLineArgumentCounter` the final source name? | No. It is a serviceable documentation title but misleading as source. Prefer `ScanStartupCommandLineTokenLimit`. |
| Does the helper count arguments? | Only locally while scanning; no stored count and no meaningful return. |
| What is `+0x2916ca`? | Best evidence says startup/terminal-ready flag/state word. Sibling parser writes and terminal-launch reads reject "count" semantics. |
| Is the function live? | Direct liveness is unresolved: no IDA function object, no direct xrefs, no stored pointers. Source liveness is indirectly supported by the parser island and duplicated `LoadOrInitialize` code. |
| Is it a `RegistryConfig` method? | Not proven. ECX carries a config pointer, but file-level helper under `RegistryConfig.cpp` is the safer placement. |
| Should formal C++ remain blank? | It can remain blank if the supervisor wants to avoid provisional helper names. The actual first-draft body is ready and included above. |
| Does the eighth-token path clear failure? | No visible clear occurs in this body. The flag is set at entry, so any "too many args" interpretation must be documented as unproven unless a caller uses incidental return state. |

## Implementation readiness

Ready for supervisor review. The future implementation pass should update the target and support docs, not just bump the score. The highest-value corrections are:

- Reframe the behavior from "argument counter" to "token-limit scanner".
- Document `+0x2916ca` as startup/terminal-ready state, not count storage.
- Add the `RegistryConfig::LoadOrInitialize` duplicate-tokenizer evidence.
- Keep ownership at [UID:0000N4] `RegistryConfig`.
- Keep source placement file-level/config-adjacent unless a future direct caller proves method status.
- Add first-draft C++ only if provisional helper names are acceptable in the target reconstruction block.

FINISHED for report-only research.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002BG-CommandLineArgumentCounter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0002BG"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BG-CommandLineArgumentCounter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0002BG-CommandLineArgumentCounter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
