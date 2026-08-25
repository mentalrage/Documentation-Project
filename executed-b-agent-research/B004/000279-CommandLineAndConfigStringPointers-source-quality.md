** TARGET-REPORT-UID:000279 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000279 CommandLineAndConfigStringPointers Source Quality


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:000279] as the exact `0x0066d468-0x0066d47c` RegistryConfig-owned writable pointer block, but repair the target documentation with the current MCP session, correct UTF-16 string decoding, and a clearer comment-only marker.
- Final disposition: reconstructable source-support data emitted through [UID:0000N4] `RegistryConfig`, not a standalone source table, not a Browser/WebBoard table, not Crc16 data, not a no-owner/non-emitting item.
- Required action: implementation callback applied to the target by-memory page only; support docs were inspected for contradictions and no support edit was required.
- Confidence: high for range, byte layout, pointer values, xrefs, owner/emitter, and no-synthetic-table disposition; medium-high for original source spelling of the underlying static/literal names.

## Supporting Research
- Assignment: Agent-B004 new report-only source-quality research for [UID:000279] `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`.
- Required old-report search terms used: `TARGET-REPORT-UID:000279`, `000279`, `0x0066d468`, `0x0066d47c`, `0x0066d46c`, `0x0066d470`, `0x0066d474`, `0x0066d478`, `CommandLineAndConfigStringPointers`, `RegistryConfig`, `RegistryCommandLineParsers`, `StartupHostPortCommandLineParser`, `StructuredHostPortIdLauncherParser`, `RegistryPersistenceAndConfigEntryCleanup`, `RegistryConfigLoadFromRegistry`, `mscfg.dll`, `grcframe.exe`, `Unitel`, `HITEL2000`, `off_66D468`, `off_66D46C`, `off_66D474`, `lpText`, and `third_party_embeds`.
- Old-report search results: no direct existing B-agent report with `TARGET-REPORT-UID:000279` was found. Relevant executed support reports were B007 `0000N4-RegistryConfig-empty-emitter-family-source-quality.md`, B006 `0003FX-RegistryConfigAdapterHelperStringData-source-quality.md`, B003 `0002P8-RegistryConfigLoadFromRegistry-source-quality.md`, B008 `0002BH-StartupHostPortCommandLineParser-source-quality.md`, B011 `0002BR-StructuredHostPortIdLauncherParser-source-quality.md`, B004/B006/B003 WebBoard URL-escape boundary reports for predecessor [UID:000278], and B001/B002/B014 Crc16/Event reports for successor [UID:00027A]/[UID:00027B].
- Historical note: B007 inserted the current comment-only marker and rejected a synthetic five-pointer table. B006 later resolved the `grcframe.exe` slot as an xref-engine caveat instead of a use-route blocker by proving the indexed `mscfg.dll`/`grcframe.exe` two-entry loop.

## Target
- Target UID: `000279`.
- Target path: `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`.
- Report path: `tools/leaser/Agents/Agent-B004/research/000279-CommandLineAndConfigStringPointers-source-quality.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` under `## by-memory` -> `### Not-Covered Files - Reconstructable` lists UID000279 at `86/89`, combined `87.5`, reconstructable `true`, direct report count `0`.
- Current supervisor classification: Gate 1 passed and implementation callback completed; awaiting supervisor Gate 2 / execute review.
- Current scores and parent state: target implemented at `88/91`, owner [UID:0000N4], emitter [UID:0000N4], reconstructable TRUE; source file [UID:0000N4] `RegistryConfig` is `90/90`; class [UID:0000BW] is `88/90`; data-section container [UID:0001Z8] is non-emitting `85/90`.

