** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch5

Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation5-0001AW-20260616`  
Agent: B001  
Target: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)

## Final Recommendation

Create the next bounded executable child batch now:

- [UID:0003TI] `0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md`, `86/90`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- [UID:0003TJ] `0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`, `86/90`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- Add ignored padding rows for `0x0050f029-0x0050f030` and `0x0050f26d-0x0050f270`.
- Keep [UID:0001AW] `COMPLETION:85`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`, and blank final C++.

Do not create children in this batch for `0x0050ec30`, `0x0050ef00`, or `0x0050f270`. Current live IDA and raw PE evidence still shows no direct callers, no xrefs-to, and no absolute VA/RVA/relative branch hits to those starts. They remain roadmap-only retained helper/source-placement questions.

Do not move into the broad `0x005104c7-0x00513800` leaf in this batch. The required first-audit candidate, the directly called `0x0050f030` / `0x0050f130` StaticObjectPane tile chain, produced two defensible `85/85+` children. The broad leaf remains the next major follow-up after this bounded batch is applied.

No by-* documentation, generated report, IDA DB, or `by-memory/-coverage-report.md` file was directly edited by B001. This report is the only file created.

## Current State Checked

- Parent [UID:0001AW] currently remains `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, with blank final C++.
- Supervisor notes record executed MapPanePacketHandlers children [UID:0003TB]-[UID:0003TH], with [UID:0003TH] ending at `0x0050eef5` and ignored padding `0x0050eef5-0x0050ef00`.
- `auto-generated/by-memory-tool-report.md` was regenerated at `2026-06-16 05:22:16`; Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan all report `None`.
- The largest-range report still lists [UID:0001AW] leaf `0x005104c7-0x00513800` as rank 18, `13113` bytes, reconstructable.
- UID allocation assumption: supervisor notes show latest allocated MapPane child is [UID:0003TH]. If no intervening UID allocation occurred, use [UID:0003TI] and [UID:0003TJ] for this batch. If the supervisor's validator assigns different UIDs, replace every [UID:0003TI]/[UID:0003TJ] reference in the proposed text consistently.

## Evidence Checked

### Live IDA MCP

Session: `b001_mappane_0001AW_20260616`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, auto-analysis not running.

Function inventory for the batch5 candidate chain:

| Start | IDA name | Size | Result |
|---|---|---:|---|
| `0x0050ef00` | `sub_50EF00` | `0x129` | Roadmap-only retained DamageNumberObjectPane-shaped helper; no direct callers/xrefs. |
| `0x0050f030` | `sub_50F030` | `0x100` | StaticObjectPane creation/insertion helper; direct caller `sub_50F130` at `0x0050f1f8`. |
| `0x0050f130` | `sub_50F130` | `0x13d` | Static-object tile-region reconciliation loop; callers `sub_5059D0`, `sub_50BCE0`, and `sub_510960`. |
| `0x0050f270` | `sub_50F270` | `0x142` | WorldMapPane/child-pane factory-shaped successor; no direct callers/xrefs. |

`analyze_component(0x0050f030, 0x0050f130, 0x0050f270)` reports one internal edge, `0x0050f130 -> 0x0050f030`. It marks `0x0050f130` as the interface function for this local component; `0x0050f030` and `0x0050f270` are internal-only by IDA reachability, with `0x0050f270` having no direct edge from this pair.

Important IDA facts for `0x0050f030`:

- Prototype: `void *__thiscall(_DWORD **this, int, int, __int16, char)`.
- Callers: `sub_50F130`.
- Xrefs-to: one code xref at `0x0050f1f8`.
- Callees: `sub_537900`, `sub_5314A0`, `PoolAllocator_Allocate`, `sub_4B7EB0`, `sub_506980`, `sub_50A940`, `sub_4DD850`, `sub_4DDA30`, and `@__security_check_cookie@4`.
- Decompilation calls `sub_4DD850(staticId, rect)`, normalizes the rect with `sub_4B7EB0`, allocates from the StaticObjectPane pool, constructs through `sub_537900(tileX, tileY, staticId)`, queries static-object metadata through `sub_4DDA30`, applies MapPane placement through `sub_50A940` using tile dimension globals, refreshes via `sub_506980`, and inserts the new object into MapPane object/list state through `sub_5314A0` when the suppress-insert flag is clear.

Important IDA facts for `0x0050f130`:

- Prototype: `int *__userpurge@<eax>(_DWORD **@<ecx>, int@<edi>, int *)`.
- Callers: `sub_5059D0`, `sub_50BCE0`, and `sub_510960`.
- Xrefs-to: code xrefs at `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`.
- Callees: `sub_532EB0`, `sub_531C10`, `sub_50F030`, `sub_4B97D0`, `sub_50C120`, and `@__security_check_cookie@4`.
- Decompilation iterates the input rectangular tile bounds, calls `sub_50C120` for the tile descriptor, reads the static-object id word from the descriptor, finds any current object through `sub_532EB0`, keeps a matching existing StaticObjectPane by comparing its stored id at offset `+0x128`, invalidates/removes/destroys stale entries through virtual bounds, MapPane invalidation, `sub_531C10`, optional `sub_4B97D0`, and the object's virtual destructor, and calls `sub_50F030` to create a replacement when a tile has a nonzero static-object id and no matching existing object.

Caller context:

- `analyze_function(0x005059d0)` reports this existing [UID:0002QM][MapPaneRecenterAndSendPosition](../../../../../by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) path calls `sub_50F130`; the page already documents a post-send object reconciliation call at `0x0050f130`.
- `analyze_function(0x0050bce0)` reports this existing [UID:00037Y][MapPaneTileObjectGridRenderCore](../../../../../by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) path calls `sub_50F130`; that page is a MapPane tile/object-grid child and supports the same tile-region role.
- `analyze_function(0x00510960)` reports this larger MapPane map-info/object-removal packet helper calls `sub_50F130` at two sites; [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md) currently tracks opcode `0x06` as the map info/update route to `0x00510960`, but payload and helper names remain working labels.

Padding and successor boundary facts:

- `make_signature_for_range(0x0050f029, 0x0050f030, wildcard_operands=false)` returns `CC CC CC CC CC CC CC`.
- `make_signature_for_range(0x0050f26d, 0x0050f270, wildcard_operands=false)` returns `CC CC CC`.
- `analyze_function(0x0050f270)` reports size `0x142`, no callers, no xrefs-to, and callees including `sub_5C2AC0`; this looks like a WorldMapPane/child-pane creation helper but has no direct route to create now.
- `make_signature_for_range(0x0050faf4, 0x0050fb00, wildcard_operands=false)` returns twelve `CC` bytes before the later modeled `sub_50FB00`. This confirms later alignment but is outside the current child batch.

### Raw PE Scan

Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` searched absolute VA dwords, RVA dwords, and executable `E8`/`E9` rel32 branch/call encodings:

| Target | Absolute VA hits | RVA hits | Relative call/jump hits |
|---|---:|---:|---|
| `0x0050ec30` | 0 | 0 | 0 |
| `0x0050ef00` | 0 | 0 | 0 |
| `0x0050f030` | 0 | 0 | 1: call at `0x0050f1f8` |
| `0x0050f130` | 0 | 0 | 4: calls at `0x00505be0`, `0x0050bff9`, `0x00510e28`, `0x00511318` |
| `0x0050f270` | 0 | 0 | 0 |
| `0x0050f4d0` | 0 | 0 | 3: calls at `0x005074ca`, `0x0050750d`, `0x00554ee3` |
| `0x005104d0` | 0 | 0 | 1: call at `0x00507f10` |
| `0x00510960` | 0 | 0 | 1: call at `0x00507ffa` |

The raw scan agrees with IDA: the StaticObjectPane tile chain is live and bounded, while `0x0050ef00` and `0x0050f270` remain no-direct-route starts.

### Documentation Evidence

Checked support pages:

- [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) and [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) already identify MapPane as the owner for packet/object/tile routing, with [UID:0001AW] and prior children [UID:0003TB]-[UID:0003TH] listed.
- [UID:0002QM][MapPaneRecenterAndSendPosition](../../../../../by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) documents the post-send object reconciliation call to `0x0050f130`.
- [UID:00037Y][MapPaneTileObjectGridRenderCore](../../../../../by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) is a direct MapPane tile/object-grid child and provides a neighboring source-family precedent for routing `0x0050f130`.
- [UID:0000E1][StaticObjectPane](../../../../../by-class/StaticObjectPane.md) already records construction from the map object creation path at `0x0050f030`. It keeps StaticObjectPane ownership for the constructed object class, not MapPane's tile-region routing helper.
- [UID:0000O6][StaticObjectPane](../../../../../by-file/StaticObjectPane.md) keeps `StaticObjectPane.cpp` separate from MapPane and from StaticObjImageLib.
- [UID:0002WM][StaticObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) records direct allocation xrefs including `0x0050f030` and assigns the pool to StaticObjectPane.
- [UID:0001PP][g_pStaticObjImageLib](../../../../../by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) records direct reads at `0x0050f064` and `0x0050f0b0` inside this child candidate.
- [UID:0000E2][StaticObjImageLib](../../../../../by-class/StaticObjImageLib.md) and [UID:0000O7][StaticObjImageLib](../../../../../by-file/StaticObjImageLib.md) own the static-object resource/bounds/render provider, not the MapPane tile-region policy.
- [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md) gives the current working route for opcode `0x06` into `0x00510960`, but it also states payload names remain provisional; this blocks final C++ names but not the child split.

