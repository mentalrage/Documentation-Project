// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OX
// Source by-file doc: by-file/UserCreateAppearanceControls.md
// UID:0000FR | by-class/UserShapeSelectControlPane.md | Completion:92 | Confidence:93
// UID:0002Q8 | by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md | Completion:91 | Confidence:94
namespace
{
const unsigned char kUserShapeControlType = 8;
const unsigned char kInitialShapeDirection = 2;
const unsigned short kOldUserShapeLastIndex = 9;
const unsigned short kOldUserShapeForwardEdge = 8;
const unsigned short kOldUserShapeTimerMs = 200;
const unsigned short kOldUserShapeDirectionTickLimit = 16;
const unsigned char kControlPaneVisualStateNormal = 10;
const unsigned char kShapePreviewDescriptorKind = 0x50;

const unsigned short kUserShapeSpriteIds[2][10] = {
    {2, 60, 1, 8, 34, 48, 80, 36, 3, 83},
    {33, 74, 78, 50, 91, 10, 31, 4, 7, 45},
};

int CenterLow(int outerLow, int outerHigh, int innerLow, int innerHigh)
{
    return (outerLow + outerHigh) / 2 - (innerHigh - innerLow) / 2;
}

void CenterRectInBounds(RectBounds *outRect,
                        const RectBounds &outerRect,
                        const RectBounds &sourceRect)
{
    const int sourceLeft = sourceRect.left;
    const int sourceTop = sourceRect.top;
    const int sourceRight = sourceRect.right;
    const int sourceBottom = sourceRect.bottom;
    const int width = sourceRight - sourceLeft;
    const int height = sourceBottom - sourceTop;

    outRect->left = CenterLow(outerRect.left, outerRect.right,
                              sourceLeft, sourceRight);
    outRect->top = CenterLow(outerRect.top, outerRect.bottom,
                             sourceTop, sourceBottom);
    outRect->right = outRect->left + width;
    outRect->bottom = outRect->top + height;
}
}

UserShapeSelectControlPane::UserShapeSelectControlPane(short initialShapeIndex,
                                                       bool useMaleShapeBank,
                                                       const RectBounds *bounds,
                                                       unsigned char controlFlags)
    : ControlPane(kUserShapeControlType, bounds),
      m_reservedShapeState(0),
      m_shapeIndexLimit(kOldUserShapeLastIndex),
      m_selectedShapeIndex(initialShapeIndex),
      m_shapeBank(useMaleShapeBank ? 0 : 1),
      m_animationFrame(0),
      m_direction(kInitialShapeDirection),
      m_animationTick(0),
      m_selected(false)
{
    m_controlFlags = controlFlags;

    for (int bank = 0; bank < 2; ++bank) {
        for (int index = 0; index < 10; ++index) {
            m_shapeSpriteIds[bank][index] = kUserShapeSpriteIds[bank][index];
        }
    }

    ScheduleTimer(0, kOldUserShapeTimerMs, 0, 0);
}

HumanImageRenderParams *UserShapeSelectControlPane::BuildPreviewParams(
    HumanImageRenderParams *outParams) const
{
    outParams->Reset();
    outParams->isFemale = (m_shapeBank != 0);
    outParams->shapeIndex = static_cast<unsigned char>(
        m_shapeSpriteIds[m_shapeBank][m_selectedShapeIndex]);
    outParams->bodyMode = static_cast<unsigned char>(m_shapeBank);
    outParams->paletteOrFrame = -1;
    return outParams;
}

void UserShapeSelectControlPane::SetMaleShapeBank()
{
    m_shapeBank = 0;
    InvalidateBounds();
}

void UserShapeSelectControlPane::SetFemaleShapeBank()
{
    m_shapeBank = 1;
    InvalidateBounds();
}

