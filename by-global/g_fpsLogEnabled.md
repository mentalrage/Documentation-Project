*** UID:0000PZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool g_fpsLogEnabled;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_fpsLogEnabled

## Status

- Symbol kind: one-byte global diagnostics flag.
- Address/range: `0x0069b338`, backed by exact storage child [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md).
- Source-facing type and name: `bool g_fpsLogEnabled`; the type and name are the strongest human-source reconstruction rather than recovered original symbols.
- Owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: very strong for FpsPane ownership, four read-only log gates, exact byte storage, loader-zero default, no-writer/config closure, `bool` semantics, and one-definition source placement. Exact original spelling and linkage remain inferred.
- Rebuild handling: this page emits the sole source definition `bool g_fpsLogEnabled;` without an explicit initializer. Static initialization produces the observed loader-zero byte; do not add a setter, explicit initializer, or duplicate definition. The shared `extern` declaration is centralized in UID00005F's formal `FpsPane.h` payload.
- Autogen parent: [UID:0000JK][FpsPane](by-file/FpsPane.md), producing `NexusTK/ui/diagnostics/FpsPane.cpp`. UID0002W1 emits only a formal covered-by comment so physical storage is accounted for without duplicate source.

## Behavior

`g_fpsLogEnabled` gates writing FPS diagnostics logs. `FpsPane::UpdateFpsLogSession` at `0x004b64a0` and the raw summary helper at `0x004b6ae0` write `FPSDATA-*.txt`, `***NEW_CLIENT***`, min/max/average FPS, and average object counts only when this flag is enabled.

The original PE resolves the initializer direction. The byte lies in the unbacked virtual tail of writable `.data`, so the Windows loader supplies zero rather than loading a stored `0xff` or other initializer. All four uses are `cmp byte ptr ...,0` truth tests. The best source behavior is a compiled-in, default-off developer diagnostics gate; no normal in-binary writer, configuration key, UI control, or input route was found, so reconstruction must not invent one.

## Use Sites

| Address | Use | Evidence owner |
| --- | --- | --- |
| `0x004b653f` | `cmp byte ptr unk_69B338,0` reads the flag and gates new FPS log-file creation. | [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md). |
| `0x004b6645` | `cmp byte ptr unk_69B338,0` reads the flag and gates final summary output. | Same session method; raw body still lacks an IDA function object. |
| `0x004b6a17` | `cmp byte ptr unk_69B338,0` reads the flag and gates retained start-session file output. | [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md). |
| `0x004b6ae4` | `cmp byte ptr unk_69B338,0` reads the flag and implements the summary helper's early disabled return. | [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md). |

Every row is a read. No store appears in the exact xref set.

## PE Storage And Initialization Evidence

