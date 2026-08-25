// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P0
// Source by-file doc: by-file/UserLookPane.md
// UID:0000FP | by-class/UserLookPane.md | Completion:92 | Confidence:94
class Event;
class MoreInfoPane;
class ProfilePane;
class LegendPane;

extern MoreInfoPane *g_pMoreInfoPane;

class UserLookPane : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_MoreInfo = 0,
        ViewMode_Profile = 1,
        ViewMode_Bio = 2,
        ViewMode_Legend = 3
    };

    enum ActionButtonId
    {
        ActionButton_Group = 0,
        ActionButton_Exchange = 1,
        ActionButton_Previous = 2,
        ActionButton_Next = 3
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    enum ButtonFrame
    {
        ButtonFrame_Normal = 0,
        ButtonFrame_Hover = 1,
        ButtonFrame_Pressed = 2
    };

    UserLookPane();
    virtual ~UserLookPane();

    virtual void OnDraw();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool OnMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

    void GetActionButtonRect(short actionId, RectBounds *bounds) const;
    short HitTestActionButton(int y, int x) const;
    void ShowMoreInfoView();
    void ShowProfileView();
    void ShowBioView();
    void ShowLegendView();

private:
    MoreInfoPane *m_moreInfoPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_identityLine3[256];
    wchar_t m_headerText[128];
    wchar_t m_targetUserName[128];
    wchar_t m_moreInfoText[256];
    ObjectStatusBlob m_status;
    unsigned short m_bodyId;
    unsigned char m_bodyPalette;
    unsigned char m_bodyPadding;
    unsigned short m_leftHandId;
    unsigned char m_leftHandPalette;
    unsigned char m_leftHandPadding;
    unsigned short m_rightHandId;
    unsigned char m_rightHandPalette;
    unsigned char m_rightHandPadding;
    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned char m_headPadding;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned char m_rightAccessoryPadding;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned char m_leftAccessoryPadding;
    unsigned short m_faceAccessory1Id;
    unsigned short m_headAccessory2Id;
    unsigned char m_faceAccessory1Palette;
    unsigned char m_headAccessory2Palette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;
    unsigned short m_necklaceId;
    unsigned char m_necklacePalette;
    unsigned char m_necklacePadding;
    unsigned short m_footId;
    unsigned char m_footPalette;
    unsigned char m_footPadding;
    unsigned short m_coatId;
    unsigned char m_coatPalette;
    unsigned char m_coatPadding;
    unsigned short m_mantleId;
    unsigned char m_mantlePalette;
    unsigned char m_trailingProfileState;
    unsigned char m_targetNameHighlighted;
    unsigned char m_paddingB7D[3];
    unsigned int m_targetObjectId;
    unsigned char m_exchangeActionState;
    unsigned char m_groupActionState;
    unsigned char m_portraitFallbackFrame;
    unsigned char m_moreInfoLength;
    unsigned short m_portraitPayloadLength;
    unsigned char m_paddingB8A[2];
    _AUTOBUF<unsigned char> m_portraitBuffer;
    unsigned char m_profileTextLength;
    unsigned char m_paddingB99;
    wchar_t m_profileText[256];
    unsigned char m_paddingD9A[2];
    EPFTileContext m_portraitImage;
    int m_viewMode;
    unsigned char m_statusEncoding;
    unsigned char m_paddingDC9[7];
    ButtonFrame m_nextButtonFrame;
    ButtonFrame m_previousButtonFrame;
    unsigned short m_serverProfileValue;
    unsigned char m_paddingDDA[2];
};

typedef char UserLookPaneSizeMustBeDDC[
    (sizeof(UserLookPane) == 0xddc) ? 1 : -1];

// UID:0003RI | by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md | Completion:92 | Confidence:94
UserLookPane::UserLookPane()
{
    m_status.m_displayStatusByte = 0x50;

    m_moreInfoPane = new MoreInfoPane;
    g_pMoreInfoPane = m_moreInfoPane;
    m_moreInfoPane->SetMode(1);
    m_moreInfoPane->SetEditActiveState(false, false);

    m_profilePane = new ProfilePane;
    m_profilePane->SetMode(1);
    m_profilePane->SetEditActiveState(false, false);

    m_legendPane = new LegendPane;
    m_legendPane->SetMode(1);
    m_moreInfoPane->SetEditActiveState(false, false);

    m_status.m_statusKind = ObjectStatusBlob::HumanObject;
    m_status.m_appearanceId = 0;
    m_status.m_bodyId = 0;
    m_status.m_weaponId = 0;
    m_status.m_bodyColor = 0;
    m_status.m_shieldOrArrowId = 0;
    m_status.m_fullBodyId = 0;

    m_headId = 0;
    m_rightAccessoryId = 0;
    m_leftAccessoryId = 0;
    m_status.m_compositionMode = 0;

    m_identityLine2[0] = 0;
    m_identityLine1[0] = 0;
    m_headerText[0] = 0;
    m_targetUserName[0] = 0;

    m_targetObjectId = 0;
    m_portraitFallbackFrame = 0;
    m_exchangeActionState = 0xff;
    m_groupActionState = 0xff;
    m_viewMode = ViewMode_Profile;
    m_profileText[0] = 0;
    m_nextButtonFrame = ButtonFrame_Normal;
    m_previousButtonFrame = ButtonFrame_Normal;
}


