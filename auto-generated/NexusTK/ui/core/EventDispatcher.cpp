// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J7
// Source by-file doc: by-file/EventDispatcher.md
// UID:00027B | by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md | Completion:90 | Confidence:91
static bool s_idleTimerSetupPending = true;

// UID:00004M | by-class/EventDispatcher.md | Completion:89 | Confidence:91
#include "BlackHole.h"
#include "EventDispatcher.h"
#include "FrameMgr.h"

[[No Children Attached]]

// UID:000060 | by-class/HandlerFindFunc.md | Completion:88 | Confidence:92
namespace {

class HandlerFindFunc : public TreeFindFunc<EventHandler *> {
public:
    explicit HandlerFindFunc(EventHandler *handler)
        : m_handler(handler)
    {
    }

    virtual bool IsMatch(EventHandler **candidate)
    {
        return *candidate == m_handler;
    }

private:
    EventHandler *m_handler;
};

}

[[No Children Attached]]

// UID:0000FA | by-class/TreeItor_near_class_EventHandler___.md | Completion:86 | Confidence:88
// TreeItor<EventHandler *> concrete-instantiation marker. Generic authored source
// is emitted by UID0004YK Tree.h; destructor/vtable glue is compiler-covered.
[[No Children Attached]]

// UID:0000F8 | by-class/Tree_near_class_EventHandler___.md | Completion:88 | Confidence:91
// Tree<EventHandler *> concrete-instantiation marker. Generic authored source is
// emitted by UID0004YK Tree.h; vector/destructor/vtable glue is compiler-covered.
[[No Children Attached]]

// UID:000141 | by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md | Completion:87 | Confidence:91
// EventDispatcher aggregate range marker for 0x004a6a80-0x004a82a9.
// Exact constructor, routing, idle-worker, traversal, destructor, and support helper bodies
// are represented by narrower child pages; do not emit a monolithic aggregate body here.
[[No Children Attached]]

// UID:000142 | by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md | Completion:89 | Confidence:91
void EventDispatcher::ProcessIdleWork()
{
    g_pApplicationCleanupQueue->ReleaseQueuedOwnedObjects();

    if (s_idleTimerSetupPending) {
        g_pTimerMgr->BeginTimerPeriod();
    }

    g_pTimerMgr->DispatchDueTimers();
    RebuildHandlerTraversalOrder();

    unsigned int tickBaseline;
    unsigned int lastDispatchedSlice;
    if (s_idleTimerSetupPending) {
        g_pTimerMgr->RefreshCurrentTick();
        s_idleTimerSetupPending = false;
        tickBaseline = g_pTimerMgr->m_currentTick;
        m_idleTickBaseline = tickBaseline;
        m_lastDispatchedIdleSlice = 0;
        lastDispatchedSlice = 0;
    } else {
        tickBaseline = m_idleTickBaseline;
        lastDispatchedSlice = m_lastDispatchedIdleSlice;
    }

    unsigned int currentSlice = (g_pTimerMgr->m_currentTick - tickBaseline) / 20;
    if (lastDispatchedSlice != currentSlice) {
        g_frameRegistry->DispatchDueFrameCallbacks(currentSlice);
        m_lastDispatchedIdleSlice = currentSlice;
    }
}

// UID:000143 | by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md | Completion:90 | Confidence:92
unsigned int EventDispatcher::CaptureIdleTickBaseline()
{
    m_idleTickBaseline = g_pTimerMgr->m_currentTick;
    return m_idleTickBaseline;
}

// UID:000144 | by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md | Completion:89 | Confidence:92
static bool FindEnabledHandlerRecordIterator(EventHandler *handler,
                                             TreeItor<EventHandler *> *iterator)
{
    HandlerFindFunc match(handler);
    return iterator->GetTree()->Find(&match, iterator);
}

