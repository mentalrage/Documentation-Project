// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OA
// Source by-file doc: by-file/StringBase.md
// UID:0000TM | by-global/StringBufferSentinelsAndPools.md | Completion:94 | Confidence:94
#include "PoolAllocator.h"

namespace mystr {

struct StringBaseAnsiEmptySentinelStorage {
    RefCountedStringBufferHeader header;
    char data[1];
};

struct StringBaseWideEmptySentinelStorage {
    RefCountedStringBufferHeader header;
    wchar_t data[1];
};

static StringBaseWideEmptySentinelStorage g_emptyWideStringStorage = {
    { -1, 0, 0 },
    { L'\0' }
};

static StringBaseAnsiEmptySentinelStorage g_emptyAnsiStringStorage = {
    { -1, 0, 0 },
    { '\0' }
};

wchar_t *g_emptyWideString = g_emptyWideStringStorage.data;
char *g_emptyAnsiString = g_emptyAnsiStringStorage.data;

static const wchar_t g_wideTrimWhitespaceChars[] = L" \t\n\r";

PoolAllocator g_widePool64(sizeof(RefCountedStringBufferHeader) +
                           (64 + 1) * sizeof(wchar_t), 64);
PoolAllocator g_widePool128(sizeof(RefCountedStringBufferHeader) +
                            (128 + 1) * sizeof(wchar_t), 64);
PoolAllocator g_widePool256(sizeof(RefCountedStringBufferHeader) +
                            (256 + 1) * sizeof(wchar_t), 64);
PoolAllocator g_widePool512(sizeof(RefCountedStringBufferHeader) +
                            (512 + 1) * sizeof(wchar_t), 64);

PoolAllocator g_ansiPool64(sizeof(RefCountedStringBufferHeader) +
                           (64 + 1) * sizeof(char), 64);
PoolAllocator g_ansiPool128(sizeof(RefCountedStringBufferHeader) +
                            (128 + 1) * sizeof(char), 64);
PoolAllocator g_ansiPool256(sizeof(RefCountedStringBufferHeader) +
                            (256 + 1) * sizeof(char), 64);
PoolAllocator g_ansiPool512(sizeof(RefCountedStringBufferHeader) +
                            (512 + 1) * sizeof(char), 64);

} // namespace mystr

// UID:000325 | by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md | Completion:88 | Confidence:90
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::operator+=(const wchar_t* rhs)
{
    const wchar_t* end = rhs;
    while (*end != L'\0') {
        ++end;
    }

    return this->AppendWideLiteral(rhs, static_cast<unsigned int>(end - rhs));
}

}

// UID:00022D | by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md | Completion:88 | Confidence:91
namespace mystr {

StringBase<wchar_t, mychar_traits<wchar_t>>
operator+(
    const StringBase<wchar_t, mychar_traits<wchar_t>>& lhs,
    const StringBase<wchar_t, mychar_traits<wchar_t>>& rhs)
{
    StringBase<wchar_t, mychar_traits<wchar_t>> result(lhs);
    result.AppendWideSliceFromString(rhs, 0, rhs.length());
    return result;
}

}

// UID:000236 | by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md | Completion:88 | Confidence:91
static int MultiByteToWideDefaultCp(wchar_t *dst,
                                    int dstCount,
                                    const char *src,
                                    int srcCount)
{
    return MultiByteToWideChar(CP_ACP, 0, src, srcCount, dst, dstCount);
}

static int WideCharToMultiByteDefaultCp(char *dst,
                                        int dstCount,
                                        const wchar_t *src,
                                        int srcCount)
{
    return WideCharToMultiByte(CP_ACP, 0, src, srcCount, dst, dstCount, NULL, NULL);
}

