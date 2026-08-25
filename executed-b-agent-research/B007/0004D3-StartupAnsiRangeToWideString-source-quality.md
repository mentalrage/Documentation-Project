** TARGET-REPORT-UID:0004D3 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0004D3 StartupAnsiRangeToWideString Source-Quality Research


## Finalized Report / Current Recommendation
- Current disposition: UID0004D3 remains assigned to [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md), remains source-emitting, and now carries the direct range-widening formal C++ body accepted by supervisor Gate 1. The stale `std::string` staging plus `mbstowcs_s` body is historical and no longer represents the by-* target or generated output.
- Final disposition: source-ready with `COMPLETION:88`, `CONFIDENCE:91`, unchanged `CANONICAL_OWNER:0000O5`, unchanged `RECONSTRUCTABLE:TRUE`, unchanged `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`, and a direct narrow-range-to-wide-string source body.
- Applied action: replaced the target formal C++ block with the formal block in `## First-Draft C++ Recommendation`; added the MCP-backed range, caller, callee, byte, and rejected-API evidence to the target and stale support docs listed in this report.
- Confidence: strong for range, owner, two-call-site caller set, SSO/wide-string destination initialization, reserve and append dependency roles, and source-placement. Confidence remains capped below final-audit levels because the exact original source expression could have been an STL range constructor, a small helper wrapper, or a manual loop, and the helper relies on project/compiler signed-`char` behavior.

## Supporting Research
- Lifecycle history: this artifact began as B007 report-only research. After supervisor Gate 1 accepted the report, B007 applied the implementation callback to the target/support by-* docs and updated this report's ledger/checklist. B007 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, report moves, archive commands, generated-file manual edits, coverage edits, validator-state manual edits, or supervisor-ledger edits.
- Supervisor-restored MCP provenance: B007 used the existing supervisor-provided active IDA MCP session `ddf5b602` read-only. `idb_list` reported one active NexusTK session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID/worker PID `20820`, `is_analyzing:false`, `is_active:true`. `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- Prior history: B008's StartupWindow family report created UID0004D3 and inserted the current formal C++ body, which explains why the research tracker shows report count `0` for this specific UID even though the page exists and emits generated output. B003's executed UID0002U5 report later documented the shared `0x00423060` narrow-range-to-wide SSO append helper used by UID0004D3. This report rechecks those leads against current session `ddf5b602`.
- Historical pre-callback by-* state: before this callback, `by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md` recorded `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and a formal `std::wstring StartupAnsiRangeToWideString(const char *first, const char *last)` body that constructed a temporary `std::string`, called `mbstowcs_s`, and returned a wide string.
- Current by-* state after implementation: the target records `COMPLETION:88`, `CONFIDENCE:91`, unchanged owner/reconstructable/emitter fields, blank optional position, and the direct `[first, last)` range-widening formal body.
- Current generated output state: `auto-generated/NexusTK/app/StartupWindow.cpp` header records `validator-command-id: 000000006519`, `validator-refreshed-at: 2026-07-04T19:31:54-04:00`, and emits UID0004D3 as the direct range-widening helper with `text.reserve(last - first)` and `text.push_back(static_cast<wchar_t>(*it))`; no UID0004D3 `mbstowcs_s` body remains. The generated caller uses UID0004D3 at the minimap-version range and hash-list text range.

## Target
- Target UID: `0004D3`.
- Target path: `by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md`.
- Historical source queue/report row before implementation: `auto-generated/-ag-research-tracker.md` under not-covered reconstructable by-memory rows recorded UID0004D3 as `86/88`, average `87.0`, reconstructable `true`, report count `0`.
- Current supervisor classification: implementation-callback artifact for an already source-emitting exact child; supervisor-owned execution/lifecycle state is external to this report.
- Current scores and parent state: target `88/91`, owner/emitter [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md), reconstructable true. Parent/container [UID:0001IO][StartupWindowUpdateCheck](../../../by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) remains a non-emitting split/index page; UID0004D3 is one exact source-bearing child.

## Current Target State
- Current metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`.
- Existing owner/emitter/reconstructable state: owner and emitter route are already correct. UID0004D3 is a file-local StartupWindow parse/conversion helper used only from `StartupWindow__RunUpdateCheck`.
- Current C++/emitter state: the target emits a direct `static std::wstring StartupAnsiRangeToWideString(const char *first, const char *last)` helper that reserves `last - first`, loops from `first` to `last`, pushes `static_cast<wchar_t>(*it)`, and returns the wide string.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: the stale historical body implied CRT multibyte conversion and NUL-terminated `c_str()` semantics. The implemented body now follows the binary's wide SSO destination, `last - first` reserve, and half-open byte append behavior through shared helper `0x00423060`. Exact original source spelling remains inferred, but that is a confidence cap rather than a blocker.
- Related target/support docs checked: target page, parent `StartupWindowUpdateCheck`, exact caller `StartupWindowRunUpdateCheck`, `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `CurlWriteCallback`, shared `0x00423060` helper, B008 StartupWindow executed report, B003 shared helper executed report, B010 StartupWindowUpdateCheck executed report, generated `StartupWindow.cpp`, generated research tracker, generated by-memory coverage reports.
- Current artifact/lifecycle status: this report records B007's implementation callback incorporation and scoped validation results. Supervisor report execution/lifecycle state remains external to this file.

## Executive Recommendation
- Best direct owner: [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md).
- Assignment/source route: keep UID0004D3 as a StartupWindow file-local helper emitted through `StartupWindow.cpp`.
- Source-quality action: keep the source-facing name `StartupAnsiRangeToWideString` as a stable project name, but document that "ANSI" here means a narrow/byte range from fetched startup text, not a `MultiByteToWideChar`/code-page API call.
- C++ action: replace the current API-shaped body with a direct half-open range widening loop or equivalent range-constructor expression. The report recommends the explicit loop formal block below because it preserves the observed reserve-plus-append behavior and avoids the current `mbstowcs_s` semantics.
- Remaining blocked condition: none blocking implementation. The exact original source expression and whether the developer wrote an STL range constructor versus an explicit loop remain confidence caps, not blockers.

