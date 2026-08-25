// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JS
// Source by-file doc: by-file/Group.md
// UID:00005X | by-class/GroupListPane.md | Completion:88 | Confidence:90
#include "Group.h"
#include "../ui/panels/UserPane.h"
#include "../render/NewHumanImageLib.h"
#include "../render/PaletteLib.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include <windows.h>
#include <wchar.h>

class Event;

class GroupListPane : public TextEditPane
{
public:
    GroupListPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

// UID:0001H8 | by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md | Completion:89 | Confidence:91
GroupListPane::GroupListPane()
    : TextEditPane(145, 84, 145, 84, 0x80, 0, 0, 1, 6,
                   IsLegacyAssetMode(), 1, 0)
{
}

// UID:0001H9 | by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md | Completion:90 | Confidence:92
bool GroupListPane::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

bool GroupListPane::OnMouseEvent(Event *event)
{
    return false;
}

// UID:00005Y | by-class/GroupPane.md | Completion:85 | Confidence:87
// [UID:00005Y] no class-level C++ body.
// GroupPane behavior is documented through exact constructor/destructor/vtable child evidence;
// this class page remains the declaration/source-split audit until the final header declaration is ready.
// UID:00050R | by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md | Completion:94 | Confidence:95
void GroupPane::OnPaint()
{
    EPFTileContext background;
    DLPalette *tabPalette = g_pPaletteLib->GetPaletteByName(L"TABS.PAL");

    g_pEPFLib->LookupLayoutEntry(L"GROUP.EPF", 0, &background);
    g_pfnBlitSprite(this, &background, &background.m_bounds,
                    &m_visibleBounds, 0, tabPalette, 0);
}


// UID:00005Z | by-class/GroupPane2.md | Completion:85 | Confidence:88
// [UID:00005Z] no class-level C++ body.
// GroupPane2 behavior is documented through exact constructor/destructor/vtable child evidence;
// this class page remains the declaration/source-split audit until the final header declaration is ready.
// UID:00050S | by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md | Completion:94 | Confidence:95
void GroupPane2::OnPaint()
{
    EPFTileContext background;
    DLPalette *tabPalette = g_pPaletteLib->GetPaletteByName(L"TABS.PAL");

    g_pEPFLib->LookupLayoutEntry(L"GROUP.EPF", 0, &background);
    g_pfnBlitSprite(this, &background, &background.m_bounds,
                    &m_visibleBounds, 0, tabPalette, 0);
}


// UID:0002NK | by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md | Completion:88 | Confidence:92
// [UID:0002NK] no standalone C++ body.
// Compiler-emitted GroupPane2 vtable data is covered by the class declaration and exact virtual method pages.

// UID:000090 | by-class/NewGroupPane.md | Completion:94 | Confidence:95
// NewGroupPane method implementations are emitted by exact by-memory children.
// UID:0004YZ | by-memory/0x0056ca20-0x0056caeb.NewGroupPaneConstructor.md | Completion:90 | Confidence:93
NewGroupPane::NewGroupPane()
    : m_firstVisibleMember(0),
      m_groupMemberCount(0),
      m_scrollPane(NULL),
      m_numericGlyphs(NULL),
      m_toggleButtonState(0),
      m_expanded(false)
{
    m_numericGlyphs = LoadResourceBuffer(L"9X11FONT.BIN", 99);
    m_scrollPane = new ScrollNewGroupPane(0);
    m_scrollPane->Show();
}

// UID:0004Z0 | by-memory/0x0056caf0-0x0056cb73.NewGroupPaneDestructor.md | Completion:90 | Confidence:93
NewGroupPane::~NewGroupPane()
{
    if (m_scrollPane != NULL) {
        delete m_scrollPane;
        m_scrollPane = NULL;
    }
    if (m_numericGlyphs != NULL) {
        GetMemoryMan()->FreeBufferMemory(m_numericGlyphs);
        m_numericGlyphs = NULL;
    }
}

// UID:0004Z1 | by-memory/0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate.md | Completion:91 | Confidence:94
void NewGroupPane::OnActivate(const unsigned char *packetData)
{
    unsigned char packet[2];
    (void)packetData;

    m_firstVisibleMember = 0;
    m_groupMemberCount = g_pUserPane->m_groupMemberCount;
    packet[0] = 0x2d;
    packet[1] = 1;
    g_packetSender->QueueAndSendPacket(packet, sizeof(packet));
}

// UID:0004Z2 | by-memory/0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion.md | Completion:91 | Confidence:94
void NewGroupPane::UpdateRenderRegion(const RectBounds *bounds)
{
    RectBounds scrollBounds;

    InitRectBounds(&scrollBounds,
                   bounds->right - 20,
                   bounds->top + 60,
                   bounds->right - 7,
                   bounds->bottom - 18);
    m_scrollPane->SetBounds(&scrollBounds, NULL);
    PanelPane::UpdateRenderRegion(bounds);
    UpdateScrollRange();
}

// UID:0004Z3 | by-memory/0x0056cc80-0x0056cd25.NewGroupPaneSetBounds.md | Completion:91 | Confidence:94
void NewGroupPane::SetBounds(const RectBounds *bounds,
                             const RectBounds *previousBounds)
{
    RectBounds activeBounds;
    Point origin;
    (void)bounds;
    (void)previousBounds;

    if (m_expanded) {
        InitRectBounds(&activeBounds, 827, 79, 1021, 637);
    } else {
        InitRectBounds(&activeBounds, 832, 79, 1021, 367);
    }

    InitPoint(&origin, activeBounds.left, activeBounds.top);
    m_origin = origin;
    OffsetRect(&activeBounds, -origin.x, -origin.y);
    UpdateRenderRegion(&activeBounds);
}

// UID:0004Z4 | by-memory/0x0056cd30-0x0056ce4b.NewGroupPaneUpdateScrollRange.md | Completion:92 | Confidence:94
void NewGroupPane::UpdateScrollRange()
{
    const int visibleRows = m_expanded ? 12 : 6;
    short maxRange = static_cast<short>(m_groupMemberCount - visibleRows);
    short position = static_cast<short>(m_firstVisibleMember);

    if (maxRange < 0) maxRange = 0;
    if (maxRange > 30000) maxRange = 30000;
    if (m_scrollPane->m_scrollRange != maxRange) {
        m_scrollPane->SetMaxRange(maxRange);
    }

    if (position < 0) position = 0;
    if (position > m_groupMemberCount - visibleRows) {
        position = static_cast<short>(m_groupMemberCount - visibleRows);
    }
    if (position < 0) position = 0;
    if (position > 30000) position = 30000;

    if (m_scrollPane->m_scrollPosition != position) {
        m_scrollPane->SetScrollPosition(position);
    }
    m_firstVisibleMember = static_cast<signed char>(position);
}

// UID:0004Z5 | by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md | Completion:94 | Confidence:93
void NewGroupPane::OnPaint()
{
    EPFTileContext tileContext;
    EPFTileContext commaFrame;
    EPFTileContext barFill;
    EPFTileContext barLeftCap;
    EPFTileContext barRightCap;
    EPFTileContext scratchContext;
    RectBounds imageBounds;
    RectBounds sourceBounds;
    RectBounds destinationBounds;
    wchar_t percentText[128];
    HumanImageRenderParams appearance;

    appearance.m_displayStatusByte = 0x50;
    DLPalette *inventoryPalette = g_pPaletteLib->GetPaletteByName(L"ITEMINV.PAL");

    g_pEPFLib->LookupLayoutEntry(L"COMMA.EPF", 0, &commaFrame);
    g_pEPFLib->LookupLayoutEntry(
        m_expanded ? L"ITEMINVE.EPF" : L"GROUP.EPF",
        m_expanded ? 3 : 0, &tileContext);
    g_pfnBlitSprite(this, &tileContext, &tileContext.bounds,
                    &m_visibleBounds, 0, inventoryPalette, 0);

    RectBounds rowBounds = { 6, 14, 161, 54 };
    SetDrawMode(1);
    SetTextBackColor(0);
    const int visibleRows = m_expanded ? 12 : 6;
    int firstMember = m_groupMemberCount - 6;
    if (m_firstVisibleMember + 6 <= m_groupMemberCount)
        firstMember = m_firstVisibleMember;
    if (firstMember < 0)
        firstMember = 0;
    const int lastMember = firstMember + visibleRows < m_groupMemberCount
        ? firstMember + visibleRows : m_groupMemberCount;
    if (m_expanded)
        rowBounds.Offset(5, 0);

    for (int memberIndex = firstMember;
         memberIndex < lastMember;
         ++memberIndex, rowBounds.Offset(0, 44))
    {
        GroupMemberRecord &member =
            g_pUserPane->m_groupMembers[memberIndex];

        g_pEPFLib->LookupLayoutEntry(L"GROUPCOL.EPF", 0, &tileContext);
        RenderTileFrame(&tileContext, &tileContext.bounds, &rowBounds,
                        0, L"GROUPCOL.PAL", 0);

        appearance.m_ridingAppearanceId = 0;
        appearance.m_gender = 0;
        appearance.m_compositionMode = 0;
        appearance.m_faceId = member.faceId;
        appearance.m_hairId = member.hairId;
        appearance.m_faceColor = member.faceColor;
        appearance.m_hairColor = member.hairColor;
        appearance.m_skinColor = member.skinColor;
        appearance.m_bodyId = 0xffff;
        appearance.m_weaponId = 0xffff;
        appearance.m_bodyColor = 0;
        appearance.m_weaponColor = 0;
        appearance.m_shieldOrArrowId = 0xffff;
        appearance.m_shieldOrArrowColor = 0;
        appearance.m_helmetId = member.helmetId;
        appearance.m_helmetColor = member.helmetColor;
        appearance.m_mantleId = 0xffff;
        appearance.m_neckId = 0xffff;
        appearance.m_mantleColor = 0;
        appearance.m_neckColor = 0;
        appearance.m_shoesId = 0xffff;
        appearance.m_coatId = 0xffff;
        appearance.m_shoesColor = 0;
        appearance.m_invisible = 0;
        appearance.m_faceDecorationId = member.faceDecorationId;
        appearance.m_faceDecorationColor = member.faceDecorationColor;
        appearance.m_hairDecorationId = member.hairDecorationId;
        appearance.m_hairDecorationColor = member.hairDecorationColor;
        appearance.m_secondFaceDecorationId = member.secondFaceDecorationId;
        appearance.m_secondFaceDecorationColor = member.secondFaceDecorationColor;
        appearance.m_fullBodyId = 0xffff;

        g_pNewHumanImageLib->CalculateBounds(
            &appearance, 2, 0, 0, &imageBounds, 0, 1, true, 0);

        RectBounds memberBounds = rowBounds;
        memberBounds.top = memberBounds.bottom - 20;
        memberBounds.left = imageBounds.left + 13;
        memberBounds.right = imageBounds.left + 72;
        const int imageHeight = imageBounds.bottom - imageBounds.top;
        if (imageHeight > 40)
            memberBounds.Offset(0, -(imageHeight - 40) / 2);
        memberBounds.Offset(m_expanded ? 5 : 0, 2);

        g_pNewHumanImageLib->Draw(
            this, &memberBounds, &appearance, 2, 0, 0, 0,
            false, 0, 0.0f, 1, true, 0);

        RectBounds nameBounds = {
            rowBounds.left + 62, rowBounds.top + 6,
            rowBounds.left + 162, rowBounds.top + 20
        };
        const unsigned char nameColor = member.active ? 0x0c : 0x8f;
        SetTextColor(nameColor);
        nameBounds.Offset(-1, -2);
        DrawTextInRect(member.name, wcslen(member.name), &nameBounds);
        nameBounds.Offset(1, 0);
        DrawTextInRect(member.name, wcslen(member.name), &nameBounds);
        SetTextColor(0x8f);

        if (member.currentHitPoints != 0)
        {
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 0, &barFill);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 1, &barLeftCap);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 2, &barRightCap);

