// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N8
// Source by-file doc: by-file/RingBuffer.md
// UID:0000C1 | by-class/RingBuffer.md | Completion:90 | Confidence:92
#pragma once

#include "LObject.h"

class Monitor;
class MonitorCondition;
class RingBufferIterator;

class RingBuffer : public LObject
{
    friend class RingBufferIterator;

public:
    RingBuffer(int elementSize, int capacity);
    virtual ~RingBuffer();

    void Enqueue(const void *record);
    void Dequeue(void *record);
    bool IsEmpty() const;
    bool IsFull() const;
    void Lock();
    void Unlock();
    bool Empty() const;
    bool Full() const;

private:
    Monitor *mMonitor;
    MonitorCondition *mNotFull;
    MonitorCondition *mNotEmpty;
    int mElementSize;
    int mCapacity;
    unsigned char *mStorage;
    int mCount;
    int mReadIndex;
    int mWriteIndex;
};

// UID:0000C2 | by-class/RingBufferIterator.md | Completion:89 | Confidence:91
class RingBufferIterator : public LObject
{
public:
    RingBufferIterator(RingBuffer *owner);

    void Reset();
    void SetToLast();
    void Advance();
    void Retreat();
    bool AtReadBoundary() const;
    bool NextAtWriteBoundary() const;
    void *CurrentElement() const;

private:
    RingBuffer *mOwner;
    int mCurrentIndex;
};
