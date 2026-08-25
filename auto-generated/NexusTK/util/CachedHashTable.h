// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HZ
// Source by-file doc: by-file/CachedHashTable.md
// UID:00001F | by-class/CachedHashTable.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_UTIL_CACHEDHASHTABLE_H
#define NEXUSTK_UTIL_CACHEDHASHTABLE_H

#include "LObject.h"

class CachedHashTable : public LObject
{
public:
    CachedHashTable(int entrySize, int slotCount);
    virtual ~CachedHashTable();

    unsigned int ComputeHashIndex(const void *keyBytes, int keyLength) const;
    void Clear();
    void *RemoveAt(unsigned int slotIndex);
    void *GetAt(unsigned int slotIndex) const;
    int SetAt(const void *entry, unsigned int slotIndex);
    int GetSlotCount() const;
    int GetEntryCount() const;

private:
    void *GetEntryAddressUnchecked(unsigned int slotIndex) const;

    unsigned char *m_entries;
    unsigned char *m_slotState;
    int m_entrySize;
    int m_slotCount;
    int m_entryCount;
    unsigned char m_hashSeed[4];
};

typedef char CachedHashTableSizeMustBe28[
    sizeof(CachedHashTable) == 0x1c ? 1 : -1];

#endif
