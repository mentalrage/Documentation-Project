*** UID:00042K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Layout support only. The MapPane class declaration is owned by [UID:00007Q][MapPane](by-class/MapPane.md); no standalone MapPaneLayout C++ is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapPane Layout

## Status

- Entity kind: focused class-layout support for [UID:00007Q][MapPane](by-class/MapPane.md).
- Likely owner header/source: [UID:0000L3][MapPane](by-file/MapPane.md).
- Scope: offsets used by the accepted [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) split and the related notify/timer children.
- UID0003TL support scope: opcode `0x06` map-info/tile-region packet handling uses additional source-facing field names recorded below as layout candidates for accepted first-draft C++.
- Confidence: very strong for the complete `0x910` size/layout, inherited boundary, value-object regions, canonical offset identities, and alignment; original private spellings for bounded behavior-only state remain lexical caps.
- Formal C++ carries a layout-support no-code comment because complete declaration emission is now owned by UID00007Q rather than duplicated here.

## Complete 0x910 Layout Closure - 2026-07-15

- `MapPane` is exactly `0x910` bytes. `Pane` occupies `[0x000,0x0f8)` and already contains the leading GrafPort plus EventHandler and TimerHandler views. MapPane-owned state begins at `+0x0f8`; the constructor allocation route, constructor writes, ordinary destructor cleanup, and UID00007Q size guard independently enforce the terminal boundary.
- The constructor builds 32 `Motion` values at `+0x118` with exact `0x14` stride and an embedded `GrafPort` at `+0x428`; the destructor destroys those same complete-value regions. This excludes byte arrays or pointers for either region.
- Canonical source identities are singular: `+0x414` is `m_weatherLayerPane`, `+0x418` is `m_localPlayerObjectPane`, `+0x3f0` is `m_waitingForLocalPlayerStatus`, and inherited `+0xac/+0xb0` are `m_viewportPixelY/m_viewportPixelX`. Historical generic aliases describe local contexts only and are not alternate union members.

| Range | Complete source-facing state |
| --- | --- |
| `+0x0f8..+0x117` | effecter count/capacity/pointer; highlighted and selected living-object state; signed map-resource mode; map-effect enable byte; exact alignment |
| `+0x118..+0x397` | `Motion m_deferredMotionRecords[32]` |
| `+0x398..+0x39f` | deferred record count; defer, queued-map-refresh, and pending-action-poll bytes; one alignment byte |
| `+0x3a0..+0x3b7` | six dwords of pending movement/map policy state; exact storage is proven while private lexemes remain inferred |
| `+0x3b8..+0x3df` | ten day/night brightness, tint, curve, projection, and target floats |
| `+0x3e0..+0x3ef` | owned `AlphaMaskSurface *`; brightness scale/bias; pending map-state token |
| `+0x3f0..+0x427` | waiting/timer bytes; map id/dimensions/tile buffer/origin/visible span; transition/weather/movement/hour state; weather-layer/local-player/auxiliary/layer/ObjectList pointers |
| `+0x428..+0x4c7` | embedded `GrafPort m_viewportGrafPort` |
| `+0x4c8..+0x4db` | flash color; runtime/visible-refresh/full-refresh bytes and alignment; display origin pair; display scale percent |
| `+0x4dc..+0x8df` | two 256-wide-character map/resource names with 16-bit lengths |
| `+0x8e0..+0x90f` | bounded action state; pending-action flag/alignment; target tile pair; 20-byte route state; target object id; two deferred-surface dirty bytes and exact final alignment |

- Behavior-only labels in the formal class (`m_pendingMovementState`, `m_actionStatePrefix`, and `m_pendingActionState`) are intentionally bounded rather than decompiler labels. Their byte extents and alignment are exact and do not defer any type, size, or class-emission question.

## UID0003TK Effect Map-State Field Lifecycle - 2026-07-15

- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) is an exact source-bearing consumer that independently closes the canonical identities and runtime order of the map-state fields below. It stores `m_mapRuntimeMode +0x4cc` before testing `m_visibleObjectRefreshPending +0x4cd` together with map id/width/height inequality. The rebuild branch clears the pending byte, then stores `m_mapHeight +0x3f6`, `m_mapTransitionState +0x40c`, `m_mapId +0x3f2`, and `m_mapWidth +0x3f4` in that observed order after ObjectList replacement.
- `m_weatherType +0x410` supplies the existing SetMapState type, while packet flag bit `0x01` supplies its mode argument; canonical stored `m_weatherMode +0x40d` remains the current weather-mode field. Canonical `bool m_movementStatusTagDisabled +0x40e` is assigned after the rebuild branch from flag bit `0x02`; the bit disables optional movement-history/status tagging. `m_dayNightHour +0x40f` indexes the exact 24-float table after the packet updates `m_dayNightBrightnessScale +0x3e4` and `m_dayNightBrightnessBias +0x3e8`.
- The day/night target path reads `m_currentDayNightBrightness +0x3b8`, `m_dayNightTintCurveScale +0x3c8`, and `m_dayNightTintCurveBase +0x3cc`. It clamps adjusted brightness and passes the quadratic output as tint amount to SetDayNightFadeTarget. Historical duration names are disproven by the target plus Riding/Monster consumers and remain superseded aliases only.
- Existing `m_objectList +0x424` detaches `m_localPlayerObjectPane +0x418` before deletion and replacement. `m_auxiliaryPane +0x41c` is the sole guard for both its own remove/unregister/delete sequence and the detach/delete of `m_activeScreenLayer +0x420`; no independent layer guard is present. The method then sets `m_waitingForLocalPlayerStatus +0x3f0` true. This extends, and does not replace, the render/weather and local-player-status set/clear lifecycle already documented for that byte.
- The two EPF branches use canonical `m_queuedMapStateRefresh` and the exact final-layout `m_deferredPrimarySurfaceDirty` / `m_deferredSecondarySurfaceDirty` bytes near `+0x90c/+0x90e`. Primary dirty state clears before the first ClearQueuedMapStateRefresh call. The second branch reloads the EPF global, requires primary already clear plus queued state, then clears secondary dirty state before the same helper. These are source members, not raw-offset aliases; the exact layout/formal remains owned by UID00007Q.
- Historical `m_hasRenderableMap`, generic dirty names, standalone active-layer cleanup, and day/night-duration interpretations are rejected. This synchronization changes no size, offset, alias, score, owner/emitter, or formal C++; it adds only complete target-driven lifecycle evidence to the existing layout support page.

## Compressed Map Cache Consumers

- Canonical current field names are `m_mapWidth` at `+0x3f4`, `m_mapHeight` at `+0x3f6`, and `m_tileBuffer` at `+0x3f8`. The UID0003TL spellings `m_mapWidthTiles`, `m_mapHeightTiles`, and `m_mapTileRecords` were later source-shape assumptions and are retained only as superseded history.
- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md) reads/sets all three fields while validating `CMAP`, comparing two 16-bit dimensions, and inflating a six-byte-per-tile payload. [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md) multiplies the width/height fields, allocates `sizeof(MapPaneTileRecord)` rows into the pointer, and zeroes the complete buffer without freeing prior storage.
- Paired [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md) writes the same dimensions and compresses the same `6 * width * height` tile bytes; its successful path frees and clears the pointer. Coordinate, visible-bounds, collision, render, static-object, and UID0003TL packet consumers independently corroborate the offsets and six-byte row stride.
- Four-byte MapTileImageLib records are a distinct resource-table type and cannot describe this live six-byte MapPane buffer. This page keeps its owner/emitter and covered-by formal comment and does not emit a standalone class or struct; UID00037W field/type resolution raises the focused layout evidence to `90/92`.

## Render-View Consumers

- [UID:0004QW][0x00509470-0x00509478.MapPaneGetCurrentMapId](by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md) is the exact eight-byte word getter for `m_mapId` at `+0x3f2`. [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md) is the exact 191-block render consumer for the state below. Their parent [UID:00037V][0x00509470-0x0050a4fd.MapPaneRenderViewCore](by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md) is a non-emitting mixed split index.
- `+0x3f0` is `m_waitingForLocalPlayerStatus`, not `m_hasRenderableMap`: initialization/map-effect transition paths set it, local-player status creation clears it, and render/weather consumers early-out while set. The old name inverted the observed gate.
- `+0x3e0` remains compatibility-spelled `m_selectionOverlay`, but its exact type is `AlphaMaskSurface *`: construction stores `new AlphaMaskSurface`, destruction deletes the pointer, and UID0004RE dereferences it. `+0x3dc` is the day/night target brightness. The historical embedded-object interpretation is superseded.
- `+0x418` is the active/local UserPane used by the pre-render screen-position update and blind-mode local-only pass. `+0x424` is ObjectList; `+0x428` is the embedded viewport GrafPort. `+0x4c8` remains `m_mapFlashColor` and is consumed as a draw color when nonzero.
- EffectObjectPane `+0x14d` and UserPane player-settings byte `[4]` are dependency fields, not MapPane layout. Their late-effect selector and blindness-level roles are documented on their owning pages.
- This synchronization preserves the owner/emitter route and layout-only formal block. UID00007Q now emits the complete class declaration; original private spellings for bounded state remain lexical caps, while types, offsets, lifecycles, and source behavior are implementation-ready.

