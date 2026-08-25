// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P1
// Source by-file doc: by-file/UserPane.md
// UID:00030B | by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md | Completion:90 | Confidence:92
unsigned int g_lastFunctionKeyTick;


// UID:0000FQ | by-class/UserPane.md | Completion:94 | Confidence:95
#include "../../util/PoolAllocator.h"
#include "../../social/SayInputPanes.h"
#include "../../social/Chatting.h"

// UID:0002RW | by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md | Completion:90 | Confidence:92
MapPoint *UserPane::GetViewportPosition(MapPoint *outPosition) const
{
    outPosition->row = m_viewportRow;
    outPosition->column = m_viewportColumn;
    return outPosition;
}

// UID:0003U6 | by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md | Completion:92 | Confidence:94
void UserPane::ProcessMovement(unsigned char direction)
{
    if (m_isMoving)
        return;

    const unsigned char directionMode = m_playerSettingsState[3];
    if (directionMode == 1)
    {
        direction = static_cast<unsigned char>(
            (static_cast<signed char>(direction) + 2) % 4);
    }
    else if (directionMode != 0)
    {
        direction = static_cast<unsigned char>(
            g_pTimerMgr->m_currentTick & 3);
    }

    if (direction != m_facing)
    {
        SendDirectionPacket(direction);
        SetFacing(direction);
        return;
    }

    if (m_nameVisible)
        return;

    if (g_useEpfAssets == 1)
    {
        g_activeMapPane->RequestObjectEffect(m_objectId, 201, 0, false);

        EffectInfo effectInfo;
        g_pEffectObjImageLib->GetEffectInfo(&effectInfo, 201);
        UserPane *activeUserPane = g_pUserPane;
        if (activeUserPane != NULL)
        {
            if (effectInfo.secondaryFrameCount > 0 &&
                effectInfo.secondaryRangeStart >= 0 &&
                effectInfo.secondaryRangeEnd >= 0)
            {
                List *effects = activeUserPane->m_secondaryEffectObjectPanes;
                for (int index = effects->GetCount() - 1; index >= 0; --index)
                {
                    EffectObjectPane *effectPane =
                        *static_cast<EffectObjectPane **>(effects->GetElementAt(index));
                    if (effectPane->m_effectId == effectInfo.effectKeyOrId &&
                        effectPane->IsLooping())
                    {
                        delete effectPane;
                        break;
                    }
                }
            }

            if (effectInfo.primaryFrameCount > 0 &&
                effectInfo.primaryRangeStart >= 0 &&
                effectInfo.primaryRangeEnd >= 0)
            {
                List *effects = activeUserPane->m_primaryEffectObjectPanes;
                for (int index = effects->GetCount() - 1; index >= 0; --index)
                {
                    EffectObjectPane *effectPane =
                        *static_cast<EffectObjectPane **>(effects->GetElementAt(index));
                    if (effectPane->m_effectId == effectInfo.effectKeyOrId &&
                        effectPane->IsLooping())
                    {
                        delete effectPane;
                        break;
                    }
                }
            }
        }
    }

    bool sendWaypointPacket = false;
    if (m_playerSettingsState[2] != 0 &&
        m_mapPane->m_mapTransitionState != 0)
    {
        MapRect mapBounds;
        SetRect(&mapBounds, 0, 0,
                m_mapPane->m_mapWidth, m_mapPane->m_mapHeight);

        MapRect visibleBounds;
        m_mapPane->GetVisibleTileBounds(&visibleBounds);
        ++visibleBounds.left;
        ++visibleBounds.top;
        --visibleBounds.right;
        --visibleBounds.bottom;

        MapPoint position;
        GetMapPosition(&position);
        switch (direction)
        {
        case 0:
            sendWaypointPacket =
                visibleBounds.top - 1 >= mapBounds.top &&
                (visibleBounds.bottom > mapBounds.bottom ||
                 mapBounds.bottom - position.row >= m_viewportRemainingRows);
            break;
        case 1:
            sendWaypointPacket =
                visibleBounds.right + 1 <= mapBounds.right &&
                (visibleBounds.left < mapBounds.left ||
                 position.column - mapBounds.left >= m_viewportHalfColumns);
            break;
        case 2:
            sendWaypointPacket =
                visibleBounds.bottom + 1 <= mapBounds.bottom &&
                (visibleBounds.top < mapBounds.top ||
                 position.row - mapBounds.top >= m_viewportHalfRows);
            break;
        case 3:
            sendWaypointPacket =
                visibleBounds.left - 1 >= mapBounds.left &&
                (visibleBounds.right > mapBounds.right ||
                 mapBounds.right - position.column >= m_viewportRemainingColumns);
            break;
        default:
            sendWaypointPacket = false;
            break;
        }
    }
    else
    {
        MapPoint offset;
        DirectionToTileOffset(&offset, direction);

        MapPoint position;
        GetMapPosition(&position);

        MapRect visibleBounds;
        m_mapPane->GetClampedVisibleTileBounds(&visibleBounds);
        InsetRect(&visibleBounds, -1, -1);
        sendWaypointPacket = !PointInRect(
            position.row + offset.row,
            position.column + offset.column,
            &visibleBounds);
    }

    const int movementResult =
        m_mapPane->CheckMovementCollision(m_mapX, m_mapY, direction);
    if (movementResult < 0)
        return;

    if (movementResult == 0)
    {
        unsigned char packet[7];
        packet[0] = 0x69;
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapX), packet + 1);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapY), packet + 3);
        packet[5] = direction;
        packet[6] = 0;
        g_packetSender->QueueAndSendPacket(packet, 6);
        return;
    }

    const bool sendMovementStatus =
        m_mapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_mapMovementStatusOption;

    if (sendWaypointPacket)
    {
        MapRect movementBounds;
        const unsigned short movementToken =
            m_mapPane->GetAdjacentVisibleTileBounds(
                direction, &movementBounds);
        MovementWaypointSegment segment;
        segment.startX = movementBounds.left;
        segment.startY = movementBounds.top;
        segment.endX = movementBounds.right;
        segment.endY = movementBounds.bottom;
        SendMovementWaypointPacket(direction, movementToken, &segment);
        InitializeWalkAnimation(direction);

        if (sendMovementStatus)
        {
            unsigned char payload[12];
            payload[0] = 0x0b;
            payload[1] = static_cast<unsigned char>(direction | 0x80);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_mapX), payload + 2);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_mapY), payload + 4);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_viewportColumn), payload + 6);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_viewportRow), payload + 8);
            payload[10] = 1;
            payload[11] = 0;
            DispatchCopiedEventPayload(payload, 11);
        }
        return;
    }

    SendFaceDirectionPacket(direction);
    StartDirectionalAnimation(direction);
    if (sendMovementStatus)
    {
        unsigned char payload[12];
        payload[0] = 0x26;
        payload[1] = static_cast<unsigned char>(direction | 0x80);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapX), payload + 2);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_mapY), payload + 4);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_viewportColumn), payload + 6);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(m_viewportRow), payload + 8);
        payload[10] = 1;
        payload[11] = 0;
        DispatchCopiedEventPayload(payload, 11);
    }
}

// UID:0003U7 | by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md | Completion:92 | Confidence:94
void UserPane::InitializeWalkAnimation(unsigned char direction)
{
    m_facing = direction;
    ClearMovementReplyState();
    SetDirectionDelayActive(false);
    SetMovingState(true);
    m_moveFrame = 0;
    CancelBoxRotationStep();
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        kLivingTimerForwardStep,
        m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
        direction, 0);
    m_mapPane->UpdateObjectPaneScreenBounds(this);
}

// UID:0003U8 | by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md | Completion:92 | Confidence:94
void UserPane::StartDirectionalAnimation(char direction)
{
    m_isMoving = true;
    ClearMovementReplyState();
    SetDirectionDelayActive(false);
    m_moveFrame = 0;

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        m_animationGroup = direction + 5;
        MonsterImageEntry *entry =
            g_pMonsterImageLib->GetEntryByIndex(
                m_objectStatus.m_appearanceId - 0x8000);
        ImageAnimationGroup *group = entry->GetGroup(m_animationGroup);
        const ImageAnimationFrame *frame = group->GetFrame(m_moveFrame);

        PlayFacingAnimation();
        CancelBoxRotationStep();
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this), kUserPaneMovementStep,
            frame->frameDuration, direction, 0);
        SetMovingState(true);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        return;
    }

    SetMovingState(true);
    m_moveFrame = 0;
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this), kUserPaneMovementStep,
        m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
        direction, 0);
    m_mapPane->UpdateObjectPaneScreenBounds(this);
}

// UID:0003U9 | by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md | Completion:88 | Confidence:91
LocalInventorySlotRecord *UserPane::GetInventorySlotAddress(char inventorySlot)
{
    return &m_inventorySlots[inventorySlot - 1];
}

// UID:0003UA | by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md | Completion:91 | Confidence:93
void UserPane::DispatchConfiguredShortcutHotkey(
    short hotkeyNumber, int)
{
    int shortcutIndex;
    if (hotkeyNumber == 0)
        shortcutIndex = 9;
    else if (hotkeyNumber == 10)
        shortcutIndex = 19;
    else
        shortcutIndex = hotkeyNumber - 1;

    const CompactShortcutRecord &shortcut =
        g_pConfig->m_compactShortcutRecords[shortcutIndex];

    if (!isalpha(static_cast<char>(shortcut.code)))
        return;

    unsigned char slot;
    if (shortcut.code >= L'a' && shortcut.code <= L'z')
        slot = static_cast<unsigned char>(shortcut.code - L'a' + 1);
    else if (shortcut.code >= L'A' && shortcut.code <= L'Z')
        slot = static_cast<unsigned char>(shortcut.code - L'A' + 27);
    else
        slot = 0xff;

    if (shortcut.isSpellMode != 0)
        UseCommandSlot(slot);
    else
        UseInventorySlot(slot);
}


// UID:0001KN | by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md | Completion:92 | Confidence:93
int SendObjectActionPacket(unsigned char action, unsigned int objectId);