// UID:0002RM | by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md | Completion:90 | Confidence:91
namespace mystr {

namespace {

static void StringBaseSetStoredLength(char *data, int length)
{
    reinterpret_cast<int *>(data)[-2] = length;
}

static void StringBaseSetStoredLength(wchar_t *data, int length)
{
    reinterpret_cast<int *>(data)[-2] = length;
}

static long ParseAnsiLongBase10(const char *text)
{
    return atol(text);
}

static long ParseWideLongBase10(const wchar_t *text)
{
    return _wtol(text);
}

static double ParseAnsiDoubleDefaultLocale(const char *text)
{
    return atof(text);
}

static int CompareAnsiNoCase(const char *lhs, const char *rhs)
{
    return _stricmp(lhs, rhs);
}

static int CollateAnsi(const char *lhs, const char *rhs)
{
    return _strcoll(lhs, rhs);
}

static int CollateAnsiNoCase(const char *lhs, const char *rhs)
{
    return _stricoll(lhs, rhs);
}

static int CompareWideNoCase(const wchar_t *lhs, const wchar_t *rhs)
{
    return _wcsicmp(lhs, rhs);
}

static int CollateWide(const wchar_t *lhs, const wchar_t *rhs)
{
    return _wcscoll(lhs, rhs);
}

static int CollateWideNoCase(const wchar_t *lhs, const wchar_t *rhs)
{
    return _wcsicoll(lhs, rhs);
}

static char *UpperAnsiInPlace(char *text, size_t bufferCount)
{
    _strupr_s(text, bufferCount);
    return text;
}

static char *LowerAnsiInPlace(char *text, size_t bufferCount)
{
    _strlwr_s(text, bufferCount);
    return text;
}

static wchar_t *UpperWideInPlace(wchar_t *text, size_t bufferCount)
{
    _wcsupr_s(text, bufferCount);
    return text;
}

static wchar_t *LowerWideInPlace(wchar_t *text, size_t bufferCount)
{
    _wcslwr_s(text, bufferCount);
    return text;
}

static int StringBaseVsnprintf(char *buffer,
                               size_t bufferCount,
                               size_t maxCount,
                               const char *format,
                               va_list args)
{
    const int result = _vsnprintf_s(buffer, bufferCount, maxCount, format, args);
    return result < 0 ? -1 : result;
}

static int StringBaseVsnwprintf(wchar_t *buffer,
                                size_t bufferCount,
                                size_t maxCount,
                                const wchar_t *format,
                                va_list args)
{
    const int result = _vsnwprintf_s(buffer, bufferCount, maxCount, format, args);
    return result < 0 ? -1 : result;
}

} // namespace

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFromAnsi(
    const char *source)
{
    const unsigned int sourceLength = static_cast<unsigned int>(strlen(source));
    AllocateWideBuffer(sourceLength);

    const int converted = MultiByteToWideDefaultCp(
        m_data,
        static_cast<int>(sourceLength),
        source,
        static_cast<int>(sourceLength));
    m_data[converted] = L'\0';
    StringBaseSetStoredLength(m_data, converted);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFromRaw(
    const wchar_t *source)
{
    const unsigned int sourceLength = static_cast<unsigned int>(wcslen(source));
    AllocateWideBuffer(sourceLength);
    memmove(m_data, source, sourceLength * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFromWideString(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    const wchar_t *sourceData = source.c_str();
    const unsigned int sourceLength =
        static_cast<unsigned int>(wcslen(sourceData));
    const unsigned int destinationCapacity = sourceLength * sizeof(wchar_t);

    AllocateAnsiBuffer(destinationCapacity);
    const int converted = WideCharToMultiByteDefaultCp(
        m_data,
        static_cast<int>(destinationCapacity),
        sourceData,
        static_cast<int>(sourceLength));
    m_data[converted] = '\0';
    StringBaseSetStoredLength(m_data, converted);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFromStringBase(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    const int *sourceHeader = reinterpret_cast<const int *>(sourceData);

    if (sourceData == g_emptyWideString) {
        m_data = g_emptyWideString;
        return *this;
    }

    if (sourceHeader[-3] >= 0) {
        InterlockedIncrement(
            reinterpret_cast<volatile LONG *>(
                const_cast<int *>(&sourceHeader[-3])));
        m_data = sourceData;
        return *this;
    }

    const unsigned int sourceLength =
        static_cast<unsigned int>(sourceHeader[-2]);
    AllocateWideBuffer(sourceLength);
    memmove(m_data, sourceData, sourceLength * sizeof(wchar_t));
    return *this;
}

template <>
long
StringBase<wchar_t, mychar_traits<wchar_t> >::ToLong() const
{
    return ParseWideLongBase10(m_data);
}

template <>
double
StringBase<wchar_t, mychar_traits<wchar_t> >::ToDoubleDefaultLocale() const
{
    StringBase<char, mychar_traits<char> > converted;
    converted.InitializeAnsiFromWide(m_data);

    const double result = ParseAnsiDoubleDefaultLocale(converted.c_str());
    converted.ReleaseAnsiBuffer();
    return result;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFromRaw(const char *source)
{
    const unsigned int sourceLength = static_cast<unsigned int>(strlen(source));
    AllocateAnsiBuffer(sourceLength);
    memmove(m_data, source, sourceLength);
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFromWide(
    const wchar_t *source)
{
    const unsigned int sourceLength = static_cast<unsigned int>(wcslen(source));
    const unsigned int destinationCapacity = sourceLength * sizeof(wchar_t);

    AllocateAnsiBuffer(destinationCapacity);
    const int converted = WideCharToMultiByteDefaultCp(
        m_data,
        static_cast<int>(destinationCapacity),
        source,
        static_cast<int>(sourceLength));
    m_data[converted] = '\0';
    StringBaseSetStoredLength(m_data, converted);
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFromStringBase(
    const StringBase<char, mychar_traits<char> > &source)
{
    char *sourceData = source.m_data;
    const int *sourceHeader = reinterpret_cast<const int *>(sourceData);

    if (sourceData == g_emptyAnsiString) {
        m_data = g_emptyAnsiString;
        return *this;
    }

    if (sourceHeader[-3] >= 0) {
        InterlockedIncrement(
            reinterpret_cast<volatile LONG *>(
                const_cast<int *>(&sourceHeader[-3])));
        m_data = sourceData;
        return *this;
    }

    const unsigned int sourceLength =
        static_cast<unsigned int>(sourceHeader[-2]);
    AllocateAnsiBuffer(sourceLength);
    memmove(m_data, sourceData, sourceLength);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFromAnsiString(
    const StringBase<char, mychar_traits<char> > &source)
{
    const char *sourceData = source.c_str();
    const unsigned int sourceLength =
        static_cast<unsigned int>(strlen(sourceData));

    AllocateWideBuffer(sourceLength);
    const int converted = MultiByteToWideDefaultCp(
        m_data,
        static_cast<int>(sourceLength),
        sourceData,
        static_cast<int>(sourceLength));
    m_data[converted] = L'\0';
    StringBaseSetStoredLength(m_data, converted);
    return *this;
}

template <>
long
StringBase<char, mychar_traits<char> >::ToLong() const
{
    return ParseAnsiLongBase10(m_data);
}

template <>
double
StringBase<char, mychar_traits<char> >::ToDoubleDefaultLocale() const
{
    return ParseAnsiDoubleDefaultLocale(m_data);
}

} // namespace mystr

// UID:0002RP | by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md | Completion:88 | Confidence:90
namespace mystr {

template <>
bool
StringBase<char, mychar_traits<char> >::EndsWithAnsi(
    const char *suffix) const
{
    const unsigned int suffixLength =
        static_cast<unsigned int>(strlen(suffix));
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);

    return length >= suffixLength &&
           CompareAnsiRange(m_data + length - suffixLength,
                            m_data + length,
                            suffix,
                            suffix + suffixLength) == 0;
}

template <>
bool
StringBase<wchar_t, mychar_traits<wchar_t> >::EndsWithWide(
    const wchar_t *suffix) const
{
    const unsigned int suffixLength =
        static_cast<unsigned int>(wcslen(suffix));
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);

    return length >= suffixLength &&
           CompareWideSubstringWithLiteral(length - suffixLength,
                                           suffixLength,
                                           suffix) == 0;
}

} // namespace mystr

// UID:0002RQ | by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md | Completion:90 | Confidence:91
namespace mystr {

namespace {

template <class CharT>
static unsigned int StoredLength(const CharT *data)
{
    return static_cast<unsigned int>(reinterpret_cast<const int *>(data)[-2]);
}

template <class CharT>
static int StoredRefCount(const CharT *data)
{
    return reinterpret_cast<const int *>(data)[-3];
}

template <class CharT>
static void SetStoredRefCount(CharT *data, int refCount)
{
    reinterpret_cast<int *>(data)[-3] = refCount;
}

template <class CharT>
static void SetStoredLength(CharT *data, unsigned int length)
{
    reinterpret_cast<int *>(data)[-2] = static_cast<int>(length);
}

static void DetachWideIfShared(
    StringBase<wchar_t, mychar_traits<wchar_t> > &value)
{
    wchar_t *oldData = value.m_data;
    if (StoredRefCount(oldData) <= 1) {
        return;
    }

    const unsigned int length = StoredLength(oldData);
    value.AllocateWideBuffer(length);
    memmove(value.m_data, oldData, length * sizeof(wchar_t));

    StringBase<wchar_t, mychar_traits<wchar_t> > oldValue;
    oldValue.m_data = oldData;
    oldValue.ReleaseWideBuffer();
}

static void BuildWideSegment(
    StringBase<wchar_t, mychar_traits<wchar_t> > &out,
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source,
    unsigned int start,
    unsigned int count)
{
    const unsigned int length = StoredLength(source.m_data);
    unsigned int clampedStart = start;
    if (length < clampedStart) {
        clampedStart = length;
    }

    unsigned int clampedEnd = length;
    if (count != 0xffffffffU) {
        clampedEnd = clampedStart + count;
        if (length < clampedEnd) {
            clampedEnd = length;
        }
    }

    const unsigned int segmentLength = clampedEnd - clampedStart;
    if (clampedStart == 0 && count == 0xffffffffU) {
        out.CopyOrShareWide(source);
        return;
    }

    out.AllocateWideBuffer(segmentLength);
    memmove(out.m_data,
            source.m_data + clampedStart,
            segmentLength * sizeof(wchar_t));
}

static void PushWideSegment(
    SimpleUStringVector &parts,
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source,
    unsigned int start,
    unsigned int count)
{
    StringBase<wchar_t, mychar_traits<wchar_t> > part;
    BuildWideSegment(part, source, start, count);
    parts.PushBack(part);
    part.ReleaseWideBuffer();
}

} // namespace

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::SliceWideRange(
    StringBase<wchar_t, mychar_traits<wchar_t> > &out,
    int start,
    int end) const
{
    const int length = static_cast<int>(StoredLength(m_data));
    const int first = start < 0 ? length + start : start;
    const int last = end > 0 ? end : length + end;

    if (last > first) {
        SubstringWide(out, static_cast<unsigned int>(first),
                      static_cast<unsigned int>(last - first));
    } else {
        out.m_data = g_emptyWideString;
    }

    return out;
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::SplitWideBySet(
    SimpleUStringVector &parts,
    const wchar_t *delimiters,
    bool keepDelimiters) const
{
    parts.Clear();

    const unsigned int length = StoredLength(m_data);
    if (length == 0) {
        return;
    }

    const unsigned int delimiterCount =
        static_cast<unsigned int>(wcslen(delimiters));
    unsigned int cursor = 0;

    for (;;) {
        const int delimiterIndex =
            FindFirstOf(delimiters, cursor, delimiterCount);
        if (delimiterIndex == -1) {
            PushWideSegment(parts, *this, cursor, 0xffffffffU);
            return;
        }

        PushWideSegment(parts,
                        *this,
                        cursor,
                        static_cast<unsigned int>(delimiterIndex) - cursor);

        const int nextTextIndex = FindFirstNotOf(
            delimiters,
            static_cast<unsigned int>(delimiterIndex),
            delimiterCount);
        if (nextTextIndex == -1) {
            if (keepDelimiters) {
                PushWideSegment(parts,
                                *this,
                                static_cast<unsigned int>(delimiterIndex),
                                0xffffffffU);
            }
            return;
        }

        if (keepDelimiters) {
            PushWideSegment(
                parts,
                *this,
                static_cast<unsigned int>(delimiterIndex),
                static_cast<unsigned int>(nextTextIndex - delimiterIndex));
        }

        cursor = static_cast<unsigned int>(nextTextIndex);
        if (cursor >= length) {
            return;
        }
    }
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::TrimLeftWide(
    const wchar_t *trimChars)
{
    DetachWideIfShared(*this);

    const unsigned int length = StoredLength(m_data);
    const int firstText = FindFirstNotOf(
        trimChars,
        0,
        static_cast<unsigned int>(wcslen(trimChars)));
    unsigned int trimCount = static_cast<unsigned int>(firstText);
    if (trimCount >= length) {
        trimCount = length;
    }

    if (trimCount == 0) {
        return *this;
    }

    if (trimCount == length) {
        ReleaseWideBuffer();
        return *this;
    }

    MakeExclusiveWide();
    const unsigned int newLength = length - trimCount;
    memmove(m_data, m_data + trimCount, newLength * sizeof(wchar_t));
    m_data[newLength] = L'\0';
    SetStoredLength(m_data, newLength);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::TrimRightWide(
    const wchar_t *trimChars)
{
    DetachWideIfShared(*this);

    const int lastText = FindLastNotOf(
        trimChars,
        0xffffffffU,
        static_cast<unsigned int>(wcslen(trimChars)));
    RemoveWideRange(static_cast<unsigned int>(lastText + 1), 0xffffffffU);
    return *this;
}

template <>
char *
StringBase<char, mychar_traits<char> >::LockAnsiBuffer()
{
    if (m_data != g_emptyAnsiString) {
        SetStoredRefCount(m_data, 1);
    }

    return m_data;
}

template <>
wchar_t *
StringBase<wchar_t, mychar_traits<wchar_t> >::LockWideBuffer()
{
    if (m_data != g_emptyWideString) {
        SetStoredRefCount(m_data, 1);
    }

    return m_data;
}

} // namespace mystr

// UID:0003NT | by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md | Completion:88 | Confidence:90
namespace mystr {

int CompareAnsiRange(const char *lhsBegin,
                     const char *lhsEnd,
                     const char *rhsBegin,
                     const char *rhsEnd)
{
    const char *lhs = lhsBegin;
    const char *rhs = rhsBegin;

    while (lhs != lhsEnd && rhs != rhsEnd) {
        const unsigned char lhsChar = static_cast<unsigned char>(*lhs);
        const unsigned char rhsChar = static_cast<unsigned char>(*rhs);
        if (lhsChar != rhsChar) {
            return lhsChar < rhsChar ? -1 : 1;
        }
        ++lhs;
        ++rhs;
    }

    const unsigned int lhsLength =
        static_cast<unsigned int>(lhsEnd - lhsBegin);
    const unsigned int rhsLength =
        static_cast<unsigned int>(rhsEnd - rhsBegin);
    if (lhsLength == rhsLength) {
        return 0;
    }
    return lhsLength < rhsLength ? -1 : 1;
}

} // namespace mystr

// UID:0002LN | by-memory/0x005840f0-0x0058415a.WideRangeCompare.md | Completion:89 | Confidence:92
namespace mystr
{
int WideRangeCompare(const wchar_t *lhsBegin,
                     const wchar_t *lhsEnd,
                     const wchar_t *rhsBegin,
                     const wchar_t *rhsEnd)
{
    const wchar_t *lhs = lhsBegin;
    const wchar_t *rhs = rhsBegin;

    while (lhs != lhsEnd && rhs != rhsEnd)
    {
        if (*lhs != *rhs)
            return *lhs < *rhs ? -1 : 1;
        ++lhs;
        ++rhs;
    }

    const unsigned int lhsLength =
        static_cast<unsigned int>(lhsEnd - lhsBegin);
    const unsigned int rhsLength =
        static_cast<unsigned int>(rhsEnd - rhsBegin);
    if (lhsLength == rhsLength)
        return 0;
    return lhsLength < rhsLength ? -1 : 1;
}
}

// UID:0002RS | by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md | Completion:90 | Confidence:91
namespace mystr {

template <>
StringBase<char, mychar_traits<char>>&
StringBase<char, mychar_traits<char>>::AppendAnsiSliceFromString(
    const StringBase<char, mychar_traits<char>>& source,
    unsigned int sourceOffset,
    unsigned int maxCount)
{
    const unsigned int sourceLength =
        static_cast<unsigned int>(reinterpret_cast<const int*>(source.m_data)[-2]);

    if (sourceLength <= sourceOffset) {
        return *this;
    }

    unsigned int appendCount = sourceLength - sourceOffset;
    if (maxCount < appendCount) {
        appendCount = maxCount;
    }

    char* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source.m_data + sourceOffset, appendCount);
        m_data[newLength] = '\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowAnsiBuffer(appendCount);
        memmove(m_data + oldLength, source.m_data + sourceOffset, appendCount);
    }

    return *this;
}

template <>
StringBase<char, mychar_traits<char>>&
StringBase<char, mychar_traits<char>>::AppendAnsiFill(unsigned int count, char ch)
{
    char* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + count;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memset(data + oldLength, ch, count);
        m_data[newLength] = '\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowAnsiBuffer(count);
        memset(m_data + oldLength, ch, count);
    }

    return *this;
}

template <>
StringBase<char, mychar_traits<char>>&
StringBase<char, mychar_traits<char>>::AppendAnsiLiteral(const char* source,
                                                         unsigned int maxCount)
{
    unsigned int literalLength = 0;
    while (source[literalLength] != '\0') {
        ++literalLength;
    }

    unsigned int appendCount = maxCount;
    if (literalLength < appendCount) {
        appendCount = literalLength;
    }

    char* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source, appendCount);
        m_data[newLength] = '\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowAnsiBuffer(appendCount);
        memmove(m_data + oldLength, source, appendCount);
    }

    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideSliceFromString(
    const StringBase<wchar_t, mychar_traits<wchar_t>>& source,
    unsigned int sourceOffset,
    unsigned int maxCount)
{
    const unsigned int sourceLength =
        static_cast<unsigned int>(reinterpret_cast<const int*>(source.m_data)[-2]);

    if (sourceLength <= sourceOffset) {
        return *this;
    }

    unsigned int appendCount = sourceLength - sourceOffset;
    if (maxCount < appendCount) {
        appendCount = maxCount;
    }

    wchar_t* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source.m_data + sourceOffset,
                appendCount * sizeof(wchar_t));
        m_data[newLength] = L'\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowWideBuffer(appendCount);
        memmove(m_data + oldLength, source.m_data + sourceOffset,
                appendCount * sizeof(wchar_t));
    }

    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideFill(unsigned int count,
                                                           wchar_t ch)
{
    wchar_t* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + count;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        for (unsigned int i = 0; i < count; ++i) {
            data[oldLength + i] = ch;
        }
        m_data[newLength] = L'\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowWideBuffer(count);
        for (unsigned int i = 0; i < count; ++i) {
            m_data[oldLength + i] = ch;
        }
    }

    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideLiteral(
    const wchar_t* source,
    unsigned int maxCount)
{
    unsigned int literalLength = 0;
    while (source[literalLength] != L'\0') {
        ++literalLength;
    }

    unsigned int appendCount = maxCount;
    if (literalLength < appendCount) {
        appendCount = literalLength;
    }

    wchar_t* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source, appendCount * sizeof(wchar_t));
        m_data[newLength] = L'\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowWideBuffer(appendCount);
        memmove(m_data + oldLength, source, appendCount * sizeof(wchar_t));
    }

    return *this;
}

template <class CharT, class Traits>
const CharT*
StringBase<CharT, Traits>::c_str() const
{
    return m_data;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t>>::CompareWideSubstringWithLiteral(
    unsigned int start,
    unsigned int maxCount,
    const wchar_t* literal) const
{
    const wchar_t* data = m_data;
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int*>(data)[-2]);

    if (length < start) {
        return -1;
    }

    unsigned int compareCount = length - start;
    if (maxCount < compareCount) {
        compareCount = maxCount;
    }

    const wchar_t* literalEnd = literal;
    while (*literalEnd != L'\0') {
        ++literalEnd;
    }

    return WideRangeCompare(data + start,
                            data + start + compareCount,
                            literal,
                            literalEnd);
}

}

// UID:0002LO | by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md | Completion:88 | Confidence:91
namespace mystr {

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::CompareWideLiteral(
    const wchar_t *literal) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    const wchar_t *literalEnd = literal;
    while (*literalEnd != L'\0') {
        ++literalEnd;
    }

    return WideRangeCompare(m_data, m_data + length, literal, literalEnd);
}

} // namespace mystr

// UID:0003NL | by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md | Completion:89 | Confidence:91
namespace mystr {

namespace {

bool StringBaseWideCharInSet(wchar_t ch,
                             const wchar_t *set,
                             unsigned int setLength)
{
    for (unsigned int i = 0; i < setLength; ++i) {
        if (set[i] == ch) {
            return true;
        }
    }
    return false;
}

}

template <>
bool
StringBase<wchar_t, mychar_traits<wchar_t> >::empty() const
{
    return reinterpret_cast<const int *>(m_data)[-2] == 0;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::RemoveWideRange(
    unsigned int start,
    unsigned int count)
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length <= start) {
        return *this;
    }

