// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NL
// Source by-file doc: by-file/SelfLookPane.md
// UID:0000CU | by-class/SelfLookPane.md | Completion:93 | Confidence:94
class SelfLookPane : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    enum SlotId
    {
        SelfLookSlot_Face = 0,
        SelfLookSlot_Body = 1,
        SelfLookSlot_Stats = 2,
        SelfLookSlot_Previous = 3,
        SelfLookSlot_Next = 4,
        SelfLookSlot_TopOption = 5,
        SelfLookSlot_BottomOption = 6,
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    SelfLookPane();
    virtual ~SelfLookPane();

    virtual void OnReceiveCharacterData(const unsigned char *packet);
    virtual void OnPaint();
    virtual bool OnMouseClick(const PanelMouseEvent *event);
    virtual bool OnKeyPress(Event *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);
    virtual bool OnShowHelp(void *helpContext, int x, int y);
    virtual void OnGetRect(RectBounds *bounds);
    virtual int OnTransformRect(RectBounds *bounds, int transformMode);

    void AddOrUpdateSpelledEntry(const wchar_t *text, int value);
    void RefreshSpelledPane();
    void StopSpelledPaneRefresh();
    void ResetAndRefresh();
    void ActivateView();
    void ShowSpelledView();
    void DeactivateView();

    void DrawNumberString(const wchar_t *text,
                          int x,
                          int y,
                          unsigned char glyphSet);
    void GetSlotRect(short slotId, RectBounds *bounds) const;
    unsigned short HitTestSlot(int x, int y) const;

    void SendToggleLook();
    void SendToggleEquip();
    void SendToggleStats();
    bool SendSelfLookOptionRequest(unsigned char optionSubtype);
    void SendSelfLookOption02Raw();
    void SendSelfLookOption08Raw();
    void SendSelfLookOption0bRaw();

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);
    void ToggleSelfLookViewCache();

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_selfLookObjectStatus;

    unsigned short m_equipmentSlotItemIds[21];
    unsigned char m_equipmentSlotRecordStates[21];
    wchar_t m_equipmentSlotNames[21][64];
    wchar_t m_equipmentSlotDescriptions[21][64];
    unsigned int m_equipmentSlotValues[21];
    unsigned char m_equipmentSlotValueFlags[21];
    unsigned char m_equipmentSlotHoverStates[21];

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_summaryCompareKey0;
    unsigned int m_summaryCompareKey1;
    unsigned char m_summaryTailByte0;
    unsigned char m_summaryTailByte1;
    unsigned char m_summaryTailByte2;
    unsigned int m_summaryTailValue;
    unsigned int m_lastSelfLookOptionTick;
    unsigned int m_selfLookOptionRepeatDelay;
    unsigned char m_bodyToggleState;
    unsigned char m_faceToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_activeViewMode;
    int m_serverRequestedViewMode;
    int m_reservedViewState;
    int m_pendingMouseAction;
    int m_pendingMouseView;
    unsigned char m_viewCacheToggle;
};




// UID:0003QC | by-memory/0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook.md | Completion:91 | Confidence:93
void SelfLookPane::SendToggleLook()
{
    if (g_pTimerMgr->m_currentTick <=
        m_lastSelfLookOptionTick + m_selfLookOptionRepeatDelay)
    {
        return;
    }

    m_faceToggleState = m_faceToggleState == 0;

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x1b, packet + 0);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt8(0x08, packet + 2);
    PacketBufferWriteUInt8(0x00, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);

    RectBounds slotBounds;
    GetSlotRect(SelfLookSlot_Face, &slotBounds);

    m_lastSelfLookOptionTick = g_pTimerMgr->m_currentTick;
}

// UID:0003QD | by-memory/0x00567000-0x005670ba.SelfLookPaneSendToggleEquip.md | Completion:91 | Confidence:93
void SelfLookPane::SendToggleEquip()
{
    if (g_pTimerMgr->m_currentTick <=
        m_lastSelfLookOptionTick + m_selfLookOptionRepeatDelay)
    {
        return;
    }

    m_bodyToggleState = m_bodyToggleState == 0;

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x1b, packet + 0);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt8(0x02, packet + 2);
    PacketBufferWriteUInt8(0x00, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);

    RectBounds slotBounds;
    GetSlotRect(SelfLookSlot_Body, &slotBounds);

    m_lastSelfLookOptionTick = g_pTimerMgr->m_currentTick;
}

// UID:0003QE | by-memory/0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw.md | Completion:89 | Confidence:92
void SelfLookPane::SendToggleStats()
{
    if (g_pTimerMgr->m_currentTick <=
        m_lastSelfLookOptionTick + m_selfLookOptionRepeatDelay)
    {
        return;
    }

    m_statsToggleState = m_statsToggleState == 0;

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x1b, packet + 0);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt8(0x0b, packet + 2);
    PacketBufferWriteUInt8(0x00, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);

    RectBounds slotBounds;
    GetSlotRect(SelfLookSlot_Stats, &slotBounds);

    m_lastSelfLookOptionTick = g_pTimerMgr->m_currentTick;
}

// UID:0003QF | by-memory/0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw.md | Completion:90 | Confidence:92
void SelfLookPane::AddOrUpdateSpelledEntry(const wchar_t *text, int value)
{
    m_spelledPane->AddOrUpdateEntry(text, value, 0);
}


// UID:0003QH | by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md | Completion:89 | Confidence:92
void SelfLookPane::RefreshSpelledPane()
{
    m_spelledPane->RefreshScrollState();
}

// UID:0004TT | by-memory/0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh.md | Completion:92 | Confidence:94
void SelfLookPane::StopSpelledPaneRefresh()
{
    m_spelledPane->RemoveFrame();
}





// UID:0003QN | by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md | Completion:93 | Confidence:94
#include "ItemObjImageLib.h"

extern ItemObjImageLib *g_pItemObjImageLib;

void SelfLookPane::OnPaint()
{
    EPFTileContext tileContext;
    EPFTileContext commaContext;
    EPFTileContext offButtonContext;
    EPFTileContext onButtonContext;
    RectBounds imageBounds;
    RectBounds slotBounds;
    RectBounds destinationBounds;
    RectBounds statBounds;
    wchar_t text[128];


    const wchar_t *backgroundPaletteName = L"ITEMINV.PAL";

    switch (m_activeViewMode) {
    case ViewMode_Default:
        backgroundPaletteName =
            m_viewCacheToggle ? L"LOOKEXT.PAL" : L"LOOKICON.PAL";
        g_pEPFLib->LookupLayoutEntry(
            m_viewCacheToggle ? L"LOOKEXT.EPF" : L"SELFLOOK.EPF",
            0,
            &tileContext);
        break;

    case ViewMode_Spelled:
        backgroundPaletteName =
            m_viewCacheToggle ? L"LOOKEXT.PAL" : L"LOOKICON.PAL";
        g_pEPFLib->LookupLayoutEntry(
            m_viewCacheToggle ? L"LOOKEXT.EPF" : L"SELFLOOK.EPF",
            1,
            &tileContext);
        break;

    case ViewMode_Legend:
        backgroundPaletteName =
            m_viewCacheToggle ? L"LOOKEXT.PAL" : L"LOOKICON.PAL";
        g_pEPFLib->LookupLayoutEntry(
            m_viewCacheToggle ? L"LOOKEXT.EPF" : L"SELFLOOK.EPF",
            2,
            &tileContext);
        break;

    default:
        g_pEPFLib->LookupLayoutEntry(L"COMMA.EPF", 0, &commaContext);
        break;
    }

    DLPalette *backgroundPalette =
        g_pPaletteLib->GetPaletteByName(backgroundPaletteName);
    g_pfnBlitSprite(this,
                    &tileContext,
                    &tileContext.bounds,
                    &m_bounds,
                    0,
                    backgroundPalette,
                    NULL);

    if (m_activeViewMode == ViewMode_Default) {
        const int highlightLeft[14] = {
            7, 63, 121, 7, 63, 121, 7,
            63, 121, 7, 63, 121, 7, 63
        };
        const int highlightTop[14] = {
            10, 10, 10, 62, 62, 62, 114,
            114, 114, 166, 166, 166, 218, 218
        };

        for (short slotId = SelfLookEquipmentSlot_FaceAccessory1;
             slotId <= SelfLookEquipmentSlot_Foot;
             ++slotId) {
            const unsigned short itemId =
                m_equipmentSlotItemIds[slotId];
            if (itemId == 0)
                continue;

            g_pItemObjImageLib->GetItemGlyphBounds(itemId, &imageBounds);
            GetSlotRect(slotId, &slotBounds);

            const int itemWidth = imageBounds.right - imageBounds.left;
            const int itemHeight = imageBounds.bottom - imageBounds.top;
            destinationBounds.left =
                (slotBounds.left + slotBounds.right) / 2 - itemWidth / 2;
            destinationBounds.right =
                destinationBounds.left + itemWidth;
            destinationBounds.top =
                (slotBounds.top + slotBounds.bottom) / 2 - itemHeight / 2;
            destinationBounds.bottom =
                destinationBounds.top + itemHeight;

            if (m_equipmentSlotHoverStates[slotId] == 1) {
                OffsetRect(&destinationBounds, -2, -2);

                const int highlightIndex =
                    slotId - SelfLookEquipmentSlot_FaceAccessory1;
                RectBounds highlightBounds;
                InitRectBounds(&highlightBounds,
                               highlightLeft[highlightIndex],
                               highlightTop[highlightIndex],
                               highlightLeft[highlightIndex] + 48,
                               highlightTop[highlightIndex] + 48);

                g_pEPFLib->LookupLayoutEntry(L"LOOKICON.EPF",
                                             highlightIndex,
                                             &tileContext);
                RenderTileFrame(&tileContext,
                                &tileContext.bounds,
                                &highlightBounds,
                                0,
                                L"LOOKICON.PAL",
                                NULL);
            }

            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(itemId),
                m_equipmentSlotRecordStates[slotId],
                NULL,
                0.0f);
        }

        g_pEPFLib->LookupLayoutEntry(L"ONOFFBUT.EPF",
                                     0,
                                     &offButtonContext);
        g_pEPFLib->LookupLayoutEntry(L"ONOFFBUT.EPF",
                                     1,
                                     &onButtonContext);

        GetSlotRect(SelfLookSlot_TopOption, &slotBounds);
        EPFTileContext *buttonContext =
            g_pConfig->m_selfLookTopButtonSelected
                ? &onButtonContext
                : &offButtonContext;
        RenderTileFrame(buttonContext,
                        &buttonContext->bounds,
                        &slotBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        GetSlotRect(SelfLookSlot_BottomOption, &slotBounds);
        buttonContext =
            g_pConfig->m_selfLookBottomButtonSelected
                ? &onButtonContext
                : &offButtonContext;
        RenderTileFrame(buttonContext,
                        &buttonContext->bounds,
                        &slotBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        g_pEPFLib->LookupLayoutEntry(
            L"INVENBUT.EPF",
            7 * m_pendingMouseAction + 6,
            &tileContext);
        GetSlotRect(SelfLookSlot_Next, &slotBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &slotBounds,
                        0,
                        L"INVENBUT.PAL",
                        NULL);

        g_pEPFLib->LookupLayoutEntry(
            L"INVENBUT.EPF",
            7 * m_pendingMouseView + 5,
            &tileContext);
        GetSlotRect(SelfLookSlot_Previous, &slotBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &slotBounds,
                        0,
                        L"INVENBUT.PAL",
                        NULL);

        GetSlotRect(SelfLookSlot_Face, &slotBounds);
        if (m_faceToggleState == ButtonVisualState_Disabled) {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &slotBounds);
        } else {
            g_pEPFLib->LookupLayoutEntry(
                L"STATBUTS.EPF",
                m_faceToggleState ? 7 : 2,
                &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &slotBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetSlotRect(SelfLookSlot_Body, &slotBounds);
        if (m_bodyToggleState == ButtonVisualState_Disabled) {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &slotBounds);
        } else {
            g_pEPFLib->LookupLayoutEntry(
                L"STATBUTS.EPF",
                m_bodyToggleState ? 8 : 3,
                &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &slotBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetSlotRect(SelfLookSlot_Stats, &slotBounds);
        if (m_statsToggleState == ButtonVisualState_Disabled) {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &slotBounds);
            return;
        }

        g_pEPFLib->LookupLayoutEntry(
            L"STATBUTS.EPF",
            m_statsToggleState ? 9 : 4,
            &tileContext);
        return;
    }

    if (m_activeViewMode == ViewMode_Spelled) {
        SetTextColor(128);
        m_textDrawMode = 1;

        MoveTo(59, 25);
        SetTextColor(128);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(58, 24);
        SetTextColor(37);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(57, 24);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));

        MoveTo(59, 45);
        SetTextColor(128);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(58, 44);
        SetTextColor(37);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(57, 44);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));

        const int nationId = g_activeUserStatusPane->GetNationId();
        if (nationId != -1) {
            const wchar_t *nationText;
            switch (nationId) {
            case 0:
                nationText = L"Neutral";
                break;
            case 1:
                nationText = L"Koguryo";
                break;
            case 2:
                nationText = L"Buya";
                break;
            case 3:
                nationText = L"Nagnang";
                break;
            case 4:
                nationText = L"Han";
                break;
            default:
                nationText = L"";
                break;
            }

            wcscpy_s(text, 128, nationText);
            SetTextColor(128);
            MoveTo(64 - GetTextWidth(text) / 2, 86);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            SetTextColor(37);
            MoveTo(64 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            MoveTo(63 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
        }

        const int spiritId = g_activeUserStatusPane->GetSpiritId();
        if (spiritId != -1) {
            const wchar_t *spiritText;
            switch (spiritId) {
            case 0:
                spiritText = L"Ju jak";
                break;
            case 1:
                spiritText = L"Baekho";
                break;
            case 2:
                spiritText = L"Hyun moo";
                break;
            case 3:
                spiritText = L"Chung ryong";
                break;
            default:
                spiritText = L"";
                break;
            }

            wcscpy_s(text, 128, spiritText);
            SetTextColor(128);
            MoveTo(133 - GetTextWidth(text) / 2, 86);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            SetTextColor(37);
            MoveTo(133 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            MoveTo(132 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
        }

        InitRectBounds(&statBounds, 24, 120, 56, 132);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatA()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(9 * wcslen(text)) -
                        statBounds.left) /
                           2,
                       0);
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             1);
        }

        InitRectBounds(&statBounds, 83, 120, 115, 132);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatB()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(9 * wcslen(text)) -
                        statBounds.left) /
                           2,
                       0);
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             1);
        }

        InitRectBounds(&statBounds, 142, 120, 174, 132);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatC()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(9 * wcslen(text)) -
                        statBounds.left) /
                           2,
                       0);
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             1);
        }

#define DRAW_GROUPED_SELF_LOOK_NUMBER(VALUE, GLYPH_SET)                         \
        do {                                                                    \
            unsigned int groupedValue = (VALUE);                               \
            swprintf_s(text, 128, L"%10u", groupedValue);                      \
            const int textLength = static_cast<int>(wcslen(text));             \
            statBounds.right =                                                 \
                (statBounds.right + statBounds.left +                          \
                 9 * textLength + 15) / 2;                                     \
            statBounds.left = statBounds.right - 27;                           \
            statBounds.top =                                                   \
                (statBounds.top - 11 + statBounds.bottom) / 2 + 1;             \
            int digitCount = 0;                                                \
            while (groupedValue != 0 && digitCount < 10) {                     \
                ++digitCount;                                                  \
                groupedValue /= 10;                                            \
            }                                                                  \
            const int commaCount = (digitCount - 1) / 3;                       \
            OffsetRect(&statBounds, 0, -1);                                    \
            wchar_t group[4];                                                  \
            const wchar_t *groupStart = text + 7;                              \
            for (int groupIndex = 0; groupIndex < 3; ++groupIndex) {           \
                for (int copyPass = 0; copyPass < 3; ++copyPass) {             \
                    wcsncpy_s(group, 4, groupStart, 3);                         \
                    group[3] = L'\0';                                          \
                }                                                              \
                DrawNumberString(group,                                        \
                                 statBounds.left,                              \
                                 statBounds.top,                               \
                                 (GLYPH_SET));                                 \
                OffsetRect(&statBounds, -4, 6);                                \
                if (commaCount > groupIndex) {                                 \
                    RenderTileFrame(&commaContext,                             \
                                    &commaContext.bounds,                      \
                                    &statBounds,                               \
                                    1,                                         \
                                    L"COMMA.PAL",                              \
                                    NULL);                                     \
                }                                                              \
                OffsetRect(&statBounds, -27, -6);                              \
                groupStart -= 3;                                               \
            }                                                                  \
            wcsncpy_s(group, 4, text, 1);                                      \
            group[1] = L'\0';                                                  \
            OffsetRect(&statBounds, 18, 0);                                    \
            DrawNumberString(group,                                            \
                             statBounds.left,                                  \
                             statBounds.top,                                   \
                             (GLYPH_SET));                                     \
        } while (0)

        InitRectBounds(&statBounds, 50, 200, 179, 212);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            DRAW_GROUPED_SELF_LOOK_NUMBER(
                g_activeUserStatusPane->GetDisplayValueA(),
                2);
        }

        InitRectBounds(&statBounds, 50, 220, 179, 232);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            DRAW_GROUPED_SELF_LOOK_NUMBER(
                g_activeUserStatusPane->GetDisplayValueB(),
                2);
        }

        InitRectBounds(&statBounds, 0, 140, 110, 152);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%d",
                       static_cast<signed char>(m_summaryTailByte0));
            statBounds.left =
                statBounds.right -
                static_cast<int>(9 * wcslen(text));
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             2);
        }

        swprintf_s(text,
                   128,
                   L"%d",
                   static_cast<signed char>(m_summaryTailByte1));
        InitRectBounds(&statBounds, 0, 160, 83, 172);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            statBounds.left =
                statBounds.right -
                static_cast<int>(9 * wcslen(text));
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             2);
        }

        swprintf_s(text,
                   128,
                   L"%d",
                   static_cast<signed char>(m_summaryTailByte2));
        InitRectBounds(&statBounds, 0, 160, 168, 172);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            statBounds.left =
                statBounds.right -
                static_cast<int>(9 * wcslen(text));
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             2);
        }

        InitRectBounds(&statBounds, 50, 180, 179, 192);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            DRAW_GROUPED_SELF_LOOK_NUMBER(m_summaryTailValue, 0);
        }

#undef DRAW_GROUPED_SELF_LOOK_NUMBER

        InitRectBounds(&statBounds, 0, 175, 110, 187);
        if (m_exposedRegion.IntersectsRect(&statBounds) &&
            wcslen(m_auxiliaryText) > 7) {
            swprintf_s(text, 128, L"%s", m_auxiliaryText + 7);
            SetTextColor(128);
            MoveTo(58, 105);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            SetTextColor(37);
            MoveTo(58, 104);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            MoveTo(57, 104);
            DrawWideText(text, static_cast<int>(wcslen(text)));
        }
    } else if (m_activeViewMode != ViewMode_Legend) {
        return;
    }

    g_pEPFLib->LookupLayoutEntry(
        L"INVENBUT.EPF",
        7 * m_pendingMouseAction + 6,
        &tileContext);
    GetSlotRect(SelfLookSlot_Next, &slotBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &slotBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);

    g_pEPFLib->LookupLayoutEntry(
        L"INVENBUT.EPF",
        7 * m_pendingMouseView + 5,
        &tileContext);
    GetSlotRect(SelfLookSlot_Previous, &slotBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &slotBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);
}


// UID:0003QP | by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md | Completion:90 | Confidence:92
bool SelfLookPane::OnMouseClick(const PanelMouseEvent *event)
{
    const unsigned short slotId = HitTestSlot(event->x, event->y);

    if (event->button == PanelMouseButton_Right) {
        if (g_pSelfLookPopupPane != NULL)
            g_pSelfLookPopupPane->Close(1);

        switch (slotId) {
        case SelfLookSlot_Face:
            ShowSelfLookHelpPopup(197, event->x, event->y);
            return true;
        case SelfLookSlot_Body:
            ShowSelfLookHelpPopup(198, event->x, event->y);
            return true;
        case SelfLookEquipmentSlot_FaceAccessory1:
        case SelfLookEquipmentSlot_Head:
        case SelfLookEquipmentSlot_HeadAccessory2:
        case SelfLookEquipmentSlot_RightHand:
        case SelfLookEquipmentSlot_Body:
        case SelfLookEquipmentSlot_LeftHand:
        case SelfLookEquipmentSlot_RightAccessory:
        case SelfLookEquipmentSlot_Mantle:
        case SelfLookEquipmentSlot_LeftAccessory:
        case SelfLookEquipmentSlot_LeftSubAccessory:
        case SelfLookEquipmentSlot_Coat:
        case SelfLookEquipmentSlot_RightSubAccessory:
        case SelfLookEquipmentSlot_Necklace:
        case SelfLookEquipmentSlot_Foot:
            if (m_equipmentSlotItemIds[slotId] != 0)
                ShowEquipmentSlotTooltip(slotId, event->x, event->y);
            return true;
        default:
            return false;
        }
    }

    if (event->button == PanelMouseButton_Left) {
        if (g_pCollectionData->IsInteractionLocked())
            return true;

        switch (slotId) {
        case SelfLookSlot_Face: {
            if (m_faceToggleState == ButtonVisualState_Disabled)
                return true;
            m_faceToggleState = !m_faceToggleState;
            SendSelfLookOptionRequest(0x08);
            RectBounds changedBounds;
            GetSlotRect(SelfLookSlot_Face, &changedBounds);
            break;
        }

        case SelfLookSlot_Body: {
            if (m_bodyToggleState == ButtonVisualState_Disabled)
                return true;
            m_bodyToggleState = !m_bodyToggleState;
            SendSelfLookOptionRequest(0x02);
            RectBounds changedBounds;
            GetSlotRect(SelfLookSlot_Body, &changedBounds);
            break;
        }

        case SelfLookSlot_Previous:
            if (m_activeViewMode == ViewMode_Legend)
                ShowSpelledView();
            else if (m_activeViewMode == ViewMode_Spelled)
                ResetAndRefresh();
            m_pendingMouseAction = 0;
            m_pendingMouseView = 2;
            InvalidateRect(&m_bounds);
            return true;

        case SelfLookSlot_Next:
            if (m_activeViewMode == ViewMode_Default)
                ShowSpelledView();
            else if (m_activeViewMode == ViewMode_Spelled)
                DeactivateView();
            m_pendingMouseAction = 2;
            m_pendingMouseView = 0;
            InvalidateRect(&m_bounds);
            return true;

        case SelfLookSlot_TopOption:
            g_pGeneralPurposePanel->GetActiveChildPane(6);
            SendSelfLookPanelCommand(14);
            return true;

        case SelfLookSlot_BottomOption:
            g_pGeneralPurposePanel->GetActiveChildPane(6);
            SendSelfLookPanelCommand(15);
            return true;

        case SelfLookEquipmentSlot_Head:
            SendTakeOffPacket(4);
            return true;
        case SelfLookEquipmentSlot_Body:
            SendTakeOffPacket(2);
            return true;
        case SelfLookEquipmentSlot_LeftHand:
            SendTakeOffPacket(3);
            return true;
        case SelfLookEquipmentSlot_RightHand:
            SendTakeOffPacket(1);
            return true;
        case SelfLookEquipmentSlot_FaceAccessory1:
            SendTakeOffPacket(22);
            return true;
        case SelfLookEquipmentSlot_LeftAccessory:
            SendTakeOffPacket(7);
            return true;
        case SelfLookEquipmentSlot_RightAccessory:
            SendTakeOffPacket(8);
            return true;
        case SelfLookEquipmentSlot_LeftSubAccessory:
            SendTakeOffPacket(20);
            return true;
        case SelfLookEquipmentSlot_RightSubAccessory:
            SendTakeOffPacket(21);
            return true;
        case SelfLookEquipmentSlot_HeadAccessory2:
            SendTakeOffPacket(23);
            return true;
        case SelfLookEquipmentSlot_Mantle:
            SendTakeOffPacket(14);
            return true;
        case SelfLookEquipmentSlot_Necklace:
            SendTakeOffPacket(6);
            return true;
        case SelfLookEquipmentSlot_Foot:
            SendTakeOffPacket(13);
            return true;
        case SelfLookEquipmentSlot_Coat:
            SendTakeOffPacket(16);
            return true;
        default:
            return false;
        }

        m_lastSelfLookOptionTick = g_clientTickCounter->m_tickCount;
        return true;
    }

    if (event->button != PanelMouseButton_Move)
        return false;

    if (!PointInRect(event->x, event->y, &m_bounds)) {
        m_pendingMouseAction = 0;
        m_pendingMouseView = 0;
        return false;
    }

    UpdateHoverButtonState(event->x, event->y);
    m_hoverSlotStateValue = 0;
    m_hoverSlotStateValue2 = 0;
    m_hoverSlotStateFlag = 0;

    if (m_activeViewMode == ViewMode_Default) {
        const unsigned short hoverSlot =
            HitTestSlot(event->x, event->y);
        if (hoverSlot != 0xffff &&
            hoverSlot >= SelfLookEquipmentSlot_FaceAccessory1 &&
            hoverSlot <= SelfLookEquipmentSlot_Foot) {
            if (g_selfLookLastHoverEquipmentSlotId != hoverSlot) {
                m_hoverTimer.RemovePendingTimers();
                m_hoverTimer.ScheduleTimer(hoverSlot,
                                           1000,
                                           event->y,
                                           event->x);
            }
            g_selfLookLastHoverEquipmentSlotId = hoverSlot;
            m_equipmentSlotHoverStates[hoverSlot] = true;
            InvalidateRect(&m_bounds);
        }
    }

    return true;
}

// UID:0003QQ | by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md | Completion:88 | Confidence:91
bool SelfLookPane::OnPacketEvent(const PanelPacketEvent *event)
{
    const unsigned char *packet = event->packet;

    switch (packet[0]) {
    case 0x08:
        return ApplySelfLookSummaryRecord(packet);

    case 0x1d:
        return ApplySelfLookRectStateRecord(packet);

    case 0x33:
        return ApplySelfLookRectRecord(packet);

    case 0x37:
        return ApplyEquipmentSlotRecord(packet);

    case 0x38:
        return ClearEquipmentSlotRecord(packet);

    case 0x39:
        OnReceiveCharacterData(packet);
        return true;

    case 0x3a:
        return DispatchSpelledText(packet);

    default:
        return false;
    }
}




// UID:0003QU | by-memory/0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md | Completion:92 | Confidence:93
void SelfLookPane::DrawNumberString(const wchar_t *text,
                                    int x,
                                    int y,
                                    unsigned char glyphSet)
{
    EPFTileContext glyphContext;
    EPFTileContext symbolContext;
    RectBounds sourceBounds;
    RectBounds destinationBounds;

    glyphContext.rowStridePixels = 9;

    InitRectBounds(&sourceBounds, 0, 0, 9, 11);
    InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

    while (*text != L'\0') {
        if (*text == L'-') {
            g_pEPFLib->LookupLayoutEntry(L"FONTSYMB.EPF",
                                         4,
                                         &symbolContext);
            OffsetRect(&destinationBounds,
                       symbolContext.bounds.left,
                       symbolContext.bounds.top);
            RenderTileFrame(&symbolContext,
                            &symbolContext.bounds,
                            &destinationBounds,
                            1,
                            L"FONTSYMB.PAL",
                            NULL);
            OffsetRect(&destinationBounds,
                       -symbolContext.bounds.left,
                       -symbolContext.bounds.top);
        } else if (*text != L' ' && *text != L'/') {
            glyphContext.pixelData =
                m_statDigitFrames +
                99 * (*text + 10 * glyphSet - 47);
            g_pfnBlitSprite(this,
                            &glyphContext,
                            &sourceBounds,
                            &destinationBounds,
                            1,
                            NULL,
                            NULL);
        }

        ++text;
        OffsetRect(&destinationBounds, 9, 0);
    }
}

// UID:0003QV | by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md | Completion:92 | Confidence:94
void SelfLookPane::GetSlotRect(short slotId, RectBounds *bounds) const
{
    bool applyExtendedOffset = false;

    switch (slotId) {
    case SelfLookSlot_Face:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 126, 228, 153, 255);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Body:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 155, 228, 182, 255);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Stats:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 126, 256, 153, 283);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Previous:
        if (m_activeViewMode == ViewMode_Spelled)
            InitRectBounds(bounds, 149, 268, 167, 286);
        else if (m_activeViewMode == ViewMode_Legend)
            InitRectBounds(bounds, 169, 268, 187, 286);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Next:
        if (static_cast<unsigned int>(m_activeViewMode) <
            static_cast<unsigned int>(ViewMode_Legend))
            InitRectBounds(bounds, 169, 268, 187, 286);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_TopOption:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 107, 7, 121, 21);
        applyExtendedOffset = true;
        break;

    case SelfLookSlot_BottomOption:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 49, 221, 63, 235);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookEquipmentSlot_FaceAccessory1:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 12, 12, 60, 60);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Head:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 12, 116, 60);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_HeadAccessory2:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 12, 174, 60);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_RightHand:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 68, 58, 116);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Body:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 68, 116, 116);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_LeftHand:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 68, 174, 116);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_RightAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 122, 58, 170);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Mantle:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 122, 116, 170);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_LeftAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 122, 174, 170);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_LeftSubAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 174, 58, 222);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Coat:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 174, 116, 222);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_RightSubAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 174, 174, 222);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Necklace:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 226, 58, 274);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Foot:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 226, 116, 274);
        applyExtendedOffset = true;
        break;

    default:
        InitRectBounds(bounds, -1, -1, -1, -1);
        return;
    }

    if (applyExtendedOffset && m_viewCacheToggle)
        OffsetRect(bounds, 2, 272);
}

// UID:0003QW | by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md | Completion:91 | Confidence:93
unsigned short SelfLookPane::HitTestSlot(int x, int y) const
{
    for (short slotId = SelfLookSlot_Face;
         slotId <= SelfLookEquipmentSlot_Foot;
         ++slotId) {
        RectBounds bounds;
        GetSlotRect(slotId, &bounds);
        if (PointInRect(x, y, &bounds))
            return static_cast<unsigned short>(slotId);
    }

    return 0xffff;
}

// UID:0002RA | by-memory/0x0056a380-0x0056a4f4.SelfLookPanePacketSendRawHelpers.md | Completion:87 | Confidence:90
bool SelfLookPane::SendSelfLookOptionRequest(unsigned char optionSubtype)
{
    unsigned char packet[5];
    PacketBufferWriteByte(packet + 0, 0x1b);
    PacketBufferWriteByte(packet + 1, 0x01);
    PacketBufferWriteByte(packet + 2, optionSubtype);
    PacketBufferWriteByte(packet + 3, 0x00);
    packet[4] = 0;

    QueueAndSendPacket(g_packetSender, packet, 4);
    return false;
}

void SelfLookPane::SendSelfLookOption02Raw()
{
    SendSelfLookOptionRequest(0x02);
}

void SelfLookPane::SendSelfLookOption08Raw()
{
    SendSelfLookOptionRequest(0x08);
}

void SelfLookPane::SendSelfLookOption0bRaw()
{
    SendSelfLookOptionRequest(0x0b);
}

// UID:0002RB | by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md | Completion:87 | Confidence:90
bool SelfLookPane::ApplySelfLookRectRecord(const unsigned char *packet)
{
    PacketBufferReadUInt16BE(packet + 1);
    PacketBufferReadUInt16BE(packet + 3);

    if (PacketBufferReadUInt32BE(packet + 6) != g_pCollectionData->m_selectedObjectKey)
        return false;

    const unsigned char mode = packet[10];
    ObjectStatusBlob decoded;
    if (mode == 0)
        decoded.ParseFullStatus(packet + 11);
    else if (mode == 1)
        decoded.ParsePartialStatus(packet + 11);
    else
        return false;

    m_selfLookObjectStatus = decoded;
    InvalidateRect(&m_bounds);
    return false;
}

bool SelfLookPane::ApplySelfLookRectStateRecord(const unsigned char *packet)
{
    if (PacketBufferReadUInt32BE(packet + 1) != g_pCollectionData->m_selectedObjectKey)
        return false;

    const unsigned char mode = packet[5];
    if (mode == 0)
        m_selfLookObjectStatus.ParseFullStatus(packet + 6);
    else if (mode == 1)
        m_selfLookObjectStatus.ParsePartialStatus(packet + 6);
    else
        return false;

    InvalidateRect(&m_bounds);
    return false;
}

// UID:0002RC | by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md | Completion:90 | Confidence:92
bool SelfLookPane::ApplyEquipmentSlotRecord(const unsigned char *packet)
{
    enum {
        SelfLookEquipmentSelector_RightHand = 1,
        SelfLookEquipmentSelector_Body = 2,
        SelfLookEquipmentSelector_LeftHand = 3,
        SelfLookEquipmentSelector_Head = 4,
        SelfLookEquipmentSelector_Necklace = 6,
        SelfLookEquipmentSelector_LeftAccessory = 7,
        SelfLookEquipmentSelector_RightAccessory = 8,
        SelfLookEquipmentSelector_Foot = 13,
        SelfLookEquipmentSelector_Mantle = 14,
        SelfLookEquipmentSelector_Coat = 16,
        SelfLookEquipmentSelector_LeftSubAccessory = 20,
        SelfLookEquipmentSelector_RightSubAccessory = 21,
        SelfLookEquipmentSelector_FaceAccessory1 = 22,
        SelfLookEquipmentSelector_HeadAccessory2 = 23
    };

    enum {
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    const unsigned char selector = packet[1];
    const unsigned short itemId = PacketBufferReadUInt16BE(packet + 2);
    const unsigned char recordState = packet[4];
    char text[256];

#define APPLY_SELF_LOOK_EQUIPMENT_SLOT(SLOT_ID)                                      \
    do {                                                                             \
        m_equipmentSlotItemIds[SLOT_ID] = itemId;                                    \
        m_equipmentSlotRecordStates[SLOT_ID] = recordState;                          \
        const unsigned char *cursor = packet + 5;                                    \
        unsigned int textLength = *cursor++;                                         \
        memmove(text, cursor, textLength);                                           \
        text[textLength] = '\0';                                                     \
        int converted = MultiByteToWideChar(0, 0, text, textLength,                  \
                                            m_equipmentSlotNames[SLOT_ID], 256);     \
        m_equipmentSlotNames[SLOT_ID][converted] = L'\0';                            \
        cursor += textLength;                                                        \
                                                                                     \
        textLength = *cursor++;                                                      \
        memmove(text, cursor, textLength);                                           \
        text[textLength] = '\0';                                                     \
        converted = MultiByteToWideChar(0, 0, text, textLength,                      \
                                        m_equipmentSlotDescriptions[SLOT_ID], 256);  \
        m_equipmentSlotDescriptions[SLOT_ID][converted] = L'\0';                     \
        cursor += textLength;                                                        \
                                                                                     \
        m_equipmentSlotValues[SLOT_ID] = PacketBufferReadUInt32BE(cursor);           \
        m_equipmentSlotValueFlags[SLOT_ID] = cursor[4];                              \
    } while (0)

    switch (selector) {
    case SelfLookEquipmentSelector_RightHand:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_RightHand);
        break;
    case SelfLookEquipmentSelector_Body:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Body);
        break;
    case SelfLookEquipmentSelector_LeftHand:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_LeftHand);
        break;
    case SelfLookEquipmentSelector_Head:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Head);
        break;
    case SelfLookEquipmentSelector_Necklace:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Necklace);
        break;
    case SelfLookEquipmentSelector_LeftAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_LeftAccessory);
        break;
    case SelfLookEquipmentSelector_RightAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_RightAccessory);
        break;
    case SelfLookEquipmentSelector_Foot:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Foot);
        break;
    case SelfLookEquipmentSelector_Mantle:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Mantle);
        break;
    case SelfLookEquipmentSelector_Coat:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Coat);
        break;
    case SelfLookEquipmentSelector_LeftSubAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_LeftSubAccessory);
        break;
    case SelfLookEquipmentSelector_RightSubAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_RightSubAccessory);
        break;
    case SelfLookEquipmentSelector_FaceAccessory1:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_FaceAccessory1);
        break;
    case SelfLookEquipmentSelector_HeadAccessory2:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_HeadAccessory2);
        break;
    default:
        break;
    }

#undef APPLY_SELF_LOOK_EQUIPMENT_SLOT

    InvalidateRect(&m_bounds);
    return false;
}

// UID:0002RD | by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md | Completion:87 | Confidence:90
bool SelfLookPane::ClearEquipmentSlotRecord(const unsigned char *packet)
{
    switch (packet[1]) {
    case 1:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_RightHand] = 0;
        break;
    case 2:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_Body] = 0;
        break;
    case 3:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_LeftHand] = 0;
        break;
    case 4:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_Head] = 0;
        break;
    case 6:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_Necklace] = 0;
        break;
    case 7:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_LeftAccessory] = 0;
        break;
    case 8:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_RightAccessory] = 0;
        break;
    case 13:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_Foot] = 0;
        break;
    case 14:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_Mantle] = 0;
        break;
    case 16:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_Coat] = 0;
        break;
    case 20:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_LeftSubAccessory] = 0;
        break;
    case 21:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_RightSubAccessory] = 0;
        break;
    case 22:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_FaceAccessory1] = 0;
        break;
    case 23:
        m_equipmentSlotItemIds[SelfLookEquipmentSlot_HeadAccessory2] = 0;
        break;
    default:
        break;
    }

    InvalidateRect(&m_bounds);
    return false;
}

// UID:0002RE | by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md | Completion:90 | Confidence:92
bool SelfLookPane::ApplySelfLookSummaryRecord(const unsigned char *packet)
{
    const unsigned char mask = packet[1];

    unsigned int compare0 = m_summaryCompareKey0;
    unsigned int compare1 = m_summaryCompareKey1;
    unsigned int tailValue = m_summaryTailValue;
    unsigned char tailByte0 = m_summaryTailByte0;
    unsigned char tailByte1 = m_summaryTailByte1;
    unsigned char tailByte2 = m_summaryTailByte2;
    unsigned short cursor = 2;

    if ((mask & 0x40) != 0) {
        compare0 = PacketBufferReadUInt32BE(packet + 7);
        compare1 = PacketBufferReadUInt32BE(packet + 11);
        cursor = 0x1f;
    }

    if ((mask & 0x20) != 0) {
        cursor += 8;
    }
    if ((mask & 0x10) != 0) {
        cursor += 9;
    }
    if ((mask & 0x08) != 0) {
        cursor += 11;
    }

    if ((mask & 0x01) != 0) {
        tailValue = PacketBufferReadUInt32BE(packet + cursor);
        tailByte0 = packet[cursor + 4];
        tailByte1 = packet[cursor + 5];
        tailByte2 = packet[cursor + 6];
    }

    bool dirty = compare0 != m_summaryCompareKey0 ||
                 compare1 != m_summaryCompareKey1;

    if (tailValue != m_summaryTailValue) {
        m_summaryTailValue = tailValue;
        dirty = true;
    }
    if (tailByte0 != m_summaryTailByte0) {
        m_summaryTailByte0 = tailByte0;
        dirty = true;
    }
    if (tailByte1 != m_summaryTailByte1) {
        m_summaryTailByte1 = tailByte1;
        dirty = true;
    }
    if (tailByte2 != m_summaryTailByte2) {
        m_summaryTailByte2 = tailByte2;
        dirty = true;
    }

    if (dirty) {
        InvalidateRect(&m_bounds);
    }

    return false;
}

// UID:0002RF | by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md | Completion:88 | Confidence:92
bool SelfLookPane::DispatchSpelledText(const unsigned char *packet)
{
    int cursor = 1;

    StringBase text;
    PacketBufferReadAnsiString8(&text, packet, &cursor);

    const int value = PacketBufferReadUInt32BE(packet, &cursor);
    if (value == 0)
        m_spelledPane->RemoveEntry(text.c_str(), 0);
    else
        m_spelledPane->AddOrUpdateEntry(text.c_str(), value, 0);

    return false;
}

// UID:0002RG | by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md | Completion:89 | Confidence:92
void SelfLookPane::ToggleSelfLookViewCache()
{
    m_viewCacheToggle = m_viewCacheToggle == 0;

    OnViewCacheToggleChanged();

    RectBounds attachRect;
    GetChildAttachRect(&attachRect, 0);
    AttachToLayer(&attachRect, 0, g_pBackPane, MainUiLayerSlots);
    InvalidateRect(&m_bounds);

    if (m_activeViewMode == ViewMode_Default) {
        memset(m_equipmentSlotHoverStates +
                   SelfLookEquipmentSlot_FaceAccessory1,
               0,
               SelfLookEquipmentSlot_Foot -
                   SelfLookEquipmentSlot_FaceAccessory1 + 1);
        m_identityLine1[0] = L'\0';
    } else if (m_activeViewMode == ViewMode_Legend) {
        m_legendPane->RefreshScrollState();
    }
}


// UID:0000CV | by-class/SelfLookPane2.md | Completion:94 | Confidence:94
class SelfLookPane2 : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    enum ButtonId
    {
        ButtonId_Look = 0,
        ButtonId_Equipment = 1,
        ButtonId_Stats = 2,
        ButtonId_Previous = 3,
        ButtonId_Next = 4
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

    SelfLookPane2();
    virtual ~SelfLookPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void SendToggleLook();
    void SendToggleEquip();
    void SendToggleStats();
    void ShowDefaultView();
    void ShowSpelledView();
    void ShowProfileView();
    void ShowLegendView();
    void DrawStatText(const wchar_t *text,
                      int x,
                      int y,
                      bool alternateSet);
    void GetButtonRect(short buttonId, RectBounds *bounds) const;
    short HitTestButton(int y, int x) const;

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_objectStatus;

    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_displayValueA;
    unsigned int m_displayValueB;
    unsigned char m_activationState0;
    unsigned char m_activationState1;
    unsigned char m_activationState2;
    unsigned int m_activationValue;
    unsigned int m_lastToggleTick;
    unsigned int m_toggleRepeatDelay;
    unsigned char m_equipmentToggleState;
    unsigned char m_lookToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_viewMode;
    int m_profileState;
    int m_reservedViewState;
    ButtonFrame m_nextButtonFrame;
    ButtonFrame m_previousButtonFrame;
};



// UID:0003QZ | by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md | Completion:92 | Confidence:94
namespace
{
static __forceinline unsigned char ReadSelfLookPane2Text(
    const unsigned char *packetData,
    int &offset,
    char *multibyteText,
    wchar_t *text,
    int capacity)
{
    const unsigned char byteCount = packetData[offset++];
    memmove(multibyteText, packetData + offset, byteCount);
    multibyteText[byteCount] = 0;
    const unsigned char length = static_cast<unsigned char>(
        MultiByteToWideChar(CP_ACP,
                            0,
                            multibyteText,
                            byteCount,
                            text,
                            capacity));
    text[length] = 0;
    offset += byteCount;
    return length;
}
}

void SelfLookPane2::OnActivate(const unsigned char *packetData)
{
    int offset = 1;
    wchar_t identityLine1[256];
    wchar_t statusLineA[256];
    wchar_t auxiliaryText[256];
    wchar_t statusLineB[256];
    wchar_t spelledText[256];
    wchar_t legendText[256];
    char multibyteText[256];

    m_activationState0 = packetData[offset++];
    m_activationState1 = packetData[offset++];
    m_activationState2 = packetData[offset++];

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          identityLine1,
                          256);

    const unsigned char identityLine2ByteCount = packetData[offset++];
    const int identityLine2Length =
        MultiByteToWideChar(CP_ACP,
                            0,
                            reinterpret_cast<const char *>(packetData + offset),
                            identityLine2ByteCount,
                            m_identityLine2,
                            255);
    m_identityLine2[identityLine2Length] = 0;
    offset += identityLine2ByteCount;

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          statusLineA,
                          256);
    g_activeUserStatusPane->SetDisplayLineA(statusLineA);

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          auxiliaryText,
                          256);
    m_equipmentToggleState = packetData[offset++];

    m_activationValue = PacketBufferReadUInt32BE(packetData + offset);
    offset += 4;

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          statusLineB,
                          256);
    g_activeUserStatusPane->SetDisplayLineB(statusLineB);

    const unsigned short headId = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char headPalette = packetData[offset++];

    const unsigned short leftAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char leftAccessoryPalette = packetData[offset++];

    const unsigned short rightAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char rightAccessoryPalette = packetData[offset++];

    const unsigned short leftSubAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned short rightSubAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char leftSubAccessoryPalette = packetData[offset++];
    const unsigned char rightSubAccessoryPalette = packetData[offset++];

    const unsigned char spelledLength =
        ReadSelfLookPane2Text(packetData,
                              offset,
                              multibyteText,
                              spelledText,
                              256);
    for (unsigned char index = 0; index < spelledLength; ++index)
    {
        if (spelledText[index] == L'\t')
            spelledText[index] = L'\n';
    }

    m_lookToggleState = packetData[offset++];
    m_statsToggleState = packetData[offset++];

    g_pLocalPlayer->GetSpriteConfig(&m_objectStatus);

    m_headId = headId;
    m_headPalette = headPalette;
    m_leftAccessoryId = leftAccessoryId;
    m_leftAccessoryPalette = leftAccessoryPalette;
    m_rightAccessoryId = rightAccessoryId;
    m_rightAccessoryPalette = rightAccessoryPalette;
    m_leftSubAccessoryId = leftSubAccessoryId;
    m_rightSubAccessoryId = rightSubAccessoryId;
    m_leftSubAccessoryPalette = leftSubAccessoryPalette;
    m_rightSubAccessoryPalette = rightSubAccessoryPalette;

    wcscpy_s(m_identityLine1, 256, identityLine1);
    wcscpy_s(m_statusLineA, 256, statusLineA);
    wcscpy_s(m_statusLineB, 128, statusLineB);
    g_activeUserStatusPane->CopyNameLineA(m_statusName, 128);
    m_displayValueA = g_activeUserStatusPane->GetDisplayValueA();
    m_displayValueB = g_activeUserStatusPane->GetDisplayValueB();
    wcscpy_s(m_auxiliaryText, 256, auxiliaryText);
    wcscpy_s(m_spelledSourceText, 256, spelledText);

    m_spelledPane->ParseAndLoadEntries(m_spelledSourceText,
                                       static_cast<int>(wcslen(m_spelledSourceText)));

    m_legendPane->ClearText();
    m_legendPane->SetEditActiveState(true, false);

    const unsigned short legendEntryCount =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    short legendTextOffset = 0;

    for (unsigned short entry = 0; entry < legendEntryCount; ++entry)
    {
        const unsigned char symbolIndex = packetData[offset++];
        const unsigned char textColor = packetData[offset++];
        short legendLength =
            ReadSelfLookPane2Text(packetData,
                                  offset,
                                  multibyteText,
                                  legendText,
                                  256);
        legendText[legendLength++] = L'\r';
        legendText[legendLength] = 0;

        EPFTextEditObject *symbol =
            new EPFTextEditObject(m_legendPane, symbolIndex);
        m_legendPane->InsertText(L" ", 0);
        m_legendPane->InsertEmbeddedObject(symbol, 12, 12);

        const short textStart = static_cast<short>(legendTextOffset + 2);
        m_legendPane->SetText(legendText, legendLength, 0, 0);
        const short textEnd = static_cast<short>(textStart + legendLength);

        unsigned int formatData[3] = { 0, textColor, 0 };
        m_legendPane->SetSelectionRange(textStart, textEnd);
        m_legendPane->ApplySelectionFormat(2, formatData);
        m_legendPane->SetSelectionRange(textEnd, textEnd);
        legendTextOffset = textEnd;
    }

    m_legendPane->SetEditActiveState(false, false);
    m_profileState = 0;

    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    m_spelledPane->RefreshScrollState();

    if (m_viewMode == ViewMode_Spelled)
        ShowSpelledView();
    else if (m_viewMode == ViewMode_Legend)
        ShowLegendView();
}

// UID:0003R1 | by-memory/0x00570940-0x005709fa.SelfLookPane2SendToggleLookRaw.md | Completion:91 | Confidence:93
void SelfLookPane2::SendToggleLook()
{
    if (g_pTimerMgr->m_currentTick <=
        m_lastToggleTick + m_toggleRepeatDelay)
    {
        return;
    }

    m_lookToggleState = m_lookToggleState == 0;

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x1b, packet + 0);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt8(0x08, packet + 2);
    PacketBufferWriteUInt8(0x00, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);

    RectBounds buttonBounds;
    GetButtonRect(ButtonId_Look, &buttonBounds);

    m_lastToggleTick = g_pTimerMgr->m_currentTick;
}

// UID:0003R2 | by-memory/0x00570a00-0x00570aba.SelfLookPane2SendToggleEquipRaw.md | Completion:91 | Confidence:93
void SelfLookPane2::SendToggleEquip()
{
    if (g_pTimerMgr->m_currentTick <=
        m_lastToggleTick + m_toggleRepeatDelay)
    {
        return;
    }

    m_equipmentToggleState = m_equipmentToggleState == 0;

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x1b, packet + 0);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt8(0x02, packet + 2);
    PacketBufferWriteUInt8(0x00, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);

    RectBounds buttonBounds;
    GetButtonRect(ButtonId_Equipment, &buttonBounds);

    m_lastToggleTick = g_pTimerMgr->m_currentTick;
}

// UID:0003R3 | by-memory/0x00570ac0-0x00570b7a.SelfLookPane2SendToggleStatsRaw.md | Completion:89 | Confidence:92
void SelfLookPane2::SendToggleStats()
{
    if (g_pTimerMgr->m_currentTick <=
        m_lastToggleTick + m_toggleRepeatDelay)
    {
        return;
    }

    m_statsToggleState = m_statsToggleState == 0;

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x1b, packet + 0);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt8(0x0b, packet + 2);
    PacketBufferWriteUInt8(0x00, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);

    RectBounds buttonBounds;
    GetButtonRect(ButtonId_Stats, &buttonBounds);

    m_lastToggleTick = g_pTimerMgr->m_currentTick;
}





// UID:0003R8 | by-memory/0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView.md | Completion:91 | Confidence:94
void SelfLookPane2::ShowDefaultView()
{
    m_viewMode = ViewMode_Default;

    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();

    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();

    RectBounds defaultBounds;
    InitRectBounds(&defaultBounds, 17, 192, 174, 251);

    InvalidateRect(&m_bounds);
}

// UID:0003R9 | by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md | Completion:92 | Confidence:94
void SelfLookPane2::ShowSpelledView()
{
    m_viewMode = ViewMode_Spelled;

    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();

    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();

    RectBounds spelledBounds;
    InitRectBounds(&spelledBounds, 3, 162, 183, 245);

    const unsigned short currentPosition =
        m_spelledPane->GetScrollPosition(0);
    m_spelledPane->ApplyScrollPosition(0, currentPosition, 0);
    m_spelledPane->AddToLayer(&spelledBounds,
                              0,
                              this,
                              g_mainUiLayerSlots.rootPaneLayerContext);
    m_spelledPane->SetPaneOrder(0, this);

    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > text =
        m_spelledPane->GetText();
    text.TrimLeftWide(L" \t\n\r");
    text.TrimRightWide(L" \t\n\r");

    m_spelledPane->ClearText();
    m_spelledPane->SetText(text.c_str(),
                           static_cast<short>(text.length()),
                           0,
                           0);
    m_spelledPane->SetSelectionRange(0, 0);
    m_spelledPane->SyncScrollbars();

    RectBounds textAreaBounds;
    m_spelledPane->GetTextAreaBounds(&textAreaBounds);
    textAreaBounds.Offset(0, -textAreaBounds.top);
    m_spelledPane->SetTextAreaBounds(&textAreaBounds);

    InvalidateRect(&m_bounds);
}

// UID:0004NA | by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md | Completion:89 | Confidence:92
void SelfLookPane2::ShowProfileView()
{
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();

    m_profilePane->UnregisterEventHandler();
    m_profilePane->RemoveFromLayer();

    RectBounds profileBounds;
    InitRectBounds(&profileBounds, 17, 36, 174, 131);

    const unsigned short currentPosition =
        m_profilePane->GetScrollPosition(0);
    m_profilePane->ApplyScrollPosition(0, currentPosition, 0);
    m_profilePane->AddToLayer(&profileBounds,
                              0,
                              this,
                              g_mainUiLayerSlots.rootPaneLayerContext);
    m_profilePane->SetPaneOrder(0, this);
    InvalidateRect(&m_bounds);
}

// UID:0003RA | by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md | Completion:91 | Confidence:94
void SelfLookPane2::ShowLegendView()
{
    m_viewMode = ViewMode_Legend;

    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();

    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();

    RectBounds legendBounds;
    InitRectBounds(&legendBounds, 3, 10, 183, 239);

    const unsigned short currentPosition =
        m_legendPane->GetScrollPosition(0);
    m_legendPane->ApplyScrollPosition(0, currentPosition, 0);
    m_legendPane->AddToLayer(&legendBounds,
                             0,
                             this,
                             g_mainUiLayerSlots.rootPaneLayerContext);
    m_legendPane->SetPaneOrder(0, this);

    InvalidateRect(&m_bounds);
}

// UID:0003RB | by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md | Completion:93 | Confidence:94
void SelfLookPane2::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds overlayBounds;
    RectBounds destinationBounds;
    RectBounds buttonBounds;
    RectBounds statBounds;
    wchar_t statText[128];

    DLPalette *palette = g_pPaletteLib->GetPaletteByName(L"SELFLOOK.PAL");

    if (m_viewMode == ViewMode_Default ||
        m_viewMode == ViewMode_Spelled ||
        m_viewMode == ViewMode_Legend)
    {
        g_pEPFLib->LookupLayoutEntry(L"SELFLOOK.EPF",
                                     m_viewMode,
                                     &tileContext);
    }

    g_pfnBlitSprite(this,
                     &tileContext,
                     &tileContext.bounds,
                     &m_bounds,
                     0,
                     palette,
                     NULL);

    if (m_viewMode == ViewMode_Default)
    {
        if (m_objectStatus.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            g_pNewHumanImageLib->CalculateBounds(&m_objectStatus,
                                                 2,
                                                 0,
                                                 0,
                                                 &imageBounds,
                                                 0,
                                                 0,
                                                 1,
                                                 0);
            g_pNewHumanImageLib->ComputeOverlayBounds(&m_objectStatus,
                                                      2,
                                                      0,
                                                      0,
                                                      &overlayBounds,
                                                      0,
                                                      1);

            destinationBounds.bottom = 171;
            destinationBounds.top =
                171 - (imageBounds.bottom - imageBounds.top);
            destinationBounds.left = 80;
            destinationBounds.right =
                80 + (imageBounds.right - imageBounds.left);
            OffsetRect(&destinationBounds, overlayBounds.left, 0);
            destinationBounds.left +=
                imageBounds.left - overlayBounds.left;
            destinationBounds.right +=
                imageBounds.right - overlayBounds.right;

            g_pNewHumanImageLib->Draw(this,
                                      &destinationBounds,
                                      &m_objectStatus,
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
        else if (m_objectStatus.m_statusKind ==
                 ObjectStatusBlob::MonsterObject)
        {
            g_pMonsterImageLib->ComputeRenderBounds(&m_objectStatus,
                                                    7,
                                                    0,
                                                    &imageBounds,
                                                    NULL);

            const int width = imageBounds.right - imageBounds.left;
            const int halfWidthOffset = width / -2;
            destinationBounds.left = 93 + halfWidthOffset;
            destinationBounds.right = 117 + width + halfWidthOffset;
            destinationBounds.top = imageBounds.top + 140;
            destinationBounds.bottom = imageBounds.bottom + 140;

            g_pMonsterImageLib->RenderMonsterImage(this,
                                                   &destinationBounds,
                                                   &m_objectStatus,
                                                   7,
                                                   0,
                                                   0,
                                                   0,
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
            destinationBounds.top = 44 + halfHeight;
            destinationBounds.bottom =
                44 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_headId),
                                              m_headPalette,
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
            destinationBounds.left = 153 + halfWidth;
            destinationBounds.right =
                153 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 139 + halfHeight;
            destinationBounds.bottom =
                139 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftAccessoryId),
                m_leftAccessoryPalette,
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
            destinationBounds.left = 31 + halfWidth;
            destinationBounds.right =
                31 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 139 + halfHeight;
            destinationBounds.bottom =
                139 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightAccessoryId),
                m_rightAccessoryPalette,
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
            destinationBounds.left = 31 + halfWidth;
            destinationBounds.right =
                31 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 202 + halfHeight;
            destinationBounds.bottom =
                202 + (imageBounds.bottom - imageBounds.top) + halfHeight;
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
            destinationBounds.left = 84 + halfWidth;
            destinationBounds.right =
                84 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 202 + halfHeight;
            destinationBounds.bottom =
                202 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightSubAccessoryId),
                m_rightSubAccessoryPalette,
                NULL,
                0.0f);
        }

        g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                     5 * m_nextButtonFrame,
                                     &tileContext);
        GetButtonRect(ButtonId_Next, &buttonBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &buttonBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                     5 * m_previousButtonFrame + 1,
                                     &tileContext);
        GetButtonRect(ButtonId_Previous, &buttonBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &buttonBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        GetButtonRect(ButtonId_Look, &buttonBounds);
        if (m_lookToggleState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_lookToggleState ? 7 : 2,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetButtonRect(ButtonId_Equipment, &buttonBounds);
        if (m_equipmentToggleState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_equipmentToggleState ? 8 : 3,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetButtonRect(ButtonId_Stats, &buttonBounds);
        if (m_statsToggleState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
            return;
        }

        g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                     m_statsToggleState ? 9 : 4,
                                     &tileContext);
        return;
    }

    if (m_viewMode == ViewMode_Spelled)
    {
        SetTextColor(128);
        m_textDrawMode = 1;

        wcscpy_s(m_identityLine1,
                 256,
                 L"\ub3cc\uc544\uc628\ud6c4\ub808\uc2dc\ub9e8\ub274");
        MoveTo(59, 28);
        SetTextColor(128);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(58, 27);
        SetTextColor(37);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(57, 27);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));

        wcscpy_s(m_identityLine2,
                 256,
                 L"\ud3c9\ud654\uc758\uc218\ud638\uc790");
        MoveTo(59, 48);
        SetTextColor(128);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(58, 47);
        SetTextColor(37);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(57, 47);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));

        InitRectBounds(&statBounds, 26, 58, 56, 70);
        if (m_exposedRegion.IntersectsRect(&statBounds))
        {
            swprintf_s(statText,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatA()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(10 * wcslen(statText)) -
                        statBounds.left) /
                           2,
                       0);
            DrawStatText(statText, statBounds.left, statBounds.top, true);
        }

        InitRectBounds(&statBounds, 83, 58, 113, 70);
        if (m_exposedRegion.IntersectsRect(&statBounds))
        {
            swprintf_s(statText,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatB()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(10 * wcslen(statText)) -
                        statBounds.left) /
                           2,
                       0);
            DrawStatText(statText, statBounds.left, statBounds.top, true);
        }

        InitRectBounds(&statBounds, 140, 58, 170, 70);
        if (m_exposedRegion.IntersectsRect(&statBounds))
        {
            swprintf_s(statText,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatC()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(10 * wcslen(statText)) -
                        statBounds.left) /
                           2,
                       0);
            DrawStatText(statText, statBounds.left, statBounds.top, true);
        }
    }
    else if (m_viewMode != ViewMode_Legend)
    {
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                 5 * m_nextButtonFrame,
                                 &tileContext);
    GetButtonRect(ButtonId_Next, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"BUTTON.PAL",
                    NULL);

    g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                 5 * m_previousButtonFrame + 1,
                                 &tileContext);
    GetButtonRect(ButtonId_Previous, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"BUTTON.PAL",
                    NULL);
}

// UID:0003RC | by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool SelfLookPane2::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char translatedKey =
        g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown) {
        return false;
    }

    if (translatedKey == kPaneKeyPageUp) {
        if (event->m_payload.m_key.m_modifiers != 0) {
            return false;
        }

        if (m_viewMode == ViewMode_Legend) {
            ShowSpelledView();
        } else if (m_viewMode == ViewMode_Spelled) {
            ShowDefaultView();
        }

        return true;
    }

    if (translatedKey == kPaneKeyPageDown) {
        if (event->m_payload.m_key.m_modifiers != 0) {
            return false;
        }

        if (m_viewMode == ViewMode_Spelled) {
            ShowLegendView();
        } else if (m_viewMode == ViewMode_Default) {
            ShowSpelledView();
        }

        return true;
    }

    return false;
}

// UID:0003RD | by-memory/0x00571cc0-0x005720ff.SelfLookPane2HandlePointerOrMouseEvent.md | Completion:93 | Confidence:94
bool SelfLookPane2::HandlePointerOrMouseEvent(Event *event)
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

        RectBounds nextButtonBounds;
        RectBounds previousButtonBounds;
        GetButtonRect(ButtonId_Next, &nextButtonBounds);
        GetButtonRect(ButtonId_Previous, &previousButtonBounds);

        if (PointInRect(y, x, &nextButtonBounds))
        {
            m_nextButtonFrame = ButtonFrame_Hover;
            m_previousButtonFrame = ButtonFrame_Normal;
            InvalidateRect(&m_bounds);
            return true;
        }

        if (PointInRect(y, x, &previousButtonBounds))
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
        switch (HitTestButton(y, x))
        {
        case ButtonId_Look:
            if (m_lookToggleState != ButtonVisualState_Disabled)
                SendToggleLook();
            return true;

        case ButtonId_Equipment:
            if (m_equipmentToggleState != ButtonVisualState_Disabled)
                SendToggleEquip();
            return true;

        case ButtonId_Stats:
            return true;

        case ButtonId_Previous:
            if (m_viewMode == ViewMode_Legend)
                ShowSpelledView();
            else if (m_viewMode == ViewMode_Spelled)
                ShowDefaultView();

            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Pressed;
            InvalidateRect(&m_bounds);
            return true;

        case ButtonId_Next:
            if (m_viewMode == ViewMode_Default)
                ShowSpelledView();
            else if (m_viewMode == ViewMode_Spelled)
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
        const short buttonId = HitTestButton(y, x);

        delete g_pSimpleHelpPane;

        switch (buttonId)
        {
        case ButtonId_Look:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(197),
                this,
                x,
                y,
                5000);
            return true;

        case ButtonId_Equipment:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(198),
                this,
                x,
                y,
                5000);
            return true;

        case ButtonId_Stats:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(199),
                this,
                x,
                y,
                5000);
            return true;

        default:
            return false;
        }
    }

    default:
        return false;
    }
}

// UID:0003RE | by-memory/0x00572120-0x005725ed.SelfLookPane2HandlePacketEvent.md | Completion:92 | Confidence:94
bool SelfLookPane2::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(
            event->m_payload.m_packet.m_data);

    switch (packet[0])
    {
    case 0x08:
        return ApplySelfLookSummaryRecord(packet);

    case 0x1d:
        return ApplySelfLookRectStateRecord(packet);

    case 0x33:
        return ApplySelfLookRectRecord(packet);

    case 0x37:
        return ApplyEquipmentSlotRecord(packet);

    case 0x38:
        return ClearEquipmentSlotRecord(packet);

    case 0x39:
        OnActivate(packet);
        return true;

    case 0x3a:
        return DispatchSpelledText(packet);

    default:
        return false;
    }
}

// UID:0003RF | by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md | Completion:92 | Confidence:93
void SelfLookPane2::DrawStatText(const wchar_t *text,
                                 int x,
                                 int y,
                                 bool alternateSet)
{
    EPFTileContext glyphContext;
    RectBounds sourceBounds;
    RectBounds destinationBounds;

    glyphContext.rowStridePixels = 9;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);
    InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

    for (const wchar_t *current = text; *current != L'\0'; ++current)
    {
        if (*current != L' ' && *current != L'/')
        {
            glyphContext.pixelData =
                m_statDigitFrames +
                99 * (static_cast<unsigned short>(*current) +
                      10 * static_cast<int>(alternateSet) - 47);
            g_pfnBlitSprite(this,
                             &glyphContext,
                             &sourceBounds,
                             &destinationBounds,
                             1,
                             NULL,
                             NULL);
        }

        OffsetRect(&destinationBounds, 9, 0);
    }
}

// UID:0003RG | by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md | Completion:92 | Confidence:94
void SelfLookPane2::GetButtonRect(short buttonId, RectBounds *bounds) const
{
    int left = -1;
    int top = -1;
    int right = -1;
    int bottom = -1;

    switch (buttonId)
    {
    case ButtonId_Look:
        if (m_viewMode == ViewMode_Default)
        {
            left = 57;
            top = 246;
            right = 93;
            bottom = 282;
        }
        break;

    case ButtonId_Equipment:
        if (m_viewMode == ViewMode_Default)
        {
            left = 93;
            top = 246;
            right = 129;
            bottom = 282;
        }
        break;

    case ButtonId_Stats:
        if (m_viewMode == ViewMode_Default)
        {
            left = 129;
            top = 246;
            right = 165;
            bottom = 282;
        }
        break;

    case ButtonId_Previous:
        if (m_viewMode == ViewMode_Spelled ||
            m_viewMode == ViewMode_Legend)
        {
            left = 4;
            top = 247;
            right = 40;
            bottom = 283;
        }
        break;

    case ButtonId_Next:
        if (m_viewMode == ViewMode_Default)
        {
            left = 4;
            top = 247;
            right = 40;
            bottom = 283;
        }
        else if (m_viewMode == ViewMode_Spelled)
        {
            left = 42;
            top = 247;
            right = 78;
            bottom = 283;
        }
        break;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}

// UID:0003RH | by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md | Completion:92 | Confidence:94
short SelfLookPane2::HitTestButton(int y, int x) const
{
    for (short buttonId = ButtonId_Look;
         buttonId <= ButtonId_Next;
         ++buttonId)
    {
        RectBounds buttonBounds;
        GetButtonRect(buttonId, &buttonBounds);

        if (PointInRect(y, x, &buttonBounds))
            return buttonId;
    }

    return -1;
}


// UID:0004Q0 | by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md | Completion:91 | Confidence:93
bool SelfLookPane2::ApplySelfLookRectRecord(const unsigned char *packet)
{
    PacketBufferReadUInt16BE(packet + 1);
    PacketBufferReadUInt16BE(packet + 3);

    if (PacketBufferReadUInt32BE(packet + 6) != g_pUserPane->GetObjectId())
        return false;

    const unsigned char mode = packet[10];
    ObjectStatusBlob decoded;
    if (mode == 0)
        decoded.ParseFullStatus(packet + 11);
    else if (mode == 1)
        decoded.ParsePartialStatus(packet + 11);
    else
        return false;

    m_objectStatus = decoded;
    InvalidateRect(&m_bounds);
    return false;
}

// UID:0004Q1 | by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md | Completion:91 | Confidence:93
bool SelfLookPane2::ApplySelfLookRectStateRecord(const unsigned char *packet)
{
    if (PacketBufferReadUInt32BE(packet + 1) != g_pUserPane->GetObjectId())
        return false;

    const unsigned char mode = packet[5];
    if (mode == 0)
        m_objectStatus.ParseFullStatus(packet + 6);
    else if (mode == 1)
        m_objectStatus.ParsePartialStatus(packet + 6);
    else
        return false;

    InvalidateRect(&m_bounds);
    return false;
}

// UID:0004Q2 | by-memory/0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md | Completion:92 | Confidence:94
bool SelfLookPane2::ApplyEquipmentSlotRecord(const unsigned char *packet)
{
    enum EquipmentSelector
    {
        EquipmentSelector_Head = 4,
        EquipmentSelector_LeftAccessory = 7,
        EquipmentSelector_RightAccessory = 8,
        EquipmentSelector_LeftSubAccessory = 20,
        EquipmentSelector_RightSubAccessory = 21
    };

    const unsigned char selector = packet[1];
    const unsigned short itemId = PacketBufferReadUInt16BE(packet + 2);
    const unsigned char palette = packet[4];

    switch (selector)
    {
    case EquipmentSelector_Head:
        m_headId = itemId;
        m_headPalette = palette;
        break;

    case EquipmentSelector_LeftAccessory:
        m_leftAccessoryId = itemId;
        m_leftAccessoryPalette = palette;
        break;

    case EquipmentSelector_RightAccessory:
        m_rightAccessoryId = itemId;
        m_rightAccessoryPalette = palette;
        break;

    case EquipmentSelector_LeftSubAccessory:
        m_leftSubAccessoryId = itemId;
        m_leftSubAccessoryPalette = palette;
        break;

    case EquipmentSelector_RightSubAccessory:
        m_rightSubAccessoryId = itemId;
        m_rightSubAccessoryPalette = palette;
        break;

    default:
        break;
    }

    InvalidateRect(&m_bounds);
    return true;
}

// UID:0004Q3 | by-memory/0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md | Completion:92 | Confidence:94
bool SelfLookPane2::ClearEquipmentSlotRecord(const unsigned char *packet)
{
    enum EquipmentSelector
    {
        EquipmentSelector_Head = 4,
        EquipmentSelector_LeftAccessory = 7,
        EquipmentSelector_RightAccessory = 8,
        EquipmentSelector_LeftSubAccessory = 20,
        EquipmentSelector_RightSubAccessory = 21
    };

    switch (packet[1])
    {
    case EquipmentSelector_Head:
        m_headId = 0;
        break;

    case EquipmentSelector_LeftAccessory:
        m_leftAccessoryId = 0;
        break;

    case EquipmentSelector_RightAccessory:
        m_rightAccessoryId = 0;
        break;

    case EquipmentSelector_LeftSubAccessory:
        m_leftSubAccessoryId = 0;
        break;

    case EquipmentSelector_RightSubAccessory:
        m_rightSubAccessoryId = 0;
        break;

    default:
        break;
    }

    InvalidateRect(&m_bounds);
    return true;
}

// UID:0004Q4 | by-memory/0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md | Completion:91 | Confidence:93
bool SelfLookPane2::ApplySelfLookSummaryRecord(const unsigned char *packet)
{
    unsigned int displayValueA = m_displayValueA;
    unsigned int displayValueB = m_displayValueB;

    if ((packet[1] & 0x40) != 0)
    {
        displayValueA = PacketBufferReadUInt32BE(packet + 7);
        displayValueB = PacketBufferReadUInt32BE(packet + 11);
    }

    if (displayValueA != m_displayValueA ||
        displayValueB != m_displayValueB)
    {
        InvalidateRect(&m_bounds);
    }

    return false;
}

// UID:00039N | by-memory/0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch.md | Completion:90 | Confidence:93
bool SelfLookPane2::DispatchSpelledText(const unsigned char *packet)
{
    int cursor = 1;

    StringBase text;
    PacketBufferReadAnsiString8(&text, packet, &cursor);

    const int value = PacketBufferReadUInt32BE(packet, &cursor);
    if (value == 0)
        m_spelledPane->RemoveEntry(text.c_str(), 0);
    else
        m_spelledPane->AddOrUpdateEntry(text.c_str(), value, 0);

    return true;
}


// UID:0002CG | by-global/g_selfLookLastHoverEquipmentSlotId.md | Completion:88 | Confidence:91
static unsigned short g_selfLookLastHoverEquipmentSlotId = 0xffff;

// UID:0003EU | by-memory/0x00624788-0x006247f0.SelfLookPaneLookResourceStrings.md | Completion:90 | Confidence:92
// Covered by the LOOKEXT.EPF, LOOKEXT.PAL, SELFLOOK.EPF, and
// LOOKICON.PAL use-site literals in SelfLookPane::OnPaint().

// UID:0003EW | by-memory/0x00624804-0x006248cc.SelfLookPaneLookIconNationStrings.md | Completion:90 | Confidence:92
// Covered by the LOOKICON.EPF, STATBUTS.EPF, nation-name, and
// spirit-name use-site literals in SelfLookPane::OnPaint().

// UID:0003EY | by-memory/0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md | Completion:87 | Confidence:90
struct SelfLookEquipmentSlotLabel {
    unsigned short slotId;
    const wchar_t *label;
};

static const SelfLookEquipmentSlotLabel kSelfLookEquipmentSlotLabels[] = {
    { SelfLookEquipmentSlot_Head, L"Head(h)" },
    { SelfLookEquipmentSlot_Body, L"Body(a)" },
    { SelfLookEquipmentSlot_LeftHand, L"Lefthand(s)" },
    { SelfLookEquipmentSlot_RightHand, L"Righthand(w)" },
    { SelfLookEquipmentSlot_FaceAccessory1, L"Faceaccessory(1)" },
    { SelfLookEquipmentSlot_HeadAccessory2, L"Headaccessory(2)" },
    { SelfLookEquipmentSlot_LeftAccessory, L"Leftaccessory(l)" },
    { SelfLookEquipmentSlot_RightAccessory, L"Rightaccessory(r)" },
    { SelfLookEquipmentSlot_LeftSubAccessory, L"Subaccessory([)" },
    { SelfLookEquipmentSlot_RightSubAccessory, L"Subaccessory(r)" },
    { SelfLookEquipmentSlot_Mantle, L"Mantle(m)" },
    { SelfLookEquipmentSlot_Necklace, L"Necklace(n)" },
    { SelfLookEquipmentSlot_Foot, L"Foot(f)" },
    { SelfLookEquipmentSlot_Coat, L"Coat(c)" }
};




// UID:0003F7 | by-memory/0x00624be0-0x00624bf0.SelfLookPaneRectConstantsA.md | Completion:90 | Confidence:92
// Covered by SelfLookPane::OnPaint() local highlightLeft coordinates.

// UID:0003F9 | by-memory/0x00624c00-0x00624c10.SelfLookPaneRectConstantB.md | Completion:90 | Confidence:92
// Covered by SelfLookPane::OnPaint() local highlightTop coordinates.

// UID:0003FB | by-memory/0x00624c20-0x00624c60.SelfLookPaneRectConstantsC.md | Completion:90 | Confidence:92
// Covered by SelfLookPane::OnPaint() local highlightLeft and
// highlightTop coordinate arrays.

// UID:000283 | by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md | Completion:87 | Confidence:90
// Storage backing for g_selfLookLastHoverEquipmentSlotId lives at 0x0066fe40.
// The source declaration is emitted by [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md); 0x0066fe42-0x0066fe44 is alignment before the SpelledPane delimiter.

// UID:00038M | by-type/by-vtable/SelfLookPaneFamilyVtables.md | Completion:91 | Confidence:95
// Compiler-generated SelfLookPane and SelfLookPane2 RTTI and vtable data; no manual source arrays.

// UID:0003Q8 | by-memory\0x00565610-0x005657d2.SelfLookPaneConstructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003Q9 | by-memory\0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003QA | by-memory\0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QG | by-memory\0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003QJ | by-memory\0x00567200-0x00567280.SelfLookPaneResetAndRefresh.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003QK | by-memory\0x00567280-0x005672b0.SelfLookPaneActivateView.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QL | by-memory\0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QM | by-memory\0x00567380-0x00567472.SelfLookPaneDeactivateView.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QO | by-memory\0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QR | by-memory\0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QS | by-memory\0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003QT | by-memory\0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:00039F | by-memory\0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003QX | by-memory\0x0056fe80-0x0057002c.SelfLookPane2Constructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003QY | by-memory\0x00570030-0x005700d7.SelfLookPane2NonDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003R4 | by-memory\0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003R5 | by-memory\0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003R6 | by-memory\0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003R7 | by-memory\0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:00039L | by-memory\0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:00039E | by-memory\0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003F3 | by-memory\0x00624b74-0x00624b90.SelfLookPane2PaletteResourceString.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:0003F4 | by-memory\0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0003F5 | by-memory\0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md | Completion:90 | Confidence:92 | Empty Emitter Marker