void UserPane::UseInventorySlot(unsigned char slot)
{
    if (slot == 0 || slot > 52)
        return;

    LocalInventorySlotRecord *record =
        GetInventorySlotAddress(static_cast<char>(slot));
    if (record == 0 || !record->active)
        return;

    if (record->targetMode == 0)
    {
        SendObjectActionPacket(slot, m_objectId);
        return;
    }

    if (record->targetMode == 1 &&
        g_activeMapPane->m_selectedObjectActive == 1 &&
        g_activeMapPane->m_selectedObjectPane != 0)
    {
        SendObjectActionPacket(
            slot, g_activeMapPane->m_selectedObjectPane->m_objectId);
        return;
    }

    ItemWhoInputPaneState *state =
        static_cast<ItemWhoInputPaneState *>(
            g_pGeneralPurposePanel->GetChildPaneByIndex(3));
    if (state->m_active)
        return;

    new ItemWhoInputPane(slot);

    state = static_cast<ItemWhoInputPaneState *>(
        g_pGeneralPurposePanel->GetChildPaneByIndex(3));
    state->SetInputModeFlag(true);
}

// UID:0004R7 | by-memory/0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText.md | Completion:90 | Confidence:93
void UserPane::BuildInventorySlotRangeText(wchar_t *outText) const
{
    wchar_t *out = outText;
    int runStart = 0;
    const int slotCount = g_activeUserStatusPane->m_inventorySlotCount;

    for (int slot = 1; slot <= slotCount + 1; ++slot)
    {
        const bool active =
            slot <= slotCount && m_inventorySlots[slot - 1].active != 0;
        if (active)
        {
            if (runStart == 0)
            {
                runStart = slot;
                *out++ = slot <= 26
                    ? (wchar_t)(L'a' + slot - 1)
                    : (slot <= 52
                        ? (wchar_t)(L'A' + slot - 27) : L' ');
            }
            continue;
        }

        if (runStart == 0)
            continue;

        const int runEnd = slot - 1;
        if (runEnd - runStart + 1 <= 3)
        {
            for (int item = runStart + 1; item <= runEnd; ++item)
            {
                *out++ = item <= 26
                    ? (wchar_t)(L'a' + item - 1)
                    : (item <= 52
                        ? (wchar_t)(L'A' + item - 27) : L' ');
            }
        }
        else
        {
            *out++ = L'-';
            *out++ = runEnd <= 26
                ? (wchar_t)(L'a' + runEnd - 1)
                : (runEnd <= 52
                    ? (wchar_t)(L'A' + runEnd - 27) : L' ');
        }
        runStart = 0;
    }

    *out = 0;
}

// UID:0004R8 | by-memory/0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText.md | Completion:90 | Confidence:93
void UserPane::BuildSpellSlotRangeText(wchar_t *outText) const
{
    wchar_t *out = outText;
    int runStart = 0;

    for (int slot = 1; slot <= 53; ++slot)
    {
        const bool active =
            slot <= 52 && m_spellCommandSlots[slot - 1].active != 0;
        if (active)
        {
            if (runStart == 0)
            {
                runStart = slot;
                *out++ = slot <= 26
                    ? (wchar_t)(L'a' + slot - 1)
                    : (wchar_t)(L'A' + slot - 27);
            }
            continue;
        }

        if (runStart == 0)
            continue;

        const int runEnd = slot - 1;
        if (runEnd - runStart + 1 <= 3)
        {
            for (int item = runStart + 1; item <= runEnd; ++item)
            {
                *out++ = item <= 26
                    ? (wchar_t)(L'a' + item - 1)
                    : (wchar_t)(L'A' + item - 27);
            }
        }
        else
        {
            *out++ = L'-';
            *out++ = runEnd <= 26
                ? (wchar_t)(L'a' + runEnd - 1)
                : (wchar_t)(L'A' + runEnd - 27);
        }
        runStart = 0;
    }

    *out = 0;
}

// UID:0003UC | by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md | Completion:88 | Confidence:90
void UserPane::UseCommandSlot(unsigned char slot)
{
    if (!m_spellCommandSlotsReady || slot == 0 || slot > 52)
        return;

    SpellCommandSlotRecord *record = GetSpellCommandSlotRecord(slot);
    if (record == 0 || !record->active)
        return;

    switch (record->inputKind)
    {
    case kSpellInputString:
        new SpellStringInputPane(slot);
        return;
    case kSpellInputTarget:
        if (g_activeMapPane != 0 && g_activeMapPane->HasPendingSpellTarget())
        {
            LivingObjectPane *target = g_activeMapPane->GetPendingSpellTarget();
            if (target != 0)
            {
                MapPosition firstPosition;
                MapPosition secondPosition;
                target->GetMapPosition(&firstPosition);
                target->GetMapPosition(&secondPosition);
                SendTargetedActionPacket(
                    slot, target->GetObjectId(),
                    secondPosition.word1, firstPosition.word0);
                return;
            }
        }

        new SpellWhoInputPane(slot);
        {
            LivingObjectPane *target = 0;
            if (g_activeMapPane != 0)
                target = g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
            if (target == 0 || target->GetObjectType() != kObjectTypeLiving ||
                target->IsTargetSuppressed())
                target = g_pUserPane;
            if (target != 0)
            {
                target->SetTargetHighlight(true);
                s_spellWhoTargetId = target->GetObjectId();
            }
        }
        return;
    case kSpellInputFourNumbers:
        new SpellFourArgsInputPane(slot);
        return;
    case kSpellInputThreeNumbers:
        new SpellThreeArgsInputPane(slot);
        return;
    case kSpellInputNone:
        SendImmediateSpellCommand(slot);
        return;
    case kSpellInputTwoNumbers:
        new SpellTwoArgsInputPane(slot);
        return;
    case kSpellInputOneNumber:
        new SpellOneArgInputPane(slot);
        return;
    case kSpellInputSlot:
        new SpellSlotInputPane(slot);
        return;
    default:
        return;
    }
}

// UID:00057A | by-memory/0x005a4ab0-0x005a4c8b.UserPaneWhisperRecipientHistoryHelpers.md | Completion:92 | Confidence:94
void UserPane::GetPreviousRecentRecipientHistory(
    short *historyIndex, wchar_t *recipient, size_t recipientCount)
{
    const int count = m_outgoingWhisperRecipientHistory->GetCount();
    if (count <= 0)
    {
        recipient[0] = L'\0';
        return;
    }

    const int index = *historyIndex == -1
        ? count - 1
        : (count + *historyIndex - 1) % count;
    *historyIndex = static_cast<short>(index);
    wcscpy_s(recipient, recipientCount,
        static_cast<const wchar_t *>(
            m_outgoingWhisperRecipientHistory->GetElementAt(index)));
}

