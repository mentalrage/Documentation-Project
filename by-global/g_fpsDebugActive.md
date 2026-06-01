*** UID:0000PY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_fpsDebugActive

## Status

- Symbol kind: global flag
- Address: `0x0066da90` (`dword_66DA90` in IDA)
- Likely type: `int` or `bool`
- Likely owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: medium

## Behavior

This flag controls FPS diagnostics session startup and restart behavior. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw helper at `0x004b69b0` read and clear it when starting a new FPS monitoring session.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0066da90` are all in the FpsPane diagnostic neighborhood: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`.
- Current active `class_FpsPane.cpp` consumes the flag through `UpdateFpsLogSession`; `class_ParcelPane.cpp` still emits the generated global-data row and `class_ParcelPane.meta_wave3` still has stale owner-method references.

## Ownership Note

Treat ParcelPane global-data ownership as stale generated-data pollution. The stronger source owner is `FpsPane.cpp`.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents address, likely type/owner, FPS diagnostic behavior, IDA xrefs, generated-owner pollution, and refs, but the exact flag semantics and final type remain medium-confidence.
