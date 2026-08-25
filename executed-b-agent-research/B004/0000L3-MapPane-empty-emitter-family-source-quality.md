** TARGET-REPORT-UID:0000L3 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000L3] MapPane empty-emitter family source-quality report

## Report Metadata

- Agent: Agent-B004
- Assignment: `B004-report-0000L3-MapPane-empty-emitter-family-20260629`
- Target family: [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) / `auto-generated/NexusTK/map/MapPane.cpp`
- Report path: `tools/leaser/Agents/Agent-B004/research/0000L3-MapPane-empty-emitter-family-source-quality.md`
- Original report-only pass: no by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files were edited before supervisor acceptance.
- Implementation callback: accepted narrowed first batch applied to target/support by-* docs; generated/tracker updates were validator-owned only.
- MCP session: `supervisor_resume_20260629`
- MCP evidence window: 2026-06-29T22:11:40-04:00 through 2026-06-29T22:27:42-04:00

## Executive Disposition

FINISHED_REPORT.

The MapPane empty-emitter family is not one homogeneous blocker. It splits into six implementation classes:

1. Small exact body ready for first-draft C++: [UID:0001AQ] `ScaleDirectionOffsetToPixels`; [UID:0000VC] should become a non-duplicating by-item covered marker.
2. Static data declarations ready for first-draft C++ or covered-storage comments: [UID:0000T7], [UID:0001OJ], [UID:0001OK], [UID:0000PR], [UID:0001OW], [UID:0002ZJ], [UID:0002ZN], [UID:00027F], [UID:00027O], [UID:00027Q], and [UID:0002AZ].
3. Compiler/generated-binary or support-container rows that should get explicit no-code formal comments, not function bodies: [UID:0002SQ], [UID:00042K], [UID:0001AX], and [UID:0001AZ].
4. Mixed aggregates that should not emit a single body: [UID:0001AW] should become a non-emitting split/container after preserving its exact child inventory; [UID:00037Q] needs exact child pages before the aggregate is retired as a split/container.
5. Source bodies with strong evidence but not safe whole-body C++ in this batch: [UID:0002QJ], [UID:0002QK], [UID:00037T], [UID:0003TF], and [UID:0003TL]. Each has exact owner/range behavior; the implementation path is bounded below, not deferred to open-ended research.
6. Declaration/index rows that should stay documentation-only until dependent names stabilize: [UID:00007Q], [UID:00027N], and [UID:0001SO].

Recommended immediate implementation callback:

- Apply the formal C++ and formal no-code comments listed in "Formal C++ Blocks For Accepted Batch".
- Update support summaries for [UID:0002AZ], [UID:0002SQ], [UID:0003TF], [UID:0003TL], [UID:0001AW], [UID:00037Q], and [UID:0000L3] to record the current distinctions.
- Do not attempt a full packet dispatcher reconstruction or 256-entry checksum literal in the first callback.

## Current Generated State

Generated `auto-generated/NexusTK/map/MapPane.cpp` is validator-owned output. It was read only.

| Artifact | Current header/state |
| --- | --- |
| `auto-generated/NexusTK/map/MapPane.cpp` | `validator-command-id: 000000001286`, refreshed `2026-06-29T22:06:24-04:00` |
| Visible `Empty Emitter Marker` comments in `MapPane.cpp` | 27 |
| `auto-generated/-ag-research-tracker.md` | `validator-command-id: 000000001315`, refreshed `2026-06-29T22:21:45-04:00` |
| Tracker family row | [UID:0000L3] reports `74` total emitters, `45` filled, `29` empty, `60.8%`, generated path `auto-generated/NexusTK/map/MapPane.cpp` |
| Direct report count row | [UID:0000L3] row reports direct report count `0` |

Generated-state discrepancy: the newer tracker still reports `29` empty emitters for [UID:0000L3], while the currently checked `MapPane.cpp` file has `27` visible empty marker comments. This report uses the concrete `MapPane.cpp` marker inventory below and records the tracker row as stale/freshness evidence to be reconciled by validator refresh after implementation.

## MCP Availability And Current Evidence

MCP remained available. No fallback-only evidence was used.

