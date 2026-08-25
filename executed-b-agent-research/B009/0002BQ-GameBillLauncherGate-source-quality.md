** TARGET-REPORT-UID:0002BQ **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BQ GameBillLauncherGate Source-Quality Report

Agent: B009
Assignment: `B009-report-0002BQ-GameBillLauncherGate-source-quality-20260627`
Mode: report-only research; no by-* implementation edits until supervisor validation and callback.
Target: [UID:0002BQ] `by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md`
Report path: `tools/leaser/Agents/Agent-B009/research/0002BQ-GameBillLauncherGate-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002BQ] from `COMPLETION:85` / `CONFIDENCE:88` to `COMPLETION:88` / `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000N4`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000N4`, and add formal first-draft C++ for a file-static `ParseGameBillLauncher(RegistryConfig *config)` helper.
- Final disposition: source-authored RegistryConfig command-line parser child. It should emit as a scoped child under [UID:0000N4] `RegistryConfig.cpp`; [UID:000220] remains a parser-island aggregate/index with blank aggregate C++.
- Required action after supervisor validation: update the target and listed support docs at report-level detail, insert the exact formal C++ block below, then run scoped validators. Do not edit generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or the IDA DB.
- Confidence: high for exact local behavior, range, ownership route, and first-draft child C++ readiness; capped below final-audit because the dispatcher/caller route remains unrecovered and the source-facing helper name is inferred from sibling parser style rather than original symbols.

## Target

