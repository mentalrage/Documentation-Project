*** UID:0001UO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FpsPane layout is emitted by UID00005F FpsPane class declaration; this support page emits no duplicate type.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FpsPane Layout

## Status

- Entity kind: diagnostic pane layout.
- Covered class: [UID:00005F][FpsPane](by-class/FpsPane.md).
- Likely owner source: [UID:0000JK][FpsPane](by-file/FpsPane.md).
- Confidence: strong for normalized offsets below; medium for final source-facing field names and exact allocation size.
- Owner/emitter route: attached to [UID:00005F][FpsPane](by-class/FpsPane.md); the class scores `87/88` and this layout scores `88/90`, so both sides satisfy the current `85/85` parent/support gate.

## Layout Notes

`FpsPane` has three vtable views: primary at `+0x00`, secondary EventHandler view at `+0xa0`, and TimerHandler view at `+0xa4`. `FpsPane::OnTimer` at `0x004b68b0` receives the TimerHandler subobject, so raw offsets are `0xa4` bytes lower than owner offsets. The table normalizes every field to the complete `FpsPane` object.

| Owner offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | primary vtable | Raw constructor, non-deleting destructor, and scalar deleting destructor write `0x0061a620`. |
| `+0xa0` | `4` | secondary pane vtable view | Same lifecycle bodies write `0x0061a66c`; destructor thunk at `0x004b6c2b` subtracts `0xa0`. |
| `+0xa4` | `4` | timer/update vtable view | Same lifecycle bodies write `0x0061a69c`; slot `+0x04` points to `0x004b68b0`; destructor thunk at `0x004b6c36` subtracts `0xa4`. |
| `+0xf5` | `1` | inherited `m_hasPendingMotionRegion` | Raw constructor writes `1`; Pane layout and layer behavior support this inherited state rather than a standalone FpsPane visibility member. |
| `+0xf8` | `4` | `m_frameCount` / Singleton empty-base position | `OnPaint` increments it; `UpdateFpsLogSession` resets it; `OnTimer` reads/clears it through subobject offset `+0x54`; RTTI gives Singleton direct-base PMD `+0xf8`. |
| `+0xfc` | `4` | `m_reservedFrameState` | No file-owned code reads or writes this slot. It preserves exact layout without inventing semantics and is not constructor-initialized. |
| `+0x100` | `4` | `m_currentFps` | Raw constructor clears it; `OnPaint` reads it; `OnTimer` writes it through subobject offset `+0x5c`. |
| `+0x104` | `0x32` | `m_logFileName` | Logging paths pass this buffer to `_fopen_s` and format `FPSDATA-%d-%d-%d-%d-%d.txt` into it with size `0x32`. |
| `+0x136` | `0x10` | `m_logStartTime` / `SYSTEMTIME` | Logging start paths call `GetLocalTime(this + 0x136)` and read month/day/hour/minute/second fields for the filename/start line; year is not read for the filename. |
| `+0x148` | `4` | `m_logStartTick` | Start paths store `timeGetTime`; summary path subtracts this from the current tick and divides by `1000` for elapsed seconds. |
| `+0x14c` | `4` | `m_minFps` | Start paths initialize to `300.0f`; `OnTimer` updates through offset `+0xa8`; summary writes `minFPS`. |
| `+0x150` | `4` | `m_maxFps` | Start paths initialize to `0.0f`; `OnTimer` updates through offset `+0xac`; summary writes `maxFPS`. |
| `+0x154` | `4` | `m_sampleCount` | Start paths initialize to `1`; `OnTimer` increments through offset `+0xb0`; summary divides totals by it. |
| `+0x158` | `8` | `m_totalFps` | Start paths zero it; `OnTimer` accumulates through offset `+0xb4`; summary divides by sample count. |
| `+0x160` | `4` | `m_totalLivingObjects` | `OnTimer` accumulates front-row counts through offset `+0xbc`; summary computes the average. |
| `+0x164` | `4` | `m_totalBalloonObjects` | `OnTimer` accumulates visible-list count through offset `+0xc0`; summary computes the average. |
| `+0x168` | `4` | `m_totalStaticObjects` | `OnTimer` accumulates back-row counts through offset `+0xc4`; summary computes the average. |

The accepted complete object size is exactly `0x170`, corroborated by scalar-deleting-destructor allocation size and the formal class size assertion.

