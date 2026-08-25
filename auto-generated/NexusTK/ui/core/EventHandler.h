// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0004ZN
// Source by-file doc: by-file/EventHandler.md
// UID:00004N | by-class/EventHandler.md | Completion:89 | Confidence:92
#ifndef NEXUSTK_UI_CORE_EVENTHANDLER_H
#define NEXUSTK_UI_CORE_EVENTHANDLER_H

#include "RectBounds.h"

class Event;
class EventDispatcher;

extern EventDispatcher *g_pEventDispatcher;

class EventHandler
{
public:
    EventHandler();
    virtual ~EventHandler();

    virtual bool HandlePointerOrMouseEvent(Event *event) = 0;
    virtual bool HandleKeyOrTextEvent(Event *event) = 0;
    virtual bool HandleImeEvent(Event *event) = 0;
    virtual bool HandlePacketEvent(Event *event) = 0;
    virtual bool HandleSystemOrControlEvent(Event *event) = 0;
    virtual bool HandleType19Event(Event *event) = 0;

    virtual bool ForwardHandlerOrder(EventHandler *first, EventHandler *second);
    virtual void GetLocalOffset(Point *offset);
    virtual void GetScreenOffset(Point *offset);
    virtual bool ShouldAcceptEvent() const;
};

typedef char EventHandlerSizeMustBe4[sizeof(EventHandler) == 4 ? 1 : -1];

#endif