- Target UID: `0002BQ`
- Target path: `by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` still lists the target as `80/86`, reconstructable, zero emitted code. `auto-generated/-ag-coverage-report-by-memory.md` still renders `emits_code:false`. These generated rows are stale lead context only and must not be edited manually.
- Current supervisor classification: report-only source-quality research from the by-memory not-covered reconstructable queue.
- Current scores and parent state: target page is `85/88`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`; owner file [UID:0000N4] is `88/85`, class support [UID:0000BW] is `87/87`, and parent aggregate [UID:000220] is `86/89`.

## Current Target State

Existing metadata:

```yaml
COMPLETION: 85
CONFIDENCE: 88
CANONICAL_OWNER: 0000N4
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000N4
RECONSTRUCTION_CPP CODE: blank
```

Existing owner/emitter/reconstructable state is correct. The target is custom source-authored launcher/config code, not compiler/runtime glue. The current owner route through [UID:0000N4] `RegistryConfig` is supported by the parser island, startup-state field writes, sibling parser pages, and RegistryConfig file/class support docs.

Existing open questions and stale caveats:

- Still true: IDA does not model `0x00491790` as a function; no direct xref, caller, vtable route, or stored VA/RVA/raw-pointer route to `0x00491790` was recovered.
- Stale as a C++ blocker: the current page says final C++ should remain blank pending dispatcher/name/field work. That is now too conservative. Accepted sibling parser work treats raw/no-dispatcher status as a confidence cap, not as a blank-C++ blocker, once the local range, behavior, field writes, source placement, and helper style are resolved.
- Target prose should separate two cases it currently compresses: missing executable-tail delimiter returns quietly; null first token after tokenization enters the GameBill failure UI.
- Target prose still uses `param_1 + 0x2916ca` / `param_1 + 0x28de28`. Support docs now establish source-facing names sufficiently for first-draft C++: `m_startupReady` / `m_startupConnectionMode`.

Related target/support docs checked:

- [UID:0002BQ] `by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md`
- [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- [UID:0000N4] `by-file/RegistryConfig.md`
- [UID:0000BW] `by-class/RegistryConfig.md`
- [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- Accepted/current sibling context: [UID:0002BK] `LgInternetSessionLauncherParser`, [UID:0002BL] `LauncherHostPortPayloadParser`, [UID:0002BM] `MihosoftLauncherParser`, and active [UID:0002BR] `StructuredHostPortIdLauncherParser`.

## Supervisor Active Recheck

- The active user/supervisor instruction assigns only [UID:0002BQ] and requires report-only research first.
- No split execution is authorized by this assignment. The target does not need a split: live MCP decodes a single contiguous raw body at `0x00491790-0x004918dc`, with `0xcc` alignment before and after.
- No by-* target/support docs were edited in this report-only pass. No leases were taken.
- IDA MCP was available and used live. Active database/session for this report: `398b87c1`.

## Inference Research Guidance Check

I treated existing docs and accepted reports as leads and cross-checked target-local claims against live IDA MCP. Address adjacency alone is not used as ownership proof. The owner/source-placement conclusion combines incoming `ecx` object use, exact field writes, parser-island context, sibling file-static parser precedent, and current RegistryConfig support docs. Direct facts, documentation evidence, and inference are separated below.

Stale Wave2/Wave3 artifacts were not used as authority. Generated tracker and auto coverage rows were read only as stale queue/generated context; no generated reports were edited.

## MCP Provenance

Current live MCP pass:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Safe flow used: `initialize`, `tools/list`, `idb_list`, `server_health`, then read-only inspection tools.
- `initialize`: server `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`.
- `tools/list`: 65 tools returned. Current schemas require explicit `database` for IDB-backed inspection tools.
- Active database/session: `398b87c1`
- `idb_list` at `2026-06-27T13:11:28-04:00`: one active worker session, `input_path:E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `filename:NexusTK.exe.i64`, `created_at:2026-06-27T13:10:15.523204`, `is_analyzing:false`, `is_active:true`, worker pid `23700`.
- `server_health(database=398b87c1)`: `status:ok`, `idb_path:E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- No IDA DB edits, function definitions, comments, renames, type edits, patches, saves, process management, or MCP restarts were performed.

## Evidence Checked

IDA MCP/manual evidence performed in this pass:

- `lookup_funcs` on `0x00491790`, `0x004918dc`, `0x004918dd`, `0x004918e0`, and `0x00491b30`.
- `entity_query(kind=functions,min_addr=0x00491700,max_addr=0x00491b40)` for local function inventory.
- `xrefs_to` on `0x00491790`, `0x004918dc`, `0x004918dd`, `0x004918e0`, `0x006173a8`, `0x006173c0`, and `0x0060de18`.
- `find_bytes` for VA/RVA little-endian patterns `90 17 49 00`, `90 17 09 00`, `DC 18 49 00`, `DC 18 09 00`, `E0 18 49 00`, and `E0 18 09 00`.
- `get_bytes` around `0x0049178d`, `0x004918d8`, `0x006173a8`, `0x006173c0`, and `0x0060de18`.
- `get_string` on `0x006173a8`, `0x006173c0`, and `0x0060de18`.
- `decompile(addr=0x00491790)`.
- `insn_query(start=0x00491790,end=0x004918dc,include_disasm=true,include_fn=true)`.
- `make_signature_for_range(start=0x00491790,end=0x004918dc)`.
- `int_convert` for `0x14c`, `0xa28`, `0x400`, `0x2916ca`, `0x28de28`, and `5`.

Docs/reports checked:

- Current target/support docs listed above.
- Accepted executed reports for [UID:0002BK], [UID:0002BL], and [UID:0002BM].
- Active [UID:0002BR] report/support context.
- Generated queue/coverage rows for stale generated state.

Failed/unavailable checks:

- `decompile(0x00491790)` failed with `Decompilation failed at 0x491790`, which is expected because IDA has no function object at this raw start. The report relies on `insn_query`, bytes, xrefs, and support docs instead.
- `get_string(0x006173c0)` returns `"t"`, which is wrong for this UTF-16 text. The GameBill failure message was decoded from raw UTF-16LE bytes.

## IDA MCP Facts

Function/range facts:

- `lookup_funcs` reports `0x00491790`, `0x004918dc`, and `0x004918dd` as `Not a function`.
- Successor `0x004918e0` is modeled as `sub_4918E0`, size `0x248`.
- Later successor `0x00491b30` is modeled as `sub_491B30`, size `0xb65`.
- Function inventory for `0x00491700-0x00491b40` contains only `sub_4918E0` at `0x004918e0` and `sub_491B30` at `0x00491b30`; no function object exists at `0x00491790`.
- `insn_query` over `0x00491790-0x004918dc` decodes 98 instructions, all with `fn:null`, `truncated:false`.
- `make_signature_for_range(0x00491790-0x004918dc)` returned `unique:true`; signature begins with `55 8B EC 81 EC 28 0A 00 00 A1 ...`.
- `0x004918dc - 0x00491790 = 0x14c` / decimal `332` bytes (Verified with `int_convert`).

Boundary/data facts:

- `get_bytes(0x0049178d,24)` returns three predecessor `0xcc` bytes, then raw prologue bytes `55 8b ec 81 ec 28 0a 00 00 ...`.
- `get_bytes(0x004918d8,24)` captures the tail of `call __loaddll`, then four `0xcc` bytes at `0x004918dc-0x004918e0`, then the `sub_4918E0` prologue.
- Local stack reserve `0xa28` is decimal `2600` bytes (Verified with `int_convert`).
- The command-line buffer length `0x400` is decimal `1024` wide characters (Verified with `int_convert`).
- Field offset `0x2916ca` is decimal `2692810`; field offset `0x28de28` is decimal `2678312`; mode value `5` is `0x5` (Verified with `int_convert`).

Xref facts:

- `xrefs_to` reports zero xrefs to `0x00491790`, `0x004918dc`, `0x004918dd`, and `0x004918e0`.
- `find_bytes` found zero matches for raw VA/RVA byte patterns for the target start, target end, and successor start:
  - `90 17 49 00`, `90 17 09 00`
  - `DC 18 49 00`, `DC 18 09 00`
  - `E0 18 49 00`, `E0 18 09 00`
- `xrefs_to(0x006173a8)` returns exactly one data xref at `0x00491852`, from the `/GameBill` compare.
- `xrefs_to(0x006173c0)` returns exactly one data xref at `0x00491889`, from the failure message path.
- `xrefs_to(0x0060de18)` returns 24 refs to the shared wide-space delimiter; [UID:0002BQ] contributes refs at `0x0049180f` and `0x00491834`.

String facts:

- `get_string(0x006173a8)` returns `/GameBill`.
- Byte decoding of `0x006173a8` confirms UTF-16LE `/GameBill`.
- `get_string(0x0060de18)` returns a single space; bytes decode as UTF-16LE `" "`.
- `get_string(0x006173c0)` incorrectly returns `"t"`, but raw UTF-16LE bytes decode to: `이 버전의 바람의 나라는 GameBill 전용입니다. 입력정보에 오류가 있습니다.`

Instruction facts:

- `0x00491790-0x004917a6`: normal stack-frame prologue, `sub esp, 0A28h`, security cookie setup, save incoming `ecx` object pointer in `edi`, and call `sub_516030`.
- `0x004917ab-0x004917be`: call `GetCommandLineW` and copy into local buffer with `_wcscpy_s(commandLine, 0x400, GetCommandLineW())`.
- `0x004917c3-0x004917f2`: executable-tail skip. Search quote (`0x22`) first; if quote is found, advance past it and search for the next quote. If no quote was found, search for space (`0x20`) from the command-line start. If no delimiter is found, jump to normal epilogue at `0x0049187a` and return quietly.
- `0x004917f8-0x00491825`: initialize token context to zero and call `_wcstok_s(argumentText, L" ", &tokenContext)`; if the first token is null, branch to failure at `0x00491889`.
- `0x00491827-0x0049184c`: increment token counter before each later `_wcstok_s(NULL, L" ", &tokenContext)` call; if the counter reaches 8, return quietly before setting startup state.
- `0x0049184e-0x00491867`: preserve the binary's `test esi, esi; jle failure` guard, then compare `tokens[0]` with `/GameBill` via `__wcsicmp`; mismatch branches to failure.
- `0x00491869-0x00491872`: success writes `word ptr [edi+2916CAh] = 1` and `byte ptr [edi+28DE28h] = 5`.
- `0x00491879-0x00491888`: normal epilogue.
- `0x00491889-0x004918d7`: failure path pushes `0x006173c0`, formats to a `0x100` wide-character stack buffer through `sub_41B9B0`, obtains application/window strings through `sub_41D6A0`, `sub_4F0350`, `sub_4673E0`, and `sub_4651D0`, calls `MessageBoxW`, calls `PostQuitMessage(0)`, then calls `__loaddll(0)`.

## Behavior Reconstruction

[UID:0002BQ] is a compact `/GameBill` startup-mode gate:

1. Copy the process command line into a 1024-wide-character local buffer.
2. Skip the executable token using the parser-island quote/space delimiter idiom.
3. Return quietly if there is no executable-tail delimiter.
4. Tokenize the argument tail on the shared wide-space delimiter.
5. Enter the GameBill failure UI if the first token is null.
6. Accept one through seven non-null post-executable tokens for selector validation; eight or more non-null tokens hit the binary's guard return and do not write startup state.
7. Require case-insensitive token 0 equal to `/GameBill`.
8. On success, set only `m_startupReady = 1` and `m_startupConnectionMode = 5`.
9. Do not parse or write host, IP, port, id, payload, LG session id/key, Thrunet token, COM launcher-auth context, startup launcher id, or startup host buffer fields.
10. On selector/token failure, show the dedicated Korean GameBill failure text, post quit, and call `__loaddll(0)`.

Important correction for implementation: missing command-tail delimiter returns quietly; null first token after tokenization is failure UI.

## Heuristic / Inference Reanalysis And Validation

Raw helper role and liveness:

- Best inference: live source-authored file-static command-line parser helper under `RegistryConfig.cpp`.
- Evidence: real stack-frame source-style code, `GetCommandLineW`, `_wcstok_s`, `/GameBill` selector literal, localized failure UI, and RegistryConfig startup-state writes.
- Rejected alternative: compiler/runtime helper. The body is application-specific and uses game launcher strings/state fields.
- Remaining uncertainty: no direct dispatcher route is recovered. This caps confidence but does not block child C++ because local behavior and emitter route are otherwise resolved.

Source-facing name:

- Recommended name: `ParseGameBillLauncher(RegistryConfig *config)`.
- Evidence: accepted sibling helpers use `Parse<Mode>Launcher(RegistryConfig *config)` or close variants; the body parses a launcher mode selector and writes RegistryConfig startup state.
- Rejected `GameBillLauncherGate` as emitted function name: useful as documentation title, but "Gate" is documentation-shaped and less consistent with accepted source helper names.
- Rejected `RegistryConfig::ParseGameBillLauncher()`: plausible future class-method shape because the incoming `ecx` is the config object, but not currently proven without a dispatcher/caller or whole-island rehome.
- Rejected standalone GameBill file: overfits one brand literal and ignores shared RegistryConfig parser fields, delimiter literal, failure helpers, and sibling source placement.

Field/type naming:

- Use `m_startupReady` for `+0x2916ca` and `m_startupConnectionMode` for `+0x28de28`.
- Evidence: [UID:0000BW] startup parser field inventory and [UID:00028Q] global config page already document these offsets as shared startup/terminal-ready and connection-mode fields across parser siblings.
- Rejected host/port/payload field names for this target: no instructions write `+0x2915b4`, `+0x2915c4`, `+0x2916c4`, `+0x2918f0`, `+0x28d9e0`, or `+0x28da20`.

Failure string handling:

- Use `kGameBillInputErrorMessage` or equivalent local const/string helper in C++.
- Evidence: `0x006173c0` has exactly one xref from this target; raw bytes decode to the GameBill dedicated-client/input-error message.
- Rejected reliance on IDA string object: `get_string` incorrectly returns `"t"` at `0x006173c0`.

C++ readiness:

- Best decision: first-draft formal C++ is justified.
- Evidence: target is reconstructable, has nonblank emitter [UID:0000N4], current and recommended scores clear the `(COMPLETION + CONFIDENCE) / 2 > 85` gate, and the local source behavior is fully bounded by live MCP evidence.
- Rejected blank C++: the remaining direct-dispatcher gap is a confidence cap and is already handled that way for accepted sibling parser children.

## Ranked Ownership Analysis

### 1. [UID:0000N4] `RegistryConfig` file-level helper route

- Evidence for: all local writes target the incoming config object; sibling parser island and support docs route the command-line/session parser family through `RegistryConfig.cpp`; [UID:0000N4] owns the parser aggregate and clears the parent gate; accepted sibling reports use file-static helpers under the same route.
- Evidence against: no direct dispatcher/caller proves the exact source-level declaration form; no original symbol recovered.
- Decision: accepted. Keep `CANONICAL_OWNER:0000N4` and `EMITTER_UIDS:0000N4`.

### 2. [UID:0000BW] `RegistryConfig` class method route

- Evidence for: incoming `ecx` object pointer and object-field writes make class-method form plausible.
- Evidence against: no vtable edge, caller, dispatcher, or whole-island class-method reconstruction proves this specific helper was declared as a member method; support docs intentionally keep raw parser children file-level until the island is rehomed consistently.
- Decision: reject for current implementation; preserve as future source-placement caveat.

### 3. Standalone GameBill launcher module

- Evidence for: target has a dedicated `/GameBill` selector and dedicated failure message.
- Evidence against: it shares the RegistryConfig object, parser-island command-line idioms, startup-state fields, delimiter storage, and failure helper route; no standalone module evidence exists.
- Decision: reject.

### 4. No owner / non-emitting

- Evidence for: no direct caller and no IDA function object.
- Evidence against: owner/emitter route already exists through [UID:0000N4], behavior is source-authored and bounded, and current policy/sibling precedent permits first-draft child C++ for raw parser children when local semantics are resolved.
- Decision: reject.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x00491790-0x004918dc`, size `0x14c` / decimal `332` bytes (Verified with `int_convert`).
- Predecessor padding: `0x0049178d-0x00491790` is three `0xcc` bytes.
- Successor padding: `0x004918dc-0x004918e0` is four `0xcc` bytes before modeled `sub_4918E0`.
- No internal split is recommended. The entire range is one contiguous raw helper body with one normal epilogue and one failure tail.
- No aggregate reclassification is recommended. [UID:000220] remains a reconstructable source-bearing parser-island aggregate/index, but aggregate C++ should remain blank while exact children carry scoped C++.