## Current Target State
- Existing metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`, blank emitter position.
- Existing owner/emitter/reconstructable state: correct; retain [UID:0000N4] `RegistryConfig` as both direct semantic owner and generated-output route.
- Existing C++/emitter state after callback: formal block is the accepted two-line comment-only/no-synthetic-table marker. Generated refresh from validator command `000000007833` was reported as deferred; no generated file was edited manually.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - Callback resolved the former formal-marker ambiguity: the target now uses the accepted two-line no-synthetic-table marker, while the helper-loop proof is recorded in prose evidence.
  - Callback resolved the target-page mojibake issue by recording the Unitel/HITEL Korean UTF-16 messages through copy-safe Unicode escape forms only.
  - Original source spellings for the per-use constants or static pointer declarations are not proven. Source-facing names should live with the consumer helpers, not as raw IDA labels such as `off_66D468`, `off_66D46C`, `off_66D474`, or `lpText`.
  - The page should remain one exact memory-range support page. That does not mean the final source had one five-element array; the binary shape can be a compiler-adjacent block of per-use pointer variables/literals.
- Related target/support docs checked: target page, [UID:0000N4] `RegistryConfig`, [UID:0000BW] `RegistryConfig` class, [UID:000220] parser aggregate, [UID:0002BH] Unitel parser, [UID:0002BR] structured parser, [UID:0002P8] `LoadFromRegistry`, [UID:000111] persistence aggregate, [UID:0003FX] string-data support, [UID:0001Z8] data section, predecessor [UID:000278] browser URL-escape character sets, successor [UID:00027A] checksum lookup tables, generated `RegistryConfig.cpp`, generated tracker/coverage, and matching executed reports.
- Current artifact/lifecycle status: implementation callback has been applied to the target by-memory page and this report ledger/checklist; support docs were not changed; no generated files, coverage files, validator state, lifecycle files, or supervisor ledgers were manually edited; `execute_report` was not run.

## Executive Recommendation
- Keep canonical owner/emitter [UID:0000N4] `RegistryConfig`.
- Raise the target to `COMPLETION:88`, `CONFIDENCE:91` after incorporating the current MCP evidence, Unicode decoding, and clearer marker wording.
- Replace the current formal marker with a still-comment-only marker that rejects a synthetic five-pointer source table while recording the proven `grcframe.exe` loop route.
- Do not split this range now. The exact half-open byte range is real and useful as a memory support page, while final source should keep literal/static names at the parser/load use sites.

## Supervisor Active Recheck
- Triggering instruction: current Agent-B004 goal assigns a report-only source-quality report for [UID:000279] and forbids by-* edits, validators, generated/coverage edits, and lifecycle commands.
- Split repair needed before final report: no. The exact target range is `0x0066d468-0x0066d47c`; predecessor [UID:000278] ends at `0x0066d468`; successor [UID:00027A] starts at `0x0066d47c`.
- Source-bearing children in scope: UID000279 is the only target. Its consumer bodies [UID:0002BH], [UID:0002BR], and [UID:0002P8] already carry source-facing behavior and are support evidence only.

## Inference Research Guidance Check
- `by-memory` guidance treats this as address-range documentation: exact bytes, xrefs, range boundaries, owner/emitter route, rebuild handling, and C++ marker/no-code disposition must be explicit.
- `by-structure.md` permits reconstructable source-support data to emit a formal marker when the actual source should be represented at other exact consumer pages rather than duplicated as a standalone table.
- Existing documentation assumptions treated as uncertain: raw IDA names (`off_66D468`, `off_66D46C`, `off_66D474`, `lpText`) and a single synthetic table declaration are not original source proof.
- IDA facts used for bytes, pointer values, xrefs, function boundaries, and loop instructions; current by-* docs and executed reports used as corroborating documentation; source-facing names remain inference where original spelling is unavailable.
- No Wave2/Wave3 material was used as proof. Generated C++ was read only as current emitted-state evidence.

## Heuristic / Inference Reanalysis And Validation
- Half-open range: current MCP bytes from `0x0066d458` through `0x0066d487` show the predecessor WebBoard unsafe-character table ending at `0x0066d468`, exactly five pointer dwords through `0x0066d47b`, four zero bytes at `0x0066d47c-0x0066d480`, then the Crc16 table bytes beginning at `0x0066d480`. Keep the target range unchanged.
- Pointer layout: current MCP `get_global_value` resolves the five slots as `0x0066d468 -> 0x0061693c`, `0x0066d46c -> 0x006178d8`, `0x0066d470 -> 0x006178ec`, `0x0066d474 -> 0x0061794c`, and `0x0066d478 -> 0x00617954`.
- String decoding: IDA `get_string` still renders some UTF-16 Korean strings as narrow one-character artifacts, but raw `get_bytes` decoded as UTF-16LE resolves the two Korean UI strings. To avoid renderer-dependent mojibake, the Unicode escape forms below are the only copy-safe implementation source for those strings; any visible non-ASCII rendering is secondary and must be regenerated from these escapes before insertion.
- Copy-safe corrected string forms for implementation:
  - Unitel-only Unicode escape form: `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020\uC720\uB2C8\uD154\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`
  - HITEL2000 Unicode escape form: `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020HITEL2000\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`
  - Other decoded slots: `mscfg.dll`, `grcframe.exe`, and `"/ \t"`.
- Any mojibake-like rendering of these Korean messages is historical/current-target text damage or a non-UTF-8 viewer artifact; do not copy it into the target page. If a visible rendering disagrees with the Unicode escapes, the escapes are authoritative.
- Xrefs: four slots have direct code/data reads from RegistryConfig parser/load code. The `grcframe.exe` slot has no direct `xrefs_to` result, but its target literal has a data xref from the slot and the `LoadFromRegistry` loop reads `off_66D46C[eax]`, increments the table offset by four, compares against eight, and branches back for a second iteration.
- Source shape: the binary has a contiguous writable pointer block, but the source is better represented by per-use names/literals in `ParseUnitelRelayStartupHostPort`, `RegistryConfig::LoadFromRegistry`, and `ParseStructuredHostPortIdLauncher`. A single five-pointer array would imply source grouping across unrelated startup alert, helper-file probe, delimiter, and missing-argument text that current evidence does not prove.
- Owner/emitter: RegistryConfig file ownership remains strongest because all code consumers are RegistryConfig command-line/session/parser/load code, and the source root already emits the related helper bodies.
- Rejected alternatives:
  - Browser/WebBoard ownership is rejected because [UID:000278] ends immediately before this range and its xrefs are WebBoard-specific; UID000279 xrefs are RegistryConfig-specific.
  - Crc16 ownership is rejected because [UID:00027A] starts at `0x0066d47c` and its first source data begins after the four zero prefix at `0x0066d480`; UID000279 has no Crc16 helper xrefs.
  - No-owner/non-emitting is rejected because RegistryConfig has a valid owner/emitter and proven source consumers.
  - Synthetic five-pointer declaration is rejected because it overstates source grouping and would duplicate better source-facing constants at the use sites.
  - Splitting into five separate by-memory pages is rejected for now because the exact 20-byte support block is small, contiguous, already bounded, and split would not solve the remaining source-name uncertainty.
- Remaining unresolved issue: exact original static/literal names and whether the compiler produced this adjacency from one array or several adjacent file-scope pointer variables. This caps score below final-audit levels but does not block a marker-only target repair.

## Evidence Standards Used
- Evidence types used: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `get_int`, `get_global_value`, `get_string`, `xrefs_to`, `entity_query`, `find_bytes`, and bounded `search_text`; current target/support docs; generated tracker/coverage and `RegistryConfig.cpp`; matching executed B-agent reports; negative xref and boundary checks.
- Evidence is strong enough for a modest score increase because the current session rechecked the exact bytes, slot values, xref counts, function boundaries, Unicode string contents, generated marker state, and key indexed-loop proof.
- Evidence remains below final-source certainty because original source declarations and constant names are not recovered and the xref engine still does not attach a direct code xref to the second helper-probe slot.

## Evidence Checked
- IDA MCP checks performed:
  - `idb_list` found active IDB session `supervisor-nexustk-20260707`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker PID `14640`, active and not analyzing.
  - `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with size `2067`.
  - `lookup_funcs` returned `0x004918e0` as `sub_4918E0`, size `0x248`, and `0x004926a0` as `sub_4926A0`, size `0x1789`; `0x0048f4d0`, `0x0066d430`, `0x0066d468`, `0x0066d47c`, and `0x0066d480` are not functions.
  - `get_bytes` confirmed target bytes `3c 69 61 00 d8 78 61 00 ec 78 61 00 4c 79 61 00 54 79 61 00`; predecessor bytes at `0x0066d458-0x0066d468`; successor bytes at `0x0066d47c` as four zeros followed by Crc16 table words.
  - `get_int`/`get_global_value` confirmed the five little-endian slot target addresses and `0x0066d47c` as zero.
  - `get_string` and raw UTF-16LE `get_bytes` decoding checked the five target strings plus structured parser support literals.
  - `xrefs_to` confirmed slot xrefs: `0x0066d468` one xref at `0x0048f6a3`; `0x0066d46c` one at `0x00493d0c`; `0x0066d470` zero; `0x0066d474` three at `0x00491969`, `0x004919d1`, `0x00491a3d`; `0x0066d478` three at `0x0049195b`, `0x004919c3`, `0x00491a2f`; `0x0066d47c` zero; `0x0066d480` two Crc16 table xrefs.
  - `xrefs_to` for target strings confirmed the pointer slots as data xrefs to the string targets, and structured marker/failure strings are referenced from `sub_4918E0`.
  - `search_text` around `0x00493d00-0x00493df0` confirmed `mov eax, off_66D46C[eax]` at `0x00493d0c`, `add eax, 4` at `0x00493dda`, `cmp eax, 8` at `0x00493de3`, and `jb loc_493CD0` at `0x00493de6`.
  - `search_text` around `0x004918e0-0x00491b28` confirmed the three `off_66D474` delimiter reads and `lpText` missing-argument pushes.
  - `find_bytes` found zero VA/RVA pointer-pattern hits for `0x0066d470` using direct `70 d4 66 00`, RVA `70 d4 26 00`, and scoped instruction-pattern variants checked in this pass.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target UID000279, RegistryConfig file/class, parser aggregate UID000220, Unitel parser UID0002BH, structured parser UID0002BR, LoadFromRegistry UID0002P8, persistence aggregate UID000111, RegistryConfig string data UID0003FX, DataSection UID0001Z8, predecessor UID000278, successor UID00027A, generated `RegistryConfig.cpp`, generated research tracker and by-memory coverage, and relevant executed B-agent reports listed in Supporting Research.
