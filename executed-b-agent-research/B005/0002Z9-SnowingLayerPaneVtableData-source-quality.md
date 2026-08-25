** TARGET-REPORT-UID:0002Z9 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002Z9 SnowingLayerPaneVtableData Source-Quality Report


Report timestamp: `2026-07-05T17:41:14-04:00`
Implementation callback timestamp: `2026-07-05T17:57:25-04:00`

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:0002Z9] `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md` as a target-only evidence and score refresh.
- Final disposition: keep UID0002Z9 as source-declared/generated-binary `SnowingLayerPane` RTTI/vtable support, directly owned and emitted through [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md).
- Required action: raise target metadata from `85/90` to `88/92`, preserve `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the existing no-hand-authored-vtable formal marker.
- Confidence: high for class ownership, range boundaries, vtable slots, generated route, and no-standalone-array disposition; below final-audit quality because no local UDT/header source or original `WeatherLayerPane.cpp` versus dedicated `SnowingLayerPane.cpp` source split proof exists.

## Supporting Research

- Lifecycle/status notes: Gate 1 passed and the supervisor approved a target-only implementation callback for this exact report. During callback, B005 edited only the target by-memory doc and this report; no support by-* docs, coverage reports, lifecycle/archive files, supervisor ledgers, manual generated files, or IDA DB state were edited. The scoped validator produced validator-owned generated/state side effects recorded below.
- MCP requirement: satisfied using active MCP database/session `supervisor_recovery_20260705`.
- MCP health: `status:"ok"`, `idb_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Existing report searches were performed with `0002Z9`, `0x006312ac`, `SnowingLayerPaneVtableData`, `SnowingLayerPane vtable`, `WeatherLayerPane empty-emitter`, `0002Z8`, and `0002ZA`. Relevant opened reports were executed B001 `000270`, executed B001 `0001O1`, executed B008 `0000P8`, executed B012 `0001O0`, and active sibling B004 `0002Z7`; no prior direct UID0002Z9 B report was found.

## Target

- Target UID: `0002Z9`
- Target path: `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` by-memory Not-Covered Files - Reconstructable row at `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: xHigh report-only source-quality research for a reconstructable by-memory vtable data page.
- Current scores and parent state: report-time target was `85/90`; callback target is now `88/92`. Direct parent [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) remains `86/88`, reconstructable, and emits through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md).

## Current Target State

- Pre-callback metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
- Callback metadata now applied: `COMPLETION:88`, `CONFIDENCE:92`, with `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the formal marker preserved exactly.
- Existing owner/emitter/reconstructable state: direct class owner/emitter [UID:0000DC] is correct; the route reaches [UID:0000P8] and current generated `auto-generated/NexusTK/map/WeatherLayerPane.cpp`.
- Existing C++/emitter state: formal C++ contains the intentional marker `// SnowingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.`
- Callback-resolved body gaps: target prose now carries current session evidence, full adjusted COL coverage, current pointer-search negatives, no local UDT/source-string negatives, generated-route freshness, and the `0x00631300` / `0x00631330` adjusted complete-object-locator dwords.
- Related target/support docs checked: Waitable/weather aggregate, Weather/Raining/Snowing/Swallow class and file docs, WaitableTimer boundary docs, predecessor [UID:0002Z8], successor [UID:0002ZA], Snowing method index/constructor/update/randomize/render/destructor children, generated tracker/coverage/source, and relevant executed reports.
- Current artifact/lifecycle status: report artifact is active under `tools/leaser/Agents/Agent-B005/research/`; Gate 1 passed, callback implementation is complete, and the report awaits supervisor Gate 2 review. It has not been executed or archived.

## Executive Recommendation

UID0002Z9 should remain an exact reconstructable vtable-data child. It should not be converted to `RECONSTRUCTABLE:FALSE`, because this is not the broad mixed `.rdata` aggregate; it is the exact `SnowingLayerPane` source-declared/generated-binary support range generated by the class declaration and virtual method set.

Recommended implementation is target-only:

- set `COMPLETION:88`;
- set `CONFIDENCE:92`;
- preserve all owner/emitter/reconstructable fields and the existing formal marker;
- update the target body with current MCP session `supervisor_recovery_20260705`, full key dword/slot inventory, constructor/decompiler facts, boundary proof, pointer/type/source-string negative checks, generated route proof, rejected alternatives, and no-standalone-array proof.

No support-doc edits are required. The support docs already carry same-or-greater source-placement context: [UID:0000DC] has `[[CHILDREN]]`, [UID:0000P8] records the weather-layer family route, [UID:000270] records this as the exact Snowing vtable child, and generated `WeatherLayerPane.cpp` already contains UID0002Z9's marker.

## Supervisor Active Recheck

- Current supervisor instruction approved a target-only implementation callback for UID0002Z9 after Gate 1 passed. No support-doc edits were authorized or needed.
- The assigned item does not require split repair. The exact half-open range `0x006312ac-0x0063133c` is already split from [UID:000270]; predecessor [UID:0002Z8] ends at `0x006312ac`, and successor [UID:0002ZA] starts at `0x0063133c`.
- Every source-bearing child needed to support this vtable is already documented: constructor [UID:0003O0], update/render [UID:0003O1], randomize [UID:0003O2], render [UID:0003O3], scalar deleting destructor [UID:0003O4], and Snowing class [UID:0000DC].

## Inference Research Guidance Check

