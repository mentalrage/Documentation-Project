** TARGET-REPORT-UID:0002QG **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: MapPane Movement And Object Update Cluster

Assignment id: `B002-goal2-mappane-movement-object-update-source-quality-0002QG-0002QL-0002QM-0002QN-20260618`

Targets:

- [UID:0002QG] `by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md`
- [UID:0002QL] `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md`
- [UID:0002QM] `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`
- [UID:0002QN] `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`

Report-only statement: I did not edit by-memory docs, generated reports, generated source, the IDA database, or `by-memory/-coverage-report.md`. This report is the only intended output file.

## Summary Recommendation

| UID | Current | Recommended | Owner / emitter | C++ |
| --- | ---: | ---: | --- | --- |
| `0002QG` | `84/88` | `87/90` | Change `0000L3` -> `00007Q` | Populate first-draft `MapPane::QueueMotionMessage` / deferred motion queue method. |
| `0002QL` | `84/88` | `87/90` | Keep `00007Q` | Populate first-draft `MapPane::ScrollViewportByDirection`. |
| `0002QM` | `84/88` | `88/90` | Keep `00007Q` | Populate first-draft `MapPane::RecenterAndSendPosition`. |
| `0002QN` | `84/88` | `88/90` | Keep `00007Q` | Populate first-draft `MapPane::CreateOrUpdateObjectPane`. |

All four targets are source-bearing MapPane methods under the active code-entry gate: `RECONSTRUCTABLE:TRUE`, valid nonblank emitter [UID:00007Q] `MapPane`, and average score above 85 after this pass. The old "final C++ remains blank because names are provisional" language is now stale for this exact cluster. The formal C++ should be first-draft, descriptive, and allowed to carry inferred names with documented uncertainty.

## Evidence Checked