- Negative checks performed: no direct old UID000279 report; no function at target/data boundaries; no direct slot xref to `0x0066d470`; no xrefs to `0x0066d47c`; no direct pointer-pattern hits for `0x0066d470`; no Browser/WebBoard/Crc16 xrefs to the pointer block.
- Failed, unavailable, or intentionally skipped checks: no validators, no execute/lifecycle/archive commands, and no IDA DB write tools were run because the assignment forbids them.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B004-279-C01 | UID000279 is exactly the five-dword writable pointer block `0x0066d468-0x0066d47c`. | High | MCP `get_bytes`, `get_int`, predecessor/successor bytes. | Target Summary/Layout/Evidence. | incorporate | applied - target Summary/Layout/Evidence records exact range, five dword slots, byte block, and boundary proof; validator `000000007833` passed. |
| B004-279-C02 | Owner/emitter [UID:0000N4] `RegistryConfig` remains correct. | High | Slot xrefs only from RegistryConfig parser/load paths; support docs and generated source route. | Target metadata/summary; no support metadata change. | already-present | already-present - target header retained `CANONICAL_OWNER:0000N4`, `EMITTER_UIDS:0000N4`, `RECONSTRUCTABLE:TRUE`, and support docs inspected showed no contradiction. |
| B004-279-C03 | `0x0066d470` still has zero direct slot xrefs, but `grcframe.exe` is live through the indexed two-entry helper-probe loop. | High | `xrefs_to` zero for slot, `get_global_value`, `search_text` loop at `0x00493d0c/0x00493dda/0x00493de3/0x00493de6`. | Target Evidence, Reconstruction Notes, formal marker. | incorporate | applied - target Evidence records zero direct slot xref plus loop addresses `0x00493d0c/0x00493dda/0x00493de3/0x00493de6`; Reconstruction Notes and marker keep source use at parser/load sites. |
| B004-279-C04 | The Unitel and HITEL2000 messages should be recorded as decoded UTF-16LE Korean text, not mojibake. Use only these copy-safe implementation sources: Unitel-only Unicode escape form `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020\uC720\uB2C8\uD154\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`; HITEL2000 Unicode escape form `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020HITEL2000\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`. Any mojibake-like visible text is a bad historical/current-target rendering example, not corrected text. | High | MCP `get_bytes` raw decode; IDA `get_string` narrow artifact caveat. | Target Layout/Evidence. | incorporate | applied - target Layout records only the Unicode escape forms as copy-safe decoded text sources; mojibake was removed and target read-back has no Hangul/mojibake codepoints. |
| B004-279-C05 | Do not emit a synthetic five-pointer source table; use per-consumer literals/static names. | High | Mixed consumer roles, B007 executed report, generated RegistryConfig.cpp marker, current MCP xrefs. | Target formal marker and Reconstruction Notes. | incorporate | applied - target formal block is the accepted two-line comment-only marker and Reconstruction Notes reject synthetic table/raw IDA-name source. |
| B004-279-C06 | Do not split the target range now. | Medium-high | Exact small contiguous block, no boundary ambiguity, unresolved source declarations would not be solved by five tiny pages. | Target Reconstruction Notes; Range/Split section. | incorporate | applied - target Reconstruction Notes rejects five tiny splits and keeps exact half-open range. |
| B004-279-C07 | Browser/WebBoard, Crc16, no-owner/non-emitting, and third-party import alternatives are rejected. | High | Neighbor support docs, xrefs, by-structure owner rules, no third-party source question. | Target Reconstruction Notes/Negative Evidence. | incorporate | applied - target Reconstruction Notes rejects Browser/WebBoard, Crc16, no-owner/non-emitting, third-party import, raw labels, and synthetic table alternatives. |
| B004-279-C08 | Recommended score after target repair is `88/91`, with owner/emitter/reconstructable unchanged. | Medium-high | Current MCP recheck removes documentation-quality blockers but not original-name/source-declaration uncertainty. | Target metadata/Score Rationale. | incorporate | applied - target header is `COMPLETION:88` / `CONFIDENCE:91`; owner/emitter/reconstructable unchanged; Score Rationale explains why not higher/lower. |

