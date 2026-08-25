// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MW
// Source by-file doc: by-file/Queue.md
// UID:0000BF | by-class/Queue.md | Completion:91 | Confidence:92
#include "Queue.h"
#include "MemoryMan.h"


// UID:0001FM | by-memory/0x005539e0-0x00553a5c.QueueConstructor.md | Completion:88 | Confidence:90
Queue::Queue(int slotSize, int slotCount)
    : LObject()
{
    m_slotSize = slotSize;
    m_slotCount = slotCount;
    m_buffer = GetMemoryMan()->ZeroAllocateBufferMemory(slotSize * slotCount);
    m_readIndex = 0;
    m_writeIndex = 0;
}

// UID:0001FO | by-memory/0x00553a60-0x00553ab9.QueueDestructor.md | Completion:88 | Confidence:91
Queue::~Queue()
{
    if (m_buffer != NULL) {
        m_buffer = GetMemoryMan()->FreeBufferMemory(m_buffer);
    }
}

// UID:0001FP | by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md | Completion:87 | Confidence:90
void Queue::WriteSlot(const void *slot)
{
    GetMemoryMan()->MemmoveWrapper(
        static_cast<unsigned char *>(m_buffer) + (m_writeIndex * m_slotSize),
        slot,
        m_slotSize);

    if (m_writeIndex >= m_slotCount - 1) {
        m_writeIndex = 0;
    } else {
        ++m_writeIndex;
    }
}

// UID:0001FQ | by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md | Completion:87 | Confidence:90
void Queue::ReadSlot(void *slot)
{
    GetMemoryMan()->MemmoveWrapper(
        slot,
        static_cast<unsigned char *>(m_buffer) + (m_readIndex * m_slotSize),
        m_slotSize);

    if (m_readIndex >= m_slotCount - 1) {
        m_readIndex = 0;
    } else {
        ++m_readIndex;
    }
}

// UID:0001FR | by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md | Completion:87 | Confidence:90
bool Queue::IsEmpty() const
{
    return m_readIndex == m_writeIndex;
}

// UID:0001FN | by-memory\0x005539e0-0x00553c07.Queue.md | Completion:90 | Confidence:91 | Empty Emitter Marker

// UID:0003CS | by-memory\0x00622d24-0x00622d30.QueueVtableData.md | Completion:87 | Confidence:93 | Empty Emitter Marker