// UID:0003RK | by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md | Completion:92 | Confidence:93
#include "../../render/ResourceLayoutTable.h"

namespace
{
int ReadUserLookText(const unsigned char *packetData,
                     int &offset,
                     wchar_t *text,
                     int capacity)
{
    unsigned char byteCount = packetData[offset++];
    int length = MultiByteToWideChar(CP_ACP,
                                     0,
                                     reinterpret_cast<const char *>(packetData + offset),
                                     byteCount,
                                     text,
                                     capacity - 1);
    text[length] = 0;
    offset += byteCount;
    return length;
}

void SkipUserLookText(const unsigned char *packetData, int &offset)
{
    offset += packetData[offset] + 1;
}

void ReadUserLookEquipmentRecord(const unsigned char *packetData,
                                 int &offset,
                                 unsigned short &itemId,
                                 unsigned char &palette)
{
    itemId = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    palette = packetData[offset++];
    SkipUserLookText(packetData, offset);
    SkipUserLookText(packetData, offset);
    offset += 6;
}
}

void UserLookPane::OnActivate(const unsigned char *packetData)
{
    int offset = 1;
    wchar_t identityLine1[256];
    wchar_t identityLine2[256];
    wchar_t headerText[256];
    wchar_t targetUserName[256];
    ObjectStatusBlob status;

    ReadUserLookText(packetData, offset, identityLine1, 256);
    ReadUserLookText(packetData, offset, identityLine2, 256);
    ReadUserLookText(packetData, offset, m_identityLine3, 256);
    ReadUserLookText(packetData, offset, headerText, 256);
    ReadUserLookText(packetData, offset, targetUserName, 256);

    m_statusEncoding = packetData[offset++];
    int statusLength = 0;
    if (m_statusEncoding == 0)
        statusLength = status.ParseFullStatus(packetData + offset);
    else if (m_statusEncoding == 1)
        statusLength = status.ParsePartialStatus(packetData + offset);
    offset += statusLength;

    unsigned short bodyId, leftHandId, rightHandId, headId;
    unsigned short rightAccessoryId, leftAccessoryId;
    unsigned short faceAccessory1Id, headAccessory2Id;
    unsigned short leftSubAccessoryId, rightSubAccessoryId;
    unsigned short necklaceId, footId, coatId, mantleId;
    unsigned char bodyPalette, leftHandPalette, rightHandPalette, headPalette;
    unsigned char rightAccessoryPalette, leftAccessoryPalette;
    unsigned char faceAccessory1Palette, headAccessory2Palette;
    unsigned char leftSubAccessoryPalette, rightSubAccessoryPalette;
    unsigned char necklacePalette, footPalette, coatPalette, mantlePalette;

    ReadUserLookEquipmentRecord(packetData, offset, bodyId, bodyPalette);
    ReadUserLookEquipmentRecord(packetData, offset, leftHandId, leftHandPalette);
    ReadUserLookEquipmentRecord(packetData, offset, rightHandId, rightHandPalette);
    ReadUserLookEquipmentRecord(packetData, offset, headId, headPalette);
    ReadUserLookEquipmentRecord(packetData, offset, rightAccessoryId, rightAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, leftAccessoryId, leftAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, faceAccessory1Id, faceAccessory1Palette);
    ReadUserLookEquipmentRecord(packetData, offset, headAccessory2Id, headAccessory2Palette);
    ReadUserLookEquipmentRecord(packetData, offset, leftSubAccessoryId, leftSubAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, rightSubAccessoryId, rightSubAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, necklaceId, necklacePalette);
    ReadUserLookEquipmentRecord(packetData, offset, footId, footPalette);
    ReadUserLookEquipmentRecord(packetData, offset, coatId, coatPalette);
    ReadUserLookEquipmentRecord(packetData, offset, mantleId, mantlePalette);

    m_moreInfoLength = static_cast<unsigned char>(
        ReadUserLookText(packetData, offset, m_moreInfoText, 256));
    for (int i = 0; i < m_moreInfoLength; ++i)
    {
        if (m_moreInfoText[i] == L'\t')
            m_moreInfoText[i] = L'\r';
    }

    m_moreInfoPane->SetSelectionRange(0, 0x7fff);
    m_moreInfoPane->SetText(m_moreInfoText, m_moreInfoLength, 0, 0);
    m_moreInfoPane->SetSelectionRange(0, 0);

    m_targetObjectId = PacketBufferReadUInt32BE(packetData + offset);
    offset += 4;
    m_exchangeActionState = packetData[offset++];
    m_groupActionState = packetData[offset++];
    m_portraitFallbackFrame = packetData[offset++];
    m_serverProfileValue = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    m_portraitPayloadLength = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;

    if (m_portraitPayloadLength != 0)
    {
        if (memcmp(packetData + offset, "JPF", 4) == 0)
        {
            unsigned char *portraitData =
                m_portraitBuffer.Resize(m_portraitPayloadLength);
            memmove(portraitData, packetData + offset, m_portraitPayloadLength);
            DecodeJpfImageToTileContext(portraitData,
                                        m_portraitPayloadLength,
                                        &m_portraitImage);
        }
        else
        {
            unsigned char *portraitData =
                m_portraitBuffer.Resize(m_portraitPayloadLength);
            memmove(portraitData, packetData + offset, m_portraitPayloadLength);

            if (portraitData[6] != 0 || portraitData[7] != 0)
                m_portraitPayloadLength = 0;
            else
                ResourceLayoutRawBufferLookupEntry(portraitData, &m_portraitImage);
        }
    }
    offset += m_portraitPayloadLength;

    m_profilePane->ClearText();
    unsigned char profileByteCount = packetData[offset++];
    if (profileByteCount != 0)
    {
        int profileLength = MultiByteToWideChar(
            CP_ACP,
            0,
            reinterpret_cast<const char *>(packetData + offset),
            profileByteCount,
            m_profileText,
            255);
        m_profileText[profileLength] = 0;
        m_profileTextLength = static_cast<unsigned char>(profileLength);
        offset += profileByteCount;

        m_profilePane->SetSelectionRange(0, 0x7fff);
        m_profilePane->SetText(m_profileText, profileLength, 0, 0);
        m_profilePane->SetSelectionRange(0, 0);
    }

    m_legendPane->ClearText();
    m_legendPane->SetEditActiveState(true, false);
    unsigned short legendEntryCount = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;

    for (unsigned short entry = 0; entry < legendEntryCount; ++entry)
    {
        unsigned char symbolIndex = packetData[offset++];
        unsigned char textColor = packetData[offset++];
        wchar_t legendText[512];
        int legendLength = ReadUserLookText(packetData,
                                            offset,
                                            legendText,
                                            512);
        legendText[legendLength++] = L'\r';
        legendText[legendLength] = 0;

        EPFTextEditObject *symbol =
            new EPFTextEditObject(m_legendPane, symbolIndex);
        m_legendPane->InsertText(L" ", 0);
        m_legendPane->InsertEmbeddedObject(symbol, 12, 12);

        short textStart = m_legendPane->GetTextLength();
        m_legendPane->InsertText(legendText, 0);
        short textEnd = m_legendPane->GetTextLength();

        unsigned int formatData[3] = { 0, textColor, 0 };
        m_legendPane->SetSelectionRange(textStart, textEnd);
        m_legendPane->ApplySelectionFormat(2, formatData);
        m_legendPane->SetSelectionRange(textEnd, textEnd);
    }

    m_legendPane->SetEditActiveState(false, false);
    m_legendPane->SetSelectionRange(0, 0);
    m_legendPane->SyncScrollbars();

    m_trailingProfileState = packetData[offset++];
    m_targetNameHighlighted = packetData[offset++];

    wcscpy_s(m_identityLine1, 256, identityLine1);
    wcscpy_s(m_identityLine2, 256, identityLine2);
    wcscpy_s(m_headerText, 128, headerText);
    wcscpy_s(m_targetUserName, 128, targetUserName);
    m_status = status;

    m_bodyId = bodyId;
    m_bodyPalette = bodyPalette;
    m_leftHandId = leftHandId;
    m_leftHandPalette = leftHandPalette;
    m_rightHandId = rightHandId;
    m_rightHandPalette = rightHandPalette;
    m_headId = headId;
    m_headPalette = headPalette;
    m_rightAccessoryId = rightAccessoryId;
    m_rightAccessoryPalette = rightAccessoryPalette;
    m_leftAccessoryId = leftAccessoryId;
    m_leftAccessoryPalette = leftAccessoryPalette;
    m_faceAccessory1Id = faceAccessory1Id;
    m_faceAccessory1Palette = faceAccessory1Palette;
    m_headAccessory2Id = headAccessory2Id;
    m_headAccessory2Palette = headAccessory2Palette;
    m_leftSubAccessoryId = leftSubAccessoryId;
    m_leftSubAccessoryPalette = leftSubAccessoryPalette;
    m_rightSubAccessoryId = rightSubAccessoryId;
    m_rightSubAccessoryPalette = rightSubAccessoryPalette;
    m_necklaceId = necklaceId;
    m_necklacePalette = necklacePalette;
    m_footId = footId;
    m_footPalette = footPalette;
    m_coatId = coatId;
    m_coatPalette = coatPalette;
    m_mantleId = mantleId;
    m_mantlePalette = mantlePalette;

    m_viewMode = 1;
    m_moreInfoPane->RemoveFromLayer();
    m_moreInfoPane->UnregisterEventHandler();
    m_profilePane->RemoveFromLayer();
    m_profilePane->UnregisterEventHandler();
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    ShowMoreInfoView();
}