## OnPaint Field Evidence

B005's 2026-06-19 [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) implementation strengthens the first two diagnostics fields:

- `m_frameCount` at owner `+0xf8` is incremented directly by `FpsPane::OnPaint` at `0x004b67e6`, then sampled and reset by [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) through timer-facet offset `+0x54`. This rejects elapsed-time or timer-id interpretations for the field.
- `m_currentFps` at owner `+0x100` is read by `FpsPane::OnPaint` with `movss` at `0x004b67db`, promoted to `double`, formatted with UTF-16 `L"%5.1f FPS"`, and drawn by two `DrawWideText` passes. [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) writes the same field through timer-facet offset `+0x5c`. This rejects average/min/max interpretations for `+0x100`; those statistics live at `+0x14c` onward.

The same B005 pass confirms the exact paint range `0x004b67b0-0x004b68ab`, vtable-only dispatch at `0x0061a664`, and the source pair with `UpdateStatistics`. The paint method does not introduce additional FpsPane fields beyond `+0xf8` and `+0x100`; its other helpers are StringBase, inherited bounds, GrafPort, and SurfaceRenderCallbackTable dependencies.

## UpdateStatistics Field Evidence

B005's 2026-06-20 implementation and the 2026-06-22 B013 root-report verification for [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) strengthen the timer-facet normalization and statistics fields:

- The binary receiver is the timer/update facet at `FpsPane +0xa4`. Its raw `+0x54`, `+0x5c`, `+0xa8`, `+0xac`, `+0xb0`, `+0xb4`, `+0xbc`, `+0xc0`, and `+0xc4` offsets normalize to owner `+0xf8`, `+0x100`, `+0x14c`, `+0x150`, `+0x154`, `+0x158`, `+0x160`, `+0x164`, and `+0x168`.
- `m_frameCount +0xf8` is sampled and reset once per timer callback, confirming it is not an elapsed-time field or timer id.
- `m_currentFps +0x100` is written from the current one-second sample, confirming it is the displayed current FPS rather than average/min/max state.
- `m_minFps +0x14c`, `m_maxFps +0x150`, `m_sampleCount +0x154`, and `m_totalFps +0x158` are updated directly by the callback; summary helpers later read these values for `minFPS`, `maxFPS`, and average FPS output.
- `m_totalLivingObjects +0x160`, `m_totalBalloonObjects +0x164`, and `m_totalStaticObjects +0x168` store running totals, not precomputed averages. [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) adds front-row bucket counts to `+0x160`, visible-object-list counts to `+0x164`, and back-row bucket counts to `+0x168`; [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) computes averages later by dividing by `m_sampleCount`.
- `g_activeMapPane`, `MapPane::GetClampedVisibleTileBounds`, `MapPane +0x424 m_objectList`, ObjectList front/back/visible count helpers, and `TimerHandler::ScheduleTimer(0,1000,0,0)` are dependencies for collecting and scheduling diagnostics; none of them transfer ownership of these fields away from `FpsPane`.

The exact original `MapRect` spelling, ObjectList row-tier method names, and TimerHandler wrapper name are still descriptive/inferred, but the field offsets and accumulator semantics are address-backed by this method.

## Generated-Data Caveat

Current `source-3/simroot_v2/class_FpsPane.meta_wave3` reports only `Pane`, synthetic undefined bytes, `+0xf8`, and `+0x100` fields, and still reports `vtable_count: 0`. That generated layout is incomplete for source reconstruction because the FPS logging session fields at `+0x104` through `+0x168` are proven by IDA disassembly. Use this page as the layout anchor until Wave3 metadata is repaired.

## 2026-06-16 Source-Quality Recheck

Live IDA MCP session `b001_0001KM_20260616` reconfirmed the layout and the source-quality blockers:

- `lookup_funcs` still reports no function object at raw starts `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0`; modeled bodies remain `0x004b6470` size `0x29`, `0x004b67b0` size `0xfb`, `0x004b68b0` size `0x100`, `0x004b6c2b` size `0xb`, `0x004b6c36` size `0xb`, and `0x004b6c50` size `0x5f`.
- `xref_query` to `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` returned zero cross-references. That keeps the raw constructor/session/start/summary bodies documented as real code-shaped ranges but not safe to promote into final emitted methods from this layout page.
- `insn_query` over `0x004b6410-0x004b6470` shows the raw constructor prologue, `g_pFpsPane` store, three vtable stores at `+0x00/+0xa0/+0xa4`, visible byte write at `+0xf5`, and state setup at `+0xf8/+0x100`.
- `insn_query` over `0x004b64a0-0x004b67a8`, renamed [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md), and `0x004b6ae0-0x004b6c2b` reconfirmed the logging-session fields: `+0x148` start tick, `+0x14c/+0x150` min/max floats, `+0x154` sample count, `+0x158` double sum, `+0x160/+0x164/+0x168` object-count accumulators, and `+0x104` filename use for `_fopen_s`.
- `type_query` and `search_structs` for `FpsPane` found no local preserved NexusTK UDT. Final field names therefore cannot be recovered from IDA type metadata.
- `source-3/simroot_v2/class_FpsPane.cpp` was checked as generated-source evidence. It offers plausible names such as `m_minFPS`, `m_maxFPS`, `m_frameCount`, `m_totalFPS`, `m_avgLivingObjects`, `m_avgBalloonObjects`, and `m_avgStaticObjects`, plus a synthetic `FpsPaneStatsLayout`; however, the file is marked incomplete, contains raw-start/generated-placeholder penalties, and uses synthetic reserved overlays. Use those names as leads, not final declaration authority.

The existing owner/emitter route to [UID:00005F][FpsPane](by-class/FpsPane.md) remains correct and surfaces to `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`. Layout C++ remains blank because this page is the field-layout support document; eligible child method/global pages now carry first-draft source.

## 2026-06-17 B003 Source-Quality Update

B003's pass resolves the highest-confidence source-facing names for the FpsPane diagnostic fields and corrects two stale layout interpretations:

- `+0x160`, `+0x164`, and `+0x168` store totals, not averages. The summary helper computes averages at write time by dividing each total by `m_sampleCount`.
- The filename/start-line timestamp uses month/day/hour/minute/second. Year-based interpretations are rejected because the assembly does not read `wYear` for the `FPSDATA-%d-%d-%d-%d-%d.txt` arguments.
- `g_fpsLogEnabled` is exact one-byte loader-zero source storage. Original-PE mapping now supersedes the export-only caveat: VA `0x0069b338` lies at `.data` delta `0x0002e338`, beyond the section's `0x0000d800` raw payload, so no stored `0xff` initializer exists. The older `byte_69B338 db ?` export remains compatible historical evidence but is not the controlling proof.
- `g_fpsDebugActive` remains an explicit initialized dword `1`, best described as a pending debug/log-session start flag.
- Raw helper liveness remains the final-audit cap, but method pages now enter first-draft C++ where they clear the active owner/emitter and score gate.
- B002's 2026-06-23 MCP session `80de0a67` refresh keeps the same layout conclusions for renamed [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md): the 70-instruction body resets `+0x148` through `+0x168`, uses `+0x104` / `+0x136` for filename and timestamp storage, and has no route/literal-pointer proof to the exact raw entry. The layout evidence is positive even though liveness remains capped.

## g_fpsLogEnabled Backing And Source Interpretation

- Original input `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe` is PE32 x86 with image base `0x00400000`. The target VA/RVA is `0x0069b338` / `0x0029b338` in writable `.data` at section VA `0x0066d000`, virtual size `0x0002fe24`, raw size `0x0000d800`, raw pointer `0x0026ac00`, and characteristics `0xc0000040`.
- The target is outside the raw payload and dated bounded MCP reads return zero. The following bytes `0x0069b339-0x0069b33c` are also unbacked zero bytes with no xrefs, so they are separate loader-zero padding rather than an initializer extension.
- Exact reads occur at `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`. Each is `cmp byte ptr ...,0`; the target has no store xref, pointer route, generated/source assignment, FPS config/UI/input key, or normal setter.
- `bool` is the resolved human-source type because the exact storage is one byte and every use is a truth test. Byte/character types are semantically weaker, `BOOL`/`int` conflict with the boundary, and a bitfield conflicts with direct standalone addressing.
- The source declaration is `bool g_fpsLogEnabled;` without an explicit initializer, emitted once by [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) through [UID:0000JK][FpsPane](by-file/FpsPane.md). The exact storage child [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md) emits only a covered-by comment; this layout page gains no global source payload.
- The best behavior is a compiled-in, default-off developer diagnostics gate. Reconstructed code must not invent a writer or explicit initializer. Exact original symbol/linkage spelling remains inferred, but raw `unk_69B338`/`byte_69B338` labels are evidence aliases rather than final source names.
- The historical `0xff` view and saved-rename claim are retained as disproved/stale IDB observations on the target/global pages. They do not alter this layout page's `88/90` score, owner/emitter route, or blank formal CPP/H.