## Positive Evidence Summary
- Direct facts supporting the recommendation: current MCP proves the exact bytes, five pointer values, direct slot xrefs, zero direct `0x0066d470` slot xrefs, indexed helper-loop use, string targets, function boundaries, and adjacent range boundaries.
- Corroborating documentation/generated-report evidence: current target docs already route UID000279 to RegistryConfig; B007 accepted the comment-only no-synthetic-table marker; B006 resolved `grcframe.exe` as live through the helper-probe loop; generated `RegistryConfig.cpp` emits the marker under UID000279; consumer docs contain the per-use parser/load source-facing names.
- Strongest inference chain: every code consumer is a RegistryConfig parser/load path, and the range is a compiler-visible `.data` pointer block to parser/load literals. That supports RegistryConfig ownership while rejecting a standalone source table.

## IDA MCP Facts
- Function/range facts: `0x004918e0` is `sub_4918E0`, size `0x248`; `0x004926a0` is `sub_4926A0`, size `0x1789`; `0x0048f4d0` remains not modeled as a function; target/data boundary addresses are not functions.
- Data/table/padding facts: `0x0066d468-0x0066d47c` is exactly five 32-bit little-endian pointers. `0x0066d47c-0x0066d480` is zero prefix before Crc16 table bytes at `0x0066d480`.
- Xref facts: direct slot xref counts are `1,1,0,3,3` for slots `0x0066d468`, `0x0066d46c`, `0x0066d470`, `0x0066d474`, and `0x0066d478`. String targets have data xrefs from the pointer slots.
- Vtable/global/type facts: not applicable; this target is file-level writable pointer data, not a vtable or class static.
- Negative IDA facts: no direct code xref to `0x0066d470`, no xref to `0x0066d47c`, no function at target boundaries, no direct VA/RVA pointer-pattern hits to the `0x0066d470` slot.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0066d430-0x0066d468` | [UID:000278] `BrowserUrlEscapeCharacterSets` | Predecessor WebBoard URL escape character sets. | TRUE | [UID:0000P9] WebBoardDialog | `86/93` | boundary support |
| `0x0066d468-0x0066d47c` | [UID:000279] target | RegistryConfig startup/config string pointer block. | TRUE | [UID:0000N4] RegistryConfig | `86/89` -> recommend `88/91` | target repair |
| `0x0066d47c-0x0066d480` | prefix inside [UID:00027A] | Four zero bytes before Crc16 table words. | covered by successor page | [UID:00032J] Crc16 | [UID:00027A] `88/92` | successor boundary |
| `0x0066d480-0x0066d880` | [UID:00027A] Crc16 tables | Two 256-entry CRC16 word tables. | TRUE | [UID:00032J] Crc16 | `88/92` | successor support |
| `0x0048f4d0-0x0048f6cb` | [UID:0002BH] Unitel parser | Consumes `off_66D468`. | TRUE | [UID:0000N4] RegistryConfig | `88/90` | support |
| `0x004918e0-0x00491b28` | [UID:0002BR] structured parser | Consumes `off_66D474` and `lpText`. | TRUE | [UID:0000N4] RegistryConfig | `90/92` | support |
| `0x004926a0-0x00493e29` | [UID:0002P8] LoadFromRegistry | Consumes `mscfg.dll`/`grcframe.exe` helper-probe names. | TRUE | [UID:0000BW] RegistryConfig class | `88/90` | support |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0048f6a3 -> 0x0066d468` | raw Unitel parser read of `off_66D468` | Unitel-only startup alert message pointer. |
| `0x00493d0c -> 0x0066d46c` | `sub_4926A0` reads `off_66D46C[eax]` | Base of two-entry helper-file probe table. |
| `0x0066d470` | zero direct slot xrefs | `grcframe.exe` entry reached by index, not by direct slot operand. |
| `0x00493dda`, `0x00493de3`, `0x00493de6` | `add eax, 4`; `cmp eax, 8`; `jb loc_493CD0` | Two-entry loop covers offsets `0` and `4`, therefore `mscfg.dll` and `grcframe.exe`. |
| `0x00491969`, `0x004919d1`, `0x00491a3d -> 0x0066d474` | structured parser delimiter reads | `"/ \t"` delimiter for `/host:`, `/portno:`, `/id:` extraction. |
| `0x0049195b`, `0x004919c3`, `0x00491a2f -> 0x0066d478` | structured parser missing-argument pushes | HITEL2000/default missing-argument text. |
| `0x0066d480` | xrefs at `0x0049bbff`, `0x0049bc2c` | Successor Crc16 table starts after target and zero prefix. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target page; `RegistryConfig` file/class; parser aggregate; Unitel parser; structured parser; `LoadFromRegistry`; RegistryConfig string-data page; DataSection; predecessor WebBoard page; successor Crc16 table page.
- Existing docs that are stale, incomplete, or contradicted: target page's Korean strings are mojibake; formal marker should be clarified so `grcframe.exe` is not read as unresolved use; old B007 "zero xref" wording is superseded by B006's helper-loop proof but remains useful as an xref-engine caveat.
- Generated/coverage report state: `auto-generated/-ag-research-tracker.md` lists UID000279 as not-covered reconstructable at `86/89` with direct report count `0`; `auto-generated/-ag-coverage-report-by-memory.md` lists the same row; generated `RegistryConfig.cpp` header is `000000007812` and emits the current UID000279 comment-only marker.

