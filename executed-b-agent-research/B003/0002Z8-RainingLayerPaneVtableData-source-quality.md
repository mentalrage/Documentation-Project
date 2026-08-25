** TARGET-REPORT-UID:0002Z8 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0002Z8] RainingLayerPaneVtableData Source-Quality Report

Agent: B003  
Assignment id: `B003-report-0002Z8-RainingLayerPaneVtableData-source-quality-20260705`  
Report timestamp: `2026-07-05T17:41:30-04:00`  
Target: `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`  
Report path: `tools/leaser/Agents/Agent-B003/research/0002Z8-RainingLayerPaneVtableData-source-quality.md`  
Mode: Gate 1 report accepted; implementation callback applied on 2026-07-05. During the original report-only pass no by-* docs were edited and no validators/lifecycle commands were run. During the accepted callback, only the target and authorized support doc were edited, scoped validators were run, leases were acquired/released, generated output was inspected read-only after validator refresh, and no `execute_report`, dry-run/probing execute variants, lifecycle commands, registry commands, manual moves, archive moves, coverage-report edits, or manual generated-file edits were run.

## Finalized Report / Current Recommendation

UID0002Z8 is an exact source-declared/generated-binary `RainingLayerPane` RTTI/vtable data page. It should remain class-owned by [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), remain reconstructable, and keep `EMITTER_UIDS:0000BJ`. It should not become a broad non-reconstructable audit container, and it should not emit a hand-authored vtable array.

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000BJ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BJ`
- `EMITTER_POSITION_OPTIONAL:` blank
- `Nested:0`

Recommended formal C++ handling: keep the current target marker exactly:

```cpp
// RainingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.
```

This marker is source-quality sufficient under current `by-structure.md`: class declarations and exact virtual method pages are source-level reconstruction inputs, while the raw RTTI/vtable bytes are compiler/linker output. The target needs a current evidence refresh, a score raise, and a generated-route support repair.

Support route disposition: the accepted callback updated [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) so its formal marker includes a `[[CHILDREN]]` insertion point after the existing class-route comment:

```cpp
// RainingLayerPane class-owned methods and vtable support emit on exact child pages; no duplicate broad class body is emitted here.
[[CHILDREN]]
```

Pre-callback reason: generated coverage routed UID0002Z8 as `coded`/`emits_code:true` through owner/emitter `0000BJ`, but generated `auto-generated/NexusTK/map/WeatherLayerPane.cpp` refreshed by validator command `000000007143` at `2026-07-05T15:10:39-04:00` did not contain UID0002Z8 or the Raining vtable marker. The sibling [UID:0002Z9] Snowing vtable marker did appear because [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) already had an effective child insertion route. Adding `[[CHILDREN]]` to the Raining class page was the narrow support fix; it did not create a broad class body or move the target to [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md). Callback validator `000000007279` is historical callback-time proof that the route repair refreshed `WeatherLayerPane.cpp` with UID0002Z8 and the accepted marker. Later unrelated validators can advance the generated header again; the durable claim is that UID0002Z8 has remained present in callback-time, supervisor, and latest B003-observed generated output after the route repair.

## Supporting Research

Current target/support docs checked:

- `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`
- `by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md`
- `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`
- `by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md`
- `by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md`
- `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md`
- `by-class/RainingLayerPane.md`
- `by-file/RainingLayerPane.md`
- `by-class/WeatherLayerPane.md`
- `by-file/WeatherLayerPane.md`
- `by-class/SnowingLayerPane.md`
- `by-file/SnowingLayerPane.md`
- `by-class/SwallowLayerPane.md`
- `by-file/SwallowLayerPane.md`

Generated/tracker files checked read-only:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/map/WeatherLayerPane.cpp`
- `auto-generated/NexusTK/map/RainingLayerPane.cpp`

Historical/executed reports checked as context, not as a substitute for current MCP:

- `executed-b-agent-research/B001/000270-WaitableWeatherReadOnlyData.md`
- `executed-b-agent-research/B001/0001NZ-weather-raining-source-container.md`
- `executed-b-agent-research/B001/0001NZ-child-split-weather-raining.md`
- `executed-b-agent-research/B001/0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md`
- `executed-b-agent-research/B008/0000P8-WeatherLayerPane-empty-emitter-family-source-quality.md`
- sibling active report context `tools/leaser/Agents/Agent-B004/research/0002Z7-WeatherLayerPaneVtableData-source-quality.md`

## Target

[UID:0002Z8] `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`

The target is a 0x90-byte half-open `.rdata` band containing:

- primary Raining COL pointer at `0x0063121c`, followed by primary vtable base `0x00631220`;
- adjusted `_0` COL pointer at `0x00631270`, followed by adjusted vtable base `0x00631274`;
- adjusted `_1` COL pointer at `0x006312a0`, followed by adjusted vtable base `0x006312a4`;
- successor boundary at `0x006312ac`, where [UID:0002Z9][SnowingLayerPaneVtableData](by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md) begins.

## Current Target State

Current post-callback target header in `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000BJ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BJ`
- `EMITTER_POSITION_OPTIONAL:` blank
- `Nested:0`
- Formal C++ still contains the unchanged no-hand-authored-vtable marker: `// RainingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.`

Current post-callback documentation state:

- The target now records direct class ownership by [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), reconstructable source-declared/generated-binary disposition, marker-only formal C++, exact half-open range `0x0063121c-0x006312ac`, sibling boundaries against UID0002Z7 and UID0002Z9, current MCP session `supervisor_recovery_20260705`, all three COL/vtable views, constructor stores, Rain virtual slots, shared destructor/adjustor thunk caveat, no direct xref / no VA/RVA pointer-hit negatives, no local UDT result, generated-route reasoning, rejected alternatives, and `88/92` score rationale.
- Authorized support doc [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) now contains `[[CHILDREN]]` after the existing class-route marker. Its class metadata score remains unchanged.
- Scoped validators ran and passed: target validator `000000007278` at `2026-07-05T17:51:39-04:00`, exit `0`, `ok:1`; support validator `000000007279` at `2026-07-05T17:51:47-04:00`, exit `0`, `ok:1`.
- Generated output observations are freshness snapshots, not permanent current-state guarantees. Callback validator `000000007279` remains historical callback-time proof, not a current generated-header claim. A supervisor recheck later observed `validator-command-id: 000000007304`, `validator-refreshed-at: 2026-07-05T18:22:19-04:00`, with UID0002Z8 still at generated lines 9-10. During this B003 report-text repair, a read-only observation saw `validator-command-id: 000000007309`, `validator-refreshed-at: 2026-07-05T18:30:44-04:00`, `validator-refresh-source: foreground-generated-refresh`, again with UID0002Z8 at generated lines 9-10 with `Completion:88`, `Confidence:92`, and the exact Rain vtable marker.
- Generated output may continue advancing because unrelated validators refresh shared `auto-generated/NexusTK/map/WeatherLayerPane.cpp`. Before `execute_report`, the supervisor should perform final current generated-header verification. The durable report claim is not a fixed header id; it is that UID0002Z8 remained present after the [UID:0000BJ] `[[CHILDREN]]` route repair in the latest B003/supervisor observations.

Historical pre-callback state:

- Before the accepted callback, the target header was `COMPLETION:85` and `CONFIDENCE:90`; those values are historical and no longer current.
- Before the accepted callback, the target's observed-content table named only one RTTI-adjacent word; current MCP confirmed three COL dwords inside the target at `0x0063121c`, `0x00631270`, and `0x006312a0`, and those details are now incorporated.
- Before the accepted callback, the page lacked current session `supervisor_recovery_20260705` evidence, full vtable view layout, capped pointer-scan negatives, current type-query negative, and the generated-route mismatch/resolution; those gaps are now incorporated.
- Before the accepted callback, generated `WeatherLayerPane.cpp` lacked UID0002Z8 because [UID:0000BJ]'s class page did not expose a child insertion point. The support route is now repaired with `[[CHILDREN]]`, and generated output now contains UID0002Z8.
- The old `85/90` score was the minimum pre-callback state. The current applied score is `88/92`.

## Evidence Standards Used

- Current IDA MCP evidence is mandatory and was used. The report does not rely on fallback-only local documentation.
- MCP calls were narrow, paged, and schema-current: exact ranges, exact addresses, capped `find_bytes`, and bounded entity/type queries.
- Historical reports are used only to preserve accepted context and rejected alternatives; current MCP evidence controls this report's source-quality recommendation.
- For `.rdata` vtable pages, `source-declared/generated-binary` means the source must recover class declarations and exact virtual methods, but must not hand-port raw RTTI/vtable byte arrays.
- Ownership distinguishes semantic class ownership from source-file route. [UID:0000BJ] is the direct class owner; [UID:0000P8] remains the weather-family source-file route through the class page unless a later file-split proof moves Rain to [UID:0000MY].

## Evidence Checked

MCP tools used read-only:

- `tools/list`
- `idb_list`
- `server_health`
- `entity_query`
- `get_bytes`
- `get_int`
- `xrefs_to`
- `lookup_funcs`
- `func_profile`
- `disasm`
- `decompile`
- `find_bytes`
- `type_query`

Important local checks:

- target, predecessor, successor, parent aggregate, class, and file docs;
- generated `WeatherLayerPane.cpp` and `RainingLayerPane.cpp` read-only;
- generated memory coverage and research tracker rows read-only;
- prior accepted weather/rain split and empty-emitter family reports.

## MCP Availability And Provenance

