// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KS
// Source by-file doc: by-file/List.md
// UID:000079 | by-class/List.md | Completion:93 | Confidence:94
#include "List.h"

// UID:000191 | by-memory/0x004f3060-0x004f30d5.ListConstructor.md | Completion:92 | Confidence:93
List::List(int elementSize, int pageSize)
    : LObject()
{
    m_elementSize = elementSize;
    m_pageSize = pageSize;
    m_count = 0;
    m_data = GetMemoryMan()->ZeroAllocateBufferMemory(elementSize * pageSize);
}

// UID:000192 | by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md | Completion:92 | Confidence:93
List::~List()
{
    if (m_data != NULL) {
        m_data = GetMemoryMan()->FreeBufferMemory(m_data);
    }
}

// UID:0003JT | by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md | Completion:90 | Confidence:91
void List::AssignFrom(List *source)
{
    m_elementSize = source->m_elementSize;
    m_pageSize = source->m_pageSize;
    m_count = source->m_count;

    if (m_data != NULL) {
        m_data = GetMemoryMan()->FreeBufferMemory(m_data);
    }

    int pageCount = 1;
    if (m_count > 0) {
        pageCount = ((m_count - 1) / m_pageSize) + 1;
    }

    m_data = GetMemoryMan()->AllocateBufferMemory(m_elementSize * m_pageSize * pageCount);
    GetMemoryMan()->MemmoveWrapper(m_data, source->m_data, m_elementSize * m_count);
}

// UID:0003JU | by-memory/0x004f31d0-0x004f329f.ListSetCount.md | Completion:90 | Confidence:92
void List::SetCount(int count)
{
    int oldPageCount = 1;
    if (m_count > 0) {
        oldPageCount = ((m_count - 1) / m_pageSize) + 1;
    }

    int newPageCount = 1;
    if (count > 0) {
        newPageCount = ((count - 1) / m_pageSize) + 1;
    }

    if (oldPageCount < newPageCount) {
        size_t newSize = newPageCount * m_pageSize * m_elementSize;
        if (m_data == NULL) {
            void *newData = GetMemoryMan()->AllocateBufferMemory(newSize);
            m_count = count;
            m_data = newData;
            return;
        }

        m_data = GetMemoryMan()->ReallocateBufferMemory(m_data, newSize);
    } else if (oldPageCount > newPageCount) {
        int capacity = newPageCount * m_pageSize;
        if (capacity == 0) {
            capacity = m_pageSize;
        }

        m_data = GetMemoryMan()->ReallocateBufferMemory(
            m_data,
            capacity * m_elementSize);
    }

    m_count = count;
}

// UID:0003JV | by-memory/0x004f32a0-0x004f32a4.ListGetData.md | Completion:91 | Confidence:93
void *List::GetData()
{
    return m_data;
}

// UID:0003JW | by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md | Completion:91 | Confidence:92
void *List::GetElementAt(int index)
{
    if (m_data == NULL || (index != 0 && (index < 0 || index >= m_count))) {
        return NULL;
    }

    return static_cast<unsigned char *>(m_data) + index * m_elementSize;
}

// UID:0003JX | by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md | Completion:90 | Confidence:92
void List::InsertAt(int index, int count, void *source)
{
    MemoryMan *memoryMan = GetMemoryMan();

    int oldCount = m_count;
    int oldPageCount = 1;
    if (oldCount > 0)
        oldPageCount = ((oldCount - 1) / m_pageSize) + 1;

    int newCount = oldCount + count;
    int newPageCount = 1;
    if (newCount > 0)
        newPageCount = ((newCount - 1) / m_pageSize) + 1;

    if (oldPageCount < newPageCount) {
        size_t byteCount = newPageCount * m_pageSize * m_elementSize;
        if (m_data == NULL)
            m_data = memoryMan->AllocateBufferMemory(byteCount);
        else
            m_data = memoryMan->ReallocateBufferMemory(m_data, byteCount);
    }

    unsigned char *data = static_cast<unsigned char *>(m_data);
    memoryMan->MoveBufferMemory(
        data + ((index + count) * m_elementSize),
        data + (index * m_elementSize),
        (oldCount - index) * m_elementSize);

    m_count += count;
    memoryMan->MemmoveWrapper(
        data + (index * m_elementSize),
        source,
        count * m_elementSize);
}

