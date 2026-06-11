*** UID:0000HO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BackPane

## Status

- Confidence: strong for `BackPane`/`BackGroundPane` core ownership, root singleton lifecycle, and source path; medium-high for help-popup helper reachability.
- Proposed module folder: `map/`
- Proposed source file: `map/BackPane.cpp`
- Historical generated source names: `class_BackPane.cpp` and `class_BackGroundPane.cpp`; use these only as search context, not as authority.
- Main classes: [UID:00000S][BackPane](by-class/BackPane.md), [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- Main address docs: historical mixed index [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md), with exact reconstructable split children [UID:00030L][0x00467510-0x0046782f.BackGroundPaneCoreMethods](by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md), [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md), and [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md).
- Evidence basis: current UID-backed project documentation plus recorded IDA MCP boundary/decompile/storage checks; older generated/Wave owner names are caveats only.

## File Role

`BackPane.cpp` is the base background pane module for the live game UI. It owns the root map/backdrop pane created during successful login, its EPF tile-frame context, its global singleton pointer, its bounds helper, and the asset-mode palette branch used while painting the backdrop.

`BackGroundPane` is adjacent and closely related: it is a smaller background/tile-frame pane that uses the same `Pane` plus `EPFTileContext` construction idiom and tracks two readiness flags before drawing its tile data. Its address placement immediately before `BackPane` and its matching vtable/destructor pattern make `map/BackPane.cpp` the best provisional file home.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BackGroundPane` | [UID:00030L][0x00467510-0x0046782f.BackGroundPaneCoreMethods](by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md) | Small background tile-frame pane with singleton pointer, readiness flags, paint path, callback, accessors, and scalar deleting destructor. |
| `BackPane` | [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) and [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) | Root game backdrop pane with singleton pointer, EPF tile context, resource frame load, activate/paint/destructor methods. The intervening `0x00467960-0x004679bf` function is the separate [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md), not BackPane source. |
| `BackPane::GetBounds` | [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) | Tiny accessor that copies the pane/layer cached bounds; broad fan-in from UI/render code. |
| help packet display helpers | [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) | Working `BackPane` help-from-packet helpers; back-pane anchored because help placement reads the current back-pane bounds before allocating the popup pane. |
| runtime root-pane construction | `0x004f7d10` caller | `InitializeMainUiGraph` allocates `BackPane` as the root pane in both EPF and legacy branches. |
| singleton/data slots | [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), [UID:0002VV][0x0067ab7c-0x0067ab80.g_pBackGroundPane](by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md) | Root `BackPane*` storage and exact `BackGroundPane *g_pBackGroundPane` storage. |
| globals/resources | `g_pEPFLib`, [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), [UID:00024U][0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData](by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md) | Subsystem dependencies plus vtable/resource literal data for root backdrop/frame loading. |

## Evidence Notes

- IDA confirms the contiguous core functions at `0x00467510`, `0x004675b0`, `0x004675e0`, `0x00467690`, `0x004677d0`, `0x00467830`, `0x004678f0`, `0x004679c0`, `0x004679e0`, and `0x00467a80`.
- A005 live IDA MCP on 2026-06-07 reconfirmed the current promoted BackPane/BackGroundPane starts and sizes, and corrected the older broad-range caveat: `0x00467960` is a separate `Application` message helper (`0x5f` bytes, caller at `0x00504a7e`), while the next non-BackPane island begins at `0x00467b30` with `BalloonObjectPane`.
- A006 Batch 105 split refresh created exact child pages for the `BackGroundPane` method cluster, the `BackPane` constructor/destructor pair, and the `BackPane` activate/paint/deleting-destructor tail. Those children carry the direct BackGroundPane/BackPane assignments, while [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md) is retained only as a reviewed mixed index around the cross-owned Application helper.
- `BackPane::BackPane` stores `g_pBackPane`, initializes an `EPFTileContext` at `this + 0xf8`, copies screen dimensions, and calls the EPF/resource layout table frame loader with the constructor resource name.
- `BackPane::OnPaint` branches on `g_useEpfAssets`: EPF mode uses `FRAME.PAL`; legacy mode uses `NPAL5.PAL`.
- `InitializeMainUiGraph_004F7D10` creates the root `BackPane` with one frame resource in EPF mode and a separate frame resource in legacy mode, then attaches map/chat/status child panes beneath it.
- `BackGroundPane::OnPaint` draws only when both state bytes at offsets `0x160` and `0x161` are set. Otherwise it clears a paint/control byte, sets a text/color state to `0x80`, and invalidates its region.
- [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md) records the exact root `BackPane*` storage, 106 xrefs, five authoritative writes, and two constructor call sites from `InitializeMainUiGraph`.
- [UID:0002VV][0x0067ab7c-0x0067ab80.g_pBackGroundPane](by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md) records the exact `BackGroundPane *g_pBackGroundPane` slot at `0x0067ab7c`, including six lifecycle xrefs, constructor/destructor/callback writes, and boundaries against application-loop and TimerMgr slots.
- [UID:00024U][0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData](by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md) records the BackGroundPane/BackPane vtable slices plus the `AME.PAL` resource literal in the read-only data island.

## Boundary Notes

- Older generated output placed scattered methods at [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md), [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md), [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md), [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md), [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md), and `0x005c2760-0x005c2930`. Only `GetBounds` and the help packet helpers currently remain BackPane-related; the other scattered rows are generated-owner caveats.
- IDA reports `0x005c2760` and `0x005c2840` as not function starts even though generated source emits scroll-animation methods there. Manual disassembly shows Swallow flight-field offsets and a raw call to `0x005c2930`, so keep them with [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), not `BackPane`.
- `0x005c2930` is an IDA-modeled [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) current-rect invalidation helper with calls from `0x005c25e2` and raw `0x005c291d`.
- `BackPane::GetBounds` at `0x004b8e00` is broad infrastructure. Keep it documented here because the current UID-backed memory page and caller behavior identify it as a back-pane bounds copy helper, but expect many callers from non-map UI code.
- The three help packet display helpers have no direct code xrefs in the current IDA database, but their bodies all read `BackPane::GetBounds`, convert packet text with `MultiByteToWideChar`, close the active help popup, and construct a replacement popup anchored against the back-pane bounds.
- `0x004806d0` is not a BackPane source candidate after the 2026-05-26 IDA recheck. Its only direct caller is [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md) at `0x0048093e`; keep it with chat-height viewport layout.
- `0x00506ce0` is a MapPane/target-selection hit-test helper used by spell/item/object target input panes. Keep it with [UID:0000L3][MapPane](by-file/MapPane.md) or [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), not `BackPane`.
- `0x005388a0` is a tiny timer-start wrapper called only from MapPane packet/object setup at `0x0050eb14`. IDA MCP caller review now shows the same pointer is constructed as `EffectObjectPane` immediately before the call, so BackPane ownership is rejected and the helper is reowned to [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md).

## Ownership Notes

Keep [UID:0000L3][MapPane](by-file/MapPane.md) separate. `BackPane` is the root backdrop/container and utility bounds surface; `MapPane` owns map tiles, objects, packet dispatch, and game-world rendering.

Keep [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) and [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) separate. `BackPane` consumes those render/resource helpers but should not own tile-frame decoding.

## Score Rationale

- Completion is raised to 86 because the file page now ties together the root/background class island, exact root singleton storage, exact background singleton storage, read-only vtable/resource data, construction from `InitializeMainUiGraph`, paint/resource behavior, and rejected generated-owner pollution.
- Confidence is raised to 88 because current project docs, recorded IDA evidence, and the split `g_pBackGroundPane` child agree on `NexusTK/map/BackPane.cpp` as the provisional source home for `BackPane` and `BackGroundPane`.
- Confidence remains below near-final because the help packet helpers still have no direct code xrefs in the current IDA database and final source declarations for the singleton globals/resources remain below the `95/95` final-source threshold.

## Cross-References

- [UID:00000S][BackPane](by-class/BackPane.md)
- [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md)
- [UID:0002VV][0x0067ab7c-0x0067ab80.g_pBackGroundPane](by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md)
- [UID:00024U][0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData](by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md)
- [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md)
- [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md)
- [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md)
- [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md)
- [UID:0001R7][backpane-background-resources](by-resource/backpane-background-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)

## Changes

- What existed before: the page documented the root back-pane module, scattered helper exclusions, and evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: core `BackPane`/`BackGroundPane` ownership is well supported by contiguous ranges and constructor/paint evidence; confidence is held below higher levels by help-helper reachability and generated-owner caveats.
- 2026-06-02 projected path update:
  - Before: the page proposed `map/BackPane.cpp` in prose but left `PROPOSED_RECONSTRUCTION_PATH` blank.
  - After: metadata now uses `NexusTK/map/`.
  - Evidence: this page's Proposed Contents and Ownership Notes already identify `map/BackPane.cpp` as the provisional source home for the root backdrop/container and adjacent `BackGroundPane`.
- 2026-06-06: Raised to `84/86`, replaced generated/Wave authority wording with current project-doc/IDA-backed evidence, added exact `g_pBackPane` storage, `g_pBackGroundPane` mixed-cluster ownership, read-only vtable/resource data, and an explicit score rationale. [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md) is now attached to this file page; manual report and validator/autogen sync remain pending while the shared files are leased.
- 2026-06-07 A005 boundary correction: updated the core `BackPane` address summary to exclude [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) from BackPane ownership. Live IDA MCP confirmed `0x00467960` as an Application message helper and `0x00467b30` as the next `BalloonObjectPane` function start.
- 2026-06-07 A006 singleton split refresh: raised from `84/86` to `86/88` after splitting exact [UID:0002VV][0x0067ab7c-0x0067ab80.g_pBackGroundPane](by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md) storage out of the mixed aggregate and attaching it here. Evidence: live IDA confirms six xrefs, all from BackGroundPane constructor/destructor/callback/clear/deleting-destructor bodies, with boundaries against application-loop and TimerMgr slots.
- 2026-06-08 A006 Batch 105 source-owner recheck: linked the exact split children [UID:00030L][0x00467510-0x0046782f.BackGroundPaneCoreMethods](by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md), [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md), and [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md). The file score remains `86/88`; the new evidence clarifies direct ownership but leaves final source layout and emitted C++ work open.