void UserPane::UpdateRecentRecipientList(const wchar_t *recipient)
{
    int foundIndex = -1;
    const int count = m_outgoingWhisperRecipientHistory->GetCount();
    for (int i = 0; i < count; ++i)
    {
        if (wcscmp(static_cast<const wchar_t *>(
                m_outgoingWhisperRecipientHistory->GetElementAt(i)), recipient) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex >= 0)
        m_outgoingWhisperRecipientHistory->RemoveAt(foundIndex, 1);
    else if (count >= 10)
        m_outgoingWhisperRecipientHistory->RemoveAt(0, 1);

    m_outgoingWhisperRecipientHistory->Append(
        1, const_cast<wchar_t *>(recipient));
    m_whisperHistorySource = 1;
}

void UserPane::GetPreviousFallbackRecipientHistory(
    short *historyIndex, wchar_t *recipient, size_t recipientCount)
{
    const int count = m_incomingWhisperSenderHistory->GetCount();
    if (count <= 0)
    {
        recipient[0] = L'\0';
        return;
    }

    const int index = *historyIndex == -1
        ? count - 1
        : (count + *historyIndex - 1) % count;
    *historyIndex = static_cast<short>(index);
    wcscpy_s(recipient, recipientCount,
        static_cast<const wchar_t *>(
            m_incomingWhisperSenderHistory->GetElementAt(index)));
}

// UID:00054G | by-memory/0x005a4de0-0x005a4e3d.UserPaneOpenMixItemDialog.md | Completion:92 | Confidence:94
#include "../dialogs/ItemDialogs.h"

void UserPane::OpenMixItemDialog()
{
    if (g_pMixItemDialog == 0)
        new MixItemDialog();
}

// UID:0002RX | by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md | Completion:90 | Confidence:92
void UserPane::OpenInputPaneForCurrentSayMode()
{
    if (!g_useEpfAssets || g_pChattingHandlePane->m_chatTargetPending)
    {
        OpenDefaultSayInputPane();
        return;
    }

    switch (m_currentSayMode)
    {
    case kSayInputModeDefault:
        OpenDefaultSayInputPane();
        break;

    case kSayInputModeShout:
        OpenShoutInputPane();
        break;

    case kSayInputModeWhisper:
    {
        wchar_t recipientName[64] = L"";

        if (m_outgoingWhisperRecipientHistory->GetCount() > 0)
        {
            const int last = m_outgoingWhisperRecipientHistory->GetCount() - 1;
            wcscpy_s(recipientName, _countof(recipientName),
                static_cast<const wchar_t *>(
                    m_outgoingWhisperRecipientHistory->GetElementAt(last)));
        }

        UpdateRecentRecipientList(recipientName);
        new NewSayToUserMessageInputPane(recipientName);
        break;
    }

    case kSayInputModeGroup:
        new SayToGroupMessageInputPane(L"!!");
        break;

    case kSayInputModeClan:
        new SayToClanMessageInputPane(L"!");
        break;

    default:
        break;
    }
}

// UID:000579 | by-memory/0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners.md | Completion:92 | Confidence:94
void UserPane::OpenDefaultSayInputPane()
{
    m_currentSayMode = kSayInputModeDefault;
    new SayInputPane();
}

void UserPane::OpenSayToUserNameInputPane()
{
    new SayToUserNameInputPane();
}

void UserPane::OpenSayToLastRecipientInputPane()
{
    wchar_t recipientName[64] = L"";
    if (m_outgoingWhisperRecipientHistory->GetCount() > 0)
    {
        const int last = m_outgoingWhisperRecipientHistory->GetCount() - 1;
        wcscpy_s(recipientName, _countof(recipientName),
            static_cast<const wchar_t *>(
                m_outgoingWhisperRecipientHistory->GetElementAt(last)));
    }
    UpdateRecentRecipientList(recipientName);
    new NewSayToUserMessageInputPane(recipientName);
}

void UserPane::OpenSayToGroupMessageInputPane()
{
    new SayToGroupMessageInputPane(L"!!");
}

void UserPane::OpenSayToClanMessageInputPane()
{
    new SayToClanMessageInputPane(L"!");
}

void UserPane::OpenShoutInputPane()
{
    m_currentSayMode = kSayInputModeShout;
    new ShoutInputPane();
}

// UID:0003UD | by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md | Completion:88 | Confidence:90
void UserPane::TryPerformAction()
{
    const unsigned char actionMode = m_actionMode;
    if (actionMode == 3 || actionMode == 1)
        return;

    unsigned int delay = 500;
    if (ClassifyHumanPartFiveBucket(m_objectStatus.m_weaponId) == 3)
        delay = 100;

    const unsigned int currentTick = g_pTimerMgr->m_currentTick;
    if (currentTick - m_lastActionTick <= delay)
        return;

    const int secondaryClass =
        ClassifyHumanPartTwoBucket(m_objectStatus.m_shieldOrArrowId);
    if (actionMode != 0 && secondaryClass != 2)
    {
        SystemMessagePane *pane = g_pChattingViewport;
        pane->m_pendingRefreshByte = 0;
        pane->AppendColoredText(kArrowShortageWarningText, 0x84, 0x24);
        pane->RefreshAndPruneMessages();
        return;
    }

    SendActionPacketWithAutoFace();
    if (actionMode == 1 || actionMode == 2)
        PlayActionAnimationOrEffect(27, 200, 0);
    m_lastActionTick = currentTick;
}

// UID:0003UE | by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md | Completion:88 | Confidence:90
bool UserPane::WarpToPosition(
    int x, int y, int viewportColumn, int viewportRow)
{
    if (!m_mapPane->ValidateMapAndViewportCoords(
            x, y, viewportColumn, viewportRow))
        return false;

    if (m_tileX != x || m_tileY != y)
    {
        MapPoint oldPosition;
        MapPoint newPosition;
        InitMapPoint(&oldPosition, m_tileY, m_tileX);
        InitMapPoint(&newPosition, y, x);
        m_mapPane->ReindexObjectPanePosition(
            this, oldPosition.y, oldPosition.x,
            newPosition.y, newPosition.x);
        m_tileX = x;
        m_tileY = y;
    }

    m_viewportColumn = viewportColumn;
    m_viewportRow = viewportRow;
    CancelTimer(kLivingTimerForwardStep);
    CancelTimer(kUserPaneMovementStep);
    ClearAllEffects();
    m_isMoving = false;
    ClearMovementReplyState();
    SetDirectionDelayActive(false);
    return m_mapPane->InvalidateObject(this);
}


// UID:0003V9 | by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool UserPane::HandleKeyOrTextEvent(Event *event)
{
    if (m_inputLocked)
        return true;
    if (m_mapPane->m_waitingForLocalPlayerStatus)
        return false;
    if (g_pTransferServerDialog != NULL)
        return false;
    if (event->m_type == kEventTextInput)
        return false;

    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    const unsigned char modifiers = event->m_payload.m_key.m_modifiers;

    if (m_nameVisible &&
        key != 0x1b && key != 0x09 && key != 'v' &&
        (m_actionMode != 2 ||
         (key != 0x80 && key != 0x81 &&
          key != 0x82 && key != 0x83)))
    {
        return false;
    }

    if ((modifiers & 3) == 1)
    {
        if (key >= '0' && key <= '9')
        {
            ExecuteHotkeyAction((short)(key - 28));
            return true;
        }

        switch (key)
        {
        case 'c':
            if (g_pChatInputPane == NULL)
                new ChatInputPane(L">");
            return true;

        case 't':
            g_pConfig->m_staticObjectTransparencyEnabled =
                !g_pConfig->m_staticObjectTransparencyEnabled;
            return true;

        case 'x':
            OpenQuitPrompt();
            return true;

        default:
            return false;
        }
    }

    if ((modifiers & 1) == 0 && (modifiers & 2) != 0)
    {
        if (key >= '0' && key <= '9')
        {
            ExecuteHotkeyAction((short)(key - 38));
            return true;
        }

        switch (key)
        {
        case 0x09:
            if (g_pConfig->m_tabVSwap)
                return true;
            if (g_targetObjectTargetModeActive)
                ReverseTargetSelectionDirection();
            else
                NavigateTargetSelection(false, true);
            return true;

        case 'v':
            if (!g_pConfig->m_tabVSwap)
                return true;
            if (g_targetObjectTargetModeActive)
                ReverseTargetSelectionDirection();
            else
                NavigateTargetSelection(false, true);
            return true;

        case ',':
            SendOpcode7Command(3);
            return true;

        case 'w':
        {
            g_gameServerNationTable->RequestNationEntries();
            if (m_userListDeferUntilTick >= g_pTimerMgr->m_currentTick)
            {
                m_skipNextUserListPacket = true;
                DispatchCopiedEventPayload(
                    m_deferredUserListPacket,
                    m_deferredUserListPacketSize);
            }
            else
            {
                unsigned char packet[2] = { 0x18, 0 };
                g_packetSender->QueueAndSendPacket(packet, 1);
            }
            return true;
        }

        case 0x80:
            SendAttackTargetPacket(3);
            return true;
        case 0x81:
            SendAttackTargetPacket(0);
            return true;
        case 0x82:
            SendAttackTargetPacket(1);
            return true;
        case 0x83:
            SendAttackTargetPacket(2);
            return true;

        default:
            return false;
        }
    }

    if ((modifiers & 3) != 0)
        return false;

    switch (key)
    {
    case 0x09:
    case 0x0d:
        if (!g_pConfig->m_sayWithEnter)
            return true;
        m_currentSayMode = 0;
        OpenDefaultSayPane();
        return true;

    case 0x1b:
        if (m_nameVisible)
        {
            SendMovementPacket(1);
            return false;
        }
        if (!m_mapPane->m_selectedObjectActive)
            return false;
        m_mapPane->m_selectedObjectActive = false;
        if (m_mapPane->m_selectedObjectPane != NULL)
            m_mapPane->m_selectedObjectPane->SetTargetHighlight(false);
        m_mapPane->m_selectedObjectPane = NULL;
        m_mapPane->m_selectedObjectDirection = -1;
        g_selectObjectTargetModeActive = false;
        g_targetObjectTargetModeActive = false;
        return true;

    case 0x20:
        if (m_actionMode == 0 ||
            g_pTimerMgr->m_currentTick - m_lastActionTick <= 100 ||
            m_actionMode != 1 ||
            g_activeSelectObjectWithKeyboardPane != NULL ||
            m_mapPane->m_selectedObjectActive)
        {
            TryPerformAction();
        }
        else
        {
            new SelectObjectWithKeyboardPane();
        }
        return true;

    case '!':
        m_currentSayMode = 1;
        CreateShoutInputPane();
        return true;

    case '"':
        m_currentSayMode = 2;
        new SayToUserNameInputPane();
        return true;

    case '\'':
        OpenInputPaneForCurrentSayMode();
        return true;

    case '*':
        return true;

    case '+':
        g_pGeneralPurposePanel->SwitchActiveTab(3, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;

    case ',':
        if (g_pTimerMgr->m_currentTick - m_lastGroundItemCommandTick > 1000)
        {
            unsigned char packet[3] = { 7, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 2);
            m_lastGroundItemCommandTick = g_pTimerMgr->m_currentTick;
        }
        return true;

    case '/':
        m_currentSayMode = 0;
        new SayInputPane(L"/");
        return true;

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        ExecuteHotkeyAction((short)(key - '0'));
        return true;

    case ':':
        new EmotionInputPane();
        return true;

    case ';':
    {
        unsigned char packet[2] = { 9, 0 };
        g_packetSender->QueueAndSendPacket(packet, 1);
        return true;
    }

    case '<':
        SendOpcode7Command(1);
        return true;

    case 'C':
        new ChangeSpellSlotInputPane(
                g_pLanguageMan->GetLocalizedString(45));
        return true;

    case 'D':
    {
        DropAllInputPane *pane = new DropAllInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(8), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'E':
        if (g_pGeneralPurposePanel->m_activeChildIndex == 1)
        {
            unsigned char packet[5] = { 27, 1, 8, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 4);
        }
        else
        {
            ((SelfLookPane *)g_pGeneralPurposePanel->GetActiveChildPane())
                ->SendToggleLook();
        }
        return true;

    case 'F':
    {
        unsigned char packet[5] = { 27, 1, 10, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 'G':
        if (g_pGeneralPurposePanel->m_activeChildIndex == 1)
        {
            unsigned char packet[5] = { 27, 1, 2, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 4);
        }
        else
        {
            ((SelfLookPane *)g_pGeneralPurposePanel->GetActiveChildPane())
                ->SendToggleEquip();
        }
        return true;

    case 'H':
    {
        GiveAllInputPane *pane = new GiveAllInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(44), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'I':
        if (g_pMixItemDialog == NULL)
            new MixItemDialog();
        return true;

    case 'M':
        if (g_pBulletinSession == NULL)
            new BulletinSession(1, 0, true);
        return true;

    case 'P':
        if (!m_playerSettingsState[0])
            return true;
        {
            unsigned char packet[8] = {
                76, 1, 4,
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[0],
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[1],
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[2],
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[3],
                0
            };
            g_packetSender->QueueAndSendPacket(packet, 7);
        }
        return true;

    case 'Q':
        OpenQuitPrompt();
        return true;

    case 'R':
        g_pConfig->m_clickLookEnabled = !g_pConfig->m_clickLookEnabled;
        g_pChattingViewport->AppendColoredText(
            g_pConfig->m_clickLookEnabled
                ? L"Right click look :ON" : L"Right click look :OFF",
            132, 36);
        return true;

    case 'T':
        new TakeOffInputPane();
        return true;

    case 'V':
    case 'v':
        if (m_nameVisible)
        {
            SendMovementPacket(1);
            return false;
        }
        ToggleTargetSelectionPane((modifiers & 4) != 0);
        return true;

    case 'W':
    {
        WearInputPane *pane = new WearInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(33), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'Z':
        if (m_spellCommandSlotsReady)
        {
            SpellSpellInputPane *pane = new SpellSpellInputPane(0);
            wchar_t slots[36];
            wchar_t prompt[128];
            BuildSpellSlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(36), slots);
            pane->SetPrompt(prompt);
        }
        return true;

    case 'b':
        EnsureNormalBulletinSession();
        return true;

    case 'c':
        new ChangeItemSlotInputPane(
                g_pLanguageMan->GetLocalizedString(46));
        return true;

    case 'd':
    {
        DropInputPane *pane = new DropInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(6), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'e':
    {
        EatInputPane *pane = new EatInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(12), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'f':
        g_pGeneralPurposePanel->SwitchActiveTab(4, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;

    case 'g':
            new GroupInputPane(g_pLanguageMan->GetLocalizedString(47));
        return true;

    case 'h':
    {
        GiveInputPane *pane = new GiveInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(42), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'i':
        g_pGeneralPurposePanel->SwitchActiveTab(2, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;

    case 'm':
        if (g_pMiniMapDialog != NULL)
        {
            g_pMiniMapDialog->Show(1);
        }
        else
        {
            m_mapPane->GetCurrentMapId();
            unsigned char packet[2] = { 124, 0 };
            g_packetSender->QueueAndSendPacket(packet, 1);
        }
        return true;

    case 'o':
        if (g_pTimerMgr->m_currentTick - m_lastMapCommandTick > 1000)
        {
            unsigned char packet[2] = { 32, 0 };
            g_packetSender->QueueAndSendPacket(packet, 1);
            m_lastMapCommandTick = g_pTimerMgr->m_currentTick;
        }
        return true;

    case 'p':
    {
        PostInputPane *pane = new PostInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(11), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'r':
    {
        unsigned char packet[5] = { 27, 1, 0, 1, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 's':
    {
        unsigned char packet[3] = { 45, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 2);
        if (g_useEpfAssets)
            g_epfLocalPlayerStatusRequestTime = event->m_payload.m_key.m_messageTime;
        else
            g_legacyLocalPlayerStatusRequestTime = event->m_payload.m_key.m_messageTime;
        return true;
    }

    case 't':
    {
        ThrowInputPane *pane = new ThrowInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(35), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'u':
    {
        UseInputPane *pane = new UseInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
            swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(9), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'w':
        new WieldInputPane();
        return true;

    case 'z':
        if (m_collectionData.metadataLoaded)
        {
            if (m_collectionPanelSoundEnabled)
                g_pSoundManager->PlaySoundEffect(0x198, 100);
            g_pGeneralPurposePanel->SwitchActiveTab(5, NULL);
        }
        else
        {
            unsigned char packet[4] = { 39, 0, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 3);
        }
        return true;

    case 0x80:
        ProcessMovement(3);
        return true;
    case 0x81:
        ProcessMovement(0);
        return true;
    case 0x82:
        ProcessMovement(1);
        return true;
    case 0x83:
        ProcessMovement(2);
        return true;

    case 0x85:
        if (((modifiers & 4) != 0) == g_pConfig->m_f1Swap)
        {
            if (g_pActiveBrowserWindow == NULL)
                new BrowserDialog(0, L"help.nexustk.com/wiki", 900, 650);
        }
        else
        {
            SendOpcode43MinusOneRequest();
        }
        return true;

    case 0x86:
    {
        unsigned char packet[11] = {
            67, 1, 0xff, 0xff, 0xff, 0xfe,
            0, 0, 0, 4, 0
        };
        g_packetSender->QueueAndSendPacket(packet, 10);
        return true;
    }

    case 0x87:
        new FriendListDialog();
        return true;

    case 0x88:
    {
        unsigned char packet[5] = { 27, 1, 7, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 0x89:
    {
        unsigned char packet[5] = { 27, 1, 1, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 0x8a:
    {
        unsigned char packet[5] = { 27, 1, 3, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 0x8b:
        if (g_pSoundManager->IsSoundEffectsEnabled())
        {
            g_pSoundManager->DisableSoundEffects();
            g_pSoundManager->MuteMusic();
        }
        else
        {
            g_pSoundManager->EnableSoundEffects();
            g_pSoundManager->UnmuteMusic();
        }
        return true;

    case 0x8c:
        new MusicControlDialog();
        return true;

    case 0x8d:
        if ((modifiers & 4) != 0)
        {
            if (g_pFittingRoomDialog == NULL)
                new FittingRoomDialog();
        }
        else
        {
            new BlockListenInputPane();
        }
        return true;

    case 0x8e:
        if ((modifiers & 4) != 0)
        {
            g_pConfig->m_showDamage = !g_pConfig->m_showDamage;
            g_pChattingViewport->AppendColoredText(
                g_pConfig->m_showDamage
                    ? L"Show Damage      :ON" : L"Show Damage      :OFF",
                132, 36);
        }
        else
        {
            g_pGeneralPurposePanel->SwitchActiveTab(6, NULL);
            g_pSoundManager->PlaySoundEffect(0x198, 100);
        }
        return true;

    case 0x8f:
        if ((modifiers & 4) != 0)
        {
            g_pConfig->m_tabVSwap = !g_pConfig->m_tabVSwap;
            g_pChattingViewport->AppendColoredText(
                g_pConfig->m_tabVSwap
                    ? L"Tab V Swap       :ON" : L"Tab V Swap       :OFF",
                132, 36);
        }
        else
        {
            new IntegrateMacroDialog();
        }
        return true;

    case 0x90:
        if ((modifiers & 4) != 0)
        {
            g_pConfig->m_clickMoveEnabled = !g_pConfig->m_clickMoveEnabled;
            g_pChattingViewport->AppendColoredText(
                g_pConfig->m_clickMoveEnabled
                    ? L"Click to move    :ON" : L"Click to move    :OFF",
                132, 36);
        }
        else
        {
            g_pConfig->m_mapMovementStatusOption =
                !g_pConfig->m_mapMovementStatusOption;
            unsigned char packet[4] = { 27, 1, 9, 0 };
            g_packetSender->QueueAndSendPacket(packet, 3);
        }
        return true;

    case 0x92:
        g_pSoundManager->m_advanceTrackRequested = true;
        if (g_pConfig->m_musicSourceMode == 1)
            g_pSoundManager->PlayNextTrack();
        else if (g_pConfig->m_musicSourceMode == 2)
            g_pSoundManager->AdvanceRedbookTrack();
        return false;

    default:
        return false;
    }
}

// UID:0003VB | by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md | Completion:87 | Confidence:89
// No whole-method reconstruction is currently entered for
// UserPane::OnServerMessage. Current IDA MCP evidence proves this is the
// live UserPane vtable dispatcher at 0x005a76c0 with a 128-case packet
// switch, event payload pointer/size at event +0x0c/+0x10, inline opcode
// 0x04 and 0x36 bodies, and delegated packet helpers for resolved cases.
// The remaining packet cases and payload-local field names are not
// source-quality enough for a behavior-complete formal C++ body without
// freezing decompiler-shaped offsets or inventing helper calls.

// UID:0003VD | by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md | Completion:94 | Confidence:94
bool UserPane::OnTimer(int timerId, int arg0, int arg1)
{
    switch (timerId)
    {
    case kUserPaneMovementStep:
        {
            int direction = arg0;
            const int movementFrameCount = 4 * g_movementSubstepScale;

            m_movementTimerHandled = true;

            if (IsDirectionDelayActive())
            {
                m_moveFrame = static_cast<signed char>(
                    (movementFrameCount + m_moveFrame - 1) %
                    movementFrameCount);
                direction = RemapMovementDirectionForMapScroll(
                    static_cast<unsigned char>(direction));
            }
            else
            {
                m_moveFrame = static_cast<signed char>(
                    (m_moveFrame + 1) % movementFrameCount);
            }

            if (m_moveFrame == 0)
            {
                m_isMoving = false;
                ScheduleBoxRotationStep();
            }
            else if (!IsDirectionDelayActive() &&
                     m_moveFrame >= 2 &&
                     !m_movementReplyReceived)
            {
                if (m_moveFrame == 2)
                {
                    m_movementReplyPending = true;
                    m_movementReplyTimerFamily = 0;
                }
            }
            else
            {
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kUserPaneMovementStep,
                    m_objectStatus.m_displayStatusByte /
                        g_movementSubstepScale,
                    direction,
                    0);
            }

            if (m_isMoving)
            {
                PropagateLinkedObjectMode(direction);
            }
            else
            {
                if (!IsDirectionDelayActive())
                {
                    MapPoint offset;
                    DirectionToTileOffset(&offset, m_facing);
                    WarpToPosition(
                        m_mapX + offset.column,
                        m_mapY + offset.row,
                        m_viewportColumn + offset.column,
                        m_viewportRow + offset.row);
                }

                PropagateLinkedObjectMode(direction);
                SyncPositionToLinkedObjects();
            }

            if (!IsDirectionDelayActive() &&
                !m_isMoving &&
                --m_movementReplyCount > 0)
            {
                StartDirectionalAnimation(
                    static_cast<char>(direction));
                m_movementReplyReceived = true;
            }

            return true;
        }

    case kLivingTimerForwardStep:
        {
            int direction = arg0;
            const unsigned char originalDirection =
                static_cast<unsigned char>(direction);
            const int movementFrameCount = 4 * g_movementSubstepScale;

            m_movementTimerHandled = true;

            if (IsDirectionDelayActive())
            {
                m_moveFrame = static_cast<signed char>(
                    (movementFrameCount + m_moveFrame - 1) %
                    movementFrameCount);
                direction = RemapMovementDirectionForMapScroll(
                    static_cast<unsigned char>(direction));
            }
            else
            {
                m_moveFrame = static_cast<signed char>(
                    (m_moveFrame + 1) % movementFrameCount);
            }

            if (m_moveFrame == 0)
            {
                m_isMoving = false;
                ScheduleBoxRotationStep();
            }
            else if (!IsDirectionDelayActive() &&
                     m_moveFrame >= 2 &&
                     !m_movementReplyReceived)
            {
                if (m_moveFrame == 2)
                {
                    m_movementReplyPending = true;
                    m_movementReplyTimerFamily = 1;
                }
            }
            else
            {
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kLivingTimerForwardStep,
                    m_objectStatus.m_displayStatusByte /
                        g_movementSubstepScale,
                    direction,
                    0);
            }

            if (m_isMoving)
            {
                PropagateLinkedObjectMode(direction);
                m_mapPane->ApplyMovementSubstepScroll(
                    RemapMovementDirectionForMapScroll(
                        static_cast<unsigned char>(direction)));
            }
            else
            {
                if (!IsDirectionDelayActive())
                {
                    PropagateLinkedObjectMode(direction);

                    MapPoint offset;
                    DirectionToTileOffset(&offset, m_facing);
                    WarpToPosition(
                        m_mapX + offset.column,
                        m_mapY + offset.row,
                        m_viewportColumn,
                        m_viewportRow);

                    m_mapPane->ApplyMovementSubstepScroll(
                        RemapMovementDirectionForMapScroll(
                            static_cast<unsigned char>(direction)));
                    m_mapPane->ScrollViewportByDirection(
                        originalDirection);
                }

                SyncPositionToLinkedObjects();
            }

            if (!IsDirectionDelayActive() &&
                !m_isMoving &&
                --m_movementReplyCount > 0)
            {
                InitializeWalkAnimation(
                    static_cast<unsigned char>(direction));
                m_movementReplyReceived = true;
            }

            return true;
        }

    case kLivingTimerFrameAnimation:
        return LivingObjectPane::OnTimer(
            kLivingTimerFrameAnimation, arg0, arg1);

    default:
        return LivingObjectPane::OnTimer(timerId, arg0, arg1);
    }
}

// UID:0003VE | by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md | Completion:87 | Confidence:89
LocalMovementHistoryRecord *UserPane::GetActiveMovementHistoryRecordByIndex(
    unsigned char recordIndex)
{
    if (recordIndex >= m_movementHistoryCapacity)
        return 0;
    LocalMovementHistoryRecord *record =
        &m_movementHistoryRecords[recordIndex];
    return record->active != 0 ? record : 0;
}

// UID:0003UF | by-memory/0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords.md | Completion:88 | Confidence:90
void UserPane::ClearAllMovementHistoryRecords()
{
    for (int index = 0; index < m_movementHistoryCapacity; ++index)
        m_movementHistoryRecords[index].active = 0;
}

// UID:0003UG | by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md | Completion:90 | Confidence:92
void UserPane::ClearMovementHistoryRecordByIndex(int recordIndex)
{
    if (recordIndex >= 0 && recordIndex < m_movementHistoryCapacity)
        m_movementHistoryRecords[recordIndex].active = 0;
}

// UID:0003UH | by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md | Completion:88 | Confidence:90
void UserPane::UpdateScreenPosition()
{
    MapCoordinatePair screenPos;
    GetMapPosition(&screenPos);
    m_mapPane->MapToScreenCoords(&screenPos);

    MapCoordinatePair stepOffset;
    m_mapPane->DirectionToTileOffset(&stepOffset, m_facing);
    ScaleDirectionOffsetToPixels(&stepOffset);

    const int divisor = 4 * g_movementSubstepScale;
    const int screenX = screenPos.x +
        (m_moveFrame * stepOffset.x) / divisor + g_mapTilePixelWidth / 2;
    const int screenY = screenPos.y +
        (m_moveFrame * stepOffset.y) / divisor + g_mapTilePixelHeight / 2;
    m_screenX = screenX;
    m_screenY = screenY;

    InitRectBounds(
        &m_screenHitBounds,
        screenX - m_localPlayerHitRadius,
        screenY - m_localPlayerHitRadius,
        screenX + m_localPlayerHitRadius,
        screenY + m_localPlayerHitRadius);
    InitRectBounds(
        &m_screenLowerHitBounds,
        screenX - m_localPlayerHitRadius,
        screenY,
        screenX + m_localPlayerHitRadius,
        screenY + m_localPlayerHitRadius);
}

// UID:0004TX | by-memory/0x005a89d0-0x005a8a01.UserPaneClearDeferredUserListPacket.md | Completion:92 | Confidence:94
void UserPane::ClearDeferredUserListPacket()
{
    free(m_deferredUserListPacket);
    m_deferredUserListPacket = NULL;
    m_userListPacketTick = 0;
    m_userListDeferUntilTick = 0;
}

// UID:0003UI | by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md | Completion:90 | Confidence:92
void UserPane::SendMovementPacket(unsigned char direction)
{
    m_lastMovementInputTick = g_pTimerMgr->m_currentTick;
    std::vector<unsigned int> objectIds;
    g_pActiveMapPane->CollectMovementTargetObjectIds(objectIds);
    g_pActiveMapPane->SortMovementTargetObjectIdsByDistance(objectIds);

    unsigned char packet[60];
    unsigned int packetSize = 0;
    packet[packetSize++] = 0x13;
    if (direction != 0 || objectIds.empty())
    {
        packet[packetSize++] = 4;
    }
    else
    {
        packet[packetSize++] =
            static_cast<unsigned char>(2 + (m_actionMode == 2));
        unsigned int elapsed =
            (m_lastMovementInputTick - m_lastMovementSendTick) / 125;
        if (elapsed > 40)
            elapsed = 40;
        packet[packetSize++] = static_cast<unsigned char>(elapsed);
        packet[packetSize++] = static_cast<unsigned char>(objectIds.size());
        for (std::vector<unsigned int>::size_type index = 0;
             index < objectIds.size() && index < 9; ++index)
        {
            PacketBufferWriteUInt32BE(objectIds[index], packet + packetSize);
            packetSize += 4;
        }
    }

    packet[packetSize] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetSize));
}

// UID:0004SL | by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md | Completion:91 | Confidence:93
void UserPane::AdvanceMovementSendTick()
{
    m_lastMovementSendTick += 1000;
    if (m_lastMovementSendTick >= g_pTimerMgr->m_currentTick)
        m_lastMovementSendTick = g_pTimerMgr->m_currentTick - 1;

    g_pBowGaugeObjectPane->SetAnimationStartTick(
        m_lastMovementSendTick);
}

// UID:0003UJ | by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md | Completion:92 | Confidence:93
void UserPane::TryDispatchFunctionKeyShortcut(
    short functionKeyOrdinal, unsigned int currentTick)
{
    if (currentTick - g_lastFunctionKeyTick <= 100 &&
        currentTick >= g_lastFunctionKeyTick)
        return;

    int shortcutIndex;
    if (functionKeyOrdinal == 0)
        shortcutIndex = 9;
    else
        shortcutIndex = functionKeyOrdinal - 1;

    const wchar_t key =
        g_pConfig->m_legacyShortcutText[shortcutIndex][0];
    if (!isalpha(static_cast<char>(key)))
        return;

    unsigned char slot;
    if (key >= L'a' && key <= L'z')
        slot = static_cast<unsigned char>(key - L'a' + 1);
    else if (key >= L'A' && key <= L'Z')
        slot = static_cast<unsigned char>(key - L'A' + 27);
    else
        slot = 0xff;

    UseCommandSlot(slot);
}

// UID:0003UK | by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md | Completion:88 | Confidence:90
void UserPane::CopyDeferredUserListPacket(
    const unsigned char *packetData, size_t packetSize)
{
    free(m_deferredUserListPacket);
    m_deferredUserListPacket =
        static_cast<unsigned char *>(malloc(packetSize));
    m_deferredUserListPacketSize = packetSize;
    memmove(m_deferredUserListPacket, packetData, packetSize);
}

// UID:0003UL | by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md | Completion:92 | Confidence:94
bool UserPane::ParsePlayerSettingsPacket(const unsigned char *packet)
{
    enum PlayerSettingsStateIndex
    {
        kPlayerFeatureMode = 0,
        kUseViewportMovementThresholds = 2,
        kDirectionMode = 3,
        kBlindnessLevel = 4,
        kChatDisplayRestrictionLevel = 5,
        kChatSendRestrictionLevel = 6
    };

    const unsigned char flags = packet[1];
    m_playerSettingsState[kPlayerFeatureMode] =
        static_cast<unsigned char>(flags >> 7);
    if (flags & 0x04)
        m_actionGateState = 3;
    m_playerSettingsState[kUseViewportMovementThresholds] =
        (flags & 0x02) == 0;

    unsigned int offset = (flags & 0x40) ? 31 : 2;
    if (flags & 0x20)
        offset += 8;
    if (flags & 0x10)
        offset += 9;
    if (flags & 0x08)
    {
        const unsigned char oldBlindnessLevel =
            m_playerSettingsState[kBlindnessLevel];
        m_playerSettingsState[kDirectionMode] = packet[offset++];
        m_playerSettingsState[kBlindnessLevel] = packet[offset++];
        m_playerSettingsState[kChatDisplayRestrictionLevel] = packet[offset++];
        m_playerSettingsState[kChatSendRestrictionLevel] = packet[offset++];
        ++offset;
        if (oldBlindnessLevel !=
            m_playerSettingsState[kBlindnessLevel])
        {
            RectBounds bounds;
            m_mapPane->GetBounds(&bounds);
            m_mapPane->InvalidateRect(&bounds);
        }
    }

    g_pConfig->m_mapMovementStatusOption = packet[++offset];
    if (g_pConfig->m_mapMovementStatusOption &&
        m_movementState[3] != 0)
    {
        TryStepForward();
        m_movementState[3] = 0;
        m_isMoving = false;
    }

    const unsigned short options = static_cast<unsigned short>(
        PacketBufferReadUInt32BE(packet + offset + 1));
    g_pConfig->m_whisperEnabled = (options & 0x0001) != 0;
    g_pConfig->m_shoutEnabled = (options & 0x0004) != 0;
    g_pConfig->m_adviceEnabled = (options & 0x0008) != 0;
    g_pConfig->m_magicEnabled = (options & 0x0010) != 0;
    g_pConfig->m_weatherEnabled = (options & 0x0020) != 0;
    g_pConfig->m_fixedMovementEnabled = (options & 0x0040) != 0;
    g_pConfig->m_mapMovementStatusOption = (options & 0x0100) != 0;
    g_pConfig->m_soundEffectsEnabled = (options & 0x1000) != 0;
    g_pConfig->m_selfLookTopButtonSelected =
        (options & 0x2000) != 0;
    g_pConfig->m_selfLookBottomButtonSelected =
        (options & 0x4000) != 0;

    if (g_pConfig->m_soundEffectsEnabled)
    {
        g_pSoundManager->EnableSoundEffects();
        g_pSoundManager->m_soundEffectsOptionEnabled = true;
    }
    else
    {
        g_pSoundManager->DisableSoundEffects();
        g_pSoundManager->m_soundEffectsOptionEnabled = false;
    }

    if (g_pGeneralPurposePanel->m_activeChildIndex == 6)
        g_pGeneralPurposePanel->GetChildPaneByIndex(6)->OnActivate(NULL);
    return false;
}

// UID:0003UM | by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md | Completion:92 | Confidence:94
bool UserPane::ParseInventorySlotUpdatePacket(const unsigned char *packet)
{
    MemoryMan *memoryMan = GetMemoryMan();
    size_t offset = 1;
    const char inventorySlot = static_cast<char>(packet[offset++]);
    const unsigned short itemId = PacketBufferReadUInt16BE(packet + offset);
    offset += 2;
    const unsigned char iconStyle = packet[offset++];

    char narrowText[256];
    wchar_t displayName[256];
    unsigned char textLength = packet[offset++];
    memoryMan->MemmoveWrapper(narrowText, packet + offset, textLength);
    offset += textLength;
    narrowText[textLength] = '\0';
    unsigned char convertedLength = static_cast<unsigned char>(
        MultiByteToWideChar(0, 0, narrowText, textLength,
                            displayName, 256));
    displayName[convertedLength] = L'\0';

    wchar_t itemMetaKey[256];
    textLength = packet[offset++];
    memoryMan->MemmoveWrapper(narrowText, packet + offset, textLength);
    offset += textLength;
    narrowText[textLength] = '\0';
    convertedLength = static_cast<unsigned char>(
        MultiByteToWideChar(0, 0, narrowText, textLength,
                            itemMetaKey, 256));
    itemMetaKey[convertedLength] = L'\0';

    const unsigned int quantityOrCount =
        PacketBufferReadUInt32BE(packet, &offset);
    const bool quantityPromptFlag =
        PacketBufferReadUInt8(packet, &offset) != 0;
    const unsigned int currentDurability =
        PacketBufferReadUInt32BE(packet, &offset);
    const unsigned int protectionCount =
        PacketBufferReadUInt8(packet, &offset);

    wchar_t ownerName[256];
    textLength = packet[offset++];
    memoryMan->MemmoveWrapper(narrowText, packet + offset, textLength);
    offset += textLength;
    narrowText[textLength] = '\0';
    convertedLength = static_cast<unsigned char>(
        MultiByteToWideChar(0, 0, narrowText, textLength,
                            ownerName, 256));
    ownerName[convertedLength] = L'\0';

    const bool targetMode = PacketBufferReadUInt8(packet, &offset) != 0;

    if (inventorySlot > 0 &&
        inventorySlot <= g_activeUserStatusPane->m_inventorySlotCount)
    {
        LocalInventorySlotRecord &record =
            m_inventorySlots[inventorySlot - 1];
        record.itemId = itemId;
        record.quantityOrCount = quantityOrCount;
        record.quantityPromptFlag = quantityPromptFlag ? 1 : 0;
        record.currentDurability = currentDurability;
        record.protectionCount = protectionCount;
        record.iconStyle = iconStyle;
        record.active = 1;
        wcscpy_s(record.displayName, 80, displayName);
        wcscpy_s(record.itemMetaKey, 80, itemMetaKey);
        record.targetMode = targetMode ? 1 : 0;
        wcscpy_s(record.ownerName, 80, ownerName);
    }

    return false;
}

// UID:0003UN | by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md | Completion:92 | Confidence:94
#include "../core/BlackHole.h"

bool UserPane::HandleServerEntryPacket(const unsigned char *packet)
{
    if (g_useEpfAssets == 1)
    {
        SelfLookPane *selfLookPane = static_cast<SelfLookPane *>(
            g_pGeneralPurposePanel->GetChildPaneByIndex(0));
        selfLookPane->RefreshSpelledPane();

        NewSystemMessagePane *systemMessagePane =
            static_cast<NewSystemMessagePane *>(
                g_pGeneralPurposePanel2->GetChildPaneByIndex(0));
        systemMessagePane->RefreshSpelledPane();

        g_packetSender->SetSendDisabled(false);
        if (g_pTransferServerDialog != 0)
        {
            g_pTransferServerDialog->ResetOpacityAndRepaint();
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(
                g_pTransferServerDialog);
        }

        m_objectId = PacketBufferReadUInt32BE(packet + 1);
        m_facing = packet[8];
        const unsigned char statusIconId = packet[9];
        if (statusIconId <= 4)
            g_activeUserStatusPane->SetStatusIconId(statusIconId);

        m_mapPane->UpdateObjectPaneScreenBounds(this);

        SimpleUStringVector &blockedNames = g_pConfig->m_blockListenNames;
        if (blockedNames.size() < 0xff)
        {
            for (SimpleUStringVector::const_iterator it = blockedNames.begin();
                 it != blockedNames.end(); ++it)
            {
                if (!it->empty())
                {
                    unsigned char request[0x400];
                    int requestSize = 0;
                    PacketBufferAppendUInt8(0x0d, request, &requestSize);
                    PacketBufferAppendUInt8(0x02, request, &requestSize);

                    StringBase<char, mychar_traits<char> > narrowName(*it);
                    PacketBufferAppendAnsiString8(
                        narrowName.c_str(), request, &requestSize);
                    g_packetSender->QueueAndSendPacket(
                        request, static_cast<short>(requestSize));
                }
            }
        }
    }
    else
    {
        SelfLookPane *selfLookPane = static_cast<SelfLookPane *>(
            g_pGeneralPurposePanel->GetChildPaneByIndex(0));
        selfLookPane->RefreshSpelledPane();

        g_packetSender->SetSendDisabled(false);
        if (g_pTransferServerDialog != 0)
        {
            g_pTransferServerDialog->ResetOpacityAndRepaint();
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(
                g_pTransferServerDialog);
        }

        m_objectId = PacketBufferReadUInt32BE(packet + 1);
        m_facing = packet[8];
        const unsigned char statusIconId = packet[9];
        if (statusIconId <= 4)
            g_pOldUserStatusPane->SetStatusIconId(statusIconId);

        m_mapPane->UpdateObjectPaneScreenBounds(this);

        SimpleUStringVector &blockedNames = g_pConfig->m_blockListenNames;
        if (blockedNames.size() < 0xff)
        {
            for (SimpleUStringVector::const_iterator it = blockedNames.begin();
                 it != blockedNames.end(); ++it)
            {
                if (!it->empty())
                {
                    unsigned char request[0x400];
                    int requestSize = 0;
                    PacketBufferAppendUInt8(0x0d, request, &requestSize);
                    PacketBufferAppendUInt8(0x02, request, &requestSize);

                    StringBase<char, mychar_traits<char> > narrowName(*it);
                    PacketBufferAppendAnsiString8(
                        narrowName.c_str(), request, &requestSize);
                    g_packetSender->QueueAndSendPacket(
                        request, static_cast<short>(requestSize));
                }
            }
        }
    }

    return true;
}

// UID:0003UO | by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md | Completion:87 | Confidence:89
bool UserPane::HandleWarpPacket(const unsigned char *packet)
{
    const int x = static_cast<short>(PacketBufferReadUInt16BE(packet + 1));
    const int y = static_cast<short>(PacketBufferReadUInt16BE(packet + 3));
    const int viewportColumn =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 5));
    const int viewportRow =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 7));
    WarpToPosition(x, y, viewportColumn, viewportRow);
    m_mapPane->OnLocalPlayerWarpApplied();
    ClearAllMovementHistoryRecords();
    return false;
}

// UID:0003UP | by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md | Completion:92 | Confidence:94
bool UserPane::HandleMovementReplyPacket(const unsigned char *packet)
{
    const unsigned char direction = packet[1];
    const int serverX = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 2));
    const int serverY = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 4));
    const int viewportColumn = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 6));
    const int viewportRow = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 8));
    const unsigned char historyIndex = packet[10] & 0x7f;

    if (!m_isMoving &&
        (!m_mapPane->AllowsMovementStatusTag() ||
         !g_pConfig->m_mapMovementStatusOption))
    {
        WarpToPosition(serverX, serverY, viewportColumn, viewportRow);
        if (direction != 4)
            InitializeWalkAnimation(direction);
        SetMovementReplyState();
        m_mapPane->RecenterAndSendPosition(
            serverX, serverY, viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemovePendingTimersForOwner(
            static_cast<TimerHandler *>(m_mapPane));
        return true;
    }

    if (!m_mapPane->AllowsMovementStatusTag() ||
        g_pConfig->m_mapMovementStatusOption != 1)
    {
        if (serverX == m_tileX && serverY == m_tileY &&
            direction == m_facing)
        {
            const bool pendingReply = m_movementReplyPending;
            SetMovementReplyState();
            if (pendingReply)
            {
                const int event = m_movementReplyTimerFamily != 0
                    ? kLivingTimerForwardStep
                    : kUserPaneMovementStep;
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    event, 0, m_facing, 0);
            }
            return false;
        }

        MapPoint step;
        DirectionToTileOffset(&step, direction);
        const int correctedX = serverX + step.column;
        const int correctedY = serverY + step.row;
        WarpToPosition(
            correctedX, correctedY, viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            correctedX, correctedY, viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemovePendingTimersForOwner(
            static_cast<TimerHandler *>(m_mapPane));
        return false;
    }

    if (direction & 0x80)
    {
        const bool pendingReply = m_movementReplyPending;
        SetMovementReplyState();
        if (pendingReply)
        {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLivingTimerForwardStep, 0, m_facing, 0);
        }
        return false;
    }

    if (historyIndex >= m_movementHistoryCapacity)
        return false;

    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[historyIndex];
    if (!record.active)
        return false;

    if (record.tileX != serverX || record.tileY != serverY ||
        record.direction != direction)
    {
        MapPoint step;
        DirectionToTileOffset(&step, direction);
        const int correctedX = serverX + step.column;
        const int correctedY = serverY + step.row;
        WarpToPosition(
            correctedX, correctedY, viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            correctedX, correctedY, viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemovePendingTimersForOwner(
            static_cast<TimerHandler *>(m_mapPane));
        ClearAllMovementHistoryRecords();
    }
    ClearMovementHistoryRecordByIndex(historyIndex);
    return false;
}

// UID:0003UQ | by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md | Completion:92 | Confidence:94
bool UserPane::HandleExtendedMovementReplyPacket(
    const unsigned char *packet)
{
    const unsigned char direction = packet[1];
    const int serverX = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 2));
    const int serverY = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 4));
    const int viewportColumn = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 6));
    const int viewportRow = static_cast<short>(
        PacketBufferReadUInt16BE(packet + 8));
    const unsigned char historyIndex = packet[10] & 0x7f;

    if (!m_isMoving &&
        (!m_mapPane->AllowsMovementStatusTag() ||
         !g_pConfig->m_mapMovementStatusOption))
    {
        WarpToPosition(serverX, serverY, viewportColumn, viewportRow);
        if (direction != 4)
            InitializeWalkAnimation(direction);
        SetMovementReplyState();
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemovePendingTimersForOwner(
            static_cast<TimerHandler *>(m_mapPane));
        return true;
    }

    if (!m_mapPane->AllowsMovementStatusTag() ||
        g_pConfig->m_mapMovementStatusOption != 1)
    {
        if (serverX == m_tileX && serverY == m_tileY &&
            direction == m_facing)
        {
            const bool pendingReply = m_movementReplyPending;
            SetMovementReplyState();
            if (pendingReply)
            {
                const int event = m_movementReplyTimerFamily != 0
                    ? kLivingTimerForwardStep
                    : kUserPaneMovementStep;
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    event, 0, m_facing, 0);
            }
            return false;
        }

        MapPoint step;
        DirectionToTileOffset(&step, direction);
        const int correctedX = serverX + step.column;
        const int correctedY = serverY + step.row;
        WarpToPosition(
            correctedX, correctedY, viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            correctedX, correctedY, viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemovePendingTimersForOwner(
            static_cast<TimerHandler *>(m_mapPane));
        return false;
    }

    if (direction & 0x80)
    {
        const bool pendingReply = m_movementReplyPending;
        SetMovementReplyState();
        if (pendingReply)
        {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kUserPaneMovementStep,
                m_objectStatus.m_displayStatusByte /
                    g_movementSubstepScale,
                m_facing, 0);
        }
        return false;
    }

    if (historyIndex >= m_movementHistoryCapacity)
        return false;

    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[historyIndex];
    if (!record.active)
        return false;

    if (record.tileX != serverX || record.tileY != serverY ||
        record.direction != direction)
    {
        MapPoint step;
        DirectionToTileOffset(&step, direction);
        const int correctedX = serverX + step.column;
        const int correctedY = serverY + step.row;
        WarpToPosition(
            correctedX, correctedY, viewportColumn, viewportRow);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemovePendingTimersForOwner(
            static_cast<TimerHandler *>(m_mapPane));
        ClearAllMovementHistoryRecords();
    }
    ClearMovementHistoryRecordByIndex(historyIndex);
    return false;
}