// UID:0003RM | by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md | Completion:93 | Confidence:94
void UserLookPane::OnDraw()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds overlayBounds;
    RectBounds destinationBounds;
    RectBounds buttonBounds;

    void *backgroundPalette = g_pEPFLib;

    switch (m_viewMode)
    {
    case ViewMode_MoreInfo:
        g_pEPFLib->LookupLayoutEntry(L"USERLOOK.EPF", 0, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"USERLOOK.PAL");
        break;

    case ViewMode_Profile:
        (void)g_pApplication->GetVersionMajor();
        g_pEPFLib->LookupLayoutEntry(L"USERLOOK.EPF", 1, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"USERLOOK.PAL");
        break;

    case ViewMode_Bio:
        g_pEPFLib->LookupLayoutEntry(L"PFLOOK.EPF", 0, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"PFLOOK.PAL");
        break;

    case ViewMode_Legend:
        g_pEPFLib->LookupLayoutEntry(L"USERLOOK.EPF", 3, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"USERLOOK.PAL");
        break;
    }

    g_pfnBlitSprite(this,
                     &tileContext,
                     &tileContext.bounds,
                     &m_bounds,
                     0,
                     backgroundPalette,
                     NULL);

    switch (m_viewMode)
    {
    case ViewMode_MoreInfo:
    {
        const int headerLength = static_cast<int>(wcslen(m_headerText));
        const int headerHalfWidth = GetTextWidth(m_headerText,
                                                 headerLength) / -2;
        const int headerShadowX = 35 + headerHalfWidth;
        SetTextColor(128);
        MoveTo(headerShadowX > 3 ? headerShadowX : 3, 25);
        DrawWideText(m_headerText,
                     static_cast<int>(wcslen(m_headerText)));
        SetTextColor(143);
        MoveTo(headerShadowX > 3 ? 34 + headerHalfWidth : 2, 24);
        DrawWideText(m_headerText,
                     static_cast<int>(wcslen(m_headerText)));

        const int targetNameLength =
            static_cast<int>(wcslen(m_targetUserName));
        const int targetNameHalfWidth =
            GetTextWidth(m_targetUserName, targetNameLength) / -2;
        SetTextColor(128);
        MoveTo(118 + targetNameHalfWidth, 25);
        DrawWideText(m_targetUserName,
                     static_cast<int>(wcslen(m_targetUserName)));
        SetTextColor(m_targetNameHighlighted ? 143 : 10);
        MoveTo(117 + targetNameHalfWidth, 24);
        DrawWideText(m_targetUserName,
                     static_cast<int>(wcslen(m_targetUserName)));

        const int line1Length = static_cast<int>(wcslen(m_identityLine1));
        const int line1HalfWidth =
            GetTextWidth(m_identityLine1, line1Length) / -2;
        SetTextColor(128);
        MoveTo(106 + line1HalfWidth, 45);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        SetTextColor(143);
        MoveTo(105 + line1HalfWidth, 44);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        SetTextBackColor(0);

        const int line2Length = static_cast<int>(wcslen(m_identityLine2));
        const int line2HalfWidth =
            GetTextWidth(m_identityLine2, line2Length) / -2;
        SetTextColor(128);
        MoveTo(106 + line2HalfWidth, 66);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        SetTextColor(143);
        MoveTo(105 + line2HalfWidth, 65);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));

        const int line3Length = static_cast<int>(wcslen(m_identityLine3));
        const int line3HalfWidth =
            GetTextWidth(m_identityLine3, line3Length) / -2;
        SetTextColor(128);
        MoveTo(106 + line3HalfWidth, 87);
        DrawWideText(m_identityLine3,
                     static_cast<int>(wcslen(m_identityLine3)));
        SetTextColor(143);
        MoveTo(105 + line3HalfWidth, 86);
        DrawWideText(m_identityLine3,
                     static_cast<int>(wcslen(m_identityLine3)));

        if (m_status.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            g_pNewHumanImageLib->CalculateBounds(&m_status,
                                                 2,
                                                 0,
                                                 0,
                                                 &imageBounds,
                                                 0,
                                                 0,
                                                 1,
                                                 0);
            g_pNewHumanImageLib->ComputeOverlayBounds(&m_status,
                                                      2,
                                                      0,
                                                      0,
                                                      &overlayBounds,
                                                      0,
                                                      1);

            destinationBounds.bottom = 187;
            destinationBounds.top =
                187 - (imageBounds.bottom - imageBounds.top);
            destinationBounds.left = 54;
            destinationBounds.right =
                54 + (imageBounds.right - imageBounds.left);
            OffsetRect(&destinationBounds, overlayBounds.left, 0);
            destinationBounds.left +=
                imageBounds.left - overlayBounds.left;
            destinationBounds.right +=
                imageBounds.right - overlayBounds.right;

            g_pNewHumanImageLib->Draw(this,
                                      &destinationBounds,
                                      &m_status,
                                      2,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0.0f,
                                      0,
                                      1,
                                      0);
        }
        else if (m_status.m_statusKind == ObjectStatusBlob::MonsterObject)
        {
            g_pMonsterImageLib->ComputeRenderBounds(&m_status,
                                                    7,
                                                    0,
                                                    &imageBounds,
                                                    NULL);
            const int width = imageBounds.right - imageBounds.left;
            const int height = imageBounds.bottom - imageBounds.top;
            const int halfWidth = width / -2;
            const int halfHeight = height / -2;
            destinationBounds.left = 78 + halfWidth;
            destinationBounds.right = 78 + width + halfWidth;
            destinationBounds.top = 131 + halfHeight;
            destinationBounds.bottom = 131 + height + halfHeight;

            g_pMonsterImageLib->RenderMonsterImage(this,
                                                   &destinationBounds,
                                                   &m_status,
                                                   7,
                                                   0,
                                                   0,
                                                   0,
                                                   NULL,
                                                   0.0f);
        }

        GetActionButtonRect(ActionButton_Exchange, &buttonBounds);
        if (m_exchangeActionState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_exchangeActionState ? 8 : 3,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetActionButtonRect(ActionButton_Group, &buttonBounds);
        if (m_groupActionState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_groupActionState ? 7 : 2,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }
        break;
    }

    case ViewMode_Profile:
    {
        if (m_bodyId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_bodyId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 92 + halfHeight;
            destinationBounds.bottom =
                92 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_bodyId),
                                              m_bodyPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_leftHandId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_leftHandId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 150 + halfWidth;
            destinationBounds.right =
                150 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 92 + halfHeight;
            destinationBounds.bottom =
                92 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_leftHandId),
                                              m_leftHandPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_rightHandId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_rightHandId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 92 + halfHeight;
            destinationBounds.bottom =
                92 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_rightHandId),
                                              m_rightHandPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_headId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_headId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 36 + halfHeight;
            destinationBounds.bottom =
                36 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_headId),
                                              m_headPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_faceAccessory1Id != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_faceAccessory1Id,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 36 + halfWidth;
            destinationBounds.right =
                36 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 36 + halfHeight;
            destinationBounds.bottom =
                36 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_faceAccessory1Id),
                m_faceAccessory1Palette,
                NULL,
                0.0f);
        }

        if (m_headAccessory2Id != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_headAccessory2Id,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 150 + halfWidth;
            destinationBounds.right =
                150 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 36 + halfHeight;
            destinationBounds.bottom =
                36 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_headAccessory2Id),
                m_headAccessory2Palette,
                NULL,
                0.0f);
        }

        if (m_rightAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_rightAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 147 + halfWidth;
            destinationBounds.right =
                147 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 146 + halfHeight;
            destinationBounds.bottom =
                146 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightAccessoryId),
                m_rightAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_leftAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_leftAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 146 + halfHeight;
            destinationBounds.bottom =
                146 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftAccessoryId),
                m_leftAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_leftSubAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_leftSubAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 198 + halfHeight;
            destinationBounds.bottom =
                198 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftSubAccessoryId),
                m_leftSubAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_rightSubAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_rightSubAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 150 + halfWidth;
            destinationBounds.right =
                150 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 198 + halfHeight;
            destinationBounds.bottom =
                198 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightSubAccessoryId),
                m_rightSubAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_necklaceId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_necklaceId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 146 + halfHeight;
            destinationBounds.bottom =
                146 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_necklaceId),
                                              m_necklacePalette,
                                              NULL,
                                              0.0f);
        }

        if (m_footId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_footId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 250 + halfHeight;
            destinationBounds.bottom =
                250 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_footId),
                                              m_footPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_coatId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_coatId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 250 + halfHeight;
            destinationBounds.bottom =
                250 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_coatId),
                                              m_coatPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_mantleId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_mantleId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 198 + halfHeight;
            destinationBounds.bottom =
                198 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_mantleId),
                                              m_mantlePalette,
                                              NULL,
                                              0.0f);
        }
        break;
    }

    case ViewMode_Bio:
    {
        RectBounds portraitBounds;
        InitRectBounds(&portraitBounds, 70, 48, 118, 104);
        void *portraitPalette =
            g_pPaletteLib->GetSlotPalette(13, 0, 0);

        if (m_portraitPayloadLength != 0)
        {
            g_pfnBlitSprite(this,
                             &m_portraitImage,
                             &m_portraitImage.bounds,
                             &portraitBounds,
                             0,
                             portraitPalette,
                             NULL);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"FACE.EPF",
                                         m_statusEncoding != 0,
                                         &tileContext);
            SurfaceSpriteBlitOptions portraitOptions;
            portraitOptions.mode = 4;
            g_pfnBlitSprite(this,
                             &tileContext,
                             &tileContext.bounds,
                             &portraitBounds,
                             1,
                             NULL,
                             &portraitOptions);
        }

        g_pEPFLib->LookupLayoutEntry(L"NATION.EPF",
                                     m_portraitFallbackFrame,
                                     &tileContext);
        break;
    }

    case ViewMode_Legend:
        break;

    default:
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF",
                                 7 * m_nextButtonFrame + 6,
                                 &tileContext);
    GetActionButtonRect(ActionButton_Next, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);

    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF",
                                 7 * m_previousButtonFrame + 5,
                                 &tileContext);
    GetActionButtonRect(ActionButton_Previous, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);
}