## Supervisor Active Recheck
- Original triggering instruction: Agent-B007 `goal.md` assigned UID0004D3 report-only research and required current IDA MCP evidence, exact required B-agent headings, a complete Claim And Incorporation Ledger, an Implementation Tracking Checklist, and exact formal C++ insertion text if code was recommended. The implementation callback has since applied the accepted report.
- Split status: no split repair is required. The exact child already exists at `0x00581cf0-0x00581d30`, and current MCP confirms the surrounding padding/function boundaries.
- Source-bearing children in scope: only UID0004D3 is assigned here. Neighboring `CurlWriteCallback`, `StartupWindowScalarDeletingDestructor`, `StartupNoticeDrawPcxImage`, `AnsiSmallStringFindFrom`, and `AnsiSmallStringSubstring` are support context, not callback scope for this report.

## Inference Research Guidance Check
- I treated generated C++ and earlier B008/B010 reports as leads, not authority. The current `mbstowcs_s` body was rechecked against session `ddf5b602` before making a recommendation.
- IDA facts: current MCP range, decompile, disassembly, callers, callees, xrefs, import query, and bytes.
- Documentation evidence: by-* pages and executed reports explain the target's placement and the shared helper dependency.
- Inference: the source expression is reconstructed as a human-written StartupWindow-local range-to-wide helper because the binary has only two StartupWindow call sites and no data/table route. The exact expression is inferred because current IDB has no original symbol/type metadata.
- Wave2/Wave3 artifacts: no current recommendation relies on Wave2/Wave3 generated assumptions. Generated `StartupWindow.cpp` is used only to identify current output and the stale formal body.

## Heuristic / Inference Reanalysis And Validation
- API/source-shape issue: the existing C++ body models a NUL-terminated multibyte conversion through `mbstowcs_s`. MCP `callees 0x00581cf0` returns only `sub_423EB0` and `sub_423060`. MCP `imports_query` finds `MultiByteToWideChar` imported at `0x0060d120`, but `xrefs_to 0x0060d120` with a 20-hit cap shows unrelated conversion callers starting around `0x0045c2a0` and no UID0004D3 hit; `search_text` for `MultiByteToWideChar` inside `0x00581cf0-0x00581d30` returns zero hits. There is also no `mbstowcs*` import hit. Reject API-shaped C++ for this exact target.
- Exact input bounds: decompile and disassembly agree that the target takes two semantic stack arguments, `first` and `last`, computes `last - first` at `0x581d11-0x581d15`, reserves that many wide characters through `0x00423eb0`, then passes `first` and `last` to `0x00423060`. The binary pushes a third stack value, but B003's shared-helper report and current disassembly show that the shared helper cleans but does not semantically use it; UID0004D3 should not expose a third source parameter.
- Output object: IDA recovers `ecx` as a destination object pointer. The target writes `+0x10 = 0`, `+0x14 = 7`, and an inline UTF-16 NUL at `[object+0]`, matching the project `std::wstring`/SimpleUString SSO-7 shape documented by UID0002U5. Source-level C++ should return a wide string by value, not expose the decompiler's hidden destination pointer.
- Caller set: `xrefs_to 0x00581cf0` reports exactly two code refs, both in `StartupWindow__RunUpdateCheck`: `0x00580e3f` and `0x00580fb6`. No data refs, VA pointer bytes, or RVA pointer bytes were found for `0x00581cf0`.
- Caller roles: current RunUpdateCheck decompile context shows `0x00580e3f` converting the minimap version substring and copying it with `wcscpy_s(..., 0x21u, ...)`; `0x00580fb6` converts the fetched `HashList.txt` text and passes it to the MiniMapVersionManager hash-list update path. Those uses are StartupWindow update/minimap parsing, not generic runtime conversion ownership.
- Shared helper relationship: current `xrefs_to 0x00423060` reports two code refs, `0x00421bc5` in fitting-room catalog JSON parsing and `0x00581d22` inside UID0004D3. This proves `0x00423060` is a shared string helper dependency, not the source owner of UID0004D3.
- Source-facing name: `StartupAnsiRangeToWideString` remains acceptable because it describes the startup-local caller role and existing generated source. The report caps confidence because "ANSI" may overstate code-page conversion; docs should define it as raw narrow/byte range widening.
- Rejected alternatives: generic `StringUtil` owner for UID0004D3, direct `SimpleUString` owner for UID0004D3, `MultiByteToWideChar`/`mbstowcs_s` implementation, raw `sub_581CF0` naming, third-argument source API, no-owner/non-emitting route, and broad merge into the parent aggregate are rejected by current evidence.

