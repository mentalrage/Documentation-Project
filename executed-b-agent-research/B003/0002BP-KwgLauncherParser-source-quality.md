** TARGET-REPORT-UID:0002BP **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BP KwgLauncherParser Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0002BP] as a source-ready, file-static `RegistryConfig.cpp` launcher helper named `ParseKornetWorldLauncher(RegistryConfig *config)`.
- Final disposition: keep `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N4`; raise the target from `85/88` to `88/90`; insert first-draft formal C++ in the target's `RECONSTRUCTION_CPP CODE` block after supervisor validation.
- Required action: supervisor Rule 26 validation first, then implementation callback to update the target plus support docs. No target/support by-* docs were edited during this report-only pass.
- Confidence: high for local behavior, range, owner/emitter route, fixed host/port/state writes, failure paths, and first-draft C++ readiness; capped below final-audit because the direct dispatcher/caller route and original source symbol names remain unrecovered.

## Target

- Target UID: [UID:0002BP]
- Target path: `by-memory/0x00491450-0x0049178d.KwgLauncherParser.md`
- Assignment id: `B003-report-0002BP-KwgLauncherParser-source-quality-20260627`
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, line 1581 still reports stale `80/86`, average `83.0`, true, zero code.
- Current supervisor classification: report-only research first; do not edit by-* docs until supervisor validation and implementation callback.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current generated state: `auto-generated/-ag-coverage-report-by-memory.md` still reports [UID:0002BP] as `emits_code:false`, `80%`, updated `2026-06-23 21:41:15`; do not hand-edit generated rows.

## Current Target State

- Existing target role is broadly correct: raw `/KWG` launcher parser in the RegistryConfig command-line parser island with fixed `game.kornetworld.com` host, four payload conversions, fixed port `9000`, and Unicode failure-path coverage.
- Existing stale/incomplete target claims:
  - The page says [UID:0000N4] RegistryConfig is `88/82`; current [UID:0000N4] metadata is `88/85`.
  - The page contradicts successor padding: one section says two `0xcc` bytes, while current bytes prove three `0xcc` bytes at `0x0049178d-0x00491790`.
  - The old C++ blocker says final C++ should wait for the whole launcher selector audit. Current accepted sibling parser reports show that no direct dispatcher route caps confidence but does not block scoped child C++ when local behavior, fields, boundaries, and owner route are resolved.
  - The target uses raw `param_1`/offset prose and lacks a source-facing payload overlay for `+0x28d9e0/+0x28d9f0/+0x28da00/+0x28da10`.
