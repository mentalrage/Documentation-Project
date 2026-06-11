# 000270 WaitableWeatherReadOnlyData Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000270] `0x00631184-0x006313fc.WaitableWeatherReadOnlyData` as a parent-blank, non-emitting mixed `.rdata` container.
- Final disposition: applied. The aggregate remains `RECONSTRUCTABLE:FALSE`, while all six exact children are reconstructable and assigned to their actual direct class parents.
- Required action: no additional split or aggregate assignment is required. Supervisor can archive this report after review; B001 must not move it to `executed`.
- Confidence: high for range boundaries, child ownership, and the aggregate/container disposition.
- Supervisor review: accepted on 2026-06-10 after independent header and coverage checks confirmed the aggregate is `RECONSTRUCTABLE:FALSE`/parent blank, all six exact children are assigned to the direct class parents listed below, the five direct class parents clear `85/85`, generated memory coverage reports the same state, and targeted validator runs exited cleanly for the touched target scope.

## Supporting Research

## Target

- Target UID: `000270`
- Target path: `by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md`
- Source queue/report row: Supervisor row `assigned | Agent-B001 | B001-037`.
- Current supervisor classification: audit mixed WaitableTimer/WeatherLayer/RainingLayer/SnowingLayer/SwallowLayer read-only data island, exact split children, stale grouped pages, and strict child/direct-parent `85/85` gates.
- Current live state after the executed repair: target aggregate `90/93`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID` blank, final C++ blank. Exact children are assigned because both child and direct class parent now pass `85/85`.

## Executive Recommendation

[UID:000270] is not a source owner. It is a physical `.rdata` adjacency island that crosses two source families: `WaitableTimer` utility data at `0x00631184-0x0063118c` and map/weather-layer data/resources at `0x0063118c-0x006313fc`. The correct reconstruction shape is a parent-blank, non-emitting aggregate plus exact assigned child pages.

The exact children now satisfy the assignment gate:

- [UID:0002P2] attaches to direct class parent [UID:0000FY] `WaitableTimer`, now `86/86`.
- [UID:0002Z7] attaches to direct class parent [UID:0000G1] `WeatherLayerPane`, now `86/88`.
- [UID:0002Z8] attaches to direct class parent [UID:0000BJ] `RainingLayerPane`, now `86/88`.
- [UID:0002Z9] attaches to direct class parent [UID:0000DC] `SnowingLayerPane`, now `86/88`.
- [UID:0002ZA] and [UID:0002ZB] attach to direct class parent [UID:0000E9] `SwallowLayerPane`, now `86/88`.

## Supervisor Active Recheck

- The assigned item required split-first review. Exact child pages already existed, and live IDA confirmed their boundaries.
- No missing child range was found inside `0x00631184-0x006313fc`.
- The broad aggregate was correctly repaired to a non-emitting container. After subsequent live parent-gate repair, the exact children are now assigned to direct class parents rather than left unassigned.

## Inference Research Guidance Check

- `by-structure.md` supports `RECONSTRUCTABLE:FALSE` for reviewed mixed aggregates that are only audit/index ranges, even when contained children are reconstructable.
- Direct parent assignment must use the narrowest semantic owner. The vtable/resource children attach to their direct class parents, not to the broad [UID:000270] aggregate and not directly to file pages.
- Existing documentation assumptions were treated as leads. IDA confirmed the exact split boundaries; live headers and coverage now confirm the child/direct-parent gates are clear.

## Evidence Standards Used

- IDA MCP `py_eval` was used during B001-037 for selected dwords, UTF-16 bytes, names, function boundaries, and xrefs.
- Documentation evidence used: target page, exact child pages, five direct class parent pages, predecessor/successor pages, manual memory coverage, generated autogen memory coverage, and stale-reference scan.
- Gate evidence used: live child scores/parents and direct class parent scores from the current headers.

## IDA MCP Facts

- Boundary facts:
  - `0x00631180` reads as zero terminator data before the target.
  - `0x00631184 -> ??_R4WaitableTimer@@6B@`.
  - `0x0063118c -> ??_R4WeatherLayerPane@@6B@`.
  - `0x0063121c -> ??_R4RainingLayerPane@@6B@`.
  - `0x006312ac -> ??_R4SnowingLayerPane@@6B@`.
  - `0x0063133c -> ??_R4SwallowLayerPane@@6B@`.
  - `0x006313fc -> ??_R4WorldMapPane@@6B@`; `0x00631400` is the `WorldMapPane` vtable base.
- Xref facts:
  - `0x00631188` has stores/refs from `0x005c1020`, `0x005c10a8`, `0x005c121b`.
  - `0x00631190`, `0x006311e4`, `0x00631214` have `WeatherLayerPane` constructor store refs at `0x005c12d0`, `0x005c12d6`, `0x005c12e0`.
  - `0x00631220`, `0x00631274`, `0x006312a4` have `RainingLayerPane` constructor store refs at `0x005c1424`, `0x005c1433`, `0x005c143d`.
  - `0x006312b0`, `0x00631304`, `0x00631334` have `SnowingLayerPane` constructor store refs at `0x005c1c0d`, `0x005c1c18`, `0x005c1c22`.
  - `0x00631340`, `0x00631394`, `0x006313c4` have Swallow constructor/destructor refs at `0x005c226d`/`0x005c2340`/`0x005c2a66`, `0x005c2273`/`0x005c2346`/`0x005c2a6c`, and `0x005c227d`/`0x005c2350`/`0x005c2a76`.
  - `0x006313cc` has constructor xrefs from `0x005c22d6` and `0x005c22e9`; `0x006313e4` has constructor xrefs from `0x005c22f0` and `0x005c2303`.
- String facts:
  - `0x006313cc` decodes as UTF-16 `SWALLOW.EPF`.
  - `0x006313e4` decodes as UTF-16 `SWALLOW.EPD`.
- Negative IDA facts:
  - RTTI-adjacent words at class boundaries have no direct xrefs, which is normal for complete-object-locator-adjacent words and does not imply ownership by the preceding range.
  - No full-range xref cluster ties `0x00631184-0x006313fc` to one source owner.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00631184-0x006313fc` | [UID:000270] `WaitableWeatherReadOnlyData` | Mixed physical `.rdata` container | FALSE | none | `90/93` | Parent-blank, non-emitting container |