- `by-structure.md` classifies vtables as `source-declared/generated-binary`: the source declaration/virtual method shape must be reconstructed, while raw RTTI/vtable bytes should be regenerated by the compiler/linker.
- The direct semantic owner rule favors [UID:0000DC] `SnowingLayerPane`, not the weather-family file page, mixed `.rdata` aggregate, or adjacent Raining/Swallow siblings.
- Existing documentation assumptions were rechecked rather than copied: the old B008 marker is valid, but current MCP adds adjusted COL dwords, pointer/type/source-string negatives, and generated-route proof.
- Wave2/Wave3/simroot output was treated only as historical/lead context where it appears in docs; the recommendation is based on current by-* docs and current IDA MCP evidence.

## Heuristic / Inference Reanalysis And Validation

- Owner/source-quality issue: whether the page should stay with [UID:0000DC] or move to a file/aggregate/no-owner state. Current decorated names, constructor vptr stores, and vtable method slots validate the direct class owner.
- Rebuild-handling issue: whether exact vtable bytes should be source code. Current `by-structure.md` and B008 precedent validate the no-hand-authored-array marker. The source-bearing reconstruction lives on the class/method pages, not this `.rdata` table page.
- Score blocker: current page has only compact 2026-06 evidence. Current MCP now verifies the range bytes, three COL/vtable views, vptr stores, virtual method slots, destructor thunks, shared timer slot, successor boundary, pointer-search negatives, no local UDT, no source-file/PDB string proof, and generated marker route. That supports a score lift to `88/92`.
- Source-placement blocker: final one-file `WeatherLayerPane.cpp` versus dedicated `SnowingLayerPane.cpp` remains unresolved. This is a confidence cap, not a target owner/emitter blocker, because UID0002Z9 already routes through [UID:0000DC] to the current weather-family source root and generated output contains the marker.
- Rejected alternatives: raw vtable array/global, `RECONSTRUCTABLE:FALSE`, broad [UID:000270] owner, file-only owner [UID:0000P8] or [UID:0000NR], no-owner/non-emitting, Raining/Swallow/Waitable ownership, and forcing source-file split based on class names alone.
- Unresolved issue remaining: no local IDA UDT or source-path string proves the final header/source split. This caps confidence below final-audit levels but does not block the target-only evidence refresh.

## Evidence Standards Used

- Current IDA MCP evidence: `idb_list`, `server_health`, `get_bytes`, `get_int`, `entity_query`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `type_query`, `disasm`, and `decompile`, all with exact addresses and bounded limits.
- Documentation evidence: target/support by-* docs, generated source/tracker/coverage rows, and search-gated executed reports.
- Negative evidence: zero xrefs to COL/raw boundary cells where expected, pointer-byte scans for VA/RVA patterns, zero local IDA type rows for Snowing/WeatherLayerPane, and no `.cpp`/`.pdb` source string hits beyond RTTI class strings.
- Evidence strength: strong enough for target metadata and no-code marker confidence because binary facts directly identify class-specific RTTI/vtables and stores. Not strong enough for 95+ scores or final header/source split claims.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` found one active session `supervisor_recovery_20260705`.
  - `server_health` returned ready status with Hex-Rays and strings cache available.
  - `get_bytes 0x006312a4 size 160` covered the Raining adjusted-tail, full UID0002Z9 range, and Swallow successor start.
  - `get_int` checked key dwords from `0x006312a4` through `0x00631340`; conversions for quoted decimal values were verified with `tools/int_convert.py`.
  - `entity_query kind=names` over `0x006312a0-0x00631344` and `0x00654060-0x00654190` found Snowing vtable names and RTTI names.
  - `xrefs_to` checked target boundaries, vtable bases, slot target functions, constructor, thunks, destructor, and shared timer handler.
  - `lookup_funcs` checked Snowing constructor/method/destructor/thunk and Weather/Swallow boundary functions.
  - `find_bytes` checked VA/RVA pointer patterns for target start, vtable bases, timer cell, and successor boundary.
  - `type_query` checked `*SnowingLayerPane*` and `*WeatherLayerPane*`.
  - `entity_query kind=strings` checked weather-layer class/source-path strings.
  - `disasm/decompile` checked `0x005c1bd0`, `0x005c29ec`, `0x005c2a20`, and `0x005c13b0`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target UID0002Z9; predecessor UID0002Z8; successor UID0002ZA; aggregate UID000270; WaitableTimer boundary UID0002P2; Weather/Raining/Snowing/Swallow class and file pages; exact Snowing method children; Snowing/Swallow aggregate/index pages.
  - Generated `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, `auto-generated/NexusTK/map/SnowingLayerPane.cpp`, `auto-generated/NexusTK/map/RainingLayerPane.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
  - Executed B001 `000270`, executed B001 `0001O1`, executed B008 `0000P8`, executed B012 `0001O0`, and active sibling B004 `0002Z7` as lead/context.
- Negative checks performed:
  - Zero xrefs to `0x006312ac`, `0x00631300`, `0x00631330`, `0x0063133c`, and table-cell addresses where no code stores are expected.
  - `find_bytes` found no VA pointer to raw target start, timer cell, or successor, and no RVA pointer pattern for target start/vtable bases/timer/successor; only constructor immediates for vtable bases `0x006312b0`, `0x00631304`, and `0x00631334` were found.
  - `type_query` returned no local IDA type catalog rows for SnowingLayerPane or WeatherLayerPane.
  - String regex returned only RTTI class strings and no source filename/PDB proof.
- Failed, unavailable, or intentionally skipped checks and why:
  - One initial `tools/int_convert.py` multi-number positional call returned an invalid-number data error; it was corrected with stdin JSON batch conversion.
  - No broad list/search/callgraph/batch analysis was run, in accordance with MCP output discipline.
  - During the report-only phase, no validator was run because no by-* docs were edited. Callback scoped validator results are recorded in `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002Z9-01 | UID0002Z9 should remain directly owned by [UID:0000DC] `SnowingLayerPane`. | xHigh / 0.94 | MCP names `??_7SnowingLayerPane@@6B@`, `_0`, `_1`; RTTI names; constructor stores at `0x005c1c0d`, `0x005c1c18`, `0x005c1c22`; slot xrefs to Snowing methods. | Target metadata and Assignment Decision | already-present | applied |
