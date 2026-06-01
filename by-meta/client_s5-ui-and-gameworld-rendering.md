*** UID:0001QQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client S5 UI And Gameworld Rendering

## Status

- Scope: live in-game UI/rendering, map panes, object panes, and rendering support needed after successful login.
- Confidence: medium; core `MapPane`, `ObjectPane`, and `BackPane` ownership is documented, but several scattered helpers still need pass-by-pass validation.

## Current Pane Layers

- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md) tracks the reusable pane/tree/event/dialog/control infrastructure below the feature panes.
- [UID:0000HO][BackPane](by-file/BackPane.md) is the root/backdrop pane created by `InitializeMainUiGraph`. It loads the background frame resource and paints with `FRAME.PAL` in EPF mode or `NPAL5.PAL` in legacy mode.
- [UID:0000L3][MapPane](by-file/MapPane.md) owns map tiles, map coordinate conversion, object indexing, input, map file load/save, weather/day-night state, and packet-driven map/object updates. The broader map system is tracked in [UID:0001QG][client_map_system](by-meta/client_map_system.md), and the observed dispatcher values are tracked in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md), [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) form the main renderable object-pane family.
- [UID:0000LE][MiniMap](by-file/MiniMap.md) owns the minimap dialog/renderer/control family. [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) builds the 768x768 map view and [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) parses cached `.mnm` data into image, symbol, and label views.
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) remain render/resource infrastructure, not pane ownership.

## Current Findings

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) owns `InitializeMainUiGraph_004F7D10`, the post-login bootstrap that builds `BackPane` first, then attaches the playfield/map pane and child UI panes under it in EPF and legacy branches.
- `BackPane::GetBounds` is a broad helper used by many UI/render classes; it should stay documented as `BackPane` infrastructure but treated carefully because broad fan-in makes ownership mistakes easy.
- `BackGroundPane` is adjacent to `BackPane` and likely belongs in `map/BackPane.cpp` as a small tile-frame background companion.
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) owns the old-layout interface visual-effect manager created by `InitializeMainUiGraph`, plus the scheduled `.EPD`/`.PAD` UI effect objects used by inventory/dialog paths.

## Screen And Cursor Root

- [UID:0000NB][ScreenPane](by-file/ScreenPane.md) owns [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) at `0x0067a7cc`; IDA confirms its constructor writes the singleton and its destructor clears it.
- [UID:0000IL][CursorManager](by-file/CursorManager.md) is a provisional helper/source view over the same root object, covering cursor switching and screen-dimension accessors used by UI placement code.
- Treat generated [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) uses as a typed alias for `g_pScreenPane` until a distinct cursor manager object is proven. A 2026-05-26 IDA MCP recheck still finds one root storage slot at `0x0067a7cc`, written by `ScreenPane::ScreenPane` and consumed by the cursor helper island.

## Dialog And Alert Infrastructure

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md) owns the shared dynamic alert classes: [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), and [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md).
- `BlueAlertPane` is the confirmed `BDFRAME.EPF` alert-frame renderer; the generated constructor text currently conflicts with IDA and is tracked as a Wave3 data issue.
- Generated `g_uiTileRenderer` references in `BlueAlertPane` are not a proven singleton. IDA shows [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) resource lookup plus shared [UID:0000OC][Surface](by-file/Surface.md) render callback dispatch.
- 2026-05-26 AlertPanes recheck anchors the shared [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) and compiler [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md). The same destructor is referenced by `AlertPane`, `BlueAlertPane`, `CopyWindow`, `QuitDialog`, and `ClanLeaveConfirmDialog` vtables.
- Feature-specific alert subclasses remain with their feature modules when their callbacks, packets, or singleton state are feature-owned.

## Tooltip And Help Overlay Infrastructure

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md) owns the generic tooltip/help overlay family: [UID:000063][HelpPane](by-class/HelpPane.md), [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md), [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md), [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), and [UID:0000G6][WillBeChangedSpellPane](by-class/WillBeChangedSpellPane.md).
- `HelpPane::SimpleHelpTextPartPane` is separate from `StaticTextControlPane2::SimpleHelpTextPartPane`; both draw styled text, but they belong to different parent classes and address neighborhoods.
- `ItemHelpPane` remains presentation/UI ownership even though it depends on item metadata, inventory state, and player data.
- 2026-05-26 HelpPanes recheck anchors the missing [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) and singleton globals [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md), [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md), and [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md).

## Cross-References

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md)
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md)
- [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md)
- [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
