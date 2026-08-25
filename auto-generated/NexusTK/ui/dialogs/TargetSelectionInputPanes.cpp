// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OH
// Source by-file doc: by-file/TargetSelectionInputPanes.md
// UID:0002AB | by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md | Completion:90 | Confidence:92
static unsigned int s_spellWhoTargetId = 0;
static unsigned int s_itemWhoTargetId = 0;
unsigned int s_selectObjectTargetId = 0;
static unsigned int s_targetObjectTargetId = 0;
static unsigned int s_targetObjectPreviousTargetId = 0;

// UID:0003J5 | by-memory/0x00630af0-0x00630b10.ItemWhoTargetPromptString.md | Completion:88 | Confidence:92
static const wchar_t kWhichTargetPrompt[] = L"Which target?";

// UID:0001L9 | by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md | Completion:88 | Confidence:90
int SendTargetedActionPacket(unsigned char action, unsigned int objectId,
    unsigned short argument1, unsigned short argument2)
{
    unsigned char packet[11];

    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(action, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    PacketBufferWriteUInt16BE(argument1, packet + 6);
    PacketBufferWriteUInt16BE(argument2, packet + 8);
    packet[10] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 10);
}

// UID:0001LA | by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md | Completion:88 | Confidence:90
int SendObjectActionPacket(unsigned char action, unsigned int objectId)
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x1c, packet);
    PacketBufferWriteUInt8(action, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    packet[6] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:00006X | by-class/ItemWhoInputPane.md | Completion:88 | Confidence:90
#include "../core/BlackHole.h"

// No standalone ItemWhoInputPane class-level source body; exact method and helper children emit this class.
// UID:0002S1 | by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md | Completion:88 | Confidence:90
ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)
    : LineInputPane(NULL),
      m_itemSlot(itemSlot)
{
    SetPromptText(kWhichTargetPrompt);

    unsigned int targetId = s_itemWhoTargetId;
    if (g_pConfig->saveTargetOnClose)
        targetId = s_spellWhoTargetId;

    s_itemWhoTargetId = targetId;

    LivingObjectPane *target = g_pUserPane->GetLocalPlayerObject();
    LivingObjectPane *candidate = g_activeMapPane->FindObjectPaneById(targetId);
    if (candidate != NULL &&
        candidate->ObjectType() == kLivingObjectType &&
        !candidate->IsTargetingDisabled()) {
        target = candidate;
    }

    target->SetTargetHighlight(true);
    s_itemWhoTargetId = target->ObjectId();
}

// UID:0001L5 | by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md | Completion:88 | Confidence:90
ItemWhoInputPane::~ItemWhoInputPane()
{
    if (g_pConfig->saveTargetOnClose)
        s_spellWhoTargetId = s_itemWhoTargetId;

    ItemWhoInputPaneState *state =
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3));
    if (state != NULL)
        state->SetInputModeFlag(false);
}

// UID:0002S2 | by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md | Completion:88 | Confidence:90
bool ItemWhoInputPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = NarrowKey(event->key);

    if ((event->modifierFlags & 0x03) != 0)
        return true;

    if (event->kind != kKeyPressed)
        return false;

    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);

    if (key == kKeyEnter) {
        if (current != NULL) {
            ClearItemWhoTarget();
            SendObjectActionPacket(m_itemSlot, current->ObjectId());
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kKeyEscape) {
        if (current != NULL)
            ClearItemWhoTarget();
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kKeySelfTarget) {
        LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
        if (current != selfTarget) {
            if (current != NULL)
                current->SetTargetHighlight(false);
            selfTarget->SetTargetHighlight(true);
            s_itemWhoTargetId = selfTarget->ObjectId();
        }
        return true;
    }

    LivingObjectPane *nextTarget = NULL;
    const bool alternateTraversal = (event->modifierFlags & 0x04) != 0;

    if (IsPreviousTargetKey(key)) {
        if (current != NULL) {
            nextTarget = alternateTraversal
                ? g_activeMapPane->FindPreviousSelectableObjectAlternate(current)
                : g_activeMapPane->FindPreviousSelectableObject(current);
        } else {
            nextTarget = g_pUserPane->GetLocalPlayerObject();
        }
    } else if (IsNextTargetKey(key)) {
        if (current != NULL) {
            nextTarget = alternateTraversal
                ? g_activeMapPane->FindNextSelectableObjectAlternate(current)
                : g_activeMapPane->FindNextSelectableObject(current);
        } else {
            nextTarget = g_pUserPane->GetLocalPlayerObject();
        }
    } else {
        return false;
    }

    if (nextTarget == current)
        return true;

    if (current != NULL)
        current->SetTargetHighlight(false);

    if (nextTarget != NULL) {
        nextTarget->SetTargetHighlight(true);
        s_itemWhoTargetId = nextTarget->ObjectId();
    } else {
        s_itemWhoTargetId = 0;
    }

    return true;
}

