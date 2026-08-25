// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MZ
// Source by-file doc: by-file/RankingDialog.md
// UID:0000BL | by-class/RankingCategoryRecord.md | Completion:94 | Confidence:95
// UID:0002K0 | by-memory/0x0045bf60-0x0045bf63.RankingCategoryRecordGetListIndex.md | Completion:87 | Confidence:92
short RankingCategoryRecord::GetListIndex() const
{
    return m_listIndex;
}

// UID:0002K1 | by-memory/0x0045bf70-0x0045bf73.RankingCategoryRecordGetCategoryId.md | Completion:88 | Confidence:93
int RankingCategoryRecord::GetCategoryId() const
{
    return m_categoryId;
}

// UID:0002K2 | by-memory/0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode.md | Completion:94 | Confidence:95
int RankingCategoryRecord::GetStateCode() const
{
    return m_stateCode;
}

// UID:0002K3 | by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md | Completion:93 | Confidence:95
tm RankingCategoryRecord::GetStartTime() const
{
    return m_startTime;
}

// UID:0002K4 | by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md | Completion:93 | Confidence:95
tm RankingCategoryRecord::GetEndTime() const
{
    return m_endTime;
}

// UID:0002K5 | by-memory/0x0045bfd0-0x0045bfd3.RankingCategoryRecordGetTitleText.md | Completion:88 | Confidence:93
const wchar_t* RankingCategoryRecord::GetTitleText() const
{
    return m_title;
}

// UID:0002K6 | by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md | Completion:94 | Confidence:95
RankingUserEntry *RankingCategoryRecord::GetUserEntryAt(int index)
{
    int userEntryCount = static_cast<int>(m_userEntries.size());

    if (userEntryCount <= index)
        return NULL;

    return &m_userEntries[index];
}

// UID:0004YY | by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md | Completion:90 | Confidence:94
void RankingCategoryRecord::SetStateCode(int stateCode)
{
    m_stateCode = stateCode;
}

// UID:0002K7 | by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md | Completion:91 | Confidence:94
void RankingCategoryRecord::SetStartTimeFromPackedDateTime(int packedDate, int packedTime)
{
    m_startTime.tm_year = packedDate / 10000;
    m_startTime.tm_mon = (packedDate % 10000) / 100;
    m_startTime.tm_mday = packedDate % 100;

    m_startTime.tm_hour = packedTime / 10000;
    m_startTime.tm_min = (packedTime % 10000) / 100;
    m_startTime.tm_sec = packedTime % 100;
}

// UID:0002K8 | by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md | Completion:91 | Confidence:94
void RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime)
{
    m_endTime.tm_year = packedDate / 10000;
    m_endTime.tm_mon = (packedDate % 10000) / 100;
    m_endTime.tm_mday = packedDate % 100;

    m_endTime.tm_hour = packedTime / 10000;
    m_endTime.tm_min = (packedTime % 10000) / 100;
    m_endTime.tm_sec = packedTime % 100;
}

// UID:0002K9 | by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md | Completion:86 | Confidence:90
// [UID:0002K9] Source abstraction is resolved but this support-only callback does not
// promote a separately unaudited formal body for the append child.
// RankingCategoryRecord owns std::vector<RankingUserEntry> m_userEntries, and the
// source method is void AppendUserEntry(const RankingUserEntry& entry) with
// m_userEntries.push_back(entry). The observed +0x258/+0x25c/+0x260 stores,
// 0x4c-byte fixed copy, and sub_45D1B0 growth call are compiler-lowered vector work,
// not authored pointer fields or a source-visible helper API.

// UID:0002KA | by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md | Completion:94 | Confidence:95
void RankingCategoryRecord::ResetUserEntries()
{
    m_userEntries.clear();
    m_localPlayerRank = -1;
}






// UID:0000BK | by-class/RankingCategoryCollection.md | Completion:93 | Confidence:95
#include <windows.h>

#include "MemoryMan.h"
#include "RankingDialog.h"
#include "PacketBuffer.h"



// UID:0003WR | by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md | Completion:93 | Confidence:93
void RankingCategoryCollection::ParseCategoryListResponse(
    const unsigned char *packet)
{
    m_records.clear();

    short packetOffset = 4;
    const short categoryCount =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 2));
    wchar_t wideTitle[256] = { 0 };

    for (short categoryIndex = 0;
         categoryIndex < categoryCount;
         ++categoryIndex)
    {
        const int categoryId =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        const int startDate =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int startTime =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int endDate =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int endTime =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        const char stateCode =
            static_cast<char>(packet[packetOffset++]);
        const unsigned char titleLength = packet[packetOffset++];

        char narrowTitle[256];
        GetMemoryMan()->MemmoveWrapper(
            narrowTitle,
            packet + packetOffset,
            titleLength);
        packetOffset =
            static_cast<short>(packetOffset + titleLength);
        narrowTitle[titleLength] = '\0';

        const short wideTitleLength =
            static_cast<short>(
                static_cast<unsigned short>(
                    MultiByteToWideChar(
                        CP_ACP,
                        0,
                        narrowTitle,
                        titleLength,
                        wideTitle,
                        256)));
        wideTitle[wideTitleLength] = L'\0';

        RankingCategoryRecord category;
        category.SetListIndex(categoryIndex);
        category.SetCategoryId(categoryId);
        category.SetStartTimeFromPackedDateTime(startDate, startTime);
        category.SetEndTimeFromPackedDateTime(endDate, endTime);
        category.SetStateCode(stateCode);
        category.SetTitleText(wideTitle);
        m_records.push_back(category);
    }
}

// UID:0003WS | by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md | Completion:93 | Confidence:93
void RankingCategoryCollection::ParseInitialCategoryPageResponse(
    const unsigned char *packet)
{
    m_records.clear();

    short packetOffset = 4;
    const short categoryCount =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 2));
    wchar_t wideTitle[256] = { 0 };
    wchar_t wideName[256];
    char narrowText[256];

    for (short categoryIndex = 0;
         categoryIndex < categoryCount;
         ++categoryIndex)
    {
        const int categoryId =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        const int startDate =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int startTime =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int endDate =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int endTime =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        const char stateCode =
            static_cast<char>(packet[packetOffset++]);
        const unsigned char titleLength = packet[packetOffset++];

        GetMemoryMan()->MemmoveWrapper(
            narrowText,
            packet + packetOffset,
            titleLength);
        narrowText[titleLength] = '\0';
        packetOffset =
            static_cast<short>(packetOffset + titleLength);

        const int wideTitleLength =
            MultiByteToWideChar(
                CP_ACP,
                0,
                narrowText,
                titleLength,
                wideTitle,
                256);
        wideTitle[wideTitleLength] = L'\0';

        RankingCategoryRecord category;
        category.SetListIndex(categoryIndex);
        category.SetCategoryId(categoryId);
        category.SetStartTimeFromPackedDateTime(startDate, startTime);
        category.SetEndTimeFromPackedDateTime(endDate, endTime);
        category.SetStateCode(stateCode);
        category.SetTitleText(wideTitle);
        m_records.push_back(category);
    }

    const int selectedCategoryId =
        static_cast<int>(
            PacketBufferReadUInt32BE(packet + packetOffset));
    packetOffset += 4;

    RankingCategoryRecord *selectedRecord = 0;
    for (unsigned int categoryIndex = 0;
         categoryIndex < m_records.size();
         ++categoryIndex)
    {
        if (m_records[categoryIndex].GetCategoryId() == selectedCategoryId)
        {
            selectedRecord = &m_records[categoryIndex];
            break;
        }
    }

    if (selectedRecord == 0)
        return;

    m_selectedCategoryId = selectedCategoryId;
    selectedRecord->ResetUserEntries();

    const char hasLocalPlayer =
        static_cast<char>(packet[packetOffset++]);
    if (hasLocalPlayer > 0)
    {
        const int localPlayerRank =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int localPlayerScore =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const char localStateCode =
            static_cast<char>(packet[packetOffset++]);

        selectedRecord->m_loadedRowsCategoryId = selectedCategoryId;
        selectedRecord->m_localPlayerScore = localPlayerScore;
        selectedRecord->m_localPlayerRank = localPlayerRank;
        selectedRecord->SetStateCode(localStateCode);
    }

    const short rowCount =
        static_cast<short>(
            PacketBufferReadUInt16BE(packet + packetOffset));
    packetOffset += 2;

    for (short rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        const unsigned char nameLength = packet[packetOffset++];
        GetMemoryMan()->MemmoveWrapper(
            narrowText,
            packet + packetOffset,
            nameLength);
        narrowText[nameLength] = '\0';
        packetOffset =
            static_cast<short>(packetOffset + nameLength);

        const int wideNameLength =
            MultiByteToWideChar(
                CP_ACP,
                0,
                narrowText,
                nameLength,
                wideName,
                256);
        wideName[wideNameLength] = L'\0';

        const int rank =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int score =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        RankingUserEntry entry;
        entry.categoryId = selectedCategoryId;
        entry.score = -1;
        entry.rank = rank;
        wcscpy_s(entry.name, 32, wideName);
        entry.score = score;
        selectedRecord->AppendUserEntry(entry);
    }

    selectedRecord->SetTotalRankCount(
        static_cast<int>(
            PacketBufferReadUInt32BE(packet + packetOffset)));
}

// UID:0003WT | by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md | Completion:93 | Confidence:94
void RankingCategoryCollection::ParseRankingRowsResponse(
    const unsigned char *packet)
{
    const int categoryId =
        static_cast<int>(PacketBufferReadUInt32BE(packet + 2));

    if (m_selectedCategoryId != categoryId)
        return;

    RankingCategoryRecord *selectedRecord = 0;
    for (unsigned int categoryIndex = 0;
         categoryIndex < m_records.size();
         ++categoryIndex)
    {
        if (m_records[categoryIndex].GetCategoryId() == categoryId)
        {
            selectedRecord = &m_records[categoryIndex];
            break;
        }
    }

    if (selectedRecord == 0)
        return;

    selectedRecord->ResetUserEntries();
    selectedRecord->m_localPlayerRank = -1;

    short packetOffset = 7;
    const char hasLocalPlayer = static_cast<char>(packet[6]);
    if (hasLocalPlayer > 0)
    {
        const int localPlayerRank =
            static_cast<int>(PacketBufferReadUInt32BE(packet + 7));
        const int localPlayerScore =
            static_cast<int>(PacketBufferReadUInt32BE(packet + 11));
        const char localStateCode = static_cast<char>(packet[15]);

        selectedRecord->m_localPlayerRank = localPlayerRank;
        packetOffset = 16;
        selectedRecord->m_localPlayerScore = localPlayerScore;
        selectedRecord->m_loadedRowsCategoryId = categoryId;
        selectedRecord->SetStateCode(localStateCode);
    }

    const short rowCount =
        static_cast<short>(
            PacketBufferReadUInt16BE(packet + packetOffset));
    packetOffset += 2;

    wchar_t wideName[256];
    char narrowName[256];

    for (short rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        const unsigned char nameLength = packet[packetOffset++];
        GetMemoryMan()->MemmoveWrapper(
            narrowName,
            packet + packetOffset,
            nameLength);
        narrowName[nameLength] = '\0';
        packetOffset =
            static_cast<short>(packetOffset + nameLength);

        const int wideNameLength =
            MultiByteToWideChar(
                CP_ACP,
                0,
                narrowName,
                nameLength,
                wideName,
                256);
        wideName[wideNameLength] = L'\0';

        const int rank =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int score =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        RankingUserEntry entry;
        entry.categoryId = categoryId;
        entry.score = -1;
        entry.rank = rank;
        wcscpy_s(entry.name, 32, wideName);
        entry.score = score;
        selectedRecord->AppendUserEntry(entry);
    }

    selectedRecord->SetTotalRankCount(
        static_cast<int>(
            PacketBufferReadUInt32BE(packet + packetOffset)));
}

// UID:0003WU | by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md | Completion:94 | Confidence:94
void RankingCategoryCollection::ApplyRewardClaimStatusResponse(const unsigned char *packet)
{
    const int categoryId =
        static_cast<int>(PacketBufferReadUInt32BE(packet + 2));

    if (packet[6] == 0)
        return;

    const int categoryCount = GetCount();
    for (short index = 0; index < categoryCount; ++index)
    {
        RankingCategoryRecord *category = GetByIndex(index);
        if (category != 0 && category->GetCategoryId() == categoryId)
        {
            category->SetStateCode(1);
            break;
        }
    }
}


// UID:0003WW | by-memory/0x0045ce40-0x0045ce57.RankingCategoryCollectionGetCount.md | Completion:92 | Confidence:94
int RankingCategoryCollection::GetCount() const
{
    return static_cast<int>(m_records.size());
}



// UID:0003WZ | by-memory/0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex.md | Completion:92 | Confidence:94
RankingCategoryRecord *RankingCategoryCollection::GetByIndex(short index) const
{
    if (index < 0 || index >= GetCount())
        return 0;

    return &m_records[index];
}



// UID:0004ZM | by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md | Completion:92 | Confidence:94
void RankingDialog::RequestRewardClaim()
{
    RankingCategoryRecord *category = m_categories.GetSelectedRecord();
    if (category == 0)
        return;

    unsigned char packet[64];
    PacketBufferWriteUInt8(0x7d, &packet[0]);
    PacketBufferWriteUInt8(6, &packet[1]);
    PacketBufferWriteUInt32BE(category->GetCategoryId(), &packet[2]);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:0004YX | by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md | Completion:92 | Confidence:94
void RankingDialog::UpdateRewardAndNavigationButtons()
{
    RankingCategoryRecord *record = m_categories.GetSelectedRecord();

    FittingRoomTextButtonControlPane *rewardInfoButton =
        GetChild<FittingRoomTextButtonControlPane>(5);
    if (record != 0)
    {
        rewardInfoButton->Enable();

        switch (record->GetStateCode())
        {
        case 0:
            GetChild<FittingRoomTextButtonControlPane>(6)->Enable();
            break;

        case 1:
        case 2:
            GetChild<FittingRoomTextButtonControlPane>(6)->Disable();
            break;
        }
    }
    else
    {
        rewardInfoButton->Disable();
        GetChild<FittingRoomTextButtonControlPane>(6)->Disable();
    }

    ImageButtonControlPane *previousButton =
        GetChild<ImageButtonControlPane>(3);
    if (m_currentPage <= 0)
    {
        if (previousButton != 0 && previousButton->IsEnabled())
            previousButton->Disable();
    }
    else if (previousButton != 0 && !previousButton->IsEnabled())
    {
        previousButton->Enable();
    }

    ImageButtonControlPane *nextButton =
        GetChild<ImageButtonControlPane>(4);
    if (m_currentPage >= m_maxPage)
    {
        if (nextButton != 0 && nextButton->IsEnabled())
            nextButton->Disable();
    }
    else if (nextButton != 0 && !nextButton->IsEnabled())
    {
        nextButton->Enable();
    }
}


// UID:0000BO | by-class/RankingEventScrollPane.md | Completion:89 | Confidence:92
enum RankingScrollPart {
    kRankingScrollPartLeading = 0,
    kRankingScrollPartPageBeforeThumb = 1,
    kRankingScrollPartThumb = 2,
    kRankingScrollPartPageAfterThumb = 3,
    kRankingScrollPartTrailing = 4,
    kRankingScrollPartNone = -1
};

const int kRankingScrollThumbSpan = 38;

class RankingEventScrollPane : public Pane {
public:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool HasActiveEffect();
    virtual void OnPaint();

private:
    RankingScrollPart HitTestPart(int y, int x);
    void GetPartRect(RankingScrollPart part, RectBounds *outRect);
    void SetHighlightedPart(RankingScrollPart part);
    void BeginPartInteraction(RankingScrollPart part, int mouseY, int mouseX);
    void UpdateActiveInteraction();
    void DragToPosition(int y, int x);
    void ResetInteractionState();

    short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_highlightPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};


// UID:0000Y3 | by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md | Completion:89 | Confidence:91
bool RankingEventScrollPane::OnMouseEvent(const PaneMouseEvent& event)
{
    bool handled = false;
    RectBounds partRect;

    switch (event.type) {
    case kPaneMouseMove:
        if (m_activePart != kRankingScrollPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kPaneMouseDown:
        if (!PointInRect(event.y, event.x, &m_bounds)) {
            return false;
        }
        if (!m_enabled || m_scrollRange <= 0) {
            return false;
        }

        if (m_activePart == kRankingScrollPartNone) {
            const RankingScrollPart part = HitTestPart(event.y, event.x);

            if (part != kRankingScrollPartNone) {
                CaptureMouse();

                if (part == kRankingScrollPartThumb) {
                    if (m_highlightPart != kRankingScrollPartThumb) {
                        if (m_highlightPart != kRankingScrollPartNone) {
                            GetPartRect(static_cast<RankingScrollPart>(m_highlightPart), &partRect);
                            InvalidateRect(&partRect);
                        }

                        GetPartRect(kRankingScrollPartThumb, &partRect);
                        InvalidateRect(&partRect);
                        m_highlightPart = static_cast<signed char>(kRankingScrollPartThumb);
                    }

                    GetPartRect(kRankingScrollPartThumb, &partRect);
                    m_thumbDragOffset.y = event.y - partRect.top;
                    m_thumbDragOffset.x = event.x - partRect.left;
                }

                m_activePart = static_cast<signed char>(part);

                Point cursor;
                Point origin;
                EventMan::GetCursorPosition(&cursor);
                GetScreenOffset(&origin);

                if (origin.x != -1000 || origin.y != -1000) {
                    const int localY = cursor.y - origin.y;
                    const int localX = cursor.x - origin.x;

                    if (m_activePart == kRankingScrollPartThumb) {
                        DragToPosition(localY, localX);
                    } else {
                        if (HitTestPart(localY, localX) ==
                            static_cast<RankingScrollPart>(m_activePart)) {
                            DragToPosition(localY, localX);
                        }

                        if (m_highlightPart != kRankingScrollPartNone) {
                            GetPartRect(static_cast<RankingScrollPart>(m_highlightPart), &partRect);
                            InvalidateRect(&partRect);
                            m_highlightPart = static_cast<signed char>(kRankingScrollPartNone);
                        }
                    }
                }

                ScheduleTimer(0, 200, 0, 0);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kPaneMouseUp:
        if (m_activePart != kRankingScrollPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();

            const signed char oldHighlightPart = m_highlightPart;
            m_activePart = static_cast<signed char>(kRankingScrollPartNone);

            if (oldHighlightPart != static_cast<signed char>(kRankingScrollPartNone)) {
                GetPartRect(static_cast<RankingScrollPart>(oldHighlightPart), &partRect);
                InvalidateRect(&partRect);
                m_highlightPart = static_cast<signed char>(kRankingScrollPartNone);
            }

            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_bounds);
        break;

    default:
        break;
    }

    return handled;
}

// UID:0001Z9 | by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md | Completion:91 | Confidence:92
bool RankingEventScrollPane::DefaultVirtualFalse(int)
{
    return false;
}

// UID:0001ZA | by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md | Completion:89 | Confidence:91
void RankingEventScrollPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    if (m_enabled && m_scrollRange > 0) {
        const bool horizontal = (m_orientation != 0);
        const RankingScrollPart trackParts[2] = {
            kRankingScrollPartPageBeforeThumb,
            kRankingScrollPartPageAfterThumb
        };

        for (int i = 0; i < 2; ++i) {
            const RankingScrollPart part = trackParts[i];

            GetPartRect(part, &partRect);
            if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                continue;
            }

            m_drawMode = 0;
            SetDrawColor(0);
            PreparePaneRegion(&drawRect);
            SetDrawColor(0x80);

            const int fillFrame = horizontal ? 4 : 1;
            const int capFrame = horizontal
                ? (part == kRankingScrollPartPageBeforeThumb ? 3 : 5)
                : (part == kRankingScrollPartPageBeforeThumb ? 0 : 2);

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
            RenderTileFrame(&tile,
                            &tile.bounds,
                            &drawRect,
                            1,
                            L"SLIDEBG.PAL",
                            0);
        }

        GetPartRect(kRankingScrollPartThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            m_drawMode = 0;
            SetDrawColor(0);
            PreparePaneRegion(&drawRect);
            SetDrawColor(0x80);

            const int frame =
                (m_highlightPart == kRankingScrollPartThumb) ? 1 : 0;
            g_pEPFLib->LookupLayoutEntry(L"SCRBUTT.EPF", frame, &tile);
            RenderTileFrame(&tile,
                            &tile.bounds,
                            &drawRect,
                            1,
                            L"BUTTON.PAL",
                            0);
        }

        return;
    }

    if (m_scrollStyle == 0) {
        SetDrawColor(0);
        m_drawMode = 0;
        PreparePaneRegion(&clipRect);
    }
}

// UID:0000Y4 | by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md | Completion:89 | Confidence:91
RankingScrollPart RankingEventScrollPane::HitTestPart(int y, int x)
{
    RectBounds partRect;

    for (int partValue = kRankingScrollPartLeading;
         partValue <= kRankingScrollPartTrailing;
         ++partValue) {
        const RankingScrollPart part = static_cast<RankingScrollPart>(partValue);
        Point cursor;
        Point origin;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);

        if (origin.y != -1000 || origin.x != -1000) {
            cursor.y -= origin.y;
            cursor.x -= origin.x;
            partRect = m_bounds;

            if (m_orientation != 0) {
                const int thumbSpan = m_bounds.bottom - m_bounds.top;

                if (part == kRankingScrollPartLeading) {
                    partRect.right = partRect.left;
                } else if (part == kRankingScrollPartTrailing) {
                    partRect.left = partRect.right;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int thumbLimit = m_bounds.right - thumbSpan;
                    const int thumbLeft = m_bounds.left +
                        (m_scrollPosition * (thumbLimit - m_bounds.left)) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kRankingScrollPartThumb) {
                        partRect.left = thumbLeft;
                        partRect.right = thumbRight;
                    } else if (part == kRankingScrollPartPageBeforeThumb) {
                        partRect.right = thumbLeft;
                    } else if (part == kRankingScrollPartPageAfterThumb) {
                        partRect.left = thumbRight;
                    }
                } else if (part == kRankingScrollPartThumb) {
                    partRect.left += thumbSpan;
                    partRect.right -= thumbSpan;
                } else {
                    InitRectBounds(&partRect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = kRankingScrollThumbSpan;

                if (part == kRankingScrollPartLeading) {
                    partRect.bottom = partRect.top;
                } else if (part == kRankingScrollPartTrailing) {
                    partRect.top = partRect.bottom;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int thumbLimit = m_bounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_bounds.top + cursor.y - m_thumbDragOffset.y;

                        if (thumbTop < m_bounds.top) {
                            thumbTop = m_bounds.top;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = m_bounds.top +
                            (m_scrollPosition * (thumbLimit - m_bounds.top)) /
                                m_scrollRange;
                    }

                    const int thumbBottom = thumbTop + thumbSpan;

                    if (part == kRankingScrollPartThumb) {
                        partRect.top = thumbTop;
                        partRect.bottom = thumbBottom;
                    } else if (part == kRankingScrollPartPageBeforeThumb) {
                        partRect.bottom = thumbTop;
                    } else if (part == kRankingScrollPartPageAfterThumb) {
                        partRect.top = thumbBottom;
                    }
                } else if (part == kRankingScrollPartThumb) {
                    partRect.top += thumbSpan;
                    partRect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&partRect, 0, 0, 0, 0);
                }
            }
        }

        if (PointInRect(y, x, &partRect)) {
            return part;
        }
    }

    return kRankingScrollPartNone;
}

// UID:0001ZB | by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md | Completion:89 | Confidence:91
void RankingEventScrollPane::GetPartRect(RankingScrollPart part, RectBounds *outRect)
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
        const int thumbSpan = bounds.bottom - bounds.top;

        if (part == kRankingScrollPartLeading) {
            *outRect = bounds;
            outRect->right = outRect->left;
            return;
        }
        if (part == kRankingScrollPartTrailing) {
            *outRect = bounds;
            outRect->left = outRect->right;
            return;
        }

        if (m_enabled && m_scrollRange > 0) {
            const int thumbLeft = bounds.left +
                (m_scrollPosition *
                 (bounds.right - bounds.left - thumbSpan)) /
                    m_scrollRange;
            const int thumbRight = thumbLeft + thumbSpan;

            *outRect = bounds;
            if (part == kRankingScrollPartThumb) {
                outRect->left = thumbLeft;
                outRect->right = thumbRight;
            } else if (part == kRankingScrollPartPageBeforeThumb) {
                outRect->right = thumbLeft;
            } else if (part == kRankingScrollPartPageAfterThumb) {
                outRect->left = thumbRight;
            }
            return;
        }

        if (part == kRankingScrollPartThumb) {
            *outRect = bounds;
            outRect->left += thumbSpan;
            outRect->right -= thumbSpan;
        } else if (part == kRankingScrollPartPageBeforeThumb ||
                   part == kRankingScrollPartPageAfterThumb) {
            InitRectBounds(outRect, 0, 0, 0, 0);
        }
        return;
    }

    if (part == kRankingScrollPartLeading) {
        *outRect = bounds;
        outRect->bottom = outRect->top;
        return;
    }
    if (part == kRankingScrollPartTrailing) {
        *outRect = bounds;
        outRect->top = outRect->bottom;
        return;
    }

    if (m_enabled && m_scrollRange > 0) {
        const int thumbLimit = bounds.bottom - kRankingScrollThumbSpan;
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
            thumbTop = bounds.top +
                (m_scrollPosition * (thumbLimit - bounds.top)) /
                    m_scrollRange;
        }

        const int thumbBottom = thumbTop + kRankingScrollThumbSpan;
        *outRect = bounds;
        if (part == kRankingScrollPartThumb) {
            outRect->top = thumbTop;
            outRect->bottom = thumbBottom;
        } else if (part == kRankingScrollPartPageBeforeThumb) {
            outRect->bottom = thumbTop;
        } else if (part == kRankingScrollPartPageAfterThumb) {
            outRect->top = thumbBottom;
        }
        return;
    }

    if (part == kRankingScrollPartThumb) {
        *outRect = bounds;
        outRect->top += kRankingScrollThumbSpan;
        outRect->bottom -= kRankingScrollThumbSpan;
    } else if (part == kRankingScrollPartPageBeforeThumb ||
               part == kRankingScrollPartPageAfterThumb) {
        InitRectBounds(outRect, 0, 0, 0, 0);
    }
}

// UID:0004J0 | by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md | Completion:90 | Confidence:93
void RankingEventScrollPane::SetHighlightedPart(RankingScrollPart part)
{
    RectBounds rect;
    const RankingScrollPart oldPart =
        static_cast<RankingScrollPart>(m_highlightPart);

    if (oldPart == part)
        return;

    if (oldPart != kRankingScrollPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kRankingScrollPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}

// UID:0000Y5 | by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md | Completion:90 | Confidence:93
// [UID:0000Y5] Non-emitting split index. Exact child pages own the three methods.

// UID:0004J1 | by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md | Completion:90 | Confidence:92
void RankingEventScrollPane::BeginPartInteraction(RankingScrollPart part,
                                                  int mouseY,
                                                  int mouseX)
{
    RectBounds rect;

    if (part == kRankingScrollPartThumb) {
        if (m_highlightPart != kRankingScrollPartThumb) {
            if (m_highlightPart != kRankingScrollPartNone) {
                GetPartRect(static_cast<RankingScrollPart>(m_highlightPart),
                            &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kRankingScrollPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart =
                static_cast<signed char>(kRankingScrollPartThumb);
        }

        GetPartRect(kRankingScrollPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateActiveInteraction();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:0004J2 | by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md | Completion:90 | Confidence:93
void RankingEventScrollPane::UpdateActiveInteraction()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000)
        return;

    const int localY = cursor.y - origin.y;
    const int localX = cursor.x - origin.x;

    if (m_activePart == kRankingScrollPartThumb) {
        DragToPosition(localY, localX);
        return;
    }

    if (HitTestPart(localY, localX) ==
        static_cast<RankingScrollPart>(m_activePart)) {
        DragToPosition(localY, localX);
    }

    if (m_highlightPart != kRankingScrollPartNone) {
        GetPartRect(static_cast<RankingScrollPart>(m_highlightPart), &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kRankingScrollPartNone);
    }
}

// UID:0000Y6 | by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md | Completion:90 | Confidence:92
void RankingEventScrollPane::DragToPosition(int y, int x)
{
    const short oldPosition = m_scrollPosition;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    Point cursor;
    Point origin;

    GetPartRect(kRankingScrollPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_bounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_bounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    short newPosition;
    if (m_orientation != 0) {
        int thumbStart = x - m_thumbDragOffset.x + 1;
        const int trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        const int maxThumbStart = trailingRect.left +
            thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan = trailingRect.left + thumbRect.left -
            thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) /
            trackSpan);
    } else {
        int thumbStart = y - m_thumbDragOffset.y + 1;
        const int trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        const int maxThumbStart = trailingRect.top +
            thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan = trailingRect.top + thumbRect.top -
            thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) /
            trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition == newPosition) {
        return;
    }

    RankingEventListPane *owner =
        static_cast<RankingEventListPane *>(GetOwnerPane());
    owner->SetScrollPosition(0, oldPosition, newPosition);
}

// UID:0000Y7 | by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md | Completion:89 | Confidence:92
void RankingEventScrollPane::ResetInteractionState()
{
    RectBounds rect;
    const RankingScrollPart oldPart =
        static_cast<RankingScrollPart>(m_highlightPart);

    RemovePendingTimers();
    m_activePart = static_cast<signed char>(kRankingScrollPartNone);

    if (oldPart != kRankingScrollPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kRankingScrollPartNone);
    }
}



// UID:0000BP | by-class/RankingRewardInfoDialog.md | Completion:91 | Confidence:93
#include "../core/BlackHole.h"

typedef EPFTileContext FrameDrawRecord;

class Event;

struct RankingRewardItem
{
    wchar_t name[256];
    int quantity;
    unsigned short iconId;
    unsigned char paletteIndex;
    unsigned char reserved_207;
};

typedef std::vector<RankingRewardItem> RankingRewardItemVector;

struct RankingRewardEntry
{
    RankingRewardEntry();
    int ParseFromPacket(const unsigned char *packet);

    wchar_t rankStartText[8];
    wchar_t rankEndText[8];
    wchar_t symbolText[256];
    char symbolFrameIndex;
    unsigned char symbolAttribute;
    RankingRewardItemVector items;

    wchar_t *GetRankStartText();
    wchar_t *GetRankEndText();
    int GetItemCount() const;
    wchar_t *GetSymbolText();
    RankingRewardItem *ItemAt(int index);
};

typedef std::vector<RankingRewardEntry> RankingRewardEntryVector;

class RankingRewardInfoDialog : public DialogPane
{
public:
    RankingRewardInfoDialog();

    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();
    virtual void OnDialogAction(int actionId, int actionParam);

private:
    void BuildCloseButtonBounds(short layoutSelector, RectBounds *outBounds) const;
    void SendRewardInfoRequest();

    RankingRewardEntryVector m_rewardEntries;
};

// UID:000202 | by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md | Completion:90 | Confidence:92
RankingRewardEntry::RankingRewardEntry()
    : symbolFrameIndex(-1)
{
}

// UID:0001ZF | by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md | Completion:91 | Confidence:92
int RankingRewardEntry::ParseFromPacket(const unsigned char *packet)
{
    char narrowText[256];
    wchar_t wideText[256] = {0};
    int offset = 0;

    unsigned int length = static_cast<unsigned char>(packet[offset++]);
    GetMemoryMan()->MemmoveWrapper(narrowText, packet + offset, length);
    narrowText[length] = '\0';
    offset += length;
    unsigned int wideLength = MultiByteToWideChar(
        CP_ACP, 0, narrowText, length, wideText, 256);
    wideText[wideLength] = L'\0';
    wcscpy_s(rankStartText, 8, wideText);

    length = static_cast<unsigned char>(packet[offset++]);
    GetMemoryMan()->MemmoveWrapper(narrowText, packet + offset, length);
    narrowText[length] = '\0';
    offset += length;
    wideLength = MultiByteToWideChar(
        CP_ACP, 0, narrowText, length, wideText, 256);
    wideText[wideLength] = L'\0';
    wcscpy_s(rankEndText, 8, wideText);

    length = static_cast<unsigned char>(packet[offset++]);
    GetMemoryMan()->MemmoveWrapper(narrowText, packet + offset, length);
    narrowText[length] = '\0';
    offset += length;
    wideLength = MultiByteToWideChar(
        CP_ACP, 0, narrowText, length, wideText, 256);
    wideText[wideLength] = L'\0';
    wcscpy_s(symbolText, 256, wideText);

    symbolFrameIndex = static_cast<char>(packet[offset++]);
    symbolAttribute = packet[offset++];

    signed char itemCount = static_cast<signed char>(packet[offset++]);
    for (signed char itemIndex = 0; itemIndex < itemCount; ++itemIndex)
    {
        RankingRewardItem item;

        length = static_cast<unsigned char>(packet[offset++]);
        GetMemoryMan()->MemmoveWrapper(narrowText, packet + offset, length);
        narrowText[length] = '\0';
        offset += length;
        wideLength = MultiByteToWideChar(
            CP_ACP, 0, narrowText, length, wideText, 256);
        wideText[wideLength] = L'\0';
        wcscpy_s(item.name, 256, wideText);

        item.quantity = PacketBufferReadUInt32BE(packet + offset);
        offset += 4;
        item.iconId = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        item.paletteIndex = packet[offset++];
        items.push_back(item);
    }

    return offset;
}

wchar_t *RankingRewardEntry::GetRankStartText()
{
    return rankStartText;
}

wchar_t *RankingRewardEntry::GetRankEndText()
{
    return rankEndText;
}

int RankingRewardEntry::GetItemCount() const
{
    return static_cast<int>(items.size());
}

wchar_t *RankingRewardEntry::GetSymbolText()
{
    return symbolText;
}

// UID:000204 | by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md | Completion:90 | Confidence:92
RankingRewardItem *RankingRewardEntry::ItemAt(int index)
{
    int itemCount = static_cast<int>(items.size());

    if (itemCount <= index)
        return NULL;

    return &items[index];
}

// UID:0004I7 | by-memory/0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor.md | Completion:91 | Confidence:93
RankingRewardInfoDialog::RankingRewardInfoDialog()
    : DialogPane(L"", static_cast<unsigned short>(-1), 0)
{
    g_pRankingRewardInfoDialog = this;

    RectBounds closeBounds;
    BuildCloseButtonBounds(0, &closeBounds);
    AddControl(new ImageButtonControlPane(14, &closeBounds));

    RectBounds dialogBounds;
    InitRectBoundsFromSize(&dialogBounds, 202, 104, 620, 500);
    OnCreate(&dialogBounds, 0, NULL, dword_69B36C);
    OnShow(NULL, g_pBackPane);
    SetFocusedControl(0);
    SetPendingControl(0);

    SendRewardInfoRequest();
    SlideOpenVertical();
}

// UID:0004I9 | by-memory/0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction.md | Completion:90 | Confidence:92
void RankingRewardInfoDialog::OnDialogAction(int actionId, int actionParam)
{
    (void)actionParam;

    if (actionId == 0)
    {
        SlideCloseVertical();
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    }
}

// UID:0001ZH | by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md | Completion:91 | Confidence:93
bool RankingRewardInfoDialog::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->packet;
    if (packet[0] != 0x7d || packet[1] != 5)
        return false;

    const unsigned int categoryId = PacketBufferReadUInt32BE(packet + 2);
    RankingCategoryRecord *category =
        g_pRankingDialog->m_categories.GetSelectedRecord();

    if (category != NULL &&
        static_cast<unsigned int>(category->GetCategoryId()) == categoryId)
    {
        const short entryCount =
            static_cast<short>(PacketBufferReadUInt16BE(packet + 6));
        int packetOffset = 8;

        for (int index = 0; index < entryCount; ++index)
        {
            RankingRewardEntry entry;
            packetOffset += entry.ParseFromPacket(packet + packetOffset);
            m_rewardEntries.push_back(entry);
        }

        InvalidateRect(&m_bounds);
    }

    return true;
}

// UID:0004IA | by-memory/0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md | Completion:90 | Confidence:92
void RankingRewardInfoDialog::OnPaint()
{
    FrameDrawRecord frame;
    g_pEPFLib->LookupLayoutEntry(L"WBOARDBK.EPF", 0, &frame);

    m_drawMode = 1;

    RectBounds backgroundBounds = m_visibleBounds;
    backgroundBounds.left += 11;
    backgroundBounds.top += 42;
    backgroundBounds.right -= 11;
    backgroundBounds.bottom -= 40;
    DrawTiledBackground(&backgroundBounds, &frame, L"WBOARDBK.PAL");

    const int width = m_visibleBounds.right - m_visibleBounds.left;
    const int height = m_visibleBounds.bottom - m_visibleBounds.top;
    RectBounds sourceBounds;
    RectBounds destinationBounds;


    InitRectBounds(&sourceBounds, 0, 0, 37, 42);
    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 37, 0);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 1, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"WEBBOARD.PAL", NULL);
        OffsetRect(&destinationBounds, 37, 0);
    }
    while (destinationBounds.right < width + sourceBounds.right);

    InitRectBounds(&sourceBounds, 0, 0, 37, 40);
    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 37, height - 40);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 6, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"WEBBOARD.PAL", NULL);
        OffsetRect(&destinationBounds, 37, 0);
    }
    while (destinationBounds.right < width + sourceBounds.right);

    InitRectBounds(&sourceBounds, 0, 0, 11, 40);
    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 0, 40);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 3, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"WEBBOARD.PAL", NULL);
        OffsetRect(&destinationBounds, 0, 40);
    }
    while (destinationBounds.bottom < height + sourceBounds.bottom);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 11, 40);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 4, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"WEBBOARD.PAL", NULL);
        OffsetRect(&destinationBounds, 0, 40);
    }
    while (destinationBounds.bottom < height + sourceBounds.bottom);

    InitRectBounds(&sourceBounds, 0, 0, 37, 42);
    destinationBounds = sourceBounds;
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 0, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"WEBBOARD.PAL", NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 37, 0);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 2, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"WEBBOARD.PAL", NULL);

    InitRectBounds(&sourceBounds, 0, 0, 37, 40);
    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 0, height - 40);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 5, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"WEBBOARD.PAL", NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 37, height - 40);
    g_pEPFLib->LookupLayoutEntry(L"WEBBOARD.EPF", 7, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"WEBBOARD.PAL", NULL);

    SetTextColor(143);
    SetTextBackColor(128);

    RankingCategoryRecord *category =
        g_pRankingDialog->m_categories.GetSelectedRecord();
    if (category != NULL)
    {
        const wchar_t *title = category->GetTitleText();
        DrawOutlinedText(30, 64, title, static_cast<int>(wcslen(title)));
    }

    DrawOutlinedText(30, 86, L"Rank", 4);
    DrawOutlinedText(110, 86, L"Reward Legend", 13);
    DrawOutlinedText(290, 86, L"Reward Items", 12);

    Point cursor;
    cursor.y = 110;
    cursor.x = 30;

    const signed char entryCount =
        static_cast<signed char>(m_rewardEntries.size());
    for (int entryIndex = 0; entryIndex < entryCount; ++entryIndex)
    {
        RankingRewardEntry &entry = m_rewardEntries[entryIndex];

        if (wcscmp(entry.rankStartText, entry.rankEndText) != 0)
        {
            DrawOutlinedText(cursor.x, cursor.y, entry.rankStartText,
                             static_cast<int>(wcslen(entry.rankStartText)));
            cursor.x += 25;
            DrawOutlinedText(cursor.x, cursor.y, L"~", 1);
            cursor.x += 15;
            DrawOutlinedText(cursor.x, cursor.y, entry.rankEndText,
                             static_cast<int>(wcslen(entry.rankEndText)));
            cursor.x += 40;
        }
        else
        {
            DrawOutlinedText(cursor.x, cursor.y, entry.rankStartText,
                             static_cast<int>(wcslen(entry.rankStartText)));
            cursor.x += 80;
        }

        if (entry.symbolFrameIndex >= 0)
        {
            RectBounds symbolBounds;
            InitRectBoundsFromSize(&symbolBounds, cursor.x, cursor.y - 10, 10, 10);
            g_pEPFLib->LookupLayoutEntry(L"SYMBOLS.EPF",
                                         entry.symbolFrameIndex,
                                         &frame);
            g_pfnBlitSprite(this, &frame, &frame.bounds, &symbolBounds,
                            1, NULL, NULL);
            DrawOutlinedText(cursor.x + 20, cursor.y, entry.symbolText,
                             static_cast<int>(wcslen(entry.symbolText)));
        }

        cursor.x += 190;

        const signed char itemCount =
            static_cast<signed char>(entry.items.size());
        for (int itemIndex = 0; itemIndex < itemCount; ++itemIndex)
        {
            RankingRewardItem &item = entry.items[itemIndex];
            short itemId = static_cast<short>(item.iconId - 0x4000);
            if (item.iconId >= 0xc000)
                itemId = static_cast<short>(item.iconId);

            RectBounds itemBounds;
            GetItemGlyphBounds(itemId, &itemBounds);
            const int itemWidth = itemBounds.right - itemBounds.left;
            const int itemHeight = itemBounds.bottom - itemBounds.top;

            RectBounds drawBounds;
            if (itemHeight > 40 || itemWidth > 40)
            {
                const int drawWidth = itemWidth / 2;
                const int drawHeight = itemHeight / 2;
                const int left = cursor.x - drawWidth / 2 - 5;
                const int top = cursor.y - drawHeight / 2 - 5;
                InitRectBounds(&drawBounds, left, top,
                               left + drawWidth, top + drawHeight);
                g_pItemObjImageLib->DrawItemImageUnscaled(
                    this, &drawBounds, itemId, item.paletteIndex);
            }
            else
            {
                InitRectBounds(&drawBounds,
                               cursor.x - 25, cursor.y - 25,
                               cursor.x + 15, cursor.y + 15);
                g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                    this, &drawBounds, itemId, item.paletteIndex, NULL, 0.0f);
            }

            cursor.x += 10;

            wchar_t label[256];
            swprintf_s(label, L"%s(%d)",
                       item.name, item.quantity);
            const int labelLength = static_cast<int>(wcslen(label));
            DrawOutlinedText(cursor.x, cursor.y, label, labelLength);
            cursor.x += GetTextWidth(label, labelLength) + 30;
        }

        cursor.y += 26;
        cursor.x = 30;
    }
}

// UID:0004IB | by-memory/0x0045ea20-0x0045ea5e.RankingRewardInfoDialogBuildCloseButtonBoundsRaw.md | Completion:89 | Confidence:91
void RankingRewardInfoDialog::BuildCloseButtonBounds(
    short layoutSelector,
    RectBounds *outBounds) const
{
    if (layoutSelector != 0)
        InitRectBounds(outBounds, -1, -1, -1, -1);
    else
        InitRectBoundsFromSize(outBounds, 279, 468, 63, 24);
}

// UID:0004IC | by-memory/0x0045ea60-0x0045ead9.RankingRewardInfoDialogSendRewardInfoRequestRaw.md | Completion:90 | Confidence:92
void RankingRewardInfoDialog::SendRewardInfoRequest()
{
    RankingCategoryRecord *category =
        g_pRankingDialog->m_categories.GetSelectedRecord();
    if (category == NULL)
        return;

    unsigned char packet[7];
    PacketBufferWriteUInt8(0x7d, &packet[0]);
    PacketBufferWriteUInt8(5, &packet[1]);
    PacketBufferWriteUInt32BE(category->GetCategoryId(), &packet[2]);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:0003X6 | by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md | Completion:92 | Confidence:93
// Emitted code for this std::vector<RankingRewardItem> capacity-growth slow path
// is covered by [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) RankingRewardEntry::ParseFromPacket source as
// items.push_back(item).
// The compiler/STL regenerates the allocation, relocation, cleanup, and
// inserted-iterator return represented by this binary helper.
// Do not emit a standalone decompiler-shaped
// RankingRewardItemVectorInsertWithGrowth helper body here.

// UID:0003X7 | by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md | Completion:93 | Confidence:94
// Emitted code for this std::vector<RankingRewardEntry> capacity-growth slow path
// is covered by [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md) RankingRewardInfoDialog::HandlePacketEvent source as
// m_rewardEntries.push_back(entry).
// The compiler/STL regenerates memberwise fixed-field copy through +0x221,
// implicit +0x222..+0x223 padding omission, nested item-vector deep copy,
// partial-range unwind cleanup, allocation/free, and inserted-iterator return.
// Do not emit a standalone decompiler-shaped
// RankingRewardEntryVectorInsertWithGrowth helper body here.

// UID:0003X9 | by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md | Completion:92 | Confidence:94
// Emitted code for this std::vector<RankingRewardItem> copy-construction
// lowering is covered by [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md) RankingRewardInfoDialog::HandlePacketEvent source as
// m_rewardEntries.push_back(entry).
// Copy-constructing RankingRewardEntry deep-copies its items member; the
// compiler/STL regenerates the empty, allocation, contiguous-copy, and
// failure behavior represented by this binary specialization.
// Do not emit a standalone decompiler-shaped
// RankingRewardItemVectorClone helper body here.


// UID:0001ZK | by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md | Completion:92 | Confidence:94
// Emitted code for this std::vector<RankingRewardEntry> destruction lowering
// is covered by [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) declarations of
// RankingRewardEntryVector m_rewardEntries and RankingRewardItemVector items.
// Implicit RankingRewardEntry and RankingRewardInfoDialog destruction makes
// the compiler/STL destroy each nested items vector, free outer capacity
// storage, and clear the vector state represented by this binary helper.
// Do not emit a standalone decompiler-shaped
// RankingRewardEntryVectorDestroy helper or explicit entry destructor here.

// UID:0004J3 | by-memory/0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy.md | Completion:92 | Confidence:94
// Emitted code for this completed std::vector<RankingRewardEntry> range
// destruction is covered by [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
// m_rewardEntries.push_back(entry). The compiler/STL regenerates this
// failed-growth rollback walk and destroys each completed entry's nested
// RankingRewardItemVector items member. Do not emit a standalone
// decompiler-shaped RankingRewardEntryRangeDestroy helper here.

// UID:0004J4 | by-memory/0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy.md | Completion:93 | Confidence:94
// Emitted code for this std::vector<RankingRewardItem> destruction lowering
// is covered by [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) declarations of
// RankingRewardItemVector items and RankingRewardEntryVector m_rewardEntries.
// Automatic RankingRewardEntry lifetime and implicit vector destruction
// regenerate the checked storage free and triplet clear. Do not emit a
// standalone decompiler-shaped RankingRewardItemVectorDestroy helper here.

// UID:0004J5 | by-memory/0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct.md | Completion:93 | Confidence:94
// Emitted code for this std::vector<RankingRewardEntry> range copy
// construction is covered by [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
// m_rewardEntries.push_back(entry). The compiler/STL regenerates fixed-member
// copy through +0x221, natural alignment before items +0x224, nested item
// vector copy, and completed-range EH rollback. Do not emit a standalone
// decompiler-shaped RankingRewardEntryRangeCopyConstruct helper here.

// UID:0004J6 | by-memory/0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage.md | Completion:93 | Confidence:94
// Emitted code for this std::vector<RankingRewardItem> storage allocation
// lowering is covered by [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md)
// items.push_back(item) and [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
// m_rewardEntries.push_back(entry). The compiler/STL regenerates exact-count
// allocation and the aligned large-allocation header path. Do not emit a
// standalone decompiler-shaped RankingRewardItemVectorAllocateStorage helper.

// UID:0004J7 | by-memory/0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage.md | Completion:92 | Confidence:94
// Emitted code for this std::vector<RankingRewardEntry> failed-growth storage
// free is covered by [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
// m_rewardEntries.push_back(entry). The compiler/STL regenerates completed
// entry rollback, size recovery, aligned-header validation, and storage free.
// Do not emit a standalone decompiler-shaped
// RankingRewardEntryVectorFreeStorage helper here.

// UID:0000BQ | by-class/RankingUserListPane.md | Completion:87 | Confidence:90
struct RectBounds;

class RankingUserListPane : public ControlPane
{
public:
    explicit RankingUserListPane(const RectBounds *bounds);
    virtual ~RankingUserListPane();

protected:
    virtual void OnPaint();

    [[No Children Attached]]
};

// UID:0000S2 | by-global/g_pRankingDialog.md | Completion:88 | Confidence:92
class RankingDialog;

RankingDialog *g_pRankingDialog = 0;

// UID:0000S3 | by-global/g_pRankingRewardInfoDialog.md | Completion:88 | Confidence:92
class RankingRewardInfoDialog;

RankingRewardInfoDialog *g_pRankingRewardInfoDialog = 0;

// UID:0003X1 | by-memory\0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003X2 | by-memory\0x0045d320-0x0045d36c.RankingUserEntryCopyRange.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003X3 | by-memory\0x0045d370-0x0045d419.RankingUserEntryVectorClone.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003YV | by-memory\0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0001VN | by-type\by-struct\RankingCategoryRecordLayout.md | Completion:93 | Confidence:95 | Empty Emitter Marker

// UID:0003WP | by-memory\0x0045c260-0x0045c281.RankingCategoryCollectionConstructor.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0001ZC | by-memory\0x0045c260-0x0045d4f8.RankingCategoryCollection.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0003WV | by-memory\0x0045ce30-0x0045ce3d.RankingCategoryCollectionSetSelectedCategoryId.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0003WX | by-memory\0x0045ce60-0x0045ce64.RankingCategoryCollectionGetSelectedCategoryId.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0003WY | by-memory\0x0045ce70-0x0045ceab.RankingCategoryCollectionGetSelectedRecord.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0001ZE | by-memory\0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0000BM | by-class\RankingDialog.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0000BN | by-class\RankingEventListPane.md | Completion:87 | Confidence:89 | Empty Emitter Marker

// UID:0000Y2 | by-memory\0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0001VO | by-type\by-struct\RankingEventScrollPaneLayout.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0001YK | by-type\by-vtable\RankingEventScrollPaneVtables.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0000YA | by-memory\0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md | Completion:88 | Confidence:95 | Empty Emitter Marker

// UID:0000XZ | by-memory\0x00458610-0x0045f9f5.RankingDialog.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0002ON | by-memory\0x00610980-0x00610e38.RankingDialogReadOnlyData.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0001YJ | by-type\by-vtable\RankingDialogVtableFamily.md | Completion:86 | Confidence:92 | Empty Emitter Marker
