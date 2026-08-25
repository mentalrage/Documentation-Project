// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LM
// Source by-file doc: by-file/MSGHandler.md
// UID:00008S | by-class/MSGHandler.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_APP_MSGHANDLER_H
#define NEXUSTK_APP_MSGHANDLER_H

#include <windows.h>

class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual LRESULT DispatchMessage(MSG *message);

private:
    MSGHandler *m_previousHandler;
};

#endif
