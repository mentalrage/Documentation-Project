// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J7
// Source by-file doc: by-file/EventDispatcher.md
// UID:00004M | by-class/EventDispatcher.md | Completion:89 | Confidence:91
#include "../../util/TimerHandler.h"
#include "../../util/Tree.h"
#include "EventHandler.h"

class EventDispatcher : public TimerHandler
{
public:
    EventDispatcher();
    virtual ~EventDispatcher();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    bool SetPaneOrder(EventHandler *first, EventHandler *second,
                      bool placeAfter);
    bool DispatchEvent(Event *event);
    void ProcessIdleWork();
    void ArmTextInputGuardTimer();
    unsigned int CaptureIdleTickBaseline();

private:
    Tree<EventHandler *> m_handlerTree;
    EventHandler *m_activeHandler;
    EventHandler *m_contextHandler;
    EventHandler *m_currentHandler;
    void *m_modalHandlerList;
    int m_modalHandlerCount;
    bool m_textInputGuard;
    unsigned int m_idleTickBaseline;
    unsigned int m_lastDispatchedIdleSlice;
    bool m_cursorHideArmed;
    unsigned int m_cursorStillStartTick;
    unsigned int m_cursorHideDelayMs;
    int m_lastCursorX;
    int m_lastCursorY;
};

extern EventDispatcher *g_pEventDispatcher;

typedef char EventDispatcherSizeMustBe72[
    sizeof(EventDispatcher) == 0x48 ? 1 : -1];

[[No Children Attached]]