// UID:0003RN | by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md | Completion:93 | Confidence:94
static void __stdcall SendUserLookNameCommandPacket(
    const wchar_t *targetName);
static void __stdcall SendUserLookTargetActionPacket(
    unsigned int targetObjectId);

bool UserLookPane::OnMouseEvent(Event *event)
{
    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;

    switch (event->m_type)
    {
    case kEventCursorMove:
    {
        if (!PointInRect(y, x, &m_bounds))
        {
            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Normal;
            return false;
        }

        RectBounds nextBounds;
        RectBounds previousBounds;
        GetActionButtonRect(ActionButton_Next, &nextBounds);
        GetActionButtonRect(ActionButton_Previous, &previousBounds);

        if (PointInRect(y, x, &nextBounds))
        {
            m_nextButtonFrame = ButtonFrame_Hover;
            m_previousButtonFrame = ButtonFrame_Normal;
            InvalidateRect(&m_bounds);
            return true;
        }

        if (PointInRect(y, x, &previousBounds))
        {
            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Hover;
            InvalidateRect(&m_bounds);
            return true;
        }

        if (m_nextButtonFrame == ButtonFrame_Normal &&
            m_previousButtonFrame == ButtonFrame_Normal)
        {
            return true;
        }

        m_nextButtonFrame = ButtonFrame_Normal;
        m_previousButtonFrame = ButtonFrame_Normal;
        InvalidateRect(&m_bounds);
        return true;
    }

    case kEventLeftButtonDown:
        switch (HitTestActionButton(y, x))
        {
        case ActionButton_Group:
            if (m_exchangeActionState != ButtonVisualState_Disabled)
                SendUserLookTargetActionPacket(m_targetObjectId);
            return true;

        case ActionButton_Exchange:
            if (m_exchangeActionState != ButtonVisualState_Disabled)
                SendUserLookNameCommandPacket(m_targetUserName);
            return true;

        case ActionButton_Previous:
            if (m_viewMode == ViewMode_Legend)
                ShowBioView();
            else if (m_viewMode == ViewMode_Bio)
                ShowProfileView();
            else if (m_viewMode == ViewMode_Profile &&
                     g_useEpfAssets == 1)
                ShowMoreInfoView();

            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Pressed;
            InvalidateRect(&m_bounds);
            return true;

        case ActionButton_Next:
            if (m_viewMode == ViewMode_MoreInfo)
                ShowProfileView();
            else if (m_viewMode == ViewMode_Profile)
                ShowBioView();
            else if (m_viewMode == ViewMode_Bio)
                ShowLegendView();

            m_nextButtonFrame = ButtonFrame_Pressed;
            m_previousButtonFrame = ButtonFrame_Normal;
            InvalidateRect(&m_bounds);
            return true;

        default:
            return false;
        }

    case kEventRightButtonDown:
    {
        const short actionId = HitTestActionButton(y, x);
        delete g_pSimpleHelpPane;

        switch (actionId)
        {
        case ActionButton_Group:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(200),
                this, x, y, 5000);
            return true;

        case ActionButton_Exchange:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(201),
                this, x, y, 5000);
            return true;

        default:
            return false;
        }
    }

    default:
        return false;
    }
}

