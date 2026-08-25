// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OB
// Source by-file doc: by-file/StringUtil.md
// UID:0000D9 | by-class/SimpleUString.md | Completion:90 | Confidence:92
#ifndef NEXUSTK_UTIL_STRINGUTIL_H
#define NEXUSTK_UTIL_STRINGUTIL_H

#include "LObject.h"

class SimpleUString
{
public:
    SimpleUString();
    ~SimpleUString();

    void Clear();
    SimpleUString& Assign(const wchar_t *source, unsigned int length);
    wchar_t *MutableData()
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }
    const wchar_t *Data() const
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }
    unsigned int Length() const
    {
        return m_length;
    }

private:
    union
    {
        wchar_t m_inlineBuffer[8];
        wchar_t *m_heapBuffer;
    };
    unsigned int m_length;
    unsigned int m_capacity;
};

// UID:0000DA | by-class/SimpleUStringVector.md | Completion:88 | Confidence:89
namespace mystr
{
template <class CharT>
struct mychar_traits;

template <class CharT, class Traits>
class StringBase;
}

typedef wchar_t *SimpleUStringHandle;

class SimpleUStringVector
{
public:
    SimpleUStringVector();
    ~SimpleUStringVector();

    void Clear();
    unsigned int Size() const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >&
        operator[](unsigned int index);
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >&
        operator[](unsigned int index) const;
    void PushBack(
        const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &value);
    void PushBack(const SimpleUStringHandle *value);

private:
    SimpleUStringHandle *m_begin;
    SimpleUStringHandle *m_end;
    SimpleUStringHandle *m_capacity;

    SimpleUStringHandle *GrowAndInsert(SimpleUStringHandle *position,
                                       const SimpleUStringHandle *value);
};

// UID:0000E7 | by-class/StringIter.md | Completion:88 | Confidence:89
class StringIter : public LObject
{
public:
    StringIter(const wchar_t *data, int length);
    StringIter(const wchar_t *data, int length, int position);
    virtual ~StringIter();

    wchar_t PeekCharAtOffset(int offset) const;
    void Advance(int count);
    wchar_t GetNextChar();

private:
    const wchar_t *m_data;
    int m_length;
    int m_position;
};

// UID:0000PW | by-global/g_emptySimpleUString.md | Completion:92 | Confidence:93
extern SimpleUString g_emptySimpleUString;

#endif