// UID:0002S3 | by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md | Completion:88 | Confidence:90
bool ItemWhoInputPane::OnMouseEvent(MouseEvent *event)
{
    if (event->kind != kMouseTargetChange &&
        event->kind != kMouseTargetConfirm) {
        return false;
    }

    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    g_activeMapPane->GetBoundsRect(&mapRect);
    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);

    if (event->kind == kMouseTargetConfirm) {
        if (current == NULL || !PointInRect(mapX, mapY, mapRect))
            return false;

        current->SetTargetHighlight(false);
        g_pUserPane->ClearPendingTargetObject();
        SendObjectActionPacket(m_itemSlot, current->ObjectId());
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return true;
    }

    LivingObjectPane *hitTarget =
        g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

    if (hitTarget != NULL && hitTarget != current) {
        if (current != NULL)
            current->SetTargetHighlight(false);
        hitTarget->SetTargetHighlight(true);
        s_itemWhoTargetId = hitTarget->ObjectId();

        if (g_pConfig->doubleClick)
            return true;

        ClearItemWhoTarget();
        g_pUserPane->ClearPendingTargetObject();
        SendObjectActionPacket(m_itemSlot, hitTarget->ObjectId());
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return true;
    }

    if (!PointInRect(mapX, mapY, mapRect))
        return false;

    if (g_pConfig->doubleClick || current == NULL)
        return true;

    ClearItemWhoTarget();
    g_pUserPane->ClearPendingTargetObject();
    SendObjectActionPacket(m_itemSlot, current->ObjectId());
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    return true;
}

// UID:0001L6 | by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md | Completion:88 | Confidence:90
bool ItemWhoInputPane::OnObjectListMessage(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload == NULL || payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    bool containsCurrentTarget = false;

    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);
        if (objectId == s_itemWhoTargetId) {
            containsCurrentTarget = true;
            break;
        }
    }

    if (!containsCurrentTarget)
        return false;

    LivingObjectPane *oldTarget =
        g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);
    LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();

    s_itemWhoTargetId = selfTarget->ObjectId();

    if (oldTarget != NULL)
        oldTarget->SetTargetHighlight(false);

    selfTarget->SetTargetHighlight(true);
    return false;
}

// UID:0002S5 | by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md | Completion:88 | Confidence:89
// Emitted code for this range is covered by [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md).

// UID:00006Y | by-class/ItemWhoInputPaneState.md | Completion:87 | Confidence:90
// No standalone ItemWhoInputPaneState class declaration is emitted here; [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) emits SetInputModeFlag.
// UID:0001IJ | by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md | Completion:88 | Confidence:90
bool ItemWhoInputPaneState::SetInputModeFlag(bool active)
{
    m_active = active;
    return active;
}

// UID:0000CT | by-class/SelectObjectWithKeyboardPane.md | Completion:87 | Confidence:88
// No standalone SelectObjectWithKeyboardPane class-level source body; exact method and helper children emit this class.
// UID:0001LB | by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md | Completion:88 | Confidence:91
SelectObjectWithKeyboardPane::SelectObjectWithKeyboardPane()
    : LineInputPane(NULL)
{
    s_activeSelectObjectWithKeyboardPane = this;

    SetPromptText(L"Use arrow key to select target then press enter.");

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_selectObjectTargetId = target->ObjectId();

    SetPaneOrder(NULL, g_pBackPane);
    s_selectObjectTargetModeActive = false;
}

