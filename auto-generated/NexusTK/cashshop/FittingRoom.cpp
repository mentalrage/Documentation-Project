// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JE
// Source by-file doc: by-file/FittingRoom.md
// UID:000051 | by-class/FittingRoomDialogItemState.md | Completion:90 | Confidence:91
#include <hash_map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <vector>
#include <wchar.h>
#include <windows.h>
#include <shlobj.h>
#include "json/json.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../render/ItemObjImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"
#include "../ui/core/Region.h"
#include "../ui/panels/UserPane.h"

enum FittingRoomCatalogCategory
{
    kFittingRoomCategoryMain = 0,
    kFittingRoomCategoryUsableItems = 1,
    kFittingRoomCategoryWeapons = 2,
    kFittingRoomCategoryMounts = 3,
    kFittingRoomCategoryFace = 4,
    kFittingRoomCategoryHead = 5,
    kFittingRoomCategoryMantle = 6,
    kFittingRoomCategoryNecklaces = 7,
    kFittingRoomCategoryCoats = 8,
    kFittingRoomCategoryShoes = 9,
    kFittingRoomCategorySpecialtySets = 10,
    kFittingRoomCategoryCount = 11
};

struct FittingRoomCatalogPartRecord
{
    signed char part;
    unsigned short tile;
    unsigned char color;
    unsigned char gender;
};

struct FittingRoomCatalogEntry
{
    explicit FittingRoomCatalogEntry(FittingRoomCatalogCategory categoryValue)
        : category(categoryValue),
          parts()
    {
    }

    bool LoadFromJson(const Json::Value& value);
    int GetPartCount() const
    {
        return static_cast<int>(parts.size());
    }
    const FittingRoomCatalogPartRecord* GetPart(signed char partIndex) const;

    FittingRoomCatalogCategory category;
    bool enabled;
    short tile;
    unsigned char color;
    wchar_t name[0x55];
    std::vector<FittingRoomCatalogPartRecord> parts;
};

typedef std::vector<FittingRoomCatalogEntry*> FittingRoomCatalogEntryList;
typedef stdext::hash_map<unsigned char, FittingRoomCatalogEntryList>
    FittingRoomCategoryMap;

class FittingRoomListPane;

struct FittingRoomSelectionEntry
{
    FittingRoomCatalogCategory category;
    wchar_t name[0x50];
    short catalogIndex;
    std::vector<int> partTypes;
};

class FittingRoomDialogItemState
{
    friend class FittingRoomListPane;

public:
    FittingRoomDialogItemState();
    ~FittingRoomDialogItemState();

    void ResetEquipmentEntries();
    void ResetCategoryEntryLists();
    void SaveEncodedStateBuffer(std::string source);
    short GetItemCount(unsigned char category);
    FittingRoomCatalogEntry* GetItemByIndex(
        unsigned char category,
        short itemIndex);
    bool LoadEncodedStateBuffer(std::string source);

private:
    void LoadEncodedCacheFile();
    void TransformPersistedBuffer(char* buffer, int byteCount);
    bool LoadCategoryFromJson(
        const Json::Value& root,
        FittingRoomCatalogCategory category);
    void LoadItemShopTestJson();

    std::string m_catalogVersion;
    wchar_t m_cacheFilePath[260];
    FittingRoomCategoryMap m_categoryLookup;
    std::vector<FittingRoomSelectionEntry> m_selectedFittingItems;
    bool m_cacheLoaded;
    std::string m_encodeKey;
    std::string m_decodeKey;
};


// UID:0000WS | by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md | Completion:88 | Confidence:91
void FittingRoomDialogItemState::ResetEquipmentEntries()
{
    m_selectedFittingItems.clear();
}



// UID:0004WI | by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md | Completion:90 | Confidence:91
// Emitted source for this retained constructor body is covered by
// [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) FittingRoomCatalogEntry(FittingRoomCatalogCategory) and
// [UID:0002E6][0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson](by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md) new FittingRoomCatalogEntry(category).

// UID:0002E4 | by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md | Completion:90 | Confidence:91
bool FittingRoomCatalogEntry::LoadFromJson(const Json::Value& value)
{
    enabled = true;

    const std::string itemName = value.get("name", "None").asString();
    if (itemName == "None") {
        return false;
    }

    const std::wstring wideName(itemName.begin(), itemName.end());
    wcscpy_s(name, 0x50, wideName.c_str());

    tile = static_cast<short>(value.get("tile", -1).asInt());
    tile = static_cast<short>(tile - 0x4000);
    color = static_cast<unsigned char>(value.get("color", -1).asInt());

    Json::Value items = value.get("items", Json::Value());
    const int itemCount = static_cast<int>(items.size());
    for (int index = 0; index < itemCount; ++index) {
        Json::Value partValue = items[index];

        FittingRoomCatalogPartRecord part;
        part.part = static_cast<signed char>(
            partValue.get("part", -11).asInt());
        if (part.part == -11) {
            return false;
        }

        part.tile = static_cast<unsigned short>(partValue.get("tile", -11).asInt());
        part.color = static_cast<unsigned char>(partValue.get("color", -1).asInt());
        part.gender = static_cast<unsigned char>(partValue.get("gender", -1).asInt());
        if (part.gender == 0xff) {
            return false;
        }

        parts.push_back(part);
    }

    return true;
}

// UID:0002E5 | by-memory/0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup.md | Completion:90 | Confidence:91
const FittingRoomCatalogPartRecord* FittingRoomCatalogEntry::GetPart(
    signed char partIndex) const
{
    const int index = static_cast<int>(partIndex);
    if (index >= static_cast<int>(parts.size())) {
        return NULL;
    }

    return &parts[0] + index;
}

// UID:0002E7 | by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md | Completion:90 | Confidence:91
FittingRoomDialogItemState::FittingRoomDialogItemState()
    : m_catalogVersion(""),
      m_cacheLoaded(false),
      m_encodeKey("CASHEncodeDecodeByChris"),
      m_decodeKey("sirhCyBedoceDedocnEHSAC")
{
    m_cacheFilePath[0] = L'\0';

    wchar_t documentsPath[MAX_PATH];
    wchar_t directoryPath[MAX_PATH];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) == S_OK) {
        swprintf_s(directoryPath, MAX_PATH, L"%s\\NexusTK", documentsPath);
        if (CreateDirectoryW(directoryPath, NULL) ||
            GetLastError() == ERROR_ALREADY_EXISTS) {
            swprintf_s(
                directoryPath,
                MAX_PATH,
                L"%s\\NexusTK\\ItemShop",
                documentsPath);
            if (CreateDirectoryW(directoryPath, NULL) ||
                GetLastError() == ERROR_ALREADY_EXISTS) {
                swprintf_s(
                    m_cacheFilePath,
                    MAX_PATH,
                    L"%s\\ItemShop.jbn",
                    directoryPath);
            }
        }
    }

    FILE* cacheFile = _wfopen(m_cacheFilePath, L"rb");
    if (cacheFile == NULL) {
        return;
    }

    fseek(cacheFile, 0, SEEK_END);
    const long fileLength = ftell(cacheFile);
    fseek(cacheFile, 0, SEEK_SET);

    std::string decoded;
    if (fileLength >= 0) {
        char* fileBytes =
            static_cast<char*>(malloc(static_cast<size_t>(fileLength) + 1));
        if (fileBytes != NULL) {
            fileBytes[fileLength] = '\0';
            if (fread(
                    fileBytes,
                    1,
                    static_cast<size_t>(fileLength),
                    cacheFile) == static_cast<size_t>(fileLength)) {
                TransformPersistedBuffer(
                    fileBytes,
                    static_cast<int>(fileLength));
                decoded.assign(fileBytes, static_cast<size_t>(fileLength));
            }
            free(fileBytes);
        }
    }

    fclose(cacheFile);

    if (LoadEncodedStateBuffer(decoded)) {
        m_cacheLoaded = true;
    }
}

// UID:0002EB | by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md | Completion:87 | Confidence:90
FittingRoomDialogItemState::~FittingRoomDialogItemState()
{
    ResetCategoryEntryLists();
}

// UID:0002EC | by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md | Completion:91 | Confidence:92
void FittingRoomDialogItemState::ResetCategoryEntryLists()
{
    for (FittingRoomCategoryMap::iterator category =
             m_categoryLookup.begin();
         category != m_categoryLookup.end();
         ++category) {
        std::vector<FittingRoomCatalogEntry*> entries = category->second;

        for (std::vector<FittingRoomCatalogEntry*>::iterator entry =
                 entries.begin();
             entry != entries.end();
             ++entry) {
            delete *entry;
        }
    }

    m_categoryLookup.clear();
    m_categoryLookup.rehash(8);
}

// UID:0002EF | by-memory/0x004225a0-0x0042268f.FittingRoomDialogItemStateSaveEncodedStateBuffer.md | Completion:89 | Confidence:91
void FittingRoomDialogItemState::SaveEncodedStateBuffer(std::string source)
{
    FILE* cacheFile = _wfopen(m_cacheFilePath, L"wb");
    if (cacheFile != NULL) {
        const size_t byteCount = source.length();
        char* fileBytes = static_cast<char*>(malloc(byteCount + 1));
        strcpy_s(fileBytes, byteCount + 1, source.c_str());

        TransformPersistedBuffer(fileBytes, static_cast<int>(byteCount));
        fwrite(fileBytes, 1, byteCount, cacheFile);
        fclose(cacheFile);
        free(fileBytes);
    }

    m_cacheLoaded = true;
}

// UID:0000WV | by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md | Completion:94 | Confidence:95
short FittingRoomDialogItemState::GetItemCount(unsigned char category)
{
    FittingRoomCategoryMap::iterator position =
        m_categoryLookup.find(category);
    if (position == m_categoryLookup.end()) {
        return 0;
    }

    return static_cast<short>(position->second.size());
}

FittingRoomCatalogEntry* FittingRoomDialogItemState::GetItemByIndex(
    unsigned char category,
    short itemIndex)
{
    FittingRoomCategoryMap::iterator position =
        m_categoryLookup.find(category);
    if (position == m_categoryLookup.end()) {
        return NULL;
    }

    std::vector<FittingRoomCatalogEntry*> entries = position->second;
    if (static_cast<short>(entries.size()) <= itemIndex) {
        return NULL;
    }

    return entries[itemIndex];
}

// UID:0002E9 | by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md | Completion:87 | Confidence:90
bool FittingRoomDialogItemState::LoadEncodedStateBuffer(std::string source)
{
    Json::Value root;
    Json::Reader reader;
    reader.parse(source, root, true);

    const Json::Value versionValue = root.get("version", Json::Value());
    if (versionValue.isNull()) {
        return false;
    }

    m_catalogVersion = versionValue.asString();

    for (int category = 0; category < kFittingRoomCategoryCount; ++category) {
        if (!LoadCategoryFromJson(
                root,
                static_cast<FittingRoomCatalogCategory>(category))) {
            return false;
        }
    }

    return true;
}


