// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KS
// Source by-file doc: by-file/List.md
// UID:000079 | by-class/List.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UTIL_LIST_H
#define NEXUSTK_UTIL_LIST_H

#include "LObject.h"

typedef int (__cdecl *ListCompareFunction)(const void *left,
                                           const void *right);

class List : public LObject
{
public:
    List(int elementSize, int pageSize);
    virtual ~List();
    virtual void *GetData();
    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();
    virtual void SwapElements(int firstIndex, int secondIndex);
    void AssignFrom(List *source);
    void SetCount(int count);
    int GetCount() const { return m_count; }
    void Sort(ListCompareFunction compare);

protected:
    int m_elementSize;
    int m_pageSize;
    int m_count;
    void *m_data;

private:
    void ReserveElementCapacity(int elementCount);
    void ReservePageCapacity(int pageCount);
    int PageCountForElementCount(int elementCount);
};

typedef char ListSizeMustBe20[sizeof(List) == 0x14 ? 1 : -1];

#endif