## Ranked Ownership Analysis

### 1. [UID:0000N4] RegistryConfig
- Evidence for: all current code xrefs are RegistryConfig startup/parser/load paths; source file has valid `NexusTK/config/` route; file docs already group command-line parser helpers, registry load, and related string data; executed support reports agree.
- Evidence against: exact original static names for the five pointer slots are unknown, and [UID:0002P8] is class-owned while parser helpers are file-static.
- Decision: keep as direct owner/emitter. The class/page distinction does not change this target because the pointer block bridges file-static parser helpers and load-method literals.

### 2. [UID:0000BW] RegistryConfig class
- Evidence for: `LoadFromRegistry` is a real class method and consumes the helper-probe entries.
- Evidence against: Unitel and structured parser helpers are file-static/config-adjacent, not confirmed class methods; class ownership would be too narrow for all five slots.
- Decision: reject as direct canonical owner; use as support for the load-method half only.

### 3. Browser/WebBoard and Crc16 neighbors
- Evidence for: physically adjacent data ranges on both sides.
- Evidence against: predecessor [UID:000278] and successor [UID:00027A] have separate xrefs, source owners, and boundaries; UID000279 xrefs do not point to WebBoard or Crc16 code.
- Decision: reject as owners; keep as boundary support only.

### 4. No-owner/non-emitting or synthetic new file
- Evidence for: source declarations are not fully proven and one slot lacks direct xrefs.
- Evidence against: RegistryConfig ownership is already strong and the generated route is valid; non-emitting would lose useful per-use literal support; a new file would be artificial.
- Decision: reject.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items rejected: Browser/WebBoard URL escape data, Crc16 tables, read-only string-data owner UID0003FX, and a standalone command-line pointer table module.
- Standalone, narrow, or broad source-file inference: narrow support data inside existing `RegistryConfig.cpp` source route.