IDA MCP was available.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `supervisor_recovery_20260705`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `server_health`: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`

One local PowerShell parse mistake attempted `server_health` with an empty `database` value after `idb_list`; MCP returned the schema-current "database is required" error. The call was immediately corrected with explicit `database='supervisor_recovery_20260705'`. This was not MCP unavailability, busy state, or session loss.

## IDA MCP Facts

Current MCP `entity_query kind=names` over `0x00631200-0x006312b8` returned:

- `0x00631214`: `??_7WeatherLayerPane@@6B@_1` (predecessor vtable tail)
- `0x00631220`: `??_7RainingLayerPane@@6B@`
- `0x00631274`: `??_7RainingLayerPane@@6B@_0`
- `0x006312a4`: `??_7RainingLayerPane@@6B@_1`
- `0x006312b0`: `??_7SnowingLayerPane@@6B@` (successor vtable base)

Current MCP `entity_query kind=names` over `0x00654060-0x006540f0` returned the Raining RTTI names:

- `0x00654070`: `??_R4RainingLayerPane@@6B@`
- `0x00654084`: `??_R3RainingLayerPane@@8`
- `0x00654094`: `??_R2RainingLayerPane@@8`
- `0x006540b4`: `??_R1A@?0A@EA@RainingLayerPane@@8`
- `0x006540d0`: `??_R4RainingLayerPane@@6B@_0`
- `0x006540e4`: `??_R4RainingLayerPane@@6B@_1`

Current MCP `get_bytes` over `0x0063121c` size `144` returned exact bytes beginning:

```text
70 40 65 00 d0 b0 49 00 10 4b 4f 00 c0 b6 41 00
20 8e 4b 00 10 18 5c 00 30 47 54 00 50 47 54 00
...
d0 40 65 00 11 af 49 00 ... e4 40 65 00 1c af 49 00 b0 13 5c 00
```

Current MCP `get_int` over the exact target range returned this dword layout:

| Address | Value | Meaning |
| --- | --- | --- |
| `0x0063121c` | `0x00654070` | Primary `RainingLayerPane` COL pointer. |
| `0x00631220` | `0x0049b0d0` | Primary vtable slot 0, shared scalar deleting destructor wrapper. |
| `0x00631224` | `0x004f4b10` | Inherited/base slot. |
| `0x00631228` | `0x0041b6c0` | `nullsub_18`, inherited/base slot. |
| `0x0063122c` | `0x004b8e20` | Inherited/base slot. |
| `0x00631230` | `0x005c1810` | `RainingLayerPane::DrawRainOnTarget` virtual slot. |
| `0x00631234` | `0x00544730` | Inherited/base Pane-family slot. |
| `0x00631238` | `0x00544750` | Inherited/base Pane-family slot. |
| `0x0063123c` | `0x005447a0` | Inherited/base Pane-family slot. |
| `0x00631240` | `0x00544800` | Inherited/base Pane-family slot. |
| `0x00631244` | `0x00544a20` | Inherited/base Pane-family slot. |
| `0x00631248` | `0x00544b80` | Inherited/base Pane-family slot. |
| `0x0063124c` | `0x00544bd0` | Inherited/base Pane-family slot. |
| `0x00631250` | `0x00544c70` | Inherited/base Pane-family slot. |
| `0x00631254` | `0x00544cb0` | Inherited/base Pane-family slot. |
| `0x00631258` | `0x00544ce0` | Inherited/base Pane-family slot. |
| `0x0063125c` | `0x00544d30` | Inherited/base Pane-family slot. |
| `0x00631260` | `0x00544d70` | Inherited/base Pane-family slot. |
| `0x00631264` | `0x005c1460` | `RainingLayerPane::OnPaint` virtual slot. |
| `0x00631268` | `0x0041b6c0` | `nullsub_18`, inherited/base slot. |
| `0x0063126c` | `0x0041b6a0` | Guard-check thunk slot. |
| `0x00631270` | `0x006540d0` | Adjusted `_0` `RainingLayerPane` COL pointer. |
| `0x00631274` | `0x0049af11` | Adjusted `_0` vtable slot 0; subtracts `this` by `0xa0` then jumps to `0x0049b0d0`. |
| `0x00631278` | `0x00544db0` | Inherited adjusted-view slot. |
| `0x0063127c` | `0x00544dc0` | Inherited adjusted-view slot. |
| `0x00631280` | `0x00544dd0` | Inherited adjusted-view slot. |
| `0x00631284` | `0x00544de0` | Inherited adjusted-view slot. |
| `0x00631288` | `0x00544df0` | Inherited adjusted-view slot. |
| `0x0063128c` | `0x00544e00` | Inherited adjusted-view slot. |
| `0x00631290` | `0x004a89f0` | Inherited adjusted-view slot. |
| `0x00631294` | `0x00544e10` | Inherited adjusted-view slot. |
| `0x00631298` | `0x00544e30` | Inherited adjusted-view slot. |
| `0x0063129c` | `0x00544e70` | Inherited adjusted-view slot. |
| `0x006312a0` | `0x006540e4` | Adjusted `_1` `RainingLayerPane` COL pointer. |
| `0x006312a4` | `0x0049af1c` | Adjusted `_1` vtable slot 0; subtracts `this` by `0xa4` then jumps to `0x0049b0d0`. |
| `0x006312a8` | `0x005c13b0` | Shared `WeatherLayerPane::OnTimerEvent` virtual slot. |

Current MCP `xrefs_to` results:

- `0x0063121c`: 0 direct xrefs.
- `0x00631220`: one data xref, constructor store at `0x005c1424` inside `sub_5C1410`.
- `0x00631274`: one data xref, constructor store at `0x005c1433` inside `sub_5C1410`.
- `0x006312a4`: one data xref, constructor store at `0x005c143d` inside `sub_5C1410`.
- `0x00631230`, `0x00631264`, `0x00631270`, `0x006312a0`, `0x006312a8`, and `0x006312ac`: no direct xrefs to those data-cell addresses.
- `0x005c1810`: one data xref from vtable cell `0x00631230`.
- `0x005c1460`: one data xref from vtable cell `0x00631264`.
- `0x005c13b0`: data xrefs from Weather, Rain, and Snow timer slots at `0x00631218`, `0x006312a8`, and `0x00631338`.
- `0x0049b0d0`: data refs from ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane primary vtable cells plus code jumps from `0x0049af11` and `0x0049af1c`.
- `0x0049af11`: data refs from ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane adjusted `_0` vtable cells.
- `0x0049af1c`: data refs from ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane adjusted `_1` vtable cells.

Current MCP `lookup_funcs` / `func_profile` facts:

- `0x005c1410`: `sub_5C1410`, size `0x4a`, prototype `_WORD *__thiscall(_WORD *this)`, one caller `0x0050db50`, one callee `0x005c12a0`.
- `0x005c1460`: `sub_5C1460`, size `0x3ac`, no ordinary code callers in `func_profile`, data-routed by vtable cell `0x00631264`.
- `0x005c1810`: `sub_5C1810`, size `0x3b7`, no ordinary code callers in `func_profile`, data-routed by vtable cell `0x00631230`.
- `0x005c13b0`: `sub_5C13B0`, size `0x58`, data-routed by weather/rain/snow timer slots.
- `0x0049b0d0`: `sub_49B0D0`, size `0x3b`, shared scalar deleting destructor wrapper.
- `0x0049af11`: `sub_49AF11`, size `0x0b`, adjusted thunk.
- `0x0049af1c`: `sub_49AF1C`, size `0x0b`, adjusted thunk.

Current MCP `decompile 0x005c1410` shows:

```cpp
_WORD *__thiscall sub_5C1410(_WORD *this)
{
  _WORD *result; // eax

  sub_5C12A0((int)this); /*0x5c141a*/
  *(_DWORD *)this = &RainingLayerPane::`vftable'; /*0x5c1424*/
  this[125] = 120; /*0x5c142a*/
  result = this; /*0x5c1431*/
  *((_DWORD *)this + 40) = &RainingLayerPane::`vftable'; /*0x5c1433*/
  *((_DWORD *)this + 41) = &RainingLayerPane::`vftable'; /*0x5c143d*/
  *((_BYTE *)this + 249) = 3; /*0x5c1447*/
  *((_BYTE *)this + 246) = 1; /*0x5c144e*/
  return result; /*0x5c1455*/
}
```

Current MCP `disasm 0x0049af11` and `0x0049af1c` shows:

- `0x0049af11`: `sub ecx, 0A0h`; `jmp sub_49B0D0`.
- `0x0049af1c`: `sub ecx, 0A4h`; `jmp sub_49B0D0`.

Current MCP `decompile 0x0049b0d0` shows shared scalar deleting wrapper behavior:

```cpp
_DWORD *__thiscall sub_49B0D0(_DWORD *Block, char a2)
{
  sub_544580(Block); /*0x49b0d6*/
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 ) /*0x49b0e4*/
    return Block; /*0x49b104*/
  sub_4F4AC0(Block); /*0x49b0e7*/
  return Block; /*0x49b0f1*/
}
```

Current MCP `find_bytes` facts:

- Exact 16-byte target signature `70 40 65 00 D0 B0 49 00 10 4B 4F 00 C0 B6 41 00` appears once, at `0x0063121c`.
- VA/RVA pointer patterns for target start `0x0063121c` / RVA `0x0023121c`: 0 matches.
- VA pointer patterns for vtable bases `0x00631220`, `0x00631274`, and `0x006312a4` appear only at constructor immediate operands `0x005c1426`, `0x005c1439`, and `0x005c1443`; RVA patterns for those bases have 0 matches.
- VA/RVA pointer patterns for successor `0x006312ac`: 0 matches.

Current MCP `type_query` for `*RainingLayerPane*` and `*WeatherLayerPane*` found 0 local type-catalog UDT/declaration matches, so source names and class relationships remain inferred from RTTI/vtable names, decompiled constructor stores, existing by-* class docs, and method-page evidence.

## Current Documentation Evidence And IDA Status

Current target documentation already correctly records the direct class owner and marker-only no-hand-authored-vtable C++ block. Current support docs provide strong context:

- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) is `86/88`, reconstructable, and records the exact constructor, paint, and target draw child pages. It also records the MapPane caller, base-constructor call, rain vtable stores, and rain render slots.
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) is a candidate dedicated source file under `NexusTK/map/`, with final separate-file versus weather-family split still below proof.
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) remains the weather-layer source-family file route. It explicitly says direct method owners are the four weather-layer classes and that vtable-data pages are marker-only support.
- [UID:000270][WaitableWeatherReadOnlyData](by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md) is the parent-blank mixed `.rdata` inventory. It maps UID0002Z8 to Raining and rejects broad aggregate source emission.
- [UID:0002Z7] and [UID:0002Z9] are exact sibling vtable pages with the same source-declared/generated-binary marker policy.

