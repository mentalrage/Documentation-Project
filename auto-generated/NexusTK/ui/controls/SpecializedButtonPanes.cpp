// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NY
// Source by-file doc: by-file/SpecializedButtonPanes.md
// UID:00005P | by-class/GenderButtonControlPane.md | Completion:94 | Confidence:95
#include "SpecializedButtonPanes.h"

#include <cwchar>

#include "../../app/StartupWindow.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"




// UID:0004ZY | by-memory/0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState.md | Completion:94 | Confidence:96
void GenderButtonControlPane::SetVisualState(unsigned char visualState)
{
    if (m_visualState != visualState && visualState == 11)
        m_stateFrameOffset = 1;

    ControlPane::SetVisualState(visualState);
}

// UID:0004ZZ | by-memory/0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md | Completion:92 | Confidence:94
void GenderButtonControlPane::OnPaint()
{
    EPFTileContext tileContext;

    RectBounds destinationBounds = m_visibleBounds;
    g_pEPFLib->LookupLayoutEntry(L"GENDER.EPF",
                                 m_genderIndex * 3 + m_stateFrameOffset,
                                 &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &destinationBounds,
                    0,
                    0,
                    0);

    if (!m_enabled)
    {
        SetDrawColor(143);
        m_drawMode = 2;
        FillRect(&m_visibleBounds);
    }
}

// UID:00003X | by-class/DirectionButtonControlPane.md | Completion:94 | Confidence:95
// UID:00050G | by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md | Completion:93 | Confidence:95
// Emitted source for this retained constructor is inline in the [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md) class declaration.

// UID:00050H | by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md | Completion:94 | Confidence:96
void DirectionButtonControlPane::SetVisualState(unsigned char visualState)
{
    if (m_visualState != visualState)
        m_stateFrameOffset = visualState == 11 ? 1 : 0;

    ControlPane::SetVisualState(visualState);
}

// UID:00050I | by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md | Completion:93 | Confidence:95
void DirectionButtonControlPane::OnPaint()
{
    EPFTileContext tileContext;

    RectBounds destinationBounds = m_visibleBounds;
    g_pEPFLib->LookupLayoutEntry(L"DIREC.EPD",
                                 m_directionIndex * 2 + m_stateFrameOffset,
                                 &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &destinationBounds,
                    1,
                    L"NPAL3.PAL",
                    0);

    if (!m_enabled)
    {
        SetDrawColor(143);
        m_drawMode = 2;
        FillRect(&m_visibleBounds);
    }
}


// UID:0003FE | by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md | Completion:93 | Confidence:95
CheckBoxTextControlPane::CheckBoxTextControlPane(
    bool checked,
    const wchar_t *label,
    const RectBounds *bounds)
    : ControlPane(8, bounds),
      m_checked(checked)
{
    wcscpy_s(m_label, 256, label);
}

// UID:0003FF | by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md | Completion:93 | Confidence:95
CheckBoxTextControlPane::~CheckBoxTextControlPane()
{
}

// UID:0003FG | by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md | Completion:93 | Confidence:95
void CheckBoxTextControlPane::OnPaint()
{
    EPFTileContext uncheckedFrame;
    EPFTileContext checkedFrame;

    g_pEPFLib->LookupLayoutEntry(L"ON", 0, &uncheckedFrame);
    g_pEPFLib->LookupLayoutEntry(L"ON", 1, &checkedFrame);

    SetDrawColor(0);
    g_pfnFillRect(this, &m_visibleBounds);
    SetTextColor(128);
    SetTextBackColor(128);
    m_textDrawMode = 1;
    SetFontId(static_cast<unsigned short>(IsLegacyAssetMode()));

    const int textLength = static_cast<int>(wcslen(m_label));
    const int textY = m_visibleBounds.top + 16;
    MoveTo(m_visibleBounds.left + 28, textY);
    DrawWideText(m_label, textLength);
    MoveTo(m_visibleBounds.left + 29, textY);
    DrawWideText(m_label, textLength);

    RectBounds destinationBounds;
    InitRectBounds(&destinationBounds, 4, 3, 24, 23);

    const EPFTileContext *frame =
        m_checked ? &checkedFrame : &uncheckedFrame;
    RenderTileFrame(frame,
                    &frame->bounds,
                    &destinationBounds,
                    0,
                    L"BU",
                    0);
}

// UID:0003FH | by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md | Completion:92 | Confidence:94
void CheckBoxTextControlPane::SetChecked(bool checked)
{
    m_checked = checked;
}

// UID:0003FI | by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md | Completion:92 | Confidence:94
bool CheckBoxTextControlPane::GetChecked() const
{
    return m_checked;
}

// UID:0002DZ | by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md | Completion:94 | Confidence:96
unsigned char CheckBoxTextControlPane::HitTestPart(int, int)
{
    return 22;
}

// UID:0004ZV | by-memory\0x00500640-0x00500690.GenderButtonControlPaneConstructor.md | Completion:93 | Confidence:95 | Empty Emitter Marker

// UID:0004ZW | by-memory\0x00500690-0x00500697.GenderButtonControlPaneIsSelected.md | Completion:94 | Confidence:96 | Empty Emitter Marker

// UID:0004ZX | by-memory\0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected.md | Completion:94 | Confidence:96 | Empty Emitter Marker

// UID:000022 | by-class\CheckBoxTextControlPane.md | Completion:95 | Confidence:96 | Empty Emitter Marker