            RectBounds fullBar = {
                rowBounds.left + 64, rowBounds.top + 20,
                rowBounds.left + 149, rowBounds.top + 34
            };
            RectBounds fillBounds = fullBar;
            fillBounds.right = fullBar.right
                - (fullBar.right - fullBar.left) / 2 - 4;
            if (member.maximumHitPoints != 0)
            {
                if (member.currentHitPoints < member.maximumHitPoints)
                {
                    fillBounds.left = fillBounds.right - MulDiv(
                        fillBounds.right - fillBounds.left,
                        member.currentHitPoints,
                        member.maximumHitPoints);
                }

                sourceBounds = barFill.bounds;
                sourceBounds.left += fillBounds.left - fillBounds.right;
                RectBounds leftCapBounds = fillBounds;
                leftCapBounds.left = fillBounds.left - 3;
                leftCapBounds.right = fillBounds.left;
                RectBounds rightCapBounds = fillBounds;
                rightCapBounds.left = fillBounds.right;
                rightCapBounds.right = fillBounds.right + 3;
                RenderTileFrame(&barLeftCap, &barLeftCap.bounds,
                                &leftCapBounds, 1, L"BAR.PAL", 0);
                RenderTileFrame(&barFill, &sourceBounds, &fillBounds,
                                0, L"BAR.PAL", 0);
                RenderTileFrame(&barRightCap, &barRightCap.bounds,
                                &rightCapBounds, 1, L"BAR.PAL", 0);
            }
            else
            {
                fillBounds.left = fillBounds.right;
            }