- Current target pages for `0002QG`, `0002QL`, `0002QM`, and `0002QN`.
- Support docs: [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane` file, [UID:0001AP] `MapPaneWeatherCoordinateObjectCore`, [UID:00037Q] `MapPaneObjectLookupHelpers`, [UID:00037W] `MapPanePaintLightingCore`, [UID:00037Y] `MapPaneTileObjectGridRenderCore`, [UID:0000M6]/[UID:00009S]/[UID:000179] `ObjectStatusBlob`, [UID:0001FW]/[UID:0002R9] Region/Motion rectangle helpers, [UID:0001D3] `ObjectListAccessorsAndSweeps`, [UID:00023D] `ObjectListStaticObjectLightingSyncHelper`, [UID:0003XP] `ObjectPaneGetMapPosition`, and [UID:0001SO] `MapServerPacketOpcode`.
- Current generated coverage: `auto-generated/-ag-memory-coverage.md` still marks all four target rows as `no` C++; `0002QG` still emits through file UID `0000L3` while the other three emit through class UID `00007Q`.
- Current `by-memory/-coverage-report.md` rows 2079 and 2084-2086 still carry compact `84% : strong` summaries.
- Live MCP was unavailable for this execution. I attempted the local MCP HTTP endpoint at `127.0.0.1:13337/mcp` and received a connection failure. I therefore treated existing live-IDA-backed docs as the IDA evidence record and performed a direct PE scan on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for route/call/pointer checks.
- Direct PE scan anchor: MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`. Relevant sections: `.text` `0x00401000-0x0060c4ac`, `.rdata` `0x0060d000-0x0066c0be`, `.data` `0x0066d000-0x0069ce24`.
- Direct PE route checks:
  - `0x005046d0`: no direct rel32 call/jump; one pointer hit at `.rdata:0x0061e73c`, matching the documented MapPane vtable slot.
  - `0x005058b0`: one direct call at `0x005a8597`.
  - `0x005059d0`: direct calls at `0x00505f48`, `0x00507f73`, `0x005113a0`, `0x005a822a`, `0x005ab169`, `0x005ab2b2`, `0x005ab3cf`, `0x005ab71c`, and `0x005ac23b`.
  - `0x00505e00`: direct calls at `0x0050fca5` and `0x00511664`.
  - `0x0050a940`: direct calls at `0x00505ef6`, `0x0050f0f1`, and `0x00538a83`.
  - `0x00532730` `ObjectList::ShiftAll`: one direct call at `0x005058f9`.
  - `0x0050f130` static-object tile-region reconciliation: direct calls at `0x00505be0`, `0x0050bff9`, `0x00510e28`, and `0x00511318`.
  - `0x00505080` direction-to-offset helper has broad direct-call fan-in and is called from `0x005058d5`.
- Historical Wave2/source-name material was treated only as stale/search-lead context where already echoed by current docs; it was not used as proof.

## Heuristic / Inference Reanalysis And Validation

### [UID:0002QG] MapPane Queued Motion Message

Best source placement: this is a `MapPane` class method, not a file-level helper. The old file-route was a conservative workaround when the class route and score gate were unresolved. Current evidence is stronger: the only non-code route is a `MapPane` vtable slot at `0x0061e73c -> 0x005046d0`, the method consumes `this` fields in the MapPane layout, and the direct parent class now clears the active code-entry gate.

Best source-facing method direction: `MapPane::QueueMotionMessage`, `MapPane::QueueDeferredMotion`, or `MapPane::QueueDirtyRegion`. I recommend documenting `MapPane::QueueMotionMessage` as the method label because it preserves the accepted target name while removing raw/provisional wording. In body text, describe the data as deferred motion/dirty-region records rather than generic "message blobs".

Best field/type names:

- `MapPane +0x118`: high-probability `m_deferredMotionRecords[32]` / `m_queuedMotionRecords[32]`. The constructor initializes a fixed 32-entry `0x14` member array at `+0x118`; QG appends at dword index `70 + 5 * count`, exactly `+0x118 + 0x14 * count`; previous-entry comparison uses dword index `65 + 5 * count`, which is `+0x118 + 0x14 * (count - 1)` for nonzero counts.
- `MapPane +0x398`: high-probability `m_deferredMotionRecordCount` / `m_queuedMotionCount`.
- `MapPane +0x39c`: high-probability `m_deferMotionMessages` / `m_deferredMotionActive`.
- The record type is not an arbitrary project-specific packet structure. The callees are the Region/Motion rectangle family: `0x00554680` `Region::Region`, `0x00554720` `Motion::SetRect`, `0x00554760` `Motion::CopyRectFrom`, and raw/modelled Region/Motion containment helpers around `0x00554a60`. The best documentation wording is "deferred motion/dirty-region record backed by the Region/Motion rectangle object layout".
- `sub_544800` is no longer a generic immediate handler: Pane vtable/support docs resolve `0x00544800` as `Pane::InvalidateRect`.
- `sub_544940` remains below exact naming proof, but its local role is defensible as the pane dirty/motion notification helper called after queue updates. Do not overstate an exact original name; use `NotifyDeferredMotionChanged` or `AddDirtyRegion` as a source-draft helper name with a note that the exact Pane helper spelling is still open.

Rejected alternatives:

- File-only owner [UID:0000L3] is now stale for this exact method. The file remains the source module, but the semantic owner/emitter should be [UID:00007Q].
- "Layer state array" for `+0x118` is superseded. The fixed 32-entry, `0x14` stride array ending immediately before `+0x398` is exactly the deferred queue consumed here; no layer call evidence was found for this field family in the current target.
- Packet/message-record naming is too broad. The helper never touches socket packet data; it coalesces rectangles/motions before forwarding or invalidating.

Remaining uncertainty: the exact original C++ spelling of the `0x00544940` Pane helper and whether the source class used `Region`, `Motion`, or a typedef for the 0x14 records. This should cap the target below final audit but does not block first-draft C++.

Score/source/C++ impact: raising to `87/90`, routing through [UID:00007Q], and populating first-draft C++ is justified. The formal C++ should use descriptive helper names and keep exact Region/Motion spelling as inferred.

### [UID:0002QL] MapPane Scroll Viewport By Direction

Best source-facing method direction: `MapPane::ScrollViewportByDirection(unsigned char direction)`. The existing title is already source-shaped and is supported by the one direct caller, `UserPane::OnAnimationStep` at `0x005a8597`.

Resolved helper names/roles:

- `0x0053a6b0`: living-object direction remap helper. Current docs prove the mapping `1 -> 3`, `2 -> 0`, `3 -> 1`, default -> `2`. Use `LivingObjectPane::RemapMovementDirectionForMapScroll` or the shorter local draft `RemapMovementDirectionForMapScroll`. It is a callee dependency, not the owner of QL.
- `0x00505080`: MapPane direction-to-tile-offset helper. Best source-facing local name: `MapPane::DirectionToTileOffset`.
- `0x00532730`: [UID:0001D3] proves `ObjectList::ShiftAll`; this target's call at `0x005058f9` is the only direct caller in the PE scan.
- `0x005374d0`: [UID:0003XP] proves `ObjectPane::GetMapPosition(MapPoint *out) const`, with the caveat that store order copies `+0x104` then `+0x100`.
- `0x005a2de0`: [UID:0002RW] `LivingObjectPaneGetViewportPosition`.
- `0x0050bce0`: tile/object-grid refresh helper inside [UID:00037Y]. For this method, use descriptive `RefreshScrolledTileData` or `SetTileDataForScroll`; do not claim a final exact original name from current docs.

Best fields:

- `MapPane +0x418`: `m_activeObjectPane` / `m_localPlayerObjectPane`. QL reads coordinates from this pointer; this is stronger than the current class glossary's `m_objectListDetachPreserve` wording.
- `MapPane +0x424`: `m_objectList`.
- Map tile dimensions are globals from [UID:0000T7], not MapPane fields.

Rejected alternatives:

- `MapPaneSpatialIndex` owner for `ObjectList::ShiftAll` remains a generated/provisional alias. The concrete owner is `ObjectList`; QL consumes it through MapPane's `m_objectList`.
- A shared standalone scroll helper source file is not supported. The receiver, fields, caller path, and refresh handoff are all MapPane local-player movement behavior.

Remaining uncertainty: exact helper spelling for the tile refresh call and row/column output order of the coordinate pair. This is low-risk and does not block first-draft C++.

Score/source/C++ impact: raise to `87/90`, keep [UID:00007Q], populate first-draft C++.

### [UID:0002QM] MapPane Recenter And Send Position

Best source-facing method direction: `MapPane::RecenterAndSendPosition(int targetX, int targetY, int viewportX, int viewportY, bool useActiveObjectViewport)`. The exact integral widths of the coordinate arguments can be normalized later; current calls and packet writers support integer map/viewport coordinates.

Resolved fields:

- `+0x3f4/+0x3f6`: `m_mapWidth`, `m_mapHeight`.
- `+0x404/+0x408`: `m_visibleTileColumns`, `m_visibleTileRows`.
- `+0xac/+0xb0`: `m_pixelOriginX`, `m_pixelOriginY` or `m_viewPixelOrigin`.
- `+0x3fc/+0x400`: `m_tileOriginX`, `m_tileOriginY`.
- `+0x418`: `m_activeObjectPane` / `m_localPlayerObjectPane`, used when the final flag requests active-object viewport coordinates.
- `+0x424`: `m_objectList`.

Resolved helper names/roles:

- `0x005a2de0`: `LivingObjectPane::GetViewportPosition`.
- `0x004b7c50`: Rect geometry initializer/setter from [UID:00015S].
- `0x00554720`: `Motion::SetRect` in the Region/Motion helper family.
- `0x00532f70`: ObjectList extended scan/update helper; use descriptive `m_objectList->RecenterObjects` / `UpdateObjectsForViewportOrigin` in first-draft C++ and keep exact name open.
- `0x0050d840`: MapPane visible tile redraw helper, `DrawVisibleTiles` in current docs.
- `0x00505290`: clamped visible tile bounds helper.
- `0x0050c040`: visible-range checksum helper over [UID:00027N] checksum table.
- `0x00505370`: extended visible bounds helper.
- `0x0050f130`: [UID:0003TJ] `MapPaneRefreshStaticObjectTileRegion`.
- Packet writers `0x005753a0`, `0x00575380`, and `0x005753c0` belong to [UID:0001HZ] `PacketBufferHelpers`.
- Sender path is [UID:0001P0] `g_packetSender` and [UID:0001HU] `QueueAndSendPacket`.

Packet/protocol interpretation:

- This method sends outbound opcode `0x05`, not an inbound `MapServerPacketOpcode` value. The inbound enum page [UID:0001SO] should not absorb it as a server-dispatch entry. Add a note that `0x05` is an outbound client map-position/update packet emitted by `MapPane::RecenterAndSendPosition`.
- Packet layout is already strong: byte `0` opcode `0x05`, bytes `1..2` and `3..4` clamped visible-range coordinates, bytes `5` and `6` old/current viewport deltas from the visible origin, bytes `7..9` checksum, and one zeroed staging byte outside the 10-byte send length.
- The old "flag-clear delta source not initialized" caveat is best resolved as caller/ABI/decompiler noise rather than a semantic blocker. All known flag-clear callers supply the viewport offset pair and execute the send path; the same pair is used for validation and tile-origin math. The high-probability source shape is that `oldViewportX/oldViewportY` are initialized from supplied arguments unless `useActiveObjectViewport` replaces them with the active object's cached viewport position. This conclusion is not source-symbol proof, but it is the only defensible reconstruction that explains the send path without undefined source behavior.

Rejected alternatives:

- Treating the packet delta fields as unresolved random locals is contradicted by the consistent flag-clear caller shape and by the flag-set active-object branch.
- Routing through UserPane or LivingObjectPane is rejected: those are callers/consumers. The owned fields, redraw, object-list reconciliation, and outbound packet send are MapPane behavior.
- Adding `0x05` to the inbound server opcode enum is rejected because this method is an outbound sender.

Remaining uncertainty: exact original names of the ObjectList recenter helper and checksum helper, plus exact coordinate pair order. These cap final audit confidence but do not block first-draft C++.

Score/source/C++ impact: raise to `88/90`, keep [UID:00007Q], populate first-draft C++.

### [UID:0002QN] MapPane Create Or Update Object Pane

Best source-facing method direction: `MapPane::CreateOrUpdateObjectPane(int tileX, int tileY, int objectId, unsigned char action, const ObjectStatusBlob& status)`. The current target name is already source-shaped and supported by both caller paths: object-info/update packet at `0x0050fca5` and draw-objects/spawn packet at `0x00511664`.

Resolved `ObjectStatusBlob` field directions:

- `status +0`: high-probability `m_statusKind` / `m_objectKind`. Values `0` and `1` are living-object records; value `2` is the ground-item/object path.
- `status +4`: compact/full appearance or object/item id field. In QN item path, use `m_appearanceId` / `m_itemId` depending on source context.
- `status +6`: status/palette/variant byte used by compact and item-state paths.
- `status +33/+34`: direction/posture-style bytes.
- `status +36`: default state/action category, initialized to `11` by parsers.
- `status +40`: display/status byte, default `0x50` in partial parser.
- `status +42`: title id; `+44/+46/+48` title metadata words.
- `status +50..+64`: trailing palette/equipment/profile/object-type/effect/status run.

These are high-probability source-facing field aliases, not exact symbol proofs. They are nevertheless better than leaving QN blocked on "compiler-generated names" because the parser pages prove the byte offsets, parse modes, and caller families.

Resolved active-object state-copy target:

- The copy is into the active `LivingObjectPane` / active `ObjectPane` embedded object-status/current appearance state, not into MapPane or ObjectList. The local-player branch compares incoming id to `MapPane +0x418`, removes duplicate external list entries, recenters with [UID:0002QM], then refreshes and copies the full 68-byte blob into that active object's state area. Best field direction: `m_activeObjectPane->m_objectStatus` or `m_activeObjectPane->m_statusBlob`.

Resolved helper names/roles:

- `0x00532370`: `ObjectList::FindByObjectId`.
- `0x00506170`: `MapPane::DetachObjectPane`.
- `0x00537b40`: ItemObjectPane constructor path.
- `0x0050a940`: not merely "item visual helper". [UID:00037W] lists it as a MapPane lighting/effect object setup helper; [UID:0003TI] calls the same helper for static objects after StaticObjImageLib metadata lookup. Direct PE scan confirms the QN item path call at `0x00505ef6` and sibling calls from static-object and object-pane contexts. Best source-facing name: `MapPane::AttachObjectLighting` / `MapPane::AttachLightingObjectForMapObject`. In QN text, say the item pane itself is created by ItemObjectPane, while `0x0050a940` attaches/configures any descriptor-driven lighting/effect companion using half-tile offsets.
- `0x00531c10`: ObjectList remove/type-dispatch remove.
- `0x005314a0`: ObjectList insert/categorize.
- `0x00506980`: MapPane object-position/screen-bounds refresh helper. Current support docs and old integrated-name traces both point to `MapPane::UpdateObjectPosition`; current docs should use that as a high-probability name while noting final exact spelling remains open.
- `0x0053a900`, `0x0053a9f0`, `0x0053a110`, `0x0053bf40`: LivingObjectPane status/appearance/map-position/timer helpers; exact names remain support-owned, but QN can describe them as applying the incoming object status and refreshing animation/timer state.

Rejected alternatives:

- ItemObjectPane ownership for the whole method is rejected. QN chooses between item and living panes, searches/removes/inserts through MapPane's ObjectList, recenters the local map, and owns object-pane creation policy.
- `0x0050a940` as a simple item sprite image helper is rejected because it is also called from static-object setup and sits in the MapPane paint/lighting family. The sprite/image row lookup still belongs to the item/static image libraries; the helper's MapPane-side role is descriptor-driven lighting/effect attachment.
- Leaving `ObjectStatusBlob` unnamed is rejected. Parser pages prove enough offset roles for high-probability field aliases; exact names can remain below final audit without blocking first-draft C++.

Remaining uncertainty: exact source spellings of LivingObjectPane update helpers, the final `ObjectStatusBlob` member names, and whether the original source named status kind `kind`, `mode`, or `type`. These should cap score below 95, but not block C++.

Score/source/C++ impact: raise to `88/90`, keep [UID:00007Q], populate first-draft C++.

### Support-Doc And Generated-Output Impacts

- [UID:00007Q] `MapPane` should replace `+0x118` `m_layerStates` with the deferred motion queue terminology proved by QG. This correction also affects the compiler-artifact note that currently mentions `m_layerStates` vector destructor loop.
- [UID:00007Q] should replace `+0x418` primary alias `m_objectListDetachPreserve` with `m_activeObjectPane` / `m_localPlayerObjectPane`, with a note that destructor/ObjectList cleanup may pass it as a preserve/skip pointer. QL/QM/QN and independent ChatPacketType13 docs all use `g_activeMapPane +0x418` as the active-local object route.
- [UID:0000M6]/[UID:00009S]/[UID:000179] should add a compact field-alias table for the ObjectStatusBlob offsets listed above.
- [UID:0001SO] should add an explicit exclusion note for outbound opcode `0x05`.
- Generated `auto-generated/NexusTK/map/MapPane.cpp` currently lacks formal C++ for all four targets. After supervisor edits and generator rerun, all four should switch from `no` to `yes` in generated memory coverage.

## First-Draft C++ Recommendation

Populate formal C++ for all four targets. The drafts below intentionally use descriptive helper/type names. Exact point-coordinate order and some helper spellings should be normalized later by the MapPane/ObjectPane/ObjectStatusBlob support passes.

### [UID:0002QG] Draft C++

```cpp
void MapPane::QueueMotionMessage(const Rect *rect)
{
    if (!m_deferMotionMessages)
    {
        InvalidateRect(rect);
        return;
    }

    if (rect == NULL)
    {
        m_deferMotionMessages = false;
        NotifyDeferredMotionChanged();
        return;
    }

    Region incoming;
    incoming.SetRect(rect);

    if (m_deferredMotionRecordCount >= 32)
    {
        InvalidateRect(rect);
        return;
    }

    if (m_deferredMotionRecordCount != 0)
    {
        Motion &last = m_deferredMotionRecords[m_deferredMotionRecordCount - 1];

        if (last.Contains(incoming))
            return;

        if (incoming.Contains(last))
        {
            last.CopyRectFrom(incoming);
            NotifyDeferredMotionChanged();
            return;
        }
    }

    m_deferredMotionRecords[m_deferredMotionRecordCount].CopyRectFrom(incoming);
    ++m_deferredMotionRecordCount;
    NotifyDeferredMotionChanged();
}
```

### [UID:0002QL] Draft C++

```cpp
void MapPane::ScrollViewportByDirection(unsigned char direction)
{
    unsigned char scrollDirection = RemapMovementDirectionForMapScroll(direction);

    MapPoint tileDelta;
    DirectionToTileOffset(scrollDirection, &tileDelta);

    Point pixelDelta;
    pixelDelta.x = tileDelta.x * g_mapTilePixelWidth;
    pixelDelta.y = tileDelta.y * g_mapTilePixelHeight;

    if (m_objectList != NULL)
        m_objectList->ShiftAll(pixelDelta.x, pixelDelta.y);

    MapPoint objectPosition;
    MapPoint viewportPosition;
    m_activeObjectPane->GetMapPosition(&objectPosition);
    m_activeObjectPane->GetViewportPosition(&viewportPosition);

    RefreshScrolledTileData(objectPosition.x,
                            objectPosition.y,
                            viewportPosition.x,
                            viewportPosition.y,
                            direction);
}
```

### [UID:0002QM] Draft C++

```cpp
void MapPane::RecenterAndSendPosition(int targetX,
                                      int targetY,
                                      int viewportX,
                                      int viewportY,
                                      bool useActiveObjectViewport)
{
    MapPoint oldViewport;
    oldViewport.x = viewportX;
    oldViewport.y = viewportY;

    if (useActiveObjectViewport && m_activeObjectPane != NULL)
        m_activeObjectPane->GetViewportPosition(&oldViewport);

    if (targetX < 0 || targetY < 0 ||
        targetX >= m_mapWidth || targetY >= m_mapHeight ||
        oldViewport.x < 0 || oldViewport.y < 0 ||
        oldViewport.x >= m_visibleTileColumns ||
        oldViewport.y >= m_visibleTileRows)
    {
        return;
    }

    if (g_useEpfAssets)
    {
        m_pixelOriginX = -g_mapTilePixelWidth;
        m_pixelOriginY = -g_mapTilePixelHeight;
    }
    else
    {
        m_pixelOriginX = 14 - g_mapTilePixelWidth;
        m_pixelOriginY = 12 - g_mapTilePixelHeight;
    }

    Rect bounds;
    SetRect(&bounds,
            m_pixelOriginX,
            m_pixelOriginY,
            m_pixelOriginX + (m_visibleTileColumns + 1) * g_mapTilePixelWidth,
            m_pixelOriginY + (m_visibleTileRows + 1) * g_mapTilePixelHeight);
    SetBounds(&bounds);

    int oldOriginX = m_tileOriginX;
    int oldOriginY = m_tileOriginY;
    m_tileOriginX = targetX - oldViewport.x;
    m_tileOriginY = targetY - oldViewport.y;

    if (m_objectList != NULL)
        m_objectList->UpdateObjectsForViewportOrigin(m_tileOriginX - oldOriginX,
                                                     m_tileOriginY - oldOriginY);

    DrawVisibleTiles();

    MapRect visible;
    GetClampedVisibleTileBounds(&visible);

    unsigned int checksum = ComputeVisibleTileChecksum(visible);

    unsigned char packet[11];
    unsigned char *out = packet;
    *out++ = 0x05;
    out = PacketBufferWriteUInt16BE(out, visible.left);
    out = PacketBufferWriteUInt16BE(out, visible.top);
    out = PacketBufferWriteUInt8(out, oldViewport.x - visible.left);
    out = PacketBufferWriteUInt8(out, oldViewport.y - visible.top);
    out = PacketBufferWriteUInt24BE(out, checksum);
    packet[10] = 0;

    g_packetSender->QueueAndSendPacket(packet, 10);

    MapRect objectRefreshBounds;
    GetExtendedVisibleTileBounds(&objectRefreshBounds);
    RefreshStaticObjectTileRegion(objectRefreshBounds);
}
```

### [UID:0002QN] Draft C++

```cpp
ObjectPane *MapPane::CreateOrUpdateObjectPane(int tileX,
                                              int tileY,
                                              int objectId,
                                              unsigned char action,
                                              const ObjectStatusBlob &status)
{
    ObjectPane *existing = m_objectList->FindByObjectId(objectId);

    if (status.m_statusKind == ObjectStatusBlob::ItemObject)
    {
        if (existing != NULL)
            DetachObjectPane(existing);

        ItemObjectPane *item = new (g_itemObjectPanePool.Allocate())
            ItemObjectPane(tileX, tileY, objectId, action, status);

        const ItemObjectImageEntry *entry =
            g_pItemObjImageLib->Find(status.m_appearanceId);
        if (entry != NULL)
        {
            AttachObjectLighting(item,
                                 entry,
                                 g_mapTilePixelWidth / 2,
                                 g_mapTilePixelHeight / 2);
        }

        UpdateObjectPosition(item);
        m_objectList->InsertByType(item);
        return item;
    }

    if (status.m_statusKind != ObjectStatusBlob::FullLivingObject &&
        status.m_statusKind != ObjectStatusBlob::CompactLivingObject)
    {
        return NULL;
    }

    if (m_activeObjectPane != NULL &&
        m_activeObjectPane->GetObjectId() == objectId)
    {
        if (existing != NULL && existing != m_activeObjectPane)
            m_objectList->RemoveByType(existing);

        RecenterAndSendPosition(tileX, tileY, 0, 0, true);

        LivingObjectPane *active = static_cast<LivingObjectPane *>(m_activeObjectPane);
        active->ApplyObjectStatus(status);
        active->SetMapPosition(tileX, tileY);

        if (active->GetActionState() == 2)
            active->SetActionState(5);

        active->m_objectStatus = status;
        active->ClearAttachedOverlayPanes();
        active->m_transientObjectFlag = false;
        m_pendingLocalObjectRefresh = false;
        active->RefreshAnimationTimer();
        return active;
    }

    if (existing != NULL)
    {
        LivingObjectPane *living = static_cast<LivingObjectPane *>(existing);
        living->ApplyObjectStatus(status);
        living->SetMapPosition(tileX, tileY);
        living->RefreshAnimationTimer();
        UpdateObjectPosition(living);
        return living;
    }

    LivingObjectPane *living = new (g_livingObjectPanePool.Allocate())
        LivingObjectPane(tileX, tileY, objectId, action, status);
    living->RefreshAnimationTimer();
    UpdateObjectPosition(living);
    m_objectList->InsertByType(living);
    return living;
}
```

## Exact Supervisor Edits

### [UID:0002QG]

Metadata replacement:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

Emit through [UID:00007Q][MapPane](by-class/MapPane.md). The previous file-level [UID:0000L3][MapPane](by-file/MapPane.md) route is stale for this exact method because the only non-code reachability route is the `MapPane` vtable slot at `0x0061e73c -> 0x005046d0`, and the method consumes MapPane instance fields.

Best source-facing name is `MapPane::QueueMotionMessage` or `MapPane::QueueDeferredMotion`. The queued record type should be described as a deferred motion/dirty-region record backed by the Region/Motion rectangle layout, not as a packet/message blob. `MapPane +0x118` is the 32-entry `0x14`-stride deferred record array; `+0x398` is the queued record count; `+0x39c` is the deferred-motion active flag. The existing class glossary name `m_layerStates` for `+0x118` is superseded by this queue evidence.

Formal first-draft C++ is recommended under the active code-entry gate. Exact original spelling for the `0x00544940` Pane dirty/motion notification helper and for the Region/Motion typedef remains below final-audit proof, so use descriptive helper names and keep the score below 95.
```

Place the draft C++ from this report between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

### [UID:0002QL]

Metadata replacement:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace `## Reconstruction Notes` with:

```markdown
## Reconstruction Notes

Formal first-draft C++ is recommended under the active code-entry gate. The remaining names are source-facing and descriptive rather than blocker-grade: `0x0053a6b0` is the living-object movement-direction remap helper, `0x00505080` is `MapPane::DirectionToTileOffset`, `0x00532730` is `ObjectList::ShiftAll`, `0x005374d0` is `ObjectPane::GetMapPosition`, `0x005a2de0` is the active object's viewport-position getter, and `0x0050bce0` is the tile/object-grid refresh helper for the scrolled view.

Use `MapPane +0x418` primarily as `m_activeObjectPane` / `m_localPlayerObjectPane` and `MapPane +0x424` as `m_objectList`. Exact row/column output order and tile-refresh helper spelling remain cleanup items, not final-C++ blockers.
```

Place the draft C++ from this report between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

### [UID:0002QM]

Metadata replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the caveat paragraph in `## Behavior` beginning `One caveat remains:` with:

```markdown
The previous flag-clear packet-delta caveat is now best treated as caller/ABI/decompiler noise rather than an unresolved semantic blocker. The defensible source shape is that the supplied viewport-offset pair initializes the old/current viewport pair for flag-clear callers; when the final flag is set, the method replaces that pair with the active object's cached viewport position through [UID:0002RW][0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition.md). All known flag-clear callers pass the offset pair and execute the send path, so leaving the delta fields as uninitialized source locals is not credible. Exact coordinate names/order remain below final audit, but first-draft C++ should use `oldViewportX` / `oldViewportY` or equivalent.
```

Replace `## Reconstruction Notes` with:

```markdown
## Reconstruction Notes

Formal first-draft C++ is recommended under the active code-entry gate. Best source-facing signature direction is `MapPane::RecenterAndSendPosition(int targetX, int targetY, int viewportX, int viewportY, bool useActiveObjectViewport)`. Resolved field aliases are `m_mapWidth/m_mapHeight` at `+0x3f4/+0x3f6`, `m_visibleTileColumns/m_visibleTileRows` at `+0x404/+0x408`, `m_pixelOriginX/m_pixelOriginY` at `+0xac/+0xb0`, `m_tileOriginX/m_tileOriginY` at `+0x3fc/+0x400`, `m_activeObjectPane` at `+0x418`, and `m_objectList` at `+0x424`.

Outbound opcode `0x05` belongs to this MapPane send helper, not to the inbound `MapServerPacketOpcode` dispatcher enum. Packet layout remains byte `0` opcode, bytes `1..4` clamped visible-range coordinates, bytes `5..6` viewport deltas from the visible origin, bytes `7..9` checksum, and a zeroed staging byte outside the 10-byte send length. Exact names for the ObjectList recenter helper and checksum helper remain descriptive cleanup items, not C++ blockers.
```

Place the draft C++ from this report between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

### [UID:0002QN]

Metadata replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace `## Reconstruction Notes` with:

```markdown
## Reconstruction Notes

Formal first-draft C++ is recommended under the active code-entry gate. Best source-facing signature direction is `MapPane::CreateOrUpdateObjectPane(int tileX, int tileY, int objectId, unsigned char action, const ObjectStatusBlob& status)`.

The `ObjectStatusBlob` field names are not symbol-proven but are now good enough for source drafts: `+0` is status/object kind, with values `0`/`1` for living objects and `2` for item objects; `+4` is appearance/object/item id; `+6` is compact status/palette/variant byte; `+33/+34` are direction/posture-style bytes; `+36` is default state/action category; `+40` is a display/status byte; `+42/+44/+46/+48` are title id and title metadata; and `+50..+64` is the palette/equipment/profile/object-type/effect/status run.

The active-object local-player branch copies the 68-byte status blob into the active `LivingObjectPane` embedded current-status/object-status state, not into MapPane or ObjectList. Use `m_activeObjectPane->m_objectStatus` / `m_statusBlob` as the source-draft target name.

The helper at `0x0050a940` should not be called a generic item visual helper. It is a MapPane lighting/effect object setup helper also called from static-object setup, so document it as `MapPane::AttachObjectLighting` / `AttachLightingObjectForMapObject` with exact spelling still open. ItemObjectPane owns the ground-item pane construction; MapPane owns the creation/update policy and descriptor-driven lighting/effect attachment.
```

Place the draft C++ from this report between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

### Support Doc Edits

In [UID:00007Q] `by-class/MapPane.md`, replace these field glossary rows:

```markdown
| `+0x118` | `m_layerStates` / `m_mapLayerStates` | descriptive; fixed 32-entry `0x14` array. |
| `+0x418`, `+0x41c`, `+0x420`, `+0x424` | `m_objectListDetachPreserve`, `m_auxiliaryPane`, `m_activeScreenLayer`, `m_objectList` | `m_objectList` is strong; the others remain descriptive names for source drafts. |
```

with:

```markdown
| `+0x118` | `m_deferredMotionRecords` / `m_queuedMotionRecords` | high-probability; constructor initializes exactly 32 `0x14`-byte Region/Motion-style records, and [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md) appends at `+0x118 + 0x14 * count`. This supersedes the older `m_layerStates` alias. |
| `+0x398`, `+0x39c` | `m_deferredMotionRecordCount`, `m_deferMotionMessages` | high-probability queue count and deferred-motion active flag used by [UID:0002QG]. |
| `+0x418`, `+0x41c`, `+0x420`, `+0x424` | `m_activeObjectPane` / `m_localPlayerObjectPane`, `m_auxiliaryPane`, `m_activeScreenLayer`, `m_objectList` | `+0x418` is the active/local object pointer in movement, chat-state, recenter, and create/update paths; destructor/ObjectList cleanup may use the same pointer as a preserve/skip object. `m_objectList` at `+0x424` is strong. |
```

In the same MapPane page, replace:

```markdown
Compiler artifacts are not source statements: MapPane vtable writes/reseats, scalar deleting destructor flag handling, destructor adjustor thunks, `m_viewportGrafPort` explicit destructor call, `m_layerStates` vector destructor loop, and base `Pane` destructor call should stay represented as normal C++ class/member/base behavior.
```

with:

```markdown
Compiler artifacts are not source statements: MapPane vtable writes/reseats, scalar deleting destructor flag handling, destructor adjustor thunks, `m_viewportGrafPort` explicit destructor call, deferred-motion record member-array construction/destruction, and base `Pane` destructor call should stay represented as normal C++ class/member/base behavior.
```

In [UID:00009S] `by-class/ObjectStatusBlob.md` and [UID:000179] `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`, insert after the existing layout/field-offset notes:

```markdown
## Source-Draft Field Alias Guidance

These aliases are high-probability source-facing names for consumers such as [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md), not exact symbol proofs:

| Offset | Source-draft alias | Evidence |
| --- | --- | --- |
| `+0` | `m_statusKind` / `m_objectKind` | Parser mode field; MapPane object creation treats `0`/`1` as living objects and `2` as item objects. |
| `+4` | `m_appearanceId` / `m_objectIdOrItemId` | Compact/partial parsers write the 16-bit id here; item path uses it for image/resource lookup. |
| `+6` | `m_variantOrPalette` / `m_compactStatusByte` | Compact/partial status byte written beside the id. |
| `+33`, `+34` | `m_direction`, `m_posture` | Full and partial parsers write the leading direction/posture-style bytes here. |
| `+36` | `m_state` / `m_actionCategory` | Full/partial parsers initialize default value `11`; local-player update normalizes one action/status value from `2` to `5`. |
| `+40` | `m_displayStatusByte` | Full parser reads it from payload; partial parser defaults it to `0x50`. |
| `+42`, `+44`, `+46`, `+48` | `m_titleId` and derived title metadata | Full parser reads title id and fills metadata words when nonzero. |
| `+50..+64` | equipment/palette/profile/object-type/effect/status run | Full parser fills this trailing run from payload offsets `+8..+42`. |
```

In [UID:0001SO] `MapServerPacketOpcode.md`, insert under `## Dispatcher Scope` or `## Declaration Readiness`:

```markdown
Outbound opcode note: `0x05` is sent by [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) as a 10-byte client map-position/update packet. It is not an inbound `MapPane::HandlePacket` switch value and should remain excluded from this server-opcode enum except as an outbound cross-reference.
```

## Coverage Row Recommendation

Replace the existing `by-memory/-coverage-report.md` rows for these UIDs with the following after supervisor application:

```markdown
        - [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md) 0x005046d0-0x005047e8 | method | MapPaneQueuedMotionMessage : reconstructable : 87% : very strong : B002 2026-06-18 source-quality pass routes this vtable-backed method through `MapPane` class UID `00007Q`, resolves `+0x118/+0x398/+0x39c` as the deferred motion/dirty-region queue family, identifies Region/Motion rectangle helpers and `Pane::InvalidateRect` immediate path, rejects the stale file-only route and `m_layerStates` alias, and recommends first-draft C++ with only exact Pane notification/helper spelling still open.
        - [UID:0002QL][0x005058b0-0x0050593e.MapPaneScrollViewportByDirection](by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md) 0x005058b0-0x0050593e | method | MapPaneScrollViewportByDirection : reconstructable : 87% : very strong : B002 2026-06-18 source-quality pass resolves the one-caller local-player scroll path, source-facing `ScrollViewportByDirection` method shape, direction remap, `MapPane::DirectionToTileOffset`, `ObjectList::ShiftAll`, active-object map/viewport position accessors, `+0x418` active-object pointer, `+0x424` object-list pointer, and first-draft C++ readiness with only exact tile-refresh helper spelling and coordinate-order cleanup below final audit.
        - [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) 0x005059d0-0x00505bf8 | method | MapPaneRecenterAndSendPosition : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves MapPane field aliases for map dimensions, visible extents, pixel origin, tile origin, active object, and ObjectList; treats flag-clear packet delta source as caller-supplied viewport state rather than undefined source locals; distinguishes outbound opcode `0x05` from the inbound server opcode enum; and recommends first-draft C++ for recenter, redraw, position-packet send, and static-object reconciliation.
        - [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md) 0x00505e00-0x005060e3 | method | MapPaneCreateOrUpdateObjectPane : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves source-facing create/update method shape, ObjectStatusBlob status-kind/appearance/status/title/equipment field aliases, active-object status-copy target, local-player recenter branch, item/living pane creation policy, `0x0050a940` as MapPane descriptor-driven lighting/effect attachment rather than generic item drawing, and first-draft C++ readiness.
```

Expected generated coverage after rerun: the four `auto-generated/-ag-memory-coverage.md` rows should change their C++ column from `no` to `yes`, and `0002QG` should show emitter/owner `00007Q` instead of `0000L3`.

## Validator Commands

Run after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality-removed.md](0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the local validator uses a different CLI wrapper, run the equivalent per-target validation plus generated-coverage regeneration/check. The important postconditions are: metadata parses, no target has blank C++ with average score above 85, `0002QG` no longer emits through file UID `0000L3`, and generated MapPane.cpp contains four new formal draft bodies.

## Changed Files / No Direct Edit Statement

Only this report file was created by this assignment:

```text
tools/leaser/Agents/Agent-B002/research/0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md
```

No by-memory documents, generated reports, generated source, IDA database files, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002QG"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002QG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