## Positive Evidence Summary

- Direct IDA facts confirm a real source-style raw body: prologue, stack cookie, command-line copy, quote/space executable-tail scan, `_wcstok_s` tokenization, `/GameBill` compare, two startup-state writes, and failure UI/quit path.
- Literal xrefs are exact and unique for `/GameBill` and the failure text.
- Raw byte decoding corrects IDA's bad `get_string` result for the Korean message.
- Field writes match current RegistryConfig startup field naming and sibling parser support docs.
- Accepted sibling reports and implemented support docs establish the file-static parser helper pattern for raw/no-direct-xref parser island children.

## Negative Evidence Summary

- No modeled IDA function exists at `0x00491790`.
- No direct xref exists to `0x00491790`, target end addresses, or successor start.
- No simple stored VA/RVA/raw pointer byte patterns for target start/end/successor were found.
- No vtable/class-member route was recovered.
- No original helper name or source file path was recovered.
- These negatives cap confidence at `90` and keep the helper file-static/inferred, but they do not currently block owner/emitter route or formal child C++.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0002BQ] is a source-authored `/GameBill` launcher gate. | Confirmed | Live instructions, `/GameBill` xref, failure text xref, startup-state writes. | Runtime/helper alternative rejected; no generic/compiler pattern. | None for local behavior. |
| Direct owner/emitter should remain [UID:0000N4]. | Strong | RegistryConfig object writes, parser aggregate, [UID:0000N4]/[UID:0000BW] support docs, accepted sibling route. | Standalone file and class-method-only routes checked and rejected for current pass. | Dispatcher route would refine static-vs-member source shape. |
| Final source helper should be file-static `ParseGameBillLauncher(RegistryConfig *config)`. | Strong inference | Sibling `Parse*Launcher` pattern and target role. | `GameBillLauncherGate`, class method, and standalone names rejected. | Original symbols or dispatcher reconstruction could adjust exact spelling. |
| First-draft formal C++ is justified. | Strong | Code-entry gate clears; local behavior/fields/failure text are resolved; sibling precedent. | Raw/no-xref/no-function facts rechecked and treated as confidence caps. | Final audit should revisit once whole parser dispatcher is reconstructed. |
| `0x006173c0` is the GameBill failure text despite `get_string` returning `"t"`. | Confirmed | Raw UTF-16LE bytes decode to the Korean text; single xref from failure path. | IDA string typing checked and rejected as wrong. | None for target use. |

