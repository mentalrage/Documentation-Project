*** UID:0000FQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../util/PoolAllocator.h"
#include "../../social/SayInputPanes.h"
#include "../../social/Chatting.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Say-Input Ownership And Recipient-History Synchronization - 2026-08-25

- UserPane owns the current-mode dispatcher [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md), six opener definitions [UID:000579][0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners](by-memory/0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners.md), and three recipient-history definitions [UID:00057A][0x005a4ab0-0x005a4c8b.UserPaneWhisperRecipientHistoryHelpers](by-memory/0x005a4ab0-0x005a4c8b.UserPaneWhisperRecipientHistoryHelpers.md). All ten methods emit as members through `UserPane.cpp`; their declarations and `SayInputMode` enum emit once through this complete H block.
- Formal CPP adds direct `SayInputPanes.h` and `Chatting.h` dependencies after the existing PoolAllocator include and before `[[CHILDREN]]`. The dispatcher reads `g_useEpfAssets` and `g_pChattingHandlePane`; the openers construct the seven SayInputPanes classes. No enum or UserPane helper definition is emitted from SayInputPanes itself.
- Complete-object offsets remain unchanged: `m_currentSayMode` is at `+0x3eb4`; `m_chatHistory` is at `+0x13eb04`; outgoing/recent recipients are at `+0x13eb08`; incoming/fallback senders are at `+0x13eb0c`; and `m_whisperHistorySource` is at `+0x13eb10`. The history helpers use signed-short cursors, bounded wide copies, a ten-entry cap, duplicate removal, and selector values rather than raw offsets.
- Bounded `friend class SayToUserNameInputPane` matches the constructor/event methods' direct reads of both private recipient lists and selector. It adds no object bytes and does not expose the fields publicly. Historical free-function, SayInputPanes-owned, Plan-owned, mixed-range aggregate, raw-offset, and polluted STL-alias routes are superseded.
- The complete inherited layout, every unrelated method/field/friend, `sizeof(UserPane)==0x13eb84`, score `94/95`, position 10, class closure, and `[[CHILDREN]]` remain unchanged.

## UID0003VD OnTimer Source-Quality Integration - 2026-07-30

- [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) is the complete `virtual bool OnTimer(int timerId, int arg0, int arg1)` override reached through UserPane's TimerHandler secondary facet at complete-object offset `+0xa4`. The adjusted machine receiver is normal multiple-inheritance lowering; source uses ordinary UserPane member access.
- Timer ID `20` is class-local `kUserPaneMovementStep`. The override also handles inherited `kLivingTimerForwardStep` / `FWdA`, delegates `kLivingTimerFrameAnimation` / `FAnD`, and delegates every unknown timer to `LivingObjectPane::OnTimer`.
- The complete class declaration now belongs in formal H. Formal CPP is intentionally blank because exact by-memory children own out-of-class definitions through `[[CHILDREN]]`; this avoids a duplicate class declaration in generated `UserPane.cpp` and makes `UserPane.h` the one declaration route.
- The declaration preserves the accepted UID000415 chat-history methods and `m_chatHistory`, all B007/B008 additions, every unrelated field and method, all size guards, and `sizeof(UserPane)==0x13eb84`.

### Size-Neutral Movement And Active-Input Layout

| Complete-object offset | Source declaration | Evidence/disposition |
| --- | --- | --- |
| `+0x1c6` | inherited `signed char m_moveFrame` | remains inherited from LivingObjectPane; IDA may expose the flattened member, but UserPane does not redeclare it |
| `+0x20c` | `bool m_movementTimerHandled` | set by both UID0003VD movement branches; replaces the first byte of the former four-byte opaque state |
| `+0x20d..+0x20f` | `unsigned char m_userPaneBaseStateTail[3]` | preserves the remaining opaque bytes without offset drift |
| `+0x210` | `LineInputPane *m_activeLineInputPane` | sole non-null writer is the typed LineInputPane constructor; eighteen other writes initialize or clear it; no ObjectPane pointer is stored here |
| `+0x214..+0x217` | `unsigned char m_userPanePreGroupState[4]` | preserved tail before `m_groupMembers +0x218` |
| `+0x13eaf0` | `unsigned char m_movementMode` | first byte of the former five-byte movement array; adjacent mode state |
| `+0x13eaf1` | `signed char m_movementReplyCount` | signed continuation countdown used by UID0003VD |
| `+0x13eaf2` | `bool m_movementReplyReceived` | reply-received latch and continuation state |
| `+0x13eaf3` | `bool m_movementReplyPending` | pending reply latch consumed by movement-reply handlers |
| `+0x13eaf4` | `bool m_directionDelayActive` | direction-delay/reverse-phase selector |
| `+0x13eb1e` | `unsigned char m_movementReplyTimerFamily` | records local-event versus FWdA continuation family |
| `+0x13eb1f` | `bool m_movementHistoryEnabled` | adjacent history-enable state; not read by UID0003VD |

The inline helpers are exact source-level operations over those named fields: `ClearMovementReplyState` clears the received/pending latches, `SetMovementReplyState` sets count one and received true, `IsDirectionDelayActive` reads the direction-delay flag, and `SetDirectionDelayActive` writes it. `ClearActiveLineInputPane` remains the independent `+0x210` lifecycle helper.

### Vtable, Behavior, And Source Readiness

- UserPane vtable cell `0x0062efc4` is the sole inbound route to UID0003VD and is the TimerHandler secondary-facet `OnTimer` slot. Zero direct callers are expected for the virtual callback.
- Event 20 and FWdA share four-substep movement based on `4 * g_movementSubstepScale`, signed `m_moveFrame` arithmetic, reply latches, MapPane movement/scroll integration, linked-object propagation/synchronization, and exact continuation behavior. FAnD/default delegation remains inherited.
- UID0003VD owns the one complete out-of-class `UserPane::OnTimer` definition. The class H formal owns the declaration, enum, named fields, and inline helpers. No aggregate or vtable page emits duplicate source.
- Metadata remains `94/95`, canonical owner/emitter UID0000P1, reconstructable true, and emitter position 10. The synchronization improves declaration/source correctness but does not justify raising an already high class score.

### Negative Evidence And Corrected History

- The previous `OnAnimationStep` spelling was a decompiler-era semantic label, not the inherited TimerHandler source contract. It remains historical only.
- The previous broad `m_movementState[5]`, `m_movementHistoryState[2]`, and `ClearMovementHistoryToken` spellings hid independently evidenced byte roles and are superseded by the size-neutral named fields/helpers above.
- The earlier `ObjectPane *m_pendingTargetObject` / `ClearPendingTargetObject()` model at `+0x210` is disproved: the only non-null store is typed `LineInputPane *this`, while target-selection objects remain separate. It is retained below solely as dated provenance.
- No null checks, scale guards, clamps, duplicate wrapper method, or new class layout bytes are supported by the target.

## UID00035P Active Line-Input Slot Correction - 2026-07-30