Generated state checked read-only across report and callback phases:

- Historical pre-callback assignment tracker state: `auto-generated/-ag-research-tracker.md` listed UID0002Z8 under reconstructable not-covered files at `85/90`, combined `87.5`, reports `0`. This was the queue/source state for the report, not the current post-callback target score.
- Historical pre-callback memory coverage state: `auto-generated/-ag-memory-coverage.md` listed UID0002Z8 as `coded`, owner/emitter `0000BJ`, `emits_code: yes`, output `auto-generated/NexusTK/map/WeatherLayerPane.cpp`.
- Pre-callback `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, refreshed by validator command `000000007143` at `2026-07-05T15:10:39-04:00`, contained the [UID:0000BJ] class marker but did not contain UID0002Z8 or the Raining vtable marker. Callback validator `000000007279` repaired the generated route at callback time. Later generated refreshes superseded that header; supervisor observation `000000007304` / `2026-07-05T18:22:19-04:00` and latest B003 report-time observation `000000007309` / `2026-07-05T18:30:44-04:00` both still had UID0002Z8 at generated lines 9-10.
- The same generated file contained UID0002Z9 and the Snowing vtable marker before the callback, indicating the UID0002Z8 miss was likely a class-child insertion route issue for [UID:0000BJ], not a reason to change UID0002Z8's owner.
- `auto-generated/NexusTK/map/RainingLayerPane.cpp`, also refreshed by command `000000007143`, contains only [UID:0001ON] rain coordinate table empty marker under [UID:0000MY]. That supports retaining file-split uncertainty rather than forcing UID0002Z8 to [UID:0000MY].

## Heuristic / Inference Reanalysis And Validation

The old low score was not caused by wrong ownership. It was caused by thin current evidence and generated-route staleness.

Validated:

- Exact range: `0x0063121c-0x006312ac`, size `0x90`.
- Split boundaries: predecessor UID0002Z7 ends exactly at Rain primary COL pointer; successor UID0002Z9 begins exactly at Snow primary COL pointer.
- Semantic owner: [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), not base Weather, Snowing, Swallow, WaitableTimer, MapPane, the broad mixed `.rdata` inventory, or shared destructor glue.
- Source disposition: source-declared/generated-binary vtable support. The raw table is compiler-emitted from class/virtual declarations and exact method pages.
- Route: current project routes class children through [UID:0000BJ] and ultimately [UID:0000P8] `WeatherLayerPane.cpp`. This is consistent with current support docs while the dedicated [UID:0000MY] file remains plausible but unproven.
- Formal C++: marker-only, not blank and not a hand-authored array.

Rejected:

- Reclassifying to `RECONSTRUCTABLE:FALSE`: this exact child is not a mixed broad container. Source declaration recovery is still required.
- Clearing owner/emitter: current class owner/emitter is valid, and support docs clear the direct-parent gate.
- Assigning to [UID:0000P8] directly: WeatherLayerPane is the source-family route, but the vtable names and constructor stores are concrete Rain.
- Assigning to [UID:0000MY] directly in target metadata: dedicated file remains plausible but not proven by current generated output or source-path evidence.
- Assigning to shared destructor/adjustor pages: the destructor wrapper and adjusted thunks are shared ButtonControlPane/SelectBox/Weather/Rain glue and do not own this vtable page.
- Creating a by-type vtable page or merging into UID000270: unnecessary for this exact child and contrary to current split.

## Positive Evidence Summary

- Current MCP session is live and healthy.
- Target start has unique 16-byte signature at `0x0063121c`.
- RTTI names identify the primary and adjusted Rain COLs: `??_R4RainingLayerPane@@6B@`, `_0`, and `_1`.
- Vtable names identify `??_7RainingLayerPane@@6B@`, `_0`, and `_1` at `0x00631220`, `0x00631274`, and `0x006312a4`.
- Rain constructor stores those three vtable bases at `0x005c1424`, `0x005c1433`, and `0x005c143d`.
- Rain constructor has one ordinary caller from MapPane weather setup and calls the base Weather constructor.
- Rain-specific virtual slots point to exact source-bearing method pages: `0x00631230 -> 0x005c1810` and `0x00631264 -> 0x005c1460`.
- Timer slot `0x006312a8 -> 0x005c13b0` matches shared Weather timer handling.
- Class/file docs already record the weather-family source context and final file-split caveat.

## Negative Evidence Summary

- No direct xrefs to target start `0x0063121c` or successor start `0x006312ac`.
- No VA/RVA pointer hits to target start or successor start.
- RVA pointer patterns for the vtable bases have no matches; VA patterns appear only as constructor immediates.
- No local `RainingLayerPane` or `WeatherLayerPane` UDT exists in IDA type catalog, so class layout names remain documentation-level reconstructions.
- `0x0049b0d0`, `0x0049af11`, and `0x0049af1c` are shared destructor/adjustor glue, not Rain-exclusive methods.
- Historical pre-callback generated output lacked UID0002Z8 despite coverage saying it should emit; callback support repair proved this was a class-child route issue, not ownership failure, and generated output now contains UID0002Z8.

## Ranked Ownership Analysis

1. [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md): best direct owner. RTTI/vtable names, constructor stores, MapPane construction path, and rain virtual slots all point to the concrete class.
2. [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md): valid source-family/file route, but not the direct semantic owner of the Rain vtable band.
3. [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md): plausible future dedicated file route, but current generated output and file-split caveats do not prove a target metadata move.
4. [UID:000270][WaitableWeatherReadOnlyData](by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md): rejected as direct owner. It is a mixed `.rdata` inventory and already delegates exact children.
5. Shared destructor/adjustor pages [UID:0002XV]/[UID:0002XW] and ButtonControlPane/SelectBoxControlPane: rejected. They explain shared slot values but not ownership of this Rain vtable data.
6. SnowingLayerPane, SwallowLayerPane, WaitableTimer, MapPane, render/global/type pages: rejected. They are neighboring or consuming/support contexts, not the owner of UID0002Z8.

## Source Placement

Best current placement is class-owned [UID:0000BJ] under the weather-layer source-family route to [UID:0000P8] `NexusTK/map/WeatherLayerPane.cpp`, while preserving the dedicated [UID:0000MY] `RainingLayerPane.cpp` candidate as unresolved support context.

Reasoning:

- The target's source declaration is the `RainingLayerPane` class and its virtual surface.
- [UID:0000BJ] currently emits through [UID:0000P8] and generated coverage routes UID0002Z8 to `WeatherLayerPane.cpp`.
- [UID:0000MY] currently receives rain coordinate tables, not the vtable marker or exact rain method pages.
- No current source-path/PDB/string evidence proves final one-file versus per-layer source layout.

Therefore, target metadata correctly keeps `CANONICAL_OWNER:0000BJ` and `EMITTER_UIDS:0000BJ`; the callback repaired [UID:0000BJ]'s `[[CHILDREN]]` route and did not move the target.

## Range / Split / Padding / Reclassification Analysis

No split, merge, rename, or padding reclassification is recommended.

- Start `0x0063121c` is the primary Rain COL pointer `0x00654070`.
- Predecessor [UID:0002Z7] ends at `0x0063121c`; its final cell `0x00631218 -> 0x005c13b0` is Weather timer slot data.
- End `0x006312ac` is the successor [UID:0002Z9] Snow primary COL pointer `0x006540f8`.
- The target interior is all meaningful RTTI/vtable dwords; no ignored padding row belongs inside UID0002Z8.
- The target should remain `RECONSTRUCTABLE:TRUE` because it is exact class vtable data, not a mixed audit island.

## Function / Child Inventory

Source-bearing executable children supporting this vtable:

| Address range | UID | Role |
| --- | --- | --- |
| `0x005c1410-0x005c145a` | [UID:0003PI] | Raining constructor; stores the three Rain vtable views. |
| `0x005c1460-0x005c180c` | [UID:0003PJ] | Main rain paint/render path; vtable slot `0x00631264`. |
| `0x005c1810-0x005c1bc7` | [UID:0003PK] | Target/minimap-style rain draw path; vtable slot `0x00631230`. |
| `0x005c13b0-0x005c1408` | [UID:0003PH] | Shared Weather timer handler; Rain adjusted `_1` slot `0x006312a8`. |
| `0x0049b0d0-0x0049b10b` | [UID:0002XW] | Shared scalar deleting wrapper slot, not Rain-exclusive owner. |
| `0x0049af11-0x0049af27` | [UID:0002XV] | Shared adjusted thunks used by ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane. |

## Direct Xref / Caller Inventory

| Target | Current evidence |
| --- | --- |
| `0x00631220` | Constructor store at `0x005c1424`. |
| `0x00631274` | Constructor store at `0x005c1433`. |
| `0x006312a4` | Constructor store at `0x005c143d`. |
| `0x005c1410` | One ordinary caller: `0x0050dc3b` inside `sub_50DB50` MapPane weather setup. |
| `0x005c1460` | No ordinary caller; vtable data xref from `0x00631264`. |
| `0x005c1810` | No ordinary caller; vtable data xref from `0x00631230`. |
| `0x005c13b0` | Vtable data xrefs from Weather, Rain, and Snow timer slots. |
| `0x0049b0d0` | Shared primary-vtable refs from ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane plus thunk code jumps. |

## First-Draft C++ Recommendation

Do not add a hand-authored vtable array or standalone source body. Keep the target formal C++ block exactly:

```cpp
// RainingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.
```

This is not an empty-emitter blocker. It is the correct source-declared/generated-binary no-code marker for an exact vtable data page. The exact constructor/paint/draw method pages carry source-bearing behavior.

## Recommended Target Doc Changes

Accepted target doc changes, now applied after leasing the target:

- Changed `COMPLETION:85` to `COMPLETION:88`.
- Changed `CONFIDENCE:90` to `CONFIDENCE:92`.
- Kept `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BJ`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the formal marker unchanged.
- Updated Item Summary and prose with current MCP session `supervisor_recovery_20260705`, exact range/size `0x0063121c-0x006312ac` / `0x90`, unique 16-byte signature, primary and adjusted COL/vtable views, constructor stores, Rain virtual method slots, shared destructor/adjustor thunk caveat, no direct xref / no VA/RVA pointer-hit findings, no local UDT result, and generated-route expectation/resolution.
- Preserved historical A002/B001/B008 evidence while historicalizing older thin evidence as superseded by the current MCP refresh.

Required scoped validator after target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0002Z8-RainingLayerPaneVtableData-source-quality-removed.md](0002Z8-RainingLayerPaneVtableData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated freshness result after validation/generation refresh:

- `auto-generated/NexusTK/map/WeatherLayerPane.cpp` now contains UID0002Z8 and the exact Rain vtable marker after [UID:0000BJ] received the `[[CHILDREN]]` route.
- The historical target-only risk was that generated output could remain older/missing for UID0002Z8 without the support repair; that risk was resolved for this artifact at callback time by validator `000000007279`. Later generated headers can advance due unrelated validators; supervisor observation `000000007304` and latest B003-observed header `000000007309` both still contain UID0002Z8 at lines 9-10.
- Do not manually edit generated output.

## Recommended Support Doc Changes

Accepted support edit, now applied under callback scope:

- `by-class/RainingLayerPane.md`: added `[[CHILDREN]]` after the current formal class-route comment so exact child pages, including UID0002Z8, can emit marker-only or method bodies through the class route. Metadata scores were preserved. This is a generated-route support repair, not a semantic ownership change.

Scoped validator if edited:

> Executable block R002 was removed from this report and preserved verbatim in [0002Z8-RainingLayerPaneVtableData-source-quality-removed.md](0002Z8-RainingLayerPaneVtableData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Support docs that appear same-or-greater and do not need edits in the default callback:

- `by-file/RainingLayerPane.md`: already records the dedicated-file candidate and split-file caveat; no target metadata move to [UID:0000MY] is recommended.
- `by-file/WeatherLayerPane.md`: already records weather-family source route and marker-only vtable policy; no support edit needed unless generated-route text must mention the [UID:0000BJ] `[[CHILDREN]]` repair.
- `by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md`: already maps UID0002Z8 to the Rain child; no edit needed.
- sibling UID0002Z7/UID0002Z9/UID0002ZA pages: no edit needed for UID0002Z8 except if supervisor chooses to synchronize generated-route wording across siblings.

## Score And Metadata Recommendation

Current applied recommendation is `COMPLETION:88`, `CONFIDENCE:92`.

Completion rose from historical `85` to current `88` because current MCP resolves full target contents, all three COL/vtable views, constructor-store route, virtual-method slots, pointer-scan negatives, range boundaries, no-code marker eligibility, and the generated-route issue. It should not rise to 90+ yet because the original source-file split remains unresolved and no local UDT exists; the class-child route repair itself is now applied and no longer a current blocker.

Confidence rose from historical `90` to current `92` because current MCP independently confirms the core facts and no contradictory support evidence was found. It should remain below final-audit confidence because no local UDT exists and final source-file placement is not proven. The historical generated-output miss is resolved: `WeatherLayerPane.cpp` now contains the UID0002Z8 marker.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002Z8-01 | Target metadata should raise to `COMPLETION:88`, `CONFIDENCE:92` while preserving owner/emitter/reconstructable fields. | High | Current MCP range/xref/pointer facts plus support docs; target is not a mixed container. | Target metadata | incorporate | applied: target header now has `COMPLETION:88` and `CONFIDENCE:92`; validator `000000007278` reported completion/confidence updates and `ok:1`. |
| C-0002Z8-02 | UID0002Z8 is exactly `0x0063121c-0x006312ac`, size `0x90`, with no split/merge/padding change. | High | MCP `get_bytes`, `get_int`, names; predecessor UID0002Z7 and successor UID0002Z9 docs. | Target Summary / Range Evidence | incorporate | applied: target Summary/Item Summary/Changes now state exact `0x90` range and no split/merge/padding change; validator `000000007278` passed. |
| C-0002Z8-03 | The target contains three Raining COL/vtable views: primary at `0x0063121c/0x00631220`, adjusted `_0` at `0x00631270/0x00631274`, and adjusted `_1` at `0x006312a0/0x006312a4`. | High | MCP `get_int`, `entity_query` names around `0x00654070-0x006540e4`. | Target Observed Contents | incorporate | applied: target Observed Contents and Dword Layout record all three COL/vtable views and the RTTI name cluster. |
| C-0002Z8-04 | Constructor `0x005c1410` stores the three Rain vtable bases and is reached by MapPane weather setup at `0x0050dc3b`. | High | MCP `decompile`, `disasm`, `func_profile`, `xrefs_to`. | Target Evidence / Item Summary | incorporate | applied: target Evidence/Item Summary/Assignment Decision document constructor stores, base constructor, and MapPane caller. |
| C-0002Z8-05 | Rain virtual method slots route to exact child methods: `0x00631230 -> 0x005c1810`, `0x00631264 -> 0x005c1460`, and timer `0x006312a8 -> 0x005c13b0`. | High | MCP `get_int`, `xrefs_to`, support child docs. | Target Observed Contents / Function Inventory | incorporate | applied: target Observed Contents and Dword Layout record draw-target, paint, and timer slots with exact child links. |
| C-0002Z8-06 | Shared `0x0049b0d0` scalar wrapper and `0x0049af11`/`0x0049af1c` adjusted thunks are slot values, not Rain-exclusive source ownership. | High | MCP `xrefs_to`, `disasm`, `decompile`; B001 shared-thunk report. | Target Rejected Alternatives / Ownership Analysis | incorporate | applied: target Observed Contents, Evidence, Assignment Decision, and Rejected Alternatives document the shared wrapper/thunk caveat. |
| C-0002Z8-07 | No direct xref or VA/RVA pointer route exists to target start or successor; vtable-base VA hits are only constructor immediates. | High | MCP `xrefs_to`, capped `find_bytes`. | Target Evidence / Negative Evidence Summary | incorporate | applied: target Evidence records no direct xrefs and no VA/RVA pointer route, including constructor-immediate-only hits for the vtable bases. |
| C-0002Z8-08 | Formal C++ should remain the exact source-declared/generated-binary marker, not a blank block and not a hand-authored vtable array. | High | `by-structure.md` generated-binary policy; target current block; MCP proves data-only vtable page. | Target `RECONSTRUCTION_CPP CODE` | already-present | already-present: target formal marker was left unchanged exactly as accepted; no vtable array was added. |
| C-0002Z8-09 | [UID:0000BJ] is the correct direct owner/emitter; [UID:0000P8] is source-family route; [UID:0000MY] remains a plausible but unproven dedicated file route. | High | Current class/file docs, generated coverage, MCP RTTI/vtable names and constructor route. | Target Assignment Decision / Source Placement | incorporate | applied: target Assignment Decision, Rejected Alternatives, Generated Route Notes, and Open Questions Resolved document owner/source-placement reasoning and rejected moves. |
| C-0002Z8-10 | [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) should add `[[CHILDREN]]` after its current class-route marker to restore generated child marker emission. | Medium-high | Historical pre-callback generated `WeatherLayerPane.cpp` lacked UID0002Z8 though coverage routed it as coded; sibling UID0002Z9 appeared through class child route. | Support `by-class/RainingLayerPane.md` formal block | incorporate | applied: `by-class/RainingLayerPane.md` formal block now has `[[CHILDREN]]`; validator `000000007279` passed as callback-time proof. Later generated headers advanced to supervisor-observed `000000007304` and latest B003-observed `000000007309`; both observations still include UID0002Z8 at lines 9-10. |
| C-0002Z8-11 | `by-file/RainingLayerPane.md` and `by-file/WeatherLayerPane.md` already capture the file-split caveat and do not require default score or metadata changes for this target. | Medium-high | Read-only support review. | Support file docs | already-present | already-present: no file support docs were edited; target now states the same file-split caveat and no callback scope required file-score changes. |
| C-0002Z8-12 | Generated output should be checked after validation: `WeatherLayerPane.cpp` should eventually include UID0002Z8 marker after the class route repair; generated files must not be edited manually. | Medium-high | Generated coverage row, generated source read-only freshness observations. | Target Generated Notes / Checklist | incorporate | applied: generated output was inspected read-only after validators; callback header `000000007279` / `2026-07-05T17:51:47-04:00` is historical proof. Later supervisor and B003 observations saw headers `000000007304` / `2026-07-05T18:22:19-04:00` and `000000007309` / `2026-07-05T18:30:44-04:00`; UID0002Z8 marker remained at lines 9-10. Final current-header verification remains supervisor-owned before `execute_report` because unrelated validators can advance generated output. |
| C-0002Z8-13 | No validators or lifecycle/archive/report-execution commands were run during this report-only pass. | High | Agent command history for this pass. | Validator Results / Changed Files | not-applicable | applied/not-applicable: report-only phase remained validator/lifecycle-free; callback ran only scoped file validators `000000007278` and `000000007279`; no lifecycle/archive/execute command was run. |

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md` and `by-class/RainingLayerPane.md` immediately before editing. Proof: `python leaser.py B003 lease ...` returned `Success` for both files.
- [x] Apply C-0002Z8-01 metadata score change to `88/92` only. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BJ`, blank optional emitter position, `Nested:0`, and formal marker are unchanged.
- [x] Apply C-0002Z8-02 through C-0002Z8-07 evidence details to the target Summary, Observed Contents, Evidence, Assignment Decision, Score Rationale, and Changes sections. Proof: target now includes exact `0x90` range, Dword Layout, current MCP session, constructor stores, virtual slots, shared thunk caveat, negative xref/pointer facts, and source-placement reasoning.
- [x] Preserve C-0002Z8-08 formal marker exactly; do not add a vtable array. Proof: target `RECONSTRUCTION_CPP CODE` still contains only `// RainingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.`
- [x] Preserve C-0002Z8-09 owner/emitter/reconstructable fields exactly. Proof: target metadata still has `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BJ`, blank optional emitter.
- [x] Apply C-0002Z8-10 to `by-class/RainingLayerPane.md` by adding `[[CHILDREN]]` after the current class-route marker; do not change class score by default. Proof: support formal block now contains `[[CHILDREN]]`; class metadata remains `86/88`.
- [x] Mark C-0002Z8-11 as already-present for support file docs. Proof: `by-file/RainingLayerPane.md` and `by-file/WeatherLayerPane.md` were not edited; accepted scope only authorized `by-class/RainingLayerPane.md`, and the target now carries the relevant file-split caveat.
- [x] Run scoped target validator. Proof: `python .\tools\validator.py --mode file --file by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md --apply --queue-timeout 240`; command `000000007278`, timestamp `2026-07-05T17:51:39-04:00`, exit `0`, `ok:1`.
- [x] Run scoped support validator. Proof: `python .\tools\validator.py --mode file --file by-class/RainingLayerPane.md --apply --queue-timeout 240`; command `000000007279`, timestamp `2026-07-05T17:51:47-04:00`, exit `0`, `ok:1`.
- [x] Inspect generated `auto-generated/NexusTK/map/WeatherLayerPane.cpp` read-only after validation/generation refresh. Proof: callback-time generated header `000000007279` / `2026-07-05T17:51:47-04:00` proved the support repair. Later freshness observations are snapshots rather than current-state guarantees: supervisor observed `000000007304` / `2026-07-05T18:22:19-04:00`, and latest B003 report-time read observed `000000007309` / `2026-07-05T18:30:44-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0002Z8 marker still appeared at lines 9-10 in those later observations.
- [x] Release all B003 leases immediately after the edit/validator/freshness batch. Proof: `python leaser.py B003 unlease ...` returned `Success` for both files. Final lease check shows no active B003 leases; a later unrelated B005 lease exists on sibling `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`.
- [x] Update this report's ledger/checklist with applied/already-present/not-applicable states and validator command metadata before Gate 2 return. Proof: this section and ledger updated after validation.
- [x] Ledger rows use only allowed action states: `incorporate`, `already-present`, or `not-applicable`; verification states are now callback states with proof.

## Validator Results

Report-only phase: validators were intentionally not run.

Implementation callback validators:

| Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md --apply --queue-timeout 240` | `000000007278` | `2026-07-05T17:51:39-04:00` | `0` | `1` | Reported `completion_update 0002Z8 88`, `confidence_update 0002Z8 92`, `uid_link_insert` rows, `projected_stats_update:1`, `generated_refresh: deferred`. Missing-ref UID warnings for `0003PK`, `0003PJ`, and `0003PH` were pre-existing registry gaps for linked exact child UIDs, not target validation failure. |
| `python .\tools\validator.py --mode file --file by-class/RainingLayerPane.md --apply --queue-timeout 240` | `000000007279` | `2026-07-05T17:51:47-04:00` | `0` | `1` | Reported `autogen_registry_update 0000BJ`, `projected_stats_update:1`, `generated_refresh: deferred`. Missing-ref UID warnings for `0003PI`, `0003PJ`, and `0003PK` were pre-existing registry gaps for linked exact children, not support validation failure. |