| C-0002Z9-02 | UID0002Z9 should remain `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:0000DC`. | xHigh / 0.91 | `by-structure.md` source-declared/generated-binary vtable rule; generated route present in `WeatherLayerPane.cpp`; exact child not broad aggregate. | Target metadata and Rebuild Handling And No-Standalone-Array Proof | already-present | applied |
| C-0002Z9-03 | Target score should move to `88/92`. | xHigh / 0.90 | Current MCP verifies bytes, dwords, xrefs, function facts, decompile/disasm facts, pointer negatives, type/source-string negatives, and generated marker route. | Target metadata and Score Rationale | incorporate | applied |
| C-0002Z9-04 | Target prose should document three Snowing COL/vtable views: primary, adjusted `_0`, and adjusted `_1`. | xHigh / 0.95 | `get_int`/`entity_query`: `0x006312ac -> 0x006540f8`, `0x00631300 -> 0x00654158`, `0x00631330 -> 0x0065416c`; names returned for `??_R4SnowingLayerPane@@6B@`, `_0`, `_1` (hex conversions verified with `tools/int_convert.py`). | Target Current IDA MCP Evidence / Observed Contents | incorporate | applied |
| C-0002Z9-05 | Target prose should document the primary vtable stores and adjusted vtable stores from the constructor. | xHigh / 0.94 | `xrefs_to 0x006312b0/0x00631304/0x00631334`; `disasm/decompile 0x005c1bd0` shows base constructor call, vtable stores, 200 particle initialization, and state setup. | Target Constructor And Slot Evidence / Assignment Decision | incorporate | applied |
| C-0002Z9-06 | Target prose should document key slots: destructor, render, update/render, randomize, thunks, and shared timer. | xHigh / 0.93 | `get_int`, `lookup_funcs`, and `xrefs_to`: `0x006312b0 -> 0x005c2a20`, `0x006312c0 -> 0x005c20e0`, `0x006312f4 -> 0x005c1c80`, `0x006312fc -> 0x005c1f50`, `0x00631304 -> 0x005c29ec`, `0x00631334 -> 0x005c29f7`, `0x00631338 -> 0x005c13b0`. | Target Observed Contents / Constructor And Slot Evidence | incorporate | applied |
| C-0002Z9-07 | Existing formal vtable marker is correct and should be preserved exactly; do not emit a raw vtable array. | xHigh / 0.93 | B008 accepted marker; MCP confirms compiler-generated vtable/COL data from class stores and method slots; generated source already contains marker. | Target formal C++ block / Rebuild Handling And No-Standalone-Array Proof | already-present | already-present |
| C-0002Z9-08 | Generated route is already fresh enough for this target: `WeatherLayerPane.cpp` contains UID0002Z9 marker under the Snowing class route. | xHigh / 0.90 | Generated header command `000000007143`, refreshed `2026-07-05T15:10:39-04:00`; generated file lines contain UID0002Z9 and marker. | Target Generated Route Proof and generated read-only check | incorporate | applied |
| C-0002Z9-09 | No support-doc edits are required for Gate 1 acceptance. | xHigh / 0.86 | [UID:0000DC] already has `[[CHILDREN]]`; [UID:0000P8] documents weather-family route; [UID:000270] documents exact child split; generated route already contains UID0002Z9 marker. | Recommended Support Doc Changes / callback scope | not-applicable | excluded-with-reason |
| C-0002Z9-10 | Reject conversion to `RECONSTRUCTABLE:FALSE`. | xHigh / 0.90 | Broad [UID:000270] is `FALSE`; exact vtable child remains source-declaration support required for rebuild. | Target Rejected Alternatives / Score Rationale | reject-invalid | applied |
| C-0002Z9-11 | Reject no-owner/non-emitting and broad aggregate ownership. | xHigh / 0.92 | Class-specific decorated names, constructor stores, vtable slots, and support class parent above gate prove owner/emitter route. | Target Rejected Alternatives / Assignment Decision | reject-invalid | applied |
| C-0002Z9-12 | Reject forced [UID:0000NR] dedicated `SnowingLayerPane.cpp` file route for this target. | xHigh / 0.84 | Dedicated file page remains plausible, but string checks found no `.cpp`/`.pdb` source-path proof; current generated route is [UID:0000P8]. | Target Source Placement / Rejected Alternatives | reject-stale | applied |
| C-0002Z9-13 | Preserve negative evidence: no local IDA UDT and no source filename/PDB string proof. | xHigh / 0.88 | `type_query` zero rows; string query returned only RTTI class strings. | Target Pointer, Type, And Source-String Negative Evidence / Source Placement | incorporate | applied |

Callback verification notes:

- C-0002Z9-01 through C-0002Z9-06: incorporated into `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md` headers and sections `Current IDA MCP Evidence`, `Observed Contents`, `Constructor And Slot Evidence`, `Assignment Decision`, and `Score Rationale`.
- C-0002Z9-07: already present in the formal C++ block before callback and preserved byte-for-byte; body proof was expanded under `Rebuild Handling And No-Standalone-Array Proof`.
- C-0002Z9-08: generated route proof incorporated into target body; read-only post-validator generated check found `WeatherLayerPane.cpp` refreshed to command `000000007285` with UID0002Z9 marker and no raw vtable array.
- C-0002Z9-09: excluded with reason because the accepted callback scope was target-only, support docs were not authorized for editing, and no concrete support drift was found during callback.
- C-0002Z9-10 through C-0002Z9-13: incorporated under `Rejected Alternatives`, `Pointer, Type, And Source-String Negative Evidence`, and `Source Placement`.

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - MCP names identify Snowing primary and adjusted vtable bases at `0x006312b0`, `0x00631304`, and `0x00631334`.
  - MCP RTTI names identify Snowing primary and adjusted complete-object-locator dwords at `0x006540f8`, `0x00654158`, and `0x0065416c`.
  - Constructor `sub_5C1BD0` stores all three Snowing vtable views and is called from `MapPane` weather setup at `0x0050dc17`.
  - Snowing virtual slots point to the Snowing destructor/method/thunk set; the shared timer slot points to `WeatherLayerPane` timer handler.
- Corroborating documentation/generated-report evidence:
  - [UID:0000DC] documents the Snowing class and includes `[[CHILDREN]]`.
  - [UID:0000P8] documents the weather-layer source-family route.
  - [UID:000270] documents UID0002Z9 as the exact Snowing vtable child.
  - Generated `WeatherLayerPane.cpp` contains the UID0002Z9 marker.
- Strongest inference chain and why it is sufficient:
  - Class-specific RTTI/vtable names plus constructor stores plus method slots prove direct class ownership. `by-structure.md` then decides rebuild handling: source declaration needed, raw array not hand-authored.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs`: `0x005c1bd0` `sub_5C1BD0` size `0xae`; `0x005c1c80` size `0x2cc`; `0x005c1f50` size `0x184`; `0x005c20e0` size `0x148`; `0x005c29ec`/`0x005c29f7` size `0xb`; `0x005c2a20` size `0x3b`; `0x005c13b0` size `0x58`; successor `0x005c2230` size `0x110`.
  - `decompile 0x005c1bd0` confirms base `sub_5C12A0` call, three Snowing vtable assignments, 200 particle-record initialization, state dword setup, and inherited visibility byte setup.
  - `disasm 0x005c1bd0` shows vtable stores at `0x005c1c0d`, `0x005c1c18`, and `0x005c1c22`.
  - `disasm 0x005c29ec` shows the adjusted thunk subtracting `0xa0` and jumping to `0x005c2a20`; `xrefs_to 0x005c2a20` also proves the sibling thunk at `0x005c29f7`.
  - `decompile 0x005c2a20` confirms the scalar deleting destructor wrapper calls base cleanup `0x00544580` and conditional delete helper `0x004f4ac0`.
  - `decompile 0x005c13b0` confirms the shared weather timer increments animation frame state, invalidates/repaints through virtual calls, reschedules the timer, and returns handled.
- Data/table/padding facts:
  - `get_bytes 0x006312a4 size 160` covers the Raining adjusted tail, all UID0002Z9 bytes, and the Swallow successor dwords.
  - `0x006312a4`/`0x006312a8` are predecessor Raining adjusted `_1` vtable/timer cells; `0x006312ac` begins Snowing; `0x0063133c` begins Swallow.
- Xref facts:
  - `xrefs_to 0x006312b0`: one constructor data xref at `0x005c1c0d`.
  - `xrefs_to 0x00631304`: one constructor data xref at `0x005c1c18`.
  - `xrefs_to 0x00631334`: one constructor data xref at `0x005c1c22`.
  - `xrefs_to 0x005c1bd0`: code xref from `0x0050dc17`.
  - `xrefs_to 0x005c1c80`, `0x005c1f50`, `0x005c20e0`, `0x005c29ec`, `0x005c29f7`, `0x005c2a20`, and `0x005c13b0` match the target slot cells.
  - `xrefs_to 0x00631340`: Swallow successor has constructor/destructor/deleting-destructor refs at `0x005c226d`, `0x005c2340`, and `0x005c2a66`.
- Vtable/global/type facts:
  - `entity_query kind=names` returned `??_7SnowingLayerPane@@6B@`, `??_7SnowingLayerPane@@6B@_0`, `??_7SnowingLayerPane@@6B@_1`, and matching RTTI names.
  - `type_query` for SnowingLayerPane and WeatherLayerPane returned zero rows, so no local IDA UDT is available as final header proof.
- Negative IDA facts:
  - No xrefs to COL dwords `0x006312ac`, `0x00631300`, `0x00631330`, or successor COL `0x0063133c`.
  - Pointer-byte scans found no VA/RVA raw-start or successor route; only expected constructor immediates for the three Snowing vtable bases.
  - String query found only RTTI class strings and no `.cpp`/`.pdb` source-path proof.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x006312ac-0x0063133c` | [UID:0002Z9] `SnowingLayerPaneVtableData` | Snowing RTTI/vtable data | TRUE | [UID:0000DC] | current `85/90`; recommend `88/92` | Target evidence refresh recommended |
