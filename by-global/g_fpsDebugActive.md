*** UID:0000PY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int g_fpsDebugActive = 1;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_fpsDebugActive

## Status

- Symbol kind: global flag
- Address: `0x0066da90` (`dword_66DA90` in current MCP session `ddf5b602`; `g_fpsDebugActive` is the source-facing documentation/generator name)
- Likely type: `int`
- Owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: very strong for FpsPane ownership, four exact uses, initialized value `1`, `int` storage width, one-definition source routing, and the activation/session-start semantics; exact original lexical spelling remains inferred.
- Rebuild handling: source-declared module/global diagnostic flag; exact address and generated initializer are linker output.
- Autogen parent: [UID:0000JK][FpsPane](by-file/FpsPane.md); this page emits the first-draft source declaration while the exact memory storage child [UID:00027E][0x0066da90-0x0066da94.g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md) carries only a formal covered-by marker to avoid duplicate output.

## Behavior

This flag controls FPS diagnostics session startup and restart behavior. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw helper at `0x004b69b0` read and clear it when starting a new FPS monitoring session.

B003 keeps the stable `g_fpsDebugActive` name but records the source semantics as a pending debug/log-session start flag. `g_fpsDebugSessionPending` or `g_fpsLogStartPending` would be descriptive aliases if a later naming pass changes the symbol.

## Use Sites

| Address | Use | Evidence owner |
| --- | --- | --- |
| `0x004b64e5` | Start/finalize session path checks the diagnostic restart flag. | [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md). |
| `0x004b65f5` | Main session method clears or consumes the flag after session setup. | Same session method; raw body still lacks an IDA function object. |
| `0x004b69bd` | Raw/unmodeled source-facing start-session helper gates new-log setup on the flag. | [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md). |
| `0x004b6acd` | Raw start-session helper clears the flag after resetting counters/file state. | Same raw helper; liveness is still unresolved, but the storage use is FPS-specific. |

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0066da90` are all in the FpsPane diagnostic neighborhood: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`.
- 2026-07-04 B005 MCP session `ddf5b602` reconfirmed `get_global_value 0x0066da90 == 1`, `get_global_value dword_66DA90 == 1`, `get_bytes 0x0066da90 size 4 == 01 00 00 00`, and the neighborhood bytes `58 00 3a 00 5c 00 00 00 01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00`.
- 2026-07-04 B005 MCP session `ddf5b602` reports no current symbol resolution for `g_fpsDebugActive`; the current live IDB label is raw `dword_66DA90`. Preserve `g_fpsDebugActive` as the source-facing documentation/generator name, not as current-symbol proof.
- 2026-07-04 B005 MCP session `ddf5b602` reconfirmed the same four refs to the storage at `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`; scoped `search_text` renders them as `dword_66DA90` compares/clears, and exact pointer-byte checks found no RVA route.
- Historical 2026-06-16 C001 live IDA MCP recheck on session `b001_selflookpane_0001H7_20260616` reconfirmed the neighborhood bytes and saved the label change from `dword_66DA90` to `g_fpsDebugActive`. Current session `ddf5b602` does not expose that saved name, so use C001 as historical naming provenance only.
- [UID:0000JK][FpsPane](by-file/FpsPane.md) is a validated `NexusTK/ui/diagnostics/` source root and lists this global as proposed FpsPane module state.
- [UID:00005F][FpsPane](by-class/FpsPane.md) records that the class-owned diagnostics cluster reads and clears this flag in `UpdateFpsLogSession` and the raw start-session helper.
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) is the current aggregate evidence home for the constructor/session/paint/statistics/logging helper island.
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) records the same four xrefs and places the related session fields at owner offsets `+0x104` through `+0x168`.
- Current generated `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` consumes/emits this flag through the FpsPane source route; historical `class_FpsPane.cpp`, `class_ParcelPane.cpp`, and `class_ParcelPane.meta_wave3` references remain stale generated-source leads only.
- 2026-06-17 B003 local IDA export lists `.data:0066DA90 dword_66DA90 dd 1`, supporting the first-draft source declaration `int g_fpsDebugActive = 1;`.

## Ownership Note

Treat ParcelPane global-data ownership as stale generated-data pollution. The stronger source owner is `FpsPane.cpp`.

The first-draft declaration is now emitted here as `int g_fpsDebugActive = 1;`. Final audit still needs original spelling, but the dword initializer, owner route, and FpsPane-only compare/clear refs are sufficient for draft C++. Do not duplicate this declaration in the exact by-memory storage child [UID:00027E][0x0066da90-0x0066da94.g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md); that page is a covered-by storage/evidence child.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)
- [Wave3 data issues](../wave3_data_issues.md)