// UID:0003UR | by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md | Completion:88 | Confidence:91
bool UserPane::HandleChatMessagePacket(const unsigned char *packet)
{
    if (packet[1] != 0)
        return false;

    const unsigned int textByteCount = PacketBufferReadUInt16BE(packet + 2);
    if (textByteCount >= 0x8000)
        __report_rangecheckfailure();

    char ansiText[0x8000];
    wchar_t wideText[0x8000];
    wchar_t senderScratch[128];
    GetMemoryMan();
    MemmoveWrapper(ansiText, packet + 4, textByteCount);
    ansiText[textByteCount] = 0;

    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, ansiText, static_cast<int>(textByteCount),
        wideText, 0x8000);
    if (static_cast<unsigned int>(static_cast<unsigned short>(wideCount)) >=
        0x8000)
        __report_rangecheckfailure();
    wideText[static_cast<unsigned short>(wideCount)] = 0;

    if ((wideText[0] == L'-' && wideText[1] == L'>' && wideText[2] == L' ') ||
        wcsstr(wideText, L"> ") != 0)
        return false;

    wchar_t *quoteSpace = wcsstr(wideText, L"\" ");
    if (quoteSpace == 0)
        return false;
    *quoteSpace = 0;
    wcsncpy_s(senderScratch, 128, wideText, 128);
    senderScratch[35] = 0;
    if (wcschr(senderScratch, L' ') != 0)
        return false;

    List *senders = m_incomingWhisperSenderHistory;
    int foundIndex = -1;
    const int count = senders->GetCount();
    for (int i = 0; i < count; ++i)
    {
        const wchar_t *stored =
            static_cast<const wchar_t *>(senders->GetElementAt(i));
        if (wcscmp(stored, senderScratch) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
        senders->RemoveAt(foundIndex, 1);
    else if (count >= 10)
        senders->RemoveAt(0, 1);
    senders->Append(1, senderScratch);
    m_whisperHistorySource = WhisperHistorySource_IncomingSender;
    return false;
}

// UID:0003US | by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md | Completion:94 | Confidence:95
bool UserPane::HandleUserListPacket(const ServerMessageEvent *event)
{
    if (m_skipNextUserListPacket)
    {
        m_skipNextUserListPacket = false;
    }
    else
    {
        const unsigned char *packet = event->packetData;
        const size_t packetSize = event->packetSize;
        const unsigned short entryCount =
            PacketBufferReadUInt16BE(packet + 3);
        const unsigned int currentTick = g_pTimerMgr->m_currentTick;

        m_userListPacketTick = currentTick;
        if (entryCount < 100)
        {
            m_userListDeferUntilTick = currentTick;
        }
        else if (entryCount < 300)
        {
            m_userListDeferUntilTick = currentTick + 30000;
            CopyDeferredUserListPacket(packet, packetSize);
        }
        else if (entryCount < 500)
        {
            m_userListDeferUntilTick = currentTick + 60000;
            CopyDeferredUserListPacket(packet, packetSize);
        }
        else if (entryCount < 800)
        {
            m_userListDeferUntilTick = currentTick + 90000;
            CopyDeferredUserListPacket(packet, packetSize);
        }
        else
        {
            m_userListDeferUntilTick = currentTick + 150000;
            free(m_deferredUserListPacket);
            m_deferredUserListPacket =
                static_cast<unsigned char *>(malloc(packetSize));
            m_deferredUserListPacketSize = packetSize;
            memmove(m_deferredUserListPacket, packet, packetSize);
        }
    }

    if (g_pUserListDialogPane == NULL)
        new UserListDialogPane(event->packetData);
    return true;
}

// UID:0003UV | by-memory/0x005ac1b0-0x005ac27c.UserPaneHandlePositionSyncPacket.md | Completion:87 | Confidence:88
bool UserPane::HandlePositionSyncPacket(const unsigned char *packet)
{
    (void)packet[1];
    const int targetX = PacketBufferReadUInt16BE(packet + 2);
    const int targetY = PacketBufferReadUInt16BE(packet + 4);
    const int viewportColumn = PacketBufferReadUInt16BE(packet + 6);
    const int viewportRow = PacketBufferReadUInt16BE(packet + 8);

    if (!m_isMoving)
    {
        WarpToPosition(
            targetX, targetY, viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            targetX, targetY, viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPosition(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
    }
    return true;
}

// UID:0003UW | by-memory/0x005ac280-0x005ac69b.UserPaneParseGroupListPacket.md | Completion:92 | Confidence:94
bool UserPane::ParseGroupListPacket(const unsigned char *packet)
{
    const signed char newMemberCount =
        static_cast<signed char>(packet[0]);

    if (m_groupMemberCount > newMemberCount)
    {
        for (int i = 0; i < m_groupMemberCount; ++i)
            g_activeMapPane->RemoveGroupMemberHitBar(
                m_groupMembers[i].memberId);
    }

    m_groupMemberCount = newMemberCount;

    unsigned int offset = 1;
    for (int i = 0; i < m_groupMemberCount; ++i)
    {
        GroupMemberRecord &member = g_pUserPane->m_groupMembers[i];

        member.memberId = PacketBufferReadUInt32BE(packet + offset);
        offset += 4;

        const unsigned int nameLength =
            static_cast<signed char>(packet[offset++]);
        char nameBytes[128];
        GetMemoryMan()->MemmoveWrapper(
            nameBytes, packet + offset, nameLength);
        offset += nameLength;
        nameBytes[nameLength] = '\0';

        const signed char wideLength = static_cast<signed char>(
            MultiByteToWideChar(
                CP_ACP,
                0,
                nameBytes,
                nameLength,
                member.name,
                0x8000));
        member.name[wideLength] = L'\0';

        member.active = packet[offset++] != 0;
        member.faceId = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        member.hairId = packet[offset++];
        member.hairColor = packet[offset++];
        member.faceColor = packet[offset++];
        member.skinColor = packet[offset++];
        member.bodyColor = packet[offset++];
        member.helmetId = packet[offset++];
        member.helmetColor = packet[offset++];
        member.faceDecorationId =
            PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        member.faceDecorationColor = packet[offset++];
        member.hairDecorationId =
            PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        member.hairDecorationColor = packet[offset++];
        member.secondFaceDecorationId =
            PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        member.secondFaceDecorationColor = packet[offset++];
        member.maximumHitPoints =
            PacketBufferReadUInt32BE(packet + offset);
        offset += 4;
        member.currentHitPoints =
            PacketBufferReadUInt32BE(packet + offset);
        offset += 4;
        member.maximumManaPoints =
            PacketBufferReadUInt32BE(packet + offset);
        offset += 4;
        member.currentManaPoints =
            PacketBufferReadUInt32BE(packet + offset);
        offset += 4;

        g_activeMapPane->RefreshGroupMemberHitBar(
            m_groupMembers[i].memberId);
    }

    return true;
}

// UID:0003UX | by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md | Completion:88 | Confidence:89
void UserPane::SendMovementWaypointPacket(
    unsigned char direction, unsigned short token,
    const MovementWaypointSegment *segment)
{
    unsigned char packet[0x12];
    int packetSize = 0;
    packet[packetSize++] = 0x06;
    packet[packetSize++] = direction;
    packet[packetSize++] =
        m_mapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_mapMovementStatusOption
            ? static_cast<unsigned char>(m_movementHistoryWriteIndex | 0x80)
            : static_cast<unsigned char>(m_movementHistoryWriteIndex & 0x7f);
    packet[packetSize++] = m_objectStatus.m_displayStatusByte;

    MapPoint position;
    GetMapPosition(&position);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(position.column), packet, &packetSize);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(position.row), packet, &packetSize);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(segment->startX), packet, &packetSize);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(segment->startY), packet, &packetSize);
    PacketBufferAppendUInt8(
        static_cast<unsigned char>(segment->endX - segment->startX),
        packet, &packetSize);
    PacketBufferAppendUInt8(
        static_cast<unsigned char>(segment->endY - segment->startY),
        packet, &packetSize);
    PacketBufferAppendUInt16BE(token, packet, &packetSize);

    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[m_movementHistoryWriteIndex];
    record.active = 1;
    record.tileY = position.row;
    record.tileX = position.column;
    record.direction = direction;
    m_movementHistoryWriteIndex = static_cast<unsigned char>(
        (m_movementHistoryWriteIndex + 1) % m_movementHistoryCapacity);
    packet[packetSize] = 0;
    g_packetSender->QueueAndSendPacket(packet, packetSize);
}

