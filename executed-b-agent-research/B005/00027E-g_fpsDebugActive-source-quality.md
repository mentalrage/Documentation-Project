** TARGET-REPORT-UID:00027E **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID00027E g_fpsDebugActive Source-Quality Research


## Finalized Report / Current Recommendation

UID00027E is the exact four-byte `.data` storage child at `0x0066da90-0x0066da94` for the FpsPane diagnostics start-pending flag. At report time the target page is `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JK`, and has a blank formal `RECONSTRUCTION_CPP CODE` block. The semantic by-global page [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) already emits the actual source declaration `int g_fpsDebugActive = 1;` through [UID:0000JK][FpsPane](by-file/FpsPane.md), so UID00027E should not duplicate that declaration.

Recommendation: raise UID00027E to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000JK`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000JK`, and replace the blank formal block with a formal covered-by marker comment. This resolves the current empty-emitter defect while preserving the no-duplicate declaration policy already used by nearby exact-storage globals such as [UID:0001OG][g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md).

Implementation callback status: applied on 2026-07-04. UID00027E is now `88/90`, retains owner/emitter [UID:0000JK], carries the formal covered-by marker, and generated `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` refreshed to validator header command `000000006472` with the UID00027E marker comment instead of the old empty-emitter marker.

## Supporting Research

This report records both the initial report-only pass and the accepted implementation callback. During the initial report-only pass, no target/support by-* documentation, generated output, coverage reports, validator state, lifecycle state, archives, or supervisor ledgers were edited. During the implementation callback, B005 edited only `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` and stale support page `by-global/g_fpsDebugActive.md`, then ran scoped file validators for those two by-* docs. B005 did not run `execute_report`, dry-run execute variants, report moves, registry lifecycle commands, archive commands, or manual generated/coverage edits.

Required local and historical sources were checked:

- Target page: `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`.
- Semantic declaration page: `by-global/g_fpsDebugActive.md`.
- Source owner/support pages: `by-file/FpsPane.md`, `by-class/FpsPane.md`, and `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`.
- Generated output and trackers: `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-memory-coverage.md`.
- Historical executed B reports: `executed-b-agent-research/B003/00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md`, `executed-b-agent-research/B008/00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality.md`, `executed-b-agent-research/B002/00015I-FpsPaneStartLogSessionRaw-source-quality.md`, and `executed-b-agent-research/B003/00015J-FpsPaneWriteLogSummaryRaw-source-quality.md`.
- Root/project report-style sources and active-agent notes: `wave3_data_issues.md`, `project-level/-resolved.md`, `project-level/-unresolved.md`, `by-project-structure/proposed-source-tree.md`, `tools/leaser/Agents/Supervisor_notes.md`, `tools/leaser/Agents/Agent-A003/notes.md`, `tools/leaser/Agents/Agent-C001/notes.md`, and `tools/leaser/Agents/b-agent-rule26-incorporation-tracker.md`.
- Adjacent exact-storage pages and globals: [UID:00027D][FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md), [UID:0001OG][g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md), [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md).

The archived/executed B-agent corpus checked for this target was `executed-b-agent-research`; no pre-existing Agent-B005 UID00027E root report was present before this artifact.

Current MCP-backed evidence was refreshed under supervisor-restored session `ddf5b602`. Earlier listener-only/no-session MCP checks are historical incident context only and are not used as final evidence.

## Target

- Target UID: `00027E`
- Target path: `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`
- Address range: `0x0066da90-0x0066da94`
- Report-time classification: exact initialized global-data storage child for the FpsPane diagnostics source global.
- Report-time tracker row: `auto-generated/-ag-research-tracker.md` lists UID00027E at `86/88`, average `87.0`, reconstructable `true`, reports `0`, path `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`.

## Current Target State

Current post-callback target state:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000JK`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JK`
- Blank optional position
- Formal `RECONSTRUCTION_CPP CODE` contains the covered-by/no-duplicate marker:

```cpp
// Exact four-byte storage is emitted by UID0000PY g_fpsDebugActive; this by-memory child records bytes/xrefs only and emits no duplicate definition.
```

Historical pre-callback state: the target page was `86/88` with a blank formal block, which conflicted with its nonblank emitter route and score over the source-entry gate. Generated `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` emitted [UID:0000PY] as:

```cpp
// UID:0000PY | by-global/g_fpsDebugActive.md | Completion:88 | Confidence:89
int g_fpsDebugActive = 1;
```

The pre-callback generated file then emitted [UID:00027E] as:

```cpp
// UID:00027E | by-memory\0x0066da90-0x0066da94.g_fpsDebugActive.md | Completion:86 | Confidence:88 | Empty Emitter Marker
```

