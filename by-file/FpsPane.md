*** UID:0000JK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/diagnostics/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FpsPane

## Status

- Proposed module: `ui/diagnostics/FpsPane.cpp`
- Proposed header: `ui/diagnostics/FpsPane.h`
- Confidence: strong for separate diagnostic module, medium-high for final folder.
- Current generated source: `class_FpsPane.cpp`
- Related generated-data caveat: `class_ParcelPane.meta_wave3` and ParcelPane global-data rows still reference FPS diagnostics ownership, even though active `class_FpsPane.cpp` now emits `0x004b64a0`.
- Type docs: [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md), [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md)

## File Role

`FpsPane.cpp` likely owned the in-client performance overlay. It displays FPS, schedules a one-second update callback, records FPS min/max/average values, optionally writes `FPSDATA-*.txt` logs, and samples live map object counts through `MapPane` / `ObjectList`.

Keep this separate from [UID:0000MF][ParcelPane](by-file/ParcelPane.md) and [UID:0000M4][ObjectList](by-file/ObjectList.md):

- It is not parcel UI; the `0x004b64a0` body is FPS logging/session code. Current active generated source places it in `class_FpsPane.cpp`, while stale ParcelPane metadata still references it.
- It is not a map object-index class; it reads map object counts only for diagnostics.

## Proposed Contents

| Entity | Current range | Current generated owner | Proposed ownership |
| --- | --- | --- | --- |
| [UID:00005F][FpsPane](by-class/FpsPane.md) constructor/raw setup | `0x004b6410-0x004b646b` | `class_FpsPane.cpp`; not an IDA function | `FpsPane.cpp` |
| non-deleting destructor body | `0x004b6470-0x004b6499` | IDA function, not emitted in active `class_FpsPane.cpp` | `FpsPane.cpp` |
| `UpdateFpsLogSession` | `0x004b64a0-0x004b67a7` | `class_FpsPane.cpp`; stale ParcelPane metadata/global-data references | `FpsPane.cpp` |
| raw start-session helper | `0x004b69b0-0x004b6adc` | not emitted as a separate active method; not an IDA function | `FpsPane.cpp` or private diagnostics helper |
| raw write-summary helper | `0x004b6ae0-0x004b6c2b` | not emitted as a separate active method; not an IDA function | `FpsPane.cpp` or private diagnostics helper |
| destructor adjustor thunks | [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) | IDA-confirmed 0xb-byte vtable adjustor thunks; ignored as compiler glue | compiler-generated, not source |
| [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) | `0x0069b334` | `class_FpsPane.cpp` | `FpsPane.cpp` module global |
| [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) | `0x0066da90` | generated under `class_ParcelPane.cpp` global-data | `FpsPane.cpp` module global |
| [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) | `0x0069b338` | generated under `class_ParcelPane.cpp` global-data | `FpsPane.cpp` module global |
| [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md) | `0x0061a620`, `0x0061a66c`, `0x0061a69c` | type data | `FpsPane.cpp` / `FpsPane.h` |
| [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) | `0x0061a61c-0x0061a6a4` | exact RTTI/vtable data | compiler-generated from `FpsPane` declarations |

## Evidence

- Wave3 import provenance names `FpsPane.cpp`.
- Current `source-3/simroot_v2/class_FpsPane.cpp` emits `UpdateFpsLogSession` at `0x004b64a0`; older/suspect ParcelPane metadata and global-data rows still reference that same method context.
- IDA MCP confirms the non-deleting destructor body at `0x004b6470`, plus `OnPaint`, `UpdateStatistics`, destructor thunks, and scalar deleting destructor in the compact `0x004b67b0-0x004b6caf` range.
- 2026-05-31 IDA MCP confirms exact FpsPane RTTI/vtable data at [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md), with string data beginning at `0x0061a6a4`.
- Wave3 metadata places `FpsPane::FpsPane` at `0x004b6410-0x004b646a`, but IDA currently leaves the range unmarked.
- IDA raw disassembly confirms additional FpsPane-shaped, callerless helper starts at `0x004b69b0` and `0x004b6ae0`. They operate on the same FPS session/log filename fields and globals but are not emitted as separate active methods.
- 2026-05-26 IDA layout follow-up confirms the apparent field split between `OnPaint` and `UpdateStatistics` is caused by `UpdateStatistics` using the timer/update subobject at `+0xa4`; normalized owner offsets are documented in [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md).
- `FpsPane::UpdateStatistics` reads `g_pMapPane`, visible tile bounds, and ObjectList row-bucket counts, but does not own map/object code.
- 2026-05-26 IDA MCP reconfirmed the thunk pair at `0x004b6c2b` and `0x004b6c36` as vtable-only compiler adjustors into `FpsPane::ScalarDeletingDestructor`; these are now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Source-Structure Decision

Use a standalone `FpsPane.cpp` module. The exact folder is open: `ui/diagnostics/` matches the behavior in the reconstructed tree, while a flat `FpsPane.cpp` may be closer if the original VC++ project did not split diagnostic UI into folders.

Do not merge this into `MapPane.cpp`; the object-count calls are diagnostic reads. Do not let stale ParcelPane metadata or generated global-data placement pull the session/logging code into `ParcelPane.cpp`.

## Migration Notes

- Recheck the constructor, session method, and raw helper boundaries with another disassembler before header migration.
- Keep `0x004b64a0-0x004b67a7` in `FpsPane` unless future evidence proves a shared diagnostics helper.
- Attach or explicitly quarantine raw helper starts `0x004b69b0` and `0x004b6ae0`; they should not be silently hidden behind the aggregate page.
- Keep `g_pMapPane` external; FpsPane should only include a forward declaration or use an accessor.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
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
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- `ParcelPane` generated-source ownership caveat in [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the status kept the final folder open between `ui/diagnostics/` and a flat original source file.
  - Changed to: `NexusTK/ui/diagnostics/`, matching the existing proposed source-tree placement.
  - Summary/evidence: the existing project-structure page already lists `ui/diagnostics/FpsPane.cpp`; IDA MCP recheck confirms this cluster is an FPS overlay/logging module with vtable data refs at `0x0061a620`, `0x0061a66c`, and `0x0061a69c`, singleton/global refs at `0x0069b334`, `0x0066da90`, and `0x0069b338`, and no evidence tying the diagnostics source to ParcelPane or MapPane ownership.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: diagnostics overlay role, proposed contents, layout/vtable docs, FPS globals, raw helper boundaries, stale ParcelPane ownership caveat, map/object dependencies, migration notes, and cross-references are documented; confidence is strong with final folder and raw helper treatment still medium.
- 2026-05-31: Added exact FpsPane vtable-data child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) to proposed contents and evidence. Evidence: IDA MCP verified RTTI/vtable span, constructor/destructor/scalar-destructor vtable writes, and the adjacent FPS string-data boundary.