## Evidence

- Raw constructor bytes at `0x004b6410-0x004b646b` install all three vtables, set byte `+0xf5`, and clear `+0x100`.
- `OnPaint` at `0x004b67b0` increments `+0xf8` and reads `+0x100` for the displayed FPS text.
- `UpdateStatistics` at `0x004b68b0` is a timer/update-view method. Its decompiler offsets normalize by adding `0xa4`, matching `+0xf8`, `+0x100`, and the logging-session totals.
- `UpdateFpsLogSession` at `0x004b64a0` and raw helpers at `0x004b69b0` / `0x004b6ae0` use owner-relative fields `+0x104` through `+0x168`.
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md) records `0x0061a69c + 0x04 -> 0x004b68b0` and the adjustor thunks that prove the `+0xa4` subobject view.
- 2026-05-31 IDA MCP `lookup_funcs` confirms `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` are still not modeled as functions, while `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50` are modeled functions with sizes `0x29`, `0xfb`, `0x100`, `0xb`, `0xb`, and `0x5f`.
- 2026-05-31 IDA MCP xrefs confirm the three vtable constants are written by the raw constructor (`0x004b643b`, `0x004b6441`, `0x004b644b`), ordinary destructor (`0x004b6470`, `0x004b6476`, `0x004b6480`), and scalar deleting destructor (`0x004b6c56`, `0x004b6c5c`, `0x004b6c66`).
- 2026-05-31 IDA MCP xrefs confirm [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) is written at `0x004b6434`, `0x004b648a`, and `0x004b6c70`; [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) is used at `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`; [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) is used at `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`.
- 2026-06-13 A001 IDA MCP refresh reconfirmed the `UpdateFpsLogSession` owner-offset users: `0x004b64a0-0x004b67a7` writes/resets `+0x148` through `+0x168`, builds the filename at `+0x104`, calls `GetLocalTime(this + 0x136)`, resets `+0xf8`, schedules the timer/update view at `this + 0xa4`, reads the same statistics fields for summary output, and removes that timer/update view on finalize. The same pass reconfirmed no modeled function/caller for the raw start, which affects method liveness but not the field-offset evidence.

## Score Rationale

- Completion is `88` because the page now records the three-vtable layout, normalized owner-relative offsets, raw constructor/session/start/summary disassembly, modeled paint/statistics consumers, B003's best source-facing field names, totals-versus-averages correction, timestamp ordering, and global initializer semantics.
- Confidence is `90` because IDA disassembly, decompilation, and B003's local listing review independently corroborate the offset map and timer-subobject normalization. Confidence remains below final audit because the raw logging bodies have zero xrefs in the current IDB and the field names are descriptive rather than recovered source declarations.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md)
- [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)

## 2026-08-24 Accepted Layout Closure

- Direct bases are `Pane` and empty `Singleton<FpsPane>`; RTTI places the Singleton direct base at PMD `+0xf8`. `Pane` supplies EventHandler and TimerHandler views at owner `+0xa0/+0xa4`.
- Raw constructor writes no bytes at `+0xf8/+0xfc`; `m_frameCount` becomes defined when a logging session starts, and `m_reservedFrameState` has no discovered behavior. This preserves byte-equivalent initialization rather than adding cosmetic zeroing.
- Lifecycle stores at constructor, ordinary destructor, and scalar wrapper independently confirm primary/secondary/tertiary vptr positions. Adjustors subtract exactly `0xa0` and `0xa4` before reaching the scalar wrapper.
- Formal type ownership is UID00005F H. This page emits only the exact class-covered CPP comment above and keeps H blank to avoid duplicate type declarations.
- Metadata remains owner/emitter `00005F`, reconstructable `TRUE`; score is `94/96`.

## Changes