## Source Placement

Recommended source placement:

- `NexusTK/config/RegistryConfig.cpp`
- File-static helper: `static void ParseGameBillLauncher(RegistryConfig *config)`
- Parent [UID:000220] remains an aggregate/index. Do not emit a monolithic parser-island body.

Why this placement fits:

- The helper consumes only `RegistryConfig` startup state and shared RegistryConfig parser literals/helpers.
- The accepted parser-island style now keeps raw/no-direct-xref children as file-static helpers until a whole-island dispatcher route proves member-method declarations.
- The target is simpler than [UID:0002BK], [UID:0002BL], [UID:0002BM], and [UID:0002BR], all of which now use the same child-level source-ready pattern despite raw/no-dispatcher caveats.

Rejected placements:

- `RegistryConfig::ParseGameBillLauncher()` rejected for now because no caller/dispatcher/vtable route proves a class method.
- Standalone `GameBill` source file rejected for lack of source-module evidence.
- Aggregate [UID:000220] C++ rejected because by-memory C++ must stay within exact target ranges and the aggregate covers many child helpers.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested in this report-only pass.

Source-facing names recommended for documentation/C++ after supervisor approval:

- `ParseGameBillLauncher(RegistryConfig *config)` for the file-static helper.
- `m_startupReady` for `+0x2916ca`.
- `m_startupConnectionMode` for `+0x28de28`.
- `kGameBillInputErrorMessage` for the UTF-16 text at `0x006173c0`.
- Reuse accepted local helper abstractions such as `CopyLauncherCommandLineTail` and `AbortWithLauncherMessage` if they remain the supervisor-approved parser-island names.

