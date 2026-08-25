*** UID:0000JK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/diagnostics/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FpsPane

## UID00029O Incidental IME-Layer Reuse - 2026-07-21

`FpsPane.cpp` retains the complete diagnostics source inventory. `UpdateFpsLogSession` consumes `g_pIMEPaneLayer` once as a frame parent when starting a visible session, without owning or defining that global. Logging gates, timestamps, CP949 strings, timer behavior, helper calls, globals, raw liveness caveat, generated order, and all unrelated evidence remain unchanged.

## Status

- Proposed module: `ui/diagnostics/FpsPane.cpp`
- Proposed header: `ui/diagnostics/FpsPane.h`
- Confidence: very strong for the separate diagnostic module, FPS global ownership, and `g_fpsLogEnabled` source/storage route; lower than final-audit for unrelated raw-helper liveness and exact historical folder provenance.
- Current generated source: `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`
- Related generated-data caveat: historical `class_FpsPane.cpp`, `class_ParcelPane.meta_wave3`, and ParcelPane global-data rows still appear as stale source-placement leads, but current accepted output is the diagnostics FpsPane module.
- Type docs: [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md), [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md)

## g_fpsLogEnabled Source Route And Storage Closure

- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) is the sole semantic definition page and emits exactly `bool g_fpsLogEnabled;` through this file. Its H channel stays blank because all observed consumers are in this translation unit.
- [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md) is the exact one-byte physical-storage child. It emits only a formal covered-by comment and must not duplicate the variable definition.
- The original PE is PE32 x86 with image base `0x00400000`. Target VA/RVA `0x0069b338` / `0x0029b338` lies in writable `.data` at section VA `0x0066d000`, virtual size `0x0002fe24`, raw size `0x0000d800`, and raw pointer `0x0026ac00`. The target delta `0x0002e338` is outside the raw payload, so loader zero fill, not a stored `0xff`, supplies the default-off byte.
- Exact uses are four reads: `0x004b653f` gates new log-file creation, `0x004b6645` gates final summary output, `0x004b6a17` gates the retained start-log helper, and `0x004b6ae4` implements the retained summary helper's early disabled return. Each instruction is `cmp byte ptr ...,0`; none writes the byte.
- Exact xrefs/data-flow, VA/RVA/pointer searches, current documentation/generated source, and FPS config/UI/input/string searches found no writer or normal toggle route. The most plausible source role is a compiled-in, default-off developer diagnostics gate; do not invent a setter.
- `bool` is selected over byte/character, four-byte `BOOL`/`int`, and bitfield alternatives because the exact storage is one byte and every use is a direct truth test. `g_fpsLogEnabled` is the best human source name and follows `g_pFpsPane` / `g_fpsDebugActive`; raw `unk_69B338` and `byte_69B338` spellings remain evidence aliases only.
- File-local `static` linkage is plausible because all consumers are local, but surviving evidence does not prove that spelling. Retain the established `bool g_fpsLogEnabled;` form rather than inventing a linkage change.
- The predecessor `g_pFpsPane` slot ends at `0x0069b338` and has three lifecycle refs. The three successor bytes `[0x0069b339,0x0069b33c)` are unreferenced loader-zero padding; `FramePartPaneSlots` begins at `0x0069b33c` with four positive-control refs. These distributions confirm the one-byte child boundary.
- Historical local-export `db ?`, `0xff`, saved-rename, ParcelPane ownership, and `class_ParcelPane.cpp` conclusions remain useful chronology but are not current source/storage authority. Exact PE mapping disproves stored `0xff`; dated fresh IDA inspection found no stored source-quality symbol, and a validation-only dry run resolved only synthetic `unk_69B338` without applying a rename.

## File Role

`FpsPane.cpp` likely owned the in-client performance overlay. It displays FPS, schedules a one-second update callback, records FPS min/max/average values, optionally writes `FPSDATA-*.txt` logs, and samples live map object counts through `MapPane` / `ObjectList`.

Keep this separate from [UID:0000MF][ParcelPane](by-file/ParcelPane.md) and [UID:0000M4][ObjectList](by-file/ObjectList.md):

