// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MS
// Source by-file doc: by-file/ProfileStorage.md
// UID:00019T | by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md | Completion:94 | Confidence:94
#include "ProfileStorage.h"

#include <shlobj.h>
#include <stdio.h>
#include <wchar.h>

#include "../config/Config.h"
#include "../config/RegistryConfig.h"
#include "../platform/PlatformApi.h"
#include "../string/SimpleUString.h"

namespace
{
    static const unsigned int kLocalPlayerNameLength = 0x28;
    static const unsigned int kLegacyPathLength = 0x80;
    static const unsigned int kProfilePathLength = 0x104;
    static const unsigned int kProfileTextCount = 10;
    static const unsigned int kProfileTextLength = 0x80;
    static const unsigned int kFriendNameCount = 20;
    static const unsigned int kSelectedProfileLength = 0x100;
    static const unsigned int kShortcutCount = 20;
    static const unsigned int kMacroTextLength = 0x80;

    static void ReadLegacyQuotedString(FILE *file, wchar_t *destination,
                                       size_t destinationLength)
    {
        wchar_t buffer[512];
        unsigned short length = 0;
        wint_t ch;

        do
        {
            ch = g_pfnReadUtf16CodeUnitFromFile(file);
        }
        while (ch != L'"' && ch != WEOF);

        do
        {
            ch = g_pfnReadUtf16CodeUnitFromFile(file);
            buffer[length] = static_cast<wchar_t>(ch);
            if (ch == L'"' || ch == WEOF)
                break;
            ++length;
        }
        while (true);

        buffer[length] = L'\0';
        if (destinationLength == kSelectedProfileLength &&
            length >= kSelectedProfileLength)
        {
            buffer[kSelectedProfileLength - 1] = L'\0';
        }
        wcscpy_s(destination, destinationLength, buffer);
    }

    static void ImportLegacyUserProfileData()
    {
        wchar_t path[kLegacyPathLength];
        wchar_t playerName[kLocalPlayerNameLength];

        g_pfnGetCurrentDirectoryW(kLegacyPathLength, path);
        GetLocalPlayerName(playerName, kLocalPlayerNameLength);
        wcscat_s(path, kLegacyPathLength, L"\\users\\");
        wcscat_s(path, kLegacyPathLength, playerName);
        wcscat_s(path, kLegacyPathLength, L".cfg");

        FILE *file = g_pfnWideOpenFile(path, L"rb");
        if (file == NULL)
            return;

        Config &config = *g_pConfig;
        unsigned int i;

        for (i = 0; i < kProfileTextCount; ++i)
            ReadLegacyQuotedString(file, config.m_profileTextSlots[i],
                                   kProfileTextLength);

        for (i = 0; i < kProfileTextCount; ++i)
            ReadLegacyQuotedString(file, config.m_legacyShortcutText[i],
                                   kProfileTextLength);

        for (i = 0; i < kFriendNameCount; ++i)
        {
            wchar_t value[512];
            ReadLegacyQuotedString(file, value,
                                   sizeof(value) / sizeof(value[0]));
            config.m_friendNames[i] = value;
        }

        ReadLegacyQuotedString(file, config.m_selectedProfileName,
                               kSelectedProfileLength);

        fclose(file);
        g_pfnDeleteFileW(path);
    }

    static bool CreateProfileDirectory(const wchar_t *path)
    {
        if (g_pfnCreateDirectoryW(path, NULL))
            return true;
        return GetLastError() == ERROR_ALREADY_EXISTS;
    }

    static void ReadProfileString(FILE *file,
                                  mystr::StringBase<wchar_t> &value)
    {
        unsigned short length = 0;
        fread(&length, sizeof(length), 1, file);

        wchar_t *buffer = value.SetLengthWideAndDetach(length);
        fread(buffer, sizeof(wchar_t), length, file);
        value.LockWideBuffer();
    }

