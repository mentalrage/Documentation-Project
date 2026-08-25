// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IT
// Source by-file doc: by-file/DialogPane.md
// UID:00003T | by-class/DialogPane.md | Completion:93 | Confidence:96
#include "DialogPane.h"





// UID:0003KG | by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md | Completion:92 | Confidence:94
void DialogPane::SetBackgroundResource(const wchar_t *resourceName,
                                       short frameIndex)
{
    MemoryMan *memoryMan = GetMemoryMan();
    EPFTileContext sourceContext;

    g_pEPFLib->LookupLayoutEntry(resourceName, frameIndex, &sourceContext);

    m_backgroundTileContext.ReleaseBuffers();
    m_backgroundTileContext.pixelData = 0;
    m_backgroundTileContext.rowStridePixels = sourceContext.rowStridePixels;
    m_backgroundTileContext.bounds = sourceContext.bounds;
    m_backgroundTileContext.encodedMaskByteCount =
        sourceContext.encodedMaskByteCount;
    m_backgroundTileContext.encodedMaskBytes =
        static_cast<unsigned char *>(
            GetMemoryMan()->AllocateBufferMemory(
                m_backgroundTileContext.encodedMaskByteCount));

    memoryMan->MemmoveWrapper(
        m_backgroundTileContext.encodedMaskBytes,
        sourceContext.encodedMaskBytes,
        m_backgroundTileContext.encodedMaskByteCount);
}

// UID:0003KH | by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md | Completion:95 | Confidence:98
void DialogPane::AddControl(ControlPane *control)
{
    if (m_controlManager == NULL)
        m_controlManager = new List(sizeof(ControlPane *), 20);

    m_controlManager->Append(1, &control);
}

// UID:0003KI | by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md | Completion:92 | Confidence:93
void DialogPane::RemoveControl(ControlPane *control)
{
    const int controlIndex = FindControlIndex(control);
    if (controlIndex >= 0)
        RemoveControl(controlIndex);
}

// UID:00012T | by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md | Completion:90 | Confidence:92
void DialogPane::RemoveControl(int controlIndex)
{
    m_controlManager->RemoveAt(controlIndex, 1);
}

// UID:0003KJ | by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md | Completion:90 | Confidence:92
int DialogPane::FindControlIndex(const ControlPane *control) const
{
    if (m_controlManager == 0)
        return -1;

    const int controlCount = m_controlManager->GetCount();
    for (int index = 0; index < controlCount; ++index) {
        ControlPane *entry = *static_cast<ControlPane **>(
            m_controlManager->GetElementAt(index));
        if (entry == control)
            return index;
    }

    return -1;
}

// UID:0003KK | by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md | Completion:90 | Confidence:91
int DialogPane::GetControlCount() const
{
    List *controlManager = m_controlManager;
    if (controlManager == NULL)
        return 0;

    return controlManager->GetCount();
}



// UID:0003KN | by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md | Completion:92 | Confidence:95
void DialogPane::SetSelectionVisualState(int controlId, unsigned char visualState)
{
    if (m_selectedControlId != -1 &&
        m_selectedControlId != controlId &&
        m_selectionVisualState != 10)
    {
        GetChild<ControlPane>(m_selectedControlId)->SetVisualState(10);
    }

    m_selectedControlId = controlId;
    m_selectionVisualState = visualState;

    if (controlId != -1)
        GetChild<ControlPane>(controlId)->SetVisualState(visualState);
}

// UID:0003KO | by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md | Completion:94 | Confidence:96
void DialogPane::ActivateFocusedControl()
{
    if (m_focusedControlId == -1)
        return;

    ControlPane *focusedControl =
        GetChild<ControlPane>(m_focusedControlId);
    if (!focusedControl->IsEnabled())
        return;

    SetSelectionVisualState(m_focusedControlId, 11);
    g_pScreenPane->RenderPresentation();
    Sleep(0x85);

    if (m_selectedControlId != -1 && m_selectionVisualState != 10)
        GetChild<ControlPane>(m_selectedControlId)->SetVisualState(10);

    m_selectedControlId = -1;
    m_selectionVisualState = 10;

    g_pScreenPane->RenderPresentation();
    OnControlCommand(m_focusedControlId, 11);
}


// UID:00012U | by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md | Completion:90 | Confidence:91
void DialogPane::SlideOpenVertical()
{
    if (!CanRunSlideAnimation())
        return;

    const int height = m_bounds.bottom - m_bounds.top;

    RectBounds originalBounds;
    GetScreenBounds(&originalBounds);

    int heightOffset = height * 4;
    for (int step = 0; step < 5; ++step)
    {
        RectBounds frameBounds = originalBounds;
        const int dy = heightOffset / -5;
        OffsetRect(&frameBounds, 0, dy);
        SetBounds(&frameBounds, 0);
        OffsetPresentationRegion(0, -dy);
        g_pScreenPane->RenderPresentation();
        OffsetPresentationRegion(0, dy);
        Sleep(0x18);
        heightOffset -= height;
    }
}