Generated freshness:

- `auto-generated/NexusTK/map/WeatherLayerPane.cpp` was inspected read-only after validation.
- Historical callback-time generated header: `validator-command-id: 000000007279`, `validator-refreshed-at: 2026-07-05T17:51:47-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Supervisor freshness observation after a later unrelated refresh: `validator-command-id: 000000007304`, `validator-refreshed-at: 2026-07-05T18:22:19-04:00`; UID0002Z8 remained at lines 9-10.
- Latest B003-observed generated header during this report-text repair: `validator-command-id: 000000007309`, `validator-refreshed-at: 2026-07-05T18:30:44-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- UID0002Z8 remained present in the latest B003-observed generated output: line 9 contained `// UID:0002Z8 | by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md | Completion:88 | Confidence:92`, line 10 contained the exact Rain vtable marker.
- Generated `WeatherLayerPane.cpp` is shared and may advance again due unrelated validators. The supervisor must perform final current generated-header verification before `execute_report`; the durable incorporated claim is that the UID0002Z8 marker persisted across callback-time and later B003/supervisor observations after the route repair.

## Changed Files

Report-only phase changed only the report artifact.

Implementation callback changed by-* docs:

- `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`
- `by-class/RainingLayerPane.md`

Report artifact updated after implementation:

- `tools/leaser/Agents/Agent-B003/research/0002Z8-RainingLayerPaneVtableData-source-quality.md`