// UID:000145 | by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md | Completion:90 | Confidence:92
/* Superseded hand-lowered std::vector instance retained as historical evidence.
static EventHandlerRecord *InsertHandlerRecord(
    EventHandlerRecordVector *records,
    EventHandlerRecord *insertAt,
    const EventHandlerRecord *source)
{
    int insertIndex = static_cast<int>(insertAt - records->begin);
    int count = GetHandlerRecordCount(records);
    if (count == static_cast<int>(kMaxHandlerRecordCount)) {
        _invalid_parameter_noinfo_noreturn();
    }

    int requestedCount = count + 1;
    unsigned int oldCapacity = static_cast<unsigned int>(GetHandlerRecordCapacity(records));
    unsigned int growBy = oldCapacity / 2;
    unsigned int newCapacity = requestedCount;
    if (oldCapacity <= kMaxHandlerRecordCount - growBy) {
        newCapacity = oldCapacity + growBy;
        if (newCapacity < static_cast<unsigned int>(requestedCount)) {
            newCapacity = static_cast<unsigned int>(requestedCount);
        }
    }

    EventHandlerRecord *newBegin = AllocateHandlerRecordBuffer(newCapacity);
    EventHandlerRecord *newRecord = newBegin + insertIndex;

    if (insertIndex != 0) {
        memmove(newBegin, records->begin, insertIndex * sizeof(EventHandlerRecord));
    }

    *newRecord = *source;

    if (insertAt != records->end) {
        memmove(newRecord + 1, insertAt, (records->end - insertAt) * sizeof(EventHandlerRecord));
    }

    RebindHandlerRecordVectorStorage(records, newBegin, requestedCount, static_cast<int>(newCapacity));
    return records->begin + insertIndex;
}
*/
// Compiler-covered std::vector<TreeNode<EventHandler *> > insert/growth instance.

// UID:000146 | by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md | Completion:88 | Confidence:92
// Split/index marker for EventDispatcher handler-tree support at 0x004a7cd0-0x004a7df4.
// Generic Tree/Event iterator source is represented by UID0004YK Tree.h.
// HandlerFindFunc and handler-list behavior remain dispatcher-local; destructors are compiler glue.
// Do not emit a synthetic monolithic body for this mixed destructor/thunk/predicate/wrapper island.

// UID:000147 | by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md | Completion:89 | Confidence:92
struct EventHandlerList {
    EventHandlerListNode *head;
    int count;
};

static void DestroyEventHandlerList(EventHandlerList *list)
{
    EventHandlerListNode *head = list->head;
    EventHandlerListNode *node = head->next;

    head->next = head;
    head->previous = head;
    list->count = 0;

    while (node != head) {
        EventHandlerListNode *next = node->next;
        operator delete(node);
        node = next;
    }

    operator delete(head);
}

// UID:00022A | by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md | Completion:88 | Confidence:92
#include "EventDispatcher.h"
#include <deque>

