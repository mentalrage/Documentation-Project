// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JZ
// Source by-file doc: by-file/IconsPane.md
// UID:00006B | by-class/IconsPane.md | Completion:92 | Confidence:94
// IconsPane declarations are emitted in IconsPane.h; exact child pages emit method definitions.
// UID:0003BN | by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:00006B][IconsPane](by-class/IconsPane.md).

// UID:0002SW | by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md | Completion:92 | Confidence:93
IconsPane::IconsPane()
    : Pane(1),
      m_showAllIcons(!g_pConfig->m_iconPaneReducedMode),
      m_selectedIconIndex(-1),
      m_isPressed(false)
{
}

// UID:00016Z | by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md | Completion:86 | Confidence:88
// IconsPaneCore is an aggregate index; exact child pages emit the IconsPane method bodies.

// UID:0002SX | by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md | Completion:92 | Confidence:94
IconsPane::~IconsPane()
{
}

// UID:0002SY | by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md | Completion:91 | Confidence:92
bool IconsPane::IsShowingAllIcons() const
{
    return m_showAllIcons;
}

// UID:0002SZ | by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md | Completion:91 | Confidence:92
void IconsPane::ShowAllIcons()
{
    if (!m_showAllIcons) {
        g_pConfig->m_iconPaneReducedMode = 0;
        m_showAllIcons = true;
        InvalidateRect(&m_bounds);
    }
}

// UID:0002T0 | by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md | Completion:91 | Confidence:92
void IconsPane::ShowReducedIcons()
{
    if (m_showAllIcons) {
        g_pConfig->m_iconPaneReducedMode = 1;
        m_showAllIcons = false;
        InvalidateRect(&m_bounds);
    }
}

// UID:0002T1 | by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md | Completion:89 | Confidence:91
void IconsPane::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds iconRect;


    SetDrawColor(0);
    m_drawMode = 0;
    SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds);

    int iconIndex = m_showAllIcons ? 0 : 6;
    int x = iconIndex * 20;

    while (x < 160) {
        int frameIndex = iconIndex;
        if (iconIndex == m_selectedIconIndex && m_isPressed) {
            frameIndex += 8;
        }

        g_pEPFLib->LookupLayoutEntry(L"ICONS.EPD", frameIndex, &tileContext);

        InitRectBounds(&iconRect, x, 0, x + 19, 14);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &iconRect,
                        0,
                        L"NPAL7.PAL",
                        0);

        x += 20;
        ++iconIndex;
    }
}

// UID:0002T2 | by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md | Completion:89 | Confidence:91
bool IconsPane::OnMouseEvent(const PaneMouseEvent *event)
{
    bool handled = false;
    const int y = event->y;
    const int x = event->x;

    switch (event->type)
    {
    case MouseEvent_Move:
        if (HasMouseCapture())
        {
            SetIconHighlight(HitTestIcon(y, x) == m_selectedIconIndex);
            handled = true;
        }
        break;

    case MouseEvent_ButtonDown:
        if (PointInRect(y, x, &m_bounds))
        {
            m_selectedIconIndex = HitTestIcon(y, x);
            if (m_selectedIconIndex != -1)
            {
                CaptureMouse();
                SetIconHighlight(true);
                handled = true;
            }
        }
        break;

    case MouseEvent_ButtonUp:
        if (HasMouseCapture())
        {
            const int hitIcon = HitTestIcon(y, x);
            if (hitIcon == m_selectedIconIndex && !g_activeMapPane->m_inputLocked)
            {
                switch (hitIcon)
                {
                case 0:
                    SwitchGeneralPurposePanelMode2WithClickSound();
                    break;

                case 1:
                    SwitchGeneralPurposePanelMode3WithClickSound();
                    break;

                case 2:
                    RequestLocalPlayerStatus(0);
                    break;

                case 3:
                    g_pCollectionData->SyncNationEntriesOrDeferredState();
                    break;

                case 4:
                    EnsureNormalBulletinSession();
                    break;

                case 5:
                    g_pCollectionData->OpenInputPaneForCurrentSayMode();
                    break;

                case 6:
                    SendOpcode43MinusOneRequest();
                    break;

                case 7:
                    OpenQuitPrompt();
                    break;

                default:
                    break;
                }
            }

            SetIconHighlight(false);
            m_selectedIconIndex = -1;
            ReleaseMouseCapture();
            handled = true;
        }
        break;

    case MouseEvent_Hover:
        if (PointInRect(y, x, &m_bounds))
        {
            const int hitIcon = HitTestIcon(y, x);
            if (hitIcon != -1)
            {
                static const unsigned short kTooltipStringIds[8] = {
                    202, 203, 204, 205, 206, 207, 208, 209
                };

                new SimpleHelpPane(
                    g_pLanguageMan->GetLocalizedString(kTooltipStringIds[hitIcon]),
                    this,
                    x,
                    y,
                    5000);
                handled = true;
            }
        }
        break;

    default:
        break;
    }

    return handled;
}

// UID:0002T3 | by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md | Completion:90 | Confidence:92
int IconsPane::HitTestIcon(int y, int x)
{
    RectBounds iconRect;

    int iconIndex = m_showAllIcons ? 0 : 6;
    int iconX = iconIndex * 20;

    while (iconX < 160) {
        InitRectBounds(&iconRect, iconX, 0, iconX + 19, 14);

        if (PointInRect(y, x, &iconRect)) {
            return iconIndex;
        }

        iconX += 20;
        ++iconIndex;
    }

    return -1;
}

// UID:0002T4 | by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md | Completion:90 | Confidence:92
void IconsPane::SetIconHighlight(bool isPressed)
{
    if (isPressed != m_isPressed) {
        RectBounds iconRect;

        int iconX = m_selectedIconIndex * 20;
        InitRectBounds(&iconRect, iconX, 0, iconX + 19, 14);
        InvalidateRect(&iconRect);

        m_isPressed = isPressed;
    }
}

// UID:00034V | by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md | Completion:87 | Confidence:91
// Compiler-generated scalar deleting destructor for IconsPane; source is IconsPane::~IconsPane().

// UID:0000R6 | by-global/g_pIconsPane.md | Completion:92 | Confidence:94
IconsPane *g_pIconsPane = NULL;
// UID:0002XU | by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md).

// UID:00022Q | by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md | Completion:88 | Confidence:90
static void __stdcall DispatchIconsPaneAction(int action)
{
    if (g_activeMapPane->m_inputLocked)
        return;

    switch (action)
    {
    case 0:
        SwitchGeneralPurposePanelMode2WithClickSound();
        break;

    case 1:
        SwitchGeneralPurposePanelMode3WithClickSound();
        break;

    case 2:
        RequestLocalPlayerStatus(0);
        break;

    case 3:
        g_pCollectionData->SyncNationEntriesOrDeferredState();
        break;

    case 4:
        EnsureNormalBulletinSession();
        break;

    case 5:
        g_pCollectionData->OpenInputPaneForCurrentSayMode();
        break;

    case 6:
        SendOpcode43MinusOneRequest();
        break;

    case 7:
        OpenQuitPrompt();
        break;

    default:
        break;
    }
}