## Source Placement
- Recommended source file/class/global/module placement: keep under [UID:0000N4] `RegistryConfig` / `NexusTK/config/RegistryConfig.cpp`.
- Why this placement fits source-tree and subsystem context: the data feeds `RegistryConfig` startup command-line parsers and registry load helper-file checks; generated source already emits the consumer bodies and marker under `RegistryConfig.cpp`.
- Rejected placements and why: WebBoardDialog owns only predecessor URL escape characters; Crc16 owns only successor tables; a new pointer-table source file would be decompiler-shaped; [UID:0003FX] owns pooled `.rdata` literal context but not this writable `.data` pointer block.
- Remaining placement uncertainty: exact local/static declaration spelling at the use sites.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: target begins at `0x0066d468` immediately after [UID:000278] old-path WebBoard unsafe-character bytes and ends at `0x0066d47c` before [UID:00027A]'s zero prefix and Crc16 word tables.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: create no new children; do not merge with predecessor or successor; do not split into five four-byte pages.
- Padding/table/data/code distinctions: target is writable `.data` pointer storage; `0x0066d47c-0x0066d480` is successor-owned zero prefix, not part of this table; no code or functions exist at these addresses.
- Parent/container impact: DataSection remains a non-emitting container; target remains RegistryConfig-owned reconstructable data support.

## Negative Evidence Summary
- No direct prior UID000279 B-agent report exists.
- No function exists at target or neighboring data addresses.
- No direct code xref or pointer-pattern hit exists for slot `0x0066d470`; use is proven only through the indexed base-slot loop.
- No xrefs target the end boundary `0x0066d47c`; successor Crc16 xrefs begin at `0x0066d480`.
- No Browser/WebBoard or Crc16 consumer xrefs point into UID000279.
- No source evidence proves a single original five-pointer array; do not emit `off_66D468`-style arrays or IDA labels.
- No third-party import question applies; this is NexusTK-owned configuration/startup support data.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Keep raw IDA names only as evidence labels; do not use `off_66D468`, `off_66D46C`, `off_66D474`, or `lpText` in final source.
  - Use consumer-local source-facing names such as `kUnitelOnlyVersionMessage`, `SystemDirectoryFileExists("mscfg.dll")`, `SystemDirectoryFileExists("grcframe.exe")`, `kCommandLineTokenDelimiters`, and a HITEL2000/default missing-argument message name where the consumer docs already support them.
  - Target formal marker should say the range is a writable pointer block and that source use belongs at parser/load use sites.
- Evidence for each proposed name/type/comment: current consumer docs and generated code already use source-facing parser/load helper names; current MCP proves the pointer storage and consumer routes.
- Items intentionally left unchanged and why: no IDA DB rename/type/comment edits requested; no metadata owner/emitter change; no split/rename of target file in this report-only pass.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: eligible only for a formal comment-only marker, not a standalone table declaration.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text for the target page:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This range is the writable pointer block for RegistryConfig startup/config literals.
// Do not emit a synthetic five-pointer source table; keep literal names at parser/load use sites.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable; no `third_party_embeds/...` source import is involved, and the multiline C++ block should not be blanked for an import directive.
- Reason it preserves exact original behavior: it avoids emitting a standalone table that could duplicate or distort consumer-level literal use while preserving traceability for the exact pointer bytes and helper-loop behavior.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: developer source likely used named local/static string constants or pointer variables beside parser/load code, not raw IDA `off_` labels or a cross-purpose decompiler table.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: names stay in consumer pages; this target only records the pointer block.
- Naming/coding style convention used and evidence for consistency: file-static `k...` constant style and RegistryConfig helper naming matches accepted parser/load child pages.
- Reason code should remain blank, if applicable: not blank; formal marker is preferred.
- Exact no-code proof, if not eligible: no standalone data declaration is eligible because current evidence proves per-consumer use but not one source-authored five-entry array.

## Final Recommendation
- Exact changes applied: updated target evidence/layout/reconstruction notes with current MCP facts, copy-safe UTF-16 escape forms for the Korean strings, the callback's accepted two-line formal marker, no-synthetic-table proof, and score `88/91`.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:0000N4`, `EMITTER_UIDS:0000N4`, `RECONSTRUCTABLE:TRUE`.
- Exact items left no-owner/non-emitting and why: none for this target; no-owner/non-emitting is rejected.
- Exact future work outside this assignment scope: a whole RegistryConfig parser-island pass could recover exact dispatcher route and final constant names; not required for this target repair.