/* Superseded UID0004YK hand-lowered generic Tree/std::vector draft retained
   as historical evidence only; it is intentionally non-compiling source.

static const int kNoHandlerRecord = -1;
static const unsigned int kMaxHandlerRecordCount = 0x09249249u;

struct EventHandlerIterator {
    void *vtable;
    EventHandlerTree *tree;
    int index;
};

struct EventHandlerListNode {
    EventHandlerListNode *next;
    EventHandlerListNode *previous;
    EventHandler *handler;
};

static EventHandlerRecord *AllocateHandlerRecordBuffer(unsigned int count);
static void _invalid_parameter_noinfo_noreturn();

static int GetHandlerRecordCount(const EventHandlerRecordVector *records)
{
    return static_cast<int>(records->end - records->begin);
}

static int GetHandlerRecordCapacity(const EventHandlerRecordVector *records)
{
    return static_cast<int>(records->capacityEnd - records->begin);
}

static EventHandlerRecord *InsertHandlerRecord(
    EventHandlerRecordVector *records,
    EventHandlerRecord *insertAt,
    const EventHandlerRecord *source);

static void AppendHandlerRecord(EventHandlerRecordVector *records, const EventHandlerRecord *source)
{
    if (records->end == records->capacityEnd) {
        InsertHandlerRecord(records, records->end, source);
        return;
    }

    *records->end = *source;
    ++records->end;
}

static void InsertFirstChildHandlerRecord(
    EventHandlerTree *tree,
    const EventHandlerIterator *parent,
    EventHandler *handler)
{
    EventHandlerRecordVector *records = &tree->records;
    int newIndex = GetHandlerRecordCount(records);
    EventHandlerRecord *parentRecord = records->begin + parent->index;

    parentRecord->firstChildIndex = newIndex;
    parentRecord->lastChildIndex = newIndex;

    EventHandlerRecord record;
    record.parentIndex = parent->index;
    record.firstChildIndex = kNoHandlerRecord;
    record.lastChildIndex = kNoHandlerRecord;
    record.previousSiblingIndex = kNoHandlerRecord;
    record.nextSiblingIndex = kNoHandlerRecord;
    record.handler = handler;
    record.isDisabled = 0;
    record.reserved[0] = 0;
    record.reserved[1] = 0;
    record.reserved[2] = 0;

    AppendHandlerRecord(records, &record);
}

static void InsertHandlerRecordAfterSibling(
    EventHandlerTree *tree,
    const EventHandlerIterator *sibling,
    EventHandler *handler)
{
    EventHandlerRecordVector *records = &tree->records;
    int newIndex = GetHandlerRecordCount(records);
    EventHandlerRecord *siblingRecord = records->begin + sibling->index;
    int oldNext = siblingRecord->nextSiblingIndex;

    siblingRecord->nextSiblingIndex = newIndex;
    if (oldNext == kNoHandlerRecord && siblingRecord->parentIndex != kNoHandlerRecord) {
        records->begin[siblingRecord->parentIndex].lastChildIndex = newIndex;
    }

    EventHandlerRecord record;
    record.parentIndex = siblingRecord->parentIndex;
    record.firstChildIndex = kNoHandlerRecord;
    record.lastChildIndex = kNoHandlerRecord;
    record.previousSiblingIndex = sibling->index;
    record.nextSiblingIndex = oldNext;
    record.handler = handler;
    record.isDisabled = 0;
    record.reserved[0] = 0;
    record.reserved[1] = 0;
    record.reserved[2] = 0;

    AppendHandlerRecord(records, &record);
}

static void RemoveHandlerRecordAndDisableSubtree(
    EventHandlerTree *tree,
    const EventHandlerIterator *iterator)
{
    EventHandlerRecordVector *records = &tree->records;
    std::deque<int> pending;

    pending.push_back(iterator->index);
    while (!pending.empty()) {
        int recordIndex = pending.back();
        pending.pop_back();

        EventHandlerRecord *record = records->begin + recordIndex;
        record->isDisabled = 1;

        for (int childIndex = record->firstChildIndex;
             childIndex != kNoHandlerRecord;
             childIndex = records->begin[childIndex].nextSiblingIndex) {
            pending.push_back(childIndex);
        }
    }

    EventHandlerRecord *record = records->begin + iterator->index;
    int previous = record->previousSiblingIndex;

    if (previous == kNoHandlerRecord && record->parentIndex != kNoHandlerRecord) {
        records->begin[record->parentIndex].firstChildIndex = record->nextSiblingIndex;
        previous = record->previousSiblingIndex;
    }

    int next = record->nextSiblingIndex;

    if (next == kNoHandlerRecord && record->parentIndex != kNoHandlerRecord) {
        records->begin[record->parentIndex].lastChildIndex = record->previousSiblingIndex;
        previous = record->previousSiblingIndex;
        next = record->nextSiblingIndex;
    }

    if (previous != kNoHandlerRecord) {
        records->begin[previous].nextSiblingIndex = next;
    }

    if (next != kNoHandlerRecord) {
        records->begin[next].previousSiblingIndex = record->previousSiblingIndex;
    }
}

static EventHandlerListNode *CreateEventHandlerListNodeLinks(
    EventHandlerListNode *next,
    EventHandlerListNode *previous)
{
    EventHandlerListNode *node =
        static_cast<EventHandlerListNode *>(operator new(sizeof(EventHandlerListNode)));

    if (next != 0) {
        node->next = next;
        node->previous = previous;
    } else {
        node->next = node;
        node->previous = node;
    }

    return node;
}

static void RebindHandlerRecordVectorStorage(
    EventHandlerRecordVector *records,
    EventHandlerRecord *newBegin,
    int count,
    int capacity)
{
    EventHandlerRecord *oldBegin = records->begin;
    if (oldBegin != 0) {
        void *block = oldBegin;
        unsigned int byteCount =
            static_cast<unsigned int>(GetHandlerRecordCapacity(records) * sizeof(EventHandlerRecord));

        if (byteCount >= 0x1000u) {
            void *raw = reinterpret_cast<void **>(oldBegin)[-1];
            if (static_cast<unsigned int>(
                    reinterpret_cast<unsigned char *>(oldBegin) -
                    reinterpret_cast<unsigned char *>(raw) - 4) > 0x1fu) {
                _invalid_parameter_noinfo_noreturn();
            }
            block = raw;
        }

        operator delete(block);
    }

    records->begin = newBegin;
    records->end = newBegin + count;
    records->capacityEnd = newBegin + capacity;
}

static void ReserveHandlerRecordVectorStorage(
    EventHandlerRecordVector *records,
    unsigned int capacity)
{
    int count = GetHandlerRecordCount(records);
    EventHandlerRecord *newBegin = AllocateHandlerRecordBuffer(capacity);
    memmove(newBegin, records->begin, count * sizeof(EventHandlerRecord));
    RebindHandlerRecordVectorStorage(records, newBegin, count, static_cast<int>(capacity));
}
*/