| `0x005c1bd0-0x005c1c7e` | [UID:0003O0] `SnowingLayerPaneConstructor` | Constructor/vptr stores | TRUE | [UID:0000DC] | `86/88` | Already present support |
| `0x005c1c80-0x005c1f4c` | [UID:0003O1] `UpdateAndRenderSnowParticles` | Snow virtual method | TRUE | [UID:0000DC] | `88/89` | Already emits first-draft C++ |
| `0x005c1f50-0x005c20d4` | [UID:0003O2] `RandomizeSnowParticles` | Snow virtual method | TRUE | [UID:0000DC] | `88/89` | Blank C++ by accepted no-code proof |
| `0x005c20e0-0x005c2228` | [UID:0003O3] `RenderSnowParticles` | Snow virtual method | TRUE | [UID:0000DC] | `88/89` | Already emits first-draft C++ |
| `0x005c2a20-0x005c2a5b` | [UID:0003O4] `SnowingLayerPaneScalarDeletingDestructor` | Deleting destructor wrapper | TRUE | [UID:0000DC] | `85/88` | Already present support |
| `0x0063121c-0x006312ac` | [UID:0002Z8] `RainingLayerPaneVtableData` | Predecessor sibling | TRUE | [UID:0000BJ] | `85/90` | Boundary support only |
| `0x0063133c-0x006313cc` | [UID:0002ZA] `SwallowLayerPaneVtableData` | Successor sibling | TRUE | [UID:0000E9] | `85/90` | Boundary support only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006312b0` | `0x005c1c0d` in `sub_5C1BD0` | Primary Snowing vtable store. |
| `0x00631304` | `0x005c1c18` in `sub_5C1BD0` | Adjusted `_0` Snowing vtable store. |
| `0x00631334` | `0x005c1c22` in `sub_5C1BD0` | Adjusted `_1` Snowing vtable store. |
| `0x005c1bd0` | caller `0x0050dc17` in `sub_50DB50` | Map weather setup constructs the Snowing layer. |
| `0x005c2a20` | data xref `0x006312b0`, code xrefs `0x005c29f2`/`0x005c29fd` | Destructor slot and two adjustor thunks. |
| `0x005c20e0` | data xref `0x006312c0` | Render method slot. |
| `0x005c1c80` | data xref `0x006312f4` | Update/render method slot. |
| `0x005c1f50` | data xref `0x006312fc` | Randomize method slot. |
| `0x005c29ec` | data xref `0x00631304` | Adjusted destructor thunk slot. |
| `0x005c29f7` | data xref `0x00631334` | Adjusted destructor thunk slot. |
| `0x005c13b0` | data refs `0x00631218`, `0x006312a8`, `0x00631338` | Shared WeatherLayerPane timer handler in Weather/Rain/Snow tables. |
| `0x00631340` | `0x005c226d`, `0x005c2340`, `0x005c2a66` | Swallow successor vtable stores/restores; confirms successor boundary. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - UID0002Z9 already has correct direct owner/emitter metadata and no-hand-authored-vtable marker.
  - [UID:0000DC] records the constructor/method/destructor family, accepted helper mappings, and `[[CHILDREN]]` route.
  - [UID:0000P8] records the weather-layer source-family route under `NexusTK/map/`.
  - [UID:000270] records the mixed aggregate as non-emitting and maps UID0002Z9 as the Snowing vtable child.
  - [UID:0001O0] and [UID:0001O1] record the Snowing/Swallow code island as split/indexed rather than a broad source owner.
- Existing docs that are stale, incomplete, or contradicted:
  - UID0002Z9 lacks the current session evidence and adjusted COL dwords, but its owner/marker direction is not contradicted.
  - No support doc drift was found that requires report-first support edits.
- Generated/coverage report state:
  - `auto-generated/-ag-research-tracker.md` lists UID0002Z9 as `85/90`, reconstructable, reports `0`.
  - `auto-generated/-ag-coverage-report-by-memory.md` lists UID0002Z9 as `emits_code:true`, reconstructable, updated `2026-07-01 05:24:00`.
  - `auto-generated/NexusTK/map/WeatherLayerPane.cpp` command `000000007143`, refreshed `2026-07-05T15:10:39-04:00`, includes UID0002Z9 and its marker.

## Ranked Ownership Analysis

### 1. [UID:0000DC] SnowingLayerPane

- Evidence for: decorated vtable/RTTI names, constructor stores, MapPane weather constructor caller, Snowing method/destructor slots, support class above gate, and generated child route through the class.
- Evidence against: no local IDA UDT or source-path string proves final header file text, but this does not weaken direct class ownership.
- Decision: accepted and already present; preserve as `CANONICAL_OWNER` and `EMITTER_UIDS`.

### 2. [UID:0000P8] WeatherLayerPane file family

- Evidence for: current generated route surfaces Snowing class children into `auto-generated/NexusTK/map/WeatherLayerPane.cpp`; weather overlay family is map-state driven.
- Evidence against: file-family route is not the direct semantic owner of a concrete class vtable.
- Decision: accepted as source-family context only; do not change target canonical owner to [UID:0000P8].

### 3. [UID:0000NR] SnowingLayerPane dedicated file candidate

- Evidence for: dedicated by-file page exists and some snow data routes through it.
- Evidence against: current source/path string checks find no `.cpp`/`.pdb` proof; current class route uses [UID:0000P8].
- Decision: keep as future split candidate/support context; do not force route churn for UID0002Z9.

### 4. [UID:000270] WaitableWeatherReadOnlyData aggregate

- Evidence for: physical containment in the broad `.rdata` island.
- Evidence against: aggregate is mixed-owner, `RECONSTRUCTABLE:FALSE`, and explicitly delegates exact ownership to child pages.
- Decision: reject as canonical owner or emitter.

### 5. Adjacent Raining/Swallow/Waitable/Weather base classes

- Evidence for: adjacency and sibling weather-family patterns.
- Evidence against: predecessor Raining ends at `0x006312ac`; Swallow begins at `0x0063133c`; WaitableTimer/WeatherLayerPane own separate bands.
- Decision: reject.

### 6. No-owner/non-emitting or standalone global array

- Evidence for: COL boundary cells have no direct xrefs and raw vtable bytes are compiler-generated.
- Evidence against: class-specific constructor stores and method slots prove ownership; `by-structure.md` vtable handling requires source-declared/generated-binary reconstruction, not no-owner or handwritten array.
- Decision: reject.

## Source Placement

- Recommended source file/class/global/module placement: keep UID0002Z9 under [UID:0000DC] `SnowingLayerPane`; it routes through the current weather-layer source-family root [UID:0000P8] to `NexusTK/map/WeatherLayerPane.cpp`.
- Why this placement fits source-tree and subsystem context: MapPane weather setup constructs the concrete weather layers, and [UID:0000P8] remains the conservative source-family route for Weather/Raining/Snowing/Swallow until final file-split evidence appears.
- Rejected placements and why: direct [UID:0000P8] file ownership is too broad; [UID:0000NR] dedicated file placement remains plausible but unproven; aggregate [UID:000270] is a non-emitting inventory; adjacent Raining/Swallow/Waitable pages own separate ranges.
- Remaining placement uncertainty: exact original one-file versus per-layer file split is unresolved. Current string and type checks did not recover source-path/PDB/header proof.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - UID0002Z9 remains `0x006312ac-0x0063133c`.
  - Predecessor [UID:0002Z8] includes Raining adjusted `_1` table ending with `0x006312a4 -> 0x0049af1c` and `0x006312a8 -> 0x005c13b0`.
  - `0x006312ac` begins Snowing RTTI/COL data.
  - `0x0063133c` begins Swallow RTTI/COL data; `xrefs_to 0x00631340` confirms successor Swallow stores/restores.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - No new child pages or split/merge/rename are recommended.
  - The target body should add adjusted COL evidence at `0x00631300` and `0x00631330`.
- Padding/table/data/code distinctions:
  - This is `.rdata` vtable/RTTI support, not padding, executable code, or a source-authored static array.
- Parent/container impact:
  - [UID:000270] remains `RECONSTRUCTABLE:FALSE` mixed container. UID0002Z9 remains a reconstructable exact child.

## Negative Evidence Summary

- No direct xrefs to `0x006312ac`, `0x00631300`, `0x00631330`, or `0x0063133c`; this is normal for RTTI-adjacent complete-object-locator dwords and does not weaken class ownership.
- No VA/RVA pointer-byte hits for the target raw start, timer cell, or successor boundary. Only expected constructor immediates for the three Snowing vtable bases were found.
- No local IDA type catalog rows for SnowingLayerPane or WeatherLayerPane; do not invent final header layout from this page.
- No `.cpp`/`.pdb` source-path string proof; do not force the dedicated `SnowingLayerPane.cpp` route.
- Consumer/read xrefs from vtable cells prove slot identity, not a standalone global-array source owner.
- Address adjacency to Raining and Swallow does not transfer ownership across the `0x006312ac` and `0x0063133c` class boundaries.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: none for IDA DB. Use `SnowingLayerPaneVtableData` in docs and keep MSVC decorated labels as binary evidence, not as source names.
- Evidence for each proposed name/type/comment: target name matches existing source class and range role.
- Items intentionally left unchanged and why: no IDA UDT exists for final layout; no IDA rename/type/comment edit is required for report-only documentation.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. B-agent report-only scope must not edit IDA DB.

## First-Draft C++ Recommendation

- Eligible for draft C++: the page is numerically eligible because it is reconstructable, has an emitter route, and clears the combined-score gate after the recommended score lift.
- Recommended code: preserve the existing formal marker exactly; do not emit a vtable array.

```cpp
// SnowingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.
```

- Reason it preserves exact original behavior: MSVC regenerates RTTI/vtable data from class declarations, inheritance, virtual methods, and destructor/thunk shape. Hand-authoring raw dwords would freeze original addresses and duplicate compiler output.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: developers would write a `SnowingLayerPane` class and method bodies, not a C++ source array of vtable pointers.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: none on this target page. Exact method child pages own method names and first-draft method code where applicable.
- Naming/coding style convention used and evidence for consistency: preserve `SnowingLayerPane` class-family naming already used by class/file/memory child docs.
- Reason code should remain marker-only: source-visible behavior is on [UID:0000DC] and exact Snowing method pages; this range is compiler-emitted `.rdata` support.
- Exact no-code proof: current MCP proves constructor stores the three vtable views and slots point to Snowing/Weather methods; generated `WeatherLayerPane.cpp` already contains the marker and no raw array; support docs carry class/method source routes; raw vtable data has no standalone source declaration style.

## Final Recommendation

- Exact changes recommended: target-only metadata and body refresh for UID0002Z9, with `COMPLETION:88` and `CONFIDENCE:92`.
- Exact parent assignments recommended: keep [UID:0000DC] for `CANONICAL_OWNER` and `EMITTER_UIDS`.
- Exact items left no-owner/non-emitting and why: none for UID0002Z9. The broad aggregate [UID:000270] remains non-emitting by existing docs and is not changed by this report.
- Exact future work outside this assignment scope: final weather-layer file split and local IDA UDT/header recovery, if future evidence appears. No support edits are required now.

## Recommended Target Doc Changes

- Target path: `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`
- Exact report facts to incorporate:
  - Current MCP session `supervisor_recovery_20260705` health and readiness summary.
  - Byte/dword inventory for the Snowing band, including `0x006312ac`, `0x006312b0`, `0x006312c0`, `0x006312f4`, `0x006312fc`, `0x00631300`, `0x00631304`, `0x00631330`, `0x00631334`, `0x00631338`, and successor `0x0063133c`.
  - Constructor xrefs/stores at `0x005c1c0d`, `0x005c1c18`, and `0x005c1c22`.
  - Slot target facts for `0x005c2a20`, `0x005c20e0`, `0x005c1c80`, `0x005c1f50`, `0x005c29ec`, `0x005c29f7`, and `0x005c13b0`.
  - Decompile/disasm facts for `sub_5C1BD0`, `sub_5C29EC`, `sub_5C2A20`, and `sub_5C13B0`.
  - Pointer-byte negative checks, no local UDT, no source-path/PDB proof, and generated marker route proof.
  - Rejected alternatives and no-standalone-array proof.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION:85` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Preserve `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the formal marker exactly.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve B008 marker history as correct.
  - Reject raw vtable arrays, `RECONSTRUCTABLE:FALSE`, no-owner/non-emitting, broad aggregate owner, file-owner-only route, adjacent sibling ownership, and forced dedicated source split.

## Recommended Support Doc Changes

- Support path: none recommended for callback. Related docs checked and current disposition:
  - [UID:0000DC] `by-class/SnowingLayerPane.md`: already contains the route marker plus `[[CHILDREN]]` and supports UID0002Z9's generated marker route.
  - [UID:0000P8] `by-file/WeatherLayerPane.md`: already records the weather-layer source-family route and one-file versus per-layer split caveat.
  - [UID:000270] `by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md`: already records UID0002Z9 as the exact Snowing vtable child and keeps the broad aggregate non-emitting.
  - Predecessor/successor UID0002Z8 and UID0002ZA already state boundaries; no direct contradiction was found.
- Exact report facts to incorporate: not applicable unless the supervisor expands scope or discovers drift during implementation callback.
- Metadata/link/score/coverage/source-placement changes: none recommended.

## Score And Metadata Recommendation

- Current score/metadata: `85/90`, `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank position, marker-only formal C++.
- Recommended score/metadata: `88/92`, same owner/emitter/reconstructable/position/marker state.
- Score rationale and reason not higher/lower:
  - Completion improves because target can now record full current MCP evidence, adjusted COL views, constructor store xrefs, slot target facts, pointer/type/source-string negatives, generated freshness, and rejected alternatives.
  - Confidence improves because current live IDA independently confirms the older split/ownership facts and generated route.
  - Do not exceed low 90s or use 95+ because final class UDT/header text, inherited slot semantics, and original source-file split are not final-audit complete.
