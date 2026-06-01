*** UID:0000HO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BackPane

## Status

- Confidence: strong for `BackPane`/`BackGroundPane` core ownership; medium for help-popup helpers; generated scattered helper ownership is now split out by caller evidence.
- Proposed module folder: `map/`
- Proposed source file: `map/BackPane.cpp`
- Current generated sources: `source-3/simroot_v2/class_BackPane.cpp` and `class_BackGroundPane.cpp`
- Main classes: [UID:00000S][BackPane](by-class/BackPane.md), [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- Main address doc: [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- Evidence basis: generated `simroot_v2` source, `by-memory/-report.md` Wave2 annotations, and IDA MCP boundary/decompile checks on 2026-05-24. `wave3.py` was not executed for this pass.

## File Role

`BackPane.cpp` is the base background pane module for the live game UI. It owns the root map/backdrop pane created during successful login, its EPF tile-frame context, its global singleton pointer, its bounds helper, and the asset-mode palette branch used while painting the backdrop.

`BackGroundPane` is adjacent and closely related: it is a smaller background/tile-frame pane that uses the same `Pane` plus `EPFTileContext` construction idiom and tracks two readiness flags before drawing its tile data. Its address placement immediately before `BackPane` and its matching vtable/destructor pattern make `map/BackPane.cpp` the best provisional file home.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BackGroundPane` | `0x00467510-0x004677d0` plus thunks/accessors through `0x004677c1` | Small background tile-frame pane with singleton pointer, readiness flags, paint path, and scalar deleting destructor. |
| `BackPane` | `0x00467830-0x00467b2d` | Root game backdrop pane with singleton pointer, EPF tile context, resource frame load, activate/paint/destructor methods. |
| `BackPane::GetBounds` | [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) | Tiny accessor that copies the pane/layer cached bounds; broad fan-in from UI/render code. |
| help packet display helpers | [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) | Generated as `BackPane::ShowHelpFromPacket*`; back-pane anchored because help placement reads the current back-pane bounds before allocating the popup pane. |
| runtime root-pane construction | `0x004f7d10` caller | `InitializeMainUiGraph` allocates `BackPane` as the root pane in both EPF and legacy branches. |
| globals | `g_pBackPane`, `g_pBackGroundPane`, `g_pEPFLib`, [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), `g_useEpfAssets` | Singleton and subsystem dependencies for root backdrop/frame loading. |

## Evidence Notes

- IDA confirms the contiguous core functions at `0x00467510`, `0x004675b0`, `0x004675e0`, `0x00467690`, `0x004677d0`, `0x00467830`, `0x004678f0`, `0x004679c0`, `0x004679e0`, and `0x00467a80`.
- `BackPane::BackPane` stores `g_pBackPane`, initializes an `EPFTileContext` at `this + 0xf8`, copies screen dimensions, and calls the EPF/resource layout table frame loader with the constructor resource name.
- `BackPane::OnPaint` branches on `g_useEpfAssets`: EPF mode uses `FRAME.PAL`; legacy mode uses `NPAL5.PAL`.
- `InitializeMainUiGraph_004F7D10` creates the root `BackPane` with one frame resource in EPF mode and a separate frame resource in legacy mode, then attaches map/chat/status child panes beneath it.
- `BackGroundPane::OnPaint` draws only when both state bytes at offsets `0x160` and `0x161` are set. Otherwise it clears a paint/control byte, sets a text/color state to `0x80`, and invalidates its region.

## Boundary Notes

- The generated `class_BackPane.cpp` includes scattered methods at [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md), [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md), [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md), [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md), [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md), and `0x005c2760-0x005c2930`. Only `GetBounds` and the help packet helpers currently remain BackPane-related; the other scattered rows are generated-owner caveats.
- IDA reports `0x005c2760` and `0x005c2840` as not function starts even though generated source emits scroll-animation methods there. Manual disassembly shows Swallow flight-field offsets and a raw call to `0x005c2930`, so keep them with [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), not `BackPane`.
- `0x005c2930` is an IDA-modeled [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) current-rect invalidation helper with calls from `0x005c25e2` and raw `0x005c291d`.
- `BackPane::GetBounds` at `0x004b8e00` is broad infrastructure. Keep it documented here because Wave2 already integrated it as `BackPane::GetBounds`, but expect many callers from non-map UI code.
- The three help packet display helpers have no direct code xrefs in the current IDA database, but their bodies all read `BackPane::GetBounds`, convert packet text with `MultiByteToWideChar`, close the active help popup, and construct a replacement popup anchored against the back-pane bounds.
- `0x004806d0` is not a BackPane source candidate after the 2026-05-26 IDA recheck. Its only direct caller is [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md) at `0x0048093e`; keep it with chat-height viewport layout.
- `0x00506ce0` is a MapPane/target-selection hit-test helper used by spell/item/object target input panes. Keep it with [UID:0000L3][MapPane](by-file/MapPane.md) or [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), not `BackPane`.
- `0x005388a0` is a tiny timer-start wrapper called only from MapPane packet/object setup at `0x0050eb14`. IDA MCP caller review now shows the same pointer is constructed as `EffectObjectPane` immediately before the call, so BackPane ownership is rejected and the helper is reowned to [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md).

## Ownership Notes

Keep [UID:0000L3][MapPane](by-file/MapPane.md) separate. `BackPane` is the root backdrop/container and utility bounds surface; `MapPane` owns map tiles, objects, packet dispatch, and game-world rendering.

Keep [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) and [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) separate. `BackPane` consumes those render/resource helpers but should not own tile-frame decoding.

## Cross-References

- [UID:00000S][BackPane](by-class/BackPane.md)
- [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
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