| `0x00631184-0x0063118c` | [UID:0002P2] `WaitableTimerVtableData` | WaitableTimer RTTI/vtable data | TRUE | [UID:0000FY] `WaitableTimer` class, `86/86` | `88/92` | Assigned |
| `0x0063118c-0x0063121c` | [UID:0002Z7] `WeatherLayerPaneVtableData` | Base weather RTTI/vtable data | TRUE | [UID:0000G1] `WeatherLayerPane` class, `86/88` | `85/90` | Assigned |
| `0x0063121c-0x006312ac` | [UID:0002Z8] `RainingLayerPaneVtableData` | Rain overlay RTTI/vtable data | TRUE | [UID:0000BJ] `RainingLayerPane` class, `86/88` | `85/90` | Assigned |
| `0x006312ac-0x0063133c` | [UID:0002Z9] `SnowingLayerPaneVtableData` | Snow overlay RTTI/vtable data | TRUE | [UID:0000DC] `SnowingLayerPane` class, `86/88` | `85/90` | Assigned |
| `0x0063133c-0x006313cc` | [UID:0002ZA] `SwallowLayerPaneVtableData` | Swallow overlay RTTI/vtable data | TRUE | [UID:0000E9] `SwallowLayerPane` class, `86/88` | `85/90` | Assigned |
| `0x006313cc-0x006313fc` | [UID:0002ZB] `SwallowLayerResourceStrings` | `SWALLOW.EPF` / `SWALLOW.EPD` literals | TRUE | [UID:0000E9] `SwallowLayerPane` class, `86/88` | `85/90` | Assigned |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00631188` | refs from `0x005c1020`, `0x005c10a8`, `0x005c121b` | `WaitableTimer` vtable installed/restored by timer code. |
| `0x00631190` | ref from `0x005c12d0` | `WeatherLayerPane` primary vtable store. |
| `0x00631220` | ref from `0x005c1424` | `RainingLayerPane` primary vtable store. |
| `0x006312b0` | ref from `0x005c1c0d` | `SnowingLayerPane` primary vtable store. |
| `0x00631340` | refs from `0x005c226d`, `0x005c2340`, `0x005c2a66` | `SwallowLayerPane` primary vtable store/restores. |
| `0x006313cc` / `0x006313e4` | refs from `0x005c22d6`/`0x005c22e9` and `0x005c22f0`/`0x005c2303` | Swallow constructor selects resource filenames. |

## Documentation Evidence And IDA Status

- Existing docs confirmed by IDA:
  - [UID:0002P2], [UID:0002Z7], [UID:0002Z8], [UID:0002Z9], [UID:0002ZA], and [UID:0002ZB] have correct boundaries and roles.
  - [UID:00026Z] correctly ends before `0x00631184`.
  - [UID:000271] correctly starts at `0x006313fc`.
- Current live headers confirm assignment:
  - [UID:0002P2] `AUTOGEN_PARENT_UID:0000FY`.
  - [UID:0002Z7] `AUTOGEN_PARENT_UID:0000G1`.
  - [UID:0002Z8] `AUTOGEN_PARENT_UID:0000BJ`.
  - [UID:0002Z9] `AUTOGEN_PARENT_UID:0000DC`.
  - [UID:0002ZA] and [UID:0002ZB] `AUTOGEN_PARENT_UID:0000E9`.
- Current manual and generated coverage confirm assignment:
  - `by-memory/-coverage-report.md` lists [UID:000270] as `not_reconstructable` and each exact child as assigned to the appropriate direct class parent.
  - `auto-generated/-ag-memory-coverage.md` lists [UID:000270] as `not_reconstructable` and [UID:0002P2]/[UID:0002Z7]/[UID:0002Z8]/[UID:0002Z9]/[UID:0002ZA]/[UID:0002ZB] as `assigned`.
- Stale grouped references:
  - `tools/leaser/Agents/SupervisorAssignments.md` still has historical rows naming old `0x00631184-0x00631400.WaitableWeatherReadOnlyData.md`. This is assignment-history metadata, outside B001 edit scope, and not used as current evidence.

## Ranked Ownership Analysis

### 1. Mixed aggregate remains parent blank

- Evidence for: live IDA owner switches at each RTTI boundary; distinct xref clusters for WaitableTimer, WeatherLayerPane, RainingLayerPane, SnowingLayerPane, SwallowLayerPane, and Swallow resource strings; successor `WorldMapPane` begins exactly at `0x006313fc`.
- Evidence against: none for container classification. The only reason this range exists is physical adjacency in `.rdata`.
- Decision: accepted and applied. The aggregate remains parent blank, `RECONSTRUCTABLE:FALSE`, and non-emitting.

### 2. Exact child assignment to direct class parents

- Evidence for: each exact child has clear class-specific RTTI/vtable/string evidence; current direct class parents now clear the `85/85` gate; live autogen metadata and coverage show assigned state.
- Evidence against: no contradiction in live files. Final C++ is still blank because these vtable/resource pages are source-declared/generated-binary or source literals, not final standalone code bodies.
- Decision: accepted and live. Children are assigned to direct class parents.

### 3. Attach aggregate to `WeatherLayerPane` / weather family

- Evidence for: most of the range, `0x0063118c-0x006313fc`, is weather-family data.
- Evidence against: `0x00631184-0x0063118c` is definitively `WaitableTimer`; weather family does not own the full span.
- Decision: rejected for the aggregate.

### 4. Attach aggregate to `WaitableTimer`

- Evidence for: the range begins with `WaitableTimer` RTTI/vtable data.
- Evidence against: only the first 8 bytes belong to `WaitableTimer`; the rest is weather-layer data/resources.
- Decision: rejected for the aggregate.

## Proposed New File / Grouping

- Proposed owner/name/path: no new owner required.
- Likely full contents: existing `util/WaitableTimer.cpp` and `map/*WeatherLayerPane.cpp` family remain the correct candidate source roots.
- Candidate related items that belong:
  - [UID:0002P2] belongs under [UID:0000FY] `WaitableTimer`.
  - [UID:0002Z7] belongs under [UID:0000G1] `WeatherLayerPane`.
  - [UID:0002Z8] belongs under [UID:0000BJ] `RainingLayerPane`.
  - [UID:0002Z9] belongs under [UID:0000DC] `SnowingLayerPane`.
  - [UID:0002ZA] and [UID:0002ZB] belong under [UID:0000E9] `SwallowLayerPane`.
- Standalone, narrow, or broad source-file inference: the current broad `.rdata` range is not a source file; it is an address-range inventory.

## Negative Evidence Summary

- Address adjacency alone does not prove same source owner.
- The aggregate crosses an observed source-family boundary at `0x0063118c`.
- `WorldMapPane` begins at `0x006313fc`, so the old `0x00631400` end boundary was stale and is not reintroduced.
- Consumer/read xrefs to vtable slots prove class identity for exact children, not aggregate ownership.
- Direct class-parent assignment is now valid for children only; it does not make the mixed aggregate assignable.

## Final Recommendation

- Exact changes applied:
  - [UID:000270] changed from `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`.
  - [UID:000270] remains parent blank and non-emitting.
  - Manual coverage now lists [UID:000270] as `not_reconstructable` and nests all six exact child rows.
  - Exact children are assigned to direct class parents after parent-gate repair: [UID:0002P2] -> [UID:0000FY], [UID:0002Z7] -> [UID:0000G1], [UID:0002Z8] -> [UID:0000BJ], [UID:0002Z9] -> [UID:0000DC], [UID:0002ZA]/[UID:0002ZB] -> [UID:0000E9].
- Exact parent assignments applied:
  - Aggregate [UID:000270]: none.
  - Children: all six assigned to direct class parents as listed above.
- Exact items left unassigned and why:
  - None inside this target range.
- Exact future work outside this assignment:
  - Continue improving final source/file split quality for the weather family before adding final C++ snippets, but that no longer blocks these vtable/resource child assignments.

## Follow-Up Actions

- Supervisor actions: review and move this report to `research/executed` if accepted.
- A-agent actions: none required for B001-037 ownership state. Future work can continue improving final C++ and parent source-file detail.
- B001 future research actions: none for `000270` unless a new stale boundary or ownership contradiction is reported.

## Confidence

- Recommendation confidence: high.
- Score confidence: target `90/93` remains justified for a container-level audit; exact children clear their own scores and direct parent gates.
- Remaining uncertainty: final one-file versus split-file implementation inside the weather family and final-source C++ quality; not a blocker for current child assignment.

## Validator Results

- Commands run during the original execution:
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "by-memory\0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md" --apply`
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "by-memory\-coverage-report.md" --apply`
- Original execution results:
  - Target file apply: `ok: 1`; `autogen_registry_update 000270 ... true -> false`; generated memory coverage reports [UID:000270] as `not_reconstructable`.
  - Coverage file apply: `ok: 1`; no UID/reference errors reported.
- Current live verification before this report correction:
  - Child headers and `auto-generated/-ag-memory-coverage.md` show all six exact children assigned to direct class parents.
  - Manual `by-memory/-coverage-report.md` also shows assigned child rows and parent-gate-cleared class scores.
- Supervisor post-correction targeted validator checks:
  - `by-memory\0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md`: exit `0`, `ok: 1`.
  - `by-memory\0x00631184-0x0063118c.WaitableTimerVtableData.md`: exit `0`, `ok: 1`.
  - `by-memory\0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md`: exit `0`, `ok: 1`.
  - `by-memory\0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`: exit `0`, `ok: 1`.
  - `by-memory\0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`: exit `0`, `ok: 1`.
  - `by-memory\0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md`: exit `0`, `ok: 1`.
  - `by-memory\0x006313cc-0x006313fc.SwallowLayerResourceStrings.md`: exit `0`, `ok: 1`.
  - `by-class\WaitableTimer.md`: exit `0`, `ok: 1`.
  - `by-class\WeatherLayerPane.md`: exit `0`, `ok: 1`.
  - `by-class\RainingLayerPane.md`: exit `0`, `ok: 1`.
  - `by-class\SnowingLayerPane.md`: exit `0`, `ok: 1`.
  - `by-class\SwallowLayerPane.md`: exit `0`, `ok: 1`.
  - `by-memory\-coverage-report.md`: exit `0`, `ok: 1`.
- Unrelated generated churn:
  - The targeted dry-runs only reported `stats_incremental_skip` rows for `project-level/-auto-completion-stats.md`; no target-specific validator failures or stale references were reported.

## Changed Files

- Modified during original execution:
  - `by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md`
  - `by-memory/-coverage-report.md`
  - `tools/leaser/Agents/Agent-B001/research/000270-WaitableWeatherReadOnlyData.md`
- Modified during this supervisor-correction pass:
  - `tools/leaser/Agents/Agent-B001/research/000270-WaitableWeatherReadOnlyData.md`
- Validator-generated side effects observed:
  - `auto-generated/-ag-memory-coverage.md` reports [UID:000270] as `not_reconstructable`.
  - `auto-generated/-ag-memory-coverage.md` reports [UID:0002P2], [UID:0002Z7], [UID:0002Z8], [UID:0002Z9], [UID:0002ZA], and [UID:0002ZB] as `assigned`.
- Created: none.
- Renamed: none.
- Moved to executed:
  - `tools/leaser/Agents/Agent-B001/research/executed/000270-WaitableWeatherReadOnlyData.md`