// UID:0001LC | by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md | Completion:88 | Confidence:91
SelectObjectWithKeyboardPane::~SelectObjectWithKeyboardPane()
{
    s_activeSelectObjectWithKeyboardPane = NULL;
}

// UID:0001LD | by-memory/0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent.md | Completion:88 | Confidence:90
bool SelectObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = event->key;

    if ((event->modifierFlags & 0x03) != 0)
        return true;

    switch (key) {
    case kKeyEnter:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *target =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            if (target != NULL) {
                ClearCurrentTarget();
                g_activeMapPane->InteractWithObject(target);
            }
            s_selectObjectTargetModeActive = false;
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        }
        LineInputPane::OnKeyEvent(event);
        return true;

    case kKeyEscape:
    case kKeySpace:
        if (event->kind == kTargetSelectionKeyEvent) {
            if (g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId) != NULL)
                ClearCurrentTarget();
            s_selectObjectTargetModeActive = false;
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        }
        event->key = kKeyEscape;
        LineInputPane::OnKeyEvent(event);
        event->key = key;
        return false;

    case 'v':
        if (g_pConfig->tabVSwap || g_pConfig->targetSelectionSuppressed)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeyTab:
        if (!g_pConfig->tabVSwap || g_pConfig->targetSelectionSuppressed)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeySelfTarget:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
            if (oldTarget != selfTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                selfTarget->SetTargetHighlight(true);
                s_selectObjectTargetId = selfTarget->GetObjectId();
            }
        }
        return true;

    case 'h':
    case 'k':
    case kKeyPrevA:
    case kKeyPrevB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *start = oldTarget;
            if (start == NULL)
                start = g_pUserPane->GetLocalPlayerObject();

            LivingObjectPane *newTarget =
                g_activeMapPane->FindPreviousSelectableObject(start);
            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_selectObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_selectObjectTargetId = 0;
                }
            }
        }
        return true;

    case 'j':
    case 'l':
    case kKeyNextA:
    case kKeyNextB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *start = oldTarget;
            if (start == NULL)
                start = g_pUserPane->GetLocalPlayerObject();

            LivingObjectPane *newTarget =
                g_activeMapPane->FindNextSelectableObject(start);
            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_selectObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_selectObjectTargetId = 0;
                }
            }
        }
        return true;
    }

    return true;
}

// UID:0001LE | by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md | Completion:88 | Confidence:90
bool SelectObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)
{
    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    if (event->kind == kMouseTargetConfirm) {
        g_activeMapPane->GetBoundsRect(&mapRect);
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);

        if (!PointInRect(mapX, mapY, mapRect) || target == NULL)
            return false;

        ClearCurrentTarget();
        g_pUserPane->ClearPendingTargetObject();
        g_activeMapPane->InteractWithObject(target);
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        g_pUserPane->ClearPendingTargetObject();

        if (g_pChattingHandlePane != NULL && g_pChattingHandlePane->m_chatTargetPending) {
            g_pUserPane->ClearChatTargetState();
            if (g_pChattingVarietyPane != NULL)
                g_pChattingVarietyPane->RefreshAfterTargetSelection();
        }
        return true;
    }

    if (event->kind != kMouseTargetChange)
        return false;

    LivingObjectPane *oldTarget =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    LivingObjectPane *hitTarget = g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

    if (hitTarget != NULL) {
        if (hitTarget != oldTarget) {
            if (oldTarget != NULL)
                oldTarget->SetTargetHighlight(false);
            hitTarget->SetTargetHighlight(true);
            s_selectObjectTargetId = hitTarget->GetObjectId();

            if (g_pConfig->doubleClick)
                return true;
            if (oldTarget == NULL)
                return false;

            ClearCurrentTarget();
            g_pUserPane->ClearPendingTargetObject();
            g_activeMapPane->InteractWithObject(hitTarget);
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
            g_pUserPane->ClearPendingTargetObject();
            return true;
        }

        if (g_pConfig->doubleClick)
            return true;
        if (oldTarget == NULL)
            return false;

        ClearCurrentTarget();
        g_pUserPane->ClearPendingTargetObject();
        g_activeMapPane->InteractWithObject(oldTarget);
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        g_pUserPane->ClearPendingTargetObject();
        return true;
    }

    g_activeMapPane->GetBoundsRect(&mapRect);
    if (!PointInRect(mapX, mapY, mapRect))
        return false;

    if (g_pConfig->doubleClick || oldTarget == NULL)
        return true;

    ClearCurrentTarget();
    g_pUserPane->ClearPendingTargetObject();
    g_activeMapPane->InteractWithObject(oldTarget);
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    g_pUserPane->ClearPendingTargetObject();
    return true;
}