Items intentionally left as evidence-only raw labels:

- `sub_516030`, `sub_41B9B0`, `sub_41D6A0`, `sub_4F0350`, `sub_4673E0`, and `sub_4651D0` remain raw evidence/helper dependencies in prose. They should not appear as final source-facing API in this target's C++ except through accepted local helper abstractions.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has emitter [UID:0000N4], currently averages `86.5`, and after this report should be `88/90`. The local behavior, source placement, field names, range, failure text, and sibling source pattern are resolved enough for formal first-draft child C++.

Recommended code: insert this exact content into [UID:0002BQ]'s formal `RECONSTRUCTION_CPP CODE:BEGIN/END` block if the supervisor accepts this report. This is formal insertion text, not an illustrative snippet.

```cpp
static void ParseGameBillLauncher(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t *tokens[8];
    wchar_t *tokenContext = NULL;

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    tokens[0] = wcstok_s(argumentText, L" ", &tokenContext);
    if (tokens[0] == NULL)
        AbortWithLauncherMessage(kGameBillInputErrorMessage);

    int tokenCount = 0;
    do
    {
        ++tokenCount;
        if (tokenCount >= _countof(tokens))
            return;

        tokens[tokenCount] = wcstok_s(NULL, L" ", &tokenContext);
    } while (tokens[tokenCount] != NULL);

    if (tokenCount <= 0 || _wcsicmp(tokens[0], L"/GameBill") != 0)
        AbortWithLauncherMessage(kGameBillInputErrorMessage);

    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}
```

Reason it preserves original behavior:

- `CopyLauncherCommandLineTail` must preserve the accepted parser-island quote/space executable-tail skip, including quiet return when no tail delimiter is found.
- `wcstok_s` and the `tokenCount >= _countof(tokens)` guard preserve the binary's eight-token quiet-return cap.
- The redundant `tokenCount <= 0` test preserves the binary's `test esi, esi; jle failure` shape.
- The helper writes exactly the two observed success fields and no host/port/payload/id/session fields.
- `AbortWithLauncherMessage(kGameBillInputErrorMessage)` must preserve the `sub_41B9B0` formatting, `MessageBoxW`, `PostQuitMessage(0)`, and `__loaddll(0)` failure route already used by sibling helper abstractions.

Reason it matches plausible original source shape:

- It follows accepted sibling file-static parser helpers under `RegistryConfig.cpp`.
- It uses source-facing names instead of raw IDA labels.
- It keeps the helper narrow and does not promote this one child to a standalone module or confirmed member method without dispatcher proof.