            if (m_exposedRegion.IntersectsRect(&fillBounds))
            {
                fillBounds.Offset(-2, 3);
                swprintf_s(percentText, 128, L"%d%%",
                    static_cast<unsigned int>(
                        static_cast<double>(member.currentHitPoints) /
                        static_cast<double>(member.maximumHitPoints) * 100.0));
                fillBounds.left = fillBounds.right - 9 * wcslen(percentText);
                DrawNumberString(percentText, fillBounds.left,
                                 fillBounds.top, 2);
            }

            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 3, &barFill);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 4, &barLeftCap);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 5, &barRightCap);

            fillBounds = fullBar;
            fillBounds.left = fullBar.left
                + (fullBar.right - fullBar.left) / 2 + 4;
            if (member.maximumManaPoints != 0)
            {
                if (member.currentManaPoints < member.maximumManaPoints)
                {
                    fillBounds.left = fillBounds.right - MulDiv(
                        fillBounds.right - fillBounds.left,
                        member.currentManaPoints,
                        member.maximumManaPoints);
                }

                sourceBounds = barFill.bounds;
                sourceBounds.left += fillBounds.left - fillBounds.right;
                RectBounds leftCapBounds = fillBounds;
                leftCapBounds.left = fillBounds.left - 3;
                leftCapBounds.right = fillBounds.left;
                RectBounds rightCapBounds = fillBounds;
                rightCapBounds.left = fillBounds.right;
                rightCapBounds.right = fillBounds.right + 3;
                RenderTileFrame(&barLeftCap, &barLeftCap.bounds,
                                &leftCapBounds, 1, L"BAR.PAL", 0);
                RenderTileFrame(&barFill, &sourceBounds, &fillBounds,
                                0, L"BAR.PAL", 0);
                RenderTileFrame(&barRightCap, &barRightCap.bounds,
                                &rightCapBounds, 1, L"BAR.PAL", 0);
            }
            else
            {
                fillBounds.left = fillBounds.right;
            }

            if (m_exposedRegion.IntersectsRect(&fillBounds))
            {
                fillBounds.Offset(-2, 3);
                swprintf_s(percentText, 128, L"%d%%",
                    static_cast<unsigned int>(
                        static_cast<double>(member.currentManaPoints) /
                        static_cast<double>(member.maximumManaPoints) * 100.0));
                fillBounds.left = fillBounds.right - 9 * wcslen(percentText);
                DrawNumberString(percentText, fillBounds.left,
                                 fillBounds.top, 2);
            }
        }
    }

    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF",
        7 * m_toggleButtonState + (m_expanded ? 3 : 4), &tileContext);
    RectBounds toggleBounds;
    InitRectBounds(&toggleBounds, 168, 37, 185, 54);
    if (m_expanded)
        toggleBounds.Offset(5, 0);
    RenderTileFrame(&tileContext, &tileContext.bounds, &toggleBounds,
                    0, L"invenbut.pal", 0);
}

// UID:0003F2 | by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md | Completion:94 | Confidence:95
// [UID:0003F2] No standalone source object is emitted for these pooled literals.
// L"GROUPCOL.EPF", L"GROUPCOL.PAL", and L"%d%%" are reconstructed
// at their NewGroupPane::OnPaint use sites.

// UID:0003F8 | by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md | Completion:94 | Confidence:94
// Covered by NewGroupPane::OnPaint() local rowBounds initializer:
// RectBounds rowBounds = { 6, 14, 161, 54 };

// UID:0004Z6 | by-memory/0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent.md | Completion:90 | Confidence:93
bool NewGroupPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(event->key,
                                                              event->modifier);
    if (event->type != 8) return false;

    if (key == 0x93 && event->modifier == 0) {
        m_firstVisibleMember -= 6;
        if (m_firstVisibleMember < 0) m_firstVisibleMember = 0;
        UpdateScrollRange();
    } else if (key == 0x94 && event->modifier == 0) {
        m_firstVisibleMember += 6;
        if (m_firstVisibleMember >= m_groupMemberCount - 6) {
            m_firstVisibleMember = m_groupMemberCount - 6;
        }
        UpdateScrollRange();
    } else if (key == 'f' && event->modifier != 2) {
        ToggleExpandedMode();
        m_toggleButtonState = 0;
    } else {
        return false;
    }

    InvalidateRect(&m_visibleBounds);
    return true;
}