- The source-facing complete-object slot at `UserPane+0x210` is `LineInputPane *m_activeLineInputPane`, not a pending target `ObjectPane *`. [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) reads the previous pointer, queues that exact `LineInputPane` for deferred deletion, and stores the new constructor receiver. [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md) clears the same slot during dismissal.
- The inline source operation is therefore `ClearActiveLineInputPane() { m_activeLineInputPane = NULL; }`. This naming follows the exact read/queue/store/clear lifecycle and does not infer ownership transfer or a general pending-target abstraction.
- The bounded source declaration continues to model only UserPane-owned bytes after the `0x20c` LivingObjectPane base: four bytes `[+0x20c,+0x210)`, the pointer at `+0x210`, four bytes `[+0x214,+0x218)`, then `m_groupMembers` at `+0x218`. Every field at and after `+0x218` and `sizeof(UserPane)==0x13eb84` remains unchanged.
- Historical pre-Gate-2B IDA held one opaque `0x52`-byte span `[+0x1c6,+0x218)` between inherited state and `m_groupMembers`. Catalog entry 0377 records the applied bounded split: `_userPaneToActiveLineInput[0x4a]` at `+0x1c6`, `LineInputPane *m_activeLineInputPane` at `+0x210`, and `_userPaneAfterActiveLineInput[4]` at `+0x214`. Saved readback preserves `m_groupMembers` at `+0x218`, every later member and tail, and exact total `sizeof(UserPane)==0x13eb84`; no unrelated class member moved or changed.
- UID00035P prestate/backup SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94` is dated history. The applied poststate is authoritative saved IDB SHA256 `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`. The controlled unsaved stack-offset experiment did not affect this type and was discarded before the clean saved transaction.
- Metadata remains `94/95`, owner/emitter UID0000P1, reconstructable true, position 10, and the complete declaration/child topology is preserved. Historical `m_pendingTargetObject` and `ClearPendingTargetObject` text below records a disproved 2026-07-20 interpretation only.

## UID000415 Chat-History Member Contract - 2026-07-30

- `UserPane` owns the shared default-chat history list and all three source-facing member helpers used by Say/Chat input panes. The sole field renamed by this callback is `List *m_chatHistory` at complete-object offset `+0x13eb04`; adjacent `+0x13eb08`, `+0x13eb0c`, and `+0x13eb10` retain their existing outgoing-recipient, incoming-sender, and selector roles.
- `void GetPreviousChatHistoryLine(short *historyCursor, wchar_t *destination, size_t destinationCount)` at `0x005a4930` advances backward with wraparound, copies a bounded wide string from `m_chatHistory`, and updates the caller-owned signed-short cursor.
- `void GetNextChatHistoryLine(short *historyCursor, wchar_t *destination, size_t destinationCount)` at `0x005a4990` advances forward with wraparound and returns an empty destination when navigation moves beyond the newest entry, preserving the caller-owned signed-short cursor contract.
- `void SaveChatHistoryLine(const wchar_t *text)` at `0x005a49e0` ignores empty text, suppresses a duplicate of the newest line, appends a copied wide string, and removes the oldest entry when the list exceeds ten lines.
- [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md) calls the previous/next members through canonical `g_pUserPane` for unmodified Up/Down key-down Events. [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) calls `g_pUserPane->SaveChatHistoryLine(wideText)` after accepting the submitted line. ChatInputPane-family callers share the same list; their physical/source-family placement does not move these receiver-bearing members out of `UserPane.cpp`.
- Saved IDB `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2` is the dated Gate-1 checkpoint. Current authoritative save `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E`, `143193954` bytes, saved `2026-07-30T07:36:29.3601106-04:00`, preserves the three helper bodies at `0x005a4930/0x005a4990/0x005a49e0`, their raw declarations/UserPane receiver use, and stable global [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) as `UserPane *g_pUserPane`. Raw helper and field labels remain dated IDA evidence; the declarations above are the accepted human source reconstruction.
- Historical `m_whisperHistoryOther` at `+0x13eb04` and helper ownership under `SayInputPanes` or `Chatting` are rejected for current source. They remain recorded here as superseded assumptions rather than being deleted from project history.

## UID0001LM Spell-Prompt Accessor Integration - 2026-07-19

- The public inline `const wchar_t *GetSpellPromptText(char spellIndex) const` accessor is the source-facing cross-TU interface used by the six `SpellInputPanes.cpp` prompt constructors. It returns `m_spellCommandSlots[spellIndex - 1].prompt` without creating an out-of-line function or binary entry.
- Exact layout algebra is unchanged: `m_spellCommandSlots` begins at complete-object `+0x13a834`; `SpellCommandSlotRecord` is `0x148` bytes; `prompt[80]` begins at record `+0xa8`. The expression therefore compiles to `UserPane+0x13a794+0x148*spellIndex`, exactly matching all six constructors.
- Plain `char` preserves repeated binary `movsx` semantics and one-based indexing. Direct cross-TU access to the private table is avoided without inventing `UserSpellRecord`, `GetSpellRecord`, or `promptText`.
- The accessor is the only change to the managed declaration. The complete `0x13eb84` layout, size guards, B001/B002/B003/B004/B005 method/field union, current helper declarations, access control, emitter position, `94/95` metadata, and class closure before `[[CHILDREN]]` are preserved.

## UID000477 Hunters-List And Party-Search State Integration - 2026-07-19

- Complete-object `+0x3cb1` is `unsigned char m_huntersListFlag`; exact consumers are UID000477 incoming opcode `0x83`, UID000470 initial checkbox construction, UID00047B retained outbound raw helper, and PartySearch constructor/action paths.
- Complete-object `+0x3cb2..+0x3eb1` is `wchar_t m_partySearchSourceText[256]`. The raw helper and PartySearch paths copy or convert exactly 256 wide characters. Two residual opaque bytes at `+0x3eb2..+0x3eb3` retain the next aligned `m_currentSayMode` at `+0x3eb4`.
- Four public inline accessors provide source-safe cross-context reads/writes without callable binary entries: `GetHuntersListFlag`, `SetHuntersListFlag`, and mutable/const `GetPartySearchSourceText`. Public raw fields, friend expansion, unions, raw-offset overlays, and synthetic packet helpers are rejected.
- The split is exactly size-neutral: old opaque span `0x203` bytes becomes `1 + 0x200 + 2`; every downstream field and the exact `sizeof(UserPane)==0x13eb84` guard remain unchanged.
- Class metadata is raised `93/94 -> 94/95`. Owner/emitter UID0000P1, reconstructable state, position 10, inheritance, every B001/B002/B003/B004/B005 method/field/friend/record, class closure, and `[[CHILDREN]]` remain intact. Exact private spellings remain inferred and cap confidence.

## UID0003UJ Legacy Function-Key Shortcut Integration - 2026-07-16

- [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) is the exact retained source-authored `void UserPane::TryDispatchFunctionKeyShortcut(short functionKeyOrdinal, unsigned int currentTick)` member at `92/93`. The complete class declaration changes only the first parameter from unsigned to signed 16-bit; all current fields, methods, support types, size guards, access sections, friendships, source ordering, and `[[CHILDREN]]` placement remain unchanged.
- The signed declaration is required by the target's `movsx` of the 16-bit argument before index arithmetic. Ordinal zero selects legacy row 9 and every nonzero signed value selects `ordinal - 1`; no range clamp or unsigned normalization is added.
- The method reads direct base-Config `m_legacyShortcutText[10][0x80]` storage through `g_pConfig`, classifies the sign-extended low byte, returns without dispatch for nonalphabetic values, maps full-wide ASCII lowercase/uppercase to one-based command slots `1..26`/`27..52`, and uses `0xff` only for a classifier-accepted full-wide value outside both ASCII ranges.
- UID00030B `g_lastFunctionKeyTick` is UserPane.cpp file-scope zero-initialized storage emitted before this class. The target reads it twice, has no writer or address-taking route, and preserves unsigned wrap/reset debounce behavior without inventing an assignment.
- Owner/emitter remains UID0000P1, class metadata remains `93/94`, reconstructable true, and position `10`. The exact target body emits only from UID0003UJ; this page supplies the compile-visible declaration and does not duplicate method source.
- No function object or surviving caller exists for UID0003UJ, but exhaustive branch/pointer/vtable/duplicate scans and the accepted UID0003UA retained-source precedent support preserving the complete UserPane member. Historical LivingObjectPane, blank/no-code, unsigned-selector, nested-profile, nonalpha-sentinel, and future-writer conclusions are superseded.
- Compiler/linker padding, the preceding vtable forwarder, imported `_isalpha`, command-slot callee internals, and ABI lowering remain outside the class declaration and exact member body.

## UID0003TQ Group And Movement-Tick Helper Integration - 2026-07-16

- The complete `0x13eb84` UserPane declaration is preserved byte-for-byte except for two accepted private declarations: `bool IsGroupMember(unsigned int memberId) const;` before the existing pointer-returning lookup and `void AdvanceMovementSendTick();` after it.
- [UID:0004SM][0x005adba0-0x005adbdc.UserPaneIsGroupMember](by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md) emits the exact const linear predicate over signed `m_groupMemberCount` and embedded 50-entry, `0x12c` GroupMemberRecord table. It returns true on first matching unsigned member id or false after exhaustion without a count clamp or defensive check.
- [UID:0004SL][0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick](by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md) emits the exact tick helper: add 1000 to unsigned `m_lastMovementSendTick`, clamp values at/after TimerMgr current tick to current tick minus one, and forward the result through [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md).
- UID0003TQ owns the caller policy: duplicated membership queries inside the local/group-bar HitBar condition and the local-player/negative-action/name-visible gate for the movement-tick call. These helpers do not absorb MapPane packet logic or Config policy.
- No field, record, access level, inheritance relation, virtual slot, inline helper, forward declaration, size guard, class closure, or `[[CHILDREN]]` position changes. Existing B001/B002/B003/B004/B005 declaration and layout facts, UID0004R9, `StartDirectionalAnimation(char)`, inventory/settings/server-entry/movement/hotkey/appearance unions, and compiler exclusions remain intact.
- Class metadata remains `93/94`, owner/emitter UID0000P1, reconstructable true, position 10. Each helper body emits once from its exact by-memory child; the class block contains declarations only.

## UID0003TX Current-Appearance Tail Integration - 2026-07-16

- The complete shared `0x13eb84` UserPane declaration remains intact. Only the final unresolved `0x45`-byte tail is split without changing size: one byte `m_userPaneTrailingState2` followed by the exact 68-byte `ObjectStatusBlob m_currentAppearance` at `+0x13eb40`.
- UID0002QN is the direct producer. On local-player Human status it calls `SetSpriteConfig(&status, action)` and then copies the by-value status into `m_currentAppearance`; Monster status does not perform the appearance copy.
- The preceding `m_actionMode`, `m_userPaneTrailingState0`, and `m_includeAdjacentMovementTargets` bytes retain their accepted meanings and offsets. No field is inserted, removed, or reordered outside the final size-neutral split.
- MapPane friendship is the compile-visible source route for direct access to `m_playerSettingsState`, linked overlay pointers, transient state, and `m_currentAppearance`. No accessor, wrapper, or duplicate status storage is invented.
- Historical generic `m_userPaneTrailingState2[0x45]` wording is preserved only as the superseded unresolved-tail model. Current direct factory use resolves the final 68 bytes while exact original spelling remains inferred.
- Every B001/B003/B004/B005 shared declaration, record, method, helper prototype, size guard, and `[[CHILDREN]]` insertion remains unchanged around this delta; compiler EH, deleting wrappers, vtables, and pool/storage lowering remain non-emitting.

## UID0003UW Group-List Declaration And Layout Synchronization - 2026-07-15

- Current class metadata remains the stronger `93/94`, owner/emitter UID0000P1, reconstructable true, position 10. This bounded merge preserves the terminal B001 direction-helper ABI, B003 Event/target-selection/helper union and field splits, B004 inventory/server-entry facts, B005 player-settings separation, every unrelated declaration/field/size guard, and the final `[[CHILDREN]]` insertion point.
- [UID:0003UW][0x005ac280-0x005ac69b.UserPaneParseGroupListPacket](by-memory/0x005ac280-0x005ac69b.UserPaneParseGroupListPacket.md) is the exact source-ready `bool UserPane::ParseGroupListPacket(const unsigned char *packet)` member at `92/94`. Opcode `0x63` subtype 2 dispatches to it with `packet + 2`; subtype 3 performs the matching single-member update in UID0003VB.
- `GroupMemberRecord` is the exact naturally aligned `0x12c` source record. It contains member ID, 128-wide-character name, active state, face/hair/body/helmet and three decoration identities/colors, then maximum/current HP and maximum/current MP. Natural alignment supplies bytes `+0x105`, `+0x10f`, `+0x113`, `+0x117`, and `+0x11b`; no artificial reserve fields are authored.
- The table starts at complete UserPane offset `+0x218` as `m_groupMembers[50]`; signed `m_groupMemberCount` follows at `+0x3cb0`. Current typed state is `m_huntersListFlag` at `+0x3cb1`, `m_partySearchSourceText[256]` at `+0x3cb2`, and two residual bytes before current say mode; collection sound state, debounce/input-lock fields, and complete `0x13eb84` class size remain intact.
- [UID:0004R9][0x005adbe0-0x005adc15.UserPaneFindGroupMemberById](by-memory/0x005adbe0-0x005adc15.UserPaneFindGroupMemberById.md) is the exact private linear lookup at `91/93`. It compares `memberId` over the signed count and returns the matching record or null without bounds/null checks.
- MapPane direct access and the two Group.cpp marker replay helpers are represented source-safely by `friend class MapPane`, `RefreshGroupMemberMarkers`, and `ClearGroupMemberMarkers`. The helper declarations are file-scope declarations, not duplicate bodies or class members.
- Historical `LinkedPlayerRecord`, `m_linkedPlayers`, `m_linkedPlayerCount`, `ParseLinkedObjectsPacket`, generic raw field names, and explicit reserve bytes are superseded. Exact parser/helper bodies stay on their by-memory children; this class page emits declarations/layout only and does not handwrite conversion/library, range-failure, cookie, allocator, deleting-destructor, or other compiler-lowered operations.

## UID0003UB Integrated Hotkey-Action Declaration Synchronization - 2026-07-15

- [UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) is the exact nonvirtual `void UserPane::ExecuteHotkeyAction(short hotkey)` member already declared in the managed class block. It retains owner/emitter UID0000FQ, source route [UID:0000P1][UserPane](by-file/UserPane.md), `90/92`, blank position, and `Nested:8`; no virtual slot, field, access-level, inheritance, layout, size-guard, or class-formal change is required.
- [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md) supplies three source digit routes: `0..9` with no modifier, `10..19` with modifier bit 2, and `20..29` with modifier bit 1. Optimized machine code merges them into the sole direct UID0003UB call at `0x005a5ce5`; the caller controls the page and the target adds no bounds guard.
- UID0003UB rotates multiples of ten to the preceding decade's final row and other values to the zero-based row, then consumes one of 30 exact `MacroHotkeyRecord` rows at inherited Config-base runtime offset `+0x28f2ec`. Text state builds opcode `0x0e`, subtype `0`, one-byte ACP length and text, copies through MemoryMan, and sends `textLength + 3` through `g_packetSender`; both terminators are local-only. Spell state calls the existing `UseCommandSlot` declaration at `0x005a3bf2/0x005a3c28/0x005a3c4e`, and Item state calls the existing `UseInventorySlot` declaration at `0x005a3ba1`.
- Historical UID0003UB callback state left its behavior-complete target formal blank because the then-current Config declaration lacked a legal macro-table member. The current complete base-Config declaration now resolves that support blocker, while this bounded callback intentionally leaves UID0003UB's own page/formal unchanged. Nested-profile, RegistryConfig-cast, raw-offset, placeholder-layout, range-check, cookie/EH, and decompiler routes remain rejected; all UserPane declarations and B001/B002/B003/B004 unions remain unchanged.
- Historical LivingObjectPane ownership, `UseSpellSlot`, unresolved state/helper labels, and the former nested-profile target body are retained only as superseded provenance. Current helper ownership and signatures are `UserPane::UseCommandSlot(unsigned char)` and `UserPane::UseInventorySlot(unsigned char)`.

## B001 UID0002QY Accepted Callback Synchronization - 2026-07-14

- Final metadata is `93/94`, owner/emitter UID0000P1, reconstructable true, position 10. Destination 12 is the single authoritative UserPane declaration and preserves the trailing children insertion point, existing virtuals/accessors, and unrelated current class facts.
- The declaration begins at the exact `0x20c` LivingObjectPane base boundary and ends at `0x13eb84`. It supplies exact linked-player, inventory, spell-command, movement-history, deferred-packet, map/screen/action, collection, and tail state needed by all 33 member definitions.
- Inventory storage is `m_inventorySlots[52]` at `+0x134104..+0x13a834`; spell-command storage begins immediately at `+0x13a834`. One-based source indexing uses `slot - 1`; the old adjusted machine displacement is not modeled as an overlapping member or invented inter-table pad.
- Semantic declarations are synchronized for ParseInventorySlotUpdatePacket, HandleMovementReplyPacket, and HandleExtendedMovementReplyPacket. Every formerly blank source-bearing member has a complete declaration and destination body.
- File-local HandleUIPanelSwitchPacket and SendDirectionPacket prototypes precede first use but are not class members. UID0003UU remains outside UserPane. Exact original private spellings are confidence-capped without leaving layout, access, type, declaration, or emitter blockers.

## UID0003H4 Direction Packet Helper ABI Synchronization - 2026-07-15

- [UID:0003H4][0x005acae0-0x005acb1f.UserPaneSendDirectionPacket](by-memory/0x005acae0-0x005acb1f.UserPaneSendDirectionPacket.md) is the retained UserPane.cpp file-local direction-packet helper at `92/93`, with canonical owner/emitter [UID:0000P1][UserPane](by-file/UserPane.md), reconstructable true, blank position, `Nested:0`, and a complete nonblank source body. It is not a `UserPane` class member and adds no field, virtual slot, access requirement, layout byte, or size-guard change.
- The exact machine body consumes one byte from its only stack argument and ends in `retn 4`. The file-scope declaration therefore uses explicit `static void __stdcall SendDirectionPacket(unsigned char direction)`, matching the authoritative definition and preserving callee cleanup for one four-byte argument slot. The earlier plain-static prototype omitted an observed ABI fact and is superseded.
- The helper builds local bytes `{0x11, direction, 0}` and sends exactly two bytes through `g_packetSender->QueueAndSendPacket`; the local zero is not part of the requested payload. It reads no receiver, overwrites `ecx` with the packet sender, and is intentionally declared outside `class UserPane`.
- The retained out-of-line body has no direct entry route, but the same opcode-`0x11` serializer is realized in ProcessMovement, SendAutoFaceDirectionPacket, and SendActionPacketWithAutoFace. ProcessMovement and UID0003H5 are its two direct source callers; UID0003UZ calls H5 and reaches the serializer transitively through compiler inlining. This supports file-local retained/inlined source rather than LivingObjectPane ownership, member qualification, covered-by treatment, or blank C++.
- Current class metadata remains B003's stronger `93/94`, owner/emitter UID0000P1, reconstructable true, position 10. The complete Event, target-selection, server-entry, player-settings, inventory, group-member, movement, field-layout, size-guard, and `[[CHILDREN]]` union is otherwise byte-for-byte preserved by this one-token formal synchronization.

## UID0003H5 Auto-Face Declaration And Dependency Synchronization - 2026-07-15

- The complete managed class block already declares `void SendAutoFaceDirectionPacket();` and `void SendActionPacketWithAutoFace();` in source order. No declaration, field, access level, vtable slot, layout byte, size guard, position, score, or `[[CHILDREN]]` change is required.
- UID0003H5 is the `92/93` retained source member that looks up `s_selectObjectTargetId` through externally linked `g_activeMapPane`, then uses inherited `m_mapY`, `m_mapX`, and `m_facing` with exact row/column and integer-quotient direction behavior before calling file-local UID0003H4.
- UID0003UZ is the `92/94` modeled action sender with one UID0003UD caller. It source-calls UID0003H5 for action mode `1`, preserves action modes `0/1/2`, unknown-mode packet size, dynamic terminator, and opcode `0x13` ordering; compiler inlining explains its duplicate H5/H4 machine realization.
- UID0003EB is UserPane.cpp compiler-pooled `-1.0f` support covered by H5/HUZ source literals, not a class static field or LivingObjectPane-owned declaration. `g_activeMapPane` and `s_selectObjectTargetId` remain external source dependencies, not UserPane fields.
- B005's report-only UID0003UP/UID0003UQ artifact SHA `D42D13C36310140D1BC899A31EB7F4C7FCFA292A2059F45507870861FD14EA13` and the full live class union were reread immediately before this additive edit. The complete B005 movement-reply/Config proposal, all current methods and fields, and the formal class block remain unchanged.

## UID00037V Blindness-State Support - 2026-07-14

- [UID:0003UL][0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket](by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md) retains the complete B001-managed UserPane body and now names its saved `m_playerSettingsState[4]` value `oldBlindnessLevel` rather than `oldSpeed`.
- The parser invalidates MapPane movement bounds only when byte `[4]` changes. Exact render child [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md) independently tests that byte: zero executes ordinary world rendering; nonzero uses a solid color-128 fill and renders only the local player plus attached effects. This proves blindness-level semantics and rejects speed.
- `m_playerSettingsState` remains the existing eight-byte class field at `+0x1340fc`; no declaration, offset, size guard, access level, owner/emitter, score, or source route changes. Exact original array/member spelling remains stripped and is a lexical cap only.
- This support rebase preserves B001's complete class declaration, all 33 member definitions, UserPane-only large-offset layout, concurrent UID00037X friendship/adjacency field, and `[[CHILDREN]]` placement without compression.

# UserPane

## UID00037R MapPane Keyboard Consumer - 2026-08-24

- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) consumes two existing UserPane contracts. First, `m_playerSettingsState[0]` is the exact feature-mode gate for MapPane's `-`/`=` day/night brightness stepping; the setting remains UserPane-owned state.
- Second, the MapPane call at `0x005070c1` targets [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md). Exact Control plus lowercase `a`..`z` maps to slots 1..26; exact Control+Shift plus uppercase `A`..`Z` maps to slots 27..52.
- MapPane owns key translation and slot-number derivation. UserPane retains validation, inventory-record lookup, target-mode dispatch, packet send, and target-prompt behavior. No UserPane declaration, layout, source body, or ownership changes are required.

## Mix-Item Dialog Opener - 2026-08-16

- [UID:00054G][0x005a4de0-0x005a4e3d.UserPaneOpenMixItemDialog](by-memory/0x005a4de0-0x005a4e3d.UserPaneOpenMixItemDialog.md) emits `void UserPane::OpenMixItemDialog()` through this class and [UID:0000P1][UserPane](by-file/UserPane.md).
- The sole caller at `0x004ed269` is immediately preceded by `mov ecx,g_pUserPane`, proving the UserPane member ABI. The helper checks `g_pMixItemDialog`, allocates `0x26c`, and invokes the parameterless constructor only when absent.
- This addition closes NewInventoryPane's action-button API without transferring helper ownership into NewInventoryPane, exposing singleton internals, or changing UserPane's existing `94/95` score.

## UID0000LU NewSpell Access Synchronization - 2026-08-15

`class NewSpellInventoryPane;` and `friend class NewSpellInventoryPane;` grant the reconstructed owner access to the existing private inline `GetSpellCommandSlotRecord(unsigned char)`. The complete `SpellCommandSlotRecord` layout and getter body are preserved verbatim; no new public getter or reduced record API was introduced.

## UID0003F8 NewGroupPane Group-Member Access Synchronization - 2026-08-16

- `GroupMemberRecord` remains the global source type declared before `UserPane`; it is not nested as `UserPane::GroupMemberRecord`. The exact naturally aligned `0x12c` record, `m_groupMembers[50]` at complete-object offset `+0x218`, signed `m_groupMemberCount`, and every later UserPane field and size guard remain unchanged.
- `NewGroupPane::OnPaint` reads the private group table directly while iterating displayed rows. The binary accesses the embedded table through `g_pUserPane`, so the source-faithful access route is the bounded `friend class NewGroupPane;` declaration rather than a public table, synthetic accessor, reinterpret cast, or duplicated record definition.
- The forward declaration and friendship change no object bytes, inheritance, vtable slot, source owner, emitter route, or score. [UID:0000FQ] remains `94/95`, owned/emitted by UID0000P1 at H position 10.
- The paint method copies identity/appearance and HP/MP state from each `GroupMemberRecord`, but it builds `HumanImageRenderParams` with exact partial writes rather than copying a complete appearance object. That consumer relationship belongs to Group.cpp and does not transfer record ownership from UserPane.h.
- Historical generated source that used `UserPane::GroupMemberRecord` was declaration-invalid and is superseded. Narrow friendship preserves the private storage contract and matches existing `MapPane`, spell-pane, and file-helper friendship patterns already used by this declaration.

## UID0000KA Inventory Consumer Contract - 2026-08-15

Legacy `InventoryPane` and `InventoryPane2` consume, but do not own, `g_pUserPane`, exact `LocalInventorySlotRecord` storage, `GetInventorySlotAddress(char)`, `UseInventorySlot(unsigned char)`, and `IsInputLocked() const`. The complete record remains 0x1FC bytes; panes scan one-based slots `1..52`, map only active rows to visible ordinals, draw/hit-test locally, and call the owner APIs for use/lock decisions. The new field-safe inline declaration returns existing `m_inputLocked` at `+0x13eb1d`; it adds no field, offset, helper body, or duplicate storage.

## UID0004YC Local-Player Status Request Support - 2026-07-29

- [UID:0004YC][0x005a4f70-0x005a500f.RequestLocalPlayerStatus](by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md) is an externally linked UserPane.cpp helper, not a `UserPane` member. It sends the exact two-byte `{0x2d,0}` request and stores the caller-provided message time in `g_epfLocalPlayerStatusRequestTime` or `g_legacyLocalPlayerStatusRequestTime` according to `g_useEpfAssets`.
- The global-scope H declaration emitted by UID0004YC supports MapPane, IconsPane, the retained old-HUD raw body, and TabPane consumers. The complete class declaration is unchanged at `94/95`; no duplicate member, source-visible opcode-derived API, or reverse-engineered `dword_69BF6C/70` name is introduced.
- Historical `SendOpcode2DAndStoreExtra`, `g_opcode2dEpfCommandExtraValue`, and `g_opcode2dLegacyCommandExtraValue` are superseded descriptions. The semantic status-request API and unsigned request-time storage are supported by all callers and the inline UserPane equivalent.

## UID0003ZT MapPane Field And Header Contract - 2026-07-23

- `MapPane+0x418` is source-typed `UserPane *m_localPlayerObjectPane`, not merely `LivingObjectPane *`: the timer path calls UserPane-only `ProcessMovement`, while UserPane inheritance preserves every LivingObjectPane/ObjectPane operation used elsewhere.
- The complete UserPane declaration is exported through the inferred same-basename `NexusTK/ui/panels/UserPane.h` contract. MapPane.cpp includes UserPane.h before member calls through the `+0x418` field.
- UserPane.h also provides the declaration visibility for `extern UserPane *g_pUserPane;` and `extern InputBlockerPane *g_pInputBlockerPane;`, with `InputBlockerPane` forward-declared where only pointer completeness is required.
- The corresponding definitions remain in their existing emitters; MapPane adds no duplicate singleton storage and does not take UserPane ownership.
- This consumer/header closure preserves `94/95`, owner/emitter [UID:0000P1][UserPane](by-file/UserPane.md), the complete class formal, inheritance/layout, every existing method/packet/UI fact, and all prior source order.

## UID00029O Status-Layer Consumer Evidence - 2026-07-21

Two preserved InputBlocker paths at `0x005a7d90` and `0x005abd49` consume independent `g_pStatusPaneLayer` through physical storage `0x0069b378`. UserPane neither owns nor defines that global. The complete current class union, including all concurrent movement, packet, option/settings, inventory, group, action, history, viewport, timer, social, field-layout, ABI, helper, server, and caller evidence, remains unchanged. Broad dispatcher/aggregate formals stay blank and this bounded synchronization adds no C++.

## Current UID0002QY Source Boundary - 2026-07-14

- Current declaration authority: the managed block above is the complete source-facing UserPane declaration, size `0x13eb84`, derived from the exact `0x20c` LivingObjectPane base, with every required field/type/method and `[[CHILDREN]]`.
- Current source family: 33 moved receiver-bearing bodies are current `UserPane::` members under UID0000FQ/UID0000P1. UID0003UT and UID0003H4 are UserPane.cpp file-local/static helpers and therefore have no class-member qualification. UID0003UU remains outside this class.
- Current formal/body state: every one of the 35 moved pages is reconstructable and nonblank with the accepted definition. No current UserPane class section treats those bodies as LivingObjectPane-owned, blank, no-code, or deferred.
- Current evidence retention: all valid class purpose, constructor/destructor, event/vtable, field/layout, caller, packet, route-negative, and source-order evidence below remains retained; only the superseded source-owner/qualification and blank-body conclusions are rejected.

## Historical / Superseded Assumptions - Pre-2026-07-14

- Date/source: the nested UserPane class material below records earlier source-quality passes incorporated before the final UID0002QY UserPane ownership and integration repair.
- Rejected claim: UserPane-only large-offset bodies belonged to LivingObjectPane/LivingObjectPane.cpp, retained reverse-engineering qualifiers/placeholders, or required blank/no-code treatment because a direct route or declaration was missing.
- Disproof evidence: the complete LivingObjectPane object ends at `+0x20c`; receiver-bearing moved bodies use UserPane-only `+0x134000..+0x13eb84` state, the two no-receiver helpers cluster with UserPane source, and the complete UID0000FQ/UID0000P1 declaration/definition route compiles those bodies without an access or type gap.
- Accepted replacement: 33 UserPane members and two UserPane.cpp file-local/static helpers, each with its current nonblank managed body. UID0003UU remains the explicit unchanged LivingObjectPane.cpp exception.
- Evidence preservation: factual bytes, ranges, callers, xrefs, fields, ABI, packet behavior, negative evidence, and provenance below remain valid evidence unless a nested sentence states one of the rejected conclusions above.

### Status

- Confidence: strong for IDA-confirmed method boundaries, vtable slots, singleton/global lifetime, and source parent; medium-high for final field names and the exact split from adjacent social and movement helpers.
- Likely source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Address range: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- Evidence basis: live IDA MCP inspection on 2026-06-04 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Reconstruction status: reconstructable under [UID:0000P1][UserPane](by-file/UserPane.md). B010's accepted 2026-07-01 empty-emitter audit makes the class declaration source-ready and populates formal C++ with a declaration-level shell plus `[[CHILDREN]]`. Exact method bodies still belong on exact by-memory children such as [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md), [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), and [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md); the class page must not duplicate those method bodies.

### Class Purpose

`UserPane` is the local player/user display pane. It constructs the main local-user pane object, stores large per-user state arrays, routes key and server-message input, updates animation and clipping, tracks visible slot labels, and manages the floating local name label.

### Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `UserPane::UserPane()` | `0x005a2530-0x005a2c5b` | Constructs the pane, installs all three `UserPane` vtables, stores `this` in [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / source-facing `g_pUserPane`, vector-constructs 128 large records at stride `0x2604`, initializes child/state fields, handles EPF/non-EPF branches, copies [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) to `m_mapPane` at `this+0x1340f8`, writes `MapPane+0x418 = this`, constructs the BowGauge child at `0x005a2956`, and creates the direct-message history children including `+0x13eb08` outgoing recent recipients and `+0x13eb0c` incoming/fallback sender history as ten-entry `List(0x40, 0x0a)` name lists. |
| `UserPane::~UserPane()` non-deleting cleanup body | `0x005a2c60-0x005a2d74` | Restores `UserPane` vtables, deletes/releases the `+0x13eb04/+0x13eb08/+0x13eb0c` children, frees dynamic buffers, runs BowGauge timer/show cleanup, vector-destroys the 128 records, clears [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `g_pUserPane`, and calls base cleanup. The `+0x13eb08/+0x13eb0c` children are the outgoing-recipient and incoming/fallback whisper-sender history lists selected by byte `+0x13eb10`. |
| file-scope `SetLocalPlayerName` / `SetUserPaneNameBuffer` | `0x005a2d80-0x005a2d97` | Bounded `wcscpy_s` into the 32-wide-character local-player name buffer at `word_69BEE0`; called from UI initialization at `0x004f84ad` and `0x004f8a14`. Treat as a UserPane file-scope helper unless later source evidence proves it was a static class method. |
| `UserPane::BuildInventorySlotRangeText(wchar_t *out)` | [UID:0004R7][0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText](by-memory/0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText.md) | Builds compact inventory slot label/range strings; callers include repeated dispatch sites inside `HandleKeyOrTextEvent` plus nearby command-row helpers. Historical `BuildInventorySlotLabelString`/`OnKeyEvent` spellings are superseded. |
| `UserPane::BuildSpellSlotRangeText(wchar_t *out)` | [UID:0004R8][0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText](by-memory/0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText.md) | Builds compact spell slot label/range strings over 52 spell slots; callers include `HandleKeyOrTextEvent` and helper sites at `0x005a9e9d` and `0x005b618f`. Historical `BuildSpellSlotLabelString`/`OnKeyEvent` spellings are superseded. |
| `UserPane::OnBoundsChanged(...)` | [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md) | Updates cached bounds and invalidates child geometry; first-draft C++ is plausible after rectangle helper and field names are accepted. |
| `bool UserPane::HandleKeyOrTextEvent(Event *event)` | [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md), switch-table child [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables.md) | Complete source-ready EventHandler override for local-player keyboard/text commands and related pane/packet dispatch. It returns handled/unhandled in `AL`, emits exact R1 through UserPane.cpp, and retains `OnKeyEvent`/`HandleKeyEvent`/`PaneKeyEvent` only as superseded provenance. UID0003VA is compiler-generated switch/selector data and remains non-emitting. |
| `bool UserPane::OnServerMessage(const ServerMessageEvent *event)` / `HandleServerMessage` | [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), switch-table child [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md) | Handles server message payloads routed to the local user pane. Reads packet payload pointer/size at event `+0x0c/+0x10`; opcode `0x36` is the inline user-list packet case, not a call to standalone `0x005abb20`; opcode `0x58` directly calls [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) at `0x005a8172`, but that helper has no UserPane field access and emits as a file-local [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) packet helper. |
| `bool UserPane::OnTimer(int timerId, int arg0, int arg1)` | [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) | Complete TimerHandler override. Local event `20` and inherited `FWdA` perform exact four-substep movement/reply/map/linked-object behavior; `FAnD` and default delegate to `LivingObjectPane::OnTimer`. The adjusted machine receiver is the `+0xa4` TimerHandler facet, all target fields/helpers are resolved, and the exact child emits complete CPP. |
| `UserPane::OnClipBounds(...)` | `0x005a8840-0x005a88cf` | Calls base `LivingObjectPane` clipping and optionally intersects a centered avatar/name-label clip rectangle using client-state option and render flags. It ends before one `0xcc` byte at `0x005a88cf`; the following [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) body is a separate `LivingObjectPane` local-player screen-position/cache method called from `MapPane` render through `MapPane+0x418`. Future exact child should be created before formal C++. |
| `ShowNameLabel` | `0x005a8e70-0x005a8f5a` | Sets the visible/name-label flag, computes the pane rectangle from the current bounds, drives [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) virtual show/position calls, and calls BowGauge helper `0x00538c10`. |
| `HideNameLabel` | `0x005a8f60-0x005a8f8c` | Clears the visible/name-label flag, removes pending timers from [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) through [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md), and caches `dword_67AB80+0x18` into `this+0x13eaf8`. |
| `UserPane::SendDropItemPacket(signed char slot, bool allItems)` | `0x005ad7a0` | FunctionObject-bound item-action callback used by DropAll/Drop confirmation panes; sends opcode `0x08`, selected slot, and all-items/single-item mode through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). |
| `UserPane::SendGiveItemPacket(signed char slot, bool allItems)` | `0x005ad720` | FunctionObject-bound item-action callback used by GiveAll/Give confirmation panes; sends opcode `0x29`, selected slot, and all-items/single-item mode through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). |
| UserPane collection/name record constructor helpers | `0x005b7560`, `0x005b75a0`, destructor candidate `0x005b7660` | Future exact split candidates for the nested UserPane record array. B013 evidence says `0x005b7560` initializes a `0x4c`-byte record with three SSO UTF-16 string fields and a byte flag; `0x005b75a0` vector-constructs `0x80` of those records and clears a leading byte; `0x005b7660` releases the same fields; and `0x005ad820` uses the ctor/dtor for stack temporaries while swapping two `0x2604`-stride UserPane records. Exact semantic field names remain medium confidence. |
| scalar deleting destructor | `0x005b8230-0x005b8395` | Full destructor body plus conditional pool return through `byte_69BF34`; vtable xrefs and thunks at `0x005b792e`/`0x005b7939` point here. |
| `GetMapPane` virtual accessor | `0x005b83a0-0x005b83a7` | Tiny vtable accessor returning `MapPane *m_mapPane` at `this+0x1340f8`; B001 2026-06-18 operand scan resolves the field from constructor copies of `g_activeMapPane` and MapPane-helper consumers. |

### Source-Facing Field And Helper Guidance

- Use `g_pUserPane` as the source-facing name for `dword_67A748` where code is reconstructed, while retaining [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) as the stable alias/search path. The storage is a broad local-player/UserPane/client-state pointer, not collection-private.
- Use mutable/const `GetCollectionData()` as the source-facing typed feature-view contract over the in-object collection storage that begins at `this+0x3ec8`. The accessor is inline-capable and adds no binary function or second storage object; it prevents collection source from exposing raw `UserPane` offsets, `0x2604` strides, byte indexes, or string reinterpretation.
- Use `g_localPlayerName` or `s_localPlayerName` as the descriptive direction for `word_69BEE0`; the exact storage remains [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md), a fixed `wchar_t[32]`.
- Use `s_userPanePool` / `UserPanePoolStaticStorage` for `byte_69BF34`; it is the UserPane pool object, not arbitrary raw bytes.
- Treat `this+0x1340f8` as `MapPane *m_mapPane`.
- Treat `this+0x13eb20..+0x13eb30` as UserPane-owned deferred user-list state: `m_deferredUserListPacket`, `m_deferredUserListPacketSize`, `m_userListPacketTick`, `m_userListDeferUntilTick`, and the one-shot `m_skipNextUserListPacket`. The live opcode `0x36` inline server-message path and retained out-of-line [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) body use the same state.
- Treat `this+0x13eaf8` as a name-label hidden/timer tick field. `HideNameLabel` stores the current timer tick there; `ShowNameLabel` uses nearby name-label timestamp state and can backdate by 5000 under a UserPane flag.
- Keep the three list children at `+0x13eb04/+0x13eb08/+0x13eb0c` behavior-named until caller use is fully mapped; current evidence supports UserPane-owned list children, with `+0x13eb08` outgoing recent recipients and `+0x13eb0c` incoming/fallback senders.
- Do not invent final `SpellManager`, collection-private, or BowGauge-owned names for UserPane fields without stronger source evidence.

### Emission Policy

The class and broad [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md) aggregate clear the current routing gate. B010's 2026-07-01 implementation-callback update resolves the class page itself as a declaration emitter: the formal C++ block contains the high-confidence class shell, virtual method prototypes, callback packet helpers, and `[[CHILDREN]]`. Method bodies still emit at exact source-bearing children. The class block must not absorb excluded LivingObjectPane, SayInputPanes, Chatting, FunctionObjects, MapPane, BowGauge, UserStatusPane, compiler switch-table artifacts, or broad parent aggregate source.

The UID00010X callback rebases that complete block additively: only the `CollectionPlayerDataView` forward declaration and two `GetCollectionData()` overloads are new. Every pre-existing virtual, packet helper, access level, and `[[CHILDREN]]` position is preserved. [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) proves the view boundary through the 128 records constructed by `UserPane`, while [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) remains the sole global pointer storage definition.

Good next exact split or first-draft candidates are the constructor, non-deleting cleanup body, local-player name setter, inventory and spell slot-label builders, `OnBoundsChanged`, `OnClipBounds`, `ShowNameLabel`, and `HideNameLabel`. Keep `OnKeyEvent`, [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), and [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) method-body C++ out of this class page. [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) now has a target-specific no-current-improvement formal comment because the current body is a 99-basic-block packet switch with unresolved remaining packet structs. [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) now has a target-specific no-current-improvement formal comment because fresh MCP decompilation proves an adjusted facet where the `LivingObjectPane` base is `this - 0xa4`; UserPane-local `0x14` and local-player movement field/helper names remain the blocker, not the resolved `FWdA`/`FAnD` LivingObjectPane timer constants.

Also create future exact children for the B013 record-layout candidates at `0x005b7560-0x005b759f` and `0x005b75a0-0x005b75ce` before formal C++. They are separated from the preceding BlockListen find helper by padding and should be researched as UserPane nested record constructors/destructors, not as BlockListen or ConfirmInputPane code.

### Live IDA Evidence

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, checked through IDA MCP on 2026-06-04.
- Function boundaries confirmed by `lookup_funcs`: constructor `0x005a2530-0x005a2c5b`, cleanup `0x005a2c60-0x005a2d74`, name setter `0x005a2d80-0x005a2d97`, inventory/spell label builders `0x005a40d0-0x005a430c` and `0x005a4310-0x005a4523`, virtual handlers `0x005a5b80-0x005a5bc7`, `0x005a5bd0-0x005a7422`, `0x005a76c0-0x005a82bd`, `0x005a83b0-0x005a87ad`, `0x005a8840-0x005a88cf`, name-label methods `0x005a8e70-0x005a8f5a` and `0x005a8f60-0x005a8f8c`, scalar destructor `0x005b8230-0x005b8395`, and adjacent accessor `0x005b83a0-0x005b83a7`.
- Constructor direct callers are `0x004f84e2` and `0x004f8a49`, both inside the UI initialization function at `0x004f7d10`; the local-name setter is called from the same function at `0x004f84ad` and `0x004f8a14`.
- Constructor setup: `0x005a2587` stores `this` into [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`; `0x005a25b7`, `0x005a25bd`, and `0x005a25c7` install the three `UserPane` vtables; `0x005a2598-0x005a25d1` vector-constructs 128 records of size `0x2604`; `0x005a277b` / `0x005a2a85` zero the cached map-pane member, `0x005a2785` / `0x005a2a8f` load [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), `0x005a2792` / `0x005a2a9c` store it into `MapPane *m_mapPane` at `+0x1340f8`, and `0x005a2798` / `0x005a2aa2` write the inverse `MapPane+0x418 = this` active/local object pointer.
- Collection view boundary: the array starts at `this+0x3ec8`; `128 * sizeof(CollectionGroupRecord) == 128 * 0x2604 == 0x130200`, ending exactly at `this+0x1340c8` for `groupCount`, followed by `metadataLoaded` at `+0x1340c9`. This supports the accessor declaration without requiring a broad public `UserPane` member layout.
- Direct-message history setup: the constructor-created `+0x13eb08` and `+0x13eb0c` children are fixed-width `List(0x40, 0x0a)` name-history lists. `+0x13eb08` is the outgoing/recent whisper-recipient list updated by `sub_5A4B60`, `+0x13eb0c` is the incoming/fallback sender list updated by [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md), and byte `+0x13eb10` selects which list `SayToUserNameInputPane` preloads/navigates.
- B003 [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) reanalysis uses source-facing helper names `GetPreviousRecentRecipientHistory`, `GetPreviousFallbackRecipientHistory`, and `UpdateRecentRecipientList` for the `+0x13eb08/+0x13eb0c/+0x13eb10` dependency. These names clarify call sites but do not make `SayToUserNameInputPane` a `UserPane.cpp` class.
- Destructor setup: both cleanup bodies restore the same three vtables, release child pointers at `+0x13eb04`, `+0x13eb08`, and `+0x13eb0c`, free `+0x13eb14` and `+0x13eb20`, call BowGauge cleanup through `dword_69BA24`, vector-destroy the 128 records, and clear [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748` at `0x005a2d55` or `0x005b832c`.
- Vtable slots confirmed in `.rdata`: `0x0062ef0c -> 0x005b8230`, `0x0062ef18 -> 0x005a5b80`, `0x0062ef28 -> 0x005b83a0`, `0x0062ef5c -> 0x005a8840`, `0x0062ef80 -> 0x005a8e70`, `0x0062ef84 -> 0x005a8f60`, `0x0062ef98 -> 0x005a5bd0`, `0x0062efa0 -> 0x005a76c0`, and `0x0062efc4 -> 0x005a83b0`.
- 2026-06-16 B001 retry split the former `0x005a5b79-0x005a87e0` leaf into exact UserPane method children [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md), [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md), [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), and [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md), ignored switch-table children [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables.md) and [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md), and a separate LivingObjectPane raw helper [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md). Scores remain `86/86`; this was an exact child/support update, not a full class rescore.
- Global/data xrefs: [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748` is written by the constructor at `0x005a2587` and cleared by cleanup at `0x005a258e`, `0x005a2d55`, and `0x005b832c`; accepted [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) evidence also records clear helper `0x005b7640`, so the complete write set has five UserPane-only writes. `word_69BEE0` is used by the setter/getter/conversion helpers at `0x005a2d88`, `0x005a2da3`, `0x005a2dc6`, and block-list validation at `0x005b6df4`; the `byte_69BF34` pool is referenced by static construction `0x0041a4b7`, unwind cleanup `0x00502445`, scalar return-to-pool `0x005b834e`, and static cleanup `0x0060c450`.
- BowGauge relationship: IDA xrefs show the BowGauge constructor `0x00538bc0` is called only from `UserPane` at `0x005a2956`; BowGauge timer cleanup `0x00538c40` is called from `0x005a2d28`, `0x005a8f7b`, and `0x005b82ff`; BowGauge update helper `0x00538c10` is called from `ShowNameLabel` at `0x005a8f46`.
- Boundary padding is confirmed as `0xcc`: `0x005a2523-0x005a2530`, `0x005a2c5b-0x005a2c60`, `0x005a2d74-0x005a2d80`, `0x005b8395-0x005b83a0`, and `0x005b83a7-0x005b83b0`.
- B003 Rule 26 reanalysis of [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) resolves `0x005ad7a0` and `0x005ad720` as the `UserPane` member packet callbacks bound into drop/give confirmation FunctionObjects. Both bodies are packet helpers that do not need `ecx`, but the construction sites pass them as `UserPane` member-function pointers and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) dispatches them through the captured `UserPane *` target.
- B014 direct PE verification supports creating future exact children for `0x005ad7a0-0x005ad811` and `0x005ad720-0x005ad791` under this class/file. The two targets have no direct rel32 caller route; their pointer/immediate hits are the four confirmation-action construction sites only. That is expected callback binding evidence, not proof of free-function or ItemActionInputPane ownership.
- 2026-06-22 B013 neighbor review records `0x005b7560-0x005b759f` and `0x005b75a0-0x005b75ce` as UserPane record constructor split candidates: raw exports show a nested `0x4c`-byte record with three SSO-style UTF-16 strings and a byte flag, an array constructor for `0x80` records, matching release helper `0x005b7660`, constructor use in the main `0x2604`-stride UserPane record array, and stack-temporary/swap use from `0x005ad820`.