That empty marker was the source-quality defect for this exact-storage page. Post-callback generated `FpsPane.cpp` now has validator header `validator-command-id: 000000006472`, `validator-refreshed-at: 2026-07-04T19:11:45-04:00`, and emits:

```cpp
// UID:00027E | by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md | Completion:88 | Confidence:90
// Exact four-byte storage is emitted by UID0000PY g_fpsDebugActive; this by-memory child records bytes/xrefs only and emits no duplicate definition.
```

## Executive Recommendation

Accepted implementation applied a narrow target repair and light support synchronization:

- UID00027E was updated to `88/90`, with owner/reconstructable/emitter kept as `0000JK`/true/`0000JK`.
- The exact formal covered-by marker from this report was inserted into UID00027E.
- By-global [UID:0000PY] remains the only source declaration body for `int g_fpsDebugActive = 1;`.
- UID00027E and [UID:0000PY] now distinguish the source-facing documentation/generator name `g_fpsDebugActive` from the current MCP session's raw IDB label `dword_66DA90`.
- `by-file/FpsPane.md` and `by-class/FpsPane.md` were inspected and left unchanged because they already contain same-or-greater declaration/source-route evidence and do not present UID00027E as the current empty-emitter state.

## Supervisor Active Recheck

Current live MCP evidence is sufficient for Gate 1. Supervisor confirmed session `ddf5b602`; B005 rechecked the active session, health, target bytes, target xrefs, raw helper disassembly, text searches, pointer/immediate searches, decompile status, and local/generated documentation. No fallback-only conclusion is used.

## Inference Research Guidance Check

This target is a small initialized-data object, but it still needs a source-quality disposition because it is reconstructable, has a nonblank emitter, and appears in generated output as an empty emitter marker. The correct fix is not a new aggregate, split, or duplicate source declaration. The direct by-memory page is an exact storage/evidence child; the semantic by-global page is the source declaration route.

The adjacent [UID:0001OG][g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md) page already uses the local project pattern:

```cpp
// Exact two-byte storage is emitted by UID0000SU g_screenWidth; this by-memory child records bytes/xrefs only and emits no duplicate definition.
```

UID00027E should use the same covered-by marker pattern with [UID:0000PY].

## Heuristic / Inference Reanalysis And Validation

The prior blocker was "blank final C++ while declaration type/raw helper boundaries remain open." That blocker is now overbroad. The exact storage type is a four-byte initialized dword, the source owner is FpsPane diagnostics, and [UID:0000PY] already emits the declaration. The remaining unresolved facts are exact original spelling and whether the raw helper bodies at `0x004b64a0`/`0x004b69b0` were directly callable source methods or retained helper bodies. Those are confidence caps, not reasons to leave UID00027E as an empty emitter.

The correct source-quality distinction is:

- [UID:0000PY] emits the semantic source declaration `int g_fpsDebugActive = 1;`.
- [UID:00027E] records the exact memory storage, value, xrefs, and boundaries, and emits only a formal covered-by marker to prevent duplicate definitions.
- FpsPane methods [UID:00015F] and [UID:00015I] consume/clear the global in their formal source bodies.

## Evidence Standards Used

- Current IDA MCP evidence is mandatory and must be session-backed. Evidence in this report uses restored session `ddf5b602`.
- Broad/unbounded MCP calls were avoided. B005 used bounded/specific calls: `idb_list`, `server_health`, `lookup_funcs` on exact addresses, `get_global_value` for exact symbols/addresses, `get_bytes` for 4/16/32 byte windows, `xref_query`/`xrefs_to` on exact addresses, scoped `search_text` over `0x004b6400-0x004b6b00`, exact `find`/`find_bytes`, bounded `disasm`, and targeted `decompile`.
- Older reports are treated as leads. Storage, xref, naming, generated-output, and no-duplicate claims were revalidated against current docs and MCP session `ddf5b602`.

## Evidence Checked

Current MCP session `ddf5b602` facts:

- `idb_list`: active session `ddf5b602`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker, worker PID `20820`.
- `server_health`: status `ok`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; image base `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready.
- `lookup_funcs 0x0066da90`: not a function.
- `lookup_funcs` around FpsPane diagnostics: `0x004b6470` is `sub_4B6470` size `0x29`; `0x004b67b0` is `sub_4B67B0` size `0xfb`; `0x004b68b0` is `sub_4B68B0` size `0x100`; `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` are not modeled functions.
- `get_global_value 0x0066da90`: `0x1`.
- `get_global_value dword_66DA90`: `0x1`.
- `get_global_value g_fpsDebugActive`: not found in the current session.
- `get_bytes 0x0066da90 size 4`: `01 00 00 00`.
- `get_bytes 0x0066da88 size 32`: `58 00 3a 00 5c 00 00 00 01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00`.
- `xref_query 0x0066da90`: exactly four data refs: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, `0x004b6acd`.
- Scoped `search_text dword_66DA90` over `0x004b6400-0x004b6b00`: same four rendered refs, with compares at `0x004b64e5` and `0x004b69bd`, clears at `0x004b65f5` and `0x004b6acd`.
- `find` data references to `0x0066da90`: same four refs.
- `find_bytes 90 DA 66 00`: operand bytes only at `0x004b64e7`, `0x004b65f7`, `0x004b69bf`, `0x004b6acf`.
- `find_bytes 90 DA 26 00`: no matches, so no RVA-style pointer route was found.
- `xref_query g_fpsDebugActive`: failed to resolve under the current session name catalog.
- `list_globals`/`entity_query` around the address did not return a cataloged `g_fpsDebugActive` symbol, reinforcing that the current session label is raw `dword_66DA90` even though source docs and generated C++ use `g_fpsDebugActive`.

Historical/current doc facts rechecked:

- B003 diagnostics report records `.data:0066DA90 dword_66DA90 dd 1` and recommends `int g_fpsDebugActive = 1`.
- B003 records UID00027E as owner/emitter [UID:0000JK] with final declaration through FpsPane diagnostics.
- B008 records [UID:00015F] `FpsPane::UpdateFpsLogSession` as the source method consuming/clearing `g_fpsDebugActive`.
- B002 records [UID:00015I] `FpsPane::StartLogSession()` consuming and clearing the same global while keeping the no-function/no-route state as a confidence cap.
- `by-global/g_fpsDebugActive.md` already contains formal source code `int g_fpsDebugActive = 1;`.
- `by-file/FpsPane.md` includes `int g_fpsDebugActive = 1;` in draft declarations and keeps FpsPane diagnostics as the source route.
- `project-level/-resolved.md`, `wave3_data_issues.md`, C001 notes, and Supervisor notes preserve the older saved-rename story (`dword_66DA90` to `g_fpsDebugActive`); current session `ddf5b602` makes that a historical naming fact rather than current live-IDB truth.
- B001/B004 neighboring-global reports treat `0x0066da90` as a localized FpsPane diagnostics negative control, which supports rejection of address-cluster ownership for the nearby display/movement globals.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C-00027E-001 | UID00027E is exact four-byte initialized storage at `0x0066da90-0x0066da94` with value `1`. | High | MCP `get_bytes`/`get_global_value`; B003 `.data:0066DA90 dword_66DA90 dd 1`; target page. | `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` summary/evidence | Apply current-session evidence and score raise. | applied: target evidence now records `ddf5b602`, exact bytes/value, and score `88/90`; validator `000000006469` ok. |
| C-00027E-002 | The only direct refs to `0x0066da90` are four FpsPane diagnostics compare/clear sites. | High | MCP `xref_query`, `xrefs_to`, scoped `search_text`, `find` all return `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, `0x004b6acd`. | Target evidence; by-global use table; FpsPane diagnostics support. | Apply exact refs and roles. | applied: target and by-global support both list the four refs and compare/clear roles; validators `000000006469` and `000000006470` ok. |
| C-00027E-003 | Current IDB session `ddf5b602` resolves `dword_66DA90`, not `g_fpsDebugActive`; `g_fpsDebugActive` remains a source-facing doc/generator name. | Medium-high | MCP `get_global_value g_fpsDebugActive` fails; `get_global_value dword_66DA90` succeeds; docs/generated C++ use `g_fpsDebugActive`. | Target evidence; `by-global/g_fpsDebugActive.md`; support caveat. | Historicalize "current IDB label is g_fpsDebugActive" wording; preserve source-facing name. | applied: target and by-global now state current MCP raw `dword_66DA90` and preserve `g_fpsDebugActive` as source-facing name. |
| C-00027E-004 | [UID:0000PY] already emits the declaration `int g_fpsDebugActive = 1;`; UID00027E must not duplicate it. | High | `by-global/g_fpsDebugActive.md` formal code; generated FpsPane.cpp UID0000PY lines. | Target reconstruction notes/formal block; by-file FpsPane source structure. | Insert covered-by marker on UID00027E, keep declaration on UID0000PY. | applied: by-global formal declaration unchanged; target formal block contains only the covered-by marker. |
| C-00027E-005 | Pre-callback UID00027E appeared as an empty emitter marker in generated FpsPane.cpp. | High | Pre-callback `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` contained UID00027E empty marker after UID0000PY declaration; post-callback generated output is refreshed. | Target reconstruction block and score rationale. | Replace blank block with exact formal marker. | applied: generated FpsPane.cpp final header is `000000006472` and now emits UID00027E covered-by comment with no UID00027E empty marker. |
| C-00027E-006 | FpsPane [UID:0000JK] remains the correct owner/emitter route; ParcelPane, FolderSelect, screen-size/Application, MapPane, and no-owner alternatives are rejected. | High | All four refs are FpsPane diagnostics; by-file FpsPane docs; adjacent data xrefs go to distinct owners; generated source route is FpsPane.cpp. | Target ownership/rejected alternatives; support docs if stale. | Keep `CANONICAL_OWNER:0000JK`, `EMITTER_UIDS:0000JK`. | applied/already-present: target keeps owner/emitter `0000JK`; by-file/by-class already record FpsPane route and rejected non-FpsPane owners at same-or-greater detail. |
| C-00027E-007 | Score should move from `86/88` to `88/90` after current MCP and formal-marker repair. | Medium-high | Exact current session evidence, no-duplicate formal route, generated empty marker resolved; remaining cap is original spelling/type and raw-helper route. | Target metadata and score rationale. | Apply `COMPLETION:88`, `CONFIDENCE:90`. | applied: target metadata is `COMPLETION:88`, `CONFIDENCE:90`; validator `000000006469` recorded completion/confidence updates. |
| C-00027E-008 | Support docs need only targeted sync: by-global current-IDB-label caveat and FpsPane source route/no-duplicate marker if stale. | Medium-high | Current docs already carry declaration and source route but stale "current IDB label" wording exists. | `by-global/g_fpsDebugActive.md`, `by-file/FpsPane.md`, `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`. | Edit only if stale during callback; otherwise mark already-present. | applied/already-present: by-global updated for `ddf5b602` raw-label caveat and UID00027E covered-by role; by-file/by-class left unchanged as already-present; aggregate diagnostics doc not edited because it does not contradict this callback. |