void DialogPane::SlideCloseVertical()
{
    if (!CanRunSlideAnimation())
        return;

    const int height = m_bounds.bottom - m_bounds.top;

    RectBounds originalBounds;
    GetScreenBounds(&originalBounds);

    int heightOffset = height;
    for (int step = 0; step < 5; ++step)
    {
        RectBounds frameBounds = originalBounds;
        const int dy = heightOffset / -5;
        OffsetRect(&frameBounds, 0, dy);
        SetBounds(&frameBounds, 0);
        OffsetPresentationRegion(0, -dy);
        g_pScreenPane->RenderPresentation();
        OffsetPresentationRegion(0, dy);
        Sleep(0x18);
        heightOffset += height;
    }

    RectBounds frameBounds = originalBounds;
    SetBounds(&frameBounds, 0);
}

void DialogPane::SlideOpenHorizontal(unsigned char direction)
{
    if (!CanRunSlideAnimation())
        return;

    const int width = m_bounds.right - m_bounds.left;

    RectBounds originalBounds;
    GetScreenBounds(&originalBounds);

    int widthOffset = width * 4;
    for (int step = 0; step < 5; ++step)
    {
        int dx = widthOffset / 5;
        if (direction)
            dx = widthOffset / -5;

        RectBounds frameBounds = originalBounds;
        OffsetRect(&frameBounds, dx, 0);
        SetBounds(&frameBounds, 0);
        OffsetPresentationRegion(-dx, 0);
        g_pScreenPane->RenderPresentation();
        OffsetPresentationRegion(dx, 0);
        widthOffset -= width;
    }
}

void DialogPane::SlideCloseHorizontal(unsigned char direction)
{
    if (!CanRunSlideAnimation())
        return;

    const int width = m_bounds.right - m_bounds.left;

    RectBounds originalBounds;
    GetScreenBounds(&originalBounds);

    int widthOffset = width;
    for (int step = 0; step < 5; ++step)
    {
        int dx = widthOffset / 5;
        if (direction)
            dx = widthOffset / -5;

        RectBounds frameBounds = originalBounds;
        OffsetRect(&frameBounds, dx, 0);
        SetBounds(&frameBounds, 0);
        OffsetPresentationRegion(-dx, 0);
        g_pScreenPane->RenderPresentation();
        OffsetPresentationRegion(dx, 0);
        widthOffset += width;
    }

    RectBounds frameBounds = originalBounds;
    SetBounds(&frameBounds, 0);
}

void DialogPane::SlideShrink(unsigned char direction)
{
    if (!CanRunSlideAnimation())
        return;

    const int width = m_bounds.right - m_bounds.left;
    const int height = m_bounds.bottom - m_bounds.top;

    RectBounds originalBounds;
    GetScreenBounds(&originalBounds);

    int widthOffset = width * 4;
    int heightOffset = height * 4;
    for (int step = 0; step < 5; ++step)
    {
        int dx = widthOffset / 5;
        if (direction)
            dx = widthOffset / -5;
        const int dy = heightOffset / -5;

        RectBounds frameBounds = originalBounds;
        OffsetRect(&frameBounds, dx, dy);
        SetBounds(&frameBounds, 0);
        OffsetPresentationRegion(-dx, -dy);
        g_pScreenPane->RenderPresentation();
        OffsetPresentationRegion(dx, dy);
        widthOffset -= width;
        heightOffset -= height;
    }
}

void DialogPane::SlideExpand(unsigned char direction)
{
    if (!CanRunSlideAnimation())
        return;

    const int width = m_bounds.right - m_bounds.left;
    const int height = m_bounds.bottom - m_bounds.top;

    RectBounds originalBounds;
    GetScreenBounds(&originalBounds);

    int widthOffset = width;
    int heightOffset = height;
    for (int step = 0; step < 5; ++step)
    {
        int dx = widthOffset / 5;
        if (direction)
            dx = widthOffset / -5;
        const int dy = heightOffset / -5;

        RectBounds frameBounds = originalBounds;
        OffsetRect(&frameBounds, dx, dy);
        SetBounds(&frameBounds, 0);
        OffsetPresentationRegion(-dx, -dy);
        g_pScreenPane->RenderPresentation();
        OffsetPresentationRegion(dx, dy);
        widthOffset += width;
        heightOffset += height;
    }

    RectBounds frameBounds = originalBounds;
    SetBounds(&frameBounds, 0);
}

