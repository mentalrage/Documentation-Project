// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MU
// Source by-file doc: by-file/ProtectedArray.md
// UID:0001WR | by-type/by-template/ProtectedArrayTemplates.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UTIL_PROTECTEDARRAY_H
#define NEXUSTK_UTIL_PROTECTEDARRAY_H

#include <string.h>

template <class T>
class ProtectedArray
{
public:
    explicit ProtectedArray(int defaultCapacity = 10)
        : m_count(0),
          m_entries(0),
          m_defaultCapacity(defaultCapacity),
          m_defaultEntry()
    {
    }

    virtual ~ProtectedArray()
    {
        delete [] m_entries;
    }

    T *GetAtOrDefault(int index)
    {
        if (index < 0 || index >= m_count)
            return &m_defaultEntry;

        return &m_entries[index];
    }

    void Resize(int count)
    {
        if (count <= 0 || count == m_count)
            return;

        T *entries = new T[count];
        if (m_entries != 0) {
            int copyCount = m_count;
            if (count < copyCount)
                copyCount = count;

            memmove(entries, m_entries, copyCount * sizeof(T));
            delete [] m_entries;
        }

        m_entries = entries;
        m_count = count;
    }

private:
    int m_count;
    T *m_entries;
    int m_defaultCapacity;
    T m_defaultEntry;
};

#endif