## Positive Evidence Summary

- The exact data bytes at `0x0066da90-0x0066da94` are `01 00 00 00`, matching B003's local export `dword_66DA90 dd 1`.
- The four refs are exactly confined to FpsPane diagnostics start/update paths: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, `0x004b6acd`.
- The two compare refs gate the FPS debug/log session startup path; the two write refs clear the flag after the session handling path.
- The predecessor bytes at `0x0066da88-0x0066da90` are the FolderSelect drive-root buffer `X:\`, and successor bytes at `0x0066da94` begin the screen-width/global display cluster; their xref sets differ from UID00027E.
- FpsPane docs and generated output already route the source global through `NexusTK/ui/diagnostics/FpsPane.cpp`.
- The by-global declaration page already emits the source definition, so the by-memory page has an established covered-by route.

## IDA MCP Facts

MCP session: `ddf5b602`.

Bounded MCP call results:

- Target global value: `0x0066da90 == 1`.
- Current session raw label: `dword_66DA90`.
- Current session source-facing label lookup: `g_fpsDebugActive` not found.
- Target bytes: `01 00 00 00`.
- Neighbor bytes: `58 00 3a 00 5c 00 00 00 01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00`.
- Direct refs: four data refs only.
- VA operand byte matches for `0x0066da90`: four matches at operand locations only.
- RVA byte matches for `0x0026da90`: none.
- `lookup_funcs` confirms the data address is not a function.
- `decompile 0x004b64a0` and `decompile 0x004b69b0` fail because those raw starts are not modeled functions in the current IDB.

## Function / Child Inventory

| Range / address | Current role | UID / doc | Current relevance to UID00027E |
|---|---|---|---|
| `0x0066da90-0x0066da94` | Exact initialized global storage child | [UID:00027E][g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md) | Target. Should carry covered-by formal marker and source/evidence notes. |
| `0x0066da90` semantic global | Source declaration | [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) | Emits `int g_fpsDebugActive = 1;`; target must not duplicate it. |
| `0x004b64a0-0x004b67a7` | Raw `FpsPane::UpdateFpsLogSession(bool)` source body | [UID:00015F](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) | Reads and clears UID00027E. No modeled function in current IDB remains a liveness cap only. |
| `0x004b69b0-0x004b6adc` | Retained/private `FpsPane::StartLogSession()` helper | [UID:00015I](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) | Reads and clears UID00027E. No modeled function/caller route remains a liveness cap only. |
| `0x0066da88-0x0066da90` | FolderSelect drive-root buffer | [UID:00027D](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) | Predecessor only; different owner/xrefs. |
| `0x0066da94-0x0066da96` | Exact storage child for `g_screenWidth` | [UID:0001OG](by-memory/0x0066da94-0x0066da96.g_screenWidth.md) | Successor only; different owner/xrefs and already uses covered-by marker pattern. |

## Direct Xref / Caller Inventory

Current session `ddf5b602` direct refs to `0x0066da90`:

| Ref | Instruction role | Source interpretation |
|---|---|---|
| `0x004b64e5` | `cmp dword_66DA90, 0` | `UpdateFpsLogSession` checks whether startup/new-client FPS log handling should run. |
| `0x004b65f5` | `mov dword_66DA90, 0` | `UpdateFpsLogSession` clears the pending flag after session/file handling. |
| `0x004b69bd` | `cmp dword_66DA90, 0` | `StartLogSession` retained helper performs the same pending-start gate. |
| `0x004b6acd` | `mov dword_66DA90, 0` | `StartLogSession` retained helper clears the pending flag after writing startup information. |

No additional pointer/immediate/RVA route was found by exact byte searches. This supports a single data global used by FpsPane diagnostics, not a vtable, callback table, or broad data island.

## Documentation Evidence And IDA Status

The target page's existing evidence is directionally correct but stale in two important ways:

- It says the saved IDB rename to `g_fpsDebugActive` made that the current IDB label. Current session `ddf5b602` resolves `dword_66DA90` and does not resolve `g_fpsDebugActive`, so the saved-rename wording must be historicalized.
- It keeps final C++ blank to avoid duplicate output. That policy is correct, but a blank formal block now produces an empty emitter marker; a formal covered-by comment is the better final representation for this by-memory child.

The by-global page is source-correct in its formal declaration but should also receive the current-session naming caveat if edited during callback. The formal by-global declaration should remain:

```cpp
int g_fpsDebugActive = 1;
```

## Ranked Ownership Analysis

1. [UID:0000JK][FpsPane](by-file/FpsPane.md): accepted owner/emitter. All four direct refs are in FpsPane diagnostics code; the declaration is already generated in `NexusTK/ui/diagnostics/FpsPane.cpp`.
2. [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md): semantic declaration child/source anchor. It should remain the declaration emitter, while UID00027E remains exact storage evidence.
3. [UID:00005F][FpsPane](by-class/FpsPane.md): class context for the methods that read/clear the flag. It is not the direct by-memory emitter route, but it supports the owner.
4. ParcelPane / stale generated `class_ParcelPane.cpp` pollution: rejected. The refs, source route, and FpsPane diagnostics docs do not support ParcelPane ownership.
5. FolderSelectDialog: rejected. The predecessor buffer at `0x0066da88-0x0066da90` has a separate xref set and source role.
6. Application/screen-size globals: rejected. The successor width/height cluster has broad Application/layout consumers and no meaningful ref overlap with UID00027E.
7. MapPane/ObjectList/MainUiLayerSlots: rejected as owners. They are dependencies or neighboring/global families in diagnostics methods, not owners of this flag.
8. No-owner/non-emitting data: rejected. The storage is source-declared, reconstructable, owner-rooted, and already represented by by-global source output.

## Source Placement

The source placement remains `NexusTK/ui/diagnostics/FpsPane.cpp` through [UID:0000JK]. The global is best treated as a file/module global next to FpsPane diagnostics state:

```cpp
int g_fpsDebugActive = 1;
```

The spelling `g_fpsDebugActive` remains a source-facing project name rather than recovered original symbol proof. The target page should mention descriptive aliases (`g_fpsDebugSessionPending`, `g_fpsLogStartPending`) as naming context only, not as replacements.

## Range / Split / Padding / Reclassification Analysis

No split is needed. UID00027E is already an exact four-byte range:

- Predecessor [UID:00027D] ends exactly at `0x0066da90`.
- Target bytes occupy `0x0066da90-0x0066da94`.
- Successor [UID:0001OG] starts exactly at `0x0066da94`.

No range extension is justified. The target is not padding, not dead data, not a table fragment, and not part of the screen-width pair. The correct representation is exact storage child covered by semantic by-global declaration output.

## Negative Evidence Summary

- No current IDB function exists at `0x0066da90`; this is data, not a function.
- `g_fpsDebugActive` does not resolve as a current session IDB label under `ddf5b602`, so docs must not present it as the current live IDB symbol.
- No RVA pointer bytes for `0x0066da90` were found.
- No direct refs outside the four FpsPane diagnostics compare/clear sites were found.
- No evidence supports moving ownership to ParcelPane, FolderSelectDialog, Application/screen-size globals, MapPane, ObjectList, MainUiLayerSlots, or a free no-owner data bucket.
- Duplicating `int g_fpsDebugActive = 1;` in UID00027E would create duplicate source output because [UID:0000PY] already emits it.
- Leaving UID00027E blank with a nonblank emitter preserves the generated empty-emitter marker and fails the source-entry gate expectation for this target.

## IDA Rename / Type / Comment Recommendations

No IDA edits were performed during this report-only pass.

If a later IDA naming pass is authorized, it can reapply/check the data name `g_fpsDebugActive` at `0x0066da90`. The documentation should not depend on that current IDB label being present; source output can still use the project source-facing name because by-global and FpsPane source docs already converge on it. The type should remain a four-byte integer/dword in source until original declaration spelling or a stronger bool/int style proof is recovered.

## First-Draft C++ Recommendation

UID00027E is eligible for a formal block because it is reconstructable, has a nonblank emitter, and scores above the source-entry gate. It should not contain a duplicate declaration body. Insert this exact formal marker block into `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact four-byte storage is emitted by UID0000PY g_fpsDebugActive; this by-memory child records bytes/xrefs only and emits no duplicate definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not insert `int g_fpsDebugActive = 1;` into UID00027E. That declaration remains on [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md):