| MCP call | Result |
| --- | --- |
| JSON-RPC `101`, `server_health(database=supervisor_resume_20260629)` | `status:"ok"`, uptime `2780.056`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready, module `NexusTK.exe`, imagebase `0x400000` |
| JSON-RPC `112`, `idb_list` | One active session `supervisor_resume_20260629`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker_pid `17592` |
| JSON-RPC `221`, `analyze_function(0x00505100)` | `sub_505100`, prototype `int __stdcall(int *)`, size `36`, one block, no callees, seven callers, decompile multiplies `a1[1]` by `word_66DA9C` and `a1[0]` by `word_66DAA0`, returns `a1[0]` |
| JSON-RPC `222`, `decompile(0x00505100)` | Same code and refs to `word_66DA9C` and `word_66DAA0` |
| JSON-RPC `223`, `analyze_function(0x0050ea30)` | `sub_50EA30`, size `346`, callers from `sub_50E320` and `sub_50E850`, callees include `sub_4B1400`, `sub_5387B0`, `sub_5314A0`, `sub_5388A0`, `sub_53AE10`, `sub_53ADB0`, and `sub_597910`; confirms the current `EffectInfo` by-value ABI and timer behavior |
| JSON-RPC `224`, `analyze_function(0x00504b90)` | `sub_504B90`, prototype `void __thiscall(int,unsigned __int16,int)`, size `609`, callers `0x0050bcad` and `0x00510746`, confirms Documents/NexusTK/Maps `TK%06d.cmp`, `CMAP`, width/height validation, tile reset, AUTOBUF, and zlib uncompress |
| JSON-RPC `225`, `analyze_function(0x00504e00)` | `sub_504E00`, prototype `FILE *__thiscall(int)`, size `629`, callers `0x0050458b`, `0x0050483e`, `0x0050bbe7`, `0x00510671`, confirms `CMAP` save, zlib compress, tile-buffer free/clear, monster image cache refresh |
| JSON-RPC `241`, `get_bytes` | Confirms `0x0066da90` neighborhood, `0x0066db48` pointer plus checksum-table opening, direction masks at `0x0066dd50`, 96-byte day/night float table at `0x0066dd78`, and zero-filled `0x0069b4f4-0x0069b504` |
| JSON-RPC `242`, `get_int` | `byte_66DA96 == 1`, `word_66DA9C == 48`, `word_66DAA0 == 48`, `dword_66DB48 == 0x0061e6f0`, `byte_69B4F8 == 0` |
| JSON-RPC `243`, `xrefs_to` selected data | `0x0066db48` has exactly two xrefs in load/save; `0x0066db50` has eight checksum refs; `0x0066dd50` and `0x0066dd58` have two refs each; `0x0066dd78` has four refs; `0x0069b4f8` has two refs |
| JSON-RPC `244-246`, active MapPane singleton | `0x0067a764` bytes are zero, value `0`, xref sample is broad and includes constructor/lifecycle/minimap/application/map consumers |
| JSON-RPC `247`, vtable bytes | Confirms the 132-byte `0x0061e71c-0x0061e7a0` MapPane vtable group bytes and slot sequence documented by [UID:0002SQ] |
| JSON-RPC `251`, `lookup_funcs` object/dispatcher starts | Confirms object helper starts at `0x00506970`, `0x00506980`, `0x00506ae0`, `0x00506b30`, `0x00506b80`, `0x00506bd0`, `0x00506c20`, `0x00506c70`, `0x00506cc0`; dispatcher `0x00507c90` size `0x1176`; `0x00508e06` not a function; next helper `0x00508f60` |
| JSON-RPC `252-253`, object helper analysis | Confirms `0x00506970` calls `sub_532370(this[265], objectId)` and has high fanout; `0x00506980` is a larger MapPane/object coordinate helper with tile globals and movement-scale dependency |

## Prior Report Search

No direct executed report for [UID:0000L3] was found. Relevant prior executed or in-agent reports used as support:

| Report | Relevance |
| --- | --- |
| `executed-b-agent-research/B002/00007Q-MapPane-class-source-quality.md` | MapPane class owner and class-page blank/declaration-container policy |
| `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md` | Coordinate/movement/tile helper split and [UID:00042K] layout support context |
| `executed-b-agent-research/B005/00037Y-MapPaneTileObjectGridRenderCore-source-quality.md` | Checksum/direction-mask helper names and no-route helper handling |
| `executed-b-agent-research/B013/00037U-MapPaneNotifyTimerCore-source-quality.md` | Precedent for converting broad MapPane split parents to non-emitting containers with exact child methods |
| `executed-b-agent-research/B013/000424-MapPaneGetUnclampedExtendedVisibleTileBounds-source-quality.md` | Precedent for raw/no-route MapPane family helpers: source family can be MapPane while generated route remains withheld |
| `executed-b-agent-research/B008/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md` | Uses [UID:0003TF] `MapPane::CreateEffectObjectPane` signature and effect descriptor routing |
| `executed-b-agent-research/B003/0003P9-SharedEpfSuffixString-current-source-routing.md` | Shared literal/source-use policy for MapPane map-info helper dependencies |

## Empty Marker Inventory And Disposition