short UserShapeSelectControlPane::StepShapeForward()
{
    if (m_selectedShapeIndex < kOldUserShapeForwardEdge) {
        ++m_selectedShapeIndex;
        InvalidateBounds();
        return m_selectedShapeIndex;
    }

    if (m_selectedShapeIndex == kOldUserShapeForwardEdge) {
        m_selectedShapeIndex = kOldUserShapeLastIndex;
        InvalidateBounds();
        return -1;
    }
}

short UserShapeSelectControlPane::StepShapeBackward()
{
    if (m_selectedShapeIndex > 1) {
        --m_selectedShapeIndex;
        InvalidateBounds();
        return m_selectedShapeIndex;
    }

    if (m_selectedShapeIndex == 1) {
        m_selectedShapeIndex = 0;
        InvalidateBounds();
        return -1;
    }
}

bool UserShapeSelectControlPane::IsSelected() const
{
    return m_selected;
}

void UserShapeSelectControlPane::SetSelected(bool selected)
{
    if (m_selected == selected) {
        return;
    }

    m_selected = selected;
    InvalidateBounds();
}

bool UserShapeSelectControlPane::OnTimerEvent(int timerId, int, int)
{
    if (timerId == 0) {
        m_animationFrame = static_cast<unsigned short>((m_animationFrame + 1) % 4);
        ++m_animationTick;

        if (m_animationTick >= kOldUserShapeDirectionTickLimit) {
            m_animationTick = 0;
            m_direction = static_cast<unsigned short>((m_direction + 1) % 4);
        }

        InvalidateBounds();
        ScheduleTimer(0, kOldUserShapeTimerMs, 0, 0);
    }

    return true;
}

bool UserShapeSelectControlPane::OnMouseEvent(const MouseEvent *event)
{
    if (event != NULL &&
        event->type == MouseEvent::ButtonDown &&
        PointInRect(event->mouseY, event->mouseX, &m_bounds) &&
        !m_selected)
    {
        m_selected = true;
        InvalidateBounds();
    }

    return true;
}

void UserShapeSelectControlPane::OnPaint()
{
    EPFTileContext frameContext;
    RectBounds frameRect;
    RectBounds drawRect;
    HumanImageRenderParams params;

    SetDrawColor(0);
    FillRect(&m_bounds);

    if (m_selected || m_visualState != kControlPaneVisualStateNormal) {
        const wchar_t *frameResource = g_useEpfAssets == 1
            ? L"USERPART.EPF"
            : L"CAPSULE.EPD";
        const wchar_t *paletteResource = g_useEpfAssets == 1
            ? L"NEWBUTT.PAL"
            : L"NPAL3.PAL";

        g_pEPFLib->LookupLayoutEntry(frameResource, 0, &frameContext);

        const RectBounds &sourceRect = frameContext.bounds;
        CenterRectInBounds(&frameRect, m_bounds, sourceRect);

        RenderTileFrame(&frameContext, &sourceRect, &frameRect, 0, paletteResource, 0);
    }

    BuildPreviewParams(&params);
    params.kind = kShapePreviewDescriptorKind;
    g_pNewHumanImageLib->CalculateBounds(&params, m_direction, &drawRect);

    CenterRectInBounds(&drawRect, m_bounds, drawRect);

    BuildPreviewParams(&params);
    params.kind = kShapePreviewDescriptorKind;
    g_pNewHumanImageLib->Draw(this, &drawRect, &params, m_direction);
}

// UID:0004P6 | by-type/by-struct/UserCreateAppearanceControlLayouts.md | Completion:90 | Confidence:92
struct UserCreateColorSwatchItem
{
    int row;
    int colorValue;
};

// UID:0004P7 | by-memory/0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable.md | Completion:92 | Confidence:95
static const int kUserCreateColorValues[16] = {
    0, 3, 5, 7, 1, 9, 8, 10,
    11, 12, 13, 20, 26, 24, 21, 29
};