// UID:0002EG | by-memory/0x004229f0-0x00422b25.FittingRoomDialogItemStateLoadEncodedCacheFile.md | Completion:88 | Confidence:90
void FittingRoomDialogItemState::LoadEncodedCacheFile()
{
    FILE* cacheFile = _wfopen(m_cacheFilePath, L"rb");
    if (cacheFile == NULL) {
        return;
    }

    fseek(cacheFile, 0, SEEK_END);
    const long fileLength = ftell(cacheFile);
    fseek(cacheFile, 0, SEEK_SET);

    std::string decoded;
    char* fileBytes = static_cast<char*>(malloc(static_cast<size_t>(fileLength) + 1));
    fileBytes[fileLength] = '\0';

    if (fread(fileBytes, 1, static_cast<size_t>(fileLength), cacheFile) ==
        static_cast<size_t>(fileLength)) {
        TransformPersistedBuffer(fileBytes, static_cast<int>(fileLength));
        decoded.assign(fileBytes);
    }

    fclose(cacheFile);
    free(fileBytes);

    if (LoadEncodedStateBuffer(decoded)) {
        m_cacheLoaded = true;
    }
}

// UID:0002E8 | by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md | Completion:88 | Confidence:91
void FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)
{
    const int keyLength = static_cast<int>(m_encodeKey.length());

    for (int index = 0; index < byteCount; ++index) {
        const int keyIndex = index % keyLength;
        buffer[index] ^= m_encodeKey[keyIndex];
        buffer[index] ^= m_decodeKey[keyIndex];
    }
}

// UID:0002E6 | by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md | Completion:90 | Confidence:91
bool FittingRoomDialogItemState::LoadCategoryFromJson(
    const Json::Value& root,
    FittingRoomCatalogCategory category)
{
    const char* categoryKey;

    switch (category) {
    case kFittingRoomCategoryMain:
        categoryKey = "main";
        break;
    case kFittingRoomCategoryUsableItems:
        categoryKey = "usable_items";
        break;
    case kFittingRoomCategoryWeapons:
        categoryKey = "weapons";
        break;
    case kFittingRoomCategoryMounts:
        categoryKey = "mounts";
        break;
    case kFittingRoomCategoryFace:
        categoryKey = "face";
        break;
    case kFittingRoomCategoryHead:
        categoryKey = "head";
        break;
    case kFittingRoomCategoryMantle:
        categoryKey = "mantle";
        break;
    case kFittingRoomCategoryNecklaces:
        categoryKey = "necklaces";
        break;
    case kFittingRoomCategoryCoats:
        categoryKey = "coats";
        break;
    case kFittingRoomCategoryShoes:
        categoryKey = "shoes";
        break;
    case kFittingRoomCategorySpecialtySets:
        categoryKey = "specialty_sets";
        break;
    default:
        return false;
    }

    Json::Value categoryValue = root.get(categoryKey, Json::Value());
    if (categoryValue.isNull()) {
        return false;
    }

    std::vector<FittingRoomCatalogEntry*> entries;
    const int itemCount = static_cast<int>(categoryValue.size());

    for (int index = 0; index < itemCount; ++index) {
        Json::Value itemValue = categoryValue[index];
        FittingRoomCatalogEntry* entry =
            new FittingRoomCatalogEntry(category);

        if (!entry->LoadFromJson(itemValue)) {
            return false;
        }

        entries.push_back(entry);
    }

    m_categoryLookup.insert(
        std::make_pair(static_cast<unsigned char>(category), entries));
    return true;
}

// UID:0002ED | by-memory/0x00422ec0-0x00422ff1.FittingRoomItemShopTestJsonLoader.md | Completion:88 | Confidence:90
void FittingRoomDialogItemState::LoadItemShopTestJson()
{
    FILE* testFile = NULL;
    fopen_s(&testFile, "test.json", "rb");
    if (testFile == NULL) {
        return;
    }

    fseek(testFile, 0, SEEK_END);
    const long fileLength = ftell(testFile);
    fseek(testFile, 0, SEEK_SET);

    std::string source;
    char* fileBytes = static_cast<char*>(malloc(static_cast<size_t>(fileLength) + 1));
    fileBytes[fileLength] = '\0';

    if (fread(fileBytes, 1, static_cast<size_t>(fileLength), testFile) ==
        static_cast<size_t>(fileLength)) {
        source.assign(fileBytes);
    }

    fclose(testFile);
    free(fileBytes);

    if (!LoadEncodedStateBuffer(source)) {
        ResetCategoryEntryLists();
    }
}


// UID:0002UE | by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md | Completion:88 | Confidence:90
// Emitted code for this range is covered by [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) FittingRoomDialogItemState::~FittingRoomDialogItemState() and the [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) field lifecycle.
// Retain this page as vector-storage cleanup evidence for FittingRoomDialogItemState::m_selectedFittingItems.

// UID:0002UF | by-memory/0x004238f0-0x00423952.FittingRoomCategoryEntryVectorDestroy.md | Completion:88 | Confidence:91
// Emitted code for this range is covered by [UID:0002EC][0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries](by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md) FittingRoomDialogItemState::ResetCategoryEntryLists() and the [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) FittingRoomCatalogEntry::parts field lifecycle.
// Retain this page as vector-storage cleanup evidence for FittingRoomCatalogEntry::parts.


// UID:000050 | by-class/FittingRoomDialog.md | Completion:91 | Confidence:92
#include "../ui/core/BlackHole.h"
#include "../map/ObjectStatusBlob.h"
#include "../ui/core/DialogPane.h"
#include "CashShopRequest.h"

class FittingRoomListPane;

enum FittingRoomDialogCommand
{
    kFittingRoomCommandClose = 0,
    kFittingRoomCommandRotateRight = 3,
    kFittingRoomCommandRotateLeft = 4,
    kFittingRoomCommandBasic = 5,
    kFittingRoomCommandCurrent = 6,
    kFittingRoomCommandUsableItems = 7,
    kFittingRoomCommandWeapons = 8,
    kFittingRoomCommandMounts = 9,
    kFittingRoomCommandFace = 10,
    kFittingRoomCommandHead = 11,
    kFittingRoomCommandMantle = 12,
    kFittingRoomCommandNecklaces = 13,
    kFittingRoomCommandCoats = 14,
    kFittingRoomCommandShoes = 15,
    kFittingRoomCommandSpecialtySets = 16
};

struct FittingRoomCategoryButtonDef
{
    int commandId;
    const wchar_t* label;
};

class FittingRoomDialog : public DialogPane
{
    friend class FittingRoomListPane;

public:
    FittingRoomDialog();
    virtual ~FittingRoomDialog();

protected:
    virtual void OnCommand(int commandId);
    virtual void DrawBackground();
    virtual bool HandleFittingAction(int action, int arg0, int arg1);

private:
    int ShowPreview();
    void RebuildCategoryButtons();
    void SelectButton(int commandId);

    ObjectStatusBlob m_baseAppearance;
    ObjectStatusBlob m_previewAppearance;
    FittingRoomDialogItemState m_itemState;
    int m_activeCategory;
    int m_selectedCategoryCommandId;
    int m_categoryListState;
    std::string m_itemShopVersion;
    CashShopRequest* m_activeCatalogRequest;
};

typedef char FittingRoomDialogSizeMustBe1964[
    sizeof(FittingRoomDialog) == 0x7ac ? 1 : -1];

extern FittingRoomDialog* g_pFittingRoomDialog;

// UID:0002CP | by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md | Completion:86 | Confidence:91
FittingRoomDialog::FittingRoomDialog()
    : DialogPane(L""),
      m_itemState(),
      m_activeCategory(0),
      m_selectedCategoryCommandId(-1),
      m_reservedCategoryState(0),
      m_cachedEquipmentName(),
      m_pendingCatalogRequest(NULL)
{
    g_pFittingRoomDialog = this;

    CopyCollectionAppearance(&m_baseAppearance, g_pCollectionData, 0x13eb40, 0x44);
    CopyCollectionAppearance(&m_previewAppearance, g_pCollectionData, 0x13eb40, 0x44);
    m_baseAppearance.byte28 = 0;
    m_baseAppearance.byte34 = 0x50;
    m_previewAppearance.byte28 = 0;
    m_previewAppearance.byte34 = 0x50;

    RectBounds bounds;
    GetFittingRoomControlBounds(0, &bounds);
    AddControl(new ButtonControlPane(14, &bounds));

    GetFittingRoomControlBounds(1, &bounds);
    AddControl(new FittingRoomUserImageControlPane(&bounds, &m_baseAppearance));

    GetFittingRoomControlBounds(2, &bounds);
    FittingRoomListPane* listPane = new FittingRoomListPane(&bounds);
    listPane->SetVisibleFlag();
    listPane->Show();
    AddControl(listPane);

    GetFittingRoomControlBounds(3, &bounds);
    AddControl(new ButtonControlPane(44, &bounds));

    GetFittingRoomControlBounds(4, &bounds);
    AddControl(new ButtonControlPane(45, &bounds));

    GetFittingRoomControlBounds(5, &bounds);
    AddControl(new FittingRoomTextButtonControlPane(L"Basic", &bounds));

    GetFittingRoomControlBounds(6, &bounds);
    AddControl(new FittingRoomTextButtonControlPane(L"Current", &bounds));

    GetFittingRoomControlBounds(2, &bounds);
    FittingRoomDownloadControlPane* downloadPane = new FittingRoomDownloadControlPane(7, &bounds);
    downloadPane->SetProgressPercent(0);
    AddControl(downloadPane);

    RectBounds dialogRect;
    InitRectBounds(&dialogRect, 102, 134, 820, 500);
    SetDialogResourceName(L"USERLOOK.EPF");
    ShowInLayer(&dialogRect, 0, 0, g_mainUiLayerSlots[2]);
    InitializeDialogControls();
    EnableDialogInput();
    ActivateDialog();

    SubmitCashShopVersionRequest(g_pCashShopRequest, 10002);
    m_timerHandler.ScheduleTimer(0, 100, 0, 0);
}

// UID:0002CQ | by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md | Completion:87 | Confidence:91
void FittingRoomDialog::OnCommand(int commandId)
{
    switch (commandId) {
    case kFittingRoomCommandClose:
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return;

    case kFittingRoomCommandRotateRight: {
        FittingRoomUserImageControlPane* pane =
            static_cast<FittingRoomUserImageControlPane*>(m_controlManager->FindControlById(1));
        if (pane != NULL)
            pane->AdvanceFacingDirection();
        return;
    }

    case kFittingRoomCommandRotateLeft: {
        FittingRoomUserImageControlPane* pane =
            static_cast<FittingRoomUserImageControlPane*>(m_controlManager->FindControlById(1));
        if (pane != NULL)
            pane->RetreatFacingDirection();
        return;
    }

    case kFittingRoomCommandBasic:
        CopyCollectionAppearance(&m_baseAppearance, g_pCollectionData, 0x13eb40, 0x44);
        NormalizeBasicFittingAppearance(&m_baseAppearance);
        m_previewAppearance = m_baseAppearance;
        m_itemState.ResetEquipmentEntries();
        break;

    case kFittingRoomCommandCurrent:
        CopyCollectionAppearance(&m_baseAppearance, g_pCollectionData, 0x13eb40, 0x44);
        m_baseAppearance.m_compositionMode = 0;
        m_previewAppearance = m_baseAppearance;
        m_itemState.ResetEquipmentEntries();
        break;

    case kFittingRoomCommandUsableItems:
    case kFittingRoomCommandWeapons:
    case kFittingRoomCommandMounts:
    case kFittingRoomCommandFace:
    case kFittingRoomCommandHead:
    case kFittingRoomCommandMantle:
    case kFittingRoomCommandNecklaces:
    case kFittingRoomCommandCoats:
    case kFittingRoomCommandShoes:
    case kFittingRoomCommandSpecialtySets:
        SelectButton(commandId);
        m_activeCategory = commandId - kFittingRoomCommandUsableItems + 1;
        break;

    default:
        return;
    }

    FittingRoomListPane* listPane =
        static_cast<FittingRoomListPane*>(m_controlManager->FindControlById(2));
    if (listPane != NULL)
        listPane->ResetScrollPosition();
}

// UID:0002CS | by-memory/0x0041c5e0-0x0041cb63.FittingRoomDialogDrawBackground.md | Completion:87 | Confidence:91
void FittingRoomDialog::DrawBackground()
{
    RectBounds content;
    content.left = m_bounds.left + 11;
    content.top = m_bounds.top + 42;
    content.right = m_bounds.right - 11;
    content.bottom = m_bounds.bottom - 40;

    EPFTileContext tile;
    tile.Open(L"WBOARDBK.EPF");
    const ResourceFrame* centerFrame = LookupResourceFrame(&tile, 0);

    DrawState savedState;
    SaveGrafPortDrawState(&savedState);
    SetGrafPortClipRect(&content);

    if (centerFrame != NULL && centerFrame->width > 0 && centerFrame->height > 0) {
        for (int y = content.top; y < content.bottom; y += centerFrame->height) {
            for (int x = content.left; x < content.right; x += centerFrame->width) {
                RectBounds tileRect;
                InitRectLTRB(&tileRect, x, y, x + centerFrame->width, y + centerFrame->height);
                RenderTileFrame(&tile, 0, L"WBOARDBK.PAL", &tileRect);
            }
        }
    }

    RestoreGrafPortDrawState(&savedState);
    tile.Close();

    EPFTileContext frame;
    frame.Open(L"WEBBOARD.EPF");

    const int width = m_bounds.right - m_bounds.left;
    const int height = m_bounds.bottom - m_bounds.top;

    for (int x = 37; x < width - 37; x += 37) {
        DrawResourceFrame(&frame, 1, L"WEBBOARD.PAL", x, 0, 37, 42);
        DrawResourceFrame(&frame, 6, L"WEBBOARD.PAL", x, height - 40, 37, 40);
    }

    for (int y = 42; y < height - 40; y += 40) {
        DrawResourceFrame(&frame, 3, L"WEBBOARD.PAL", 0, y, 11, 40);
        DrawResourceFrame(&frame, 4, L"WEBBOARD.PAL", width - 11, y, 11, 40);
    }

    DrawResourceFrame(&frame, 0, L"WEBBOARD.PAL", 0, 0, 37, 42);
    DrawResourceFrame(&frame, 2, L"WEBBOARD.PAL", width - 37, 0, 37, 42);
    DrawResourceFrame(&frame, 5, L"WEBBOARD.PAL", 0, height - 40, 37, 40);
    DrawResourceFrame(&frame, 7, L"WEBBOARD.PAL", width - 37, height - 40, 37, 40);

    frame.Close();
}

// UID:0002CT | by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md | Completion:88 | Confidence:91
bool FittingRoomDialog::HandleFittingAction(int action, int /*unused1*/, int /*unused2*/)
{
    enum
    {
        kCheckCatalogVersionAction = 0,
        kPollCatalogRequestAction = 1,
        kFittingActionDelayMs = 100,
        kDownloadProgressControlId = 7
    };

    switch (action) {
    case kPollCatalogRequestAction:
    {
        bool reachedTerminalProgress = false;

        if (m_activeCatalogRequest != NULL) {
            FittingRoomDownloadControlPane *progressPane =
                static_cast<FittingRoomDownloadControlPane *>(
                    m_controlManager->FindControlById(kDownloadProgressControlId));

            const unsigned char progressPercent =
                m_activeCatalogRequest->downloadProgress.GetUsagePercent();

            if (progressPane->m_progressPercent != progressPercent) {
                progressPane->m_progressPercent = progressPercent;
                progressPane->Invalidate(false);
                reachedTerminalProgress = (progressPercent >= 100);
            }
        }

        if (m_activeCatalogRequest == NULL ||
            !m_activeCatalogRequest->downloadProgress.downloadComplete ||
            reachedTerminalProgress) {
            m_fittingActionTimer.ScheduleTimer(kPollCatalogRequestAction,
                                               kFittingActionDelayMs, 0, 0);
            return true;
        }

        m_itemState.ResetCategoryEntries();

        if (m_itemState.LoadEncodedStateBuffer(
                m_activeCatalogRequest->responseText) == 1) {
            m_itemState.SaveEncodedStateBuffer(m_activeCatalogRequest->responseText);
            ShowPreview();
        }
        return true;
    }

    case kCheckCatalogVersionAction:
    {
        if (CompareEquipmentNames(m_itemShopVersion.c_str(),
                                  static_cast<unsigned int>(m_itemShopVersion.length()),
                                  "",
                                  0)) {
            m_fittingActionTimer.ScheduleTimer(kCheckCatalogVersionAction,
                                               kFittingActionDelayMs, 0, 0);
            return true;
        }

        const std::string cachedVersionText = m_itemState.GetCachedVersionText();
        if (CompareEquipmentNames(m_itemShopVersion.c_str(),
                                  static_cast<unsigned int>(m_itemShopVersion.length()),
                                  cachedVersionText.c_str(),
                                  static_cast<unsigned int>(cachedVersionText.length()))) {
            ShowPreview();
            return true;
        }

        FittingRoomDownloadControlPane *progressPane =
            static_cast<FittingRoomDownloadControlPane *>(
                m_controlManager->FindControlById(kDownloadProgressControlId));
        progressPane->m_catalogRequestPending = true;
        progressPane->Invalidate(false);

        g_pFileDownloader->SubmitCashShopCatalogRequest();
        m_fittingActionTimer.ScheduleTimer(kPollCatalogRequestAction,
                                           kFittingActionDelayMs, 0, 0);
        return true;
    }

    default:
        return true;
    }
}

// UID:0002CU | by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md | Completion:87 | Confidence:91
int FittingRoomDialog::ShowPreview()
{
    RefreshDialogStateForDisplay();
    RebuildCategoryButtons();

    FittingRoomListPane* listPane =
        static_cast<FittingRoomListPane*>(m_controlManager->FindControlById(2));
    if (listPane != NULL) {
        listPane->SetVisibleFlag();
        listPane->Show();
    }

    RectBounds dialogRect;
    InitRectBounds(&dialogRect, 102, 134, 820, 500);
    return ShowInLayer(&dialogRect, 0, 0, g_mainUiLayerSlots[2]);
}

// UID:0002CV | by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md | Completion:87 | Confidence:91
void FittingRoomDialog::RebuildCategoryButtons()
{
    static const FittingRoomCategoryButtonDef kButtons[] = {
        { kFittingRoomCommandUsableItems, L"UsableItems" },
        { kFittingRoomCommandWeapons, L"Weapons" },
        { kFittingRoomCommandMounts, L"Mounts" },
        { kFittingRoomCommandFace, L"Face" },
        { kFittingRoomCommandHead, L"Head" },
        { kFittingRoomCommandMantle, L"Mantle" },
        { kFittingRoomCommandNecklaces, L"Necklaces" },
        { kFittingRoomCommandCoats, L"Coats" },
        { kFittingRoomCommandShoes, L"Shoes" },
        { kFittingRoomCommandSpecialtySets, L"SpecialtySets" },
    };

    ControlPane* oldFirstButton = *static_cast<ControlPane **>(
        m_controlManager->GetElementAt(kFittingRoomCommandUsableItems));
    if (oldFirstButton != NULL) {
        RemoveControl(kFittingRoomCommandUsableItems);
        oldFirstButton->Release(true);
    }

    for (unsigned int i = 0; i < sizeof(kButtons) / sizeof(kButtons[0]); ++i) {
        RectBounds bounds;
        GetFittingRoomControlBounds(kButtons[i].commandId, &bounds);

        FittingRoomTextButtonControlPane* button =
            new FittingRoomTextButtonControlPane(kButtons[i].label, &bounds);
        AddControl(button);

        if (i == 0 && m_itemState.GetItemCount(0) <= 0) {
            button->SetSelected(true);
            m_selectedCategoryCommandId = kFittingRoomCommandUsableItems;
        }
    }

    InvalidateRect(&m_bounds);
}

// UID:0002CX | by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md | Completion:88 | Confidence:92
void FittingRoomDialog::SelectButton(int commandId)
{
    FittingRoomTextButtonControlPane* oldButton = NULL;
    FittingRoomTextButtonControlPane* newButton = NULL;

    if (m_selectedCategoryCommandId > 0) {
        oldButton = static_cast<FittingRoomTextButtonControlPane*>(
            m_controlManager->FindControlById(m_selectedCategoryCommandId));
    }

    if (commandId > 0) {
        newButton = static_cast<FittingRoomTextButtonControlPane*>(
            m_controlManager->FindControlById(commandId));
    }

    m_selectedCategoryCommandId = commandId;

    if (oldButton != NULL) {
        oldButton->SetSelected(false);
        oldButton->InvalidateRect(NULL);
    }

    if (newButton != NULL) {
        newButton->SetSelected(true);
        newButton->InvalidateRect(NULL);
    }
}

// UID:0002CR | by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md | Completion:88 | Confidence:91
FittingRoomDialog::~FittingRoomDialog()
{
    if (m_activeCatalogRequest != NULL) {
        if (m_activeCatalogRequest->downloadComplete) {
            delete m_activeCatalogRequest;
        }
        m_activeCatalogRequest = NULL;
    }

    g_pFittingRoomDialog = NULL;
}

// UID:000053 | by-class/FittingRoomListPane.md | Completion:91 | Confidence:92
#include "../ui/core/ControlPane.h"
#include "../ui/core/Event.h"
#include "../ui/core/Region.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../render/ItemObjImageLib.h"
#include "../render/Surface.h"
#include "../ui/panels/UserPane.h"
#include "../util/StringUtil.h"

class FittingRoomScrollPane;
class Layer;
struct PaneKeyEvent;
struct Point;
struct RectBounds;

typedef short FittingRoomSlotIndex;

enum FittingRoomListDisplayMode
{
    FittingRoomListDisplayMode_Rows = 0,
    FittingRoomListDisplayMode_Grid = 1
};

static const int kFittingRoomRowPageSize = 26;
static const int kFittingRoomGridPageRows = 3;
static const int kFittingRoomGridColumns = 6;
static const int kFittingRoomGridVisibleCells = 18;
static const int kFittingRoomMaxScroll = 30000;
static const FittingRoomSlotIndex kInvalidFittingRoomSlot = -1;

class FittingRoomListPane : public ControlPane
{
public:
    explicit FittingRoomListPane(const RectBounds *bounds);
    virtual ~FittingRoomListPane();

    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition,
                                 short newPosition);

protected:
    virtual void OnResize(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *oldBounds);
    virtual void OnInsertPane(const RectBounds *bounds,
                              int order,
                              Pane *previousPane,
                              Layer *layerOrContext);
    virtual void OnDetachPane();
    virtual void OnPaint();
    virtual bool OnKeyScroll(PaneKeyEvent *event);
    virtual bool OnInputEvent(Event *event);
    virtual bool OnScrollStep(int direction, int arg0, int arg1);

private:
    void UpdateScrollBar();
    void ResetScrollPosition();
    void GetItemSlotRect(FittingRoomSlotIndex slotIndex,
                         RectBounds *rect);
    FittingRoomSlotIndex HitTestSlot(int localX, int localY);
    FittingRoomSlotIndex ValidateFittingSelectionIndex(
        FittingRoomSlotIndex candidate) const;
    void GetItemSlotOrigin(Point *point,
                           FittingRoomSlotIndex slotIndex);
    void CancelPendingSlotTimer();

    short m_scrollPosition;
    short m_enabledItemCount;
    FittingRoomListDisplayMode m_displayMode;
    int m_listState0;
    int m_listState1;
    int m_listState2;
    FittingRoomScrollPane *m_scrollPane;

#pragma pack(push, 1)
    struct
    {
        unsigned char m_selectionState;
        short m_selectedItemIndex;
        unsigned char m_selectionFlags;
    };
#pragma pack(pop)

    unsigned int m_pendingSlotTimer;
    unsigned char m_stateFlags;
};

typedef char FittingRoomListPaneSizeMustBe300[
    sizeof(FittingRoomListPane) == 0x12c ? 1 : -1];

// UID:000054 | by-class/FittingRoomScrollPane.md | Completion:90 | Confidence:92
struct PaneMouseEvent;
class FittingRoomListPane;

enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};

class FittingRoomScrollPane : public Pane
{
public:
    explicit FittingRoomScrollPane(unsigned char orientation);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool DefaultVirtualFalse(int value);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnDraw();

private:
    friend class FittingRoomListPane;

    FittingRoomScrollPart HitTestPart(int localY, int localX);
    void GetPartRect(FittingRoomScrollPart part, RectBounds *rect);
    void SetHotPart(FittingRoomScrollPart part);
    void BeginPartPress(FittingRoomScrollPart part,
                        int localY,
                        int localX);
    void ProcessActivePart();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_scrollEnabled;
    signed char m_hotPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char FittingRoomScrollPaneSizeMustBe272[
    sizeof(FittingRoomScrollPane) == 0x110 ? 1 : -1];

// UID:000493 | by-memory/0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw.md | Completion:89 | Confidence:91
void FittingRoomScrollPane::SetHotPart(FittingRoomScrollPart part)
{
    RectBounds rect;
    FittingRoomScrollPart oldPart;

    oldPart = static_cast<FittingRoomScrollPart>(m_hotPart);
    if (oldPart == part) {
        return;
    }

    if (oldPart != kFittingRoomScrollPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kFittingRoomScrollPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_hotPart = static_cast<int8_t>(part);
}

// UID:000494 | by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md | Completion:89 | Confidence:91
void FittingRoomScrollPane::BeginPartPress(FittingRoomScrollPart part, int mouseY, int mouseX)
{
    RectBounds rect;

    if (part == kFittingRoomScrollPartThumb) {
        if (m_hotPart != kFittingRoomScrollPartThumb) {
            if (m_hotPart != kFittingRoomScrollPartNone) {
                GetPartRect(static_cast<FittingRoomScrollPart>(m_hotPart), &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kFittingRoomScrollPartThumb, &rect);
            InvalidateRect(&rect);
            m_hotPart = static_cast<int8_t>(kFittingRoomScrollPartThumb);
        }

        GetPartRect(kFittingRoomScrollPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset, mouseY - rect.top, mouseX - rect.left);
    }

    m_activePart = static_cast<int8_t>(part);
    ProcessActivePart();
    m_repeatTimer.ScheduleTimer(0, 200, 0, 0);
}

// UID:0002D5 | by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md | Completion:90 | Confidence:92
void FittingRoomScrollPane::ProcessActivePart()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    if (m_activePart == kFittingRoomScrollPartThumb) {
        UpdatePositionFromCursor(cursor.y, cursor.x);
        return;
    }

    const FittingRoomScrollPart hitPart =
        HitTestPart(cursor.y, cursor.x);
    if (hitPart == m_activePart) {
        UpdatePositionFromCursor(cursor.y, cursor.x);
    }

    if (m_hotPart != kFittingRoomScrollPartNone) {
        GetPartRect(static_cast<FittingRoomScrollPart>(m_hotPart),
                    &rect);
        InvalidateRect(&rect);
        m_hotPart = kFittingRoomScrollPartNone;
    }
}

// UID:0002D9 | by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md | Completion:92 | Confidence:94
void FittingRoomScrollPane::UpdatePositionFromCursor(int localY, int localX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    short oldPosition;
    short newPosition;
    int thumbStart;
    int maxThumbStart;
    int trackStart;
    int trackSpan;

    oldPosition = m_scrollPosition;
    GetPartRect(kFittingRoomScrollPartThumb, &thumbRect);

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

    if (m_orientation != 0) {
        thumbStart = localX - m_thumbDragOffset.x + 1;
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
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        thumbStart = localY - m_thumbDragOffset.y + 1;
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
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        static_cast<FittingRoomListPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
}

// UID:0002DB | by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md | Completion:88 | Confidence:90
void FittingRoomScrollPane::ResetScrollState()
{
    RectBounds rect;

    m_repeatTimer.RemovePendingTimers();

    const int8_t oldHotPart = m_hotPart;
    m_activePart = kFittingRoomScrollPartNone;

    if (oldHotPart != kFittingRoomScrollPartNone) {
        GetPartRect(static_cast<FittingRoomScrollPart>(oldHotPart), &rect);
        InvalidateRect(&rect);
        m_hotPart = kFittingRoomScrollPartNone;
    }
}

// UID:0002D2 | by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md | Completion:90 | Confidence:92
bool FittingRoomScrollPane::OnMouseEvent(const PaneMouseEvent& event)
{
    bool handled = false;
    RectBounds partRect;

    switch (event.type) {
    case kPaneMouseMove:
        if (m_activePart != kFittingRoomScrollPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kPaneMouseDown:
        if (!PointInRect(event.y, event.x, &m_bounds)) {
            return false;
        }
        if (!m_scrollEnabled || m_scrollRange <= 0) {
            return false;
        }

        if (m_activePart == kFittingRoomScrollPartNone) {
            const FittingRoomScrollPart part =
                HitTestPart(event.y, event.x);

            if (part != kFittingRoomScrollPartNone) {
                CaptureMouse();

                if (part == kFittingRoomScrollPartThumb) {
                    if (m_hotPart != kFittingRoomScrollPartThumb) {
                        if (m_hotPart != kFittingRoomScrollPartNone) {
                            GetPartRect(
                                static_cast<FittingRoomScrollPart>(
                                    m_hotPart),
                                &partRect);
                            InvalidateRect(&partRect);
                        }

                        GetPartRect(kFittingRoomScrollPartThumb, &partRect);
                        InvalidateRect(&partRect);
                        m_hotPart = kFittingRoomScrollPartThumb;
                    }

                    GetPartRect(kFittingRoomScrollPartThumb, &partRect);
                    m_thumbDragOffset.y = event.y - partRect.top;
                    m_thumbDragOffset.x = event.x - partRect.left;
                }

                m_activePart = static_cast<signed char>(part);
                ProcessActivePart();
                m_repeatTimer.ScheduleTimer(0, 200, 0, 0);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kPaneMouseUp:
        if (m_activePart != kFittingRoomScrollPartNone) {
            ReleaseMouseCapture();
            m_repeatTimer.RemovePendingTimers();

            const signed char oldHotPart = m_hotPart;
            m_activePart = kFittingRoomScrollPartNone;
            if (oldHotPart != kFittingRoomScrollPartNone) {
                GetPartRect(
                    static_cast<FittingRoomScrollPart>(oldHotPart),
                    &partRect);
                InvalidateRect(&partRect);
                m_hotPart = kFittingRoomScrollPartNone;
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

// UID:0002D3 | by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md | Completion:91 | Confidence:92
bool FittingRoomScrollPane::DefaultVirtualFalse(int)
{
    return false;
}

// UID:0002D4 | by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md | Completion:89 | Confidence:91
bool FittingRoomScrollPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kFittingRoomScrollPartNone) {
        ProcessActivePart();
        m_repeatTimer.ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}

// UID:0002D6 | by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md | Completion:88 | Confidence:90
void FittingRoomScrollPane::OnDraw()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    if (m_scrollEnabled && m_scrollRange > 0) {
        const bool horizontal = (m_orientation != 0);

        for (int pass = 0; pass < 2; ++pass) {
            const FittingRoomScrollPart part =
                pass == 0 ? kFittingRoomScrollPartPageBeforeThumb
                          : kFittingRoomScrollPartPageAfterThumb;

            GetPartRect(part, &partRect);
            if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                continue;
            }

            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);

            const int fillFrame = horizontal ? 4 : 1;
            const int capFrame = horizontal
                ? (pass == 0 ? 3 : 5)
                : (pass == 0 ? 0 : 2);

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SLIDEBG.EPF",
                fillFrame,
                &tile);

            stripRect = drawRect;
            if (horizontal) {
                stripRect.right = stripRect.left + 1;
                while (stripRect.left < drawRect.right) {
                    RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                    OffsetRect(&stripRect, 1, 0);
                }
            } else {
                stripRect.bottom = stripRect.top + 1;
                while (stripRect.top < drawRect.bottom) {
                    RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                    OffsetRect(&stripRect, 0, 1);
                }
            }

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SLIDEBG.EPF",
                capFrame,
                &tile);
            RenderTileFrame(this, &tile, &drawRect, L"SLIDEBG.PAL");
        }

        GetPartRect(kFittingRoomScrollPartThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SCRBUTT.EPF",
                m_hotPart == kFittingRoomScrollPartThumb ? 1 : 0,
                &tile);
            RenderTileFrame(this, &tile, &drawRect, L"BUTTON.PAL");
        }
        return;
    }

    if (!m_scrollEnabled) {
        SetDrawColor(0);
        FillRect(&clipRect);
        SetDrawColor(128);
    }
}

// UID:0002D8 | by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md | Completion:90 | Confidence:92
FittingRoomScrollPart FittingRoomScrollPane::HitTestPart(int localY,
                                                         int localX)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return kFittingRoomScrollPartNone;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    const bool horizontal = (m_orientation != 0);
    const int fixedExtent = horizontal
        ? (m_bounds.bottom - m_bounds.top)
        : kFittingRoomScrollPartExtentBySkin[m_scrollSkinIndex];

    const int trackStart = horizontal ? m_bounds.left + fixedExtent
                                      : m_bounds.top + fixedExtent;
    const int trackEnd = horizontal ? m_bounds.right - fixedExtent
                                    : m_bounds.bottom - fixedExtent;
    const int trackSize = trackEnd - trackStart;

    int thumbStart = trackStart;
    int thumbEnd = trackEnd;

    if (m_scrollEnabled && m_scrollRange > 0 && trackSize > 0) {
        const int thumbLimit = trackEnd - fixedExtent;
        if (m_thumbDragActive) {
            thumbStart = horizontal
                ? cursor.x - m_thumbDragOffset.x
                : cursor.y - m_thumbDragOffset.y;
            if (thumbStart < trackStart) {
                thumbStart = trackStart;
            }
            if (thumbStart > thumbLimit) {
                thumbStart = thumbLimit;
            }
        } else {
            thumbStart = trackStart + (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        }
        thumbEnd = thumbStart + fixedExtent;
    }

    for (int partIndex = kFittingRoomScrollPartLeading;
         partIndex <= kFittingRoomScrollPartTrailing;
         ++partIndex) {
        RectBounds rect = m_bounds;
        const FittingRoomScrollPart part = static_cast<FittingRoomScrollPart>(partIndex);

        if (horizontal) {
            switch (part) {
            case kFittingRoomScrollPartLeading:
                rect.right = m_bounds.left + fixedExtent;
                break;
            case kFittingRoomScrollPartPageBeforeThumb:
                rect.left = trackStart;
                rect.right = thumbStart;
                break;
            case kFittingRoomScrollPartThumb:
                rect.left = thumbStart;
                rect.right = thumbEnd;
                break;
            case kFittingRoomScrollPartPageAfterThumb:
                rect.left = thumbEnd;
                rect.right = trackEnd;
                break;
            case kFittingRoomScrollPartTrailing:
                rect.left = m_bounds.right - fixedExtent;
                break;
            default:
                break;
            }
        } else {
            switch (part) {
            case kFittingRoomScrollPartLeading:
                rect.bottom = m_bounds.top + fixedExtent;
                break;
            case kFittingRoomScrollPartPageBeforeThumb:
                rect.top = trackStart;
                rect.bottom = thumbStart;
                break;
            case kFittingRoomScrollPartThumb:
                rect.top = thumbStart;
                rect.bottom = thumbEnd;
                break;
            case kFittingRoomScrollPartPageAfterThumb:
                rect.top = thumbEnd;
                rect.bottom = trackEnd;
                break;
            case kFittingRoomScrollPartTrailing:
                rect.top = m_bounds.bottom - fixedExtent;
                break;
            default:
                break;
            }
        }

        if (PointInRect(localY, localX, &rect)) {
            return part;
        }
    }

    return kFittingRoomScrollPartNone;
}

// UID:0002D7 | by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md | Completion:88 | Confidence:90
void FittingRoomScrollPane::GetPartRect(FittingRoomScrollPart part, RectBounds* outRect)
{
    RectBounds bounds = m_bounds;
    *outRect = bounds;

    const bool horizontal = (m_orientation != 0);
    const int fixedExtent = horizontal
        ? bounds.Height()
        : kFittingRoomScrollPartExtentBySkin[m_scrollSkinIndex];

    if (m_scrollRange <= 0 || !m_scrollEnabled) {
        switch (part) {
        case kFittingRoomScrollPartLeading:
            if (horizontal) {
                outRect->right = outRect->left + fixedExtent;
            } else {
                outRect->bottom = outRect->top + fixedExtent;
            }
            return;

        case kFittingRoomScrollPartPageBeforeThumb:
        case kFittingRoomScrollPartPageAfterThumb:
            outRect->left = outRect->right = bounds.left;
            outRect->top = outRect->bottom = bounds.top;
            return;

        case kFittingRoomScrollPartThumb:
            if (horizontal) {
                outRect->left += fixedExtent;
                outRect->right -= fixedExtent;
            } else {
                outRect->top += fixedExtent;
                outRect->bottom -= fixedExtent;
            }
            return;

        case kFittingRoomScrollPartTrailing:
            if (horizontal) {
                outRect->left = outRect->right - fixedExtent;
            } else {
                outRect->top = outRect->bottom - fixedExtent;
            }
            return;

        default:
            return;
        }
    }

    const int trackStart = horizontal ? bounds.left + fixedExtent : bounds.top + fixedExtent;
    const int trackEnd = horizontal ? bounds.right - fixedExtent : bounds.bottom - fixedExtent;
    const int trackLength = trackEnd - trackStart;
    const int thumbExtent = fixedExtent;

    int thumbStart;
    if (m_thumbDragActive) {
        Point cursor;
        Point origin;
        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);
        cursor.x -= origin.x;
        cursor.y -= origin.y;

        const int cursorAxis = horizontal ? cursor.x : cursor.y;
        const int dragAxis = horizontal ? m_thumbDragOffset.x : m_thumbDragOffset.y;
        thumbStart = cursorAxis - dragAxis;
    } else {
        const int movable = trackLength - thumbExtent;
        thumbStart = trackStart;
        if (m_scrollRange > 0 && movable > 0) {
            thumbStart += (movable * m_scrollPosition) / m_scrollRange;
        }
    }

    if (thumbStart < trackStart) {
        thumbStart = trackStart;
    }
    if (thumbStart + thumbExtent > trackEnd) {
        thumbStart = trackEnd - thumbExtent;
    }

    switch (part) {
    case kFittingRoomScrollPartLeading:
        if (horizontal) {
            outRect->right = outRect->left + fixedExtent;
        } else {
            outRect->bottom = outRect->top + fixedExtent;
        }
        break;

    case kFittingRoomScrollPartPageBeforeThumb:
        if (horizontal) {
            outRect->left = trackStart;
            outRect->right = thumbStart;
        } else {
            outRect->top = trackStart;
            outRect->bottom = thumbStart;
        }
        break;

    case kFittingRoomScrollPartThumb:
        if (horizontal) {
            outRect->left = thumbStart;
            outRect->right = thumbStart + thumbExtent;
        } else {
            outRect->top = thumbStart;
            outRect->bottom = thumbStart + thumbExtent;
        }
        break;

    case kFittingRoomScrollPartPageAfterThumb:
        if (horizontal) {
            outRect->left = thumbStart + thumbExtent;
            outRect->right = trackEnd;
        } else {
            outRect->top = thumbStart + thumbExtent;
            outRect->bottom = trackEnd;
        }
        break;

    case kFittingRoomScrollPartTrailing:
        if (horizontal) {
            outRect->left = outRect->right - fixedExtent;
        } else {
            outRect->top = outRect->bottom - fixedExtent;
        }
        break;

    default:
        break;
    }
}

// UID:0002DC | by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md | Completion:88 | Confidence:91
FittingRoomListPane::FittingRoomListPane(const RectBounds* bounds)
    : ControlPane(8, bounds)
{
    m_scrollPosition = 0;
    m_enabledItemCount = 0;
    m_displayMode = FittingRoomListDisplayMode_Grid;
    m_listState0 = 0;
    m_listState1 = 0;
    m_listState2 = 0;
    m_selectedItemIndex = kInvalidFittingRoomSlot;
    m_pendingSlotTimer = 0;
    m_stateFlags = 0;

    m_scrollPane = new FittingRoomScrollPane(FittingRoomScrollOrientation_Vertical);
    m_scrollPane->SetVisibleFlag();
}

// UID:0002DE | by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md | Completion:86 | Confidence:90
void FittingRoomListPane::OnResize(const RectBounds* bounds)
{
    RectBounds clientBounds;
    SetRectLTRB(&clientBounds,
                0,
                0,
                bounds->right - bounds->left,
                bounds->bottom - bounds->top);

    RectBounds scrollBounds;
    SetRectLTRB(&scrollBounds,
                bounds->right - 16,
                bounds->top + 21,
                bounds->right - 3,
                bounds->bottom - 21);

    m_scrollPane->SetBounds(&scrollBounds, 0);
    UpdateRenderRegion(bounds);
    UpdateScrollBar();
}

// UID:0002DG | by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md | Completion:87 | Confidence:90
void FittingRoomListPane::SetBounds(
    const RectBounds *bounds,
    const RectBounds *)
{
    Point origin;
    InitPointPair(&origin, bounds->top, bounds->left);
    InitPointPair(&m_origin, origin.y, origin.x);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -origin.x, -origin.y);
    UpdateRenderRegion(&localBounds);
}

// UID:0002DF | by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md | Completion:87 | Confidence:90
void FittingRoomListPane::UpdateScrollBar()
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    const short totalItems = itemState->GetItemCount(category);
    short enabledItems = 0;

    for (short index = 0; index < totalItems; ++index) {
        FittingRoomCatalogEntry* entry = itemState->GetItemByIndex(category, index);
        if (entry != 0 && entry->enabled != 0) {
            ++enabledItems;
        }
    }

    m_enabledItemCount = enabledItems;

    const bool rowMode = (m_displayMode == FittingRoomListDisplayMode_Rows);
    const int pageSize = rowMode ? kFittingRoomRowPageSize : kFittingRoomGridPageRows;
    const int contentRows = rowMode ? totalItems : ((totalItems + 5) / kFittingRoomGridColumns);

    short maxScroll = 0;
    if (contentRows > pageSize) {
        maxScroll = static_cast<short>(contentRows - pageSize);
        if (maxScroll > kFittingRoomMaxScroll) {
            maxScroll = kFittingRoomMaxScroll;
        }
    }

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_scrollRange != maxScroll) {
        if (maxScroll < scrollPane->m_scrollPosition) {
            scrollPane->m_scrollPosition = maxScroll;
            scrollPane->Invalidate();
        }

        scrollPane->m_scrollRange = maxScroll;
        scrollPane->Invalidate();

        const bool shouldShowScroll = (maxScroll > 0);
        if (scrollPane->m_visible != shouldShowScroll) {
            scrollPane->m_visible = shouldShowScroll;
            scrollPane->Invalidate();
        }
    }

    short clampedScroll = m_scrollPosition;
    if (clampedScroll < 0) {
        clampedScroll = 0;
    }

    const int maxCurrent = rowMode
        ? (totalItems - pageSize)
        : (((totalItems + 5) / kFittingRoomGridColumns) - pageSize);

    if (clampedScroll > maxCurrent) {
        clampedScroll = static_cast<short>(maxCurrent);
    }
    if (clampedScroll < 0) {
        clampedScroll = 0;
    }
    if (clampedScroll > kFittingRoomMaxScroll) {
        clampedScroll = kFittingRoomMaxScroll;
    }

    if (scrollPane->m_scrollPosition != clampedScroll) {
        scrollPane->m_scrollPosition = clampedScroll;
        scrollPane->Invalidate();
    }

    m_scrollPosition = clampedScroll;
}

// UID:0002DH | by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md | Completion:90 | Confidence:92
void FittingRoomListPane::OnScrollPositionChanged(
    unsigned char orientation,
    short oldPosition,
    short newPosition)
{
    (void)orientation;

    if (oldPosition == newPosition) {
        return;
    }

    m_scrollPosition = newPosition;

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_scrollPosition != newPosition) {
        scrollPane->m_scrollPosition = newPosition;
        scrollPane->Invalidate();
    }

    UpdateScrollBar();
    Invalidate();
}

// UID:0002DI | by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md | Completion:90 | Confidence:92
void FittingRoomListPane::ResetScrollPosition()
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;

    if (dialog->m_activeCategory == 3) {
        for (std::vector<FittingRoomSelectionEntry>::iterator it =
                 itemState->m_selectedFittingItems.begin();
             it != itemState->m_selectedFittingItems.end();
             ++it) {
            if (it->category == 3) {
                dialog->m_baseAppearance.m_compositionMode = 3;
            }
        }
    } else {
        dialog->m_baseAppearance.m_compositionMode = 0;
    }

    m_scrollPosition = 0;

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_scrollPosition != 0) {
        scrollPane->m_scrollPosition = 0;
        scrollPane->Invalidate();
    }

    UpdateScrollBar();
    Invalidate();
    Invalidate();
}

// UID:0002DJ | by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md | Completion:88 | Confidence:91
void FittingRoomListPane::OnInsertPane(const RectBounds* bounds,
                                       int order,
                                       Pane* previousPane,
                                       Layer* layerOrContext)
{
    Pane::AddToLayer(bounds, order, previousPane, layerOrContext);

    RectBounds childBounds;
    m_scrollPane->GetScreenBounds(&childBounds);
    m_scrollPane->AddToLayer(&childBounds, 0, this, layerOrContext);

    UpdateScrollBar();
}

// UID:0002DK | by-memory/0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane.md | Completion:88 | Confidence:91
void FittingRoomListPane::OnDetachPane()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:0002DL | by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md | Completion:90 | Confidence:92
void FittingRoomListPane::OnPaint()
{
    EPFTileContext boardFrame;
    Region savedClip;


    if (g_pEPFLib->LookupLayoutEntry(L"WBOARDBK.EPF", 0, &boardFrame) != 0) {
        RectBounds visible = m_visibleBounds;
        m_drawMode = 1;

        GetClipRegion(&savedClip);
        SetClipRect(&visible);

        const int tileWidth = boardFrame.bounds.right - boardFrame.bounds.left;
        const int tileHeight = boardFrame.bounds.bottom - boardFrame.bounds.top;
        if (tileWidth > 0 && tileHeight > 0) {
            for (int y = visible.top; y < visible.bottom; y += tileHeight) {
                for (int x = visible.left; x < visible.right; x += tileWidth) {
                    RectBounds destination;
                    InitRectBounds(&destination,
                                   x,
                                   y,
                                   x + tileWidth,
                                   y + tileHeight);
                    RenderTileFrame(&boardFrame,
                                    &boardFrame.bounds,
                                    &destination,
                                    m_drawMode,
                                    L"WBOARDBK.PAL",
                                    0);
                }
            }
        }

        SetClipRegion(&savedClip);
    }

    FittingRoomDialog *dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState *itemState = &dialog->m_itemState;
    const int activeCategory = dialog->m_activeCategory;
    const unsigned char catalogCategory = static_cast<unsigned char>(activeCategory);

    EPFTileContext itemScratch;
    EPFTileContext glyphScratch;

    UpdateScrollBar();

    const short totalItems = itemState->GetItemCount(catalogCategory);

    short enabledBeforeVisibleStart = 0;
    for (short scanIndex = 1; scanIndex <= totalItems; ++scanIndex) {
        FittingRoomCatalogEntry *scanEntry =
            itemState->GetItemByIndex(catalogCategory, scanIndex);
        if (scanEntry != 0 && scanEntry->enabled != 0) {
            ++enabledBeforeVisibleStart;
            if (m_scrollPosition * kFittingRoomGridColumns < enabledBeforeVisibleStart) {
                break;
            }
        }
    }

    Point cell;
    InitPointPair(&cell, 31, 17);
    m_drawMode = 1;

    unsigned char cellIndex = 0;
    short drawnCells = 0;
    short catalogIndex = static_cast<short>(m_scrollPosition * kFittingRoomGridColumns);
    if (m_enabledItemCount == 0 ||
        m_scrollPosition + kFittingRoomGridVisibleCells > totalItems) {
        catalogIndex = 0;
    }

    while (catalogIndex < totalItems && drawnCells < kFittingRoomGridVisibleCells) {
        FittingRoomCatalogEntry *entry =
            itemState->GetItemByIndex(catalogCategory, catalogIndex);

        if (entry != 0) {
            for (std::vector<FittingRoomSelectionEntry>::iterator selected =
                     itemState->m_selectedFittingItems.begin();
                 selected != itemState->m_selectedFittingItems.end();
                 ++selected) {
                if (selected->category == activeCategory &&
                    selected->catalogIndex == catalogIndex) {
                    RectBounds highlight;
                    InitRectBounds(&highlight,
                                   cell.x,
                                   cell.y,
                                   cell.x + 50,
                                   cell.y + 50);
                    SetDrawColor(0x8a);
                    g_pfnFillRect(this, &highlight);
                    break;
                }
            }

            if (entry->enabled != 0) {
                RectBounds &glyphBounds = glyphScratch.bounds;
                GetItemGlyphBounds(entry->tile, &glyphBounds);

                RectBounds iconRect;
                const int glyphWidth = glyphBounds.right - glyphBounds.left;
                const int glyphHeight = glyphBounds.bottom - glyphBounds.top;
                if (glyphWidth <= 50 && glyphHeight <= 50) {
                    InitRectBounds(&iconRect,
                                   cell.x,
                                   cell.y,
                                   cell.x + 50,
                                   cell.y + 50);
                    g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                        this, &iconRect, entry->tile, entry->color, 0, 0.0f);
                } else {
                    const int centeredLeft = cell.x + ((50 - glyphWidth) / 2);
                    const int centeredTop = cell.y + ((50 - glyphHeight) / 2);
                    InitRectBounds(&iconRect,
                                   centeredLeft,
                                   centeredTop,
                                   centeredLeft + glyphWidth,
                                   centeredTop + glyphHeight);
                    g_pItemObjImageLib->DrawItemImageUnscaled(
                        this, &iconRect, entry->tile, entry->color);
                }

                SetTextColor(0x8f);

                wchar_t formattedName[128];
                swprintf_s(formattedName, _countof(formattedName), L"%s", entry->name);

                SimpleUString itemName;
                itemName.Assign(formattedName, wcslen(formattedName));

                wchar_t line[32];
                memset(line, 0, sizeof(line));

                wchar_t *nextToken = 0;
                wchar_t *token = wcstok(itemName.MutableData(), L" ", &nextToken);
                int lineLength = 0;
                int textY = cell.y + 0x42;
                const int textX = cell.x - 6;

                while (token != 0) {
                    if (lineLength > 0) {
                        const int tokenLength = static_cast<int>(wcslen(token));
                        if (lineLength + tokenLength >= 14) {
                            const short width = GetTextWidth(line, lineLength);
                            MoveTo(textX - width / 2 + 31, textY);
                            DrawWideText(line, lineLength);
                            textY += 16;
                            line[0] = 0;
                            lineLength = 0;
                        }
                    }

                    if (lineLength != 0) {
                        swprintf_s(line, _countof(line), L"%s %s", line, token);
                    } else {
                        swprintf_s(line, _countof(line), L"%s", token);
                    }

                    lineLength = static_cast<int>(wcslen(line));
                    token = wcstok(0, L" ", &nextToken);
                }

                if (lineLength > 0) {
                    const short width = GetTextWidth(line, lineLength);
                    MoveTo(textX - width / 2 + 31, textY);
                    DrawWideText(line, lineLength);
                }
            }

            ++drawnCells;
            cellIndex = static_cast<unsigned char>((cellIndex + 1) % kFittingRoomGridColumns);
            cell.x = cellIndex * 0x60 + 0x11;
            if (cellIndex == 0) {
                cell.y += 0x70;
            }
        }

        ++catalogIndex;
    }

    SetDrawColor(0x8f);
    m_drawMode = 2;
}

// UID:0002DM | by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md | Completion:90 | Confidence:91
bool FittingRoomListPane::OnKeyScroll(PaneKeyEvent *event)
{
    if (event->eventKind != kPaneKeyDown) {
        return false;
    }

    const unsigned char key =
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);
    if (event->keyState != 0) {
        return false;
    }

    const bool rowMode = (m_displayMode == FittingRoomListDisplayMode_Rows);
    const short pageSize = static_cast<short>(
        rowMode ? kFittingRoomRowPageSize : kFittingRoomGridPageRows);

    if (key == kPaneKeyPageUp) {
        short nextPosition = static_cast<short>(m_scrollPosition - pageSize);
        if (nextPosition < 0) {
            nextPosition = 0;
        }

        m_scrollPosition = nextPosition;
        UpdateScrollBar();
        Invalidate();
        return true;
    }

    if (key == kPaneKeyPageDown) {
        FittingRoomDialog *dialog = g_pFittingRoomDialog;
        FittingRoomDialogItemState *itemState = &dialog->m_itemState;
        const unsigned char category =
            static_cast<unsigned char>(dialog->m_activeCategory);
        const short totalItems = itemState->GetItemCount(category);

        short nextPosition = static_cast<short>(m_scrollPosition + pageSize);
        const int maxPosition = rowMode
            ? (totalItems - pageSize)
            : (((totalItems + (kFittingRoomGridColumns - 1)) /
                    kFittingRoomGridColumns) - pageSize);

        if (nextPosition > maxPosition) {
            nextPosition = static_cast<short>(maxPosition);
        }
        if (nextPosition < 0) {
            nextPosition = 0;
        }

        m_scrollPosition = nextPosition;
        UpdateScrollBar();
        Invalidate();
        return true;
    }

    return false;
}

// UID:0002DN | by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md | Completion:90 | Confidence:91
bool FittingRoomListPane::OnInputEvent(Event* event)
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    if (event->m_type == kEventLeftButtonUp) {
        FittingRoomSlotIndex slot =
            HitTestSlot(event->m_payload.m_pointer.m_x,
                        event->m_payload.m_pointer.m_y);
        if (static_cast<unsigned short>(slot) <= 0x1a) {
            FittingRoomSlotIndex candidate;
            if (m_displayMode == FittingRoomListDisplayMode_Rows) {
                candidate = static_cast<FittingRoomSlotIndex>(m_scrollPosition + slot);
            } else {
                candidate = static_cast<FittingRoomSlotIndex>(
                    m_scrollPosition * kFittingRoomGridColumns + slot);
            }

            candidate = ValidateFittingSelectionIndex(candidate);
            if (candidate != kInvalidFittingRoomSlot &&
                !g_pUserPane->m_nameVisible) {
                FittingRoomCatalogEntry* catalogEntry =
                    itemState->GetItemByIndex(category, candidate);
                bool removing = false;

                FittingRoomSelectionEntry newEntry;
                newEntry.category =
                    static_cast<FittingRoomCatalogCategory>(category);
                newEntry.catalogIndex = candidate;

                for (int partIndex = 0;
                     partIndex < catalogEntry->GetPartCount();
                     ++partIndex) {
                    const FittingRoomCatalogPartRecord* part =
                        catalogEntry->GetPart(
                            static_cast<signed char>(partIndex));
                    if (part != 0 && part->part != -1) {
                        newEntry.partTypes.push_back(
                            static_cast<int>(part->part));
                    }
                }

                for (std::vector<FittingRoomSelectionEntry>::iterator it =
                         itemState->m_selectedFittingItems.begin();
                     it != itemState->m_selectedFittingItems.end();
                     ++it) {
                    if (it->category == newEntry.category &&
                        it->catalogIndex == newEntry.catalogIndex) {
                        itemState->m_selectedFittingItems.erase(it);
                        removing = true;
                        break;
                    }
                }

                if (!removing && !newEntry.partTypes.empty()) {
                    wcscpy_s(newEntry.name, 0x50, catalogEntry->name);

                    std::vector<FittingRoomSelectionEntry>::iterator existing =
                        itemState->m_selectedFittingItems.begin();
                    while (existing != itemState->m_selectedFittingItems.end()) {
                        bool overlaps = false;
                        for (std::vector<int>::const_iterator oldPart =
                                 existing->partTypes.begin();
                             oldPart != existing->partTypes.end() && !overlaps;
                             ++oldPart) {
                            for (std::vector<int>::const_iterator newPart =
                                     newEntry.partTypes.begin();
                                 newPart != newEntry.partTypes.end();
                                 ++newPart) {
                                if (*oldPart == *newPart) {
                                    overlaps = true;
                                    break;
                                }
                            }
                        }

                        if (overlaps) {
                            existing =
                                itemState->m_selectedFittingItems.erase(existing);
                        } else {
                            ++existing;
                        }
                    }

                    itemState->m_selectedFittingItems.push_back(newEntry);
                }

                dialog->m_baseAppearance.m_compositionMode = 0;

                for (int partIndex = 0;
                     partIndex < catalogEntry->GetPartCount();
                     ++partIndex) {
                    const FittingRoomCatalogPartRecord* part =
                        catalogEntry->GetPart(static_cast<signed char>(partIndex));
                    if (part == 0 || part->tile == 0xffff) {
                        continue;
                    }

                    ObjectStatusBlob& appearance = dialog->m_baseAppearance;
                    const ObjectStatusBlob& original =
                        dialog->m_previewAppearance;

                    switch (part->part) {
                    case 1:
                        appearance.m_weaponId =
                            removing ? original.m_weaponId : part->tile;
                        appearance.m_weaponColor =
                            removing ? original.m_weaponColor : part->color;
                        break;
                    case 2:
                        appearance.m_bodyId =
                            removing ? original.m_bodyId : part->tile;
                        appearance.m_bodyColor =
                            removing ? original.m_bodyColor : part->color;
                        break;
                    case 3:
                        appearance.m_shieldOrArrowId =
                            removing ? original.m_shieldOrArrowId : part->tile;
                        appearance.m_shieldOrArrowColor =
                            removing ? original.m_shieldOrArrowColor : part->color;
                        break;
                    case 4:
                        appearance.m_helmetId = static_cast<unsigned char>(
                            removing ? original.m_helmetId : part->tile);
                        appearance.m_helmetColor =
                            removing ? original.m_helmetColor : part->color;
                        appearance.m_headgearMode = 1;
                        break;
                    case 6:
                        appearance.m_neckId =
                            removing ? original.m_neckId : part->tile;
                        appearance.m_neckColor =
                            removing ? original.m_neckColor : part->color;
                        break;
                    case 13:
                        appearance.m_shoesId =
                            removing ? original.m_shoesId : part->tile;
                        appearance.m_shoesColor =
                            removing ? original.m_shoesColor : part->color;
                        break;
                    case 14:
                        appearance.m_mantleId =
                            removing ? original.m_mantleId : part->tile;
                        appearance.m_mantleColor =
                            removing ? original.m_mantleColor : part->color;
                        break;
                    case 16:
                        if (removing) {
                            appearance.m_coatId = original.m_coatId;
                            appearance.m_bodyId = original.m_bodyId;
                            appearance.m_bodyColor = original.m_bodyColor;
                            appearance.m_shoesId = original.m_shoesId;
                        } else {
                            appearance.m_coatId =
                                part->tile > 9999
                                    ? static_cast<unsigned short>(
                                          part->tile % 10000)
                                    : 0xffff;
                            appearance.m_bodyId =
                                part->tile <= 9999 ? part->tile : 0xffff;
                            appearance.m_bodyColor = part->color;

                            if (appearance.m_coatId != 0xffff &&
                                appearance.m_shoesId == 0xffff) {
                                appearance.m_shoesId =
                                    part->gender != 0 ? 1 : 0;
                            } else if (appearance.m_coatId == 0xffff &&
                                       appearance.m_bodyId != 0 &&
                                       appearance.m_bodyId != 1 &&
                                       appearance.m_bodyId != 0x39 &&
                                       appearance.m_bodyId != 0x3a &&
                                       appearance.m_bodyId != 0xa0 &&
                                       appearance.m_bodyId != 0xa1) {
                                appearance.m_shoesId = 0xffff;
                            }
                        }
                        break;
                    case 22:
                        appearance.m_faceDecorationId =
                            removing ? original.m_faceDecorationId : part->tile;
                        appearance.m_faceDecorationColor =
                            removing
                                ? original.m_faceDecorationColor
                                : part->color;
                        break;
                    case 23:
                        appearance.m_hairDecorationId =
                            removing ? original.m_hairDecorationId : part->tile;
                        appearance.m_hairDecorationColor =
                            removing
                                ? original.m_hairDecorationColor
                                : part->color;
                        if (!removing && part->tile >= 10000) {
                            appearance.m_helmetId = 0xff;
                            if (part->tile > 19999) {
                                appearance.m_hairColor = part->color;
                                appearance.m_hairId =
                                    static_cast<unsigned char>(
                                        part->tile % 20000);
                            } else {
                                appearance.m_hairId =
                                    static_cast<unsigned char>(
                                        part->tile % 10000);
                            }
                            appearance.m_hairDecorationId = 0xffff;
                        }
                        break;
                    case 24:
                        appearance.m_secondFaceDecorationId =
                            removing
                                ? original.m_secondFaceDecorationId
                                : part->tile;
                        appearance.m_secondFaceDecorationColor =
                            removing
                                ? original.m_secondFaceDecorationColor
                                : part->color;
                        break;
                    case 30:
                        appearance.m_appearanceId =
                            removing ? original.m_appearanceId : part->tile;
                        appearance.m_faceColor =
                            removing ? original.m_faceColor : part->color;
                        break;
                    case 31:
                        appearance.m_hairId = static_cast<unsigned char>(
                            removing ? original.m_hairId : part->tile);
                        break;
                    case 32:
                        appearance.m_hairColor =
                            removing ? original.m_hairColor : part->color;
                        break;
                    case 33:
                        if (removing) {
                            appearance.m_compositionMode = 0;
                            appearance.m_ridingDefinitionIndex =
                                original.m_ridingDefinitionIndex;
                            appearance.m_ridingPaletteFlags =
                                original.m_ridingPaletteFlags;
                            appearance.m_ridingYOffset =
                                original.m_ridingYOffset;
                        } else {
                            appearance.m_compositionMode = 3;
                            appearance.m_ridingDefinitionIndex = part->tile;
                            appearance.m_ridingPaletteFlags = part->color;
                            appearance.m_ridingYOffset = 0;
                        }
                        break;
                    }
                }
            }
        }
    } else if (event->m_type == kEventMouseWheel) {
        if (PointInRect(event->m_payload.m_pointer.m_y,
                        event->m_payload.m_pointer.m_x,
                        &m_visibleBounds)) {
            const short oldPosition = m_scrollPane->m_scrollPosition;
            short newPosition = static_cast<short>(
                oldPosition - event->m_payload.m_pointer.m_detail);
            if (newPosition < 0) {
                newPosition = 0;
            }
            if (newPosition > m_scrollPane->m_scrollRange) {
                newPosition = m_scrollPane->m_scrollRange;
            }
            OnScrollPositionChanged(0, oldPosition, newPosition);
        }
    }

    Point childOrigin;
    m_scrollPane->GetOrigin(&childOrigin);
    event->m_payload.m_pointer.m_x -= childOrigin.x;
    event->m_payload.m_pointer.m_y -= childOrigin.y;
    const bool handled = m_scrollPane->OnInputEvent(event);
    event->m_payload.m_pointer.m_x += childOrigin.x;
    event->m_payload.m_pointer.m_y += childOrigin.y;
    return handled;
}

// UID:0002DS | by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md | Completion:88 | Confidence:91
static const int kFittingRoomScrollStepUp = 1;
static const int kFittingRoomScrollStepDown = 2;
static const int kFittingRoomScrollStepRepeatInterval = 50;

bool FittingRoomListPane::OnScrollStep(int direction, int, int)
{
    FittingRoomScrollPane *scrollPane = m_scrollPane;
    short nextPosition = scrollPane->m_scrollPosition;

    if (direction == kFittingRoomScrollStepUp) {
        --nextPosition;
        if (nextPosition < 0) {
            nextPosition = 0;
        }
    } else if (direction == kFittingRoomScrollStepDown) {
        ++nextPosition;
        if (nextPosition > scrollPane->m_scrollRange) {
            nextPosition = scrollPane->m_scrollRange;
        }
    } else {
        return false;
    }

    if (scrollPane->m_scrollPosition != nextPosition) {
        m_scrollPosition = nextPosition;
        scrollPane->m_scrollPosition = nextPosition;
        scrollPane->Invalidate();

        UpdateScrollBar();
        Invalidate();
    }

    m_timerHandler.ScheduleTimer(direction, kFittingRoomScrollStepRepeatInterval, 0, 0);
    return true;
}

// UID:0002DT | by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md | Completion:86 | Confidence:89
static void GetFittingRoomEquipmentSlotRect(FittingRoomSlotIndex slotId, RectBounds* rect)
{
    switch (slotId) {
    case 2:
        SetRectLTRB(rect, 168, 37, 185, 54);
        break;
    case 3:
        SetRectLTRB(rect, 168, 55, 185, 72);
        break;
    case 4:
        SetRectLTRB(rect, 168, 99, 185, 116);
        break;
    default:
        SetRectLTRB(rect, -1, -1, -1, -1);
        break;
    }
}

void FittingRoomListPane::GetItemSlotRect(FittingRoomSlotIndex slotIndex, RectBounds* rect)
{
    if (m_displayMode == FittingRoomListDisplayMode_Rows) {
        if (static_cast<unsigned short>(slotIndex) <= 0x1a) {
            const int top = slotIndex * 20 + 16;
            SetRectLTRB(rect, 2, top, 160, top + 20);
            return;
        }
    } else {
        if (static_cast<unsigned short>(slotIndex) <= 0x12) {
            const int row = slotIndex / 6;
            const int column = slotIndex % 6;
            const int left = column * 96 + 16;
            const int top = row * 112 + 31;
            SetRectLTRB(rect, left, top, left + 54, top + 54);
            return;
        }
    }

    SetRectLTRB(rect, -1, -1, -1, -1);
}

static FittingRoomSlotIndex HitTestFittingRoomEquipmentSlot(int x, int y)
{
    RectBounds rect;

    for (FittingRoomSlotIndex slotId = 0; slotId < 5; ++slotId) {
        GetFittingRoomEquipmentSlotRect(slotId, &rect);
        if (PointInRect(&rect, x, y)) {
            return slotId;
        }
    }

    return kInvalidFittingRoomSlot;
}

// UID:0002DP | by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md | Completion:87 | Confidence:90
FittingRoomSlotIndex FittingRoomListPane::HitTestSlot(int x, int y)
{
    RectBounds rect;

    if (m_displayMode == FittingRoomListDisplayMode_Rows) {
        for (FittingRoomSlotIndex slotIndex = 0; slotIndex <= 0x1a; ++slotIndex) {
            GetItemSlotRect(slotIndex, &rect);
            if (PointInRect(&rect, x, y)) {
                return slotIndex;
            }
        }
    } else {
        for (FittingRoomSlotIndex slotIndex = 0; slotIndex <= 0x12; ++slotIndex) {
            GetItemSlotRect(slotIndex, &rect);
            if (PointInRect(&rect, x, y)) {
                return slotIndex;
            }
        }
    }

    return kInvalidFittingRoomSlot;
}

// UID:0002DQ | by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md | Completion:87 | Confidence:90
FittingRoomSlotIndex FittingRoomListPane::ValidateFittingSelectionIndex(FittingRoomSlotIndex candidate) const
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    if (candidate > itemState->GetItemCount(category)) {
        return kInvalidFittingRoomSlot;
    }

    FittingRoomCatalogEntry* entry = itemState->GetItemByIndex(category, candidate);
    if (entry != 0 && entry->enabled != 0) {
        return candidate;
    }

    return kInvalidFittingRoomSlot;
}

// UID:0002DU | by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md | Completion:88 | Confidence:90
void FittingRoomListPane::GetItemSlotOrigin(Point* point, FittingRoomSlotIndex slotIndex)
{
    if (m_displayMode == FittingRoomListDisplayMode_Rows) {
        SetPoint(point, 30, 20);
        point->y += slotIndex * 20;
    } else {
        const int row = slotIndex / 6;
        const int column = slotIndex % 6;

        SetPoint(point, 21, 17);
        point->x += column * 96;
        point->y += row * 112;
    }
}

void FittingRoomListPane::CancelPendingSlotTimer()
{
    if (m_pendingSlotTimer != 0) {
        m_timerHandler.CancelTimer(m_pendingSlotTimer);
        m_pendingSlotTimer = 0;
    }
}



// UID:0002DX | by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md | Completion:88 | Confidence:91
FittingRoomListPane::~FittingRoomListPane()
{
    delete m_scrollPane;
}


// UID:0000WP | by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md | Completion:88 | Confidence:90
FittingRoomDownloadControlPane::FittingRoomDownloadControlPane(const RectBounds *bounds)
    : ControlPane(8, bounds),
      m_progressPercent(0)
{
}


// UID:000055 | by-class/FittingRoomTextButtonControlPane.md | Completion:88 | Confidence:90
// FittingRoomTextButtonControlPane emits exact child bodies through this source route.
// Current source-ready children: [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md), [UID:0004GG][0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint](by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md), and [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md).
// UID:0004GE | by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md | Completion:90 | Confidence:92
FittingRoomTextButtonControlPane::FittingRoomTextButtonControlPane(const wchar_t *label, const RectBounds *bounds)
    : TextButtonControlPane(label, bounds),
      m_selected(false)
{
}

// UID:0004GG | by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md | Completion:88 | Confidence:91
void FittingRoomTextButtonControlPane::OnPaint()
{
    const unsigned int kNormalTopLeftColor = 208;
    const unsigned int kNormalBottomRightColor = 216;
    const unsigned int kPressedTopLeftColor = 216;
    const unsigned int kPressedBottomRightColor = 208;
    const unsigned int kButtonFillColor = 212;
    const unsigned int kEnabledTextColor = 128;
    const unsigned int kDisabledTextColor = 134;
    const unsigned char kPressedVisualState = 11;
    const int kLabelHalfHeight = 6;

    const bool pushed = (m_visualState == kPressedVisualState || m_selected);

    unsigned int topLeftColor = kNormalTopLeftColor;
    unsigned int bottomRightColor = kNormalBottomRightColor;
    if (pushed) {
        topLeftColor = kPressedTopLeftColor;
        bottomRightColor = kPressedBottomRightColor;
    }

    const unsigned int textColor = m_controlVisible ? kEnabledTextColor : kDisabledTextColor;

    RectBounds frame = m_bounds;

    SetDrawColor(kButtonFillColor);
    FillRect(&frame);

    MoveTo(frame.left, frame.bottom - 1);
    SetDrawColor(topLeftColor);
    LineTo(frame.left, frame.top);
    LineTo(frame.right - 1, frame.top);
    SetDrawColor(bottomRightColor);
    LineTo(frame.right - 1, frame.bottom - 1);
    LineTo(frame.left, frame.bottom - 1);

    InsetRect(&frame, 1, 1);

    MoveTo(frame.left, frame.bottom - 1);
    SetDrawColor(topLeftColor);
    LineTo(frame.left, frame.top);
    LineTo(frame.right - 1, frame.top);
    SetDrawColor(bottomRightColor);
    LineTo(frame.right - 1, frame.bottom - 1);
    LineTo(frame.left, frame.bottom - 1);

    RectBounds textRect = m_bounds;
    const int textCenterY = (textRect.top + textRect.bottom) / 2;
    textRect.top = textCenterY - kLabelHalfHeight;
    textRect.bottom = textCenterY + kLabelHalfHeight;

    if (pushed) {
        OffsetRect(&textRect, 1, 1);
    }

    SetTextColor(textColor);
    m_textDrawMode = 1;
    m_textAlign = 1;

    DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), &textRect);
}

// UID:0004GH | by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md | Completion:90 | Confidence:92
void FittingRoomTextButtonControlPane::SetSelected(bool selected)
{
    m_selected = selected;
}



// UID:0004GB | by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md | Completion:88 | Confidence:91
unsigned char FittingRoomDownloadProgressState::GetPercent() const
{
    if (m_total == 0) {
        return 0;
    }

    return static_cast<unsigned char>((m_current * 100) / m_total);
}


// UID:0002CW | by-memory/0x0041d150-0x0041d284.FittingRoomControlBounds.md | Completion:88 | Confidence:93
void GetFittingRoomControlBounds(int controlId, RectBounds *bounds)
{
    switch (controlId) {
    case 0:
        InitRectBoundsFromSize(bounds, 379, 468, 63, 24);
        return;
    case 1:
        InitRectBoundsFromSize(bounds, 18, 50, 192, 192);
        return;
    case 2:
        InitRectBoundsFromSize(bounds, 218, 92, 586, 362);
        return;
    case 3:
        InitRectBoundsFromSize(bounds, 18, 248, 63, 24);
        return;
    case 4:
        InitRectBoundsFromSize(bounds, 149, 250, 63, 24);
        return;
    case 5:
        InitRectBoundsFromSize(bounds, 18, 276, 92, 30);
        return;
    case 6:
        InitRectBoundsFromSize(bounds, 120, 276, 92, 30);
        return;
    default:
        if (controlId >= 7 && controlId <= 16) {
            const int index = controlId - 7;
            InitRectBoundsFromSize(bounds,
                                   280 + 90 * (index % 5),
                                   50 + 26 * (index / 5),
                                   86,
                                   22);
        } else {
            InitRectBounds(bounds, -1, -1, -1, -1);
        }
        return;
    }
}

// UID:0002CY | by-memory/0x0041d340-0x0041d3b0.CompareEquipmentNames.md | Completion:88 | Confidence:91
static bool CompareEquipmentNames(const char *leftBytes,
                                  unsigned int leftLength,
                                  const char *rightBytes,
                                  unsigned int rightLength)
{
    if (leftLength != rightLength) {
        return false;
    }

    while (leftLength >= 4) {
        if (*reinterpret_cast<const unsigned int *>(leftBytes) !=
            *reinterpret_cast<const unsigned int *>(rightBytes)) {
            return false;
        }

        leftBytes += 4;
        rightBytes += 4;
        leftLength -= 4;
    }

    while (leftLength != 0) {
        if (*leftBytes != *rightBytes) {
            return false;
        }

        ++leftBytes;
        ++rightBytes;
        --leftLength;
    }

    return true;
}





// UID:00028I | by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md | Completion:89 | Confidence:91
FittingRoomDialog *g_pFittingRoomDialog;

// UID:00004Z | by-class\FittingEquipmentState.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0004WJ | by-memory\0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0004WL | by-memory\0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0002EA | by-memory\0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0002U6 | by-memory\0x00423210-0x004233ea.FittingRoomEntryPartVectorGrowInsert.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0001UH | by-type\by-struct\FittingEquipmentStateLayout.md | Completion:91 | Confidence:92 | Empty Emitter Marker

// UID:00030R | by-memory\0x00420ef0-0x00421143.FittingRoomSelectionEntryVectorGrowInsert.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:00030T | by-memory\0x00421150-0x0042122b.FittingRoomSelectionEntryMoveConstructRange.md | Completion:87 | Confidence:89 | Empty Emitter Marker

// UID:000052 | by-class\FittingRoomDownloadControlPane.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0000WQ | by-memory\0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:000056 | by-class\FittingRoomUserImageControlPane.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:000576 | by-memory\0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0000WR | by-memory\0x0041ba40-0x004245f5.FittingRoomUiCore.md | Completion:88 | Confidence:89 | Empty Emitter Marker

// UID:0002DW | by-memory\0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0002E0 | by-memory\0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0003G1 | by-memory\0x0060d94c-0x0060d958.SharedVersionJsonKey.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003AM | by-memory\0x0060d9c0-0x0060e174.FittingRoomReadOnlyData.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0001UI | by-type\by-struct\FittingRoomDownloadProgressState.md | Completion:85 | Confidence:90 | Empty Emitter Marker
