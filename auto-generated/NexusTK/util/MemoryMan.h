// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L7
// Source by-file doc: by-file/MemoryMan.md
// UID:00007U | by-class/MemoryMan.md | Completion:91 | Confidence:91
#pragma once

#include <stddef.h>

class MemoryMan
{
public:
    MemoryMan();
    virtual ~MemoryMan();

    void *AllocateBufferMemory(size_t size);
    void *ZeroAllocateBufferMemory(size_t size);
    void *FreeBufferMemory(void *block);
    void *ReallocateBufferMemory(void *block, size_t newSize);
    void *MemmoveWrapper(void *destination, const void *source, size_t size);
    void *MoveBufferMemory(void *destination, const void *source, size_t size);
};

// UID:0001BC | by-memory/0x00516030-0x00516036.GetMemoryMan.md | Completion:90 | Confidence:92
MemoryMan *GetMemoryMan();
