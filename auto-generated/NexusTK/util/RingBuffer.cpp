// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N8
// Source by-file doc: by-file/RingBuffer.md
// UID:0000C1 | by-class/RingBuffer.md | Completion:90 | Confidence:92
#include "RingBuffer.h"

#include "MemoryMan.h"
#include "Monitor.h"


// UID:0004EN | by-memory/0x005563d0-0x005564d4.RingBufferConstructor.md | Completion:92 | Confidence:93
RingBuffer::RingBuffer(int elementSize, int capacity)
{
    MemoryMan *memoryMan = GetMemoryMan();

    mMonitor = new Monitor;
    mNotFull = new MonitorCondition(mMonitor);
    mNotEmpty = new MonitorCondition(mMonitor);
    mElementSize = elementSize;
    mCapacity = capacity;
    mStorage = static_cast<unsigned char *>(
        memoryMan->ZeroAllocateBufferMemory(mElementSize * mCapacity));
    mCount = 0;
    mReadIndex = 0;
    mWriteIndex = 0;
}

// UID:0004EO | by-memory/0x005564e0-0x00556579.RingBufferCleanupBody.md | Completion:93 | Confidence:94
RingBuffer::~RingBuffer()
{
    if (mStorage != 0) {
        GetMemoryMan()->FreeBufferMemory(mStorage);
        mStorage = 0;
    }

    delete mNotEmpty;
    mNotEmpty = 0;

    delete mNotFull;
    mNotFull = 0;

    delete mMonitor;
    mMonitor = 0;
}

// UID:0004EP | by-memory/0x00556580-0x005565ec.RingBufferEnqueue.md | Completion:89 | Confidence:92
void RingBuffer::Enqueue(const void *record)
{
    MemoryMan *memoryMan = GetMemoryMan();

    mMonitor->Lock();

    while (mCount >= mCapacity)
        mNotFull->Wait();

    unsigned char *destination = mStorage + (mElementSize * mWriteIndex);
    memoryMan->MemmoveWrapper(destination, record, mElementSize);

    ++mWriteIndex;
    if (mWriteIndex >= mCapacity)
        mWriteIndex = 0;

    ++mCount;
    mNotEmpty->Signal();

    mMonitor->Unlock();
}

// UID:0004EQ | by-memory/0x005565f0-0x0055665a.RingBufferDequeue.md | Completion:89 | Confidence:92
void RingBuffer::Dequeue(void *record)
{
    MemoryMan *memoryMan = GetMemoryMan();

    mMonitor->Lock();

    while (mCount <= 0)
        mNotEmpty->Wait();

    unsigned char *source = mStorage + (mElementSize * mReadIndex);
    memoryMan->MemmoveWrapper(record, source, mElementSize);

    ++mReadIndex;
    if (mReadIndex >= mCapacity)
        mReadIndex = 0;

    --mCount;
    mNotFull->Signal();

    mMonitor->Unlock();
}

// UID:0004ER | by-memory/0x00556660-0x00556668.RingBufferIsEmpty.md | Completion:88 | Confidence:91
bool RingBuffer::IsEmpty() const
{
    return mCount <= 0;
}

// UID:0004ES | by-memory/0x00556670-0x0055667a.RingBufferIsFullRawPredicate.md | Completion:86 | Confidence:88
bool RingBuffer::IsFull() const
{
    return mCapacity <= mCount;
}

// UID:0004ET | by-memory/0x00556680-0x00556688.RingBufferLock.md | Completion:87 | Confidence:90
void RingBuffer::Lock()
{
    mMonitor->Lock();
}

// UID:0004EU | by-memory/0x00556690-0x00556698.RingBufferUnlock.md | Completion:87 | Confidence:90
void RingBuffer::Unlock()
{
    mMonitor->Unlock();
}

// UID:0004EV | by-memory/0x005566a0-0x005566a8.RingBufferEmptyPredicateAlias.md | Completion:86 | Confidence:88
bool RingBuffer::Empty() const
{
    return mCount <= 0;
}

// UID:0004EW | by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md | Completion:85 | Confidence:87
bool RingBuffer::Full() const
{
    return mCapacity <= mCount;
}

// UID:0004EX | by-memory/0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw.md | Completion:88 | Confidence:90
RingBufferIterator::RingBufferIterator(RingBuffer *owner)
    : LObject(),
      mOwner(owner),
      mCurrentIndex(-1)
{
}

// UID:0004EY | by-memory/0x005566f0-0x005566fa.RingBufferIteratorReset.md | Completion:88 | Confidence:91
void RingBufferIterator::Reset()
{
    mCurrentIndex = mOwner->mReadIndex;
}

// UID:0004EZ | by-memory/0x00556700-0x00556715.RingBufferIteratorSetToLastRaw.md | Completion:87 | Confidence:90
void RingBufferIterator::SetToLast()
{
    mCurrentIndex = (mOwner->mWriteIndex - 1 + mOwner->mCapacity) % mOwner->mCapacity;
}

// UID:0004F0 | by-memory/0x00556720-0x00556749.RingBufferIteratorAdvance.md | Completion:87 | Confidence:90
void RingBufferIterator::Advance()
{
    int nextIndex = (mCurrentIndex + 1) % mOwner->mCapacity;
    if (nextIndex != mOwner->mWriteIndex)
        mCurrentIndex = nextIndex;
}

// UID:0004F1 | by-memory/0x00556750-0x00556767.RingBufferIteratorRetreatRaw.md | Completion:87 | Confidence:90
void RingBufferIterator::Retreat()
{
    if (mCurrentIndex == mOwner->mReadIndex)
        return;

    if (mCurrentIndex == 0)
        mCurrentIndex = mOwner->mCapacity - 1;
    else
        --mCurrentIndex;
}

// UID:0004F2 | by-memory/0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw.md | Completion:87 | Confidence:90
bool RingBufferIterator::AtReadBoundary() const
{
    return mCurrentIndex == mOwner->mReadIndex;
}

// UID:0004F3 | by-memory/0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw.md | Completion:87 | Confidence:90
bool RingBufferIterator::NextAtWriteBoundary() const
{
    int nextIndex = (mCurrentIndex + 1) % mOwner->mCapacity;
    return nextIndex == mOwner->mWriteIndex;
}

// UID:0004F4 | by-memory/0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw.md | Completion:87 | Confidence:90
void *RingBufferIterator::CurrentElement() const
{
    return mOwner->mStorage + (mOwner->mElementSize * mCurrentIndex);
}

// UID:0002OQ | by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md | Completion:92 | Confidence:94
// RingBuffer and RingBufferIterator RTTI/vtable data is compiler-generated from
// the class declarations in [UID:0000C1][RingBuffer](by-class/RingBuffer.md) and [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md); do not hand-emit tables.

// UID:0001YN | by-type/by-vtable/RingBufferVtables.md | Completion:92 | Confidence:94
// The RingBuffer vtable inventory is covered by the RingBuffer and
// RingBufferIterator class declarations; no source table is emitted here.

// UID:0000C2 | by-class\RingBufferIterator.md | Completion:89 | Confidence:91 | Empty Emitter Marker
