// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OR
// Source by-file doc: by-file/Thread.md
// UID:0000EV | by-class/Thread.md | Completion:93 | Confidence:94
#include "Thread.h"
#include "Singleton.h"

// UID:0000WL | by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md | Completion:88 | Confidence:90
void Thread::OnWaitObject(int)
{
}

// UID:0000EW | by-class/ThreadMan.md | Completion:92 | Confidence:94
class Thread;
class List;
struct ThreadManWatchRecord;

class ThreadMan : public LObject, public Singleton<ThreadMan>
{
public:
    ThreadMan();
    virtual ~ThreadMan();

    void RegisterThread(Thread *thread, void *context);
    void UnregisterThread(Thread *thread);
    void ClearThreadProbe(Thread *thread);
    void MarkCurrentThreadBlocked();
    void ClearCurrentThreadBlocked();

private:
    void RunMessagePump();

    int  FindWatchRecordByThread(Thread *thread) const;
    int  FindWatchRecordByThreadId(DWORD threadId) const;
    void ScanWatchList();
    void CheckWatchRecordTimeout(ThreadManWatchRecord *record);
    void AddWatchRecord(Thread *thread, void *context);
    void RemoveWatchRecord(Thread *thread);
    void ClearWatchRecordProbe(Thread *thread);
    void MarkThreadIdBlocked(DWORD threadId);
    void ClearThreadIdBlocked(DWORD threadId);

    bool   m_isDebuggerPresent;
    HANDLE m_workerThreadHandle;
    DWORD  m_workerThreadId;
    List  *m_watchList;
};

// UID:0000SH | by-global/g_pThreadMan.md | Completion:92 | Confidence:94
static ThreadMan *g_pThreadMan = NULL;

template <>
Singleton<ThreadMan>::Singleton()
{
    g_pThreadMan = static_cast<ThreadMan *>(this);
}

template <>
Singleton<ThreadMan>::~Singleton()
{
    g_pThreadMan = NULL;
}

// UID:000305 | by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md | Completion:92 | Confidence:94
// Exact storage and lifetime source for g_pThreadMan are emitted once by
// UID0000SH through the ThreadMan source stream; this address-only page does
// not emit a duplicate definition.

// UID:0001K0 | by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md | Completion:91 | Confidence:94
ThreadMan::ThreadMan()
    : m_isDebuggerPresent(false),
      m_workerThreadHandle(NULL),
      m_workerThreadId(0),
      m_watchList(NULL)
{
    HMODULE kernel32 = LoadLibraryW(L"KERNEL32.DLL");
    if (kernel32 != NULL)
    {
        typedef BOOL (WINAPI *IsDebuggerPresentProc)();
        IsDebuggerPresentProc isDebuggerPresent =
            reinterpret_cast<IsDebuggerPresentProc>(GetProcAddress(kernel32, "IsDebuggerPresent"));
        if (isDebuggerPresent != NULL)
            m_isDebuggerPresent = (isDebuggerPresent() != FALSE);
        FreeLibrary(kernel32);
    }

    m_watchList = new List(sizeof(ThreadManWatchRecord), 16);
    m_workerThreadHandle = CreateThread(NULL, 0, ThreadManWorkerEntry, this, 0, &m_workerThreadId);
    if (m_workerThreadHandle == NULL)
        throw Win32Error();
}

// UID:0001K1 | by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md | Completion:90 | Confidence:93
ThreadMan::~ThreadMan()
{
    if (m_workerThreadHandle != NULL)
    {
        TerminateThread(m_workerThreadHandle, 0);
        CloseHandle(m_workerThreadHandle);
        m_workerThreadHandle = NULL;
    }

    if (m_watchList != NULL)
    {
        delete m_watchList;
        m_watchList = NULL;
    }
}

void ThreadMan::RegisterThread(Thread *thread, void *context)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_REGISTER_THREAD,
                       reinterpret_cast<WPARAM>(thread),
                       reinterpret_cast<LPARAM>(context));
}

void ThreadMan::UnregisterThread(Thread *thread)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_UNREGISTER_THREAD,
                       reinterpret_cast<WPARAM>(thread), 0);
}

void ThreadMan::ClearThreadProbe(Thread *thread)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_CLEAR_THREAD_PROBE,
                       reinterpret_cast<WPARAM>(thread), 0);
}

void ThreadMan::MarkCurrentThreadBlocked()
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_MARK_THREAD_ID_BLOCKED,
                       GetCurrentThreadId(), 0);
}

void ThreadMan::ClearCurrentThreadBlocked()
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_CLEAR_THREAD_ID_BLOCKED,
                       GetCurrentThreadId(), 0);
}