## Paint And Lighting Layout

- The accepted UID00037W split resolves the full state surface used by UID0004RA-UID0004RE and the paired predicates. The broad parent is a non-emitting index; these offsets belong to the complete [UID:00007Q][MapPane](by-class/MapPane.md) class declaration.
- `LivingObjectPane *m_highlightedObjectPane` at `+0x104` is cleared by OnPaint after exact terminal-animation or human/composition-mode-5/GM-suffix policy.
- The accepted screen-effecter storage remains the count/capacity/pointer triplet at `+0xf8/+0xfc/+0x100`. OnPaint's large inlined allocation sequence is source-reduced to `ConfigureScreenEffecterList` and does not imply extra layout fields.
- `Motion m_deferredMotionRecords[32]` begins at `+0x118` with exact `0x14` stride; `m_deferredMotionRecordCount` at `+0x398` and `m_deferMotionMessages` at `+0x39c` control the deferred dirty-region render policy.
- `m_currentDayNightBrightness` at `+0x3b8`, `m_dayNightTintCurveScale` at `+0x3c8`, and `m_dayNightTintCurveBase` at `+0x3cc` drive the exact quadratic tint output. Historical `m_dayNightDurationCurveScale` and `m_dayNightDurationBase` are retained only as superseded aliases.
- `m_dayNightTintAmount` at `+0x3d0`, `m_newHumanProjectionDivisor` at `+0x3d4`, and `m_newHumanProjectionShear` at `+0x3d8` are independently proven by Riding/Monster scaled-RLE callback arguments. UID0004RC writes tint plus fixed `2.0f`/`0.8f` projection values.
- `m_dayNightTargetBrightness` at `+0x3dc` is the setter/render/predicate target. `AlphaMaskSurface *m_selectionOverlay` at `+0x3e0` is the pointer-owned overlay used by UID0004RE and UID0004QY.
- The current helper declarations are `ComputeDayNightBrightnessAndTint`, `SetDayNightFadeTarget(float targetBrightness, float tintAmount)`, and `RenderDayNightOverlay(const RectBounds *)`; the old duration/helper aliases and embedded overlay are historical only.