### Boundary Notes

- Keep `0x005a4930-0x005a5791` with chat/history/say-input documentation unless later caller evidence proves the original source intentionally grouped those helpers with `UserPane`.
- Keep neighboring movement/combat/local-object helpers such as `0x005a2de0`, `0x005a2e00`, `0x005a4530`, `0x005a5a90`, `0x005a87e0`, `0x005a88d0`, and `0x005a8cf0` with [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md) or the appropriate movement/object-pane owner. [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) is padding-separated from `UserPane::OnClipBounds` and should remain a LivingObjectPane child.
- Keep [UID:0000FP][UserLookPane](by-class/UserLookPane.md), [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), and [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) separate. The adjacent `0x005b83a0-0x005b83a7` accessor is `UserPane`-owned by vtable slot, but `0x005b83b0` starts the separate `UserStatusPane` range.

### Evidence Notes

- The class is reconstructable enough to attach to [UID:0000P1][UserPane](by-file/UserPane.md) because the constructor/destructor, virtual slots, source path, singleton/pool lifetime, and related child/global docs are all IDA-backed and the parent confidence is above the attachment threshold.
- B010's 2026-07-01 empty-emitter audit raised the class page to `88/88` and populated the declaration shell. The 2026-07-13 UID00010X callback raises it to `89/89` by adding only the forward-declared typed collection view and mutable/const accessor declarations. Existing virtuals and packet callbacks remain unchanged, and unresolved broad handler bodies still belong on exact child pages. `FWdA` and `FAnD` remain resolved LivingObjectPane timer tags.
- The broad address neighborhood still requires exclusions: nearby social/history helpers and `LivingObjectPane` movement helpers are real code, but they are not proven `UserPane` class methods.
- Historical 2026-06-18 opcode-`0x36` interpretation: [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) correctly owns the live inline case, and the no-call decision remains valid. The then-current claim that [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) was a `LivingObjectPane` helper is superseded: exact `0x13ebxx` receiver storage proves an ordinary retained `UserPane::HandleUserListPacket` member body. Preserve both machine-code forms and do not rewrite the dispatcher as a call.
- 2026-06-21 B011 opcode `0x58` source-shape audit: [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) owns the dispatcher case and sole direct call at `0x005a8172`, but [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) is `ret 4`, takes one stack packet argument, ignores the seeded local-player `ecx`, and should not be represented as a UserPane or LivingObjectPane member method.