    unsigned int removeCount = length - start;
    if (count < removeCount) {
        removeCount = count;
    }
    if (removeCount == 0) {
        return *this;
    }

    if (start == 0 && removeCount == length) {
        ReleaseWideBuffer();
        return *this;
    }

    DetachWideIfShared();
    const unsigned int newLength = length - removeCount;
    memmove(m_data + start,
            m_data + start + removeCount,
            (newLength - start) * sizeof(wchar_t));
    m_data[newLength] = L'\0';
    reinterpret_cast<int *>(m_data)[-2] = static_cast<int>(newLength);
    return *this;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindSubstring(
    const wchar_t *needle,
    unsigned int start,
    unsigned int needleLength) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < start + needleLength) {
        return -1;
    }

    for (unsigned int index = start;
         index + needleLength <= length;
         ++index) {
        unsigned int matched = 0;
        while (matched < needleLength &&
               m_data[index + matched] == needle[matched]) {
            ++matched;
        }
        if (matched == needleLength) {
            return index == length ? -1 : static_cast<int>(index);
        }
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindFirstNotOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < start) {
        return -1;
    }

    for (unsigned int index = start; index < length; ++index) {
        if (!StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindFirstOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < start) {
        return -1;
    }

    for (unsigned int index = start; index < length; ++index) {
        if (StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindLastNotOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length == 0) {
        return -1;
    }

    unsigned int index = start;
    if (length - 1 < index) {
        index = length - 1;
    }

    for (;;) {
        if (!StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
        if (index == 0) {
            break;
        }
        --index;
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindLastOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length == 0) {
        return -1;
    }

    unsigned int index = start;
    if (length - 1 < index) {
        index = length - 1;
    }

    for (;;) {
        if (StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
        if (index == 0) {
            break;
        }
        --index;
    }

    return -1;
}

} // namespace mystr

// UID:0003NM | by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md | Completion:89 | Confidence:91
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::SpliceWide(
    unsigned int start,
    unsigned int removeMax,
    const wchar_t *insertText,
    unsigned int insertMax)
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length <= start) {
        return *this;
    }

    unsigned int removeCount = length - start;
    if (removeMax < removeCount) {
        removeCount = removeMax;
    }

    unsigned int insertLength = 0;
    while (insertText[insertLength] != L'\0') {
        ++insertLength;
    }
    if (insertMax < insertLength) {
        insertLength = insertMax;
    }

    const unsigned int newLength = length + insertLength - removeCount;
    RefCountedStringBufferHeader *header =
        reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;

    if ((header->refCount == 1 || header->refCount == -1) &&
        newLength <= header->capacity) {
        if (removeCount != insertLength) {
            memmove(m_data + start + insertLength,
                    m_data + start + removeCount,
                    (length - removeCount - start) * sizeof(wchar_t));
        }
        memmove(m_data + start, insertText, insertLength * sizeof(wchar_t));
        m_data[newLength] = L'\0';
        header->length = newLength;
        return *this;
    }

    wchar_t *oldData = m_data;
    if (header->refCount > 1 || header->capacity < newLength) {
        ReleaseWideBuffer();
        AllocateWideBuffer(newLength);
    }

    memmove(m_data, oldData, start * sizeof(wchar_t));
    memmove(m_data + start, insertText, insertLength * sizeof(wchar_t));
    memmove(m_data + start + insertLength,
            oldData + start + removeCount,
            (length - removeCount - start) * sizeof(wchar_t));

    StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseWideBuffer();
    return *this;
}

template <>
void
StringBase<char, mychar_traits<char> >::EnsureAnsiCapacity(
    unsigned int capacity)
{
    RefCountedStringBufferHeader *header =
        reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
    if (capacity <= header->capacity) {
        return;
    }

    char *oldData = m_data;
    const unsigned int oldLength = header->length;
    unsigned int allocationLength = capacity;
    if (allocationLength < oldLength) {
        allocationLength = oldLength;
    }

    AllocateAnsiBuffer(allocationLength);
    memmove(m_data, oldData, oldLength);
    m_data[oldLength] = '\0';
    reinterpret_cast<RefCountedStringBufferHeader *>(m_data)[-1].length =
        oldLength;

    StringBase<char, mychar_traits<char> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseAnsiBuffer();
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::EnsureWideCapacity(
    unsigned int capacity)
{
    RefCountedStringBufferHeader *header =
        reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
    if (capacity <= header->capacity) {
        return;
    }

    wchar_t *oldData = m_data;
    const unsigned int oldLength = header->length;
    unsigned int allocationLength = capacity;
    if (allocationLength < oldLength) {
        allocationLength = oldLength;
    }

    AllocateWideBuffer(allocationLength);
    memmove(m_data, oldData, oldLength * sizeof(wchar_t));
    m_data[oldLength] = L'\0';
    reinterpret_cast<RefCountedStringBufferHeader *>(m_data)[-1].length =
        oldLength;

    StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseWideBuffer();
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindLastSubstring(
    const wchar_t *needle,
    unsigned int start,
    unsigned int needleLength) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < needleLength) {
        return -1;
    }

    unsigned int index = start;
    if (needleLength == 0) {
        return length < index ? static_cast<int>(length)
                              : static_cast<int>(index);
    }

    const unsigned int lastPossible = length - needleLength;
    if (lastPossible < index) {
        index = lastPossible;
    }

    for (;;) {
        unsigned int matched = 0;
        while (matched < needleLength &&
               m_data[index + matched] == needle[matched]) {
            ++matched;
        }
        if (matched == needleLength) {
            return static_cast<int>(index);
        }
        if (index == 0) {
            break;
        }
        --index;
    }

    return -1;
}

template <class CharT, class Traits>
unsigned int
StringBase<CharT, Traits>::length() const
{
    return static_cast<unsigned int>(
        reinterpret_cast<const int *>(m_data)[-2]);
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::SubstringWide(
    StringBase<wchar_t, mychar_traits<wchar_t> > &out,
    unsigned int start,
    unsigned int count) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    unsigned int first = start;
    if (length < first) {
        first = length;
    }

    if (first == 0 && count == 0xffffffffU) {
        out.CopyOrShareWide(*this);
        return out;
    }

    unsigned int last = length;
    if (count != 0xffffffffU) {
        last = first + count;
        if (length < last) {
            last = length;
        }
    }

    const unsigned int resultLength = last - first;
    out.AllocateWideBuffer(resultLength);
    memmove(out.m_data, m_data + first, resultLength * sizeof(wchar_t));
    return out;
}

} // namespace mystr

