** TARGET-REPORT-UID:000249 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report - [UID:000249] PlatformStringConversionHelpers

Assignment: `B002-goal2-platform-string-conversion-source-quality-000249-20260617`

Primary target: [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](../../../../../by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md)

Report-only output. No by-* docs, generated reports/source, IDA DB, source files, or `by-memory/-coverage-report.md` were edited.

## Recommendation Summary

Recommend raising [UID:000249] from `82/88` to `88/91`, keeping file-level ownership and emission through [UID:0000ML] `PlatformApi`:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000ML
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ML
```

The helper island should stay a single PlatformApi-owned source helper group. It should not be split to MAPI, UniAPIInit, FileIO, or a new string utility file. The five bodies are small, share one platform compatibility source role, and are bounded by documented `0xcc` padding before [UID:0001KE].

Because the target is reconstructable/emitting, has a valid route to `auto-generated/NexusTK/platform/PlatformApi.cpp`, and now clears the current `(completion + confidence) / 2 > 85` gate, I recommend populating the formal C++ block with the first-draft code in this report after supervisor acceptance.

## Supporting Research

Read and rechecked:

- [UID:000249] target page.
- [UID:0000ML] `PlatformApi` file.
- [UID:00022V] `MapiSendMailHelper`.
- [UID:0001KE] `UniAPIInit`.
- [UID:0000WD] `WideApiDispatchInit`.
- [UID:0000TQ] `WideApiDispatchTable`.
- [UID:0000FE] `UniAPIInit` class.
- [UID:0002AS] / [UID:0002A6] wide dispatch table-body/tail pages.
- Auto-generated route reports and the generated `NexusTK/platform/PlatformApi.cpp`.

Executed B-agent reports were searched for `000249`, `PlatformStringConversionHelpers`, `0x00599440`, `0x005994d0`, `0x00599550`, and `0x00599570`. No prior executed B report for this UID or contained helpers was found.

## IDA And Binary Evidence

Current IDA MCP session: `b003_00018a_ime_comp_20260617`, input `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready.

Function and range facts:

| Range | IDA state | Size | Best source-facing helper |
| --- | --- | ---: | --- |
| `0x00599440-0x005994a8` | modeled function `sub_599440` | `0x68` / 104 bytes (Verified with int_convert.py) | `AllocAnsiFromWideDefaultCodepage(const wchar_t*)` |
| `0x005994b0-0x005994c5` | modeled function `sub_5994B0` | `0x15` / 21 bytes (Verified with int_convert.py) | `FreeAllocatedAnsiString(char*)` |
| `0x005994d0-0x00599543` | raw function-shaped code, not modeled | `0x73` / 115 bytes (Verified with int_convert.py) | `AllocWideFromAnsiDefaultCodepage(const char*)` |
| `0x00599550-0x00599565` | raw function-shaped code, not modeled | `0x15` / 21 bytes (Verified with int_convert.py) | `FreeAllocatedWideString(wchar_t*)` |
| `0x00599570-0x005995a7` | modeled function `sub_599570` | `0x37` / 55 bytes (Verified with int_convert.py) | `ReadUtf16CodeUnitFromFile(FILE*)` |

Behavior facts:

- `0x00599440` null-checks the input, counts UTF-16 code units manually, calls `WideCharToMultiByte(CP_ACP, 0, ...)` once for size and once for output, allocates `bytes + 1`, writes a byte NUL terminator, and returns the allocated ANSI buffer.
- `0x005994b0` null-checks and tail-jumps to the CRT free path for non-null input.
- `0x005994d0` is the inverse helper: null-checks, counts bytes until NUL, calls `MultiByteToWideChar(CP_ACP, 0, ...)` once for count and once for output, uses an overflow-aware `(chars + 1) * sizeof(wchar_t)` allocation expression, writes a UTF-16 NUL terminator, and returns the allocated wide buffer.
- `0x00599550` is the inverse free wrapper with the same null-check/tail-free shape.
- `0x00599570` checks `feof(stream)`, returns `0xffff` at EOF, otherwise reads one two-byte code unit with `fread(&buffer, 2, 1, stream)` and returns it.

