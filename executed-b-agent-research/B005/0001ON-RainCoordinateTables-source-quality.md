** TARGET-REPORT-UID:0001ON **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001ON RainCoordinateTables Source-Quality Closure


## Finalized Report / Current Recommendation

- Applied callback result: the complete `0x006702c8-0x00670784` span is reconstructed as six writable, internal-linkage C++03 arrays using signed `short` record fields and exact initializers recovered from the executable.
- Final disposition: source-authored/static source data. The three four-byte zero gaps are compiler alignment between source declarations, not explicit source objects or sentinel records.
- Current target state: [UID:0001ON] is `93/94`, `CANONICAL_OWNER:0000P8`, `EMITTER_UIDS:0000P8`, `EMITTER_POSITION_OPTIONAL:0`, with accepted formal R1. Every accepted ordinary support destination has been updated and scoped-validated; the exact five-root manual coverage handoff remains supervisor-only and blocked for B005.
- Source placement: `NexusTK/map/WeatherLayerPane.cpp`, before weather method bodies. The former direct route to `NexusTK/map/RainingLayerPane.cpp` is historical/superseded because code, RTTI/vtables, and rain/snow data all independently cluster as one weather-layer compilation family.
- Mandatory layout acceptance passed before R1 was marked applied: ordinary declarations compiled into six distinct x86 COFF objects at the exact required starts/sizes with three symbol-free four-byte gaps, total `.data` extent `0x4bc`, and SHA256 `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4`. No explicit alignment attribute or source padding object was needed.
- Confidence: very strong for bytes, boundaries, signed types, dimensions, consumers, linkage class, declarations, physical duplication, and source-family placement; inferred rather than symbol-proven for exact human identifier spellings and whether the original author used file-scope versus function-local `static` declarations.

## Supporting Research

- Historical initial phase: this began as a report-only pass for [UID:0001ON], during which no target/support by-* file, manual coverage file, generated file, tracker, supervisor file, validator state, lease file, IDA database, or lifecycle path was edited.
- Current callback phase: after exact report SHA256 `48B38BDC454E9BC128D14EB9DB3EBA6ACB590ED668942CEF0FC4585A73CD1EEA` passed supervisor Gate 1, B005 updated the eight accepted ordinary by-* destinations, ran their scoped validators serially, created the B005-owned layout-test source/object artifacts, and reconciled this same report. B005 did not directly edit manual coverage, generated/tracker/audit/supervisor/validator-state/IDA/lifecycle files and did not run/probe `execute_report`.
- Live IDA MCP database session `9b0396a3` was healthy throughout the pass. A final health recheck on 2026-07-22 reported `status:ok`, `NexusTK.exe` image base `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and active worker PID `15732`.
- The report used live MCP `idb_list`, `server_health`, `survey_binary`, `entity_query`, `get_bytes`, `xrefs_to`, `decompile`, `func_profile`, `insn_query`, and exact-address lookup/disassembly evidence.
- Executed B001 reports for UID0001NZ and B003 report UID0002Z8 were reviewed only as broad weather-family leads. Neither is direct report coverage for UID0001ON, and their unresolved source-split/name assumptions were independently reanalyzed rather than copied.
- Stale Wave2/Wave3 provenance and generated-source assumptions were encountered in current/older weather docs. They were ignored as authority under the current skill. Current by-* state, live MCP, raw bytes, current generated output, and current project structure rules control this report.

## Target

- Target UID: `0001ON`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0001ON] `by-memory/0x006702c8-0x00670784.RainCoordinateTables.md`, the exact 1212-byte rain-coordinate data object.
- Target path: `by-memory/0x006702c8-0x00670784.RainCoordinateTables.md`.
- Historical assignment-time queue row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, command `000000016628`, line 1793, tuple `86/91`, combined `88.5`, reconstructable true, zero direct/additional/B-agent reports.
- Current supervisor classification: accepted source-closure implementation callback complete in ordinary docs; exact manual coverage and lifecycle remain supervisor-owned.
- Current scores and parent state: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000P8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P8`, position `0`, formal R1 applied.

## Current Target State

- Current target checkpoint: SHA256 `477400B118F7E7AF4A4703E9D260DAE18969CEE9517191CCB9EEA151FB1C4CFE`, 18,597 bytes, 250 physical lines.
- Current source names are `s_targetRainStreaks`, `s_targetRainSmallSplashes`, `s_targetRainLargeSplashes`, `s_rainStreaks`, `s_rainSmallSplashes`, and `s_rainLargeSplashes`; the former `g_minimap*`/`g_rain*Coord*` names remain only in explicit historical analysis.
- Current type names are `RainStreak` and `RainSplash`, with exact signed-short fields and dimensions. The target records six exact objects, three compiler-alignment gaps, and the hard snow-data successor boundary.
- Historical generated state: command `000000016594` emitted UID0001ON only as an empty marker in `auto-generated/NexusTK/map/RainingLayerPane.cpp`.
- Callback validation generated checkpoint command `000000016680`/SHA256 `49E0E0C6A640D2C4D83BEFEA085287AB13A30E82E981AAC3571AC4ACD1235408` is historical. The current later unrelated generated state is `auto-generated/NexusTK/map/WeatherLayerPane.cpp` command `000000016688`, refreshed `2026-07-23T00:00:05-04:00`, source `foreground-generated-refresh`, SHA256 `D250DB2E9984E7228BA86843D6782F1DF59AC8B67CC2B095CB05153A658AF7E1`, 12,165 bytes, 268 physical lines. It preserves R1's six declarations exactly once, R2 and R3 exactly once as non-duplicating comments, and no UID0001ON empty marker. `auto-generated/NexusTK/map/RainingLayerPane.cpp` remains absent after the accepted source-route change.
- Callback tracker checkpoint command16680/SHA256 `9481C71617A7B9BAED326CFA996373172AC45551EB6E21158BEC90AC4D55EC0B` is historical. The current later unrelated tracker checkpoint is command `000000016689`, refreshed `2026-07-23T00:01:35-04:00`, source `deferred-generated-refresh`, SHA256 `F33AFE5BD2228B8E0CF88BD5B047C149EB1C5998219B90D9CEC78C4C95993F44`, 1,636,242 bytes, 6,510 physical lines. UID0001ON remains `93/94`, reconstructable true, with zero direct/additional/B-agent report coverage at line 3412.
- Current relevant support checkpoints:
  - `by-file/WeatherLayerPane.md`: SHA256 `E3B00C1A26077446FF3B4D2B3079D08278CD10B6093B9C3A0907B57B69010057`, 28,573 bytes, 131 lines, `90/90`.
  - `by-file/RainingLayerPane.md`: SHA256 `C14C3F0D7343691A7A05DF22B77F5ABF65CC248F643AC7E022761A69EF108935`, 13,138 bytes, 93 lines, `86/87`.
  - `by-class/RainingLayerPane.md`: SHA256 `3F5EDC72AE7A6A50DA4083004A7AE9BFF9713A2EE6ABDAC6D5958FC28D2DDF0E`, 10,028 bytes, 89 lines, `88/90`, routed to UID0000P8.
  - `by-global/WeatherLayerGlobals.md`: SHA256 `70D0669F4BCEE68C39FD9110708050661D2C8E6E127C4A29C0E2721462FE38B8`, 18,512 bytes, 133 lines, `92/90`, routed to UID0000P8.
  - `by-type/by-struct/WeatherLayerDataLayouts.md`: SHA256 `5C5A8681FEB7026A30801860C8248034838254128C6796AE00E263A61D6CFCA3`, 19,851 bytes, 138 lines, `88/91`, routed to UID0000P8.
  - `by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md`: SHA256 `09E68F93CBB4537675E0AE520F52112651ECA85470BF479FE330D603F8709333`, 5,970 bytes, 56 lines, `86/88`.
  - `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`: SHA256 `C76127EC06DE3BE32EA9303683FB3497053DEB2B63ABDCF29C48A0B0E0C58C5A`, 6,559 bytes, 57 lines, `86/88`.
- Duplicate/lease screen: the accepted report remains the sole active UID0001ON report. B005 used only short per-file leases for callback edits/validation; current shared `current_leases.md` confirms zero B005 leases.

## Executive Recommendation

- Reclassify the exact physical range from an untyped/provisionally named blob into six source arrays:
  - `s_targetRainStreaks[3][24]`
  - `s_targetRainSmallSplashes[3][7]`
  - `s_targetRainLargeSplashes[3][7]`
  - `s_rainStreaks[3][24]`
  - `s_rainSmallSplashes[3][7]`
  - `s_rainLargeSplashes[3][7]`