| UID | Target | Current generated marker | Disposition |
| --- | --- | --- | --- |
| 00007Q | `by-class/MapPane.md` | Class page empty marker | Keep class-page C++ blank/declaration-container policy. Add/refresh note that first-draft bodies/data emit through exact child/global pages, not the class page. Do not emit a class declaration until field and payload names are synchronized. |
| 0002QJ | `0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile` | Exact source method empty marker | Strong exact evidence but not first callback C++; method names, reset helper name, and AUTOBUF/StdioFile style remain below final source quality. Keep routed to [UID:00007Q] and add current MCP evidence; bounded follow-up after helper declarations. |
| 0002QK | `0x00504e00-0x00505075.MapPaneSaveCompressedMapFile` | Exact source method empty marker | Same as [UID:0002QJ]. Direct CRT stream path and AUTOBUF style need a helper-declaration pass before formal C++. |
| 00037Q | `0x00506970-0x00506cdd.MapPaneObjectLookupHelpers` | Multi-helper aggregate empty marker | Do not emit a single C++ body. Split exact children using the function table below, then retire aggregate as non-emitting split/container. |
| 00037T | `0x00507c90-0x00508f60.MapPanePacketDispatcher` | Dispatcher plus switch-table empty marker | Keep reconstructable and routed. Do not emit whole dispatcher until packet payload structs and case names stabilize. Preserve table tail `0x00508e06-0x00508f60` as switch data. |
| 0001AW | `0x0050e4c0-0x00514920.MapPanePacketHandlers` | Broad packet-handler aggregate empty marker | Convert to non-emitting split/container after preserving exact child inventory. Existing exact children and retained raw duplicate proofs mean a parent body would duplicate or collapse source placement. |
| 0003TF | `0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane` | Exact source helper empty marker | Keep exact child; add missing Item Summary and current MCP evidence. Signature is stable for callers, but full helper-local body still depends on final `EffectInfo` member names. |
| 0003TL | `0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket` | Exact source packet handler empty marker | Keep exact child and add missing Item Summary. Do not emit body until payload/map-name/tile descriptor fields are named; support dependency on PaletteLib is resolved as callee-only. |
| 0002SQ | `0x0061e71c-0x0061e7a0.MapPaneVtableData` | Vtable data empty marker | Add explicit formal no-code comment. Vtable bytes are compiler-generated from [UID:00007Q] and exact virtual method children; no hand-authored table. Also fix stale item-summary wording that says it is unassigned. |
| 00042K | `by-type/by-struct/MapPaneLayout.md` | Layout support empty marker | Add explicit formal no-code comment or mark non-emitting support-only. This is an offset ledger, not a standalone struct declaration. |
| 0002ZJ | `by-global/MapPaneCmapSignaturePointer.md` | Static data empty marker | First-draft source declaration ready: file-local `const char *` initialized to `"CMAP"`. |
| 0000T7 | `by-global/MapTilePixelDimensions.md` | Static data empty marker | First-draft source declarations ready: two signed 16-bit globals initialized to `48`. Current MCP confirms `movsx` consumers. |
| 0001OJ | width storage child | Storage child empty marker | Add non-duplicating formal covered-by comment pointing to [UID:0000T7]. |
| 0001OK | height storage child | Storage child empty marker | Add non-duplicating formal covered-by comment pointing to [UID:0000T7]. |
| 0000PR | `by-global/g_activeMapPane.md` | Static pointer empty marker | First-draft source declaration ready: `static MapPane *g_activeMapPane = NULL;`, with final spelling still descriptive. |
| 0001OW | active pointer storage child | Storage child empty marker | Add non-duplicating formal covered-by comment pointing to [UID:0000PR]. |
| 0000VC | by-item alias for `ScaleDirectionOffsetToPixels` | Alias empty marker | Add non-duplicating formal covered-by comment pointing to [UID:0001AQ]. |
| 0001AQ | exact `ScaleDirectionOffsetToPixels` memory child | Exact small helper empty marker | First-draft C++ body ready. Current MCP confirms one-block `__stdcall` helper, seven callers, no callees, exact tile-dimension reads. |
| 0001AX | raw day/night duplicate | Raw duplicate empty marker | Add formal no-code comment. Proven source route is dispatcher opcode `0x20`, not raw start `0x00510400`. |
| 0001AZ | raw friend-sync duplicate | Raw duplicate empty marker | Add formal no-code comment. Proven source route is dispatcher opcode `0x6a`, not raw start `0x00514380`. |
| 00027F | movement-scale storage child | Storage child empty marker | Add covered-by comment pointing to already-emitting [UID:0002CF] `g_movementSubstepScale`. |
| 0002ZN | `CMAP` pointer storage child | Storage child empty marker | Add covered-by comment pointing to [UID:0002ZJ]. |
| 00027N | checksum lookup table | Static data empty marker | Do not implement in first callback. Either emit a 256-entry literal table in a dedicated data pass or generate from a proven CRC algorithm. Current report records exact bytes/xrefs but does not transcribe all entries. |
| 00027O | direction masks | Static data empty marker | First-draft static byte arrays ready. Current MCP confirms exact 16 bytes and four refs. |
| 00027Q | day/night float table | Static data empty marker | First-draft static float table ready. Current MCP confirms exact 96 bytes and four refs. |
| 0002AZ | render scratch flag | Static byte empty marker | First-draft source declaration ready as cached `Shadow` option byte initialized to `0`; fix stale `0xff` item-summary wording. |
| 0001SO | `MapServerPacketOpcode` | Working enum/index empty marker | Keep as dispatcher index, not final emitted enum. Add explicit no-code/declaration-not-final comment only if the implementation callback wants marker removal without promoting provisional labels. |

## Formal C++ Blocks For Accepted Batch

These blocks are implementation-ready if the supervisor accepts the recommended immediate batch.

### [UID:0001AQ] `ScaleDirectionOffsetToPixels`

```cpp
static int __stdcall ScaleDirectionOffsetToPixels(int *tileOffset)
{
    tileOffset[1] *= g_mapTilePixelWidth;
    tileOffset[0] *= g_mapTilePixelHeight;
    return tileOffset[0];
}
```

Current MCP proof: `analyze_function(0x00505100)` and `decompile(0x00505100)` returned `int __stdcall(int *)`, one basic block, no callees, seven callers, and exact operations `a1[1] *= word_66DA9C`, `*a1 *= word_66DAA0`, return `*a1`.

### [UID:0000VC] by-item alias

```cpp
// Emitted code for this helper is covered by [UID:0001AQ].
```

### [UID:0000T7] `MapTilePixelDimensions`

```cpp
static short g_mapTilePixelWidth = 48;
static short g_mapTilePixelHeight = 48;
```

Use `short`, not `int`: current MCP confirms exact two-byte storage and the small helper uses `movsx` from `word_66DA9C` and `word_66DAA0`.

### [UID:0001OJ] and [UID:0001OK] exact storage children

```cpp
// Emitted declarations for these storage words are covered by [UID:0000T7].
```

If validator policy requires one comment per page, use singular wording on each page:

```cpp
// Emitted declaration for this storage word is covered by [UID:0000T7].
```

### [UID:0000PR] `g_activeMapPane`

```cpp
static MapPane *g_activeMapPane = NULL;
```

Current MCP proof: `get_bytes(0x0067a764,4)` and `get_int(0x0067a764,u32le)` return zero; `xrefs_to` shows the broad active-map singleton consumer spread. The final source spelling is still descriptive but strong enough for first draft.

### [UID:0001OW] exact active-pointer storage child

```cpp
// Emitted declaration for this storage pointer is covered by [UID:0000PR].
```

### [UID:0002ZJ] `MapPaneCmapSignaturePointer`

```cpp
static const char *g_mapPaneCmapSignature = "CMAP";
```

Current MCP proof: `get_int(0x0066db48,u32le)` returns `0x0061e6f0`; `xrefs_to(0x0066db48)` returns only the load/save refs at `0x00504ccf` and `0x00504f41`; `get_bytes(0x0066db48,16)` shows pointer `f0 e6 61 00`, four zero bytes, then checksum-table opening bytes.