- Original input: `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, 2679296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- The target VA/RVA is `0x0069b338` / `0x0029b338` in PE32 x86 writable `.data` (section VA `0x0066d000`, virtual size `0x0002fe24`, raw size `0x0000d800`, raw pointer `0x0026ac00`, characteristics `0xc0000040`).
- Its section-relative delta `0x0002e338` exceeds the raw size, proving that no file byte initializes the storage. Dated bounded MCP reads return zero, exactly matching loader/static zero initialization.
- The exact memory child is one byte. The following three bytes at `0x0069b339-0x0069b33c` are separate loader-zero padding, while the next pointer-slot owner starts at `0x0069b33c`.

## Type, Name, Linkage, And Source Placement

- `bool` is selected because MSVC x86 stores a standalone `bool` in one byte and every use is a direct zero/nonzero truth test. `BYTE`, `unsigned char`, and `char` are binary-compatible but semantically weaker; `BOOL`/`int` conflict with the one-byte boundary; a bitfield conflicts with the standalone addressed byte and absence of masking.
- `g_fpsLogEnabled` is the best source-facing name because it describes the only observed behavior and follows neighboring FpsPane globals `g_pFpsPane` and `g_fpsDebugActive`. Dated IDA inspection instead showed a blank stored name/type and the synthetic operand rendering `unk_69B338`; neither raw rendering should appear in reconstructed source.
- Same-translation-unit use makes `static bool` plausible, but stripped binary evidence cannot recover the original linkage spelling. Retain the established external-form declaration rather than inventing a project-wide linkage change.
- This page is the sole declaration-bearing source child. UID0002W1 records bytes/xrefs and emits its covered-by comment; [UID:00005F][FpsPane](by-class/FpsPane.md) owns consuming methods but must not duplicate file-level global source.

## No-Writer And Route Closure

- Exact bounded xrefs to `0x0069b338` are `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`, all inside the FpsPane diagnostics/logging island and all reads.
- Backward data-flow found no store node. Exact little-endian VA search (`38 b3 69 00`) found only those four instruction operands; RVA pattern `38 b3 29 00` and pointer/data-table searches found no indirect route.
- Repository/current generated source contains no assignment beyond `bool g_fpsLogEnabled;`. FPS string/config/UI/input searches found log filenames and statistics text but no toggle key or control.
- The raw starts `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` remain unmodeled as IDA functions, but their exact instructions and storage xrefs are sufficient for this global's behavior and source placement.

## Supporting Evidence

- [UID:0000JK][FpsPane](by-file/FpsPane.md) is a validated `NexusTK/ui/diagnostics/` source root and lists this global as proposed FpsPane module state.
- [UID:00005F][FpsPane](by-class/FpsPane.md) records that the class-owned diagnostics cluster checks this flag in `UpdateFpsLogSession` and the raw write-summary helper before appending FPS log output.
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) is the current aggregate evidence home for the constructor/session/paint/statistics/logging helper island.
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) records the same four xrefs and places the log filename/statistics fields at owner offsets `+0x104` through `+0x168`.
- Current generated `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` consumes/emits this flag through the FpsPane source route; historical `class_FpsPane.cpp`, `class_ParcelPane.cpp`, and `class_ParcelPane.meta_wave3` references remain stale generated-source leads only.

## Historical Assumptions Retained As Disproved Or Limited

- The older local export `.data:0069B338 byte_69B338 db ?` correctly suggested static storage but did not prove physical raw backing, final source type, or original name.
- The earlier `0xff` interpretation is disproved by exact original-PE mapping: the VA lies beyond `.data` raw payload and is loader-zeroed.
- The 2026-06-16 saved-rename claim is retained as historical IDB activity, not current symbol authority. Fresh dated pre-dry-run inspection found a blank stored name/type; a validation-only rename dry run resolved the synthetic auto-name `unk_69B338` but did not apply `g_fpsLogEnabled` or recover an original symbol.
- Earlier externally toggled/config-patched alternatives remain possible development provenance, but exhaustive current binary searches found no writer/config/UI/input route. They do not justify inventing runtime source behavior.

## Ownership Note

Treat ParcelPane global-data ownership as stale generated-data pollution. The stronger source owner is `FpsPane.cpp`.

The source definition is emitted here exactly once as `bool g_fpsLogEnabled;`; this page's H channel remains blank because the accepted `extern bool g_fpsLogEnabled;` declaration is centralized in UID00005F's formal `FpsPane.h` payload. UID0002W1's formal covered-by comment prevents an empty physical emitter without creating a second definition. Exact original spelling/linkage remains a lexical uncertainty, not a behavior, type, initializer, writer, owner, or C++ blocker.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | Covers exact one-byte storage, original-PE loader zero, all four read roles, exhaustive no-writer/pointer/config/source-assignment closure, resolved source type/name/default, sole-definition policy, centralized header declaration, and FpsPane.cpp placement. |
| Confidence `96` | PE mapping, bounded MCP bytes/xrefs/instructions, adjacent boundaries, current FpsPane documentation, and accepted source routing agree. Exact original spelling/linkage and external developer-control provenance remain inferred but do not affect runtime behavior. |

## 2026-08-24 Accepted Source Closure

- The exact definition is `bool g_fpsLogEnabled;`; loader/static zero initialization reproduces the observed byte without inventing an explicit initializer.
- All four xrefs are read-only zero tests. No store, setter, config key, UI control, input route, pointer table, or source assignment exists in the exhaustive accepted searches.
- UID0002W1 accounts for the physical byte with a covered-storage comment. UID00005F centralizes the `extern` declaration, so this page's H channel remains intentionally blank.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-08-04 B009 accepted ordinary-document implementation:
  - Raised `89/90` to `92/93` after incorporating exact original-PE loader-zero proof, all four read-only uses, exhaustive no-writer/config/pointer closure, and final source-shape reasoning.
  - Retained the sole formal CPP payload `bool g_fpsLogEnabled;` and blank H channel; documented UID0002W1's covered-by marker and rejected duplicate class/memory definitions.
  - Historicalized the former `0xff`, `db ?`, saved-rename, and possible hidden-toggle assumptions without deleting their evidentiary history.

- 2026-07-04 B006 UID00015D support sync:
  - Score unchanged.
  - Replaced stale current `class_FpsPane.cpp` source wording with current `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` context. UID00015D now serves as a reviewed non-emitting split/index evidence home for the diagnostics cluster, not an aggregate source emitter.

- 2026-06-23 B002 StartLogSession support sync:
  - Score unchanged.
  - Updated [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) references to the renamed [0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md). MCP session `80de0a67` confirms `0x004b6a17` as the start-helper log-file gate while keeping the exact helper entry callerless/unmodeled.

- 2026-06-17 B003 source-quality execution:
  - Before: `88/90`, blank C++ and stale ambiguity around older nonzero initializer wording.
  - Changed to: `89/90`, first-draft `bool g_fpsLogEnabled;` declaration.
  - Incorporated B003 report details: local IDA export `byte_69B338 db ?`, zero-initialized source storage, no proven writer, four FpsPane compare refs, stale ParcelPane owner rejection, and exact-memory storage page remains blank to avoid duplicate output.

- 2026-06-06 A010 diagnostics-flag evidence consolidation:
  - Before: `COMPLETION:80`, `CONFIDENCE:82`, with owner/xref bullets but no exact use table or rebuild-handling note.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared flag handling, exact use table, layout/session-helper cross-references, stronger stale ParcelPane owner caveat, and final declaration-type/liveness caveat.
  - Summary/evidence: the FpsPane diagnostics pages record all `0x0069b338` refs inside `0x004b64a0`, `0x004b69b0`, `0x004b6ae0`, and nearby FpsPane helper tails: `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`. Confidence remains below final-audit because the final type and raw helper liveness are unresolved.
- 2026-06-16 C001 global/IDA refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Evidence: live IDA MCP reconfirmed the exact byte-storage neighborhood, four FpsPane-only raw refs, raw helper no-function status, start-session gate, and summary early-exit behavior. Applied and saved the safe data label `g_fpsLogEnabled`. Final C++/type edits remain blocked by raw helper liveness and exact source declaration type.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents address, likely type/owner, FPS logging behavior, IDA xrefs, generated-owner pollution, and refs, but exact flag semantics and final type remain medium-confidence.
- 2026-06-03 FpsPane ownership pass:
  - Before: the page remained unparented at `78/74`, even though all known xrefs and the file/class pages identify the FPS diagnostics module as the owner.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JK`.
  - Evidence: [UID:0000JK][FpsPane](by-file/FpsPane.md) was `86/80` and [UID:00005F][FpsPane](by-class/FpsPane.md) was `82/80` at the time of that pass; IDA-backed xrefs remained confined to `0x004b64a0`, `0x004b6ae0`, and nearby FpsPane helper tails. The old blank-C++/95+ conclusion is superseded by the 2026-06-17 B003 source-quality execution.