## Focused Offset Ledger

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0xf8/+0xfc/+0x100` | `m_screenEffecterCount`, screen-effecter capacity, `m_screenEffecters` | Accepted effect-list triplet; UID0004RA checks count, signed `m_mapResourceMode`, and config enable before invoking the accepted configuration helper. |
| `+0x104` | `LivingObjectPane *m_highlightedObjectPane` | UID0004RA tests terminal animation and human/composition/GM conditions, clears highlighting, then nulls this pointer. |
| `+0x114` / `+276` | `m_mapResourceMode` | [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) optionally reads a packet mode byte, compares it with the old value, stores it at `this+276`, and calls `sub_5040A0` / `ResetMapResourceStateForModeChange` when it changes. |
| `+0x118` | `Motion m_deferredMotionRecords[32]` | Exact `0x14` stride and 32-element constructor/queue/OnPaint inventory; supersedes older layer-state aliases. |
| `+0x398/+0x39c` | `m_deferredMotionRecordCount`, `m_deferMotionMessages` | UID0004RA sums the first count records, chooses full/per-record rendering, clears count, and enables defer state on the nondeferred route. |
| `+0xb0` / `+0xac` | inherited X/column `m_viewportPixelX` and Y/row `m_viewportPixelY` | [UID:000427][0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll](by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md) writes the width/column delta to `MapPane+0xb0` and the height/row delta to `MapPane+0xac`; [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) repeats those stores. Historical `m_pixelOriginX/m_pixelOriginY` are superseded aliases, not separate fields. |
| `+0x39d` | `bool m_queuedMapStateRefresh` | Canonical single current field. Raw UID00042E/UID00042G set it before scheduling timer ids `6`/`8`; [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) and [UID:00042F][0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh](by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md) clear it before canceling ids 6/8 and releasing mouse capture; [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) gates/reschedules both paths. `m_movementTimerQueued` is retained only as a superseded descriptive alias. |
| `+0x39e` | `m_pendingActionPoll` | Canonical bool: [UID:00042H][0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer](by-memory/0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer.md) sets this byte to `1` before converting complete MapPane at `this+0xa4` to the inherited TimerHandler facet and scheduling timer id `7`; timer event `7` in [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) consumes it for left-button/local-player action polling; [UID:00042I][0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll](by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md) clears it and cancels timer id `7`. Historical `m_leftButtonActionPending` is a superseded alias only. |
| `+0x3b8` | `m_currentDayNightBrightness` | UID0004RB subtracts this value before applying the quadratic tint curve. |
| `+0x3c8/+0x3cc` | `m_dayNightTintCurveScale`, `m_dayNightTintCurveBase` | UID0004RB computes tint as scale times squared brightness delta plus base. Historical duration names are superseded. |
| `+0x3d0/+0x3d4/+0x3d8` | `m_dayNightTintAmount`, `m_newHumanProjectionDivisor`, `m_newHumanProjectionShear` | UID0004RC writes the fields; Riding/Monster scaled-RLE consumers prove tint/vertical-projection/horizontal-shear roles. |
| `+0x3dc` / `+988` | `m_dayNightTargetBrightness` | UID0004RC writes it; UID0004QY, UID0004RE, UID0004RG, and UID0004RH consume it. |
| `+0x3e0` / `+992` | `AlphaMaskSurface *m_selectionOverlay` | Pointer ownership is exact from allocation/deletion and UID0004RE dereferences; selection-only and embedded-object wording is superseded. |
| `+0x3f0` / `+1008` | `m_waitingForLocalPlayerStatus` | Initialization and map/effect transition paths set the byte, local-player status creation clears it, and UID0004QY plus weather/render paths early-out while it is set. Historical `m_hasRenderableMap` inverted the branch meaning and is superseded. |
| `+0x3f1` / `+1009` | `m_objectInteractionTimerActive` | UID0004QB sets this byte only before sending a human-object interaction packet and schedules timer id `5` for 4000 ms; UID0003ZS case 5 clears it. Nonhuman interaction bypasses the gate. Historical `m_timerState5` was role-unknown and is superseded. |
| `+0x3f2` | `m_mapId` | Exact UID0004QW `MapPane::GetCurrentMapId() const` returns this 16-bit word through `movzx`; six direct consumers and load/save/transition paths corroborate it. The getter is outside UID00037U and is the first source child of UID00037V. |
| `+0x3f4/+0x3f6` / `+1012/+1014` | `m_mapWidth`, `m_mapHeight` | Validated by compressed-map load/save and allocation, coordinate validation, visible-bounds helpers, movement collision checks, `MapPane::RecenterAndSendPosition`, and UID0003TL clipping/row stride. Historical `m_mapWidthTiles`/`m_mapHeightTiles` aliases are superseded. |
| `+0x3f8` / `+1016` | `m_tileBuffer` | Loaded/allocated MapPane tile-buffer pointer. UID0002QJ inflates into it, UID0004PZ allocates/zeroes it, UID0002QK compresses/frees it, and UID0003TL indexes six-byte [UID:0004HP][MapPaneTileRecord](by-type/by-struct/MapPaneTileRecord.md) entries as `tileX + tileY * m_mapWidth`. Historical `m_mapTileRecords` is superseded. |
| `+0x3fc/+0x400` | `m_tileOriginX`, `m_tileOriginY` | Used by map/screen conversion, visible-bounds helpers, and recenter logic. |
| `+0x404/+0x408` | `m_visibleTileColumns`, `m_visibleTileRows` | Used by coordinate validation, visible-span getter, visible-bounds builders, and recenter validation. |
| `+0x40c` | `m_mapTransitionState` | UID0004QE stores the fifth ChangeMap argument here on every transition before map id/weather update, including same-id changes. |
| `+0x40d` | `m_weatherMode` | Map weather/render state byte; UID0004QE passes its incoming weather-mode byte into SetMapState while preserving the separate current weather-type argument. |
| `+0x40e` | `bool m_movementStatusTagDisabled` | Constructor [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) initializes it true through the packed `0x00010001` store at `+0x40c`; [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) is the sole runtime writer and stores flag bit `0x02`; [UID:000426][0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag](by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md) is the sole direct reader and returns the inverse. Global config requests the feature while this per-map bool vetoes it. Historical `m_movementGate` / `m_viewportMoveGate`, day/night, collision, and enabled-polarity interpretations are rejected. |
| `+0x410` | `m_weatherType` | Current dword weather type consumed as the first SetMapState argument by UID0004QE; distinct from incoming byte `m_weatherMode` at `+0x40d`. |
| `+0x414` | `m_weatherLayerPane` | SetMapState owns/recreates this weather-layer pane, and exit teardown queues it for deferred deletion. Older generic `m_deferredCleanupPane` wording described teardown behavior but is superseded as current identity. |
| `+0x4ce` / `+1230` | `m_refreshWholeVisibleMap` | UID0003TL checks and clears this byte to force a whole extended visible-map refresh before static-object reconciliation. |
| `+0x4dc` / `+1244` | `m_mapName[256]` | UID0003TL stores converted optional packet map-name text here after copying length-prefixed ANSI bytes and calling `MultiByteToWideChar`. |
| `+0x6dc` / `+1756` | `m_mapNameLength` | UID0003TL stores the converted map-name character count here and terminates the wide string at that index. |
| `+0x6de` / `+1758` | `m_mapResourceName[256]` | UID0003TL stores converted optional resource/palette packet text here before appending `.EPF` and `.PAL` into local resource-name buffers. |
| `+0x8de` / `+2270` | `m_mapResourceNameLength` | UID0003TL stores the converted resource-name character count here and terminates the wide string at that index. |
| `+0x418` | `UserPane *m_localPlayerObjectPane` | Movement, recenter, object update, timer, and render paths use this pointer for the local player; UID0003ZS calls UserPane-only `ProcessMovement`, while inherited LivingObjectPane operations remain available. Historical `m_activeObjectPane` and `m_objectListDetachPreserve` are contextual aliases for this same offset. |

## UID0003ZT Timer-State Layout Closure - 2026-07-23

- Exact complete-object adjustment places the EventHandler facet at `MapPane+0xa0`, inherited TimerHandler facet at `MapPane+0xa4`, and canonical queued-state byte at `MapPane+0x39d`. The timer facet is inheritance layout, not an additional data member.
- UID0003ZT drains the flag before testing `Event::m_type`; UID00042F performs the same clear/cancel/release sequence; raw UID00042E/G are setters/queue paths; UID0003ZS is the timer consumer. Together they establish one bool field and reject simultaneous aliasing.
- The complete class remains exactly `0x910` bytes. This support page remains layout-only and covered by UID00007Q; no standalone duplicate MapPane declaration or source emitter is introduced.
| `+0x424` | `m_objectList` | Object create/update, remove/detach/intersect, movement collision, reindexing, and timer event `8` object-id lookup use this owned ObjectList pointer. |
| `+0x428` | `m_viewportGrafPort` | [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) opens/closes this cached viewport paint lifecycle. |
| `+0x4c8` | `m_mapFlashColor` | UID0004Q9 stores and clears this dword around two invalidate/present passes and `Sleep(100)`; UID0003TO inlines the same policy with color 143; UID00037V render code passes nonzero values to `GrafPort::SetDrawColor(int)`. |
| `+0x4cd` | `m_visibleObjectRefreshPending` | Producer `0x0050f460` sets this byte before visible-object mark/prune work; UID0004QA and UID0001B1 prune marked visible objects and clear it; UID0003TK independently tests/clears it across map-state changes. |
| `+0x8ec/+0x8f0` | pending action target tile / saved target tile coordinates | Raw timer queue helpers write this pair; [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) event `8` compares object/current coordinates against it. |
| `+0x90c/+0x90e` / `+2316/+2318` | deferred map-surface refresh dirty flags | UID0003TL uses this pair in the EPF-layout deferred surface refresh branch after updating tile records. The exact original field names remain inferred. |

## Notes

This page now records the complete `0x910` layout and canonical offset vocabulary while remaining a nonduplicating support emitter. UID00007Q owns the final header declaration and exact by-memory children own method definitions.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md)
- [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md)
- [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md)
- [UID:0004HP][MapPaneTileRecord](by-type/by-struct/MapPaneTileRecord.md)
- [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md)
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md)
- [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md)

## Changes

- 2026-07-31 Agent-B008 UID000426 support sync: canonicalized `+0x40e` as `bool m_movementStatusTagDisabled`, recorded constructor/packet-writer/inverse-reader lifecycle and exact neighbors, and historicalized generic gate/day/collision/enabled-polarity aliases without changing layout size, score, owner, or emitter.
- 2026-07-15 B005 UID0003TK accepted source-quality callback: preserved `93/94`, the exact `0x910` layout, all concurrent field evidence, and the covered-by managed formal byte-for-byte; added exact runtime/pending/map-dimension/transition/weather/movement/day-night/ObjectList/auxiliary/layer/waiting/EPF field lifecycles and historicalized only disproven aliases.

- 2026-07-15 B002 UID00037W accepted callback: raised the focused layout page to `90/92`; added exact highlighted/effect/deferred-motion/day-night tint/projection/target/overlay fields, corrected `+0x3e0` to `AlphaMaskSurface *`, historicalized duration/embedded aliases, and preserved the existing owner/emitter and layout-only covered-by formal comment.
- 2026-07-14 Agent-B005 UID00037V callback: added exact getter/render child links and synchronized `+0x3dc/+0x3e0/+0x3f0/+0x3f2/+0x418/+0x424/+0x428/+0x4c8` render roles, including the waiting-status lifecycle and superseded `m_hasRenderableMap` interpretation. Score, owner/emitter, and layout-only formal remain unchanged.
- 2026-07-14 Agent-B005 UID00037X callback: added exact interaction timer, transition/weather/layer, map-flash-color, and visible-refresh-pending rows at `+0x3f1/+0x40c/+0x40d/+0x410/+0x414/+0x4c8/+0x4cd`, with producer/consumer/inline lifecycles and superseded generic names. Score, owner/emitter, and layout-only formal remain unchanged.
- 2026-07-06 Agent-B011 UID0003TL implementation callback:
  - Historically added UID0003TL offset rows including `m_mapWidthTiles`, `m_mapHeightTiles`, and `m_mapTileRecords`. The UID0002QJ callback superseded only those three aliases with canonical `m_mapWidth`, `m_mapHeight`, and `m_tileBuffer`; the other resource/name/refresh candidates remain unchanged.
  - Linked [UID:0004HP][MapPaneTileRecord](by-type/by-struct/MapPaneTileRecord.md) as the six-byte live tile-buffer record used by UID0003TL. This page remains layout support only and does not emit a standalone MapPane class declaration.
- 2026-07-01 Agent-B002 implementation of accepted `00042H` report:
  - Updated the `+0x39e` row to include the full queue/consume/clear chain: [UID:00042H][0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer](by-memory/0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer.md) sets the byte before scheduling timer id `7`, [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) consumes it for action polling, and [UID:00042I][0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll](by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md) clears it.

## UID00042I Layout Closure - 2026-07-28

- The adjacent bytes are separate canonical state: `+0x39d bool m_queuedMapStateRefresh`, `+0x39e bool m_pendingActionPoll` in source documentation, and `+0x39f` one-byte alignment/padding. The two bools drive different timer families and must not be merged or aliased.
- UID00042H sets `+0x39e` and schedules inherited TimerHandler event 7. UID0003ZS polls the flag and `VK_LBUTTON`, calls the local-player action helper, reschedules at 500 ms while active, and calls UID00042I on release. UID00042I clears the byte and cancels event 7.
- The complete-object-to-TimerHandler conversion is fixed at `+0xa4`; it is an inherited base-facet adjustment, not a layout member. The surrounding `+0x39d` queued-map-refresh field and `+0x39f` padding are protected from the action-poll interpretation.
- IDA models `m_pendingActionPoll` as one-byte `unsigned __int8` inside the exact `0x910` MapPane UDT. Source documentation uses behavior-backed `bool`; the 2026-07-29 supervisor Gate 2B readback verified exact `NO_CHANGE`: size `0x910`, 62 members, `m_pendingActionPoll` at `+0x39e`, and all neighboring members remain unchanged.
- 2026-06-29 Agent-B004 MapPane empty-emitter callback:
  - Inserted the accepted layout-support no-code comment. No standalone struct declaration was added.
  - Evidence: this page remains offset vocabulary for [UID:00007Q][MapPane](by-class/MapPane.md) and [UID:0000L3][MapPane](by-file/MapPane.md); the class declaration container owns source emission.
- 2026-06-25 Agent-B009 implementation of accepted 0001AP report: created the focused MapPane layout support page requested by the implementation goal, limited to offsets proven by the accepted helper split and related timer/notify evidence.
