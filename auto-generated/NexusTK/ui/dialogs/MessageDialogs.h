// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LA
// Source by-file doc: by-file/MessageDialogs.md
// UID:0000BE | by-class/PursuitMessageDialogPane.md | Completion:92 | Confidence:94
#include "DialogPane.h"

class Event;

class PursuitMessageDialogPane : public DialogPane
{
public:
    PursuitMessageDialogPane();
    virtual bool HandlePacketEvent(Event *event);

protected:
    void SendPreviousDialogPacket();
    void SendNextDialogPacket();
    void SendCurrentDialogPacket();

    unsigned char m_dialogType;
    unsigned int m_dialogId;
    unsigned short m_dialogState;
    unsigned short m_dialogPageIndex;
};