```cpp
int g_fpsDebugActive = 1;
```

## Final Recommendation

Repair UID00027E as an exact storage child with formal covered-by marker output, not as a second source definition. Raise the target to `88/90`, keep FpsPane owner/emitter route [UID:0000JK], keep reconstructable true, and update evidence to record current MCP session `ddf5b602`.

Support synchronization should be limited and evidence-driven: preserve [UID:0000PY]'s declaration, add the current raw-label caveat where stale "current IDB name" wording exists, and keep FpsPane source placement in `NexusTK/ui/diagnostics/FpsPane.cpp`.

## Recommended Target Doc Changes

For `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000JK`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000JK`.
- Keep optional position blank.
- Replace blank formal C++ with the exact covered-by marker block from this report.
- Update Item Summary to state that exact four-byte storage is covered by [UID:0000PY] declaration output and no longer remains a blank final-C++ target.
- Add current MCP session `ddf5b602` evidence: active session, health, raw label `dword_66DA90`, value `1`, bytes, exact four refs, scoped `search_text`, no `g_fpsDebugActive` current-label resolution, no RVA pointer matches, and no modeled function at the data address.
- Preserve B003 source declaration evidence and the pending debug/log-session start semantics.
- Historicalize stale C001 saved-IDB-rename wording: it is historical; current session `ddf5b602` does not expose `g_fpsDebugActive` as a live name.
- Preserve rejected owner alternatives: ParcelPane, FolderSelect predecessor, screen-width successor/Application display globals, MapPane/ObjectList dependencies, no-owner, padding/data-island-only.

## Recommended Support Doc Changes

Check/edit only where stale during callback:

- `by-global/g_fpsDebugActive.md`: keep formal `int g_fpsDebugActive = 1;`; add `ddf5b602` evidence that current MCP resolves raw `dword_66DA90`, not `g_fpsDebugActive`, while preserving `g_fpsDebugActive` as source-facing output name. Historicalize any line saying it is `g_fpsDebugActive` in the current IDB.
- `by-file/FpsPane.md`: already contains the correct source declaration and route. Add a short note only if stale wording fails to state that exact by-memory UID00027E is covered by [UID:0000PY] and must not duplicate the declaration.
- `by-class/FpsPane.md`: likely already sufficient. Edit only if it contradicts the global/source route or presents UID00027E as unresolved no-code rather than covered storage.
- `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`: likely already sufficient for raw helper/global use. Add the current session naming caveat only if stale support text says the live IDB name is `g_fpsDebugActive`.
- No generated files, coverage reports, validator state, lifecycle state, or supervisor ledgers should be edited by B005.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000JK
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JK
```