// UID:0004Z7 | by-memory/0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent.md | Completion:90 | Confidence:92
bool NewGroupPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->m_inputLocked) return false;

    if (event->type == 0) {
        if (!PointInRect(event->y, event->x, &m_visibleBounds)) {
            m_toggleButtonState = 0;
            return false;
        }
        RectBounds toggleBounds;
        GetGroupToggleButtonRect(6, &toggleBounds);
        m_toggleButtonState = PointInRect(event->y, event->x, &toggleBounds) ? 1 : 0;
        InvalidateRect(&m_visibleBounds);
        return true;
    }

    if (event->type == 1 && HitTestGroupToggleButton(event->y, event->x) == 6) {
        ToggleExpandedMode();
        m_toggleButtonState = 2;
        InvalidateRect(&m_visibleBounds);
    } else if (event->type == 7 &&
               PointInRect(event->y, event->x, &m_visibleBounds)) {
        short position = static_cast<short>(m_scrollPane->m_scrollPosition -
                                            event->wheelDelta);
        if (position < 0) position = 0;
        if (position > m_scrollPane->m_scrollRange) {
            position = m_scrollPane->m_scrollRange;
        }
        if (position != m_scrollPane->m_scrollPosition) {
            m_firstVisibleMember = static_cast<signed char>(position);
            m_scrollPane->SetScrollPosition(position);
            UpdateScrollRange();
            InvalidateRect(&m_visibleBounds);
        }
    }

    MapRect scrollMap;
    m_scrollPane->GetMapRect(&scrollMap);
    event->x -= scrollMap.top;
    event->y -= scrollMap.left;
    const bool handled = m_scrollPane->HandlePointerOrMouseEvent(event);
    event->x += scrollMap.top;
    event->y += scrollMap.left;
    return handled;
}

// UID:0004Z8 | by-memory/0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent.md | Completion:91 | Confidence:93
bool NewGroupPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->packetData;
    if (packet[0] != 99) return false;

    switch (packet[1]) {
    case 2:
        return ParseGroupListPacket(packet + 2);
    case 3:
        return UpdateGroupMemberStatus(packet + 2);
    default:
        return false;
    }
}

// UID:0004Z9 | by-memory/0x0056df00-0x0056df38.NewGroupPaneSetScrollPosition.md | Completion:92 | Confidence:94
void NewGroupPane::SetScrollPosition(unsigned char orientation,
                                     short oldPosition,
                                     short newPosition)
{
    (void)orientation;
    if (oldPosition == newPosition) return;

    m_firstVisibleMember = static_cast<signed char>(newPosition);
    m_scrollPane->SetScrollPosition(newPosition);
    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
}

// UID:0004ZA | by-memory/0x0056df40-0x0056dfa6.NewGroupPaneAddToLayer.md | Completion:91 | Confidence:94
void NewGroupPane::AddToLayer(RectBounds *bounds,
                              int order,
                              Pane *previousPane,
                              Layer *layer)
{
    RectBounds scrollBounds;
    Pane::AddToLayer(bounds, order, previousPane, layer);
    m_scrollPane->GetBounds(&scrollBounds);
    m_scrollPane->AddToLayer(&scrollBounds, 0, this, layer);
    UpdateScrollRange();
}

// UID:0004ZB | by-memory/0x0056dfb0-0x0056dfc6.NewGroupPaneRemoveFromLayer.md | Completion:92 | Confidence:94
void NewGroupPane::RemoveFromLayer()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:0004ZC | by-memory/0x0056dfd0-0x0056e027.GetGroupToggleButtonRect.md | Completion:92 | Confidence:94
static void __stdcall GetGroupToggleButtonRect(short part,
                                                RectBounds *bounds)
{
    if (part == 6) {
        InitRectBounds(bounds, 168, 37, 185, 54);
    } else {
        InitRectBounds(bounds, -1, -1, -1, -1);
    }
}

// UID:0004ZD | by-memory/0x0056e030-0x0056e086.GetGroupMemberRowRect.md | Completion:88 | Confidence:91
static void __stdcall GetGroupMemberRowRect(unsigned short row,
                                             RectBounds *bounds)
{
    if (row < 6) {
        InitRectBounds(bounds, 6, row * 40 + 14, 161, row * 40 + 62);
    } else {
        InitRectBounds(bounds, -1, -1, -1, -1);
    }
}

// UID:0004ZE | by-memory/0x0056e090-0x0056e126.HitTestGroupMemberRow.md | Completion:88 | Confidence:91
static short __stdcall HitTestGroupMemberRow(int y, int x)
{
    RectBounds bounds;
    for (short row = 0; row < 6; ++row) {
        InitRectBounds(&bounds, 6, row * 40 + 14, 161, row * 40 + 62);
        if (PointInRect(y, x, &bounds)) return row;
    }
    return -1;
}

// UID:0004ZF | by-memory/0x0056e130-0x0056e565.NewGroupPaneParseGroupListPacket.md | Completion:91 | Confidence:93
bool NewGroupPane::ParseGroupListPacket(const unsigned char *packetData)
{
    const unsigned char *read = packetData;
    const unsigned char memberCount = *read++;

    if (m_groupMemberCount > memberCount) {
        for (int i = 0; i < m_groupMemberCount; ++i) {
            g_activeMapPane->RemoveGroupMemberHitBar(
                g_pUserPane->m_groupMembers[i].memberId);
        }
    }

    g_pUserPane->m_groupMemberCount = memberCount;
    m_groupMemberCount = memberCount;

    for (int i = 0; i < memberCount; ++i) {
        GroupMemberRecord &member = g_pUserPane->m_groupMembers[i];
        member.memberId = PacketBufferReadUInt32BE(read); read += 4;

        const unsigned int nameLength = *read++;
        char nameBuffer[128];
        memcpy(nameBuffer, read, nameLength);
        read += nameLength;
        nameBuffer[nameLength] = 0;
        const int wideLength = MultiByteToWideChar(0, 0, nameBuffer,
                                                   nameLength, member.name, 128);
        member.name[wideLength] = 0;

        member.active = (*read++ != 0);
        member.faceId = PacketBufferReadUInt16BE(read); read += 2;
        member.hairId = *read++;
        member.hairColor = *read++;
        member.faceColor = *read++;
        member.skinColor = *read++;
        member.bodyColor = *read++;
        member.helmetId = *read++;
        member.helmetColor = *read++;
        member.faceDecorationId = PacketBufferReadUInt16BE(read); read += 2;
        member.faceDecorationColor = *read++;
        member.hairDecorationId = PacketBufferReadUInt16BE(read); read += 2;
        member.hairDecorationColor = *read++;
        member.secondFaceDecorationId = PacketBufferReadUInt16BE(read); read += 2;
        member.secondFaceDecorationColor = *read++;
        member.maximumHitPoints = PacketBufferReadUInt32BE(read); read += 4;
        member.currentHitPoints = PacketBufferReadUInt32BE(read); read += 4;
        member.maximumManaPoints = PacketBufferReadUInt32BE(read); read += 4;
        member.currentManaPoints = PacketBufferReadUInt32BE(read); read += 4;
        g_activeMapPane->RefreshGroupMemberHitBar(member.memberId);
    }

    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
    return true;
}