## Evidence Standards Used
- IDA MCP evidence used: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, `imports_query`, `find_bytes`, and bounded `search_text`, all against session `ddf5b602`.
- Binary evidence used: exact function range, basic block count, disassembly, target bytes, predecessor padding, successor function start, caller/callee lists, xrefs, import/xref negative evidence, and pointer-pattern negative evidence.
- Documentation evidence used: current target/support by-* docs, generated source output, generated tracker/coverage rows, and matching executed B reports.
- Strength: direct IDA facts are strong enough to repair the C++ source shape and raise scores. Confidence is not higher because original source metadata is absent and the exact source spelling could have been a concise STL range constructor rather than the explicit loop recommended for behavior clarity.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` and `server_health` for session `ddf5b602`.
  - `lookup_funcs` for `0x00581ce6`, `0x00581cf0`, `0x00581d2f`, `0x00581d30`, caller sites `0x00580e3f` and `0x00580fb6`, and dependencies `0x00423060` and `0x00423eb0`.
  - `analyze_function` and `decompile` for `0x00581cf0`.
  - `disasm 0x00581cf0` with 50-instruction cap and total count.
  - `xrefs_to` for `0x00581cf0`, `0x00423060`, `0x00423eb0`, and `0x0060d120`.
  - `callees` for `0x00581cf0` and `0x00423060`.
  - `get_bytes` for `0x00581ce6` size 10, `0x00581cf0` size 64, and `0x00581d30` size 16.
  - `imports_query` for `MultiByteToWideChar` and `mbstowcs*`.
  - `find_bytes` for target VA bytes `F0 1C 58 00` and target RVA bytes `F0 1C 18 00`, limit 20.
  - `search_text` for `MultiByteToWideChar` restricted to `0x00581cf0-0x00581d30`.
  - Decompile of `StartupWindow__RunUpdateCheck` restricted to extracting lines around `sub_581CF0`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, parent `StartupWindowUpdateCheck`, exact `StartupWindowRunUpdateCheck`, `StartupWindow` file/class pages, `CurlWriteCallback`, UID0002U5 shared helper, `auto-generated/NexusTK/app/StartupWindow.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md`, B003 `0002U5-SharedNarrowRangeToWideSsoAppendHelper-source-quality.md`, B010 `0001IO-StartupWindowUpdateCheck-source-quality.md`, and matching search hits in agent notes/reports.
- Negative checks performed: no `mbstowcs*` import hit, no target text hit for `MultiByteToWideChar`, no `MultiByteToWideChar` xref in UID0004D3, no target VA/RVA pointer bytes, no target data refs, no non-StartupWindow callers for UID0004D3, and no proof that the third stack argument is a real source parameter.
- Failed, unavailable, or intentionally skipped checks and why: during the original report-only evidence pass no validators were run. During the implementation callback, scoped validators were run only for changed by-* files and are recorded in `## Validator Results`. No broad callgraph/listing/type scans were run because the current goal required narrow bounded MCP calls.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004D3-01 | UID0004D3 is an exact IDA function at `0x00581cf0-0x00581d30`, size `0x40` / 64 bytes, with one basic block and complexity 1. | Strong | `lookup_funcs`, `analyze_function`, `disasm` on `ddf5b602`; predecessor `0x00581ce6` is not a function and successor `0x00581d30` starts `sub_581D30`. | Target `Status` / `Evidence`; parent child row | Incorporated exact range/size/function facts. | applied: target `Status` and `Evidence` now state exact range/size/function facts; parent row now identifies UID0004D3 as exact size `0x40`. |
| C-0004D3-02 | Predecessor boundary is ten `0xcc` bytes at `0x00581ce6-0x00581cf0`; successor begins at `0x00581d30` with scalar deleting destructor bytes. | Strong | `get_bytes` returned ten `0xcc` bytes, target 64 bytes, successor first 16 bytes. | Target `Evidence`; parent split row | Incorporated bytes/padding facts. | applied: target `Evidence` records ten predecessor `0xcc` bytes and successor bytes; parent split row records the padding and successor boundary. |
| C-0004D3-03 | The helper initializes a wide SSO destination: `+0x10` length 0, `+0x14` capacity 7, inline UTF-16 NUL at offset 0. | Strong | Disassembly `0x581d00`, `0x581d07`, `0x581d0e`; decompile writes `Src[4]=0`, `Src[5]=7`, `*(_WORD *)Src=0`. | Target `Evidence` / `Behavior` | Incorporated destination-layout facts. | applied: target `Evidence` records hidden wide-SSO destination initialization and the confidence cap for source spelling. |
| C-0004D3-04 | The semantic inputs are a half-open narrow byte range, `first` and `last`; target reserves `last - first`. | Strong | Disassembly `mov esi,[arg_0]`, `mov edi,[arg_4]`, `sub eax, esi`, `call sub_423EB0` at `0x581d16`. | Target `Behavior`; formal C++ | Incorporated as two-parameter source API. | applied: target formal C++ uses `first`/`last`, reserves `last - first`, and loops over `[first, last)`. |
| C-0004D3-05 | The third stack argument is not a source-facing parameter for UID0004D3. | Strong | Current UID0004D3 pushes duplicate `end`; B003 UID0002U5 report and shared helper behavior show the helper cleans but does not semantically read the third value. | Target `Evidence`; rejected alternatives | Preserved rejection of three-argument public/source helper. | applied: target evidence and support notes state no third source parameter; formal C++ has only `first` and `last`. |
| C-0004D3-06 | UID0004D3 does not call `MultiByteToWideChar`, `mbstowcs_s`, or another conversion API directly. | Strong | `callees 0x00581cf0` lists only `0x00423eb0` and `0x00423060`; `imports_query` finds `MultiByteToWideChar` but no `mbstowcs*`; bounded target `search_text` for `MultiByteToWideChar` returns zero. | Target C++ / `Negative Evidence` | Replaced current `mbstowcs_s` formal body. | applied: target formal C++ and generated output no longer contain the UID0004D3 `mbstowcs_s` body; target evidence records API negatives. |
| C-0004D3-07 | The actual conversion equivalent is byte-by-byte widening through shared helper `0x00423060`. | Strong | `callees 0x00581cf0`; `xrefs_to 0x00423060`; shared helper disassembly `movsx ax, byte ptr [eax]`, stores `dx`, writes terminator. | Target `Evidence`; shared-helper cross-reference | Documented dependency and behavior. | applied: target/support docs identify `0x00423060` as the shared byte-widening append dependency and preserve shared-helper ownership as separate. |
| C-0004D3-08 | Caller set is exactly two code refs in `StartupWindow__RunUpdateCheck`, at `0x00580e3f` and `0x00580fb6`. | Strong | `xrefs_to 0x00581cf0` result count 2, both in `0x00580870` `StartupWindow__RunUpdateCheck`. | Target `Cross-References`; parent/exact caller docs | Incorporated exact caller facts. | applied: target, parent, exact caller, file, and class docs record the two RunUpdateCheck call sites. |
| C-0004D3-09 | The first caller converts the minimap field substring, then copies the wide result to the minimap version buffer; the second converts hash-list text for MiniMapVersionManager update. | Strong | RunUpdateCheck decompile contexts around `0x00580e3f` and `0x00580fb6`; generated RunUpdateCheck source lines use `StartupAnsiRangeToWideString` for minimap and hash list. | Target `Evidence`; optional RunUpdateCheck support note | Incorporated caller-role facts without duplicating full caller body. | applied: target and exact caller support note record minimap substring and hash-list text roles. |
| C-0004D3-10 | Owner/emitter should stay `0000O5` StartupWindow, not StringUtil/SimpleUString/no-owner. | Strong | Two StartupWindow callers only; target is local wrapper over shared string dependencies; shared helper itself has separate two-caller StringUtil/SimpleUString ownership. | Target metadata/source placement; file/class support docs | Preserved owner/emitter route. | applied: target metadata keeps `CANONICAL_OWNER:0000O5` and `EMITTER_UIDS:0000O5`; file/class support notes keep StartupWindow-local placement. |
| C-0004D3-11 | Recommended formal C++ should be a direct range-widening `std::wstring` helper, not the current `std::string` plus `mbstowcs_s` body. | Medium-high | MCP target/callee facts and shared-helper disassembly; source-shape inference from StartupWindow generated helper usage. | Target formal C++ block; generated output after validator | Applied formal block from this report during callback. | applied: target formal block contains the direct range-widening helper; generated `StartupWindow.cpp` contains UID0004D3 with `text.reserve(last - first)` and `text.push_back(static_cast<wchar_t>(*it))`. |
| C-0004D3-12 | Score should improve to `88/91`, not higher, after target/support incorporation. | Medium-high | Current direct MCP evidence resolves API/caller/blocker issues; remaining uncertainty is exact original source expression, signed-char spelling, and caller buffer-size detail. | Target metadata; support docs/checklist | Applied score recommendation during callback. | applied: target metadata is `COMPLETION:88`, `CONFIDENCE:91`; support docs record the confidence caps. |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation:
  - `sub_581CF0` is an exact IDA function at `0x00581cf0`, size `0x40`.
  - The function initializes a wide-string destination object, reserves `last - first`, calls `0x00423060`, and returns the destination pointer.
  - The only target callers are two `StartupWindow__RunUpdateCheck` call sites.
  - The shared append helper performs byte-to-16-bit widening and terminator writes, matching a direct range-to-wide-string helper.