Rationale:

- Completion `88`: exact bytes/value, exact xrefs, boundaries, source route, generated output defect, no-duplicate source policy, and current MCP label caveat are all resolved at target level.
- Confidence `90`: ownership/storage/use evidence is strong. Remaining caps are original source spelling/type style and raw helper liveness/no-function state for FpsPane logging helpers.
- Do not raise beyond `90` until the current IDB/source-name mismatch and original type/spelling are resolved.

## Open Questions With Attempted Resolution

- Original source spelling: unresolved. `g_fpsDebugActive` is accepted as the project source-facing/generator name; current MCP session `ddf5b602` exposes `dword_66DA90`.
- Exact source type: likely `int` because storage is a dword, generated declaration is `int`, and raw refs compare/write dword. A `bool` rewrite would be less binary-faithful and is not recommended.
- Raw helper liveness: unresolved as direct route evidence because `0x004b64a0` and `0x004b69b0` are not modeled functions in the current session. This remains a confidence cap for helper methods, not a blocker to the global storage/declaration route.
- Why UID00027E still had no direct B report: older A/C and aggregate B passes covered storage and support evidence, but no direct UID00027E B report had resolved the nonblank-emitter/blank-formal generated empty-marker problem.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report edit is recommended for B005. Neither the initial report-only pass nor the implementation callback manually edited `by-memory/-coverage-report.md`, `by-global/-coverage-report.md`, generated tracker files, or any generated C++ file.

