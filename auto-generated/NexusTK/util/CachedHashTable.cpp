// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HZ
// Source by-file doc: by-file/CachedHashTable.md
// UID:00001F | by-class/CachedHashTable.md | Completion:94 | Confidence:94
#include "CachedHashTable.h"

#include "MemoryMan.h"

#include <stdlib.h>

// UID:00050T | by-memory/0x004c6160-0x004c6259.CachedHashTableConstructor.md | Completion:94 | Confidence:94
CachedHashTable::CachedHashTable(int entrySize, int slotCount)
    : LObject()
{
    m_entrySize = entrySize;
    m_slotCount = slotCount;
    m_entryCount = 0;

    m_entries = static_cast<unsigned char *>(
        GetMemoryMan()->AllocateBufferMemory(m_entrySize * m_slotCount));
    m_slotState = static_cast<unsigned char *>(
        GetMemoryMan()->AllocateBufferMemory(m_slotCount));

    for (unsigned int slotIndex = 0;
         slotIndex < static_cast<unsigned int>(m_slotCount);
         ++slotIndex) {
        m_slotState[slotIndex] = 0;
    }

    m_hashSeed[0] = static_cast<unsigned char>(rand());
    m_hashSeed[1] = static_cast<unsigned char>(rand());
    m_hashSeed[2] = static_cast<unsigned char>(rand());
    m_hashSeed[3] = static_cast<unsigned char>(rand());
}

// UID:00050U | by-memory/0x004c6260-0x004c62ce.CachedHashTableDestructor.md | Completion:94 | Confidence:94
CachedHashTable::~CachedHashTable()
{
    GetMemoryMan()->FreeBufferMemory(m_entries);
    GetMemoryMan()->FreeBufferMemory(m_slotState);
    m_entries = 0;
    m_slotState = 0;
}

// UID:00050V | by-memory/0x004c62d0-0x004c63c1.CachedHashTableComputeHashIndex.md | Completion:93 | Confidence:93
unsigned int CachedHashTable::ComputeHashIndex(const void *keyBytes,
                                                int keyLength) const
{
    const unsigned char *bytes =
        static_cast<const unsigned char *>(keyBytes);
    unsigned int hash = 0;

    for (int index = 0; index < keyLength; ++index)
        hash += bytes[index];

    return hash % static_cast<unsigned int>(m_slotCount);
}

// UID:00050W | by-memory/0x004c63d0-0x004c63ee.CachedHashTableClear.md | Completion:94 | Confidence:94
void CachedHashTable::Clear()
{
    m_entryCount = 0;

    for (unsigned int slotIndex = 0;
         slotIndex < static_cast<unsigned int>(m_slotCount);
         ++slotIndex) {
        m_slotState[slotIndex] = 0;
    }
}

// UID:00050X | by-memory/0x004c63f0-0x004c641e.CachedHashTableRemoveAt.md | Completion:94 | Confidence:94
void *CachedHashTable::RemoveAt(unsigned int slotIndex)
{
    if (slotIndex >= static_cast<unsigned int>(m_slotCount) ||
        m_slotState[slotIndex] == 0) {
        return 0;
    }

    m_slotState[slotIndex] = 0;
    --m_entryCount;
    return m_entries + m_entrySize * slotIndex;
}

// UID:00050Y | by-memory/0x004c6420-0x004c6447.CachedHashTableGetAt.md | Completion:94 | Confidence:94
void *CachedHashTable::GetAt(unsigned int slotIndex) const
{
    if (slotIndex >= static_cast<unsigned int>(m_slotCount) ||
        m_slotState[slotIndex] == 0) {
        return 0;
    }

    return m_entries + m_entrySize * slotIndex;
}

// UID:00050Z | by-memory/0x004c6450-0x004c64a7.CachedHashTableSetAt.md | Completion:94 | Confidence:94
int CachedHashTable::SetAt(const void *entry, unsigned int slotIndex)
{
    if (slotIndex >= static_cast<unsigned int>(m_slotCount))
        return -1;

    unsigned char *destination =
        m_entries + m_entrySize * slotIndex;
    GetMemoryMan()->MemmoveWrapper(destination, entry, m_entrySize);

    if (m_slotState[slotIndex] != 0)
        return 0;

    ++m_entryCount;
    m_slotState[slotIndex] = 1;
    return 1;
}

// UID:00016Q | by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md | Completion:94 | Confidence:95
int CachedHashTable::GetSlotCount() const
{
    return m_slotCount;
}

int CachedHashTable::GetEntryCount() const
{
    return m_entryCount;
}

// UID:000510 | by-memory/0x004c64d0-0x004c64e1.CachedHashTableGetEntryAddressUnchecked.md | Completion:93 | Confidence:93
void *CachedHashTable::GetEntryAddressUnchecked(
    unsigned int slotIndex) const
{
    return m_entries + m_entrySize * slotIndex;
}