Third-party import directive: not applicable.

## Score And Metadata Recommendation

Current score/metadata:

```yaml
COMPLETION: 85
CONFIDENCE: 88
CANONICAL_OWNER: 0000N4
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000N4
RECONSTRUCTION_CPP CODE: blank
```

Recommended score/metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 0000N4
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000N4
RECONSTRUCTION_CPP CODE: formal first-draft ParseGameBillLauncher block
```

Score rationale:

- Completion should rise to `88` because this pass resolves the previous C++ blocker, corrects the missing-tail versus null-token behavior split, adds current session MCP provenance, confirms unique range signature, confirms no direct xref/VA/RVA pointer route, byte-decodes the bad-IDA-string failure text, ties field writes to current support-doc names, and supplies implementation-ready target/support doc changes.
- Confidence should rise to `90` because compact local behavior is triangulated by direct instruction stream, bytes, xrefs, unique signature, support field docs, and accepted sibling source-shape precedent.
- Do not raise higher: no direct dispatcher/caller route, no original source symbol/name, no class-method proof, and no final whole-island parser dispatcher reconstruction are recovered.

Score-improvement blockers and resolution:

- Raw/no-function start: rechecked with `lookup_funcs`, `entity_query`, `insn_query`, and decompile failure; resolved as a confidence cap, not a C++ blocker.
- No xrefs/routes: rechecked with `xrefs_to` and VA/RVA/raw pointer byte searches; resolved as a confidence cap and documented negative evidence.
- Descriptive-but-unproven names: resolved to best-supported inferred source names from accepted sibling style and support docs.
- C++ blank blocker: resolved with formal first-draft C++ and exact no-overreach boundaries.
- String typing issue: resolved by byte-level UTF-16LE decode.

## Recommended Target Doc Changes

Target path: `by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md`

Apply these changes after supervisor approval:

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:88` to `CONFIDENCE:90`.
- Keep owner/emitter/reconstructable metadata unchanged.
- Insert the exact formal first-draft C++ block from this report.
- Update Item Summary to say the current MCP session confirms the raw no-function `/GameBill` launcher gate, exact boundary/padding, no direct xref or VA/RVA pointer route, byte-decoded failure text, missing-tail and token-cap quiet returns, `m_startupReady` / `m_startupConnectionMode` writes, and source-ready file-static `ParseGameBillLauncher` C++.
- Update Rebuild Handling so C++ handling says first-draft file-static child C++ is present; raw/no-dispatcher remains a confidence cap only.
- Update Behavior to distinguish missing command-tail delimiter quiet return from first-token-null failure UI.
- Replace `param_1 + 0x2916ca` / `param_1 + 0x28de28` prose with `m_startupReady` / `m_startupConnectionMode` while preserving offsets.
- Add current MCP session `398b87c1` evidence and keep older June evidence only as historical/superseded.
- Add score rationale and a Changes entry for B009 source-quality report acceptance.

## Recommended Support Doc Changes

`by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`:

- Expand the [UID:0002BQ] child row from `/GameBill launch-mode gate` to file-static `ParseGameBillLauncher(RegistryConfig *config)` first-draft C++ ready.
- Record exact behavior: executable-tail skip, tokenization on wide space, first token must be `/GameBill`, missing-tail and eight-token cap return quietly, null first token or selector mismatch enters GameBill failure UI, success writes only `m_startupReady` and `m_startupConnectionMode = 5`.
- Add a source reconstruction note that [UID:0002BQ] follows the accepted file-static helper pattern for raw parser children and does not require aggregate C++.
- Preserve the no-direct-dispatch/no-pointer-route caveat.

`by-file/RegistryConfig.md`:

- Add [UID:0002BQ] to the command-line/session parser helper list as `static void ParseGameBillLauncher(RegistryConfig *config)`.
- Add a source-placement paragraph: GameBill requires `/GameBill`, writes only `m_startupReady` and `m_startupConnectionMode = 5`, has no host/port/payload/session writes, remains file-level/config-adjacent, and should not be promoted to a confirmed class method without a whole-island dispatcher route.
- Update parser field inventory/prose so `m_startupReady` and `m_startupConnectionMode` include [UID:0002BQ].
- Add [UID:0002BQ] as a negative example for no `+0x28d9e0/+0x28da20` payload/session writes if the relevant row/paragraph is touched.

`by-class/RegistryConfig.md`:

- Add [UID:0002BQ] to ownership notes as RegistryConfig-owned source logic with first-draft file-static `ParseGameBillLauncher(RegistryConfig *config)`.
- Update Startup Parser Field Inventory rows so `m_startupReady` and `m_startupConnectionMode` include the GameBill success path.
- Add a negative note to the mode-dependent payload/session row that GameBill, like Mihosoft, does not write `+0x28d9e0/+0x28da20`.
- Add [UID:0002BQ] to cross-reference lists if absent.

`by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`:

- Keep `0x006173a8` as wide `/GameBill`, xref `0x00491852`.
- Add `0x006173c0` as the GameBill dedicated-client/input-error UTF-16 text, xref `0x00491889`.
- Record that IDA `get_string` misreports `0x006173c0` as `"t"` and that the text must be preserved from raw UTF-16LE bytes.

`by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`:

- Add [UID:0002BQ] to `+0x2916ca` as a success-path writer of the startup/terminal-ready flag/state word.
- Add [UID:0002BQ] to `+0x28de28` as a success-path writer of mode byte `5`.
- Add [UID:0002BQ] as a negative example for no host/port/payload/id/session writes if the mode-dependent launcher payload/session row is touched.
- Add a Changes note for B009 support sync.

Generated reports and manual coverage:

- Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, project-level generated reports, or any `-coverage-report.md`.
- Generated `emits_code`/coverage state should refresh through source docs, scoped validators, and supervisor-owned executed-report lifecycle after implementation.
- No explicit manual coverage-report row is needed.

## Open Questions With Attempted Resolution

- Dispatcher/caller route: unresolved after `xrefs_to` and pointer-byte searches. This affects final class/static confidence but not current owner/emitter or first-draft child C++ readiness.
- Exact original helper name: unresolved; best inferred name is `ParseGameBillLauncher` based on accepted sibling style. This caps confidence but is better than preserving a documentation-shaped label or raw IDA name.
- Exact original field spellings: partially unresolved globally, but current support docs are strong enough to use `m_startupReady` and `m_startupConnectionMode` in this target's first-draft C++.
- Whole parser island member-method rehome: outside this target's implementation scope; current report preserves the caveat and keeps this child file-static.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No manual `-coverage-report.md` edit is requested or permitted. Do not write row text for validator-owned `auto-generated/-ag-*` reports.

## Expected Validators After Implementation

