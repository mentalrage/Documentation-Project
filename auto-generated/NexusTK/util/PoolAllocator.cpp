// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MM
// Source by-file doc: by-file/PoolAllocator.md
// UID:0000AM | by-class/PoolAllocator.md | Completion:94 | Confidence:94
#include "PoolAllocator.h"

#include <new>

struct PoolChunkHeader
{
    PoolChunkHeader *next;
};

struct PoolFreeBlock
{
    PoolFreeBlock *next;
};

static PoolChunkHeader *AllocatePoolChunk(
    PoolChunkHeader **chunkListHead,
    int blocksPerChunk,
    int blockSize);
static void FreePoolChunkList(PoolChunkHeader *chunkList);

// UID:000152 | by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md | Completion:94 | Confidence:95
PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)
    : m_blockSize(blockSize),
      m_blocksPerChunk(blocksPerChunk),
      m_chunkList(0),
      m_freeList(0)
{
    InitializeCriticalSection(&m_lock);
}

void *PoolAllocator::Allocate()
{
    EnterCriticalSection(&m_lock);

    try
    {
        if (m_freeList == 0)
        {
            PoolChunkHeader *chunk = AllocatePoolChunk(
                &m_chunkList,
                m_blocksPerChunk,
                m_blockSize);
            char *block = reinterpret_cast<char *>(chunk + 1);

            block += (m_blocksPerChunk - 1) * m_blockSize;
            for (int index = m_blocksPerChunk - 1; index >= 0; --index)
            {
                PoolFreeBlock *freeBlock =
                    reinterpret_cast<PoolFreeBlock *>(block);
                freeBlock->next = m_freeList;
                m_freeList = freeBlock;
                block -= m_blockSize;
            }
        }

        PoolFreeBlock *block = m_freeList;
        m_freeList = block->next;
        LeaveCriticalSection(&m_lock);
        return block;
    }
    catch (...)
    {
        LeaveCriticalSection(&m_lock);
        throw;
    }
}

// UID:000153 | by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md | Completion:94 | Confidence:95
void PoolAllocator::Free(void *block)
{
    if (block == 0)
        return;

    EnterCriticalSection(&m_lock);
    PoolFreeBlock *freeBlock = static_cast<PoolFreeBlock *>(block);
    freeBlock->next = m_freeList;
    m_freeList = freeBlock;
    LeaveCriticalSection(&m_lock);
}

PoolAllocator::~PoolAllocator()
{
    EnterCriticalSection(&m_lock);
    FreePoolChunkList(m_chunkList);
    m_chunkList = 0;
    m_freeList = 0;
    LeaveCriticalSection(&m_lock);
    DeleteCriticalSection(&m_lock);
}

// UID:0001F4 | by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md | Completion:94 | Confidence:95
static PoolChunkHeader *AllocatePoolChunk(
    PoolChunkHeader **chunkListHead,
    int blocksPerChunk,
    int blockSize)
{
    PoolChunkHeader *chunk = static_cast<PoolChunkHeader *>(
        ::operator new(sizeof(PoolChunkHeader) + blocksPerChunk * blockSize));
    chunk->next = *chunkListHead;
    *chunkListHead = chunk;
    return chunk;
}

// UID:00023L | by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md | Completion:94 | Confidence:95
static void FreePoolChunkList(PoolChunkHeader *chunkList)
{
    while (chunkList != 0)
    {
        PoolChunkHeader *chunk = chunkList;
        chunkList = chunk->next;
        ::operator delete(chunk);
    }
}