// UID:0001VQ | by-type/by-struct/RefCountedStringBufferHeader.md | Completion:90 | Confidence:91
namespace mystr {

struct RefCountedStringBufferHeader {
    volatile LONG refCount;
    unsigned int length;
    unsigned int capacity;
};

} // namespace mystr

// UID:0001W4 | by-type/by-struct/SimpleUStringPointerBackedLayout.md | Completion:87 | Confidence:89
// Layout-only view: the one-pointer StringBase receiver layout is represented by [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) and exact StringBase child helper bodies; this page owns no standalone C++ declaration.

// UID:0001WS | by-type/by-template/StringBaseTemplate.md | Completion:88 | Confidence:91

// UID:0002RN | by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md | Completion:91 | Confidence:92
namespace mystr {

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::ShareOrCopyAnsiFromStringBase(
    const StringBase<char, mychar_traits<char> > &source)
{
    char *sourceData = source.m_data;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    char *resultData = g_emptyAnsiString;
    if (sourceHeader->refCount >= 0) {
        if (sourceData != g_emptyAnsiString) {
            InterlockedIncrement(
                const_cast<LONG *>(&sourceHeader->refCount));
            resultData = sourceData;
        }

        m_data = resultData;
        return *this;
    }

    if (sourceData == g_emptyAnsiString) {
        m_data = resultData;
        return *this;
    }

    EnsureAnsiCapacity(sourceHeader->length);
    memmove(m_data, sourceData, sourceHeader->length);
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFromCountedBytes(
    const char *source,
    unsigned int count)
{
    AllocateAnsiBuffer(count);
    memmove(m_data, source, count);
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeEmptyAnsi()
{
    m_data = g_emptyAnsiString;
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::ShareOrCopyWideFromStringBase(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    wchar_t *resultData = g_emptyWideString;
    if (sourceHeader->refCount >= 0) {
        if (sourceData != g_emptyWideString) {
            InterlockedIncrement(
                const_cast<LONG *>(&sourceHeader->refCount));
            resultData = sourceData;
        }

        m_data = resultData;
        return *this;
    }

    if (sourceData == g_emptyWideString) {
        m_data = resultData;
        return *this;
    }

    EnsureWideCapacity(sourceHeader->length);
    memmove(m_data, sourceData, sourceHeader->length * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFromRange(
    const wchar_t *first,
    const wchar_t *last)
{
    const unsigned int count = static_cast<unsigned int>(last - first);
    AllocateWideBuffer(count);
    memmove(m_data, first, count * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeEmptyWide()
{
    m_data = g_emptyWideString;
    return *this;
}

template <>
StringBase<char, mychar_traits<char> >::~StringBase()
{
    ReleaseAnsiBuffer();
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> >::~StringBase()
{
    ReleaseWideBuffer();
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::AssignAnsiFromStringBase(
    const StringBase<char, mychar_traits<char> > &source)
{
    char *sourceData = source.m_data;
    if (sourceData == g_emptyAnsiString) {
        m_data = g_emptyAnsiString;
        return *this;
    }

    char *data = m_data;
    if (data == sourceData) {
        return *this;
    }

    RefCountedStringBufferHeader *destinationHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(data) - 1;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    if ((destinationHeader->refCount >= 0 || data == g_emptyAnsiString) &&
        sourceHeader->refCount >= 0) {
        ReleaseAnsiBuffer();
        InterlockedIncrement(
            const_cast<LONG *>(&sourceHeader->refCount));
        m_data = sourceData;
        return *this;
    }

    unsigned int copyLength = sourceHeader->length;
    const unsigned int visibleLength =
        static_cast<unsigned int>(strlen(sourceData));
    if (visibleLength < copyLength) {
        copyLength = visibleLength;
    }

    if (destinationHeader->refCount > 1 ||
        destinationHeader->capacity < copyLength) {
        ReleaseAnsiBuffer();
        AllocateAnsiBuffer(copyLength);
        data = m_data;
    }

    memmove(data, sourceData, copyLength);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::AssignWideFromStringBase(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    if (sourceData == g_emptyWideString) {
        m_data = g_emptyWideString;
        return *this;
    }

    wchar_t *data = m_data;
    if (data == sourceData) {
        return *this;
    }

    RefCountedStringBufferHeader *destinationHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(data) - 1;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    if ((destinationHeader->refCount >= 0 || data == g_emptyWideString) &&
        sourceHeader->refCount >= 0) {
        ReleaseWideBuffer();
        InterlockedIncrement(
            const_cast<LONG *>(&sourceHeader->refCount));
        m_data = sourceData;
        return *this;
    }

    unsigned int copyLength = sourceHeader->length;
    const unsigned int visibleLength =
        static_cast<unsigned int>(wcslen(sourceData));
    if (visibleLength < copyLength) {
        copyLength = visibleLength;
    }

    if (destinationHeader->refCount > 1 ||
        destinationHeader->capacity < copyLength) {
        ReleaseWideBuffer();
        AllocateWideBuffer(copyLength);
        data = m_data;
    }

    memmove(data, sourceData, copyLength * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::AssignWideLiteral(
    const wchar_t *source)
{
    ReleaseWideBuffer();
    const unsigned int count = static_cast<unsigned int>(wcslen(source));
    AllocateWideBuffer(count);
    memmove(m_data, source, count * sizeof(wchar_t));
    return *this;
}

template <>
wchar_t
StringBase<wchar_t, mychar_traits<wchar_t> >::GetWideAt(
    unsigned int index) const
{
    return m_data[index];
}

} // namespace mystr

// UID:0002RO | by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md | Completion:91 | Confidence:92
namespace mystr {

template <>
char *
StringBase<char, mychar_traits<char> >::AllocateAnsiBuffer(unsigned int length)
{
    if (length == 0) {
        m_data = g_emptyAnsiString;
        return m_data;
    }

    RefCountedStringBufferHeader *header = 0;
    if (length <= 64) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool64.Allocate());
        header->capacity = 64;
    } else if (length <= 128) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool128.Allocate());
        header->capacity = 128;
    } else if (length <= 256) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool256.Allocate());
        header->capacity = 256;
    } else if (length <= 512) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool512.Allocate());
        header->capacity = 512;
    } else {
        header = static_cast<RefCountedStringBufferHeader *>(
            ::operator new(length +
                           sizeof(RefCountedStringBufferHeader) +
                           sizeof(char)));
        header->capacity = length;
    }

    header->refCount = 1;
    header->length = length;
    char *data = reinterpret_cast<char *>(header + 1);
    data[length] = '\0';
    m_data = data;
    return m_data;
}

template <>
wchar_t *
StringBase<wchar_t, mychar_traits<wchar_t> >::AllocateWideBuffer(
    unsigned int length)
{
    if (length == 0) {
        m_data = g_emptyWideString;
        return m_data;
    }

    RefCountedStringBufferHeader *header = 0;
    if (length <= 64) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool64.Allocate());
        header->capacity = 64;
    } else if (length <= 128) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool128.Allocate());
        header->capacity = 128;
    } else if (length <= 256) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool256.Allocate());
        header->capacity = 256;
    } else if (length <= 512) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool512.Allocate());
        header->capacity = 512;
    } else {
        header = static_cast<RefCountedStringBufferHeader *>(
            ::operator new(length * sizeof(wchar_t) +
                           sizeof(RefCountedStringBufferHeader) +
                           sizeof(wchar_t)));
        header->capacity = length;
    }

    header->refCount = 1;
    header->length = length;
    wchar_t *data = reinterpret_cast<wchar_t *>(header + 1);
    data[length] = L'\0';
    m_data = data;
    return m_data;
}