// UID:0000FL | by-class/UserHairSelectControlPane.md | Completion:91 | Confidence:93
// UID:0004OG | by-memory/0x00501150-0x005012af.UserHairSelectControlPaneConstructor.md | Completion:91 | Confidence:93
UserHairSelectControlPane::UserHairSelectControlPane(
    short selectedHair,
    unsigned char hairColor,
    unsigned char gender,
    const RectBounds *bounds,
    unsigned char controlFlags)
    : ControlPane(8, bounds),
      m_reservedState(0),
      m_selectedHair(selectedHair),
      m_gender(gender),
      m_hairColor(hairColor),
      m_mouseTracking(false),
      m_columnCount(kColumns),
      m_hitBounds(*bounds)
{
    m_controlFlags = controlFlags;
    m_hitBounds.right -= m_hitBounds.left;
    m_hitBounds.bottom -= m_hitBounds.top;
    m_hitBounds.left = 0;
    m_hitBounds.top = 0;

    m_hairPartFrames[0][0] = 2;
    m_hairPartFrames[0][1] = 60;
    m_hairPartFrames[0][2] = 1;
    m_hairPartFrames[0][3] = 8;
    m_hairPartFrames[0][4] = 34;
    m_hairPartFrames[0][5] = 48;
    m_hairPartFrames[0][6] = 80;
    m_hairPartFrames[0][7] = 36;
    m_hairPartFrames[0][8] = 3;
    m_hairPartFrames[0][9] = 83;
    m_hairPartFrames[0][10] = 0;
    m_hairPartFrames[0][11] = 15;
    m_hairPartFrames[0][12] = 17;
    m_hairPartFrames[0][13] = 24;
    m_hairPartFrames[0][14] = 49;
    m_hairPartFrames[0][15] = 71;
    m_hairPartFrames[0][16] = 51;
    m_hairPartFrames[0][17] = 59;

    m_hairPartFrames[1][0] = 33;
    m_hairPartFrames[1][1] = 74;
    m_hairPartFrames[1][2] = 78;
    m_hairPartFrames[1][3] = 50;
    m_hairPartFrames[1][4] = 91;
    m_hairPartFrames[1][5] = 10;
    m_hairPartFrames[1][6] = 31;
    m_hairPartFrames[1][7] = 4;
    m_hairPartFrames[1][8] = 7;
    m_hairPartFrames[1][9] = 45;
    m_hairPartFrames[1][10] = 5;
    m_hairPartFrames[1][11] = 13;
    m_hairPartFrames[1][12] = 25;
    m_hairPartFrames[1][13] = 54;
    m_hairPartFrames[1][14] = 65;
    m_hairPartFrames[1][15] = 80;
    m_hairPartFrames[1][16] = 52;
    m_hairPartFrames[1][17] = 58;
}

// UID:0004OH | by-memory/0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent.md | Completion:90 | Confidence:93
bool UserHairSelectControlPane::OnMouseEvent(const MouseEvent *event)
{
    if (PointInRect(event->mouseY, event->mouseX, &m_hitBounds)) {
        if (event->type == MouseEvent::LeftButtonDown) {
            m_mouseTracking = true;
        } else if (event->type != MouseEvent::Move || !m_mouseTracking) {
            return ControlPane::OnMouseEvent(event);
        }

        SelectHairAtPoint(event->mouseY, event->mouseX);
        return true;
    }

    if (event->type == MouseEvent::LeftButtonDown) {
        m_mouseTracking = false;
        return true;
    }

    return ControlPane::OnMouseEvent(event);
}

