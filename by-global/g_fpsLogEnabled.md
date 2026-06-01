*** UID:0000PZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_fpsLogEnabled

## Status

- Symbol kind: global flag
- Address: `0x0069b338` (`byte_69B338` in IDA)
- Likely type: `bool` or byte flag
- Likely owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: medium

## Behavior

`g_fpsLogEnabled` gates writing FPS diagnostics logs. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw summary helper at `0x004b6ae0` write `FPSDATA-*.txt`, `***NEW_CLIENT***`, min/max/average FPS, and average object counts only when this flag is enabled.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069b338` are all in the FpsPane diagnostic neighborhood: `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`.
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