// UID:0003JY | by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md | Completion:89 | Confidence:92
void List::Append(int count, void *source)
{
    InsertAt(m_count, count, source);
}

// UID:0003JZ | by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md | Completion:90 | Confidence:92
void List::RemoveAt(int index, int count)
{
    MemoryMan *memoryMan = GetMemoryMan();
    unsigned char *data = static_cast<unsigned char *>(m_data);

    memoryMan->MoveBufferMemory(
        data + (index * m_elementSize),
        data + ((index + count) * m_elementSize),
        (m_count - index - count) * m_elementSize);

    int oldCount = m_count;
    int oldPageCount = 1;
    if (oldCount > 0)
        oldPageCount = ((oldCount - 1) / m_pageSize) + 1;

    int newCount = oldCount - count;
    int newPageCount = 1;
    if (newCount > 0)
        newPageCount = ((newCount - 1) / m_pageSize) + 1;

    if (newPageCount < oldPageCount) {
        int capacity = newPageCount * m_pageSize;
        if (capacity == 0)
            capacity = m_pageSize;

        m_data = memoryMan->ReallocateBufferMemory(
            m_data,
            capacity * m_elementSize);
    }

    m_count = newCount;
}

// UID:0003K0 | by-memory/0x004f34a0-0x004f34ab.ListClear.md | Completion:89 | Confidence:92
void List::RemoveAll()
{
    RemoveAt(0, m_count);
}

// UID:0003K1 | by-memory/0x004f34b0-0x004f3532.ListSwapElements.md | Completion:90 | Confidence:92
void List::SwapElements(int firstIndex, int secondIndex)
{
    if (firstIndex == secondIndex)
        return;

    MemoryMan *memoryMan = GetMemoryMan();
    void *temporary = memoryMan->AllocateBufferMemory(m_elementSize);

    void *first = GetElementAt(firstIndex);
    void *second = GetElementAt(secondIndex);

    memoryMan->MemmoveWrapper(temporary, first, m_elementSize);
    memoryMan->MemmoveWrapper(first, second, m_elementSize);
    memoryMan->MemmoveWrapper(second, temporary, m_elementSize);

    memoryMan->FreeBufferMemory(temporary);
}

// UID:0003K2 | by-memory/0x004f3540-0x004f355b.ListSort.md | Completion:90 | Confidence:92
void List::Sort(ListCompareFunction compare)
{
    qsort(m_data, m_count, m_elementSize, compare);
}

// UID:0003K3 | by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md | Completion:88 | Confidence:91
void List::ReserveElementCapacity(int elementCount)
{
    MemoryMan *memoryMan = GetMemoryMan();
    size_t byteCount = m_elementSize * elementCount;

    if (m_data == NULL) {
        m_data = memoryMan->AllocateBufferMemory(byteCount);
        return;
    }

    m_data = memoryMan->ReallocateBufferMemory(m_data, byteCount);
}

// UID:0003K4 | by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md | Completion:88 | Confidence:91
void List::ReservePageCapacity(int pageCount)
{
    if (pageCount == 0)
        pageCount = m_pageSize;

    m_data = GetMemoryMan()->ReallocateBufferMemory(
        m_data,
        m_elementSize * pageCount);
}

// UID:0003K5 | by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md | Completion:88 | Confidence:91
int List::PageCountForElementCount(int elementCount)
{
    if (elementCount <= 0)
        return 1;

    return ((elementCount - 1) / m_pageSize) + 1;
}

// UID:00037L | by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md | Completion:87 | Confidence:92
// Source-level teardown is emitted by [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md) ListNonDeletingDestructor
// as ordinary List::~List(). This page documents the MSVC scalar deleting
// destructor wrapper at 0x004f3810-0x004f38a7; do not hand-write the
// delete-flag, vtable-reset, base-destructor, guard-check, or object-free code.

// UID:0003OL | by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md | Completion:90 | Confidence:94
// The List/SortedList RTTI and vtable data at 0x0061ce28-0x0061ce84 is
// generated from the List and SortedList class declarations and destructor
// routes. Keep the exact slot bytes as evidence; do not hand-author a vtable
// initializer here.