// UID:0004OI | by-memory/0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md | Completion:89 | Confidence:92
void UserHairSelectControlPane::OnPaintFrame()
{
    EPFTileContext selectionFrame;
    EPFTileContext partFrame;
    SurfaceSpriteBlitOptions options;
    RectBounds cellBounds;
    RectBounds drawBounds;

    SetDrawColor(0);
    g_pfnFillRect(this, &m_bounds);

    options.mode = 2;
    options.color = m_hairColor;
    options.flags = 0;

    for (int row = 0; row < kRows; ++row) {
        for (int column = 0; column < m_columnCount; ++column) {
            SetRect(&cellBounds,
                    column * kCellWidth,
                    row * kCellHeight,
                    (column + 1) * kCellWidth,
                    (row + 1) * kCellHeight);

            g_pNewHumanImageLib->LoadPartFrameDrawRecord(
                5,
                m_hairPartFrames[m_gender][row * m_columnCount + column],
                2,
                0,
                &partFrame);

            drawBounds.left = partFrame.bounds.left +
                              (cellBounds.left + cellBounds.right) / 2;
            drawBounds.right = partFrame.bounds.right +
                               (cellBounds.left + cellBounds.right) / 2;
            drawBounds.top = partFrame.bounds.top +
                             (cellBounds.top + cellBounds.bottom) / 2 + 60;
            drawBounds.bottom = partFrame.bounds.bottom +
                                (cellBounds.top + cellBounds.bottom) / 2 + 60;

            DLPalette *palette = g_pPaletteLib->GetSlotPalette(
                14, 0, m_hairColor >> 5);
            g_pfnBlitSprite(&partFrame,
                            &partFrame.bounds,
                            &drawBounds,
                            true,
                            palette,
                            &options);
        }
    }

    g_pEPFLib->LookupLayoutEntry(L"USERPART.EPF", 0, &selectionFrame);
    SetRect(&cellBounds,
            (m_selectedHair % m_columnCount) * kCellWidth,
            (m_selectedHair / m_columnCount) * kCellHeight,
            (m_selectedHair % m_columnCount + 1) * kCellWidth,
            (m_selectedHair / m_columnCount + 1) * kCellHeight);

    const int frameWidth = selectionFrame.bounds.right - selectionFrame.bounds.left;
    const int frameHeight = selectionFrame.bounds.bottom - selectionFrame.bounds.top;
    drawBounds.left = (cellBounds.left + cellBounds.right) / 2 - frameWidth / 2;
    drawBounds.top = (cellBounds.top + cellBounds.bottom) / 2 - frameHeight / 2;
    drawBounds.right = drawBounds.left + frameWidth;
    drawBounds.bottom = drawBounds.top + frameHeight;

    RenderTileFrame(&selectionFrame,
                    &selectionFrame.bounds,
                    &drawBounds,
                    true,
                    L"USERPART.PAL",
                    0);
}

// UID:0004OJ | by-memory/0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint.md | Completion:91 | Confidence:94
void UserHairSelectControlPane::SelectHairAtPoint(int mouseY, int mouseX)
{
    int column = mouseX / kCellWidth;
    if (column < 0)
        column = 0;
    if (column >= m_columnCount)
        column = m_columnCount - 1;

    int row = mouseY / kCellHeight;
    if (row < 0)
        row = 0;
    if (row >= kRows)
        row = kRows - 1;

    m_selectedHair = static_cast<short>(row * m_columnCount + column);
    InvalidateRect(&m_bounds);
}

// UID:0004OK | by-memory/0x00501620-0x00501631.UserHairSelectControlPaneSetMaleMode.md | Completion:92 | Confidence:95
void UserHairSelectControlPane::SetMaleMode()
{
    m_gender = 0;
    InvalidateRect(&m_bounds);
}

// UID:0004OL | by-memory/0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleMode.md | Completion:92 | Confidence:95
void UserHairSelectControlPane::SetFemaleMode()
{
    m_gender = 1;
    InvalidateRect(&m_bounds);
}