// UID:0003UY | by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md | Completion:87 | Confidence:89
void UserPane::SendFaceDirectionPacket(unsigned char direction)
{
    unsigned char packet[11];
    packet[0] = 0x32;
    packet[1] = direction;
    packet[2] =
        m_mapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_mapMovementStatusOption
            ? static_cast<unsigned char>(m_movementHistoryWriteIndex | 0x80)
            : static_cast<unsigned char>(m_movementHistoryWriteIndex & 0x7f);
    packet[3] = m_objectStatus.m_displayStatusByte;

    MapPoint position;
    GetMapPosition(&position);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(position.column), packet + 4);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(position.row), packet + 6);

    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[m_movementHistoryWriteIndex];
    record.active = 1;
    record.tileY = position.row;
    record.tileX = position.column;
    record.direction = direction;
    m_movementHistoryWriteIndex = static_cast<unsigned char>(
        (m_movementHistoryWriteIndex + 1) % m_movementHistoryCapacity);

    PacketBufferWriteUInt16BE(0x32, packet + 8);
    packet[9] = 0;
    g_packetSender->QueueAndSendPacket(packet, 9);
}

// UID:0003H5 | by-memory/0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket.md | Completion:92 | Confidence:93
extern MapPane *g_activeMapPane;
extern unsigned int s_selectObjectTargetId;