- Corroborating documentation/generated-report evidence:
  - Target and generated reports already route UID0004D3 through StartupWindow and generated `StartupWindow.cpp`.
  - B010 described the target as StartupWindow-local; B003 documented the `0x00423060` dependency as a shared append helper and warned against exposing its third stack argument as a source method.
  - Generated `RunUpdateCheck` source already uses a two-argument `StartupAnsiRangeToWideString` helper at the two caller roles.
- Strongest inference chain: two StartupWindow call sites plus no data/pointer route prove local placement; target decompile/disassembly plus shared-helper disassembly prove direct half-open byte-range widening; therefore source should be a local `std::wstring` range helper rather than API conversion or hidden-destination decompiler form.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs`: `0x00581cf0` -> `sub_581CF0`, size `0x40`; `0x00581d2f` remains inside it; `0x00581d30` -> `sub_581D30`, size `0x82`; `0x00581ce6` is not a function.
  - `analyze_function`: prototype recovered as `void **__thiscall(void **Src, char *, char *, int)`, size `64`, strings `[]`, constants `[]`, callees `sub_423EB0` and `sub_423060`, caller `StartupWindow__RunUpdateCheck`, one basic block, cyclomatic complexity `1`.
  - `disasm`: 27 instructions, total 27, ending `retn 0Ch`.
- Data/table/padding facts:
  - `get_bytes 0x00581ce6 size 10`: ten `0xcc` bytes.
  - `get_bytes 0x00581cf0 size 64`: starts `55 8b ec 53 8b d9 33 c0 56 8b 75 08 57 8b 7d 0c`, contains reserve call bytes and append call bytes, ends `5f 5e 8b c3 5b 5d c2 0c 00`.
  - `get_bytes 0x00581d30 size 16`: successor starts `55 8b ec 53 8b d9 80 7b 04 00 c7 03 70 d4 62 00`.
- Xref facts:
  - `xrefs_to 0x00581cf0`: `0x00580e3f` and `0x00580fb6`, both code refs in `StartupWindow__RunUpdateCheck`.
  - `xrefs_to 0x00423060`: `0x00421bc5` in `sub_421A40` and `0x00581d22` in `sub_581CF0`.
  - `xrefs_to 0x00423eb0`: `0x00421bb8` in `sub_421A40` and `0x00581d16` in `sub_581CF0`.
- Vtable/global/type facts:
  - No vtable/global route exists for UID0004D3. The source route is ordinary code-call locality under StartupWindow.
  - `find_bytes` for target VA `F0 1C 58 00` and target RVA `F0 1C 18 00` returned zero matches.
- Negative IDA facts:
  - `imports_query` found `MultiByteToWideChar` at `0x0060d120`, but xref results are unrelated to UID0004D3; no `mbstowcs*` import was found.
  - `search_text` for `MultiByteToWideChar` inside the target range returned zero hits.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00581ce6-0x00581cf0` | ignored padding span in parent | callback-to-convert alignment | FALSE if materialized | parent aggregate | N/A | ten `0xcc` bytes |