- Use two file-private record types: `RainStreak { short x; short y; short length; }` and `RainSplash { short x; short y; }`.
- Use writable `static`, not `const`: the exact storage is in writable `.data`, and every coordinate/length load is signed-extension (`movsx`) rather than zero-extension.
- Preserve both physically duplicated families. Do not deduplicate them into one shared array even though corresponding segments are byte-identical; a one-copy reconstruction would not reproduce the original storage/declaration shape.
- Route the target to [UID:0000P8] `WeatherLayerPane.cpp`, position 0. Contiguous weather code, contiguous weather RTTI/vtables, adjacent rain/snow data, and the already-consistent class/global/type routes outweigh the standalone `RainingLayerPane.cpp` candidate.
- Do not split the page. The target is one coherent declaration group with compiler alignment gaps between declarations and a hard snow-data successor boundary.

## Supervisor Active Recheck

- Historical Gate-1 instruction required report-only source closure of UID0001ON and specifically required resolving declaration/type/name/formal-code blockers rather than preserving provisional names. The accepted callback then authorized the exact ordinary-document implementation recorded here.
- No split repair is required before the report: every byte in the target is either one of the six arrays or one of three proven four-byte alignment gaps, and all belong to the same weather/rain source declaration group.
- Every source-bearing subrange is represented by R1. The three zero gaps are documented but intentionally have no source declaration.
- The existing source-family disagreement was rechecked as part of the named source-placement blocker. It is resolved to UID0000P8 as the best current inference rather than deferred.

## Inference Research Guidance Check

- `by-structure.md` classifies initialized writable globals/static arrays as source-declared/generated-binary data and requires source declarations/initializers rather than raw-address blobs. It also requires formal C++ once the combined score/emitter gate is cleared and source-quality blockers are resolved.
- Existing `minimap` and `g_` names were treated as uncertain because no original symbols exist and the first family has only an arbitrary target-port consumer.
- Direct IDA facts, current documentation evidence, and source inference are separated below. Exact bytes/types/xrefs are facts; `s_` identifiers and file-scope placement are best-source inferences.
- The current broad weather docs contain stale Wave2/Wave3 provenance and generated-source suggestions. These were ignored as authority.

## Heuristic / Inference Reanalysis And Validation

### Record types and signedness

- Direct fact: both rain consumers use `movsx` for every table word load. `insn_query` found 23 `movsx` instructions and zero `movzx` instructions in each of `0x005c1460` and `0x005c1810`.
- Direct fact: streak addressing reads three consecutive words and uses the third as the line-length/delta magnitude. Splash addressing reads two consecutive words.
- Best source form: `RainStreak` with three `short` fields and `RainSplash` with two `short` fields.
- Rejected: `unsigned short`, packed byte fields, `POINT`, `RECT`, three independent scalar arrays, and raw `short[][72]`. These conflict with signed loads or erase the repeated record structure.

### Linkage, mutability, and declaration scope

- Direct fact: the range lies in writable `.data`, not `.rdata`.
- Direct fact: no names/globals are defined inside the target range in the current IDB.
- Direct fact: each physical family is consumed by only one method and has no cross-family code references.
- Best source form: writable internal-linkage `static` arrays. `s_` matches current project source style for file-private arrays and avoids implying exported/global ABI names.
- Rejected: `const` arrays, `extern` globals, exported `g_` names, class static data members, and one shared array. They conflict with writable placement, lack external consumers, or physical duplication.
- Secondary plausible form: function-local static arrays in the two consumer methods. It is weaker because the six declarations form one contiguous rain block immediately before snow data, the current by-memory page is already a coherent source-data emitter, and the weather-family source root can place the declarations before both consumers without inventing separate method-local ownership.

### Human names

- `RainStreak` and `RainSplash` are concise source-facing type names consistent with the actual drawing roles. The old `Coord` suffix is unnecessary because the records include a streak length or represent complete splash marks.
- `s_targetRain*` is preferred for the first family because the proven method receives a supplied `GrafPort`-like target. “Minimap” is rejected: no minimap-specific caller, string, field, vtable slot name, or independent data route proves that target.
- `s_rain*` is preferred for the main-view family because the direct consumer is the class paint path.
- `SmallSplashes` and `LargeSplashes` reflect the exact two-pixel versus four-pixel drawing shapes. Singular `SplashSmall`/`SplashLarge` is less idiomatic and looks reconstruction-derived.

### Array dimensions and physical duplication

- Each streak array is 432 bytes: `3 * 24 * sizeof(RainStreak)` with `sizeof(RainStreak)==6`.
- Each splash array is 84 bytes: `3 * 7 * sizeof(RainSplash)` with `sizeof(RainSplash)==4`.
- Each streak frame draws entries 0 through 17 and retains six zero records at entries 18 through 23. The zeros are real initializer elements in the 24-record stride, not inter-array padding.
- The two streak arrays, the two small-splash arrays, and the two large-splash arrays are pairwise byte-identical, but all six physical objects must remain.
- The large-splash frame groups are the small-splash groups rotated by one frame. Preserve the exact initializer order instead of generating it at runtime.

### Padding and boundaries

- `0x006704cc-0x006704d0`, `0x00670524-0x00670528`, and `0x0067072c-0x00670730` are each four zero bytes, have no xrefs, and align the next 84-byte array to an eight-byte address.
- They are compiler/linker alignment, not one `RainSplash` record, because no consumer indexes them and each adjacent array already has exactly 21 used pairs.
- R1 intentionally emits no `char pad[4]`, dummy `RainSplash`, source sentinel, or alignment qualifier in its initial source form. Callback acceptance is conditional on the actual target MSVC/toolchain reproducing all six distinct objects at eight-byte-aligned starts and the three four-byte gaps. If ordinary declarations do not reproduce that layout, use the period-plausible fallback `__declspec(align(8))` on each of the six array declarations and repeat the object-layout test; never insert unexplained padding objects.
- The rain page ends exactly at `0x00670784`. Snow xrefs begin at interior successor addresses `0x00670785`, `0x00670788`, and `0x0067078c`.

### Source-file placement

- Direct physical clustering:
  - Weather base, rain, snow, and swallow code form the contiguous `0x005c12a0-0x005c2ab5` family.
  - Weather/rain/snow/swallow RTTI/vtables form the contiguous `0x0063118c-0x006313cc` family.
  - Rain coordinate data ends exactly where snow pattern data begins at `0x00670784`.
- Current routing corroboration:
  - Raining, Snowing, Swallow, Weather class pages already route to [UID:0000P8].
  - Weather globals and weather layouts already route to [UID:0000P8].
  - Only UID0001ON routes to [UID:0000MY], producing a separate file with an empty marker.
- Best inference: one `WeatherLayerPane.cpp` compilation family. Dedicated `RainingLayerPane.cpp` remains historical/secondary only unless future source/PDB evidence proves a split.

## Evidence Standards Used

- Strongest evidence: exact raw bytes, exact segment placement, exact xrefs, exact signed load instructions, exact decompilation formulas, and exact physical boundaries.
- Corroborating evidence: current class/file/global/type docs, current emitter routes, current generated source, source-root conventions, and period-plausible Visual C++ internal-linkage style.
- Negative evidence: no target names, no external/global consumers, no xrefs to alignment gaps, no xref at the rain/snow boundary byte, no unsigned table loads, no evidence for minimap specificity, and no direct executed report coverage.
- Binary context matters: writable `.data` is strong evidence against source `const`, while linker layout cannot prove exact spelling or file-scope versus function-local scope by itself.

## Evidence Checked

- IDA MCP/manual checks:
  - `server_health` and `idb_list` for active database `9b0396a3`.
  - `survey_binary` for `.data` range `0x0066d000-0x0069d000`.
  - `entity_query` over the target for names/globals.
  - one 1212-byte `get_bytes` read of `0x006702c8-0x00670784`.
  - `xrefs_to` for all six array starts, all three padding starts, the rain end, and first snow anchors.
  - `decompile`, `func_profile`, and exact-address instruction queries for `0x005c1460` and `0x005c1810`.
  - `insn_query` for `movsx` and `movzx` in both consumers.
- Documentation:
  - target UID0001ON;
  - UID0000P8 and UID0000MY by-file pages;
  - UID0000BJ class page;
  - UID0000TP global page;
  - UID0001WJ struct page;
  - UID0003PJ and UID0003PK consumer pages;
  - current `by-structure.md`;
  - broad executed UID0001NZ and UID0002Z8 reports;
  - current generated WeatherLayerPane/RainingLayerPane source and research tracker.