## Rejected Alternatives

- Reclassify [UID:0001AW] now: rejected. This batch removes another direct-evidence helper chain, but the parent still contains source-bearing gaps and the large `0x005104c7-0x00513800` leaf. Parent remains reconstructable until exact children cover or reclassify the remaining source.
- Create `0x0050ef00-0x0050f029` now: rejected. IDA says `sub_50EF00` is real DamageNumberObjectPane-shaped construction behavior, but IDA and raw PE scans show no direct callers/xrefs/pointer hits, and the live `0x00512960` combat/status handler constructs DamageNumberObjectPane directly. This can be retained helper evidence, duplicate/dead code, or a source-local helper with no recovered route; current evidence is not safe for a new 85/85+ emitted child.
- Create `0x0050f270-0x0050f3b2` now: rejected. IDA models `sub_50F270` and it calls WorldMapPane construction, but there are no direct callers/xrefs and no raw PE hits to the start. Its owner could be a retained MapPane factory, WorldMapPane creation route, or duplicate helper. Keep it roadmap-only.
- Attach `0x0050f030` to StaticObjectPane: rejected. StaticObjectPane owns constructor `0x00537900`, pool storage, vtables, rendering, and static-object click behavior. The `0x0050f030` body is the MapPane-side helper deciding where, when, and whether to allocate/register a static object for a tile.
- Attach `0x0050f030` or `0x0050f130` to StaticObjImageLib: rejected. StaticObjImageLib provides bounds/resource metadata consumed by the helper; it does not own MapPane object-list registration or tile-region reconciliation.
- Attach `0x0050f130` to ObjectList: rejected. ObjectList is a storage/index dependency called by the helper. The policy loop reads MapPane tile descriptors and decides object invalidation/replacement based on visible tile state.
- Move into `0x005104c7-0x00513800` now: rejected for this batch only. The user asked to move there only if the StaticObjectPane chain could not produce 85/85+ pages. It can.

## Executable Supervisor Batch

### Create Child Page [UID:0003TI]

Create:

`by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md`

With exact content:

```markdown
*** UID:0003TI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050f030-0x0050f130 MapPane Create StaticObjectPane For Tile

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane private static-object tile helper child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneCreateStaticObjectPaneForTile`.
- Confidence: strong for exact range, one direct caller, StaticObjectPane pool/constructor route, StaticObjImageLib metadata/bounds use, MapPane object-list insertion, ownership, and padding; medium-high for final field/helper names.
- Reconstruction note: C++ intentionally blank. Final source names for the tile descriptor, static-object metadata record, placement helper, and object-list insertion helper are still provisional.