## Recommended Target Doc Changes
- Target path: `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`.
- Exact report facts to incorporate:
  - Current MCP session `supervisor-nexustk-20260707` and health/session facts.
  - Exact pointer bytes and slot values from current MCP.
  - Correct UTF-16LE decoded Korean strings, using only these copy-safe implementation sources:
    - Unitel-only Unicode escape form: `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020\uC720\uB2C8\uD154\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`
    - HITEL2000 Unicode escape form: `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020HITEL2000\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`
    - Do not copy any mojibake-like visible rendering; decode from the escape forms before insertion.
  - Direct slot xref counts and the zero-direct-xref caveat for `0x0066d470`.
  - Indexed helper-loop proof for `grcframe.exe`: base read at `0x00493d0c`, `add eax, 4` at `0x00493dda`, `cmp eax, 8` at `0x00493de3`, `jb` at `0x00493de6`.
  - Boundary proof: predecessor WebBoard bytes end at `0x0066d468`; successor zero prefix/Crc16 table begins at `0x0066d47c`/`0x0066d480`.
  - Negative evidence rejecting Browser/WebBoard, Crc16, no-owner/non-emitting, split, and synthetic table alternatives.
- Metadata/score/owner/emitter/reconstructable/C++ changes: recommend `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter/reconstructable unchanged, and replace formal marker with the exact block in `First-Draft C++ Recommendation`.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B007 no-synthetic-table decision; B006 `grcframe.exe` loop proof; xref-engine caveat; raw IDA names as evidence labels only; no split/merge.

## Recommended Support Doc Changes
- Support path: `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`, `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`, `by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md`, `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`, `by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md`, `by-memory/0x0066d000-0x0069d000.DataSection.md`, `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`, and `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`.
- Exact report facts to incorporate: no mandatory support edits; these docs already contain the owner/source route, parser/load uses, boundaries, and rejected neighboring-owner facts at same-or-greater useful detail. If the supervisor chooses optional support cleanup, only add a short cross-reference note that UID000279's current B004 report confirms the no-synthetic-table marker and corrected Unicode decoding.
- Metadata/link/score/coverage/source-placement changes: no required support score, metadata, link, or source-placement changes.

## Score And Metadata Recommendation
- Current score/metadata: target `86/89`, owner [UID:0000N4], emitter [UID:0000N4], reconstructable TRUE.
- Recommended score/metadata: target `88/91`, owner/emitter/reconstructable unchanged.
- Score rationale and reason not higher/lower: raise because current MCP verifies exact bytes, direct xrefs, Unicode string decoding, generated marker state, loop proof, negative pointer-pattern evidence, and neighboring boundaries. Do not exceed low 90s because original source spellings and whether the five pointers derive from one array versus adjacent per-use statics remain unresolved.
- Score-improvement attempt:
  - Range blocker: resolved by current `get_bytes` over predecessor/target/successor.
  - `grcframe.exe` liveness blocker: resolved as live through indexed loop, while direct xref absence remains a caveat.
  - String decoding blocker: resolved by raw UTF-16LE decoding.
  - Source grouping blocker: resolved to marker-only/no-synthetic-table recommendation; original grouping remains unresolved but nonblocking.
  - Owner/emitter blocker: resolved as RegistryConfig; Browser/WebBoard/Crc16/no-owner alternatives rejected.
  - Final static-name blocker: unresolved after current docs/MCP; caps score.
- Metadata fields to change or leave unchanged: change only completion, confidence, and formal marker after supervisor approval; leave owner, emitter, reconstructable, range, and filename unchanged.

## Open Questions With Attempted Resolution
- Open questions found:
  - Exact original source names for the five constants/pointer variables.
  - Whether source had one two-entry helper-probe array for `mscfg.dll`/`grcframe.exe`, adjacent separate pointer variables, or compiler/linker-created adjacency across several declarations.
  - Whether later parser-island recovery will rehome file-static helpers as private `RegistryConfig::` methods.
- Evidence checked for each: current MCP bytes, values, xrefs, pointer-pattern searches, consumer docs, generated `RegistryConfig.cpp`, executed B006/B007/B008/B011/B003 reports, neighboring WebBoard and Crc16 docs.
- Best supported resolution or inference: keep a single exact by-memory support page; use consumer-local names/literals; keep formal marker only; avoid synthetic cross-purpose table.
- Questions remaining unresolved: original declaration spelling/source grouping and parser-island dispatcher route. These cap score and prevent source declarations but do not block the target documentation repair.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Applicable only when an explicit manual `-coverage-report.md` or supervisor-owned tracker row needs a change: not applicable.
- Do not write row text for validator-owned `auto-generated/-ag-*` reports: no generated/coverage edits are recommended for B-agent application.
- File/placement: n/a.
- Exact replacement/insert/delete text: n/a.
- Reason B agent must not apply it directly: assignment forbids generated/coverage edits; source target metadata plus scoped validator refresh is sufficient after callback.

## Follow-Up Actions
- Supervisor actions: Gate 2 review the target/report/validator result and execute the report if accepted.
- A-agent actions: none.
- B004 future research actions: none for UID000279 unless supervisor rejects the marker/no-split disposition or requests parser-island-wide naming work.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: original static/literal declaration spellings and final parser-island source shape.

## Validator Results
- Commands run: `python .\tools\validator.py --mode file --file by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md --apply --queue-timeout 240`
- Results: exit code `0`; command_id `000000007833`; command_timestamp `2026-07-07T03:39:40-04:00`; scanned markdown files `1`; `ok: 1`.
- Validator output summary: `completion_update 000279 ... 88`, `confidence_update 000279 ... 91`, `autogen_registry_update`, `reference_index_add` for `000278`, `00027A`, and `0002P8`, and `uid_link_insert` for `000278` / `00027A`.
- Generated refresh state: `generated_refresh: deferred`; `generated_refresh_command_id: 000000007833`; `generated_refresh_timestamp: 2026-07-07T03:39:40-04:00`. Validator also reported `projected_stats_update` for `project-level/-auto-completion-stats.md`; no generated/coverage/project-level files were manually edited.
- Any unresolved validator warnings/errors: none reported by the scoped validator.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B004/research/000279-CommandLineAndConfigStringPointers-source-quality.md` during report-only pass.
- Modified by B004 callback: `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`; this report file.
- Support docs: none modified; inspected support docs had no direct contradiction.
- Validator-owned side effects reported: autogen registry/projected stats/reference index updates and deferred generated refresh from command `000000007833`.
- Renamed: none.
- Report execution: not run.