Xref/liveness facts:

- IDA `xrefs_to 0x00599440` reports exactly five code refs, all from raw [UID:00022V] MAPI helper call sites: `0x004f5b58`, `0x004f5b61`, `0x004f5b6c`, `0x004f5b77`, `0x004f5b8c`.
- IDA `xrefs_to 0x005994b0` reports exactly five code refs from the same MAPI cleanup path: `0x004f5c3a`, `0x004f5c45`, `0x004f5c4d`, `0x004f5c55`, `0x004f5c5d`.
- IDA `xrefs_to 0x005994d0` and `0x00599550` reports no refs.
- A PE-aware scan of `NexusTK.exe` `.text` found no direct `call`/`jmp` rel32 edges and no absolute VA pointer references to `0x005994d0` or `0x00599550`. The same scan positively found the five known calls to `0x00599440`, the five known calls to `0x005994b0`, and the three absolute refs to `0x00599570`, so the negative result is meaningful rather than a broken scan.
- `0x00599570` has three absolute/data refs: the real initializer [UID:0000WD] at `0x0041a2b1`, and generated/raw UniAPIInit projection writes at `0x005995ea` and `0x00599821`.
- IDA byte/padding checks show `0x0059943f-0x00599440`, `0x005994a8-0x005994b0`, `0x005994c5-0x005994d0`, `0x00599543-0x00599550`, `0x00599565-0x00599570`, and `0x005995a7-0x005995b0` are all `0xcc` alignment spans.

Generated-output facts:

- `auto-generated/-ag-memory-coverage.md` routes [UID:000249] through [UID:0000ML] to `auto-generated/NexusTK/platform/PlatformApi.cpp`.
- `auto-generated/NexusTK/platform/PlatformApi.cpp` currently exists but is zero bytes, so this helper island has an active output route but no populated formal C++ yet.

## Helper Names, Signatures, And Ownership

Recommended source-facing declarations:

```cpp
static char *AllocAnsiFromWideDefaultCodepage(const wchar_t *text);
static void FreeAllocatedAnsiString(char *text);
static wchar_t *AllocWideFromAnsiDefaultCodepage(const char *text);
static void FreeAllocatedWideString(wchar_t *text);
static wchar_t ReadUtf16CodeUnitFromFile(FILE *stream);
```

Name rationale:

- `AllocAnsiFromWideDefaultCodepage` is preferable to a MAPI-specific name because the helper does not know about MAPI; MAPI is just the only surviving caller. The `CP_ACP`/default-codepage behavior is semantically important and should stay in the name or documentation.
- `AllocWideFromAnsiDefaultCodepage` should be kept as the inverse helper name even with no current inbound edge. Its code is not random padding or compiler glue; it is a matched retained conversion helper.
- The two free wrappers should stay typed by output buffer kind, not collapsed to one shared page name, because the binary has two distinct source-shaped bodies at two distinct aligned starts.
- `ReadUtf16CodeUnitFromFile` is stronger than `fgetwc` or `ReadWideChar` because the body explicitly reads two bytes from a `FILE*` and returns `0xffff` at EOF. It is a PlatformApi fallback/dispatch helper, not a general `DATFile` or `StdioFile` method.

Ownership decision:

- Best owner: [UID:0000ML] `PlatformApi`.
- MAPI helper owner rejected: [UID:00022V] only uses the ANSI conversion/free pair. It does not use or own the inverse pair or UTF-16 file reader.
- UniAPIInit class owner rejected for the whole target: the reader is installed into UniAPI dispatch state, but the conversion helpers are free platform utilities and the exact UniAPI initializer class shape remains a generated-boundary caveat.
- `WideApiDispatchTable` rejected for the whole target: it owns table storage; it does not own executable conversion allocation helpers.
- New `StringUtil`/platform string file rejected: no evidence of broader non-platform use, no separate generated route, and address locality is tightly adjacent to PlatformApi/UniAPIInit.
- FileIO/StdioFile rejected: file consumers use the dispatch table; they do not own this fallback reader or conversion helpers.