## Address Range

- Start: `0x0050f030`
- End: `0x0050f130` end-exclusive
- IDA function: `sub_50F030`
- IDA size: `0x100` bytes
- Preceded by ignored padding `0x0050f029-0x0050f030` after roadmap-only retained helper body `sub_50EF00`.
- Followed by sibling child [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md).

## Behavior

This helper creates and optionally registers a `StaticObjectPane` for one map tile:

- requests static-object bounds through `sub_4DD850(staticId, rect)` and normalizes the rectangle through `sub_4B7EB0`;
- allocates from the [UID:0002WM][StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) pool;
- constructs a `StaticObjectPane` through `sub_537900(tileX, tileY, staticId)`;
- queries static-object metadata through `sub_4DDA30(staticId)`;
- when metadata is present and valid, applies MapPane placement through `sub_50A940` with tile-dimension globals;
- runs the object setup/refresh helper `sub_506980`;
- inserts the new object into MapPane object/list state through `sub_5314A0` when the suppress-insert flag is clear;
- returns the created object pointer.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_50F030` at `0x0050f030`, size `0x100`.
- `analyze_function(0x0050f030)` reports prototype `void *__thiscall(_DWORD **this, int, int, __int16, char)`.
- Callers: `sub_50F130`.
- Xrefs-to: one code xref at `0x0050f1f8`.
- Direct callees: `sub_537900`, `sub_5314A0`, `PoolAllocator_Allocate`, `@__security_check_cookie@4`, `sub_4B7EB0`, `sub_506980`, `sub_50A940`, `sub_4DD850`, and `sub_4DDA30`.
- Decompilation shows the helper calls StaticObjImageLib bounds/metadata providers, allocates from the StaticObjectPane pool, constructs a StaticObjectPane, applies MapPane placement, refreshes object state, and conditionally inserts into MapPane object-list state.
- Raw PE scan of `NexusTK.exe` confirms one `E8` rel32 call to `0x0050f030` at `0x0050f1f8`; no absolute VA or RVA pointer hits were found.
- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) records construction from the map object creation path at `0x0050f030`.
- [UID:0002WM][StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) records direct allocation xrefs including `0x0050f030`.
- [UID:0001PP][g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) records reads at `0x0050f064` and `0x0050f0b0` inside this range.
- B001 byte-signature review confirms preceding bytes `0x0050f029-0x0050f030` are seven `0xcc` padding bytes, not part of this child.

## Ownership Decision

This body belongs to MapPane because it is the MapPane-side creation and registration helper for static map-object tiles. StaticObjectPane owns the constructed object class, pool, constructor, destructor, vtables, and click/render behavior. StaticObjImageLib owns the static-object resource metadata and bounds provider. MapPane owns this tile-driven creation/registration policy.

## Rejected Owners

- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md): constructed object class, not the MapPane tile/object-list placement helper.
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md): metadata/bounds provider only.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): insertion/index dependency only.
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md): correct source for StaticObjectPane methods and pool, but not for this MapPane helper body.

## Score Rationale

Completion is `86` because exact range, caller/xref, raw PE call hit, decompiled behavior, StaticObjectPane pool/constructor route, StaticObjImageLib provider dependencies, MapPane insertion role, ownership decision, rejected owners, and adjacent padding are documented. Confidence is `90` because IDA, raw PE, and support docs triangulate the helper's role; confidence stays below final-source quality because original helper spelling, tile descriptor fields, metadata record fields, and placement helper names remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch5 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) StaticObjectPane/tile helper chain. Parent remains reconstructable because later source-bearing leaves and retained no-caller helper bodies remain unsplit.
```

### Create Child Page [UID:0003TJ]

Create:

`by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`

With exact content:

```markdown
*** UID:0003TJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050f130-0x0050f26d MapPane Refresh StaticObjectPane Tile Region

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane private static-object tile-region reconciliation child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneRefreshStaticObjectTileRegion`.
- Confidence: strong for exact range, direct callers, tile descriptor scan, object-list lookup/removal, StaticObjectPane creation call, ownership, and padding; medium-high for final tile descriptor and field names.
- Reconstruction note: C++ intentionally blank. Final source names for the tile rectangle argument, tile descriptor fields, object-list helpers, and invalidation/update helper names remain provisional.

## Address Range

- Start: `0x0050f130`
- End: `0x0050f26d` end-exclusive
- IDA function: `sub_50F130`
- IDA size: `0x13d` bytes
- Preceded by sibling child [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md).
- Followed by ignored padding `0x0050f26d-0x0050f270` before roadmap-only no-direct-call helper body `sub_50F270`.

## Behavior

This helper reconciles StaticObjectPane entries over a rectangular tile region:

- iterates tile coordinates from the input rectangle;
- fetches each tile descriptor through `sub_50C120`;
- reads the static-object id word from the descriptor;
- finds the current object at the tile through MapPane object-list state via `sub_532EB0`;
- keeps an existing object when its stored static-object id at offset `+0x128` matches the current tile id;
- when an existing object is stale or the tile id is zero, invalidates its bounds, removes it through `sub_531C10`, performs non-static cleanup through `sub_4B97D0` when needed, and calls the object's virtual destructor;
- when the tile id is nonzero and no matching object remains, creates the replacement through [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md).

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_50F130` at `0x0050f130`, size `0x13d`.
- `analyze_function(0x0050f130)` reports prototype `int *__userpurge@<eax>(_DWORD **@<ecx>, int@<edi>, int *)`.
- Callers: `sub_5059D0`, `sub_50BCE0`, and `sub_510960`.
- Xrefs-to: code xrefs at `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`.
- Direct callees: `sub_532EB0`, `sub_531C10`, `sub_50F030`, `@__security_check_cookie@4`, `sub_4B97D0`, and `sub_50C120`.
- Decompilation shows nested rectangular tile iteration, static-object id comparison against the existing object's stored id at offset `+0x128`, object invalidation/removal/destruction for stale entries, and replacement creation through `sub_50F030`.
- Raw PE scan of `NexusTK.exe` confirms four `E8` rel32 calls to `0x0050f130` at `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`; no absolute VA or RVA pointer hits were found.
- [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) documents the post-send object reconciliation call to `0x0050f130`.
- [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) is a MapPane tile/object-grid child and one of the direct caller contexts.
- `analyze_function(0x00510960)` reports two direct calls from the MapPane map-info/object-removal packet helper; [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) tracks this as the current working opcode `0x06` map info/update route.
- B001 byte-signature review confirms the following `0x0050f26d-0x0050f270` bytes are three `0xcc` padding bytes, not part of this child.

## Ownership Decision

This body belongs to MapPane because it reads MapPane tile descriptors, reconciles MapPane object-list entries against tile static-object ids, invalidates MapPane bounds, removes stale entries, and calls the MapPane-owned StaticObjectPane creation helper for replacements. StaticObjectPane owns the constructed static-object pane class, and ObjectList owns storage/index operations; neither owns the MapPane tile-region reconciliation policy.

## Rejected Owners

- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md): constructed object class only.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): lookup/removal dependency only.
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md): not called directly here; provider used by the sibling creation helper.
- [UID:0000L3][MapPane](by-file/MapPane.md) as direct owner: rejected only as too broad for canonical ownership; direct class owner [UID:00007Q][MapPane](by-class/MapPane.md) is the correct narrow owner, with file emission through the class.

## Score Rationale

Completion is `86` because exact range, caller/xref set, raw PE call hits, decompiled tile-region behavior, object-list removal/destruction policy, sibling creation helper call, ownership decision, rejected owners, and trailing padding are documented. Confidence is `90` because caller/callee/decompile/raw evidence agrees with existing MapPane and StaticObjectPane support docs; confidence stays below final-source quality because final tile-descriptor, object-list, rectangle, and helper names are still provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md)
- [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md)
- [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch5 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) StaticObjectPane/tile helper chain. Parent remains reconstructable because later source-bearing leaves and retained no-caller helper bodies remain unsplit.
```

