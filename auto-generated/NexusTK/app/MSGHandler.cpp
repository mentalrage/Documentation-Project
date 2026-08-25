// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LM
// Source by-file doc: by-file/MSGHandler.md
// UID:00008S | by-class/MSGHandler.md | Completion:94 | Confidence:95
#include "MSGHandler.h"
#include "Application.h"

// UID:0001CN | by-memory/0x00528d60-0x00528e55.MSGHandler.md | Completion:94 | Confidence:95
MSGHandler::MSGHandler()
    : m_previousHandler(g_pApplication->ExchangeMSGHandler(this))
{
}

MSGHandler::~MSGHandler()
{
    g_pApplication->ExchangeMSGHandler(m_previousHandler);
}

LRESULT MSGHandler::DispatchMessage(MSG *message)
{
    return m_previousHandler->DispatchMessage(message);
}

// UID:0002GL | by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md | Completion:94 | Confidence:95
// Emitted code for this compiler-generated vtable range is covered by [UID:00008S][MSGHandler](by-class/MSGHandler.md).