| `0x00581cf0-0x00581d30` | [UID:0004D3][StartupAnsiRangeToWideString](../../../by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md) | StartupWindow-local half-open narrow range to wide string helper | TRUE | [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md) | current `86/88`, recommended `88/91` | source-ready with formal C++ body repair |
| `0x00581d30-0x00581db2` | [UID:0004D4][StartupWindowScalarDeletingDestructor](../../../by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md) | compiler scalar deleting destructor wrapper | FALSE | StartupWindow class context | `86/90` in current docs | outside UID0004D3 scope |
| `0x00423060-0x00423204` | [UID:0002U5][SharedNarrowRangeToWideSsoAppendHelper](../../../by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) | shared string append dependency | TRUE with no standalone method body | SimpleUString/StringUtil support | `87/90` | already documented dependency |
| `0x00423eb0` | no exact target page in this report | reserve/capacity helper dependency | separate support pocket | string support | N/A | dependency only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00580e3f` | code ref to `0x00581cf0` in `StartupWindow__RunUpdateCheck` | converts minimap response substring from `responseText` to wide temporary, then caller copies it with `wcscpy_s` |
| `0x00580fb6` | code ref to `0x00581cf0` in `StartupWindow__RunUpdateCheck` | converts fetched `HashList.txt` text to wide temporary, then caller passes it to MiniMapVersionManager update |
| `0x00581d16` | call from UID0004D3 to `0x00423eb0` | reserve destination capacity for `last - first` |
| `0x00581d22` | call from UID0004D3 to `0x00423060` | append/widen half-open narrow byte range into destination |
| `0x00421bc5` | other code ref to `0x00423060` | fitting-room catalog parser uses the same shared append helper, proving dependency sharing but not UID0004D3 ownership |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page already places UID0004D3 under StartupWindow and states it is used by `RunUpdateCheck` at `0x00580e3f` and `0x00580fb6`.
  - Parent `StartupWindowUpdateCheck` row already maps `0x00581cf0-0x00581d30` as an IDA helper, size `0x40`.
  - `StartupWindowRunUpdateCheck` formal C++ already has two high-level calls to `StartupAnsiRangeToWideString`.
  - UID0002U5 shared helper page already documents the `0x00581d22` call and the SSO-7 append helper role.
- Existing docs that are stale, incomplete, or contradicted:
  - Target formal C++ and generated output use `mbstowcs_s`, which is contradicted by current callee/import/disassembly evidence.
  - Target evidence is too thin for `86/88` after current MCP recheck; it should record exact range, bytes, callers, callees, dependency behavior, and negative API evidence.
  - Parent/file/class support docs are broadly correct but should stop implying the helper is merely a generic "ANSI-to-wide conversion" without documenting that the conversion is byte-range widening, not `MultiByteToWideChar`/locale conversion.
- Generated/coverage report state:
  - Generated `StartupWindow.cpp` currently emits the stale `mbstowcs_s` body at UID0004D3.
  - Generated tracker shows direct report count `0`, explaining why this B007 report is needed despite existing code output.

## Ranked Ownership Analysis

### 1. StartupWindow file-local helper
- Evidence for: only two code refs, both from `StartupWindow__RunUpdateCheck`; helper consumes StartupWindow update/minimap parsing ranges; current by-file and by-memory generated coverage route through UID0000O5; parent aggregate places surrounding helpers in StartupWindow update-notice island.
- Evidence against: helper depends on shared string support routines also used by fitting-room parsing.
- Decision: accepted. Dependency sharing does not override caller-local wrapper ownership.

### 2. StringUtil/SimpleUString helper ownership
- Evidence for: target uses `0x00423eb0` reserve and `0x00423060` shared narrow-to-wide append helper; destination layout is `std::wstring`/SimpleUString SSO-7.
- Evidence against: UID0004D3 itself has only StartupWindow callers and is a small wrapper that applies shared string operations to startup HTTP response ranges. The actual shared helper has its own page/owner and only two refs.
- Decision: reject for UID0004D3. Keep `0x00423060` as dependency/cross-reference.

### 3. Runtime/API conversion helper
- Evidence for: project imports `MultiByteToWideChar`; current generated body calls `mbstowcs_s`.
- Evidence against: target callees are only internal reserve/append helpers; bounded target search for `MultiByteToWideChar` returns zero; `mbstowcs*` import query returns zero; shared helper disassembly shows sign-extension and 16-bit stores, not code-page conversion.
- Decision: reject. Current API-shaped formal body is stale.

### 4. No-owner/non-emitting target
- Evidence for: no original symbol/source name proof.
- Evidence against: reconstructable true, valid emitter route, direct two-call source usage, exact function boundary, source-like behavior, and existing generated output.
- Decision: reject. Keep emitting through StartupWindow.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Keep [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md) and source-facing helper name `StartupAnsiRangeToWideString`.
- Likely full contents: only this helper's body changes for UID0004D3; the broader StartupWindow source file already hosts the RunUpdateCheck helpers.
- Candidate related items that belong: UID0004D6 and UID0004D7 remain adjacent StartupWindow parse helpers but are separate targets.
- Candidate related items rejected: UID0002U5 belongs to shared string support, not StartupWindow.
- Standalone, narrow, or broad source-file inference: narrow file-local helper inside broad StartupWindow source file.

## Source Placement
- Recommended source file/class/global/module placement: static helper in `NexusTK/app/StartupWindow.cpp` under [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md).
- Why this placement fits source-tree and subsystem context: both callers are StartupWindow update-check parse sites and no external route exists; generated file route already puts UID0004D3 in `auto-generated/NexusTK/app/StartupWindow.cpp`.
- Rejected placements and why: `StringUtil.cpp`/SimpleUString rejected because target is the caller-local wrapper, not the shared append helper; Win32/API conversion rejected because no target API call exists; parent aggregate rejected because exact child already carries source.
- Remaining placement uncertainty, if any: none material. Exact helper name could be `StartupNarrowRangeToWideString` in original source, but existing `StartupAnsiRangeToWideString` is a stable, acceptable source-facing name if documented as narrow byte range.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `0x00581cf0-0x00581d30`, size `0x40`, starts with standard prologue bytes and ends with `retn 0Ch`; predecessor `0x00581ce6-0x00581cf0` is ten `0xcc` bytes; successor `0x00581d30` starts scalar deleting destructor wrapper.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new children. Keep predecessor padding ignored through parent docs. Keep successor UID0004D4 as separate compiler wrapper.
- Padding/table/data/code distinctions: UID0004D3 is code; predecessor bytes are padding; no table/data island involved.
- Parent/container impact: parent [UID:0001IO] remains non-emitting split/container; update only its UID0004D3 row/evidence if stale after callback.

## Negative Evidence Summary
- No direct evidence supports `mbstowcs_s` or `MultiByteToWideChar` for UID0004D3. The current formal body is an inferred family-level placeholder contradicted by current MCP.
- No direct evidence supports a third source parameter. The third stack slot is ABI/helper cleanup noise from the shared append helper convention.
- No direct evidence supports generic `StringUtil` ownership for the wrapper. The underlying append helper is shared, but UID0004D3's callers are startup-only.
- No pointer/table/vtable route to UID0004D3 was found: `find_bytes` for target VA/RVA returned zero matches, and `xrefs_to 0x00581cf0` returned only two code refs.
- No reason exists to demote to non-emitting/no-code: the target already satisfies reconstructable/emitter/score gates and has a source-like two-argument helper shape.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Keep source helper name `StartupAnsiRangeToWideString`.
  - Document semantic parameters as `const char *first` and `const char *last`.
  - Document hidden destination as compiler/STL return-by-value storage, not a source parameter.
  - Document `0x00423eb0` as reserve/capacity dependency and `0x00423060` as shared narrow-byte-to-wide append helper dependency.
- Evidence for each proposed name/type/comment: two RunUpdateCheck caller contexts and current formal/generated usage support `Startup...`; target disassembly supports half-open pointer names; shared-helper page and current xrefs support dependency comments.
- Items intentionally left unchanged and why: no IDA DB rename/type changes are requested by this report-only pass; B agents should not make IDA write-side changes here.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. If a supervisor later allows IDA comments, a non-destructive comment explaining "range-to-wide startup helper; no `mbstowcs_s`/`MultiByteToWideChar`" would be safe but unnecessary for documentation implementation.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. UID0004D3 is reconstructable, has a valid StartupWindow emitter route, and current evidence resolves the behavior well enough to emit source.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static std::wstring StartupAnsiRangeToWideString(const char *first, const char *last)
{
    std::wstring text;
    text.reserve(last - first);

    for (const char *it = first; it != last; ++it) {
        text.push_back(static_cast<wchar_t>(*it));
    }

    return text;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable. This is first-party StartupWindow helper source.
- Reason it preserves exact original behavior: it consumes a half-open `[first, last)` range, reserves `last - first`, appends one wide character per source byte, and returns an empty string for an empty range. It intentionally avoids `c_str()`/NUL-terminated staging and avoids multibyte/code-page APIs. Under the original MSVC signed-`char` behavior, `static_cast<wchar_t>(*it)` matches the shared helper's `movsx` byte-to-16-bit path.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it is a small file-local helper using ordinary `std::wstring`, pointer-range arguments, and a simple loop. It avoids decompiler hidden-destination pointer parameters and avoids synthetic `sub_581CF0`/`Src` names.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `first`, `last`, `text`, and `it` replace `Src`, `a2`, `a3`, and the unused fourth decompiler parameter.
- Naming/coding style convention used and evidence for consistency: static helper name and two-pointer range style match existing generated StartupWindow parse helper usage and current `RunUpdateCheck` source calls.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied from the accepted report: updated target metadata to `88/91`; kept owner/emitter/reconstructable fields; replaced the existing `mbstowcs_s` formal C++ block with the formal block above; added direct session `ddf5b602` evidence for range, bytes, callers, callees, dependency roles, import/API negatives, and source-shape rationale.
- Exact parent assignments recommended: keep [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md) as both canonical owner and emitter. Keep [UID:0001IO][StartupWindowUpdateCheck](../../../by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) as a non-emitting split/index parent.
- Exact items left no-owner/non-emitting and why: none for UID0004D3. Neighboring scalar deleting destructor UID0004D4 remains outside this report and compiler-generated/non-emitting per existing docs.
- Exact future work, if any, outside this assignment scope: a separate RunUpdateCheck source-quality pass can re-audit the minimap destination capacity shown as `0x21` in current decompile versus current source spelling. That caller-local buffer-size detail does not block UID0004D3 because this helper returns only a wide string for the input range.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md`.
- Implementation status: applied to the target page.
- Exact report facts to incorporate:
  - MCP session `ddf5b602` was active/healthy and used read-only.
  - `lookup_funcs` confirms `sub_581CF0` at `0x00581cf0`, size `0x40`; `0x00581ce6` is not a function; `0x00581d30` is successor `sub_581D30`.
  - Bytes: ten `0xcc` predecessor padding bytes, exact target bytes beginning `55 8b ec ...`, target ending `c2 0c 00`, successor bytes beginning `55 8b ec ...`.
  - Decompile/disasm: length/capacity/init writes at `+0x10/+0x14/[0]`, reserve `last - first` through `0x00423eb0`, append via `0x00423060`, return destination, `retn 0Ch`.
  - Caller set: `0x00580e3f` and `0x00580fb6` only, both inside `StartupWindow__RunUpdateCheck`.
  - Dependency facts: `0x00423060` has another caller at `0x00421bc5` but remains dependency; shared helper sign-extends byte and stores 16-bit code units.
  - Negative facts: no target `MultiByteToWideChar`/`mbstowcs_s`, zero target VA/RVA pointer-byte hits, no data route.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - Keep `CANONICAL_OWNER:0000O5`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:0000O5`
  - Keep blank `EMITTER_POSITION_OPTIONAL`
  - Replace formal C++ with the exact formal block in this report.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: historical B008 family split created the current page and `mbstowcs_s` body; B007 current recheck supersedes the API-shaped body but not B008's correct split/owner/emitter route. Preserve rejected StringUtil direct ownership, runtime/API conversion, third-argument source method, raw `sub_581CF0` naming, no-owner, and parent-aggregate merge alternatives.

## Recommended Support Doc Changes
- Support path: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`.
  - Implementation status: applied to the parent split/index page.
  - Exact report facts to incorporate: update UID0004D3 child row/evidence to current `ddf5b602` facts: exact `0x40` function, ten-byte predecessor padding, two RunUpdateCheck callers, reserve/append dependency roles, no `MultiByteToWideChar`/`mbstowcs_s`.
  - Metadata/link/score/coverage/source-placement changes: parent metadata unchanged; keep parent non-emitting split/index.