template <>
void
StringBase<char, mychar_traits<char> >::GrowAnsiBuffer(
    unsigned int additionalLength)
{
    char *oldData = m_data;
    if (oldData == g_emptyAnsiString) {
        AllocateAnsiBuffer(additionalLength);
        return;
    }

    const RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(oldData) - 1;
    const unsigned int oldLength = oldHeader->length;
    InterlockedIncrement(const_cast<LONG *>(&oldHeader->refCount));

    ReleaseAnsiBuffer();
    AllocateAnsiBuffer(oldLength + additionalLength);
    memmove(m_data, oldData, oldLength);

    reinterpret_cast<StringBase<char, mychar_traits<char> > *>(&oldData)
        ->ReleaseAnsiBuffer();
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::GrowWideBuffer(
    unsigned int additionalLength)
{
    wchar_t *oldData = m_data;
    if (oldData == g_emptyWideString) {
        AllocateWideBuffer(additionalLength);
        return;
    }

    const RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(oldData) - 1;
    const unsigned int oldLength = oldHeader->length;
    InterlockedIncrement(const_cast<LONG *>(&oldHeader->refCount));

    ReleaseWideBuffer();
    AllocateWideBuffer(oldLength + additionalLength);
    memmove(m_data, oldData, oldLength * sizeof(wchar_t));

    reinterpret_cast<StringBase<wchar_t, mychar_traits<wchar_t> > *>(&oldData)
        ->ReleaseWideBuffer();
}

template <>
void
StringBase<char, mychar_traits<char> >::DetachAnsiIfShared()
{
    char *oldData = m_data;
    RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(oldData) - 1;
    if (oldHeader->refCount <= 1) {
        return;
    }

    const unsigned int length = oldHeader->length;

    AllocateAnsiBuffer(length);
    memmove(m_data, oldData, length);

    reinterpret_cast<StringBase<char, mychar_traits<char> > *>(&oldData)
        ->ReleaseAnsiBuffer();
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::DetachWideIfShared()
{
    wchar_t *oldData = m_data;
    RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(oldData) - 1;
    if (oldHeader->refCount <= 1) {
        return;
    }

    const unsigned int length = oldHeader->length;

    AllocateWideBuffer(length);
    memmove(m_data, oldData, length * sizeof(wchar_t));

    reinterpret_cast<StringBase<wchar_t, mychar_traits<wchar_t> > *>(&oldData)
        ->ReleaseWideBuffer();
}

} // namespace mystr

// UID:0002LJ | by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md | Completion:88 | Confidence:91
namespace mystr {

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFormat(
    const char *format,
    ...)
{
    m_data = g_emptyAnsiString;

    va_list args;
    va_start(args, format);
    AnsiVFormat(format, args);
    va_end(args);
    return *this;
}

} // namespace mystr

// UID:0002LK | by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md | Completion:88 | Confidence:91
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFormat(
    const wchar_t *format,
    ...)
{
    m_data = g_emptyWideString;

    va_list args;
    va_start(args, format);
    WideVFormat(format, args);
    va_end(args);
    return *this;
}

} // namespace mystr

