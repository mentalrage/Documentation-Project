** TARGET-REPORT-UID:0002RW **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B006 Source-Quality Report: [UID:0002RW] LivingObjectPaneGetViewportPosition

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002RW-LivingObjectPaneGetViewportPosition-source-quality.md`  
Target path: `source-3/project-documentation/by-memory/0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition.md`  
Mode: report-only. No by-* docs, generated docs, project-level files, validator/tool state, IDA database files, or coverage reports were edited.

## Recommendation

Implement the target as a small exact `LivingObjectPane` child method in `NexusTK/map/LivingObjectPane.cpp`, keep owner/emitter [UID:0000KU] `by-file/LivingObjectPane.md`, keep `RECONSTRUCTABLE:TRUE`, and raise the target from `85/88` to `90/91`.

The blank C++ blocker is narrow and now resolved for this exact child: the output type is the same two-int `MapPoint` family used by [UID:0002QL] `MapPane::ScrollViewportByDirection` and [UID:0002QM] `MapPane::RecenterAndSendPosition`. The important source-quality detail is element order. The project map/point convention here is row/y first and column/x second:

```cpp
MapPoint *LivingObjectPane::GetViewportPosition(MapPoint *outPosition) const
{
    outPosition->y = m_viewportRow;
    outPosition->x = m_viewportColumn;
    return outPosition;
}
```

If the shared point type is later spelled `row/column` instead of `y/x`, use the equivalent row-first assignment. Do not rewrite this as `x = column; y = row` unless the shared `MapPoint` declaration is proven to store x first; the binary stores the column/x value at output element 1 and the row/y value at output element 0.

Recommended field names for this target:

| Offset | Decimal | Recommended name | Alias | Evidence |
| --- | ---: | --- | --- | --- |
| `this+0x13ead8` | `1305304` | `m_viewportColumn` | `m_viewportX` / `m_viewportOffsetX` | `WarpToPosition` stores argument 3 here; getter returns it through output element 1. |
| `this+0x13eadc` | `1305308` | `m_viewportRow` | `m_viewportY` / `m_viewportOffsetY` | `WarpToPosition` stores argument 4 here; getter returns it through output element 0. |

Prefer target prose such as "cached viewport row/column" or "viewport offset pair". Avoid calling this pair screen pixels. The older `screenX/screenY` wording in `WarpToPosition` is historical/descriptive; the MapPane consumers validate the pair against visible tile columns/rows and packetize viewport offsets.

## Evidence Used

### Current IDA MCP

MCP was available and responsive.

- Listener status before evidence calls: `127.0.0.1:13337` listening, owning process `13684`.
- Process status: `idalib-mcp` process present at PID `17084`; active IDA worker session PID `26892`.
- `idb_list`: active worker session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, owned/adopted worker.
- `server_health` for `80de0a67`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

Target function facts from MCP session `80de0a67`:

- `lookup_funcs` reports `sub_5A2DE0` at `0x005a2de0`, size `0x1b`.
- `lookup_funcs` reports `0x005a2dfb` is not a function and `0x005a2e00` is successor `sub_5A2E00`, size `0x8de`.
- `int_convert.py` verifies `0x1b` = 27, `0x13ead8` = 1305304, and `0x13eadc` = 1305308.
- `analyze_function` reports prototype `_DWORD *__thiscall(_DWORD *this, _DWORD *)`, size 27, one basic block, cyclomatic complexity 1, no callees, and callers `sub_5058B0`, `sub_5059D0`, `sub_50C790`, `sub_50D010`.
- `xrefs_to 0x005a2de0` reports four code xrefs: `0x0050591f` in `sub_5058B0`, `0x00505a01` in `sub_5059D0`, `0x0050c87e` in `sub_50C790`, and `0x0050d159` in `sub_50D010`.
- `xrefs_to 0x005a2dfb` reports no cross-references to the endpoint.
- `callees` reports no callees.
- `get_bytes 0x005a2de0 size 32` returns the 27-byte body followed by five `0xcc` bytes: `55 8b ec 8b 45 08 8b 91 d8 ea 13 00 8b 89 dc ea 13 00 89 50 04 89 08 5d c2 04 00 cc cc cc cc cc`.

Exact target body:

```asm
0x005a2de0  push ebp
0x005a2de1  mov  ebp, esp
0x005a2de3  mov  eax, [ebp+arg_0]
0x005a2de6  mov  edx, [ecx+13EAD8h]
0x005a2dec  mov  ecx, [ecx+13EADCh]
0x005a2df2  mov  [eax+4], edx
0x005a2df5  mov  [eax], ecx
0x005a2df7  pop  ebp
0x005a2df8  retn 4
```

Hex-Rays agrees:

```cpp
result = a2;
v3 = this[326326];
v4 = this[326327];
a2[1] = v3;
*a2 = v4;
return result;
```

Producer evidence from `0x005a5a90` / [UID:0003UE] `WarpToPosition`:

```asm
0x005a5b10  mov eax, [ebp+arg_8]
0x005a5b19  mov [edi+13EAD8h], eax
0x005a5b1f  mov eax, [ebp+arg_C]
0x005a5b27  mov [edi+13EADCh], eax
```

This proves `+0x13ead8` is the third viewport argument and `+0x13eadc` is the fourth viewport argument. [UID:0003UV] B010 and the current docs name those third/fourth position-sync fields `viewportX` and `viewportY` / `viewportOffsetX` and `viewportOffsetY`. The getter returns them as element 1 then element 0, matching the project row/y-first point storage convention also documented for `ObjectPane::GetMapPosition`.

### Caller Semantics

The four callers are all map-side consumers, not alternate owners.

1. `0x005058b0` / [UID:0002QL] `MapPane::ScrollViewportByDirection`
   - MCP decompile calls `sub_5374D0` into a local pair, then calls `sub_5A2DE0` on `MapPane+0x418`, then calls `sub_50BCE0(v10, mapElement1, mapElement0, viewportElement1, viewportElement0, direction)`.
   - Existing first-draft C++ already uses `MapPoint viewportPosition; m_activeObjectPane->GetViewportPosition(&viewportPosition);`.

2. `0x005059d0` / [UID:0002QM] `MapPane::RecenterAndSendPosition`
   - MCP decompile calls this accessor only when `useActiveObjectViewport` is set.
   - Element 1 is checked against visible tile columns; element 0 is checked against visible tile rows.
   - Existing first-draft C++ already uses `MapPoint oldViewport; m_activeObjectPane->GetViewportPosition(&oldViewport);`.

3. `0x0050c790` path scan
   - MCP disassembly window around `0x0050c87e` first calls `ObjectPane::GetMapPosition`, then calls this accessor through `MapPane+0x418`, subtracts output element 0 from the first map-position element and output element 1 from the second map-position element, and seeds viewport-relative path-grid locals.

4. `0x0050d010` path scan
   - MCP disassembly window around `0x0050d159` repeats the same map-position/get-viewport/subtract pattern for the sibling path scan.

These consumers explain the four map-side xrefs and reject a MapPane ownership move: MapPane reads the active local object viewport state, but the state lives on the `LivingObjectPane` receiver.

## Ownership And Placement

Ranked placement:

1. [UID:0000KU] `LivingObjectPane` by-file, [UID:00007B] class, exact child page [UID:0002RW]: accepted. The body uses `ecx` as the living-object receiver, reads adjusted local-player viewport fields, has no MapPane receiver fields, and sits in the [UID:0001KM] local-player extension split.
2. [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`: keep as non-emitting split index. It should list this exact child and summarize the resolved row/column offsets, but it should not emit this method itself.
3. [UID:00007Q] `MapPane`: rejected as owner. All four xrefs are consumer/caller contexts; two named first-draft MapPane methods already call `GetViewportPosition` on `m_activeObjectPane`.
4. [UID:00009R] `ObjectPane`: rejected as owner. `ObjectPane::GetMapPosition` is a parallel base-position accessor with the same two-int output convention, but this target reads local-player viewport fields not base object fields.
5. [UID:0000FQ] / `UserPane`: rejected as owner. UserPane installs or drives local-player flow in nearby code, but this leaf is a `LivingObjectPane` thiscall and not a UserPane virtual/helper.
6. No-owner/raw-helper/padding/compiler-generated: rejected. IDA has a modeled function, direct code xrefs, a normal `thiscall` output-pointer ABI, no switch/data-table role, and exact `0xcc` padding after the body.