// UID:0003RO | by-memory/0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md | Completion:92 | Confidence:93
bool UserLookPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown) {
        return false;
    }

    if (key == kPaneKeyPageUp) {
        if (event->m_payload.m_key.m_modifiers != 0) {
            return false;
        }

        if (m_viewMode == 3) {
            ShowBioView();
        } else if (m_viewMode == 2) {
            ShowProfileView();
        } else if (m_viewMode == 1 && g_useEpfAssets) {
            ShowMoreInfoView();
        }
        return true;
    }

    if (key == kPaneKeyPageDown) {
        if (event->m_payload.m_key.m_modifiers != 0) {
            return false;
        }

        if (m_viewMode == 0) {
            ShowProfileView();
        } else if (m_viewMode == 1) {
            ShowBioView();
        } else if (m_viewMode == 2) {
            ShowLegendView();
        }
        return true;
    }

    return false;
}

// UID:0003RP | by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md | Completion:92 | Confidence:94
void UserLookPane::GetActionButtonRect(
    short actionId,
    RectBounds *bounds) const
{
    int left = -1;
    int top = -1;
    int right = -1;
    int bottom = -1;

    switch (actionId)
    {
    case ActionButton_Group:
        if (m_viewMode == ViewMode_MoreInfo)
        {
            left = 146;
            top = 112;
            right = 182;
            bottom = 148;
        }
        break;

    case ActionButton_Exchange:
        if (m_viewMode == ViewMode_MoreInfo)
        {
            left = 146;
            top = 148;
            right = 182;
            bottom = 184;
        }
        break;

    case ActionButton_Previous:
        if (m_viewMode == ViewMode_Profile ||
            m_viewMode == ViewMode_Bio)
        {
            left = 149;
            top = 268;
            right = 167;
            bottom = 286;
        }
        break;

    case ActionButton_Next:
        if (m_viewMode == ViewMode_MoreInfo ||
            m_viewMode == ViewMode_Profile ||
            m_viewMode == ViewMode_Bio)
        {
            left = 169;
            top = 268;
            right = 187;
            bottom = 286;
        }
        break;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}

// UID:0003RQ | by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md | Completion:92 | Confidence:94
short UserLookPane::HitTestActionButton(int y, int x) const
{
    RectBounds bounds;

    for (short actionId = ActionButton_Group;
         actionId <= ActionButton_Next;
         ++actionId)
    {
        GetActionButtonRect(actionId, &bounds);
        if (PointInRect(y, x, &bounds))
            return actionId;
    }

    return -1;
}

// UID:0003RR | by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md | Completion:92 | Confidence:93
void UserLookPane::ShowMoreInfoView()
{
    m_viewMode = ViewMode_MoreInfo;

    RectBounds moreInfoBounds;
    if (g_useEpfAssets == 1)
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();
        InitRectBounds(&moreInfoBounds, 7, 205, 182, 266);
    }
    else
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        InitRectBounds(&moreInfoBounds, 17, 192, 174, 251);
    }

    const unsigned short currentPosition =
        m_moreInfoPane->GetScrollPosition(0);
    m_moreInfoPane->ApplyScrollPosition(0, currentPosition, 0);
    m_moreInfoPane->AddToLayer(
        &moreInfoBounds,
        0,
        this,
        g_mainUiLayerSlots.rootPaneLayerContext);
    m_moreInfoPane->SetPaneOrder(0, this);
    InvalidateRect(&m_bounds);
}