// UID:0000FJ | by-class/UserFaceSelectControlPane.md | Completion:91 | Confidence:93
// UID:0004OM | by-memory/0x00501660-0x00501783.UserFaceSelectControlPaneConstructor.md | Completion:91 | Confidence:93
UserFaceSelectControlPane::UserFaceSelectControlPane(
    short selectedFace,
    unsigned char faceColor,
    unsigned char gender,
    const RectBounds *bounds,
    unsigned char controlFlags)
    : ControlPane(8, bounds),
      m_reservedState(0),
      m_selectedFace(selectedFace),
      m_gender(gender),
      m_faceColor(faceColor),
      m_mouseTracking(false),
      m_columnCount(kColumns),
      m_hitBounds(*bounds)
{
    m_controlFlags = controlFlags;
    m_hitBounds.right -= m_hitBounds.left;
    m_hitBounds.bottom -= m_hitBounds.top;
    m_hitBounds.left = 0;
    m_hitBounds.top = 0;

    for (int bank = 0; bank < 2; ++bank)
        for (int index = 0; index < 12; ++index)
            m_facePartIds[bank][index] = static_cast<unsigned short>(index);
}

// UID:0004ON | by-memory/0x00501790-0x0050183a.UserFaceSelectControlPaneOnMouseEvent.md | Completion:90 | Confidence:93
bool UserFaceSelectControlPane::OnMouseEvent(const MouseEvent *event)
{
    if (PointInRect(event->mouseY, event->mouseX, &m_hitBounds)) {
        if (event->type == MouseEvent::LeftButtonDown) {
            m_mouseTracking = true;
        } else if (event->type != MouseEvent::Move || !m_mouseTracking) {
            return ControlPane::OnMouseEvent(event);
        }

        SelectFaceAtPoint(event->mouseY, event->mouseX);
        return true;
    }

    if (event->type == MouseEvent::LeftButtonDown) {
        m_mouseTracking = false;
        return true;
    }

    return ControlPane::OnMouseEvent(event);
}

// UID:0004OO | by-memory/0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md | Completion:89 | Confidence:92
void UserFaceSelectControlPane::OnPaintFrame()
{
    EPFTileContext selectionFrame;
    EPFTileContext partFrame;
    SurfaceSpriteBlitOptions options;
    RectBounds cellBounds;
    RectBounds drawBounds;

    SetDrawColor(0);
    g_pfnFillRect(this, &m_bounds);

    options.mode = 2;
    options.color = m_faceColor;
    options.flags = 0;

    for (int row = 0; row < kRows; ++row) {
        for (int column = 0; column < m_columnCount; ++column) {
            SetRect(&cellBounds,
                    column * kCellWidth,
                    row * kCellHeight,
                    (column + 1) * kCellWidth,
                    (row + 1) * kCellHeight);

            g_pNewHumanImageLib->LoadPartFrameDrawRecord(
                2,
                m_facePartIds[m_gender][row * m_columnCount + column],
                2,
                0,
                &partFrame);

            drawBounds.left = partFrame.bounds.left +
                              (cellBounds.left + cellBounds.right) / 2;
            drawBounds.right = partFrame.bounds.right +
                               (cellBounds.left + cellBounds.right) / 2;
            drawBounds.top = partFrame.bounds.top +
                             (cellBounds.top + cellBounds.bottom) / 2 + 60;
            drawBounds.bottom = partFrame.bounds.bottom +
                                (cellBounds.top + cellBounds.bottom) / 2 + 60;

            DLPalette *palette = g_pPaletteLib->GetSlotPalette(
                13, 0, m_faceColor >> 5);
            g_pfnBlitSprite(&partFrame,
                            &partFrame.bounds,
                            &drawBounds,
                            true,
                            palette,
                            &options);
        }
    }

    g_pEPFLib->LookupLayoutEntry(L"USERPART.EPF", 0, &selectionFrame);
    SetRect(&cellBounds,
            (m_selectedFace % m_columnCount) * kCellWidth,
            (m_selectedFace / m_columnCount) * kCellHeight,
            (m_selectedFace % m_columnCount + 1) * kCellWidth,
            (m_selectedFace / m_columnCount + 1) * kCellHeight);

    const int frameWidth = selectionFrame.bounds.right - selectionFrame.bounds.left;
    const int frameHeight = selectionFrame.bounds.bottom - selectionFrame.bounds.top;
    drawBounds.left = (cellBounds.left + cellBounds.right) / 2 - frameWidth / 2;
    drawBounds.top = (cellBounds.top + cellBounds.bottom) / 2 - frameHeight / 2;
    drawBounds.right = drawBounds.left + frameWidth;
    drawBounds.bottom = drawBounds.top + frameHeight;

    RenderTileFrame(&selectionFrame,
                    &selectionFrame.bounds,
                    &drawBounds,
                    true,
                    L"USERPART.PAL",
                    0);
}