- Support path: `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`.
  - Implementation status: applied to the exact caller page as support evidence only; no duplicate target body was inserted.
  - Exact report facts to incorporate: if stale, add support note that current MCP caller contexts confirm `0x00580e3f` converts the minimap substring and `0x00580fb6` converts hash-list text. Do not duplicate the UID0004D3 helper body here.
  - Metadata/link/score/coverage/source-placement changes: no required metadata change.
- Support path: `by-file/StartupWindow.md`.
  - Implementation status: applied to the file-route/source-output notes.
  - Exact report facts to incorporate: source-output note should state UID0004D3 remains a StartupWindow file-local emitter but the formal body is direct narrow-range-to-wide widening, not `mbstowcs_s`.
  - Metadata/link/score/coverage/source-placement changes: no file metadata change required unless support text is stale.
- Support path: `by-class/StartupWindow.md`.
  - Implementation status: applied to the class helper/source-route notes.
  - Exact report facts to incorporate: if current helper notes are too generic, add that current MCP reconfirms UID0004D3 as a StartupWindow-local parse helper with two RunUpdateCheck callers and shared string dependency, not a generic conversion API.
  - Metadata/link/score/coverage/source-placement changes: no class metadata change required.
- Support path: `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`.
  - Implementation status: already present/excluded from edits; no stale direct UID0004D3 contradiction was found in the accepted callback scope.
  - Exact report facts to incorporate: already present at same-or-greater detail for the shared helper behavior and UID0004D3 call relation; no edit required unless a callback reviewer finds stale current-session wording.