// UID:0004ZG | by-memory/0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus.md | Completion:88 | Confidence:91
bool NewGroupPane::UpdateGroupMemberStatus(const unsigned char *packetData)
{
    const unsigned char *read = packetData;
    const unsigned int memberId = PacketBufferReadUInt32BE(read); read += 4;
    const unsigned int nameLength = *read++;
    char nameBuffer[128];
    wchar_t wideName[128];

    memcpy(nameBuffer, read, nameLength);
    read += nameLength;
    nameBuffer[nameLength] = 0;
    const int wideLength = MultiByteToWideChar(0, 0, nameBuffer,
                                               nameLength, wideName, 128);
    wideName[wideLength] = 0;

    const unsigned int hitPoints = PacketBufferReadUInt32BE(read); read += 4;
    const unsigned int manaPoints = PacketBufferReadUInt32BE(read);
    for (int i = 0; i < m_groupMemberCount; ++i) {
        GroupMemberRecord &member = g_pUserPane->m_groupMembers[i];
        if (member.memberId == memberId) {
            member.currentHitPoints = hitPoints;
            member.currentManaPoints = manaPoints;
            g_activeMapPane->RefreshGroupMemberHitBar(memberId);
            break;
        }
    }

    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
    return true;
}

// UID:0004ZH | by-memory/0x0056e6d0-0x0056e813.NewGroupPaneDrawNumberString.md | Completion:91 | Confidence:93
void NewGroupPane::DrawNumberString(const wchar_t *text,
                                    int left,
                                    int top,
                                    unsigned char colorVariant)
{
    EPFTileContext glyph;
    EPFTileContext punctuation;
    RectBounds destination;
    EPFTileContext_Initialize(&glyph);
    EPFTileContext_Initialize(&punctuation);
    glyph.rowStridePixels = 9;
    InitRectBounds(&glyph.bounds, 0, 0, 9, 11);
    InitRectBounds(&destination, left, top, left + 9, top + 11);

    while (*text != 0) {
        int punctuationFrame = -1;
        if (*text == L'/') punctuationFrame = 0;
        else if (*text == L'%') punctuationFrame = 1;
        else if (*text == L'(') punctuationFrame = 2;
        else if (*text == L')') punctuationFrame = 3;

        if (punctuationFrame >= 0) {
            g_pEPFLib->LookupLayoutEntry(L"COMMA.EPF", punctuationFrame,
                                         &punctuation);
            RenderTileFrame(&punctuation, &punctuation.bounds,
                            &destination, true, L"COMMA.PAL", 0);
        } else if (*text != L' ') {
            glyph.pixelData = m_numericGlyphs +
                99 * (*text + 10 * colorVariant - L'/');
            RenderTileFrame(&glyph, &glyph.bounds, &destination,
                            true, NULL, 0);
        }
        ++text;
        OffsetRect(&destination, 9, 0);
    }
}

// UID:0004ZI | by-memory/0x0056e820-0x0056e8b4.HitTestGroupToggleButton.md | Completion:88 | Confidence:91
static short __stdcall HitTestGroupToggleButton(int y, int x)
{
    RectBounds bounds;
    for (short part = 0; part < 7; ++part) {
        GetGroupToggleButtonRect(part, &bounds);
        if (PointInRect(y, x, &bounds)) return part;
    }
    return -1;
}

// UID:0004ZJ | by-memory/0x0056e8c0-0x0056e939.NewGroupPaneToggleExpandedMode.md | Completion:92 | Confidence:94
void NewGroupPane::ToggleExpandedMode()
{
    RectBounds bounds;
    m_toggleButtonState = 2;
    m_expanded = !m_expanded;
    RemoveFromLayer();
    GetBounds(&bounds);
    SetBounds(&bounds, NULL);
    AddToLayer(&bounds, 0, g_pBackPane, g_activeLayer);
    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
}


// UID:0000CL | by-class/ScrollNewGroupPane.md | Completion:88 | Confidence:90
#include "../ui/core/ScrollBar.h"

// [UID:0000CL] no class-level C++ body.
// ScrollNewGroupPane method bodies are emitted by exact child by-memory pages where source-ready;
// this class page remains the ownership/declaration audit until the full class layout is ready.
// UID:00044X | by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md | Completion:88 | Confidence:90
ScrollNewGroupPane::ScrollNewGroupPane(bool horizontal)
    : Pane(true)
{
    m_scrollSkinIndex = 0;
    m_scrollStyleByte = 1;
    m_thumbDragActive = false;
    m_orientation = horizontal ? 1 : 0;
    m_scrollPosition = 0;
    m_scrollRange = 0;
    m_scrollEnabled = true;
    m_highlightPart = kScrollNewGroupPartNone;
    m_activePart = kScrollNewGroupPartNone;
    InitPointPair(&m_thumbDragOffset, 0, 0);
}

// UID:00044Y | by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md | Completion:85 | Confidence:88
// [UID:00044Y] no standalone C++ body.
// Covered by no-code proof NC-02: this raw setter is reconstructable and routed, but no function object,
// direct caller, pointer route, or source declaration proves a callable ScrollNewGroupPane API.