- Score-improvement attempt:
  - Checked target bytes/dwords: resolved.
  - Checked owner/emitter route: resolved.
  - Checked support parent scores/routes: resolved as already present.
  - Checked source split proof: unresolved after source-string/type checks; confidence cap only.
  - Checked C++ eligibility: marker-only disposition resolved; no raw vtable array.
- Metadata fields to change or leave unchanged: change only completion/confidence; leave all other header fields unchanged.

## Open Questions With Attempted Resolution

- Open question: should UID0002Z9 convert to non-reconstructable compiler-generated support?
  - Evidence checked: by-structure rules, UID000270 aggregate disposition, exact child metadata, B008 marker precedent, current MCP vtable stores/slots.
  - Resolution: no. Keep `RECONSTRUCTABLE:TRUE` because exact class vtable support depends on source declaration/virtual method reconstruction.
- Open question: should [UID:0000NR] dedicated Snowing file become the route?
  - Evidence checked: by-file pages, generated output, strings/type checks, WeatherLayerPane source-family docs.
  - Resolution: no current route change. Dedicated file remains a future candidate only.
- Open question: should the formal C++ block be blank or marker-only?
  - Evidence checked: current target, generated output, B008 report, by-structure no-code marker guidance for covered/generated-binary support.
  - Resolution: preserve marker-only block. It is clearer than blank and prevents a false empty-emitter state without hand-authoring bytes.