// UID:0001K2 | by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md | Completion:89 | Confidence:88
void ThreadMan::RunMessagePump()
{
    MSG msg;

    for (;;)
    {
        DWORD result = MsgWaitForMultipleObjects(0, NULL, FALSE, 500, QS_ALLINPUT);
        if (result == WAIT_OBJECT_0)
        {
            while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
            {
                switch (msg.message)
                {
                case THREADMAN_REGISTER_THREAD:
                    AddWatchRecord(reinterpret_cast<Thread *>(msg.wParam),
                                   reinterpret_cast<void *>(msg.lParam));
                    break;

                case THREADMAN_UNREGISTER_THREAD:
                    RemoveWatchRecord(reinterpret_cast<Thread *>(msg.wParam));
                    break;

                case THREADMAN_CLEAR_THREAD_PROBE:
                    ClearWatchRecordProbe(reinterpret_cast<Thread *>(msg.wParam));
                    break;

                case THREADMAN_MARK_THREAD_ID_BLOCKED:
                    MarkThreadIdBlocked(static_cast<DWORD>(msg.wParam));
                    break;

                case THREADMAN_CLEAR_THREAD_ID_BLOCKED:
                    ClearThreadIdBlocked(static_cast<DWORD>(msg.wParam));
                    break;
                }
            }
        }
        else if (result == WAIT_TIMEOUT && !m_isDebuggerPresent)
        {
            ScanWatchList();
        }
    }
}


// UID:0001K5 | by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md | Completion:86 | Confidence:91
// Compiler-emitted scalar deleting destructor for ThreadMan; generated from
// virtual ~ThreadMan(), Singleton<ThreadMan> base destruction, and the ordinary
// destructor source, so no standalone handwritten body is emitted here.

// UID:0001SR | by-type/by-enum/ThreadManMessageId.md | Completion:88 | Confidence:91
enum ThreadManMessageId
{
    THREADMAN_REGISTER_THREAD         = WM_USER + 0x64, // 0x0464
    THREADMAN_UNREGISTER_THREAD       = WM_USER + 0x65, // 0x0465
    THREADMAN_CLEAR_THREAD_PROBE      = WM_USER + 0x66, // 0x0466
    THREADMAN_MARK_THREAD_ID_BLOCKED  = WM_USER + 0x67, // 0x0467
    THREADMAN_CLEAR_THREAD_ID_BLOCKED = WM_USER + 0x68  // 0x0468
};

// UID:0001WA | by-type/by-struct/ThreadManLayout.md | Completion:90 | Confidence:94
// ThreadMan object layout is emitted by [UID:0000EW][ThreadMan](by-class/ThreadMan.md) ThreadMan class declaration;
// this page supplies offset evidence only and should not emit a duplicate type.

// UID:0001WB | by-type/by-struct/ThreadManWatchRecord.md | Completion:88 | Confidence:90
struct ThreadManWatchRecord
{
    Thread *thread;
    void   *context;
    DWORD   watchedThreadId;
    bool    probePending;
    DWORD   deadlineTick;
};


// UID:0004CI | by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md | Completion:88 | Confidence:89
void Thread::WaitForQueueDrain()
{
    HANDLE event = CreateEventW(NULL, TRUE, FALSE, NULL);

    ThreadResultEntry entry;
    entry.event = event;
    entry.result = 0;

    m_resultGate->Lock();
    m_resultList->Add(&entry);
    m_resultGate->Unlock();

    ThreadMessage message;
    message.messageId = 2;
    message.arg1 = 0;
    message.arg2 = 0;
    message.resultEvent = event;
    message.syncArg1 = 0;
    message.syncArg2 = 0;

    m_messageQueue->Push(&message);
    ReleaseSemaphore(m_waitHandles[0], 1, NULL);

    WaitForSingleObject(event, INFINITE);

    m_resultGate->Lock();
    for (int i = 0; i < m_resultList->GetCount(); ++i)
    {
        ThreadResultEntry *current =
            static_cast<ThreadResultEntry *>(m_resultList->GetAt(i));
        if (current->event == event)
        {
            m_resultList->RemoveAt(i);
            break;
        }
    }
    m_resultGate->Unlock();

    CloseHandle(event);
}

// UID:0004CJ | by-memory/0x00596760-0x005967c7.ThreadWaitForResult.md | Completion:88 | Confidence:89
int Thread::WaitForResult(HANDLE resultEvent)
{
    int result = reinterpret_cast<int>(resultEvent);

    WaitForSingleObject(resultEvent, INFINITE);

    m_resultGate->Lock();
    for (int i = 0; i < m_resultList->GetCount(); ++i)
    {
        ThreadResultEntry *entry =
            static_cast<ThreadResultEntry *>(m_resultList->GetAt(i));
        if (entry->event == resultEvent)
        {
            result = entry->result;
            m_resultList->RemoveAt(i);
            break;
        }
    }
    m_resultGate->Unlock();

    CloseHandle(resultEvent);
    return result;
}