// UID:0004OP | by-memory/0x00501a70-0x00501af2.UserFaceSelectControlPaneSelectFaceAtPoint.md | Completion:91 | Confidence:94
void UserFaceSelectControlPane::SelectFaceAtPoint(int mouseY, int mouseX)
{
    int column = mouseX / kCellWidth;
    if (column < 0)
        column = 0;
    if (column >= m_columnCount)
        column = m_columnCount - 1;

    int row = mouseY / kCellHeight;
    if (row < 0)
        row = 0;
    if (row >= kRows)
        row = kRows - 1;

    m_selectedFace = static_cast<short>(row * m_columnCount + column);
    InvalidateRect(&m_bounds);
}

// UID:0004OQ | by-memory/0x00501b00-0x00501b11.UserFaceSelectControlPaneSetMaleMode.md | Completion:92 | Confidence:95
void UserFaceSelectControlPane::SetMaleMode()
{
    m_gender = 0;
    InvalidateRect(&m_bounds);
}

// UID:0004OR | by-memory/0x00501b20-0x00501b31.UserFaceSelectControlPaneSetFemaleMode.md | Completion:92 | Confidence:95
void UserFaceSelectControlPane::SetFemaleMode()
{
    m_gender = 1;
    InvalidateRect(&m_bounds);
}

// UID:0000FH | by-class/UserCreatePreviewControlPane.md | Completion:90 | Confidence:92
// UID:0004OS | by-memory/0x00501b40-0x00501bba.UserCreatePreviewControlPaneConstructor.md | Completion:91 | Confidence:93
UserCreatePreviewControlPane::UserCreatePreviewControlPane(
    short faceFrame,
    unsigned char faceColor,
    short hairFrame,
    unsigned char hairColor,
    unsigned char gender,
    const RectBounds *bounds,
    int)
    : ControlPane(8, bounds),
      m_faceFrameBase(static_cast<unsigned short>(faceFrame + 200)),
      m_hairFrame(static_cast<unsigned short>(hairFrame)),
      m_gender(gender),
      m_direction(2),
      m_hairColor(hairColor),
      m_faceColor(faceColor),
      m_reservedState(0)
{
}

// UID:0004OT | by-memory/0x00501bc0-0x00501c58.UserCreatePreviewControlPaneBuildPreviewParams.md | Completion:91 | Confidence:93
HumanImageRenderParams *UserCreatePreviewControlPane::BuildPreviewParams(
    HumanImageRenderParams *params) const
{
    params->Reset();
    params->gender = m_gender;
    params->isFemale = (m_gender == 1);
    params->faceFrame = m_faceFrameBase;
    params->faceColor = m_faceColor;
    params->hairFrame = static_cast<unsigned char>(m_hairFrame);
    params->hairColor = m_hairColor;
    return params;
}

// UID:0004OU | by-memory/0x00501c60-0x00501d45.UserCreatePreviewControlPaneOnPaint.md | Completion:90 | Confidence:92
void UserCreatePreviewControlPane::OnPaint()
{
    HumanImageRenderParams params;
    RectBounds drawBounds;
    RectBounds imageBounds;

    SetDrawColor(0);
    g_pfnFillRect(this, &m_bounds);

    params.kind = 0x50;
    BuildPreviewParams(&params);
    SetRect(&drawBounds, 0, 0, 82, 117);
    g_pNewHumanImageLib->CalculateBounds(
        &params, m_direction, 0, 0, &imageBounds, 0, 0, true, 0);
    OffsetRectBounds(&drawBounds, imageBounds.left, imageBounds.top);
    OffsetRectBounds(&drawBounds, 15, 75);

    params.kind = 0x50;
    BuildPreviewParams(&params);
    g_pNewHumanImageLib->Draw(
        this, &drawBounds, &params, m_direction, 0, 0, 0, 0, 0, 0.0f, 0, true, 0);
}