- It is not parcel UI; the `0x004b64a0` body is FPS logging/session code. Current generated source places it in `NexusTK/ui/diagnostics/FpsPane.cpp`, while stale ParcelPane metadata still references it.
- It is not a map object-index class; it reads map object counts only for diagnostics.

## Proposed Contents

| Entity | Current range | Current generated owner | Proposed ownership |
| --- | --- | --- | --- |
| [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) | `0x004b6410-0x004b6caf` | previously an empty aggregate marker in `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` | reviewed non-emitting split/index parent only; exact child rows below carry source C++ or compiler-glue no-code policy. |
| [UID:00005F][FpsPane](by-class/FpsPane.md) constructor/raw setup | `0x004b6410-0x004b646b` | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`; not an IDA function | `FpsPane.cpp`; first-draft `FpsPane::FpsPane()` now lives on the child page. |
| [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) | `0x004b6470-0x004b6499` | IDA function; exact authored C++ is populated on the child page | `FpsPane.cpp`; authored `FpsPane::~FpsPane()` is empty. The Singleton base specialization clears `g_pFpsPane`; three vtable-view restores and the `Pane::~Pane()` tail chain are compiler/base output. |
| `UpdateFpsLogSession` | `0x004b64a0-0x004b67a7` | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`; stale ParcelPane metadata/global-data references are historical leads | `FpsPane.cpp`; target [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) is `94/95`. Exact source uses `RectBounds::SetLTRB`, `IsAttachedToLayer`, `AddToLayer`/`RemoveFromLayer`, inherited `ScheduleTimer`/`RemovePendingTimers`, retained helpers, and independent `g_pIMEPaneLayer`. |
| [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) | `0x004b67b0-0x004b68ab` | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`; previously blank formal C++ | `FpsPane.cpp`; B005 populated first-draft `void FpsPane::OnPaint()` with frame-count increment, UTF-16 `L"%5.1f FPS"` formatting, bounds fill/clear, and two counted text passes. |
| [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) | `0x004b68b0-0x004b69b0` | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`; exact C++ is populated on the exact child page | `FpsPane.cpp`; source-bearing `bool FpsPane::OnTimer(int, int, int)` override. `UpdateStatistics` remains the historical documentation slug. The callback samples the frame count produced by `OnPaint`, updates current/min/max/sample/total FPS and object-count totals, then calls inherited `ScheduleTimer(0, 1000, 0, 0)`. |
| [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) | `0x004b69b0-0x004b6adc` | not emitted as a separate active method; not an IDA function | `FpsPane.cpp` private diagnostics helper or old retained helper implementation; formal `FpsPane::StartLogSession()` C++ lives on the child page, while the exact raw entry still has no proven live route. |
| [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) | `0x004b6ae0-0x004b6c2b` | not emitted as a separate active method; not an IDA function | `FpsPane.cpp` private diagnostics helper or old retained helper implementation; formal `FpsPane::WriteLogSummary()` C++ lives on the child page at `88/89`. B003 session `80de0a67` confirms no raw-start route but also confirms the complete summary writer body, append-mode literal `0x0061a700` `"a"`, and source-shaped `fprintf` output sequence. |
| destructor adjustor thunks | [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) | IDA-confirmed 0xb-byte vtable adjustor thunks; ignored as compiler glue | compiler-generated, not source |
| [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) | `0x004b6c50-0x004b6caf` | IDA/export-confirmed scalar deleting destructor wrapper | compiler-generated vtable/delete support for `FpsPane::~FpsPane()`; comment-only/no-code marker on the exact child page, not a handwritten source method. |
| [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) | `0x0069b334` | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` | Sole module definition `FpsPane *g_pFpsPane = 0;`; `Singleton<FpsPane>` constructor/destructor specializations publish and clear this cell. |
| [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) | `0x0066da90` | generated under `class_ParcelPane.cpp` global-data | `FpsPane.cpp` module global, explicit local IDA export `dd 1`, source declaration `int g_fpsDebugActive = 1;`. |
| [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) | `0x0069b338` | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` | Sole `FpsPane.cpp` module definition `bool g_fpsLogEnabled;`; the one-byte unbacked `.data` virtual-tail storage is loader-zeroed, has four read-only gates, and has no writer/config route. |
| [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md) | `0x0069b334-0x0069b338` | exact global-data slot | Physical `.data` storage for the active FpsPane singleton. |
| [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md) | `0x0069b338-0x0069b339` | exact global-data byte with formal covered-by output | Physical loader-zero storage/evidence child for the FPS log gate; UID0000PZ emits the definition once, while this child records PE mapping/xrefs and emits no duplicate source. |
| [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md) | `0x0061a620`, `0x0061a66c`, `0x0061a69c` | type data | `FpsPane.cpp` / `FpsPane.h` |
| [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) | `0x0061a61c-0x0061a6a4` | exact RTTI/vtable data | compiler-generated from `FpsPane` declarations |

