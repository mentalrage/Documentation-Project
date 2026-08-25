// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NN
// Source by-file doc: by-file/SelfSaveOKPane.md
// UID:0000CX | by-class/SelfSaveOKPane.md | Completion:94 | Confidence:95
#include "SelfSaveOKPane.h"

#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"
#include "../MainUiGraph.h"

// UID:0002OU | by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md | Completion:94 | Confidence:95
// The physical SelfSaveOKPane RTTI/COL/vtable bytes are covered by the
// SelfSaveOKPane class declaration and its virtual OnTimer override.

// UID:0003JL | by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md | Completion:94 | Confidence:95
// The pooled twelve-space UTF-16 literal is covered by L"            "
// at the SelfSaveOKPane construction use sites; no standalone array emits.

// UID:0001YV | by-type/by-vtable/SelfSaveOKPane_vtables.md | Completion:94 | Confidence:95
// SelfSaveOKPane vtables are compiler-generated from SelfSaveOKPane.h;
// no hand-authored vtable array belongs in SelfSaveOKPane.cpp.

// UID:0001AY | by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md | Completion:93 | Confidence:92
static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)
{
    (void)unusedPacket;

    new SelfSaveOKPane;
    return true;
}

// UID:0001B0 | by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md | Completion:94 | Confidence:95
SelfSaveOKPane::SelfSaveOKPane()
    : TextBoxPane(408, 12, false, 143, 1, NULL)
{
    const wchar_t *padding = L"            ";

    InsertText(padding, 0);
    InsertText(g_pLanguageMan->GetLocalizedString(61), 0);
    InsertText(padding, 0);

    RectBounds bounds;
    InitRectBounds(&bounds, 14, 456, 422, 468);
    AddToLayer(&bounds, 0, g_pBackPane,
               g_mainUiLayerSlots.rootPaneLayerContext);

    ScheduleTimer(0, 1000, 0, 0);
}

bool SelfSaveOKPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0) {
        RemoveFromLayer();
        delete this;
    }

    return true;
}