- Manual coverage roots and all applicable rows were read for exact no-loss handoff.
- Research-phase checks did not fail or become unavailable; IDA mutation and validators were intentionally skipped before Gate 1. The accepted callback subsequently ran the eight scoped ordinary-file validators recorded below and made no IDA mutation.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1ON-01 | 0001ON | The target is an exact 1212-byte writable `.data` range. | exact | MCP segment and full byte read; whole-range SHA256 `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4` | UID0001ON Status/Evidence | incorporate | applied |
| C1ON-02 | 0001ON | `0x6702c8-0x670478` is a 432-byte `3x24` streak array. | exact | bytes and consumer stride | UID0001ON range map/R1 | incorporate | applied |
| C1ON-03 | 0001ON | `0x670478-0x6704cc` is an 84-byte `3x7` small-splash array. | exact | bytes and consumer stride | UID0001ON range map/R1 | incorporate | applied |
| C1ON-04 | 0001ON | `0x6704cc-0x6704d0` is four-byte alignment, not a splash record. | very strong | zero bytes, zero xrefs, next object alignment; callback COFF gap is symbol-free | UID0001ON padding analysis | incorporate | applied |
| C1ON-05 | 0001ON | `0x6704d0-0x670524` is an 84-byte `3x7` large-splash array. | exact | bytes and consumer stride | UID0001ON range map/R1 | incorporate | applied |
| C1ON-06 | 0001ON | `0x670524-0x670528` is four-byte alignment. | very strong | zero bytes, zero xrefs; callback COFF gap is symbol-free | UID0001ON padding analysis | incorporate | applied |
| C1ON-07 | 0001ON | `0x670528-0x6706d8` is the second 432-byte `3x24` streak array. | exact | bytes and consumer stride | UID0001ON range map/R1 | incorporate | applied |
| C1ON-08 | 0001ON | `0x6706d8-0x67072c` is the second 84-byte `3x7` small-splash array. | exact | bytes and consumer stride | UID0001ON range map/R1 | incorporate | applied |
| C1ON-09 | 0001ON | `0x67072c-0x670730` is four-byte alignment. | very strong | zero bytes, zero xrefs; callback COFF gap is symbol-free | UID0001ON padding analysis | incorporate | applied |
| C1ON-10 | 0001ON | `0x670730-0x670784` is the second 84-byte `3x7` large-splash array. | exact | bytes and consumer stride | UID0001ON range map/R1 | incorporate | applied |
| C1ON-11 | 0001ON | The three paired array bodies are byte-identical across target/main families. | exact | pairwise SHA256 equality | UID0001ON duplication evidence | incorporate | applied |
| C1ON-12 | 0001ON | Streak records are three signed shorts; splash records are two signed shorts. | exact | 46 `movsx`, zero `movzx`, access formulas | UID0001ON types; UID0001WJ | incorporate | applied |
| C1ON-13 | 0001ON | Each streak frame has 18 drawn records plus six real zero initializer records. | exact | loop bound 18, stride 24, bytes | UID0001ON layout/R1 | incorporate | applied |
| C1ON-14 | 0001ON | Each splash frame contains seven records. | exact | loop bound and stride | UID0001ON layout/R1 | incorporate | applied |
| C1ON-15 | 0001ON | The first family is target-port data, not proven minimap data. | very strong | sole consumer UID0003PK receives supplied target; no minimap-specific route | UID0001ON names; UID0003PK; support docs | reject-stale | applied |
| C1ON-16 | 0001ON | Best type names are `RainStreak` and `RainSplash`. | strong inference | behavior, field roles, concise period style | UID0001ON/R1; UID0001WJ | incorporate | applied |
| C1ON-17 | 0001ON | Best array names are the six `s_targetRain*`/`s_rain*` names in R1. | strong inference | internal linkage, consumers, project `s_` style | UID0001ON/R1; support docs | incorporate | applied |
| C1ON-18 | 0001ON | Arrays must remain writable and non-const. | very strong | `.data` placement | UID0001ON/R1 | incorporate | applied |
| C1ON-19 | 0001ON | Arrays should have internal linkage. | strong inference | sole local consumers, no external refs/names; six local COFF symbols | UID0001ON/R1 | incorporate | applied |
| C1ON-20 | 0001ON | One shared deduplicated table is invalid source shape. | very strong | two physical copies with distinct exclusive consumers | UID0001ON rejected alternatives | reject-invalid | applied |
| C1ON-21 | 0001ON | Explicit padding declarations are invalid. | very strong | gaps are unreferenced alignment between exact arrays; test emitted no gap symbol | UID0001ON padding/R1 | reject-invalid | applied |
| C1ON-22 | 0001ON | Snow begins at `0x670784`; first snow refs are `0x670785/788/78c`. | exact | xrefs and boundary bytes | UID0001ON boundaries | incorporate | applied |
| C1ON-23 | 0001ON | The direct source owner/emitter should be UID0000P8, not UID0000MY. | strong inference | code/vtable/data clustering and current family routes | UID0001ON metadata; UID0000P8/0000MY | incorporate | applied |
| C1ON-24 | 0001ON | Position 0 is required so declarations precede weather consumers. | strong | C++ declaration order and emitter routing | UID0001ON metadata | incorporate | applied |
| C1ON-25 | 0001ON | R1 is exact formal C++ for the target range. | very strong | full byte decode, source-shape analysis, and six-object COFF `.data` hash equality | UID0001ON formal header | incorporate | applied |
| C1ON-26 | 0001ON | Target score should become `93/94`. | strong | all prior blockers resolved except original spellings/scope proof | UID0001ON metadata/rationale | incorporate | applied |
| C1ON-27 | 0001ON | UID0000P8 should become `90/90` and record one-file-family resolution. | strong | clustering and accepted routes | by-file/WeatherLayerPane | incorporate | applied |
| C1ON-28 | 0001ON | UID0000MY remains `86/87` but becomes a rejected/secondary split candidate for this data. | strong | no direct source-path proof; stronger UID0000P8 clustering | by-file/RainingLayerPane | historicalize | applied |
| C1ON-29 | 0001ON | UID0000BJ should become `88/90` while retaining owner/emitter UID0000P8. | strong | source placement/table closure; method bodies still incomplete | by-class/RainingLayerPane | incorporate | applied |
| C1ON-30 | 0001ON | UID0000TP should become `92/90` and replace provisional rain names. | strong | exact rain closure; snow/global caveats remain | by-global/WeatherLayerGlobals | incorporate | applied |
| C1ON-31 | 0001ON | UID0001WJ should become `88/91`; rain layout prose code must become non-code tables and R2. | strong | exact rain types; snow types still broader | by-type/by-struct/WeatherLayerDataLayouts | incorporate | applied |
| C1ON-32 | 0001ON | UID0003PJ retains `86/88` but its stale table-name blocker is removed. | strong | exact main-family names/types now resolved | UID0003PJ Score/Evidence | incorporate | applied |
| C1ON-33 | 0001ON | UID0003PK retains `86/88` and replaces minimap wording with target-port wording. | strong | exact target-family consumer evidence | UID0003PK Status/Evidence | incorporate | applied |
| C1ON-34 | 0001ON | R3 keeps broad WeatherLayerGlobals non-duplicating while pointing rain emission to UID0001ON. | strong | one-definition/emitter policy | UID0000TP formal header | incorporate | applied |
| C1ON-35 | 0001ON | Generated output must move the exact UID0001ON block from the empty Raining source to WeatherLayerPane source exactly once. | strong | command16680 generated readback: six declarations once, R2/R3 once, no UID0001ON empty marker, old source absent | generated readback expectation | incorporate | applied |
| C1ON-36 | 0001ON | All applicable manual rows require the exact no-loss dispositions below. | exact handoff | current five roots/rows reread after callback; exact replacement/absent-row dispositions remain unapplied by B005 | five manual roots/six replacement rows plus two absent-row dispositions | incorporate | blocked |
| C1ON-37 | 0001ON | No direct UID0001ON report, duplicate assignment, or lease exists. | exact assignment-time state | goal/report/lease search; current report is the accepted assigned artifact and zero B005 leases remain | report provenance | already-present | already-present |
| C1ON-38 | 0001ON | IDA names/types should not be mutated in this report-only pass. | exact actor boundary | explicit assignment restriction; callback made no IDA mutation | IDA recommendation | not-applicable | excluded-with-reason |
| C1ON-39 | 0001ON | Wave2/Wave3 suggestions are stale and non-authoritative. | exact policy | skill and current docs; retained only as labeled history | historical evidence treatment | reject-stale | applied |
| C1ON-40 | 0001ON | The pass changes only this report before Gate 1. | exact historical scope | pre-Gate1 file audit; callback changes are separately recorded after acceptance | Changed Files/checklist | incorporate | already-present |

## Positive Evidence Summary

