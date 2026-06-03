*** UID:0000PZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong for FpsPane ownership and log-write gating behavior; medium-high for exact final type/name.
- Autogen parent: [UID:0000JK][FpsPane](by-file/FpsPane.md); C++ remains blank because the final declaration type and session-helper boundary are below the `95+` source gate.

## Behavior

`g_fpsLogEnabled` gates writing FPS diagnostics logs. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw summary helper at `0x004b6ae0` write `FPSDATA-*.txt`, `***NEW_CLIENT***`, min/max/average FPS, and average object counts only when this flag is enabled.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069b338` are all in the FpsPane diagnostic neighborhood: `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`.
- [UID:0000JK][FpsPane](by-file/FpsPane.md) is a validated `NexusTK/ui/diagnostics/` source root at `86/80` and lists this global as proposed FpsPane module state.
- [UID:00005F][FpsPane](by-class/FpsPane.md) records that the class-owned diagnostics cluster checks this flag in `UpdateFpsLogSession` and the raw write-summary helper before appending FPS log output.
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) is the current aggregate evidence home for the constructor/session/paint/statistics/logging helper island.
- Current active `class_FpsPane.cpp` consumes the flag through `UpdateFpsLogSession`; `class_ParcelPane.cpp` still emits the generated global-data row and `class_ParcelPane.meta_wave3` still has stale owner-method references.

## Ownership Note

Treat ParcelPane global-data ownership as stale generated-data pollution. The stronger source owner is `FpsPane.cpp`.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents address, likely type/owner, FPS logging behavior, IDA xrefs, generated-owner pollution, and refs, but exact flag semantics and final type remain medium-confidence.
- 2026-06-03 FpsPane ownership pass:
  - Before: the page remained unparented at `78/74`, even though all known xrefs and the file/class pages identify the FPS diagnostics module as the owner.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JK`.
  - Evidence: [UID:0000JK][FpsPane](by-file/FpsPane.md) is `86/80` with a validated `NexusTK/ui/diagnostics/` path; [UID:00005F][FpsPane](by-class/FpsPane.md) is `82/80` and records the diagnostics/session behavior; IDA-backed xrefs remain confined to `0x004b64a0`, `0x004b6ae0`, and nearby FpsPane helper tails. C++ remains blank because final type/name and raw helper boundaries are not at the `95+` code-emission threshold.