## Evidence

- Wave3 import provenance names `FpsPane.cpp`.
- Current `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` emits `UpdateFpsLogSession` at `0x004b64a0`; older/suspect `source-3/simroot_v2/class_FpsPane.cpp`, ParcelPane metadata, and global-data rows remain historical leads only.
- B008's 2026-06-25 MCP session `80de0a67` refresh raises [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) to `89/89` while keeping this source root. The evidence confirms the 190-instruction raw method body, FpsPane-local field/global/string flow, paired retained helper bodies, target body SHA-256 `5dfaffba35e1013a192cd1c812c0c135b0544b94a515d10f148dfb75c6de596e`, and no function/caller/pointer route to `0x004b64a0` as a liveness cap.
- IDA MCP confirms the non-deleting destructor body at `0x004b6470`, plus `OnPaint`, source-facing `OnTimer` (historical `UpdateStatistics` alias), destructor thunks, and scalar deleting destructor in the compact `0x004b67b0-0x004b6caf` range.
- 2026-05-31 IDA MCP confirms exact FpsPane RTTI/vtable data at [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md), with string data beginning at `0x0061a6a4`.
- Wave3 metadata places `FpsPane::FpsPane` at `0x004b6410-0x004b646a`, but IDA currently leaves the range unmarked.
- IDA raw disassembly confirms additional FpsPane-shaped, callerless helper starts at `0x004b69b0` and `0x004b6ae0`. They operate on the same FPS session/log filename fields and globals but are not emitted as separate active methods. B002's 2026-06-23 MCP session `80de0a67` refresh renames the start helper child to [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md), confirms the complete 70-instruction start helper and duplicate `UpdateFpsLogSession` start path, and keeps no xrefs/literal pointers as the live-route confidence cap.
- B003's 2026-06-23 MCP session `80de0a67` refresh keeps [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) as the matching retained `WriteLogSummary()` child. `lookup_funcs`, `decompile`, `xrefs_to`, and pointer-route scans still find no function, caller, direct xref, VA pattern, RVA pattern, or raw-offset pattern for `0x004b6ae0`; those negatives cap liveness/final-audit confidence. The same pass decodes 84 instructions over the exact `0x14b` byte body, records SHA16 `93961235a91a75d1`, confirms four `0xcc` bytes at `0x004b6adc-0x004b6ae0`, uses the successor thunk pointer at `0x0061a66c` as a positive boundary control, and records the `0x0061a700` `"a"` append-mode string xrefs `0x004b6652` and `0x004b6af4`.
- Current RTTI/vtable analysis confirms the apparent field split between `OnPaint` and `OnTimer` is caused by `OnTimer` using the `TimerHandler` subobject at `+0xa4`; normalized owner offsets are documented in [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md).
- `FpsPane::OnTimer` reads `g_activeMapPane`, visible tile bounds, and ObjectList row-bucket counts, but does not own map/object code.
- 2026-05-26 IDA MCP reconfirmed the thunk pair at `0x004b6c2b` and `0x004b6c36` as vtable-only compiler adjustors into `FpsPane::ScalarDeletingDestructor`; these are now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-07 Batch038 IDA refresh confirms exact FPS `.data` children: [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md) refs at `0x004b6434`, `0x004b648a`, and `0x004b6c70`; [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md) refs at `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`.