- The complete target can be decoded into exact source initializers with no unknown byte.
- Six direct base xref groups divide cleanly between exactly two rain methods.
- Every table field load is signed; record sizes and dimensions are exact.
- Pairwise-identical segment hashes prove two physical declaration families rather than uncertain overlapping slices.
- All gaps are zero, unreferenced, and alignment-sized.
- Weather code, vtables, and rain/snow data each cluster independently around the same source family.
- Existing class/global/type emitter routes already converge on UID0000P8, so the route change removes an outlier rather than inventing a new owner.

## IDA MCP Facts

- Database: session `9b0396a3`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x400000`.
- Target segment: writable `.data`, `0x0066d000-0x0069d000`.
- Full target bytes: 1212 bytes, SHA256 `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4`.
- Segment hashes:
  - both streak arrays: `93B2AE3B44CC63D2DA850BC54EA31D8EA8D8C03B72700113399F720E37BE1B5D`;
  - both small-splash arrays: `D67D4BBB8566025A1F05C333CDFC4BD80A29E5D24E44A6DBB6FB8A7B06943928`;
  - both large-splash arrays: `FB4C8492E8DD2B2C49B7FE1A19C1D2B3DE1DD166DF55A5AF009612490E1E18A7`;
  - each four-byte zero gap: `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Main paint `sub_5C1460`: start `0x005c1460`, size `0x3ac`; 23 `movsx`, zero `movzx`.
- Target draw `sub_5C1810`: start `0x005c1810`, size `0x3b7`; 23 `movsx`, zero `movzx`.
- Main-view formulas:
  - streak index `3 * (entry + 24 * frame)`, loop 18;
  - splash index `2 * (entry + 7 * frame)`, loop 7.
- Target-port formulas are equivalent against the first physical family.
- Small splash draws two marks; large splash draws four marks in a diamond-like shape.
- Negative IDA facts: no target names/globals, no gap xrefs, no xref at `0x670784`, and no unsigned-extension table load in either consumer.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x006702c8-0x00670478` | UID0001ON subrange | target-port streak array | true | UID0000P8 applied | target 93/94 | exact R1 initializer applied |
| `0x00670478-0x006704cc` | UID0001ON subrange | target-port small splashes | true | UID0000P8 applied | target 93/94 | exact R1 initializer applied |
| `0x006704cc-0x006704d0` | UID0001ON gap | compiler alignment | false source object | target container | n/a | documented, no C++ |
| `0x006704d0-0x00670524` | UID0001ON subrange | target-port large splashes | true | UID0000P8 applied | target 93/94 | exact R1 initializer applied |
| `0x00670524-0x00670528` | UID0001ON gap | compiler alignment | false source object | target container | n/a | documented, no C++ |
| `0x00670528-0x006706d8` | UID0001ON subrange | main-view streak array | true | UID0000P8 applied | target 93/94 | exact R1 initializer applied |
| `0x006706d8-0x0067072c` | UID0001ON subrange | main-view small splashes | true | UID0000P8 applied | target 93/94 | exact R1 initializer applied |
| `0x0067072c-0x00670730` | UID0001ON gap | compiler alignment | false source object | target container | n/a | documented, no C++ |
| `0x00670730-0x00670784` | UID0001ON subrange | main-view large splashes | true | UID0000P8 applied | target 93/94 | exact R1 initializer applied |
| `0x005c1460-0x005c180c` | UID0003PJ | main rain consumer | true | UID0000BJ | 86/88 unchanged | support prose synced |
| `0x005c1810-0x005c1bc7` | UID0003PK | target-port rain consumer | true | UID0000BJ | 86/88 unchanged | support prose synced |
| `0x00670784-0x006707d0` | UID0001OO | successor snow pattern data | true | separate snow route | 84/manual | excluded from R1 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006702c8` | `0x005c1877`, `sub_5C1810` | target streak base |
| `0x00670478` | `0x005c1950`, `0x005c19bd`, `sub_5C1810` | target small-splash x/y reads |
| `0x006704cc` | none | alignment gap |
| `0x006704d0` | `0x005c1a3a`, `0x005c1aa5`, `0x005c1b10`, `0x005c1b7e`, `sub_5C1810` | target large-splash reads |
| `0x00670524` | none | alignment gap |
| `0x00670528` | `0x005c14d3`, `sub_5C1460` | main streak base |
| `0x006706d8` | `0x005c15ad`, `0x005c1617`, `sub_5C1460` | main small-splash reads |
| `0x0067072c` | none | alignment gap |
| `0x00670730` | `0x005c168d`, `0x005c16f7`, `0x005c1761`, `0x005c17ce`, `sub_5C1460` | main large-splash reads |
| `0x00670784` | none | exact rain/snow boundary |
| `0x00670785` | `0x005c207f`, `sub_5C1F50` | first direct snow threshold ref |
| `0x00670788` | `0x005c20a9`, `sub_5C1F50` | snow size-table ref |
| `0x0067078c` | `0x005c2134`, `sub_5C20E0` | snow pattern ref |

## Documentation Evidence And IDA Status

- Historical pre-callback state: UID0001ON had correct broad ownership, frame/stride, and snow-boundary evidence, but its source names, table extents, source placement, and formal block were incomplete.
- Current callback state: UID0000TP and UID0001WJ preserve their full rain/snow family evidence while current rain names/types and R2/R3 are applied; provisional names remain only as labeled history.
- UID0000P8 owns the current class/global/type/data emitter family and records contiguous weather code.
- Historical pre-callback state: UID0000MY was the direct standalone rain-file route and emitted only an empty UID0001ON marker. It is now a secondary historical source-split candidate and the orphan generated source is absent.
- UID0003PJ and UID0003PK accurately document the consumers with exact current table names/types; their remaining helper/field/method-body blockers are retained.
- IDA remains untyped at the target. That is a database presentation state, not evidence against the recovered source declarations.

## Ranked Ownership Analysis

### 1. [UID:0000P8] WeatherLayerPane source family

- Evidence for:
  - contiguous weather base/rain/snow/swallow code;
  - contiguous weather RTTI/vtable families;
  - contiguous rain and snow static data;
  - existing Raining/Snowing/Swallow/Weather class routes;
  - existing WeatherLayerGlobals and WeatherLayerDataLayouts routes;
  - generated `WeatherLayerPane.cpp` already carries the family.
- Evidence against:
  - no original PDB/source path proves the exact filename;
  - dedicated by-file candidates exist.
- Decision: accepted as the best direct file owner and emitter for UID0001ON.

### 2. [UID:0000MY] dedicated RainingLayerPane file

- Evidence for:
  - exact tables are rain-only;
  - a dedicated by-file candidate exists;
  - one-file-per-class was common.
- Evidence against:
  - current rain class/method emitter route does not use it;
  - it produces only an empty marker;
  - rain data physically abuts snow data;
  - all three independent binary clustering signals support the broader family;
  - old separate-file provenance is stale Wave2/Wave3 material.
- Decision: reject as the current target route; preserve as a historical/secondary candidate requiring future direct source/PDB proof.

### 3. [UID:0000TP] WeatherLayerGlobals or [UID:0001WJ] WeatherLayerDataLayouts

- Evidence for:
  - both describe the data semantically.
- Evidence against:
  - they are broad support pages, not the exact source file;
  - emitting through them would duplicate or broaden the target declaration block.
- Decision: retain as support-only routes under UID0000P8; exact source remains UID0001ON.

### Proposed new file/grouping, if applicable

- Not applicable. UID0000P8 already represents the best source grouping and no new by-file page is needed.

## Source Placement

- Current accepted source file: `NexusTK/map/WeatherLayerPane.cpp`.
- Current accepted location: file scope before weather class method definitions, using `EMITTER_POSITION_OPTIONAL:0`.
- Current accepted linkage: `static`.
- The record types are private implementation types in the same `.cpp`; no public header is required.
- Rejected placements: standalone `RainingLayerPane.cpp`, `MapPane.cpp`, generic render/GrafPort code, a shared globals translation unit, a type-only header, or a generated raw-data file.
- Remaining uncertainty: exact original filename and exact identifier spellings are unavailable. That uncertainty caps the score below 95 but does not justify retaining decompiler labels or blank C++.

## Range / Split / Padding / Reclassification Analysis

- The target remains one by-memory page because all six declarations form one coherent rain source-data group.
- Exact source-bearing spans are listed in the inventory; no child split is needed.
- The three four-byte gaps remain documented inside the physical page but must not become child pages or explicit formal objects.
- The target remains `RECONSTRUCTABLE:TRUE`.
- Its canonical owner/emitter changed from UID0000MY to UID0000P8.
- The snow successor UID0001OO remains out of scope and must not be absorbed.

## Negative Evidence Summary

