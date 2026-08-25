// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NU
// Source by-file doc: by-file/SortedList.md
// UID:0000DF | by-class/SortedList.md | Completion:94 | Confidence:94
#include "List.h"

class SortedList : public List
{
public:
    SortedList(int elementSize,
               ListCompareFunction compare,
               int pageSize);
    virtual ~SortedList();
    virtual void *GetElementAt(int index);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();

    int InsertSorted(const void *element);
    int FindFirstEqual(const void *key);

private:
    ListCompareFunction m_compare;
};

typedef char SortedListSizeMustBe24[sizeof(SortedList) == 0x18 ? 1 : -1];

[[No Children Attached]]