### Cross-References

- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md)
- [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md)
- [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md)
- [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md)
- [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md)
- [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md)

### UID00037X MapPane Movement-Target Support - 2026-07-14

- The complete managed class block preserves every existing UserPane declaration, record, field, size guard, and `[[CHILDREN]]` position while adding only binary-proven MapPane access and the exact trailing-field split required by movement-target collection.
- `friend class MapPane` permits UID0004QC to read UserPane `m_actionMode`, inherited `m_facing`, and `m_includeAdjacentMovementTargets` directly, matching the binary without synthetic getters or public exposure.
- Byte `+0x13eb3c` remains `m_actionMode`. Previously opaque trailing byte `+0x13eb3d` remains unresolved one-byte state. Exact byte `+0x13eb3e` is `m_includeAdjacentMovementTargets`; only value exactly `true` enables parallel-lane expansion in action mode 2 and eight-neighbor expansion around the selected target in other modes. Tail storage resumes at `+0x13eb3f` for `0x45` bytes, preserving exact class size `0x13eb84`.
- UID0003UI uses `m_actionMode` to select packet subtype `2` versus `3`, records `m_lastMovementInputTick`, and retains `m_lastMovementSendTick` for clamped elapsed encoding. MapPane's collector consumes the state; UserPane remains owner of the fields and packet sender.
- Historical broad trailing-state treatment was layout-incomplete. It is superseded only for `+0x13eb3e`; neighboring bytes remain explicitly unresolved rather than receiving inferred names.
- Scores, owner/emitter, source route, unrelated field inventory, and all prior UserPane evidence remain unchanged.