- Related support docs checked:
  - [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
  - [UID:0000N4] `by-file/RegistryConfig.md`
  - [UID:0000BW] `by-class/RegistryConfig.md`
  - [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
  - [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
  - Proposed source tree `by-project-structure/proposed-source-tree.md`, which places `RegistryConfig.cpp` under `config/`.

## Supervisor Active Recheck

- Active instruction: continue Agent-B003 report-only research for [UID:0002BP], use project-level `ntk-b-agent-workflow`, do not spawn subagents, do not edit target/support by-* docs until supervisor validation and callback, and use live IDA MCP.
- MCP availability: a first pre-update probe reached the MCP server but listed zero active sessions and is not used as final evidence. After the supervisor MCP status update, live session `398b87c1` was used for all target evidence below.
- Split repair: no split execution is needed. The target range is an exact raw code body with three-byte successor alignment padding and no mixed internal subrange.
- Source-bearing children: [UID:0002BP] is already the exact child. No child creation, range split, or merge is recommended.

## Inference Research Guidance Check

- IDA facts, documentation evidence, and inference are separated below. IDA facts include live session `398b87c1` function lookup, xrefs, bytes, disassembly, decompile failure, string bytes, and range signature.
- Existing documentation was treated as a lead, not authority. The stale two-byte padding, stale parent score, stale generated tracker row, and blank-C++ blocker were all rechecked against current evidence and sibling accepted reports.
- Stale Wave2/Wave3/generator artifacts were not used as authority. `wave3_data_issues.md`, old manual coverage rows, and generated tracker rows were considered stale queue/context only.
- Address adjacency is not the sole ownership evidence. The owner route is supported by RegistryConfig field writes, sibling parser island pattern, accepted support docs, proposed source-tree placement, and absence of a better direct owner.

## Evidence Standards Used

- Live IDA MCP: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `get_string`, `decompile`, `disasm`, and `make_signature_for_range`.
- Local numeric conversion: `tools/int_convert.py`.
- Documentation evidence: current target/support docs, proposed source tree, generated tracker and auto coverage rows, executed sibling reports [UID:0002BK], [UID:0002BL], [UID:0002BM], plus active supervisor instructions.
- Negative evidence: zero xrefs to start/end/successor/modelled neighbor, zero stored VA/RVA byte-pattern hits for the raw start/end/successor, failed decompile due raw non-function, no IDA function object for target start.
- Tool limitation: IDA string typing renders several UTF-16 strings in this cluster as one-character values (`/`, `t`, `g`, `t`), so string roles are based on raw UTF-16 bytes and xrefs, not `get_string` alone.

## Evidence Checked

- IDA MCP session: `398b87c1`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker `pid:23700`, `backend:"worker"`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, cache size `2067`.
- Function lookup:
  - `0x00491450`, `0x0049178d`, `0x00491790`, `0x004910d0`, `0x00491445`, and `0x004918dc`: `Not a function`.
  - `0x004918e0`: modeled `sub_4918E0`, size `0x248`.
- Xrefs:
  - Zero xrefs to `0x00491450`, `0x0049178d`, `0x00491790`, and `0x004918e0`.
  - `0x0061729c` `/KWG`: one data xref from `0x00491525`.
  - `0x006172a8` KornetWorld input-error text: one data xref from `0x004916e1`.
  - `0x0061730c` `game.kornetworld.com`: one data xref from `0x00491540`.
  - `0x00617338` KornetWorld host-error format: one data xref from `0x00491735`.
  - `0x00617314` `.kornetworld.com` has no xrefs and is not the fixed host copied by this helper.
  - `0x006173a8` `/GameBill`: one xref from `0x00491852`, confirming it belongs to the successor [UID:0002BQ], not this target.
- Pointer-pattern searches:
  - No matches for `50 14 49 00`, `50 14 09 00`, `8D 17 49 00`, `8D 17 09 00`, `90 17 49 00`, or `90 17 09 00`.
- Boundary bytes:
  - `0x00491445`: eleven `0xcc` bytes followed by `55 8b ec 81 ec ac 0a 00 00 ...`.
  - `0x00491780`: tail call bytes, then three `0xcc` bytes at `0x0049178d-0x00491790`, then successor prologue at `0x00491790`.
- String bytes:
  - `0x0061729c`: UTF-16 `/KWG`.
  - `0x0061730c`: UTF-16 `game.kornetworld.com`.
  - `0x006172a8` and `0x00617338`: localized KornetWorld failure text/format byte regions containing wide `KornetWorld`; `0x00617338` contains wide `%s`.
- Decompile:
  - `decompile 0x00491450`: `Decompilation failed at 0x491450`, expected because target is raw non-function code.
- Disassembly:
  - `disasm 0x00491450` confirms a real `.text` raw body, prologue, `GetCommandLineW`, `_wcscpy_s`, `_wcschr`, `_wcstok_s`, `/KWG` compare, fixed-host path, DNS path, four payload conversions, fixed port/ready/mode writes, and failure paths.
- Range signature:
  - `make_signature_for_range 0x00491450-0x0049178d` returned a unique wildcarded signature.
- Numeric conversions:
  - `0x2328` -> decimal `9000`, bytes `28 23` (Verified with int_convert.py).
  - `0x33d` -> decimal `829` target byte length (Verified with int_convert.py).
  - `0x10` -> decimal `16` output cap (Verified with int_convert.py).
  - `0x100` -> decimal `256` output cap (Verified with int_convert.py).
  - `0x80` -> decimal `128` host wide/ANSI cap where documented (Verified with int_convert.py; invoked with `--size 2`).

## IDA MCP Facts

- Function/range facts:
  - Target range is `.text` raw code at `0x00491450-0x0049178d`, length `0x33d` / decimal `829` bytes (Verified with int_convert.py).
  - IDA does not model target start/end or successor `0x00491790` as functions.
  - Successor modeled function after raw successor span remains `sub_4918E0` at `0x004918e0`.
- Data/table/padding facts:
  - Eleven `0xcc` bytes precede the target start.
  - Three `0xcc` bytes follow target code before successor start; the target page's two-byte wording is stale.
- Xref facts:
  - No direct xrefs to target start/end/successor/modelled neighbor.
  - Four KWG string anchors each have exactly one current target xref.
- Negative IDA facts:
  - No stored VA/RVA pointer-byte route was recovered for target start, target end, or successor start.
  - `get_string` is unreliable for this UTF-16 cluster; raw bytes are stronger evidence.

## Behavior Summary From Disassembly

- `0x00491450-0x00491484`: stack frame and security cookie setup, `ecx` saved as the config/startup-state pointer in `edi`, memory manager acquired through `sub_516030`, command line copied to a `0x400` wide-character stack buffer.
- `0x00491489-0x004914b8`: executable path skipped by finding a quote first or a space otherwise. No delimiter returns quietly.
- `0x004914db-0x0049151f`: tokenizes remaining command-line text on the shared space delimiter at `0x0060de18` with `_wcstok_s`. It stores token pointers in an eight-entry local array, quietly returns when the counter reaches eight, and requires exactly five real tokens.
- `0x004914e9`: null first token after a command-tail exists branches to the general KornetWorld input-error path.
- `0x00491525-0x0049153a`: token zero must case-insensitively match `/KWG`; mismatch branches to the same input-error path.
- `0x00491540-0x00491551`: fixed host `game.kornetworld.com` is copied into `config + 0x2915c4` with `_wcscpy_s(..., 0x80, ...)`.
- `0x00491560-0x00491599`: host length is measured, host converted to ANSI with `WideCharToMultiByte`, converted count `>= 0x80` branches to `___report_rangecheckfailure`, and the ANSI scratch buffer is explicitly NUL terminated.
- `0x004915a1-0x004915ca`: `gethostbyname` resolves the fixed host. On success, four bytes from `host->h_addr_list[0]` are copied into `config + 0x2915b4` through `sub_516220` and the memory manager object.
- `0x004915cf-0x004916af`: payload tokens one through four convert to `config + 0x28d9e0`, `+0x28d9f0`, `+0x28da00`, and `+0x28da10`. The first three use cap `0x10` / decimal `16` (Verified with int_convert.py); the fourth uses cap `0x100` / decimal `256` (Verified with int_convert.py). Each writes an explicit terminator at the returned byte count.
- `0x004916b7-0x004916ca`: writes `0x2328` / decimal `9000` (Verified with int_convert.py) to `config + 0x2916c4`, writes word `1` to `config + 0x2916ca`, and writes byte `5` to `config + 0x28de28`.
- `0x004916e1-0x0049172f`: general input-error path formats the KornetWorld-only localized message, displays it with `MessageBoxW`, posts quit, then calls `__loaddll(0)`.
- `0x00491734-0x00491783`: DNS failure path formats the host-specific KornetWorld failure string with the fixed host and follows the same message-box/quit/load path.
- `0x00491788`: host ANSI conversion overflow calls `___report_rangecheckfailure`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00491450-0x0049178d` | [UID:0002BP] `by-memory/0x00491450-0x0049178d.KwgLauncherParser.md` | `/KWG` fixed-host KornetWorld launcher parser | TRUE | [UID:0000N4] | current `85/88`, recommended `88/90` | exact child; emit first-draft C++ after callback |
| `0x00491445-0x00491450` | parent gap before target | `0xcc` alignment | FALSE | aggregate context | not applicable | no child page needed |
| `0x0049178d-0x00491790` | gap before [UID:0002BQ] | three `0xcc` alignment bytes | FALSE | aggregate context | not applicable | correct stale two-byte wording |
| `0x0048f400-0x00491b28` | [UID:000220] `RegistryCommandLineParsers` | aggregate parser island | TRUE aggregate/index | [UID:0000N4] | `86/89` | keep aggregate C++ blank; child emits |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00491450` | zero xrefs | no direct dispatcher/caller route recovered |
| `0x0049178d` | zero xrefs | no external target-end reference |
| `0x00491790` | zero xrefs | successor raw start also has no direct route |
| `0x0061729c` | data xref from `0x00491525` | `/KWG` selector compare |
| `0x006172a8` | data xref from `0x004916e1` | general KornetWorld input-error text |
| `0x0061730c` | data xref from `0x00491540` | fixed host `game.kornetworld.com` |
| `0x00617338` | data xref from `0x00491735` | host-specific KornetWorld failure format |

## Documentation Evidence And IDA Status

- Existing docs supporting recommendation:
  - [UID:000220] documents the parser island, all siblings, current file route, and aggregate C++ blank caveat.
  - [UID:0000N4] and [UID:0000BW] document current parser-island convention: helpers receive a RegistryConfig pointer and remain file-static/config-adjacent unless a whole-island class-method route is recovered.
  - [UID:00028Q] documents shared startup fields and mode-dependent payload/session overlays.
  - Executed sibling reports [UID:0002BK], [UID:0002BL], and [UID:0002BM] establish accepted first-draft C++ for raw/no-direct-xref parser children once local behavior and field names are resolved.
- Existing docs incomplete/stale for this target:
  - Target page keeps blank C++ for a now-resolved blocker.
  - [UID:000220] only says `/KWG` parser with fixed port `9000`, not source-ready `ParseKornetWorldLauncher` with fixed host and four payload slots.
  - [UID:0000N4] and [UID:0000BW] do not include [UID:0002BP] in the current source-placement/helper inventory.
  - [UID:0003FV] lacks explicit entries for `/KWG`, the fixed host, and the two KornetWorld failure anchors.
  - [UID:00028Q] lacks the KWG-specific four-payload overlay.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0002BP] is a source-authored RegistryConfig parser helper | High | raw `.text` code body, parser island location, RegistryConfig field writes, [UID:0000N4]/[UID:000220] route | no function object, no direct xrefs, no pointer route | dispatcher/caller route remains unrecovered |
| Helper should be file-static `ParseKornetWorldLauncher(RegistryConfig *config)` | Strong inferred | `/KWG` selector, fixed `game.kornetworld.com`, KornetWorld failure strings, sibling naming pattern | `ParseKwgLauncher` and class method form considered | original source name unknown |
| Fixed host is `game.kornetworld.com` | Confirmed | raw UTF-16 bytes at `0x0061730c`, one xref from copy at `0x00491540` | `.kornetworld.com` at `0x00617314` has no target xref | none for behavior |
| Fixed port is `9000` | Confirmed | `mov dword ptr [edi+2916C4h], 2328h`; `0x2328` -> decimal `9000` verified | host/port token parsing not present for this target | none for behavior |
| Four payload slots are neutral KWG payload data, not account/ticket/session names | Medium-high inferred | writes to four adjacent offsets with caps `0x10/0x10/0x10/0x100`; no consumers proving semantic names | sibling overlay docs reviewed; no better consumer names found in current docs | future consumer discovery could refine field names |
| First-draft C++ is ready despite raw/no-xref status | High | current score gate, owner/emitter route, live disassembly, accepted sibling reports | raw start, failed decompile, no dispatcher route | final-audit source class/member route remains open |

## Positive Evidence Summary

- Direct facts supporting recommendation:
  - Exact raw range and padding are verified by current bytes.
  - `/KWG`, fixed host, input-error text, and host-error text each have target-local xrefs.
  - Disassembly fully explains token count, selector check, host route, payload conversions, fixed port/ready/mode writes, and failure/default cases.
  - Current owner/emitter route to [UID:0000N4] already exists and remains correct.
- Corroborating documentation/generated-report evidence:
  - [UID:000220] already classifies the parser island under RegistryConfig.
  - [UID:0000N4] proposed source path is `NexusTK/config/`.
  - Sibling executed reports already validate the current source-shape pattern for parser children.
- Strongest inference chain:
  - This is not independent network/bootstrap source because it receives and mutates RegistryConfig startup fields directly, lives in the RegistryConfig parser island, uses sibling helper structure, and has no separate class/vtable/global owner signal.

## Ranked Ownership Analysis

### 1. [UID:0000N4] RegistryConfig file root

- Evidence for: current canonical owner/emitter, proposed `config/RegistryConfig.cpp` source placement, shared startup field writes, sibling parser-island pattern, support docs and accepted sibling reports.
- Evidence against: no direct dispatcher/caller route proving exact original helper declaration, and `ecx` receiver could later support a class-method spelling.
- Decision: keep as direct owner/emitter. It is the narrowest current source root that clears the ownership and generation route without overclaiming class method status.

### 2. [UID:0000BW] RegistryConfig class

- Evidence for: helper receives the config object in `ecx` and writes fields that belong to RegistryConfig/runtime Config layout.
- Evidence against: no vtable route, direct caller, IDA function object, method signature, class member list proof, or whole-island class-method migration. Current accepted sibling pattern keeps these helpers file-static/config-adjacent.
- Decision: reject as canonical owner for this pass; document class-scope field use but do not rehome as `RegistryConfig::ParseKornetWorldLauncher`.

### 3. [UID:000220] RegistryCommandLineParsers aggregate

- Evidence for: aggregate contains the exact target and indexes all parser children.
- Evidence against: aggregate is an evidence/index page with blank C++ and should not own emitted child code that already has a valid file root.
- Decision: keep as parent/context/support page, not direct emitter.

### 4. New network/bootstrap module

- Evidence for: helper performs DNS lookup and launcher startup handling.
- Evidence against: all persistent state writes are RegistryConfig startup fields; no independent module globals, vtables, source strings, or caller cluster prove a separate owner.
- Decision: reject.

### 5. No-owner/non-emitting fallback

- Evidence for: raw no-function status and no direct xref route.
- Evidence against: reconstructable source logic, live behavior resolved, current owner/emitter valid, sibling reports accept same raw-island condition for child C++.
- Decision: reject. No-owner/non-emitting would lose source-ready facts.

## Source Placement

- Recommended placement: file-static helper in `NexusTK/config/RegistryConfig.cpp`:
  - `static void ParseKornetWorldLauncher(RegistryConfig *config)`
- Why it fits:
  - Proposed source tree assigns RegistryConfig to `config/RegistryConfig.cpp`.
  - Neighboring helpers use file-static parser names such as `ParseLgInternetSessionLauncher`, `ParseLauncherHostPortPayload`, and `ParseMihosoftLauncher`.
  - The helper uses a RegistryConfig/startup pointer but lacks class-method proof.
- Rejected placements:
  - `RegistryConfig::ParseKornetWorldLauncher()`: plausible future class-method form, rejected until a dispatcher/member route is recovered or whole island is rehomed consistently.
  - `ParseKwgLauncher`: selector-only and weaker than the fixed-host/failure-string KornetWorld evidence.
  - `ParseKornetWorldCommandLine`: too broad for a single mode parser.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x00491450-0x0049178d`.
- Target body begins after eleven `0xcc` bytes at `0x00491445-0x00491450`.
- Target body ends before three `0xcc` bytes at `0x0049178d-0x00491790`.
- No internal split is recommended. The disassembly from prologue to `___report_rangecheckfailure` tail is one coherent helper body.
- No padding child page is needed. Padding should be corrected in target and aggregate prose only.
- Reclassification: remain `RECONSTRUCTABLE:TRUE`; add formal child C++ after validation.

## Heuristic / Inference Reanalysis And Validation

- Raw helper role:
  - Best interpretation: a file-static KornetWorld launcher parser. It is raw only because IDA lacks a function object, not because the code is unreachable or compiler-generated.
- Source-facing name:
  - Best name: `ParseKornetWorldLauncher`, strongly inferred from `/KWG`, fixed `game.kornetworld.com`, and KornetWorld-only failure strings.
  - Rejected `KwgLauncherParser` as a final function name because it mirrors the documentation/generated label.
- Field/type naming:
  - `config + 0x2915b4`: `m_startupAddress`.
  - `config + 0x2915c4`: `m_startupHostName`.
  - `config + 0x2916c4`: `m_startupPort` for this target.
  - `config + 0x2916ca`: `m_startupReady`.
  - `config + 0x28de28`: `m_startupConnectionMode`.
  - KWG-specific payload overlay:
    - `+0x28d9e0`: `m_kornetWorldPayload[0][0x10]`
    - `+0x28d9f0`: `m_kornetWorldPayload[1][0x10]`
    - `+0x28da00`: `m_kornetWorldPayload[2][0x10]`
    - `+0x28da10`: `m_kornetWorldPayloadData[0x100]`
- Payload semantic blocker:
  - Resolved for current pass by neutral target-local overlay names. No current consumer evidence proves account/ticket/session meanings, so stronger semantic names are rejected rather than deferred.
- Final-C++ blocker:
  - Resolved. Raw/no-direct-xref status remains a confidence cap, but the target clears the formal C++ eligibility gate and has enough local evidence for source-style C++.
- Rejected alternatives:
  - Do not leave C++ blank solely because original source symbols are unavailable.
  - Do not use raw `sub_`, `param_1`, or address-shaped names in formal C++ when source-facing names are supported.
  - Do not assign payload fields stronger final meanings without consumer evidence.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits were made or requested in this report-only pass.
- Source-facing documentation names to use after supervisor approval:
  - `ParseKornetWorldLauncher(RegistryConfig *config)`
  - `m_kornetWorldPayload[3][0x10]`
  - `m_kornetWorldPayloadData[0x100]`
  - `kKornetWorldInputErrorMessage`
  - `kKornetWorldHostErrorFormat`
- IDA edits are not required for this report. Any future IDA rename/type pass should be supervisor-authorized and should not precede by-* source documentation.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Gate:
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000N4`, which routes to [UID:0000N4] `NexusTK/config/RegistryConfig.cpp`
  - Current average `(85 + 88) / 2 = 86.5`, greater than `85`; recommended average `(88 + 90) / 2 = 89`.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE:BEGIN/END` block content after supervisor approval. The inline `RECONSTRUCTION_CPP CODE:[[[]]]` value should remain blank.

```cpp
static void ParseKornetWorldLauncher(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[0x400];
    wchar_t *tokens[8] = {};
    wchar_t *tokenContext = NULL;
    char ansiHost[0x80];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    wchar_t *token = wcstok_s(argumentText, L" ", &tokenContext);
    tokens[0] = token;
    if (token == NULL)
        AbortWithLauncherMessage(kKornetWorldInputErrorMessage);

    int tokenCount = 0;
    do
    {
        ++tokenCount;
        if (tokenCount >= _countof(tokens))
            return;

        token = wcstok_s(NULL, L" ", &tokenContext);
        tokens[tokenCount] = token;
    } while (token != NULL);

    if (tokenCount != 5 || _wcsicmp(tokens[0], L"/KWG") != 0)
        AbortWithLauncherMessage(kKornetWorldInputErrorMessage);

    wcscpy_s(config->m_startupHostName,
             _countof(config->m_startupHostName),
             L"game.kornetworld.com");

    size_t hostLength = wcslen(config->m_startupHostName);
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
        AbortWithLauncherHostMessage(kKornetWorldHostErrorFormat,
                                     config->m_startupHostName);

    memoryMan->MemmoveWrapper(config->m_startupAddress,
                              host->h_addr_list[0],
                              4);

    wchar_t *payloadToken1 = tokens[1];
    wchar_t *payloadToken2 = tokens[2];
    wchar_t *payloadToken3 = tokens[3];
    wchar_t *payloadToken4 = tokens[4];

    int payloadLength = static_cast<int>(wcslen(payloadToken1));
    int payloadBytes = WideCharToMultiByte(CP_ACP,
                                           0,
                                           payloadToken1,
                                           payloadLength,
                                           config->m_kornetWorldPayload[0],
                                           0x10,
                                           NULL,
                                           NULL);
    config->m_kornetWorldPayload[0][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken2));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken2,
                                       payloadLength,
                                       config->m_kornetWorldPayload[1],
                                       0x10,
                                       NULL,
                                       NULL);
    config->m_kornetWorldPayload[1][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken3));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken3,
                                       payloadLength,
                                       config->m_kornetWorldPayload[2],
                                       0x10,
                                       NULL,
                                       NULL);
    config->m_kornetWorldPayload[2][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken4));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken4,
                                       payloadLength,
                                       config->m_kornetWorldPayloadData,
                                       0x100,
                                       NULL,
                                       NULL);
    config->m_kornetWorldPayloadData[payloadBytes] = '\0';

    config->m_startupPort = 9000;
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}
```

- Reason it preserves exact original behavior:
  - It follows the same command-tail/token loop, exactly five-token requirement, `/KWG` compare, fixed-host DNS route, payload conversion caps, explicit NUL writes, fixed port `9000`, ready word, mode byte, quiet returns, failure-message routes, and host overflow range-check path.
- Reason it matches plausible original source shape:
  - It uses a file-static helper in `RegistryConfig.cpp`, ordinary Win32/CRT calls, source-facing helper names, and explicit config fields rather than decompiler temporaries.
- Third-party import directive: not applicable.

## Final Recommendation

- Target changes recommended:
  - Raise [UID:0002BP] metadata to `COMPLETION:88`, `CONFIDENCE:90`.
  - Keep owner/emitter/reconstructable metadata unchanged.
  - Insert the formal C++ block above.
  - Update item summary, stale parent score, boundary/padding prose, evidence section, source-shape section, field overlay table, score rationale, and change log.
- Support changes recommended:
  - Update [UID:000220], [UID:0000N4], [UID:0000BW], [UID:0003FV], and [UID:00028Q] at report-level detail.
- Items left no-owner/non-emitting:
  - None for [UID:0002BP]. The aggregate [UID:000220] remains blank-C++ by design, but [UID:0002BP] should emit through [UID:0000N4].
- Future work outside this assignment:
  - Whole-island dispatcher/caller reconstruction and final class-method-vs-file-static decision for all parser helpers.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00491450-0x0049178d.KwgLauncherParser.md`