// UID:0001LF | by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md | Completion:88 | Confidence:90
bool SelectObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);

        if (objectId == s_selectObjectTargetId) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *localPlayer = g_pUserPane->GetLocalPlayerObject();

            s_selectObjectTargetId = localPlayer->GetObjectId();
            oldTarget->SetTargetHighlight(false);
            localPlayer->SetTargetHighlight(true);
            break;
        }
    }

    return false;
}

// UID:0001LG | by-memory/0x005afd30-0x005afd4f.SelectObjectWithKeyboardPaneClearCurrentTarget.md | Completion:88 | Confidence:91
void SelectObjectWithKeyboardPane::ClearCurrentTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}

// UID:00048D | by-memory/0x005afd50-0x005afe6f.SelectObjectWithKeyboardPaneNavigationRawHelpers.md | Completion:88 | Confidence:89
// Emitted code for this range is covered by [UID:0001LD][0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent](by-memory/0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent.md).

// UID:0001LH | by-memory/0x005afe70-0x005afeee.SelectObjectWithKeyboardPaneForwardTabKey.md | Completion:88 | Confidence:90
bool SelectObjectWithKeyboardPane::ForwardTabKey(KeyEvent *event)
{
    if (event->kind == kTargetSelectionKeyEvent) {
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
        if (target != NULL) {
            g_activeMapPane->m_targetSelectionActive = true;
            g_activeMapPane->m_targetSelectionObject = target;
            g_activeMapPane->m_targetSelectionFilter = -1;
            s_selectObjectTargetModeActive = true;
        }

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    }

    const unsigned char savedKey = event->key;
    event->key = kKeyTab;
    const bool handled = LineInputPane::OnKeyEvent(event);
    event->key = savedKey;
    return handled;
}

// UID:0003J6 | by-memory/0x00630b10-0x00630b78.SelectObjectKeyboardPromptString.md | Completion:86 | Confidence:92
// Prompt literal is emitted inline by [UID:0001LB][0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor](by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md).

// UID:0000DM | by-class/SpellInputPaneState.md | Completion:87 | Confidence:90
// SpellInputPaneState is declared by this page's formal H; [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) emits the method body.
// UID:0001II | by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md | Completion:92 | Confidence:94
void SpellInputPaneState::SetInputModeFlag(bool active)
{
    m_spellInputActive = active;
}

// UID:0000DX | by-class/SpellWhoInputPane.md | Completion:87 | Confidence:88
#include "TargetSelectionInputPanes.h"

// UID:0001KX | by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md | Completion:88 | Confidence:90
SpellWhoInputPane::SpellWhoInputPane(char spellIndex)
    : LineInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_spellWhoTargetId = target->ObjectId();
}

// UID:0001KZ | by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md | Completion:88 | Confidence:90
SpellWhoInputPane::~SpellWhoInputPane()
{
    if (g_targetInputStateUsesItemWho) {
        ItemWhoInputPaneState *state =
            static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3));
        if (state != NULL)
            state->SetInputModeFlag(false);
    } else {
        SpellInputPaneState *state =
            static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3));
        if (state != NULL)
            state->SetInputModeFlag(false);
    }
}