// UID:0001JZ | by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md | Completion:89 | Confidence:90
HANDLE Thread::AddWaitHandle(HANDLE handle)
{
    const int index = static_cast<signed char>(m_waitHandleCount);
    m_waitHandles[index] = handle;
    ++m_waitHandleCount;
    return handle;
}

// UID:0004CK | by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md | Completion:89 | Confidence:90
void Thread::RemoveLastWaitHandle()
{
    --m_waitHandleCount;
    m_waitHandles[static_cast<signed char>(m_waitHandleCount)] = NULL;
}

// UID:0004CL | by-memory/0x00596810-0x00596915.ThreadProc.md | Completion:92 | Confidence:94
int Thread::ThreadProc()
{
    for (;;)
    {
        Sleep(1);

        DWORD waitIndex = WaitForMultipleObjects(
            m_waitHandleCount,
            m_waitHandles,
            FALSE,
            m_waitTimeout);

        if (waitIndex == WAIT_OBJECT_0)
        {
            OnDispatchBegin();

            RingBuffer *queue = NULL;
            if (!m_priorityQueue->IsEmpty())
                queue = m_priorityQueue;
            else if (!m_messageQueue->IsEmpty())
                queue = m_messageQueue;

            if (queue != NULL)
            {
                ThreadMessage message;
                queue->Dequeue(&message);

                if (message.resultEvent == NULL)
                {
                    OnMessage(message.messageId, message.arg1, message.arg2);
                }
                else
                {
                    int result = OnMessageEx(message.messageId,
                                             message.syncArg1,
                                             message.syncArg2,
                                             message.arg1,
                                             message.arg2);

                    m_resultMonitor->Lock();
                    int resultCount = m_resultList->GetCount();
                    for (int resultIndex = 0;
                         resultIndex < resultCount;
                         ++resultIndex)
                    {
                        ThreadResultEntry *entry =
                            static_cast<ThreadResultEntry *>(
                                m_resultList->GetElementAt(resultIndex));
                        if (entry->event == message.resultEvent)
                        {
                            entry->result = result;
                            break;
                        }
                    }
                    m_resultMonitor->Unlock();

                    SetEvent(message.resultEvent);
                }
            }
        }
        else if (waitIndex < m_waitHandleCount)
        {
            OnWaitObject(static_cast<int>(waitIndex));
        }

        if (m_stopRequested)
            return 0;

        OnIdle();
    }
}

// UID:0004CM | by-memory/0x00596920-0x00596931.ThreadOnMessage.md | Completion:90 | Confidence:91
void Thread::OnMessage(int messageId, int, int)
{
    if (messageId == 1)
        m_stopRequested = TRUE;
}

// UID:0004CN | by-memory/0x00596940-0x0059695e.ThreadOnMessageEx.md | Completion:90 | Confidence:91
int Thread::OnMessageEx(int messageId, int, int, int, int)
{
    if (messageId == 1)
        m_stopRequested = TRUE;

    return 0;
}

// UID:0004CO | by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md | Completion:89 | Confidence:90
BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)
{
    ThreadMessage message;
    message.messageId = messageId;
    message.arg1 = arg1;
    message.arg2 = arg2;
    message.resultEvent = NULL;
    message.syncArg1 = 0;
    message.syncArg2 = 0;

    m_messageQueue->Push(&message);
    return ReleaseSemaphore(m_waitHandles[0], 1, NULL);
}

// UID:0004CP | by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md | Completion:89 | Confidence:90
BOOL Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)
{
    ThreadMessage message;
    message.messageId = messageId;
    message.arg1 = arg1;
    message.arg2 = arg2;
    message.resultEvent = NULL;
    message.syncArg1 = 0;
    message.syncArg2 = 0;

    m_priorityQueue->Push(&message);
    return ReleaseSemaphore(m_waitHandles[0], 1, NULL);
}

// UID:0001K3 | by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md | Completion:89 | Confidence:88
static DWORD WINAPI ThreadManWorkerEntry(LPVOID parameter)
{
    try
    {
        static_cast<ThreadMan *>(parameter)->RunMessagePump();
    }
    catch (Error *error)
    {
        wchar_t text[0x800];
        error->CopyMessage(text, 0x800);
        MessageBoxW(NULL, text, L"Error", MB_OK);
        if (g_pApplication != NULL)
            g_pApplication->RequestExit();
        delete error;
    }

    return 0;
}

// UID:00026P | by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md | Completion:90 | Confidence:93
// Thread/ThreadMan RTTI, vtables, and local literals are regenerated from class
// declarations and method use sites; no standalone .rdata source declaration is
// emitted for this exact range.

// UID:0003V7 | by-memory\0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:0001JX | by-memory\0x00596250-0x0059756e.ThreadAndThreadMan.md | Completion:88 | Confidence:89 | Empty Emitter Marker
