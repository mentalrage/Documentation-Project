// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OA
// Source by-file doc: by-file/StringBase.md
// UID:0001WS | by-type/by-template/StringBaseTemplate.md | Completion:88 | Confidence:91
#ifndef NEXUSTK_UTIL_STRINGBASE_H
#define NEXUSTK_UTIL_STRINGBASE_H

namespace mystr
{
template <class CharT>
struct mychar_traits;

template <class CharT, class Traits = mychar_traits<CharT> >
class StringBase
{
public:
    StringBase();
    StringBase(const CharT *text);
    StringBase(const StringBase& other);
    template <class OtherCharT, class OtherTraits>
    StringBase(const StringBase<OtherCharT, OtherTraits>& other);
    ~StringBase();

    StringBase& operator=(const StringBase& other);
    StringBase& operator=(const CharT *text);

    const CharT *c_str() const;
    CharT *data();
    StringBase ToLower() const;
    void DetachAnsiIfShared();
    unsigned int length() const;
    bool empty() const;
    StringBase& AppendWideLiteral(const wchar_t *source, unsigned int maxCount);
    int CompareWideLiteral(const wchar_t *literal) const;
    int FindLastOf(const wchar_t *chars, unsigned int start, unsigned int charCount) const;
    int FindLastNotOf(const wchar_t *chars, unsigned int start, unsigned int charCount) const;
    StringBase& SubstringWide(StringBase& out, unsigned int start, unsigned int count) const;
    long ToLong() const;
    int FormatWide(const wchar_t *format, ...);
    StringBase& InitializeWideFromRange(const wchar_t *first, const wchar_t *last);
    void append(const CharT *text);
    StringBase& append(unsigned int count, CharT character);
    void insert(int position, const CharT *text);
    void insert(int position, const StringBase& text);
    void DetachWideIfShared();
    wchar_t *SetLengthWideAndDetach(unsigned int length);
    wchar_t *LockWideBuffer();

private:
    CharT *m_data;
};

int WideRangeCompare(const wchar_t *lhsBegin, const wchar_t *lhsEnd,
                     const wchar_t *rhsBegin, const wchar_t *rhsEnd);
}

// UID:0004FM | by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md | Completion:92 | Confidence:94
namespace mystr {

template <>
inline StringBase<char, mychar_traits<char> >
StringBase<char, mychar_traits<char> >::ToLower() const
{
    StringBase<char, mychar_traits<char> > result(*this);

    result.DetachAnsiIfShared();
    _strlwr_s(result.data(), result.length() + 1);

    return result;
}

}

#endif