- 2026-08-04 B009 `g_fpsLogEnabled` backing support correction:
  - Score and metadata remain `88/90`, owner/emitter UID00005F, reconstructable true, and blank formal CPP/H.
  - Replaced the export-only `db ?` / possible-`0xff` caveat with exact original-PE loader-zero proof, four read-only use sites, no-writer/config closure, resolved `bool` interpretation, and one-definition source placement.
  - Retained the old export/`0xff`/saved-rename conclusions as compatible, disproved, or stale historical evidence rather than deleting them.

- 2026-06-23 B002 StartLogSession layout support sync:
  - Score unchanged.
  - Updated [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) links to [0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) and recorded that MCP session `80de0a67` preserves the same field-layout evidence for `+0x104`, `+0x136`, and `+0x148` through `+0x168` while keeping the raw helper route/liveness as a confidence cap.

- 2026-06-22 B013 UpdateStatistics root-report verification:
  - Score unchanged.
  - Confirmed the field-layout support for [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md): receiver normalization from `FpsPane +0xa4`, frame/current/min/max/sample/total FPS offsets, object-count total offsets, and MapPane/ObjectList/TimerHandler dependency roles remain address-backed. Final original helper/type names remain confidence caps rather than code-entry blockers.

- 2026-06-20 B005 UpdateStatistics layout support update:
  - Score unchanged.
  - Added direct [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) evidence for timer-facet normalization, `m_frameCount +0xf8`, `m_currentFps +0x100`, min/max/sample/total FPS fields, object-count total fields at `+0x160/+0x164/+0x168`, totals-versus-averages semantics, and dependency-only roles for MapPane/ObjectList/TimerHandler.

- 2026-06-19 B005 OnPaint layout support update:
  - Score unchanged.
  - Added direct OnPaint evidence for `m_frameCount +0xf8` and `m_currentFps +0x100`, including the producer/consumer relationship with `UpdateStatistics`, rejection of stale field interpretations, and confirmation that no additional FpsPane fields are introduced by the paint body.

- 2026-06-17 B003 source-quality execution:
  - Before: `86/89`, with generated-source names listed as leads and the object-count fields still described partly as average-style counters.
  - Changed to: `88/90`; standardized field names to `m_frameCount`, `m_currentFps`, `m_logFileName`, `m_logStartTime`, `m_logStartTick`, `m_minFps`, `m_maxFps`, `m_sampleCount`, `m_totalFps`, `m_totalLivingObjects`, `m_totalBalloonObjects`, and `m_totalStaticObjects`.
  - Incorporated B003 report details: totals-versus-averages correction, month/day/hour/minute/second timestamp ordering, `g_fpsLogEnabled` as zero-initialized `db ?`, `g_fpsDebugActive` as explicit `dd 1`, and raw-helper liveness as a score cap rather than a first-draft C++ blocker.

- 2026-06-13 A001 support-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, and a stale status note saying the class parent was `82/80`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; refreshed the parent/support gate note to [UID:00005F][FpsPane](by-class/FpsPane.md) at `85/86`.
  - Summary/evidence: live IDA MCP rechecked the `0x004b64a0-0x004b67a7` raw session body and reconfirmed owner offsets `+0xf8`, `+0x104`, `+0x136`, and `+0x148` through `+0x168`, plus timer/update subobject use at `+0xa4`. Confidence remains below final-audit because raw helper liveness and final field names remain open.
- 2026-06-16 A002 source-quality pass:
  - Before: `85/88`.
  - After: `86/89`.
  - Summary/evidence: live IDA MCP session `b001_0001KM_20260616` reconfirmed modeled and raw boundaries, zero xrefs to raw starts, raw disassembly for constructor/session/start/summary fields, no preserved `FpsPane` UDT, and generated `class_FpsPane.cpp` synthetic field-name leads. The by-struct coverage row was also stale at `82%` and was synced to the refreshed page score.
- 2026-06-06: Attached layout to [UID:00005F][FpsPane](by-class/FpsPane.md) as its autogen parent. Scores were left at `82/88`; this is a metadata cleanup only because the documented three-vtable diagnostic pane layout already matched the class page's validated `82/80` parent gate.
- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `82/88`.
  - Summary/evidence: IDA MCP reconfirmed modeled and unmodeled FpsPane function boundaries, vtable writes, global xrefs, destructor/scalar destructor vtable restoration, `OnPaint` use of `+0xf8/+0x100`, and `UpdateStatistics` timer-view offsets that normalize by `+0xa4`. Scores remain below near-final because raw start ownership, final private field names, exact allocation size, and final source folder are still open.