- Questions remaining unresolved:
  - No local UDT/source-file proof for final header/source split. This caps confidence and support C++ finality but does not block the target recommendation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Generated tracker and generated coverage are validator-owned and should refresh from source by-* metadata if the target change is accepted.
- No manual `-coverage-report.md` edit is requested for this report.

## Follow-Up Actions

- Supervisor actions: Gate 2 claim-by-claim verification against the target doc, report ledger/checklist, validator output, and generated freshness notes. Report execution/archive remains supervisor-only after Gate 2.
- A-agent actions: none.
- B005 future research actions: none unless supervisor finds a Gate 2 discrepancy or support-doc drift requiring a new explicit scope decision.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/92`, not final-audit `95+`.
- Remaining uncertainty: final weather-layer source split and unrecovered local UDT/header text.

## Validator Results

- Required scoped command from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002Z9-SnowingLayerPaneVtableData-source-quality-removed.md](0002Z9-SnowingLayerPaneVtableData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `000000007283`, timestamp `2026-07-05T17:55:30-04:00`, exit `1`: frontend queued the command but hit `PermissionError: [Errno 13] Permission denied` while reading result JSON. This was not used as the final validator result.
- `000000007284`, timestamp `2026-07-05T17:55:48-04:00`, exit `0`, `ok: 1`: validator succeeded but reported `missing_ref_uid` for newly added UID labels `0003O0`, `0003O2`, and `0003O4`. The target links were corrected to keep file links without those validator-missing UID labels.
- `000000007285`, timestamp `2026-07-05T17:56:22-04:00`, exit `0`, `ok: 1`: final scoped validator result for the applied target edit. Remaining diagnostics: `stats_incremental_noop 0002Z9 project-level/-auto-completion-stats.md file is not present in generated stats lists`; `projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section`; `generated_refresh: deferred`; `generated_refresh_command_id: 000000007285`; `generated_refresh_timestamp: 2026-07-05T17:56:22-04:00`.
- Generated freshness/read-only check: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` refreshed to `validator-command-id: 000000007285`, `validator-refreshed-at: 2026-07-05T17:56:22-04:00`, equal to the final validator command. UID0002Z9 appears at generated lines `98-99` with `Completion:88 | Confidence:92` and the exact Snowing vtable marker. Read-only search found no raw UID0002Z9 vtable array emitted.
- Validator-owned side effects observed in git status after validation: `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`. B005 did not manually edit generated files, generated reports, coverage reports, or validator state.