Validator-generated refresh observed, not manually edited:

- `auto-generated/NexusTK/map/WeatherLayerPane.cpp` refreshed by callback validator command `000000007279` as historical proof and was later observed by supervisor at header `000000007304` and by B003 at header `000000007309`; UID0002Z8 remained present at lines 9-10. Generated files were inspected read-only only, and no generated file was edited manually.

No coverage reports, supervisor ledgers, validator state files, lifecycle/archive files, IDA database state, or report archive/execution locations were edited manually. No `execute_report` or lifecycle/archive command was run.

## Open Questions With Attempted Resolution

1. Should UID0002Z8 become `RECONSTRUCTABLE:FALSE` because it is compiler-emitted vtable data?

   Resolved: no. Current `by-structure.md` treats source-declared/generated-binary artifacts as reconstructable when source declarations and exact virtual method pages are required. UID0002Z8 is an exact class-owned vtable child, not a mixed audit container.

2. Should UID0002Z8 move from [UID:0000BJ] to [UID:0000P8] or [UID:0000MY]?

   Resolved: no for this callback. [UID:0000BJ] is the direct semantic owner. [UID:0000P8] is the current source-family route through the class page, and [UID:0000MY] remains plausible but unproven.

3. Is the generated-output mismatch a target error?

   Resolved: pre-callback generated output lacked the child marker because [UID:0000BJ]'s formal block had no `[[CHILDREN]]`, not because target owner/emitter was invalid. Callback scope allowed the support repair, `[[CHILDREN]]` was added, and validator `000000007279` proved UID0002Z8 generation at callback time. Later generated headers are moving freshness observations rather than permanent current-state guarantees; supervisor-observed `000000007304` and latest B003-observed `000000007309` both still contained UID0002Z8 at lines 9-10.

4. Are the shared destructor/adjustor thunk slots evidence that this target belongs to ButtonControlPane/SelectBox shared pages?

   Resolved: no. MCP shows those functions are shared slot values across ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane. They explain inherited/destructor mechanics but do not own the Rain vtable page.

## Final Recommendation

Implemented recommendation: target evidence refresh and score raise to `88/92` are applied, owner/emitter/reconstructable/formal marker are unchanged, and [UID:0000BJ]'s class-child generation route is repaired with `[[CHILDREN]]`. No split, rename, broad reclassification, no-owner conversion, or hand-authored C++ vtable array was applied or remains recommended.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000007314","destination_path":"executed-b-agent-research/B003/0002Z8-RainingLayerPaneVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002Z8-RainingLayerPaneVtableData-source-quality.md","timestamp":"2026-07-05T18:40:52-04:00","uid":"0002Z8"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002Z8-RainingLayerPaneVtableData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002Z8-RainingLayerPaneVtableData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002Z8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
