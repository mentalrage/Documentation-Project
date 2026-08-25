// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JM
// Source by-file doc: by-file/FrameMgr.md
// UID:00005G | by-class/FrameHandler.md | Completion:94 | Confidence:94
#include "FrameMgr.h"

FrameHandler::~FrameHandler()
{
    g_frameRegistry->RemoveFrame(this);
}

void FrameHandler::ScheduleNextFrame()
{
    g_frameRegistry->Insert(this, g_frameRegistry->m_context.currentFrame + 1);
}

void FrameHandler::RemoveFrame()
{
    g_frameRegistry->RemoveFrame(this);
}

void FrameHandler::ScheduleFrameCallback(int delayFrames)
{
    g_frameRegistry->Insert(
        this, g_frameRegistry->m_context.callbackFrame + delayFrames);
}

// UID:0000Q0 | by-global/g_frameRegistry.md | Completion:93 | Confidence:94
// The declaration is emitted in FrameMgr.h; UID0002AT owns the definition.

// UID:0002AT | by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md | Completion:92 | Confidence:93
FrameMgr *g_frameRegistry;

template <>
Singleton<FrameMgr>::Singleton()
{
    g_frameRegistry = static_cast<FrameMgr *>(this);
}

template <>
Singleton<FrameMgr>::~Singleton()
{
    g_frameRegistry = 0;
}

// UID:00005H | by-class/FrameMgr.md | Completion:94 | Confidence:94
FrameMgr::FrameMgr()
{
    m_context.dispatching = false;
    m_context.callbackFrame = 0;
    m_context.currentFrame = 0;
}

void FrameMgr::Insert(FrameHandler *handler, unsigned int dueFrame)
{
    FrameScheduleEntry entry;
    entry.handler = handler;
    entry.dueFrame = dueFrame;

    std::list<FrameScheduleEntry>::iterator position = m_callbacks.begin();
    while (position != m_callbacks.end() &&
           position->dueFrame <= dueFrame) {
        ++position;
    }
    m_callbacks.insert(position, entry);
}

void FrameMgr::RemoveFrame(FrameHandler *handler)
{
    std::list<FrameScheduleEntry>::iterator position = m_callbacks.begin();
    while (position != m_callbacks.end()) {
        if (position->handler == handler)
            position = m_callbacks.erase(position);
        else
            ++position;
    }
}

void FrameMgr::DispatchDueFrameCallbacks(unsigned int currentFrame)
{
    const unsigned int previousFrame = m_context.currentFrame;
    m_context.currentFrame = currentFrame;
    if (previousFrame == currentFrame) {
        m_context.callbackFrame = currentFrame;
        return;
    }

    m_context.dispatching = true;
    while (!m_callbacks.empty() &&
           m_callbacks.front().dueFrame < currentFrame) {
        m_context.callbackFrame = m_callbacks.front().dueFrame;
        FrameHandler *handler = m_callbacks.front().handler;
        m_callbacks.pop_front();
        handler->OnFrameUpdate(&m_context);
    }

    m_context.dispatching = false;
    while (!m_callbacks.empty() &&
           m_callbacks.front().dueFrame == currentFrame) {
        m_context.callbackFrame = m_callbacks.front().dueFrame;
        FrameHandler *handler = m_callbacks.front().handler;
        m_callbacks.pop_front();
        handler->OnFrameUpdate(&m_context);
    }
    m_context.callbackFrame = currentFrame;
}

void FrameMgr::AdvanceCallbackFrame(bool dispatching)
{
    const unsigned int currentFrame = m_context.currentFrame;
    m_context.dispatching = dispatching;
    while (!m_callbacks.empty() &&
           m_callbacks.front().dueFrame <= currentFrame) {
        FrameHandler *handler = m_callbacks.front().handler;
        m_callbacks.pop_front();
        handler->OnFrameUpdate(&m_context);
    }
    ++m_context.callbackFrame;
}

// UID:00015M | by-memory\0x004b6cb0-0x004b7112.FrameScheduler.md | Completion:94 | Confidence:94 | Empty Emitter Marker

// UID:0002V3 | by-memory\0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md | Completion:89 | Confidence:94 | Empty Emitter Marker