- No source or decorated symbol identifies any table/type.
- No IDA name/global exists inside the range.
- No minimap-specific call route supports the old names.
- No external consumer supports `extern`/exported globals.
- No unsigned loads support unsigned coordinates.
- No write is required to prove mutability; writable `.data` placement is enough to reject source `const`.
- No xref supports treating the zero gaps as records.
- No evidence supports deduplicating the two physical families.
- No direct source/PDB path proves `RainingLayerPane.cpp`; the stale separate-file provenance was rejected.
- Lack of original symbols is not used as a blocker: best human source names are supplied.

## IDA Rename / Type / Comment Recommendations

- Source-facing names/types are R1's `RainStreak`, `RainSplash`, and six `s_` arrays.
- If a future supervisor explicitly authorizes IDA mutation, these descriptive names/types are safe documentation aliases after the by-* callback is accepted; they must be labeled inferred rather than original-symbol recovered.
- No IDA rename/type/comment edit was requested or made during the report-only phase or accepted callback.
- Raw `word_6702C8`-style labels must not enter final C++.

## First-Draft C++ Recommendation

- Eligible for draft/finalizing C++: yes, and R1 is applied. The target is reconstructable, the accepted UID0000P8 emitter reaches a valid file root, the current score clears the code gate, every target byte has a source-level disposition, and the mandatory object-layout test passed.
- Accepted and currently applied target managed header/formal R1:

```text
*** UID:0001ON | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct RainStreak {
    short x;
    short y;
    short length;
};

struct RainSplash {
    short x;
    short y;
};

static RainStreak s_targetRainStreaks[3][24] = {
    {
        { 87, 1, 30 }, { 167, 17, 30 }, { 215, 1, 46 },
        { 247, 65, 30 }, { 335, 9, 22 }, { 357, 40, 14 },
        { 39, 113, 30 }, { 103, 97, 46 }, { 151, 161, 30 },
        { 199, 145, 30 }, { 263, 129, 46 }, { 319, 97, 42 },
        { 357, 159, 30 }, { 39, 225, 30 }, { 95, 257, 22 },
        { 199, 257, 22 }, { 228, 295, 4 }, { 295, 289, 8 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 23, 1, 14 }, { 39, 49, 46 }, { 79, 1, 6 },
        { 105, 1, 18 }, { 231, 17, 30 }, { 319, 1, 7 },
        { 335, 33, 30 }, { 355, 73, 26 }, { 55, 145, 46 },
        { 143, 97, 54 }, { 135, 193, 46 }, { 191, 129, 30 },
        { 279, 129, 46 }, { 356, 161, 47 }, { 55, 290, 9 },
        { 103, 303, 3 }, { 199, 209, 30 }, { 215, 273, 17 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 15, 1, 22 }, { 39, 33, 30 }, { 119, 21, 54 },
        { 167, 1, 14 }, { 7, 129, 7 }, { 127, 213, 38 },
        { 215, 33, 46 }, { 237, 83, 52 }, { 256, 185, 14 },
        { 354, 69, 6 }, { 31, 177, 20 }, { 71, 225, 30 },
        { 103, 189, 10 }, { 183, 225, 40 }, { 247, 177, 46 },
        { 279, 257, 23 }, { 336, 265, 20 }, { 307, 1, 14 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    }
};

static RainSplash s_targetRainSmallSplashes[3][7] = {
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    },
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    }
};

static RainSplash s_targetRainLargeSplashes[3][7] = {
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    },
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    }
};

static RainStreak s_rainStreaks[3][24] = {
    {
        { 87, 1, 30 }, { 167, 17, 30 }, { 215, 1, 46 },
        { 247, 65, 30 }, { 335, 9, 22 }, { 357, 40, 14 },
        { 39, 113, 30 }, { 103, 97, 46 }, { 151, 161, 30 },
        { 199, 145, 30 }, { 263, 129, 46 }, { 319, 97, 42 },
        { 357, 159, 30 }, { 39, 225, 30 }, { 95, 257, 22 },
        { 199, 257, 22 }, { 228, 295, 4 }, { 295, 289, 8 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 23, 1, 14 }, { 39, 49, 46 }, { 79, 1, 6 },
        { 105, 1, 18 }, { 231, 17, 30 }, { 319, 1, 7 },
        { 335, 33, 30 }, { 355, 73, 26 }, { 55, 145, 46 },
        { 143, 97, 54 }, { 135, 193, 46 }, { 191, 129, 30 },
        { 279, 129, 46 }, { 356, 161, 47 }, { 55, 290, 9 },
        { 103, 303, 3 }, { 199, 209, 30 }, { 215, 273, 17 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 15, 1, 22 }, { 39, 33, 30 }, { 119, 21, 54 },
        { 167, 1, 14 }, { 7, 129, 7 }, { 127, 213, 38 },
        { 215, 33, 46 }, { 237, 83, 52 }, { 256, 185, 14 },
        { 354, 69, 6 }, { 31, 177, 20 }, { 71, 225, 30 },
        { 103, 189, 10 }, { 183, 225, 40 }, { 247, 177, 46 },
        { 279, 257, 23 }, { 336, 265, 20 }, { 307, 1, 14 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    }
};

static RainSplash s_rainSmallSplashes[3][7] = {
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    },
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    }
};

static RainSplash s_rainLargeSplashes[3][7] = {
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    },
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    }
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Accepted and currently applied [UID:0001WJ] complete managed header/formal R2:

```text
*** UID:0001WJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RainStreak and RainSplash are private implementation types emitted with the exact rain arrays by [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md); remaining weather layouts stay on their exact source pages.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Accepted and currently applied [UID:0000TP] complete managed header/formal R3:

```text
*** UID:0000TP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact rain declarations emit from [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md); remaining weather globals are represented by their exact rain/snow data pages and consuming methods.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Why R1 preserves behavior:
  - every field and initializer comes from the exact target bytes;
  - array dimensions reproduce the exact consumer formulas;
  - signed shorts reproduce `movsx`;
  - writable static storage reproduces `.data`;
  - six declarations preserve both physical copies;
  - no explicit padding object changes indexing or introduces false semantics.
- Why R1 matches plausible original source:
  - simple C++03 structs, C arrays, and internal-linkage definitions are period-appropriate;
  - names describe human rendering concepts, not addresses/decompiler artifacts;
  - no `std::array`, lambdas, constexpr, generated byte blobs, IDA names, or explicit linker artifacts are present.

### Callback Acceptance Test: Six Objects And Alignment Gaps

R1 was marked applied only after the callback passed the required six-object test. The target executable records linker `14.16`; the locally installed/current project x86 MSVC toolset is `cl 19.44.35226.0`. The ordinary declarations were compiled with the project-relevant x86 ABI/alignment/optimization settings and reproduced the executable's complete physical bytes, not merely semantic values:

1. Current generated `auto-generated/NexusTK/map/WeatherLayerPane.cpp` contains the six declarations exactly once, with no deduplication, alias, helper-generated copy, explicit byte-padding object, or seventh rain-data object.
2. The B005 layout-test translation unit compiled with x86 MSVC `/O2 /MT /EHsc /Zp8 /Gy- /Gw-` and its COFF `.data` contains six distinct internal objects in this exact declaration order and with these exact sizes/relative starts:
   - `s_targetRainStreaks`: start `+0x000`, size `0x1b0`;
   - `s_targetRainSmallSplashes`: start `+0x1b0`, size `0x54`;
   - `s_targetRainLargeSplashes`: start `+0x208`, size `0x54`, proving gap `+0x204-+0x208`;
   - `s_rainStreaks`: start `+0x260`, size `0x1b0`, proving gap `+0x25c-+0x260`;
   - `s_rainSmallSplashes`: start `+0x410`, size `0x54`;
   - `s_rainLargeSplashes`: start `+0x468`, size `0x54`, proving gap `+0x464-+0x468`;
   - total covered extent: `+0x000-+0x4bc`.
3. COFF data from the first array start through `+0x4bc` has exact SHA256 `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4` and exact four zero bytes in each of the three gaps.
4. COFF symbols confirm that the three gaps have no source symbol/object of their own and arise from declaration alignment only.
5. Ordinary R1 declarations passed every start, gap, extent, distinct-object, and hash assertion. The conditional `__declspec(align(8))` fallback was therefore not applied, and no raw `char` padding, dummy record, or linker-byte blob was introduced.

## Final Recommendation

- Applied the complete managed header replacement R1 to UID0001ON and moved its direct owner/emitter to UID0000P8 at position 0.
- UID0001ON is now `93/94`.
- Resolved the source-family question in favor of `WeatherLayerPane.cpp` while preserving dedicated `RainingLayerPane.cpp` as a superseded/secondary hypothesis.
- Updated UID0000P8, UID0000MY, UID0000BJ, UID0000TP, UID0001WJ, UID0003PJ, and UID0003PK at full report detail.
- Applied the complete managed header replacements R2 and R3 only to their exact support destinations; rain C++ exists only in managed formal headers, with non-emitting support detail retained as prose/layout tables.
- The six-object/toolchain-layout test above was enforced as a callback acceptance gate and passed before R1 was marked applied.
- The callback did not split the target, emit source padding, deduplicate arrays, use `const`, preserve `g_minimap*` as current, or hand-write raw address labels.
- Future work outside this target: complete the remaining helper/field/formal C++ blockers in UID0003PJ/UID0003PK. This report removes their table-name/type/source-placement blocker but does not claim complete method reconstruction.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x006702c8-0x00670784.RainCoordinateTables.md`.
- Current metadata:
  - `COMPLETION:93`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:0000P8`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000P8`
  - `EMITTER_POSITION_OPTIONAL:0`
  - complete managed UID0001ON metadata/formal header is R1, including its exact managed body delimiters