## 2026-08-24 Accepted Source Closure

- The exact definition remains `int g_fpsDebugActive = 1;` in `FpsPane.cpp`; its declaration is centralized in UID00005F `FpsPane.h`, so this by-global H channel remains blank.
- The four references are exhaustive for the accepted evidence set: checks at `0x004b64e5` and `0x004b69bd`, followed by one-shot clears at `0x004b65f5` and `0x004b6acd`.
- UID00027E owns only the physical four-byte evidence and emits a covered-storage comment, preventing a duplicate definition.
- Completion/confidence are `92/94`: binary width, initializer, use distribution, module ownership, source type, and one-definition placement are resolved; only original source spelling lacks symbol proof.

## Changes

- 2026-07-04 B006 UID00015D support sync:
  - Score unchanged.
  - Replaced stale current `class_FpsPane.cpp` source wording with current `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` context. UID00015D now serves as a reviewed non-emitting split/index evidence home for the diagnostics cluster, not an aggregate source emitter.

- 2026-07-04 B005 UID00027E source-quality support sync:
  - Score unchanged.
  - Added current MCP session `ddf5b602` evidence that live lookup resolves raw `dword_66DA90`, not `g_fpsDebugActive`, while preserving `g_fpsDebugActive` as the source-facing documentation/generator name.
  - Reconfirmed exact value/bytes, four FpsPane compare/clear refs, no RVA pointer route, and adjacent FolderSelect/screen-size boundaries.
  - Clarified that this by-global page remains the source declaration owner for `int g_fpsDebugActive = 1;`; exact memory child [UID:00027E][0x0066da90-0x0066da94.g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md) now carries only a covered-by marker to avoid duplicate output.

- 2026-06-23 B002 StartLogSession support sync:
  - Score unchanged.
  - Updated [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) references to the renamed [0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md). MCP session `80de0a67` preserves the `0x004b69bd` compare and `0x004b6acd` clear as start-helper uses of this flag while confirming no direct route to the raw helper entry.

- 2026-06-17 B003 source-quality execution:
  - Before: `87/89`, blank C++ with final type/liveness caveat.
  - Changed to: `88/89`, first-draft `int g_fpsDebugActive = 1;` declaration.
  - Incorporated B003 report details: local IDA export `dword_66DA90 dd 1`, pending debug/log-session start semantics, four FpsPane compare/clear refs, stale ParcelPane owner rejection, and exact-memory storage page remains blank to avoid duplicate output.

- 2026-06-06 A010 diagnostics-flag evidence consolidation:
  - Before: `COMPLETION:80`, `CONFIDENCE:82`, with owner/xref bullets but no exact use table or rebuild-handling note.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared flag handling, exact use table, layout/session-helper cross-references, stronger stale ParcelPane owner caveat, and final declaration-type/liveness caveat.
  - Summary/evidence: the FpsPane diagnostics pages record all `0x0066da90` refs inside `0x004b64a0`, `0x004b69b0`, and nearby FpsPane helper tails: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`. Confidence remains below final-audit because the final type and raw helper liveness are unresolved.
- 2026-06-16 C001 global/IDA refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:89`.
  - Evidence: live IDA MCP reconfirmed initialized dword bytes, exactly four FpsPane raw diagnostic refs, and no modeled function objects for the session helpers. Historical action: applied and saved the data label `g_fpsDebugActive`; current MCP session `ddf5b602` exposes raw `dword_66DA90`, so the saved label is naming provenance rather than current live-symbol proof.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents address, likely type/owner, FPS diagnostic behavior, IDA xrefs, generated-owner pollution, and refs, but the exact flag semantics and final type remain medium-confidence.
- 2026-06-03 FpsPane ownership pass:
  - Before: the page remained unparented at `78/74`, even though all known xrefs and the file/class pages identify the FPS diagnostics module as the owner.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JK`.
  - Evidence: [UID:0000JK][FpsPane](by-file/FpsPane.md) was `86/80` and [UID:00005F][FpsPane](by-class/FpsPane.md) was `82/80` at the time of that pass; IDA-backed xrefs remained confined to `0x004b64a0`, `0x004b69b0`, and nearby FpsPane helper tails. The old blank-C++/95+ conclusion is superseded by the 2026-06-17 B003 source-quality execution.