## Source-Structure Decision

Use a standalone `FpsPane.cpp` module under `NexusTK/ui/diagnostics/`. B003 rechecked the source-placement alternatives and kept `ui/diagnostics/FpsPane.cpp` as the best current source root: the Wave3 import name is `FpsPane.cpp`, the proposed source tree already places it under diagnostics, and the methods/globals/vtables/strings are all FPS overlay diagnostics.

B006's 2026-07-04 split/index cleanup makes [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) a reviewed non-emitting parent. The file still owns the diagnostics source island, but source output comes from exact children for the constructor, destructor, `UpdateFpsLogSession`, `OnPaint`, `OnTimer`, `StartLogSession`, and `WriteLogSummary`, plus compiler-covered children where appropriate. Do not emit an aggregate UID00015D body or empty marker.

Do not merge this into `ParcelPane.cpp`; stale ParcelPane metadata/global-data placement is generated pollution. Do not merge it into `MapPane.cpp` or `ObjectList.cpp`; those classes are read-only diagnostic data sources for object counts. Do not move it into `MainUiGraph.cpp`; [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) owns the parent/layer slot consumed by `UpdateFpsLogSession`, not the FpsPane class, fields, strings, globals, or vtables.

B005's 2026-06-19 OnPaint implementation adds a concrete code-emission requirement for this file: `NexusTK/ui/diagnostics/FpsPane.cpp` should emit the [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) `FpsPane::OnPaint()` body, not an empty marker. The method is source-placed here because the primary FpsPane vtable slot `0x0061a664` points to `0x004b67b0`, the body uses FpsPane fields `m_frameCount +0xf8` and `m_currentFps +0x100`, and the overlay literal `L"%5.1f FPS"` belongs to the FpsPane diagnostic string run. The method depends on StringBase wide formatting/access/release helpers, inherited Pane bounds copy, GrafPort draw/text cursor/color helpers, and SurfaceRenderCallbackTable slot `0x0069b3fc` as a rectangle fill/clear wrapper. Those dependencies do not transfer ownership out of FpsPane.

The `OnPaint`/`OnTimer` relationship is explicit source shape: `OnPaint` increments the one-second frame counter and displays the last current-FPS sample; `OnTimer` samples/resets that counter through the `TimerHandler` facet at `FpsPane +0xa4`, writes the current FPS value, updates logging statistics, samples MapPane/ObjectList counts, and reschedules the next callback. This confirms `MapPane`, `ObjectList`, `TimerHandler`, and `MainUiGraph` are dependencies, not source owners.

The accepted callback supersedes the earlier `UpdateStatistics` source spelling: `NexusTK/ui/diagnostics/FpsPane.cpp` emits [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) as `bool FpsPane::OnTimer(int, int, int)`. Tertiary slot `0x0061a6a0` points to `0x004b68b0`; the body writes normalized FpsPane fields from `+0xf8` through `+0x168`, and external reads remain diagnostic dependencies. `UpdateStatistics` is retained only as a historical/descriptive alias.

## Lifecycle Notes

B004's destructor pass resolves the FpsPane singleton lifecycle as a direct source pattern in this module:

- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) publishes the active object to [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) at `0x004b6434`.
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) is source-bearing `FpsPane::~FpsPane()` with an empty authored body; the Singleton base specialization owns the pointer clear.
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) mirrors the singleton clear at `0x004b6c70` as compiler-generated scalar deleting destructor/delete support.

B012's local export/listing recheck strengthens the same route. `sub_4B6470` is a `0x29` / 41-byte ordinary destructor body with no direct callers, while `sub_4B6C50` is a `0x5f` / 95-byte scalar deleting wrapper reached by primary vtable slot `0x0061a620` and adjustor-thunk jumps at `0x004b6c31` and `0x004b6c3c`. The wrapper restores the same three vtable views, clears `g_pFpsPane` at `0x004b6c70`, calls the pane-base destructor helper, optionally deletes through `sub_4F4AC0`, and has the guard-check flag-4 path with size `0x170`. Constructor/destructor/scalar-wrapper parity, the shared three-view vtable restores, and the confined `g_pFpsPane` xrefs keep the owner/emitter route in `NexusTK/ui/diagnostics/FpsPane.cpp`. Do not emit vtable writes, explicit `Pane::~Pane()` calls, scalar-delete flags, `_guard_check_icall_nop`, or `sub_4F4AC0` in source-level FpsPane code.