### Changes

- 2026-07-30 B007 UID000415 accepted ordinary implementation callback:
  - Preserved `94/95`, owner/emitter UID0000P1, position 10, complete class layout, size guards, all concurrent declarations, and `[[CHILDREN]]`.
  - Added the exact previous/next/save chat-history member declarations and changed only complete-object `+0x13eb04` from historical `m_whisperHistoryOther` to `List *m_chatHistory`.
  - Recorded wraparound, empty-result, duplicate suppression, ten-entry cap, SayInputPane/ChatInputPane callers, `g_pUserPane` receiver, and UserPane.cpp source ownership while preserving adjacent recipient-history fields unchanged.

- 2026-07-21 B003 UID0001PK bounded spell-record/access synchronization:
  - Preserved `94/95`, owner/emitter UID0000P1, position 10, complete B001/B002/B004/B005 shared declaration union, all methods/fields, access control, class closure, child marker, and both exact size guards.
  - Replaced only unresolved `SpellCommandSlotRecord::reserved008[0xa0]` with exact `wchar_t displayName[80]` at record `+0x08..+0xa7`; existing `wchar_t prompt[80]` remains at `+0xa8`, and `sizeof(SpellCommandSlotRecord) == 0x148` remains unchanged.
  - Exact algebra `g_pUserPane + 0x13a6ec + 0x148*spellSlot` equals `&m_spellCommandSlots[spellSlot - 1]`; UID0004V9 obtains that pointer and UID0004VB reads `displayName`.
  - Added only forward declaration and bounded private friendship for `WillBeChangedSpellPane`, allowing the source-faithful record access without exposing the table publicly, inventing an out-of-line accessor, or changing layout.
  - The complete managed formal remains the accepted no-loss R18 declaration and preserves `sizeof(UserPane) == 0x13eb84`.