- Exact report facts to incorporate:
  - Current MCP session `398b87c1` provenance and health.
  - Raw non-function status for target start/end/successor and modeled successor `sub_4918E0`.
  - Eleven-byte predecessor padding and three-byte successor padding.
  - Zero direct xrefs and zero VA/RVA pointer-pattern hits.
  - Literal xrefs for `/KWG`, fixed host, input-error text, and host-error format.
  - Disassembly-backed behavior from command-line copy through token gating, fixed host, DNS, four payload conversions, fixed port, ready/mode writes, input failure, DNS failure, and range-check failure.
  - Source-facing helper name `ParseKornetWorldLauncher(RegistryConfig *config)`.
  - Neutral KWG payload overlay fields.
  - Rejected alternatives and negative evidence.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - keep `CANONICAL_OWNER:0000N4`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:0000N4`
  - add formal C++ block above.
- Historical/stale assumptions to preserve as corrected:
  - Old "two `0xcc` bytes" successor gap is superseded by three-byte proof.
  - Old "wait for whole launcher selector audit" C++ blocker is superseded by current sibling precedent and resolved local evidence.

## Recommended Support Doc Changes

- Support path: [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
  - Update the [UID:0002BP] child row to source-ready `ParseKornetWorldLauncher(RegistryConfig *config)`, fixed host `game.kornetworld.com`, fixed port `9000` (Verified with int_convert.py), four KWG payload outputs, and three-byte successor padding.
  - Add [UID:0002BP] to source reconstruction notes as another file-static RegistryConfig.cpp parser helper with formal child C++ while aggregate C++ remains blank.
  - Add field notes for `+0x2915b4`, `+0x2915c4`, `+0x2916c4`, `+0x2916ca`, `+0x28de28`, and KWG overlay `+0x28d9e0/+0x28d9f0/+0x28da00/+0x28da10`.
- Support path: [UID:0000N4] `by-file/RegistryConfig.md`
  - Add [UID:0002BP] to the command-line/session parser source-placement notes as file-static/config-adjacent `ParseKornetWorldLauncher(RegistryConfig *config)`.
  - Preserve no confirmed class-method claim.
  - Add mode-dependent KWG field overlay and fixed-host/fixed-port writes.
- Support path: [UID:0000BW] `by-class/RegistryConfig.md`
  - Add [UID:0002BP] to RegistryConfig-owned source logic notes while keeping it file-level/config-adjacent.
  - Add the KWG overlay and fixed `m_startupPort = 9000` (Verified with int_convert.py), `m_startupReady = 1`, and `m_startupConnectionMode = 5`.
- Support path: [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
  - Add string-data rows:
    - `0x0061729c`: UTF-16 `/KWG`, single xref from `0x00491525`.
    - `0x006172a8`: localized KornetWorld-only input-error message, single xref from `0x004916e1`.
    - `0x0061730c`: UTF-16 fixed host `game.kornetworld.com`, single xref from `0x00491540`.
    - `0x00617338`: localized KornetWorld host-error format containing `%s`, single xref from `0x00491735`.
  - Note IDA string typing is unreliable here; byte-backed UTF-16 roles are stronger evidence.
- Support path: [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
  - Add [UID:0002BP] to startup address/host/port/ready/mode field notes.
  - Add KWG-specific overlay for `+0x28d9e0/+0x28d9f0/+0x28da00/+0x28da10`, caps `0x10`, `0x10`, `0x10`, and `0x100` (Verified with int_convert.py for decimal cap values).

## Score And Metadata Recommendation

- Current target score/metadata: `85/88`, owner `0000N4`, reconstructable true, emitter `0000N4`, blank C++.
- Recommended target score/metadata: `88/90`, owner/emitter/reconstructable unchanged, formal C++ inserted.
- Score rationale:
  - `COMPLETION:88`: current live MCP resolves target behavior, boundary bytes, xrefs, negative pointer routes, fixed host, fixed port, payload output slots, failure paths, owner/source placement, and formal C++. It remains below `90+` because dispatcher/caller route and final payload semantics remain unresolved.
  - `CONFIDENCE:90`: behavior and source route are strongly supported by current IDA facts and sibling docs. It remains below final-audit confidence because target is raw/non-function, decompile fails, and no original source symbols or direct dispatcher route were recovered.
- Score-improvement attempt:
  - Raw/no-function blocker: checked `lookup_funcs`, `decompile`, and disassembly; resolved as confidence cap, not C++ blocker.
  - Missing xref/pointer route: checked direct xrefs and VA/RVA byte patterns; no route found, documented as confidence cap.
  - Descriptive helper name: resolved to `ParseKornetWorldLauncher` from fixed host/failure strings and sibling naming.
  - Payload names: resolved to neutral KWG overlay; stronger semantic names rejected.
  - Support-doc incompleteness: implementation-ready support changes listed above.
  - Blank formal C++ blocker: resolved by code gate and sibling precedent.

## Open Questions With Attempted Resolution

- Dispatcher/caller route:
  - Evidence checked: xrefs to target start/end/successor/modelled neighbor, VA/RVA byte patterns, support docs, sibling reports.
  - Resolution: no route recovered. This caps score and keeps helper file-static but does not block C++.
- Original helper/member names:
  - Evidence checked: target strings, support docs, sibling naming, proposed source tree.
  - Resolution: exact original names unavailable. Use best source-facing inferred names; do not keep IDA labels.
- Payload semantic names:
  - Evidence checked: target writes, sibling overlay docs, global config field docs.
  - Resolution: use neutral KWG overlay names. Do not claim account/ticket/session semantics without future consumer evidence.
- IDA string transcription:
  - Evidence checked: `get_string` and raw bytes.
  - Resolution: use byte-backed roles and avoid exact Korean transcription in this pass.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- No manual coverage-report edit is requested.
- Do not edit `by-memory/-coverage-report.md`, `auto-generated/-ag-research-tracker.md`, or `auto-generated/-ag-coverage-report-by-memory.md`.
- Generated tracker/coverage rows should refresh through scoped validator runs after implementation and supervisor-owned `execute_report`.

## Expected Validators After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` only after supervisor implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [0002BP-KwgLauncherParser-source-quality-removed.md](0002BP-KwgLauncherParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After supervisor verifies implementation, supervisor-owned report execution should be:

> Executable block R002 was removed from this report and preserved verbatim in [0002BP-KwgLauncherParser-source-quality-removed.md](0002BP-KwgLauncherParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Validator Results

- Report-only pass: no by-* docs were edited, so no scoped validator was run.
- Local conversion command:
  - `tools/int_convert.py` was used for `0x2328`, `0x33d`, `0x10`, `0x100`, and `0x80`; documented conversions above are marked verified.
- No validator-generated output was relied on as current after implementation because implementation has not occurred yet.

## Changed Files

- Created: none.
- Modified: `tools/leaser/Agents/Agent-B003/research/0002BP-KwgLauncherParser-source-quality.md`
- Renamed: none.
- Report execution: leave blank during B-agent report-only pass. Supervisor runs `tools/validator.py execute_report ... --apply` after validation and implementation verification.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/90`; not final-audit.
- Remaining uncertainty: dispatcher/caller route, exact original source symbol names, and final semantic names for the four KWG payload strings.

## Follow-Up Actions

- Supervisor actions:
  - Validate this report and checklist under Rule 26.
  - If accepted, send Agent-B003 an implementation callback with the target/support file list above.
- B003 implementation callback actions:
  - Apply target and support doc changes at report-level detail, lease only immediate edit batches, run scoped validators, update this checklist with checkmarks/proof, and report generated-refresh state.
- Future research outside this assignment:
  - Whole parser-island dispatcher reconstruction, including [UID:0002BO], [UID:0002BP], [UID:0002BQ], and sibling raw starts.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor sent the active implementation callback in `Agent-B003/goal.md`.
- [x] Target/support docs to update: `by-memory/0x00491450-0x0049178d.KwgLauncherParser.md`, `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`. Proof: all six files were edited in the implementation callback.
- [x] Current target state and actual evidence checked recorded: live MCP session `398b87c1`, health, lookup, xrefs, byte gaps, literal bytes, failed decompile, disassembly behavior, unique signature, generated tracker/coverage stale rows, support docs, executed sibling reports, and negative pointer-route checks. Proof: preserved in this report and carried into target/support evidence sections where useful.
- [x] Metadata/score changes to apply: [UID:0002BP] `COMPLETION:85 -> 88`, `CONFIDENCE:88 -> 90`; leave owner/emitter/reconstructable unchanged. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N4`.
- [x] Score-limiting blockers researched to resolution or evidence-backed cap: raw non-function status, no direct xrefs, no stored pointer route, no dispatcher route, source-facing name, payload semantics, string typing, and blank-C++ blocker. Proof: target records these as confidence caps or resolved code-entry blockers; C++ is now entered for the exact child.
- [x] Owner/emitter/reconstructable changes to apply: no changes; confirm `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`. Proof: target metadata retained those values.
- [x] Split/rename/new-child changes to apply: none; correct successor padding to three `0xcc` bytes but do not create a padding child. Proof: target and parser aggregate now record `0x0049178d-0x00491790` as three `0xcc` bytes; no new child file was created.
- [x] Source-placement/range/IDA rename/type/comment changes to apply or confirm not applicable: add file-static/config-adjacent source placement; no IDA DB edits requested. Proof: target, parser aggregate, by-file, and by-class docs now identify file-static `ParseKornetWorldLauncher(RegistryConfig *config)` and no IDA DB edits were made.
- [x] First-draft C++ to apply: insert exact `ParseKornetWorldLauncher(RegistryConfig *config)` formal C++ block in the target multiline `RECONSTRUCTION_CPP CODE` block, leaving inline value blank. Proof: target multiline block now contains the accepted formal C++.
- [x] Third-party import directive: not applicable; confirm no `third_party_embeds/...` import and multiline C++ block contains the target C++ only. Proof: target uses direct multiline C++ and no third-party import directive.
- [x] Exact target/support doc facts to incorporate at report-level detail: fixed host, fixed port, four payload caps/offsets, state writes, failure paths, current MCP facts, negative evidence, rejected alternatives, score rationale, support string rows, and global config overlay. Proof: incorporated across target plus RegistryCommandLineParsers, RegistryConfig file/class, RegistryConfigChannelStartupStringData, and g_pConfig docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale two-byte padding correction, stale parent score correction, rejected class-method route, rejected no-code/no-owner route, rejected payload semantic overclaim, no direct xref/pointer route. Proof: target/support notes retain these as current caveats, corrections, or rejected alternatives.
- [x] Wave2/Wave3/generated artifacts encountered and ignored/rejected as stale: generated tracker/coverage stale `80/86`/`emits_code:false` rows, old Wave3/generated omission context, old manual coverage row; do not edit generated/manual coverage files. Proof: implementation did not manually edit generated reports or manual coverage reports.
- [x] Open questions to close or document as evidence-backed unresolved: dispatcher/caller route, original symbol names, final KWG payload semantics. Proof: target documents dispatcher/original-symbol/payload-semantic uncertainty with score/C++ impact.
- [x] Validators to run after callback: six scoped file validators listed above, with command_id, command_timestamp, exit code, ok count, and generated-refresh state recorded. Proof: validator results are recorded in the callback pass checklist below.
- [x] Generated report refresh expected: target validator should refresh `auto-generated/NexusTK/config/RegistryConfig.cpp` and generated coverage/tracker state through validator mechanics; check generated file header if generated C++ is inspected. No manual supervisor-owned coverage text needed. Proof: all six scoped validators were run with `--wait-generated`, and each reported `generated_refresh: completed`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: active supervisor callback in `goal.md` names this report and target.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: edited `by-memory/0x00491450-0x0049178d.KwgLauncherParser.md`, `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: [UID:0002BP] is `88/90`, owner/emitter/reconstructable unchanged, no split/rename/new child created, formal C++ inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve raw no-function/no-xref/no-pointer evidence, successor-padding correction, rejected class-method route, rejected no-code route, and payload-semantic caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target documents dispatcher/caller route, original symbol names, and final KWG payload semantics as confidence caps instead of C++ blockers.
- [x] Validators run and results recorded. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x00491450-0x0049178d.KwgLauncherParser.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004435`, timestamp `2026-06-27T20:49:11-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004436`, timestamp `2026-06-27T20:49:35-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\RegistryConfig.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004437`, timestamp `2026-06-27T20:49:52-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\RegistryConfig.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004438`, timestamp `2026-06-27T20:50:09-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004439`, timestamp `2026-06-27T20:50:26-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004440`, timestamp `2026-06-27T20:50:43-04:00`, exit `0`, `ok: 1`.
- [x] Generated report refresh completed by validator or generated freshness checked where relevant. Proof: every scoped validator above reported `generated_refresh: completed` with matching generated refresh command id/timestamp.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted implementation items remain unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BP-KwgLauncherParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002BP-KwgLauncherParser-source-quality.md","timestamp":"2026-06-27T20:56:57","uid":"0002BP"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BP-KwgLauncherParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002BP-KwgLauncherParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