## Current Docs Reviewed

- Target [UID:0002RW] `by-memory/0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition.md`
- [UID:0000KU] `by-file/LivingObjectPane.md`
- [UID:00007B] `by-class/LivingObjectPane.md`
- [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- [UID:0002QL] `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md`
- [UID:0002QM] `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`
- [UID:0003XP] `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`
- [UID:0003UE] `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`
- [UID:0003UV] `by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md`
- Executed B010 report `executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md`
- Coordinate-support docs [UID:00041W] `MapPaneDirectionToTileOffset`, [UID:00041Z] `MapPaneValidateMapAndViewportCoords`, and [UID:0000T7] `MapTilePixelDimensions`

## Implementation Notes

Target page update should:

- Set `COMPLETION:90` and `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank optional emitter position.
- Populate the `RECONSTRUCTION_CPP` block with the first-draft C++ above.
- Replace "world-position" wording with "cached viewport row/column" or "viewport offset pair".
- Add the live MCP session `80de0a67` evidence: health, exact size, disassembly, bytes, xrefs, no callees, endpoint/successor boundary, and producer store order from `WarpToPosition`.
- State explicitly that `+0x13ead8` is column/x and `+0x13eadc` is row/y, while the output pointer is row/y first and column/x second.
- Note that this closes the target-level blank-C++ blocker but does not close the broader `MapPoint`/coordinate-order cleanup for unrelated accessors such as [UID:0003XP].

Support-doc updates should be scoped:

- [UID:0000KU] by-file and [UID:00007B] by-class: add this exact child to the local-player movement/accessor family as `GetViewportPosition(MapPoint *) const`, with the row/column offset model. Preserve broad class/file C++ blank.
- [UID:0001KM] aggregate: update the `0x005a2de0-0x005a2dfb` row from generic viewport/world-position wording to the resolved row/column accessor and mention exact child C++ eligibility.
- [UID:0002QL] and [UID:0002QM]: if touched, clarify that the active-object viewport getter returns the same row/y-first `MapPoint` convention they already use. Do not rewrite their accepted first-draft bodies unless the supervisor wants a wider point-type cleanup.
- [UID:0003UE] and [UID:0003UV]: replace the old "internal ordering provisional in [UID:0002RW]" caveat with the resolved offset order: third viewport argument -> `+0x13ead8` -> output element 1; fourth viewport argument -> `+0x13eadc` -> output element 0.
- [UID:0003XP] `ObjectPaneGetMapPosition`: optional back-reference only. Its separate base-coordinate C++ can remain blank because broader `MapPoint` declaration/original spelling still affects that accessor.

Expected validator runs after implementation are per edited by-* file, for example:

> Executable block R001 was removed from this report and preserved verbatim in [0002RW-LivingObjectPaneGetViewportPosition-source-quality-removed.md](0002RW-LivingObjectPaneGetViewportPosition-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add validator runs for `0002QL`, `0002QM`, `0003UE`, `0003UV`, or any other support page only if implementation edits those pages. Generated/project-level/manual coverage files should refresh only through approved tooling, not manual edits.

## Open Caveats

- Exact original symbol spellings are not recovered. The report recommends descriptive names `m_viewportRow` and `m_viewportColumn`.
- The broader shared `MapPoint` declaration remains a project-wide cleanup item. This target is safe because the output order is now explicitly documented and the first-draft C++ uses row/y-first assignment.
- Broad [UID:0000KU] file and [UID:00007B] class C++ should remain blank; exact child C++ is the correct emission unit.

## Implementation Checklist

- [x] Update [UID:0002RW] metadata to `COMPLETION:90`, `CONFIDENCE:91`, with unchanged owner/emitter/reconstructable fields. Proof: target header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000KU`; validator command `000000003016` (`2026-06-26T17:06:44-04:00`) reported `completion_update 0002RW 90`, `confidence_update 0002RW 91`, `canonical_owner_update 0002RW 0000KU`, exit `0`, `ok: 1`.
- [x] Insert the formal first-draft `LivingObjectPane::GetViewportPosition(MapPoint *outPosition) const` C++ block with row/y-first and column/x-second assignment. Proof: target `RECONSTRUCTION_CPP` now contains the accepted `MapPoint *LivingObjectPane::GetViewportPosition(MapPoint *outPosition) const` block assigning `outPosition->y = m_viewportRow;` and `outPosition->x = m_viewportColumn;`; validator `000000003016` reported `autogen_registry_update 0002RW ... blank -> block`, exit `0`, `ok: 1`.
- [x] Add the MCP session `80de0a67` evidence: server health, listener/process status summary, lookup size, endpoint/successor, no callees, four xrefs, disassembly/decompile, and byte span with five `0xcc` padding bytes. Proof: target section `2026-06-26 IDA MCP Evidence` records listener/process status, `server_health` `ok`, `lookup_funcs` size `0x1b` / 27, endpoint `0x005a2dfb` not-a-function, successor `0x005a2e00`, no callees, four xrefs, exact disassembly, Hex-Rays output, and byte span `55 ... c2 04 00 cc cc cc cc cc`.
- [x] Document `+0x13ead8 = m_viewportColumn/m_viewportX` and `+0x13eadc = m_viewportRow/m_viewportY`, including the `WarpToPosition` store evidence. Proof: target `Field Model` and `Producer And Caller Evidence` sections document both offsets, decimal values, aliases, output slots, and producer stores at `0x005a5b10/0x005a5b19` and `0x005a5b1f/0x005a5b27`.
- [x] Update [UID:0000KU], [UID:00007B], and [UID:0001KM] support prose for the resolved exact child and keep broad source blocks blank. Proof: updated `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`, and `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md` with exact child source placement and row/column offset model while leaving their `RECONSTRUCTION_CPP` blocks blank; validators `000000003020`, `000000003024`, and `000000003025` all exited `0` with `ok: 1`.
- [x] If editing [UID:0002QL]/[UID:0002QM]/[UID:0003UE]/[UID:0003UV], keep changes to cross-reference/order caveats only; do not widen into a project-wide `MapPoint` refactor. Proof: [UID:0003UE] and [UID:0003UV] now replace provisional viewport-pair wording with third argument -> `+0x13ead8` -> output element 1 / column and fourth argument -> `+0x13eadc` -> output element 0 / row; [UID:0002QL] and [UID:0002QM] only add resolved getter-order notes and leave existing first-draft C++ bodies unchanged. Validators `000000003026`, `000000003027`, `000000003028`, and `000000003029` all exited `0` with `ok: 1`.
- [x] Run scoped validators for every edited by-* doc and capture logs under the implementing agent, without manually editing generated/project-level/manual coverage/tool-state/IDA DB files. Proof: ran `python .\tools\validator.py --mode file --file ... --apply --queue-timeout 240` for target/support files with command IDs `000000003016`, `000000003020`, `000000003024`, `000000003025`, `000000003026`, `000000003027`, `000000003028`, and `000000003029`; all had exit `0` and `ok: 1`. No manual edits were made to generated/project-level/manual coverage/tool-state/IDA DB files or any `-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002RW-LivingObjectPaneGetViewportPosition-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002RW-LivingObjectPaneGetViewportPosition-source-quality.md","timestamp":"2026-06-26T17:11:51","uid":"0002RW"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RW-LivingObjectPaneGetViewportPosition-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002RW-LivingObjectPaneGetViewportPosition-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