## Changed Files

- Created/updated report: `tools/leaser/Agents/Agent-B005/research/0002Z9-SnowingLayerPaneVtableData-source-quality.md`
- Modified target: `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`
- Support docs edited: none.
- Validator/generated side effects, not manually edited by B005: `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`.
- Leaser-generated side effect, not manually edited by B005: `tools/leaser/Agents/Agent-B005/current_leases.md`; it shows no active B005 lease for the target after release.
- Renamed: none.
- Report execution: not run. B005 did not run `execute_report`, dry-run/probing execute variants, lifecycle commands, registry commands, manual report moves, or archive moves.
- Leases: B005 leased only `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md` immediately before editing. Lease command succeeded; release command succeeded after edit/validator/generated-freshness checks. Current lease report shows no active B005 lease for the target.

## Implementation Tracking Checklist

Callback verification states:

- [x] Supervisor validation required before implementation: Gate 1 passed per supervisor callback for this exact report and target.
- [x] Target/support docs to update: target-only `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md` updated; no support docs edited because none were authorized and no concrete support drift was found.
- [x] Current target state and actual evidence checked recorded: target now records pre/post metadata, support-doc route context, generated state, MCP session `supervisor_recovery_20260705`, current byte/dword inventory, and negative evidence.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger above now uses callback states `applied`, `already-present`, and `excluded-with-reason`.
- [x] Metadata/score changes to apply: target is now `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` were preserved.
- [x] Score-limiting blockers researched to resolution: owner, route, split, no-code marker, adjusted COL evidence, pointer/type/source-string negatives, and generated freshness are now documented in the target; final one-file versus dedicated file split remains an evidence-backed confidence cap.
- [x] Owner/emitter/reconstructable changes to apply: no changes required beyond preservation; [UID:0000DC], `TRUE`, and [UID:0000DC] are unchanged.
- [x] Split/rename/new-child changes to apply: none; target remains exact half-open range `0x006312ac-0x0063133c`.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: target preserves current weather-family route, source-placement caveat, and no IDA DB changes.
- [x] First-draft C++ or no-code proof to apply: formal marker preserved exactly and expanded no-standalone-array proof added; no raw vtable array emitted.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: target now includes MCP health/session, range bytes/dwords, constructor stores, slot xrefs, decompile/disasm facts, pointer negatives, type/source-string negatives, generated route proof, rejected alternatives, and score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B008 marker history preserved; target rejects raw arrays, non-reconstructable conversion, no-owner/non-emitting, aggregate/file/sibling ownership, and forced dedicated source split.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: report retains the report-only conclusion that generated/simroot mentions were treated as lead/history only; no target body dependency on stale Wave2/Wave3 material was added.
- [x] Open questions to close or document as evidence-backed unresolved: final one-file versus dedicated file split and local UDT/header proof remain unresolved confidence caps and are documented.
- [x] Validators to run: scoped target validator run; final clean result is command `000000007285`, timestamp `2026-07-05T17:56:22-04:00`, exit `0`, `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated refresh completed for `auto-generated/NexusTK/map/WeatherLayerPane.cpp` at command `000000007285`; no manual coverage/tracker text requested.
- [x] Lease release: B005 target lease acquired immediately before edit and released immediately after edit/validator/generated-freshness batch; no active B005 target lease remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000007290","destination_path":"executed-b-agent-research/B005/0002Z9-SnowingLayerPaneVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002Z9-SnowingLayerPaneVtableData-source-quality.md","timestamp":"2026-07-05T18:08:15-04:00","uid":"0002Z9"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002Z9-SnowingLayerPaneVtableData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002Z9-SnowingLayerPaneVtableData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002Z9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
