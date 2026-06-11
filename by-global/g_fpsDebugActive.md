*** UID:0000PY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_fpsDebugActive

## Status

- Symbol kind: global flag
- Address: `0x0066da90` (`dword_66DA90` in IDA)
- Likely type: `int` or `bool`
- Owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: strong for FpsPane ownership, diagnostic-session behavior, and xref locality; medium-high for exact final type/name.
- Rebuild handling: source-declared module/global diagnostic flag; exact address and generated initializer are linker output.
- Autogen parent: [UID:0000JK][FpsPane](by-file/FpsPane.md); C++ remains blank because the final declaration type and session-helper boundary are below the `95+` source gate.

## Behavior

This flag controls FPS diagnostics session startup and restart behavior. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw helper at `0x004b69b0` read and clear it when starting a new FPS monitoring session.

## Use Sites

| Address | Use | Evidence owner |
| --- | --- | --- |
| `0x004b64e5` | Start/finalize session path checks the diagnostic restart flag. | [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md). |
| `0x004b65f5` | Main session method clears or consumes the flag after session setup. | Same session method; raw body still lacks an IDA function object. |
| `0x004b69bd` | Raw start-session helper gates new-log setup on the flag. | [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md). |
| `0x004b6acd` | Raw start-session helper clears the flag after resetting counters/file state. | Same raw helper; liveness is still unresolved, but the storage use is FPS-specific. |

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0066da90` are all in the FpsPane diagnostic neighborhood: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`.
- [UID:0000JK][FpsPane](by-file/FpsPane.md) is a validated `NexusTK/ui/diagnostics/` source root at `86/80` and lists this global as proposed FpsPane module state.
- [UID:00005F][FpsPane](by-class/FpsPane.md) records that the class-owned diagnostics cluster reads and clears this flag in `UpdateFpsLogSession` and the raw start-session helper.
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) is the current aggregate evidence home for the constructor/session/paint/statistics/logging helper island.
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) records the same four xrefs and places the related session fields at owner offsets `+0x104` through `+0x168`.
- Current active `class_FpsPane.cpp` consumes the flag through `UpdateFpsLogSession`; `class_ParcelPane.cpp` still emits the generated global-data row and `class_ParcelPane.meta_wave3` still has stale owner-method references.

## Ownership Note

Treat ParcelPane global-data ownership as stale generated-data pollution. The stronger source owner is `FpsPane.cpp`.

Do not promote this to final C++ yet. The flag is clearly source-declared diagnostics state, but the final declaration type (`bool`, `int`, or byte-sized compatibility storage) and raw helper liveness remain below the final-code threshold.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-06 A010 diagnostics-flag evidence consolidation:
  - Before: `COMPLETION:80`, `CONFIDENCE:82`, with owner/xref bullets but no exact use table or rebuild-handling note.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared flag handling, exact use table, layout/session-helper cross-references, stronger stale ParcelPane owner caveat, and final declaration-type/liveness caveat.
  - Summary/evidence: the FpsPane diagnostics pages record all `0x0066da90` refs inside `0x004b64a0`, `0x004b69b0`, and nearby FpsPane helper tails: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`. Confidence remains below final-audit because the final type and raw helper liveness are unresolved.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents address, likely type/owner, FPS diagnostic behavior, IDA xrefs, generated-owner pollution, and refs, but the exact flag semantics and final type remain medium-confidence.
- 2026-06-03 FpsPane ownership pass:
  - Before: the page remained unparented at `78/74`, even though all known xrefs and the file/class pages identify the FPS diagnostics module as the owner.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JK`.
  - Evidence: [UID:0000JK][FpsPane](by-file/FpsPane.md) is `86/80` with a validated `NexusTK/ui/diagnostics/` path; [UID:00005F][FpsPane](by-class/FpsPane.md) is `82/80` and records the diagnostics/session behavior; IDA-backed xrefs remain confined to `0x004b64a0`, `0x004b69b0`, and nearby FpsPane helper tails. C++ remains blank because final type/name and raw helper boundaries are not at the `95+` code-emission threshold.