void UserPane::SendAutoFaceDirectionPacket()
{
    ObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    if (m_actionMode != 1)
        return;
    if (target == 0)
        return;

    MapPoint targetPosition;
    target->GetMapPosition(&targetPosition);
    const int rowDelta = targetPosition.row - m_mapY;
    const int columnDelta = targetPosition.column - m_mapX;
    unsigned char direction;
    if (rowDelta == 0)
        direction = columnDelta <= 0 ? 3 : 1;
    else if (columnDelta == 0)
        direction = rowDelta <= 0 ? 0 : 2;
    else
    {
        const float slope =
            static_cast<float>(-(rowDelta / columnDelta));
        if (columnDelta <= 0)
            direction = slope > 1.0f ? 2
                : (slope < -1.0f ? 0 : 3);
        else
            direction = slope > 1.0f ? 0
                : (slope < -1.0f ? 2 : 1);
    }
    if (direction != m_facing)
        SendDirectionPacket(direction);
}

// UID:0003UZ | by-memory/0x005acc30-0x005acd85.UserPaneSendActionPacketWithAutoFace.md | Completion:92 | Confidence:94
void UserPane::SendActionPacketWithAutoFace()
{
    unsigned char packet[3];
    packet[0] = 0x13;
    int packetSize = 1;
    if (m_actionMode == 1)
    {
        SendAutoFaceDirectionPacket();
        packet[1] = 1;
        packetSize = 2;
    }
    else if (m_actionMode == 2)
    {
        packet[1] = 1;
        packetSize = 2;
    }
    else if (m_actionMode == 0)
    {
        packet[1] = 0;
        packetSize = 2;
    }
    packet[packetSize] = 0;
    g_packetSender->QueueAndSendPacket(packet, packetSize);
}