struct EventHandlerListNode {
    EventHandlerListNode *next;
    EventHandlerListNode *previous;
    EventHandler *handler;
};

static EventHandlerListNode *CreateEventHandlerListNodeLinks(
    EventHandlerListNode *next,
    EventHandlerListNode *previous)
{
    EventHandlerListNode *node =
        static_cast<EventHandlerListNode *>(operator new(sizeof(EventHandlerListNode)));
    if (next != 0) {
        node->next = next;
        node->previous = previous;
    } else {
        node->next = node;
        node->previous = node;
    }
    return node;
}

// UID:000148 | by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md | Completion:89 | Confidence:94
/* Superseded hand-lowered std::vector instance retained as historical evidence.
static void FreeHandlerRecordVector(EventHandlerRecordVector *records)
{
    EventHandlerRecord *begin = records->begin;
    if (begin == 0) {
        return;
    }

    void *block = begin;
    unsigned int byteCount =
        static_cast<unsigned int>((records->capacityEnd - begin) * sizeof(EventHandlerRecord));

    if (byteCount >= 0x1000u) {
        void *raw = reinterpret_cast<void **>(begin)[-1];
        if (static_cast<unsigned int>(
                reinterpret_cast<unsigned char *>(begin) -
                reinterpret_cast<unsigned char *>(raw) - 4) > 0x1fu) {
            _invalid_parameter_noinfo_noreturn();
        }
        block = raw;
    }

    operator delete(block);
    records->begin = 0;
    records->end = 0;
    records->capacityEnd = 0;
}
*/
// Compiler-covered std::vector<TreeNode<EventHandler *> > storage release.

// UID:00022B | by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md | Completion:89 | Confidence:94
/* Superseded hand-lowered std::vector instances retained as historical evidence.
static EventHandlerRecord *AllocateHandlerRecordBuffer(unsigned int count)
{
    unsigned int byteCount = count * sizeof(EventHandlerRecord);

    if (count <= kMaxHandlerRecordCount) {
        if (byteCount < 0x1000u) {
            if (byteCount == 0) {
                return 0;
            }
            return static_cast<EventHandlerRecord *>(operator new(byteCount));
        }
    } else {
        byteCount = 0xffffffffu;
    }

    unsigned int allocationSize = byteCount + 35u;
    if (allocationSize < byteCount) {
        allocationSize = 0xffffffffu;
    }

    void *raw = operator new(allocationSize);
    if (raw == 0) {
        _invalid_parameter_noinfo_noreturn();
    }

    EventHandlerRecord *aligned =
        reinterpret_cast<EventHandlerRecord *>((reinterpret_cast<unsigned int>(raw) + 35u) & 0xffffffe0u);
    reinterpret_cast<void **>(aligned)[-1] = raw;
    return aligned;
}

static void FreeHandlerRecordBuffer(EventHandlerRecord *records, int count)
{
    void *block = records;

    if (static_cast<unsigned int>(count * sizeof(EventHandlerRecord)) >= 0x1000u) {
        void *raw = reinterpret_cast<void **>(records)[-1];
        if (static_cast<unsigned int>(
                reinterpret_cast<unsigned char *>(records) -
                reinterpret_cast<unsigned char *>(raw) - 4) > 0x1fu) {
            _invalid_parameter_noinfo_noreturn();
        }
        block = raw;
    }

    operator delete(block);
}
*/
// Compiler-covered std::vector<TreeNode<EventHandler *> > allocation support.


// UID:000296 | by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md | Completion:88 | Confidence:90
class EventDispatcher;
EventDispatcher *g_pEventDispatcher;

// UID:0002AV | by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md | Completion:90 | Confidence:92
static unsigned char KeyState[256];
static unsigned int s_cachedScrollLockToggleState;

// UID:0002AW | by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md | Completion:88 | Confidence:92
static bool s_keyboardChordGateActive;

// UID:0001UF | by-type/by-struct/EventDispatcherHandlerTreeLayouts.md | Completion:86 | Confidence:90
// EventDispatcher Tree<EventHandler *> concrete-layout evidence marker.
// UID0004YK Tree.h owns TreeNode, std::vector-backed Tree, and TreeItor source.
// UID00022A retains only dispatcher-specific EventHandlerListNode behavior.
[[No Children Attached]]

// UID:0003I5 | by-memory\0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData.md | Completion:86 | Confidence:91 | Empty Emitter Marker