// UID:0001L0 | by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md | Completion:88 | Confidence:90
bool SpellWhoInputPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = NarrowKey(event->key);
    const unsigned char flags = event->modifierFlags;

    if ((flags & 0x03) != 0)
        return true;

    if (key == kKeyEnter) {
        if (event->kind == kKeyPressed) {
            LivingObjectPane *target =
                g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
            if (target != NULL) {
                ClearSpellWhoTarget();

                ObjectListPosition position;
                target->GetObjectListPosition(&position);
                SendTargetedActionPacket(m_spellIndex, target->ObjectId(),
                    position.x, position.y);
            }
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kKeyEscape) {
        if (event->kind == kKeyPressed) {
            LivingObjectPane *target =
                g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
            if (target != NULL)
                ClearSpellWhoTarget();
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (event->kind != kKeyPressed)
        return true;

    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);

    if (key == kKeySelfTarget) {
        LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
        if (current != selfTarget) {
            if (current != NULL)
                current->SetTargetHighlight(false);
            selfTarget->SetTargetHighlight(true);
            s_spellWhoTargetId = selfTarget->ObjectId();
        }
        return true;
    }

    const TargetTraversalOrder *order =
        ((flags & 0x04) != 0)
            ? &g_pConfig->alternateTargetTraversalOrder
            : &g_pConfig->targetTraversalOrder;

    int traversalDirection;
    if (order->first == 1) {
        if (order->second == 1) {
            traversalDirection = -1;
        } else if (order->second == 0) {
            traversalDirection = 0;
        } else {
            return true;
        }
    } else {
        if (order->first != 0 || order->second != 1)
            return true;
        traversalDirection = 1;
    }

    LivingObjectPane *nextTarget = NULL;
    if (IsPreviousTargetKey(key)) {
        nextTarget = current != NULL
            ? g_activeMapPane->FindPreviousSelectableObject(current, traversalDirection)
            : g_pUserPane->GetLocalPlayerObject();
    } else if (IsNextTargetKey(key)) {
        nextTarget = current != NULL
            ? g_activeMapPane->FindNextSelectableObject(current, traversalDirection)
            : g_pUserPane->GetLocalPlayerObject();
    } else {
        return true;
    }

    if (nextTarget == current)
        return true;

    if (current != NULL)
        current->SetTargetHighlight(false);

    if (nextTarget != NULL) {
        nextTarget->SetTargetHighlight(true);
        s_spellWhoTargetId = nextTarget->ObjectId();
    } else {
        s_spellWhoTargetId = 0;
    }

    return true;
}

// UID:0001L1 | by-memory/0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput.md | Completion:88 | Confidence:90
bool SpellWhoInputPane::OnMouseEvent(MouseEvent *event)
{
    if (event->kind != kMouseTargetChange &&
        event->kind != kMouseTargetConfirm) {
        return false;
    }

    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    g_activeMapPane->GetBoundsRect(&mapRect);
    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);

    if (event->kind == kMouseTargetConfirm) {
        if (current == NULL || !PointInRect(mapX, mapY, mapRect))
            return false;

        current->SetTargetHighlight(false);
        g_pUserPane->ClearPendingTargetObject();

        ObjectListPosition position;
        current->GetObjectListPosition(&position);
        SendTargetedActionPacket(m_spellIndex, current->ObjectId(),
            position.x, position.y);

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return true;
    }

    LivingObjectPane *hitTarget =
        g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

    if (hitTarget != NULL && hitTarget != current) {
        if (current != NULL)
            current->SetTargetHighlight(false);
        hitTarget->SetTargetHighlight(true);
        s_spellWhoTargetId = hitTarget->ObjectId();

        if (g_pConfig->doubleClick)
            return true;

        if (current == NULL)
            return false;

        ClearSpellWhoTarget();
        g_pUserPane->ClearPendingTargetObject();

        ObjectListPosition position;
        hitTarget->GetObjectListPosition(&position);
        SendTargetedActionPacket(m_spellIndex, hitTarget->ObjectId(),
            position.x, position.y);

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return true;
    }

    if (!PointInRect(mapX, mapY, mapRect))
        return false;

    if (g_pConfig->doubleClick || current == NULL)
        return true;

    ClearSpellWhoTarget();
    g_pUserPane->ClearPendingTargetObject();

    ObjectListPosition position;
    current->GetObjectListPosition(&position);
    SendTargetedActionPacket(m_spellIndex, current->ObjectId(),
        position.x, position.y);

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    return true;
}

