// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OR
// Source by-file doc: by-file/Thread.md
// UID:0000EV | by-class/Thread.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UTIL_THREAD_H
#define NEXUSTK_UTIL_THREAD_H

#include <windows.h>
#include "LObject.h"

struct ThreadMessage
{
    int messageId;
    int arg1;
    int arg2;
    HANDLE resultEvent;
    int syncArg1;
    int syncArg2;
};

struct ThreadResultEntry
{
    HANDLE event;
    int result;
};

class RingBuffer;
class Monitor;
class List;

class Thread : public LObject
{
public:
    Thread(int messageCapacity);
    virtual ~Thread();

    virtual void StopThread();
    virtual void ForceTerminate();

    virtual void OnStart();
    virtual void OnThreadBegin();
    virtual int ThreadProc();
    virtual void OnThreadEnd();
    virtual void OnDispatchBegin();
    virtual void OnIdle();
    virtual void OnMessage(int messageId, int arg1, int arg2);
    virtual int OnMessageEx(int messageId, int syncArg1, int syncArg2,
                            int arg1, int arg2);
    virtual void OnWaitObject(int waitIndex);

    DWORD StartThread();
    DWORD SuspendThread();
    DWORD ResumeThread();

    void WaitForQueueDrain();
    int WaitForResult(HANDLE resultEvent);
    HANDLE AddWaitHandle(HANDLE handle);
    void RemoveLastWaitHandle();

    BOOL DispatchRequest(int messageId, int arg1, int arg2);
    BOOL DispatchPriorityRequest(int messageId, int arg1, int arg2);
    HANDLE DispatchRequestAndReturnEvent(int messageId, int syncArg1, int syncArg2, int arg1, int arg2);

private:
    static unsigned __stdcall ThreadEntry(void *context);

    DWORD m_waitTimeout;
    signed char m_waitHandleCount;
    HANDLE m_waitHandles[16];
    RingBuffer *m_messageQueue;
    RingBuffer *m_priorityQueue;
    Monitor *m_resultMonitor;
    List *m_resultList;
    HANDLE m_threadHandle;
    unsigned int m_threadId;
    unsigned char m_stopRequested;
};

#endif
