*** UID:00005F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FpsPane

## Status

- Confidence: strong for overlay/statistics responsibility, medium for the constructor/session-start boundaries.
- Likely source file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Current recovered file: `source-3/simroot_v2/class_FpsPane.cpp`
- Related generated-data caveat: `source-3/simroot_v2/class_ParcelPane.meta_wave3` and ParcelPane global-data rows still reference FPS globals and the old `0x004b64a0` owner context.
- Memory range: [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- Layout docs: [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- Exact vtable data: [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)

## Class Purpose

`FpsPane` is a small diagnostic overlay pane. It displays the current frames-per-second value, samples FPS once per second, records min/max/average statistics, and collects map object-count metrics by reading the `ObjectList` row buckets used by `MapPane`.

This class is a consumer of [UID:00009Q][ObjectList](by-class/ObjectList.md), not an owner of the map object index.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x004b6410-0x004b646b` | `FpsPane::FpsPane` | Wave3 constructor range. Sets `g_pFpsPane`, installs three FpsPane vtable views, marks visible, and zeros current FPS. IDA currently does not mark this as a function. |
| `0x004b6470-0x004b6499` | non-deleting destructor | IDA-confirmed function. Reinstalls the three FpsPane vtable views, clears `g_pFpsPane`, and tail-jumps to the pane base destructor. Not emitted in active `class_FpsPane.cpp`. |
| `0x004b64a0-0x004b67a7` | `UpdateFpsLogSession` | Active `class_FpsPane.cpp` now emits this method. It starts/finalizes FPS logging, writes `FPSDATA-*.txt`, and schedules/removes the diagnostics timer. IDA currently does not mark this as a function. |
| `0x004b67b0-0x004b68ab` | `OnPaint` | Formats `"%5.1f FPS"` and draws two text passes for foreground/shadow. |
| `0x004b68b0-0x004b69b0` | `UpdateStatistics` | Samples tick count, updates FPS stats, reads `MapPane` visible bounds, sums front/back row-bucket counts, and schedules the next one-second timer. |
| `0x004b69b0-0x004b6adc` | raw start-session helper | IDA raw start, no direct xrefs. Resets session start time, min/max/sample fields, optionally creates a new `FPSDATA-*` file, then clears `g_fpsDebugActive`. |
| `0x004b6ae0-0x004b6c2b` | raw write-summary helper | IDA raw start, no direct xrefs. If `g_fpsLogEnabled` is set, appends elapsed time, FPS min/max/average, and object-count averages to the current log file. |
| [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) | vtable adjustment thunks | Compiler-generated thunks that forward to scalar deleting destructor with `this - 0x28` and `this - 0x29` dwords. Disabled in Wave3 active output and listed in ignored memory ranges. |
| `0x004b6c50-0x004b6caf` | `ScalarDeletingDestructor` | Clears `g_pFpsPane`, destroys the pane base, and optionally deletes memory. |

## Layout Notes

See [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) for the normalized object offsets. The key detail is that `UpdateStatistics` is reached through the timer/update vtable at owner offset `+0xa4`, so its decompiler offsets must be normalized by adding `0xa4`. After that normalization, the paint and statistics paths both use owner fields `+0xf8` for the frame/tick counter and `+0x100` for current displayed FPS, while the logging-session fields occupy `+0x104` through `+0x168`.

## Evidence Notes

- IDA MCP confirms real functions at `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50`.
- IDA MCP does not currently mark `0x004b6410`, `0x004b64a0`, `0x004b69b0`, or `0x004b6ae0` as functions, while raw disassembly shows method-shaped code starts. Treat those starts as unresolved boundary data, not as proof the code is absent.
- IDA MCP vtable inspection shows the FpsPane primary vtable at `0x0061a620`, secondary view at `0x0061a66c`, and timer/update view at `0x0061a69c`.
- 2026-05-31 IDA MCP dword scan confirms the exact FpsPane RTTI/vtable data span [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md), bounded by preceding read-only data at `0x0061a618` and FPS diagnostic string data at `0x0061a6a4`.
- 2026-05-26 IDA MCP layout follow-up confirms `UpdateStatistics` is subobject-relative to the `+0xa4` timer/update view; normalized owner offsets now line up with `OnPaint` and the raw logging helpers.
- IDA MCP xrefs to `g_fpsDebugActive` and `g_fpsLogEnabled` all land inside the FPS diagnostics neighborhood, including `0x004b64a0` and the raw helper tails.
- `UpdateStatistics` calls the `ObjectList`/`MapPaneSpatialIndex` accessors at `0x00532670`, `0x005326d0`, and `0x00532610` only to read counts for diagnostics.
- 2026-05-26 IDA MCP reconfirmed `0x004b6c2b` and `0x004b6c36` as 0xb-byte vtable-only adjustor thunks with data refs from `0x0061a66c` and `0x0061a69c`; keep them out of handwritten source reconstruction.

## Open Questions

- Decide whether raw starts `0x004b69b0` and `0x004b6ae0` are dead duplicate helpers, unreferenced private methods, or boundary artifacts related to `UpdateFpsLogSession`.
- Decide whether `FpsPane.cpp` belongs under `ui/diagnostics/`, `debug/`, or a flat original UI folder.
- Resolve the constructor/session boundary discrepancy between Wave3 and IDA before changing generated ownership.

## Cross-References

- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md)
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md)
- [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md)
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md)
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- 2026-06-01 autogen parent attachment:
  - What existed before: the class was marked `RECONSTRUCTABLE:TRUE` but had no `AUTOGEN_PARENT_UID`.
  - Changed to: parent [UID:0000JK][FpsPane](by-file/FpsPane.md).
  - Summary/evidence: the by-file page now has a validated `ui/diagnostics/` reconstruction path, and IDA MCP recheck confirms the class-owned vtable/global/function cluster belongs to the FPS diagnostics module.

- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: diagnostic overlay purpose, FPS/session methods, layout normalization, raw-start caveats, vtable addresses, global ownership, and ObjectList/MapPane consumer boundaries are documented; confidence remains limited by constructor/session boundary discrepancies. Evidence: diagnostics memory cluster `0x004b6410-0x004b6caf`, individual by-memory pages for constructor/destructor/session/paint/statistics helpers, `FpsPaneLayout`, and `FpsPane_vtables`.
- 2026-05-31: Reconstructable metadata clarified.
  - Before: `RECONSTRUCTABLE` was blank despite the class being documented as NexusTK-owned diagnostic pane source.
  - After: marked `RECONSTRUCTABLE:TRUE`; parent/code fields remain blank.
  - Summary/evidence: IDA MCP reconfirmed FpsPane vtable writes, destructor/paint/statistics/scalar-destructor functions, raw FpsPane-shaped constructor/session helper starts, and owned globals, but final source folder and raw helper treatment remain below autogen attachment confidence.
- 2026-05-31: Added exact vtable-data child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md). Evidence: IDA MCP dword scan and vtable xrefs prove the RTTI/vtable span and adjacent string-data boundary.