## Draft Declarations

B003 recommends these source-facing global declarations for this module. They are emitted through their by-global pages to avoid duplicate child-memory storage output:

```cpp
FpsPane *g_pFpsPane = 0;
int g_fpsDebugActive = 1;
bool g_fpsLogEnabled;
```

`g_pFpsPane` and `g_fpsLogEnabled` are modeled as zero-initialized static storage. For `g_fpsLogEnabled`, exact original-PE mapping proves that `0x0069b338` lies in the unbacked `.data` virtual tail and is loader-zeroed; the older `byte_69B338 db ?` export is retained only as compatible historical evidence. `g_fpsDebugActive` remains an explicit initialized dword because the local IDA export lists `dword_66DA90 dd 1`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | Complete compilation-unit inventory, exact CPP/H routing, corrected inherited APIs and `OnTimer` identity, all source-bearing bodies, one-definition globals, and compiler/data covered dispositions are implementation-ready. |
| Confidence `96` | Exact bodies, RTTI/vtables, offsets, globals, literals, ranges, and dependencies agree. Missing original symbols, raw-start call routes, unused `+0xfc`, and exact historical folder provenance remain bounded confidence caps. |

## Migration Notes

- Recheck the constructor, session method, and raw helper liveness with another disassembler before final-audit scoring.
- Keep `0x004b64a0-0x004b67a7` in `FpsPane`; B003 rejected ParcelPane, MapPane, ObjectList, MainUiGraph, padding, and compiler-thunk ownership alternatives.
- Treat raw helper starts `0x004b69b0` and `0x004b6ae0` as retained private helpers or old helper implementations duplicated/inlined into `UpdateFpsLogSession`, with no-proven-caller as a liveness score cap. The source-facing `StartLogSession` child now lives at [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md).
- Keep [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) in this source root for the same reason. It consumes FpsPane logging fields, `g_fpsLogEnabled`, FpsPane diagnostic strings, and the same `NexusTK/ui/diagnostics/FpsPane.cpp` output route as `StartLogSession()` and `UpdateFpsLogSession()`. The formal source representation remains on the memory child so this file page records source placement without duplicating method C++.
- Keep `g_pMapPane` external; FpsPane should only include a forward declaration or use an accessor.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md)
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md)
- [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md)
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- `ParcelPane` generated-source ownership caveat in [Wave3 data issues](../wave3_data_issues.md)

## 2026-08-24 Accepted Whole-File Callback

- Canonical source remains `NexusTK/ui/diagnostics/FpsPane.cpp` with required sibling `FpsPane.h`; direct bases are `Pane` and `Singleton<FpsPane>`, object size is `0x170`, and the `TimerHandler` facet is inherited through `Pane` at owner offset `+0xa4`.
- Complete code map: seven authored bodies at `0x004b6410`, `0x004b6470`, `0x004b64a0`, `0x004b67b0`, `0x004b68b0`, `0x004b69b0`, and `0x004b6ae0`; two adjustors at `0x004b6c2b`/`0x004b6c36`; scalar wrapper at `0x004b6c50`; six exact `0xcc` gaps at `0x004b646b-0x004b6470`, `0x004b6499-0x004b64a0`, `0x004b67a7-0x004b67b0`, `0x004b68ab-0x004b68b0`, `0x004b6adc-0x004b6ae0`, and `0x004b6c41-0x004b6c50`.
- Complete non-code inventory: three semantic globals plus three physical children, 34 vtable-region dwords, 12 RTTI records, and 15 exact diagnostic literals. Vtables/RTTI are compiler-generated from the class declaration; literals are emitted by method expressions; physical global pages emit covered-storage comments rather than duplicate definitions.
- Source order is includes, Singleton specializations, constructor, destructor, `UpdateFpsLogSession`, `OnPaint`, `OnTimer`, retained private start helper, retained private summary helper, and the three semantic global definitions. No raw `sub_`, `dword_`, `unk_`, explicit vtable write, adjustor, scalar wrapper, raw table, or invented logging setter belongs in handwritten source.
- Raw constructor/controller/start/summary entries have exhaustive zero inbound xref and pointer-route results. They remain retained source-shaped methods without a false live-reachability claim. ParcelPane placement is historical pollution; MapPane, ObjectList, TimerHandler, GrafPort, StringBase, and MainUiGraph are dependencies only.
- Final current score is `94/96`; owner `FILE` and path `NexusTK/ui/diagnostics/` are unchanged.