## Implementation Tracking Checklist

Initial report-only pass:

Report-only self-check items:
- [x] Supervisor validation required before implementation.
- [x] Current target state and actual evidence checked recorded: target metadata, generated marker, MCP session, support docs, tracker/coverage, and old-report hits recorded.
- [x] Claim And Incorporation Ledger populated with destination and report-only verification state for every proposed claim during the report-only pass; rows B004-279-C01 through C08 are now updated above with callback verification states.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or evidence-backed unresolved cap: range, string decode, `grcframe.exe` route, owner, split, and marker/no-code disposition resolved; original names remain evidence-backed unresolved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated/old source artifacts treated as lead material only; no Wave2/Wave3 proof used.
- [x] Open questions documented with evidence-backed unresolved rationale: original constant names/source grouping and parser dispatcher route remain unresolved and score-capping.

Implementation callback items:
- [x] Target/support docs to update: target UID000279 only; support docs inspected and no contradiction found, so none edited.
- [x] Metadata/score changes to apply: target changed `86/89 -> 88/91`; owner/emitter/reconstructable unchanged.
- [x] Owner/emitter/reconstructable changes to apply: none; kept [UID:0000N4] owner/emitter and TRUE reconstructable.
- [x] Split/rename/new-child changes to apply: none; kept exact half-open range and filename.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement remains `RegistryConfig.cpp`; no IDA DB edits requested; range/split unchanged.
- [x] First-draft C++ or no-code proof to apply: replaced target formal block with the callback's accepted two-line comment-only marker; did not emit a five-pointer declaration; helper-loop proof incorporated in prose evidence.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable; this is NexusTK-owned pointer data, not a third-party embed.
- [x] Exact target/support doc facts to incorporate at report-level detail: target Layout/Evidence/Reconstruction Notes/Score Rationale/Changes now incorporate the accepted facts; support docs were already sufficient and unchanged.
- [x] Corrected UTF-16LE string text to incorporate using Unicode escapes only as the copy-safe implementation source: target Layout records Unitel-only `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020\uC720\uB2C8\uD154\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`; HITEL2000 `\uC774\u0020\uBC84\uC804\uC758\u0020\uBC14\uB78C\uC758\u0020\uB098\uB77C\uB294\u0020HITEL2000\u0020\uC804\uC6A9\uC785\uB2C8\uB2E4\u002E`, and read-back found no Hangul/mojibake codepoints.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserved B007 marker/no-table decision, B006 helper-loop proof, xref-engine caveat, no Browser/WebBoard/Crc16 ownership, no split, and no raw IDA names in source.
- [x] Validators to run: scoped file validator run for `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`, command `000000007833`, exit `0`, `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator reported `generated_refresh: deferred`; no manual generated/coverage/tracker text.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 passed at hash `BF1E55988BE89F811FD71A935F06886764C9F8A9B3E7BE10B62A5BC557A45F47`.
- [x] All accepted target/support doc details incorporated at report-level detail: target updated; support docs already sufficient and unchanged.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows B004-279-C01 through C08 updated above.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target now `88/91`; owner/emitter/reconstructable/range/filename unchanged; formal block updated to accepted callback marker.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target Reconstruction Notes/Changes preserve no-table, no-split, xref caveat, helper-loop proof, and rejected owners/imports.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original declaration spelling/source grouping and parser-island dispatcher route remain unresolved score caps.
- [x] Validators run and results recorded: scoped target validator `000000007833`, timestamp `2026-07-07T03:39:40-04:00`, exit `0`, `ok: 1`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: validator reported deferred generated refresh for command `000000007833`; no manual generated/coverage/tracker text required.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007845","destination_path":"executed-b-agent-research/B004/000279-CommandLineAndConfigStringPointers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000279-CommandLineAndConfigStringPointers-source-quality.md","timestamp":"2026-07-07T03:54:42-04:00","uid":"000279"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