// UID:00044Z | by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md | Completion:85 | Confidence:87
// [UID:00044Z] no standalone C++ body.
// Covered by no-code proof NC-03: this raw setter is reconstructable and routed, but no function object,
// direct caller, pointer route, or source declaration proves a callable ScrollNewGroupPane API.

// UID:000450 | by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md | Completion:94 | Confidence:94
void ScrollNewGroupPane::SetMaxRange(short maxRange)
{
    if (maxRange < 0) {
        maxRange = 0;
    }
    if (maxRange > 30000) {
        maxRange = 30000;
    }

    if (m_scrollRange == maxRange) {
        return;
    }

    if (m_scrollPosition > maxRange) {
        m_scrollPosition = maxRange;
        InvalidateRect(&m_visibleBounds);
    }

    m_scrollRange = maxRange;
    InvalidateRect(&m_visibleBounds);
}

// UID:000451 | by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md | Completion:94 | Confidence:94
void ScrollNewGroupPane::SetScrollPosition(short position)
{
    if (m_scrollPosition == position) {
        return;
    }

    m_scrollPosition = position;
    InvalidateRect(&m_visibleBounds);
}

// UID:000452 | by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md | Completion:89 | Confidence:91
void ScrollNewGroupPane::Show()
{
    if (m_scrollEnabled) {
        return;
    }

    m_scrollEnabled = true;
    InvalidateRect(&m_bounds);
}

// UID:000453 | by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md | Completion:89 | Confidence:90
bool ScrollNewGroupPane::HandleMouseEvent(const PaneMouseEvent *event)
{
    bool handled = false;
    RectBounds rect;

    switch (event->type) {
    case kPaneMouseMove:
        if (m_activePart != kScrollNewGroupPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        return handled;

    case kPaneMouseDown:
        if (!PointInRect(event->mouseY, event->mouseX, &m_bounds)) {
            return false;
        }
        if (!m_scrollEnabled || m_scrollRange <= 0) {
            return false;
        }

        if (m_activePart == kScrollNewGroupPartNone) {
            const ScrollNewGroupPart part =
                HitTestPart(event->mouseY, event->mouseX);
            if (part != kScrollNewGroupPartNone) {
                CaptureMouse();
                BeginPartInteraction(part, event->mouseY, event->mouseX);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        return true;

    case kPaneMouseUp:
        if (m_activePart != kScrollNewGroupPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();

            const ScrollNewGroupPart oldPart =
                static_cast<ScrollNewGroupPart>(m_highlightPart);
            m_activePart =
                static_cast<signed char>(kScrollNewGroupPartNone);

            if (oldPart != kScrollNewGroupPartNone) {
                GetPartRect(oldPart, &rect);
                InvalidateRect(&rect);
                m_highlightPart =
                    static_cast<signed char>(kScrollNewGroupPartNone);
            }

            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_bounds);
        return handled;

    default:
        return false;
    }
}

// UID:000454 | by-memory/0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll.md | Completion:88 | Confidence:92
bool ScrollNewGroupPane::CanScroll(int)
{
    return false;
}

// UID:000455 | by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md | Completion:88 | Confidence:90
bool ScrollNewGroupPane::OnScrollTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollNewGroupPartNone) {
        UpdateActiveInteraction();
        ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}

// UID:000456 | by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md | Completion:88 | Confidence:90
void ScrollNewGroupPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    if (!m_scrollEnabled || m_scrollRange <= 0) {
        return;
    }

    const bool horizontal = (m_orientation != 0);
    const ScrollNewGroupPart trackParts[2] = {
        kScrollNewGroupPartPageBeforeThumb,
        kScrollNewGroupPartPageAfterThumb
    };

    for (int i = 0; i < 2; ++i) {
        const ScrollNewGroupPart part = trackParts[i];

        GetPartRect(part, &partRect);
        if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
            continue;
        }

        SetDrawColor(0);
        PreparePaneRegion(&drawRect);
        SetDrawColor(0x80);

        const int fillFrame = horizontal ? 4 : 1;
        const int capFrame = horizontal
            ? (part == kScrollNewGroupPartPageBeforeThumb ? 3 : 5)
            : (part == kScrollNewGroupPartPageBeforeThumb ? 0 : 2);

        g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", fillFrame, &tile);

        stripRect = drawRect;
        if (horizontal) {
            stripRect.right = stripRect.left + 1;
            while (stripRect.left < drawRect.right) {
                RenderTileFrame(&tile,
                                &tile.bounds,
                                &stripRect,
                                1,
                                L"SLIDEBG.PAL",
                                0);
                OffsetRect(&stripRect, 1, 0);
            }
        } else {
            stripRect.bottom = stripRect.top + 1;
            while (stripRect.top < drawRect.bottom) {
                RenderTileFrame(&tile,
                                &tile.bounds,
                                &stripRect,
                                1,
                                L"SLIDEBG.PAL",
                                0);
                OffsetRect(&stripRect, 0, 1);
            }
        }

        g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", capFrame, &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect, 1, L"SLIDEBG.PAL", 0);
    }

    GetPartRect(kScrollNewGroupPartThumb, &partRect);
    if (IntersectRects(&drawRect, &partRect, &clipRect)) {
        SetDrawColor(0);
        PreparePaneRegion(&drawRect);
        SetDrawColor(0x80);

        const int frame =
            (m_highlightPart == kScrollNewGroupPartThumb) ? 1 : 0;
        g_pEPFLib->LookupLayoutEntry(L"SCRBUTT.EPF", frame, &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect, 1, L"BUTTON.PAL", 0);
    }
}