## Changes

- 2026-08-04 B009 accepted `g_fpsLogEnabled` source-route implementation:
  - Raised `88/87` to `89/90` after closing the exact loader-zero storage and sole-definition/covered-by source route.
  - Corrected the global inventory from stale `class_ParcelPane.cpp` / export-only wording to `NexusTK/ui/diagnostics/FpsPane.cpp`, exact PE virtual-tail proof, four read-only gates, and no-writer/config closure.
  - Retained all unrelated diagnostics evidence and historical ParcelPane/`db ?`/`0xff`/saved-rename assumptions as historical rather than deleting them.

- 2026-07-04 B006 UID00015D split/index support sync:
  - Score unchanged.
  - Updated current generated-source context from stale `class_FpsPane.cpp` wording to `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`.
  - Added [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) as a reviewed non-emitting split/index parent. Exact child pages remain the source-output carriers; aggregate UID00015D C++ and empty-marker output are rejected.

- 2026-06-25 B008 UpdateFpsLogSession placement refresh:
  - Score unchanged.
  - Recorded [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) as `89/89` after current MCP session `80de0a67`. The accepted source root remains `NexusTK/ui/diagnostics/FpsPane.cpp`; the no-function/no-caller/no-pointer state remains a liveness cap, not a reason to move the method to ParcelPane, MapPane, ObjectList, or MainUiGraph.

- 2026-06-23 B003 WriteLogSummary source-quality support sync:
  - Score unchanged.
  - Updated the proposed contents and source-structure notes for [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md). The file page now records that `NexusTK/ui/diagnostics/FpsPane.cpp` emits the retained `FpsPane::WriteLogSummary()` child, while MCP session `80de0a67` keeps no-function/no-xref/no-pointer-route status as a liveness cap. The update preserves B002's renamed [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) `StartLogSession` links and rejects stale ParcelPane, MapPane, ObjectList, MainUiGraph, direct file-owner/free-helper, and no-owner alternatives for the summary body.

- 2026-06-23 B002 StartLogSession source-quality support sync:
  - Score unchanged.
  - Updated the proposed contents row and cross-reference to the renamed [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md). The file page now states that formal `FpsPane::StartLogSession()` C++ lives on the child page, and that MCP session `80de0a67` keeps the exact raw entry's no-function/no-xref/no-literal-route status as a confidence cap rather than a file/source-placement blocker.

- 2026-06-21 B012 scalar-deleting-destructor source-quality incorporation:
  - Score unchanged.
  - Synchronized file-level lifecycle routing with B012's local export/listing evidence: [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) is the only handwritten `FpsPane::~FpsPane()` source body, while [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) is class-owned generated-binary scalar deleting destructor glue. Kept `NexusTK/ui/diagnostics/FpsPane.cpp` as source root and rejected wrapper flag/delete/guard mechanics as handwritten source.

- 2026-06-22 B013 UpdateStatistics root-report verification:
  - Score unchanged.
  - Confirmed [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) is already represented as emitted `FpsPane.cpp` code with first-draft `bool FpsPane::UpdateStatistics(int, int, int)`. B013 keeps `NexusTK/ui/diagnostics/FpsPane.cpp` as the source root, preserves dependency-only roles for `g_activeMapPane`, MapPane, ObjectList, and TimerHandler helpers, and rejects stale ParcelPane/caller-biased/raw-helper/no-code ownership interpretations.