// UID:0001L2 | by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md | Completion:88 | Confidence:90
bool SpellWhoInputPane::OnObjectListMessage(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload == NULL || payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    bool containsCurrentTarget = false;

    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);
        if (objectId == s_spellWhoTargetId) {
            containsCurrentTarget = true;
            break;
        }
    }

    if (!containsCurrentTarget)
        return false;

    LivingObjectPane *oldTarget =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
    LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();

    s_spellWhoTargetId = selfTarget->ObjectId();

    if (oldTarget != NULL)
        oldTarget->SetTargetHighlight(false);

    selfTarget->SetTargetHighlight(true);
    return false;
}

// UID:0000ED | by-class/TargetObjectWithKeyboardPane.md | Completion:87 | Confidence:88
// No standalone TargetObjectWithKeyboardPane class-level source body; exact method and helper children emit this class.
// UID:0001LI | by-memory/0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor.md | Completion:88 | Confidence:92
TargetObjectWithKeyboardPane::TargetObjectWithKeyboardPane()
    : LineInputPane(NULL)
{
    s_activeTargetObjectWithKeyboardPane = this;

    SetPromptText(L"Use arrow key to select target then press 'v'.");

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_targetObjectTargetId = target->ObjectId();

    SetPaneOrder(NULL, g_pBackPane);
    s_targetObjectTargetModeActive = false;
}

// UID:0001LJ | by-memory/0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor.md | Completion:88 | Confidence:91
TargetObjectWithKeyboardPane::~TargetObjectWithKeyboardPane()
{
    s_activeTargetObjectWithKeyboardPane = NULL;
}

// UID:0001LK | by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md | Completion:88 | Confidence:90
bool TargetObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = NarrowKey(event->key);

    if ((event->modifierFlags & 0x03) != 0)
        return true;

    switch (key) {
    case kKeyEscape:
    case kKeySpace:
        if (event->kind == kTargetSelectionKeyEvent) {
            if (g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId) != NULL)
                ClearCurrentTarget();
            s_targetObjectTargetModeActive = false;
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        }
        event->key = kKeyEscape;
        LineInputPane::OnKeyEvent(event);
        event->key = key;
        return false;

    case 'v':
        if (!g_pConfig->tabVSwap)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeyTab:
        if (g_pConfig->tabVSwap)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeySelfTarget:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
            if (oldTarget != selfTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                selfTarget->SetTargetHighlight(true);
                s_targetObjectTargetId = selfTarget->GetObjectId();
            }
        }
        return true;

    case 'h':
    case 'k':
    case kKeyPrevA:
    case kKeyPrevB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *newTarget;
            if (oldTarget != NULL) {
                newTarget = g_activeMapPane->FindPreviousSelectableObject(oldTarget);
            } else {
                newTarget = g_pUserPane->GetLocalPlayerObject();
            }

            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_targetObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_targetObjectTargetId = 0;
                }
            }
        }
        return true;

    case 'j':
    case 'l':
    case kKeyNextA:
    case kKeyNextB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *newTarget;
            if (oldTarget != NULL) {
                newTarget = g_activeMapPane->FindNextSelectableObject(oldTarget);
            } else {
                newTarget = g_pUserPane->GetLocalPlayerObject();
            }

            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_targetObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_targetObjectTargetId = 0;
                }
            }
        }
        return true;
    }

    return true;
}