    static void MigrateLegacyShortcuts(Config &config)
    {
        unsigned int i;

        for (i = 0; i < kProfileTextCount; ++i)
        {
            wchar_t code = config.m_legacyShortcutText[i][0];
            if (code == L'\0')
                continue;

            config.m_compactShortcutRecords[i].code = code;
            config.m_compactShortcutRecords[i].isSpellMode = 1;
            config.m_legacyShortcutText[i][0] = L'\0';
        }

        for (i = 0; i < kShortcutCount; ++i)
        {
            CompactShortcutRecord &shortcut =
                config.m_compactShortcutRecords[i];
            if (shortcut.code == L'\0')
                continue;

            MacroHotkeyRecord &macro = config.m_macroHotkeys[i];
            macro.state = (shortcut.isSpellMode != 1) + 2;
            macro.text[0] = shortcut.code;
            macro.text[1] = L'\0';
            shortcut.code = L'\0';
        }
    }
}

void LoadUserProfileData()
{
    static_cast<RegistryConfig *>(g_pConfig)->InitializeUserDataDefaults();
    Config &config = *g_pConfig;

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t path[kProfilePathLength];
    swprintf_s(path, L"%s\\NexusTK", documentsPath);
    if (!CreateProfileDirectory(path))
        return;

    swprintf_s(path, L"%s\\NexusTK\\users", documentsPath);
    if (!CreateProfileDirectory(path))
        return;

    wchar_t playerName[kLocalPlayerNameLength];
    GetLocalPlayerName(playerName, kLocalPlayerNameLength);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", path, playerName);

    FILE *file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
    if (file == NULL)
    {
        g_pfnGetCurrentDirectoryW(kLegacyPathLength, path);
        profilePath.Format(L"%s/users/%s.usr", path, playerName);
        file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
        if (file == NULL)
        {
            ImportLegacyUserProfileData();
            return;
        }
    }

    unsigned int i;
    for (i = 0; i < kProfileTextCount; ++i)
    {
        unsigned short length = 0;
        fread(&length, sizeof(length), 1, file);
        if (length > 0x7f)
            return;

        fread(config.m_profileTextSlots[i], sizeof(wchar_t), length, file);
        config.m_profileTextSlots[i][length] = L'\0';
    }

    for (i = 0; i < kProfileTextCount; ++i)
    {
        config.m_legacyShortcutText[i][0] =
            static_cast<wchar_t>(fgetwc(file));
        config.m_legacyShortcutText[i][1] = L'\0';
    }

    for (i = 0; i < kFriendNameCount; ++i)
        ReadProfileString(file, config.m_friendNames[i]);

    unsigned short selectedLength = 0;
    fread(&selectedLength, sizeof(selectedLength), 1, file);
    fread(config.m_selectedProfileName, sizeof(wchar_t), selectedLength, file);
    config.m_selectedProfileName[selectedLength] = L'\0';

    unsigned int count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1)
    {
        config.m_blockListenNames.Clear();
        for (i = 0; i < count; ++i)
        {
            unsigned int length = 0;
            fread(&length, sizeof(length), 1, file);

            mystr::StringBase<wchar_t> name;
            wchar_t *buffer = name.SetLengthWideAndDetach(length);
            fread(buffer, sizeof(wchar_t), length, file);
            name.LockWideBuffer();
            config.m_blockListenNames.PushBack(name);
        }
    }

    unsigned int present = 0;
    if (fread(&present, sizeof(present), 1, file) == 1)
    {
        for (i = 0; i < kShortcutCount; ++i)
        {
            config.m_compactShortcutRecords[i].code =
                static_cast<wchar_t>(fgetwc(file));
            config.m_compactShortcutRecords[i].isSpellMode =
                fgetwc(file) == L'S';
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0)
    {
        for (i = 0; i < count; ++i)
        {
            wint_t type = fgetwc(file);
            if (type == L'T')
                config.m_macroHotkeys[i].state = 1;
            else if (type == L'S')
                config.m_macroHotkeys[i].state = 2;
            else if (type == L'I')
                config.m_macroHotkeys[i].state = 3;

            unsigned short length = 0;
            fread(&length, sizeof(length), 1, file);
            if (length < kMacroTextLength)
            {
                fread(config.m_macroHotkeys[i].text,
                      sizeof(wchar_t), length, file);
                config.m_macroHotkeys[i].text[length] = L'\0';
            }
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0)
    {
        for (i = 0; i < count; ++i)
        {
            config.m_targetOptionRows[i].userEnabled = fgetwc(file) == L'1';
            config.m_targetOptionRows[i].monsterEnabled = fgetwc(file) == L'1';
        }
    }

    MigrateLegacyShortcuts(config);
    fclose(file);
}

// UID:0001AV | by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md | Completion:94 | Confidence:95
void SaveUserSettings()
{
    Config &config = *g_pConfig;

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t usersDirectory[MAX_PATH];
    swprintf_s(usersDirectory, L"%s\\NexusTK", documentsPath);
    if (!g_pfnCreateDirectoryW(usersDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
    {
        return;
    }

    swprintf_s(usersDirectory, L"%s\\NexusTK\\users", documentsPath);
    if (!g_pfnCreateDirectoryW(usersDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
    {
        return;
    }

    wchar_t playerName[0x28];
    GetLocalPlayerName(playerName, 0x28);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", usersDirectory, playerName);

    g_pfnSetFileAttributesW(profilePath.c_str(), FILE_ATTRIBUTE_NORMAL);
    g_pfnDeleteFileW(profilePath.c_str());

    FILE *file = g_pfnWideOpenFile(profilePath.c_str(), L"wb");
    if (file == NULL)
        return;

    unsigned int i;
    for (i = 0; i < 10; ++i)
    {
        unsigned short length = static_cast<unsigned short>(
            wcslen(config.m_profileTextSlots[i]));
        fwrite(&length, sizeof(length), 1, file);
        fwrite(config.m_profileTextSlots[i], sizeof(wchar_t), length, file);
    }

    for (i = 0; i < 10; ++i)
        fputwc(config.m_legacyShortcutText[i][0], file);

    for (i = 0; i < 20; ++i)
    {
        unsigned short length = static_cast<unsigned short>(
            config.m_friendNames[i].length());
        fwrite(&length, sizeof(length), 1, file);
        fwrite(config.m_friendNames[i].c_str(), sizeof(wchar_t), length, file);
    }

    unsigned short selectedLength = static_cast<unsigned short>(
        wcslen(config.m_selectedProfileName));
    fwrite(&selectedLength, sizeof(selectedLength), 1, file);
    fwrite(config.m_selectedProfileName,
           sizeof(wchar_t), selectedLength, file);

    unsigned int count = config.m_blockListenNames.Size();
    fwrite(&count, sizeof(count), 1, file);
    for (i = 0; i < count; ++i)
    {
        const mystr::StringBase<wchar_t> &name =
            config.m_blockListenNames[i];
        unsigned int length = name.length();
        fwrite(&length, sizeof(length), 1, file);
        fwrite(name.c_str(), sizeof(wchar_t), length, file);
    }

    unsigned int compactSectionPresent = 1;
    fwrite(&compactSectionPresent, sizeof(compactSectionPresent), 1, file);
    for (i = 0; i < 20; ++i)
    {
        fputwc(config.m_compactShortcutRecords[i].code, file);
        fputwc(config.m_compactShortcutRecords[i].isSpellMode != 0
                   ? L'S' : L'I',
               file);
    }

    count = 30;
    fwrite(&count, sizeof(count), 1, file);
    for (i = 0; i < count; ++i)
    {
        const MacroHotkeyRecord &macro = config.m_macroHotkeys[i];
        if (macro.state == 1)
            fputwc(L'T', file);
        else if (macro.state == 2)
            fputwc(L'S', file);
        else if (macro.state == 3)
            fputwc(L'I', file);

        unsigned short length = static_cast<unsigned short>(
            wcslen(macro.text));
        fwrite(&length, sizeof(length), 1, file);
        fwrite(macro.text, sizeof(wchar_t), length, file);
    }

    count = 2;
    fwrite(&count, sizeof(count), 1, file);
    for (i = 0; i < count; ++i)
    {
        fputwc(config.m_targetOptionRows[i].userEnabled == 1 ? L'1' : L'0',
               file);
        fputwc(config.m_targetOptionRows[i].monsterEnabled == 1 ? L'1' : L'0',
               file);
    }

    fclose(file);
}