### [UID:0002ZN] exact CMAP pointer storage child

```cpp
// Emitted declaration for this signature pointer is covered by [UID:0002ZJ].
```

### [UID:00027F] exact movement-scale storage child

```cpp
// Emitted declaration for this storage byte is covered by [UID:0002CF].
```

[UID:0002CF] already emits:

```cpp
static unsigned char g_movementSubstepScale = 1;
```

Current MCP proof: `get_int(0x0066da96,u8)` returns `1`.

### [UID:00027O] `MapObjectDirectionMasks`

```cpp
static const unsigned char s_mapObjectDirectionMaskA[8] = {
    0x02, 0x08, 0x01, 0x04, 0x04, 0x00, 0x00, 0x00
};

static const unsigned char s_mapObjectDirectionMaskB[8] = {
    0x01, 0x04, 0x02, 0x08, 0x08, 0x00, 0x00, 0x00
};
```

Current MCP proof: `get_bytes(0x0066dd50,16)` returns exactly those bytes; `xrefs_to` returns two refs to `0x0066dd50` and two refs to `0x0066dd58`.

### [UID:00027Q] `MapPaneDayNightFloatTable`

```cpp
static const float s_dayNightBrightnessByHour[24] = {
    0.35f, 0.35f, 0.35f, 0.40f,
    0.45f, 0.55f, 0.65f, 0.85f,
    0.90f, 0.95f, 1.00f, 1.00f,
    1.00f, 1.00f, 1.00f, 0.95f,
    0.90f, 0.85f, 0.65f, 0.55f,
    0.45f, 0.40f, 0.35f, 0.35f
};
```

Current MCP proof: `get_bytes(0x0066dd78,96)` returns the documented 24 IEEE-754 values; `xrefs_to(0x0066dd78)` returns the four documented refs in dispatcher, raw duplicate, compute helper, and modeled map-state/effect handler contexts.

### [UID:0002AZ] `MapPaneRenderScratchFlag`

```cpp
static unsigned char s_mapPaneCachedShadowOption = 0;
```

Current MCP proof: `get_int(0x0069b4f8,u8)` returns `0`; `get_bytes(0x0069b4f4,16)` is zero-filled; `xrefs_to(0x0069b4f8)` returns the compare/store pair in `sub_5094B0`. The current item summary says initialized to `0xff`; that is stale and should be superseded with the zero initializer.

### [UID:0002SQ] vtable no-code block

```cpp
// MapPane vtable bytes are compiler-generated from [UID:00007Q] and its exact virtual method children; do not emit a hand-authored table here.
```

### [UID:00042K] layout support no-code block

```cpp
// Layout support only. The MapPane class declaration is owned by [UID:00007Q]; no standalone MapPaneLayout C++ is emitted here.
```

### [UID:0001AX] raw day/night duplicate no-code block

```cpp
// No standalone body: this retained raw duplicate is covered by the live MapPane::HandlePacket opcode 0x20 route in [UID:00037T].
```

### [UID:0001AZ] raw friend-sync duplicate no-code block

```cpp
// No standalone body: this retained raw duplicate is covered by the live MapPane::HandlePacket opcode 0x6a route in [UID:00037T].
```

### [UID:0001AW] aggregate no-code policy

Preferred metadata action:

```text
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Required prose: this range is a split/container over exact packet-handler children and retained raw duplicate evidence. It must not emit one aggregate C++ body. If the validator requires a formal block while metadata remains reconstructable, use:

```cpp
// Split/container range. Exact MapPane packet-handler code is owned by child pages under [UID:0001AW]; do not emit an aggregate body here.
```

## Exact Split Plan For [UID:00037Q]

Do not insert one C++ block into [UID:00037Q]. Current MCP proves it is a nine-function family plus padding:

| Proposed child range | MCP function | Size | Current source-facing role |
| --- | --- | ---: | --- |
| `0x00506970-0x0050697f` | `sub_506970` | `0x0f` | `MapPane::FindObjectPaneById(int objectId)` / object-list lookup wrapper |
| `0x00506980-0x00506ad4` | `sub_506980` | `0x154` | object coordinate/update helper using tile dimensions and movement interpolation |
| `0x00506ae0-0x00506b2a` | `sub_506AE0` | `0x4a` | previous selectable-object wrapper |
| `0x00506b30-0x00506b7a` | `sub_506B30` | `0x4a` | next selectable-object wrapper |
| `0x00506b80-0x00506bca` | `sub_506B80` | `0x4a` | item-target previous/alternate wrapper |
| `0x00506bd0-0x00506c1a` | `sub_506BD0` | `0x4a` | item-target next/alternate wrapper |
| `0x00506c20-0x00506c6d` | `sub_506C20` | `0x4d` | living-target/SpellWho previous wrapper with filter argument |
| `0x00506c70-0x00506cbd` | `sub_506C70` | `0x4d` | living-target/SpellWho next wrapper with filter argument |
| `0x00506cc0-0x00506cdd` | `sub_506CC0` | `0x1d` | terminal lookup/status helper before hit-test child |

Padding/tails:

- `0x0050697f-0x00506980`
- `0x00506ad4-0x00506ae0`
- `0x00506b2a-0x00506b30`
- `0x00506b7a-0x00506b80`
- `0x00506bca-0x00506bd0`
- `0x00506c1a-0x00506c20`
- `0x00506c6d-0x00506c70`
- `0x00506cbd-0x00506cc0`
- `0x00506cdd-0x00506ce0`

Implementation rule: create exact child pages first, then convert [UID:00037Q] to non-emitting split/container. Do not use ObjectList as owner for these wrappers; ObjectList owns key production/movement/resolution callees, while MapPane owns the wrapper surface.

## Source Bodies Not In The Immediate Batch

### [UID:0002QJ] and [UID:0002QK]

Current MCP confirms exact functions and behavior:

- [UID:0002QJ] `0x00504b90-0x00504df1`, size `609`, two callers, Documents path, `%s\NexusTK`, `%s\NexusTK\Maps`, `%s\TK%06d.cmp`, `CMAP`, width/height validation, tile reset, AUTOBUF, zlib uncompress.
- [UID:0002QK] `0x00504e00-0x00505075`, size `629`, four callers, same path/signature, width/height writes, zlib compress, tile-buffer free/clear, monster image cache refresh.

Bounded blocker: not lack of behavior. The blocker is final source syntax around `StdioFile`, AUTOBUF inline construction, wide API dispatch entries, tile-buffer reset helper, and final `MapPane` field names. Do not emit decompiler-shaped C++ into these methods in the first callback.

### [UID:00037T]

Current MCP confirms dispatcher `0x00507c90` is a function of size `0x1176`, `0x00508e06` is not a function, and `0x00508f60` is the next helper. The tail `0x00508e06-0x00508f60` remains switch/table data.

Bounded blocker: a whole-dispatcher C++ block would be too broad and would lock in provisional packet payload names. The correct implementation path is packet-structure naming plus either a dispatcher-case split or a full dispatcher report. Do not mark it non-reconstructable; it is a live source method.

### [UID:0003TF]

Current MCP confirms:

- `sub_50EA30`, size `346`, callers from object-id and coordinate effect descriptor dispatchers.
- Constructor route through pool allocation and `sub_5387B0`.
- `EffectInfo` is by value because the helper receives 52 bytes on the stack and returns with `ret 0x4c`.
- `timerAction == -1` suppresses creation; `timerAction == -2` suppresses event-id-2 scheduling; positive actions are converted to milliseconds.

Immediate callback should add the missing Item Summary and preserve the stable signature:

```cpp
void MapPane::CreateEffectObjectPane(
    ObjectPane *target,
    int mapX,
    int mapY,
    EffectInfo effectInfo,
    int timerAction,
    int sequenceIndex,
    bool compactFlag);