Run these from `source-3/project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002BQ-GameBillLauncherGate-source-quality-removed.md](0002BQ-GameBillLauncherGate-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

For the target validator, record `command_id`, `command_timestamp`, exit code, `ok` count, generated-refresh state, and whether generated `auto-generated/NexusTK/config/RegistryConfig.cpp` is equal/newer than the command metadata if inspected.

## Changed Files

- Created: none
- Modified manually in implementation callback: target [UID:0002BQ] `by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md`; support docs [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, [UID:0000N4] `by-file/RegistryConfig.md`, [UID:0000BW] `by-class/RegistryConfig.md`, [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`, [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`; this report checklist.
- Renamed: none
- Generated/tool-owned side effects: only from the requested scoped validator runs with `--apply`; generated reports, generated C++, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, and IDA DB were not manually edited.
- Report execution: not used; implementation was performed by direct supervisor callback after accepted report validation.

## Implementation Tracking Checklist

Implementation callback proof:

- [x] Supervisor validation required before implementation. Proof: user callback explicitly reported `Supervisor validation result: ACCEPTED for implementation` and overrode the report-only restriction for this accepted report only.
- [x] Target metadata updated: [UID:0002BQ] `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged. Proof: target validator `command_id:000000004402`, `command_timestamp:2026-06-27T13:29:13-04:00`, exit `0`, `ok:1`, emitted `completion_update 0002BQ ... 88`, `confidence_update 0002BQ ... 90`, and `canonical_owner_update 0002BQ ... 0000N4`.
- [x] Target formal C++ block populated with the exact `static void ParseGameBillLauncher(RegistryConfig *config)` body from this report. Proof: [UID:0002BQ] multiline `RECONSTRUCTION_CPP CODE` now contains the exact formal body; validator `000000004402` reported `autogen_cpp_update: 1` and `ok:1`.
- [x] Target behavior/evidence updated with MCP session `398b87c1`, raw no-function status, exact `0x14c` range size, boundary padding, no xrefs, no VA/RVA pointer hits, unique signature, byte-decoded `/GameBill` and failure text, token-cap quiet return, missing-tail quiet return, and startup state writes. Proof: [UID:0002BQ] Evidence/Behavior/Score Rationale sections updated; validator `000000004402`, exit `0`, `ok:1`.
- [x] Target source-placement notes updated: file-static helper under `RegistryConfig.cpp`, not standalone file, not confirmed class method, not aggregate C++. Proof: [UID:0002BQ] Rebuild Handling/Reconstruction Notes/Changes sections updated with rejected alternatives and generated-row ownership; validator `000000004402`, exit `0`, `ok:1`.
- [x] [UID:000220] parent aggregate updated with expanded [UID:0002BQ] child row and source reconstruction note for `ParseGameBillLauncher`. Proof: validator `command_id:000000004401`, `command_timestamp:2026-06-27T13:29:13-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
- [x] [UID:0000N4] `by-file/RegistryConfig.md` updated with [UID:0002BQ] helper/source-placement and field inventory support details. Proof: validator `command_id:000000004403`, `command_timestamp:2026-06-27T13:29:13-04:00`, exit `0`, `ok:1`, `reference_index_add 0002BQ`; pre-existing `missing_ref_uid 0003FW` warnings only.
- [x] [UID:0000BW] `by-class/RegistryConfig.md` updated with [UID:0002BQ] ownership note, field inventory additions, payload/session negative note, and cross-reference. Proof: validator `command_id:000000004406`, `command_timestamp:2026-06-27T13:32:24-04:00`, exit `0`, `ok:1`, `reference_index_add 0002BQ`; pre-existing `missing_ref_uid 0003FW` warnings only.
- [x] [UID:0003FV] string-data page updated with `0x006173c0` GameBill failure text, xref `0x00491889`, and raw UTF-16LE/IDA-string-typing caveat. Proof: validator `command_id:000000004404`, `command_timestamp:2026-06-27T13:29:14-04:00`, exit `0`, `ok:1`, `reference_index_add 0002BQ`; pre-existing `missing_ref_uid 0003TY` warnings only.
- [x] [UID:00028Q] `g_pConfig` page updated with [UID:0002BQ] as writer of `+0x2916ca` and `+0x28de28`, plus no host/port/payload/session negative notes. Proof: validator `command_id:000000004407`, `command_timestamp:2026-06-27T13:32:24-04:00`, exit `0`, `ok:1`, `reference_index_add 0002BQ`; pre-existing `missing_ref_uid 0003UJ/0003UA` warnings only.
- [x] Historical/stale assumptions preserved: old blank-C++ blocker superseded as a confidence cap; generated tracker/coverage rows left untouched as validator-owned stale/generated state; rejected alternatives and negative evidence preserved. Proof: [UID:0002BQ] and support doc Changes/Reconstruction Notes preserve no dispatcher/caller route, no original symbol, no class-method proof, no standalone GameBill module, no no-owner fallback, and generated-row ownership.
- [x] Scoped validators run after implementation. Proof: target `000000004402` at `2026-06-27T13:29:13-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`; aggregate `000000004401` at `2026-06-27T13:29:13-04:00`, exit `0`, `ok:1`; by-file `000000004403` at `2026-06-27T13:29:13-04:00`, exit `0`, `ok:1`; string data `000000004404` at `2026-06-27T13:29:14-04:00`, exit `0`, `ok:1`; by-class `000000004406` at `2026-06-27T13:32:24-04:00`, exit `0`, `ok:1`; g_pConfig `000000004407` at `2026-06-27T13:32:24-04:00`, exit `0`, `ok:1`.
- [x] Generated-refresh state recorded. Proof: target validator `000000004402` ran with `--wait-generated` and reported `generated_refresh: completed`, `generated_refresh_command_id: 000000004402`, `generated_refresh_timestamp: 2026-06-27T13:29:13-04:00`; queue status `command_id:000000004409`, `command_timestamp:2026-06-27T13:32:58-04:00`, and final recheck `command_id:000000004412`, `command_timestamp:2026-06-27T13:34:09-04:00`, both showed `queued jobs:0`, `processing jobs:0`, `queued generated refresh jobs:0`, and `processing generated refresh jobs:0`; final `generated refresh results:2224`.
- [x] Confirm no generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, IDA DB, or unrelated docs were edited manually. Proof: manual edits were limited to the accepted target/support by-* docs and this report; validator/tool-owned side effects were produced only by the requested scoped `validator.py --apply` commands; no IDA write tools were used.
- [x] Confirm implementation leases taken for by-* edits were released immediately after edit/validator batches. Proof: initial free-file batch lease succeeded for target, aggregate, by-file, and string-data; unlease after validation returned `Rejected[No active lease]` for those four because no B009 active lease remained, confirmed by `current_leases.md` at `2026-06-27T13:29:39.6024621-04:00` showing `No active leases`. Remaining batch lease succeeded for `by-class/RegistryConfig.md` and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`; unlease returned `Success` for both; final `current_leases.md` at `2026-06-27T13:32:40.7224038-04:00` showed `No active leases`.
- [x] Report accepted by supervisor for implementation. Proof: same accepted callback as above.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: every accepted file was edited and passed its scoped validator command listed above.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: target metadata and C++ applied; aggregate C++ intentionally blank and documented as aggregate/index only.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve raw no-function/no-route/no-symbol/no-class-method/no-standalone-module caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: dispatcher/caller and original symbol remain documented unresolved confidence caps, not blockers.
- [x] Validators run and results recorded. Proof: command IDs/timestamps/exit/ok values above.
- [x] Generated report refresh completed by validator or documented as deferred/current by header metadata. Proof: target wait-generated completed and final queue status idle; support validators reported `generated_refresh:deferred` but final queue status `000000004409` shows no queued/processing jobs.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no unapplied accepted items remain; no lease conflict remained after B011 leases cleared.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002BQ-GameBillLauncherGate-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002BQ-GameBillLauncherGate-source-quality.md","timestamp":"2026-06-27T13:39:52","uid":"0002BQ"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BQ-GameBillLauncherGate-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002BQ-GameBillLauncherGate-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
