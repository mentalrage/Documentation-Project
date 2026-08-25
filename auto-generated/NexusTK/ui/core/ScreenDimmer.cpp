// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NA
// Source by-file doc: by-file/ScreenDimmer.md
// UID:0000C8 | by-class/ScreenDimmer.md | Completion:92 | Confidence:94
#include "ScreenDimmer.h"

// UID:000392 | by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md | Completion:93 | Confidence:94
ScreenDimmer::ScreenDimmer(unsigned char dimLevel, Pane *parentPane)
    : Pane(2),
      m_dimLevel(dimLevel)
{
    RectBounds bounds;

    if (g_useEpfAssets) {
        g_pScreenPane->GetBounds(&bounds);
        parentPane->GetBounds(&bounds);
        AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
        SetPaneOrder(NULL, NULL);

        if (parentPane != g_pScreenPane) {
            RemoveFromLayer();
            UnregisterEventHandler();
            parentPane->GetBounds(&bounds);
            AddToLayer(&bounds, 0, parentPane, g_pStatusPaneLayer);
            SetPaneOrder(NULL, parentPane);
        }
    } else {
        g_pScreenPane->GetBounds(&bounds);
        AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
        SetPaneOrder(NULL, NULL);
    }

    g_pEventDispatcher->AddToModalList(this);
}




// UID:0000S5 | by-global/g_pScreenDimmer.md | Completion:92 | Confidence:94
ScreenDimmer *g_pScreenDimmer = NULL;

// UID:00029D | by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md | Completion:92 | Confidence:94
// Exact storage for g_pScreenDimmer is represented by [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md); this range is source-declared/generated-binary storage evidence.

// UID:000393 | by-memory\0x00559cf0-0x00559dc4.ScreenDimmerDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:000394 | by-memory\0x00559dd0-0x00559e2d.ScreenDimmerOnPaint.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003EF | by-memory\0x00623480-0x00623508.ScreenDimmerVtableData.md | Completion:85 | Confidence:91 | Empty Emitter Marker

// UID:0000PJ | by-global\CreateScreenDimmer_4A12B0.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:000133 | by-memory\0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md | Completion:87 | Confidence:90 | Empty Emitter Marker