- Applied Item Summary:
  - `Exact writable three-frame signed-short rain streak/splash arrays for RainingLayerPane main-view and target-port drawing, with duplicated physical families, exclusive consumers, and three compiler-alignment gaps.`
- Applied the nine exact spans/dimensions in the inventory and added whole/segment hashes, pairwise equality, complete initializer provenance, signedness proof, xref table, source declaration/linkage reasoning, and grouped WeatherLayerPane source placement.
- Historicalized:
  - `g_minimap*` and `g_rainStreakCoords` as superseded provisional names;
  - 88-byte splash-range wording;
  - blank-C++ rationale based on unresolved names/declarations;
  - dedicated UID0000MY route as the earlier split hypothesis.
- Preserved all earlier date-stamped evidence and score history in `Changes`, labeling superseded conclusions rather than deleting them.

## Recommended Support Doc Changes

- `by-file/WeatherLayerPane.md` [UID0000P8]:
  - applied `88/86 -> 90/90`;
  - recorded the three independent clustering signals and selected the one-file family as current best source placement;
  - listed R1's exact rain declarations as source-family contents;
  - preserved all existing snow/swallow/raw-helper evidence and old split hypothesis as historical.
- `by-file/RainingLayerPane.md` [UID0000MY]:
  - retained `86/87`;
  - recorded that UID0001ON no longer routes here and that dedicated source remains a secondary historical hypothesis;
  - replaced current `minimap` wording with target-port wording;
  - preserved exact class/method evidence.
- `by-class/RainingLayerPane.md` [UID0000BJ]:
  - applied `86/88 -> 88/90`;
  - retained `CANONICAL_OWNER:0000P8`, `EMITTER_UIDS:0000P8`, and class `[[CHILDREN]]` route;
  - documented exact file-static rain types/arrays and removed table-name/source-split as unresolved class blockers;
  - preserved remaining method/helper blockers.
- `by-global/WeatherLayerGlobals.md` [UID0000TP]:
  - applied `91/87 -> 92/90`;
  - replaced provisional current `g_minimap*`/`g_rain*` rain rows with R1 names and internal-linkage status;
  - added exact signedness, dimensions, duplicate-family hashes, and alignment facts;
  - applied complete managed header replacement R3 and preserved all snow/global/alias evidence.
- `by-type/by-struct/WeatherLayerDataLayouts.md` [UID0001WJ]:
  - applied `85/89 -> 88/91`;
  - replaced current `RainStreakCoord`/`RainSplashCoord` with exact `RainStreak`/`RainSplash` layout prose;
  - converted the broad out-of-header C++ hypothesis block into no-loss field-layout tables so no draft/example C++ remains outside formal metadata;
  - applied complete managed header replacement R2 and preserved every snow layout and its unresolved names.
- `by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md` [UID0003PJ]:
  - retained `86/88`, owner/emitter, and blank formal C++;
  - added exact `s_rain*` names, signed-short types, frame dimensions, and pairwise-duplicate evidence;
  - removed table names/source split from the blocker list and retained unresolved GrafPort/helper/field/method C++ blockers.
- `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md` [UID0003PK]:
  - retained `86/88`, owner/emitter, and blank formal C++;
  - replaced current minimap-specific wording with target-port wording;
  - added exact `s_targetRain*` names, signed-short types, frame dimensions, and pairwise-duplicate evidence;
  - removed table names/source split from the blocker list and retained remaining method blockers.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/91`, owner/emitter UID0000MY, reconstructable true, blank position/formal.
- Current accepted target: `93/94`, owner/emitter UID0000P8, reconstructable true, position 0, R1 formal.
- Reason not higher:
  - original symbols do not survive;
  - exact historical spelling is inferred;
  - file-scope versus function-local `static` cannot be proven from the binary alone;
  - exact original filename lacks PDB/source-path proof;
  - scores at or above 95 are reserved for near-final source certainty.
- Reason not lower:
  - all 1212 bytes are classified;
  - all boundaries, xrefs, consumers, signed fields, dimensions, formulas, initializer values, duplicate copies, and gaps are exact;
  - source linkage/mutability and best owner/emitter are supported by multiple independent evidence classes;
  - formal C++ is behavior-complete for the target.
- Score-improvement attempt:
  - provisional names -> resolved through consumer role, linkage, project style, and rejected alternatives;
  - untyped words -> resolved through signed instruction audit and exact record strides;
  - blank declarations -> resolved with R1;
  - uncertain gaps -> resolved as alignment through bytes/xrefs/object sizes;
  - minimap assumption -> rejected through caller/consumer evidence;
  - standalone versus family file -> resolved to UID0000P8 through code/vtable/data clustering and current route consistency;
  - duplicated tables -> resolved as six declarations through pairwise hashes and exclusive consumers.

## Open Questions With Attempted Resolution

- Exact original identifier spellings:
  - checked IDA names/globals, strings, current docs, old reports, current project naming, consumers, and generated source;
  - no original symbols survive;
  - resolved to the best human names in R1. This is not a blocker and raw names must not remain.
- File-scope versus function-local `static`:
  - checked exclusive consumers, physical order, contiguous declaration block, emitter model, and period style;
  - file-scope `static` is selected as the stronger implementation-ready source form;
  - function-local statics remain a lower-ranked historical alternative only and do not block R1.
- One source file versus per-layer files:
  - checked code order, RTTI/vtable order, data order, current routes, file candidates, old reports, and stale provenance;
  - `WeatherLayerPane.cpp` is selected as the high-probability source family;
  - future direct PDB/source evidence may override the inference, but no current evidence justifies deferral.
- Explicit alignment syntax:
  - checked exact gap size, array sizes, addresses, xrefs, and source declaration alignment;
  - ordinary declarations were the first and most plausible source form and were not accepted on assumption alone;
  - callback compilation proved the six object starts, three four-byte gaps, total `0x4bc` extent, and full physical hash under the available x86 MSVC toolchain;
  - default alignment passed, so `__declspec(align(8))` was unnecessary; unexplained source padding objects remain rejected.
- No source-quality question remains that requires the target formal block to stay blank.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Historical Gate-1 manual-root checkpoints:

- `by-memory/-coverage-report.md`: SHA256 `A7D812B60CB35399C541461DC0E214A8380B61D7793E2BB499B9247449A1A70B`, 1,982,596 bytes, 4,564 lines.
- `by-file/-coverage-report.md`: SHA256 `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90`, 154,448 bytes, 317 lines.
- `by-class/-coverage-report.md`: SHA256 `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E`, 257,808 bytes, 624 lines.
- `by-global/-coverage-report.md`: SHA256 `D25BDD5BB2F097258C9B76628317CDC773F8E4F1014B808BAB421E1CC0040226`, 99,098 bytes, 217 lines.
- `by-type/by-struct/-coverage-report.md`: SHA256 `04ADEC897541A72ACC40FAB47489583F5D927FB483A4DA10B25DFD11CA51819E`, 58,207 bytes, 137 lines.

Current post-callback supervisor-owned root/readback checkpoints:

- `by-memory/-coverage-report.md`: SHA256 `723B4F8683F4F1BA6432877FC5AF950A3DF7843ABAF69CC85900F91CB4C89331`, 1,986,657 bytes, 4,569 lines. UID0001ON remains the pre-handoff `84%`/strong row at line 4331; UID0003PJ and UID0003PK still have no direct row.
- `by-file/-coverage-report.md`: SHA256 `70155286C7996606A19DC0CCDB35106FBA2901902BEE0D33C15068A6BC22305E`, 154,839 bytes, 317 lines. UID0000MY remains the pre-handoff `84%`/strong row at line 223; UID0000P8 remains the pre-handoff `86%`/medium-high row at line 305.
- `by-class/-coverage-report.md`: SHA256 `BB86D73534E40EBA319F364F58E2980595A864B2F2596FBCC9B0B4BB5EA833E5`, 258,083 bytes, 624 lines. UID0000BJ remains the pre-handoff `86%`/strong row at line 438.
- `by-global/-coverage-report.md`: SHA256 `D25BDD5BB2F097258C9B76628317CDC773F8E4F1014B808BAB421E1CC0040226`, 99,098 bytes, 217 lines. UID0000TP remains the pre-handoff `91%`/strong row at line 200.
- `by-type/by-struct/-coverage-report.md`: SHA256 `04ADEC897541A72ACC40FAB47489583F5D927FB483A4DA10B25DFD11CA51819E`, 58,207 bytes, 137 lines. UID0001WJ remains the pre-handoff `85%`/strong row at line 128.
- These current rows were reread after command16680 and remain exactly the rows that the no-loss replacements below supersede. B005 made zero manual-root edits; C1ON-36 remains blocked solely on the supervisor-only actor boundary.

Exact no-loss replacement rows:

1. Replace current by-memory line 4331 for UID0001ON with:

```text
    - [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) 0x006702c8-0x00670784 | static weather data | RainCoordinateTables : reconstructable : 93% : very-strong : Exact writable three-frame signed-short RainStreak/RainSplash arrays for RainingLayerPane main-view and target-port drawing; full bytes, six exclusive table-start consumer groups, 18-of-24 streak usage, seven-entry splash frames, byte-identical physical families, three unreferenced four-byte alignment gaps, hard snow boundary, internal linkage, WeatherLayerPane.cpp source route, and complete formal initializers are documented.
