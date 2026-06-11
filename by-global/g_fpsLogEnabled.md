*** UID:0000PZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_fpsLogEnabled

## Status

- Symbol kind: global flag
- Address: `0x0069b338` (`byte_69B338` in IDA)
- Likely type: `bool` or byte flag
- Owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: strong for FpsPane ownership, log-write gating behavior, and xref locality; medium-high for exact final type/name.
- Rebuild handling: source-declared module/global diagnostic flag; exact address and generated initializer are linker output.
- Autogen parent: [UID:0000JK][FpsPane](by-file/FpsPane.md); C++ remains blank because the final declaration type and session-helper boundary are below the `95+` source gate.

## Behavior

`g_fpsLogEnabled` gates writing FPS diagnostics logs. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw summary helper at `0x004b6ae0` write `FPSDATA-*.txt`, `***NEW_CLIENT***`, min/max/average FPS, and average object counts only when this flag is enabled.

## Use Sites

| Address | Use | Evidence owner |
| --- | --- | --- |
| `0x004b653f` | Main session method gates new FPS log-file creation. | [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md). |
| `0x004b6645` | Main session method gates final summary write behavior. | Same session method; raw body still lacks an IDA function object. |
| `0x004b6a17` | Raw start-session helper gates file creation/start-line output. | [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md). |
| `0x004b6ae4` | Raw summary helper exits early unless logging is enabled. | [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md). |

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069b338` are all in the FpsPane diagnostic neighborhood: `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`.
- [UID:0000JK][FpsPane](by-file/FpsPane.md) is a validated `NexusTK/ui/diagnostics/` source root at `86/80` and lists this global as proposed FpsPane module state.
- [UID:00005F][FpsPane](by-class/FpsPane.md) records that the class-owned diagnostics cluster checks this flag in `UpdateFpsLogSession` and the raw write-summary helper before appending FPS log output.
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) is the current aggregate evidence home for the constructor/session/paint/statistics/logging helper island.
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) records the same four xrefs and places the log filename/statistics fields at owner offsets `+0x104` through `+0x168`.
- Current active `class_FpsPane.cpp` consumes the flag through `UpdateFpsLogSession`; `class_ParcelPane.cpp` still emits the generated global-data row and `class_ParcelPane.meta_wave3` still has stale owner-method references.

## Ownership Note

Treat ParcelPane global-data ownership as stale generated-data pollution. The stronger source owner is `FpsPane.cpp`.

Do not promote this to final C++ yet. The flag is clearly source-declared diagnostics state, but the final declaration type (`bool`, byte flag, or ABI-sized storage) and raw helper liveness remain below the final-code threshold.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-06 A010 diagnostics-flag evidence consolidation:
  - Before: `COMPLETION:80`, `CONFIDENCE:82`, with owner/xref bullets but no exact use table or rebuild-handling note.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared flag handling, exact use table, layout/session-helper cross-references, stronger stale ParcelPane owner caveat, and final declaration-type/liveness caveat.
  - Summary/evidence: the FpsPane diagnostics pages record all `0x0069b338` refs inside `0x004b64a0`, `0x004b69b0`, `0x004b6ae0`, and nearby FpsPane helper tails: `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`. Confidence remains below final-audit because the final type and raw helper liveness are unresolved.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents address, likely type/owner, FPS logging behavior, IDA xrefs, generated-owner pollution, and refs, but exact flag semantics and final type remain medium-confidence.
- 2026-06-03 FpsPane ownership pass:
  - Before: the page remained unparented at `78/74`, even though all known xrefs and the file/class pages identify the FPS diagnostics module as the owner.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JK`.
  - Evidence: [UID:0000JK][FpsPane](by-file/FpsPane.md) is `86/80` with a validated `NexusTK/ui/diagnostics/` path; [UID:00005F][FpsPane](by-class/FpsPane.md) is `82/80` and records the diagnostics/session behavior; IDA-backed xrefs remain confined to `0x004b64a0`, `0x004b6ae0`, and nearby FpsPane helper tails. C++ remains blank because final type/name and raw helper boundaries are not at the `95+` code-emission threshold.
