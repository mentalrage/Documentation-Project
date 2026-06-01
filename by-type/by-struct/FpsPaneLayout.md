*** UID:0001UO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FpsPane Layout

## Status

- Entity kind: diagnostic pane layout.
- Covered class: [UID:00005F][FpsPane](by-class/FpsPane.md).
- Likely owner source: [UID:0000JK][FpsPane](by-file/FpsPane.md).
- Confidence: strong for normalized offsets below; medium for final source-facing field names and exact allocation size.

## Layout Notes

`FpsPane` has three vtable views: primary at `+0x00`, secondary pane view at `+0xa0`, and timer/update view at `+0xa4`. IDA decompiles `FpsPane::UpdateStatistics` at `0x004b68b0` from the timer/update subobject view, so its raw Hex-Rays offsets are `0xa4` bytes lower than the owning `FpsPane` offsets. The table below normalizes all fields back to the owner object.

| Owner offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | primary vtable | Raw constructor, non-deleting destructor, and scalar deleting destructor write `0x0061a620`. |
| `+0xa0` | `4` | secondary pane vtable view | Same lifecycle bodies write `0x0061a66c`; destructor thunk at `0x004b6c2b` subtracts `0xa0`. |
| `+0xa4` | `4` | timer/update vtable view | Same lifecycle bodies write `0x0061a69c`; slot `+0x04` points to `0x004b68b0`; destructor thunk at `0x004b6c36` subtracts `0xa4`. |
| `+0xf5` | `1` | visible/enabled pane byte | Raw constructor writes `1`; likely inherited `Pane` state. |
| `+0xf8` | `4` | frame/tick counter | Raw constructor computes singleton from `this + 0xf8`; `OnPaint` increments it; `UpdateFpsLogSession` resets it; `UpdateStatistics` reads and clears it via timer-subobject offset `+0x54`. |
| `+0x100` | `4` | current displayed FPS float | Raw constructor clears it; `OnPaint` reads it; `UpdateStatistics` writes it via timer-subobject offset `+0x5c`. |
| `+0x104` | `0x32` | log filename buffer | Logging paths pass this buffer to `_fopen_s` and format `FPSDATA-%d-%d-%d-%d-%d.txt` into it with size `0x32`. |
| `+0x136` | `0x10` | `SYSTEMTIME` block | Logging start paths call `GetLocalTime(this + 0x136)` and read year/month/day/hour/minute fields through `+0x138` to `+0x142`. |
| `+0x148` | `4` | logging-session start tick | Start paths store `timeGetTime`; summary path subtracts this from the current tick. |
| `+0x14c` | `4` | logging-session min FPS | Start paths initialize to `300.0f`; `UpdateStatistics` updates it via timer-subobject offset `+0xa8`; summary writes `minFPS`. |
| `+0x150` | `4` | logging-session max FPS | Start paths initialize to `0.0f`; `UpdateStatistics` updates it via timer-subobject offset `+0xac`; summary writes `maxFPS`. |
| `+0x154` | `4` | sample count | Start paths initialize to `1`; `UpdateStatistics` increments it via timer-subobject offset `+0xb0`; summary divides accumulated totals by it. |
| `+0x158` | `8` | double FPS sum | Start paths zero it; `UpdateStatistics` accumulates into it via timer-subobject offset `+0xb4`; summary divides by sample count for `aveFPS`. |
| `+0x160` | `4` | accumulated front/living object count | Start paths zero it; `UpdateStatistics` accumulates front-row bucket counts via timer-subobject offset `+0xbc`; summary writes `aveLivingObject`. |
| `+0x164` | `4` | accumulated visible/balloon object count | Start paths zero it; `UpdateStatistics` accumulates visible-object count via timer-subobject offset `+0xc0`; summary writes `aveBalloonObject`. |
| `+0x168` | `4` | accumulated back/static object count | Start paths zero it; `UpdateStatistics` accumulates back-row bucket counts via timer-subobject offset `+0xc4`; summary writes `aveStaticObject`. |

Minimum observed FpsPane-specific state extends through `+0x168`, so practical object size is at least `0x16c` bytes before allocator padding.

## Generated-Data Caveat

Current `source-3/simroot_v2/class_FpsPane.meta_wave3` reports only `Pane`, synthetic undefined bytes, `+0xf8`, and `+0x100` fields, and still reports `vtable_count: 0`. That generated layout is incomplete for source reconstruction because the FPS logging session fields at `+0x104` through `+0x168` are proven by IDA disassembly. Use this page as the layout anchor until Wave3 metadata is repaired.

## Evidence

- Raw constructor bytes at `0x004b6410-0x004b646b` install all three vtables, set byte `+0xf5`, and clear `+0x100`.
- `OnPaint` at `0x004b67b0` increments `+0xf8` and reads `+0x100` for the displayed FPS text.
- `UpdateStatistics` at `0x004b68b0` is a timer/update-view method. Its decompiler offsets normalize by adding `0xa4`, matching `+0xf8`, `+0x100`, and the logging-session totals.
- `UpdateFpsLogSession` at `0x004b64a0` and raw helpers at `0x004b69b0` / `0x004b6ae0` use owner-relative fields `+0x104` through `+0x168`.
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md) records `0x0061a69c + 0x04 -> 0x004b68b0` and the adjustor thunks that prove the `+0xa4` subobject view.
- 2026-05-31 IDA MCP `lookup_funcs` confirms `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` are still not modeled as functions, while `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50` are modeled functions with sizes `0x29`, `0xfb`, `0x100`, `0xb`, `0xb`, and `0x5f`.
- 2026-05-31 IDA MCP xrefs confirm the three vtable constants are written by the raw constructor (`0x004b643b`, `0x004b6441`, `0x004b644b`), ordinary destructor (`0x004b6470`, `0x004b6476`, `0x004b6480`), and scalar deleting destructor (`0x004b6c56`, `0x004b6c5c`, `0x004b6c66`).
- 2026-05-31 IDA MCP xrefs confirm [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) is written at `0x004b6434`, `0x004b648a`, and `0x004b6c70`; [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) is used at `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`; [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) is used at `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md)
- [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)

## Changes

- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `82/88`.
  - Summary/evidence: IDA MCP reconfirmed modeled and unmodeled FpsPane function boundaries, vtable writes, global xrefs, destructor/scalar destructor vtable restoration, `OnPaint` use of `+0xf8/+0x100`, and `UpdateStatistics` timer-view offsets that normalize by `+0xa4`. Scores remain below near-final because raw start ownership, final private field names, exact allocation size, and final source folder are still open.