// UID:0002RT | by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md | Completion:91 | Confidence:92
namespace mystr {

namespace {

static RefCountedStringBufferHeader *HeaderFromData(void *data)
{
    return reinterpret_cast<RefCountedStringBufferHeader *>(
        static_cast<char *>(data) - sizeof(RefCountedStringBufferHeader));
}

static const RefCountedStringBufferHeader *HeaderFromData(const void *data)
{
    return reinterpret_cast<const RefCountedStringBufferHeader *>(
        static_cast<const char *>(data) - sizeof(RefCountedStringBufferHeader));
}

static void ReturnAnsiHeader(RefCountedStringBufferHeader *header)
{
    switch (header->capacity) {
    case 64:
        g_ansiPool64.Free(header);
        break;
    case 128:
        g_ansiPool128.Free(header);
        break;
    case 256:
        g_ansiPool256.Free(header);
        break;
    case 512:
        g_ansiPool512.Free(header);
        break;
    default:
        free(header);
        break;
    }
}

static void ReturnWideHeader(RefCountedStringBufferHeader *header)
{
    switch (header->capacity) {
    case 64:
        g_widePool64.Free(header);
        break;
    case 128:
        g_widePool128.Free(header);
        break;
    case 256:
        g_widePool256.Free(header);
        break;
    case 512:
        g_widePool512.Free(header);
        break;
    default:
        free(header);
        break;
    }
}

} // namespace

template <>
void StringBase<char, mychar_traits<char> >::ReleaseAnsiBuffer()
{
    char *data = m_data;
    if (data != g_emptyAnsiString) {
        RefCountedStringBufferHeader *header = HeaderFromData(data);
        if (InterlockedDecrement(&header->refCount) <= 0) {
            ReturnAnsiHeader(header);
        }
    }

    m_data = g_emptyAnsiString;
}

template <>
void StringBase<wchar_t, mychar_traits<wchar_t> >::ReleaseWideBuffer()
{
    wchar_t *data = m_data;
    if (data != g_emptyWideString) {
        RefCountedStringBufferHeader *header = HeaderFromData(data);
        if (InterlockedDecrement(&header->refCount) <= 0) {
            ReturnWideHeader(header);
        }
    }

    m_data = g_emptyWideString;
}

template <class CharT, class Traits>
RefCountedStringBufferHeader *
StringBase<CharT, Traits>::GetBufferHeader() const
{
    return HeaderFromData(m_data);
}

template <>
void StringBase<wchar_t, mychar_traits<wchar_t> >::CopyOrShareWide(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    const RefCountedStringBufferHeader *sourceHeader = HeaderFromData(sourceData);

    if (sourceHeader->refCount >= 0) {
        if (sourceData != g_emptyWideString) {
            InterlockedIncrement(
                const_cast<LONG *>(&sourceHeader->refCount));
        }
        m_data = sourceData;
        return;
    }

    m_data = g_emptyWideString;
    if (sourceData != g_emptyWideString) {
        EnsureWideCapacity(sourceHeader->length);
        memmove(m_data, sourceData, sourceHeader->length * sizeof(wchar_t));
    }
}

template <>
char *StringBase<char, mychar_traits<char> >::SetLengthAnsiAndDetach(
    unsigned int length)
{
    if (length == 0 && m_data == g_emptyAnsiString) {
        return m_data;
    }

    RefCountedStringBufferHeader *header = HeaderFromData(m_data);
    if (length > header->capacity) {
        char *oldData = m_data;
        unsigned int oldLength = header->length;
        unsigned int preserveLength = oldLength;
        if (preserveLength < length) {
            preserveLength = length;
        }

        AllocateAnsiBuffer(preserveLength);
        memmove(m_data, oldData, oldLength);
        m_data[oldLength] = '\0';
        HeaderFromData(m_data)->length = oldLength;

        StringBase<char, mychar_traits<char> > oldString;
        oldString.m_data = oldData;
        oldString.ReleaseAnsiBuffer();
        header = HeaderFromData(m_data);
    }

    m_data[length] = '\0';
    header->length = length;

    if (header->refCount > 1) {
        char *oldData = m_data;
        unsigned int copyLength = header->length;
        AllocateAnsiBuffer(copyLength);
        memmove(m_data, oldData, copyLength);

        StringBase<char, mychar_traits<char> > oldString;
        oldString.m_data = oldData;
        oldString.ReleaseAnsiBuffer();
        header = HeaderFromData(m_data);
    }

    header->refCount = -1;
    return m_data;
}

template <>
wchar_t *StringBase<wchar_t, mychar_traits<wchar_t> >::SetLengthWideAndDetach(
    unsigned int length)
{
    if (length == 0 && m_data == g_emptyWideString) {
        return m_data;
    }

    EnsureWideCapacity(length);
    m_data[length] = L'\0';

    RefCountedStringBufferHeader *header = HeaderFromData(m_data);
    header->length = length;

    if (header->refCount > 1) {
        wchar_t *oldData = m_data;
        unsigned int copyLength = header->length;
        AllocateWideBuffer(copyLength);
        memmove(m_data, oldData, copyLength * sizeof(wchar_t));

        StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
        oldString.m_data = oldData;
        oldString.ReleaseWideBuffer();
        header = HeaderFromData(m_data);
    }

    header->refCount = -1;
    return m_data;
}

template <>
wchar_t *StringBase<wchar_t, mychar_traits<wchar_t> >::MakeExclusiveWide()
{
    RefCountedStringBufferHeader *header = HeaderFromData(m_data);
    if (header->refCount <= 1) {
        header->refCount = -1;
        return m_data;
    }

    wchar_t *oldData = m_data;
    unsigned int length = header->length;
    AllocateWideBuffer(length);
    memmove(m_data, oldData, length * sizeof(wchar_t));

    StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseWideBuffer();

    HeaderFromData(m_data)->refCount = -1;
    return m_data;
}

template <>
int StringBase<wchar_t, mychar_traits<wchar_t> >::FormatWide(
    const wchar_t *format, ...)
{
    va_list args;
    va_start(args, format);
    int result = WideVFormat(format, args);
    va_end(args);
    return result;
}

} // namespace mystr