- 2026-07-14 Agent-B005 UID00037V support rebase: documented `m_playerSettingsState[4]` as the blindness level from parser invalidation plus UID0004QY render behavior; historical `oldSpeed` is superseded. The complete B001 class block and all concurrent UserPane content remain unchanged.
- 2026-07-14 Agent-B005 UID00037X callback: rebased the complete class block with `friend class MapPane` and the exact `+0x13eb3e` adjacency flag split, preserving every concurrent declaration, size guard, child marker, and unrelated field.

- 2026-07-13 B004 UID00010X split callback: raised from `88/88` to `89/89` and rebased the complete managed class block with only `struct CollectionPlayerDataView;` plus mutable/const `GetCollectionData()` declarations.
  - Evidence: constructor vector-construction proves 128 records of stride `0x2604` beginning at `+0x3ec8`; the array ends at `+0x1340c8` for `groupCount`, followed by `metadataLoaded`. [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) carries the exact formal layout, and [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) remains the sole `UserPane *g_pUserPane` storage definition.
  - Preservation: every prior virtual, packet callback, access level, `[[CHILDREN]]`, source owner/emitter, broad-handler caveat, singleton lifetime, and unrelated class evidence is unchanged. The accessor introduces no standalone function/global requirement and rejects raw-offset/stride/byte-cast collection source.

- 2026-06-26 B007 accepted [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) support sync:
  - Historical checkpoint: updated then-current `OnAnimationStep` support wording so `0x41645746` / `FWdA` and `0x446e4146` / `FAnD` were resolved LivingObjectPane timer constants while event `0x14` and local fields/helpers still blocked C++. UID0003VD's 2026-07-30 source-quality pass later resolved those blockers and supersedes this state.
  - Preserved class-level C++ blank and child-first emission policy.
- 2026-06-21 Rule 26 support sync from B011 [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md):
  - Added the opcode `0x58` `OnServerMessage` call boundary and recorded that `UserPane` owns only the dispatcher route, not the message-show helper body.
- 2026-06-21 Rule 26 support sync from B008 [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md):
  - Added the `OnClipBounds`/`UpdateScreenPosition` boundary note and preserved [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) as a LivingObjectPane child reached from `MapPane` render through `MapPane+0x418`, not as a UserPane method.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Scores remain `86/86`.
  - Replaced the class-level C++ rationale with the child-first route: the class and [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md) aggregate clear the current owner/emitter gate, but formal C++ should be emitted from exact source-bearing children rather than a broad class aggregate.
  - Added source-facing signatures for `UserPane::UserPane()`, `UserPane::~UserPane()`, `SetLocalPlayerName` / `SetUserPaneNameBuffer`, inventory/spell slot-label builders, `bool OnKeyEvent(...)`, `bool OnServerMessage(...)`, `bool OnAnimationStep(...)`, `OnClipBounds(...)`, `ShowNameLabel()`, `HideNameLabel()`, and `MapPane *GetMapPane()`.
  - Added field/global naming guidance for `g_pUserPane` / `g_pCollectionData`, `g_localPlayerName`, `s_userPanePool`, `m_mapPane`, deferred user-list packet state, name-label timer ticks, and the UserPane-owned list children.
  - Reconfirmed that `LivingObjectPane`, SayInputPanes, Chatting, FunctionObjects, MapPane, BowGaugeObjectPane, UserStatusPane, and compiler switch tables are dependencies or neighbors rather than owners of this class page.
- 2026-06-20 B003 UserPane callback support sync:
  - Scores remain `86/86`.
  - Added the two FunctionObject-bound packet callback methods `UserPane::SendDropItemPacket(signed char,bool)` and `UserPane::SendGiveItemPacket(signed char,bool)` and recorded why they are still `UserPane` methods despite not reading `ecx`.
- 2026-06-22 B014 callback-target verification:
  - Scores remain `86/86`.
  - Added no-direct-call/pointer-immediate evidence for the two future exact packet-helper children and preserved UserPane ownership over free-function or item-action ownership.
- 2026-06-16 B001 retry local event-band child split:
  - Scores remain `86/86`.
  - Added exact child links for [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md)-[UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) and recorded [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md) as a LivingObjectPane exclusion.
  - Evidence: byte-audited `0x005a5b79-0x005a87e0`, checked IDA decompile cache for the four UserPane virtuals, and confirmed the only absolute pointers to the method starts are UserPane vtable slots.
- 2026-06-18 B001 source-quality resolution for [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md):
  - Scores remain `86/86`.
  - Resolved the adjacent virtual accessor as `UserPane::GetMapPane`, returning cached `MapPane *m_mapPane` at `this+0x1340f8`.
  - Evidence: constructor arms copy [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) into `+0x1340f8` and write the inverse `MapPane+0x418 = this`; B001 grouped all 68 known displacement users and confirmed MapPane receiver/helper behavior; the stale `dword` accessor wording is superseded.
- 2026-06-07 Batch050 split-recheck reference cleanup:
  - Before: the cross-reference list pointed only at the broad UserPane/input vtable aggregate.
  - After: the page now also links exact child [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md), matching the corrected `0x0062ef0c-0x006307ec` aggregate boundary.

- 2026-06-07 A005 resolved-name cleanup:
  - Before: UserPane singleton/storage evidence used only historical `dword_67A748`.
  - After: the page recorded canonical `g_pCollectionData` beside the historical label and cross-linked the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IDA-backed evidence already ties the address to UserPane construction, cleanup, and local-player/client state.
- 2026-06-19 B001 accepted `g_pUserPane` implementation:
  - Scores remain `86/86`.
  - Updated singleton/lifetime wording to source-facing `g_pUserPane` while retaining the stable `g_pCollectionData` alias page.
  - Evidence: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) now emits `UserPane *g_pUserPane = 0`, documents 505 exact operand refs, and closes the lifetime write set as constructor/fallback/destructor/clear-helper/scalar-destructor writes only.
- 2026-06-20 B001 [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md) support sync:
  - Added constructor/destructor role detail for `+0x13eb08` outgoing recent-recipient list, `+0x13eb0c` incoming/fallback whisper-sender list, and selector byte `+0x13eb10`.
- 2026-06-20 B003 [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) source-quality sync:
  - Recorded the recipient-history helper names as call dependencies for the direct-message recipient pane while preserving `SayInputPanes` ownership for that class.
- 2026-06-22 B013 [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) neighbor evidence sync:
  - Scores remain `86/86`.
  - Added future exact split candidates for `0x005b7560` and `0x005b75a0` as UserPane nested record constructors, with `0x005b7660` destructor and `0x005ad820` stack-temporary/swap helper evidence.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the broad method map, constructor/destructor evidence, local-user input/message/animation/name-label roles, BowGauge owner-pollution correction, and accessor boundary note; confidence is capped because the broad address neighborhood still contains LivingObjectPane/social-helper ownership caveats and some helper names remain provisional.
- 2026-06-04 live IDA rescore and parent attachment:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:76`, blank reconstructable/parent metadata, older external-lead wording, and only sparse IDA evidence.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P1`.
  - Summary/evidence: live IDA MCP now records the IDB identity, exact function ranges, constructor/name-helper callers, constructor vtable/global setup, destructor cleanup behavior, vtable slots, `dword_67A748` / `g_pCollectionData`, `word_69BEE0`/`byte_69BF34`/BowGauge xrefs, and surrounding `0xcc` padding. Scores stay below final-source quality because large handler field names and adjacent social/movement source ownership still need final layout proof.

## UID0003U6 ProcessMovement Declaration And Layout Synchronization - 2026-07-15

- Metadata remains `92/93`, owner/emitter UID0000P1, reconstructable true, position 10. The accepted complete declaration preserves all unrelated methods, records, fields, inline helpers, `[[CHILDREN]]`, inheritance, and the exact `sizeof(UserPane) == 0x13eb84` guard.
- [UID:0004R0][MapPoint](by-type/by-struct/MapPoint.md) is the shared eight-byte row/column value type. The class declaration forward-declares it and uses it in `GetViewportPosition`; it does not emit an x/y alias union or duplicate type.
- External declarations now cover free MapPane.cpp `DirectionToTileOffset(MapPoint *, unsigned char)` and free Event.cpp `DispatchCopiedEventPayload(const void *, size_t)`. Neither helper is qualified as a UserPane/MapPane member or made file-static.
- `ProcessMovement(unsigned char)`, retained `SendMovementWaypointPacket`, retained `SendFaceDirectionPacket`, animation helpers, and exact packet-handler inventory remain UserPane members. UID0003UX/UID0003UY retain their no-start-xref history while remaining source-bearing declarations.
- The exact threshold fields are `m_viewportHalfColumns` at `+0x13eae0`, `m_viewportHalfRows` at `+0x13eae4`, `m_viewportRemainingColumns` at `+0x13eae8`, and `m_viewportRemainingRows` at `+0x13eaec`. Constructor visible-column/row math and ProcessMovement switch use prove the names without changing layout.
- Movement history remains `LocalMovementHistoryRecord *m_movementHistoryRecords` at `+0x13eb14`, capacity at `+0x13eb18`, write index at `+0x13eb1c`, followed by the preserved deferred-packet/action fields. The 16-byte record retains active, tile Y, tile X, direction, and padding order.
- The authoritative target is [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md). Receiver accesses beyond the `0x20c` LivingObjectPane base prove UserPane ownership; former LivingObjectPane qualification and generic movement-limit fields are historical only.
- Status packet/event source uses inherited `m_objectStatus.m_displayStatusByte`, `MapPane::AllowsMovementStatusTag`, value-first PacketBuffer calls, global `g_pUserPane` effect lists, and [UID:0004QZ][0x004aa050-0x004aa109.DispatchCopiedEventPayload](by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md). No synthetic `m_movementSpeed`, `AllowsMovementStatusFlag`, `SendMovementViewportState`, or hardening guard is declared.

