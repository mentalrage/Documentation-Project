// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LY
// Source by-file doc: by-file/NewUserShapeSelectControlPane.md
// UID:0002Q9 | by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md | Completion:94 | Confidence:95
#include "NewUserShapeSelectControlPane.h"
#include "../render/EPFTileContext.h"

namespace
{
const unsigned short kMaleBodyMode = 2;
const unsigned short kFemaleBodyMode = 6;
const unsigned char kInitialDirection = 2;
const int kShapeColumns = 5;
const int kShapeRows = 3;
const int kShapesPerPage = 15;
const int kShapeCellWidth = 80;
const int kShapeCellHeight = 132;
const unsigned short kAnimationTimerMs = 200;

int ClampShapeCell(int value, int limit)
{
    if (value < 0)
        return 0;
    if (value >= limit)
        return limit - 1;
    return value;
}
}

NewUserShapeSelectControlPane::NewUserShapeSelectControlPane(
    short initialSelectedSlot,
    bool useMaleShapeBank,
    const RectBounds *bounds,
    unsigned char controlFlags)
    : ControlPane(8, bounds),
      m_reservedShapeState(0),
      m_maxShapeIndex(static_cast<unsigned short>(
          g_pNewHumanImageLib->GetShapeCount() - 1)),
      m_bodyMode(useMaleShapeBank ? kMaleBodyMode : kFemaleBodyMode),
      m_animationFrame(0),
      m_direction(kInitialDirection),
      m_animationTick(0),
      m_reservedDrawState(0),
      m_selectedShapeSlot(initialSelectedSlot),
      m_shapePage(0),
      m_mouseTracking(false)
{
    m_controlFlags = controlFlags;
    ScheduleTimer(0, kAnimationTimerMs, 0, 0);
}

HumanImageRenderParams *
NewUserShapeSelectControlPane::BuildPreviewParams(
    HumanImageRenderParams *outParams,
    unsigned char shapeIndex) const
{
    outParams->m_statusKind = 0;
    outParams->m_compositionMode = 0;
    outParams->m_faceColor = 0;
    outParams->m_gender = (m_bodyMode != kMaleBodyMode);
    outParams->m_shapeIndex = shapeIndex;
    outParams->m_bodyId = static_cast<unsigned char>(m_bodyMode);
    outParams->m_bodyColor = 0;
    outParams->m_weaponId = 0xffff;
    outParams->m_shieldOrArrowId = 0xffff;
    return outParams;
}

void NewUserShapeSelectControlPane::AdvanceDirection()
{
    m_direction = static_cast<unsigned char>((m_direction + 1) % 4);
}

short NewUserShapeSelectControlPane::StepShapeForward()
{
    const int finalSlot = g_pNewHumanImageLib->GetShapeCount() - 2;
    if (m_selectedShapeSlot < finalSlot) {
        ++m_selectedShapeSlot;
        InvalidateBounds();
        return m_selectedShapeSlot;
    }
    if (m_selectedShapeSlot == finalSlot) {
        ++m_selectedShapeSlot;
        InvalidateBounds();
        return -1;
    }
}

short NewUserShapeSelectControlPane::StepShapeBackward()
{
    if (m_selectedShapeSlot > 1) {
        --m_selectedShapeSlot;
        InvalidateBounds();
        return m_selectedShapeSlot;
    }
    if (m_selectedShapeSlot == 1) {
        m_selectedShapeSlot = 0;
        InvalidateBounds();
        return -1;
    }
}

short NewUserShapeSelectControlPane::SelectNextPage()
{
    const int shapeCount = g_pNewHumanImageLib->GetShapeCount();
    ++m_shapePage;
    if (m_shapePage < 0)
        m_shapePage = 0;
    const short lastPage = static_cast<short>(shapeCount / kShapesPerPage);
    if (m_shapePage > lastPage)
        m_shapePage = lastPage;
    if (m_shapePage == lastPage &&
        m_selectedShapeSlot >= shapeCount % kShapesPerPage) {
        m_selectedShapeSlot = static_cast<short>(
            shapeCount - kShapesPerPage * lastPage - 1);
        if (m_selectedShapeSlot < 0)
            m_selectedShapeSlot = 0;
    }
    InvalidateBounds();
    return m_shapePage;
}