// UID:0003RS | by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md | Completion:92 | Confidence:93
void UserLookPane::ShowProfileView()
{
    m_viewMode = ViewMode_Profile;

    if (g_useEpfAssets == 1)
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();
    }
    else
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();

        RectBounds profileViewBounds;
        InitRectBounds(&profileViewBounds, 17, 192, 174, 251);
        const unsigned short currentPosition =
            m_moreInfoPane->GetScrollPosition(0);
        m_moreInfoPane->ApplyScrollPosition(0, currentPosition, 0);
        m_moreInfoPane->AddToLayer(
            &profileViewBounds,
            0,
            this,
            g_mainUiLayerSlots.rootPaneLayerContext);
        m_moreInfoPane->SetPaneOrder(0, this);
    }

    InvalidateRect(&m_bounds);
}

// UID:0003RT | by-memory/0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md | Completion:92 | Confidence:93
void UserLookPane::ShowBioView()
{
    m_viewMode = 2;

    m_moreInfoPane->RemoveFromLayer();
    m_moreInfoPane->UnregisterEventHandler();
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();

    RectBounds profileBounds(17, 120, 174, 240);
    const unsigned short currentPosition =
        m_profilePane->GetScrollPosition(0);
    m_profilePane->ApplyScrollPosition(0, currentPosition, 0);
    m_profilePane->AddToLayer(
        &profileBounds,
        0,
        this,
        g_mainUiLayerSlots.rootPaneLayerContext);
    m_profilePane->SetPaneOrder(0, this);

    InvalidateRect(&m_bounds);
}