## Raw Helper Liveness Decision

`0x005994d0` and `0x00599550` should be documented as retained source-shaped platform helpers with no surviving inbound edge in the current binary.

Rejected alternatives:

- Not padding: both bodies have complete prologue/epilogue or tail-free shapes, API calls, local state, allocation, terminator writes, and alignment after the return.
- Not compiler-generated CRT/STL: the conversion body calls Win32 `MultiByteToWideChar` and mirrors a project helper that is actively called by MAPI.
- Not MAPI-owned: MAPI has no refs to the inverse pair.
- Not dispatch-table entries: PE/IDA pointer scans found no absolute references to the inverse pair, while the reader helper did produce three absolute refs.
- Not currently live through direct call/table edge: IDA xrefs and the independent PE scan agree there are no rel32 direct calls, jumps, or VA pointers to the inverse pair.

Best explanation: the original PlatformApi source had a symmetric ANSI/wide conversion helper pair. The wide-to-ANSI side survived because MAPI needs ANSI `MapiMessage` strings. The ANSI-to-wide side survived as retained compiled code, likely because function-level dead stripping was not removing unreferenced source functions in this build or because generated projection/liveness metadata once referenced it but no direct edge remains.

This should not lower the target below 85/85. It affects final naming confidence only mildly because the bodies are source-shaped and the pair relationship is direct.

## Heuristic / Inference Reanalysis And Validation

Best defensible directions:

- Treat the target as a PlatformApi platform-string helper island, not as a MAPI-local helper. Evidence: MAPI call sites cover only two of five bodies; the reader is dispatch-table state; the inverse pair is not reached by MAPI.
- Use default-codepage wording in the conversion helper names. Evidence: both conversion bodies pass code page `0` and flags `0` to Win32 conversion APIs.
- Treat allocation/free as a pair-owned conversion API. Evidence: allocation bodies call the project/CRT allocation wrapper and free bodies tail to the CRT free path. The source-facing free helpers should be used for buffers returned by these conversion helpers rather than exposing the underlying CRT convention to consumers.
- Treat `ReadUtf16CodeUnitFromFile` as a dispatch-table UTF-16 reader. Evidence: `dword_69BE1C` gets this helper from the real initializer and generated UniAPI projection, while no consumer module uniquely owns it.
- Keep [UID:000249] emitting through [UID:0000ML]. Evidence: PlatformApi file is `88/85`, target route is valid, and the generated reports already surface it to `NexusTK/platform/PlatformApi.cpp`.

Existing docs validated:

- Existing behavior summaries for all five helpers are correct.
- Existing PlatformApi ownership is validated and should remain.
- Existing boundary/padding notes are validated by current byte checks.
- Existing note that `0x005994d0` and `0x00599550` have no IDA xrefs is strengthened by PE rel32/pointer scanning and should no longer be treated as a vague blocker.

Existing docs to revise:

- The target page's "medium for final helper names" can be raised: the names above are defensible source-facing descriptive names, even if not proven original spellings.
- The target page's final C++ caveat should change. With current gate and this bounded helper island, first-draft C++ is safe enough to enter after supervisor review.
- [UID:0000ML] should record the inverse conversion helper as retained source-shaped PlatformApi code, not just "MAPI string conversion."
- [UID:0001KE] and [UID:0000WD] coverage rows are stale relative to their current page scores and should be synced if supervisor is already updating this neighborhood.

Remaining uncertainty:

- Original exact helper spellings are not proven by symbols. This does not block source placement or C++ entry because the descriptive names are tight and all behavior is documented.
- The exact source spelling for allocation/free could have used `new`/`delete`, wrapper macros, or direct CRT allocation. The first draft uses `operator new` plus `free` to reflect the observed allocation/free lowering while keeping the wrapper boundary explicit. If a later project-wide allocator pass establishes a named allocator wrapper, update the helper bodies to call that wrapper.

