// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OZ
// Source by-file doc: by-file/UserListDialogPane.md
// UID:0000A7 | by-class/PartySearchEditPane.md | Completion:92 | Confidence:93
class PartySearchEditPane : public DialogPane
{
public:
    PartySearchEditPane();
    virtual ~PartySearchEditPane() {}

    virtual void OnPaint();
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};

// UID:0003E7 | by-memory/0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData.md | Completion:90 | Confidence:93
// Compiler-emitted PartySearchEditPane RTTI/vtable data is covered by the
// complete PartySearchEditPane class declaration and exact virtual method
// definitions; do not hand-author vtable or RTTI arrays.

// UID:0000FN | by-class/UserListDialogPane.md | Completion:94 | Confidence:95
#include "../ui/core/BlackHole.h"

template <class T> class Singleton;
class DialogPane;
class Event;
class List;
class PartySearchEditPane;
class UserListDialogPane;
class UserListPane;
class WideString;

extern UserListDialogPane *g_pUserListDialogPane;
void GetLocalPlayerNameString(WideString &outName);

#pragma pack(push, 1)
struct UserListRecord
{
    unsigned char careerId;
    unsigned char bucketIndex;
    unsigned char reserved2;
    unsigned char badgeIconId;
    unsigned char displayColor;
    unsigned char reserved5[3];
    long arrivalSortKey;
    unsigned char statusIconId;
    unsigned char reservedD;
    wchar_t name[256];
    unsigned char huntersListFlag;
    unsigned char hasSourceText;
    wchar_t sourceText[256];
    unsigned char careerVariant;
    unsigned char reserved411[3];
};
#pragma pack(pop)

int __cdecl CompareUserListRecordsByStatus(const UserListRecord *left,
                                           const UserListRecord *right);
int __cdecl CompareUserListRecordsByName(const UserListRecord *left,
                                         const UserListRecord *right);

class UserListDialogPane : public Singleton<UserListDialogPane>, public DialogPane
{
public:
    enum UserListMessage
    {
        kUserListHuntersListStateUpdate = 0x83,
        kUserListSourceTextUpdate = 0x84
    };

    enum UserListControlIndex
    {
        kHuntersListParticipationControl = 0x14
    };

    explicit UserListDialogPane(const unsigned char *packet);
    virtual ~UserListDialogPane();

    void SortListsByStatus();
    void SortListsByName();
    void RefreshCategoryView(char step);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);

    void AddUserListSourceMessage(const UserListRecord *record);

private:
    friend class PartySearchEditPane;
    short m_selectedNationId;
    short m_categoryPage;
    short m_selectedCareerVariant;
    UserListPane *m_bucketPanes[5];
    List *m_allUserRecords;
};

[[No Children Attached]]

// UID:0000FO | by-class/UserListPane.md | Completion:93 | Confidence:94
class MouseEvent;
class UserListRecord;

class UserListPane : public ListPane
{
public:
    UserListPane(int recordSize,
                 int pageSize,
                 UserListPane **siblingPanes,
                 int siblingPaneCount);
    virtual ~UserListPane();

    void SortRecords(ListCompareFunction compare);
    int GetRecordCount() const;
    UserListRecord *GetRecordAt(int index)
    {
        return static_cast<UserListRecord *>(GetItem(index));
    }
    int GetSelectedIndex() const
    {
        return m_selectedIndex;
    }
    UserListRecord *GetSelectedRecord()
    {
        return m_selectedIndex >= 0 ? GetRecordAt(m_selectedIndex) : 0;
    }
    void AddEntry(const UserListRecord *record);
    void SyncSourceText(const UserListRecord *sourceRecord);

    virtual void DrawUserEntry(int itemIndex,
                               const UserListRecord *record,
                               const RectBounds *bounds);
    virtual void OnItemSelected(int itemIndex);
    virtual void OnItemActivated();
    virtual bool OnDoubleClick(const MouseEvent &event);

private:
    EPFTileContext m_statusIconFrames[4];
    EPFTileContext m_badgeIconFrames[16];
    EPFTileContext m_huntersListIconFrame;
    UserListPane **m_siblingPanes;
    int m_siblingPaneCount;
};

[[No Children Attached]]

// UID:0002ZX | by-global/g_bShowHuntersListOnly.md | Completion:88 | Confidence:90
static bool g_bShowHuntersListOnly = false;

// UID:0003EI | by-global/g_pUserListDialogPane.md | Completion:92 | Confidence:94
UserListDialogPane *g_pUserListDialogPane = NULL;
[[No Children Attached]]

// UID:000470 | by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md | Completion:93 | Confidence:94
UserListDialogPane::UserListDialogPane(const unsigned char *packet)
    : Singleton<UserListDialogPane>(),
      DialogPane(L"Users Dialog Pane", 8, 1)
{
    wchar_t localPlayerName[128];
    GetMemoryMan();
    GetLocalPlayerName(localPlayerName, 128);

    const unsigned char playerSettingsFlag = g_pUserPane->m_playerSettingsState[0];
    RectBounds bounds;
    wchar_t countText[12];
    char narrowName[256];
    int filteredCount = 0;
    int visibleCount = 0;

    if (g_useEpfAssets == 1)
    {
        InitRectBounds(&bounds, 0, 0, 709, 452);
        AddControl(new EPFImageControlPane(L"USERLIST.EPF", 0, true, &bounds,
                                           L"USERLIST.PAL"));

        InitRectBounds(&bounds, 608, 412, 671, 436);
        AddControl(new ImageButtonControlPane(15, &bounds));

        g_pUserStatusPane->GetNationId();
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        m_categoryPage = 1;

        const GameServerConfig::NationEntry *nationEntry =
            g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
        const unsigned short selectedNationId = nationEntry->nationId;

        InitRectBounds(&bounds, 82, 391, 154, 403);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        const unsigned short reportedCount = PacketBufferReadUInt16BE(packet + 1);
        const unsigned short entryCount = PacketBufferReadUInt16BE(packet + 3);
        const unsigned char initialSort = packet[5];
        const unsigned char *cursor = packet + 6;

        InitRectBounds(&bounds, 379, 388, 469, 432);
        RadioGroupControlPane *sortControl = new RadioGroupControlPane(&bounds);
        AddControl(sortControl);
        InitRectBounds(&bounds, 0, 1, 88, 15);
        sortControl->AddOption(L"", &bounds);
        InitRectBounds(&bounds, 0, 29, 88, 43);
        sortControl->AddOption(L"", &bounds);
        sortControl->SetSelectedIndex(initialSort);

        int left = 16;
        for (int index = 0; index < 5; ++index)
        {
            m_bucketPanes[index] = new UserListPane(sizeof(UserListRecord), 100,
                                                    m_bucketPanes, 5);
            InitRectBounds(&bounds, left, 95, left + 121, 331);
            AddControl(new ScrollableControlPane(&bounds, m_bucketPanes[index],
                                                 0, 0, 0));
            left += 135;
        }

        m_allUserRecords = new List(sizeof(UserListRecord), 100);

        for (unsigned int ordinal = 0; ordinal < entryCount; ++ordinal)
        {
            UserListRecord record;

            unsigned char encoded = *cursor++;
            record.careerId = encoded >> 4;
            record.bucketIndex = encoded & 7;

            encoded = *cursor++;
            record.statusIconId = encoded >> 4;
            record.badgeIconId = encoded & 7;

            encoded = *cursor++;
            record.careerVariant = encoded >> 4;
            record.huntersListFlag = encoded & 7;

            record.displayColor = *cursor++;
            record.arrivalSortKey = 100000 - ordinal;
            record.reserved2 = 0;

            const unsigned char nameLength = *cursor++;
            memmove(narrowName, cursor, nameLength);
            cursor += nameLength;
            narrowName[nameLength] = '\0';

            const int convertedLength = MultiByteToWideChar(
                CP_ACP, 0, narrowName, nameLength, record.name, 256);
            record.name[convertedLength] = L'\0';
            record.hasSourceText = 0;

            if (wcscmp(record.name, localPlayerName) == 0)
            {
                record.displayColor = 0x80;
                m_selectedCareerVariant = record.careerVariant;
            }

            if (record.reserved2 == 0 || playerSettingsFlag == 1)
                m_allUserRecords->Append(1, &record);
            else
                ++filteredCount;
        }

        for (int index = 0; index < m_allUserRecords->GetCount(); ++index)
        {
            UserListRecord *record = static_cast<UserListRecord *>(
                m_allUserRecords->GetElementAt(index));

            if ((g_bShowHuntersListOnly != 1 || record->huntersListFlag != 0) &&
                ((selectedNationId == 10 &&
                  record->careerVariant == m_selectedCareerVariant) ||
                 record->careerId == selectedNationId))
            {
                UserListPane *pane = record->bucketIndex != 0
                    ? m_bucketPanes[record->bucketIndex - 1]
                    : m_bucketPanes[4];
                pane->AddEntry(record);
            }
        }

        left = 89;
        for (int index = 0; index < 5; ++index)
        {
            if (initialSort == 0)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByStatus);
            else if (initialSort == 1)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByName);

            InitRectBounds(&bounds, left, 344, left + 24, 356);
            swprintf_s(countText, 12, L"%d", m_bucketPanes[index]->GetRecordCount());
            AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                                 &bounds, false, false));
            visibleCount += m_bucketPanes[index]->GetRecordCount();
            left += 135;
        }

        swprintf_s(countText, 12, L"%d",
                   static_cast<unsigned short>(reportedCount - filteredCount));
        InitRectBounds(&bounds, 176, 419, 248, 431);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        swprintf_s(countText, 12, L"%d", static_cast<unsigned short>(visibleCount));
        InitRectBounds(&bounds, 176, 391, 248, 403);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 270, 386, 333, 410);
        AddControl(new ImageButtonControlPane(45, &bounds));

        SimpleUString emptyText;
        InitRectBounds(&bounds, 288, 424, 374, 436);
        AddControl(new StaticTextControlPane(emptyText.c_str(), 1, 128, 0,
                                             &bounds, false, false));

        nationEntry = g_gameServerNationTable->GetNationEntryAtOrDefault(
            m_selectedNationId);
        InitRectBounds(&bounds, 83, 391, 155, 403);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 7, 386, 70, 410);
        AddControl(new ImageButtonControlPane(44, &bounds));

        InitRectBounds(&bounds, 530, 385, 680, 409);
        AddControl(new CheckBoxTextControlPane(
            g_pUserPane->GetHuntersListFlag() != 0, L"", &bounds));

        InitRectBounds(&bounds, 514, 13, 642, 37);
        AddControl(new CheckBoxTextControlPane(g_bShowHuntersListOnly, L"", &bounds));

        SetBackgroundResource(L"US", 0);
        SetHoverControl(1);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetMode(1);
        InitRectBounds(&bounds, 0, 0, 709, 452);
        OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
        OnShow(NULL, NULL);
        SlideOpenVertical();
    }
    else
    {
        InitRectBounds(&bounds, 0, 0, 635, 390);
        AddControl(new EPFImageControlPane(L"USERLIST.EPD", 0, true, &bounds,
                                           L"USERLIST.PAD"));

        InitRectBounds(&bounds, 529, 302, 601, 318);
        AddControl(new ImageButtonControlPane(15, &bounds));

        g_pOldUserStatusPane->GetNationId();
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        m_categoryPage = 1;

        const GameServerConfig::NationEntry *nationEntry =
            g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
        const unsigned short selectedNationId = nationEntry->nationId;

        InitRectBounds(&bounds, 36, 304, 107, 316);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        const unsigned short reportedCount = PacketBufferReadUInt16BE(packet + 1);
        const unsigned short entryCount = PacketBufferReadUInt16BE(packet + 3);
        const unsigned char initialSort = packet[5];
        const unsigned char *cursor = packet + 6;

        InitRectBounds(&bounds, 506, 37, 568, 63);
        RadioGroupControlPane *sortControl = new RadioGroupControlPane(&bounds);
        AddControl(sortControl);
        InitRectBounds(&bounds, 0, 0, 59, 11);
        sortControl->AddOption(L"", &bounds);
        InitRectBounds(&bounds, 0, 16, 59, 26);
        sortControl->AddOption(L"", &bounds);
        sortControl->SetSelectedIndex(initialSort);

        int left = 36;
        for (int index = 0; index < 5; ++index)
        {
            m_bucketPanes[index] = new UserListPane(sizeof(UserListRecord), 100,
                                                    m_bucketPanes, 5);
            InitRectBounds(&bounds, left, 102, left + 110, 282);
            AddControl(new ScrollableControlPane(&bounds, m_bucketPanes[index],
                                                 0, 0, 0));
            left += 113;
        }

        m_allUserRecords = new List(sizeof(UserListRecord), 100);

        for (unsigned int ordinal = 0; ordinal < entryCount; ++ordinal)
        {
            UserListRecord record;

            unsigned char encoded = *cursor++;
            record.careerId = encoded >> 4;
            record.bucketIndex = encoded & 7;

            encoded = *cursor++;
            record.statusIconId = encoded >> 4;
            record.badgeIconId = encoded & 7;

            record.displayColor = *cursor++;
            record.reserved2 = 0;
            record.arrivalSortKey = 100000 - ordinal;

            const unsigned char nameLength = *cursor++;
            memmove(narrowName, cursor, nameLength);
            cursor += nameLength;
            narrowName[nameLength] = '\0';

            const int convertedLength = MultiByteToWideChar(
                CP_ACP, 0, narrowName, nameLength, record.name, 256);
            record.name[convertedLength] = L'\0';

            if (record.reserved2 == 0 || playerSettingsFlag == 1)
            {
                m_allUserRecords->Append(1, &record);

                if (((selectedNationId == 10 &&
                      record.careerVariant == m_selectedCareerVariant) ||
                     record.careerId == selectedNationId) &&
                    record.bucketIndex != 0)
                {
                    m_bucketPanes[record.bucketIndex - 1]->AddEntry(&record);
                }
            }
            else
            {
                ++filteredCount;
            }
        }

        left = 36;
        for (int index = 0; index < 5; ++index)
        {
            if (initialSort == 0)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByStatus);
            else if (initialSort == 1)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByName);

            InitRectBounds(&bounds, left, 285, left + 110, 297);
            swprintf_s(countText, 12, L"%d", m_bucketPanes[index]->GetRecordCount());
            AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                                 &bounds, false, false));
            visibleCount += m_bucketPanes[index]->GetRecordCount();
            left += 113;
        }

        swprintf_s(countText, 12, L"%d",
                   static_cast<unsigned short>(reportedCount - filteredCount));
        InitRectBounds(&bounds, 111, 323, 183, 335);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        swprintf_s(countText, 12, L"%d", static_cast<unsigned short>(visibleCount));
        InitRectBounds(&bounds, 111, 304, 183, 316);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 190, 321, 262, 337);
        AddControl(new ImageButtonControlPane(45, &bounds));

        SimpleUString emptyText;
        InitRectBounds(&bounds, 111, 341, 261, 353);
        AddControl(new StaticTextControlPane(emptyText.c_str(), 1, 128, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 190, 302, 262, 318);
        AddControl(new ImageButtonControlPane(44, &bounds));

        SetBackgroundResource(L"US", 0);
        SetHoverControl(1);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetMode(1);
        InitRectBounds(&bounds, 0, 50, 635, 440);
        OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
        OnShow(NULL, NULL);
        SlideOpenVertical();
    }
}

// UID:000473 | by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md | Completion:88 | Confidence:90
void UserListDialogPane::SortListsByStatus()
{
    for (int index = 0; index < 5; ++index)
    {
        UserListPane *pane = m_bucketPanes[index];
        pane->SortRecords(CompareUserListRecordsByStatus);
        pane->Invalidate();
    }
}

// UID:000474 | by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md | Completion:88 | Confidence:90
void UserListDialogPane::SortListsByName()
{
    for (int index = 0; index < 5; ++index)
    {
        UserListPane *pane = m_bucketPanes[index];
        pane->SortRecords(CompareUserListRecordsByName);
        pane->Invalidate();
    }
}

// UID:000475 | by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md | Completion:93 | Confidence:94
void UserListDialogPane::RefreshCategoryView(char step)
{
    m_categoryPage += step;
    if (m_categoryPage > 5)
        m_categoryPage = 5;
    else if (m_categoryPage < 0)
        m_categoryPage = 0;

    switch (m_categoryPage)
    {
    case 0:
        m_selectedNationId = g_activeUserStatusPane->GetNationId();
        break;
    case 1:
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        break;
    case 2:
        m_selectedNationId = 1;
        break;
    case 3:
        m_selectedNationId = 2;
        break;
    case 4:
        m_selectedNationId = 3;
        break;
    case 5:
        m_selectedNationId = 0;
        break;
    }

    for (int index = 0; index < 5; ++index)
    {
        UserListPane *pane = m_bucketPanes[index];
        pane->RemoveItems(0, pane->GetRecordCount());
    }

    const GameServerConfig::NationEntry *nationEntry =
        g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
    const unsigned short selectedNationId = nationEntry->nationId;

    for (int index = 0; index < m_allUserRecords->GetCount(); ++index)
    {
        UserListRecord *record = static_cast<UserListRecord *>(
            m_allUserRecords->GetElementAt(index));

        if ((!g_bShowHuntersListOnly || record->huntersListFlag != 0) &&
            ((selectedNationId == 10 &&
              record->careerVariant == m_selectedCareerVariant) ||
             record->careerId == selectedNationId))
        {
            UserListPane *pane = record->bucketIndex != 0
                ? m_bucketPanes[record->bucketIndex - 1]
                : m_bucketPanes[4];
            pane->AddEntry(record);
        }
    }

    const int selectedSort =
        GetChild<RadioGroupControlPane>(3)->GetSelectedIndex();
    if (selectedSort == 0)
    {
        for (int index = 0; index < 5; ++index)
        {
            UserListPane *pane = m_bucketPanes[index];
            pane->SortRecords(CompareUserListRecordsByStatus);
            pane->Invalidate();
        }
    }
    else if (selectedSort == 1)
    {
        for (int index = 0; index < 5; ++index)
        {
            UserListPane *pane = m_bucketPanes[index];
            pane->SortRecords(CompareUserListRecordsByName);
            pane->Invalidate();
        }
    }

    wchar_t countText[40];
    int visibleCount = 0;
    for (int index = 0; index < 5; ++index)
    {
        TextEditControlPane *countControl =
            GetChild<TextEditControlPane>(index + 9);
        visibleCount += m_bucketPanes[index]->GetRecordCount();
        swprintf_s(countText, 40, L"%d",
                   m_bucketPanes[index]->GetRecordCount());
        countControl->SetText(countText);
    }

    swprintf_s(countText, 40, L"%d", static_cast<short>(visibleCount));
    GetChild<TextEditControlPane>(15)->SetText(countText);

    nationEntry =
        g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
    if (g_useEpfAssets == 1)
    {
        swprintf_s(countText, 40, nationEntry->label);
        GetChild<TextEditControlPane>(2)->SetText(countText);
        GetChild<TextEditControlPane>(18)->SetText(countText);
    }
    else
    {
        GetChild<TextEditControlPane>(2)->SetText(nationEntry->label);
    }

    Invalidate();
}

// UID:000477 | by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md | Completion:92 | Confidence:94
bool UserListDialogPane::HandlePacketEvent(Event *event)
{
    const char *packet =
        static_cast<const char *>(event->m_payload.m_packet.m_data);

    switch (static_cast<unsigned char>(packet[0]))
    {
    case kUserListHuntersListStateUpdate:
    {
        const unsigned char huntersListFlag =
            static_cast<unsigned char>(packet[1]);

        g_pUserPane->SetHuntersListFlag(huntersListFlag);

        CheckBoxTextControlPane *checkBox =
            GetChild<CheckBoxTextControlPane>(kHuntersListParticipationControl);
        checkBox->SetChecked(huntersListFlag != 0);
        checkBox->Invalidate();

        const int recordCount = m_allUserRecords->GetCount();
        for (int index = 0; index < recordCount; ++index)
        {
            UserListRecord *record = static_cast<UserListRecord *>(
                m_allUserRecords->GetElementAt(index));

            WideString localPlayerName;
            GetLocalPlayerNameString(localPlayerName);
            if (wcscmp(record->name, localPlayerName.c_str()) == 0)
            {
                record->huntersListFlag = huntersListFlag;
                break;
            }
        }

        RefreshCategoryView(0);
        break;
    }

    case kUserListSourceTextUpdate:
    {
        const unsigned char targetNameLength =
            static_cast<unsigned char>(packet[1]);
        wchar_t targetName[256];
        const short targetNameCharacters = static_cast<short>(
            MultiByteToWideChar(CP_ACP, 0, packet + 2, targetNameLength,
                                targetName, 256));
        targetName[targetNameCharacters] = L'\0';

        const unsigned char sourceTextLength =
            static_cast<unsigned char>(packet[targetNameLength + 2]);
        wchar_t sourceText[256];
        const short sourceTextCharacters = static_cast<short>(
            MultiByteToWideChar(CP_ACP, 0,
                                packet + targetNameLength + 3,
                                sourceTextLength, sourceText, 256));
        sourceText[sourceTextCharacters] = L'\0';

        int index = 0;
        if (m_allUserRecords->GetCount() != 0)
        {
            UserListRecord *record;
            do
            {
                record = static_cast<UserListRecord *>(
                    m_allUserRecords->GetElementAt(index));
                if (wcscmp(targetName, record->name) == 0)
                    break;
                ++index;
            }
            while (m_allUserRecords->GetCount() != 0);

            record->hasSourceText = 1;
            wcscpy_s(record->sourceText, 256, sourceText);

            UserListPane *pane = record->bucketIndex != 0
                ? m_bucketPanes[record->bucketIndex - 1]
                : m_bucketPanes[4];
            pane->SyncSourceText(record);
            AddUserListSourceMessage(record);
        }
        break;
    }
    }

    return false;
}

// UID:000478 | by-memory/0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool UserListDialogPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == kPaneKeyPageUp)
    {
        if (event->m_payload.m_key.m_modifiers == 0 &&
            event->m_type == kEventKeyDown)
        {
            RefreshCategoryView(-1);
            return true;
        }
        return DialogPane::HandleKeyOrTextEvent(event);
    }

    if (key == kPaneKeyPageDown)
    {
        if (event->m_payload.m_key.m_modifiers == 0 &&
            event->m_type == kEventKeyDown)
        {
            RefreshCategoryView(1);
            return true;
        }
        return DialogPane::HandleKeyOrTextEvent(event);
    }

    if (key == 'c' &&
        (event->m_payload.m_key.m_modifiers & kEventModifierControl) != 0)
    {
        for (int paneIndex = 0; paneIndex < 5; ++paneIndex)
        {
            if (m_bucketPanes[paneIndex]->GetSelectedIndex() >= 0)
            {
                UserListRecord *record =
                    m_bucketPanes[paneIndex]->GetSelectedRecord();
                TextEditScrap scrap;
                scrap.Clear();
                scrap.SetText(record->name, wcslen(record->name));
                PutScrapToClipboard(&scrap);
            }
        }
        return false;
    }

    return DialogPane::HandleKeyOrTextEvent(event);
}

// UID:000479 | by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md | Completion:90 | Confidence:92
void UserListDialogPane::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    switch (controlIndex)
    {
    case 1:
        SlideCloseVertical();
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        break;

    case 3:
    {
        const int selectedIndex = GetChild<RadioGroupControlPane>(3)->GetSelectedIndex();
        if (selectedIndex == 0)
            SortListsByStatus();
        else if (selectedIndex == 1)
            SortListsByName();
        Invalidate();
        break;
    }

    case 0x10:
        RefreshCategoryView(1);
        break;

    case 0x13:
        RefreshCategoryView(-1);
        break;

    case 0x14:
        new PartySearchEditPane();
        break;

    case 0x15:
    {
        g_bShowHuntersListOnly = !g_bShowHuntersListOnly;
        CheckBoxTextControlPane *checkBox =
            GetChild<CheckBoxTextControlPane>(0x15);
        checkBox->SetChecked(g_bShowHuntersListOnly);
        checkBox->Invalidate();
        RefreshCategoryView(0);
        break;
    }
    }
}

// UID:00047C | by-memory/0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage.md | Completion:90 | Confidence:93
void UserListDialogPane::AddUserListSourceMessage(const UserListRecord *record)
{
    if (g_pChattingDisplayPane == 0)
        return;

    wchar_t message[256];
    swprintf_s(message, L"%s > %s", record->name, record->sourceText);
    g_pChattingDisplayPane->AddChattingMessage(message, 143, 128, 0, 0, 0);
}

// UID:00047D | by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md | Completion:92 | Confidence:94
PartySearchEditPane::PartySearchEditPane()
    : DialogPane(L"", 3, 1)
{
    g_pSoundManager->PlayEffect(0x198, 100);

    RectBounds bounds;
    InitRectBounds(&bounds, 0, 0, 338, 190);
    AddControl(new EPFImageControlPane(L"DLGSETUP.EPF", 0, true, &bounds,
                                       L"DLGSETUP.PAL"));

    InitRectBounds(&bounds, 138, 156, 201, 180);
    AddControl(new ImageButtonControlPane(14, &bounds));

    InitRectBounds(&bounds, 16, 58, 322, 82);
    AddControl(new CheckBoxTextControlPane(
        g_pUserPane->GetHuntersListFlag() != 0,
        L"Put me on the hunters list", &bounds));

    InitRectBounds(&bounds, 16, 88, 322, 126);
    TextEditControlPane *sourceEdit = new TextEditControlPane(
        g_pUserPane->GetPartySearchSourceText(), true, 128, 0, &bounds,
        false, false, true, false, 1.0f, 0);
    sourceEdit->SetMode(1);
    sourceEdit->SetMaxLength(40);
    sourceEdit->SetMaxLines(1);
    AddControl(sourceEdit);

    SetHoverControl(2);
    SetFocusedControl(1);
    SetPendingControl(1);
    SetBackgroundResource(L"DLGSETUP.EPF", 0);

    InitRectBounds(&bounds, 0, 0, 338, 190);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:00047F | by-memory/0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop.md | Completion:92 | Confidence:94
void PartySearchEditPane::OnPaint()
{
}

// UID:00047G | by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md | Completion:92 | Confidence:93
#include "../auth/PasswordGuard.h"

void PartySearchEditPane::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 2)
    {
        CheckBoxTextControlPane *checkBox =
            GetChild<CheckBoxTextControlPane>(2);
        checkBox->SetChecked(!checkBox->GetChecked());
        checkBox->Invalidate();
        return;
    }

    if (controlIndex != 1)
        return;

    SlideCloseVertical();

    g_pUserPane->SetHuntersListFlag(
        GetChild<CheckBoxTextControlPane>(2)->GetChecked());

    wchar_t sourceText[256];
    GetChild<TextEditControlPane>(3)->ReadText(sourceText, 256);
    ValidateChatInputOrThrowPasswordError(sourceText);
    SanitizeWideTextForChat(sourceText,
                            static_cast<unsigned int>(wcslen(sourceText)));
    wcscpy_s(g_pUserPane->GetPartySearchSourceText(), 256, sourceText);

    if (g_pUserListDialogPane != NULL)
    {
        wchar_t localPlayerName[128];
        GetLocalPlayerName(localPlayerName, 128);

        UserListRecord *localRecord = NULL;
        for (int index = 0;
             index < g_pUserListDialogPane->m_allUserRecords->GetCount();
             ++index)
        {
            UserListRecord *record = static_cast<UserListRecord *>(
                g_pUserListDialogPane->m_allUserRecords->GetElementAt(index));
            if (wcscmp(record->name, localPlayerName) == 0)
            {
                localRecord = record;
                break;
            }
        }

        if (localRecord->huntersListFlag !=
                g_pUserPane->GetHuntersListFlag() ||
            wcscmp(localRecord->sourceText,
                   g_pUserPane->GetPartySearchSourceText()) != 0)
        {
            localRecord->huntersListFlag =
                g_pUserPane->GetHuntersListFlag();
            localRecord->hasSourceText = 0;
            wcscpy_s(localRecord->sourceText, 256,
                     g_pUserPane->GetPartySearchSourceText());

            unsigned char packet[259];
            PacketBufferWriteUInt8(0x84, &packet[0]);
            PacketBufferWriteUInt8(localRecord->huntersListFlag, &packet[1]);
            short packetSize = 2;

            if (localRecord->huntersListFlag == 1)
            {
                char encodedText[256];
                const int encodedLength = WideCharToMultiByte(
                    CP_ACP, 0, localRecord->sourceText,
                    static_cast<int>(wcslen(localRecord->sourceText)),
                    encodedText, 256, NULL, NULL);
                PacketBufferWriteUInt8(
                    static_cast<unsigned char>(encodedLength), &packet[2]);
                memcpy(&packet[3], encodedText, encodedLength);
                packetSize = static_cast<short>(encodedLength + 3);
            }

            g_packetSender->QueueAndSendPacket(packet, packetSize);
        }
    }

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

// UID:00047H | by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md | Completion:92 | Confidence:94
UserListPane::UserListPane(int recordSize,
                           int pageSize,
                           UserListPane **siblingPanes,
                           int siblingPaneCount)
    : ListPane(recordSize, pageSize, 108, 12, 0, true, true)
{
    for (int index = 0; index < 4; ++index)
    {
    }

    for (int index = 0; index < 16; ++index)
    {
    }


    if (g_useEpfAssets == 1)
    {
        for (short frameIndex = 0; frameIndex < 4; ++frameIndex)
        {
            g_pEPFLib->CopyEntryTileContext(
                L"STAR.EPF", frameIndex, &m_statusIconFrames[frameIndex]);
        }

        for (short frameIndex = 0; frameIndex < 16; ++frameIndex)
        {
            g_pEPFLib->CopyEntryTileContext(
                L"ICON.EPF", frameIndex, &m_badgeIconFrames[frameIndex]);
        }

        g_pEPFLib->CopyEntryTileContext(
            L"SYMBOLS.EPF", 223, &m_huntersListIconFrame);
    }
    else
    {
        for (short frameIndex = 0; frameIndex < 4; ++frameIndex)
        {
            g_pEPFLib->CopyEntryTileContext(
                L"STAR.EPD", frameIndex, &m_statusIconFrames[frameIndex]);
        }

        for (short frameIndex = 0; frameIndex < 16; ++frameIndex)
        {
            g_pEPFLib->CopyEntryTileContext(
                L"ICON.EPD", frameIndex, &m_badgeIconFrames[frameIndex]);
        }
    }

    m_siblingPanes = siblingPanes;
    m_siblingPaneCount = siblingPaneCount;
}

// UID:00047I | by-memory/0x0059e8a0-0x0059e943.UserListPaneDestructor.md | Completion:92 | Confidence:94
UserListPane::~UserListPane()
{
    for (int index = 0; index < 4; ++index)
    {
        m_statusIconFrames[index].ReleaseBuffers();
    }

    for (int index = 0; index < 16; ++index)
    {
        m_badgeIconFrames[index].ReleaseBuffers();
    }

    m_huntersListIconFrame.ReleaseBuffers();
}

// UID:00047J | by-memory/0x0059e950-0x0059e983.CompareUserListRecordsByStatus.md | Completion:90 | Confidence:92
int __cdecl CompareUserListRecordsByStatus(const UserListRecord *left, const UserListRecord *right)
{
    const int rightStatus = right->statusIconId & 0x0f;
    const int leftStatus = left->statusIconId & 0x0f;

    if (rightStatus == leftStatus)
        return right->arrivalSortKey - left->arrivalSortKey;

    return rightStatus - leftStatus;
}

// UID:00047K | by-memory/0x0059e990-0x0059e9a6.CompareUserListRecordsByName.md | Completion:90 | Confidence:92
int __cdecl CompareUserListRecordsByName(const UserListRecord *left, const UserListRecord *right)
{
    return _wcsicmp(left->name, right->name);
}

// UID:00047N | by-memory/0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText.md | Completion:90 | Confidence:93
void UserListPane::SyncSourceText(const UserListRecord *sourceRecord)
{
    const int count = GetRecordCount();

    for (int index = 0; index < count; ++index)
    {
        UserListRecord *record = GetRecordAt(index);

        if (wcscmp(record->name, sourceRecord->name) != 0)
            continue;

        record->hasSourceText = 1;
        wcscpy_s(record->sourceText, 256, sourceRecord->sourceText);
    }
}

// UID:00047O | by-memory/0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry.md | Completion:92 | Confidence:94
void UserListPane::DrawUserEntry(int itemIndex,
                                 const UserListRecord *record,
                                 const RectBounds *bounds)
{
    m_textDrawMode = 1;
    SetDrawColor(37);

    const RectBounds rowBounds = *bounds;
    RectBounds iconBounds;
    InitRectBounds(&iconBounds, 0, 0, 0, 0);

    if (record->huntersListFlag == 1)
    {
        EPFTileContext &frame = m_huntersListIconFrame;
        const int frameWidth = frame.bounds.right - frame.bounds.left;
        const int frameHeight = frame.bounds.bottom - frame.bounds.top;

        iconBounds.left = 0;
        iconBounds.top = (rowBounds.top + rowBounds.bottom) / 2 - frameHeight / 2;
        iconBounds.right = iconBounds.left + frameWidth;
        iconBounds.bottom = iconBounds.top + frameHeight;

        g_pfnBlitSprite(this,
                        &frame,
                        &frame.bounds,
                        &iconBounds,
                        1,
                        NULL,
                        NULL);
    }

    if (record->statusIconId >= 1 && record->statusIconId <= 4)
    {
        EPFTileContext &frame = m_statusIconFrames[record->statusIconId - 1];
        const int frameWidth = frame.bounds.right - frame.bounds.left;
        const int frameHeight = frame.bounds.bottom - frame.bounds.top;

        iconBounds.left = 12;
        iconBounds.top = (rowBounds.top + rowBounds.bottom) / 2 - frameHeight / 2;
        iconBounds.right = iconBounds.left + frameWidth;
        iconBounds.bottom = iconBounds.top + frameHeight;

        g_pfnBlitSprite(this,
                        &frame,
                        &frame.bounds,
                        &iconBounds,
                        1,
                        NULL,
                        NULL);
    }

    RectBounds badgeBounds;
    InitRectBounds(&badgeBounds, 0, 0, 0, 0);
    if (record->badgeIconId >= 1 && record->badgeIconId <= 4 &&
        record->bucketIndex >= 1 && record->bucketIndex <= 4)
    {
        const int frameIndex =
            (record->bucketIndex - 1) * 4 + (record->badgeIconId - 1);
        EPFTileContext &frame = m_badgeIconFrames[frameIndex];
        const int frameWidth = frame.bounds.right - frame.bounds.left;
        const int frameHeight = frame.bounds.bottom - frame.bounds.top;

        badgeBounds.left = 24;
        badgeBounds.top = (rowBounds.top + rowBounds.bottom) / 2 - frameHeight / 2;
        badgeBounds.right = badgeBounds.left + frameWidth;
        badgeBounds.bottom = badgeBounds.top + frameHeight;

        g_pfnBlitSprite(this,
                        &frame,
                        &frame.bounds,
                        &badgeBounds,
                        1,
                        NULL,
                        NULL);
    }

    unsigned int textColor = record->displayColor;
    if (IsItemSelected(itemIndex))
    {
        SetDrawColor(record->displayColor);
        g_pfnFillRect(this, bounds);
        textColor = 128;
    }
    SetTextColor(textColor);

    for (int index = 0; index < 20; ++index)
    {
        if (_wcsicmp(g_pConfig->m_profileStringSlots[index].c_str(),
                     record->name) == 0)
        {
            SetTextColor(9);
        }
    }

    const int nameLength = static_cast<int>(wcslen(record->name));
    const int nameWidth = GetTextWidth(record->name, nameLength);
    MoveTo(rowBounds.right - nameWidth,
           (rowBounds.top + rowBounds.bottom) / 2 + 6);
    DrawWideText(record->name, nameLength);
}

// UID:00047P | by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md | Completion:87 | Confidence:90
void UserListPane::OnItemSelected(int itemIndex)
{
    for (int index = 0; index < m_siblingPaneCount; ++index)
        m_siblingPanes[index]->SetSelection(-1, false);

    SetSelection(itemIndex, false);
}

// UID:00047Q | by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md | Completion:94 | Confidence:95
void UserListPane::OnItemActivated()
{
    UserListRecord *record = GetRecordAt(m_selectedIndex);

    g_pUserListDialogPane->CloseDialog();

    if (g_useEpfAssets)
        new NewSayToUserMessageInputPane(record->name);
    else
        new SayToUserMessageInputPane(record->name);
}

// UID:00047R | by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md | Completion:89 | Confidence:92
bool UserListPane::OnDoubleClick(const MouseEvent &event)
{
    if (!event.IsLeftDoubleClick() || !ContainsPoint(event.x, event.y))
        return ListPane::OnMouseEvent(event);

    const int itemIndex = HitTestItem(event.x, event.y);
    if (itemIndex < 0)
        return false;

    UserListRecord *record = GetRecordAt(itemIndex);
    if (record == 0 || record->huntersListFlag == 0)
        return false;

    if (record->hasSourceText && g_pUserListDialogPane != 0)
    {
        g_pUserListDialogPane->AddUserListSourceMessage(record);
        return true;
    }

    char name[256];
    const int nameLength = WideCharToMultiByte(CP_ACP, 0, record->name, -1, name, sizeof(name), 0, 0);
    if (nameLength <= 0)
        return true;

    unsigned char packet[258];
    packet[0] = 0x85;
    packet[1] = static_cast<unsigned char>(nameLength - 1);
    memcpy(&packet[2], name, nameLength - 1);
    SendMapPacket(packet, nameLength + 1);
    return true;
}
