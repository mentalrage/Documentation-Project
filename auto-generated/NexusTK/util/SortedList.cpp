// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NU
// Source by-file doc: by-file/SortedList.md
// UID:0000DF | by-class/SortedList.md | Completion:94 | Confidence:94
#include "SortedList.h"
#include "MemoryMan.h"


// UID:00037J | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md | Completion:96 | Confidence:96
int SortedList::InsertSorted(const void *element)
{
    int index = 0;
    unsigned char *current = static_cast<unsigned char *>(m_data);
    while (index < m_count) {
        if (m_compare(element, current) < 0) {
            break;
        }

        current += m_elementSize;
        ++index;
    }

    MemoryMan *memoryMan = GetMemoryMan();
    int oldCount = m_count;

    int oldPageCount = 1;
    if (oldCount > 0) {
        oldPageCount = ((oldCount - 1) / m_pageSize) + 1;
    }

    int newPageCount = 1;
    if (oldCount >= 0) {
        newPageCount = (oldCount / m_pageSize) + 1;
    }

    if (oldPageCount < newPageCount) {
        size_t byteCount = newPageCount * m_pageSize * m_elementSize;
        MemoryMan *allocator = GetMemoryMan();
        if (m_data != NULL) {
            m_data = allocator->ReallocateBufferMemory(m_data, byteCount);
        } else {
            m_data = allocator->AllocateBufferMemory(byteCount);
        }
    }

    unsigned char *data = static_cast<unsigned char *>(m_data);
    memoryMan->MoveBufferMemory(
        data + ((index + 1) * m_elementSize),
        data + (index * m_elementSize),
        (oldCount - index) * m_elementSize);

    ++m_count;
    memoryMan->MemmoveWrapper(
        data + (index * m_elementSize),
        element,
        m_elementSize);

    return index;
}

// UID:00037I | by-memory\0x004f3600-0x004f3681.SortedListConstructor.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:00037K | by-memory\0x004f3780-0x004f3803.SortedListFindFirstEqual.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:00037M | by-memory\0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00037N | by-memory\0x004f3950-0x004f397a.SortedListGetElementAt.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:00037O | by-memory\0x004f3980-0x004f398b.SortedListClear.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:00037P | by-memory\0x004f3990-0x004f3a43.SortedListRemoveRange.md | Completion:88 | Confidence:91 | Empty Emitter Marker