// UID:0003V0 | by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md | Completion:92 | Confidence:94
void UserPane::SendAttackTargetPacket(char direction)
{
    if (m_isMoving)
        return;

    MapRect targetBounds;
    const unsigned short boundsChecksum =
        m_mapPane->GetAdjacentVisibleTileBounds(direction, &targetBounds);

    unsigned char packet[13];
    PacketBufferWriteUInt8(0x82, packet);
    PacketBufferWriteUInt8(direction, packet + 1);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(m_viewportColumn), packet + 2);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(m_viewportRow), packet + 3);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(targetBounds.left), packet + 4);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(targetBounds.top), packet + 6);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(
            targetBounds.right - targetBounds.left),
        packet + 8);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(
            targetBounds.bottom - targetBounds.top),
        packet + 9);
    PacketBufferWriteUInt16BE(boundsChecksum, packet + 10);
    packet[12] = 0;

    g_packetSender->QueueAndSendPacket(packet, 12);
}

// UID:0004SM | by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md | Completion:92 | Confidence:94
bool UserPane::IsGroupMember(unsigned int memberId) const
{
    for (int i = 0; i < m_groupMemberCount; ++i)
    {
        if (m_groupMembers[i].memberId == memberId)
            return true;
    }

    return false;
}

// UID:0004R9 | by-memory/0x005adbe0-0x005adc15.UserPaneFindGroupMemberById.md | Completion:91 | Confidence:93
GroupMemberRecord *UserPane::FindGroupMemberById(unsigned int memberId)
{
    for (int i = 0; i < m_groupMemberCount; ++i)
    {
        if (m_groupMembers[i].memberId == memberId)
            return &m_groupMembers[i];
    }

    return 0;
}

