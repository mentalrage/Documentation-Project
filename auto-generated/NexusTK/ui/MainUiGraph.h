// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L1
// Source by-file doc: by-file/MainUiGraph.md
// UID:0004VF | by-global/g_pStatusPaneLayer.md | Completion:92 | Confidence:94
class Layer;

extern Layer *g_pStatusPaneLayer;

// UID:0004VG | by-global/g_pIMEPaneLayer.md | Completion:92 | Confidence:94
class Layer;

extern Layer *g_pIMEPaneLayer;

// UID:0000T6 | by-global/MainUiLayerSlots.md | Completion:90 | Confidence:92
#ifndef NEXUSTK_UI_MAINUIGRAPH_H
#define NEXUSTK_UI_MAINUIGRAPH_H

class Layer;

struct MainUiLayerSlots
{
    Layer *effectPaneLayerContext;
    Layer *rootPaneLayerContext;
    Layer *overlayPaneLayerContext;
};

extern MainUiLayerSlots g_mainUiLayerSlots;

#endif
