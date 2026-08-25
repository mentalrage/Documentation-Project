// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JM
// Source by-file doc: by-file/FrameMgr.md
// UID:00005G | by-class/FrameHandler.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_UI_CORE_FRAMEMGR_H
#define NEXUSTK_UI_CORE_FRAMEMGR_H

#include "../../util/LObject.h"
#include "../../util/Singleton.h"
#include <list>

struct FrameUpdateContext
{
    unsigned int callbackFrame;
    unsigned int currentFrame;
    bool dispatching;
};

class FrameHandler
{
public:
    virtual ~FrameHandler();

    void ScheduleNextFrame();
    void RemoveFrame();

protected:
    void ScheduleFrameCallback(int delayFrames);
    virtual void OnFrameUpdate(const FrameUpdateContext *context) = 0;
};

struct FrameScheduleEntry
{
    FrameHandler *handler;
    unsigned int dueFrame;
};

class FrameMgr;

typedef char FrameUpdateContextSizeMustBe12[
    sizeof(FrameUpdateContext) == 0x0c ? 1 : -1];
typedef char FrameScheduleEntrySizeMustBe8[
    sizeof(FrameScheduleEntry) == 0x08 ? 1 : -1];

// UID:0000Q0 | by-global/g_frameRegistry.md | Completion:93 | Confidence:94
extern FrameMgr *g_frameRegistry;

// UID:00005H | by-class/FrameMgr.md | Completion:94 | Confidence:94
class FrameMgr : public LObject, public Singleton<FrameMgr>
{
public:
    FrameMgr();
    void DispatchDueFrameCallbacks(unsigned int currentFrame);

private:
    friend class FrameHandler;

    void Insert(FrameHandler *handler, unsigned int dueFrame);
    void RemoveFrame(FrameHandler *handler);
    void AdvanceCallbackFrame(bool dispatching);

    FrameUpdateContext m_context;
    std::list<FrameScheduleEntry> m_callbacks;
};

typedef char FrameMgrSizeMustBe24[
    sizeof(FrameMgr) == 0x18 ? 1 : -1];

#endif