// UID:00024A | by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md | Completion:89 | Confidence:92
MapPane *UserPane::GetMapPane()
{
    return m_mapPane;
}

// UID:0003EE | by-global/g_pInputBlockerPane.md | Completion:87 | Confidence:90
class InputBlockerPane;

InputBlockerPane *g_pInputBlockerPane = 0;

// UID:0001KL | by-memory/0x005a2530-0x005b8395.UserPane.md | Completion:91 | Confidence:93
// Broad UserPane executable aggregate. Formal source is emitted by exact
// children such as UserPane methods, file-scope globals, and layout pages.
// The aggregate is documented through its exact source children; do not emit a synthetic body.

// UID:0004YC | by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md | Completion:92 | Confidence:94
void __stdcall RequestLocalPlayerStatus(unsigned int requestTime)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x2d, packet);
    PacketBufferWriteUInt8(0, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);

    if (g_useEpfAssets)
        g_epfLocalPlayerStatusRequestTime = requestTime;
    else
        g_legacyLocalPlayerStatusRequestTime = requestTime;
}

// UID:0004US | by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md | Completion:90 | Confidence:93
void EnsureNormalBulletinSession()
{
    if (g_pBulletinSession == 0)
        new BulletinSession(1, 0, false);
}

// UID:0003UT | by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md | Completion:88 | Confidence:90
static bool __stdcall HandleUIPanelSwitchPacket(const unsigned char *packet)
{
    unsigned int offset = 1;
    const unsigned char panel = PacketBufferReadUInt8(packet, &offset);
    if (g_useEpfAssets)
    {
        switch (panel)
        {
        case 0: g_pMainWindow->SwitchAuxiliaryPanel(2, false); break;
        case 2: g_pMainWindow->SwitchAuxiliaryPanel(3, false); break;
        case 4:
            RefreshUserPanelState();
            g_pMainWindow->GetPaneByRole(MainWindowPane_User)->m_panelMode = 0;
            break;
        case 6: OpenCollectionPanel(); break;
        case 7:
            RefreshUserPanelState();
            g_pMainWindow->GetPaneByRole(MainWindowPane_User)->m_panelMode = 3;
            break;
        case 8:
            RefreshUserPanelState();
            g_pMainWindow->GetPaneByRole(MainWindowPane_User)->m_panelMode = 2;
            break;
        }
    }
    else
    {
        switch (panel)
        {
        case 0: g_pMainWindow->SwitchAuxiliaryPanel(2, false); break;
        case 2: g_pMainWindow->SwitchAuxiliaryPanel(3, false); break;
        case 4:
            RefreshUserPanelState();
            g_pMainWindow->GetPaneByRole(MainWindowPane_User)->m_panelMode = 1;
            break;
        case 6: OpenCollectionPanel(); break;
        case 7:
            RefreshUserPanelState();
            g_pMainWindow->GetPaneByRole(MainWindowPane_User)->m_panelMode = 3;
            break;
        case 8:
            RefreshUserPanelState();
            g_pMainWindow->GetPaneByRole(MainWindowPane_User)->m_panelMode = 2;
            break;
        }
    }
    return true;
}

// UID:0003H4 | by-memory/0x005acae0-0x005acb1f.UserPaneSendDirectionPacket.md | Completion:92 | Confidence:93
static void __stdcall SendDirectionPacket(unsigned char direction)
{
    unsigned char packet[3] = {0x11, direction, 0};
    g_packetSender->QueueAndSendPacket(packet, 2);
}

// UID:0004R3 | by-memory/0x005acf10-0x005acf5f.UserPaneSendOpcode7Command.md | Completion:90 | Confidence:93
static void SendOpcode7Command(unsigned char command)
{
    unsigned char packet[3];
    packet[0] = 7;
    packet[1] = command;
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}


// UID:0003EB | by-memory/0x00630c24-0x00630c28.UserPaneActionNegativeOneFloatConstant.md | Completion:91 | Confidence:93
// Compiler-pooled -1.0f uses are covered by UID0003H5 and UID0003UZ.

// UID:0001OR | by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md | Completion:89 | Confidence:90
class UserPane;

UserPane *g_pUserPane = 0;

// UID:0002AA | by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md | Completion:88 | Confidence:91
wchar_t g_localPlayerName[32] = { 0 };

// UID:0002AC | by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md | Completion:91 | Confidence:90
static PoolAllocator g_userPanePool(sizeof(UserPane), 2);

// UID:00030A | by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md | Completion:88 | Confidence:90
static unsigned int g_epfLocalPlayerStatusRequestTime = 0;
static unsigned int g_legacyLocalPlayerStatusRequestTime = 0;

// UID:0001TZ | by-type\by-struct\CollectionPlayerDataLayout.md | Completion:93 | Confidence:94 | Empty Emitter Marker

// UID:0003UB | by-memory\0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:0003V8 | by-memory\0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003J2 | by-memory\0x006307ec-0x006309d0.UserPaneOptionStatusStrings.md | Completion:87 | Confidence:92 | Empty Emitter Marker