## UID0003U8 StartDirectionalAnimation Contract Synchronization - 2026-07-15

- [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md) is a private source-authored UserPane movement helper. Its entry `movsx` proves the declaration's signed plain-`char` direction ABI; the prior `unsigned char` declaration was inconsistent with the machine contract.
- Exact entry state uses existing class members and inline helpers: `m_isMoving`, `ClearMovementReplyState`, `SetDirectionDelayActive(false)`, and `m_moveFrame`. UID0003VD's size-neutral field refinement names the two reply latches used by that helper without changing any offset or behavior.
- The monster branch uses inherited `m_objectStatus`, `m_animationGroup`, `PlayFacingAnimation`, and `CancelBoxRotationStep`, then reads [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) and schedules `kUserPaneMovementStep` (`20`) through the inherited TimerHandler route.
- The non-monster branch uses inherited `m_objectStatus.m_displayStatusByte` with the signed MapPane-owned `g_movementSubstepScale`. Both branches finish through the existing `MapPane *m_mapPane` field and [UID:0004DS][0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds](by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md).
- UserPane remains the direct owner because the method participates in the local-player movement family and reads UserPane-only `m_mapPane`; LivingObjectPane supplies inherited animation/timer state but does not own this method. The class score, owner/emitter, position, size guard, field layout, other declarations, and `[[CHILDREN]]` inventory remain unchanged.
- Historical `HumanObject`, `g_pObjectImageLib`, `ImageFrameGroup`, unsigned-direction, merged-delay-tail, and LivingObjectPane-owner forms are superseded for this declaration. They remain provenance on the target page and are not parallel class contracts.

## UID0003UM Inventory Slot Record Contract Synchronization - 2026-07-15

- [UID:0003UM][0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket](by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md) proves the exact local inventory record at UserPane `+0x134104`: 52 records, one-based indexing, and exact `0x1fc` / 508-byte stride. The size guard and every unrelated UserPane field/method remain unchanged.
- The three exact 80-wide-character fields are `displayName` at record `+0x006`, `itemMetaKey` at `+0x0a6`, and `ownerName` at `+0x146`. ItemHelpPane consumes the second as its metadata-key fallback input and copies the third to its accepted owner-name member.
- Scalar fields remain `quantityOrCount` at `+0x1e8`, `quantityPromptFlag` at `+0x1ec`, and `targetMode` at `+0x1f8`; target and ItemHelpPane consumer evidence resolves `+0x1f0` as `currentDurability` and `+0x1f4` as dword `protectionCount` populated from one packet byte.
- The exact parser writes item id, quantity/count, prompt, current durability, protection count, icon style, active state, display name, metadata key, target mode, and owner name in machine order. It bounds the signed one-based slot with `g_activeUserStatusPane->m_inventorySlotCount`, not CollectionData.
- This synchronization preserves B001's accepted `StartDirectionalAnimation(char direction)` declaration byte-for-byte. The former `secondaryText`, `tertiaryText`, `value1f0`, and `value1f4` names are historical generic placeholders, not parallel fields.
- Class metadata remains `92/93`, canonical owner/emitter [UID:0000P1][UserPane](by-file/UserPane.md), reconstructable true, position 10, with the complete class closure, `[[CHILDREN]]`, inheritance, inline helpers, and `sizeof(UserPane) == 0x13eb84` guard preserved.

## UID0003UL Player-Settings State Synchronization - 2026-07-15

- [UID:0003UL][0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket](by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md) establishes the source-facing meanings of the eight-byte `m_playerSettingsState` array at `UserPane + 0x1340fc` without changing its storage: index 0 is the feature/UI mode flag, index 2 is the viewport-threshold flag, index 3 is the direction setting, index 4 is the blindness setting, index 5 is the chat-display restriction, index 6 is the chat-send restriction, and indices 1 and 7 remain reserved because no stronger semantic names are proven. UID0003UL writes indices 0 and 2 on every call and writes indices 3 through 6 only when packet flag `0x08` is set.
- The separate five-byte `m_movementState` array remains at `UserPane + 0x13eaf0`: UID0003UL and the corrected UID0003UP/UID0003UQ reply branches read pending-reply index 3 at `+0x13eaf3`, while the established `IsDirectionDelayActive()` helper reads direction-delay index 4 at `+0x13eaf4` for its independent consumers. The arrays do not alias, and this correction introduces no field, layout, or size change.
- Opcode `0x08` now has a complete source-ready UserPane member body: flag-derived state assignment, offset arithmetic, blindness invalidation, movement-state interaction, narrowed UInt32BE option handling, ten direct RegistryConfig stores, SoundManager synchronization, and active child-6 refresh. These behaviors add parser evidence to the existing class surface and do not alter the class declaration or layout.
- The current formal class block continues to preserve B001's signed `StartDirectionalAnimation(char direction)` ABI and B004's `itemMetaKey`, `ownerName`, `currentDurability`, and `protectionCount` inventory fields. No accepted concurrent field, method, inline helper, inheritance, size guard, or `[[CHILDREN]]` entry is removed or renamed.
- Historical statements that treated the accepted opcode-`0x08` body as complete while using an index-4 movement-reply test, generic timer removal, a UInt16BE option read, generic option helper compression, or a MainWindow refresh are superseded by the target-specific callback evidence. Class metadata, score `92/93`, owner/emitter, position, and formal block remain unchanged.

## UID0003V9 HandleKeyOrTextEvent Declaration And Layout Synchronization - 2026-07-15

- Current class metadata is `93/94`, owner/emitter [UID:0000P1][UserPane](by-file/UserPane.md), reconstructable true, position 10. The managed declaration remains one complete `0x13eb84` UserPane class, closes before `[[CHILDREN]]`, and preserves every unrelated declaration, record, inline helper, inherited field use, and size guard.
- [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md) is the exact EventHandler override `virtual bool HandleKeyOrTextEvent(Event *event)`. The accepted mutable `Event *` contract replaces only the superseded `OnKeyEvent(const PaneKeyEvent *)` declaration; it preserves the complete UserPane receiver, bool handled result, EventHandler secondary-facet ABI, and attached compiler switch-table relationship.
- The class now declares exact source dependencies used by that body: `ToggleTargetSelectionPane`, `NavigateTargetSelection`, `ReverseTargetSelectionDirection`, externally linked `g_selectObjectTargetModeActive`, `g_targetObjectTargetModeActive`, and `g_activeSelectObjectWithKeyboardPane`, plus file-local `SendOpcode7Command`. These declarations represent cross-translation-unit calls or UserPane.cpp file-local source as proved; they do not transfer ownership from TargetSelectionInputPanes or create class members.
- Exact source children [UID:0004R7][0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText](by-memory/0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText.md) and [UID:0004R8][0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText](by-memory/0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText.md) are declared as const UserPane members. [UID:0004R3][0x005acf10-0x005acf5f.UserPaneSendOpcode7Command](by-memory/0x005acf10-0x005acf5f.UserPaneSendOpcode7Command.md) remains a UserPane.cpp file-local helper and is not qualified as a member.
- Layout arithmetic is exact and size-neutral. After the signed count at `+0x3cb0`, typed storage is `m_huntersListFlag` at `+0x3cb1`, `m_partySearchSourceText[256]` at `+0x3cb2`, and `m_preCollectionState[2]` at `+0x3eb2`; `int m_currentSayMode` occupies `+0x3eb4`, two unresolved bytes remain at `+0x3eb8`, `bool m_collectionPanelSoundEnabled` occupies `+0x3eba`, and nine unresolved bytes at `+0x3ebb` lead to `m_localPlayerHitRadius` at `+0x3ec4`. At the former eight-byte block `+0x13eafc`, `m_lastMapCommandTick` and `m_lastGroundItemCommandTick` are two distinct unsigned debounce ticks. At `+0x13eb1d`, `bool m_inputLocked` precedes two still-unresolved movement-history bytes. No packed overlay, raw pointer arithmetic, second storage object, or object-size change is introduced.
- The declaration keeps B001's `StartDirectionalAnimation(char direction)`, signed-short MonsterObject frame-duration/table contract and event-20 route; B004 UID0003UM's exact `LocalInventorySlotRecord` names and 508-byte size; B005 UID0003UL's distinct `m_playerSettingsState[8]` plus the size-neutral `m_movementMode`, signed `m_movementReplyCount`, `m_movementReplyReceived`, `m_movementReplyPending`, and `m_directionDelayActive` fields, preserving the former index-3 pending-reply versus index-4 direction-delay distinction; and B004 UID0003UN's `HandleServerEntryPacket` declaration. Current B002-owned [UID:0004R9][0x005adbe0-0x005adc15.UserPaneFindGroupMemberById](by-memory/0x005adbe0-0x005adc15.UserPaneFindGroupMemberById.md) remains an untouched exact child; its broader UID0003UW declaration/layout callback is outside this bounded change.
- The old `HandleKeyEvent`, `OnKeyEvent`, `PaneKeyEvent`, unresolved-field, and blank-target conclusions remain historical provenance only. Exact private lexical spellings are still confidence-capped, but method type, access, field width/order, helper linkage, owner/emitter route, and source shape no longer block human C++.

## 2026-07-15 UID0003UP Reply-Handler Class Synchronization

- This shared-page addition was made only after a post-lease reread of B002's current UID0003H5 report and the live destination. It preserves B002's accepted retained H5 source body, HUZ source call to H5, H5 source call to file-local H4, H4 caller taxonomy, external `g_activeMapPane`, external `s_selectObjectTargetId`, MapPoint row/column semantics, signed-integer quotient, and compiler-inlining disposition.
- It also preserves B001 movement/direction/event contracts, B002 GroupMemberRecord/ParseGroupListPacket/FindGroupMemberById/MapPane/Group facts, B003 Event/target-selection union, B004 inventory/server-entry fields and opcode `0x0f`, B005 settings/movement-state separation, and all unrelated declarations, children, source order, and history.
- Class metadata remains `93/94`; inheritance, complete formal declaration, `[[CHILDREN]]`, all methods/fields, and unrelated current union are byte-for-byte preserved. The existing `HandleMovementReplyPacket(const unsigned char *)` and `HandleExtendedMovementReplyPacket(const unsigned char *)` declarations now have complete exact child definitions.
- UID0003UP/UQ share signed packet words, capability/direct-`Config::m_mapMovementStatusOption` gating, named `m_movementReplyPending` state at the former index 3, 16-byte history records, MapPane correction helpers, and null-safe timer removal, but retain distinct opcode, recenter, event, delay, invalidation, and return paths.
- The two-byte storage at `+0x13eb1e` is split size-neutrally into `m_movementReplyTimerFamily` and `m_movementHistoryEnabled`; reply handlers use only the timer-family byte. No unsupported `m_actionMode` rename or layout shift is introduced.
- Direct Config storage is an arbitrary `unsigned char` at `+0x28de75`. No RegistryConfig cast, raw offset, nested profile, accessor shim, or class-layout change is required.
- Historical LivingObjectPane ownership, blank-formal, unsigned-coordinate, stale MapPoint x/y, generic timer, and provisional source-ready-body claims are retained only as superseded evidence for these two methods.