short NewUserShapeSelectControlPane::SelectPreviousPage()
{
    const int shapeCount = g_pNewHumanImageLib->GetShapeCount();
    --m_shapePage;
    if (m_shapePage < 0)
        m_shapePage = 0;
    const short lastPage = static_cast<short>(shapeCount / kShapesPerPage);
    if (m_shapePage > lastPage)
        m_shapePage = lastPage;
    if (m_shapePage == lastPage &&
        m_selectedShapeSlot > shapeCount % kShapesPerPage)
        m_selectedShapeSlot = 1;
    InvalidateBounds();
    return m_shapePage;
}

bool NewUserShapeSelectControlPane::IsSelected() const
{
    return false;
}

void NewUserShapeSelectControlPane::SetSelected(bool)
{
}

bool NewUserShapeSelectControlPane::OnTimerEvent(int timerId, int, int)
{
    if (timerId == 0) {
        m_animationFrame =
            static_cast<unsigned short>((m_animationFrame + 1) % 4);
        ++m_animationTick;
        InvalidateBounds();
        ScheduleTimer(0, kAnimationTimerMs, 0, 0);
    }
    return true;
}

bool NewUserShapeSelectControlPane::OnMouseEvent(
    const MouseEvent *event)
{
    RectBounds selectorBounds;
    InitRectBounds(&selectorBounds, 17, 6, 417, 534);
    if (PointInRect(event->mouseY, event->mouseX, &selectorBounds)) {
        const int localY = event->mouseY - 6;
        const int localX = event->mouseX - 17;
        if (event->type == MouseEvent::ButtonDown) {
            m_mouseTracking = true;
            SelectShapeAtPoint(localY, localX);
            return true;
        }
        if (event->type == MouseEvent::MouseMove && m_mouseTracking) {
            SelectShapeAtPoint(localY, localX);
            return true;
        }
    }
    if (event->type != MouseEvent::ButtonDown)
        return ControlPane::OnMouseEvent(event);
    m_mouseTracking = false;
    return true;
}

void NewUserShapeSelectControlPane::OnPaint()
{
    EPFTileContext frameContext;
    RectBounds cellBounds;
    RectBounds previewBounds;
    RectBounds measuredBounds;
    HumanImageRenderParams params;

    SetDrawColor(0);
    FillRect(&m_visibleBounds);

    int rowTop = 6;
    for (int row = 0; row < kShapeRows; ++row) {
        for (int column = 0; column < kShapeColumns; ++column) {
            const unsigned char shapeIndex =
                static_cast<unsigned char>(
                    column + kShapeColumns *
                    (row + kShapeRows * m_shapePage));
            if (shapeIndex > m_maxShapeIndex)
                continue;

            const int left = 17 + kShapeCellWidth * column;
            if (m_selectedShapeSlot == column + kShapeColumns * row) {
                InitRectBounds(&cellBounds, left, rowTop,
                               left + kShapeCellWidth,
                               rowTop + kShapeCellHeight);
                g_pEPFLib->LookupLayoutEntry(
                    L"USERPART.EPF", 0, &frameContext);
                RenderTileFrame(&frameContext,
                                &frameContext.bounds,
                                &cellBounds, 1,
                                L"USERPART.PAL", 0);
            }

            InitRectBounds(&previewBounds,
                           left + 8, rowTop + 72,
                           left + 88, rowTop + 204);
            BuildPreviewParams(&params, shapeIndex);
            g_pNewHumanImageLib->CalculateBounds(
                &params, m_direction, &measuredBounds);
            OffsetRect(&previewBounds,
                       measuredBounds.left, measuredBounds.top);
            BuildPreviewParams(&params, shapeIndex);
            g_pNewHumanImageLib->Draw(
                this, &previewBounds, &params, m_direction);
        }
        rowTop += kShapeCellHeight;
    }
}

int NewUserShapeSelectControlPane::SelectShapeAtPoint(
    int localY, int localX)
{
    const int column =
        ClampShapeCell(localX / kShapeCellWidth, kShapeColumns);
    const int row =
        ClampShapeCell(localY / kShapeCellHeight, kShapeRows);
    const int shapeIndex =
        kShapesPerPage * m_shapePage + kShapeColumns * row + column;
    if (shapeIndex >= 0 && shapeIndex <= m_maxShapeIndex)
        m_selectedShapeSlot =
            static_cast<short>(shapeIndex % kShapesPerPage);
    return InvalidateBounds();
}

// UID:00009G | by-class\NewUserShapeSelectControlPane.md | Completion:93 | Confidence:94 | Empty Emitter Marker