// UID:0004OV | by-memory/0x00501d50-0x00501d74.UserCreatePreviewControlPaneAdvanceDirection.md | Completion:92 | Confidence:94
void UserCreatePreviewControlPane::AdvanceDirection()
{
    m_direction = static_cast<unsigned char>((m_direction + 1) % 4);
    InvalidateRect(&m_bounds);
}

// UID:0004OW | by-memory/0x00501d80-0x00501dbc.UserCreatePreviewControlPaneUpdatePreviewFaceHairGender.md | Completion:88 | Confidence:90
void UserCreatePreviewControlPane::UpdatePreview(
    short faceFrame, short hairFrame, unsigned char gender)
{
    m_faceFrameBase = static_cast<unsigned short>(faceFrame + 200);
    m_hairFrame = static_cast<unsigned short>(hairFrame);
    m_gender = gender;
    m_hairColor = 0;
    m_faceColor = 0;
    InvalidateRect(&m_bounds);
}

// UID:0004OX | by-memory/0x00501dc0-0x00501e05.UserCreatePreviewControlPaneUpdatePreviewFull.md | Completion:91 | Confidence:93
void UserCreatePreviewControlPane::UpdatePreview(
    short faceFrame,
    unsigned char faceColor,
    short hairFrame,
    unsigned char hairColor,
    unsigned char gender)
{
    m_faceFrameBase = static_cast<unsigned short>(faceFrame + 200);
    m_hairFrame = static_cast<unsigned short>(hairFrame);
    m_gender = gender;
    m_faceColor = faceColor;
    m_hairColor = hairColor;
    InvalidateRect(&m_bounds);
}

// UID:0000FK | by-class/UserHairColorSelectListPane.md | Completion:90 | Confidence:92
// UID:0004OY | by-memory/0x00501e10-0x00501f12.UserHairColorSelectListPaneConstructor.md | Completion:91 | Confidence:93
UserHairColorSelectListPane::UserHairColorSelectListPane(
    CreateUserDialogPane *owner)
    : ListPane(sizeof(UserCreateColorSwatchItem), 32, 32, 32, 0, true, 4),
      m_owner(owner)
{
    for (int row = 0; row < 16; ++row) {
        UserCreateColorSwatchItem item = { row, kUserCreateColorValues[row] };
        AddEntry(&item);
    }

    SetSelectedIndex(0, false);
    m_owner->SetHairColorIndex(GetSelectedColorValue());
}

// UID:0004OZ | by-memory/0x00501f20-0x00501f2f.UserHairColorSelectListPaneGetSelectedColorValue.md | Completion:88 | Confidence:91
int UserHairColorSelectListPane::GetSelectedColorValue()
{
    UserCreateColorSwatchItem *item =
        static_cast<UserCreateColorSwatchItem *>(GetSelectedItem());
    return item->colorValue;
}