## Score And Metadata Recommendation
- Historical pre-callback score/metadata: `86/88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position, formal `mbstowcs_s` helper body.
- Current applied score/metadata: `88/91`, same owner/reconstructable/emitter/blank optional position, formal direct range-widening helper body.
- Score rationale and reason not higher/lower:
  - Raise completion because current MCP evidence resolves the caller/callee/range/API/source-shape blockers and supplies detailed facts missing from the target page.
  - Raise confidence because the target is an exact function with two exact callers, clear dependencies, exact bytes, and strong negative evidence against the current API body.
  - Do not raise higher because exact original source expression and exact helper name spelling are not original-proof; signed-`char` behavior is inferred from binary and compiler default; and caller-side minimap destination capacity remains a separate caller-page caveat.
- Score-improvement attempt:
  - ANSI range-to-wide conversion helper: checked decompile/disasm and shared helper disasm; resolved as direct byte-range widening.
  - Exact input/output bounds: checked caller contexts and target disassembly; resolved as `[first,last)` input and returned wide SSO string.
  - MultiByteToWideChar/API usage: checked imports, xrefs, target text, and callees; rejected for UID0004D3.
  - Caller set: checked `xrefs_to`; resolved as two RunUpdateCheck calls only.
  - StartupWindow notice/minimap relationship: checked caller decompile and generated RunUpdateCheck; resolved as update/minimap parse helper.
  - Naming/source placement: checked by-file/by-class/parent docs and generated route; keep StartupWindow file-local helper.
  - C++ readiness: resolved with formal replacement block, with confidence cap for exact source expression.
- Metadata fields to change or leave unchanged: change only completion/confidence and C++ body; leave owner/emitter/reconstructable/position unchanged.

## Open Questions With Attempted Resolution
- Open question: did original source use `std::wstring(first, last)` or an explicit loop?
  - Evidence checked: target decompile/disassembly, shared helper disassembly, generated source, older B008/B003 reports.
  - Best supported resolution: the binary shape is compatible with an STL range construction or a small explicit reserve/loop helper. The explicit loop formal block is recommended because it documents and preserves exact range semantics without relying on locale APIs.
  - Remaining impact: caps confidence at 91; does not block source readiness.
- Open question: should the function name say `Ansi` or `Narrow`?
  - Evidence checked: current target name, generated callers, surrounding `AnsiSmallStringFindFrom`/`AnsiSmallStringSubstring` naming, binary absence of code-page API.
  - Best supported resolution: keep `StartupAnsiRangeToWideString` for stable project naming, but define `Ansi` as narrow startup response bytes, not Windows code-page conversion.
  - Remaining impact: naming caveat only.
- Open question: should the helper cast through explicit `signed char`?
  - Evidence checked: shared helper `movsx ax, byte ptr [eax]` and 16-bit store; original MSVC default signed `char` behavior.
  - Best supported resolution: source block uses `static_cast<wchar_t>(*it)` as a human-written expression consistent with default signed char and observed binary. If the rebuild ever uses unsigned `char` flags, a future compiler-configuration pass may need an explicit signed-char cast.
  - Remaining impact: confidence cap; not a current blocker.
- Open question: does caller destination capacity require RunUpdateCheck source repair?
  - Evidence checked: current caller decompile around `0x00580e3f` shows `wcscpy_s(..., 0x21u, ...)`, while current `RunUpdateCheck` source says `wchar_t minimapVersion[34]`/`wcscpy_s(...,34,...)`.
  - Best supported resolution: this is a caller-page detail outside UID0004D3. UID0004D3 only returns the wide temporary. Record for future RunUpdateCheck source-quality review.
  - Remaining impact: does not lower UID0004D3 below `88/91`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Applicable: not applicable.
- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated auto reports and tracker rows are validator-owned. Callback implementation should edit by-* source docs and run scoped validators; B007 must not manually edit generated coverage/tracker files.

## Follow-Up Actions
- Supervisor actions: supervisor-owned execution/lifecycle handling remains outside B007's callback scope. This report records the accepted implementation incorporation and scoped validation evidence.
- A-agent actions: none required.
- B007 future research actions: none for UID0004D3 unless the supervisor returns a concrete repair callback. No new target should be started from this report.

## Confidence
- Recommendation confidence: strong (`91`) for owner/emitter/source-ready disposition and formal body replacement.
- Score confidence: `88/91` recommended, with direct MCP support.
- Remaining uncertainty: exact original source expression/spelling, compiler signed-char policy as a source-level assumption, and caller-side minimap destination capacity are the only material caps.

## Validator Results
- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md --apply --queue-timeout 240 --wait-generated`
    - `command_id: 000000006487`; `command_timestamp: 2026-07-04T19:16:30-04:00`; exit code `0`; `ok: 1`.
    - Generated refresh: `completed`; `generated_refresh_command_id: 000000006487`; `generated_refresh_timestamp: 2026-07-04T19:16:30-04:00`.
    - Warnings/side effects: validator-owned generated refresh reported `autogen_backup_create: 3`, `autogen_children_fallback_insert: 16`, `autogen_children_marker_missing: 82`, `autogen_cpp_update: 1`, `autogen_emitter_has_no_code: 225`, `autogen_registry_rebuild: 1`, `generated_metadata_refresh: 281`, `projected_stats_update: 1`, `research_tracker_update: 1`, and `stats_incremental_noop: 1`; no validation errors.
  - `python .\tools\validator.py --mode file --file by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md --apply --queue-timeout 240`
    - `command_id: 000000006511`; `command_timestamp: 2026-07-04T19:26:27-04:00`; exit code `0`; `ok: 1`.
    - Generated refresh: `deferred`; `generated_refresh_command_id: 000000006511`; `generated_refresh_timestamp: 2026-07-04T19:26:27-04:00`.
    - Warnings/side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`; no validation errors.
  - `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240`
    - `command_id: 000000006517`; `command_timestamp: 2026-07-04T19:31:38-04:00`; exit code `0`; `ok: 1`.
    - Generated refresh: `deferred`; `generated_refresh_command_id: 000000006517`; `generated_refresh_timestamp: 2026-07-04T19:31:38-04:00`.
    - Warnings/side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`; no validation errors.
  - `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006518`; `command_timestamp: 2026-07-04T19:31:44-04:00`; exit code `0`; `ok: 1`.
    - Generated refresh: `deferred`; `generated_refresh_command_id: 000000006518`; `generated_refresh_timestamp: 2026-07-04T19:31:44-04:00`.
    - Warnings/side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`; no validation errors.
  - `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006519`; `command_timestamp: 2026-07-04T19:31:54-04:00`; exit code `0`; `ok: 1`.
    - Generated refresh: `deferred`; `generated_refresh_command_id: 000000006519`; `generated_refresh_timestamp: 2026-07-04T19:31:54-04:00`.
    - Warnings/side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`; no validation errors.