```

2. UID0003PJ and UID0003PK have no current direct rows in `by-memory/-coverage-report.md` after exact UID/path/address search. Do not invent new rows solely for metadata-unchanged prose synchronization. Their consumer facts are represented in the no-loss UID0001ON row above and the exact by-class/by-file rows below; generated tracker/coverage will continue to enumerate their pages.

3. Replace current by-file line 305 for UID0000P8 with:

```text
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) : reconstructable : 90% : very-strong : Weather-layer source family under NexusTK/map/ with map ownership, exact base/rain/snow/swallow class and memory routes, global/type support, live IDA checks, contiguous weather code and RTTI/vtables, adjacent rain/snow data, source-ready UID0001ON signed-short rain arrays, and the one-file WeatherLayerPane.cpp placement selected as the strongest current inference while historical split-file alternatives remain recorded.
```

4. Replace current by-file line 223 for UID0000MY with:

```text
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) : reconstructable : 86% : strong : Rain-overlay dedicated-file candidate under NexusTK/map/ with exact constructor/paint/target-port methods, MapPane weather-constructor path, rain vtables, active-map weather-state checks, and exact rain-table consumers preserved; UID0001ON now routes to the stronger contiguous WeatherLayerPane.cpp family, so standalone RainingLayerPane.cpp remains a historical/secondary source-split hypothesis rather than the current data emitter.
```

5. Replace current by-class line 438 for UID0000BJ with:

```text
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) : reconstructable : 88% : very-strong : Direct RainingLayerPane class evidence with exact constructor/paint/target-port ranges, MapPane caller, base-constructor call, vtable stores and rain render slots; UID0001ON now resolves the signed-short file-static rain types, six exact array declarations, duplicated physical families, and WeatherLayerPane.cpp route, while remaining method helper/field C++ blockers stay documented.
```

6. Replace current by-global line 200 for UID0000TP with:

```text
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) : reconstructable : 92% : very-strong : Weather static-data family attached to WeatherLayerPane.cpp with live-confirmed rain/snow ranges, descriptor/guard storage, saved weather method labels, callback dependency, g_activeMapPane alias checks, and one-file/per-layer history preserved; UID0001ON now supplies exact writable internal-linkage signed-short RainStreak/RainSplash declarations, six physical arrays, complete initializers, exclusive consumers, and compiler-alignment evidence without duplicating the broad global block.
```

7. Replace current by-struct line 128 for UID0001WJ with:

```text
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md) : reconstructable : 88% : very-strong : Weather-layer layout support attached to WeatherLayerPane.cpp; live MCP proves exact signed-short RainStreak and RainSplash fields, 3x24/3x7 dimensions, duplicate rain families, 20-byte SnowParticleEntry records, and 40-byte SnowPatternDescriptor records, with exact rain types emitted by UID0001ON while broader snow names/header placement and callback ownership remain documented caveats.
```

Reason B005 must not apply these rows directly: all `-coverage-report.md` roots are supervisor-owned under the active workflow. The supervisor must reread/rebase every root immediately before applying, preserve any unrelated concurrent additions, validate each changed coverage root serially, and record the resulting current hashes/anchors in this report during callback reconciliation.

## Follow-Up Actions

- Supervisor:
  - perform fresh exact-artifact Gate 1/Gate 2 verification against this callback-reconciled report;
  - verify each C1ON claim, R1-R3, toolchain test, score, owner/emitter, support destination hash, validator record, and current generated readback;
  - reread/rebase and apply the exact five-root manual coverage handoff without loss, validate those roots serially, then update this report or return an exact repair instruction if the manual-root epoch advances;
  - run the supervisor-owned report lifecycle only after the manual rows and Gate 2 pass.
- B005 callback work is complete:
  - eight ordinary destinations were leased/edited/validated/released serially;
  - full accepted detail, R1-R3, score/source/history changes, toolchain acceptance, hashes, commands, generated readback, and ledger/checklist truth are recorded here;
  - B005 retains zero leases and made no manual/generated/tracker/supervisor/validator-state/IDA/lifecycle edit;
  - B005 remains loaded for exact report-only repair if supervisor verification rejects a concrete claim.
- Future research outside callback:
  - UID0003PJ/UID0003PK need separate method-body closure for remaining helper/field/formal blockers; the rain table blocker is no longer valid.

## Confidence

- Recommendation confidence: very strong (`94`) for target reconstruction and strong for exact source-family inference.
- Score confidence: strong; `93/94` reflects exact behavior/data with sub-95 historical spelling/scope uncertainty.
- Remaining uncertainty: exact original names, exact translation-unit filename, and file-scope versus function-local spelling only. None requires decompiler-shaped final source or blank target C++.

## Validator Results

- Required workdir for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Every accepted ordinary destination was validated serially while B005 held only that destination's immediate lease; every command exited `0`, returned `ok: 1`, completed `--wait-generated`, and was followed by immediate lease release.

| Command ID | Timestamp | Literal command | Result / bounded diagnostics |
| --- | --- | --- | --- |
| `000000016662` | `2026-07-22T23:34:31-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x006702c8-0x00670784.RainCoordinateTables.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; target became 93/94 and emitted through UID0000P8. |
| `000000016666` | `2026-07-22T23:36:37-04:00` | `python .\tools\validator.py --mode file --file by-file\WeatherLayerPane.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; 34 pre-existing missing-reference diagnostics for weather children including UID0003PG/PH/PI/PJ/PK were bounded unrelated. |
| `000000016668` | `2026-07-22T23:37:54-04:00` | `python .\tools\validator.py --mode file --file by-file\RainingLayerPane.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; 15 pre-existing UID0003PI/PJ/PK missing-reference diagnostics were bounded unrelated; validator removed orphaned generated `NexusTK/map/RainingLayerPane.cpp` after the accepted route change. |
| `000000016670` | `2026-07-22T23:38:53-04:00` | `python .\tools\validator.py --mode file --file by-class\RainingLayerPane.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; 12 pre-existing UID0003PI/PJ/PK missing-reference diagnostics were bounded unrelated. |
| `000000016672` | `2026-07-22T23:40:30-04:00` | `python .\tools\validator.py --mode file --file by-global\WeatherLayerGlobals.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; no target-specific unresolved diagnostic. |
| `000000016678` | `2026-07-22T23:46:38-04:00` | `python .\tools\validator.py --mode file --file by-type\by-struct\WeatherLayerDataLayouts.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; three pre-existing UID0003O2 missing-reference diagnostics were bounded unrelated. |
| `000000016679` | `2026-07-22T23:47:52-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; transient UID0003PK missing-reference diagnostic occurred because the sibling had not yet received its current registry pass. |
| `000000016680` | `2026-07-22T23:49:26-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1, generated refresh completed; registered UID0003PK and resolved the prior sibling sequencing condition. |

- Accepted callback generated verification at command16680, reconfirmed unchanged by later unrelated current commands16688/16689:
  - `auto-generated/NexusTK/map/WeatherLayerPane.cpp` contains each of the six R1 declarations exactly once, R2 exactly once, R3 exactly once, and zero UID0001ON empty markers;
  - two remaining empty markers are only the intentionally blank method pages UID0003PJ and UID0003PK;
  - `auto-generated/NexusTK/map/RainingLayerPane.cpp` is absent;
  - tracker row is `93/94`, reconstructable true, zero direct/additional/B-agent report coverage at line 3414.
- Six-object callback acceptance:
  - B005 source `tools/leaser/Agents/Agent-B005/research/0001ON-layout-test.cpp`, SHA256 `CF9D838DB4234C0084962845DBCB4C07F8168A671C7E92491F3DE3F1680B61F2`, 4,896 bytes, 145 lines;
  - compiled with locally available x86 MSVC `cl 19.44.35226.0` using `/nologo /c /O2 /MT /EHsc /Zp8 /Gy- /Gw-`;
  - object `tools/leaser/Agents/Agent-B005/research/0001ON-layout-test.obj`, SHA256 `665629C4908D532CB1B3079492C5D9E68A3A9CB5113EA6D468B81344CBEB9E91`, 2,486 bytes;
  - COFF `.data` is exactly `0x4bc` bytes; symbols occur at `+0x000/+0x1b0/+0x208/+0x260/+0x410/+0x468` with sizes `0x1b0/0x54/0x54/0x1b0/0x54/0x54`; each intervening four-byte gap is zero and symbol-free; `.data` SHA256 is exactly `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4`.
- No unresolved target-specific validator error remains. Broad marker/missing-reference diagnostics printed by the validator are pre-existing project conditions and are explicitly bounded above.

## Changed Files

- Modified ordinary callback destinations:
  - `by-memory/0x006702c8-0x00670784.RainCoordinateTables.md`: SHA256 `477400B118F7E7AF4A4703E9D260DAE18969CEE9517191CCB9EEA151FB1C4CFE`, 18,597 bytes, 250 lines.
  - `by-file/WeatherLayerPane.md`: SHA256 `E3B00C1A26077446FF3B4D2B3079D08278CD10B6093B9C3A0907B57B69010057`, 28,573 bytes, 131 lines.
  - `by-file/RainingLayerPane.md`: SHA256 `C14C3F0D7343691A7A05DF22B77F5ABF65CC248F643AC7E022761A69EF108935`, 13,138 bytes, 93 lines.
  - `by-class/RainingLayerPane.md`: SHA256 `3F5EDC72AE7A6A50DA4083004A7AE9BFF9713A2EE6ABDAC6D5958FC28D2DDF0E`, 10,028 bytes, 89 lines.
  - `by-global/WeatherLayerGlobals.md`: SHA256 `70D0669F4BCEE68C39FD9110708050661D2C8E6E127C4A29C0E2721462FE38B8`, 18,512 bytes, 133 lines.
  - `by-type/by-struct/WeatherLayerDataLayouts.md`: SHA256 `5C5A8681FEB7026A30801860C8248034838254128C6796AE00E263A61D6CFCA3`, 19,851 bytes, 138 lines.
  - `by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md`: SHA256 `09E68F93CBB4537675E0AE520F52112651ECA85470BF479FE330D603F8709333`, 5,970 bytes, 56 lines.
  - `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`: SHA256 `C76127EC06DE3BE32EA9303683FB3497053DEB2B63ABDCF29C48A0B0E0C58C5A`, 6,559 bytes, 57 lines.
- Created B005-owned callback acceptance artifacts:
  - `tools/leaser/Agents/Agent-B005/research/0001ON-layout-test.cpp`: SHA256 `CF9D838DB4234C0084962845DBCB4C07F8168A671C7E92491F3DE3F1680B61F2`, 4,896 bytes, 145 lines.
  - `tools/leaser/Agents/Agent-B005/research/0001ON-layout-test.obj`: SHA256 `665629C4908D532CB1B3079492C5D9E68A3A9CB5113EA6D468B81344CBEB9E91`, 2,486 bytes.
- Modified this same report after callback: `tools/leaser/Agents/Agent-B005/research/0001ON-RainCoordinateTables-source-quality.md`; its final hash/metrics are reported at handoff.
- Validator-owned read-only current checkpoints:
  - `auto-generated/NexusTK/map/WeatherLayerPane.cpp`: current unrelated command16688/SHA256 `D250DB2E9984E7228BA86843D6782F1DF59AC8B67CC2B095CB05153A658AF7E1`, 12,165 bytes, 268 lines; command16680 was the callback validation checkpoint.
  - `auto-generated/NexusTK/map/RainingLayerPane.cpp`: absent after command16668 accepted route cleanup.
  - `auto-generated/-ag-research-tracker.md`: current unrelated command16689/SHA256 `F33AFE5BD2228B8E0CF88BD5B047C149EB1C5998219B90D9CEC78C4C95993F44`, 1,636,242 bytes, 6,510 lines; UID0001ON semantic row remains `93/94`, true, zero coverage at line 3412.
- Manual coverage roots: read only and unchanged by B005; exact current hashes/anchors and replacement rows are recorded above for supervisor application.
- Leases: eight short ordinary-file leases acquired serially and released; zero B005 leases held at handoff.
- Report execution/lifecycle: not run. B005 did not run/probe `execute_report`, any lifecycle command, or any report validator.

## Implementation Tracking Checklist

Accepted callback tracking:

- [x] Supervisor validated exact pre-callback report SHA256 `48B38BDC454E9BC128D14EB9DB3EBA6ACB590ED668942CEF0FC4585A73CD1EEA`, all 40 ledger claims, R1-R3, destination scope, scores, and manual rows before implementation.
- [x] Updated `by-memory/0x006702c8-0x00670784.RainCoordinateTables.md` to `93/94`, owner/emitter UID0000P8, position 0, exact range/byte/xref/type/name/linkage/source-placement evidence, and R1.
- [x] Updated `by-file/WeatherLayerPane.md` to `90/90` with the accepted one-file source-family inference and complete rain declaration evidence.
- [x] Updated `by-file/RainingLayerPane.md` at unchanged `86/87`, historicalizing its dedicated-file route for UID0001ON while preserving class/method evidence.
- [x] Updated `by-class/RainingLayerPane.md` to `88/90`, preserved UID0000P8 routing/`[[CHILDREN]]`, and removed only resolved table/source-placement blockers.
- [x] Updated `by-global/WeatherLayerGlobals.md` to `92/90`, replaced provisional current rain names, preserved all snow/global/alias evidence, and applied R3.
- [x] Updated `by-type/by-struct/WeatherLayerDataLayouts.md` to `88/91`, moved rain source code out of prose into exact formal ownership/R2, and preserved all snow layout detail.
- [x] Updated `by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md` at unchanged `86/88` with exact main-family names/types/dimensions and remaining blockers.
- [x] Updated `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md` at unchanged `86/88` with target-port names/types/dimensions, no current minimap assertion, and remaining blockers.
- [x] Preserved the six physical arrays, exact duplicate initializers, 18+6 streak frame shape, seven-entry splash frames, three alignment gaps, and hard snow boundary.
- [x] Preserved historical assumptions under explicit superseded labels: `g_minimap*`, `Rain*Coord`, 88-byte splash-plus-gap wording, blank formal, and dedicated UID0000MY emitter.
- [x] Rejected `const`, unsigned fields, shared/deduplicated arrays, explicit padding objects, raw IDA names, modern containers, and code outside formal headers.
- [x] Ran and recorded the callback six-object/toolchain-layout acceptance test: exact six symbols, declaration order, `0x1b0/0x54/0x54/0x1b0/0x54/0x54` sizes, starts `+0x000/+0x1b0/+0x208/+0x260/+0x410/+0x468`, three four-byte zero gaps, total `0x4bc`, and SHA256 `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4`; default alignment passed and no fallback/padding object was used.
- [x] Ran each accepted ordinary-file scoped validator serially from the required workdir while holding only that file's immediate lease, then released it.
- [x] Verified generated WeatherLayerPane/RainingLayerPane C++ and tracker semantics after callback command16680 `--wait-generated`, then reconfirmed the same UID0001ON semantics under later unrelated current commands16688/16689.
- [ ] Supervisor rereads/rebases and applies the exact five-root manual coverage handoff without loss, then validates those roots serially.
- [x] Updated every C1ON ledger row and this checklist with applied/already-present/excluded/blocked proof, exact destination hashes, commands, generated readback, and zero leases.
- [x] Confirmed stale Wave2/Wave3 material remains historical and non-authoritative.
- [x] Confirmed no IDA DB mutation, generated/manual direct edit, lifecycle command, or report self-execution occurred.
- [ ] Supervisor performs fresh exact-artifact Gate 1/Gate 2, completes the manual-root actor-boundary work, and exclusively invokes any accepted report lifecycle command.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000016700","destination_path":"executed-b-agent-research/B005/0001ON-RainCoordinateTables-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001ON-RainCoordinateTables-source-quality.md","timestamp":"2026-07-23T00:17:16-04:00","uid":"0001ON"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