// UID:0001LL | by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md | Completion:88 | Confidence:90
bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)
{
    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    LivingObjectPane *targetToConfirm = NULL;

    if (event->kind == kMouseTargetConfirm) {
        g_activeMapPane->GetBoundsRect(&mapRect);
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);

        if (!PointInRect(mapX, mapY, mapRect) || target == NULL)
            return false;

        targetToConfirm = target;
    } else if (event->kind == kMouseTargetChange) {
        LivingObjectPane *oldTarget =
            g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
        LivingObjectPane *hitTarget = g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

        if (hitTarget != NULL) {
            if (hitTarget != oldTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                hitTarget->SetTargetHighlight(true);
                s_targetObjectTargetId = hitTarget->GetObjectId();

                if (g_pConfig->doubleClick)
                    return true;
                if (oldTarget == NULL)
                    return false;

                targetToConfirm = hitTarget;
            } else {
                if (g_pConfig->doubleClick)
                    return true;
                if (oldTarget == NULL)
                    return false;

                targetToConfirm = oldTarget;
            }
        } else {
            g_activeMapPane->GetBoundsRect(&mapRect);
            if (!PointInRect(mapX, mapY, mapRect))
                return false;

            if (g_pConfig->doubleClick || oldTarget == NULL)
                return true;

            targetToConfirm = oldTarget;
        }
    } else {
        return false;
    }

    ClearCurrentTarget();
    g_pUserPane->ClearPendingTargetObject();
    g_activeMapPane->InteractWithObject(targetToConfirm);
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    g_pUserPane->ClearPendingTargetObject();

    if (g_pChattingHandlePane != NULL && g_pChattingHandlePane->m_chatTargetPending) {
        g_pUserPane->ClearChatTargetState();
        if (g_pChattingVarietyPane != NULL)
            g_pChattingVarietyPane->RefreshAfterTargetSelection();
    }

    return true;
}

// UID:00036R | by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md | Completion:88 | Confidence:90
bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);

        if (objectId == s_targetObjectTargetId) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *localPlayer = g_pUserPane->GetLocalPlayerObject();

            s_targetObjectTargetId = localPlayer->GetObjectId();
            oldTarget->SetTargetHighlight(false);
            localPlayer->SetTargetHighlight(true);
            break;
        }
    }

    return false;
}

// UID:00036S | by-memory/0x005b05b0-0x005b05cf.TargetObjectWithKeyboardPaneClearCurrentTarget.md | Completion:88 | Confidence:90
void TargetObjectWithKeyboardPane::ClearCurrentTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}

// UID:00040Y | by-memory/0x005b05d0-0x005b0638.TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper.md | Completion:88 | Confidence:90
// Emitted code for this range is covered by [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md).

// UID:00040Z | by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md | Completion:88 | Confidence:89
// Emitted code for this range is covered by [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md).

// UID:000410 | by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md | Completion:88 | Confidence:89
// Emitted code for this range is covered by [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md).

// UID:00036U | by-memory/0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper.md | Completion:88 | Confidence:90
bool TargetObjectWithKeyboardPane::ForwardTabKey(KeyEvent *event)
{
    if (event->kind == kTargetSelectionKeyEvent) {
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
        if (target != NULL) {
            g_activeMapPane->m_targetSelectionActive = true;
            g_activeMapPane->m_targetSelectionObject = target;
            g_activeMapPane->m_targetSelectionFilter = target->GetTargetFilter();
            s_targetObjectTargetModeActive = true;
            s_targetObjectPreviousTargetId = s_targetObjectTargetId;
        }

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    }

    const unsigned char savedKey = event->key;
    event->key = kKeyTab;
    const bool handled = LineInputPane::OnKeyEvent(event);
    event->key = savedKey;
    return handled;
}

// UID:0003J7 | by-memory/0x00630b78-0x00630bd8.TargetObjectKeyboardPromptString.md | Completion:86 | Confidence:92
// Prompt literal is emitted inline by [UID:0001LI][0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor](by-memory/0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor.md).

// UID:0004R4 | by-memory/0x005ad450-0x005ad4ff.ToggleTargetSelectionPane.md | Completion:90 | Confidence:93
void ToggleTargetSelectionPane(bool)
{
    if (!g_activeMapPane->m_selectedObjectActive)
    {
        new SelectObjectWithKeyboardPane();
        return;
    }

    g_activeMapPane->m_selectedObjectActive = false;
    if (g_activeMapPane->m_selectedObjectPane != NULL)
        g_activeMapPane->m_selectedObjectPane->SetTargetHighlight(false);
    g_activeMapPane->m_selectedObjectPane = NULL;
    g_activeMapPane->m_selectedObjectDirection = -1;
    g_selectObjectTargetModeActive = false;
    g_targetObjectTargetModeActive = false;
}