### Parent [UID:0001AW] Edits

Do not change [UID:0001AW] metadata. Keep:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

In the parent exact child table, insert after [UID:0003TH] and before [UID:0001AX]:

```markdown
| [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) | Exact modeled MapPane private helper that allocates/constructs/places/registers a `StaticObjectPane` for one tile from the live static-object tile refresh flow. |
| [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) | Exact modeled MapPane private tile-region reconciliation helper that scans tile descriptors, removes stale static-object panes, and calls [UID:0003TI] for replacements. |
```

In `## Current Exact Boundary Inventory`, replace the existing `0x0050f030` row and add the `0x0050f130`/`0x0050f270` rows so the sequence reads:

```markdown
| `0x0050ef00` | `sub_50EF00` | `0x129` | Roadmap-only retained DamageNumberObjectPane construction helper evidence. Live IDA reports no direct callers/xrefs, raw PE scan found no absolute VA/RVA/relative branch hits to the start, and live combat/status handler `0x00512960` constructs DamageNumberObjectPane directly, so no batch5 child is recommended. |
| `0x0050f030` | `sub_50F030` | `0x100` | Exact child [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md); StaticObjectPane creation/placement helper called by `sub_50F130` at `0x0050f1f8`. |
| `0x0050f130` | `sub_50F130` | `0x13d` | Exact child [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md); tile-region static-object reconciliation helper called from `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`. |
| `0x0050f270` | `sub_50F270` | `0x142` | Roadmap-only WorldMapPane/child-pane factory-shaped successor. Live IDA reports no callers/xrefs and raw PE scan found no absolute VA/RVA/relative branch hits to the start, so no batch5 child is recommended. |
```

Append to the parent evidence/history near the existing batch4 evidence:

```markdown
- 2026-06-16 B001 continuation batch5 live IDA MCP session `b001_mappane_0001AW_20260616`: `analyze_function(0x0050f030)` reports `sub_50F030` size `0x100`, caller `sub_50F130`, xref at `0x0050f1f8`, StaticObjectPane pool allocation, constructor `sub_537900`, StaticObjImageLib bounds/metadata callees `sub_4DD850`/`sub_4DDA30`, MapPane placement helper `sub_50A940`, and ObjectList insertion `sub_5314A0`. `analyze_function(0x0050f130)` reports `sub_50F130` size `0x13d`, callers `sub_5059D0`, `sub_50BCE0`, and `sub_510960`, xrefs at `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`, tile descriptor lookup through `sub_50C120`, existing-object lookup/removal through `sub_532EB0`/`sub_531C10`, stale-object destruction, and replacement creation through `0x0050f030`. A raw PE scan confirms one relative call to `0x0050f030`, four relative calls to `0x0050f130`, and no VA/RVA pointer hits to either start. The same pass checked `0x0050ef00` and `0x0050f270`; both remain no-direct-call/no-xref/no-raw-hit roadmap-only helper bodies. `make_signature_for_range` confirms `0x0050f029-0x0050f030` as seven `0xcc` bytes and `0x0050f26d-0x0050f270` as three `0xcc` bytes.
```

Append to the parent Cross-References list after [UID:0003TH]:

```markdown
- [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
```

Append to the parent Changes section:

```markdown
- 2026-06-16 B001 continuation split batch5: create exact children [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) and [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md), plus ignored padding `0x0050f029-0x0050f030` and `0x0050f26d-0x0050f270`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because retained no-caller helper bodies and the broad `0x005104c7-0x00513800` leaf still need exact split/source-placement work.
```

### Support Doc Edits

No support doc score or metadata changes are recommended.

In [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), insert these Cross-References lines after [UID:0003TH]:

```markdown
- [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
```

In [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), append this Changes entry above the existing batch4 entry:

```markdown
- 2026-06-16 B001 continuation split batch5:
  - Score unchanged at `85/85`.
  - Added exact MapPane static-object/tile children [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) and [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md). The children document MapPane-owned tile-region static-object reconciliation while keeping StaticObjectPane, StaticObjImageLib, and ObjectList as constructed-object/provider/storage owners rather than owners of these MapPane helpers.
```

In [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), insert these Cross-References lines after [UID:0003TH]:

```markdown
- [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
```

In [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), append this Changes entry above the existing batch4 entry:

```markdown
- 2026-06-16 B001 continuation split batch5:
  - Score unchanged at `89/85`.
  - Added exact children [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) and [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) under the MapPane packet/tile/object family. StaticObjectPane, StaticObjImageLib, ObjectList, and PoolAllocator remain constructed-object/provider/storage/allocator owners rather than owners of these MapPane methods.
```

No changes are needed to [UID:0000E1][StaticObjectPane](../../../../../by-class/StaticObjectPane.md), [UID:0000O6][StaticObjectPane](../../../../../by-file/StaticObjectPane.md), [UID:0000E2][StaticObjImageLib](../../../../../by-class/StaticObjImageLib.md), [UID:0000O7][StaticObjImageLib](../../../../../by-file/StaticObjImageLib.md), [UID:0002WM][StaticObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md), or [UID:0001PP][g_pStaticObjImageLib](../../../../../by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md). Those pages already record the relevant construction, pool, and provider evidence, and changing their scores/owners would overstate what this MapPane child split proves.

### by-memory/-ignored.md Entries

Insert after the existing `0x0050eef5-0x0050ef00` entry:

```markdown
- `0x0050f029-0x0050f030` - alignment padding before `MapPaneCreateStaticObjectPaneForTile`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after roadmap-only retained `sub_50EF00` and before the exact StaticObjectPane tile helper.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows seven `0xcc` bytes at `0x0050f029-0x0050f030`; `analyze_function(0x0050ef00)` reports `sub_50EF00` size `0x129`, and `analyze_function(0x0050f030)` reports the next modeled function starts at `0x0050f030`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) and [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md).

- `0x0050f26d-0x0050f270` - alignment padding after `MapPaneRefreshStaticObjectTileRegion`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the exact tile-region child and before no-direct-call successor `sub_50F270`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows three `0xcc` bytes at `0x0050f26d-0x0050f270`; `analyze_function(0x0050f130)` reports `sub_50F130` size `0x13d`, and the next modeled function starts at `0x0050f270`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
```

### by-memory/-coverage-report.md Rows

Do not edit `by-memory/-coverage-report.md` directly as B001. Use this existing row as placement context only; do not duplicate it:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050eef5-0x0050ef00 | padding | MapPaneCreateHitBarObjectPaneEventOverlay to retained DamageNumberObjectPane helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes after `sub_50EDD0` end-exclusive `0x0050eef5` and before modeled function `sub_50EF00` starts at `0x0050ef00`.
```

Insert the following four rows immediately after that existing context row and before the existing [UID:0001AX] row:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f029-0x0050f030 | padding | Retained DamageNumberObjectPane helper to StaticObjectPane tile helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows seven `0xcc` bytes after roadmap-only `sub_50EF00` end-exclusive `0x0050f029` and before modeled function `sub_50F030` starts at `0x0050f030`.
        - [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) 0x0050f030-0x0050f130 | class method/private helper | MapPaneCreateStaticObjectPaneForTile : reconstructable : 86% : strong : Exact modeled `sub_50F030` child split from MapPanePacketHandlers; live IDA and raw PE confirm one direct call from `sub_50F130` at `0x0050f1f8`; helper uses StaticObjImageLib bounds/metadata, allocates/constructs a `StaticObjectPane`, applies MapPane placement, refreshes setup state, and optionally inserts it into MapPane object-list state. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); StaticObjectPane owns the constructed class/pool/constructor. Final C++ blank pending final tile descriptor, metadata, field, and helper names.
        - [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) 0x0050f130-0x0050f26d | class method/private helper | MapPaneRefreshStaticObjectTileRegion : reconstructable : 86% : strong : Exact modeled `sub_50F130` child split from MapPanePacketHandlers; live IDA and raw PE confirm direct calls from `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`; helper scans a rectangular tile region, compares tile static-object ids to existing StaticObjectPane ids, invalidates/removes stale objects, and calls [UID:0003TI] for replacements. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); ObjectList and StaticObjectPane remain dependency/constructed-object owners. Final C++ blank pending final tile descriptor, object-list, and field names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f26d-0x0050f270 | padding | MapPaneRefreshStaticObjectTileRegion to retained WorldMapPane factory-shaped helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows three `0xcc` bytes after `sub_50F130` end-exclusive `0x0050f26d` and before modeled function `sub_50F270` starts at `0x0050f270`.
```