// UID:0002LL | by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md | Completion:88 | Confidence:91
namespace mystr {

template <>
int
StringBase<char, mychar_traits<char> >::AnsiVFormat(const char *format,
                                                    va_list args)
{
    unsigned int requested = static_cast<unsigned int>(strlen(format)) + 64;
    int result = -1;

    for (;;) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1 || header->capacity < requested) {
            ReleaseAnsiBuffer();
            AllocateAnsiBuffer(requested);
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        const unsigned int capacity = header->capacity;
        m_data[capacity] = '\0';
        header->length = capacity;

        result = StringBaseVsnprintf(m_data,
                                     capacity,
                                     capacity,
                                     format,
                                     args);
        if (result != -1) {
            break;
        }

        requested = capacity * 2;
    }

    if (m_data != g_emptyAnsiString) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1) {
            char *oldData = m_data;
            const unsigned int length = header->length;
            AllocateAnsiBuffer(length);
            memmove(m_data, oldData, length);

            StringBase<char, mychar_traits<char> > oldString;
            oldString.m_data = oldData;
            oldString.ReleaseAnsiBuffer();
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        header->length = static_cast<unsigned int>(strlen(m_data));
    }

    return result;
}

} // namespace mystr

// UID:0002LM | by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md | Completion:88 | Confidence:91
namespace mystr {

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::WideVFormat(
    const wchar_t *format,
    va_list args)
{
    unsigned int requested = static_cast<unsigned int>(wcslen(format)) + 64;
    int result = -1;

    for (;;) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1 || header->capacity < requested) {
            ReleaseWideBuffer();
            AllocateWideBuffer(requested);
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        const unsigned int capacity = header->capacity;
        m_data[capacity] = L'\0';
        header->length = capacity;

        result = StringBaseVsnwprintf(m_data,
                                      capacity,
                                      capacity,
                                      format,
                                      args);
        if (result != -1) {
            break;
        }

        requested = capacity * 2;
    }

    if (m_data != g_emptyWideString) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1) {
            wchar_t *oldData = m_data;
            const unsigned int length = header->length;
            AllocateWideBuffer(length);
            memmove(m_data, oldData, length * sizeof(wchar_t));

            StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
            oldString.m_data = oldData;
            oldString.ReleaseWideBuffer();
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        header->length = static_cast<unsigned int>(wcslen(m_data));
    }

    return result;
}

} // namespace mystr

// UID:0004FM | by-memory\0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md | Completion:92 | Confidence:94 | Empty Emitter Marker