## 2026-07-15 UID0003UA Configured-Shortcut Declaration Synchronization

- This shared-page rebase was performed after rereading the terminal B005 UID0003UP artifact, terminal B002 UID0003H5 artifact, and the live class page under the short B003 lease. It preserves the complete `93/94` UserPane declaration and `sizeof(UserPane) == 0x13eb84` guard, class closure before `[[CHILDREN]]`, B002's H5/HUZ/H4 declarations and external dependencies, B005's reply-handler/Config/movement-state union, B004's inventory/server-entry fields, B003's Event and target-selection union, and every unrelated method, field, inline helper, route, score, and history entry.
- [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) is the exact retained `UserPane::DispatchConfiguredShortcutHotkey(short hotkeyNumber, int)` source member. The existing declaration remains ABI-correct; the accepted out-of-class definition may leave the second parameter unnamed because the body does not use it.
- The method reads direct base-typed `g_pConfig->m_compactShortcutRecords` storage. Each 0x4-byte row is `wchar_t code`, `unsigned char isSpellMode`, and natural tail alignment. It remaps selector decades to 20 rows, classifies the sign-extended low byte through `_isalpha`, uses full-wchar ASCII range tests, preserves the `0xff` accepted-but-out-of-range fallback, and dispatches to `UseCommandSlot` when `isSpellMode != 0` or `UseInventorySlot` when it is zero.
- UserPane ownership is established by the two existing member callees, the complete class/source-family placement, direct Config state use, and the retained source-era duplicate behavior. Absence of a current modeled function or direct entry route remains liveness/confidence evidence only; it does not make the body a LivingObjectPane member, file-local free helper, compiler artifact, covered-by marker, blank emitter, or no-code item.
- Historical class prose that used `mode`, nested `m_userProfile`, unsigned-char key conversion, unresolved Config declaration, or LivingObjectPane/raw-helper ownership is superseded only for UID0003UA. UID0003UB's separate 30-row macro dispatcher, all movement-reply and action-chain declarations, and all unrelated source-quality blockers remain independently scoped and unchanged.
- Earlier support sections that quote pre-rebase `92/93` class metadata are historical score snapshots. Current class metadata remains `93/94`, canonical owner/emitter UID0000P1, reconstructable true, position 10; this prose synchronization changes no formal declaration bytes or object layout.

## 2026-07-15 UID0003V0 Attack-Target Packet Declaration Synchronization

- This bounded shared-page rebase follows the finalized B002 UID0003H5, executed B003 UID0003UA, and executed B005 UID0003UP unions. It preserves the complete `93/94` declaration, `sizeof(UserPane) == 0x13eb84`, class closure before `[[CHILDREN]]`, `CompactShortcutRecord::isSpellMode`, all movement-reply and auto-face declarations, every field and helper, and all unrelated current and historical evidence.
- [UID:0003V0][0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket](by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md) is the exact source-authored `void UserPane::SendAttackTargetPacket(char direction)` member. The single declaration correction from `unsigned char action` to plain `char direction` follows the target's `movsx` promotion and Hex-Rays plain-char contract; the four live caller constants `0..3` are non-discriminating, explicit `signed char` is the code-generation-equivalent runner-up, and unsigned remains rejected without matching compiler evidence.
- The member returns immediately while inherited `m_isMoving` is nonzero, then uses cached `m_mapPane`, `m_viewportColumn`, and `m_viewportRow` with `MapPane::GetAdjacentVisibleTileBounds` and `MapRect`. It serializes opcode `0x82`, direction, narrowed viewport coordinates, big-endian left/top, unclamped one-byte width/height differences, and the 16-bit bounds checksum through six value-first UInt8 and three value-first UInt16BE calls, writes an unsent local terminator at byte 12, and queues exactly 12 bytes.
- One caller function, [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md), contains four call sites mapping key cases `0x80/0x81/0x82/0x83` to directions `3/0/1/2`. No duplicate member, raw-offset declaration, NxRect/GetAttackTargetRect compatibility shim, packet-writer wrapper, range clamp, compiler cookie, or ABI scaffolding belongs in this class block.

## Historical 2026-07-20 UID000364 Pending-Target State Synchronization

- This section records the accepted R9 evidence-time interpretation before UID00035P constructor/handler correlation disproved its current source role. Its no-loss layout constraints remain valid, but the `ObjectPane`/pending-target names are historical rather than current declarations.
- The accepted R9 declaration was a no-loss rebase of the complete B001/B002/B003/B004/B005 UserPane union at `93/94`, owner/emitter UID0000P1, reconstructable true, position 10, and exact `sizeof(UserPane)==0x13eb84`. Every existing method, record, external, inline helper, field, later offset, child, history section, and class-close-before-children invariant remained present.
- The only layout refinement replaces the opaque twelve-byte span at complete-object `+0x20c..+0x217` with `unsigned char m_userPaneBaseState[4]`, `ObjectPane *m_pendingTargetObject` at `+0x210`, and `unsigned char m_userPaneBaseTail[4]`. This preserves all later offsets and total size without packing or raw-layout source.
- UID000364 writes zero to `g_pUserPane + 0x210`; current Chatting reads the same field as the pending target object, and accepted SpellWho/ItemWho/SelectObject source already uses the source-level clear operation. R9 therefore exposes inline `void ClearPendingTargetObject() { m_pendingTargetObject = NULL; }` and retains `extern UserPane *g_pUserPane`.
- UID000364's exact printable path queues the complete CharInputPane, calls this clear helper, invokes inherited LineInputPane handling, then invokes OnAccept. The field is an `ObjectPane *`, not a Boolean, integer mode, second UserPane object, raw byte array alias, or ownership transfer.
- No UserPane score, source route, owner/emitter, position, method ABI, or unrelated shared behavior changes. Historical opaque-tail statements remain valid evidence-time descriptions only and are superseded for these twelve bytes by the direct read/write consumers.

## 2026-07-20 UID0003TY Deferred-List Cleanup Synchronization

- The complete managed declaration adds only `void ClearDeferredUserListPacket();` in the private UserPane source-helper surface. [UID:0004TX][0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket](by-memory/0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket.md) supplies the exact definition.
- The method operates on the accepted trailing state: `m_deferredUserListPacket` at `+0x13eb20`, `m_deferredUserListPacketSize` at `+0x13eb24`, `m_userListPacketTick` at `+0x13eb28`, `m_userListDeferUntilTick` at `+0x13eb2c`, and `m_skipNextUserListPacket` at `+0x13eb30`.
- Its exact stores free and clear the pointer, packet tick, and defer-until tick. No store clears packet size or the skip-next flag, so the source declaration and documentation preserve those two values. [UID:0003UK][0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket](by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md) remains the distinct copy/allocation helper.
- UID0003TY is the sole recovered caller and supplies `g_pUserPane` as receiver after its crash-report send. That call establishes liveness without moving the method to MapPane or LivingObjectPane.
- Metadata remains the current stronger `94/95`, canonical owner/emitter UID0000P1, reconstructable true, position 10. The complete B001/B002/B003/B004/B005 declaration union, inherited layout, every unrelated method/field/helper, exact `sizeof(UserPane)==0x13eb84`, class closure, and `[[CHILDREN]]` position are preserved.
- Historical broad-reset, raw-offset, merged-copy, compiler-cleanup, and clear-all-five-fields interpretations are rejected. The emitted source contains no null guard, `memset`, size reset, active reset, EH body, or deleting-wrapper body absent from the machine code.

## 2026-08-01 UID0003US User-List State And Retained-Member Synchronization

- The complete declaration preserves `m_deferredUserListPacket` at `+0x13eb20`, `size_t m_deferredUserListPacketSize` at `+0x13eb24`, every neighboring field, and `sizeof(UserPane)==0x13eb84`. Only the three stale trailing-state declarations are source-corrected: `+0x13eb28` is unsigned packet-receipt tick `m_userListPacketTick`, `+0x13eb2c` is unsigned `m_userListDeferUntilTick`, and `+0x13eb30` is boolean one-shot replay guard `m_skipNextUserListPacket`.
- [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) is the exact retained out-of-line `bool UserPane::HandleUserListPacket(const ServerMessageEvent *event)` definition already declared once in this class. The child H remains blank to avoid a duplicate declaration.
- The handler records `g_pTimerMgr->m_currentTick`, applies the `100/300/500/800` entry thresholds and `0/30000/60000/90000/150000` defer schedule, stages medium packets through `CopyDeferredUserListPacket`, performs the largest allocation/copy inline, clears the one-shot guard during cached replay, lazy-creates `UserListDialogPane`, and returns true.
- [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) contains the semantically identical live opcode-`0x36` inline body. The standalone child has zero direct xrefs, but retained source emits through UserPane because exact layout and duplicate-body evidence resolve ownership and source shape; no artificial dispatcher call is introduced.
- The older `m_deferredUserListCount`, `m_deferredUserListDeadline`, `m_deferredUserListActive`, LivingObjectPane ownership, and blank/no-code descriptions remain only as dated rejected assumptions. They must not be reused as current class declarations or field semantics.

## 2026-07-21 UID0002VS GeneralPurposePanel2 Consumer Synchronization

- The complete [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md) audit proves exactly fourteen direct references to the physical singleton backing: five compiler/`Singleton<GeneralPurposePanel2>` lifetime writes and nine runtime reads. Seven of the nine reads belong to UserPane source; the remaining two are MapPane reads at `0x005049ee` and `0x0050fef7`. This class consumes the singleton but does not publish, clear, allocate, delete, or physically own it.
- [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) supplies four exact reads. `0x005a7711` performs the one-time `SwitchActiveChild(0, NULL)` initialization before dispatch. `0x005a792e` selects child zero and forwards decoded text/update data. The opcode-`0x3a` branch at `0x005a7ed5` and opcode-`0x3f` branch at `0x005a7fb9` independently select child zero and dispatch the length-selected empty/text operation.
- The retained raw UserPane source body at `0x005a9130` reads the singleton at `0x005a9143`, obtains child zero through [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md), emits each pending record from UserPane `+0x13a6f4` with mode `1`, and clears the pending state. The separate retained raw source body at `0x005aac10` reads the singleton at `0x005aac2b`, maps code `1..52` to a system-message entry, and sends the selected text through child zero.
- [UID:0003UN][0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket](by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md) supplies the seventh UserPane read at `0x005aacda`; it obtains child zero and invokes the NewSystemMessagePane refresh route. Its accepted source body, score, ownership, and formal C++ remain unchanged.
- The source-facing dependency is external [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md), whose sole zero-initialized definition belongs to `NexusTK/ui/panels/GeneralPurposePanel.cpp`. UserPane retains no duplicate global definition, no raw `dword_69B358`/`DAT_0069b358` name, no explicit Singleton publication/clear, and no ownership transfer. Current class score, metadata, complete managed declaration, layout, methods, history, and every unrelated concurrent B001/B002/B003/B004/B005 fact remain unchanged.