Parent [UID:0001AW] row remains unchanged.

### IDA DB Recommendation

No IDA DB edits are recommended. IDA already has correct modeled boundaries for `sub_50F030`, `sub_50F130`, and `sub_50F270`. Missing direct callers for `0x0050ef00` and `0x0050f270` should not be repaired manually because the raw PE scan found no branch or pointer route to those starts.

### Validation Order

Supervisor validation order after applying the batch:

1. Create [UID:0003TI] and [UID:0003TJ] child pages exactly as above.
2. Apply [UID:0001AW] parent child-table, boundary-inventory, evidence, cross-reference, and Changes additions.
3. Apply MapPane class/file cross-reference and Changes additions.
4. Apply the two `by-memory/-ignored.md` entries.
5. Insert the four coverage rows under [UID:0001AW] after the existing `0x0050eef5-0x0050ef00` padding row and before [UID:0001AX].
6. Run scoped validator passes for both new child pages, [UID:0001AW], [UID:00007Q], [UID:0000L3], `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.
7. Run `python .\tools\memory_ranges.py report` and confirm Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan remain `None`.
8. Confirm [UID:0001AW] still remains `RECONSTRUCTABLE:TRUE`, `85/88`, owner/emitter [UID:00007Q], and blank final C++.

## Remaining Blockers and Next Follow-Up

- `0x0050ec30-0x0050edd0`: investigated in the prior batch and rechecked by raw PE scan target list. IDA reports no callers/xrefs and raw PE scan reports no absolute VA/RVA/relative branch hits. Keep roadmap-only until a pointer/caller/source route is found or it is reclassified as retained duplicate/dead helper evidence.
- `0x0050ef00-0x0050f029`: investigated with IDA `analyze_function`, support docs, and raw PE scan. It is real DamageNumberObjectPane-shaped construction behavior, but no code/pointer route reaches it; live `0x00512960` constructs DamageNumberObjectPane directly. Current evidence cannot safely choose MapPane source helper, retained duplicate, or dead code.
- `0x0050f270-0x0050f3b2`: investigated with IDA `analyze_function` and raw PE scan. It calls WorldMapPane/child-pane construction code but has no direct callers/xrefs or raw hits. It should not be created until source route evidence exists.
- `0x0050f3b2-0x0050f4d0` and `0x0050f52a-0x0050f9c0`: earlier signature checks showed code-like bytes mixed with padding, not pure alignment. These spans need a future exact raw-helper pass before any ignored or child rows are recommended.
- `0x005104c7-0x00513800`: still the largest [UID:0001AW] leaf and should be the next major continuation after this batch. Known route leads include `0x005104d0`, `0x00510960`, `0x00511440`, `0x00511db0`, `0x00512960`, `0x00512d60`, WorldMapPane creation boundaries, opcode names, and packet payload structures.
- Final C++ blockers for the new children: exact source helper names, tile descriptor structure, StaticObjectPane id field name, MapPane object-list field/helper names, and static-object metadata record fields remain provisional. The new child pages clear the documentation/ownership gate but should keep final C++ blank.

## No-Direct-Edit Confirmation

B001 created this research report only:

- Created: `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch5.md`
- Modified: none outside the research report.
- IDA DB: no edits.
- Generated reports and `by-memory/-coverage-report.md`: no direct edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch5.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