Impact:

- Score can rise to `88/91`.
- Owner/emitter stay [UID:0000ML].
- No split is required.
- Formal C++ should be populated for this target after supervisor acceptance.

## First-Draft C++ Recommendation

Populate [UID:000249]'s formal `RECONSTRUCTION_CPP CODE` block with this first draft after applying the accepted source-facing names. The code is intentionally limited to the five helper bodies in the target range.

```cpp
static char *AllocAnsiFromWideDefaultCodepage(const wchar_t *text)
{
    if (text == NULL)
        return NULL;

    int wideLength = (int)wcslen(text);
    int byteLength = WideCharToMultiByte(CP_ACP, 0, text, wideLength, NULL, 0, NULL, NULL);
    char *result = (char *)operator new(byteLength + 1);

    WideCharToMultiByte(CP_ACP, 0, text, wideLength, result, byteLength, NULL, NULL);
    result[byteLength] = '\0';
    return result;
}

static void FreeAllocatedAnsiString(char *text)
{
    if (text != NULL)
        free(text);
}

static wchar_t *AllocWideFromAnsiDefaultCodepage(const char *text)
{
    if (text == NULL)
        return NULL;

    int byteLength = (int)strlen(text);
    int wideLength = MultiByteToWideChar(CP_ACP, 0, text, byteLength, NULL, 0);
    wchar_t *result = (wchar_t *)operator new((wideLength + 1) * sizeof(wchar_t));

    MultiByteToWideChar(CP_ACP, 0, text, byteLength, result, wideLength);
    result[wideLength] = L'\0';
    return result;
}

static void FreeAllocatedWideString(wchar_t *text)
{
    if (text != NULL)
        free(text);
}

static wchar_t ReadUtf16CodeUnitFromFile(FILE *stream)
{
    wchar_t ch;

    if (feof(stream))
        return (wchar_t)0xffff;

    fread(&ch, sizeof(wchar_t), 1, stream);
    return ch;
}
```

Notes for supervisor:

- Include the needed C headers in the owning file once PlatformApi.cpp is populated: Windows headers for `WideCharToMultiByte` / `MultiByteToWideChar`, CRT headers for `FILE`, `wcslen`, `strlen`, `free`, `feof`, and `fread`.
- If the wider reconstruction standard prefers wrapper names over direct `operator new`/`free`, keep these five source helper bodies but replace allocation/free calls consistently across PlatformApi after that allocator convention is named.

## Support Docs To Update

Recommended support updates:

- [UID:000249] target:
  - Apply metadata `88/91`, owner/emitter unchanged.
  - Add current IDA MCP session evidence, PE direct-call/pointer scan results, and source-facing signatures.
  - Replace "final C++ blank until names/source split settled" with the accepted first-draft C++ decision.
- [UID:0000ML] `PlatformApi`:
  - Record the target helper names and state that the inverse ANSI-to-wide pair is retained source-shaped platform helper code with no direct edge.
  - Keep `PlatformApi.cpp` as the source root for the helper island.
- [UID:00022V] `MapiSendMailHelper`:
  - Update dependency names to `AllocAnsiFromWideDefaultCodepage` and `FreeAllocatedAnsiString`.
  - Do not claim MAPI owns the conversion helpers; it consumes them.
- [UID:0000WD] `WideApiDispatchInit`, [UID:0000TQ] `WideApiDispatchTable`, [UID:0001KE] `UniAPIInit`:
  - Name the `0x0069be1c` slot as the `ReadUtf16CodeUnitFromFile` / wide-file-code-unit reader entry.
  - Keep `0x00599570` with PlatformApi, not inside `UniAPIInit` code generation.

## Supervisor-Owned Coverage Rows

Replacement row for [UID:000249], replacing the current row immediately after the `0x0059943f-0x00599440` padding row and before the existing `0x005995a7-0x005995b0` padding row:

```text
    - [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md) 0x00599440-0x005995a7 | global helpers | PlatformStringConversionHelpers : reconstructable : 88% : very strong : B002 current IDA and PE-aware source-quality pass confirms PlatformApi-owned default-codepage conversion helper island: live MAPI calls to `AllocAnsiFromWideDefaultCodepage` and `FreeAllocatedAnsiString`, retained no-direct-edge inverse helpers `AllocWideFromAnsiDefaultCodepage` and `FreeAllocatedWideString`, dispatch-table UTF-16 reader `ReadUtf16CodeUnitFromFile`, exact modeled/raw helper boundaries, internal `0xcc` padding, no hidden rel32/VA refs to the inverse pair, valid [UID:0000ML] PlatformApi emitter route, and first-draft C++ ready for supervisor entry.
```

Optional stale support-row sync for [UID:0000WD], replacing the current low-address row near `0x0041a280`:

```text
    - [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) : reconstructable : 85% : very strong : Current page score is 85/90; live IDA refresh confirms exact `0x228` / 552-byte PlatformApi dispatch initializer, startup-table data xref, NT wide-API assignment sequence, `ReadUtf16CodeUnitFromFile` slot at `0x0069be1c`, `_wfopen`/`_wstat64i32`/`SendMessageW` representative slots, `_atexit` cleanup registration, and separate successor boundary at `0x0041a4b0`.
```

Optional stale support-row sync for [UID:0001KE], replacing the current row immediately after the `0x005995a7-0x005995b0` padding row:

```text
    - [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) 0x005995b0-0x00599a34 | class/static initializer caveat | UniAPIInit : reconstructable : 85% : strong : Current page score is 85/86; PlatformApi static object/generated-boundary caveat with true dispatch initializer at `0x0041a280`, fallback reader refs to [UID:000249] `ReadUtf16CodeUnitFromFile`, vtable reset helper `0x005997e0`, scalar deleting destructor `0x00599a10-0x00599a34`, exact predecessor/successor padding, and unresolved raw initializer-shaped spans around generated `0x005995b0`.
```

No internal padding rows are required for [UID:000249] unless the supervisor chooses to split exact child helper pages later. The aggregate row currently covers the full helper island, and the page body should list the internal `0xcc` spans.

## Validation Commands

Commands run or recommended:

> Executable block R001 was removed from this report and preserved verbatim in [000249-platform-string-conversion-source-quality-removed.md](000249-platform-string-conversion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP validation used:

```text
server_health
lookup_funcs: 0x00599440, 0x005994b0, 0x005994d0, 0x00599550, 0x00599570, 0x005995b0, 0x0041a280
xrefs_to: 0x00599440, 0x005994b0, 0x005994d0, 0x00599550, 0x00599570, 0x005995b0
analyze_function/decompile: 0x00599440, 0x005994b0, 0x00599570
disasm: 0x005994d0, 0x00599550, 0x00599440
get_bytes: 0x0059943f, 0x005994a8, 0x005994c5, 0x00599543, 0x00599565, 0x005995a7
find_bytes: VA pointer byte patterns for 0x00599440, 0x005994b0, 0x005994d0, 0x00599550, 0x00599570
```

After supervisor applies accepted edits:

> Executable block R002 was removed from this report and preserved verbatim in [000249-platform-string-conversion-source-quality-removed.md](000249-platform-string-conversion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Files Changed, Leases, And Blockers

Changed file:

- `tools/leaser/Agents/Agent-B002/research/000249-platform-string-conversion-source-quality.md`

Leases used: none. Research report creation in the assigned folder does not require a lease.

Blockers: none for supervisor review.

Next useful follow-up: after applying this report, run a focused PlatformApi source pass to name the `WideApiDispatchTable` typedefs and decide the final static `UniAPIInit` object declaration style. That broader pass can then populate [UID:0000WD] and dispatch-table C++ with consistent typedefs.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000249-platform-string-conversion-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"000249"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000249-platform-string-conversion-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/000249-platform-string-conversion-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000249"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
