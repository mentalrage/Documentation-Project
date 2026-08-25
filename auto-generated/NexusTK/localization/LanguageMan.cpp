// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KK
// Source by-file doc: by-file/LanguageMan.md
// UID:000071 | by-class/LanguageMan.md | Completion:94 | Confidence:95
#include "LanguageMan.h"
#include "../archive/DATFile.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"

#include <windows.h>

// UID:0000RC | by-global/g_pLanguageMan.md | Completion:94 | Confidence:96
LanguageMan *g_pLanguageMan = 0;

template <>
Singleton<LanguageMan>::Singleton()
{
    g_pLanguageMan = static_cast<LanguageMan *>(this);
}

template <>
Singleton<LanguageMan>::~Singleton()
{
    g_pLanguageMan = 0;
}

// UID:00040V | by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md | Completion:91 | Confidence:91
namespace {
const int kMaxStringResourceLineBytes = 1024;
const int kMaxLocalizedStringCount = 1024;
}

// UID:00040X | by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md | Completion:91 | Confidence:95
namespace {
const wchar_t kStringResourceName[] = L"str.res";
const wchar_t kTooManyStringsMessage[] = L"Too many strings";
const wchar_t kInvalidStringIdText[] = L"Invalid String ID";
}

// UID:00041V | by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md | Completion:94 | Confidence:95
LanguageMan::LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    DATFile stringResource;
    stringResource.Open(kStringResourceName);
    (void)stringResource.GetSize();

    wchar_t **temporaryStrings =
        static_cast<wchar_t **>(
            memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * kMaxLocalizedStringCount));
    m_stringCount = 0;

    bool reachedEndOfFile = false;
    char multiByteLine[kMaxStringResourceLineBytes * 2];
    wchar_t wideLine[kMaxStringResourceLineBytes];

    do {
        int lineLength = 0;

        while (stringResource.GetPosition() < stringResource.GetSize()) {
            stringResource.Read(&multiByteLine[lineLength], 1);

            if (multiByteLine[lineLength] == '\r') {
                stringResource.Seek(1, 1);
                break;
            }

            if (multiByteLine[lineLength] == '\n' || ++lineLength >= kMaxStringResourceLineBytes)
                break;
        }

        if (stringResource.GetPosition() >= stringResource.GetSize())
            reachedEndOfFile = true;

        for (int i = 0; i < lineLength; ++i) {
            if (multiByteLine[i] == 0x11)
                multiByteLine[i] = '\r';
        }

        const int wideChars = MultiByteToWideChar(
            0,
            0,
            multiByteLine,
            lineLength,
            wideLine,
            kMaxStringResourceLineBytes);
        const size_t byteCount = static_cast<size_t>(wideChars) * sizeof(wchar_t);
        wchar_t *copiedLine =
            static_cast<wchar_t *>(
                memoryMan->AllocateBufferMemory(byteCount + sizeof(wchar_t)));

        temporaryStrings[m_stringCount] = copiedLine;
        memoryMan->MemmoveWrapper(temporaryStrings[m_stringCount], wideLine, byteCount);
        temporaryStrings[m_stringCount][wideChars] = L'\0';

        const int storedIndex = m_stringCount++;
        if (storedIndex >= kMaxLocalizedStringCount)
            throw MyError(kTooManyStringsMessage);
    } while (!reachedEndOfFile);

    m_strings =
        static_cast<wchar_t **>(memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * m_stringCount));
    for (int i = 0; i < m_stringCount; ++i)
        m_strings[i] = temporaryStrings[i];

    memoryMan->FreeBufferMemory(temporaryStrings);
}

// UID:00018S | by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md | Completion:93 | Confidence:95
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
}

// UID:00040P | by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md | Completion:93 | Confidence:95
const wchar_t *LanguageMan::GetLocalizedString(int stringId) const
{
    if (stringId >= 0 && stringId < m_stringCount) {
        return m_strings[stringId];
    }

    return kInvalidStringIdText;
}

// UID:00040Q | by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md | Completion:94 | Confidence:95
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
LanguageMan::CopyLocalizedString(int stringId) const
{
    if (stringId >= 0 && stringId < m_stringCount) {
        return mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >(
            m_strings[stringId]);
    }

    return mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >(
        kInvalidStringIdText);
}