// UID:0003RU | by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md | Completion:92 | Confidence:93
void UserLookPane::ShowLegendView()
{
    m_viewMode = ViewMode_Legend;

    RectBounds legendBounds;
    if (g_useEpfAssets == 1)
    {
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        InitRectBounds(&legendBounds, 7, 15, 182, 265);

        const unsigned short currentPosition =
            m_legendPane->GetScrollPosition(0);
        m_legendPane->ApplyScrollPosition(0, currentPosition, 0);
        m_legendPane->m_verticalScrollBarOffset = 49;
        m_legendPane->AddToLayer(
            &legendBounds,
            0,
            this,
            g_mainUiLayerSlots.rootPaneLayerContext);
        m_legendPane->SetPaneOrder(0, this);

        const unsigned short maximumPosition =
            m_legendPane->GetScrollMax(0);
        const unsigned short currentPositionAfterAttach =
            m_legendPane->GetScrollPosition(0);
        m_legendPane->ApplyScrollPosition(
            0, currentPositionAfterAttach, maximumPosition);
    }
    else
    {
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        InitRectBounds(&legendBounds, 17, 36, 174, 251);

        const unsigned short currentPosition =
            m_legendPane->GetScrollPosition(0);
        m_legendPane->ApplyScrollPosition(0, currentPosition, 0);
        m_legendPane->AddToLayer(
            &legendBounds,
            0,
            this,
            g_mainUiLayerSlots.rootPaneLayerContext);
        m_legendPane->SetPaneOrder(0, this);
    }

    InvalidateRect(&m_bounds);
}


