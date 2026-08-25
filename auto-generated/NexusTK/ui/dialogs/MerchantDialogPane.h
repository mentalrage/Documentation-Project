// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L9
// Source by-file doc: by-file/MerchantDialogPane.md
// UID:000083 | by-class/MerchantDialogPane.md | Completion:94 | Confidence:94
#pragma once

#include "DialogPane.h"

class Event;

class MerchantDialogPane : public DialogPane
{
public:
    explicit MerchantDialogPane(unsigned char menuDialogType);
    virtual bool HandlePacketEvent(Event *event);

protected:
    void SendMenuRequestPacket();

    unsigned char m_menuDialogType;
    unsigned char m_reserved[3];
    unsigned int m_menuObjectId;
};
