// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MM
// Source by-file doc: by-file/PoolAllocator.md
// UID:0000AM | by-class/PoolAllocator.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_UTIL_POOLALLOCATOR_H
#define NEXUSTK_UTIL_POOLALLOCATOR_H

#include <windows.h>

struct PoolChunkHeader;
struct PoolFreeBlock;

class PoolAllocator
{
public:
    PoolAllocator(int blockSize, int blocksPerChunk);
    ~PoolAllocator();

    void *Allocate();
    void Free(void *block);

private:
    int m_blockSize;
    int m_blocksPerChunk;
    PoolChunkHeader *m_chunkList;
    PoolFreeBlock *m_freeList;
    CRITICAL_SECTION m_lock;
};

typedef char PoolAllocatorSizeMustBe40[
    sizeof(PoolAllocator) == 0x28 ? 1 : -1];

#endif