// UID:0004P0 | by-memory/0x00501f30-0x00502087.UserHairColorSelectListPaneDrawItem.md | Completion:90 | Confidence:93
void UserHairColorSelectListPane::DrawItem(
    int row,
    const UserCreateColorSwatchItem *item,
    const RectBounds *bounds)
{
    RectBounds fillBounds;

    if (IsItemSelected(row)) {
        fillBounds = *bounds;
        SetMode(1);
        SetDrawColor(128);
        g_pfnFillRect(this, &fillBounds);

        fillBounds = *bounds;
        InsetRectBounds(&fillBounds, 2, 2);
        SetMode(1);
        SetDrawColor(143);
        g_pfnFillRect(this, &fillBounds);
    }

    fillBounds = *bounds;
    InsetRectBounds(&fillBounds, 3, 3);
    SetMode(1);

    UserCreateColorSwatchItem *selectedItem =
        static_cast<UserCreateColorSwatchItem *>(GetSelectedItem());
    SetPalette(g_pPaletteLib->GetSlotPalette(
        14, 0, selectedItem->colorValue / 32));
    SetDrawColor((8 * item->colorValue + 128) % 256 + 4);
    g_pfnFillRect(this, &fillBounds);
    SetPalette(NULL);
}

// UID:0004P1 | by-memory/0x00502090-0x005020c3.UserHairColorSelectListPaneOnItemSelected.md | Completion:91 | Confidence:94
void UserHairColorSelectListPane::OnItemSelected(int row, int notify)
{
    ListPane::OnItemSelected(row, notify);
    m_owner->SetHairColorIndex(GetSelectedColorValue());
}

// UID:0000FI | by-class/UserFaceColorSelectListPane.md | Completion:90 | Confidence:92
// UID:0004P2 | by-memory/0x005020d0-0x005021d2.UserFaceColorSelectListPaneConstructor.md | Completion:91 | Confidence:93
UserFaceColorSelectListPane::UserFaceColorSelectListPane(
    CreateUserDialogPane *owner)
    : ListPane(sizeof(UserCreateColorSwatchItem), 32, 32, 32, 0, true, 4),
      m_owner(owner)
{
    for (int row = 0; row < 16; ++row) {
        UserCreateColorSwatchItem item = { row, kUserCreateColorValues[row] };
        AddEntry(&item);
    }

    SetSelectedIndex(0, false);
    m_owner->SetFaceColorIndex(GetSelectedColorValue());
}

// UID:0004P3 | by-memory/0x005021e0-0x005021ef.UserFaceColorSelectListPaneGetSelectedColorValue.md | Completion:88 | Confidence:91
int UserFaceColorSelectListPane::GetSelectedColorValue()
{
    UserCreateColorSwatchItem *item =
        static_cast<UserCreateColorSwatchItem *>(GetSelectedItem());
    return item->colorValue;
}

// UID:0004P4 | by-memory/0x005021f0-0x00502347.UserFaceColorSelectListPaneDrawItem.md | Completion:90 | Confidence:93
void UserFaceColorSelectListPane::DrawItem(
    int row,
    const UserCreateColorSwatchItem *item,
    const RectBounds *bounds)
{
    RectBounds fillBounds;

    if (IsItemSelected(row)) {
        fillBounds = *bounds;
        SetMode(1);
        SetDrawColor(128);
        g_pfnFillRect(this, &fillBounds);

        fillBounds = *bounds;
        InsetRectBounds(&fillBounds, 2, 2);
        SetMode(1);
        SetDrawColor(143);
        g_pfnFillRect(this, &fillBounds);
    }

    fillBounds = *bounds;
    InsetRectBounds(&fillBounds, 3, 3);
    SetMode(1);

    UserCreateColorSwatchItem *selectedItem =
        static_cast<UserCreateColorSwatchItem *>(GetSelectedItem());
    SetPalette(g_pPaletteLib->GetSlotPalette(
        13, 0, selectedItem->colorValue / 32));
    SetDrawColor((8 * item->colorValue + 128) % 256 + 4);
    g_pfnFillRect(this, &fillBounds);
    SetPalette(NULL);
}

// UID:0004P5 | by-memory/0x00502350-0x00502383.UserFaceColorSelectListPaneOnItemSelected.md | Completion:91 | Confidence:94
void UserFaceColorSelectListPane::OnItemSelected(int row, int notify)
{
    ListPane::OnItemSelected(row, notify);
    m_owner->SetFaceColorIndex(GetSelectedColorValue());
}
