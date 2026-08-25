// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KK
// Source by-file doc: by-file/LanguageMan.md
// UID:000071 | by-class/LanguageMan.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_LOCALIZATION_LANGUAGEMAN_H
#define NEXUSTK_LOCALIZATION_LANGUAGEMAN_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class LanguageMan;
extern LanguageMan *g_pLanguageMan;

class LanguageMan : public LObject, public Singleton<LanguageMan>
{
public:
    LanguageMan();
    virtual ~LanguageMan();

    const wchar_t *GetLocalizedString(int stringId) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
    CopyLocalizedString(int stringId) const;

private:
    wchar_t **m_strings;
    int m_stringCount;
    unsigned int m_reservedState[8];
};

typedef char LanguageManSizeMustBe44[
    sizeof(LanguageMan) == 0x2c ? 1 : -1];

#endif