// UID:0002A8 | by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md | Completion:90 | Confidence:92
MoreInfoPane *g_pMoreInfoPane = 0;

// UID:0003RV | by-memory/0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket.md | Completion:91 | Confidence:93
static void __stdcall SendUserLookNameCommandPacket(
    const wchar_t *targetName)
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (targetName[0] == L'\0')
        return;

    unsigned char packet[300];
    char convertedText[256];

    PacketBufferWriteUInt8(0x2e, packet);

    const short sourceLength =
        static_cast<short>(wcslen(targetName));
    const unsigned int textLength =
        static_cast<unsigned int>(
            WideCharToMultiByte(
                CP_ACP, 0,
                targetName, sourceLength,
                convertedText, 256,
                NULL, NULL));

    convertedText[textLength] = '\0';
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(textLength),
        packet + 1);
    memoryMan->MemmoveWrapper(
        packet + 2, convertedText, textLength);

    const unsigned int packetLength = textLength + 2;
    packet[packetLength] = '\0';
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}

// UID:0003RW | by-memory/0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket.md | Completion:91 | Confidence:93
static void __stdcall SendUserLookTargetActionPacket(
    unsigned int targetObjectId)
{
    unsigned char packet[16];
    PacketBufferWriteUInt8(0x4a, packet);
    PacketBufferWriteUInt8(0, packet + 1);
    PacketBufferWriteUInt32BE(targetObjectId, packet + 2);
    packet[6] = 0;
    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:00008Q | by-class/MoreInfoPane.md | Completion:90 | Confidence:92
class Event;

class MoreInfoPane : public TextEditPane
{
public:
    MoreInfoPane();
    virtual ~MoreInfoPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

// UID:0003RX | by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md | Completion:88 | Confidence:91
MoreInfoPane::MoreInfoPane()
    : TextEditPane(145,
                   108,
                   145,
                   108,
                   128,
                   0,
                   false,
                   true,
                   6,
                   IsLegacyAssetMode(),
                   true,
                   false)
{
}

// UID:0003RY | by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md | Completion:89 | Confidence:92
bool MoreInfoPane::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

// UID:0003RZ | by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md | Completion:89 | Confidence:92
bool MoreInfoPane::OnMouseEvent(Event *event)
{
    return false;
}

// UID:0000AV | by-class/ProfilePane.md | Completion:90 | Confidence:92
class Event;

class ProfilePane : public TextEditPane
{
public:
    ProfilePane();
    virtual ~ProfilePane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

// UID:0003S0 | by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md | Completion:88 | Confidence:91
ProfilePane::ProfilePane()
    : TextEditPane(145,
                   108,
                   145,
                   108,
                   128,
                   0,
                   false,
                   true,
                   6,
                   IsLegacyAssetMode(),
                   true,
                   false)
{
}

// UID:0003S1 | by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md | Completion:89 | Confidence:92
bool ProfilePane::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

// UID:0003S2 | by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md | Completion:89 | Confidence:92
bool ProfilePane::OnMouseEvent(Event *event)
{
    return false;
}

// UID:0003RJ | by-memory\0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003S4 | by-memory\0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003F4 | by-memory\0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:00026V | by-memory\0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:00038X | by-memory\0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:00038Q | by-type\by-vtable\UserLookPaneFamilyVtables.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:00038R | by-memory\0x0062eccc-0x0062ed58.UserLookPaneVtableData.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:00038S | by-memory\0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:00038T | by-memory\0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker
