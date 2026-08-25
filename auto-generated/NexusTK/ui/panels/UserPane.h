// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P1
// Source by-file doc: by-file/UserPane.md
// UID:0001TZ | by-type/by-struct/CollectionPlayerDataLayout.md | Completion:93 | Confidence:94
#include "../../util/StringUtil.h"

struct CollectionEntryRecord
{
    SimpleUString shortName;
    SimpleUString entryName;
    SimpleUString description;
    unsigned char collectedFlag;
    unsigned char reserved[3];
};

struct CollectionGroupRecord
{
    unsigned char loadedFlag;
    unsigned char groupType;
    unsigned char totalEntries;
    unsigned char collectedEntries;
    CollectionEntryRecord entries[128];
};

struct CollectionPlayerDataView
{
    CollectionGroupRecord groups[128];
    signed char groupCount;
    unsigned char metadataLoaded;
};

typedef char CollectionEntryRecordSizeMustBe0x4C[
    sizeof(CollectionEntryRecord) == 0x4C ? 1 : -1];
typedef char CollectionGroupRecordSizeMustBe0x2604[
    sizeof(CollectionGroupRecord) == 0x2604 ? 1 : -1];

// UID:0000FQ | by-class/UserPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_PANELS_USERPANE_H
#define NEXUSTK_UI_PANELS_USERPANE_H

#include <stddef.h>

#include "../../map/LivingObjectPane.h"

class Event;
class LineInputPane;
class MapPane;
class NewGroupPane;
class NewSpellInventoryPane;
class ObjectPane;
class SelectObjectWithKeyboardPane;
class SayToUserNameInputPane;
class UserPane;
class WillBeChangedSpellPane;
struct MapPoint;
struct ServerMessageEvent;

extern UserPane *g_pUserPane;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

void ToggleTargetSelectionPane(bool alternateMode);
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer);
void ReverseTargetSelectionDirection();
extern bool g_selectObjectTargetModeActive;
extern bool g_targetObjectTargetModeActive;
extern SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void __stdcall SendDirectionPacket(unsigned char direction);
static void SendOpcode7Command(unsigned char command);
void RefreshGroupMemberMarkers(UserPane *userPane);
void ClearGroupMemberMarkers(UserPane *userPane);

struct GroupMemberRecord
{
    unsigned int memberId;
    wchar_t name[128];
    bool active;
    unsigned short faceId;
    unsigned char hairId;
    unsigned char faceColor;
    unsigned char hairColor;
    unsigned char skinColor;
    unsigned char bodyColor;
    unsigned char helmetId;
    unsigned char helmetColor;
    unsigned short faceDecorationId;
    unsigned char faceDecorationColor;
    unsigned short hairDecorationId;
    unsigned char hairDecorationColor;
    unsigned short secondFaceDecorationId;
    unsigned char secondFaceDecorationColor;
    unsigned int maximumHitPoints;
    unsigned int currentHitPoints;
    unsigned int maximumManaPoints;
    unsigned int currentManaPoints;
};

struct LocalInventorySlotRecord
{
    unsigned char active;
    unsigned char reserved001;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved005;
    wchar_t displayName[80];
    wchar_t itemMetaKey[80];
    wchar_t ownerName[80];
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;
    unsigned char quantityPromptFlag;
    unsigned char reserved1ed[3];
    unsigned int currentDurability;
    unsigned int protectionCount;
    unsigned char targetMode;
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;
    unsigned char reserved001[3];
    int inputKind;
    wchar_t displayName[80];
    wchar_t prompt[80];
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

enum SayInputMode
{
    kSayInputModeDefault = 0,
    kSayInputModeShout = 1,
    kSayInputModeWhisper = 2,
    kSayInputModeGroup = 3,
    kSayInputModeClan = 4,
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    void GetPreviousChatHistoryLine(short *historyCursor,
                                    wchar_t *destination,
                                    size_t destinationCount);
    void GetNextChatHistoryLine(short *historyCursor,
                                wchar_t *destination,
                                size_t destinationCount);
    void SaveChatHistoryLine(const wchar_t *text);
    void GetPreviousRecentRecipientHistory(
        short *historyIndex, wchar_t *recipient, size_t recipientCount);
    void UpdateRecentRecipientList(const wchar_t *recipient);
    void GetPreviousFallbackRecipientHistory(
        short *historyIndex, wchar_t *recipient, size_t recipientCount);
    void OpenInputPaneForCurrentSayMode();
    void OpenDefaultSayInputPane();
    void OpenSayToUserNameInputPane();
    void OpenSayToLastRecipientInputPane();
    void OpenSayToGroupMessageInputPane();
    void OpenSayToClanMessageInputPane();
    void OpenShoutInputPane();

    const wchar_t *GetSpellPromptText(char spellIndex) const
    {
        return m_spellCommandSlots[spellIndex - 1].prompt;
    }

    unsigned char GetHuntersListFlag() const
    {
        return m_huntersListFlag;
    }

    void SetHuntersListFlag(unsigned char flag)
    {
        m_huntersListFlag = flag;
    }

    wchar_t *GetPartySearchSourceText()
    {
        return m_partySearchSourceText;
    }

    const wchar_t *GetPartySearchSourceText() const
    {
        return m_partySearchSourceText;
    }

    void ClearActiveLineInputPane()
    {
        m_activeLineInputPane = NULL;
    }

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void OpenMixItemDialog();
    bool IsInputLocked() const
    {
        return m_inputLocked;
    }
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    void ClearDeferredUserListPacket();
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseGroupListPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(char direction);
    void BuildInventorySlotRangeText(wchar_t *outText) const;
    void BuildSpellSlotRangeText(wchar_t *outText) const;

private:
    friend class MapPane;
    friend class NewGroupPane;
    friend class NewSpellInventoryPane;
    friend class SayToUserNameInputPane;
    friend class WillBeChangedSpellPane;
    friend void RefreshGroupMemberMarkers(UserPane *userPane);
    friend void ClearGroupMemberMarkers(UserPane *userPane);

    bool IsGroupMember(unsigned int memberId) const;
    GroupMemberRecord *FindGroupMemberById(unsigned int memberId);
    void AdvanceMovementSendTick();

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementReplyState()
    {
        m_movementReplyReceived = false;
        m_movementReplyPending = false;
    }

    void SetMovementReplyState()
    {
        m_movementReplyCount = 1;
        m_movementReplyReceived = true;
    }

    bool IsDirectionDelayActive() const
    {
        return m_directionDelayActive;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_directionDelayActive = active;
    }

    bool m_movementTimerHandled;
    unsigned char m_userPaneBaseStateTail[3];
    LineInputPane *m_activeLineInputPane;
    unsigned char m_userPanePreGroupState[4];
    GroupMemberRecord m_groupMembers[50];
    signed char m_groupMemberCount;
    unsigned char m_huntersListFlag;
    wchar_t m_partySearchSourceText[256];
    unsigned char m_preCollectionState[2];
    int m_currentSayMode;
    unsigned char m_preCollectionCommandState[2];
    bool m_collectionPanelSoundEnabled;
    unsigned char m_postCollectionCommandState[9];
    int m_localPlayerHitRadius;
    CollectionPlayerDataView m_collectionData;
    int m_screenX;
    int m_screenY;
    unsigned int m_screenState;
    RectBounds m_screenHitBounds;
    RectBounds m_screenLowerHitBounds;
    MapPane *m_mapPane;
    unsigned char m_playerSettingsState[8];
    LocalInventorySlotRecord m_inventorySlots[52];
    SpellCommandSlotRecord m_spellCommandSlots[52];
    bool m_spellCommandSlotsReady;
    unsigned char m_preViewportState[3];
    int m_viewportColumn;
    int m_viewportRow;
    int m_viewportHalfColumns;
    int m_viewportHalfRows;
    int m_viewportRemainingColumns;
    int m_viewportRemainingRows;
    unsigned char m_movementMode;
    signed char m_movementReplyCount;
    bool m_movementReplyReceived;
    bool m_movementReplyPending;
    bool m_directionDelayActive;
    unsigned char m_preActionTickState[3];
    unsigned int m_lastActionTick;
    unsigned int m_lastMapCommandTick;
    unsigned int m_lastGroundItemCommandTick;
    List *m_chatHistory;
    List *m_outgoingWhisperRecipientHistory;
    List *m_incomingWhisperSenderHistory;
    unsigned char m_whisperHistorySource;
    unsigned char m_preMovementHistory[3];
    LocalMovementHistoryRecord *m_movementHistoryRecords;
    int m_movementHistoryCapacity;
    unsigned char m_movementHistoryWriteIndex;
    bool m_inputLocked;
    unsigned char m_movementReplyTimerFamily;
    bool m_movementHistoryEnabled;
    unsigned char *m_deferredUserListPacket;
    size_t m_deferredUserListPacketSize;
    unsigned int m_userListPacketTick;
    unsigned int m_userListDeferUntilTick;
    bool m_skipNextUserListPacket;
    unsigned char m_preMovementTicks[3];
    unsigned int m_lastMovementSendTick;
    unsigned int m_lastMovementInputTick;
    unsigned char m_actionMode;
    unsigned char m_userPaneTrailingState0;
    bool m_includeAdjacentMovementTargets;
    unsigned char m_userPaneTrailingState2;
    ObjectStatusBlob m_currentAppearance;
};

typedef char GroupMemberRecordSizeMustBe300[
    sizeof(GroupMemberRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

// UID:0004YC | by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md | Completion:92 | Confidence:94
void __stdcall RequestLocalPlayerStatus(unsigned int requestTime);

#endif // NEXUSTK_UI_PANELS_USERPANE_H
