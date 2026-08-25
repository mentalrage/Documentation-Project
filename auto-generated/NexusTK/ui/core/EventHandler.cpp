// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0004ZN
// Source by-file doc: by-file/EventHandler.md
// UID:00004N | by-class/EventHandler.md | Completion:89 | Confidence:92
#include "EventHandler.h"
#include "EventDispatcher.h"

// UID:00014A | by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md | Completion:90 | Confidence:92
EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

bool EventHandler::HandlePointerOrMouseEvent(Event *event)
{
    return false;
}

bool EventHandler::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

bool EventHandler::HandleImeEvent(Event *event)
{
    return false;
}

bool EventHandler::HandlePacketEvent(Event *event)
{
    return false;
}

bool EventHandler::HandleType19Event(Event *event)
{
    return false;
}

bool EventHandler::HandleSystemOrControlEvent(Event *event)
{
    return false;
}

bool EventHandler::ForwardHandlerOrder(EventHandler *first, EventHandler *second)
{
    return g_pEventDispatcher->SetPaneOrder(first, second, false);
}

void EventHandler::GetLocalOffset(Point *offset)
{
    offset->y = 0;
    offset->x = 0;
}

void EventHandler::GetScreenOffset(Point *offset)
{
    offset->y = 0;
    offset->x = 0;
}

bool EventHandler::ShouldAcceptEvent() const
{
    return true;
}

// UID:0003I6 | by-memory\0x00619670-0x006196a0.EventHandlerVtableData.md | Completion:85 | Confidence:91 | Empty Emitter Marker