// UID:0001GQ | by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md | Completion:88 | Confidence:90
ScrollNewGroupPart ScrollNewGroupPane::HitTestPart(int mouseY, int mouseX)
{
    for (int partValue = kScrollNewGroupPartLeading;
         partValue <= kScrollNewGroupPartTrailing;
         ++partValue) {
        const ScrollNewGroupPart part =
            static_cast<ScrollNewGroupPart>(partValue);
        Point cursor;
        Point origin;
        RectBounds rect;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);

        if (origin.x == -1000 && origin.y == -1000) {
            InitRectBounds(&rect, 0, 0, 0, 0);
        } else {
            cursor.x -= origin.x;
            cursor.y -= origin.y;
            rect = m_bounds;

            if (m_orientation == 0) {
                const int thumbSpan =
                    kScrollPanePartExtentBySkin[m_scrollSkinIndex];

                if (part == kScrollNewGroupPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollNewGroupPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackTop = m_bounds.top;
                    const int thumbLimit = m_bounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_bounds.top + cursor.y - m_thumbDragOffset.y;
                        if (thumbTop < trackTop) {
                            thumbTop = trackTop;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = trackTop +
                            ((thumbLimit - trackTop) * m_scrollPosition) /
                                m_scrollRange;
                    }

                    const int thumbBottom = thumbTop + thumbSpan;

                    if (part == kScrollNewGroupPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollNewGroupPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollNewGroupPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollNewGroupPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = m_bounds.bottom - m_bounds.top;

                if (part == kScrollNewGroupPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollNewGroupPartTrailing) {
                    rect.left = rect.right;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackLeft = m_bounds.left;
                    const int thumbLimit = m_bounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kScrollNewGroupPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollNewGroupPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollNewGroupPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollNewGroupPartThumb) {
                    rect.left += thumbSpan;
                    rect.right -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            }
        }

        if (PointInRect(mouseY, mouseX, &rect)) {
            return part;
        }
    }

    return kScrollNewGroupPartNone;
}

// UID:0001GR | by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md | Completion:89 | Confidence:91
void ScrollNewGroupPane::GetPartRect(ScrollNewGroupPart part, RectBounds *outRect)
{
    Point cursor;
    Point origin;
    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    const RectBounds bounds = m_bounds;
    if (m_orientation != 0) {
        const int thumbExtent = bounds.bottom - bounds.top;

        switch (part) {
        case kScrollNewGroupPartLeading:
            *outRect = bounds;
            outRect->right = outRect->left;
            return;

        case kScrollNewGroupPartTrailing:
            *outRect = bounds;
            outRect->left = outRect->right;
            return;

        default:
            break;
        }

        if (m_scrollEnabled && m_scrollRange > 0) {
            const int thumbLeft =
                bounds.left
                + (m_scrollPosition * (bounds.right - bounds.left - thumbExtent)) / m_scrollRange;
            const int thumbRight = thumbLeft + thumbExtent;

            *outRect = bounds;
            switch (part) {
            case kScrollNewGroupPartThumb:
                outRect->left = thumbLeft;
                outRect->right = thumbRight;
                return;

            case kScrollNewGroupPartPageBeforeThumb:
                outRect->right = thumbLeft;
                return;

            case kScrollNewGroupPartPageAfterThumb:
                outRect->left = thumbRight;
                return;

            default:
                return;
            }
        }

        if (part == kScrollNewGroupPartThumb) {
            *outRect = bounds;
            outRect->left += thumbExtent;
            outRect->right -= thumbExtent;
            return;
        }

        if (part == kScrollNewGroupPartPageBeforeThumb || part == kScrollNewGroupPartPageAfterThumb) {
            outRect->left = 0;
            outRect->top = 0;
            outRect->right = 0;
            outRect->bottom = 0;
        }
        return;
    }

    const int thumbExtent = kScrollPanePartExtentBySkin[m_scrollSkinIndex];

    switch (part) {
    case kScrollNewGroupPartLeading:
        *outRect = bounds;
        outRect->bottom = outRect->top;
        return;

    case kScrollNewGroupPartTrailing:
        *outRect = bounds;
        outRect->top = outRect->bottom;
        return;

    default:
        break;
    }

    if (m_scrollEnabled && m_scrollRange > 0) {
        const int thumbLimit = bounds.bottom - thumbExtent;
        int thumbTop;

        if (m_thumbDragActive) {
            thumbTop = bounds.top + cursor.y - m_thumbDragOffset.y;
            if (thumbTop < bounds.top) {
                thumbTop = bounds.top;
            }
            if (thumbTop > thumbLimit) {
                thumbTop = thumbLimit;
            }
        } else {
            thumbTop =
                bounds.top
                + (m_scrollPosition * (thumbLimit - bounds.top)) / m_scrollRange;
        }

        const int thumbBottom = thumbTop + thumbExtent;

        *outRect = bounds;
        switch (part) {
        case kScrollNewGroupPartThumb:
            outRect->top = thumbTop;
            outRect->bottom = thumbBottom;
            return;

        case kScrollNewGroupPartPageBeforeThumb:
            outRect->bottom = thumbTop;
            return;

        case kScrollNewGroupPartPageAfterThumb:
            outRect->top = thumbBottom;
            return;

        default:
            return;
        }
    }

    if (part == kScrollNewGroupPartThumb) {
        *outRect = bounds;
        outRect->top += thumbExtent;
        outRect->bottom -= thumbExtent;
        return;
    }

    if (part == kScrollNewGroupPartPageBeforeThumb || part == kScrollNewGroupPartPageAfterThumb) {
        outRect->left = 0;
        outRect->top = 0;
        outRect->right = 0;
        outRect->bottom = 0;
    }
}

// UID:00042L | by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md | Completion:92 | Confidence:94
void ScrollNewGroupPane::SetHighlightedPart(ScrollNewGroupPart part)
{
    RectBounds rect;
    const ScrollNewGroupPart oldPart =
        static_cast<ScrollNewGroupPart>(m_highlightPart);

    if (oldPart == part)
        return;

    if (oldPart != kScrollNewGroupPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollNewGroupPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}

// UID:00042M | by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md | Completion:88 | Confidence:90
void ScrollNewGroupPane::BeginPartInteraction(ScrollNewGroupPart part,
                                              int mouseY,
                                              int mouseX)
{
    RectBounds rect;

    if (part == kScrollNewGroupPartThumb) {
        if (m_highlightPart != kScrollNewGroupPartThumb) {
            if (m_highlightPart != kScrollNewGroupPartNone) {
                GetPartRect(static_cast<ScrollNewGroupPart>(m_highlightPart),
                            &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollNewGroupPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart =
                static_cast<signed char>(kScrollNewGroupPartThumb);
        }

        GetPartRect(kScrollNewGroupPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateActiveInteraction();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:00042N | by-memory/0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md | Completion:88 | Confidence:90
void ScrollNewGroupPane::UpdateActiveInteraction()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.x == -1000 && origin.y == -1000)
        return;

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    if (m_activePart == kScrollNewGroupPartThumb) {
        UpdateScrollPositionFromCursor(cursor.y, cursor.x);
        return;
    }

    if (HitTestPart(cursor.y, cursor.x) ==
        static_cast<ScrollNewGroupPart>(m_activePart)) {
        UpdateScrollPositionFromCursor(cursor.y, cursor.x);
    }

    if (m_highlightPart != kScrollNewGroupPartNone) {
        GetPartRect(static_cast<ScrollNewGroupPart>(m_highlightPart), &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollNewGroupPartNone);
    }
}

// UID:00042O | by-memory/0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md | Completion:88 | Confidence:90
void ScrollNewGroupPane::UpdateScrollPositionFromCursor(int mouseY,
                                                        int mouseX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    unsigned short oldPosition;
    unsigned short newPosition;
    int thumbStart;
    int maxThumbStart;
    int trackStart;
    int trackSpan;

    oldPosition = m_scrollPosition;
    GetPartRect(kScrollNewGroupPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    leadingRect = m_bounds;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    trailingRect = m_bounds;

    if (m_orientation != 0) {
        leadingRect.right = leadingRect.left;
        trailingRect.left = trailingRect.right;

        thumbStart = mouseX - m_thumbDragOffset.x + 1;
        trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.left + thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.left + thumbRect.left -
                    thumbRect.right - leadingRect.right;
        newPosition = static_cast<unsigned short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        leadingRect.bottom = leadingRect.top;
        trailingRect.top = trailingRect.bottom;

        thumbStart = mouseY - m_thumbDragOffset.y + 1;
        trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.top + thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.top + thumbRect.top -
                    thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<unsigned short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        GetOwnerPane()->SetScrollPosition(m_orientation,
                                          oldPosition,
                                          newPosition);
    }
}

// UID:00042P | by-memory/0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md | Completion:87 | Confidence:90
void ScrollNewGroupPane::ResetInteractionState()
{
    RectBounds rect;
    const ScrollNewGroupPart oldPart =
        static_cast<ScrollNewGroupPart>(m_highlightPart);

    RemovePendingTimers();
    m_activePart = static_cast<signed char>(kScrollNewGroupPartNone);

    if (oldPart != kScrollNewGroupPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollNewGroupPartNone);
    }
}

// UID:0004I3 | by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md | Completion:88 | Confidence:90
void ScrollNewGroupPane::Hide()
{
    if (!m_scrollEnabled) {
        return;
    }

    m_scrollEnabled = false;
    InvalidateRect(&m_bounds);
}

// UID:0004I5 | by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md | Completion:88 | Confidence:90
bool ScrollNewGroupPane::CanAdjust() const
{
    return m_scrollEnabled && m_scrollRange > 0;
}

// UID:0002OS | by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md | Completion:87 | Confidence:92
// [UID:0002OS] no standalone C++ body.
// Compiler-emitted ScrollNewGroupPane vtable data is covered by the class declaration and exact virtual method pages.

// UID:0001YR | by-type/by-vtable/ScrollNewGroupPaneVtables.md | Completion:85 | Confidence:91
// [UID:0001YR] no standalone C++ body.
// ScrollNewGroupPane vtable clusters are compiler-emitted data; source coverage belongs to the class declaration and virtual method pages.

// UID:0001KR | by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md | Completion:89 | Confidence:91
void RefreshGroupMemberMarkers(UserPane *userPane)
{
    for (int i = 0; i < userPane->m_groupMemberCount; ++i)
    {
        const unsigned int memberId =
            userPane->m_groupMembers[i].memberId;
        g_activeMapPane->RefreshGroupMemberHitBar(memberId);
    }
}

void ClearGroupMemberMarkers(UserPane *userPane)
{
    for (int i = 0; i < userPane->m_groupMemberCount; ++i)
    {
        const unsigned int memberId =
            userPane->m_groupMembers[i].memberId;
        g_activeMapPane->RemoveGroupMemberHitBar(memberId);
    }
}

// UID:0003F0 | by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md | Completion:94 | Confidence:95
// [UID:0003F0] No standalone source object is emitted for this pooled literal.
// L"GROUP.EPF" is reconstructed at the GroupPane::OnPaint,
// GroupPane2::OnPaint, and NewGroupPane::OnPaint use sites.

// UID:0003F6 | by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md | Completion:94 | Confidence:96
// Covered by NewGroupPane::OnPaint() HP and MP percentage expressions.

// UID:0001XP | by-type/by-vtable/GroupPaneFamilyVtables.md | Completion:90 | Confidence:94
// [UID:0001XP] no standalone C++ body.
// Group pane family vtable clusters are compiler-emitted data; source coverage belongs to the class declarations and virtual method pages.
// UID:0002NI | by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md | Completion:87 | Confidence:92
// [UID:0002NI] no standalone C++ body.
// Compiler-emitted GroupListPane vtable data is covered by the class declaration and exact virtual method pages.

// UID:0002NJ | by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md | Completion:88 | Confidence:92
// [UID:0002NJ] no standalone C++ body.
// Compiler-emitted GroupPane vtable data is covered by the class declaration and exact virtual method pages.

// UID:0002NL | by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md | Completion:91 | Confidence:95
// [UID:0002NL] no standalone C++ body.
// Compiler-emitted NewGroupPane vtable data is covered by the class declaration and exact virtual method pages.

// UID:000391 | by-memory\0x00573490-0x0057353d.GroupPaneScalarDeletingDestructor.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:000390 | by-memory\0x005733e0-0x0057348d.GroupPane2ScalarDeletingDestructor.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:00039D | by-memory\0x00573570-0x00573634.NewGroupPaneScalarDeletingDestructor.md | Completion:86 | Confidence:91 | Empty Emitter Marker
