** TARGET-REPORT-UID:0001NZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001NZ Weather/Raining Source-Container Research

Assignment: `B001-goal2-weather-raining-source-container-0001NZ-20260616`  
Target: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](../../../../../by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)

## Recommendation

Keep [UID:0001NZ] as a source-bearing reconstructable aggregate for now:

- `COMPLETION:82`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000P8`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000P8`
- final C++ blank

Do not reclassify it yet to the [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](../../../../../by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) model. `0001O1` is now safe as a non-emitting migration index because exact Snowing child pages, the Swallow core page, the Swallow raw-helper page, thunk/ignore rows, and padding rows carry the source or non-source state. `0001NZ` does not have equivalent exact executable child pages for the Weather/Rain functions. The by-memory search found only the aggregate page for the executable range, plus exact data children for vtables and rain coordinate tables.

The code itself is live and not a dead duplicate. Live IDA and local PE scans show unique bodies, ordinary constructor/caller/vtable/table reachability, and no duplicate retained byte island. The remaining problem is source-container granularity, not liveness.

## Why This Differs From 0001O1

The accepted `0001O1` source-placement report applied the `by-structure.md` mixed-container rule: a broad mixed address-neighborhood page should become `RECONSTRUCTABLE:FALSE` when exact children already carry the actual source ownership. Current `0001NZ` fails the second half of that rule.

Current exact executable child coverage:

| Range | Exact executable child page exists? | Current source carrier |
| --- | --- | --- |
| `0x005c12a0-0x005c13a1` WeatherLayerPane constructor | No | `0001NZ` aggregate, class/file support docs |
| `0x005c13b0-0x005c1408` WeatherLayerPane timer handler | No | `0001NZ` aggregate, class/file support docs |
| `0x005c1410-0x005c145a` RainingLayerPane constructor | No | `0001NZ` aggregate, class/file support docs |
| `0x005c1460-0x005c180c` RainingLayerPane::OnPaint | No | `0001NZ` aggregate, class/file/table support docs |
| `0x005c1810-0x005c1bc7` RainingLayerPane::DrawRainOnTarget | No | `0001NZ` aggregate, class/file/table support docs |

The exact support pages that do exist are data/support, not executable method carriers:

- [UID:0002Z7][0x0063118c-0x0063121c.WeatherLayerPaneVtableData](../../../../../by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md)
- [UID:0002Z8][0x0063121c-0x006312ac.RainingLayerPaneVtableData](../../../../../by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](../../../../../by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)
- [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](../../../../../by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- [UID:0001WJ][WeatherLayerDataLayouts](../../../../../by-type/by-struct/WeatherLayerDataLayouts.md)

Those pages are adequate as support evidence but not as substitutes for exact executable source pages.

## Evidence Checked

### Documentation and Coverage

- Read B001 `goal.md`, standing `notes.md`, and the accepted/executed `0001O1` report.
- Read [UID:0001NZ] target doc, [UID:0000P8][WeatherLayerPane](../../../../../by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](../../../../../by-file/RainingLayerPane.md), [UID:0000G1][WeatherLayerPane](../../../../../by-class/WeatherLayerPane.md), [UID:0000BJ][RainingLayerPane](../../../../../by-class/RainingLayerPane.md), WeatherLayer globals/layout docs, vtable children, rain table child, active-map singleton, and proposed source-tree weather notes.
- `rg --files by-memory` found no exact executable Weather/Rain child pages for the five functions inside `0001NZ`. The only executable page at those starts is `0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md`.
- [UID:0001O1] now has the contrasting exact-child state: exact Snowing children (`0003O0` through `0003O4`), [UID:0001O2] Swallow core, [UID:0001O3] Swallow raw helpers, and padding/thunk rows carry the actual state. That makes the `0001O1` non-emitting migration-index precedent valid there but not yet for `0001NZ`.
- `by-memory/-coverage-report.md` still has a stale `50% : medium : reconstructable` row for `0001NZ`; this should be replaced with a current `82% : strong` row matching the target header and B001 source-container decision.

### Live IDA MCP

Active session: `c001_midiplayer_rdata_20260615`, `NexusTK.exe`, image base `0x400000`; `server_health` returned `status: ok`, Hex-Rays ready, strings cache ready. No IDA writes were performed.

`lookup_funcs` confirms modeled function boundaries:

| Address | IDA result |
| --- | --- |
| `0x005c12a0` | `sub_5C12A0`, size `0x101` |
| `0x005c13b0` | `sub_5C13B0`, size `0x58` |
| `0x005c1410` | `sub_5C1410`, size `0x4a` |
| `0x005c1460` | `sub_5C1460`, size `0x3ac` |
| `0x005c1810` | `sub_5C1810`, size `0x3b7` |
| `0x005c1bd0` | successor `sub_5C1BD0`, size `0xae` |

Boundary checks:

- `0x005c129a`, `0x005c13a1`, `0x005c1408`, `0x005c145a`, `0x005c180c`, and `0x005c1bc7` are not function starts.
- `get_bytes` reports all internal/trailing gaps as `0xcc`: `0x005c129a-0x005c12a0`, `0x005c13a1-0x005c13b0`, `0x005c1408-0x005c1410`, `0x005c145a-0x005c1460`, `0x005c180c-0x005c1810`, and `0x005c1bc7-0x005c1bd0`.

Reachability and ownership xrefs:

- `xrefs_to 0x005c12a0`: code callers at `0x005c141a` rain, `0x005c1bfb` snow, and `0x005c225b` swallow.
- `xrefs_to 0x005c13b0`: data/vtable refs at `0x00631218`, `0x006312a8`, and `0x00631338`.
- `xrefs_to 0x005c1410`: code caller at `0x0050dc3b` inside `sub_50DB50`.
- `xrefs_to 0x005c1460`: data/vtable ref at `0x00631264`.
- `xrefs_to 0x005c1810`: data/vtable ref at `0x00631230`.
- Weather vtable stores: `0x00631190`, `0x006311e4`, and `0x00631214` are stored from `0x005c12d0`, `0x005c12d6`, and `0x005c12e0`.
- Rain vtable stores: `0x00631220`, `0x00631274`, and `0x006312a4` are stored from `0x005c1424`, `0x005c1433`, and `0x005c143d`.
- Rain table xrefs remain exclusive to the two rain draw paths: target/minimap starts `0x006702c8`, `0x00670478`, `0x006704d0` are used by `0x005c1810`; main-view starts `0x00670528`, `0x006706d8`, `0x00670730` are used by `0x005c1460`; `0x00670784` has no xref and is the snow-table boundary.

`analyze_component` over `0x005c12a0`, `0x005c13b0`, `0x005c1410`, `0x005c1460`, `0x005c1810`, and `0x0050db50` confirms the internal source-family edges:

- `0x005c1410 -> 0x005c12a0`
- `0x0050db50 -> 0x005c1410`

Shared globals from the same component:

- `word_66DA9C` and `word_66DAA0` are shared by `sub_50DB50` and `sub_5C12A0`.
- `dword_67A764` / active MapPane is shared by the two rain draw paths.

### Local PE Scans

Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x400000`.

Exact-body scans:

| Pattern | Result |
| --- | --- |
| Aggregate `0x005c12a0-0x005c1bc7` | one match, at `0x005c12a0` |
| Weather constructor `0x005c12a0-0x005c13a1` | one match, at `0x005c12a0` |
| Weather timer `0x005c13b0-0x005c1408` | one match, at `0x005c13b0` |
| Rain constructor `0x005c1410-0x005c145a` | one match, at `0x005c1410` |
| Rain paint `0x005c1460-0x005c180c` | one match, at `0x005c1460` |
| Rain target draw `0x005c1810-0x005c1bc7` | one match, at `0x005c1810` |

Pointer/branch scans:

- No absolute VA pointer hits for `0x005c12a0`, `0x005c1410`, `0x005c1bc7`, or `0x005c1bd0`.
- Absolute VA hits for function-pointer/vtable cells match IDA: `0x005c13b0` at `0x00631218`, `0x006312a8`, `0x00631338`; `0x005c1460` at `0x00631264`; `0x005c1810` at `0x00631230`.
- Absolute VA operand hits for vtable/table bases match constructor/table use: `0x00631190` at `0x005c12d2`, `0x00631220` at `0x005c1426`, and `0x006702c8` at `0x005c187b`.
- No RVA-pointer hits for the scanned function starts/boundaries/data anchors.
- `.text` `E8`/`E9` rel32 hits: `0x005c12a0` has the three derived-constructor calls at `0x005c141a`, `0x005c1bfb`, `0x005c225b`; `0x005c1410` has the MapPane call at `0x0050dc3b`; sibling `0x005c1bd0` and `0x005c2230` have MapPane calls at `0x0050dc17` and `0x0050dbf3`. No rel32 hits target `0x005c13b0`, `0x005c1460`, `0x005c1810`, or endpoint `0x005c1bc7`.
- No conditional rel32 branch hits target the scanned function starts or endpoint.

These scans rule out the raw/dead duplicate theory for `0001NZ`. The bodies are unique, modeled by IDA, and reached through normal constructors or vtable slots.

### Source-Placement and Generated-Output Heuristics

- `find_regex` for weather source names found only RTTI type strings: `.?AVWeatherLayerPane@@`, `.?AVRainingLayerPane@@`, `.?AVSnowingLayerPane@@`, and `.?AVSwallowLayerPane@@`. It found no `.cpp`, `.pdb`, or source-path strings that settle original file placement.
- [UID:0000P8][WeatherLayerPane](../../../../../by-file/WeatherLayerPane.md) is the documented weather-layer source-family root under `NexusTK/map/`, with separate candidate files `WeatherLayerPane.cpp`, `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp`.
- [UID:0000MY][RainingLayerPane](../../../../../by-file/RainingLayerPane.md) is a strong dedicated rain file candidate, but still explicitly keeps the dedicated-file versus weather-family split open.
- `auto-generated/-ag-memory-coverage.md` currently routes `0001NZ` through `0000P8` to `auto-generated/NexusTK/map/WeatherLayerPane.cpp`; the exact rain coordinate tables route through `0000MY` to `RainingLayerPane.cpp`.
- `auto-generated/-ag-class-coverage.md` routes Weather/Raining/Snowing/Swallow classes through `0000P8` to `WeatherLayerPane.cpp`, while `auto-generated/-ag-file-coverage.md` also lists separate by-file roots for `WeatherLayerPane.cpp`, `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp`.
- The current `auto-generated/NexusTK/map/WeatherLayerPane.cpp` and `auto-generated/NexusTK/map/RainingLayerPane.cpp` files are zero-byte roots. The older `simroot_v2/class_WeatherLayerPane.cpp` and `simroot_v2/class_RainingLayerPane.cpp` contain generated active views but have autograder penalties and missing source-map memory ranges, so they are provenance hints rather than final source.

The best current model is: `0001NZ` remains the temporary executable source carrier for the base Weather and concrete Rain methods under the WeatherLayerPane source-family owner. Exact child splitting should move real source ownership down to direct class pages; only after that should the aggregate become a non-emitting migration index.

## Unresolved Issues

### One File Versus Split Files

Not resolved safely. Evidence checked:

- Proposed source tree lists separate map/weather files.
- File/class docs support both a weather-family root and possible separate `RainingLayerPane.cpp`.
- IDA strings expose RTTI class names but no source filenames, PDB paths, or compile-unit hints.
- Generated coverage is internally split: class routes collapse through `WeatherLayerPane.cpp`, file roots exist separately, and exact data routes may use `RainingLayerPane.cpp`.

This blocks final C++ and final emitter granularity, but it does not justify reclassifying `0001NZ` as non-emitting before exact executable child pages exist.

### Exact Executable Child Coverage

Resolved as a required precondition for reclassification: exact child pages do not currently exist. The report does not create them because this assignment requested research-only output and no direct by-* edits. Without those pages, making `0001NZ` `RECONSTRUCTABLE:FALSE` would remove the only by-memory source-bearing carrier for five live functions.

### IDA DB Repair

No repair is recommended. IDA already has modeled functions at all five starts with correct exclusive ends and successor padding. The only broad-source issue is documentation/source-container granularity, not IDA function recovery. No rename, function creation, function deletion, or IDB save is justified from this pass.

## Supervisor Actions

### Immediate target/support docs

No immediate target-header, support-doc, owner, emitter, or final-C++ change is recommended for [UID:0001NZ].

Keep:

```text
COMPLETION:82
CONFIDENCE:86
CANONICAL_OWNER:0000P8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P8
```

Keep the final C++ block blank.

### Shared coverage row

Do not edit `by-memory/-coverage-report.md` directly as B001. Supervisor should replace the stale current `0001NZ` row immediately after the `0x005c129a-0x005c12a0` ignored padding row and before the `0x005c1bc7-0x005c1bd0` ignored padding row with:

```markdown
    - [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) 0x005c12a0-0x005c1bc7 | class aggregate | WeatherAndRainingLayerPanes : reconstructable : 82% : strong : B001 2026-06-16 keeps this WeatherLayerPane/RainingLayerPane executable aggregate source-bearing for now: live IDA and PE scans confirm five modeled unique function bodies, expected MapPane/derived-constructor/vtable/table refs, and pure 0xcc padding boundaries, but exact Weather/Rain executable child pages do not yet exist, so 0001NZ cannot safely become a non-emitting migration index like 0001O1. Final C++ remains blank pending child split and the one-file versus per-layer source decision.
```

### Conditional child split before future reclassification

Open a follow-up split assignment before applying the `0001O1` non-emitting model to `0001NZ`. Suggested child pages:

| Proposed child | Direct owner/emitter | Notes |
| --- | --- | --- |
| `by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md` | [UID:0000G1] WeatherLayerPane class | Base constructor; callers from Rain/Snow/Swallow constructors; Weather vtable stores. |
| `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent.md` | [UID:0000G1] WeatherLayerPane class | Shared timer virtual in Weather/Rain/Snow vtables. |
| `by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md` | [UID:0000BJ] RainingLayerPane class | MapPane weather setup caller; calls Weather base; rain vtable stores. |
| `by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md` | [UID:0000BJ] RainingLayerPane class | Main-view rain render path and main rain tables. |
| `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md` | [UID:0000BJ] RainingLayerPane class | Target/minimap rain render path and alternate rain tables. |

After those exact child pages and internal padding rows exist and validate, supervisor can consider reclassifying `0001NZ` to:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000P8
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Do not apply that future metadata before the split, because today `0001NZ` is still the only exact by-memory source carrier for the base Weather and Rain executable functions.

### Validation commands

If supervisor applies only the shared-row replacement:

> Executable block R001 was removed from this report and preserved verbatim in [0001NZ-weather-raining-source-container-removed.md](0001NZ-weather-raining-source-container-removed.md). The archived block is non-authoritative and must not be executed.

If supervisor later edits the target or adds child pages:

> Executable block R002 was removed from this report and preserved verbatim in [0001NZ-weather-raining-source-container-removed.md](0001NZ-weather-raining-source-container-removed.md). The archived block is non-authoritative and must not be executed.

Run additional validator targets for each new child page if the split is performed.

## Final Disposition

`0001NZ` should not become non-emitting yet. It should remain a reconstructable, WeatherLayerPane-owned source-family aggregate with blank final C++ until exact Weather/Rain executable children exist. Once those children exist, the same structural rule used for `0001O1` should likely apply and `0001NZ` can become a non-emitting migration index.

No direct by-* docs, generated reports, IDA DB, or coverage report files were changed by this research pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001NZ-weather-raining-source-container.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001NZ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001NZ-weather-raining-source-container-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001NZ-weather-raining-source-container.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001NZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
