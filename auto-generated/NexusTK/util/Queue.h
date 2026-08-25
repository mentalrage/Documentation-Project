// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MW
// Source by-file doc: by-file/Queue.md
// UID:0000BF | by-class/Queue.md | Completion:91 | Confidence:92
#pragma once

#include "LObject.h"

class Queue : public LObject
{
public:
    Queue(int slotSize, int slotCount);
    virtual ~Queue();

    void WriteSlot(const void *slot);
    void ReadSlot(void *slot);
    bool IsEmpty() const;

private:
    int m_slotSize;
    int m_slotCount;
    void *m_buffer;
    int m_readIndex;
    int m_writeIndex;
};

typedef char QueueSizeMustBe24[sizeof(Queue) == 0x18 ? 1 : -1];