```

Do not insert the full helper body until `EffectInfo` member names are synchronized. This is a bounded name dependency; the source owner and ABI are already resolved.

### [UID:0003TL]

Immediate callback should add the missing Item Summary. Current evidence proves range, owner, route, palette dependency, two static-object refresh calls, and padding. Formal body should wait for packet payload structures, map-name buffers, palette/resource fields, tile descriptor names, and dirty-region helper names.

### [UID:00027N]

Current MCP reconfirms the start of the data island: `0x0066db48` contains the `CMAP` pointer, `0x0066db4c-0x0066db50` is four zero bytes, and `0x0066db50` begins the CRC/CCITT-style table with `00 00 21 10 42 20 63 30`. `xrefs_to(0x0066db50)` returns the eight documented refs.

Do not include this table in the first callback unless the callback explicitly accepts a 256-entry literal transcription. The implementation-ready path is either:

- a dedicated data-literal callback that reads all `0x200` table bytes and emits `static const unsigned short s_mapPaneChecksumTable[256] = {...};`, or
- a helper/algorithm callback that proves the exact polynomial/init contract and emits generated-source logic.

### [UID:0001SO]

Keep this page as a working dispatcher index. Do not promote the observed values into a formal enum in this batch. If the supervisor wants marker removal without source promotion, use a formal no-code comment:

```cpp
// Working MapPane packet opcode index only; final enum C++ is withheld until payload structures and route names are stable.
```

## Negative Evidence And Owner Exclusions

- [UID:00037Q] is not ObjectList-owned. The wrappers call ObjectList helpers, but MapPane owns the receiver state and wrapper surface.
- [UID:0003TF] is not EffectObjectPane-owned. EffectObjectPane owns the constructed class and `StartIdleTimer`; MapPane owns the packet/effect creation decision.
- [UID:0003TL] is not PaletteLib, StaticObjectPane, or ObjectList-owned. Those are callees/dependencies after MapPane packet parsing mutates MapPane strings and tile descriptors.
- [UID:0002AZ] is not MessageShowPane or MemoryMan-owned. Current MCP and docs bound it between those neighbors and show only MapPane render compare/store refs.
- [UID:0002SQ] is not a source table declaration. It is compiler-generated from MapPane class/virtual method declarations.
- [UID:0001AX] and [UID:0001AZ] are not independently routed source bodies. Existing no-route PE scans plus dispatcher equivalence prove they are retained raw duplicate evidence.
- No support-body edits are required for ItemObjImageLib, GrafPort, RectBounds, EPFTileContext, PaletteLib, ObjectList, StaticObjectPane, EffectObjectPane, or TimerMgr during the immediate callback unless a directly contradictory cross-reference is discovered.

## Score And Metadata Rationale

Suggested immediate score changes:

| UID | Suggested score | Rationale |
| --- | --- | --- |
| 0001AQ | `88/91` | Current MCP proves exact one-block helper, ABI, seven callers, no callees, and direct tile-dimension reads; first-draft C++ is exact. |
| 0000T7 | `91/92` | Current MCP proves two signed two-byte 48-valued globals and `movsx` consumers; formal declarations are ready. |
| 0000PR | `90/88` | Storage/lifecycle role is strong; final source spelling remains descriptive. |
| 0002ZJ | `90/94` | Exact pointer, target literal, and two load/save xrefs are current; formal pointer declaration is ready. |
| 00027O | `87/91` | Exact 16 bytes and four xrefs are current; descriptive table names remain non-final. |
| 00027Q | `87/91` | Exact 96 bytes and four refs are current; descriptive table name remains non-final. |
| 0002AZ | `87/90` | Current zero initializer and two MapPane render refs are current; stale `0xff` wording should be corrected. |
| 0002SQ | `89/93` | Current vtable bytes confirm generated-binary status; stale unassigned wording should be superseded. |
| 0001AW | `86/90` if kept as split-container, or `85/88` unchanged if metadata policy avoids score change | Existing exact child inventory and raw duplicate proofs make non-emitting split-container policy stronger than an aggregate body. |

Suggested no score change:

- [UID:0002QJ], [UID:0002QK], [UID:00037T], [UID:0003TF], [UID:0003TL], [UID:00027N], [UID:0001SO], and [UID:00007Q] unless the implementation callback adds substantial new text beyond current evidence.

## Implementation Callback Result

`FINISHED_IMPLEMENTATION` for the accepted narrowed first batch only. No full-family closeout was applied, no [UID:00037Q] split child pages were created, and no generated files, generated reports, manual coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, or lock files were hand-edited. The only generated/tracker changes observed were validator-owned refresh side effects.

Short leases were requested immediately before by-* edits with:

> Executable block R001 was removed from this report and preserved verbatim in [0000L3-MapPane-empty-emitter-family-source-quality-removed.md](0000L3-MapPane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The lease command returned `Success` for every requested path. The release command after the validator batch returned `Rejected[No active lease]` for every requested path because the short leases had already expired or been purged. At post-release inspection, the shared current lease list contained only unrelated active B002/B005 Spell/TargetSelection leases, and no active B004 or MapPane lease remained.

[UID:0002AZ] had a goal-path mismatch: the callback listed stale path `by-memory/0x0069b4f4-0x0069b504.MapPaneRenderScratchFlag.md`, but the live UID page is `by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md`; the live UID page was edited and validated. [UID:0001AW] metadata conversion to a non-emitting split/container was accepted by validator command `000000001414`; the alternate aggregate no-code fallback was not needed.

Generated freshness was inspected only through validator-owned metadata. `auto-generated/NexusTK/map/MapPane.cpp` now carries header `validator-command-id: 000000001392`, `validator-refreshed-at: 2026-06-29T22:51:19-04:00`, `validator-refresh-source: deferred-generated-refresh`, source UID `0000L3`, and source by-file doc `by-file/MapPane.md`. The tracker row now records `73` total, `62` filled, `11` empty, `84.9%` for `auto-generated/NexusTK/map/MapPane.cpp`; the by-file support note preserves the accepted report's earlier discrepancy observation of 27 visible empty comments versus the tracker value 29.

## Implementation Tracking Checklist

- [x] [UID:0001AQ] Inserted exact first-draft `ScaleDirectionOffsetToPixels` C++ block and updated score/rationale. Proof: `by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md`; validator `000000001397`, timestamp `2026-06-29T22:52:06-04:00`, exit `0`, ok `1`.
- [x] [UID:0000VC] Added covered-by comment pointing to [UID:0001AQ]. Proof: `by-item/ScaleDirectionOffsetToPixels_00505100.md`; validator `000000001398`, timestamp `2026-06-29T22:52:12-04:00`, exit `0`, ok `1`.
- [x] [UID:0000T7] Inserted signed-short width/height declarations. Proof: `by-global/MapTilePixelDimensions.md`; validator `000000001399`, timestamp `2026-06-29T22:52:22-04:00`, exit `0`, ok `1`.
- [x] [UID:0001OJ] Added covered-by comment pointing to [UID:0000T7]. Proof: `by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md`; validator `000000001400`, timestamp `2026-06-29T22:52:23-04:00`, exit `0`, ok `1`.
- [x] [UID:0001OK] Added covered-by comment pointing to [UID:0000T7]. Proof: `by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md`; validator `000000001401`, timestamp `2026-06-29T22:52:30-04:00`, exit `0`, ok `1`.
- [x] [UID:0000PR] Inserted `static MapPane *g_activeMapPane = NULL;`. Proof: `by-global/g_activeMapPane.md`; validator `000000001402`, timestamp `2026-06-29T22:52:32-04:00`, exit `0`, ok `1`.
- [x] [UID:0001OW] Added covered-by comment pointing to [UID:0000PR]. Proof: `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`; validator `000000001403`, timestamp `2026-06-29T22:52:34-04:00`, exit `0`, ok `1`.
- [x] [UID:0002ZJ] Inserted `static const char *g_mapPaneCmapSignature = "CMAP";`. Proof: `by-global/MapPaneCmapSignaturePointer.md`; validator `000000001404`, timestamp `2026-06-29T22:52:43-04:00`, exit `0`, ok `1`.
- [x] [UID:0002ZN] Added covered-by comment pointing to [UID:0002ZJ]. Proof: `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`; validator `000000001405`, timestamp `2026-06-29T22:52:44-04:00`, exit `0`, ok `1`.
- [x] [UID:00027F] Added covered-by comment pointing to [UID:0002CF]. Proof: `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`; validator `000000001406`, timestamp `2026-06-29T22:52:54-04:00`, exit `0`, ok `1`.
- [x] [UID:00027O] Inserted two static mask arrays. Proof: `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md`; validator `000000001407`, timestamp `2026-06-29T22:52:55-04:00`, exit `0`, ok `1`.
- [x] [UID:00027Q] Inserted 24-entry static float table. Proof: `by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md`; validator `000000001408`, timestamp `2026-06-29T22:52:57-04:00`, exit `0`, ok `1`.
- [x] [UID:0002AZ] Inserted cached Shadow option declaration and superseded stale `0xff` wording with current zero initializer. Proof: live path `by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md`; stale callback path was not present; validator `000000001409`, timestamp `2026-06-29T22:53:07-04:00`, exit `0`, ok `1`.
- [x] [UID:0002SQ] Added vtable no-code comment and superseded stale "left unassigned" item-summary wording. Proof: `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md`; validator `000000001410`, timestamp `2026-06-29T22:53:17-04:00`, exit `0`, ok `1`.
- [x] [UID:00042K] Added layout-support no-code comment and preserved support-only class declaration policy. Proof: `by-type/by-struct/MapPaneLayout.md`; validator `000000001411`, timestamp `2026-06-29T22:53:26-04:00`, exit `0`, ok `1`.
- [x] [UID:0001AX] Added raw-duplicate no-code comment for dispatcher opcode `0x20`. Proof: `by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md`; validator `000000001412`, timestamp `2026-06-29T22:53:28-04:00`, exit `0`, ok `1`.
- [x] [UID:0001AZ] Added raw-duplicate no-code comment for dispatcher opcode `0x6a`. Proof: `by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md`; validator `000000001413`, timestamp `2026-06-29T22:53:30-04:00`, exit `0`, ok `1`.
- [x] [UID:0001AW] Converted aggregate to non-emitting split/container. Proof: `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`; validator `000000001414`, timestamp `2026-06-29T22:53:32-04:00`, exit `0`, ok `1`; metadata conversion accepted, so the formal aggregate no-code fallback was excluded as not needed.
- [x] [UID:0003TF] Added missing Item Summary and preserved support-only body deferral until `EffectInfo` field names are accepted. Proof: `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md`; validator `000000001415`, timestamp `2026-06-29T22:53:34-04:00`, exit `0`, ok `1`.
- [x] [UID:0003TL] Added missing Item Summary and current PaletteLib dependency wording; body remains deferred until packet/tile field names are accepted. Proof: `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`; validator `000000001416`, timestamp `2026-06-29T22:53:44-04:00`, exit `0`, ok `1`.
- [x] [UID:0000L3] Updated by-file note with resolved first-draft rows, covered-storage rows, non-emitting split containers, follow-up rows, exact [UID:00037Q] split plan, and generated-state discrepancy. Proof: `by-file/MapPane.md`; validator `000000001417`, timestamp `2026-06-29T22:53:51-04:00`, exit `0`, ok `1`.
- [x] Ran scoped validators for every changed by-* doc from `E:\NTK\GhidraBridge\source-3\project-documentation`. Proof: commands `000000001397` through `000000001417`, each exit `0`, ok `1`; non-fatal `missing_ref_uid` counts were validator warnings on already reference-heavy pages, not failures.
- [x] Inspected generated `auto-generated/NexusTK/map/MapPane.cpp` freshness through validator-owned metadata only; no generated output was hand-edited. Proof: header command `000000001392`, refreshed `2026-06-29T22:51:19-04:00`, deferred-generated-refresh; tracker row `73/62/11/84.9%`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Target incorporation | State |
| --- | --- | --- | --- | --- |
| C001 | MCP was available and current; no fallback-only evidence was used. | `server_health` JSON-RPC `101`; `idb_list` JSON-RPC `112`; successful read-only calls through `253`. | Report evidence retained; callback incorporated only MCP-backed claims from accepted report. | incorporated; no MCP fallback used during implementation |
| C002 | Generated `MapPane.cpp` had an accepted discrepancy: 27 visible empty markers while tracker reported 29. | Original report count and tracker/header read; post-callback generated header and tracker read. | [UID:0000L3] support note records the accepted discrepancy and later generated-refresh state. | incorporated; post-callback header `000000001392`, tracker `73/62/11/84.9%` |
| C003 | [UID:0001AQ] is safe first-draft C++. | MCP `221/222`: one-block `__stdcall`, no callees, seven callers, exact multiplies. | [UID:0001AQ] formal C++; [UID:0000VC] covered-by comment. | incorporated; validators `000000001397` and `000000001398` ok |
| C004 | Tile dimension globals are signed 16-bit static data initialized to 48. | MCP `241/242`, `analyze_function` `movsx` reads. | [UID:0000T7] formal C++; [UID:0001OJ]/[UID:0001OK] covered-by comments. | incorporated; validators `000000001399` through `000000001401` ok |
| C005 | `g_activeMapPane` is a zero-initialized process pointer with broad active-map xrefs. | MCP `244-246`; existing lifecycle docs. | [UID:0000PR] formal C++; [UID:0001OW] covered-by comment. | incorporated; validators `000000001402` and `000000001403` ok |
| C006 | `CMAP` pointer is exact MapPane load/save data. | MCP `241-243`; [UID:0002QJ]/[UID:0002QK] xrefs. | [UID:0002ZJ] formal C++; [UID:0002ZN] covered-by comment. | incorporated; validators `000000001404` and `000000001405` ok |
| C007 | Movement-scale storage child should not duplicate [UID:0002CF]. | [UID:0002CF] already emits formal declaration; MCP `242` confirms value `1`. | [UID:00027F] covered-by comment. | incorporated; validator `000000001406` ok |
| C008 | Direction masks are ready as two static byte arrays. | MCP `241` exact 16 bytes; MCP `243` four refs. | [UID:00027O] formal C++. | incorporated; validator `000000001407` ok |
| C009 | Day/night brightness table is ready as a 24-entry static float table. | MCP `241` exact 96 bytes; MCP `243` four refs; [UID:0001AX]/[UID:0001SO] roles. | [UID:00027Q] formal C++. | incorporated; validator `000000001408` ok |
| C010 | Render scratch flag initializer is zero, not `0xff`. | MCP `241/242/243`; current [UID:0002AZ] body already supersedes old wording. | [UID:0002AZ] formal C++ and summary correction. | incorporated on live UID path `0x0069b4f8-0x0069b4f9`; stale callback path excluded with reason; validator `000000001409` ok |
| C011 | MapPane vtable bytes should not be hand-authored. | MCP `247`; [UID:0002SQ] constructor/cleanup/vtable slot docs. | [UID:0002SQ] no-code comment and stale-summary correction. | incorporated; validator `000000001410` ok |
| C012 | Raw day/night and friend-sync duplicate bodies should stay non-emitting. | Existing B003/B004 no-route PE scans; [UID:0001AX]/[UID:0001AZ] docs; dispatcher routes in [UID:00037T]. | [UID:0001AX]/[UID:0001AZ] formal no-code comments. | incorporated; validators `000000001412` and `000000001413` ok |
| C013 | [UID:0001AW] is a split/container, not a single source body. | Exact child inventory in [UID:0001AW]; raw duplicate no-code proofs; prior split-container precedent [UID:00037U]. | Convert [UID:0001AW] to non-emitting split/container or add aggregate no-code comment if validator rejects conversion. | incorporated by conversion; validator `000000001414` accepted; fallback excluded-not-needed |
| C014 | [UID:00037Q] must split before aggregate retirement. | MCP `251-253` exact starts/sizes and helper roles. | Exact split plan recorded in [UID:0000L3]; no child pages created in this callback by supervisor instruction. | follow-up inventory preserved; by-file validator `000000001417` ok |
| C015 | Cache load/save methods are exact but not first-batch C++. | MCP `224/225` exact behavior and helper dependencies. | [UID:0000L3] follow-up/support note only; no [UID:0002QJ]/[UID:0002QK] body edits in narrowed callback. | follow-up inventory preserved |
| C016 | Dispatcher [UID:00037T] remains source-bearing and should not be no-coded. | MCP `251`: `0x00507c90` function, `0x00508e06` not function, `0x00508f60` next helper. | [UID:0000L3] note preserves dispatcher/body deferral; [UID:0001AW] aggregate retired as split/container. | follow-up inventory preserved |
| C017 | [UID:0003TF] signature is stable but full body waits on `EffectInfo` names. | MCP `223`; existing [UID:0003TF] signature/ABI docs. | Added Item Summary and support-only detail; no full body. | incorporated; validator `000000001415` ok |
| C018 | [UID:0003TL] source owner/range/route are exact but body waits on packet/tile field names. | Existing docs plus PaletteLib support update; MCP evidence from caller route via docs. | Added Item Summary and dependency detail; no full body. | incorporated; validator `000000001416` ok |
| C019 | [UID:00027N] should not be transcribed in the first callback. | MCP `241/243` confirms start/refs but not full 256-entry literal in this report. | [UID:0000L3] follow-up inventory only; no by-memory table transcription in narrowed callback. | follow-up inventory preserved |
| C020 | [UID:0001SO] remains a working opcode index, not final enum code. | Existing packet enum docs; [UID:00037T] dispatcher state. | [UID:0000L3] follow-up inventory only; no enum declaration/no-code marker applied in narrowed callback. | optional callback preserved |

## Validator Batch

All scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with:

> Executable block R002 was removed from this report and preserved verbatim in [0000L3-MapPane-empty-emitter-family-source-quality-removed.md](0000L3-MapPane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| File | command_id | command_timestamp | exit | ok | Generated refresh state |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md` | `000000001397` | `2026-06-29T22:52:06-04:00` | `0` | `1` | deferred |
| `by-item/ScaleDirectionOffsetToPixels_00505100.md` | `000000001398` | `2026-06-29T22:52:12-04:00` | `0` | `1` | deferred |
| `by-global/MapTilePixelDimensions.md` | `000000001399` | `2026-06-29T22:52:22-04:00` | `0` | `1` | deferred |
| `by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md` | `000000001400` | `2026-06-29T22:52:23-04:00` | `0` | `1` | deferred |
| `by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md` | `000000001401` | `2026-06-29T22:52:30-04:00` | `0` | `1` | deferred |
| `by-global/g_activeMapPane.md` | `000000001402` | `2026-06-29T22:52:32-04:00` | `0` | `1` | deferred |
| `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md` | `000000001403` | `2026-06-29T22:52:34-04:00` | `0` | `1` | deferred |
| `by-global/MapPaneCmapSignaturePointer.md` | `000000001404` | `2026-06-29T22:52:43-04:00` | `0` | `1` | deferred |
| `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md` | `000000001405` | `2026-06-29T22:52:44-04:00` | `0` | `1` | deferred |
| `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` | `000000001406` | `2026-06-29T22:52:54-04:00` | `0` | `1` | deferred |
| `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md` | `000000001407` | `2026-06-29T22:52:55-04:00` | `0` | `1` | deferred |
| `by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md` | `000000001408` | `2026-06-29T22:52:57-04:00` | `0` | `1` | deferred |
| `by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md` | `000000001409` | `2026-06-29T22:53:07-04:00` | `0` | `1` | deferred |
| `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md` | `000000001410` | `2026-06-29T22:53:17-04:00` | `0` | `1` | deferred |
| `by-type/by-struct/MapPaneLayout.md` | `000000001411` | `2026-06-29T22:53:26-04:00` | `0` | `1` | deferred |
| `by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md` | `000000001412` | `2026-06-29T22:53:28-04:00` | `0` | `1` | deferred |
| `by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md` | `000000001413` | `2026-06-29T22:53:30-04:00` | `0` | `1` | deferred |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `000000001414` | `2026-06-29T22:53:32-04:00` | `0` | `1` | deferred; non-emitting conversion accepted |
| `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md` | `000000001415` | `2026-06-29T22:53:34-04:00` | `0` | `1` | deferred |
| `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md` | `000000001416` | `2026-06-29T22:53:44-04:00` | `0` | `1` | deferred |
| `by-file/MapPane.md` | `000000001417` | `2026-06-29T22:53:51-04:00` | `0` | `1` | deferred |

No accepted callback item remains unapplied. Follow-up inventory rows remain intentionally unimplemented by supervisor instruction.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0000L3-MapPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000L3-MapPane-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T23:04:48","uid":"0000L3"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000L3-MapPane-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0000L3-MapPane-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000L3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