// UID:0004R5 | by-memory/0x005ad500-0x005ad660.NavigateTargetSelection.md | Completion:90 | Confidence:93
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer)
{
    if (g_pConfig->m_targetSelectionSuppressed)
        return;

    if (g_activeMapPane->m_selectedObjectActive)
    {
        if (g_selectObjectTargetModeActive)
        {
            g_activeMapPane->m_selectedObjectActive = false;
            if (g_activeMapPane->m_selectedObjectPane != NULL)
                g_activeMapPane->m_selectedObjectPane
                    ->SetTargetHighlight(false);
            g_activeMapPane->m_selectedObjectPane = NULL;
            g_selectObjectTargetModeActive = false;
            g_targetObjectTargetModeActive = false;
            return;
        }

        LivingObjectPane *oldSelection =
            g_activeMapPane->m_selectedObjectPane;
        LivingObjectPane *newSelection = previous
            ? g_activeMapPane->FindPreviousLivingTarget(
                oldSelection, g_activeMapPane->m_selectedObjectDirection)
            : g_activeMapPane->FindNextLivingTarget(
                oldSelection, g_activeMapPane->m_selectedObjectDirection);

        if (oldSelection != NULL)
            oldSelection->SetTargetHighlight(false);
        if (newSelection != NULL)
            newSelection->SetTargetHighlight(true);
        g_activeMapPane->m_selectedObjectPane = newSelection;
        s_targetObjectTargetId =
            newSelection != NULL ? newSelection->m_objectId : 0;
        return;
    }

    LivingObjectPane *selection = g_pUserPane;
    int direction = 0;
    if (!chooseLocalPlayer)
    {
        LivingObjectPane *candidate =
            g_activeMapPane->FindNextLivingTarget(g_pUserPane, 1);
        if (candidate != NULL && candidate != g_pUserPane)
        {
            selection = candidate;
            direction = 1;
        }
    }

    if (selection != NULL)
        selection->SetTargetHighlight(true);
    g_activeMapPane->m_selectedObjectActive = true;
    g_activeMapPane->m_selectedObjectPane = selection;
    g_activeMapPane->m_selectedObjectDirection = direction;
    g_targetObjectTargetModeActive = true;
    s_targetObjectPreviousTargetId = -1;
    s_targetObjectTargetId = selection != NULL ? selection->m_objectId : 0;
}

// UID:0004R6 | by-memory/0x005ad660-0x005ad719.ReverseTargetSelectionDirection.md | Completion:90 | Confidence:93
void ReverseTargetSelectionDirection()
{
    if (g_selectObjectTargetModeActive ||
        g_activeMapPane->m_selectedObjectDirection == -1)
    {
        return;
    }

    g_activeMapPane->m_selectedObjectDirection =
        !g_activeMapPane->m_selectedObjectDirection;
    LivingObjectPane *oldSelection =
        g_activeMapPane->m_selectedObjectPane;
    if (oldSelection == NULL)
        return;

    LivingObjectPane *newSelection;
    if (s_targetObjectPreviousTargetId != -1)
    {
        newSelection = g_activeMapPane->FindObjectPaneById(
            s_targetObjectPreviousTargetId);
    }
    else
    {
        newSelection = g_activeMapPane->FindNextLivingTarget(
            oldSelection, g_activeMapPane->m_selectedObjectDirection);
    }

    oldSelection->SetTargetHighlight(false);
    if (newSelection != NULL)
        newSelection->SetTargetHighlight(true);
    g_activeMapPane->m_selectedObjectPane = newSelection;
    s_targetObjectPreviousTargetId =
        newSelection != NULL ? (int)oldSelection->m_objectId : -1;
    s_targetObjectTargetId =
        newSelection != NULL ? newSelection->m_objectId : 0;
}

// UID:0001L3 | by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md | Completion:88 | Confidence:90
static void ClearSpellWhoTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}

// UID:0001L7 | by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md | Completion:88 | Confidence:90
static void ClearItemWhoTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}

// UID:0002A9 | by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md | Completion:91 | Confidence:93
bool g_selectObjectTargetModeActive = false;
bool g_targetObjectTargetModeActive = false;

// UID:0002A2 | by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md | Completion:90 | Confidence:92
SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane = NULL;
static TargetObjectWithKeyboardPane *s_activeTargetObjectWithKeyboardPane = NULL;