If supervisor policy later requires manual coverage text after implementation, use the updated target summary facts rather than the stale manual row that still describes blank final C++. Suggested content:

```text
FpsPane diagnostics startup/restart flag with current MCP-confirmed four-byte value 1, exact FolderSelect/screen-width boundaries, four FpsPane compare/clear refs, source declaration covered by [UID:0000PY] `int g_fpsDebugActive = 1`, formal covered-by marker on the exact storage child, current-session raw `dword_66DA90` label caveat, and rejected ParcelPane/adjacent-data/no-owner alternatives.
```

## Follow-Up Actions

Implementation callback follow-up is complete. B005 leased only the target and stale by-global support page for the edit/validator batch, applied the accepted details, ran scoped validators, confirmed generated `FpsPane.cpp` refreshed to the UID00027E covered-by marker, and released the leases. Supervisor-only remaining action is Gate 2 verification and, if accepted, `execute_report`.

## Confidence

Overall report confidence: high.

The storage/value/xref/boundary evidence is exact and current-session backed. The only reason confidence is not final-audit level is the mismatch between project source-facing name and current IDB label plus the retained no-function status of raw FpsPane helper starts. Those caps do not justify leaving UID00027E as a blank formal emitter.

## Validator Results

Implementation callback scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id / timestamp | Exit / ok | Warnings/errors | Generated refresh / side effects |
|---|---|---|---|---|---|
| `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` | `python .\tools\validator.py --mode file --file by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md --apply --queue-timeout 240` | `000000006469` / `2026-07-04T19:11:01-04:00` | `exit=0`, `ok: 1` | warnings `0`, errors `0` | `generated_refresh: deferred`; recorded `completion_update 00027E ... 88`, `confidence_update 00027E ... 90`, `autogen_registry_update` hash, `autogen_registry_update blank -> block`, `projected_stats_update`, `stats_incremental_noop`. |
| `by-global/g_fpsDebugActive.md` | `python .\tools\validator.py --mode file --file by-global/g_fpsDebugActive.md --apply --queue-timeout 240` | `000000006470` / `2026-07-04T19:11:08-04:00` | `exit=0`, `ok: 1` | warnings `0`, errors `0` | `generated_refresh: deferred`; recorded `reference_index_add 00027E`, `stats_row_update 0000PY`, and `projected_stats_update`. |

Generated freshness/read-only follow-up:

- Final `python .\tools\validator.py --queue-status` returned command `000000006481` at `2026-07-04T19:15:26-04:00`, exit `0`, with `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` header now reports `validator-command-id: 000000006472`, `validator-refreshed-at: 2026-07-04T19:11:45-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- The generated file now emits [UID:00027E] at `Completion:88 | Confidence:90` with the covered-by comment. The old UID00027E empty-emitter marker is gone. Other unrelated FpsPane empty markers remain outside this callback scope.

## Changed Files

Report/callback files:

- `tools/leaser/Agents/Agent-B005/research/00027E-g_fpsDebugActive-source-quality.md`
- `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`: edited under B005 lease; metadata changed to `88/90`, formal covered-by marker inserted, current `ddf5b602` evidence and no-duplicate policy added.
- `by-global/g_fpsDebugActive.md`: edited under B005 lease; declaration preserved, current `ddf5b602` raw-label caveat and UID00027E covered-by/no-duplicate role added.
- `by-file/FpsPane.md`: inspected, not edited; already contains `int g_fpsDebugActive = 1;` draft declaration and source route through [UID:0000JK].
- `by-class/FpsPane.md`: inspected, not edited; already records FpsPane helper/global use and source route at same-or-greater detail.

Validator-generated side effects observed, not manually edited by B005:

- `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` refreshed to command `000000006472` and now contains the UID00027E covered-by marker.
- Validator output reported projected stats/registry/reference-index updates as listed in `Validator Results`.

No manual generated files, coverage reports, validator state files, lifecycle/archive files, or supervisor ledgers were edited by B005. No report move/archive/lifecycle command was run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read Agent-B005 goal for UID00027E and confirmed report-only boundaries.
- [x] Used project B-agent workflow and required Medium provenance headers.
- [x] Searched current target/support docs for UID00027E, `g_fpsDebugActive`, `dword_66DA90`, `0x0066da90`, FpsPane diagnostics, generated output, tracker state, and adjacent globals.
- [x] Searched executed B-agent reports for FpsPane diagnostics, UpdateFpsLogSession, StartLogSession, WriteLogSummary, UID00027E, and source declaration evidence.
- [x] Rechecked MCP evidence under current session `ddf5b602` with narrow, bounded calls.
- [x] Reanalyzed owner/emitter route and rejected ParcelPane, FolderSelect, screen-size/Application, MapPane/ObjectList, no-owner, padding, and duplicate-declaration alternatives.
- [x] Resolved the source-quality blocker: UID00027E should use a formal covered-by marker, while [UID:0000PY] keeps the declaration.
- [x] Included exact formal `RECONSTRUCTION_CPP CODE` insertion text.
- [x] Included score/metadata recommendation and target/support doc changes.
- [x] Did not edit by-* docs, generated files, coverage reports, validator state, lifecycle state, archives, or supervisor ledgers.
- [x] Did not run validators, `execute_report`, lifecycle commands, or archive/report moves.

Implementation callback checklist:

- [x] Lease `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`, apply metadata `88/90`, keep owner/reconstructable/emitter route, insert formal covered-by marker, and add current MCP evidence.
  - Proof: B005 lease succeeded; target now has `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter `0000JK`, formal marker comment, `ddf5b602` bytes/value/xref/raw-name evidence, adjacent-global separation, and no duplicate declaration policy. Validator `000000006469` exited `0`, `ok: 1`.
- [x] Inspect `by-global/g_fpsDebugActive.md`; if stale, add current-session raw-label caveat while preserving formal declaration.
  - Proof: B005 lease succeeded; by-global formal `int g_fpsDebugActive = 1;` remains unchanged, while status/evidence now record current MCP raw `dword_66DA90`, failed `g_fpsDebugActive` symbol resolution, exact bytes/value, four refs, no RVA pointer route, and UID00027E covered-by role. Validator `000000006470` exited `0`, `ok: 1`.
- [x] Inspect `by-file/FpsPane.md`, `by-class/FpsPane.md`, and `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`; edit only if they contradict the covered-by/no-duplicate route or current-session naming caveat.
  - Proof: `by-file/FpsPane.md` already contains the module global declaration block with `int g_fpsDebugActive = 1;`, no-duplicate by-global declaration routing, and FpsPane source-root evidence; no edit. `by-class/FpsPane.md` already records FpsPane helper/global use, raw-helper confidence caps, and `g_fpsDebugActive` as explicit initialized storage; no edit. Aggregate diagnostics support already routes globals through FpsPane children and does not contradict the covered-by storage-child repair; no edit.
- [x] Run scoped validators for each changed by-* file with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`.
  - Proof: target validator `000000006469` / `2026-07-04T19:11:01-04:00` and by-global validator `000000006470` / `2026-07-04T19:11:08-04:00` both exited `0`, `ok: 1`, warnings `0`, errors `0`.
- [x] Record validator command IDs, timestamps, exit codes, ok counts, warnings, generated refresh/freshness state, and final lease release state in this report.
  - Proof: `Validator Results` records both scoped validators plus queue-status/generated freshness. `Changed Files` records the edited files and generated refresh observation.
- [x] Release leases immediately after edit/validator batch.
  - Proof: `python leaser.py Agent-B005 unlease ...` succeeded for both target and by-global support page after validators.
- [x] Do not edit generated output, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.
  - Proof: no manual edits were made to generated files, coverage reports, validator state files, lifecycle/archive files, or supervisor ledgers. Validator-owned generated refresh and projected-stat side effects are reported, not manually edited.
- [x] Stop at the supervisor-requested checkpoint and do not run `execute_report`.
  - Proof: no `execute_report`, dry-run/probing execute variant, registry lifecycle command, report move, or archive command was run. This artifact is ready for supervisor Gate 2 / execute decision.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000006504","destination_path":"executed-b-agent-research/B005/00027E-g_fpsDebugActive-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00027E-g_fpsDebugActive-source-quality.md","timestamp":"2026-07-04T19:23:08-04:00","uid":"00027E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