- Generated freshness observation: after the last scoped validator, `auto-generated/NexusTK/app/StartupWindow.cpp` header records `validator-command-id: 000000006519` and `validator-refreshed-at: 2026-07-04T19:31:54-04:00`. UID0004D3 output is present at the generated marker and contains the direct range-widening body, not an Empty Emitter Marker and not `mbstowcs_s`.
- Lease/coordination observation: B010 and B008 temporarily held shared StartupWindow support-doc leases during this callback. B007 waited, validated unblocked files first, then acquired/released the remaining support-doc leases after they cleared. No B007 leases remained after validation.
- Any unresolved validator warnings/errors: no validation errors. Remaining warning rows are validator-owned generated/autogen status rows, not UID0004D3 implementation blockers.

## Changed Files
- B007 implementation callback by-* files updated/validated:
  - `by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md`
  - `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
  - `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`
  - `by-file/StartupWindow.md`
  - `by-class/StartupWindow.md`
- Report file updated: `tools/leaser/Agents/Agent-B007/research/0004D3-StartupAnsiRangeToWideString-source-quality.md`.
- Validator-owned/generated side effects observed: `auto-generated/NexusTK/app/StartupWindow.cpp` currently reflects generated UID0004D3 output under validator command `000000006519`; generated coverage/tracker/projected stats were touched only by validators. B007 did not manually edit generated files or coverage reports.
- Renamed: none.
- Report execution: not run. B007 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, report moves, archive moves, supervisor-ledger edits, generated-file manual edits, or coverage-report edits.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update identified: target UID0004D3, parent `StartupWindowUpdateCheck`, optional exact caller `StartupWindowRunUpdateCheck`, `by-file/StartupWindow.md`, `by-class/StartupWindow.md`; shared helper page likely already-present.
- [x] Current target state and actual evidence checked recorded, including MCP session `ddf5b602`, exact bytes, callers, callees, generated output, and research tracker row.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched: API usage rejected, exact input/output bounds resolved, caller set resolved, source placement resolved, C++ readiness resolved with remaining confidence caps.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve `0000O5` owner/emitter and `RECONSTRUCTABLE:TRUE`.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement/range/padding/reclassification recommendations recorded: StartupWindow file-local helper, exact `0x00581cf0-0x00581d30` range, ten-byte predecessor padding, successor split unchanged.
- [x] First-draft C++ to apply: exact formal block supplied in `## First-Draft C++ Recommendation`.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve recorded.
- [x] Wave2/Wave3 artifacts encountered and ignored/rejected as stale where applicable; generated output used only as lead/current-state evidence.
- [x] Open questions closed or documented with evidence-backed unresolved rationale and score impact.
- [x] Validators to run after callback: scoped file validators for every edited by-* file, likely at minimum the target and any stale support docs; use generated freshness check for `auto-generated/NexusTK/app/StartupWindow.cpp`.
- [x] Generated report refresh expected: validator should update generated UID0004D3 body from `mbstowcs_s` to the formal range-widening helper after target callback.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 passed for SHA256 `63DA07374E364CDDB44DB2A03247635219913239082EACA6EFDB2DC7477CF2EB`.
- [x] Lease only files about to be edited and release immediately after edit/validator batch: B007 used leases for the target, caller, parent, file, and class support docs; B010/B008 support-doc lease conflicts were waited out; final lease check found no B007 leases.
- [x] Apply target metadata: target now records `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Replace UID0004D3 formal C++ block with the exact formal block from this report: target and generated `StartupWindow.cpp` now contain direct range-widening source.
- [x] Incorporate target facts at report-level detail: target evidence records session `ddf5b602`, range/size, bytes/padding, caller/callee set, SSO init, reserve/append behavior, API negatives, pointer negatives, rejected alternatives, and confidence caps.
- [x] Update parent/support docs only where stale: parent child row/evidence, file/class source-output notes, and RunUpdateCheck caller note were synced; shared helper page was already present/excluded from edits.
- [x] Preserve historical B008 split context while superseding the `mbstowcs_s` body: target/support docs state the B008 split remains valid while the old API-shaped body is superseded.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* file with `--apply --queue-timeout 240`: commands `000000006487`, `000000006511`, `000000006517`, `000000006518`, and `000000006519` all exited `0` with `ok: 1`.
- [x] Record validator command IDs, timestamps, exit codes, ok counts, warnings/errors, generated refresh state, changed files, and lease release status: recorded in `## Validator Results` and `## Changed Files`.
- [x] Update this ledger and checklist to `applied`, `already-present`, `excluded-with-reason`, or `blocked` after callback: all accepted claims are applied or already-present/excluded where noted; no accepted UID0004D3 claim remains blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000006564","destination_path":"executed-b-agent-research/B007/0004D3-StartupAnsiRangeToWideString-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0004D3-StartupAnsiRangeToWideString-source-quality.md","timestamp":"2026-07-04T20:13:11-04:00","uid":"0004D3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