- 2026-06-20 B005 UpdateStatistics source-quality implementation:
  - Score unchanged.
  - Added [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) as an explicit emitted `FpsPane.cpp` method with first-draft `bool FpsPane::UpdateStatistics(int, int, int)` readiness. The update records the dependency roles for `g_activeMapPane`, `MapPane::GetClampedVisibleTileBounds`, ObjectList front/back/visible count helpers, and `TimerHandler::ScheduleTimer`, keeps `NexusTK/ui/diagnostics/FpsPane.cpp` as the source root, and preserves rejection of ParcelPane/MapPane/ObjectList/TimerHandler ownership for the timer callback body.

- 2026-06-20 B004 destructor source-quality implementation:
  - Score unchanged.
  - Added the resolved `FpsPane::~FpsPane()` lifecycle route: constructor publishes `g_pFpsPane`, ordinary destructor [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) clears it with first-draft C++, and scalar deleting wrapper [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) mirrors the clear as compiler-generated delete support. Kept source root `NexusTK/ui/diagnostics/FpsPane.cpp` and rejected vtable/base/scalar-delete mechanics as handwritten source.

- 2026-06-19 B005 OnPaint source-quality support update:
  - Score unchanged.
  - Added [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) as an explicit emitted `FpsPane.cpp` method with first-draft `void FpsPane::OnPaint()` readiness, draw order, source dependencies, and source-placement reasoning. The update records the relationship to [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) `UpdateStatistics`, keeps `NexusTK/ui/diagnostics/FpsPane.cpp` as the source root, and preserves rejection of ParcelPane/MapPane/ObjectList/MainUiGraph ownership for the paint body.

- 2026-06-17 B003 source-quality execution:
  - Before: `87/85` with raw helper placement still open and global initializer language split between older IDA/PE interpretations.
  - Changed to: `88/87`; `NexusTK/ui/diagnostics/FpsPane.cpp` remains the accepted source root, raw helpers are documented as retained/private or old helper implementations, and draft global declarations are recorded.
  - Incorporated B003 report details: constructor/session/helper source shape, `StartLogSession`/`WriteLogSummary` helper-call model, MainUiLayerSlots `dword_69B37C` dependency, zero-initialized `g_pFpsPane` / `g_fpsLogEnabled`, explicit `g_fpsDebugActive = 1`, month/day/hour/minute/second timestamp order, CP949 string roles, and rejected ParcelPane/MapPane/ObjectList/MainUiGraph ownership alternatives.

- 2026-06-07 A009 Batch038 singleton split:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:80`; FPS global ownership was documented through by-global pages but not tied to exact split memory children.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:85`; added [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md), [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md), and exact Batch038 xrefs.
  - Summary/evidence: live IDA confirms both split children are directly FpsPane diagnostics state. Confidence rises to the corrected parent gate while preserving final-folder and raw-helper caveats.

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the status kept the final folder open between `ui/diagnostics/` and a flat original source file.
  - Changed to: `NexusTK/ui/diagnostics/`, matching the existing proposed source-tree placement.
  - Summary/evidence: the existing project-structure page already lists `ui/diagnostics/FpsPane.cpp`; IDA MCP recheck confirms this cluster is an FPS overlay/logging module with vtable data refs at `0x0061a620`, `0x0061a66c`, and `0x0061a69c`, singleton/global refs at `0x0069b334`, `0x0066da90`, and `0x0069b338`, and no evidence tying the diagnostics source to ParcelPane or MapPane ownership.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: diagnostics overlay role, proposed contents, layout/vtable docs, FPS globals, raw helper boundaries, stale ParcelPane ownership caveat, map/object dependencies, migration notes, and cross-references are documented; confidence is strong with final folder and raw helper treatment still medium.
- 2026-05-31: Added exact FpsPane vtable-data child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) to proposed contents and evidence. Evidence: IDA MCP verified RTTI/vtable span, constructor/destructor/scalar-destructor vtable writes, and the adjacent FPS string-data boundary.