// UID:0004SW | by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md | Completion:92 | Confidence:94
void DialogPane::DrawBackground()
{
    EPFTileContext frame;

    if (g_useEpfAssets)
    {

        if (m_backgroundTileContext.encodedMaskBytes == 0)
        {
            g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 8, &frame);
            m_drawMode = 1;

            RectBounds backgroundBounds = m_bounds;
            backgroundBounds.Inset(1, 1);
            DrawTiledBackground(&backgroundBounds, &frame, L"PAL01.PAL");
            return;
        }
    }
    else
    {

        if (m_backgroundTileContext.encodedMaskBytes == 0)
        {
            g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 8, &frame);
            m_drawMode = 0;
            DrawTiledBackground(&m_bounds, &frame, L"NPAL8.PAL");
            return;
        }
    }

    SetDrawColor(0);
    FillRect(&m_bounds);
    SetDrawColor(128);
    g_pfnFillRle(this,
                 &m_backgroundTileContext,
                 &m_backgroundTileContext.bounds,
                 &m_backgroundTileContext.bounds,
                 1,
                 0);
}

// UID:0004SX | by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md | Completion:92 | Confidence:94
void DialogPane::DrawBorder()
{
    EPFTileContext frame;

    if (m_backgroundTileContext.encodedMaskBytes != 0)
        return;

    RectBounds sourceBounds;
    RectBounds originBounds;
    RectBounds destinationBounds;

    if (g_useEpfAssets)
    {
        InitRectBounds(&sourceBounds, 0, 0, 14, 14);
        InitRectBounds(&originBounds, 0, 0, 14, 14);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 14, 0);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 1, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 14, 0);
        }
        while (destinationBounds.right <
               originBounds.left + m_bounds.right - m_bounds.left);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 14,
                   m_bounds.bottom - m_bounds.top - 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 6, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 14, 0);
        }
        while (destinationBounds.right <
               originBounds.left + m_bounds.right - m_bounds.left);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 0, 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 3, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 0, 14);
        }
        while (destinationBounds.bottom <
               originBounds.top + m_bounds.bottom - m_bounds.top);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds,
                   m_bounds.right - m_bounds.left - 14, 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 4, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 0, 14);
        }
        while (destinationBounds.bottom <
               originBounds.top + m_bounds.bottom - m_bounds.top);

        destinationBounds = originBounds;
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 0, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds,
                   m_bounds.right - m_bounds.left - 14, 0);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 2, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 0,
                   m_bounds.bottom - m_bounds.top - 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 5, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds,
                   m_bounds.right - m_bounds.left - 14,
                   m_bounds.bottom - m_bounds.top - 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 7, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);
        return;
    }

    InitRectBounds(&sourceBounds, 0, 0, 16, 16);
    InitRectBounds(&originBounds, 0, 0, 16, 16);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16, 0);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 1, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 16, 0);
    }
    while (destinationBounds.right <
           originBounds.left + m_bounds.right - m_bounds.left);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16,
               m_bounds.bottom - m_bounds.top - 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 6, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 16, 0);
    }
    while (destinationBounds.right <
           originBounds.left + m_bounds.right - m_bounds.left);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0, 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 3, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 0, 16);
    }
    while (destinationBounds.bottom <
           originBounds.top + m_bounds.bottom - m_bounds.top);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds,
               m_bounds.right - m_bounds.left - 16, 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 4, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 0, 16);
    }
    while (destinationBounds.bottom <
           originBounds.top + m_bounds.bottom - m_bounds.top);

    destinationBounds = originBounds;
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 0, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds,
               m_bounds.right - m_bounds.left - 16, 0);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 2, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0,
               m_bounds.bottom - m_bounds.top - 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 5, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds,
               m_bounds.right - m_bounds.left - 16,
               m_bounds.bottom - m_bounds.top - 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 7, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);
}

// UID:0004RI | by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md | Completion:90 | Confidence:94
void DialogPane::SetHoverControl(int controlId)
{
    if (m_activeControlId != -1)
        GetChild<ControlPane>(m_activeControlId)->Deactivate();

    if (controlId != -1)
        GetChild<ControlPane>(controlId)->Activate();

    m_activeControlId = controlId;
}




// UID:0000PQ | by-global/g_activeDialogCount.md | Completion:86 | Confidence:88
signed char g_activeDialogCount;

// UID:00012R | by-memory\0x0049d8a0-0x0049feae.DialogPane.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0003KD | by-memory\0x0049dae0-0x0049db14.DialogPaneStoreClampRect.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003KE | by-memory\0x0049db20-0x0049db28.DialogPaneClearClampRectDirtyFlag.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003KF | by-memory\0x0049db30-0x0049db5d.DialogPaneSetTitleText.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003KL | by-memory\0x0049dd80-0x0049ddd0.DialogPaneSetFocusedControl.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003KM | by-memory\0x0049ddd0-0x0049ddf7.DialogPaneSetPendingControl.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003KP | by-memory\0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003AW | by-memory\0x00618a60-0x00618afc.DialogPaneVtableData.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0001U4 | by-type\by-struct\DialogPaneLayout.md | Completion:94 | Confidence:97 | Empty Emitter Marker

// UID:0003JB | by-type\by-vtable\DialogPaneVtables.md | Completion:90 | Confidence:94 | Empty Emitter Marker

// UID:0001PH | by-memory\0x0069b380-0x0069b381.g_activeDialogCount.md | Completion:88 | Confidence:91 | Empty Emitter Marker
